static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 ) ;
F_3 () ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
F_6 () ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 () ;
V_4 = F_11 ( V_2 -> V_3 , V_5 , 0 , V_2 -> V_6 , V_2 ) ;
if ( V_4 )
{
F_3 () ;
return V_4 ;
}
F_12 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , char * V_7 , unsigned V_8 )
{
struct V_9 V_10 ;
struct V_9 * V_11 = & V_10 ;
char * V_12 ;
int V_13 ;
V_11 -> V_14 = ( unsigned long ) F_14 ( 0 ) ;
V_11 -> V_15 = ( char * ) F_14 ( ( unsigned long ) V_7 ) ;
V_11 -> V_16 = (struct V_17 * ) ( V_11 -> V_14 + V_18 ) ;
memset ( ( char * ) V_11 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
for( V_13 = 0 ; V_13 < sizeof( struct V_17 ) ; V_13 ++ )
if( ( ( char * ) V_11 -> V_16 ) [ V_13 ] )
return 0 ;
V_11 -> V_16 -> V_19 = V_20 ;
if( V_11 -> V_16 -> V_19 != V_20 )
return 0 ;
V_12 = ( char * ) F_14 ( ( unsigned long ) V_7 ) ;
V_11 -> V_21 = (struct V_22 * ) V_12 ;
memset ( ( char * ) V_11 -> V_21 , 0 , sizeof( struct V_22 ) ) ;
V_11 -> V_16 -> V_21 = F_15 ( V_11 -> V_21 ) ;
V_11 -> V_21 -> V_23 = 1 ;
F_3 () ;
F_16 () ;
F_17 ( 1 ) ;
if( V_11 -> V_21 -> V_23 )
return 0 ;
return 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_18 ( V_2 ) ;
F_3 () ;
F_17 ( 1 ) ;
V_11 -> V_16 = (struct V_17 * ) ( V_11 -> V_14 + V_18 ) ;
V_11 -> V_21 = (struct V_22 * ) F_14 ( V_2 -> V_24 ) ;
V_11 -> V_25 = (struct V_26 * ) ( ( char * ) V_11 -> V_21 + sizeof( struct V_22 ) ) ;
memset ( ( char * ) V_11 -> V_21 , 0 , sizeof( struct V_22 ) ) ;
memset ( ( char * ) V_11 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
V_11 -> V_16 -> V_21 = F_15 ( V_11 -> V_21 ) ;
V_11 -> V_16 -> V_19 = V_20 ;
V_11 -> V_21 -> V_27 = F_19 ( V_11 -> V_25 ) ;
V_11 -> V_21 -> V_28 = F_15 ( F_14 ( V_2 -> V_24 ) ) ;
V_11 -> V_21 -> V_23 = 1 ;
F_3 () ;
F_16 () ;
F_17 ( 1 ) ;
if( V_11 -> V_21 -> V_23 )
F_20 ( L_1 , V_2 -> V_6 ) ;
V_11 -> V_29 = 0 ;
memset ( ( char * ) V_11 -> V_25 , 0 , sizeof( struct V_26 ) ) ;
}
struct V_1 * T_1 F_21 ( int V_30 )
{
struct V_1 * V_2 ;
unsigned long V_31 ;
static int V_32 = 0 ;
int V_33 = - V_34 ;
switch( V_35 -> V_36 ) {
case V_37 | V_38 :
case V_37 | V_39 :
break;
default:
return F_22 ( - V_40 ) ;
}
if ( V_32 )
return F_22 ( - V_40 ) ;
V_31 = ( unsigned long ) F_23 ( V_41 , V_42 ) ;
if ( ! V_31 )
return F_22 ( - V_34 ) ;
V_32 = 1 ;
V_2 = F_24 ( sizeof( struct V_9 ) ) ;
if ( ! V_2 )
goto V_43;
if ( V_30 >= 0 ) {
sprintf ( V_2 -> V_6 , L_2 , V_30 ) ;
F_25 ( V_2 ) ;
}
V_2 -> V_3 = V_44 ;
V_2 -> V_45 = V_31 ;
V_33 = F_26 ( V_2 , V_31 ) ;
if ( V_33 )
goto V_46;
V_33 = F_27 ( V_2 ) ;
if ( V_33 )
goto V_47;
return V_2 ;
V_47:
F_28 ( V_31 , V_42 ) ;
V_46:
F_29 ( V_2 ) ;
V_43:
F_30 ( ( void V_48 * ) V_31 ) ;
return F_22 ( V_33 ) ;
}
static int T_1 F_26 ( struct V_1 * V_2 , int V_31 )
{
int V_13 , V_8 , V_49 ;
if ( ! F_31 ( V_31 , V_42 , V_50 ) )
return - V_51 ;
for( V_13 = 0 ; V_13 < 6 ; V_13 ++ )
V_2 -> V_52 [ V_13 ] = V_35 -> V_53 [ V_13 ] ;
F_20 ( L_3 , V_2 -> V_6 , V_2 -> V_45 ) ;
V_8 = 0x8000 ;
V_2 -> V_24 = ( unsigned long ) F_32 ( 0x8000 , 0x1000 ) ;
V_2 -> V_54 = V_2 -> V_24 + V_8 ;
if( V_8 != 0x2000 && V_8 != 0x4000 && V_8 != 0x8000 ) {
F_20 ( L_4 , V_2 -> V_6 , V_8 ) ;
V_49 = - V_40 ;
goto V_43;
}
if( ! F_13 ( V_2 , ( char * ) V_2 -> V_24 , V_8 ) ) {
F_20 ( L_5 , V_2 -> V_24 , V_8 ) ;
V_49 = - V_40 ;
goto V_43;
}
( (struct V_9 * ) F_18 ( V_2 ) ) -> V_15 =
( char * ) F_14 ( V_2 -> V_24 ) ;
( (struct V_9 * ) F_18 ( V_2 ) ) -> V_14 = ( unsigned long ) F_14 ( 0 ) ;
F_7 ( V_2 ) ;
if( V_8 == 0x2000 )
( (struct V_9 * ) F_18 ( V_2 ) ) -> V_55 =
V_56 ;
else if( V_8 == 0x4000 )
( (struct V_9 * ) F_18 ( V_2 ) ) -> V_55 =
V_57 ;
else
( (struct V_9 * ) F_18 ( V_2 ) ) -> V_55 =
V_58 ;
F_20 ( L_6 , V_2 -> V_24 , V_8 , V_2 -> V_3 ) ;
V_2 -> V_59 = & V_60 ;
V_2 -> V_61 = V_62 / 20 ;
V_2 -> V_63 = 0 ;
return 0 ;
V_43:
F_28 ( V_31 , V_42 ) ;
return V_49 ;
}
static int F_8 ( struct V_1 * V_2 )
{
void * V_64 ;
int V_13 , V_65 = 0 ;
struct V_9 * V_11 = F_18 ( V_2 ) ;
volatile struct V_66 * V_67 ;
volatile struct V_68 * V_69 ;
volatile struct V_70 * V_71 ;
volatile struct V_72 * V_73 ;
struct V_74 * V_75 ;
int V_76 = F_33 ( V_2 ) ;
V_64 = ( void * ) ( ( char * ) V_11 -> V_25 + sizeof( struct V_26 ) ) ;
V_67 = (struct V_66 * ) V_64 ;
V_67 -> V_77 = 0 ;
V_67 -> V_78 = F_34 ( V_79 | V_80 ) ;
V_67 -> V_81 = 0xffff ;
V_67 -> V_82 = 0x0a ;
V_67 -> V_83 = V_83 ;
V_67 -> V_84 = 0x40 ;
V_67 -> V_85 = 0x2e ;
V_67 -> V_86 = 0x00 ;
V_67 -> V_87 = 0x60 ;
V_67 -> V_88 = 0x00 ;
V_67 -> V_89 = 0xf2 ;
V_67 -> V_90 = 0 ;
if( V_2 -> V_91 & V_92 ) {
int V_93 = ( ( char * ) V_11 -> V_21 - ( char * ) V_64 - 8 ) / 6 ;
if( V_76 > V_93 ) {
F_20 ( L_7 , V_2 -> V_6 ) ;
V_67 -> V_90 = 1 ;
}
}
if( V_2 -> V_91 & V_94 )
V_67 -> V_90 = 1 ;
V_67 -> V_95 = 0x00 ;
V_11 -> V_25 -> V_96 = F_19 ( V_67 ) ;
V_11 -> V_25 -> V_97 = 0 ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_35 ( V_67 ) ;
if( ( F_34 ( V_67 -> V_77 ) & ( V_100 | V_101 ) ) != ( V_101 | V_100 ) )
{
F_20 ( L_8 , V_2 -> V_6 , F_34 ( V_67 -> V_77 ) ) ;
return 1 ;
}
V_69 = (struct V_68 * ) V_64 ;
V_69 -> V_77 = 0 ;
V_69 -> V_78 = F_34 ( V_102 | V_80 ) ;
V_69 -> V_81 = 0xffff ;
memcpy ( ( char * ) & V_69 -> V_103 , ( char * ) V_2 -> V_52 , V_104 ) ;
V_11 -> V_25 -> V_96 = F_19 ( V_69 ) ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_35 ( V_69 ) ;
if( ( F_34 ( V_69 -> V_77 ) & ( V_100 | V_101 ) ) != ( V_100 | V_101 ) ) {
F_20 ( L_9 , V_2 -> V_6 , F_34 ( V_69 -> V_77 ) ) ;
return 1 ;
}
V_71 = (struct V_70 * ) V_64 ;
V_71 -> V_77 = 0 ;
V_71 -> V_78 = F_34 ( V_105 | V_80 ) ;
V_71 -> V_81 = 0xffff ;
V_71 -> V_106 = 0 ;
V_11 -> V_25 -> V_96 = F_19 ( V_71 ) ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_35 ( V_71 ) ;
if( ! ( F_34 ( V_71 -> V_77 ) & V_101 ) )
{
F_20 ( L_10 , V_2 -> V_6 ) ;
}
else
{
F_36 () ;
V_65 = F_34 ( V_71 -> V_106 ) ;
V_11 -> V_25 -> V_98 = V_11 -> V_25 -> V_107 & V_108 ;
F_16 () ;
if( V_65 & V_109 )
;
else if( V_65 & V_110 )
F_20 ( L_11 , V_2 -> V_6 ) ;
else if( V_65 & V_111 )
F_20 ( L_12 , V_2 -> V_6 , V_65 & V_112 ) ;
else if( V_65 & V_113 )
{
if ( V_65 & V_112 )
F_20 ( L_13 , V_2 -> V_6 , V_65 & V_112 ) ;
}
else
F_20 ( L_14 , V_2 -> V_6 , V_65 ) ;
}
if( V_76 && ! ( V_2 -> V_91 & V_94 ) )
{
V_73 = (struct V_72 * ) V_64 ;
V_73 -> V_77 = 0 ;
V_73 -> V_78 = F_34 ( V_114 | V_80 ) ;
V_73 -> V_81 = 0xffff ;
V_73 -> V_115 = F_34 ( V_76 * 6 ) ;
V_13 = 0 ;
F_37 (ha, dev)
memcpy ( ( char * ) V_73 -> V_116 [ V_13 ++ ] ,
V_75 -> V_117 , V_104 ) ;
V_11 -> V_25 -> V_96 = F_19 ( V_73 ) ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_35 ( V_73 ) ;
if( ( F_34 ( V_73 -> V_77 ) & ( V_101 | V_100 ) ) != ( V_101 | V_100 ) )
F_20 ( L_15 , V_2 -> V_6 ) ;
}
#if ( V_118 == 1 )
for( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
{
V_11 -> V_119 [ V_13 ] = (struct V_120 * ) V_64 ;
V_11 -> V_119 [ V_13 ] -> V_78 = F_34 ( V_121 ) ;
V_11 -> V_119 [ V_13 ] -> V_77 = 0 ;
V_11 -> V_119 [ V_13 ] -> V_81 = F_19 ( ( V_11 -> V_119 [ V_13 ] ) ) ;
V_64 = ( char * ) V_64 + sizeof( struct V_120 ) ;
}
#else
for( V_13 = 0 ; V_13 < V_118 ; V_13 ++ )
{
V_11 -> V_119 [ V_13 ] = (struct V_120 * ) V_64 ;
V_11 -> V_119 [ V_13 ] -> V_78 = F_34 ( V_121 ) ;
V_11 -> V_119 [ V_13 ] -> V_77 = 0 ;
V_11 -> V_119 [ V_13 ] -> V_81 = F_19 ( ( V_11 -> V_119 [ V_13 ] ) ) ;
V_64 = ( char * ) V_64 + sizeof( struct V_120 ) ;
}
#endif
V_64 = F_38 ( V_2 , ( void * ) V_64 ) ;
for( V_13 = 0 ; V_13 < V_118 ; V_13 ++ )
{
V_11 -> V_122 [ V_13 ] = (struct V_123 * ) V_64 ;
V_64 = ( char * ) V_64 + sizeof( struct V_123 ) ;
V_11 -> V_124 [ V_13 ] = ( char * ) V_64 ;
V_64 = ( char * ) V_64 + V_125 ;
V_11 -> V_126 [ V_13 ] = (struct V_127 * ) V_64 ;
V_64 = ( char * ) V_64 + sizeof( struct V_127 ) ;
if( ( void * ) V_64 > ( void * ) V_2 -> V_54 )
{
F_20 ( L_16 , V_2 -> V_6 ) ;
return 1 ;
}
memset ( ( char * ) ( V_11 -> V_122 [ V_13 ] ) , 0 , sizeof( struct V_123 ) ) ;
memset ( ( char * ) ( V_11 -> V_126 [ V_13 ] ) , 0 , sizeof( struct V_127 ) ) ;
V_11 -> V_122 [ V_13 ] -> V_81 = F_19 ( V_11 -> V_119 [ ( V_13 + 1 ) % V_118 ] ) ;
V_11 -> V_122 [ V_13 ] -> V_77 = F_34 ( V_101 ) ;
V_11 -> V_122 [ V_13 ] -> V_78 = F_34 ( V_128 | V_129 ) ;
V_11 -> V_122 [ V_13 ] -> V_130 = F_19 ( ( V_11 -> V_126 [ V_13 ] ) ) ;
V_11 -> V_126 [ V_13 ] -> V_131 = 0xffff ;
V_11 -> V_126 [ V_13 ] -> V_132 = F_15 ( ( V_11 -> V_124 [ V_13 ] ) ) ;
}
V_11 -> V_133 = 0 ;
V_11 -> V_134 = 0 ;
#ifndef F_39
V_11 -> V_135 = 0 ;
#endif
#ifndef F_39
V_11 -> V_25 -> V_96 = F_19 ( V_11 -> V_119 [ 0 ] ) ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_40 () ;
#else
V_11 -> V_122 [ 0 ] -> V_81 = F_19 ( V_11 -> V_122 [ 0 ] ) ;
V_11 -> V_122 [ 0 ] -> V_78 = F_34 ( V_128 | V_136 | V_129 ) ;
#endif
V_11 -> V_25 -> V_98 = V_11 -> V_25 -> V_107 & V_108 ;
F_16 () ;
F_36 () ;
F_10 () ;
F_41 () ;
return 0 ;
}
static void * F_38 ( struct V_1 * V_2 , void * V_64 )
{
volatile struct V_137 * V_138 = (struct V_137 * ) V_64 ;
volatile struct V_139 * V_140 ;
int V_13 ;
struct V_9 * V_11 = F_18 ( V_2 ) ;
memset ( ( char * ) V_138 , 0 , sizeof( struct V_137 ) * ( V_11 -> V_55 + V_141 ) ) ;
V_11 -> V_142 = V_138 ;
for( V_13 = 0 ; V_13 < ( V_11 -> V_55 + V_141 ) ; V_13 ++ ) {
V_138 [ V_13 ] . V_131 = F_19 ( V_138 + ( V_13 + 1 ) % ( V_11 -> V_55 + V_141 ) ) ;
V_138 [ V_13 ] . V_143 = 0xffff ;
}
V_138 [ V_11 -> V_55 - 1 + V_141 ] . V_144 = V_145 ;
V_64 = ( void * ) ( V_138 + ( V_11 -> V_55 + V_141 ) ) ;
V_140 = (struct V_139 * ) V_64 ;
V_64 = ( void * ) ( V_140 + V_11 -> V_55 ) ;
memset ( ( char * ) V_140 , 0 , sizeof( struct V_139 ) * ( V_11 -> V_55 ) ) ;
for( V_13 = 0 ; V_13 < V_11 -> V_55 ; V_13 ++ )
{
V_140 [ V_13 ] . V_131 = F_19 ( ( V_140 + ( V_13 + 1 ) % V_11 -> V_55 ) ) ;
V_140 [ V_13 ] . V_8 = F_34 ( V_146 ) ;
V_140 [ V_13 ] . V_132 = F_15 ( V_64 ) ;
V_64 = ( char * ) V_64 + V_146 ;
}
V_11 -> V_147 = V_11 -> V_142 ;
V_11 -> V_148 = V_11 -> V_142 + ( V_11 -> V_55 - 1 + V_141 ) ;
V_11 -> V_25 -> V_149 = F_19 ( V_11 -> V_142 ) ;
V_11 -> V_142 -> V_143 = F_19 ( V_140 ) ;
return V_64 ;
}
static T_2 V_5 ( int V_3 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
unsigned short V_151 ;
int V_152 = 0 ;
struct V_9 * V_11 ;
if ( ! V_2 ) {
F_20 ( L_17 , V_3 ) ;
return V_153 ;
}
V_11 = F_18 ( V_2 ) ;
if( V_154 > 1 )
F_20 ( L_18 ) ;
F_40 () ;
while( ( V_151 = V_11 -> V_25 -> V_107 & V_108 ) )
{
V_11 -> V_25 -> V_98 = V_151 ;
F_16 () ;
if( V_151 & V_155 )
F_42 ( V_2 ) ;
if( V_151 & V_156 )
{
F_20 ( L_19 ) ;
if( V_11 -> V_25 -> V_157 & V_158 )
{
F_40 () ;
V_11 -> V_25 -> V_97 = V_159 ;
F_16 () ;
F_43 () ;
}
else
{
F_20 ( L_20 , V_2 -> V_6 , ( int ) V_151 , ( int ) V_11 -> V_25 -> V_157 ) ;
F_44 ( V_2 ) ;
}
}
if( V_151 & V_160 )
F_45 ( V_2 ) ;
#ifndef F_39
if( V_151 & V_161 )
{
if( F_46 ( V_2 ) )
F_20 ( L_21 , V_2 -> V_6 , ( int ) V_151 , ( int ) V_11 -> V_25 -> V_107 ) ;
}
#endif
if( V_154 > 1 )
F_20 ( L_22 , V_152 ++ ) ;
F_40 () ;
if( V_11 -> V_25 -> V_98 )
{
F_20 ( L_23 , V_2 -> V_6 ) ;
F_6 () ;
break;
}
}
if( V_154 > 1 )
F_20 ( L_24 ) ;
return V_162 ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_106 , V_152 = 0 ;
unsigned short V_163 ;
struct V_164 * V_165 ;
struct V_139 * V_140 ;
struct V_9 * V_11 = F_18 ( V_2 ) ;
if( V_154 > 0 )
F_20 ( L_25 ) ;
for(; ( V_106 = V_11 -> V_147 -> V_166 ) & V_167 ; )
{
V_140 = (struct V_139 * ) F_47 ( V_11 -> V_147 -> V_143 ) ;
if( V_106 & V_168 )
{
if( ( V_163 = F_34 ( V_140 -> V_106 ) ) & V_169 )
{
V_163 &= V_170 ;
V_140 -> V_106 = 0 ;
V_165 = F_48 ( V_2 , V_163 + 2 ) ;
if( V_165 != NULL )
{
F_49 ( V_165 , 2 ) ;
F_50 ( V_165 , V_163 ) ;
F_51 ( V_165 , ( char * ) V_11 -> V_14 + F_52 ( ( unsigned long ) V_140 -> V_132 ) , V_163 ) ;
V_165 -> V_171 = F_53 ( V_165 , V_2 ) ;
F_54 ( V_165 ) ;
V_2 -> V_172 . V_173 ++ ;
}
else
V_2 -> V_172 . V_174 ++ ;
}
else
{
int V_175 ;
V_163 = 0 ;
while( ! ( ( V_175 = F_34 ( V_140 -> V_106 ) ) & V_169 ) )
{
V_163 += V_175 & V_170 ;
if( ! V_175 )
{
F_20 ( L_26 , V_2 -> V_6 ) ;
break;
}
V_140 -> V_106 = 0 ;
V_140 = (struct V_139 * ) F_47 ( V_140 -> V_131 ) ;
}
V_163 += V_175 & V_170 ;
V_140 -> V_106 = 0 ;
F_20 ( L_27 , V_2 -> V_6 , V_163 ) ;
V_2 -> V_172 . V_174 ++ ;
}
}
else
{
F_20 ( L_28 , V_2 -> V_6 , V_106 ) ;
V_2 -> V_172 . V_176 ++ ;
}
V_11 -> V_147 -> V_166 = 0 ;
V_11 -> V_147 -> V_144 = V_145 ;
V_11 -> V_147 -> V_143 = 0xffff ;
V_11 -> V_148 -> V_144 = 0 ;
V_11 -> V_148 = V_11 -> V_147 ;
V_11 -> V_147 = (struct V_137 * ) F_47 ( V_11 -> V_147 -> V_131 ) ;
V_11 -> V_25 -> V_149 = F_19 ( V_11 -> V_147 ) ;
if( V_154 > 0 )
F_20 ( L_22 , V_152 ++ ) ;
}
if( V_177 )
{
F_40 () ;
V_11 -> V_25 -> V_97 = V_159 ;
F_16 () ;
F_43 () ;
}
#ifdef F_55
{
int V_13 ;
for( V_13 = 0 ; V_13 < 1024 ; V_13 ++ )
{
if( V_11 -> V_147 -> V_106 )
break;
F_36 () ;
if( V_13 == 1023 )
F_20 ( L_29 , V_2 -> V_6 ) ;
}
}
#endif
#if 0
if(!at_least_one)
{
int i;
volatile struct rfd_struct *rfds=p->rfd_top;
volatile struct rbd_struct *rbds;
printk("%s: received a FC intr. without having a frame: %04x %d\n",dev->name,status,old_at_least);
for(i=0;i< (p->num_recv_buffs+4);i++)
{
rbds = (struct rbd_struct *) make32(rfds->rbd_offset);
printk("%04x:%04x ",rfds->status,rbds->status);
rfds = (struct rfd_struct *) make32(rfds->next);
}
printk("\nerrs: %04x %04x stat: %04x\n",(int)p->scb->rsc_errs,(int)p->scb->ovrn_errs,(int)p->scb->status);
printk("\nerrs: %04x %04x rus: %02x, cus: %02x\n",(int)p->scb->rsc_errs,(int)p->scb->ovrn_errs,(int)p->scb->rus,(int)p->scb->cus);
}
old_at_least = at_least_one;
#endif
if( V_154 > 0 )
F_20 ( L_30 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_18 ( V_2 ) ;
V_2 -> V_172 . V_176 ++ ;
F_40 () ;
V_11 -> V_25 -> V_97 = V_178 ;
F_16 () ;
F_43 () ;
F_38 ( V_2 , ( char * ) V_11 -> V_142 ) ;
F_9 ( V_2 ) ;
F_20 ( L_31 , V_2 -> V_6 , V_11 -> V_25 -> V_157 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_106 ;
struct V_9 * V_11 = F_18 ( V_2 ) ;
if( V_154 > 0 )
F_20 ( L_32 ) ;
V_106 = F_34 ( V_11 -> V_122 [ V_11 -> V_134 ] -> V_77 ) ;
if( ! ( V_106 & V_101 ) )
F_20 ( L_33 , V_2 -> V_6 ) ;
if( V_106 & V_100 )
{
V_2 -> V_172 . V_179 ++ ;
V_2 -> V_172 . V_180 += ( V_106 & V_181 ) ;
}
else
{
V_2 -> V_172 . V_182 ++ ;
if( V_106 & V_183 ) {
F_20 ( L_34 , V_2 -> V_6 ) ;
V_2 -> V_172 . V_180 ++ ;
}
else if( V_106 & V_184 ) {
V_2 -> V_172 . V_185 ++ ;
F_20 ( L_35 , V_2 -> V_6 ) ;
}
else if( V_106 & V_186 )
F_20 ( L_36 , V_2 -> V_6 ) ;
else if( V_106 & V_187 ) {
V_2 -> V_172 . V_188 ++ ;
F_20 ( L_37 , V_2 -> V_6 ) ;
}
else if( V_106 & V_189 ) {
F_20 ( L_38 , V_2 -> V_6 ) ;
V_2 -> V_172 . V_180 += 16 ;
}
}
#if ( V_118 > 1 )
if( ( ++ V_11 -> V_134 ) == V_118 )
V_11 -> V_134 = 0 ;
#endif
F_56 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_18 ( V_2 ) ;
F_40 () ;
F_43 () ;
V_11 -> V_25 -> V_149 = F_19 ( V_11 -> V_142 ) ;
V_11 -> V_25 -> V_97 = V_190 ;
F_16 () ;
F_43 () ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_18 ( V_2 ) ;
#ifndef F_39
if( V_11 -> V_25 -> V_107 & V_191 )
{
F_56 ( V_2 ) ;
#ifdef F_58
F_20 ( L_39 , V_2 -> V_6 ) ;
F_20 ( L_40 , V_2 -> V_6 , ( int ) F_34 ( V_11 -> V_122 [ 0 ] -> V_77 ) , ( int ) F_34 ( V_11 -> V_119 [ 0 ] -> V_77 ) , ( int ) F_34 ( V_11 -> V_119 [ 1 ] -> V_77 ) , ( int ) V_11 -> V_135 ) ;
#endif
V_11 -> V_25 -> V_98 = V_192 ;
F_16 () ;
F_40 () ;
V_11 -> V_25 -> V_96 = F_19 ( V_11 -> V_119 [ V_11 -> V_135 ] ) ;
V_11 -> V_25 -> V_98 = V_99 ;
F_16 () ;
F_40 () ;
V_2 -> V_193 = V_194 ;
return 0 ;
}
#endif
{
#ifdef F_58
F_20 ( L_41 , V_2 -> V_6 , V_11 -> V_25 -> V_107 ) ;
F_20 ( L_42 , V_2 -> V_6 , F_34 ( V_11 -> V_122 [ 0 ] -> V_77 ) , F_34 ( V_11 -> V_122 [ 1 ] -> V_77 ) ) ;
F_20 ( L_43 , V_2 -> V_6 ) ;
#endif
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
V_2 -> V_193 = V_194 ;
}
static int F_59 ( struct V_164 * V_165 , struct V_1 * V_2 )
{
int V_93 , V_13 ;
#ifndef F_39
int V_195 ;
#endif
struct V_9 * V_11 = F_18 ( V_2 ) ;
if( V_165 -> V_93 > V_125 )
{
F_20 ( L_44 , V_2 -> V_6 , V_125 , V_165 -> V_93 ) ;
return V_196 ;
}
F_4 ( V_2 ) ;
#if ( V_118 > 1 )
if( F_60 ( 0 , ( void * ) & V_11 -> V_197 ) ) {
F_20 ( L_45 , V_2 -> V_6 ) ;
return V_198 ;
}
else
#endif
{
V_93 = V_165 -> V_93 ;
if ( V_93 < V_199 ) {
memset ( ( void * ) V_11 -> V_124 [ V_11 -> V_133 ] , 0 ,
V_199 ) ;
V_93 = V_199 ;
}
F_61 ( V_165 , ( void * ) V_11 -> V_124 [ V_11 -> V_133 ] , V_165 -> V_93 ) ;
#if ( V_118 == 1 )
# ifdef F_39
#ifdef F_58
if( V_11 -> V_25 -> V_107 & V_191 )
{
F_20 ( L_46 , V_2 -> V_6 ) ;
F_20 ( L_47 , V_2 -> V_6 , V_11 -> V_25 -> V_107 , F_34 ( V_11 -> V_122 [ 0 ] -> V_77 ) ) ;
}
#endif
V_11 -> V_126 [ 0 ] -> V_8 = F_34 ( V_200 | V_93 ) ;
for( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
{
V_11 -> V_122 [ 0 ] -> V_77 = 0 ;
F_40 () ;
if( ( V_11 -> V_25 -> V_107 & V_201 ) == V_202 )
V_11 -> V_25 -> V_98 = V_203 ;
else
{
V_11 -> V_25 -> V_96 = F_19 ( V_11 -> V_122 [ 0 ] ) ;
V_11 -> V_25 -> V_98 = V_99 ;
}
F_16 () ;
if( ! V_13 )
F_62 ( V_165 ) ;
F_40 () ;
if( ( V_11 -> V_25 -> V_107 & V_191 ) )
break;
if( V_11 -> V_122 [ 0 ] -> V_77 )
break;
if( V_13 == 15 )
F_20 ( L_48 , V_2 -> V_6 ) ;
}
# else
V_195 = ( V_11 -> V_135 + 1 ) & 0x1 ;
V_11 -> V_126 [ 0 ] -> V_8 = F_34 ( V_200 | V_93 ) ;
V_11 -> V_122 [ 0 ] -> V_81 = V_11 -> V_119 [ V_195 ] -> V_81
= F_19 ( ( V_11 -> V_119 [ V_195 ] ) ) ;
V_11 -> V_122 [ 0 ] -> V_77 = V_11 -> V_119 [ V_195 ] -> V_77 = 0 ;
V_11 -> V_119 [ V_11 -> V_135 ] -> V_81 = F_19 ( ( V_11 -> V_122 [ 0 ] ) ) ;
V_11 -> V_135 = V_195 ;
F_62 ( V_165 ) ;
# endif
#else
V_11 -> V_126 [ V_11 -> V_133 ] -> V_8 = F_34 ( V_200 | V_93 ) ;
if( ( V_195 = V_11 -> V_133 + 1 ) == V_118 )
V_195 = 0 ;
V_11 -> V_122 [ V_11 -> V_133 ] -> V_77 = 0 ;
V_11 -> V_119 [ V_195 ] -> V_81 = F_19 ( ( V_11 -> V_119 [ V_195 ] ) ) ;
V_11 -> V_119 [ V_195 ] -> V_77 = 0 ;
V_11 -> V_119 [ V_11 -> V_133 ] -> V_81 = F_19 ( ( V_11 -> V_122 [ V_11 -> V_133 ] ) ) ;
V_11 -> V_133 = V_195 ;
{
unsigned long V_91 ;
F_63 ( V_91 ) ;
if( V_11 -> V_133 != V_11 -> V_134 )
F_56 ( V_2 ) ;
V_11 -> V_197 = 0 ;
F_64 ( V_91 ) ;
}
F_62 ( V_165 ) ;
#endif
}
return V_196 ;
}
static struct V_204 * F_65 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_18 ( V_2 ) ;
unsigned short V_205 , V_206 , V_207 , V_208 ;
V_205 = F_34 ( V_11 -> V_25 -> V_209 ) ;
V_11 -> V_25 -> V_209 = 0 ;
V_206 = F_34 ( V_11 -> V_25 -> V_210 ) ;
V_11 -> V_25 -> V_210 = 0 ;
V_207 = F_34 ( V_11 -> V_25 -> V_211 ) ;
V_11 -> V_25 -> V_211 = 0 ;
V_208 = F_34 ( V_11 -> V_25 -> V_212 ) ;
V_11 -> V_25 -> V_212 = 0 ;
V_2 -> V_172 . V_213 += V_205 ;
V_2 -> V_172 . V_214 += V_208 ;
V_2 -> V_172 . V_215 += V_206 ;
V_2 -> V_172 . V_174 += V_207 ;
return & V_2 -> V_172 ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_6 () ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 () ;
F_56 ( V_2 ) ;
}
