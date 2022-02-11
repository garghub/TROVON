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
V_30 = (* V_26 -> V_60 )( V_26 , V_56 , V_28 ) ;
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
V_56 -> V_6 , NULL , NULL ) ;
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
int V_30 ;
if ( ! V_42 [ V_68 ] )
return - V_50 ;
V_30 = F_35 ( V_66 , V_67 ,
V_42 [ V_68 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
return F_3 ( V_28 -> V_45 , V_69 ,
F_36 ( V_66 [ V_70 ] ) ,
F_37 ( V_66 [ V_70 ] ) ) ;
}
static int F_38 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
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
static int F_44 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
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
int V_30 ;
if ( ! V_42 [ V_108 ] )
return - V_50 ;
V_30 = F_35 ( V_104 , V_105 , V_42 [ V_108 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
if ( ! V_104 [ V_109 ] )
return - V_50 ;
V_30 = F_35 ( V_71 , V_106 ,
V_104 [ V_109 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
if ( ! V_104 [ V_110 ] )
return - V_50 ;
V_30 = F_35 ( V_83 , V_107 ,
V_104 [ V_110 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
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
int V_30 ;
if ( ! V_42 [ V_108 ] )
return - V_50 ;
V_30 = F_35 ( V_104 , V_105 , V_42 [ V_108 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
V_134 . V_135 = F_50 ( V_104 [ V_136 ] ) ;
V_134 . V_137 = F_51 ( F_50 ( V_104 [ V_114 ] ) ) ;
F_52 ( V_134 . V_22 , V_104 [ V_111 ] ,
V_138 ) ;
return F_3 ( V_28 -> V_45 , V_139 ,
& V_134 , sizeof( V_134 ) ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_140 * V_141 )
{
switch ( V_28 -> V_26 ) {
case V_142 :
return F_41 ( V_2 , V_80 , F_42 ( V_141 -> V_143 ) ) ;
case V_144 :
return F_41 ( V_2 , V_116 , F_42 ( V_141 -> V_143 ) ) ;
case V_145 :
return F_41 ( V_2 , V_84 , F_42 ( V_141 -> V_143 ) ) ;
}
return - V_50 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_41 * V_71 ;
struct V_41 * V_146 ;
struct V_140 * V_141 ;
V_141 = (struct V_140 * ) F_9 ( V_28 -> V_49 ) ;
V_146 = F_39 ( V_2 , V_147 ) ;
if ( ! V_146 )
return - V_10 ;
if ( F_40 ( V_2 , V_148 , V_141 -> V_74 ) )
return - V_10 ;
V_71 = F_39 ( V_2 , V_149 ) ;
if ( ! V_71 )
return - V_10 ;
F_53 ( V_2 , V_28 , V_141 ) ;
F_43 ( V_2 , V_71 ) ;
F_43 ( V_2 , V_146 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_41 * V_71 ;
struct V_41 * V_66 ;
struct V_140 * V_141 ;
V_141 = (struct V_140 * ) F_9 ( V_28 -> V_49 ) ;
V_66 = F_39 ( V_2 , V_68 ) ;
if ( ! V_66 )
return - V_10 ;
if ( F_40 ( V_2 , V_70 , V_141 -> V_74 ) )
return - V_10 ;
V_71 = F_39 ( V_2 , V_79 ) ;
if ( ! V_71 )
return - V_10 ;
F_53 ( V_2 , V_28 , V_141 ) ;
F_43 ( V_2 , V_71 ) ;
F_43 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_41 * V_71 ;
struct V_41 * V_104 ;
struct V_140 * V_141 ;
V_141 = (struct V_140 * ) F_9 ( V_28 -> V_49 ) ;
V_104 = F_39 ( V_2 , V_108 ) ;
if ( ! V_104 )
return - V_10 ;
if ( F_40 ( V_2 , V_111 , V_141 -> V_74 ) )
return - V_10 ;
V_71 = F_39 ( V_2 , V_109 ) ;
if ( ! V_71 )
return - V_10 ;
F_53 ( V_2 , V_28 , V_141 ) ;
F_43 ( V_2 , V_71 ) ;
F_43 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_57 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_140 * V_141 ;
struct V_150 * V_66 ;
struct V_151 * V_146 ;
V_141 = (struct V_140 * ) F_9 ( V_28 -> V_49 ) ;
V_146 = F_58 ( V_141 -> V_74 ) ;
if ( V_146 ) {
V_26 -> V_65 = & V_152 ;
return F_54 ( V_2 , V_28 ) ;
}
V_66 = F_59 ( V_28 -> V_153 , V_141 -> V_74 ) ;
if ( V_66 ) {
V_26 -> V_65 = & V_154 ;
return F_55 ( V_2 , V_28 ) ;
}
return F_56 ( V_2 , V_28 ) ;
}
static int F_60 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
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
static int F_61 ( struct V_27 * V_28 )
{
int V_155 ;
T_2 V_156 ;
struct V_157 * V_158 ;
static const char * const V_53 [] = {
L_18 ,
L_19 ,
L_20 ,
L_21
} ;
V_158 = (struct V_157 * ) F_9 ( V_28 -> V_49 ) ;
V_156 = F_42 ( V_158 -> V_156 ) ;
if ( V_156 > 4 )
V_156 = 4 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ )
F_13 ( V_28 -> V_45 , V_53 [ V_155 ] ) ;
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_62 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
char V_159 [ 27 ] ;
struct V_157 * V_158 ;
struct V_41 * V_160 [ V_161 + 1 ] ;
struct V_41 * V_162 [ V_163 + 1 ] ;
T_2 V_164 , V_156 , type , V_165 , V_166 ;
static const char * const V_167 [] = { L_23 , L_24 , L_25 ,
L_26 } ;
int V_30 ;
if ( ! V_42 [ V_168 ] )
return - V_50 ;
V_30 = F_35 ( V_160 , V_161 ,
V_42 [ V_168 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
if ( ! V_160 [ V_169 ] )
return - V_50 ;
V_30 = F_35 ( V_162 , V_163 ,
V_160 [ V_169 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
V_158 = (struct V_157 * ) F_9 ( V_28 -> V_49 ) ;
V_156 = F_42 ( V_158 -> V_156 ) ;
type = F_42 ( V_158 -> type ) ;
V_165 = F_42 ( V_158 -> V_165 ) ;
V_166 = F_42 ( V_158 -> V_166 ) ;
if ( ! ( V_156 & V_170 ) &&
( type != F_47 ( V_162 [ V_171 ] ) ) )
return 0 ;
if ( V_165 && ( V_165 > F_47 ( V_162 [ V_172 ] ) ) )
return 0 ;
if ( V_166 && ( V_166 < F_47 ( V_162 [ V_173 ] ) ) )
return 0 ;
F_13 ( V_28 -> V_45 , L_27 ,
F_47 ( V_162 [ V_171 ] ) ) ;
if ( V_156 == 1 )
goto V_174;
F_13 ( V_28 -> V_45 , L_28 ,
F_47 ( V_162 [ V_173 ] ) ,
F_47 ( V_162 [ V_172 ] ) ) ;
if ( V_156 == 2 )
goto V_174;
V_164 = F_47 ( V_162 [ V_175 ] ) ;
sprintf ( V_159 , L_29 , F_63 ( V_164 ) , F_64 ( V_164 ) ,
F_65 ( V_164 ) , F_47 ( V_162 [ V_176 ] ) ) ;
F_13 ( V_28 -> V_45 , L_30 , V_159 ) ;
if ( V_156 == 3 )
goto V_174;
F_13 ( V_28 -> V_45 , L_31 ,
F_47 ( V_162 [ V_177 ] ) ,
V_167 [ F_47 ( V_162 [ V_178 ] ) ] ) ;
V_174:
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_66 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
T_2 type , V_179 , V_180 ;
struct V_41 * V_162 [ V_163 + 1 ] ;
int V_30 ;
if ( ! V_42 [ V_181 ] )
return - V_50 ;
V_30 = F_35 ( V_162 , V_163 , V_42 [ V_181 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
type = F_47 ( V_162 [ V_171 ] ) ;
V_179 = F_47 ( V_162 [ V_173 ] ) ;
V_180 = F_47 ( V_162 [ V_172 ] ) ;
if ( V_179 == V_180 )
F_13 ( V_28 -> V_45 , L_32 , type , V_179 ) ;
else
F_13 ( V_28 -> V_45 , L_33 , type , V_179 , V_180 ) ;
return 0 ;
}
static int F_67 ( struct V_27 * V_28 , T_2 V_182 )
{
int V_30 ;
void * V_183 ;
struct V_41 * V_184 ;
struct V_1 * args ;
struct V_25 V_185 ;
args = F_22 ( V_36 , V_21 ) ;
if ( ! args )
return - V_37 ;
V_183 = F_68 ( args , 0 , 0 , & V_62 , V_186 ,
V_187 ) ;
V_184 = F_39 ( args , V_188 ) ;
if ( ! V_184 ) {
F_26 ( args ) ;
return - V_10 ;
}
if ( F_41 ( args , V_189 , V_182 ) ) {
F_26 ( args ) ;
return - V_10 ;
}
F_43 ( args , V_184 ) ;
F_69 ( args , V_183 ) ;
V_185 . V_40 = V_190 ;
V_185 . V_44 = F_66 ;
V_30 = F_21 ( & V_185 , V_28 , args ) ;
F_26 ( args ) ;
return V_30 ;
}
static int F_70 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
int V_30 ;
T_2 V_191 ;
struct V_41 * V_182 [ V_192 + 1 ] ;
if ( ! V_42 [ V_188 ] )
return - V_50 ;
V_30 = F_35 ( V_182 , V_192 , V_42 [ V_188 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
V_191 = F_47 ( V_182 [ V_189 ] ) ;
F_13 ( V_28 -> V_45 , L_34 , V_191 ) ;
if ( V_182 [ V_193 ] ) {
T_2 V_164 ;
struct V_41 * V_194 [ V_195 + 1 ] ;
F_35 ( V_194 , V_195 ,
V_182 [ V_193 ] , NULL , NULL ) ;
V_164 = F_47 ( V_194 [ V_196 ] ) ;
F_13 ( V_28 -> V_45 , L_35 ,
F_63 ( V_164 ) ,
F_64 ( V_164 ) ,
F_65 ( V_164 ) ,
F_47 ( V_194 [ V_197 ] ) ) ;
if ( V_194 [ V_198 ] )
F_13 ( V_28 -> V_45 , L_36 ,
F_47 ( V_194 [ V_199 ] ) ,
F_47 ( V_194 [ V_200 ] ) ) ;
else
F_13 ( V_28 -> V_45 , L_22 ) ;
} else if ( V_182 [ V_201 ] ) {
F_13 ( V_28 -> V_45 , L_37 ) ;
V_30 = F_67 ( V_28 , V_191 ) ;
if ( V_30 )
return V_30 ;
}
F_13 ( V_28 -> V_45 , L_22 ) ;
return 0 ;
}
static int F_71 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_41 * V_146 [ V_202 + 1 ] ;
int V_30 ;
if ( ! V_42 [ V_147 ] )
return - V_50 ;
V_30 = F_35 ( V_146 , V_202 ,
V_42 [ V_147 ] , NULL , NULL ) ;
if ( V_30 )
return V_30 ;
return F_3 ( V_28 -> V_45 , V_203 ,
F_36 ( V_146 [ V_148 ] ) ,
F_37 ( V_146 [ V_148 ] ) ) ;
}
static int F_72 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
struct V_204 V_205 ;
struct V_41 * V_164 [ V_206 + 1 ] ;
int V_30 ;
if ( ! V_42 [ V_207 ] )
return - V_50 ;
V_30 = F_35 ( V_164 , V_206 , V_42 [ V_207 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
V_205 . V_208 = F_51 ( F_47 ( V_164 [ V_209 ] ) ) ;
V_205 . V_137 = F_51 ( F_50 ( V_164 [ V_210 ] ) ) ;
return F_3 ( V_28 -> V_45 , V_211 , & V_205 ,
sizeof( V_205 ) ) ;
}
static int F_73 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_2 V_212 ;
struct V_41 * V_153 ;
V_212 = F_42 ( * ( V_213 * ) F_9 ( V_28 -> V_49 ) ) ;
V_153 = F_39 ( V_2 , V_214 ) ;
if ( ! V_153 )
return - V_10 ;
if ( V_28 -> V_26 == V_215 ) {
if ( F_41 ( V_2 , V_216 , V_212 ) )
return - V_10 ;
} else if ( V_28 -> V_26 == V_217 ) {
if ( F_41 ( V_2 , V_218 , V_212 ) )
return - V_10 ;
}
F_43 ( V_2 , V_153 ) ;
return 0 ;
}
static int F_74 ( struct V_27 * V_28 ,
struct V_41 * * V_42 )
{
V_213 V_219 ;
struct V_41 * V_153 [ V_220 + 1 ] ;
int V_30 ;
if ( ! V_42 [ V_214 ] )
return - V_50 ;
V_30 = F_35 ( V_153 , V_220 , V_42 [ V_214 ] ,
NULL , NULL ) ;
if ( V_30 )
return V_30 ;
V_219 = F_51 ( F_47 ( V_153 [ V_218 ] ) ) ;
return F_3 ( V_28 -> V_45 , V_221 , & V_219 , sizeof( V_219 ) ) ;
}
static int F_75 ( struct V_27 * V_28 )
{
V_28 -> V_45 = F_16 ( V_222 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
F_10 ( V_28 -> V_45 , V_223 ) ;
F_13 ( V_28 -> V_45 , L_38 V_224 L_22 ) ;
return 0 ;
}
static int F_76 ( struct V_27 * V_28 )
{
struct V_25 V_185 ;
struct V_54 V_65 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
switch ( V_28 -> V_26 ) {
case V_225 :
V_28 -> V_45 = F_16 ( 0 ) ;
if ( ! V_28 -> V_45 )
return - V_37 ;
return 0 ;
case V_226 :
V_28 -> V_51 = V_227 * F_5 ( V_228 ) ;
V_185 . V_40 = V_229 ;
V_185 . V_44 = F_34 ;
return F_27 ( & V_185 , V_28 ) ;
case V_230 :
V_28 -> V_48 = V_231 ;
V_65 . V_65 = V_232 ;
V_65 . V_60 = F_38 ;
return F_33 ( & V_65 , V_28 ) ;
case V_233 :
V_28 -> V_48 = V_69 ;
V_65 . V_65 = V_234 ;
V_65 . V_60 = F_44 ;
return F_33 ( & V_65 , V_28 ) ;
case V_235 :
V_28 -> V_48 = V_236 ;
V_28 -> V_51 = V_222 ;
V_28 -> V_52 = V_223 ;
V_185 . V_40 = V_237 ;
V_185 . V_44 = F_48 ;
return F_27 ( & V_185 , V_28 ) ;
case V_238 :
V_28 -> V_48 = V_239 ;
V_28 -> V_51 = V_222 ;
V_185 . V_40 = V_237 ;
V_185 . V_44 = F_49 ;
return F_27 ( & V_185 , V_28 ) ;
case V_144 :
case V_142 :
case V_145 :
V_28 -> V_48 = V_240 ;
V_65 . V_65 = V_241 ;
V_65 . V_60 = F_57 ;
return F_33 ( & V_65 , V_28 ) ;
case V_242 :
V_28 -> V_48 = V_236 ;
V_65 . V_65 = V_243 ;
V_65 . V_60 = F_60 ;
return F_33 ( & V_65 , V_28 ) ;
case V_244 :
V_28 -> V_48 = V_245 ;
V_28 -> V_51 = V_222 ;
V_28 -> V_52 = V_223 ;
V_185 . V_53 = F_61 ;
V_185 . V_40 = V_246 ;
V_185 . V_44 = F_62 ;
return F_27 ( & V_185 , V_28 ) ;
case V_247 :
V_28 -> V_51 = V_222 ;
V_28 -> V_52 = V_223 ;
V_185 . V_40 = V_248 ;
V_185 . V_44 = F_70 ;
return F_27 ( & V_185 , V_28 ) ;
case V_249 :
V_28 -> V_51 = V_250 * F_5 ( V_251 ) ;
V_185 . V_40 = V_252 ;
V_185 . V_44 = F_71 ;
return F_27 ( & V_185 , V_28 ) ;
case V_253 :
V_28 -> V_51 = V_222 ;
V_185 . V_40 = V_254 ;
V_185 . V_44 = F_72 ;
return F_27 ( & V_185 , V_28 ) ;
case V_215 :
V_28 -> V_48 = V_239 ;
V_65 . V_65 = V_255 ;
V_65 . V_60 = F_73 ;
return F_33 ( & V_65 , V_28 ) ;
case V_217 :
V_28 -> V_48 = V_221 ;
V_65 . V_65 = V_255 ;
V_65 . V_60 = F_73 ;
return F_33 ( & V_65 , V_28 ) ;
case V_256 :
V_28 -> V_51 = sizeof( T_2 ) ;
V_185 . V_40 = V_257 ;
V_185 . V_44 = F_74 ;
return F_27 ( & V_185 , V_28 ) ;
case V_258 :
return F_75 ( V_28 ) ;
}
return - V_259 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
int V_30 ;
int V_6 ;
struct V_27 V_28 ;
struct V_31 * V_260 ;
struct V_31 * V_261 ;
struct V_262 * V_263 = V_59 -> V_264 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_260 = (struct V_31 * ) V_2 -> V_7 ;
V_28 . V_49 = F_78 ( V_260 ) + V_19 + V_20 ;
V_28 . V_26 = V_263 -> V_26 ;
V_28 . V_153 = F_79 ( V_59 ) ;
V_28 . V_39 = V_2 -> V_38 ;
if ( ( V_28 . V_26 & 0xC000 ) && ( ! F_80 ( V_2 , V_265 ) ) ) {
V_28 . V_45 = F_20 ( V_266 ) ;
V_30 = - V_267 ;
goto V_268;
}
V_6 = F_81 ( V_260 , V_19 + V_20 ) ;
if ( V_6 && ! F_82 ( V_28 . V_49 , V_6 ) ) {
V_28 . V_45 = F_20 ( V_269 ) ;
V_30 = - V_259 ;
goto V_268;
}
V_30 = F_76 ( & V_28 ) ;
if ( ( V_30 == - V_259 ) || ( V_30 == - V_270 ) )
V_28 . V_45 = F_20 ( V_269 ) ;
else if ( V_30 == - V_50 )
V_28 . V_45 = F_20 ( V_271 ) ;
V_268:
if ( ! V_28 . V_45 )
return V_30 ;
V_6 = F_17 ( V_19 + V_20 ) ;
F_83 ( V_28 . V_45 , V_6 ) ;
V_261 = F_84 ( V_28 . V_45 ) ;
memcpy ( V_261 , V_59 -> V_272 , V_6 ) ;
V_261 -> V_273 = V_28 . V_45 -> V_6 ;
F_85 ( V_28 . V_153 , V_28 . V_45 , F_86 ( V_2 ) . V_274 ) ;
return V_30 ;
}
int T_4 F_87 ( void )
{
int V_275 ;
V_275 = F_88 ( & V_276 ) ;
if ( V_275 ) {
F_89 ( L_39 ) ;
return V_275 ;
}
return 0 ;
}
void F_90 ( void )
{
F_91 ( & V_276 ) ;
}
