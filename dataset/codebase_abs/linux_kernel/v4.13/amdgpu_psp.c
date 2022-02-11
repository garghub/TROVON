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
V_5 -> V_15 = V_30 ;
V_5 -> V_17 = V_31 ;
V_5 -> V_23 = V_32 ;
V_5 -> V_25 = V_33 ;
break;
default:
return - V_34 ;
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
int F_7 ( struct V_4 * V_5 , T_1 V_35 ,
T_1 V_36 , T_1 V_37 , bool V_38 )
{
T_1 V_39 ;
int V_40 ;
struct V_2 * V_3 = V_5 -> V_3 ;
V_39 = F_8 ( V_35 ) ;
for ( V_40 = 0 ; V_40 < V_3 -> V_41 ; V_40 ++ ) {
if ( V_38 ) {
if ( V_39 != V_36 )
return 0 ;
} else {
if ( ( V_39 & V_37 ) == V_36 )
return 0 ;
}
F_9 ( 1 ) ;
}
return - V_42 ;
}
static int
F_10 ( struct V_4 * V_5 ,
struct V_43 * V_44 ,
struct V_45 * V_46 , T_2 V_47 ,
int V_48 )
{
int V_6 ;
struct V_49 * V_50 ;
T_2 V_51 ;
struct V_45 * V_52 ;
struct V_2 * V_3 = V_5 -> V_3 ;
V_6 = F_11 ( V_3 , V_53 , V_54 ,
V_55 ,
& V_50 , & V_51 ,
( void * * ) & V_52 ) ;
if ( V_6 )
return V_6 ;
memset ( V_52 , 0 , V_53 ) ;
memcpy ( V_52 , V_46 , sizeof( struct V_45 ) ) ;
V_6 = F_12 ( V_5 , V_44 , V_51 ,
V_47 , V_48 ) ;
while ( * ( ( unsigned int * ) V_5 -> V_56 ) != V_48 ) {
F_13 ( 1 ) ;
}
F_14 ( & V_50 ,
& V_51 ,
( void * * ) & V_52 ) ;
return V_6 ;
}
static void F_15 ( struct V_45 * V_46 ,
T_2 V_57 , T_1 V_58 )
{
V_46 -> V_59 = V_60 ;
V_46 -> V_46 . V_61 . V_62 = F_16 ( V_57 ) ;
V_46 -> V_46 . V_61 . V_63 = F_17 ( V_57 ) ;
V_46 -> V_46 . V_61 . V_64 = V_58 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_11 ( V_5 -> V_3 , 0x300000 , 0x100000 ,
V_55 ,
& V_5 -> V_65 , & V_5 -> V_66 , & V_5 -> V_67 ) ;
return V_6 ;
}
static int F_19 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_45 * V_46 ;
V_46 = F_20 ( sizeof( struct V_45 ) , V_68 ) ;
if ( ! V_46 )
return - V_69 ;
F_15 ( V_46 , V_5 -> V_66 , 0x300000 ) ;
V_6 = F_10 ( V_5 , NULL , V_46 ,
V_5 -> V_70 , 1 ) ;
if ( V_6 )
goto V_71;
F_21 ( V_46 ) ;
return 0 ;
V_71:
F_21 ( V_46 ) ;
return V_6 ;
}
static void F_22 ( struct V_45 * V_46 ,
T_2 V_72 , T_2 V_73 ,
T_1 V_58 , T_1 V_74 )
{
V_46 -> V_59 = V_75 ;
V_46 -> V_46 . V_76 . V_77 = F_16 ( V_72 ) ;
V_46 -> V_46 . V_76 . V_78 = F_17 ( V_72 ) ;
V_46 -> V_46 . V_76 . V_79 = V_58 ;
V_46 -> V_46 . V_76 . V_80 = F_16 ( V_73 ) ;
V_46 -> V_46 . V_76 . V_81 = F_17 ( V_73 ) ;
V_46 -> V_46 . V_76 . V_82 = V_74 ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_11 ( V_5 -> V_3 , V_83 ,
V_54 , V_55 ,
& V_5 -> V_84 ,
& V_5 -> V_85 ,
& V_5 -> V_86 ) ;
return V_6 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_45 * V_46 ;
if ( F_25 ( V_5 -> V_3 ) )
return 0 ;
V_46 = F_20 ( sizeof( struct V_45 ) , V_68 ) ;
if ( ! V_46 )
return - V_69 ;
memset ( V_5 -> V_87 , 0 , V_88 ) ;
memcpy ( V_5 -> V_87 , V_5 -> V_89 , V_5 -> V_90 ) ;
F_22 ( V_46 , V_5 -> V_91 , V_5 -> V_85 ,
V_5 -> V_90 , V_83 ) ;
V_6 = F_10 ( V_5 , NULL , V_46 ,
V_5 -> V_70 , 2 ) ;
F_21 ( V_46 ) ;
return V_6 ;
}
static int F_26 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_27 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_29 ( V_5 , V_92 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_19 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_24 ( V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 )
{
int V_40 , V_6 ;
struct V_43 * V_44 ;
struct V_2 * V_3 = V_5 -> V_3 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_93 . V_94 ; V_40 ++ ) {
V_44 = & V_3 -> V_93 . V_44 [ V_40 ] ;
if ( ! V_44 -> V_95 )
continue;
if ( V_44 -> V_96 == V_97 &&
F_31 ( V_5 ) )
continue;
if ( F_25 ( V_3 ) &&
( V_44 -> V_96 == V_98
|| V_44 -> V_96 == V_99
|| V_44 -> V_96 == V_100 ) )
continue;
V_6 = F_32 ( V_44 , V_5 -> V_46 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_5 , V_44 , V_5 -> V_46 ,
V_5 -> V_70 , V_40 + 3 ) ;
if ( V_6 )
return V_6 ;
#if 0
if (!amdgpu_psp_check_fw_loading_status(adev, i))
return -EINVAL;
#endif
}
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
int V_6 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
V_5 -> V_46 = F_20 ( sizeof( struct V_45 ) , V_68 ) ;
if ( ! V_5 -> V_46 )
return - V_69 ;
V_6 = F_11 ( V_3 , V_88 , V_88 ,
V_101 ,
& V_5 -> V_102 ,
& V_5 -> V_91 ,
& V_5 -> V_87 ) ;
if ( V_6 )
goto V_71;
V_6 = F_11 ( V_3 , V_103 , V_54 ,
V_55 ,
& V_5 -> V_104 ,
& V_5 -> V_70 ,
& V_5 -> V_56 ) ;
if ( V_6 )
goto V_105;
memset ( V_5 -> V_56 , 0 , V_103 ) ;
V_6 = F_34 ( V_5 , V_92 ) ;
if ( V_6 )
goto V_105;
V_6 = F_18 ( V_5 ) ;
if ( V_6 )
goto V_106;
V_6 = F_23 ( V_5 ) ;
if ( V_6 )
goto V_106;
V_6 = F_26 ( V_5 ) ;
if ( V_6 )
goto V_106;
V_6 = F_30 ( V_5 ) ;
if ( V_6 )
goto V_106;
return 0 ;
V_106:
F_14 ( & V_5 -> V_104 ,
& V_5 -> V_70 , & V_5 -> V_56 ) ;
V_105:
F_14 ( & V_5 -> V_102 ,
& V_5 -> V_91 , & V_5 -> V_87 ) ;
V_71:
F_21 ( V_5 -> V_46 ) ;
V_5 -> V_46 = NULL ;
return V_6 ;
}
static int F_35 ( void * V_1 )
{
int V_6 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_93 . V_107 != V_108 )
return 0 ;
F_36 ( & V_3 -> V_93 . V_109 ) ;
V_6 = F_37 ( V_3 ) ;
if ( V_6 )
goto V_71;
V_6 = F_33 ( V_3 ) ;
if ( V_6 ) {
F_5 ( L_2 ) ;
goto V_71;
}
F_38 ( & V_3 -> V_93 . V_109 ) ;
return 0 ;
V_71:
V_3 -> V_93 . V_107 = V_110 ;
F_38 ( & V_3 -> V_93 . V_109 ) ;
return - V_34 ;
}
static int F_39 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
if ( V_3 -> V_93 . V_107 != V_108 )
return 0 ;
F_40 ( V_3 ) ;
F_41 ( V_5 , V_92 ) ;
if ( V_5 -> V_67 )
F_14 ( & V_5 -> V_65 , & V_5 -> V_66 , & V_5 -> V_67 ) ;
if ( V_5 -> V_87 )
F_14 ( & V_5 -> V_102 ,
& V_5 -> V_91 , & V_5 -> V_87 ) ;
if ( V_5 -> V_104 )
F_14 ( & V_5 -> V_104 ,
& V_5 -> V_70 , & V_5 -> V_56 ) ;
F_21 ( V_5 -> V_46 ) ;
V_5 -> V_46 = NULL ;
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
if ( V_3 -> V_93 . V_107 != V_108 )
return 0 ;
F_44 ( L_3 ) ;
F_36 ( & V_3 -> V_93 . V_109 ) ;
V_6 = F_26 ( V_5 ) ;
if ( V_6 )
goto V_71;
V_6 = F_30 ( V_5 ) ;
if ( V_6 )
goto V_71;
F_38 ( & V_3 -> V_93 . V_109 ) ;
return 0 ;
V_71:
F_5 ( L_4 ) ;
F_38 ( & V_3 -> V_93 . V_109 ) ;
return V_6 ;
}
static bool F_45 ( struct V_2 * V_3 ,
enum V_111 V_112 )
{
struct V_43 * V_44 = NULL ;
if ( V_3 -> V_93 . V_107 != V_108 ) {
F_44 ( L_5 ) ;
return true ;
}
if ( ! V_3 -> V_93 . V_113 )
return false ;
V_44 = & V_3 -> V_93 . V_44 [ V_112 ] ;
if ( ! V_44 -> V_95 || ! V_44 -> V_114 )
return false ;
return F_46 ( & V_3 -> V_5 , V_44 , V_112 ) ;
}
static int F_47 ( void * V_1 ,
enum V_115 V_116 )
{
return 0 ;
}
static int F_48 ( void * V_1 ,
enum V_117 V_116 )
{
return 0 ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( NULL == V_3 -> V_93 . V_118 )
V_3 -> V_93 . V_118 = & V_119 ;
}
