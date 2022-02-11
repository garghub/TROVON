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
if ( F_3 ( V_2 ) ) {
for ( V_5 = ( V_7 - 1 ) ; V_5 >= 0 ; -- V_5 )
V_4 [ V_5 ] = V_6 [ V_5 ] ;
}
#endif
}
void F_5 ( void )
{
int V_8 ;
V_8 = F_6 ( V_9 , V_10 ,
F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
if ( V_11 [ 0 ] != V_12 )
V_2 = 0 ;
}
void F_8 ( void )
{
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
F_5 () ;
F_10 ( & V_14 , V_13 ) ;
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
if ( F_12 ( & V_14 ) )
F_13 ( & V_14 ) ;
}
int F_14 ( unsigned long V_1 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_16 , V_17 , V_1 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int T_1 F_15 ( unsigned int * V_18 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_19 , 0UL , F_7 ( V_11 ) ) ;
F_4 ( V_11 ) ;
* V_18 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int T_1 F_16 ( struct F_16 * V_20 , void * V_21 , unsigned long V_22 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
memcpy ( & V_11 , V_20 , sizeof( * V_20 ) ) ;
memcpy ( & V_23 , V_21 , V_22 ) ;
V_15 = F_6 ( V_24 , V_25 ,
F_7 ( V_11 ) , F_7 ( V_23 ) , V_22 ) ;
memcpy ( V_20 , V_11 , sizeof( * V_20 ) ) ;
memcpy ( V_21 , V_23 , V_22 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_17 ( unsigned long V_26 , unsigned long V_27 )
{
int V_15 = 0 ;
unsigned long V_13 ;
if ( ! F_18 () )
return - 1 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_28 , V_29 , F_7 ( & V_26 ) , F_7 ( & V_27 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_19 ( unsigned long V_30 )
{
int V_15 = 0 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_24 , V_31 , V_30 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_20 ( unsigned long * V_32 )
{
int V_15 = 0 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_24 , V_33 , F_7 ( V_11 ) ) ;
* V_32 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_21 ( struct V_34 * V_35 )
{
int V_8 ;
V_8 = F_6 ( V_36 , V_37 , F_7 ( V_11 ) ) ;
F_4 ( V_11 ) ;
V_35 -> V_38 = V_11 [ 0 ] ;
V_35 -> V_39 = V_11 [ 1 ] ;
V_35 -> V_40 = V_11 [ 17 ] ;
V_35 -> V_41 = V_11 [ 18 ] ;
return V_8 ;
}
int V_34 ( struct V_34 * V_35 )
{
int V_8 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_8 = F_21 ( V_35 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_8 ;
}
int F_22 ( unsigned long * V_42 , unsigned long V_43 , unsigned int V_44 ,
void * V_45 , unsigned int V_46 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_47 , V_48 , F_7 ( V_11 ) , V_43 ,
V_44 , F_7 ( V_23 ) , V_46 ) ;
F_4 ( V_11 ) ;
* V_42 = V_11 [ 0 ] ;
memcpy ( V_45 , V_23 , V_46 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_23 ( struct V_49 * V_50 ,
struct V_51 * V_52 , long V_53 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_54 , V_55 , F_7 ( V_11 ) ,
F_7 ( V_23 ) , V_53 ) ;
F_4 ( V_11 ) ;
memcpy ( V_50 , V_11 , sizeof( * V_50 ) ) ;
memcpy ( V_52 , V_23 , sizeof( * V_52 ) ) ;
F_10 ( & V_14 , V_13 ) ;
V_50 -> V_56 = F_1 ( V_50 -> V_56 ) ;
return V_15 ;
}
int F_24 ( struct V_57 * V_58 ,
long V_53 , long V_59 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_54 , V_60 , F_7 ( V_11 ) ,
V_53 , V_59 ) ;
F_4 ( V_11 ) ;
memcpy ( V_58 , V_11 , sizeof( * V_58 ) ) ;
F_10 ( & V_14 , V_13 ) ;
V_58 -> V_56 = F_1 ( V_58 -> V_56 ) ;
return V_15 ;
}
int F_25 ( struct V_61 * V_41 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_9 , V_62 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
memcpy ( V_41 , V_11 , sizeof( * V_41 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_26 ( char * V_63 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_9 , V_64 , F_7 ( V_11 ) ,
V_65 , F_7 ( V_63 ) ) ;
F_4 ( V_11 ) ;
if ( V_15 == V_66 ) {
V_63 [ V_11 [ 0 ] ] = '\0' ;
} else {
V_63 [ 0 ] = 0 ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_27 ( unsigned long * V_67 , int V_68 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_9 , V_69 , F_7 ( V_11 ) , V_68 ) ;
F_4 ( V_11 ) ;
* V_67 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_28 ( unsigned long * V_70 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_11 [ 0 ] = 0 ;
V_15 = F_6 ( V_9 , V_71 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
* V_70 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_29 ( unsigned long * V_72 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_11 [ 0 ] = 0 ;
V_15 = F_6 ( V_9 , V_10 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
if ( V_15 == V_66 ) {
* V_72 = V_11 [ 0 ] ;
} else {
* V_72 = V_73 ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_30 ( struct F_30 * V_74 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_75 , V_76 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
memcpy ( V_74 , V_11 , sizeof( * V_74 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_31 ( unsigned long * V_77 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_11 [ 0 ] = 0 ;
V_15 = F_6 ( V_75 , V_78 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
* V_77 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_32 ( struct F_32 * V_79 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_80 , V_81 , F_7 ( V_11 ) , 0 ) ;
memcpy ( V_79 , V_11 , sizeof( * V_79 ) ) ;
F_10 ( & V_14 , V_13 ) ;
if( V_15 < 0 ) {
V_79 -> V_82 = 0 ;
}
return V_15 ;
}
int F_33 ( struct V_83 * V_1 ,
struct V_51 * V_52 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
memcpy ( V_23 , V_52 , sizeof( * V_52 ) ) ;
V_15 = F_6 ( V_84 , V_85 , F_7 ( V_11 ) ,
F_7 ( V_23 ) ) ;
memcpy ( V_1 , V_11 , sizeof( * V_1 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_34 ( char * V_86 , unsigned long V_43 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_87 , V_88 ,
F_7 ( V_11 ) , V_43 ) ;
if ( V_15 < 0 ) {
memset ( V_86 , 0 , V_89 ) ;
} else {
memcpy ( V_86 , V_11 , V_89 ) ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_35 ( unsigned long V_90 , void * V_91 , unsigned long V_92 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_93 , V_94 , V_90 ,
F_7 ( V_11 ) , V_92 ) ;
F_4 ( V_11 ) ;
memcpy ( V_91 , V_11 , V_92 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_36 ( unsigned long V_90 , void * V_91 , unsigned long V_92 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
memcpy ( V_11 , V_91 , V_92 ) ;
F_4 ( V_11 ) ;
V_15 = F_6 ( V_93 , V_95 , V_90 ,
F_7 ( V_11 ) , V_92 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_37 ( unsigned long * V_96 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_93 , V_97 , F_7 ( V_11 ) ) ;
* V_96 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_38 ( void )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_93 , V_98 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_39 ( void )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_93 , V_99 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_40 ( struct V_100 * V_101 , struct V_102 * V_103 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
#define F_41 () (strlen(boot_cpu_data.pdc.sys_model_name) == 14 && \
strncmp(boot_cpu_data.pdc.sys_model_name, "9000/785", 8) == 0)
V_15 = F_6 ( V_104 , V_105 ,
F_7 ( V_11 ) , F_7 ( V_101 ) ) ;
if ( V_15 < V_66 )
goto V_106;
if ( V_11 [ 0 ] < 16 ) {
V_103 -> V_107 = V_11 [ 0 ] ;
} else {
V_103 -> V_107 = - 1 ;
}
switch ( V_11 [ 1 ] ) {
case 1 : V_103 -> V_108 = 50 ; break;
case 2 : V_103 -> V_108 = 25 ; break;
case 5 : V_103 -> V_108 = 12 ; break;
case 25 : V_103 -> V_108 = 10 ; break;
case 20 : V_103 -> V_108 = 12 ; break;
case 40 : V_103 -> V_108 = 10 ; break;
default: V_103 -> V_108 = - 1 ; break;
}
if ( F_41 () ) {
V_103 -> V_109 = V_11 [ 4 ] ;
V_103 -> V_110 = V_11 [ 5 ] ;
} else {
V_103 -> V_109 = - 1 ;
V_103 -> V_110 = - 1 ;
}
V_106:
F_10 ( & V_14 , V_13 ) ;
return ( V_15 >= V_66 ) ;
}
int F_42 ( unsigned long * V_111 , unsigned long V_43 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_112 , V_113 ,
F_7 ( V_11 ) , V_43 ) ;
F_4 ( V_11 ) ;
* V_111 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_43 ( unsigned long V_111 , unsigned long V_43 , void * V_114 )
{
int V_15 ;
unsigned long V_13 ;
F_44 ( ( unsigned long ) V_114 & 0x7 ) ;
F_9 ( & V_14 , V_13 ) ;
V_11 [ 0 ] = V_111 ;
V_15 = F_6 ( V_112 , V_115 ,
F_7 ( V_11 ) , V_43 , F_7 ( V_114 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_45 ( struct V_116 * V_117 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_118 , V_119 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
memcpy ( V_117 , V_11 , sizeof( * V_117 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_46 ( struct V_120 * V_121 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_122 , V_123 , F_7 ( V_11 ) , 0 ) ;
F_4 ( V_11 ) ;
memcpy ( V_121 , V_11 , sizeof( * V_121 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_47 ( struct V_124 * V_125 ,
unsigned long * V_126 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_122 , V_127 , F_7 ( V_11 ) ,
F_7 ( V_126 ) ) ;
if ( V_15 == V_66 ) {
F_4 ( V_11 ) ;
memcpy ( V_125 , V_11 , sizeof( * V_125 ) ) ;
}
F_10 ( & V_14 , V_13 ) ;
#ifdef F_2
if ( F_48 ( ( V_15 == V_66 ) && V_2 ) )
return V_128 ;
#endif
return V_15 ;
}
int F_49 ( unsigned long V_129 , unsigned long V_130 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_118 , V_131 , V_129 , V_130 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_50 ( struct V_132 * V_133 ,
struct V_134 * V_114 , unsigned long V_135 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_122 , V_136 , F_7 ( V_11 ) , F_7 ( V_23 ) , V_135 ) ;
F_4 ( V_11 ) ;
memcpy ( V_133 , V_11 , sizeof( * V_133 ) ) ;
memcpy ( V_114 , V_23 , V_135 * sizeof( * V_114 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_51 ( unsigned long V_137 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_138 , V_139 ,
V_140 , V_137 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_52 ( void )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_138 , V_141 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int T_1 F_53 ( unsigned long * V_142 )
{
int V_15 ;
unsigned long V_13 ;
* V_142 = ( unsigned long ) ( - 1 ) ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_143 , V_144 , F_7 ( V_11 ) , 0 ) ;
if ( V_15 == V_66 ) {
F_4 ( V_11 ) ;
* V_142 = F_1 ( V_11 [ 0 ] ) ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_54 ( int V_145 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_143 , V_146 , F_7 ( V_11 ) , V_145 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
void F_55 ( void )
{
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
F_6 ( V_147 , V_148 , 0 ) ;
F_10 ( & V_14 , V_13 ) ;
}
void F_56 ( void )
{
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
F_6 ( V_147 , V_149 , 0 ) ;
F_10 ( & V_14 , V_13 ) ;
}
int F_57 ( const unsigned char * V_150 , unsigned V_92 )
{
unsigned int V_5 ;
unsigned long V_13 ;
for ( V_5 = 0 ; V_5 < V_92 ; ) {
switch( V_150 [ V_5 ] ) {
case '\n' :
V_151 [ V_5 + 0 ] = '\r' ;
V_151 [ V_5 + 1 ] = '\n' ;
V_5 += 2 ;
goto V_152;
default:
V_151 [ V_5 ] = V_150 [ V_5 ] ;
V_5 ++ ;
break;
}
}
V_152:
F_9 ( & V_14 , V_13 ) ;
F_58 ( V_153 -> V_154 . V_155 ,
( unsigned long ) V_153 -> V_154 . V_43 , V_156 ,
V_153 -> V_154 . V_157 , F_7 ( V_153 -> V_154 . V_158 . V_159 ) ,
F_7 ( V_160 ) , 0 , F_7 ( V_151 ) , V_5 , 0 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_5 ;
}
int F_59 ( void )
{
int V_161 ;
int V_162 ;
unsigned long V_13 ;
if ( ! V_153 -> V_163 . V_155 )
return 0 ;
F_9 ( & V_14 , V_13 ) ;
F_58 ( V_153 -> V_163 . V_155 ,
( unsigned long ) V_153 -> V_163 . V_43 , V_164 ,
V_153 -> V_163 . V_157 , F_7 ( V_153 -> V_163 . V_158 . V_159 ) ,
F_7 ( V_160 ) , 0 , F_7 ( V_151 ) , 1 , 0 ) ;
V_161 = * V_151 ;
V_162 = * V_160 ;
F_10 ( & V_14 , V_13 ) ;
if ( V_162 == 0 )
return - 1 ;
return V_161 ;
}
int F_60 ( unsigned long V_165 , unsigned long V_13 ,
unsigned long V_166 , unsigned long V_167 ,
unsigned long V_168 )
{
int V_15 ;
unsigned long V_169 ;
F_9 ( & V_14 , V_169 ) ;
V_15 = F_58 ( V_165 , V_13 , V_166 , V_167 , V_168 ) ;
F_10 ( & V_14 , V_169 ) ;
return V_15 ;
}
int F_61 ( struct V_170 * V_171 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_172 , V_173 , F_7 ( V_11 ) ) ;
memcpy ( V_171 , V_11 , sizeof( * V_171 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_62 ( unsigned long * V_42 , unsigned long V_174 , unsigned long V_175 ,
unsigned long V_176 , void * V_177 )
{
int V_15 ;
unsigned long V_13 ;
static struct V_178 T_2 V_179 ( ( F_63 ( 8 ) ) ) ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_172 , V_180 , F_7 ( V_11 ) ,
V_174 , V_175 , V_176 , F_7 ( & T_2 ) ) ;
if( ! V_15 ) {
* V_42 = V_11 [ 0 ] ;
memcpy ( V_177 , & T_2 , * V_42 ) ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_64 ( struct V_181 * V_182 , unsigned long V_43 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_183 , V_184 ,
F_7 ( & V_11 ) , V_43 ) ;
memcpy ( V_182 , V_11 , sizeof( * V_182 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_65 ( unsigned long * V_111 , unsigned long V_185 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_186 , V_187 ,
F_7 ( V_11 ) , V_185 ) ;
* V_111 = V_11 [ 0 ] ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_66 ( void * V_133 , unsigned long V_185 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_186 , V_188 ,
F_7 ( V_133 ) , V_185 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_67 ( unsigned long * V_189 , void * V_177 ,
unsigned long V_92 , unsigned long V_190 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_191 , V_192 , F_7 ( V_11 ) ,
F_7 ( V_23 ) , V_92 , V_190 ) ;
* V_189 = V_11 [ 0 ] ;
memcpy ( V_177 , V_23 , * V_189 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_68 ( unsigned long V_193 , int V_194 , V_3 * V_177 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_186 , V_195 ,
F_7 ( V_11 ) , V_193 , V_194 ) ;
switch( V_194 ) {
case 1 : * ( V_196 * ) V_177 = ( V_196 ) V_11 [ 0 ] ; break;
case 2 : * ( V_197 * ) V_177 = ( V_197 ) V_11 [ 0 ] ; break;
case 4 : * ( V_3 * ) V_177 = ( V_3 ) V_11 [ 0 ] ; break;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_69 ( unsigned long V_193 , int V_194 , V_3 V_198 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_186 , V_199 ,
V_193 , V_194 , V_198 ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_70 ( struct V_200 * V_121 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_201 , V_202 ,
F_7 ( & V_11 ) ) ;
if ( V_15 == V_66 )
memcpy ( V_121 , & V_11 , sizeof( * V_121 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_71 ( struct V_203 * V_121 ,
unsigned long V_204 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_201 , V_205 ,
F_7 ( & V_11 ) , V_204 ) ;
if ( V_15 == V_66 )
memcpy ( V_121 , & V_11 , sizeof( * V_121 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_72 ( struct V_206 * V_125 ,
unsigned long * V_126 , unsigned long V_207 )
{
int V_15 ;
unsigned long V_13 , V_135 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_201 , V_208 ,
F_7 ( & V_11 ) , V_209 ,
F_7 ( V_126 ) ) ;
if ( V_15 == V_66 ) {
V_135 = F_73 ( V_11 [ 0 ] , V_207 ) ;
V_125 -> V_210 = V_135 ;
V_125 -> V_211 = V_135 * sizeof( unsigned long ) ;
}
F_10 ( & V_14 , V_13 ) ;
F_74 ( V_15 == V_66 && V_11 [ 0 ] > V_207 ) ;
return V_15 ;
}
int F_75 ( struct V_206 * V_125 ,
unsigned long * V_126 , unsigned long V_92 ,
unsigned long V_190 )
{
int V_15 ;
unsigned long V_13 , V_135 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_201 , V_212 ,
F_7 ( & V_11 ) , F_7 ( V_126 ) ,
V_92 , V_190 ) ;
if ( V_15 == V_66 ) {
V_135 = F_73 ( V_11 [ 0 ] , V_92 ) ;
V_125 -> V_211 = V_135 ;
V_125 -> V_210 = V_135 / sizeof( unsigned long ) ;
}
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
int F_76 (
struct V_213 * V_125 ,
unsigned long V_214 )
{
int V_15 ;
unsigned long V_13 ;
F_9 ( & V_14 , V_13 ) ;
V_15 = F_6 ( V_201 , V_215 ,
F_7 ( & V_11 ) , V_214 ) ;
if ( V_15 == V_66 )
memcpy ( V_125 , & V_11 , sizeof( * V_125 ) ) ;
F_10 ( & V_14 , V_13 ) ;
return V_15 ;
}
long F_58 ( unsigned long V_216 , ... )
{
T_3 args ;
extern struct V_217 V_218 ;
extern unsigned long V_219 ( unsigned int * ,
unsigned int * ,
unsigned int ) ;
va_start ( args , V_216 ) ;
V_218 . V_220 = va_arg (args, unsigned int) ;
V_218 . V_221 = va_arg (args, unsigned int) ;
V_218 . V_222 = va_arg (args, unsigned int) ;
V_218 . V_223 = va_arg (args, unsigned int) ;
V_218 . V_224 = va_arg (args, unsigned int) ;
V_218 . V_225 = va_arg (args, unsigned int) ;
V_218 . V_226 = va_arg (args, unsigned int) ;
V_218 . V_227 = va_arg (args, unsigned int) ;
V_218 . V_228 = va_arg (args, unsigned int) ;
V_218 . V_229 = va_arg (args, unsigned int) ;
V_218 . V_230 = va_arg (args, unsigned int) ;
V_218 . V_231 = va_arg (args, unsigned int) ;
V_218 . V_232 = va_arg (args, unsigned int) ;
V_218 . V_233 = va_arg (args, unsigned int) ;
va_end ( args ) ;
return V_219 ( & V_218 . V_234 , & V_218 . V_220 , V_216 ) ;
}
long F_77 ( unsigned long V_216 , ... )
{
T_3 args ;
extern struct V_235 V_236 ;
extern unsigned long V_237 ( unsigned long * ,
unsigned long * ,
unsigned long ) ;
va_start ( args , V_216 ) ;
V_236 . V_220 = va_arg (args, unsigned long) ;
V_236 . V_221 = va_arg (args, unsigned long) ;
V_236 . V_222 = va_arg (args, unsigned long) ;
V_236 . V_223 = va_arg (args, unsigned long) ;
V_236 . V_224 = va_arg (args, unsigned long) ;
V_236 . V_225 = va_arg (args, unsigned long) ;
V_236 . V_226 = va_arg (args, unsigned long) ;
V_236 . V_227 = va_arg (args, unsigned long) ;
V_236 . V_228 = va_arg (args, unsigned long) ;
V_236 . V_229 = va_arg (args, unsigned long) ;
V_236 . V_230 = va_arg (args, unsigned long) ;
V_236 . V_231 = va_arg (args, unsigned long) ;
V_236 . V_232 = va_arg (args, unsigned long) ;
V_236 . V_233 = va_arg (args, unsigned long) ;
va_end ( args ) ;
return V_237 ( & V_236 . V_234 , & V_236 . V_220 , V_216 ) ;
}
