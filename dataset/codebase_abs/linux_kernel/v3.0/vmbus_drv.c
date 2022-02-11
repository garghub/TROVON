static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 V_6 ;
if ( ! V_2 -> V_7 )
return;
F_2 ( V_2 -> V_7 , & V_6 ) ;
V_4 -> V_8 = V_6 . V_9 ;
V_4 -> V_10 = V_6 . V_11 ;
memcpy ( & V_4 -> V_12 , & V_6 . V_13 ,
sizeof( struct V_14 ) ) ;
memcpy ( & V_4 -> V_15 , & V_6 . V_16 ,
sizeof( struct V_14 ) ) ;
V_4 -> V_17 = V_6 . V_18 ;
V_4 -> V_19 = V_6 . V_20 ;
V_4 -> V_21 = V_6 . V_22 ;
V_4 -> V_23 = V_6 . V_24 ;
V_4 -> V_25 = V_6 . V_26 ;
V_4 -> V_27 = V_6 . V_28 ;
V_4 -> V_29 = V_6 . V_30 ;
V_4 -> V_31 . V_32 = V_6 . V_31 . V_33 ;
V_4 -> V_31 . V_34 = V_6 . V_31 . V_35 ;
V_4 -> V_31 . V_36 = V_6 . V_31 . V_37 ;
V_4 -> V_31 . V_38 =
V_6 . V_31 . V_38 ;
V_4 -> V_31 . V_39 =
V_6 . V_31 . V_39 ;
V_4 -> V_40 . V_32 =
V_6 . V_40 . V_33 ;
V_4 -> V_40 . V_34 = V_6 . V_40 . V_35 ;
V_4 -> V_40 . V_36 = V_6 . V_40 . V_37 ;
V_4 -> V_40 . V_38 =
V_6 . V_40 . V_38 ;
V_4 -> V_40 . V_39 =
V_6 . V_40 . V_39 ;
}
static T_1 F_3 ( struct V_2 * V_41 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_45 = F_4 ( V_41 ) ;
struct V_3 V_46 ;
memset ( & V_46 , 0 , sizeof( struct V_3 ) ) ;
F_1 ( V_45 , & V_46 ) ;
if ( ! strcmp ( V_43 -> V_47 . V_48 , L_1 ) ) {
return sprintf ( V_44 , L_2
L_3 ,
V_46 . V_12 . V_49 [ 3 ] ,
V_46 . V_12 . V_49 [ 2 ] ,
V_46 . V_12 . V_49 [ 1 ] ,
V_46 . V_12 . V_49 [ 0 ] ,
V_46 . V_12 . V_49 [ 5 ] ,
V_46 . V_12 . V_49 [ 4 ] ,
V_46 . V_12 . V_49 [ 7 ] ,
V_46 . V_12 . V_49 [ 6 ] ,
V_46 . V_12 . V_49 [ 8 ] ,
V_46 . V_12 . V_49 [ 9 ] ,
V_46 . V_12 . V_49 [ 10 ] ,
V_46 . V_12 . V_49 [ 11 ] ,
V_46 . V_12 . V_49 [ 12 ] ,
V_46 . V_12 . V_49 [ 13 ] ,
V_46 . V_12 . V_49 [ 14 ] ,
V_46 . V_12 . V_49 [ 15 ] ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_4 ) ) {
return sprintf ( V_44 , L_2
L_3 ,
V_46 . V_15 . V_49 [ 3 ] ,
V_46 . V_15 . V_49 [ 2 ] ,
V_46 . V_15 . V_49 [ 1 ] ,
V_46 . V_15 . V_49 [ 0 ] ,
V_46 . V_15 . V_49 [ 5 ] ,
V_46 . V_15 . V_49 [ 4 ] ,
V_46 . V_15 . V_49 [ 7 ] ,
V_46 . V_15 . V_49 [ 6 ] ,
V_46 . V_15 . V_49 [ 8 ] ,
V_46 . V_15 . V_49 [ 9 ] ,
V_46 . V_15 . V_49 [ 10 ] ,
V_46 . V_15 . V_49 [ 11 ] ,
V_46 . V_15 . V_49 [ 12 ] ,
V_46 . V_15 . V_49 [ 13 ] ,
V_46 . V_15 . V_49 [ 14 ] ,
V_46 . V_15 . V_49 [ 15 ] ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_5 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_10 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_7 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_8 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_8 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_32 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_9 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_34 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_10 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_36 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_11 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_40 . V_38 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_12 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_40 . V_39 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_13 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_32 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_14 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_34 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_15 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_36 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_16 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_31 . V_38 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_17 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_31 . V_39 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_18 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_17 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_19 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_19 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_20 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_21 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_21 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_23 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_22 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_25 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_23 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_27 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_24 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_29 ) ;
} else {
return 0 ;
}
}
static int F_5 ( struct V_2 * V_2 , struct V_50 * V_51 )
{
struct V_1 * V_41 = F_4 ( V_2 ) ;
int V_52 ;
V_52 = F_6 ( V_51 , L_25
L_26
L_27 ,
V_41 -> V_53 . V_49 [ 3 ] ,
V_41 -> V_53 . V_49 [ 2 ] ,
V_41 -> V_53 . V_49 [ 1 ] ,
V_41 -> V_53 . V_49 [ 0 ] ,
V_41 -> V_53 . V_49 [ 5 ] ,
V_41 -> V_53 . V_49 [ 4 ] ,
V_41 -> V_53 . V_49 [ 7 ] ,
V_41 -> V_53 . V_49 [ 6 ] ,
V_41 -> V_53 . V_49 [ 8 ] ,
V_41 -> V_53 . V_49 [ 9 ] ,
V_41 -> V_53 . V_49 [ 10 ] ,
V_41 -> V_53 . V_49 [ 11 ] ,
V_41 -> V_53 . V_49 [ 12 ] ,
V_41 -> V_53 . V_49 [ 13 ] ,
V_41 -> V_53 . V_49 [ 14 ] ,
V_41 -> V_53 . V_49 [ 15 ] ) ;
if ( V_52 )
return V_52 ;
V_52 = F_6 ( V_51 , L_28
L_26
L_27 ,
V_41 -> V_54 . V_49 [ 3 ] ,
V_41 -> V_54 . V_49 [ 2 ] ,
V_41 -> V_54 . V_49 [ 1 ] ,
V_41 -> V_54 . V_49 [ 0 ] ,
V_41 -> V_54 . V_49 [ 5 ] ,
V_41 -> V_54 . V_49 [ 4 ] ,
V_41 -> V_54 . V_49 [ 7 ] ,
V_41 -> V_54 . V_49 [ 6 ] ,
V_41 -> V_54 . V_49 [ 8 ] ,
V_41 -> V_54 . V_49 [ 9 ] ,
V_41 -> V_54 . V_49 [ 10 ] ,
V_41 -> V_54 . V_49 [ 11 ] ,
V_41 -> V_54 . V_49 [ 12 ] ,
V_41 -> V_54 . V_49 [ 13 ] ,
V_41 -> V_54 . V_49 [ 14 ] ,
V_41 -> V_54 . V_49 [ 15 ] ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_2 , struct V_55 * V_56 )
{
int V_57 = 0 ;
struct V_58 * V_59 = F_8 ( V_56 ) ;
struct V_1 * V_45 = F_4 ( V_2 ) ;
if ( memcmp ( & V_45 -> V_53 , & V_59 -> V_53 ,
sizeof( struct V_14 ) ) == 0 )
V_57 = 1 ;
return V_57 ;
}
static int F_9 ( struct V_2 * V_60 )
{
int V_52 = 0 ;
struct V_58 * V_59 =
F_8 ( V_60 -> V_56 ) ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( V_59 -> V_61 ) {
V_52 = V_59 -> V_61 ( V_41 ) ;
if ( V_52 != 0 )
F_10 ( L_29 ,
F_11 ( V_60 ) , V_52 ) ;
} else {
F_10 ( L_30 ,
F_11 ( V_60 ) ) ;
V_52 = - 1 ;
}
return V_52 ;
}
static int F_12 ( struct V_2 * V_60 )
{
int V_52 ;
struct V_58 * V_59 ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( V_60 -> V_56 ) {
V_59 = F_8 ( V_60 -> V_56 ) ;
if ( V_59 -> remove ) {
V_52 = V_59 -> remove ( V_41 ) ;
} else {
F_10 ( L_31 ,
F_11 ( V_60 ) ) ;
V_52 = - 1 ;
}
}
return 0 ;
}
static void F_13 ( struct V_2 * V_60 )
{
struct V_58 * V_59 ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( ! V_60 -> V_56 )
return;
V_59 = F_8 ( V_60 -> V_56 ) ;
if ( V_59 -> V_62 )
V_59 -> V_62 ( V_41 ) ;
return;
}
static void F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_45 = F_4 ( V_2 ) ;
F_15 ( V_45 ) ;
}
static void F_16 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
V_66 = F_17 ( V_64 , struct V_65 ,
V_64 ) ;
F_18 ( & V_66 -> V_67 ) ;
F_15 ( V_66 ) ;
}
static void F_19 ( unsigned long V_49 )
{
int V_68 = F_20 () ;
void * V_69 = V_70 . V_71 [ V_68 ] ;
struct V_72 * V_67 = (struct V_72 * ) V_69 +
V_73 ;
struct V_65 * V_66 ;
while ( 1 ) {
if ( V_67 -> V_74 . V_75 == V_76 ) {
break;
} else {
V_66 = F_21 ( sizeof( * V_66 ) , V_77 ) ;
if ( V_66 == NULL )
continue;
F_22 ( & V_66 -> V_64 , F_16 ) ;
memcpy ( & V_66 -> V_67 , V_67 , sizeof( * V_67 ) ) ;
F_23 ( V_78 . V_79 , & V_66 -> V_64 ) ;
}
V_67 -> V_74 . V_75 = V_76 ;
F_24 () ;
if ( V_67 -> V_74 . V_80 . V_81 ) {
F_25 ( V_82 , 0 ) ;
}
}
}
static int F_26 ( void )
{
int V_52 = 0 ;
int V_68 = F_20 () ;
void * V_69 ;
struct V_72 * V_67 ;
union V_83 * V_84 ;
V_69 = V_70 . V_71 [ V_68 ] ;
V_67 = (struct V_72 * ) V_69 + V_73 ;
if ( V_67 -> V_74 . V_75 != V_76 )
V_52 |= 0x1 ;
V_69 = V_70 . V_85 [ V_68 ] ;
V_84 = (union V_83 * ) V_69 + V_73 ;
if ( F_27 ( 0 , ( unsigned long * ) & V_84 -> V_86 [ 0 ] ) )
V_52 |= 0x2 ;
return V_52 ;
}
static T_2 F_28 ( int V_87 , void * V_88 )
{
int V_52 ;
V_52 = F_26 () ;
if ( V_52 > 0 ) {
if ( F_29 ( 0 , ( unsigned long * ) & V_52 ) )
F_30 ( & V_89 ) ;
if ( F_29 ( 1 , ( unsigned long * ) & V_52 ) )
F_30 ( & V_90 ) ;
return V_91 ;
} else {
return V_92 ;
}
}
static int F_31 ( struct V_93 * V_94 )
{
int V_52 ;
unsigned int V_95 ;
V_52 = F_32 () ;
if ( V_52 != 0 ) {
F_10 ( L_32 , V_52 ) ;
goto V_96;
}
F_33 ( & V_89 , F_19 , 0 ) ;
F_33 ( & V_90 , V_97 , 0 ) ;
V_52 = F_34 ( & V_98 ) ;
if ( V_52 ) {
V_52 = - 1 ;
goto V_96;
}
V_52 = F_35 ( V_94 -> V_87 , F_28 ,
V_99 | V_100 ,
V_101 , V_94 ) ;
if ( V_52 != 0 ) {
F_10 ( L_33 ,
V_94 -> V_87 ) ;
F_36 ( & V_98 ) ;
V_52 = - 1 ;
goto V_96;
}
V_95 = V_102 + V_94 -> V_87 ;
F_37 ( V_103 , ( void * ) & V_95 , 1 ) ;
V_52 = F_38 () ;
if ( V_52 ) {
F_39 ( V_94 -> V_87 , V_94 ) ;
F_36 ( & V_98 ) ;
goto V_96;
}
F_40 () ;
V_96:
return V_52 ;
}
int F_41 ( struct V_55 * V_59 )
{
int V_52 ;
F_42 ( L_34 , V_59 -> V_48 ) ;
V_59 -> V_104 = & V_98 ;
V_52 = F_43 ( V_59 ) ;
F_40 () ;
return V_52 ;
}
void F_44 ( struct V_55 * V_59 )
{
F_42 ( L_35 , V_59 -> V_48 ) ;
F_45 ( V_59 ) ;
V_59 -> V_104 = NULL ;
}
struct V_1 * F_46 ( struct V_14 * type ,
struct V_14 * V_105 ,
struct V_106 * V_7 )
{
struct V_1 * V_107 ;
V_107 = F_47 ( sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_107 ) {
F_10 ( L_36 ) ;
return NULL ;
}
V_107 -> V_7 = V_7 ;
memcpy ( & V_107 -> V_53 , type , sizeof( struct V_14 ) ) ;
memcpy ( & V_107 -> V_54 , V_105 ,
sizeof( struct V_14 ) ) ;
return V_107 ;
}
int F_48 ( struct V_1 * V_107 )
{
int V_52 = 0 ;
static T_3 V_109 = F_49 ( 0 ) ;
F_50 ( & V_107 -> V_2 , L_37 ,
F_51 ( & V_109 ) ) ;
V_107 -> V_2 . V_104 = & V_98 ;
V_107 -> V_2 . V_110 = & V_111 -> V_41 ;
V_107 -> V_2 . V_112 = F_14 ;
V_52 = F_52 ( & V_107 -> V_2 ) ;
if ( V_52 )
F_10 ( L_38 ) ;
else
F_42 ( L_39 ,
F_11 ( & V_107 -> V_2 ) ) ;
return V_52 ;
}
void F_53 ( struct V_1 * V_113 )
{
F_54 ( & V_113 -> V_2 ) ;
F_42 ( L_40 ,
F_11 ( & V_113 -> V_2 ) ) ;
}
static T_4 F_55 ( struct V_114 * V_115 , void * V_87 )
{
if ( V_115 -> type == V_116 ) {
struct V_117 * V_118 ;
V_118 = & V_115 -> V_49 . V_87 ;
* ( ( unsigned int * ) V_87 ) = V_118 -> V_119 [ 0 ] ;
}
return V_120 ;
}
static int F_56 ( struct V_121 * V_2 )
{
T_4 V_122 ;
V_122 =
F_57 ( V_2 -> V_123 , V_124 ,
F_55 , & V_87 ) ;
if ( F_58 ( V_122 ) ) {
F_59 ( & V_125 ) ;
return - V_126 ;
}
F_59 ( & V_125 ) ;
return 0 ;
}
static int F_60 ( void )
{
int V_122 ;
V_122 = F_61 ( & V_127 ) ;
if ( V_122 < 0 )
return V_122 ;
return 0 ;
}
static void F_62 ( void )
{
F_63 ( & V_127 ) ;
return;
}
static int T_5 F_64 ( struct V_93 * V_94 ,
const struct V_128 * V_129 )
{
V_111 = V_94 ;
V_130 = F_65 ( V_94 ) ;
if ( V_130 )
goto V_131;
if ( V_94 -> V_87 == 0 )
V_94 -> V_87 = V_87 ;
V_130 = F_31 ( V_94 ) ;
if ( V_130 )
F_66 ( V_94 ) ;
V_131:
F_59 ( & V_125 ) ;
return V_130 ;
}
static int T_6 F_67 ( void )
{
int V_52 ;
F_68 ( & V_125 ) ;
V_52 = F_60 () ;
if ( V_52 )
return V_52 ;
F_69 ( & V_125 ) ;
if ( V_87 <= 0 ) {
F_62 () ;
return - V_126 ;
}
F_62 () ;
F_68 ( & V_125 ) ;
V_52 = F_70 ( & V_132 ) ;
if ( V_52 )
return V_52 ;
F_69 ( & V_125 ) ;
if ( V_130 )
F_71 ( & V_132 ) ;
return V_130 ;
}
