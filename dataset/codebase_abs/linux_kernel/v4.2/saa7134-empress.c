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
struct V_32 V_33 = {
. V_34 = V_35 ,
} ;
struct V_36 * V_37 = & V_33 . V_38 ;
F_3 ( V_8 , V_39 , V_40 , NULL , & V_33 ) ;
F_13 ( & V_23 -> V_33 . V_41 , V_37 ) ;
V_23 -> V_33 . V_41 . V_27 = V_28 ;
V_23 -> V_33 . V_41 . V_42 = V_43 * V_8 -> V_44 . V_45 ;
V_23 -> V_33 . V_41 . V_46 = 0 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_20 , void * V_21 ,
struct V_31 * V_23 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_32 V_38 = {
. V_34 = V_35 ,
} ;
F_15 ( & V_38 . V_38 , & V_23 -> V_33 . V_41 , V_47 ) ;
F_3 ( V_8 , V_39 , V_48 , NULL , & V_38 ) ;
F_13 ( & V_23 -> V_33 . V_41 , & V_38 . V_38 ) ;
V_23 -> V_33 . V_41 . V_27 = V_28 ;
V_23 -> V_33 . V_41 . V_42 = V_43 * V_8 -> V_44 . V_45 ;
V_23 -> V_33 . V_41 . V_46 = 0 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_20 , void * V_21 ,
struct V_31 * V_23 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_49 V_50 ;
struct V_32 V_38 = {
. V_34 = V_51 ,
} ;
F_15 ( & V_38 . V_38 , & V_23 -> V_33 . V_41 , V_47 ) ;
F_3 ( V_8 , V_39 , V_48 , & V_50 , & V_38 ) ;
F_13 ( & V_23 -> V_33 . V_41 , & V_38 . V_38 ) ;
V_23 -> V_33 . V_41 . V_27 = V_28 ;
V_23 -> V_33 . V_41 . V_42 = V_43 * V_8 -> V_44 . V_45 ;
V_23 -> V_33 . V_41 . V_46 = 0 ;
return 0 ;
}
static void F_17 ( struct V_52 * V_53 )
{
struct V_7 * V_8 =
F_18 ( V_53 , struct V_7 , V_54 ) ;
if ( V_8 -> V_55 ) {
F_19 ( L_2 ) ;
} else {
F_19 ( L_3 ) ;
}
}
static void F_20 ( struct V_7 * V_8 )
{
F_21 ( & V_8 -> V_54 ) ;
}
static bool F_22 ( const struct V_56 * V_57 )
{
switch ( V_57 -> V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
return true ;
default:
return false ;
}
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_67 * V_68 = & V_8 -> V_69 ;
struct V_1 * V_70 ;
int V_10 ;
F_19 ( L_4 , V_8 -> V_71 , V_72 ) ;
V_8 -> V_73 = F_24 () ;
if ( NULL == V_8 -> V_73 )
return - V_74 ;
* ( V_8 -> V_73 ) = V_75 ;
V_8 -> V_73 -> V_76 = & V_8 -> V_76 ;
V_8 -> V_73 -> V_77 = V_78 ;
V_8 -> V_73 -> V_79 = & V_8 -> V_79 ;
snprintf ( V_8 -> V_73 -> V_71 , sizeof( V_8 -> V_73 -> V_71 ) ,
L_5 , V_8 -> V_71 ,
V_80 [ V_8 -> V_11 ] . V_71 ) ;
F_25 ( V_68 , 21 ) ;
F_26 ( V_68 , & V_8 -> V_81 , F_22 ) ;
if ( V_8 -> V_82 )
F_26 ( V_68 , V_8 -> V_82 -> V_81 , NULL ) ;
if ( V_68 -> error ) {
V_78 ( V_8 -> V_73 ) ;
return V_68 -> error ;
}
V_8 -> V_73 -> V_81 = V_68 ;
F_27 ( & V_8 -> V_54 , F_17 ) ;
V_70 = & V_8 -> V_83 ;
V_70 -> type = V_84 ;
V_70 -> V_85 = V_86 | V_87 ;
V_70 -> V_6 = & V_8 -> V_88 ;
V_70 -> V_89 = & V_90 ;
V_70 -> V_91 = V_92 ;
V_70 -> V_93 = & V_94 ;
V_70 -> V_95 = sizeof( struct V_96 ) ;
V_70 -> V_97 = V_98 ;
V_70 -> V_79 = & V_8 -> V_79 ;
V_10 = F_28 ( V_70 ) ;
if ( V_10 )
return V_10 ;
V_8 -> V_73 -> V_99 = V_70 ;
F_29 ( V_8 -> V_73 , V_8 ) ;
V_10 = F_30 ( V_8 -> V_73 , V_100 ,
V_101 [ V_8 -> V_102 ] ) ;
if ( V_10 < 0 ) {
F_31 ( L_6 ,
V_8 -> V_71 ) ;
V_78 ( V_8 -> V_73 ) ;
V_8 -> V_73 = NULL ;
return V_10 ;
}
F_31 ( L_7 ,
V_8 -> V_71 , F_32 ( V_8 -> V_73 ) ) ;
F_17 ( & V_8 -> V_54 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 )
{
F_19 ( L_4 , V_8 -> V_71 , V_72 ) ;
if ( NULL == V_8 -> V_73 )
return 0 ;
F_34 ( & V_8 -> V_54 ) ;
F_35 ( V_8 -> V_73 ) ;
F_36 ( & V_8 -> V_83 ) ;
F_37 ( & V_8 -> V_69 ) ;
V_8 -> V_73 = NULL ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_103 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_103 ) ;
}
