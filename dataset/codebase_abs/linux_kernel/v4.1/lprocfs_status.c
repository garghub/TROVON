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
T_4 V_41 ;
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
T_3 V_33 = 0 ;
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
if ( V_39 == NULL ) {
V_39 = F_12 ( - V_36 ) ;
goto V_48;
}
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
F_28 ( V_51 , L_7 , * ( unsigned int * ) V_29 ) ;
return 0 ;
}
int F_29 ( struct V_25 * V_25 , const char T_2 * V_9 ,
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
F_28 ( V_51 , L_8 , * ( T_1 * ) V_29 ) ;
return 0 ;
}
int F_31 ( struct V_50 * V_51 , void * V_29 )
{
T_5 * V_55 = V_29 ;
F_23 ( V_55 != NULL ) ;
F_28 ( V_51 , L_9 , F_32 ( V_55 ) ) ;
return 0 ;
}
int F_33 ( struct V_25 * V_25 , const char T_2 * V_9 ,
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
F_28 ( V_51 , L_10 , V_59 -> V_60 . V_61 ) ;
return 0 ;
}
int F_37 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_62 = V_29 ;
F_23 ( V_62 != NULL ) ;
F_28 ( V_51 , L_10 , V_62 -> V_63 ) ;
return 0 ;
}
int F_38 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_64 V_65 ;
int V_49 = V_64 ( NULL , V_59 -> V_66 , & V_65 ,
F_39 ( - V_67 ) ,
V_68 ) ;
if ( ! V_49 )
F_28 ( V_51 , L_7 , V_65 . V_69 ) ;
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
F_28 ( V_51 , L_8 , V_71 ) ;
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
F_28 ( V_51 , L_8 , V_71 ) ;
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
F_28 ( V_51 , L_8 , V_71 ) ;
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
F_28 ( V_51 , L_8 , V_65 . V_75 ) ;
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
F_28 ( V_51 , L_8 , V_65 . V_76 ) ;
return V_49 ;
}
int F_45 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_77 * V_78 ;
char * V_79 = NULL ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
V_79 = F_47 ( V_78 -> V_83 ) ;
F_28 ( V_51 , L_11 ,
F_48 ( V_59 ) , V_79 ,
V_78 -> V_84 ? L_12 : L_2 ) ;
F_49 ( V_59 ) ;
return 0 ;
}
int F_50 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
struct V_85 * V_86 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_86 = V_59 -> V_80 . V_81 . V_82 -> V_87 ;
if ( V_86 && V_59 -> V_80 . V_81 . V_82 )
F_28 ( V_51 , L_10 , V_86 -> V_88 . V_61 ) ;
else
F_51 ( V_51 , L_13 ) ;
F_49 ( V_59 ) ;
return 0 ;
}
void F_52 ( struct V_89 * V_90 , int V_91 ,
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
V_94 = F_53 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
V_95 = F_54 ( V_90 , V_6 , V_91 ) ;
V_93 -> V_96 += V_95 -> V_96 ;
V_93 -> V_101 += V_95 -> V_101 ;
if ( V_95 -> V_97 < V_93 -> V_97 )
V_93 -> V_97 = V_95 -> V_97 ;
if ( V_95 -> V_102 > V_93 -> V_102 )
V_93 -> V_102 = V_95 -> V_102 ;
V_93 -> V_103 += V_95 -> V_103 ;
}
F_55 ( V_90 , V_99 , & V_3 ) ;
}
static int F_56 ( struct V_77 * V_78 , struct V_50 * V_51 )
{
bool V_104 = true ;
if ( V_78 -> V_105 -> V_106 ) {
F_28 ( V_51 , L_14 ) ;
V_104 = false ;
}
F_57 ( V_107 , V_104 ) ;
V_104 = false ;
F_57 ( V_108 , V_104 ) ;
F_57 ( V_109 , V_104 ) ;
F_57 ( V_110 , V_104 ) ;
return 0 ;
}
static void F_58 ( struct V_50 * V_51 , T_1 V_3 , char * V_4 )
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
int F_59 ( struct V_50 * V_51 , void * V_29 )
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
F_58 ( V_51 , V_78 -> V_117 . V_119 , L_21 ) ;
F_28 ( V_51 ,
L_22
L_23 ) ;
F_56 ( V_78 , V_51 ) ;
F_28 ( V_51 ,
L_22
L_24
L_25 ) ;
F_60 ( & V_78 -> V_120 ) ;
V_114 = 0 ;
F_61 (conn, &imp->imp_conn_list, oic_item) {
F_28 ( V_51 , L_1 , V_114 ? L_21 : L_2 ,
F_62 ( V_86 -> V_121 -> V_122 . V_123 ) ) ;
V_114 ++ ;
}
F_28 ( V_51 ,
L_22
L_26
L_27
L_28
L_29 ,
V_78 -> V_87 == NULL ? L_30 :
F_62 ( V_78 -> V_87 -> V_122 . V_123 ) ,
V_78 -> V_124 ,
V_78 -> V_125 ,
F_32 ( & V_78 -> V_126 ) ) ;
F_63 ( & V_78 -> V_120 ) ;
if ( V_59 -> V_127 == NULL )
goto V_128;
V_112 = & V_59 -> V_127 -> V_129 [ V_130 ] ;
F_52 ( V_59 -> V_127 , V_130 , & V_7 ) ;
if ( V_7 . V_96 != 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_64 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
} else
V_7 . V_101 = 0 ;
F_28 ( V_51 ,
L_31
L_32
L_33
L_34
L_35 ,
F_32 ( & V_78 -> V_132 ) ,
F_32 ( & V_78 -> V_133 ) ,
F_32 ( & V_78 -> V_134 ) ,
V_7 . V_101 , V_112 -> V_135 ) ;
V_115 = 0 ;
for ( V_114 = 0 ; V_114 < V_136 ; V_114 ++ ) {
if ( V_78 -> V_137 . V_138 [ V_114 ] == 0 )
break;
V_115 = F_65 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_28 ( V_51 ,
L_36
L_37
L_38 ,
V_115 ,
F_66 ( & V_78 -> V_137 . V_139 ) ) ;
F_28 ( V_51 ,
L_39
L_40
L_41
L_42 ,
V_78 -> V_140 ,
V_78 -> V_141 ,
V_78 -> V_142 ) ;
for ( V_116 = 0 ; V_116 <= 1 ; V_116 ++ ) {
F_52 ( V_59 -> V_127 ,
V_143 + V_144 + V_116 ,
& V_7 ) ;
if ( V_7 . V_101 > 0 && V_7 . V_96 > 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_64 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
F_28 ( V_51 ,
L_43
L_44 ,
V_116 ? L_45 : L_46 ,
V_7 . V_101 ) ;
}
V_115 = ( int ) V_7 . V_101 ;
V_114 = F_67 ( V_145 + V_116 ) + V_146 ;
V_112 = & V_59 -> V_127 -> V_129 [ V_114 ] ;
F_52 ( V_59 -> V_127 , V_114 , & V_7 ) ;
if ( V_7 . V_101 > 0 && V_7 . V_96 != 0 ) {
T_1 V_131 = V_7 . V_101 ;
F_64 ( V_131 , V_7 . V_96 ) ;
V_7 . V_101 = V_131 ;
F_28 ( V_51 ,
L_47 ,
V_112 -> V_135 , V_7 . V_101 ) ;
V_114 = ( int ) V_7 . V_101 ;
if ( V_114 > 0 )
F_28 ( V_51 ,
L_48 ,
V_115 / V_114 , ( 100 * V_115 / V_114 ) % 100 ) ;
}
}
V_128:
F_49 ( V_59 ) ;
return 0 ;
}
int F_68 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_77 * V_78 ;
int V_114 , V_115 ;
F_23 ( V_59 != NULL ) ;
F_46 ( V_59 ) ;
V_78 = V_59 -> V_80 . V_81 . V_82 ;
F_28 ( V_51 , L_49 ,
F_47 ( V_78 -> V_83 ) ) ;
F_28 ( V_51 , L_50 ) ;
V_115 = V_78 -> V_147 ;
for ( V_114 = 0 ; V_114 < V_148 ; V_114 ++ ) {
struct V_149 * V_150 =
& V_78 -> V_151 [ ( V_115 + V_114 ) % V_148 ] ;
if ( V_150 -> V_152 == 0 )
continue;
F_28 ( V_51 , L_51 V_153 L_52 ,
V_150 -> V_154 ,
F_47 ( V_150 -> V_152 ) ) ;
}
F_49 ( V_59 ) ;
return 0 ;
}
int F_69 ( struct V_50 * V_51 , struct V_155 * V_156 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_157 ; V_6 ++ )
F_28 ( V_51 , L_53 , V_156 -> V_158 [ V_6 ] ) ;
F_28 ( V_51 , L_54 ) ;
return 0 ;
}
int F_70 ( struct V_50 * V_51 , void * V_29 )
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
V_161 = F_71 () ;
F_72 ( & V_164 , V_161 - V_78 -> V_165 ) ;
F_28 ( V_51 , L_55 V_166 L_56 ,
L_57 , V_78 -> V_165 , F_73 ( & V_164 ) ) ;
V_159 = F_66 ( & V_78 -> V_137 . V_139 ) ;
V_160 = V_78 -> V_137 . V_139 . V_167 ;
V_162 = V_78 -> V_137 . V_139 . V_168 ;
F_72 ( & V_164 , V_161 - V_162 ) ;
F_28 ( V_51 , L_58 V_166 L_59 ,
L_60 , V_159 , V_160 , V_162 , F_73 ( & V_164 ) ) ;
F_69 ( V_51 , & V_78 -> V_137 . V_139 ) ;
for ( V_6 = 0 ; V_6 < V_136 ; V_6 ++ ) {
if ( V_78 -> V_137 . V_138 [ V_6 ] == 0 )
break;
V_159 = F_66 ( & V_78 -> V_137 . V_169 [ V_6 ] ) ;
V_160 = V_78 -> V_137 . V_169 [ V_6 ] . V_167 ;
V_162 = V_78 -> V_137 . V_169 [ V_6 ] . V_168 ;
F_72 ( & V_164 , V_161 - V_162 ) ;
F_28 ( V_51 , L_61
V_166 L_59 , V_78 -> V_137 . V_138 [ V_6 ] ,
V_159 , V_160 , V_162 , F_73 ( & V_164 ) ) ;
F_69 ( V_51 , & V_78 -> V_137 . V_169 [ V_6 ] ) ;
}
F_49 ( V_59 ) ;
return 0 ;
}
int F_74 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
T_1 V_3 ;
F_46 ( V_59 ) ;
V_3 = V_59 -> V_80 . V_81 . V_82 -> V_117 . V_119 ;
F_28 ( V_51 , L_62 , V_3 ) ;
F_58 ( V_51 , V_3 , L_54 ) ;
F_28 ( V_51 , L_54 ) ;
F_49 ( V_59 ) ;
return 0 ;
}
int F_75 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_59 = V_29 ;
F_23 ( V_59 != NULL ) ;
F_28 ( V_51 , L_7 , V_59 -> V_170 ) ;
return 0 ;
}
int F_76 ( struct V_50 * V_51 , void * V_29 )
{
struct V_171 * V_172 = (struct V_171 * ) V_29 ;
F_23 ( V_172 != NULL ) ;
F_28 ( V_51 , L_9 , V_172 -> V_173 ) ;
return 0 ;
}
int F_77 ( struct V_58 * V_59 , struct V_43 * V_44 )
{
int V_49 = 0 ;
F_23 ( V_59 != NULL ) ;
F_23 ( V_59 -> V_174 == V_175 ) ;
F_23 ( V_59 -> V_171 -> V_176 != NULL ) ;
V_59 -> V_177 = F_25 ( V_59 -> V_63 ,
V_59 -> V_171 -> V_176 ,
V_44 , V_59 ) ;
if ( F_78 ( V_59 -> V_177 ) ) {
V_49 = F_79 ( V_59 -> V_177 ) ;
F_14 ( L_63 ,
V_49 , V_59 -> V_63 ) ;
V_59 -> V_177 = NULL ;
}
return V_49 ;
}
int F_80 ( struct V_58 * V_59 )
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
static void F_81 ( struct V_179 * V_180 )
{
F_82 ( V_181 , L_64 , V_180 ,
V_180 -> V_182 , V_180 -> V_183 ) ;
F_83 ( F_32 ( & V_180 -> V_184 ) == 0 ,
L_65 , F_62 ( V_180 -> V_123 ) ,
F_32 ( & V_180 -> V_184 ) ) ;
if ( V_180 -> V_182 )
F_20 ( & V_180 -> V_182 ) ;
if ( V_180 -> V_183 )
F_84 ( & V_180 -> V_183 ) ;
if ( V_180 -> V_185 )
F_84 ( & V_180 -> V_185 ) ;
F_85 ( V_180 ) ;
return;
}
void F_86 ( struct V_58 * V_59 )
{
struct V_186 * V_187 = V_59 -> V_188 ;
struct V_179 * V_189 ;
while ( ! F_87 ( & V_59 -> V_190 ) ) {
V_189 = F_88 ( V_59 -> V_190 . V_191 ,
struct V_179 , V_192 ) ;
F_89 ( & V_189 -> V_192 ) ;
F_90 ( V_187 , & V_189 -> V_123 , & V_189 -> V_193 ) ;
F_81 ( V_189 ) ;
}
}
int F_91 ( struct V_89 * V_90 , unsigned int V_194 )
{
struct V_92 * V_195 ;
unsigned int V_196 ;
int V_49 = - V_36 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_23 ( V_90 -> V_100 [ V_194 ] == NULL ) ;
F_23 ( ( V_90 -> V_197 & V_198 ) == 0 ) ;
V_196 = F_92 ( V_90 ) ;
F_93 ( V_90 -> V_100 [ V_194 ] , V_196 ) ;
if ( V_90 -> V_100 [ V_194 ] != NULL ) {
V_49 = 0 ;
if ( F_94 ( V_90 -> V_199 <= V_194 ) ) {
if ( V_90 -> V_197 & V_200 )
F_95 ( & V_90 -> V_201 , V_3 ) ;
else
F_60 ( & V_90 -> V_201 ) ;
if ( V_90 -> V_199 <= V_194 )
V_90 -> V_199 = V_194 + 1 ;
if ( V_90 -> V_197 & V_200 )
F_96 ( & V_90 -> V_201 , V_3 ) ;
else
F_63 ( & V_90 -> V_201 ) ;
}
for ( V_6 = 0 ; V_6 < V_90 -> V_202 ; ++ V_6 ) {
V_195 = F_54 ( V_90 , V_194 , V_6 ) ;
V_195 -> V_97 = V_98 ;
}
}
return V_49 ;
}
struct V_89 * F_97 ( unsigned int V_203 ,
enum V_204 V_3 )
{
struct V_89 * V_90 ;
unsigned int V_94 ;
unsigned int V_196 = 0 ;
int V_6 ;
if ( V_203 == 0 )
return NULL ;
if ( V_205 != 0 )
V_3 |= V_198 ;
if ( V_3 & V_198 )
V_94 = 1 ;
else
V_94 = F_98 () ;
F_99 ( V_90 , F_100 ( F_101 ( * V_90 ) , V_100 [ V_94 ] ) ) ;
if ( V_90 == NULL )
return NULL ;
V_90 -> V_202 = V_203 ;
V_90 -> V_197 = V_3 ;
F_102 ( & V_90 -> V_201 ) ;
F_99 ( V_90 -> V_129 ,
V_90 -> V_202 * sizeof( struct V_111 ) ) ;
if ( V_90 -> V_129 == NULL )
goto V_206;
if ( ( V_3 & V_198 ) != 0 ) {
V_196 = F_92 ( V_90 ) ;
F_93 ( V_90 -> V_100 [ 0 ] , V_196 ) ;
if ( V_90 -> V_100 [ 0 ] == NULL )
goto V_206;
V_90 -> V_199 = 1 ;
} else if ( ( V_3 & V_200 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_94 ; ++ V_6 )
if ( F_91 ( V_90 , V_6 ) < 0 )
goto V_206;
}
return V_90 ;
V_206:
F_84 ( & V_90 ) ;
return NULL ;
}
void F_84 ( struct V_89 * * V_207 )
{
struct V_89 * V_90 = * V_207 ;
unsigned int V_94 ;
unsigned int V_196 ;
unsigned int V_6 ;
if ( V_90 == NULL || V_90 -> V_202 == 0 )
return;
* V_207 = NULL ;
if ( V_90 -> V_197 & V_198 )
V_94 = 1 ;
else
V_94 = F_98 () ;
V_196 = F_92 ( V_90 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ )
if ( V_90 -> V_100 [ V_6 ] != NULL )
F_103 ( V_90 -> V_100 [ V_6 ] , V_196 ) ;
if ( V_90 -> V_129 != NULL )
F_103 ( V_90 -> V_129 , V_90 -> V_202 *
sizeof( struct V_111 ) ) ;
F_103 ( V_90 , F_100 ( F_101 ( * V_90 ) , V_100 [ V_94 ] ) ) ;
}
void F_104 ( struct V_89 * V_90 )
{
struct V_92 * V_95 ;
int V_6 ;
int V_114 ;
unsigned int V_94 ;
unsigned long V_3 = 0 ;
V_94 = F_53 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
for ( V_114 = 0 ; V_114 < V_90 -> V_202 ; V_114 ++ ) {
V_95 = F_54 ( V_90 , V_6 , V_114 ) ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_98 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 0 ;
V_95 -> V_101 = 0 ;
if ( V_90 -> V_197 & V_200 )
V_95 -> V_208 = 0 ;
}
}
F_55 ( V_90 , V_99 , & V_3 ) ;
}
static T_8 F_105 ( struct V_25 * V_25 ,
const char T_2 * V_209 ,
T_9 V_210 , T_10 * V_211 )
{
struct V_50 * V_212 = V_25 -> V_213 ;
struct V_89 * V_90 = V_212 -> V_214 ;
F_104 ( V_90 ) ;
return V_210 ;
}
static void * F_106 ( struct V_50 * V_52 , T_10 * V_215 )
{
struct V_89 * V_90 = V_52 -> V_214 ;
return ( * V_215 < V_90 -> V_202 ) ? V_215 : NULL ;
}
static void F_107 ( struct V_50 * V_52 , void * V_216 )
{
}
static void * F_108 ( struct V_50 * V_52 , void * V_216 , T_10 * V_215 )
{
( * V_215 ) ++ ;
return F_106 ( V_52 , V_215 ) ;
}
static int F_109 ( struct V_50 * V_52 , void * V_216 )
{
struct V_89 * V_90 = V_52 -> V_214 ;
struct V_111 * V_217 ;
struct V_92 V_218 ;
int V_91 = * ( T_10 * ) V_216 ;
if ( V_91 == 0 ) {
struct V_219 V_161 ;
F_110 ( & V_161 ) ;
F_28 ( V_52 , L_66 ,
L_67 ,
V_161 . V_220 , ( unsigned long ) V_161 . V_221 ) ;
}
V_217 = & V_90 -> V_129 [ V_91 ] ;
F_52 ( V_90 , V_91 , & V_218 ) ;
if ( V_218 . V_96 != 0 ) {
F_28 ( V_52 , L_68 ,
V_217 -> V_222 , V_218 . V_96 , V_217 -> V_135 ) ;
if ( ( V_217 -> V_223 & V_224 ) &&
( V_218 . V_96 > 0 ) ) {
F_28 ( V_52 , L_69 ,
V_218 . V_97 , V_218 . V_102 , V_218 . V_101 ) ;
if ( V_217 -> V_223 & V_225 )
F_28 ( V_52 , L_70 , V_218 . V_103 ) ;
}
F_111 ( V_52 , '\n' ) ;
}
return 0 ;
}
static int F_112 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_50 * V_212 ;
int V_49 ;
V_49 = F_113 ( V_25 , & V_226 ) ;
if ( V_49 )
return V_49 ;
V_212 = V_25 -> V_213 ;
V_212 -> V_214 = F_114 ( V_24 ) ;
return 0 ;
}
int F_115 ( struct V_26 * V_27 , const char * V_28 ,
struct V_89 * V_90 )
{
struct V_26 * V_39 ;
F_23 ( V_27 != NULL ) ;
V_39 = F_13 ( V_28 , 0644 , V_27 ,
& V_227 , V_90 ) ;
if ( V_39 == NULL )
return - V_36 ;
return 0 ;
}
void F_116 ( struct V_89 * V_90 , int V_228 ,
unsigned V_229 , const char * V_28 , const char * V_230 )
{
struct V_111 * V_112 ;
struct V_92 * V_95 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_231 ;
F_23 ( V_90 != NULL ) ;
V_112 = & V_90 -> V_129 [ V_228 ] ;
F_83 ( V_112 != NULL , L_71 ,
V_228 , V_28 , V_230 ) ;
V_112 -> V_223 = V_229 ;
V_112 -> V_222 = V_28 ;
V_112 -> V_135 = V_230 ;
V_231 = F_53 ( V_90 , V_99 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_231 ; ++ V_6 ) {
if ( V_90 -> V_100 [ V_6 ] == NULL )
continue;
V_95 = F_54 ( V_90 , V_6 , V_228 ) ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_98 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 0 ;
V_95 -> V_101 = 0 ;
if ( ( V_90 -> V_197 & V_200 ) != 0 )
V_95 -> V_208 = 0 ;
}
F_55 ( V_90 , V_99 , & V_3 ) ;
}
void F_117 ( int V_232 , struct V_89 * V_90 )
{
F_118 ( V_232 , V_90 , V_233 ) ;
F_118 ( V_232 , V_90 , V_234 ) ;
F_118 ( V_232 , V_90 , V_235 ) ;
F_118 ( V_232 , V_90 , V_236 ) ;
F_118 ( V_232 , V_90 , V_237 ) ;
F_118 ( V_232 , V_90 , V_238 ) ;
F_118 ( V_232 , V_90 , V_239 ) ;
F_118 ( V_232 , V_90 , V_240 ) ;
F_118 ( V_232 , V_90 , V_241 ) ;
F_118 ( V_232 , V_90 , V_242 ) ;
F_118 ( V_232 , V_90 , V_243 ) ;
F_118 ( V_232 , V_90 , V_244 ) ;
F_118 ( V_232 , V_90 , V_245 ) ;
F_118 ( V_232 , V_90 , V_246 ) ;
F_118 ( V_232 , V_90 , V_247 ) ;
F_118 ( V_232 , V_90 , V_248 ) ;
F_118 ( V_232 , V_90 , V_249 ) ;
F_118 ( V_232 , V_90 , V_250 ) ;
F_118 ( V_232 , V_90 , V_251 ) ;
F_118 ( V_232 , V_90 , V_252 ) ;
F_118 ( V_232 , V_90 , V_253 ) ;
F_118 ( V_232 , V_90 , V_254 ) ;
F_118 ( V_232 , V_90 , V_255 ) ;
F_118 ( V_232 , V_90 , V_256 ) ;
F_118 ( V_232 , V_90 , V_257 ) ;
F_118 ( V_232 , V_90 , V_258 ) ;
F_118 ( V_232 , V_90 , V_259 ) ;
F_118 ( V_232 , V_90 , V_260 ) ;
F_118 ( V_232 , V_90 , V_261 ) ;
F_118 ( V_232 , V_90 , V_262 ) ;
F_118 ( V_232 , V_90 , V_263 ) ;
F_118 ( V_232 , V_90 , V_264 ) ;
F_118 ( V_232 , V_90 , V_265 ) ;
F_118 ( V_232 , V_90 , V_266 ) ;
F_118 ( V_232 , V_90 , V_267 ) ;
F_118 ( V_232 , V_90 , V_268 ) ;
F_118 ( V_232 , V_90 , V_269 ) ;
F_118 ( V_232 , V_90 , V_270 ) ;
F_118 ( V_232 , V_90 , V_271 ) ;
F_118 ( V_232 , V_90 , V_272 ) ;
F_118 ( V_232 , V_90 , V_273 ) ;
F_118 ( V_232 , V_90 , V_274 ) ;
F_118 ( V_232 , V_90 , V_275 ) ;
F_118 ( V_232 , V_90 , V_276 ) ;
F_118 ( V_232 , V_90 , V_277 ) ;
F_118 ( V_232 , V_90 , V_278 ) ;
F_118 ( V_232 , V_90 , V_279 ) ;
}
int F_119 ( struct V_58 * V_59 , unsigned V_232 )
{
struct V_89 * V_90 ;
unsigned int V_280 ;
int V_49 , V_6 ;
F_23 ( V_59 -> V_281 == NULL ) ;
F_23 ( V_59 -> V_177 != NULL ) ;
F_23 ( V_59 -> V_282 == 0 ) ;
V_280 = ( ( int ) sizeof( * V_59 -> V_171 -> V_283 ) / sizeof( void * ) ) +
V_232 - 1 ;
V_90 = F_97 ( V_280 , 0 ) ;
if ( V_90 == NULL )
return - V_36 ;
F_117 ( V_232 , V_90 ) ;
for ( V_6 = V_232 ; V_6 < V_280 ; V_6 ++ ) {
F_83 ( V_90 -> V_129 [ V_6 ] . V_222 != NULL ,
L_72 ,
V_6 - V_232 ) ;
}
V_49 = F_115 ( V_59 -> V_177 , L_73 , V_90 ) ;
if ( V_49 < 0 ) {
F_84 ( & V_90 ) ;
} else {
V_59 -> V_281 = V_90 ;
V_59 -> V_282 = V_232 ;
}
return V_49 ;
}
void F_120 ( struct V_58 * V_59 )
{
if ( V_59 -> V_281 )
F_84 ( & V_59 -> V_281 ) ;
}
void F_121 ( int V_232 , struct V_89 * V_90 )
{
F_122 ( V_232 , V_90 , V_284 ) ;
F_122 ( V_232 , V_90 , V_285 ) ;
F_122 ( V_232 , V_90 , V_265 ) ;
F_122 ( V_232 , V_90 , V_286 ) ;
F_122 ( V_232 , V_90 , V_256 ) ;
F_122 ( V_232 , V_90 , V_287 ) ;
F_122 ( V_232 , V_90 , V_288 ) ;
F_122 ( V_232 , V_90 , V_260 ) ;
F_122 ( V_232 , V_90 , V_289 ) ;
F_122 ( V_232 , V_90 , V_290 ) ;
F_122 ( V_232 , V_90 , V_291 ) ;
F_122 ( V_232 , V_90 , rename ) ;
F_122 ( V_232 , V_90 , V_292 ) ;
F_122 ( V_232 , V_90 , V_258 ) ;
F_122 ( V_232 , V_90 , V_293 ) ;
F_122 ( V_232 , V_90 , V_294 ) ;
F_122 ( V_232 , V_90 , V_295 ) ;
F_122 ( V_232 , V_90 , V_296 ) ;
F_122 ( V_232 , V_90 , V_297 ) ;
F_122 ( V_232 , V_90 , V_298 ) ;
F_122 ( V_232 , V_90 , V_299 ) ;
F_122 ( V_232 , V_90 , V_300 ) ;
F_122 ( V_232 , V_90 , V_301 ) ;
F_122 ( V_232 , V_90 , V_302 ) ;
F_122 ( V_232 , V_90 , V_303 ) ;
F_122 ( V_232 , V_90 , V_304 ) ;
F_122 ( V_232 , V_90 , V_305 ) ;
F_122 ( V_232 , V_90 , V_306 ) ;
F_122 ( V_232 , V_90 , V_307 ) ;
F_122 ( V_232 , V_90 , V_308 ) ;
F_122 ( V_232 , V_90 , V_309 ) ;
F_122 ( V_232 , V_90 , V_310 ) ;
}
int F_123 ( struct V_58 * V_59 ,
unsigned V_232 )
{
struct V_89 * V_90 ;
unsigned int V_280 ;
int V_49 , V_6 ;
F_23 ( V_59 -> V_311 == NULL ) ;
F_23 ( V_59 -> V_177 != NULL ) ;
F_23 ( V_59 -> V_312 == 0 ) ;
V_280 = 1 + F_124 ( V_310 ) +
V_232 ;
V_90 = F_97 ( V_280 , 0 ) ;
if ( V_90 == NULL )
return - V_36 ;
F_121 ( V_232 , V_90 ) ;
for ( V_6 = V_232 ; V_6 < V_280 ; V_6 ++ ) {
if ( V_90 -> V_129 [ V_6 ] . V_222 == NULL ) {
F_14 ( L_74 ,
V_6 - V_232 ) ;
F_125 () ;
}
}
V_49 = F_115 ( V_59 -> V_177 , L_75 , V_90 ) ;
if ( V_49 < 0 ) {
F_84 ( & V_90 ) ;
} else {
V_59 -> V_311 = V_90 ;
V_59 -> V_312 = V_232 ;
}
return V_49 ;
}
void F_126 ( struct V_58 * V_59 )
{
struct V_89 * V_90 = V_59 -> V_311 ;
if ( V_90 != NULL ) {
V_59 -> V_311 = NULL ;
V_59 -> V_312 = 0 ;
F_84 ( & V_90 ) ;
}
}
void F_127 ( struct V_89 * V_313 )
{
F_116 ( V_313 ,
V_314 - V_315 ,
0 , L_76 , L_77 ) ;
F_116 ( V_313 ,
V_316 - V_315 ,
0 , L_78 , L_77 ) ;
F_116 ( V_313 ,
V_317 - V_315 ,
0 , L_79 , L_77 ) ;
F_116 ( V_313 ,
V_318 - V_315 ,
0 , L_80 , L_77 ) ;
F_116 ( V_313 ,
V_319 - V_315 ,
0 , L_81 , L_77 ) ;
F_116 ( V_313 ,
V_320 - V_315 ,
0 , L_82 , L_77 ) ;
}
int F_128 ( struct V_186 * V_321 , struct V_322 * V_323 ,
struct V_324 * V_325 , void * V_29 )
{
struct V_326 * exp = F_129 ( V_321 , V_325 ) ;
struct V_50 * V_51 = (struct V_50 * ) V_29 ;
if ( exp -> V_327 )
F_28 ( V_51 , L_10 , F_130 ( & exp -> V_328 ) ) ;
return 0 ;
}
static int
F_131 ( struct V_50 * V_51 , void * V_329 )
{
struct V_179 * V_90 = (struct V_179 * ) V_51 -> V_214 ;
struct V_58 * V_59 = V_90 -> V_330 ;
F_132 ( V_59 -> V_331 , & V_90 -> V_123 ,
F_128 , V_51 ) ;
return 0 ;
}
int F_133 ( struct V_186 * V_321 , struct V_322 * V_323 ,
struct V_324 * V_325 , void * V_332 )
{
struct V_333 * V_29 = (struct V_333 * ) V_332 ;
struct V_326 * exp = F_129 ( V_321 , V_325 ) ;
if ( exp -> V_334 != NULL ) {
if ( V_29 -> V_104 ) {
F_134 ( V_29 -> V_51 ) ;
V_29 -> V_104 = false ;
}
F_135 ( V_321 , V_29 -> V_51 ) ;
}
return 0 ;
}
static int
F_136 ( struct V_50 * V_51 , void * V_329 )
{
struct V_179 * V_90 = (struct V_179 * ) V_51 -> V_214 ;
struct V_58 * V_59 = V_90 -> V_330 ;
struct V_333 V_332 = {
. V_51 = V_51 ,
. V_104 = true
} ;
F_132 ( V_59 -> V_331 , & V_90 -> V_123 ,
F_133 , & V_332 ) ;
return 0 ;
}
int F_137 ( struct V_50 * V_51 , void * V_29 )
{
F_28 ( V_51 , L_10 ,
L_83 ) ;
return 0 ;
}
static int F_138 ( void * V_335 , void * V_29 )
{
struct V_179 * V_189 = V_335 ;
F_82 ( V_336 , L_84 , F_32 ( & V_189 -> V_184 ) ) ;
if ( F_32 ( & V_189 -> V_184 ) == 1 ) {
F_60 ( & V_189 -> V_330 -> V_337 ) ;
F_139 ( & V_189 -> V_192 , V_29 ) ;
F_63 ( & V_189 -> V_330 -> V_337 ) ;
return 1 ;
}
if ( V_189 -> V_183 )
F_104 ( V_189 -> V_183 ) ;
return 0 ;
}
int F_140 ( struct V_25 * V_25 , const char * V_9 ,
unsigned long V_2 , void * V_29 )
{
struct V_58 * V_59 = (struct V_58 * ) V_29 ;
struct V_179 * V_180 ;
F_141 ( V_338 ) ;
F_142 ( V_59 -> V_188 ,
F_138 , & V_338 ) ;
while ( ! F_87 ( & V_338 ) ) {
V_180 = F_88 ( V_338 . V_191 , struct V_179 ,
V_192 ) ;
F_89 ( & V_180 -> V_192 ) ;
F_81 ( V_180 ) ;
}
return V_2 ;
}
int F_143 ( struct V_326 * exp , T_11 * V_123 , int * V_339 )
{
struct V_179 * V_340 , * V_341 ;
struct V_58 * V_59 = NULL ;
struct V_26 * V_39 ;
char * V_9 = NULL ;
int V_49 = 0 ;
* V_339 = 0 ;
if ( ! exp || ! exp -> V_342 || ! exp -> V_342 -> V_178 ||
! exp -> V_342 -> V_188 )
return - V_15 ;
if ( ! V_123 || * V_123 == V_343 )
return 0 ;
V_59 = exp -> V_342 ;
F_82 ( V_181 , L_85 , V_59 -> V_188 ) ;
F_144 ( V_340 ) ;
if ( V_340 == NULL )
return - V_36 ;
V_340 -> V_123 = * V_123 ;
V_340 -> V_330 = exp -> V_342 ;
F_35 ( & V_340 -> V_184 , 1 ) ;
V_341 = F_145 ( V_59 -> V_188 ,
V_123 , & V_340 -> V_193 ) ;
F_82 ( V_336 , L_86 ,
V_341 , F_62 ( * V_123 ) ,
F_32 ( & V_340 -> V_184 ) ) ;
if ( exp -> V_327 ) {
F_146 ( exp -> V_327 ) ;
exp -> V_327 = NULL ;
}
if ( V_341 != V_340 ) {
exp -> V_327 = V_341 ;
V_49 = - V_344 ;
goto V_345;
}
F_147 ( V_9 , V_346 ) ;
if ( V_9 == NULL ) {
V_49 = - V_36 ;
goto V_345;
}
memcpy ( V_9 , F_62 ( * V_123 ) , V_346 ) ;
V_340 -> V_182 = F_25 ( V_9 ,
V_59 -> V_178 ,
NULL , NULL ) ;
F_18 ( V_9 , V_346 ) ;
if ( F_78 ( V_340 -> V_182 ) ) {
F_14 ( L_87 ,
F_62 ( * V_123 ) ) ;
V_49 = F_79 ( V_340 -> V_182 ) ;
V_340 -> V_182 = NULL ;
goto V_347;
}
V_39 = F_11 ( V_340 -> V_182 , L_88 ,
V_340 , & V_348 ) ;
if ( F_78 ( V_39 ) ) {
F_148 ( L_89 ) ;
V_49 = F_79 ( V_39 ) ;
goto V_347;
}
V_39 = F_11 ( V_340 -> V_182 , L_90 ,
V_340 , & V_349 ) ;
if ( F_78 ( V_39 ) ) {
F_148 ( L_91 ) ;
V_49 = F_79 ( V_39 ) ;
goto V_347;
}
exp -> V_327 = V_340 ;
* V_339 = 1 ;
F_60 ( & V_59 -> V_337 ) ;
F_149 ( & V_340 -> V_192 , & V_59 -> V_190 ) ;
F_63 ( & V_59 -> V_337 ) ;
return V_49 ;
V_347:
if ( V_340 -> V_182 != NULL )
F_20 ( & V_340 -> V_182 ) ;
F_90 ( V_59 -> V_188 , V_123 , & V_340 -> V_193 ) ;
V_345:
F_146 ( V_340 ) ;
F_85 ( V_340 ) ;
return V_49 ;
}
int F_150 ( struct V_326 * exp )
{
struct V_179 * V_189 = exp -> V_327 ;
if ( ! V_189 || ! exp -> V_342 )
return 0 ;
F_146 ( exp -> V_327 ) ;
exp -> V_327 = NULL ;
return 0 ;
}
T_12 F_151 ( struct V_92 * V_350 ,
struct V_111 * V_112 ,
enum V_204 V_3 ,
enum V_351 V_352 )
{
T_12 V_7 = 0 ;
if ( V_350 == NULL || V_112 == NULL )
return 0 ;
switch ( V_352 ) {
case V_353 :
V_7 = V_112 -> V_223 ;
break;
case V_354 :
V_7 = V_350 -> V_101 ;
if ( ( V_3 & V_200 ) != 0 )
V_7 += V_350 -> V_208 ;
break;
case V_355 :
V_7 = V_350 -> V_97 ;
break;
case V_356 :
V_7 = V_350 -> V_102 ;
break;
case V_357 :
V_7 = ( V_350 -> V_102 - V_350 -> V_97 ) / 2 ;
break;
case V_358 :
V_7 = V_350 -> V_103 ;
break;
case V_359 :
V_7 = V_350 -> V_96 ;
break;
default:
break;
}
return 0 ;
}
int F_34 ( const char T_2 * V_9 , unsigned long V_2 ,
int * V_10 )
{
return F_4 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_152 ( struct V_50 * V_51 , long V_10 , int V_11 )
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
F_28 ( V_51 , L_92 , V_13 ) ;
else
F_28 ( V_51 , L_92 , V_13 / 10 ) ;
}
F_28 ( V_51 , L_54 ) ;
return 0 ;
}
int F_153 ( const char T_2 * V_9 , unsigned long V_2 ,
T_1 * V_10 )
{
return F_154 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_154 ( const char * V_9 , unsigned long V_2 ,
T_1 * V_10 , int V_11 )
{
char V_19 [ 22 ] , * V_20 , * V_21 ;
T_1 V_360 , V_361 = 0 , V_230 ;
unsigned V_362 = 1 ;
int V_363 = 1 ;
if ( V_2 > ( sizeof( V_19 ) - 1 ) )
return - V_15 ;
if ( F_5 ( V_19 , V_9 , V_2 ) )
return - V_22 ;
V_19 [ V_2 ] = '\0' ;
V_21 = V_19 ;
if ( * V_21 == '-' ) {
V_363 = - 1 ;
V_21 ++ ;
}
V_360 = F_155 ( V_21 , & V_20 , 10 ) ;
if ( V_21 == V_20 )
return - V_15 ;
if ( * V_20 == '.' ) {
int V_6 ;
V_21 = V_20 + 1 ;
if ( strlen ( V_21 ) > 10 )
V_21 [ 10 ] = '\0' ;
V_361 = F_155 ( V_21 , & V_20 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_20 - V_21 ) ; V_6 ++ )
V_362 *= 10 ;
}
V_230 = 1 ;
switch ( tolower ( * V_20 ) ) {
case 'p' :
V_230 <<= 10 ;
case 't' :
V_230 <<= 10 ;
case 'g' :
V_230 <<= 10 ;
case 'm' :
V_230 <<= 10 ;
case 'k' :
V_230 <<= 10 ;
}
if ( V_230 > 1 )
V_11 = V_230 ;
V_361 *= V_11 ;
F_64 ( V_361 , V_362 ) ;
* V_10 = V_363 * ( V_360 * V_11 + V_361 ) ;
return 0 ;
}
static char * F_156 ( const char * V_364 , const char * V_365 , T_9 V_210 )
{
T_9 V_366 ;
V_366 = strlen ( V_365 ) ;
if ( ! V_366 )
return ( char * ) V_364 ;
while ( V_210 >= V_366 ) {
V_210 -- ;
if ( ! memcmp ( V_364 , V_365 , V_366 ) )
return ( char * ) V_364 ;
V_364 ++ ;
}
return NULL ;
}
char * F_157 ( const char * V_9 , const char * V_28 ,
T_9 * V_2 )
{
char * V_10 ;
T_9 V_367 = * V_2 ;
V_10 = F_156 ( V_9 , V_28 , V_367 ) ;
if ( V_10 == NULL )
return ( char * ) V_9 ;
V_10 += strlen ( V_28 ) ;
while ( V_10 < V_9 + V_367 && isspace ( * V_10 ) )
V_10 ++ ;
* V_2 = 0 ;
while ( V_10 < V_9 + V_367 && isalnum ( * V_10 ) ) {
++ * V_2 ;
++ V_10 ;
}
return V_10 - * V_2 ;
}
int F_158 ( struct V_26 * V_37 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_368 ,
void * V_29 )
{
struct V_26 * V_39 ;
F_23 ( ( V_368 -> V_35 == NULL ) == ( ( V_33 & 0222 ) == 0 ) ) ;
V_39 = F_13 ( V_28 , V_33 , V_37 , V_368 , V_29 ) ;
if ( V_39 == NULL )
return - V_36 ;
return 0 ;
}
int F_159 ( struct V_58 * V_62 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_368 ,
void * V_29 )
{
return F_158 ( V_62 -> V_177 , V_28 ,
V_33 , V_368 , V_29 ) ;
}
void F_160 ( struct V_369 * V_370 , unsigned int V_371 )
{
if ( V_371 >= V_372 )
V_371 = V_372 - 1 ;
F_60 ( & V_370 -> V_373 ) ;
V_370 -> V_374 [ V_371 ] ++ ;
F_63 ( & V_370 -> V_373 ) ;
}
void F_161 ( struct V_369 * V_370 , unsigned int V_371 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; ( ( 1 << V_10 ) < V_371 ) && ( V_10 <= V_372 ) ; V_10 ++ )
;
F_160 ( V_370 , V_10 ) ;
}
unsigned long F_162 ( struct V_369 * V_370 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_372 ; V_6 ++ )
V_7 += V_370 -> V_374 [ V_6 ] ;
return V_7 ;
}
void F_163 ( struct V_369 * V_370 )
{
F_60 ( & V_370 -> V_373 ) ;
memset ( V_370 -> V_374 , 0 , sizeof( V_370 -> V_374 ) ) ;
F_63 ( & V_370 -> V_373 ) ;
}
int F_164 ( struct V_50 * V_51 , void * V_29 )
{
struct V_58 * V_62 = V_29 ;
struct V_375 * V_81 = & V_62 -> V_80 . V_81 ;
F_165 ( & V_81 -> V_376 ) ;
F_28 ( V_51 , L_9 , V_81 -> V_377 ) ;
F_166 ( & V_81 -> V_376 ) ;
return 0 ;
}
