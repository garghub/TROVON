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
if ( T_1 -> V_128 . V_135 ) {
T_2 V_130 = sizeof( struct V_136 ) ;
V_130 += T_1 -> V_128 . V_137 *
sizeof( struct V_138 ) ;
V_26 -> V_135 = F_51 ( V_130 ) ;
if ( ! V_26 -> V_135 )
goto V_134;
V_26 -> V_139 = F_51 ( V_130 ) ;
if ( ! V_26 -> V_139 )
goto V_134;
}
V_26 -> V_140 = malloc ( V_141 ) ;
if ( ! V_26 -> V_140 )
goto V_134;
V_26 -> T_1 = T_1 ;
V_26 -> V_33 = V_33 ;
V_26 -> V_110 = F_42 ( T_1 ) ;
V_26 -> V_31 = - 1 ;
V_26 -> V_32 = - 1 ;
V_26 -> V_30 = - 1 ;
V_26 -> V_142 = - 1 ;
V_126 . V_127 = F_13 ;
V_126 . V_143 = F_32 ;
V_126 . V_19 = V_26 ;
V_126 . V_144 = F_44 ( T_1 ) ;
V_126 . V_145 = T_1 -> V_145 ;
V_126 . V_146 = F_45 ( T_1 ) ;
V_126 . V_147 = T_1 -> V_147 ;
V_126 . V_148 = T_1 -> V_148 ;
if ( T_1 -> V_128 . V_149 ) {
if ( T_1 -> V_128 . V_150 ) {
switch ( T_1 -> V_128 . V_151 ) {
case V_152 :
V_126 . V_151 =
V_153 ;
V_126 . V_150 = T_1 -> V_128 . V_150 ;
break;
case V_154 :
V_126 . V_151 = V_155 ;
V_126 . V_150 = T_1 -> V_128 . V_150 ;
break;
case V_156 :
V_126 . V_151 = V_155 ;
V_126 . V_150 = F_49 ( T_1 ,
T_1 -> V_128 . V_150 ) ;
break;
default:
break;
}
}
if ( ! V_126 . V_150 ) {
V_126 . V_151 = V_153 ;
V_126 . V_150 = 1 ;
}
}
V_26 -> V_157 = F_52 ( & V_126 ) ;
if ( ! V_26 -> V_157 )
goto V_134;
return V_26 ;
V_134:
F_53 ( & V_26 -> V_140 ) ;
F_53 ( & V_26 -> V_135 ) ;
F_53 ( & V_26 -> V_139 ) ;
F_53 ( & V_26 -> V_133 ) ;
free ( V_26 ) ;
return NULL ;
}
static void F_54 ( void * V_158 )
{
struct V_25 * V_26 = V_158 ;
if ( ! V_26 )
return;
F_10 ( V_26 -> V_34 ) ;
F_55 ( V_26 -> V_157 ) ;
F_53 ( & V_26 -> V_140 ) ;
F_53 ( & V_26 -> V_135 ) ;
F_53 ( & V_26 -> V_139 ) ;
F_53 ( & V_26 -> V_133 ) ;
free ( V_26 ) ;
}
static void F_56 ( struct V_1 * T_1 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = V_28 -> V_158 ;
if ( V_28 -> V_32 == - 1 || T_1 -> V_159 ) {
V_26 -> V_32 = F_57 ( T_1 -> V_35 , V_26 -> V_30 ) ;
F_10 ( V_26 -> V_34 ) ;
}
if ( ! V_26 -> V_34 && V_26 -> V_32 != - 1 )
V_26 -> V_34 = F_12 ( T_1 -> V_35 , - 1 , V_26 -> V_32 ) ;
if ( V_26 -> V_34 ) {
V_26 -> V_31 = V_26 -> V_34 -> V_160 ;
if ( V_28 -> V_30 == - 1 )
V_26 -> V_30 = V_26 -> V_34 -> V_30 ;
}
}
static void F_58 ( struct V_25 * V_26 )
{
if ( V_26 -> V_161 -> V_162 & V_163 ) {
V_26 -> V_162 = V_164 | V_165 ;
} else if ( V_26 -> V_161 -> V_162 & V_166 ) {
if ( V_26 -> V_161 -> V_77 )
V_26 -> V_162 = V_164 | V_167 |
V_168 |
V_169 ;
else
V_26 -> V_162 = V_164 |
V_170 ;
V_26 -> V_171 = 0 ;
} else {
if ( V_26 -> V_161 -> V_172 )
V_26 -> V_162 = F_59 ( V_26 -> V_161 -> V_173 ) ;
else
V_26 -> V_162 = V_164 |
V_174 ;
if ( V_26 -> V_161 -> V_162 & V_175 )
V_26 -> V_162 |= V_176 ;
V_26 -> V_171 = V_26 -> V_161 -> V_171 ;
}
}
static int F_60 ( struct V_1 * T_1 ,
struct V_27 * V_28 ,
unsigned int V_33 )
{
struct V_25 * V_26 = V_28 -> V_158 ;
if ( F_61 ( & V_28 -> V_177 ) )
return 0 ;
if ( ! V_26 ) {
V_26 = F_50 ( T_1 , V_33 ) ;
if ( ! V_26 )
return - V_44 ;
V_28 -> V_158 = V_26 ;
if ( V_28 -> V_30 != - 1 )
V_26 -> V_30 = V_28 -> V_30 ;
V_26 -> V_32 = V_28 -> V_32 ;
if ( T_1 -> V_49 ) {
if ( T_1 -> V_114 )
V_26 -> V_53 = true ;
if ( T_1 -> V_114 || ! T_1 -> V_159 )
V_26 -> V_52 = true ;
}
}
if ( ! V_26 -> V_178 &&
( ! T_1 -> V_179 ||
V_26 -> V_180 != V_181 ) ) {
const struct V_182 * V_161 ;
int V_8 ;
if ( T_1 -> V_114 )
return 0 ;
F_9 ( L_11 , V_33 ) ;
F_9 ( L_12 ,
V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_161 = F_62 ( V_26 -> V_157 ) ;
if ( V_161 -> V_69 ) {
if ( V_161 -> V_69 == V_183 ) {
F_9 ( L_13 ,
V_33 ) ;
return 0 ;
}
continue;
}
if ( V_161 -> V_184 )
break;
}
V_26 -> V_184 = V_161 -> V_184 ;
F_9 ( L_14 V_185 L_15 ,
V_33 , V_26 -> V_184 ) ;
V_26 -> V_161 = V_161 ;
V_26 -> V_186 = true ;
F_58 ( V_26 ) ;
V_8 = F_63 ( & T_1 -> V_187 , V_33 , V_26 -> V_184 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_178 = true ;
}
return 0 ;
}
static int F_64 ( struct V_1 * T_1 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < T_1 -> V_39 . V_188 ; V_10 ++ ) {
V_8 = F_60 ( T_1 , & T_1 -> V_39 . V_40 [ V_10 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static inline void F_65 ( struct V_25 * V_26 )
{
struct V_136 * V_189 = V_26 -> V_139 ;
struct V_136 * V_190 = V_26 -> V_135 ;
T_2 V_191 = 0 ;
V_190 -> V_191 = V_189 -> V_191 ;
if ( ! V_189 -> V_191 )
return;
V_191 = V_26 -> T_1 -> V_128 . V_137 - V_26 -> V_192 ;
memcpy ( & V_190 -> V_193 [ 0 ] ,
& V_189 -> V_193 [ V_26 -> V_192 ] ,
sizeof( struct V_138 ) * V_191 ) ;
if ( V_189 -> V_191 >= V_26 -> T_1 -> V_128 . V_137 ) {
memcpy ( & V_190 -> V_193 [ V_191 ] ,
& V_189 -> V_193 [ 0 ] ,
sizeof( struct V_138 ) * V_26 -> V_192 ) ;
}
}
static inline void F_66 ( struct V_25 * V_26 )
{
V_26 -> V_192 = 0 ;
V_26 -> V_139 -> V_191 = 0 ;
}
static void F_67 ( struct V_25 * V_26 )
{
const struct V_182 * V_161 = V_26 -> V_161 ;
struct V_136 * V_194 = V_26 -> V_139 ;
struct V_138 * V_195 ;
if ( ! V_26 -> V_192 )
V_26 -> V_192 = V_26 -> T_1 -> V_128 . V_137 ;
V_26 -> V_192 -= 1 ;
V_195 = & V_194 -> V_193 [ V_26 -> V_192 ] ;
V_195 -> V_196 = V_161 -> V_172 ;
V_195 -> V_197 = V_161 -> V_77 ;
V_195 -> V_162 . abort = ! ! ( V_161 -> V_162 & V_163 ) ;
V_195 -> V_162 . V_198 = ! ! ( V_161 -> V_162 & V_175 ) ;
V_195 -> V_162 . V_199 = V_26 -> T_1 -> V_200 ;
if ( V_194 -> V_191 < V_26 -> T_1 -> V_128 . V_137 )
V_194 -> V_191 += 1 ;
}
static int F_68 ( union V_201 * V_202 ,
struct V_203 * V_204 , T_4 type ,
bool V_205 )
{
V_202 -> V_206 . V_20 = F_69 ( V_204 , type , 0 ) ;
return F_70 ( V_202 , type , 0 , V_204 , V_205 ) ;
}
static int F_71 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_201 * V_202 = V_26 -> V_140 ;
struct V_203 V_204 = { . V_76 = 0 , } ;
struct V_207 {
T_4 V_191 ;
struct V_138 V_193 ;
} V_208 ;
if ( T_1 -> V_209 && ! ( T_1 -> V_209 & V_26 -> V_162 ) )
return 0 ;
V_202 -> V_204 . V_206 . type = V_210 ;
V_202 -> V_204 . V_206 . V_211 = V_90 ;
V_202 -> V_204 . V_206 . V_20 = sizeof( struct V_212 ) ;
if ( ! T_1 -> V_114 )
V_204 . time = F_72 ( V_26 -> V_184 , & T_1 -> V_122 ) ;
V_204 . V_76 = V_26 -> V_161 -> V_172 ;
V_204 . V_31 = V_26 -> V_31 ;
V_204 . V_32 = V_26 -> V_32 ;
V_204 . V_213 = V_26 -> V_161 -> V_77 ;
V_204 . V_214 = V_26 -> T_1 -> V_215 ;
V_204 . V_216 = V_26 -> T_1 -> V_215 ;
V_204 . V_150 = 1 ;
V_204 . V_30 = V_26 -> V_30 ;
V_204 . V_162 = V_26 -> V_162 ;
V_204 . V_171 = V_26 -> V_171 ;
if ( T_1 -> V_128 . V_135 && V_217 == V_218 ) {
V_208 = (struct V_207 ) {
. V_191 = 1 ,
. V_193 = {
. V_196 = V_204 . V_76 ,
. V_197 = V_204 . V_213 ,
} ,
} ;
V_204 . V_136 = (struct V_136 * ) & V_208 ;
}
if ( T_1 -> V_128 . V_219 ) {
V_8 = F_68 ( V_202 , & V_204 ,
T_1 -> V_220 ,
T_1 -> V_221 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_73 ( T_1 -> V_42 , V_202 , & V_204 ) ;
if ( V_8 )
F_74 ( L_16 ,
V_8 ) ;
return V_8 ;
}
static int F_75 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_201 * V_202 = V_26 -> V_140 ;
struct V_203 V_204 = { . V_76 = 0 , } ;
V_202 -> V_204 . V_206 . type = V_210 ;
V_202 -> V_204 . V_206 . V_211 = V_90 ;
V_202 -> V_204 . V_206 . V_20 = sizeof( struct V_212 ) ;
if ( ! T_1 -> V_114 )
V_204 . time = F_72 ( V_26 -> V_184 , & T_1 -> V_122 ) ;
V_204 . V_76 = V_26 -> V_161 -> V_172 ;
V_204 . V_31 = V_26 -> V_31 ;
V_204 . V_32 = V_26 -> V_32 ;
V_204 . V_213 = V_26 -> V_161 -> V_77 ;
V_204 . V_214 = V_26 -> T_1 -> V_222 ;
V_204 . V_216 = V_26 -> T_1 -> V_222 ;
V_204 . V_150 = V_26 -> V_161 -> V_223 - V_26 -> V_224 ;
V_204 . V_30 = V_26 -> V_30 ;
V_204 . V_162 = V_26 -> V_162 ;
V_204 . V_171 = V_26 -> V_171 ;
V_26 -> V_224 = V_26 -> V_161 -> V_223 ;
if ( T_1 -> V_128 . V_129 ) {
F_76 ( V_26 -> V_34 , V_26 -> V_133 ,
T_1 -> V_128 . V_132 , V_204 . V_76 ) ;
V_204 . V_129 = V_26 -> V_133 ;
}
if ( T_1 -> V_128 . V_135 ) {
F_65 ( V_26 ) ;
V_204 . V_136 = V_26 -> V_135 ;
}
if ( T_1 -> V_128 . V_219 ) {
V_8 = F_68 ( V_202 , & V_204 ,
T_1 -> V_225 ,
T_1 -> V_221 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_73 ( T_1 -> V_42 , V_202 , & V_204 ) ;
if ( V_8 )
F_74 ( L_17 ,
V_8 ) ;
if ( T_1 -> V_128 . V_135 )
F_66 ( V_26 ) ;
return V_8 ;
}
static int F_77 ( struct V_25 * V_26 )
{
int V_8 ;
struct V_1 * T_1 = V_26 -> T_1 ;
union V_201 * V_202 = V_26 -> V_140 ;
struct V_203 V_204 = { . V_76 = 0 , } ;
V_202 -> V_204 . V_206 . type = V_210 ;
V_202 -> V_204 . V_206 . V_211 = V_90 ;
V_202 -> V_204 . V_206 . V_20 = sizeof( struct V_212 ) ;
if ( ! T_1 -> V_114 )
V_204 . time = F_72 ( V_26 -> V_184 , & T_1 -> V_122 ) ;
V_204 . V_76 = V_26 -> V_161 -> V_172 ;
V_204 . V_31 = V_26 -> V_31 ;
V_204 . V_32 = V_26 -> V_32 ;
V_204 . V_213 = V_26 -> V_161 -> V_77 ;
V_204 . V_214 = V_26 -> T_1 -> V_226 ;
V_204 . V_216 = V_26 -> T_1 -> V_226 ;
V_204 . V_150 = 1 ;
V_204 . V_30 = V_26 -> V_30 ;
V_204 . V_162 = V_26 -> V_162 ;
V_204 . V_171 = V_26 -> V_171 ;
if ( T_1 -> V_128 . V_129 ) {
F_76 ( V_26 -> V_34 , V_26 -> V_133 ,
T_1 -> V_128 . V_132 , V_204 . V_76 ) ;
V_204 . V_129 = V_26 -> V_133 ;
}
if ( T_1 -> V_128 . V_135 ) {
F_65 ( V_26 ) ;
V_204 . V_136 = V_26 -> V_135 ;
}
if ( T_1 -> V_128 . V_219 ) {
V_8 = F_68 ( V_202 , & V_204 ,
T_1 -> V_227 ,
T_1 -> V_221 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_73 ( T_1 -> V_42 , V_202 , & V_204 ) ;
if ( V_8 )
F_74 ( L_18 ,
V_8 ) ;
if ( T_1 -> V_128 . V_129 )
F_66 ( V_26 ) ;
return V_8 ;
}
static int F_78 ( struct V_1 * T_1 , int V_228 , int V_30 ,
T_8 V_31 , T_8 V_32 , T_4 V_76 )
{
union V_201 V_202 ;
char V_229 [ V_230 ] ;
int V_69 ;
F_79 ( V_228 , V_229 , V_230 ) ;
F_80 ( & V_202 . V_231 , V_232 ,
V_228 , V_30 , V_31 , V_32 , V_76 , V_229 ) ;
V_69 = F_73 ( T_1 -> V_42 , & V_202 , NULL ) ;
if ( V_69 )
F_74 ( L_19 ,
V_69 ) ;
return V_69 ;
}
static int F_81 ( struct V_1 * T_1 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
T_8 V_32 = V_26 -> V_142 ;
int V_69 ;
if ( V_32 == - 1 )
return 0 ;
F_9 ( L_20 , V_26 -> V_30 , V_32 ) ;
V_69 = F_82 ( T_1 -> V_35 , V_26 -> V_30 , - 1 , V_32 ) ;
V_28 = & T_1 -> V_39 . V_40 [ V_26 -> V_33 ] ;
F_56 ( T_1 , V_28 ) ;
V_26 -> V_142 = - 1 ;
return V_69 ;
}
static inline bool F_83 ( struct V_25 * V_26 , T_4 V_76 )
{
struct V_1 * T_1 = V_26 -> T_1 ;
return V_76 == T_1 -> V_233 &&
( V_26 -> V_162 & V_164 ) &&
! ( V_26 -> V_162 & ( V_234 | V_168 |
V_169 | V_165 ) ) ;
}
static int F_84 ( struct V_25 * V_26 )
{
const struct V_182 * V_161 = V_26 -> V_161 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_69 ;
if ( ! V_26 -> V_186 )
return 0 ;
V_26 -> V_186 = false ;
if ( T_1 -> V_235 &&
( V_161 -> type & V_236 ) ) {
V_69 = F_75 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_237 &&
( V_161 -> type & V_238 ) ) {
V_69 = F_77 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( ! ( V_161 -> type & V_239 ) )
return 0 ;
if ( T_1 -> V_128 . V_129 )
F_85 ( V_26 -> V_34 , V_26 -> V_162 , V_161 -> V_172 ,
V_161 -> V_77 , V_26 -> V_171 ,
V_161 -> V_50 ) ;
else
F_86 ( V_26 -> V_34 , V_161 -> V_50 ) ;
if ( T_1 -> V_240 ) {
V_69 = F_71 ( V_26 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_128 . V_135 )
F_67 ( V_26 ) ;
if ( ! T_1 -> V_179 )
return 0 ;
if ( F_83 ( V_26 , V_161 -> V_77 ) ) {
switch ( V_26 -> V_180 ) {
case V_241 :
case V_242 :
V_69 = F_81 ( T_1 , V_26 ) ;
if ( V_69 )
return V_69 ;
V_26 -> V_180 = V_243 ;
break;
default:
V_26 -> V_180 = V_181 ;
return 1 ;
}
} else if ( ! V_161 -> V_77 ) {
V_26 -> V_180 = V_244 ;
} else if ( V_26 -> V_180 == V_244 ) {
V_26 -> V_180 = V_241 ;
} else if ( V_26 -> V_180 == V_241 &&
V_161 -> V_77 == T_1 -> V_245 &&
( V_26 -> V_162 & V_167 ) ) {
V_26 -> V_180 = V_243 ;
}
return 0 ;
}
static T_4 F_87 ( struct V_1 * T_1 , T_4 * V_245 )
{
struct V_35 * V_35 = T_1 -> V_35 ;
struct V_93 * V_93 ;
struct V_246 * V_247 , * V_18 ;
T_4 V_76 , V_233 = 0 ;
const char * V_248 ;
if ( V_245 )
* V_245 = 0 ;
V_93 = F_88 ( V_35 ) ;
if ( ! V_93 )
return 0 ;
if ( F_37 ( V_93 , V_35 -> V_99 ) )
return 0 ;
V_18 = F_89 ( V_93 -> V_59 , V_92 ) ;
for ( V_247 = V_18 ; V_247 ; V_247 = F_90 ( V_247 ) ) {
if ( V_247 -> V_249 == V_250 &&
! strcmp ( V_247 -> V_251 , L_21 ) ) {
V_76 = V_93 -> V_252 ( V_93 , V_247 -> V_18 ) ;
if ( V_76 >= V_93 -> V_18 && V_76 < V_93 -> V_103 ) {
V_233 = V_76 ;
break;
}
}
}
if ( ! V_233 || ! V_245 )
return 0 ;
if ( T_1 -> V_159 == 1 )
V_248 = L_22 ;
else
V_248 = L_23 ;
for ( V_247 = V_18 ; V_247 ; V_247 = F_90 ( V_247 ) ) {
if ( ! strcmp ( V_247 -> V_251 , V_248 ) ) {
V_76 = V_93 -> V_252 ( V_93 , V_247 -> V_18 ) ;
if ( V_76 >= V_93 -> V_18 && V_76 < V_93 -> V_103 ) {
* V_245 = V_76 ;
break;
}
}
}
return V_233 ;
}
static int F_91 ( struct V_25 * V_26 , T_4 * V_184 )
{
const struct V_182 * V_161 = V_26 -> V_161 ;
struct V_1 * T_1 = V_26 -> T_1 ;
int V_69 ;
if ( ! T_1 -> V_88 ) {
T_1 -> V_88 = F_92 ( T_1 -> V_35 ) ;
if ( T_1 -> V_253 &&
( T_1 -> V_159 == 1 || T_1 -> V_159 == 3 ) &&
! T_1 -> V_114 && F_47 ( T_1 ) &&
! T_1 -> V_49 ) {
T_1 -> V_233 = F_87 ( T_1 , & T_1 -> V_245 ) ;
if ( T_1 -> V_233 ) {
F_9 ( L_24 V_185 L_25 V_185 L_15 ,
T_1 -> V_233 , T_1 -> V_245 ) ;
T_1 -> V_179 = true ;
}
}
}
F_9 ( L_12 ,
V_26 -> V_33 , V_26 -> V_30 , V_26 -> V_31 , V_26 -> V_32 ) ;
while ( 1 ) {
V_69 = F_84 ( V_26 ) ;
if ( V_69 )
return V_69 ;
V_161 = F_62 ( V_26 -> V_157 ) ;
if ( V_161 -> V_69 ) {
if ( V_161 -> V_69 == V_183 )
return 1 ;
if ( T_1 -> V_179 &&
V_161 -> V_172 >= T_1 -> V_88 ) {
T_1 -> V_179 = false ;
F_81 ( T_1 , V_26 ) ;
}
if ( T_1 -> V_128 . V_254 ) {
V_69 = F_78 ( T_1 , V_161 -> V_69 ,
V_26 -> V_30 , V_26 -> V_31 ,
V_26 -> V_32 ,
V_161 -> V_172 ) ;
if ( V_69 )
return V_69 ;
}
continue;
}
V_26 -> V_161 = V_161 ;
V_26 -> V_186 = true ;
F_58 ( V_26 ) ;
if ( T_1 -> V_255 &&
( V_161 -> V_172 >= T_1 -> V_88 || ! V_161 -> V_172 ) &&
V_161 -> V_77 && V_161 -> V_77 < T_1 -> V_88 ) {
F_9 ( L_26 V_185 L_27 V_185 L_15 ,
V_161 -> V_184 , V_161 -> V_256 ) ;
V_26 -> V_184 = V_161 -> V_256 ;
} else if ( T_1 -> V_179 &&
V_26 -> V_180 == V_241 &&
F_83 ( V_26 , V_161 -> V_77 ) &&
V_26 -> V_142 == - 1 ) {
F_9 ( L_26 V_185 L_27 V_185 L_15 ,
V_161 -> V_184 , V_161 -> V_256 ) ;
V_26 -> V_184 = V_161 -> V_256 ;
} else if ( V_161 -> V_184 > V_26 -> V_184 ) {
V_26 -> V_184 = V_161 -> V_184 ;
}
if ( ! T_1 -> V_114 && V_26 -> V_184 >= * V_184 ) {
* V_184 = V_26 -> V_184 ;
return 0 ;
}
}
return 0 ;
}
static inline int F_93 ( struct V_1 * T_1 )
{
if ( T_1 -> V_39 . V_257 ) {
T_1 -> V_39 . V_257 = false ;
return F_64 ( T_1 ) ;
}
return 0 ;
}
static int F_94 ( struct V_1 * T_1 , T_4 V_184 )
{
unsigned int V_33 ;
T_4 V_258 ;
int V_8 ;
while ( 1 ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
if ( ! T_1 -> V_187 . V_259 )
return 0 ;
if ( T_1 -> V_187 . V_260 [ 0 ] . V_261 >= V_184 )
return 0 ;
V_33 = T_1 -> V_187 . V_260 [ 0 ] . V_33 ;
V_28 = & T_1 -> V_39 . V_40 [ V_33 ] ;
V_26 = V_28 -> V_158 ;
F_9 ( L_28 V_185 L_29 V_185 L_15 ,
V_33 , T_1 -> V_187 . V_260 [ 0 ] . V_261 ,
V_184 ) ;
F_95 ( & T_1 -> V_187 ) ;
if ( T_1 -> V_187 . V_259 ) {
V_258 = T_1 -> V_187 . V_260 [ 0 ] . V_261 + 1 ;
if ( V_258 > V_184 )
V_258 = V_184 ;
} else {
V_258 = V_184 ;
}
F_56 ( T_1 , V_28 ) ;
V_8 = F_91 ( V_26 , & V_258 ) ;
if ( V_8 < 0 ) {
F_63 ( & T_1 -> V_187 , V_33 , V_258 ) ;
return V_8 ;
}
if ( ! V_8 ) {
V_8 = F_63 ( & T_1 -> V_187 , V_33 , V_258 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_26 -> V_178 = false ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * T_1 , T_8 V_32 ,
T_4 V_262 )
{
struct V_263 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
T_4 V_258 = 0 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_188 ; V_10 ++ ) {
struct V_27 * V_28 = & T_1 -> V_39 . V_40 [ V_10 ] ;
struct V_25 * V_26 = V_28 -> V_158 ;
if ( V_26 && ( V_32 == - 1 || V_26 -> V_32 == V_32 ) ) {
V_26 -> time = V_262 ;
F_56 ( T_1 , V_28 ) ;
F_91 ( V_26 , & V_258 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_1 * T_1 , struct V_203 * V_204 )
{
return F_78 ( T_1 , V_264 , V_204 -> V_30 ,
V_204 -> V_31 , V_204 -> V_32 , 0 ) ;
}
static struct V_25 * F_98 ( struct V_1 * T_1 , int V_30 )
{
unsigned V_10 , V_265 ;
if ( V_30 < 0 || ! T_1 -> V_39 . V_188 )
return NULL ;
if ( ( unsigned ) V_30 >= T_1 -> V_39 . V_188 )
V_10 = T_1 -> V_39 . V_188 - 1 ;
else
V_10 = V_30 ;
if ( T_1 -> V_39 . V_40 [ V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_158 ;
for ( V_265 = 0 ; V_10 > 0 ; V_265 ++ ) {
if ( T_1 -> V_39 . V_40 [ -- V_10 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_10 ] . V_158 ;
}
for (; V_265 < T_1 -> V_39 . V_188 ; V_265 ++ ) {
if ( T_1 -> V_39 . V_40 [ V_265 ] . V_30 == V_30 )
return T_1 -> V_39 . V_40 [ V_265 ] . V_158 ;
}
return NULL ;
}
static int F_99 ( struct V_1 * T_1 , int V_30 , T_8 V_32 ,
T_4 V_184 )
{
struct V_25 * V_26 ;
int V_69 ;
if ( ! T_1 -> V_179 )
return 1 ;
V_26 = F_98 ( T_1 , V_30 ) ;
if ( ! V_26 )
return 1 ;
switch ( V_26 -> V_180 ) {
case V_244 :
V_26 -> V_142 = - 1 ;
break;
case V_241 :
case V_243 :
V_26 -> V_142 = V_32 ;
V_26 -> V_180 = V_242 ;
return 0 ;
case V_181 :
if ( ! V_26 -> V_178 ) {
V_26 -> V_184 = F_100 ( V_184 ,
& T_1 -> V_122 ) ;
V_69 = F_63 ( & T_1 -> V_187 , V_26 -> V_33 ,
V_26 -> V_184 ) ;
if ( V_69 )
return V_69 ;
V_26 -> V_178 = true ;
}
V_26 -> V_180 = V_243 ;
break;
case V_242 :
V_26 -> V_142 = V_32 ;
F_9 ( L_30 , V_30 ) ;
break;
default:
break;
}
return 1 ;
}
static int F_101 ( struct V_1 * T_1 ,
struct V_203 * V_204 )
{
struct V_108 * V_109 ;
T_8 V_32 ;
int V_30 , V_8 ;
V_109 = F_102 ( T_1 -> V_42 -> V_266 , V_204 -> V_214 ) ;
if ( V_109 != T_1 -> V_267 )
return 0 ;
V_32 = F_103 ( V_109 , V_204 , L_31 ) ;
V_30 = V_204 -> V_30 ;
F_9 ( L_32 V_268 L_33 V_185 L_15 ,
V_30 , V_32 , V_204 -> time , F_100 ( V_204 -> time ,
& T_1 -> V_122 ) ) ;
V_8 = F_99 ( T_1 , V_30 , V_32 , V_204 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_82 ( T_1 -> V_35 , V_30 , - 1 , V_32 ) ;
}
static int F_104 ( struct V_1 * T_1 , union V_201 * V_202 ,
struct V_203 * V_204 )
{
bool V_102 = V_202 -> V_206 . V_211 & V_269 ;
T_8 V_31 , V_32 ;
int V_30 , V_8 ;
V_30 = V_204 -> V_30 ;
if ( T_1 -> V_159 == 3 ) {
if ( ! V_102 )
return 0 ;
if ( V_202 -> V_206 . type != V_270 ) {
F_74 ( L_34 ) ;
return - V_22 ;
}
V_31 = V_202 -> V_271 . V_272 ;
V_32 = V_202 -> V_271 . V_273 ;
} else {
if ( V_102 )
return 0 ;
V_31 = V_204 -> V_31 ;
V_32 = V_204 -> V_32 ;
}
if ( V_32 == - 1 ) {
F_74 ( L_35 ) ;
return - V_22 ;
}
F_9 ( L_36 V_268 L_33 V_185 L_15 ,
V_30 , V_31 , V_32 , V_204 -> time , F_100 ( V_204 -> time ,
& T_1 -> V_122 ) ) ;
V_8 = F_99 ( T_1 , V_30 , V_32 , V_204 -> time ) ;
if ( V_8 <= 0 )
return V_8 ;
return F_82 ( T_1 -> V_35 , V_30 , V_31 , V_32 ) ;
}
static int F_105 ( struct V_1 * T_1 ,
union V_201 * V_202 ,
struct V_203 * V_204 )
{
if ( ! T_1 -> V_253 )
return 0 ;
F_9 ( L_37 V_268 L_33 V_185 L_15 ,
V_204 -> V_30 , V_202 -> V_274 . V_31 ,
V_202 -> V_274 . V_32 , V_204 -> time ,
F_100 ( V_204 -> time , & T_1 -> V_122 ) ) ;
return F_82 ( T_1 -> V_35 , V_204 -> V_30 ,
V_202 -> V_274 . V_31 ,
V_202 -> V_274 . V_32 ) ;
}
static int F_106 ( struct V_275 * V_42 ,
union V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_276 * V_277 )
{
struct V_1 * T_1 = F_107 ( V_42 -> V_278 , struct V_1 ,
V_278 ) ;
T_4 V_184 ;
int V_69 = 0 ;
if ( V_279 )
return 0 ;
if ( ! V_277 -> V_280 ) {
F_74 ( L_38 ) ;
return - V_22 ;
}
if ( V_204 -> time && V_204 -> time != ( T_4 ) - 1 )
V_184 = F_100 ( V_204 -> time , & T_1 -> V_122 ) ;
else
V_184 = 0 ;
if ( V_184 || T_1 -> V_114 ) {
V_69 = F_93 ( T_1 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_114 ) {
if ( V_202 -> V_206 . type == V_281 ) {
V_69 = F_96 ( T_1 ,
V_202 -> V_282 . V_32 ,
V_204 -> time ) ;
}
} else if ( V_184 ) {
V_69 = F_94 ( T_1 , V_184 ) ;
}
if ( V_69 )
return V_69 ;
if ( V_202 -> V_206 . type == V_283 &&
( V_202 -> V_284 . V_162 & V_285 ) &&
T_1 -> V_128 . V_254 ) {
V_69 = F_97 ( T_1 , V_204 ) ;
if ( V_69 )
return V_69 ;
}
if ( T_1 -> V_267 && V_202 -> V_206 . type == V_210 )
V_69 = F_101 ( T_1 , V_204 ) ;
else if ( V_202 -> V_206 . type == V_286 )
V_69 = F_105 ( T_1 , V_202 , V_204 ) ;
else if ( V_202 -> V_206 . type == V_287 ||
V_202 -> V_206 . type == V_270 )
V_69 = F_104 ( T_1 , V_202 , V_204 ) ;
F_9 ( L_39 V_268 L_33 V_185 L_15 ,
F_108 ( V_202 -> V_206 . type ) , V_202 -> V_206 . type ,
V_204 -> V_30 , V_204 -> time , V_184 ) ;
return V_69 ;
}
static int F_109 ( struct V_275 * V_42 , struct V_276 * V_277 )
{
struct V_1 * T_1 = F_107 ( V_42 -> V_278 , struct V_1 ,
V_278 ) ;
int V_8 ;
if ( V_279 )
return 0 ;
if ( ! V_277 -> V_280 )
return - V_22 ;
V_8 = F_93 ( T_1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( T_1 -> V_114 )
return F_96 ( T_1 , - 1 ,
V_288 - 1 ) ;
return F_94 ( T_1 , V_288 ) ;
}
static void F_110 ( struct V_275 * V_42 )
{
struct V_1 * T_1 = F_107 ( V_42 -> V_278 , struct V_1 ,
V_278 ) ;
struct V_263 * V_39 = & T_1 -> V_39 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_188 ; V_10 ++ ) {
F_54 ( V_39 -> V_40 [ V_10 ] . V_158 ) ;
V_39 -> V_40 [ V_10 ] . V_158 = NULL ;
}
F_111 () ;
F_112 ( V_39 ) ;
}
static void F_113 ( struct V_275 * V_42 )
{
struct V_1 * T_1 = F_107 ( V_42 -> V_278 , struct V_1 ,
V_278 ) ;
F_114 ( & T_1 -> V_187 ) ;
F_110 ( V_42 ) ;
V_42 -> V_278 = NULL ;
F_115 ( T_1 -> V_91 ) ;
free ( T_1 ) ;
}
static int F_116 ( struct V_275 * V_42 ,
union V_201 * V_202 ,
struct V_276 * V_277 V_2 )
{
struct V_1 * T_1 = F_107 ( V_42 -> V_278 , struct V_1 ,
V_278 ) ;
if ( T_1 -> V_49 )
return 0 ;
if ( ! T_1 -> V_289 ) {
struct V_15 * V_29 ;
T_3 V_290 ;
int V_41 = F_16 ( V_42 -> V_43 ) ;
int V_69 ;
if ( F_117 ( V_42 -> V_43 ) ) {
V_290 = 0 ;
} else {
V_290 = F_118 ( V_41 , 0 , V_291 ) ;
if ( V_290 == - 1 )
return - V_292 ;
}
V_69 = F_119 ( & T_1 -> V_39 , V_42 , V_202 ,
V_290 , & V_29 ) ;
if ( V_69 )
return V_69 ;
if ( V_279 ) {
if ( F_17 ( V_29 , V_41 ) ) {
F_5 ( T_1 , V_29 -> V_19 ,
V_29 -> V_20 ) ;
F_120 ( V_29 ) ;
}
}
}
return 0 ;
}
static int F_121 ( struct V_276 * V_277 ,
union V_201 * V_202 ,
struct V_203 * V_204 V_2 ,
struct V_35 * V_35 V_2 )
{
struct V_293 * V_293 =
F_107 ( V_277 , struct V_293 , V_294 ) ;
return F_73 ( V_293 -> V_42 , V_202 ,
NULL ) ;
}
static int F_122 ( struct V_275 * V_42 ,
struct V_104 * V_105 , T_4 V_214 )
{
struct V_293 V_293 ;
memset ( & V_293 , 0 , sizeof( struct V_293 ) ) ;
V_293 . V_42 = V_42 ;
return F_123 ( & V_293 . V_294 , V_105 , 1 ,
& V_214 , F_121 ) ;
}
static int F_124 ( struct V_1 * T_1 ,
struct V_275 * V_42 )
{
struct V_295 * V_266 = V_42 -> V_266 ;
struct V_108 * V_109 ;
struct V_104 V_105 ;
bool V_296 = false ;
T_4 V_214 ;
int V_69 ;
F_43 (evlist, evsel) {
if ( V_109 -> V_105 . type == T_1 -> V_107 && V_109 -> V_297 ) {
V_296 = true ;
break;
}
}
if ( ! V_296 ) {
F_125 ( L_40 ) ;
return 0 ;
}
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
V_105 . V_20 = sizeof( struct V_104 ) ;
V_105 . type = V_298 ;
V_105 . V_117 = V_109 -> V_105 . V_117 & V_299 ;
V_105 . V_117 |= V_300 | V_301 |
V_302 ;
if ( T_1 -> V_114 )
V_105 . V_117 &= ~ ( T_4 ) V_118 ;
else
V_105 . V_117 |= V_118 ;
if ( ! T_1 -> V_253 )
V_105 . V_117 &= ~ ( T_4 ) V_303 ;
V_105 . V_304 = V_109 -> V_105 . V_304 ;
V_105 . V_110 = V_109 -> V_105 . V_110 ;
V_105 . V_305 = V_109 -> V_105 . V_305 ;
V_105 . V_306 = V_109 -> V_105 . V_306 ;
V_105 . V_307 = V_109 -> V_105 . V_307 ;
V_105 . V_308 = V_109 -> V_105 . V_308 ;
V_105 . V_309 = V_109 -> V_105 . V_309 ;
V_214 = V_109 -> V_214 [ 0 ] + 1000000000 ;
if ( ! V_214 )
V_214 = 1 ;
if ( T_1 -> V_128 . V_149 ) {
V_105 . V_106 = V_310 ;
if ( T_1 -> V_128 . V_151 == V_156 )
V_105 . V_311 =
F_49 ( T_1 , T_1 -> V_128 . V_150 ) ;
else
V_105 . V_311 = T_1 -> V_128 . V_150 ;
T_1 -> V_312 = V_105 . V_311 ;
if ( T_1 -> V_128 . V_129 )
V_105 . V_117 |= V_313 ;
if ( T_1 -> V_128 . V_135 )
V_105 . V_117 |= V_314 ;
F_125 ( L_41 V_268 L_42 V_185 L_15 ,
V_214 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_122 ( V_42 , & V_105 , V_214 ) ;
if ( V_69 ) {
F_74 ( L_43 ,
V_315 ) ;
return V_69 ;
}
T_1 -> V_235 = true ;
T_1 -> V_225 = V_105 . V_117 ;
T_1 -> V_222 = V_214 ;
V_214 += 1 ;
}
if ( T_1 -> V_128 . V_316 ) {
V_105 . V_106 = V_310 ;
V_105 . V_311 = 1 ;
if ( T_1 -> V_128 . V_129 )
V_105 . V_117 |= V_313 ;
if ( T_1 -> V_128 . V_135 )
V_105 . V_117 |= V_314 ;
F_125 ( L_44 V_268 L_42 V_185 L_15 ,
V_214 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_122 ( V_42 , & V_105 , V_214 ) ;
if ( V_69 ) {
F_74 ( L_45 ,
V_315 ) ;
return V_69 ;
}
T_1 -> V_237 = true ;
T_1 -> V_226 = V_214 ;
V_214 += 1 ;
F_43 (evlist, evsel) {
if ( V_109 -> V_214 && V_109 -> V_214 [ 0 ] == T_1 -> V_226 ) {
if ( V_109 -> V_251 )
F_53 ( & V_109 -> V_251 ) ;
V_109 -> V_251 = F_126 ( L_46 ) ;
break;
}
}
}
if ( T_1 -> V_128 . V_317 ) {
V_105 . V_106 = V_318 ;
V_105 . V_311 = 1 ;
V_105 . V_117 |= V_319 ;
V_105 . V_117 &= ~ ( T_4 ) V_313 ;
V_105 . V_117 &= ~ ( T_4 ) V_314 ;
F_125 ( L_47 V_268 L_42 V_185 L_15 ,
V_214 , ( T_4 ) V_105 . V_117 ) ;
V_69 = F_122 ( V_42 , & V_105 , V_214 ) ;
if ( V_69 ) {
F_74 ( L_48 ,
V_315 ) ;
return V_69 ;
}
T_1 -> V_240 = true ;
T_1 -> V_220 = V_105 . V_117 ;
T_1 -> V_215 = V_214 ;
}
T_1 -> V_221 = V_109 -> V_320 ;
return 0 ;
}
static struct V_108 * F_127 ( struct V_295 * V_266 )
{
struct V_108 * V_109 ;
F_128 (evlist, evsel) {
const char * V_251 = F_129 ( V_109 ) ;
if ( ! strcmp ( V_251 , L_49 ) )
return V_109 ;
}
return NULL ;
}
static bool F_130 ( struct V_295 * V_266 )
{
struct V_108 * V_109 ;
F_43 (evlist, evsel) {
if ( V_109 -> V_105 . V_271 )
return true ;
}
return false ;
}
static int F_131 ( const char * V_54 , const char * V_55 , void * V_19 )
{
struct V_1 * T_1 = V_19 ;
if ( ! strcmp ( V_54 , L_50 ) )
T_1 -> V_200 = F_132 ( V_54 , V_55 ) ;
return 0 ;
}
static void F_133 ( T_4 * V_321 , int V_18 , int V_322 )
{
int V_10 ;
if ( ! V_279 )
return;
for ( V_10 = V_18 ; V_10 <= V_322 ; V_10 ++ )
fprintf ( stdout , V_323 [ V_10 ] , V_321 [ V_10 ] ) ;
}
int F_134 ( union V_201 * V_202 ,
struct V_275 * V_42 )
{
struct V_324 * V_325 = & V_202 -> V_325 ;
T_2 V_326 = sizeof( T_4 ) * V_327 ;
struct V_1 * T_1 ;
int V_69 ;
if ( V_325 -> V_206 . V_20 < sizeof( struct V_324 ) +
V_326 )
return - V_22 ;
T_1 = F_51 ( sizeof( struct V_1 ) ) ;
if ( ! T_1 )
return - V_44 ;
F_20 ( F_131 , T_1 ) ;
V_69 = F_135 ( & T_1 -> V_39 ) ;
if ( V_69 )
goto V_328;
F_136 ( V_329 ) ;
T_1 -> V_42 = V_42 ;
T_1 -> V_35 = & V_42 -> V_330 . V_331 ;
T_1 -> V_332 = V_325 -> type ;
T_1 -> V_107 = V_325 -> V_158 [ V_333 ] ;
T_1 -> V_122 . V_124 = V_325 -> V_158 [ V_334 ] ;
T_1 -> V_122 . V_123 = V_325 -> V_158 [ V_335 ] ;
T_1 -> V_122 . V_336 = V_325 -> V_158 [ V_337 ] ;
T_1 -> V_116 = V_325 -> V_158 [ V_338 ] ;
T_1 -> V_115 = V_325 -> V_158 [ V_339 ] ;
T_1 -> V_111 = V_325 -> V_158 [ V_340 ] ;
T_1 -> V_159 = V_325 -> V_158 [ V_341 ] ;
T_1 -> V_45 = V_325 -> V_158 [ V_342 ] ;
T_1 -> V_253 = V_325 -> V_158 [ V_327 ] ;
F_133 ( & V_325 -> V_158 [ 0 ] , V_333 ,
V_327 ) ;
if ( V_325 -> V_206 . V_20 >= sizeof( struct V_324 ) +
( sizeof( T_4 ) * V_343 ) ) {
T_1 -> V_344 = V_325 -> V_158 [ V_345 ] ;
T_1 -> V_113 = V_325 -> V_158 [ V_346 ] ;
T_1 -> V_147 = V_325 -> V_158 [ V_347 ] ;
T_1 -> V_148 = V_325 -> V_158 [ V_348 ] ;
T_1 -> V_349 = V_325 -> V_158 [ V_343 ] ;
F_133 ( & V_325 -> V_158 [ 0 ] , V_345 ,
V_343 ) ;
}
T_1 -> V_114 = F_46 ( T_1 ) ;
T_1 -> V_21 = F_48 ( T_1 ) ;
T_1 -> V_49 = false ;
T_1 -> V_255 = ! T_1 -> V_114 ;
T_1 -> V_91 = F_137 ( 999999999 , 999999999 ) ;
if ( ! T_1 -> V_91 ) {
V_69 = - V_44 ;
goto V_350;
}
F_138 ( & T_1 -> V_91 -> V_351 ) ;
V_69 = F_139 ( T_1 -> V_91 , L_51 , 0 ) ;
if ( V_69 )
goto V_352;
if ( F_140 ( T_1 -> V_91 , T_1 -> V_35 ) ) {
V_69 = - V_44 ;
goto V_352;
}
T_1 -> V_278 . V_353 = F_106 ;
T_1 -> V_278 . V_354 = F_116 ;
T_1 -> V_278 . V_355 = F_109 ;
T_1 -> V_278 . V_356 = F_110 ;
T_1 -> V_278 . free = F_113 ;
V_42 -> V_278 = & T_1 -> V_278 ;
if ( V_279 )
return 0 ;
if ( T_1 -> V_159 == 1 ) {
T_1 -> V_267 = F_127 ( V_42 -> V_266 ) ;
if ( ! T_1 -> V_267 ) {
F_74 ( L_52 , V_315 ) ;
goto V_352;
}
} else if ( T_1 -> V_159 == 2 &&
! F_130 ( V_42 -> V_266 ) ) {
F_74 ( L_53 , V_315 ) ;
goto V_352;
}
if ( V_42 -> V_357 && V_42 -> V_357 -> V_358 ) {
T_1 -> V_128 = * V_42 -> V_357 ;
} else {
F_141 ( & T_1 -> V_128 ) ;
if ( V_359 != - 1 ) {
T_1 -> V_128 . V_317 = false ;
T_1 -> V_128 . V_129 = true ;
}
}
if ( T_1 -> V_128 . log )
F_142 () ;
if ( T_1 -> V_122 . V_123 ) {
T_4 V_360 = F_49 ( T_1 , 1000000000 ) ;
T_1 -> V_145 = ( V_360 + 50000000 ) / 100000000 ;
F_9 ( L_54 V_268 L_15 , V_360 ) ;
F_9 ( L_55 ,
T_1 -> V_145 ) ;
}
if ( T_1 -> V_128 . V_361 )
T_1 -> V_209 |= V_167 | V_168 |
V_170 ;
if ( T_1 -> V_128 . V_362 )
T_1 -> V_209 |= V_363 |
V_174 ;
if ( T_1 -> V_128 . V_129 && ! V_364 . V_365 ) {
V_364 . V_365 = true ;
if ( F_143 ( & V_366 ) < 0 ) {
V_364 . V_365 = false ;
T_1 -> V_128 . V_129 = false ;
}
}
V_69 = F_124 ( T_1 , V_42 ) ;
if ( V_69 )
goto V_352;
V_69 = F_144 ( & T_1 -> V_39 , V_42 ) ;
if ( V_69 )
goto V_352;
if ( T_1 -> V_39 . V_367 )
T_1 -> V_289 = true ;
if ( T_1 -> V_114 )
F_145 ( L_56 ) ;
return 0 ;
V_352:
F_10 ( T_1 -> V_91 ) ;
V_350:
F_111 () ;
F_112 ( & T_1 -> V_39 ) ;
V_42 -> V_278 = NULL ;
V_328:
free ( T_1 ) ;
return V_69 ;
}
