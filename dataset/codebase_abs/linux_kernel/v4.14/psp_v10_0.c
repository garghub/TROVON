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
V_35 -> V_33 . V_52 = F_7 ( V_40 -> V_48 . V_53 ) ;
V_35 -> V_33 . V_54 = ( V_55 * ) V_40 +
F_7 ( V_40 -> V_48 . V_56 ) ;
return 0 ;
V_45:
if ( V_38 ) {
F_8 ( V_35 -> V_44 ,
L_4 ,
V_37 ) ;
F_9 ( V_35 -> V_33 . V_43 ) ;
V_35 -> V_33 . V_43 = NULL ;
}
return V_38 ;
}
int F_10 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
int V_59 ;
T_1 V_60 = V_2 -> V_61 ;
struct V_62 * V_48 ;
memset ( V_58 , 0 , sizeof( struct V_57 ) ) ;
V_48 = (struct V_62 * ) V_2 -> V_63 ;
V_58 -> V_64 = V_65 ;
V_58 -> V_58 . V_66 . V_67 = F_11 ( V_60 ) ;
V_58 -> V_58 . V_66 . V_68 = F_12 ( V_60 ) ;
V_58 -> V_58 . V_66 . V_69 = F_7 ( V_48 -> V_53 ) ;
V_59 = F_1 ( V_2 , & V_58 -> V_58 . V_66 . V_70 ) ;
if ( V_59 )
F_13 ( L_5 ) ;
return V_59 ;
}
int F_14 ( struct V_32 * V_33 , enum V_71 V_72 )
{
int V_59 = 0 ;
struct V_73 * V_74 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_74 = & V_33 -> V_75 ;
V_74 -> V_72 = V_72 ;
V_74 -> V_76 = 0x1000 ;
V_59 = F_15 ( V_35 , V_74 -> V_76 , V_77 ,
V_78 ,
& V_35 -> V_79 . V_80 ,
& V_74 -> V_81 ,
( void * * ) & V_74 -> V_82 ) ;
if ( V_59 ) {
V_74 -> V_76 = 0 ;
return V_59 ;
}
return 0 ;
}
int F_16 ( struct V_32 * V_33 , enum V_71 V_72 )
{
int V_59 = 0 ;
unsigned int V_83 = 0 ;
struct V_73 * V_74 = & V_33 -> V_75 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_83 = F_11 ( V_74 -> V_81 ) ;
F_17 ( V_84 , 0 , V_85 , V_83 ) ;
V_83 = F_12 ( V_74 -> V_81 ) ;
F_17 ( V_84 , 0 , V_86 , V_83 ) ;
V_83 = V_74 -> V_76 ;
F_17 ( V_84 , 0 , V_87 , V_83 ) ;
V_83 = V_72 ;
V_83 = V_83 << 16 ;
F_17 ( V_84 , 0 , V_88 , V_83 ) ;
F_18 ( 20 ) ;
V_59 = F_19 ( V_33 , F_20 ( V_84 , 0 , V_88 ) ,
0x80000000 , 0x8000FFFF , false ) ;
return V_59 ;
}
int F_21 ( struct V_32 * V_33 , enum V_71 V_72 )
{
int V_59 = 0 ;
struct V_73 * V_74 ;
unsigned int V_83 = 0 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_74 = & V_33 -> V_75 ;
V_83 = 3 << 16 ;
F_17 ( V_84 , 0 , V_88 , V_83 ) ;
F_18 ( 20 ) ;
V_59 = F_19 ( V_33 , F_20 ( V_84 , 0 , V_88 ) ,
0x80000000 , 0x80000000 , false ) ;
F_22 ( & V_35 -> V_79 . V_80 ,
& V_74 -> V_81 ,
( void * * ) & V_74 -> V_82 ) ;
return V_59 ;
}
int F_23 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_1 V_89 , T_1 V_90 ,
int V_91 )
{
unsigned int V_92 = 0 ;
struct V_93 * V_94 = V_33 -> V_75 . V_82 ;
struct V_73 * V_74 = & V_33 -> V_75 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_92 = F_24 ( V_84 , 0 , V_95 ) ;
if ( ( V_92 % V_74 -> V_76 ) == 0 )
V_94 = V_74 -> V_82 ;
else
V_94 = V_74 -> V_82 + ( V_92 / ( sizeof( struct V_93 ) / 4 ) ) ;
V_94 -> V_96 = F_12 ( V_89 ) ;
V_94 -> V_97 = F_11 ( V_89 ) ;
V_94 -> V_98 = F_12 ( V_90 ) ;
V_94 -> V_99 = F_11 ( V_90 ) ;
V_94 -> V_100 = V_91 ;
V_92 += sizeof( struct V_93 ) / 4 ;
V_92 = ( V_92 >= V_74 -> V_76 ) ? 0 : V_92 ;
F_17 ( V_84 , 0 , V_95 , V_92 ) ;
return 0 ;
}
static int
F_25 ( unsigned int * V_101 , unsigned int * V_102 ,
unsigned int * V_103 ,
enum V_104 V_4 )
{
int V_59 = 0 ;
switch( V_4 ) {
#if 0
case AMDGPU_UCODE_ID_SMC:
*sram_offset = 0;
*sram_addr_reg_offset = 0;
*sram_data_reg_offset = 0;
break;
#endif
case V_9 :
* V_101 = 0x0 ;
* V_102 = F_20 ( V_105 , 0 , V_106 ) ;
* V_103 = F_20 ( V_105 , 0 , V_107 ) ;
break;
case V_11 :
* V_101 = 0x0 ;
* V_102 = F_20 ( V_105 , 0 , V_108 ) ;
* V_103 = F_20 ( V_105 , 0 , V_109 ) ;
break;
case V_13 :
* V_101 = 0x0 ;
* V_102 = F_20 ( V_105 , 0 , V_110 ) ;
* V_103 = F_20 ( V_105 , 0 , V_111 ) ;
break;
case V_15 :
* V_101 = 0x10000 ;
* V_102 = F_20 ( V_105 , 0 , V_112 ) ;
* V_103 = F_20 ( V_105 , 0 , V_113 ) ;
break;
case V_19 :
* V_101 = 0x10000 ;
* V_102 = F_20 ( V_105 , 0 , V_114 ) ;
* V_103 = F_20 ( V_105 , 0 , V_115 ) ;
break;
case V_22 :
* V_101 = 0x2000 ;
* V_102 = F_20 ( V_105 , 0 , V_116 ) ;
* V_103 = F_20 ( V_105 , 0 , V_117 ) ;
break;
case V_5 :
* V_101 = 0x0 ;
* V_102 = F_20 ( V_118 , 0 , V_119 ) ;
* V_103 = F_20 ( V_118 , 0 , V_120 ) ;
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
V_59 = - V_31 ;
break;
}
return V_59 ;
}
bool F_26 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
enum V_104 V_121 )
{
int V_38 = 0 ;
unsigned int V_122 = 0 ;
unsigned int V_123 = 0 ;
unsigned int V_124 = 0 ;
unsigned int V_125 ;
T_2 * V_126 = NULL ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_38 = F_25 ( & V_122 , & V_123 ,
& V_124 , V_121 ) ;
if ( V_38 )
return false ;
F_27 ( V_123 , V_122 ) ;
V_125 = V_2 -> V_125 ;
V_126 = ( T_2 * ) V_2 -> V_127 ;
while ( ! V_125 ) {
V_122 = F_28 ( V_124 ) ;
if ( * V_126 != V_122 )
return false ;
V_126 ++ ;
V_125 -= 4 ;
}
return true ;
}
