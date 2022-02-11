static void F_1 ( const char * V_1 )
{
F_2 () ;
F_3 ( L_1 ) ;
abort () ;
}
static void F_4 ( T_1 * V_2 , const char * V_3 , T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_4 ) ;
}
static T_1 * F_7 ( const char * V_1 )
{
T_1 * V_5 ;
V_5 = F_8 ( V_6 , V_1 ) ;
if ( V_5 && ! F_9 ( V_5 ) )
return NULL ;
return V_5 ;
}
static void F_10 ( T_1 * V_5 , T_1 * args , const char * V_7 )
{
T_1 * V_8 ;
V_8 = F_11 ( V_5 , args ) ;
if ( V_8 == NULL )
F_1 ( V_7 ) ;
F_6 ( V_8 ) ;
}
static void F_12 ( const char * V_1 , T_1 * args )
{
T_1 * V_5 ;
V_5 = F_7 ( V_1 ) ;
if ( V_5 )
F_10 ( V_5 , args , V_1 ) ;
}
static void F_13 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_13 ,
const char * V_14 )
{
const char * V_1 = L_2 ;
T_1 * V_15 ;
unsigned long long V_16 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_3 ;
V_15 = F_14 ( 4 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_16 = F_15 ( V_13 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_16 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_14 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_19 ( enum V_9 V_10 ,
struct V_19 * V_20 ,
const char * V_11 ,
const char * V_12 )
{
F_13 ( V_10 , V_11 , V_12 , V_20 -> V_16 ,
V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
F_19 ( V_10 , V_20 -> V_22 , V_11 , V_12 ) ;
}
static void F_20 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_23 )
{
const char * V_1 = L_5 ;
T_1 * V_15 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_6 ;
if ( V_10 == V_24 )
V_15 = F_14 ( 3 ) ;
else
V_15 = F_14 ( 2 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
if ( V_10 == V_24 )
F_16 ( V_15 , V_17 ++ , F_17 ( V_23 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_21 ( struct V_25 * V_26 ,
const char * V_11 ,
struct V_27 * args )
{
if ( args == NULL )
return;
switch ( args -> type ) {
case V_28 :
break;
case V_29 :
F_13 ( V_24 , V_11 , V_30 , L_7 ,
args -> V_31 . V_31 ) ;
V_32 = 0 ;
break;
case V_33 :
free ( V_30 ) ;
V_30 = F_22 ( args -> V_20 . V_34 ) ;
break;
case V_24 :
F_21 ( V_26 , V_11 , args -> V_35 . V_20 ) ;
F_20 ( V_24 , V_11 , V_30 ,
args -> V_35 . V_23 ) ;
F_19 ( V_24 , args -> V_35 . V_35 , V_11 ,
V_30 ) ;
break;
case V_18 :
F_21 ( V_26 , V_11 , args -> V_36 . V_20 ) ;
F_20 ( V_18 , V_11 , V_30 , NULL ) ;
F_19 ( V_18 , args -> V_36 . V_37 , V_11 ,
V_30 ) ;
break;
case V_38 :
F_21 ( V_26 , V_11 , args -> V_39 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_39 . V_40 ) ;
break;
case V_41 :
F_21 ( V_26 , V_11 , args -> V_42 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_42 . V_43 ) ;
F_21 ( V_26 , V_11 , args -> V_42 . V_44 ) ;
break;
case V_45 :
break;
case V_46 :
F_21 ( V_26 , V_11 , args -> V_47 . V_48 ) ;
break;
case V_49 :
if ( strcmp ( args -> V_50 . V_50 , L_8 ) == 0 )
V_32 = 1 ;
F_21 ( V_26 , V_11 , args -> V_50 . V_51 ) ;
F_21 ( V_26 , V_11 , args -> V_50 . V_52 ) ;
break;
default:
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static T_1 * F_23 ( struct V_25 * V_26 ,
struct V_58 * V_20 , void * V_59 )
{
bool V_60 = V_20 -> V_35 & V_61 ;
T_1 * V_62 , * V_63 = NULL ;
unsigned long long V_4 ;
unsigned int V_64 , V_65 , V_66 ;
if ( V_60 ) {
V_63 = F_24 ( V_20 -> V_67 ) ;
V_64 = V_20 -> V_40 / V_20 -> V_67 ;
V_65 = V_20 -> V_67 ;
} else {
V_64 = V_20 -> V_40 ;
V_65 = 1 ;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
V_4 = F_25 ( V_26 , V_59 + V_20 -> V_68 + V_66 * V_64 ,
V_64 ) ;
if ( V_20 -> V_35 & V_69 ) {
if ( ( long long ) V_4 >= V_70 &&
( long long ) V_4 <= V_71 )
V_62 = F_18 ( V_4 ) ;
else
V_62 = F_26 ( V_4 ) ;
} else {
if ( V_4 <= V_71 )
V_62 = F_18 ( V_4 ) ;
else
V_62 = F_27 ( V_4 ) ;
}
if ( V_60 )
F_28 ( V_63 , V_66 , V_62 ) ;
}
if ( V_60 )
V_62 = V_63 ;
return V_62 ;
}
static T_1 * F_29 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_1 * V_78 ;
V_78 = F_24 ( 0 ) ;
if ( ! V_78 )
F_3 ( L_9 ) ;
if ( ! V_79 . V_80 || ! V_73 -> V_81 )
goto exit;
if ( F_30 ( V_77 -> V_82 , & V_83 , V_75 ,
V_73 , NULL , NULL ,
V_84 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_83 ) ;
while ( 1 ) {
T_1 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_33 ( & V_83 ) ;
if ( ! V_87 )
break;
V_85 = F_34 () ;
if ( ! V_85 )
F_3 ( L_11 ) ;
F_4 ( V_85 , L_12 ,
F_27 ( V_87 -> V_88 ) ) ;
if ( V_87 -> V_89 ) {
T_1 * V_90 = F_34 () ;
if ( ! V_90 )
F_3 ( L_11 ) ;
F_4 ( V_90 , L_13 ,
F_27 ( V_87 -> V_89 -> V_91 ) ) ;
F_4 ( V_90 , L_14 ,
F_27 ( V_87 -> V_89 -> V_92 ) ) ;
F_4 ( V_90 , L_15 ,
F_18 ( V_87 -> V_89 -> V_93 ) ) ;
F_4 ( V_90 , L_16 ,
F_35 ( V_87 -> V_89 -> V_34 ,
V_87 -> V_89 -> V_94 ) ) ;
F_4 ( V_85 , L_17 , V_90 ) ;
}
if ( V_87 -> V_95 ) {
struct V_95 * V_95 = V_87 -> V_95 ;
const char * V_96 = L_18 ;
if ( V_95 && V_95 -> V_97 && ( V_95 -> V_97 -> V_34 || V_95 -> V_97 -> V_98 ) ) {
if ( V_79 . V_99 && V_95 -> V_97 -> V_98 )
V_96 = V_95 -> V_97 -> V_98 ;
else if ( V_95 -> V_97 -> V_34 )
V_96 = V_95 -> V_97 -> V_34 ;
}
F_4 ( V_85 , L_19 ,
F_17 ( V_96 ) ) ;
}
F_36 ( & V_83 ) ;
F_37 ( V_78 , V_85 ) ;
F_6 ( V_85 ) ;
}
exit:
return V_78 ;
}
static void F_38 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_25 * V_26 = V_75 -> V_100 ;
T_1 * V_5 , * V_101 , * V_15 , * V_62 , * V_81 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_58 * V_20 ;
unsigned long V_102 , V_103 ;
unsigned V_17 = 0 ;
int V_104 ;
int V_105 = V_73 -> V_105 ;
void * V_59 = V_73 -> V_106 ;
unsigned long long V_107 = V_73 -> time ;
const char * V_108 = F_39 ( V_77 -> V_82 ) ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
if ( ! V_26 ) {
snprintf ( V_1 , sizeof( V_1 ) ,
L_20 V_110 , ( V_111 ) V_75 -> V_112 . V_113 ) ;
F_3 ( V_1 ) ;
}
V_104 = F_40 ( V_26 , L_21 , V_59 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_41 ( V_26 -> V_114 , V_115 ) )
F_21 ( V_26 , V_1 , V_26 -> V_116 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_102 = V_107 / V_117 ;
V_103 = V_107 - V_102 * V_117 ;
V_118 -> V_119 = V_59 ;
V_118 -> V_120 = V_75 -> V_100 -> V_120 ;
V_101 = F_42 ( V_118 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_101 ) ;
V_81 = F_29 ( V_73 , V_75 , V_77 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_102 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_104 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_108 ) ) ;
F_16 ( V_15 , V_17 ++ , V_81 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_105 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_102 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_103 ) ) ;
F_4 ( V_2 , L_21 , F_18 ( V_104 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_108 ) ) ;
F_4 ( V_2 , L_28 , V_81 ) ;
}
for ( V_20 = V_26 -> V_121 . V_122 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_123 ) {
int V_68 ;
if ( V_20 -> V_35 & V_124 ) {
V_68 = * ( int * ) ( V_59 + V_20 -> V_68 ) ;
V_68 &= 0xffff ;
} else
V_68 = V_20 -> V_68 ;
V_62 = F_17 ( ( char * ) V_59 + V_68 ) ;
} else {
V_62 = F_23 ( V_26 , V_20 , V_59 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_62 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_62 ) ;
}
if ( ! V_5 )
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_43 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_5 ) {
F_10 ( V_5 , V_15 , V_1 ) ;
} else {
F_12 ( L_30 , V_15 ) ;
F_6 ( V_2 ) ;
}
F_6 ( V_15 ) ;
}
static T_1 * F_44 ( unsigned int V_125 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_125 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_45 ( T_1 * V_15 , unsigned int V_126 , V_111 V_4 )
{
#if V_127 == 64
return F_16 ( V_15 , V_126 , F_18 ( V_4 ) ) ;
#endif
#if V_127 == 32
return F_16 ( V_15 , V_126 , F_26 ( V_4 ) ) ;
#endif
}
static int F_46 ( T_1 * V_15 , unsigned int V_126 , T_2 V_4 )
{
return F_16 ( V_15 , V_126 , F_18 ( V_4 ) ) ;
}
static int F_47 ( T_1 * V_15 , unsigned int V_126 , const char * V_102 )
{
return F_16 ( V_15 , V_126 , F_17 ( V_102 ) ) ;
}
static int F_48 ( struct V_128 * V_129 , struct V_74 * V_75 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 2 ) ;
F_45 ( V_15 , 0 , V_75 -> V_131 ) ;
F_47 ( V_15 , 1 , F_50 ( V_75 ) ) ;
F_10 ( V_130 -> V_132 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_51 ( struct V_128 * V_129 ,
struct V_133 * V_133 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 3 ) ;
F_45 ( V_15 , 0 , V_133 -> V_131 ) ;
F_46 ( V_15 , 1 , V_133 -> V_104 ) ;
F_47 ( V_15 , 2 , V_133 -> V_134 ? V_133 -> V_134 : L_32 ) ;
F_10 ( V_130 -> V_135 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_128 * V_129 , struct V_82 * V_82 ,
V_111 V_136 , struct V_133 * V_133 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 5 ) ;
F_45 ( V_15 , 0 , V_82 -> V_131 ) ;
F_45 ( V_15 , 1 , V_133 -> V_131 ) ;
F_45 ( V_15 , 2 , V_136 ) ;
F_46 ( V_15 , 3 , V_82 -> V_137 ) ;
F_46 ( V_15 , 4 , V_82 -> V_138 ) ;
F_10 ( V_130 -> V_139 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_128 * V_129 , struct V_108 * V_108 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 2 ) ;
F_45 ( V_15 , 0 , V_108 -> V_131 ) ;
F_47 ( V_15 , 1 , F_54 ( V_108 ) ) ;
F_10 ( V_130 -> V_140 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_55 ( struct V_128 * V_129 , V_111 V_131 ,
struct V_108 * V_108 , struct V_82 * V_82 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 3 ) ;
F_45 ( V_15 , 0 , V_131 ) ;
F_45 ( V_15 , 1 , V_108 -> V_131 ) ;
F_45 ( V_15 , 2 , V_82 -> V_131 ) ;
F_10 ( V_130 -> V_141 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_128 * V_129 , struct V_97 * V_97 ,
struct V_133 * V_133 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
char V_142 [ V_143 ] ;
T_1 * V_15 ;
F_57 ( V_97 -> V_144 , sizeof( V_97 -> V_144 ) , V_142 ) ;
V_15 = F_44 ( 5 ) ;
F_45 ( V_15 , 0 , V_97 -> V_131 ) ;
F_45 ( V_15 , 1 , V_133 -> V_131 ) ;
F_47 ( V_15 , 2 , V_97 -> V_145 ) ;
F_47 ( V_15 , 3 , V_97 -> V_98 ) ;
F_47 ( V_15 , 4 , V_142 ) ;
F_10 ( V_130 -> V_146 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_128 * V_129 , struct V_36 * V_89 ,
struct V_97 * V_97 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
V_111 * V_147 = F_59 ( V_89 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 6 ) ;
F_45 ( V_15 , 0 , * V_147 ) ;
F_45 ( V_15 , 1 , V_97 -> V_131 ) ;
F_45 ( V_15 , 2 , V_89 -> V_91 ) ;
F_45 ( V_15 , 3 , V_89 -> V_92 ) ;
F_46 ( V_15 , 4 , V_89 -> V_93 ) ;
F_47 ( V_15 , 5 , V_89 -> V_34 ) ;
F_10 ( V_130 -> V_148 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_60 ( struct V_128 * V_129 , T_3 V_149 ,
const char * V_34 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 2 ) ;
F_46 ( V_15 , 0 , V_149 ) ;
F_47 ( V_15 , 1 , V_34 ) ;
F_10 ( V_130 -> V_150 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_128 * V_129 ,
struct V_151 * V_152 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_15 = F_44 ( 22 ) ;
F_45 ( V_15 , 0 , V_152 -> V_131 ) ;
F_45 ( V_15 , 1 , V_152 -> V_75 -> V_131 ) ;
F_45 ( V_15 , 2 , V_152 -> V_77 -> V_133 -> V_131 ) ;
F_45 ( V_15 , 3 , V_152 -> V_77 -> V_82 -> V_131 ) ;
F_45 ( V_15 , 4 , V_152 -> V_153 ) ;
F_45 ( V_15 , 5 , V_152 -> V_154 ) ;
F_45 ( V_15 , 6 , V_152 -> V_147 ) ;
F_45 ( V_15 , 7 , V_152 -> V_68 ) ;
F_45 ( V_15 , 8 , V_152 -> V_73 -> V_88 ) ;
F_45 ( V_15 , 9 , V_152 -> V_73 -> time ) ;
F_46 ( V_15 , 10 , V_152 -> V_73 -> V_105 ) ;
F_45 ( V_15 , 11 , V_152 -> V_155 ) ;
F_45 ( V_15 , 12 , V_152 -> V_156 ) ;
F_45 ( V_15 , 13 , V_152 -> V_157 ) ;
F_45 ( V_15 , 14 , V_152 -> V_73 -> V_158 ) ;
F_45 ( V_15 , 15 , V_152 -> V_73 -> V_159 ) ;
F_45 ( V_15 , 16 , V_152 -> V_73 -> V_160 ) ;
F_45 ( V_15 , 17 , V_152 -> V_73 -> V_161 ) ;
F_45 ( V_15 , 18 , V_152 -> V_73 -> V_162 ) ;
F_46 ( V_15 , 19 , V_152 -> V_73 -> V_35 & V_163 ) ;
F_46 ( V_15 , 20 , ! ! ( V_152 -> V_73 -> V_35 & V_164 ) ) ;
F_45 ( V_15 , 21 , V_152 -> V_165 ) ;
F_10 ( V_130 -> V_166 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_62 ( struct V_128 * V_129 , struct V_167 * V_168 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
T_1 * V_15 ;
V_111 V_169 , V_147 ;
V_169 = V_168 -> V_170 ? V_168 -> V_170 -> V_131 : 0 ;
V_147 = V_168 -> V_89 ? * ( V_111 * ) F_59 ( V_168 -> V_89 ) : 0 ;
V_15 = F_44 ( 4 ) ;
F_45 ( V_15 , 0 , V_168 -> V_131 ) ;
F_45 ( V_15 , 1 , V_169 ) ;
F_45 ( V_15 , 2 , V_147 ) ;
F_45 ( V_15 , 3 , V_168 -> V_88 ) ;
F_10 ( V_130 -> V_171 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_128 * V_129 ,
struct V_172 * V_173 )
{
struct V_130 * V_130 = F_49 ( V_129 , struct V_130 , V_129 ) ;
V_111 V_153 = V_173 -> V_108 ? V_173 -> V_108 -> V_131 : 0 ;
T_1 * V_15 ;
V_15 = F_44 ( 11 ) ;
F_45 ( V_15 , 0 , V_173 -> V_131 ) ;
F_45 ( V_15 , 1 , V_173 -> V_82 -> V_131 ) ;
F_45 ( V_15 , 2 , V_153 ) ;
F_45 ( V_15 , 3 , V_173 -> V_168 -> V_131 ) ;
F_45 ( V_15 , 4 , V_173 -> V_174 ) ;
F_45 ( V_15 , 5 , V_173 -> V_175 ) ;
F_45 ( V_15 , 6 , V_173 -> V_176 ) ;
F_45 ( V_15 , 7 , V_173 -> V_177 ) ;
F_45 ( V_15 , 8 , V_173 -> V_178 ) ;
F_45 ( V_15 , 9 , V_173 -> V_168 -> V_170 -> V_131 ) ;
F_46 ( V_15 , 10 , V_173 -> V_35 ) ;
F_10 ( V_130 -> V_179 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_172 * V_173 , void * V_59 )
{
struct V_128 * V_129 = V_59 ;
return F_65 ( V_129 , V_173 ) ;
}
static void F_66 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_81 , * V_180 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_180 = F_34 () ;
if ( ! V_180 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_50 ( V_75 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_75 -> V_112 , sizeof( V_75 -> V_112 ) ) ) ;
F_4 ( V_180 , L_47 ,
F_18 ( V_73 -> V_104 ) ) ;
F_4 ( V_180 , L_48 ,
F_18 ( V_73 -> V_138 ) ) ;
F_4 ( V_180 , L_49 ,
F_18 ( V_73 -> V_105 ) ) ;
F_4 ( V_180 , L_12 ,
F_27 ( V_73 -> V_88 ) ) ;
F_4 ( V_180 , L_50 ,
F_27 ( V_73 -> time ) ) ;
F_4 ( V_180 , L_51 ,
F_27 ( V_73 -> V_159 ) ) ;
F_4 ( V_2 , L_52 , V_180 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_73 -> V_106 , V_73 -> V_181 ) ) ;
F_4 ( V_2 , L_54 ,
F_17 ( F_39 ( V_77 -> V_82 ) ) ) ;
if ( V_77 -> V_95 ) {
F_4 ( V_2 , L_19 ,
F_17 ( V_77 -> V_95 -> V_97 -> V_34 ) ) ;
}
if ( V_77 -> V_89 ) {
F_4 ( V_2 , L_55 ,
F_17 ( V_77 -> V_89 -> V_34 ) ) ;
}
V_81 = F_29 ( V_73 , V_75 , V_77 ) ;
F_4 ( V_2 , L_56 , V_81 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_43 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_67 ( union V_182 * V_26 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_130 * V_130 = & V_183 ;
switch ( V_75 -> V_112 . type ) {
case V_184 :
F_38 ( V_73 , V_75 , V_77 ) ;
break;
default:
if ( V_130 -> V_185 )
F_68 ( & V_130 -> V_129 , V_26 , V_73 , V_75 , V_77 ) ;
else
F_66 ( V_73 , V_75 , V_77 ) ;
}
}
static void F_69 ( char * V_21 , T_4 V_40 ,
struct V_74 * V_75 )
{
char * V_186 = V_21 ;
F_70 ( V_21 , V_40 , L_57 , F_50 ( V_75 ) ) ;
while ( ( V_186 = strchr ( V_186 , ':' ) ) ) {
* V_186 = '_' ;
V_186 ++ ;
}
}
static void
F_71 ( struct V_74 * V_187 , int V_105 , int V_82 , V_111 V_188 ,
struct V_189 * V_43 )
{
T_1 * V_5 , * V_15 ;
static char V_1 [ 256 ] ;
int V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_69 ( V_1 , sizeof( V_1 ) ,
V_187 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_72 ( L_58 , V_1 ) ;
return;
}
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_82 ) ) ;
F_45 ( V_15 , V_17 ++ , V_188 ) ;
F_45 ( V_15 , V_17 ++ , V_43 -> V_4 ) ;
F_45 ( V_15 , V_17 ++ , V_43 -> V_190 ) ;
F_45 ( V_15 , V_17 ++ , V_43 -> V_191 ) ;
if ( F_43 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static void F_73 ( struct V_192 * V_113 ,
struct V_74 * V_187 , V_111 V_188 )
{
struct V_193 * V_194 = V_187 -> V_194 ;
struct V_195 * V_196 = V_187 -> V_196 ;
int V_105 , V_82 ;
if ( V_113 -> V_197 == V_198 ) {
F_71 ( V_187 , - 1 , - 1 , V_188 ,
& V_187 -> V_199 -> V_200 ) ;
return;
}
for ( V_82 = 0 ; V_82 < V_194 -> V_201 ; V_82 ++ ) {
for ( V_105 = 0 ; V_105 < V_196 -> V_201 ; V_105 ++ ) {
F_71 ( V_187 , V_196 -> V_95 [ V_105 ] ,
F_74 ( V_194 , V_82 ) , V_188 ,
F_75 ( V_187 -> V_199 , V_105 , V_82 ) ) ;
}
}
}
static void F_76 ( V_111 V_188 )
{
T_1 * V_5 , * V_15 ;
static const char V_1 [] = L_59 ;
int V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_72 ( L_58 , V_1 ) ;
return;
}
F_45 ( V_15 , V_17 ++ , V_188 ) ;
if ( F_43 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static int F_77 ( void )
{
V_202 = F_78 ( L_60 ) ;
if ( V_202 == NULL )
return - 1 ;
F_79 ( V_202 ) ;
V_6 = F_80 ( V_202 ) ;
if ( V_6 == NULL )
goto error;
F_79 ( V_6 ) ;
F_12 ( L_61 , NULL ) ;
return 0 ;
error:
F_81 ( V_6 ) ;
F_81 ( V_202 ) ;
return - 1 ;
}
static void F_82 ( struct V_130 * V_130 )
{
const char * V_203 = L_62 ;
const char * V_204 = L_63 ;
const char * V_205 = L_64 ;
T_1 * V_185 , * V_206 , * V_207 ;
bool V_208 = false ;
bool V_209 = false ;
int V_210 ;
memset ( V_130 , 0 , sizeof( struct V_130 ) ) ;
if ( F_83 ( & V_130 -> V_129 ) )
F_3 ( L_65 ) ;
V_185 = F_8 ( V_6 , V_203 ) ;
if ( ! V_185 )
return;
V_210 = F_84 ( V_185 ) ;
if ( V_210 == - 1 )
F_1 ( V_203 ) ;
if ( ! V_210 )
return;
V_130 -> V_129 . V_211 = NULL ;
V_206 = F_8 ( V_6 , V_204 ) ;
if ( V_206 ) {
V_210 = F_84 ( V_206 ) ;
if ( V_210 == - 1 )
F_1 ( V_204 ) ;
V_208 = ! ! V_210 ;
}
if ( V_208 ) {
V_130 -> V_129 . V_211 =
F_85 ( F_64 ,
& V_130 -> V_129 ) ;
if ( ! V_130 -> V_129 . V_211 )
F_3 ( L_66 ) ;
}
V_130 -> V_129 . V_212 = NULL ;
V_207 = F_8 ( V_6 ,
V_205 ) ;
if ( V_207 ) {
V_210 = F_84 ( V_207 ) ;
if ( V_210 == - 1 )
F_1 ( V_205 ) ;
V_209 = ! ! V_210 ;
}
if ( V_209 ) {
if ( V_130 -> V_129 . V_211 )
V_130 -> V_129 . V_212 = V_130 -> V_129 . V_211 -> V_212 ;
else
V_130 -> V_129 . V_212 = F_86 () ;
if ( ! V_130 -> V_129 . V_212 )
F_3 ( L_67 ) ;
}
V_130 -> V_185 = true ;
V_79 . V_213 = sizeof( V_111 ) ;
F_87 ( V_75 ) ;
F_87 ( V_133 ) ;
F_87 ( V_82 ) ;
F_87 ( V_108 ) ;
F_87 ( V_214 ) ;
F_87 ( V_97 ) ;
F_87 ( V_36 ) ;
F_87 ( V_149 ) ;
F_87 ( V_73 ) ;
F_87 ( V_167 ) ;
F_87 ( V_172 ) ;
}
static int F_88 ( const char * V_215 , int V_216 , const char * * V_217 )
{
struct V_130 * V_130 = & V_183 ;
const char * * V_218 ;
char V_219 [ V_220 ] ;
int V_66 , V_221 = 0 ;
T_5 * V_222 ;
V_218 = malloc ( ( V_216 + 1 ) * sizeof( const char * ) ) ;
V_218 [ 0 ] = V_215 ;
for ( V_66 = 1 ; V_66 < V_216 + 1 ; V_66 ++ )
V_218 [ V_66 ] = V_217 [ V_66 - 1 ] ;
F_89 () ;
F_90 () ;
F_91 ( V_216 + 1 , ( char * * ) V_218 ) ;
V_222 = fopen ( V_215 , L_68 ) ;
if ( ! V_222 ) {
sprintf ( V_219 , L_69 , V_215 ) ;
perror ( V_219 ) ;
V_221 = - 1 ;
goto error;
}
V_221 = F_92 ( V_222 , V_215 ) ;
if ( V_221 ) {
fprintf ( V_223 , L_70 , V_215 ) ;
goto error;
}
V_221 = F_77 () ;
if ( V_221 ) {
fprintf ( V_223 , L_71 , V_215 ) ;
goto error;
}
F_82 ( V_130 ) ;
if ( V_130 -> V_185 ) {
V_221 = F_93 ( & V_130 -> V_129 ) ;
if ( V_221 )
goto error;
}
free ( V_218 ) ;
return V_221 ;
error:
F_94 () ;
free ( V_218 ) ;
return V_221 ;
}
static int F_95 ( void )
{
struct V_130 * V_130 = & V_183 ;
return F_96 ( & V_130 -> V_129 ) ;
}
static int F_97 ( void )
{
struct V_130 * V_130 = & V_183 ;
F_12 ( L_72 , NULL ) ;
F_98 ( & V_130 -> V_129 ) ;
F_81 ( V_6 ) ;
F_81 ( V_202 ) ;
F_94 () ;
return 0 ;
}
static int F_99 ( struct V_120 * V_120 , const char * V_224 )
{
struct V_25 * V_26 = NULL ;
struct V_58 * V_225 ;
char V_226 [ V_220 ] ;
int V_227 , V_43 ;
T_5 * V_228 ;
sprintf ( V_226 , L_73 , V_224 ) ;
V_228 = fopen ( V_226 , L_74 ) ;
if ( V_228 == NULL ) {
fprintf ( V_223 , L_75 , V_226 ) ;
return - 1 ;
}
fprintf ( V_228 , L_76
L_77 ) ;
fprintf ( V_228 , L_78
L_79 ) ;
fprintf ( V_228 , L_80
L_81 ) ;
fprintf ( V_228 , L_82
L_83 ) ;
fprintf ( V_228 , L_84
L_85 ) ;
fprintf ( V_228 , L_86
L_87 ) ;
fprintf ( V_228 , L_88
L_89 ) ;
fprintf ( V_228 , L_90 ) ;
fprintf ( V_228 , L_91 ) ;
fprintf ( V_228 , L_92 ) ;
fprintf ( V_228 , L_93 ) ;
fprintf ( V_228 , L_94 ) ;
fprintf ( V_228 , L_95 ) ;
fprintf ( V_228 , L_96 ) ;
fprintf ( V_228 , L_97 ) ;
fprintf ( V_228 , L_98 ) ;
fprintf ( V_228 , L_99 ) ;
while ( ( V_26 = F_100 ( V_120 , V_26 ) ) ) {
fprintf ( V_228 , L_100 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_228 , L_101 ) ;
fprintf ( V_228 , L_102 ) ;
fprintf ( V_228 , L_103 ) ;
fprintf ( V_228 , L_104 ) ;
fprintf ( V_228 , L_105 ) ;
fprintf ( V_228 , L_106 ) ;
fprintf ( V_228 , L_107 ) ;
fprintf ( V_228 , L_108 ) ;
V_227 = 0 ;
V_43 = 0 ;
for ( V_225 = V_26 -> V_121 . V_122 ; V_225 ; V_225 = V_225 -> V_22 ) {
if ( V_227 ++ )
fprintf ( V_228 , L_109 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_228 , L_110 ) ;
fprintf ( V_228 , L_43 , V_225 -> V_34 ) ;
}
fprintf ( V_228 , L_111 ) ;
fprintf ( V_228 , L_112
L_113
L_114 ) ;
fprintf ( V_228 , L_115 ) ;
V_227 = 0 ;
V_43 = 0 ;
for ( V_225 = V_26 -> V_121 . V_122 ; V_225 ; V_225 = V_225 -> V_22 ) {
if ( V_227 ++ )
fprintf ( V_228 , L_109 ) ;
if ( V_43 && V_43 % 3 == 0 ) {
fprintf ( V_228 , L_116 ) ;
}
V_43 ++ ;
fprintf ( V_228 , L_117 , V_225 -> V_34 ) ;
if ( V_225 -> V_35 & V_123 ||
V_225 -> V_35 & V_229 ||
V_225 -> V_35 & V_61 ||
V_225 -> V_35 & V_230 )
fprintf ( V_228 , L_118 ) ;
else if ( V_225 -> V_35 & V_69 )
fprintf ( V_228 , L_119 ) ;
else
fprintf ( V_228 , L_120 ) ;
}
fprintf ( V_228 , L_121 ) ;
V_227 = 0 ;
V_43 = 0 ;
for ( V_225 = V_26 -> V_121 . V_122 ; V_225 ; V_225 = V_225 -> V_22 ) {
if ( V_227 ++ )
fprintf ( V_228 , L_109 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_228 , L_122 ) ;
if ( V_225 -> V_35 & V_229 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_228 , L_122 ) ;
V_43 = 4 ;
}
fprintf ( V_228 , L_123 ) ;
fprintf ( V_228 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_228 , L_125 , V_225 -> V_34 ,
V_225 -> V_34 ) ;
} else if ( V_225 -> V_35 & V_230 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_228 , L_122 ) ;
V_43 = 4 ;
}
fprintf ( V_228 , L_126 ) ;
fprintf ( V_228 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_228 , L_125 , V_225 -> V_34 ,
V_225 -> V_34 ) ;
} else
fprintf ( V_228 , L_43 , V_225 -> V_34 ) ;
}
fprintf ( V_228 , L_127 ) ;
fprintf ( V_228 , L_128 ) ;
fprintf ( V_228 , L_129 ) ;
fprintf ( V_228 , L_130 ) ;
fprintf ( V_228 , L_131 ) ;
fprintf ( V_228 , L_132 ) ;
fprintf ( V_228 , L_133 ) ;
}
fprintf ( V_228 , L_134
L_135 ) ;
fprintf ( V_228 , L_136
L_137 ) ;
fprintf ( V_228 , L_138
L_139
L_140
L_141 ) ;
fclose ( V_228 ) ;
fprintf ( V_223 , L_142 , V_226 ) ;
return 0 ;
}
