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
static int F_66 ( const char * V_110 , const struct V_36 * V_36 ,
const char * type , unsigned long V_97 , void * V_111 )
{
struct V_13 * V_24 ;
int error = 0 ;
if ( ( V_97 & V_112 ) == V_113 )
V_97 &= ~ V_112 ;
V_97 &= ~ V_114 ;
V_24 = F_28 () ;
if ( ! F_20 ( V_24 ) ) {
if ( V_97 & V_115 )
error = F_67 ( V_24 , V_36 , V_97 , V_111 ) ;
else if ( V_97 & V_116 )
error = F_68 ( V_24 , V_36 , V_110 , V_97 ) ;
else if ( V_97 & ( V_117 | V_118 | V_119 |
V_120 ) )
error = F_69 ( V_24 , V_36 , V_97 ) ;
else if ( V_97 & V_121 )
error = F_70 ( V_24 , V_36 , V_110 ) ;
else
error = F_71 ( V_24 , V_110 , V_36 , type ,
V_97 , V_111 ) ;
}
F_30 ( V_24 ) ;
return error ;
}
static int F_72 ( struct V_122 * V_44 , int V_97 )
{
struct V_13 * V_24 ;
int error = 0 ;
V_24 = F_28 () ;
if ( ! F_20 ( V_24 ) )
error = F_73 ( V_24 , V_44 , V_97 ) ;
F_30 ( V_24 ) ;
return error ;
}
static int F_74 ( const struct V_36 * V_65 ,
const struct V_36 * V_66 )
{
struct V_13 * V_24 ;
int error = 0 ;
V_24 = F_75 () ;
if ( ! F_20 ( V_24 ) )
error = F_76 ( V_24 , V_65 , V_66 ) ;
F_13 ( V_24 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_123 , char * V_124 ,
char * * V_125 )
{
int error = - V_126 ;
const struct V_1 * V_1 = F_78 ( V_123 ) ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_13 * V_24 = NULL ;
if ( strcmp ( V_124 , L_1 ) == 0 )
V_24 = F_79 ( V_4 -> V_24 ) ;
else if ( strcmp ( V_124 , L_2 ) == 0 && V_4 -> V_127 )
V_24 = F_79 ( V_4 -> V_127 ) ;
else if ( strcmp ( V_124 , L_3 ) == 0 && V_4 -> V_128 )
V_24 = F_79 ( V_4 -> V_128 ) ;
else
error = - V_129 ;
if ( V_24 )
error = F_80 ( V_24 , V_125 ) ;
F_13 ( V_24 ) ;
F_81 ( V_1 ) ;
return error ;
}
static int F_82 ( const char * V_124 , void * V_125 ,
T_7 V_130 )
{
char * V_131 , * V_132 = NULL , * args = V_125 ;
T_7 V_133 ;
int error ;
F_83 ( V_134 , V_135 , V_136 ) ;
if ( V_130 == 0 )
return - V_129 ;
if ( args [ V_130 - 1 ] != '\0' ) {
V_132 = args = F_84 ( V_130 + 1 , V_87 ) ;
if ( ! args )
return - V_5 ;
memcpy ( args , V_125 , V_130 ) ;
args [ V_130 ] = '\0' ;
}
error = - V_129 ;
args = F_85 ( args ) ;
V_131 = F_86 ( & args , L_4 ) ;
if ( ! args )
goto V_137;
args = F_87 ( args ) ;
if ( ! * args )
goto V_137;
V_133 = V_130 - ( args - ( V_132 ? V_132 : ( char * ) V_125 ) ) ;
if ( strcmp ( V_124 , L_1 ) == 0 ) {
if ( strcmp ( V_131 , L_5 ) == 0 ) {
error = F_88 ( args , V_133 ,
V_138 ) ;
} else if ( strcmp ( V_131 , L_6 ) == 0 ) {
error = F_88 ( args , V_133 ,
V_139 ) ;
} else if ( strcmp ( V_131 , L_7 ) == 0 ) {
error = F_89 ( args , V_138 ) ;
} else if ( strcmp ( V_131 , L_8 ) == 0 ) {
error = F_89 ( args , V_139 ) ;
} else if ( strcmp ( V_131 , L_9 ) == 0 ) {
error = F_89 ( args , V_140 ) ;
} else
goto V_141;
} else if ( strcmp ( V_124 , L_3 ) == 0 ) {
if ( strcmp ( V_131 , L_3 ) == 0 )
error = F_89 ( args , V_142 ) ;
else if ( strcmp ( V_131 , L_9 ) == 0 )
error = F_89 ( args , ( V_142 |
V_140 ) ) ;
else
goto V_141;
} else
goto V_141;
if ( ! error )
error = V_130 ;
V_137:
F_90 ( V_132 ) ;
return error ;
V_141:
F_91 ( & V_134 ) -> V_24 = F_10 () ;
F_91 ( & V_134 ) -> V_143 = V_124 ;
F_91 ( & V_134 ) -> error = error = - V_129 ;
F_92 ( V_144 , & V_134 , NULL ) ;
F_14 ( F_91 ( & V_134 ) -> V_24 ) ;
goto V_137;
}
static void F_93 ( struct V_145 * V_146 )
{
struct V_13 * V_24 = F_94 () ;
struct V_3 * V_9 = F_3 ( V_146 -> V_1 ) ;
if ( ( V_9 -> V_24 -> V_147 == V_24 -> V_147 ) ||
( F_20 ( V_9 -> V_24 ) ) )
return;
F_95 ( V_146 -> V_1 , V_81 -> V_148 ) ;
V_81 -> V_149 = 0 ;
F_96 ( V_24 , V_9 -> V_24 ) ;
}
static void F_97 ( struct V_145 * V_146 )
{
return;
}
static int F_98 ( struct V_10 * V_123 ,
unsigned int V_150 , struct V_151 * V_152 )
{
struct V_13 * V_24 = F_28 () ;
int error = 0 ;
if ( ! F_20 ( V_24 ) )
error = F_99 ( V_24 , V_123 , V_150 , V_152 ) ;
F_30 ( V_24 ) ;
return error ;
}
static int F_100 ( struct V_10 * V_20 , struct V_153 * V_143 ,
int V_154 , T_3 V_155 )
{
struct V_13 * V_156 , * V_157 ;
int error ;
if ( V_155 )
return 0 ;
V_156 = F_28 () ;
V_157 = F_11 ( V_20 ) ;
error = F_101 ( V_156 , V_157 , V_154 ) ;
F_13 ( V_157 ) ;
F_30 ( V_156 ) ;
return error ;
}
static int T_8 F_102 ( char * V_158 )
{
unsigned long V_159 ;
int error = F_103 ( V_158 , 0 , & V_159 ) ;
if ( ! error )
V_160 = V_159 ? 1 : 0 ;
return 1 ;
}
static int F_104 ( const char * V_161 , const struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_105 ( NULL ) )
return - V_165 ;
return F_106 ( V_161 , V_163 ) ;
}
static int F_107 ( char * V_166 , const struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_108 ( NULL ) )
return - V_165 ;
return F_109 ( V_166 , V_163 ) ;
}
static int F_110 ( const char * V_161 , const struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_105 ( NULL ) )
return - V_165 ;
return F_106 ( V_161 , V_163 ) ;
}
static int F_111 ( char * V_166 , const struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_108 ( NULL ) )
return - V_165 ;
return F_109 ( V_166 , V_163 ) ;
}
static int F_112 ( const char * V_161 , const struct V_162 * V_163 )
{
int error ;
if ( ! V_160 )
return - V_129 ;
if ( V_164 )
return - V_165 ;
error = F_113 ( V_161 , V_163 ) ;
F_114 ( L_10 , V_167 ) ;
return error ;
}
static int F_115 ( char * V_166 , const struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_108 ( NULL ) )
return - V_165 ;
return F_116 ( V_166 , V_163 ) ;
}
static int F_117 ( char * V_166 , struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_108 ( NULL ) )
return - V_165 ;
return sprintf ( V_166 , L_11 , V_168 [ V_169 ] ) ;
}
static int F_118 ( const char * V_161 , struct V_162 * V_163 )
{
int V_28 ;
if ( ! V_160 )
return - V_129 ;
if ( ! V_161 )
return - V_129 ;
if ( V_164 && ! F_105 ( NULL ) )
return - V_165 ;
for ( V_28 = 0 ; V_28 < V_170 ; V_28 ++ ) {
if ( strcmp ( V_161 , V_168 [ V_28 ] ) == 0 ) {
V_169 = V_28 ;
return 0 ;
}
}
return - V_129 ;
}
static int F_119 ( char * V_166 , struct V_162 * V_163 )
{
if ( ! V_160 )
return - V_129 ;
if ( V_164 && ! F_108 ( NULL ) )
return - V_165 ;
return sprintf ( V_166 , L_11 , V_171 [ V_172 ] ) ;
}
static int F_120 ( const char * V_161 , struct V_162 * V_163 )
{
int V_28 ;
if ( ! V_160 )
return - V_129 ;
if ( ! V_161 )
return - V_129 ;
if ( V_164 && ! F_105 ( NULL ) )
return - V_165 ;
for ( V_28 = 0 ; V_28 < V_173 ; V_28 ++ ) {
if ( strcmp ( V_161 , V_171 [ V_28 ] ) == 0 ) {
V_172 = V_28 ;
return 0 ;
}
}
return - V_129 ;
}
static int T_8 F_121 ( void )
{
struct V_1 * V_1 = (struct V_1 * ) V_81 -> V_174 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_87 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_24 = F_122 ( F_123 ( V_175 ) ) ;
F_3 ( V_1 ) = V_4 ;
return 0 ;
}
static void F_124 ( void )
{
T_3 V_28 , V_176 ;
F_125 (i) {
F_126 (j) {
F_90 ( F_127 ( V_177 , V_28 ) . V_178 [ V_176 ] ) ;
F_127 ( V_177 , V_28 ) . V_178 [ V_176 ] = NULL ;
}
}
}
static int T_8 F_128 ( void )
{
T_3 V_28 , V_176 ;
F_125 (i) {
F_126 (j) {
char * V_166 ;
if ( F_129 ( V_28 ) > F_130 () )
V_166 = F_84 ( V_167 , V_87 ) ;
else
V_166 = F_131 ( V_167 , V_87 ,
F_129 ( V_28 ) ) ;
if ( ! V_166 ) {
F_124 () ;
return - V_5 ;
}
F_127 ( V_177 , V_28 ) . V_178 [ V_176 ] = V_166 ;
}
}
return 0 ;
}
static int F_132 ( struct V_179 * V_180 , int V_181 ,
void T_9 * V_166 , T_7 * V_182 , T_10 * V_183 )
{
if ( ! F_105 ( NULL ) )
return - V_165 ;
if ( ! V_160 )
return - V_129 ;
return F_133 ( V_180 , V_181 , V_166 , V_182 , V_183 ) ;
}
static int T_8 F_134 ( void )
{
return F_135 ( V_184 ,
V_185 ) ? 0 : - V_5 ;
}
static inline int F_134 ( void )
{
return 0 ;
}
static int T_8 F_136 ( void )
{
int error ;
if ( ! V_160 || ! F_137 ( L_12 ) ) {
F_138 ( L_13 ) ;
V_160 = 0 ;
return 0 ;
}
error = F_139 () ;
if ( error ) {
F_140 ( L_14 ) ;
goto V_186;
}
error = F_141 () ;
if ( error ) {
F_140 ( L_15 ) ;
goto V_186;
}
error = F_134 () ;
if ( error ) {
F_140 ( L_16 ) ;
goto V_186;
}
error = F_128 () ;
if ( error ) {
F_140 ( L_17 ) ;
goto V_187;
}
error = F_121 () ;
if ( error ) {
F_140 ( L_18 ) ;
F_142 () ;
goto V_187;
}
F_143 ( V_188 , F_144 ( V_188 ) ,
L_12 ) ;
V_164 = 1 ;
if ( V_172 == V_189 )
F_138 ( L_19 ) ;
else if ( V_172 == V_190 )
F_138 ( L_20 ) ;
else
F_138 ( L_21 ) ;
return error ;
V_187:
F_124 () ;
V_186:
F_145 () ;
F_146 () ;
V_160 = 0 ;
return error ;
}
