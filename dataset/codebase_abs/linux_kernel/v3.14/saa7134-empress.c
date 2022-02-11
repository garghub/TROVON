static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_2 ( V_4 , 0x00 ) ;
F_3 ( 10 ) ;
F_2 ( V_4 , 0x01 ) ;
F_3 ( 100 ) ;
V_2 -> V_3 = 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
V_5 = 1 ;
break;
}
F_1 ( V_2 ) ;
F_5 ( V_2 , V_10 , V_11 , V_5 ) ;
V_2 -> V_3 = 1 ;
return 0 ;
}
static int F_6 ( struct V_12 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_15 * V_16 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_17 ) ;
if ( NULL == V_16 )
return - V_18 ;
F_10 ( & V_16 -> V_16 , V_14 ) ;
V_12 -> V_19 = V_16 ;
V_16 -> V_20 = true ;
F_11 ( & V_16 -> V_16 ) ;
F_2 ( V_21 ,
F_12 ( V_21 ) & ~ ( 1 << 6 ) ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_12 -> V_19 ;
if ( F_14 ( V_16 , V_22 ) ) {
F_15 ( & V_2 -> V_23 ) ;
F_16 ( & V_2 -> V_23 ) ;
F_1 ( V_2 ) ;
F_2 ( V_21 ,
F_12 ( V_21 ) | ( 1 << 6 ) ) ;
}
F_17 ( & V_16 -> V_16 ) ;
F_18 ( & V_16 -> V_16 ) ;
return 0 ;
}
static T_2
F_19 ( struct V_12 * V_12 , char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
if ( F_20 ( V_2 , V_22 ) )
return - V_27 ;
if ( ! V_2 -> V_3 )
F_4 ( V_2 ) ;
return F_21 ( & V_2 -> V_23 ,
V_24 , V_25 , V_26 , 0 ,
V_12 -> V_28 & V_29 ) ;
}
static unsigned int
F_22 ( struct V_12 * V_12 , struct V_30 * V_31 )
{
unsigned long V_32 = F_23 ( V_31 ) ;
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_12 -> V_19 ;
unsigned int V_33 = 0 ;
if ( F_24 ( & V_16 -> V_16 ) )
V_33 = V_34 ;
else if ( V_32 & V_34 )
F_25 ( V_12 , & V_16 -> V_16 . V_31 , V_31 ) ;
return V_33 | F_26 ( V_12 , & V_2 -> V_23 , V_31 ) ;
}
static int
F_27 ( struct V_12 * V_12 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
return F_28 ( & V_2 -> V_23 , V_36 ) ;
}
static int F_29 ( struct V_12 * V_12 , void * V_37 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_40 != 0 )
return - V_41 ;
F_30 ( V_39 -> V_42 , L_1 , sizeof( V_39 -> V_42 ) ) ;
V_39 -> V_43 = V_44 ;
V_39 -> V_45 = V_46 ;
return 0 ;
}
static int F_31 ( struct V_12 * V_12 , void * V_37 ,
struct V_47 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_48 V_49 ;
F_5 ( V_2 , V_50 , V_51 , & V_49 ) ;
F_32 ( & V_39 -> V_52 . V_53 , & V_49 ) ;
V_39 -> V_52 . V_53 . V_43 = V_44 ;
V_39 -> V_52 . V_53 . V_54 = V_55 * V_2 -> V_56 . V_57 ;
V_39 -> V_52 . V_53 . V_58 = 0 ;
V_39 -> V_52 . V_53 . V_37 = 0 ;
return 0 ;
}
static int F_33 ( struct V_12 * V_12 , void * V_37 ,
struct V_47 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_48 V_49 ;
F_34 ( & V_49 , & V_39 -> V_52 . V_53 , V_59 ) ;
F_5 ( V_2 , V_50 , V_60 , & V_49 ) ;
F_32 ( & V_39 -> V_52 . V_53 , & V_49 ) ;
V_39 -> V_52 . V_53 . V_43 = V_44 ;
V_39 -> V_52 . V_53 . V_54 = V_55 * V_2 -> V_56 . V_57 ;
V_39 -> V_52 . V_53 . V_58 = 0 ;
V_39 -> V_52 . V_53 . V_37 = 0 ;
return 0 ;
}
static int F_35 ( struct V_12 * V_12 , void * V_37 ,
struct V_47 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_48 V_49 ;
F_34 ( & V_49 , & V_39 -> V_52 . V_53 , V_59 ) ;
F_5 ( V_2 , V_50 , V_61 , & V_49 ) ;
F_32 ( & V_39 -> V_52 . V_53 , & V_49 ) ;
V_39 -> V_52 . V_53 . V_43 = V_44 ;
V_39 -> V_52 . V_53 . V_54 = V_55 * V_2 -> V_56 . V_57 ;
V_39 -> V_52 . V_53 . V_58 = 0 ;
V_39 -> V_52 . V_53 . V_37 = 0 ;
return 0 ;
}
static void F_36 ( struct V_62 * V_63 )
{
struct V_1 * V_2 =
F_37 ( V_63 , struct V_1 , V_64 ) ;
if ( V_2 -> V_65 ) {
F_38 ( L_2 ) ;
} else {
F_38 ( L_3 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_64 ) ;
}
static bool F_41 ( const struct V_66 * V_67 )
{
switch ( V_67 -> V_68 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
return true ;
default:
return false ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_79 ;
int V_80 ;
F_38 ( L_4 , V_2 -> V_81 , V_82 ) ;
V_2 -> V_83 = F_43 () ;
if ( NULL == V_2 -> V_83 )
return - V_18 ;
* ( V_2 -> V_83 ) = V_84 ;
V_2 -> V_83 -> V_85 = & V_2 -> V_85 ;
V_2 -> V_83 -> V_86 = V_87 ;
snprintf ( V_2 -> V_83 -> V_81 , sizeof( V_2 -> V_83 -> V_81 ) ,
L_5 , V_2 -> V_81 ,
V_88 [ V_2 -> V_6 ] . V_81 ) ;
F_44 ( V_89 , & V_2 -> V_83 -> V_45 ) ;
F_45 ( V_78 , 21 ) ;
F_46 ( V_78 , & V_2 -> V_90 , F_41 ) ;
if ( V_2 -> V_91 )
F_46 ( V_78 , V_2 -> V_91 -> V_90 , NULL ) ;
if ( V_78 -> error ) {
V_87 ( V_2 -> V_83 ) ;
return V_78 -> error ;
}
V_2 -> V_83 -> V_90 = V_78 ;
F_47 ( & V_2 -> V_64 , F_36 ) ;
F_48 ( V_2 -> V_83 , V_2 ) ;
V_80 = F_49 ( V_2 -> V_83 , V_92 ,
V_93 [ V_2 -> V_94 ] ) ;
if ( V_80 < 0 ) {
F_50 ( V_95 L_6 ,
V_2 -> V_81 ) ;
V_87 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
return V_80 ;
}
F_50 ( V_95 L_7 ,
V_2 -> V_81 , F_51 ( V_2 -> V_83 ) ) ;
F_52 ( & V_2 -> V_23 , & V_96 ,
& V_2 -> V_97 -> V_2 , & V_2 -> V_98 ,
V_99 ,
V_100 ,
sizeof( struct V_101 ) ,
V_2 , NULL ) ;
F_36 ( & V_2 -> V_64 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
F_38 ( L_4 , V_2 -> V_81 , V_82 ) ;
if ( NULL == V_2 -> V_83 )
return 0 ;
F_54 ( & V_2 -> V_64 ) ;
F_55 ( V_2 -> V_83 ) ;
F_56 ( & V_2 -> V_79 ) ;
V_2 -> V_83 = NULL ;
return 0 ;
}
static int T_6 F_57 ( void )
{
return F_58 ( & V_102 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_102 ) ;
}
