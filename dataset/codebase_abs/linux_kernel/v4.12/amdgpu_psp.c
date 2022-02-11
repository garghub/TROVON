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
default:
return - V_29 ;
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
int F_7 ( struct V_4 * V_5 , T_1 V_30 ,
T_1 V_31 , T_1 V_32 , bool V_33 )
{
T_1 V_34 ;
int V_35 ;
struct V_2 * V_3 = V_5 -> V_3 ;
V_34 = F_8 ( V_30 ) ;
for ( V_35 = 0 ; V_35 < V_3 -> V_36 ; V_35 ++ ) {
if ( V_33 ) {
if ( V_34 != V_31 )
return 0 ;
} else {
if ( ( V_34 & V_32 ) == V_31 )
return 0 ;
}
F_9 ( 1 ) ;
}
return - V_37 ;
}
static int
F_10 ( struct V_4 * V_5 ,
struct V_38 * V_39 ,
struct V_40 * V_41 , T_2 V_42 ,
int V_43 )
{
int V_6 ;
struct V_44 * V_45 ;
T_2 V_46 ;
struct V_40 * V_47 ;
struct V_2 * V_3 = V_5 -> V_3 ;
V_6 = F_11 ( V_3 , V_48 , V_49 ,
V_50 ,
& V_45 , & V_46 ,
( void * * ) & V_47 ) ;
if ( V_6 )
return V_6 ;
memset ( V_47 , 0 , V_48 ) ;
memcpy ( V_47 , V_41 , sizeof( struct V_40 ) ) ;
V_6 = F_12 ( V_5 , V_39 , V_46 ,
V_42 , V_43 ) ;
while ( * ( ( unsigned int * ) V_5 -> V_51 ) != V_43 ) {
F_13 ( 1 ) ;
}
F_14 ( & V_45 ,
& V_46 ,
( void * * ) & V_47 ) ;
return V_6 ;
}
static void F_15 ( struct V_40 * V_41 ,
T_2 V_52 , T_1 V_53 )
{
V_41 -> V_54 = V_55 ;
V_41 -> V_41 . V_56 . V_57 = ( T_1 ) V_52 ;
V_41 -> V_41 . V_56 . V_58 = ( T_1 ) ( V_52 >> 32 ) ;
V_41 -> V_41 . V_56 . V_59 = V_53 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_11 ( V_5 -> V_3 , 0x300000 , 0x100000 ,
V_50 ,
& V_5 -> V_60 , & V_5 -> V_61 , & V_5 -> V_62 ) ;
return V_6 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_40 * V_41 ;
V_41 = F_18 ( sizeof( struct V_40 ) , V_63 ) ;
if ( ! V_41 )
return - V_64 ;
F_15 ( V_41 , V_5 -> V_61 , 0x300000 ) ;
V_6 = F_10 ( V_5 , NULL , V_41 ,
V_5 -> V_65 , 1 ) ;
if ( V_6 )
goto V_66;
F_19 ( V_41 ) ;
return 0 ;
V_66:
F_19 ( V_41 ) ;
return V_6 ;
}
static void F_20 ( struct V_40 * V_41 ,
T_2 V_67 , T_2 V_68 ,
T_1 V_53 , T_1 V_69 )
{
V_41 -> V_54 = V_70 ;
V_41 -> V_41 . V_71 . V_72 = F_21 ( V_67 ) ;
V_41 -> V_41 . V_71 . V_73 = F_22 ( V_67 ) ;
V_41 -> V_41 . V_71 . V_74 = V_53 ;
V_41 -> V_41 . V_71 . V_75 = F_21 ( V_68 ) ;
V_41 -> V_41 . V_71 . V_76 = F_22 ( V_68 ) ;
V_41 -> V_41 . V_71 . V_77 = V_69 ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_11 ( V_5 -> V_3 , V_78 ,
V_49 , V_50 ,
& V_5 -> V_79 ,
& V_5 -> V_80 ,
& V_5 -> V_81 ) ;
return V_6 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_40 * V_41 ;
V_41 = F_18 ( sizeof( struct V_40 ) , V_63 ) ;
if ( ! V_41 )
return - V_64 ;
memset ( V_5 -> V_82 , 0 , V_83 ) ;
memcpy ( V_5 -> V_82 , V_5 -> V_84 , V_5 -> V_85 ) ;
F_20 ( V_41 , V_5 -> V_86 , V_5 -> V_80 ,
V_5 -> V_85 , V_78 ) ;
V_6 = F_10 ( V_5 , NULL , V_41 ,
V_5 -> V_65 , 2 ) ;
F_19 ( V_41 ) ;
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
V_6 = F_28 ( V_5 , V_87 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_17 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_24 ( V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_35 , V_6 ;
struct V_38 * V_39 ;
struct V_2 * V_3 = V_5 -> V_3 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_88 . V_89 ; V_35 ++ ) {
V_39 = & V_3 -> V_88 . V_39 [ V_35 ] ;
if ( ! V_39 -> V_90 )
continue;
if ( V_39 -> V_91 == V_92 &&
F_30 ( V_5 ) )
continue;
if ( F_31 ( V_3 ) &&
( V_39 -> V_91 == V_93
|| V_39 -> V_91 == V_94
|| V_39 -> V_91 == V_95 ) )
continue;
V_6 = F_32 ( V_39 , V_5 -> V_41 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_5 , V_39 , V_5 -> V_41 ,
V_5 -> V_65 , V_35 + 3 ) ;
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
struct V_40 * V_41 ;
V_41 = F_18 ( sizeof( struct V_40 ) , V_63 ) ;
if ( ! V_41 )
return - V_64 ;
V_5 -> V_41 = V_41 ;
V_6 = F_11 ( V_3 , V_83 , V_83 ,
V_96 ,
& V_5 -> V_97 ,
& V_5 -> V_86 ,
& V_5 -> V_82 ) ;
if ( V_6 )
goto V_66;
V_6 = F_11 ( V_3 , V_98 , V_49 ,
V_50 ,
& V_5 -> V_99 ,
& V_5 -> V_65 ,
& V_5 -> V_51 ) ;
if ( V_6 )
goto V_100;
memset ( V_5 -> V_51 , 0 , V_98 ) ;
V_6 = F_34 ( V_5 , V_87 ) ;
if ( V_6 )
goto V_100;
V_6 = F_16 ( V_5 ) ;
if ( V_6 )
goto V_101;
V_6 = F_23 ( V_5 ) ;
if ( V_6 )
goto V_101;
V_6 = F_25 ( V_5 ) ;
if ( V_6 )
goto V_101;
V_6 = F_29 ( V_5 ) ;
if ( V_6 )
goto V_101;
F_19 ( V_41 ) ;
return 0 ;
V_101:
F_14 ( & V_5 -> V_99 ,
& V_5 -> V_65 , & V_5 -> V_51 ) ;
V_100:
F_14 ( & V_5 -> V_97 ,
& V_5 -> V_86 , & V_5 -> V_82 ) ;
V_66:
F_19 ( V_41 ) ;
return V_6 ;
}
static int F_35 ( void * V_1 )
{
int V_6 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_88 . V_102 != V_103 )
return 0 ;
F_36 ( & V_3 -> V_88 . V_104 ) ;
V_6 = F_37 ( V_3 ) ;
if ( V_6 )
goto V_66;
V_6 = F_33 ( V_3 ) ;
if ( V_6 ) {
F_5 ( L_2 ) ;
goto V_66;
}
F_38 ( & V_3 -> V_88 . V_104 ) ;
return 0 ;
V_66:
V_3 -> V_88 . V_102 = V_105 ;
F_38 ( & V_3 -> V_88 . V_104 ) ;
return - V_29 ;
}
static int F_39 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
if ( V_3 -> V_88 . V_102 != V_103 )
return 0 ;
F_40 ( V_3 ) ;
F_41 ( V_5 , V_87 ) ;
if ( V_5 -> V_62 )
F_14 ( & V_5 -> V_60 , & V_5 -> V_61 , & V_5 -> V_62 ) ;
if ( V_5 -> V_82 )
F_14 ( & V_5 -> V_97 ,
& V_5 -> V_86 , & V_5 -> V_82 ) ;
if ( V_5 -> V_99 )
F_14 ( & V_5 -> V_99 ,
& V_5 -> V_65 , & V_5 -> V_51 ) ;
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
if ( V_3 -> V_88 . V_102 != V_103 )
return 0 ;
F_44 ( L_3 ) ;
F_36 ( & V_3 -> V_88 . V_104 ) ;
V_6 = F_25 ( V_5 ) ;
if ( V_6 )
goto V_66;
V_6 = F_29 ( V_5 ) ;
if ( V_6 )
goto V_66;
F_38 ( & V_3 -> V_88 . V_104 ) ;
return 0 ;
V_66:
F_5 ( L_4 ) ;
F_38 ( & V_3 -> V_88 . V_104 ) ;
return V_6 ;
}
static bool F_45 ( struct V_2 * V_3 ,
enum V_106 V_107 )
{
struct V_38 * V_39 = NULL ;
if ( V_3 -> V_88 . V_102 != V_103 ) {
F_44 ( L_5 ) ;
return true ;
}
if ( ! V_3 -> V_88 . V_108 )
return false ;
V_39 = & V_3 -> V_88 . V_39 [ V_107 ] ;
if ( ! V_39 -> V_90 || ! V_39 -> V_109 )
return false ;
return F_46 ( & V_3 -> V_5 , V_39 , V_107 ) ;
}
static int F_47 ( void * V_1 ,
enum V_110 V_111 )
{
return 0 ;
}
static int F_48 ( void * V_1 ,
enum V_112 V_111 )
{
return 0 ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( NULL == V_3 -> V_88 . V_113 )
V_3 -> V_88 . V_113 = & V_114 ;
}
