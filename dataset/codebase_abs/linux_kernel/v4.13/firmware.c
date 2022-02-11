static unsigned long F_1 ( unsigned long V_1 )
{
#ifdef F_2
if( F_3 ( V_2 ) ) {
if( ( V_1 & 0xff000000 ) == 0xf0000000 )
return 0xf0f0f0f000000000UL | ( V_3 ) V_1 ;
if( ( V_1 & 0xf0000000 ) == 0xf0000000 )
return 0xffffffff00000000UL | ( V_3 ) V_1 ;
}
#endif
return V_1 ;
}
static void F_4 ( unsigned long * V_4 )
{
#ifdef F_2
int V_5 ;
unsigned int * V_6 = ( unsigned int * ) V_4 ;
if( F_3 ( V_2 ) ) {
for( V_5 = 31 ; V_5 >= 0 ; -- V_5 )
V_4 [ V_5 ] = V_6 [ V_5 ] ;
}
#endif
}
void F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( V_8 , V_9 ,
F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
if ( V_10 [ 0 ] != V_11 )
V_2 = 0 ;
}
void F_8 ( void )
{
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
F_5 () ;
F_10 ( & V_13 , V_12 ) ;
}
void F_5 ( void )
{
return;
}
void F_8 ( void )
{
return;
}
void F_11 ( void )
{
if ( F_12 ( & V_13 ) )
F_13 ( & V_13 ) ;
}
int F_14 ( unsigned long V_1 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_15 , V_16 , V_1 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int T_1 F_15 ( struct F_15 * V_17 , void * V_18 , unsigned long V_19 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
memcpy ( & V_10 , V_17 , sizeof( * V_17 ) ) ;
memcpy ( & V_20 , V_18 , V_19 ) ;
V_14 = F_6 ( V_21 , V_22 ,
F_7 ( V_10 ) , F_7 ( V_20 ) , V_19 ) ;
memcpy ( V_17 , V_10 , sizeof( * V_17 ) ) ;
memcpy ( V_18 , V_20 , V_19 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_16 ( unsigned long V_23 , unsigned long V_24 )
{
int V_14 = 0 ;
unsigned long V_12 ;
if ( ! F_17 () )
return - 1 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_25 , V_26 , F_7 ( & V_23 ) , F_7 ( & V_24 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_18 ( unsigned long V_27 )
{
int V_14 = 0 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_21 , V_28 , V_27 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_19 ( unsigned long * V_29 )
{
int V_14 = 0 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_21 , V_30 , F_7 ( V_10 ) ) ;
* V_29 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_20 ( struct V_31 * V_32 )
{
int V_7 ;
V_7 = F_6 ( V_33 , V_34 , F_7 ( V_10 ) ) ;
F_4 ( V_10 ) ;
V_32 -> V_35 = V_10 [ 0 ] ;
V_32 -> V_36 = V_10 [ 1 ] ;
V_32 -> V_37 = V_10 [ 17 ] ;
V_32 -> V_38 = V_10 [ 18 ] ;
return V_7 ;
}
int V_31 ( struct V_31 * V_32 )
{
int V_7 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_7 = F_20 ( V_32 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_7 ;
}
int F_21 ( unsigned long * V_39 , unsigned long V_40 , unsigned int V_41 ,
void * V_42 , unsigned int V_43 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_44 , V_45 , F_7 ( V_10 ) , V_40 ,
V_41 , F_7 ( V_20 ) , V_43 ) ;
F_4 ( V_10 ) ;
* V_39 = V_10 [ 0 ] ;
memcpy ( V_42 , V_20 , V_43 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 , long V_50 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_51 , V_52 , F_7 ( V_10 ) ,
F_7 ( V_20 ) , V_50 ) ;
F_4 ( V_10 ) ;
memcpy ( V_47 , V_10 , sizeof( * V_47 ) ) ;
memcpy ( V_49 , V_20 , sizeof( * V_49 ) ) ;
F_10 ( & V_13 , V_12 ) ;
V_47 -> V_53 = F_1 ( V_47 -> V_53 ) ;
return V_14 ;
}
int F_23 ( struct V_54 * V_55 ,
long V_50 , long V_56 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_51 , V_57 , F_7 ( V_10 ) ,
V_50 , V_56 ) ;
F_4 ( V_10 ) ;
memcpy ( V_55 , V_10 , sizeof( * V_55 ) ) ;
F_10 ( & V_13 , V_12 ) ;
V_55 -> V_53 = F_1 ( V_55 -> V_53 ) ;
return V_14 ;
}
int F_24 ( struct V_58 * V_38 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_8 , V_59 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
memcpy ( V_38 , V_10 , sizeof( * V_38 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_25 ( char * V_60 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_8 , V_61 , F_7 ( V_10 ) ,
V_62 , F_7 ( V_60 ) ) ;
F_4 ( V_10 ) ;
if ( V_14 == V_63 ) {
V_60 [ V_10 [ 0 ] ] = '\0' ;
} else {
V_60 [ 0 ] = 0 ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_26 ( unsigned long * V_64 , int V_65 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_8 , V_66 , F_7 ( V_10 ) , V_65 ) ;
F_4 ( V_10 ) ;
* V_64 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_27 ( unsigned long * V_67 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_10 [ 0 ] = 0 ;
V_14 = F_6 ( V_8 , V_68 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
* V_67 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_28 ( unsigned long * V_69 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_10 [ 0 ] = 0 ;
V_14 = F_6 ( V_8 , V_9 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
if ( V_14 == V_63 ) {
* V_69 = V_10 [ 0 ] ;
} else {
* V_69 = V_70 ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_29 ( struct F_29 * V_71 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_72 , V_73 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
memcpy ( V_71 , V_10 , sizeof( * V_71 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_30 ( unsigned long * V_74 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_10 [ 0 ] = 0 ;
V_14 = F_6 ( V_72 , V_75 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
* V_74 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_31 ( struct F_31 * V_76 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_77 , V_78 , F_7 ( V_10 ) , 0 ) ;
memcpy ( V_76 , V_10 , sizeof( * V_76 ) ) ;
F_10 ( & V_13 , V_12 ) ;
if( V_14 < 0 ) {
V_76 -> V_79 = 0 ;
}
return V_14 ;
}
int F_32 ( struct V_80 * V_1 ,
struct V_48 * V_49 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
memcpy ( V_20 , V_49 , sizeof( * V_49 ) ) ;
V_14 = F_6 ( V_81 , V_82 , F_7 ( V_10 ) ,
F_7 ( V_20 ) ) ;
memcpy ( V_1 , V_10 , sizeof( * V_1 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_33 ( char * V_83 , unsigned long V_40 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_84 , V_85 ,
F_7 ( V_10 ) , V_40 ) ;
if ( V_14 < 0 ) {
memset ( V_83 , 0 , V_86 ) ;
} else {
memcpy ( V_83 , V_10 , V_86 ) ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_34 ( unsigned long V_87 , void * V_88 , unsigned long V_89 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_90 , V_91 , V_87 ,
F_7 ( V_10 ) , V_89 ) ;
F_4 ( V_10 ) ;
memcpy ( V_88 , V_10 , V_89 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_35 ( unsigned long V_87 , void * V_88 , unsigned long V_89 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
memcpy ( V_10 , V_88 , V_89 ) ;
F_4 ( V_10 ) ;
V_14 = F_6 ( V_90 , V_92 , V_87 ,
F_7 ( V_10 ) , V_89 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_36 ( unsigned long * V_93 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_90 , V_94 , F_7 ( V_10 ) ) ;
* V_93 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_37 ( void )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_90 , V_95 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_38 ( void )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_90 , V_96 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_39 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
#define F_40 () (strlen(boot_cpu_data.pdc.sys_model_name) == 14 && \
strncmp(boot_cpu_data.pdc.sys_model_name, "9000/785", 8) == 0)
V_14 = F_6 ( V_101 , V_102 ,
F_7 ( V_10 ) , F_7 ( V_98 ) ) ;
if ( V_14 < V_63 )
goto V_103;
if ( V_10 [ 0 ] < 16 ) {
V_100 -> V_104 = V_10 [ 0 ] ;
} else {
V_100 -> V_104 = - 1 ;
}
switch ( V_10 [ 1 ] ) {
case 1 : V_100 -> V_105 = 50 ; break;
case 2 : V_100 -> V_105 = 25 ; break;
case 5 : V_100 -> V_105 = 12 ; break;
case 25 : V_100 -> V_105 = 10 ; break;
case 20 : V_100 -> V_105 = 12 ; break;
case 40 : V_100 -> V_105 = 10 ; break;
default: V_100 -> V_105 = - 1 ; break;
}
if ( F_40 () ) {
V_100 -> V_106 = V_10 [ 4 ] ;
V_100 -> V_107 = V_10 [ 5 ] ;
} else {
V_100 -> V_106 = - 1 ;
V_100 -> V_107 = - 1 ;
}
V_103:
F_10 ( & V_13 , V_12 ) ;
return ( V_14 >= V_63 ) ;
}
int F_41 ( unsigned long * V_108 , unsigned long V_40 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_109 , V_110 ,
F_7 ( V_10 ) , V_40 ) ;
F_4 ( V_10 ) ;
* V_108 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_42 ( unsigned long V_108 , unsigned long V_40 , void * V_111 )
{
int V_14 ;
unsigned long V_12 ;
F_43 ( ( unsigned long ) V_111 & 0x7 ) ;
F_9 ( & V_13 , V_12 ) ;
V_10 [ 0 ] = V_108 ;
V_14 = F_6 ( V_109 , V_112 ,
F_7 ( V_10 ) , V_40 , F_7 ( V_111 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_44 ( struct V_113 * V_114 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_115 , V_116 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
memcpy ( V_114 , V_10 , sizeof( * V_114 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_45 ( struct V_117 * V_118 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_119 , V_120 , F_7 ( V_10 ) , 0 ) ;
F_4 ( V_10 ) ;
memcpy ( V_118 , V_10 , sizeof( * V_118 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_46 ( struct V_121 * V_122 ,
unsigned long * V_123 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_119 , V_124 , F_7 ( V_10 ) ,
F_7 ( V_20 ) ) ;
if ( V_14 == V_63 ) {
F_4 ( V_10 ) ;
memcpy ( V_122 , V_10 , sizeof( * V_122 ) ) ;
F_4 ( V_20 ) ;
memcpy ( V_123 , V_20 ,
V_122 -> V_125 * sizeof( * V_123 ) ) ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_47 ( unsigned long V_126 , unsigned long V_127 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_115 , V_128 , V_126 , V_127 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_48 ( struct V_129 * V_130 ,
struct V_131 * V_111 , unsigned long V_132 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_119 , V_133 , F_7 ( V_10 ) , F_7 ( V_20 ) , V_132 ) ;
F_4 ( V_10 ) ;
memcpy ( V_130 , V_10 , sizeof( * V_130 ) ) ;
memcpy ( V_111 , V_20 , V_132 * sizeof( * V_111 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_49 ( unsigned long V_134 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_135 , V_136 ,
V_137 , V_134 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_50 ( void )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_135 , V_138 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int T_1 F_51 ( unsigned long * V_139 )
{
int V_14 ;
unsigned long V_12 ;
* V_139 = ( unsigned long ) ( - 1 ) ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_140 , V_141 , F_7 ( V_10 ) , 0 ) ;
if ( V_14 == V_63 ) {
F_4 ( V_10 ) ;
* V_139 = F_1 ( V_10 [ 0 ] ) ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_52 ( int V_142 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_140 , V_143 , F_7 ( V_10 ) , V_142 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
void F_53 ( void )
{
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
F_6 ( V_144 , V_145 , 0 ) ;
F_10 ( & V_13 , V_12 ) ;
}
void F_54 ( void )
{
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
F_6 ( V_144 , V_146 , 0 ) ;
F_10 ( & V_13 , V_12 ) ;
}
int F_55 ( const unsigned char * V_147 , unsigned V_89 )
{
unsigned int V_5 ;
unsigned long V_12 ;
for ( V_5 = 0 ; V_5 < V_89 ; ) {
switch( V_147 [ V_5 ] ) {
case '\n' :
V_148 [ V_5 + 0 ] = '\r' ;
V_148 [ V_5 + 1 ] = '\n' ;
V_5 += 2 ;
goto V_149;
default:
V_148 [ V_5 ] = V_147 [ V_5 ] ;
V_5 ++ ;
break;
}
}
V_149:
F_9 ( & V_13 , V_12 ) ;
F_56 ( V_150 -> V_151 . V_152 ,
( unsigned long ) V_150 -> V_151 . V_40 , V_153 ,
V_150 -> V_151 . V_154 , F_7 ( V_150 -> V_151 . V_155 . V_156 ) ,
F_7 ( V_157 ) , 0 , F_7 ( V_148 ) , V_5 , 0 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_5 ;
}
int F_57 ( void )
{
int V_158 ;
int V_159 ;
unsigned long V_12 ;
if ( ! V_150 -> V_160 . V_152 )
return 0 ;
F_9 ( & V_13 , V_12 ) ;
F_56 ( V_150 -> V_160 . V_152 ,
( unsigned long ) V_150 -> V_160 . V_40 , V_161 ,
V_150 -> V_160 . V_154 , F_7 ( V_150 -> V_160 . V_155 . V_156 ) ,
F_7 ( V_157 ) , 0 , F_7 ( V_148 ) , 1 , 0 ) ;
V_158 = * V_148 ;
V_159 = * V_157 ;
F_10 ( & V_13 , V_12 ) ;
if ( V_159 == 0 )
return - 1 ;
return V_158 ;
}
int F_58 ( unsigned long V_162 , unsigned long V_12 ,
unsigned long V_163 , unsigned long V_164 ,
unsigned long V_165 )
{
int V_14 ;
unsigned long V_166 ;
F_9 ( & V_13 , V_166 ) ;
V_14 = F_56 ( V_162 , V_12 , V_163 , V_164 , V_165 ) ;
F_10 ( & V_13 , V_166 ) ;
return V_14 ;
}
int F_59 ( struct V_167 * V_168 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_169 , V_170 , F_7 ( V_10 ) ) ;
memcpy ( V_168 , V_10 , sizeof( * V_168 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_60 ( unsigned long * V_39 , unsigned long V_171 , unsigned long V_172 ,
unsigned long V_173 , void * V_174 )
{
int V_14 ;
unsigned long V_12 ;
static struct V_175 T_2 V_176 ( ( F_61 ( 8 ) ) ) ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_169 , V_177 , F_7 ( V_10 ) ,
V_171 , V_172 , V_173 , F_7 ( & T_2 ) ) ;
if( ! V_14 ) {
* V_39 = V_10 [ 0 ] ;
memcpy ( V_174 , & T_2 , * V_39 ) ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_62 ( struct V_178 * V_179 , unsigned long V_40 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_180 , V_181 ,
F_7 ( & V_10 ) , V_40 ) ;
memcpy ( V_179 , V_10 , sizeof( * V_179 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_63 ( unsigned long * V_108 , unsigned long V_182 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_183 , V_184 ,
F_7 ( V_10 ) , V_182 ) ;
* V_108 = V_10 [ 0 ] ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_64 ( void * V_130 , unsigned long V_182 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_183 , V_185 ,
F_7 ( V_130 ) , V_182 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_65 ( unsigned long * V_186 , void * V_174 ,
unsigned long V_89 , unsigned long V_187 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_188 , V_189 , F_7 ( V_10 ) ,
F_7 ( V_20 ) , V_89 , V_187 ) ;
* V_186 = V_10 [ 0 ] ;
memcpy ( V_174 , V_20 , * V_186 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_66 ( unsigned long V_190 , int V_191 , V_3 * V_174 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_183 , V_192 ,
F_7 ( V_10 ) , V_190 , V_191 ) ;
switch( V_191 ) {
case 1 : * ( V_193 * ) V_174 = ( V_193 ) V_10 [ 0 ] ; break;
case 2 : * ( V_194 * ) V_174 = ( V_194 ) V_10 [ 0 ] ; break;
case 4 : * ( V_3 * ) V_174 = ( V_3 ) V_10 [ 0 ] ; break;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_67 ( unsigned long V_190 , int V_191 , V_3 V_195 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_183 , V_196 ,
V_190 , V_191 , V_195 ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_68 ( struct V_197 * V_118 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_198 , V_199 ,
F_7 ( & V_10 ) ) ;
if ( V_14 == V_63 )
memcpy ( V_118 , & V_10 , sizeof( * V_118 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_69 ( struct V_200 * V_122 ,
unsigned long * V_123 , unsigned long V_201 )
{
int V_14 ;
unsigned long V_12 , V_132 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_198 , V_202 ,
F_7 ( & V_10 ) , V_203 , F_7 ( & V_20 ) ) ;
if ( V_14 == V_63 ) {
V_132 = F_70 ( V_10 [ 0 ] , V_201 ) ;
V_122 -> V_125 = V_132 ;
V_122 -> V_204 = V_132 * sizeof( unsigned long ) ;
memcpy ( V_123 , & V_20 , V_122 -> V_204 ) ;
}
F_10 ( & V_13 , V_12 ) ;
F_71 ( V_14 == V_63 && V_10 [ 0 ] > V_201 ) ;
return V_14 ;
}
int F_72 ( struct V_200 * V_122 ,
unsigned long * V_123 , unsigned long V_89 ,
unsigned long V_187 )
{
int V_14 ;
unsigned long V_12 , V_132 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_198 , V_205 ,
F_7 ( & V_10 ) , F_7 ( V_123 ) ,
V_89 , V_187 ) ;
if ( V_14 == V_63 ) {
V_132 = F_70 ( V_10 [ 0 ] , V_89 ) ;
V_122 -> V_204 = V_132 ;
V_122 -> V_125 = V_132 / sizeof( unsigned long ) ;
}
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
int F_73 (
struct V_206 * V_122 ,
unsigned long V_207 )
{
int V_14 ;
unsigned long V_12 ;
F_9 ( & V_13 , V_12 ) ;
V_14 = F_6 ( V_198 , V_208 ,
F_7 ( & V_10 ) , V_207 ) ;
if ( V_14 == V_63 )
memcpy ( V_122 , & V_10 , sizeof( * V_122 ) ) ;
F_10 ( & V_13 , V_12 ) ;
return V_14 ;
}
long F_56 ( unsigned long V_209 , ... )
{
T_3 args ;
extern struct V_210 V_211 ;
extern unsigned long V_212 ( unsigned int * ,
unsigned int * ,
unsigned int ) ;
va_start ( args , V_209 ) ;
V_211 . V_213 = va_arg (args, unsigned int) ;
V_211 . V_214 = va_arg (args, unsigned int) ;
V_211 . V_215 = va_arg (args, unsigned int) ;
V_211 . V_216 = va_arg (args, unsigned int) ;
V_211 . V_217 = va_arg (args, unsigned int) ;
V_211 . V_218 = va_arg (args, unsigned int) ;
V_211 . V_219 = va_arg (args, unsigned int) ;
V_211 . V_220 = va_arg (args, unsigned int) ;
V_211 . V_221 = va_arg (args, unsigned int) ;
V_211 . V_222 = va_arg (args, unsigned int) ;
V_211 . V_223 = va_arg (args, unsigned int) ;
V_211 . V_224 = va_arg (args, unsigned int) ;
V_211 . V_225 = va_arg (args, unsigned int) ;
V_211 . V_226 = va_arg (args, unsigned int) ;
va_end ( args ) ;
return V_212 ( & V_211 . V_227 , & V_211 . V_213 , V_209 ) ;
}
long F_74 ( unsigned long V_209 , ... )
{
T_3 args ;
extern struct V_228 V_229 ;
extern unsigned long V_230 ( unsigned long * ,
unsigned long * ,
unsigned long ) ;
va_start ( args , V_209 ) ;
V_229 . V_213 = va_arg (args, unsigned long) ;
V_229 . V_214 = va_arg (args, unsigned long) ;
V_229 . V_215 = va_arg (args, unsigned long) ;
V_229 . V_216 = va_arg (args, unsigned long) ;
V_229 . V_217 = va_arg (args, unsigned long) ;
V_229 . V_218 = va_arg (args, unsigned long) ;
V_229 . V_219 = va_arg (args, unsigned long) ;
V_229 . V_220 = va_arg (args, unsigned long) ;
V_229 . V_221 = va_arg (args, unsigned long) ;
V_229 . V_222 = va_arg (args, unsigned long) ;
V_229 . V_223 = va_arg (args, unsigned long) ;
V_229 . V_224 = va_arg (args, unsigned long) ;
V_229 . V_225 = va_arg (args, unsigned long) ;
V_229 . V_226 = va_arg (args, unsigned long) ;
va_end ( args ) ;
return V_230 ( & V_229 . V_227 , & V_229 . V_213 , V_209 ) ;
}
