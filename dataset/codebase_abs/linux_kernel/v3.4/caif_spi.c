static inline void * F_1 ( T_1 * V_1 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline void F_3 ( void * V_4 , T_1 V_5 )
{
F_4 ( V_4 ) ;
}
static inline void * F_1 ( T_1 * V_1 )
{
return F_5 ( NULL , V_2 , V_1 ,
V_3 ) ;
}
static inline void F_3 ( void * V_4 , T_1 V_5 )
{
F_6 ( NULL , V_2 , V_4 , V_5 ) ;
}
static inline void F_7 ( void )
{
V_6 = F_8 ( V_7 . V_8 . V_9 , NULL ) ;
}
static inline void F_9 ( void )
{
F_10 ( V_6 ) ;
}
static inline void F_11 ( struct V_10 * V_10 )
{
F_10 ( V_10 -> V_11 ) ;
F_10 ( V_10 -> V_12 ) ;
F_10 ( V_10 -> V_13 ) ;
}
static T_2 V_12 ( struct V_14 * V_14 , char T_3 * V_15 ,
T_4 V_16 , T_5 * V_17 )
{
char * V_18 ;
int V_19 = 0 ;
T_2 V_20 ;
struct V_10 * V_10 = V_14 -> V_21 ;
V_18 = F_12 ( V_22 , V_3 ) ;
if ( ! V_18 )
return 0 ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_1 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) , V_23 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_2 , V_10 -> V_24 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_3 , V_10 -> V_25 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_4 , V_10 -> V_26 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_5 , V_10 -> V_27 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_6 , V_10 -> V_28 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_7 , V_10 -> V_29 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_8 , V_10 -> V_30 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_9 , V_10 -> V_31 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_10 , V_10 -> V_32 ) ;
if ( V_19 > V_22 )
V_19 = V_22 ;
V_20 = F_13 ( V_15 , V_16 , V_17 , V_18 , V_19 ) ;
F_4 ( V_18 ) ;
return V_20 ;
}
static T_2 F_14 ( char * V_18 , T_4 V_20 , char * V_33 ,
T_4 V_16 , T_4 V_34 )
{
int V_19 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_16 ; V_35 ++ ) {
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_20 - V_19 ) ,
L_11 V_36 L_12 ,
V_33 [ V_35 ] ) ;
if ( ( V_35 == V_34 ) && ( V_16 > ( V_34 * 2 ) ) ) {
V_35 = V_16 - V_34 ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_20 - V_19 ) ,
L_13 ,
( int ) ( V_16 - ( V_34 * 2 ) ) ) ;
}
if ( ( ! ( V_35 % 10 ) ) && V_35 ) {
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_14 ) ;
}
}
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) , L_14 ) ;
return V_19 ;
}
static T_2 V_11 ( struct V_14 * V_14 , char T_3 * V_15 ,
T_4 V_16 , T_5 * V_17 )
{
char * V_18 ;
int V_19 = 0 ;
T_2 V_20 ;
struct V_10 * V_10 ;
V_10 = V_14 -> V_21 ;
V_18 = F_12 ( V_22 , V_3 ) ;
if ( ! V_18 )
return 0 ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_15 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_16 , V_10 -> V_29 ) ;
V_19 += F_14 ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
V_10 -> V_37 . V_38 [ 0 ] ,
( V_10 -> V_29 + V_39 ) , 100 ) ;
V_19 += snprintf ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
L_17 , V_10 -> V_30 ) ;
V_19 += F_14 ( ( V_18 + V_19 ) , ( V_22 - V_19 ) ,
V_10 -> V_37 . V_40 ,
( V_10 -> V_30 + V_39 ) , 100 ) ;
V_20 = F_13 ( V_15 , V_16 , V_17 , V_18 , V_19 ) ;
F_4 ( V_18 ) ;
return V_20 ;
}
static inline void F_15 ( struct V_10 * V_10 )
{
V_10 -> V_13 = F_8 ( V_10 -> V_41 -> V_9 , V_6 ) ;
V_10 -> V_12 = F_16 ( L_18 , V_42 ,
V_10 -> V_13 , V_10 ,
& V_43 ) ;
V_10 -> V_11 = F_16 ( L_19 , V_42 ,
V_10 -> V_13 , V_10 ,
& V_44 ) ;
}
inline void F_17 ( struct V_10 * V_10 , int V_45 )
{
V_10 -> V_24 = V_45 ;
}
static inline void F_7 ( void )
{
}
static inline void F_9 ( void )
{
}
static inline void F_15 ( struct V_10 * V_10 )
{
}
static inline void F_11 ( struct V_10 * V_10 )
{
}
inline void F_17 ( struct V_10 * V_10 , int V_45 )
{
}
static T_2 F_18 ( struct V_46 * V_8 , char * V_18 )
{
return sprintf ( V_18 , L_20 , V_47 ) ;
}
static T_2 F_19 ( struct V_46 * V_8 , char * V_18 )
{
return sprintf ( V_18 , L_20 , V_48 ) ;
}
static T_2 F_20 ( struct V_46 * V_8 , char * V_18 )
{
return sprintf ( V_18 , L_20 , V_49 ) ;
}
static T_2 F_21 ( struct V_46 * V_8 , char * V_18 )
{
return sprintf ( V_18 , L_20 , V_50 ) ;
}
static T_2 F_22 ( struct V_46 * V_8 , char * V_18 )
{
return sprintf ( V_18 , L_20 , V_51 ) ;
}
int F_23 ( struct V_10 * V_10 , T_6 * V_18 , T_4 V_19 )
{
T_6 * V_52 = V_18 ;
F_24 ( V_18 ) ;
if ( V_10 -> V_53 && ! V_10 -> V_54 )
V_10 -> V_54 = true ;
do {
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_59 = 0 ;
int V_60 ;
V_56 = F_25 ( & V_10 -> V_61 ) ;
if ( ! V_56 )
break;
V_58 = (struct V_57 * ) & V_56 -> V_62 ;
if ( V_47 > 1 ) {
V_59 = 1 + F_26 ( ( V_58 -> V_63 + 1 ) , V_47 ) ;
* V_52 = ( T_6 ) ( V_59 - 1 ) ;
V_52 += V_59 ;
}
F_27 ( V_56 , 0 , V_52 , V_56 -> V_19 ) ;
V_52 += V_56 -> V_19 ;
V_10 -> V_64 -> V_65 . V_66 ++ ;
V_10 -> V_64 -> V_65 . V_67 += V_56 -> V_19 ;
V_60 = F_26 ( ( V_56 -> V_19 + V_59 ) , V_48 ) ;
V_52 += V_60 ;
F_28 ( V_56 ) ;
} while ( ( V_52 - V_18 ) < V_19 );
return V_52 - V_18 ;
}
int F_29 ( struct V_10 * V_10 )
{
struct V_55 * V_56 = NULL ;
int V_68 = 0 ;
int V_69 = 0 ;
while ( F_30 ( & V_10 -> V_61 ) ) {
V_56 = F_31 ( & V_10 -> V_61 ) ;
F_32 ( & V_10 -> V_70 , V_56 ) ;
}
do {
struct V_57 * V_58 = NULL ;
int V_59 = 0 ;
int V_60 = 0 ;
V_56 = F_25 ( & V_10 -> V_70 ) ;
if ( ! V_56 )
break;
V_58 = (struct V_57 * ) & V_56 -> V_62 ;
if ( V_47 > 1 )
V_59 = 1 + F_26 ( ( V_58 -> V_63 + 1 ) , V_47 ) ;
V_60 = F_26 ( ( V_56 -> V_19 + V_59 ) , V_48 ) ;
if ( ( V_56 -> V_19 + V_59 + V_60 + V_68 ) <= V_71 ) {
F_33 ( & V_10 -> V_61 , V_56 ) ;
V_69 ++ ;
V_68 += V_56 -> V_19 + V_59 + V_60 ;
} else {
F_32 ( & V_10 -> V_70 , V_56 ) ;
break;
}
} while ( V_69 <= V_72 );
if ( V_10 -> V_73 && V_10 -> V_70 . V_74 < V_10 -> V_75 &&
V_10 -> V_76 . V_77 ) {
V_10 -> V_73 = 0 ;
V_10 -> V_76 . V_77 ( V_10 -> V_64 , 1 ) ;
}
return V_68 ;
}
static void F_34 ( bool assert , struct V_78 * V_79 )
{
struct V_10 * V_10 = (struct V_10 * ) V_79 -> V_80 ;
if ( V_10 -> V_53 && ! V_10 -> V_54 ) {
F_35 ( V_81 L_21 ) ;
return;
}
if ( ! F_36 () )
F_37 ( & V_10 -> V_82 ) ;
if ( assert ) {
F_38 ( V_83 , & V_10 -> V_45 ) ;
F_38 ( V_84 , & V_10 -> V_45 ) ;
} else {
F_38 ( V_85 , & V_10 -> V_45 ) ;
}
if ( ! F_36 () )
F_39 ( & V_10 -> V_82 ) ;
if ( assert )
F_40 ( & V_10 -> V_86 ) ;
}
static void F_41 ( struct V_78 * V_79 )
{
struct V_10 * V_10 = (struct V_10 * ) V_79 -> V_80 ;
F_42 ( & V_10 -> V_87 ) ;
}
static int F_43 ( struct V_55 * V_56 , struct V_88 * V_89 )
{
struct V_10 * V_10 = NULL ;
unsigned long V_90 ;
if ( ! V_89 )
return - V_91 ;
V_10 = F_44 ( V_89 ) ;
F_33 ( & V_10 -> V_70 , V_56 ) ;
F_45 ( & V_10 -> V_82 , V_90 ) ;
if ( ! F_46 ( V_84 , & V_10 -> V_45 ) ) {
F_40 ( & V_10 -> V_86 ) ;
}
F_47 ( & V_10 -> V_82 , V_90 ) ;
if ( ! V_10 -> V_73 &&
V_10 -> V_70 . V_74 > V_10 -> V_92 &&
V_10 -> V_76 . V_77 ) {
V_10 -> V_73 = 1 ;
V_10 -> V_76 . V_77 ( V_10 -> V_64 , 0 ) ;
}
return 0 ;
}
int F_48 ( struct V_10 * V_10 , T_6 * V_18 , T_4 V_19 )
{
T_6 * V_93 = V_18 ;
F_24 ( V_18 != NULL ) ;
do {
int V_94 ;
struct V_55 * V_56 = NULL ;
int V_59 = 0 ;
int V_60 = 0 ;
T_6 * V_52 = NULL ;
int V_95 = 0 ;
if ( V_49 > 1 ) {
V_59 = 1 + * V_93 ;
V_93 += V_59 ;
}
V_95 = * V_93 ;
V_95 |= ( ( * ( V_93 + 1 ) ) << 8 ) & 0xFF00 ;
V_95 += 2 ;
V_56 = F_49 ( V_10 -> V_64 , V_95 + 1 ) ;
F_24 ( V_56 != NULL ) ;
V_52 = F_50 ( V_56 , V_95 ) ;
memcpy ( V_52 , V_93 , V_95 ) ;
V_93 += V_95 ;
V_56 -> V_96 = F_51 ( V_97 ) ;
F_52 ( V_56 ) ;
V_56 -> V_89 = V_10 -> V_64 ;
if ( ! V_98 )
V_94 = F_53 ( V_56 ) ;
else
V_94 = F_43 ( V_56 , V_10 -> V_64 ) ;
if ( ! V_94 ) {
V_10 -> V_64 -> V_65 . V_99 ++ ;
V_10 -> V_64 -> V_65 . V_100 += V_95 ;
} else
V_10 -> V_64 -> V_65 . V_101 ++ ;
V_60 = F_26 ( ( V_95 + V_59 ) , V_50 ) ;
V_93 += V_60 ;
} while ( ( V_93 - V_18 ) < V_19 );
return V_93 - V_18 ;
}
static int F_54 ( struct V_88 * V_89 )
{
F_55 ( V_89 ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_89 )
{
F_57 ( V_89 ) ;
return 0 ;
}
static int F_58 ( struct V_88 * V_89 )
{
int V_94 = 0 ;
struct V_10 * V_10 = F_44 ( V_89 ) ;
V_10 -> V_73 = 0 ;
V_10 -> V_75 = V_102 ;
V_10 -> V_92 = V_103 ;
if ( ! strncmp ( V_7 . V_8 . V_9 , L_22 , 10 ) ) {
V_10 -> V_53 = true ;
V_10 -> V_54 = false ;
} else {
V_10 -> V_53 = false ;
V_10 -> V_54 = false ;
}
V_10 -> V_37 . V_38 [ 0 ] = F_1 ( & V_10 -> V_37 . V_104 [ 0 ] ) ;
if ( ! V_10 -> V_37 . V_38 [ 0 ] ) {
V_94 = - V_105 ;
goto V_106;
}
V_10 -> V_37 . V_40 = F_1 ( & V_10 -> V_37 . V_107 ) ;
if ( ! V_10 -> V_37 . V_40 ) {
V_94 = - V_105 ;
goto V_108;
}
F_59 ( & V_10 -> V_109 , V_110 ) ;
F_60 ( & V_10 -> V_82 ) ;
V_10 -> V_111 = false ;
F_61 ( & V_10 -> V_86 ) ;
V_10 -> V_112 = F_62 ( V_89 -> V_9 ) ;
if ( ! V_10 -> V_112 ) {
F_35 ( V_81 L_23 ) ;
V_94 = - V_105 ;
goto V_113;
}
F_63 ( & V_10 -> V_87 ) ;
F_15 ( V_10 ) ;
V_10 -> V_79 . V_114 = F_34 ;
V_10 -> V_79 . V_115 = F_41 ;
V_10 -> V_79 . V_80 = V_10 ;
F_37 ( & V_116 ) ;
F_64 ( & V_10 -> V_117 , & V_118 ) ;
F_39 ( & V_116 ) ;
F_65 ( V_10 -> V_112 , & V_10 -> V_109 ) ;
return 0 ;
V_113:
F_3 ( V_10 -> V_37 . V_40 , V_10 -> V_37 . V_107 ) ;
V_108:
F_3 ( V_10 -> V_37 . V_38 [ 0 ] , V_10 -> V_37 . V_104 [ 0 ] ) ;
V_106:
return V_94 ;
}
static void F_66 ( struct V_88 * V_89 )
{
struct V_10 * V_10 = F_44 ( V_89 ) ;
F_37 ( & V_116 ) ;
F_67 ( & V_10 -> V_117 ) ;
F_39 ( & V_116 ) ;
V_10 -> V_64 = NULL ;
F_3 ( V_10 -> V_37 . V_40 , V_10 -> V_37 . V_107 ) ;
F_3 ( V_10 -> V_37 . V_38 [ 0 ] , V_10 -> V_37 . V_104 [ 0 ] ) ;
F_38 ( V_119 , & V_10 -> V_45 ) ;
F_40 ( & V_10 -> V_86 ) ;
F_68 ( V_10 -> V_112 ) ;
F_11 ( V_10 ) ;
return;
}
static void F_69 ( struct V_88 * V_89 )
{
struct V_10 * V_10 = F_44 ( V_89 ) ;
V_89 -> V_120 = 0 ;
V_89 -> V_121 = & V_122 ;
V_89 -> type = V_123 ;
V_89 -> V_90 = V_124 | V_125 ;
V_89 -> V_126 = 0 ;
V_89 -> V_127 = V_128 ;
V_89 -> V_129 = V_130 ;
F_70 ( & V_10 -> V_70 ) ;
F_70 ( & V_10 -> V_61 ) ;
V_10 -> V_76 . V_131 = V_132 ;
V_10 -> V_76 . V_133 = false ;
V_10 -> V_76 . V_134 = false ;
V_10 -> V_76 . V_135 = false ;
V_10 -> V_64 = V_89 ;
}
int F_71 ( struct V_136 * V_41 )
{
struct V_10 * V_10 = NULL ;
struct V_88 * V_64 ;
struct V_137 * V_89 ;
int V_94 ;
V_89 = (struct V_137 * ) V_41 -> V_89 . V_138 ;
V_64 = F_72 ( sizeof( struct V_10 ) ,
L_24 , F_69 ) ;
if ( ! V_89 )
return - V_105 ;
V_10 = F_44 ( V_64 ) ;
F_57 ( V_64 ) ;
V_10 -> V_64 = V_64 ;
V_10 -> V_41 = V_41 ;
V_10 -> V_89 = V_89 ;
V_89 -> V_79 = & V_10 -> V_79 ;
V_94 = F_73 ( V_64 ) ;
if ( V_94 ) {
F_35 ( V_139 L_25 , V_94 ) ;
goto V_140;
}
return V_94 ;
V_140:
V_130 ( V_64 ) ;
return V_94 ;
}
int F_74 ( struct V_136 * V_41 )
{
return 0 ;
}
static void T_7 F_75 ( void )
{
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_10 * V_10 = NULL ;
F_76 (list_node, n, &cfspi_list) {
V_10 = F_77 ( V_142 , struct V_10 , V_117 ) ;
F_78 ( V_10 -> V_64 ) ;
}
F_79 ( & V_7 . V_8 ,
& V_144 ) ;
F_79 ( & V_7 . V_8 ,
& V_145 ) ;
F_79 ( & V_7 . V_8 ,
& V_146 ) ;
F_79 ( & V_7 . V_8 ,
& V_147 ) ;
F_79 ( & V_7 . V_8 , & V_148 ) ;
F_80 ( & V_7 ) ;
F_9 () ;
}
static int T_8 F_81 ( void )
{
int V_149 ;
F_60 ( & V_116 ) ;
V_149 = F_82 ( & V_7 ) ;
if ( V_149 ) {
F_35 ( V_139 L_26 ) ;
goto V_150;
}
V_149 =
F_83 ( & V_7 . V_8 ,
& V_144 ) ;
if ( V_149 ) {
F_35 ( V_139 L_27 ) ;
goto V_151;
}
V_149 =
F_83 ( & V_7 . V_8 ,
& V_145 ) ;
if ( V_149 ) {
F_35 ( V_139 L_28 ) ;
goto V_152;
}
V_149 =
F_83 ( & V_7 . V_8 ,
& V_146 ) ;
if ( V_149 ) {
F_35 ( V_139 L_29 ) ;
goto V_153;
}
V_149 =
F_83 ( & V_7 . V_8 ,
& V_147 ) ;
if ( V_149 ) {
F_35 ( V_139 L_30 ) ;
goto V_154;
}
V_149 =
F_83 ( & V_7 . V_8 ,
& V_148 ) ;
if ( V_149 ) {
F_35 ( V_139 L_31 ) ;
goto V_155;
}
F_7 () ;
return V_149 ;
V_155:
F_79 ( & V_7 . V_8 ,
& V_147 ) ;
V_154:
F_79 ( & V_7 . V_8 ,
& V_146 ) ;
V_153:
F_79 ( & V_7 . V_8 ,
& V_145 ) ;
V_152:
F_79 ( & V_7 . V_8 ,
& V_144 ) ;
V_151:
V_150:
return V_149 ;
}
