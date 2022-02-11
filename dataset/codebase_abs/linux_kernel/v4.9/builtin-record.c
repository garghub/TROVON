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
static void F_16 ( void )
{
if ( V_40 == - 1 )
return;
signal ( V_40 , V_42 ) ;
raise ( V_40 ) ;
}
static int F_17 ( struct V_8 * V_9 ,
union V_10 * V_11 , void * V_43 ,
T_1 V_44 , void * V_45 , T_1 V_46 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_47 * V_6 = & V_2 -> V_6 ;
T_1 V_48 ;
T_4 V_49 [ 8 ] = { 0 } ;
if ( ! F_18 ( V_6 ) ) {
T_5 V_50 ;
int V_51 = F_19 ( V_6 ) ;
int V_52 ;
V_50 = F_20 ( V_51 , 0 , V_53 ) ;
if ( V_50 == - 1 )
return - 1 ;
V_52 = F_21 ( & V_2 -> V_5 -> V_54 ,
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
static int F_22 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
int V_57 ;
V_57 = F_23 ( V_56 , V_2 -> V_58 , & V_2 -> V_9 ,
F_17 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
V_2 -> V_35 ++ ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
int V_57 ;
V_57 = F_25 ( V_56 , V_2 -> V_58 , & V_2 -> V_9 ,
F_17 ,
V_2 -> V_59 . V_60 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
V_2 -> V_35 ++ ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_61 ;
int V_34 = 0 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_62 -> V_63 ; V_61 ++ ) {
struct V_55 * V_56 =
& V_2 -> V_62 -> V_64 [ V_61 ] . V_55 ;
if ( ! V_56 -> V_32 )
continue;
if ( F_24 ( V_2 , V_56 ) != 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
V_36:
return V_34 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_8 ( L_9 ) ;
if ( F_26 ( V_2 ) < 0 ) {
F_28 ( & V_65 ) ;
} else {
if ( F_29 ( V_2 -> V_58 ) )
F_28 ( & V_65 ) ;
else
F_30 ( & V_65 ) ;
}
}
static inline
int F_22 ( struct V_1 * V_2 V_13 ,
struct V_55 * V_56 V_13 )
{
return 0 ;
}
static inline
void F_27 ( struct V_1 * V_2 V_13 )
{
}
static inline
int F_31 ( struct V_66 * V_58 V_13 )
{
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_67 * V_62 )
{
struct V_68 * V_59 = & V_2 -> V_59 ;
char V_69 [ 512 ] ;
if ( F_33 ( V_62 , V_59 -> V_70 , false ,
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
F_34 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
if ( V_73 )
return - V_73 ;
else
return - V_75 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , V_2 -> V_62 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
char V_69 [ 512 ] ;
struct V_76 * V_77 ;
struct V_67 * V_62 = V_2 -> V_62 ;
struct V_78 * V_5 = V_2 -> V_5 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_79 * V_80 ;
int V_34 = 0 ;
F_37 ( V_62 , V_59 , & V_81 ) ;
F_38 (evlist, pos) {
V_82:
if ( F_39 ( V_77 , V_77 -> V_83 , V_77 -> V_84 ) < 0 ) {
if ( F_40 ( V_77 , V_73 , V_69 , sizeof( V_69 ) ) ) {
if ( V_85 )
F_41 ( L_16 , V_69 ) ;
goto V_82;
}
V_34 = - V_73 ;
F_42 ( V_77 , & V_59 -> V_86 ,
V_73 , V_69 , sizeof( V_69 ) ) ;
F_43 ( L_16 , V_69 ) ;
goto V_36;
}
}
if ( F_44 ( V_62 , & V_77 ) ) {
error ( L_17 ,
V_77 -> V_87 , F_45 ( V_77 ) , V_73 ,
F_34 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
V_34 = - 1 ;
goto V_36;
}
if ( F_46 ( V_62 , & V_77 , & V_80 ) ) {
error ( L_18 ,
V_80 -> V_88 . V_89 , F_45 ( V_77 ) , V_73 ,
F_34 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
V_34 = - 1 ;
goto V_36;
}
V_34 = F_35 ( V_2 ) ;
if ( V_34 )
goto V_36;
V_5 -> V_62 = V_62 ;
F_47 ( V_5 ) ;
V_36:
return V_34 ;
}
static int F_48 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_76 * V_90 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_35 ++ ;
return F_49 ( V_9 , V_11 , T_2 , V_90 , V_14 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_78 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_91 . V_92 = true ;
if ( V_2 -> V_93 )
V_2 -> V_9 . T_2 = NULL ;
return F_51 ( V_5 ) ;
}
static void F_52 ( struct V_14 * V_14 , void * V_25 )
{
int V_52 ;
struct V_8 * V_9 = V_25 ;
V_52 = F_53 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_19
L_20 , V_14 -> V_94 ) ;
V_52 = F_54 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_19
L_20 , V_14 -> V_94 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_67 * V_62 ,
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
F_22 ( V_2 , V_56 ) != 0 ) {
V_34 = - 1 ;
goto V_36;
}
}
if ( V_7 != V_2 -> V_7 )
V_34 = F_1 ( V_2 , & V_99 , sizeof( V_99 ) ) ;
if ( V_27 )
F_56 ( V_62 , V_100 ) ;
V_36:
return V_34 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_55 ( V_2 , V_2 -> V_62 , false ) ;
if ( V_52 )
return V_52 ;
return F_55 ( V_2 , V_2 -> V_62 , true ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
int V_101 ;
for ( V_101 = V_102 ; V_101 < V_103 ; V_101 ++ )
F_59 ( & V_5 -> V_15 , V_101 ) ;
if ( V_2 -> V_104 )
F_60 ( & V_5 -> V_15 , V_105 ) ;
if ( ! F_61 ( & V_2 -> V_62 -> V_106 ) )
F_60 ( & V_5 -> V_15 , V_107 ) ;
if ( ! V_2 -> V_59 . V_108 )
F_60 ( & V_5 -> V_15 , V_109 ) ;
if ( ! V_2 -> V_59 . V_110 )
F_60 ( & V_5 -> V_15 , V_111 ) ;
F_60 ( & V_5 -> V_15 , V_112 ) ;
}
static void
F_62 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 = F_19 ( V_6 ) ;
if ( V_6 -> V_113 )
return;
V_2 -> V_5 -> V_15 . V_114 += V_2 -> V_7 ;
V_6 -> V_4 = F_20 ( F_19 ( V_6 ) , 0 , V_53 ) ;
if ( ! V_2 -> V_104 ) {
F_50 ( V_2 ) ;
if ( V_2 -> V_93 )
F_63 ( V_2 -> V_5 ) ;
}
F_64 ( V_2 -> V_5 , V_2 -> V_62 , V_51 , true ) ;
return;
}
static int F_65 ( struct V_1 * V_2 , bool V_115 )
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
return F_66 ( & V_2 -> V_9 , & V_116 . V_117 ,
F_4 ,
& V_2 -> V_5 -> V_124 . V_125 ,
V_2 -> V_59 . V_126 ,
V_2 -> V_59 . V_127 ) ;
}
static int
F_67 ( struct V_1 * V_2 , bool V_128 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 , V_52 ;
char V_129 [] = L_21 ;
F_68 ( V_2 , true ) ;
if ( F_69 ( & V_2 -> V_59 . V_86 ) )
F_65 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
F_62 ( V_2 ) ;
V_52 = F_70 ( V_129 , sizeof( V_129 ) ) ;
if ( V_52 ) {
F_3 ( L_22 ) ;
return - V_75 ;
}
V_51 = F_71 ( V_6 , V_129 ,
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
F_68 ( V_2 , false ) ;
if ( F_69 ( & V_2 -> V_59 . V_86 ) )
F_65 ( V_2 , false ) ;
}
return V_51 ;
}
static void F_72 ( int T_6 V_13 ,
T_7 * V_134 ,
void * T_8 V_13 )
{
V_135 = V_134 -> V_136 . V_137 ;
V_41 = 1 ;
V_39 = 1 ;
}
int __weak
F_73 ( const struct V_138 * T_9 V_13 ,
struct V_8 * V_9 V_13 ,
T_10 T_11 V_13 ,
struct V_14 * V_14 V_13 )
{
return 0 ;
}
static const struct V_138 *
F_74 ( struct V_67 * V_62 )
{
if ( V_62 ) {
if ( V_62 -> V_64 && V_62 -> V_64 [ 0 ] . V_32 )
return V_62 -> V_64 [ 0 ] . V_32 ;
if ( V_62 -> V_96 && V_62 -> V_96 [ 0 ] . V_32 )
return V_62 -> V_96 [ 0 ] . V_32 ;
}
return NULL ;
}
static const struct V_138 * F_75 ( struct V_1 * V_2 )
{
const struct V_138 * T_9 ;
T_9 = F_74 ( V_2 -> V_62 ) ;
if ( T_9 )
return T_9 ;
return NULL ;
}
static int F_68 ( struct V_1 * V_2 , bool V_115 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
struct V_14 * V_14 = & V_5 -> V_124 . V_125 ;
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_51 = F_19 ( V_6 ) ;
int V_52 = 0 ;
if ( V_2 -> V_59 . V_120 != V_115 )
return 0 ;
if ( V_6 -> V_113 ) {
V_52 = F_76 ( V_9 , V_5 ,
F_4 ) ;
if ( V_52 < 0 ) {
F_3 ( L_24 ) ;
goto V_36;
}
if ( F_61 ( & V_2 -> V_62 -> V_106 ) ) {
V_52 = F_77 ( V_9 , V_51 , V_2 -> V_62 ,
F_4 ) ;
if ( V_52 <= 0 ) {
F_3 ( L_25 ) ;
goto V_36;
}
V_2 -> V_7 += V_52 ;
}
}
V_52 = F_73 ( F_75 ( V_2 ) , V_9 ,
F_4 , V_14 ) ;
if ( V_52 )
goto V_36;
if ( V_2 -> V_59 . V_110 ) {
V_52 = F_78 ( V_2 -> V_58 , V_9 ,
V_5 , F_4 ) ;
if ( V_52 )
goto V_36;
}
V_52 = F_54 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_26
L_27
L_28 ) ;
V_52 = F_53 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_29
L_27
L_30 ) ;
if ( V_139 ) {
F_79 ( & V_5 -> V_124 ,
F_52 , V_9 ) ;
}
V_52 = F_80 ( V_14 , V_9 , & V_59 -> V_86 , V_2 -> V_62 -> V_84 ,
F_4 , V_59 -> V_126 ,
V_59 -> V_127 ) ;
V_36:
return V_52 ;
}
static int F_81 ( struct V_1 * V_2 , int V_140 , const char * * V_141 )
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
atexit ( F_16 ) ;
signal ( V_38 , F_15 ) ;
signal ( V_148 , F_15 ) ;
signal ( V_149 , F_15 ) ;
if ( V_2 -> V_59 . V_72 || V_2 -> V_150 ) {
signal ( V_151 , V_152 ) ;
if ( V_2 -> V_59 . V_72 )
F_82 ( & V_65 ) ;
if ( V_2 -> V_150 )
F_82 ( & V_153 ) ;
} else {
signal ( V_151 , V_154 ) ;
}
V_5 = F_83 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_31 ) ;
return - 1 ;
}
V_51 = F_19 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_58 ( V_2 ) ;
if ( V_144 ) {
V_52 = F_84 ( V_2 -> V_62 , & V_59 -> V_86 ,
V_141 , V_6 -> V_113 ,
F_72 ) ;
if ( V_52 < 0 ) {
F_3 ( L_32 ) ;
V_142 = V_52 ;
goto V_155;
}
}
if ( F_36 ( V_2 ) != 0 ) {
V_52 = - 1 ;
goto V_156;
}
V_52 = F_85 () ;
if ( V_52 ) {
char V_157 [ V_158 ] ;
F_86 ( V_52 , V_157 , sizeof( V_157 ) ) ;
F_3 ( L_33 ,
V_157 ) ;
goto V_156;
}
if ( V_2 -> V_9 . V_159 && ! F_87 ( V_2 -> V_62 ) ) {
F_88 ( L_34 ) ;
V_2 -> V_9 . V_159 = false ;
}
if ( ! V_2 -> V_62 -> V_160 )
F_60 ( & V_5 -> V_15 , V_161 ) ;
if ( V_6 -> V_113 ) {
V_52 = F_89 ( V_51 ) ;
if ( V_52 < 0 )
goto V_156;
} else {
V_52 = F_64 ( V_5 , V_2 -> V_62 , V_51 , false ) ;
if ( V_52 < 0 )
goto V_156;
}
if ( ! V_2 -> V_104
&& ! F_90 ( & V_5 -> V_15 , V_105 ) ) {
F_3 ( L_35
L_36 ) ;
V_52 = - 1 ;
goto V_156;
}
V_14 = & V_5 -> V_124 . V_125 ;
V_52 = F_68 ( V_2 , false ) ;
if ( V_52 < 0 )
goto V_156;
if ( V_2 -> V_162 ) {
struct V_163 V_164 ;
V_164 . V_165 = V_2 -> V_162 ;
if ( F_91 ( 0 , V_166 , & V_164 ) ) {
F_3 ( L_37 ) ;
V_52 = - 1 ;
goto V_156;
}
}
if ( ! F_69 ( & V_59 -> V_86 ) && ! V_59 -> V_167 )
F_92 ( V_2 -> V_62 ) ;
if ( V_144 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_123 ) + V_14 -> V_168 ) ;
if ( V_11 == NULL ) {
V_52 = - V_169 ;
goto V_156;
}
F_93 ( V_9 , V_11 ,
V_2 -> V_62 -> V_122 . V_94 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_94 ( V_2 -> V_62 ) ;
}
if ( V_59 -> V_167 ) {
F_95 ( V_59 -> V_167 * V_170 ) ;
F_92 ( V_2 -> V_62 ) ;
}
F_30 ( & V_65 ) ;
F_30 ( & V_153 ) ;
for (; ; ) {
unsigned long long V_171 = V_2 -> V_35 ;
if ( F_96 ( & V_153 ) || V_41 || V_146 )
F_56 ( V_2 -> V_62 , V_98 ) ;
if ( F_57 ( V_2 ) < 0 ) {
F_28 ( & V_65 ) ;
F_28 ( & V_153 ) ;
V_52 = - 1 ;
goto V_156;
}
if ( V_172 ) {
V_172 = 0 ;
if ( ! F_97 ( & V_65 ) )
F_27 ( V_2 ) ;
if ( F_97 ( & V_65 ) ) {
F_3 ( L_38 ) ;
V_52 = - 1 ;
goto V_156;
}
}
if ( F_96 ( & V_153 ) ) {
if ( V_2 -> V_62 -> V_97 == V_173 )
continue;
F_30 ( & V_153 ) ;
F_56 ( V_2 -> V_62 , V_173 ) ;
if ( ! V_131 )
fprintf ( V_132 , L_39 ,
V_143 ) ;
V_143 = 0 ;
V_51 = F_67 ( V_2 , false ) ;
if ( V_51 < 0 ) {
F_3 ( L_40 ) ;
F_28 ( & V_153 ) ;
V_52 = V_51 ;
goto V_156;
}
}
if ( V_171 == V_2 -> V_35 ) {
if ( V_41 || V_146 )
break;
V_52 = F_98 ( V_2 -> V_62 , - 1 ) ;
if ( V_52 > 0 || ( V_52 < 0 && V_73 == V_174 ) )
V_52 = 0 ;
V_143 ++ ;
if ( F_99 ( V_2 -> V_62 , V_175 | V_176 ) == 0 )
V_146 = true ;
}
if ( V_41 && ! V_145 && ! F_69 ( & V_59 -> V_86 ) ) {
F_100 ( & V_65 ) ;
F_101 ( V_2 -> V_62 ) ;
V_145 = true ;
}
}
F_100 ( & V_65 ) ;
F_100 ( & V_153 ) ;
if ( V_144 && V_135 ) {
char V_69 [ V_177 ] ;
const char * V_178 = F_34 ( V_135 , V_69 , sizeof( V_69 ) ) ;
F_3 ( L_41 , V_178 ) ;
V_52 = - 1 ;
goto V_156;
}
if ( ! V_131 )
fprintf ( V_132 , L_42 , V_143 ) ;
if ( F_69 ( & V_2 -> V_59 . V_86 ) )
F_65 ( V_2 , true ) ;
V_156:
if ( V_144 ) {
int V_179 ;
if ( ! V_39 )
F_102 ( V_2 -> V_62 -> V_122 . V_94 , V_149 ) ;
F_103 ( & V_179 ) ;
if ( V_52 < 0 )
V_142 = V_52 ;
else if ( F_104 ( V_179 ) )
V_142 = F_105 ( V_179 ) ;
else if ( F_106 ( V_179 ) )
V_40 = F_107 ( V_179 ) ;
} else
V_142 = V_52 ;
F_68 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
if ( ! V_52 ) {
if ( ! V_2 -> V_180 ) {
F_62 ( V_2 ) ;
} else {
V_51 = F_67 ( V_2 , true ) ;
if ( V_51 < 0 ) {
V_142 = V_51 ;
goto V_155;
}
}
}
if ( ! V_52 && ! V_131 ) {
char V_35 [ 128 ] ;
const char * V_181 = V_2 -> V_180 ?
L_43 : L_44 ;
if ( V_2 -> V_35 && ! V_2 -> V_59 . V_110 )
F_108 ( V_35 , sizeof( V_35 ) ,
L_45 V_182 L_46 , V_2 -> V_35 ) ;
else
V_35 [ 0 ] = '\0' ;
fprintf ( V_132 , L_47 ,
F_109 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_133 , V_181 , V_35 ) ;
}
V_155:
F_110 ( V_5 ) ;
return V_142 ;
}
static void F_111 ( struct V_81 * V_183 )
{
static const char * V_184 [ V_185 ] = { L_48 , L_49 , L_50 , L_51 } ;
F_8 ( L_52 , V_184 [ V_183 -> V_186 ] ) ;
if ( V_183 -> V_186 == V_187 )
F_8 ( L_53 ,
V_183 -> V_188 ) ;
}
int F_112 ( struct V_68 * V_1 ,
struct V_81 * V_183 ,
const char * V_189 , bool V_190 )
{
int V_57 ;
V_183 -> V_191 = ! V_190 ;
if ( V_190 ) {
V_183 -> V_186 = V_192 ;
F_8 ( L_54 ) ;
return 0 ;
}
V_57 = F_113 ( V_189 , V_183 ) ;
if ( ! V_57 ) {
if ( V_183 -> V_186 == V_187 )
V_1 -> V_126 = true ;
F_111 ( V_183 ) ;
}
return V_57 ;
}
int F_114 ( const struct V_193 * V_194 ,
const char * V_189 ,
int V_190 )
{
return F_112 ( V_194 -> V_195 , & V_81 , V_189 , V_190 ) ;
}
int F_115 ( const struct V_193 * V_194 ,
const char * V_189 V_13 ,
int V_190 V_13 )
{
struct V_81 * V_183 = V_194 -> V_195 ;
V_183 -> V_191 = true ;
if ( V_183 -> V_186 == V_192 )
V_183 -> V_186 = V_196 ;
F_111 ( V_183 ) ;
return 0 ;
}
static int F_116 ( const char * V_197 , const char * V_195 , void * V_198 )
{
struct V_1 * V_2 = V_198 ;
if ( ! strcmp ( V_197 , L_55 ) ) {
if ( ! strcmp ( V_195 , L_56 ) )
V_2 -> V_199 = false ;
else if ( ! strcmp ( V_195 , L_57 ) )
V_2 -> V_199 = true ;
else if ( ! strcmp ( V_195 , L_58 ) )
V_2 -> V_104 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_197 , L_59 ) )
V_197 = L_60 ;
return F_117 ( V_197 , V_195 , V_198 ) ;
}
static int F_118 ( const struct V_193 * V_194 , const char * V_184 , int V_190 )
{
struct V_68 * V_59 = (struct V_68 * ) V_194 -> V_195 ;
const struct V_200 * V_201 ;
const char * V_202 = V_184 ;
if ( V_190 ) {
V_59 -> V_203 = 0 ;
return 0 ;
}
if ( ! V_184 )
return 0 ;
if ( V_59 -> V_203 )
return - 1 ;
V_59 -> V_203 = true ;
if ( sscanf ( V_184 , L_61 , & V_59 -> V_204 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_184 , L_62 , 6 ) )
V_184 += 6 ;
for ( V_201 = V_205 ; V_201 -> V_206 ; V_201 ++ ) {
if ( ! strcasecmp ( V_184 , V_201 -> V_206 ) ) {
V_59 -> V_204 = V_201 -> V_204 ;
return 0 ;
}
}
V_59 -> V_203 = false ;
F_41 ( L_63 , V_202 ) ;
return - 1 ;
}
static int F_119 ( const struct V_193 * V_194 ,
const char * V_184 ,
int V_190 V_13 )
{
struct V_68 * V_59 = V_194 -> V_195 ;
char * V_207 , * V_208 ;
unsigned int V_70 ;
int V_57 ;
if ( ! V_184 )
return - V_75 ;
V_207 = F_120 ( V_184 ) ;
if ( ! V_207 )
return - V_169 ;
V_208 = strchr ( V_207 , ',' ) ;
if ( V_208 )
* V_208 = '\0' ;
if ( * V_207 ) {
V_57 = F_121 ( & V_70 , V_207 ) ;
if ( V_57 )
goto V_209;
V_59 -> V_70 = V_70 ;
}
if ( ! V_208 ) {
V_57 = 0 ;
goto V_209;
}
V_57 = F_121 ( & V_70 , V_208 + 1 ) ;
if ( V_57 )
goto V_209;
V_59 -> V_71 = V_70 ;
V_209:
free ( V_207 ) ;
return V_57 ;
}
int F_122 ( int V_140 , const char * * V_141 , const char * T_12 V_13 )
{
int V_52 ;
struct V_1 * V_2 = & V_1 ;
char V_157 [ V_158 ] ;
#ifndef F_123
# define F_124 ( V_207 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_124 ( '\0' , L_64 , true ) ;
F_124 ( '\0' , L_65 , true ) ;
# undef F_124
#endif
#ifndef F_125
# if ! F_126 ( V_210 )
# define F_127 "NO_DWARF=1"
# elif ! F_126 ( F_123 )
# define F_127 "NO_LIBBPF=1"
# else
# define F_127 "this architecture doesn't support BPF prologue"
# endif
# define F_124 ( V_207 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_124 ( '\0' , L_66 , true ) ;
# undef F_124
# undef F_127
#endif
V_2 -> V_62 = F_128 () ;
if ( V_2 -> V_62 == NULL )
return - V_169 ;
F_129 ( F_116 , V_2 ) ;
V_140 = F_130 ( V_140 , V_141 , V_211 , V_212 ,
V_213 ) ;
if ( ! V_140 && F_69 ( & V_2 -> V_59 . V_86 ) )
F_131 ( V_212 , V_211 ) ;
if ( V_214 && ! V_2 -> V_59 . V_86 . V_215 ) {
F_132 ( V_212 , V_211 ,
L_67 ) ;
}
if ( V_2 -> V_59 . V_216 &&
! F_133 () ) {
F_43 ( L_68 ) ;
F_134 ( V_212 , V_211 , L_69 , 0 ) ;
return - V_75 ;
}
if ( V_2 -> V_150 )
V_2 -> V_180 = true ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = F_135 ( V_2 -> V_62 , & V_52 ) ;
if ( V_52 )
goto V_36;
}
V_52 = F_136 ( V_2 -> V_58 , & V_2 -> V_59 ,
V_2 -> V_59 . V_217 ) ;
if ( V_52 )
goto V_36;
V_91 . V_218 = true ;
F_137 ( NULL ) ;
V_52 = F_138 ( V_2 -> V_62 ) ;
if ( V_52 )
goto V_36;
if ( V_219 )
goto V_36;
V_52 = F_139 ( V_2 -> V_62 ) ;
if ( V_52 ) {
F_140 ( V_2 -> V_62 , V_52 , V_157 , sizeof( V_157 ) ) ;
F_3 ( L_70 ,
V_157 ) ;
goto V_36;
}
V_52 = - V_169 ;
if ( V_91 . V_220 )
F_88 (
L_71
L_72
L_73
L_74
L_75
L_76
L_77 ) ;
if ( V_2 -> V_199 || V_2 -> V_104 ) {
F_141 () ;
} else if ( V_2 -> V_150 ) {
bool V_221 = true ;
if ( V_2 -> V_222 && ! V_2 -> V_104 )
V_221 = false ;
if ( V_2 -> V_223 && ! V_2 -> V_199 )
V_221 = false ;
if ( V_221 ) {
V_2 -> V_104 = true ;
V_2 -> V_199 = true ;
F_141 () ;
}
}
if ( V_1 . V_59 . V_30 )
V_1 . V_59 . V_120 = true ;
if ( V_2 -> V_62 -> V_224 == 0 &&
F_142 ( V_2 -> V_62 ) < 0 ) {
F_3 ( L_78 ) ;
goto V_36;
}
if ( V_2 -> V_59 . V_86 . V_225 && ! V_2 -> V_59 . V_226 )
V_2 -> V_59 . V_227 = true ;
V_52 = F_143 ( & V_2 -> V_59 . V_86 ) ;
if ( V_52 ) {
F_144 ( & V_2 -> V_59 . V_86 , V_52 , V_157 , V_158 ) ;
F_41 ( L_79 , V_157 ) ;
}
V_52 = F_145 ( & V_2 -> V_59 . V_86 ) ;
if ( V_52 ) {
int V_228 = V_73 ;
F_144 ( & V_2 -> V_59 . V_86 , V_52 , V_157 , V_158 ) ;
F_43 ( L_79 , V_157 ) ;
V_52 = - V_228 ;
goto V_36;
}
V_52 = - V_169 ;
if ( F_146 ( V_2 -> V_62 , & V_2 -> V_59 . V_86 ) < 0 )
F_131 ( V_212 , V_211 ) ;
V_52 = F_147 ( V_2 -> V_58 , V_2 -> V_62 , & V_2 -> V_59 ) ;
if ( V_52 )
goto V_36;
if ( V_2 -> V_59 . V_110 )
V_2 -> V_93 = true ;
if ( F_148 ( & V_2 -> V_59 ) ) {
V_52 = - V_75 ;
goto V_36;
}
V_52 = F_81 ( & V_1 , V_140 , V_141 ) ;
V_36:
F_149 ( V_2 -> V_62 ) ;
F_150 () ;
F_151 ( V_2 -> V_58 ) ;
return V_52 ;
}
static void V_152 ( int V_37 V_13 )
{
if ( F_152 ( & V_65 ) ) {
F_153 ( & V_65 ) ;
V_172 = 1 ;
if ( F_31 ( V_1 . V_58 ) )
F_28 ( & V_65 ) ;
}
if ( F_152 ( & V_153 ) )
F_153 ( & V_153 ) ;
}
