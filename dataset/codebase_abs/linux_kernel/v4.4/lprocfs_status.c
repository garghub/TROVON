int F_1 ( char * V_1 , int V_2 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 , V_7 = 0 ;
for ( V_6 = 0 ; V_8 [ V_6 ] != NULL ; V_6 ++ , V_5 <<= 1 ) {
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
int F_2 ( char * V_9 , unsigned long V_2 , long V_10 ,
int V_11 )
{
long V_12 , V_13 ;
int V_14 ;
if ( V_2 < 10 )
return - V_15 ;
V_12 = V_10 / V_11 ;
V_14 = snprintf ( V_9 , V_2 , L_4 , V_12 ) ;
V_13 = V_10 % V_11 ;
if ( V_14 < ( V_2 - 4 ) && V_13 > 0 ) {
long V_16 ;
int V_6 , V_17 = 1 , V_18 = 0 ;
V_16 = V_13 * 10 ;
V_9 [ V_14 ++ ] = '.' ;
while ( V_18 < 2 && ( V_16 / V_11 ) < 1 ) {
V_9 [ V_14 ++ ] = '0' ;
V_16 *= 10 ;
V_18 ++ ;
}
for ( V_6 = 0 ; V_6 < ( 5 - V_14 ) ; V_6 ++ )
V_17 *= 10 ;
V_18 = F_3 ( ( int ) V_2 - V_14 , 3 - V_18 ) ;
V_14 += snprintf ( V_9 + V_14 , V_18 , L_4 ,
V_13 * V_17 / V_11 ) ;
V_14 -- ;
while ( V_9 [ V_14 ] < '1' || V_9 [ V_14 ] > '9' ) {
V_14 -- ;
if ( V_9 [ V_14 ] == '.' ) {
V_14 -- ;
break;
}
}
V_14 ++ ;
}
V_9 [ V_14 ++ ] = '\n' ;
return V_14 ;
}
int F_4 ( const char T_2 * V_9 , unsigned long V_2 ,
int * V_10 , int V_11 )
{
char V_19 [ 20 ] , * V_20 , * V_21 ;
if ( V_2 > ( sizeof( V_19 ) - 1 ) )
return - V_15 ;
if ( F_5 ( V_19 , V_9 , V_2 ) )
return - V_22 ;
V_19 [ V_2 ] = '\0' ;
V_21 = V_19 ;
if ( * V_21 == '-' ) {
V_11 = - V_11 ;
V_21 ++ ;
}
* V_10 = ( int ) F_6 ( V_21 , & V_20 , 10 ) * V_11 ;
if ( V_21 == V_20 )
return - V_15 ;
if ( V_20 != NULL && * V_20 == '.' ) {
int V_23 , pow = 1 ;
int V_6 ;
V_21 = V_20 + 1 ;
if ( strlen ( V_21 ) > 5 )
V_21 [ 5 ] = '\0' ;
V_23 = ( int ) F_6 ( V_21 , & V_20 , 10 ) * V_11 ;
if ( V_21 < V_20 ) {
for ( V_6 = 0 ; V_6 < ( V_20 - V_21 ) ; V_6 ++ )
pow *= 10 ;
* V_10 += V_23 / pow ;
}
}
return 0 ;
}
int F_7 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
return F_8 ( V_24 , V_25 ) ;
}
int F_9 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
return F_10 ( V_24 , V_25 ) ;
}
struct V_26 * F_11 ( struct V_26 * V_27 ,
char * V_28 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_26 * V_32 ;
T_3 V_33 = 0 ;
if ( V_27 == NULL || V_28 == NULL || V_31 == NULL )
return F_12 ( - V_15 ) ;
if ( V_31 -> V_34 )
V_33 = 0444 ;
if ( V_31 -> V_35 )
V_33 |= 0200 ;
V_32 = F_13 ( V_28 , V_33 , V_27 , V_29 , V_31 ) ;
if ( F_14 ( V_32 ) ) {
F_15 ( L_5 , V_28 ) ;
return V_32 ? : F_12 ( - V_36 ) ;
}
return V_32 ;
}
int F_16 ( struct V_26 * V_37 ,
struct V_38 * V_39 ,
void * V_29 )
{
if ( F_14 ( V_37 ) || F_14 ( V_39 ) )
return - V_15 ;
while ( V_39 -> V_28 != NULL ) {
struct V_26 * V_32 ;
T_3 V_33 = 0 ;
if ( V_39 -> V_40 != 0000 ) {
V_33 = V_39 -> V_40 ;
} else if ( V_39 -> V_31 ) {
if ( V_39 -> V_31 -> V_34 )
V_33 = 0444 ;
if ( V_39 -> V_31 -> V_35 )
V_33 |= 0200 ;
}
V_32 = F_13 ( V_39 -> V_28 , V_33 , V_37 ,
V_39 -> V_29 ? : V_29 ,
V_39 -> V_31 ? : & V_41
) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_17 ( V_32 ) : - V_36 ;
V_39 ++ ;
}
return 0 ;
}
void F_18 ( struct V_26 * * V_42 )
{
F_19 ( * V_42 ) ;
* V_42 = NULL ;
}
struct V_26 * F_20 ( const char * V_28 ,
struct V_26 * V_37 ,
struct V_38 * V_39 , void * V_29 )
{
struct V_26 * V_32 ;
V_32 = F_21 ( V_28 , V_37 ) ;
if ( F_14 ( V_32 ) ) {
V_32 = V_32 ? : F_12 ( - V_36 ) ;
goto V_43;
}
if ( ! F_14 ( V_39 ) ) {
int V_44 ;
V_44 = F_16 ( V_32 , V_39 , V_29 ) ;
if ( V_44 != 0 ) {
F_22 ( V_32 ) ;
V_32 = F_12 ( V_44 ) ;
}
}
V_43:
return V_32 ;
}
int F_23 ( struct V_45 * V_46 , void * V_29 )
{
F_24 ( V_46 , L_6 , * ( unsigned int * ) V_29 ) ;
return 0 ;
}
int F_25 ( struct V_25 * V_25 , const char T_2 * V_9 ,
unsigned long V_2 , void * V_29 )
{
unsigned * V_47 = V_29 ;
char V_48 [ V_49 + 1 ] , * V_20 ;
unsigned long V_50 ;
V_48 [ V_49 ] = '\0' ;
if ( F_5 ( V_48 , V_9 , V_49 ) )
return - V_22 ;
V_50 = F_6 ( V_48 , & V_20 , 0 ) ;
if ( V_48 == V_20 )
return - V_15 ;
* V_47 = ( unsigned int ) V_50 ;
return V_2 ;
}
static T_4 F_26 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
return sprintf ( V_55 , L_7 , V_57 -> V_59 . V_60 ) ;
}
static T_4 F_28 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 )
return sprintf ( V_55 , L_6 , V_62 . V_66 ) ;
return V_44 ;
}
static T_4 F_30 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 ) {
T_5 V_67 = V_62 . V_66 >> 10 ;
T_1 V_68 = V_62 . V_69 ;
while ( V_67 >>= 1 )
V_68 <<= 1 ;
return sprintf ( V_55 , L_8 , V_68 ) ;
}
return V_44 ;
}
static T_4 F_31 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 ) {
T_5 V_67 = V_62 . V_66 >> 10 ;
T_1 V_68 = V_62 . V_70 ;
while ( V_67 >>= 1 )
V_68 <<= 1 ;
return sprintf ( V_55 , L_8 , V_68 ) ;
}
return V_44 ;
}
static T_4 F_32 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 ) {
T_5 V_67 = V_62 . V_66 >> 10 ;
T_1 V_68 = V_62 . V_71 ;
while ( V_67 >>= 1 )
V_68 <<= 1 ;
return sprintf ( V_55 , L_8 , V_68 ) ;
}
return V_44 ;
}
static T_4 F_33 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 )
return sprintf ( V_55 , L_8 , V_62 . V_72 ) ;
return V_44 ;
}
static T_4 F_34 ( struct V_51 * V_52 , struct V_53 * V_54 ,
char * V_55 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
struct V_61 V_62 ;
int V_44 = V_61 ( NULL , V_57 -> V_63 , & V_62 ,
F_29 ( - V_64 ) ,
V_65 ) ;
if ( ! V_44 )
return sprintf ( V_55 , L_8 , V_62 . V_73 ) ;
return V_44 ;
}
int F_35 ( struct V_45 * V_46 , void * V_29 )
{
struct V_56 * V_57 = V_29 ;
struct V_74 * V_75 ;
char * V_76 = NULL ;
int V_44 ;
F_36 ( V_57 != NULL ) ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_75 = V_57 -> V_77 . V_78 . V_79 ;
V_76 = F_38 ( V_75 -> V_80 ) ;
F_24 ( V_46 , L_9 ,
F_39 ( V_57 ) , V_76 ,
V_75 -> V_81 ? L_10 : L_2 ) ;
F_40 ( V_57 ) ;
return 0 ;
}
int F_41 ( struct V_45 * V_46 , void * V_29 )
{
struct V_56 * V_57 = V_29 ;
struct V_82 * V_83 ;
int V_44 ;
F_36 ( V_57 != NULL ) ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_83 = V_57 -> V_77 . V_78 . V_79 -> V_84 ;
if ( V_83 && V_57 -> V_77 . V_78 . V_79 )
F_24 ( V_46 , L_7 , V_83 -> V_85 . V_60 ) ;
else
F_42 ( V_46 , L_11 ) ;
F_40 ( V_57 ) ;
return 0 ;
}
void F_43 ( struct V_86 * V_87 , int V_88 ,
struct V_89 * V_90 )
{
unsigned int V_91 ;
struct V_89 * V_92 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
if ( V_87 == NULL ) {
V_90 -> V_93 = 1 ;
return;
}
V_90 -> V_94 = V_95 ;
V_91 = F_44 ( V_87 , V_96 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ ) {
if ( V_87 -> V_97 [ V_6 ] == NULL )
continue;
V_92 = F_45 ( V_87 , V_6 , V_88 ) ;
V_90 -> V_93 += V_92 -> V_93 ;
V_90 -> V_98 += V_92 -> V_98 ;
if ( V_92 -> V_94 < V_90 -> V_94 )
V_90 -> V_94 = V_92 -> V_94 ;
if ( V_92 -> V_99 > V_90 -> V_99 )
V_90 -> V_99 = V_92 -> V_99 ;
V_90 -> V_100 += V_92 -> V_100 ;
}
F_46 ( V_87 , V_96 , & V_3 ) ;
}
static int F_47 ( struct V_74 * V_75 , struct V_45 * V_46 )
{
bool V_101 = true ;
if ( V_75 -> V_102 -> V_103 ) {
F_24 ( V_46 , L_12 ) ;
V_101 = false ;
}
F_48 ( V_104 , V_101 ) ;
V_101 = false ;
F_48 ( V_105 , V_101 ) ;
F_48 ( V_106 , V_101 ) ;
F_48 ( V_107 , V_101 ) ;
return 0 ;
}
static void F_49 ( struct V_45 * V_46 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_101 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] != NULL ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_24 ( V_46 , L_1 ,
V_101 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_101 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_24 ( V_46 , L_3 ,
V_101 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_50 ( struct V_45 * V_46 , void * V_29 )
{
char V_108 [ V_109 ] ;
struct V_89 V_7 ;
struct V_110 * V_111 ;
struct V_56 * V_57 = V_29 ;
struct V_74 * V_75 ;
struct V_112 * V_83 ;
int V_113 ;
int V_114 ;
int V_115 = 0 ;
int V_44 ;
F_36 ( V_57 != NULL ) ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_75 = V_57 -> V_77 . V_78 . V_79 ;
F_24 ( V_46 ,
L_13
L_14
L_15
L_16
L_17
L_18 ,
V_57 -> V_116 ,
F_39 ( V_57 ) ,
F_38 ( V_75 -> V_80 ) ,
V_75 -> V_117 . V_118 ) ;
F_49 ( V_46 , V_75 -> V_117 . V_119 , L_19 ) ;
F_24 ( V_46 ,
L_20
L_21 ) ;
F_47 ( V_75 , V_46 ) ;
F_24 ( V_46 ,
L_20
L_22
L_23 ) ;
F_51 ( & V_75 -> V_120 ) ;
V_113 = 0 ;
F_52 (conn, &imp->imp_conn_list, oic_item) {
F_53 ( V_83 -> V_121 -> V_122 . V_123 ,
V_108 , sizeof( V_108 ) ) ;
F_24 ( V_46 , L_1 , V_113 ? L_19 : L_2 , V_108 ) ;
V_113 ++ ;
}
F_53 ( V_75 -> V_84 -> V_122 . V_123 ,
V_108 , sizeof( V_108 ) ) ;
F_24 ( V_46 ,
L_20
L_24
L_25
L_26
L_27 ,
V_75 -> V_84 == NULL ? L_28 : V_108 ,
V_75 -> V_124 ,
V_75 -> V_125 ,
F_54 ( & V_75 -> V_126 ) ) ;
F_55 ( & V_75 -> V_120 ) ;
if ( V_57 -> V_127 == NULL )
goto V_128;
V_111 = & V_57 -> V_127 -> V_129 [ V_130 ] ;
F_43 ( V_57 -> V_127 , V_130 , & V_7 ) ;
if ( V_7 . V_93 != 0 ) {
T_1 V_131 = V_7 . V_98 ;
F_56 ( V_131 , V_7 . V_93 ) ;
V_7 . V_98 = V_131 ;
} else
V_7 . V_98 = 0 ;
F_24 ( V_46 ,
L_29
L_30
L_31
L_32
L_33 ,
F_54 ( & V_75 -> V_132 ) ,
F_54 ( & V_75 -> V_133 ) ,
F_54 ( & V_75 -> V_134 ) ,
V_7 . V_98 , V_111 -> V_135 ) ;
V_114 = 0 ;
for ( V_113 = 0 ; V_113 < V_136 ; V_113 ++ ) {
if ( V_75 -> V_137 . V_138 [ V_113 ] == 0 )
break;
V_114 = F_57 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_24 ( V_46 ,
L_34
L_35
L_36 ,
V_114 ,
F_58 ( & V_75 -> V_137 . V_139 ) ) ;
F_24 ( V_46 ,
L_37
L_38
L_39
L_40 ,
V_75 -> V_140 ,
V_75 -> V_141 ,
V_75 -> V_142 ) ;
for ( V_115 = 0 ; V_115 <= 1 ; V_115 ++ ) {
F_43 ( V_57 -> V_127 ,
V_143 + V_144 + V_115 ,
& V_7 ) ;
if ( V_7 . V_98 > 0 && V_7 . V_93 > 0 ) {
T_1 V_131 = V_7 . V_98 ;
F_56 ( V_131 , V_7 . V_93 ) ;
V_7 . V_98 = V_131 ;
F_24 ( V_46 ,
L_41
L_42 ,
V_115 ? L_43 : L_44 ,
V_7 . V_98 ) ;
}
V_114 = ( int ) V_7 . V_98 ;
V_113 = F_59 ( V_145 + V_115 ) + V_146 ;
V_111 = & V_57 -> V_127 -> V_129 [ V_113 ] ;
F_43 ( V_57 -> V_127 , V_113 , & V_7 ) ;
if ( V_7 . V_98 > 0 && V_7 . V_93 != 0 ) {
T_1 V_131 = V_7 . V_98 ;
F_56 ( V_131 , V_7 . V_93 ) ;
V_7 . V_98 = V_131 ;
F_24 ( V_46 ,
L_45 ,
V_111 -> V_135 , V_7 . V_98 ) ;
V_113 = ( int ) V_7 . V_98 ;
if ( V_113 > 0 )
F_24 ( V_46 ,
L_46 ,
V_114 / V_113 , ( 100 * V_114 / V_113 ) % 100 ) ;
}
}
V_128:
F_40 ( V_57 ) ;
return 0 ;
}
int F_60 ( struct V_45 * V_46 , void * V_29 )
{
struct V_56 * V_57 = V_29 ;
struct V_74 * V_75 ;
int V_113 , V_114 , V_44 ;
F_36 ( V_57 != NULL ) ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_75 = V_57 -> V_77 . V_78 . V_79 ;
F_24 ( V_46 , L_47 ,
F_38 ( V_75 -> V_80 ) ) ;
F_24 ( V_46 , L_48 ) ;
V_114 = V_75 -> V_147 ;
for ( V_113 = 0 ; V_113 < V_148 ; V_113 ++ ) {
struct V_149 * V_150 =
& V_75 -> V_151 [ ( V_114 + V_113 ) % V_148 ] ;
if ( V_150 -> V_152 == 0 )
continue;
F_24 ( V_46 , L_49 , ( V_153 ) V_150 -> V_154 ,
F_38 ( V_150 -> V_152 ) ) ;
}
F_40 ( V_57 ) ;
return 0 ;
}
int F_61 ( struct V_45 * V_46 , struct V_155 * V_156 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_157 ; V_6 ++ )
F_24 ( V_46 , L_50 , V_156 -> V_158 [ V_6 ] ) ;
F_24 ( V_46 , L_51 ) ;
return 0 ;
}
int F_62 ( struct V_45 * V_46 , void * V_29 )
{
struct V_56 * V_57 = V_29 ;
struct V_74 * V_75 ;
unsigned int V_159 , V_160 ;
T_6 V_161 , V_162 ;
struct V_163 V_164 ;
int V_6 , V_44 ;
F_36 ( V_57 != NULL ) ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_75 = V_57 -> V_77 . V_78 . V_79 ;
V_161 = F_63 () ;
F_64 ( & V_164 , V_161 - V_75 -> V_165 ) ;
F_24 ( V_46 , L_52 V_166 L_53 ,
L_54 , ( V_153 ) V_75 -> V_165 , F_65 ( & V_164 ) ) ;
V_159 = F_58 ( & V_75 -> V_137 . V_139 ) ;
V_160 = V_75 -> V_137 . V_139 . V_167 ;
V_162 = V_75 -> V_137 . V_139 . V_168 ;
F_64 ( & V_164 , V_161 - V_162 ) ;
F_24 ( V_46 , L_55 V_166 L_56 ,
L_57 , V_159 , V_160 , ( V_153 ) V_162 , F_65 ( & V_164 ) ) ;
F_61 ( V_46 , & V_75 -> V_137 . V_139 ) ;
for ( V_6 = 0 ; V_6 < V_136 ; V_6 ++ ) {
if ( V_75 -> V_137 . V_138 [ V_6 ] == 0 )
break;
V_159 = F_58 ( & V_75 -> V_137 . V_169 [ V_6 ] ) ;
V_160 = V_75 -> V_137 . V_169 [ V_6 ] . V_167 ;
V_162 = V_75 -> V_137 . V_169 [ V_6 ] . V_168 ;
F_64 ( & V_164 , V_161 - V_162 ) ;
F_24 ( V_46 , L_58
V_166 L_56 , V_75 -> V_137 . V_138 [ V_6 ] ,
V_159 , V_160 , ( V_153 ) V_162 , F_65 ( & V_164 ) ) ;
F_61 ( V_46 , & V_75 -> V_137 . V_169 [ V_6 ] ) ;
}
F_40 ( V_57 ) ;
return 0 ;
}
int F_66 ( struct V_45 * V_46 , void * V_29 )
{
struct V_56 * V_57 = V_29 ;
T_1 V_3 ;
int V_44 ;
V_44 = F_37 ( V_57 ) ;
if ( V_44 )
return V_44 ;
V_3 = V_57 -> V_77 . V_78 . V_79 -> V_117 . V_119 ;
F_24 ( V_46 , L_59 , V_3 ) ;
F_49 ( V_46 , V_3 , L_51 ) ;
F_24 ( V_46 , L_51 ) ;
F_40 ( V_57 ) ;
return 0 ;
}
static void F_67 ( struct V_51 * V_52 )
{
struct V_56 * V_57 = F_27 ( V_52 , struct V_56 ,
V_58 ) ;
F_68 ( & V_57 -> V_170 ) ;
}
int F_69 ( struct V_56 * V_57 , struct V_38 * V_39 ,
struct V_171 * V_172 )
{
int V_44 = 0 ;
F_70 ( & V_57 -> V_170 ) ;
V_44 = F_71 ( & V_57 -> V_58 , & V_173 ,
V_57 -> V_174 -> V_175 ,
L_60 , V_57 -> V_116 ) ;
if ( V_44 )
return V_44 ;
if ( V_172 ) {
V_44 = F_72 ( & V_57 -> V_58 , V_172 ) ;
if ( V_44 ) {
F_73 ( & V_57 -> V_58 ) ;
return V_44 ;
}
}
V_57 -> V_176 = F_20 ( V_57 -> V_116 ,
V_57 -> V_174 -> V_177 ,
V_39 , V_57 ) ;
if ( F_14 ( V_57 -> V_176 ) ) {
V_44 = V_57 -> V_176 ? F_17 ( V_57 -> V_176 )
: - V_36 ;
F_15 ( L_61 ,
V_44 , V_57 -> V_116 ) ;
V_57 -> V_176 = NULL ;
}
return V_44 ;
}
int F_74 ( struct V_56 * V_57 )
{
if ( ! V_57 )
return - V_15 ;
if ( ! F_14 ( V_57 -> V_176 ) )
F_18 ( & V_57 -> V_176 ) ;
F_73 ( & V_57 -> V_58 ) ;
F_75 ( & V_57 -> V_170 ) ;
return 0 ;
}
int F_76 ( struct V_86 * V_87 , unsigned int V_178 )
{
struct V_89 * V_179 ;
unsigned int V_180 ;
int V_44 = - V_36 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_36 ( V_87 -> V_97 [ V_178 ] == NULL ) ;
F_36 ( ( V_87 -> V_181 & V_182 ) == 0 ) ;
V_180 = F_77 ( V_87 ) ;
F_78 ( V_87 -> V_97 [ V_178 ] , V_180 ) ;
if ( V_87 -> V_97 [ V_178 ] != NULL ) {
V_44 = 0 ;
if ( F_79 ( V_87 -> V_183 <= V_178 ) ) {
if ( V_87 -> V_181 & V_184 )
F_80 ( & V_87 -> V_185 , V_3 ) ;
else
F_51 ( & V_87 -> V_185 ) ;
if ( V_87 -> V_183 <= V_178 )
V_87 -> V_183 = V_178 + 1 ;
if ( V_87 -> V_181 & V_184 )
F_81 ( & V_87 -> V_185 , V_3 ) ;
else
F_55 ( & V_87 -> V_185 ) ;
}
for ( V_6 = 0 ; V_6 < V_87 -> V_186 ; ++ V_6 ) {
V_179 = F_45 ( V_87 , V_178 , V_6 ) ;
V_179 -> V_94 = V_95 ;
}
}
return V_44 ;
}
struct V_86 * F_82 ( unsigned int V_187 ,
enum V_188 V_3 )
{
struct V_86 * V_87 ;
unsigned int V_91 ;
unsigned int V_180 = 0 ;
int V_6 ;
if ( V_187 == 0 )
return NULL ;
if ( V_189 != 0 )
V_3 |= V_182 ;
if ( V_3 & V_182 )
V_91 = 1 ;
else
V_91 = F_83 () ;
F_84 ( V_87 , F_85 ( F_86 ( * V_87 ) , V_97 [ V_91 ] ) ) ;
if ( V_87 == NULL )
return NULL ;
V_87 -> V_186 = V_187 ;
V_87 -> V_181 = V_3 ;
F_87 ( & V_87 -> V_185 ) ;
F_84 ( V_87 -> V_129 ,
V_87 -> V_186 * sizeof( struct V_110 ) ) ;
if ( V_87 -> V_129 == NULL )
goto V_190;
if ( ( V_3 & V_182 ) != 0 ) {
V_180 = F_77 ( V_87 ) ;
F_78 ( V_87 -> V_97 [ 0 ] , V_180 ) ;
if ( V_87 -> V_97 [ 0 ] == NULL )
goto V_190;
V_87 -> V_183 = 1 ;
} else if ( ( V_3 & V_184 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_91 ; ++ V_6 )
if ( F_76 ( V_87 , V_6 ) < 0 )
goto V_190;
}
return V_87 ;
V_190:
F_88 ( & V_87 ) ;
return NULL ;
}
void F_88 ( struct V_86 * * V_191 )
{
struct V_86 * V_87 = * V_191 ;
unsigned int V_91 ;
unsigned int V_180 ;
unsigned int V_6 ;
if ( V_87 == NULL || V_87 -> V_186 == 0 )
return;
* V_191 = NULL ;
if ( V_87 -> V_181 & V_182 )
V_91 = 1 ;
else
V_91 = F_83 () ;
V_180 = F_77 ( V_87 ) ;
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ )
if ( V_87 -> V_97 [ V_6 ] != NULL )
F_89 ( V_87 -> V_97 [ V_6 ] , V_180 ) ;
if ( V_87 -> V_129 != NULL )
F_89 ( V_87 -> V_129 , V_87 -> V_186 *
sizeof( struct V_110 ) ) ;
F_89 ( V_87 , F_85 ( F_86 ( * V_87 ) , V_97 [ V_91 ] ) ) ;
}
void F_90 ( struct V_86 * V_87 )
{
struct V_89 * V_92 ;
int V_6 ;
int V_113 ;
unsigned int V_91 ;
unsigned long V_3 = 0 ;
V_91 = F_44 ( V_87 , V_96 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ ) {
if ( V_87 -> V_97 [ V_6 ] == NULL )
continue;
for ( V_113 = 0 ; V_113 < V_87 -> V_186 ; V_113 ++ ) {
V_92 = F_45 ( V_87 , V_6 , V_113 ) ;
V_92 -> V_93 = 0 ;
V_92 -> V_94 = V_95 ;
V_92 -> V_99 = 0 ;
V_92 -> V_100 = 0 ;
V_92 -> V_98 = 0 ;
if ( V_87 -> V_181 & V_184 )
V_92 -> V_192 = 0 ;
}
}
F_46 ( V_87 , V_96 , & V_3 ) ;
}
static T_4 F_91 ( struct V_25 * V_25 ,
const char T_2 * V_55 ,
T_7 V_193 , T_8 * V_194 )
{
struct V_45 * V_195 = V_25 -> V_196 ;
struct V_86 * V_87 = V_195 -> V_197 ;
F_90 ( V_87 ) ;
return V_193 ;
}
static void * F_92 ( struct V_45 * V_47 , T_8 * V_198 )
{
struct V_86 * V_87 = V_47 -> V_197 ;
return ( * V_198 < V_87 -> V_186 ) ? V_198 : NULL ;
}
static void F_93 ( struct V_45 * V_47 , void * V_199 )
{
}
static void * F_94 ( struct V_45 * V_47 , void * V_199 , T_8 * V_198 )
{
( * V_198 ) ++ ;
return F_92 ( V_47 , V_198 ) ;
}
static int F_95 ( struct V_45 * V_47 , void * V_199 )
{
struct V_86 * V_87 = V_47 -> V_197 ;
struct V_110 * V_200 ;
struct V_89 V_201 ;
int V_88 = * ( T_8 * ) V_199 ;
if ( V_88 == 0 ) {
struct V_202 V_161 ;
F_96 ( & V_161 ) ;
F_24 ( V_47 , L_62 ,
L_63 ,
( V_153 ) V_161 . V_203 , ( unsigned long ) V_161 . V_204 ) ;
}
V_200 = & V_87 -> V_129 [ V_88 ] ;
F_43 ( V_87 , V_88 , & V_201 ) ;
if ( V_201 . V_93 != 0 ) {
F_24 ( V_47 , L_64 ,
V_200 -> V_205 , V_201 . V_93 , V_200 -> V_135 ) ;
if ( ( V_200 -> V_206 & V_207 ) &&
( V_201 . V_93 > 0 ) ) {
F_24 ( V_47 , L_65 ,
V_201 . V_94 , V_201 . V_99 , V_201 . V_98 ) ;
if ( V_200 -> V_206 & V_208 )
F_24 ( V_47 , L_66 , V_201 . V_100 ) ;
}
F_97 ( V_47 , '\n' ) ;
}
return 0 ;
}
static int F_98 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_45 * V_195 ;
int V_44 ;
V_44 = F_99 ( V_25 , & V_209 ) ;
if ( V_44 )
return V_44 ;
V_195 = V_25 -> V_196 ;
V_195 -> V_197 = V_24 -> V_210 ;
return 0 ;
}
int F_100 ( struct V_26 * V_37 , const char * V_28 ,
struct V_86 * V_87 )
{
struct V_26 * V_32 ;
F_36 ( ! F_14 ( V_37 ) ) ;
V_32 = F_13 ( V_28 , 0644 , V_37 , V_87 ,
& V_211 ) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_17 ( V_32 ) : - V_36 ;
return 0 ;
}
void F_101 ( struct V_86 * V_87 , int V_212 ,
unsigned V_213 , const char * V_28 , const char * V_214 )
{
struct V_110 * V_111 ;
struct V_89 * V_92 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_215 ;
F_36 ( V_87 != NULL ) ;
V_111 = & V_87 -> V_129 [ V_212 ] ;
F_102 ( V_111 != NULL , L_67 ,
V_212 , V_28 , V_214 ) ;
V_111 -> V_206 = V_213 ;
V_111 -> V_205 = V_28 ;
V_111 -> V_135 = V_214 ;
V_215 = F_44 ( V_87 , V_96 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_215 ; ++ V_6 ) {
if ( V_87 -> V_97 [ V_6 ] == NULL )
continue;
V_92 = F_45 ( V_87 , V_6 , V_212 ) ;
V_92 -> V_93 = 0 ;
V_92 -> V_94 = V_95 ;
V_92 -> V_99 = 0 ;
V_92 -> V_100 = 0 ;
V_92 -> V_98 = 0 ;
if ( ( V_87 -> V_181 & V_184 ) != 0 )
V_92 -> V_192 = 0 ;
}
F_46 ( V_87 , V_96 , & V_3 ) ;
}
int F_103 ( struct V_216 * exp )
{
return 0 ;
}
T_9 F_104 ( struct V_89 * V_217 ,
struct V_110 * V_111 ,
enum V_188 V_3 ,
enum V_218 V_219 )
{
T_9 V_7 = 0 ;
if ( V_217 == NULL || V_111 == NULL )
return 0 ;
switch ( V_219 ) {
case V_220 :
V_7 = V_111 -> V_206 ;
break;
case V_221 :
V_7 = V_217 -> V_98 ;
if ( ( V_3 & V_184 ) != 0 )
V_7 += V_217 -> V_192 ;
break;
case V_222 :
V_7 = V_217 -> V_94 ;
break;
case V_223 :
V_7 = V_217 -> V_99 ;
break;
case V_224 :
V_7 = ( V_217 -> V_99 - V_217 -> V_94 ) / 2 ;
break;
case V_225 :
V_7 = V_217 -> V_100 ;
break;
case V_226 :
V_7 = V_217 -> V_93 ;
break;
default:
break;
}
return 0 ;
}
int F_105 ( const char T_2 * V_9 , unsigned long V_2 ,
int * V_10 )
{
return F_4 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_106 ( const char T_2 * V_9 , unsigned long V_2 ,
T_1 * V_10 )
{
return F_107 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_107 ( const char * V_9 , unsigned long V_2 ,
T_1 * V_10 , int V_11 )
{
char V_19 [ 22 ] , * V_20 , * V_21 ;
T_1 V_227 , V_228 = 0 , V_214 ;
unsigned V_229 = 1 ;
int V_230 = 1 ;
if ( V_2 > ( sizeof( V_19 ) - 1 ) )
return - V_15 ;
if ( F_5 ( V_19 , V_9 , V_2 ) )
return - V_22 ;
V_19 [ V_2 ] = '\0' ;
V_21 = V_19 ;
if ( * V_21 == '-' ) {
V_230 = - 1 ;
V_21 ++ ;
}
V_227 = F_108 ( V_21 , & V_20 , 10 ) ;
if ( V_21 == V_20 )
return - V_15 ;
if ( * V_20 == '.' ) {
int V_6 ;
V_21 = V_20 + 1 ;
if ( strlen ( V_21 ) > 10 )
V_21 [ 10 ] = '\0' ;
V_228 = F_108 ( V_21 , & V_20 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_20 - V_21 ) ; V_6 ++ )
V_229 *= 10 ;
}
V_214 = 1 ;
switch ( tolower ( * V_20 ) ) {
case 'p' :
V_214 <<= 10 ;
case 't' :
V_214 <<= 10 ;
case 'g' :
V_214 <<= 10 ;
case 'm' :
V_214 <<= 10 ;
case 'k' :
V_214 <<= 10 ;
}
if ( V_214 > 1 )
V_11 = V_214 ;
V_228 *= V_11 ;
F_56 ( V_228 , V_229 ) ;
* V_10 = V_230 * ( V_227 * V_11 + V_228 ) ;
return 0 ;
}
static char * F_109 ( const char * V_231 , const char * V_232 , T_7 V_193 )
{
T_7 V_233 ;
V_233 = strlen ( V_232 ) ;
if ( ! V_233 )
return ( char * ) V_231 ;
while ( V_193 >= V_233 ) {
V_193 -- ;
if ( ! memcmp ( V_231 , V_232 , V_233 ) )
return ( char * ) V_231 ;
V_231 ++ ;
}
return NULL ;
}
char * F_110 ( const char * V_9 , const char * V_28 ,
T_7 * V_2 )
{
char * V_10 ;
T_7 V_234 = * V_2 ;
V_10 = F_109 ( V_9 , V_28 , V_234 ) ;
if ( V_10 == NULL )
return ( char * ) V_9 ;
V_10 += strlen ( V_28 ) ;
while ( V_10 < V_9 + V_234 && isspace ( * V_10 ) )
V_10 ++ ;
* V_2 = 0 ;
while ( V_10 < V_9 + V_234 && isalnum ( * V_10 ) ) {
++ * V_2 ;
++ V_10 ;
}
return V_10 - * V_2 ;
}
int F_111 ( struct V_26 * V_37 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_235 ,
void * V_29 )
{
struct V_26 * V_32 ;
F_36 ( ( V_235 -> V_35 == NULL ) == ( ( V_33 & 0222 ) == 0 ) ) ;
V_32 = F_13 ( V_28 , V_33 , V_37 , V_29 , V_235 ) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_17 ( V_32 ) : - V_36 ;
return 0 ;
}
int F_112 ( struct V_56 * V_236 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_235 ,
void * V_29 )
{
return F_111 ( V_236 -> V_176 , V_28 ,
V_33 , V_235 , V_29 ) ;
}
void F_113 ( struct V_237 * V_238 , unsigned int V_239 )
{
if ( V_239 >= V_240 )
V_239 = V_240 - 1 ;
F_51 ( & V_238 -> V_241 ) ;
V_238 -> V_242 [ V_239 ] ++ ;
F_55 ( & V_238 -> V_241 ) ;
}
void F_114 ( struct V_237 * V_238 , unsigned int V_239 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; ( ( 1 << V_10 ) < V_239 ) && ( V_10 <= V_240 ) ; V_10 ++ )
;
F_113 ( V_238 , V_10 ) ;
}
unsigned long F_115 ( struct V_237 * V_238 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_240 ; V_6 ++ )
V_7 += V_238 -> V_242 [ V_6 ] ;
return V_7 ;
}
void F_116 ( struct V_237 * V_238 )
{
F_51 ( & V_238 -> V_241 ) ;
memset ( V_238 -> V_242 , 0 , sizeof( V_238 -> V_242 ) ) ;
F_55 ( & V_238 -> V_241 ) ;
}
static T_4 F_117 ( struct V_51 * V_52 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_243 * V_244 = F_27 ( V_54 , struct V_243 , V_54 ) ;
return V_244 -> V_245 ? V_244 -> V_245 ( V_52 , V_54 , V_55 ) : 0 ;
}
static T_4 F_118 ( struct V_51 * V_52 , struct V_53 * V_54 ,
const char * V_55 , T_7 V_193 )
{
struct V_243 * V_244 = F_27 ( V_54 , struct V_243 , V_54 ) ;
return V_244 -> V_246 ? V_244 -> V_246 ( V_52 , V_54 , V_55 , V_193 ) : V_193 ;
}
