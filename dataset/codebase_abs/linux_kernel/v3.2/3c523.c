static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_3 | 0x3 | V_4 | V_2 , V_1 + V_5 ) ;
F_3 () ;
F_2 ( V_3 | 0x3 | V_2 , V_1 + V_5 ) ;
}
static void F_4 ( int V_1 , int V_2 )
{
F_2 ( 0x3 | V_6 , V_1 + V_5 ) ;
F_3 () ;
F_2 ( V_3 | V_6 | 0x3 , V_1 + V_5 ) ;
F_1 ( V_1 , V_2 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 ) ;
F_7 () ;
F_8 ( V_8 -> V_9 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
int V_10 ;
F_10 () ;
V_10 = F_11 ( V_8 -> V_9 , V_11 , V_12 ,
V_8 -> V_13 , V_8 ) ;
if ( V_10 ) {
F_12 ( L_1 , V_8 -> V_13 , V_8 -> V_9 ) ;
F_7 () ;
return V_10 ;
}
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_7 * V_8 , unsigned long V_14 , unsigned V_15 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
char * V_18 [ 2 ] ;
int V_19 = 0 ;
V_17 -> V_20 = ( unsigned long ) F_19 ( ( unsigned long ) V_14 ) + V_15 - 0x01000000 ;
V_17 -> V_21 = F_19 ( ( unsigned long ) V_14 ) + V_15 ;
V_17 -> V_22 = (struct V_23 * ) ( V_17 -> V_20 + V_24 ) ;
memset ( ( char * ) V_17 -> V_22 , 0 , sizeof( struct V_23 ) ) ;
V_17 -> V_22 -> V_25 = V_26 ;
V_18 [ 0 ] = F_19 ( ( unsigned long ) V_14 ) ;
V_18 [ 1 ] = ( char * ) V_17 -> V_22 - sizeof( struct V_27 ) ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_17 -> V_28 = (struct V_27 * ) V_18 [ V_19 ] ;
memset ( ( char * ) V_17 -> V_28 , 0 , sizeof( struct V_27 ) ) ;
V_17 -> V_22 -> V_28 = F_20 ( V_17 -> V_28 ) ;
V_17 -> V_28 -> V_29 = 1 ;
F_7 () ;
F_10 () ;
F_21 ( 1 ) ;
if ( V_17 -> V_28 -> V_29 ) {
return 0 ;
}
}
return 1 ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
F_7 () ;
F_21 ( 2 ) ;
V_17 -> V_22 = (struct V_23 * ) ( V_17 -> V_20 + V_24 ) ;
V_17 -> V_30 = (struct V_31 * ) F_19 ( V_8 -> V_32 ) ;
V_17 -> V_28 = (struct V_27 * ) ( ( char * ) V_17 -> V_22 - sizeof( struct V_27 ) ) ;
memset ( ( char * ) V_17 -> V_28 , 0 , sizeof( struct V_27 ) ) ;
memset ( ( char * ) V_17 -> V_22 , 0 , sizeof( struct V_23 ) ) ;
V_17 -> V_22 -> V_28 = F_20 ( V_17 -> V_28 ) ;
V_17 -> V_22 -> V_25 = V_26 ;
V_17 -> V_28 -> V_33 = F_22 ( V_17 -> V_30 ) ;
V_17 -> V_28 -> V_29 = 1 ;
F_7 () ;
F_10 () ;
F_21 ( 2 ) ;
if ( V_17 -> V_28 -> V_29 )
F_12 ( L_2 , V_8 -> V_13 ) ;
memset ( ( char * ) V_17 -> V_30 , 0 , sizeof( struct V_31 ) ) ;
}
static int F_23 ( char * V_34 , int V_35 , void * V_36 )
{
int V_37 = 0 ;
struct V_7 * V_8 = V_36 ;
if ( V_8 == NULL )
return V_37 ;
V_37 += sprintf ( V_34 + V_37 , L_3 ,
F_24 ( V_8 -> V_38 + V_39 ) & 0xf ) ;
V_37 += sprintf ( V_34 + V_37 , L_4 , V_8 -> V_9 ) ;
V_37 += sprintf ( V_34 + V_37 , L_5 , V_8 -> V_38 ,
V_8 -> V_38 + V_40 ) ;
V_37 += sprintf ( V_34 + V_37 , L_6 , V_8 -> V_32 ,
V_8 -> V_41 - 1 ) ;
V_37 += sprintf ( V_34 + V_37 , L_7 , V_8 -> V_42 ?
L_8 : L_9 ) ;
V_37 += sprintf ( V_34 + V_37 , L_10 , V_8 -> V_13 ) ;
V_37 += sprintf ( V_34 + V_37 , L_11 ,
V_8 -> V_43 ) ;
return V_37 ;
}
static int T_1 F_25 ( struct V_7 * V_8 )
{
static int V_35 ;
int V_38 = V_8 -> V_38 ;
int V_9 = V_8 -> V_9 ;
T_2 V_44 = 0 ;
T_2 V_45 = 0 ;
int V_19 = 0 ;
unsigned int V_15 = 0 ;
int V_46 ;
struct V_16 * V_47 = F_18 ( V_8 ) ;
if ( V_48 == 0 ) {
return - V_49 ;
}
V_35 = F_26 ( V_50 , 0 ) ;
while ( V_35 != - 1 ) {
V_44 = F_27 ( V_35 , 2 ) ;
V_8 -> V_9 = V_51 [ ( V_44 & V_52 ) >> 6 ] ;
V_8 -> V_38 = V_53 [ ( V_44 & V_54 ) >> 1 ] ;
if ( ( V_9 && V_9 != V_8 -> V_9 ) ||
( V_38 && V_38 != V_8 -> V_38 ) ) {
V_35 = F_26 ( V_50 , V_35 + 1 ) ;
continue;
}
if ( ! F_28 ( V_8 -> V_38 , V_40 , V_55 ) ) {
V_35 = F_26 ( V_50 , V_35 + 1 ) ;
continue;
}
break;
}
if ( V_35 == V_56 )
return ( V_38 || V_9 ) ? - V_57 : - V_49 ;
F_29 ( V_35 , L_12 ) ;
F_30 ( V_35 , ( V_58 ) F_23 , V_8 ) ;
F_31 ( L_13 , V_8 -> V_13 , V_35 + 1 ) ;
V_45 = F_24 ( V_8 -> V_38 + V_39 ) & 0xf ;
switch ( V_8 -> V_9 ) {
case 3 :
F_32 ( V_35 , 3 , 0x04 ) ;
break;
case 7 :
F_32 ( V_35 , 3 , 0x02 ) ;
break;
case 9 :
F_32 ( V_35 , 3 , 0x08 ) ;
break;
case 12 :
F_32 ( V_35 , 3 , 0x01 ) ;
break;
}
V_47 -> V_35 = V_35 ;
F_31 ( L_14 , V_8 -> V_13 , ( int ) V_45 ,
V_8 -> V_38 ) ;
V_8 -> V_42 = ( V_44 & V_59 ) ;
V_8 -> V_32 = V_60 [ ( V_44 & V_61 ) >> 3 ] ;
F_7 () ;
V_15 = 0x4000 ;
if ( ! F_17 ( V_8 , V_8 -> V_32 , V_15 ) ) {
F_12 ( L_15 , V_8 -> V_13 ,
V_8 -> V_32 ) ;
V_46 = - V_49 ;
goto V_62;
}
V_8 -> V_41 = V_8 -> V_32 + V_15 ;
V_47 -> V_21 = F_19 ( V_8 -> V_32 ) + V_15 ;
V_47 -> V_20 = ( unsigned long ) F_19 ( V_8 -> V_32 ) + V_15 - 0x01000000 ;
F_13 ( V_8 ) ;
F_7 () ;
V_47 -> V_63 = V_64 ;
F_31 ( L_16 , V_8 -> V_13 ,
V_8 -> V_9 , V_8 -> V_42 ? L_17 : L_18 ,
V_8 -> V_32 , V_8 -> V_41 - 1 ) ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_8 -> V_43 [ V_19 ] = F_24 ( V_8 -> V_38 + V_19 ) ;
F_31 ( L_19 ,
V_8 -> V_13 , V_8 -> V_43 ) ;
V_8 -> V_65 = & V_65 ;
V_8 -> V_66 = V_67 ;
V_8 -> V_68 = & V_69 ;
#ifndef F_33
V_8 -> V_70 &= ~ V_71 ;
#endif
V_46 = F_34 ( V_8 ) ;
if ( V_46 )
goto V_62;
return 0 ;
V_62:
F_30 ( V_35 , NULL , NULL ) ;
F_35 ( V_8 -> V_38 , V_40 ) ;
return V_46 ;
}
static void F_36 ( struct V_7 * V_8 )
{
F_30 ( ( (struct V_16 * ) F_18 ( V_8 ) ) -> V_35 ,
NULL , NULL ) ;
F_35 ( V_8 -> V_38 , V_40 ) ;
}
struct V_7 * T_1 F_37 ( int V_72 )
{
struct V_7 * V_8 = F_38 ( sizeof( struct V_16 ) ) ;
int V_73 ;
if ( ! V_8 )
return F_39 ( - V_74 ) ;
sprintf ( V_8 -> V_13 , L_20 , V_72 ) ;
F_40 ( V_8 ) ;
V_73 = F_25 ( V_8 ) ;
if ( V_73 )
goto V_75;
return V_8 ;
V_75:
F_41 ( V_8 ) ;
return F_39 ( V_73 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
void * V_76 ;
unsigned long V_77 ;
int V_19 , V_78 = 0 ;
struct V_16 * V_17 = F_18 ( V_8 ) ;
volatile struct V_79 * V_80 ;
volatile struct V_81 * V_82 ;
volatile struct V_83 * V_84 ;
volatile struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_89 = F_42 ( V_8 ) ;
V_76 = ( void * ) ( ( char * ) V_17 -> V_30 + sizeof( struct V_31 ) ) ;
V_80 = (struct V_79 * ) V_76 ;
V_80 -> V_90 = 0 ;
V_80 -> V_91 = V_92 | V_93 ;
V_80 -> V_94 = 0xffff ;
V_80 -> V_95 = 0x0a ;
V_80 -> V_96 = 0x08 ;
V_80 -> V_97 = 0x40 ;
V_80 -> V_98 = 0x2e ;
V_80 -> V_99 = 0x00 ;
V_80 -> V_100 = 0x60 ;
V_80 -> V_101 = 0x00 ;
V_80 -> V_102 = 0xf2 ;
V_80 -> V_103 = 0 ;
if ( V_8 -> V_70 & ( V_104 | V_105 ) )
V_80 -> V_103 = 1 ;
V_80 -> V_106 = 0x00 ;
V_17 -> V_30 -> V_107 = F_22 ( V_80 ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_10 () ;
V_77 = V_110 ;
while ( ! ( V_80 -> V_90 & V_111 ) ) {
if ( F_43 ( V_110 , V_77 + 30 * V_67 / 100 ) )
break;
}
if ( ( V_80 -> V_90 & ( V_112 | V_111 ) ) != ( V_111 | V_112 ) ) {
F_44 ( L_21 , V_8 -> V_13 , V_80 -> V_90 ) ;
return 1 ;
}
V_82 = (struct V_81 * ) V_76 ;
V_82 -> V_90 = 0 ;
V_82 -> V_91 = V_113 | V_93 ;
V_82 -> V_94 = 0xffff ;
memcpy ( ( char * ) & V_82 -> V_114 , ( char * ) V_8 -> V_43 , V_115 ) ;
V_17 -> V_30 -> V_107 = F_22 ( V_82 ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_10 () ;
V_77 = V_110 ;
while ( ! ( V_82 -> V_90 & V_111 ) ) {
if ( F_43 ( V_110 , V_77 + 30 * V_67 / 100 ) )
break;
}
if ( ( V_82 -> V_90 & ( V_112 | V_111 ) ) != ( V_112 | V_111 ) ) {
F_44 ( L_22 ,
V_8 -> V_13 , V_82 -> V_90 ) ;
return 1 ;
}
V_84 = (struct V_83 * ) V_76 ;
V_84 -> V_90 = 0 ;
V_84 -> V_91 = V_116 | V_93 ;
V_84 -> V_94 = 0xffff ;
V_84 -> V_44 = 0 ;
V_17 -> V_30 -> V_107 = F_22 ( V_84 ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_45 () ;
V_77 = V_110 ;
while ( ! ( V_84 -> V_90 & V_111 ) ) {
if ( F_43 ( V_110 , V_77 + 30 * V_67 / 100 ) ) {
F_44 ( L_23 , V_8 -> V_13 , __LINE__ ) ;
V_78 = 1 ;
break;
}
}
if ( ! V_78 ) {
F_21 ( 2 ) ;
V_78 = V_84 -> V_44 ;
V_17 -> V_30 -> V_108 = V_17 -> V_30 -> V_44 & V_117 ;
F_10 () ;
if ( V_78 & V_118 ) {
} else if ( V_78 & V_119 ) {
F_44 ( L_24 , V_8 -> V_13 ) ;
} else if ( V_78 & V_120 ) {
F_44 ( L_25 , V_8 -> V_13 , V_78 & V_121 ) ;
} else if ( V_78 & V_122 ) {
if ( V_78 & V_121 )
F_44 ( L_26 , V_8 -> V_13 , V_78 & V_121 ) ;
} else {
F_44 ( L_27 , V_8 -> V_13 , V_78 ) ;
}
}
V_17 -> V_30 -> V_108 = V_17 -> V_30 -> V_44 & V_117 ;
F_10 () ;
#if ( V_123 == 1 )
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_17 -> V_124 [ V_19 ] = (struct V_125 * ) V_76 ;
V_17 -> V_124 [ V_19 ] -> V_91 = V_126 ;
V_17 -> V_124 [ V_19 ] -> V_90 = 0 ;
V_17 -> V_124 [ V_19 ] -> V_94 = F_22 ( ( V_17 -> V_124 [ V_19 ] ) ) ;
V_76 = ( char * ) V_76 + sizeof( struct V_125 ) ;
}
V_17 -> V_127 [ 0 ] = (struct V_128 * ) V_76 ;
V_76 = ( char * ) V_76 + sizeof( struct V_128 ) ;
#else
for ( V_19 = 0 ; V_19 < V_123 ; V_19 ++ ) {
V_17 -> V_124 [ V_19 ] = (struct V_125 * ) V_76 ;
V_17 -> V_124 [ V_19 ] -> V_91 = V_126 ;
V_17 -> V_124 [ V_19 ] -> V_90 = 0 ;
V_17 -> V_124 [ V_19 ] -> V_94 = F_22 ( ( V_17 -> V_124 [ V_19 ] ) ) ;
V_76 = ( char * ) V_76 + sizeof( struct V_125 ) ;
V_17 -> V_127 [ V_19 ] = (struct V_128 * ) V_76 ;
V_76 = ( char * ) V_76 + sizeof( struct V_128 ) ;
}
#endif
V_76 = F_46 ( V_8 , ( void * ) V_76 ) ;
if ( V_89 ) {
int V_37 = ( ( char * ) V_17 -> V_28 - ( char * ) V_76 - 8 ) / 6 ;
if ( V_37 <= 0 ) {
F_12 ( L_28 , V_8 -> V_13 ) ;
} else {
if ( V_37 < V_89 ) {
V_89 = V_37 ;
F_44 ( L_29 ,
V_8 -> V_13 , V_89 ) ;
}
V_86 = (struct V_85 * ) V_76 ;
V_86 -> V_90 = 0 ;
V_86 -> V_91 = V_129 | V_93 ;
V_86 -> V_94 = 0xffff ;
V_86 -> V_130 = V_89 * 6 ;
V_19 = 0 ;
F_47 (ha, dev)
memcpy ( ( char * ) V_86 -> V_131 [ V_19 ++ ] ,
V_88 -> V_132 , 6 ) ;
V_17 -> V_30 -> V_107 = F_22 ( V_86 ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_10 () ;
V_77 = V_110 ;
while ( ! ( V_86 -> V_90 & V_111 ) ) {
if ( F_43 ( V_110 , V_77 + 30 * V_67 / 100 ) )
break;
}
if ( ! ( V_86 -> V_90 & V_111 ) ) {
F_44 ( L_30 , V_8 -> V_13 ) ;
}
}
}
for ( V_19 = 0 ; V_19 < V_123 ; V_19 ++ ) {
V_17 -> V_133 [ V_19 ] = ( char * ) V_76 ;
V_76 = ( char * ) V_76 + V_134 ;
V_17 -> V_135 [ V_19 ] = (struct V_136 * ) V_76 ;
V_76 = ( char * ) V_76 + sizeof( struct V_136 ) ;
if ( ( void * ) V_76 > ( void * ) V_17 -> V_28 ) {
F_12 ( L_31 , V_8 -> V_13 ) ;
return 1 ;
}
memset ( ( char * ) ( V_17 -> V_127 [ V_19 ] ) , 0 , sizeof( struct V_128 ) ) ;
memset ( ( char * ) ( V_17 -> V_135 [ V_19 ] ) , 0 , sizeof( struct V_136 ) ) ;
V_17 -> V_127 [ V_19 ] -> V_90 = V_111 ;
V_17 -> V_127 [ V_19 ] -> V_91 = V_137 | V_138 ;
V_17 -> V_127 [ V_19 ] -> V_139 = F_22 ( ( V_17 -> V_135 [ V_19 ] ) ) ;
V_17 -> V_135 [ V_19 ] -> V_140 = 0xffff ;
V_17 -> V_135 [ V_19 ] -> V_141 = F_20 ( ( V_17 -> V_133 [ V_19 ] ) ) ;
}
V_17 -> V_142 = 0 ;
V_17 -> V_143 = 0 ;
#ifndef F_48
V_17 -> V_144 = 0 ;
#endif
#ifndef F_48
V_17 -> V_30 -> V_107 = F_22 ( V_17 -> V_124 [ 0 ] ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_10 () ;
F_49 () ;
#else
V_17 -> V_127 [ 0 ] -> V_94 = 0xffff ;
V_17 -> V_127 [ 0 ] -> V_91 = V_137 | V_93 | V_138 ;
#endif
return 0 ;
}
static void * F_46 ( struct V_7 * V_8 , void * V_76 )
{
volatile struct V_145 * V_146 = (struct V_145 * ) V_76 ;
volatile struct V_147 * V_148 ;
int V_19 ;
struct V_16 * V_17 = F_18 ( V_8 ) ;
memset ( ( char * ) V_146 , 0 , sizeof( struct V_145 ) * V_17 -> V_63 ) ;
V_17 -> V_149 = V_146 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_63 ; V_19 ++ ) {
V_146 [ V_19 ] . V_140 = F_22 ( V_146 + ( V_19 + 1 ) % V_17 -> V_63 ) ;
}
V_146 [ V_17 -> V_63 - 1 ] . V_150 = V_151 ;
V_76 = ( void * ) ( V_146 + V_17 -> V_63 ) ;
V_148 = (struct V_147 * ) V_76 ;
V_76 = ( void * ) ( V_148 + V_17 -> V_63 ) ;
memset ( ( char * ) V_148 , 0 , sizeof( struct V_147 ) * V_17 -> V_63 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_63 ; V_19 ++ ) {
V_148 [ V_19 ] . V_140 = F_22 ( ( V_148 + ( V_19 + 1 ) % V_17 -> V_63 ) ) ;
V_148 [ V_19 ] . V_15 = V_152 ;
V_148 [ V_19 ] . V_141 = F_20 ( V_76 ) ;
V_76 = ( char * ) V_76 + V_152 ;
}
V_17 -> V_153 = V_17 -> V_149 ;
V_17 -> V_154 = V_17 -> V_149 + V_17 -> V_63 - 1 ;
V_17 -> V_30 -> V_155 = F_22 ( V_17 -> V_149 ) ;
V_17 -> V_149 -> V_156 = F_22 ( V_148 ) ;
return V_76 ;
}
static T_3
V_11 ( int V_9 , void * V_157 )
{
struct V_7 * V_8 = V_157 ;
unsigned short V_158 ;
struct V_16 * V_17 ;
if ( ! F_50 ( V_8 ) ) {
F_10 () ;
return V_159 ;
} else if ( ! ( V_160 & F_24 ( V_8 -> V_38 + V_5 ) ) ) {
return V_161 ;
}
V_17 = F_18 ( V_8 ) ;
while ( ( V_158 = V_17 -> V_30 -> V_44 & V_117 ) )
{
V_17 -> V_30 -> V_108 = V_158 ;
F_45 () ;
if ( V_158 & V_162 ) {
F_51 ( V_8 ) ;
}
if ( V_158 & V_163 ) {
F_52 ( V_8 ) ;
}
#ifndef F_48
if ( V_158 & V_164 ) {
if ( F_50 ( V_8 ) ) {
F_44 ( L_32 ,
V_8 -> V_13 , ( int ) V_158 , ( int ) V_17 -> V_30 -> V_44 ) ;
}
}
#endif
if ( V_158 & V_165 ) {
if ( V_17 -> V_30 -> V_44 & V_166 ) {
F_49 () ;
V_17 -> V_30 -> V_108 = V_167 ;
F_45 () ;
} else {
F_44 ( L_33 ,
V_8 -> V_13 , ( int ) V_158 , ( int ) V_17 -> V_30 -> V_44 ) ;
F_53 ( V_8 ) ;
}
}
F_49 () ;
if ( V_17 -> V_30 -> V_108 ) {
break;
}
}
return V_159 ;
}
static void F_52 ( struct V_7 * V_8 )
{
int V_44 ;
unsigned short V_168 ;
struct V_169 * V_170 ;
struct V_147 * V_148 ;
struct V_16 * V_17 = F_18 ( V_8 ) ;
for (; ( V_44 = V_17 -> V_153 -> V_44 ) & V_111 ; ) {
V_148 = (struct V_147 * ) F_54 ( V_17 -> V_153 -> V_156 ) ;
if ( V_44 & V_112 ) {
if ( ( V_168 = V_148 -> V_44 ) & V_171 ) {
V_168 &= V_172 ;
V_148 -> V_44 = 0 ;
V_170 = (struct V_169 * ) F_55 ( V_168 + 2 ) ;
if ( V_170 != NULL ) {
F_56 ( V_170 , 2 ) ;
F_57 ( V_170 , V_168 ) ;
F_58 ( V_170 , ( char * ) V_17 -> V_20 + ( unsigned long ) V_148 -> V_141 , V_168 ) ;
V_170 -> V_173 = F_59 ( V_170 , V_8 ) ;
F_60 ( V_170 ) ;
V_8 -> V_174 . V_175 ++ ;
V_8 -> V_174 . V_176 += V_168 ;
} else {
V_8 -> V_174 . V_177 ++ ;
}
} else {
F_44 ( L_34 , V_8 -> V_13 ) ;
V_8 -> V_174 . V_177 ++ ;
}
} else {
F_44 ( L_35 , V_8 -> V_13 , V_44 ) ;
V_8 -> V_174 . V_178 ++ ;
}
V_17 -> V_153 -> V_44 = 0 ;
V_17 -> V_153 -> V_150 = V_151 ;
V_17 -> V_154 -> V_150 = 0 ;
V_17 -> V_154 = V_17 -> V_153 ;
V_17 -> V_153 = (struct V_145 * ) F_54 ( V_17 -> V_153 -> V_140 ) ;
}
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
V_8 -> V_174 . V_178 ++ ;
F_49 () ;
V_17 -> V_30 -> V_108 = V_179 ;
F_45 () ;
F_49 () ;
F_46 ( V_8 , ( char * ) V_17 -> V_149 ) ;
F_15 ( V_8 ) ;
F_44 ( L_36 , V_8 -> V_13 , V_17 -> V_30 -> V_44 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
int V_44 ;
struct V_16 * V_17 = F_18 ( V_8 ) ;
V_44 = V_17 -> V_127 [ V_17 -> V_143 ] -> V_90 ;
if ( ! ( V_44 & V_111 ) ) {
F_44 ( L_37 , V_8 -> V_13 ) ;
}
if ( V_44 & V_112 ) {
V_8 -> V_174 . V_180 ++ ;
V_8 -> V_174 . V_181 += ( V_44 & V_182 ) ;
} else {
V_8 -> V_174 . V_183 ++ ;
if ( V_44 & V_184 ) {
F_44 ( L_38 , V_8 -> V_13 ) ;
V_8 -> V_174 . V_181 ++ ;
} else if ( V_44 & V_185 ) {
V_8 -> V_174 . V_186 ++ ;
F_44 ( L_39 , V_8 -> V_13 ) ;
} else if ( V_44 & V_187 ) {
F_44 ( L_40 , V_8 -> V_13 ) ;
} else if ( V_44 & V_188 ) {
V_8 -> V_174 . V_189 ++ ;
F_44 ( L_41 , V_8 -> V_13 ) ;
} else if ( V_44 & V_190 ) {
F_44 ( L_42 , V_8 -> V_13 ) ;
V_8 -> V_174 . V_181 += 16 ;
}
}
#if ( V_123 != 1 )
if ( ( ++ V_17 -> V_143 ) == V_123 ) {
V_17 -> V_143 = 0 ;
}
#endif
F_61 ( V_8 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
V_17 -> V_30 -> V_155 = F_22 ( V_17 -> V_149 ) ;
V_17 -> V_30 -> V_108 = V_191 ;
F_45 () ;
F_49 () ;
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
if ( V_17 -> V_30 -> V_44 & V_192 ) {
F_63 ( L_43 , V_8 -> V_13 ) ;
F_63 ( L_44 , V_8 -> V_13 ,
( int ) V_17 -> V_127 [ 0 ] -> V_90 ,
( int ) V_17 -> V_124 [ 0 ] -> V_90 ,
( int ) V_17 -> V_124 [ 1 ] -> V_90 , ( int ) V_17 -> V_144 ) ;
V_17 -> V_30 -> V_108 = V_193 ;
F_45 () ;
F_49 () ;
V_17 -> V_30 -> V_107 = F_22 ( V_17 -> V_124 [ V_17 -> V_144 ] ) ;
V_17 -> V_30 -> V_108 = V_109 ;
F_45 () ;
F_49 () ;
F_61 ( V_8 ) ;
} else {
F_63 ( L_45 ,
V_8 -> V_13 , V_17 -> V_30 -> V_44 ) ;
F_63 ( L_46 , V_8 -> V_13 ,
V_17 -> V_127 [ 0 ] -> V_90 , V_17 -> V_127 [ 1 ] -> V_90 ) ;
F_5 ( V_8 ) ;
F_9 ( V_8 ) ;
}
}
static T_4 F_64 ( struct V_169 * V_170 , struct V_7 * V_8 )
{
int V_37 ;
int V_19 ;
#ifndef F_48
int V_194 ;
#endif
struct V_16 * V_17 = F_18 ( V_8 ) ;
F_6 ( V_8 ) ;
V_37 = ( V_195 < V_170 -> V_37 ) ? V_170 -> V_37 : V_195 ;
if ( V_37 != V_170 -> V_37 )
memset ( ( char * ) V_17 -> V_133 [ V_17 -> V_142 ] , 0 , V_195 ) ;
F_65 ( V_170 , ( char * ) V_17 -> V_133 [ V_17 -> V_142 ] , V_170 -> V_37 ) ;
#if ( V_123 == 1 )
#ifdef F_48
V_17 -> V_135 [ 0 ] -> V_15 = V_196 | V_37 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_17 -> V_30 -> V_107 = F_22 ( V_17 -> V_127 [ 0 ] ) ;
V_17 -> V_30 -> V_108 = V_109 ;
V_17 -> V_127 [ 0 ] -> V_90 = 0 ;
F_45 () ;
if ( ! V_19 ) {
F_66 ( V_170 ) ;
}
F_49 () ;
if ( ( V_17 -> V_30 -> V_44 & V_192 ) ) {
break;
}
if ( V_17 -> V_127 [ 0 ] -> V_90 ) {
break;
}
if ( V_19 == 15 ) {
F_44 ( L_47 , V_8 -> V_13 ) ;
}
}
#else
V_194 = ( V_17 -> V_144 + 1 ) & 0x1 ;
V_17 -> V_135 [ 0 ] -> V_15 = V_196 | V_37 ;
V_17 -> V_127 [ 0 ] -> V_94 = V_17 -> V_124 [ V_194 ] -> V_94
= F_22 ( ( V_17 -> V_124 [ V_194 ] ) ) ;
V_17 -> V_127 [ 0 ] -> V_90 = V_17 -> V_124 [ V_194 ] -> V_90 = 0 ;
V_17 -> V_124 [ V_17 -> V_144 ] -> V_94 = F_22 ( ( V_17 -> V_127 [ 0 ] ) ) ;
V_17 -> V_144 = V_194 ;
F_66 ( V_170 ) ;
#endif
#else
V_17 -> V_135 [ V_17 -> V_142 ] -> V_15 = V_196 | V_37 ;
if ( ( V_194 = V_17 -> V_142 + 1 ) == V_123 ) {
V_194 = 0 ;
}
V_17 -> V_127 [ V_17 -> V_142 ] -> V_90 = 0 ;
V_17 -> V_127 [ V_17 -> V_142 ] -> V_94 = V_17 -> V_124 [ V_194 ] -> V_94
= F_22 ( ( V_17 -> V_124 [ V_194 ] ) ) ;
V_17 -> V_124 [ V_194 ] -> V_90 = 0 ;
V_17 -> V_124 [ V_17 -> V_142 ] -> V_94 = F_22 ( ( V_17 -> V_127 [ V_17 -> V_142 ] ) ) ;
V_17 -> V_142 = V_194 ;
if ( V_17 -> V_142 != V_17 -> V_143 )
F_61 ( V_8 ) ;
F_66 ( V_170 ) ;
#endif
return V_197 ;
}
static struct V_198 * F_67 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
unsigned short V_199 , V_200 , V_201 , V_202 ;
V_199 = V_17 -> V_30 -> V_203 ;
V_17 -> V_30 -> V_203 -= V_199 ;
V_200 = V_17 -> V_30 -> V_204 ;
V_17 -> V_30 -> V_204 -= V_200 ;
V_201 = V_17 -> V_30 -> V_205 ;
V_17 -> V_30 -> V_205 -= V_201 ;
V_202 = V_17 -> V_30 -> V_206 ;
V_17 -> V_30 -> V_206 -= V_202 ;
V_8 -> V_174 . V_207 += V_199 ;
V_8 -> V_174 . V_208 += V_202 ;
V_8 -> V_174 . V_209 += V_200 ;
V_8 -> V_174 . V_177 += V_201 ;
return & V_8 -> V_174 ;
}
static void F_68 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_210 ) {
return;
}
V_8 -> V_210 = 0 ;
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
V_8 -> V_210 = 1 ;
}
static void F_69 ( struct V_7 * V_8 ,
struct V_211 * V_212 )
{
strcpy ( V_212 -> V_213 , V_55 ) ;
strcpy ( V_212 -> V_214 , V_215 ) ;
sprintf ( V_212 -> V_216 , L_48 , V_8 -> V_38 ) ;
}
int T_1 F_70 ( void )
{
int V_217 , V_218 = 0 ;
for( V_217 = 0 ; V_217 < V_219 ; V_217 ++ ) {
struct V_7 * V_8 = F_38 ( sizeof( struct V_16 ) ) ;
if ( ! V_8 )
break;
V_8 -> V_9 = V_9 [ V_217 ] ;
V_8 -> V_38 = V_220 [ V_217 ] ;
if ( F_25 ( V_8 ) == 0 ) {
V_221 [ V_217 ] = V_8 ;
V_218 ++ ;
continue;
}
F_41 ( V_8 ) ;
if ( V_220 [ V_217 ] == 0 )
break;
F_44 ( L_49 , V_220 [ V_217 ] ) ;
}
if( V_218 == 0 ) {
if ( V_220 [ 0 ] == 0 )
F_71 ( L_50 ) ;
return - V_57 ;
} else return 0 ;
}
void T_5 F_72 ( void )
{
int V_217 ;
for ( V_217 = 0 ; V_217 < V_219 ; V_217 ++ ) {
struct V_7 * V_8 = V_221 [ V_217 ] ;
if ( V_8 ) {
F_73 ( V_8 ) ;
F_36 ( V_8 ) ;
F_41 ( V_8 ) ;
}
}
}
