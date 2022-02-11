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
struct V_26 * F_16 ( const char * V_28 , struct V_26 * V_37 ,
const char * V_38 , ... )
{
struct V_26 * V_32 ;
char * V_39 ;
T_4 V_40 ;
if ( V_37 == NULL || V_38 == NULL )
return NULL ;
V_39 = F_17 ( V_41 + 1 , V_42 ) ;
if ( ! V_39 )
return NULL ;
va_start ( V_40 , V_38 ) ;
vsnprintf ( V_39 , V_41 , V_38 , V_40 ) ;
va_end ( V_40 ) ;
V_32 = F_18 ( V_28 , V_37 , V_39 ) ;
if ( F_14 ( V_32 ) ) {
F_15 ( L_6 ,
V_28 , V_39 ) ;
V_32 = NULL ;
}
F_19 ( V_39 ) ;
return V_32 ;
}
int F_20 ( struct V_26 * V_37 ,
struct V_43 * V_44 ,
void * V_29 )
{
if ( F_14 ( V_37 ) || F_14 ( V_44 ) )
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
V_32 = F_13 ( V_44 -> V_28 , V_33 , V_37 ,
V_44 -> V_29 ? : V_29 ,
V_44 -> V_31 ? : & V_46
) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_21 ( V_32 ) : - V_36 ;
V_44 ++ ;
}
return 0 ;
}
void F_22 ( struct V_26 * * V_47 )
{
F_23 ( * V_47 ) ;
* V_47 = NULL ;
}
struct V_26 * F_24 ( const char * V_28 ,
struct V_26 * V_37 ,
struct V_43 * V_44 , void * V_29 )
{
struct V_26 * V_32 ;
V_32 = F_25 ( V_28 , V_37 ) ;
if ( F_14 ( V_32 ) ) {
V_32 = V_32 ? : F_12 ( - V_36 ) ;
goto V_48;
}
if ( ! F_14 ( V_44 ) ) {
int V_49 ;
V_49 = F_20 ( V_32 , V_44 , V_29 ) ;
if ( V_49 != 0 ) {
F_26 ( V_32 ) ;
V_32 = F_12 ( V_49 ) ;
}
}
V_48:
return V_32 ;
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
char V_53 [ V_41 + 1 ] , * V_20 ;
unsigned long V_54 ;
V_53 [ V_41 ] = '\0' ;
if ( F_5 ( V_53 , V_9 , V_41 ) )
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
F_32 ( V_55 != NULL ) ;
F_28 ( V_51 , L_9 , F_33 ( V_55 ) ) ;
return 0 ;
}
int F_34 ( struct V_25 * V_25 , const char T_2 * V_9 ,
unsigned long V_2 , void * V_29 )
{
T_5 * V_56 = V_29 ;
int V_10 = 0 ;
int V_49 ;
V_49 = F_35 ( V_9 , V_2 , & V_10 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_10 <= 0 )
return - V_57 ;
F_36 ( V_56 , V_10 ) ;
return V_2 ;
}
static T_6 F_37 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
return sprintf ( V_62 , L_10 , V_64 -> V_66 . V_67 ) ;
}
int F_39 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_68 = V_29 ;
F_32 ( V_68 != NULL ) ;
F_28 ( V_51 , L_10 , V_68 -> V_69 ) ;
return 0 ;
}
static T_6 F_40 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 )
return sprintf ( V_62 , L_7 , V_71 . V_75 ) ;
return V_49 ;
}
static T_6 F_42 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 ) {
T_7 V_76 = V_71 . V_75 >> 10 ;
T_1 V_77 = V_71 . V_78 ;
while ( V_76 >>= 1 )
V_77 <<= 1 ;
return sprintf ( V_62 , L_8 , V_77 ) ;
}
return V_49 ;
}
static T_6 F_43 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 ) {
T_7 V_76 = V_71 . V_75 >> 10 ;
T_1 V_77 = V_71 . V_79 ;
while ( V_76 >>= 1 )
V_77 <<= 1 ;
return sprintf ( V_62 , L_8 , V_77 ) ;
}
return V_49 ;
}
static T_6 F_44 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 ) {
T_7 V_76 = V_71 . V_75 >> 10 ;
T_1 V_77 = V_71 . V_80 ;
while ( V_76 >>= 1 )
V_77 <<= 1 ;
return sprintf ( V_62 , L_8 , V_77 ) ;
}
return V_49 ;
}
static T_6 F_45 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 )
return sprintf ( V_62 , L_8 , V_71 . V_81 ) ;
return V_49 ;
}
static T_6 F_46 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
struct V_70 V_71 ;
int V_49 = V_70 ( NULL , V_64 -> V_72 , & V_71 ,
F_41 ( - V_73 ) ,
V_74 ) ;
if ( ! V_49 )
return sprintf ( V_62 , L_8 , V_71 . V_82 ) ;
return V_49 ;
}
int F_47 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_64 = V_29 ;
struct V_83 * V_84 ;
char * V_85 = NULL ;
F_32 ( V_64 != NULL ) ;
F_48 ( V_64 ) ;
V_84 = V_64 -> V_86 . V_87 . V_88 ;
V_85 = F_49 ( V_84 -> V_89 ) ;
F_28 ( V_51 , L_11 ,
F_50 ( V_64 ) , V_85 ,
V_84 -> V_90 ? L_12 : L_2 ) ;
F_51 ( V_64 ) ;
return 0 ;
}
int F_52 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_64 = V_29 ;
struct V_91 * V_92 ;
F_32 ( V_64 != NULL ) ;
F_48 ( V_64 ) ;
V_92 = V_64 -> V_86 . V_87 . V_88 -> V_93 ;
if ( V_92 && V_64 -> V_86 . V_87 . V_88 )
F_28 ( V_51 , L_10 , V_92 -> V_94 . V_67 ) ;
else
F_53 ( V_51 , L_13 ) ;
F_51 ( V_64 ) ;
return 0 ;
}
void F_54 ( struct V_95 * V_96 , int V_97 ,
struct V_98 * V_99 )
{
unsigned int V_100 ;
struct V_98 * V_101 ;
int V_6 ;
unsigned long V_3 = 0 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
if ( V_96 == NULL ) {
V_99 -> V_102 = 1 ;
return;
}
V_99 -> V_103 = V_104 ;
V_100 = F_55 ( V_96 , V_105 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ ) {
if ( V_96 -> V_106 [ V_6 ] == NULL )
continue;
V_101 = F_56 ( V_96 , V_6 , V_97 ) ;
V_99 -> V_102 += V_101 -> V_102 ;
V_99 -> V_107 += V_101 -> V_107 ;
if ( V_101 -> V_103 < V_99 -> V_103 )
V_99 -> V_103 = V_101 -> V_103 ;
if ( V_101 -> V_108 > V_99 -> V_108 )
V_99 -> V_108 = V_101 -> V_108 ;
V_99 -> V_109 += V_101 -> V_109 ;
}
F_57 ( V_96 , V_105 , & V_3 ) ;
}
static int F_58 ( struct V_83 * V_84 , struct V_50 * V_51 )
{
bool V_110 = true ;
if ( V_84 -> V_111 -> V_112 ) {
F_28 ( V_51 , L_14 ) ;
V_110 = false ;
}
F_59 ( V_113 , V_110 ) ;
V_110 = false ;
F_59 ( V_114 , V_110 ) ;
F_59 ( V_115 , V_110 ) ;
F_59 ( V_116 , V_110 ) ;
return 0 ;
}
static void F_60 ( struct V_50 * V_51 , T_1 V_3 , char * V_4 )
{
T_1 V_5 = 1 ;
int V_6 ;
bool V_110 = true ;
for ( V_6 = 0 ; V_8 [ V_6 ] != NULL ; V_6 ++ , V_5 <<= 1 ) {
if ( V_3 & V_5 ) {
F_28 ( V_51 , L_1 ,
V_110 ? V_4 : L_2 , V_8 [ V_6 ] ) ;
V_110 = false ;
}
}
if ( V_3 & ~ ( V_5 - 1 ) )
F_28 ( V_51 , L_3 ,
V_110 ? V_4 : L_2 , V_3 & ~ ( V_5 - 1 ) ) ;
}
int F_61 ( struct V_50 * V_51 , void * V_29 )
{
struct V_98 V_7 ;
struct V_117 * V_118 ;
struct V_63 * V_64 = (struct V_63 * ) V_29 ;
struct V_83 * V_84 ;
struct V_119 * V_92 ;
int V_120 ;
int V_121 ;
int V_122 = 0 ;
F_32 ( V_64 != NULL ) ;
F_48 ( V_64 ) ;
V_84 = V_64 -> V_86 . V_87 . V_88 ;
F_28 ( V_51 ,
L_15
L_16
L_17
L_18
L_19
L_20 ,
V_64 -> V_69 ,
F_50 ( V_64 ) ,
F_49 ( V_84 -> V_89 ) ,
V_84 -> V_123 . V_124 ) ;
F_60 ( V_51 , V_84 -> V_123 . V_125 , L_21 ) ;
F_28 ( V_51 ,
L_22
L_23 ) ;
F_58 ( V_84 , V_51 ) ;
F_28 ( V_51 ,
L_22
L_24
L_25 ) ;
F_62 ( & V_84 -> V_126 ) ;
V_120 = 0 ;
F_63 (conn, &imp->imp_conn_list, oic_item) {
F_28 ( V_51 , L_1 , V_120 ? L_21 : L_2 ,
F_64 ( V_92 -> V_127 -> V_128 . V_129 ) ) ;
V_120 ++ ;
}
F_28 ( V_51 ,
L_22
L_26
L_27
L_28
L_29 ,
V_84 -> V_93 == NULL ? L_30 :
F_64 ( V_84 -> V_93 -> V_128 . V_129 ) ,
V_84 -> V_130 ,
V_84 -> V_131 ,
F_33 ( & V_84 -> V_132 ) ) ;
F_65 ( & V_84 -> V_126 ) ;
if ( V_64 -> V_133 == NULL )
goto V_134;
V_118 = & V_64 -> V_133 -> V_135 [ V_136 ] ;
F_54 ( V_64 -> V_133 , V_136 , & V_7 ) ;
if ( V_7 . V_102 != 0 ) {
T_1 V_137 = V_7 . V_107 ;
F_66 ( V_137 , V_7 . V_102 ) ;
V_7 . V_107 = V_137 ;
} else
V_7 . V_107 = 0 ;
F_28 ( V_51 ,
L_31
L_32
L_33
L_34
L_35 ,
F_33 ( & V_84 -> V_138 ) ,
F_33 ( & V_84 -> V_139 ) ,
F_33 ( & V_84 -> V_140 ) ,
V_7 . V_107 , V_118 -> V_141 ) ;
V_121 = 0 ;
for ( V_120 = 0 ; V_120 < V_142 ; V_120 ++ ) {
if ( V_84 -> V_143 . V_144 [ V_120 ] == 0 )
break;
V_121 = F_67 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_28 ( V_51 ,
L_36
L_37
L_38 ,
V_121 ,
F_68 ( & V_84 -> V_143 . V_145 ) ) ;
F_28 ( V_51 ,
L_39
L_40
L_41
L_42 ,
V_84 -> V_146 ,
V_84 -> V_147 ,
V_84 -> V_148 ) ;
for ( V_122 = 0 ; V_122 <= 1 ; V_122 ++ ) {
F_54 ( V_64 -> V_133 ,
V_149 + V_150 + V_122 ,
& V_7 ) ;
if ( V_7 . V_107 > 0 && V_7 . V_102 > 0 ) {
T_1 V_137 = V_7 . V_107 ;
F_66 ( V_137 , V_7 . V_102 ) ;
V_7 . V_107 = V_137 ;
F_28 ( V_51 ,
L_43
L_44 ,
V_122 ? L_45 : L_46 ,
V_7 . V_107 ) ;
}
V_121 = ( int ) V_7 . V_107 ;
V_120 = F_69 ( V_151 + V_122 ) + V_152 ;
V_118 = & V_64 -> V_133 -> V_135 [ V_120 ] ;
F_54 ( V_64 -> V_133 , V_120 , & V_7 ) ;
if ( V_7 . V_107 > 0 && V_7 . V_102 != 0 ) {
T_1 V_137 = V_7 . V_107 ;
F_66 ( V_137 , V_7 . V_102 ) ;
V_7 . V_107 = V_137 ;
F_28 ( V_51 ,
L_47 ,
V_118 -> V_141 , V_7 . V_107 ) ;
V_120 = ( int ) V_7 . V_107 ;
if ( V_120 > 0 )
F_28 ( V_51 ,
L_48 ,
V_121 / V_120 , ( 100 * V_121 / V_120 ) % 100 ) ;
}
}
V_134:
F_51 ( V_64 ) ;
return 0 ;
}
int F_70 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_64 = (struct V_63 * ) V_29 ;
struct V_83 * V_84 ;
int V_120 , V_121 ;
F_32 ( V_64 != NULL ) ;
F_48 ( V_64 ) ;
V_84 = V_64 -> V_86 . V_87 . V_88 ;
F_28 ( V_51 , L_49 ,
F_49 ( V_84 -> V_89 ) ) ;
F_28 ( V_51 , L_50 ) ;
V_121 = V_84 -> V_153 ;
for ( V_120 = 0 ; V_120 < V_154 ; V_120 ++ ) {
struct V_155 * V_156 =
& V_84 -> V_157 [ ( V_121 + V_120 ) % V_154 ] ;
if ( V_156 -> V_158 == 0 )
continue;
F_28 ( V_51 , L_51 V_159 L_52 ,
V_156 -> V_160 ,
F_49 ( V_156 -> V_158 ) ) ;
}
F_51 ( V_64 ) ;
return 0 ;
}
int F_71 ( struct V_50 * V_51 , struct V_161 * V_162 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_163 ; V_6 ++ )
F_28 ( V_51 , L_53 , V_162 -> V_164 [ V_6 ] ) ;
F_28 ( V_51 , L_54 ) ;
return 0 ;
}
int F_72 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_64 = (struct V_63 * ) V_29 ;
struct V_83 * V_84 ;
unsigned int V_165 , V_166 ;
T_8 V_167 , V_168 ;
struct V_169 V_170 ;
int V_6 ;
F_32 ( V_64 != NULL ) ;
F_48 ( V_64 ) ;
V_84 = V_64 -> V_86 . V_87 . V_88 ;
V_167 = F_73 () ;
F_74 ( & V_170 , V_167 - V_84 -> V_171 ) ;
F_28 ( V_51 , L_55 V_172 L_56 ,
L_57 , V_84 -> V_171 , F_75 ( & V_170 ) ) ;
V_165 = F_68 ( & V_84 -> V_143 . V_145 ) ;
V_166 = V_84 -> V_143 . V_145 . V_173 ;
V_168 = V_84 -> V_143 . V_145 . V_174 ;
F_74 ( & V_170 , V_167 - V_168 ) ;
F_28 ( V_51 , L_58 V_172 L_59 ,
L_60 , V_165 , V_166 , V_168 , F_75 ( & V_170 ) ) ;
F_71 ( V_51 , & V_84 -> V_143 . V_145 ) ;
for ( V_6 = 0 ; V_6 < V_142 ; V_6 ++ ) {
if ( V_84 -> V_143 . V_144 [ V_6 ] == 0 )
break;
V_165 = F_68 ( & V_84 -> V_143 . V_175 [ V_6 ] ) ;
V_166 = V_84 -> V_143 . V_175 [ V_6 ] . V_173 ;
V_168 = V_84 -> V_143 . V_175 [ V_6 ] . V_174 ;
F_74 ( & V_170 , V_167 - V_168 ) ;
F_28 ( V_51 , L_61
V_172 L_59 , V_84 -> V_143 . V_144 [ V_6 ] ,
V_165 , V_166 , V_168 , F_75 ( & V_170 ) ) ;
F_71 ( V_51 , & V_84 -> V_143 . V_175 [ V_6 ] ) ;
}
F_51 ( V_64 ) ;
return 0 ;
}
int F_76 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_64 = V_29 ;
T_1 V_3 ;
F_48 ( V_64 ) ;
V_3 = V_64 -> V_86 . V_87 . V_88 -> V_123 . V_125 ;
F_28 ( V_51 , L_62 , V_3 ) ;
F_60 ( V_51 , V_3 , L_54 ) ;
F_28 ( V_51 , L_54 ) ;
F_51 ( V_64 ) ;
return 0 ;
}
static void F_77 ( struct V_58 * V_59 )
{
struct V_63 * V_64 = F_38 ( V_59 , struct V_63 ,
V_65 ) ;
F_78 ( & V_64 -> V_176 ) ;
}
int F_79 ( struct V_63 * V_64 , struct V_43 * V_44 ,
struct V_177 * V_178 )
{
int V_49 = 0 ;
F_80 ( & V_64 -> V_176 ) ;
V_49 = F_81 ( & V_64 -> V_65 , & V_179 ,
V_64 -> V_180 -> V_181 ,
L_63 , V_64 -> V_69 ) ;
if ( V_49 )
return V_49 ;
if ( V_178 ) {
V_49 = F_82 ( & V_64 -> V_65 , V_178 ) ;
if ( V_49 ) {
F_83 ( & V_64 -> V_65 ) ;
return V_49 ;
}
}
V_64 -> V_182 = F_24 ( V_64 -> V_69 ,
V_64 -> V_180 -> V_183 ,
V_44 , V_64 ) ;
if ( F_14 ( V_64 -> V_182 ) ) {
V_49 = V_64 -> V_182 ? F_21 ( V_64 -> V_182 )
: - V_36 ;
F_15 ( L_64 ,
V_49 , V_64 -> V_69 ) ;
V_64 -> V_182 = NULL ;
}
return V_49 ;
}
int F_84 ( struct V_63 * V_64 )
{
if ( ! V_64 )
return - V_15 ;
if ( ! F_14 ( V_64 -> V_182 ) )
F_22 ( & V_64 -> V_182 ) ;
F_83 ( & V_64 -> V_65 ) ;
F_85 ( & V_64 -> V_176 ) ;
return 0 ;
}
int F_86 ( struct V_95 * V_96 , unsigned int V_184 )
{
struct V_98 * V_185 ;
unsigned int V_186 ;
int V_49 = - V_36 ;
unsigned long V_3 = 0 ;
int V_6 ;
F_32 ( V_96 -> V_106 [ V_184 ] == NULL ) ;
F_32 ( ( V_96 -> V_187 & V_188 ) == 0 ) ;
V_186 = F_87 ( V_96 ) ;
F_88 ( V_96 -> V_106 [ V_184 ] , V_186 ) ;
if ( V_96 -> V_106 [ V_184 ] != NULL ) {
V_49 = 0 ;
if ( F_89 ( V_96 -> V_189 <= V_184 ) ) {
if ( V_96 -> V_187 & V_190 )
F_90 ( & V_96 -> V_191 , V_3 ) ;
else
F_62 ( & V_96 -> V_191 ) ;
if ( V_96 -> V_189 <= V_184 )
V_96 -> V_189 = V_184 + 1 ;
if ( V_96 -> V_187 & V_190 )
F_91 ( & V_96 -> V_191 , V_3 ) ;
else
F_65 ( & V_96 -> V_191 ) ;
}
for ( V_6 = 0 ; V_6 < V_96 -> V_192 ; ++ V_6 ) {
V_185 = F_56 ( V_96 , V_184 , V_6 ) ;
V_185 -> V_103 = V_104 ;
}
}
return V_49 ;
}
struct V_95 * F_92 ( unsigned int V_193 ,
enum V_194 V_3 )
{
struct V_95 * V_96 ;
unsigned int V_100 ;
unsigned int V_186 = 0 ;
int V_6 ;
if ( V_193 == 0 )
return NULL ;
if ( V_195 != 0 )
V_3 |= V_188 ;
if ( V_3 & V_188 )
V_100 = 1 ;
else
V_100 = F_93 () ;
F_94 ( V_96 , F_95 ( F_96 ( * V_96 ) , V_106 [ V_100 ] ) ) ;
if ( V_96 == NULL )
return NULL ;
V_96 -> V_192 = V_193 ;
V_96 -> V_187 = V_3 ;
F_97 ( & V_96 -> V_191 ) ;
F_94 ( V_96 -> V_135 ,
V_96 -> V_192 * sizeof( struct V_117 ) ) ;
if ( V_96 -> V_135 == NULL )
goto V_196;
if ( ( V_3 & V_188 ) != 0 ) {
V_186 = F_87 ( V_96 ) ;
F_88 ( V_96 -> V_106 [ 0 ] , V_186 ) ;
if ( V_96 -> V_106 [ 0 ] == NULL )
goto V_196;
V_96 -> V_189 = 1 ;
} else if ( ( V_3 & V_190 ) != 0 ) {
for ( V_6 = 0 ; V_6 < V_100 ; ++ V_6 )
if ( F_86 ( V_96 , V_6 ) < 0 )
goto V_196;
}
return V_96 ;
V_196:
F_98 ( & V_96 ) ;
return NULL ;
}
void F_98 ( struct V_95 * * V_197 )
{
struct V_95 * V_96 = * V_197 ;
unsigned int V_100 ;
unsigned int V_186 ;
unsigned int V_6 ;
if ( V_96 == NULL || V_96 -> V_192 == 0 )
return;
* V_197 = NULL ;
if ( V_96 -> V_187 & V_188 )
V_100 = 1 ;
else
V_100 = F_93 () ;
V_186 = F_87 ( V_96 ) ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ )
if ( V_96 -> V_106 [ V_6 ] != NULL )
F_99 ( V_96 -> V_106 [ V_6 ] , V_186 ) ;
if ( V_96 -> V_135 != NULL )
F_99 ( V_96 -> V_135 , V_96 -> V_192 *
sizeof( struct V_117 ) ) ;
F_99 ( V_96 , F_95 ( F_96 ( * V_96 ) , V_106 [ V_100 ] ) ) ;
}
void F_100 ( struct V_95 * V_96 )
{
struct V_98 * V_101 ;
int V_6 ;
int V_120 ;
unsigned int V_100 ;
unsigned long V_3 = 0 ;
V_100 = F_55 ( V_96 , V_105 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ ) {
if ( V_96 -> V_106 [ V_6 ] == NULL )
continue;
for ( V_120 = 0 ; V_120 < V_96 -> V_192 ; V_120 ++ ) {
V_101 = F_56 ( V_96 , V_6 , V_120 ) ;
V_101 -> V_102 = 0 ;
V_101 -> V_103 = V_104 ;
V_101 -> V_108 = 0 ;
V_101 -> V_109 = 0 ;
V_101 -> V_107 = 0 ;
if ( V_96 -> V_187 & V_190 )
V_101 -> V_198 = 0 ;
}
}
F_57 ( V_96 , V_105 , & V_3 ) ;
}
static T_6 F_101 ( struct V_25 * V_25 ,
const char T_2 * V_62 ,
T_9 V_199 , T_10 * V_200 )
{
struct V_50 * V_201 = V_25 -> V_202 ;
struct V_95 * V_96 = V_201 -> V_203 ;
F_100 ( V_96 ) ;
return V_199 ;
}
static void * F_102 ( struct V_50 * V_52 , T_10 * V_204 )
{
struct V_95 * V_96 = V_52 -> V_203 ;
return ( * V_204 < V_96 -> V_192 ) ? V_204 : NULL ;
}
static void F_103 ( struct V_50 * V_52 , void * V_205 )
{
}
static void * F_104 ( struct V_50 * V_52 , void * V_205 , T_10 * V_204 )
{
( * V_204 ) ++ ;
return F_102 ( V_52 , V_204 ) ;
}
static int F_105 ( struct V_50 * V_52 , void * V_205 )
{
struct V_95 * V_96 = V_52 -> V_203 ;
struct V_117 * V_206 ;
struct V_98 V_207 ;
int V_97 = * ( T_10 * ) V_205 ;
if ( V_97 == 0 ) {
struct V_208 V_167 ;
F_106 ( & V_167 ) ;
F_28 ( V_52 , L_65 ,
L_66 ,
V_167 . V_209 , ( unsigned long ) V_167 . V_210 ) ;
}
V_206 = & V_96 -> V_135 [ V_97 ] ;
F_54 ( V_96 , V_97 , & V_207 ) ;
if ( V_207 . V_102 != 0 ) {
F_28 ( V_52 , L_67 ,
V_206 -> V_211 , V_207 . V_102 , V_206 -> V_141 ) ;
if ( ( V_206 -> V_212 & V_213 ) &&
( V_207 . V_102 > 0 ) ) {
F_28 ( V_52 , L_68 ,
V_207 . V_103 , V_207 . V_108 , V_207 . V_107 ) ;
if ( V_206 -> V_212 & V_214 )
F_28 ( V_52 , L_69 , V_207 . V_109 ) ;
}
F_107 ( V_52 , '\n' ) ;
}
return 0 ;
}
static int F_108 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_50 * V_201 ;
int V_49 ;
V_49 = F_109 ( V_25 , & V_215 ) ;
if ( V_49 )
return V_49 ;
V_201 = V_25 -> V_202 ;
V_201 -> V_203 = V_24 -> V_216 ;
return 0 ;
}
int F_110 ( struct V_26 * V_37 , const char * V_28 ,
struct V_95 * V_96 )
{
struct V_26 * V_32 ;
F_32 ( ! F_14 ( V_37 ) ) ;
V_32 = F_13 ( V_28 , 0644 , V_37 , V_96 ,
& V_217 ) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_21 ( V_32 ) : - V_36 ;
return 0 ;
}
void F_111 ( struct V_95 * V_96 , int V_218 ,
unsigned V_219 , const char * V_28 , const char * V_220 )
{
struct V_117 * V_118 ;
struct V_98 * V_101 ;
unsigned long V_3 = 0 ;
unsigned int V_6 ;
unsigned int V_221 ;
F_32 ( V_96 != NULL ) ;
V_118 = & V_96 -> V_135 [ V_218 ] ;
F_112 ( V_118 != NULL , L_70 ,
V_218 , V_28 , V_220 ) ;
V_118 -> V_212 = V_219 ;
V_118 -> V_211 = V_28 ;
V_118 -> V_141 = V_220 ;
V_221 = F_55 ( V_96 , V_105 , & V_3 ) ;
for ( V_6 = 0 ; V_6 < V_221 ; ++ V_6 ) {
if ( V_96 -> V_106 [ V_6 ] == NULL )
continue;
V_101 = F_56 ( V_96 , V_6 , V_218 ) ;
V_101 -> V_102 = 0 ;
V_101 -> V_103 = V_104 ;
V_101 -> V_108 = 0 ;
V_101 -> V_109 = 0 ;
V_101 -> V_107 = 0 ;
if ( ( V_96 -> V_187 & V_190 ) != 0 )
V_101 -> V_198 = 0 ;
}
F_57 ( V_96 , V_105 , & V_3 ) ;
}
void F_113 ( int V_222 , struct V_95 * V_96 )
{
F_114 ( V_222 , V_96 , V_223 ) ;
F_114 ( V_222 , V_96 , V_224 ) ;
F_114 ( V_222 , V_96 , V_225 ) ;
F_114 ( V_222 , V_96 , V_226 ) ;
F_114 ( V_222 , V_96 , V_227 ) ;
F_114 ( V_222 , V_96 , V_228 ) ;
F_114 ( V_222 , V_96 , V_229 ) ;
F_114 ( V_222 , V_96 , V_230 ) ;
F_114 ( V_222 , V_96 , V_231 ) ;
F_114 ( V_222 , V_96 , V_232 ) ;
F_114 ( V_222 , V_96 , V_233 ) ;
F_114 ( V_222 , V_96 , V_234 ) ;
F_114 ( V_222 , V_96 , V_235 ) ;
F_114 ( V_222 , V_96 , V_236 ) ;
F_114 ( V_222 , V_96 , V_237 ) ;
F_114 ( V_222 , V_96 , V_238 ) ;
F_114 ( V_222 , V_96 , V_239 ) ;
F_114 ( V_222 , V_96 , V_240 ) ;
F_114 ( V_222 , V_96 , V_241 ) ;
F_114 ( V_222 , V_96 , V_242 ) ;
F_114 ( V_222 , V_96 , V_243 ) ;
F_114 ( V_222 , V_96 , V_244 ) ;
F_114 ( V_222 , V_96 , V_245 ) ;
F_114 ( V_222 , V_96 , V_246 ) ;
F_114 ( V_222 , V_96 , V_247 ) ;
F_114 ( V_222 , V_96 , V_248 ) ;
F_114 ( V_222 , V_96 , V_249 ) ;
F_114 ( V_222 , V_96 , V_250 ) ;
F_114 ( V_222 , V_96 , V_251 ) ;
F_114 ( V_222 , V_96 , V_252 ) ;
F_114 ( V_222 , V_96 , V_253 ) ;
F_114 ( V_222 , V_96 , V_254 ) ;
F_114 ( V_222 , V_96 , V_255 ) ;
F_114 ( V_222 , V_96 , V_256 ) ;
F_114 ( V_222 , V_96 , V_257 ) ;
F_114 ( V_222 , V_96 , V_258 ) ;
F_114 ( V_222 , V_96 , V_259 ) ;
F_114 ( V_222 , V_96 , V_260 ) ;
F_114 ( V_222 , V_96 , V_261 ) ;
F_114 ( V_222 , V_96 , V_262 ) ;
F_114 ( V_222 , V_96 , V_263 ) ;
F_114 ( V_222 , V_96 , V_264 ) ;
F_114 ( V_222 , V_96 , V_265 ) ;
F_114 ( V_222 , V_96 , V_266 ) ;
F_114 ( V_222 , V_96 , V_267 ) ;
F_114 ( V_222 , V_96 , V_268 ) ;
F_114 ( V_222 , V_96 , V_269 ) ;
}
int F_115 ( struct V_63 * V_64 , unsigned V_222 )
{
struct V_95 * V_96 ;
unsigned int V_270 ;
int V_49 , V_6 ;
F_32 ( V_64 -> V_271 == NULL ) ;
F_32 ( V_64 -> V_182 != NULL ) ;
F_32 ( V_64 -> V_272 == 0 ) ;
V_270 = ( ( int ) sizeof( * V_64 -> V_180 -> V_273 ) / sizeof( void * ) ) +
V_222 - 1 ;
V_96 = F_92 ( V_270 , 0 ) ;
if ( V_96 == NULL )
return - V_36 ;
F_113 ( V_222 , V_96 ) ;
for ( V_6 = V_222 ; V_6 < V_270 ; V_6 ++ ) {
F_112 ( V_96 -> V_135 [ V_6 ] . V_211 != NULL ,
L_71 ,
V_6 - V_222 ) ;
}
V_49 = F_110 ( V_64 -> V_182 , L_72 , V_96 ) ;
if ( V_49 < 0 ) {
F_98 ( & V_96 ) ;
} else {
V_64 -> V_271 = V_96 ;
V_64 -> V_272 = V_222 ;
}
return V_49 ;
}
void F_116 ( struct V_63 * V_64 )
{
if ( V_64 -> V_271 )
F_98 ( & V_64 -> V_271 ) ;
}
void F_117 ( int V_222 , struct V_95 * V_96 )
{
F_118 ( V_222 , V_96 , V_274 ) ;
F_118 ( V_222 , V_96 , V_275 ) ;
F_118 ( V_222 , V_96 , V_255 ) ;
F_118 ( V_222 , V_96 , V_276 ) ;
F_118 ( V_222 , V_96 , V_246 ) ;
F_118 ( V_222 , V_96 , V_277 ) ;
F_118 ( V_222 , V_96 , V_278 ) ;
F_118 ( V_222 , V_96 , V_250 ) ;
F_118 ( V_222 , V_96 , V_279 ) ;
F_118 ( V_222 , V_96 , V_280 ) ;
F_118 ( V_222 , V_96 , V_281 ) ;
F_118 ( V_222 , V_96 , rename ) ;
F_118 ( V_222 , V_96 , V_282 ) ;
F_118 ( V_222 , V_96 , V_248 ) ;
F_118 ( V_222 , V_96 , V_283 ) ;
F_118 ( V_222 , V_96 , V_284 ) ;
F_118 ( V_222 , V_96 , V_285 ) ;
F_118 ( V_222 , V_96 , V_286 ) ;
F_118 ( V_222 , V_96 , V_287 ) ;
F_118 ( V_222 , V_96 , V_288 ) ;
F_118 ( V_222 , V_96 , V_289 ) ;
F_118 ( V_222 , V_96 , V_290 ) ;
F_118 ( V_222 , V_96 , V_291 ) ;
F_118 ( V_222 , V_96 , V_292 ) ;
F_118 ( V_222 , V_96 , V_293 ) ;
F_118 ( V_222 , V_96 , V_294 ) ;
F_118 ( V_222 , V_96 , V_295 ) ;
F_118 ( V_222 , V_96 , V_296 ) ;
F_118 ( V_222 , V_96 , V_297 ) ;
F_118 ( V_222 , V_96 , V_298 ) ;
F_118 ( V_222 , V_96 , V_299 ) ;
F_118 ( V_222 , V_96 , V_300 ) ;
}
int F_119 ( struct V_63 * V_64 ,
unsigned V_222 )
{
struct V_95 * V_96 ;
unsigned int V_270 ;
int V_49 , V_6 ;
F_32 ( V_64 -> V_301 == NULL ) ;
F_32 ( V_64 -> V_182 != NULL ) ;
F_32 ( V_64 -> V_302 == 0 ) ;
V_270 = 1 + F_120 ( V_300 ) +
V_222 ;
V_96 = F_92 ( V_270 , 0 ) ;
if ( V_96 == NULL )
return - V_36 ;
F_117 ( V_222 , V_96 ) ;
for ( V_6 = V_222 ; V_6 < V_270 ; V_6 ++ ) {
if ( V_96 -> V_135 [ V_6 ] . V_211 == NULL ) {
F_15 ( L_73 ,
V_6 - V_222 ) ;
F_121 () ;
}
}
V_49 = F_110 ( V_64 -> V_182 , L_74 , V_96 ) ;
if ( V_49 < 0 ) {
F_98 ( & V_96 ) ;
} else {
V_64 -> V_301 = V_96 ;
V_64 -> V_302 = V_222 ;
}
return V_49 ;
}
void F_122 ( struct V_63 * V_64 )
{
struct V_95 * V_96 = V_64 -> V_301 ;
if ( V_96 != NULL ) {
V_64 -> V_301 = NULL ;
V_64 -> V_302 = 0 ;
F_98 ( & V_96 ) ;
}
}
void F_123 ( struct V_95 * V_303 )
{
F_111 ( V_303 ,
V_304 - V_305 ,
0 , L_75 , L_76 ) ;
F_111 ( V_303 ,
V_306 - V_305 ,
0 , L_77 , L_76 ) ;
F_111 ( V_303 ,
V_307 - V_305 ,
0 , L_78 , L_76 ) ;
F_111 ( V_303 ,
V_308 - V_305 ,
0 , L_79 , L_76 ) ;
F_111 ( V_303 ,
V_309 - V_305 ,
0 , L_80 , L_76 ) ;
F_111 ( V_303 ,
V_310 - V_305 ,
0 , L_81 , L_76 ) ;
}
int F_124 ( struct V_311 * exp )
{
return 0 ;
}
T_11 F_125 ( struct V_98 * V_312 ,
struct V_117 * V_118 ,
enum V_194 V_3 ,
enum V_313 V_314 )
{
T_11 V_7 = 0 ;
if ( V_312 == NULL || V_118 == NULL )
return 0 ;
switch ( V_314 ) {
case V_315 :
V_7 = V_118 -> V_212 ;
break;
case V_316 :
V_7 = V_312 -> V_107 ;
if ( ( V_3 & V_190 ) != 0 )
V_7 += V_312 -> V_198 ;
break;
case V_317 :
V_7 = V_312 -> V_103 ;
break;
case V_318 :
V_7 = V_312 -> V_108 ;
break;
case V_319 :
V_7 = ( V_312 -> V_108 - V_312 -> V_103 ) / 2 ;
break;
case V_320 :
V_7 = V_312 -> V_109 ;
break;
case V_321 :
V_7 = V_312 -> V_102 ;
break;
default:
break;
}
return 0 ;
}
int F_35 ( const char T_2 * V_9 , unsigned long V_2 ,
int * V_10 )
{
return F_4 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_126 ( struct V_50 * V_51 , long V_10 , int V_11 )
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
F_28 ( V_51 , L_82 , V_13 ) ;
else
F_28 ( V_51 , L_82 , V_13 / 10 ) ;
}
F_28 ( V_51 , L_54 ) ;
return 0 ;
}
int F_127 ( const char T_2 * V_9 , unsigned long V_2 ,
T_1 * V_10 )
{
return F_128 ( V_9 , V_2 , V_10 , 1 ) ;
}
int F_128 ( const char * V_9 , unsigned long V_2 ,
T_1 * V_10 , int V_11 )
{
char V_19 [ 22 ] , * V_20 , * V_21 ;
T_1 V_322 , V_323 = 0 , V_220 ;
unsigned V_324 = 1 ;
int V_325 = 1 ;
if ( V_2 > ( sizeof( V_19 ) - 1 ) )
return - V_15 ;
if ( F_5 ( V_19 , V_9 , V_2 ) )
return - V_22 ;
V_19 [ V_2 ] = '\0' ;
V_21 = V_19 ;
if ( * V_21 == '-' ) {
V_325 = - 1 ;
V_21 ++ ;
}
V_322 = F_129 ( V_21 , & V_20 , 10 ) ;
if ( V_21 == V_20 )
return - V_15 ;
if ( * V_20 == '.' ) {
int V_6 ;
V_21 = V_20 + 1 ;
if ( strlen ( V_21 ) > 10 )
V_21 [ 10 ] = '\0' ;
V_323 = F_129 ( V_21 , & V_20 , 10 ) ;
for ( V_6 = 0 ; V_6 < ( V_20 - V_21 ) ; V_6 ++ )
V_324 *= 10 ;
}
V_220 = 1 ;
switch ( tolower ( * V_20 ) ) {
case 'p' :
V_220 <<= 10 ;
case 't' :
V_220 <<= 10 ;
case 'g' :
V_220 <<= 10 ;
case 'm' :
V_220 <<= 10 ;
case 'k' :
V_220 <<= 10 ;
}
if ( V_220 > 1 )
V_11 = V_220 ;
V_323 *= V_11 ;
F_66 ( V_323 , V_324 ) ;
* V_10 = V_325 * ( V_322 * V_11 + V_323 ) ;
return 0 ;
}
static char * F_130 ( const char * V_326 , const char * V_327 , T_9 V_199 )
{
T_9 V_328 ;
V_328 = strlen ( V_327 ) ;
if ( ! V_328 )
return ( char * ) V_326 ;
while ( V_199 >= V_328 ) {
V_199 -- ;
if ( ! memcmp ( V_326 , V_327 , V_328 ) )
return ( char * ) V_326 ;
V_326 ++ ;
}
return NULL ;
}
char * F_131 ( const char * V_9 , const char * V_28 ,
T_9 * V_2 )
{
char * V_10 ;
T_9 V_329 = * V_2 ;
V_10 = F_130 ( V_9 , V_28 , V_329 ) ;
if ( V_10 == NULL )
return ( char * ) V_9 ;
V_10 += strlen ( V_28 ) ;
while ( V_10 < V_9 + V_329 && isspace ( * V_10 ) )
V_10 ++ ;
* V_2 = 0 ;
while ( V_10 < V_9 + V_329 && isalnum ( * V_10 ) ) {
++ * V_2 ;
++ V_10 ;
}
return V_10 - * V_2 ;
}
int F_132 ( struct V_26 * V_37 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_330 ,
void * V_29 )
{
struct V_26 * V_32 ;
F_32 ( ( V_330 -> V_35 == NULL ) == ( ( V_33 & 0222 ) == 0 ) ) ;
V_32 = F_13 ( V_28 , V_33 , V_37 , V_29 , V_330 ) ;
if ( F_14 ( V_32 ) )
return V_32 ? F_21 ( V_32 ) : - V_36 ;
return 0 ;
}
int F_133 ( struct V_63 * V_68 ,
const char * V_28 ,
T_3 V_33 ,
const struct V_30 * V_330 ,
void * V_29 )
{
return F_132 ( V_68 -> V_182 , V_28 ,
V_33 , V_330 , V_29 ) ;
}
void F_134 ( struct V_331 * V_332 , unsigned int V_333 )
{
if ( V_333 >= V_334 )
V_333 = V_334 - 1 ;
F_62 ( & V_332 -> V_335 ) ;
V_332 -> V_336 [ V_333 ] ++ ;
F_65 ( & V_332 -> V_335 ) ;
}
void F_135 ( struct V_331 * V_332 , unsigned int V_333 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; ( ( 1 << V_10 ) < V_333 ) && ( V_10 <= V_334 ) ; V_10 ++ )
;
F_134 ( V_332 , V_10 ) ;
}
unsigned long F_136 ( struct V_331 * V_332 )
{
unsigned long V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_334 ; V_6 ++ )
V_7 += V_332 -> V_336 [ V_6 ] ;
return V_7 ;
}
void F_137 ( struct V_331 * V_332 )
{
F_62 ( & V_332 -> V_335 ) ;
memset ( V_332 -> V_336 , 0 , sizeof( V_332 -> V_336 ) ) ;
F_65 ( & V_332 -> V_335 ) ;
}
int F_138 ( struct V_50 * V_51 , void * V_29 )
{
struct V_63 * V_68 = V_29 ;
struct V_337 * V_87 = & V_68 -> V_86 . V_87 ;
F_139 ( & V_87 -> V_338 ) ;
F_28 ( V_51 , L_9 , V_87 -> V_339 ) ;
F_140 ( & V_87 -> V_338 ) ;
return 0 ;
}
T_6 F_141 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_340 * V_341 = F_38 ( V_61 , struct V_340 , V_61 ) ;
return V_341 -> V_342 ? V_341 -> V_342 ( V_59 , V_61 , V_62 ) : 0 ;
}
T_6 F_142 ( struct V_58 * V_59 , struct V_60 * V_61 ,
const char * V_62 , T_9 V_199 )
{
struct V_340 * V_341 = F_38 ( V_61 , struct V_340 , V_61 ) ;
return V_341 -> V_343 ? V_341 -> V_343 ( V_59 , V_61 , V_62 , V_199 ) : V_199 ;
}
