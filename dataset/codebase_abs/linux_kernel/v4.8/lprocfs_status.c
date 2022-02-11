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
int V_3 ;
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
}
int F_9 ( char * V_39 , unsigned long V_2 , long V_40 ,
int V_41 )
{
long V_42 , V_43 ;
int V_44 ;
if ( V_2 < 10 )
return - V_45 ;
V_42 = V_40 / V_41 ;
V_44 = snprintf ( V_39 , V_2 , L_20 , V_42 ) ;
V_43 = V_40 % V_41 ;
if ( V_44 < ( V_2 - 4 ) && V_43 > 0 ) {
long V_46 ;
int V_6 , V_47 = 1 , V_48 = 0 ;
V_46 = V_43 * 10 ;
V_39 [ V_44 ++ ] = '.' ;
while ( V_48 < 2 && ( V_46 / V_41 ) < 1 ) {
V_39 [ V_44 ++ ] = '0' ;
V_46 *= 10 ;
V_48 ++ ;
}
for ( V_6 = 0 ; V_6 < ( 5 - V_44 ) ; V_6 ++ )
V_47 *= 10 ;
V_48 = F_10 ( ( int ) V_2 - V_44 , 3 - V_48 ) ;
V_44 += snprintf ( V_39 + V_44 , V_48 , L_20 ,
V_43 * V_47 / V_41 ) ;
V_44 -- ;
while ( V_39 [ V_44 ] < '1' || V_39 [ V_44 ] > '9' ) {
V_44 -- ;
if ( V_39 [ V_44 ] == '.' ) {
V_44 -- ;
break;
}
}
V_44 ++ ;
}
V_39 [ V_44 ++ ] = '\n' ;
return V_44 ;
}
int F_11 ( const char T_2 * V_39 , unsigned long V_2 ,
int * V_40 , int V_41 )
{
char V_49 [ 20 ] , * V_50 , * V_51 ;
if ( V_2 > ( sizeof( V_49 ) - 1 ) )
return - V_45 ;
if ( F_12 ( V_49 , V_39 , V_2 ) )
return - V_52 ;
V_49 [ V_2 ] = '\0' ;
V_51 = V_49 ;
if ( * V_51 == '-' ) {
V_41 = - V_41 ;
V_51 ++ ;
}
* V_40 = ( int ) F_13 ( V_51 , & V_50 , 10 ) * V_41 ;
if ( V_51 == V_50 )
return - V_45 ;
if ( V_50 && * V_50 == '.' ) {
int V_53 , pow = 1 ;
int V_6 ;
V_51 = V_50 + 1 ;
if ( strlen ( V_51 ) > 5 )
V_51 [ 5 ] = '\0' ;
V_53 = ( int ) F_13 ( V_51 , & V_50 , 10 ) * V_41 ;
if ( V_51 < V_50 ) {
for ( V_6 = 0 ; V_6 < ( V_50 - V_51 ) ; V_6 ++ )
pow *= 10 ;
* V_40 += V_53 / pow ;
}
}
return 0 ;
}
int F_14 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_15 ( V_54 , V_55 ) ;
}
int F_16 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_17 ( V_54 , V_55 ) ;
}
struct V_56 * F_18 ( struct V_56 * V_57 ,
char * V_58 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_56 * V_62 ;
T_3 V_63 = 0 ;
if ( ! V_57 || ! V_58 || ! V_61 )
return F_19 ( - V_45 ) ;
if ( V_61 -> V_64 )
V_63 = 0444 ;
if ( V_61 -> V_65 )
V_63 |= 0200 ;
V_62 = F_20 ( V_58 , V_63 , V_57 , V_59 , V_61 ) ;
if ( F_21 ( V_62 ) ) {
F_22 ( L_21 , V_58 ) ;
return V_62 ? : F_19 ( - V_66 ) ;
}
return V_62 ;
}
int F_23 ( struct V_56 * V_67 ,
struct V_68 * V_69 ,
void * V_59 )
{
if ( F_21 ( V_67 ) || F_21 ( V_69 ) )
return - V_45 ;
while ( V_69 -> V_58 ) {
struct V_56 * V_62 ;
T_3 V_63 = 0 ;
if ( V_69 -> V_70 != 0000 ) {
V_63 = V_69 -> V_70 ;
} else if ( V_69 -> V_61 ) {
if ( V_69 -> V_61 -> V_64 )
V_63 = 0444 ;
if ( V_69 -> V_61 -> V_65 )
V_63 |= 0200 ;
}
V_62 = F_20 ( V_69 -> V_58 , V_63 , V_67 ,
V_69 -> V_59 ? : V_59 ,
V_69 -> V_61 ? : & V_71
) ;
if ( F_21 ( V_62 ) )
return V_62 ? F_24 ( V_62 ) : - V_66 ;
V_69 ++ ;
}
return 0 ;
}
void F_25 ( struct V_56 * * V_72 )
{
F_26 ( * V_72 ) ;
* V_72 = NULL ;
}
struct V_56 * F_27 ( const char * V_58 ,
struct V_56 * V_67 ,
struct V_68 * V_69 , void * V_59 )
{
struct V_56 * V_62 ;
V_62 = F_28 ( V_58 , V_67 ) ;
if ( F_21 ( V_62 ) ) {
V_62 = V_62 ? : F_19 ( - V_66 ) ;
goto V_73;
}
if ( ! F_21 ( V_69 ) ) {
int V_74 ;
V_74 = F_23 ( V_62 , V_69 , V_59 ) ;
if ( V_74 != 0 ) {
F_29 ( V_62 ) ;
V_62 = F_19 ( V_74 ) ;
}
}
V_73:
return V_62 ;
}
int F_30 ( struct V_9 * V_10 , void * V_59 )
{
F_4 ( V_10 , L_22 , * ( unsigned int * ) V_59 ) ;
return 0 ;
}
int F_31 ( struct V_55 * V_55 , const char T_2 * V_39 ,
unsigned long V_2 , void * V_59 )
{
unsigned * V_75 = V_59 ;
char V_76 [ V_77 + 1 ] , * V_50 ;
unsigned long V_78 ;
V_76 [ V_77 ] = '\0' ;
if ( F_12 ( V_76 , V_39 , V_77 ) )
return - V_52 ;
V_78 = F_13 ( V_76 , & V_50 , 0 ) ;
if ( V_76 == V_50 )
return - V_45 ;
* V_75 = ( unsigned int ) V_78 ;
return V_2 ;
}
static T_4 F_32 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
return sprintf ( V_83 , L_23 , V_85 -> V_87 . V_88 ) ;
}
static T_4 F_34 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 )
return sprintf ( V_83 , L_22 , V_90 . V_94 ) ;
return V_74 ;
}
static T_4 F_36 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 ) {
T_5 V_95 = V_90 . V_94 >> 10 ;
T_1 V_96 = V_90 . V_97 ;
while ( V_95 >>= 1 )
V_96 <<= 1 ;
return sprintf ( V_83 , L_24 , V_96 ) ;
}
return V_74 ;
}
static T_4 F_37 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 ) {
T_5 V_95 = V_90 . V_94 >> 10 ;
T_1 V_96 = V_90 . V_98 ;
while ( V_95 >>= 1 )
V_96 <<= 1 ;
return sprintf ( V_83 , L_24 , V_96 ) ;
}
return V_74 ;
}
static T_4 F_38 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 ) {
T_5 V_95 = V_90 . V_94 >> 10 ;
T_1 V_96 = V_90 . V_99 ;
while ( V_95 >>= 1 )
V_96 <<= 1 ;
return sprintf ( V_83 , L_24 , V_96 ) ;
}
return V_74 ;
}
static T_4 F_39 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 )
return sprintf ( V_83 , L_24 , V_90 . V_100 ) ;
return V_74 ;
}
static T_4 F_40 ( struct V_79 * V_80 , struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
struct V_89 V_90 ;
int V_74 = V_89 ( NULL , V_85 -> V_91 , & V_90 ,
F_35 ( - V_92 ) ,
V_93 ) ;
if ( ! V_74 )
return sprintf ( V_83 , L_24 , V_90 . V_101 ) ;
return V_74 ;
}
int F_41 ( struct V_9 * V_10 , void * V_59 )
{
struct V_84 * V_85 = V_59 ;
struct V_102 * V_103 ;
char * V_104 = NULL ;
int V_74 ;
F_3 ( V_85 ) ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_103 = V_85 -> V_105 . V_106 . V_107 ;
V_104 = F_43 ( V_103 -> V_108 ) ;
F_4 ( V_10 , L_25 ,
F_44 ( V_85 ) , V_104 ,
V_103 -> V_109 ? L_26 : L_2 ) ;
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
int F_46 ( struct V_9 * V_10 , void * V_59 )
{
struct V_84 * V_85 = V_59 ;
struct V_111 * V_112 ;
int V_74 ;
F_3 ( V_85 ) ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_112 = V_85 -> V_105 . V_106 . V_107 -> V_113 ;
if ( V_112 && V_85 -> V_105 . V_106 . V_107 )
F_4 ( V_10 , L_23 , V_112 -> V_114 . V_88 ) ;
else
F_47 ( V_10 , L_27 ) ;
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
void F_48 ( struct V_115 * V_116 , int V_117 ,
struct V_118 * V_119 )
{
unsigned int V_120 ;
struct V_118 * V_121 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
if ( ! V_116 ) {
V_119 -> V_122 = 1 ;
return;
}
V_119 -> V_123 = V_124 ;
V_120 = F_49 ( V_116 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_120 ; V_6 ++ ) {
if ( ! V_116 -> V_126 [ V_6 ] )
continue;
V_121 = F_50 ( V_116 , V_6 , V_117 ) ;
V_119 -> V_122 += V_121 -> V_122 ;
V_119 -> V_127 += V_121 -> V_127 ;
if ( V_121 -> V_123 < V_119 -> V_123 )
V_119 -> V_123 = V_121 -> V_123 ;
if ( V_121 -> V_128 > V_119 -> V_128 )
V_119 -> V_128 = V_121 -> V_128 ;
V_119 -> V_129 += V_121 -> V_129 ;
}
F_51 ( V_116 , V_125 , & V_3 ) ;
}
static int F_52 ( struct V_102 * V_103 , struct V_9 * V_10 )
{
bool V_130 = true ;
if ( V_103 -> V_131 -> V_132 ) {
F_4 ( V_10 , L_28 ) ;
V_130 = false ;
}
F_53 ( V_133 , V_130 ) ;
V_130 = false ;
F_53 ( V_134 , V_130 ) ;
F_53 ( V_135 , V_130 ) ;
F_53 ( V_136 , V_130 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_10 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_130 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_4 ( V_10 , L_1 ,
V_130 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_130 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_4 ( V_10 , L_3 ,
V_130 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_55 ( struct V_9 * V_10 , void * V_59 )
{
char V_137 [ V_138 ] ;
struct V_118 V_7 ;
struct V_139 * V_140 ;
struct V_84 * V_85 = V_59 ;
struct V_102 * V_103 ;
struct V_141 * V_112 ;
struct V_11 * V_12 ;
int V_142 ;
int V_143 ;
int V_144 = 0 ;
int V_74 ;
F_3 ( V_85 ) ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_103 = V_85 -> V_105 . V_106 . V_107 ;
V_12 = & V_103 -> V_145 ;
F_4 ( V_10 , L_29
L_30
L_31
L_32
L_33
L_34 ,
V_85 -> V_146 ,
F_44 ( V_85 ) ,
F_43 ( V_103 -> V_108 ) ,
V_103 -> V_145 . V_14 ) ;
F_54 ( V_10 , V_103 -> V_145 . V_13 ,
L_35 ) ;
F_4 ( V_10 , L_36 ) ;
F_2 ( V_10 , V_12 ) ;
F_4 ( V_10 , L_37 ) ;
F_52 ( V_103 , V_10 ) ;
F_4 ( V_10 ,
L_36
L_38
L_39 ) ;
F_56 ( & V_103 -> V_147 ) ;
V_142 = 0 ;
F_57 (conn, &imp->imp_conn_list, oic_item) {
F_58 ( V_112 -> V_148 -> V_149 . V_150 ,
V_137 , sizeof( V_137 ) ) ;
F_4 ( V_10 , L_1 , V_142 ? L_35 : L_2 , V_137 ) ;
V_142 ++ ;
}
if ( V_103 -> V_113 )
F_58 ( V_103 -> V_113 -> V_149 . V_150 ,
V_137 , sizeof( V_137 ) ) ;
else
strncpy ( V_137 , L_40 , sizeof( V_137 ) ) ;
F_4 ( V_10 ,
L_36
L_41
L_42
L_43
L_44 ,
V_137 ,
V_103 -> V_151 ,
V_103 -> V_152 ,
F_59 ( & V_103 -> V_153 ) ) ;
F_60 ( & V_103 -> V_147 ) ;
if ( ! V_85 -> V_154 )
goto V_155;
V_140 = & V_85 -> V_154 -> V_156 [ V_157 ] ;
F_48 ( V_85 -> V_154 , V_157 , & V_7 ) ;
if ( V_7 . V_122 != 0 ) {
T_1 V_158 = V_7 . V_127 ;
F_61 ( V_158 , V_7 . V_122 ) ;
V_7 . V_127 = V_158 ;
} else {
V_7 . V_127 = 0 ;
}
F_4 ( V_10 ,
L_45
L_46
L_47
L_48
L_49 ,
F_59 ( & V_103 -> V_159 ) ,
F_59 ( & V_103 -> V_160 ) ,
F_59 ( & V_103 -> V_161 ) ,
V_7 . V_127 , V_140 -> V_162 ) ;
V_143 = 0 ;
for ( V_142 = 0 ; V_142 < V_163 ; V_142 ++ ) {
if ( V_103 -> V_164 . V_165 [ V_142 ] == 0 )
break;
V_143 = F_62 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_4 ( V_10 ,
L_50
L_51
L_52 ,
V_143 ,
F_63 ( & V_103 -> V_164 . V_166 ) ) ;
F_4 ( V_10 ,
L_53
L_54
L_55
L_56 ,
V_103 -> V_167 ,
V_103 -> V_168 ,
V_103 -> V_169 ) ;
for ( V_144 = 0 ; V_144 <= 1 ; V_144 ++ ) {
F_48 ( V_85 -> V_154 ,
V_170 + V_171 + V_144 ,
& V_7 ) ;
if ( V_7 . V_127 > 0 && V_7 . V_122 > 0 ) {
T_1 V_158 = V_7 . V_127 ;
F_61 ( V_158 , V_7 . V_122 ) ;
V_7 . V_127 = V_158 ;
F_4 ( V_10 ,
L_57
L_58 ,
V_144 ? L_59 : L_60 ,
V_7 . V_127 ) ;
}
V_143 = ( int ) V_7 . V_127 ;
V_142 = F_64 ( V_172 + V_144 ) + V_173 ;
V_140 = & V_85 -> V_154 -> V_156 [ V_142 ] ;
F_48 ( V_85 -> V_154 , V_142 , & V_7 ) ;
if ( V_7 . V_127 > 0 && V_7 . V_122 != 0 ) {
T_1 V_158 = V_7 . V_127 ;
F_61 ( V_158 , V_7 . V_122 ) ;
V_7 . V_127 = V_158 ;
F_4 ( V_10 ,
L_61 ,
V_140 -> V_162 , V_7 . V_127 ) ;
V_142 = ( int ) V_7 . V_127 ;
if ( V_142 > 0 )
F_4 ( V_10 ,
L_62 ,
V_143 / V_142 , ( 100 * V_143 / V_142 ) % 100 ) ;
}
}
V_155:
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
int F_65 ( struct V_9 * V_10 , void * V_59 )
{
struct V_84 * V_85 = V_59 ;
struct V_102 * V_103 ;
int V_142 , V_143 , V_74 ;
F_3 ( V_85 ) ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_103 = V_85 -> V_105 . V_106 . V_107 ;
F_4 ( V_10 , L_63 ,
F_43 ( V_103 -> V_108 ) ) ;
F_4 ( V_10 , L_64 ) ;
V_143 = V_103 -> V_174 ;
for ( V_142 = 0 ; V_142 < V_175 ; V_142 ++ ) {
struct V_176 * V_177 =
& V_103 -> V_178 [ ( V_143 + V_142 ) % V_175 ] ;
if ( V_177 -> V_179 == 0 )
continue;
F_4 ( V_10 , L_65 , ( V_180 ) V_177 -> V_181 ,
F_43 ( V_177 -> V_179 ) ) ;
}
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
int F_66 ( struct V_9 * V_10 , struct V_182 * V_183 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_184 ; V_6 ++ )
F_4 ( V_10 , L_66 , V_183 -> V_185 [ V_6 ] ) ;
F_4 ( V_10 , L_67 ) ;
return 0 ;
}
int F_67 ( struct V_9 * V_10 , void * V_59 )
{
struct V_84 * V_85 = V_59 ;
struct V_102 * V_103 ;
unsigned int V_186 , V_187 ;
T_6 V_188 , V_189 ;
struct V_190 V_191 ;
int V_6 , V_74 ;
F_3 ( V_85 ) ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_103 = V_85 -> V_105 . V_106 . V_107 ;
V_188 = F_68 () ;
F_69 ( & V_191 , V_188 - V_103 -> V_192 ) ;
F_4 ( V_10 , L_68 V_193 L_69 ,
L_70 , ( V_180 ) V_103 -> V_192 , F_70 ( & V_191 ) ) ;
V_186 = F_63 ( & V_103 -> V_164 . V_166 ) ;
V_187 = V_103 -> V_164 . V_166 . V_194 ;
V_189 = V_103 -> V_164 . V_166 . V_195 ;
F_69 ( & V_191 , V_188 - V_189 ) ;
F_4 ( V_10 , L_71 V_193 L_72 ,
L_73 , V_186 , V_187 , ( V_180 ) V_189 , F_70 ( & V_191 ) ) ;
F_66 ( V_10 , & V_103 -> V_164 . V_166 ) ;
for ( V_6 = 0 ; V_6 < V_163 ; V_6 ++ ) {
if ( V_103 -> V_164 . V_165 [ V_6 ] == 0 )
break;
V_186 = F_63 ( & V_103 -> V_164 . V_196 [ V_6 ] ) ;
V_187 = V_103 -> V_164 . V_196 [ V_6 ] . V_194 ;
V_189 = V_103 -> V_164 . V_196 [ V_6 ] . V_195 ;
F_69 ( & V_191 , V_188 - V_189 ) ;
F_4 ( V_10 , L_74
V_193 L_72 , V_103 -> V_164 . V_165 [ V_6 ] ,
V_186 , V_187 , ( V_180 ) V_189 , F_70 ( & V_191 ) ) ;
F_66 ( V_10 , & V_103 -> V_164 . V_196 [ V_6 ] ) ;
}
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
int F_71 ( struct V_9 * V_10 , void * V_59 )
{
struct V_84 * V_85 = V_59 ;
T_1 V_3 ;
int V_74 ;
V_74 = F_42 ( V_85 ) ;
if ( V_74 )
return V_74 ;
V_3 = V_85 -> V_105 . V_106 . V_107 -> V_145 . V_13 ;
F_4 ( V_10 , L_75 , V_3 ) ;
F_54 ( V_10 , V_3 , L_67 ) ;
F_4 ( V_10 , L_67 ) ;
F_45 ( & V_85 -> V_105 . V_106 . V_110 ) ;
return 0 ;
}
static void F_72 ( struct V_79 * V_80 )
{
struct V_84 * V_85 = F_33 ( V_80 , struct V_84 ,
V_86 ) ;
F_73 ( & V_85 -> V_197 ) ;
}
int F_74 ( struct V_84 * V_85 , struct V_68 * V_69 ,
struct V_198 * V_199 )
{
int V_74 = 0 ;
F_75 ( & V_85 -> V_197 ) ;
V_74 = F_76 ( & V_85 -> V_86 , & V_200 ,
V_85 -> V_201 -> V_202 ,
L_76 , V_85 -> V_146 ) ;
if ( V_74 )
return V_74 ;
if ( V_199 ) {
V_74 = F_77 ( & V_85 -> V_86 , V_199 ) ;
if ( V_74 ) {
F_78 ( & V_85 -> V_86 ) ;
return V_74 ;
}
}
V_85 -> V_203 = F_27 ( V_85 -> V_146 ,
V_85 -> V_201 -> V_204 ,
V_69 , V_85 ) ;
if ( F_21 ( V_85 -> V_203 ) ) {
V_74 = V_85 -> V_203 ? F_24 ( V_85 -> V_203 )
: - V_66 ;
F_22 ( L_77 ,
V_74 , V_85 -> V_146 ) ;
V_85 -> V_203 = NULL ;
}
return V_74 ;
}
int F_79 ( struct V_84 * V_85 )
{
if ( ! V_85 )
return - V_45 ;
if ( ! F_21 ( V_85 -> V_203 ) )
F_25 ( & V_85 -> V_203 ) ;
F_78 ( & V_85 -> V_86 ) ;
F_80 ( & V_85 -> V_197 ) ;
return 0 ;
}
int F_81 ( struct V_115 * V_116 , unsigned int V_205 )
{
struct V_118 * V_206 ;
unsigned int V_207 ;
int V_74 = - V_66 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_3 ( ! V_116 -> V_126 [ V_205 ] ) ;
F_3 ( ( V_116 -> V_208 & V_209 ) == 0 ) ;
V_207 = F_82 ( V_116 ) ;
F_83 ( V_116 -> V_126 [ V_205 ] , V_207 ) ;
if ( V_116 -> V_126 [ V_205 ] ) {
V_74 = 0 ;
if ( F_84 ( V_116 -> V_210 <= V_205 ) ) {
if ( V_116 -> V_208 & V_211 )
F_85 ( & V_116 -> V_212 , V_3 ) ;
else
F_56 ( & V_116 -> V_212 ) ;
if ( V_116 -> V_210 <= V_205 )
V_116 -> V_210 = V_205 + 1 ;
if ( V_116 -> V_208 & V_211 )
F_86 ( & V_116 -> V_212 , V_3 ) ;
else
F_60 ( & V_116 -> V_212 ) ;
}
for ( V_6 = 0 ; V_6 < V_116 -> V_213 ; ++ V_6 ) {
V_206 = F_50 ( V_116 , V_205 , V_6 ) ;
V_206 -> V_123 = V_124 ;
}
}
return V_74 ;
}
struct V_115 * F_87 ( unsigned int V_214 ,
enum V_215 V_3 )
{
struct V_115 * V_116 ;
unsigned int V_120 ;
unsigned int V_207 = 0 ;
int V_6 ;
if ( V_214 == 0 )
return NULL ;
if ( V_216 != 0 )
V_3 |= V_209 ;
if ( V_3 & V_209 )
V_120 = 1 ;
else
V_120 = F_88 () ;
F_89 ( V_116 , F_90 ( F_91 ( * V_116 ) , V_126 [ V_120 ] ) ) ;
if ( ! V_116 )
return NULL ;
V_116 -> V_213 = V_214 ;
V_116 -> V_208 = V_3 ;
F_92 ( & V_116 -> V_212 ) ;
F_89 ( V_116 -> V_156 ,
V_116 -> V_213 * sizeof( struct V_139 ) ) ;
if ( ! V_116 -> V_156 )
goto V_217;
if ( ( V_3 & V_209 ) != 0 ) {
V_207 = F_82 ( V_116 ) ;
F_83 ( V_116 -> V_126 [ 0 ] , V_207 ) ;
if ( ! V_116 -> V_126 [ 0 ] )
goto V_217;
V_116 -> V_210 = 1 ;
} else if ( ( V_3 & V_211 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_120 ; ++ V_6 )
if ( F_81 ( V_116 , V_6 ) < 0 )
goto V_217;
}
return V_116 ;
V_217:
F_93 ( & V_116 ) ;
return NULL ;
}
void F_93 ( struct V_115 * * V_218 )
{
struct V_115 * V_116 = * V_218 ;
unsigned int V_120 ;
unsigned int V_207 ;
unsigned int V_6 ;
if ( ! V_116 || V_116 -> V_213 == 0 )
return;
* V_218 = NULL ;
if ( V_116 -> V_208 & V_209 )
V_120 = 1 ;
else
V_120 = F_88 () ;
V_207 = F_82 ( V_116 ) ;
for ( V_6 = 0 ; V_6 < V_120 ; V_6 ++ )
if ( V_116 -> V_126 [ V_6 ] )
F_94 ( V_116 -> V_126 [ V_6 ] , V_207 ) ;
if ( V_116 -> V_156 )
F_94 ( V_116 -> V_156 , V_116 -> V_213 *
sizeof( struct V_139 ) ) ;
F_94 ( V_116 , F_90 ( F_91 ( * V_116 ) , V_126 [ V_120 ] ) ) ;
}
void F_95 ( struct V_115 * V_116 )
{
struct V_118 * V_121 ;
int V_6 ;
int V_142 ;
unsigned int V_120 ;
unsigned long V_3 = 0 ;
V_120 = F_49 ( V_116 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_120 ; V_6 ++ ) {
if ( ! V_116 -> V_126 [ V_6 ] )
continue;
for ( V_142 = 0 ; V_142 < V_116 -> V_213 ; V_142 ++ ) {
V_121 = F_50 ( V_116 , V_6 , V_142 ) ;
V_121 -> V_122 = 0 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = 0 ;
V_121 -> V_127 = 0 ;
if ( V_116 -> V_208 & V_211 )
V_121 -> V_219 = 0 ;
}
}
F_51 ( V_116 , V_125 , & V_3 ) ;
}
static T_4 F_96 ( struct V_55 * V_55 ,
const char T_2 * V_83 ,
T_7 V_220 , T_8 * V_221 )
{
struct V_9 * V_222 = V_55 -> V_223 ;
struct V_115 * V_116 = V_222 -> V_224 ;
F_95 ( V_116 ) ;
return V_220 ;
}
static void * F_97 ( struct V_9 * V_75 , T_8 * V_225 )
{
struct V_115 * V_116 = V_75 -> V_224 ;
return ( * V_225 < V_116 -> V_213 ) ? V_225 : NULL ;
}
static void F_98 ( struct V_9 * V_75 , void * V_226 )
{
}
static void * F_99 ( struct V_9 * V_75 , void * V_226 , T_8 * V_225 )
{
( * V_225 ) ++ ;
return F_97 ( V_75 , V_225 ) ;
}
static int F_100 ( struct V_9 * V_75 , void * V_226 )
{
struct V_115 * V_116 = V_75 -> V_224 ;
struct V_139 * V_227 ;
struct V_118 V_228 ;
int V_117 = * ( T_8 * ) V_226 ;
if ( V_117 == 0 ) {
struct V_229 V_188 ;
F_101 ( & V_188 ) ;
F_4 ( V_75 , L_78 ,
L_79 ,
( V_180 ) V_188 . V_230 , ( unsigned long ) V_188 . V_231 ) ;
}
V_227 = & V_116 -> V_156 [ V_117 ] ;
F_48 ( V_116 , V_117 , & V_228 ) ;
if ( V_228 . V_122 != 0 ) {
F_4 ( V_75 , L_80 ,
V_227 -> V_232 , V_228 . V_122 , V_227 -> V_162 ) ;
if ( ( V_227 -> V_233 & V_234 ) &&
( V_228 . V_122 > 0 ) ) {
F_4 ( V_75 , L_81 ,
V_228 . V_123 , V_228 . V_128 , V_228 . V_127 ) ;
if ( V_227 -> V_233 & V_235 )
F_4 ( V_75 , L_82 , V_228 . V_129 ) ;
}
F_102 ( V_75 , '\n' ) ;
}
return 0 ;
}
static int F_103 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_9 * V_222 ;
int V_74 ;
V_74 = F_104 ( V_55 , & V_236 ) ;
if ( V_74 )
return V_74 ;
V_222 = V_55 -> V_223 ;
V_222 -> V_224 = V_54 -> V_237 ;
return 0 ;
}
int F_105 ( struct V_56 * V_67 , const char * V_58 ,
struct V_115 * V_116 )
{
struct V_56 * V_62 ;
F_3 ( ! F_21 ( V_67 ) ) ;
V_62 = F_20 ( V_58 , 0644 , V_67 , V_116 ,
& V_238 ) ;
if ( F_21 ( V_62 ) )
return V_62 ? F_24 ( V_62 ) : - V_66 ;
return 0 ;
}
void F_106 ( struct V_115 * V_116 , int V_239 ,
unsigned V_240 , const char * V_58 , const char * V_241 )
{
struct V_139 * V_140 ;
struct V_118 * V_121 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_242 ;
V_140 = & V_116 -> V_156 [ V_239 ] ;
F_107 ( V_140 , L_83 ,
V_239 , V_58 , V_241 ) ;
V_140 -> V_233 = V_240 ;
V_140 -> V_232 = V_58 ;
V_140 -> V_162 = V_241 ;
V_242 = F_49 ( V_116 , V_125 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_242 ; ++ V_6 ) {
if ( ! V_116 -> V_126 [ V_6 ] )
continue;
V_121 = F_50 ( V_116 , V_6 , V_239 ) ;
V_121 -> V_122 = 0 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = 0 ;
V_121 -> V_127 = 0 ;
if ( ( V_116 -> V_208 & V_211 ) != 0 )
V_121 -> V_219 = 0 ;
}
F_51 ( V_116 , V_125 , & V_3 ) ;
}
int F_108 ( struct V_243 * exp )
{
return 0 ;
}
T_9 F_109 ( struct V_118 * V_244 ,
struct V_139 * V_140 ,
enum V_215 V_3 ,
enum V_245 V_246 )
{
T_9 V_7 = 0 ;
if ( ! V_244 || ! V_140 )
return 0 ;
switch ( V_246 ) {
case V_247 :
V_7 = V_140 -> V_233 ;
break;
case V_248 :
V_7 = V_244 -> V_127 ;
if ( ( V_3 & V_211 ) != 0 )
V_7 += V_244 -> V_219 ;
break;
case V_249 :
V_7 = V_244 -> V_123 ;
break;
case V_250 :
V_7 = V_244 -> V_128 ;
break;
case V_251 :
V_7 = ( V_244 -> V_128 - V_244 -> V_123 ) / 2 ;
break;
case V_252 :
V_7 = V_244 -> V_129 ;
break;
case V_253 :
V_7 = V_244 -> V_122 ;
break;
default:
break;
}
return 0 ;
}
int F_110 ( const char T_2 * V_39 , unsigned long V_2 ,
int * V_40 )
{
return F_11 ( V_39 , V_2 , V_40 , 1 ) ;
}
int F_111 ( const char T_2 * V_39 , unsigned long V_2 ,
T_1 * V_40 )
{
return F_112 ( V_39 , V_2 , V_40 , 1 ) ;
}
int F_112 ( const char T_2 * V_39 ,
unsigned long V_2 , T_1 * V_40 , int V_41 )
{
char V_49 [ 22 ] , * V_50 , * V_51 ;
T_1 V_254 , V_255 = 0 , V_241 ;
unsigned V_256 = 1 ;
int V_257 = 1 ;
if ( V_2 > ( sizeof( V_49 ) - 1 ) )
return - V_45 ;
if ( F_12 ( V_49 , V_39 , V_2 ) )
return - V_52 ;
V_49 [ V_2 ] = '\0' ;
V_51 = V_49 ;
if ( * V_51 == '-' ) {
V_257 = - 1 ;
V_51 ++ ;
}
V_254 = F_113 ( V_51 , & V_50 , 10 ) ;
if ( V_51 == V_50 )
return - V_45 ;
if ( * V_50 == '.' ) {
int V_6 ;
V_51 = V_50 + 1 ;
if ( strlen ( V_51 ) > 10 )
V_51 [ 10 ] = '\0' ;
V_255 = F_113 ( V_51 , & V_50 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_50 - V_51 ) ; V_6 ++ )
V_256 *= 10 ;
}
V_241 = 1 ;
if ( V_50 ) {
switch ( tolower ( * V_50 ) ) {
case 'p' :
V_241 <<= 10 ;
case 't' :
V_241 <<= 10 ;
case 'g' :
V_241 <<= 10 ;
case 'm' :
V_241 <<= 10 ;
case 'k' :
V_241 <<= 10 ;
}
}
if ( V_241 > 1 )
V_41 = V_241 ;
V_255 *= V_41 ;
F_61 ( V_255 , V_256 ) ;
* V_40 = V_257 * ( V_254 * V_41 + V_255 ) ;
return 0 ;
}
static char * F_114 ( const char * V_258 , const char * V_259 , T_7 V_220 )
{
T_7 V_260 ;
V_260 = strlen ( V_259 ) ;
if ( ! V_260 )
return ( char * ) V_258 ;
while ( V_220 >= V_260 ) {
V_220 -- ;
if ( ! memcmp ( V_258 , V_259 , V_260 ) )
return ( char * ) V_258 ;
V_258 ++ ;
}
return NULL ;
}
char * F_115 ( const char * V_39 , const char * V_58 ,
T_7 * V_2 )
{
char * V_40 ;
T_7 V_261 = * V_2 ;
V_40 = F_114 ( V_39 , V_58 , V_261 ) ;
if ( ! V_40 )
return ( char * ) V_39 ;
V_40 += strlen ( V_58 ) ;
while ( V_40 < V_39 + V_261 && isspace ( * V_40 ) )
V_40 ++ ;
* V_2 = 0 ;
while ( V_40 < V_39 + V_261 && isalnum ( * V_40 ) ) {
++ * V_2 ;
++ V_40 ;
}
return V_40 - * V_2 ;
}
int F_116 ( struct V_56 * V_67 , const char * V_58 ,
T_3 V_63 , const struct V_60 * V_262 ,
void * V_59 )
{
struct V_56 * V_62 ;
F_3 ( ( V_262 -> V_65 == NULL ) == ( ( V_63 & 0222 ) == 0 ) ) ;
V_62 = F_20 ( V_58 , V_63 , V_67 , V_59 , V_262 ) ;
if ( F_21 ( V_62 ) )
return V_62 ? F_24 ( V_62 ) : - V_66 ;
return 0 ;
}
int F_117 ( struct V_84 * V_263 ,
const char * V_58 ,
T_3 V_63 ,
const struct V_60 * V_262 ,
void * V_59 )
{
return F_116 ( V_263 -> V_203 , V_58 ,
V_63 , V_262 , V_59 ) ;
}
void F_118 ( struct V_264 * V_265 , unsigned int V_266 )
{
if ( V_266 >= V_267 )
V_266 = V_267 - 1 ;
F_56 ( & V_265 -> V_268 ) ;
V_265 -> V_269 [ V_266 ] ++ ;
F_60 ( & V_265 -> V_268 ) ;
}
void F_119 ( struct V_264 * V_265 , unsigned int V_266 )
{
unsigned int V_40 = 0 ;
if ( F_120 ( V_266 != 0 ) )
V_40 = F_10 ( F_121 ( V_266 - 1 ) , V_267 ) ;
F_118 ( V_265 , V_40 ) ;
}
unsigned long F_122 ( struct V_264 * V_265 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_267 ; V_6 ++ )
V_7 += V_265 -> V_269 [ V_6 ] ;
return V_7 ;
}
void F_123 ( struct V_264 * V_265 )
{
F_56 ( & V_265 -> V_268 ) ;
memset ( V_265 -> V_269 , 0 , sizeof( V_265 -> V_269 ) ) ;
F_60 ( & V_265 -> V_268 ) ;
}
static T_4 F_124 ( struct V_79 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_270 * V_271 = F_33 ( V_82 , struct V_270 , V_82 ) ;
return V_271 -> V_272 ? V_271 -> V_272 ( V_80 , V_82 , V_83 ) : 0 ;
}
static T_4 F_125 ( struct V_79 * V_80 , struct V_81 * V_82 ,
const char * V_83 , T_7 V_220 )
{
struct V_270 * V_271 = F_33 ( V_82 , struct V_270 , V_82 ) ;
return V_271 -> V_273 ? V_271 -> V_273 ( V_80 , V_82 , V_83 , V_220 ) : V_220 ;
}
