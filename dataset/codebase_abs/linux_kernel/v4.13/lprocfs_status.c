int F_1 ( char * V_1 , int V_2 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 , V_7 = 0 ;
for ( V_6 = 0 ; V_8 [ V_6 ] ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 )
V_7 += snprintf ( V_1 + V_7 , V_2 - V_7 , L_1 ,
V_7 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
}
if ( V_3 & ~ ( V_5 - 1 ) )
V_7 += snprintf ( V_1 + V_7 , V_2 - V_7 ,
L_3 ,
V_7 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
return V_7 ;
}
static void F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
T_2 V_3 ;
F_3 ( V_12 ) ;
V_3 = V_12 -> V_13 ;
F_4 ( V_10 , L_4
L_5
L_6 ,
V_12 -> V_13 ,
V_12 -> V_14 ) ;
if ( V_3 & V_15 )
F_4 ( V_10 , L_7 ,
F_5 ( V_12 -> V_16 ) ,
F_6 ( V_12 -> V_16 ) ,
F_7 ( V_12 -> V_16 ) ,
F_8 ( V_12 -> V_16 ) ) ;
if ( V_3 & V_17 )
F_4 ( V_10 , L_8 , V_12 -> V_18 ) ;
if ( V_3 & V_19 )
F_4 ( V_10 , L_9 , V_12 -> V_20 ) ;
if ( V_3 & V_21 )
F_4 ( V_10 , L_10 , V_12 -> V_22 ) ;
if ( V_3 & V_23 )
F_4 ( V_10 , L_11 , V_12 -> V_24 ) ;
if ( V_3 & V_25 )
F_4 ( V_10 , L_12 ,
V_12 -> V_26 ) ;
if ( V_3 & V_27 )
F_4 ( V_10 , L_13
L_14
L_15 ,
V_12 -> V_28 ,
V_12 -> V_29 ,
V_12 -> V_30 ) ;
if ( V_3 & V_31 )
F_4 ( V_10 , L_16 ,
V_12 -> V_32 ) ;
if ( V_3 & V_33 )
F_4 ( V_10 , L_17 ,
V_12 -> V_34 ) ;
if ( V_3 & V_35 )
F_4 ( V_10 , L_18 , V_12 -> V_36 ) ;
if ( V_3 & V_37 )
F_4 ( V_10 , L_19 ,
V_12 -> V_38 ) ;
if ( V_3 & V_39 )
F_4 ( V_10 , L_20 ,
V_12 -> V_40 ) ;
}
int F_9 ( char * V_41 , unsigned long V_2 , long V_42 ,
int V_43 )
{
long V_44 , V_45 ;
int V_46 ;
if ( V_2 < 10 )
return - V_47 ;
V_44 = V_42 / V_43 ;
V_46 = snprintf ( V_41 , V_2 , L_21 , V_44 ) ;
V_45 = V_42 % V_43 ;
if ( V_46 < ( V_2 - 4 ) && V_45 > 0 ) {
long V_48 ;
int V_6 , V_49 = 1 , V_50 = 0 ;
V_48 = V_45 * 10 ;
V_41 [ V_46 ++ ] = '.' ;
while ( V_50 < 2 && ( V_48 / V_43 ) < 1 ) {
V_41 [ V_46 ++ ] = '0' ;
V_48 *= 10 ;
V_50 ++ ;
}
for ( V_6 = 0 ; V_6 < ( 5 - V_46 ) ; V_6 ++ )
V_49 *= 10 ;
V_50 = F_10 ( ( int ) V_2 - V_46 , 3 - V_50 ) ;
V_46 += snprintf ( V_41 + V_46 , V_50 , L_21 ,
V_45 * V_49 / V_43 ) ;
V_46 -- ;
while ( V_41 [ V_46 ] < '1' || V_41 [ V_46 ] > '9' ) {
V_46 -- ;
if ( V_41 [ V_46 ] == '.' ) {
V_46 -- ;
break;
}
}
V_46 ++ ;
}
V_41 [ V_46 ++ ] = '\n' ;
return V_46 ;
}
int F_11 ( const char T_3 * V_41 , unsigned long V_2 ,
int * V_42 , int V_43 )
{
char V_51 [ 20 ] , * V_52 , * V_53 ;
if ( V_2 > ( sizeof( V_51 ) - 1 ) )
return - V_47 ;
if ( F_12 ( V_51 , V_41 , V_2 ) )
return - V_54 ;
V_51 [ V_2 ] = '\0' ;
V_53 = V_51 ;
if ( * V_53 == '-' ) {
V_43 = - V_43 ;
V_53 ++ ;
}
* V_42 = ( int ) F_13 ( V_53 , & V_52 , 10 ) * V_43 ;
if ( V_53 == V_52 )
return - V_47 ;
if ( V_52 && * V_52 == '.' ) {
int V_55 , pow = 1 ;
int V_6 ;
V_53 = V_52 + 1 ;
if ( strlen ( V_53 ) > 5 )
V_53 [ 5 ] = '\0' ;
V_55 = ( int ) F_13 ( V_53 , & V_52 , 10 ) * V_43 ;
if ( V_53 < V_52 ) {
for ( V_6 = 0 ; V_6 < ( V_52 - V_53 ) ; V_6 ++ )
pow *= 10 ;
* V_42 += V_55 / pow ;
}
}
return 0 ;
}
int F_14 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_15 ( V_56 , V_57 ) ;
}
int F_16 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_17 ( V_56 , V_57 ) ;
}
struct V_58 * F_18 ( struct V_58 * V_59 ,
char * V_60 , void * V_61 ,
const struct V_62 * V_63 )
{
struct V_58 * V_64 ;
T_4 V_65 = 0 ;
if ( ! V_59 || ! V_60 || ! V_63 )
return F_19 ( - V_47 ) ;
if ( V_63 -> V_66 )
V_65 = 0444 ;
if ( V_63 -> V_67 )
V_65 |= 0200 ;
V_64 = F_20 ( V_60 , V_65 , V_59 , V_61 , V_63 ) ;
if ( F_21 ( V_64 ) ) {
F_22 ( L_22 , V_60 ) ;
return V_64 ? : F_19 ( - V_68 ) ;
}
return V_64 ;
}
int F_23 ( struct V_58 * V_69 ,
struct V_70 * V_71 ,
void * V_61 )
{
if ( F_21 ( V_69 ) || F_21 ( V_71 ) )
return - V_47 ;
while ( V_71 -> V_60 ) {
struct V_58 * V_64 ;
T_4 V_65 = 0 ;
if ( V_71 -> V_72 != 0000 ) {
V_65 = V_71 -> V_72 ;
} else if ( V_71 -> V_63 ) {
if ( V_71 -> V_63 -> V_66 )
V_65 = 0444 ;
if ( V_71 -> V_63 -> V_67 )
V_65 |= 0200 ;
}
V_64 = F_20 ( V_71 -> V_60 , V_65 , V_69 ,
V_71 -> V_61 ? : V_61 ,
V_71 -> V_63 ? : & V_73
) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
V_71 ++ ;
}
return 0 ;
}
void F_25 ( struct V_58 * * V_74 )
{
F_26 ( * V_74 ) ;
* V_74 = NULL ;
}
struct V_58 * F_27 ( const char * V_60 ,
struct V_58 * V_69 ,
struct V_70 * V_71 , void * V_61 )
{
struct V_58 * V_64 ;
V_64 = F_28 ( V_60 , V_69 ) ;
if ( F_21 ( V_64 ) ) {
V_64 = V_64 ? : F_19 ( - V_68 ) ;
goto V_75;
}
if ( ! F_21 ( V_71 ) ) {
int V_76 ;
V_76 = F_23 ( V_64 , V_71 , V_61 ) ;
if ( V_76 != 0 ) {
F_29 ( V_64 ) ;
V_64 = F_19 ( V_76 ) ;
}
}
V_75:
return V_64 ;
}
static T_5 F_30 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
return sprintf ( V_81 , L_23 , V_83 -> V_85 . V_86 ) ;
}
static T_5 F_32 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 )
return sprintf ( V_81 , L_24 , V_88 . V_92 ) ;
return V_76 ;
}
static T_5 F_34 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 ) {
T_6 V_93 = V_88 . V_92 >> 10 ;
T_1 V_94 = V_88 . V_95 ;
while ( V_93 >>= 1 )
V_94 <<= 1 ;
return sprintf ( V_81 , L_25 , V_94 ) ;
}
return V_76 ;
}
static T_5 F_35 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 ) {
T_6 V_93 = V_88 . V_92 >> 10 ;
T_1 V_94 = V_88 . V_96 ;
while ( V_93 >>= 1 )
V_94 <<= 1 ;
return sprintf ( V_81 , L_25 , V_94 ) ;
}
return V_76 ;
}
static T_5 F_36 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 ) {
T_6 V_93 = V_88 . V_92 >> 10 ;
T_1 V_94 = V_88 . V_97 ;
while ( V_93 >>= 1 )
V_94 <<= 1 ;
return sprintf ( V_81 , L_25 , V_94 ) ;
}
return V_76 ;
}
static T_5 F_37 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 )
return sprintf ( V_81 , L_25 , V_88 . V_98 ) ;
return V_76 ;
}
static T_5 F_38 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
struct V_87 V_88 ;
int V_76 = V_87 ( NULL , V_83 -> V_89 , & V_88 ,
F_33 ( - V_90 ) ,
V_91 ) ;
if ( ! V_76 )
return sprintf ( V_81 , L_25 , V_88 . V_99 ) ;
return V_76 ;
}
int F_39 ( struct V_9 * V_10 , void * V_61 )
{
struct V_82 * V_83 = V_61 ;
struct V_100 * V_101 ;
char * V_102 = NULL ;
int V_76 ;
F_3 ( V_83 ) ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_101 = V_83 -> V_103 . V_104 . V_105 ;
V_102 = F_41 ( V_101 -> V_106 ) ;
F_4 ( V_10 , L_26 ,
F_42 ( V_83 ) , V_102 ,
V_101 -> V_107 ? L_27 : L_2 ) ;
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
int F_44 ( struct V_9 * V_10 , void * V_61 )
{
struct V_82 * V_83 = V_61 ;
struct V_109 * V_110 ;
int V_76 ;
F_3 ( V_83 ) ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_110 = V_83 -> V_103 . V_104 . V_105 -> V_111 ;
if ( V_110 && V_83 -> V_103 . V_104 . V_105 )
F_4 ( V_10 , L_23 , V_110 -> V_112 . V_86 ) ;
else
F_45 ( V_10 , L_28 ) ;
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
int F_46 ( struct V_113 * V_114 ,
enum V_115 V_116 ,
unsigned long * V_3 )
{
if ( V_114 -> V_117 & V_118 ) {
if ( V_114 -> V_117 & V_119 )
F_47 ( & V_114 -> V_120 , * V_3 ) ;
else
F_48 ( & V_114 -> V_120 ) ;
return V_116 == V_121 ? 1 : 0 ;
}
switch ( V_116 ) {
case V_122 : {
unsigned int V_123 = F_49 () ;
if ( F_50 ( ! V_114 -> V_124 [ V_123 ] ) ) {
int V_76 = F_51 ( V_114 , V_123 ) ;
if ( V_76 < 0 ) {
F_52 () ;
return V_76 ;
}
}
return V_123 ;
}
case V_121 :
return V_114 -> V_125 ;
default:
F_53 () ;
}
}
void F_54 ( struct V_113 * V_114 ,
enum V_115 V_116 ,
unsigned long * V_3 )
{
if ( V_114 -> V_117 & V_118 ) {
if ( V_114 -> V_117 & V_119 )
F_55 ( & V_114 -> V_120 , * V_3 ) ;
else
F_56 ( & V_114 -> V_120 ) ;
} else if ( V_116 == V_122 ) {
F_52 () ;
}
}
void F_57 ( struct V_113 * V_114 , int V_126 ,
struct V_127 * V_128 )
{
unsigned int V_129 ;
struct V_127 * V_130 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
if ( ! V_114 ) {
V_128 -> V_131 = 1 ;
return;
}
V_128 -> V_132 = V_133 ;
V_129 = F_46 ( V_114 , V_121 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
if ( ! V_114 -> V_124 [ V_6 ] )
continue;
V_130 = F_58 ( V_114 , V_6 , V_126 ) ;
V_128 -> V_131 += V_130 -> V_131 ;
V_128 -> V_134 += V_130 -> V_134 ;
if ( V_130 -> V_132 < V_128 -> V_132 )
V_128 -> V_132 = V_130 -> V_132 ;
if ( V_130 -> V_135 > V_128 -> V_135 )
V_128 -> V_135 = V_130 -> V_135 ;
V_128 -> V_136 += V_130 -> V_136 ;
}
F_54 ( V_114 , V_121 , & V_3 ) ;
}
static int F_59 ( struct V_100 * V_101 , struct V_9 * V_10 )
{
bool V_137 = true ;
if ( V_101 -> V_138 -> V_139 ) {
F_45 ( V_10 , L_29 ) ;
V_137 = false ;
}
F_60 ( V_140 , V_137 ) ;
V_137 = false ;
F_60 ( V_141 , V_137 ) ;
F_60 ( V_142 , V_137 ) ;
F_60 ( V_143 , V_137 ) ;
return 0 ;
}
static void F_61 ( struct V_9 * V_10 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_137 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_4 ( V_10 , L_1 ,
V_137 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_137 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_4 ( V_10 , L_3 ,
V_137 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_62 ( struct V_9 * V_10 , void * V_61 )
{
char V_144 [ V_145 ] ;
struct V_127 V_7 ;
struct V_146 * V_147 ;
struct V_82 * V_83 = V_61 ;
struct V_100 * V_101 ;
struct V_148 * V_110 ;
struct V_11 * V_12 ;
int V_149 ;
int V_150 ;
int V_151 = 0 ;
int V_76 ;
F_3 ( V_83 ) ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_101 = V_83 -> V_103 . V_104 . V_105 ;
V_12 = & V_101 -> V_152 ;
F_4 ( V_10 , L_30
L_31
L_32
L_33
L_34
L_35 ,
V_83 -> V_153 ,
F_42 ( V_83 ) ,
F_41 ( V_101 -> V_106 ) ,
V_101 -> V_152 . V_14 ) ;
F_61 ( V_10 , V_101 -> V_152 . V_13 ,
L_36 ) ;
F_45 ( V_10 , L_37 ) ;
F_2 ( V_10 , V_12 ) ;
F_45 ( V_10 , L_38 ) ;
F_59 ( V_101 , V_10 ) ;
F_45 ( V_10 ,
L_37
L_39
L_40 ) ;
F_48 ( & V_101 -> V_154 ) ;
V_149 = 0 ;
F_63 (conn, &imp->imp_conn_list, oic_item) {
F_64 ( V_110 -> V_155 -> V_156 . V_157 ,
V_144 , sizeof( V_144 ) ) ;
F_4 ( V_10 , L_1 , V_149 ? L_36 : L_2 , V_144 ) ;
V_149 ++ ;
}
if ( V_101 -> V_111 )
F_64 ( V_101 -> V_111 -> V_156 . V_157 ,
V_144 , sizeof( V_144 ) ) ;
else
strncpy ( V_144 , L_41 , sizeof( V_144 ) ) ;
F_4 ( V_10 ,
L_37
L_42
L_43
L_44
L_45 ,
V_144 ,
V_101 -> V_158 ,
V_101 -> V_159 ,
F_65 ( & V_101 -> V_160 ) ) ;
F_56 ( & V_101 -> V_154 ) ;
if ( ! V_83 -> V_161 )
goto V_162;
V_147 = & V_83 -> V_161 -> V_163 [ V_164 ] ;
F_57 ( V_83 -> V_161 , V_164 , & V_7 ) ;
if ( V_7 . V_131 != 0 ) {
T_1 V_165 = V_7 . V_134 ;
F_66 ( V_165 , V_7 . V_131 ) ;
V_7 . V_134 = V_165 ;
} else {
V_7 . V_134 = 0 ;
}
F_4 ( V_10 ,
L_46
L_47
L_48
L_49
L_50 ,
F_65 ( & V_101 -> V_166 ) ,
F_65 ( & V_101 -> V_167 ) ,
F_65 ( & V_101 -> V_168 ) ,
V_7 . V_134 , V_147 -> V_169 ) ;
V_150 = 0 ;
for ( V_149 = 0 ; V_149 < V_170 ; V_149 ++ ) {
if ( V_101 -> V_171 . V_172 [ V_149 ] == 0 )
break;
V_150 = F_67 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_4 ( V_10 ,
L_51
L_52
L_53 ,
V_150 ,
F_68 ( & V_101 -> V_171 . V_173 ) ) ;
F_4 ( V_10 ,
L_54
L_55
L_56
L_57 ,
V_101 -> V_174 ,
V_101 -> V_175 ,
V_101 -> V_176 ) ;
for ( V_151 = 0 ; V_151 <= 1 ; V_151 ++ ) {
F_57 ( V_83 -> V_161 ,
V_177 + V_178 + V_151 ,
& V_7 ) ;
if ( V_7 . V_134 > 0 && V_7 . V_131 > 0 ) {
T_1 V_165 = V_7 . V_134 ;
F_66 ( V_165 , V_7 . V_131 ) ;
V_7 . V_134 = V_165 ;
F_4 ( V_10 ,
L_58
L_59 ,
V_151 ? L_60 : L_61 ,
V_7 . V_134 ) ;
}
V_150 = ( int ) V_7 . V_134 ;
V_149 = F_69 ( V_179 + V_151 ) + V_180 ;
V_147 = & V_83 -> V_161 -> V_163 [ V_149 ] ;
F_57 ( V_83 -> V_161 , V_149 , & V_7 ) ;
if ( V_7 . V_134 > 0 && V_7 . V_131 != 0 ) {
T_1 V_165 = V_7 . V_134 ;
F_66 ( V_165 , V_7 . V_131 ) ;
V_7 . V_134 = V_165 ;
F_4 ( V_10 ,
L_62 ,
V_147 -> V_169 , V_7 . V_134 ) ;
V_149 = ( int ) V_7 . V_134 ;
if ( V_149 > 0 )
F_4 ( V_10 ,
L_63 ,
V_150 / V_149 , ( 100 * V_150 / V_149 ) % 100 ) ;
}
}
V_162:
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
int F_70 ( struct V_9 * V_10 , void * V_61 )
{
struct V_82 * V_83 = V_61 ;
struct V_100 * V_101 ;
int V_149 , V_150 , V_76 ;
F_3 ( V_83 ) ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_101 = V_83 -> V_103 . V_104 . V_105 ;
F_4 ( V_10 , L_64 ,
F_41 ( V_101 -> V_106 ) ) ;
F_45 ( V_10 , L_65 ) ;
V_150 = V_101 -> V_181 ;
for ( V_149 = 0 ; V_149 < V_182 ; V_149 ++ ) {
struct V_183 * V_184 =
& V_101 -> V_185 [ ( V_150 + V_149 ) % V_182 ] ;
if ( V_184 -> V_186 == 0 )
continue;
F_4 ( V_10 , L_66 , ( V_187 ) V_184 -> V_188 ,
F_41 ( V_184 -> V_186 ) ) ;
}
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
int F_71 ( struct V_9 * V_10 , struct V_189 * V_190 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_191 ; V_6 ++ )
F_4 ( V_10 , L_67 , V_190 -> V_192 [ V_6 ] ) ;
F_45 ( V_10 , L_68 ) ;
return 0 ;
}
int F_72 ( struct V_9 * V_10 , void * V_61 )
{
struct V_82 * V_83 = V_61 ;
struct V_100 * V_101 ;
unsigned int V_193 , V_194 ;
T_7 V_195 , V_196 ;
struct V_197 V_198 ;
int V_6 , V_76 ;
F_3 ( V_83 ) ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_101 = V_83 -> V_103 . V_104 . V_105 ;
V_195 = F_73 () ;
F_74 ( & V_198 , V_195 - V_101 -> V_199 ) ;
F_4 ( V_10 , L_69 V_200 L_70 ,
L_71 , ( V_187 ) V_101 -> V_199 , F_75 ( & V_198 ) ) ;
V_193 = F_68 ( & V_101 -> V_171 . V_173 ) ;
V_194 = V_101 -> V_171 . V_173 . V_201 ;
V_196 = V_101 -> V_171 . V_173 . V_202 ;
F_74 ( & V_198 , V_195 - V_196 ) ;
F_4 ( V_10 , L_72 V_200 L_73 ,
L_74 , V_193 , V_194 , ( V_187 ) V_196 , F_75 ( & V_198 ) ) ;
F_71 ( V_10 , & V_101 -> V_171 . V_173 ) ;
for ( V_6 = 0 ; V_6 < V_170 ; V_6 ++ ) {
if ( V_101 -> V_171 . V_172 [ V_6 ] == 0 )
break;
V_193 = F_68 ( & V_101 -> V_171 . V_203 [ V_6 ] ) ;
V_194 = V_101 -> V_171 . V_203 [ V_6 ] . V_201 ;
V_196 = V_101 -> V_171 . V_203 [ V_6 ] . V_202 ;
F_74 ( & V_198 , V_195 - V_196 ) ;
F_4 ( V_10 , L_75
V_200 L_73 , V_101 -> V_171 . V_172 [ V_6 ] ,
V_193 , V_194 , ( V_187 ) V_196 , F_75 ( & V_198 ) ) ;
F_71 ( V_10 , & V_101 -> V_171 . V_203 [ V_6 ] ) ;
}
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
int F_76 ( struct V_9 * V_10 , void * V_61 )
{
struct V_82 * V_83 = V_61 ;
T_1 V_3 ;
int V_76 ;
V_76 = F_40 ( V_83 ) ;
if ( V_76 )
return V_76 ;
V_3 = V_83 -> V_103 . V_104 . V_105 -> V_152 . V_13 ;
F_4 ( V_10 , L_76 , V_3 ) ;
F_61 ( V_10 , V_3 , L_68 ) ;
F_45 ( V_10 , L_68 ) ;
F_43 ( & V_83 -> V_103 . V_104 . V_108 ) ;
return 0 ;
}
static void F_77 ( struct V_77 * V_78 )
{
struct V_82 * V_83 = F_31 ( V_78 , struct V_82 ,
V_84 ) ;
F_78 ( & V_83 -> V_204 ) ;
}
int F_79 ( struct V_82 * V_83 , struct V_70 * V_71 ,
struct V_205 * V_206 )
{
int V_76 = 0 ;
F_80 ( & V_83 -> V_204 ) ;
V_76 = F_81 ( & V_83 -> V_84 , & V_207 ,
V_83 -> V_208 -> V_209 ,
L_77 , V_83 -> V_153 ) ;
if ( V_76 )
return V_76 ;
if ( V_206 ) {
V_76 = F_82 ( & V_83 -> V_84 , V_206 ) ;
if ( V_76 ) {
F_83 ( & V_83 -> V_84 ) ;
return V_76 ;
}
}
V_83 -> V_210 = F_27 ( V_83 -> V_153 ,
V_83 -> V_208 -> V_211 ,
V_71 , V_83 ) ;
if ( F_21 ( V_83 -> V_210 ) ) {
V_76 = V_83 -> V_210 ? F_24 ( V_83 -> V_210 )
: - V_68 ;
F_22 ( L_78 ,
V_76 , V_83 -> V_153 ) ;
V_83 -> V_210 = NULL ;
}
return V_76 ;
}
int F_84 ( struct V_82 * V_83 )
{
if ( ! V_83 )
return - V_47 ;
if ( ! F_21 ( V_83 -> V_210 ) )
F_25 ( & V_83 -> V_210 ) ;
F_83 ( & V_83 -> V_84 ) ;
F_85 ( & V_83 -> V_204 ) ;
return 0 ;
}
int F_51 ( struct V_113 * V_114 , unsigned int V_123 )
{
struct V_127 * V_212 ;
unsigned int V_213 ;
int V_76 = - V_68 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_3 ( ! V_114 -> V_124 [ V_123 ] ) ;
F_3 ( ( V_114 -> V_117 & V_118 ) == 0 ) ;
V_213 = F_86 ( V_114 ) ;
F_87 ( V_114 -> V_124 [ V_123 ] , V_213 ) ;
if ( V_114 -> V_124 [ V_123 ] ) {
V_76 = 0 ;
if ( F_50 ( V_114 -> V_125 <= V_123 ) ) {
if ( V_114 -> V_117 & V_119 )
F_47 ( & V_114 -> V_120 , V_3 ) ;
else
F_48 ( & V_114 -> V_120 ) ;
if ( V_114 -> V_125 <= V_123 )
V_114 -> V_125 = V_123 + 1 ;
if ( V_114 -> V_117 & V_119 )
F_55 ( & V_114 -> V_120 , V_3 ) ;
else
F_56 ( & V_114 -> V_120 ) ;
}
for ( V_6 = 0 ; V_6 < V_114 -> V_214 ; ++ V_6 ) {
V_212 = F_58 ( V_114 , V_123 , V_6 ) ;
V_212 -> V_132 = V_133 ;
}
}
return V_76 ;
}
struct V_113 * F_88 ( unsigned int V_215 ,
enum V_216 V_3 )
{
struct V_113 * V_114 ;
unsigned int V_129 ;
unsigned int V_213 = 0 ;
int V_6 ;
if ( V_215 == 0 )
return NULL ;
if ( V_217 != 0 )
V_3 |= V_118 ;
if ( V_3 & V_118 )
V_129 = 1 ;
else
V_129 = F_89 () ;
F_90 ( V_114 , F_91 ( F_92 ( * V_114 ) , V_124 [ V_129 ] ) ) ;
if ( ! V_114 )
return NULL ;
V_114 -> V_214 = V_215 ;
V_114 -> V_117 = V_3 ;
F_93 ( & V_114 -> V_120 ) ;
F_90 ( V_114 -> V_163 ,
V_114 -> V_214 * sizeof( struct V_146 ) ) ;
if ( ! V_114 -> V_163 )
goto V_218;
if ( ( V_3 & V_118 ) != 0 ) {
V_213 = F_86 ( V_114 ) ;
F_87 ( V_114 -> V_124 [ 0 ] , V_213 ) ;
if ( ! V_114 -> V_124 [ 0 ] )
goto V_218;
V_114 -> V_125 = 1 ;
} else if ( ( V_3 & V_119 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_129 ; ++ V_6 )
if ( F_51 ( V_114 , V_6 ) < 0 )
goto V_218;
}
return V_114 ;
V_218:
F_94 ( & V_114 ) ;
return NULL ;
}
void F_94 ( struct V_113 * * V_219 )
{
struct V_113 * V_114 = * V_219 ;
unsigned int V_129 ;
unsigned int V_213 ;
unsigned int V_6 ;
if ( ! V_114 || V_114 -> V_214 == 0 )
return;
* V_219 = NULL ;
if ( V_114 -> V_117 & V_118 )
V_129 = 1 ;
else
V_129 = F_89 () ;
V_213 = F_86 ( V_114 ) ;
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ )
if ( V_114 -> V_124 [ V_6 ] )
F_95 ( V_114 -> V_124 [ V_6 ] , V_213 ) ;
if ( V_114 -> V_163 )
F_95 ( V_114 -> V_163 , V_114 -> V_214 *
sizeof( struct V_146 ) ) ;
F_95 ( V_114 , F_91 ( F_92 ( * V_114 ) , V_124 [ V_129 ] ) ) ;
}
T_1 F_96 ( struct V_113 * V_114 , int V_126 ,
enum V_220 V_221 )
{
unsigned int V_6 ;
unsigned int V_222 ;
unsigned long V_3 = 0 ;
T_1 V_7 = 0 ;
F_3 ( V_114 ) ;
V_222 = F_46 ( V_114 , V_121 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_222 ; V_6 ++ ) {
if ( ! V_114 -> V_124 [ V_6 ] )
continue;
V_7 += F_97 (
F_58 ( V_114 , V_6 , V_126 ) ,
& V_114 -> V_163 [ V_126 ] , V_114 -> V_117 ,
V_221 ) ;
}
F_54 ( V_114 , V_121 , & V_3 ) ;
return V_7 ;
}
void F_98 ( struct V_113 * V_114 )
{
struct V_127 * V_130 ;
int V_6 ;
int V_149 ;
unsigned int V_129 ;
unsigned long V_3 = 0 ;
V_129 = F_46 ( V_114 , V_121 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
if ( ! V_114 -> V_124 [ V_6 ] )
continue;
for ( V_149 = 0 ; V_149 < V_114 -> V_214 ; V_149 ++ ) {
V_130 = F_58 ( V_114 , V_6 , V_149 ) ;
V_130 -> V_131 = 0 ;
V_130 -> V_132 = V_133 ;
V_130 -> V_135 = 0 ;
V_130 -> V_136 = 0 ;
V_130 -> V_134 = 0 ;
if ( V_114 -> V_117 & V_119 )
V_130 -> V_223 = 0 ;
}
}
F_54 ( V_114 , V_121 , & V_3 ) ;
}
static T_5 F_99 ( struct V_57 * V_57 ,
const char T_3 * V_81 ,
T_8 V_224 , T_9 * V_225 )
{
struct V_9 * V_226 = V_57 -> V_227 ;
struct V_113 * V_114 = V_226 -> V_228 ;
F_98 ( V_114 ) ;
return V_224 ;
}
static void * F_100 ( struct V_9 * V_229 , T_9 * V_230 )
{
struct V_113 * V_114 = V_229 -> V_228 ;
return ( * V_230 < V_114 -> V_214 ) ? V_230 : NULL ;
}
static void F_101 ( struct V_9 * V_229 , void * V_231 )
{
}
static void * F_102 ( struct V_9 * V_229 , void * V_231 , T_9 * V_230 )
{
( * V_230 ) ++ ;
return F_100 ( V_229 , V_230 ) ;
}
static int F_103 ( struct V_9 * V_229 , void * V_231 )
{
struct V_113 * V_114 = V_229 -> V_228 ;
struct V_146 * V_232 ;
struct V_127 V_233 ;
int V_126 = * ( T_9 * ) V_231 ;
if ( V_126 == 0 ) {
struct V_234 V_195 ;
F_104 ( & V_195 ) ;
F_4 ( V_229 , L_79 ,
L_80 ,
( V_187 ) V_195 . V_235 , ( unsigned long ) V_195 . V_236 ) ;
}
V_232 = & V_114 -> V_163 [ V_126 ] ;
F_57 ( V_114 , V_126 , & V_233 ) ;
if ( V_233 . V_131 != 0 ) {
F_4 ( V_229 , L_81 ,
V_232 -> V_237 , V_233 . V_131 , V_232 -> V_169 ) ;
if ( ( V_232 -> V_238 & V_239 ) &&
( V_233 . V_131 > 0 ) ) {
F_4 ( V_229 , L_82 ,
V_233 . V_132 , V_233 . V_135 , V_233 . V_134 ) ;
if ( V_232 -> V_238 & V_240 )
F_4 ( V_229 , L_83 , V_233 . V_136 ) ;
}
F_105 ( V_229 , '\n' ) ;
}
return 0 ;
}
static int F_106 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_226 ;
int V_76 ;
V_76 = F_107 ( V_57 , & V_241 ) ;
if ( V_76 )
return V_76 ;
V_226 = V_57 -> V_227 ;
V_226 -> V_228 = V_56 -> V_242 ;
return 0 ;
}
int F_108 ( struct V_58 * V_69 , const char * V_60 ,
struct V_113 * V_114 )
{
struct V_58 * V_64 ;
F_3 ( ! F_21 ( V_69 ) ) ;
V_64 = F_20 ( V_60 , 0644 , V_69 , V_114 ,
& V_243 ) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
return 0 ;
}
void F_109 ( struct V_113 * V_114 , int V_244 ,
unsigned int V_245 , const char * V_60 ,
const char * V_246 )
{
struct V_146 * V_147 ;
struct V_127 * V_130 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_222 ;
V_147 = & V_114 -> V_163 [ V_244 ] ;
F_110 ( V_147 , L_84 ,
V_244 , V_60 , V_246 ) ;
V_147 -> V_238 = V_245 ;
V_147 -> V_237 = V_60 ;
V_147 -> V_169 = V_246 ;
V_222 = F_46 ( V_114 , V_121 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_222 ; ++ V_6 ) {
if ( ! V_114 -> V_124 [ V_6 ] )
continue;
V_130 = F_58 ( V_114 , V_6 , V_244 ) ;
V_130 -> V_131 = 0 ;
V_130 -> V_132 = V_133 ;
V_130 -> V_135 = 0 ;
V_130 -> V_136 = 0 ;
V_130 -> V_134 = 0 ;
if ( ( V_114 -> V_117 & V_119 ) != 0 )
V_130 -> V_223 = 0 ;
}
F_54 ( V_114 , V_121 , & V_3 ) ;
}
int F_111 ( struct V_247 * exp )
{
return 0 ;
}
T_10 F_97 ( struct V_127 * V_248 ,
struct V_146 * V_147 ,
enum V_216 V_3 ,
enum V_220 V_221 )
{
T_10 V_7 = 0 ;
if ( ! V_248 || ! V_147 )
return 0 ;
switch ( V_221 ) {
case V_249 :
V_7 = V_147 -> V_238 ;
break;
case V_250 :
V_7 = V_248 -> V_134 ;
if ( ( V_3 & V_119 ) != 0 )
V_7 += V_248 -> V_223 ;
break;
case V_251 :
V_7 = V_248 -> V_132 ;
break;
case V_252 :
V_7 = V_248 -> V_135 ;
break;
case V_253 :
V_7 = ( V_248 -> V_135 - V_248 -> V_132 ) / 2 ;
break;
case V_254 :
V_7 = V_248 -> V_136 ;
break;
case V_255 :
V_7 = V_248 -> V_131 ;
break;
default:
break;
}
return 0 ;
}
int F_112 ( const char T_3 * V_41 , unsigned long V_2 ,
int * V_42 )
{
return F_11 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_113 ( const char T_3 * V_41 , unsigned long V_2 ,
T_1 * V_42 )
{
return F_114 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_114 ( const char T_3 * V_41 ,
unsigned long V_2 , T_1 * V_42 , int V_43 )
{
char V_51 [ 22 ] , * V_52 , * V_53 ;
T_1 V_256 , V_257 = 0 , V_246 ;
unsigned V_258 = 1 ;
int V_259 = 1 ;
if ( V_2 > ( sizeof( V_51 ) - 1 ) )
return - V_47 ;
if ( F_12 ( V_51 , V_41 , V_2 ) )
return - V_54 ;
V_51 [ V_2 ] = '\0' ;
V_53 = V_51 ;
if ( * V_53 == '-' ) {
V_259 = - 1 ;
V_53 ++ ;
}
V_256 = F_115 ( V_53 , & V_52 , 10 ) ;
if ( V_53 == V_52 )
return - V_47 ;
if ( * V_52 == '.' ) {
int V_6 ;
V_53 = V_52 + 1 ;
if ( strlen ( V_53 ) > 10 )
V_53 [ 10 ] = '\0' ;
V_257 = F_115 ( V_53 , & V_52 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_52 - V_53 ) ; V_6 ++ )
V_258 *= 10 ;
}
V_246 = 1 ;
if ( V_52 ) {
switch ( tolower ( * V_52 ) ) {
case 'p' :
V_246 <<= 10 ;
case 't' :
V_246 <<= 10 ;
case 'g' :
V_246 <<= 10 ;
case 'm' :
V_246 <<= 10 ;
case 'k' :
V_246 <<= 10 ;
}
}
if ( V_246 > 1 )
V_43 = V_246 ;
V_257 *= V_43 ;
F_66 ( V_257 , V_258 ) ;
* V_42 = V_259 * ( V_256 * V_43 + V_257 ) ;
return 0 ;
}
static char * F_116 ( const char * V_260 , const char * V_261 , T_8 V_224 )
{
T_8 V_262 ;
V_262 = strlen ( V_261 ) ;
if ( ! V_262 )
return ( char * ) V_260 ;
while ( V_224 >= V_262 ) {
V_224 -- ;
if ( ! memcmp ( V_260 , V_261 , V_262 ) )
return ( char * ) V_260 ;
V_260 ++ ;
}
return NULL ;
}
char * F_117 ( const char * V_41 , const char * V_60 ,
T_8 * V_2 )
{
char * V_42 ;
T_8 V_263 = * V_2 ;
V_42 = F_116 ( V_41 , V_60 , V_263 ) ;
if ( ! V_42 )
return ( char * ) V_41 ;
V_42 += strlen ( V_60 ) ;
while ( V_42 < V_41 + V_263 && isspace ( * V_42 ) )
V_42 ++ ;
* V_2 = 0 ;
while ( V_42 < V_41 + V_263 && isalnum ( * V_42 ) ) {
++ * V_2 ;
++ V_42 ;
}
return V_42 - * V_2 ;
}
int F_118 ( struct V_58 * V_69 , const char * V_60 ,
T_4 V_65 , const struct V_62 * V_264 ,
void * V_61 )
{
struct V_58 * V_64 ;
F_3 ( ( V_264 -> V_67 == NULL ) == ( ( V_65 & 0222 ) == 0 ) ) ;
V_64 = F_20 ( V_60 , V_65 , V_69 , V_61 , V_264 ) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
return 0 ;
}
int F_119 ( struct V_82 * V_265 ,
const char * V_60 ,
T_4 V_65 ,
const struct V_62 * V_264 ,
void * V_61 )
{
return F_118 ( V_265 -> V_210 , V_60 ,
V_65 , V_264 , V_61 ) ;
}
void F_120 ( struct V_266 * V_267 , unsigned int V_268 )
{
if ( V_268 >= V_269 )
V_268 = V_269 - 1 ;
F_48 ( & V_267 -> V_270 ) ;
V_267 -> V_271 [ V_268 ] ++ ;
F_56 ( & V_267 -> V_270 ) ;
}
void F_121 ( struct V_266 * V_267 , unsigned int V_268 )
{
unsigned int V_42 = 0 ;
if ( F_122 ( V_268 != 0 ) )
V_42 = F_10 ( F_123 ( V_268 - 1 ) , V_269 ) ;
F_120 ( V_267 , V_42 ) ;
}
unsigned long F_124 ( struct V_266 * V_267 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_269 ; V_6 ++ )
V_7 += V_267 -> V_271 [ V_6 ] ;
return V_7 ;
}
void F_125 ( struct V_266 * V_267 )
{
F_48 ( & V_267 -> V_270 ) ;
memset ( V_267 -> V_271 , 0 , sizeof( V_267 -> V_271 ) ) ;
F_56 ( & V_267 -> V_270 ) ;
}
int F_126 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_272 * V_273 , char * V_60 )
{
char V_51 [ 64 ] , * V_274 , * V_275 ;
unsigned long V_276 , V_277 ;
int V_76 ;
if ( V_2 >= sizeof( V_51 ) ) {
V_275 = L_85 ;
V_76 = - V_47 ;
goto V_278;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_275 = L_86 ;
V_76 = - V_54 ;
goto V_278;
}
V_51 [ V_2 ] = '\0' ;
V_274 = strchr ( V_51 , ':' ) ;
if ( ! V_274 ) {
V_275 = L_87 ;
V_76 = - V_47 ;
goto V_279;
}
* V_274 = '\0' ;
V_274 ++ ;
if ( F_127 ( V_51 , 0 , & V_276 ) != 0 ) {
V_275 = L_88 ;
V_76 = - V_47 ;
goto V_279;
}
if ( F_127 ( V_274 , 0 , & V_277 ) != 0 ) {
V_275 = L_89 ;
V_76 = - V_47 ;
goto V_279;
}
V_273 -> V_280 = V_276 ;
V_273 -> V_281 = V_277 ;
F_128 ( L_90 ,
V_60 , V_273 -> V_280 , V_273 -> V_281 ) ;
return V_2 ;
V_279:
if ( V_274 ) {
V_274 -- ;
* V_274 = ':' ;
}
F_129 ( L_91 ,
V_60 , V_51 , V_275 , V_76 ) ;
return V_76 ;
V_278:
F_129 ( L_92 ,
V_60 , V_275 , V_76 ) ;
return V_76 ;
}
int F_130 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_272 * V_273 , char * V_60 )
{
char * V_51 = NULL , * V_275 ;
struct V_282 V_274 ;
int V_224 = V_2 ;
int V_76 ;
if ( V_2 > 4096 ) {
V_275 = L_85 ;
V_76 = - V_47 ;
goto V_279;
}
V_51 = F_131 ( V_2 + 1 , V_283 ) ;
if ( ! V_51 ) {
V_275 = L_93 ;
V_76 = - V_68 ;
goto V_279;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_275 = L_86 ;
V_76 = - V_54 ;
goto V_279;
}
V_51 [ V_2 ] = '\0' ;
if ( V_2 > 0 && V_51 [ V_2 - 1 ] == '\n' )
V_224 = V_2 - 1 ;
if ( ( V_224 == 4 && ! strncmp ( V_51 , L_94 , V_224 ) ) ||
( V_224 == 5 && ! strncmp ( V_51 , L_95 , V_224 ) ) ) {
F_132 ( & V_273 -> V_284 ) ;
if ( ! F_133 ( & V_273 -> V_285 ) )
F_134 ( & V_273 -> V_285 ) ;
F_135 ( & V_273 -> V_284 ) ;
F_128 ( L_96 , V_60 ) ;
F_136 ( V_51 ) ;
return V_2 ;
}
F_137 ( & V_274 ) ;
if ( F_138 ( V_51 , V_2 , & V_274 ) <= 0 ) {
V_275 = L_97 ;
V_76 = - V_47 ;
goto V_279;
}
F_128 ( L_98 ,
V_60 , V_51 ) ;
F_136 ( V_51 ) ;
V_51 = NULL ;
F_132 ( & V_273 -> V_284 ) ;
if ( ! F_133 ( & V_273 -> V_285 ) )
F_134 ( & V_273 -> V_285 ) ;
F_139 ( & V_274 , & V_273 -> V_285 ) ;
F_135 ( & V_273 -> V_284 ) ;
return V_2 ;
V_279:
if ( V_51 ) {
F_129 ( L_99 ,
V_60 , V_51 , V_275 , V_76 ) ;
F_136 ( V_51 ) ;
V_51 = NULL ;
} else {
F_129 ( L_100 ,
V_60 , V_275 , V_76 ) ;
}
return V_76 ;
}
static T_5 F_140 ( struct V_77 * V_78 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_286 * V_287 = F_31 ( V_80 , struct V_286 , V_80 ) ;
return V_287 -> V_288 ? V_287 -> V_288 ( V_78 , V_80 , V_81 ) : 0 ;
}
static T_5 F_141 ( struct V_77 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_8 V_224 )
{
struct V_286 * V_287 = F_31 ( V_80 , struct V_286 , V_80 ) ;
return V_287 -> V_289 ? V_287 -> V_289 ( V_78 , V_80 , V_81 , V_224 ) : V_224 ;
}
