static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
V_2 -> V_5 = V_4 ;
V_2 -> V_6 [ V_2 -> V_7 ] . V_8 = V_4 ;
V_2 -> V_6 [ V_2 -> V_7 ] . V_9 =
F_2 () ;
V_2 -> V_7 = ( V_2 -> V_7 + 1 ) %
V_10 ;
}
int F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_12 ++ ;
V_2 -> V_5 = V_13 ;
F_5 ( & V_2 -> V_11 ) ;
return 0 ;
}
void F_6 ( char * V_14 , const char * V_15 , char * * V_16 , int * V_17 )
{
* V_16 = ! V_15 || strncmp ( V_14 , V_15 , strlen ( V_15 ) )
? V_14 : V_14 + strlen ( V_15 ) ;
* V_17 = strlen ( * V_16 ) ;
if ( * V_17 < strlen ( V_18 ) )
return;
if ( ! strncmp ( * V_16 + * V_17 - strlen ( V_18 ) ,
V_18 , strlen ( V_18 ) ) )
* V_17 -= strlen ( V_18 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_19 )
{
int V_20 = 0 ;
F_4 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_5 == V_21 &&
( V_19 == 0 || V_19 == V_2 -> V_22 ) ) {
char * V_23 ;
int V_24 ;
F_6 ( F_8 ( V_2 -> V_25 ) , NULL ,
& V_23 , & V_24 ) ;
if ( V_2 -> V_26 ) {
F_9 ( L_1
L_2
L_3 ,
V_2 -> V_25 -> V_27 , V_24 , V_23 ,
F_10 ( V_2 -> V_28 -> V_29 . V_30 ) ) ;
} else {
F_11 ( 0x166 , L_4
L_5
L_6 ,
V_2 -> V_25 -> V_27 ,
V_24 , V_23 ,
F_10 ( V_2 -> V_28 -> V_29 . V_30 ) ) ;
}
F_12 ( V_2 , V_31 ) ;
F_5 ( & V_2 -> V_11 ) ;
if ( V_32 )
F_13 () ;
F_14 ( V_2 -> V_25 , V_2 , V_33 ) ;
V_20 = 1 ;
} else {
F_5 ( & V_2 -> V_11 ) ;
F_15 ( V_34 , L_7 ,
V_2 -> V_35 -> V_36 , V_2 ,
( V_2 -> V_5 == V_21 &&
V_2 -> V_22 > V_19 ) ?
L_8 : L_9 , V_2 -> V_22 ,
V_19 , F_16 ( V_2 -> V_5 ) ) ;
}
return V_20 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( F_19 ( & V_2 -> V_11 ) ) ;
F_15 ( V_34 , L_10 , F_8 ( V_2 -> V_25 ) ) ;
V_2 -> V_37 = 1 ;
V_2 -> V_12 ++ ;
F_5 ( & V_2 -> V_11 ) ;
F_20 ( V_2 ) ;
F_14 ( V_2 -> V_25 , V_2 , V_38 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 ) ;
F_17 ( V_2 ) ;
}
static unsigned int
F_22 ( struct V_39 * V_40 , T_2 V_41 )
{
long V_42 ;
if ( ! ( ( ( V_40 -> V_43 == V_44 ) && ! V_40 -> V_45 ) ||
( V_40 -> V_43 == V_46 ) ||
( V_40 -> V_43 == V_47 ) ) )
return 0 ;
if ( V_40 -> V_48 )
return 0 ;
if ( V_40 -> V_43 == V_47 )
V_42 = V_40 -> V_49 ;
else
V_42 = V_40 -> V_50 ;
if ( V_42 <= V_41 )
return 0 ;
return V_42 - V_41 ;
}
static unsigned int F_23 ( struct V_1 * V_2 )
{
T_2 V_41 = F_2 () ;
struct V_51 * V_52 , * V_53 ;
struct V_39 * V_40 ;
unsigned int V_54 = 0 ;
F_4 ( & V_2 -> V_11 ) ;
F_24 (tmp, n, &imp->imp_sending_list) {
V_40 = F_25 ( V_52 , struct V_39 , V_55 ) ;
V_54 = F_26 ( F_22 ( V_40 , V_41 ) , V_54 ) ;
}
F_5 ( & V_2 -> V_11 ) ;
return V_54 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_51 * V_52 , * V_53 ;
struct V_39 * V_40 ;
struct V_56 V_57 ;
unsigned int V_54 ;
int V_20 ;
F_28 ( & V_2 -> V_58 ) ;
if ( ! V_2 -> V_37 || V_2 -> V_25 -> V_59 )
F_21 ( V_2 ) ;
F_18 ( V_2 -> V_37 ) ;
do {
if ( ! F_29 ( V_60 ) ) {
V_54 = F_23 ( V_2 ) ;
V_54 += V_54 / 3 ;
if ( V_54 == 0 )
V_54 = V_61 ;
} else {
V_54 = 1 ;
}
F_15 ( V_62 , L_11 ,
V_54 ) ;
V_57 = F_30 (
F_31 ( F_32 ( V_54 ) ) ,
( V_54 > 1 ) ? F_32 ( 1 ) : F_32 ( 1 ) / 2 ,
NULL , NULL ) ;
V_20 = F_33 ( V_2 -> V_63 ,
( F_34 ( & V_2 -> V_64 ) == 0 ) ,
& V_57 ) ;
if ( V_20 ) {
const char * V_65 = F_8 ( V_2 -> V_25 ) ;
F_35 ( L_12 ,
V_65 , V_20 ,
F_34 ( & V_2 -> V_64 ) ) ;
F_4 ( & V_2 -> V_11 ) ;
if ( F_34 ( & V_2 -> V_64 ) == 0 ) {
int V_66 = F_34 ( & V_2 -> V_67 ) ;
F_36 ( V_66 == 0 , L_13
L_14 , V_66 ) ;
V_20 = 0 ;
} else {
F_24 (tmp, n,
&imp->imp_sending_list) {
V_40 = F_25 ( V_52 ,
struct V_39 ,
V_55 ) ;
F_37 ( V_68 , V_40 ,
L_15 ) ;
}
F_24 (tmp, n,
&imp->imp_delayed_list) {
V_40 = F_25 ( V_52 ,
struct V_39 ,
V_55 ) ;
F_37 ( V_68 , V_40 ,
L_16 ) ;
}
F_35 ( L_17
L_18
L_19 , V_65 ,
F_38 ( V_69 ) ,
F_34 ( & V_2 ->
V_67 ) ) ;
}
F_5 ( & V_2 -> V_11 ) ;
}
} while ( V_20 != 0 );
F_18 ( F_34 ( & V_2 -> V_64 ) == 0 ) ;
F_14 ( V_2 -> V_25 , V_2 , V_70 ) ;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_58 ) ;
F_41 ( & V_2 -> V_63 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = V_2 -> V_25 ;
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_37 = 0 ;
F_5 ( & V_2 -> V_11 ) ;
F_14 ( V_72 , V_2 , V_73 ) ;
}
void F_43 ( struct V_1 * V_2 , T_1 V_19 )
{
F_18 ( ! V_2 -> V_74 ) ;
if ( F_7 ( V_2 , V_19 ) ) {
if ( ! V_2 -> V_26 ) {
F_15 ( V_34 , L_20
L_21 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ,
V_2 -> V_25 -> V_27 ) ;
F_21 ( V_2 ) ;
}
F_15 ( V_34 , L_22 ,
F_8 ( V_2 -> V_25 ) ) ;
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_76 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
F_44 () ;
}
}
int F_45 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
F_27 ( V_2 ) ;
F_46 ( V_2 , 1 ) ;
if ( F_34 ( & V_2 -> V_58 ) > 0 ) {
int V_20 ;
struct V_56 V_57 = F_47 ( V_77 , NULL ) ;
V_20 = F_33 ( V_2 -> V_63 ,
( F_34 ( & V_2 -> V_58 ) == 0 ) ,
& V_57 ) ;
if ( V_20 )
F_35 ( L_23 ,
F_34 ( & V_2 -> V_58 ) ) ;
}
V_2 -> V_25 -> V_59 = 0 ;
F_42 ( V_2 ) ;
F_48 ( V_2 , NULL , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_80 ;
struct V_81 * V_82 ;
char * V_23 ;
int V_24 , V_83 = 1 ;
F_4 ( & V_2 -> V_11 ) ;
if ( F_50 ( & V_2 -> V_84 ) ) {
F_35 ( L_24 ,
V_2 -> V_25 -> V_27 ) ;
F_5 ( & V_2 -> V_11 ) ;
return - V_85 ;
}
F_51 (conn, &imp->imp_conn_list, oic_item) {
F_15 ( V_34 , L_25 V_86 L_26 ,
V_2 -> V_25 -> V_27 ,
F_10 ( V_80 -> V_87 -> V_29 . V_30 ) ,
V_80 -> V_88 ) ;
if ( ( V_80 -> V_88 == 0 ) ||
F_52 ( V_80 -> V_88 ,
V_2 -> V_89 ) ) {
V_79 = V_80 ;
V_83 = 0 ;
break;
}
if ( ! V_79 )
V_79 = V_80 ;
else if ( F_53 ( V_80 -> V_88 ,
V_79 -> V_88 ) )
V_79 = V_80 ;
}
if ( ! V_79 || V_2 -> V_90 ) {
F_18 ( V_2 -> V_91 ) ;
V_79 = V_2 -> V_91 ;
V_83 = 0 ;
}
F_18 ( V_79 -> V_87 ) ;
if ( V_83 && ( V_2 -> V_84 . V_92 == & V_79 -> V_93 ) ) {
struct V_94 * V_95 = & V_2 -> V_96 . V_97 ;
if ( F_54 ( V_95 ) < V_98 ) {
F_55 ( V_95 , F_54 ( V_95 ) + V_99 ) ;
if ( F_54 ( V_95 ) > V_98 )
F_56 ( V_95 , V_98 ) ;
}
F_18 ( V_79 -> V_88 ) ;
F_15 ( V_34 , L_27
L_28 , V_2 -> V_25 -> V_27 , F_54 ( V_95 ) ) ;
}
V_79 -> V_88 = F_57 () ;
if ( V_2 -> V_28 )
F_58 ( V_2 -> V_28 ) ;
V_2 -> V_28 = F_59 ( V_79 -> V_87 ) ;
V_82 = F_60 ( & V_2 -> V_100 ) ;
F_18 ( V_82 != NULL ) ;
if ( V_82 -> V_101 )
F_58 ( V_82 -> V_101 ) ;
V_82 -> V_101 = F_59 ( V_79 -> V_87 ) ;
F_61 ( V_82 ) ;
if ( V_2 -> V_91 != V_79 ) {
if ( V_2 -> V_91 ) {
F_6 ( F_8 ( V_2 -> V_25 ) , NULL ,
& V_23 , & V_24 ) ;
F_15 ( V_34 , L_29
L_30 ,
V_2 -> V_25 -> V_27 ,
V_24 , V_23 ,
F_10 ( V_79 -> V_87 -> V_29 . V_30 ) ) ;
}
V_2 -> V_91 = V_79 ;
}
F_15 ( V_34 , L_31 ,
V_2 -> V_25 -> V_27 , V_2 , V_79 -> V_102 . V_14 ,
F_10 ( V_79 -> V_87 -> V_29 . V_30 ) ) ;
F_5 ( & V_2 -> V_11 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , T_3 * V_103 )
{
struct V_39 * V_40 ;
struct V_51 * V_52 ;
if ( ! F_50 ( & V_2 -> V_104 ) ) {
V_52 = V_2 -> V_104 . V_92 ;
V_40 = F_25 ( V_52 , struct V_39 , V_105 ) ;
* V_103 = V_40 -> V_106 ;
if ( V_40 -> V_106 == 0 ) {
F_37 ( V_68 , V_40 ,
L_32 ) ;
F_63 () ;
}
return 1 ;
}
if ( ! F_50 ( & V_2 -> V_107 ) ) {
V_52 = V_2 -> V_107 . V_92 ;
V_40 = F_25 ( V_52 , struct V_39 , V_105 ) ;
* V_103 = V_40 -> V_106 ;
if ( V_40 -> V_106 == 0 ) {
F_37 ( V_68 , V_40 , L_33 ) ;
F_63 () ;
}
return 1 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = V_2 -> V_25 ;
int V_108 = 0 ;
int V_109 = 0 ;
T_3 V_110 = 0 ;
struct V_39 * V_111 ;
char * V_112 [] = { NULL ,
F_8 ( V_2 -> V_25 ) ,
V_72 -> V_113 . V_14 ,
( char * ) & V_2 -> V_100 ,
( char * ) & V_2 -> V_114 } ;
struct V_115 * V_116 ;
int V_20 ;
F_4 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_5 == V_117 ) {
F_5 ( & V_2 -> V_11 ) ;
F_35 ( L_34 ) ;
return - V_85 ;
} else if ( V_2 -> V_5 == V_21 ) {
F_5 ( & V_2 -> V_11 ) ;
F_35 ( L_35 ) ;
return 0 ;
} else if ( V_2 -> V_5 == V_118 ) {
F_5 ( & V_2 -> V_11 ) ;
F_35 ( L_36 ) ;
return - V_119 ;
}
F_12 ( V_2 , V_118 ) ;
V_2 -> V_22 ++ ;
V_2 -> V_120 = 0 ;
if ( ! F_65 ( & V_2 -> V_121 ) )
V_108 = 1 ;
else
V_110 = V_2 -> V_122 ;
V_109 = F_62 ( V_2 ,
& V_2 -> V_114 . V_123 ) ;
F_5 ( & V_2 -> V_11 ) ;
V_20 = F_49 ( V_2 ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
V_20 = F_66 ( V_2 , NULL , 0 ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
V_2 -> V_114 . V_125 = V_2 -> V_126 ;
V_2 -> V_114 . V_127 = V_128 ;
V_2 -> V_129 &= ~ V_130 ;
V_2 -> V_129 &= ~ V_131 ;
V_20 = F_67 ( NULL , V_2 -> V_25 -> V_132 , V_72 ,
& V_72 -> V_113 , & V_2 -> V_114 , NULL ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
V_111 = F_68 ( V_2 , & V_133 ) ;
if ( V_111 == NULL )
GOTO ( V_124 , V_20 = - V_134 ) ;
V_20 = F_69 ( V_111 , V_135 ,
V_2 -> V_136 , V_112 , NULL ) ;
if ( V_20 ) {
F_70 ( V_111 ) ;
GOTO ( V_124 , V_20 ) ;
}
F_71 ( V_111 -> V_137 ,
F_72 ( V_111 -> V_138 ) ) ;
V_111 -> V_138 = V_139 ;
F_73 ( V_111 -> V_137 , V_111 -> V_138 ) ;
F_74 ( V_111 -> V_137 , V_140 ) ;
V_111 -> V_141 = V_111 -> V_142 = 1 ;
V_111 -> V_143 = V_118 ;
F_75 ( & V_111 -> V_144 , & V_145 , V_146 ,
sizeof( struct V_147 ) + 16 * sizeof( T_3 ) ) ;
F_76 ( V_111 ) ;
V_111 -> V_148 = V_149 ;
F_77 ( sizeof( * V_116 ) <= sizeof( V_111 -> V_150 ) ) ;
V_116 = F_78 ( V_111 ) ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_151 = V_110 ;
V_116 -> V_152 = V_108 ;
if ( V_116 -> V_152 ) {
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_26 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
F_74 ( V_111 -> V_137 ,
V_153 ) ;
}
if ( V_109 )
F_74 ( V_111 -> V_137 ,
V_154 ) ;
F_37 ( V_62 , V_111 , L_37 ,
V_111 -> V_138 ) ;
F_79 ( V_111 , V_155 , - 1 ) ;
V_20 = 0 ;
V_124:
if ( V_20 != 0 ) {
F_80 ( V_2 , V_31 ) ;
}
return V_20 ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_156 ;
F_4 ( & V_2 -> V_11 ) ;
V_156 = V_2 -> V_76 != 0 ;
F_5 ( & V_2 -> V_11 ) ;
if ( V_156 )
F_44 () ;
}
static int F_82 ( int V_20 )
{
return ( V_20 == - V_157 ) || ( V_20 == - V_158 ) ;
}
static int V_149 ( const struct V_159 * V_160 ,
struct V_39 * V_111 ,
void * V_161 , int V_20 )
{
struct V_115 * V_116 = V_161 ;
struct V_1 * V_2 = V_111 -> V_162 ;
struct V_163 * V_164 = & V_2 -> V_25 -> V_165 . V_164 ;
struct V_166 V_167 ;
T_3 V_168 ;
int V_169 ;
struct V_147 * V_170 ;
struct V_81 * exp ;
int V_171 ;
F_4 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_5 == V_117 ) {
V_2 -> V_172 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
return 0 ;
}
if ( V_20 ) {
V_2 -> V_90 = F_82 ( V_20 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_81 ( V_2 ) ;
GOTO ( V_124 , V_20 ) ;
}
F_5 ( & V_2 -> V_11 ) ;
F_18 ( V_2 -> V_91 ) ;
V_169 = F_83 ( V_111 -> V_173 ) ;
V_171 = F_84 ( & V_111 -> V_144 , & V_145 ,
V_146 ) ;
V_170 = F_85 ( & V_111 -> V_144 ,
& V_145 , V_171 ) ;
if ( V_170 == NULL ) {
F_35 ( L_38 ,
V_2 -> V_25 -> V_27 ) ;
V_20 = - V_174 ;
GOTO ( V_124 , V_20 ) ;
}
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_175 = 1 ;
V_2 -> V_90 = 0 ;
V_2 -> V_76 = 0 ;
V_2 -> V_114 = * V_170 ;
F_15 ( V_34 , L_39 ,
V_2 -> V_25 -> V_27 , V_170 -> V_176 ) ;
exp = F_60 ( & V_2 -> V_100 ) ;
F_5 ( & V_2 -> V_11 ) ;
if ( ( V_170 -> V_125 & V_2 -> V_126 ) !=
V_170 -> V_125 ) {
F_35 ( L_40
L_41 V_177 L_42 V_177 L_26 ,
V_2 -> V_25 -> V_27 , V_2 -> V_126 ,
V_170 -> V_125 ) ;
GOTO ( V_124 , V_20 = - V_174 ) ;
}
if ( ! exp ) {
F_35 ( L_43 ,
V_2 -> V_25 -> V_27 ) ;
GOTO ( V_124 , V_20 = - V_178 ) ;
}
V_168 = F_86 ( exp ) ;
exp -> V_179 = * V_170 ;
V_2 -> V_25 -> V_132 -> V_179 = * V_170 ;
F_61 ( exp ) ;
F_14 ( V_2 -> V_25 , V_2 , V_180 ) ;
if ( V_116 -> V_152 ) {
F_4 ( & V_2 -> V_11 ) ;
if ( V_169 & V_181 ) {
V_2 -> V_26 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
F_15 ( V_34 , L_44 ,
F_8 ( V_2 -> V_25 ) ) ;
} else {
V_2 -> V_26 = 0 ;
F_5 ( & V_2 -> V_11 ) ;
}
V_2 -> V_121 =
* F_87 ( V_111 -> V_173 ) ;
if ( V_169 & V_182 ) {
F_15 ( V_34 , L_45 ,
F_8 ( V_2 -> V_25 ) ) ;
F_80 ( V_2 , V_183 ) ;
} else {
F_80 ( V_2 , V_21 ) ;
F_42 ( V_2 ) ;
}
GOTO ( V_184 , V_20 = 0 ) ;
}
if ( V_185 & V_169 ) {
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
if ( ! memcmp ( & V_167 , F_87 ( V_111 -> V_173 ) ,
sizeof( V_167 ) ) ) {
F_9 ( L_46
L_47 V_177 L_26 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ,
V_2 -> V_100 . V_186 ) ;
GOTO ( V_124 , V_20 = - V_187 ) ;
}
if ( memcmp ( & V_2 -> V_121 ,
F_87 ( V_111 -> V_173 ) ,
sizeof( V_2 -> V_121 ) ) ) {
int V_188 = V_169 & V_182 ?
V_34 : V_189 ;
if ( ( V_182 & V_169 ) ) {
F_15 ( V_188 , L_48
V_177 L_49 V_177
L_50 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ,
V_2 -> V_121 . V_186 ,
F_87 (
V_111 -> V_173 ) -> V_186 ) ;
} else {
F_9 ( L_51
L_52
V_177 L_49 V_177 L_26 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> \
V_75 . V_14 ,
V_2 -> V_121 . V_186 ,
F_87 (
V_111 -> V_173 ) -> V_186 ) ;
}
V_2 -> V_121 =
* F_87 ( V_111 -> V_173 ) ;
if ( ! ( V_182 & V_169 ) ) {
F_80 ( V_2 , V_190 ) ;
GOTO ( V_184 , V_20 = 0 ) ;
}
} else {
F_15 ( V_34 , L_53 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ) ;
}
if ( V_2 -> V_37 ) {
F_15 ( V_34 , L_54
L_55 , V_2 -> V_25 -> V_27 ) ;
F_80 ( V_2 , V_190 ) ;
} else if ( V_182 & V_169 ) {
F_15 ( V_34 , L_56 ,
V_2 -> V_25 -> V_27 ,
F_8 ( V_2 -> V_25 ) ) ;
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_120 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
F_80 ( V_2 , V_191 ) ;
} else {
F_80 ( V_2 , V_192 ) ;
}
} else if ( ( V_182 & V_169 ) && ! V_2 -> V_37 ) {
F_18 ( V_2 -> V_26 ) ;
V_2 -> V_121 =
* F_87 ( V_111 -> V_173 ) ;
V_2 -> V_193 = 0 ;
F_80 ( V_2 , V_191 ) ;
} else {
F_37 ( V_34 , V_111 , L_57
L_58 , V_2 -> V_25 -> V_27 , V_169 ) ;
V_2 -> V_121 =
* F_87 ( V_111 -> V_173 ) ;
F_80 ( V_2 , V_190 ) ;
}
if ( ! ( V_2 -> V_26 ) != ! ( V_169 & V_181 ) ) {
F_35 ( L_59
L_60 ) ;
}
if ( F_88 ( V_111 -> V_173 ) > 0 &&
F_88 ( V_111 -> V_173 ) <
V_116 -> V_151 ) {
F_35 ( L_61 V_194
L_62 V_194
L_63
L_64 ,
F_8 ( V_2 -> V_25 ) , V_116 -> V_151 ,
F_88 ( V_111 -> V_173 ) ) ;
}
V_184:
V_20 = F_89 ( V_2 ) ;
if ( V_20 != 0 ) {
if ( V_20 == - V_187 ) {
F_15 ( V_34 , L_65
L_66 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ) ;
F_64 ( V_2 ) ;
V_2 -> V_172 = 1 ;
return 0 ;
}
} else {
F_4 ( & V_2 -> V_11 ) ;
F_90 ( & V_2 -> V_91 -> V_93 ) ;
F_91 ( & V_2 -> V_91 -> V_93 ,
& V_2 -> V_84 ) ;
V_2 -> V_89 =
V_2 -> V_91 -> V_88 ;
F_5 ( & V_2 -> V_11 ) ;
if ( ! V_170 -> V_195 &&
V_170 -> V_125 & V_196 )
F_35 ( L_67
L_68 ) ;
if ( ( V_170 -> V_125 & V_197 ) &&
( V_170 -> V_127 > V_128 +
V_198 ||
V_170 -> V_127 < V_128 -
V_198 ) ) {
const char * V_199 = L_69
L_70 ;
const char * V_200 = L_71
L_72 ;
F_9 ( L_73
L_74 ,
F_8 ( V_2 -> V_25 ) ,
F_92 ( V_170 -> V_127 ) ,
F_93 ( V_170 -> V_127 ) ,
F_94 ( V_170 -> V_127 ) ,
F_95 ( V_170 -> V_127 ) ,
V_170 -> V_127 > V_128 ?
V_200 : V_199 , V_201 ) ;
}
#if V_128 < F_96 ( 3 , 2 , 50 , 0 )
if ( F_97 ( ( V_170 -> V_125 & V_197 ) &&
! ( V_170 -> V_125 & V_202 ) &&
F_92 ( V_170 -> V_127 ) == 2 &&
F_93 ( V_170 -> V_127 ) == 2 &&
F_94 ( V_170 -> V_127 ) < 55 &&
strcmp ( V_2 -> V_25 -> V_203 -> V_204 ,
V_205 ) == 0 ) )
V_2 -> V_206 = 1 ;
else
V_2 -> V_206 = 0 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
if ( V_170 -> V_125 & V_207 ) {
if ( ( V_170 -> V_208 &
F_98 () ) == 0 ) {
F_9 ( L_75
L_76
L_77
L_78 ,
F_8 ( V_2 -> V_25 ) ,
V_170 -> V_208 ,
F_98 () ) ;
V_164 -> V_209 = 0 ;
V_164 -> V_210 = V_211 ;
} else {
V_164 -> V_210 = V_170 -> V_208 ;
}
} else {
V_164 -> V_210 = V_211 ;
}
V_164 -> V_212 = F_99 ( V_164 -> V_210 ) ;
if ( V_170 -> V_125 & V_213 )
V_164 -> V_214 =
F_100 ( V_170 -> V_215 >> V_216 ,
V_164 -> V_214 ) ;
else if ( V_2 -> V_136 == V_217 ||
V_2 -> V_136 == V_218 )
V_164 -> V_214 = 1 ;
if ( V_168 != F_86 ( exp ) ||
V_116 -> V_152 ) {
F_15 ( V_34 , L_79
L_80 V_177 L_26 , V_2 -> V_25 -> V_27 ,
V_170 -> V_125 ) ;
V_2 -> V_25 -> V_219 -> V_220 =
V_170 -> V_125 ;
V_2 -> V_25 -> V_219 -> V_221 =
V_170 -> V_125 ;
}
if ( ( V_170 -> V_125 & V_222 ) &&
( V_2 -> V_223 == V_224 ) )
V_2 -> V_129 |= V_130 ;
else
V_2 -> V_129 &= ~ V_130 ;
if ( ( V_170 -> V_125 & V_225 ) &&
( V_2 -> V_223 == V_224 ) )
V_2 -> V_129 |= V_131 ;
else
V_2 -> V_129 &= ~ V_131 ;
F_18 ( ( V_164 -> V_214 <= V_226 ) &&
( V_164 -> V_214 > 0 ) ) ;
}
V_124:
V_2 -> V_172 = 1 ;
if ( V_20 != 0 ) {
F_80 ( V_2 , V_31 ) ;
if ( V_20 == - V_227 ) {
V_2 -> V_25 -> V_59 = 1 ;
F_21 ( V_2 ) ;
}
if ( V_20 == - V_174 ) {
struct V_147 * V_170 ;
if ( V_111 -> V_173 == NULL )
return - V_174 ;
V_170 = F_101 ( & V_111 -> V_144 ,
& V_145 ) ;
if ( V_170 &&
( V_170 -> V_125 & V_197 ) &&
( V_170 -> V_127 != V_128 ) ) {
F_11 ( 0x16a , L_81
L_82
L_83
L_84
L_85 ,
F_8 ( V_2 -> V_25 ) ,
F_92 ( V_170 -> V_127 ) ,
F_93 ( V_170 -> V_127 ) ,
F_94 ( V_170 -> V_127 ) ,
F_95 ( V_170 -> V_127 ) ,
V_201 ) ;
F_21 ( V_2 ) ;
F_80 ( V_2 , V_117 ) ;
}
return - V_174 ;
}
F_81 ( V_2 ) ;
F_15 ( V_34 , L_86 ,
F_8 ( V_2 -> V_25 ) ,
( char * ) V_2 -> V_28 -> V_75 . V_14 , V_20 ) ;
}
F_41 ( & V_2 -> V_63 ) ;
return V_20 ;
}
static int F_102 ( const struct V_159 * V_160 ,
struct V_39 * V_40 ,
void * V_161 , int V_20 )
{
F_40 ( & V_40 -> V_162 -> V_228 ) ;
if ( V_40 -> V_229 == 0 &&
! V_40 -> V_162 -> V_230 ) {
F_89 ( V_40 -> V_162 ) ;
} else {
if ( V_40 -> V_162 -> V_230 ) {
F_15 ( V_189 ,
L_87 ,
V_40 -> V_162 -> V_25 -> V_27 ) ;
} else {
F_15 ( V_34 , L_88
L_89 ,
V_40 -> V_162 -> V_25 -> V_27 ,
V_40 -> V_229 ) ;
}
F_64 ( V_40 -> V_162 ) ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
if ( F_97 ( F_29 ( V_231 ) ) )
return 0 ;
F_18 ( F_34 ( & V_2 -> V_228 ) == 0 ) ;
F_28 ( & V_2 -> V_228 ) ;
V_40 = F_104 ( V_2 , & V_232 , V_135 ,
V_233 ) ;
if ( V_40 == NULL ) {
F_40 ( & V_2 -> V_228 ) ;
return - V_134 ;
}
F_76 ( V_40 ) ;
V_40 -> V_143 = V_234 ;
F_105 ( V_40 -> V_137 ,
V_235 | V_236 ) ;
if ( V_237 )
V_40 -> V_138 *= 3 ;
V_40 -> V_148 = F_102 ;
F_79 ( V_40 , V_155 , - 1 ) ;
return 0 ;
}
static int F_106 ( void * V_161 )
{
struct V_1 * V_2 = V_161 ;
F_107 () ;
F_15 ( V_34 , L_90 ,
V_2 -> V_25 -> V_27 , F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ) ;
F_27 ( V_2 ) ;
if ( V_238 ) {
F_35 ( L_91 ) ;
F_13 () ;
}
F_80 ( V_2 , V_192 ) ;
F_89 ( V_2 ) ;
F_108 ( V_2 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
int V_239 ;
char * V_23 ;
int V_24 ;
if ( V_2 -> V_5 == V_190 ) {
F_6 ( F_8 ( V_2 -> V_25 ) , NULL ,
& V_23 , & V_24 ) ;
if ( strcmp ( V_2 -> V_25 -> V_203 -> V_204 ,
V_205 ) != 0 ) {
F_11 ( 0x167 , L_92
L_93
L_94 ,
V_2 -> V_25 -> V_27 , V_24 ,
V_23 ) ;
}
F_15 ( V_34 , L_95 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ) ;
F_4 ( & V_2 -> V_11 ) ;
V_2 -> V_230 = 0 ;
F_5 ( & V_2 -> V_11 ) ;
{
struct V_240 * V_241 ;
F_109 ( V_2 ) ;
V_241 = F_110 ( F_106 , V_2 ,
L_96 ) ;
if ( F_111 ( V_241 ) ) {
F_108 ( V_2 ) ;
F_35 ( L_97 , V_20 ) ;
V_20 = F_112 ( V_241 ) ;
} else {
V_20 = 0 ;
}
return V_20 ;
}
}
if ( V_2 -> V_5 == V_191 ) {
F_15 ( V_34 , L_98 ,
F_8 ( V_2 -> V_25 ) ) ;
V_20 = F_113 ( V_2 , & V_239 ) ;
if ( V_239 == 0 &&
F_34 ( & V_2 -> V_228 ) == 0 ) {
F_80 ( V_2 , V_183 ) ;
V_20 = F_114 ( V_2 ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
}
V_20 = 0 ;
}
if ( V_2 -> V_5 == V_183 ) {
if ( F_34 ( & V_2 -> V_228 ) == 0 ) {
F_80 ( V_2 , V_234 ) ;
V_20 = F_103 ( V_2 ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
}
}
if ( V_2 -> V_5 == V_234 ) {
if ( F_34 ( & V_2 -> V_228 ) == 0 ) {
F_80 ( V_2 , V_192 ) ;
}
}
if ( V_2 -> V_5 == V_192 ) {
F_15 ( V_34 , L_99 ,
F_8 ( V_2 -> V_25 ) ,
V_2 -> V_28 -> V_75 . V_14 ) ;
V_20 = F_115 ( V_2 ) ;
if ( V_20 )
GOTO ( V_124 , V_20 ) ;
F_80 ( V_2 , V_21 ) ;
F_42 ( V_2 ) ;
F_6 ( F_8 ( V_2 -> V_25 ) , NULL ,
& V_23 , & V_24 ) ;
F_116 ( L_100 ,
V_2 -> V_25 -> V_27 ,
V_24 , V_23 ,
F_10 ( V_2 -> V_28 -> V_29 . V_30 ) ) ;
}
if ( V_2 -> V_5 == V_21 ) {
F_41 ( & V_2 -> V_63 ) ;
F_117 ( V_2 ) ;
}
V_124:
return V_20 ;
}
int F_46 ( struct V_1 * V_2 , int V_242 )
{
struct V_39 * V_40 ;
int V_243 , V_20 = 0 ;
int V_244 = V_2 -> V_25 -> V_245 ;
if ( V_244 )
GOTO ( V_246 , V_20 ) ;
switch ( V_2 -> V_136 ) {
case V_247 : V_243 = V_248 ; break;
case V_217 : V_243 = V_249 ; break;
case V_218 : V_243 = V_250 ; break;
default:
F_35 ( L_101 ,
F_8 ( V_2 -> V_25 ) , V_2 -> V_136 ) ;
return - V_85 ;
}
if ( F_118 ( V_2 ) ) {
struct V_56 V_57 ;
T_4 V_54 ;
if ( V_237 ) {
if ( V_2 -> V_251 )
V_54 = F_32 ( V_61 / 2 ) ;
else
V_54 = F_32 ( V_61 ) ;
} else {
int V_252 = F_119 ( V_2 ,
V_2 -> V_35 -> V_253 ) ;
V_54 = F_32 (
F_54 ( & V_2 -> V_96 . V_254 [ V_252 ] ) ) ;
}
V_57 = F_120 ( F_31 ( V_54 ) ,
V_255 , V_77 , NULL ) ;
V_20 = F_33 ( V_2 -> V_63 ,
! F_118 ( V_2 ) , & V_57 ) ;
}
F_4 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_5 != V_21 )
GOTO ( V_124 , 0 ) ;
F_5 ( & V_2 -> V_11 ) ;
V_40 = F_104 ( V_2 , & V_256 ,
V_135 , V_243 ) ;
if ( V_40 ) {
V_40 -> V_141 = 1 ;
V_40 -> V_138 = F_121 ( int , V_40 -> V_138 ,
V_139 ) ;
F_80 ( V_2 , V_118 ) ;
V_40 -> V_143 = V_118 ;
F_76 ( V_40 ) ;
V_20 = F_122 ( V_40 ) ;
F_123 ( V_40 ) ;
}
V_246:
F_4 ( & V_2 -> V_11 ) ;
V_124:
if ( V_242 )
F_12 ( V_2 , V_31 ) ;
else
F_12 ( V_2 , V_117 ) ;
memset ( & V_2 -> V_121 , 0 , sizeof( V_2 -> V_121 ) ) ;
F_5 ( & V_2 -> V_11 ) ;
return V_20 ;
}
void F_124 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 ) ;
F_12 ( V_2 , V_117 ) ;
V_2 -> V_12 ++ ;
F_5 ( & V_2 -> V_11 ) ;
F_20 ( V_2 ) ;
}
int F_55 ( struct V_94 * V_95 , unsigned int V_257 )
{
unsigned int V_258 = V_95 -> V_259 ;
T_2 V_41 = F_2 () ;
T_2 V_260 = F_125 ( T_2 , V_261 / V_262 , 1 ) ;
F_18 ( V_95 ) ;
F_15 ( V_263 , L_102 ,
V_257 , V_95 , V_41 - V_95 -> V_264 , V_95 -> V_259 ,
V_95 -> V_265 [ 0 ] , V_95 -> V_265 [ 1 ] , V_95 -> V_265 [ 2 ] , V_95 -> V_265 [ 3 ] ) ;
if ( V_257 == 0 )
return 0 ;
F_4 ( & V_95 -> V_266 ) ;
if ( F_97 ( V_95 -> V_264 == 0 ) ) {
V_95 -> V_259 = V_257 ;
V_95 -> V_267 = V_257 ;
V_95 -> V_268 = V_41 ;
V_95 -> V_265 [ 0 ] = V_257 ;
V_95 -> V_264 = V_41 ;
} else if ( V_41 - V_95 -> V_264 < V_260 ) {
V_95 -> V_265 [ 0 ] = F_26 ( V_257 , V_95 -> V_265 [ 0 ] ) ;
V_95 -> V_259 = F_26 ( V_257 , V_95 -> V_259 ) ;
} else {
int V_269 , V_270 ;
unsigned int V_271 = V_257 ;
V_270 = ( V_41 - V_95 -> V_264 ) / V_260 ;
F_18 ( V_270 > 0 ) ;
for ( V_269 = V_262 - 1 ; V_269 >= 0 ; V_269 -- ) {
if ( V_269 >= V_270 ) {
V_95 -> V_265 [ V_269 ] = V_95 -> V_265 [ V_269 - V_270 ] ;
V_271 = F_26 ( V_271 , V_95 -> V_265 [ V_269 ] ) ;
} else {
V_95 -> V_265 [ V_269 ] = 0 ;
}
}
V_95 -> V_265 [ 0 ] = V_257 ;
V_95 -> V_259 = V_271 ;
V_95 -> V_264 += V_270 * V_260 ;
}
if ( V_95 -> V_259 > V_95 -> V_267 ) {
V_95 -> V_267 = V_95 -> V_259 ;
V_95 -> V_268 = V_41 ;
}
if ( V_95 -> V_272 & V_273 )
V_95 -> V_259 = V_257 ;
if ( V_274 > 0 )
V_95 -> V_259 = F_100 ( V_95 -> V_259 , V_274 ) ;
V_95 -> V_259 = F_26 ( V_95 -> V_259 , V_275 ) ;
if ( V_95 -> V_259 != V_258 )
F_15 ( V_263 , L_103
L_104 , V_95 ,
V_258 , V_95 -> V_259 , V_95 -> V_259 - V_258 , V_257 ,
V_95 -> V_265 [ 0 ] , V_95 -> V_265 [ 1 ] , V_95 -> V_265 [ 2 ] ,
V_95 -> V_265 [ 3 ] ) ;
V_258 = ( V_95 -> V_259 != V_258 ) ? V_258 : 0 ;
F_5 ( & V_95 -> V_266 ) ;
return V_258 ;
}
int F_119 ( struct V_1 * V_2 , int V_276 )
{
struct V_96 * V_95 = & V_2 -> V_96 ;
int V_269 ;
for ( V_269 = 0 ; V_269 < V_277 ; V_269 ++ ) {
if ( V_95 -> V_278 [ V_269 ] == V_276 )
return V_269 ;
if ( V_95 -> V_278 [ V_269 ] == 0 )
break;
}
F_4 ( & V_2 -> V_11 ) ;
for (; V_269 < V_277 ; V_269 ++ ) {
if ( V_95 -> V_278 [ V_269 ] == V_276 )
goto V_124;
if ( V_95 -> V_278 [ V_269 ] == 0 )
break;
}
F_18 ( V_269 < V_277 ) ;
V_95 -> V_278 [ V_269 ] = V_276 ;
V_124:
F_5 ( & V_2 -> V_11 ) ;
return V_269 ;
}
