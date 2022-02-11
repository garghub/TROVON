static void F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 ) ) ;
F_3 ( V_1 ) = NULL ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_6 , const struct V_1 * V_7 ,
T_1 V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_7 ( V_4 , F_3 ( V_7 ) ) ;
F_3 ( V_6 ) = V_4 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_6 , const struct V_1 * V_7 )
{
const struct V_3 * V_8 = F_3 ( V_7 ) ;
struct V_3 * V_9 = F_3 ( V_6 ) ;
F_7 ( V_9 , V_8 ) ;
}
static int F_9 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
return F_10 ( V_13 , V_11 , V_12 ) ;
}
static int F_11 ( struct V_10 * V_14 )
{
return F_10 ( V_14 , V_13 , V_15 ) ;
}
static int F_12 ( struct V_10 * V_16 , T_2 * V_17 ,
T_2 * V_18 , T_2 * V_19 )
{
struct V_20 * V_21 ;
const struct V_1 * V_1 ;
F_13 () ;
V_1 = F_14 ( V_16 ) ;
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) && ! F_17 ( V_21 ) ) {
* V_17 = F_18 ( * V_17 , V_21 -> V_22 . V_23 ) ;
* V_19 = F_18 ( * V_19 , V_21 -> V_22 . V_23 ) ;
}
F_19 () ;
return 0 ;
}
static int F_20 ( const struct V_1 * V_1 , struct V_24 * V_25 ,
int V_26 , int V_27 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) )
error = F_21 ( V_21 , V_26 , V_27 ) ;
return error ;
}
static int F_22 ( const char * V_28 , const struct V_29 * V_29 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_20 * V_21 ;
int error = 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) )
error = F_24 ( V_28 , V_21 , V_29 , 0 , V_30 , V_32 ) ;
return error ;
}
static int F_25 ( const char * V_28 , const struct V_29 * V_29 , T_3 V_30 )
{
struct V_31 V_32 = { F_26 ( V_29 -> V_33 ) -> V_34 ,
F_26 ( V_29 -> V_33 ) -> V_35
} ;
if ( ! F_27 ( V_29 -> V_33 ) )
return 0 ;
return F_22 ( V_28 , V_29 , V_30 , & V_32 ) ;
}
static int F_28 ( const char * V_28 , const struct V_29 * V_36 ,
struct V_33 * V_33 , T_3 V_30 ,
struct V_31 * V_32 )
{
struct V_29 V_29 = { . V_37 = V_36 -> V_37 , . V_33 = V_33 } ;
return F_22 ( V_28 , & V_29 , V_30 , V_32 ) ;
}
static int F_29 ( const char * V_28 , const struct V_29 * V_36 ,
struct V_33 * V_33 , T_3 V_30 )
{
struct V_38 * V_38 = F_26 ( V_33 ) ;
struct V_31 V_32 = { } ;
if ( ! V_38 || ! F_27 ( V_33 ) )
return 0 ;
V_32 . V_39 = V_38 -> V_34 ;
V_32 . V_12 = V_38 -> V_35 ;
return F_28 ( V_28 , V_36 , V_33 , V_30 , & V_32 ) ;
}
static int F_30 ( const char * V_28 , const struct V_29 * V_36 ,
struct V_33 * V_33 , T_3 V_30 , T_4 V_12 )
{
struct V_31 V_32 = { F_31 () , V_12 } ;
if ( ! F_27 ( V_36 -> V_33 ) )
return 0 ;
return F_28 ( V_28 , V_36 , V_33 , V_30 , & V_32 ) ;
}
static int F_32 ( const struct V_29 * V_36 , struct V_33 * V_33 )
{
return F_29 ( V_40 , V_36 , V_33 , V_41 ) ;
}
static int F_33 ( const struct V_29 * V_36 , struct V_33 * V_33 ,
T_4 V_12 )
{
return F_30 ( V_42 , V_36 , V_33 , V_43 ,
V_44 ) ;
}
static int F_34 ( const struct V_29 * V_36 , struct V_33 * V_33 )
{
return F_29 ( V_45 , V_36 , V_33 , V_41 ) ;
}
static int F_35 ( const struct V_29 * V_36 , struct V_33 * V_33 ,
T_4 V_12 , unsigned int V_46 )
{
return F_30 ( V_47 , V_36 , V_33 , V_43 , V_12 ) ;
}
static int F_36 ( const struct V_29 * V_29 )
{
return F_25 ( V_48 , V_29 , V_49 | V_50 ) ;
}
static int F_37 ( const struct V_29 * V_36 , struct V_33 * V_33 ,
const char * V_51 )
{
return F_30 ( V_52 , V_36 , V_33 , V_43 ,
V_53 ) ;
}
static int F_38 ( struct V_33 * V_54 , const struct V_29 * V_55 ,
struct V_33 * V_56 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_27 ( V_54 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) )
error = F_40 ( V_21 , V_54 , V_55 , V_56 ) ;
return error ;
}
static int F_41 ( const struct V_29 * V_57 , struct V_33 * V_54 ,
const struct V_29 * V_55 , struct V_33 * V_56 )
{
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_27 ( V_54 ) )
return 0 ;
V_21 = F_39 () ;
if ( ! F_16 ( V_21 ) ) {
struct V_29 V_58 = { . V_37 = V_57 -> V_37 ,
. V_33 = V_54 } ;
struct V_29 V_59 = { . V_37 = V_55 -> V_37 ,
. V_33 = V_56 } ;
struct V_31 V_32 = { F_26 ( V_54 ) -> V_34 ,
F_26 ( V_54 ) -> V_35
} ;
error = F_24 ( V_60 , V_21 , & V_58 , 0 ,
V_61 | V_62 | V_49 |
V_50 | V_41 ,
& V_32 ) ;
if ( ! error )
error = F_24 ( V_63 , V_21 , & V_59 ,
0 , V_49 | V_50 |
V_43 , & V_32 ) ;
}
return error ;
}
static int F_42 ( const struct V_29 * V_29 , T_4 V_12 )
{
return F_25 ( V_64 , V_29 , V_65 ) ;
}
static int F_43 ( const struct V_29 * V_29 , T_5 V_39 , T_6 V_66 )
{
return F_25 ( V_67 , V_29 , V_68 ) ;
}
static int F_44 ( const struct V_29 * V_29 )
{
return F_25 ( V_69 , V_29 , V_62 ) ;
}
static int F_45 ( struct V_70 * V_70 , const struct V_1 * V_1 )
{
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_20 * V_21 ;
int error = 0 ;
if ( ! F_27 ( V_70 -> V_74 . V_33 ) )
return 0 ;
if ( V_13 -> V_75 ) {
V_72 -> V_23 = V_76 | V_61 | V_77 ;
return 0 ;
}
V_21 = F_15 ( V_1 ) ;
if ( ! F_16 ( V_21 ) ) {
struct V_38 * V_38 = F_46 ( V_70 ) ;
struct V_31 V_32 = { V_38 -> V_34 , V_38 -> V_35 } ;
error = F_24 ( V_78 , V_21 , & V_70 -> V_74 , 0 ,
F_47 ( V_70 ) , & V_32 ) ;
V_72 -> V_23 = F_47 ( V_70 ) ;
}
return error ;
}
static int F_48 ( struct V_70 * V_70 )
{
V_70 -> V_73 = F_49 ( V_79 ) ;
if ( ! V_70 -> V_73 )
return - V_5 ;
return 0 ;
}
static void F_50 ( struct V_70 * V_70 )
{
struct V_71 * V_4 = V_70 -> V_73 ;
F_51 ( V_4 ) ;
}
static int F_52 ( const char * V_28 , struct V_70 * V_70 , T_3 V_30 )
{
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_20 * V_21 , * V_80 = F_15 ( V_70 -> V_81 ) ;
int error = 0 ;
F_53 ( ! V_80 ) ;
if ( ! V_70 -> V_74 . V_37 ||
! F_27 ( V_70 -> V_74 . V_33 ) )
return 0 ;
V_21 = F_23 () ;
if ( ! F_16 ( V_21 ) && ! F_16 ( V_80 ) &&
( ( V_80 != V_21 ) || ( V_30 & ~ V_72 -> V_23 ) ) )
error = F_54 ( V_28 , V_21 , V_70 , V_30 ) ;
return error ;
}
static int F_55 ( struct V_70 * V_70 , int V_30 )
{
return F_52 ( V_82 , V_70 , V_30 ) ;
}
static int F_56 ( struct V_70 * V_70 , unsigned int V_83 )
{
T_3 V_30 = V_84 ;
if ( V_83 == V_85 )
V_30 |= V_49 ;
return F_52 ( V_86 , V_70 , V_30 ) ;
}
static int F_57 ( const char * V_28 , struct V_70 * V_70 , unsigned long V_87 ,
unsigned long V_88 )
{
int V_30 = 0 ;
if ( ! V_70 || ! V_70 -> V_73 )
return 0 ;
if ( V_87 & V_89 )
V_30 |= V_61 ;
if ( ( V_87 & V_90 ) && ! ( V_88 & V_91 ) )
V_30 |= V_49 ;
if ( V_87 & V_92 )
V_30 |= V_77 ;
return F_52 ( V_28 , V_70 , V_30 ) ;
}
static int F_58 ( struct V_70 * V_70 , unsigned long V_93 ,
unsigned long V_87 , unsigned long V_88 )
{
return F_57 ( V_94 , V_70 , V_87 , V_88 ) ;
}
static int F_59 ( struct V_95 * V_96 ,
unsigned long V_93 , unsigned long V_87 )
{
return F_57 ( V_97 , V_96 -> V_98 , V_87 ,
! ( V_96 -> V_99 & V_100 ) ? V_91 : 0 ) ;
}
static int F_60 ( struct V_10 * V_101 , char * V_102 ,
char * * V_103 )
{
int error = - V_104 ;
const struct V_1 * V_1 = F_61 ( V_101 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_20 * V_21 = NULL ;
if ( strcmp ( V_102 , L_1 ) == 0 )
V_21 = F_62 ( V_4 -> V_21 ) ;
else if ( strcmp ( V_102 , L_2 ) == 0 && V_4 -> V_105 )
V_21 = F_62 ( V_4 -> V_105 ) ;
else if ( strcmp ( V_102 , L_3 ) == 0 && V_4 -> V_106 )
V_21 = F_62 ( V_4 -> V_106 ) ;
else
error = - V_107 ;
if ( V_21 )
error = F_63 ( V_21 , V_103 ) ;
F_64 ( V_21 ) ;
F_65 ( V_1 ) ;
return error ;
}
static int F_66 ( const char * V_102 , void * V_103 ,
T_7 V_108 )
{
char * V_109 , * V_110 = NULL , * args = V_103 ;
T_7 V_111 ;
int error ;
F_67 ( V_112 , V_113 , V_114 ) ;
if ( V_108 == 0 )
return - V_107 ;
if ( args [ V_108 - 1 ] != '\0' ) {
V_110 = args = F_68 ( V_108 + 1 , V_79 ) ;
if ( ! args )
return - V_5 ;
memcpy ( args , V_103 , V_108 ) ;
args [ V_108 ] = '\0' ;
}
error = - V_107 ;
args = F_69 ( args ) ;
V_109 = F_70 ( & args , L_4 ) ;
if ( ! args )
goto V_115;
args = F_71 ( args ) ;
if ( ! * args )
goto V_115;
V_111 = V_108 - ( args - ( V_110 ? V_110 : ( char * ) V_103 ) ) ;
if ( strcmp ( V_102 , L_1 ) == 0 ) {
if ( strcmp ( V_109 , L_5 ) == 0 ) {
error = F_72 ( args , V_111 ,
! V_116 ) ;
} else if ( strcmp ( V_109 , L_6 ) == 0 ) {
error = F_72 ( args , V_111 ,
V_116 ) ;
} else if ( strcmp ( V_109 , L_7 ) == 0 ) {
error = F_73 ( args , ! V_117 ,
! V_116 , false ) ;
} else if ( strcmp ( V_109 , L_8 ) == 0 ) {
error = F_73 ( args , ! V_117 , V_116 ,
false ) ;
} else
goto V_118;
} else if ( strcmp ( V_102 , L_3 ) == 0 ) {
if ( strcmp ( V_109 , L_3 ) == 0 )
error = F_73 ( args , V_117 , ! V_116 ,
false ) ;
else
goto V_118;
} else
goto V_118;
if ( ! error )
error = V_108 ;
V_115:
F_74 ( V_110 ) ;
return error ;
V_118:
F_75 ( & V_112 ) -> V_21 = F_39 () ;
F_75 ( & V_112 ) -> V_119 = V_102 ;
F_75 ( & V_112 ) -> error = error = - V_107 ;
F_76 ( V_120 , & V_112 , NULL ) ;
goto V_115;
}
static int F_77 ( struct V_10 * V_101 ,
unsigned int V_121 , struct V_122 * V_123 )
{
struct V_20 * V_21 = F_23 () ;
int error = 0 ;
if ( ! F_16 ( V_21 ) )
error = F_78 ( V_21 , V_101 , V_121 , V_123 ) ;
return error ;
}
static int T_8 F_79 ( char * V_124 )
{
unsigned long V_125 ;
int error = F_80 ( V_124 , 0 , & V_125 ) ;
if ( ! error )
V_126 = V_125 ? 1 : 0 ;
return 1 ;
}
static int F_81 ( const char * V_127 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_82 ( NULL ) )
return - V_131 ;
return F_83 ( V_127 , V_129 ) ;
}
static int F_84 ( char * V_132 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_85 ( NULL ) )
return - V_131 ;
return F_86 ( V_132 , V_129 ) ;
}
static int F_87 ( const char * V_127 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_82 ( NULL ) )
return - V_131 ;
return F_83 ( V_127 , V_129 ) ;
}
static int F_88 ( char * V_132 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_85 ( NULL ) )
return - V_131 ;
return F_86 ( V_132 , V_129 ) ;
}
static int F_89 ( const char * V_127 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_82 ( NULL ) )
return - V_131 ;
return F_90 ( V_127 , V_129 ) ;
}
static int F_91 ( char * V_132 , const struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_85 ( NULL ) )
return - V_131 ;
return F_92 ( V_132 , V_129 ) ;
}
static int F_93 ( char * V_132 , struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_85 ( NULL ) )
return - V_131 ;
return sprintf ( V_132 , L_9 , V_133 [ V_134 ] ) ;
}
static int F_94 ( const char * V_127 , struct V_128 * V_129 )
{
int V_135 ;
if ( ! V_126 )
return - V_107 ;
if ( ! V_127 )
return - V_107 ;
if ( V_130 && ! F_82 ( NULL ) )
return - V_131 ;
for ( V_135 = 0 ; V_135 < V_136 ; V_135 ++ ) {
if ( strcmp ( V_127 , V_133 [ V_135 ] ) == 0 ) {
V_134 = V_135 ;
return 0 ;
}
}
return - V_107 ;
}
static int F_95 ( char * V_132 , struct V_128 * V_129 )
{
if ( ! V_126 )
return - V_107 ;
if ( V_130 && ! F_85 ( NULL ) )
return - V_131 ;
return sprintf ( V_132 , L_9 , V_137 [ V_138 ] ) ;
}
static int F_96 ( const char * V_127 , struct V_128 * V_129 )
{
int V_135 ;
if ( ! V_126 )
return - V_107 ;
if ( ! V_127 )
return - V_107 ;
if ( V_130 && ! F_82 ( NULL ) )
return - V_131 ;
for ( V_135 = 0 ; V_135 < V_139 ; V_135 ++ ) {
if ( strcmp ( V_127 , V_137 [ V_135 ] ) == 0 ) {
V_138 = V_135 ;
return 0 ;
}
}
return - V_107 ;
}
static int T_8 F_97 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_13 -> V_140 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_79 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_21 = F_98 ( V_141 -> F_16 ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static void F_99 ( void )
{
T_3 V_135 , V_142 ;
F_100 (i) {
F_101 (j) {
F_74 ( F_102 ( V_143 , V_135 ) . V_144 [ V_142 ] ) ;
F_102 ( V_143 , V_135 ) . V_144 [ V_142 ] = NULL ;
}
}
}
static int T_8 F_103 ( void )
{
T_3 V_135 , V_142 ;
F_100 (i) {
F_101 (j) {
char * V_132 ;
if ( F_104 ( V_135 ) > F_105 () )
V_132 = F_68 ( V_145 , V_79 ) ;
else
V_132 = F_106 ( V_145 , V_79 ,
F_104 ( V_135 ) ) ;
if ( ! V_132 ) {
F_99 () ;
return - V_5 ;
}
F_102 ( V_143 , V_135 ) . V_144 [ V_142 ] = V_132 ;
}
}
return 0 ;
}
static int F_107 ( struct V_146 * V_147 , int V_148 ,
void T_9 * V_132 , T_7 * V_149 , T_10 * V_150 )
{
if ( ! F_82 ( NULL ) )
return - V_131 ;
if ( ! V_126 )
return - V_107 ;
return F_108 ( V_147 , V_148 , V_132 , V_149 , V_150 ) ;
}
static int T_8 F_109 ( void )
{
return F_110 ( V_151 ,
V_152 ) ? 0 : - V_5 ;
}
static inline int F_109 ( void )
{
return 0 ;
}
static int T_8 F_111 ( void )
{
int error ;
if ( ! V_126 || ! F_112 ( L_10 ) ) {
F_113 ( L_11 ) ;
V_126 = 0 ;
return 0 ;
}
error = F_114 () ;
if ( error ) {
F_115 ( L_12 ) ;
goto V_153;
}
error = F_116 () ;
if ( error ) {
F_115 ( L_13 ) ;
goto V_153;
}
error = F_109 () ;
if ( error ) {
F_115 ( L_14 ) ;
goto V_153;
}
error = F_103 () ;
if ( error ) {
F_115 ( L_15 ) ;
goto V_154;
}
error = F_97 () ;
if ( error ) {
F_115 ( L_16 ) ;
F_117 () ;
goto V_154;
}
F_118 ( V_155 , F_119 ( V_155 ) ,
L_10 ) ;
V_130 = 1 ;
if ( V_138 == V_156 )
F_113 ( L_17 ) ;
else if ( V_138 == V_157 )
F_113 ( L_18 ) ;
else
F_113 ( L_19 ) ;
return error ;
V_154:
F_99 () ;
V_153:
F_120 () ;
F_121 () ;
V_126 = 0 ;
return error ;
}
