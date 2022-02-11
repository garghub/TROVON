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
int F_2 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_34 ;
T_1 V_35 = V_2 -> V_36 ;
struct V_37 * V_38 ;
memset ( V_33 , 0 , sizeof( struct V_32 ) ) ;
V_38 = (struct V_37 * ) V_2 -> V_39 ;
V_33 -> V_40 = V_41 ;
V_33 -> V_33 . V_42 . V_43 = F_3 ( V_35 ) ;
V_33 -> V_33 . V_42 . V_44 = F_4 ( V_35 ) ;
V_33 -> V_33 . V_42 . V_45 = F_5 ( V_38 -> V_46 ) ;
V_34 = F_1 ( V_2 , & V_33 -> V_33 . V_42 . V_47 ) ;
if ( V_34 )
F_6 ( L_1 ) ;
return V_34 ;
}
int F_7 ( struct V_48 * V_49 , enum V_50 V_51 )
{
int V_34 = 0 ;
unsigned int V_52 = 0 ;
struct V_53 * V_54 ;
struct V_55 * V_56 = V_49 -> V_56 ;
V_54 = & V_49 -> V_57 ;
V_54 -> V_51 = V_51 ;
V_54 -> V_58 = 0x1000 ;
V_34 = F_8 ( V_56 , V_54 -> V_58 , V_59 ,
V_60 ,
& V_56 -> V_61 . V_62 ,
& V_54 -> V_63 ,
( void * * ) & V_54 -> V_64 ) ;
if ( V_34 ) {
V_54 -> V_58 = 0 ;
return V_34 ;
}
V_52 = F_3 ( V_54 -> V_63 ) ;
F_9 ( V_65 , 0 , V_66 , V_52 ) ;
V_52 = F_4 ( V_54 -> V_63 ) ;
F_9 ( V_65 , 0 , V_67 , V_52 ) ;
V_52 = V_54 -> V_58 ;
F_9 ( V_65 , 0 , V_68 , V_52 ) ;
V_52 = V_51 ;
V_52 = V_52 << 16 ;
F_9 ( V_65 , 0 , V_69 , V_52 ) ;
V_52 = 0 ;
while ( ( V_52 & 0x80000000 ) == 0 ) {
V_52 = F_10 ( V_65 , 0 , V_69 ) ;
}
return 0 ;
}
int F_11 ( struct V_48 * V_49 ,
struct V_1 * V_2 ,
T_1 V_70 , T_1 V_71 ,
int V_72 )
{
unsigned int V_73 = 0 ;
struct V_74 * V_75 = V_49 -> V_57 . V_64 ;
struct V_53 * V_54 = & V_49 -> V_57 ;
struct V_55 * V_56 = V_49 -> V_56 ;
V_73 = F_10 ( V_65 , 0 , V_76 ) ;
if ( ( V_73 % V_54 -> V_58 ) == 0 )
V_75 = V_54 -> V_64 ;
else
V_75 = V_54 -> V_64 + ( V_73 / ( sizeof( struct V_74 ) / 4 ) ) ;
V_75 -> V_77 = F_4 ( V_70 ) ;
V_75 -> V_78 = F_3 ( V_70 ) ;
V_75 -> V_79 = F_4 ( V_71 ) ;
V_75 -> V_80 = F_3 ( V_71 ) ;
V_75 -> V_81 = V_72 ;
V_73 += sizeof( struct V_74 ) / 4 ;
V_73 = ( V_73 >= V_54 -> V_58 ) ? 0 : V_73 ;
F_9 ( V_65 , 0 , V_76 , V_73 ) ;
return 0 ;
}
static int
F_12 ( unsigned int * V_82 , unsigned int * V_83 ,
unsigned int * V_84 ,
enum V_85 V_4 )
{
int V_34 = 0 ;
switch( V_4 ) {
#if 0
case AMDGPU_UCODE_ID_SMC:
*sram_offset = 0;
*sram_addr_reg_offset = 0;
*sram_data_reg_offset = 0;
break;
#endif
case V_9 :
* V_82 = 0x0 ;
* V_83 = F_13 ( V_86 , 0 , V_87 ) ;
* V_84 = F_13 ( V_86 , 0 , V_88 ) ;
break;
case V_11 :
* V_82 = 0x0 ;
* V_83 = F_13 ( V_86 , 0 , V_89 ) ;
* V_84 = F_13 ( V_86 , 0 , V_90 ) ;
break;
case V_13 :
* V_82 = 0x0 ;
* V_83 = F_13 ( V_86 , 0 , V_91 ) ;
* V_84 = F_13 ( V_86 , 0 , V_92 ) ;
break;
case V_15 :
* V_82 = 0x10000 ;
* V_83 = F_13 ( V_86 , 0 , V_93 ) ;
* V_84 = F_13 ( V_86 , 0 , V_94 ) ;
break;
case V_19 :
* V_82 = 0x10000 ;
* V_83 = F_13 ( V_86 , 0 , V_95 ) ;
* V_84 = F_13 ( V_86 , 0 , V_96 ) ;
break;
case V_22 :
* V_82 = 0x2000 ;
* V_83 = F_13 ( V_86 , 0 , V_97 ) ;
* V_84 = F_13 ( V_86 , 0 , V_98 ) ;
break;
case V_5 :
* V_82 = 0x0 ;
* V_83 = F_13 ( V_99 , 0 , V_100 ) ;
* V_84 = F_13 ( V_99 , 0 , V_101 ) ;
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
V_34 = - V_31 ;
break;
}
return V_34 ;
}
bool F_14 ( struct V_48 * V_49 ,
struct V_1 * V_2 ,
enum V_85 V_102 )
{
int V_103 = 0 ;
unsigned int V_104 = 0 ;
unsigned int V_105 = 0 ;
unsigned int V_106 = 0 ;
unsigned int V_107 ;
T_2 * V_108 = NULL ;
struct V_55 * V_56 = V_49 -> V_56 ;
V_103 = F_12 ( & V_104 , & V_105 ,
& V_106 , V_102 ) ;
if ( V_103 )
return false ;
F_15 ( V_105 , V_104 ) ;
V_107 = V_2 -> V_107 ;
V_108 = ( T_2 * ) V_2 -> V_109 ;
while ( ! V_107 ) {
V_104 = F_16 ( V_106 ) ;
if ( * V_108 != V_104 )
return false ;
V_108 ++ ;
V_107 -= 4 ;
}
return true ;
}
