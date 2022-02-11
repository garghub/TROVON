static void T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
struct V_6 * V_7 = & V_5 -> V_7 ;
V_5 -> V_2 = V_2 ;
F_2 ( & V_5 -> V_8 ) ;
V_7 -> V_9 = ( V_3 < V_2 -> V_10 -> V_11 ) ? 1 : 0 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = 0 ;
V_7 -> type = V_17 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_20 = V_21 ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_3 ;
V_7 -> V_25 = & V_2 -> V_25 [ 0 ] ;
V_7 -> V_26 = & V_5 -> V_26 [ 0 ] ;
V_7 -> V_27 = (struct V_28 * ) V_2 -> V_29 -> V_30 ;
V_7 -> V_31 = V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
int V_34 ;
if ( ! V_2 )
return;
if ( V_2 -> V_35 & V_36 )
V_34 = V_37 ;
else
V_34 = V_38 ;
if ( V_2 -> V_39 )
F_4 ( V_2 -> V_39 ) ;
if ( V_2 -> V_40 )
F_5 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_40 ) * V_42 ,
V_2 -> V_40 , V_2 -> V_43 ) ;
if ( V_2 -> V_44 )
F_5 ( V_2 -> V_41 , V_45 ,
V_2 -> V_44 , V_2 -> V_46 ) ;
if ( V_2 -> V_47 )
F_5 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ,
V_2 -> V_47 , V_2 -> V_49 ) ;
if ( V_2 -> V_50 )
F_5 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_50 ) * V_34 ,
V_2 -> V_50 , V_2 -> V_51 ) ;
#ifndef F_6
if ( V_2 -> V_52 )
F_5 ( V_2 -> V_41 , V_53 ,
V_2 -> V_52 , V_2 -> V_54 ) ;
#endif
V_55 -> V_56 ( V_2 ) ;
if ( V_2 -> V_29 )
F_7 ( V_2 -> V_29 ) ;
F_8 (mwq, &mvi->wq_list, entry)
F_9 ( & V_33 -> V_57 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( unsigned long V_58 )
{
unsigned long V_35 ;
T_2 V_59 ;
T_3 V_60 , V_61 = 0 ;
struct V_1 * V_2 ;
struct V_28 * V_62 = (struct V_28 * ) V_58 ;
V_60 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_65 ;
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ 0 ] ;
if ( F_12 ( ! V_2 ) )
F_13 ( 1 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ V_61 ] ;
V_59 = V_55 -> V_66 ( V_2 , V_2 -> V_67 ) ;
if ( V_59 )
V_55 -> V_68 ( V_2 , V_2 -> V_67 , V_59 ) ;
}
}
static T_4 F_14 ( int V_67 , void * V_58 )
{
T_2 V_60 , V_61 = 0 ;
T_2 V_59 ;
struct V_1 * V_2 ;
struct V_28 * V_62 = V_58 ;
V_60 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_65 ;
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ 0 ] ;
if ( F_12 ( ! V_2 ) )
return V_69 ;
V_59 = V_55 -> V_66 ( V_2 , V_67 ) ;
if ( ! V_59 )
return V_69 ;
#ifdef F_15
F_16 ( & V_70 ) ;
#else
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ V_61 ] ;
V_55 -> V_68 ( V_2 , V_67 , V_59 ) ;
}
#endif
return V_71 ;
}
static int T_1 F_17 ( struct V_1 * V_2 , struct V_72 * V_29 )
{
int V_61 = 0 , V_34 ;
char V_73 [ 32 ] ;
if ( V_2 -> V_35 & V_36 )
V_34 = V_37 ;
else
V_34 = V_38 ;
F_18 ( & V_2 -> V_74 ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_10 -> V_11 ; V_61 ++ ) {
F_1 ( V_2 , V_61 ) ;
V_2 -> V_75 [ V_61 ] . V_76 = 0 ;
V_2 -> V_75 [ V_61 ] . V_77 = 0 ;
F_19 ( & V_2 -> V_75 [ V_61 ] . V_78 ) ;
}
for ( V_61 = 0 ; V_61 < V_79 ; V_61 ++ ) {
V_2 -> V_80 [ V_61 ] . V_81 = V_82 ;
V_2 -> V_80 [ V_61 ] . V_83 = V_84 ;
V_2 -> V_80 [ V_61 ] . V_85 = V_61 ;
V_2 -> V_80 [ V_61 ] . V_86 = V_87 ;
F_2 ( & V_2 -> V_80 [ V_61 ] . V_8 ) ;
}
V_2 -> V_40 = F_20 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_40 ) * V_42 ,
& V_2 -> V_43 , V_88 ) ;
if ( ! V_2 -> V_40 )
goto V_89;
memset ( V_2 -> V_40 , 0 , sizeof( * V_2 -> V_40 ) * V_42 ) ;
V_2 -> V_44 = F_20 ( V_2 -> V_41 , V_45 ,
& V_2 -> V_46 , V_88 ) ;
if ( ! V_2 -> V_44 )
goto V_89;
memset ( V_2 -> V_44 , 0 , V_45 ) ;
V_2 -> V_47 = F_20 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ,
& V_2 -> V_49 , V_88 ) ;
if ( ! V_2 -> V_47 )
goto V_89;
memset ( V_2 -> V_47 , 0 , sizeof( * V_2 -> V_47 ) * ( V_48 + 1 ) ) ;
V_2 -> V_47 [ 0 ] = F_21 ( 0xfff ) ;
V_2 -> V_90 = 0xfff ;
V_2 -> V_50 = F_20 ( V_2 -> V_41 ,
sizeof( * V_2 -> V_50 ) * V_34 ,
& V_2 -> V_51 , V_88 ) ;
if ( ! V_2 -> V_50 )
goto V_89;
memset ( V_2 -> V_50 , 0 , sizeof( * V_2 -> V_50 ) * V_34 ) ;
#ifndef F_6
V_2 -> V_52 = F_20 ( V_2 -> V_41 ,
V_53 ,
& V_2 -> V_54 , V_88 ) ;
if ( ! V_2 -> V_52 )
goto V_89;
#endif
sprintf ( V_73 , L_1 , L_2 , V_2 -> V_24 ) ;
V_2 -> V_39 = F_22 ( V_73 , V_2 -> V_91 , V_92 , 16 , 0 ) ;
if ( ! V_2 -> V_39 ) {
F_23 ( V_93 L_3 , V_73 ) ;
goto V_89;
}
V_2 -> V_94 = V_34 ;
F_24 ( V_2 ) ;
return 0 ;
V_89:
return 1 ;
}
int F_25 ( struct V_1 * V_2 , int V_95 , int V_96 )
{
unsigned long V_97 , V_98 , V_99 , V_100 = 0 ;
struct V_101 * V_91 = V_2 -> V_91 ;
if ( V_96 != - 1 ) {
V_97 = F_26 ( V_91 , V_96 ) ;
V_98 = F_27 ( V_91 , V_96 ) ;
if ( ! V_97 || ! V_98 )
goto V_89;
V_100 = F_28 ( V_91 , V_96 ) ;
if ( V_100 & V_102 ) {
if ( V_100 & V_103 )
V_2 -> V_104 = F_29 ( V_97 , V_98 ) ;
else
V_2 -> V_104 = F_30 ( V_97 ,
V_98 ) ;
} else
V_2 -> V_104 = ( void * ) V_97 ;
if ( ! V_2 -> V_104 )
goto V_89;
}
V_97 = F_26 ( V_91 , V_95 ) ;
V_98 = F_27 ( V_91 , V_95 ) ;
if ( ! V_97 || ! V_98 )
goto V_89;
V_99 = F_28 ( V_91 , V_95 ) ;
if ( V_99 & V_103 )
V_2 -> V_105 = F_29 ( V_97 , V_98 ) ;
else
V_2 -> V_105 = F_30 ( V_97 , V_98 ) ;
if ( ! V_2 -> V_105 ) {
if ( V_2 -> V_104 && ( V_100 & V_102 ) )
F_31 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
goto V_89;
}
return 0 ;
V_89:
return - 1 ;
}
void F_32 ( void T_5 * V_105 )
{
F_31 ( V_105 ) ;
}
static struct V_1 * T_1 F_33 ( struct V_101 * V_91 ,
const struct V_106 * V_107 ,
struct V_72 * V_29 , unsigned int V_24 )
{
struct V_1 * V_2 ;
struct V_28 * V_62 = F_34 ( V_29 ) ;
V_2 = F_35 ( sizeof( * V_2 ) + V_38 * sizeof( struct V_108 ) ,
V_88 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_91 = V_91 ;
V_2 -> V_41 = & V_91 -> V_41 ;
V_2 -> V_109 = V_107 -> V_110 ;
V_2 -> V_10 = & V_111 [ V_2 -> V_109 ] ;
F_19 ( & V_2 -> V_112 ) ;
V_2 -> V_67 = V_91 -> V_67 ;
( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ V_24 ] = V_2 ;
( (struct V_63 * ) V_62 -> V_64 ) -> V_11 = V_2 -> V_10 -> V_11 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_113 = V_62 ;
V_2 -> V_29 = V_29 ;
#ifdef F_15
F_36 ( & V_70 , F_11 , ( unsigned long ) V_62 ) ;
#endif
if ( V_55 -> V_114 ( V_2 ) )
goto V_89;
if ( ! F_17 ( V_2 , V_29 ) )
return V_2 ;
V_89:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_37 ( struct V_101 * V_91 )
{
int V_115 ;
if ( ! F_38 ( V_91 , F_39 ( 64 ) ) ) {
V_115 = F_40 ( V_91 , F_39 ( 64 ) ) ;
if ( V_115 ) {
V_115 = F_40 ( V_91 , F_39 ( 32 ) ) ;
if ( V_115 ) {
F_41 ( V_116 , & V_91 -> V_41 ,
L_4 ) ;
return V_115 ;
}
}
} else {
V_115 = F_38 ( V_91 , F_39 ( 32 ) ) ;
if ( V_115 ) {
F_41 ( V_116 , & V_91 -> V_41 ,
L_5 ) ;
return V_115 ;
}
V_115 = F_40 ( V_91 , F_39 ( 32 ) ) ;
if ( V_115 ) {
F_41 ( V_116 , & V_91 -> V_41 ,
L_6 ) ;
return V_115 ;
}
}
return V_115 ;
}
static int T_1 F_42 ( struct V_72 * V_29 ,
const struct V_117 * V_118 )
{
int V_119 , V_120 ; unsigned short V_60 ;
struct V_6 * * V_121 ;
struct V_122 * * V_123 ;
struct V_28 * V_62 = F_34 ( V_29 ) ;
V_60 = V_118 -> V_65 ;
V_119 = V_60 * V_118 -> V_11 ;
V_120 = V_119 ;
memset ( V_62 , 0x00 , sizeof( struct V_28 ) ) ;
V_121 = F_43 ( V_119 , sizeof( void * ) , V_88 ) ;
V_123 = F_43 ( V_120 , sizeof( void * ) , V_88 ) ;
if ( ! V_121 || ! V_123 )
goto V_124;
V_62 -> V_7 = V_121 ;
V_62 -> V_125 = V_123 ;
V_62 -> V_126 . V_29 = V_29 ;
V_62 -> V_64 = F_35 ( sizeof( struct V_63 ) , V_88 ) ;
if ( ! V_62 -> V_64 )
goto V_124;
( (struct V_63 * ) V_62 -> V_64 ) -> V_65 = V_60 ;
V_29 -> V_127 = V_128 ;
V_29 -> V_129 = 128 ;
V_29 -> V_130 = ~ 0 ;
V_29 -> V_131 = 1 ;
V_29 -> V_132 = 16 ;
return 0 ;
V_124:
F_10 ( V_121 ) ;
F_10 ( V_123 ) ;
return - 1 ;
}
static void T_1 F_44 ( struct V_72 * V_29 ,
const struct V_117 * V_118 )
{
int V_133 , V_61 = 0 , V_134 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_62 = F_34 ( V_29 ) ;
unsigned short V_135 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_65 ;
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ V_134 ] ;
for ( V_61 = 0 ; V_61 < V_118 -> V_11 ; V_61 ++ ) {
V_62 -> V_7 [ V_134 * V_118 -> V_11 + V_61 ] =
& V_2 -> V_5 [ V_61 ] . V_7 ;
V_62 -> V_125 [ V_134 * V_118 -> V_11 + V_61 ] =
& V_2 -> V_75 [ V_61 ] . V_125 ;
}
}
V_62 -> V_136 = V_137 ;
V_62 -> V_41 = V_2 -> V_41 ;
V_62 -> V_138 = V_139 ;
V_62 -> V_25 = & V_2 -> V_25 [ 0 ] ;
V_62 -> V_140 = V_135 * V_118 -> V_11 ;
V_62 -> V_141 = V_141 ;
if ( V_2 -> V_35 & V_36 )
V_133 = V_142 ;
else
V_133 = V_143 ;
V_62 -> V_144 = V_133 ;
V_29 -> V_133 = V_133 ;
V_2 -> V_29 -> V_145 = V_38 / V_62 -> V_140 ;
V_62 -> V_126 . V_29 = V_2 -> V_29 ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_6 V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_10 -> V_11 ; V_61 ++ ) {
V_2 -> V_5 [ V_61 ] . V_146 = 0x5005043011ab0000ULL ;
V_2 -> V_5 [ V_61 ] . V_146 =
F_46 ( ( V_147 ) ( * ( V_147 * ) & V_2 -> V_5 [ V_61 ] . V_146 ) ) ;
}
memcpy ( V_2 -> V_25 , & V_2 -> V_5 [ 0 ] . V_146 , V_148 ) ;
}
static int T_1 F_47 ( struct V_101 * V_91 ,
const struct V_106 * V_107 )
{
unsigned int V_115 , V_149 = 0 ;
struct V_1 * V_2 ;
T_7 V_150 = F_14 ;
struct V_72 * V_29 = NULL ;
const struct V_117 * V_10 ;
F_41 ( V_151 , & V_91 -> V_41 ,
L_7 , V_152 ) ;
V_115 = F_48 ( V_91 ) ;
if ( V_115 )
goto V_153;
F_49 ( V_91 ) ;
V_115 = F_50 ( V_91 , V_137 ) ;
if ( V_115 )
goto V_154;
V_115 = F_37 ( V_91 ) ;
if ( V_115 )
goto V_155;
V_29 = F_51 ( & V_156 , sizeof( void * ) ) ;
if ( ! V_29 ) {
V_115 = - V_157 ;
goto V_155;
}
V_10 = & V_111 [ V_107 -> V_110 ] ;
F_34 ( V_29 ) =
F_43 ( 1 , sizeof( struct V_28 ) , V_88 ) ;
if ( ! F_34 ( V_29 ) ) {
F_10 ( V_29 ) ;
V_115 = - V_157 ;
goto V_155;
}
V_115 = F_42 ( V_29 , V_10 ) ;
if ( V_115 ) {
F_10 ( V_29 ) ;
V_115 = - V_157 ;
goto V_155;
}
F_52 ( V_91 , F_34 ( V_29 ) ) ;
do {
V_2 = F_33 ( V_91 , V_107 , V_29 , V_149 ) ;
if ( ! V_2 ) {
V_115 = - V_157 ;
goto V_155;
}
F_45 ( V_2 ) ;
V_2 -> V_158 = V_149 ;
V_115 = V_55 -> V_159 ( V_2 ) ;
if ( V_115 ) {
F_3 ( V_2 ) ;
goto V_155;
}
V_149 ++ ;
} while ( V_149 < V_10 -> V_65 );
#ifdef F_15
F_36 ( & V_70 , F_11 ,
( unsigned long ) F_34 ( V_29 ) ) ;
#endif
F_44 ( V_29 , V_10 ) ;
V_115 = F_53 ( V_29 , & V_91 -> V_41 ) ;
if ( V_115 )
goto V_160;
V_115 = F_54 ( F_34 ( V_29 ) ) ;
if ( V_115 )
goto V_160;
V_115 = F_55 ( V_91 -> V_67 , V_150 , V_161 ,
V_137 , F_34 ( V_29 ) ) ;
if ( V_115 )
goto V_162;
V_55 -> V_163 ( V_2 ) ;
F_56 ( V_2 -> V_29 ) ;
return 0 ;
V_162:
F_57 ( F_34 ( V_29 ) ) ;
V_160:
F_58 ( V_2 -> V_29 ) ;
V_155:
F_59 ( V_91 ) ;
V_154:
F_60 ( V_91 ) ;
V_153:
return V_115 ;
}
static void T_8 F_61 ( struct V_101 * V_91 )
{
unsigned short V_60 , V_61 = 0 ;
struct V_28 * V_62 = F_62 ( V_91 ) ;
struct V_1 * V_2 = NULL ;
V_60 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_65 ;
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ 0 ] ;
#ifdef F_15
F_63 ( & V_70 ) ;
#endif
F_52 ( V_91 , NULL ) ;
F_57 ( V_62 ) ;
F_64 ( V_2 -> V_29 ) ;
F_58 ( V_2 -> V_29 ) ;
V_55 -> V_164 ( V_2 ) ;
F_65 ( V_2 -> V_67 , V_62 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_2 = ( (struct V_63 * ) V_62 -> V_64 ) -> V_2 [ V_61 ] ;
F_3 ( V_2 ) ;
}
F_10 ( V_62 -> V_7 ) ;
F_10 ( V_62 -> V_125 ) ;
F_10 ( V_62 ) ;
F_59 ( V_91 ) ;
F_60 ( V_91 ) ;
return;
}
static int T_9 F_66 ( void )
{
int V_115 ;
V_128 = F_67 ( & V_165 ) ;
if ( ! V_128 )
return - V_157 ;
V_166 = F_68 ( L_8 , sizeof( struct V_167 ) ,
0 , V_168 , NULL ) ;
if ( ! V_166 ) {
V_115 = - V_157 ;
F_69 ( L_9 , V_169 ) ;
goto V_89;
}
V_115 = F_70 ( & V_170 ) ;
if ( V_115 )
goto V_89;
return 0 ;
V_89:
F_71 ( V_128 ) ;
return V_115 ;
}
static void T_10 F_72 ( void )
{
F_73 ( & V_170 ) ;
F_71 ( V_128 ) ;
F_74 ( V_166 ) ;
}
