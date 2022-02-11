static void
F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
T_1 V_8 ;
T_2 V_9 , V_10 ;
V_6 = V_11 [ V_2 -> V_12 ] ;
if ( ! V_6 )
return;
V_9 = V_10 = F_2 ( V_13 , V_6 -> V_14 , V_15 ) ;
if ( V_9 . V_16 == V_17 ) {
V_9 . V_16 = V_18 ;
F_3 ( V_13 , V_6 -> V_14 , V_15 , V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
if ( V_3 [ V_7 ] == '\n' ) {
do {
V_8 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
} while ( ! V_8 . V_20 );
F_4 ( V_13 , V_6 -> V_14 , V_21 , '\r' ) ;
}
do {
V_8 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
} while ( ! V_8 . V_20 );
F_4 ( V_13 , V_6 -> V_14 , V_21 , V_3 [ V_7 ] ) ;
}
if ( V_9 . V_16 != V_10 . V_16 )
F_3 ( V_13 , V_6 -> V_14 , V_15 , V_10 ) ;
}
static int T_3
F_5 ( struct V_1 * V_2 , char * V_22 )
{
struct V_23 * V_24 ;
int V_25 = 115200 ;
int V_26 = 8 ;
int V_27 = 'n' ;
int V_28 = 'n' ;
if ( V_2 -> V_12 < 0 || V_2 -> V_12 >= V_29 )
V_2 -> V_12 = 0 ;
V_24 = & V_11 [ V_2 -> V_12 ] -> V_24 ;
V_30 = V_24 ;
V_2 -> V_31 |= V_32 ;
if ( V_22 )
F_6 ( V_22 , & V_25 , & V_27 , & V_26 , & V_28 ) ;
V_33 = V_25 ;
F_7 ( V_24 , V_2 -> V_12 ) ;
F_8 ( V_24 , V_2 , V_25 , V_27 , V_26 , V_28 ) ;
return 0 ;
}
static inline int F_9 ( struct V_5 * V_6 )
{
void T_4 * V_14 = V_6 -> V_14 ;
T_1 V_34 = F_2 ( V_13 , V_14 , V_19 ) ;
return ! ( V_34 . V_35 == V_36 ) ;
}
static inline void F_10 ( struct V_5 * V_6 ,
int V_37 , int V_38 )
{
void T_4 * V_14 = V_6 -> V_14 ;
unsigned long V_31 ;
T_5 V_39 ;
F_11 ( V_31 ) ;
V_39 = F_2 ( V_13 , V_14 , V_40 ) ;
if ( V_37 )
V_39 . V_35 = V_36 ;
else
V_39 . V_35 = V_41 ;
F_3 ( V_13 , V_14 , V_40 , V_39 ) ;
F_12 ( V_31 ) ;
}
static inline int F_13 ( struct V_5 * V_6 )
{
void T_4 * V_14 = V_6 -> V_14 ;
T_1 V_34 = F_2 ( V_13 , V_14 , V_19 ) ;
return ( V_34 . V_42 == V_36 ) ;
}
static void F_14 ( struct V_23 * V_24 , char V_43 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
T_6 V_44 = { . V_45 = V_43 } ;
T_7 V_46 = { . V_20 = V_17 } ;
T_1 V_34 ;
T_8 V_47 , V_48 ;
void T_4 * V_14 = V_6 -> V_14 ;
unsigned long V_31 ;
F_15 ( & V_24 -> V_49 , V_31 ) ;
do {
F_16 ( & V_24 -> V_49 , V_31 ) ;
F_15 ( & V_24 -> V_49 , V_31 ) ;
V_47 = V_48 = F_2 ( V_13 , V_14 , V_50 ) ;
V_34 = F_2 ( V_13 , V_14 , V_19 ) ;
} while ( ! V_34 . V_20 );
F_3 ( V_13 , V_14 , V_51 , V_46 ) ;
V_48 . V_52 = 0 ;
F_3 ( V_13 , V_14 , V_50 , V_48 ) ;
F_3 ( V_13 , V_14 , V_21 , V_44 ) ;
V_6 -> V_24 . V_53 . V_54 ++ ;
V_34 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
if ( V_34 . V_55 ) {
T_9 V_56 = { . V_57 = 1 } ;
T_2 V_9 ;
F_3 ( V_13 , V_14 , V_58 , V_56 ) ;
V_9 = F_2 ( V_13 , V_14 , V_15 ) ;
V_47 . V_52 = 1 ;
V_9 . V_16 = 0 ;
F_3 ( V_13 , V_14 , V_15 , V_9 ) ;
}
F_3 ( V_13 , V_14 , V_50 , V_47 ) ;
F_16 ( & V_24 -> V_49 , V_31 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
if ( V_6 -> V_59 )
return;
V_6 -> V_59 = 1 ;
F_18 ( V_24 ) ;
}
static inline void F_18 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
void T_4 * V_14 = V_6 -> V_14 ;
T_8 V_48 ;
T_10 V_60 ;
V_48 = F_2 ( V_13 , V_14 , V_50 ) ;
V_48 . V_52 = V_18 ;
F_3 ( V_13 , V_14 , V_50 , V_48 ) ;
V_60 = F_2 ( V_13 , V_14 , V_61 ) ;
V_60 . V_20 = V_17 ;
F_3 ( V_13 , V_14 , V_61 , V_60 ) ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
void T_4 * V_14 = V_6 -> V_14 ;
T_8 V_48 ;
T_10 V_60 ;
T_2 V_9 = { 0 } ;
T_9 V_56 = { 0 } ;
V_60 = F_2 ( V_13 , V_14 , V_61 ) ;
V_60 . V_20 = V_18 ;
F_3 ( V_13 , V_14 , V_61 , V_60 ) ;
V_48 = F_2 ( V_13 , V_14 , V_50 ) ;
V_48 . V_52 = 1 ;
F_3 ( V_13 , V_14 , V_50 , V_48 ) ;
V_56 . V_57 = 1 ;
F_3 ( V_13 , V_14 , V_58 , V_56 ) ;
V_9 . V_16 = 0 ;
F_3 ( V_13 , V_14 , V_15 , V_9 ) ;
V_6 -> V_59 = 0 ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
void T_4 * V_14 = V_6 -> V_14 ;
T_5 V_39 = F_2 ( V_13 , V_14 , V_40 ) ;
V_39 . V_16 = V_18 ;
F_3 ( V_13 , V_14 , V_40 , V_39 ) ;
}
static unsigned int F_21 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned long V_31 ;
unsigned int V_62 ;
T_1 V_34 = { 0 } ;
F_15 ( & V_6 -> V_24 . V_49 , V_31 ) ;
V_34 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
V_62 = V_34 . V_63 ? V_64 : 0 ;
F_16 ( & V_6 -> V_24 . V_49 , V_31 ) ;
return V_62 ;
}
static unsigned int F_22 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned int V_62 ;
V_62 = 0 ;
if ( F_9 ( V_6 ) )
V_62 |= V_65 ;
if ( F_13 ( V_6 ) )
V_62 |= V_66 ;
return F_23 ( V_6 -> V_67 , & V_62 ) ;
}
static void F_24 ( struct V_23 * V_24 , unsigned int V_68 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
F_10 ( V_6 , V_68 & V_65 ? 1 : 0 , 0 ) ;
F_25 ( V_6 -> V_67 , V_68 ) ;
}
static void F_26 ( struct V_23 * V_24 , int V_69 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned long V_31 ;
T_8 V_48 ;
T_2 V_9 ;
T_10 V_60 ;
F_15 ( & V_6 -> V_24 . V_49 , V_31 ) ;
V_48 = F_2 ( V_13 , V_6 -> V_14 , V_50 ) ;
V_9 = F_2 ( V_13 , V_6 -> V_14 , V_15 ) ;
V_60 = F_2 ( V_13 , V_6 -> V_14 , V_61 ) ;
if ( V_69 != 0 ) {
V_60 . V_20 = V_18 ;
V_9 . V_16 = 0 ;
V_48 . V_52 = 1 ;
V_48 . V_70 = 0 ;
} else {
V_60 . V_20 = V_17 ;
V_48 . V_52 = 0 ;
V_48 . V_70 = 1 ;
}
F_3 ( V_13 , V_6 -> V_14 , V_50 , V_48 ) ;
F_3 ( V_13 , V_6 -> V_14 , V_15 , V_9 ) ;
F_3 ( V_13 , V_6 -> V_14 , V_61 , V_60 ) ;
F_16 ( & V_6 -> V_24 . V_49 , V_31 ) ;
}
static void
F_27 ( struct V_5 * V_6 )
{
int V_71 ;
struct V_72 * V_73 = & V_6 -> V_24 . V_74 -> V_73 ;
void T_4 * V_14 = V_6 -> V_14 ;
T_1 V_34 ;
T_7 V_46 = { . V_20 = V_17 } ;
if ( F_28 ( V_73 ) || F_29 ( & V_6 -> V_24 ) ) {
T_10 V_60 ;
V_60 = F_2 ( V_13 , V_14 , V_61 ) ;
V_60 . V_20 = 0 ;
V_60 . V_63 = 0 ;
F_3 ( V_13 , V_14 , V_61 , V_60 ) ;
V_6 -> V_59 = 0 ;
return;
}
V_71 = 64 ;
do {
T_6 V_44 = { . V_45 = V_73 -> V_75 [ V_73 -> V_76 ] } ;
F_3 ( V_13 , V_14 , V_21 , V_44 ) ;
F_3 ( V_13 , V_14 , V_51 , V_46 ) ;
V_73 -> V_76 = ( V_73 -> V_76 + 1 ) & ( V_77 - 1 ) ;
V_6 -> V_24 . V_53 . V_54 ++ ;
if ( V_73 -> V_78 == V_73 -> V_76 )
break;
V_34 = F_2 ( V_13 , V_14 , V_19 ) ;
} while ( ( -- V_71 > 0 ) && V_34 . V_20 );
if ( F_30 ( V_73 ) < V_79 )
F_31 ( & V_6 -> V_24 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
T_11 V_80 ;
T_1 V_34 ;
struct V_81 * V_24 ;
struct V_82 * V_53 ;
int V_71 = 16 ;
char V_83 ;
T_7 V_46 = { 0 } ;
V_34 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
V_53 = & V_6 -> V_24 . V_53 ;
V_24 = & V_6 -> V_24 . V_74 -> V_24 ;
do {
V_80 = F_2 ( V_13 , V_6 -> V_14 , V_84 ) ;
V_83 = V_85 ;
V_46 . V_86 = 1 ;
F_3 ( V_13 , V_6 -> V_14 , V_51 , V_46 ) ;
V_53 -> V_87 ++ ;
if ( V_80 . V_88 | V_80 . V_89 | V_80 . V_90 ) {
if ( V_80 . V_45 == 0x00 &&
V_80 . V_88 ) {
V_83 = V_91 ;
V_53 -> V_92 ++ ;
} else if ( V_80 . V_89 ) {
V_83 = V_93 ;
V_53 -> V_27 ++ ;
} else if ( V_80 . V_90 ) {
V_83 = V_94 ;
V_53 -> V_95 ++ ;
} else if ( V_80 . V_88 ) {
V_83 = V_96 ;
V_53 -> V_97 ++ ;
}
}
if ( ! F_33 ( V_24 , V_80 . V_45 , V_83 ) )
F_34 ( L_1 , V_98 ) ;
V_34 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
} while ( V_34 . V_86 && ( V_71 -- > 0 ) );
F_35 ( & V_6 -> V_24 . V_49 ) ;
F_36 ( V_24 ) ;
F_37 ( & V_6 -> V_24 . V_49 ) ;
}
static T_12
F_38 ( int V_99 , void * V_100 )
{
struct V_5 * V_6 = (struct V_5 * ) V_100 ;
void T_4 * V_14 ;
int V_101 = 0 ;
F_37 ( & V_6 -> V_24 . V_49 ) ;
V_14 = V_6 -> V_14 ;
if ( V_14 ) {
T_13 V_102 ;
V_102 = F_2 ( V_13 , V_14 , V_103 ) ;
if ( V_102 . V_86 ) {
F_32 ( V_6 ) ;
V_101 = 1 ;
}
if ( V_102 . V_20 ) {
F_27 ( V_6 ) ;
V_101 = 1 ;
}
}
F_35 ( & V_6 -> V_24 . V_49 ) ;
return F_39 ( V_101 ) ;
}
static int F_40 ( struct V_23 * V_24 )
{
T_11 V_8 ;
T_7 V_46 = { 0 } ;
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
do {
V_8 = F_2 ( V_13 , V_6 -> V_14 , V_84 ) ;
} while ( ! V_8 . V_86 );
V_46 . V_86 = 1 ;
F_3 ( V_13 , V_6 -> V_14 , V_51 , V_46 ) ;
return V_8 . V_45 ;
}
static void F_41 ( struct V_23 * V_24 ,
unsigned char V_104 )
{
T_1 V_8 ;
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
do {
V_8 = F_2 ( V_13 , V_6 -> V_14 , V_19 ) ;
} while ( ! V_8 . V_20 );
F_4 ( V_13 , V_6 -> V_14 , V_21 , V_104 ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned long V_31 ;
T_10 V_105 = { 0 } ;
V_105 . V_86 = V_17 ;
if ( F_43 ( V_11 [ V_24 -> line ] -> V_99 , F_38 ,
0 , V_106 , V_11 [ V_24 -> line ] ) )
F_34 ( L_2 , V_24 -> line ) ;
F_15 ( & V_6 -> V_24 . V_49 , V_31 ) ;
F_3 ( V_13 , V_6 -> V_14 , V_61 , V_105 ) ;
F_24 ( & V_6 -> V_24 , V_6 -> V_24 . V_68 ) ;
F_16 ( & V_6 -> V_24 . V_49 , V_31 ) ;
return 0 ;
}
static void F_44 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned long V_31 ;
F_15 ( & V_6 -> V_24 . V_49 , V_31 ) ;
F_19 ( V_24 ) ;
F_20 ( V_24 ) ;
F_45 ( V_11 [ V_24 -> line ] -> V_99 ,
V_11 [ V_24 -> line ] ) ;
F_24 ( & V_6 -> V_24 , V_6 -> V_24 . V_68 ) ;
F_16 ( & V_6 -> V_24 . V_49 , V_31 ) ;
}
static void
F_46 ( struct V_23 * V_24 , struct V_107 * V_108 ,
struct V_107 * V_10 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
unsigned long V_31 ;
T_14 V_109 ;
T_9 V_56 = { 0 } ;
T_8 V_110 = { 0 } ;
T_2 V_111 = { 0 } ;
T_5 V_112 = { 0 } ;
T_15 V_113 = { 0 } ;
T_16 V_114 = { 0 } ;
int V_25 ;
if ( V_10 &&
V_108 -> V_115 == V_10 -> V_115 &&
V_108 -> V_116 == V_10 -> V_116 )
return;
V_110 . V_117 = V_118 ;
V_110 . V_16 = 0 ;
V_110 . V_52 = 0 ;
V_110 . V_119 = V_18 ;
V_110 . V_70 = 1 ;
V_110 . V_120 = 0 ;
V_112 . V_121 = V_122 ;
V_112 . V_123 = V_124 ;
V_112 . V_125 = 1 ;
V_112 . V_35 = V_41 ;
V_110 . V_126 = V_127 ;
V_112 . V_126 = V_127 ;
V_110 . V_128 = V_129 ;
V_112 . V_128 = V_129 ;
V_110 . V_130 = V_18 ;
V_112 . V_130 = V_18 ;
V_110 . V_131 = V_132 ;
if ( ( V_24 != V_30 ) || V_10 )
V_25 = F_47 ( V_24 , V_108 , V_10 , 0 ,
V_24 -> V_133 / 8 ) ;
else
V_25 = V_33 ;
V_113 . div = 29493000 / ( 8 * V_25 ) ;
V_114 . div = V_113 . div ;
V_112 . V_117 = V_110 . V_117 ;
if ( ( V_108 -> V_115 & V_134 ) == V_135 ) {
V_110 . V_126 = V_136 ;
V_112 . V_126 = V_136 ;
}
if ( V_108 -> V_115 & V_137 ) {
V_110 . V_131 = V_138 ;
}
if ( V_108 -> V_115 & V_139 ) {
V_110 . V_130 = V_17 ;
V_112 . V_130 = V_17 ;
}
if ( V_108 -> V_115 & V_140 ) {
if ( V_108 -> V_115 & V_141 ) {
V_110 . V_128 = V_142 ;
V_112 . V_128 = V_142 ;
} else {
V_110 . V_128 = V_143 ;
V_112 . V_128 = V_143 ;
}
} else {
if ( V_108 -> V_115 & V_141 ) {
V_110 . V_128 = V_144 ;
V_112 . V_128 = V_144 ;
}
}
if ( V_108 -> V_115 & V_145 ) {
V_110 . V_120 = V_17 ;
}
V_110 . V_16 = V_17 ;
V_112 . V_16 = V_17 ;
F_15 ( & V_24 -> V_49 , V_31 ) ;
V_111 . V_16 = 0 ;
F_3 ( V_13 , V_6 -> V_14 , V_15 , V_111 ) ;
F_48 ( V_24 , V_108 -> V_115 , V_24 -> V_133 / 8 ) ;
F_49 ( V_6 -> V_14 , V_146 , V_114 ) ;
F_49 ( V_6 -> V_14 , V_40 , V_112 ) ;
F_49 ( V_6 -> V_14 , V_147 , V_113 ) ;
F_49 ( V_6 -> V_14 , V_50 , V_110 ) ;
V_111 . V_16 = 0 ;
F_3 ( V_13 , V_6 -> V_14 , V_15 , V_111 ) ;
V_109 = F_2 ( V_13 , V_6 -> V_14 , V_148 ) ;
if ( V_6 -> V_24 . V_74 && V_6 -> V_24 . V_74 -> V_24 . V_149 &&
( V_6 -> V_24 . V_74 -> V_24 . V_149 -> V_108 . V_116 & V_150 ) ) {
V_109 . V_151 = F_50 ( V_6 -> V_24 . V_74 -> V_24 . V_149 ) ;
V_109 . V_152 = V_17 ;
} else
V_109 . V_152 = V_18 ;
F_49 ( V_6 -> V_14 , V_148 , V_109 ) ;
V_56 . V_57 = 1 ;
F_3 ( V_13 , V_6 -> V_14 , V_58 , V_56 ) ;
F_24 ( & V_6 -> V_24 , V_6 -> V_24 . V_68 ) ;
F_16 ( & V_6 -> V_24 . V_49 , V_31 ) ;
}
static const char *
F_51 ( struct V_23 * V_24 )
{
return L_3 ;
}
static void F_52 ( struct V_23 * V_24 )
{
}
static int F_53 ( struct V_23 * V_24 )
{
return 0 ;
}
static void F_54 ( struct V_23 * V_24 , int V_31 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
V_6 -> V_24 . type = V_153 ;
}
static void F_7 ( struct V_23 * V_24 , int line )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 ;
if ( V_6 -> V_154 )
return;
V_6 -> V_154 = 1 ;
V_24 -> line = line ;
F_55 ( & V_24 -> V_49 ) ;
V_24 -> V_155 = & V_156 ;
V_24 -> V_99 = V_6 -> V_99 ;
V_24 -> V_157 = ( unsigned long ) V_6 -> V_14 ;
V_24 -> V_133 = 29493000 ;
V_24 -> V_158 = 255 ;
V_24 -> V_31 = V_159 ;
}
static int F_56 ( struct V_160 * V_161 )
{
struct V_162 * V_163 = V_161 -> V_164 . V_165 ;
struct V_5 * V_6 ;
int V_100 ;
if ( ! V_163 )
return - V_166 ;
V_100 = F_57 ( V_163 , L_4 ) ;
if ( V_100 < 0 )
V_100 = 0 ;
if ( V_100 >= V_29 )
return - V_167 ;
if ( V_11 [ V_100 ] )
return - V_168 ;
V_6 = F_58 ( & V_161 -> V_164 , sizeof( struct V_5 ) ,
V_169 ) ;
if ( ! V_6 )
return - V_170 ;
V_6 -> V_99 = F_59 ( V_163 , 0 ) ;
V_6 -> V_14 = F_60 ( V_163 , 0 ) ;
V_6 -> V_24 . V_164 = & V_161 -> V_164 ;
V_6 -> V_67 = F_61 ( & V_161 -> V_164 , 0 ) ;
if ( F_62 ( V_6 -> V_67 ) )
return F_63 ( V_6 -> V_67 ) ;
F_7 ( & V_6 -> V_24 , V_100 ) ;
V_11 [ V_100 ] = V_6 ;
F_64 ( V_161 , & V_6 -> V_24 ) ;
F_65 ( & V_171 , & V_6 -> V_24 ) ;
return 0 ;
}
static int F_66 ( struct V_160 * V_161 )
{
struct V_23 * V_24 ;
V_24 = F_67 ( V_161 ) ;
F_68 ( & V_171 , V_24 ) ;
V_11 [ V_24 -> line ] = NULL ;
return 0 ;
}
static int T_3 F_69 ( void )
{
int V_62 ;
V_62 = F_70 ( & V_171 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_71 ( & V_172 ) ;
if ( V_62 )
F_72 ( & V_171 ) ;
return V_62 ;
}
static void T_17 F_73 ( void )
{
F_74 ( & V_172 ) ;
F_72 ( & V_171 ) ;
}
