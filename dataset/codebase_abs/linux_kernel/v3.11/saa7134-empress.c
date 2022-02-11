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
int V_15 ;
F_9 ( L_1 , F_10 ( V_14 ) ) ;
V_15 = - V_16 ;
if ( ! F_11 ( & V_2 -> V_17 . V_18 ) )
return V_15 ;
if ( F_12 ( & V_2 -> V_19 ) )
goto V_20;
F_2 ( V_21 ,
F_13 ( V_21 ) & ~ ( 1 << 6 ) ) ;
F_14 ( & V_2 -> V_19 ) ;
V_12 -> V_22 = V_2 ;
V_15 = 0 ;
V_20:
F_15 ( & V_2 -> V_17 . V_18 ) ;
return V_15 ;
}
static int F_16 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
F_17 ( & V_2 -> V_17 ) ;
F_18 ( & V_2 -> V_17 ) ;
F_1 ( V_2 ) ;
F_2 ( V_21 ,
F_13 ( V_21 ) | ( 1 << 6 ) ) ;
F_19 ( & V_2 -> V_19 ) ;
return 0 ;
}
static T_2
F_20 ( struct V_12 * V_12 , char T_3 * V_23 , T_4 V_24 , T_5 * V_25 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
if ( ! V_2 -> V_3 )
F_4 ( V_2 ) ;
return F_21 ( & V_2 -> V_17 ,
V_23 , V_24 , V_25 , 0 ,
V_12 -> V_26 & V_27 ) ;
}
static unsigned int
F_22 ( struct V_12 * V_12 , struct V_28 * V_29 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_23 ( V_12 , & V_2 -> V_17 , V_29 ) ;
}
static int
F_24 ( struct V_12 * V_12 , struct V_30 * V_31 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_25 ( & V_2 -> V_17 , V_31 ) ;
}
static int F_26 ( struct V_12 * V_12 , void * V_32 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
strcpy ( V_34 -> V_35 , L_2 ) ;
F_27 ( V_34 -> V_36 , V_37 [ V_2 -> V_6 ] . V_38 ,
sizeof( V_34 -> V_36 ) ) ;
sprintf ( V_34 -> V_39 , L_3 , F_28 ( V_2 -> V_40 ) ) ;
V_34 -> V_41 =
V_42 |
V_43 |
V_44 ;
return 0 ;
}
static int F_29 ( struct V_12 * V_12 , void * V_32 ,
struct V_45 * V_46 )
{
if ( V_46 -> V_47 != 0 )
return - V_48 ;
V_46 -> type = V_49 ;
strcpy ( V_46 -> V_38 , L_4 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_12 , void * V_32 , unsigned int * V_46 )
{
* V_46 = 0 ;
return 0 ;
}
static int F_31 ( struct V_12 * V_12 , void * V_32 , unsigned int V_46 )
{
if ( V_46 != 0 )
return - V_48 ;
return 0 ;
}
static int F_32 ( struct V_12 * V_12 , void * V_32 ,
struct V_50 * V_51 )
{
if ( V_51 -> V_47 != 0 )
return - V_48 ;
F_27 ( V_51 -> V_52 , L_5 , sizeof( V_51 -> V_52 ) ) ;
V_51 -> V_53 = V_54 ;
V_51 -> V_55 = V_56 ;
return 0 ;
}
static int F_33 ( struct V_12 * V_12 , void * V_32 ,
struct V_57 * V_51 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
struct V_58 V_59 ;
F_5 ( V_2 , V_60 , V_61 , & V_59 ) ;
F_34 ( & V_51 -> V_62 . V_63 , & V_59 ) ;
V_51 -> V_62 . V_63 . V_53 = V_54 ;
V_51 -> V_62 . V_63 . V_64 = V_65 * V_2 -> V_66 . V_67 ;
V_51 -> V_62 . V_63 . V_68 = 0 ;
V_51 -> V_62 . V_63 . V_32 = 0 ;
return 0 ;
}
static int F_35 ( struct V_12 * V_12 , void * V_32 ,
struct V_57 * V_51 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
struct V_58 V_59 ;
F_36 ( & V_59 , & V_51 -> V_62 . V_63 , V_69 ) ;
F_5 ( V_2 , V_60 , V_70 , & V_59 ) ;
F_34 ( & V_51 -> V_62 . V_63 , & V_59 ) ;
V_51 -> V_62 . V_63 . V_53 = V_54 ;
V_51 -> V_62 . V_63 . V_64 = V_65 * V_2 -> V_66 . V_67 ;
V_51 -> V_62 . V_63 . V_68 = 0 ;
V_51 -> V_62 . V_63 . V_32 = 0 ;
return 0 ;
}
static int F_37 ( struct V_12 * V_12 , void * V_32 ,
struct V_57 * V_51 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
struct V_58 V_59 ;
F_36 ( & V_59 , & V_51 -> V_62 . V_63 , V_69 ) ;
F_5 ( V_2 , V_60 , V_71 , & V_59 ) ;
F_34 ( & V_51 -> V_62 . V_63 , & V_59 ) ;
V_51 -> V_62 . V_63 . V_53 = V_54 ;
V_51 -> V_62 . V_63 . V_64 = V_65 * V_2 -> V_66 . V_67 ;
V_51 -> V_62 . V_63 . V_68 = 0 ;
V_51 -> V_62 . V_63 . V_32 = 0 ;
return 0 ;
}
static int F_38 ( struct V_12 * V_12 , void * V_32 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_39 ( & V_2 -> V_17 , V_73 ) ;
}
static int F_40 ( struct V_12 * V_12 , void * V_32 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_41 ( & V_2 -> V_17 , V_75 ) ;
}
static int F_42 ( struct V_12 * V_12 , void * V_32 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_43 ( & V_2 -> V_17 , V_75 ) ;
}
static int F_44 ( struct V_12 * V_12 , void * V_32 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_45 ( & V_2 -> V_17 , V_75 ,
V_12 -> V_26 & V_27 ) ;
}
static int F_46 ( struct V_12 * V_12 , void * V_32 ,
enum V_76 type )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_47 ( & V_2 -> V_17 ) ;
}
static int F_48 ( struct V_12 * V_12 , void * V_32 ,
enum V_76 type )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_49 ( & V_2 -> V_17 ) ;
}
static int F_50 ( struct V_12 * V_12 , void * V_32 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
int V_15 ;
if ( V_78 -> V_24 == 0 )
return 0 ;
if ( V_78 -> V_79 != V_80 )
return - V_48 ;
V_15 = F_51 ( V_2 , V_10 , V_81 , V_78 ) ;
F_4 ( V_2 ) ;
return V_15 ;
}
static int F_52 ( struct V_12 * V_12 , void * V_32 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
if ( V_78 -> V_79 != V_80 )
return - V_48 ;
return F_51 ( V_2 , V_10 , V_82 , V_78 ) ;
}
static int F_53 ( struct V_12 * V_12 , void * V_32 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_54 ( V_2 , NULL , V_84 ) ;
}
static int F_55 ( struct V_12 * V_12 , void * V_32 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_56 ( V_2 , NULL , V_84 ) ;
}
static int F_57 ( struct V_12 * V_12 , void * V_32 ,
struct V_85 * V_84 )
{
static const T_1 V_86 [] = {
V_87 ,
V_88 ,
V_89 ,
V_90 ,
V_91 ,
V_92 ,
V_93 ,
V_94 ,
0
} ;
static const T_1 V_95 [] = {
V_96 ,
V_97 ,
V_98 ,
V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ,
V_107 ,
V_108 ,
V_109 ,
0
} ;
static const T_1 * V_110 [] = {
V_86 ,
V_95 ,
NULL
} ;
struct V_1 * V_2 = V_12 -> V_22 ;
V_84 -> V_111 = F_58 ( V_110 , V_84 -> V_111 ) ;
if ( V_84 -> V_111 == 0 )
return - V_48 ;
if ( V_84 -> V_111 == V_87 || V_84 -> V_111 == V_96 )
return F_59 ( V_84 , 0 , 0 , 0 , 0 ) ;
if ( F_60 ( V_84 -> V_111 ) != V_80 )
return F_61 ( V_12 , V_32 , V_84 ) ;
return F_51 ( V_2 , V_10 , V_112 , V_84 ) ;
}
static int F_62 ( struct V_12 * V_12 , void * V_32 ,
struct V_113 * V_84 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
if ( F_60 ( V_84 -> V_111 ) != V_80 )
return - V_48 ;
return F_51 ( V_2 , V_10 , V_114 , V_84 ) ;
}
static int F_63 ( struct V_12 * V_12 , void * V_32 , T_6 V_111 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
return F_64 ( V_2 , NULL , V_111 ) ;
}
static int F_65 ( struct V_12 * V_12 , void * V_32 , T_6 * V_111 )
{
struct V_1 * V_2 = V_12 -> V_22 ;
* V_111 = V_2 -> V_115 -> V_111 ;
return 0 ;
}
static void F_66 ( struct V_116 * V_117 )
{
struct V_1 * V_2 =
F_67 ( V_117 , struct V_1 , V_118 ) ;
if ( V_2 -> V_119 ) {
F_9 ( L_6 ) ;
} else {
F_9 ( L_7 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( & V_2 -> V_118 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_15 ;
F_9 ( L_8 , V_2 -> V_38 , V_120 ) ;
V_2 -> V_121 = F_71 () ;
if ( NULL == V_2 -> V_121 )
return - V_122 ;
* ( V_2 -> V_121 ) = V_123 ;
V_2 -> V_121 -> V_124 = & V_2 -> V_124 ;
V_2 -> V_121 -> V_125 = V_126 ;
snprintf ( V_2 -> V_121 -> V_38 , sizeof( V_2 -> V_121 -> V_38 ) ,
L_9 , V_2 -> V_38 ,
V_37 [ V_2 -> V_6 ] . V_38 ) ;
F_72 ( & V_2 -> V_118 , F_66 ) ;
F_73 ( V_2 -> V_121 , V_2 ) ;
V_15 = F_74 ( V_2 -> V_121 , V_127 ,
V_128 [ V_2 -> V_129 ] ) ;
if ( V_15 < 0 ) {
F_75 ( V_130 L_10 ,
V_2 -> V_38 ) ;
V_126 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
return V_15 ;
}
F_75 ( V_130 L_11 ,
V_2 -> V_38 , F_10 ( V_2 -> V_121 ) ) ;
F_76 ( & V_2 -> V_17 , & V_131 ,
& V_2 -> V_40 -> V_2 , & V_2 -> V_132 ,
V_133 ,
V_134 ,
sizeof( struct V_135 ) ,
V_2 , NULL ) ;
F_66 ( & V_2 -> V_118 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
F_9 ( L_8 , V_2 -> V_38 , V_120 ) ;
if ( NULL == V_2 -> V_121 )
return 0 ;
F_78 ( & V_2 -> V_118 ) ;
F_79 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
return 0 ;
}
static int T_7 F_80 ( void )
{
return F_81 ( & V_136 ) ;
}
static void T_8 F_82 ( void )
{
F_83 ( & V_136 ) ;
}
