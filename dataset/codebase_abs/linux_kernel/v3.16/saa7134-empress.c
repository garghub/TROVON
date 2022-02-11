static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 = 0 ;
int V_10 ;
V_10 = F_2 ( V_2 , V_3 ) ;
if ( V_10 )
return V_10 ;
switch ( V_8 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
V_9 = 1 ;
break;
}
F_3 ( V_8 , V_15 , V_16 , V_9 ) ;
F_4 ( V_17 ,
F_5 ( V_17 ) & ~ ( 1 << 6 ) ) ;
V_8 -> V_18 = 1 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_7 ( V_2 ) ;
F_4 ( V_19 , 0x00 ) ;
F_8 ( 20 ) ;
F_4 ( V_19 , 0x01 ) ;
F_8 ( 100 ) ;
F_4 ( V_17 ,
F_5 ( V_17 ) | ( 1 << 6 ) ) ;
V_8 -> V_18 = 0 ;
}
static int F_9 ( struct V_20 * V_20 , void * V_21 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_24 != 0 )
return - V_25 ;
F_10 ( V_23 -> V_26 , L_1 , sizeof( V_23 -> V_26 ) ) ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = V_30 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_20 , void * V_21 ,
struct V_31 * V_23 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_32 V_33 ;
F_3 ( V_8 , V_34 , V_35 , & V_33 ) ;
F_13 ( & V_23 -> V_36 . V_37 , & V_33 ) ;
V_23 -> V_36 . V_37 . V_27 = V_28 ;
V_23 -> V_36 . V_37 . V_38 = V_39 * V_8 -> V_40 . V_41 ;
V_23 -> V_36 . V_37 . V_42 = 0 ;
V_23 -> V_36 . V_37 . V_21 = 0 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_20 , void * V_21 ,
struct V_31 * V_23 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_32 V_33 ;
F_15 ( & V_33 , & V_23 -> V_36 . V_37 , V_43 ) ;
F_3 ( V_8 , V_34 , V_44 , & V_33 ) ;
F_13 ( & V_23 -> V_36 . V_37 , & V_33 ) ;
V_23 -> V_36 . V_37 . V_27 = V_28 ;
V_23 -> V_36 . V_37 . V_38 = V_39 * V_8 -> V_40 . V_41 ;
V_23 -> V_36 . V_37 . V_42 = 0 ;
V_23 -> V_36 . V_37 . V_21 = 0 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_20 , void * V_21 ,
struct V_31 * V_23 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_32 V_33 ;
F_15 ( & V_33 , & V_23 -> V_36 . V_37 , V_43 ) ;
F_3 ( V_8 , V_34 , V_45 , & V_33 ) ;
F_13 ( & V_23 -> V_36 . V_37 , & V_33 ) ;
V_23 -> V_36 . V_37 . V_27 = V_28 ;
V_23 -> V_36 . V_37 . V_38 = V_39 * V_8 -> V_40 . V_41 ;
V_23 -> V_36 . V_37 . V_42 = 0 ;
V_23 -> V_36 . V_37 . V_21 = 0 ;
return 0 ;
}
static void F_17 ( struct V_46 * V_47 )
{
struct V_7 * V_8 =
F_18 ( V_47 , struct V_7 , V_48 ) ;
if ( V_8 -> V_49 ) {
F_19 ( L_2 ) ;
} else {
F_19 ( L_3 ) ;
}
}
static void F_20 ( struct V_7 * V_8 )
{
F_21 ( & V_8 -> V_48 ) ;
}
static bool F_22 ( const struct V_50 * V_51 )
{
switch ( V_51 -> V_52 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
return true ;
default:
return false ;
}
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_61 * V_62 = & V_8 -> V_63 ;
struct V_1 * V_64 ;
int V_10 ;
F_19 ( L_4 , V_8 -> V_65 , V_66 ) ;
V_8 -> V_67 = F_24 () ;
if ( NULL == V_8 -> V_67 )
return - V_68 ;
* ( V_8 -> V_67 ) = V_69 ;
V_8 -> V_67 -> V_70 = & V_8 -> V_70 ;
V_8 -> V_67 -> V_71 = V_72 ;
V_8 -> V_67 -> V_73 = & V_8 -> V_73 ;
snprintf ( V_8 -> V_67 -> V_65 , sizeof( V_8 -> V_67 -> V_65 ) ,
L_5 , V_8 -> V_65 ,
V_74 [ V_8 -> V_11 ] . V_65 ) ;
F_25 ( V_75 , & V_8 -> V_67 -> V_29 ) ;
F_26 ( V_62 , 21 ) ;
F_27 ( V_62 , & V_8 -> V_76 , F_22 ) ;
if ( V_8 -> V_77 )
F_27 ( V_62 , V_8 -> V_77 -> V_76 , NULL ) ;
if ( V_62 -> error ) {
V_72 ( V_8 -> V_67 ) ;
return V_62 -> error ;
}
V_8 -> V_67 -> V_76 = V_62 ;
F_28 ( & V_8 -> V_48 , F_17 ) ;
V_64 = & V_8 -> V_78 ;
V_64 -> type = V_79 ;
V_64 -> V_80 = V_81 | V_82 ;
V_64 -> V_6 = & V_8 -> V_83 ;
V_64 -> V_84 = & V_85 ;
V_64 -> V_86 = V_87 ;
V_64 -> V_88 = & V_89 ;
V_64 -> V_90 = sizeof( struct V_91 ) ;
V_64 -> V_92 = V_93 ;
V_64 -> V_73 = & V_8 -> V_73 ;
V_10 = F_29 ( V_64 ) ;
if ( V_10 )
return V_10 ;
V_8 -> V_67 -> V_94 = V_64 ;
F_30 ( V_8 -> V_67 , V_8 ) ;
V_10 = F_31 ( V_8 -> V_67 , V_95 ,
V_96 [ V_8 -> V_97 ] ) ;
if ( V_10 < 0 ) {
F_32 ( V_98 L_6 ,
V_8 -> V_65 ) ;
V_72 ( V_8 -> V_67 ) ;
V_8 -> V_67 = NULL ;
return V_10 ;
}
F_32 ( V_98 L_7 ,
V_8 -> V_65 , F_33 ( V_8 -> V_67 ) ) ;
F_17 ( & V_8 -> V_48 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 )
{
F_19 ( L_4 , V_8 -> V_65 , V_66 ) ;
if ( NULL == V_8 -> V_67 )
return 0 ;
F_35 ( & V_8 -> V_48 ) ;
F_36 ( V_8 -> V_67 ) ;
F_37 ( & V_8 -> V_78 ) ;
F_38 ( & V_8 -> V_63 ) ;
V_8 -> V_67 = NULL ;
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_99 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_99 ) ;
}
