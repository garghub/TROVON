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
if ( F_30 ( V_77 -> V_82 , V_75 ,
V_73 , NULL , NULL ,
V_83 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_84 ) ;
while ( 1 ) {
T_1 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_33 ( & V_84 ) ;
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
F_36 ( & V_84 ) ;
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
if ( ! V_26 )
F_40 ( L_20 , ( int ) V_75 -> V_110 . V_111 ) ;
V_104 = F_41 ( V_26 , L_21 , V_59 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_42 ( V_26 -> V_112 , V_113 ) )
F_21 ( V_26 , V_1 , V_26 -> V_114 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_102 = V_107 / V_115 ;
V_103 = V_107 - V_102 * V_115 ;
V_116 -> V_117 = V_59 ;
V_116 -> V_118 = V_75 -> V_100 -> V_118 ;
V_101 = F_43 ( V_116 , NULL ) ;
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
for ( V_20 = V_26 -> V_119 . V_120 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_121 ) {
int V_68 ;
if ( V_20 -> V_35 & V_122 ) {
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
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_5 ) {
F_10 ( V_5 , V_15 , V_1 ) ;
} else {
F_12 ( L_30 , V_15 ) ;
F_6 ( V_2 ) ;
}
F_6 ( V_15 ) ;
}
static T_1 * F_45 ( unsigned int V_123 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_123 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_46 ( T_1 * V_15 , unsigned int V_124 , T_2 V_4 )
{
#if V_125 == 64
return F_16 ( V_15 , V_124 , F_18 ( V_4 ) ) ;
#endif
#if V_125 == 32
return F_16 ( V_15 , V_124 , F_26 ( V_4 ) ) ;
#endif
}
static int F_47 ( T_1 * V_15 , unsigned int V_124 , T_3 V_4 )
{
return F_16 ( V_15 , V_124 , F_18 ( V_4 ) ) ;
}
static int F_48 ( T_1 * V_15 , unsigned int V_124 , const char * V_102 )
{
return F_16 ( V_15 , V_124 , F_17 ( V_102 ) ) ;
}
static int F_49 ( struct V_126 * V_127 , struct V_74 * V_75 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_75 -> V_129 ) ;
F_48 ( V_15 , 1 , F_51 ( V_75 ) ) ;
F_10 ( V_128 -> V_130 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_126 * V_127 ,
struct V_131 * V_131 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_131 -> V_129 ) ;
F_47 ( V_15 , 1 , V_131 -> V_104 ) ;
F_48 ( V_15 , 2 , V_131 -> V_132 ? V_131 -> V_132 : L_32 ) ;
F_10 ( V_128 -> V_133 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_126 * V_127 , struct V_82 * V_82 ,
T_2 V_134 , struct V_131 * V_131 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_82 -> V_129 ) ;
F_46 ( V_15 , 1 , V_131 -> V_129 ) ;
F_46 ( V_15 , 2 , V_134 ) ;
F_47 ( V_15 , 3 , V_82 -> V_135 ) ;
F_47 ( V_15 , 4 , V_82 -> V_136 ) ;
F_10 ( V_128 -> V_137 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_126 * V_127 , struct V_108 * V_108 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_108 -> V_129 ) ;
F_48 ( V_15 , 1 , F_55 ( V_108 ) ) ;
F_10 ( V_128 -> V_138 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_126 * V_127 , T_2 V_129 ,
struct V_108 * V_108 , struct V_82 * V_82 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_129 ) ;
F_46 ( V_15 , 1 , V_108 -> V_129 ) ;
F_46 ( V_15 , 2 , V_82 -> V_129 ) ;
F_10 ( V_128 -> V_139 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_126 * V_127 , struct V_97 * V_97 ,
struct V_131 * V_131 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
char V_140 [ V_141 * 2 + 1 ] ;
T_1 * V_15 ;
F_58 ( V_97 -> V_142 , sizeof( V_97 -> V_142 ) , V_140 ) ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_97 -> V_129 ) ;
F_46 ( V_15 , 1 , V_131 -> V_129 ) ;
F_48 ( V_15 , 2 , V_97 -> V_143 ) ;
F_48 ( V_15 , 3 , V_97 -> V_98 ) ;
F_48 ( V_15 , 4 , V_140 ) ;
F_10 ( V_128 -> V_144 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_126 * V_127 , struct V_36 * V_89 ,
struct V_97 * V_97 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_2 * V_145 = F_60 ( V_89 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 6 ) ;
F_46 ( V_15 , 0 , * V_145 ) ;
F_46 ( V_15 , 1 , V_97 -> V_129 ) ;
F_46 ( V_15 , 2 , V_89 -> V_91 ) ;
F_46 ( V_15 , 3 , V_89 -> V_92 ) ;
F_47 ( V_15 , 4 , V_89 -> V_93 ) ;
F_48 ( V_15 , 5 , V_89 -> V_34 ) ;
F_10 ( V_128 -> V_146 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_126 * V_127 , T_4 V_147 ,
const char * V_34 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_47 ( V_15 , 0 , V_147 ) ;
F_48 ( V_15 , 1 , V_34 ) ;
F_10 ( V_128 -> V_148 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_62 ( struct V_126 * V_127 ,
struct V_149 * V_150 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 21 ) ;
F_46 ( V_15 , 0 , V_150 -> V_129 ) ;
F_46 ( V_15 , 1 , V_150 -> V_75 -> V_129 ) ;
F_46 ( V_15 , 2 , V_150 -> V_77 -> V_131 -> V_129 ) ;
F_46 ( V_15 , 3 , V_150 -> V_77 -> V_82 -> V_129 ) ;
F_46 ( V_15 , 4 , V_150 -> V_151 ) ;
F_46 ( V_15 , 5 , V_150 -> V_152 ) ;
F_46 ( V_15 , 6 , V_150 -> V_145 ) ;
F_46 ( V_15 , 7 , V_150 -> V_68 ) ;
F_46 ( V_15 , 8 , V_150 -> V_73 -> V_88 ) ;
F_46 ( V_15 , 9 , V_150 -> V_73 -> time ) ;
F_47 ( V_15 , 10 , V_150 -> V_73 -> V_105 ) ;
F_46 ( V_15 , 11 , V_150 -> V_153 ) ;
F_46 ( V_15 , 12 , V_150 -> V_154 ) ;
F_46 ( V_15 , 13 , V_150 -> V_155 ) ;
F_46 ( V_15 , 14 , V_150 -> V_73 -> V_156 ) ;
F_46 ( V_15 , 15 , V_150 -> V_73 -> V_157 ) ;
F_46 ( V_15 , 16 , V_150 -> V_73 -> V_158 ) ;
F_46 ( V_15 , 17 , V_150 -> V_73 -> V_159 ) ;
F_46 ( V_15 , 18 , V_150 -> V_73 -> V_160 ) ;
F_47 ( V_15 , 19 , V_150 -> V_73 -> V_35 & V_161 ) ;
F_47 ( V_15 , 20 , ! ! ( V_150 -> V_73 -> V_35 & V_162 ) ) ;
F_10 ( V_128 -> V_163 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_126 * V_127 , struct V_164 * V_165 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_1 * V_15 ;
T_2 V_166 , V_145 ;
V_166 = V_165 -> V_167 ? V_165 -> V_167 -> V_129 : 0 ;
V_145 = V_165 -> V_89 ? * ( T_2 * ) F_60 ( V_165 -> V_89 ) : 0 ;
V_15 = F_45 ( 4 ) ;
F_46 ( V_15 , 0 , V_165 -> V_129 ) ;
F_46 ( V_15 , 1 , V_166 ) ;
F_46 ( V_15 , 2 , V_145 ) ;
F_46 ( V_15 , 3 , V_165 -> V_88 ) ;
F_10 ( V_128 -> V_168 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_126 * V_127 ,
struct V_169 * V_170 )
{
struct V_128 * V_128 = F_50 ( V_127 , struct V_128 , V_127 ) ;
T_2 V_151 = V_170 -> V_108 ? V_170 -> V_108 -> V_129 : 0 ;
T_1 * V_15 ;
V_15 = F_45 ( 11 ) ;
F_46 ( V_15 , 0 , V_170 -> V_129 ) ;
F_46 ( V_15 , 1 , V_170 -> V_82 -> V_129 ) ;
F_46 ( V_15 , 2 , V_151 ) ;
F_46 ( V_15 , 3 , V_170 -> V_165 -> V_129 ) ;
F_46 ( V_15 , 4 , V_170 -> V_171 ) ;
F_46 ( V_15 , 5 , V_170 -> V_172 ) ;
F_46 ( V_15 , 6 , V_170 -> V_173 ) ;
F_46 ( V_15 , 7 , V_170 -> V_174 ) ;
F_46 ( V_15 , 8 , V_170 -> V_175 ) ;
F_46 ( V_15 , 9 , V_170 -> V_165 -> V_167 -> V_129 ) ;
F_47 ( V_15 , 10 , V_170 -> V_35 ) ;
F_10 ( V_128 -> V_176 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_169 * V_170 , void * V_59 )
{
struct V_126 * V_127 = V_59 ;
return F_66 ( V_127 , V_170 ) ;
}
static void F_67 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_81 , * V_177 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_177 = F_34 () ;
if ( ! V_177 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_51 ( V_75 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_75 -> V_110 , sizeof( V_75 -> V_110 ) ) ) ;
F_4 ( V_177 , L_47 ,
F_18 ( V_73 -> V_104 ) ) ;
F_4 ( V_177 , L_48 ,
F_18 ( V_73 -> V_136 ) ) ;
F_4 ( V_177 , L_49 ,
F_18 ( V_73 -> V_105 ) ) ;
F_4 ( V_177 , L_12 ,
F_27 ( V_73 -> V_88 ) ) ;
F_4 ( V_177 , L_50 ,
F_27 ( V_73 -> time ) ) ;
F_4 ( V_177 , L_51 ,
F_27 ( V_73 -> V_157 ) ) ;
F_4 ( V_2 , L_52 , V_177 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_73 -> V_106 , V_73 -> V_178 ) ) ;
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
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_68 ( union V_179 * V_26 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_128 * V_128 = & V_180 ;
switch ( V_75 -> V_110 . type ) {
case V_181 :
F_38 ( V_73 , V_75 , V_77 ) ;
break;
default:
if ( V_128 -> V_182 )
F_69 ( & V_128 -> V_127 , V_26 , V_73 , V_75 , V_77 ) ;
else
F_67 ( V_73 , V_75 , V_77 ) ;
}
}
static int F_70 ( void )
{
V_183 = F_71 ( L_57 ) ;
if ( V_183 == NULL )
return - 1 ;
F_72 ( V_183 ) ;
V_6 = F_73 ( V_183 ) ;
if ( V_6 == NULL )
goto error;
F_72 ( V_6 ) ;
F_12 ( L_58 , NULL ) ;
return 0 ;
error:
F_74 ( V_6 ) ;
F_74 ( V_183 ) ;
return - 1 ;
}
static void F_75 ( struct V_128 * V_128 )
{
const char * V_184 = L_59 ;
const char * V_185 = L_60 ;
T_1 * V_182 , * V_186 ;
bool V_187 = false ;
int V_188 ;
memset ( V_128 , 0 , sizeof( struct V_128 ) ) ;
if ( F_76 ( & V_128 -> V_127 ) )
F_3 ( L_61 ) ;
V_182 = F_8 ( V_6 , V_184 ) ;
if ( ! V_182 )
return;
V_188 = F_77 ( V_182 ) ;
if ( V_188 == - 1 )
F_1 ( V_184 ) ;
if ( ! V_188 )
return;
V_128 -> V_127 . V_189 = NULL ;
V_186 = F_8 ( V_6 , V_185 ) ;
if ( V_186 ) {
V_188 = F_77 ( V_186 ) ;
if ( V_188 == - 1 )
F_1 ( V_185 ) ;
V_187 = ! ! V_188 ;
}
if ( V_187 ) {
V_128 -> V_127 . V_189 =
F_78 ( F_65 ,
& V_128 -> V_127 ) ;
if ( ! V_128 -> V_127 . V_189 )
F_3 ( L_62 ) ;
}
V_128 -> V_182 = true ;
V_79 . V_190 = sizeof( T_2 ) ;
F_79 ( V_75 ) ;
F_79 ( V_131 ) ;
F_79 ( V_82 ) ;
F_79 ( V_108 ) ;
F_79 ( V_191 ) ;
F_79 ( V_97 ) ;
F_79 ( V_36 ) ;
F_79 ( V_147 ) ;
F_79 ( V_73 ) ;
F_79 ( V_164 ) ;
F_79 ( V_169 ) ;
}
static int F_80 ( const char * V_192 , int V_193 , const char * * V_194 )
{
struct V_128 * V_128 = & V_180 ;
const char * * V_195 ;
char V_196 [ V_197 ] ;
int V_66 , V_198 = 0 ;
T_5 * V_199 ;
V_195 = malloc ( ( V_193 + 1 ) * sizeof( const char * ) ) ;
V_195 [ 0 ] = V_192 ;
for ( V_66 = 1 ; V_66 < V_193 + 1 ; V_66 ++ )
V_195 [ V_66 ] = V_194 [ V_66 - 1 ] ;
F_81 () ;
F_82 () ;
F_83 ( V_193 + 1 , ( char * * ) V_195 ) ;
V_199 = fopen ( V_192 , L_63 ) ;
if ( ! V_199 ) {
sprintf ( V_196 , L_64 , V_192 ) ;
perror ( V_196 ) ;
V_198 = - 1 ;
goto error;
}
V_198 = F_84 ( V_199 , V_192 ) ;
if ( V_198 ) {
fprintf ( V_200 , L_65 , V_192 ) ;
goto error;
}
V_198 = F_70 () ;
if ( V_198 ) {
fprintf ( V_200 , L_66 , V_192 ) ;
goto error;
}
free ( V_195 ) ;
F_75 ( V_128 ) ;
if ( V_128 -> V_182 ) {
V_198 = F_85 ( & V_128 -> V_127 ) ;
if ( V_198 )
goto error;
}
return V_198 ;
error:
F_86 () ;
free ( V_195 ) ;
return V_198 ;
}
static int F_87 ( void )
{
struct V_128 * V_128 = & V_180 ;
return F_88 ( & V_128 -> V_127 ) ;
}
static int F_89 ( void )
{
struct V_128 * V_128 = & V_180 ;
F_12 ( L_67 , NULL ) ;
F_90 ( & V_128 -> V_127 ) ;
F_74 ( V_6 ) ;
F_74 ( V_183 ) ;
F_86 () ;
return 0 ;
}
static int F_91 ( struct V_118 * V_118 , const char * V_201 )
{
struct V_25 * V_26 = NULL ;
struct V_58 * V_202 ;
char V_203 [ V_197 ] ;
int V_204 , V_43 ;
T_5 * V_205 ;
sprintf ( V_203 , L_68 , V_201 ) ;
V_205 = fopen ( V_203 , L_69 ) ;
if ( V_205 == NULL ) {
fprintf ( V_200 , L_70 , V_203 ) ;
return - 1 ;
}
fprintf ( V_205 , L_71
L_72 ) ;
fprintf ( V_205 , L_73
L_74 ) ;
fprintf ( V_205 , L_75
L_76 ) ;
fprintf ( V_205 , L_77
L_78 ) ;
fprintf ( V_205 , L_79
L_80 ) ;
fprintf ( V_205 , L_81
L_82 ) ;
fprintf ( V_205 , L_83
L_84 ) ;
fprintf ( V_205 , L_85 ) ;
fprintf ( V_205 , L_86 ) ;
fprintf ( V_205 , L_87 ) ;
fprintf ( V_205 , L_88 ) ;
fprintf ( V_205 , L_89 ) ;
fprintf ( V_205 , L_90 ) ;
fprintf ( V_205 , L_91 ) ;
fprintf ( V_205 , L_92 ) ;
fprintf ( V_205 , L_93 ) ;
fprintf ( V_205 , L_94 ) ;
while ( ( V_26 = F_92 ( V_118 , V_26 ) ) ) {
fprintf ( V_205 , L_95 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_205 , L_96 ) ;
fprintf ( V_205 , L_97 ) ;
fprintf ( V_205 , L_98 ) ;
fprintf ( V_205 , L_99 ) ;
fprintf ( V_205 , L_100 ) ;
fprintf ( V_205 , L_101 ) ;
fprintf ( V_205 , L_102 ) ;
fprintf ( V_205 , L_103 ) ;
V_204 = 0 ;
V_43 = 0 ;
for ( V_202 = V_26 -> V_119 . V_120 ; V_202 ; V_202 = V_202 -> V_22 ) {
if ( V_204 ++ )
fprintf ( V_205 , L_104 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_205 , L_105 ) ;
fprintf ( V_205 , L_43 , V_202 -> V_34 ) ;
}
fprintf ( V_205 , L_106 ) ;
fprintf ( V_205 , L_107
L_108
L_109 ) ;
fprintf ( V_205 , L_110 ) ;
V_204 = 0 ;
V_43 = 0 ;
for ( V_202 = V_26 -> V_119 . V_120 ; V_202 ; V_202 = V_202 -> V_22 ) {
if ( V_204 ++ )
fprintf ( V_205 , L_104 ) ;
if ( V_43 && V_43 % 3 == 0 ) {
fprintf ( V_205 , L_111 ) ;
}
V_43 ++ ;
fprintf ( V_205 , L_112 , V_202 -> V_34 ) ;
if ( V_202 -> V_35 & V_121 ||
V_202 -> V_35 & V_206 ||
V_202 -> V_35 & V_61 ||
V_202 -> V_35 & V_207 )
fprintf ( V_205 , L_113 ) ;
else if ( V_202 -> V_35 & V_69 )
fprintf ( V_205 , L_114 ) ;
else
fprintf ( V_205 , L_115 ) ;
}
fprintf ( V_205 , L_116 ) ;
V_204 = 0 ;
V_43 = 0 ;
for ( V_202 = V_26 -> V_119 . V_120 ; V_202 ; V_202 = V_202 -> V_22 ) {
if ( V_204 ++ )
fprintf ( V_205 , L_104 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_205 , L_117 ) ;
if ( V_202 -> V_35 & V_206 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_205 , L_117 ) ;
V_43 = 4 ;
}
fprintf ( V_205 , L_118 ) ;
fprintf ( V_205 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_205 , L_120 , V_202 -> V_34 ,
V_202 -> V_34 ) ;
} else if ( V_202 -> V_35 & V_207 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_205 , L_117 ) ;
V_43 = 4 ;
}
fprintf ( V_205 , L_121 ) ;
fprintf ( V_205 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_205 , L_120 , V_202 -> V_34 ,
V_202 -> V_34 ) ;
} else
fprintf ( V_205 , L_43 , V_202 -> V_34 ) ;
}
fprintf ( V_205 , L_122 ) ;
fprintf ( V_205 , L_123 ) ;
fprintf ( V_205 , L_124 ) ;
fprintf ( V_205 , L_125 ) ;
fprintf ( V_205 , L_126 ) ;
fprintf ( V_205 , L_127 ) ;
fprintf ( V_205 , L_128 ) ;
}
fprintf ( V_205 , L_129
L_130 ) ;
fprintf ( V_205 , L_131
L_132 ) ;
fprintf ( V_205 , L_133
L_134
L_135
L_136 ) ;
fclose ( V_205 ) ;
fprintf ( V_200 , L_137 , V_203 ) ;
return 0 ;
}
