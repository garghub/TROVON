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
static int F_12 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
V_15 -> V_16 = V_14 -> V_17 ;
return 0 ;
}
static T_2 V_12 ( struct V_15 * V_15 , char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
char * V_21 ;
int V_22 = 0 ;
T_2 V_23 ;
struct V_10 * V_10 = V_15 -> V_16 ;
V_21 = F_13 ( V_24 , V_3 ) ;
if ( ! V_21 )
return 0 ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_1 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) , V_25 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_2 , V_10 -> V_26 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_3 , V_10 -> V_27 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_4 , V_10 -> V_28 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_5 , V_10 -> V_29 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_6 , V_10 -> V_30 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_7 , V_10 -> V_31 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_8 , V_10 -> V_32 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_9 , V_10 -> V_33 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_10 , V_10 -> V_34 ) ;
if ( V_22 > V_24 )
V_22 = V_24 ;
V_23 = F_14 ( V_18 , V_19 , V_20 , V_21 , V_22 ) ;
F_4 ( V_21 ) ;
return V_23 ;
}
static T_2 F_15 ( char * V_21 , T_4 V_23 , char * V_35 ,
T_4 V_19 , T_4 V_36 )
{
int V_22 = 0 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_19 ; V_37 ++ ) {
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_23 - V_22 ) ,
L_11 V_38 L_12 ,
V_35 [ V_37 ] ) ;
if ( ( V_37 == V_36 ) && ( V_19 > ( V_36 * 2 ) ) ) {
V_37 = V_19 - V_36 ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_23 - V_22 ) ,
L_13 ,
( int ) ( V_19 - ( V_36 * 2 ) ) ) ;
}
if ( ( ! ( V_37 % 10 ) ) && V_37 ) {
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_14 ) ;
}
}
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) , L_14 ) ;
return V_22 ;
}
static T_2 V_11 ( struct V_15 * V_15 , char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
char * V_21 ;
int V_22 = 0 ;
T_2 V_23 ;
struct V_10 * V_10 ;
V_10 = V_15 -> V_16 ;
V_21 = F_13 ( V_24 , V_3 ) ;
if ( ! V_21 )
return 0 ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_15 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_16 , V_10 -> V_31 ) ;
V_22 += F_15 ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
V_10 -> V_39 . V_40 ,
( V_10 -> V_31 + V_41 ) , 100 ) ;
V_22 += snprintf ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
L_17 , V_10 -> V_32 ) ;
V_22 += F_15 ( ( V_21 + V_22 ) , ( V_24 - V_22 ) ,
V_10 -> V_39 . V_42 ,
( V_10 -> V_32 + V_41 ) , 100 ) ;
V_23 = F_14 ( V_18 , V_19 , V_20 , V_21 , V_22 ) ;
F_4 ( V_21 ) ;
return V_23 ;
}
static inline void F_16 ( struct V_10 * V_10 )
{
V_10 -> V_13 = F_8 ( V_10 -> V_43 -> V_9 , V_6 ) ;
V_10 -> V_12 = F_17 ( L_18 , V_44 ,
V_10 -> V_13 , V_10 ,
& V_45 ) ;
V_10 -> V_11 = F_17 ( L_19 , V_44 ,
V_10 -> V_13 , V_10 ,
& V_46 ) ;
}
inline void F_18 ( struct V_10 * V_10 , int V_47 )
{
V_10 -> V_26 = V_47 ;
}
static inline void F_7 ( void )
{
}
static inline void F_9 ( void )
{
}
static inline void F_16 ( struct V_10 * V_10 )
{
}
static inline void F_11 ( struct V_10 * V_10 )
{
}
inline void F_18 ( struct V_10 * V_10 , int V_47 )
{
}
static T_2 F_19 ( struct V_48 * V_8 , char * V_21 )
{
return sprintf ( V_21 , L_20 , V_49 ) ;
}
static T_2 F_20 ( struct V_48 * V_8 , char * V_21 )
{
return sprintf ( V_21 , L_20 , V_50 ) ;
}
static T_2 F_21 ( struct V_48 * V_8 , char * V_21 )
{
return sprintf ( V_21 , L_20 , V_51 ) ;
}
static T_2 F_22 ( struct V_48 * V_8 , char * V_21 )
{
return sprintf ( V_21 , L_20 , V_52 ) ;
}
static T_2 F_23 ( struct V_48 * V_8 , char * V_21 )
{
return sprintf ( V_21 , L_20 , V_53 ) ;
}
int F_24 ( struct V_10 * V_10 , T_6 * V_21 , T_4 V_22 )
{
T_6 * V_54 = V_21 ;
F_25 ( V_21 ) ;
if ( V_10 -> V_55 && ! V_10 -> V_56 )
V_10 -> V_56 = true ;
do {
struct V_57 * V_58 ;
struct V_59 * V_60 ;
int V_61 = 0 ;
int V_62 ;
V_58 = F_26 ( & V_10 -> V_63 ) ;
if ( ! V_58 )
break;
V_60 = (struct V_59 * ) & V_58 -> V_64 ;
if ( V_49 > 1 ) {
V_61 = 1 + F_27 ( ( V_60 -> V_65 + 1 ) , V_49 ) ;
* V_54 = ( T_6 ) ( V_61 - 1 ) ;
V_54 += V_61 ;
}
F_28 ( V_58 , 0 , V_54 , V_58 -> V_22 ) ;
V_54 += V_58 -> V_22 ;
V_10 -> V_66 -> V_67 . V_68 ++ ;
V_10 -> V_66 -> V_67 . V_69 += V_58 -> V_22 ;
V_62 = F_27 ( ( V_58 -> V_22 + V_61 ) , V_50 ) ;
V_54 += V_62 ;
F_29 ( V_58 ) ;
} while ( ( V_54 - V_21 ) < V_22 );
return V_54 - V_21 ;
}
int F_30 ( struct V_10 * V_10 )
{
struct V_57 * V_58 = NULL ;
int V_70 = 0 ;
int V_71 = 0 ;
while ( F_31 ( & V_10 -> V_63 ) ) {
V_58 = F_32 ( & V_10 -> V_63 ) ;
F_33 ( & V_10 -> V_72 , V_58 ) ;
}
do {
struct V_59 * V_60 = NULL ;
int V_61 = 0 ;
int V_62 = 0 ;
V_58 = F_26 ( & V_10 -> V_72 ) ;
if ( ! V_58 )
break;
V_60 = (struct V_59 * ) & V_58 -> V_64 ;
if ( V_49 > 1 )
V_61 = 1 + F_27 ( ( V_60 -> V_65 + 1 ) , V_49 ) ;
V_62 = F_27 ( ( V_58 -> V_22 + V_61 ) , V_50 ) ;
if ( ( V_58 -> V_22 + V_61 + V_62 + V_70 ) <= V_73 ) {
F_34 ( & V_10 -> V_63 , V_58 ) ;
V_71 ++ ;
V_70 += V_58 -> V_22 + V_61 + V_62 ;
} else {
F_33 ( & V_10 -> V_72 , V_58 ) ;
break;
}
} while ( V_71 <= V_74 );
if ( V_10 -> V_75 && V_10 -> V_72 . V_76 < V_10 -> V_77 &&
V_10 -> V_78 . V_79 ) {
V_10 -> V_75 = 0 ;
V_10 -> V_78 . V_79 ( V_10 -> V_66 , 1 ) ;
}
return V_70 ;
}
static void F_35 ( bool assert , struct V_80 * V_81 )
{
struct V_10 * V_10 = (struct V_10 * ) V_81 -> V_82 ;
if ( V_10 -> V_55 && ! V_10 -> V_56 ) {
F_36 ( V_83 L_21 ) ;
return;
}
if ( ! F_37 () )
F_38 ( & V_10 -> V_84 ) ;
if ( assert ) {
F_39 ( V_85 , & V_10 -> V_47 ) ;
F_39 ( V_86 , & V_10 -> V_47 ) ;
} else {
F_39 ( V_87 , & V_10 -> V_47 ) ;
}
if ( ! F_37 () )
F_40 ( & V_10 -> V_84 ) ;
if ( assert )
F_41 ( & V_10 -> V_88 ) ;
}
static void F_42 ( struct V_80 * V_81 )
{
struct V_10 * V_10 = (struct V_10 * ) V_81 -> V_82 ;
F_43 ( & V_10 -> V_89 ) ;
}
static int F_44 ( struct V_57 * V_58 , struct V_90 * V_91 )
{
struct V_10 * V_10 = NULL ;
unsigned long V_92 ;
if ( ! V_91 )
return - V_93 ;
V_10 = F_45 ( V_91 ) ;
F_34 ( & V_10 -> V_72 , V_58 ) ;
F_46 ( & V_10 -> V_84 , V_92 ) ;
if ( ! F_47 ( V_86 , & V_10 -> V_47 ) ) {
F_41 ( & V_10 -> V_88 ) ;
}
F_48 ( & V_10 -> V_84 , V_92 ) ;
if ( ! V_10 -> V_75 &&
V_10 -> V_72 . V_76 > V_10 -> V_94 &&
V_10 -> V_78 . V_79 ) {
V_10 -> V_75 = 1 ;
V_10 -> V_78 . V_79 ( V_10 -> V_66 , 0 ) ;
}
return 0 ;
}
int F_49 ( struct V_10 * V_10 , T_6 * V_21 , T_4 V_22 )
{
T_6 * V_95 = V_21 ;
F_25 ( V_21 != NULL ) ;
do {
int V_96 ;
struct V_57 * V_58 = NULL ;
int V_61 = 0 ;
int V_62 = 0 ;
T_6 * V_54 = NULL ;
int V_97 = 0 ;
if ( V_51 > 1 ) {
V_61 = 1 + * V_95 ;
V_95 += V_61 ;
}
V_97 = * V_95 ;
V_97 |= ( ( * ( V_95 + 1 ) ) << 8 ) & 0xFF00 ;
V_97 += 2 ;
V_58 = F_50 ( V_10 -> V_66 , V_97 + 1 ) ;
F_25 ( V_58 != NULL ) ;
V_54 = F_51 ( V_58 , V_97 ) ;
memcpy ( V_54 , V_95 , V_97 ) ;
V_95 += V_97 ;
V_58 -> V_98 = F_52 ( V_99 ) ;
F_53 ( V_58 ) ;
V_58 -> V_91 = V_10 -> V_66 ;
if ( ! V_100 )
V_96 = F_54 ( V_58 ) ;
else
V_96 = F_44 ( V_58 , V_10 -> V_66 ) ;
if ( ! V_96 ) {
V_10 -> V_66 -> V_67 . V_101 ++ ;
V_10 -> V_66 -> V_67 . V_102 += V_97 ;
} else
V_10 -> V_66 -> V_67 . V_103 ++ ;
V_62 = F_27 ( ( V_97 + V_61 ) , V_52 ) ;
V_95 += V_62 ;
} while ( ( V_95 - V_21 ) < V_22 );
return V_95 - V_21 ;
}
static int F_55 ( struct V_90 * V_91 )
{
F_56 ( V_91 ) ;
return 0 ;
}
static int F_57 ( struct V_90 * V_91 )
{
F_58 ( V_91 ) ;
return 0 ;
}
static void F_59 ( struct V_90 * V_91 )
{
struct V_10 * V_10 = F_45 ( V_91 ) ;
V_91 -> V_104 = 0 ;
V_91 -> V_105 = & V_106 ;
V_91 -> type = V_107 ;
V_91 -> V_92 = V_108 | V_109 ;
V_91 -> V_110 = 0 ;
V_91 -> V_111 = V_112 ;
V_91 -> V_113 = V_114 ;
F_60 ( & V_10 -> V_72 ) ;
F_60 ( & V_10 -> V_63 ) ;
V_10 -> V_78 . V_115 = V_116 ;
V_10 -> V_78 . V_117 = false ;
V_10 -> V_78 . V_118 = false ;
V_10 -> V_78 . V_119 = false ;
V_10 -> V_66 = V_91 ;
}
int F_61 ( struct V_120 * V_43 )
{
struct V_10 * V_10 = NULL ;
struct V_90 * V_66 ;
struct V_121 * V_91 ;
int V_96 ;
V_91 = (struct V_121 * ) V_43 -> V_91 . V_122 ;
V_66 = F_62 ( sizeof( struct V_10 ) ,
L_22 , F_59 ) ;
if ( ! V_66 )
return - V_123 ;
V_10 = F_45 ( V_66 ) ;
F_58 ( V_66 ) ;
V_10 -> V_66 = V_66 ;
V_10 -> V_43 = V_43 ;
V_10 -> V_75 = 0 ;
V_10 -> V_77 = V_124 ;
V_10 -> V_94 = V_125 ;
if ( ! strncmp ( V_7 . V_8 . V_9 , L_23 , 10 ) ) {
V_10 -> V_55 = true ;
V_10 -> V_56 = false ;
} else {
V_10 -> V_55 = false ;
V_10 -> V_56 = false ;
}
V_10 -> V_91 = V_91 ;
V_91 -> V_81 = & V_10 -> V_81 ;
V_10 -> V_39 . V_40 = F_1 ( & V_10 -> V_39 . V_126 ) ;
if ( ! V_10 -> V_39 . V_40 ) {
V_96 = - V_127 ;
goto V_128;
}
V_10 -> V_39 . V_42 = F_1 ( & V_10 -> V_39 . V_129 ) ;
if ( ! V_10 -> V_39 . V_42 ) {
V_96 = - V_127 ;
goto V_130;
}
F_63 ( & V_10 -> V_131 , V_132 ) ;
F_64 ( & V_10 -> V_84 ) ;
V_10 -> V_133 = false ;
F_65 ( & V_10 -> V_88 ) ;
V_10 -> V_134 = F_66 ( V_91 -> V_9 ) ;
if ( ! V_10 -> V_134 ) {
F_36 ( V_83 L_24 ) ;
V_96 = - V_127 ;
goto V_135;
}
F_67 ( & V_10 -> V_89 ) ;
F_16 ( V_10 ) ;
V_10 -> V_81 . V_136 = F_35 ;
V_10 -> V_81 . V_137 = F_42 ;
V_10 -> V_81 . V_82 = V_10 ;
F_38 ( & V_138 ) ;
F_68 ( & V_10 -> V_139 , & V_140 ) ;
F_40 ( & V_138 ) ;
F_69 ( V_10 -> V_134 , & V_10 -> V_131 ) ;
V_96 = F_70 ( V_66 ) ;
if ( V_96 ) {
F_36 ( V_141 L_25 , V_96 ) ;
goto V_142;
}
return V_96 ;
V_142:
F_11 ( V_10 ) ;
F_39 ( V_143 , & V_10 -> V_47 ) ;
F_41 ( & V_10 -> V_88 ) ;
F_71 ( V_10 -> V_134 ) ;
V_135:
F_3 ( V_10 -> V_39 . V_42 , V_10 -> V_39 . V_129 ) ;
V_130:
F_3 ( V_10 -> V_39 . V_40 , V_10 -> V_39 . V_126 ) ;
V_128:
V_114 ( V_66 ) ;
return V_96 ;
}
int F_72 ( struct V_120 * V_43 )
{
struct V_144 * V_145 ;
struct V_144 * V_146 ;
struct V_10 * V_10 = NULL ;
struct V_121 * V_91 ;
V_91 = (struct V_121 * ) V_43 -> V_91 . V_122 ;
F_38 ( & V_138 ) ;
F_73 (list_node, n, &cfspi_list) {
V_10 = F_74 ( V_145 , struct V_10 , V_139 ) ;
if ( V_10 -> V_91 == V_91 ) {
F_75 ( V_145 ) ;
F_3 ( V_10 -> V_39 . V_42 , V_10 -> V_39 . V_129 ) ;
F_3 ( V_10 -> V_39 . V_40 , V_10 -> V_39 . V_126 ) ;
F_39 ( V_143 , & V_10 -> V_47 ) ;
F_41 ( & V_10 -> V_88 ) ;
F_71 ( V_10 -> V_134 ) ;
F_11 ( V_10 ) ;
F_76 ( V_10 -> V_66 ) ;
F_40 ( & V_138 ) ;
return 0 ;
}
}
F_40 ( & V_138 ) ;
return - V_127 ;
}
static void T_7 F_77 ( void )
{
struct V_144 * V_145 ;
struct V_144 * V_146 ;
struct V_10 * V_10 = NULL ;
F_73 (list_node, n, &cfspi_list) {
V_10 = F_74 ( V_145 , struct V_10 , V_139 ) ;
F_78 ( V_10 -> V_43 ) ;
}
F_79 ( & V_7 . V_8 ,
& V_147 ) ;
F_79 ( & V_7 . V_8 ,
& V_148 ) ;
F_79 ( & V_7 . V_8 ,
& V_149 ) ;
F_79 ( & V_7 . V_8 ,
& V_150 ) ;
F_79 ( & V_7 . V_8 , & V_151 ) ;
F_80 ( & V_7 ) ;
F_9 () ;
}
static int T_8 F_81 ( void )
{
int V_152 ;
F_64 ( & V_138 ) ;
V_152 = F_82 ( & V_7 ) ;
if ( V_152 ) {
F_36 ( V_141 L_26 ) ;
goto V_153;
}
V_152 =
F_83 ( & V_7 . V_8 ,
& V_147 ) ;
if ( V_152 ) {
F_36 ( V_141 L_27 ) ;
goto V_154;
}
V_152 =
F_83 ( & V_7 . V_8 ,
& V_148 ) ;
if ( V_152 ) {
F_36 ( V_141 L_28 ) ;
goto V_155;
}
V_152 =
F_83 ( & V_7 . V_8 ,
& V_149 ) ;
if ( V_152 ) {
F_36 ( V_141 L_29 ) ;
goto V_156;
}
V_152 =
F_83 ( & V_7 . V_8 ,
& V_150 ) ;
if ( V_152 ) {
F_36 ( V_141 L_30 ) ;
goto V_157;
}
V_152 =
F_83 ( & V_7 . V_8 ,
& V_151 ) ;
if ( V_152 ) {
F_36 ( V_141 L_31 ) ;
goto V_158;
}
F_7 () ;
return V_152 ;
V_158:
F_79 ( & V_7 . V_8 ,
& V_150 ) ;
V_157:
F_79 ( & V_7 . V_8 ,
& V_149 ) ;
V_156:
F_79 ( & V_7 . V_8 ,
& V_148 ) ;
V_155:
F_79 ( & V_7 . V_8 ,
& V_147 ) ;
V_154:
V_153:
return V_152 ;
}
