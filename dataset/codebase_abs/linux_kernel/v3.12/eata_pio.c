static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 , L_1
L_2 , V_5 , V_6 , V_7 ) ;
F_2 ( V_2 , L_3
L_4 , V_8 , V_9 ) ;
F_2 ( V_2 , L_5 ,
V_4 -> V_10 , F_3 ( V_4 ) -> V_11 ) ;
F_2 ( V_2 , L_6 ,
F_3 ( V_4 ) -> V_12 ) ;
F_2 ( V_2 , L_7 ) ;
F_2 ( V_2 , L_8 , ( V_13 ) V_4 -> V_14 ) ;
F_2 ( V_2 , L_9 ,
( F_3 ( V_4 ) -> V_15 == 'P' ) ? L_10 :
( F_3 ( V_4 ) -> V_15 == 'E' ) ? L_11 : L_12 ) ;
return 0 ;
}
static int F_4 ( struct V_3 * V_16 )
{
T_1 * V_17 = F_3 ( V_16 ) ;
if ( V_16 -> V_18 && V_19 [ V_16 -> V_18 ] == 1 )
F_5 ( V_16 -> V_18 , NULL ) ;
else
V_19 [ V_16 -> V_18 ] -- ;
if ( F_3 ( V_16 ) -> V_20 == 0 ) {
if ( V_16 -> V_21 && V_16 -> V_22 )
F_6 ( V_16 -> V_21 , V_16 -> V_22 ) ;
}
if ( V_17 -> V_23 )
F_7 ( V_17 -> V_23 ) ;
return 1 ;
}
static void F_8 ( struct V_24 * V_25 , unsigned int V_26 )
{
V_25 -> V_27 += V_26 ;
if ( ( V_25 -> V_28 -= V_26 ) == 0 ) {
if ( ( -- V_25 -> V_29 ) == 0 )
V_25 -> V_30 = 0 ;
else {
V_25 -> V_31 ++ ;
V_25 -> V_27 = F_9 ( V_25 -> V_31 ) ;
V_25 -> V_28 = V_25 -> V_31 -> V_32 ;
}
}
}
static T_2 F_10 ( int V_18 , void * V_33 )
{
unsigned long V_34 ;
struct V_3 * V_35 = V_33 ;
T_2 V_36 ;
F_11 ( V_35 -> V_37 , V_34 ) ;
V_36 = F_12 ( V_18 , V_33 ) ;
F_13 ( V_35 -> V_37 , V_34 ) ;
return V_36 ;
}
static T_2 F_12 ( int V_18 , void * V_33 )
{
unsigned int V_38 = 0xfffff ;
struct V_39 * V_40 ;
T_1 * V_17 ;
struct V_41 * V_42 ;
unsigned long V_14 ;
unsigned int V_43 , V_44 ;
struct V_3 * V_16 ;
unsigned short V_45 = 0 ;
unsigned char V_46 , V_47 ;
T_2 V_36 = V_48 ;
for ( V_43 = 1 , V_16 = V_49 ; V_43 <= V_50 ; V_43 ++ , V_16 = F_3 ( V_16 ) -> V_51 )
{
if ( V_16 -> V_18 != V_18 )
continue;
if ( F_14 ( V_16 -> V_14 + V_52 ) & V_53 )
continue;
V_9 ++ ;
V_36 = V_54 ;
V_17 = F_3 ( V_16 ) ;
V_42 = & V_17 -> V_55 [ 0 ] ;
V_40 = V_42 -> V_40 ;
V_14 = V_40 -> V_56 -> V_57 -> V_14 ;
do {
V_46 = F_14 ( V_14 + V_52 ) ;
if ( V_46 & V_58 ) {
if ( V_42 -> V_59 ) {
V_44 = 256 ;
V_47 = 0 ;
while ( ( V_40 -> V_25 . V_30 ) && ( ( V_44 > 0 ) || ( V_47 ) ) ) {
if ( V_47 ) {
* ( V_40 -> V_25 . V_27 ) = V_45 >> 8 ;
F_8 ( & V_40 -> V_25 , 1 ) ;
V_47 = 0 ;
}
V_43 = F_15 (unsigned int, z, cmd->SCp.this_residual / 2 ) ;
F_16 ( V_14 + V_60 , V_40 -> V_25 . V_27 , V_43 ) ;
V_44 -= V_43 ;
F_8 ( & V_40 -> V_25 , 2 * V_43 ) ;
if ( ( V_44 > 0 ) && ( V_40 -> V_25 . V_28 == 1 ) ) {
V_45 = F_17 ( V_14 + V_60 ) ;
* ( V_40 -> V_25 . V_27 ) = V_45 & 0xff ;
F_8 ( & V_40 -> V_25 , 1 ) ;
V_44 -- ;
V_47 = 1 ;
}
}
while ( V_44 > 0 ) {
V_45 = F_17 ( V_14 + V_60 ) ;
V_44 -- ;
}
} else {
V_47 = 0 ;
V_44 = 256 ;
while ( ( V_40 -> V_25 . V_30 ) && ( ( V_44 > 0 ) || ( V_47 ) ) ) {
if ( V_47 ) {
V_45 += * ( V_40 -> V_25 . V_27 ) << 8 ;
F_8 ( & V_40 -> V_25 , 1 ) ;
F_18 ( V_45 , V_14 + V_60 ) ;
V_44 -- ;
V_47 = 0 ;
}
V_43 = F_15 (unsigned int, z, cmd->SCp.this_residual / 2 ) ;
F_19 ( V_14 + V_60 , V_40 -> V_25 . V_27 , V_43 ) ;
V_44 -= V_43 ;
F_8 ( & V_40 -> V_25 , 2 * V_43 ) ;
if ( ( V_44 > 0 ) && ( V_40 -> V_25 . V_28 == 1 ) ) {
V_45 = * ( V_40 -> V_25 . V_27 ) ;
V_45 &= 0xff ;
F_8 ( & V_40 -> V_25 , 1 ) ;
V_47 = 1 ;
}
}
while ( V_44 > 0 || V_47 ) {
F_18 ( V_45 , V_14 + V_60 ) ;
V_44 -- ;
V_47 = 0 ;
}
}
}
}
while ( ( V_46 & V_58 ) || ( ( V_46 & V_61 ) && V_17 -> V_62 ) );
if ( V_46 & V_53 )
break;
if ( ! ( F_14 ( V_14 + V_52 ) & V_63 ) ) {
V_40 -> V_64 = ( V_65 << 16 ) ;
V_17 -> V_66 |= ( 1 << V_42 -> V_67 ) ;
} else if ( V_17 -> V_66 & ( 1 << V_42 -> V_67 ) )
V_40 -> V_64 = ( V_65 << 16 ) + 0x02 ;
else
V_40 -> V_64 = ( V_68 << 16 ) ;
if ( V_42 -> V_69 == V_70 ) {
V_42 -> V_69 = FREE ;
V_38 = F_14 ( V_14 + V_52 ) ;
F_20 ( V_71 L_13 L_14 ) ;
return V_36 ;
}
#if V_72
if ( V_46 != 0x50 )
F_20 ( V_73 L_15 , V_46 , V_40 -> V_64 ) ;
#endif
V_42 -> V_69 = FREE ;
V_40 -> V_74 ( V_40 ) ;
}
return V_36 ;
}
static inline unsigned int F_21 ( unsigned long V_14 , unsigned char V_75 )
{
unsigned int V_76 = 50 ;
while ( F_14 ( V_14 + V_52 ) & V_53 )
if ( -- V_76 == 0 )
return 1 ;
F_22 ( V_77 , V_14 + V_78 ) ;
F_22 ( V_75 , V_14 + V_79 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 ,
void (* F_24)( struct V_39 * ) )
{
unsigned int V_43 , V_80 ;
unsigned long V_14 ;
T_1 * V_17 ;
struct V_3 * V_16 ;
struct V_41 * V_42 ;
V_8 ++ ;
V_17 = F_25 ( V_40 ) ;
V_16 = V_40 -> V_56 -> V_57 ;
V_14 = V_16 -> V_14 ;
V_80 = V_43 = 0 ;
if ( V_17 -> V_55 [ V_80 ] . V_69 != FREE ) {
F_26 ( V_81 , F_20 ( V_82 L_16 , V_16 -> V_83 , V_43 , V_80 ) ) ;
#if V_84
F_27 ( V_82 L_17 L_18 , V_8 , V_9 ) ;
#else
F_27 ( V_82 L_19 ) ;
#endif
}
V_42 = & V_17 -> V_55 [ V_80 ] ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 -> V_69 = V_85 ;
F_26 ( V_81 , F_28 ( V_73 , V_40 ,
L_20 , V_40 , V_80 ) ) ;
V_40 -> V_74 = ( void * ) F_24 ;
if ( V_40 -> V_86 == V_87 )
V_42 -> V_88 = 1 ;
else
V_42 -> V_59 = 0 ;
V_42 -> V_89 = ( V_40 -> V_56 -> V_90 == V_17 -> V_91 ) ;
V_42 -> V_92 = F_29 ( F_30 ( V_40 ) ) ;
V_42 -> V_93 = 0 ;
V_42 -> V_94 = 0 ;
V_42 -> V_95 = 0 ;
V_42 -> V_67 = V_40 -> V_56 -> V_90 ;
V_42 -> V_96 = V_40 -> V_56 -> V_97 ;
V_42 -> V_98 = 0 ;
V_42 -> V_99 = 1 ;
memcpy ( V_42 -> V_100 , V_40 -> V_101 , F_31 ( * V_40 -> V_101 ) ) ;
V_42 -> V_102 = 0 ;
V_42 -> V_103 = V_42 ;
V_42 -> V_40 = V_40 ;
V_40 -> V_104 = ( char * ) & V_17 -> V_55 [ V_80 ] ;
if ( ! F_30 ( V_40 ) ) {
V_40 -> V_25 . V_29 = 1 ;
V_40 -> V_25 . V_27 = NULL ;
V_40 -> V_25 . V_28 = 0 ;
V_40 -> V_25 . V_31 = NULL ;
} else {
V_40 -> V_25 . V_31 = F_32 ( V_40 ) ;
V_40 -> V_25 . V_29 = F_33 ( V_40 ) ;
V_40 -> V_25 . V_27 = F_9 ( V_40 -> V_25 . V_31 ) ;
V_40 -> V_25 . V_28 = V_40 -> V_25 . V_31 -> V_32 ;
}
V_40 -> V_25 . V_30 = ( V_40 -> V_25 . V_28 != 0 ) ;
if ( F_21 ( V_14 , V_105 ) ) {
V_40 -> V_64 = V_106 << 16 ;
F_28 ( V_107 , V_40 ,
L_21
L_22 , V_40 ) ;
F_24 ( V_40 ) ;
V_42 -> V_69 = FREE ;
return 0 ;
}
while ( ! ( F_14 ( V_14 + V_52 ) & V_58 ) )
F_34 () ;
F_19 ( V_14 + V_60 , V_42 , V_17 -> V_108 ) ;
F_22 ( V_109 , V_14 + V_79 ) ;
for ( V_43 = 0 ; V_43 < V_17 -> V_110 ; V_43 ++ )
F_18 ( 0 , V_14 + V_60 ) ;
F_26 ( V_81 , F_28 ( V_73 , V_40 ,
L_23
L_24 , V_16 -> V_14 , V_40 , V_80 , V_16 -> V_18 ) ) ;
return 0 ;
}
int F_35 ( struct V_39 * V_40 )
{
unsigned int V_43 , V_111 = 0 ;
unsigned char V_112 = 0 ;
struct V_39 * V_113 ;
struct V_3 * V_57 = V_40 -> V_56 -> V_57 ;
F_26 ( V_114 , F_28 ( V_115 , V_40 ,
L_25 ) ) ;
F_36 ( V_57 -> V_37 ) ;
if ( F_25 ( V_40 ) -> V_116 == V_117 ) {
F_20 ( V_115 L_26 ) ;
F_37 ( V_57 -> V_37 ) ;
return V_118 ;
}
for ( V_43 = 0 ; V_43 < V_40 -> V_56 -> V_57 -> V_83 ; V_43 ++ ) {
if ( F_25 ( V_40 ) -> V_55 [ V_43 ] . V_69 == FREE )
continue;
V_113 = F_25 ( V_40 ) -> V_55 [ V_43 ] . V_40 ;
F_25 ( V_40 ) -> V_55 [ V_43 ] . V_69 = V_117 ;
F_20 ( V_115 L_27 , V_43 ) ;
if ( V_113 == NULL )
F_27 ( L_28 , V_43 ) ;
}
F_22 ( V_119 , V_40 -> V_56 -> V_57 -> V_14 + V_79 ) ;
F_26 ( V_114 , F_20 ( V_115 L_29 ) ) ;
F_25 ( V_40 ) -> V_116 = V_117 ;
F_37 ( V_57 -> V_37 ) ;
F_38 ( 3000 ) ;
F_36 ( V_57 -> V_37 ) ;
F_26 ( V_114 , F_20 ( V_115 L_30 L_31 , V_111 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_56 -> V_57 -> V_83 ; V_43 ++ ) {
if ( F_25 ( V_40 ) -> V_55 [ V_43 ] . V_69 != V_117 )
continue;
V_113 = F_25 ( V_40 ) -> V_55 [ V_43 ] . V_40 ;
V_113 -> V_64 = V_120 << 16 ;
F_20 ( V_115 L_32 , V_43 ) ;
F_25 ( V_40 ) -> V_55 [ V_43 ] . V_69 = FREE ;
V_113 -> V_74 ( V_113 ) ;
}
F_25 ( V_40 ) -> V_116 = 0 ;
F_37 ( V_57 -> V_37 ) ;
if ( V_112 ) {
F_26 ( V_114 , F_20 ( V_115 L_33 ) ) ;
return V_121 ;
} else {
F_26 ( V_114 , F_20 ( V_115 L_34 ) ) ;
return V_118 ;
}
}
static char * F_39 ( unsigned long V_14 , unsigned int V_18 , unsigned int V_90 , unsigned long V_108 , unsigned short V_110 )
{
struct V_41 V_42 ;
static char V_122 [ 256 ] ;
int V_44 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
V_42 . V_59 = 1 ;
V_42 . V_89 = 1 ;
V_42 . V_92 = F_29 ( 254 ) ;
V_42 . V_123 = F_29 ( 0 ) ;
V_42 . V_67 = V_90 ;
V_42 . V_96 = 0 ;
V_42 . V_100 [ 0 ] = V_124 ;
V_42 . V_100 [ 1 ] = 0 ;
V_42 . V_100 [ 2 ] = 0 ;
V_42 . V_100 [ 3 ] = 0 ;
V_42 . V_100 [ 4 ] = 254 ;
V_42 . V_100 [ 5 ] = 0 ;
if ( F_21 ( V_14 , V_105 ) )
return NULL ;
while ( ! ( F_14 ( V_14 + V_52 ) & V_58 ) )
F_34 () ;
F_19 ( V_14 + V_60 , & V_42 , V_108 ) ;
F_22 ( V_109 , V_14 + V_79 ) ;
for ( V_44 = 0 ; V_44 < V_110 ; V_44 ++ )
F_18 ( 0 , V_14 + V_60 ) ;
while ( F_14 ( V_14 + V_52 ) & V_53 )
F_34 () ;
if ( F_14 ( V_14 + V_52 ) & V_63 )
return NULL ;
else if ( ! ( F_14 ( V_14 + V_52 ) & V_58 ) )
return NULL ;
else {
F_16 ( V_14 + V_60 , & V_122 , 127 ) ;
while ( F_14 ( V_14 + V_52 ) & V_58 )
F_17 ( V_14 + V_60 ) ;
return V_122 ;
}
}
static int F_40 ( unsigned long V_14 , struct V_125 * V_126 )
{
unsigned long V_76 = V_127 / 2 ;
int V_44 ;
unsigned short * V_128 ;
if ( ! F_41 ( V_14 , 9 , L_35 ) )
return 0 ;
memset ( V_126 , 0 , sizeof( struct V_125 ) ) ;
while ( F_14 ( V_14 + V_52 ) & V_53 )
if ( -- V_76 == 0 )
goto V_129;
F_26 ( V_130 && V_131 , F_20 ( V_73 L_36 , V_14 ) ) ;
F_21 ( V_14 , V_132 ) ;
V_76 = 50 ;
for ( V_128 = ( unsigned short * ) V_126 ; ( long ) V_128 <= ( ( long ) V_126 + ( sizeof( struct V_125 ) / 2 ) ) ; V_128 ++ ) {
while ( ! ( F_14 ( V_14 + V_52 ) & V_58 ) )
if ( -- V_76 == 0 )
goto V_129;
V_76 = 50 ;
* V_128 = F_17 ( V_14 + V_60 ) ;
}
if ( F_14 ( V_14 + V_52 ) & V_63 ) {
F_26 ( V_131 , F_20 ( L_37
L_38 , V_14 ) ) ;
goto V_129;
}
if ( F_29 ( V_133 ) != V_126 -> V_134 )
goto V_129;
F_26 ( V_130 && V_131 , F_20 ( V_107 L_39
L_40 ,
V_14 , ( unsigned int ) ( V_126 -> V_135 ) ) ) ;
while ( F_14 ( V_14 + V_52 ) & V_58 )
F_17 ( V_14 + V_60 ) ;
if ( ! V_136 ) {
for ( V_44 = 0 ; V_44 < V_137 ; V_44 ++ )
if ( V_14 == V_138 [ V_44 ] ) {
V_126 -> V_139 = V_140 [ V_44 ] ;
break;
}
}
return 1 ;
V_129:
F_6 ( V_14 , 9 ) ;
return 0 ;
}
static void F_42 ( struct V_125 * V_141 )
{
F_20 ( L_41 ) ;
F_20 ( L_42 , F_43 ( V_141 -> V_142 ) , V_141 -> V_135 , V_141 -> V_143 , V_141 -> V_144 , V_141 -> V_145 , V_141 -> V_146 ) ;
F_20 ( L_43 , V_141 -> V_147 , V_141 -> V_148 [ 3 ] , V_141 -> V_148 [ 2 ] , V_141 -> V_148 [ 1 ] , F_44 ( V_141 -> V_149 ) , F_44 ( V_141 -> V_150 ) , V_141 -> V_151 ) ;
F_20 ( L_44 , V_141 -> V_139 , V_141 -> V_152 , V_141 -> V_153 , V_141 -> V_154 , V_141 -> V_155 ) ;
}
static unsigned int F_45 ( unsigned int V_14 )
{
unsigned char V_31 [ 512 ] ;
#ifdef F_46
int V_44 ;
#endif
F_20 ( L_45 ) ;
while ( F_14 ( V_14 + V_52 ) & V_53 ) ;
F_22 ( V_156 , V_14 + V_79 ) ;
do {
while ( F_14 ( V_14 + V_52 ) & V_53 )
;
if ( F_14 ( V_14 + V_52 ) & V_58 ) {
F_16 ( V_14 + V_60 , & V_31 , 256 ) ;
#ifdef F_46
for ( V_44 = 0 ; V_44 < 511 && V_31 [ V_44 ] ; V_44 ++ )
if ( V_31 [ V_44 ] != 7 )
F_20 ( L_46 , V_31 [ V_44 ] ) ;
#endif
}
} while ( F_14 ( V_14 + V_52 ) & ( V_53 | V_58 ) );
return ( ! ( F_14 ( V_14 + V_52 ) & V_63 ) ) ;
}
static int F_47 ( long V_14 , struct V_125 * V_141 , struct V_157 * V_23 )
{
unsigned long V_158 = 0 ;
char * V_122 ;
unsigned long V_108 ;
unsigned short V_110 ;
struct V_3 * V_16 ;
T_1 * V_17 ;
F_26 ( V_159 , F_42 ( V_141 ) ) ;
if ( V_141 -> V_160 ) {
F_20 ( L_47 , V_14 ) ;
if ( ! V_136 )
return 0 ;
}
if ( ( V_122 = F_39 ( V_14 , V_141 -> V_139 , V_141 -> V_148 [ 3 ] , V_108 = ( F_29 ( V_141 -> V_108 ) + 1 ) / 2 , V_110 = ( F_48 ( V_141 -> V_110 ) + 1 ) / 2 ) ) == NULL ) {
F_20 ( L_48 , V_14 ) ;
return 0 ;
}
if ( ! F_45 ( V_14 ) && ! V_136 ) {
F_20 ( L_49 , V_14 ) ;
return 0 ;
}
V_158 = sizeof( T_1 ) + ( sizeof( struct V_41 ) * F_44 ( V_141 -> V_149 ) ) ;
V_16 = F_49 ( & V_161 , V_158 ) ;
if ( V_16 == NULL )
return 0 ;
if ( ! V_19 [ V_141 -> V_139 ] ) {
if ( ! F_50 ( V_141 -> V_139 , F_10 , V_162 , L_50 , V_16 ) ) {
V_19 [ V_141 -> V_139 ] ++ ;
if ( ! V_141 -> V_152 )
V_163 [ V_141 -> V_139 ] = 1 ;
} else {
F_20 ( L_51 , V_141 -> V_139 ) ;
return 0 ;
}
} else {
if ( V_163 [ V_141 -> V_139 ] ) {
F_20 ( L_52 L_53 ) ;
return 0 ;
} else
V_19 [ V_141 -> V_139 ] ++ ;
}
V_17 = F_3 ( V_16 ) ;
memset ( V_17 -> V_55 , 0 , ( sizeof( struct V_41 ) * F_44 ( V_141 -> V_149 ) ) ) ;
memset ( V_17 -> V_164 , 0 , sizeof( V_17 -> V_164 ) ) ;
F_51 ( F_3 ( V_16 ) -> V_165 , & V_122 [ 8 ] , sizeof( F_3 ( V_16 ) -> V_165 ) ) ;
F_51 ( F_3 ( V_16 ) -> V_11 , & V_122 [ 16 ] , sizeof( F_3 ( V_16 ) -> V_11 ) ) ;
F_3 ( V_16 ) -> V_12 [ 0 ] = V_122 [ 32 ] ;
F_3 ( V_16 ) -> V_12 [ 1 ] = V_122 [ 33 ] ;
F_3 ( V_16 ) -> V_12 [ 2 ] = V_122 [ 34 ] ;
F_3 ( V_16 ) -> V_12 [ 3 ] = '.' ;
F_3 ( V_16 ) -> V_12 [ 4 ] = V_122 [ 35 ] ;
F_3 ( V_16 ) -> V_12 [ 5 ] = 0 ;
switch ( F_43 ( V_141 -> V_142 ) ) {
case 0x1c :
F_3 ( V_16 ) -> V_166 = 'a' ;
break;
case 0x1e :
F_3 ( V_16 ) -> V_166 = 'b' ;
break;
case 0x22 :
F_3 ( V_16 ) -> V_166 = 'c' ;
break;
case 0x24 :
F_3 ( V_16 ) -> V_166 = 'z' ;
default:
F_3 ( V_16 ) -> V_166 = '?' ;
}
if ( F_43 ( V_141 -> V_142 ) >= 0x22 ) {
if ( V_141 -> V_167 )
V_17 -> V_15 = V_168 ;
else if ( V_141 -> V_169 )
V_17 -> V_15 = V_170 ;
else
V_17 -> V_15 = V_171 ;
} else {
if ( V_122 [ 21 ] == '4' )
V_17 -> V_15 = V_168 ;
else if ( V_122 [ 21 ] == '2' )
V_17 -> V_15 = V_170 ;
else
V_17 -> V_15 = V_171 ;
}
F_3 ( V_16 ) -> V_108 = V_108 ;
F_3 ( V_16 ) -> V_110 = V_110 ;
F_3 ( V_16 ) -> V_91 = V_141 -> V_148 [ 3 ] ;
F_3 ( V_16 ) -> V_66 = 1 << V_141 -> V_148 [ 3 ] ;
F_3 ( V_16 ) -> V_62 = V_141 -> V_146 ;
V_16 -> V_172 = V_14 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_21 = V_14 ;
V_16 -> V_22 = 9 ;
V_16 -> V_18 = V_141 -> V_139 ;
V_16 -> V_173 = V_174 ;
V_16 -> V_175 = V_141 -> V_148 [ 3 ] ;
V_16 -> V_83 = 1 ;
V_16 -> V_176 = 1 ;
V_16 -> V_177 = V_178 ;
V_17 -> V_20 = 0 ;
V_17 -> V_23 = F_52 ( V_23 ) ;
V_16 -> V_179 = 8 ;
V_16 -> V_180 = 8 ;
if ( V_141 -> V_151 )
V_17 -> V_181 = 0 ;
else
V_17 -> V_181 = 1 ;
V_17 -> V_182 = NULL ;
V_17 -> V_51 = V_183 ;
if ( V_17 -> V_51 != NULL )
F_3 ( V_17 -> V_51 ) -> V_182 = V_16 ;
V_183 = V_16 ;
if ( V_49 == NULL )
V_49 = V_16 ;
V_50 ++ ;
return ( 1 ) ;
}
static void F_53 ( struct V_125 * V_126 )
{
int V_184 ;
for ( V_184 = 0 ; V_184 < V_137 ; V_184 ++ ) {
if ( ! V_138 [ V_184 ] )
continue;
if ( ! F_40 ( V_138 [ V_184 ] , V_126 ) )
continue;
if ( ! F_47 ( V_138 [ V_184 ] , V_126 , NULL ) )
F_6 ( V_138 [ V_184 ] , 9 ) ;
else
V_138 [ V_184 ] = 0 ;
}
return;
}
static void F_54 ( struct V_125 * V_126 )
{
V_13 V_14 ;
int V_184 ;
#ifdef F_55
T_3 V_185 , V_186 , V_187 ;
#endif
for ( V_184 = 0 ; V_184 < V_188 ; V_184 ++ ) {
if ( V_189 [ V_184 ] ) {
V_14 = 0x1c88 + ( V_184 * 0x1000 ) ;
#ifdef F_55
V_185 = F_14 ( ( V_190 ) V_14 - 8 ) ;
V_186 = F_14 ( ( V_190 ) V_14 - 7 ) ;
V_187 = F_14 ( ( V_190 ) V_14 - 6 ) ;
if ( ( ( V_185 == 0x12 ) && ( V_186 == 0x14 ) ) || ( ( V_185 == 0x38 ) && ( V_186 == 0xa3 ) && ( V_187 == 0x82 ) ) || ( ( V_185 == 0x06 ) && ( V_186 == 0x94 ) && ( V_187 == 0x24 ) ) ) {
F_26 ( V_131 , F_20 ( V_107 L_54 L_55 , ( int ) V_185 , ( int ) V_186 , ( int ) V_187 ) ) ;
#endif
if ( F_40 ( V_14 , V_126 ) ) {
F_26 ( V_131 && V_191 , F_42 ( V_126 ) ) ;
if ( V_126 -> V_139 ) {
if ( ! F_47 ( V_14 , V_126 , NULL ) )
F_6 ( V_14 , 9 ) ;
} else {
F_20 ( V_107 L_56 L_57 ) ;
F_6 ( V_14 , 9 ) ;
}
}
V_189 [ V_184 ] = 0 ;
#ifdef F_55
}
#endif
}
}
return;
}
static void F_56 ( struct V_125 * V_126 )
{
#ifndef F_57
F_20 ( L_58 ) ;
#else
struct V_157 * V_35 = NULL ;
unsigned long V_14 , V_43 ;
while ( ( V_35 = F_58 ( V_192 , V_193 , V_35 ) ) != NULL ) {
F_26 ( V_131 && V_194 , F_20 ( L_59 , F_59 ( V_35 ) ) ) ;
if ( F_60 ( V_35 ) )
continue;
F_61 ( V_35 ) ;
V_14 = F_62 ( V_35 , 0 ) ;
if ( V_14 & V_195 ) {
F_20 ( L_60 , F_59 ( V_35 ) ) ;
continue;
}
V_14 = F_63 ( V_35 , 0 ) ;
if ( ( F_14 ( V_14 ) == 0x12 ) && ( F_14 ( V_14 + 1 ) == 0x14 ) )
continue;
V_14 += 0x10 ;
if ( V_14 != 0x1f8 ) {
if ( F_40 ( V_14 , V_126 ) ) {
if ( V_126 -> V_153 ) {
F_6 ( V_14 , 9 ) ;
continue;
}
if ( ! F_47 ( V_14 , V_126 , V_35 ) ) {
F_6 ( V_14 , 9 ) ;
continue;
}
if ( V_14 < 0x1000 ) {
for ( V_43 = 0 ; V_43 < V_137 ; ++ V_43 ) {
if ( V_138 [ V_43 ] == V_14 ) {
V_138 [ V_43 ] = 0 ;
break;
}
}
} else if ( ( V_14 & 0x0fff ) == 0x0c88 ) {
V_43 = ( V_14 >> 12 ) & 0x0f ;
V_189 [ V_43 ] = 0 ;
}
}
#ifdef F_64
else if ( F_65 ( V_14 ) ) {
F_20 ( L_61 L_62 ) ;
}
#endif
}
}
#endif
}
static int F_66 ( struct V_196 * V_197 )
{
struct V_3 * V_198 ;
struct V_125 V_141 ;
int V_184 ;
F_56 ( & V_141 ) ;
F_54 ( & V_141 ) ;
F_53 ( & V_141 ) ;
for ( V_184 = 0 ; V_184 < V_199 ; V_184 ++ )
if ( V_19 [ V_184 ] )
F_50 ( V_184 , F_10 , V_162 , L_50 , NULL ) ;
V_198 = V_49 ;
if ( V_50 != 0 ) {
F_20 ( L_63
L_64 L_65 L_66 , V_5 , V_6 , V_7 ) ;
F_20 ( L_67 ) ;
F_20 ( L_68 L_69 ) ;
for ( V_184 = 1 ; V_184 <= V_50 ; V_184 ++ ) {
F_20 ( L_70
L_71 ,
V_198 -> V_10 , F_3 ( V_198 ) -> V_11 , F_3 ( V_198 ) -> V_12 ,
F_3 ( V_198 ) -> V_166 , ( F_3 ( V_198 ) -> V_15 == 'P' ) ?
L_10 : ( F_3 ( V_198 ) -> V_15 == 'E' ) ? L_11 : L_12 ,
V_198 -> V_14 , V_198 -> V_18 , F_3 ( V_198 ) -> V_20 , V_198 -> V_175 ,
F_3 ( V_198 ) -> V_181 ? 'Y' : 'N' , V_198 -> V_83 ,
V_198 -> V_177 , V_198 -> V_176 ) ;
V_198 = F_3 ( V_198 ) -> V_182 ;
}
}
return ( V_50 ) ;
}
