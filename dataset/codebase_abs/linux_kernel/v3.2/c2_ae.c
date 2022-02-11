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
} ;
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
V_38 = F_6 ( V_35 ) ;
if ( ! V_38 )
return;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_46 = F_7 ( V_38 ) ;
V_44 = F_8 ( V_38 -> V_49 . V_50 . V_51 ) ;
V_39 =
( void * ) ( unsigned long ) V_38 -> V_49 . V_50 . V_52 ;
V_48 = V_41 . V_48 = F_1 ( F_9 ( V_38 ) ) ;
F_10 ( L_55
L_56 ,
V_32 , V_46 , V_44 , V_39 ,
V_48 ) ;
switch ( V_44 ) {
case V_53 : {
struct V_54 * V_55 = (struct V_54 * ) V_39 ;
struct V_56 * V_57 = V_55 -> V_57 ;
struct V_58 * V_59 ;
if ( ! V_57 ) {
F_10 ( L_57 ,
V_55 ) ;
goto V_60;
}
F_10 ( L_58
L_59
L_60 ,
V_61 ,
F_3 ( V_46 ) ,
( unsigned long long ) V_38 -> V_49 . V_50 . V_52 ,
F_8 ( V_38 -> V_49 . V_50 . V_51 ) ,
F_8 ( V_38 -> V_49 . V_50 . V_62 ) ,
F_4 ( F_8 ( V_38 -> V_49 . V_50 . V_63 ) ) ) ;
F_11 ( V_55 , F_8 ( V_38 -> V_49 . V_50 . V_63 ) ) ;
switch ( V_46 ) {
case V_64 :
V_59 = & V_38 -> V_49 . V_65 ;
V_41 . V_20 = V_66 ;
V_41 . V_67 . V_68 . V_69 = V_59 -> V_70 ;
V_41 . V_71 . V_68 . V_69 = V_59 -> V_72 ;
V_41 . V_67 . V_73 = V_59 -> V_74 ;
V_41 . V_71 . V_73 = V_59 -> V_75 ;
if ( V_48 == 0 ) {
V_41 . V_76 =
F_8 ( V_59 -> V_77 ) ;
V_41 . V_78 = V_59 -> V_78 ;
} else {
F_12 ( & V_55 -> V_79 , V_47 ) ;
if ( V_55 -> V_57 ) {
V_55 -> V_57 -> V_80 ( V_55 -> V_57 ) ;
V_55 -> V_57 = NULL ;
}
F_13 ( & V_55 -> V_79 , V_47 ) ;
V_41 . V_76 = 0 ;
V_41 . V_78 = NULL ;
}
if ( V_57 -> V_81 )
V_57 -> V_81 ( V_57 , & V_41 ) ;
break;
case V_82 :
case V_83 :
V_42 . V_84 = & V_32 -> V_85 ;
V_42 . V_86 . V_55 = & V_55 -> V_87 ;
V_42 . V_20 = V_88 ;
if ( V_55 -> V_87 . V_81 )
V_55 -> V_87 . V_81 ( & V_42 ,
V_55 -> V_87 .
V_89 ) ;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
F_14 ( V_57 -> V_81 == ( void * ) 0x6b6b6b6b ) ;
F_12 ( & V_55 -> V_79 , V_47 ) ;
if ( V_55 -> V_57 ) {
V_55 -> V_57 -> V_80 ( V_55 -> V_57 ) ;
V_55 -> V_57 = NULL ;
}
F_13 ( & V_55 -> V_79 , V_47 ) ;
V_41 . V_20 = V_94 ;
V_41 . V_48 = 0 ;
if ( V_57 -> V_81 )
V_57 -> V_81 ( V_57 , & V_41 ) ;
break;
default:
F_14 ( 1 ) ;
F_10 ( L_61
L_62 ,
V_61 , __LINE__ ,
V_46 , V_55 , V_57 ) ;
break;
}
break;
}
case V_95 : {
struct V_96 * V_97 =
& V_38 -> V_49 . V_98 ;
struct V_56 * V_57 =
(struct V_56 * ) V_39 ;
F_10 ( L_63 , V_46 ) ;
if ( V_46 != V_99 ) {
F_10 ( L_64 ,
V_61 , V_46 ) ;
break;
}
V_41 . V_20 = V_100 ;
V_41 . V_101 = ( void * ) ( unsigned long ) V_97 -> V_102 ;
V_41 . V_67 . V_68 . V_69 = V_97 -> V_70 ;
V_41 . V_71 . V_68 . V_69 = V_97 -> V_72 ;
V_41 . V_67 . V_73 = V_97 -> V_74 ;
V_41 . V_71 . V_73 = V_97 -> V_75 ;
V_41 . V_76 =
F_8 ( V_97 -> V_77 ) ;
V_41 . V_78 = V_97 -> V_78 ;
V_41 . V_103 = V_41 . V_104 = 128 ;
if ( V_57 -> V_81 )
V_57 -> V_81 ( V_57 , & V_41 ) ;
break;
}
case V_105 : {
struct V_106 * V_107 =
(struct V_106 * ) V_39 ;
F_10 ( L_65 ) ;
V_42 . V_84 = & V_32 -> V_85 ;
V_42 . V_86 . V_107 = & V_107 -> V_108 ;
V_42 . V_20 = V_109 ;
if ( V_107 -> V_108 . V_81 )
V_107 -> V_108 . V_81 ( & V_42 ,
V_107 -> V_108 . V_110 ) ;
}
default:
F_2 ( L_66 ,
V_44 ) ;
break;
}
V_60:
F_15 ( V_35 ) ;
}
