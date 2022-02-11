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
static unsigned int F_48 ( struct V_1 * T_1 )
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
static bool F_49 ( struct V_1 * T_1 )
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
static bool F_50 ( struct V_1 * T_1 )
{
struct V_118 * V_119 ;
F_46 (pt->session->evlist, evsel) {
if ( F_44 ( T_1 , & V_119 -> V_115 , NULL ) &&
! V_119 -> V_115 . V_120 )
return true ;
}
return false ;
}
static bool F_51 ( struct V_1 * T_1 )
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
static T_4 F_52 ( const struct V_1 * T_1 , T_4 V_129 )
{
T_4 V_130 , V_131 ;
V_130 = V_129 / T_1 -> V_132 . V_133 ;
V_131 = V_129 % T_1 -> V_132 . V_133 ;
return ( V_130 << T_1 -> V_132 . V_134 ) + ( V_131 << T_1 -> V_132 . V_134 ) /
T_1 -> V_132 . V_133 ;
}
static struct V_25 * F_53 ( struct V_1 * T_1 ,
unsigned int V_33 )
{
struct V_135 V_136 = { . V_137 = 0 , } ;
struct V_25 * V_26 ;
V_26 = F_54 ( sizeof( struct V_25 ) ) ;
if ( ! V_26 )
return NULL ;
if ( T_1 -> V_138 . V_139 ) {
T_2 V_140 = sizeof( struct V_141 ) ;
V_140 += T_1 -> V_138 . V_142 * sizeof( T_4 ) ;
V_26 -> V_143 = F_54 ( V_140 ) ;
if ( ! V_26 -> V_143 )
goto V_144;
}
if ( T_1 -> V_138 . V_145 ) {
T_2 V_140 = sizeof( struct V_146 ) ;
V_140 += T_1 -> V_138 . V_147 *
sizeof( struct V_148 ) ;
V_26 -> V_145 = F_54 ( V_140 ) ;
if ( ! V_26 -> V_145 )
goto V_144;
V_26 -> V_149 = F_54 ( V_140 ) ;
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
V_136 . V_155 = T_1 -> V_155 ;
V_136 . V_156 = F_48 ( T_1 ) ;
V_136 . V_157 = T_1 -> V_157 ;
V_136 . V_158 = T_1 -> V_158 ;
if ( T_1 -> V_159 . V_160 > 0 )
V_136 . V_161 = F_43 ;
if ( T_1 -> V_138 . V_162 ) {
if ( T_1 -> V_138 . V_163 ) {
switch ( T_1 -> V_138 . V_164 ) {
case V_165 :
V_136 . V_164 =
V_166 ;
V_136 . V_163 = T_1 -> V_138 . V_163 ;
break;
case V_167 :
V_136 . V_164 = V_168 ;
V_136 . V_163 = T_1 -> V_138 . V_163 ;
break;
case V_169 :
V_136 . V_164 = V_168 ;
V_136 . V_163 = F_52 ( T_1 ,
T_1 -> V_138 . V_163 ) ;
break;
default:
break;
}
}
if ( ! V_136 . V_163 ) {
V_136 . V_164 = V_166 ;
V_136 . V_163 = 1 ;
}
}
V_26 -> V_170 = F_55 ( & V_136 ) ;
if ( ! V_26 -> V_170 )
goto V_144;
return V_26 ;
V_144:
F_56 ( & V_26 -> V_150 ) ;
F_56 ( & V_26 -> V_145 ) ;
F_56 ( & V_26 -> V_149 ) ;
F_56 ( & V_26 -> V_143 ) ;
free ( V_26 ) ;
return NULL ;
}
static void F_57 ( void * V_171 )
{
struct V_25 * V_26 = V_171 ;
if ( ! V_26 )
return;
F_10 ( V_26 -> V_34 ) ;
F_58 ( V_26 -> V_170 ) ;
F_56 ( & V_26 -> V_150 ) ;
F_56 ( & V_26 -> V_145 ) ;
F_56 ( & V_26 -> V_149 ) ;
F_56 ( & V_26 -> V_143 ) ;
free ( V_26 ) ;
}
static void F_59 ( struct V_1 * T_1 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_171 ;
if ( V_28 -> V_32 == - 1 || T_1 -> V_172 ) {
V_26 -> V_32 = F_60 ( T_1 -> V_35 , V_26 -> V_30 ) ;
F_10 ( V_26 -> V_34 ) ;
}
if ( ! V_26 -> V_34 && V_26 -> V_32 != - 1 )
V_26 -> V_34 = F_12 ( T_1 -> V_35 , - 1 , V_26 -> V_32 ) ;
if ( V_26 -> V_34 ) {
V_26 -> V_31 = V_26 -> V_34 -> V_173 ;
if ( V_28 -> V_30 == - 1 )
V_26 -> V_30 = V_26 -> V_34 -> V_30 ;
}
}
static void F_61 ( struct V_25 * V_26 )
{
if ( V_26 -> V_174 -> V_175 & V_176 ) {
V_26 -> V_175 = V_177 | V_178 ;
} else if ( V_26 -> V_174 -> V_175 & V_179 ) {
if ( V_26 -> V_174 -> V_80 )
V_26 -> V_175 = V_177 | V_180 |
V_181 |
V_182 ;
else
V_26 -> V_175 = V_177 |
V_183 ;
V_26 -> V_184 = 0 ;
} else {
if ( V_26 -> V_174 -> V_185 )
V_26 -> V_175 = F_62 ( V_26 -> V_174 -> V_186 ) ;
else
V_26 -> V_175 = V_177 |
V_187 ;
if ( V_26 -> V_174 -> V_175 & V_188 )
V_26 -> V_175 |= V_189 ;
V_26 -> V_184 = V_26 -> V_174 -> V_184 ;
memcpy ( V_26 -> V_75 , V_26 -> V_174 -> V_75 , V_76 ) ;
}
}
static int F_63 ( struct V_1 * T_1 ,
struct V_27 * V_28 ,
unsigned int V_33 )
{
struct V_25 * V_26 = V_28 -> V_171 ;
if ( F_64 ( & V_28 -> V_190 ) )
return 0 ;
if ( ! V_26 ) {
V_26 = F_53 ( T_1 , V_33 ) ;
if ( ! V_26 )
return - V_45 ;
V_28 -> V_171 = V_26 ;
if ( V_28 -> V_30 != - 1 )
V_26 -> V_30 = V_28 -> V_30 ;
V_26 -> V_32 = V_28 -> V_32 ;
if ( T_1 -> V_50 ) {
if ( T_1 -> V_124 )
V_26 -> V_54 = true ;
if ( T_1 -> V_124 || ! T_1 -> V_172 )
V_26 -> V_53 = true ;
}
}
if ( ! V_26 -> V_191 &&
( ! T_1 -> V_192 ||
V_26 -> V_193 != V_194 ) ) {
const struct V_195 * V_174 ;
int V_8 ;
if ( T_1 -> V_124 )
return 0 ;
F_9 ( L_20 , V_33 ) ;
F_9 ( L_21 ,
V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_174 = F_65 ( V_26 -> V_170 ) ;
if ( V_174 -> V_70 ) {
if ( V_174 -> V_70 == V_196 ) {
F_9 ( L_22 ,
V_33 ) ;
return 0 ;
}
continue;
}
if ( V_174 -> V_197 )
break;
}
V_26 -> V_197 = V_174 -> V_197 ;
F_9 ( L_23 V_112 L_15 ,
V_33 , V_26 -> V_197 ) ;
V_26 -> V_174 = V_174 ;
V_26 -> V_198 = true ;
F_61 ( V_26 ) ;
V_8 = F_66 ( & T_1 -> V_199 , V_33 , V_26 -> V_197 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_191 = true ;
}
return 0 ;
}
static int F_67 ( struct V_1 * T_1 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < T_1 -> V_39 . V_200 ; V_10 ++ ) {
V_8 = F_63 ( T_1 , & T_1 -> V_39 . V_40 [ V_10 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static inline void F_68 ( struct V_25 * V_26 )
{
struct V_146 * V_201 = V_26 -> V_149 ;
struct V_146 * V_202 = V_26 -> V_145 ;
T_2 V_203 = 0 ;
V_202 -> V_203 = V_201 -> V_203 ;
if ( ! V_201 -> V_203 )
return;
V_203 = V_26 -> T_1 -> V_138 . V_147 - V_26 -> V_204 ;
memcpy ( & V_202 -> V_205 [ 0 ] ,
& V_201 -> V_205 [ V_26 -> V_204 ] ,
sizeof( struct V_148 ) * V_203 ) ;
if ( V_201 -> V_203 >= V_26 -> T_1 -> V_138 . V_147 ) {
memcpy ( & V_202 -> V_205 [ V_203 ] ,
& V_201 -> V_205 [ 0 ] ,
sizeof( struct V_148 ) * V_26 -> V_204 ) ;
}
}
static inline void F_69 ( struct V_25 * V_26 )
{
V_26 -> V_204 = 0 ;
V_26 -> V_149 -> V_203 = 0 ;
}
static void F_70 ( struct V_25 * V_26 )
{
const struct V_195 * V_174 = V_26 -> V_174 ;
struct V_146 * V_206 = V_26 -> V_149 ;
struct V_148 * V_207 ;
if ( ! V_26 -> V_204 )
V_26 -> V_204 = V_26 -> T_1 -> V_138 . V_147 ;
V_26 -> V_204 -= 1 ;
V_207 = & V_206 -> V_205 [ V_26 -> V_204 ] ;
V_207 -> V_208 = V_174 -> V_185 ;
V_207 -> V_209 = V_174 -> V_80 ;
V_207 -> V_175 . abort = ! ! ( V_174 -> V_175 & V_176 ) ;
V_207 -> V_175 . V_210 = ! ! ( V_174 -> V_175 & V_188 ) ;
V_207 -> V_175 . V_211 = V_26 -> T_1 -> V_212 ;
if ( V_206 -> V_203 < V_26 -> T_1 -> V_138 . V_147 )
V_206 -> V_203 += 1 ;
}
static int F_71 ( union V_213 * V_214 ,
struct V_215 * V_216 , T_4 type ,
bool V_217 )
{
V_214 -> V_218 . V_20 = F_72 ( V_216 , type , 0 ) ;
return F_73 ( V_214 , type , 0 , V_216 , V_217 ) ;
}
static int F_74 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_213 * V_214 = V_26 -> V_150 ;
struct V_215 V_216 = { . V_79 = 0 , } ;
struct V_219 {
T_4 V_203 ;
struct V_148 V_205 ;
} V_220 ;
if ( T_1 -> V_221 && ! ( T_1 -> V_221 & V_26 -> V_175 ) )
return 0 ;
if ( T_1 -> V_138 . V_222 &&
T_1 -> V_223 ++ < T_1 -> V_138 . V_222 )
return 0 ;
V_214 -> V_216 . V_218 . type = V_224 ;
V_214 -> V_216 . V_218 . V_225 = V_92 ;
V_214 -> V_216 . V_218 . V_20 = sizeof( struct V_226 ) ;
if ( ! T_1 -> V_124 )
V_216 . time = F_75 ( V_26 -> V_197 , & T_1 -> V_132 ) ;
V_216 . V_85 = V_92 ;
V_216 . V_79 = V_26 -> V_174 -> V_185 ;
V_216 . V_31 = V_26 -> V_31 ;
V_216 . V_32 = V_26 -> V_32 ;
V_216 . V_111 = V_26 -> V_174 -> V_80 ;
V_216 . V_227 = V_26 -> T_1 -> V_228 ;
V_216 . V_229 = V_26 -> T_1 -> V_228 ;
V_216 . V_163 = 1 ;
V_216 . V_30 = V_26 -> V_30 ;
V_216 . V_175 = V_26 -> V_175 ;
V_216 . V_184 = V_26 -> V_184 ;
memcpy ( V_216 . V_75 , V_26 -> V_75 , V_76 ) ;
if ( T_1 -> V_138 . V_145 && V_230 == V_231 ) {
V_220 = (struct V_219 ) {
. V_203 = 1 ,
. V_205 = {
. V_208 = V_216 . V_79 ,
. V_209 = V_216 . V_111 ,
} ,
} ;
V_216 . V_146 = (struct V_146 * ) & V_220 ;
}
if ( T_1 -> V_138 . V_232 ) {
V_8 = F_71 ( V_214 , & V_216 ,
T_1 -> V_233 ,
T_1 -> V_234 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_76 ( T_1 -> V_43 , V_214 , & V_216 ) ;
if ( V_8 )
F_77 ( L_24 ,
V_8 ) ;
return V_8 ;
}
static int F_78 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_213 * V_214 = V_26 -> V_150 ;
struct V_215 V_216 = { . V_79 = 0 , } ;
if ( T_1 -> V_138 . V_222 &&
T_1 -> V_223 ++ < T_1 -> V_138 . V_222 )
return 0 ;
V_214 -> V_216 . V_218 . type = V_224 ;
V_214 -> V_216 . V_218 . V_225 = V_92 ;
V_214 -> V_216 . V_218 . V_20 = sizeof( struct V_226 ) ;
if ( ! T_1 -> V_124 )
V_216 . time = F_75 ( V_26 -> V_197 , & T_1 -> V_132 ) ;
V_216 . V_85 = V_92 ;
V_216 . V_79 = V_26 -> V_174 -> V_185 ;
V_216 . V_31 = V_26 -> V_31 ;
V_216 . V_32 = V_26 -> V_32 ;
V_216 . V_111 = V_26 -> V_174 -> V_80 ;
V_216 . V_227 = V_26 -> T_1 -> V_235 ;
V_216 . V_229 = V_26 -> T_1 -> V_235 ;
V_216 . V_163 = V_26 -> V_174 -> V_236 - V_26 -> V_237 ;
V_216 . V_30 = V_26 -> V_30 ;
V_216 . V_175 = V_26 -> V_175 ;
V_216 . V_184 = V_26 -> V_184 ;
memcpy ( V_216 . V_75 , V_26 -> V_75 , V_76 ) ;
V_26 -> V_237 = V_26 -> V_174 -> V_236 ;
if ( T_1 -> V_138 . V_139 ) {
F_79 ( V_26 -> V_34 , V_26 -> V_143 ,
T_1 -> V_138 . V_142 , V_216 . V_79 ) ;
V_216 . V_139 = V_26 -> V_143 ;
}
if ( T_1 -> V_138 . V_145 ) {
F_68 ( V_26 ) ;
V_216 . V_146 = V_26 -> V_145 ;
}
if ( T_1 -> V_138 . V_232 ) {
V_8 = F_71 ( V_214 , & V_216 ,
T_1 -> V_238 ,
T_1 -> V_234 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_76 ( T_1 -> V_43 , V_214 , & V_216 ) ;
if ( V_8 )
F_77 ( L_25 ,
V_8 ) ;
if ( T_1 -> V_138 . V_145 )
F_69 ( V_26 ) ;
return V_8 ;
}
static int F_80 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_213 * V_214 = V_26 -> V_150 ;
struct V_215 V_216 = { . V_79 = 0 , } ;
if ( T_1 -> V_138 . V_222 &&
T_1 -> V_223 ++ < T_1 -> V_138 . V_222 )
return 0 ;
V_214 -> V_216 . V_218 . type = V_224 ;
V_214 -> V_216 . V_218 . V_225 = V_92 ;
V_214 -> V_216 . V_218 . V_20 = sizeof( struct V_226 ) ;
if ( ! T_1 -> V_124 )
V_216 . time = F_75 ( V_26 -> V_197 , & T_1 -> V_132 ) ;
V_216 . V_85 = V_92 ;
V_216 . V_79 = V_26 -> V_174 -> V_185 ;
V_216 . V_31 = V_26 -> V_31 ;
V_216 . V_32 = V_26 -> V_32 ;
V_216 . V_111 = V_26 -> V_174 -> V_80 ;
V_216 . V_227 = V_26 -> T_1 -> V_239 ;
V_216 . V_229 = V_26 -> T_1 -> V_239 ;
V_216 . V_163 = 1 ;
V_216 . V_30 = V_26 -> V_30 ;
V_216 . V_175 = V_26 -> V_175 ;
V_216 . V_184 = V_26 -> V_184 ;
memcpy ( V_216 . V_75 , V_26 -> V_75 , V_76 ) ;
if ( T_1 -> V_138 . V_139 ) {
F_79 ( V_26 -> V_34 , V_26 -> V_143 ,
T_1 -> V_138 . V_142 , V_216 . V_79 ) ;
V_216 . V_139 = V_26 -> V_143 ;
}
if ( T_1 -> V_138 . V_145 ) {
F_68 ( V_26 ) ;
V_216 . V_146 = V_26 -> V_145 ;
}
if ( T_1 -> V_138 . V_232 ) {
V_8 = F_71 ( V_214 , & V_216 ,
T_1 -> V_240 ,
T_1 -> V_234 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_76 ( T_1 -> V_43 , V_214 , & V_216 ) ;
if ( V_8 )
F_77 ( L_26 ,
V_8 ) ;
if ( T_1 -> V_138 . V_145 )
F_69 ( V_26 ) ;
return V_8 ;
}
static int F_81 ( struct V_1 * T_1 , int V_241 , int V_30 ,
T_8 V_31 , T_8 V_32 , T_4 V_79 )
{
union V_213 V_214 ;
char V_242 [ V_243 ] ;
int V_70 ;
F_82 ( V_241 , V_242 , V_243 ) ;
F_83 ( & V_214 . V_244 , V_245 ,
V_241 , V_30 , V_31 , V_32 , V_79 , V_242 ) ;
V_70 = F_76 ( T_1 -> V_43 , & V_214 , NULL ) ;
if ( V_70 )
F_77 ( L_27 ,
V_70 ) ;
return V_70 ;
}
static int F_84 ( struct V_1 * T_1 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_8 V_32 = V_26 -> V_152 ;
int V_70 ;
if ( V_32 == - 1 )
return 0 ;
F_9 ( L_28 , V_26 -> V_30 , V_32 ) ;
V_70 = F_85 ( T_1 -> V_35 , V_26 -> V_30 , - 1 , V_32 ) ;
V_28 = & T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
F_59 ( T_1 , V_28 ) ;
V_26 -> V_152 = - 1 ;
return V_70 ;
}
static inline bool F_86 ( struct V_25 * V_26 , T_4 V_79 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
return V_79 == T_1 -> V_246 &&
( V_26 -> V_175 & V_177 ) &&
! ( V_26 -> V_175 & ( V_247 | V_181 |
V_182 | V_178 ) ) ;
}
static int F_87 ( struct V_25 * V_26 )
{
const struct V_195 * V_174 = V_26 -> V_174 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! V_26 -> V_198 )
return 0 ;
V_26 -> V_198 = false ;
if ( T_1 -> V_248 &&
( V_174 -> type & V_249 ) &&
( ! T_1 -> V_138 . V_222 ||
T_1 -> V_223 ++ >= T_1 -> V_138 . V_222 ) ) {
V_70 = F_78 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_250 &&
( V_174 -> type & V_251 ) &&
( ! T_1 -> V_138 . V_222 ||
T_1 -> V_223 ++ >= T_1 -> V_138 . V_222 ) ) {
V_70 = F_80 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( ! ( V_174 -> type & V_252 ) )
return 0 ;
if ( T_1 -> V_138 . V_139 || T_1 -> V_138 . V_253 )
F_88 ( V_26 -> V_34 , V_26 -> V_175 , V_174 -> V_185 ,
V_174 -> V_80 , V_26 -> V_184 ,
V_174 -> V_51 ) ;
else
F_89 ( V_26 -> V_34 , V_174 -> V_51 ) ;
if ( T_1 -> V_254 ) {
V_70 = F_74 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_138 . V_145 )
F_70 ( V_26 ) ;
if ( ! T_1 -> V_192 )
return 0 ;
if ( F_86 ( V_26 , V_174 -> V_80 ) ) {
switch ( V_26 -> V_193 ) {
case V_255 :
case V_256 :
V_70 = F_84 ( T_1 , V_26 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_193 = V_257 ;
break;
default:
V_26 -> V_193 = V_194 ;
return 1 ;
}
} else if ( ! V_174 -> V_80 ) {
V_26 -> V_193 = V_258 ;
} else if ( V_26 -> V_193 == V_258 ) {
V_26 -> V_193 = V_255 ;
} else if ( V_26 -> V_193 == V_255 &&
V_174 -> V_80 == T_1 -> V_259 &&
( V_26 -> V_175 & V_180 ) ) {
V_26 -> V_193 = V_257 ;
}
return 0 ;
}
static T_4 F_90 ( struct V_1 * T_1 , T_4 * V_259 )
{
struct V_35 * V_35 = T_1 -> V_35 ;
struct V_95 * V_95 ;
struct V_260 * V_261 , * V_18 ;
T_4 V_79 , V_246 = 0 ;
const char * V_262 ;
if ( V_259 )
* V_259 = 0 ;
V_95 = F_91 ( V_35 ) ;
if ( ! V_95 )
return 0 ;
if ( F_36 ( V_95 ) )
return 0 ;
V_18 = F_92 ( V_95 -> V_60 , V_94 ) ;
for ( V_261 = V_18 ; V_261 ; V_261 = F_93 ( V_261 ) ) {
if ( V_261 -> V_263 == V_264 &&
! strcmp ( V_261 -> V_265 , L_29 ) ) {
V_79 = V_95 -> V_266 ( V_95 , V_261 -> V_18 ) ;
if ( V_79 >= V_95 -> V_18 && V_79 < V_95 -> V_104 ) {
V_246 = V_79 ;
break;
}
}
}
if ( ! V_246 || ! V_259 )
return 0 ;
if ( T_1 -> V_172 == 1 )
V_262 = L_30 ;
else
V_262 = L_31 ;
for ( V_261 = V_18 ; V_261 ; V_261 = F_93 ( V_261 ) ) {
if ( ! strcmp ( V_261 -> V_265 , V_262 ) ) {
V_79 = V_95 -> V_266 ( V_95 , V_261 -> V_18 ) ;
if ( V_79 >= V_95 -> V_18 && V_79 < V_95 -> V_104 ) {
* V_259 = V_79 ;
break;
}
}
}
return V_246 ;
}
static int F_94 ( struct V_25 * V_26 , T_4 * V_197 )
{
const struct V_195 * V_174 = V_26 -> V_174 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! T_1 -> V_90 ) {
T_1 -> V_90 = F_95 ( T_1 -> V_35 ) ;
if ( T_1 -> V_267 &&
( T_1 -> V_172 == 1 || T_1 -> V_172 == 3 ) &&
! T_1 -> V_124 && F_50 ( T_1 ) &&
! T_1 -> V_50 ) {
T_1 -> V_246 = F_90 ( T_1 , & T_1 -> V_259 ) ;
if ( T_1 -> V_246 ) {
F_9 ( L_32 V_112 L_33 V_112 L_15 ,
T_1 -> V_246 , T_1 -> V_259 ) ;
T_1 -> V_192 = true ;
}
}
}
F_9 ( L_21 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_70 = F_87 ( V_26 ) ;
if ( V_70 )
return V_70 ;
V_174 = F_65 ( V_26 -> V_170 ) ;
if ( V_174 -> V_70 ) {
if ( V_174 -> V_70 == V_196 )
return 1 ;
if ( T_1 -> V_192 &&
V_174 -> V_185 >= T_1 -> V_90 ) {
T_1 -> V_192 = false ;
F_84 ( T_1 , V_26 ) ;
}
if ( T_1 -> V_138 . V_268 ) {
V_70 = F_81 ( T_1 , V_174 -> V_70 ,
V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_32 ,
V_174 -> V_185 ) ;
if ( V_70 )
return V_70 ;
}
continue;
}
V_26 -> V_174 = V_174 ;
V_26 -> V_198 = true ;
F_61 ( V_26 ) ;
if ( T_1 -> V_269 &&
( V_174 -> V_185 >= T_1 -> V_90 || ! V_174 -> V_185 ) &&
V_174 -> V_80 && V_174 -> V_80 < T_1 -> V_90 ) {
F_9 ( L_34 V_112 L_35 V_112 L_15 ,
V_174 -> V_197 , V_174 -> V_270 ) ;
V_26 -> V_197 = V_174 -> V_270 ;
} else if ( T_1 -> V_192 &&
V_26 -> V_193 == V_255 &&
F_86 ( V_26 , V_174 -> V_80 ) &&
V_26 -> V_152 == - 1 ) {
F_9 ( L_34 V_112 L_35 V_112 L_15 ,
V_174 -> V_197 , V_174 -> V_270 ) ;
V_26 -> V_197 = V_174 -> V_270 ;
} else if ( V_174 -> V_197 > V_26 -> V_197 ) {
V_26 -> V_197 = V_174 -> V_197 ;
}
if ( ! T_1 -> V_124 && V_26 -> V_197 >= * V_197 ) {
* V_197 = V_26 -> V_197 ;
return 0 ;
}
}
return 0 ;
}
static inline int F_96 ( struct V_1 * T_1 )
{
if ( T_1 -> V_39 . V_271 ) {
T_1 -> V_39 . V_271 = false ;
return F_67 ( T_1 ) ;
}
return 0 ;
}
static int F_97 ( struct V_1 * T_1 , T_4 V_197 )
{
unsigned int V_33 ;
T_4 V_272 ;
int V_8 ;
while ( 1 ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
if ( ! T_1 -> V_199 . V_273 )
return 0 ;
if ( T_1 -> V_199 . V_274 [ 0 ] . V_275 >= V_197 )
return 0 ;
V_33 = T_1 -> V_199 . V_274 [ 0 ] . V_33 ;
V_28 = & T_1 -> V_39 . V_40 [ V_33 ] ;
V_26 = V_28 -> V_171 ;
F_9 ( L_36 V_112 L_37 V_112 L_15 ,
V_33 , T_1 -> V_199 . V_274 [ 0 ] . V_275 ,
V_197 ) ;
F_98 ( & T_1 -> V_199 ) ;
if ( T_1 -> V_199 . V_273 ) {
V_272 = T_1 -> V_199 . V_274 [ 0 ] . V_275 + 1 ;
if ( V_272 > V_197 )
V_272 = V_197 ;
} else {
V_272 = V_197 ;
}
F_59 ( T_1 , V_28 ) ;
V_8 = F_94 ( V_26 , & V_272 ) ;
if ( V_8 < 0 ) {
F_66 ( & T_1 -> V_199 , V_33 , V_272 ) ;
return V_8 ;
}
if ( ! V_8 ) {
V_8 = F_66 ( & T_1 -> V_199 , V_33 , V_272 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_26 -> V_191 = false ;
}
}
return 0 ;
}
static int F_99 ( struct V_1 * T_1 , T_8 V_32 ,
T_4 V_276 )
{
struct V_277 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
T_4 V_272 = 0 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_200 ; V_10 ++ ) {
struct V_27 * V_28 = & T_1 -> V_39 . V_40 [ V_10 ] ;
struct V_25 * V_26 = V_28 -> V_171 ;
if ( V_26 && ( V_32 == - 1 || V_26 -> V_32 == V_32 ) ) {
V_26 -> time = V_276 ;
F_59 ( T_1 , V_28 ) ;
F_94 ( V_26 , & V_272 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_1 * T_1 , struct V_215 * V_216 )
{
return F_81 ( T_1 , V_278 , V_216 -> V_30 ,
V_216 -> V_31 , V_216 -> V_32 , 0 ) ;
}
static struct V_25 * F_101 ( struct V_1 * T_1 , int V_30 )
{
unsigned V_10 , V_279 ;
if ( V_30 < 0 || ! T_1 -> V_39 . V_200 )
return NULL ;
if ( ( unsigned ) V_30 >= T_1 -> V_39 . V_200 )
V_10 = T_1 -> V_39 . V_200 - 1 ;
else
V_10 = V_30 ;
if ( T_1 -> V_39 . V_40 [ V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_171 ;
for ( V_279 = 0 ; V_10 > 0 ; V_279 ++ ) {
if ( T_1 -> V_39 . V_40 [ -- V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_171 ;
}
for (; V_279 < T_1 -> V_39 . V_200 ; V_279 ++ ) {
if ( T_1 -> V_39 . V_40 [ V_279 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_279 ] . V_171 ;
}
return NULL ;
}
static int F_102 ( struct V_1 * T_1 , int V_30 , T_8 V_32 ,
T_4 V_197 )
{
struct V_25 * V_26 ;
int V_70 ;
if ( ! T_1 -> V_192 )
return 1 ;
V_26 = F_101 ( T_1 , V_30 ) ;
if ( ! V_26 )
return 1 ;
switch ( V_26 -> V_193 ) {
case V_258 :
V_26 -> V_152 = - 1 ;
break;
case V_255 :
case V_257 :
V_26 -> V_152 = V_32 ;
V_26 -> V_193 = V_256 ;
return 0 ;
case V_194 :
if ( ! V_26 -> V_191 ) {
V_26 -> V_197 = F_103 ( V_197 ,
& T_1 -> V_132 ) ;
V_70 = F_66 ( & T_1 -> V_199 , V_26 -> V_33 ,
V_26 -> V_197 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_191 = true ;
}
V_26 -> V_193 = V_257 ;
break;
case V_256 :
V_26 -> V_152 = V_32 ;
F_9 ( L_38 , V_30 ) ;
break;
default:
break;
}
return 1 ;
}
static int F_104 ( struct V_1 * T_1 ,
struct V_215 * V_216 )
{
struct V_118 * V_119 ;
T_8 V_32 ;
int V_30 , V_8 ;
V_119 = F_105 ( T_1 -> V_43 -> V_280 , V_216 -> V_227 ) ;
if ( V_119 != T_1 -> V_281 )
return 0 ;
V_32 = F_106 ( V_119 , V_216 , L_39 ) ;
V_30 = V_216 -> V_30 ;
F_9 ( L_40 V_282 L_41 V_112 L_15 ,
V_30 , V_32 , V_216 -> time , F_103 ( V_216 -> time ,
& T_1 -> V_132 ) ) ;
V_8 = F_102 ( T_1 , V_30 , V_32 , V_216 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_85 ( T_1 -> V_35 , V_30 , - 1 , V_32 ) ;
}
static int F_107 ( struct V_1 * T_1 , union V_213 * V_214 ,
struct V_215 * V_216 )
{
bool V_103 = V_214 -> V_218 . V_225 & V_283 ;
T_8 V_31 , V_32 ;
int V_30 , V_8 ;
V_30 = V_216 -> V_30 ;
if ( T_1 -> V_172 == 3 ) {
if ( ! V_103 )
return 0 ;
if ( V_214 -> V_218 . type != V_284 ) {
F_77 ( L_42 ) ;
return - V_22 ;
}
V_31 = V_214 -> V_285 . V_286 ;
V_32 = V_214 -> V_285 . V_287 ;
} else {
if ( V_103 )
return 0 ;
V_31 = V_216 -> V_31 ;
V_32 = V_216 -> V_32 ;
}
if ( V_32 == - 1 ) {
F_77 ( L_43 ) ;
return - V_22 ;
}
F_9 ( L_44 V_282 L_41 V_112 L_15 ,
V_30 , V_31 , V_32 , V_216 -> time , F_103 ( V_216 -> time ,
& T_1 -> V_132 ) ) ;
V_8 = F_102 ( T_1 , V_30 , V_32 , V_216 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_85 ( T_1 -> V_35 , V_30 , V_31 , V_32 ) ;
}
static int F_108 ( struct V_1 * T_1 ,
union V_213 * V_214 ,
struct V_215 * V_216 )
{
if ( ! T_1 -> V_267 )
return 0 ;
F_9 ( L_45 V_282 L_41 V_112 L_15 ,
V_216 -> V_30 , V_214 -> V_288 . V_31 ,
V_214 -> V_288 . V_32 , V_216 -> time ,
F_103 ( V_216 -> time , & T_1 -> V_132 ) ) ;
return F_85 ( T_1 -> V_35 , V_216 -> V_30 ,
V_214 -> V_288 . V_31 ,
V_214 -> V_288 . V_32 ) ;
}
static int F_109 ( struct V_289 * V_43 ,
union V_213 * V_214 ,
struct V_215 * V_216 ,
struct V_290 * V_291 )
{
struct V_1 * T_1 = F_110 ( V_43 -> V_292 , struct V_1 ,
V_292 ) ;
T_4 V_197 ;
int V_70 = 0 ;
if ( V_293 )
return 0 ;
if ( ! V_291 -> V_294 ) {
F_77 ( L_46 ) ;
return - V_22 ;
}
if ( V_216 -> time && V_216 -> time != ( T_4 ) - 1 )
V_197 = F_103 ( V_216 -> time , & T_1 -> V_132 ) ;
else
V_197 = 0 ;
if ( V_197 || T_1 -> V_124 ) {
V_70 = F_96 ( T_1 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_124 ) {
if ( V_214 -> V_218 . type == V_295 ) {
V_70 = F_99 ( T_1 ,
V_214 -> V_296 . V_32 ,
V_216 -> time ) ;
}
} else if ( V_197 ) {
V_70 = F_97 ( T_1 , V_197 ) ;
}
if ( V_70 )
return V_70 ;
if ( V_214 -> V_218 . type == V_297 &&
( V_214 -> V_298 . V_175 & V_299 ) &&
T_1 -> V_138 . V_268 ) {
V_70 = F_100 ( T_1 , V_216 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_281 && V_214 -> V_218 . type == V_224 )
V_70 = F_104 ( T_1 , V_216 ) ;
else if ( V_214 -> V_218 . type == V_300 )
V_70 = F_108 ( T_1 , V_214 , V_216 ) ;
else if ( V_214 -> V_218 . type == V_301 ||
V_214 -> V_218 . type == V_284 )
V_70 = F_107 ( T_1 , V_214 , V_216 ) ;
F_9 ( L_47 V_282 L_41 V_112 L_15 ,
F_111 ( V_214 -> V_218 . type ) , V_214 -> V_218 . type ,
V_216 -> V_30 , V_216 -> time , V_197 ) ;
return V_70 ;
}
static int F_112 ( struct V_289 * V_43 , struct V_290 * V_291 )
{
struct V_1 * T_1 = F_110 ( V_43 -> V_292 , struct V_1 ,
V_292 ) ;
int V_8 ;
if ( V_293 )
return 0 ;
if ( ! V_291 -> V_294 )
return - V_22 ;
V_8 = F_96 ( T_1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( T_1 -> V_124 )
return F_99 ( T_1 , - 1 ,
V_302 - 1 ) ;
return F_97 ( T_1 , V_302 ) ;
}
static void F_113 ( struct V_289 * V_43 )
{
struct V_1 * T_1 = F_110 ( V_43 -> V_292 , struct V_1 ,
V_292 ) ;
struct V_277 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_200 ; V_10 ++ ) {
F_57 ( V_39 -> V_40 [ V_10 ] . V_171 ) ;
V_39 -> V_40 [ V_10 ] . V_171 = NULL ;
}
F_114 () ;
F_115 ( V_39 ) ;
}
static void F_116 ( struct V_289 * V_43 )
{
struct V_1 * T_1 = F_110 ( V_43 -> V_292 , struct V_1 ,
V_292 ) ;
F_117 ( & T_1 -> V_199 ) ;
F_113 ( V_43 ) ;
V_43 -> V_292 = NULL ;
F_118 ( T_1 -> V_93 ) ;
F_119 ( & T_1 -> V_159 ) ;
F_56 ( & T_1 -> V_303 ) ;
free ( T_1 ) ;
}
static int F_120 ( struct V_289 * V_43 ,
union V_213 * V_214 ,
struct V_290 * V_291 V_2 )
{
struct V_1 * T_1 = F_110 ( V_43 -> V_292 , struct V_1 ,
V_292 ) ;
if ( T_1 -> V_50 )
return 0 ;
if ( ! T_1 -> V_304 ) {
struct V_15 * V_29 ;
T_3 V_305 ;
int V_42 = F_16 ( V_43 -> V_44 ) ;
int V_70 ;
if ( F_121 ( V_43 -> V_44 ) ) {
V_305 = 0 ;
} else {
V_305 = F_122 ( V_42 , 0 , V_306 ) ;
if ( V_305 == - 1 )
return - V_307 ;
}
V_70 = F_123 ( & T_1 -> V_39 , V_43 , V_214 ,
V_305 , & V_29 ) ;
if ( V_70 )
return V_70 ;
if ( V_293 ) {
if ( F_17 ( V_29 , V_42 ) ) {
F_5 ( T_1 , V_29 -> V_19 ,
V_29 -> V_20 ) ;
F_124 ( V_29 ) ;
}
}
}
return 0 ;
}
static int F_125 ( struct V_290 * V_291 ,
union V_213 * V_214 ,
struct V_215 * V_216 V_2 ,
struct V_35 * V_35 V_2 )
{
struct V_308 * V_308 =
F_110 ( V_291 , struct V_308 , V_309 ) ;
return F_76 ( V_308 -> V_43 , V_214 ,
NULL ) ;
}
static int F_126 ( struct V_289 * V_43 ,
struct V_114 * V_115 , T_4 V_227 )
{
struct V_308 V_308 ;
memset ( & V_308 , 0 , sizeof( struct V_308 ) ) ;
V_308 . V_43 = V_43 ;
return F_127 ( & V_308 . V_309 , V_115 , 1 ,
& V_227 , F_125 ) ;
}
static int F_128 ( struct V_1 * T_1 ,
struct V_289 * V_43 )
{
struct V_310 * V_280 = V_43 -> V_280 ;
struct V_118 * V_119 ;
struct V_114 V_115 ;
bool V_311 = false ;
T_4 V_227 ;
int V_70 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_115 . type == T_1 -> V_117 && V_119 -> V_312 ) {
V_311 = true ;
break;
}
}
if ( ! V_311 ) {
F_129 ( L_48 ) ;
return 0 ;
}
memset ( & V_115 , 0 , sizeof( struct V_114 ) ) ;
V_115 . V_20 = sizeof( struct V_114 ) ;
V_115 . type = V_313 ;
V_115 . V_127 = V_119 -> V_115 . V_127 & V_314 ;
V_115 . V_127 |= V_315 | V_316 |
V_317 ;
if ( T_1 -> V_124 )
V_115 . V_127 &= ~ ( T_4 ) V_128 ;
else
V_115 . V_127 |= V_128 ;
if ( ! T_1 -> V_267 )
V_115 . V_127 &= ~ ( T_4 ) V_318 ;
V_115 . V_319 = V_119 -> V_115 . V_319 ;
V_115 . V_120 = V_119 -> V_115 . V_120 ;
V_115 . V_320 = V_119 -> V_115 . V_320 ;
V_115 . V_321 = V_119 -> V_115 . V_321 ;
V_115 . V_322 = V_119 -> V_115 . V_322 ;
V_115 . V_323 = V_119 -> V_115 . V_323 ;
V_115 . V_324 = V_119 -> V_115 . V_324 ;
V_227 = V_119 -> V_227 [ 0 ] + 1000000000 ;
if ( ! V_227 )
V_227 = 1 ;
if ( T_1 -> V_138 . V_162 ) {
V_115 . V_116 = V_325 ;
if ( T_1 -> V_138 . V_164 == V_169 )
V_115 . V_326 =
F_52 ( T_1 , T_1 -> V_138 . V_163 ) ;
else
V_115 . V_326 = T_1 -> V_138 . V_163 ;
T_1 -> V_327 = V_115 . V_326 ;
if ( T_1 -> V_138 . V_139 )
V_115 . V_127 |= V_328 ;
if ( T_1 -> V_138 . V_145 )
V_115 . V_127 |= V_329 ;
F_129 ( L_49 V_282 L_50 V_112 L_15 ,
V_227 , ( T_4 ) V_115 . V_127 ) ;
V_70 = F_126 ( V_43 , & V_115 , V_227 ) ;
if ( V_70 ) {
F_77 ( L_51 ,
V_330 ) ;
return V_70 ;
}
T_1 -> V_248 = true ;
T_1 -> V_238 = V_115 . V_127 ;
T_1 -> V_235 = V_227 ;
V_227 += 1 ;
}
if ( T_1 -> V_138 . V_331 ) {
V_115 . V_116 = V_325 ;
V_115 . V_326 = 1 ;
if ( T_1 -> V_138 . V_139 )
V_115 . V_127 |= V_328 ;
if ( T_1 -> V_138 . V_145 )
V_115 . V_127 |= V_329 ;
F_129 ( L_52 V_282 L_50 V_112 L_15 ,
V_227 , ( T_4 ) V_115 . V_127 ) ;
V_70 = F_126 ( V_43 , & V_115 , V_227 ) ;
if ( V_70 ) {
F_77 ( L_53 ,
V_330 ) ;
return V_70 ;
}
T_1 -> V_250 = true ;
T_1 -> V_239 = V_227 ;
V_227 += 1 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_227 && V_119 -> V_227 [ 0 ] == T_1 -> V_239 ) {
if ( V_119 -> V_265 )
F_56 ( & V_119 -> V_265 ) ;
V_119 -> V_265 = F_130 ( L_54 ) ;
break;
}
}
}
if ( T_1 -> V_138 . V_332 ) {
V_115 . V_116 = V_333 ;
V_115 . V_326 = 1 ;
V_115 . V_127 |= V_334 ;
V_115 . V_127 &= ~ ( T_4 ) V_328 ;
V_115 . V_127 &= ~ ( T_4 ) V_329 ;
F_129 ( L_55 V_282 L_50 V_112 L_15 ,
V_227 , ( T_4 ) V_115 . V_127 ) ;
V_70 = F_126 ( V_43 , & V_115 , V_227 ) ;
if ( V_70 ) {
F_77 ( L_56 ,
V_330 ) ;
return V_70 ;
}
T_1 -> V_254 = true ;
T_1 -> V_233 = V_115 . V_127 ;
T_1 -> V_228 = V_227 ;
}
T_1 -> V_234 = V_119 -> V_335 ;
return 0 ;
}
static struct V_118 * F_131 ( struct V_310 * V_280 )
{
struct V_118 * V_119 ;
F_132 (evlist, evsel) {
const char * V_265 = F_133 ( V_119 ) ;
if ( ! strcmp ( V_265 , L_57 ) )
return V_119 ;
}
return NULL ;
}
static bool F_134 ( struct V_310 * V_280 )
{
struct V_118 * V_119 ;
F_46 (evlist, evsel) {
if ( V_119 -> V_115 . V_285 )
return true ;
}
return false ;
}
static int F_135 ( const char * V_55 , const char * V_56 , void * V_19 )
{
struct V_1 * T_1 = V_19 ;
if ( ! strcmp ( V_55 , L_58 ) )
T_1 -> V_212 = F_136 ( V_55 , V_56 ) ;
return 0 ;
}
static void F_137 ( T_4 * V_336 , int V_18 , int V_337 )
{
int V_10 ;
if ( ! V_293 )
return;
for ( V_10 = V_18 ; V_10 <= V_337 ; V_10 ++ )
fprintf ( stdout , V_338 [ V_10 ] , V_336 [ V_10 ] ) ;
}
static void F_138 ( const char * V_265 , const char * V_339 )
{
if ( ! V_293 )
return;
fprintf ( stdout , L_59 , V_265 , V_339 ? V_339 : L_60 ) ;
}
static bool F_139 ( struct V_340 * V_341 , int V_7 )
{
return V_341 -> V_218 . V_20 >=
sizeof( struct V_340 ) + ( sizeof( T_4 ) * ( V_7 + 1 ) ) ;
}
int F_140 ( union V_213 * V_214 ,
struct V_289 * V_43 )
{
struct V_340 * V_341 = & V_214 -> V_341 ;
T_2 V_342 = sizeof( T_4 ) * V_343 ;
struct V_1 * T_1 ;
void * V_344 ;
T_4 * V_345 ;
int V_70 ;
if ( V_341 -> V_218 . V_20 < sizeof( struct V_340 ) +
V_342 )
return - V_22 ;
T_1 = F_54 ( sizeof( struct V_1 ) ) ;
if ( ! T_1 )
return - V_45 ;
F_141 ( & T_1 -> V_159 ) ;
F_20 ( F_135 , T_1 ) ;
V_70 = F_142 ( & T_1 -> V_39 ) ;
if ( V_70 )
goto V_346;
F_143 ( V_347 ) ;
T_1 -> V_43 = V_43 ;
T_1 -> V_35 = & V_43 -> V_348 . V_349 ;
T_1 -> V_350 = V_341 -> type ;
T_1 -> V_117 = V_341 -> V_171 [ V_351 ] ;
T_1 -> V_132 . V_134 = V_341 -> V_171 [ V_352 ] ;
T_1 -> V_132 . V_133 = V_341 -> V_171 [ V_353 ] ;
T_1 -> V_132 . V_354 = V_341 -> V_171 [ V_355 ] ;
T_1 -> V_126 = V_341 -> V_171 [ V_356 ] ;
T_1 -> V_125 = V_341 -> V_171 [ V_357 ] ;
T_1 -> V_121 = V_341 -> V_171 [ V_358 ] ;
T_1 -> V_172 = V_341 -> V_171 [ V_359 ] ;
T_1 -> V_46 = V_341 -> V_171 [ V_360 ] ;
T_1 -> V_267 = V_341 -> V_171 [ V_343 ] ;
F_137 ( & V_341 -> V_171 [ 0 ] , V_351 ,
V_343 ) ;
if ( F_139 ( V_341 , V_361 ) ) {
T_1 -> V_362 = V_341 -> V_171 [ V_363 ] ;
T_1 -> V_123 = V_341 -> V_171 [ V_364 ] ;
T_1 -> V_157 = V_341 -> V_171 [ V_365 ] ;
T_1 -> V_158 = V_341 -> V_171 [ V_366 ] ;
T_1 -> V_367 = V_341 -> V_171 [ V_361 ] ;
F_137 ( & V_341 -> V_171 [ 0 ] , V_363 ,
V_361 ) ;
}
if ( F_139 ( V_341 , V_368 ) ) {
T_1 -> V_155 =
V_341 -> V_171 [ V_368 ] ;
F_137 ( & V_341 -> V_171 [ 0 ] ,
V_368 ,
V_368 ) ;
}
V_345 = & V_341 -> V_171 [ V_369 ] + 1 ;
V_344 = ( void * ) V_345 + V_341 -> V_218 . V_20 ;
if ( F_139 ( V_341 , V_369 ) ) {
T_2 V_4 ;
V_4 = V_341 -> V_171 [ V_369 ] ;
F_137 ( & V_341 -> V_171 [ 0 ] ,
V_369 ,
V_369 ) ;
if ( V_4 ) {
const char * V_303 = ( const char * ) V_345 ;
V_4 = F_144 ( V_4 + 1 , 8 ) ;
V_345 += V_4 >> 3 ;
if ( ( void * ) V_345 > V_344 ) {
F_77 ( L_61 , V_330 ) ;
V_70 = - V_22 ;
goto V_370;
}
T_1 -> V_303 = F_145 ( V_303 , V_4 ) ;
if ( ! T_1 -> V_303 ) {
V_70 = - V_45 ;
goto V_370;
}
if ( V_43 -> V_218 . V_335 )
F_146 ( T_1 -> V_303 , V_4 ) ;
if ( T_1 -> V_303 [ V_4 - 1 ] ) {
F_77 ( L_62 , V_330 ) ;
V_70 = - V_22 ;
goto V_370;
}
V_70 = F_147 ( & T_1 -> V_159 ,
V_303 ) ;
if ( V_70 )
goto V_370;
}
F_138 ( L_63 , T_1 -> V_303 ) ;
}
T_1 -> V_124 = F_49 ( T_1 ) ;
T_1 -> V_21 = F_51 ( T_1 ) ;
T_1 -> V_50 = false ;
T_1 -> V_269 = ! T_1 -> V_124 ;
T_1 -> V_93 = F_148 ( 999999999 , 999999999 ) ;
if ( ! T_1 -> V_93 ) {
V_70 = - V_45 ;
goto V_370;
}
F_149 ( & T_1 -> V_93 -> V_371 ) ;
V_70 = F_150 ( T_1 -> V_93 , L_64 , 0 ) ;
if ( V_70 )
goto V_372;
if ( F_151 ( T_1 -> V_93 , T_1 -> V_35 ) ) {
V_70 = - V_45 ;
goto V_372;
}
T_1 -> V_292 . V_373 = F_109 ;
T_1 -> V_292 . V_374 = F_120 ;
T_1 -> V_292 . V_375 = F_112 ;
T_1 -> V_292 . V_376 = F_113 ;
T_1 -> V_292 . free = F_116 ;
V_43 -> V_292 = & T_1 -> V_292 ;
if ( V_293 )
return 0 ;
if ( T_1 -> V_172 == 1 ) {
T_1 -> V_281 = F_131 ( V_43 -> V_280 ) ;
if ( ! T_1 -> V_281 ) {
F_77 ( L_65 , V_330 ) ;
V_70 = - V_22 ;
goto V_372;
}
} else if ( T_1 -> V_172 == 2 &&
! F_134 ( V_43 -> V_280 ) ) {
F_77 ( L_66 , V_330 ) ;
V_70 = - V_22 ;
goto V_372;
}
if ( V_43 -> V_377 && V_43 -> V_377 -> V_378 ) {
T_1 -> V_138 = * V_43 -> V_377 ;
} else {
F_152 ( & T_1 -> V_138 ) ;
if ( V_379 != - 1 ) {
T_1 -> V_138 . V_332 = false ;
T_1 -> V_138 . V_139 = true ;
}
if ( V_43 -> V_377 )
T_1 -> V_138 . V_253 =
V_43 -> V_377 -> V_253 ;
}
if ( T_1 -> V_138 . log )
F_153 () ;
if ( T_1 -> V_132 . V_133 ) {
T_4 V_380 = F_52 ( T_1 , 1000000000 ) ;
if ( ! T_1 -> V_155 )
T_1 -> V_155 =
( V_380 + 50000000 ) / 100000000 ;
F_9 ( L_67 V_282 L_15 , V_380 ) ;
F_9 ( L_68 ,
T_1 -> V_155 ) ;
}
if ( T_1 -> V_138 . V_381 )
T_1 -> V_221 |= V_180 | V_181 |
V_183 ;
if ( T_1 -> V_138 . V_382 )
T_1 -> V_221 |= V_383 |
V_187 ;
if ( T_1 -> V_138 . V_139 && ! V_384 . V_385 ) {
V_384 . V_385 = true ;
if ( F_154 ( & V_386 ) < 0 ) {
V_384 . V_385 = false ;
T_1 -> V_138 . V_139 = false ;
}
}
V_70 = F_128 ( T_1 , V_43 ) ;
if ( V_70 )
goto V_372;
V_70 = F_155 ( & T_1 -> V_39 , V_43 ) ;
if ( V_70 )
goto V_372;
if ( T_1 -> V_39 . V_387 )
T_1 -> V_304 = true ;
if ( T_1 -> V_124 )
F_156 ( L_69 ) ;
return 0 ;
V_372:
F_10 ( T_1 -> V_93 ) ;
V_370:
F_114 () ;
F_115 ( & T_1 -> V_39 ) ;
V_43 -> V_292 = NULL ;
V_346:
F_119 ( & T_1 -> V_159 ) ;
F_56 ( & T_1 -> V_303 ) ;
free ( T_1 ) ;
return V_70 ;
}
