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
void F_48 ( struct V_117 * V_118 , int V_119 ,
struct V_120 * V_121 )
{
unsigned int V_122 ;
struct V_120 * V_123 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
if ( ! V_118 ) {
V_121 -> V_124 = 1 ;
return;
}
V_121 -> V_125 = V_126 ;
V_122 = F_49 ( V_118 , V_127 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
V_123 = F_50 ( V_118 , V_6 , V_119 ) ;
V_121 -> V_124 += V_123 -> V_124 ;
V_121 -> V_129 += V_123 -> V_129 ;
if ( V_123 -> V_125 < V_121 -> V_125 )
V_121 -> V_125 = V_123 -> V_125 ;
if ( V_123 -> V_130 > V_121 -> V_130 )
V_121 -> V_130 = V_123 -> V_130 ;
V_121 -> V_131 += V_123 -> V_131 ;
}
F_51 ( V_118 , V_127 , & V_3 ) ;
}
static int F_52 ( struct V_104 * V_105 , struct V_9 * V_10 )
{
bool V_132 = true ;
if ( V_105 -> V_133 -> V_134 ) {
F_4 ( V_10 , L_29 ) ;
V_132 = false ;
}
F_53 ( V_135 , V_132 ) ;
V_132 = false ;
F_53 ( V_136 , V_132 ) ;
F_53 ( V_137 , V_132 ) ;
F_53 ( V_138 , V_132 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_10 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_132 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_4 ( V_10 , L_1 ,
V_132 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_132 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_4 ( V_10 , L_3 ,
V_132 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_55 ( struct V_9 * V_10 , void * V_61 )
{
char V_139 [ V_140 ] ;
struct V_120 V_7 ;
struct V_141 * V_142 ;
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
struct V_143 * V_114 ;
struct V_11 * V_12 ;
int V_144 ;
int V_145 ;
int V_146 = 0 ;
int V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
V_12 = & V_105 -> V_147 ;
F_4 ( V_10 , L_30
L_31
L_32
L_33
L_34
L_35 ,
V_87 -> V_148 ,
F_44 ( V_87 ) ,
F_43 ( V_105 -> V_110 ) ,
V_105 -> V_147 . V_14 ) ;
F_54 ( V_10 , V_105 -> V_147 . V_13 ,
L_36 ) ;
F_4 ( V_10 , L_37 ) ;
F_2 ( V_10 , V_12 ) ;
F_4 ( V_10 , L_38 ) ;
F_52 ( V_105 , V_10 ) ;
F_4 ( V_10 ,
L_37
L_39
L_40 ) ;
F_56 ( & V_105 -> V_149 ) ;
V_144 = 0 ;
F_57 (conn, &imp->imp_conn_list, oic_item) {
F_58 ( V_114 -> V_150 -> V_151 . V_152 ,
V_139 , sizeof( V_139 ) ) ;
F_4 ( V_10 , L_1 , V_144 ? L_36 : L_2 , V_139 ) ;
V_144 ++ ;
}
if ( V_105 -> V_115 )
F_58 ( V_105 -> V_115 -> V_151 . V_152 ,
V_139 , sizeof( V_139 ) ) ;
else
strncpy ( V_139 , L_41 , sizeof( V_139 ) ) ;
F_4 ( V_10 ,
L_37
L_42
L_43
L_44
L_45 ,
V_139 ,
V_105 -> V_153 ,
V_105 -> V_154 ,
F_59 ( & V_105 -> V_155 ) ) ;
F_60 ( & V_105 -> V_149 ) ;
if ( ! V_87 -> V_156 )
goto V_157;
V_142 = & V_87 -> V_156 -> V_158 [ V_159 ] ;
F_48 ( V_87 -> V_156 , V_159 , & V_7 ) ;
if ( V_7 . V_124 != 0 ) {
T_1 V_160 = V_7 . V_129 ;
F_61 ( V_160 , V_7 . V_124 ) ;
V_7 . V_129 = V_160 ;
} else {
V_7 . V_129 = 0 ;
}
F_4 ( V_10 ,
L_46
L_47
L_48
L_49
L_50 ,
F_59 ( & V_105 -> V_161 ) ,
F_59 ( & V_105 -> V_162 ) ,
F_59 ( & V_105 -> V_163 ) ,
V_7 . V_129 , V_142 -> V_164 ) ;
V_145 = 0 ;
for ( V_144 = 0 ; V_144 < V_165 ; V_144 ++ ) {
if ( V_105 -> V_166 . V_167 [ V_144 ] == 0 )
break;
V_145 = F_62 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_4 ( V_10 ,
L_51
L_52
L_53 ,
V_145 ,
F_63 ( & V_105 -> V_166 . V_168 ) ) ;
F_4 ( V_10 ,
L_54
L_55
L_56
L_57 ,
V_105 -> V_169 ,
V_105 -> V_170 ,
V_105 -> V_171 ) ;
for ( V_146 = 0 ; V_146 <= 1 ; V_146 ++ ) {
F_48 ( V_87 -> V_156 ,
V_172 + V_173 + V_146 ,
& V_7 ) ;
if ( V_7 . V_129 > 0 && V_7 . V_124 > 0 ) {
T_1 V_160 = V_7 . V_129 ;
F_61 ( V_160 , V_7 . V_124 ) ;
V_7 . V_129 = V_160 ;
F_4 ( V_10 ,
L_58
L_59 ,
V_146 ? L_60 : L_61 ,
V_7 . V_129 ) ;
}
V_145 = ( int ) V_7 . V_129 ;
V_144 = F_64 ( V_174 + V_146 ) + V_175 ;
V_142 = & V_87 -> V_156 -> V_158 [ V_144 ] ;
F_48 ( V_87 -> V_156 , V_144 , & V_7 ) ;
if ( V_7 . V_129 > 0 && V_7 . V_124 != 0 ) {
T_1 V_160 = V_7 . V_129 ;
F_61 ( V_160 , V_7 . V_124 ) ;
V_7 . V_129 = V_160 ;
F_4 ( V_10 ,
L_62 ,
V_142 -> V_164 , V_7 . V_129 ) ;
V_144 = ( int ) V_7 . V_129 ;
if ( V_144 > 0 )
F_4 ( V_10 ,
L_63 ,
V_145 / V_144 , ( 100 * V_145 / V_144 ) % 100 ) ;
}
}
V_157:
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_65 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
int V_144 , V_145 , V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
F_4 ( V_10 , L_64 ,
F_43 ( V_105 -> V_110 ) ) ;
F_4 ( V_10 , L_65 ) ;
V_145 = V_105 -> V_176 ;
for ( V_144 = 0 ; V_144 < V_177 ; V_144 ++ ) {
struct V_178 * V_179 =
& V_105 -> V_180 [ ( V_145 + V_144 ) % V_177 ] ;
if ( V_179 -> V_181 == 0 )
continue;
F_4 ( V_10 , L_66 , ( V_182 ) V_179 -> V_183 ,
F_43 ( V_179 -> V_181 ) ) ;
}
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_66 ( struct V_9 * V_10 , struct V_184 * V_185 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_186 ; V_6 ++ )
F_4 ( V_10 , L_67 , V_185 -> V_187 [ V_6 ] ) ;
F_4 ( V_10 , L_68 ) ;
return 0 ;
}
int F_67 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
struct V_104 * V_105 ;
unsigned int V_188 , V_189 ;
T_7 V_190 , V_191 ;
struct V_192 V_193 ;
int V_6 , V_76 ;
F_3 ( V_87 ) ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_105 = V_87 -> V_107 . V_108 . V_109 ;
V_190 = F_68 () ;
F_69 ( & V_193 , V_190 - V_105 -> V_194 ) ;
F_4 ( V_10 , L_69 V_195 L_70 ,
L_71 , ( V_182 ) V_105 -> V_194 , F_70 ( & V_193 ) ) ;
V_188 = F_63 ( & V_105 -> V_166 . V_168 ) ;
V_189 = V_105 -> V_166 . V_168 . V_196 ;
V_191 = V_105 -> V_166 . V_168 . V_197 ;
F_69 ( & V_193 , V_190 - V_191 ) ;
F_4 ( V_10 , L_72 V_195 L_73 ,
L_74 , V_188 , V_189 , ( V_182 ) V_191 , F_70 ( & V_193 ) ) ;
F_66 ( V_10 , & V_105 -> V_166 . V_168 ) ;
for ( V_6 = 0 ; V_6 < V_165 ; V_6 ++ ) {
if ( V_105 -> V_166 . V_167 [ V_6 ] == 0 )
break;
V_188 = F_63 ( & V_105 -> V_166 . V_198 [ V_6 ] ) ;
V_189 = V_105 -> V_166 . V_198 [ V_6 ] . V_196 ;
V_191 = V_105 -> V_166 . V_198 [ V_6 ] . V_197 ;
F_69 ( & V_193 , V_190 - V_191 ) ;
F_4 ( V_10 , L_75
V_195 L_73 , V_105 -> V_166 . V_167 [ V_6 ] ,
V_188 , V_189 , ( V_182 ) V_191 , F_70 ( & V_193 ) ) ;
F_66 ( V_10 , & V_105 -> V_166 . V_198 [ V_6 ] ) ;
}
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
int F_71 ( struct V_9 * V_10 , void * V_61 )
{
struct V_86 * V_87 = V_61 ;
T_1 V_3 ;
int V_76 ;
V_76 = F_42 ( V_87 ) ;
if ( V_76 )
return V_76 ;
V_3 = V_87 -> V_107 . V_108 . V_109 -> V_147 . V_13 ;
F_4 ( V_10 , L_76 , V_3 ) ;
F_54 ( V_10 , V_3 , L_68 ) ;
F_4 ( V_10 , L_68 ) ;
F_45 ( & V_87 -> V_107 . V_108 . V_112 ) ;
return 0 ;
}
static void F_72 ( struct V_81 * V_82 )
{
struct V_86 * V_87 = F_33 ( V_82 , struct V_86 ,
V_88 ) ;
F_73 ( & V_87 -> V_199 ) ;
}
int F_74 ( struct V_86 * V_87 , struct V_70 * V_71 ,
struct V_200 * V_201 )
{
int V_76 = 0 ;
F_75 ( & V_87 -> V_199 ) ;
V_76 = F_76 ( & V_87 -> V_88 , & V_202 ,
V_87 -> V_203 -> V_204 ,
L_77 , V_87 -> V_148 ) ;
if ( V_76 )
return V_76 ;
if ( V_201 ) {
V_76 = F_77 ( & V_87 -> V_88 , V_201 ) ;
if ( V_76 ) {
F_78 ( & V_87 -> V_88 ) ;
return V_76 ;
}
}
V_87 -> V_205 = F_27 ( V_87 -> V_148 ,
V_87 -> V_203 -> V_206 ,
V_71 , V_87 ) ;
if ( F_21 ( V_87 -> V_205 ) ) {
V_76 = V_87 -> V_205 ? F_24 ( V_87 -> V_205 )
: - V_68 ;
F_22 ( L_78 ,
V_76 , V_87 -> V_148 ) ;
V_87 -> V_205 = NULL ;
}
return V_76 ;
}
int F_79 ( struct V_86 * V_87 )
{
if ( ! V_87 )
return - V_47 ;
if ( ! F_21 ( V_87 -> V_205 ) )
F_25 ( & V_87 -> V_205 ) ;
F_78 ( & V_87 -> V_88 ) ;
F_80 ( & V_87 -> V_199 ) ;
return 0 ;
}
int F_81 ( struct V_117 * V_118 , unsigned int V_207 )
{
struct V_120 * V_208 ;
unsigned int V_209 ;
int V_76 = - V_68 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_3 ( ! V_118 -> V_128 [ V_207 ] ) ;
F_3 ( ( V_118 -> V_210 & V_211 ) == 0 ) ;
V_209 = F_82 ( V_118 ) ;
F_83 ( V_118 -> V_128 [ V_207 ] , V_209 ) ;
if ( V_118 -> V_128 [ V_207 ] ) {
V_76 = 0 ;
if ( F_84 ( V_118 -> V_212 <= V_207 ) ) {
if ( V_118 -> V_210 & V_213 )
F_85 ( & V_118 -> V_214 , V_3 ) ;
else
F_56 ( & V_118 -> V_214 ) ;
if ( V_118 -> V_212 <= V_207 )
V_118 -> V_212 = V_207 + 1 ;
if ( V_118 -> V_210 & V_213 )
F_86 ( & V_118 -> V_214 , V_3 ) ;
else
F_60 ( & V_118 -> V_214 ) ;
}
for ( V_6 = 0 ; V_6 < V_118 -> V_215 ; ++ V_6 ) {
V_208 = F_50 ( V_118 , V_207 , V_6 ) ;
V_208 -> V_125 = V_126 ;
}
}
return V_76 ;
}
struct V_117 * F_87 ( unsigned int V_216 ,
enum V_217 V_3 )
{
struct V_117 * V_118 ;
unsigned int V_122 ;
unsigned int V_209 = 0 ;
int V_6 ;
if ( V_216 == 0 )
return NULL ;
if ( V_218 != 0 )
V_3 |= V_211 ;
if ( V_3 & V_211 )
V_122 = 1 ;
else
V_122 = F_88 () ;
F_89 ( V_118 , F_90 ( F_91 ( * V_118 ) , V_128 [ V_122 ] ) ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_215 = V_216 ;
V_118 -> V_210 = V_3 ;
F_92 ( & V_118 -> V_214 ) ;
F_89 ( V_118 -> V_158 ,
V_118 -> V_215 * sizeof( struct V_141 ) ) ;
if ( ! V_118 -> V_158 )
goto V_219;
if ( ( V_3 & V_211 ) != 0 ) {
V_209 = F_82 ( V_118 ) ;
F_83 ( V_118 -> V_128 [ 0 ] , V_209 ) ;
if ( ! V_118 -> V_128 [ 0 ] )
goto V_219;
V_118 -> V_212 = 1 ;
} else if ( ( V_3 & V_213 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_122 ; ++ V_6 )
if ( F_81 ( V_118 , V_6 ) < 0 )
goto V_219;
}
return V_118 ;
V_219:
F_93 ( & V_118 ) ;
return NULL ;
}
void F_93 ( struct V_117 * * V_220 )
{
struct V_117 * V_118 = * V_220 ;
unsigned int V_122 ;
unsigned int V_209 ;
unsigned int V_6 ;
if ( ! V_118 || V_118 -> V_215 == 0 )
return;
* V_220 = NULL ;
if ( V_118 -> V_210 & V_211 )
V_122 = 1 ;
else
V_122 = F_88 () ;
V_209 = F_82 ( V_118 ) ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ )
if ( V_118 -> V_128 [ V_6 ] )
F_94 ( V_118 -> V_128 [ V_6 ] , V_209 ) ;
if ( V_118 -> V_158 )
F_94 ( V_118 -> V_158 , V_118 -> V_215 *
sizeof( struct V_141 ) ) ;
F_94 ( V_118 , F_90 ( F_91 ( * V_118 ) , V_128 [ V_122 ] ) ) ;
}
void F_95 ( struct V_117 * V_118 )
{
struct V_120 * V_123 ;
int V_6 ;
int V_144 ;
unsigned int V_122 ;
unsigned long V_3 = 0 ;
V_122 = F_49 ( V_118 , V_127 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
for ( V_144 = 0 ; V_144 < V_118 -> V_215 ; V_144 ++ ) {
V_123 = F_50 ( V_118 , V_6 , V_144 ) ;
V_123 -> V_124 = 0 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_130 = 0 ;
V_123 -> V_131 = 0 ;
V_123 -> V_129 = 0 ;
if ( V_118 -> V_210 & V_213 )
V_123 -> V_221 = 0 ;
}
}
F_51 ( V_118 , V_127 , & V_3 ) ;
}
static T_5 F_96 ( struct V_57 * V_57 ,
const char T_3 * V_85 ,
T_8 V_222 , T_9 * V_223 )
{
struct V_9 * V_224 = V_57 -> V_225 ;
struct V_117 * V_118 = V_224 -> V_226 ;
F_95 ( V_118 ) ;
return V_222 ;
}
static void * F_97 ( struct V_9 * V_77 , T_9 * V_227 )
{
struct V_117 * V_118 = V_77 -> V_226 ;
return ( * V_227 < V_118 -> V_215 ) ? V_227 : NULL ;
}
static void F_98 ( struct V_9 * V_77 , void * V_228 )
{
}
static void * F_99 ( struct V_9 * V_77 , void * V_228 , T_9 * V_227 )
{
( * V_227 ) ++ ;
return F_97 ( V_77 , V_227 ) ;
}
static int F_100 ( struct V_9 * V_77 , void * V_228 )
{
struct V_117 * V_118 = V_77 -> V_226 ;
struct V_141 * V_229 ;
struct V_120 V_230 ;
int V_119 = * ( T_9 * ) V_228 ;
if ( V_119 == 0 ) {
struct V_231 V_190 ;
F_101 ( & V_190 ) ;
F_4 ( V_77 , L_79 ,
L_80 ,
( V_182 ) V_190 . V_232 , ( unsigned long ) V_190 . V_233 ) ;
}
V_229 = & V_118 -> V_158 [ V_119 ] ;
F_48 ( V_118 , V_119 , & V_230 ) ;
if ( V_230 . V_124 != 0 ) {
F_4 ( V_77 , L_81 ,
V_229 -> V_234 , V_230 . V_124 , V_229 -> V_164 ) ;
if ( ( V_229 -> V_235 & V_236 ) &&
( V_230 . V_124 > 0 ) ) {
F_4 ( V_77 , L_82 ,
V_230 . V_125 , V_230 . V_130 , V_230 . V_129 ) ;
if ( V_229 -> V_235 & V_237 )
F_4 ( V_77 , L_83 , V_230 . V_131 ) ;
}
F_102 ( V_77 , '\n' ) ;
}
return 0 ;
}
static int F_103 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
struct V_9 * V_224 ;
int V_76 ;
V_76 = F_104 ( V_57 , & V_238 ) ;
if ( V_76 )
return V_76 ;
V_224 = V_57 -> V_225 ;
V_224 -> V_226 = V_56 -> V_239 ;
return 0 ;
}
int F_105 ( struct V_58 * V_69 , const char * V_60 ,
struct V_117 * V_118 )
{
struct V_58 * V_64 ;
F_3 ( ! F_21 ( V_69 ) ) ;
V_64 = F_20 ( V_60 , 0644 , V_69 , V_118 ,
& V_240 ) ;
if ( F_21 ( V_64 ) )
return V_64 ? F_24 ( V_64 ) : - V_68 ;
return 0 ;
}
void F_106 ( struct V_117 * V_118 , int V_241 ,
unsigned int V_242 , const char * V_60 ,
const char * V_243 )
{
struct V_141 * V_142 ;
struct V_120 * V_123 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_244 ;
V_142 = & V_118 -> V_158 [ V_241 ] ;
F_107 ( V_142 , L_84 ,
V_241 , V_60 , V_243 ) ;
V_142 -> V_235 = V_242 ;
V_142 -> V_234 = V_60 ;
V_142 -> V_164 = V_243 ;
V_244 = F_49 ( V_118 , V_127 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_244 ; ++ V_6 ) {
if ( ! V_118 -> V_128 [ V_6 ] )
continue;
V_123 = F_50 ( V_118 , V_6 , V_241 ) ;
V_123 -> V_124 = 0 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_130 = 0 ;
V_123 -> V_131 = 0 ;
V_123 -> V_129 = 0 ;
if ( ( V_118 -> V_210 & V_213 ) != 0 )
V_123 -> V_221 = 0 ;
}
F_51 ( V_118 , V_127 , & V_3 ) ;
}
int F_108 ( struct V_245 * exp )
{
return 0 ;
}
T_10 F_109 ( struct V_120 * V_246 ,
struct V_141 * V_142 ,
enum V_217 V_3 ,
enum V_247 V_248 )
{
T_10 V_7 = 0 ;
if ( ! V_246 || ! V_142 )
return 0 ;
switch ( V_248 ) {
case V_249 :
V_7 = V_142 -> V_235 ;
break;
case V_250 :
V_7 = V_246 -> V_129 ;
if ( ( V_3 & V_213 ) != 0 )
V_7 += V_246 -> V_221 ;
break;
case V_251 :
V_7 = V_246 -> V_125 ;
break;
case V_252 :
V_7 = V_246 -> V_130 ;
break;
case V_253 :
V_7 = ( V_246 -> V_130 - V_246 -> V_125 ) / 2 ;
break;
case V_254 :
V_7 = V_246 -> V_131 ;
break;
case V_255 :
V_7 = V_246 -> V_124 ;
break;
default:
break;
}
return 0 ;
}
int F_110 ( const char T_3 * V_41 , unsigned long V_2 ,
int * V_42 )
{
return F_11 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_111 ( const char T_3 * V_41 , unsigned long V_2 ,
T_1 * V_42 )
{
return F_112 ( V_41 , V_2 , V_42 , 1 ) ;
}
int F_112 ( const char T_3 * V_41 ,
unsigned long V_2 , T_1 * V_42 , int V_43 )
{
char V_51 [ 22 ] , * V_52 , * V_53 ;
T_1 V_256 , V_257 = 0 , V_243 ;
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
V_256 = F_113 ( V_53 , & V_52 , 10 ) ;
if ( V_53 == V_52 )
return - V_47 ;
if ( * V_52 == '.' ) {
int V_6 ;
V_53 = V_52 + 1 ;
if ( strlen ( V_53 ) > 10 )
V_53 [ 10 ] = '\0' ;
V_257 = F_113 ( V_53 , & V_52 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_52 - V_53 ) ; V_6 ++ )
V_258 *= 10 ;
}
V_243 = 1 ;
if ( V_52 ) {
switch ( tolower ( * V_52 ) ) {
case 'p' :
V_243 <<= 10 ;
case 't' :
V_243 <<= 10 ;
case 'g' :
V_243 <<= 10 ;
case 'm' :
V_243 <<= 10 ;
case 'k' :
V_243 <<= 10 ;
}
}
if ( V_243 > 1 )
V_43 = V_243 ;
V_257 *= V_43 ;
F_61 ( V_257 , V_258 ) ;
* V_42 = V_259 * ( V_256 * V_43 + V_257 ) ;
return 0 ;
}
static char * F_114 ( const char * V_260 , const char * V_261 , T_8 V_222 )
{
T_8 V_262 ;
V_262 = strlen ( V_261 ) ;
if ( ! V_262 )
return ( char * ) V_260 ;
while ( V_222 >= V_262 ) {
V_222 -- ;
if ( ! memcmp ( V_260 , V_261 , V_262 ) )
return ( char * ) V_260 ;
V_260 ++ ;
}
return NULL ;
}
char * F_115 ( const char * V_41 , const char * V_60 ,
T_8 * V_2 )
{
char * V_42 ;
T_8 V_263 = * V_2 ;
V_42 = F_114 ( V_41 , V_60 , V_263 ) ;
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
int F_116 ( struct V_58 * V_69 , const char * V_60 ,
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
int F_117 ( struct V_86 * V_265 ,
const char * V_60 ,
T_4 V_65 ,
const struct V_62 * V_264 ,
void * V_61 )
{
return F_116 ( V_265 -> V_205 , V_60 ,
V_65 , V_264 , V_61 ) ;
}
void F_118 ( struct V_266 * V_267 , unsigned int V_268 )
{
if ( V_268 >= V_269 )
V_268 = V_269 - 1 ;
F_56 ( & V_267 -> V_270 ) ;
V_267 -> V_271 [ V_268 ] ++ ;
F_60 ( & V_267 -> V_270 ) ;
}
void F_119 ( struct V_266 * V_267 , unsigned int V_268 )
{
unsigned int V_42 = 0 ;
if ( F_120 ( V_268 != 0 ) )
V_42 = F_10 ( F_121 ( V_268 - 1 ) , V_269 ) ;
F_118 ( V_267 , V_42 ) ;
}
unsigned long F_122 ( struct V_266 * V_267 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_269 ; V_6 ++ )
V_7 += V_267 -> V_271 [ V_6 ] ;
return V_7 ;
}
void F_123 ( struct V_266 * V_267 )
{
F_56 ( & V_267 -> V_270 ) ;
memset ( V_267 -> V_271 , 0 , sizeof( V_267 -> V_271 ) ) ;
F_60 ( & V_267 -> V_270 ) ;
}
int F_124 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_272 * V_273 , char * V_60 )
{
char V_51 [ 64 ] , * V_80 , * V_274 ;
unsigned long V_275 , V_276 ;
int V_76 ;
if ( V_2 >= sizeof( V_51 ) ) {
V_274 = L_85 ;
V_76 = - V_47 ;
goto V_277;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_274 = L_86 ;
V_76 = - V_54 ;
goto V_277;
}
V_51 [ V_2 ] = '\0' ;
V_80 = strchr ( V_51 , ':' ) ;
if ( ! V_80 ) {
V_274 = L_87 ;
V_76 = - V_47 ;
goto V_278;
}
* V_80 = '\0' ;
V_80 ++ ;
if ( F_125 ( V_51 , 0 , & V_275 ) != 0 ) {
V_274 = L_88 ;
V_76 = - V_47 ;
goto V_278;
}
if ( F_125 ( V_80 , 0 , & V_276 ) != 0 ) {
V_274 = L_89 ;
V_76 = - V_47 ;
goto V_278;
}
V_273 -> V_279 = V_275 ;
V_273 -> V_280 = V_276 ;
F_126 ( L_90 ,
V_60 , V_273 -> V_279 , V_273 -> V_280 ) ;
return V_2 ;
V_278:
if ( V_80 ) {
V_80 -- ;
* V_80 = ':' ;
}
F_127 ( L_91 ,
V_60 , V_51 , V_274 , V_76 ) ;
return V_76 ;
V_277:
F_127 ( L_92 ,
V_60 , V_274 , V_76 ) ;
return V_76 ;
}
int F_128 ( const char T_3 * V_41 , unsigned long V_2 ,
struct V_272 * V_273 , char * V_60 )
{
char * V_51 = NULL , * V_274 ;
struct V_281 V_80 ;
int V_222 = V_2 ;
int V_76 ;
if ( V_2 > 4096 ) {
V_274 = L_85 ;
V_76 = - V_47 ;
goto V_278;
}
V_51 = F_129 ( V_2 + 1 , V_282 ) ;
if ( ! V_51 ) {
V_274 = L_93 ;
V_76 = - V_68 ;
goto V_278;
}
if ( F_12 ( V_51 , V_41 , V_2 ) ) {
V_274 = L_86 ;
V_76 = - V_54 ;
goto V_278;
}
V_51 [ V_2 ] = '\0' ;
if ( V_2 > 0 && V_51 [ V_2 - 1 ] == '\n' )
V_222 = V_2 - 1 ;
if ( ( V_222 == 4 && ! strncmp ( V_51 , L_94 , V_222 ) ) ||
( V_222 == 5 && ! strncmp ( V_51 , L_95 , V_222 ) ) ) {
F_130 ( & V_273 -> V_283 ) ;
if ( ! F_131 ( & V_273 -> V_284 ) )
F_132 ( & V_273 -> V_284 ) ;
F_133 ( & V_273 -> V_283 ) ;
F_126 ( L_96 , V_60 ) ;
F_134 ( V_51 ) ;
return V_2 ;
}
F_135 ( & V_80 ) ;
if ( F_136 ( V_51 , V_2 , & V_80 ) <= 0 ) {
V_274 = L_97 ;
V_76 = - V_47 ;
goto V_278;
}
F_126 ( L_98 ,
V_60 , V_51 ) ;
F_134 ( V_51 ) ;
V_51 = NULL ;
F_130 ( & V_273 -> V_283 ) ;
if ( ! F_131 ( & V_273 -> V_284 ) )
F_132 ( & V_273 -> V_284 ) ;
F_137 ( & V_80 , & V_273 -> V_284 ) ;
F_133 ( & V_273 -> V_283 ) ;
return V_2 ;
V_278:
if ( V_51 ) {
F_127 ( L_99 ,
V_60 , V_51 , V_274 , V_76 ) ;
F_134 ( V_51 ) ;
V_51 = NULL ;
} else {
F_127 ( L_100 ,
V_60 , V_274 , V_76 ) ;
}
return V_76 ;
}
static T_5 F_138 ( struct V_81 * V_82 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_285 * V_286 = F_33 ( V_84 , struct V_285 , V_84 ) ;
return V_286 -> V_287 ? V_286 -> V_287 ( V_82 , V_84 , V_85 ) : 0 ;
}
static T_5 F_139 ( struct V_81 * V_82 , struct V_83 * V_84 ,
const char * V_85 , T_8 V_222 )
{
struct V_285 * V_286 = F_33 ( V_84 , struct V_285 , V_84 ) ;
return V_286 -> V_288 ? V_286 -> V_288 ( V_82 , V_84 , V_85 , V_222 ) : V_222 ;
}
