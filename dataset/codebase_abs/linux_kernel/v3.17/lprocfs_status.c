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
int F_4 ( const char * V_9 , unsigned long V_2 ,
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
T_2 V_33 = 0 ;
if ( V_27 == NULL || V_28 == NULL || V_31 == NULL )
return F_12 ( - V_15 ) ;
if ( V_31 -> V_34 )
V_33 = 0444 ;
if ( V_31 -> V_35 )
V_33 |= 0200 ;
V_32 = F_13 ( V_28 , V_33 , V_27 , V_31 , V_29 ) ;
if ( ! V_32 ) {
F_14 ( L_5 , V_28 ) ;
return F_12 ( - V_36 ) ;
}
return V_32 ;
}
struct V_26 * F_15 ( const char * V_28 ,
struct V_26 * V_37 , const char * V_38 , ... )
{
struct V_26 * V_39 ;
char * V_40 ;
T_3 V_41 ;
if ( V_37 == NULL || V_38 == NULL )
return NULL ;
F_16 ( V_40 , V_42 + 1 ) ;
if ( V_40 == NULL )
return NULL ;
va_start ( V_41 , V_38 ) ;
vsnprintf ( V_40 , V_42 , V_38 , V_41 ) ;
va_end ( V_41 ) ;
V_39 = F_17 ( V_28 , V_37 , V_40 ) ;
if ( V_39 == NULL )
F_14 ( L_6 ,
V_28 , V_40 ) ;
F_18 ( V_40 , V_42 + 1 ) ;
return V_39 ;
}
int F_19 ( struct V_26 * V_27 , struct V_43 * V_44 ,
void * V_29 )
{
if ( V_27 == NULL || V_44 == NULL )
return - V_15 ;
while ( V_44 -> V_28 != NULL ) {
struct V_26 * V_32 ;
T_2 V_33 = 0 ;
if ( V_44 -> V_45 != 0000 ) {
V_33 = V_44 -> V_45 ;
} else if ( V_44 -> V_31 ) {
if ( V_44 -> V_31 -> V_34 )
V_33 = 0444 ;
if ( V_44 -> V_31 -> V_35 )
V_33 |= 0200 ;
}
V_32 = F_13 ( V_44 -> V_28 , V_33 , V_27 ,
V_44 -> V_31 ? : & V_46 ,
V_44 -> V_29 ? : V_29 ) ;
if ( V_32 == NULL )
return - V_36 ;
V_44 ++ ;
}
return 0 ;
}
void F_20 ( struct V_26 * * V_47 )
{
F_21 ( * V_47 ) ;
* V_47 = NULL ;
}
void F_22 ( const char * V_28 , struct V_26 * V_37 )
{
F_23 ( V_37 != NULL ) ;
F_24 ( V_28 , V_37 ) ;
}
struct V_26 * F_25 ( const char * V_28 ,
struct V_26 * V_37 ,
struct V_43 * V_44 , void * V_29 )
{
struct V_26 * V_39 ;
V_39 = F_26 ( V_28 , V_37 ) ;
if ( V_39 == NULL )
GOTO ( V_48 , V_39 = F_12 ( - V_36 ) ) ;
if ( V_44 != NULL ) {
int V_49 = F_19 ( V_39 , V_44 , V_29 ) ;
if ( V_49 != 0 ) {
F_20 ( & V_39 ) ;
V_39 = F_12 ( V_49 ) ;
}
}
V_48:
return V_39 ;
}
int F_27 ( struct V_50 * V_51 , void * V_29 )
{
return F_28 ( V_51 , L_7 , * ( unsigned int * ) V_29 ) ;
}
int F_29 ( struct V_25 * V_25 , const char T_4 * V_9 ,
unsigned long V_2 , void * V_29 )
{
unsigned * V_52 = V_29 ;
char V_53 [ V_42 + 1 ] , * V_20 ;
unsigned long V_54 ;
V_53 [ V_42 ] = '\0' ;
if ( F_5 ( V_53 , V_9 , V_42 ) )
return - V_22 ;
V_54 = F_6 ( V_53 , & V_20 , 0 ) ;
if ( V_53 == V_20 )
return - V_15 ;
* V_52 = ( unsigned int ) V_54 ;
return V_2 ;
}
int F_30 ( struct V_50 * V_51 , void * V_29 )
{
return F_28 ( V_51 , L_8 , * ( T_1 * ) V_29 ) ;
}
int F_31 ( struct V_50 * V_51 , void * V_29 )
{
T_5 * V_55 = V_29 ;
F_23 ( V_55 != NULL ) ;
return F_28 ( V_51 , L_9 , F_32 ( V_55 ) ) ;
}
int F_33 ( struct V_25 * V_25 , const char T_4 * V_9 ,
unsigned long V_2 , void * V_29 )
{
T_5 * V_56 = V_29 ;
int V_10 = 0 ;
int V_49 ;
V_49 = F_34 ( V_9 , V_2 , & V_10 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_10 <= 0 )
return - V_57 ;
F_35 ( V_56 , V_10 ) ;
return V_2 ;
}
int F_36 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
F_23 ( V_59 != NULL ) ;
return F_28 ( V_51 , L_10 , V_59 -> V_60 . V_61 ) ;
}
int F_37 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_62 = V_29 ;
F_23 ( V_62 != NULL ) ;
return F_28 ( V_51 , L_10 , V_62 -> V_63 ) ;
}
int F_38 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 )
V_49 = F_28 ( V_51 , L_7 , V_65 . V_69 ) ;
return V_49 ;
}
int F_40 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 ) {
T_6 V_70 = V_65 . V_69 >> 10 ;
T_1 V_71 = V_65 . V_72 ;
while ( V_70 >>= 1 )
V_71 <<= 1 ;
V_49 = F_28 ( V_51 , L_8 , V_71 ) ;
}
return V_49 ;
}
int F_41 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 ) {
T_6 V_70 = V_65 . V_69 >> 10 ;
T_1 V_71 = V_65 . V_73 ;
while ( V_70 >>= 1 )
V_71 <<= 1 ;
V_49 = F_28 ( V_51 , L_8 , V_71 ) ;
}
return V_49 ;
}
int F_42 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 ) {
T_6 V_70 = V_65 . V_69 >> 10 ;
T_1 V_71 = V_65 . V_74 ;
while ( V_70 >>= 1 )
V_71 <<= 1 ;
V_49 = F_28 ( V_51 , L_8 , V_71 ) ;
}
return V_49 ;
}
int F_43 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 )
V_49 = F_28 ( V_51 , L_8 , V_65 . V_75 ) ;
return V_49 ;
}
int F_44 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 )
V_49 = F_28 ( V_51 , L_8 , V_65 . V_76 ) ;
return V_49 ;
}
int F_45 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_77 * V_78 ;
char * V_79 = NULL ;
int V_49 = 0 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
V_79 = F_47 ( V_78 -> V_83 ) ;
V_49 = F_28 ( V_51 , L_11 , F_48 ( V_59 ) , V_79 ,
V_78 -> V_84 ? L_12 : L_2 ) ;
F_49 ( V_59 ) ;
return V_49 ;
}
int F_50 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_85 * V_86 ;
int V_49 = 0 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_86 = V_59 -> V_80 . V_81 . V_82 -> V_87 ;
if ( V_86 && V_59 -> V_80 . V_81 . V_82 )
V_49 = F_28 ( V_51 , L_10 , V_86 -> V_88 . V_61 ) ;
else
V_49 = F_28 ( V_51 , L_10 , L_13 ) ;
F_49 ( V_59 ) ;
return V_49 ;
}
void F_51 ( struct V_89 * V_90 , int V_91 ,
struct V_92 * V_93 )
{
unsigned int V_94 ;
struct V_92 * V_95 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
if ( V_90 == NULL ) {
V_93 -> V_96 = 1 ;
return;
}
V_93 -> V_97 = V_98 ;
V_94 = F_52 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
V_95 = F_53 ( V_90 , V_6 , V_91 ) ;
V_93 -> V_96 += V_95 -> V_96 ;
V_93 -> V_101 += V_95 -> V_101 ;
if ( V_95 -> V_97 < V_93 -> V_97 )
V_93 -> V_97 = V_95 -> V_97 ;
if ( V_95 -> V_102 > V_93 -> V_102 )
V_93 -> V_102 = V_95 -> V_102 ;
V_93 -> V_103 += V_95 -> V_103 ;
}
F_54 ( V_90 , V_99 , & V_3 ) ;
}
static int F_55 ( struct V_77 * V_78 , struct V_50 * V_51 )
{
bool V_104 = true ;
if ( V_78 -> V_105 -> V_106 ) {
F_28 ( V_51 , L_14 ) ;
V_104 = false ;
}
F_56 ( V_107 , V_104 ) ;
V_104 = false ;
F_56 ( V_108 , V_104 ) ;
F_56 ( V_109 , V_104 ) ;
F_56 ( V_110 , V_104 ) ;
return 0 ;
}
static void F_57 ( struct V_50 * V_51 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_104 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] != NULL ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_28 ( V_51 , L_1 ,
V_104 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_104 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_28 ( V_51 , L_3 ,
V_104 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_58 ( struct V_50 * V_51 , void * V_29 )
{
struct V_92 V_7 ;
struct V_111 * V_112 ;
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_77 * V_78 ;
struct V_113 * V_86 ;
int V_114 ;
int V_115 ;
int V_116 = 0 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
F_28 ( V_51 ,
L_15
L_16
L_17
L_18
L_19
L_20 ,
V_59 -> V_63 ,
F_48 ( V_59 ) ,
F_47 ( V_78 -> V_83 ) ,
V_78 -> V_117 . V_118 ) ;
F_57 ( V_51 , V_78 -> V_117 . V_119 , L_21 ) ;
F_28 ( V_51 ,
L_22
L_23 ) ;
F_55 ( V_78 , V_51 ) ;
F_28 ( V_51 ,
L_22
L_24
L_25 ) ;
F_59 ( & V_78 -> V_120 ) ;
V_114 = 0 ;
F_60 (conn, &imp->imp_conn_list, oic_item) {
F_28 ( V_51 , L_1 , V_114 ? L_21 : L_2 ,
F_61 ( V_86 -> V_121 -> V_122 . V_123 ) ) ;
V_114 ++ ;
}
F_28 ( V_51 ,
L_22
L_26
L_27
L_28
L_29 ,
V_78 -> V_87 == NULL ? L_13 :
F_61 ( V_78 -> V_87 -> V_122 . V_123 ) ,
V_78 -> V_124 ,
V_78 -> V_125 ,
F_32 ( & V_78 -> V_126 ) ) ;
F_62 ( & V_78 -> V_120 ) ;
if ( V_59 -> V_127 == NULL )
goto V_128;
V_112 = & V_59 -> V_127 -> V_129 [ V_130 ] ;
F_51 ( V_59 -> V_127 , V_130 , & V_7 ) ;
if ( V_7 . V_96 != 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_63 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
} else
V_7 . V_101 = 0 ;
F_28 ( V_51 ,
L_30
L_31
L_32
L_33
L_34 ,
F_32 ( & V_78 -> V_132 ) ,
F_32 ( & V_78 -> V_133 ) ,
F_32 ( & V_78 -> V_134 ) ,
V_7 . V_101 , V_112 -> V_135 ) ;
V_115 = 0 ;
for( V_114 = 0 ; V_114 < V_136 ; V_114 ++ ) {
if ( V_78 -> V_137 . V_138 [ V_114 ] == 0 )
break;
V_115 = F_64 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_28 ( V_51 ,
L_35
L_36
L_37 ,
V_115 ,
F_65 ( & V_78 -> V_137 . V_139 ) ) ;
F_28 ( V_51 ,
L_38
L_39
L_40
L_41 ,
V_78 -> V_140 ,
V_78 -> V_141 ,
V_78 -> V_142 ) ;
for ( V_116 = 0 ; V_116 <= 1 ; V_116 ++ ) {
F_51 ( V_59 -> V_127 ,
V_143 + V_144 + V_116 ,
& V_7 ) ;
if ( V_7 . V_101 > 0 && V_7 . V_96 > 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_63 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
F_28 ( V_51 ,
L_42
L_43 ,
V_116 ? L_44 : L_45 ,
V_7 . V_101 ) ;
}
V_115 = ( int ) V_7 . V_101 ;
V_114 = F_66 ( V_145 + V_116 ) + V_146 ;
V_112 = & V_59 -> V_127 -> V_129 [ V_114 ] ;
F_51 ( V_59 -> V_127 , V_114 , & V_7 ) ;
if ( V_7 . V_101 > 0 && V_7 . V_96 != 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_63 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
F_28 ( V_51 ,
L_46 ,
V_112 -> V_135 , V_7 . V_101 ) ;
V_114 = ( int ) V_7 . V_101 ;
if ( V_114 > 0 )
F_28 ( V_51 ,
L_47 ,
V_115 / V_114 , ( 100 * V_115 / V_114 ) % 100 ) ;
}
}
V_128:
F_49 ( V_59 ) ;
return 0 ;
}
int F_67 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_77 * V_78 ;
int V_114 , V_115 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
F_28 ( V_51 , L_48 ,
F_47 ( V_78 -> V_83 ) ) ;
F_28 ( V_51 , L_49 ) ;
V_115 = V_78 -> V_147 ;
for ( V_114 = 0 ; V_114 < V_148 ; V_114 ++ ) {
struct V_149 * V_150 =
& V_78 -> V_151 [ ( V_115 + V_114 ) % V_148 ] ;
if ( V_150 -> V_152 == 0 )
continue;
F_28 ( V_51 , L_50 V_153 L_51 ,
V_150 -> V_154 ,
F_47 ( V_150 -> V_152 ) ) ;
}
F_49 ( V_59 ) ;
return 0 ;
}
int F_68 ( struct V_50 * V_51 , struct V_155 * V_156 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_157 ; V_6 ++ )
F_28 ( V_51 , L_52 , V_156 -> V_158 [ V_6 ] ) ;
F_28 ( V_51 , L_53 ) ;
return 0 ;
}
int F_69 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_77 * V_78 ;
unsigned int V_159 , V_160 ;
T_7 V_161 , V_162 ;
struct V_163 V_164 ;
int V_6 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
V_161 = F_70 () ;
F_71 ( & V_164 , V_161 - V_78 -> V_165 ) ;
F_28 ( V_51 , L_54 V_166 L_55 ,
L_56 , V_78 -> V_165 , F_72 ( & V_164 ) ) ;
V_159 = F_65 ( & V_78 -> V_137 . V_139 ) ;
V_160 = V_78 -> V_137 . V_139 . V_167 ;
V_162 = V_78 -> V_137 . V_139 . V_168 ;
F_71 ( & V_164 , V_161 - V_162 ) ;
F_28 ( V_51 , L_57 V_166 L_58 ,
L_59 , V_159 , V_160 , V_162 , F_72 ( & V_164 ) ) ;
F_68 ( V_51 , & V_78 -> V_137 . V_139 ) ;
for( V_6 = 0 ; V_6 < V_136 ; V_6 ++ ) {
if ( V_78 -> V_137 . V_138 [ V_6 ] == 0 )
break;
V_159 = F_65 ( & V_78 -> V_137 . V_169 [ V_6 ] ) ;
V_160 = V_78 -> V_137 . V_169 [ V_6 ] . V_167 ;
V_162 = V_78 -> V_137 . V_169 [ V_6 ] . V_168 ;
F_71 ( & V_164 , V_161 - V_162 ) ;
F_28 ( V_51 , L_60
V_166 L_58 , V_78 -> V_137 . V_138 [ V_6 ] ,
V_159 , V_160 , V_162 , F_72 ( & V_164 ) ) ;
F_68 ( V_51 , & V_78 -> V_137 . V_169 [ V_6 ] ) ;
}
F_49 ( V_59 ) ;
return 0 ;
}
int F_73 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
T_1 V_3 ;
F_46 ( V_59 ) ;
V_3 = V_59 -> V_80 . V_81 . V_82 -> V_117 . V_119 ;
F_28 ( V_51 , L_61 , V_3 ) ;
F_57 ( V_51 , V_3 , L_53 ) ;
F_28 ( V_51 , L_53 ) ;
F_49 ( V_59 ) ;
return 0 ;
}
int F_74 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
F_23 ( V_59 != NULL ) ;
return F_28 ( V_51 , L_7 , V_59 -> V_170 ) ;
}
int F_75 ( struct V_50 * V_51 , void * V_29 )
{
struct V_171 * V_172 = (struct V_171 * ) V_29 ;
F_23 ( V_172 != NULL ) ;
return F_28 ( V_51 , L_9 , V_172 -> V_173 ) ;
}
int F_76 ( struct V_58 * V_59 , struct V_43 * V_44 )
{
int V_49 = 0 ;
F_23 ( V_59 != NULL ) ;
F_23 ( V_59 -> V_174 == V_175 ) ;
F_23 ( V_59 -> V_171 -> V_176 != NULL ) ;
V_59 -> V_177 = F_25 ( V_59 -> V_63 ,
V_59 -> V_171 -> V_176 ,
V_44 , V_59 ) ;
if ( F_77 ( V_59 -> V_177 ) ) {
V_49 = F_78 ( V_59 -> V_177 ) ;
F_14 ( L_62 , V_49 , V_59 -> V_63 ) ;
V_59 -> V_177 = NULL ;
}
return V_49 ;
}
int F_79 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return - V_15 ;
if ( V_59 -> V_178 ) {
F_20 ( & V_59 -> V_178 ) ;
V_59 -> V_178 = NULL ;
}
if ( V_59 -> V_177 ) {
F_20 ( & V_59 -> V_177 ) ;
V_59 -> V_177 = NULL ;
}
return 0 ;
}
static void F_80 ( struct V_179 * V_180 )
{
F_81 ( V_181 , L_63 , V_180 ,
V_180 -> V_182 , V_180 -> V_183 ) ;
F_82 ( F_32 ( & V_180 -> V_184 ) == 0 ,
L_64 , F_61 ( V_180 -> V_123 ) ,
F_32 ( & V_180 -> V_184 ) ) ;
if ( V_180 -> V_182 )
F_20 ( & V_180 -> V_182 ) ;
if ( V_180 -> V_183 )
F_83 ( & V_180 -> V_183 ) ;
if ( V_180 -> V_185 )
F_83 ( & V_180 -> V_185 ) ;
F_84 ( V_180 ) ;
return;
}
void F_85 ( struct V_58 * V_59 )
{
struct V_186 * V_187 = V_59 -> V_188 ;
struct V_179 * V_189 ;
while ( ! F_86 ( & V_59 -> V_190 ) ) {
V_189 = F_87 ( V_59 -> V_190 . V_191 ,
struct V_179 , V_192 ) ;
F_88 ( & V_189 -> V_192 ) ;
F_89 ( V_187 , & V_189 -> V_123 , & V_189 -> V_193 ) ;
F_80 ( V_189 ) ;
}
}
struct V_89 * F_90 ( unsigned int V_194 ,
enum V_195 V_3 )
{
struct V_89 * V_90 ;
unsigned int V_94 ;
unsigned int V_196 = 0 ;
int V_6 ;
if ( V_194 == 0 )
return NULL ;
if ( V_197 != 0 )
V_3 |= V_198 ;
if ( V_3 & V_198 )
V_94 = 1 ;
else
V_94 = F_91 () ;
F_92 ( V_90 , F_93 ( F_94 ( * V_90 ) , V_100 [ V_94 ] ) ) ;
if ( V_90 == NULL )
return NULL ;
V_90 -> V_199 = V_194 ;
V_90 -> V_200 = V_3 ;
F_95 ( & V_90 -> V_201 ) ;
F_92 ( V_90 -> V_129 ,
V_90 -> V_199 * sizeof( struct V_111 ) ) ;
if ( V_90 -> V_129 == NULL )
goto V_202;
if ( ( V_3 & V_198 ) != 0 ) {
V_196 = F_96 ( V_90 ) ;
F_97 ( V_90 -> V_100 [ 0 ] , V_196 ) ;
if ( V_90 -> V_100 [ 0 ] == NULL )
goto V_202;
V_90 -> V_203 = 1 ;
} else if ( ( V_3 & V_204 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_94 ; ++ V_6 )
if ( F_98 ( V_90 , V_6 ) < 0 )
goto V_202;
}
return V_90 ;
V_202:
F_83 ( & V_90 ) ;
return NULL ;
}
void F_83 ( struct V_89 * * V_205 )
{
struct V_89 * V_90 = * V_205 ;
unsigned int V_94 ;
unsigned int V_196 ;
unsigned int V_6 ;
if ( V_90 == NULL || V_90 -> V_199 == 0 )
return;
* V_205 = NULL ;
if ( V_90 -> V_200 & V_198 )
V_94 = 1 ;
else
V_94 = F_91 () ;
V_196 = F_96 ( V_90 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ )
if ( V_90 -> V_100 [ V_6 ] != NULL )
F_99 ( V_90 -> V_100 [ V_6 ] , V_196 ) ;
if ( V_90 -> V_129 != NULL )
F_99 ( V_90 -> V_129 , V_90 -> V_199 *
sizeof( struct V_111 ) ) ;
F_99 ( V_90 , F_93 ( F_94 ( * V_90 ) , V_100 [ V_94 ] ) ) ;
}
void F_100 ( struct V_89 * V_90 )
{
struct V_92 * V_95 ;
int V_6 ;
int V_114 ;
unsigned int V_94 ;
unsigned long V_3 = 0 ;
V_94 = F_52 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
for ( V_114 = 0 ; V_114 < V_90 -> V_199 ; V_114 ++ ) {
V_95 = F_53 ( V_90 , V_6 , V_114 ) ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_98 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 0 ;
V_95 -> V_101 = 0 ;
if ( V_90 -> V_200 & V_204 )
V_95 -> V_206 = 0 ;
}
}
F_54 ( V_90 , V_99 , & V_3 ) ;
}
static T_8 F_101 ( struct V_25 * V_25 ,
const char T_4 * V_207 ,
T_9 V_208 , T_10 * V_209 )
{
struct V_50 * V_210 = V_25 -> V_211 ;
struct V_89 * V_90 = V_210 -> V_212 ;
F_100 ( V_90 ) ;
return V_208 ;
}
static void * F_102 ( struct V_50 * V_52 , T_10 * V_213 )
{
struct V_89 * V_90 = V_52 -> V_212 ;
return ( * V_213 < V_90 -> V_199 ) ? V_213 : NULL ;
}
static void F_103 ( struct V_50 * V_52 , void * V_214 )
{
}
static void * F_104 ( struct V_50 * V_52 , void * V_214 , T_10 * V_213 )
{
( * V_213 ) ++ ;
return F_102 ( V_52 , V_213 ) ;
}
static int F_105 ( struct V_50 * V_52 , void * V_214 )
{
struct V_89 * V_90 = V_52 -> V_212 ;
struct V_111 * V_215 ;
struct V_92 V_216 ;
int V_91 = * ( T_10 * ) V_214 ;
int V_49 = 0 ;
if ( V_91 == 0 ) {
struct V_217 V_161 ;
F_106 ( & V_161 ) ;
V_49 = F_28 ( V_52 , L_65 ,
L_66 , V_161 . V_218 , ( unsigned long ) V_161 . V_219 ) ;
if ( V_49 < 0 )
return V_49 ;
}
V_215 = & V_90 -> V_129 [ V_91 ] ;
F_51 ( V_90 , V_91 , & V_216 ) ;
if ( V_216 . V_96 == 0 )
goto V_48;
V_49 = F_28 ( V_52 , L_67 , V_215 -> V_220 ,
V_216 . V_96 , V_215 -> V_135 ) ;
if ( V_49 < 0 )
goto V_48;
if ( ( V_215 -> V_221 & V_222 ) && ( V_216 . V_96 > 0 ) ) {
V_49 = F_28 ( V_52 , L_68 ,
V_216 . V_97 , V_216 . V_102 , V_216 . V_101 ) ;
if ( V_49 < 0 )
goto V_48;
if ( V_215 -> V_221 & V_223 )
V_49 = F_28 ( V_52 , L_69 , V_216 . V_103 ) ;
if ( V_49 < 0 )
goto V_48;
}
V_49 = F_28 ( V_52 , L_53 ) ;
V_48:
return ( V_49 < 0 ) ? V_49 : 0 ;
}
static int F_107 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_50 * V_210 ;
int V_49 ;
V_49 = F_108 ( V_25 , & V_224 ) ;
if ( V_49 )
return V_49 ;
V_210 = V_25 -> V_211 ;
V_210 -> V_212 = F_109 ( V_24 ) ;
return 0 ;
}
int F_110 ( struct V_26 * V_27 , const char * V_28 ,
struct V_89 * V_90 )
{
struct V_26 * V_39 ;
F_23 ( V_27 != NULL ) ;
V_39 = F_13 ( V_28 , 0644 , V_27 ,
& V_225 , V_90 ) ;
if ( V_39 == NULL )
return - V_36 ;
return 0 ;
}
void F_111 ( struct V_89 * V_90 , int V_226 ,
unsigned V_227 , const char * V_28 , const char * V_228 )
{
struct V_111 * V_112 ;
struct V_92 * V_95 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_229 ;
F_23 ( V_90 != NULL ) ;
V_112 = & V_90 -> V_129 [ V_226 ] ;
F_82 ( V_112 != NULL , L_70 ,
V_226 , V_28 , V_228 ) ;
V_112 -> V_221 = V_227 ;
V_112 -> V_220 = V_28 ;
V_112 -> V_135 = V_228 ;
V_229 = F_52 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_229 ; ++ V_6 ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
V_95 = F_53 ( V_90 , V_6 , V_226 ) ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_98 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 0 ;
V_95 -> V_101 = 0 ;
if ( ( V_90 -> V_200 & V_204 ) != 0 )
V_95 -> V_206 = 0 ;
}
F_54 ( V_90 , V_99 , & V_3 ) ;
}
void F_112 ( int V_230 , struct V_89 * V_90 )
{
F_113 ( V_230 , V_90 , V_231 ) ;
F_113 ( V_230 , V_90 , V_232 ) ;
F_113 ( V_230 , V_90 , V_233 ) ;
F_113 ( V_230 , V_90 , V_234 ) ;
F_113 ( V_230 , V_90 , V_235 ) ;
F_113 ( V_230 , V_90 , V_236 ) ;
F_113 ( V_230 , V_90 , V_237 ) ;
F_113 ( V_230 , V_90 , V_238 ) ;
F_113 ( V_230 , V_90 , V_239 ) ;
F_113 ( V_230 , V_90 , V_240 ) ;
F_113 ( V_230 , V_90 , V_241 ) ;
F_113 ( V_230 , V_90 , V_242 ) ;
F_113 ( V_230 , V_90 , V_243 ) ;
F_113 ( V_230 , V_90 , V_244 ) ;
F_113 ( V_230 , V_90 , V_245 ) ;
F_113 ( V_230 , V_90 , V_246 ) ;
F_113 ( V_230 , V_90 , V_247 ) ;
F_113 ( V_230 , V_90 , V_248 ) ;
F_113 ( V_230 , V_90 , V_249 ) ;
F_113 ( V_230 , V_90 , V_250 ) ;
F_113 ( V_230 , V_90 , V_251 ) ;
F_113 ( V_230 , V_90 , V_252 ) ;
F_113 ( V_230 , V_90 , V_253 ) ;
F_113 ( V_230 , V_90 , V_254 ) ;
F_113 ( V_230 , V_90 , V_255 ) ;
F_113 ( V_230 , V_90 , V_256 ) ;
F_113 ( V_230 , V_90 , V_257 ) ;
F_113 ( V_230 , V_90 , V_258 ) ;
F_113 ( V_230 , V_90 , V_259 ) ;
F_113 ( V_230 , V_90 , V_260 ) ;
F_113 ( V_230 , V_90 , V_261 ) ;
F_113 ( V_230 , V_90 , V_262 ) ;
F_113 ( V_230 , V_90 , V_263 ) ;
F_113 ( V_230 , V_90 , V_264 ) ;
F_113 ( V_230 , V_90 , V_265 ) ;
F_113 ( V_230 , V_90 , V_266 ) ;
F_113 ( V_230 , V_90 , V_267 ) ;
F_113 ( V_230 , V_90 , V_268 ) ;
F_113 ( V_230 , V_90 , V_269 ) ;
F_113 ( V_230 , V_90 , V_270 ) ;
F_113 ( V_230 , V_90 , V_271 ) ;
F_113 ( V_230 , V_90 , V_272 ) ;
F_113 ( V_230 , V_90 , V_273 ) ;
F_113 ( V_230 , V_90 , V_274 ) ;
F_113 ( V_230 , V_90 , V_275 ) ;
F_113 ( V_230 , V_90 , V_276 ) ;
F_113 ( V_230 , V_90 , V_277 ) ;
F_113 ( V_230 , V_90 , V_278 ) ;
F_113 ( V_230 , V_90 , V_279 ) ;
F_113 ( V_230 , V_90 , V_280 ) ;
F_113 ( V_230 , V_90 , V_281 ) ;
F_113 ( V_230 , V_90 , V_282 ) ;
F_113 ( V_230 , V_90 , V_283 ) ;
F_113 ( V_230 , V_90 , V_284 ) ;
F_113 ( V_230 , V_90 , V_285 ) ;
F_113 ( V_230 , V_90 , V_286 ) ;
F_113 ( V_230 , V_90 , V_287 ) ;
F_113 ( V_230 , V_90 , V_288 ) ;
F_113 ( V_230 , V_90 , V_289 ) ;
F_113 ( V_230 , V_90 , V_290 ) ;
F_113 ( V_230 , V_90 , V_291 ) ;
F_113 ( V_230 , V_90 , V_292 ) ;
F_113 ( V_230 , V_90 , V_293 ) ;
F_113 ( V_230 , V_90 , V_294 ) ;
F_113 ( V_230 , V_90 , V_295 ) ;
F_113 ( V_230 , V_90 , V_296 ) ;
F_113 ( V_230 , V_90 , V_297 ) ;
}
int F_114 ( struct V_58 * V_59 , unsigned V_230 )
{
struct V_89 * V_90 ;
unsigned int V_298 ;
int V_49 , V_6 ;
F_23 ( V_59 -> V_299 == NULL ) ;
F_23 ( V_59 -> V_177 != NULL ) ;
F_23 ( V_59 -> V_300 == 0 ) ;
V_298 = ( ( int ) sizeof( * V_59 -> V_171 -> V_301 ) / sizeof( void * ) ) +
V_230 - 1 ;
V_90 = F_90 ( V_298 , 0 ) ;
if ( V_90 == NULL )
return - V_36 ;
F_112 ( V_230 , V_90 ) ;
for ( V_6 = V_230 ; V_6 < V_298 ; V_6 ++ ) {
F_82 ( V_90 -> V_129 [ V_6 ] . V_220 != NULL ,
L_71
L_72 , V_6 - V_230 ) ;
}
V_49 = F_110 ( V_59 -> V_177 , L_73 , V_90 ) ;
if ( V_49 < 0 ) {
F_83 ( & V_90 ) ;
} else {
V_59 -> V_299 = V_90 ;
V_59 -> V_300 = V_230 ;
}
return V_49 ;
}
void F_115 ( struct V_58 * V_59 )
{
if ( V_59 -> V_299 )
F_83 ( & V_59 -> V_299 ) ;
}
void F_116 ( int V_230 , struct V_89 * V_90 )
{
F_117 ( V_230 , V_90 , V_302 ) ;
F_117 ( V_230 , V_90 , V_303 ) ;
F_117 ( V_230 , V_90 , V_274 ) ;
F_117 ( V_230 , V_90 , V_304 ) ;
F_117 ( V_230 , V_90 , V_255 ) ;
F_117 ( V_230 , V_90 , V_305 ) ;
F_117 ( V_230 , V_90 , V_272 ) ;
F_117 ( V_230 , V_90 , V_260 ) ;
F_117 ( V_230 , V_90 , V_306 ) ;
F_117 ( V_230 , V_90 , V_307 ) ;
F_117 ( V_230 , V_90 , V_308 ) ;
F_117 ( V_230 , V_90 , rename ) ;
F_117 ( V_230 , V_90 , V_309 ) ;
F_117 ( V_230 , V_90 , V_258 ) ;
F_117 ( V_230 , V_90 , V_266 ) ;
F_117 ( V_230 , V_90 , V_310 ) ;
F_117 ( V_230 , V_90 , V_311 ) ;
F_117 ( V_230 , V_90 , V_312 ) ;
F_117 ( V_230 , V_90 , V_313 ) ;
F_117 ( V_230 , V_90 , V_314 ) ;
F_117 ( V_230 , V_90 , V_315 ) ;
F_117 ( V_230 , V_90 , V_316 ) ;
F_117 ( V_230 , V_90 , V_317 ) ;
F_117 ( V_230 , V_90 , V_318 ) ;
F_117 ( V_230 , V_90 , V_319 ) ;
F_117 ( V_230 , V_90 , V_320 ) ;
F_117 ( V_230 , V_90 , V_276 ) ;
F_117 ( V_230 , V_90 , V_321 ) ;
F_117 ( V_230 , V_90 , V_322 ) ;
F_117 ( V_230 , V_90 , V_323 ) ;
F_117 ( V_230 , V_90 , V_324 ) ;
F_117 ( V_230 , V_90 , V_325 ) ;
}
int F_118 ( struct V_58 * V_59 ,
unsigned V_230 )
{
struct V_89 * V_90 ;
unsigned int V_298 ;
int V_49 , V_6 ;
F_23 ( V_59 -> V_326 == NULL ) ;
F_23 ( V_59 -> V_177 != NULL ) ;
F_23 ( V_59 -> V_327 == 0 ) ;
V_298 = 1 + F_119 ( V_325 ) +
V_230 ;
V_90 = F_90 ( V_298 , 0 ) ;
if ( V_90 == NULL )
return - V_36 ;
F_116 ( V_230 , V_90 ) ;
for ( V_6 = V_230 ; V_6 < V_298 ; V_6 ++ ) {
if ( V_90 -> V_129 [ V_6 ] . V_220 == NULL ) {
F_14 ( L_74
L_75 ,
V_6 - V_230 ) ;
F_120 () ;
}
}
V_49 = F_110 ( V_59 -> V_177 , L_76 , V_90 ) ;
if ( V_49 < 0 ) {
F_83 ( & V_90 ) ;
} else {
V_59 -> V_326 = V_90 ;
V_59 -> V_327 = V_230 ;
}
return V_49 ;
}
void F_121 ( struct V_58 * V_59 )
{
struct V_89 * V_90 = V_59 -> V_326 ;
if ( V_90 != NULL ) {
V_59 -> V_326 = NULL ;
V_59 -> V_327 = 0 ;
F_83 ( & V_90 ) ;
}
}
void F_122 ( struct V_89 * V_328 )
{
F_111 ( V_328 ,
V_329 - V_330 ,
0 , L_77 , L_78 ) ;
F_111 ( V_328 ,
V_331 - V_330 ,
0 , L_79 , L_78 ) ;
F_111 ( V_328 ,
V_332 - V_330 ,
0 , L_80 , L_78 ) ;
F_111 ( V_328 ,
V_333 - V_330 ,
0 , L_81 , L_78 ) ;
F_111 ( V_328 ,
V_334 - V_330 ,
0 , L_82 , L_78 ) ;
F_111 ( V_328 ,
V_335 - V_330 ,
0 , L_83 , L_78 ) ;
}
int F_123 ( struct V_186 * V_336 , struct V_337 * V_338 ,
struct V_339 * V_340 , void * V_29 )
{
struct V_341 * exp = F_124 ( V_336 , V_340 ) ;
struct V_50 * V_51 = (struct V_50 * ) V_29 ;
if ( exp -> V_342 )
F_28 ( V_51 , L_10 , F_125 ( & exp -> V_343 ) ) ;
return 0 ;
}
static int
F_126 ( struct V_50 * V_51 , void * V_344 )
{
struct V_179 * V_90 = (struct V_179 * ) V_51 -> V_212 ;
struct V_58 * V_59 = V_90 -> V_345 ;
F_127 ( V_59 -> V_346 , & V_90 -> V_123 ,
F_123 , V_51 ) ;
return 0 ;
}
int F_128 ( struct V_186 * V_336 , struct V_337 * V_338 ,
struct V_339 * V_340 , void * V_347 )
{
struct V_348 * V_29 = (struct V_348 * ) V_347 ;
struct V_341 * exp = F_124 ( V_336 , V_340 ) ;
if ( exp -> V_349 != NULL ) {
if ( V_29 -> V_104 ) {
F_129 ( V_29 -> V_51 ) ;
V_29 -> V_104 = false ;
}
F_130 ( V_336 , V_29 -> V_51 ) ;
}
return 0 ;
}
static int
F_131 ( struct V_50 * V_51 , void * V_344 )
{
struct V_179 * V_90 = (struct V_179 * ) V_51 -> V_212 ;
struct V_58 * V_59 = V_90 -> V_345 ;
struct V_348 V_347 = { V_51 , true } ;
F_127 ( V_59 -> V_346 , & V_90 -> V_123 ,
F_128 , & V_347 ) ;
return 0 ;
}
int F_132 ( struct V_50 * V_51 , void * V_29 )
{
return F_28 ( V_51 , L_10 ,
L_84
L_85 ) ;
}
static int F_133 ( void * V_350 , void * V_29 )
{
struct V_179 * V_189 = V_350 ;
F_81 ( V_351 , L_86 , F_32 ( & V_189 -> V_184 ) ) ;
if ( F_32 ( & V_189 -> V_184 ) == 1 ) {
F_59 ( & V_189 -> V_345 -> V_352 ) ;
F_134 ( & V_189 -> V_192 , V_29 ) ;
F_62 ( & V_189 -> V_345 -> V_352 ) ;
return 1 ;
}
if ( V_189 -> V_183 )
F_100 ( V_189 -> V_183 ) ;
return 0 ;
}
int F_135 ( struct V_25 * V_25 , const char * V_9 ,
unsigned long V_2 , void * V_29 )
{
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_179 * V_180 ;
F_136 ( V_353 ) ;
F_137 ( V_59 -> V_188 ,
F_133 , & V_353 ) ;
while ( ! F_86 ( & V_353 ) ) {
V_180 = F_87 ( V_353 . V_191 , struct V_179 ,
V_192 ) ;
F_88 ( & V_180 -> V_192 ) ;
F_80 ( V_180 ) ;
}
return V_2 ;
}
int F_138 ( struct V_341 * exp , T_11 * V_123 , int * V_354 )
{
struct V_179 * V_355 , * V_356 ;
struct V_58 * V_59 = NULL ;
struct V_26 * V_39 ;
char * V_9 = NULL ;
int V_49 = 0 ;
* V_354 = 0 ;
if ( ! exp || ! exp -> V_357 || ! exp -> V_357 -> V_178 ||
! exp -> V_357 -> V_188 )
return - V_15 ;
if ( ! V_123 || * V_123 == V_358 )
return 0 ;
V_59 = exp -> V_357 ;
F_81 ( V_181 , L_87 , V_59 -> V_188 ) ;
F_139 ( V_355 ) ;
if ( V_355 == NULL )
return - V_36 ;
V_355 -> V_123 = * V_123 ;
V_355 -> V_345 = exp -> V_357 ;
F_35 ( & V_355 -> V_184 , 1 ) ;
V_356 = F_140 ( V_59 -> V_188 ,
V_123 , & V_355 -> V_193 ) ;
F_81 ( V_351 , L_88 ,
V_356 , F_61 ( * V_123 ) ,
F_32 ( & V_355 -> V_184 ) ) ;
if ( exp -> V_342 ) {
F_141 ( exp -> V_342 ) ;
exp -> V_342 = NULL ;
}
if ( V_356 != V_355 ) {
exp -> V_342 = V_356 ;
GOTO ( V_359 , V_49 = - V_360 ) ;
}
F_142 ( V_9 , V_361 ) ;
if ( V_9 == NULL )
GOTO ( V_359 , V_49 = - V_36 ) ;
memcpy ( V_9 , F_61 ( * V_123 ) , V_361 ) ;
V_355 -> V_182 = F_25 ( V_9 ,
V_59 -> V_178 ,
NULL , NULL ) ;
F_18 ( V_9 , V_361 ) ;
if ( F_77 ( V_355 -> V_182 ) ) {
F_14 ( L_89 ,
F_61 ( * V_123 ) ) ;
V_49 = F_78 ( V_355 -> V_182 ) ;
V_355 -> V_182 = NULL ;
GOTO ( V_362 , V_49 ) ;
}
V_39 = F_11 ( V_355 -> V_182 , L_90 ,
V_355 , & V_363 ) ;
if ( F_77 ( V_39 ) ) {
F_143 ( L_91 ) ;
V_49 = F_78 ( V_39 ) ;
GOTO ( V_362 , V_49 ) ;
}
V_39 = F_11 ( V_355 -> V_182 , L_92 ,
V_355 , & V_364 ) ;
if ( F_77 ( V_39 ) ) {
F_143 ( L_93 ) ;
V_49 = F_78 ( V_39 ) ;
GOTO ( V_362 , V_49 ) ;
}
exp -> V_342 = V_355 ;
* V_354 = 1 ;
F_59 ( & V_59 -> V_352 ) ;
F_144 ( & V_355 -> V_192 , & V_59 -> V_190 ) ;
F_62 ( & V_59 -> V_352 ) ;
return V_49 ;
V_362:
if ( V_355 -> V_182 != NULL )
F_20 ( & V_355 -> V_182 ) ;
F_89 ( V_59 -> V_188 , V_123 , & V_355 -> V_193 ) ;
V_359:
F_141 ( V_355 ) ;
F_84 ( V_355 ) ;
return V_49 ;
}
int F_145 ( struct V_341 * exp )
{
struct V_179 * V_189 = exp -> V_342 ;
if( ! V_189 || ! exp -> V_357 )
return 0 ;
F_141 ( exp -> V_342 ) ;
exp -> V_342 = NULL ;
return 0 ;
}
int F_34 ( const char * V_9 , unsigned long V_2 ,
int * V_10 )
{
return F_4 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_146 ( struct V_50 * V_51 , long V_10 , int V_11 )
{
long V_12 , V_13 ;
V_12 = V_10 / V_11 ;
F_28 ( V_51 , L_4 , V_12 ) ;
V_13 = V_10 % V_11 ;
if ( V_13 > 0 ) {
V_13 *= 100 ;
V_13 /= V_11 ;
}
if ( V_13 > 0 ) {
if ( ( V_13 % 10 ) != 0 )
F_28 ( V_51 , L_94 , V_13 ) ;
else
F_28 ( V_51 , L_94 , V_13 / 10 ) ;
}
F_28 ( V_51 , L_53 ) ;
return 0 ;
}
int F_147 ( const char * V_9 , unsigned long V_2 , T_1 * V_10 )
{
return F_148 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_148 ( const char * V_9 , unsigned long V_2 ,
T_1 * V_10 , int V_11 )
{
char V_19 [ 22 ] , * V_20 , * V_21 ;
T_1 V_365 , V_366 = 0 , V_228 ;
unsigned V_367 = 1 ;
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
V_365 = F_149 ( V_21 , & V_20 , 10 ) ;
if ( V_21 == V_20 )
return - V_15 ;
if ( V_20 != NULL && * V_20 == '.' ) {
int V_6 ;
V_21 = V_20 + 1 ;
if ( strlen ( V_21 ) > 10 )
V_21 [ 10 ] = '\0' ;
V_366 = F_149 ( V_21 , & V_20 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_20 - V_21 ) ; V_6 ++ )
V_367 *= 10 ;
}
V_228 = 1 ;
switch( * V_20 ) {
case 'p' : case 'P' :
V_228 <<= 10 ;
case 't' : case 'T' :
V_228 <<= 10 ;
case 'g' : case 'G' :
V_228 <<= 10 ;
case 'm' : case 'M' :
V_228 <<= 10 ;
case 'k' : case 'K' :
V_228 <<= 10 ;
}
if ( V_228 )
V_11 = V_11 < 0 ? - V_228 : V_228 ;
V_366 *= V_11 ;
F_63 ( V_366 , V_367 ) ;
* V_10 = V_365 * V_11 + V_366 ;
return 0 ;
}
static char * F_150 ( const char * V_368 , const char * V_369 , T_9 V_208 )
{
T_9 V_370 ;
V_370 = strlen ( V_369 ) ;
if ( ! V_370 )
return ( char * ) V_368 ;
while ( V_208 >= V_370 ) {
V_208 -- ;
if ( ! memcmp ( V_368 , V_369 , V_370 ) )
return ( char * ) V_368 ;
V_368 ++ ;
}
return NULL ;
}
char * F_151 ( const char * V_9 , const char * V_28 ,
T_9 * V_2 )
{
char * V_10 ;
T_9 V_371 = * V_2 ;
V_10 = F_150 ( V_9 , V_28 , V_371 ) ;
if ( V_10 == NULL )
return ( char * ) V_9 ;
V_10 += strlen ( V_28 ) ;
while ( V_10 < V_9 + V_371 && isspace ( * V_10 ) )
V_10 ++ ;
* V_2 = 0 ;
while ( V_10 < V_9 + V_371 && isalnum ( * V_10 ) ) {
++ * V_2 ;
++ V_10 ;
}
return V_10 - * V_2 ;
}
int F_152 ( struct V_26 * V_37 ,
const char * V_28 ,
T_2 V_33 ,
const struct V_30 * V_372 ,
void * V_29 )
{
struct V_26 * V_39 ;
F_23 ( ( V_372 -> V_35 == NULL ) == ( ( V_33 & 0222 ) == 0 ) ) ;
V_39 = F_13 ( V_28 , V_33 , V_37 , V_372 , V_29 ) ;
if ( V_39 == NULL )
return - V_36 ;
return 0 ;
}
int F_153 ( struct V_58 * V_62 ,
const char * V_28 ,
T_2 V_33 ,
const struct V_30 * V_372 ,
void * V_29 )
{
return ( F_152 ( V_62 -> V_177 , V_28 ,
V_33 , V_372 , V_29 ) ) ;
}
void F_154 ( struct V_373 * V_374 , unsigned int V_375 )
{
if ( V_375 >= V_376 )
V_375 = V_376 - 1 ;
F_59 ( & V_374 -> V_377 ) ;
V_374 -> V_378 [ V_375 ] ++ ;
F_62 ( & V_374 -> V_377 ) ;
}
void F_155 ( struct V_373 * V_374 , unsigned int V_375 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; ( ( 1 << V_10 ) < V_375 ) && ( V_10 <= V_376 ) ; V_10 ++ )
;
F_154 ( V_374 , V_10 ) ;
}
unsigned long F_156 ( struct V_373 * V_374 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_376 ; V_6 ++ )
V_7 += V_374 -> V_378 [ V_6 ] ;
return V_7 ;
}
void F_157 ( struct V_373 * V_374 )
{
F_59 ( & V_374 -> V_377 ) ;
memset ( V_374 -> V_378 , 0 , sizeof( V_374 -> V_378 ) ) ;
F_62 ( & V_374 -> V_377 ) ;
}
int F_158 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_62 = V_29 ;
struct V_379 * V_81 = & V_62 -> V_80 . V_81 ;
int V_49 ;
F_159 ( & V_81 -> V_380 ) ;
V_49 = F_28 ( V_51 , L_9 , V_81 -> V_381 ) ;
F_160 ( & V_81 -> V_380 ) ;
return V_49 ;
}
