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
int V_34 ;
unsigned int V_35 = V_36 ;
if ( V_28 . V_29 ( V_2 ) )
return 0 ;
V_28 . V_37 ( V_2 ) ;
do {
V_34 = ! ( F_3 ( V_31 -> V_38 ) & F_4 ( V_33 -> V_39 ) ) ;
} while ( V_34 && -- V_35 );
return V_34 ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_28 . V_40 ( V_2 ) ;
}
static unsigned long F_21 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_41 ;
V_41 = ( F_3 ( V_6 + V_33 -> V_42 ) >> 6 ) & 0x1ff ;
return V_3 * V_41 ;
}
static long F_22 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_41 ;
V_41 = V_9 / * V_10 ;
if ( V_41 < V_33 -> V_43 )
V_41 = V_33 -> V_43 ;
else if ( V_41 > 432 )
V_41 = 432 ;
return * V_10 * V_41 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = F_19 ( V_31 ) ;
unsigned long V_41 ;
unsigned long V_44 ;
int V_45 ;
V_45 = F_16 ( V_2 ) ;
if ( V_45 )
F_20 ( V_2 ) ;
V_41 = V_9 / V_3 ;
V_44 = F_3 ( V_6 + V_33 -> V_42 ) & ~ ( 0x1ff << 6 ) ;
F_24 ( V_44 | ( ( V_41 & 0x1ff ) << 6 ) , V_6 + V_33 -> V_42 ) ;
if ( V_45 )
F_17 ( V_2 ) ;
return 0 ;
}
static unsigned long F_25 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_46 . V_47 ( V_2 , V_3 ) ;
}
static long F_26 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
return V_46 . V_48 ( V_2 , V_9 , V_10 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
int V_45 , V_49 ;
struct V_50 * div = F_28 ( V_2 ) ;
struct V_51 * V_52 = F_29 ( div ) ;
V_45 = F_16 ( V_52 -> V_53 ) ;
if ( V_45 )
F_20 ( V_52 -> V_53 ) ;
V_49 = V_46 . V_54 ( V_2 , V_9 , V_3 ) ;
if ( V_45 )
F_17 ( V_52 -> V_53 ) ;
return V_49 ;
}
static struct V_1 * F_30 ( const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_2 * V_38 , T_1 V_55 , T_1 V_56 ,
T_1 V_57 , const struct V_58 * V_59 ,
struct V_1 * V_60 , T_3 * V_61 )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
struct V_20 V_21 ;
int V_49 ;
V_52 = F_11 ( sizeof( * V_52 ) , V_22 ) ;
if ( ! V_52 )
return F_12 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_62 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = ( V_18 ? & V_18 : NULL ) ;
V_21 . V_27 = ( V_18 ? 1 : 0 ) ;
V_52 -> div . V_38 = V_38 ;
V_52 -> div . V_55 = V_55 ;
V_52 -> div . V_56 = V_56 ;
V_52 -> div . V_19 = V_57 ;
V_52 -> div . V_61 = V_61 ;
V_52 -> div . V_59 = V_59 ;
V_52 -> div . V_2 . V_21 = & V_21 ;
V_52 -> V_53 = V_60 ;
V_2 = & V_52 -> div . V_2 ;
V_49 = F_31 ( NULL , V_2 ) ;
if ( V_49 ) {
F_15 ( V_52 ) ;
V_2 = F_12 ( V_49 ) ;
}
return V_2 ;
}
static struct V_1 * F_32 ( const char * V_63 ,
const struct V_64 * V_65 , T_3 * V_61 )
{
struct V_32 * V_33 ;
struct V_20 V_21 = { NULL } ;
void T_2 * V_38 ;
struct V_1 * V_60 ;
int V_49 ;
int V_66 ;
const struct V_67 * V_68 ;
V_33 = F_11 ( sizeof( * V_33 ) , V_22 ) ;
if ( ! V_33 )
return F_12 ( - V_23 ) ;
V_68 = & V_69 [ V_65 -> V_70 ] ;
V_21 . V_17 = V_68 -> V_71 ;
V_21 . V_24 = & V_72 ;
V_21 . V_19 = V_73 ;
V_21 . V_26 = & V_63 ;
V_21 . V_27 = 1 ;
V_33 -> V_31 . V_61 = V_61 ;
V_33 -> V_31 . V_38 = V_6 + V_74 ;
V_33 -> V_31 . V_8 = V_68 -> V_8 ;
V_33 -> V_31 . V_2 . V_21 = & V_21 ;
V_33 -> V_42 = V_68 -> V_42 ;
V_33 -> V_43 = V_65 -> V_43 ;
V_33 -> V_39 = V_68 -> V_39 ;
V_33 -> V_75 = ( F_3 ( V_6 + V_74 ) >> V_68 -> V_8 ) & 0x1 ;
V_38 = V_6 + V_33 -> V_42 ;
V_60 = & V_33 -> V_31 . V_2 ;
V_49 = F_31 ( NULL , V_60 ) ;
if ( V_49 ) {
F_15 ( V_33 ) ;
return F_12 ( V_49 ) ;
}
for ( V_66 = 0 ; V_66 < V_76 ; V_66 ++ )
if ( V_65 -> V_77 [ V_66 ] )
F_30 ( V_65 -> V_77 [ V_66 ] ,
V_68 -> V_71 ,
0 ,
V_38 ,
V_78 [ V_66 ] . V_55 ,
V_78 [ V_66 ] . V_56 ,
V_78 [ V_66 ] . V_79 ,
V_78 [ V_66 ] . V_80 ,
V_60 ,
V_61 ) ;
return V_60 ;
}
static int F_33 ( T_1 V_81 , T_1 V_82 )
{
T_4 V_59 [ V_83 ] ;
if ( V_81 == 1 ) {
if ( F_34 ( V_82 >= V_84 ) )
return - V_85 ;
return V_82 ;
}
memcpy ( V_59 , V_86 , sizeof( V_59 ) ) ;
if ( F_34 ( V_82 >= V_87 * sizeof( V_59 ) ||
0 == ( V_59 [ F_35 ( V_82 ) ] &
F_36 ( V_82 ) ) ) )
return - V_85 ;
V_59 [ F_35 ( V_82 ) ] &=
F_37 ( V_82 % V_88 , 0 ) ;
return V_84 - 1 + F_38 ( V_59 [ 0 ] ) +
( F_35 ( V_82 ) >= 1 ? F_38 ( V_59 [ 1 ] ) : 0 ) +
( F_35 ( V_82 ) >= 2 ? F_38 ( V_59 [ 2 ] ) : 0 ) ;
}
static struct V_1 *
F_39 ( struct V_89 * V_90 , void * V_65 )
{
int V_66 = F_33 ( V_90 -> args [ 0 ] , V_90 -> args [ 1 ] ) ;
if ( V_66 < 0 )
return F_12 ( - V_85 ) ;
return V_91 [ V_66 ] ;
}
static inline void F_40 ( void )
{
if ( V_92 )
F_41 ( V_92 , 0x00 , ( 1 << 8 ) , ( 1 << 8 ) ) ;
}
static inline void F_42 ( void )
{
if ( V_92 )
F_41 ( V_92 , 0x00 , ( 1 << 8 ) , ( 0 << 8 ) ) ;
}
static inline void F_43 ( void )
{
unsigned long V_44 ;
V_44 = F_3 ( V_6 + V_93 ) ;
F_24 ( V_44 | F_4 ( 16 ) , V_6 + V_93 ) ;
F_24 ( V_44 & ~ F_4 ( 16 ) , V_6 + V_93 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_94 * V_95 = F_45 ( V_31 ) ;
int V_34 ;
unsigned int V_35 = V_96 ;
if ( V_28 . V_29 ( V_2 ) )
return 0 ;
F_40 () ;
V_28 . V_37 ( V_2 ) ;
do {
V_34 = ! ( F_3 ( V_31 -> V_38 ) & F_4 ( V_95 -> V_39 ) ) ;
if ( V_34 )
F_46 ( 100 ) ;
} while ( V_34 && -- V_35 );
F_42 () ;
return V_34 ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_28 . V_40 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
return V_28 . V_29 ( V_2 ) ;
}
static struct V_1 * F_49 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_2 * V_38 , T_1 V_8 , T_1 V_39 ,
T_1 V_97 , T_3 * V_61 )
{
struct V_94 * V_95 ;
struct V_20 V_21 = { NULL } ;
struct V_1 * V_2 ;
int V_49 ;
V_95 = F_11 ( sizeof( * V_95 ) , V_22 ) ;
if ( ! V_95 )
return F_12 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_98 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_95 -> V_39 = V_39 ;
V_95 -> V_31 . V_61 = V_61 ;
V_95 -> V_31 . V_38 = V_38 ;
V_95 -> V_31 . V_8 = V_8 ;
V_95 -> V_31 . V_2 . V_21 = & V_21 ;
V_2 = & V_95 -> V_31 . V_2 ;
V_49 = F_31 ( V_16 , V_2 ) ;
if ( V_49 ) {
F_15 ( V_95 ) ;
V_2 = F_12 ( V_49 ) ;
}
return V_2 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_49 ;
F_40 () ;
V_49 = V_28 . V_37 ( V_2 ) ;
F_42 () ;
return V_49 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_40 () ;
V_28 . V_40 ( V_2 ) ;
F_42 () ;
}
static int F_52 ( struct V_1 * V_2 )
{
return V_28 . V_29 ( V_2 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 )
{
return V_99 . V_100 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_101 )
{
int V_49 ;
F_40 () ;
F_43 () ;
V_49 = V_99 . V_102 ( V_2 , V_101 ) ;
F_42 () ;
return V_49 ;
}
static struct V_1 * F_55 ( struct V_15 * V_16 , const char * V_17 ,
const char * const * V_26 , int V_27 ,
void T_2 * V_38 , T_1 V_8 , T_1 V_55 , unsigned long V_19 ,
T_3 * V_61 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_103 * V_104 ;
V_31 = F_11 ( sizeof( * V_31 ) , V_22 ) ;
if ( ! V_31 ) {
V_2 = F_12 ( - V_85 ) ;
goto V_105;
}
V_104 = F_11 ( sizeof( * V_104 ) , V_22 ) ;
if ( ! V_104 ) {
F_15 ( V_31 ) ;
V_2 = F_12 ( - V_85 ) ;
goto V_105;
}
V_31 -> V_38 = V_38 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_19 = 0 ;
V_31 -> V_61 = V_61 ;
V_104 -> V_38 = V_38 ;
V_104 -> V_55 = V_55 ;
V_104 -> V_106 = 3 ;
V_104 -> V_19 = 0 ;
V_2 = F_56 ( V_16 , V_17 , V_26 , V_27 ,
& V_104 -> V_2 , & V_107 ,
NULL , NULL ,
& V_31 -> V_2 , & V_108 ,
V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_31 ) ;
F_15 ( V_104 ) ;
}
V_105:
return V_2 ;
}
static struct V_1 * F_57 ( const char * V_17 ,
const char * const * V_26 , int V_27 ,
int V_109 , T_1 V_55 , T_1 V_106 ,
int V_110 , T_1 V_8 ,
unsigned long V_19 , T_3 * V_61 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 = NULL ;
struct V_103 * V_104 = NULL ;
struct V_1 * V_111 = NULL , * V_112 = NULL ;
const struct V_113 * V_114 = NULL , * V_115 = NULL ;
if ( V_110 != V_116 ) {
V_31 = F_11 ( sizeof( * V_31 ) , V_22 ) ;
if ( ! V_31 ) {
V_2 = F_12 ( - V_85 ) ;
goto V_105;
}
V_31 -> V_38 = V_6 + V_110 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_19 = 0 ;
V_31 -> V_61 = V_61 ;
V_112 = & V_31 -> V_2 ;
V_115 = & V_28 ;
}
if ( V_109 != V_117 ) {
V_104 = F_11 ( sizeof( * V_104 ) , V_22 ) ;
if ( ! V_104 ) {
V_2 = F_12 ( - V_85 ) ;
goto V_105;
}
V_104 -> V_38 = V_6 + V_109 ;
V_104 -> V_55 = V_55 ;
V_104 -> V_106 = V_106 ;
V_104 -> V_19 = 0 ;
V_111 = & V_104 -> V_2 ;
V_114 = & V_99 ;
}
if ( V_111 == NULL && V_112 == NULL ) {
V_2 = F_12 ( - V_85 ) ;
goto V_105;
}
V_2 = F_56 ( NULL , V_17 , V_26 , V_27 ,
V_111 , V_114 ,
NULL , NULL ,
V_112 , V_115 ,
V_19 ) ;
V_105:
if ( F_14 ( V_2 ) ) {
F_15 ( V_31 ) ;
F_15 ( V_104 ) ;
}
return V_2 ;
}
static void T_5 F_58 ( struct V_118 * V_119 )
{
const char * V_120 , * V_121 ;
int V_41 ;
const struct V_122 * V_123 ;
const struct V_124 * V_65 ;
unsigned long V_125 ;
const char * V_63 ;
unsigned long V_126 ;
V_6 = F_59 ( V_119 , 0 ) ;
if ( ! V_6 ) {
F_60 ( L_1 , V_119 -> V_17 ) ;
return;
}
V_92 = F_61 ( V_119 , L_2 ) ;
if ( F_14 ( V_92 ) ) {
V_92 = NULL ;
F_62 ( L_3 , V_127 ) ;
}
V_123 = F_63 ( V_128 , V_119 ) ;
if ( F_34 ( ! V_123 ) )
return;
V_65 = V_123 -> V_65 ;
V_84 = V_65 -> V_129 ;
V_91 = F_64 ( V_65 -> V_130 + V_84 ,
sizeof( * V_91 ) , V_22 ) ;
if ( ! V_91 )
goto V_105;
V_86 = V_65 -> V_131 ;
V_120 = F_65 ( V_119 , 0 ) ;
V_121 = F_65 ( V_119 , 1 ) ;
V_132 [ 1 ] = V_121 ;
V_133 [ 2 ] = V_121 ;
V_91 [ V_134 ] = F_66 ( NULL , L_4 ,
NULL , 0 , 16000000 , 160000 ) ;
V_125 = F_3 ( V_6 + V_135 ) ;
V_63 = V_125 & F_4 ( 22 ) ? V_120 : L_4 ;
V_126 = V_125 & 0x3f ;
F_67 ( NULL , L_5 , V_63 ,
0 , 1 , V_126 ) ;
F_32 ( L_5 , & V_65 -> V_136 [ 0 ] ,
& V_137 ) ;
V_91 [ V_138 ] = F_32 ( L_5 ,
& V_65 -> V_136 [ 1 ] , & V_137 ) ;
V_91 [ V_139 ] = F_32 ( L_5 ,
& V_65 -> V_136 [ 2 ] , & V_137 ) ;
for ( V_41 = 0 ; V_41 < V_140 ; V_41 ++ ) {
const struct V_141 * V_142 ;
struct V_1 * V_2 ;
V_142 = & V_143 [ V_41 ] ;
V_2 = F_30 ( V_142 -> V_17 ,
V_142 -> V_144 ,
V_142 -> V_145 ,
V_6 + V_142 -> V_42 ,
V_142 -> V_55 ,
V_142 -> V_56 ,
V_142 -> V_79 ,
V_142 -> V_80 ,
V_91 [ V_142 -> V_70 ] ,
& V_137 ) ;
if ( V_142 -> V_146 != V_147 )
V_91 [ V_142 -> V_146 ] = V_2 ;
}
V_148 [ 1 ] = V_120 ;
V_91 [ V_149 ] = F_68 (
NULL , L_6 , V_148 , F_69 ( V_148 ) , 0 ,
V_6 + V_7 , 0 , 3 , 0 , NULL , & V_137 ) ;
F_70 ( NULL , L_7 , L_6 ,
V_12 , V_6 + V_7 ,
4 , 4 , 0 , V_150 , & V_137 ) ;
F_70 ( NULL , L_8 , L_7 ,
V_12 , V_6 + V_7 ,
10 , 3 , 0 , V_151 , & V_137 ) ;
F_10 ( NULL , L_9 , L_8 ,
V_12 , 12 ) ;
F_70 ( NULL , L_10 , L_7 ,
V_12 , V_6 + V_7 ,
13 , 3 , 0 , V_151 , & V_137 ) ;
F_10 ( NULL , L_11 , L_10 ,
V_12 , 15 ) ;
V_91 [ V_152 ] = F_67 ( NULL , L_12 , L_7 ,
0 , 1 , 8 ) ;
V_91 [ V_153 ] = F_67 ( NULL , L_13 , L_7 ,
0 , 1 , 1 ) ;
for ( V_41 = 0 ; V_41 < V_65 -> V_130 ; V_41 ++ ) {
const struct V_154 * V_155 ;
unsigned int V_82 ;
int V_146 ;
V_155 = & V_65 -> V_156 [ V_41 ] ;
V_82 = 8 * ( V_155 -> V_42 - V_157 ) +
V_155 -> V_8 ;
V_146 = F_33 ( 0 , V_82 ) ;
if ( V_146 < 0 )
goto V_105;
V_91 [ V_146 ] = F_71 (
NULL , V_155 -> V_17 , V_155 -> V_18 , V_155 -> V_19 ,
V_6 + V_155 -> V_42 , V_155 -> V_8 , 0 , & V_137 ) ;
if ( F_14 ( V_91 [ V_146 ] ) ) {
F_60 ( L_14 ,
V_119 , V_155 -> V_17 ) ;
goto V_105;
}
}
V_91 [ V_158 ] = F_49 ( NULL , L_15 , L_16 , 0 ,
V_6 + V_159 , 0 , 1 , 0 , & V_137 ) ;
if ( F_14 ( V_91 [ V_158 ] ) ) {
F_60 ( L_17 ) ;
goto V_105;
}
V_91 [ V_160 ] = F_49 ( NULL , L_18 , L_19 , 0 ,
V_6 + V_93 , 0 , 1 , 0 , & V_137 ) ;
if ( F_14 ( V_91 [ V_160 ] ) ) {
F_60 ( L_20 ) ;
goto V_105;
}
V_91 [ V_161 ] = F_72 ( NULL , L_21 , L_22 ,
0 , V_6 + V_7 , 16 , 5 , 0 ,
& V_137 ) ;
if ( F_14 ( V_91 [ V_161 ] ) ) {
F_60 ( L_23 ) ;
goto V_105;
}
V_91 [ V_162 ] = F_55 ( NULL , L_24 , V_163 , 4 ,
V_6 + V_93 , 15 , 8 , 0 , & V_137 ) ;
if ( F_14 ( V_91 [ V_162 ] ) ) {
F_60 ( L_25 ) ;
goto V_105;
}
for ( V_41 = 0 ; V_41 < V_65 -> V_164 ; V_41 ++ ) {
const struct V_165 * V_166 ;
struct V_1 * V_2 ;
V_166 = & V_65 -> V_166 [ V_41 ] ;
V_2 = F_57 ( V_166 -> V_17 ,
V_166 -> V_26 , V_166 -> V_27 ,
V_166 -> V_109 , V_166 -> V_55 ,
V_166 -> V_106 , V_166 -> V_110 ,
V_166 -> V_8 , V_166 -> V_19 ,
& V_137 ) ;
if ( F_14 ( V_2 ) ) {
F_62 ( L_26 , V_166 -> V_17 ) ;
continue;
}
if ( V_166 -> V_146 != V_147 )
V_91 [ V_166 -> V_146 ] = V_2 ;
}
if ( F_73 ( V_119 , L_27 ) )
F_67 ( NULL , L_28 , L_4 , 0 ,
1 , 488 ) ;
F_74 ( V_119 , F_39 , NULL ) ;
return;
V_105:
F_15 ( V_91 ) ;
F_75 ( V_6 ) ;
}
