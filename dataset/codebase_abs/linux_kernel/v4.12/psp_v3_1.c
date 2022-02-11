static int
F_1 ( struct V_1 * V_2 , enum V_3 * type )
{
switch( V_2 -> V_4 ) {
case V_5 :
* type = V_6 ;
break;
case V_7 :
* type = V_8 ;
break;
case V_9 :
* type = V_10 ;
break;
case V_11 :
* type = V_12 ;
break;
case V_13 :
* type = V_14 ;
break;
case V_15 :
* type = V_16 ;
break;
case V_17 :
* type = V_18 ;
break;
case V_19 :
* type = V_16 ;
break;
case V_20 :
* type = V_21 ;
break;
case V_22 :
* type = V_23 ;
break;
case V_24 :
* type = V_25 ;
break;
case V_26 :
* type = V_27 ;
break;
case V_28 :
* type = V_29 ;
break;
case V_30 :
default:
return - V_31 ;
}
return 0 ;
}
int F_2 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
const char * V_36 ;
char V_37 [ 30 ] ;
int V_38 = 0 ;
const struct V_39 * V_40 ;
F_3 ( L_1 ) ;
switch ( V_35 -> V_41 ) {
case V_42 :
V_36 = L_2 ;
break;
default: F_4 () ;
}
snprintf ( V_37 , sizeof( V_37 ) , L_3 , V_36 ) ;
V_38 = F_5 ( & V_35 -> V_33 . V_43 , V_37 , V_35 -> V_44 ) ;
if ( V_38 )
goto V_45;
V_38 = F_6 ( V_35 -> V_33 . V_43 ) ;
if ( V_38 )
goto V_45;
V_40 = ( const struct V_39 * ) V_35 -> V_33 . V_43 -> V_46 ;
V_35 -> V_33 . V_47 = F_7 ( V_40 -> V_48 . V_49 ) ;
V_35 -> V_33 . V_50 = F_7 ( V_40 -> V_51 ) ;
V_35 -> V_33 . V_52 = F_7 ( V_40 -> V_53 ) ;
V_35 -> V_33 . V_54 = F_7 ( V_40 -> V_48 . V_55 ) -
F_7 ( V_40 -> V_53 ) ;
V_35 -> V_33 . V_56 = ( V_57 * ) V_40 +
F_7 ( V_40 -> V_48 . V_58 ) ;
V_35 -> V_33 . V_59 = ( V_57 * ) V_35 -> V_33 . V_56 +
F_7 ( V_40 -> V_60 ) ;
snprintf ( V_37 , sizeof( V_37 ) , L_4 , V_36 ) ;
V_38 = F_5 ( & V_35 -> V_33 . V_61 , V_37 , V_35 -> V_44 ) ;
if ( V_38 )
goto V_45;
V_38 = F_6 ( V_35 -> V_33 . V_61 ) ;
if ( V_38 )
goto V_45;
V_40 = ( const struct V_39 * ) V_35 -> V_33 . V_61 -> V_46 ;
V_35 -> V_33 . V_62 = F_7 ( V_40 -> V_48 . V_49 ) ;
V_35 -> V_33 . V_63 = F_7 ( V_40 -> V_51 ) ;
V_35 -> V_33 . V_64 = F_7 ( V_40 -> V_48 . V_55 ) ;
V_35 -> V_33 . V_65 = ( V_57 * ) V_40 +
F_7 ( V_40 -> V_48 . V_58 ) ;
return 0 ;
V_45:
if ( V_38 ) {
F_8 ( V_35 -> V_44 ,
L_5 ,
V_37 ) ;
F_9 ( V_35 -> V_33 . V_43 ) ;
V_35 -> V_33 . V_43 = NULL ;
F_9 ( V_35 -> V_33 . V_61 ) ;
V_35 -> V_33 . V_61 = NULL ;
}
return V_38 ;
}
int F_10 ( struct V_32 * V_33 )
{
int V_66 ;
T_1 V_67 = 0 ;
struct V_34 * V_35 = V_33 -> V_35 ;
T_1 V_68 ;
V_68 = F_11 ( F_12 ( V_69 , 0 , V_70 ) ) ;
if ( V_68 )
return 0 ;
V_66 = F_13 ( V_33 , F_12 ( V_69 , 0 , V_71 ) ,
0x80000000 , 0x80000000 , false ) ;
if ( V_66 )
return V_66 ;
memset ( V_33 -> V_72 , 0 , V_73 ) ;
memcpy ( V_33 -> V_72 , V_33 -> V_56 , V_33 -> V_54 ) ;
F_14 ( F_12 ( V_69 , 0 , V_74 ) ,
( T_1 ) ( V_33 -> V_75 >> 20 ) ) ;
V_67 = 1 << 16 ;
F_14 ( F_12 ( V_69 , 0 , V_71 ) ,
V_67 ) ;
F_15 ( 20 ) ;
V_66 = F_13 ( V_33 , F_12 ( V_69 , 0 , V_71 ) ,
0x80000000 , 0x80000000 , false ) ;
return V_66 ;
}
int F_16 ( struct V_32 * V_33 )
{
int V_66 ;
unsigned int V_67 = 0 ;
struct V_34 * V_35 = V_33 -> V_35 ;
T_1 V_68 ;
V_68 = F_11 ( F_12 ( V_69 , 0 , V_70 ) ) ;
if ( V_68 )
return 0 ;
V_66 = F_13 ( V_33 , F_12 ( V_69 , 0 , V_71 ) ,
0x80000000 , 0x80000000 , false ) ;
if ( V_66 )
return V_66 ;
memset ( V_33 -> V_72 , 0 , V_73 ) ;
memcpy ( V_33 -> V_72 , V_33 -> V_59 , V_33 -> V_52 ) ;
F_14 ( F_12 ( V_69 , 0 , V_74 ) ,
( T_1 ) ( V_33 -> V_75 >> 20 ) ) ;
V_67 = 2 << 16 ;
F_14 ( F_12 ( V_69 , 0 , V_71 ) ,
V_67 ) ;
F_15 ( 20 ) ;
#if 0
ret = psp_wait_for(psp, SOC15_REG_OFFSET(MP0, 0, mmMP0_SMN_C2PMSG_81),
RREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_SMN_C2PMSG_81)),
0, true);
#endif
return V_66 ;
}
int F_17 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
int V_66 ;
T_2 V_78 = V_2 -> V_79 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_80 = V_81 ;
V_77 -> V_77 . V_82 . V_83 = ( T_1 ) V_78 ;
V_77 -> V_77 . V_82 . V_84 = ( T_1 ) ( ( T_2 ) V_78 >> 32 ) ;
V_77 -> V_77 . V_82 . V_85 = V_2 -> V_86 ;
V_66 = F_1 ( V_2 , & V_77 -> V_77 . V_82 . V_87 ) ;
if ( V_66 )
F_18 ( L_6 ) ;
return V_66 ;
}
int F_19 ( struct V_32 * V_33 , enum V_88 V_89 )
{
int V_66 = 0 ;
struct V_90 * V_91 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_91 = & V_33 -> V_92 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_93 = 0x1000 ;
V_66 = F_20 ( V_35 , V_91 -> V_93 , V_94 ,
V_95 ,
& V_35 -> V_96 . V_97 ,
& V_91 -> V_98 ,
( void * * ) & V_91 -> V_99 ) ;
if ( V_66 ) {
V_91 -> V_93 = 0 ;
return V_66 ;
}
return 0 ;
}
int F_21 ( struct V_32 * V_33 , enum V_88 V_89 )
{
int V_66 = 0 ;
unsigned int V_100 = 0 ;
struct V_90 * V_91 = & V_33 -> V_92 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_100 = F_22 ( V_91 -> V_98 ) ;
F_14 ( F_12 ( V_69 , 0 , V_101 ) , V_100 ) ;
V_100 = F_23 ( V_91 -> V_98 ) ;
F_14 ( F_12 ( V_69 , 0 , V_102 ) , V_100 ) ;
V_100 = V_91 -> V_93 ;
F_14 ( F_12 ( V_69 , 0 , V_103 ) , V_100 ) ;
V_100 = V_89 ;
V_100 = V_100 << 16 ;
F_14 ( F_12 ( V_69 , 0 , V_104 ) , V_100 ) ;
F_15 ( 20 ) ;
V_66 = F_13 ( V_33 , F_12 ( V_69 , 0 , V_104 ) ,
0x80000000 , 0x8000FFFF , false ) ;
return V_66 ;
}
int F_24 ( struct V_32 * V_33 , enum V_88 V_89 )
{
int V_66 = 0 ;
struct V_90 * V_91 ;
unsigned int V_100 = 0 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_91 = & V_33 -> V_92 ;
V_100 = 3 << 16 ;
F_14 ( F_12 ( V_69 , 0 , V_104 ) , V_100 ) ;
F_15 ( 20 ) ;
V_66 = F_13 ( V_33 , F_12 ( V_69 , 0 , V_104 ) ,
0x80000000 , 0x80000000 , false ) ;
if ( V_91 -> V_99 )
F_25 ( & V_35 -> V_96 . V_97 ,
& V_91 -> V_98 ,
( void * * ) & V_91 -> V_99 ) ;
return V_66 ;
}
int F_26 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_2 V_105 , T_2 V_106 ,
int V_107 )
{
unsigned int V_108 = 0 ;
struct V_109 * V_110 = V_33 -> V_92 . V_99 ;
struct V_90 * V_91 = & V_33 -> V_92 ;
struct V_34 * V_35 = V_33 -> V_35 ;
T_1 V_111 = V_91 -> V_93 / 4 ;
T_1 V_112 = sizeof( struct V_109 ) / 4 ;
V_108 = F_11 ( F_12 ( V_69 , 0 , V_113 ) ) ;
if ( ( V_108 % V_111 ) == 0 )
V_110 = V_91 -> V_99 ;
else
V_110 = V_91 -> V_99 + ( V_108 / V_112 ) ;
memset ( V_110 , 0 , sizeof( struct V_109 ) ) ;
V_110 -> V_114 = ( unsigned int ) ( V_105 >> 32 ) ;
V_110 -> V_115 = ( unsigned int ) ( V_105 ) ;
V_110 -> V_116 = ( unsigned int ) ( V_106 >> 32 ) ;
V_110 -> V_117 = ( unsigned int ) ( V_106 ) ;
V_110 -> V_118 = V_107 ;
V_108 = ( V_108 + V_112 ) % V_111 ;
F_14 ( F_12 ( V_69 , 0 , V_113 ) , V_108 ) ;
return 0 ;
}
static int
F_27 ( unsigned int * V_119 , unsigned int * V_120 ,
unsigned int * V_121 ,
enum V_122 V_4 )
{
int V_66 = 0 ;
switch( V_4 ) {
#if 0
case AMDGPU_UCODE_ID_SMC:
*sram_offset = 0;
*sram_addr_reg_offset = 0;
*sram_data_reg_offset = 0;
break;
#endif
case V_9 :
* V_119 = 0x0 ;
* V_120 = F_12 ( V_123 , 0 , V_124 ) ;
* V_121 = F_12 ( V_123 , 0 , V_125 ) ;
break;
case V_11 :
* V_119 = 0x0 ;
* V_120 = F_12 ( V_123 , 0 , V_126 ) ;
* V_121 = F_12 ( V_123 , 0 , V_127 ) ;
break;
case V_13 :
* V_119 = 0x0 ;
* V_120 = F_12 ( V_123 , 0 , V_128 ) ;
* V_121 = F_12 ( V_123 , 0 , V_129 ) ;
break;
case V_15 :
* V_119 = 0x10000 ;
* V_120 = F_12 ( V_123 , 0 , V_130 ) ;
* V_121 = F_12 ( V_123 , 0 , V_131 ) ;
break;
case V_19 :
* V_119 = 0x10000 ;
* V_120 = F_12 ( V_123 , 0 , V_132 ) ;
* V_121 = F_12 ( V_123 , 0 , V_133 ) ;
break;
case V_22 :
* V_119 = 0x2000 ;
* V_120 = F_12 ( V_123 , 0 , V_134 ) ;
* V_121 = F_12 ( V_123 , 0 , V_135 ) ;
break;
case V_5 :
* V_119 = 0x0 ;
* V_120 = F_12 ( V_136 , 0 , V_137 ) ;
* V_121 = F_12 ( V_136 , 0 , V_138 ) ;
break;
#if 0
case AMDGPU_UCODE_ID_SDMA1:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
case AMDGPU_UCODE_ID_UVD:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
case AMDGPU_UCODE_ID_VCE:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
#endif
case V_30 :
default:
V_66 = - V_31 ;
break;
}
return V_66 ;
}
bool F_28 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
enum V_122 V_139 )
{
int V_38 = 0 ;
unsigned int V_140 = 0 ;
unsigned int V_141 = 0 ;
unsigned int V_142 = 0 ;
unsigned int V_86 ;
T_1 * V_143 = NULL ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_38 = F_27 ( & V_140 , & V_141 ,
& V_142 , V_139 ) ;
if ( V_38 )
return false ;
F_14 ( V_141 , V_140 ) ;
V_86 = V_2 -> V_86 ;
V_143 = ( T_1 * ) V_2 -> V_144 ;
while ( V_86 ) {
V_140 = F_11 ( V_142 ) ;
if ( * V_143 != V_140 )
return false ;
V_143 ++ ;
V_86 -= 4 ;
}
return true ;
}
bool F_29 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
T_1 V_145 ;
V_145 = V_146 | 0x03b00000 ;
F_14 ( F_12 ( V_147 , 0 , V_148 ) , V_145 ) ;
V_145 = F_11 ( F_12 ( V_147 , 0 , V_149 ) ) ;
return ( V_145 & V_150 ) ? true : false ;
}
