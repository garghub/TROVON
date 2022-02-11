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
V_29 = F_14 ( V_28 , V_29 ) ;
if ( ! V_29 ) {
if ( V_37 )
F_15 ( V_37 ) ;
V_17 -> V_4 = 0 ;
return 0 ;
}
V_26 -> V_29 = V_29 ;
if ( ! V_29 -> V_19 ) {
int V_41 = F_16 ( V_26 -> T_1 -> V_42 -> V_43 ) ;
V_29 -> V_19 = F_17 ( V_29 , V_41 ) ;
if ( ! V_29 -> V_19 )
return - V_44 ;
}
if ( V_26 -> T_1 -> V_45 && ! V_29 -> V_46 && V_37 &&
F_6 ( V_26 -> T_1 , V_37 , V_29 ) )
return - V_44 ;
if ( V_37 )
F_15 ( V_37 ) ;
if ( V_29 -> V_24 ) {
V_17 -> V_4 = V_29 -> V_23 ;
V_17 -> V_3 = V_29 -> V_24 ;
} else {
V_17 -> V_4 = V_29 -> V_20 ;
V_17 -> V_3 = V_29 -> V_19 ;
}
V_17 -> V_47 = V_29 -> V_48 ;
if ( ! V_37 || V_26 -> T_1 -> V_49 || ( V_26 -> T_1 -> V_45 &&
! V_29 -> V_46 ) ) {
V_17 -> V_46 = false ;
V_17 -> V_50 = V_29 -> V_51 + 1 ;
} else {
V_17 -> V_46 = true ;
}
if ( V_26 -> V_52 && ( V_26 -> V_31 != V_29 -> V_31 ||
V_26 -> V_32 != V_29 -> V_32 ) )
F_8 ( V_26 , V_28 , V_29 ) ;
if ( V_26 -> V_53 )
V_26 -> V_38 = true ;
if ( ! V_17 -> V_4 )
return F_13 ( V_17 , V_19 ) ;
return 0 ;
}
static int F_18 ( const char * V_54 , const char * V_55 , void * V_19 )
{
int * V_56 = V_19 ;
long V_57 ;
if ( ! strcmp ( V_54 , L_10 ) ) {
V_57 = strtol ( V_55 , NULL , 0 ) ;
if ( V_57 > 0 && V_57 <= V_58 )
* V_56 = V_57 ;
}
return 0 ;
}
static int F_19 ( void )
{
static int V_56 ;
if ( V_56 )
return V_56 ;
F_20 ( F_18 , & V_56 ) ;
if ( ! V_56 )
V_56 = 64 ;
return V_56 ;
}
static unsigned int F_21 ( struct V_59 * V_59 ,
struct V_35 * V_35 )
{
T_3 V_20 ;
V_20 = F_22 ( V_59 , V_35 ) ;
V_20 /= F_19 () ;
if ( V_20 < 1000 )
return 10 ;
if ( V_20 > ( 1 << 21 ) )
return 21 ;
return 32 - F_23 ( V_20 ) ;
}
static struct V_60 * F_24 ( struct V_59 * V_59 ,
struct V_35 * V_35 )
{
struct V_60 * V_61 ;
unsigned int V_62 ;
if ( V_59 -> V_60 )
return V_59 -> V_60 ;
V_62 = F_21 ( V_59 , V_35 ) ;
V_61 = F_25 ( V_62 , sizeof( struct V_63 ) , 200 ) ;
V_59 -> V_60 = V_61 ;
return V_61 ;
}
static int F_26 ( struct V_59 * V_59 , struct V_35 * V_35 ,
T_4 V_64 , T_4 V_65 , T_4 V_66 ,
struct V_67 * V_67 )
{
struct V_60 * V_61 = F_24 ( V_59 , V_35 ) ;
struct V_63 * V_68 ;
int V_69 ;
if ( ! V_61 )
return - V_44 ;
V_68 = F_27 ( V_61 ) ;
if ( ! V_68 )
return - V_44 ;
V_68 -> V_65 = V_65 ;
V_68 -> V_66 = V_66 ;
V_68 -> V_70 = V_67 -> V_70 ;
V_68 -> V_71 = V_67 -> V_71 ;
V_68 -> V_72 = V_67 -> V_72 ;
V_68 -> V_73 = V_67 -> V_73 ;
V_69 = F_28 ( V_61 , V_64 , & V_68 -> V_74 ) ;
if ( V_69 )
F_29 ( V_61 , V_68 ) ;
return V_69 ;
}
static struct V_63 *
F_30 ( struct V_59 * V_59 , struct V_35 * V_35 , T_4 V_64 )
{
struct V_60 * V_61 = F_24 ( V_59 , V_35 ) ;
if ( ! V_61 )
return NULL ;
return F_31 ( V_59 -> V_60 , V_64 ) ;
}
static int F_32 ( struct V_67 * V_67 ,
T_5 * V_75 , T_5 * V_76 ,
T_5 V_77 , T_5 V_78 ,
void * V_19 )
{
struct V_25 * V_26 = V_19 ;
struct V_35 * V_35 = V_26 -> T_1 -> V_35 ;
struct V_34 * V_34 ;
struct V_79 V_80 ;
unsigned char V_3 [ 1024 ] ;
T_2 V_81 ;
T_6 V_4 ;
int V_82 ;
T_7 V_83 ;
T_4 V_64 , V_84 , V_85 ;
T_4 V_65 = 0 ;
bool V_86 = true ;
if ( V_77 && * V_76 == V_77 )
goto V_87;
V_81 = F_33 () ;
if ( * V_76 >= V_26 -> T_1 -> V_88 )
V_83 = V_89 ;
else
V_83 = V_90 ;
V_34 = V_26 -> V_34 ;
if ( ! V_34 ) {
if ( V_83 != V_89 )
return - V_22 ;
V_34 = V_26 -> T_1 -> V_91 ;
}
while ( 1 ) {
F_34 ( V_34 , V_83 , V_92 , * V_76 , & V_80 ) ;
if ( ! V_80 . V_93 || ! V_80 . V_93 -> V_59 )
return - V_22 ;
if ( V_80 . V_93 -> V_59 -> V_19 . V_94 == V_95 &&
F_35 ( V_80 . V_93 -> V_59 ,
V_96 ) )
return - V_97 ;
V_64 = V_80 . V_93 -> V_98 ( V_80 . V_93 , * V_76 ) ;
if ( ! V_77 && V_86 ) {
struct V_63 * V_68 ;
V_68 = F_30 ( V_80 . V_93 -> V_59 , V_35 , V_64 ) ;
if ( V_68 &&
( ! V_78 || V_68 -> V_65 <= V_78 ) ) {
* V_75 = V_68 -> V_65 ;
* V_76 += V_68 -> V_66 ;
V_67 -> V_70 = V_68 -> V_70 ;
V_67 -> V_71 = V_68 -> V_71 ;
V_67 -> V_72 = V_68 -> V_72 ;
V_67 -> V_73 = V_68 -> V_73 ;
F_36 ( V_67 , * V_76 ) ;
return 0 ;
}
}
V_84 = V_64 ;
V_85 = * V_76 ;
F_37 ( V_80 . V_93 , V_35 -> V_99 ) ;
V_82 = V_80 . V_93 -> V_59 -> V_100 ;
while ( 1 ) {
V_4 = F_38 ( V_80 . V_93 -> V_59 , V_35 ,
V_64 , V_3 , V_81 ) ;
if ( V_4 <= 0 )
return - V_22 ;
if ( F_39 ( V_3 , V_4 , V_82 , V_67 ) )
return - V_22 ;
F_40 ( V_67 , * V_76 ) ;
V_65 += 1 ;
if ( V_67 -> V_71 != V_101 )
goto V_102;
if ( V_78 && V_65 >= V_78 )
goto V_87;
* V_76 += V_67 -> V_72 ;
if ( V_77 && * V_76 == V_77 )
goto V_87;
if ( * V_76 >= V_80 . V_93 -> V_103 )
break;
V_64 += V_67 -> V_72 ;
}
V_86 = false ;
}
V_102:
* V_75 = V_65 ;
if ( ! V_86 )
goto V_87;
if ( V_77 ) {
struct V_63 * V_68 ;
V_68 = F_30 ( V_80 . V_93 -> V_59 , V_35 , V_84 ) ;
if ( V_68 )
return 0 ;
}
F_26 ( V_80 . V_93 -> V_59 , V_35 , V_84 , V_65 ,
* V_76 - V_85 , V_67 ) ;
return 0 ;
V_87:
* V_75 = V_65 ;
return 0 ;
}
static bool F_41 ( struct V_1 * T_1 ,
struct V_104 * V_105 , T_4 * V_106 )
{
if ( V_105 -> type == T_1 -> V_107 ) {
if ( V_106 )
* V_106 = V_105 -> V_106 ;
return true ;
}
return false ;
}
static bool F_42 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
F_43 (pt->session->evlist, evsel) {
if ( F_41 ( T_1 , & V_109 -> V_105 , NULL ) &&
! V_109 -> V_105 . V_110 )
return false ;
}
return true ;
}
static bool F_44 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
T_4 V_106 ;
if ( ! T_1 -> V_111 )
return true ;
F_43 (pt->session->evlist, evsel) {
if ( F_41 ( T_1 , & V_109 -> V_105 , & V_106 ) &&
( V_106 & T_1 -> V_111 ) )
return false ;
}
return true ;
}
static unsigned int F_45 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
unsigned int V_112 ;
T_4 V_106 ;
if ( ! T_1 -> V_113 )
return 0 ;
for ( V_112 = 0 , V_106 = T_1 -> V_113 ; ! ( V_106 & 1 ) ; V_112 ++ )
V_106 >>= 1 ;
F_43 (pt->session->evlist, evsel) {
if ( F_41 ( T_1 , & V_109 -> V_105 , & V_106 ) )
return ( V_106 & T_1 -> V_113 ) >> V_112 ;
}
return 0 ;
}
static bool F_46 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
bool V_114 = true ;
T_4 V_106 ;
if ( ! T_1 -> V_115 || ! T_1 -> V_116 )
return true ;
F_43 (pt->session->evlist, evsel) {
if ( ! ( V_109 -> V_105 . V_117 & V_118 ) )
return true ;
if ( F_41 ( T_1 , & V_109 -> V_105 , & V_106 ) ) {
if ( V_106 & T_1 -> V_115 )
V_114 = false ;
else
return true ;
}
}
return V_114 ;
}
static bool F_47 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
F_43 (pt->session->evlist, evsel) {
if ( F_41 ( T_1 , & V_109 -> V_105 , NULL ) &&
! V_109 -> V_105 . V_110 )
return true ;
}
return false ;
}
static bool F_48 ( struct V_1 * T_1 )
{
struct V_108 * V_109 ;
bool V_21 = false ;
T_4 V_106 ;
if ( ! T_1 -> V_115 )
return false ;
F_43 (pt->session->evlist, evsel) {
if ( F_41 ( T_1 , & V_109 -> V_105 , & V_106 ) ) {
if ( V_106 & T_1 -> V_115 )
V_21 = true ;
else
return false ;
}
}
return V_21 ;
}
static T_4 F_49 ( const struct V_1 * T_1 , T_4 V_119 )
{
T_4 V_120 , V_121 ;
V_120 = V_119 / T_1 -> V_122 . V_123 ;
V_121 = V_119 % T_1 -> V_122 . V_123 ;
return ( V_120 << T_1 -> V_122 . V_124 ) + ( V_121 << T_1 -> V_122 . V_124 ) /
T_1 -> V_122 . V_123 ;
}
static struct V_25 * F_50 ( struct V_1 * T_1 ,
unsigned int V_33 )
{
struct V_125 V_126 = { . V_127 = 0 , } ;
struct V_25 * V_26 ;
V_26 = F_51 ( sizeof( struct V_25 ) ) ;
if ( ! V_26 )
return NULL ;
if ( T_1 -> V_128 . V_129 ) {
T_2 V_130 = sizeof( struct V_131 ) ;
V_130 += T_1 -> V_128 . V_132 * sizeof( T_4 ) ;
V_26 -> V_133 = F_51 ( V_130 ) ;
if ( ! V_26 -> V_133 )
goto V_134;
}
V_26 -> V_135 = malloc ( V_136 ) ;
if ( ! V_26 -> V_135 )
goto V_134;
V_26 -> T_1 = T_1 ;
V_26 -> V_33 = V_33 ;
V_26 -> V_110 = F_42 ( T_1 ) ;
V_26 -> V_31 = - 1 ;
V_26 -> V_32 = - 1 ;
V_26 -> V_30 = - 1 ;
V_26 -> V_137 = - 1 ;
V_126 . V_127 = F_13 ;
V_126 . V_138 = F_32 ;
V_126 . V_19 = V_26 ;
V_126 . V_139 = F_44 ( T_1 ) ;
V_126 . V_140 = T_1 -> V_140 ;
V_126 . V_141 = F_45 ( T_1 ) ;
V_126 . V_142 = T_1 -> V_142 ;
V_126 . V_143 = T_1 -> V_143 ;
if ( T_1 -> V_128 . V_144 ) {
if ( T_1 -> V_128 . V_145 ) {
switch ( T_1 -> V_128 . V_146 ) {
case V_147 :
V_126 . V_146 =
V_148 ;
V_126 . V_145 = T_1 -> V_128 . V_145 ;
break;
case V_149 :
V_126 . V_146 = V_150 ;
V_126 . V_145 = T_1 -> V_128 . V_145 ;
break;
case V_151 :
V_126 . V_146 = V_150 ;
V_126 . V_145 = F_49 ( T_1 ,
T_1 -> V_128 . V_145 ) ;
break;
default:
break;
}
}
if ( ! V_126 . V_145 ) {
V_126 . V_146 = V_148 ;
V_126 . V_145 = 1000 ;
}
}
V_26 -> V_152 = F_52 ( & V_126 ) ;
if ( ! V_26 -> V_152 )
goto V_134;
return V_26 ;
V_134:
F_53 ( & V_26 -> V_135 ) ;
F_53 ( & V_26 -> V_133 ) ;
free ( V_26 ) ;
return NULL ;
}
static void F_54 ( void * V_153 )
{
struct V_25 * V_26 = V_153 ;
if ( ! V_26 )
return;
F_10 ( V_26 -> V_34 ) ;
F_55 ( V_26 -> V_152 ) ;
F_53 ( & V_26 -> V_135 ) ;
F_53 ( & V_26 -> V_133 ) ;
free ( V_26 ) ;
}
static void F_56 ( struct V_1 * T_1 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_153 ;
if ( V_28 -> V_32 == - 1 || T_1 -> V_154 ) {
V_26 -> V_32 = F_57 ( T_1 -> V_35 , V_26 -> V_30 ) ;
F_10 ( V_26 -> V_34 ) ;
}
if ( ! V_26 -> V_34 && V_26 -> V_32 != - 1 )
V_26 -> V_34 = F_12 ( T_1 -> V_35 , - 1 , V_26 -> V_32 ) ;
if ( V_26 -> V_34 ) {
V_26 -> V_31 = V_26 -> V_34 -> V_155 ;
if ( V_28 -> V_30 == - 1 )
V_26 -> V_30 = V_26 -> V_34 -> V_30 ;
}
}
static void F_58 ( struct V_25 * V_26 )
{
if ( V_26 -> V_156 -> V_157 & V_158 ) {
V_26 -> V_157 = V_159 | V_160 ;
} else if ( V_26 -> V_156 -> V_157 & V_161 ) {
if ( V_26 -> V_156 -> V_77 )
V_26 -> V_157 = V_159 | V_162 |
V_163 |
V_164 ;
else
V_26 -> V_157 = V_159 |
V_165 ;
V_26 -> V_166 = 0 ;
} else {
if ( V_26 -> V_156 -> V_167 )
V_26 -> V_157 = F_59 ( V_26 -> V_156 -> V_168 ) ;
else
V_26 -> V_157 = V_159 |
V_169 ;
if ( V_26 -> V_156 -> V_157 & V_170 )
V_26 -> V_157 |= V_171 ;
V_26 -> V_166 = V_26 -> V_156 -> V_166 ;
}
}
static int F_60 ( struct V_1 * T_1 ,
struct V_27 * V_28 ,
unsigned int V_33 )
{
struct V_25 * V_26 = V_28 -> V_153 ;
if ( F_61 ( & V_28 -> V_172 ) )
return 0 ;
if ( ! V_26 ) {
V_26 = F_50 ( T_1 , V_33 ) ;
if ( ! V_26 )
return - V_44 ;
V_28 -> V_153 = V_26 ;
if ( V_28 -> V_30 != - 1 )
V_26 -> V_30 = V_28 -> V_30 ;
V_26 -> V_32 = V_28 -> V_32 ;
if ( T_1 -> V_49 ) {
if ( T_1 -> V_114 )
V_26 -> V_53 = true ;
if ( T_1 -> V_114 || ! T_1 -> V_154 )
V_26 -> V_52 = true ;
}
}
if ( ! V_26 -> V_173 &&
( ! T_1 -> V_174 ||
V_26 -> V_175 != V_176 ) ) {
const struct V_177 * V_156 ;
int V_8 ;
if ( T_1 -> V_114 )
return 0 ;
F_9 ( L_11 , V_33 ) ;
F_9 ( L_12 ,
V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_156 = F_62 ( V_26 -> V_152 ) ;
if ( V_156 -> V_69 ) {
if ( V_156 -> V_69 == V_178 ) {
F_9 ( L_13 ,
V_33 ) ;
return 0 ;
}
continue;
}
if ( V_156 -> V_179 )
break;
}
V_26 -> V_179 = V_156 -> V_179 ;
F_9 ( L_14 V_180 L_15 ,
V_33 , V_26 -> V_179 ) ;
V_26 -> V_156 = V_156 ;
V_26 -> V_181 = true ;
F_58 ( V_26 ) ;
V_8 = F_63 ( & T_1 -> V_182 , V_33 , V_26 -> V_179 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_173 = true ;
}
return 0 ;
}
static int F_64 ( struct V_1 * T_1 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < T_1 -> V_39 . V_183 ; V_10 ++ ) {
V_8 = F_60 ( T_1 , & T_1 -> V_39 . V_40 [ V_10 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_65 ( union V_184 * V_185 ,
struct V_186 * V_187 , T_4 type ,
bool V_188 )
{
V_185 -> V_189 . V_20 = F_66 ( V_187 , type , 0 ) ;
return F_67 ( V_185 , type , 0 , V_187 , V_188 ) ;
}
static int F_68 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_184 * V_185 = V_26 -> V_135 ;
struct V_186 V_187 = { . V_76 = 0 , } ;
V_185 -> V_187 . V_189 . type = V_190 ;
V_185 -> V_187 . V_189 . V_191 = V_90 ;
V_185 -> V_187 . V_189 . V_20 = sizeof( struct V_192 ) ;
if ( ! T_1 -> V_114 )
V_187 . time = F_69 ( V_26 -> V_179 , & T_1 -> V_122 ) ;
V_187 . V_76 = V_26 -> V_156 -> V_167 ;
V_187 . V_31 = V_26 -> V_31 ;
V_187 . V_32 = V_26 -> V_32 ;
V_187 . V_193 = V_26 -> V_156 -> V_77 ;
V_187 . V_194 = V_26 -> T_1 -> V_195 ;
V_187 . V_196 = V_26 -> T_1 -> V_195 ;
V_187 . V_145 = 1 ;
V_187 . V_30 = V_26 -> V_30 ;
V_187 . V_157 = V_26 -> V_157 ;
V_187 . V_166 = V_26 -> V_166 ;
if ( T_1 -> V_197 && ! ( T_1 -> V_197 & V_26 -> V_157 ) )
return 0 ;
if ( T_1 -> V_128 . V_198 ) {
V_8 = F_65 ( V_185 , & V_187 ,
T_1 -> V_199 ,
T_1 -> V_200 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_70 ( T_1 -> V_42 , V_185 , & V_187 ) ;
if ( V_8 )
F_71 ( L_16 ,
V_8 ) ;
return V_8 ;
}
static int F_72 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_184 * V_185 = V_26 -> V_135 ;
struct V_186 V_187 = { . V_76 = 0 , } ;
V_185 -> V_187 . V_189 . type = V_190 ;
V_185 -> V_187 . V_189 . V_191 = V_90 ;
V_185 -> V_187 . V_189 . V_20 = sizeof( struct V_192 ) ;
if ( ! T_1 -> V_114 )
V_187 . time = F_69 ( V_26 -> V_179 , & T_1 -> V_122 ) ;
V_187 . V_76 = V_26 -> V_156 -> V_167 ;
V_187 . V_31 = V_26 -> V_31 ;
V_187 . V_32 = V_26 -> V_32 ;
V_187 . V_193 = V_26 -> V_156 -> V_77 ;
V_187 . V_194 = V_26 -> T_1 -> V_201 ;
V_187 . V_196 = V_26 -> T_1 -> V_201 ;
V_187 . V_145 = V_26 -> V_156 -> V_202 - V_26 -> V_203 ;
V_187 . V_30 = V_26 -> V_30 ;
V_187 . V_157 = V_26 -> V_157 ;
V_187 . V_166 = V_26 -> V_166 ;
V_26 -> V_203 = V_26 -> V_156 -> V_202 ;
if ( T_1 -> V_128 . V_129 ) {
F_73 ( V_26 -> V_34 , V_26 -> V_133 ,
T_1 -> V_128 . V_132 , V_187 . V_76 ) ;
V_187 . V_129 = V_26 -> V_133 ;
}
if ( T_1 -> V_128 . V_198 ) {
V_8 = F_65 ( V_185 , & V_187 ,
T_1 -> V_204 ,
T_1 -> V_200 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_70 ( T_1 -> V_42 , V_185 , & V_187 ) ;
if ( V_8 )
F_71 ( L_17 ,
V_8 ) ;
return V_8 ;
}
static int F_74 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_184 * V_185 = V_26 -> V_135 ;
struct V_186 V_187 = { . V_76 = 0 , } ;
V_185 -> V_187 . V_189 . type = V_190 ;
V_185 -> V_187 . V_189 . V_191 = V_90 ;
V_185 -> V_187 . V_189 . V_20 = sizeof( struct V_192 ) ;
if ( ! T_1 -> V_114 )
V_187 . time = F_69 ( V_26 -> V_179 , & T_1 -> V_122 ) ;
V_187 . V_76 = V_26 -> V_156 -> V_167 ;
V_187 . V_31 = V_26 -> V_31 ;
V_187 . V_32 = V_26 -> V_32 ;
V_187 . V_193 = V_26 -> V_156 -> V_77 ;
V_187 . V_194 = V_26 -> T_1 -> V_205 ;
V_187 . V_196 = V_26 -> T_1 -> V_205 ;
V_187 . V_145 = 1 ;
V_187 . V_30 = V_26 -> V_30 ;
V_187 . V_157 = V_26 -> V_157 ;
V_187 . V_166 = V_26 -> V_166 ;
if ( T_1 -> V_128 . V_129 ) {
F_73 ( V_26 -> V_34 , V_26 -> V_133 ,
T_1 -> V_128 . V_132 , V_187 . V_76 ) ;
V_187 . V_129 = V_26 -> V_133 ;
}
if ( T_1 -> V_128 . V_198 ) {
V_8 = F_65 ( V_185 , & V_187 ,
T_1 -> V_206 ,
T_1 -> V_200 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_70 ( T_1 -> V_42 , V_185 , & V_187 ) ;
if ( V_8 )
F_71 ( L_18 ,
V_8 ) ;
return V_8 ;
}
static int F_75 ( struct V_1 * T_1 , int V_207 , int V_30 ,
T_8 V_31 , T_8 V_32 , T_4 V_76 )
{
union V_184 V_185 ;
char V_208 [ V_209 ] ;
int V_69 ;
F_76 ( V_207 , V_208 , V_209 ) ;
F_77 ( & V_185 . V_210 , V_211 ,
V_207 , V_30 , V_31 , V_32 , V_76 , V_208 ) ;
V_69 = F_70 ( T_1 -> V_42 , & V_185 , NULL ) ;
if ( V_69 )
F_71 ( L_19 ,
V_69 ) ;
return V_69 ;
}
static int F_78 ( struct V_1 * T_1 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_8 V_32 = V_26 -> V_137 ;
int V_69 ;
if ( V_32 == - 1 )
return 0 ;
F_9 ( L_20 , V_26 -> V_30 , V_32 ) ;
V_69 = F_79 ( T_1 -> V_35 , V_26 -> V_30 , - 1 , V_32 ) ;
V_28 = & T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
F_56 ( T_1 , V_28 ) ;
V_26 -> V_137 = - 1 ;
return V_69 ;
}
static inline bool F_80 ( struct V_25 * V_26 , T_4 V_76 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
return V_76 == T_1 -> V_212 &&
( V_26 -> V_157 & V_159 ) &&
! ( V_26 -> V_157 & ( V_213 | V_163 |
V_164 | V_160 ) ) ;
}
static int F_81 ( struct V_25 * V_26 )
{
const struct V_177 * V_156 = V_26 -> V_156 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_69 ;
if ( ! V_26 -> V_181 )
return 0 ;
V_26 -> V_181 = false ;
if ( T_1 -> V_214 &&
( V_156 -> type & V_215 ) ) {
V_69 = F_72 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_216 &&
( V_156 -> type & V_217 ) ) {
V_69 = F_74 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( ! ( V_156 -> type & V_218 ) )
return 0 ;
if ( T_1 -> V_128 . V_129 )
F_82 ( V_26 -> V_34 , V_26 -> V_157 , V_156 -> V_167 ,
V_156 -> V_77 , V_26 -> V_166 ,
V_156 -> V_50 ) ;
else
F_83 ( V_26 -> V_34 , V_156 -> V_50 ) ;
if ( T_1 -> V_219 ) {
V_69 = F_68 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( ! T_1 -> V_174 )
return 0 ;
if ( F_80 ( V_26 , V_156 -> V_77 ) ) {
switch ( V_26 -> V_175 ) {
case V_220 :
case V_221 :
V_69 = F_78 ( T_1 , V_26 ) ;
if ( V_69 )
return V_69 ;
V_26 -> V_175 = V_222 ;
break;
default:
V_26 -> V_175 = V_176 ;
return 1 ;
}
} else if ( ! V_156 -> V_77 ) {
V_26 -> V_175 = V_223 ;
} else if ( V_26 -> V_175 == V_223 ) {
V_26 -> V_175 = V_220 ;
} else if ( V_26 -> V_175 == V_220 &&
V_156 -> V_77 == T_1 -> V_224 &&
( V_26 -> V_157 & V_162 ) ) {
V_26 -> V_175 = V_222 ;
}
return 0 ;
}
static T_4 F_84 ( struct V_35 * V_35 , T_4 * V_224 )
{
struct V_93 * V_93 ;
struct V_225 * V_226 , * V_18 ;
T_4 V_76 , V_212 = 0 ;
if ( V_224 )
* V_224 = 0 ;
V_93 = F_85 ( V_35 , V_92 ) ;
if ( ! V_93 )
return 0 ;
if ( F_37 ( V_93 , V_35 -> V_99 ) )
return 0 ;
V_18 = F_86 ( V_93 -> V_59 , V_92 ) ;
for ( V_226 = V_18 ; V_226 ; V_226 = F_87 ( V_226 ) ) {
if ( V_226 -> V_227 == V_228 &&
! strcmp ( V_226 -> V_229 , L_21 ) ) {
V_76 = V_93 -> V_230 ( V_93 , V_226 -> V_18 ) ;
if ( V_76 >= V_93 -> V_18 && V_76 < V_93 -> V_103 ) {
V_212 = V_76 ;
break;
}
}
}
if ( ! V_212 || ! V_224 )
return 0 ;
for ( V_226 = V_18 ; V_226 ; V_226 = F_87 ( V_226 ) ) {
if ( ! strcmp ( V_226 -> V_229 , L_22 ) ) {
V_76 = V_93 -> V_230 ( V_93 , V_226 -> V_18 ) ;
if ( V_76 >= V_93 -> V_18 && V_76 < V_93 -> V_103 ) {
* V_224 = V_76 ;
break;
}
}
}
return V_212 ;
}
static int F_88 ( struct V_25 * V_26 , T_4 * V_179 )
{
const struct V_177 * V_156 = V_26 -> V_156 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_69 ;
if ( ! T_1 -> V_88 ) {
T_1 -> V_88 = F_89 ( T_1 -> V_35 ) ;
if ( T_1 -> V_231 && T_1 -> V_154 &&
! T_1 -> V_114 && F_47 ( T_1 ) &&
! T_1 -> V_49 ) {
T_1 -> V_212 = F_84 ( T_1 -> V_35 ,
& T_1 -> V_224 ) ;
if ( T_1 -> V_212 ) {
F_9 ( L_23 V_180 L_24 V_180 L_15 ,
T_1 -> V_212 , T_1 -> V_224 ) ;
T_1 -> V_174 = true ;
}
}
}
F_9 ( L_12 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_69 = F_81 ( V_26 ) ;
if ( V_69 )
return V_69 ;
V_156 = F_62 ( V_26 -> V_152 ) ;
if ( V_156 -> V_69 ) {
if ( V_156 -> V_69 == V_178 )
return 1 ;
if ( T_1 -> V_174 &&
V_156 -> V_167 >= T_1 -> V_88 ) {
T_1 -> V_174 = false ;
F_78 ( T_1 , V_26 ) ;
}
if ( T_1 -> V_128 . V_232 ) {
V_69 = F_75 ( T_1 , V_156 -> V_69 ,
V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_32 ,
V_156 -> V_167 ) ;
if ( V_69 )
return V_69 ;
}
continue;
}
V_26 -> V_156 = V_156 ;
V_26 -> V_181 = true ;
F_58 ( V_26 ) ;
if ( T_1 -> V_233 &&
( V_156 -> V_167 >= T_1 -> V_88 || ! V_156 -> V_167 ) &&
V_156 -> V_77 && V_156 -> V_77 < T_1 -> V_88 ) {
F_9 ( L_25 V_180 L_26 V_180 L_15 ,
V_156 -> V_179 , V_156 -> V_234 ) ;
V_26 -> V_179 = V_156 -> V_234 ;
} else if ( T_1 -> V_174 &&
V_26 -> V_175 == V_220 &&
F_80 ( V_26 , V_156 -> V_77 ) &&
V_26 -> V_137 == - 1 ) {
F_9 ( L_25 V_180 L_26 V_180 L_15 ,
V_156 -> V_179 , V_156 -> V_234 ) ;
V_26 -> V_179 = V_156 -> V_234 ;
} else if ( V_156 -> V_179 > V_26 -> V_179 ) {
V_26 -> V_179 = V_156 -> V_179 ;
}
if ( ! T_1 -> V_114 && V_26 -> V_179 >= * V_179 ) {
* V_179 = V_26 -> V_179 ;
return 0 ;
}
}
return 0 ;
}
static inline int F_90 ( struct V_1 * T_1 )
{
if ( T_1 -> V_39 . V_235 ) {
T_1 -> V_39 . V_235 = false ;
return F_64 ( T_1 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * T_1 , T_4 V_179 )
{
unsigned int V_33 ;
T_4 V_236 ;
int V_8 ;
while ( 1 ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
if ( ! T_1 -> V_182 . V_237 )
return 0 ;
if ( T_1 -> V_182 . V_238 [ 0 ] . V_239 >= V_179 )
return 0 ;
V_33 = T_1 -> V_182 . V_238 [ 0 ] . V_33 ;
V_28 = & T_1 -> V_39 . V_40 [ V_33 ] ;
V_26 = V_28 -> V_153 ;
F_9 ( L_27 V_180 L_28 V_180 L_15 ,
V_33 , T_1 -> V_182 . V_238 [ 0 ] . V_239 ,
V_179 ) ;
F_92 ( & T_1 -> V_182 ) ;
if ( T_1 -> V_182 . V_237 ) {
V_236 = T_1 -> V_182 . V_238 [ 0 ] . V_239 + 1 ;
if ( V_236 > V_179 )
V_236 = V_179 ;
} else {
V_236 = V_179 ;
}
F_56 ( T_1 , V_28 ) ;
V_8 = F_88 ( V_26 , & V_236 ) ;
if ( V_8 < 0 ) {
F_63 ( & T_1 -> V_182 , V_33 , V_236 ) ;
return V_8 ;
}
if ( ! V_8 ) {
V_8 = F_63 ( & T_1 -> V_182 , V_33 , V_236 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_26 -> V_173 = false ;
}
}
return 0 ;
}
static int F_93 ( struct V_1 * T_1 , T_8 V_32 ,
T_4 V_240 )
{
struct V_241 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
T_4 V_236 = 0 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_183 ; V_10 ++ ) {
struct V_27 * V_28 = & T_1 -> V_39 . V_40 [ V_10 ] ;
struct V_25 * V_26 = V_28 -> V_153 ;
if ( V_26 && ( V_32 == - 1 || V_26 -> V_32 == V_32 ) ) {
V_26 -> time = V_240 ;
F_56 ( T_1 , V_28 ) ;
F_88 ( V_26 , & V_236 ) ;
}
}
return 0 ;
}
static int F_94 ( struct V_1 * T_1 , struct V_186 * V_187 )
{
return F_75 ( T_1 , V_242 , V_187 -> V_30 ,
V_187 -> V_31 , V_187 -> V_32 , 0 ) ;
}
static struct V_25 * F_95 ( struct V_1 * T_1 , int V_30 )
{
unsigned V_10 , V_243 ;
if ( V_30 < 0 || ! T_1 -> V_39 . V_183 )
return NULL ;
if ( ( unsigned ) V_30 >= T_1 -> V_39 . V_183 )
V_10 = T_1 -> V_39 . V_183 - 1 ;
else
V_10 = V_30 ;
if ( T_1 -> V_39 . V_40 [ V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_153 ;
for ( V_243 = 0 ; V_10 > 0 ; V_243 ++ ) {
if ( T_1 -> V_39 . V_40 [ -- V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_153 ;
}
for (; V_243 < T_1 -> V_39 . V_183 ; V_243 ++ ) {
if ( T_1 -> V_39 . V_40 [ V_243 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_243 ] . V_153 ;
}
return NULL ;
}
static int F_96 ( struct V_1 * T_1 ,
struct V_186 * V_187 )
{
struct V_25 * V_26 ;
struct V_108 * V_109 ;
T_8 V_32 ;
int V_30 , V_69 ;
V_109 = F_97 ( T_1 -> V_42 -> V_244 , V_187 -> V_194 ) ;
if ( V_109 != T_1 -> V_245 )
return 0 ;
V_32 = F_98 ( V_109 , V_187 , L_29 ) ;
V_30 = V_187 -> V_30 ;
F_9 ( L_30 V_246 L_31 V_180 L_15 ,
V_30 , V_32 , V_187 -> time , F_99 ( V_187 -> time ,
& T_1 -> V_122 ) ) ;
if ( ! T_1 -> V_174 )
goto V_102;
V_26 = F_95 ( T_1 , V_30 ) ;
if ( ! V_26 )
goto V_102;
switch ( V_26 -> V_175 ) {
case V_223 :
V_26 -> V_137 = - 1 ;
break;
case V_220 :
case V_222 :
V_26 -> V_137 = V_32 ;
V_26 -> V_175 = V_221 ;
return 0 ;
case V_176 :
if ( ! V_26 -> V_173 ) {
V_26 -> V_179 = F_99 ( V_187 -> time ,
& T_1 -> V_122 ) ;
V_69 = F_63 ( & T_1 -> V_182 , V_26 -> V_33 ,
V_26 -> V_179 ) ;
if ( V_69 )
return V_69 ;
V_26 -> V_173 = true ;
}
V_26 -> V_175 = V_222 ;
break;
case V_221 :
V_26 -> V_137 = V_32 ;
F_9 ( L_32 , V_30 ) ;
break;
default:
break;
}
V_102:
return F_79 ( T_1 -> V_35 , V_30 , - 1 , V_32 ) ;
}
static int F_100 ( struct V_1 * T_1 ,
union V_184 * V_185 ,
struct V_186 * V_187 )
{
if ( ! T_1 -> V_231 )
return 0 ;
F_9 ( L_33 V_246 L_31 V_180 L_15 ,
V_187 -> V_30 , V_185 -> V_247 . V_31 ,
V_185 -> V_247 . V_32 , V_187 -> time ,
F_99 ( V_187 -> time , & T_1 -> V_122 ) ) ;
return F_79 ( T_1 -> V_35 , V_187 -> V_30 ,
V_185 -> V_247 . V_31 ,
V_185 -> V_247 . V_32 ) ;
}
static int F_101 ( struct V_248 * V_42 ,
union V_184 * V_185 ,
struct V_186 * V_187 ,
struct V_249 * V_250 )
{
struct V_1 * T_1 = F_102 ( V_42 -> V_251 , struct V_1 ,
V_251 ) ;
T_4 V_179 ;
int V_69 = 0 ;
if ( V_252 )
return 0 ;
if ( ! V_250 -> V_253 ) {
F_71 ( L_34 ) ;
return - V_22 ;
}
if ( V_187 -> time && V_187 -> time != ( T_4 ) - 1 )
V_179 = F_99 ( V_187 -> time , & T_1 -> V_122 ) ;
else
V_179 = 0 ;
if ( V_179 || T_1 -> V_114 ) {
V_69 = F_90 ( T_1 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_114 ) {
if ( V_185 -> V_189 . type == V_254 ) {
V_69 = F_93 ( T_1 ,
V_185 -> V_255 . V_32 ,
V_187 -> time ) ;
}
} else if ( V_179 ) {
V_69 = F_91 ( T_1 , V_179 ) ;
}
if ( V_69 )
return V_69 ;
if ( V_185 -> V_189 . type == V_256 &&
( V_185 -> V_257 . V_157 & V_258 ) &&
T_1 -> V_128 . V_232 ) {
V_69 = F_94 ( T_1 , V_187 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_245 && V_185 -> V_189 . type == V_190 )
V_69 = F_96 ( T_1 , V_187 ) ;
else if ( V_185 -> V_189 . type == V_259 )
V_69 = F_100 ( T_1 , V_185 , V_187 ) ;
F_9 ( L_35 V_246 L_31 V_180 L_15 ,
F_103 ( V_185 -> V_189 . type ) , V_185 -> V_189 . type ,
V_187 -> V_30 , V_187 -> time , V_179 ) ;
return V_69 ;
}
static int F_104 ( struct V_248 * V_42 , struct V_249 * V_250 )
{
struct V_1 * T_1 = F_102 ( V_42 -> V_251 , struct V_1 ,
V_251 ) ;
int V_8 ;
if ( V_252 )
return 0 ;
if ( ! V_250 -> V_253 )
return - V_22 ;
V_8 = F_90 ( T_1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( T_1 -> V_114 )
return F_93 ( T_1 , - 1 ,
V_260 - 1 ) ;
return F_91 ( T_1 , V_260 ) ;
}
static void F_105 ( struct V_248 * V_42 )
{
struct V_1 * T_1 = F_102 ( V_42 -> V_251 , struct V_1 ,
V_251 ) ;
struct V_241 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_183 ; V_10 ++ ) {
F_54 ( V_39 -> V_40 [ V_10 ] . V_153 ) ;
V_39 -> V_40 [ V_10 ] . V_153 = NULL ;
}
F_106 () ;
F_107 ( V_39 ) ;
}
static void F_108 ( struct V_248 * V_42 )
{
struct V_1 * T_1 = F_102 ( V_42 -> V_251 , struct V_1 ,
V_251 ) ;
F_109 ( & T_1 -> V_182 ) ;
F_105 ( V_42 ) ;
V_42 -> V_251 = NULL ;
F_110 ( T_1 -> V_91 ) ;
free ( T_1 ) ;
}
static int F_111 ( struct V_248 * V_42 ,
union V_184 * V_185 ,
struct V_249 * V_250 V_2 )
{
struct V_1 * T_1 = F_102 ( V_42 -> V_251 , struct V_1 ,
V_251 ) ;
if ( T_1 -> V_49 )
return 0 ;
if ( ! T_1 -> V_261 ) {
struct V_15 * V_29 ;
T_3 V_262 ;
int V_41 = F_16 ( V_42 -> V_43 ) ;
int V_69 ;
if ( F_112 ( V_42 -> V_43 ) ) {
V_262 = 0 ;
} else {
V_262 = F_113 ( V_41 , 0 , V_263 ) ;
if ( V_262 == - 1 )
return - V_264 ;
}
V_69 = F_114 ( & T_1 -> V_39 , V_42 , V_185 ,
V_262 , & V_29 ) ;
if ( V_69 )
return V_69 ;
if ( V_252 ) {
if ( F_17 ( V_29 , V_41 ) ) {
F_5 ( T_1 , V_29 -> V_19 ,
V_29 -> V_20 ) ;
F_115 ( V_29 ) ;
}
}
}
return 0 ;
}
static int F_116 ( struct V_249 * V_250 ,
union V_184 * V_185 ,
struct V_186 * V_187 V_2 ,
struct V_35 * V_35 V_2 )
{
struct V_265 * V_265 =
F_102 ( V_250 , struct V_265 , V_266 ) ;
return F_70 ( V_265 -> V_42 , V_185 ,
NULL ) ;
}
static int F_117 ( struct V_248 * V_42 ,
struct V_104 * V_105 , T_4 V_194 )
{
struct V_265 V_265 ;
memset ( & V_265 , 0 , sizeof( struct V_265 ) ) ;
V_265 . V_42 = V_42 ;
return F_118 ( & V_265 . V_266 , V_105 , 1 ,
& V_194 , F_116 ) ;
}
static int F_119 ( struct V_1 * T_1 ,
struct V_248 * V_42 )
{
struct V_267 * V_244 = V_42 -> V_244 ;
struct V_108 * V_109 ;
struct V_104 V_105 ;
bool V_268 = false ;
T_4 V_194 ;
int V_69 ;
F_43 (evlist, evsel) {
if ( V_109 -> V_105 . type == T_1 -> V_107 && V_109 -> V_269 ) {
V_268 = true ;
break;
}
}
if ( ! V_268 ) {
F_120 ( L_36 ) ;
return 0 ;
}
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
V_105 . V_20 = sizeof( struct V_104 ) ;
V_105 . type = V_270 ;
V_105 . V_117 = V_109 -> V_105 . V_117 & V_271 ;
V_105 . V_117 |= V_272 | V_273 |
V_274 ;
if ( T_1 -> V_114 )
V_105 . V_117 &= ~ ( T_4 ) V_118 ;
else
V_105 . V_117 |= V_118 ;
if ( ! T_1 -> V_231 )
V_105 . V_117 &= ~ ( T_4 ) V_275 ;
V_105 . V_276 = V_109 -> V_105 . V_276 ;
V_105 . V_110 = V_109 -> V_105 . V_110 ;
V_105 . V_277 = V_109 -> V_105 . V_277 ;
V_105 . V_278 = V_109 -> V_105 . V_278 ;
V_105 . V_279 = V_109 -> V_105 . V_279 ;
V_105 . V_280 = V_109 -> V_105 . V_280 ;
V_105 . V_281 = V_109 -> V_105 . V_281 ;
V_194 = V_109 -> V_194 [ 0 ] + 1000000000 ;
if ( ! V_194 )
V_194 = 1 ;
if ( T_1 -> V_128 . V_144 ) {
V_105 . V_106 = V_282 ;
if ( T_1 -> V_128 . V_146 == V_151 )
V_105 . V_283 =
F_49 ( T_1 , T_1 -> V_128 . V_145 ) ;
else
V_105 . V_283 = T_1 -> V_128 . V_145 ;
T_1 -> V_284 = V_105 . V_283 ;
if ( T_1 -> V_128 . V_129 )
V_105 . V_117 |= V_285 ;
F_120 ( L_37 V_246 L_38 V_180 L_15 ,
V_194 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_117 ( V_42 , & V_105 , V_194 ) ;
if ( V_69 ) {
F_71 ( L_39 ,
V_286 ) ;
return V_69 ;
}
T_1 -> V_214 = true ;
T_1 -> V_204 = V_105 . V_117 ;
T_1 -> V_201 = V_194 ;
V_194 += 1 ;
}
if ( T_1 -> V_128 . V_287 ) {
V_105 . V_106 = V_282 ;
V_105 . V_283 = 1 ;
if ( T_1 -> V_128 . V_129 )
V_105 . V_117 |= V_285 ;
F_120 ( L_40 V_246 L_38 V_180 L_15 ,
V_194 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_117 ( V_42 , & V_105 , V_194 ) ;
if ( V_69 ) {
F_71 ( L_41 ,
V_286 ) ;
return V_69 ;
}
T_1 -> V_216 = true ;
T_1 -> V_205 = V_194 ;
V_194 += 1 ;
F_43 (evlist, evsel) {
if ( V_109 -> V_194 && V_109 -> V_194 [ 0 ] == T_1 -> V_205 ) {
if ( V_109 -> V_229 )
F_53 ( & V_109 -> V_229 ) ;
V_109 -> V_229 = F_121 ( L_42 ) ;
break;
}
}
}
if ( T_1 -> V_128 . V_288 ) {
V_105 . V_106 = V_289 ;
V_105 . V_283 = 1 ;
V_105 . V_117 |= V_290 ;
V_105 . V_117 &= ~ ( T_4 ) V_285 ;
F_120 ( L_43 V_246 L_38 V_180 L_15 ,
V_194 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_117 ( V_42 , & V_105 , V_194 ) ;
if ( V_69 ) {
F_71 ( L_44 ,
V_286 ) ;
return V_69 ;
}
T_1 -> V_219 = true ;
T_1 -> V_199 = V_105 . V_117 ;
T_1 -> V_195 = V_194 ;
}
T_1 -> V_200 = V_109 -> V_291 ;
return 0 ;
}
static struct V_108 * F_122 ( struct V_267 * V_244 )
{
struct V_108 * V_109 ;
F_123 (evlist, evsel) {
const char * V_229 = F_124 ( V_109 ) ;
if ( ! strcmp ( V_229 , L_45 ) )
return V_109 ;
}
return NULL ;
}
static void F_125 ( T_4 * V_292 , int V_18 , int V_293 )
{
int V_10 ;
if ( ! V_252 )
return;
for ( V_10 = V_18 ; V_10 <= V_293 ; V_10 ++ )
fprintf ( stdout , V_294 [ V_10 ] , V_292 [ V_10 ] ) ;
}
int F_126 ( union V_184 * V_185 ,
struct V_248 * V_42 )
{
struct V_295 * V_296 = & V_185 -> V_296 ;
T_2 V_297 = sizeof( T_4 ) * V_298 ;
struct V_1 * T_1 ;
int V_69 ;
if ( V_296 -> V_189 . V_20 < sizeof( struct V_295 ) +
V_297 )
return - V_22 ;
T_1 = F_51 ( sizeof( struct V_1 ) ) ;
if ( ! T_1 )
return - V_44 ;
V_69 = F_127 ( & T_1 -> V_39 ) ;
if ( V_69 )
goto V_299;
F_128 ( V_300 ) ;
T_1 -> V_42 = V_42 ;
T_1 -> V_35 = & V_42 -> V_301 . V_302 ;
T_1 -> V_303 = V_296 -> type ;
T_1 -> V_107 = V_296 -> V_153 [ V_304 ] ;
T_1 -> V_122 . V_124 = V_296 -> V_153 [ V_305 ] ;
T_1 -> V_122 . V_123 = V_296 -> V_153 [ V_306 ] ;
T_1 -> V_122 . V_307 = V_296 -> V_153 [ V_308 ] ;
T_1 -> V_116 = V_296 -> V_153 [ V_309 ] ;
T_1 -> V_115 = V_296 -> V_153 [ V_310 ] ;
T_1 -> V_111 = V_296 -> V_153 [ V_311 ] ;
T_1 -> V_154 = V_296 -> V_153 [ V_312 ] ;
T_1 -> V_45 = V_296 -> V_153 [ V_313 ] ;
T_1 -> V_231 = V_296 -> V_153 [ V_298 ] ;
F_125 ( & V_296 -> V_153 [ 0 ] , V_304 ,
V_298 ) ;
if ( V_296 -> V_189 . V_20 >= sizeof( struct V_295 ) +
( sizeof( T_4 ) * V_314 ) ) {
T_1 -> V_315 = V_296 -> V_153 [ V_316 ] ;
T_1 -> V_113 = V_296 -> V_153 [ V_317 ] ;
T_1 -> V_142 = V_296 -> V_153 [ V_318 ] ;
T_1 -> V_143 = V_296 -> V_153 [ V_319 ] ;
T_1 -> V_320 = V_296 -> V_153 [ V_314 ] ;
F_125 ( & V_296 -> V_153 [ 0 ] , V_316 ,
V_314 ) ;
}
T_1 -> V_114 = F_46 ( T_1 ) ;
T_1 -> V_21 = F_48 ( T_1 ) ;
T_1 -> V_49 = false ;
T_1 -> V_233 = ! T_1 -> V_114 ;
T_1 -> V_91 = F_129 ( 999999999 , 999999999 ) ;
if ( ! T_1 -> V_91 ) {
V_69 = - V_44 ;
goto V_321;
}
V_69 = F_130 ( T_1 -> V_91 , L_46 , 0 ) ;
if ( V_69 )
goto V_322;
if ( F_131 ( T_1 -> V_91 , T_1 -> V_35 ) ) {
V_69 = - V_44 ;
goto V_322;
}
T_1 -> V_251 . V_323 = F_101 ;
T_1 -> V_251 . V_324 = F_111 ;
T_1 -> V_251 . V_325 = F_104 ;
T_1 -> V_251 . V_326 = F_105 ;
T_1 -> V_251 . free = F_108 ;
V_42 -> V_251 = & T_1 -> V_251 ;
if ( V_252 )
return 0 ;
if ( T_1 -> V_154 == 1 ) {
T_1 -> V_245 = F_122 ( V_42 -> V_244 ) ;
if ( ! T_1 -> V_245 ) {
F_71 ( L_47 , V_286 ) ;
goto V_322;
}
}
if ( V_42 -> V_327 && V_42 -> V_327 -> V_328 ) {
T_1 -> V_128 = * V_42 -> V_327 ;
} else {
F_132 ( & T_1 -> V_128 ) ;
if ( V_329 != - 1 ) {
T_1 -> V_128 . V_288 = false ;
T_1 -> V_128 . V_129 = true ;
}
}
if ( T_1 -> V_128 . log )
F_133 () ;
if ( T_1 -> V_122 . V_123 ) {
T_4 V_330 = F_49 ( T_1 , 1000000000 ) ;
T_1 -> V_140 = ( V_330 + 50000000 ) / 100000000 ;
F_9 ( L_48 V_246 L_15 , V_330 ) ;
F_9 ( L_49 ,
T_1 -> V_140 ) ;
}
if ( T_1 -> V_128 . V_331 )
T_1 -> V_197 |= V_162 | V_163 |
V_165 ;
if ( T_1 -> V_128 . V_332 )
T_1 -> V_197 |= V_333 |
V_169 ;
if ( T_1 -> V_128 . V_129 && ! V_334 . V_335 ) {
V_334 . V_335 = true ;
if ( F_134 ( & V_336 ) < 0 ) {
V_334 . V_335 = false ;
T_1 -> V_128 . V_129 = false ;
}
}
V_69 = F_119 ( T_1 , V_42 ) ;
if ( V_69 )
goto V_322;
V_69 = F_135 ( & T_1 -> V_39 , V_42 ) ;
if ( V_69 )
goto V_322;
if ( T_1 -> V_39 . V_337 )
T_1 -> V_261 = true ;
if ( T_1 -> V_114 )
F_136 ( L_50 ) ;
return 0 ;
V_322:
F_110 ( T_1 -> V_91 ) ;
V_321:
F_106 () ;
F_107 ( & T_1 -> V_39 ) ;
V_42 -> V_251 = NULL ;
V_299:
free ( T_1 ) ;
return V_69 ;
}
