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
error ( L_17 ,
V_80 -> V_90 , F_53 ( V_80 ) , V_75 ,
F_42 ( V_75 , V_71 , sizeof( V_71 ) ) ) ;
V_36 = - 1 ;
goto V_38;
}
if ( F_54 ( V_64 , & V_80 , & V_83 ) ) {
error ( L_18 ,
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
if ( V_2 -> V_61 . V_74 || V_2 -> V_3 . V_149 ) {
signal ( V_150 , V_151 ) ;
if ( V_2 -> V_61 . V_74 )
F_92 ( & V_67 ) ;
if ( V_2 -> V_3 . V_149 )
F_92 ( & V_4 ) ;
} else {
signal ( V_150 , V_152 ) ;
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
goto V_153;
}
}
if ( F_44 ( V_2 ) != 0 ) {
V_54 = - 1 ;
goto V_154;
}
V_54 = F_95 () ;
if ( V_54 ) {
char V_155 [ V_78 ] ;
F_96 ( V_54 , V_155 , sizeof( V_155 ) ) ;
F_7 ( L_33 ,
V_155 ) ;
goto V_154;
}
if ( V_2 -> V_11 . V_156 && ! F_97 ( V_2 -> V_64 ) ) {
F_98 ( L_34 ) ;
V_2 -> V_11 . V_156 = false ;
}
if ( ! V_2 -> V_64 -> V_157 )
F_68 ( & V_8 -> V_17 , V_158 ) ;
if ( V_9 -> V_116 ) {
V_54 = F_99 ( V_53 ) ;
if ( V_54 < 0 )
goto V_154;
} else {
V_54 = F_72 ( V_8 , V_2 -> V_64 , V_53 , false ) ;
if ( V_54 < 0 )
goto V_154;
}
if ( ! V_2 -> V_107
&& ! F_100 ( & V_8 -> V_17 , V_108 ) ) {
F_7 ( L_35
L_36 ) ;
V_54 = - 1 ;
goto V_154;
}
V_16 = & V_8 -> V_122 . V_123 ;
V_54 = F_78 ( V_2 , false ) ;
if ( V_54 < 0 )
goto V_154;
if ( V_2 -> V_159 ) {
struct V_160 V_161 ;
V_161 . V_162 = V_2 -> V_159 ;
if ( F_101 ( 0 , V_163 , & V_161 ) ) {
F_7 ( L_37 ) ;
V_54 = - 1 ;
goto V_154;
}
}
if ( ! F_79 ( & V_61 -> V_89 ) && ! V_61 -> V_164 )
F_102 ( V_2 -> V_64 ) ;
if ( V_142 ) {
union V_12 * V_13 ;
V_13 = malloc ( sizeof( V_13 -> V_165 ) + V_16 -> V_166 ) ;
if ( V_13 == NULL ) {
V_54 = - V_167 ;
goto V_154;
}
F_103 ( V_11 , V_13 ,
V_2 -> V_64 -> V_121 . V_97 ,
F_9 ,
V_16 ) ;
free ( V_13 ) ;
F_104 ( V_2 -> V_64 ) ;
}
if ( V_61 -> V_164 ) {
F_105 ( V_61 -> V_164 * V_168 ) ;
F_102 ( V_2 -> V_64 ) ;
}
F_38 ( & V_67 ) ;
F_38 ( & V_4 ) ;
F_106 () ;
for (; ; ) {
unsigned long long V_169 = V_2 -> V_37 ;
if ( F_107 ( & V_4 ) || V_43 || V_144 )
F_64 ( V_2 -> V_64 , V_101 ) ;
if ( F_65 ( V_2 ) < 0 ) {
F_36 ( & V_67 ) ;
F_36 ( & V_4 ) ;
V_54 = - 1 ;
goto V_154;
}
if ( V_170 ) {
V_170 = 0 ;
if ( ! F_108 ( & V_67 ) )
F_35 ( V_2 ) ;
if ( F_108 ( & V_67 ) ) {
F_7 ( L_38 ) ;
V_54 = - 1 ;
goto V_154;
}
}
if ( F_107 ( & V_4 ) ) {
if ( V_2 -> V_64 -> V_100 == V_171 )
continue;
F_38 ( & V_4 ) ;
F_64 ( V_2 -> V_64 , V_171 ) ;
if ( ! V_129 )
fprintf ( V_130 , L_39 ,
V_141 ) ;
V_141 = 0 ;
V_53 = F_77 ( V_2 , false ) ;
if ( V_53 < 0 ) {
F_7 ( L_40 ) ;
F_36 ( & V_4 ) ;
V_54 = V_53 ;
goto V_154;
}
if ( V_2 -> V_3 . time )
F_109 ( V_2 -> V_3 . time ) ;
}
if ( V_169 == V_2 -> V_37 ) {
if ( V_43 || V_144 )
break;
V_54 = F_110 ( V_2 -> V_64 , - 1 ) ;
if ( V_54 > 0 || ( V_54 < 0 && V_75 == V_172 ) )
V_54 = 0 ;
V_141 ++ ;
if ( F_111 ( V_2 -> V_64 , V_173 | V_174 ) == 0 )
V_144 = true ;
}
if ( V_43 && ! V_143 && ! F_79 ( & V_61 -> V_89 ) ) {
F_112 ( & V_67 ) ;
F_113 ( V_2 -> V_64 ) ;
V_143 = true ;
}
}
F_112 ( & V_67 ) ;
F_112 ( & V_4 ) ;
if ( V_142 && V_133 ) {
char V_71 [ V_175 ] ;
const char * V_176 = F_42 ( V_133 , V_71 , sizeof( V_71 ) ) ;
F_7 ( L_41 , V_176 ) ;
V_54 = - 1 ;
goto V_154;
}
if ( ! V_129 )
fprintf ( V_130 , L_42 , V_141 ) ;
if ( F_79 ( & V_2 -> V_61 . V_89 ) )
F_73 ( V_2 , true ) ;
V_154:
if ( V_142 ) {
int V_177 ;
if ( ! V_41 )
F_114 ( V_2 -> V_64 -> V_121 . V_97 , V_147 ) ;
F_115 ( & V_177 ) ;
if ( V_54 < 0 )
V_140 = V_54 ;
else if ( F_116 ( V_177 ) )
V_140 = F_117 ( V_177 ) ;
else if ( F_118 ( V_177 ) )
V_42 = F_119 ( V_177 ) ;
} else
V_140 = V_54 ;
F_78 ( V_2 , true ) ;
V_2 -> V_37 = 0 ;
if ( ! V_54 ) {
if ( ! V_2 -> V_178 ) {
F_70 ( V_2 ) ;
} else {
V_53 = F_77 ( V_2 , true ) ;
if ( V_53 < 0 ) {
V_140 = V_53 ;
goto V_153;
}
}
}
F_120 () ;
if ( ! V_54 && ! V_129 ) {
char V_37 [ 128 ] ;
const char * V_179 = V_2 -> V_178 ?
L_43 : L_44 ;
if ( V_2 -> V_37 && ! V_2 -> V_61 . V_113 )
F_121 ( V_37 , sizeof( V_37 ) ,
L_45 V_180 L_46 , V_2 -> V_37 ) ;
else
V_37 [ 0 ] = '\0' ;
fprintf ( V_130 , L_47 ,
F_122 ( V_9 ) / 1024.0 / 1024.0 ,
V_9 -> V_131 , V_179 , V_37 ) ;
}
V_153:
F_123 ( V_8 ) ;
return V_140 ;
}
static void F_124 ( struct V_84 * V_181 )
{
static const char * V_182 [ V_183 ] = { L_48 , L_49 , L_50 , L_51 } ;
F_13 ( L_52 , V_182 [ V_181 -> V_184 ] ) ;
if ( V_181 -> V_184 == V_185 )
F_13 ( L_53 ,
V_181 -> V_186 ) ;
}
int F_125 ( struct V_70 * V_1 ,
struct V_84 * V_181 ,
const char * V_187 , bool V_188 )
{
int V_59 ;
V_181 -> V_149 = ! V_188 ;
if ( V_188 ) {
V_181 -> V_184 = V_189 ;
F_13 ( L_54 ) ;
return 0 ;
}
V_59 = F_126 ( V_187 , V_181 ) ;
if ( ! V_59 ) {
if ( V_181 -> V_184 == V_185 )
V_1 -> V_124 = true ;
F_124 ( V_181 ) ;
}
return V_59 ;
}
int F_127 ( const struct V_190 * V_191 ,
const char * V_187 ,
int V_188 )
{
return F_125 ( V_191 -> V_192 , & V_84 , V_187 , V_188 ) ;
}
int F_128 ( const struct V_190 * V_191 ,
const char * V_187 V_15 ,
int V_188 V_15 )
{
struct V_84 * V_181 = V_191 -> V_192 ;
V_181 -> V_149 = true ;
if ( V_181 -> V_184 == V_189 )
V_181 -> V_184 = V_193 ;
F_124 ( V_181 ) ;
return 0 ;
}
static int F_129 ( const char * V_194 , const char * V_192 , void * V_195 )
{
struct V_1 * V_2 = V_195 ;
if ( ! strcmp ( V_194 , L_55 ) ) {
if ( ! strcmp ( V_192 , L_56 ) )
V_2 -> V_196 = false ;
else if ( ! strcmp ( V_192 , L_57 ) )
V_2 -> V_196 = true ;
else if ( ! strcmp ( V_192 , L_58 ) )
V_2 -> V_107 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_194 , L_59 ) )
V_194 = L_60 ;
return F_130 ( V_194 , V_192 , V_195 ) ;
}
static int F_131 ( const struct V_190 * V_191 , const char * V_182 , int V_188 )
{
struct V_70 * V_61 = (struct V_70 * ) V_191 -> V_192 ;
const struct V_197 * V_198 ;
const char * V_199 = V_182 ;
if ( V_188 ) {
V_61 -> V_200 = 0 ;
return 0 ;
}
if ( ! V_182 )
return 0 ;
if ( V_61 -> V_200 )
return - 1 ;
V_61 -> V_200 = true ;
if ( sscanf ( V_182 , L_61 , & V_61 -> V_201 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_182 , L_62 , 6 ) )
V_182 += 6 ;
for ( V_198 = V_202 ; V_198 -> V_203 ; V_198 ++ ) {
if ( ! strcasecmp ( V_182 , V_198 -> V_203 ) ) {
V_61 -> V_201 = V_198 -> V_201 ;
return 0 ;
}
}
V_61 -> V_200 = false ;
F_49 ( L_63 , V_199 ) ;
return - 1 ;
}
static int F_132 ( const struct V_190 * V_191 ,
const char * V_182 ,
int V_188 V_15 )
{
struct V_70 * V_61 = V_191 -> V_192 ;
char * V_204 , * V_205 ;
unsigned int V_72 ;
int V_59 ;
if ( ! V_182 )
return - V_77 ;
V_204 = F_133 ( V_182 ) ;
if ( ! V_204 )
return - V_167 ;
V_205 = strchr ( V_204 , ',' ) ;
if ( V_205 )
* V_205 = '\0' ;
if ( * V_204 ) {
V_59 = F_134 ( & V_72 , V_204 ) ;
if ( V_59 )
goto V_206;
V_61 -> V_72 = V_72 ;
}
if ( ! V_205 ) {
V_59 = 0 ;
goto V_206;
}
V_59 = F_134 ( & V_72 , V_205 + 1 ) ;
if ( V_59 )
goto V_206;
V_61 -> V_73 = V_72 ;
V_206:
free ( V_204 ) ;
return V_59 ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_3 V_207 = F_136 ( V_2 -> V_61 . V_72 ) ;
struct V_3 * V_204 = & V_2 -> V_3 ;
V_207 /= 2 ;
if ( V_204 -> V_5 < V_207 ) {
char V_18 [ 100 ] ;
F_137 ( V_18 , sizeof( V_18 ) , V_207 ) ;
F_98 ( L_64
L_65
L_66 , V_18 ) ;
}
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_204 = & V_2 -> V_3 ;
static struct V_208 V_209 [] = {
{ . V_210 = 'B' , . V_211 = 1 } ,
{ . V_210 = 'K' , . V_211 = 1 << 10 } ,
{ . V_210 = 'M' , . V_211 = 1 << 20 } ,
{ . V_210 = 'G' , . V_211 = 1 << 30 } ,
{ . V_210 = 0 } ,
} ;
static struct V_208 V_212 [] = {
{ . V_210 = 's' , . V_211 = 1 } ,
{ . V_210 = 'm' , . V_211 = 60 } ,
{ . V_210 = 'h' , . V_211 = 60 * 60 } ,
{ . V_210 = 'd' , . V_211 = 60 * 60 * 24 } ,
{ . V_210 = 0 } ,
} ;
unsigned long V_91 ;
if ( ! V_204 -> V_213 )
return 0 ;
if ( ! strcmp ( V_204 -> V_182 , L_67 ) ) {
V_204 -> signal = true ;
F_13 ( L_68 ) ;
goto V_149;
}
V_91 = F_139 ( V_204 -> V_182 , V_209 ) ;
if ( V_91 != ( unsigned long ) - 1 ) {
V_204 -> V_5 = V_91 ;
F_13 ( L_69 , V_204 -> V_182 ) ;
goto V_149;
}
V_91 = F_139 ( V_204 -> V_182 , V_212 ) ;
if ( V_91 != ( unsigned long ) - 1 ) {
V_204 -> time = V_91 ;
F_13 ( L_70 ,
V_204 -> V_182 , V_204 -> time ) ;
goto V_149;
}
return - 1 ;
V_149:
V_2 -> V_178 = true ;
V_204 -> V_149 = true ;
if ( V_204 -> V_5 && ! V_2 -> V_61 . V_214 )
F_135 ( V_2 ) ;
return 0 ;
}
int F_140 ( int V_138 , const char * * V_139 , const char * T_12 V_15 )
{
int V_54 ;
struct V_1 * V_2 = & V_1 ;
char V_155 [ V_78 ] ;
#ifndef F_141
# define F_142 ( V_204 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_142 ( '\0' , L_71 , true ) ;
F_142 ( '\0' , L_72 , true ) ;
# undef F_142
#endif
#ifndef F_143
# if ! F_144 ( V_215 )
# define F_145 "NO_DWARF=1"
# elif ! F_144 ( F_141 )
# define F_145 "NO_LIBBPF=1"
# else
# define F_145 "this architecture doesn't support BPF prologue"
# endif
# define F_142 ( V_204 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_142 ( '\0' , L_73 , true ) ;
# undef F_142
# undef F_145
#endif
V_2 -> V_64 = F_146 () ;
if ( V_2 -> V_64 == NULL )
return - V_167 ;
V_54 = F_147 ( F_129 , V_2 ) ;
if ( V_54 )
return V_54 ;
V_138 = F_148 ( V_138 , V_139 , V_216 , V_217 ,
V_218 ) ;
if ( V_129 )
F_149 () ;
if ( ! V_138 && F_79 ( & V_2 -> V_61 . V_89 ) )
V_2 -> V_61 . V_89 . V_219 = true ;
if ( V_220 && ! V_2 -> V_61 . V_89 . V_219 ) {
F_150 ( V_217 , V_216 ,
L_74 ) ;
}
if ( V_2 -> V_61 . V_221 &&
! F_151 () ) {
F_51 ( L_75 ) ;
F_152 ( V_217 , V_216 , L_76 , 0 ) ;
return - V_77 ;
}
if ( F_138 ( V_2 ) ) {
F_152 ( V_217 , V_216 , L_77 , 0 ) ;
return - V_77 ;
}
if ( V_2 -> V_3 . time ) {
signal ( V_222 , V_223 ) ;
F_109 ( V_2 -> V_3 . time ) ;
}
if ( ! V_2 -> V_60 ) {
V_2 -> V_60 = F_153 ( V_2 -> V_64 , & V_54 ) ;
if ( V_54 )
goto V_38;
}
V_54 = F_154 ( V_2 -> V_60 , & V_2 -> V_61 ,
V_2 -> V_61 . V_224 ) ;
if ( V_54 )
goto V_38;
V_94 . V_225 = true ;
F_155 ( NULL ) ;
V_54 = F_156 ( V_2 -> V_64 ) ;
if ( V_54 )
goto V_38;
if ( V_226 )
goto V_38;
V_54 = F_157 ( V_2 -> V_64 ) ;
if ( V_54 ) {
F_158 ( V_2 -> V_64 , V_54 , V_155 , sizeof( V_155 ) ) ;
F_7 ( L_78 ,
V_155 ) ;
goto V_38;
}
V_54 = - V_167 ;
if ( V_94 . V_227 )
F_98 (
L_79
L_80
L_81
L_82
L_83
L_84
L_85 ) ;
if ( V_2 -> V_196 || V_2 -> V_107 ) {
F_159 () ;
} else if ( V_2 -> V_3 . V_149 ) {
bool V_228 = true ;
if ( V_2 -> V_229 && ! V_2 -> V_107 )
V_228 = false ;
if ( V_2 -> V_230 && ! V_2 -> V_196 )
V_228 = false ;
if ( V_228 ) {
V_2 -> V_107 = true ;
V_2 -> V_196 = true ;
F_159 () ;
}
}
if ( V_1 . V_61 . V_32 )
V_1 . V_61 . V_120 = true ;
if ( V_2 -> V_64 -> V_231 == 0 &&
F_160 ( V_2 -> V_64 ) < 0 ) {
F_7 ( L_86 ) ;
goto V_38;
}
if ( V_2 -> V_61 . V_89 . V_232 && ! V_2 -> V_61 . V_233 )
V_2 -> V_61 . V_234 = true ;
V_54 = F_161 ( & V_2 -> V_61 . V_89 ) ;
if ( V_54 ) {
F_162 ( & V_2 -> V_61 . V_89 , V_54 , V_155 , V_78 ) ;
F_49 ( L_87 , V_155 ) ;
}
V_54 = F_163 ( & V_2 -> V_61 . V_89 ) ;
if ( V_54 ) {
int V_235 = V_75 ;
F_162 ( & V_2 -> V_61 . V_89 , V_54 , V_155 , V_78 ) ;
F_51 ( L_87 , V_155 ) ;
V_54 = - V_235 ;
goto V_38;
}
V_2 -> V_61 . V_236 = V_2 -> V_61 . V_89 . V_237 != V_238 ;
V_54 = - V_167 ;
if ( F_164 ( V_2 -> V_64 , & V_2 -> V_61 . V_89 ) < 0 )
F_165 ( V_217 , V_216 ) ;
V_54 = F_166 ( V_2 -> V_60 , V_2 -> V_64 , & V_2 -> V_61 ) ;
if ( V_54 )
goto V_38;
if ( V_2 -> V_61 . V_113 )
V_2 -> V_96 = true ;
if ( F_167 ( & V_2 -> V_61 ) ) {
V_54 = - V_77 ;
goto V_38;
}
V_54 = F_91 ( & V_1 , V_138 , V_139 ) ;
V_38:
F_168 ( V_2 -> V_64 ) ;
F_169 () ;
F_170 ( V_2 -> V_60 ) ;
return V_54 ;
}
static void V_151 ( int V_39 V_15 )
{
struct V_1 * V_2 = & V_1 ;
if ( F_2 ( & V_67 ) ) {
F_8 ( & V_67 ) ;
V_170 = 1 ;
if ( F_39 ( V_1 . V_60 ) )
F_36 ( & V_67 ) ;
}
if ( F_1 ( V_2 ) )
F_8 ( & V_4 ) ;
}
static void V_223 ( int V_39 V_15 )
{
struct V_1 * V_2 = & V_1 ;
if ( F_4 ( V_2 ) )
F_8 ( & V_4 ) ;
}
