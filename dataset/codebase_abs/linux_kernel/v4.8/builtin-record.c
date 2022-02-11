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
int V_34 = 0 ;
F_37 ( V_62 , V_59 , & V_79 ) ;
F_38 (evlist, pos) {
V_80:
if ( F_39 ( V_77 , V_77 -> V_81 , V_77 -> V_82 ) < 0 ) {
if ( F_40 ( V_77 , V_73 , V_69 , sizeof( V_69 ) ) ) {
if ( V_83 )
F_41 ( L_16 , V_69 ) ;
goto V_80;
}
V_34 = - V_73 ;
F_42 ( V_77 , & V_59 -> V_84 ,
V_73 , V_69 , sizeof( V_69 ) ) ;
F_43 ( L_16 , V_69 ) ;
goto V_36;
}
}
if ( F_44 ( V_62 , & V_77 ) ) {
error ( L_17 ,
V_77 -> V_85 , F_45 ( V_77 ) , V_73 ,
F_34 ( V_73 , V_69 , sizeof( V_69 ) ) ) ;
V_34 = - 1 ;
goto V_36;
}
V_34 = F_35 ( V_2 ) ;
if ( V_34 )
goto V_36;
V_5 -> V_62 = V_62 ;
F_46 ( V_5 ) ;
V_36:
return V_34 ;
}
static int F_47 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_76 * V_86 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_35 ++ ;
return F_48 ( V_9 , V_11 , T_2 , V_86 , V_14 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_78 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_87 . V_88 = true ;
if ( V_2 -> V_89 )
V_2 -> V_9 . T_2 = NULL ;
return F_50 ( V_5 ) ;
}
static void F_51 ( struct V_14 * V_14 , void * V_25 )
{
int V_52 ;
struct V_8 * V_9 = V_25 ;
V_52 = F_52 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_18
L_19 , V_14 -> V_90 ) ;
V_52 = F_53 ( V_9 , F_4 ,
V_14 ) ;
if ( V_52 < 0 )
F_3 ( L_18
L_19 , V_14 -> V_90 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_67 * V_62 ,
bool V_27 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_61 ;
int V_34 = 0 ;
struct V_28 * V_91 ;
if ( ! V_62 )
return 0 ;
V_91 = V_27 ? V_62 -> V_92 : V_62 -> V_64 ;
if ( ! V_91 )
return 0 ;
if ( V_27 && V_62 -> V_93 != V_94 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_62 -> V_63 ; V_61 ++ ) {
struct V_55 * V_56 = & V_91 [ V_61 ] . V_55 ;
if ( V_91 [ V_61 ] . V_32 ) {
if ( F_12 ( V_2 , & V_91 [ V_61 ] ,
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
V_34 = F_1 ( V_2 , & V_95 , sizeof( V_95 ) ) ;
if ( V_27 )
F_55 ( V_62 , V_96 ) ;
V_36:
return V_34 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_54 ( V_2 , V_2 -> V_62 , false ) ;
if ( V_52 )
return V_52 ;
return F_54 ( V_2 , V_2 -> V_62 , true ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
int V_97 ;
for ( V_97 = V_98 ; V_97 < V_99 ; V_97 ++ )
F_58 ( & V_5 -> V_15 , V_97 ) ;
if ( V_2 -> V_100 )
F_59 ( & V_5 -> V_15 , V_101 ) ;
if ( ! F_60 ( & V_2 -> V_62 -> V_102 ) )
F_59 ( & V_5 -> V_15 , V_103 ) ;
if ( ! V_2 -> V_59 . V_104 )
F_59 ( & V_5 -> V_15 , V_105 ) ;
if ( ! V_2 -> V_59 . V_106 )
F_59 ( & V_5 -> V_15 , V_107 ) ;
F_59 ( & V_5 -> V_15 , V_108 ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 = F_19 ( V_6 ) ;
if ( V_6 -> V_109 )
return;
V_2 -> V_5 -> V_15 . V_110 += V_2 -> V_7 ;
V_6 -> V_4 = F_20 ( F_19 ( V_6 ) , 0 , V_53 ) ;
if ( ! V_2 -> V_100 ) {
F_49 ( V_2 ) ;
if ( V_2 -> V_89 )
F_62 ( V_2 -> V_5 ) ;
}
F_63 ( V_2 -> V_5 , V_2 -> V_62 , V_51 , true ) ;
return;
}
static int F_64 ( struct V_1 * V_2 , bool V_111 )
{
struct {
struct V_112 V_113 ;
struct V_114 V_115 ;
} V_112 ;
if ( V_2 -> V_59 . V_116 != V_111 )
return 0 ;
V_112 . V_113 . V_117 = 1 ;
V_112 . V_113 . V_113 [ 0 ] . V_90 = V_2 -> V_62 -> V_118 . V_90 ;
V_112 . V_113 . V_113 [ 0 ] . V_119 = NULL ;
return F_65 ( & V_2 -> V_9 , & V_112 . V_113 ,
F_4 ,
& V_2 -> V_5 -> V_120 . V_121 ,
V_2 -> V_59 . V_122 ,
V_2 -> V_59 . V_123 ) ;
}
static int
F_66 ( struct V_1 * V_2 , bool V_124 )
{
struct V_47 * V_6 = & V_2 -> V_6 ;
int V_51 , V_52 ;
char V_125 [] = L_20 ;
F_67 ( V_2 , true ) ;
if ( F_68 ( & V_2 -> V_59 . V_84 ) )
F_64 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
F_61 ( V_2 ) ;
V_52 = F_69 ( V_125 , sizeof( V_125 ) ) ;
if ( V_52 ) {
F_3 ( L_21 ) ;
return - V_75 ;
}
V_51 = F_70 ( V_6 , V_125 ,
V_2 -> V_5 -> V_15 . V_126 ,
V_124 ) ;
if ( V_51 >= 0 && ! V_124 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_5 -> V_15 . V_110 = 0 ;
}
if ( ! V_127 )
fprintf ( V_128 , L_22 ,
V_6 -> V_129 , V_125 ) ;
if ( ! V_124 ) {
F_67 ( V_2 , false ) ;
if ( F_68 ( & V_2 -> V_59 . V_84 ) )
F_64 ( V_2 , false ) ;
}
return V_51 ;
}
static void F_71 ( int T_6 V_13 ,
T_7 * V_130 ,
void * T_8 V_13 )
{
V_131 = V_130 -> V_132 . V_133 ;
V_41 = 1 ;
V_39 = 1 ;
}
int __weak
F_72 ( const struct V_134 * T_9 V_13 ,
struct V_8 * V_9 V_13 ,
T_10 T_11 V_13 ,
struct V_14 * V_14 V_13 )
{
return 0 ;
}
static const struct V_134 *
F_73 ( struct V_67 * V_62 )
{
if ( V_62 ) {
if ( V_62 -> V_64 && V_62 -> V_64 [ 0 ] . V_32 )
return V_62 -> V_64 [ 0 ] . V_32 ;
if ( V_62 -> V_92 && V_62 -> V_92 [ 0 ] . V_32 )
return V_62 -> V_92 [ 0 ] . V_32 ;
}
return NULL ;
}
static const struct V_134 * F_74 ( struct V_1 * V_2 )
{
const struct V_134 * T_9 ;
T_9 = F_73 ( V_2 -> V_62 ) ;
if ( T_9 )
return T_9 ;
return NULL ;
}
static int F_67 ( struct V_1 * V_2 , bool V_111 )
{
struct V_78 * V_5 = V_2 -> V_5 ;
struct V_14 * V_14 = & V_5 -> V_120 . V_121 ;
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_51 = F_19 ( V_6 ) ;
int V_52 = 0 ;
if ( V_2 -> V_59 . V_116 != V_111 )
return 0 ;
if ( V_6 -> V_109 ) {
V_52 = F_75 ( V_9 , V_5 ,
F_4 ) ;
if ( V_52 < 0 ) {
F_3 ( L_23 ) ;
goto V_36;
}
if ( F_60 ( & V_2 -> V_62 -> V_102 ) ) {
V_52 = F_76 ( V_9 , V_51 , V_2 -> V_62 ,
F_4 ) ;
if ( V_52 <= 0 ) {
F_3 ( L_24 ) ;
goto V_36;
}
V_2 -> V_7 += V_52 ;
}
}
V_52 = F_72 ( F_74 ( V_2 ) , V_9 ,
F_4 , V_14 ) ;
if ( V_52 )
goto V_36;
if ( V_2 -> V_59 . V_106 ) {
V_52 = F_77 ( V_2 -> V_58 , V_9 ,
V_5 , F_4 ) ;
if ( V_52 )
goto V_36;
}
V_52 = F_53 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_25
L_26
L_27 ) ;
V_52 = F_52 ( V_9 , F_4 ,
V_14 ) ;
F_10 ( V_52 < 0 , L_28
L_26
L_29 ) ;
if ( V_135 ) {
F_78 ( & V_5 -> V_120 ,
F_51 , V_9 ) ;
}
V_52 = F_79 ( V_14 , V_9 , & V_59 -> V_84 , V_2 -> V_62 -> V_82 ,
F_4 , V_59 -> V_122 ,
V_59 -> V_123 ) ;
V_36:
return V_52 ;
}
static int F_80 ( struct V_1 * V_2 , int V_136 , const char * * V_137 )
{
int V_52 ;
int V_138 = 0 ;
unsigned long V_139 = 0 ;
const bool V_140 = V_136 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_68 * V_59 = & V_2 -> V_59 ;
struct V_47 * V_6 = & V_2 -> V_6 ;
struct V_78 * V_5 ;
bool V_141 = false , V_142 = false ;
int V_51 ;
V_2 -> V_143 = V_137 [ 0 ] ;
atexit ( F_16 ) ;
signal ( V_38 , F_15 ) ;
signal ( V_144 , F_15 ) ;
signal ( V_145 , F_15 ) ;
if ( V_2 -> V_59 . V_72 || V_2 -> V_146 ) {
signal ( V_147 , V_148 ) ;
if ( V_2 -> V_59 . V_72 )
F_81 ( & V_65 ) ;
if ( V_2 -> V_146 )
F_81 ( & V_149 ) ;
} else {
signal ( V_147 , V_150 ) ;
}
V_5 = F_82 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_30 ) ;
return - 1 ;
}
V_51 = F_19 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_57 ( V_2 ) ;
if ( V_140 ) {
V_52 = F_83 ( V_2 -> V_62 , & V_59 -> V_84 ,
V_137 , V_6 -> V_109 ,
F_71 ) ;
if ( V_52 < 0 ) {
F_3 ( L_31 ) ;
V_138 = V_52 ;
goto V_151;
}
}
if ( F_36 ( V_2 ) != 0 ) {
V_52 = - 1 ;
goto V_152;
}
V_52 = F_84 () ;
if ( V_52 ) {
char V_153 [ V_154 ] ;
F_85 ( V_52 , V_153 , sizeof( V_153 ) ) ;
F_3 ( L_32 ,
V_153 ) ;
goto V_152;
}
if ( V_2 -> V_9 . V_155 && ! F_86 ( V_2 -> V_62 ) ) {
F_87 ( L_33 ) ;
V_2 -> V_9 . V_155 = false ;
}
if ( ! V_2 -> V_62 -> V_156 )
F_59 ( & V_5 -> V_15 , V_157 ) ;
if ( V_6 -> V_109 ) {
V_52 = F_88 ( V_51 ) ;
if ( V_52 < 0 )
goto V_152;
} else {
V_52 = F_63 ( V_5 , V_2 -> V_62 , V_51 , false ) ;
if ( V_52 < 0 )
goto V_152;
}
if ( ! V_2 -> V_100
&& ! F_89 ( & V_5 -> V_15 , V_101 ) ) {
F_3 ( L_34
L_35 ) ;
V_52 = - 1 ;
goto V_152;
}
V_14 = & V_5 -> V_120 . V_121 ;
V_52 = F_67 ( V_2 , false ) ;
if ( V_52 < 0 )
goto V_152;
if ( V_2 -> V_158 ) {
struct V_159 V_160 ;
V_160 . V_161 = V_2 -> V_158 ;
if ( F_90 ( 0 , V_162 , & V_160 ) ) {
F_3 ( L_36 ) ;
V_52 = - 1 ;
goto V_152;
}
}
if ( ! F_68 ( & V_59 -> V_84 ) && ! V_59 -> V_163 )
F_91 ( V_2 -> V_62 ) ;
if ( V_140 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_119 ) + V_14 -> V_164 ) ;
if ( V_11 == NULL ) {
V_52 = - V_165 ;
goto V_152;
}
F_92 ( V_9 , V_11 ,
V_2 -> V_62 -> V_118 . V_90 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_93 ( V_2 -> V_62 ) ;
}
if ( V_59 -> V_163 ) {
F_94 ( V_59 -> V_163 * 1000 ) ;
F_91 ( V_2 -> V_62 ) ;
}
F_30 ( & V_65 ) ;
F_30 ( & V_149 ) ;
for (; ; ) {
unsigned long long V_166 = V_2 -> V_35 ;
if ( F_95 ( & V_149 ) || V_41 || V_142 )
F_55 ( V_2 -> V_62 , V_94 ) ;
if ( F_56 ( V_2 ) < 0 ) {
F_28 ( & V_65 ) ;
F_28 ( & V_149 ) ;
V_52 = - 1 ;
goto V_152;
}
if ( V_167 ) {
V_167 = 0 ;
if ( ! F_96 ( & V_65 ) )
F_27 ( V_2 ) ;
if ( F_96 ( & V_65 ) ) {
F_3 ( L_37 ) ;
V_52 = - 1 ;
goto V_152;
}
}
if ( F_95 ( & V_149 ) ) {
if ( V_2 -> V_62 -> V_93 == V_168 )
continue;
F_30 ( & V_149 ) ;
F_55 ( V_2 -> V_62 , V_168 ) ;
if ( ! V_127 )
fprintf ( V_128 , L_38 ,
V_139 ) ;
V_139 = 0 ;
V_51 = F_66 ( V_2 , false ) ;
if ( V_51 < 0 ) {
F_3 ( L_39 ) ;
F_28 ( & V_149 ) ;
V_52 = V_51 ;
goto V_152;
}
}
if ( V_166 == V_2 -> V_35 ) {
if ( V_41 || V_142 )
break;
V_52 = F_97 ( V_2 -> V_62 , - 1 ) ;
if ( V_52 > 0 || ( V_52 < 0 && V_73 == V_169 ) )
V_52 = 0 ;
V_139 ++ ;
if ( F_98 ( V_2 -> V_62 , V_170 | V_171 ) == 0 )
V_142 = true ;
}
if ( V_41 && ! V_141 && ! F_68 ( & V_59 -> V_84 ) ) {
F_99 ( & V_65 ) ;
F_100 ( V_2 -> V_62 ) ;
V_141 = true ;
}
}
F_99 ( & V_65 ) ;
F_99 ( & V_149 ) ;
if ( V_140 && V_131 ) {
char V_69 [ V_172 ] ;
const char * V_173 = F_34 ( V_131 , V_69 , sizeof( V_69 ) ) ;
F_3 ( L_40 , V_173 ) ;
V_52 = - 1 ;
goto V_152;
}
if ( ! V_127 )
fprintf ( V_128 , L_41 , V_139 ) ;
if ( F_68 ( & V_2 -> V_59 . V_84 ) )
F_64 ( V_2 , true ) ;
V_152:
if ( V_140 ) {
int V_174 ;
if ( ! V_39 )
F_101 ( V_2 -> V_62 -> V_118 . V_90 , V_145 ) ;
F_102 ( & V_174 ) ;
if ( V_52 < 0 )
V_138 = V_52 ;
else if ( F_103 ( V_174 ) )
V_138 = F_104 ( V_174 ) ;
else if ( F_105 ( V_174 ) )
V_40 = F_106 ( V_174 ) ;
} else
V_138 = V_52 ;
F_67 ( V_2 , true ) ;
V_2 -> V_35 = 0 ;
if ( ! V_52 ) {
if ( ! V_2 -> V_175 ) {
F_61 ( V_2 ) ;
} else {
V_51 = F_66 ( V_2 , true ) ;
if ( V_51 < 0 ) {
V_138 = V_51 ;
goto V_151;
}
}
}
if ( ! V_52 && ! V_127 ) {
char V_35 [ 128 ] ;
const char * V_176 = V_2 -> V_175 ?
L_42 : L_43 ;
if ( V_2 -> V_35 && ! V_2 -> V_59 . V_106 )
F_107 ( V_35 , sizeof( V_35 ) ,
L_44 V_177 L_45 , V_2 -> V_35 ) ;
else
V_35 [ 0 ] = '\0' ;
fprintf ( V_128 , L_46 ,
F_108 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_129 , V_176 , V_35 ) ;
}
V_151:
F_109 ( V_5 ) ;
return V_138 ;
}
static void F_110 ( struct V_79 * V_178 )
{
static const char * V_179 [ V_180 ] = { L_47 , L_48 , L_49 , L_50 } ;
F_8 ( L_51 , V_179 [ V_178 -> V_181 ] ) ;
if ( V_178 -> V_181 == V_182 )
F_8 ( L_52 ,
V_178 -> V_183 ) ;
}
int F_111 ( struct V_68 * V_1 ,
struct V_79 * V_178 ,
const char * V_184 , bool V_185 )
{
int V_57 ;
V_178 -> V_186 = ! V_185 ;
if ( V_185 ) {
V_178 -> V_181 = V_187 ;
F_8 ( L_53 ) ;
return 0 ;
}
V_57 = F_112 ( V_184 , V_178 ) ;
if ( ! V_57 ) {
if ( V_178 -> V_181 == V_182 )
V_1 -> V_122 = true ;
F_110 ( V_178 ) ;
}
return V_57 ;
}
int F_113 ( const struct V_188 * V_189 ,
const char * V_184 ,
int V_185 )
{
return F_111 ( V_189 -> V_190 , & V_79 , V_184 , V_185 ) ;
}
int F_114 ( const struct V_188 * V_189 ,
const char * V_184 V_13 ,
int V_185 V_13 )
{
struct V_79 * V_178 = V_189 -> V_190 ;
V_178 -> V_186 = true ;
if ( V_178 -> V_181 == V_187 )
V_178 -> V_181 = V_191 ;
F_110 ( V_178 ) ;
return 0 ;
}
static int F_115 ( const char * V_192 , const char * V_190 , void * V_193 )
{
struct V_1 * V_2 = V_193 ;
if ( ! strcmp ( V_192 , L_54 ) ) {
if ( ! strcmp ( V_190 , L_55 ) )
V_2 -> V_194 = false ;
else if ( ! strcmp ( V_190 , L_56 ) )
V_2 -> V_194 = true ;
else if ( ! strcmp ( V_190 , L_57 ) )
V_2 -> V_100 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_192 , L_58 ) )
V_192 = L_59 ;
return F_116 ( V_192 , V_190 , V_193 ) ;
}
static int F_117 ( const struct V_188 * V_189 , const char * V_179 , int V_185 )
{
struct V_68 * V_59 = (struct V_68 * ) V_189 -> V_190 ;
const struct V_195 * V_196 ;
const char * V_197 = V_179 ;
if ( V_185 ) {
V_59 -> V_198 = 0 ;
return 0 ;
}
if ( ! V_179 )
return 0 ;
if ( V_59 -> V_198 )
return - 1 ;
V_59 -> V_198 = true ;
if ( sscanf ( V_179 , L_60 , & V_59 -> V_199 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_179 , L_61 , 6 ) )
V_179 += 6 ;
for ( V_196 = V_200 ; V_196 -> V_201 ; V_196 ++ ) {
if ( ! strcasecmp ( V_179 , V_196 -> V_201 ) ) {
V_59 -> V_199 = V_196 -> V_199 ;
return 0 ;
}
}
V_59 -> V_198 = false ;
F_41 ( L_62 , V_197 ) ;
return - 1 ;
}
static int F_118 ( const struct V_188 * V_189 ,
const char * V_179 ,
int V_185 V_13 )
{
struct V_68 * V_59 = V_189 -> V_190 ;
char * V_202 , * V_203 ;
unsigned int V_70 ;
int V_57 ;
if ( ! V_179 )
return - V_75 ;
V_202 = F_119 ( V_179 ) ;
if ( ! V_202 )
return - V_165 ;
V_203 = strchr ( V_202 , ',' ) ;
if ( V_203 )
* V_203 = '\0' ;
if ( * V_202 ) {
V_57 = F_120 ( & V_70 , V_202 ) ;
if ( V_57 )
goto V_204;
V_59 -> V_70 = V_70 ;
}
if ( ! V_203 ) {
V_57 = 0 ;
goto V_204;
}
V_57 = F_120 ( & V_70 , V_203 + 1 ) ;
if ( V_57 )
goto V_204;
V_59 -> V_71 = V_70 ;
V_204:
free ( V_202 ) ;
return V_57 ;
}
int F_121 ( int V_136 , const char * * V_137 , const char * T_12 V_13 )
{
int V_52 ;
struct V_1 * V_2 = & V_1 ;
char V_153 [ V_154 ] ;
#ifndef F_122
# define F_123 ( V_202 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_123 ( '\0' , L_63 , true ) ;
F_123 ( '\0' , L_64 , true ) ;
# undef F_123
#endif
#ifndef F_124
# if ! F_125 ( V_205 )
# define F_126 "NO_DWARF=1"
# elif ! F_125 ( F_122 )
# define F_126 "NO_LIBBPF=1"
# else
# define F_126 "this architecture doesn't support BPF prologue"
# endif
# define F_123 ( V_202 , T_13 , T_14 ) set_option_nobuild(record_options, s, l, REASON, c)
F_123 ( '\0' , L_65 , true ) ;
# undef F_123
# undef F_126
#endif
V_2 -> V_62 = F_127 () ;
if ( V_2 -> V_62 == NULL )
return - V_165 ;
F_128 ( F_115 , V_2 ) ;
V_136 = F_129 ( V_136 , V_137 , V_206 , V_207 ,
V_208 ) ;
if ( ! V_136 && F_68 ( & V_2 -> V_59 . V_84 ) )
F_130 ( V_207 , V_206 ) ;
if ( V_209 && ! V_2 -> V_59 . V_84 . V_210 ) {
F_131 ( V_207 , V_206 ,
L_66 ) ;
}
if ( V_2 -> V_59 . V_211 &&
! F_132 () ) {
F_43 ( L_67 ) ;
F_133 ( V_207 , V_206 , L_68 , 0 ) ;
return - V_75 ;
}
if ( V_2 -> V_146 )
V_2 -> V_175 = true ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = F_134 ( V_2 -> V_62 , & V_52 ) ;
if ( V_52 )
return V_52 ;
}
V_52 = F_135 ( V_2 -> V_58 , & V_2 -> V_59 ,
V_2 -> V_59 . V_212 ) ;
if ( V_52 )
return V_52 ;
if ( V_213 )
return 0 ;
V_52 = F_136 ( V_2 -> V_62 ) ;
if ( V_52 ) {
F_137 ( V_2 -> V_62 , V_52 , V_153 , sizeof( V_153 ) ) ;
F_3 ( L_69 ,
V_153 ) ;
return V_52 ;
}
V_52 = - V_165 ;
F_138 ( NULL ) ;
if ( V_87 . V_214 )
F_87 (
L_70
L_71
L_72
L_73
L_74
L_75
L_76 ) ;
if ( V_2 -> V_194 || V_2 -> V_100 ) {
F_139 () ;
} else if ( V_2 -> V_146 ) {
bool V_215 = true ;
if ( V_2 -> V_216 && ! V_2 -> V_100 )
V_215 = false ;
if ( V_2 -> V_217 && ! V_2 -> V_194 )
V_215 = false ;
if ( V_215 ) {
V_2 -> V_100 = true ;
V_2 -> V_194 = true ;
F_139 () ;
}
}
if ( V_1 . V_59 . V_30 )
V_1 . V_59 . V_116 = true ;
if ( V_2 -> V_62 -> V_218 == 0 &&
F_140 ( V_2 -> V_62 ) < 0 ) {
F_3 ( L_77 ) ;
goto V_219;
}
if ( V_2 -> V_59 . V_84 . V_220 && ! V_2 -> V_59 . V_221 )
V_2 -> V_59 . V_222 = true ;
V_52 = F_141 ( & V_2 -> V_59 . V_84 ) ;
if ( V_52 ) {
F_142 ( & V_2 -> V_59 . V_84 , V_52 , V_153 , V_154 ) ;
F_41 ( L_78 , V_153 ) ;
}
V_52 = F_143 ( & V_2 -> V_59 . V_84 ) ;
if ( V_52 ) {
int V_223 = V_73 ;
F_142 ( & V_2 -> V_59 . V_84 , V_52 , V_153 , V_154 ) ;
F_43 ( L_78 , V_153 ) ;
V_52 = - V_223 ;
goto V_219;
}
V_52 = - V_165 ;
if ( F_144 ( V_2 -> V_62 , & V_2 -> V_59 . V_84 ) < 0 )
F_130 ( V_207 , V_206 ) ;
V_52 = F_145 ( V_2 -> V_58 , V_2 -> V_62 , & V_2 -> V_59 ) ;
if ( V_52 )
goto V_219;
if ( V_2 -> V_59 . V_106 )
V_2 -> V_89 = true ;
if ( F_146 ( & V_2 -> V_59 ) ) {
V_52 = - V_75 ;
goto V_219;
}
V_52 = F_80 ( & V_1 , V_136 , V_137 ) ;
V_219:
F_147 ( V_2 -> V_62 ) ;
F_148 () ;
F_149 ( V_2 -> V_58 ) ;
return V_52 ;
}
static void V_148 ( int V_37 V_13 )
{
if ( F_150 ( & V_65 ) ) {
F_151 ( & V_65 ) ;
V_167 = 1 ;
if ( F_31 ( V_1 . V_58 ) )
F_28 ( & V_65 ) ;
}
if ( F_150 ( & V_149 ) )
F_151 ( & V_149 ) ;
}
