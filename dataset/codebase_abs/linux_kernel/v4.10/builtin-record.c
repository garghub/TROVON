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
F_11 ( void * V_25 , int V_17 , T_3 V_18 , T_3 V_26 ,
T_3 * V_19 , T_3 * V_20 , bool V_27 )
{
if ( ! V_27 ) {
* V_19 = V_26 ;
* V_20 = V_18 ;
return 0 ;
}
return F_6 ( V_25 , V_17 , V_18 , V_19 , V_20 ) ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_28 * V_29 ,
bool V_30 , bool V_27 )
{
T_3 V_18 = F_13 ( V_29 ) ;
T_3 V_26 = V_29 -> V_31 ;
T_3 V_20 = V_18 , V_19 = V_26 ;
unsigned char * V_25 = V_29 -> V_32 + V_33 ;
unsigned long V_4 ;
void * V_16 ;
int V_34 = 0 ;
if ( F_11 ( V_25 , V_29 -> V_17 , V_18 ,
V_26 , & V_19 , & V_20 , V_27 ) )
return - 1 ;
if ( V_19 == V_20 )
return 0 ;
V_2 -> V_35 ++ ;
V_4 = V_20 - V_19 ;
if ( V_4 > ( unsigned long ) ( V_29 -> V_17 ) + 1 ) {
F_10 ( 1 , L_8 ) ;
V_29 -> V_31 = V_18 ;
F_14 ( V_29 , V_30 || V_27 ) ;
return 0 ;
}
if ( ( V_19 & V_29 -> V_17 ) + V_4 != ( V_20 & V_29 -> V_17 ) ) {
V_16 = & V_25 [ V_19 & V_29 -> V_17 ] ;
V_4 = V_29 -> V_17 + 1 - ( V_19 & V_29 -> V_17 ) ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_16 , V_4 ) < 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
V_16 = & V_25 [ V_19 & V_29 -> V_17 ] ;
V_4 = V_20 - V_19 ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_16 , V_4 ) < 0 ) {
V_34 = - 1 ;
goto V_36;
}
V_29 -> V_31 = V_18 ;
F_14 ( V_29 , V_30 || V_27 ) ;
V_36:
return V_34 ;
}
static void F_15 ( int V_37 )
{
if ( V_37 == V_38 )
V_39 = 1 ;
else
V_40 = V_37 ;
V_41 = 1 ;
}
static void F_16 ( int V_37 )
{
F_17 () ;
F_18 ( V_37 ) ;
}
static void F_19 ( void )
{
if ( V_40 == - 1 )
return;
signal ( V_40 , V_42 ) ;
raise ( V_40 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
union V_10 * V_11 , void * V_43 ,
T_1 V_44 , void * V_45 , T_1 V_46 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_47 * V_6 = & V_2 -> V_6 ;
T_1 V_48 ;
T_4 V_49 [ 8 ] = { 0 } ;
if ( ! F_21 ( V_6 ) ) {
T_5 V_50 ;
int V_51 = F_22 ( V_6 ) ;
int V_52 ;
V_50 = F_23 ( V_51 , 0 , V_53 ) ;
if ( V_50 == - 1 )
return - 1 ;
V_52 = F_24 ( & V_2 -> V_5 -> V_54 ,
V_11 , V_50 ) ;
if ( V_52 )
return V_52 ;
}
V_48 = ( V_44 + V_46 ) & 7 ;
if ( V_48 )
V_48 = 8 - V_48 ;
F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
F_1 ( V_2 , V_43 , V_44 ) ;
if ( V_46 )
F_1 ( V_2 , V_45 , V_46 ) ;
F_1 ( V_2 , & V_49 , V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
int V_57 ;
V_57 = F_26 ( V_56 , V_2 -> V_58 , & V_2 -> V_9 ,
F_20 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
V_2 -> V_35 ++ ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
int V_57 ;
V_57 = F_28 ( V_56 , V_2 -> V_58 , & V_2 -> V_9 ,
F_20 ,
V_2 -> V_59 . V_60 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
V_2 -> V_35 ++ ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_61 ;
int V_34 = 0 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_62 -> V_63 ; V_61 ++ ) {
struct V_55 * V_56 =
& V_2 -> V_62 -> V_64 [ V_61 ] . V_55 ;
if ( ! V_56 -> V_32 )
continue;
if ( F_27 ( V_2 , V_56 ) != 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
V_36:
return V_34 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_8 ( L_9 ) ;
if ( F_29 ( V_2 ) < 0 ) {
F_31 ( & V_65 ) ;
} else {
if ( F_32 ( V_2 -> V_58 ) )
F_31 ( & V_65 ) ;
else
F_33 ( & V_65 ) ;
}
}
static inline
int F_25 ( struct V_1 * V_2 V_13 ,
struct V_55 * V_56 V_13 )
{
return 0 ;
}
static inline
void F_30 ( struct V_1 * V_2 V_13 )
{
}
static inline
int F_34 ( struct V_66 * V_58 V_13 )
{
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_67 * V_62 )
{
struct V_68 * V_59 = & V_2 -> V_59 ;
char V_69 [ 512 ] ;
if ( F_36 ( V_62 , V_59 -> V_70 , false ,
V_59 -> V_71 ,
V_59 -> V_72 ) < 0 ) {
if ( V_73 == V_74 ) {
F_3 ( L_10
L_11
L_12
L_13
L_14 ,
V_59 -> V_70 , V_59 -> V_71 ) ;
return - V_73 ;
} else {
F_3 ( L_15 , V_73 ,
F_37 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
if ( V_73 )
return - V_73 ;
else
return - V_75 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
return F_35 ( V_2 , V_2 -> V_62 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
char V_69 [ 512 ] ;
struct V_76 * V_77 ;
struct V_67 * V_62 = V_2 -> V_62 ;
struct V_78 * V_5 = V_2 -> V_5 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_79 * V_80 ;
int V_34 = 0 ;
F_40 ( V_62 , V_59 , & V_81 ) ;
F_41 (evlist, pos) {
V_82:
if ( F_42 ( V_77 , V_77 -> V_83 , V_77 -> V_84 ) < 0 ) {
if ( F_43 ( V_77 , V_73 , V_69 , sizeof( V_69 ) ) ) {
if ( V_85 )
F_44 ( L_16 , V_69 ) ;
goto V_82;
}
V_34 = - V_73 ;
F_45 ( V_77 , & V_59 -> V_86 ,
V_73 , V_69 , sizeof( V_69 ) ) ;
F_46 ( L_16 , V_69 ) ;
goto V_36;
}
}
if ( F_47 ( V_62 , & V_77 ) ) {
error ( L_17 ,
V_77 -> V_87 , F_48 ( V_77 ) , V_73 ,
F_37 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
V_34 = - 1 ;
goto V_36;
}
if ( F_49 ( V_62 , & V_77 , & V_80 ) ) {
error ( L_18 ,
V_80 -> V_88 . V_89 , F_48 ( V_77 ) , V_73 ,
F_37 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
V_34 = - 1 ;
goto V_36;
}
V_34 = F_38 ( V_2 ) ;
if ( V_34 )
goto V_36;
V_5 -> V_62 = V_62 ;
F_50 ( V_5 ) ;
V_36:
return V_34 ;
}
static int F_51 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_76 * V_90 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_35 ++ ;
return F_52 ( V_9 , V_11 , T_2 , V_90 , V_14 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_78 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_91 . V_92 = true ;
if ( V_2 -> V_93 )
V_2 -> V_9 . T_2 = NULL ;
return F_54 ( V_5 ) ;
}
static void F_55 ( struct V_14 * V_14 , void * V_25 )
{
int V_52 ;
struct V_8 * V_9 = V_25 ;
V_52 = F_56 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_19
L_20 , V_14 -> V_94 ) ;
V_52 = F_57 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_19
L_20 , V_14 -> V_94 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_67 * V_62 ,
bool V_27 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_61 ;
int V_34 = 0 ;
struct V_28 * V_95 ;
if ( ! V_62 )
return 0 ;
V_95 = V_27 ? V_62 -> V_96 : V_62 -> V_64 ;
if ( ! V_95 )
return 0 ;
if ( V_27 && V_62 -> V_97 != V_98 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_62 -> V_63 ; V_61 ++ ) {
struct V_55 * V_56 = & V_95 [ V_61 ] . V_55 ;
if ( V_95 [ V_61 ] . V_32 ) {
if ( F_12 ( V_2 , & V_95 [ V_61 ] ,
V_62 -> V_30 , V_27 ) != 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
if ( V_56 -> V_32 && ! V_2 -> V_59 . V_72 &&
F_25 ( V_2 , V_56 ) != 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
if ( V_7 != V_2 -> V_7 )
V_34 = F_1 ( V_2 , & V_99 , sizeof( V_99 ) ) ;
if ( V_27 )
F_59 ( V_62 , V_100 ) ;
V_36:
return V_34 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_58 ( V_2 , V_2 -> V_62 , false ) ;
if ( V_52 )
return V_52 ;
return F_58 ( V_2 , V_2 -> V_62 , true ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
int V_101 ;
for ( V_101 = V_102 ; V_101 < V_103 ; V_101 ++ )
F_62 ( & V_5 -> V_15 , V_101 ) ;
if ( V_2 -> V_104 )
F_63 ( & V_5 -> V_15 , V_105 ) ;
if ( ! F_64 ( & V_2 -> V_62 -> V_106 ) )
F_63 ( & V_5 -> V_15 , V_107 ) ;
if ( ! V_2 -> V_59 . V_108 )
F_63 ( & V_5 -> V_15 , V_109 ) ;
if ( ! V_2 -> V_59 . V_110 )
F_63 ( & V_5 -> V_15 , V_111 ) ;
F_63 ( & V_5 -> V_15 , V_112 ) ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 = F_22 ( V_6 ) ;
if ( V_6 -> V_113 )
return;
V_2 -> V_5 -> V_15 . V_114 += V_2 -> V_7 ;
V_6 -> V_4 = F_23 ( F_22 ( V_6 ) , 0 , V_53 ) ;
if ( ! V_2 -> V_104 ) {
F_53 ( V_2 ) ;
if ( V_2 -> V_93 )
F_66 ( V_2 -> V_5 ) ;
}
F_67 ( V_2 -> V_5 , V_2 -> V_62 , V_51 , true ) ;
return;
}
static int F_68 ( struct V_1 * V_2 , bool V_115 )
{
struct {
struct V_116 V_117 ;
struct V_118 V_119 ;
} V_116 ;
if ( V_2 -> V_59 . V_120 != V_115 )
return 0 ;
V_116 . V_117 . V_121 = 1 ;
V_116 . V_117 . V_117 [ 0 ] . V_94 = V_2 -> V_62 -> V_122 . V_94 ;
V_116 . V_117 . V_117 [ 0 ] . V_123 = NULL ;
return F_69 ( & V_2 -> V_9 , & V_116 . V_117 ,
F_4 ,
& V_2 -> V_5 -> V_124 . V_125 ,
V_2 -> V_59 . V_126 ,
V_2 -> V_59 . V_127 ) ;
}
static int
F_70 ( struct V_1 * V_2 , bool V_128 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 , V_52 ;
char V_129 [] = L_21 ;
F_71 ( V_2 , true ) ;
if ( F_72 ( & V_2 -> V_59 . V_86 ) )
F_68 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
F_65 ( V_2 ) ;
V_52 = F_73 ( V_129 , sizeof( V_129 ) ) ;
if ( V_52 ) {
F_3 ( L_22 ) ;
return - V_75 ;
}
V_51 = F_74 ( V_6 , V_129 ,
V_2 -> V_5 -> V_15 . V_130 ,
V_128 ) ;
if ( V_51 >= 0 && ! V_128 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_5 -> V_15 . V_114 = 0 ;
}
if ( ! V_131 )
fprintf ( V_132 , L_23 ,
V_6 -> V_133 , V_129 ) ;
if ( ! V_128 ) {
F_71 ( V_2 , false ) ;
if ( F_72 ( & V_2 -> V_59 . V_86 ) )
F_68 ( V_2 , false ) ;
}
return V_51 ;
}
static void F_75 ( int T_6 V_13 ,
T_7 * V_134 ,
void * T_8 V_13 )
{
V_135 = V_134 -> V_136 . V_137 ;
V_41 = 1 ;
V_39 = 1 ;
}
int __weak
F_76 ( const struct V_138 * T_9 V_13 ,
struct V_8 * V_9 V_13 ,
T_10 T_11 V_13 ,
struct V_14 * V_14 V_13 )
{
return 0 ;
}
static const struct V_138 *
F_77 ( struct V_67 * V_62 )
{
if ( V_62 ) {
if ( V_62 -> V_64 && V_62 -> V_64 [ 0 ] . V_32 )
return V_62 -> V_64 [ 0 ] . V_32 ;
if ( V_62 -> V_96 && V_62 -> V_96 [ 0 ] . V_32 )
return V_62 -> V_96 [ 0 ] . V_32 ;
}
return NULL ;
}
static const struct V_138 * F_78 ( struct V_1 * V_2 )
{
const struct V_138 * T_9 ;
T_9 = F_77 ( V_2 -> V_62 ) ;
if ( T_9 )
return T_9 ;
return NULL ;
}
static int F_71 ( struct V_1 * V_2 , bool V_115 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
struct V_14 * V_14 = & V_5 -> V_124 . V_125 ;
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_51 = F_22 ( V_6 ) ;
int V_52 = 0 ;
if ( V_2 -> V_59 . V_120 != V_115 )
return 0 ;
if ( V_6 -> V_113 ) {
V_52 = F_79 ( V_9 , V_5 ,
F_4 ) ;
if ( V_52 < 0 ) {
F_3 ( L_24 ) ;
goto V_36;
}
if ( F_64 ( & V_2 -> V_62 -> V_106 ) ) {
V_52 = F_80 ( V_9 , V_51 , V_2 -> V_62 ,
F_4 ) ;
if ( V_52 <= 0 ) {
F_3 ( L_25 ) ;
goto V_36;
}
V_2 -> V_7 += V_52 ;
}
}
V_52 = F_76 ( F_78 ( V_2 ) , V_9 ,
F_4 , V_14 ) ;
if ( V_52 )
goto V_36;
if ( V_2 -> V_59 . V_110 ) {
V_52 = F_81 ( V_2 -> V_58 , V_9 ,
V_5 , F_4 ) ;
if ( V_52 )
goto V_36;
}
V_52 = F_57 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_26
L_27
L_28 ) ;
V_52 = F_56 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_29
L_27
L_30 ) ;
if ( V_139 ) {
F_82 ( & V_5 -> V_124 ,
F_55 , V_9 ) ;
}
V_52 = F_83 ( V_14 , V_9 , & V_59 -> V_86 , V_2 -> V_62 -> V_84 ,
F_4 , V_59 -> V_126 ,
V_59 -> V_127 ) ;
V_36:
return V_52 ;
}
static int F_84 ( struct V_1 * V_2 , int V_140 , const char * * V_141 )
{
int V_52 ;
int V_142 = 0 ;
unsigned long V_143 = 0 ;
const bool V_144 = V_140 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_78 * V_5 ;
bool V_145 = false , V_146 = false ;
int V_51 ;
V_2 -> V_147 = V_141 [ 0 ] ;
atexit ( F_19 ) ;
signal ( V_38 , F_15 ) ;
signal ( V_148 , F_15 ) ;
signal ( V_149 , F_15 ) ;
signal ( V_150 , F_16 ) ;
if ( V_2 -> V_59 . V_72 || V_2 -> V_151 ) {
signal ( V_152 , V_153 ) ;
if ( V_2 -> V_59 . V_72 )
F_85 ( & V_65 ) ;
if ( V_2 -> V_151 )
F_85 ( & V_154 ) ;
} else {
signal ( V_152 , V_155 ) ;
}
V_5 = F_86 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_31 ) ;
return - 1 ;
}
V_51 = F_22 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_61 ( V_2 ) ;
if ( V_144 ) {
V_52 = F_87 ( V_2 -> V_62 , & V_59 -> V_86 ,
V_141 , V_6 -> V_113 ,
F_75 ) ;
if ( V_52 < 0 ) {
F_3 ( L_32 ) ;
V_142 = V_52 ;
goto V_156;
}
}
if ( F_39 ( V_2 ) != 0 ) {
V_52 = - 1 ;
goto V_157;
}
V_52 = F_88 () ;
if ( V_52 ) {
char V_158 [ V_159 ] ;
F_89 ( V_52 , V_158 , sizeof( V_158 ) ) ;
F_3 ( L_33 ,
V_158 ) ;
goto V_157;
}
if ( V_2 -> V_9 . V_160 && ! F_90 ( V_2 -> V_62 ) ) {
F_91 ( L_34 ) ;
V_2 -> V_9 . V_160 = false ;
}
if ( ! V_2 -> V_62 -> V_161 )
F_63 ( & V_5 -> V_15 , V_162 ) ;
if ( V_6 -> V_113 ) {
V_52 = F_92 ( V_51 ) ;
if ( V_52 < 0 )
goto V_157;
} else {
V_52 = F_67 ( V_5 , V_2 -> V_62 , V_51 , false ) ;
if ( V_52 < 0 )
goto V_157;
}
if ( ! V_2 -> V_104
&& ! F_93 ( & V_5 -> V_15 , V_105 ) ) {
F_3 ( L_35
L_36 ) ;
V_52 = - 1 ;
goto V_157;
}
V_14 = & V_5 -> V_124 . V_125 ;
V_52 = F_71 ( V_2 , false ) ;
if ( V_52 < 0 )
goto V_157;
if ( V_2 -> V_163 ) {
struct V_164 V_165 ;
V_165 . V_166 = V_2 -> V_163 ;
if ( F_94 ( 0 , V_167 , & V_165 ) ) {
F_3 ( L_37 ) ;
V_52 = - 1 ;
goto V_157;
}
}
if ( ! F_72 ( & V_59 -> V_86 ) && ! V_59 -> V_168 )
F_95 ( V_2 -> V_62 ) ;
if ( V_144 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_123 ) + V_14 -> V_169 ) ;
if ( V_11 == NULL ) {
V_52 = - V_170 ;
goto V_157;
}
F_96 ( V_9 , V_11 ,
V_2 -> V_62 -> V_122 . V_94 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_97 ( V_2 -> V_62 ) ;
}
if ( V_59 -> V_168 ) {
F_98 ( V_59 -> V_168 * V_171 ) ;
F_95 ( V_2 -> V_62 ) ;
}
F_33 ( & V_65 ) ;
F_33 ( & V_154 ) ;
F_99 () ;
for (; ; ) {
unsigned long long V_172 = V_2 -> V_35 ;
if ( F_100 ( & V_154 ) || V_41 || V_146 )
F_59 ( V_2 -> V_62 , V_98 ) ;
if ( F_60 ( V_2 ) < 0 ) {
F_31 ( & V_65 ) ;
F_31 ( & V_154 ) ;
V_52 = - 1 ;
goto V_157;
}
if ( V_173 ) {
V_173 = 0 ;
if ( ! F_101 ( & V_65 ) )
F_30 ( V_2 ) ;
if ( F_101 ( & V_65 ) ) {
F_3 ( L_38 ) ;
V_52 = - 1 ;
goto V_157;
}
}
if ( F_100 ( & V_154 ) ) {
if ( V_2 -> V_62 -> V_97 == V_174 )
continue;
F_33 ( & V_154 ) ;
F_59 ( V_2 -> V_62 , V_174 ) ;
if ( ! V_131 )
fprintf ( V_132 , L_39 ,
V_143 ) ;
V_143 = 0 ;
V_51 = F_70 ( V_2 , false ) ;
if ( V_51 < 0 ) {
F_3 ( L_40 ) ;
F_31 ( & V_154 ) ;
V_52 = V_51 ;
goto V_157;
}
}
if ( V_172 == V_2 -> V_35 ) {
if ( V_41 || V_146 )
break;
V_52 = F_102 ( V_2 -> V_62 , - 1 ) ;
if ( V_52 > 0 || ( V_52 < 0 && V_73 == V_175 ) )
V_52 = 0 ;
V_143 ++ ;
if ( F_103 ( V_2 -> V_62 , V_176 | V_177 ) == 0 )
V_146 = true ;
}
if ( V_41 && ! V_145 && ! F_72 ( & V_59 -> V_86 ) ) {
F_104 ( & V_65 ) ;
F_105 ( V_2 -> V_62 ) ;
V_145 = true ;
}
}
F_104 ( & V_65 ) ;
F_104 ( & V_154 ) ;
if ( V_144 && V_135 ) {
char V_69 [ V_178 ] ;
const char * V_179 = F_37 ( V_135 , V_69 , sizeof( V_69 ) ) ;
F_3 ( L_41 , V_179 ) ;
V_52 = - 1 ;
goto V_157;
}
if ( ! V_131 )
fprintf ( V_132 , L_42 , V_143 ) ;
if ( F_72 ( & V_2 -> V_59 . V_86 ) )
F_68 ( V_2 , true ) ;
V_157:
if ( V_144 ) {
int V_180 ;
if ( ! V_39 )
F_106 ( V_2 -> V_62 -> V_122 . V_94 , V_149 ) ;
F_107 ( & V_180 ) ;
if ( V_52 < 0 )
V_142 = V_52 ;
else if ( F_108 ( V_180 ) )
V_142 = F_109 ( V_180 ) ;
else if ( F_110 ( V_180 ) )
V_40 = F_111 ( V_180 ) ;
} else
V_142 = V_52 ;
F_71 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
if ( ! V_52 ) {
if ( ! V_2 -> V_181 ) {
F_65 ( V_2 ) ;
} else {
V_51 = F_70 ( V_2 , true ) ;
if ( V_51 < 0 ) {
V_142 = V_51 ;
goto V_156;
}
}
}
F_112 () ;
if ( ! V_52 && ! V_131 ) {
char V_35 [ 128 ] ;
const char * V_182 = V_2 -> V_181 ?
L_43 : L_44 ;
if ( V_2 -> V_35 && ! V_2 -> V_59 . V_110 )
F_113 ( V_35 , sizeof( V_35 ) ,
L_45 V_183 L_46 , V_2 -> V_35 ) ;
else
V_35 [ 0 ] = '\0' ;
fprintf ( V_132 , L_47 ,
F_114 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_133 , V_182 , V_35 ) ;
}
V_156:
F_115 ( V_5 ) ;
return V_142 ;
}
static void F_116 ( struct V_81 * V_184 )
{
static const char * V_185 [ V_186 ] = { L_48 , L_49 , L_50 , L_51 } ;
F_8 ( L_52 , V_185 [ V_184 -> V_187 ] ) ;
if ( V_184 -> V_187 == V_188 )
F_8 ( L_53 ,
V_184 -> V_189 ) ;
}
int F_117 ( struct V_68 * V_1 ,
struct V_81 * V_184 ,
const char * V_190 , bool V_191 )
{
int V_57 ;
V_184 -> V_192 = ! V_191 ;
if ( V_191 ) {
V_184 -> V_187 = V_193 ;
F_8 ( L_54 ) ;
return 0 ;
}
V_57 = F_118 ( V_190 , V_184 ) ;
if ( ! V_57 ) {
if ( V_184 -> V_187 == V_188 )
V_1 -> V_126 = true ;
F_116 ( V_184 ) ;
}
return V_57 ;
}
int F_119 ( const struct V_194 * V_195 ,
const char * V_190 ,
int V_191 )
{
return F_117 ( V_195 -> V_196 , & V_81 , V_190 , V_191 ) ;
}
int F_120 ( const struct V_194 * V_195 ,
const char * V_190 V_13 ,
int V_191 V_13 )
{
struct V_81 * V_184 = V_195 -> V_196 ;
V_184 -> V_192 = true ;
if ( V_184 -> V_187 == V_193 )
V_184 -> V_187 = V_197 ;
F_116 ( V_184 ) ;
return 0 ;
}
static int F_121 ( const char * V_198 , const char * V_196 , void * V_199 )
{
struct V_1 * V_2 = V_199 ;
if ( ! strcmp ( V_198 , L_55 ) ) {
if ( ! strcmp ( V_196 , L_56 ) )
V_2 -> V_200 = false ;
else if ( ! strcmp ( V_196 , L_57 ) )
V_2 -> V_200 = true ;
else if ( ! strcmp ( V_196 , L_58 ) )
V_2 -> V_104 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_198 , L_59 ) )
V_198 = L_60 ;
return F_122 ( V_198 , V_196 , V_199 ) ;
}
static int F_123 ( const struct V_194 * V_195 , const char * V_185 , int V_191 )
{
struct V_68 * V_59 = (struct V_68 * ) V_195 -> V_196 ;
const struct V_201 * V_202 ;
const char * V_203 = V_185 ;
if ( V_191 ) {
V_59 -> V_204 = 0 ;
return 0 ;
}
if ( ! V_185 )
return 0 ;
if ( V_59 -> V_204 )
return - 1 ;
V_59 -> V_204 = true ;
if ( sscanf ( V_185 , L_61 , & V_59 -> V_205 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_185 , L_62 , 6 ) )
V_185 += 6 ;
for ( V_202 = V_206 ; V_202 -> V_207 ; V_202 ++ ) {
if ( ! strcasecmp ( V_185 , V_202 -> V_207 ) ) {
V_59 -> V_205 = V_202 -> V_205 ;
return 0 ;
}
}
V_59 -> V_204 = false ;
F_44 ( L_63 , V_203 ) ;
return - 1 ;
}
static int F_124 ( const struct V_194 * V_195 ,
const char * V_185 ,
int V_191 V_13 )
{
struct V_68 * V_59 = V_195 -> V_196 ;
char * V_208 , * V_209 ;
unsigned int V_70 ;
int V_57 ;
if ( ! V_185 )
return - V_75 ;
V_208 = F_125 ( V_185 ) ;
if ( ! V_208 )
return - V_170 ;
V_209 = strchr ( V_208 , ',' ) ;
if ( V_209 )
* V_209 = '\0' ;
if ( * V_208 ) {
V_57 = F_126 ( & V_70 , V_208 ) ;
if ( V_57 )
goto V_210;
V_59 -> V_70 = V_70 ;
}
if ( ! V_209 ) {
V_57 = 0 ;
goto V_210;
}
V_57 = F_126 ( & V_70 , V_209 + 1 ) ;
if ( V_57 )
goto V_210;
V_59 -> V_71 = V_70 ;
V_210:
free ( V_208 ) ;
return V_57 ;
}
int F_127 ( int V_140 , const char * * V_141 , const char * T_12 V_13 )
{
int V_52 ;
struct V_1 * V_2 = & V_1 ;
char V_158 [ V_159 ] ;
#ifndef F_128
# define F_129 ( V_208 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_129 ( '\0' , L_64 , true ) ;
F_129 ( '\0' , L_65 , true ) ;
# undef F_129
#endif
#ifndef F_130
# if ! F_131 ( V_211 )
# define F_132 "NO_DWARF=1"
# elif ! F_131 ( F_128 )
# define F_132 "NO_LIBBPF=1"
# else
# define F_132 "this architecture doesn't support BPF prologue"
# endif
# define F_129 ( V_208 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_129 ( '\0' , L_66 , true ) ;
# undef F_129
# undef F_132
#endif
V_2 -> V_62 = F_133 () ;
if ( V_2 -> V_62 == NULL )
return - V_170 ;
F_134 ( F_121 , V_2 ) ;
V_140 = F_135 ( V_140 , V_141 , V_212 , V_213 ,
V_214 ) ;
if ( ! V_140 && F_72 ( & V_2 -> V_59 . V_86 ) )
F_136 ( V_213 , V_212 ) ;
if ( V_215 && ! V_2 -> V_59 . V_86 . V_216 ) {
F_137 ( V_213 , V_212 ,
L_67 ) ;
}
if ( V_2 -> V_59 . V_217 &&
! F_138 () ) {
F_46 ( L_68 ) ;
F_139 ( V_213 , V_212 , L_69 , 0 ) ;
return - V_75 ;
}
if ( V_2 -> V_151 )
V_2 -> V_181 = true ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = F_140 ( V_2 -> V_62 , & V_52 ) ;
if ( V_52 )
goto V_36;
}
V_52 = F_141 ( V_2 -> V_58 , & V_2 -> V_59 ,
V_2 -> V_59 . V_218 ) ;
if ( V_52 )
goto V_36;
V_91 . V_219 = true ;
F_142 ( NULL ) ;
V_52 = F_143 ( V_2 -> V_62 ) ;
if ( V_52 )
goto V_36;
if ( V_220 )
goto V_36;
V_52 = F_144 ( V_2 -> V_62 ) ;
if ( V_52 ) {
F_145 ( V_2 -> V_62 , V_52 , V_158 , sizeof( V_158 ) ) ;
F_3 ( L_70 ,
V_158 ) ;
goto V_36;
}
V_52 = - V_170 ;
if ( V_91 . V_221 )
F_91 (
L_71
L_72
L_73
L_74
L_75
L_76
L_77 ) ;
if ( V_2 -> V_200 || V_2 -> V_104 ) {
F_146 () ;
} else if ( V_2 -> V_151 ) {
bool V_222 = true ;
if ( V_2 -> V_223 && ! V_2 -> V_104 )
V_222 = false ;
if ( V_2 -> V_224 && ! V_2 -> V_200 )
V_222 = false ;
if ( V_222 ) {
V_2 -> V_104 = true ;
V_2 -> V_200 = true ;
F_146 () ;
}
}
if ( V_1 . V_59 . V_30 )
V_1 . V_59 . V_120 = true ;
if ( V_2 -> V_62 -> V_225 == 0 &&
F_147 ( V_2 -> V_62 ) < 0 ) {
F_3 ( L_78 ) ;
goto V_36;
}
if ( V_2 -> V_59 . V_86 . V_226 && ! V_2 -> V_59 . V_227 )
V_2 -> V_59 . V_228 = true ;
V_52 = F_148 ( & V_2 -> V_59 . V_86 ) ;
if ( V_52 ) {
F_149 ( & V_2 -> V_59 . V_86 , V_52 , V_158 , V_159 ) ;
F_44 ( L_79 , V_158 ) ;
}
V_52 = F_150 ( & V_2 -> V_59 . V_86 ) ;
if ( V_52 ) {
int V_229 = V_73 ;
F_149 ( & V_2 -> V_59 . V_86 , V_52 , V_158 , V_159 ) ;
F_46 ( L_79 , V_158 ) ;
V_52 = - V_229 ;
goto V_36;
}
V_2 -> V_59 . V_230 = V_2 -> V_59 . V_86 . V_231 != V_232 ;
V_52 = - V_170 ;
if ( F_151 ( V_2 -> V_62 , & V_2 -> V_59 . V_86 ) < 0 )
F_136 ( V_213 , V_212 ) ;
V_52 = F_152 ( V_2 -> V_58 , V_2 -> V_62 , & V_2 -> V_59 ) ;
if ( V_52 )
goto V_36;
if ( V_2 -> V_59 . V_110 )
V_2 -> V_93 = true ;
if ( F_153 ( & V_2 -> V_59 ) ) {
V_52 = - V_75 ;
goto V_36;
}
V_52 = F_84 ( & V_1 , V_140 , V_141 ) ;
V_36:
F_154 ( V_2 -> V_62 ) ;
F_155 () ;
F_156 ( V_2 -> V_58 ) ;
return V_52 ;
}
static void V_153 ( int V_37 V_13 )
{
if ( F_157 ( & V_65 ) ) {
F_158 ( & V_65 ) ;
V_173 = 1 ;
if ( F_34 ( V_1 . V_58 ) )
F_31 ( & V_65 ) ;
}
if ( F_157 ( & V_154 ) )
F_158 ( & V_154 ) ;
}
