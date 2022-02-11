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
static int F_10 ( T_1 * V_5 )
{
int V_7 = 0 ;
T_1 * V_8 = F_11 ( V_5 ,
L_2 ) ;
if ( F_12 () ) {
F_13 () ;
V_8 = F_11 ( V_5 ,
L_3 ) ;
}
F_13 () ;
if ( V_8 ) {
T_1 * V_9 = F_11 ( V_8 ,
L_4 ) ;
if ( V_9 ) {
V_7 = ( int ) F_14 ( V_9 ) ;
F_6 ( V_9 ) ;
}
F_6 ( V_8 ) ;
}
return V_7 ;
}
static void F_15 ( T_1 * V_5 , T_1 * args , const char * V_10 )
{
T_1 * V_11 ;
V_11 = F_16 ( V_5 , args ) ;
if ( V_11 == NULL )
F_1 ( V_10 ) ;
F_6 ( V_11 ) ;
}
static void F_17 ( const char * V_1 , T_1 * args )
{
T_1 * V_5 ;
V_5 = F_7 ( V_1 ) ;
if ( V_5 )
F_15 ( V_5 , args , V_1 ) ;
}
static void F_18 ( enum V_12 V_13 ,
const char * V_14 ,
const char * V_15 ,
const char * V_16 ,
const char * V_17 )
{
const char * V_1 = L_5 ;
T_1 * V_18 ;
unsigned long long V_19 ;
unsigned V_20 = 0 ;
if ( V_13 == V_21 )
V_1 = L_6 ;
V_18 = F_19 ( 4 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
V_19 = F_20 ( V_16 ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_14 ) ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_15 ) ) ;
F_21 ( V_18 , V_20 ++ , F_23 ( V_19 ) ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_17 ) ) ;
F_17 ( V_1 , V_18 ) ;
F_6 ( V_18 ) ;
}
static void F_24 ( enum V_12 V_13 ,
struct V_22 * V_23 ,
const char * V_14 ,
const char * V_15 )
{
F_18 ( V_13 , V_14 , V_15 , V_23 -> V_19 ,
V_23 -> V_24 ) ;
if ( V_23 -> V_25 )
F_24 ( V_13 , V_23 -> V_25 , V_14 , V_15 ) ;
}
static void F_25 ( enum V_12 V_13 ,
const char * V_14 ,
const char * V_15 ,
const char * V_26 )
{
const char * V_1 = L_8 ;
T_1 * V_18 ;
unsigned V_20 = 0 ;
if ( V_13 == V_21 )
V_1 = L_9 ;
if ( V_13 == V_27 )
V_18 = F_19 ( 3 ) ;
else
V_18 = F_19 ( 2 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_14 ) ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_15 ) ) ;
if ( V_13 == V_27 )
F_21 ( V_18 , V_20 ++ , F_22 ( V_26 ) ) ;
F_17 ( V_1 , V_18 ) ;
F_6 ( V_18 ) ;
}
static void F_26 ( struct V_28 * V_29 ,
const char * V_14 ,
struct V_30 * args )
{
if ( args == NULL )
return;
switch ( args -> type ) {
case V_31 :
break;
case V_32 :
F_18 ( V_27 , V_14 , V_33 , L_10 ,
args -> V_34 . V_34 ) ;
V_35 = 0 ;
break;
case V_36 :
free ( V_33 ) ;
V_33 = F_27 ( args -> V_23 . V_37 ) ;
break;
case V_27 :
F_26 ( V_29 , V_14 , args -> V_38 . V_23 ) ;
F_25 ( V_27 , V_14 , V_33 ,
args -> V_38 . V_26 ) ;
F_24 ( V_27 , args -> V_38 . V_38 , V_14 ,
V_33 ) ;
break;
case V_21 :
F_26 ( V_29 , V_14 , args -> V_39 . V_23 ) ;
F_25 ( V_21 , V_14 , V_33 , NULL ) ;
F_24 ( V_21 , args -> V_39 . V_40 , V_14 ,
V_33 ) ;
break;
case V_41 :
case V_42 :
F_26 ( V_29 , V_14 , args -> V_43 . V_23 ) ;
F_26 ( V_29 , V_14 , args -> V_43 . V_44 ) ;
break;
case V_45 :
F_26 ( V_29 , V_14 , args -> V_46 . V_23 ) ;
F_26 ( V_29 , V_14 , args -> V_46 . V_47 ) ;
F_26 ( V_29 , V_14 , args -> V_46 . V_48 ) ;
break;
case V_49 :
break;
case V_50 :
F_26 ( V_29 , V_14 , args -> V_51 . V_52 ) ;
break;
case V_53 :
if ( strcmp ( args -> V_54 . V_54 , L_11 ) == 0 )
V_35 = 1 ;
F_26 ( V_29 , V_14 , args -> V_54 . V_55 ) ;
F_26 ( V_29 , V_14 , args -> V_54 . V_56 ) ;
break;
default:
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return;
}
if ( args -> V_25 )
F_26 ( V_29 , V_14 , args -> V_25 ) ;
}
static T_1 * F_28 ( struct V_28 * V_29 ,
struct V_62 * V_23 , void * V_63 )
{
bool V_64 = V_23 -> V_38 & V_65 ;
T_1 * V_66 = NULL , * V_67 = NULL ;
unsigned long long V_4 ;
unsigned int V_68 , V_69 , V_70 ;
if ( V_64 ) {
V_67 = F_29 ( V_23 -> V_71 ) ;
V_68 = V_23 -> V_44 / V_23 -> V_71 ;
V_69 = V_23 -> V_71 ;
} else {
V_68 = V_23 -> V_44 ;
V_69 = 1 ;
}
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_4 = F_30 ( V_29 , V_63 + V_23 -> V_72 + V_70 * V_68 ,
V_68 ) ;
if ( V_23 -> V_38 & V_73 ) {
if ( ( long long ) V_4 >= V_74 &&
( long long ) V_4 <= V_75 )
V_66 = F_23 ( V_4 ) ;
else
V_66 = F_31 ( V_4 ) ;
} else {
if ( V_4 <= V_75 )
V_66 = F_23 ( V_4 ) ;
else
V_66 = F_32 ( V_4 ) ;
}
if ( V_64 )
F_33 ( V_67 , V_70 , V_66 ) ;
}
if ( V_64 )
V_66 = V_67 ;
return V_66 ;
}
static T_1 * F_34 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
T_1 * V_82 ;
V_82 = F_29 ( 0 ) ;
if ( ! V_82 )
F_3 ( L_12 ) ;
if ( ! V_83 . V_84 || ! V_77 -> V_85 )
goto exit;
if ( F_35 ( V_81 -> V_86 , & V_87 , V_79 ,
V_77 , NULL , NULL ,
V_88 ) != 0 ) {
F_36 ( L_13 ) ;
goto exit;
}
F_37 ( & V_87 ) ;
while ( 1 ) {
T_1 * V_89 ;
struct V_90 * V_91 ;
V_91 = F_38 ( & V_87 ) ;
if ( ! V_91 )
break;
V_89 = F_39 () ;
if ( ! V_89 )
F_3 ( L_14 ) ;
F_4 ( V_89 , L_15 ,
F_32 ( V_91 -> V_92 ) ) ;
if ( V_91 -> V_93 ) {
T_1 * V_94 = F_39 () ;
if ( ! V_94 )
F_3 ( L_14 ) ;
F_4 ( V_94 , L_16 ,
F_32 ( V_91 -> V_93 -> V_95 ) ) ;
F_4 ( V_94 , L_17 ,
F_32 ( V_91 -> V_93 -> V_96 ) ) ;
F_4 ( V_94 , L_18 ,
F_23 ( V_91 -> V_93 -> V_97 ) ) ;
F_4 ( V_94 , L_19 ,
F_40 ( V_91 -> V_93 -> V_37 ,
V_91 -> V_93 -> V_98 ) ) ;
F_4 ( V_89 , L_20 , V_94 ) ;
}
if ( V_91 -> V_99 ) {
struct V_99 * V_99 = V_91 -> V_99 ;
const char * V_100 = L_21 ;
if ( V_99 && V_99 -> V_101 ) {
if ( V_83 . V_102 && V_99 -> V_101 -> V_103 )
V_100 = V_99 -> V_101 -> V_103 ;
else
V_100 = V_99 -> V_101 -> V_37 ;
}
F_4 ( V_89 , L_22 ,
F_22 ( V_100 ) ) ;
}
F_41 ( & V_87 ) ;
F_42 ( V_82 , V_89 ) ;
F_6 ( V_89 ) ;
}
exit:
return V_82 ;
}
static T_1 * F_43 ( struct V_104 * V_19 )
{
T_1 * V_18 ;
V_18 = F_19 ( 2 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
F_21 ( V_18 , 0 , F_32 ( V_19 -> V_105 ) ) ;
F_21 ( V_18 , 1 , F_32 ( V_19 -> V_19 ) ) ;
return V_18 ;
}
static void F_44 ( T_1 * V_106 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
T_2 V_107 = V_79 -> V_108 . V_107 ;
T_1 * V_109 ;
unsigned int V_70 ;
if ( V_107 & V_110 ) {
F_4 ( V_106 , L_23 ,
F_32 ( V_77 -> V_111 . V_112 ) ) ;
}
if ( V_107 & V_113 ) {
F_4 ( V_106 , L_24 ,
F_32 ( V_77 -> V_111 . V_114 ) ) ;
}
if ( V_107 & V_115 )
V_109 = F_29 ( V_77 -> V_111 . V_116 . V_117 ) ;
else
V_109 = F_29 ( 1 ) ;
if ( ! V_109 )
F_3 ( L_12 ) ;
if ( V_107 & V_115 ) {
for ( V_70 = 0 ; V_70 < V_77 -> V_111 . V_116 . V_117 ; V_70 ++ ) {
T_1 * V_18 = F_43 ( & V_77 -> V_111 . V_116 . V_109 [ V_70 ] ) ;
F_33 ( V_109 , V_70 , V_18 ) ;
}
} else {
T_1 * V_18 = F_43 ( & V_77 -> V_111 . V_118 ) ;
F_33 ( V_109 , 0 , V_18 ) ;
}
F_4 ( V_106 , L_25 , V_109 ) ;
}
static T_1 * F_45 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 ,
T_1 * V_85 )
{
T_1 * V_2 , * V_106 ;
V_2 = F_39 () ;
if ( ! V_2 )
F_3 ( L_14 ) ;
V_106 = F_39 () ;
if ( ! V_106 )
F_3 ( L_14 ) ;
F_4 ( V_2 , L_26 , F_22 ( F_46 ( V_79 ) ) ) ;
F_4 ( V_2 , L_27 , F_40 (
( const char * ) & V_79 -> V_108 , sizeof( V_79 -> V_108 ) ) ) ;
F_4 ( V_106 , L_28 ,
F_23 ( V_77 -> V_119 ) ) ;
F_4 ( V_106 , L_29 ,
F_23 ( V_77 -> V_120 ) ) ;
F_4 ( V_106 , L_30 ,
F_23 ( V_77 -> V_121 ) ) ;
F_4 ( V_106 , L_15 ,
F_32 ( V_77 -> V_92 ) ) ;
F_4 ( V_106 , L_31 ,
F_32 ( V_77 -> time ) ) ;
F_4 ( V_106 , L_32 ,
F_32 ( V_77 -> V_122 ) ) ;
F_44 ( V_106 , V_77 , V_79 ) ;
F_4 ( V_2 , L_33 , V_106 ) ;
F_4 ( V_2 , L_34 , F_40 (
( const char * ) V_77 -> V_123 , V_77 -> V_124 ) ) ;
F_4 ( V_2 , L_35 ,
F_22 ( F_47 ( V_81 -> V_86 ) ) ) ;
if ( V_81 -> V_99 ) {
F_4 ( V_2 , L_22 ,
F_22 ( V_81 -> V_99 -> V_101 -> V_37 ) ) ;
}
if ( V_81 -> V_93 ) {
F_4 ( V_2 , L_36 ,
F_22 ( V_81 -> V_93 -> V_37 ) ) ;
}
F_4 ( V_2 , L_37 , V_85 ) ;
return V_2 ;
}
static void F_48 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_28 * V_29 = V_79 -> V_125 ;
T_1 * V_5 , * V_126 , * V_18 , * V_66 = NULL , * V_85 ;
T_1 * V_2 = NULL , * V_127 = NULL ;
static char V_1 [ 256 ] ;
struct V_62 * V_23 ;
unsigned long V_128 , V_129 ;
unsigned V_20 = 0 ;
int V_119 ;
int V_121 = V_77 -> V_121 ;
void * V_63 = V_77 -> V_123 ;
unsigned long long V_130 = V_77 -> time ;
const char * V_131 = F_47 ( V_81 -> V_86 ) ;
const char * V_132 = L_38 ;
if ( ! V_29 ) {
snprintf ( V_1 , sizeof( V_1 ) ,
L_39 V_133 , ( T_2 ) V_79 -> V_108 . V_134 ) ;
F_3 ( V_1 ) ;
}
V_119 = F_49 ( V_29 , L_40 , V_63 ) ;
sprintf ( V_1 , L_41 , V_29 -> system , V_29 -> V_37 ) ;
if ( ! F_50 ( V_29 -> V_105 , V_135 ) )
F_26 ( V_29 , V_1 , V_29 -> V_136 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_5 = F_7 ( V_132 ) ;
if ( ! V_5 )
return;
V_2 = F_39 () ;
if ( ! V_2 )
F_3 ( L_42 ) ;
}
V_18 = F_19 ( V_137 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
V_128 = V_130 / V_138 ;
V_129 = V_130 - V_128 * V_138 ;
V_139 -> V_140 = V_63 ;
V_139 -> V_141 = V_79 -> V_125 -> V_141 ;
V_126 = F_51 ( V_139 , NULL ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_1 ) ) ;
F_21 ( V_18 , V_20 ++ , V_126 ) ;
V_85 = F_34 ( V_77 , V_79 , V_81 ) ;
F_52 ( V_85 ) ;
if ( ! V_2 ) {
F_21 ( V_18 , V_20 ++ , F_23 ( V_121 ) ) ;
F_21 ( V_18 , V_20 ++ , F_23 ( V_128 ) ) ;
F_21 ( V_18 , V_20 ++ , F_23 ( V_129 ) ) ;
F_21 ( V_18 , V_20 ++ , F_23 ( V_119 ) ) ;
F_21 ( V_18 , V_20 ++ , F_22 ( V_131 ) ) ;
F_21 ( V_18 , V_20 ++ , V_85 ) ;
} else {
F_4 ( V_2 , L_43 , F_23 ( V_121 ) ) ;
F_4 ( V_2 , L_44 , F_23 ( V_128 ) ) ;
F_4 ( V_2 , L_45 , F_23 ( V_129 ) ) ;
F_4 ( V_2 , L_40 , F_23 ( V_119 ) ) ;
F_4 ( V_2 , L_46 , F_22 ( V_131 ) ) ;
F_4 ( V_2 , L_47 , V_85 ) ;
}
for ( V_23 = V_29 -> V_142 . V_143 ; V_23 ; V_23 = V_23 -> V_25 ) {
unsigned int V_72 , V_144 ;
unsigned long long V_4 ;
if ( V_23 -> V_38 & V_65 ) {
V_72 = V_23 -> V_72 ;
V_144 = V_23 -> V_44 ;
if ( V_23 -> V_38 & V_145 ) {
V_4 = F_53 ( V_139 -> V_141 ,
V_63 + V_72 , V_144 ) ;
V_72 = V_4 ;
V_144 = V_72 >> 16 ;
V_72 &= 0xffff ;
}
if ( V_23 -> V_38 & V_146 &&
F_54 ( V_63 + V_72 , V_144 ) ) {
V_66 = F_22 ( ( char * ) V_63 + V_72 ) ;
} else {
V_66 = F_55 ( ( const char * ) V_63 + V_72 , V_144 ) ;
V_23 -> V_38 &= ~ V_146 ;
}
} else {
V_66 = F_28 ( V_29 , V_23 , V_63 ) ;
}
if ( ! V_2 )
F_21 ( V_18 , V_20 ++ , V_66 ) ;
else
F_4 ( V_2 , V_23 -> V_37 , V_66 ) ;
}
if ( V_2 )
F_21 ( V_18 , V_20 ++ , V_2 ) ;
if ( F_10 ( V_5 ) == ( int ) V_20 + 1 ) {
V_127 = F_45 ( V_77 , V_79 , V_81 ,
V_85 ) ;
F_21 ( V_18 , V_20 ++ , V_127 ) ;
} else {
F_6 ( V_85 ) ;
}
if ( F_56 ( & V_18 , V_20 ) == - 1 )
F_3 ( L_48 ) ;
if ( ! V_2 ) {
F_15 ( V_5 , V_18 , V_1 ) ;
} else {
F_15 ( V_5 , V_18 , V_132 ) ;
F_6 ( V_2 ) ;
}
F_57 ( V_127 ) ;
F_6 ( V_18 ) ;
}
static T_1 * F_58 ( unsigned int V_147 )
{
T_1 * V_18 ;
V_18 = F_19 ( V_147 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
return V_18 ;
}
static int F_59 ( T_1 * V_18 , unsigned int V_148 , T_2 V_4 )
{
#if V_149 == 64
return F_21 ( V_18 , V_148 , F_23 ( V_4 ) ) ;
#endif
#if V_149 == 32
return F_21 ( V_18 , V_148 , F_31 ( V_4 ) ) ;
#endif
}
static int F_60 ( T_1 * V_18 , unsigned int V_148 , T_3 V_4 )
{
return F_21 ( V_18 , V_148 , F_23 ( V_4 ) ) ;
}
static int F_61 ( T_1 * V_18 , unsigned int V_148 , const char * V_128 )
{
return F_21 ( V_18 , V_148 , F_22 ( V_128 ) ) ;
}
static int F_62 ( struct V_150 * V_151 , struct V_78 * V_79 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 2 ) ;
F_59 ( V_18 , 0 , V_79 -> V_153 ) ;
F_61 ( V_18 , 1 , F_46 ( V_79 ) ) ;
F_15 ( V_152 -> V_154 , V_18 , L_49 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_64 ( struct V_150 * V_151 ,
struct V_155 * V_155 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 3 ) ;
F_59 ( V_18 , 0 , V_155 -> V_153 ) ;
F_60 ( V_18 , 1 , V_155 -> V_119 ) ;
F_61 ( V_18 , 2 , V_155 -> V_156 ? V_155 -> V_156 : L_50 ) ;
F_15 ( V_152 -> V_157 , V_18 , L_51 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_65 ( struct V_150 * V_151 , struct V_86 * V_86 ,
T_2 V_158 , struct V_155 * V_155 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 5 ) ;
F_59 ( V_18 , 0 , V_86 -> V_153 ) ;
F_59 ( V_18 , 1 , V_155 -> V_153 ) ;
F_59 ( V_18 , 2 , V_158 ) ;
F_60 ( V_18 , 3 , V_86 -> V_159 ) ;
F_60 ( V_18 , 4 , V_86 -> V_120 ) ;
F_15 ( V_152 -> V_160 , V_18 , L_52 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_66 ( struct V_150 * V_151 , struct V_131 * V_131 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 2 ) ;
F_59 ( V_18 , 0 , V_131 -> V_153 ) ;
F_61 ( V_18 , 1 , F_67 ( V_131 ) ) ;
F_15 ( V_152 -> V_161 , V_18 , L_53 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_68 ( struct V_150 * V_151 , T_2 V_153 ,
struct V_131 * V_131 , struct V_86 * V_86 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 3 ) ;
F_59 ( V_18 , 0 , V_153 ) ;
F_59 ( V_18 , 1 , V_131 -> V_153 ) ;
F_59 ( V_18 , 2 , V_86 -> V_153 ) ;
F_15 ( V_152 -> V_162 , V_18 , L_54 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_69 ( struct V_150 * V_151 , struct V_101 * V_101 ,
struct V_155 * V_155 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
char V_163 [ V_164 ] ;
T_1 * V_18 ;
F_70 ( V_101 -> V_165 , sizeof( V_101 -> V_165 ) , V_163 ) ;
V_18 = F_58 ( 5 ) ;
F_59 ( V_18 , 0 , V_101 -> V_153 ) ;
F_59 ( V_18 , 1 , V_155 -> V_153 ) ;
F_61 ( V_18 , 2 , V_101 -> V_166 ) ;
F_61 ( V_18 , 3 , V_101 -> V_103 ) ;
F_61 ( V_18 , 4 , V_163 ) ;
F_15 ( V_152 -> V_167 , V_18 , L_55 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_71 ( struct V_150 * V_151 , struct V_39 * V_93 ,
struct V_101 * V_101 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_2 * V_168 = F_72 ( V_93 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 6 ) ;
F_59 ( V_18 , 0 , * V_168 ) ;
F_59 ( V_18 , 1 , V_101 -> V_153 ) ;
F_59 ( V_18 , 2 , V_93 -> V_95 ) ;
F_59 ( V_18 , 3 , V_93 -> V_96 ) ;
F_60 ( V_18 , 4 , V_93 -> V_97 ) ;
F_61 ( V_18 , 5 , V_93 -> V_37 ) ;
F_15 ( V_152 -> V_169 , V_18 , L_56 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_73 ( struct V_150 * V_151 , T_4 V_170 ,
const char * V_37 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 2 ) ;
F_60 ( V_18 , 0 , V_170 ) ;
F_61 ( V_18 , 1 , V_37 ) ;
F_15 ( V_152 -> V_171 , V_18 , L_57 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_74 ( struct V_150 * V_151 ,
struct V_172 * V_173 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
V_18 = F_58 ( 22 ) ;
F_59 ( V_18 , 0 , V_173 -> V_153 ) ;
F_59 ( V_18 , 1 , V_173 -> V_79 -> V_153 ) ;
F_59 ( V_18 , 2 , V_173 -> V_81 -> V_155 -> V_153 ) ;
F_59 ( V_18 , 3 , V_173 -> V_81 -> V_86 -> V_153 ) ;
F_59 ( V_18 , 4 , V_173 -> V_174 ) ;
F_59 ( V_18 , 5 , V_173 -> V_175 ) ;
F_59 ( V_18 , 6 , V_173 -> V_168 ) ;
F_59 ( V_18 , 7 , V_173 -> V_72 ) ;
F_59 ( V_18 , 8 , V_173 -> V_77 -> V_92 ) ;
F_59 ( V_18 , 9 , V_173 -> V_77 -> time ) ;
F_60 ( V_18 , 10 , V_173 -> V_77 -> V_121 ) ;
F_59 ( V_18 , 11 , V_173 -> V_176 ) ;
F_59 ( V_18 , 12 , V_173 -> V_177 ) ;
F_59 ( V_18 , 13 , V_173 -> V_178 ) ;
F_59 ( V_18 , 14 , V_173 -> V_77 -> V_179 ) ;
F_59 ( V_18 , 15 , V_173 -> V_77 -> V_122 ) ;
F_59 ( V_18 , 16 , V_173 -> V_77 -> V_180 ) ;
F_59 ( V_18 , 17 , V_173 -> V_77 -> V_181 ) ;
F_59 ( V_18 , 18 , V_173 -> V_77 -> V_182 ) ;
F_60 ( V_18 , 19 , V_173 -> V_77 -> V_38 & V_183 ) ;
F_60 ( V_18 , 20 , ! ! ( V_173 -> V_77 -> V_38 & V_184 ) ) ;
F_59 ( V_18 , 21 , V_173 -> V_185 ) ;
F_15 ( V_152 -> V_186 , V_18 , L_58 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_75 ( struct V_150 * V_151 , struct V_187 * V_188 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_1 * V_18 ;
T_2 V_189 , V_168 ;
V_189 = V_188 -> V_190 ? V_188 -> V_190 -> V_153 : 0 ;
V_168 = V_188 -> V_93 ? * ( T_2 * ) F_72 ( V_188 -> V_93 ) : 0 ;
V_18 = F_58 ( 4 ) ;
F_59 ( V_18 , 0 , V_188 -> V_153 ) ;
F_59 ( V_18 , 1 , V_189 ) ;
F_59 ( V_18 , 2 , V_168 ) ;
F_59 ( V_18 , 3 , V_188 -> V_92 ) ;
F_15 ( V_152 -> V_191 , V_18 , L_59 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_76 ( struct V_150 * V_151 ,
struct V_192 * V_193 )
{
struct V_152 * V_152 = F_63 ( V_151 , struct V_152 , V_151 ) ;
T_2 V_174 = V_193 -> V_131 ? V_193 -> V_131 -> V_153 : 0 ;
T_1 * V_18 ;
V_18 = F_58 ( 11 ) ;
F_59 ( V_18 , 0 , V_193 -> V_153 ) ;
F_59 ( V_18 , 1 , V_193 -> V_86 -> V_153 ) ;
F_59 ( V_18 , 2 , V_174 ) ;
F_59 ( V_18 , 3 , V_193 -> V_188 -> V_153 ) ;
F_59 ( V_18 , 4 , V_193 -> V_194 ) ;
F_59 ( V_18 , 5 , V_193 -> V_195 ) ;
F_59 ( V_18 , 6 , V_193 -> V_196 ) ;
F_59 ( V_18 , 7 , V_193 -> V_197 ) ;
F_59 ( V_18 , 8 , V_193 -> V_198 ) ;
F_59 ( V_18 , 9 , V_193 -> V_188 -> V_190 -> V_153 ) ;
F_60 ( V_18 , 10 , V_193 -> V_38 ) ;
F_15 ( V_152 -> V_199 , V_18 , L_60 ) ;
F_6 ( V_18 ) ;
return 0 ;
}
static int F_77 ( struct V_192 * V_193 , void * V_63 )
{
struct V_150 * V_151 = V_63 ;
return F_78 ( V_151 , V_193 ) ;
}
static void F_79 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
T_1 * V_5 , * V_18 , * V_2 , * V_85 ;
static char V_1 [ 64 ] ;
unsigned V_20 = 0 ;
snprintf ( V_1 , sizeof( V_1 ) , L_61 , L_62 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
return;
V_18 = F_19 ( V_137 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
V_85 = F_34 ( V_77 , V_79 , V_81 ) ;
V_2 = F_45 ( V_77 , V_79 , V_81 , V_85 ) ;
F_21 ( V_18 , V_20 ++ , V_2 ) ;
if ( F_56 ( & V_18 , V_20 ) == - 1 )
F_3 ( L_48 ) ;
F_15 ( V_5 , V_18 , V_1 ) ;
F_6 ( V_2 ) ;
F_6 ( V_18 ) ;
}
static void F_80 ( union V_200 * V_29 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_152 * V_152 = & V_201 ;
switch ( V_79 -> V_108 . type ) {
case V_202 :
F_48 ( V_77 , V_79 , V_81 ) ;
break;
default:
if ( V_152 -> V_203 )
F_81 ( & V_152 -> V_151 , V_29 , V_77 , V_79 , V_81 ) ;
else
F_79 ( V_77 , V_79 , V_81 ) ;
}
}
static void F_82 ( char * V_24 , T_5 V_44 ,
struct V_78 * V_79 )
{
char * V_204 = V_24 ;
F_83 ( V_24 , V_44 , L_63 , F_46 ( V_79 ) ) ;
while ( ( V_204 = strchr ( V_204 , ':' ) ) ) {
* V_204 = '_' ;
V_204 ++ ;
}
}
static void
F_84 ( struct V_78 * V_205 , int V_121 , int V_86 , T_2 V_206 ,
struct V_207 * V_47 )
{
T_1 * V_5 , * V_18 ;
static char V_1 [ 256 ] ;
int V_20 = 0 ;
V_18 = F_19 ( V_137 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
F_82 ( V_1 , sizeof( V_1 ) ,
V_205 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_85 ( L_64 , V_1 ) ;
return;
}
F_21 ( V_18 , V_20 ++ , F_23 ( V_121 ) ) ;
F_21 ( V_18 , V_20 ++ , F_23 ( V_86 ) ) ;
F_59 ( V_18 , V_20 ++ , V_206 ) ;
F_59 ( V_18 , V_20 ++ , V_47 -> V_4 ) ;
F_59 ( V_18 , V_20 ++ , V_47 -> V_208 ) ;
F_59 ( V_18 , V_20 ++ , V_47 -> V_209 ) ;
if ( F_56 ( & V_18 , V_20 ) == - 1 )
F_3 ( L_48 ) ;
F_15 ( V_5 , V_18 , V_1 ) ;
F_6 ( V_18 ) ;
}
static void F_86 ( struct V_210 * V_134 ,
struct V_78 * V_205 , T_2 V_206 )
{
struct V_211 * V_212 = V_205 -> V_212 ;
struct V_213 * V_214 = V_205 -> V_214 ;
int V_121 , V_86 ;
if ( V_134 -> V_215 == V_216 ) {
F_84 ( V_205 , - 1 , - 1 , V_206 ,
& V_205 -> V_217 -> V_218 ) ;
return;
}
for ( V_86 = 0 ; V_86 < V_212 -> V_117 ; V_86 ++ ) {
for ( V_121 = 0 ; V_121 < V_214 -> V_117 ; V_121 ++ ) {
F_84 ( V_205 , V_214 -> V_99 [ V_121 ] ,
F_87 ( V_212 , V_86 ) , V_206 ,
F_88 ( V_205 -> V_217 , V_121 , V_86 ) ) ;
}
}
}
static void F_89 ( T_2 V_206 )
{
T_1 * V_5 , * V_18 ;
static const char V_1 [] = L_65 ;
int V_20 = 0 ;
V_18 = F_19 ( V_137 ) ;
if ( ! V_18 )
F_3 ( L_7 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_85 ( L_64 , V_1 ) ;
return;
}
F_59 ( V_18 , V_20 ++ , V_206 ) ;
if ( F_56 ( & V_18 , V_20 ) == - 1 )
F_3 ( L_48 ) ;
F_15 ( V_5 , V_18 , V_1 ) ;
F_6 ( V_18 ) ;
}
static int F_90 ( void )
{
V_219 = F_91 ( L_66 ) ;
if ( V_219 == NULL )
return - 1 ;
F_52 ( V_219 ) ;
V_6 = F_92 ( V_219 ) ;
if ( V_6 == NULL )
goto error;
F_52 ( V_6 ) ;
F_17 ( L_67 , NULL ) ;
return 0 ;
error:
F_57 ( V_6 ) ;
F_57 ( V_219 ) ;
return - 1 ;
}
static void F_93 ( struct V_152 * V_152 )
{
const char * V_220 = L_68 ;
const char * V_221 = L_69 ;
const char * V_222 = L_70 ;
T_1 * V_203 , * V_223 , * V_224 ;
bool V_225 = false ;
bool V_226 = false ;
int V_227 ;
memset ( V_152 , 0 , sizeof( struct V_152 ) ) ;
if ( F_94 ( & V_152 -> V_151 ) )
F_3 ( L_71 ) ;
V_203 = F_8 ( V_6 , V_220 ) ;
if ( ! V_203 )
return;
V_227 = F_95 ( V_203 ) ;
if ( V_227 == - 1 )
F_1 ( V_220 ) ;
if ( ! V_227 )
return;
V_152 -> V_151 . V_228 = NULL ;
V_223 = F_8 ( V_6 , V_221 ) ;
if ( V_223 ) {
V_227 = F_95 ( V_223 ) ;
if ( V_227 == - 1 )
F_1 ( V_221 ) ;
V_225 = ! ! V_227 ;
}
if ( V_225 ) {
V_152 -> V_151 . V_228 =
F_96 ( F_77 ,
& V_152 -> V_151 ) ;
if ( ! V_152 -> V_151 . V_228 )
F_3 ( L_72 ) ;
}
V_152 -> V_151 . V_229 = NULL ;
V_224 = F_8 ( V_6 ,
V_222 ) ;
if ( V_224 ) {
V_227 = F_95 ( V_224 ) ;
if ( V_227 == - 1 )
F_1 ( V_222 ) ;
V_226 = ! ! V_227 ;
}
if ( V_226 ) {
if ( V_152 -> V_151 . V_228 )
V_152 -> V_151 . V_229 = V_152 -> V_151 . V_228 -> V_229 ;
else
V_152 -> V_151 . V_229 = F_97 () ;
if ( ! V_152 -> V_151 . V_229 )
F_3 ( L_73 ) ;
}
V_152 -> V_203 = true ;
V_83 . V_230 = sizeof( T_2 ) ;
F_98 ( V_79 ) ;
F_98 ( V_155 ) ;
F_98 ( V_86 ) ;
F_98 ( V_131 ) ;
F_98 ( V_231 ) ;
F_98 ( V_101 ) ;
F_98 ( V_39 ) ;
F_98 ( V_170 ) ;
F_98 ( V_77 ) ;
F_98 ( V_187 ) ;
F_98 ( V_192 ) ;
}
static int F_99 ( const char * V_232 , int V_233 , const char * * V_234 )
{
struct V_152 * V_152 = & V_201 ;
const char * * V_235 ;
char V_236 [ V_237 ] ;
int V_70 , V_238 = 0 ;
T_6 * V_239 ;
V_235 = malloc ( ( V_233 + 1 ) * sizeof( const char * ) ) ;
V_235 [ 0 ] = V_232 ;
for ( V_70 = 1 ; V_70 < V_233 + 1 ; V_70 ++ )
V_235 [ V_70 ] = V_234 [ V_70 - 1 ] ;
F_100 () ;
F_101 () ;
F_102 ( V_233 + 1 , ( char * * ) V_235 ) ;
V_239 = fopen ( V_232 , L_74 ) ;
if ( ! V_239 ) {
sprintf ( V_236 , L_75 , V_232 ) ;
perror ( V_236 ) ;
V_238 = - 1 ;
goto error;
}
V_238 = F_103 ( V_239 , V_232 ) ;
if ( V_238 ) {
fprintf ( V_240 , L_76 , V_232 ) ;
goto error;
}
V_238 = F_90 () ;
if ( V_238 ) {
fprintf ( V_240 , L_77 , V_232 ) ;
goto error;
}
F_93 ( V_152 ) ;
if ( V_152 -> V_203 ) {
V_238 = F_104 ( & V_152 -> V_151 ) ;
if ( V_238 )
goto error;
}
free ( V_235 ) ;
return V_238 ;
error:
F_105 () ;
free ( V_235 ) ;
return V_238 ;
}
static int F_106 ( void )
{
struct V_152 * V_152 = & V_201 ;
return F_107 ( & V_152 -> V_151 ) ;
}
static int F_108 ( void )
{
struct V_152 * V_152 = & V_201 ;
F_17 ( L_78 , NULL ) ;
F_109 ( & V_152 -> V_151 ) ;
F_57 ( V_6 ) ;
F_57 ( V_219 ) ;
F_105 () ;
return 0 ;
}
static int F_110 ( struct V_141 * V_141 , const char * V_241 )
{
struct V_28 * V_29 = NULL ;
struct V_62 * V_242 ;
char V_243 [ V_237 ] ;
int V_244 , V_47 ;
T_6 * V_245 ;
sprintf ( V_243 , L_79 , V_241 ) ;
V_245 = fopen ( V_243 , L_80 ) ;
if ( V_245 == NULL ) {
fprintf ( V_240 , L_81 , V_243 ) ;
return - 1 ;
}
fprintf ( V_245 , L_82
L_83 ) ;
fprintf ( V_245 , L_84
L_85 ) ;
fprintf ( V_245 , L_86
L_87 ) ;
fprintf ( V_245 , L_88
L_89 ) ;
fprintf ( V_245 , L_90
L_91 ) ;
fprintf ( V_245 , L_92
L_93 ) ;
fprintf ( V_245 , L_94
L_95 ) ;
fprintf ( V_245 , L_96 ) ;
fprintf ( V_245 , L_97 ) ;
fprintf ( V_245 , L_98 ) ;
fprintf ( V_245 , L_99 ) ;
fprintf ( V_245 , L_100 ) ;
fprintf ( V_245 , L_101 ) ;
fprintf ( V_245 , L_102 ) ;
fprintf ( V_245 , L_103 ) ;
fprintf ( V_245 , L_104 ) ;
fprintf ( V_245 , L_105 ) ;
while ( ( V_29 = F_111 ( V_141 , V_29 ) ) ) {
fprintf ( V_245 , L_106 , V_29 -> system , V_29 -> V_37 ) ;
fprintf ( V_245 , L_107 ) ;
fprintf ( V_245 , L_108 ) ;
fprintf ( V_245 , L_109 ) ;
fprintf ( V_245 , L_110 ) ;
fprintf ( V_245 , L_111 ) ;
fprintf ( V_245 , L_112 ) ;
fprintf ( V_245 , L_113 ) ;
fprintf ( V_245 , L_114 ) ;
V_244 = 0 ;
V_47 = 0 ;
for ( V_242 = V_29 -> V_142 . V_143 ; V_242 ; V_242 = V_242 -> V_25 ) {
if ( V_244 ++ )
fprintf ( V_245 , L_115 ) ;
if ( ++ V_47 % 5 == 0 )
fprintf ( V_245 , L_116 ) ;
fprintf ( V_245 , L_61 , V_242 -> V_37 ) ;
}
if ( V_244 ++ )
fprintf ( V_245 , L_115 ) ;
if ( ++ V_47 % 5 == 0 )
fprintf ( V_245 , L_117 ) ;
fprintf ( V_245 , L_118 ) ;
fprintf ( V_245 , L_119 ) ;
fprintf ( V_245 , L_120
L_121
L_122 ) ;
fprintf ( V_245 , L_123 ) ;
V_244 = 0 ;
V_47 = 0 ;
for ( V_242 = V_29 -> V_142 . V_143 ; V_242 ; V_242 = V_242 -> V_25 ) {
if ( V_244 ++ )
fprintf ( V_245 , L_115 ) ;
if ( V_47 && V_47 % 3 == 0 ) {
fprintf ( V_245 , L_124 ) ;
}
V_47 ++ ;
fprintf ( V_245 , L_125 , V_242 -> V_37 ) ;
if ( V_242 -> V_38 & V_146 ||
V_242 -> V_38 & V_246 ||
V_242 -> V_38 & V_65 ||
V_242 -> V_38 & V_247 )
fprintf ( V_245 , L_126 ) ;
else if ( V_242 -> V_38 & V_73 )
fprintf ( V_245 , L_127 ) ;
else
fprintf ( V_245 , L_128 ) ;
}
fprintf ( V_245 , L_129 ) ;
V_244 = 0 ;
V_47 = 0 ;
for ( V_242 = V_29 -> V_142 . V_143 ; V_242 ; V_242 = V_242 -> V_25 ) {
if ( V_244 ++ )
fprintf ( V_245 , L_115 ) ;
if ( ++ V_47 % 5 == 0 )
fprintf ( V_245 , L_117 ) ;
if ( V_242 -> V_38 & V_246 ) {
if ( ( V_47 - 1 ) % 5 != 0 ) {
fprintf ( V_245 , L_117 ) ;
V_47 = 4 ;
}
fprintf ( V_245 , L_130 ) ;
fprintf ( V_245 , L_131 , V_29 -> system ,
V_29 -> V_37 ) ;
fprintf ( V_245 , L_132 , V_242 -> V_37 ,
V_242 -> V_37 ) ;
} else if ( V_242 -> V_38 & V_247 ) {
if ( ( V_47 - 1 ) % 5 != 0 ) {
fprintf ( V_245 , L_117 ) ;
V_47 = 4 ;
}
fprintf ( V_245 , L_133 ) ;
fprintf ( V_245 , L_131 , V_29 -> system ,
V_29 -> V_37 ) ;
fprintf ( V_245 , L_132 , V_242 -> V_37 ,
V_242 -> V_37 ) ;
} else
fprintf ( V_245 , L_61 , V_242 -> V_37 ) ;
}
fprintf ( V_245 , L_134 ) ;
fprintf ( V_245 , L_135
L_136 ) ;
fprintf ( V_245 , L_137 ) ;
fprintf ( V_245 , L_138 ) ;
fprintf ( V_245 , L_139 ) ;
fprintf ( V_245 , L_140 ) ;
fprintf ( V_245 , L_141 ) ;
fprintf ( V_245 , L_142 ) ;
}
fprintf ( V_245 , L_143
L_144 ) ;
fprintf ( V_245 , L_145 ) ;
fprintf ( V_245 , L_135
L_136 ) ;
fprintf ( V_245 , L_146
L_147
L_148
L_149 ) ;
fprintf ( V_245 , L_150
L_151
L_152 ) ;
fclose ( V_245 ) ;
fprintf ( V_240 , L_153 , V_243 ) ;
return 0 ;
}
