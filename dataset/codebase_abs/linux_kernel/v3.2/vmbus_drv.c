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
sizeof( V_14 ) ) ;
memcpy ( & V_4 -> V_15 , & V_6 . V_16 ,
sizeof( V_14 ) ) ;
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
static void F_3 ( struct V_1 * V_41 , char * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 += 2 )
sprintf ( & V_42 [ V_43 ] , L_1 , V_41 -> V_45 . V_46 [ V_43 / 2 ] ) ;
}
static T_1 F_4 ( struct V_2 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_1 * V_41 = F_5 ( V_47 ) ;
struct V_3 * V_51 ;
char V_42 [ V_44 + 1 ] ;
int V_52 = 0 ;
V_51 = F_6 ( sizeof( struct V_3 ) , V_53 ) ;
if ( ! V_51 )
return V_52 ;
F_1 ( V_41 , V_51 ) ;
if ( ! strcmp ( V_49 -> V_54 . V_55 , L_2 ) ) {
V_52 = sprintf ( V_50 , L_3
L_4 ,
V_51 -> V_12 . V_46 [ 3 ] ,
V_51 -> V_12 . V_46 [ 2 ] ,
V_51 -> V_12 . V_46 [ 1 ] ,
V_51 -> V_12 . V_46 [ 0 ] ,
V_51 -> V_12 . V_46 [ 5 ] ,
V_51 -> V_12 . V_46 [ 4 ] ,
V_51 -> V_12 . V_46 [ 7 ] ,
V_51 -> V_12 . V_46 [ 6 ] ,
V_51 -> V_12 . V_46 [ 8 ] ,
V_51 -> V_12 . V_46 [ 9 ] ,
V_51 -> V_12 . V_46 [ 10 ] ,
V_51 -> V_12 . V_46 [ 11 ] ,
V_51 -> V_12 . V_46 [ 12 ] ,
V_51 -> V_12 . V_46 [ 13 ] ,
V_51 -> V_12 . V_46 [ 14 ] ,
V_51 -> V_12 . V_46 [ 15 ] ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_5 ) ) {
V_52 = sprintf ( V_50 , L_3
L_4 ,
V_51 -> V_15 . V_46 [ 3 ] ,
V_51 -> V_15 . V_46 [ 2 ] ,
V_51 -> V_15 . V_46 [ 1 ] ,
V_51 -> V_15 . V_46 [ 0 ] ,
V_51 -> V_15 . V_46 [ 5 ] ,
V_51 -> V_15 . V_46 [ 4 ] ,
V_51 -> V_15 . V_46 [ 7 ] ,
V_51 -> V_15 . V_46 [ 6 ] ,
V_51 -> V_15 . V_46 [ 8 ] ,
V_51 -> V_15 . V_46 [ 9 ] ,
V_51 -> V_15 . V_46 [ 10 ] ,
V_51 -> V_15 . V_46 [ 11 ] ,
V_51 -> V_15 . V_46 [ 12 ] ,
V_51 -> V_15 . V_46 [ 13 ] ,
V_51 -> V_15 . V_46 [ 14 ] ,
V_51 -> V_15 . V_46 [ 15 ] ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_6 ) ) {
F_3 ( V_41 , V_42 ) ;
V_52 = sprintf ( V_50 , L_7 , V_42 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_8 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_10 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_10 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_8 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_11 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_40 . V_32 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_12 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_40 . V_34 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_13 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_40 . V_36 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_14 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_40 . V_38 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_15 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_40 . V_39 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_16 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_31 . V_32 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_17 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_31 . V_34 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_18 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_31 . V_36 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_19 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_31 . V_38 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_20 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_31 . V_39 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_21 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_17 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_22 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_19 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_23 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_21 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_24 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_23 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_25 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_25 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_26 ) ) {
V_52 = sprintf ( V_50 , L_9 , V_51 -> V_27 ) ;
} else if ( ! strcmp ( V_49 -> V_54 . V_55 , L_27 ) ) {
V_52 = sprintf ( V_50 , L_9 ,
V_51 -> V_29 ) ;
}
F_7 ( V_51 ) ;
return V_52 ;
}
static int F_8 ( struct V_2 * V_2 , struct V_56 * V_57 )
{
struct V_1 * V_47 = F_5 ( V_2 ) ;
int V_52 ;
char V_42 [ V_44 + 1 ] ;
F_3 ( V_47 , V_42 ) ;
V_52 = F_9 ( V_57 , L_28 , V_42 ) ;
return V_52 ;
}
static inline bool F_10 ( const T_2 * V_58 )
{
if ( memcmp ( V_58 , & V_59 , sizeof( V_14 ) ) )
return false ;
return true ;
}
static const struct V_60 * F_11 (
const struct V_60 * V_61 ,
T_2 * V_58 )
{
for (; ! F_10 ( V_61 -> V_58 ) ; V_61 ++ )
if ( ! memcmp ( & V_61 -> V_58 , V_58 , sizeof( V_14 ) ) )
return V_61 ;
return NULL ;
}
static int F_12 ( struct V_2 * V_2 , struct V_62 * V_63 )
{
struct V_64 * V_65 = F_13 ( V_63 ) ;
struct V_1 * V_41 = F_5 ( V_2 ) ;
if ( F_11 ( V_65 -> V_66 , V_41 -> V_45 . V_46 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_67 )
{
int V_52 = 0 ;
struct V_64 * V_65 =
F_13 ( V_67 -> V_63 ) ;
struct V_1 * V_47 = F_5 ( V_67 ) ;
const struct V_60 * V_68 ;
V_68 = F_11 ( V_65 -> V_66 , V_47 -> V_45 . V_46 ) ;
if ( V_65 -> V_69 ) {
V_52 = V_65 -> V_69 ( V_47 , V_68 ) ;
if ( V_52 != 0 )
F_15 ( L_29 ,
F_16 ( V_67 ) , V_52 ) ;
} else {
F_15 ( L_30 ,
F_16 ( V_67 ) ) ;
V_52 = - V_70 ;
}
return V_52 ;
}
static int F_17 ( struct V_2 * V_67 )
{
struct V_64 * V_65 = F_13 ( V_67 -> V_63 ) ;
struct V_1 * V_47 = F_5 ( V_67 ) ;
if ( V_65 -> remove )
V_65 -> remove ( V_47 ) ;
else
F_15 ( L_31 ,
F_16 ( V_67 ) ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_67 )
{
struct V_64 * V_65 ;
struct V_1 * V_47 = F_5 ( V_67 ) ;
if ( ! V_67 -> V_63 )
return;
V_65 = F_13 ( V_67 -> V_63 ) ;
if ( V_65 -> V_71 )
V_65 -> V_71 ( V_47 ) ;
return;
}
static void F_19 ( struct V_2 * V_2 )
{
struct V_1 * V_41 = F_5 ( V_2 ) ;
F_7 ( V_41 ) ;
}
static void F_20 ( struct V_72 * V_73 )
{
struct V_74 * V_75 ;
V_75 = F_21 ( V_73 , struct V_74 ,
V_73 ) ;
F_22 ( & V_75 -> V_76 ) ;
F_7 ( V_75 ) ;
}
static void F_23 ( unsigned long V_77 )
{
int V_78 = F_24 () ;
void * V_79 = V_80 . V_81 [ V_78 ] ;
struct V_82 * V_76 = (struct V_82 * ) V_79 +
V_83 ;
struct V_74 * V_75 ;
while ( 1 ) {
if ( V_76 -> V_84 . V_85 == V_86 ) {
break;
} else {
V_75 = F_25 ( sizeof( * V_75 ) , V_87 ) ;
if ( V_75 == NULL )
continue;
F_26 ( & V_75 -> V_73 , F_20 ) ;
memcpy ( & V_75 -> V_76 , V_76 , sizeof( * V_76 ) ) ;
F_27 ( V_88 . V_89 , & V_75 -> V_73 ) ;
}
V_76 -> V_84 . V_85 = V_86 ;
F_28 () ;
if ( V_76 -> V_84 . V_90 . V_91 ) {
F_29 ( V_92 , 0 ) ;
}
}
}
static T_3 F_30 ( int V_93 , void * V_68 )
{
int V_78 = F_24 () ;
void * V_79 ;
struct V_82 * V_76 ;
union V_94 * V_95 ;
bool V_96 = false ;
V_79 = V_80 . V_97 [ V_78 ] ;
V_95 = (union V_94 * ) V_79 + V_83 ;
if ( F_31 ( 0 , ( unsigned long * ) & V_95 -> V_98 [ 0 ] ) ) {
V_96 = true ;
F_32 ( & V_99 ) ;
}
V_79 = V_80 . V_81 [ V_78 ] ;
V_76 = (struct V_82 * ) V_79 + V_83 ;
if ( V_76 -> V_84 . V_85 != V_86 ) {
V_96 = true ;
F_32 ( & V_100 ) ;
}
if ( V_96 )
return V_101 ;
else
return V_102 ;
}
static int F_33 ( int V_93 )
{
int V_52 ;
unsigned int V_103 ;
V_52 = F_34 () ;
if ( V_52 != 0 ) {
F_15 ( L_32 , V_52 ) ;
return V_52 ;
}
F_35 ( & V_100 , F_23 , 0 ) ;
F_35 ( & V_99 , V_104 , 0 ) ;
V_52 = F_36 ( & V_105 ) ;
if ( V_52 )
goto V_106;
V_52 = F_37 ( V_93 , F_30 , V_107 ,
V_108 , V_109 ) ;
if ( V_52 != 0 ) {
F_15 ( L_33 ,
V_93 ) ;
goto V_110;
}
V_103 = V_111 + V_93 ;
F_38 ( V_112 , ( void * ) & V_103 , 1 ) ;
V_52 = F_39 () ;
if ( V_52 )
goto V_113;
F_40 () ;
return 0 ;
V_113:
F_41 ( V_93 , V_109 ) ;
V_110:
F_42 ( & V_105 ) ;
V_106:
F_43 () ;
return V_52 ;
}
int F_44 ( struct V_64 * V_64 , struct V_114 * V_115 , const char * V_116 )
{
int V_52 ;
F_45 ( L_34 , V_64 -> V_55 ) ;
V_64 -> V_63 . V_55 = V_64 -> V_55 ;
V_64 -> V_63 . V_115 = V_115 ;
V_64 -> V_63 . V_116 = V_116 ;
V_64 -> V_63 . V_117 = & V_105 ;
V_52 = F_46 ( & V_64 -> V_63 ) ;
F_40 () ;
return V_52 ;
}
void F_47 ( struct V_64 * V_64 )
{
F_45 ( L_35 , V_64 -> V_55 ) ;
F_48 ( & V_64 -> V_63 ) ;
}
struct V_1 * F_49 ( V_14 * type ,
V_14 * V_118 ,
struct V_119 * V_7 )
{
struct V_1 * V_120 ;
V_120 = F_6 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_120 ) {
F_15 ( L_36 ) ;
return NULL ;
}
V_120 -> V_7 = V_7 ;
memcpy ( & V_120 -> V_45 , type , sizeof( V_14 ) ) ;
memcpy ( & V_120 -> V_121 , V_118 ,
sizeof( V_14 ) ) ;
return V_120 ;
}
int F_50 ( struct V_1 * V_120 )
{
int V_52 = 0 ;
static T_4 V_122 = F_51 ( 0 ) ;
F_52 ( & V_120 -> V_2 , L_37 ,
F_53 ( & V_122 ) ) ;
V_120 -> V_2 . V_117 = & V_105 ;
V_120 -> V_2 . V_123 = & V_109 -> V_47 ;
V_120 -> V_2 . V_124 = F_19 ;
V_52 = F_54 ( & V_120 -> V_2 ) ;
if ( V_52 )
F_15 ( L_38 ) ;
else
F_45 ( L_39 ,
F_16 ( & V_120 -> V_2 ) ) ;
return V_52 ;
}
void F_55 ( struct V_1 * V_125 )
{
F_56 ( & V_125 -> V_2 ) ;
F_45 ( L_40 ,
F_16 ( & V_125 -> V_2 ) ) ;
}
static T_5 F_57 ( struct V_126 * V_127 , void * V_93 )
{
if ( V_127 -> type == V_128 ) {
struct V_129 * V_130 ;
V_130 = & V_127 -> V_77 . V_93 ;
* ( ( unsigned int * ) V_93 ) = V_130 -> V_131 [ 0 ] ;
}
return V_132 ;
}
static int F_58 ( struct V_133 * V_2 )
{
T_5 V_134 ;
V_109 = V_2 ;
V_134 = F_59 ( V_2 -> V_135 , V_136 ,
F_57 , & V_93 ) ;
if ( F_60 ( V_134 ) ) {
F_61 ( & V_137 ) ;
return - V_70 ;
}
F_61 ( & V_137 ) ;
return 0 ;
}
static int T_6 F_62 ( void )
{
int V_52 , V_138 ;
F_63 ( & V_137 ) ;
V_52 = F_64 ( & V_139 ) ;
if ( V_52 )
return V_52 ;
V_138 = F_65 ( & V_137 , 5 * V_140 ) ;
if ( V_138 == 0 ) {
V_52 = - V_141 ;
goto V_142;
}
if ( V_93 <= 0 ) {
V_52 = - V_70 ;
goto V_142;
}
V_52 = F_33 ( V_93 ) ;
if ( V_52 )
goto V_142;
return 0 ;
V_142:
F_66 ( & V_139 ) ;
return V_52 ;
}
