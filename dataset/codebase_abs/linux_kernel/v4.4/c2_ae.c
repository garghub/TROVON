static int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
case V_7 :
return - V_8 ;
case V_9 :
return - V_10 ;
case V_11 :
return - V_12 ;
case V_13 :
return - V_14 ;
case V_15 :
return - V_14 ;
case V_16 :
return - V_14 ;
case V_17 :
return - V_18 ;
default:
F_2 (KERN_ERR PFX
L_1 ,
__func__, c2_status) ;
return - V_19 ;
}
}
static const char * F_3 ( int V_20 )
{
static const char * V_21 [] = {
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46
} ;
if ( V_20 < V_22 ||
V_20 > V_23 )
return L_47 ;
V_20 -= V_22 ;
return V_21 [ V_20 ] ;
}
static const char * F_4 ( int V_24 )
{
switch ( V_24 ) {
case V_25 :
return L_48 ;
case V_26 :
return L_49 ;
case V_27 :
return L_50 ;
case V_28 :
return L_51 ;
case V_29 :
return L_52 ;
case V_30 :
return L_53 ;
default:
return L_54 ;
}
}
void F_5 ( struct V_31 * V_32 , T_1 V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 [ V_33 ] ;
union V_37 * V_38 ;
void * V_39 ;
struct V_40 V_41 ;
struct V_42 V_42 ;
enum V_43 V_44 ;
enum V_45 V_46 ;
unsigned long V_47 ;
int V_48 ;
struct V_49 * V_50 = (struct V_49 * ) & V_41 . V_51 ;
struct V_49 * V_52 = (struct V_49 * ) & V_41 . V_53 ;
V_38 = F_6 ( V_35 ) ;
if ( ! V_38 )
return;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_46 = F_7 ( V_38 ) ;
V_44 = F_8 ( V_38 -> V_54 . V_55 . V_56 ) ;
V_39 =
( void * ) ( unsigned long ) V_38 -> V_54 . V_55 . V_57 ;
V_48 = V_41 . V_48 = F_1 ( F_9 ( V_38 ) ) ;
F_10 ( L_55
L_56 ,
V_32 , V_46 , V_44 , V_39 ,
V_48 ) ;
switch ( V_44 ) {
case V_58 : {
struct V_59 * V_60 = V_39 ;
struct V_61 * V_62 = V_60 -> V_62 ;
struct V_63 * V_64 ;
if ( ! V_62 ) {
F_10 ( L_57 ,
V_60 ) ;
goto V_65;
}
F_10 ( L_58
L_59
L_60 ,
V_66 ,
F_3 ( V_46 ) ,
( unsigned long long ) V_38 -> V_54 . V_55 . V_57 ,
F_8 ( V_38 -> V_54 . V_55 . V_56 ) ,
F_8 ( V_38 -> V_54 . V_55 . V_67 ) ,
F_4 ( F_8 ( V_38 -> V_54 . V_55 . V_68 ) ) ) ;
F_11 ( V_60 , F_8 ( V_38 -> V_54 . V_55 . V_68 ) ) ;
switch ( V_46 ) {
case V_69 :
V_64 = & V_38 -> V_54 . V_70 ;
V_41 . V_20 = V_71 ;
V_50 -> V_72 . V_73 = V_64 -> V_50 ;
V_52 -> V_72 . V_73 = V_64 -> V_52 ;
V_50 -> V_74 = V_64 -> V_75 ;
V_52 -> V_74 = V_64 -> V_76 ;
if ( V_48 == 0 ) {
V_41 . V_77 =
F_8 ( V_64 -> V_78 ) ;
V_41 . V_79 = V_64 -> V_79 ;
} else {
F_12 ( & V_60 -> V_80 , V_47 ) ;
if ( V_60 -> V_62 ) {
V_60 -> V_62 -> V_81 ( V_60 -> V_62 ) ;
V_60 -> V_62 = NULL ;
}
F_13 ( & V_60 -> V_80 , V_47 ) ;
V_41 . V_77 = 0 ;
V_41 . V_79 = NULL ;
}
if ( V_62 -> V_82 )
V_62 -> V_82 ( V_62 , & V_41 ) ;
break;
case V_83 :
case V_84 :
V_42 . V_85 = & V_32 -> V_86 ;
V_42 . V_87 . V_60 = & V_60 -> V_88 ;
V_42 . V_20 = V_89 ;
if ( V_60 -> V_88 . V_82 )
V_60 -> V_88 . V_82 ( & V_42 ,
V_60 -> V_88 .
V_90 ) ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
F_14 ( V_62 -> V_82 == ( void * ) 0x6b6b6b6b ) ;
F_12 ( & V_60 -> V_80 , V_47 ) ;
if ( V_60 -> V_62 ) {
V_60 -> V_62 -> V_81 ( V_60 -> V_62 ) ;
V_60 -> V_62 = NULL ;
}
F_13 ( & V_60 -> V_80 , V_47 ) ;
V_41 . V_20 = V_95 ;
V_41 . V_48 = 0 ;
if ( V_62 -> V_82 )
V_62 -> V_82 ( V_62 , & V_41 ) ;
break;
default:
F_14 ( 1 ) ;
F_10 ( L_61
L_62 ,
V_66 , __LINE__ ,
V_46 , V_60 , V_62 ) ;
break;
}
break;
}
case V_96 : {
struct V_97 * V_98 =
& V_38 -> V_54 . V_99 ;
struct V_61 * V_62 =
V_39 ;
F_10 ( L_63 , V_46 ) ;
if ( V_46 != V_100 ) {
F_10 ( L_64 ,
V_66 , V_46 ) ;
break;
}
V_41 . V_20 = V_101 ;
V_41 . V_102 = ( void * ) ( unsigned long ) V_98 -> V_103 ;
V_50 -> V_72 . V_73 = V_98 -> V_50 ;
V_52 -> V_72 . V_73 = V_98 -> V_52 ;
V_50 -> V_74 = V_98 -> V_75 ;
V_52 -> V_74 = V_98 -> V_76 ;
V_41 . V_77 =
F_8 ( V_98 -> V_78 ) ;
V_41 . V_79 = V_98 -> V_79 ;
V_41 . V_104 = V_41 . V_105 = 128 ;
if ( V_62 -> V_82 )
V_62 -> V_82 ( V_62 , & V_41 ) ;
break;
}
case V_106 : {
struct V_107 * V_108 =
V_39 ;
F_10 ( L_65 ) ;
V_42 . V_85 = & V_32 -> V_86 ;
V_42 . V_87 . V_108 = & V_108 -> V_109 ;
V_42 . V_20 = V_110 ;
if ( V_108 -> V_109 . V_82 )
V_108 -> V_109 . V_82 ( & V_42 ,
V_108 -> V_109 . V_111 ) ;
break;
}
default:
F_2 ( L_66 ,
V_44 ) ;
break;
}
V_65:
F_15 ( V_35 ) ;
}
