static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
return V_3 * 2 ;
return V_3 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_11 = 1 ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
V_11 = 2 ;
if ( F_6 ( V_2 ) & V_12 ) {
unsigned long V_13 = V_9 / V_11 ;
* V_10 = F_7 ( F_8 ( V_2 ) , V_13 ) ;
}
return * V_10 * V_11 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
return 0 ;
}
static struct V_14 * F_10 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 ,
unsigned long V_19 , T_1 V_8 )
{
struct V_4 * V_5 ;
struct V_20 V_21 ;
struct V_14 * V_14 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_12 ( - V_23 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_25 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_14 = F_13 ( V_16 , & V_5 -> V_2 ) ;
if ( F_14 ( V_14 ) )
F_15 ( V_5 ) ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_28 . V_29 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
int V_34 = 0 ;
unsigned long V_35 ;
V_34 = V_28 . V_36 ( V_2 ) ;
V_34 = F_20 ( V_6 + V_37 , V_35 ,
V_35 & ( 1 << V_33 -> V_38 ) , 0 , 10000 ) ;
return V_34 ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_28 . V_39 ( V_2 ) ;
}
static unsigned long F_22 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_40 ;
V_40 = ( F_3 ( V_6 + V_33 -> V_41 ) >> 6 ) & 0x1ff ;
return V_3 * V_40 ;
}
static long F_23 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_40 ;
V_40 = V_9 / * V_10 ;
if ( V_40 < V_33 -> V_42 )
V_40 = V_33 -> V_42 ;
else if ( V_40 > 432 )
V_40 = 432 ;
return * V_10 * V_40 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_40 ;
unsigned long V_43 ;
int V_44 ;
V_44 = F_16 ( V_2 ) ;
if ( V_44 )
F_21 ( V_2 ) ;
V_40 = V_9 / V_3 ;
V_43 = F_3 ( V_6 + V_33 -> V_41 ) & ~ ( 0x1ff << 6 ) ;
F_25 ( V_43 | ( ( V_40 & 0x1ff ) << 6 ) , V_6 + V_33 -> V_41 ) ;
if ( V_44 )
F_17 ( V_2 ) ;
return 0 ;
}
static unsigned long F_26 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_45 . V_46 ( V_2 , V_3 ) ;
}
static long F_27 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
return V_45 . V_47 ( V_2 , V_9 , V_10 ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
int V_44 , V_34 ;
struct V_48 * div = F_29 ( V_2 ) ;
struct V_49 * V_50 = F_30 ( div ) ;
V_44 = F_16 ( V_50 -> V_51 ) ;
if ( V_44 )
F_21 ( V_50 -> V_51 ) ;
V_34 = V_45 . V_52 ( V_2 , V_9 , V_3 ) ;
if ( V_44 )
F_17 ( V_50 -> V_51 ) ;
return V_34 ;
}
static struct V_1 * F_31 ( const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_2 * V_35 , T_1 V_53 , T_1 V_54 ,
T_1 V_55 , const struct V_56 * V_57 ,
struct V_1 * V_58 , T_3 * V_59 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_20 V_21 ;
int V_34 ;
V_50 = F_11 ( sizeof( * V_50 ) , V_22 ) ;
if ( ! V_50 )
return F_12 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_60 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = ( V_18 ? & V_18 : NULL ) ;
V_21 . V_27 = ( V_18 ? 1 : 0 ) ;
V_50 -> div . V_35 = V_35 ;
V_50 -> div . V_53 = V_53 ;
V_50 -> div . V_54 = V_54 ;
V_50 -> div . V_19 = V_55 ;
V_50 -> div . V_59 = V_59 ;
V_50 -> div . V_57 = V_57 ;
V_50 -> div . V_2 . V_21 = & V_21 ;
V_50 -> V_51 = V_58 ;
V_2 = & V_50 -> div . V_2 ;
V_34 = F_32 ( NULL , V_2 ) ;
if ( V_34 ) {
F_15 ( V_50 ) ;
V_2 = F_12 ( V_34 ) ;
}
return V_2 ;
}
static struct V_1 * F_33 ( const char * V_61 ,
const struct V_62 * V_63 , T_3 * V_59 )
{
struct V_32 * V_33 ;
struct V_20 V_21 = { NULL } ;
void T_2 * V_35 ;
struct V_1 * V_58 ;
int V_34 ;
int V_64 ;
const struct V_65 * V_66 ;
V_33 = F_11 ( sizeof( * V_33 ) , V_22 ) ;
if ( ! V_33 )
return F_12 ( - V_23 ) ;
V_66 = & V_67 [ V_63 -> V_68 ] ;
V_21 . V_17 = V_66 -> V_69 ;
V_21 . V_24 = & V_70 ;
V_21 . V_19 = V_71 ;
V_21 . V_26 = & V_61 ;
V_21 . V_27 = 1 ;
V_33 -> V_31 . V_59 = V_59 ;
V_33 -> V_31 . V_35 = V_6 + V_37 ;
V_33 -> V_31 . V_8 = V_66 -> V_8 ;
V_33 -> V_31 . V_2 . V_21 = & V_21 ;
V_33 -> V_41 = V_66 -> V_41 ;
V_33 -> V_42 = V_63 -> V_42 ;
V_33 -> V_38 = V_66 -> V_38 ;
V_33 -> V_72 = ( F_3 ( V_6 + V_37 ) >> V_66 -> V_8 ) & 0x1 ;
V_35 = V_6 + V_33 -> V_41 ;
V_58 = & V_33 -> V_31 . V_2 ;
V_34 = F_32 ( NULL , V_58 ) ;
if ( V_34 ) {
F_15 ( V_33 ) ;
return F_12 ( V_34 ) ;
}
for ( V_64 = 0 ; V_64 < V_73 ; V_64 ++ )
if ( V_63 -> V_74 [ V_64 ] )
F_31 ( V_63 -> V_74 [ V_64 ] ,
V_66 -> V_69 ,
0 ,
V_35 ,
V_75 [ V_64 ] . V_53 ,
V_75 [ V_64 ] . V_54 ,
V_75 [ V_64 ] . V_76 ,
V_75 [ V_64 ] . V_77 ,
V_58 ,
V_59 ) ;
return V_58 ;
}
static int F_34 ( T_1 V_78 , T_1 V_79 )
{
T_4 V_57 [ V_80 ] ;
if ( V_78 == 1 ) {
if ( F_35 ( V_79 >= V_81 ) )
return - V_82 ;
return V_79 ;
}
memcpy ( V_57 , V_83 , sizeof( V_57 ) ) ;
if ( F_35 ( V_79 >= V_84 * sizeof( V_57 ) ||
0 == ( V_57 [ F_36 ( V_79 ) ] &
F_37 ( V_79 ) ) ) )
return - V_82 ;
V_57 [ F_36 ( V_79 ) ] &=
F_38 ( V_79 % V_85 , 0 ) ;
return V_81 - 1 + F_39 ( V_57 [ 0 ] ) +
( F_36 ( V_79 ) >= 1 ? F_39 ( V_57 [ 1 ] ) : 0 ) +
( F_36 ( V_79 ) >= 2 ? F_39 ( V_57 [ 2 ] ) : 0 ) ;
}
static struct V_1 *
F_40 ( struct V_86 * V_87 , void * V_63 )
{
int V_64 = F_34 ( V_87 -> args [ 0 ] , V_87 -> args [ 1 ] ) ;
if ( V_64 < 0 )
return F_12 ( - V_82 ) ;
return V_88 [ V_64 ] ;
}
static inline void F_41 ( void )
{
if ( V_89 )
F_42 ( V_89 , 0x00 , ( 1 << 8 ) , ( 1 << 8 ) ) ;
}
static inline void F_43 ( void )
{
if ( V_89 )
F_42 ( V_89 , 0x00 , ( 1 << 8 ) , ( 0 << 8 ) ) ;
}
static inline void F_44 ( void )
{
unsigned long V_43 ;
V_43 = F_3 ( V_6 + V_90 ) ;
F_25 ( V_43 | F_4 ( 16 ) , V_6 + V_90 ) ;
F_25 ( V_43 & ~ F_4 ( 16 ) , V_6 + V_90 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_91 * V_92 = F_46 ( V_31 ) ;
T_5 V_35 ;
int V_34 ;
F_41 () ;
V_28 . V_36 ( V_2 ) ;
V_34 = F_20 ( V_31 -> V_35 , V_35 ,
V_35 & V_92 -> V_38 , 1000 , V_93 ) ;
F_43 () ;
return V_34 ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_28 . V_39 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
return V_28 . V_29 ( V_2 ) ;
}
static struct V_1 * F_49 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_2 * V_35 , T_1 V_8 , T_1 V_38 ,
T_1 V_94 , T_3 * V_59 )
{
struct V_91 * V_92 ;
struct V_20 V_21 = { NULL } ;
struct V_1 * V_2 ;
int V_34 ;
V_92 = F_11 ( sizeof( * V_92 ) , V_22 ) ;
if ( ! V_92 )
return F_12 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_95 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_92 -> V_38 = V_38 ;
V_92 -> V_31 . V_59 = V_59 ;
V_92 -> V_31 . V_35 = V_35 ;
V_92 -> V_31 . V_8 = V_8 ;
V_92 -> V_31 . V_2 . V_21 = & V_21 ;
V_2 = & V_92 -> V_31 . V_2 ;
V_34 = F_32 ( V_16 , V_2 ) ;
if ( V_34 ) {
F_15 ( V_92 ) ;
V_2 = F_12 ( V_34 ) ;
}
return V_2 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_34 ;
F_41 () ;
V_34 = V_28 . V_36 ( V_2 ) ;
F_43 () ;
return V_34 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_41 () ;
V_28 . V_39 ( V_2 ) ;
F_43 () ;
}
static int F_52 ( struct V_1 * V_2 )
{
return V_28 . V_29 ( V_2 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 )
{
return V_96 . V_97 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_98 )
{
int V_34 ;
F_41 () ;
F_44 () ;
V_34 = V_96 . V_99 ( V_2 , V_98 ) ;
F_43 () ;
return V_34 ;
}
static struct V_1 * F_55 ( struct V_15 * V_16 , const char * V_17 ,
const char * const * V_26 , int V_27 ,
void T_2 * V_35 , T_1 V_8 , T_1 V_53 , unsigned long V_19 ,
T_3 * V_59 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_100 * V_101 ;
V_31 = F_11 ( sizeof( * V_31 ) , V_22 ) ;
if ( ! V_31 ) {
V_2 = F_12 ( - V_82 ) ;
goto V_102;
}
V_101 = F_11 ( sizeof( * V_101 ) , V_22 ) ;
if ( ! V_101 ) {
F_15 ( V_31 ) ;
V_2 = F_12 ( - V_82 ) ;
goto V_102;
}
V_31 -> V_35 = V_35 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_19 = 0 ;
V_31 -> V_59 = V_59 ;
V_101 -> V_35 = V_35 ;
V_101 -> V_53 = V_53 ;
V_101 -> V_103 = 3 ;
V_101 -> V_19 = 0 ;
V_2 = F_56 ( V_16 , V_17 , V_26 , V_27 ,
& V_101 -> V_2 , & V_104 ,
NULL , NULL ,
& V_31 -> V_2 , & V_105 ,
V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_31 ) ;
F_15 ( V_101 ) ;
}
V_102:
return V_2 ;
}
static struct V_1 * F_57 ( const char * V_17 ,
const char * const * V_26 , int V_27 ,
int V_106 , T_1 V_53 , T_1 V_103 ,
int V_107 , T_1 V_8 ,
unsigned long V_19 , T_3 * V_59 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 = NULL ;
struct V_100 * V_101 = NULL ;
struct V_1 * V_108 = NULL , * V_109 = NULL ;
const struct V_110 * V_111 = NULL , * V_112 = NULL ;
if ( V_107 != V_113 ) {
V_31 = F_11 ( sizeof( * V_31 ) , V_22 ) ;
if ( ! V_31 ) {
V_2 = F_12 ( - V_82 ) ;
goto V_102;
}
V_31 -> V_35 = V_6 + V_107 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_19 = 0 ;
V_31 -> V_59 = V_59 ;
V_109 = & V_31 -> V_2 ;
V_112 = & V_28 ;
}
if ( V_106 != V_114 ) {
V_101 = F_11 ( sizeof( * V_101 ) , V_22 ) ;
if ( ! V_101 ) {
V_2 = F_12 ( - V_82 ) ;
goto V_102;
}
V_101 -> V_35 = V_6 + V_106 ;
V_101 -> V_53 = V_53 ;
V_101 -> V_103 = V_103 ;
V_101 -> V_19 = 0 ;
V_108 = & V_101 -> V_2 ;
V_111 = & V_96 ;
}
if ( V_108 == NULL && V_109 == NULL ) {
V_2 = F_12 ( - V_82 ) ;
goto V_102;
}
V_2 = F_56 ( NULL , V_17 , V_26 , V_27 ,
V_108 , V_111 ,
NULL , NULL ,
V_109 , V_112 ,
V_19 ) ;
V_102:
if ( F_14 ( V_2 ) ) {
F_15 ( V_31 ) ;
F_15 ( V_101 ) ;
}
return V_2 ;
}
static void T_6 F_58 ( struct V_115 * V_116 )
{
const char * V_117 , * V_118 ;
int V_40 ;
const struct V_119 * V_120 ;
const struct V_121 * V_63 ;
unsigned long V_122 ;
const char * V_61 ;
unsigned long V_123 ;
V_6 = F_59 ( V_116 , 0 ) ;
if ( ! V_6 ) {
F_60 ( L_1 , V_116 -> V_17 ) ;
return;
}
V_89 = F_61 ( V_116 , L_2 ) ;
if ( F_14 ( V_89 ) ) {
V_89 = NULL ;
F_62 ( L_3 , V_124 ) ;
}
V_120 = F_63 ( V_125 , V_116 ) ;
if ( F_35 ( ! V_120 ) )
return;
V_63 = V_120 -> V_63 ;
V_81 = V_63 -> V_126 ;
V_88 = F_64 ( V_63 -> V_127 + V_81 ,
sizeof( * V_88 ) , V_22 ) ;
if ( ! V_88 )
goto V_102;
V_83 = V_63 -> V_128 ;
V_117 = F_65 ( V_116 , 0 ) ;
V_118 = F_65 ( V_116 , 1 ) ;
V_129 [ 1 ] = V_118 ;
V_130 [ 2 ] = V_118 ;
V_88 [ V_131 ] = F_66 ( NULL , L_4 ,
NULL , 0 , 16000000 , 160000 ) ;
V_122 = F_3 ( V_6 + V_132 ) ;
V_61 = V_122 & F_4 ( 22 ) ? V_117 : L_4 ;
V_123 = V_122 & 0x3f ;
F_67 ( NULL , L_5 , V_61 ,
0 , 1 , V_123 ) ;
F_33 ( L_5 , & V_63 -> V_133 [ 0 ] ,
& V_134 ) ;
V_88 [ V_135 ] = F_33 ( L_5 ,
& V_63 -> V_133 [ 1 ] , & V_134 ) ;
V_88 [ V_136 ] = F_33 ( L_5 ,
& V_63 -> V_133 [ 2 ] , & V_134 ) ;
for ( V_40 = 0 ; V_40 < V_137 ; V_40 ++ ) {
const struct V_138 * V_139 ;
struct V_1 * V_2 ;
V_139 = & V_140 [ V_40 ] ;
V_2 = F_31 ( V_139 -> V_17 ,
V_139 -> V_141 ,
V_139 -> V_142 ,
V_6 + V_139 -> V_41 ,
V_139 -> V_53 ,
V_139 -> V_54 ,
V_139 -> V_76 ,
V_139 -> V_77 ,
V_88 [ V_139 -> V_68 ] ,
& V_134 ) ;
if ( V_139 -> V_143 != V_144 )
V_88 [ V_139 -> V_143 ] = V_2 ;
}
V_145 [ 1 ] = V_117 ;
V_88 [ V_146 ] = F_68 (
NULL , L_6 , V_145 , F_69 ( V_145 ) , 0 ,
V_6 + V_7 , 0 , 3 , 0 , NULL , & V_134 ) ;
F_70 ( NULL , L_7 , L_6 ,
V_12 , V_6 + V_7 ,
4 , 4 , 0 , V_147 , & V_134 ) ;
F_70 ( NULL , L_8 , L_7 ,
V_12 , V_6 + V_7 ,
10 , 3 , 0 , V_148 , & V_134 ) ;
F_10 ( NULL , L_9 , L_8 ,
V_12 , 12 ) ;
F_70 ( NULL , L_10 , L_7 ,
V_12 , V_6 + V_7 ,
13 , 3 , 0 , V_148 , & V_134 ) ;
F_10 ( NULL , L_11 , L_10 ,
V_12 , 15 ) ;
V_88 [ V_149 ] = F_67 ( NULL , L_12 , L_7 ,
0 , 1 , 8 ) ;
V_88 [ V_150 ] = F_67 ( NULL , L_13 , L_7 ,
0 , 1 , 1 ) ;
for ( V_40 = 0 ; V_40 < V_63 -> V_127 ; V_40 ++ ) {
const struct V_151 * V_152 ;
unsigned int V_79 ;
int V_143 ;
V_152 = & V_63 -> V_153 [ V_40 ] ;
V_79 = 8 * ( V_152 -> V_41 - V_154 ) +
V_152 -> V_8 ;
V_143 = F_34 ( 0 , V_79 ) ;
if ( V_143 < 0 )
goto V_102;
V_88 [ V_143 ] = F_71 (
NULL , V_152 -> V_17 , V_152 -> V_18 , V_152 -> V_19 ,
V_6 + V_152 -> V_41 , V_152 -> V_8 , 0 , & V_134 ) ;
if ( F_14 ( V_88 [ V_143 ] ) ) {
F_60 ( L_14 ,
V_116 -> V_155 , V_152 -> V_17 ) ;
goto V_102;
}
}
V_88 [ V_156 ] = F_49 ( NULL , L_15 , L_16 , 0 ,
V_6 + V_157 , 0 , 2 , 0 , & V_134 ) ;
if ( F_14 ( V_88 [ V_156 ] ) ) {
F_60 ( L_17 ) ;
goto V_102;
}
V_88 [ V_158 ] = F_49 ( NULL , L_18 , L_19 , 0 ,
V_6 + V_90 , 0 , 2 , 0 , & V_134 ) ;
if ( F_14 ( V_88 [ V_158 ] ) ) {
F_60 ( L_20 ) ;
goto V_102;
}
V_88 [ V_159 ] = F_72 ( NULL , L_21 , L_22 ,
0 , V_6 + V_7 , 16 , 5 , 0 ,
& V_134 ) ;
if ( F_14 ( V_88 [ V_159 ] ) ) {
F_60 ( L_23 ) ;
goto V_102;
}
V_88 [ V_160 ] = F_55 ( NULL , L_24 , V_161 , 4 ,
V_6 + V_90 , 15 , 8 , 0 , & V_134 ) ;
if ( F_14 ( V_88 [ V_160 ] ) ) {
F_60 ( L_25 ) ;
goto V_102;
}
for ( V_40 = 0 ; V_40 < V_63 -> V_162 ; V_40 ++ ) {
const struct V_163 * V_164 ;
struct V_1 * V_2 ;
V_164 = & V_63 -> V_164 [ V_40 ] ;
V_2 = F_57 ( V_164 -> V_17 ,
V_164 -> V_26 , V_164 -> V_27 ,
V_164 -> V_106 , V_164 -> V_53 ,
V_164 -> V_103 , V_164 -> V_107 ,
V_164 -> V_8 , V_164 -> V_19 ,
& V_134 ) ;
if ( F_14 ( V_2 ) ) {
F_62 ( L_26 , V_164 -> V_17 ) ;
continue;
}
if ( V_164 -> V_143 != V_144 )
V_88 [ V_164 -> V_143 ] = V_2 ;
}
if ( F_73 ( V_116 , L_27 ) )
F_67 ( NULL , L_28 , L_4 , 0 ,
1 , 488 ) ;
F_74 ( V_116 , F_40 , NULL ) ;
return;
V_102:
F_15 ( V_88 ) ;
F_75 ( V_6 ) ;
}
