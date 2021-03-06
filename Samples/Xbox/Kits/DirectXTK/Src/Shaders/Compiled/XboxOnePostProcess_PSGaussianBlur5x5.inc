#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler for Durango
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float       
// TEXCOORD                 0   xy          1     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
// Opaque Custom Data - XBOX Precompiled Shader Header
// First Precompiled Shader at offset:[97]
// Embedded Data:
//  0x00000061 - Offset To First Precompiled Shader
//  0x00000050 - Original Shader Descriptor
//  0x0000005c - Original Shader Size
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[32], dynamicIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 3
mov r0.xyzw, l(0,0,0,0)
mov r1.x, l(0)
loop 
  ige r1.y, r1.x, l(13)
  breakc_nz r1.y
  add r1.yz, v1.xxyx, cb0[r1.x + 0].xxyx
  sample_indexable(texture2d)(float,float,float,float) r2.xyzw, r1.yzyy, t0.xyzw, s0
  mad r0.xyzw, cb0[r1.x + 16].xyzw, r2.xyzw, r0.xyzw
  iadd r1.x, r1.x, l(1)
endloop 
mov o0.xyzw, r0.xyzw
ret 
// Opaque Custom Data - XBOX Precompiled Shader Object
// Offset:[97], bundle is:[244] DWORDS.
// Disassembled Precompiled Shader Object:
// Shader Type               : (PS)
// Shader Hw Stage           : (PS)
// PDB Filename              : D:\ATG\st_dev\Kits\DirectXTK\src\Shaders\Compiled\XboxOnePostProcess_PSGaussianBlur5x5.pdb
// Shader Semantic Hash      : 0x9e2699b11a788737
//
// Shader Data:
; ----------------- PS Data ------------------------
; Input Semantic Mappings
;   [0] generic,  usageIdx 1, channelMask  3, param0, paramSlot1, DefaultVal={0,0,0,0}

codeLenInByte        = 628 bytes;

; launchModeFlags    = 0x0000000E
srdTableSupport      = TRUE
immediateSupportExt  = TRUE
srdTableSupportExt   = TRUE

userElementCount     = 1;
;  userElements[0]      = PTR_EXTENDED_USER_DATA, ReferencedExtUserElements=1, s[0x0:1]
extUserElementCount  = 3;
;  extUserElements 1[0] = IMM_RESOURCE 0, offset 0x0:7 dwords
;  extUserElements 1[1] = IMM_SAMPLER 0, offset 0x8:11 dwords
;  extUserElements 1[2] = IMM_CONST_BUFFER 0, offset 0xc:15 dwords
NumVgprs             = 22;
NumSgprs             = 64;
FloatMode            = 192;
IeeeMode             = 0;
FlatPtr32            = 0;
ScratchSize          = 0 dwords/thread;
LDSByteSize          = 0 bytes/workgroup (compile time only);
ScratchWaveOffsetReg = s65535;
; texSamplerUsage         = 0x00000001
; constBufUsage           = 0x00000001

; SPI_SHADER_PGM_RSRC2_PS = 0x00000004
SSPRP:SCRATCH_EN            = 0
SSPRP:USER_SGPR             = 2
SSPRP:TRAP_PRESENT          = 0
SSPRP:WAVE_CNT_EN           = 0
SSPRP:EXTRA_LDS_SIZE        = 0
SSPRP:EXCP_EN               = 0
; SPI_SHADER_Z_FORMAT     = 0x00000000
SPZF:Z_EXPORT_FORMAT        = 0; SPI_SHADER_ZERO
; SPI_PS_IN_CONTROL       = 0x00000001
SPIC:NUM_INTERP             = 1
SPIC:PARAM_GEN              = 0
SPIC:FOG_ADDR               = 0
SPIC:BC_OPTIMIZE_DISABLE    = 0
SPIC:PASS_FOG_THROUGH_PS    = 0
; SPI_PS_INPUT_ADDR       = 0x00000002
SPIA:PERSP_CENTER_ENA       = 1
; DB_SHADER_CONTROL       = 0x00000010
DB:Z_ORDER                  = 1
DB:CONSERVATIVE_Z_EXPORT    = 0; EXPORT_ANY_Z
; CB_SHADER_MASK          = 0x0000000F
CB:OUTPUT0_ENABLE           = 15

; export table for mrt0 [patch@(bytes=0x260, dwords=0x98)]
// Export Patch Code (FMT_ZERO):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_nop         0x0000                                  // 000000000000: BF800000
  s_nop         0x0000                                  // 000000000004: BF800000
  exp           null, off, off, off, off done vm        // 000000000008: F8001890 00000000
end
// Export Patch Code (FMT_32_R):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_nop         0x0000                                  // 000000000000: BF800000
  s_nop         0x0000                                  // 000000000004: BF800000
  exp           mrt0, v16, off, off, off done vm        // 000000000008: F8001801 00000010
end
// Export Patch Code (FMT_32_GR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_nop         0x0000                                  // 000000000000: BF800000
  s_nop         0x0000                                  // 000000000004: BF800000
  exp           mrt0, v16, v17, off, off done vm        // 000000000008: F8001803 00001110
end
// Export Patch Code (FMT_32_AR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_nop         0x0000                                  // 000000000000: BF800000
  s_nop         0x0000                                  // 000000000004: BF800000
  exp           mrt0, v16, v19, off, off done vm        // 000000000008: F8001803 00001310
end
// Export Patch Code (FMT_FP16_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  v_cvt_pkrtz_f16_f32  v0, v16, v17                     // 000000000000: 5E002310
  v_cvt_pkrtz_f16_f32  v1, v18, v19                     // 000000000004: 5E022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000008: F8001C0F 00000100
end
// Export Patch Code (FMT_UNORM16_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  v_cvt_pknorm_u16_f32  v0, v16, v17                    // 000000000000: 5C002310
  v_cvt_pknorm_u16_f32  v1, v18, v19                    // 000000000004: 5C022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000008: F8001C0F 00000100
end
// Export Patch Code (FMT_SNORM16_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  v_cvt_pknorm_i16_f32  v0, v16, v17                    // 000000000000: 5A002310
  v_cvt_pknorm_i16_f32  v1, v18, v19                    // 000000000004: 5A022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000008: F8001C0F 00000100
end
// Export Patch Code (FMT_UINT16_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  v_cvt_pk_u16_u32  v0, v16, v17                        // 000000000000: 60002310
  v_cvt_pk_u16_u32  v1, v18, v19                        // 000000000004: 60022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000008: F8001C0F 00000100
end
// Export Patch Code (FMT_SINT16_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  v_cvt_pk_i16_i32  v0, v16, v17                        // 000000000000: 62002310
  v_cvt_pk_i16_i32  v1, v18, v19                        // 000000000004: 62022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000008: F8001C0F 00000100
end
// Export Patch Code (FMT_32_ABGR):
shader patch
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_nop         0x0000                                  // 000000000000: BF800000
  s_nop         0x0000                                  // 000000000004: BF800000
  exp           mrt0, v16, v17, v18, v19 done vm        // 000000000008: F800180F 13121110
end

// Shader Instructions:
shader main
  asic(CI)
  type(PS)
                                                            // s_ps_state in s0
  s_mov_b64     s[60:61], exec                          // 000000000000: BEBC047E
  s_wqm_b64     exec, exec // wrscc                     // 000000000004: BEFE0A7E
  s_mov_b32     s58, s2                                 // 000000000008: BEBA0302
  s_load_dwordx16  s[0:15], s[0:1], 0x00                // 00000000000C: C1000100
  s_waitcnt     lgkmcnt(0)                              // 000000000010: BF8C007F
  s_buffer_load_dwordx2  s[48:49], s[12:15], 0x00       // 000000000014: C2580D00
  s_buffer_load_dwordx16  s[16:31], s[12:15], 0x40      // 000000000018: C3080D40
  s_buffer_load_dwordx2  s[50:51], s[12:15], 0x04       // 00000000001C: C2590D04
  s_buffer_load_dwordx2  s[52:53], s[12:15], 0x08       // 000000000020: C25A0D08
  s_buffer_load_dwordx2  s[54:55], s[12:15], 0x0c       // 000000000024: C25B0D0C
  s_buffer_load_dwordx2  s[56:57], s[12:15], 0x10       // 000000000028: C25C0D10
  s_buffer_load_dwordx16  s[32:47], s[12:15], 0x50      // 00000000002C: C3100D50
  s_mov_b32     m0, s58                                 // 000000000030: BEFC033A
  v_interp_p1_f32  v20, v0, attr0.x                     // 000000000034: C8500000
  v_interp_p2_f32  v20, v1, attr0.x                     // 000000000038: C8510001
  v_interp_p1_f32  v21, v0, attr0.y                     // 00000000003C: C8540100
  v_interp_p2_f32  v21, v1, attr0.y                     // 000000000040: C8550101
  s_waitcnt     lgkmcnt(0)                              // 000000000044: BF8C007F
  v_add_f32     v0, s48, v20                            // 000000000048: 06002830
  v_add_f32     v1, s49, v21                            // 00000000004C: 06022A31
  v_add_f32     v4, s50, v20                            // 000000000050: 06082832
  v_add_f32     v5, s51, v21                            // 000000000054: 060A2A33
  v_add_f32     v8, s52, v20                            // 000000000058: 06102834
  v_add_f32     v9, s53, v21                            // 00000000005C: 06122A35
  v_add_f32     v12, s54, v20                           // 000000000060: 06182836
  v_add_f32     v13, s55, v21                           // 000000000064: 061A2A37
  v_add_f32     v16, s56, v20                           // 000000000068: 06202838
  v_add_f32     v17, s57, v21                           // 00000000006C: 06222A39
  image_sample  v[0:3], v[0:1], s[0:7], s[8:11] dmask:0xf // 000000000070: F0800F00 00400000
  image_sample  v[4:7], v[4:5], s[0:7], s[8:11] dmask:0xf // 000000000078: F0800F00 00400404
  image_sample  v[8:11], v[8:9], s[0:7], s[8:11] dmask:0xf // 000000000080: F0800F00 00400808
  image_sample  v[12:15], v[12:13], s[0:7], s[8:11] dmask:0xf // 000000000088: F0800F00 00400C0C
  image_sample  v[16:19], v[16:17], s[0:7], s[8:11] dmask:0xf // 000000000090: F0800F00 00401010
  s_waitcnt     vmcnt(4)                                // 000000000098: BF8C0F74
  v_mul_legacy_f32  v0, s16, v0                         // 00000000009C: 0E000010
  v_mul_legacy_f32  v1, s17, v1                         // 0000000000A0: 0E020211
  v_mul_legacy_f32  v2, s18, v2                         // 0000000000A4: 0E040412
  v_mul_legacy_f32  v3, s19, v3                         // 0000000000A8: 0E060613
  s_waitcnt     vmcnt(3)                                // 0000000000AC: BF8C0F73
  v_mac_f32     v0, s20, v4                             // 0000000000B0: 3E000814
  v_mac_f32     v1, s21, v5                             // 0000000000B4: 3E020A15
  v_mac_f32     v2, s22, v6                             // 0000000000B8: 3E040C16
  v_mac_f32     v3, s23, v7                             // 0000000000BC: 3E060E17
  s_waitcnt     vmcnt(2)                                // 0000000000C0: BF8C0F72
  v_mac_f32     v0, s24, v8                             // 0000000000C4: 3E001018
  v_mac_f32     v1, s25, v9                             // 0000000000C8: 3E021219
  v_mac_f32     v2, s26, v10                            // 0000000000CC: 3E04141A
  v_mac_f32     v3, s27, v11                            // 0000000000D0: 3E06161B
  s_waitcnt     vmcnt(1)                                // 0000000000D4: BF8C0F71
  v_mac_f32     v0, s28, v12                            // 0000000000D8: 3E00181C
  v_mac_f32     v1, s29, v13                            // 0000000000DC: 3E021A1D
  v_mac_f32     v2, s30, v14                            // 0000000000E0: 3E041C1E
  v_mac_f32     v3, s31, v15                            // 0000000000E4: 3E061E1F
  s_buffer_load_dwordx2  s[48:49], s[12:15], 0x14       // 0000000000E8: C2580D14
  s_buffer_load_dwordx2  s[50:51], s[12:15], 0x18       // 0000000000EC: C2590D18
  s_buffer_load_dwordx2  s[52:53], s[12:15], 0x1c       // 0000000000F0: C25A0D1C
  s_buffer_load_dwordx2  s[54:55], s[12:15], 0x20       // 0000000000F4: C25B0D20
  s_buffer_load_dwordx16  s[16:31], s[12:15], 0x60      // 0000000000F8: C3080D60
  s_waitcnt     vmcnt(0)                                // 0000000000FC: BF8C0F70
  v_mad_f32     v16, s32, v16, v0                       // 000000000100: D2820010 04022020
  v_mad_f32     v17, s33, v17, v1                       // 000000000108: D2820011 04062221
  v_mad_f32     v18, s34, v18, v2                       // 000000000110: D2820012 040A2422
  v_mad_f32     v19, s35, v19, v3                       // 000000000118: D2820013 040E2623
  s_waitcnt     lgkmcnt(0)                              // 000000000120: BF8C007F
  v_add_f32     v0, s48, v20                            // 000000000124: 06002830
  v_add_f32     v1, s49, v21                            // 000000000128: 06022A31
  v_add_f32     v4, s50, v20                            // 00000000012C: 06082832
  v_add_f32     v5, s51, v21                            // 000000000130: 060A2A33
  v_add_f32     v8, s52, v20                            // 000000000134: 06102834
  v_add_f32     v9, s53, v21                            // 000000000138: 06122A35
  v_add_f32     v12, s54, v20                           // 00000000013C: 06182836
  v_add_f32     v13, s55, v21                           // 000000000140: 061A2A37
  image_sample  v[0:3], v[0:1], s[0:7], s[8:11] dmask:0xf // 000000000144: F0800F00 00400000
  image_sample  v[4:7], v[4:5], s[0:7], s[8:11] dmask:0xf // 00000000014C: F0800F00 00400404
  image_sample  v[8:11], v[8:9], s[0:7], s[8:11] dmask:0xf // 000000000154: F0800F00 00400808
  image_sample  v[12:15], v[12:13], s[0:7], s[8:11] dmask:0xf // 00000000015C: F0800F00 00400C0C
  s_waitcnt     vmcnt(3)                                // 000000000164: BF8C0F73
  v_mac_f32     v16, s36, v0                            // 000000000168: 3E200024
  v_mac_f32     v17, s37, v1                            // 00000000016C: 3E220225
  v_mac_f32     v18, s38, v2                            // 000000000170: 3E240426
  v_mac_f32     v19, s39, v3                            // 000000000174: 3E260627
  s_waitcnt     vmcnt(2)                                // 000000000178: BF8C0F72
  v_mac_f32     v16, s40, v4                            // 00000000017C: 3E200828
  v_mac_f32     v17, s41, v5                            // 000000000180: 3E220A29
  v_mac_f32     v18, s42, v6                            // 000000000184: 3E240C2A
  v_mac_f32     v19, s43, v7                            // 000000000188: 3E260E2B
  s_waitcnt     vmcnt(1)                                // 00000000018C: BF8C0F71
  v_mac_f32     v16, s44, v8                            // 000000000190: 3E20102C
  v_mac_f32     v17, s45, v9                            // 000000000194: 3E22122D
  v_mac_f32     v18, s46, v10                           // 000000000198: 3E24142E
  v_mac_f32     v19, s47, v11                           // 00000000019C: 3E26162F
  s_buffer_load_dwordx2  s[32:33], s[12:15], 0x24       // 0000000001A0: C2500D24
  s_buffer_load_dwordx2  s[34:35], s[12:15], 0x28       // 0000000001A4: C2510D28
  s_buffer_load_dwordx2  s[36:37], s[12:15], 0x2c       // 0000000001A8: C2520D2C
  s_buffer_load_dwordx2  s[38:39], s[12:15], 0x30       // 0000000001AC: C2530D30
  s_buffer_load_dwordx4  s[12:15], s[12:15], 0x70       // 0000000001B0: C2860D70
  s_waitcnt     vmcnt(0)                                // 0000000001B4: BF8C0F70
  v_mac_f32     v16, s16, v12                           // 0000000001B8: 3E201810
  v_mac_f32     v17, s17, v13                           // 0000000001BC: 3E221A11
  v_mac_f32     v18, s18, v14                           // 0000000001C0: 3E241C12
  v_mac_f32     v19, s19, v15                           // 0000000001C4: 3E261E13
  s_waitcnt     lgkmcnt(0)                              // 0000000001C8: BF8C007F
  v_add_f32     v0, s32, v20                            // 0000000001CC: 06002820
  v_add_f32     v1, s33, v21                            // 0000000001D0: 06022A21
  v_add_f32     v4, s34, v20                            // 0000000001D4: 06082822
  v_add_f32     v5, s35, v21                            // 0000000001D8: 060A2A23
  v_add_f32     v8, s36, v20                            // 0000000001DC: 06102824
  v_add_f32     v9, s37, v21                            // 0000000001E0: 06122A25
  v_add_f32     v12, s38, v20                           // 0000000001E4: 06182826
  v_add_f32     v13, s39, v21                           // 0000000001E8: 061A2A27
  image_sample  v[0:3], v[0:1], s[0:7], s[8:11] dmask:0xf // 0000000001EC: F0800F00 00400000
  image_sample  v[4:7], v[4:5], s[0:7], s[8:11] dmask:0xf // 0000000001F4: F0800F00 00400404
  image_sample  v[8:11], v[8:9], s[0:7], s[8:11] dmask:0xf // 0000000001FC: F0800F00 00400808
  image_sample  v[12:15], v[12:13], s[0:7], s[8:11] dmask:0xf // 000000000204: F0800F00 00400C0C
  s_waitcnt     vmcnt(3)                                // 00000000020C: BF8C0F73
  v_mac_f32     v16, s20, v0                            // 000000000210: 3E200014
  v_mac_f32     v17, s21, v1                            // 000000000214: 3E220215
  v_mac_f32     v18, s22, v2                            // 000000000218: 3E240416
  v_mac_f32     v19, s23, v3                            // 00000000021C: 3E260617
  s_waitcnt     vmcnt(2)                                // 000000000220: BF8C0F72
  v_mac_f32     v16, s24, v4                            // 000000000224: 3E200818
  v_mac_f32     v17, s25, v5                            // 000000000228: 3E220A19
  v_mac_f32     v18, s26, v6                            // 00000000022C: 3E240C1A
  v_mac_f32     v19, s27, v7                            // 000000000230: 3E260E1B
  s_waitcnt     vmcnt(1)                                // 000000000234: BF8C0F71
  v_mac_f32     v16, s28, v8                            // 000000000238: 3E20101C
  v_mac_f32     v17, s29, v9                            // 00000000023C: 3E22121D
  v_mac_f32     v18, s30, v10                           // 000000000240: 3E24141E
  v_mac_f32     v19, s31, v11                           // 000000000244: 3E26161F
  s_waitcnt     vmcnt(0)                                // 000000000248: BF8C0F70
  v_mac_f32     v16, s12, v12                           // 00000000024C: 3E20180C
  v_mac_f32     v17, s13, v13                           // 000000000250: 3E221A0D
  v_mac_f32     v18, s14, v14                           // 000000000254: 3E241C0E
  v_mac_f32     v19, s15, v15                           // 000000000258: 3E261E0F
  s_mov_b64     exec, s[60:61]                          // 00000000025C: BEFE043C
  v_cvt_pkrtz_f16_f32  v0, v16, v17                     // 000000000260: 5E002310
  v_cvt_pkrtz_f16_f32  v1, v18, v19                     // 000000000264: 5E022712
  exp           mrt0, v0, v0, v1, v1 done compr vm      // 000000000268: F8001C0F 00000100
  s_endpgm                                              // 000000000270: BF810000
end


// Shader Statistics:
//  NumActiveWaveFront:         32
//  WorkgroupSize:              64
//  NumVRegs:                   22
//  NumSRegs:                   64
//  NumActiveWaveFrontByVReg:   40
//  NumActiveWaveFrontBySReg:   32
//  NumActiveWaveFrontByLDS:    40
//  CycleSim:                   164
//  CycleSimNWaves:             164
//  Code Size:                  628
//Assembler Counts:
//  num_32bit_ops                     : 121
//  num_64bit_ops                     : 18
//  num_alu                           : 84
//  num_fc                            : 41
//  num_inst_exp                      : 1
//  num_inst_ldsgds                   : 0
//  num_inst_mimg                     : 13
//  num_inst_mtbuf                    : 0
//  num_inst_mubuf                    : 0
//  num_inst_sopp                     : 18
//  num_inst_sopc                     : 0
//  num_inst_sop1                     : 5
//  num_inst_sop2                     : 0
//  num_inst_smrd                     : 0
//  num_inst_sopk                     : 0
//  num_inst_vop1                     : 0
//  num_inst_vop2                     : 76
//  num_inst_vop3                     : 0
//  num_inst_vopc                     : 0
//  num_inst_vintrp                   : 4
//  constant_literal_operands         : 0
//  num_tex                           : 14
//  num_vmem_group                    : 3
//  vmem_grouping_started             : 0
//
//Compilation Notes:
//
//  PS has no UAV writes, consider forcing REZ/LATEZ.
// Shader Statistics:
// m_uNumActiveWaveFront             : 32
// m_uVRegLimit                      : 47
// m_uSRegLimit                      : 100
// m_uNumVRegs                       : 22
// m_uNumSRegs                       : 64
// m_uSCCodeSize                     : 628
// m_uWorkgroupSize                  : 64
// m_uNumActiveWaveFrontByVReg       : 40
// m_uNumActiveWaveFrontBySReg       : 32
// m_uNumActiveWaveFrontByLDS        : 40
// m_uCycleSim1Wave                  : 164
// m_uCycleSimNWaves                 : 164

// Assembler Counts:
// num_32bit_ops                     : 121
// num_64bit_ops                     : 18
// num_alu                           : 84
// num_fc                            : 41
// num_inst_exp                      : 1
// num_inst_ldsgds                   : 0
// num_inst_mimg                     : 13
// num_inst_mtbuf                    : 0
// num_inst_mubuf                    : 0
// num_inst_sopp                     : 18
// num_inst_sopc                     : 0
// num_inst_sop1                     : 5
// num_inst_sop2                     : 0
// num_inst_smrd                     : 0
// num_inst_sopk                     : 0
// num_inst_vop1                     : 0
// num_inst_vop2                     : 76
// num_inst_vop3                     : 0
// num_inst_vopc                     : 0
// num_inst_vintrp                   : 4
// num_inst_smem                     : 18
// constant_literal_operands         : 0
// num_tex                           : 14
// num_vmem_group                    : 3
// vmem_grouping_started             : 0
// m_fFullPrecompilePromise          : 0
// m_fIntegerDivideExpansion         : 0
// m_fIntegerModExpansion            : 0
// m_fDoubleDivideExpansion          : 0
// m_fUsesScratch                    : 0
// m_fPerThreadIndirection           : 0
// m_fUsingTableLoads                : 0
// m_fUsingSHmemLoads                : 1
// fSemanticHashFlagOverrideApplied  : 0
// fPSHasNoUAVWrite                  : 1
// m_fRenderTargetsCanBeCompacted    : 0
// version                           : 3
// fCodePatched                      : 0

// Approximately 0 instruction slots used
#endif

const BYTE PostProcess_PSGaussianBlur5x5[] =
{
     68,  88,  66,  67,  34,  46, 
    250, 217, 188,  31, 160, 229, 
    173, 217, 122,   1, 223, 159, 
    220,  25,   1,   0,   0,   0, 
    150,   6,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    140,   0,   0,   0, 192,   0, 
      0,   0,  36,   6,   0,   0, 
     52,   6,   0,   0,  73,  83, 
     71,  78,  80,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,  56,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  68,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,   3, 
      0,   0,  83,  86,  95,  80, 
    111, 115, 105, 116, 105, 111, 
    110,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
    171, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  69,  88,  92,   5, 
      0,   0,  80,   0,   0,   0, 
     87,   1,   0,   0,  53,  16, 
      0,   0,   5,   0,   0,   0, 
     97,   0,   0,   0,  80,   0, 
      0,   0,  92,   0,   0,   0, 
    106,   8,   0,   1,  89,   8, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  32,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   3,   0, 
      0,   0,  54,   0,   0,   8, 
    242,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     48,   0,   0,   1,  33,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  13,   0, 
      0,   0,   3,   0,   4,   3, 
     26,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   9, 
     98,   0,  16,   0,   1,   0, 
      0,   0,   6,  17,  16,   0, 
      1,   0,   0,   0,   6, 129, 
     32,   4,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  69,   0,   0, 139, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 242,   0,  16,   0, 
      2,   0,   0,   0, 150,   5, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  12, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
     16,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  22,   0,   0,   1, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     53,  16,   0,   0, 246,   0, 
      0,   0,  23,   0,   1,   0, 
     41, 195,  18,   0, 120,   1, 
    237, 152, 193, 111,  27,  69, 
     20, 198, 159,  55, 203,  96, 
    140, 119, 189,  89, 187, 238, 
    198, 113, 211, 173, 227,  58, 
    174,  41,  77, 128, 134,  66, 
    169,  70, 129,  86, 170,  80, 
    145, 112,  73, 144,  66, 186, 
    106,  19, 199, 150, 136,  84, 
     26, 227, 117,  81, 184, 132, 
    192,   1,  14, 233,   1, 113, 
     10,  23,  46, 244,  15, 104, 
    175,   8,  57, 101, 115, 201, 
     17, 241,  87, 244, 200, 145, 
      3,  42, 124, 111, 119,  54, 
    184, 133, 162,  30,  44, 129, 
    192, 159, 244, 237, 219,  55, 
     59,  59, 243, 155, 153,  40, 
    242, 219,  61, 155,  66,  45, 
     54, 222, 180,  56, 126, 117, 
    127, 251, 116,  59,  65, 244, 
     20, 238,  17, 194, 200, 218, 
     49, 248,  74, 228, 133, 189, 
    136,  92, 120,  26, 110, 194, 
    121, 120,  14, 238, 106,  81, 
    172, 194, 252, 156,  35, 221, 
    115, 206,  19, 141, 195,  68, 
    175, 193,  99, 240, 109, 229, 
    143,  97, 158, 126,   1,  62, 
      1, 243, 124,  44,  53,  85, 
     40, 133, 119, 192, 209, 175, 
    183, 248, 162, 164, 195, 113, 
     95,  19,  30, 129,  15, 212, 
    226, 203,  95, 107,  27, 102, 
    254, 199, 137, 217,  98,  30, 
    230,  99,  78,  22, 175, 243, 
    159,  86, 180,  95, 127,  92, 
    217, 241,  57, 177, 248,  60, 
    250, 197, 251, 194, 125,  88, 
    105, 117, 142, 241,  62, 185, 
     42, 143, 207, 242,  30, 252, 
     56, 253,   6, 169, 238,   7, 
    138, 115,  30,  95,  36,  48, 
    106,  18,  55, 255,  83, 241, 
    223,  34, 139, 247, 130, 143, 
    128, 247,  38,   3, 199, 138, 
    159, 239, 240, 133, 182, 118, 
    217,  95,  58, 244,  11, 103, 
    113, 158,  64,  30, 237, 105, 
    148, 143, 112,  62, 250,  72, 
    158, 197, 216, 147, 116, 213, 
    158, 210, 174, 102, 138, 120, 
     31,  19,  34, 247, 144, 123, 
    125, 249,  18, 242, 165, 190, 
    124,  25, 249, 114,  95, 222, 
     64, 222, 136, 243, 120, 252, 
     76,  56, 159, 157, 229, 179, 
     70, 227, 230, 191, 217,  67, 
    198, 193, 120, 200,  56,  24, 
     15,  25,   7, 227,  33, 227, 
     96,  60, 100,  28, 140, 135, 
    140, 131, 241, 144, 113,  96, 
    166,  77, 253, 251, 222, 102, 
    234,  65,  79,  27, 249, 174, 
    135, 223, 111,  63, 124,  66, 
    183, 118, 201,  88,  12, 230, 
    140, 228, 158, 110, 188,  23, 
     36, 141, 165,  32, 109,  92, 
      9,  44, 195,  11, 234, 134, 
    181, 119, 118, 228, 215,  30, 
     81, 125,  63,  65, 151, 247, 
     41, 177, 176, 159,  72, 188, 
    187, 207, 239, 204,  84,  73, 
    188,  80, 211, 196, 139, 213, 
    164, 120, 169, 150,  18, 167, 
    171, 150, 152, 173, 217, 226, 
    229, 170,  35, 206, 212,  10, 
    226, 149, 170,  43,  94, 173, 
    149,   4, 101, 182, 126,  14, 
     43,   4,  68,  93, 143,  98, 
     50,  25, 197, 116,  58, 138, 
    150,  53,  71, 221, 204, 173, 
     93, 252, 126,  53,  71,  53, 
    205, 180, 117, 221, 204,  10, 
     97, 250, 104, 203,  37,  73, 
     30,  74, 105,  50, 159, 214, 
    229,  97,  83, 200,  14, 218, 
     28, 139, 228, 152, 173, 201, 
     66,  78, 151, 227, 121,  33, 
     63,  68,  91, 209,  33, 121, 
    164, 160, 201, 137, 162,  46, 
    143,  78,   8, 153, 195, 154, 
     28, 172, 167, 136, 245, 184, 
     88, 207,  50, 214, 215,  70, 
     63, 139,  62, 251, 201, 117, 
     53, 125,  20, 241,  88,  73, 
    232,  54,  98, 169, 156, 210, 
    179, 136, 147,  21,  83, 127, 
    146, 181,  49, 243, 223, 173, 
    137, 185, 203, 228, 202, 227, 
     90,  73,  86, 244, 178, 156, 
     18, 149, 144, 187, 154, 116, 
    229, 137,  84,  73, 214, 210, 
    101, 249, 156,  89,   9, 185, 
     79,  90, 174, 124, 222,  46, 
    201,  83, 185, 178, 156, 206, 
     87, 100, 217, 168,   7,  85, 
    227, 114, 112, 210, 120,  39, 
    152,  49, 230, 131, 182, 241, 
    121,  16, 114,  59, 174,  28, 
     45, 148, 164,  93,  44, 203, 
    236,  68,  69,  50, 167,  11, 
    206,  99, 224,  44, 129, 115, 
     18, 156, 101, 112,  30,   7, 
    103,   5, 156,  83,  79, 200, 
    153,   3, 231,  33, 112, 230, 
    193, 121,  88, 113,  58, 224, 
     28,   3, 103,   1, 156, 227, 
    138, 179,   8, 206,  35, 224, 
    156,   0, 231,  81, 112,  50, 
     83,  26,  76,   6, 152,  76, 
     48, 101, 192, 116,  78, 127, 
    208,  67, 125, 240,  80, 125, 
     65, 244, 233, 238,  24, 199, 
     71, 106, 203,  80, 201, 176, 
    195, 129, 194,  76,  79,  60, 
     84,  10, 134, 175, 161,  45, 
    205,  81, 105,  39,  42, 116, 
    168, 171,  98,  25, 126,   6, 
     78, 168, 234, 148, 191,  37, 
    232,  36, 112,  37,  58, 243, 
    197,  70, 225, 238, 215, 149, 
    111, 248, 158, 245, 163, 122, 
    231, 142, 138, 220,  55,  30, 
    123,  26, 211,  53, 195,  47, 
     13, 127, 150,  42, 174, 232, 
    190, 138,  28, 184,  46,  51, 
    213, 151, 134,  45, 115, 153, 
      3,  57,  97, 205, 133, 231, 
     42, 242,  90, 158, 133,  99, 
    142, 109, 213,  62, 163, 226, 
     21, 152,  73,  47, 156, 245, 
     94,  95, 184, 232, 249, 221, 
    107, 205, 214,  71, 222, 165, 
    181, 174, 239,  93,  88, 235, 
    180,  86, 187, 139,  11, 151, 
     60, 191, 179, 234, 205, 191, 
    191, 210, 108, 117, 124, 239, 
    252, 250,   7, 237, 181, 235, 
    173, 166, 183, 216,  88, 223, 
    120, 251,  70, 171, 190, 238, 
    119, 235, 157, 245, 213, 150, 
    239,  95, 171, 207,  95,  92, 
    185, 233, 251, 107,  43,  55, 
    222, 184, 126, 179,  51, 187, 
     49, 123, 170, 221, 108,  96, 
    240,  72, 223, 170,  41, 185, 
    110, 228, 141, 226, 237, 230, 
    127,  91, 113, 121,  25,  45, 
     31, 178, 230, 158,  70, 165, 
    248,  31,  21, 209, 239, 147, 
     30,  87, 210,   0,   0,   0, 
     88,  72,  83,  72,   8,   0, 
      0,   0,  55, 135, 120,  26, 
    177, 153,  38, 158,  88,  80, 
     68,  80,  90,   0,   0,   0, 
     68,  58,  92,  65,  84,  71, 
     92, 115, 116,  95, 100, 101, 
    118,  92,  75, 105, 116, 115, 
     92,  68, 105, 114, 101,  99, 
    116,  88,  84,  75,  92, 115, 
    114,  99,  92,  83, 104,  97, 
    100, 101, 114, 115,  92,  67, 
    111, 109, 112, 105, 108, 101, 
    100,  92,  88,  98, 111, 120, 
     79, 110, 101,  80, 111, 115, 
    116,  80, 114, 111,  99, 101, 
    115, 115,  95,  80,  83,  71, 
     97, 117, 115, 115, 105,  97, 
    110,  66, 108, 117, 114,  53, 
    120,  53,  46, 112, 100,  98
};
