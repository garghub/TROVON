static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
if ( F_2 ( V_2 -> V_5 -> V_6 , V_3 , V_4 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
V_2 -> V_7 += V_4 ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 V_13 ,
struct V_14 * V_14 V_13 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
return F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
}
static int
F_6 ( void * V_16 , int V_17 , T_3 V_18 , T_3 * V_19 , T_3 * V_20 )
{
struct V_21 * V_22 ;
T_3 V_23 = V_18 ;
int V_4 = V_17 + 1 ;
F_7 ( L_2 V_24 L_3 , V_16 , V_18 ) ;
V_22 = (struct V_21 * ) ( V_16 + ( V_18 & V_17 ) ) ;
* V_19 = V_18 ;
while ( true ) {
if ( V_23 - V_18 >= ( unsigned int ) V_4 ) {
F_8 ( L_4 ) ;
if ( V_23 - V_18 > ( unsigned int ) V_4 )
V_23 -= V_22 -> V_4 ;
* V_20 = V_23 ;
return 0 ;
}
V_22 = (struct V_21 * ) ( V_16 + ( V_23 & V_17 ) ) ;
if ( V_22 -> V_4 == 0 ) {
F_8 ( L_5 ) ;
* V_20 = V_23 ;
return 0 ;
}
V_23 += V_22 -> V_4 ;
F_9 ( L_6 V_24 L_3 , V_23 ) ;
}
F_10 ( 1 , L_7 ) ;
return - 1 ;
}
static int
F_11 ( struct V_25 * V_26 ,
void * V_27 , int V_17 , T_3 V_18 , T_3 V_28 ,
T_3 * V_19 , T_3 * V_20 )
{
if ( ! V_26 -> V_29 ) {
* V_19 = V_28 ;
* V_20 = V_18 ;
return 0 ;
}
return F_6 ( V_27 , V_17 , V_18 , V_19 , V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_30 )
{
struct V_31 * V_32 = & V_2 -> V_26 -> V_33 [ V_30 ] ;
T_3 V_18 = F_13 ( V_32 ) ;
T_3 V_28 = V_32 -> V_34 ;
T_3 V_20 = V_18 , V_19 = V_28 ;
unsigned char * V_27 = V_32 -> V_35 + V_36 ;
unsigned long V_4 ;
void * V_16 ;
int V_37 = 0 ;
if ( F_11 ( V_2 -> V_26 , V_27 , V_32 -> V_17 , V_18 ,
V_28 , & V_19 , & V_20 ) )
return - 1 ;
if ( V_19 == V_20 )
return 0 ;
V_2 -> V_38 ++ ;
V_4 = V_20 - V_19 ;
if ( V_4 > ( unsigned long ) ( V_32 -> V_17 ) + 1 ) {
F_10 ( 1 , L_8 ) ;
V_32 -> V_34 = V_18 ;
F_14 ( V_2 -> V_26 , V_30 ) ;
return 0 ;
}
if ( ( V_19 & V_32 -> V_17 ) + V_4 != ( V_20 & V_32 -> V_17 ) ) {
V_16 = & V_27 [ V_19 & V_32 -> V_17 ] ;
V_4 = V_32 -> V_17 + 1 - ( V_19 & V_32 -> V_17 ) ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_16 , V_4 ) < 0 ) {
V_37 = - 1 ;
goto V_39;
}
}
V_16 = & V_27 [ V_19 & V_32 -> V_17 ] ;
V_4 = V_20 - V_19 ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_16 , V_4 ) < 0 ) {
V_37 = - 1 ;
goto V_39;
}
V_32 -> V_34 = V_18 ;
F_14 ( V_2 -> V_26 , V_30 ) ;
V_39:
return V_37 ;
}
static void F_15 ( int V_40 )
{
if ( V_40 == V_41 )
V_42 = 1 ;
else
V_43 = V_40 ;
V_44 = 1 ;
}
static void F_16 ( void )
{
if ( V_43 == - 1 )
return;
signal ( V_43 , V_45 ) ;
raise ( V_43 ) ;
}
static int F_17 ( struct V_8 * V_9 ,
union V_10 * V_11 , void * V_46 ,
T_1 V_47 , void * V_48 , T_1 V_49 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_50 * V_6 = & V_2 -> V_6 ;
T_1 V_51 ;
T_4 V_52 [ 8 ] = { 0 } ;
if ( ! F_18 ( V_6 ) ) {
T_5 V_53 ;
int V_54 = F_19 ( V_6 ) ;
int V_55 ;
V_53 = F_20 ( V_54 , 0 , V_56 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_55 = F_21 ( & V_2 -> V_5 -> V_57 ,
V_11 , V_53 ) ;
if ( V_55 )
return V_55 ;
}
V_51 = ( V_47 + V_49 ) & 7 ;
if ( V_51 )
V_51 = 8 - V_51 ;
F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
F_1 ( V_2 , V_46 , V_47 ) ;
if ( V_49 )
F_1 ( V_2 , V_48 , V_49 ) ;
F_1 ( V_2 , & V_52 , V_51 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
int V_60 ;
V_60 = F_23 ( V_59 , V_2 -> V_61 , & V_2 -> V_9 ,
F_17 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_60 )
V_2 -> V_38 ++ ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
int V_60 ;
V_60 = F_25 ( V_59 , V_2 -> V_61 , & V_2 -> V_9 ,
F_17 ,
V_2 -> V_62 . V_63 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_60 )
V_2 -> V_38 ++ ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_64 ;
int V_37 = 0 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_26 -> V_65 ; V_64 ++ ) {
struct V_58 * V_59 =
& V_2 -> V_26 -> V_33 [ V_64 ] . V_58 ;
if ( ! V_59 -> V_35 )
continue;
if ( F_24 ( V_2 , V_59 ) != 0 ) {
V_37 = - 1 ;
goto V_39;
}
}
V_39:
return V_37 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_8 ( L_9 ) ;
if ( F_26 ( V_2 ) < 0 ) {
F_28 ( & V_66 ) ;
} else {
if ( F_29 ( V_2 -> V_61 ) )
F_28 ( & V_66 ) ;
else
F_30 ( & V_66 ) ;
}
}
static inline
int F_22 ( struct V_1 * V_2 V_13 ,
struct V_58 * V_59 V_13 )
{
return 0 ;
}
static inline
void F_27 ( struct V_1 * V_2 V_13 )
{
}
static inline
int F_31 ( struct V_67 * V_61 V_13 )
{
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
char V_68 [ 512 ] ;
struct V_69 * V_70 ;
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_71 * V_5 = V_2 -> V_5 ;
struct V_72 * V_62 = & V_2 -> V_62 ;
int V_37 = 0 ;
F_33 ( V_26 , V_62 , & V_73 ) ;
F_34 (evlist, pos) {
V_74:
if ( F_35 ( V_70 , V_70 -> V_75 , V_70 -> V_76 ) < 0 ) {
if ( F_36 ( V_70 , V_77 , V_68 , sizeof( V_68 ) ) ) {
if ( V_78 )
F_37 ( L_10 , V_68 ) ;
goto V_74;
}
V_37 = - V_77 ;
F_38 ( V_70 , & V_62 -> V_79 ,
V_77 , V_68 , sizeof( V_68 ) ) ;
F_39 ( L_10 , V_68 ) ;
goto V_39;
}
}
if ( F_40 ( V_26 , & V_70 ) ) {
error ( L_11 ,
V_70 -> V_80 , F_41 ( V_70 ) , V_77 ,
F_42 ( V_77 , V_68 , sizeof( V_68 ) ) ) ;
V_37 = - 1 ;
goto V_39;
}
if ( F_43 ( V_26 , V_62 -> V_81 , false ,
V_62 -> V_82 ,
V_62 -> V_83 ) < 0 ) {
if ( V_77 == V_84 ) {
F_3 ( L_12
L_13
L_14
L_15
L_16 ,
V_62 -> V_81 , V_62 -> V_82 ) ;
V_37 = - V_77 ;
} else {
F_3 ( L_17 , V_77 ,
F_42 ( V_77 , V_68 , sizeof( V_68 ) ) ) ;
if ( V_77 )
V_37 = - V_77 ;
else
V_37 = - V_85 ;
}
goto V_39;
}
V_5 -> V_26 = V_26 ;
F_44 ( V_5 ) ;
V_39:
return V_37 ;
}
static int F_45 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_69 * V_86 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_38 ++ ;
return F_46 ( V_9 , V_11 , T_2 , V_86 , V_14 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_50 * V_6 = & V_2 -> V_6 ;
struct V_71 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_87 . V_88 = true ;
if ( V_2 -> V_89 )
V_2 -> V_9 . T_2 = NULL ;
return F_48 ( V_5 ) ;
}
static void F_49 ( struct V_14 * V_14 , void * V_27 )
{
int V_55 ;
struct V_8 * V_9 = V_27 ;
V_55 = F_50 ( V_9 , F_4 ,
V_14 ) ;
if ( V_55 < 0 )
F_3 ( L_18
L_19 , V_14 -> V_90 ) ;
V_55 = F_51 ( V_9 , F_4 ,
V_14 ) ;
if ( V_55 < 0 )
F_3 ( L_18
L_19 , V_14 -> V_90 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_64 ;
int V_37 = 0 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_26 -> V_65 ; V_64 ++ ) {
struct V_58 * V_59 = & V_2 -> V_26 -> V_33 [ V_64 ] . V_58 ;
if ( V_2 -> V_26 -> V_33 [ V_64 ] . V_35 ) {
if ( F_12 ( V_2 , V_64 ) != 0 ) {
V_37 = - 1 ;
goto V_39;
}
}
if ( V_59 -> V_35 && ! V_2 -> V_62 . V_83 &&
F_22 ( V_2 , V_59 ) != 0 ) {
V_37 = - 1 ;
goto V_39;
}
}
if ( V_7 != V_2 -> V_7 )
V_37 = F_1 ( V_2 , & V_91 , sizeof( V_91 ) ) ;
V_39:
return V_37 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_71 * V_5 = V_2 -> V_5 ;
int V_92 ;
for ( V_92 = V_93 ; V_92 < V_94 ; V_92 ++ )
F_54 ( & V_5 -> V_15 , V_92 ) ;
if ( V_2 -> V_95 )
F_55 ( & V_5 -> V_15 , V_96 ) ;
if ( ! F_56 ( & V_2 -> V_26 -> V_97 ) )
F_55 ( & V_5 -> V_15 , V_98 ) ;
if ( ! V_2 -> V_62 . V_99 )
F_55 ( & V_5 -> V_15 , V_100 ) ;
if ( ! V_2 -> V_62 . V_101 )
F_55 ( & V_5 -> V_15 , V_102 ) ;
F_55 ( & V_5 -> V_15 , V_103 ) ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_50 * V_6 = & V_2 -> V_6 ;
int V_54 = F_19 ( V_6 ) ;
if ( V_6 -> V_104 )
return;
V_2 -> V_5 -> V_15 . V_105 += V_2 -> V_7 ;
V_6 -> V_4 = F_20 ( F_19 ( V_6 ) , 0 , V_56 ) ;
if ( ! V_2 -> V_95 ) {
F_47 ( V_2 ) ;
if ( V_2 -> V_89 )
F_58 ( V_2 -> V_5 ) ;
}
F_59 ( V_2 -> V_5 , V_2 -> V_26 , V_54 , true ) ;
return;
}
static int F_60 ( struct V_1 * V_2 )
{
struct {
struct V_106 V_107 ;
struct V_108 V_109 ;
} V_106 ;
V_106 . V_107 . V_110 = 1 ;
V_106 . V_107 . V_107 [ 0 ] . V_90 = V_2 -> V_26 -> V_111 . V_90 ;
V_106 . V_107 . V_107 [ 0 ] . V_112 = NULL ;
return F_61 ( & V_2 -> V_9 , & V_106 . V_107 ,
F_4 ,
& V_2 -> V_5 -> V_113 . V_114 ,
V_2 -> V_62 . V_115 ,
V_2 -> V_62 . V_116 ) ;
}
static int
F_62 ( struct V_1 * V_2 , bool V_117 )
{
struct V_50 * V_6 = & V_2 -> V_6 ;
int V_54 , V_55 ;
char V_118 [] = L_20 ;
V_2 -> V_38 = 0 ;
F_57 ( V_2 ) ;
V_55 = F_63 ( V_118 , sizeof( V_118 ) ) ;
if ( V_55 ) {
F_3 ( L_21 ) ;
return - V_85 ;
}
V_54 = F_64 ( V_6 , V_118 ,
V_2 -> V_5 -> V_15 . V_119 ,
V_117 ) ;
if ( V_54 >= 0 && ! V_117 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_5 -> V_15 . V_105 = 0 ;
}
if ( ! V_120 )
fprintf ( V_121 , L_22 ,
V_6 -> V_122 , V_118 ) ;
if ( ! V_117 ) {
F_65 ( V_2 ) ;
if ( F_66 ( & V_2 -> V_62 . V_79 ) )
F_60 ( V_2 ) ;
}
return V_54 ;
}
static void F_67 ( int T_6 V_13 ,
T_7 * V_123 ,
void * T_8 V_13 )
{
V_124 = V_123 -> V_125 . V_126 ;
V_44 = 1 ;
V_42 = 1 ;
}
int __weak
F_68 ( const struct V_127 * T_9 V_13 ,
struct V_8 * V_9 V_13 ,
T_10 T_11 V_13 ,
struct V_14 * V_14 V_13 )
{
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_71 * V_5 = V_2 -> V_5 ;
struct V_14 * V_14 = & V_5 -> V_113 . V_114 ;
struct V_50 * V_6 = & V_2 -> V_6 ;
struct V_72 * V_62 = & V_2 -> V_62 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_54 = F_19 ( V_6 ) ;
int V_55 = 0 ;
if ( V_6 -> V_104 ) {
V_55 = F_69 ( V_9 , V_5 ,
F_4 ) ;
if ( V_55 < 0 ) {
F_3 ( L_23 ) ;
goto V_39;
}
if ( F_56 ( & V_2 -> V_26 -> V_97 ) ) {
V_55 = F_70 ( V_9 , V_54 , V_2 -> V_26 ,
F_4 ) ;
if ( V_55 <= 0 ) {
F_3 ( L_24 ) ;
goto V_39;
}
V_2 -> V_7 += V_55 ;
}
}
V_55 = F_68 ( V_2 -> V_26 -> V_33 [ 0 ] . V_35 , V_9 ,
F_4 , V_14 ) ;
if ( V_55 )
goto V_39;
if ( V_2 -> V_62 . V_101 ) {
V_55 = F_71 ( V_2 -> V_61 , V_9 ,
V_5 , F_4 ) ;
if ( V_55 )
goto V_39;
}
V_55 = F_51 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_55 < 0 , L_25
L_26
L_27 ) ;
V_55 = F_50 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_55 < 0 , L_28
L_26
L_29 ) ;
if ( V_128 ) {
F_72 ( & V_5 -> V_113 ,
F_49 , V_9 ) ;
}
V_55 = F_73 ( V_14 , V_9 , & V_62 -> V_79 , V_2 -> V_26 -> V_76 ,
F_4 , V_62 -> V_115 ,
V_62 -> V_116 ) ;
V_39:
return V_55 ;
}
static int F_74 ( struct V_1 * V_2 , int V_129 , const char * * V_130 )
{
int V_55 ;
int V_131 = 0 ;
unsigned long V_132 = 0 ;
const bool V_133 = V_129 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_72 * V_62 = & V_2 -> V_62 ;
struct V_50 * V_6 = & V_2 -> V_6 ;
struct V_71 * V_5 ;
bool V_134 = false , V_135 = false ;
int V_54 ;
V_2 -> V_136 = V_130 [ 0 ] ;
atexit ( F_16 ) ;
signal ( V_41 , F_15 ) ;
signal ( V_137 , F_15 ) ;
signal ( V_138 , F_15 ) ;
if ( V_2 -> V_62 . V_83 || V_2 -> V_139 ) {
signal ( V_140 , V_141 ) ;
if ( V_2 -> V_62 . V_83 )
F_75 ( & V_66 ) ;
if ( V_2 -> V_139 )
F_75 ( & V_142 ) ;
} else {
signal ( V_140 , V_143 ) ;
}
V_5 = F_76 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_30 ) ;
return - 1 ;
}
V_54 = F_19 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_53 ( V_2 ) ;
if ( V_133 ) {
V_55 = F_77 ( V_2 -> V_26 , & V_62 -> V_79 ,
V_130 , V_6 -> V_104 ,
F_67 ) ;
if ( V_55 < 0 ) {
F_3 ( L_31 ) ;
V_131 = V_55 ;
goto V_144;
}
}
if ( F_32 ( V_2 ) != 0 ) {
V_55 = - 1 ;
goto V_145;
}
V_55 = F_78 () ;
if ( V_55 ) {
char V_146 [ V_147 ] ;
F_79 ( V_55 , V_146 , sizeof( V_146 ) ) ;
F_3 ( L_32 ,
V_146 ) ;
goto V_145;
}
if ( V_2 -> V_9 . V_148 && ! F_80 ( V_2 -> V_26 ) ) {
F_81 ( L_33 ) ;
V_2 -> V_9 . V_148 = false ;
}
if ( ! V_2 -> V_26 -> V_149 )
F_55 ( & V_5 -> V_15 , V_150 ) ;
if ( V_6 -> V_104 ) {
V_55 = F_82 ( V_54 ) ;
if ( V_55 < 0 )
goto V_145;
} else {
V_55 = F_59 ( V_5 , V_2 -> V_26 , V_54 , false ) ;
if ( V_55 < 0 )
goto V_145;
}
if ( ! V_2 -> V_95
&& ! F_83 ( & V_5 -> V_15 , V_96 ) ) {
F_3 ( L_34
L_35 ) ;
V_55 = - 1 ;
goto V_145;
}
V_14 = & V_5 -> V_113 . V_114 ;
V_55 = F_65 ( V_2 ) ;
if ( V_55 < 0 )
goto V_145;
if ( V_2 -> V_151 ) {
struct V_152 V_153 ;
V_153 . V_154 = V_2 -> V_151 ;
if ( F_84 ( 0 , V_155 , & V_153 ) ) {
F_3 ( L_36 ) ;
V_55 = - 1 ;
goto V_145;
}
}
if ( ! F_66 ( & V_62 -> V_79 ) && ! V_62 -> V_156 )
F_85 ( V_2 -> V_26 ) ;
if ( V_133 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_112 ) + V_14 -> V_157 ) ;
if ( V_11 == NULL ) {
V_55 = - V_158 ;
goto V_145;
}
F_86 ( V_9 , V_11 ,
V_2 -> V_26 -> V_111 . V_90 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_87 ( V_2 -> V_26 ) ;
}
if ( V_62 -> V_156 ) {
F_88 ( V_62 -> V_156 * 1000 ) ;
F_85 ( V_2 -> V_26 ) ;
}
F_30 ( & V_66 ) ;
F_30 ( & V_142 ) ;
for (; ; ) {
unsigned long long V_159 = V_2 -> V_38 ;
if ( F_52 ( V_2 ) < 0 ) {
F_28 ( & V_66 ) ;
F_28 ( & V_142 ) ;
V_55 = - 1 ;
goto V_145;
}
if ( V_160 ) {
V_160 = 0 ;
if ( ! F_89 ( & V_66 ) )
F_27 ( V_2 ) ;
if ( F_89 ( & V_66 ) ) {
F_3 ( L_37 ) ;
V_55 = - 1 ;
goto V_145;
}
}
if ( F_90 ( & V_142 ) ) {
F_30 ( & V_142 ) ;
if ( ! V_120 )
fprintf ( V_121 , L_38 ,
V_132 ) ;
V_132 = 0 ;
V_54 = F_62 ( V_2 , false ) ;
if ( V_54 < 0 ) {
F_3 ( L_39 ) ;
F_28 ( & V_142 ) ;
V_55 = V_54 ;
goto V_145;
}
}
if ( V_159 == V_2 -> V_38 ) {
if ( V_44 || V_135 )
break;
V_55 = F_91 ( V_2 -> V_26 , - 1 ) ;
if ( V_55 > 0 || ( V_55 < 0 && V_77 == V_161 ) )
V_55 = 0 ;
V_132 ++ ;
if ( F_92 ( V_2 -> V_26 , V_162 | V_163 ) == 0 )
V_135 = true ;
}
if ( V_44 && ! V_134 && ! F_66 ( & V_62 -> V_79 ) ) {
F_93 ( & V_66 ) ;
F_94 ( V_2 -> V_26 ) ;
V_134 = true ;
}
}
F_93 ( & V_66 ) ;
F_93 ( & V_142 ) ;
if ( V_133 && V_124 ) {
char V_68 [ V_164 ] ;
const char * V_165 = F_42 ( V_124 , V_68 , sizeof( V_68 ) ) ;
F_3 ( L_40 , V_165 ) ;
V_55 = - 1 ;
goto V_145;
}
if ( ! V_120 )
fprintf ( V_121 , L_41 , V_132 ) ;
V_145:
if ( V_133 ) {
int V_166 ;
if ( ! V_42 )
F_95 ( V_2 -> V_26 -> V_111 . V_90 , V_138 ) ;
F_96 ( & V_166 ) ;
if ( V_55 < 0 )
V_131 = V_55 ;
else if ( F_97 ( V_166 ) )
V_131 = F_98 ( V_166 ) ;
else if ( F_99 ( V_166 ) )
V_43 = F_100 ( V_166 ) ;
} else
V_131 = V_55 ;
V_2 -> V_38 = 0 ;
if ( ! V_55 ) {
if ( ! V_2 -> V_167 ) {
F_57 ( V_2 ) ;
} else {
V_54 = F_62 ( V_2 , true ) ;
if ( V_54 < 0 ) {
V_131 = V_54 ;
goto V_144;
}
}
}
if ( ! V_55 && ! V_120 ) {
char V_38 [ 128 ] ;
const char * V_168 = V_2 -> V_167 ?
L_42 : L_43 ;
if ( V_2 -> V_38 && ! V_2 -> V_62 . V_101 )
F_101 ( V_38 , sizeof( V_38 ) ,
L_44 V_169 L_45 , V_2 -> V_38 ) ;
else
V_38 [ 0 ] = '\0' ;
fprintf ( V_121 , L_46 ,
F_102 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_122 , V_168 , V_38 ) ;
}
V_144:
F_103 ( V_5 ) ;
return V_131 ;
}
static void F_104 ( struct V_73 * V_170 )
{
static const char * V_171 [ V_172 ] = { L_47 , L_48 , L_49 , L_50 } ;
F_8 ( L_51 , V_171 [ V_170 -> V_173 ] ) ;
if ( V_170 -> V_173 == V_174 )
F_8 ( L_52 ,
V_170 -> V_175 ) ;
}
int F_105 ( struct V_72 * V_1 ,
struct V_73 * V_170 ,
const char * V_176 , bool V_177 )
{
int V_60 ;
V_170 -> V_178 = ! V_177 ;
if ( V_177 ) {
V_170 -> V_173 = V_179 ;
F_8 ( L_53 ) ;
return 0 ;
}
V_60 = F_106 ( V_176 , V_170 ) ;
if ( ! V_60 ) {
if ( V_170 -> V_173 == V_174 )
V_1 -> V_115 = true ;
F_104 ( V_170 ) ;
}
return V_60 ;
}
int F_107 ( const struct V_180 * V_181 ,
const char * V_176 ,
int V_177 )
{
return F_105 ( V_181 -> V_182 , & V_73 , V_176 , V_177 ) ;
}
int F_108 ( const struct V_180 * V_181 ,
const char * V_176 V_13 ,
int V_177 V_13 )
{
struct V_73 * V_170 = V_181 -> V_182 ;
V_170 -> V_178 = true ;
if ( V_170 -> V_173 == V_179 )
V_170 -> V_173 = V_183 ;
F_104 ( V_170 ) ;
return 0 ;
}
static int F_109 ( const char * V_184 , const char * V_182 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
if ( ! strcmp ( V_184 , L_54 ) ) {
if ( ! strcmp ( V_182 , L_55 ) )
V_2 -> V_186 = false ;
else if ( ! strcmp ( V_182 , L_56 ) )
V_2 -> V_186 = true ;
else if ( ! strcmp ( V_182 , L_57 ) )
V_2 -> V_95 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_184 , L_58 ) )
V_184 = L_59 ;
return F_110 ( V_184 , V_182 , V_185 ) ;
}
static int F_111 ( const struct V_180 * V_181 , const char * V_171 , int V_177 )
{
struct V_72 * V_62 = (struct V_72 * ) V_181 -> V_182 ;
const struct V_187 * V_188 ;
const char * V_189 = V_171 ;
if ( V_177 ) {
V_62 -> V_190 = 0 ;
return 0 ;
}
if ( ! V_171 )
return 0 ;
if ( V_62 -> V_190 )
return - 1 ;
V_62 -> V_190 = true ;
if ( sscanf ( V_171 , L_60 , & V_62 -> V_191 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_171 , L_61 , 6 ) )
V_171 += 6 ;
for ( V_188 = V_192 ; V_188 -> V_193 ; V_188 ++ ) {
if ( ! strcasecmp ( V_171 , V_188 -> V_193 ) ) {
V_62 -> V_191 = V_188 -> V_191 ;
return 0 ;
}
}
V_62 -> V_190 = false ;
F_37 ( L_62 , V_189 ) ;
return - 1 ;
}
static int F_112 ( const struct V_180 * V_181 ,
const char * V_171 ,
int V_177 V_13 )
{
struct V_72 * V_62 = V_181 -> V_182 ;
char * V_194 , * V_195 ;
unsigned int V_81 ;
int V_60 ;
if ( ! V_171 )
return - V_85 ;
V_194 = F_113 ( V_171 ) ;
if ( ! V_194 )
return - V_158 ;
V_195 = strchr ( V_194 , ',' ) ;
if ( V_195 )
* V_195 = '\0' ;
if ( * V_194 ) {
V_60 = F_114 ( & V_81 , V_194 ) ;
if ( V_60 )
goto V_196;
V_62 -> V_81 = V_81 ;
}
if ( ! V_195 ) {
V_60 = 0 ;
goto V_196;
}
V_60 = F_114 ( & V_81 , V_195 + 1 ) ;
if ( V_60 )
goto V_196;
V_62 -> V_82 = V_81 ;
V_196:
free ( V_194 ) ;
return V_60 ;
}
int F_115 ( int V_129 , const char * * V_130 , const char * T_12 V_13 )
{
int V_55 ;
struct V_1 * V_2 = & V_1 ;
char V_146 [ V_147 ] ;
#ifndef F_116
# define F_117 ( V_194 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_117 ( '\0' , L_63 , true ) ;
F_117 ( '\0' , L_64 , true ) ;
# undef F_117
#endif
#ifndef F_118
# if ! F_119 ( V_197 )
# define F_120 "NO_DWARF=1"
# elif ! F_119 ( F_116 )
# define F_120 "NO_LIBBPF=1"
# else
# define F_120 "this architecture doesn't support BPF prologue"
# endif
# define F_117 ( V_194 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_117 ( '\0' , L_65 , true ) ;
# undef F_117
# undef F_120
#endif
V_2 -> V_26 = F_121 () ;
if ( V_2 -> V_26 == NULL )
return - V_158 ;
F_122 ( F_109 , V_2 ) ;
V_129 = F_123 ( V_129 , V_130 , V_198 , V_199 ,
V_200 ) ;
if ( ! V_129 && F_66 ( & V_2 -> V_62 . V_79 ) )
F_124 ( V_199 , V_198 ) ;
if ( V_201 && ! V_2 -> V_62 . V_79 . V_202 ) {
F_125 ( V_199 , V_198 ,
L_66 ) ;
}
if ( V_2 -> V_62 . V_203 &&
! F_126 () ) {
F_39 ( L_67 ) ;
F_127 ( V_199 , V_198 , L_68 , 0 ) ;
return - V_85 ;
}
if ( V_2 -> V_139 )
V_2 -> V_167 = true ;
if ( ! V_2 -> V_61 ) {
V_2 -> V_61 = F_128 ( V_2 -> V_26 , & V_55 ) ;
if ( V_55 )
return V_55 ;
}
V_55 = F_129 ( V_2 -> V_61 , & V_2 -> V_62 ,
V_2 -> V_62 . V_204 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_130 ( V_2 -> V_26 ) ;
if ( V_55 ) {
F_131 ( V_2 -> V_26 , V_55 , V_146 , sizeof( V_146 ) ) ;
F_3 ( L_69 ,
V_146 ) ;
return V_55 ;
}
V_55 = - V_158 ;
F_132 ( NULL ) ;
if ( V_87 . V_205 )
F_81 (
L_70
L_71
L_72
L_73
L_74
L_75
L_76 ) ;
if ( V_2 -> V_186 || V_2 -> V_95 ) {
F_133 () ;
} else if ( V_2 -> V_139 ) {
bool V_206 = true ;
if ( V_2 -> V_207 && ! V_2 -> V_95 )
V_206 = false ;
if ( V_2 -> V_208 && ! V_2 -> V_186 )
V_206 = false ;
if ( V_206 ) {
V_2 -> V_95 = true ;
V_2 -> V_186 = true ;
F_133 () ;
}
}
if ( V_2 -> V_26 -> V_209 == 0 &&
F_134 ( V_2 -> V_26 ) < 0 ) {
F_3 ( L_77 ) ;
goto V_210;
}
if ( V_2 -> V_62 . V_79 . V_211 && ! V_2 -> V_62 . V_212 )
V_2 -> V_62 . V_213 = true ;
V_55 = F_135 ( & V_2 -> V_62 . V_79 ) ;
if ( V_55 ) {
F_136 ( & V_2 -> V_62 . V_79 , V_55 , V_146 , V_147 ) ;
F_37 ( L_78 , V_146 ) ;
}
V_55 = F_137 ( & V_2 -> V_62 . V_79 ) ;
if ( V_55 ) {
int V_214 = V_77 ;
F_136 ( & V_2 -> V_62 . V_79 , V_55 , V_146 , V_147 ) ;
F_39 ( L_78 , V_146 ) ;
V_55 = - V_214 ;
goto V_210;
}
V_55 = - V_158 ;
if ( F_138 ( V_2 -> V_26 , & V_2 -> V_62 . V_79 ) < 0 )
F_124 ( V_199 , V_198 ) ;
V_55 = F_139 ( V_2 -> V_61 , V_2 -> V_26 , & V_2 -> V_62 ) ;
if ( V_55 )
goto V_210;
if ( V_2 -> V_62 . V_101 )
V_2 -> V_89 = true ;
if ( F_140 ( & V_2 -> V_62 ) ) {
V_55 = - V_85 ;
goto V_210;
}
V_55 = F_74 ( & V_1 , V_129 , V_130 ) ;
V_210:
F_141 ( V_2 -> V_26 ) ;
F_142 () ;
F_143 ( V_2 -> V_61 ) ;
return V_55 ;
}
static void V_141 ( int V_40 V_13 )
{
if ( F_144 ( & V_66 ) ) {
F_145 ( & V_66 ) ;
V_160 = 1 ;
if ( F_31 ( V_1 . V_61 ) )
F_28 ( & V_66 ) ;
}
if ( F_144 ( & V_142 ) )
F_145 ( & V_142 ) ;
}
