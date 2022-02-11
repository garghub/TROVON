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
struct V_13 * V_14 , * V_15 ;
int error ;
V_14 = F_10 () ;
V_15 = F_11 ( V_11 ) ;
error = F_12 ( V_14 , V_15 ,
V_12 == V_16 ? V_17 : V_18 ) ;
F_13 ( V_15 ) ;
F_14 ( V_14 ) ;
return error ;
}
static int F_15 ( struct V_10 * V_19 )
{
struct V_13 * V_14 , * V_15 ;
int error ;
V_15 = F_10 () ;
V_14 = F_11 ( V_19 ) ;
error = F_12 ( V_14 , V_15 , V_18 ) ;
F_13 ( V_14 ) ;
F_14 ( V_15 ) ;
return error ;
}
static int F_16 ( struct V_10 * V_20 , T_2 * V_21 ,
T_2 * V_22 , T_2 * V_23 )
{
struct V_13 * V_24 ;
const struct V_1 * V_1 ;
F_17 () ;
V_1 = F_18 ( V_20 ) ;
V_24 = F_19 ( V_1 ) ;
if ( ! F_20 ( V_24 ) ) {
struct V_25 * V_26 ;
struct V_27 V_28 ;
F_21 (i, label, profile) {
if ( F_22 ( V_26 ) )
continue;
* V_21 = F_23 ( * V_21 ,
V_26 -> V_29 . V_30 ) ;
* V_23 = F_23 ( * V_23 ,
V_26 -> V_29 . V_30 ) ;
}
}
F_24 () ;
F_13 ( V_24 ) ;
return 0 ;
}
static int F_25 ( const struct V_1 * V_1 , struct V_31 * V_32 ,
int V_33 , int V_34 )
{
struct V_13 * V_24 ;
int error = 0 ;
V_24 = F_19 ( V_1 ) ;
if ( ! F_20 ( V_24 ) )
error = F_26 ( V_24 , V_33 , V_34 ) ;
F_13 ( V_24 ) ;
return error ;
}
static int F_27 ( const char * V_35 , const struct V_36 * V_36 , T_3 V_37 ,
struct V_38 * V_39 )
{
struct V_13 * V_24 ;
int error = 0 ;
V_24 = F_28 () ;
if ( ! F_20 ( V_24 ) )
error = F_29 ( V_35 , V_24 , V_36 , 0 , V_37 , V_39 ) ;
F_30 ( V_24 ) ;
return error ;
}
static int F_31 ( const char * V_35 , const struct V_36 * V_36 , T_3 V_37 )
{
struct V_38 V_39 = { F_32 ( V_36 -> V_40 ) -> V_41 ,
F_32 ( V_36 -> V_40 ) -> V_42
} ;
if ( ! F_33 ( V_36 -> V_40 ) )
return 0 ;
return F_27 ( V_35 , V_36 , V_37 , & V_39 ) ;
}
static int F_34 ( const char * V_35 , const struct V_36 * V_43 ,
struct V_40 * V_40 , T_3 V_37 ,
struct V_38 * V_39 )
{
struct V_36 V_36 = { . V_44 = V_43 -> V_44 , . V_40 = V_40 } ;
return F_27 ( V_35 , & V_36 , V_37 , V_39 ) ;
}
static int F_35 ( const char * V_35 , const struct V_36 * V_43 ,
struct V_40 * V_40 , T_3 V_37 )
{
struct V_45 * V_45 = F_32 ( V_40 ) ;
struct V_38 V_39 = { } ;
if ( ! V_45 || ! F_33 ( V_40 ) )
return 0 ;
V_39 . V_46 = V_45 -> V_41 ;
V_39 . V_12 = V_45 -> V_42 ;
return F_34 ( V_35 , V_43 , V_40 , V_37 , & V_39 ) ;
}
static int F_36 ( const char * V_35 , const struct V_36 * V_43 ,
struct V_40 * V_40 , T_3 V_37 , T_4 V_12 )
{
struct V_38 V_39 = { F_37 () , V_12 } ;
if ( ! F_33 ( V_43 -> V_40 ) )
return 0 ;
return F_34 ( V_35 , V_43 , V_40 , V_37 , & V_39 ) ;
}
static int F_38 ( const struct V_36 * V_43 , struct V_40 * V_40 )
{
return F_35 ( V_47 , V_43 , V_40 , V_48 ) ;
}
static int F_39 ( const struct V_36 * V_43 , struct V_40 * V_40 ,
T_4 V_12 )
{
return F_36 ( V_49 , V_43 , V_40 , V_50 ,
V_51 ) ;
}
static int F_40 ( const struct V_36 * V_43 , struct V_40 * V_40 )
{
return F_35 ( V_52 , V_43 , V_40 , V_48 ) ;
}
static int F_41 ( const struct V_36 * V_43 , struct V_40 * V_40 ,
T_4 V_12 , unsigned int V_53 )
{
return F_36 ( V_54 , V_43 , V_40 , V_50 , V_12 ) ;
}
static int F_42 ( const struct V_36 * V_36 )
{
return F_31 ( V_55 , V_36 , V_56 | V_57 ) ;
}
static int F_43 ( const struct V_36 * V_43 , struct V_40 * V_40 ,
const char * V_58 )
{
return F_36 ( V_59 , V_43 , V_40 , V_50 ,
V_60 ) ;
}
static int F_44 ( struct V_40 * V_61 , const struct V_36 * V_62 ,
struct V_40 * V_63 )
{
struct V_13 * V_24 ;
int error = 0 ;
if ( ! F_33 ( V_61 ) )
return 0 ;
V_24 = F_10 () ;
if ( ! F_20 ( V_24 ) )
error = F_45 ( V_24 , V_61 , V_62 , V_63 ) ;
F_14 ( V_24 ) ;
return error ;
}
static int F_46 ( const struct V_36 * V_64 , struct V_40 * V_61 ,
const struct V_36 * V_62 , struct V_40 * V_63 )
{
struct V_13 * V_24 ;
int error = 0 ;
if ( ! F_33 ( V_61 ) )
return 0 ;
V_24 = F_10 () ;
if ( ! F_20 ( V_24 ) ) {
struct V_36 V_65 = { . V_44 = V_64 -> V_44 ,
. V_40 = V_61 } ;
struct V_36 V_66 = { . V_44 = V_62 -> V_44 ,
. V_40 = V_63 } ;
struct V_38 V_39 = { F_32 ( V_61 ) -> V_41 ,
F_32 ( V_61 ) -> V_42
} ;
error = F_29 ( V_67 , V_24 , & V_65 , 0 ,
V_68 | V_69 | V_56 |
V_57 | V_48 ,
& V_39 ) ;
if ( ! error )
error = F_29 ( V_70 , V_24 , & V_66 ,
0 , V_56 | V_57 |
V_50 , & V_39 ) ;
}
F_14 ( V_24 ) ;
return error ;
}
static int F_47 ( const struct V_36 * V_36 , T_4 V_12 )
{
return F_31 ( V_71 , V_36 , V_72 ) ;
}
static int F_48 ( const struct V_36 * V_36 , T_5 V_46 , T_6 V_73 )
{
return F_31 ( V_74 , V_36 , V_75 ) ;
}
static int F_49 ( const struct V_36 * V_36 )
{
return F_31 ( V_76 , V_36 , V_69 ) ;
}
static int F_50 ( struct V_77 * V_77 , const struct V_1 * V_1 )
{
struct V_78 * V_79 = F_51 ( V_77 ) ;
struct V_13 * V_24 ;
int error = 0 ;
if ( ! F_33 ( V_77 -> V_80 . V_40 ) )
return 0 ;
if ( V_81 -> V_82 ) {
V_79 -> V_30 = V_83 | V_68 | V_84 ;
return 0 ;
}
V_24 = F_19 ( V_1 ) ;
if ( ! F_20 ( V_24 ) ) {
struct V_45 * V_45 = F_52 ( V_77 ) ;
struct V_38 V_39 = { V_45 -> V_41 , V_45 -> V_42 } ;
error = F_29 ( V_85 , V_24 , & V_77 -> V_80 , 0 ,
F_53 ( V_77 ) , & V_39 ) ;
V_79 -> V_30 = F_53 ( V_77 ) ;
}
F_13 ( V_24 ) ;
return error ;
}
static int F_54 ( struct V_77 * V_77 )
{
int error = 0 ;
struct V_13 * V_24 = F_10 () ;
V_77 -> V_86 = F_55 ( V_24 , V_87 ) ;
if ( ! F_51 ( V_77 ) )
error = - V_5 ;
F_14 ( V_24 ) ;
return error ;
}
static void F_56 ( struct V_77 * V_77 )
{
F_57 ( F_51 ( V_77 ) ) ;
}
static int F_58 ( const char * V_35 , struct V_77 * V_77 , T_3 V_37 )
{
struct V_13 * V_24 ;
int error = 0 ;
if ( V_77 -> V_80 . V_40 == V_88 . V_40 )
return - V_89 ;
V_24 = F_28 () ;
error = F_59 ( V_35 , V_24 , V_77 , V_37 ) ;
F_30 ( V_24 ) ;
return error ;
}
static int F_60 ( struct V_77 * V_77 )
{
return F_58 ( V_90 , V_77 , F_53 ( V_77 ) ) ;
}
static int F_61 ( struct V_77 * V_77 , int V_37 )
{
return F_58 ( V_91 , V_77 , V_37 ) ;
}
static int F_62 ( struct V_77 * V_77 , unsigned int V_92 )
{
T_3 V_37 = V_93 ;
if ( V_92 == V_94 )
V_37 |= V_56 ;
return F_58 ( V_95 , V_77 , V_37 ) ;
}
static int F_63 ( const char * V_35 , struct V_77 * V_77 , unsigned long V_96 ,
unsigned long V_97 )
{
int V_37 = 0 ;
if ( ! V_77 || ! F_51 ( V_77 ) )
return 0 ;
if ( V_96 & V_98 )
V_37 |= V_68 ;
if ( ( V_96 & V_99 ) && ! ( V_97 & V_100 ) )
V_37 |= V_56 ;
if ( V_96 & V_101 )
V_37 |= V_84 ;
return F_58 ( V_35 , V_77 , V_37 ) ;
}
static int F_64 ( struct V_77 * V_77 , unsigned long V_102 ,
unsigned long V_96 , unsigned long V_97 )
{
return F_63 ( V_103 , V_77 , V_96 , V_97 ) ;
}
static int F_65 ( struct V_104 * V_105 ,
unsigned long V_102 , unsigned long V_96 )
{
return F_63 ( V_106 , V_105 -> V_107 , V_96 ,
! ( V_105 -> V_108 & V_109 ) ? V_100 : 0 ) ;
}
static int F_66 ( struct V_10 * V_110 , char * V_111 ,
char * * V_112 )
{
int error = - V_113 ;
const struct V_1 * V_1 = F_67 ( V_110 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_13 * V_24 = NULL ;
if ( strcmp ( V_111 , L_1 ) == 0 )
V_24 = F_68 ( V_4 -> V_24 ) ;
else if ( strcmp ( V_111 , L_2 ) == 0 && V_4 -> V_114 )
V_24 = F_68 ( V_4 -> V_114 ) ;
else if ( strcmp ( V_111 , L_3 ) == 0 && V_4 -> V_115 )
V_24 = F_68 ( V_4 -> V_115 ) ;
else
error = - V_116 ;
if ( V_24 )
error = F_69 ( V_24 , V_112 ) ;
F_13 ( V_24 ) ;
F_70 ( V_1 ) ;
return error ;
}
static int F_71 ( const char * V_111 , void * V_112 ,
T_7 V_117 )
{
char * V_118 , * V_119 = NULL , * args = V_112 ;
T_7 V_120 ;
int error ;
F_72 ( V_121 , V_122 , V_123 ) ;
if ( V_117 == 0 )
return - V_116 ;
if ( args [ V_117 - 1 ] != '\0' ) {
V_119 = args = F_73 ( V_117 + 1 , V_87 ) ;
if ( ! args )
return - V_5 ;
memcpy ( args , V_112 , V_117 ) ;
args [ V_117 ] = '\0' ;
}
error = - V_116 ;
args = F_74 ( args ) ;
V_118 = F_75 ( & args , L_4 ) ;
if ( ! args )
goto V_124;
args = F_76 ( args ) ;
if ( ! * args )
goto V_124;
V_120 = V_117 - ( args - ( V_119 ? V_119 : ( char * ) V_112 ) ) ;
if ( strcmp ( V_111 , L_1 ) == 0 ) {
if ( strcmp ( V_118 , L_5 ) == 0 ) {
error = F_77 ( args , V_120 ,
V_125 ) ;
} else if ( strcmp ( V_118 , L_6 ) == 0 ) {
error = F_77 ( args , V_120 ,
V_126 ) ;
} else if ( strcmp ( V_118 , L_7 ) == 0 ) {
error = F_78 ( args , V_125 ) ;
} else if ( strcmp ( V_118 , L_8 ) == 0 ) {
error = F_78 ( args , V_126 ) ;
} else if ( strcmp ( V_118 , L_9 ) == 0 ) {
error = F_78 ( args , V_127 ) ;
} else
goto V_128;
} else if ( strcmp ( V_111 , L_3 ) == 0 ) {
if ( strcmp ( V_118 , L_3 ) == 0 )
error = F_78 ( args , V_129 ) ;
else if ( strcmp ( V_118 , L_9 ) == 0 )
error = F_78 ( args , ( V_129 |
V_127 ) ) ;
else
goto V_128;
} else
goto V_128;
if ( ! error )
error = V_117 ;
V_124:
F_79 ( V_119 ) ;
return error ;
V_128:
F_80 ( & V_121 ) -> V_24 = F_10 () ;
F_80 ( & V_121 ) -> V_130 = V_111 ;
F_80 ( & V_121 ) -> error = error = - V_116 ;
F_81 ( V_131 , & V_121 , NULL ) ;
F_14 ( F_80 ( & V_121 ) -> V_24 ) ;
goto V_124;
}
static void F_82 ( struct V_132 * V_133 )
{
struct V_13 * V_24 = F_83 () ;
struct V_3 * V_9 = F_3 ( V_133 -> V_1 ) ;
if ( ( V_9 -> V_24 -> V_134 == V_24 -> V_134 ) ||
( F_20 ( V_9 -> V_24 ) ) )
return;
F_84 ( V_133 -> V_1 , V_81 -> V_135 ) ;
V_81 -> V_136 = 0 ;
F_85 ( V_24 , V_9 -> V_24 ) ;
}
static void F_86 ( struct V_132 * V_133 )
{
return;
}
static int F_87 ( struct V_10 * V_110 ,
unsigned int V_137 , struct V_138 * V_139 )
{
struct V_13 * V_24 = F_28 () ;
int error = 0 ;
if ( ! F_20 ( V_24 ) )
error = F_88 ( V_24 , V_110 , V_137 , V_139 ) ;
F_30 ( V_24 ) ;
return error ;
}
static int T_8 F_89 ( char * V_140 )
{
unsigned long V_141 ;
int error = F_90 ( V_140 , 0 , & V_141 ) ;
if ( ! error )
V_142 = V_141 ? 1 : 0 ;
return 1 ;
}
static int F_91 ( const char * V_143 , const struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_92 ( NULL ) )
return - V_147 ;
return F_93 ( V_143 , V_145 ) ;
}
static int F_94 ( char * V_148 , const struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_95 ( NULL ) )
return - V_147 ;
return F_96 ( V_148 , V_145 ) ;
}
static int F_97 ( const char * V_143 , const struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_92 ( NULL ) )
return - V_147 ;
return F_93 ( V_143 , V_145 ) ;
}
static int F_98 ( char * V_148 , const struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_95 ( NULL ) )
return - V_147 ;
return F_96 ( V_148 , V_145 ) ;
}
static int F_99 ( const char * V_143 , const struct V_144 * V_145 )
{
int error ;
if ( ! V_142 )
return - V_116 ;
if ( V_146 )
return - V_147 ;
error = F_100 ( V_143 , V_145 ) ;
F_101 ( L_10 , V_149 ) ;
return error ;
}
static int F_102 ( char * V_148 , const struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_95 ( NULL ) )
return - V_147 ;
return F_103 ( V_148 , V_145 ) ;
}
static int F_104 ( char * V_148 , struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_95 ( NULL ) )
return - V_147 ;
return sprintf ( V_148 , L_11 , V_150 [ V_151 ] ) ;
}
static int F_105 ( const char * V_143 , struct V_144 * V_145 )
{
int V_28 ;
if ( ! V_142 )
return - V_116 ;
if ( ! V_143 )
return - V_116 ;
if ( V_146 && ! F_92 ( NULL ) )
return - V_147 ;
for ( V_28 = 0 ; V_28 < V_152 ; V_28 ++ ) {
if ( strcmp ( V_143 , V_150 [ V_28 ] ) == 0 ) {
V_151 = V_28 ;
return 0 ;
}
}
return - V_116 ;
}
static int F_106 ( char * V_148 , struct V_144 * V_145 )
{
if ( ! V_142 )
return - V_116 ;
if ( V_146 && ! F_95 ( NULL ) )
return - V_147 ;
return sprintf ( V_148 , L_11 , V_153 [ V_154 ] ) ;
}
static int F_107 ( const char * V_143 , struct V_144 * V_145 )
{
int V_28 ;
if ( ! V_142 )
return - V_116 ;
if ( ! V_143 )
return - V_116 ;
if ( V_146 && ! F_92 ( NULL ) )
return - V_147 ;
for ( V_28 = 0 ; V_28 < V_155 ; V_28 ++ ) {
if ( strcmp ( V_143 , V_153 [ V_28 ] ) == 0 ) {
V_154 = V_28 ;
return 0 ;
}
}
return - V_116 ;
}
static int T_8 F_108 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_81 -> V_156 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_87 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_24 = F_109 ( F_110 ( V_157 ) ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static void F_111 ( void )
{
T_3 V_28 , V_158 ;
F_112 (i) {
F_113 (j) {
F_79 ( F_114 ( V_159 , V_28 ) . V_160 [ V_158 ] ) ;
F_114 ( V_159 , V_28 ) . V_160 [ V_158 ] = NULL ;
}
}
}
static int T_8 F_115 ( void )
{
T_3 V_28 , V_158 ;
F_112 (i) {
F_113 (j) {
char * V_148 ;
if ( F_116 ( V_28 ) > F_117 () )
V_148 = F_73 ( V_149 , V_87 ) ;
else
V_148 = F_118 ( V_149 , V_87 ,
F_116 ( V_28 ) ) ;
if ( ! V_148 ) {
F_111 () ;
return - V_5 ;
}
F_114 ( V_159 , V_28 ) . V_160 [ V_158 ] = V_148 ;
}
}
return 0 ;
}
static int F_119 ( struct V_161 * V_162 , int V_163 ,
void T_9 * V_148 , T_7 * V_164 , T_10 * V_165 )
{
if ( ! F_92 ( NULL ) )
return - V_147 ;
if ( ! V_142 )
return - V_116 ;
return F_120 ( V_162 , V_163 , V_148 , V_164 , V_165 ) ;
}
static int T_8 F_121 ( void )
{
return F_122 ( V_166 ,
V_167 ) ? 0 : - V_5 ;
}
static inline int F_121 ( void )
{
return 0 ;
}
static int T_8 F_123 ( void )
{
int error ;
if ( ! V_142 || ! F_124 ( L_12 ) ) {
F_125 ( L_13 ) ;
V_142 = 0 ;
return 0 ;
}
error = F_126 () ;
if ( error ) {
F_127 ( L_14 ) ;
goto V_168;
}
error = F_128 () ;
if ( error ) {
F_127 ( L_15 ) ;
goto V_168;
}
error = F_121 () ;
if ( error ) {
F_127 ( L_16 ) ;
goto V_168;
}
error = F_115 () ;
if ( error ) {
F_127 ( L_17 ) ;
goto V_169;
}
error = F_108 () ;
if ( error ) {
F_127 ( L_18 ) ;
F_129 () ;
goto V_169;
}
F_130 ( V_170 , F_131 ( V_170 ) ,
L_12 ) ;
V_146 = 1 ;
if ( V_154 == V_171 )
F_125 ( L_19 ) ;
else if ( V_154 == V_172 )
F_125 ( L_20 ) ;
else
F_125 ( L_21 ) ;
return error ;
V_169:
F_111 () ;
V_168:
F_132 () ;
F_133 () ;
V_142 = 0 ;
return error ;
}
