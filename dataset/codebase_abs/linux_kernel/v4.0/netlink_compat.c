static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 ) ;
V_4 = V_5 - V_2 -> V_6 ;
if ( V_3 < V_4 )
return V_3 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 type , void * V_7 , T_1 V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) F_4 ( V_2 ) ;
if ( F_1 ( V_2 ) < F_5 ( V_6 ) )
return - V_10 ;
F_6 ( V_2 , F_5 ( V_6 ) ) ;
V_9 -> V_11 = F_7 ( type ) ;
V_9 -> V_12 = F_7 ( F_8 ( V_6 ) ) ;
if ( V_6 && V_7 )
memcpy ( F_9 ( V_9 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 type )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_7 ;
F_11 ( V_9 , 0 ) ;
F_12 ( V_9 , type ) ;
F_6 ( V_2 , sizeof( struct V_8 ) ) ;
}
static int F_13 ( struct V_1 * V_2 , const char * V_13 , ... )
{
int V_14 ;
T_1 V_6 ;
T_2 V_15 ;
char * V_16 ;
struct V_8 * V_9 ;
T_3 args ;
V_15 = F_1 ( V_2 ) ;
V_9 = (struct V_8 * ) V_2 -> V_7 ;
V_6 = F_14 ( V_9 ) ;
V_16 = F_9 ( V_9 ) + V_6 ;
va_start ( args , V_13 ) ;
V_14 = F_15 ( V_16 , V_15 , V_13 , args ) ;
va_end ( args ) ;
F_11 ( V_9 , V_14 + V_6 ) ;
F_6 ( V_2 , V_14 ) ;
return V_14 ;
}
static struct V_1 * F_16 ( int V_17 )
{
int V_18 ;
struct V_1 * V_16 ;
V_17 = F_5 ( V_17 ) ;
V_18 = F_17 ( V_19 + V_20 ) ;
V_16 = F_18 ( V_18 + V_17 , V_21 ) ;
if ( ! V_16 )
return NULL ;
F_19 ( V_16 , V_18 ) ;
return V_16 ;
}
static struct V_1 * F_20 ( char * V_22 )
{
int V_23 = strlen ( V_22 ) + 1 ;
struct V_1 * V_16 ;
V_16 = F_16 ( F_5 ( V_23 ) ) ;
if ( V_16 )
F_3 ( V_16 , V_24 , V_22 , V_23 ) ;
return V_16 ;
}
static int F_21 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_1 * V_29 )
{
int V_6 = 0 ;
int V_30 ;
struct V_1 * V_16 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_35 = (struct V_31 * ) V_29 -> V_7 ;
V_34 . V_2 = V_29 ;
V_16 = F_22 ( V_36 , V_21 ) ;
if ( ! V_16 )
return - V_37 ;
V_16 -> V_38 = V_28 -> V_39 ;
do {
int V_15 ;
V_6 = (* V_26 -> V_40 )( V_16 , & V_34 ) ;
F_23 (nlmsg, nlmsg_hdr(buf), len, rem) {
struct V_41 * * V_42 ;
V_30 = F_24 ( V_32 , & V_42 ) ;
if ( V_30 )
goto V_43;
V_30 = (* V_26 -> V_44 )( V_28 , V_42 ) ;
if ( V_30 )
goto V_43;
if ( F_1 ( V_28 -> V_45 ) <= 1 ) {
V_30 = - V_10 ;
goto V_43;
}
}
F_25 ( V_16 ) ;
V_16 -> V_6 = 0 ;
} while ( V_6 );
V_30 = 0 ;
V_43:
F_26 ( V_16 ) ;
if ( V_30 == - V_10 ) {
if ( ( V_5 - V_28 -> V_45 -> V_6 ) <= 1 ) {
char * V_46 = F_4 ( V_28 -> V_45 ) ;
if ( * V_46 != '\0' )
sprintf ( V_46 - sizeof( V_47 ) - 1 ,
V_47 ) ;
}
return 0 ;
}
return V_30 ;
}
static int F_27 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
int V_30 ;
struct V_1 * V_29 ;
if ( V_28 -> V_48 && ! F_28 ( V_28 -> V_49 , V_28 -> V_48 ) )
return - V_50 ;
V_28 -> V_45 = F_16 ( V_28 -> V_51 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
if ( V_28 -> V_52 )
F_10 ( V_28 -> V_45 , V_28 -> V_52 ) ;
if ( V_26 -> V_53 )
(* V_26 -> V_53 )( V_28 ) ;
V_29 = F_22 ( 0 , V_21 ) ;
if ( ! V_29 ) {
F_26 ( V_28 -> V_45 ) ;
return - V_37 ;
}
V_30 = F_21 ( V_26 , V_28 , V_29 ) ;
if ( V_30 )
F_26 ( V_28 -> V_45 ) ;
F_26 ( V_29 ) ;
return V_30 ;
}
static int F_29 ( struct V_54 * V_26 ,
struct V_27 * V_28 )
{
int V_30 ;
struct V_1 * V_55 ;
struct V_1 * V_56 ;
struct V_41 * * V_57 ;
struct V_58 V_59 ;
V_56 = F_18 ( V_36 , V_21 ) ;
if ( ! V_56 )
return - V_37 ;
V_30 = (* V_26 -> V_60 )( V_56 , V_28 ) ;
if ( V_30 )
goto V_61;
V_57 = F_30 ( ( V_62 . V_63 + 1 ) *
sizeof( struct V_41 * ) , V_21 ) ;
if ( ! V_57 ) {
V_30 = - V_37 ;
goto V_61;
}
V_30 = F_31 ( V_57 , V_62 . V_63 ,
( const struct V_41 * ) V_56 -> V_7 ,
V_56 -> V_6 , NULL ) ;
if ( V_30 )
goto V_64;
V_55 = F_18 ( V_36 , V_21 ) ;
if ( ! V_55 ) {
V_30 = - V_37 ;
goto V_64;
}
V_55 -> V_38 = V_28 -> V_39 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_42 = V_57 ;
V_30 = (* V_26 -> V_65 )( V_55 , & V_59 ) ;
F_26 ( V_55 ) ;
V_64:
F_32 ( V_57 ) ;
V_61:
F_26 ( V_56 ) ;
return V_30 ;
}
static int F_33 ( struct V_54 * V_26 ,
struct V_27 * V_28 )
{
int V_30 ;
if ( V_28 -> V_48 && ! F_28 ( V_28 -> V_49 , V_28 -> V_48 ) )
return - V_50 ;
V_30 = F_29 ( V_26 , V_28 ) ;
if ( V_30 )
return V_30 ;
V_28 -> V_45 = F_16 ( 0 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_41 * V_66 [ V_67 + 1 ] ;
F_35 ( V_66 , V_67 , V_42 [ V_68 ] ,
NULL ) ;
return F_3 ( V_28 -> V_45 , V_69 ,
F_36 ( V_66 [ V_70 ] ) ,
F_37 ( V_66 [ V_70 ] ) ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_41 * V_71 ;
struct V_41 * V_66 ;
struct V_72 * V_73 ;
V_73 = (struct V_72 * ) F_9 ( V_28 -> V_49 ) ;
V_66 = F_39 ( V_2 , V_68 ) ;
if ( ! V_66 )
return - V_10 ;
if ( F_40 ( V_2 , V_70 , V_73 -> V_74 ) )
return - V_10 ;
if ( F_41 ( V_2 , V_75 , F_42 ( V_73 -> V_76 ) ) )
return - V_10 ;
if ( F_42 ( V_73 -> V_77 ) <= V_78 ) {
V_71 = F_39 ( V_2 , V_79 ) ;
if ( ! V_71 )
return - V_10 ;
if ( F_41 ( V_2 , V_80 , F_42 ( V_73 -> V_77 ) ) )
return - V_10 ;
F_43 ( V_2 , V_71 ) ;
}
F_43 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
char * V_74 ;
struct V_41 * V_66 ;
V_74 = ( char * ) F_9 ( V_28 -> V_49 ) ;
V_66 = F_39 ( V_2 , V_68 ) ;
if ( ! V_66 )
return - V_10 ;
if ( F_40 ( V_2 , V_70 , V_74 ) )
return - V_10 ;
F_43 ( V_2 , V_66 ) ;
return 0 ;
}
static inline T_2 F_45 ( T_2 V_81 , T_2 V_82 )
{
return ( V_81 * 100 + ( V_82 / 2 ) ) / V_82 ;
}
static void F_46 ( struct V_27 * V_28 ,
struct V_41 * V_71 [] , struct V_41 * V_83 [] )
{
F_13 ( V_28 -> V_45 , L_1 ,
F_47 ( V_71 [ V_84 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_2 ,
F_47 ( V_83 [ V_85 ] ) ,
F_47 ( V_83 [ V_86 ] ) ,
F_47 ( V_83 [ V_87 ] ) ,
F_47 ( V_83 [ V_88 ] ) ,
F_47 ( V_83 [ V_89 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_3 ,
F_47 ( V_83 [ V_90 ] ) ,
F_47 ( V_83 [ V_91 ] ) ,
F_47 ( V_83 [ V_92 ] ) ,
F_47 ( V_83 [ V_93 ] ) ,
F_47 ( V_83 [ V_94 ] ) ) ;
F_13 ( V_28 -> V_45 , L_4 ,
F_47 ( V_83 [ V_95 ] ) ,
F_47 ( V_83 [ V_96 ] ) ,
F_47 ( V_83 [ V_97 ] ) ) ;
F_13 ( V_28 -> V_45 , L_5 ,
F_47 ( V_83 [ V_98 ] ) ,
F_47 ( V_83 [ V_99 ] ) ,
F_47 ( V_83 [ V_100 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_6 ,
F_47 ( V_83 [ V_101 ] ) ,
F_47 ( V_83 [ V_102 ] ) ,
F_47 ( V_83 [ V_103 ] ) ) ;
}
static int F_48 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
char * V_74 ;
struct V_41 * V_104 [ V_105 + 1 ] ;
struct V_41 * V_71 [ V_106 + 1 ] ;
struct V_41 * V_83 [ V_107 + 1 ] ;
F_35 ( V_104 , V_105 , V_42 [ V_108 ] , NULL ) ;
F_35 ( V_71 , V_106 , V_104 [ V_109 ] ,
NULL ) ;
F_35 ( V_83 , V_107 , V_104 [ V_110 ] ,
NULL ) ;
V_74 = ( char * ) F_9 ( V_28 -> V_49 ) ;
if ( strcmp ( V_74 , F_36 ( V_104 [ V_111 ] ) ) != 0 )
return 0 ;
F_13 ( V_28 -> V_45 , L_7 ,
F_36 ( V_104 [ V_111 ] ) ) ;
if ( V_104 [ V_112 ] ) {
F_46 ( V_28 , V_71 , V_83 ) ;
return 0 ;
}
if ( V_104 [ V_113 ] )
F_13 ( V_28 -> V_45 , L_8 ) ;
else if ( V_104 [ V_114 ] )
F_13 ( V_28 -> V_45 , L_9 ) ;
else
F_13 ( V_28 -> V_45 , L_10 ) ;
F_13 ( V_28 -> V_45 , L_11 ,
F_47 ( V_104 [ V_115 ] ) ,
F_47 ( V_71 [ V_80 ] ) ) ;
F_13 ( V_28 -> V_45 , L_12 ,
F_47 ( V_71 [ V_116 ] ) ,
F_47 ( V_71 [ V_84 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_2 ,
F_47 ( V_104 [ V_117 ] ) -
F_47 ( V_83 [ V_85 ] ) ,
F_47 ( V_83 [ V_86 ] ) ,
F_47 ( V_83 [ V_87 ] ) ,
F_47 ( V_83 [ V_88 ] ) ,
F_47 ( V_83 [ V_89 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_3 ,
F_47 ( V_104 [ V_118 ] ) -
F_47 ( V_83 [ V_90 ] ) ,
F_47 ( V_83 [ V_91 ] ) ,
F_47 ( V_83 [ V_92 ] ) ,
F_47 ( V_83 [ V_93 ] ) ,
F_47 ( V_83 [ V_94 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_13 ,
F_47 ( V_83 [ V_119 ] ) ,
F_47 ( V_83 [ V_120 ] ) /
F_47 ( V_83 [ V_121 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_14 ,
F_45 ( F_47 ( V_83 [ V_122 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ,
F_45 ( F_47 ( V_83 [ V_123 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ,
F_45 ( F_47 ( V_83 [ V_124 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ,
F_45 ( F_47 ( V_83 [ V_125 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ) ;
F_13 ( V_28 -> V_45 , L_15 ,
F_45 ( F_47 ( V_83 [ V_126 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ,
F_45 ( F_47 ( V_83 [ V_127 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ,
F_45 ( F_47 ( V_83 [ V_128 ] ) ,
F_47 ( V_83 [ V_121 ] ) ) ) ;
F_13 ( V_28 -> V_45 ,
L_16 ,
F_47 ( V_83 [ V_129 ] ) ,
F_47 ( V_83 [ V_130 ] ) ,
F_47 ( V_83 [ V_95 ] ) ,
F_47 ( V_83 [ V_96 ] ) ,
F_47 ( V_83 [ V_97 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_17 ,
F_47 ( V_83 [ V_131 ] ) ,
F_47 ( V_83 [ V_132 ] ) ,
F_47 ( V_83 [ V_98 ] ) ,
F_47 ( V_83 [ V_99 ] ) ,
F_47 ( V_83 [ V_100 ] ) ) ;
F_13 ( V_28 -> V_45 ,
L_6 ,
F_47 ( V_83 [ V_101 ] ) ,
F_47 ( V_83 [ V_102 ] ) ,
F_47 ( V_83 [ V_103 ] ) ) ;
return 0 ;
}
static int F_49 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_41 * V_104 [ V_105 + 1 ] ;
struct V_133 V_134 ;
F_35 ( V_104 , V_105 , V_42 [ V_108 ] , NULL ) ;
V_134 . V_135 = F_50 ( V_104 [ V_136 ] ) ;
V_134 . V_137 = F_51 ( F_50 ( V_104 [ V_114 ] ) ) ;
strcpy ( V_134 . V_22 , F_36 ( V_104 [ V_111 ] ) ) ;
return F_3 ( V_28 -> V_45 , V_138 ,
& V_134 , sizeof( V_134 ) ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_41 * V_104 ;
struct V_41 * V_71 ;
struct V_139 * V_140 ;
V_140 = (struct V_139 * ) F_9 ( V_28 -> V_49 ) ;
V_104 = F_39 ( V_2 , V_108 ) ;
if ( ! V_104 )
return - V_10 ;
if ( F_40 ( V_2 , V_111 , V_140 -> V_74 ) )
return - V_10 ;
V_71 = F_39 ( V_2 , V_109 ) ;
if ( ! V_71 )
return - V_10 ;
if ( V_28 -> V_26 == V_141 ) {
if ( F_41 ( V_2 , V_80 , F_42 ( V_140 -> V_142 ) ) )
return - V_10 ;
} else if ( V_28 -> V_26 == V_143 ) {
if ( F_41 ( V_2 , V_116 , F_42 ( V_140 -> V_142 ) ) )
return - V_10 ;
} else if ( V_28 -> V_26 == V_144 ) {
if ( F_41 ( V_2 , V_84 , F_42 ( V_140 -> V_142 ) ) )
return - V_10 ;
}
F_43 ( V_2 , V_71 ) ;
F_43 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
char * V_74 ;
struct V_41 * V_104 ;
V_74 = ( char * ) F_9 ( V_28 -> V_49 ) ;
V_104 = F_39 ( V_2 , V_108 ) ;
if ( ! V_104 )
return - V_10 ;
if ( F_40 ( V_2 , V_111 , V_74 ) )
return - V_10 ;
F_43 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_54 ( struct V_27 * V_28 )
{
int V_145 ;
T_2 V_146 ;
struct V_147 * V_148 ;
static const char * const V_53 [] = {
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_148 = (struct V_147 * ) F_9 ( V_28 -> V_49 ) ;
V_146 = F_42 ( V_148 -> V_146 ) ;
if ( V_146 > 4 )
V_146 = 4 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
F_13 ( V_28 -> V_45 , V_53 [ V_145 ] ) ;
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_55 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
char V_149 [ 27 ] ;
struct V_147 * V_148 ;
struct V_41 * V_150 [ V_151 + 1 ] ;
struct V_41 * V_152 [ V_153 + 1 ] ;
T_2 V_154 , V_146 , type , V_155 , V_156 ;
static const char * const V_157 [] = { L_23 , L_24 , L_25 ,
L_26 } ;
F_35 ( V_150 , V_151 ,
V_42 [ V_158 ] , NULL ) ;
F_35 ( V_152 , V_153 , V_150 [ V_159 ] ,
NULL ) ;
V_148 = (struct V_147 * ) F_9 ( V_28 -> V_49 ) ;
V_146 = F_42 ( V_148 -> V_146 ) ;
type = F_42 ( V_148 -> type ) ;
V_155 = F_42 ( V_148 -> V_155 ) ;
V_156 = F_42 ( V_148 -> V_156 ) ;
if ( ! ( V_146 & V_160 ) &&
( type != F_47 ( V_152 [ V_161 ] ) ) )
return 0 ;
if ( V_155 && ( V_155 > F_47 ( V_152 [ V_162 ] ) ) )
return 0 ;
if ( V_156 && ( V_156 < F_47 ( V_152 [ V_163 ] ) ) )
return 0 ;
F_13 ( V_28 -> V_45 , L_27 ,
F_47 ( V_152 [ V_161 ] ) ) ;
if ( V_146 == 1 )
goto V_164;
F_13 ( V_28 -> V_45 , L_28 ,
F_47 ( V_152 [ V_163 ] ) ,
F_47 ( V_152 [ V_162 ] ) ) ;
if ( V_146 == 2 )
goto V_164;
V_154 = F_47 ( V_152 [ V_165 ] ) ;
sprintf ( V_149 , L_29 , F_56 ( V_154 ) , F_57 ( V_154 ) ,
F_58 ( V_154 ) , F_47 ( V_152 [ V_166 ] ) ) ;
F_13 ( V_28 -> V_45 , L_30 , V_149 ) ;
if ( V_146 == 3 )
goto V_164;
F_13 ( V_28 -> V_45 , L_31 ,
F_47 ( V_152 [ V_166 ] ) ,
V_157 [ F_47 ( V_152 [ V_167 ] ) ] ) ;
V_164:
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_59 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
T_2 type , V_168 , V_169 ;
struct V_41 * V_152 [ V_153 + 1 ] ;
F_35 ( V_152 , V_153 , V_42 [ V_170 ] , NULL ) ;
type = F_47 ( V_152 [ V_161 ] ) ;
V_168 = F_47 ( V_152 [ V_163 ] ) ;
V_169 = F_47 ( V_152 [ V_162 ] ) ;
if ( V_168 == V_169 )
F_13 ( V_28 -> V_45 , L_32 , type , V_168 ) ;
else
F_13 ( V_28 -> V_45 , L_33 , type , V_168 , V_169 ) ;
return 0 ;
}
static int F_60 ( struct V_27 * V_28 , T_2 V_171 )
{
int V_30 ;
void * V_172 ;
struct V_41 * V_173 ;
struct V_1 * args ;
struct V_25 V_174 ;
args = F_22 ( V_36 , V_21 ) ;
if ( ! args )
return - V_37 ;
V_172 = F_61 ( args , 0 , 0 , & V_62 , V_175 ,
V_176 ) ;
V_173 = F_39 ( args , V_177 ) ;
if ( ! V_173 ) {
F_26 ( args ) ;
return - V_10 ;
}
if ( F_41 ( args , V_178 , V_171 ) ) {
F_26 ( args ) ;
return - V_10 ;
}
F_43 ( args , V_173 ) ;
F_62 ( args , V_172 ) ;
V_174 . V_40 = V_179 ;
V_174 . V_44 = F_59 ;
V_30 = F_21 ( & V_174 , V_28 , args ) ;
F_26 ( args ) ;
return V_30 ;
}
static int F_63 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
int V_30 ;
T_2 V_180 ;
struct V_41 * V_171 [ V_181 + 1 ] ;
F_35 ( V_171 , V_181 , V_42 [ V_177 ] , NULL ) ;
V_180 = F_47 ( V_171 [ V_178 ] ) ;
F_13 ( V_28 -> V_45 , L_34 , V_180 ) ;
if ( V_171 [ V_182 ] ) {
T_2 V_154 ;
struct V_41 * V_183 [ V_184 + 1 ] ;
F_35 ( V_183 , V_184 , V_171 [ V_182 ] ,
NULL ) ;
V_154 = F_47 ( V_183 [ V_185 ] ) ;
F_13 ( V_28 -> V_45 , L_35 ,
F_56 ( V_154 ) ,
F_57 ( V_154 ) ,
F_58 ( V_154 ) ,
F_47 ( V_183 [ V_186 ] ) ) ;
if ( V_183 [ V_187 ] )
F_13 ( V_28 -> V_45 , L_36 ,
F_47 ( V_183 [ V_188 ] ) ,
F_47 ( V_183 [ V_189 ] ) ) ;
else
F_13 ( V_28 -> V_45 , L_22 ) ;
} else if ( V_171 [ V_190 ] ) {
F_13 ( V_28 -> V_45 , L_37 ) ;
V_30 = F_60 ( V_28 , V_180 ) ;
if ( V_30 )
return V_30 ;
}
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_64 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_41 * V_191 [ V_192 + 1 ] ;
F_35 ( V_191 , V_192 , V_42 [ V_193 ] ,
NULL ) ;
return F_3 ( V_28 -> V_45 , V_194 ,
F_36 ( V_191 [ V_195 ] ) ,
F_37 ( V_191 [ V_195 ] ) ) ;
}
static int F_65 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_196 V_197 ;
struct V_41 * V_154 [ V_198 + 1 ] ;
F_35 ( V_154 , V_198 , V_42 [ V_199 ] , NULL ) ;
V_197 . V_200 = F_51 ( F_47 ( V_154 [ V_201 ] ) ) ;
V_197 . V_137 = F_51 ( F_50 ( V_154 [ V_202 ] ) ) ;
return F_3 ( V_28 -> V_45 , V_203 , & V_197 ,
sizeof( V_197 ) ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_2 V_204 ;
struct V_41 * V_205 ;
V_204 = F_42 ( * ( V_206 * ) F_9 ( V_28 -> V_49 ) ) ;
V_205 = F_39 ( V_2 , V_207 ) ;
if ( ! V_205 )
return - V_10 ;
if ( V_28 -> V_26 == V_208 ) {
if ( F_41 ( V_2 , V_209 , V_204 ) )
return - V_10 ;
} else if ( V_28 -> V_26 == V_210 ) {
if ( F_41 ( V_2 , V_211 , V_204 ) )
return - V_10 ;
}
F_43 ( V_2 , V_205 ) ;
return 0 ;
}
static int F_67 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
V_206 V_212 ;
struct V_41 * V_205 [ V_213 + 1 ] ;
F_35 ( V_205 , V_213 , V_42 [ V_207 ] , NULL ) ;
V_212 = F_51 ( F_47 ( V_205 [ V_211 ] ) ) ;
return F_3 ( V_28 -> V_45 , V_214 , & V_212 , sizeof( V_212 ) ) ;
}
static int F_68 ( struct V_27 * V_28 )
{
V_28 -> V_45 = F_16 ( V_215 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
F_10 ( V_28 -> V_45 , V_216 ) ;
F_13 ( V_28 -> V_45 , L_38 V_217 L_22 ) ;
return 0 ;
}
static int F_69 ( struct V_27 * V_28 )
{
struct V_25 V_174 ;
struct V_54 V_65 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
switch ( V_28 -> V_26 ) {
case V_218 :
V_28 -> V_45 = F_16 ( 0 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
return 0 ;
case V_219 :
V_28 -> V_51 = V_220 * F_5 ( V_221 ) ;
V_174 . V_40 = V_222 ;
V_174 . V_44 = F_34 ;
return F_27 ( & V_174 , V_28 ) ;
case V_223 :
V_28 -> V_48 = V_224 ;
V_65 . V_65 = V_225 ;
V_65 . V_60 = F_38 ;
return F_33 ( & V_65 , V_28 ) ;
case V_226 :
V_28 -> V_48 = V_69 ;
V_65 . V_65 = V_227 ;
V_65 . V_60 = F_44 ;
return F_33 ( & V_65 , V_28 ) ;
case V_228 :
V_28 -> V_48 = V_229 ;
V_28 -> V_51 = V_215 ;
V_28 -> V_52 = V_216 ;
V_174 . V_40 = V_230 ;
V_174 . V_44 = F_48 ;
return F_27 ( & V_174 , V_28 ) ;
case V_231 :
V_28 -> V_48 = V_232 ;
V_28 -> V_51 = V_215 ;
V_174 . V_40 = V_230 ;
V_174 . V_44 = F_49 ;
return F_27 ( & V_174 , V_28 ) ;
case V_143 :
case V_141 :
case V_144 :
V_28 -> V_48 = V_233 ;
V_65 . V_65 = V_234 ;
V_65 . V_60 = F_52 ;
return F_33 ( & V_65 , V_28 ) ;
case V_235 :
V_28 -> V_48 = V_229 ;
V_65 . V_65 = V_236 ;
V_65 . V_60 = F_53 ;
return F_33 ( & V_65 , V_28 ) ;
case V_237 :
V_28 -> V_48 = V_238 ;
V_28 -> V_51 = V_215 ;
V_28 -> V_52 = V_216 ;
V_174 . V_53 = F_54 ;
V_174 . V_40 = V_239 ;
V_174 . V_44 = F_55 ;
return F_27 ( & V_174 , V_28 ) ;
case V_240 :
V_28 -> V_51 = V_215 ;
V_28 -> V_52 = V_216 ;
V_174 . V_40 = V_241 ;
V_174 . V_44 = F_63 ;
return F_27 ( & V_174 , V_28 ) ;
case V_242 :
V_28 -> V_51 = V_243 * F_5 ( V_244 ) ;
V_174 . V_40 = V_245 ;
V_174 . V_44 = F_64 ;
return F_27 ( & V_174 , V_28 ) ;
case V_246 :
V_28 -> V_51 = V_215 ;
V_174 . V_40 = V_247 ;
V_174 . V_44 = F_65 ;
return F_27 ( & V_174 , V_28 ) ;
case V_208 :
V_28 -> V_48 = V_232 ;
V_65 . V_65 = V_248 ;
V_65 . V_60 = F_66 ;
return F_33 ( & V_65 , V_28 ) ;
case V_210 :
V_28 -> V_48 = V_214 ;
V_65 . V_65 = V_248 ;
V_65 . V_60 = F_66 ;
return F_33 ( & V_65 , V_28 ) ;
case V_249 :
V_28 -> V_51 = sizeof( T_2 ) ;
V_174 . V_40 = V_250 ;
V_174 . V_44 = F_67 ;
return F_27 ( & V_174 , V_28 ) ;
case V_251 :
return F_68 ( V_28 ) ;
}
return - V_252 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
int V_30 ;
int V_6 ;
struct V_27 V_28 ;
struct V_31 * V_253 ;
struct V_31 * V_254 ;
struct V_255 * V_256 = V_59 -> V_257 ;
struct V_205 * V_205 = F_71 ( V_59 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_253 = (struct V_31 * ) V_2 -> V_7 ;
V_28 . V_49 = F_72 ( V_253 ) + V_19 + V_20 ;
V_28 . V_26 = V_256 -> V_26 ;
V_28 . V_39 = V_59 -> V_39 ;
if ( ( V_28 . V_26 & 0xC000 ) && ( ! F_73 ( V_2 , V_258 ) ) ) {
V_28 . V_45 = F_20 ( V_259 ) ;
V_30 = - V_260 ;
goto V_261;
}
V_6 = F_74 ( V_253 , V_19 + V_20 ) ;
if ( F_14 ( V_28 . V_49 ) && ! F_75 ( V_28 . V_49 , V_6 ) ) {
V_28 . V_45 = F_20 ( V_262 ) ;
V_30 = - V_252 ;
goto V_261;
}
V_30 = F_69 ( & V_28 ) ;
if ( V_30 == - V_252 )
V_28 . V_45 = F_20 ( V_262 ) ;
else if ( V_30 == - V_50 )
V_28 . V_45 = F_20 ( V_263 ) ;
V_261:
if ( ! V_28 . V_45 )
return V_30 ;
V_6 = F_17 ( V_19 + V_20 ) ;
F_76 ( V_28 . V_45 , V_6 ) ;
V_254 = F_77 ( V_28 . V_45 ) ;
memcpy ( V_254 , V_59 -> V_264 , V_6 ) ;
V_254 -> V_265 = V_28 . V_45 -> V_6 ;
F_78 ( V_205 , V_28 . V_45 , F_79 ( V_2 ) . V_266 ) ;
return V_30 ;
}
int F_80 ( void )
{
int V_267 ;
V_267 = F_81 ( & V_268 ,
V_269 ) ;
if ( V_267 ) {
F_82 ( L_39 ) ;
return V_267 ;
}
return 0 ;
}
void F_83 ( void )
{
F_84 ( & V_268 ) ;
}
