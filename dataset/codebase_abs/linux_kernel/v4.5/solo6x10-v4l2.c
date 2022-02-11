static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_2 , V_3 ) ;
V_1 -> V_4 = 1 ;
V_1 -> V_5 = 0 ;
}
static inline int F_3 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 )
return 0 ;
if ( ! V_1 -> V_5 )
F_2 ( V_1 , V_2 , 0 ) ;
if ( V_1 -> V_5 ++ >= 8 )
V_1 -> V_4 = 0 ;
return 1 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_6 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_7 ,
int V_8 , int V_9 , int V_10 , int V_11 , int V_12 )
{
if ( V_7 >= V_1 -> V_13 )
return;
F_2 ( V_1 , F_7 ( V_7 ) ,
F_8 ( V_7 ) |
F_9 ( V_8 ) |
F_10 ( V_10 ) |
F_11 ( V_12 ) ) ;
F_2 ( V_1 , F_12 ( V_7 ) ,
F_13 ( V_9 ) |
F_14 ( V_11 ) ) ;
}
static int F_15 ( struct V_1 * V_1 , T_1 V_14 , int V_15 )
{
T_1 V_7 = V_14 * 4 ;
if ( V_7 >= V_1 -> V_13 )
return - V_16 ;
if ( ! V_15 ) {
T_1 V_17 ;
for ( V_17 = V_7 ; V_17 < V_7 + 4 ; V_17 ++ )
F_6 ( V_1 , V_17 , V_1 -> V_18 ,
F_16 ( V_1 ) ,
V_1 -> V_18 ,
F_16 ( V_1 ) , 0 ) ;
return 0 ;
}
F_6 ( V_1 , V_7 , 0 , 0 , V_1 -> V_18 / 2 ,
F_16 ( V_1 ) / 2 , 3 ) ;
F_6 ( V_1 , V_7 + 1 , V_1 -> V_18 / 2 , 0 ,
V_1 -> V_18 , F_16 ( V_1 ) / 2 , 3 ) ;
F_6 ( V_1 , V_7 + 2 , 0 , F_16 ( V_1 ) / 2 ,
V_1 -> V_18 / 2 , F_16 ( V_1 ) , 3 ) ;
F_6 ( V_1 , V_7 + 3 , V_1 -> V_18 / 2 ,
F_16 ( V_1 ) / 2 , V_1 -> V_18 ,
F_16 ( V_1 ) , 3 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , int V_15 )
{
int V_9 , V_19 , V_20 , V_17 ;
if ( ! V_15 ) {
for ( V_17 = 0 ; V_17 < 16 ; V_17 ++ )
F_6 ( V_1 , V_17 , V_1 -> V_18 ,
F_16 ( V_1 ) ,
V_1 -> V_18 ,
F_16 ( V_1 ) , 0 ) ;
return 0 ;
}
V_19 = F_16 ( V_1 ) / 4 ;
V_20 = V_1 -> V_18 / 4 ;
for ( V_9 = 0 , V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_9 += V_19 ) {
F_6 ( V_1 , V_17 * 4 , 0 , V_9 , V_20 ,
V_9 + V_19 , 5 ) ;
F_6 ( V_1 , ( V_17 * 4 ) + 1 , V_20 , V_9 ,
V_20 * 2 , V_9 + V_19 , 5 ) ;
F_6 ( V_1 , ( V_17 * 4 ) + 2 , V_20 * 2 , V_9 ,
V_20 * 3 , V_9 + V_19 , 5 ) ;
F_6 ( V_1 , ( V_17 * 4 ) + 3 , V_20 * 3 , V_9 ,
V_1 -> V_18 , V_9 + V_19 , 5 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , T_1 V_7 , int V_15 )
{
T_1 V_21 ;
if ( V_7 < V_1 -> V_13 ) {
F_6 ( V_1 , V_7 , V_15 ? 0 : V_1 -> V_18 ,
V_15 ? 0 : F_16 ( V_1 ) ,
V_1 -> V_18 , F_16 ( V_1 ) ,
V_15 ? 1 : 0 ) ;
return 0 ;
}
if ( V_7 >= V_1 -> V_13 + V_1 -> V_22 )
return - V_16 ;
V_21 = V_7 - V_1 -> V_13 ;
if ( V_21 < 4 )
return F_15 ( V_1 , V_21 , V_15 ) ;
return F_17 ( V_1 , V_15 ) ;
}
static int F_19 ( struct V_1 * V_1 , T_1 V_7 )
{
if ( V_7 >= V_1 -> V_13 + V_1 -> V_22 )
return - V_16 ;
F_1 ( V_1 ) ;
F_18 ( V_1 , V_1 -> V_23 , 0 ) ;
F_18 ( V_1 , V_7 , 1 ) ;
V_1 -> V_23 = V_7 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_21 ( V_25 ) ;
T_2 V_28 ;
unsigned int V_29 ;
int error = - 1 ;
int V_17 ;
V_28 = F_22 ( V_25 , 0 ) ;
if ( ! V_28 )
goto V_30;
if ( F_3 ( V_1 ) ) {
void * V_31 = F_23 ( V_25 , 0 ) ;
int V_32 = F_24 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < V_32 ; V_17 += 2 ) {
( ( T_1 * ) V_31 ) [ V_17 ] = 0x80 ;
( ( T_1 * ) V_31 ) [ V_17 + 1 ] = 0x00 ;
}
error = 0 ;
} else {
V_29 = V_33 + ( V_1 -> V_34 *
( V_35 * F_16 ( V_1 ) ) ) ;
error = F_25 ( V_1 , 0 , V_28 , V_29 ,
F_26 ( V_1 ) ,
F_16 ( V_1 ) , V_35 ) ;
}
V_30:
if ( ! error ) {
F_27 ( V_25 , 0 ,
F_16 ( V_1 ) * F_26 ( V_1 ) ) ;
V_27 -> V_36 = V_1 -> V_36 ++ ;
V_25 -> V_37 = F_28 () ;
}
F_29 ( V_25 , error ? V_38 : V_39 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_40 * V_25 ;
for (; ; ) {
unsigned int V_41 ;
V_41 = F_31 (
F_32 ( V_1 , V_42 ) ) ;
if ( V_41 == V_1 -> V_34 )
return;
F_33 ( & V_1 -> V_43 ) ;
if ( F_34 ( & V_1 -> V_44 ) )
break;
V_25 = F_35 ( & V_1 -> V_44 , struct V_40 ,
V_45 ) ;
V_1 -> V_34 = V_41 ;
F_36 ( & V_25 -> V_45 ) ;
F_37 ( & V_1 -> V_43 ) ;
F_20 ( V_1 , & V_25 -> V_25 . V_46 ) ;
}
F_38 ( & V_1 -> V_43 ) ;
F_37 ( & V_1 -> V_43 ) ;
}
static int F_39 ( void * V_47 )
{
struct V_1 * V_1 = V_47 ;
F_40 ( V_48 , V_49 ) ;
F_41 () ;
F_42 ( & V_1 -> V_6 , & V_48 ) ;
for (; ; ) {
long V_50 = F_43 ( V_51 ) ;
if ( V_50 == - V_52 || F_44 () )
break;
F_30 ( V_1 ) ;
F_45 () ;
}
F_46 ( & V_1 -> V_6 , & V_48 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 )
{
int V_53 = 0 ;
V_1 -> V_54 = F_48 ( F_39 , V_1 , V_55 L_1 ) ;
if ( F_49 ( V_1 -> V_54 ) ) {
V_53 = F_50 ( V_1 -> V_54 ) ;
V_1 -> V_54 = NULL ;
return V_53 ;
}
F_51 ( V_1 , V_56 ) ;
return V_53 ;
}
static void F_52 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_54 )
return;
F_53 ( V_1 , V_56 ) ;
F_54 ( V_1 -> V_54 ) ;
V_1 -> V_54 = NULL ;
}
static int F_55 ( struct V_57 * V_58 ,
unsigned int * V_59 , unsigned int * V_60 ,
unsigned int V_61 [] , void * V_62 [] )
{
struct V_1 * V_1 = F_56 ( V_58 ) ;
V_61 [ 0 ] = F_24 ( V_1 ) ;
V_62 [ 0 ] = V_1 -> V_63 ;
* V_60 = 1 ;
if ( * V_59 < V_64 )
* V_59 = V_64 ;
return 0 ;
}
static int F_57 ( struct V_57 * V_58 , unsigned int V_65 )
{
struct V_1 * V_1 = F_56 ( V_58 ) ;
V_1 -> V_36 = 0 ;
return F_47 ( V_1 ) ;
}
static void F_58 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_56 ( V_58 ) ;
F_52 ( V_1 ) ;
F_59 ( & V_1 -> V_44 ) ;
}
static void F_60 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_21 ( V_25 ) ;
struct V_57 * V_66 = V_25 -> V_57 ;
struct V_1 * V_1 = F_56 ( V_66 ) ;
struct V_40 * V_67 =
F_61 ( V_27 , struct V_40 , V_25 ) ;
F_33 ( & V_1 -> V_43 ) ;
F_62 ( & V_67 -> V_45 , & V_1 -> V_44 ) ;
F_37 ( & V_1 -> V_43 ) ;
F_63 ( & V_1 -> V_6 ) ;
}
static int F_64 ( struct V_68 * V_68 , void * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
strcpy ( V_71 -> V_72 , V_55 ) ;
strcpy ( V_71 -> V_73 , L_2 ) ;
snprintf ( V_71 -> V_74 , sizeof( V_71 -> V_74 ) , L_3 ,
F_66 ( V_1 -> V_75 ) ) ;
V_71 -> V_76 = V_77 |
V_78 | V_79 ;
V_71 -> V_80 = V_71 -> V_76 | V_81 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_1 ,
struct V_82 * V_83 )
{
static const char * const V_84 [] = { L_4 } ;
static const char * const V_85 [] = { L_5 , L_6 } ;
static const char * const V_86 [] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
const char * const * V_87 ;
if ( V_83 -> V_88 >= ( V_1 -> V_13 + V_1 -> V_22 ) )
return - V_16 ;
if ( V_1 -> V_22 == 5 )
V_87 = V_86 ;
else if ( V_1 -> V_22 == 2 )
V_87 = V_85 ;
else
V_87 = V_84 ;
snprintf ( V_83 -> V_89 , sizeof( V_83 -> V_89 ) , L_10 ,
V_87 [ V_83 -> V_88 - V_1 -> V_13 ] ) ;
return 0 ;
}
static int F_68 ( struct V_68 * V_68 , void * V_69 ,
struct V_82 * V_83 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
if ( V_83 -> V_88 >= V_1 -> V_13 ) {
int V_53 = F_67 ( V_1 , V_83 ) ;
if ( V_53 < 0 )
return V_53 ;
} else {
snprintf ( V_83 -> V_89 , sizeof( V_83 -> V_89 ) , L_11 ,
V_83 -> V_88 + 1 ) ;
if ( ! F_69 ( V_1 , V_83 -> V_88 ) )
V_83 -> V_90 = V_91 ;
}
V_83 -> type = V_92 ;
V_83 -> V_93 = V_1 -> V_94 -> V_95 ;
return 0 ;
}
static int F_70 ( struct V_68 * V_68 , void * V_69 , unsigned int V_88 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
int V_53 = F_19 ( V_1 , V_88 ) ;
if ( ! V_53 ) {
while ( F_3 ( V_1 ) )
;
}
return V_53 ;
}
static int F_71 ( struct V_68 * V_68 , void * V_69 , unsigned int * V_88 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
* V_88 = V_1 -> V_23 ;
return 0 ;
}
static int F_72 ( struct V_68 * V_68 , void * V_69 ,
struct V_96 * V_97 )
{
if ( V_97 -> V_88 )
return - V_16 ;
V_97 -> V_98 = V_99 ;
F_73 ( V_97 -> V_100 , L_12 , sizeof( V_97 -> V_100 ) ) ;
return 0 ;
}
static int F_74 ( struct V_68 * V_68 , void * V_69 ,
struct V_101 * V_97 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
struct V_102 * V_103 = & V_97 -> V_104 . V_103 ;
int V_32 = F_24 ( V_1 ) ;
if ( V_103 -> V_98 != V_99 )
return - V_16 ;
V_103 -> V_105 = V_1 -> V_18 ;
V_103 -> V_106 = F_16 ( V_1 ) ;
V_103 -> V_107 = V_32 ;
V_103 -> V_108 = V_109 ;
V_103 -> V_98 = V_99 ;
V_103 -> V_110 = V_111 ;
V_103 -> V_69 = 0 ;
return 0 ;
}
static int F_75 ( struct V_68 * V_68 , void * V_69 ,
struct V_101 * V_97 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
if ( F_76 ( & V_1 -> V_112 ) )
return - V_113 ;
return F_74 ( V_68 , V_69 , V_97 ) ;
}
static int F_77 ( struct V_68 * V_68 , void * V_69 ,
struct V_101 * V_97 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
struct V_102 * V_103 = & V_97 -> V_104 . V_103 ;
V_103 -> V_105 = V_1 -> V_18 ;
V_103 -> V_106 = F_16 ( V_1 ) ;
V_103 -> V_98 = V_99 ;
V_103 -> V_108 = V_109 ;
V_103 -> V_107 = F_24 ( V_1 ) ;
V_103 -> V_110 = V_111 ;
V_103 -> V_114 = F_26 ( V_1 ) ;
V_103 -> V_69 = 0 ;
return 0 ;
}
static int F_78 ( struct V_68 * V_68 , void * V_69 , T_3 * V_17 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
if ( V_1 -> V_115 == V_116 )
* V_17 = V_117 ;
else
* V_17 = V_118 ;
return 0 ;
}
int F_79 ( struct V_1 * V_1 , bool V_119 )
{
int V_17 ;
if ( F_76 ( & V_1 -> V_112 ) )
return - V_113 ;
for ( V_17 = 0 ; V_17 < V_1 -> V_13 ; V_17 ++ )
if ( F_76 ( & V_1 -> V_120 [ V_17 ] -> V_112 ) )
return - V_113 ;
V_1 -> V_115 = V_119 ? V_121 :
V_116 ;
F_80 ( V_1 ) ;
F_81 ( V_1 ) ;
F_82 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < V_1 -> V_13 ; V_17 ++ )
F_83 ( V_1 -> V_120 [ V_17 ] ) ;
return F_19 ( V_1 , V_1 -> V_23 ) ;
}
static int F_84 ( struct V_68 * V_68 , void * V_69 , T_3 V_93 )
{
struct V_1 * V_1 = F_65 ( V_68 ) ;
return F_79 ( V_1 , V_93 & V_122 ) ;
}
static int F_85 ( struct V_123 * V_124 )
{
struct V_1 * V_1 =
F_61 ( V_124 -> V_125 , struct V_1 , V_126 ) ;
switch ( V_124 -> V_127 ) {
case V_128 :
if ( V_124 -> V_129 ) {
F_2 ( V_1 , V_130 ,
V_131 |
F_86 ( 0x20 ) |
F_87 ( 0x10 ) |
F_88 ( 0x10 ) ) ;
F_2 ( V_1 , V_132 ,
V_133 |
F_86 ( 0x10 ) |
F_87 ( 0x80 ) |
F_88 ( 0x10 ) ) ;
} else {
F_2 ( V_1 , V_130 , 0 ) ;
F_2 ( V_1 , V_132 , 0 ) ;
}
return 0 ;
default:
break;
}
return - V_16 ;
}
int F_89 ( struct V_1 * V_1 , unsigned V_134 )
{
int V_53 ;
int V_17 ;
F_90 ( & V_1 -> V_6 ) ;
F_91 ( & V_1 -> V_43 ) ;
F_92 ( & V_1 -> V_135 ) ;
F_59 ( & V_1 -> V_44 ) ;
V_1 -> V_94 = F_93 () ;
if ( ! V_1 -> V_94 )
return - V_136 ;
* V_1 -> V_94 = V_137 ;
V_1 -> V_94 -> V_138 = & V_1 -> V_138 ;
V_1 -> V_94 -> V_139 = & V_1 -> V_112 ;
V_1 -> V_94 -> V_135 = & V_1 -> V_135 ;
F_94 ( & V_1 -> V_126 , 1 ) ;
F_95 ( & V_1 -> V_126 , & V_140 , NULL ) ;
if ( V_1 -> V_126 . error ) {
V_53 = V_1 -> V_126 . error ;
goto V_141;
}
V_1 -> V_94 -> V_142 = & V_1 -> V_126 ;
F_96 ( V_1 -> V_94 , V_1 ) ;
V_1 -> V_112 . type = V_143 ;
V_1 -> V_112 . V_144 = V_145 | V_146 | V_147 ;
V_1 -> V_112 . V_148 = & V_149 ;
V_1 -> V_112 . V_150 = & V_151 ;
V_1 -> V_112 . V_152 = V_1 ;
V_1 -> V_112 . V_153 = V_154 ;
V_1 -> V_112 . V_155 = V_156 | V_157 ;
V_1 -> V_112 . V_158 = sizeof( struct V_40 ) ;
V_1 -> V_112 . V_135 = & V_1 -> V_135 ;
V_53 = F_97 ( & V_1 -> V_112 ) ;
if ( V_53 < 0 )
goto V_141;
V_1 -> V_63 = F_98 ( & V_1 -> V_75 -> V_159 ) ;
if ( F_49 ( V_1 -> V_63 ) ) {
F_99 ( & V_1 -> V_75 -> V_159 , L_13 ) ;
return F_50 ( V_1 -> V_63 ) ;
}
for ( V_17 = 0 ; V_17 < V_1 -> V_13 ; V_17 ++ ) {
F_19 ( V_1 , V_17 ) ;
while ( F_3 ( V_1 ) )
;
}
F_19 ( V_1 , 0 ) ;
while ( F_3 ( V_1 ) )
;
V_53 = F_100 ( V_1 -> V_94 , V_160 , V_134 ) ;
if ( V_53 < 0 )
goto V_141;
snprintf ( V_1 -> V_94 -> V_89 , sizeof( V_1 -> V_94 -> V_89 ) , L_14 ,
V_55 , V_1 -> V_94 -> V_161 ) ;
F_101 ( & V_1 -> V_75 -> V_159 , L_15
L_16 , V_1 -> V_94 -> V_161 ,
V_1 -> V_13 , V_1 -> V_22 ) ;
return 0 ;
V_141:
F_102 ( V_1 -> V_94 ) ;
F_103 ( V_1 -> V_63 ) ;
F_104 ( & V_1 -> V_126 ) ;
V_1 -> V_94 = NULL ;
return V_53 ;
}
void F_105 ( struct V_1 * V_1 )
{
if ( V_1 -> V_94 == NULL )
return;
F_106 ( V_1 -> V_94 ) ;
F_103 ( V_1 -> V_63 ) ;
F_104 ( & V_1 -> V_126 ) ;
V_1 -> V_94 = NULL ;
}
