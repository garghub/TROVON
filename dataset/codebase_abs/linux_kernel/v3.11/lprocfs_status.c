int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
int F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_4 ( V_1 , V_2 ) ;
}
T_1 * F_5 ( struct V_3 * V_4 ,
char * V_5 , void * V_6 ,
struct V_7 * V_8 )
{
T_1 * V_9 ;
T_2 V_10 = 0 ;
if ( V_4 == NULL || V_5 == NULL || V_8 == NULL )
return F_6 ( - V_11 ) ;
if ( V_8 -> V_12 )
V_10 = 0444 ;
if ( V_8 -> V_13 )
V_10 |= 0200 ;
V_9 = F_7 ( V_5 , V_10 , V_4 , V_8 , V_6 ) ;
if ( ! V_9 ) {
F_8 ( L_1 , V_5 ) ;
return F_6 ( - V_14 ) ;
}
return V_9 ;
}
struct V_3 * F_9 ( const char * V_5 ,
struct V_3 * V_15 , const char * V_16 , ... )
{
struct V_3 * V_17 ;
char * V_18 ;
T_3 V_19 ;
if ( V_15 == NULL || V_16 == NULL )
return NULL ;
F_10 ( V_18 , V_20 + 1 ) ;
if ( V_18 == NULL )
return NULL ;
va_start ( V_19 , V_16 ) ;
vsnprintf ( V_18 , V_20 , V_16 , V_19 ) ;
va_end ( V_19 ) ;
V_17 = F_11 ( V_5 , V_15 , V_18 ) ;
if ( V_17 == NULL )
F_8 ( L_2 ,
V_5 , V_18 ) ;
F_12 ( V_18 , V_20 + 1 ) ;
return V_17 ;
}
int F_13 ( struct V_3 * V_4 , struct V_21 * V_22 ,
void * V_6 )
{
if ( V_4 == NULL || V_22 == NULL )
return - V_11 ;
while ( V_22 -> V_5 != NULL ) {
struct V_3 * V_9 ;
T_2 V_10 = 0 ;
if ( V_22 -> V_23 != 0000 ) {
V_10 = V_22 -> V_23 ;
} else if ( V_22 -> V_8 ) {
if ( V_22 -> V_8 -> V_12 )
V_10 = 0444 ;
if ( V_22 -> V_8 -> V_13 )
V_10 |= 0200 ;
}
V_9 = F_7 ( V_22 -> V_5 , V_10 , V_4 ,
V_22 -> V_8 ? : & V_24 ,
V_22 -> V_6 ? : V_6 ) ;
if ( V_9 == NULL )
return - V_14 ;
V_22 ++ ;
}
return 0 ;
}
void F_14 ( struct V_3 * * V_25 )
{
F_15 ( * V_25 ) ;
* V_25 = NULL ;
}
void F_16 ( const char * V_5 , struct V_3 * V_15 )
{
F_17 ( V_15 != NULL ) ;
F_18 ( V_5 , V_15 ) ;
}
struct V_3 * F_19 ( const char * V_5 ,
struct V_3 * V_15 ,
struct V_21 * V_22 , void * V_6 )
{
struct V_3 * V_26 ;
V_26 = F_20 ( V_5 , V_15 ) ;
if ( V_26 != NULL && V_22 != NULL ) {
int V_27 = F_13 ( V_26 , V_22 , V_6 ) ;
if ( V_27 ) {
F_14 ( & V_26 ) ;
return F_6 ( V_27 ) ;
}
}
return V_26 ;
}
int F_21 ( struct V_28 * V_29 , void * V_6 )
{
return F_22 ( V_29 , L_3 , * ( unsigned int * ) V_6 ) ;
}
int F_23 ( struct V_2 * V_2 , const char T_4 * V_30 ,
unsigned long V_31 , void * V_6 )
{
unsigned * V_32 = V_6 ;
char V_33 [ V_20 + 1 ] , * V_34 ;
unsigned long V_35 ;
V_33 [ V_20 ] = '\0' ;
if ( F_24 ( V_33 , V_30 , V_20 ) )
return - V_36 ;
V_35 = F_25 ( V_33 , & V_34 , 0 ) ;
if ( V_33 == V_34 )
return - V_11 ;
* V_32 = ( unsigned int ) V_35 ;
return V_31 ;
}
int F_26 ( struct V_28 * V_29 , void * V_6 )
{
return F_22 ( V_29 , V_37 L_4 , * ( V_38 * ) V_6 ) ;
}
int F_27 ( struct V_28 * V_29 , void * V_6 )
{
T_5 * V_39 = V_6 ;
F_17 ( V_39 != NULL ) ;
return F_22 ( V_29 , L_5 , F_28 ( V_39 ) ) ;
}
int F_29 ( struct V_2 * V_2 , const char T_4 * V_30 ,
unsigned long V_31 , void * V_6 )
{
T_5 * V_40 = V_6 ;
int V_41 = 0 ;
int V_27 ;
V_27 = F_30 ( V_30 , V_31 , & V_41 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_41 <= 0 )
return - V_42 ;
F_31 ( V_40 , V_41 ) ;
return V_31 ;
}
int F_32 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
F_17 ( V_44 != NULL ) ;
return F_22 ( V_29 , L_6 , V_44 -> V_45 . V_46 ) ;
}
int F_33 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_47 = V_6 ;
F_17 ( V_47 != NULL ) ;
return F_22 ( V_29 , L_6 , V_47 -> V_48 ) ;
}
int F_34 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 )
V_27 = F_22 ( V_29 , L_3 , V_50 . V_54 ) ;
return V_27 ;
}
int F_36 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 ) {
T_6 V_55 = V_50 . V_54 >> 10 ;
V_38 V_56 = V_50 . V_57 ;
while ( V_55 >>= 1 )
V_56 <<= 1 ;
V_27 = F_22 ( V_29 , V_37 L_4 , V_56 ) ;
}
return V_27 ;
}
int F_37 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 ) {
T_6 V_55 = V_50 . V_54 >> 10 ;
V_38 V_56 = V_50 . V_58 ;
while ( V_55 >>= 1 )
V_56 <<= 1 ;
V_27 = F_22 ( V_29 , V_37 L_4 , V_56 ) ;
}
return V_27 ;
}
int F_38 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 ) {
T_6 V_55 = V_50 . V_54 >> 10 ;
V_38 V_56 = V_50 . V_59 ;
while ( V_55 >>= 1 )
V_56 <<= 1 ;
V_27 = F_22 ( V_29 , V_37 L_4 , V_56 ) ;
}
return V_27 ;
}
int F_39 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 )
V_27 = F_22 ( V_29 , V_37 L_4 , V_50 . V_60 ) ;
return V_27 ;
}
int F_40 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_49 V_50 ;
int V_27 = V_49 ( NULL , V_44 -> V_51 , & V_50 ,
F_35 ( - V_52 ) ,
V_53 ) ;
if ( ! V_27 )
V_27 = F_22 ( V_29 , V_37 L_4 , V_50 . V_61 ) ;
return V_27 ;
}
int F_41 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_62 * V_63 ;
char * V_64 = NULL ;
int V_27 = 0 ;
F_17 ( V_44 != NULL ) ;
F_42 ( V_44 ) ;
V_63 = V_44 -> V_65 . V_66 . V_67 ;
V_64 = F_43 ( V_63 -> V_68 ) ;
V_27 = F_22 ( V_29 , L_7 , F_44 ( V_44 ) , V_64 ,
V_63 -> V_69 ? L_8 : L_9 ) ;
F_45 ( V_44 ) ;
return V_27 ;
}
int F_46 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
struct V_70 * V_71 ;
int V_27 = 0 ;
F_17 ( V_44 != NULL ) ;
F_42 ( V_44 ) ;
V_71 = V_44 -> V_65 . V_66 . V_67 -> V_72 ;
if ( V_71 && V_44 -> V_65 . V_66 . V_67 )
V_27 = F_22 ( V_29 , L_6 , V_71 -> V_73 . V_46 ) ;
else
V_27 = F_22 ( V_29 , L_6 , L_10 ) ;
F_45 ( V_44 ) ;
return V_27 ;
}
void F_47 ( struct V_74 * V_75 , int V_76 ,
struct V_77 * V_78 )
{
unsigned int V_79 ;
struct V_77 * V_80 ;
struct V_81 * V_82 ;
int V_83 ;
unsigned long V_84 = 0 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
if ( V_75 == NULL ) {
V_78 -> V_85 = 1 ;
return;
}
V_78 -> V_86 = V_87 ;
V_79 = F_48 ( V_75 , V_88 , & V_84 ) ;
for ( V_83 = 0 ; V_83 < V_79 ; V_83 ++ ) {
if ( V_75 -> V_89 [ V_83 ] == NULL )
continue;
V_82 = & V_75 -> V_90 [ V_76 ] ;
V_80 = F_49 ( V_75 , V_83 , V_76 ) ;
V_78 -> V_85 += V_80 -> V_85 ;
V_78 -> V_91 += V_80 -> V_91 ;
if ( V_80 -> V_86 < V_78 -> V_86 )
V_78 -> V_86 = V_80 -> V_86 ;
if ( V_80 -> V_92 > V_78 -> V_92 )
V_78 -> V_92 = V_80 -> V_92 ;
V_78 -> V_93 += V_80 -> V_93 ;
}
F_50 ( V_75 , V_88 , & V_84 ) ;
}
static int F_51 ( struct V_62 * V_63 , struct V_28 * V_29 )
{
bool V_94 = true ;
if ( V_63 -> V_95 -> V_96 ) {
F_22 ( V_29 , L_11 ) ;
V_94 = false ;
}
F_52 ( V_97 , V_94 ) ;
V_94 = false ;
F_52 ( V_98 , V_94 ) ;
F_52 ( V_99 , V_94 ) ;
F_52 ( V_100 , V_94 ) ;
return 0 ;
}
static void F_53 ( struct V_28 * V_29 , V_38 V_84 , char * V_101 )
{
V_38 V_102 = 1 ;
int V_83 ;
bool V_94 = true ;
for ( V_83 = 0 ; V_103 [ V_83 ] != NULL ; V_83 ++ , V_102 <<= 1 ) {
if ( V_84 & V_102 ) {
F_22 ( V_29 , L_12 ,
V_94 ? V_101 : L_9 , V_103 [ V_83 ] ) ;
V_94 = false ;
}
}
if ( V_84 & ~ ( V_102 - 1 ) )
F_22 ( V_29 , L_13 V_104 ,
V_94 ? V_101 : L_9 , V_84 & ~ ( V_102 - 1 ) ) ;
}
int F_54 ( char * V_105 , int V_31 , V_38 V_84 , char * V_101 )
{
V_38 V_102 = 1 ;
int V_83 , V_106 = 0 ;
for ( V_83 = 0 ; V_103 [ V_83 ] != NULL ; V_83 ++ , V_102 <<= 1 ) {
if ( V_84 & V_102 )
V_106 += snprintf ( V_105 + V_106 , V_31 - V_106 , L_12 ,
V_106 ? V_101 : L_9 , V_103 [ V_83 ] ) ;
}
if ( V_84 & ~ ( V_102 - 1 ) )
V_106 += snprintf ( V_105 + V_106 , V_31 - V_106 ,
L_13 V_104 ,
V_106 ? V_101 : L_9 , V_84 & ~ ( V_102 - 1 ) ) ;
return V_106 ;
}
int F_55 ( struct V_28 * V_29 , void * V_6 )
{
struct V_77 V_106 ;
struct V_81 * V_107 ;
struct V_43 * V_44 = (struct V_43 * ) V_6 ;
struct V_62 * V_63 ;
struct V_108 * V_71 ;
int V_109 ;
int V_110 ;
int V_111 = 0 ;
F_17 ( V_44 != NULL ) ;
F_42 ( V_44 ) ;
V_63 = V_44 -> V_65 . V_66 . V_67 ;
F_22 ( V_29 ,
L_14
L_15
L_16
L_17
L_18
L_19 ,
V_44 -> V_48 ,
F_44 ( V_44 ) ,
F_43 ( V_63 -> V_68 ) ,
V_63 -> V_112 . V_113 ) ;
F_53 ( V_29 , V_63 -> V_112 . V_114 , L_20 ) ;
F_22 ( V_29 ,
L_21
L_22 ) ;
F_51 ( V_63 , V_29 ) ;
F_22 ( V_29 ,
L_21
L_23
L_24 ) ;
F_56 ( & V_63 -> V_115 ) ;
V_109 = 0 ;
F_57 (conn, &imp->imp_conn_list, oic_item) {
F_22 ( V_29 , L_12 , V_109 ? L_20 : L_9 ,
F_58 ( V_71 -> V_116 -> V_117 . V_118 ) ) ;
V_109 ++ ;
}
F_22 ( V_29 ,
L_21
L_25
L_26
L_27
L_28 ,
V_63 -> V_72 == NULL ? L_10 :
F_58 ( V_63 -> V_72 -> V_117 . V_118 ) ,
V_63 -> V_119 ,
V_63 -> V_120 ,
F_28 ( & V_63 -> V_121 ) ) ;
F_59 ( & V_63 -> V_115 ) ;
if ( V_44 -> V_122 == NULL )
goto V_123;
V_107 = & V_44 -> V_122 -> V_90 [ V_124 ] ;
F_47 ( V_44 -> V_122 , V_124 , & V_106 ) ;
if ( V_106 . V_85 != 0 ) {
V_38 V_125 = V_106 . V_91 ;
F_60 ( V_125 , V_106 . V_85 ) ;
V_106 . V_91 = V_125 ;
} else
V_106 . V_91 = 0 ;
F_22 ( V_29 ,
L_29
L_30
L_31
L_32
L_33 V_37 L_34 ,
F_28 ( & V_63 -> V_126 ) ,
F_28 ( & V_63 -> V_127 ) ,
F_28 ( & V_63 -> V_128 ) ,
V_106 . V_91 , V_107 -> V_129 ) ;
V_110 = 0 ;
for( V_109 = 0 ; V_109 < V_130 ; V_109 ++ ) {
if ( V_63 -> V_131 . V_132 [ V_109 ] == 0 )
break;
V_110 = F_61 (unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j])) ;
}
F_22 ( V_29 ,
L_35
L_36
L_37 ,
V_110 ,
F_62 ( & V_63 -> V_131 . V_133 ) ) ;
F_22 ( V_29 ,
L_38
L_39 V_37 L_4
L_40 V_37 L_4
L_41 V_37 L_4 ,
V_63 -> V_134 ,
V_63 -> V_135 ,
V_63 -> V_136 ) ;
for ( V_111 = 0 ; V_111 <= 1 ; V_111 ++ ) {
F_47 ( V_44 -> V_122 ,
V_137 + V_138 + V_111 ,
& V_106 ) ;
if ( V_106 . V_91 > 0 && V_106 . V_85 > 0 ) {
V_38 V_125 = V_106 . V_91 ;
F_60 ( V_125 , V_106 . V_85 ) ;
V_106 . V_91 = V_125 ;
F_22 ( V_29 ,
L_42
L_43 V_37 L_4 ,
V_111 ? L_44 : L_45 ,
V_106 . V_91 ) ;
}
V_110 = ( int ) V_106 . V_91 ;
V_109 = F_63 ( V_139 + V_111 ) + V_140 ;
V_107 = & V_44 -> V_122 -> V_90 [ V_109 ] ;
F_47 ( V_44 -> V_122 , V_109 , & V_106 ) ;
if ( V_106 . V_91 > 0 && V_106 . V_85 != 0 ) {
V_38 V_125 = V_106 . V_91 ;
F_60 ( V_125 , V_106 . V_85 ) ;
V_106 . V_91 = V_125 ;
F_22 ( V_29 ,
L_46 V_37 L_4 ,
V_107 -> V_129 , V_106 . V_91 ) ;
V_109 = ( int ) V_106 . V_91 ;
if ( V_109 > 0 )
F_22 ( V_29 ,
L_47 ,
V_110 / V_109 , ( 100 * V_110 / V_109 ) % 100 ) ;
}
}
V_123:
F_45 ( V_44 ) ;
return 0 ;
}
int F_64 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = (struct V_43 * ) V_6 ;
struct V_62 * V_63 ;
int V_109 , V_110 ;
F_17 ( V_44 != NULL ) ;
F_42 ( V_44 ) ;
V_63 = V_44 -> V_65 . V_66 . V_67 ;
F_22 ( V_29 , L_48 ,
F_43 ( V_63 -> V_68 ) ) ;
F_22 ( V_29 , L_49 ) ;
V_110 = V_63 -> V_141 ;
for ( V_109 = 0 ; V_109 < V_142 ; V_109 ++ ) {
struct V_143 * V_144 =
& V_63 -> V_145 [ ( V_110 + V_109 ) % V_142 ] ;
if ( V_144 -> V_146 == 0 )
continue;
F_22 ( V_29 , L_50 V_147 L_51 ,
V_144 -> V_148 ,
F_43 ( V_144 -> V_146 ) ) ;
}
F_45 ( V_44 ) ;
return 0 ;
}
int F_65 ( struct V_28 * V_29 , struct V_149 * V_150 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_151 ; V_83 ++ )
F_22 ( V_29 , L_52 , V_150 -> V_152 [ V_83 ] ) ;
F_22 ( V_29 , L_4 ) ;
return 0 ;
}
int F_66 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = (struct V_43 * ) V_6 ;
struct V_62 * V_63 ;
unsigned int V_153 , V_154 ;
T_7 V_155 , V_156 ;
struct V_157 V_158 ;
int V_83 ;
F_17 ( V_44 != NULL ) ;
F_42 ( V_44 ) ;
V_63 = V_44 -> V_65 . V_66 . V_67 ;
V_155 = F_67 () ;
F_68 ( & V_158 , V_155 - V_63 -> V_159 ) ;
F_22 ( V_29 , L_53 V_160 L_54 ,
L_55 , V_63 -> V_159 , F_69 ( & V_158 ) ) ;
V_153 = F_62 ( & V_63 -> V_131 . V_133 ) ;
V_154 = V_63 -> V_131 . V_133 . V_161 ;
V_156 = V_63 -> V_131 . V_133 . V_162 ;
F_68 ( & V_158 , V_155 - V_156 ) ;
F_22 ( V_29 , L_56 V_160 L_57 ,
L_58 , V_153 , V_154 , V_156 , F_69 ( & V_158 ) ) ;
F_65 ( V_29 , & V_63 -> V_131 . V_133 ) ;
for( V_83 = 0 ; V_83 < V_130 ; V_83 ++ ) {
if ( V_63 -> V_131 . V_132 [ V_83 ] == 0 )
break;
V_153 = F_62 ( & V_63 -> V_131 . V_163 [ V_83 ] ) ;
V_154 = V_63 -> V_131 . V_163 [ V_83 ] . V_161 ;
V_156 = V_63 -> V_131 . V_163 [ V_83 ] . V_162 ;
F_68 ( & V_158 , V_155 - V_156 ) ;
F_22 ( V_29 , L_59
V_160 L_57 , V_63 -> V_131 . V_132 [ V_83 ] ,
V_153 , V_154 , V_156 , F_69 ( & V_158 ) ) ;
F_65 ( V_29 , & V_63 -> V_131 . V_163 [ V_83 ] ) ;
}
F_45 ( V_44 ) ;
return 0 ;
}
int F_70 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
V_38 V_84 ;
F_42 ( V_44 ) ;
V_84 = V_44 -> V_65 . V_66 . V_67 -> V_112 . V_114 ;
F_22 ( V_29 , L_60 V_104 L_4 , V_84 ) ;
F_53 ( V_29 , V_84 , L_4 ) ;
F_22 ( V_29 , L_4 ) ;
F_45 ( V_44 ) ;
return 0 ;
}
int F_71 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_44 = V_6 ;
F_17 ( V_44 != NULL ) ;
return F_22 ( V_29 , L_3 , V_44 -> V_164 ) ;
}
int F_72 ( struct V_28 * V_29 , void * V_6 )
{
struct V_165 * V_166 = (struct V_165 * ) V_6 ;
F_17 ( V_166 != NULL ) ;
return F_22 ( V_29 , L_5 , V_166 -> V_167 ) ;
}
int F_73 ( struct V_43 * V_44 , struct V_21 * V_22 )
{
int V_27 = 0 ;
F_17 ( V_44 != NULL ) ;
F_17 ( V_44 -> V_168 == V_169 ) ;
F_17 ( V_44 -> V_165 -> V_170 != NULL ) ;
V_44 -> V_171 = F_19 ( V_44 -> V_48 ,
V_44 -> V_165 -> V_170 ,
V_22 , V_44 ) ;
if ( F_74 ( V_44 -> V_171 ) ) {
V_27 = F_75 ( V_44 -> V_171 ) ;
F_8 ( L_61 , V_27 , V_44 -> V_48 ) ;
V_44 -> V_171 = NULL ;
}
return V_27 ;
}
int F_76 ( struct V_43 * V_44 )
{
if ( ! V_44 )
return - V_11 ;
if ( V_44 -> V_172 ) {
F_14 ( & V_44 -> V_172 ) ;
V_44 -> V_172 = NULL ;
}
if ( V_44 -> V_171 ) {
F_14 ( & V_44 -> V_171 ) ;
V_44 -> V_171 = NULL ;
}
return 0 ;
}
static void F_77 ( struct V_173 * V_174 )
{
F_78 ( V_175 , L_62 , V_174 ,
V_174 -> V_176 , V_174 -> V_177 ) ;
F_79 ( F_28 ( & V_174 -> V_178 ) == 0 ,
L_63 , F_58 ( V_174 -> V_118 ) ,
F_28 ( & V_174 -> V_178 ) ) ;
if ( V_174 -> V_176 )
F_14 ( & V_174 -> V_176 ) ;
if ( V_174 -> V_177 )
F_80 ( & V_174 -> V_177 ) ;
if ( V_174 -> V_179 )
F_80 ( & V_174 -> V_179 ) ;
F_81 ( V_174 ) ;
return;
}
void F_82 ( struct V_43 * V_44 )
{
T_8 * V_180 = V_44 -> V_181 ;
struct V_173 * V_182 ;
V_183 ;
while ( ! F_83 ( & V_44 -> V_184 ) ) {
V_182 = F_84 ( V_44 -> V_184 . V_185 ,
struct V_173 , V_186 ) ;
F_85 ( & V_182 -> V_186 ) ;
F_86 ( V_180 , & V_182 -> V_118 , & V_182 -> V_187 ) ;
F_77 ( V_182 ) ;
}
EXIT ;
}
struct V_74 * F_87 ( unsigned int V_188 ,
enum V_189 V_84 )
{
struct V_74 * V_75 ;
unsigned int V_79 ;
unsigned int V_190 = 0 ;
int V_83 ;
if ( V_188 == 0 )
return NULL ;
if ( V_191 != 0 )
V_84 |= V_192 ;
if ( V_84 & V_192 )
V_79 = 1 ;
else
V_79 = F_88 () ;
F_89 ( V_75 , F_90 ( F_91 ( * V_75 ) , V_89 [ V_79 ] ) ) ;
if ( V_75 == NULL )
return NULL ;
V_75 -> V_193 = V_188 ;
V_75 -> V_194 = V_84 ;
F_92 ( & V_75 -> V_195 ) ;
F_89 ( V_75 -> V_90 ,
V_75 -> V_193 * sizeof( struct V_81 ) ) ;
if ( V_75 -> V_90 == NULL )
goto V_196;
if ( ( V_84 & V_192 ) != 0 ) {
V_190 = F_93 ( V_75 ) ;
F_94 ( V_75 -> V_89 [ 0 ] , V_190 ) ;
if ( V_75 -> V_89 [ 0 ] == NULL )
goto V_196;
V_75 -> V_197 = 1 ;
} else if ( ( V_84 & V_198 ) != 0 ) {
for ( V_83 = 0 ; V_83 < V_79 ; ++ V_83 )
if ( F_95 ( V_75 , V_83 ) < 0 )
goto V_196;
}
return V_75 ;
V_196:
F_80 ( & V_75 ) ;
return NULL ;
}
void F_80 ( struct V_74 * * V_199 )
{
struct V_74 * V_75 = * V_199 ;
unsigned int V_79 ;
unsigned int V_190 ;
unsigned int V_83 ;
if ( V_75 == NULL || V_75 -> V_193 == 0 )
return;
* V_199 = NULL ;
if ( V_75 -> V_194 & V_192 )
V_79 = 1 ;
else
V_79 = F_88 () ;
V_190 = F_93 ( V_75 ) ;
for ( V_83 = 0 ; V_83 < V_79 ; V_83 ++ )
if ( V_75 -> V_89 [ V_83 ] != NULL )
F_96 ( V_75 -> V_89 [ V_83 ] , V_190 ) ;
if ( V_75 -> V_90 != NULL )
F_96 ( V_75 -> V_90 , V_75 -> V_193 *
sizeof( struct V_81 ) ) ;
F_96 ( V_75 , F_90 ( F_91 ( * V_75 ) , V_89 [ V_79 ] ) ) ;
}
void F_97 ( struct V_74 * V_75 )
{
struct V_77 * V_80 ;
struct V_81 * V_107 ;
int V_83 ;
int V_109 ;
unsigned int V_79 ;
unsigned long V_84 = 0 ;
V_79 = F_48 ( V_75 , V_88 , & V_84 ) ;
for ( V_83 = 0 ; V_83 < V_79 ; V_83 ++ ) {
if ( V_75 -> V_89 [ V_83 ] == NULL )
continue;
for ( V_109 = 0 ; V_109 < V_75 -> V_193 ; V_109 ++ ) {
V_107 = & V_75 -> V_90 [ V_109 ] ;
V_80 = F_49 ( V_75 , V_83 , V_109 ) ;
V_80 -> V_85 = 0 ;
V_80 -> V_86 = V_87 ;
V_80 -> V_92 = 0 ;
V_80 -> V_93 = 0 ;
V_80 -> V_91 = 0 ;
if ( V_75 -> V_194 & V_198 )
V_80 -> V_200 = 0 ;
}
}
F_50 ( V_75 , V_88 , & V_84 ) ;
}
static T_9 F_98 ( struct V_2 * V_2 ,
const char T_4 * V_201 ,
T_10 V_202 , T_11 * V_203 )
{
struct V_28 * V_204 = V_2 -> V_205 ;
struct V_74 * V_75 = V_204 -> V_206 ;
F_97 ( V_75 ) ;
return V_202 ;
}
static void * F_99 ( struct V_28 * V_32 , T_11 * V_207 )
{
struct V_74 * V_75 = V_32 -> V_206 ;
return ( * V_207 < V_75 -> V_193 ) ? V_207 : NULL ;
}
static void F_100 ( struct V_28 * V_32 , void * V_208 )
{
}
static void * F_101 ( struct V_28 * V_32 , void * V_208 , T_11 * V_207 )
{
( * V_207 ) ++ ;
return F_99 ( V_32 , V_207 ) ;
}
static int F_102 ( struct V_28 * V_32 , void * V_208 )
{
struct V_74 * V_75 = V_32 -> V_206 ;
struct V_81 * V_209 ;
struct V_77 V_210 ;
int V_76 = * ( T_11 * ) V_208 ;
int V_27 = 0 ;
if ( V_76 == 0 ) {
struct V_211 V_155 ;
F_103 ( & V_155 ) ;
V_27 = F_22 ( V_32 , L_64 ,
L_65 , V_155 . V_212 , V_155 . V_213 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_209 = & V_75 -> V_90 [ V_76 ] ;
F_47 ( V_75 , V_76 , & V_210 ) ;
if ( V_210 . V_85 == 0 )
goto V_214;
V_27 = F_22 ( V_32 , L_66 V_215 L_67 , V_209 -> V_216 ,
V_210 . V_85 , V_209 -> V_129 ) ;
if ( V_27 < 0 )
goto V_214;
if ( ( V_209 -> V_217 & V_218 ) && ( V_210 . V_85 > 0 ) ) {
V_27 = F_22 ( V_32 , L_68 V_215 L_68 V_215 L_68 V_215 ,
V_210 . V_86 , V_210 . V_92 , V_210 . V_91 ) ;
if ( V_27 < 0 )
goto V_214;
if ( V_209 -> V_217 & V_219 )
V_27 = F_22 ( V_32 , L_68 V_215 , V_210 . V_93 ) ;
if ( V_27 < 0 )
goto V_214;
}
V_27 = F_22 ( V_32 , L_4 ) ;
V_214:
return ( V_27 < 0 ) ? V_27 : 0 ;
}
static int F_104 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_28 * V_204 ;
int V_27 ;
V_27 = F_105 ( V_2 , & V_220 ) ;
if ( V_27 )
return V_27 ;
V_204 = V_2 -> V_205 ;
V_204 -> V_206 = F_106 ( V_1 ) ;
return 0 ;
}
int F_107 ( struct V_3 * V_4 , const char * V_5 ,
struct V_74 * V_75 )
{
struct V_3 * V_17 ;
F_17 ( V_4 != NULL ) ;
V_17 = F_7 ( V_5 , 0644 , V_4 ,
& V_221 , V_75 ) ;
if ( V_17 == NULL )
return - V_14 ;
return 0 ;
}
void F_108 ( struct V_74 * V_75 , int V_222 ,
unsigned V_223 , const char * V_5 , const char * V_224 )
{
struct V_81 * V_107 ;
struct V_77 * V_80 ;
unsigned long V_84 = 0 ;
unsigned int V_83 ;
unsigned int V_225 ;
F_17 ( V_75 != NULL ) ;
V_107 = & V_75 -> V_90 [ V_222 ] ;
F_79 ( V_107 != NULL , L_69 ,
V_222 , V_5 , V_224 ) ;
V_107 -> V_217 = V_223 ;
V_107 -> V_216 = V_5 ;
V_107 -> V_129 = V_224 ;
V_225 = F_48 ( V_75 , V_88 , & V_84 ) ;
for ( V_83 = 0 ; V_83 < V_225 ; ++ V_83 ) {
if ( V_75 -> V_89 [ V_83 ] == NULL )
continue;
V_80 = F_49 ( V_75 , V_83 , V_222 ) ;
V_80 -> V_85 = 0 ;
V_80 -> V_86 = V_87 ;
V_80 -> V_92 = 0 ;
V_80 -> V_93 = 0 ;
V_80 -> V_91 = 0 ;
if ( ( V_75 -> V_194 & V_198 ) != 0 )
V_80 -> V_200 = 0 ;
}
F_50 ( V_75 , V_88 , & V_84 ) ;
}
void F_109 ( int V_226 , struct V_74 * V_75 )
{
F_110 ( V_226 , V_75 , V_227 ) ;
F_110 ( V_226 , V_75 , V_228 ) ;
F_110 ( V_226 , V_75 , V_229 ) ;
F_110 ( V_226 , V_75 , V_230 ) ;
F_110 ( V_226 , V_75 , V_231 ) ;
F_110 ( V_226 , V_75 , V_232 ) ;
F_110 ( V_226 , V_75 , V_233 ) ;
F_110 ( V_226 , V_75 , V_234 ) ;
F_110 ( V_226 , V_75 , V_235 ) ;
F_110 ( V_226 , V_75 , V_236 ) ;
F_110 ( V_226 , V_75 , V_237 ) ;
F_110 ( V_226 , V_75 , V_238 ) ;
F_110 ( V_226 , V_75 , V_239 ) ;
F_110 ( V_226 , V_75 , V_240 ) ;
F_110 ( V_226 , V_75 , V_241 ) ;
F_110 ( V_226 , V_75 , V_242 ) ;
F_110 ( V_226 , V_75 , V_243 ) ;
F_110 ( V_226 , V_75 , V_244 ) ;
F_110 ( V_226 , V_75 , V_245 ) ;
F_110 ( V_226 , V_75 , V_246 ) ;
F_110 ( V_226 , V_75 , V_247 ) ;
F_110 ( V_226 , V_75 , V_248 ) ;
F_110 ( V_226 , V_75 , V_249 ) ;
F_110 ( V_226 , V_75 , V_250 ) ;
F_110 ( V_226 , V_75 , V_251 ) ;
F_110 ( V_226 , V_75 , V_252 ) ;
F_110 ( V_226 , V_75 , V_253 ) ;
F_110 ( V_226 , V_75 , V_254 ) ;
F_110 ( V_226 , V_75 , V_255 ) ;
F_110 ( V_226 , V_75 , V_256 ) ;
F_110 ( V_226 , V_75 , V_257 ) ;
F_110 ( V_226 , V_75 , V_258 ) ;
F_110 ( V_226 , V_75 , V_259 ) ;
F_110 ( V_226 , V_75 , V_260 ) ;
F_110 ( V_226 , V_75 , V_261 ) ;
F_110 ( V_226 , V_75 , V_262 ) ;
F_110 ( V_226 , V_75 , V_263 ) ;
F_110 ( V_226 , V_75 , V_264 ) ;
F_110 ( V_226 , V_75 , V_265 ) ;
F_110 ( V_226 , V_75 , V_266 ) ;
F_110 ( V_226 , V_75 , V_267 ) ;
F_110 ( V_226 , V_75 , V_268 ) ;
F_110 ( V_226 , V_75 , V_269 ) ;
F_110 ( V_226 , V_75 , V_270 ) ;
F_110 ( V_226 , V_75 , V_271 ) ;
F_110 ( V_226 , V_75 , V_272 ) ;
F_110 ( V_226 , V_75 , V_273 ) ;
F_110 ( V_226 , V_75 , V_274 ) ;
F_110 ( V_226 , V_75 , V_275 ) ;
F_110 ( V_226 , V_75 , V_276 ) ;
F_110 ( V_226 , V_75 , V_277 ) ;
F_110 ( V_226 , V_75 , V_278 ) ;
F_110 ( V_226 , V_75 , V_279 ) ;
F_110 ( V_226 , V_75 , V_280 ) ;
F_110 ( V_226 , V_75 , V_281 ) ;
F_110 ( V_226 , V_75 , V_282 ) ;
F_110 ( V_226 , V_75 , V_283 ) ;
F_110 ( V_226 , V_75 , V_284 ) ;
F_110 ( V_226 , V_75 , V_285 ) ;
F_110 ( V_226 , V_75 , V_286 ) ;
F_110 ( V_226 , V_75 , V_287 ) ;
F_110 ( V_226 , V_75 , V_288 ) ;
F_110 ( V_226 , V_75 , V_289 ) ;
F_110 ( V_226 , V_75 , V_290 ) ;
F_110 ( V_226 , V_75 , V_291 ) ;
F_110 ( V_226 , V_75 , V_292 ) ;
F_110 ( V_226 , V_75 , V_293 ) ;
}
int F_111 ( struct V_43 * V_44 , unsigned V_226 )
{
struct V_74 * V_75 ;
unsigned int V_294 ;
int V_27 , V_83 ;
F_17 ( V_44 -> V_295 == NULL ) ;
F_17 ( V_44 -> V_171 != NULL ) ;
F_17 ( V_44 -> V_296 == 0 ) ;
V_294 = ( ( int ) sizeof( * V_44 -> V_165 -> V_297 ) / sizeof( void * ) ) +
V_226 - 1 ;
V_75 = F_87 ( V_294 , 0 ) ;
if ( V_75 == NULL )
return - V_14 ;
F_109 ( V_226 , V_75 ) ;
for ( V_83 = V_226 ; V_83 < V_294 ; V_83 ++ ) {
F_79 ( V_75 -> V_90 [ V_83 ] . V_216 != NULL ,
L_70
L_71 , V_83 - V_226 ) ;
}
V_27 = F_107 ( V_44 -> V_171 , L_72 , V_75 ) ;
if ( V_27 < 0 ) {
F_80 ( & V_75 ) ;
} else {
V_44 -> V_295 = V_75 ;
V_44 -> V_296 = V_226 ;
}
return V_27 ;
}
void F_112 ( struct V_43 * V_44 )
{
if ( V_44 -> V_295 )
F_80 ( & V_44 -> V_295 ) ;
}
void F_113 ( int V_226 , struct V_74 * V_75 )
{
F_114 ( V_226 , V_75 , V_298 ) ;
F_114 ( V_226 , V_75 , V_299 ) ;
F_114 ( V_226 , V_75 , V_270 ) ;
F_114 ( V_226 , V_75 , V_300 ) ;
F_114 ( V_226 , V_75 , V_251 ) ;
F_114 ( V_226 , V_75 , V_301 ) ;
F_114 ( V_226 , V_75 , V_268 ) ;
F_114 ( V_226 , V_75 , V_256 ) ;
F_114 ( V_226 , V_75 , V_302 ) ;
F_114 ( V_226 , V_75 , V_303 ) ;
F_114 ( V_226 , V_75 , V_304 ) ;
F_114 ( V_226 , V_75 , rename ) ;
F_114 ( V_226 , V_75 , V_305 ) ;
F_114 ( V_226 , V_75 , V_254 ) ;
F_114 ( V_226 , V_75 , V_262 ) ;
F_114 ( V_226 , V_75 , V_306 ) ;
F_114 ( V_226 , V_75 , V_307 ) ;
F_114 ( V_226 , V_75 , V_308 ) ;
F_114 ( V_226 , V_75 , V_309 ) ;
F_114 ( V_226 , V_75 , V_310 ) ;
F_114 ( V_226 , V_75 , V_311 ) ;
F_114 ( V_226 , V_75 , V_312 ) ;
F_114 ( V_226 , V_75 , V_313 ) ;
F_114 ( V_226 , V_75 , V_314 ) ;
F_114 ( V_226 , V_75 , V_315 ) ;
F_114 ( V_226 , V_75 , V_316 ) ;
F_114 ( V_226 , V_75 , V_272 ) ;
F_114 ( V_226 , V_75 , V_317 ) ;
F_114 ( V_226 , V_75 , V_318 ) ;
F_114 ( V_226 , V_75 , V_319 ) ;
F_114 ( V_226 , V_75 , V_320 ) ;
F_114 ( V_226 , V_75 , V_321 ) ;
}
int F_115 ( struct V_43 * V_44 ,
unsigned V_226 )
{
struct V_74 * V_75 ;
unsigned int V_294 ;
int V_27 , V_83 ;
F_17 ( V_44 -> V_322 == NULL ) ;
F_17 ( V_44 -> V_171 != NULL ) ;
F_17 ( V_44 -> V_323 == 0 ) ;
V_294 = 1 + F_116 ( V_321 ) +
V_226 ;
V_75 = F_87 ( V_294 , 0 ) ;
if ( V_75 == NULL )
return - V_14 ;
F_113 ( V_226 , V_75 ) ;
for ( V_83 = V_226 ; V_83 < V_294 ; V_83 ++ ) {
if ( V_75 -> V_90 [ V_83 ] . V_216 == NULL ) {
F_8 ( L_73
L_74 ,
V_83 - V_226 ) ;
F_117 () ;
}
}
V_27 = F_107 ( V_44 -> V_171 , L_75 , V_75 ) ;
if ( V_27 < 0 ) {
F_80 ( & V_75 ) ;
} else {
V_44 -> V_322 = V_75 ;
V_44 -> V_323 = V_226 ;
}
return V_27 ;
}
void F_118 ( struct V_43 * V_44 )
{
struct V_74 * V_75 = V_44 -> V_322 ;
if ( V_75 != NULL ) {
V_44 -> V_322 = NULL ;
V_44 -> V_323 = 0 ;
F_80 ( & V_75 ) ;
}
}
void F_119 ( struct V_74 * V_324 )
{
F_108 ( V_324 ,
V_325 - V_326 ,
0 , L_76 , L_77 ) ;
F_108 ( V_324 ,
V_327 - V_326 ,
0 , L_78 , L_77 ) ;
F_108 ( V_324 ,
V_328 - V_326 ,
0 , L_79 , L_77 ) ;
F_108 ( V_324 ,
V_329 - V_326 ,
0 , L_80 , L_77 ) ;
F_108 ( V_324 ,
V_330 - V_326 ,
0 , L_81 , L_77 ) ;
F_108 ( V_324 ,
V_331 - V_326 ,
0 , L_82 , L_77 ) ;
}
int F_120 ( T_8 * V_332 , T_12 * V_333 ,
struct V_334 * V_335 , void * V_6 )
{
struct V_336 * exp = F_121 ( V_332 , V_335 ) ;
struct V_28 * V_29 = (struct V_28 * ) V_6 ;
if ( exp -> V_337 )
F_22 ( V_29 , L_6 , F_122 ( & exp -> V_338 ) ) ;
return 0 ;
}
static int
F_123 ( struct V_28 * V_29 , void * V_339 )
{
struct V_173 * V_75 = (struct V_173 * ) V_29 -> V_206 ;
struct V_43 * V_44 = V_75 -> V_340 ;
F_124 ( V_44 -> V_341 , & V_75 -> V_118 ,
F_120 , V_29 ) ;
return 0 ;
}
int F_125 ( T_8 * V_332 , T_12 * V_333 ,
struct V_334 * V_335 , void * V_342 )
{
struct V_343 * V_6 = (struct V_343 * ) V_342 ;
struct V_336 * exp = F_121 ( V_332 , V_335 ) ;
if ( exp -> V_344 != NULL ) {
if ( V_6 -> V_94 ) {
F_126 ( V_6 -> V_29 ) ;
V_6 -> V_94 = false ;
}
F_127 ( V_332 , V_6 -> V_29 ) ;
}
return 0 ;
}
static int
F_128 ( struct V_28 * V_29 , void * V_339 )
{
struct V_173 * V_75 = (struct V_173 * ) V_29 -> V_206 ;
struct V_43 * V_44 = V_75 -> V_340 ;
struct V_343 V_342 = { V_29 , true } ;
F_124 ( V_44 -> V_341 , & V_75 -> V_118 ,
F_125 , & V_342 ) ;
return 0 ;
}
int F_129 ( struct V_28 * V_29 , void * V_6 )
{
return F_22 ( V_29 , L_6 ,
L_83
L_84 ) ;
}
static int F_130 ( void * V_345 , void * V_6 )
{
struct V_173 * V_182 = V_345 ;
V_183 ;
F_78 ( V_346 , L_85 , F_28 ( & V_182 -> V_178 ) ) ;
if ( F_28 ( & V_182 -> V_178 ) == 1 ) {
F_56 ( & V_182 -> V_340 -> V_347 ) ;
F_131 ( & V_182 -> V_186 , V_6 ) ;
F_59 ( & V_182 -> V_340 -> V_347 ) ;
RETURN ( 1 ) ;
}
if ( V_182 -> V_177 )
F_97 ( V_182 -> V_177 ) ;
RETURN ( 0 ) ;
}
int F_132 ( struct V_2 * V_2 , const char * V_30 ,
unsigned long V_31 , void * V_6 )
{
struct V_43 * V_44 = (struct V_43 * ) V_6 ;
struct V_173 * V_174 ;
F_133 ( V_348 ) ;
F_134 ( V_44 -> V_181 ,
F_130 , & V_348 ) ;
while ( ! F_83 ( & V_348 ) ) {
V_174 = F_84 ( V_348 . V_185 , struct V_173 ,
V_186 ) ;
F_85 ( & V_174 -> V_186 ) ;
F_77 ( V_174 ) ;
}
return V_31 ;
}
int F_135 ( struct V_336 * exp , T_13 * V_118 , int * V_349 )
{
struct V_173 * V_350 , * V_351 ;
struct V_43 * V_44 = NULL ;
T_1 * V_17 ;
char * V_30 = NULL ;
int V_27 = 0 ;
V_183 ;
* V_349 = 0 ;
if ( ! exp || ! exp -> V_352 || ! exp -> V_352 -> V_172 ||
! exp -> V_352 -> V_181 )
RETURN ( - V_11 ) ;
if ( ! V_118 || * V_118 == V_353 )
RETURN ( 0 ) ;
V_44 = exp -> V_352 ;
F_78 ( V_175 , L_86 , V_44 -> V_181 ) ;
F_136 ( V_350 ) ;
if ( V_350 == NULL )
RETURN ( - V_14 ) ;
V_350 -> V_118 = * V_118 ;
V_350 -> V_340 = exp -> V_352 ;
F_31 ( & V_350 -> V_178 , 1 ) ;
V_351 = F_137 ( V_44 -> V_181 ,
V_118 , & V_350 -> V_187 ) ;
F_78 ( V_346 , L_87 ,
V_351 , F_58 ( * V_118 ) ,
F_28 ( & V_350 -> V_178 ) ) ;
if ( exp -> V_337 ) {
F_138 ( exp -> V_337 ) ;
exp -> V_337 = NULL ;
}
if ( V_351 != V_350 ) {
exp -> V_337 = V_351 ;
GOTO ( V_354 , V_27 = - V_355 ) ;
}
F_139 ( V_30 , V_356 ) ;
if ( V_30 == NULL )
GOTO ( V_354 , V_27 = - V_14 ) ;
memcpy ( V_30 , F_58 ( * V_118 ) , V_356 ) ;
V_350 -> V_176 = F_19 ( V_30 ,
V_44 -> V_172 ,
NULL , NULL ) ;
F_12 ( V_30 , V_356 ) ;
if ( V_350 -> V_176 == NULL ) {
F_8 ( L_88 ,
F_58 ( * V_118 ) ) ;
GOTO ( V_357 , V_27 = - V_14 ) ;
}
V_17 = F_5 ( V_350 -> V_176 , L_89 ,
V_350 , & V_358 ) ;
if ( F_74 ( V_17 ) ) {
F_140 ( L_90 ) ;
V_27 = F_75 ( V_17 ) ;
GOTO ( V_357 , V_27 ) ;
}
V_17 = F_5 ( V_350 -> V_176 , L_91 ,
V_350 , & V_359 ) ;
if ( F_74 ( V_17 ) ) {
F_140 ( L_92 ) ;
V_27 = F_75 ( V_17 ) ;
GOTO ( V_357 , V_27 ) ;
}
exp -> V_337 = V_350 ;
* V_349 = 1 ;
F_56 ( & V_44 -> V_347 ) ;
F_141 ( & V_350 -> V_186 , & V_44 -> V_184 ) ;
F_59 ( & V_44 -> V_347 ) ;
RETURN ( V_27 ) ;
V_357:
if ( V_350 -> V_176 != NULL )
F_14 ( & V_350 -> V_176 ) ;
F_86 ( V_44 -> V_181 , V_118 , & V_350 -> V_187 ) ;
V_354:
F_138 ( V_350 ) ;
F_81 ( V_350 ) ;
RETURN ( V_27 ) ;
}
int F_142 ( struct V_336 * exp )
{
struct V_173 * V_182 = exp -> V_337 ;
if( ! V_182 || ! exp -> V_352 )
RETURN ( 0 ) ;
F_138 ( exp -> V_337 ) ;
exp -> V_337 = NULL ;
return 0 ;
}
int F_30 ( const char * V_30 , unsigned long V_31 ,
int * V_41 )
{
return F_143 ( V_30 , V_31 , V_41 , 1 ) ;
}
int F_143 ( const char * V_30 , unsigned long V_31 ,
int * V_41 , int V_360 )
{
char V_361 [ 20 ] , * V_34 , * V_362 ;
if ( V_31 > ( sizeof( V_361 ) - 1 ) )
return - V_11 ;
if ( F_24 ( V_361 , V_30 , V_31 ) )
return - V_36 ;
V_361 [ V_31 ] = '\0' ;
V_362 = V_361 ;
if ( * V_362 == '-' ) {
V_360 = - V_360 ;
V_362 ++ ;
}
* V_41 = ( int ) F_25 ( V_362 , & V_34 , 10 ) * V_360 ;
if ( V_362 == V_34 )
return - V_11 ;
if ( V_34 != NULL && * V_34 == '.' ) {
int V_363 , pow = 1 ;
int V_83 ;
V_362 = V_34 + 1 ;
if ( strlen ( V_362 ) > 5 )
V_362 [ 5 ] = '\0' ;
V_363 = ( int ) F_25 ( V_362 , & V_34 , 10 ) * V_360 ;
if ( V_362 < V_34 ) {
for ( V_83 = 0 ; V_83 < ( V_34 - V_362 ) ; V_83 ++ )
pow *= 10 ;
* V_41 += V_363 / pow ;
}
}
return 0 ;
}
int F_144 ( char * V_30 , unsigned long V_31 , long V_41 ,
int V_360 )
{
long V_364 , V_365 ;
int V_366 ;
if ( V_31 < 10 )
return - V_11 ;
V_364 = V_41 / V_360 ;
V_366 = snprintf ( V_30 , V_31 , L_93 , V_364 ) ;
V_365 = V_41 % V_360 ;
if ( V_366 < ( V_31 - 4 ) && V_365 > 0 ) {
long V_367 ;
int V_83 , V_368 = 1 , V_369 = 0 ;
V_367 = V_365 * 10 ;
V_30 [ V_366 ++ ] = '.' ;
while ( V_369 < 2 && ( V_367 / V_360 ) < 1 ) {
V_30 [ V_366 ++ ] = '0' ;
V_367 *= 10 ;
V_369 ++ ;
}
for ( V_83 = 0 ; V_83 < ( 5 - V_366 ) ; V_83 ++ )
V_368 *= 10 ;
V_369 = F_145 ( ( int ) V_31 - V_366 , 3 - V_369 ) ;
V_366 += snprintf ( V_30 + V_366 , V_369 , L_93 ,
V_365 * V_368 / V_360 ) ;
V_366 -- ;
while( V_30 [ V_366 ] < '1' || V_30 [ V_366 ] > '9' ) {
V_366 -- ;
if ( V_30 [ V_366 ] == '.' ) {
V_366 -- ;
break;
}
}
V_366 ++ ;
}
V_30 [ V_366 ++ ] = '\n' ;
return V_366 ;
}
int F_146 ( struct V_28 * V_29 , long V_41 , int V_360 )
{
long V_364 , V_365 ;
V_364 = V_41 / V_360 ;
F_22 ( V_29 , L_93 , V_364 ) ;
V_365 = V_41 % V_360 ;
if ( V_365 > 0 ) {
V_365 *= 100 ;
V_365 /= V_360 ;
}
if ( V_365 > 0 ) {
if ( ( V_365 % 10 ) != 0 )
F_22 ( V_29 , L_94 , V_365 ) ;
else
F_22 ( V_29 , L_94 , V_365 / 10 ) ;
}
F_22 ( V_29 , L_4 ) ;
return 0 ;
}
int F_147 ( const char * V_30 , unsigned long V_31 , V_38 * V_41 )
{
return F_148 ( V_30 , V_31 , V_41 , 1 ) ;
}
int F_148 ( const char * V_30 , unsigned long V_31 ,
V_38 * V_41 , int V_360 )
{
char V_361 [ 22 ] , * V_34 , * V_362 ;
V_38 V_370 , V_371 = 0 , V_224 ;
unsigned V_372 = 1 ;
if ( V_31 > ( sizeof( V_361 ) - 1 ) )
return - V_11 ;
if ( F_24 ( V_361 , V_30 , V_31 ) )
return - V_36 ;
V_361 [ V_31 ] = '\0' ;
V_362 = V_361 ;
if ( * V_362 == '-' ) {
V_360 = - V_360 ;
V_362 ++ ;
}
V_370 = F_149 ( V_362 , & V_34 , 10 ) ;
if ( V_362 == V_34 )
return - V_11 ;
if ( V_34 != NULL && * V_34 == '.' ) {
int V_83 ;
V_362 = V_34 + 1 ;
if ( strlen ( V_362 ) > 10 )
V_362 [ 10 ] = '\0' ;
V_371 = F_149 ( V_362 , & V_34 , 10 ) ;
for ( V_83 = 0 ; V_83 < ( V_34 - V_362 ) ; V_83 ++ )
V_372 *= 10 ;
}
V_224 = 1 ;
switch( * V_34 ) {
case 'p' : case 'P' :
V_224 <<= 10 ;
case 't' : case 'T' :
V_224 <<= 10 ;
case 'g' : case 'G' :
V_224 <<= 10 ;
case 'm' : case 'M' :
V_224 <<= 10 ;
case 'k' : case 'K' :
V_224 <<= 10 ;
}
if ( V_224 )
V_360 = V_360 < 0 ? - V_224 : V_224 ;
V_371 *= V_360 ;
F_60 ( V_371 , V_372 ) ;
* V_41 = V_370 * V_360 + V_371 ;
return 0 ;
}
static char * F_150 ( const char * V_373 , const char * V_374 , T_10 V_202 )
{
T_10 V_375 ;
V_375 = strlen ( V_374 ) ;
if ( ! V_375 )
return ( char * ) V_373 ;
while ( V_202 >= V_375 ) {
V_202 -- ;
if ( ! memcmp ( V_373 , V_374 , V_375 ) )
return ( char * ) V_373 ;
V_373 ++ ;
}
return NULL ;
}
char * F_151 ( const char * V_30 , const char * V_5 ,
unsigned long * V_31 )
{
char * V_41 ;
T_10 V_376 = * V_31 ;
V_41 = F_150 ( V_30 , V_5 , V_376 ) ;
if ( V_41 == NULL )
return ( char * ) V_30 ;
V_41 += strlen ( V_5 ) ;
while ( V_41 < V_30 + V_376 && isspace ( * V_41 ) )
V_41 ++ ;
* V_31 = 0 ;
while ( V_41 < V_30 + V_376 && isalnum ( * V_41 ) ) {
++ * V_31 ;
++ V_41 ;
}
return V_41 - * V_31 ;
}
int F_152 ( T_1 * V_15 ,
const char * V_5 ,
T_2 V_10 ,
const struct V_7 * V_377 ,
void * V_6 )
{
struct V_3 * V_17 ;
V_183 ;
F_17 ( ( V_377 -> V_13 == NULL ) == ( ( V_10 & 0222 ) == 0 ) ) ;
V_17 = F_7 ( V_5 , V_10 , V_15 , V_377 , V_6 ) ;
if ( V_17 == NULL )
RETURN ( - V_14 ) ;
RETURN ( 0 ) ;
}
int F_153 ( struct V_43 * V_47 ,
const char * V_5 ,
T_2 V_10 ,
const struct V_7 * V_377 ,
void * V_6 )
{
return ( F_152 ( V_47 -> V_171 , V_5 ,
V_10 , V_377 , V_6 ) ) ;
}
void F_154 ( struct V_378 * V_379 , unsigned int V_380 )
{
if ( V_380 >= V_381 )
V_380 = V_381 - 1 ;
F_56 ( & V_379 -> V_382 ) ;
V_379 -> V_383 [ V_380 ] ++ ;
F_59 ( & V_379 -> V_382 ) ;
}
void F_155 ( struct V_378 * V_379 , unsigned int V_380 )
{
unsigned int V_41 ;
for ( V_41 = 0 ; ( ( 1 << V_41 ) < V_380 ) && ( V_41 <= V_381 ) ; V_41 ++ )
;
F_154 ( V_379 , V_41 ) ;
}
unsigned long F_156 ( struct V_378 * V_379 )
{
unsigned long V_106 = 0 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_381 ; V_83 ++ )
V_106 += V_379 -> V_383 [ V_83 ] ;
return V_106 ;
}
void F_157 ( struct V_378 * V_379 )
{
F_56 ( & V_379 -> V_382 ) ;
memset ( V_379 -> V_383 , 0 , sizeof( V_379 -> V_383 ) ) ;
F_59 ( & V_379 -> V_382 ) ;
}
int F_158 ( struct V_28 * V_29 , void * V_6 )
{
struct V_43 * V_47 = V_6 ;
struct V_384 * V_66 = & V_47 -> V_65 . V_66 ;
int V_27 ;
F_159 ( & V_66 -> V_385 ) ;
V_27 = F_22 ( V_29 , L_5 , V_66 -> V_386 ) ;
F_160 ( & V_66 -> V_385 ) ;
return V_27 ;
}
