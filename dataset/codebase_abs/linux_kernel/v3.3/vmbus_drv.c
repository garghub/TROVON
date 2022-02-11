static int F_1 ( void )
{
if ( V_1 == NULL )
return - V_2 ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 ;
if ( ! V_4 -> V_9 )
return;
F_3 ( V_4 -> V_9 , & V_8 ) ;
V_6 -> V_10 = V_8 . V_11 ;
V_6 -> V_12 = V_8 . V_13 ;
memcpy ( & V_6 -> V_14 , & V_8 . V_15 ,
sizeof( V_16 ) ) ;
memcpy ( & V_6 -> V_17 , & V_8 . V_18 ,
sizeof( V_16 ) ) ;
V_6 -> V_19 = V_8 . V_20 ;
V_6 -> V_21 = V_8 . V_22 ;
V_6 -> V_23 = V_8 . V_24 ;
V_6 -> V_25 = V_8 . V_26 ;
V_6 -> V_27 = V_8 . V_28 ;
V_6 -> V_29 = V_8 . V_30 ;
V_6 -> V_31 = V_8 . V_32 ;
V_6 -> V_33 . V_34 = V_8 . V_33 . V_35 ;
V_6 -> V_33 . V_36 = V_8 . V_33 . V_37 ;
V_6 -> V_33 . V_38 = V_8 . V_33 . V_39 ;
V_6 -> V_33 . V_40 =
V_8 . V_33 . V_40 ;
V_6 -> V_33 . V_41 =
V_8 . V_33 . V_41 ;
V_6 -> V_42 . V_34 =
V_8 . V_42 . V_35 ;
V_6 -> V_42 . V_36 = V_8 . V_42 . V_37 ;
V_6 -> V_42 . V_38 = V_8 . V_42 . V_39 ;
V_6 -> V_42 . V_40 =
V_8 . V_42 . V_40 ;
V_6 -> V_42 . V_41 =
V_8 . V_42 . V_41 ;
}
static void F_4 ( struct V_3 * V_43 , char * V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 += 2 )
sprintf ( & V_44 [ V_45 ] , L_1 , V_43 -> V_47 . V_48 [ V_45 / 2 ] ) ;
}
static T_1 F_5 ( struct V_4 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_3 * V_43 = F_6 ( V_49 ) ;
struct V_5 * V_53 ;
char V_44 [ V_46 + 1 ] ;
int V_54 = 0 ;
V_53 = F_7 ( sizeof( struct V_5 ) , V_55 ) ;
if ( ! V_53 )
return V_54 ;
F_2 ( V_43 , V_53 ) ;
if ( ! strcmp ( V_51 -> V_56 . V_57 , L_2 ) ) {
V_54 = sprintf ( V_52 , L_3
L_4 ,
V_53 -> V_14 . V_48 [ 3 ] ,
V_53 -> V_14 . V_48 [ 2 ] ,
V_53 -> V_14 . V_48 [ 1 ] ,
V_53 -> V_14 . V_48 [ 0 ] ,
V_53 -> V_14 . V_48 [ 5 ] ,
V_53 -> V_14 . V_48 [ 4 ] ,
V_53 -> V_14 . V_48 [ 7 ] ,
V_53 -> V_14 . V_48 [ 6 ] ,
V_53 -> V_14 . V_48 [ 8 ] ,
V_53 -> V_14 . V_48 [ 9 ] ,
V_53 -> V_14 . V_48 [ 10 ] ,
V_53 -> V_14 . V_48 [ 11 ] ,
V_53 -> V_14 . V_48 [ 12 ] ,
V_53 -> V_14 . V_48 [ 13 ] ,
V_53 -> V_14 . V_48 [ 14 ] ,
V_53 -> V_14 . V_48 [ 15 ] ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_5 ) ) {
V_54 = sprintf ( V_52 , L_3
L_4 ,
V_53 -> V_17 . V_48 [ 3 ] ,
V_53 -> V_17 . V_48 [ 2 ] ,
V_53 -> V_17 . V_48 [ 1 ] ,
V_53 -> V_17 . V_48 [ 0 ] ,
V_53 -> V_17 . V_48 [ 5 ] ,
V_53 -> V_17 . V_48 [ 4 ] ,
V_53 -> V_17 . V_48 [ 7 ] ,
V_53 -> V_17 . V_48 [ 6 ] ,
V_53 -> V_17 . V_48 [ 8 ] ,
V_53 -> V_17 . V_48 [ 9 ] ,
V_53 -> V_17 . V_48 [ 10 ] ,
V_53 -> V_17 . V_48 [ 11 ] ,
V_53 -> V_17 . V_48 [ 12 ] ,
V_53 -> V_17 . V_48 [ 13 ] ,
V_53 -> V_17 . V_48 [ 14 ] ,
V_53 -> V_17 . V_48 [ 15 ] ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_6 ) ) {
F_4 ( V_43 , V_44 ) ;
V_54 = sprintf ( V_52 , L_7 , V_44 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_8 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_12 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_10 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_10 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_11 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_42 . V_34 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_12 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_42 . V_36 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_13 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_42 . V_38 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_14 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_42 . V_40 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_15 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_42 . V_41 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_16 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_33 . V_34 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_17 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_33 . V_36 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_18 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_33 . V_38 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_19 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_33 . V_40 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_20 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_33 . V_41 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_21 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_19 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_22 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_21 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_23 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_23 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_24 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_25 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_25 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_27 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_26 ) ) {
V_54 = sprintf ( V_52 , L_9 , V_53 -> V_29 ) ;
} else if ( ! strcmp ( V_51 -> V_56 . V_57 , L_27 ) ) {
V_54 = sprintf ( V_52 , L_9 ,
V_53 -> V_31 ) ;
}
F_8 ( V_53 ) ;
return V_54 ;
}
static int F_9 ( struct V_4 * V_4 , struct V_58 * V_59 )
{
struct V_3 * V_49 = F_6 ( V_4 ) ;
int V_54 ;
char V_44 [ V_46 + 1 ] ;
F_4 ( V_49 , V_44 ) ;
V_54 = F_10 ( V_59 , L_28 , V_44 ) ;
return V_54 ;
}
static inline bool F_11 ( const T_2 * V_60 )
{
if ( memcmp ( V_60 , & V_61 , sizeof( V_16 ) ) )
return false ;
return true ;
}
static const struct V_62 * F_12 (
const struct V_62 * V_63 ,
T_2 * V_60 )
{
for (; ! F_11 ( V_63 -> V_60 ) ; V_63 ++ )
if ( ! memcmp ( & V_63 -> V_60 , V_60 , sizeof( V_16 ) ) )
return V_63 ;
return NULL ;
}
static int F_13 ( struct V_4 * V_4 , struct V_64 * V_65 )
{
struct V_66 * V_67 = F_14 ( V_65 ) ;
struct V_3 * V_43 = F_6 ( V_4 ) ;
if ( F_12 ( V_67 -> V_68 , V_43 -> V_47 . V_48 ) )
return 1 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_69 )
{
int V_54 = 0 ;
struct V_66 * V_67 =
F_14 ( V_69 -> V_65 ) ;
struct V_3 * V_49 = F_6 ( V_69 ) ;
const struct V_62 * V_70 ;
V_70 = F_12 ( V_67 -> V_68 , V_49 -> V_47 . V_48 ) ;
if ( V_67 -> V_71 ) {
V_54 = V_67 -> V_71 ( V_49 , V_70 ) ;
if ( V_54 != 0 )
F_16 ( L_29 ,
F_17 ( V_69 ) , V_54 ) ;
} else {
F_16 ( L_30 ,
F_17 ( V_69 ) ) ;
V_54 = - V_2 ;
}
return V_54 ;
}
static int F_18 ( struct V_4 * V_69 )
{
struct V_66 * V_67 = F_14 ( V_69 -> V_65 ) ;
struct V_3 * V_49 = F_6 ( V_69 ) ;
if ( V_67 -> remove )
V_67 -> remove ( V_49 ) ;
else
F_16 ( L_31 ,
F_17 ( V_69 ) ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_69 )
{
struct V_66 * V_67 ;
struct V_3 * V_49 = F_6 ( V_69 ) ;
if ( ! V_69 -> V_65 )
return;
V_67 = F_14 ( V_69 -> V_65 ) ;
if ( V_67 -> V_72 )
V_67 -> V_72 ( V_49 ) ;
return;
}
static void F_20 ( struct V_4 * V_4 )
{
struct V_3 * V_43 = F_6 ( V_4 ) ;
F_8 ( V_43 ) ;
}
static void F_21 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
V_76 = F_22 ( V_74 , struct V_75 ,
V_74 ) ;
F_23 ( & V_76 -> V_77 ) ;
F_8 ( V_76 ) ;
}
static void F_24 ( unsigned long V_78 )
{
int V_79 = F_25 () ;
void * V_80 = V_81 . V_82 [ V_79 ] ;
struct V_83 * V_77 = (struct V_83 * ) V_80 +
V_84 ;
struct V_75 * V_76 ;
while ( 1 ) {
if ( V_77 -> V_85 . V_86 == V_87 ) {
break;
} else {
V_76 = F_26 ( sizeof( * V_76 ) , V_88 ) ;
if ( V_76 == NULL )
continue;
F_27 ( & V_76 -> V_74 , F_21 ) ;
memcpy ( & V_76 -> V_77 , V_77 , sizeof( * V_77 ) ) ;
F_28 ( V_89 . V_90 , & V_76 -> V_74 ) ;
}
V_77 -> V_85 . V_86 = V_87 ;
F_29 () ;
if ( V_77 -> V_85 . V_91 . V_92 ) {
F_30 ( V_93 , 0 ) ;
}
}
}
static T_3 F_31 ( int V_94 , void * V_70 )
{
int V_79 = F_25 () ;
void * V_80 ;
struct V_83 * V_77 ;
union V_95 * V_96 ;
bool V_97 = false ;
V_80 = V_81 . V_98 [ V_79 ] ;
V_96 = (union V_95 * ) V_80 + V_84 ;
if ( F_32 ( 0 , ( unsigned long * ) & V_96 -> V_99 [ 0 ] ) ) {
V_97 = true ;
F_33 ( & V_100 ) ;
}
V_80 = V_81 . V_82 [ V_79 ] ;
V_77 = (struct V_83 * ) V_80 + V_84 ;
if ( V_77 -> V_85 . V_86 != V_87 ) {
V_97 = true ;
F_33 ( & V_101 ) ;
}
if ( V_97 )
return V_102 ;
else
return V_103 ;
}
static int F_34 ( int V_94 )
{
int V_54 ;
unsigned int V_104 ;
V_54 = F_35 () ;
if ( V_54 != 0 ) {
F_16 ( L_32 , V_54 ) ;
return V_54 ;
}
F_36 ( & V_101 , F_24 , 0 ) ;
F_36 ( & V_100 , V_105 , 0 ) ;
V_54 = F_37 ( & V_106 ) ;
if ( V_54 )
goto V_107;
V_54 = F_38 ( V_94 , F_31 , V_108 ,
V_109 , V_1 ) ;
if ( V_54 != 0 ) {
F_16 ( L_33 ,
V_94 ) ;
goto V_110;
}
V_104 = V_111 + V_94 ;
F_39 ( V_112 , ( void * ) & V_104 , 1 ) ;
V_54 = F_40 () ;
if ( V_54 )
goto V_113;
F_41 () ;
return 0 ;
V_113:
F_42 ( V_94 , V_1 ) ;
V_110:
F_43 ( & V_106 ) ;
V_107:
F_44 () ;
return V_54 ;
}
int F_45 ( struct V_66 * V_66 , struct V_114 * V_115 , const char * V_116 )
{
int V_54 ;
F_46 ( L_34 , V_66 -> V_57 ) ;
V_54 = F_1 () ;
if ( V_54 < 0 )
return V_54 ;
V_66 -> V_65 . V_57 = V_66 -> V_57 ;
V_66 -> V_65 . V_115 = V_115 ;
V_66 -> V_65 . V_116 = V_116 ;
V_66 -> V_65 . V_117 = & V_106 ;
V_54 = F_47 ( & V_66 -> V_65 ) ;
F_41 () ;
return V_54 ;
}
void F_48 ( struct V_66 * V_66 )
{
F_46 ( L_35 , V_66 -> V_57 ) ;
if ( ! F_1 () )
F_49 ( & V_66 -> V_65 ) ;
}
struct V_3 * F_50 ( V_16 * type ,
V_16 * V_118 ,
struct V_119 * V_9 )
{
struct V_3 * V_120 ;
V_120 = F_7 ( sizeof( struct V_3 ) , V_55 ) ;
if ( ! V_120 ) {
F_16 ( L_36 ) ;
return NULL ;
}
V_120 -> V_9 = V_9 ;
memcpy ( & V_120 -> V_47 , type , sizeof( V_16 ) ) ;
memcpy ( & V_120 -> V_121 , V_118 ,
sizeof( V_16 ) ) ;
return V_120 ;
}
int F_51 ( struct V_3 * V_120 )
{
int V_54 = 0 ;
static T_4 V_122 = F_52 ( 0 ) ;
F_53 ( & V_120 -> V_4 , L_37 ,
F_54 ( & V_122 ) ) ;
V_120 -> V_4 . V_117 = & V_106 ;
V_120 -> V_4 . V_123 = & V_1 -> V_49 ;
V_120 -> V_4 . V_124 = F_20 ;
V_54 = F_55 ( & V_120 -> V_4 ) ;
if ( V_54 )
F_16 ( L_38 ) ;
else
F_46 ( L_39 ,
F_17 ( & V_120 -> V_4 ) ) ;
return V_54 ;
}
void F_56 ( struct V_3 * V_125 )
{
F_57 ( & V_125 -> V_4 ) ;
F_46 ( L_40 ,
F_17 ( & V_125 -> V_4 ) ) ;
}
static T_5 F_58 ( struct V_126 * V_127 , void * V_94 )
{
if ( V_127 -> type == V_128 ) {
struct V_129 * V_130 ;
V_130 = & V_127 -> V_78 . V_94 ;
* ( ( unsigned int * ) V_94 ) = V_130 -> V_131 [ 0 ] ;
}
return V_132 ;
}
static int F_59 ( struct V_133 * V_4 )
{
T_5 V_134 ;
V_1 = V_4 ;
V_134 = F_60 ( V_4 -> V_135 , V_136 ,
F_58 , & V_94 ) ;
if ( F_61 ( V_134 ) ) {
F_62 ( & V_137 ) ;
return - V_2 ;
}
F_62 ( & V_137 ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
int V_54 , V_138 ;
F_64 ( & V_137 ) ;
V_54 = F_65 ( & V_139 ) ;
if ( V_54 )
return V_54 ;
V_138 = F_66 ( & V_137 , 5 * V_140 ) ;
if ( V_138 == 0 ) {
V_54 = - V_141 ;
goto V_142;
}
if ( V_94 <= 0 ) {
V_54 = - V_2 ;
goto V_142;
}
V_54 = F_34 ( V_94 ) ;
if ( V_54 )
goto V_142;
return 0 ;
V_142:
F_67 ( & V_139 ) ;
V_1 = NULL ;
return V_54 ;
}
static void T_7 F_68 ( void )
{
F_42 ( V_94 , V_1 ) ;
F_69 () ;
F_43 ( & V_106 ) ;
F_44 () ;
F_67 ( & V_139 ) ;
}
