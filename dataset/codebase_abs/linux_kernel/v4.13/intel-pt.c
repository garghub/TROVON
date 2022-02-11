static void F_1 ( struct V_1 * T_1 V_2 ,
unsigned char * V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
T_2 V_7 = 0 ;
int V_8 , V_9 , V_10 ;
char V_11 [ V_12 ] ;
const char * V_13 = V_14 ;
F_2 ( stdout , V_13 ,
L_1 ,
V_4 ) ;
while ( V_4 ) {
V_8 = F_3 ( V_3 , V_4 , & V_6 ) ;
if ( V_8 > 0 )
V_9 = V_8 ;
else
V_9 = 1 ;
printf ( L_2 ) ;
F_2 ( stdout , V_13 , L_3 , V_7 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_2 ( stdout , V_13 , L_4 , V_3 [ V_10 ] ) ;
for (; V_10 < 16 ; V_10 ++ )
F_2 ( stdout , V_13 , L_5 ) ;
if ( V_8 > 0 ) {
V_8 = F_4 ( & V_6 , V_11 ,
V_12 ) ;
if ( V_8 > 0 )
F_2 ( stdout , V_13 , L_6 , V_11 ) ;
} else {
F_2 ( stdout , V_13 , L_7 ) ;
}
V_7 += V_9 ;
V_3 += V_9 ;
V_4 -= V_9 ;
}
}
static void F_5 ( struct V_1 * T_1 , unsigned char * V_3 ,
T_2 V_4 )
{
printf ( L_8 ) ;
F_1 ( T_1 , V_3 , V_4 ) ;
}
static int F_6 ( struct V_1 * T_1 , struct V_15 * V_16 ,
struct V_15 * V_17 )
{
void * V_18 ;
V_18 = F_7 ( V_16 -> V_19 , V_16 -> V_20 , V_17 -> V_19 , V_17 -> V_20 ,
T_1 -> V_21 ) ;
if ( ! V_18 )
return - V_22 ;
V_17 -> V_23 = V_17 -> V_19 + V_17 -> V_20 - V_18 ;
V_17 -> V_24 = V_18 ;
return 0 ;
}
static void F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_15 * V_29 )
{
if ( V_28 -> V_30 == - 1 && V_29 -> V_30 != - 1 )
V_26 -> V_30 = V_29 -> V_30 ;
V_26 -> V_31 = V_29 -> V_31 ;
V_26 -> V_32 = V_29 -> V_32 ;
F_9 ( L_9 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
F_10 ( V_26 -> V_34 ) ;
if ( V_26 -> V_32 != - 1 ) {
if ( V_26 -> V_31 != - 1 )
V_26 -> V_34 = F_11 ( V_26 -> T_1 -> V_35 ,
V_26 -> V_31 ,
V_26 -> V_32 ) ;
else
V_26 -> V_34 = F_12 ( V_26 -> T_1 -> V_35 , - 1 ,
V_26 -> V_32 ) ;
}
}
static int F_13 ( struct V_36 * V_17 , void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_15 * V_29 = V_26 -> V_29 , * V_37 = V_29 ;
struct V_27 * V_28 ;
if ( V_26 -> V_38 ) {
V_17 -> V_4 = 0 ;
return 0 ;
}
V_28 = & V_26 -> T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
V_41:
V_29 = F_14 ( V_28 , V_29 ) ;
if ( ! V_29 ) {
if ( V_37 )
F_15 ( V_37 ) ;
V_17 -> V_4 = 0 ;
return 0 ;
}
V_26 -> V_29 = V_29 ;
if ( ! V_29 -> V_19 ) {
int V_42 = F_16 ( V_26 -> T_1 -> V_43 -> V_44 ) ;
V_29 -> V_19 = F_17 ( V_29 , V_42 ) ;
if ( ! V_29 -> V_19 )
return - V_45 ;
}
if ( V_26 -> T_1 -> V_46 && ! V_29 -> V_47 && V_37 &&
F_6 ( V_26 -> T_1 , V_37 , V_29 ) )
return - V_45 ;
if ( V_29 -> V_24 ) {
V_17 -> V_4 = V_29 -> V_23 ;
V_17 -> V_3 = V_29 -> V_24 ;
} else {
V_17 -> V_4 = V_29 -> V_20 ;
V_17 -> V_3 = V_29 -> V_19 ;
}
V_17 -> V_48 = V_29 -> V_49 ;
if ( V_26 -> T_1 -> V_46 && ! V_17 -> V_4 )
goto V_41;
if ( V_37 )
F_15 ( V_37 ) ;
if ( ! V_37 || V_26 -> T_1 -> V_50 || ( V_26 -> T_1 -> V_46 &&
! V_29 -> V_47 ) ) {
V_17 -> V_47 = false ;
V_17 -> V_51 = V_29 -> V_52 + 1 ;
} else {
V_17 -> V_47 = true ;
}
if ( V_26 -> V_53 && ( V_26 -> V_31 != V_29 -> V_31 ||
V_26 -> V_32 != V_29 -> V_32 ) )
F_8 ( V_26 , V_28 , V_29 ) ;
if ( V_26 -> V_54 )
V_26 -> V_38 = true ;
if ( ! V_17 -> V_4 )
return F_13 ( V_17 , V_19 ) ;
return 0 ;
}
static int F_18 ( const char * V_55 , const char * V_56 , void * V_19 )
{
int * V_57 = V_19 ;
long V_58 ;
if ( ! strcmp ( V_55 , L_10 ) ) {
V_58 = strtol ( V_56 , NULL , 0 ) ;
if ( V_58 > 0 && V_58 <= V_59 )
* V_57 = V_58 ;
}
return 0 ;
}
static int F_19 ( void )
{
static int V_57 ;
if ( V_57 )
return V_57 ;
F_20 ( F_18 , & V_57 ) ;
if ( ! V_57 )
V_57 = 64 ;
return V_57 ;
}
static unsigned int F_21 ( struct V_60 * V_60 ,
struct V_35 * V_35 )
{
T_3 V_20 ;
V_20 = F_22 ( V_60 , V_35 ) ;
V_20 /= F_19 () ;
if ( V_20 < 1000 )
return 10 ;
if ( V_20 > ( 1 << 21 ) )
return 21 ;
return 32 - F_23 ( V_20 ) ;
}
static struct V_61 * F_24 ( struct V_60 * V_60 ,
struct V_35 * V_35 )
{
struct V_61 * V_62 ;
unsigned int V_63 ;
if ( V_60 -> V_61 )
return V_60 -> V_61 ;
V_63 = F_21 ( V_60 , V_35 ) ;
V_62 = F_25 ( V_63 , sizeof( struct V_64 ) , 200 ) ;
V_60 -> V_61 = V_62 ;
return V_62 ;
}
static int F_26 ( struct V_60 * V_60 , struct V_35 * V_35 ,
T_4 V_65 , T_4 V_66 , T_4 V_67 ,
struct V_68 * V_68 )
{
struct V_61 * V_62 = F_24 ( V_60 , V_35 ) ;
struct V_64 * V_69 ;
int V_70 ;
if ( ! V_62 )
return - V_45 ;
V_69 = F_27 ( V_62 ) ;
if ( ! V_69 )
return - V_45 ;
V_69 -> V_66 = V_66 ;
V_69 -> V_67 = V_67 ;
V_69 -> V_71 = V_68 -> V_71 ;
V_69 -> V_72 = V_68 -> V_72 ;
V_69 -> V_73 = V_68 -> V_73 ;
V_69 -> V_74 = V_68 -> V_74 ;
memcpy ( V_69 -> V_75 , V_68 -> V_3 , V_76 ) ;
V_70 = F_28 ( V_62 , V_65 , & V_69 -> V_77 ) ;
if ( V_70 )
F_29 ( V_62 , V_69 ) ;
return V_70 ;
}
static struct V_64 *
F_30 ( struct V_60 * V_60 , struct V_35 * V_35 , T_4 V_65 )
{
struct V_61 * V_62 = F_24 ( V_60 , V_35 ) ;
if ( ! V_62 )
return NULL ;
return F_31 ( V_60 -> V_61 , V_65 ) ;
}
static int F_32 ( struct V_68 * V_68 ,
T_5 * V_78 , T_5 * V_79 ,
T_5 V_80 , T_5 V_81 ,
void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_35 * V_35 = V_26 -> T_1 -> V_35 ;
struct V_34 * V_34 ;
struct V_82 V_83 ;
unsigned char V_3 [ V_76 ] ;
T_6 V_4 ;
int V_84 ;
T_7 V_85 ;
T_4 V_65 , V_86 , V_87 ;
T_4 V_66 = 0 ;
bool V_88 = true ;
V_68 -> V_73 = 0 ;
if ( V_80 && * V_79 == V_80 )
goto V_89;
if ( * V_79 >= V_26 -> T_1 -> V_90 )
V_85 = V_91 ;
else
V_85 = V_92 ;
V_34 = V_26 -> V_34 ;
if ( ! V_34 ) {
if ( V_85 != V_91 )
return - V_22 ;
V_34 = V_26 -> T_1 -> V_93 ;
}
while ( 1 ) {
F_33 ( V_34 , V_85 , V_94 , * V_79 , & V_83 ) ;
if ( ! V_83 . V_95 || ! V_83 . V_95 -> V_60 )
return - V_22 ;
if ( V_83 . V_95 -> V_60 -> V_19 . V_96 == V_97 &&
F_34 ( V_83 . V_95 -> V_60 ,
V_98 ) )
return - V_99 ;
V_65 = V_83 . V_95 -> V_100 ( V_83 . V_95 , * V_79 ) ;
if ( ! V_80 && V_88 ) {
struct V_64 * V_69 ;
V_69 = F_30 ( V_83 . V_95 -> V_60 , V_35 , V_65 ) ;
if ( V_69 &&
( ! V_81 || V_69 -> V_66 <= V_81 ) ) {
* V_78 = V_69 -> V_66 ;
* V_79 += V_69 -> V_67 ;
V_68 -> V_71 = V_69 -> V_71 ;
V_68 -> V_72 = V_69 -> V_72 ;
V_68 -> V_73 = V_69 -> V_73 ;
V_68 -> V_74 = V_69 -> V_74 ;
memcpy ( V_68 -> V_3 , V_69 -> V_75 ,
V_76 ) ;
F_35 ( V_68 , * V_79 ) ;
return 0 ;
}
}
V_86 = V_65 ;
V_87 = * V_79 ;
F_36 ( V_83 . V_95 ) ;
V_84 = V_83 . V_95 -> V_60 -> V_101 ;
while ( 1 ) {
V_4 = F_37 ( V_83 . V_95 -> V_60 , V_35 ,
V_65 , V_3 ,
V_76 ) ;
if ( V_4 <= 0 )
return - V_22 ;
if ( F_38 ( V_3 , V_4 , V_84 , V_68 ) )
return - V_22 ;
F_39 ( V_68 , * V_79 ) ;
V_66 += 1 ;
if ( V_68 -> V_72 != V_102 )
goto V_103;
if ( V_81 && V_66 >= V_81 )
goto V_89;
* V_79 += V_68 -> V_73 ;
if ( V_80 && * V_79 == V_80 )
goto V_89;
if ( * V_79 >= V_83 . V_95 -> V_104 )
break;
V_65 += V_68 -> V_73 ;
}
V_88 = false ;
}
V_103:
* V_78 = V_66 ;
if ( ! V_88 )
goto V_89;
if ( V_80 ) {
struct V_64 * V_69 ;
V_69 = F_30 ( V_83 . V_95 -> V_60 , V_35 , V_86 ) ;
if ( V_69 )
return 0 ;
}
F_26 ( V_83 . V_95 -> V_60 , V_35 , V_86 , V_66 ,
* V_79 - V_87 , V_68 ) ;
return 0 ;
V_89:
* V_78 = V_66 ;
return 0 ;
}
static bool F_40 ( struct V_1 * T_1 , T_5 V_79 ,
T_5 V_65 , const char * V_105 )
{
struct V_106 * V_107 ;
bool V_108 = false ;
bool V_109 = false ;
bool V_110 = false ;
F_41 (filt, &pt->filts.head, list) {
if ( V_107 -> V_18 )
V_108 = true ;
if ( ( V_105 && ! V_107 -> V_105 ) ||
( ! V_105 && V_107 -> V_105 ) ||
( V_105 && strcmp ( V_105 , V_107 -> V_105 ) ) )
continue;
if ( ! ( V_65 >= V_107 -> V_111 && V_65 < V_107 -> V_111 + V_107 -> V_20 ) )
continue;
F_9 ( L_11 V_112 L_12 V_112 L_13 V_112 L_14 V_112 L_15 ,
V_79 , V_65 , V_105 ? V_105 : L_16 ,
V_107 -> V_18 ? L_17 : L_18 ,
V_107 -> V_111 , V_107 -> V_20 ) ;
if ( V_107 -> V_18 )
V_110 = true ;
else
V_109 = true ;
}
if ( ! V_109 && ! V_110 )
F_9 ( L_11 V_112 L_12 V_112 L_19 ,
V_79 , V_65 , V_105 ? V_105 : L_16 ) ;
return V_109 || ( V_108 && ! V_110 ) ;
}
static int F_42 ( T_5 V_79 , void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_34 * V_34 ;
struct V_82 V_83 ;
T_7 V_85 ;
T_4 V_65 ;
if ( V_79 >= V_26 -> T_1 -> V_90 )
return F_40 ( V_26 -> T_1 , V_79 , V_79 , NULL ) ;
V_85 = V_92 ;
V_34 = V_26 -> V_34 ;
if ( ! V_34 )
return - V_22 ;
F_33 ( V_34 , V_85 , V_94 , V_79 , & V_83 ) ;
if ( ! V_83 . V_95 || ! V_83 . V_95 -> V_60 )
return - V_22 ;
V_65 = V_83 . V_95 -> V_100 ( V_83 . V_95 , V_79 ) ;
return F_40 ( V_26 -> T_1 , V_79 , V_65 ,
V_83 . V_95 -> V_60 -> V_113 ) ;
}
static bool F_43 ( T_5 V_79 , void * V_19 )
{
return F_42 ( V_79 , V_19 ) > 0 ;
}
static bool F_44 ( struct V_1 * T_1 ,
struct V_114 * V_115 , T_4 * V_116 )
{
if ( V_115 -> type == T_1 -> V_117 ) {
if ( V_116 )
* V_116 = V_115 -> V_116 ;
return true ;
}
return false ;
}
static bool F_45 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , NULL ) &&
! V_119 -> V_115 . V_120 )
return false ;
}
return true ;
}
static bool F_47 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
T_4 V_116 ;
if ( ! T_1 -> V_121 )
return true ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , & V_116 ) &&
( V_116 & T_1 -> V_121 ) )
return false ;
}
return true ;
}
static bool F_48 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
T_4 V_116 ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , & V_116 ) &&
( V_116 & 1 ) && ! ( V_116 & 0x2000 ) )
return false ;
}
return true ;
}
static unsigned int F_49 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
unsigned int V_122 ;
T_4 V_116 ;
if ( ! T_1 -> V_123 )
return 0 ;
for ( V_122 = 0 , V_116 = T_1 -> V_123 ; ! ( V_116 & 1 ) ; V_122 ++ )
V_116 >>= 1 ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , & V_116 ) )
return ( V_116 & T_1 -> V_123 ) >> V_122 ;
}
return 0 ;
}
static bool F_50 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
bool V_124 = true ;
T_4 V_116 ;
if ( ! T_1 -> V_125 || ! T_1 -> V_126 )
return true ;
F_46 (pt->session->evlist, evsel) {
if ( ! ( V_119 -> V_115 . V_127 & V_128 ) )
return true ;
if ( F_44 ( T_1 , & V_119 -> V_115 , & V_116 ) ) {
if ( V_116 & T_1 -> V_125 )
V_124 = false ;
else
return true ;
}
}
return V_124 ;
}
static bool F_51 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , NULL ) &&
! V_119 -> V_115 . V_120 )
return true ;
}
return false ;
}
static bool F_52 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
bool V_21 = false ;
T_4 V_116 ;
if ( ! T_1 -> V_125 )
return false ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , & V_116 ) ) {
if ( V_116 & T_1 -> V_125 )
V_21 = true ;
else
return false ;
}
}
return V_21 ;
}
static T_4 F_53 ( const struct V_1 * T_1 , T_4 V_129 )
{
T_4 V_130 , V_131 ;
V_130 = V_129 / T_1 -> V_132 . V_133 ;
V_131 = V_129 % T_1 -> V_132 . V_133 ;
return ( V_130 << T_1 -> V_132 . V_134 ) + ( V_131 << T_1 -> V_132 . V_134 ) /
T_1 -> V_132 . V_133 ;
}
static struct V_25 * F_54 ( struct V_1 * T_1 ,
unsigned int V_33 )
{
struct V_135 V_136 = { . V_137 = 0 , } ;
struct V_25 * V_26 ;
V_26 = F_55 ( sizeof( struct V_25 ) ) ;
if ( ! V_26 )
return NULL ;
if ( T_1 -> V_138 . V_139 ) {
T_2 V_140 = sizeof( struct V_141 ) ;
V_140 += T_1 -> V_138 . V_142 * sizeof( T_4 ) ;
V_26 -> V_143 = F_55 ( V_140 ) ;
if ( ! V_26 -> V_143 )
goto V_144;
}
if ( T_1 -> V_138 . V_145 ) {
T_2 V_140 = sizeof( struct V_146 ) ;
V_140 += T_1 -> V_138 . V_147 *
sizeof( struct V_148 ) ;
V_26 -> V_145 = F_55 ( V_140 ) ;
if ( ! V_26 -> V_145 )
goto V_144;
V_26 -> V_149 = F_55 ( V_140 ) ;
if ( ! V_26 -> V_149 )
goto V_144;
}
V_26 -> V_150 = malloc ( V_151 ) ;
if ( ! V_26 -> V_150 )
goto V_144;
V_26 -> T_1 = T_1 ;
V_26 -> V_33 = V_33 ;
V_26 -> V_120 = F_45 ( T_1 ) ;
V_26 -> V_31 = - 1 ;
V_26 -> V_32 = - 1 ;
V_26 -> V_30 = - 1 ;
V_26 -> V_152 = - 1 ;
V_136 . V_137 = F_13 ;
V_136 . V_153 = F_32 ;
V_136 . V_19 = V_26 ;
V_136 . V_154 = F_47 ( T_1 ) ;
V_136 . V_155 = F_48 ( T_1 ) ;
V_136 . V_156 = T_1 -> V_156 ;
V_136 . V_157 = F_49 ( T_1 ) ;
V_136 . V_158 = T_1 -> V_158 ;
V_136 . V_159 = T_1 -> V_159 ;
if ( T_1 -> V_160 . V_161 > 0 )
V_136 . V_162 = F_43 ;
if ( T_1 -> V_138 . V_163 ) {
if ( T_1 -> V_138 . V_164 ) {
switch ( T_1 -> V_138 . V_165 ) {
case V_166 :
V_136 . V_165 =
V_167 ;
V_136 . V_164 = T_1 -> V_138 . V_164 ;
break;
case V_168 :
V_136 . V_165 = V_169 ;
V_136 . V_164 = T_1 -> V_138 . V_164 ;
break;
case V_170 :
V_136 . V_165 = V_169 ;
V_136 . V_164 = F_53 ( T_1 ,
T_1 -> V_138 . V_164 ) ;
break;
default:
break;
}
}
if ( ! V_136 . V_164 ) {
V_136 . V_165 = V_167 ;
V_136 . V_164 = 1 ;
}
}
V_26 -> V_171 = F_56 ( & V_136 ) ;
if ( ! V_26 -> V_171 )
goto V_144;
return V_26 ;
V_144:
F_57 ( & V_26 -> V_150 ) ;
F_57 ( & V_26 -> V_145 ) ;
F_57 ( & V_26 -> V_149 ) ;
F_57 ( & V_26 -> V_143 ) ;
free ( V_26 ) ;
return NULL ;
}
static void F_58 ( void * V_172 )
{
struct V_25 * V_26 = V_172 ;
if ( ! V_26 )
return;
F_10 ( V_26 -> V_34 ) ;
F_59 ( V_26 -> V_171 ) ;
F_57 ( & V_26 -> V_150 ) ;
F_57 ( & V_26 -> V_145 ) ;
F_57 ( & V_26 -> V_149 ) ;
F_57 ( & V_26 -> V_143 ) ;
free ( V_26 ) ;
}
static void F_60 ( struct V_1 * T_1 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_172 ;
if ( V_28 -> V_32 == - 1 || T_1 -> V_173 ) {
V_26 -> V_32 = F_61 ( T_1 -> V_35 , V_26 -> V_30 ) ;
F_10 ( V_26 -> V_34 ) ;
}
if ( ! V_26 -> V_34 && V_26 -> V_32 != - 1 )
V_26 -> V_34 = F_12 ( T_1 -> V_35 , - 1 , V_26 -> V_32 ) ;
if ( V_26 -> V_34 ) {
V_26 -> V_31 = V_26 -> V_34 -> V_174 ;
if ( V_28 -> V_30 == - 1 )
V_26 -> V_30 = V_26 -> V_34 -> V_30 ;
}
}
static void F_62 ( struct V_25 * V_26 )
{
if ( V_26 -> V_175 -> V_176 & V_177 ) {
V_26 -> V_176 = V_178 | V_179 ;
} else if ( V_26 -> V_175 -> V_176 & V_180 ) {
if ( V_26 -> V_175 -> V_80 )
V_26 -> V_176 = V_178 | V_181 |
V_182 |
V_183 ;
else
V_26 -> V_176 = V_178 |
V_184 ;
V_26 -> V_185 = 0 ;
} else {
if ( V_26 -> V_175 -> V_186 )
V_26 -> V_176 = F_63 ( V_26 -> V_175 -> V_187 ) ;
else
V_26 -> V_176 = V_178 |
V_188 ;
if ( V_26 -> V_175 -> V_176 & V_189 )
V_26 -> V_176 |= V_190 ;
V_26 -> V_185 = V_26 -> V_175 -> V_185 ;
memcpy ( V_26 -> V_75 , V_26 -> V_175 -> V_75 , V_76 ) ;
}
}
static int F_64 ( struct V_1 * T_1 ,
struct V_27 * V_28 ,
unsigned int V_33 )
{
struct V_25 * V_26 = V_28 -> V_172 ;
if ( F_65 ( & V_28 -> V_191 ) )
return 0 ;
if ( ! V_26 ) {
V_26 = F_54 ( T_1 , V_33 ) ;
if ( ! V_26 )
return - V_45 ;
V_28 -> V_172 = V_26 ;
if ( V_28 -> V_30 != - 1 )
V_26 -> V_30 = V_28 -> V_30 ;
V_26 -> V_32 = V_28 -> V_32 ;
if ( T_1 -> V_50 ) {
if ( T_1 -> V_124 )
V_26 -> V_54 = true ;
if ( T_1 -> V_124 || ! T_1 -> V_173 )
V_26 -> V_53 = true ;
}
}
if ( ! V_26 -> V_192 &&
( ! T_1 -> V_193 ||
V_26 -> V_194 != V_195 ) ) {
const struct V_196 * V_175 ;
int V_8 ;
if ( T_1 -> V_124 )
return 0 ;
F_9 ( L_20 , V_33 ) ;
F_9 ( L_21 ,
V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_175 = F_66 ( V_26 -> V_171 ) ;
if ( V_175 -> V_70 ) {
if ( V_175 -> V_70 == V_197 ) {
F_9 ( L_22 ,
V_33 ) ;
return 0 ;
}
continue;
}
if ( V_175 -> V_198 )
break;
}
V_26 -> V_198 = V_175 -> V_198 ;
F_9 ( L_23 V_112 L_15 ,
V_33 , V_26 -> V_198 ) ;
V_26 -> V_175 = V_175 ;
V_26 -> V_199 = true ;
F_62 ( V_26 ) ;
V_8 = F_67 ( & T_1 -> V_200 , V_33 , V_26 -> V_198 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_192 = true ;
}
return 0 ;
}
static int F_68 ( struct V_1 * T_1 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < T_1 -> V_39 . V_201 ; V_10 ++ ) {
V_8 = F_64 ( T_1 , & T_1 -> V_39 . V_40 [ V_10 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static inline void F_69 ( struct V_25 * V_26 )
{
struct V_146 * V_202 = V_26 -> V_149 ;
struct V_146 * V_203 = V_26 -> V_145 ;
T_2 V_204 = 0 ;
V_203 -> V_204 = V_202 -> V_204 ;
if ( ! V_202 -> V_204 )
return;
V_204 = V_26 -> T_1 -> V_138 . V_147 - V_26 -> V_205 ;
memcpy ( & V_203 -> V_206 [ 0 ] ,
& V_202 -> V_206 [ V_26 -> V_205 ] ,
sizeof( struct V_148 ) * V_204 ) ;
if ( V_202 -> V_204 >= V_26 -> T_1 -> V_138 . V_147 ) {
memcpy ( & V_203 -> V_206 [ V_204 ] ,
& V_202 -> V_206 [ 0 ] ,
sizeof( struct V_148 ) * V_26 -> V_205 ) ;
}
}
static inline void F_70 ( struct V_25 * V_26 )
{
V_26 -> V_205 = 0 ;
V_26 -> V_149 -> V_204 = 0 ;
}
static void F_71 ( struct V_25 * V_26 )
{
const struct V_196 * V_175 = V_26 -> V_175 ;
struct V_146 * V_207 = V_26 -> V_149 ;
struct V_148 * V_208 ;
if ( ! V_26 -> V_205 )
V_26 -> V_205 = V_26 -> T_1 -> V_138 . V_147 ;
V_26 -> V_205 -= 1 ;
V_208 = & V_207 -> V_206 [ V_26 -> V_205 ] ;
V_208 -> V_209 = V_175 -> V_186 ;
V_208 -> V_210 = V_175 -> V_80 ;
V_208 -> V_176 . abort = ! ! ( V_175 -> V_176 & V_177 ) ;
V_208 -> V_176 . V_211 = ! ! ( V_175 -> V_176 & V_189 ) ;
V_208 -> V_176 . V_212 = V_26 -> T_1 -> V_213 ;
if ( V_207 -> V_204 < V_26 -> T_1 -> V_138 . V_147 )
V_207 -> V_204 += 1 ;
}
static inline bool F_72 ( struct V_1 * T_1 )
{
return T_1 -> V_138 . V_214 &&
T_1 -> V_215 ++ < T_1 -> V_138 . V_214 ;
}
static void F_73 ( struct V_1 * T_1 ,
struct V_25 * V_26 ,
union V_216 * V_217 ,
struct V_218 * V_219 )
{
V_217 -> V_219 . V_220 . type = V_221 ;
V_217 -> V_219 . V_220 . V_222 = V_92 ;
V_217 -> V_219 . V_220 . V_20 = sizeof( struct V_223 ) ;
if ( ! T_1 -> V_124 )
V_219 -> time = F_74 ( V_26 -> V_198 , & T_1 -> V_132 ) ;
V_219 -> V_85 = V_92 ;
V_219 -> V_79 = V_26 -> V_175 -> V_186 ;
V_219 -> V_31 = V_26 -> V_31 ;
V_219 -> V_32 = V_26 -> V_32 ;
V_219 -> V_111 = V_26 -> V_175 -> V_80 ;
V_219 -> V_164 = 1 ;
V_219 -> V_30 = V_26 -> V_30 ;
V_219 -> V_176 = V_26 -> V_176 ;
V_219 -> V_185 = V_26 -> V_185 ;
memcpy ( V_219 -> V_75 , V_26 -> V_75 , V_76 ) ;
}
static int F_75 ( union V_216 * V_217 ,
struct V_218 * V_219 , T_4 type ,
bool V_224 )
{
V_217 -> V_220 . V_20 = F_76 ( V_219 , type , 0 ) ;
return F_77 ( V_217 , type , 0 , V_219 , V_224 ) ;
}
static inline int F_78 ( struct V_1 * T_1 ,
union V_216 * V_217 ,
struct V_218 * V_219 , T_4 type )
{
if ( ! T_1 -> V_138 . V_225 )
return 0 ;
return F_75 ( V_217 , V_219 , type , T_1 -> V_226 ) ;
}
static int F_79 ( struct V_1 * T_1 ,
union V_216 * V_217 ,
struct V_218 * V_219 , T_4 type )
{
int V_8 ;
V_8 = F_78 ( T_1 , V_217 , V_219 , type ) ;
if ( V_8 )
return V_8 ;
V_8 = F_80 ( T_1 -> V_43 , V_217 , V_219 ) ;
if ( V_8 )
F_81 ( L_24 , V_8 ) ;
return V_8 ;
}
static int F_82 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_227 {
T_4 V_204 ;
struct V_148 V_206 ;
} V_228 ;
if ( T_1 -> V_229 && ! ( T_1 -> V_229 & V_26 -> V_176 ) )
return 0 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_73 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_231 ;
V_219 . V_232 = V_26 -> T_1 -> V_231 ;
if ( T_1 -> V_138 . V_145 && V_233 == V_234 ) {
V_228 = (struct V_227 ) {
. V_204 = 1 ,
. V_206 = {
. V_209 = V_219 . V_79 ,
. V_210 = V_219 . V_111 ,
} ,
} ;
V_219 . V_146 = (struct V_146 * ) & V_228 ;
}
return F_79 ( T_1 , V_217 , & V_219 ,
T_1 -> V_235 ) ;
}
static void F_83 ( struct V_1 * T_1 ,
struct V_25 * V_26 ,
union V_216 * V_217 ,
struct V_218 * V_219 )
{
F_73 ( T_1 , V_26 , V_217 , V_219 ) ;
if ( T_1 -> V_138 . V_139 ) {
F_84 ( V_26 -> V_34 , V_26 -> V_143 ,
T_1 -> V_138 . V_142 , V_219 -> V_79 ) ;
V_219 -> V_139 = V_26 -> V_143 ;
}
if ( T_1 -> V_138 . V_145 ) {
F_69 ( V_26 ) ;
V_219 -> V_146 = V_26 -> V_145 ;
}
}
static inline int F_85 ( struct V_1 * T_1 ,
struct V_25 * V_26 ,
union V_216 * V_217 ,
struct V_218 * V_219 ,
T_4 type )
{
int V_8 ;
V_8 = F_79 ( T_1 , V_217 , V_219 , type ) ;
if ( T_1 -> V_138 . V_145 )
F_70 ( V_26 ) ;
return V_8 ;
}
static int F_86 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
if ( F_72 ( T_1 ) )
return 0 ;
F_83 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_236 ;
V_219 . V_232 = V_26 -> T_1 -> V_236 ;
V_219 . V_164 = V_26 -> V_175 -> V_237 - V_26 -> V_238 ;
V_26 -> V_238 = V_26 -> V_175 -> V_237 ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_239 ) ;
}
static int F_87 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
if ( F_72 ( T_1 ) )
return 0 ;
F_83 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_240 ;
V_219 . V_232 = V_26 -> T_1 -> V_240 ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_241 ) ;
}
static void F_88 ( struct V_1 * T_1 ,
struct V_25 * V_26 ,
union V_216 * V_217 ,
struct V_218 * V_219 )
{
F_83 ( T_1 , V_26 , V_217 , V_219 ) ;
if ( ! V_219 -> V_79 )
V_219 -> V_176 = 0 ;
}
static int F_89 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_242 V_243 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_244 ;
V_219 . V_232 = V_26 -> T_1 -> V_244 ;
V_243 . V_176 = 0 ;
V_243 . V_79 = ! ! ( V_26 -> V_175 -> V_176 & V_245 ) ;
V_243 . V_246 = F_90 ( V_26 -> V_175 -> V_247 ) ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_250 ) ;
}
static int F_93 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_251 V_243 ;
T_8 V_176 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_252 ;
V_219 . V_232 = V_26 -> T_1 -> V_252 ;
V_176 = ( V_253 ) V_26 -> V_175 -> V_254 | ( T_1 -> V_156 << 16 ) ;
V_243 . V_176 = F_94 ( V_176 ) ;
V_243 . V_255 = F_94 ( V_243 . V_256 * T_1 -> V_257 ) ;
V_243 . V_258 = 0 ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_259 ) ;
}
static int F_95 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_260 V_243 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_261 ;
V_219 . V_232 = V_26 -> T_1 -> V_261 ;
V_243 . V_262 = 0 ;
V_243 . V_246 = F_90 ( V_26 -> V_175 -> V_263 ) ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_259 ) ;
}
static int F_96 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_264 V_243 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_265 ;
V_219 . V_232 = V_26 -> T_1 -> V_265 ;
V_243 . V_262 = 0 ;
V_243 . V_246 = F_90 ( V_26 -> V_175 -> V_266 ) ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_259 ) ;
}
static int F_97 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_267 V_243 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_268 ;
V_219 . V_232 = V_26 -> T_1 -> V_268 ;
V_243 . V_176 = 0 ;
V_243 . V_79 = ! ! ( V_26 -> V_175 -> V_176 & V_245 ) ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_259 ) ;
}
static int F_98 ( struct V_25 * V_26 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
union V_216 * V_217 = V_26 -> V_150 ;
struct V_218 V_219 = { . V_79 = 0 , } ;
struct V_269 V_243 ;
if ( F_72 ( T_1 ) )
return 0 ;
F_88 ( T_1 , V_26 , V_217 , & V_219 ) ;
V_219 . V_230 = V_26 -> T_1 -> V_270 ;
V_219 . V_232 = V_26 -> T_1 -> V_270 ;
V_243 . V_262 = 0 ;
V_243 . V_246 = F_90 ( V_26 -> V_175 -> V_271 ) ;
V_219 . V_248 = F_91 ( V_243 ) ;
V_219 . V_249 = F_92 ( & V_243 ) ;
return F_85 ( T_1 , V_26 , V_217 , & V_219 ,
T_1 -> V_259 ) ;
}
static int F_99 ( struct V_1 * T_1 , int V_272 , int V_30 ,
T_9 V_31 , T_9 V_32 , T_4 V_79 )
{
union V_216 V_217 ;
char V_273 [ V_274 ] ;
int V_70 ;
F_100 ( V_272 , V_273 , V_274 ) ;
F_101 ( & V_217 . V_275 , V_276 ,
V_272 , V_30 , V_31 , V_32 , V_79 , V_273 ) ;
V_70 = F_80 ( T_1 -> V_43 , & V_217 , NULL ) ;
if ( V_70 )
F_81 ( L_25 ,
V_70 ) ;
return V_70 ;
}
static int F_102 ( struct V_1 * T_1 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_9 V_32 = V_26 -> V_152 ;
int V_70 ;
if ( V_32 == - 1 )
return 0 ;
F_9 ( L_26 , V_26 -> V_30 , V_32 ) ;
V_70 = F_103 ( T_1 -> V_35 , V_26 -> V_30 , - 1 , V_32 ) ;
V_28 = & T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
F_60 ( T_1 , V_28 ) ;
V_26 -> V_152 = - 1 ;
return V_70 ;
}
static inline bool F_104 ( struct V_25 * V_26 , T_4 V_79 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
return V_79 == T_1 -> V_277 &&
( V_26 -> V_176 & V_178 ) &&
! ( V_26 -> V_176 & ( V_278 | V_182 |
V_183 | V_179 ) ) ;
}
static int F_105 ( struct V_25 * V_26 )
{
const struct V_196 * V_175 = V_26 -> V_175 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! V_26 -> V_199 )
return 0 ;
V_26 -> V_199 = false ;
if ( T_1 -> V_279 && ( V_175 -> type & V_280 ) ) {
if ( V_175 -> type & V_281 ) {
V_70 = F_93 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_175 -> type & V_282 ) {
V_70 = F_95 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_175 -> type & V_283 ) {
V_70 = F_96 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_175 -> type & V_284 ) {
V_70 = F_97 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_175 -> type & V_285 ) {
V_70 = F_98 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
}
if ( T_1 -> V_286 && ( V_175 -> type & V_287 ) ) {
V_70 = F_86 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_288 && ( V_175 -> type & V_289 ) ) {
V_70 = F_87 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_290 && ( V_175 -> type & V_291 ) ) {
V_70 = F_89 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( ! ( V_175 -> type & V_292 ) )
return 0 ;
if ( T_1 -> V_138 . V_139 || T_1 -> V_138 . V_293 )
F_106 ( V_26 -> V_34 , V_26 -> V_176 , V_175 -> V_186 ,
V_175 -> V_80 , V_26 -> V_185 ,
V_175 -> V_51 ) ;
else
F_107 ( V_26 -> V_34 , V_175 -> V_51 ) ;
if ( T_1 -> V_294 ) {
V_70 = F_82 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_138 . V_145 )
F_71 ( V_26 ) ;
if ( ! T_1 -> V_193 )
return 0 ;
if ( F_104 ( V_26 , V_175 -> V_80 ) ) {
switch ( V_26 -> V_194 ) {
case V_295 :
case V_296 :
V_70 = F_102 ( T_1 , V_26 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_194 = V_297 ;
break;
default:
V_26 -> V_194 = V_195 ;
return 1 ;
}
} else if ( ! V_175 -> V_80 ) {
V_26 -> V_194 = V_298 ;
} else if ( V_26 -> V_194 == V_298 ) {
V_26 -> V_194 = V_295 ;
} else if ( V_26 -> V_194 == V_295 &&
V_175 -> V_80 == T_1 -> V_299 &&
( V_26 -> V_176 & V_181 ) ) {
V_26 -> V_194 = V_297 ;
}
return 0 ;
}
static T_4 F_108 ( struct V_1 * T_1 , T_4 * V_299 )
{
struct V_35 * V_35 = T_1 -> V_35 ;
struct V_95 * V_95 ;
struct V_300 * V_301 , * V_18 ;
T_4 V_79 , V_277 = 0 ;
const char * V_302 ;
if ( V_299 )
* V_299 = 0 ;
V_95 = F_109 ( V_35 ) ;
if ( ! V_95 )
return 0 ;
if ( F_36 ( V_95 ) )
return 0 ;
V_18 = F_110 ( V_95 -> V_60 , V_94 ) ;
for ( V_301 = V_18 ; V_301 ; V_301 = F_111 ( V_301 ) ) {
if ( V_301 -> V_303 == V_304 &&
! strcmp ( V_301 -> V_305 , L_27 ) ) {
V_79 = V_95 -> V_306 ( V_95 , V_301 -> V_18 ) ;
if ( V_79 >= V_95 -> V_18 && V_79 < V_95 -> V_104 ) {
V_277 = V_79 ;
break;
}
}
}
if ( ! V_277 || ! V_299 )
return 0 ;
if ( T_1 -> V_173 == 1 )
V_302 = L_28 ;
else
V_302 = L_29 ;
for ( V_301 = V_18 ; V_301 ; V_301 = F_111 ( V_301 ) ) {
if ( ! strcmp ( V_301 -> V_305 , V_302 ) ) {
V_79 = V_95 -> V_306 ( V_95 , V_301 -> V_18 ) ;
if ( V_79 >= V_95 -> V_18 && V_79 < V_95 -> V_104 ) {
* V_299 = V_79 ;
break;
}
}
}
return V_277 ;
}
static int F_112 ( struct V_25 * V_26 , T_4 * V_198 )
{
const struct V_196 * V_175 = V_26 -> V_175 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! T_1 -> V_90 ) {
T_1 -> V_90 = F_113 ( T_1 -> V_35 ) ;
if ( T_1 -> V_307 &&
( T_1 -> V_173 == 1 || T_1 -> V_173 == 3 ) &&
! T_1 -> V_124 && F_51 ( T_1 ) &&
! T_1 -> V_50 ) {
T_1 -> V_277 = F_108 ( T_1 , & T_1 -> V_299 ) ;
if ( T_1 -> V_277 ) {
F_9 ( L_30 V_112 L_31 V_112 L_15 ,
T_1 -> V_277 , T_1 -> V_299 ) ;
T_1 -> V_193 = true ;
}
}
}
F_9 ( L_21 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_70 = F_105 ( V_26 ) ;
if ( V_70 )
return V_70 ;
V_175 = F_66 ( V_26 -> V_171 ) ;
if ( V_175 -> V_70 ) {
if ( V_175 -> V_70 == V_197 )
return 1 ;
if ( T_1 -> V_193 &&
V_175 -> V_186 >= T_1 -> V_90 ) {
T_1 -> V_193 = false ;
F_102 ( T_1 , V_26 ) ;
}
if ( T_1 -> V_138 . V_308 ) {
V_70 = F_99 ( T_1 , V_175 -> V_70 ,
V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_32 ,
V_175 -> V_186 ) ;
if ( V_70 )
return V_70 ;
}
continue;
}
V_26 -> V_175 = V_175 ;
V_26 -> V_199 = true ;
F_62 ( V_26 ) ;
if ( T_1 -> V_309 &&
( V_175 -> V_186 >= T_1 -> V_90 || ! V_175 -> V_186 ) &&
V_175 -> V_80 && V_175 -> V_80 < T_1 -> V_90 ) {
F_9 ( L_32 V_112 L_33 V_112 L_15 ,
V_175 -> V_198 , V_175 -> V_310 ) ;
V_26 -> V_198 = V_175 -> V_310 ;
} else if ( T_1 -> V_193 &&
V_26 -> V_194 == V_295 &&
F_104 ( V_26 , V_175 -> V_80 ) &&
V_26 -> V_152 == - 1 ) {
F_9 ( L_32 V_112 L_33 V_112 L_15 ,
V_175 -> V_198 , V_175 -> V_310 ) ;
V_26 -> V_198 = V_175 -> V_310 ;
} else if ( V_175 -> V_198 > V_26 -> V_198 ) {
V_26 -> V_198 = V_175 -> V_198 ;
}
if ( ! T_1 -> V_124 && V_26 -> V_198 >= * V_198 ) {
* V_198 = V_26 -> V_198 ;
return 0 ;
}
}
return 0 ;
}
static inline int F_114 ( struct V_1 * T_1 )
{
if ( T_1 -> V_39 . V_311 ) {
T_1 -> V_39 . V_311 = false ;
return F_68 ( T_1 ) ;
}
return 0 ;
}
static int F_115 ( struct V_1 * T_1 , T_4 V_198 )
{
unsigned int V_33 ;
T_4 V_312 ;
int V_8 ;
while ( 1 ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
if ( ! T_1 -> V_200 . V_313 )
return 0 ;
if ( T_1 -> V_200 . V_314 [ 0 ] . V_315 >= V_198 )
return 0 ;
V_33 = T_1 -> V_200 . V_314 [ 0 ] . V_33 ;
V_28 = & T_1 -> V_39 . V_40 [ V_33 ] ;
V_26 = V_28 -> V_172 ;
F_9 ( L_34 V_112 L_35 V_112 L_15 ,
V_33 , T_1 -> V_200 . V_314 [ 0 ] . V_315 ,
V_198 ) ;
F_116 ( & T_1 -> V_200 ) ;
if ( T_1 -> V_200 . V_313 ) {
V_312 = T_1 -> V_200 . V_314 [ 0 ] . V_315 + 1 ;
if ( V_312 > V_198 )
V_312 = V_198 ;
} else {
V_312 = V_198 ;
}
F_60 ( T_1 , V_28 ) ;
V_8 = F_112 ( V_26 , & V_312 ) ;
if ( V_8 < 0 ) {
F_67 ( & T_1 -> V_200 , V_33 , V_312 ) ;
return V_8 ;
}
if ( ! V_8 ) {
V_8 = F_67 ( & T_1 -> V_200 , V_33 , V_312 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_26 -> V_192 = false ;
}
}
return 0 ;
}
static int F_117 ( struct V_1 * T_1 , T_9 V_32 ,
T_4 V_316 )
{
struct V_317 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
T_4 V_312 = 0 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_201 ; V_10 ++ ) {
struct V_27 * V_28 = & T_1 -> V_39 . V_40 [ V_10 ] ;
struct V_25 * V_26 = V_28 -> V_172 ;
if ( V_26 && ( V_32 == - 1 || V_26 -> V_32 == V_32 ) ) {
V_26 -> time = V_316 ;
F_60 ( T_1 , V_28 ) ;
F_112 ( V_26 , & V_312 ) ;
}
}
return 0 ;
}
static int F_118 ( struct V_1 * T_1 , struct V_218 * V_219 )
{
return F_99 ( T_1 , V_318 , V_219 -> V_30 ,
V_219 -> V_31 , V_219 -> V_32 , 0 ) ;
}
static struct V_25 * F_119 ( struct V_1 * T_1 , int V_30 )
{
unsigned V_10 , V_319 ;
if ( V_30 < 0 || ! T_1 -> V_39 . V_201 )
return NULL ;
if ( ( unsigned ) V_30 >= T_1 -> V_39 . V_201 )
V_10 = T_1 -> V_39 . V_201 - 1 ;
else
V_10 = V_30 ;
if ( T_1 -> V_39 . V_40 [ V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_172 ;
for ( V_319 = 0 ; V_10 > 0 ; V_319 ++ ) {
if ( T_1 -> V_39 . V_40 [ -- V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_172 ;
}
for (; V_319 < T_1 -> V_39 . V_201 ; V_319 ++ ) {
if ( T_1 -> V_39 . V_40 [ V_319 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_319 ] . V_172 ;
}
return NULL ;
}
static int F_120 ( struct V_1 * T_1 , int V_30 , T_9 V_32 ,
T_4 V_198 )
{
struct V_25 * V_26 ;
int V_70 ;
if ( ! T_1 -> V_193 )
return 1 ;
V_26 = F_119 ( T_1 , V_30 ) ;
if ( ! V_26 )
return 1 ;
switch ( V_26 -> V_194 ) {
case V_298 :
V_26 -> V_152 = - 1 ;
break;
case V_295 :
case V_297 :
V_26 -> V_152 = V_32 ;
V_26 -> V_194 = V_296 ;
return 0 ;
case V_195 :
if ( ! V_26 -> V_192 ) {
V_26 -> V_198 = F_121 ( V_198 ,
& T_1 -> V_132 ) ;
V_70 = F_67 ( & T_1 -> V_200 , V_26 -> V_33 ,
V_26 -> V_198 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_192 = true ;
}
V_26 -> V_194 = V_297 ;
break;
case V_296 :
V_26 -> V_152 = V_32 ;
F_9 ( L_36 , V_30 ) ;
break;
default:
break;
}
return 1 ;
}
static int F_122 ( struct V_1 * T_1 ,
struct V_218 * V_219 )
{
struct V_118 * V_119 ;
T_9 V_32 ;
int V_30 , V_8 ;
V_119 = F_123 ( T_1 -> V_43 -> V_320 , V_219 -> V_230 ) ;
if ( V_119 != T_1 -> V_321 )
return 0 ;
V_32 = F_124 ( V_119 , V_219 , L_37 ) ;
V_30 = V_219 -> V_30 ;
F_9 ( L_38 V_322 L_39 V_112 L_15 ,
V_30 , V_32 , V_219 -> time , F_121 ( V_219 -> time ,
& T_1 -> V_132 ) ) ;
V_8 = F_120 ( T_1 , V_30 , V_32 , V_219 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_103 ( T_1 -> V_35 , V_30 , - 1 , V_32 ) ;
}
static int F_125 ( struct V_1 * T_1 , union V_216 * V_217 ,
struct V_218 * V_219 )
{
bool V_103 = V_217 -> V_220 . V_222 & V_323 ;
T_9 V_31 , V_32 ;
int V_30 , V_8 ;
V_30 = V_219 -> V_30 ;
if ( T_1 -> V_173 == 3 ) {
if ( ! V_103 )
return 0 ;
if ( V_217 -> V_220 . type != V_324 ) {
F_81 ( L_40 ) ;
return - V_22 ;
}
V_31 = V_217 -> V_325 . V_326 ;
V_32 = V_217 -> V_325 . V_327 ;
} else {
if ( V_103 )
return 0 ;
V_31 = V_219 -> V_31 ;
V_32 = V_219 -> V_32 ;
}
if ( V_32 == - 1 ) {
F_81 ( L_41 ) ;
return - V_22 ;
}
F_9 ( L_42 V_322 L_39 V_112 L_15 ,
V_30 , V_31 , V_32 , V_219 -> time , F_121 ( V_219 -> time ,
& T_1 -> V_132 ) ) ;
V_8 = F_120 ( T_1 , V_30 , V_32 , V_219 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_103 ( T_1 -> V_35 , V_30 , V_31 , V_32 ) ;
}
static int F_126 ( struct V_1 * T_1 ,
union V_216 * V_217 ,
struct V_218 * V_219 )
{
if ( ! T_1 -> V_307 )
return 0 ;
F_9 ( L_43 V_322 L_39 V_112 L_15 ,
V_219 -> V_30 , V_217 -> V_328 . V_31 ,
V_217 -> V_328 . V_32 , V_219 -> time ,
F_121 ( V_219 -> time , & T_1 -> V_132 ) ) ;
return F_103 ( T_1 -> V_35 , V_219 -> V_30 ,
V_217 -> V_328 . V_31 ,
V_217 -> V_328 . V_32 ) ;
}
static int F_127 ( struct V_329 * V_43 ,
union V_216 * V_217 ,
struct V_218 * V_219 ,
struct V_330 * V_331 )
{
struct V_1 * T_1 = F_128 ( V_43 -> V_332 , struct V_1 ,
V_332 ) ;
T_4 V_198 ;
int V_70 = 0 ;
if ( V_333 )
return 0 ;
if ( ! V_331 -> V_334 ) {
F_81 ( L_44 ) ;
return - V_22 ;
}
if ( V_219 -> time && V_219 -> time != ( T_4 ) - 1 )
V_198 = F_121 ( V_219 -> time , & T_1 -> V_132 ) ;
else
V_198 = 0 ;
if ( V_198 || T_1 -> V_124 ) {
V_70 = F_114 ( T_1 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_124 ) {
if ( V_217 -> V_220 . type == V_335 ) {
V_70 = F_117 ( T_1 ,
V_217 -> V_336 . V_32 ,
V_219 -> time ) ;
}
} else if ( V_198 ) {
V_70 = F_115 ( T_1 , V_198 ) ;
}
if ( V_70 )
return V_70 ;
if ( V_217 -> V_220 . type == V_337 &&
( V_217 -> V_338 . V_176 & V_339 ) &&
T_1 -> V_138 . V_308 ) {
V_70 = F_118 ( T_1 , V_219 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_321 && V_217 -> V_220 . type == V_221 )
V_70 = F_122 ( T_1 , V_219 ) ;
else if ( V_217 -> V_220 . type == V_340 )
V_70 = F_126 ( T_1 , V_217 , V_219 ) ;
else if ( V_217 -> V_220 . type == V_341 ||
V_217 -> V_220 . type == V_324 )
V_70 = F_125 ( T_1 , V_217 , V_219 ) ;
F_9 ( L_45 V_322 L_39 V_112 L_15 ,
F_129 ( V_217 -> V_220 . type ) , V_217 -> V_220 . type ,
V_219 -> V_30 , V_219 -> time , V_198 ) ;
return V_70 ;
}
static int F_130 ( struct V_329 * V_43 , struct V_330 * V_331 )
{
struct V_1 * T_1 = F_128 ( V_43 -> V_332 , struct V_1 ,
V_332 ) ;
int V_8 ;
if ( V_333 )
return 0 ;
if ( ! V_331 -> V_334 )
return - V_22 ;
V_8 = F_114 ( T_1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( T_1 -> V_124 )
return F_117 ( T_1 , - 1 ,
V_342 - 1 ) ;
return F_115 ( T_1 , V_342 ) ;
}
static void F_131 ( struct V_329 * V_43 )
{
struct V_1 * T_1 = F_128 ( V_43 -> V_332 , struct V_1 ,
V_332 ) ;
struct V_317 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_201 ; V_10 ++ ) {
F_58 ( V_39 -> V_40 [ V_10 ] . V_172 ) ;
V_39 -> V_40 [ V_10 ] . V_172 = NULL ;
}
F_132 () ;
F_133 ( V_39 ) ;
}
static void F_134 ( struct V_329 * V_43 )
{
struct V_1 * T_1 = F_128 ( V_43 -> V_332 , struct V_1 ,
V_332 ) ;
F_135 ( & T_1 -> V_200 ) ;
F_131 ( V_43 ) ;
V_43 -> V_332 = NULL ;
F_136 ( T_1 -> V_93 ) ;
F_137 ( & T_1 -> V_160 ) ;
F_57 ( & T_1 -> V_343 ) ;
free ( T_1 ) ;
}
static int F_138 ( struct V_329 * V_43 ,
union V_216 * V_217 ,
struct V_330 * V_331 V_2 )
{
struct V_1 * T_1 = F_128 ( V_43 -> V_332 , struct V_1 ,
V_332 ) ;
if ( T_1 -> V_50 )
return 0 ;
if ( ! T_1 -> V_344 ) {
struct V_15 * V_29 ;
T_3 V_345 ;
int V_42 = F_16 ( V_43 -> V_44 ) ;
int V_70 ;
if ( F_139 ( V_43 -> V_44 ) ) {
V_345 = 0 ;
} else {
V_345 = F_140 ( V_42 , 0 , V_346 ) ;
if ( V_345 == - 1 )
return - V_347 ;
}
V_70 = F_141 ( & T_1 -> V_39 , V_43 , V_217 ,
V_345 , & V_29 ) ;
if ( V_70 )
return V_70 ;
if ( V_333 ) {
if ( F_17 ( V_29 , V_42 ) ) {
F_5 ( T_1 , V_29 -> V_19 ,
V_29 -> V_20 ) ;
F_142 ( V_29 ) ;
}
}
}
return 0 ;
}
static int F_143 ( struct V_330 * V_331 ,
union V_216 * V_217 ,
struct V_218 * V_219 V_2 ,
struct V_35 * V_35 V_2 )
{
struct V_348 * V_348 =
F_128 ( V_331 , struct V_348 , V_349 ) ;
return F_80 ( V_348 -> V_43 , V_217 ,
NULL ) ;
}
static int F_144 ( struct V_329 * V_43 , const char * V_305 ,
struct V_114 * V_115 , T_4 V_230 )
{
struct V_348 V_348 ;
int V_70 ;
F_145 ( L_46 V_322 L_47 V_112 L_15 ,
V_305 , V_230 , ( T_4 ) V_115 -> V_127 ) ;
memset ( & V_348 , 0 , sizeof( struct V_348 ) ) ;
V_348 . V_43 = V_43 ;
V_70 = F_146 ( & V_348 . V_349 , V_115 , 1 ,
& V_230 , F_143 ) ;
if ( V_70 )
F_81 ( L_48 ,
V_350 , V_305 ) ;
return V_70 ;
}
static void F_147 ( struct V_351 * V_320 , T_4 V_230 ,
const char * V_305 )
{
struct V_118 * V_119 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_230 && V_119 -> V_230 [ 0 ] == V_230 ) {
if ( V_119 -> V_305 )
F_57 ( & V_119 -> V_305 ) ;
V_119 -> V_305 = F_148 ( V_305 ) ;
break;
}
}
}
static struct V_118 * F_149 ( struct V_1 * T_1 ,
struct V_351 * V_320 )
{
struct V_118 * V_119 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_115 . type == T_1 -> V_117 && V_119 -> V_352 )
return V_119 ;
}
return NULL ;
}
static int F_150 ( struct V_1 * T_1 ,
struct V_329 * V_43 )
{
struct V_351 * V_320 = V_43 -> V_320 ;
struct V_118 * V_119 = F_149 ( T_1 , V_320 ) ;
struct V_114 V_115 ;
T_4 V_230 ;
int V_70 ;
if ( ! V_119 ) {
F_145 ( L_49 ) ;
return 0 ;
}
memset ( & V_115 , 0 , sizeof( struct V_114 ) ) ;
V_115 . V_20 = sizeof( struct V_114 ) ;
V_115 . type = V_353 ;
V_115 . V_127 = V_119 -> V_115 . V_127 & V_354 ;
V_115 . V_127 |= V_355 | V_356 |
V_357 ;
if ( T_1 -> V_124 )
V_115 . V_127 &= ~ ( T_4 ) V_128 ;
else
V_115 . V_127 |= V_128 ;
if ( ! T_1 -> V_307 )
V_115 . V_127 &= ~ ( T_4 ) V_358 ;
V_115 . V_359 = V_119 -> V_115 . V_359 ;
V_115 . V_120 = V_119 -> V_115 . V_120 ;
V_115 . V_360 = V_119 -> V_115 . V_360 ;
V_115 . V_361 = V_119 -> V_115 . V_361 ;
V_115 . V_362 = V_119 -> V_115 . V_362 ;
V_115 . V_363 = V_119 -> V_115 . V_363 ;
V_115 . V_364 = V_119 -> V_115 . V_364 ;
V_230 = V_119 -> V_230 [ 0 ] + 1000000000 ;
if ( ! V_230 )
V_230 = 1 ;
if ( T_1 -> V_138 . V_365 ) {
V_115 . V_116 = V_366 ;
V_115 . V_367 = 1 ;
V_115 . V_127 |= V_368 ;
V_70 = F_144 ( V_43 , L_50 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_294 = true ;
T_1 -> V_235 = V_115 . V_127 ;
T_1 -> V_231 = V_230 ;
V_230 += 1 ;
V_115 . V_127 &= ~ ( T_4 ) V_368 ;
}
if ( T_1 -> V_138 . V_139 )
V_115 . V_127 |= V_369 ;
if ( T_1 -> V_138 . V_145 )
V_115 . V_127 |= V_370 ;
if ( T_1 -> V_138 . V_163 ) {
V_115 . V_116 = V_371 ;
if ( T_1 -> V_138 . V_165 == V_170 )
V_115 . V_367 =
F_53 ( T_1 , T_1 -> V_138 . V_164 ) ;
else
V_115 . V_367 = T_1 -> V_138 . V_164 ;
V_70 = F_144 ( V_43 , L_51 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_286 = true ;
T_1 -> V_239 = V_115 . V_127 ;
T_1 -> V_236 = V_230 ;
V_230 += 1 ;
}
V_115 . V_127 &= ~ ( T_4 ) V_357 ;
V_115 . V_367 = 1 ;
if ( T_1 -> V_138 . V_372 ) {
V_115 . V_116 = V_371 ;
V_70 = F_144 ( V_43 , L_52 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_288 = true ;
T_1 -> V_241 = V_115 . V_127 ;
T_1 -> V_240 = V_230 ;
F_147 ( V_320 , V_230 , L_52 ) ;
V_230 += 1 ;
}
V_115 . type = V_373 ;
V_115 . V_127 |= V_374 ;
if ( T_1 -> V_138 . V_375 ) {
V_115 . V_116 = V_376 ;
V_70 = F_144 ( V_43 , L_53 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_290 = true ;
T_1 -> V_250 = V_115 . V_127 ;
T_1 -> V_244 = V_230 ;
F_147 ( V_320 , V_230 , L_53 ) ;
V_230 += 1 ;
}
if ( T_1 -> V_138 . V_377 ) {
T_1 -> V_279 = true ;
T_1 -> V_259 = V_115 . V_127 ;
V_115 . V_116 = V_378 ;
V_70 = F_144 ( V_43 , L_54 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_252 = V_230 ;
F_147 ( V_320 , V_230 , L_54 ) ;
V_230 += 1 ;
}
if ( T_1 -> V_138 . V_377 && ( V_119 -> V_115 . V_116 & 0x10 ) ) {
V_115 . V_116 = V_379 ;
V_70 = F_144 ( V_43 , L_55 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_261 = V_230 ;
F_147 ( V_320 , V_230 , L_55 ) ;
V_230 += 1 ;
V_115 . V_116 = V_380 ;
V_70 = F_144 ( V_43 , L_56 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_265 = V_230 ;
F_147 ( V_320 , V_230 , L_56 ) ;
V_230 += 1 ;
V_115 . V_116 = V_381 ;
V_70 = F_144 ( V_43 , L_57 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_268 = V_230 ;
F_147 ( V_320 , V_230 , L_57 ) ;
V_230 += 1 ;
V_115 . V_116 = V_382 ;
V_70 = F_144 ( V_43 , L_58 , & V_115 , V_230 ) ;
if ( V_70 )
return V_70 ;
T_1 -> V_270 = V_230 ;
F_147 ( V_320 , V_230 , L_58 ) ;
V_230 += 1 ;
}
T_1 -> V_226 = V_119 -> V_383 ;
return 0 ;
}
static struct V_118 * F_151 ( struct V_351 * V_320 )
{
struct V_118 * V_119 ;
F_152 (evlist, evsel) {
const char * V_305 = F_153 ( V_119 ) ;
if ( ! strcmp ( V_305 , L_59 ) )
return V_119 ;
}
return NULL ;
}
static bool F_154 ( struct V_351 * V_320 )
{
struct V_118 * V_119 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_115 . V_325 )
return true ;
}
return false ;
}
static int F_155 ( const char * V_55 , const char * V_56 , void * V_19 )
{
struct V_1 * T_1 = V_19 ;
if ( ! strcmp ( V_55 , L_60 ) )
T_1 -> V_213 = F_156 ( V_55 , V_56 ) ;
return 0 ;
}
static void F_157 ( T_4 * V_384 , int V_18 , int V_385 )
{
int V_10 ;
if ( ! V_333 )
return;
for ( V_10 = V_18 ; V_10 <= V_385 ; V_10 ++ )
fprintf ( stdout , V_386 [ V_10 ] , V_384 [ V_10 ] ) ;
}
static void F_158 ( const char * V_305 , const char * V_387 )
{
if ( ! V_333 )
return;
fprintf ( stdout , L_61 , V_305 , V_387 ? V_387 : L_62 ) ;
}
static bool F_159 ( struct V_388 * V_389 , int V_7 )
{
return V_389 -> V_220 . V_20 >=
sizeof( struct V_388 ) + ( sizeof( T_4 ) * ( V_7 + 1 ) ) ;
}
int F_160 ( union V_216 * V_217 ,
struct V_329 * V_43 )
{
struct V_388 * V_389 = & V_217 -> V_389 ;
T_2 V_390 = sizeof( T_4 ) * V_391 ;
struct V_1 * T_1 ;
void * V_392 ;
T_4 * V_393 ;
int V_70 ;
if ( V_389 -> V_220 . V_20 < sizeof( struct V_388 ) +
V_390 )
return - V_22 ;
T_1 = F_55 ( sizeof( struct V_1 ) ) ;
if ( ! T_1 )
return - V_45 ;
F_161 ( & T_1 -> V_160 ) ;
V_70 = F_20 ( F_155 , T_1 ) ;
if ( V_70 )
goto V_394;
V_70 = F_162 ( & T_1 -> V_39 ) ;
if ( V_70 )
goto V_394;
F_163 ( V_395 ) ;
T_1 -> V_43 = V_43 ;
T_1 -> V_35 = & V_43 -> V_396 . V_397 ;
T_1 -> V_398 = V_389 -> type ;
T_1 -> V_117 = V_389 -> V_172 [ V_399 ] ;
T_1 -> V_132 . V_134 = V_389 -> V_172 [ V_400 ] ;
T_1 -> V_132 . V_133 = V_389 -> V_172 [ V_401 ] ;
T_1 -> V_132 . V_402 = V_389 -> V_172 [ V_403 ] ;
T_1 -> V_126 = V_389 -> V_172 [ V_404 ] ;
T_1 -> V_125 = V_389 -> V_172 [ V_405 ] ;
T_1 -> V_121 = V_389 -> V_172 [ V_406 ] ;
T_1 -> V_173 = V_389 -> V_172 [ V_407 ] ;
T_1 -> V_46 = V_389 -> V_172 [ V_408 ] ;
T_1 -> V_307 = V_389 -> V_172 [ V_391 ] ;
F_157 ( & V_389 -> V_172 [ 0 ] , V_399 ,
V_391 ) ;
if ( F_159 ( V_389 , V_409 ) ) {
T_1 -> V_410 = V_389 -> V_172 [ V_411 ] ;
T_1 -> V_123 = V_389 -> V_172 [ V_412 ] ;
T_1 -> V_158 = V_389 -> V_172 [ V_413 ] ;
T_1 -> V_159 = V_389 -> V_172 [ V_414 ] ;
T_1 -> V_415 = V_389 -> V_172 [ V_409 ] ;
F_157 ( & V_389 -> V_172 [ 0 ] , V_411 ,
V_409 ) ;
}
if ( F_159 ( V_389 , V_416 ) ) {
T_1 -> V_156 =
V_389 -> V_172 [ V_416 ] ;
F_157 ( & V_389 -> V_172 [ 0 ] ,
V_416 ,
V_416 ) ;
}
V_393 = & V_389 -> V_172 [ V_417 ] + 1 ;
V_392 = ( void * ) V_393 + V_389 -> V_220 . V_20 ;
if ( F_159 ( V_389 , V_417 ) ) {
T_2 V_4 ;
V_4 = V_389 -> V_172 [ V_417 ] ;
F_157 ( & V_389 -> V_172 [ 0 ] ,
V_417 ,
V_417 ) ;
if ( V_4 ) {
const char * V_343 = ( const char * ) V_393 ;
V_4 = F_164 ( V_4 + 1 , 8 ) ;
V_393 += V_4 >> 3 ;
if ( ( void * ) V_393 > V_392 ) {
F_81 ( L_63 , V_350 ) ;
V_70 = - V_22 ;
goto V_418;
}
T_1 -> V_343 = F_165 ( V_343 , V_4 ) ;
if ( ! T_1 -> V_343 ) {
V_70 = - V_45 ;
goto V_418;
}
if ( V_43 -> V_220 . V_383 )
F_166 ( T_1 -> V_343 , V_4 ) ;
if ( T_1 -> V_343 [ V_4 - 1 ] ) {
F_81 ( L_64 , V_350 ) ;
V_70 = - V_22 ;
goto V_418;
}
V_70 = F_167 ( & T_1 -> V_160 ,
V_343 ) ;
if ( V_70 )
goto V_418;
}
F_158 ( L_65 , T_1 -> V_343 ) ;
}
T_1 -> V_124 = F_50 ( T_1 ) ;
T_1 -> V_21 = F_52 ( T_1 ) ;
T_1 -> V_50 = false ;
T_1 -> V_309 = ! T_1 -> V_124 ;
T_1 -> V_93 = F_168 ( 999999999 , 999999999 ) ;
if ( ! T_1 -> V_93 ) {
V_70 = - V_45 ;
goto V_418;
}
F_169 ( & T_1 -> V_93 -> V_419 ) ;
V_70 = F_170 ( T_1 -> V_93 , L_66 , 0 ) ;
if ( V_70 )
goto V_420;
if ( F_171 ( T_1 -> V_93 , T_1 -> V_35 ) ) {
V_70 = - V_45 ;
goto V_420;
}
T_1 -> V_332 . V_421 = F_127 ;
T_1 -> V_332 . V_422 = F_138 ;
T_1 -> V_332 . V_423 = F_130 ;
T_1 -> V_332 . V_424 = F_131 ;
T_1 -> V_332 . free = F_134 ;
V_43 -> V_332 = & T_1 -> V_332 ;
if ( V_333 )
return 0 ;
if ( T_1 -> V_173 == 1 ) {
T_1 -> V_321 = F_151 ( V_43 -> V_320 ) ;
if ( ! T_1 -> V_321 ) {
F_81 ( L_67 , V_350 ) ;
V_70 = - V_22 ;
goto V_420;
}
} else if ( T_1 -> V_173 == 2 &&
! F_154 ( V_43 -> V_320 ) ) {
F_81 ( L_68 , V_350 ) ;
V_70 = - V_22 ;
goto V_420;
}
if ( V_43 -> V_425 && V_43 -> V_425 -> V_426 ) {
T_1 -> V_138 = * V_43 -> V_425 ;
} else {
F_172 ( & T_1 -> V_138 ) ;
if ( V_427 != - 1 ) {
T_1 -> V_138 . V_365 = false ;
T_1 -> V_138 . V_139 = true ;
}
if ( V_43 -> V_425 )
T_1 -> V_138 . V_293 =
V_43 -> V_425 -> V_293 ;
}
if ( T_1 -> V_138 . log )
F_173 () ;
if ( T_1 -> V_132 . V_133 ) {
T_4 V_428 = F_53 ( T_1 , 1000000000 ) ;
if ( ! T_1 -> V_156 )
T_1 -> V_156 =
( V_428 + 50000000 ) / 100000000 ;
F_9 ( L_69 V_322 L_15 , V_428 ) ;
F_9 ( L_70 ,
T_1 -> V_156 ) ;
T_1 -> V_257 = V_428 / T_1 -> V_156 / 1000 ;
}
if ( T_1 -> V_138 . V_429 )
T_1 -> V_229 |= V_181 | V_182 |
V_184 ;
if ( T_1 -> V_138 . V_430 )
T_1 -> V_229 |= V_431 |
V_188 ;
if ( T_1 -> V_138 . V_139 && ! V_432 . V_433 ) {
V_432 . V_433 = true ;
if ( F_174 ( & V_434 ) < 0 ) {
V_432 . V_433 = false ;
T_1 -> V_138 . V_139 = false ;
}
}
V_70 = F_150 ( T_1 , V_43 ) ;
if ( V_70 )
goto V_420;
V_70 = F_175 ( & T_1 -> V_39 , V_43 ) ;
if ( V_70 )
goto V_420;
if ( T_1 -> V_39 . V_435 )
T_1 -> V_344 = true ;
if ( T_1 -> V_124 )
F_176 ( L_71 ) ;
return 0 ;
V_420:
F_10 ( T_1 -> V_93 ) ;
V_418:
F_132 () ;
F_133 ( & T_1 -> V_39 ) ;
V_43 -> V_332 = NULL ;
V_394:
F_137 ( & T_1 -> V_160 ) ;
F_57 ( & T_1 -> V_343 ) ;
free ( T_1 ) ;
return V_70 ;
}
