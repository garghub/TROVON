static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_4 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = F_2 ( V_5 ) ;
V_2 -> V_10 = F_3 ( F_4 ( V_3 ) ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned long V_11 , unsigned int V_12 )
{
unsigned int V_13 = F_6 (unsigned int, len, LEN_ON_PAGE(pa)) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = F_2 ( V_13 ) ;
V_2 -> V_10 = F_3 ( V_11 ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned char * V_14 , unsigned int V_12 ,
bool V_15 )
{
unsigned long V_11 = F_4 ( V_14 ) ;
int V_16 , V_17 , V_18 = V_12 ;
if ( ! F_8 ( V_11 , V_19 ) ) {
F_9 ( L_1 ,
V_15 ? L_2 : L_3 , V_11 , V_19 ) ;
return - V_20 ;
}
if ( V_12 % V_21 ) {
F_9 ( L_4 ,
V_15 ? L_2 : L_3 , V_12 , V_21 ) ;
if ( V_15 )
return - V_20 ;
V_12 = F_10 ( V_12 , V_21 ) ;
}
if ( V_12 <= F_11 ( V_11 ) ) {
V_17 = F_5 ( V_2 , V_11 , V_12 ) ;
F_12 ( V_17 < V_12 ) ;
return 0 ;
}
for ( V_16 = 0 ; V_16 < V_22 && V_12 > 0 ; V_16 ++ ) {
V_17 = F_5 ( & V_3 [ V_16 ] , V_11 , V_12 ) ;
V_14 += V_17 ;
V_12 -= V_17 ;
V_11 = F_4 ( V_14 ) ;
}
if ( V_12 > 0 ) {
F_9 ( L_5 ,
V_18 , V_15 ? L_2 : L_3 , V_12 ) ;
if ( V_15 )
return - V_23 ;
V_18 -= V_12 ;
}
F_1 ( V_2 , V_3 , V_16 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
T_1 V_28 = V_25 -> V_28 , V_29 = F_14 () ;
T_1 V_30 = F_15 ( V_28 , V_31 ) ;
while ( ! ( F_16 ( V_27 -> V_6 ) & V_32 ) ) {
F_17 () ;
V_29 = F_14 () ;
if ( F_18 ( V_29 , V_30 ) )
break;
}
F_19 () ;
if ( ! ( V_27 -> V_6 & V_32 ) ) {
F_20 ( V_27 , L_6 ,
( long ) F_21 ( V_29 , V_28 ) ) ;
return - V_33 ;
}
if ( V_27 -> V_6 & V_34 ) {
F_20 ( V_27 , L_7 ) ;
return - V_35 ;
}
if ( V_27 -> V_6 & V_36 ) {
F_20 ( V_27 , L_8 ) ;
return - V_35 ;
}
if ( V_27 -> V_37 ) {
F_20 ( V_27 , L_9 ) ;
return - V_35 ;
}
switch ( V_27 -> V_38 ) {
case V_39 :
break;
case V_40 :
break;
case V_41 :
F_20 ( V_27 , L_10 ) ;
return - V_20 ;
case V_42 :
F_20 ( V_27 , L_11 ) ;
return - V_20 ;
case V_43 :
return - V_44 ;
case V_45 :
F_20 ( V_27 , L_12 ) ;
return - V_46 ;
case V_47 :
F_20 ( V_27 , L_13 ) ;
return - V_20 ;
case V_48 :
F_20 ( V_27 , L_14 ) ;
return - V_20 ;
case V_49 :
F_20 ( V_27 , L_15 ) ;
return - V_20 ;
case V_50 :
F_20 ( V_27 , L_16 ) ;
return - V_20 ;
case V_51 :
F_22 ( V_27 , L_17 ) ;
return - V_20 ;
case V_52 :
F_20 ( V_27 , L_18 ) ;
return - V_20 ;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
F_22 ( V_27 , L_19 ) ;
return - V_35 ;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_22 ( V_27 , L_20 ) ;
return - V_35 ;
case V_69 :
F_20 ( V_27 , L_21 ) ;
return - V_35 ;
case V_70 :
F_20 ( V_27 , L_22 ) ;
return - V_20 ;
case V_71 :
case V_72 :
F_20 ( V_27 , L_23 ) ;
return - V_20 ;
case V_73 :
F_20 ( V_27 , L_24 ) ;
return - V_20 ;
case V_74 :
F_20 ( V_27 , L_25 ) ;
return - V_20 ;
case V_75 :
F_20 ( V_27 , L_26 ) ;
return - V_20 ;
case V_76 :
F_20 ( V_27 , L_27 ) ;
return - V_35 ;
case V_77 :
F_20 ( V_27 , L_28 ) ;
return - V_35 ;
case V_78 :
F_20 ( V_27 , L_29 ) ;
return - V_35 ;
case V_79 :
F_20 ( V_27 , L_30 ) ;
return - V_35 ;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
F_22 ( V_27 , L_31 ) ;
return - V_35 ;
case V_84 :
F_22 ( V_27 , L_32 ) ;
return - V_35 ;
case V_85 :
F_20 ( V_27 , L_33 ) ;
return - V_35 ;
case V_86 :
F_20 ( V_27 , L_34 ) ;
return - V_35 ;
case V_87 :
F_20 ( V_27 , L_35 ) ;
return - V_35 ;
case V_88 :
F_20 ( V_27 , L_36 ) ;
return - V_35 ;
default:
F_20 ( V_27 , L_37 , V_27 -> V_38 ) ;
return - V_35 ;
}
if ( V_27 -> V_89 & V_90 ) {
F_20 ( V_27 , L_38 ) ;
return - V_35 ;
}
if ( V_27 -> V_89 & V_91 ) {
F_20 ( V_27 , L_39 ) ;
return - V_35 ;
}
if ( ! ( V_27 -> V_89 & V_92 ) ) {
F_20 ( V_27 , L_40 ) ;
return - V_35 ;
}
F_23 ( L_41 ,
F_24 ( V_27 -> V_7 ) ,
( unsigned long ) F_21 ( V_29 , V_28 ) ) ;
return 0 ;
}
static int F_25 ( const unsigned char * V_15 , unsigned int V_93 ,
unsigned char * V_94 , unsigned int V_95 ,
struct V_24 * V_25 )
{
struct V_96 * V_97 ;
struct V_26 * V_27 ;
T_2 V_98 ;
int V_17 ;
V_97 = & V_25 -> V_97 ;
V_27 = & V_97 -> V_27 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_17 = F_7 ( & V_97 -> V_99 , V_25 -> V_100 ,
( unsigned char * ) V_15 , V_93 , true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( & V_97 -> V_101 , V_25 -> V_102 ,
V_94 , V_95 , false ) ;
if ( V_17 )
return V_17 ;
V_98 = F_4 ( V_27 ) & V_103 ;
V_98 |= V_104 ;
V_97 -> V_98 = F_3 ( V_98 ) ;
return 0 ;
}
static int F_26 ( const unsigned char * V_15 , unsigned int V_93 ,
unsigned char * V_94 , unsigned int * V_105 ,
void * V_106 , int V_107 )
{
struct V_96 * V_97 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
int V_17 ;
T_3 V_108 ;
unsigned int V_95 = * V_105 ;
V_25 = F_27 ( V_106 , V_109 ) ;
* V_105 = 0 ;
if ( ! V_110 ) {
F_28 ( L_42 ) ;
return - V_111 ;
}
V_17 = F_25 ( V_15 , V_93 , V_94 , V_95 , V_25 ) ;
if ( V_17 )
return V_17 ;
V_97 = & V_25 -> V_97 ;
V_27 = & V_97 -> V_27 ;
V_108 = 0 ;
V_108 = F_29 ( V_112 , V_108 , V_110 ) ;
V_108 = F_29 ( V_113 , V_108 , 0 ) ;
V_108 = F_29 ( V_114 , V_108 , V_107 ) ;
V_25 -> V_28 = F_14 () ;
V_17 = F_30 ( F_2 ( V_108 ) , V_97 ) ;
F_23 ( L_43 , V_17 ,
( unsigned int ) V_108 ,
( unsigned int ) F_24 ( V_97 -> V_108 ) ) ;
V_17 &= ~ V_115 ;
switch ( V_17 ) {
case V_116 :
V_17 = F_13 ( V_25 , V_27 ) ;
break;
case V_117 :
F_23 ( L_44 ) ;
V_17 = - V_118 ;
break;
case V_119 :
F_28 ( L_45 ) ;
V_17 = - V_35 ;
break;
}
if ( ! V_17 )
* V_105 = F_24 ( V_27 -> V_7 ) ;
return V_17 ;
}
static int F_31 ( const unsigned char * V_15 , unsigned int V_93 ,
unsigned char * V_94 , unsigned int * V_105 ,
void * V_106 , int V_107 )
{
struct V_96 * V_97 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_120 * V_121 ;
int V_17 , V_16 = 0 ;
T_3 V_108 ;
unsigned int V_95 = * V_105 ;
V_25 = F_27 ( V_106 , V_109 ) ;
* V_105 = 0 ;
V_97 = & V_25 -> V_97 ;
V_27 = & V_97 -> V_27 ;
V_17 = F_25 ( V_15 , V_93 , V_94 , V_95 , V_25 ) ;
if ( V_17 )
return V_17 ;
V_108 = 0 ;
V_108 = F_29 ( V_114 , V_108 , V_107 ) ;
V_97 -> V_108 = F_2 ( V_108 ) ;
V_121 = V_25 -> V_121 ;
if ( ! V_121 ) {
F_28 ( L_46 ) ;
return - V_111 ;
}
do {
V_25 -> V_28 = F_14 () ;
F_32 () ;
F_33 ( V_97 , 0 ) ;
V_17 = F_34 ( V_121 , 0 , 1 ) ;
F_35 () ;
} while ( V_17 && ( V_16 ++ < V_122 ) );
if ( V_17 ) {
F_28 ( L_47 ) ;
return V_17 ;
}
V_17 = F_13 ( V_25 , V_27 ) ;
if ( ! V_17 )
* V_105 = F_24 ( V_27 -> V_7 ) ;
return V_17 ;
}
static int F_36 ( const unsigned char * V_15 , unsigned int V_93 ,
unsigned char * V_94 , unsigned int * V_105 ,
void * V_25 )
{
return F_37 ( V_15 , V_93 , V_94 , V_105 ,
V_25 , V_123 ) ;
}
static int F_38 ( const unsigned char * V_15 , unsigned int V_93 ,
unsigned char * V_94 , unsigned int * V_105 ,
void * V_25 )
{
return F_37 ( V_15 , V_93 , V_94 , V_105 ,
V_25 , V_124 ) ;
}
static inline void F_39 ( struct V_125 * V_126 ,
int V_127 )
{
V_126 -> V_128 = V_127 ;
F_40 ( & V_126 -> V_129 ) ;
F_41 ( & V_126 -> V_129 , & V_130 ) ;
}
static void F_42 ( struct V_125 * V_126 )
{
unsigned int V_16 , V_128 ;
F_43 (i) {
V_128 = F_44 ( V_16 ) ;
if ( V_126 -> V_128 == V_128 )
F_45 ( V_131 , V_16 ) = V_126 ;
}
}
static struct V_120 * F_46 ( struct V_125 * V_126 )
{
struct V_120 * V_121 = NULL ;
struct V_132 V_133 ;
F_47 ( & V_133 , V_126 -> V_134 ) ;
V_133 . V_135 = 0 ;
V_133 . V_136 = 0 ;
V_121 = F_48 ( V_126 -> V_137 . V_138 , V_126 -> V_134 , & V_133 ) ;
if ( F_49 ( V_121 ) ) {
F_50 ( L_48 ,
F_51 ( V_121 ) ) ;
return NULL ;
}
return V_121 ;
}
static int T_4 F_52 ( struct V_139 * V_140 , int V_128 ,
int V_141 )
{
struct V_120 * V_142 = NULL ;
struct V_143 V_144 ;
struct V_125 * V_126 ;
T_3 V_135 , V_136 , V_145 , V_146 ;
T_2 V_147 ;
const char * V_148 ;
int V_17 ;
V_17 = F_53 ( V_140 , L_49 , & V_147 ) ;
if ( V_17 ) {
F_50 ( L_50 ) ;
return V_17 ;
}
V_17 = F_54 ( V_140 , L_51 , & V_146 ) ;
if ( V_17 ) {
F_50 ( L_52 ) ;
return V_17 ;
}
V_17 = F_54 ( V_140 , L_53 , & V_135 ) ;
if ( V_17 ) {
F_50 ( L_54 ) ;
return V_17 ;
}
V_17 = F_54 ( V_140 , L_55 , & V_136 ) ;
if ( V_17 ) {
F_50 ( L_56 ) ;
return V_17 ;
}
V_17 = F_54 ( V_140 , L_57 , & V_145 ) ;
if ( V_17 ) {
F_50 ( L_58 ) ;
return V_17 ;
}
V_17 = F_55 ( V_140 , L_59 , & V_148 ) ;
if ( V_17 ) {
F_50 ( L_60 ) ;
return V_17 ;
}
V_126 = F_56 ( sizeof( * V_126 ) , V_149 ) ;
if ( ! V_126 )
return - V_150 ;
if ( ! strcmp ( V_148 , L_61 ) )
V_126 -> V_134 = V_151 ;
else if ( ! strcmp ( V_148 , L_62 ) )
V_126 -> V_134 = V_152 ;
else {
F_50 ( L_63 ) ;
V_17 = - V_20 ;
goto V_153;
}
F_57 ( & V_144 , V_126 -> V_134 ) ;
V_144 . V_147 = ( void * ) V_147 ;
V_144 . V_154 = V_146 ;
V_144 . V_155 = V_135 ;
V_144 . V_156 = V_136 ;
V_144 . V_157 = V_145 ;
V_144 . V_158 = V_159 ;
V_142 = F_58 ( V_141 , V_126 -> V_134 , & V_144 ) ;
if ( F_49 ( V_142 ) ) {
V_17 = F_51 ( V_142 ) ;
F_50 ( L_64 ,
V_17 ) ;
goto V_153;
}
V_126 -> V_137 . V_142 = V_142 ;
V_126 -> V_137 . V_138 = V_141 ;
F_39 ( V_126 , V_128 ) ;
if ( V_126 -> V_134 == V_151 )
F_42 ( V_126 ) ;
return 0 ;
V_153:
F_59 ( V_126 ) ;
return V_17 ;
}
static int T_4 F_60 ( struct V_139 * V_160 )
{
struct V_139 * V_140 ;
int V_128 , V_141 , V_17 = 0 ;
int V_161 = 0 ;
V_128 = F_61 ( V_160 ) ;
if ( V_128 < 0 ) {
F_50 ( L_65 ) ;
return - V_20 ;
}
F_62 (dn, NULL, L_66 ) {
if ( F_61 ( V_140 ) == V_128 )
break;
}
if ( ! V_140 ) {
F_50 ( L_67 ) ;
return - V_20 ;
}
if ( F_54 ( V_140 , L_68 , & V_141 ) ) {
F_50 ( L_69 ) ;
F_63 ( V_140 ) ;
return - V_20 ;
}
F_63 ( V_140 ) ;
F_64 (pn, dn) {
if ( F_65 ( V_140 , L_70 ) ) {
V_17 = F_52 ( V_140 , V_128 , V_141 ) ;
if ( V_17 ) {
F_63 ( V_140 ) ;
return V_17 ;
}
V_161 ++ ;
}
}
if ( ! V_161 ) {
F_50 ( L_71 ) ;
V_17 = - V_20 ;
}
return V_17 ;
}
static int T_4 F_66 ( struct V_139 * V_140 )
{
struct V_125 * V_126 ;
unsigned int V_134 , V_162 ;
int V_128 ;
V_128 = F_61 ( V_140 ) ;
if ( V_128 < 0 ) {
F_50 ( L_65 ) ;
return - V_20 ;
}
if ( F_54 ( V_140 , L_72 , & V_134 ) ) {
F_50 ( L_73 ) ;
return - V_20 ;
}
if ( F_54 ( V_140 , L_74 , & V_162 ) ) {
F_50 ( L_75 ) ;
return - V_20 ;
}
V_126 = F_67 ( sizeof( * V_126 ) , V_149 ) ;
if ( ! V_126 )
return - V_150 ;
V_126 -> V_134 = V_134 ;
V_126 -> V_162 = V_162 ;
F_39 ( V_126 , V_128 ) ;
F_68 ( L_76 , V_128 , V_134 , V_162 ) ;
if ( ! V_110 )
V_110 = V_134 ;
else if ( V_110 != V_134 )
F_50 ( L_77 ,
V_128 , V_134 , V_110 ) ;
return 0 ;
}
static void F_69 ( void )
{
struct V_125 * V_126 , * V_163 ;
F_70 (coproc, n, &nx842_coprocs, list) {
if ( V_126 -> V_137 . V_142 )
F_71 ( V_126 -> V_137 . V_142 ) ;
F_72 ( & V_126 -> V_129 ) ;
F_59 ( V_126 ) ;
}
}
static int F_73 ( struct V_164 * V_165 )
{
struct V_166 * V_167 = F_74 ( V_165 ) ;
struct V_24 * V_25 ;
struct V_125 * V_126 ;
int V_17 ;
V_17 = F_75 ( V_165 , & V_168 ) ;
if ( V_17 )
return V_17 ;
V_25 = F_27 ( (struct V_24 * ) V_167 -> V_25 , V_109 ) ;
V_126 = F_45 ( V_131 , F_76 () ) ;
V_17 = - V_20 ;
if ( V_126 && V_126 -> V_137 . V_142 ) {
V_25 -> V_121 = F_46 ( V_126 ) ;
if ( ! F_49 ( V_25 -> V_121 ) )
return 0 ;
V_17 = F_51 ( V_25 -> V_121 ) ;
}
return V_17 ;
}
void F_77 ( struct V_164 * V_165 )
{
struct V_166 * V_167 = F_74 ( V_165 ) ;
struct V_24 * V_25 ;
V_25 = F_27 ( (struct V_24 * ) V_167 -> V_25 , V_109 ) ;
if ( V_25 && V_25 -> V_121 )
F_71 ( V_25 -> V_121 ) ;
F_78 ( V_165 ) ;
}
static int F_79 ( struct V_164 * V_165 )
{
return F_75 ( V_165 , & V_168 ) ;
}
static T_4 int F_80 ( void )
{
struct V_139 * V_140 ;
int V_17 ;
F_81 ( V_109 % V_169 ) ;
F_81 ( V_169 % V_170 ) ;
F_81 ( V_171 % V_170 ) ;
F_81 ( V_172 % V_19 ) ;
F_81 ( V_19 % V_173 ) ;
F_81 ( V_173 % V_21 ) ;
F_62 (dn, NULL, L_78 ) {
V_17 = F_60 ( V_140 ) ;
if ( V_17 ) {
F_69 () ;
return V_17 ;
}
}
if ( F_82 ( & V_130 ) ) {
F_62 (dn, NULL, L_79 )
F_66 ( V_140 ) ;
if ( ! V_110 )
return - V_111 ;
F_37 = F_26 ;
} else {
F_37 = F_31 ;
V_174 . V_175 = F_73 ;
V_174 . V_176 = F_77 ;
}
V_17 = F_83 ( & V_174 ) ;
if ( V_17 ) {
F_69 () ;
return V_17 ;
}
return 0 ;
}
static void T_5 F_84 ( void )
{
F_85 ( & V_174 ) ;
F_69 () ;
}
