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
struct V_62 * V_63 )
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
int F_30 ( struct V_9 * V_10 , void * V_61 )
{
F_4 ( V_10 , L_23 , * ( unsigned int * ) V_61 ) ;
return 0 ;
}
int F_31 ( struct V_57 * V_57 , const char T_3 * V_41 ,
unsigned long V_2 , void * V_61 )
{
unsigned * V_77 = V_61 ;
char V_78 [ V_79 + 1 ] , * V_52 ;
unsigned long V_80 ;
if ( V_2 >= sizeof( V_78 ) )
return - V_47 ;
if ( V_2 == 0 )
return 0 ;
if ( F_12 ( V_78 , V_41 , V_2 ) )
return - V_54 ;
V_78 [ V_2 ] = '\0' ;
V_80 = F_13 ( V_78 , & V_52 , 0 ) ;
if ( V_78 == V_52 )
return - V_47 ;
* V_77 = ( unsigned int ) V_80 ;
return V_2 ;
}
static T_5 F_32 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
return sprintf ( V_85 , L_24 , V_87 -> V_89 . V_90 ) ;
}
static T_5 F_34 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 )
return sprintf ( V_85 , L_23 , V_92 . V_96 ) ;
return V_76 ;
}
static T_5 F_36 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 ) {
T_6 V_97 = V_92 . V_96 >> 10 ;
T_1 V_98 = V_92 . V_99 ;
while ( V_97 >>= 1 )
V_98 <<= 1 ;
return sprintf ( V_85 , L_25 , V_98 ) ;
}
return V_76 ;
}
static T_5 F_37 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 ) {
T_6 V_97 = V_92 . V_96 >> 10 ;
T_1 V_98 = V_92 . V_100 ;
while ( V_97 >>= 1 )
V_98 <<= 1 ;
return sprintf ( V_85 , L_25 , V_98 ) ;
}
return V_76 ;
}
static T_5 F_38 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 ) {
T_6 V_97 = V_92 . V_96 >> 10 ;
T_1 V_98 = V_92 . V_101 ;
while ( V_97 >>= 1 )
V_98 <<= 1 ;
return sprintf ( V_85 , L_25 , V_98 ) ;
}
return V_76 ;
}
static T_5 F_39 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 )
return sprintf ( V_85 , L_25 , V_92 . V_102 ) ;
return V_76 ;
}
static T_5 F_40 ( struct V_81 * V_82 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
struct V_91 V_92 ;
int V_76 = V_91 ( NULL , V_87 -> V_93 , & V_92 ,
F_35 ( - V_94 ) ,
V_95 ) ;
if ( ! V_76 )
return sprintf ( V_85 , L_25 , V_92 . V_103 ) ;
return V_76 ;
}
int F_41 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
char * V_106 = NULL ;
int V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
V_106 = F_43 ( V_105 -> V_110 ) ;
F_4 ( V_10 , L_26 ,
F_44 ( V_87 ) , V_106 ,
V_105 -> V_111 ? L_27 : L_2 ) ;
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_46 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_113 * V_114 ;
int V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_114 = V_87 -> V_107 . V_108 . V_109 -> V_115 ;
if ( V_114 && V_87 -> V_107 . V_108 . V_109 )
F_4 ( V_10 , L_24 , V_114 -> V_116 . V_90 ) ;
else
F_47 ( V_10 , L_28 ) ;
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_48 ( struct V_117 * V_118 ,
enum V_119 V_120 ,
unsigned long * V_3 )
{
if ( V_118 -> V_121 & V_122 ) {
if ( V_118 -> V_121 & V_123 )
F_49 ( & V_118 -> V_124 , * V_3 ) ;
else
F_50 ( & V_118 -> V_124 ) ;
return V_120 == V_125 ? 1 : 0 ;
}
switch ( V_120 ) {
case V_126 : {
unsigned int V_127 = F_51 () ;
if ( F_52 ( ! V_118 -> V_128 [ V_127 ] ) ) {
int V_76 = F_53 ( V_118 , V_127 ) ;
if ( V_76 < 0 ) {
F_54 () ;
return V_76 ;
}
}
return V_127 ;
}
case V_125 :
return V_118 -> V_129 ;
default:
F_55 () ;
}
}
void F_56 ( struct V_117 * V_118 ,
enum V_119 V_120 ,
unsigned long * V_3 )
{
if ( V_118 -> V_121 & V_122 ) {
if ( V_118 -> V_121 & V_123 )
F_57 ( & V_118 -> V_124 , * V_3 ) ;
else
F_58 ( & V_118 -> V_124 ) ;
} else if ( V_120 == V_126 ) {
F_54 () ;
}
}
void F_59 ( struct V_117 * V_118 , int V_130 ,
struct V_131 * V_132 )
{
unsigned int V_133 ;
struct V_131 * V_134 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
if ( ! V_118 ) {
V_132 -> V_135 = 1 ;
return;
}
V_132 -> V_136 = V_137 ;
V_133 = F_48 ( V_118 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
V_134 = F_60 ( V_118 , V_6 , V_130 ) ;
V_132 -> V_135 += V_134 -> V_135 ;
V_132 -> V_138 += V_134 -> V_138 ;
if ( V_134 -> V_136 < V_132 -> V_136 )
V_132 -> V_136 = V_134 -> V_136 ;
if ( V_134 -> V_139 > V_132 -> V_139 )
V_132 -> V_139 = V_134 -> V_139 ;
V_132 -> V_140 += V_134 -> V_140 ;
}
F_56 ( V_118 , V_125 , & V_3 ) ;
}
static int F_61 ( struct V_104 * V_105 , struct V_9 * V_10 )
{
bool V_141 = true ;
if ( V_105 -> V_142 -> V_143 ) {
F_4 ( V_10 , L_29 ) ;
V_141 = false ;
}
F_62 ( V_144 , V_141 ) ;
V_141 = false ;
F_62 ( V_145 , V_141 ) ;
F_62 ( V_146 , V_141 ) ;
F_62 ( V_147 , V_141 ) ;
return 0 ;
}
static void F_63 ( struct V_9 * V_10 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_141 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_4 ( V_10 , L_1 ,
V_141 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_141 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_4 ( V_10 , L_3 ,
V_141 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_64 ( struct V_9 * V_10 , void * V_61 )
{
char V_148 [ V_149 ] ;
struct V_131 V_7 ;
struct V_150 * V_151 ;
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
struct V_152 * V_114 ;
struct V_11 * V_12 ;
int V_153 ;
int V_154 ;
int V_155 = 0 ;
int V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
V_12 = & V_105 -> V_156 ;
F_4 ( V_10 , L_30
L_31
L_32
L_33
L_34
L_35 ,
V_87 -> V_157 ,
F_44 ( V_87 ) ,
F_43 ( V_105 -> V_110 ) ,
V_105 -> V_156 . V_14 ) ;
F_63 ( V_10 , V_105 -> V_156 . V_13 ,
L_36 ) ;
F_4 ( V_10 , L_37 ) ;
F_2 ( V_10 , V_12 ) ;
F_4 ( V_10 , L_38 ) ;
F_61 ( V_105 , V_10 ) ;
F_4 ( V_10 ,
L_37
L_39
L_40 ) ;
F_50 ( & V_105 -> V_158 ) ;
V_153 = 0 ;
F_65 (conn, &imp->imp_conn_list, oic_item) {
F_66 ( V_114 -> V_159 -> V_160 . V_161 ,
V_148 , sizeof( V_148 ) ) ;
F_4 ( V_10 , L_1 , V_153 ? L_36 : L_2 , V_148 ) ;
V_153 ++ ;
}
if ( V_105 -> V_115 )
F_66 ( V_105 -> V_115 -> V_160 . V_161 ,
V_148 , sizeof( V_148 ) ) ;
else
strncpy ( V_148 , L_41 , sizeof( V_148 ) ) ;
F_4 ( V_10 ,
L_37
L_42
L_43
L_44
L_45 ,
V_148 ,
V_105 -> V_162 ,
V_105 -> V_163 ,
F_67 ( & V_105 -> V_164 ) ) ;
F_58 ( & V_105 -> V_158 ) ;
if ( ! V_87 -> V_165 )
goto V_166;
V_151 = & V_87 -> V_165 -> V_167 [ V_168 ] ;
F_59 ( V_87 -> V_165 , V_168 , & V_7 ) ;
if ( V_7 . V_135 != 0 ) {
T_1 V_169 = V_7 . V_138 ;
F_68 ( V_169 , V_7 . V_135 ) ;
V_7 . V_138 = V_169 ;
} else {
V_7 . V_138 = 0 ;
}
F_4 ( V_10 ,
L_46
L_47
L_48
L_49
L_50 ,
F_67 ( & V_105 -> V_170 ) ,
F_67 ( & V_105 -> V_171 ) ,
F_67 ( & V_105 -> V_172 ) ,
V_7 . V_138 , V_151 -> V_173 ) ;
V_154 = 0 ;
for ( V_153 = 0 ; V_153 < V_174 ; V_153 ++ ) {
if ( V_105 -> V_175 . V_176 [ V_153 ] == 0 )
break;
V_154 = F_69 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_4 ( V_10 ,
L_51
L_52
L_53 ,
V_154 ,
F_70 ( & V_105 -> V_175 . V_177 ) ) ;
F_4 ( V_10 ,
L_54
L_55
L_56
L_57 ,
V_105 -> V_178 ,
V_105 -> V_179 ,
V_105 -> V_180 ) ;
for ( V_155 = 0 ; V_155 <= 1 ; V_155 ++ ) {
F_59 ( V_87 -> V_165 ,
V_181 + V_182 + V_155 ,
& V_7 ) ;
if ( V_7 . V_138 > 0 && V_7 . V_135 > 0 ) {
T_1 V_169 = V_7 . V_138 ;
F_68 ( V_169 , V_7 . V_135 ) ;
V_7 . V_138 = V_169 ;
F_4 ( V_10 ,
L_58
L_59 ,
V_155 ? L_60 : L_61 ,
V_7 . V_138 ) ;
}
V_154 = ( int ) V_7 . V_138 ;
V_153 = F_71 ( V_183 + V_155 ) + V_184 ;
V_151 = & V_87 -> V_165 -> V_167 [ V_153 ] ;
F_59 ( V_87 -> V_165 , V_153 , & V_7 ) ;
if ( V_7 . V_138 > 0 && V_7 . V_135 != 0 ) {
T_1 V_169 = V_7 . V_138 ;
F_68 ( V_169 , V_7 . V_135 ) ;
V_7 . V_138 = V_169 ;
F_4 ( V_10 ,
L_62 ,
V_151 -> V_173 , V_7 . V_138 ) ;
V_153 = ( int ) V_7 . V_138 ;
if ( V_153 > 0 )
F_4 ( V_10 ,
L_63 ,
V_154 / V_153 , ( 100 * V_154 / V_153 ) % 100 ) ;
}
}
V_166:
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_72 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
int V_153 , V_154 , V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
F_4 ( V_10 , L_64 ,
F_43 ( V_105 -> V_110 ) ) ;
F_4 ( V_10 , L_65 ) ;
V_154 = V_105 -> V_185 ;
for ( V_153 = 0 ; V_153 < V_186 ; V_153 ++ ) {
struct V_187 * V_188 =
& V_105 -> V_189 [ ( V_154 + V_153 ) % V_186 ] ;
if ( V_188 -> V_190 == 0 )
continue;
F_4 ( V_10 , L_66 , ( V_191 ) V_188 -> V_192 ,
F_43 ( V_188 -> V_190 ) ) ;
}
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_73 ( struct V_9 * V_10 , struct V_193 * V_194 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_195 ; V_6 ++ )
F_4 ( V_10 , L_67 , V_194 -> V_196 [ V_6 ] ) ;
F_4 ( V_10 , L_68 ) ;
return 0 ;
}
int F_74 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
unsigned int V_197 , V_198 ;
T_7 V_199 , V_200 ;
struct V_201 V_202 ;
int V_6 , V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
V_199 = F_75 () ;
F_76 ( & V_202 , V_199 - V_105 -> V_203 ) ;
F_4 ( V_10 , L_69 V_204 L_70 ,
L_71 , ( V_191 ) V_105 -> V_203 , F_77 ( & V_202 ) ) ;
V_197 = F_70 ( & V_105 -> V_175 . V_177 ) ;
V_198 = V_105 -> V_175 . V_177 . V_205 ;
V_200 = V_105 -> V_175 . V_177 . V_206 ;
F_76 ( & V_202 , V_199 - V_200 ) ;
F_4 ( V_10 , L_72 V_204 L_73 ,
L_74 , V_197 , V_198 , ( V_191 ) V_200 , F_77 ( & V_202 ) ) ;
F_73 ( V_10 , & V_105 -> V_175 . V_177 ) ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ ) {
if ( V_105 -> V_175 . V_176 [ V_6 ] == 0 )
break;
V_197 = F_70 ( & V_105 -> V_175 . V_207 [ V_6 ] ) ;
V_198 = V_105 -> V_175 . V_207 [ V_6 ] . V_205 ;
V_200 = V_105 -> V_175 . V_207 [ V_6 ] . V_206 ;
F_76 ( & V_202 , V_199 - V_200 ) ;
F_4 ( V_10 , L_75
V_204 L_73 , V_105 -> V_175 . V_176 [ V_6 ] ,
V_197 , V_198 , ( V_191 ) V_200 , F_77 ( & V_202 ) ) ;
F_73 ( V_10 , & V_105 -> V_175 . V_207 [ V_6 ] ) ;
}
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_78 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
T_1 V_3 ;
int V_76 ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_3 = V_87 -> V_107 . V_108 . V_109 -> V_156 . V_13 ;
F_4 ( V_10 , L_76 , V_3 ) ;
F_63 ( V_10 , V_3 , L_68 ) ;
F_4 ( V_10 , L_68 ) ;
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
static void F_79 ( struct V_81 * V_82 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
F_80 ( & V_87 -> V_208 ) ;
}
int F_81 ( struct V_86 * V_87 , struct V_70 * V_71 ,
struct V_209 * V_210 )
{
int V_76 = 0 ;
F_82 ( & V_87 -> V_208 ) ;
V_76 = F_83 ( & V_87 -> V_88 , & V_211 ,
V_87 -> V_212 -> V_213 ,
L_77 , V_87 -> V_157 ) ;
if ( V_76 )
return V_76 ;
if ( V_210 ) {
V_76 = F_84 ( & V_87 -> V_88 , V_210 ) ;
if ( V_76 ) {
F_85 ( & V_87 -> V_88 ) ;
return V_76 ;
}
}
V_87 -> V_214 = F_27 ( V_87 -> V_157 ,
V_87 -> V_212 -> V_215 ,
V_71 , V_87 ) ;
if ( F_21 ( V_87 -> V_214 ) ) {
V_76 = V_87 -> V_214 ? F_24 ( V_87 -> V_214 )
: - V_68 ;
F_22 ( L_78 ,
V_76 , V_87 -> V_157 ) ;
V_87 -> V_214 = NULL ;
}
return V_76 ;
}
int F_86 ( struct V_86 * V_87 )
{
if ( ! V_87 )
return - V_47 ;
if ( ! F_21 ( V_87 -> V_214 ) )
F_25 ( & V_87 -> V_214 ) ;
F_85 ( & V_87 -> V_88 ) ;
F_87 ( & V_87 -> V_208 ) ;
return 0 ;
}
int F_53 ( struct V_117 * V_118 , unsigned int V_127 )
{
struct V_131 * V_216 ;
unsigned int V_217 ;
int V_76 = - V_68 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_3 ( ! V_118 -> V_128 [ V_127 ] ) ;
F_3 ( ( V_118 -> V_121 & V_122 ) == 0 ) ;
V_217 = F_88 ( V_118 ) ;
F_89 ( V_118 -> V_128 [ V_127 ] , V_217 ) ;
if ( V_118 -> V_128 [ V_127 ] ) {
V_76 = 0 ;
if ( F_52 ( V_118 -> V_129 <= V_127 ) ) {
if ( V_118 -> V_121 & V_123 )
F_49 ( & V_118 -> V_124 , V_3 ) ;
else
F_50 ( & V_118 -> V_124 ) ;
if ( V_118 -> V_129 <= V_127 )
V_118 -> V_129 = V_127 + 1 ;
if ( V_118 -> V_121 & V_123 )
F_57 ( & V_118 -> V_124 , V_3 ) ;
else
F_58 ( & V_118 -> V_124 ) ;
}
for ( V_6 = 0 ; V_6 < V_118 -> V_218 ; ++ V_6 ) {
V_216 = F_60 ( V_118 , V_127 , V_6 ) ;
V_216 -> V_136 = V_137 ;
}
}
return V_76 ;
}
struct V_117 * F_90 ( unsigned int V_219 ,
enum V_220 V_3 )
{
struct V_117 * V_118 ;
unsigned int V_133 ;
unsigned int V_217 = 0 ;
int V_6 ;
if ( V_219 == 0 )
return NULL ;
if ( V_221 != 0 )
V_3 |= V_122 ;
if ( V_3 & V_122 )
V_133 = 1 ;
else
V_133 = F_91 () ;
F_92 ( V_118 , F_93 ( F_94 ( * V_118 ) , V_128 [ V_133 ] ) ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_218 = V_219 ;
V_118 -> V_121 = V_3 ;
F_95 ( & V_118 -> V_124 ) ;
F_92 ( V_118 -> V_167 ,
V_118 -> V_218 * sizeof( struct V_150 ) ) ;
if ( ! V_118 -> V_167 )
goto V_222;
if ( ( V_3 & V_122 ) != 0 ) {
V_217 = F_88 ( V_118 ) ;
F_89 ( V_118 -> V_128 [ 0 ] , V_217 ) ;
if ( ! V_118 -> V_128 [ 0 ] )
goto V_222;
V_118 -> V_129 = 1 ;
} else if ( ( V_3 & V_123 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_133 ; ++ V_6 )
if ( F_53 ( V_118 , V_6 ) < 0 )
goto V_222;
}
return V_118 ;
V_222:
F_96 ( & V_118 ) ;
return NULL ;
}
void F_96 ( struct V_117 * * V_223 )
{
struct V_117 * V_118 = * V_223 ;
unsigned int V_133 ;
unsigned int V_217 ;
unsigned int V_6 ;
if ( ! V_118 || V_118 -> V_218 == 0 )
return;
* V_223 = NULL ;
if ( V_118 -> V_121 & V_122 )
V_133 = 1 ;
else
V_133 = F_91 () ;
V_217 = F_88 ( V_118 ) ;
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ )
if ( V_118 -> V_128 [ V_6 ] )
F_97 ( V_118 -> V_128 [ V_6 ] , V_217 ) ;
if ( V_118 -> V_167 )
F_97 ( V_118 -> V_167 , V_118 -> V_218 *
sizeof( struct V_150 ) ) ;
F_97 ( V_118 , F_93 ( F_94 ( * V_118 ) , V_128 [ V_133 ] ) ) ;
}
T_1 F_98 ( struct V_117 * V_118 , int V_130 ,
enum V_224 V_225 )
{
unsigned int V_6 ;
unsigned int V_226 ;
unsigned long V_3 = 0 ;
T_1 V_7 = 0 ;
F_3 ( V_118 ) ;
V_226 = F_48 ( V_118 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_226 ; V_6 ++ ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
V_7 += F_99 (
F_60 ( V_118 , V_6 , V_130 ) ,
& V_118 -> V_167 [ V_130 ] , V_118 -> V_121 ,
V_225 ) ;
}
F_56 ( V_118 , V_125 , & V_3 ) ;
return V_7 ;
}
void F_100 ( struct V_117 * V_118 )
{
struct V_131 * V_134 ;
int V_6 ;
int V_153 ;
unsigned int V_133 ;
unsigned long V_3 = 0 ;
V_133 = F_48 ( V_118 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
for ( V_153 = 0 ; V_153 < V_118 -> V_218 ; V_153 ++ ) {
V_134 = F_60 ( V_118 , V_6 , V_153 ) ;
V_134 -> V_135 = 0 ;
V_134 -> V_136 = V_137 ;
V_134 -> V_139 = 0 ;
V_134 -> V_140 = 0 ;
V_134 -> V_138 = 0 ;
if ( V_118 -> V_121 & V_123 )
V_134 -> V_227 = 0 ;
}
}
F_56 ( V_118 , V_125 , & V_3 ) ;
}
static T_5 F_101 ( struct V_57 * V_57 ,
const char T_3 * V_85 ,
T_8 V_228 , T_9 * V_229 )
{
struct V_9 * V_230 = V_57 -> V_231 ;
struct V_117 * V_118 = V_230 -> V_232 ;
F_100 ( V_118 ) ;
return V_228 ;
}
static void * F_102 ( struct V_9 * V_77 , T_9 * V_233 )
{
struct V_117 * V_118 = V_77 -> V_232 ;
return ( * V_233 < V_118 -> V_218 ) ? V_233 : NULL ;
}
static void F_103 ( struct V_9 * V_77 , void * V_234 )
{
}
static void * F_104 ( struct V_9 * V_77 , void * V_234 , T_9 * V_233 )
{
( * V_233 ) ++ ;
return F_102 ( V_77 , V_233 ) ;
}
static int F_105 ( struct V_9 * V_77 , void * V_234 )
{
struct V_117 * V_118 = V_77 -> V_232 ;
struct V_150 * V_235 ;
struct V_131 V_236 ;
int V_130 = * ( T_9 * ) V_234 ;
if ( V_130 == 0 ) {
struct V_237 V_199 ;
F_106 ( & V_199 ) ;
F_4 ( V_77 , L_79 ,
L_80 ,
( V_191 ) V_199 . V_238 , ( unsigned long ) V_199 . V_239 ) ;
}
V_235 = & V_118 -> V_167 [ V_130 ] ;
F_59 ( V_118 , V_130 , & V_236 ) ;
if ( V_236 . V_135 != 0 ) {
F_4 ( V_77 , L_81 ,
V_235 -> V_240 , V_236 . V_135 , V_235 -> V_173 ) ;
if ( ( V_235 -> V_241 & V_242 ) &&
( V_236 . V_135 > 0 ) ) {
F_4 ( V_77 , L_82 ,
V_236 . V_136 , V_236 . V_139 , V_236 . V_138 ) ;
if ( V_235 -> V_241 & V_243 )
F_4 ( V_77 , L_83 , V_236 . V_140 ) ;
}
F_107 ( V_77 , '\n' ) ;
}
return 0 ;
}
static int F_108 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_230 ;
int V_76 ;
V_76 = F_109 ( V_57 , & V_244 ) ;
if ( V_76 )
return V_76 ;
V_230 = V_57 -> V_231 ;
V_230 -> V_232 = V_56 -> V_245 ;
return 0 ;
}
int F_110 ( struct V_58 * V_69 , const char * V_60 ,
struct V_117 * V_118 )
{
struct V_58 * V_64 ;
F_3 ( ! F_21 ( V_69 ) ) ;
V_64 = F_20 ( V_60 , 0644 , V_69 , V_118 ,
& V_246 ) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
return 0 ;
}
void F_111 ( struct V_117 * V_118 , int V_247 ,
unsigned int V_248 , const char * V_60 ,
const char * V_249 )
{
struct V_150 * V_151 ;
struct V_131 * V_134 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_226 ;
V_151 = & V_118 -> V_167 [ V_247 ] ;
F_112 ( V_151 , L_84 ,
V_247 , V_60 , V_249 ) ;
V_151 -> V_241 = V_248 ;
V_151 -> V_240 = V_60 ;
V_151 -> V_173 = V_249 ;
V_226 = F_48 ( V_118 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_226 ; ++ V_6 ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
V_134 = F_60 ( V_118 , V_6 , V_247 ) ;
V_134 -> V_135 = 0 ;
V_134 -> V_136 = V_137 ;
V_134 -> V_139 = 0 ;
V_134 -> V_140 = 0 ;
V_134 -> V_138 = 0 ;
if ( ( V_118 -> V_121 & V_123 ) != 0 )
V_134 -> V_227 = 0 ;
}
F_56 ( V_118 , V_125 , & V_3 ) ;
}
int F_113 ( struct V_250 * exp )
{
return 0 ;
}
T_10 F_99 ( struct V_131 * V_251 ,
struct V_150 * V_151 ,
enum V_220 V_3 ,
enum V_224 V_225 )
{
T_10 V_7 = 0 ;
if ( ! V_251 || ! V_151 )
return 0 ;
switch ( V_225 ) {
case V_252 :
V_7 = V_151 -> V_241 ;
break;
case V_253 :
V_7 = V_251 -> V_138 ;
if ( ( V_3 & V_123 ) != 0 )
V_7 += V_251 -> V_227 ;
break;
case V_254 :
V_7 = V_251 -> V_136 ;
break;
case V_255 :
V_7 = V_251 -> V_139 ;
break;
case V_256 :
V_7 = ( V_251 -> V_139 - V_251 -> V_136 ) / 2 ;
break;
case V_257 :
V_7 = V_251 -> V_140 ;
break;
case V_258 :
V_7 = V_251 -> V_135 ;
break;
default:
break;
}
return 0 ;
}
int F_114 ( const char T_3 * V_41 , unsigned long V_2 ,
int * V_42 )
{
return F_11 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_115 ( const char T_3 * V_41 , unsigned long V_2 ,
T_1 * V_42 )
{
return F_116 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_116 ( const char T_3 * V_41 ,
unsigned long V_2 , T_1 * V_42 , int V_43 )
{
char V_51 [ 22 ] , * V_52 , * V_53 ;
T_1 V_259 , V_260 = 0 , V_249 ;
unsigned V_261 = 1 ;
int V_262 = 1 ;
if ( V_2 > ( sizeof( V_51 ) - 1 ) )
return - V_47 ;
if ( F_12 ( V_51 , V_41 , V_2 ) )
return - V_54 ;
V_51 [ V_2 ] = '\0' ;
V_53 = V_51 ;
if ( * V_53 == '-' ) {
V_262 = - 1 ;
V_53 ++ ;
}
V_259 = F_117 ( V_53 , & V_52 , 10 ) ;
if ( V_53 == V_52 )
return - V_47 ;
if ( * V_52 == '.' ) {
int V_6 ;
V_53 = V_52 + 1 ;
if ( strlen ( V_53 ) > 10 )
V_53 [ 10 ] = '\0' ;
V_260 = F_117 ( V_53 , & V_52 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_52 - V_53 ) ; V_6 ++ )
V_261 *= 10 ;
}
V_249 = 1 ;
if ( V_52 ) {
switch ( tolower ( * V_52 ) ) {
case 'p' :
V_249 <<= 10 ;
case 't' :
V_249 <<= 10 ;
case 'g' :
V_249 <<= 10 ;
case 'm' :
V_249 <<= 10 ;
case 'k' :
V_249 <<= 10 ;
}
}
if ( V_249 > 1 )
V_43 = V_249 ;
V_260 *= V_43 ;
F_68 ( V_260 , V_261 ) ;
* V_42 = V_262 * ( V_259 * V_43 + V_260 ) ;
return 0 ;
}
static char * F_118 ( const char * V_263 , const char * V_264 , T_8 V_228 )
{
T_8 V_265 ;
V_265 = strlen ( V_264 ) ;
if ( ! V_265 )
return ( char * ) V_263 ;
while ( V_228 >= V_265 ) {
V_228 -- ;
if ( ! memcmp ( V_263 , V_264 , V_265 ) )
return ( char * ) V_263 ;
V_263 ++ ;
}
return NULL ;
}
char * F_119 ( const char * V_41 , const char * V_60 ,
T_8 * V_2 )
{
char * V_42 ;
T_8 V_266 = * V_2 ;
V_42 = F_118 ( V_41 , V_60 , V_266 ) ;
if ( ! V_42 )
return ( char * ) V_41 ;
V_42 += strlen ( V_60 ) ;
while ( V_42 < V_41 + V_266 && isspace ( * V_42 ) )
V_42 ++ ;
* V_2 = 0 ;
while ( V_42 < V_41 + V_266 && isalnum ( * V_42 ) ) {
++ * V_2 ;
++ V_42 ;
}
return V_42 - * V_2 ;
}
int F_120 ( struct V_58 * V_69 , const char * V_60 ,
T_4 V_65 , const struct V_62 * V_267 ,
void * V_61 )
{
struct V_58 * V_64 ;
F_3 ( ( V_267 -> V_67 == NULL ) == ( ( V_65 & 0222 ) == 0 ) ) ;
V_64 = F_20 ( V_60 , V_65 , V_69 , V_61 , V_267 ) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
return 0 ;
}
int F_121 ( struct V_86 * V_268 ,
const char * V_60 ,
T_4 V_65 ,
const struct V_62 * V_267 ,
void * V_61 )
{
return F_120 ( V_268 -> V_214 , V_60 ,
V_65 , V_267 , V_61 ) ;
}
void F_122 ( struct V_269 * V_270 , unsigned int V_271 )
{
if ( V_271 >= V_272 )
V_271 = V_272 - 1 ;
F_50 ( & V_270 -> V_273 ) ;
V_270 -> V_274 [ V_271 ] ++ ;
F_58 ( & V_270 -> V_273 ) ;
}
void F_123 ( struct V_269 * V_270 , unsigned int V_271 )
{
unsigned int V_42 = 0 ;
if ( F_124 ( V_271 != 0 ) )
V_42 = F_10 ( F_125 ( V_271 - 1 ) , V_272 ) ;
F_122 ( V_270 , V_42 ) ;
}
unsigned long F_126 ( struct V_269 * V_270 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_272 ; V_6 ++ )
V_7 += V_270 -> V_274 [ V_6 ] ;
return V_7 ;
}
void F_127 ( struct V_269 * V_270 )
{
F_50 ( & V_270 -> V_273 ) ;
memset ( V_270 -> V_274 , 0 , sizeof( V_270 -> V_274 ) ) ;
F_58 ( & V_270 -> V_273 ) ;
}
int F_128 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_275 * V_276 , char * V_60 )
{
char V_51 [ 64 ] , * V_80 , * V_277 ;
unsigned long V_278 , V_279 ;
int V_76 ;
if ( V_2 >= sizeof( V_51 ) ) {
V_277 = L_85 ;
V_76 = - V_47 ;
goto V_280;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_277 = L_86 ;
V_76 = - V_54 ;
goto V_280;
}
V_51 [ V_2 ] = '\0' ;
V_80 = strchr ( V_51 , ':' ) ;
if ( ! V_80 ) {
V_277 = L_87 ;
V_76 = - V_47 ;
goto V_281;
}
* V_80 = '\0' ;
V_80 ++ ;
if ( F_129 ( V_51 , 0 , & V_278 ) != 0 ) {
V_277 = L_88 ;
V_76 = - V_47 ;
goto V_281;
}
if ( F_129 ( V_80 , 0 , & V_279 ) != 0 ) {
V_277 = L_89 ;
V_76 = - V_47 ;
goto V_281;
}
V_276 -> V_282 = V_278 ;
V_276 -> V_283 = V_279 ;
F_130 ( L_90 ,
V_60 , V_276 -> V_282 , V_276 -> V_283 ) ;
return V_2 ;
V_281:
if ( V_80 ) {
V_80 -- ;
* V_80 = ':' ;
}
F_131 ( L_91 ,
V_60 , V_51 , V_277 , V_76 ) ;
return V_76 ;
V_280:
F_131 ( L_92 ,
V_60 , V_277 , V_76 ) ;
return V_76 ;
}
int F_132 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_275 * V_276 , char * V_60 )
{
char * V_51 = NULL , * V_277 ;
struct V_284 V_80 ;
int V_228 = V_2 ;
int V_76 ;
if ( V_2 > 4096 ) {
V_277 = L_85 ;
V_76 = - V_47 ;
goto V_281;
}
V_51 = F_133 ( V_2 + 1 , V_285 ) ;
if ( ! V_51 ) {
V_277 = L_93 ;
V_76 = - V_68 ;
goto V_281;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_277 = L_86 ;
V_76 = - V_54 ;
goto V_281;
}
V_51 [ V_2 ] = '\0' ;
if ( V_2 > 0 && V_51 [ V_2 - 1 ] == '\n' )
V_228 = V_2 - 1 ;
if ( ( V_228 == 4 && ! strncmp ( V_51 , L_94 , V_228 ) ) ||
( V_228 == 5 && ! strncmp ( V_51 , L_95 , V_228 ) ) ) {
F_134 ( & V_276 -> V_286 ) ;
if ( ! F_135 ( & V_276 -> V_287 ) )
F_136 ( & V_276 -> V_287 ) ;
F_137 ( & V_276 -> V_286 ) ;
F_130 ( L_96 , V_60 ) ;
F_138 ( V_51 ) ;
return V_2 ;
}
F_139 ( & V_80 ) ;
if ( F_140 ( V_51 , V_2 , & V_80 ) <= 0 ) {
V_277 = L_97 ;
V_76 = - V_47 ;
goto V_281;
}
F_130 ( L_98 ,
V_60 , V_51 ) ;
F_138 ( V_51 ) ;
V_51 = NULL ;
F_134 ( & V_276 -> V_286 ) ;
if ( ! F_135 ( & V_276 -> V_287 ) )
F_136 ( & V_276 -> V_287 ) ;
F_141 ( & V_80 , & V_276 -> V_287 ) ;
F_137 ( & V_276 -> V_286 ) ;
return V_2 ;
V_281:
if ( V_51 ) {
F_131 ( L_99 ,
V_60 , V_51 , V_277 , V_76 ) ;
F_138 ( V_51 ) ;
V_51 = NULL ;
} else {
F_131 ( L_100 ,
V_60 , V_277 , V_76 ) ;
}
return V_76 ;
}
static T_5 F_142 ( struct V_81 * V_82 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_288 * V_289 = F_33 ( V_84 , struct V_288 , V_84 ) ;
return V_289 -> V_290 ? V_289 -> V_290 ( V_82 , V_84 , V_85 ) : 0 ;
}
static T_5 F_143 ( struct V_81 * V_82 , struct V_83 * V_84 ,
const char * V_85 , T_8 V_228 )
{
struct V_288 * V_289 = F_33 ( V_84 , struct V_288 , V_84 ) ;
return V_289 -> V_291 ? V_289 -> V_291 ( V_82 , V_84 , V_85 , V_228 ) : V_228 ;
}
