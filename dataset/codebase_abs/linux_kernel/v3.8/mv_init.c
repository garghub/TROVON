static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
struct V_6 * V_7 = & V_5 -> V_7 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_8 = NULL ;
F_2 ( & V_5 -> V_9 ) ;
V_7 -> V_10 = ( V_3 < V_2 -> V_11 -> V_12 ) ? 1 : 0 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_15 = V_16 ;
V_7 -> V_17 = 0 ;
V_7 -> type = V_18 ;
V_7 -> V_19 = V_20 ;
V_7 -> V_21 = V_22 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_25 = V_3 ;
V_7 -> V_26 = & V_2 -> V_26 [ 0 ] ;
V_7 -> V_27 = & V_5 -> V_27 [ 0 ] ;
V_7 -> V_28 = (struct V_29 * ) V_2 -> V_30 -> V_31 ;
V_7 -> V_32 = V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_35 ;
if ( ! V_2 )
return;
if ( V_2 -> V_36 & V_37 )
V_35 = V_38 ;
else
V_35 = V_39 ;
if ( V_2 -> V_40 )
F_4 ( V_2 -> V_40 ) ;
if ( V_2 -> V_41 )
F_5 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_41 ) * V_39 ,
V_2 -> V_41 , V_2 -> V_43 ) ;
if ( V_2 -> V_44 )
F_5 ( V_2 -> V_42 , V_45 ,
V_2 -> V_44 , V_2 -> V_46 ) ;
if ( V_2 -> V_47 )
F_5 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ,
V_2 -> V_47 , V_2 -> V_49 ) ;
if ( V_2 -> V_50 )
F_5 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_50 ) * V_35 ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_2 -> V_52 )
F_5 ( V_2 -> V_42 , V_53 ,
V_2 -> V_52 , V_2 -> V_54 ) ;
if ( V_2 -> V_55 )
F_5 ( V_2 -> V_42 , V_53 ,
V_2 -> V_55 , V_2 -> V_56 ) ;
V_57 -> V_58 ( V_2 ) ;
if ( V_2 -> V_30 )
F_6 ( V_2 -> V_30 ) ;
F_7 (mwq, &mvi->wq_list, entry)
F_8 ( & V_34 -> V_59 ) ;
F_9 ( V_2 -> V_60 ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( unsigned long V_61 )
{
T_1 V_62 ;
T_2 V_63 , V_64 = 0 ;
struct V_1 * V_2 ;
struct V_29 * V_65 = (struct V_29 * ) V_61 ;
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
if ( F_11 ( ! V_2 ) )
F_12 ( 1 ) ;
V_62 = V_57 -> V_69 ( V_2 , V_2 -> V_70 -> V_71 ) ;
if ( ! V_62 )
goto V_72;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
V_57 -> V_73 ( V_2 , V_2 -> V_70 -> V_71 , V_62 ) ;
}
V_72:
V_57 -> V_74 ( V_2 ) ;
}
static T_3 F_13 ( int V_71 , void * V_61 )
{
T_1 V_63 ;
T_1 V_62 ;
struct V_1 * V_2 ;
struct V_29 * V_65 = V_61 ;
#ifndef F_14
T_1 V_64 ;
#endif
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
if ( F_11 ( ! V_2 ) )
return V_75 ;
#ifdef F_14
V_57 -> V_76 ( V_2 ) ;
#endif
V_62 = V_57 -> V_69 ( V_2 , V_71 ) ;
if ( ! V_62 ) {
#ifdef F_14
V_57 -> V_74 ( V_2 ) ;
#endif
return V_75 ;
}
#ifdef F_14
F_15 ( & ( (struct V_66 * ) V_65 -> V_67 ) -> V_77 ) ;
#else
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
V_57 -> V_73 ( V_2 , V_71 , V_62 ) ;
}
#endif
return V_78 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_79 * V_30 )
{
int V_64 = 0 , V_35 ;
char V_80 [ 32 ] ;
if ( V_2 -> V_36 & V_37 )
V_35 = V_38 ;
else
V_35 = V_39 ;
F_17 ( & V_2 -> V_81 ) ;
for ( V_64 = 0 ; V_64 < V_2 -> V_11 -> V_12 ; V_64 ++ ) {
F_1 ( V_2 , V_64 ) ;
V_2 -> V_8 [ V_64 ] . V_82 = 0 ;
V_2 -> V_8 [ V_64 ] . V_83 = 0 ;
F_18 ( & V_2 -> V_8 [ V_64 ] . V_84 ) ;
}
for ( V_64 = 0 ; V_64 < V_85 ; V_64 ++ ) {
V_2 -> V_86 [ V_64 ] . V_87 = V_88 ;
V_2 -> V_86 [ V_64 ] . V_89 = V_90 ;
V_2 -> V_86 [ V_64 ] . V_91 = V_64 ;
V_2 -> V_86 [ V_64 ] . V_92 = V_93 ;
F_2 ( & V_2 -> V_86 [ V_64 ] . V_9 ) ;
}
V_2 -> V_41 = F_19 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_41 ) * V_39 ,
& V_2 -> V_43 , V_94 ) ;
if ( ! V_2 -> V_41 )
goto V_95;
memset ( V_2 -> V_41 , 0 , sizeof( * V_2 -> V_41 ) * V_39 ) ;
V_2 -> V_44 = F_19 ( V_2 -> V_42 , V_45 ,
& V_2 -> V_46 , V_94 ) ;
if ( ! V_2 -> V_44 )
goto V_95;
memset ( V_2 -> V_44 , 0 , V_45 ) ;
V_2 -> V_47 = F_19 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ,
& V_2 -> V_49 , V_94 ) ;
if ( ! V_2 -> V_47 )
goto V_95;
memset ( V_2 -> V_47 , 0 , sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ) ;
V_2 -> V_47 [ 0 ] = F_20 ( 0xfff ) ;
V_2 -> V_96 = 0xfff ;
V_2 -> V_50 = F_19 ( V_2 -> V_42 ,
sizeof( * V_2 -> V_50 ) * V_35 ,
& V_2 -> V_51 , V_94 ) ;
if ( ! V_2 -> V_50 )
goto V_95;
memset ( V_2 -> V_50 , 0 , sizeof( * V_2 -> V_50 ) * V_35 ) ;
V_2 -> V_52 = F_19 ( V_2 -> V_42 ,
V_53 ,
& V_2 -> V_54 , V_94 ) ;
if ( ! V_2 -> V_52 )
goto V_95;
V_2 -> V_55 = F_19 ( V_2 -> V_42 ,
V_53 ,
& V_2 -> V_56 , V_94 ) ;
if ( ! V_2 -> V_55 )
goto V_95;
sprintf ( V_80 , L_1 , L_2 , V_2 -> V_25 ) ;
V_2 -> V_40 = F_21 ( V_80 , V_2 -> V_70 , V_97 , 16 , 0 ) ;
if ( ! V_2 -> V_40 ) {
F_22 ( V_98 L_3 , V_80 ) ;
goto V_95;
}
V_2 -> V_99 = V_35 ;
F_23 ( V_2 ) ;
return 0 ;
V_95:
return 1 ;
}
int F_24 ( struct V_1 * V_2 , int V_100 , int V_101 )
{
unsigned long V_102 , V_103 , V_104 , V_105 = 0 ;
struct V_106 * V_70 = V_2 -> V_70 ;
if ( V_101 != - 1 ) {
V_102 = F_25 ( V_70 , V_101 ) ;
V_103 = F_26 ( V_70 , V_101 ) ;
if ( ! V_102 || ! V_103 )
goto V_95;
V_105 = F_27 ( V_70 , V_101 ) ;
if ( V_105 & V_107 ) {
if ( V_105 & V_108 )
V_2 -> V_109 = F_28 ( V_102 , V_103 ) ;
else
V_2 -> V_109 = F_29 ( V_102 ,
V_103 ) ;
} else
V_2 -> V_109 = ( void * ) V_102 ;
if ( ! V_2 -> V_109 )
goto V_95;
}
V_102 = F_25 ( V_70 , V_100 ) ;
V_103 = F_26 ( V_70 , V_100 ) ;
if ( ! V_102 || ! V_103 )
goto V_95;
V_104 = F_27 ( V_70 , V_100 ) ;
if ( V_104 & V_108 )
V_2 -> V_110 = F_28 ( V_102 , V_103 ) ;
else
V_2 -> V_110 = F_29 ( V_102 , V_103 ) ;
if ( ! V_2 -> V_110 ) {
if ( V_2 -> V_109 && ( V_105 & V_107 ) )
F_30 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
goto V_95;
}
return 0 ;
V_95:
return - 1 ;
}
void F_31 ( void T_4 * V_110 )
{
F_30 ( V_110 ) ;
}
static struct V_1 * F_32 ( struct V_106 * V_70 ,
const struct V_111 * V_112 ,
struct V_79 * V_30 , unsigned int V_25 )
{
struct V_1 * V_2 = NULL ;
struct V_29 * V_65 = F_33 ( V_30 ) ;
V_2 = F_34 ( sizeof( * V_2 ) +
( 1L << V_113 [ V_112 -> V_114 ] . V_115 ) *
sizeof( struct V_116 ) , V_94 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_70 = V_70 ;
V_2 -> V_42 = & V_70 -> V_42 ;
V_2 -> V_117 = V_112 -> V_114 ;
V_2 -> V_11 = & V_113 [ V_2 -> V_117 ] ;
F_18 ( & V_2 -> V_118 ) ;
( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_25 ] = V_2 ;
( (struct V_66 * ) V_65 -> V_67 ) -> V_12 = V_2 -> V_11 -> V_12 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_119 = V_65 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_60 = F_34 ( V_39 >> 3 , V_94 ) ;
if ( ! V_2 -> V_60 )
goto V_95;
if ( V_57 -> V_120 ( V_2 ) )
goto V_95;
if ( ! F_16 ( V_2 , V_30 ) )
return V_2 ;
V_95:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_35 ( struct V_106 * V_70 )
{
int V_121 ;
if ( ! F_36 ( V_70 , F_37 ( 64 ) ) ) {
V_121 = F_38 ( V_70 , F_37 ( 64 ) ) ;
if ( V_121 ) {
V_121 = F_38 ( V_70 , F_37 ( 32 ) ) ;
if ( V_121 ) {
F_39 ( V_122 , & V_70 -> V_42 ,
L_4 ) ;
return V_121 ;
}
}
} else {
V_121 = F_36 ( V_70 , F_37 ( 32 ) ) ;
if ( V_121 ) {
F_39 ( V_122 , & V_70 -> V_42 ,
L_5 ) ;
return V_121 ;
}
V_121 = F_38 ( V_70 , F_37 ( 32 ) ) ;
if ( V_121 ) {
F_39 ( V_122 , & V_70 -> V_42 ,
L_6 ) ;
return V_121 ;
}
}
return V_121 ;
}
static int F_40 ( struct V_79 * V_30 ,
const struct V_123 * V_124 )
{
int V_125 , V_126 ; unsigned short V_63 ;
struct V_6 * * V_127 ;
struct V_128 * * V_129 ;
struct V_29 * V_65 = F_33 ( V_30 ) ;
V_63 = V_124 -> V_68 ;
V_125 = V_63 * V_124 -> V_12 ;
V_126 = V_125 ;
memset ( V_65 , 0x00 , sizeof( struct V_29 ) ) ;
V_127 = F_41 ( V_125 , sizeof( void * ) , V_94 ) ;
V_129 = F_41 ( V_126 , sizeof( void * ) , V_94 ) ;
if ( ! V_127 || ! V_129 )
goto V_130;
V_65 -> V_7 = V_127 ;
V_65 -> V_131 = V_129 ;
V_65 -> V_132 . V_30 = V_30 ;
V_65 -> V_67 = F_34 ( sizeof( struct V_66 ) , V_94 ) ;
if ( ! V_65 -> V_67 )
goto V_130;
( (struct V_66 * ) V_65 -> V_67 ) -> V_68 = V_63 ;
V_30 -> V_133 = V_134 ;
V_30 -> V_135 = V_85 ;
V_30 -> V_136 = ~ 0 ;
V_30 -> V_137 = 1 ;
V_30 -> V_138 = 16 ;
return 0 ;
V_130:
F_9 ( V_127 ) ;
F_9 ( V_129 ) ;
return - 1 ;
}
static void F_42 ( struct V_79 * V_30 ,
const struct V_123 * V_124 )
{
int V_139 , V_64 = 0 , V_140 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_29 * V_65 = F_33 ( V_30 ) ;
unsigned short V_141 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_140 ] ;
for ( V_64 = 0 ; V_64 < V_124 -> V_12 ; V_64 ++ ) {
V_65 -> V_7 [ V_140 * V_124 -> V_12 + V_64 ] =
& V_2 -> V_5 [ V_64 ] . V_7 ;
V_65 -> V_131 [ V_140 * V_124 -> V_12 + V_64 ] =
& V_2 -> V_8 [ V_64 ] . V_131 ;
}
}
V_65 -> V_142 = V_143 ;
V_65 -> V_42 = V_2 -> V_42 ;
V_65 -> V_144 = V_145 ;
V_65 -> V_26 = & V_2 -> V_26 [ 0 ] ;
V_65 -> V_146 = V_141 * V_124 -> V_12 ;
V_65 -> V_147 = V_147 ;
if ( V_2 -> V_36 & V_37 )
V_139 = V_148 ;
else
V_139 = V_39 ;
V_65 -> V_149 = V_139 ;
V_30 -> V_150 = F_43 ( T_2 , V_151 , V_152 ) ;
V_30 -> V_139 = V_139 ;
V_2 -> V_30 -> V_153 = V_154 ;
V_65 -> V_132 . V_30 = V_2 -> V_30 ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_5 V_64 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_11 -> V_12 ; V_64 ++ ) {
V_2 -> V_5 [ V_64 ] . V_155 = 0x5005043011ab0000ULL ;
V_2 -> V_5 [ V_64 ] . V_155 =
F_45 ( ( V_156 ) ( * ( V_156 * ) & V_2 -> V_5 [ V_64 ] . V_155 ) ) ;
}
memcpy ( V_2 -> V_26 , & V_2 -> V_5 [ 0 ] . V_155 , V_157 ) ;
}
static int F_46 ( struct V_106 * V_70 , const struct V_111 * V_112 )
{
unsigned int V_121 , V_158 = 0 ;
struct V_1 * V_2 ;
struct V_66 * V_159 ;
T_6 V_160 = F_13 ;
struct V_79 * V_30 = NULL ;
const struct V_123 * V_11 ;
F_39 ( V_161 , & V_70 -> V_42 ,
L_7 , V_162 ) ;
V_121 = F_47 ( V_70 ) ;
if ( V_121 )
goto V_163;
F_48 ( V_70 ) ;
V_121 = F_49 ( V_70 , V_143 ) ;
if ( V_121 )
goto V_164;
V_121 = F_35 ( V_70 ) ;
if ( V_121 )
goto V_165;
V_30 = F_50 ( & V_166 , sizeof( void * ) ) ;
if ( ! V_30 ) {
V_121 = - V_167 ;
goto V_165;
}
V_11 = & V_113 [ V_112 -> V_114 ] ;
F_33 ( V_30 ) =
F_41 ( 1 , sizeof( struct V_29 ) , V_94 ) ;
if ( ! F_33 ( V_30 ) ) {
F_9 ( V_30 ) ;
V_121 = - V_167 ;
goto V_165;
}
V_121 = F_40 ( V_30 , V_11 ) ;
if ( V_121 ) {
F_9 ( V_30 ) ;
V_121 = - V_167 ;
goto V_165;
}
F_51 ( V_70 , F_33 ( V_30 ) ) ;
do {
V_2 = F_32 ( V_70 , V_112 , V_30 , V_158 ) ;
if ( ! V_2 ) {
V_121 = - V_167 ;
goto V_165;
}
memset ( & V_2 -> V_168 , 0xFF ,
sizeof( struct V_169 ) ) ;
F_44 ( V_2 ) ;
V_2 -> V_170 = V_158 ;
V_121 = V_57 -> V_171 ( V_2 ) ;
if ( V_121 ) {
F_3 ( V_2 ) ;
goto V_165;
}
V_158 ++ ;
} while ( V_158 < V_11 -> V_68 );
V_159 = (struct V_66 * ) ( F_33 ( V_30 ) -> V_67 ) ;
#ifdef F_14
F_52 ( & ( V_159 -> V_77 ) , F_10 ,
( unsigned long ) F_33 ( V_30 ) ) ;
#endif
F_42 ( V_30 , V_11 ) ;
V_121 = F_53 ( V_30 , & V_70 -> V_42 ) ;
if ( V_121 )
goto V_172;
V_121 = F_54 ( F_33 ( V_30 ) ) ;
if ( V_121 )
goto V_172;
V_121 = F_55 ( V_70 -> V_71 , V_160 , V_173 ,
V_143 , F_33 ( V_30 ) ) ;
if ( V_121 )
goto V_174;
V_57 -> V_74 ( V_2 ) ;
F_56 ( V_2 -> V_30 ) ;
return 0 ;
V_174:
F_57 ( F_33 ( V_30 ) ) ;
V_172:
F_58 ( V_2 -> V_30 ) ;
V_165:
F_59 ( V_70 ) ;
V_164:
F_60 ( V_70 ) ;
V_163:
return V_121 ;
}
static void F_61 ( struct V_106 * V_70 )
{
unsigned short V_63 , V_64 = 0 ;
struct V_29 * V_65 = F_62 ( V_70 ) ;
struct V_1 * V_2 = NULL ;
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
#ifdef F_14
F_63 ( & ( (struct V_66 * ) V_65 -> V_67 ) -> V_77 ) ;
#endif
F_51 ( V_70 , NULL ) ;
F_57 ( V_65 ) ;
F_64 ( V_2 -> V_30 ) ;
F_58 ( V_2 -> V_30 ) ;
V_57 -> V_76 ( V_2 ) ;
F_65 ( V_2 -> V_70 -> V_71 , V_65 ) ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
F_3 ( V_2 ) ;
}
F_9 ( V_65 -> V_7 ) ;
F_9 ( V_65 -> V_131 ) ;
F_9 ( V_65 ) ;
F_59 ( V_70 ) ;
F_60 ( V_70 ) ;
return;
}
static T_7
F_66 ( struct V_175 * V_176 ,
struct V_177 * V_178 , char * V_179 )
{
return snprintf ( V_179 , V_180 , L_8 , V_162 ) ;
}
static T_7
F_67 ( struct V_175 * V_176 ,
struct V_177 * V_178 ,
const char * V_179 , T_8 V_181 )
{
int V_182 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_79 * V_30 = F_68 ( V_176 ) ;
struct V_29 * V_65 = F_33 ( V_30 ) ;
T_5 V_64 , V_63 ;
if ( V_179 == NULL )
return V_181 ;
if ( sscanf ( V_179 , L_9 , & V_182 ) != 1 )
return - V_183 ;
if ( V_182 >= 0x10000 ) {
F_69 ( L_10
L_11 , V_182 ) ;
return strlen ( V_179 ) ;
}
V_184 = V_182 ;
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
if ( F_11 ( ! V_2 ) )
return - V_183 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
if ( V_57 -> V_185 )
V_57 -> V_185 ( V_2 ,
V_184 ) ;
}
F_69 ( L_12 ,
V_184 ) ;
return strlen ( V_179 ) ;
}
static T_7 F_70 ( struct V_175 * V_176 ,
struct V_177 * V_178 , char * V_179 )
{
return snprintf ( V_179 , V_180 , L_13 , V_184 ) ;
}
static int T_9 F_71 ( void )
{
int V_121 ;
V_134 = F_72 ( & V_186 ) ;
if ( ! V_134 )
return - V_167 ;
V_187 = F_73 ( L_14 , sizeof( struct V_188 ) ,
0 , V_189 , NULL ) ;
if ( ! V_187 ) {
V_121 = - V_167 ;
F_74 ( L_15 , V_190 ) ;
goto V_95;
}
V_121 = F_75 ( & V_191 ) ;
if ( V_121 )
goto V_95;
return 0 ;
V_95:
F_76 ( V_134 ) ;
return V_121 ;
}
static void T_10 F_77 ( void )
{
F_78 ( & V_191 ) ;
F_76 ( V_134 ) ;
F_79 ( V_187 ) ;
}
