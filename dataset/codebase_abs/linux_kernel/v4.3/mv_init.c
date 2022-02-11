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
if ( V_105 & V_107 )
V_2 -> V_108 = F_28 ( V_102 , V_103 ) ;
else
V_2 -> V_108 = ( void * ) V_102 ;
if ( ! V_2 -> V_108 )
goto V_95;
}
V_102 = F_25 ( V_70 , V_100 ) ;
V_103 = F_26 ( V_70 , V_100 ) ;
if ( ! V_102 || ! V_103 ) {
F_29 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
goto V_95;
}
V_104 = F_27 ( V_70 , V_100 ) ;
V_2 -> V_109 = F_28 ( V_102 , V_103 ) ;
if ( ! V_2 -> V_109 ) {
if ( V_2 -> V_108 && ( V_105 & V_107 ) )
F_29 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
goto V_95;
}
return 0 ;
V_95:
return - 1 ;
}
void F_30 ( void T_4 * V_109 )
{
F_29 ( V_109 ) ;
}
static struct V_1 * F_31 ( struct V_106 * V_70 ,
const struct V_110 * V_111 ,
struct V_79 * V_30 , unsigned int V_25 )
{
struct V_1 * V_2 = NULL ;
struct V_29 * V_65 = F_32 ( V_30 ) ;
V_2 = F_33 ( sizeof( * V_2 ) +
( 1L << V_112 [ V_111 -> V_113 ] . V_114 ) *
sizeof( struct V_115 ) , V_94 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_70 = V_70 ;
V_2 -> V_42 = & V_70 -> V_42 ;
V_2 -> V_116 = V_111 -> V_113 ;
V_2 -> V_11 = & V_112 [ V_2 -> V_116 ] ;
F_18 ( & V_2 -> V_117 ) ;
( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_25 ] = V_2 ;
( (struct V_66 * ) V_65 -> V_67 ) -> V_12 = V_2 -> V_11 -> V_12 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_118 = V_65 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_60 = F_33 ( V_39 >> 3 , V_94 ) ;
if ( ! V_2 -> V_60 )
goto V_95;
if ( V_57 -> V_119 ( V_2 ) )
goto V_95;
if ( ! F_16 ( V_2 , V_30 ) )
return V_2 ;
V_95:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_34 ( struct V_106 * V_70 )
{
int V_120 ;
if ( ! F_35 ( V_70 , F_36 ( 64 ) ) ) {
V_120 = F_37 ( V_70 , F_36 ( 64 ) ) ;
if ( V_120 ) {
V_120 = F_37 ( V_70 , F_36 ( 32 ) ) ;
if ( V_120 ) {
F_38 ( V_121 , & V_70 -> V_42 ,
L_4 ) ;
return V_120 ;
}
}
} else {
V_120 = F_35 ( V_70 , F_36 ( 32 ) ) ;
if ( V_120 ) {
F_38 ( V_121 , & V_70 -> V_42 ,
L_5 ) ;
return V_120 ;
}
V_120 = F_37 ( V_70 , F_36 ( 32 ) ) ;
if ( V_120 ) {
F_38 ( V_121 , & V_70 -> V_42 ,
L_6 ) ;
return V_120 ;
}
}
return V_120 ;
}
static int F_39 ( struct V_79 * V_30 ,
const struct V_122 * V_123 )
{
int V_124 , V_125 ; unsigned short V_63 ;
struct V_6 * * V_126 ;
struct V_127 * * V_128 ;
struct V_29 * V_65 = F_32 ( V_30 ) ;
V_63 = V_123 -> V_68 ;
V_124 = V_63 * V_123 -> V_12 ;
V_125 = V_124 ;
memset ( V_65 , 0x00 , sizeof( struct V_29 ) ) ;
V_126 = F_40 ( V_124 , sizeof( void * ) , V_94 ) ;
V_128 = F_40 ( V_125 , sizeof( void * ) , V_94 ) ;
if ( ! V_126 || ! V_128 )
goto V_129;
V_65 -> V_7 = V_126 ;
V_65 -> V_130 = V_128 ;
V_65 -> V_131 . V_30 = V_30 ;
V_65 -> V_67 = F_33 ( sizeof( struct V_66 ) , V_94 ) ;
if ( ! V_65 -> V_67 )
goto V_129;
( (struct V_66 * ) V_65 -> V_67 ) -> V_68 = V_63 ;
V_30 -> V_132 = V_133 ;
V_30 -> V_134 = V_85 ;
V_30 -> V_135 = ~ 0 ;
V_30 -> V_136 = 1 ;
V_30 -> V_137 = 16 ;
return 0 ;
V_129:
F_9 ( V_126 ) ;
F_9 ( V_128 ) ;
return - 1 ;
}
static void F_41 ( struct V_79 * V_30 ,
const struct V_122 * V_123 )
{
int V_138 , V_64 = 0 , V_139 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_29 * V_65 = F_32 ( V_30 ) ;
unsigned short V_140 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_139 ] ;
for ( V_64 = 0 ; V_64 < V_123 -> V_12 ; V_64 ++ ) {
V_65 -> V_7 [ V_139 * V_123 -> V_12 + V_64 ] =
& V_2 -> V_5 [ V_64 ] . V_7 ;
V_65 -> V_130 [ V_139 * V_123 -> V_12 + V_64 ] =
& V_2 -> V_8 [ V_64 ] . V_130 ;
}
}
V_65 -> V_141 = V_142 ;
V_65 -> V_42 = V_2 -> V_42 ;
V_65 -> V_143 = V_144 ;
V_65 -> V_26 = & V_2 -> V_26 [ 0 ] ;
V_65 -> V_145 = V_140 * V_123 -> V_12 ;
if ( V_2 -> V_36 & V_37 )
V_138 = V_146 ;
else
V_138 = V_39 ;
V_30 -> V_147 = F_42 ( T_2 , V_148 , V_149 ) ;
V_30 -> V_138 = V_138 ;
V_2 -> V_30 -> V_150 = V_151 ;
V_65 -> V_131 . V_30 = V_2 -> V_30 ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_5 V_64 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_11 -> V_12 ; V_64 ++ ) {
V_2 -> V_5 [ V_64 ] . V_152 = 0x5005043011ab0000ULL ;
V_2 -> V_5 [ V_64 ] . V_152 =
F_44 ( ( V_153 ) ( * ( V_153 * ) & V_2 -> V_5 [ V_64 ] . V_152 ) ) ;
}
memcpy ( V_2 -> V_26 , & V_2 -> V_5 [ 0 ] . V_152 , V_154 ) ;
}
static int F_45 ( struct V_106 * V_70 , const struct V_110 * V_111 )
{
unsigned int V_120 , V_155 = 0 ;
struct V_1 * V_2 ;
struct V_66 * V_156 ;
T_6 V_157 = F_13 ;
struct V_79 * V_30 = NULL ;
const struct V_122 * V_11 ;
F_38 ( V_158 , & V_70 -> V_42 ,
L_7 , V_159 ) ;
V_120 = F_46 ( V_70 ) ;
if ( V_120 )
goto V_160;
F_47 ( V_70 ) ;
V_120 = F_48 ( V_70 , V_142 ) ;
if ( V_120 )
goto V_161;
V_120 = F_34 ( V_70 ) ;
if ( V_120 )
goto V_162;
V_30 = F_49 ( & V_163 , sizeof( void * ) ) ;
if ( ! V_30 ) {
V_120 = - V_164 ;
goto V_162;
}
V_11 = & V_112 [ V_111 -> V_113 ] ;
F_32 ( V_30 ) =
F_40 ( 1 , sizeof( struct V_29 ) , V_94 ) ;
if ( ! F_32 ( V_30 ) ) {
F_9 ( V_30 ) ;
V_120 = - V_164 ;
goto V_162;
}
V_120 = F_39 ( V_30 , V_11 ) ;
if ( V_120 ) {
F_9 ( V_30 ) ;
V_120 = - V_164 ;
goto V_162;
}
F_50 ( V_70 , F_32 ( V_30 ) ) ;
do {
V_2 = F_31 ( V_70 , V_111 , V_30 , V_155 ) ;
if ( ! V_2 ) {
V_120 = - V_164 ;
goto V_162;
}
memset ( & V_2 -> V_165 , 0xFF ,
sizeof( struct V_166 ) ) ;
F_43 ( V_2 ) ;
V_2 -> V_167 = V_155 ;
V_120 = V_57 -> V_168 ( V_2 ) ;
if ( V_120 ) {
F_3 ( V_2 ) ;
goto V_162;
}
V_155 ++ ;
} while ( V_155 < V_11 -> V_68 );
V_156 = (struct V_66 * ) ( F_32 ( V_30 ) -> V_67 ) ;
#ifdef F_14
F_51 ( & ( V_156 -> V_77 ) , F_10 ,
( unsigned long ) F_32 ( V_30 ) ) ;
#endif
F_41 ( V_30 , V_11 ) ;
V_120 = F_52 ( V_30 , & V_70 -> V_42 ) ;
if ( V_120 )
goto V_169;
V_120 = F_53 ( F_32 ( V_30 ) ) ;
if ( V_120 )
goto V_169;
V_120 = F_54 ( V_70 -> V_71 , V_157 , V_170 ,
V_142 , F_32 ( V_30 ) ) ;
if ( V_120 )
goto V_171;
V_57 -> V_74 ( V_2 ) ;
F_55 ( V_2 -> V_30 ) ;
return 0 ;
V_171:
F_56 ( F_32 ( V_30 ) ) ;
V_169:
F_57 ( V_2 -> V_30 ) ;
V_162:
F_58 ( V_70 ) ;
V_161:
F_59 ( V_70 ) ;
V_160:
return V_120 ;
}
static void F_60 ( struct V_106 * V_70 )
{
unsigned short V_63 , V_64 = 0 ;
struct V_29 * V_65 = F_61 ( V_70 ) ;
struct V_1 * V_2 = NULL ;
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
#ifdef F_14
F_62 ( & ( (struct V_66 * ) V_65 -> V_67 ) -> V_77 ) ;
#endif
F_56 ( V_65 ) ;
F_63 ( V_2 -> V_30 ) ;
F_57 ( V_2 -> V_30 ) ;
V_57 -> V_76 ( V_2 ) ;
F_64 ( V_2 -> V_70 -> V_71 , V_65 ) ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
F_3 ( V_2 ) ;
}
F_9 ( V_65 -> V_7 ) ;
F_9 ( V_65 -> V_130 ) ;
F_9 ( V_65 ) ;
F_58 ( V_70 ) ;
F_59 ( V_70 ) ;
return;
}
static T_7
F_65 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return snprintf ( V_176 , V_177 , L_8 , V_159 ) ;
}
static T_7
F_66 ( struct V_172 * V_173 ,
struct V_174 * V_175 ,
const char * V_176 , T_8 V_178 )
{
int V_179 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_79 * V_30 = F_67 ( V_173 ) ;
struct V_29 * V_65 = F_32 ( V_30 ) ;
T_5 V_64 , V_63 ;
if ( V_176 == NULL )
return V_178 ;
if ( sscanf ( V_176 , L_9 , & V_179 ) != 1 )
return - V_180 ;
if ( V_179 >= 0x10000 ) {
F_68 ( L_10
L_11 , V_179 ) ;
return strlen ( V_176 ) ;
}
V_181 = V_179 ;
V_63 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_68 ;
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ 0 ] ;
if ( F_11 ( ! V_2 ) )
return - V_180 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_2 = ( (struct V_66 * ) V_65 -> V_67 ) -> V_2 [ V_64 ] ;
if ( V_57 -> V_182 )
V_57 -> V_182 ( V_2 ,
V_181 ) ;
}
F_68 ( L_12 ,
V_181 ) ;
return strlen ( V_176 ) ;
}
static T_7 F_69 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return snprintf ( V_176 , V_177 , L_13 , V_181 ) ;
}
static int T_9 F_70 ( void )
{
int V_120 ;
V_133 = F_71 ( & V_183 ) ;
if ( ! V_133 )
return - V_164 ;
V_120 = F_72 ( & V_184 ) ;
if ( V_120 )
goto V_95;
return 0 ;
V_95:
F_73 ( V_133 ) ;
return V_120 ;
}
static void T_10 F_74 ( void )
{
F_75 ( & V_184 ) ;
F_73 ( V_133 ) ;
}
