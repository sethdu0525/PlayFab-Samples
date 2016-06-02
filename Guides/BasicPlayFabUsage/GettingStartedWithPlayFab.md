# Getting started with PlayFab #

*(Comment NS - This is an introduction, and not a place for deep explanation of features. Total size should be under 10 pages. It is designed to be scanned easily.)*

The PlayFab web site provides a general introduction to PlayFab and the products that make up the PlayFab suite. This page will give you a developers perspective on PlayFab, and will try to answer the following questions:

- What will PlayFab do for me?
- How does PlayFab work to deliver that promise?
- Is there a PlayFab SDK that targets my platform?

## What will PlayFab do for me? ##
There are 4 main components of PlayFab. Here's what these components can do for you as a developer.  Each component will be described more fully in later sections.

*(Comment NS - The first part of the following descriptions come from the web site, and the second part is new, intended to cover what this means in concrete terms to a developer. You will probably have things that you would like to add or change. The only critical thing is that the descriptions should stay short paragraphs.)*

- **Game Services** Back-end building blocks for your live game, accessed via an extensive set of web service APIs. Game Services are all about game, player, and studio data, and the APIs that you can use to modify that data from your game client or server. *(Comment NS - There appears to be no introduction to game services topic. Further comments in the Game Services section below.)*

- **PlayStream** Game operations automation, with game events, event triggers and real-time player segmentation. PlayStream is the real-time log of events as they happen, tracking player and game events from player logins to loot bonuses. Events can trigger custom code to modify and generate game data and trigger new events.*(Comment NS - There appears to be no introduction to PlayStream topic.)*

- **Game Manager** [Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager) is mission control for your whole team, bringing all your game’s data and events together in one place. Game Manager is a web based interface that lets you track and modify game data and events in real-time.

- **Add-On Marketplace** The largest collection of pre-integrated 3rd-party tools and services dedicated to game operations. PlayStream includes integration with many third party services, allowing you to use those services alongside PlayFab with little custom coding or additional SDKs. You can now see all your data in a single interface. *(Comment NS - There appears to be no introduction to the Marketplace topic. In fact, a search in Documentation for Marketplace comes up empty.)*

## Game Services ##
*(Comment NS - This material is taken from the PlayFab Technical White Paper, but it has been simplified, restructured, and edited for use in this introduction. There should be a separate, expanded deep dive article for Game Services that includes the more complicated bits of the white paper, and more. Perhaps a reference of all the elements available in Game Services, auto-generated with comments and notes calling out what can be accessed in Game Manager,  what needs an SDK call, and a link to what that call might be?. )*

*(Comment NS - Search in the Documentation section of the web site shows some detailed topics which I have linked to. It looks like the only areas that are covered are those that are available in the Game Manager. More of these titles would be helpful, and better indexing, or a table of contents would help discoverability. I found them by accident.)*

Game services are at the core of PlayFab. All game services are accessible from the API, and much of the data in game services can be reviewed and modified through the [Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager). Game services include:

### Player Accounts ###

Player accounts are central to PlayFab; every user gets a player account. Player accounts can be used across all the games in your studio, and can be linked to and authenticated by multiple third party systems, supporting cross-platform game play.

The Game Manager can be used to view and manage account linkages so customer support reps can deal with authentication issues.

### Data Storage ###

PlayFab provides an easy way to store custom player and game data. All data is stored as key/value pairs, where values can be plaintext, JSON, or binary blobs. Data can be stored at the following levels:

- **Game title data.** [Title data](https://api.playfab.com/docs/using-title-data) can be accessed by all players and game clients. This data is typically used for game configuration information, such as game difficulty settings, or level descriptions. 
- **Files.** PlayFab provides support for uploading and delivering files via an integrated CDN.
- **Catalog data.** Use [Catalogs](https://api.playfab.com/docs/catalogs) to define items that the player can purchase or that you can use to reward to a player. Every item in the catalog can have custom properties associated with it, such as rate-of-fire for a weapon, or mana points for a collectible card.
- **Group data.** Data shared among a specific group of players, such as a guild or lobby. All members in the group can read or write shared group data. *(Comment NS - There appears to be no topic for Group data.)*
- **Player data.** [Player data](https://api.playfab.com/docs/using-player-data) is data stored per player account. Access to player data is controlled by scope, Permissions and Client access rights. Stats are a special case of player data, which can be used in leaderboards, match-making, and player segmentation.
- **Publisher data.** [Publisher data](https://api.playfab.com/docs/using-publisher-data), or Studio data is data that spans more than one title, such as when you have multiple games that need to share common information. 

### In-game commerce ###

PlayFab provides an in-game commerce system for managing and selling in-game entitlements with real or virtual currency. These can range from virtual items such as a sword, to content unlocks such as an additional character slot. Specific features include:

- **Catalog.** The game [Catalog](https://api.playfab.com/docs/catalogs) defines the master list of all items in the game, with optional usage counts, expiration times, custom properties, stacking behavior and price in one or more virtual and real-world currencies.
- **Drop tables.** Drop tables are weighted lists of items that can be used with bundles or containers to randomly grant items according to probability. Examples include card-packs, treasure chests, or lucky draws. *(Comment NS - A deeper topic for this would be valuable. More detail on bundles and containers would be great as well.)*
- **Stores.** A store is a subset of a catalog, with optional price overrides. Stores allow items to be discontinued, yet still exist in the catalog. *(Comment NS - A deeper topic for this would be valuable, perhaps a subsection of the Catalog topic?)*
- **Inventory.** Each player and character have an inventory of items that is maintained on the server as items are purchased, granted, consumed, or expire. *(Comment NS - A deeper topic for this would be valuable.)*
- **Trading.** Items can be traded between players. Features include escrow, for safe trading. *(Comment NS - A deeper topic for this would be valuable.)*
- **Virtual currencies.** Each game can have multiple [virtual currencies](https://api.playfab.com/docs/currencies), with optional initial balances, recharge rates, and maximums. Each player and character can have separate balances for each virtual currency, and virtual currency can be exchanged between characters and players.
- **Real-money transactions.** PlayFab supports a number of payment mechanisms for real-money transactions, including third party systems such as PayPal, Amazon, and Facebook. PlayFab also supports server to server receipt validation with protection from replay attacks for mobile platforms such as Google and Apple. PlayFab provides platform specific payments for Steam, PlayStation, and Xbox. *(Comment NS - A deeper topic for this would be very valuable.)*

### Server-side game logic ###

PlayFab provides several mechanisms for hosting your custom game logic on the server. Features include:

- **CloudScript.** [CloudScript](https://api.playfab.com/docs/using-cloud-script/) is server hosted JavaScript that allows you to define custom functions that can be called from the game client and executed within the security context of the current player on the server. Cloud script code can call the privileged server API which cannot ordinarily be called from the client. Cloud script can also be triggered by PlayStream events.
- **Game server hosting.** [Custom game servers](https://api.playfab.com/docs/custom-game-servers) allow you to upload a custom game server executable for multiplayer games, and define regions around the world where the game server should be deployed. PlayFab automatically deploys and scales game servers based on load to maintain sufficient capacity for hosting new game matches. *(Comment NS - A deeper topic for this would be very valuable.)*
- **Matchmaking.** supports assigning players to matches based on parameters such as min/max players, region, game mode, player statistics, and friend list. You may also provide your own custom matchmaking logic. *(Comment NS - A deeper topic for this would be very valuable.)* 
- **Write local files.** Game servers can write local files, including logs, replays, or crash dumps. When a game session is over, local files are archived and indexed for later analysis. *(Comment NS - A deeper topic for this might be valuable.)*
- **Photon.** PlayFab’s partnership with Exit Games makes it especially easy for games to provision multiplayer game rooms using [Photon Cloud](https://api.playfab.com/docs/using-photon-with-playfab/). 

### Marketing ###

PlayFab has features to help you market your games to your existing players:

- **Push notifications.** Games can send custom mobile push notifications directly to a player through the server API. See [Push Basics](https://api.playfab.com/docs/push-basics), [Push for Android](https://api.playfab.com/docs/push-for-android), and [Push for iOS](https://api.playfab.com/docs/push-for-ios) for more details.
- **Articles.** Developers can publish articles using the Game Manager and have them displayed in the game. Examples include launcher message-of-the-day,  interstitial notices, and in game notices. *(Comment NS - A deeper topic for this might be valuable.)*
- **Coupon codes.** PlayFab can generate onetime coupon codes which may be redeemed in-game for any item in the catalog. *(Comment NS - A deeper topic for this might be valuable.)*
- **Cross-game promotions.** Publishers can cross-promote titles on PlayFab by enabling players in one game to unlock or be granted items in other games. *(Comment NS - A deeper topic for this might be valuable.)*

### Social ###

PlayFab has social features to help promote higher engagement and retention through player-to-player interaction. These include:

- **Friends list.** PlayFab maintains a friends list for each player, and can automatically add players to that list by matching against existing Facebook or Steam friends. Games can also add or remove players to the list directly. The friends list can also be used by leaderboards and matchmaking.
- **Leaderboards.** Any stat can be used to generate a leaderboard. Leaderboards can be Global or social, durable, or resettable. For any given stat, the leaderboard can reset on an hourly, daily, weekly or monthly schedule. Archives of leaderboards and player values for previous versions of the statistic are still retrievable after the reset. See [Using Resettable Statistics and Leaderboards](https://api.playfab.com/docs/using-version-statistics) for more information.
- **Chat.** PlayFab supports player chat rooms via partnership with Exit Games.

## Using Game Services. ##
You work with Game Services in several ways: 

- **Using Game Manager.** Some data and events can be viewed and manipulated in real-time using the PlayFab [Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager).
- **Using the PlayFab API.** All game services can be accessed using the [PlayFab API](https://api.playfab.com/Documentation), a HTTP web API. The PlayFab API is also exposed through platform specific  SDKs which are listed in [Available SDKs](https://api.playfab.com/sdks). These SDKs do the work of making API calls and handling responses.
- **Using CloudScript.** [CloudScript](https://api.playfab.com/docs/using-cloud-script/) offers a fast, and secure alternative to dedicated servers. Your custom JavaScript lives and executes directly on PlayFab machines. From here, your code can be called directly by your game clients or indirectly via PlayStream actions. Additionally, Cloud Script methods have full access to PlayFab's Server API set.

### Game Manager ###
[Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager) is a unified web interface that gives your team a single destination for viewing and managing the live data associated with Game Services. Specific features include:

- **Permissions.** A robust permission model so that different users can be given permission to access different features. For example, customer service reps can be given permission to edit player properties but not change item prices. *(Comment NS - A deeper topic for this might be valuable.)*
- **Dashboards and Reporting.** A set of dashboards and reports for viewing performance of the game. *(Comment NS - A deeper topic for this might be valuable.)*
- **Audit log.** A list of all configuration or data changes made via the Game Manager to track down issues or monitor support changes. *(Comment NS - A deeper topic for this might be valuable.)*
- **Customer support.** Support reps can investigate issues and provide service recovery by granting or revoking virtual items or virtual currency, and temporarily or permanently ban abusive players. *(Comment NS - A deeper topic for this might be valuable.)*

### The PlayFab API ###
All game services can be accessed using the [PlayFab API](https://api.playfab.com/Documentation), a HTTP web API which can be used directly, or through platform specific [SDKs](https://api.playfab.com/sdks), which wrap the PlayFab APIs (See the next section). The API is divided into the following sections:

- **Client.** The [Client API](https://api.playfab.com/Documentation/Client) supports client applications (like a game client). Call this API for services like authentication, account and data management, inventory, friends, matchmaking, and reporting.
- **Server.** The [Server API](https://api.playfab.com/Documentation/Server) is available to your servers or to your CloudScript functions on the PlayFab servers for trusted interactions with user inventories and data, and to handle matchmaking and client connection orchestration.
- **Matchmaker.** The [Matchmaker API](https://api.playfab.com/Documentation/Matchmaker) connects an external match-making service in conjunction with PlayFab hosted Game Server instances.
- **Administration.** [Admin API](https://api.playfab.com/Documentation/Admin)s for managing title configurations, uploaded Game Server code executables, and user data. These are used for automation and custom management tools.

All API documentation is auto-generated from the code ensuring it is always up to date with any changes.

### The PlayFab SDKs ###
PlayFab offers many [SDKs](https://api.playfab.com/sdks/) that wrap the [PlayFab APIs](https://api.playfab.com/Documentation) in platform specific code to make your development tasks easier. The SDKs cover a wide range of programming languages and hardware platforms, and are updated regularly to include the latest changes to the APIs.

All SDKs are hosted on the [PlayFab GitHub](https://github.com/PlayFab) repository.

Example code for several of the APIs can be found in the PlayFab [Samples](https://github.com/PlayFab/PlayFab-Samples) repository. 
Each SDK also includes testing code which is also a good source of examples.

All SDK calls follow a common pattern using a request and a result class. You pass in the request and you get a callback with the result or error. 

![API Calling Pattern](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_callingPattern.png "Most SDKs follow a similar Call / Response Pattern")

### PlayStream ###
Game events are generated by your client, the PlayFab server, PlayFab APIs, and third party products. They describe the history of a player while they are playing your game. 
[Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager) provides a central place to view, manage, and evaluate game events. These events drive PlayFab's real-time metrics, and you can also set triggers to fire when certain criteria are met.  These criteria might be when the event matches a preset value, or when the player enters or exits a segment. Triggers can send events or call CloudScript functions which can then modify the player's state.

### CloudScript ###
[CloudScript](https://api.playfab.com/docs/using-cloud-script/) lets you run your own trusted JavaScript code in the cloud on PlayFab servers, providing a secure environment to manage player inventories, statistics and in game currency. It also gives you a way to update and test game logic in real-time, without having to go through the expensive and time consuming effort to upgrade your game client or set up and maintain a custom server.
CloudScript functions are authored in PlayFab's [Game Manager](https://api.playfab.com/docs/introduction-to-gamemanager), or updated via a GitHub extension. They have full access to the PlayFab server APIs, and can be called using the PlayFab Client API from your game client and from other CloudScript functions on the PlayFab servers. You can also [call Webhooks](https://api.playfab.com/docs/calling-webhooks-from-cloudscript) from CloudScript.

## Next steps ##
More information on developing with PlayFab can be found in these topics:

- [Tutorials & Guides](https://api.playfab.com/docs/tutorials).
- [Recipe Index](https://api.playfab.com/docs/recipe-index).
- [PlayFab API Documentation](https://api.playfab.com/documentation).
- [AddOn Documentation](https://api.playfab.com/partners).
- [Available SDKs](https://api.playfab.com/sdks).




