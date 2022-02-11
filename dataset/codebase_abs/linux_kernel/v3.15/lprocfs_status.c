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
L_3 V_9 ,
V_7 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
return V_7 ;
}
int F_2 ( char * V_10 , unsigned long V_2 , long V_11 ,
int V_12 )
{
long V_13 , V_14 ;
int V_15 ;
if ( V_2 < 10 )
return - V_16 ;
V_13 = V_11 / V_12 ;
V_15 = snprintf ( V_10 , V_2 , L_4 , V_13 ) ;
V_14 = V_11 % V_12 ;
if ( V_15 < ( V_2 - 4 ) && V_14 > 0 ) {
long V_17 ;
int V_6 , V_18 = 1 , V_19 = 0 ;
V_17 = V_14 * 10 ;
V_10 [ V_15 ++ ] = '.' ;
while ( V_19 < 2 && ( V_17 / V_12 ) < 1 ) {
V_10 [ V_15 ++ ] = '0' ;
V_17 *= 10 ;
V_19 ++ ;
}
for ( V_6 = 0 ; V_6 < ( 5 - V_15 ) ; V_6 ++ )
V_18 *= 10 ;
V_19 = F_3 ( ( int ) V_2 - V_15 , 3 - V_19 ) ;
V_15 += snprintf ( V_10 + V_15 , V_19 , L_4 ,
V_14 * V_18 / V_12 ) ;
V_15 -- ;
while ( V_10 [ V_15 ] < '1' || V_10 [ V_15 ] > '9' ) {
V_15 -- ;
if ( V_10 [ V_15 ] == '.' ) {
V_15 -- ;
break;
}
}
V_15 ++ ;
}
V_10 [ V_15 ++ ] = '\n' ;
return V_15 ;
}
int F_4 ( const char * V_10 , unsigned long V_2 ,
int * V_11 , int V_12 )
{
char V_20 [ 20 ] , * V_21 , * V_22 ;
if ( V_2 > ( sizeof( V_20 ) - 1 ) )
return - V_16 ;
if ( F_5 ( V_20 , V_10 , V_2 ) )
return - V_23 ;
V_20 [ V_2 ] = '\0' ;
V_22 = V_20 ;
if ( * V_22 == '-' ) {
V_12 = - V_12 ;
V_22 ++ ;
}
* V_11 = ( int ) F_6 ( V_22 , & V_21 , 10 ) * V_12 ;
if ( V_22 == V_21 )
return - V_16 ;
if ( V_21 != NULL && * V_21 == '.' ) {
int V_24 , pow = 1 ;
int V_6 ;
V_22 = V_21 + 1 ;
if ( strlen ( V_22 ) > 5 )
V_22 [ 5 ] = '\0' ;
V_24 = ( int ) F_6 ( V_22 , & V_21 , 10 ) * V_12 ;
if ( V_22 < V_21 ) {
for ( V_6 = 0 ; V_6 < ( V_21 - V_22 ) ; V_6 ++ )
pow *= 10 ;
* V_11 += V_24 / pow ;
}
}
return 0 ;
}
int F_7 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_8 ( V_25 , V_26 ) ;
}
int F_9 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_10 ( V_25 , V_26 ) ;
}
struct V_27 * F_11 ( struct V_27 * V_28 ,
char * V_29 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_27 * V_33 ;
T_2 V_34 = 0 ;
if ( V_28 == NULL || V_29 == NULL || V_32 == NULL )
return F_12 ( - V_16 ) ;
if ( V_32 -> V_35 )
V_34 = 0444 ;
if ( V_32 -> V_36 )
V_34 |= 0200 ;
V_33 = F_13 ( V_29 , V_34 , V_28 , V_32 , V_30 ) ;
if ( ! V_33 ) {
F_14 ( L_5 , V_29 ) ;
return F_12 ( - V_37 ) ;
}
return V_33 ;
}
struct V_27 * F_15 ( const char * V_29 ,
struct V_27 * V_38 , const char * V_39 , ... )
{
struct V_27 * V_40 ;
char * V_41 ;
T_3 V_42 ;
if ( V_38 == NULL || V_39 == NULL )
return NULL ;
F_16 ( V_41 , V_43 + 1 ) ;
if ( V_41 == NULL )
return NULL ;
va_start ( V_42 , V_39 ) ;
vsnprintf ( V_41 , V_43 , V_39 , V_42 ) ;
va_end ( V_42 ) ;
V_40 = F_17 ( V_29 , V_38 , V_41 ) ;
if ( V_40 == NULL )
F_14 ( L_6 ,
V_29 , V_41 ) ;
F_18 ( V_41 , V_43 + 1 ) ;
return V_40 ;
}
int F_19 ( struct V_27 * V_28 , struct V_44 * V_45 ,
void * V_30 )
{
if ( V_28 == NULL || V_45 == NULL )
return - V_16 ;
while ( V_45 -> V_29 != NULL ) {
struct V_27 * V_33 ;
T_2 V_34 = 0 ;
if ( V_45 -> V_46 != 0000 ) {
V_34 = V_45 -> V_46 ;
} else if ( V_45 -> V_32 ) {
if ( V_45 -> V_32 -> V_35 )
V_34 = 0444 ;
if ( V_45 -> V_32 -> V_36 )
V_34 |= 0200 ;
}
V_33 = F_13 ( V_45 -> V_29 , V_34 , V_28 ,
V_45 -> V_32 ? : & V_47 ,
V_45 -> V_30 ? : V_30 ) ;
if ( V_33 == NULL )
return - V_37 ;
V_45 ++ ;
}
return 0 ;
}
void F_20 ( struct V_27 * * V_48 )
{
F_21 ( * V_48 ) ;
* V_48 = NULL ;
}
void F_22 ( const char * V_29 , struct V_27 * V_38 )
{
F_23 ( V_38 != NULL ) ;
F_24 ( V_29 , V_38 ) ;
}
struct V_27 * F_25 ( const char * V_29 ,
struct V_27 * V_38 ,
struct V_44 * V_45 , void * V_30 )
{
struct V_27 * V_40 ;
V_40 = F_26 ( V_29 , V_38 ) ;
if ( V_40 == NULL )
GOTO ( V_49 , V_40 = F_12 ( - V_37 ) ) ;
if ( V_45 != NULL ) {
int V_50 = F_19 ( V_40 , V_45 , V_30 ) ;
if ( V_50 != 0 ) {
F_20 ( & V_40 ) ;
V_40 = F_12 ( V_50 ) ;
}
}
V_49:
return V_40 ;
}
int F_27 ( struct V_51 * V_52 , void * V_30 )
{
return F_28 ( V_52 , L_7 , * ( unsigned int * ) V_30 ) ;
}
int F_29 ( struct V_26 * V_26 , const char T_4 * V_10 ,
unsigned long V_2 , void * V_30 )
{
unsigned * V_53 = V_30 ;
char V_54 [ V_43 + 1 ] , * V_21 ;
unsigned long V_55 ;
V_54 [ V_43 ] = '\0' ;
if ( F_5 ( V_54 , V_10 , V_43 ) )
return - V_23 ;
V_55 = F_6 ( V_54 , & V_21 , 0 ) ;
if ( V_54 == V_21 )
return - V_16 ;
* V_53 = ( unsigned int ) V_55 ;
return V_2 ;
}
int F_30 ( struct V_51 * V_52 , void * V_30 )
{
return F_28 ( V_52 , V_56 L_8 , * ( T_1 * ) V_30 ) ;
}
int F_31 ( struct V_51 * V_52 , void * V_30 )
{
T_5 * V_57 = V_30 ;
F_23 ( V_57 != NULL ) ;
return F_28 ( V_52 , L_9 , F_32 ( V_57 ) ) ;
}
int F_33 ( struct V_26 * V_26 , const char T_4 * V_10 ,
unsigned long V_2 , void * V_30 )
{
T_5 * V_58 = V_30 ;
int V_11 = 0 ;
int V_50 ;
V_50 = F_34 ( V_10 , V_2 , & V_11 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_11 <= 0 )
return - V_59 ;
F_35 ( V_58 , V_11 ) ;
return V_2 ;
}
int F_36 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
F_23 ( V_61 != NULL ) ;
return F_28 ( V_52 , L_10 , V_61 -> V_62 . V_63 ) ;
}
int F_37 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_64 = V_30 ;
F_23 ( V_64 != NULL ) ;
return F_28 ( V_52 , L_10 , V_64 -> V_65 ) ;
}
int F_38 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 )
V_50 = F_28 ( V_52 , L_7 , V_67 . V_71 ) ;
return V_50 ;
}
int F_40 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 ) {
T_6 V_72 = V_67 . V_71 >> 10 ;
T_1 V_73 = V_67 . V_74 ;
while ( V_72 >>= 1 )
V_73 <<= 1 ;
V_50 = F_28 ( V_52 , V_56 L_8 , V_73 ) ;
}
return V_50 ;
}
int F_41 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 ) {
T_6 V_72 = V_67 . V_71 >> 10 ;
T_1 V_73 = V_67 . V_75 ;
while ( V_72 >>= 1 )
V_73 <<= 1 ;
V_50 = F_28 ( V_52 , V_56 L_8 , V_73 ) ;
}
return V_50 ;
}
int F_42 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 ) {
T_6 V_72 = V_67 . V_71 >> 10 ;
T_1 V_73 = V_67 . V_76 ;
while ( V_72 >>= 1 )
V_73 <<= 1 ;
V_50 = F_28 ( V_52 , V_56 L_8 , V_73 ) ;
}
return V_50 ;
}
int F_43 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 )
V_50 = F_28 ( V_52 , V_56 L_8 , V_67 . V_77 ) ;
return V_50 ;
}
int F_44 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_66 V_67 ;
int V_50 = V_66 ( NULL , V_61 -> V_68 , & V_67 ,
F_39 ( - V_69 ) ,
V_70 ) ;
if ( ! V_50 )
V_50 = F_28 ( V_52 , V_56 L_8 , V_67 . V_78 ) ;
return V_50 ;
}
int F_45 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_79 * V_80 ;
char * V_81 = NULL ;
int V_50 = 0 ;
F_23 ( V_61 != NULL ) ;
F_46 ( V_61 ) ;
V_80 = V_61 -> V_82 . V_83 . V_84 ;
V_81 = F_47 ( V_80 -> V_85 ) ;
V_50 = F_28 ( V_52 , L_11 , F_48 ( V_61 ) , V_81 ,
V_80 -> V_86 ? L_12 : L_2 ) ;
F_49 ( V_61 ) ;
return V_50 ;
}
int F_50 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
struct V_87 * V_88 ;
int V_50 = 0 ;
F_23 ( V_61 != NULL ) ;
F_46 ( V_61 ) ;
V_88 = V_61 -> V_82 . V_83 . V_84 -> V_89 ;
if ( V_88 && V_61 -> V_82 . V_83 . V_84 )
V_50 = F_28 ( V_52 , L_10 , V_88 -> V_90 . V_63 ) ;
else
V_50 = F_28 ( V_52 , L_10 , L_13 ) ;
F_49 ( V_61 ) ;
return V_50 ;
}
void F_51 ( struct V_91 * V_92 , int V_93 ,
struct V_94 * V_95 )
{
unsigned int V_96 ;
struct V_94 * V_97 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
if ( V_92 == NULL ) {
V_95 -> V_98 = 1 ;
return;
}
V_95 -> V_99 = V_100 ;
V_96 = F_52 ( V_92 , V_101 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
if ( V_92 -> V_102 [ V_6 ] == NULL )
continue;
V_97 = F_53 ( V_92 , V_6 , V_93 ) ;
V_95 -> V_98 += V_97 -> V_98 ;
V_95 -> V_103 += V_97 -> V_103 ;
if ( V_97 -> V_99 < V_95 -> V_99 )
V_95 -> V_99 = V_97 -> V_99 ;
if ( V_97 -> V_104 > V_95 -> V_104 )
V_95 -> V_104 = V_97 -> V_104 ;
V_95 -> V_105 += V_97 -> V_105 ;
}
F_54 ( V_92 , V_101 , & V_3 ) ;
}
static int F_55 ( struct V_79 * V_80 , struct V_51 * V_52 )
{
bool V_106 = true ;
if ( V_80 -> V_107 -> V_108 ) {
F_28 ( V_52 , L_14 ) ;
V_106 = false ;
}
F_56 ( V_109 , V_106 ) ;
V_106 = false ;
F_56 ( V_110 , V_106 ) ;
F_56 ( V_111 , V_106 ) ;
F_56 ( V_112 , V_106 ) ;
return 0 ;
}
static void F_57 ( struct V_51 * V_52 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_106 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] != NULL ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_28 ( V_52 , L_1 ,
V_106 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_106 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_28 ( V_52 , L_3 V_9 ,
V_106 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_58 ( struct V_51 * V_52 , void * V_30 )
{
struct V_94 V_7 ;
struct V_113 * V_114 ;
struct V_60 * V_61 = (struct V_60 * ) V_30 ;
struct V_79 * V_80 ;
struct V_115 * V_88 ;
int V_116 ;
int V_117 ;
int V_118 = 0 ;
F_23 ( V_61 != NULL ) ;
F_46 ( V_61 ) ;
V_80 = V_61 -> V_82 . V_83 . V_84 ;
F_28 ( V_52 ,
L_15
L_16
L_17
L_18
L_19
L_20 ,
V_61 -> V_65 ,
F_48 ( V_61 ) ,
F_47 ( V_80 -> V_85 ) ,
V_80 -> V_119 . V_120 ) ;
F_57 ( V_52 , V_80 -> V_119 . V_121 , L_21 ) ;
F_28 ( V_52 ,
L_22
L_23 ) ;
F_55 ( V_80 , V_52 ) ;
F_28 ( V_52 ,
L_22
L_24
L_25 ) ;
F_59 ( & V_80 -> V_122 ) ;
V_116 = 0 ;
F_60 (conn, &imp->imp_conn_list, oic_item) {
F_28 ( V_52 , L_1 , V_116 ? L_21 : L_2 ,
F_61 ( V_88 -> V_123 -> V_124 . V_125 ) ) ;
V_116 ++ ;
}
F_28 ( V_52 ,
L_22
L_26
L_27
L_28
L_29 ,
V_80 -> V_89 == NULL ? L_13 :
F_61 ( V_80 -> V_89 -> V_124 . V_125 ) ,
V_80 -> V_126 ,
V_80 -> V_127 ,
F_32 ( & V_80 -> V_128 ) ) ;
F_62 ( & V_80 -> V_122 ) ;
if ( V_61 -> V_129 == NULL )
goto V_130;
V_114 = & V_61 -> V_129 -> V_131 [ V_132 ] ;
F_51 ( V_61 -> V_129 , V_132 , & V_7 ) ;
if ( V_7 . V_98 != 0 ) {
T_1 V_133 = V_7 . V_103 ;
F_63 ( V_133 , V_7 . V_98 ) ;
V_7 . V_103 = V_133 ;
} else
V_7 . V_103 = 0 ;
F_28 ( V_52 ,
L_30
L_31
L_32
L_33
L_34 V_56 L_35 ,
F_32 ( & V_80 -> V_134 ) ,
F_32 ( & V_80 -> V_135 ) ,
F_32 ( & V_80 -> V_136 ) ,
V_7 . V_103 , V_114 -> V_137 ) ;
V_117 = 0 ;
for( V_116 = 0 ; V_116 < V_138 ; V_116 ++ ) {
if ( V_80 -> V_139 . V_140 [ V_116 ] == 0 )
break;
V_117 = F_64 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_28 ( V_52 ,
L_36
L_37
L_38 ,
V_117 ,
F_65 ( & V_80 -> V_139 . V_141 ) ) ;
F_28 ( V_52 ,
L_39
L_40 V_56 L_8
L_41 V_56 L_8
L_42 V_56 L_8 ,
V_80 -> V_142 ,
V_80 -> V_143 ,
V_80 -> V_144 ) ;
for ( V_118 = 0 ; V_118 <= 1 ; V_118 ++ ) {
F_51 ( V_61 -> V_129 ,
V_145 + V_146 + V_118 ,
& V_7 ) ;
if ( V_7 . V_103 > 0 && V_7 . V_98 > 0 ) {
T_1 V_133 = V_7 . V_103 ;
F_63 ( V_133 , V_7 . V_98 ) ;
V_7 . V_103 = V_133 ;
F_28 ( V_52 ,
L_43
L_44 V_56 L_8 ,
V_118 ? L_45 : L_46 ,
V_7 . V_103 ) ;
}
V_117 = ( int ) V_7 . V_103 ;
V_116 = F_66 ( V_147 + V_118 ) + V_148 ;
V_114 = & V_61 -> V_129 -> V_131 [ V_116 ] ;
F_51 ( V_61 -> V_129 , V_116 , & V_7 ) ;
if ( V_7 . V_103 > 0 && V_7 . V_98 != 0 ) {
T_1 V_133 = V_7 . V_103 ;
F_63 ( V_133 , V_7 . V_98 ) ;
V_7 . V_103 = V_133 ;
F_28 ( V_52 ,
L_47 V_56 L_8 ,
V_114 -> V_137 , V_7 . V_103 ) ;
V_116 = ( int ) V_7 . V_103 ;
if ( V_116 > 0 )
F_28 ( V_52 ,
L_48 ,
V_117 / V_116 , ( 100 * V_117 / V_116 ) % 100 ) ;
}
}
V_130:
F_49 ( V_61 ) ;
return 0 ;
}
int F_67 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = (struct V_60 * ) V_30 ;
struct V_79 * V_80 ;
int V_116 , V_117 ;
F_23 ( V_61 != NULL ) ;
F_46 ( V_61 ) ;
V_80 = V_61 -> V_82 . V_83 . V_84 ;
F_28 ( V_52 , L_49 ,
F_47 ( V_80 -> V_85 ) ) ;
F_28 ( V_52 , L_50 ) ;
V_117 = V_80 -> V_149 ;
for ( V_116 = 0 ; V_116 < V_150 ; V_116 ++ ) {
struct V_151 * V_152 =
& V_80 -> V_153 [ ( V_117 + V_116 ) % V_150 ] ;
if ( V_152 -> V_154 == 0 )
continue;
F_28 ( V_52 , L_51 V_155 L_52 ,
V_152 -> V_156 ,
F_47 ( V_152 -> V_154 ) ) ;
}
F_49 ( V_61 ) ;
return 0 ;
}
int F_68 ( struct V_51 * V_52 , struct V_157 * V_158 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_159 ; V_6 ++ )
F_28 ( V_52 , L_53 , V_158 -> V_160 [ V_6 ] ) ;
F_28 ( V_52 , L_8 ) ;
return 0 ;
}
int F_69 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = (struct V_60 * ) V_30 ;
struct V_79 * V_80 ;
unsigned int V_161 , V_162 ;
T_7 V_163 , V_164 ;
struct V_165 V_166 ;
int V_6 ;
F_23 ( V_61 != NULL ) ;
F_46 ( V_61 ) ;
V_80 = V_61 -> V_82 . V_83 . V_84 ;
V_163 = F_70 () ;
F_71 ( & V_166 , V_163 - V_80 -> V_167 ) ;
F_28 ( V_52 , L_54 V_168 L_55 ,
L_56 , V_80 -> V_167 , F_72 ( & V_166 ) ) ;
V_161 = F_65 ( & V_80 -> V_139 . V_141 ) ;
V_162 = V_80 -> V_139 . V_141 . V_169 ;
V_164 = V_80 -> V_139 . V_141 . V_170 ;
F_71 ( & V_166 , V_163 - V_164 ) ;
F_28 ( V_52 , L_57 V_168 L_58 ,
L_59 , V_161 , V_162 , V_164 , F_72 ( & V_166 ) ) ;
F_68 ( V_52 , & V_80 -> V_139 . V_141 ) ;
for( V_6 = 0 ; V_6 < V_138 ; V_6 ++ ) {
if ( V_80 -> V_139 . V_140 [ V_6 ] == 0 )
break;
V_161 = F_65 ( & V_80 -> V_139 . V_171 [ V_6 ] ) ;
V_162 = V_80 -> V_139 . V_171 [ V_6 ] . V_169 ;
V_164 = V_80 -> V_139 . V_171 [ V_6 ] . V_170 ;
F_71 ( & V_166 , V_163 - V_164 ) ;
F_28 ( V_52 , L_60
V_168 L_58 , V_80 -> V_139 . V_140 [ V_6 ] ,
V_161 , V_162 , V_164 , F_72 ( & V_166 ) ) ;
F_68 ( V_52 , & V_80 -> V_139 . V_171 [ V_6 ] ) ;
}
F_49 ( V_61 ) ;
return 0 ;
}
int F_73 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
T_1 V_3 ;
F_46 ( V_61 ) ;
V_3 = V_61 -> V_82 . V_83 . V_84 -> V_119 . V_121 ;
F_28 ( V_52 , L_61 V_9 L_8 , V_3 ) ;
F_57 ( V_52 , V_3 , L_8 ) ;
F_28 ( V_52 , L_8 ) ;
F_49 ( V_61 ) ;
return 0 ;
}
int F_74 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_61 = V_30 ;
F_23 ( V_61 != NULL ) ;
return F_28 ( V_52 , L_7 , V_61 -> V_172 ) ;
}
int F_75 ( struct V_51 * V_52 , void * V_30 )
{
struct V_173 * V_174 = (struct V_173 * ) V_30 ;
F_23 ( V_174 != NULL ) ;
return F_28 ( V_52 , L_9 , V_174 -> V_175 ) ;
}
int F_76 ( struct V_60 * V_61 , struct V_44 * V_45 )
{
int V_50 = 0 ;
F_23 ( V_61 != NULL ) ;
F_23 ( V_61 -> V_176 == V_177 ) ;
F_23 ( V_61 -> V_173 -> V_178 != NULL ) ;
V_61 -> V_179 = F_25 ( V_61 -> V_65 ,
V_61 -> V_173 -> V_178 ,
V_45 , V_61 ) ;
if ( F_77 ( V_61 -> V_179 ) ) {
V_50 = F_78 ( V_61 -> V_179 ) ;
F_14 ( L_62 , V_50 , V_61 -> V_65 ) ;
V_61 -> V_179 = NULL ;
}
return V_50 ;
}
int F_79 ( struct V_60 * V_61 )
{
if ( ! V_61 )
return - V_16 ;
if ( V_61 -> V_180 ) {
F_20 ( & V_61 -> V_180 ) ;
V_61 -> V_180 = NULL ;
}
if ( V_61 -> V_179 ) {
F_20 ( & V_61 -> V_179 ) ;
V_61 -> V_179 = NULL ;
}
return 0 ;
}
static void F_80 ( struct V_181 * V_182 )
{
F_81 ( V_183 , L_63 , V_182 ,
V_182 -> V_184 , V_182 -> V_185 ) ;
F_82 ( F_32 ( & V_182 -> V_186 ) == 0 ,
L_64 , F_61 ( V_182 -> V_125 ) ,
F_32 ( & V_182 -> V_186 ) ) ;
if ( V_182 -> V_184 )
F_20 ( & V_182 -> V_184 ) ;
if ( V_182 -> V_185 )
F_83 ( & V_182 -> V_185 ) ;
if ( V_182 -> V_187 )
F_83 ( & V_182 -> V_187 ) ;
F_84 ( V_182 ) ;
return;
}
void F_85 ( struct V_60 * V_61 )
{
struct V_188 * V_189 = V_61 -> V_190 ;
struct V_181 * V_191 ;
while ( ! F_86 ( & V_61 -> V_192 ) ) {
V_191 = F_87 ( V_61 -> V_192 . V_193 ,
struct V_181 , V_194 ) ;
F_88 ( & V_191 -> V_194 ) ;
F_89 ( V_189 , & V_191 -> V_125 , & V_191 -> V_195 ) ;
F_80 ( V_191 ) ;
}
}
struct V_91 * F_90 ( unsigned int V_196 ,
enum V_197 V_3 )
{
struct V_91 * V_92 ;
unsigned int V_96 ;
unsigned int V_198 = 0 ;
int V_6 ;
if ( V_196 == 0 )
return NULL ;
if ( V_199 != 0 )
V_3 |= V_200 ;
if ( V_3 & V_200 )
V_96 = 1 ;
else
V_96 = F_91 () ;
F_92 ( V_92 , F_93 ( F_94 ( * V_92 ) , V_102 [ V_96 ] ) ) ;
if ( V_92 == NULL )
return NULL ;
V_92 -> V_201 = V_196 ;
V_92 -> V_202 = V_3 ;
F_95 ( & V_92 -> V_203 ) ;
F_92 ( V_92 -> V_131 ,
V_92 -> V_201 * sizeof( struct V_113 ) ) ;
if ( V_92 -> V_131 == NULL )
goto V_204;
if ( ( V_3 & V_200 ) != 0 ) {
V_198 = F_96 ( V_92 ) ;
F_97 ( V_92 -> V_102 [ 0 ] , V_198 ) ;
if ( V_92 -> V_102 [ 0 ] == NULL )
goto V_204;
V_92 -> V_205 = 1 ;
} else if ( ( V_3 & V_206 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_96 ; ++ V_6 )
if ( F_98 ( V_92 , V_6 ) < 0 )
goto V_204;
}
return V_92 ;
V_204:
F_83 ( & V_92 ) ;
return NULL ;
}
void F_83 ( struct V_91 * * V_207 )
{
struct V_91 * V_92 = * V_207 ;
unsigned int V_96 ;
unsigned int V_198 ;
unsigned int V_6 ;
if ( V_92 == NULL || V_92 -> V_201 == 0 )
return;
* V_207 = NULL ;
if ( V_92 -> V_202 & V_200 )
V_96 = 1 ;
else
V_96 = F_91 () ;
V_198 = F_96 ( V_92 ) ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ )
if ( V_92 -> V_102 [ V_6 ] != NULL )
F_99 ( V_92 -> V_102 [ V_6 ] , V_198 ) ;
if ( V_92 -> V_131 != NULL )
F_99 ( V_92 -> V_131 , V_92 -> V_201 *
sizeof( struct V_113 ) ) ;
F_99 ( V_92 , F_93 ( F_94 ( * V_92 ) , V_102 [ V_96 ] ) ) ;
}
void F_100 ( struct V_91 * V_92 )
{
struct V_94 * V_97 ;
int V_6 ;
int V_116 ;
unsigned int V_96 ;
unsigned long V_3 = 0 ;
V_96 = F_52 ( V_92 , V_101 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
if ( V_92 -> V_102 [ V_6 ] == NULL )
continue;
for ( V_116 = 0 ; V_116 < V_92 -> V_201 ; V_116 ++ ) {
V_97 = F_53 ( V_92 , V_6 , V_116 ) ;
V_97 -> V_98 = 0 ;
V_97 -> V_99 = V_100 ;
V_97 -> V_104 = 0 ;
V_97 -> V_105 = 0 ;
V_97 -> V_103 = 0 ;
if ( V_92 -> V_202 & V_206 )
V_97 -> V_208 = 0 ;
}
}
F_54 ( V_92 , V_101 , & V_3 ) ;
}
static T_8 F_101 ( struct V_26 * V_26 ,
const char T_4 * V_209 ,
T_9 V_210 , T_10 * V_211 )
{
struct V_51 * V_212 = V_26 -> V_213 ;
struct V_91 * V_92 = V_212 -> V_214 ;
F_100 ( V_92 ) ;
return V_210 ;
}
static void * F_102 ( struct V_51 * V_53 , T_10 * V_215 )
{
struct V_91 * V_92 = V_53 -> V_214 ;
return ( * V_215 < V_92 -> V_201 ) ? V_215 : NULL ;
}
static void F_103 ( struct V_51 * V_53 , void * V_216 )
{
}
static void * F_104 ( struct V_51 * V_53 , void * V_216 , T_10 * V_215 )
{
( * V_215 ) ++ ;
return F_102 ( V_53 , V_215 ) ;
}
static int F_105 ( struct V_51 * V_53 , void * V_216 )
{
struct V_91 * V_92 = V_53 -> V_214 ;
struct V_113 * V_217 ;
struct V_94 V_218 ;
int V_93 = * ( T_10 * ) V_216 ;
int V_50 = 0 ;
if ( V_93 == 0 ) {
struct V_219 V_163 ;
F_106 ( & V_163 ) ;
V_50 = F_28 ( V_53 , L_65 ,
L_66 , V_163 . V_220 , ( unsigned long ) V_163 . V_221 ) ;
if ( V_50 < 0 )
return V_50 ;
}
V_217 = & V_92 -> V_131 [ V_93 ] ;
F_51 ( V_92 , V_93 , & V_218 ) ;
if ( V_218 . V_98 == 0 )
goto V_49;
V_50 = F_28 ( V_53 , L_67 V_222 L_68 , V_217 -> V_223 ,
V_218 . V_98 , V_217 -> V_137 ) ;
if ( V_50 < 0 )
goto V_49;
if ( ( V_217 -> V_224 & V_225 ) && ( V_218 . V_98 > 0 ) ) {
V_50 = F_28 ( V_53 , L_69 V_222 L_69 V_222 L_69 V_222 ,
V_218 . V_99 , V_218 . V_104 , V_218 . V_103 ) ;
if ( V_50 < 0 )
goto V_49;
if ( V_217 -> V_224 & V_226 )
V_50 = F_28 ( V_53 , L_69 V_222 , V_218 . V_105 ) ;
if ( V_50 < 0 )
goto V_49;
}
V_50 = F_28 ( V_53 , L_8 ) ;
V_49:
return ( V_50 < 0 ) ? V_50 : 0 ;
}
static int F_107 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
struct V_51 * V_212 ;
int V_50 ;
V_50 = F_108 ( V_26 , & V_227 ) ;
if ( V_50 )
return V_50 ;
V_212 = V_26 -> V_213 ;
V_212 -> V_214 = F_109 ( V_25 ) ;
return 0 ;
}
int F_110 ( struct V_27 * V_28 , const char * V_29 ,
struct V_91 * V_92 )
{
struct V_27 * V_40 ;
F_23 ( V_28 != NULL ) ;
V_40 = F_13 ( V_29 , 0644 , V_28 ,
& V_228 , V_92 ) ;
if ( V_40 == NULL )
return - V_37 ;
return 0 ;
}
void F_111 ( struct V_91 * V_92 , int V_229 ,
unsigned V_230 , const char * V_29 , const char * V_231 )
{
struct V_113 * V_114 ;
struct V_94 * V_97 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_232 ;
F_23 ( V_92 != NULL ) ;
V_114 = & V_92 -> V_131 [ V_229 ] ;
F_82 ( V_114 != NULL , L_70 ,
V_229 , V_29 , V_231 ) ;
V_114 -> V_224 = V_230 ;
V_114 -> V_223 = V_29 ;
V_114 -> V_137 = V_231 ;
V_232 = F_52 ( V_92 , V_101 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_232 ; ++ V_6 ) {
if ( V_92 -> V_102 [ V_6 ] == NULL )
continue;
V_97 = F_53 ( V_92 , V_6 , V_229 ) ;
V_97 -> V_98 = 0 ;
V_97 -> V_99 = V_100 ;
V_97 -> V_104 = 0 ;
V_97 -> V_105 = 0 ;
V_97 -> V_103 = 0 ;
if ( ( V_92 -> V_202 & V_206 ) != 0 )
V_97 -> V_208 = 0 ;
}
F_54 ( V_92 , V_101 , & V_3 ) ;
}
void F_112 ( int V_233 , struct V_91 * V_92 )
{
F_113 ( V_233 , V_92 , V_234 ) ;
F_113 ( V_233 , V_92 , V_235 ) ;
F_113 ( V_233 , V_92 , V_236 ) ;
F_113 ( V_233 , V_92 , V_237 ) ;
F_113 ( V_233 , V_92 , V_238 ) ;
F_113 ( V_233 , V_92 , V_239 ) ;
F_113 ( V_233 , V_92 , V_240 ) ;
F_113 ( V_233 , V_92 , V_241 ) ;
F_113 ( V_233 , V_92 , V_242 ) ;
F_113 ( V_233 , V_92 , V_243 ) ;
F_113 ( V_233 , V_92 , V_244 ) ;
F_113 ( V_233 , V_92 , V_245 ) ;
F_113 ( V_233 , V_92 , V_246 ) ;
F_113 ( V_233 , V_92 , V_247 ) ;
F_113 ( V_233 , V_92 , V_248 ) ;
F_113 ( V_233 , V_92 , V_249 ) ;
F_113 ( V_233 , V_92 , V_250 ) ;
F_113 ( V_233 , V_92 , V_251 ) ;
F_113 ( V_233 , V_92 , V_252 ) ;
F_113 ( V_233 , V_92 , V_253 ) ;
F_113 ( V_233 , V_92 , V_254 ) ;
F_113 ( V_233 , V_92 , V_255 ) ;
F_113 ( V_233 , V_92 , V_256 ) ;
F_113 ( V_233 , V_92 , V_257 ) ;
F_113 ( V_233 , V_92 , V_258 ) ;
F_113 ( V_233 , V_92 , V_259 ) ;
F_113 ( V_233 , V_92 , V_260 ) ;
F_113 ( V_233 , V_92 , V_261 ) ;
F_113 ( V_233 , V_92 , V_262 ) ;
F_113 ( V_233 , V_92 , V_263 ) ;
F_113 ( V_233 , V_92 , V_264 ) ;
F_113 ( V_233 , V_92 , V_265 ) ;
F_113 ( V_233 , V_92 , V_266 ) ;
F_113 ( V_233 , V_92 , V_267 ) ;
F_113 ( V_233 , V_92 , V_268 ) ;
F_113 ( V_233 , V_92 , V_269 ) ;
F_113 ( V_233 , V_92 , V_270 ) ;
F_113 ( V_233 , V_92 , V_271 ) ;
F_113 ( V_233 , V_92 , V_272 ) ;
F_113 ( V_233 , V_92 , V_273 ) ;
F_113 ( V_233 , V_92 , V_274 ) ;
F_113 ( V_233 , V_92 , V_275 ) ;
F_113 ( V_233 , V_92 , V_276 ) ;
F_113 ( V_233 , V_92 , V_277 ) ;
F_113 ( V_233 , V_92 , V_278 ) ;
F_113 ( V_233 , V_92 , V_279 ) ;
F_113 ( V_233 , V_92 , V_280 ) ;
F_113 ( V_233 , V_92 , V_281 ) ;
F_113 ( V_233 , V_92 , V_282 ) ;
F_113 ( V_233 , V_92 , V_283 ) ;
F_113 ( V_233 , V_92 , V_284 ) ;
F_113 ( V_233 , V_92 , V_285 ) ;
F_113 ( V_233 , V_92 , V_286 ) ;
F_113 ( V_233 , V_92 , V_287 ) ;
F_113 ( V_233 , V_92 , V_288 ) ;
F_113 ( V_233 , V_92 , V_289 ) ;
F_113 ( V_233 , V_92 , V_290 ) ;
F_113 ( V_233 , V_92 , V_291 ) ;
F_113 ( V_233 , V_92 , V_292 ) ;
F_113 ( V_233 , V_92 , V_293 ) ;
F_113 ( V_233 , V_92 , V_294 ) ;
F_113 ( V_233 , V_92 , V_295 ) ;
F_113 ( V_233 , V_92 , V_296 ) ;
F_113 ( V_233 , V_92 , V_297 ) ;
F_113 ( V_233 , V_92 , V_298 ) ;
F_113 ( V_233 , V_92 , V_299 ) ;
F_113 ( V_233 , V_92 , V_300 ) ;
}
int F_114 ( struct V_60 * V_61 , unsigned V_233 )
{
struct V_91 * V_92 ;
unsigned int V_301 ;
int V_50 , V_6 ;
F_23 ( V_61 -> V_302 == NULL ) ;
F_23 ( V_61 -> V_179 != NULL ) ;
F_23 ( V_61 -> V_303 == 0 ) ;
V_301 = ( ( int ) sizeof( * V_61 -> V_173 -> V_304 ) / sizeof( void * ) ) +
V_233 - 1 ;
V_92 = F_90 ( V_301 , 0 ) ;
if ( V_92 == NULL )
return - V_37 ;
F_112 ( V_233 , V_92 ) ;
for ( V_6 = V_233 ; V_6 < V_301 ; V_6 ++ ) {
F_82 ( V_92 -> V_131 [ V_6 ] . V_223 != NULL ,
L_71
L_72 , V_6 - V_233 ) ;
}
V_50 = F_110 ( V_61 -> V_179 , L_73 , V_92 ) ;
if ( V_50 < 0 ) {
F_83 ( & V_92 ) ;
} else {
V_61 -> V_302 = V_92 ;
V_61 -> V_303 = V_233 ;
}
return V_50 ;
}
void F_115 ( struct V_60 * V_61 )
{
if ( V_61 -> V_302 )
F_83 ( & V_61 -> V_302 ) ;
}
void F_116 ( int V_233 , struct V_91 * V_92 )
{
F_117 ( V_233 , V_92 , V_305 ) ;
F_117 ( V_233 , V_92 , V_306 ) ;
F_117 ( V_233 , V_92 , V_277 ) ;
F_117 ( V_233 , V_92 , V_307 ) ;
F_117 ( V_233 , V_92 , V_258 ) ;
F_117 ( V_233 , V_92 , V_308 ) ;
F_117 ( V_233 , V_92 , V_275 ) ;
F_117 ( V_233 , V_92 , V_263 ) ;
F_117 ( V_233 , V_92 , V_309 ) ;
F_117 ( V_233 , V_92 , V_310 ) ;
F_117 ( V_233 , V_92 , V_311 ) ;
F_117 ( V_233 , V_92 , rename ) ;
F_117 ( V_233 , V_92 , V_312 ) ;
F_117 ( V_233 , V_92 , V_261 ) ;
F_117 ( V_233 , V_92 , V_269 ) ;
F_117 ( V_233 , V_92 , V_313 ) ;
F_117 ( V_233 , V_92 , V_314 ) ;
F_117 ( V_233 , V_92 , V_315 ) ;
F_117 ( V_233 , V_92 , V_316 ) ;
F_117 ( V_233 , V_92 , V_317 ) ;
F_117 ( V_233 , V_92 , V_318 ) ;
F_117 ( V_233 , V_92 , V_319 ) ;
F_117 ( V_233 , V_92 , V_320 ) ;
F_117 ( V_233 , V_92 , V_321 ) ;
F_117 ( V_233 , V_92 , V_322 ) ;
F_117 ( V_233 , V_92 , V_323 ) ;
F_117 ( V_233 , V_92 , V_279 ) ;
F_117 ( V_233 , V_92 , V_324 ) ;
F_117 ( V_233 , V_92 , V_325 ) ;
F_117 ( V_233 , V_92 , V_326 ) ;
F_117 ( V_233 , V_92 , V_327 ) ;
F_117 ( V_233 , V_92 , V_328 ) ;
}
int F_118 ( struct V_60 * V_61 ,
unsigned V_233 )
{
struct V_91 * V_92 ;
unsigned int V_301 ;
int V_50 , V_6 ;
F_23 ( V_61 -> V_329 == NULL ) ;
F_23 ( V_61 -> V_179 != NULL ) ;
F_23 ( V_61 -> V_330 == 0 ) ;
V_301 = 1 + F_119 ( V_328 ) +
V_233 ;
V_92 = F_90 ( V_301 , 0 ) ;
if ( V_92 == NULL )
return - V_37 ;
F_116 ( V_233 , V_92 ) ;
for ( V_6 = V_233 ; V_6 < V_301 ; V_6 ++ ) {
if ( V_92 -> V_131 [ V_6 ] . V_223 == NULL ) {
F_14 ( L_74
L_75 ,
V_6 - V_233 ) ;
F_120 () ;
}
}
V_50 = F_110 ( V_61 -> V_179 , L_76 , V_92 ) ;
if ( V_50 < 0 ) {
F_83 ( & V_92 ) ;
} else {
V_61 -> V_329 = V_92 ;
V_61 -> V_330 = V_233 ;
}
return V_50 ;
}
void F_121 ( struct V_60 * V_61 )
{
struct V_91 * V_92 = V_61 -> V_329 ;
if ( V_92 != NULL ) {
V_61 -> V_329 = NULL ;
V_61 -> V_330 = 0 ;
F_83 ( & V_92 ) ;
}
}
void F_122 ( struct V_91 * V_331 )
{
F_111 ( V_331 ,
V_332 - V_333 ,
0 , L_77 , L_78 ) ;
F_111 ( V_331 ,
V_334 - V_333 ,
0 , L_79 , L_78 ) ;
F_111 ( V_331 ,
V_335 - V_333 ,
0 , L_80 , L_78 ) ;
F_111 ( V_331 ,
V_336 - V_333 ,
0 , L_81 , L_78 ) ;
F_111 ( V_331 ,
V_337 - V_333 ,
0 , L_82 , L_78 ) ;
F_111 ( V_331 ,
V_338 - V_333 ,
0 , L_83 , L_78 ) ;
}
int F_123 ( struct V_188 * V_339 , struct V_340 * V_341 ,
struct V_342 * V_343 , void * V_30 )
{
struct V_344 * exp = F_124 ( V_339 , V_343 ) ;
struct V_51 * V_52 = (struct V_51 * ) V_30 ;
if ( exp -> V_345 )
F_28 ( V_52 , L_10 , F_125 ( & exp -> V_346 ) ) ;
return 0 ;
}
static int
F_126 ( struct V_51 * V_52 , void * V_347 )
{
struct V_181 * V_92 = (struct V_181 * ) V_52 -> V_214 ;
struct V_60 * V_61 = V_92 -> V_348 ;
F_127 ( V_61 -> V_349 , & V_92 -> V_125 ,
F_123 , V_52 ) ;
return 0 ;
}
int F_128 ( struct V_188 * V_339 , struct V_340 * V_341 ,
struct V_342 * V_343 , void * V_350 )
{
struct V_351 * V_30 = (struct V_351 * ) V_350 ;
struct V_344 * exp = F_124 ( V_339 , V_343 ) ;
if ( exp -> V_352 != NULL ) {
if ( V_30 -> V_106 ) {
F_129 ( V_30 -> V_52 ) ;
V_30 -> V_106 = false ;
}
F_130 ( V_339 , V_30 -> V_52 ) ;
}
return 0 ;
}
static int
F_131 ( struct V_51 * V_52 , void * V_347 )
{
struct V_181 * V_92 = (struct V_181 * ) V_52 -> V_214 ;
struct V_60 * V_61 = V_92 -> V_348 ;
struct V_351 V_350 = { V_52 , true } ;
F_127 ( V_61 -> V_349 , & V_92 -> V_125 ,
F_128 , & V_350 ) ;
return 0 ;
}
int F_132 ( struct V_51 * V_52 , void * V_30 )
{
return F_28 ( V_52 , L_10 ,
L_84
L_85 ) ;
}
static int F_133 ( void * V_353 , void * V_30 )
{
struct V_181 * V_191 = V_353 ;
F_81 ( V_354 , L_86 , F_32 ( & V_191 -> V_186 ) ) ;
if ( F_32 ( & V_191 -> V_186 ) == 1 ) {
F_59 ( & V_191 -> V_348 -> V_355 ) ;
F_134 ( & V_191 -> V_194 , V_30 ) ;
F_62 ( & V_191 -> V_348 -> V_355 ) ;
return 1 ;
}
if ( V_191 -> V_185 )
F_100 ( V_191 -> V_185 ) ;
return 0 ;
}
int F_135 ( struct V_26 * V_26 , const char * V_10 ,
unsigned long V_2 , void * V_30 )
{
struct V_60 * V_61 = (struct V_60 * ) V_30 ;
struct V_181 * V_182 ;
F_136 ( V_356 ) ;
F_137 ( V_61 -> V_190 ,
F_133 , & V_356 ) ;
while ( ! F_86 ( & V_356 ) ) {
V_182 = F_87 ( V_356 . V_193 , struct V_181 ,
V_194 ) ;
F_88 ( & V_182 -> V_194 ) ;
F_80 ( V_182 ) ;
}
return V_2 ;
}
int F_138 ( struct V_344 * exp , T_11 * V_125 , int * V_357 )
{
struct V_181 * V_358 , * V_359 ;
struct V_60 * V_61 = NULL ;
struct V_27 * V_40 ;
char * V_10 = NULL ;
int V_50 = 0 ;
* V_357 = 0 ;
if ( ! exp || ! exp -> V_360 || ! exp -> V_360 -> V_180 ||
! exp -> V_360 -> V_190 )
return - V_16 ;
if ( ! V_125 || * V_125 == V_361 )
return 0 ;
V_61 = exp -> V_360 ;
F_81 ( V_183 , L_87 , V_61 -> V_190 ) ;
F_139 ( V_358 ) ;
if ( V_358 == NULL )
return - V_37 ;
V_358 -> V_125 = * V_125 ;
V_358 -> V_348 = exp -> V_360 ;
F_35 ( & V_358 -> V_186 , 1 ) ;
V_359 = F_140 ( V_61 -> V_190 ,
V_125 , & V_358 -> V_195 ) ;
F_81 ( V_354 , L_88 ,
V_359 , F_61 ( * V_125 ) ,
F_32 ( & V_358 -> V_186 ) ) ;
if ( exp -> V_345 ) {
F_141 ( exp -> V_345 ) ;
exp -> V_345 = NULL ;
}
if ( V_359 != V_358 ) {
exp -> V_345 = V_359 ;
GOTO ( V_362 , V_50 = - V_363 ) ;
}
F_142 ( V_10 , V_364 ) ;
if ( V_10 == NULL )
GOTO ( V_362 , V_50 = - V_37 ) ;
memcpy ( V_10 , F_61 ( * V_125 ) , V_364 ) ;
V_358 -> V_184 = F_25 ( V_10 ,
V_61 -> V_180 ,
NULL , NULL ) ;
F_18 ( V_10 , V_364 ) ;
if ( F_77 ( V_358 -> V_184 ) ) {
F_14 ( L_89 ,
F_61 ( * V_125 ) ) ;
V_50 = F_78 ( V_358 -> V_184 ) ;
V_358 -> V_184 = NULL ;
GOTO ( V_365 , V_50 ) ;
}
V_40 = F_11 ( V_358 -> V_184 , L_90 ,
V_358 , & V_366 ) ;
if ( F_77 ( V_40 ) ) {
F_143 ( L_91 ) ;
V_50 = F_78 ( V_40 ) ;
GOTO ( V_365 , V_50 ) ;
}
V_40 = F_11 ( V_358 -> V_184 , L_92 ,
V_358 , & V_367 ) ;
if ( F_77 ( V_40 ) ) {
F_143 ( L_93 ) ;
V_50 = F_78 ( V_40 ) ;
GOTO ( V_365 , V_50 ) ;
}
exp -> V_345 = V_358 ;
* V_357 = 1 ;
F_59 ( & V_61 -> V_355 ) ;
F_144 ( & V_358 -> V_194 , & V_61 -> V_192 ) ;
F_62 ( & V_61 -> V_355 ) ;
return V_50 ;
V_365:
if ( V_358 -> V_184 != NULL )
F_20 ( & V_358 -> V_184 ) ;
F_89 ( V_61 -> V_190 , V_125 , & V_358 -> V_195 ) ;
V_362:
F_141 ( V_358 ) ;
F_84 ( V_358 ) ;
return V_50 ;
}
int F_145 ( struct V_344 * exp )
{
struct V_181 * V_191 = exp -> V_345 ;
if( ! V_191 || ! exp -> V_360 )
return 0 ;
F_141 ( exp -> V_345 ) ;
exp -> V_345 = NULL ;
return 0 ;
}
int F_34 ( const char * V_10 , unsigned long V_2 ,
int * V_11 )
{
return F_4 ( V_10 , V_2 , V_11 , 1 ) ;
}
int F_146 ( struct V_51 * V_52 , long V_11 , int V_12 )
{
long V_13 , V_14 ;
V_13 = V_11 / V_12 ;
F_28 ( V_52 , L_4 , V_13 ) ;
V_14 = V_11 % V_12 ;
if ( V_14 > 0 ) {
V_14 *= 100 ;
V_14 /= V_12 ;
}
if ( V_14 > 0 ) {
if ( ( V_14 % 10 ) != 0 )
F_28 ( V_52 , L_94 , V_14 ) ;
else
F_28 ( V_52 , L_94 , V_14 / 10 ) ;
}
F_28 ( V_52 , L_8 ) ;
return 0 ;
}
int F_147 ( const char * V_10 , unsigned long V_2 , T_1 * V_11 )
{
return F_148 ( V_10 , V_2 , V_11 , 1 ) ;
}
int F_148 ( const char * V_10 , unsigned long V_2 ,
T_1 * V_11 , int V_12 )
{
char V_20 [ 22 ] , * V_21 , * V_22 ;
T_1 V_368 , V_369 = 0 , V_231 ;
unsigned V_370 = 1 ;
if ( V_2 > ( sizeof( V_20 ) - 1 ) )
return - V_16 ;
if ( F_5 ( V_20 , V_10 , V_2 ) )
return - V_23 ;
V_20 [ V_2 ] = '\0' ;
V_22 = V_20 ;
if ( * V_22 == '-' ) {
V_12 = - V_12 ;
V_22 ++ ;
}
V_368 = F_149 ( V_22 , & V_21 , 10 ) ;
if ( V_22 == V_21 )
return - V_16 ;
if ( V_21 != NULL && * V_21 == '.' ) {
int V_6 ;
V_22 = V_21 + 1 ;
if ( strlen ( V_22 ) > 10 )
V_22 [ 10 ] = '\0' ;
V_369 = F_149 ( V_22 , & V_21 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_21 - V_22 ) ; V_6 ++ )
V_370 *= 10 ;
}
V_231 = 1 ;
switch( * V_21 ) {
case 'p' : case 'P' :
V_231 <<= 10 ;
case 't' : case 'T' :
V_231 <<= 10 ;
case 'g' : case 'G' :
V_231 <<= 10 ;
case 'm' : case 'M' :
V_231 <<= 10 ;
case 'k' : case 'K' :
V_231 <<= 10 ;
}
if ( V_231 )
V_12 = V_12 < 0 ? - V_231 : V_231 ;
V_369 *= V_12 ;
F_63 ( V_369 , V_370 ) ;
* V_11 = V_368 * V_12 + V_369 ;
return 0 ;
}
static char * F_150 ( const char * V_371 , const char * V_372 , T_9 V_210 )
{
T_9 V_373 ;
V_373 = strlen ( V_372 ) ;
if ( ! V_373 )
return ( char * ) V_371 ;
while ( V_210 >= V_373 ) {
V_210 -- ;
if ( ! memcmp ( V_371 , V_372 , V_373 ) )
return ( char * ) V_371 ;
V_371 ++ ;
}
return NULL ;
}
char * F_151 ( const char * V_10 , const char * V_29 ,
T_9 * V_2 )
{
char * V_11 ;
T_9 V_374 = * V_2 ;
V_11 = F_150 ( V_10 , V_29 , V_374 ) ;
if ( V_11 == NULL )
return ( char * ) V_10 ;
V_11 += strlen ( V_29 ) ;
while ( V_11 < V_10 + V_374 && isspace ( * V_11 ) )
V_11 ++ ;
* V_2 = 0 ;
while ( V_11 < V_10 + V_374 && isalnum ( * V_11 ) ) {
++ * V_2 ;
++ V_11 ;
}
return V_11 - * V_2 ;
}
int F_152 ( struct V_27 * V_38 ,
const char * V_29 ,
T_2 V_34 ,
const struct V_31 * V_375 ,
void * V_30 )
{
struct V_27 * V_40 ;
F_23 ( ( V_375 -> V_36 == NULL ) == ( ( V_34 & 0222 ) == 0 ) ) ;
V_40 = F_13 ( V_29 , V_34 , V_38 , V_375 , V_30 ) ;
if ( V_40 == NULL )
return - V_37 ;
return 0 ;
}
int F_153 ( struct V_60 * V_64 ,
const char * V_29 ,
T_2 V_34 ,
const struct V_31 * V_375 ,
void * V_30 )
{
return ( F_152 ( V_64 -> V_179 , V_29 ,
V_34 , V_375 , V_30 ) ) ;
}
void F_154 ( struct V_376 * V_377 , unsigned int V_378 )
{
if ( V_378 >= V_379 )
V_378 = V_379 - 1 ;
F_59 ( & V_377 -> V_380 ) ;
V_377 -> V_381 [ V_378 ] ++ ;
F_62 ( & V_377 -> V_380 ) ;
}
void F_155 ( struct V_376 * V_377 , unsigned int V_378 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; ( ( 1 << V_11 ) < V_378 ) && ( V_11 <= V_379 ) ; V_11 ++ )
;
F_154 ( V_377 , V_11 ) ;
}
unsigned long F_156 ( struct V_376 * V_377 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_379 ; V_6 ++ )
V_7 += V_377 -> V_381 [ V_6 ] ;
return V_7 ;
}
void F_157 ( struct V_376 * V_377 )
{
F_59 ( & V_377 -> V_380 ) ;
memset ( V_377 -> V_381 , 0 , sizeof( V_377 -> V_381 ) ) ;
F_62 ( & V_377 -> V_380 ) ;
}
int F_158 ( struct V_51 * V_52 , void * V_30 )
{
struct V_60 * V_64 = V_30 ;
struct V_382 * V_83 = & V_64 -> V_82 . V_83 ;
int V_50 ;
F_159 ( & V_83 -> V_383 ) ;
V_50 = F_28 ( V_52 , L_9 , V_83 -> V_384 ) ;
F_160 ( & V_83 -> V_383 ) ;
return V_50 ;
}
