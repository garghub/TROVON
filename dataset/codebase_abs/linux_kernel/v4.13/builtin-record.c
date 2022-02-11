static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . signal &&
F_2 ( & V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_5 &&
F_2 ( & V_4 ) &&
( V_2 -> V_6 >= V_2 -> V_3 . V_5 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . time &&
F_2 ( & V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_7 , T_1 V_5 )
{
if ( F_6 ( V_2 -> V_8 -> V_9 , V_7 , V_5 ) < 0 ) {
F_7 ( L_1 ) ;
return - 1 ;
}
V_2 -> V_6 += V_5 ;
if ( F_3 ( V_2 ) )
F_8 ( & V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 ,
union V_12 * V_13 ,
struct V_14 * T_2 V_15 ,
struct V_16 * V_16 V_15 )
{
struct V_1 * V_2 = F_10 ( V_11 , struct V_1 , V_11 ) ;
return F_5 ( V_2 , V_13 , V_13 -> V_17 . V_5 ) ;
}
static int
F_11 ( void * V_18 , int V_19 , T_3 V_20 , T_3 * V_21 , T_3 * V_22 )
{
struct V_23 * V_24 ;
T_3 V_25 = V_20 ;
int V_5 = V_19 + 1 ;
F_12 ( L_2 V_26 L_3 , V_18 , V_20 ) ;
V_24 = (struct V_23 * ) ( V_18 + ( V_20 & V_19 ) ) ;
* V_21 = V_20 ;
while ( true ) {
if ( V_25 - V_20 >= ( unsigned int ) V_5 ) {
F_13 ( L_4 ) ;
if ( V_25 - V_20 > ( unsigned int ) V_5 )
V_25 -= V_24 -> V_5 ;
* V_22 = V_25 ;
return 0 ;
}
V_24 = (struct V_23 * ) ( V_18 + ( V_25 & V_19 ) ) ;
if ( V_24 -> V_5 == 0 ) {
F_13 ( L_5 ) ;
* V_22 = V_25 ;
return 0 ;
}
V_25 += V_24 -> V_5 ;
F_14 ( L_6 V_26 L_3 , V_25 ) ;
}
F_15 ( 1 , L_7 ) ;
return - 1 ;
}
static int
F_16 ( void * V_27 , int V_19 , T_3 V_20 , T_3 V_28 ,
T_3 * V_21 , T_3 * V_22 , bool V_29 )
{
if ( ! V_29 ) {
* V_21 = V_28 ;
* V_22 = V_20 ;
return 0 ;
}
return F_11 ( V_27 , V_19 , V_20 , V_21 , V_22 ) ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_30 * V_31 ,
bool V_32 , bool V_29 )
{
T_3 V_20 = F_18 ( V_31 ) ;
T_3 V_28 = V_31 -> V_33 ;
T_3 V_22 = V_20 , V_21 = V_28 ;
unsigned char * V_27 = V_31 -> V_34 + V_35 ;
unsigned long V_5 ;
void * V_18 ;
int V_36 = 0 ;
if ( F_16 ( V_27 , V_31 -> V_19 , V_20 ,
V_28 , & V_21 , & V_22 , V_29 ) )
return - 1 ;
if ( V_21 == V_22 )
return 0 ;
V_2 -> V_37 ++ ;
V_5 = V_22 - V_21 ;
if ( V_5 > ( unsigned long ) ( V_31 -> V_19 ) + 1 ) {
F_15 ( 1 , L_8 ) ;
V_31 -> V_33 = V_20 ;
F_19 ( V_31 , V_32 || V_29 ) ;
return 0 ;
}
if ( ( V_21 & V_31 -> V_19 ) + V_5 != ( V_22 & V_31 -> V_19 ) ) {
V_18 = & V_27 [ V_21 & V_31 -> V_19 ] ;
V_5 = V_31 -> V_19 + 1 - ( V_21 & V_31 -> V_19 ) ;
V_21 += V_5 ;
if ( F_5 ( V_2 , V_18 , V_5 ) < 0 ) {
V_36 = - 1 ;
goto V_38;
}
}
V_18 = & V_27 [ V_21 & V_31 -> V_19 ] ;
V_5 = V_22 - V_21 ;
V_21 += V_5 ;
if ( F_5 ( V_2 , V_18 , V_5 ) < 0 ) {
V_36 = - 1 ;
goto V_38;
}
V_31 -> V_33 = V_20 ;
F_19 ( V_31 , V_32 || V_29 ) ;
V_38:
return V_36 ;
}
static void F_20 ( int V_39 )
{
if ( V_39 == V_40 )
V_41 = 1 ;
else
V_42 = V_39 ;
V_43 = 1 ;
}
static void F_21 ( int V_39 )
{
F_22 () ;
F_23 ( V_39 ) ;
}
static void F_24 ( void )
{
if ( V_42 == - 1 )
return;
signal ( V_42 , V_44 ) ;
raise ( V_42 ) ;
}
static int F_25 ( struct V_10 * V_11 ,
union V_12 * V_13 , void * V_45 ,
T_1 V_46 , void * V_47 , T_1 V_48 )
{
struct V_1 * V_2 = F_10 ( V_11 , struct V_1 , V_11 ) ;
struct V_49 * V_9 = & V_2 -> V_9 ;
T_1 V_50 ;
T_4 V_51 [ 8 ] = { 0 } ;
if ( ! F_26 ( V_9 ) ) {
T_5 V_52 ;
int V_53 = F_27 ( V_9 ) ;
int V_54 ;
V_52 = F_28 ( V_53 , 0 , V_55 ) ;
if ( V_52 == - 1 )
return - 1 ;
V_54 = F_29 ( & V_2 -> V_8 -> V_56 ,
V_13 , V_52 ) ;
if ( V_54 )
return V_54 ;
}
V_50 = ( V_46 + V_48 ) & 7 ;
if ( V_50 )
V_50 = 8 - V_50 ;
F_5 ( V_2 , V_13 , V_13 -> V_17 . V_5 ) ;
F_5 ( V_2 , V_45 , V_46 ) ;
if ( V_48 )
F_5 ( V_2 , V_47 , V_48 ) ;
F_5 ( V_2 , & V_51 , V_50 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_31 ( V_58 , V_2 -> V_60 , & V_2 -> V_11 ,
F_25 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 )
V_2 -> V_37 ++ ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_33 ( V_58 , V_2 -> V_60 , & V_2 -> V_11 ,
F_25 ,
V_2 -> V_61 . V_62 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 )
V_2 -> V_37 ++ ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_63 ;
int V_36 = 0 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_64 -> V_65 ; V_63 ++ ) {
struct V_57 * V_58 =
& V_2 -> V_64 -> V_66 [ V_63 ] . V_57 ;
if ( ! V_58 -> V_34 )
continue;
if ( F_32 ( V_2 , V_58 ) != 0 ) {
V_36 = - 1 ;
goto V_38;
}
}
V_38:
return V_36 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_13 ( L_9 ) ;
if ( F_34 ( V_2 ) < 0 ) {
F_36 ( & V_67 ) ;
} else {
if ( F_37 ( V_2 -> V_60 ) )
F_36 ( & V_67 ) ;
else
F_38 ( & V_67 ) ;
}
}
static inline
int F_30 ( struct V_1 * V_2 V_15 ,
struct V_57 * V_58 V_15 )
{
return 0 ;
}
static inline
void F_35 ( struct V_1 * V_2 V_15 )
{
}
static inline
int F_39 ( struct V_68 * V_60 V_15 )
{
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_69 * V_64 )
{
struct V_70 * V_61 = & V_2 -> V_61 ;
char V_71 [ 512 ] ;
if ( F_41 ( V_64 , V_61 -> V_72 , false ,
V_61 -> V_73 ,
V_61 -> V_74 ) < 0 ) {
if ( V_75 == V_76 ) {
F_7 ( L_10
L_11
L_12
L_13
L_14 ,
V_61 -> V_72 , V_61 -> V_73 ) ;
return - V_75 ;
} else {
F_7 ( L_15 , V_75 ,
F_42 ( V_75 , V_71 , sizeof( V_71 ) ) ) ;
if ( V_75 )
return - V_75 ;
else
return - V_77 ;
}
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_2 -> V_64 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
char V_71 [ V_78 ] ;
struct V_79 * V_80 ;
struct V_69 * V_64 = V_2 -> V_64 ;
struct V_81 * V_8 = V_2 -> V_8 ;
struct V_70 * V_61 = & V_2 -> V_61 ;
struct V_82 * V_83 ;
int V_36 = 0 ;
F_45 ( V_64 , V_61 , & V_84 ) ;
F_46 (evlist, pos) {
V_85:
if ( F_47 ( V_80 , V_80 -> V_86 , V_80 -> V_87 ) < 0 ) {
if ( F_48 ( V_80 , V_75 , V_71 , sizeof( V_71 ) ) ) {
if ( V_88 > 0 )
F_49 ( L_16 , V_71 ) ;
goto V_85;
}
V_36 = - V_75 ;
F_50 ( V_80 , & V_61 -> V_89 ,
V_75 , V_71 , sizeof( V_71 ) ) ;
F_51 ( L_16 , V_71 ) ;
goto V_38;
}
}
if ( F_52 ( V_64 , & V_80 ) ) {
F_7 ( L_17 ,
V_80 -> V_90 , F_53 ( V_80 ) , V_75 ,
F_42 ( V_75 , V_71 , sizeof( V_71 ) ) ) ;
V_36 = - 1 ;
goto V_38;
}
if ( F_54 ( V_64 , & V_80 , & V_83 ) ) {
F_7 ( L_18 ,
V_83 -> V_91 . V_92 , F_53 ( V_80 ) , V_75 ,
F_42 ( V_75 , V_71 , sizeof( V_71 ) ) ) ;
V_36 = - 1 ;
goto V_38;
}
V_36 = F_43 ( V_2 ) ;
if ( V_36 )
goto V_38;
V_8 -> V_64 = V_64 ;
F_55 ( V_8 ) ;
V_38:
return V_36 ;
}
static int F_56 ( struct V_10 * V_11 ,
union V_12 * V_13 ,
struct V_14 * T_2 ,
struct V_79 * V_93 ,
struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_11 , struct V_1 , V_11 ) ;
V_2 -> V_37 ++ ;
return F_57 ( V_11 , V_13 , T_2 , V_93 , V_16 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_49 * V_9 = & V_2 -> V_9 ;
struct V_81 * V_8 = V_2 -> V_8 ;
if ( V_9 -> V_5 == 0 )
return 0 ;
V_94 . V_95 = true ;
if ( V_2 -> V_96 )
V_2 -> V_11 . T_2 = NULL ;
return F_59 ( V_8 ) ;
}
static void F_60 ( struct V_16 * V_16 , void * V_27 )
{
int V_54 ;
struct V_10 * V_11 = V_27 ;
V_54 = F_61 ( V_11 , F_9 ,
V_16 ) ;
if ( V_54 < 0 )
F_7 ( L_19
L_20 , V_16 -> V_97 ) ;
V_54 = F_62 ( V_11 , F_9 ,
V_16 ) ;
if ( V_54 < 0 )
F_7 ( L_19
L_20 , V_16 -> V_97 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_69 * V_64 ,
bool V_29 )
{
T_3 V_6 = V_2 -> V_6 ;
int V_63 ;
int V_36 = 0 ;
struct V_30 * V_98 ;
if ( ! V_64 )
return 0 ;
V_98 = V_29 ? V_64 -> V_99 : V_64 -> V_66 ;
if ( ! V_98 )
return 0 ;
if ( V_29 && V_64 -> V_100 != V_101 )
return 0 ;
for ( V_63 = 0 ; V_63 < V_64 -> V_65 ; V_63 ++ ) {
struct V_57 * V_58 = & V_98 [ V_63 ] . V_57 ;
if ( V_98 [ V_63 ] . V_34 ) {
if ( F_17 ( V_2 , & V_98 [ V_63 ] ,
V_64 -> V_32 , V_29 ) != 0 ) {
V_36 = - 1 ;
goto V_38;
}
}
if ( V_58 -> V_34 && ! V_2 -> V_61 . V_74 &&
F_30 ( V_2 , V_58 ) != 0 ) {
V_36 = - 1 ;
goto V_38;
}
}
if ( V_6 != V_2 -> V_6 )
V_36 = F_5 ( V_2 , & V_102 , sizeof( V_102 ) ) ;
if ( V_29 )
F_64 ( V_64 , V_103 ) ;
V_38:
return V_36 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_63 ( V_2 , V_2 -> V_64 , false ) ;
if ( V_54 )
return V_54 ;
return F_63 ( V_2 , V_2 -> V_64 , true ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_81 * V_8 = V_2 -> V_8 ;
int V_104 ;
for ( V_104 = V_105 ; V_104 < V_106 ; V_104 ++ )
F_67 ( & V_8 -> V_17 , V_104 ) ;
if ( V_2 -> V_107 )
F_68 ( & V_8 -> V_17 , V_108 ) ;
if ( ! F_69 ( & V_2 -> V_64 -> V_109 ) )
F_68 ( & V_8 -> V_17 , V_110 ) ;
if ( ! V_2 -> V_61 . V_111 )
F_68 ( & V_8 -> V_17 , V_112 ) ;
if ( ! V_2 -> V_61 . V_113 )
F_68 ( & V_8 -> V_17 , V_114 ) ;
F_68 ( & V_8 -> V_17 , V_115 ) ;
}
static void
F_70 ( struct V_1 * V_2 )
{
struct V_49 * V_9 = & V_2 -> V_9 ;
int V_53 = F_27 ( V_9 ) ;
if ( V_9 -> V_116 )
return;
V_2 -> V_8 -> V_17 . V_117 += V_2 -> V_6 ;
V_9 -> V_5 = F_28 ( F_27 ( V_9 ) , 0 , V_55 ) ;
if ( ! V_2 -> V_107 ) {
F_58 ( V_2 ) ;
if ( V_2 -> V_96 )
F_71 ( V_2 -> V_8 ) ;
}
F_72 ( V_2 -> V_8 , V_2 -> V_64 , V_53 , true ) ;
return;
}
static int F_73 ( struct V_1 * V_2 , bool V_118 )
{
int V_54 ;
struct V_119 * V_119 ;
if ( V_2 -> V_61 . V_120 != V_118 )
return 0 ;
V_119 = F_74 ( V_2 -> V_64 -> V_121 . V_97 ) ;
if ( V_119 == NULL )
return - 1 ;
V_54 = F_75 ( & V_2 -> V_11 , V_119 ,
F_9 ,
& V_2 -> V_8 -> V_122 . V_123 ,
V_2 -> V_61 . V_124 ,
V_2 -> V_61 . V_125 ) ;
F_76 ( V_119 ) ;
return V_54 ;
}
static int
F_77 ( struct V_1 * V_2 , bool V_126 )
{
struct V_49 * V_9 = & V_2 -> V_9 ;
int V_53 , V_54 ;
char V_127 [] = L_21 ;
F_78 ( V_2 , true ) ;
if ( F_79 ( & V_2 -> V_61 . V_89 ) )
F_73 ( V_2 , true ) ;
V_2 -> V_37 = 0 ;
F_70 ( V_2 ) ;
V_54 = F_80 ( V_127 , sizeof( V_127 ) ) ;
if ( V_54 ) {
F_7 ( L_22 ) ;
return - V_77 ;
}
V_53 = F_81 ( V_9 , V_127 ,
V_2 -> V_8 -> V_17 . V_128 ,
V_126 ) ;
if ( V_53 >= 0 && ! V_126 ) {
V_2 -> V_6 = 0 ;
V_2 -> V_8 -> V_17 . V_117 = 0 ;
}
if ( ! V_129 )
fprintf ( V_130 , L_23 ,
V_9 -> V_131 , V_127 ) ;
if ( ! V_126 ) {
F_78 ( V_2 , false ) ;
if ( F_79 ( & V_2 -> V_61 . V_89 ) )
F_73 ( V_2 , false ) ;
}
return V_53 ;
}
static void F_82 ( int T_6 V_15 ,
T_7 * V_132 ,
void * T_8 V_15 )
{
V_133 = V_132 -> V_134 . V_135 ;
V_43 = 1 ;
V_41 = 1 ;
}
int __weak
F_83 ( const struct V_136 * T_9 V_15 ,
struct V_10 * V_11 V_15 ,
T_10 T_11 V_15 ,
struct V_16 * V_16 V_15 )
{
return 0 ;
}
static const struct V_136 *
F_84 ( struct V_69 * V_64 )
{
if ( V_64 ) {
if ( V_64 -> V_66 && V_64 -> V_66 [ 0 ] . V_34 )
return V_64 -> V_66 [ 0 ] . V_34 ;
if ( V_64 -> V_99 && V_64 -> V_99 [ 0 ] . V_34 )
return V_64 -> V_99 [ 0 ] . V_34 ;
}
return NULL ;
}
static const struct V_136 * F_85 ( struct V_1 * V_2 )
{
const struct V_136 * T_9 ;
T_9 = F_84 ( V_2 -> V_64 ) ;
if ( T_9 )
return T_9 ;
return NULL ;
}
static int F_78 ( struct V_1 * V_2 , bool V_118 )
{
struct V_81 * V_8 = V_2 -> V_8 ;
struct V_16 * V_16 = & V_8 -> V_122 . V_123 ;
struct V_49 * V_9 = & V_2 -> V_9 ;
struct V_70 * V_61 = & V_2 -> V_61 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
int V_53 = F_27 ( V_9 ) ;
int V_54 = 0 ;
if ( V_2 -> V_61 . V_120 != V_118 )
return 0 ;
if ( V_9 -> V_116 ) {
V_54 = F_86 ( V_11 , V_8 ,
F_9 ) ;
if ( V_54 < 0 ) {
F_7 ( L_24 ) ;
goto V_38;
}
if ( F_69 ( & V_2 -> V_64 -> V_109 ) ) {
V_54 = F_87 ( V_11 , V_53 , V_2 -> V_64 ,
F_9 ) ;
if ( V_54 <= 0 ) {
F_7 ( L_25 ) ;
goto V_38;
}
V_2 -> V_6 += V_54 ;
}
}
V_54 = F_83 ( F_85 ( V_2 ) , V_11 ,
F_9 , V_16 ) ;
if ( V_54 )
goto V_38;
if ( V_2 -> V_61 . V_113 ) {
V_54 = F_88 ( V_2 -> V_60 , V_11 ,
V_8 , F_9 ) ;
if ( V_54 )
goto V_38;
}
V_54 = F_62 ( V_11 , F_9 ,
V_16 ) ;
F_15 ( V_54 < 0 , L_26
L_27
L_28 ) ;
V_54 = F_61 ( V_11 , F_9 ,
V_16 ) ;
F_15 ( V_54 < 0 , L_29
L_27
L_30 ) ;
if ( V_137 ) {
F_89 ( & V_8 -> V_122 ,
F_60 , V_11 ) ;
}
V_54 = F_90 ( V_16 , V_11 , & V_61 -> V_89 , V_2 -> V_64 -> V_87 ,
F_9 , V_61 -> V_124 ,
V_61 -> V_125 ) ;
V_38:
return V_54 ;
}
static int F_91 ( struct V_1 * V_2 , int V_138 , const char * * V_139 )
{
int V_54 ;
int V_140 = 0 ;
unsigned long V_141 = 0 ;
const bool V_142 = V_138 > 0 ;
struct V_16 * V_16 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_70 * V_61 = & V_2 -> V_61 ;
struct V_49 * V_9 = & V_2 -> V_9 ;
struct V_81 * V_8 ;
bool V_143 = false , V_144 = false ;
int V_53 ;
V_2 -> V_145 = V_139 [ 0 ] ;
atexit ( F_24 ) ;
signal ( V_40 , F_20 ) ;
signal ( V_146 , F_20 ) ;
signal ( V_147 , F_20 ) ;
signal ( V_148 , F_21 ) ;
if ( V_2 -> V_61 . V_149 )
V_11 -> V_150 = true ;
if ( V_2 -> V_61 . V_74 || V_2 -> V_3 . V_151 ) {
signal ( V_152 , V_153 ) ;
if ( V_2 -> V_61 . V_74 )
F_92 ( & V_67 ) ;
if ( V_2 -> V_3 . V_151 )
F_92 ( & V_4 ) ;
} else {
signal ( V_152 , V_154 ) ;
}
V_8 = F_93 ( V_9 , false , V_11 ) ;
if ( V_8 == NULL ) {
F_7 ( L_31 ) ;
return - 1 ;
}
V_53 = F_27 ( V_9 ) ;
V_2 -> V_8 = V_8 ;
F_66 ( V_2 ) ;
if ( V_142 ) {
V_54 = F_94 ( V_2 -> V_64 , & V_61 -> V_89 ,
V_139 , V_9 -> V_116 ,
F_82 ) ;
if ( V_54 < 0 ) {
F_7 ( L_32 ) ;
V_140 = V_54 ;
goto V_155;
}
}
if ( F_44 ( V_2 ) != 0 ) {
V_54 = - 1 ;
goto V_156;
}
V_54 = F_95 () ;
if ( V_54 ) {
char V_157 [ V_78 ] ;
F_96 ( V_54 , V_157 , sizeof( V_157 ) ) ;
F_7 ( L_33 ,
V_157 ) ;
goto V_156;
}
if ( V_2 -> V_11 . V_158 && ! F_97 ( V_2 -> V_64 ) ) {
F_98 ( L_34 ) ;
V_2 -> V_11 . V_158 = false ;
}
if ( ! V_2 -> V_64 -> V_159 )
F_68 ( & V_8 -> V_17 , V_160 ) ;
if ( V_9 -> V_116 ) {
V_54 = F_99 ( V_53 ) ;
if ( V_54 < 0 )
goto V_156;
} else {
V_54 = F_72 ( V_8 , V_2 -> V_64 , V_53 , false ) ;
if ( V_54 < 0 )
goto V_156;
}
if ( ! V_2 -> V_107
&& ! F_100 ( & V_8 -> V_17 , V_108 ) ) {
F_7 ( L_35
L_36 ) ;
V_54 = - 1 ;
goto V_156;
}
V_16 = & V_8 -> V_122 . V_123 ;
V_54 = F_78 ( V_2 , false ) ;
if ( V_54 < 0 )
goto V_156;
if ( V_2 -> V_161 ) {
struct V_162 V_163 ;
V_163 . V_164 = V_2 -> V_161 ;
if ( F_101 ( 0 , V_165 , & V_163 ) ) {
F_7 ( L_37 ) ;
V_54 = - 1 ;
goto V_156;
}
}
if ( ! F_79 ( & V_61 -> V_89 ) && ! V_61 -> V_166 )
F_102 ( V_2 -> V_64 ) ;
if ( V_142 ) {
union V_12 * V_13 ;
T_12 V_167 ;
V_13 = malloc ( sizeof( V_13 -> V_168 ) + V_16 -> V_169 ) ;
if ( V_13 == NULL ) {
V_54 = - V_170 ;
goto V_156;
}
V_167 = F_103 ( V_11 , V_13 ,
V_2 -> V_64 -> V_121 . V_97 ,
F_9 ,
V_16 ) ;
free ( V_13 ) ;
if ( V_167 == - 1 )
goto V_156;
V_13 = malloc ( sizeof( V_13 -> V_171 ) +
( V_172 * sizeof( struct V_173 ) ) +
V_16 -> V_169 ) ;
if ( V_13 == NULL ) {
V_54 = - V_170 ;
goto V_156;
}
F_104 ( V_11 , V_13 ,
V_2 -> V_64 -> V_121 . V_97 ,
V_167 , F_9 ,
V_16 ) ;
free ( V_13 ) ;
F_105 ( V_2 -> V_64 ) ;
}
if ( V_61 -> V_166 ) {
F_106 ( V_61 -> V_166 * V_174 ) ;
F_102 ( V_2 -> V_64 ) ;
}
F_38 ( & V_67 ) ;
F_38 ( & V_4 ) ;
F_107 () ;
for (; ; ) {
unsigned long long V_175 = V_2 -> V_37 ;
if ( F_108 ( & V_4 ) || V_43 || V_144 )
F_64 ( V_2 -> V_64 , V_101 ) ;
if ( F_65 ( V_2 ) < 0 ) {
F_36 ( & V_67 ) ;
F_36 ( & V_4 ) ;
V_54 = - 1 ;
goto V_156;
}
if ( V_176 ) {
V_176 = 0 ;
if ( ! F_109 ( & V_67 ) )
F_35 ( V_2 ) ;
if ( F_109 ( & V_67 ) ) {
F_7 ( L_38 ) ;
V_54 = - 1 ;
goto V_156;
}
}
if ( F_108 ( & V_4 ) ) {
if ( V_2 -> V_64 -> V_100 == V_177 )
continue;
F_38 ( & V_4 ) ;
F_64 ( V_2 -> V_64 , V_177 ) ;
if ( ! V_129 )
fprintf ( V_130 , L_39 ,
V_141 ) ;
V_141 = 0 ;
V_53 = F_77 ( V_2 , false ) ;
if ( V_53 < 0 ) {
F_7 ( L_40 ) ;
F_36 ( & V_4 ) ;
V_54 = V_53 ;
goto V_156;
}
if ( V_2 -> V_3 . time )
F_110 ( V_2 -> V_3 . time ) ;
}
if ( V_175 == V_2 -> V_37 ) {
if ( V_43 || V_144 )
break;
V_54 = F_111 ( V_2 -> V_64 , - 1 ) ;
if ( V_54 > 0 || ( V_54 < 0 && V_75 == V_178 ) )
V_54 = 0 ;
V_141 ++ ;
if ( F_112 ( V_2 -> V_64 , V_179 | V_180 ) == 0 )
V_144 = true ;
}
if ( V_43 && ! V_143 && ! F_79 ( & V_61 -> V_89 ) ) {
F_113 ( & V_67 ) ;
F_114 ( V_2 -> V_64 ) ;
V_143 = true ;
}
}
F_113 ( & V_67 ) ;
F_113 ( & V_4 ) ;
if ( V_142 && V_133 ) {
char V_71 [ V_181 ] ;
const char * V_182 = F_42 ( V_133 , V_71 , sizeof( V_71 ) ) ;
F_7 ( L_41 , V_182 ) ;
V_54 = - 1 ;
goto V_156;
}
if ( ! V_129 )
fprintf ( V_130 , L_42 , V_141 ) ;
if ( F_79 ( & V_2 -> V_61 . V_89 ) )
F_73 ( V_2 , true ) ;
V_156:
if ( V_142 ) {
int V_183 ;
if ( ! V_41 )
F_115 ( V_2 -> V_64 -> V_121 . V_97 , V_147 ) ;
F_116 ( & V_183 ) ;
if ( V_54 < 0 )
V_140 = V_54 ;
else if ( F_117 ( V_183 ) )
V_140 = F_118 ( V_183 ) ;
else if ( F_119 ( V_183 ) )
V_42 = F_120 ( V_183 ) ;
} else
V_140 = V_54 ;
F_78 ( V_2 , true ) ;
V_2 -> V_37 = 0 ;
if ( ! V_54 ) {
if ( ! V_2 -> V_184 ) {
F_70 ( V_2 ) ;
} else {
V_53 = F_77 ( V_2 , true ) ;
if ( V_53 < 0 ) {
V_140 = V_53 ;
goto V_155;
}
}
}
F_121 () ;
if ( ! V_54 && ! V_129 ) {
char V_37 [ 128 ] ;
const char * V_185 = V_2 -> V_184 ?
L_43 : L_44 ;
if ( V_2 -> V_37 && ! V_2 -> V_61 . V_113 )
F_122 ( V_37 , sizeof( V_37 ) ,
L_45 V_186 L_46 , V_2 -> V_37 ) ;
else
V_37 [ 0 ] = '\0' ;
fprintf ( V_130 , L_47 ,
F_123 ( V_9 ) / 1024.0 / 1024.0 ,
V_9 -> V_131 , V_185 , V_37 ) ;
}
V_155:
F_124 ( V_8 ) ;
return V_140 ;
}
static void F_125 ( struct V_84 * V_187 )
{
static const char * V_188 [ V_189 ] = { L_48 , L_49 , L_50 , L_51 } ;
F_13 ( L_52 , V_188 [ V_187 -> V_190 ] ) ;
if ( V_187 -> V_190 == V_191 )
F_13 ( L_53 ,
V_187 -> V_192 ) ;
}
int F_126 ( struct V_70 * V_1 ,
struct V_84 * V_187 ,
const char * V_193 , bool V_194 )
{
int V_59 ;
V_187 -> V_151 = ! V_194 ;
if ( V_194 ) {
V_187 -> V_190 = V_195 ;
F_13 ( L_54 ) ;
return 0 ;
}
V_59 = F_127 ( V_193 , V_187 ) ;
if ( ! V_59 ) {
if ( V_187 -> V_190 == V_191 )
V_1 -> V_124 = true ;
F_125 ( V_187 ) ;
}
return V_59 ;
}
int F_128 ( const struct V_196 * V_197 ,
const char * V_193 ,
int V_194 )
{
return F_126 ( V_197 -> V_198 , & V_84 , V_193 , V_194 ) ;
}
int F_129 ( const struct V_196 * V_197 ,
const char * V_193 V_15 ,
int V_194 V_15 )
{
struct V_84 * V_187 = V_197 -> V_198 ;
V_187 -> V_151 = true ;
if ( V_187 -> V_190 == V_195 )
V_187 -> V_190 = V_199 ;
F_125 ( V_187 ) ;
return 0 ;
}
static int F_130 ( const char * V_200 , const char * V_198 , void * V_201 )
{
struct V_1 * V_2 = V_201 ;
if ( ! strcmp ( V_200 , L_55 ) ) {
if ( ! strcmp ( V_198 , L_56 ) )
V_2 -> V_202 = false ;
else if ( ! strcmp ( V_198 , L_57 ) )
V_2 -> V_202 = true ;
else if ( ! strcmp ( V_198 , L_58 ) )
V_2 -> V_107 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_200 , L_59 ) )
V_200 = L_60 ;
return F_131 ( V_200 , V_198 , V_201 ) ;
}
static int F_132 ( const struct V_196 * V_197 , const char * V_188 , int V_194 )
{
struct V_70 * V_61 = (struct V_70 * ) V_197 -> V_198 ;
const struct V_203 * V_204 ;
const char * V_205 = V_188 ;
if ( V_194 ) {
V_61 -> V_206 = 0 ;
return 0 ;
}
if ( ! V_188 )
return 0 ;
if ( V_61 -> V_206 )
return - 1 ;
V_61 -> V_206 = true ;
if ( sscanf ( V_188 , L_61 , & V_61 -> V_207 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_188 , L_62 , 6 ) )
V_188 += 6 ;
for ( V_204 = V_208 ; V_204 -> V_209 ; V_204 ++ ) {
if ( ! strcasecmp ( V_188 , V_204 -> V_209 ) ) {
V_61 -> V_207 = V_204 -> V_207 ;
return 0 ;
}
}
V_61 -> V_206 = false ;
F_49 ( L_63 , V_205 ) ;
return - 1 ;
}
static int F_133 ( const struct V_196 * V_197 ,
const char * V_188 ,
int V_194 V_15 )
{
struct V_70 * V_61 = V_197 -> V_198 ;
char * V_210 , * V_211 ;
unsigned int V_72 ;
int V_59 ;
if ( ! V_188 )
return - V_77 ;
V_210 = F_134 ( V_188 ) ;
if ( ! V_210 )
return - V_170 ;
V_211 = strchr ( V_210 , ',' ) ;
if ( V_211 )
* V_211 = '\0' ;
if ( * V_210 ) {
V_59 = F_135 ( & V_72 , V_210 ) ;
if ( V_59 )
goto V_212;
V_61 -> V_72 = V_72 ;
}
if ( ! V_211 ) {
V_59 = 0 ;
goto V_212;
}
V_59 = F_135 ( & V_72 , V_211 + 1 ) ;
if ( V_59 )
goto V_212;
V_61 -> V_73 = V_72 ;
V_212:
free ( V_210 ) ;
return V_59 ;
}
static void F_136 ( struct V_1 * V_2 )
{
T_3 V_213 = F_137 ( V_2 -> V_61 . V_72 ) ;
struct V_3 * V_210 = & V_2 -> V_3 ;
V_213 /= 2 ;
if ( V_210 -> V_5 < V_213 ) {
char V_18 [ 100 ] ;
F_138 ( V_18 , sizeof( V_18 ) , V_213 ) ;
F_98 ( L_64
L_65
L_66 , V_18 ) ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_210 = & V_2 -> V_3 ;
static struct V_214 V_215 [] = {
{ . V_216 = 'B' , . V_217 = 1 } ,
{ . V_216 = 'K' , . V_217 = 1 << 10 } ,
{ . V_216 = 'M' , . V_217 = 1 << 20 } ,
{ . V_216 = 'G' , . V_217 = 1 << 30 } ,
{ . V_216 = 0 } ,
} ;
static struct V_214 V_218 [] = {
{ . V_216 = 's' , . V_217 = 1 } ,
{ . V_216 = 'm' , . V_217 = 60 } ,
{ . V_216 = 'h' , . V_217 = 60 * 60 } ,
{ . V_216 = 'd' , . V_217 = 60 * 60 * 24 } ,
{ . V_216 = 0 } ,
} ;
unsigned long V_91 ;
if ( ! V_210 -> V_219 )
return 0 ;
if ( ! strcmp ( V_210 -> V_188 , L_67 ) ) {
V_210 -> signal = true ;
F_13 ( L_68 ) ;
goto V_151;
}
V_91 = F_140 ( V_210 -> V_188 , V_215 ) ;
if ( V_91 != ( unsigned long ) - 1 ) {
V_210 -> V_5 = V_91 ;
F_13 ( L_69 , V_210 -> V_188 ) ;
goto V_151;
}
V_91 = F_140 ( V_210 -> V_188 , V_218 ) ;
if ( V_91 != ( unsigned long ) - 1 ) {
V_210 -> time = V_91 ;
F_13 ( L_70 ,
V_210 -> V_188 , V_210 -> time ) ;
goto V_151;
}
return - 1 ;
V_151:
V_2 -> V_184 = true ;
V_210 -> V_151 = true ;
if ( V_210 -> V_5 && ! V_2 -> V_61 . V_220 )
F_136 ( V_2 ) ;
return 0 ;
}
int F_141 ( int V_138 , const char * * V_139 )
{
int V_54 ;
struct V_1 * V_2 = & V_1 ;
char V_157 [ V_78 ] ;
#ifndef F_142
# define F_143 ( V_210 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_143 ( '\0' , L_71 , true ) ;
F_143 ( '\0' , L_72 , true ) ;
# undef F_143
#endif
#ifndef F_144
# if ! F_145 ( V_221 )
# define F_146 "NO_DWARF=1"
# elif ! F_145 ( F_142 )
# define F_146 "NO_LIBBPF=1"
# else
# define F_146 "this architecture doesn't support BPF prologue"
# endif
# define F_143 ( V_210 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_143 ( '\0' , L_73 , true ) ;
# undef F_143
# undef F_146
#endif
V_2 -> V_64 = F_147 () ;
if ( V_2 -> V_64 == NULL )
return - V_170 ;
V_54 = F_148 ( F_130 , V_2 ) ;
if ( V_54 )
return V_54 ;
V_138 = F_149 ( V_138 , V_139 , V_222 , V_223 ,
V_224 ) ;
if ( V_129 )
F_150 () ;
if ( ! V_138 && F_79 ( & V_2 -> V_61 . V_89 ) )
V_2 -> V_61 . V_89 . V_225 = true ;
if ( V_226 && ! V_2 -> V_61 . V_89 . V_225 ) {
F_151 ( V_223 , V_222 ,
L_74 ) ;
}
if ( V_2 -> V_61 . V_227 &&
! F_152 () ) {
F_51 ( L_75 ) ;
F_153 ( V_223 , V_222 , L_76 , 0 ) ;
return - V_77 ;
}
if ( F_139 ( V_2 ) ) {
F_153 ( V_223 , V_222 , L_77 , 0 ) ;
return - V_77 ;
}
if ( V_2 -> V_3 . time ) {
signal ( V_228 , V_229 ) ;
F_110 ( V_2 -> V_3 . time ) ;
}
if ( ! V_2 -> V_60 ) {
V_2 -> V_60 = F_154 ( V_2 -> V_64 , & V_54 ) ;
if ( V_54 )
goto V_38;
}
V_54 = F_155 ( V_2 -> V_60 , & V_2 -> V_61 ,
V_2 -> V_61 . V_230 ) ;
if ( V_54 )
goto V_38;
V_94 . V_231 = true ;
F_156 ( NULL ) ;
V_54 = F_157 ( V_2 -> V_64 ) ;
if ( V_54 )
goto V_38;
if ( V_232 )
goto V_38;
V_54 = F_158 ( V_2 -> V_64 ) ;
if ( V_54 ) {
F_159 ( V_2 -> V_64 , V_54 , V_157 , sizeof( V_157 ) ) ;
F_7 ( L_78 ,
V_157 ) ;
goto V_38;
}
V_54 = - V_170 ;
if ( V_94 . V_233 )
F_98 (
L_79
L_80
L_81
L_82
L_83
L_84
L_85 ) ;
if ( V_2 -> V_202 || V_2 -> V_107 ) {
F_160 () ;
} else if ( V_2 -> V_3 . V_151 ) {
bool V_234 = true ;
if ( V_2 -> V_235 && ! V_2 -> V_107 )
V_234 = false ;
if ( V_2 -> V_236 && ! V_2 -> V_202 )
V_234 = false ;
if ( V_234 ) {
V_2 -> V_107 = true ;
V_2 -> V_202 = true ;
F_160 () ;
}
}
if ( V_1 . V_61 . V_32 )
V_1 . V_61 . V_120 = true ;
if ( V_2 -> V_64 -> V_237 == 0 &&
F_161 ( V_2 -> V_64 ) < 0 ) {
F_7 ( L_86 ) ;
goto V_38;
}
if ( V_2 -> V_61 . V_89 . V_238 && ! V_2 -> V_61 . V_239 )
V_2 -> V_61 . V_240 = true ;
V_54 = F_162 ( & V_2 -> V_61 . V_89 ) ;
if ( V_54 ) {
F_163 ( & V_2 -> V_61 . V_89 , V_54 , V_157 , V_78 ) ;
F_49 ( L_87 , V_157 ) ;
}
V_54 = F_164 ( & V_2 -> V_61 . V_89 ) ;
if ( V_54 ) {
int V_241 = V_75 ;
F_163 ( & V_2 -> V_61 . V_89 , V_54 , V_157 , V_78 ) ;
F_51 ( L_87 , V_157 ) ;
V_54 = - V_241 ;
goto V_38;
}
V_2 -> V_61 . V_242 = V_2 -> V_61 . V_89 . V_243 != V_244 ;
V_54 = - V_170 ;
if ( F_165 ( V_2 -> V_64 , & V_2 -> V_61 . V_89 ) < 0 )
F_166 ( V_223 , V_222 ) ;
V_54 = F_167 ( V_2 -> V_60 , V_2 -> V_64 , & V_2 -> V_61 ) ;
if ( V_54 )
goto V_38;
if ( V_2 -> V_61 . V_113 )
V_2 -> V_96 = true ;
if ( F_168 ( & V_2 -> V_61 ) ) {
V_54 = - V_77 ;
goto V_38;
}
V_54 = F_91 ( & V_1 , V_138 , V_139 ) ;
V_38:
F_169 ( V_2 -> V_64 ) ;
F_170 () ;
F_171 ( V_2 -> V_60 ) ;
return V_54 ;
}
static void V_153 ( int V_39 V_15 )
{
struct V_1 * V_2 = & V_1 ;
if ( F_2 ( & V_67 ) ) {
F_8 ( & V_67 ) ;
V_176 = 1 ;
if ( F_39 ( V_1 . V_60 ) )
F_36 ( & V_67 ) ;
}
if ( F_1 ( V_2 ) )
F_8 ( & V_4 ) ;
}
static void V_229 ( int V_39 V_15 )
{
struct V_1 * V_2 = & V_1 ;
if ( F_4 ( V_2 ) )
F_8 ( & V_4 ) ;
}
