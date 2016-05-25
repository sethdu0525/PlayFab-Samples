# Getting Started with the PlayFab C# SDK #

## Introduction ##
The PlayFab C# SDK allows C# developers to access the power of the PlayFab Client API from within C# programs.  The C# SDK is different from the Unity SDK, which also uses C#.
Follow these steps to create a simple C# app that will register a user with the PlayFab backend service.

## Prerequisites ##
You will need to have some things ready in order to use this guide.

- Microsoft Visual Studio, or other C# development tools. This guide was written using Visual Studio 2015.
- A little knowledge of PlayFab.  See [The PlayFab Beginner’s Guide](https://api.playfab.com/docs/beginners-guide) for an overview of how PlayFab works.  For more depth, download a copy of the [PlayFab Technical Overview](https://playfab.com/wp-content/uploads/2015/12/PlayFabTechnicalWhitePaper_2015.12.09.pdf). 
- A PlayFab Developer account.  See [PlayFab Developer Account](https://developer.playfab.com/en-us/studios) to sign up for your own free PlayFab account.

## Steps ##
Follow these steps to create your first PlayFab / C# project. By the way, in PlayFab each project or title is called a game.

### Add a game to PlayFab ###
First you will create a new PlayFab game, and make a note of the Title ID for later use in PlayFab calls.

1. Open the [Game Manager](https://developer.playfab.com/en-us/studios), PlayFab’s web based tool for adding, viewing and changing your games. You should see your games listed by studio.  If you just created your account, you will see a default studio called **My Game Studio**, and a default game called **My Game**. 
2. Create a new game by clicking **Create a new game**, and name it "Getting Started".  You can fill in the rest of the information on this page, or leave it blank.  Click **Create Game** to add this game to your PlayFab account.  
3. Return to the main view in the Game Manager by clicking the PlayFab logo in the upper left corner of the screen. You will see a tile for your new game showing the game title and Title ID. The Title ID is a unique value used by PlayFab to identify this game. Make a note of the Title ID for the new game. You will need this value later.

![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager")

### Create a simple console project in Visual Studio###

1. Click the **File** menu.
2. Click New, then click **Project...**
3. In the left hand pane of the **New Project** dialog, open Templates, then Visual C#.
4. Click on Windows under Visual C#.
5. In the center pane select Console Application.
6. At the bottom of the dialog Name the project PlayFabGettingStarted.
7. Click the OK button to create your console application.
8. Click the Start button (the green arrow in the toolbar) and confirm that your application will compile and run.

Visual Studio creates a blank project with a single file (Program.cs) that looks like this:

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    namespace PlayFabGettingStarted
    {
        class Program
        {
            static void Main(string[] args)
            {
            }
        }
    }

### Add the PlayFab C# NewGet package to your application ###
You can program the PlayFab API in several ways:

- Directly through a HTTP web API, which is described in [PlayFab API documentation](https://api.playfab.com/Documentation).
- Through platform specific libraries which are listed in [Available SDKs](https://api.playfab.com/sdks). These SDKs do the work of making API calls and handling responses.

![API Sets](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_apiSets.png "Import the SDK into your Unity project")

For C# developers there is an additional option. You can install a PlayFab NuGet package via Visual Studio, which is what you will do here.

1. Click on the **Project** menu.
2. Click Manage **NuGet Packages...**
3. In the **NuGet Package Manager**, find the search box in the upper right corner, and enter "PlayFab".
4. Select PlayFabAllSDK in the search results, and then click **Install**.
5. In the Preview dialog, click **OK**.
6. You can now close the NuGet Package Manager.

### Add PlayFab specific code to Program.cs ###
Add a using statement for the PlayFab SDK. Place this line of code after the other using statements at the top of the file.

    using PlayFab;

The following code will be used to authenticate the player.
Normally you would add code to create a unique ID and save that unique ID for later use (see the [PlayFab PrizeWheel Recipe](https://github.com/PlayFab/PlayFab-Samples/tree/master/Recipes/PrizeWheel) for an example of how that works), or use one of the other recommended APIs for logging in. In this example you will use **[LoginWithCustomIDAsync](https://api.playfab.com/Documentation/Client/method/LoginWithCustomID)** with a pre-generated identifier to keep the code simple.

Every time the game logs into PlayFab this unique value is used to find the user in the Studio's user database. The first time you log in with this identifier a user will be created in PlayFab, and from that point onward every time you log in with this id you will be connected to the same user.

All SDK calls follow a common pattern using a request and a result class.  You pass in the request and you get a callback with the result or error. **request** holds the request data, and **result** holds the returned data.

![API Calling Pattern](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_callingPattern.png "Most SDKs follow a similar Call / Response Pattern")

This is also where you use the title ID that you made note of earlier in the Game Manager.

Add the following method to the Program class, immediately after the Main method.

        static async void login()
        {
            Console.WriteLine("Logging in to PlayFab");
            PlayFabSettings.TitleId = "{your game id}";
            PlayFab.ClientModels.LoginWithCustomIDRequest request = new PlayFab.ClientModels.LoginWithCustomIDRequest();
            request.CustomId = "f5bf7f96-0399-4510-88a6-3e3a42a90f5e";
            request.TitleId = "8F2";
            request.CreateAccount = true;

            PlayFabResult<PlayFab.ClientModels.LoginResult> result = await PlayFabClientAPI.LoginWithCustomIDAsync(request);
            if (result.Result != null)
            {
                if (result.Result.NewlyCreated)
                {
                    Console.WriteLine("Got PlayFabID: " + result.Result.PlayFabId + "(new account)");
                }
                else
                {
                    Console.WriteLine("Got PlayFabID: " + result.Result.PlayFabId + "(existing account)");
                }
            }

            if (result.Error !=null)
            {
                Console.WriteLine(result.Error.ErrorMessage);
            }

            Console.WriteLine("Press any key to exit");
        }

Finally you need to wire up the button you added in the html file to the **login** method. Do this by adding this code to the Main method. The whole method now looks like this:

        static void Main(string[] args)
        {
            login();
            Console.ReadKey();
        }

The final project should look like this:

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using PlayFab;

    namespace PlayFabGettingStarted
    {
        class Program
        {
            static void Main(string[] args)
            {
                login();
                Console.ReadKey();
            }

            static async void login()
            {
                Console.WriteLine("Logging in to PlayFab");
                PlayFabSettings.TitleId = "8F2";
                PlayFab.ClientModels.LoginWithCustomIDRequest request = new PlayFab.ClientModels.LoginWithCustomIDRequest();
                request.CustomId = "f5bf7f96-0399-4510-88a6-3e3a42a90f5e";
                request.TitleId = "8F2";
                request.CreateAccount = true;

                PlayFabResult<PlayFab.ClientModels.LoginResult> result = await PlayFabClientAPI.LoginWithCustomIDAsync(request);
                if (result.Result != null)
                {
                    if (result.Result.NewlyCreated)
                    {
                        Console.WriteLine("Got PlayFabID: " + result.Result.PlayFabId + "(new account)");
                    }
                    else
                    {
                        Console.WriteLine("Got PlayFabID: " + result.Result.PlayFabId + "(existing account)");
                    }
                }

                if (result.Error != null)
                {
                    Console.WriteLine(result.Error.ErrorMessage);
                }

                Console.WriteLine("Press any key to exit");
            }
        }
    }	

### Test your C# Project ###
Click the Start button (the green arrow in the toolbar) and confirm that your application will still compile and run.

If all goes according to plan, you will see debug trace in the console window that will tell you the result of the logon attempt. If successful, the player will be logged in to PlayFab with a session ticket that is valid for 24 hours. The returned PlayFab ID in the Login method can now be used for subsequent API calls while the player interacts with your game. 
Once you have created a PlayFab account for a player from any game in your studio, their PlayFab account ID is available for all of the games in your studio.

![The PlayFab ID has been found](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/C#output.png "The output of the console window.")

### Confirm the new player in the Game Manager ###
You can now return to the Game Manager and confirm that the player has been created. Your new player should be immediately visible from the PlayStream Debugger. 

![PlayStream Debugger](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/PlayStreamDebugger.png "Clicking the Player ID will take you to the corresponding player details.")

**To view recently logged in players**:

1.	Open [Game Manager](https://developer.playfab.com/en-us/studios).
2.	Click on your title, **Getting Started**.
3.	In the left sidebar, click on the **Players** tab.  You will see a list of players who have been added to your Getting Started game.

### What just happened? ###
You used **[LoginWithCustomIDAsync](https://api.playfab.com/Documentation/Client/method/LoginWithCustomID)** to establish a connection with PlayFab and connect to a unique player for one of your titles.  If no player was found, a new player was created and associated with the unique ID that you passed in. This is a special version of **LoginWithCustomID** designed to work with the await keyword in C#.
**request** was created to hold the parameters for the call, and **result** was created to handle the returned data. 

**[LoginWithCustomIDAsync](https://api.playfab.com/Documentation/Client/method/LoginWithCustomID)** returns a session identifier which you will use to identify this player for the remainder of this game session.  The session identifier is stored for later use in the global **PlayFabId**.

## Next steps ##
Congratulations on your first PlayFab API call.  Expand on what you have learned and explore what else PlayFab can do for you by exploring [Recipes](https://api.playfab.com/docs/recipe-index), [Tutorials and Guides](https://api.playfab.com/docs/tutorials).  The [PlayFab C# SDK](https://github.com/PlayFab/CSharpSDK) on GitHub also has useful information.

