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
V_70 = F_28 ( V_62 , V_65 , & V_69 -> V_75 ) ;
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
T_5 * V_76 , T_5 * V_77 ,
T_5 V_78 , T_5 V_79 ,
void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_35 * V_35 = V_26 -> T_1 -> V_35 ;
struct V_34 * V_34 ;
struct V_80 V_81 ;
unsigned char V_3 [ 1024 ] ;
T_2 V_82 ;
T_6 V_4 ;
int V_83 ;
T_7 V_84 ;
T_4 V_65 , V_85 , V_86 ;
T_4 V_66 = 0 ;
bool V_87 = true ;
if ( V_78 && * V_77 == V_78 )
goto V_88;
V_82 = F_33 () ;
if ( * V_77 >= V_26 -> T_1 -> V_89 )
V_84 = V_90 ;
else
V_84 = V_91 ;
V_34 = V_26 -> V_34 ;
if ( ! V_34 ) {
if ( V_84 != V_90 )
return - V_22 ;
V_34 = V_26 -> T_1 -> V_92 ;
}
while ( 1 ) {
F_34 ( V_34 , V_84 , V_93 , * V_77 , & V_81 ) ;
if ( ! V_81 . V_94 || ! V_81 . V_94 -> V_60 )
return - V_22 ;
if ( V_81 . V_94 -> V_60 -> V_19 . V_95 == V_96 &&
F_35 ( V_81 . V_94 -> V_60 ,
V_97 ) )
return - V_98 ;
V_65 = V_81 . V_94 -> V_99 ( V_81 . V_94 , * V_77 ) ;
if ( ! V_78 && V_87 ) {
struct V_64 * V_69 ;
V_69 = F_30 ( V_81 . V_94 -> V_60 , V_35 , V_65 ) ;
if ( V_69 &&
( ! V_79 || V_69 -> V_66 <= V_79 ) ) {
* V_76 = V_69 -> V_66 ;
* V_77 += V_69 -> V_67 ;
V_68 -> V_71 = V_69 -> V_71 ;
V_68 -> V_72 = V_69 -> V_72 ;
V_68 -> V_73 = V_69 -> V_73 ;
V_68 -> V_74 = V_69 -> V_74 ;
F_36 ( V_68 , * V_77 ) ;
return 0 ;
}
}
V_85 = V_65 ;
V_86 = * V_77 ;
F_37 ( V_81 . V_94 ) ;
V_83 = V_81 . V_94 -> V_60 -> V_100 ;
while ( 1 ) {
V_4 = F_38 ( V_81 . V_94 -> V_60 , V_35 ,
V_65 , V_3 , V_82 ) ;
if ( V_4 <= 0 )
return - V_22 ;
if ( F_39 ( V_3 , V_4 , V_83 , V_68 ) )
return - V_22 ;
F_40 ( V_68 , * V_77 ) ;
V_66 += 1 ;
if ( V_68 -> V_72 != V_101 )
goto V_102;
if ( V_79 && V_66 >= V_79 )
goto V_88;
* V_77 += V_68 -> V_73 ;
if ( V_78 && * V_77 == V_78 )
goto V_88;
if ( * V_77 >= V_81 . V_94 -> V_103 )
break;
V_65 += V_68 -> V_73 ;
}
V_87 = false ;
}
V_102:
* V_76 = V_66 ;
if ( ! V_87 )
goto V_88;
if ( V_78 ) {
struct V_64 * V_69 ;
V_69 = F_30 ( V_81 . V_94 -> V_60 , V_35 , V_85 ) ;
if ( V_69 )
return 0 ;
}
F_26 ( V_81 . V_94 -> V_60 , V_35 , V_85 , V_66 ,
* V_77 - V_86 , V_68 ) ;
return 0 ;
V_88:
* V_76 = V_66 ;
return 0 ;
}
static bool F_41 ( struct V_1 * T_1 , T_5 V_77 ,
T_5 V_65 , const char * V_104 )
{
struct V_105 * V_106 ;
bool V_107 = false ;
bool V_108 = false ;
bool V_109 = false ;
F_42 (filt, &pt->filts.head, list) {
if ( V_106 -> V_18 )
V_107 = true ;
if ( ( V_104 && ! V_106 -> V_104 ) ||
( ! V_104 && V_106 -> V_104 ) ||
( V_104 && strcmp ( V_104 , V_106 -> V_104 ) ) )
continue;
if ( ! ( V_65 >= V_106 -> V_110 && V_65 < V_106 -> V_110 + V_106 -> V_20 ) )
continue;
F_9 ( L_11 V_111 L_12 V_111 L_13 V_111 L_14 V_111 L_15 ,
V_77 , V_65 , V_104 ? V_104 : L_16 ,
V_106 -> V_18 ? L_17 : L_18 ,
V_106 -> V_110 , V_106 -> V_20 ) ;
if ( V_106 -> V_18 )
V_109 = true ;
else
V_108 = true ;
}
if ( ! V_108 && ! V_109 )
F_9 ( L_11 V_111 L_12 V_111 L_19 ,
V_77 , V_65 , V_104 ? V_104 : L_16 ) ;
return V_108 || ( V_107 && ! V_109 ) ;
}
static int F_43 ( T_5 V_77 , void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_34 * V_34 ;
struct V_80 V_81 ;
T_7 V_84 ;
T_4 V_65 ;
if ( V_77 >= V_26 -> T_1 -> V_89 )
return F_41 ( V_26 -> T_1 , V_77 , V_77 , NULL ) ;
V_84 = V_91 ;
V_34 = V_26 -> V_34 ;
if ( ! V_34 )
return - V_22 ;
F_34 ( V_34 , V_84 , V_93 , V_77 , & V_81 ) ;
if ( ! V_81 . V_94 || ! V_81 . V_94 -> V_60 )
return - V_22 ;
V_65 = V_81 . V_94 -> V_99 ( V_81 . V_94 , V_77 ) ;
return F_41 ( V_26 -> T_1 , V_77 , V_65 ,
V_81 . V_94 -> V_60 -> V_112 ) ;
}
static bool F_44 ( T_5 V_77 , void * V_19 )
{
return F_43 ( V_77 , V_19 ) > 0 ;
}
static bool F_45 ( struct V_1 * T_1 ,
struct V_113 * V_114 , T_4 * V_115 )
{
if ( V_114 -> type == T_1 -> V_116 ) {
if ( V_115 )
* V_115 = V_114 -> V_115 ;
return true ;
}
return false ;
}
static bool F_46 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
F_47 (pt->session->evlist, evsel) {
if ( F_45 ( T_1 , & V_118 -> V_114 , NULL ) &&
! V_118 -> V_114 . V_119 )
return false ;
}
return true ;
}
static bool F_48 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
T_4 V_115 ;
if ( ! T_1 -> V_120 )
return true ;
F_47 (pt->session->evlist, evsel) {
if ( F_45 ( T_1 , & V_118 -> V_114 , & V_115 ) &&
( V_115 & T_1 -> V_120 ) )
return false ;
}
return true ;
}
static unsigned int F_49 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
unsigned int V_121 ;
T_4 V_115 ;
if ( ! T_1 -> V_122 )
return 0 ;
for ( V_121 = 0 , V_115 = T_1 -> V_122 ; ! ( V_115 & 1 ) ; V_121 ++ )
V_115 >>= 1 ;
F_47 (pt->session->evlist, evsel) {
if ( F_45 ( T_1 , & V_118 -> V_114 , & V_115 ) )
return ( V_115 & T_1 -> V_122 ) >> V_121 ;
}
return 0 ;
}
static bool F_50 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
bool V_123 = true ;
T_4 V_115 ;
if ( ! T_1 -> V_124 || ! T_1 -> V_125 )
return true ;
F_47 (pt->session->evlist, evsel) {
if ( ! ( V_118 -> V_114 . V_126 & V_127 ) )
return true ;
if ( F_45 ( T_1 , & V_118 -> V_114 , & V_115 ) ) {
if ( V_115 & T_1 -> V_124 )
V_123 = false ;
else
return true ;
}
}
return V_123 ;
}
static bool F_51 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
F_47 (pt->session->evlist, evsel) {
if ( F_45 ( T_1 , & V_118 -> V_114 , NULL ) &&
! V_118 -> V_114 . V_119 )
return true ;
}
return false ;
}
static bool F_52 ( struct V_1 * T_1 )
{
struct V_117 * V_118 ;
bool V_21 = false ;
T_4 V_115 ;
if ( ! T_1 -> V_124 )
return false ;
F_47 (pt->session->evlist, evsel) {
if ( F_45 ( T_1 , & V_118 -> V_114 , & V_115 ) ) {
if ( V_115 & T_1 -> V_124 )
V_21 = true ;
else
return false ;
}
}
return V_21 ;
}
static T_4 F_53 ( const struct V_1 * T_1 , T_4 V_128 )
{
T_4 V_129 , V_130 ;
V_129 = V_128 / T_1 -> V_131 . V_132 ;
V_130 = V_128 % T_1 -> V_131 . V_132 ;
return ( V_129 << T_1 -> V_131 . V_133 ) + ( V_130 << T_1 -> V_131 . V_133 ) /
T_1 -> V_131 . V_132 ;
}
static struct V_25 * F_54 ( struct V_1 * T_1 ,
unsigned int V_33 )
{
struct V_134 V_135 = { . V_136 = 0 , } ;
struct V_25 * V_26 ;
V_26 = F_55 ( sizeof( struct V_25 ) ) ;
if ( ! V_26 )
return NULL ;
if ( T_1 -> V_137 . V_138 ) {
T_2 V_139 = sizeof( struct V_140 ) ;
V_139 += T_1 -> V_137 . V_141 * sizeof( T_4 ) ;
V_26 -> V_142 = F_55 ( V_139 ) ;
if ( ! V_26 -> V_142 )
goto V_143;
}
if ( T_1 -> V_137 . V_144 ) {
T_2 V_139 = sizeof( struct V_145 ) ;
V_139 += T_1 -> V_137 . V_146 *
sizeof( struct V_147 ) ;
V_26 -> V_144 = F_55 ( V_139 ) ;
if ( ! V_26 -> V_144 )
goto V_143;
V_26 -> V_148 = F_55 ( V_139 ) ;
if ( ! V_26 -> V_148 )
goto V_143;
}
V_26 -> V_149 = malloc ( V_150 ) ;
if ( ! V_26 -> V_149 )
goto V_143;
V_26 -> T_1 = T_1 ;
V_26 -> V_33 = V_33 ;
V_26 -> V_119 = F_46 ( T_1 ) ;
V_26 -> V_31 = - 1 ;
V_26 -> V_32 = - 1 ;
V_26 -> V_30 = - 1 ;
V_26 -> V_151 = - 1 ;
V_135 . V_136 = F_13 ;
V_135 . V_152 = F_32 ;
V_135 . V_19 = V_26 ;
V_135 . V_153 = F_48 ( T_1 ) ;
V_135 . V_154 = T_1 -> V_154 ;
V_135 . V_155 = F_49 ( T_1 ) ;
V_135 . V_156 = T_1 -> V_156 ;
V_135 . V_157 = T_1 -> V_157 ;
if ( T_1 -> V_158 . V_159 > 0 )
V_135 . V_160 = F_44 ;
if ( T_1 -> V_137 . V_161 ) {
if ( T_1 -> V_137 . V_162 ) {
switch ( T_1 -> V_137 . V_163 ) {
case V_164 :
V_135 . V_163 =
V_165 ;
V_135 . V_162 = T_1 -> V_137 . V_162 ;
break;
case V_166 :
V_135 . V_163 = V_167 ;
V_135 . V_162 = T_1 -> V_137 . V_162 ;
break;
case V_168 :
V_135 . V_163 = V_167 ;
V_135 . V_162 = F_53 ( T_1 ,
T_1 -> V_137 . V_162 ) ;
break;
default:
break;
}
}
if ( ! V_135 . V_162 ) {
V_135 . V_163 = V_165 ;
V_135 . V_162 = 1 ;
}
}
V_26 -> V_169 = F_56 ( & V_135 ) ;
if ( ! V_26 -> V_169 )
goto V_143;
return V_26 ;
V_143:
F_57 ( & V_26 -> V_149 ) ;
F_57 ( & V_26 -> V_144 ) ;
F_57 ( & V_26 -> V_148 ) ;
F_57 ( & V_26 -> V_142 ) ;
free ( V_26 ) ;
return NULL ;
}
static void F_58 ( void * V_170 )
{
struct V_25 * V_26 = V_170 ;
if ( ! V_26 )
return;
F_10 ( V_26 -> V_34 ) ;
F_59 ( V_26 -> V_169 ) ;
F_57 ( & V_26 -> V_149 ) ;
F_57 ( & V_26 -> V_144 ) ;
F_57 ( & V_26 -> V_148 ) ;
F_57 ( & V_26 -> V_142 ) ;
free ( V_26 ) ;
}
static void F_60 ( struct V_1 * T_1 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_170 ;
if ( V_28 -> V_32 == - 1 || T_1 -> V_171 ) {
V_26 -> V_32 = F_61 ( T_1 -> V_35 , V_26 -> V_30 ) ;
F_10 ( V_26 -> V_34 ) ;
}
if ( ! V_26 -> V_34 && V_26 -> V_32 != - 1 )
V_26 -> V_34 = F_12 ( T_1 -> V_35 , - 1 , V_26 -> V_32 ) ;
if ( V_26 -> V_34 ) {
V_26 -> V_31 = V_26 -> V_34 -> V_172 ;
if ( V_28 -> V_30 == - 1 )
V_26 -> V_30 = V_26 -> V_34 -> V_30 ;
}
}
static void F_62 ( struct V_25 * V_26 )
{
if ( V_26 -> V_173 -> V_174 & V_175 ) {
V_26 -> V_174 = V_176 | V_177 ;
} else if ( V_26 -> V_173 -> V_174 & V_178 ) {
if ( V_26 -> V_173 -> V_78 )
V_26 -> V_174 = V_176 | V_179 |
V_180 |
V_181 ;
else
V_26 -> V_174 = V_176 |
V_182 ;
V_26 -> V_183 = 0 ;
} else {
if ( V_26 -> V_173 -> V_184 )
V_26 -> V_174 = F_63 ( V_26 -> V_173 -> V_185 ) ;
else
V_26 -> V_174 = V_176 |
V_186 ;
if ( V_26 -> V_173 -> V_174 & V_187 )
V_26 -> V_174 |= V_188 ;
V_26 -> V_183 = V_26 -> V_173 -> V_183 ;
}
}
static int F_64 ( struct V_1 * T_1 ,
struct V_27 * V_28 ,
unsigned int V_33 )
{
struct V_25 * V_26 = V_28 -> V_170 ;
if ( F_65 ( & V_28 -> V_189 ) )
return 0 ;
if ( ! V_26 ) {
V_26 = F_54 ( T_1 , V_33 ) ;
if ( ! V_26 )
return - V_45 ;
V_28 -> V_170 = V_26 ;
if ( V_28 -> V_30 != - 1 )
V_26 -> V_30 = V_28 -> V_30 ;
V_26 -> V_32 = V_28 -> V_32 ;
if ( T_1 -> V_50 ) {
if ( T_1 -> V_123 )
V_26 -> V_54 = true ;
if ( T_1 -> V_123 || ! T_1 -> V_171 )
V_26 -> V_53 = true ;
}
}
if ( ! V_26 -> V_190 &&
( ! T_1 -> V_191 ||
V_26 -> V_192 != V_193 ) ) {
const struct V_194 * V_173 ;
int V_8 ;
if ( T_1 -> V_123 )
return 0 ;
F_9 ( L_20 , V_33 ) ;
F_9 ( L_21 ,
V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_173 = F_66 ( V_26 -> V_169 ) ;
if ( V_173 -> V_70 ) {
if ( V_173 -> V_70 == V_195 ) {
F_9 ( L_22 ,
V_33 ) ;
return 0 ;
}
continue;
}
if ( V_173 -> V_196 )
break;
}
V_26 -> V_196 = V_173 -> V_196 ;
F_9 ( L_23 V_111 L_15 ,
V_33 , V_26 -> V_196 ) ;
V_26 -> V_173 = V_173 ;
V_26 -> V_197 = true ;
F_62 ( V_26 ) ;
V_8 = F_67 ( & T_1 -> V_198 , V_33 , V_26 -> V_196 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_190 = true ;
}
return 0 ;
}
static int F_68 ( struct V_1 * T_1 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < T_1 -> V_39 . V_199 ; V_10 ++ ) {
V_8 = F_64 ( T_1 , & T_1 -> V_39 . V_40 [ V_10 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static inline void F_69 ( struct V_25 * V_26 )
{
struct V_145 * V_200 = V_26 -> V_148 ;
struct V_145 * V_201 = V_26 -> V_144 ;
T_2 V_202 = 0 ;
V_201 -> V_202 = V_200 -> V_202 ;
if ( ! V_200 -> V_202 )
return;
V_202 = V_26 -> T_1 -> V_137 . V_146 - V_26 -> V_203 ;
memcpy ( & V_201 -> V_204 [ 0 ] ,
& V_200 -> V_204 [ V_26 -> V_203 ] ,
sizeof( struct V_147 ) * V_202 ) ;
if ( V_200 -> V_202 >= V_26 -> T_1 -> V_137 . V_146 ) {
memcpy ( & V_201 -> V_204 [ V_202 ] ,
& V_200 -> V_204 [ 0 ] ,
sizeof( struct V_147 ) * V_26 -> V_203 ) ;
}
}
static inline void F_70 ( struct V_25 * V_26 )
{
V_26 -> V_203 = 0 ;
V_26 -> V_148 -> V_202 = 0 ;
}
static void F_71 ( struct V_25 * V_26 )
{
const struct V_194 * V_173 = V_26 -> V_173 ;
struct V_145 * V_205 = V_26 -> V_148 ;
struct V_147 * V_206 ;
if ( ! V_26 -> V_203 )
V_26 -> V_203 = V_26 -> T_1 -> V_137 . V_146 ;
V_26 -> V_203 -= 1 ;
V_206 = & V_205 -> V_204 [ V_26 -> V_203 ] ;
V_206 -> V_207 = V_173 -> V_184 ;
V_206 -> V_208 = V_173 -> V_78 ;
V_206 -> V_174 . abort = ! ! ( V_173 -> V_174 & V_175 ) ;
V_206 -> V_174 . V_209 = ! ! ( V_173 -> V_174 & V_187 ) ;
V_206 -> V_174 . V_210 = V_26 -> T_1 -> V_211 ;
if ( V_205 -> V_202 < V_26 -> T_1 -> V_137 . V_146 )
V_205 -> V_202 += 1 ;
}
static int F_72 ( union V_212 * V_213 ,
struct V_214 * V_215 , T_4 type ,
bool V_216 )
{
V_213 -> V_217 . V_20 = F_73 ( V_215 , type , 0 ) ;
return F_74 ( V_213 , type , 0 , V_215 , V_216 ) ;
}
static int F_75 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_212 * V_213 = V_26 -> V_149 ;
struct V_214 V_215 = { . V_77 = 0 , } ;
struct V_218 {
T_4 V_202 ;
struct V_147 V_204 ;
} V_219 ;
if ( T_1 -> V_220 && ! ( T_1 -> V_220 & V_26 -> V_174 ) )
return 0 ;
if ( T_1 -> V_137 . V_221 &&
T_1 -> V_222 ++ < T_1 -> V_137 . V_221 )
return 0 ;
V_213 -> V_215 . V_217 . type = V_223 ;
V_213 -> V_215 . V_217 . V_224 = V_91 ;
V_213 -> V_215 . V_217 . V_20 = sizeof( struct V_225 ) ;
if ( ! T_1 -> V_123 )
V_215 . time = F_76 ( V_26 -> V_196 , & T_1 -> V_131 ) ;
V_215 . V_84 = V_91 ;
V_215 . V_77 = V_26 -> V_173 -> V_184 ;
V_215 . V_31 = V_26 -> V_31 ;
V_215 . V_32 = V_26 -> V_32 ;
V_215 . V_110 = V_26 -> V_173 -> V_78 ;
V_215 . V_226 = V_26 -> T_1 -> V_227 ;
V_215 . V_228 = V_26 -> T_1 -> V_227 ;
V_215 . V_162 = 1 ;
V_215 . V_30 = V_26 -> V_30 ;
V_215 . V_174 = V_26 -> V_174 ;
V_215 . V_183 = V_26 -> V_183 ;
if ( T_1 -> V_137 . V_144 && V_229 == V_230 ) {
V_219 = (struct V_218 ) {
. V_202 = 1 ,
. V_204 = {
. V_207 = V_215 . V_77 ,
. V_208 = V_215 . V_110 ,
} ,
} ;
V_215 . V_145 = (struct V_145 * ) & V_219 ;
}
if ( T_1 -> V_137 . V_231 ) {
V_8 = F_72 ( V_213 , & V_215 ,
T_1 -> V_232 ,
T_1 -> V_233 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_77 ( T_1 -> V_43 , V_213 , & V_215 ) ;
if ( V_8 )
F_78 ( L_24 ,
V_8 ) ;
return V_8 ;
}
static int F_79 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_212 * V_213 = V_26 -> V_149 ;
struct V_214 V_215 = { . V_77 = 0 , } ;
if ( T_1 -> V_137 . V_221 &&
T_1 -> V_222 ++ < T_1 -> V_137 . V_221 )
return 0 ;
V_213 -> V_215 . V_217 . type = V_223 ;
V_213 -> V_215 . V_217 . V_224 = V_91 ;
V_213 -> V_215 . V_217 . V_20 = sizeof( struct V_225 ) ;
if ( ! T_1 -> V_123 )
V_215 . time = F_76 ( V_26 -> V_196 , & T_1 -> V_131 ) ;
V_215 . V_84 = V_91 ;
V_215 . V_77 = V_26 -> V_173 -> V_184 ;
V_215 . V_31 = V_26 -> V_31 ;
V_215 . V_32 = V_26 -> V_32 ;
V_215 . V_110 = V_26 -> V_173 -> V_78 ;
V_215 . V_226 = V_26 -> T_1 -> V_234 ;
V_215 . V_228 = V_26 -> T_1 -> V_234 ;
V_215 . V_162 = V_26 -> V_173 -> V_235 - V_26 -> V_236 ;
V_215 . V_30 = V_26 -> V_30 ;
V_215 . V_174 = V_26 -> V_174 ;
V_215 . V_183 = V_26 -> V_183 ;
V_26 -> V_236 = V_26 -> V_173 -> V_235 ;
if ( T_1 -> V_137 . V_138 ) {
F_80 ( V_26 -> V_34 , V_26 -> V_142 ,
T_1 -> V_137 . V_141 , V_215 . V_77 ) ;
V_215 . V_138 = V_26 -> V_142 ;
}
if ( T_1 -> V_137 . V_144 ) {
F_69 ( V_26 ) ;
V_215 . V_145 = V_26 -> V_144 ;
}
if ( T_1 -> V_137 . V_231 ) {
V_8 = F_72 ( V_213 , & V_215 ,
T_1 -> V_237 ,
T_1 -> V_233 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_77 ( T_1 -> V_43 , V_213 , & V_215 ) ;
if ( V_8 )
F_78 ( L_25 ,
V_8 ) ;
if ( T_1 -> V_137 . V_144 )
F_70 ( V_26 ) ;
return V_8 ;
}
static int F_81 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_212 * V_213 = V_26 -> V_149 ;
struct V_214 V_215 = { . V_77 = 0 , } ;
if ( T_1 -> V_137 . V_221 &&
T_1 -> V_222 ++ < T_1 -> V_137 . V_221 )
return 0 ;
V_213 -> V_215 . V_217 . type = V_223 ;
V_213 -> V_215 . V_217 . V_224 = V_91 ;
V_213 -> V_215 . V_217 . V_20 = sizeof( struct V_225 ) ;
if ( ! T_1 -> V_123 )
V_215 . time = F_76 ( V_26 -> V_196 , & T_1 -> V_131 ) ;
V_215 . V_84 = V_91 ;
V_215 . V_77 = V_26 -> V_173 -> V_184 ;
V_215 . V_31 = V_26 -> V_31 ;
V_215 . V_32 = V_26 -> V_32 ;
V_215 . V_110 = V_26 -> V_173 -> V_78 ;
V_215 . V_226 = V_26 -> T_1 -> V_238 ;
V_215 . V_228 = V_26 -> T_1 -> V_238 ;
V_215 . V_162 = 1 ;
V_215 . V_30 = V_26 -> V_30 ;
V_215 . V_174 = V_26 -> V_174 ;
V_215 . V_183 = V_26 -> V_183 ;
if ( T_1 -> V_137 . V_138 ) {
F_80 ( V_26 -> V_34 , V_26 -> V_142 ,
T_1 -> V_137 . V_141 , V_215 . V_77 ) ;
V_215 . V_138 = V_26 -> V_142 ;
}
if ( T_1 -> V_137 . V_144 ) {
F_69 ( V_26 ) ;
V_215 . V_145 = V_26 -> V_144 ;
}
if ( T_1 -> V_137 . V_231 ) {
V_8 = F_72 ( V_213 , & V_215 ,
T_1 -> V_239 ,
T_1 -> V_233 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_77 ( T_1 -> V_43 , V_213 , & V_215 ) ;
if ( V_8 )
F_78 ( L_26 ,
V_8 ) ;
if ( T_1 -> V_137 . V_144 )
F_70 ( V_26 ) ;
return V_8 ;
}
static int F_82 ( struct V_1 * T_1 , int V_240 , int V_30 ,
T_8 V_31 , T_8 V_32 , T_4 V_77 )
{
union V_212 V_213 ;
char V_241 [ V_242 ] ;
int V_70 ;
F_83 ( V_240 , V_241 , V_242 ) ;
F_84 ( & V_213 . V_243 , V_244 ,
V_240 , V_30 , V_31 , V_32 , V_77 , V_241 ) ;
V_70 = F_77 ( T_1 -> V_43 , & V_213 , NULL ) ;
if ( V_70 )
F_78 ( L_27 ,
V_70 ) ;
return V_70 ;
}
static int F_85 ( struct V_1 * T_1 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_8 V_32 = V_26 -> V_151 ;
int V_70 ;
if ( V_32 == - 1 )
return 0 ;
F_9 ( L_28 , V_26 -> V_30 , V_32 ) ;
V_70 = F_86 ( T_1 -> V_35 , V_26 -> V_30 , - 1 , V_32 ) ;
V_28 = & T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
F_60 ( T_1 , V_28 ) ;
V_26 -> V_151 = - 1 ;
return V_70 ;
}
static inline bool F_87 ( struct V_25 * V_26 , T_4 V_77 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
return V_77 == T_1 -> V_245 &&
( V_26 -> V_174 & V_176 ) &&
! ( V_26 -> V_174 & ( V_246 | V_180 |
V_181 | V_177 ) ) ;
}
static int F_88 ( struct V_25 * V_26 )
{
const struct V_194 * V_173 = V_26 -> V_173 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! V_26 -> V_197 )
return 0 ;
V_26 -> V_197 = false ;
if ( T_1 -> V_247 &&
( V_173 -> type & V_248 ) &&
( ! T_1 -> V_137 . V_221 ||
T_1 -> V_222 ++ >= T_1 -> V_137 . V_221 ) ) {
V_70 = F_79 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_249 &&
( V_173 -> type & V_250 ) &&
( ! T_1 -> V_137 . V_221 ||
T_1 -> V_222 ++ >= T_1 -> V_137 . V_221 ) ) {
V_70 = F_81 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( ! ( V_173 -> type & V_251 ) )
return 0 ;
if ( T_1 -> V_137 . V_138 || T_1 -> V_137 . V_252 )
F_89 ( V_26 -> V_34 , V_26 -> V_174 , V_173 -> V_184 ,
V_173 -> V_78 , V_26 -> V_183 ,
V_173 -> V_51 ) ;
else
F_90 ( V_26 -> V_34 , V_173 -> V_51 ) ;
if ( T_1 -> V_253 ) {
V_70 = F_75 ( V_26 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_137 . V_144 )
F_71 ( V_26 ) ;
if ( ! T_1 -> V_191 )
return 0 ;
if ( F_87 ( V_26 , V_173 -> V_78 ) ) {
switch ( V_26 -> V_192 ) {
case V_254 :
case V_255 :
V_70 = F_85 ( T_1 , V_26 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_192 = V_256 ;
break;
default:
V_26 -> V_192 = V_193 ;
return 1 ;
}
} else if ( ! V_173 -> V_78 ) {
V_26 -> V_192 = V_257 ;
} else if ( V_26 -> V_192 == V_257 ) {
V_26 -> V_192 = V_254 ;
} else if ( V_26 -> V_192 == V_254 &&
V_173 -> V_78 == T_1 -> V_258 &&
( V_26 -> V_174 & V_179 ) ) {
V_26 -> V_192 = V_256 ;
}
return 0 ;
}
static T_4 F_91 ( struct V_1 * T_1 , T_4 * V_258 )
{
struct V_35 * V_35 = T_1 -> V_35 ;
struct V_94 * V_94 ;
struct V_259 * V_260 , * V_18 ;
T_4 V_77 , V_245 = 0 ;
const char * V_261 ;
if ( V_258 )
* V_258 = 0 ;
V_94 = F_92 ( V_35 ) ;
if ( ! V_94 )
return 0 ;
if ( F_37 ( V_94 ) )
return 0 ;
V_18 = F_93 ( V_94 -> V_60 , V_93 ) ;
for ( V_260 = V_18 ; V_260 ; V_260 = F_94 ( V_260 ) ) {
if ( V_260 -> V_262 == V_263 &&
! strcmp ( V_260 -> V_264 , L_29 ) ) {
V_77 = V_94 -> V_265 ( V_94 , V_260 -> V_18 ) ;
if ( V_77 >= V_94 -> V_18 && V_77 < V_94 -> V_103 ) {
V_245 = V_77 ;
break;
}
}
}
if ( ! V_245 || ! V_258 )
return 0 ;
if ( T_1 -> V_171 == 1 )
V_261 = L_30 ;
else
V_261 = L_31 ;
for ( V_260 = V_18 ; V_260 ; V_260 = F_94 ( V_260 ) ) {
if ( ! strcmp ( V_260 -> V_264 , V_261 ) ) {
V_77 = V_94 -> V_265 ( V_94 , V_260 -> V_18 ) ;
if ( V_77 >= V_94 -> V_18 && V_77 < V_94 -> V_103 ) {
* V_258 = V_77 ;
break;
}
}
}
return V_245 ;
}
static int F_95 ( struct V_25 * V_26 , T_4 * V_196 )
{
const struct V_194 * V_173 = V_26 -> V_173 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_70 ;
if ( ! T_1 -> V_89 ) {
T_1 -> V_89 = F_96 ( T_1 -> V_35 ) ;
if ( T_1 -> V_266 &&
( T_1 -> V_171 == 1 || T_1 -> V_171 == 3 ) &&
! T_1 -> V_123 && F_51 ( T_1 ) &&
! T_1 -> V_50 ) {
T_1 -> V_245 = F_91 ( T_1 , & T_1 -> V_258 ) ;
if ( T_1 -> V_245 ) {
F_9 ( L_32 V_111 L_33 V_111 L_15 ,
T_1 -> V_245 , T_1 -> V_258 ) ;
T_1 -> V_191 = true ;
}
}
}
F_9 ( L_21 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_70 = F_88 ( V_26 ) ;
if ( V_70 )
return V_70 ;
V_173 = F_66 ( V_26 -> V_169 ) ;
if ( V_173 -> V_70 ) {
if ( V_173 -> V_70 == V_195 )
return 1 ;
if ( T_1 -> V_191 &&
V_173 -> V_184 >= T_1 -> V_89 ) {
T_1 -> V_191 = false ;
F_85 ( T_1 , V_26 ) ;
}
if ( T_1 -> V_137 . V_267 ) {
V_70 = F_82 ( T_1 , V_173 -> V_70 ,
V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_32 ,
V_173 -> V_184 ) ;
if ( V_70 )
return V_70 ;
}
continue;
}
V_26 -> V_173 = V_173 ;
V_26 -> V_197 = true ;
F_62 ( V_26 ) ;
if ( T_1 -> V_268 &&
( V_173 -> V_184 >= T_1 -> V_89 || ! V_173 -> V_184 ) &&
V_173 -> V_78 && V_173 -> V_78 < T_1 -> V_89 ) {
F_9 ( L_34 V_111 L_35 V_111 L_15 ,
V_173 -> V_196 , V_173 -> V_269 ) ;
V_26 -> V_196 = V_173 -> V_269 ;
} else if ( T_1 -> V_191 &&
V_26 -> V_192 == V_254 &&
F_87 ( V_26 , V_173 -> V_78 ) &&
V_26 -> V_151 == - 1 ) {
F_9 ( L_34 V_111 L_35 V_111 L_15 ,
V_173 -> V_196 , V_173 -> V_269 ) ;
V_26 -> V_196 = V_173 -> V_269 ;
} else if ( V_173 -> V_196 > V_26 -> V_196 ) {
V_26 -> V_196 = V_173 -> V_196 ;
}
if ( ! T_1 -> V_123 && V_26 -> V_196 >= * V_196 ) {
* V_196 = V_26 -> V_196 ;
return 0 ;
}
}
return 0 ;
}
static inline int F_97 ( struct V_1 * T_1 )
{
if ( T_1 -> V_39 . V_270 ) {
T_1 -> V_39 . V_270 = false ;
return F_68 ( T_1 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * T_1 , T_4 V_196 )
{
unsigned int V_33 ;
T_4 V_271 ;
int V_8 ;
while ( 1 ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
if ( ! T_1 -> V_198 . V_272 )
return 0 ;
if ( T_1 -> V_198 . V_273 [ 0 ] . V_274 >= V_196 )
return 0 ;
V_33 = T_1 -> V_198 . V_273 [ 0 ] . V_33 ;
V_28 = & T_1 -> V_39 . V_40 [ V_33 ] ;
V_26 = V_28 -> V_170 ;
F_9 ( L_36 V_111 L_37 V_111 L_15 ,
V_33 , T_1 -> V_198 . V_273 [ 0 ] . V_274 ,
V_196 ) ;
F_99 ( & T_1 -> V_198 ) ;
if ( T_1 -> V_198 . V_272 ) {
V_271 = T_1 -> V_198 . V_273 [ 0 ] . V_274 + 1 ;
if ( V_271 > V_196 )
V_271 = V_196 ;
} else {
V_271 = V_196 ;
}
F_60 ( T_1 , V_28 ) ;
V_8 = F_95 ( V_26 , & V_271 ) ;
if ( V_8 < 0 ) {
F_67 ( & T_1 -> V_198 , V_33 , V_271 ) ;
return V_8 ;
}
if ( ! V_8 ) {
V_8 = F_67 ( & T_1 -> V_198 , V_33 , V_271 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_26 -> V_190 = false ;
}
}
return 0 ;
}
static int F_100 ( struct V_1 * T_1 , T_8 V_32 ,
T_4 V_275 )
{
struct V_276 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
T_4 V_271 = 0 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_199 ; V_10 ++ ) {
struct V_27 * V_28 = & T_1 -> V_39 . V_40 [ V_10 ] ;
struct V_25 * V_26 = V_28 -> V_170 ;
if ( V_26 && ( V_32 == - 1 || V_26 -> V_32 == V_32 ) ) {
V_26 -> time = V_275 ;
F_60 ( T_1 , V_28 ) ;
F_95 ( V_26 , & V_271 ) ;
}
}
return 0 ;
}
static int F_101 ( struct V_1 * T_1 , struct V_214 * V_215 )
{
return F_82 ( T_1 , V_277 , V_215 -> V_30 ,
V_215 -> V_31 , V_215 -> V_32 , 0 ) ;
}
static struct V_25 * F_102 ( struct V_1 * T_1 , int V_30 )
{
unsigned V_10 , V_278 ;
if ( V_30 < 0 || ! T_1 -> V_39 . V_199 )
return NULL ;
if ( ( unsigned ) V_30 >= T_1 -> V_39 . V_199 )
V_10 = T_1 -> V_39 . V_199 - 1 ;
else
V_10 = V_30 ;
if ( T_1 -> V_39 . V_40 [ V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_170 ;
for ( V_278 = 0 ; V_10 > 0 ; V_278 ++ ) {
if ( T_1 -> V_39 . V_40 [ -- V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_170 ;
}
for (; V_278 < T_1 -> V_39 . V_199 ; V_278 ++ ) {
if ( T_1 -> V_39 . V_40 [ V_278 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_278 ] . V_170 ;
}
return NULL ;
}
static int F_103 ( struct V_1 * T_1 , int V_30 , T_8 V_32 ,
T_4 V_196 )
{
struct V_25 * V_26 ;
int V_70 ;
if ( ! T_1 -> V_191 )
return 1 ;
V_26 = F_102 ( T_1 , V_30 ) ;
if ( ! V_26 )
return 1 ;
switch ( V_26 -> V_192 ) {
case V_257 :
V_26 -> V_151 = - 1 ;
break;
case V_254 :
case V_256 :
V_26 -> V_151 = V_32 ;
V_26 -> V_192 = V_255 ;
return 0 ;
case V_193 :
if ( ! V_26 -> V_190 ) {
V_26 -> V_196 = F_104 ( V_196 ,
& T_1 -> V_131 ) ;
V_70 = F_67 ( & T_1 -> V_198 , V_26 -> V_33 ,
V_26 -> V_196 ) ;
if ( V_70 )
return V_70 ;
V_26 -> V_190 = true ;
}
V_26 -> V_192 = V_256 ;
break;
case V_255 :
V_26 -> V_151 = V_32 ;
F_9 ( L_38 , V_30 ) ;
break;
default:
break;
}
return 1 ;
}
static int F_105 ( struct V_1 * T_1 ,
struct V_214 * V_215 )
{
struct V_117 * V_118 ;
T_8 V_32 ;
int V_30 , V_8 ;
V_118 = F_106 ( T_1 -> V_43 -> V_279 , V_215 -> V_226 ) ;
if ( V_118 != T_1 -> V_280 )
return 0 ;
V_32 = F_107 ( V_118 , V_215 , L_39 ) ;
V_30 = V_215 -> V_30 ;
F_9 ( L_40 V_281 L_41 V_111 L_15 ,
V_30 , V_32 , V_215 -> time , F_104 ( V_215 -> time ,
& T_1 -> V_131 ) ) ;
V_8 = F_103 ( T_1 , V_30 , V_32 , V_215 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_86 ( T_1 -> V_35 , V_30 , - 1 , V_32 ) ;
}
static int F_108 ( struct V_1 * T_1 , union V_212 * V_213 ,
struct V_214 * V_215 )
{
bool V_102 = V_213 -> V_217 . V_224 & V_282 ;
T_8 V_31 , V_32 ;
int V_30 , V_8 ;
V_30 = V_215 -> V_30 ;
if ( T_1 -> V_171 == 3 ) {
if ( ! V_102 )
return 0 ;
if ( V_213 -> V_217 . type != V_283 ) {
F_78 ( L_42 ) ;
return - V_22 ;
}
V_31 = V_213 -> V_284 . V_285 ;
V_32 = V_213 -> V_284 . V_286 ;
} else {
if ( V_102 )
return 0 ;
V_31 = V_215 -> V_31 ;
V_32 = V_215 -> V_32 ;
}
if ( V_32 == - 1 ) {
F_78 ( L_43 ) ;
return - V_22 ;
}
F_9 ( L_44 V_281 L_41 V_111 L_15 ,
V_30 , V_31 , V_32 , V_215 -> time , F_104 ( V_215 -> time ,
& T_1 -> V_131 ) ) ;
V_8 = F_103 ( T_1 , V_30 , V_32 , V_215 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_86 ( T_1 -> V_35 , V_30 , V_31 , V_32 ) ;
}
static int F_109 ( struct V_1 * T_1 ,
union V_212 * V_213 ,
struct V_214 * V_215 )
{
if ( ! T_1 -> V_266 )
return 0 ;
F_9 ( L_45 V_281 L_41 V_111 L_15 ,
V_215 -> V_30 , V_213 -> V_287 . V_31 ,
V_213 -> V_287 . V_32 , V_215 -> time ,
F_104 ( V_215 -> time , & T_1 -> V_131 ) ) ;
return F_86 ( T_1 -> V_35 , V_215 -> V_30 ,
V_213 -> V_287 . V_31 ,
V_213 -> V_287 . V_32 ) ;
}
static int F_110 ( struct V_288 * V_43 ,
union V_212 * V_213 ,
struct V_214 * V_215 ,
struct V_289 * V_290 )
{
struct V_1 * T_1 = F_111 ( V_43 -> V_291 , struct V_1 ,
V_291 ) ;
T_4 V_196 ;
int V_70 = 0 ;
if ( V_292 )
return 0 ;
if ( ! V_290 -> V_293 ) {
F_78 ( L_46 ) ;
return - V_22 ;
}
if ( V_215 -> time && V_215 -> time != ( T_4 ) - 1 )
V_196 = F_104 ( V_215 -> time , & T_1 -> V_131 ) ;
else
V_196 = 0 ;
if ( V_196 || T_1 -> V_123 ) {
V_70 = F_97 ( T_1 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_123 ) {
if ( V_213 -> V_217 . type == V_294 ) {
V_70 = F_100 ( T_1 ,
V_213 -> V_295 . V_32 ,
V_215 -> time ) ;
}
} else if ( V_196 ) {
V_70 = F_98 ( T_1 , V_196 ) ;
}
if ( V_70 )
return V_70 ;
if ( V_213 -> V_217 . type == V_296 &&
( V_213 -> V_297 . V_174 & V_298 ) &&
T_1 -> V_137 . V_267 ) {
V_70 = F_101 ( T_1 , V_215 ) ;
if ( V_70 )
return V_70 ;
}
if ( T_1 -> V_280 && V_213 -> V_217 . type == V_223 )
V_70 = F_105 ( T_1 , V_215 ) ;
else if ( V_213 -> V_217 . type == V_299 )
V_70 = F_109 ( T_1 , V_213 , V_215 ) ;
else if ( V_213 -> V_217 . type == V_300 ||
V_213 -> V_217 . type == V_283 )
V_70 = F_108 ( T_1 , V_213 , V_215 ) ;
F_9 ( L_47 V_281 L_41 V_111 L_15 ,
F_112 ( V_213 -> V_217 . type ) , V_213 -> V_217 . type ,
V_215 -> V_30 , V_215 -> time , V_196 ) ;
return V_70 ;
}
static int F_113 ( struct V_288 * V_43 , struct V_289 * V_290 )
{
struct V_1 * T_1 = F_111 ( V_43 -> V_291 , struct V_1 ,
V_291 ) ;
int V_8 ;
if ( V_292 )
return 0 ;
if ( ! V_290 -> V_293 )
return - V_22 ;
V_8 = F_97 ( T_1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( T_1 -> V_123 )
return F_100 ( T_1 , - 1 ,
V_301 - 1 ) ;
return F_98 ( T_1 , V_301 ) ;
}
static void F_114 ( struct V_288 * V_43 )
{
struct V_1 * T_1 = F_111 ( V_43 -> V_291 , struct V_1 ,
V_291 ) ;
struct V_276 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_199 ; V_10 ++ ) {
F_58 ( V_39 -> V_40 [ V_10 ] . V_170 ) ;
V_39 -> V_40 [ V_10 ] . V_170 = NULL ;
}
F_115 () ;
F_116 ( V_39 ) ;
}
static void F_117 ( struct V_288 * V_43 )
{
struct V_1 * T_1 = F_111 ( V_43 -> V_291 , struct V_1 ,
V_291 ) ;
F_118 ( & T_1 -> V_198 ) ;
F_114 ( V_43 ) ;
V_43 -> V_291 = NULL ;
F_119 ( T_1 -> V_92 ) ;
F_120 ( & T_1 -> V_158 ) ;
F_57 ( & T_1 -> V_302 ) ;
free ( T_1 ) ;
}
static int F_121 ( struct V_288 * V_43 ,
union V_212 * V_213 ,
struct V_289 * V_290 V_2 )
{
struct V_1 * T_1 = F_111 ( V_43 -> V_291 , struct V_1 ,
V_291 ) ;
if ( T_1 -> V_50 )
return 0 ;
if ( ! T_1 -> V_303 ) {
struct V_15 * V_29 ;
T_3 V_304 ;
int V_42 = F_16 ( V_43 -> V_44 ) ;
int V_70 ;
if ( F_122 ( V_43 -> V_44 ) ) {
V_304 = 0 ;
} else {
V_304 = F_123 ( V_42 , 0 , V_305 ) ;
if ( V_304 == - 1 )
return - V_306 ;
}
V_70 = F_124 ( & T_1 -> V_39 , V_43 , V_213 ,
V_304 , & V_29 ) ;
if ( V_70 )
return V_70 ;
if ( V_292 ) {
if ( F_17 ( V_29 , V_42 ) ) {
F_5 ( T_1 , V_29 -> V_19 ,
V_29 -> V_20 ) ;
F_125 ( V_29 ) ;
}
}
}
return 0 ;
}
static int F_126 ( struct V_289 * V_290 ,
union V_212 * V_213 ,
struct V_214 * V_215 V_2 ,
struct V_35 * V_35 V_2 )
{
struct V_307 * V_307 =
F_111 ( V_290 , struct V_307 , V_308 ) ;
return F_77 ( V_307 -> V_43 , V_213 ,
NULL ) ;
}
static int F_127 ( struct V_288 * V_43 ,
struct V_113 * V_114 , T_4 V_226 )
{
struct V_307 V_307 ;
memset ( & V_307 , 0 , sizeof( struct V_307 ) ) ;
V_307 . V_43 = V_43 ;
return F_128 ( & V_307 . V_308 , V_114 , 1 ,
& V_226 , F_126 ) ;
}
static int F_129 ( struct V_1 * T_1 ,
struct V_288 * V_43 )
{
struct V_309 * V_279 = V_43 -> V_279 ;
struct V_117 * V_118 ;
struct V_113 V_114 ;
bool V_310 = false ;
T_4 V_226 ;
int V_70 ;
F_47 (evlist, evsel) {
if ( V_118 -> V_114 . type == T_1 -> V_116 && V_118 -> V_311 ) {
V_310 = true ;
break;
}
}
if ( ! V_310 ) {
F_130 ( L_48 ) ;
return 0 ;
}
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_20 = sizeof( struct V_113 ) ;
V_114 . type = V_312 ;
V_114 . V_126 = V_118 -> V_114 . V_126 & V_313 ;
V_114 . V_126 |= V_314 | V_315 |
V_316 ;
if ( T_1 -> V_123 )
V_114 . V_126 &= ~ ( T_4 ) V_127 ;
else
V_114 . V_126 |= V_127 ;
if ( ! T_1 -> V_266 )
V_114 . V_126 &= ~ ( T_4 ) V_317 ;
V_114 . V_318 = V_118 -> V_114 . V_318 ;
V_114 . V_119 = V_118 -> V_114 . V_119 ;
V_114 . V_319 = V_118 -> V_114 . V_319 ;
V_114 . V_320 = V_118 -> V_114 . V_320 ;
V_114 . V_321 = V_118 -> V_114 . V_321 ;
V_114 . V_322 = V_118 -> V_114 . V_322 ;
V_114 . V_323 = V_118 -> V_114 . V_323 ;
V_226 = V_118 -> V_226 [ 0 ] + 1000000000 ;
if ( ! V_226 )
V_226 = 1 ;
if ( T_1 -> V_137 . V_161 ) {
V_114 . V_115 = V_324 ;
if ( T_1 -> V_137 . V_163 == V_168 )
V_114 . V_325 =
F_53 ( T_1 , T_1 -> V_137 . V_162 ) ;
else
V_114 . V_325 = T_1 -> V_137 . V_162 ;
T_1 -> V_326 = V_114 . V_325 ;
if ( T_1 -> V_137 . V_138 )
V_114 . V_126 |= V_327 ;
if ( T_1 -> V_137 . V_144 )
V_114 . V_126 |= V_328 ;
F_130 ( L_49 V_281 L_50 V_111 L_15 ,
V_226 , ( T_4 ) V_114 . V_126 ) ;
V_70 = F_127 ( V_43 , & V_114 , V_226 ) ;
if ( V_70 ) {
F_78 ( L_51 ,
V_329 ) ;
return V_70 ;
}
T_1 -> V_247 = true ;
T_1 -> V_237 = V_114 . V_126 ;
T_1 -> V_234 = V_226 ;
V_226 += 1 ;
}
if ( T_1 -> V_137 . V_330 ) {
V_114 . V_115 = V_324 ;
V_114 . V_325 = 1 ;
if ( T_1 -> V_137 . V_138 )
V_114 . V_126 |= V_327 ;
if ( T_1 -> V_137 . V_144 )
V_114 . V_126 |= V_328 ;
F_130 ( L_52 V_281 L_50 V_111 L_15 ,
V_226 , ( T_4 ) V_114 . V_126 ) ;
V_70 = F_127 ( V_43 , & V_114 , V_226 ) ;
if ( V_70 ) {
F_78 ( L_53 ,
V_329 ) ;
return V_70 ;
}
T_1 -> V_249 = true ;
T_1 -> V_238 = V_226 ;
V_226 += 1 ;
F_47 (evlist, evsel) {
if ( V_118 -> V_226 && V_118 -> V_226 [ 0 ] == T_1 -> V_238 ) {
if ( V_118 -> V_264 )
F_57 ( & V_118 -> V_264 ) ;
V_118 -> V_264 = F_131 ( L_54 ) ;
break;
}
}
}
if ( T_1 -> V_137 . V_331 ) {
V_114 . V_115 = V_332 ;
V_114 . V_325 = 1 ;
V_114 . V_126 |= V_333 ;
V_114 . V_126 &= ~ ( T_4 ) V_327 ;
V_114 . V_126 &= ~ ( T_4 ) V_328 ;
F_130 ( L_55 V_281 L_50 V_111 L_15 ,
V_226 , ( T_4 ) V_114 . V_126 ) ;
V_70 = F_127 ( V_43 , & V_114 , V_226 ) ;
if ( V_70 ) {
F_78 ( L_56 ,
V_329 ) ;
return V_70 ;
}
T_1 -> V_253 = true ;
T_1 -> V_232 = V_114 . V_126 ;
T_1 -> V_227 = V_226 ;
}
T_1 -> V_233 = V_118 -> V_334 ;
return 0 ;
}
static struct V_117 * F_132 ( struct V_309 * V_279 )
{
struct V_117 * V_118 ;
F_133 (evlist, evsel) {
const char * V_264 = F_134 ( V_118 ) ;
if ( ! strcmp ( V_264 , L_57 ) )
return V_118 ;
}
return NULL ;
}
static bool F_135 ( struct V_309 * V_279 )
{
struct V_117 * V_118 ;
F_47 (evlist, evsel) {
if ( V_118 -> V_114 . V_284 )
return true ;
}
return false ;
}
static int F_136 ( const char * V_55 , const char * V_56 , void * V_19 )
{
struct V_1 * T_1 = V_19 ;
if ( ! strcmp ( V_55 , L_58 ) )
T_1 -> V_211 = F_137 ( V_55 , V_56 ) ;
return 0 ;
}
static void F_138 ( T_4 * V_335 , int V_18 , int V_336 )
{
int V_10 ;
if ( ! V_292 )
return;
for ( V_10 = V_18 ; V_10 <= V_336 ; V_10 ++ )
fprintf ( stdout , V_337 [ V_10 ] , V_335 [ V_10 ] ) ;
}
static void F_139 ( const char * V_264 , const char * V_338 )
{
if ( ! V_292 )
return;
fprintf ( stdout , L_59 , V_264 , V_338 ? V_338 : L_60 ) ;
}
static bool F_140 ( struct V_339 * V_340 , int V_7 )
{
return V_340 -> V_217 . V_20 >=
sizeof( struct V_339 ) + ( sizeof( T_4 ) * ( V_7 + 1 ) ) ;
}
int F_141 ( union V_212 * V_213 ,
struct V_288 * V_43 )
{
struct V_339 * V_340 = & V_213 -> V_340 ;
T_2 V_341 = sizeof( T_4 ) * V_342 ;
struct V_1 * T_1 ;
void * V_343 ;
T_4 * V_344 ;
int V_70 ;
if ( V_340 -> V_217 . V_20 < sizeof( struct V_339 ) +
V_341 )
return - V_22 ;
T_1 = F_55 ( sizeof( struct V_1 ) ) ;
if ( ! T_1 )
return - V_45 ;
F_142 ( & T_1 -> V_158 ) ;
F_20 ( F_136 , T_1 ) ;
V_70 = F_143 ( & T_1 -> V_39 ) ;
if ( V_70 )
goto V_345;
F_144 ( V_346 ) ;
T_1 -> V_43 = V_43 ;
T_1 -> V_35 = & V_43 -> V_347 . V_348 ;
T_1 -> V_349 = V_340 -> type ;
T_1 -> V_116 = V_340 -> V_170 [ V_350 ] ;
T_1 -> V_131 . V_133 = V_340 -> V_170 [ V_351 ] ;
T_1 -> V_131 . V_132 = V_340 -> V_170 [ V_352 ] ;
T_1 -> V_131 . V_353 = V_340 -> V_170 [ V_354 ] ;
T_1 -> V_125 = V_340 -> V_170 [ V_355 ] ;
T_1 -> V_124 = V_340 -> V_170 [ V_356 ] ;
T_1 -> V_120 = V_340 -> V_170 [ V_357 ] ;
T_1 -> V_171 = V_340 -> V_170 [ V_358 ] ;
T_1 -> V_46 = V_340 -> V_170 [ V_359 ] ;
T_1 -> V_266 = V_340 -> V_170 [ V_342 ] ;
F_138 ( & V_340 -> V_170 [ 0 ] , V_350 ,
V_342 ) ;
if ( F_140 ( V_340 , V_360 ) ) {
T_1 -> V_361 = V_340 -> V_170 [ V_362 ] ;
T_1 -> V_122 = V_340 -> V_170 [ V_363 ] ;
T_1 -> V_156 = V_340 -> V_170 [ V_364 ] ;
T_1 -> V_157 = V_340 -> V_170 [ V_365 ] ;
T_1 -> V_366 = V_340 -> V_170 [ V_360 ] ;
F_138 ( & V_340 -> V_170 [ 0 ] , V_362 ,
V_360 ) ;
}
if ( F_140 ( V_340 , V_367 ) ) {
T_1 -> V_154 =
V_340 -> V_170 [ V_367 ] ;
F_138 ( & V_340 -> V_170 [ 0 ] ,
V_367 ,
V_367 ) ;
}
V_344 = & V_340 -> V_170 [ V_368 ] + 1 ;
V_343 = ( void * ) V_344 + V_340 -> V_217 . V_20 ;
if ( F_140 ( V_340 , V_368 ) ) {
T_2 V_4 ;
V_4 = V_340 -> V_170 [ V_368 ] ;
F_138 ( & V_340 -> V_170 [ 0 ] ,
V_368 ,
V_368 ) ;
if ( V_4 ) {
const char * V_302 = ( const char * ) V_344 ;
V_4 = F_145 ( V_4 + 1 , 8 ) ;
V_344 += V_4 >> 3 ;
if ( ( void * ) V_344 > V_343 ) {
F_78 ( L_61 , V_329 ) ;
V_70 = - V_22 ;
goto V_369;
}
T_1 -> V_302 = F_146 ( V_302 , V_4 ) ;
if ( ! T_1 -> V_302 ) {
V_70 = - V_45 ;
goto V_369;
}
if ( V_43 -> V_217 . V_334 )
F_147 ( T_1 -> V_302 , V_4 ) ;
if ( T_1 -> V_302 [ V_4 - 1 ] ) {
F_78 ( L_62 , V_329 ) ;
V_70 = - V_22 ;
goto V_369;
}
V_70 = F_148 ( & T_1 -> V_158 ,
V_302 ) ;
if ( V_70 )
goto V_369;
}
F_139 ( L_63 , T_1 -> V_302 ) ;
}
T_1 -> V_123 = F_50 ( T_1 ) ;
T_1 -> V_21 = F_52 ( T_1 ) ;
T_1 -> V_50 = false ;
T_1 -> V_268 = ! T_1 -> V_123 ;
T_1 -> V_92 = F_149 ( 999999999 , 999999999 ) ;
if ( ! T_1 -> V_92 ) {
V_70 = - V_45 ;
goto V_369;
}
F_150 ( & T_1 -> V_92 -> V_370 ) ;
V_70 = F_151 ( T_1 -> V_92 , L_64 , 0 ) ;
if ( V_70 )
goto V_371;
if ( F_152 ( T_1 -> V_92 , T_1 -> V_35 ) ) {
V_70 = - V_45 ;
goto V_371;
}
T_1 -> V_291 . V_372 = F_110 ;
T_1 -> V_291 . V_373 = F_121 ;
T_1 -> V_291 . V_374 = F_113 ;
T_1 -> V_291 . V_375 = F_114 ;
T_1 -> V_291 . free = F_117 ;
V_43 -> V_291 = & T_1 -> V_291 ;
if ( V_292 )
return 0 ;
if ( T_1 -> V_171 == 1 ) {
T_1 -> V_280 = F_132 ( V_43 -> V_279 ) ;
if ( ! T_1 -> V_280 ) {
F_78 ( L_65 , V_329 ) ;
V_70 = - V_22 ;
goto V_371;
}
} else if ( T_1 -> V_171 == 2 &&
! F_135 ( V_43 -> V_279 ) ) {
F_78 ( L_66 , V_329 ) ;
V_70 = - V_22 ;
goto V_371;
}
if ( V_43 -> V_376 && V_43 -> V_376 -> V_377 ) {
T_1 -> V_137 = * V_43 -> V_376 ;
} else {
F_153 ( & T_1 -> V_137 ) ;
if ( V_378 != - 1 ) {
T_1 -> V_137 . V_331 = false ;
T_1 -> V_137 . V_138 = true ;
}
if ( V_43 -> V_376 )
T_1 -> V_137 . V_252 =
V_43 -> V_376 -> V_252 ;
}
if ( T_1 -> V_137 . log )
F_154 () ;
if ( T_1 -> V_131 . V_132 ) {
T_4 V_379 = F_53 ( T_1 , 1000000000 ) ;
if ( ! T_1 -> V_154 )
T_1 -> V_154 =
( V_379 + 50000000 ) / 100000000 ;
F_9 ( L_67 V_281 L_15 , V_379 ) ;
F_9 ( L_68 ,
T_1 -> V_154 ) ;
}
if ( T_1 -> V_137 . V_380 )
T_1 -> V_220 |= V_179 | V_180 |
V_182 ;
if ( T_1 -> V_137 . V_381 )
T_1 -> V_220 |= V_382 |
V_186 ;
if ( T_1 -> V_137 . V_138 && ! V_383 . V_384 ) {
V_383 . V_384 = true ;
if ( F_155 ( & V_385 ) < 0 ) {
V_383 . V_384 = false ;
T_1 -> V_137 . V_138 = false ;
}
}
V_70 = F_129 ( T_1 , V_43 ) ;
if ( V_70 )
goto V_371;
V_70 = F_156 ( & T_1 -> V_39 , V_43 ) ;
if ( V_70 )
goto V_371;
if ( T_1 -> V_39 . V_386 )
T_1 -> V_303 = true ;
if ( T_1 -> V_123 )
F_157 ( L_69 ) ;
return 0 ;
V_371:
F_10 ( T_1 -> V_92 ) ;
V_369:
F_115 () ;
F_116 ( & T_1 -> V_39 ) ;
V_43 -> V_291 = NULL ;
V_345:
F_120 ( & T_1 -> V_158 ) ;
F_57 ( & T_1 -> V_302 ) ;
free ( T_1 ) ;
return V_70 ;
}
