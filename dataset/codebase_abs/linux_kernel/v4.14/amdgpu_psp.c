static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
return 0 ;
}
static int F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
int V_6 ;
switch ( V_3 -> V_7 ) {
case V_8 :
V_5 -> V_9 = V_10 ;
V_5 -> V_11 = V_12 ;
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = V_16 ;
V_5 -> V_17 = V_18 ;
V_5 -> V_19 = V_20 ;
V_5 -> V_21 = V_22 ;
V_5 -> V_23 = V_24 ;
V_5 -> V_25 = V_26 ;
V_5 -> V_27 = V_28 ;
break;
case V_29 :
#if 0
psp->init_microcode = psp_v10_0_init_microcode;
#endif
V_5 -> V_15 = V_30 ;
V_5 -> V_17 = V_31 ;
V_5 -> V_19 = V_32 ;
V_5 -> V_21 = V_33 ;
V_5 -> V_23 = V_34 ;
V_5 -> V_25 = V_35 ;
break;
default:
return - V_36 ;
}
V_5 -> V_3 = V_3 ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 ) {
F_5 ( L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_6 ( void * V_1 )
{
return 0 ;
}
int F_7 ( struct V_4 * V_5 , T_1 V_37 ,
T_1 V_38 , T_1 V_39 , bool V_40 )
{
T_1 V_41 ;
int V_42 ;
struct V_2 * V_3 = V_5 -> V_3 ;
for ( V_42 = 0 ; V_42 < V_3 -> V_43 ; V_42 ++ ) {
V_41 = F_8 ( V_37 ) ;
if ( V_40 ) {
if ( V_41 != V_38 )
return 0 ;
} else {
if ( ( V_41 & V_39 ) == V_38 )
return 0 ;
}
F_9 ( 1 ) ;
}
return - V_44 ;
}
static int
F_10 ( struct V_4 * V_5 ,
struct V_45 * V_46 ,
struct V_47 * V_48 , T_2 V_49 ,
int V_50 )
{
int V_6 ;
memset ( V_5 -> V_51 , 0 , V_52 ) ;
memcpy ( V_5 -> V_51 , V_48 , sizeof( struct V_47 ) ) ;
V_6 = F_11 ( V_5 , V_46 , V_5 -> V_53 ,
V_49 , V_50 ) ;
while ( * ( ( unsigned int * ) V_5 -> V_54 ) != V_50 ) {
F_12 ( 1 ) ;
}
return V_6 ;
}
static void F_13 ( struct V_47 * V_48 ,
T_2 V_55 , T_1 V_56 )
{
V_48 -> V_57 = V_58 ;
V_48 -> V_48 . V_59 . V_60 = F_14 ( V_55 ) ;
V_48 -> V_48 . V_59 . V_61 = F_15 ( V_55 ) ;
V_48 -> V_48 . V_59 . V_62 = V_56 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_17 ( V_5 -> V_3 , 0x300000 , 0x100000 ,
V_63 ,
& V_5 -> V_64 , & V_5 -> V_65 , & V_5 -> V_66 ) ;
return V_6 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_47 * V_48 ;
V_48 = F_19 ( sizeof( struct V_47 ) , V_67 ) ;
if ( ! V_48 )
return - V_68 ;
F_13 ( V_48 , V_5 -> V_65 , 0x300000 ) ;
V_6 = F_10 ( V_5 , NULL , V_48 ,
V_5 -> V_69 , 1 ) ;
if ( V_6 )
goto V_70;
F_20 ( V_48 ) ;
return 0 ;
V_70:
F_20 ( V_48 ) ;
return V_6 ;
}
static void F_21 ( struct V_47 * V_48 ,
T_2 V_71 , T_2 V_72 ,
T_1 V_56 , T_1 V_73 )
{
V_48 -> V_57 = V_74 ;
V_48 -> V_48 . V_75 . V_76 = F_14 ( V_71 ) ;
V_48 -> V_48 . V_75 . V_77 = F_15 ( V_71 ) ;
V_48 -> V_48 . V_75 . V_78 = V_56 ;
V_48 -> V_48 . V_75 . V_79 = F_14 ( V_72 ) ;
V_48 -> V_48 . V_75 . V_80 = F_15 ( V_72 ) ;
V_48 -> V_48 . V_75 . V_81 = V_73 ;
}
static int F_22 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_17 ( V_5 -> V_3 , V_82 ,
V_83 , V_63 ,
& V_5 -> V_84 ,
& V_5 -> V_85 ,
& V_5 -> V_86 ) ;
return V_6 ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_47 * V_48 ;
if ( F_24 ( V_5 -> V_3 ) )
return 0 ;
V_48 = F_19 ( sizeof( struct V_47 ) , V_67 ) ;
if ( ! V_48 )
return - V_68 ;
memset ( V_5 -> V_87 , 0 , V_88 ) ;
memcpy ( V_5 -> V_87 , V_5 -> V_89 , V_5 -> V_90 ) ;
F_21 ( V_48 , V_5 -> V_91 , V_5 -> V_85 ,
V_5 -> V_90 , V_82 ) ;
V_6 = F_10 ( V_5 , NULL , V_48 ,
V_5 -> V_69 , 2 ) ;
F_20 ( V_48 ) ;
return V_6 ;
}
static int F_25 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_26 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_27 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_5 , V_92 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_18 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_42 , V_6 ;
struct V_45 * V_46 ;
struct V_2 * V_3 = V_5 -> V_3 ;
for ( V_42 = 0 ; V_42 < V_3 -> V_93 . V_94 ; V_42 ++ ) {
V_46 = & V_3 -> V_93 . V_46 [ V_42 ] ;
if ( ! V_46 -> V_95 )
continue;
if ( V_46 -> V_96 == V_97 &&
F_30 ( V_5 ) )
continue;
if ( F_24 ( V_3 ) &&
( V_46 -> V_96 == V_98
|| V_46 -> V_96 == V_99
|| V_46 -> V_96 == V_100 ) )
continue;
V_6 = F_31 ( V_46 , V_5 -> V_48 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_5 , V_46 , V_5 -> V_48 ,
V_5 -> V_69 , V_42 + 3 ) ;
if ( V_6 )
return V_6 ;
#if 0
if (!amdgpu_psp_check_fw_loading_status(adev, i))
return -EINVAL;
#endif
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
int V_6 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
V_5 -> V_48 = F_19 ( sizeof( struct V_47 ) , V_67 ) ;
if ( ! V_5 -> V_48 )
return - V_68 ;
V_6 = F_17 ( V_3 , V_88 , V_88 ,
V_101 ,
& V_5 -> V_102 ,
& V_5 -> V_91 ,
& V_5 -> V_87 ) ;
if ( V_6 )
goto V_70;
V_6 = F_17 ( V_3 , V_103 , V_83 ,
V_63 ,
& V_5 -> V_104 ,
& V_5 -> V_69 ,
& V_5 -> V_54 ) ;
if ( V_6 )
goto V_105;
V_6 = F_17 ( V_3 , V_52 , V_83 ,
V_63 ,
& V_5 -> V_106 , & V_5 -> V_53 ,
( void * * ) & V_5 -> V_51 ) ;
if ( V_6 )
goto V_107;
memset ( V_5 -> V_54 , 0 , V_103 ) ;
V_6 = F_33 ( V_5 , V_92 ) ;
if ( V_6 )
goto V_108;
V_6 = F_16 ( V_5 ) ;
if ( V_6 )
goto V_108;
V_6 = F_22 ( V_5 ) ;
if ( V_6 )
goto V_108;
V_6 = F_25 ( V_5 ) ;
if ( V_6 )
goto V_108;
V_6 = F_29 ( V_5 ) ;
if ( V_6 )
goto V_108;
return 0 ;
V_108:
F_34 ( & V_5 -> V_106 ,
& V_5 -> V_53 ,
( void * * ) & V_5 -> V_51 ) ;
V_107:
F_34 ( & V_5 -> V_104 ,
& V_5 -> V_69 , & V_5 -> V_54 ) ;
V_105:
F_34 ( & V_5 -> V_102 ,
& V_5 -> V_91 , & V_5 -> V_87 ) ;
V_70:
F_20 ( V_5 -> V_48 ) ;
V_5 -> V_48 = NULL ;
return V_6 ;
}
static int F_35 ( void * V_1 )
{
int V_6 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_93 . V_109 != V_110 )
return 0 ;
F_36 ( & V_3 -> V_93 . V_111 ) ;
V_6 = F_37 ( V_3 ) ;
if ( V_6 )
goto V_70;
V_6 = F_32 ( V_3 ) ;
if ( V_6 ) {
F_5 ( L_2 ) ;
goto V_70;
}
F_38 ( & V_3 -> V_93 . V_111 ) ;
return 0 ;
V_70:
V_3 -> V_93 . V_109 = V_112 ;
F_38 ( & V_3 -> V_93 . V_111 ) ;
return - V_36 ;
}
static int F_39 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
if ( V_3 -> V_93 . V_109 != V_110 )
return 0 ;
F_40 ( V_3 ) ;
F_41 ( V_5 , V_92 ) ;
F_34 ( & V_5 -> V_64 , & V_5 -> V_65 , & V_5 -> V_66 ) ;
F_34 ( & V_5 -> V_102 ,
& V_5 -> V_91 , & V_5 -> V_87 ) ;
F_34 ( & V_5 -> V_104 ,
& V_5 -> V_69 , & V_5 -> V_54 ) ;
F_34 ( & V_5 -> V_84 , & V_5 -> V_85 ,
& V_5 -> V_86 ) ;
F_34 ( & V_5 -> V_106 , & V_5 -> V_53 ,
( void * * ) & V_5 -> V_51 ) ;
F_20 ( V_5 -> V_48 ) ;
V_5 -> V_48 = NULL ;
return 0 ;
}
static int F_42 ( void * V_1 )
{
return 0 ;
}
static int F_43 ( void * V_1 )
{
int V_6 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
if ( V_3 -> V_93 . V_109 != V_110 )
return 0 ;
F_44 ( L_3 ) ;
F_36 ( & V_3 -> V_93 . V_111 ) ;
V_6 = F_25 ( V_5 ) ;
if ( V_6 )
goto V_70;
V_6 = F_29 ( V_5 ) ;
if ( V_6 )
goto V_70;
F_38 ( & V_3 -> V_93 . V_111 ) ;
return 0 ;
V_70:
F_5 ( L_4 ) ;
F_38 ( & V_3 -> V_93 . V_111 ) ;
return V_6 ;
}
static bool F_45 ( struct V_2 * V_3 ,
enum V_113 V_114 )
{
struct V_45 * V_46 = NULL ;
if ( V_3 -> V_93 . V_109 != V_110 ) {
F_44 ( L_5 ) ;
return true ;
}
if ( ! V_3 -> V_93 . V_115 )
return false ;
V_46 = & V_3 -> V_93 . V_46 [ V_114 ] ;
if ( ! V_46 -> V_95 || ! V_46 -> V_116 )
return false ;
return F_46 ( & V_3 -> V_5 , V_46 , V_114 ) ;
}
static int F_47 ( void * V_1 ,
enum V_117 V_118 )
{
return 0 ;
}
static int F_48 ( void * V_1 ,
enum V_119 V_118 )
{
return 0 ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( NULL == V_3 -> V_93 . V_120 )
V_3 -> V_93 . V_120 = & V_121 ;
}
