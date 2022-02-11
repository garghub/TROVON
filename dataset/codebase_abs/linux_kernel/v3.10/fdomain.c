static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return;
if ( V_3 < 0 && V_4 < 0 ) {
F_2 ( V_5 L_1 ,
V_2 -> V_6 , V_2 -> V_7 ) ;
} else {
F_2 ( V_5 L_2 , V_2 -> V_6 ) ;
if ( V_3 >= 0 ) F_2 ( L_3 , V_3 ) ;
else F_2 ( L_4 ) ;
if ( V_4 >= 0 ) F_2 ( L_5 , V_4 ) ;
else F_2 ( L_4 ) ;
F_2 ( L_6 ,
V_8 , V_2 -> V_7 ) ;
}
F_2 ( V_5 L_7 ,
V_2 -> V_6 ,
V_9 == V_10 ? L_8 : ( V_9 == V_11 ? L_9 : ( V_9 == V_12 ? ( V_13 ? L_10 : L_11 ) : L_12 ) ) ,
V_14 ) ;
if ( V_15 )
F_2 ( L_5 , V_15 ) ;
else
F_2 ( L_13 ) ;
F_2 ( L_14 ) ;
}
int F_3 ( char * V_16 )
{
int V_17 [ 4 ] ;
( void ) F_4 ( V_16 , F_5 ( V_17 ) , V_17 ) ;
if ( V_18 ++ || V_17 [ 0 ] < 2 || V_17 [ 0 ] > 3 ) {
F_2 ( V_5 L_15 ) ;
F_2 ( V_19 L_16 ) ;
return 0 ;
}
V_14 = V_17 [ 0 ] >= 1 ? V_17 [ 1 ] : 0 ;
V_15 = V_17 [ 0 ] >= 2 ? V_17 [ 2 ] : 0 ;
V_7 = V_17 [ 0 ] >= 3 ? V_17 [ 3 ] : 0 ;
V_3 = V_4 = - 1 ;
++ V_18 ;
return 1 ;
}
static void F_6 ( unsigned V_20 )
{
F_7 ( 10 * V_20 ) ;
}
static inline void F_8 ( void )
{
F_9 ( 0 , V_14 + V_21 ) ;
F_9 ( 0 , V_14 + V_22 ) ;
if ( V_9 == V_11 || V_9 == V_12 )
F_9 ( 0x21 | V_23 , V_14 + V_24 ) ;
else
F_9 ( 0x01 | V_23 , V_14 + V_24 ) ;
}
static int F_10 ( int V_25 )
{
#if V_26
F_2 ( L_17 ,
F_11 ( V_25 + V_27 ) , F_11 ( V_25 + V_28 ) ) ;
#endif
if ( F_11 ( V_25 + V_28 ) != 0xe9 ) {
if ( F_11 ( V_25 + V_28 ) != 0x27 ) return 0 ;
if ( F_11 ( V_25 + V_27 ) != 0x61 ) return 0 ;
V_9 = V_10 ;
} else {
if ( F_11 ( V_25 + V_27 ) != 0x60 ) return 0 ;
V_9 = V_11 ;
F_9 ( 0x80 , V_25 + V_29 ) ;
if ( ( F_11 ( V_25 + V_30 ) & 0x80 ) == 0x80 ) {
F_9 ( 0x00 , V_25 + V_29 ) ;
if ( ( F_11 ( V_25 + V_30 ) & 0x80 ) == 0x00 ) {
V_9 = V_12 ;
V_31 = 0x800 ;
}
}
}
return 1 ;
}
static int F_12 ( void )
{
int V_32 ;
int V_33 ;
for ( V_32 = 0 ; V_32 < 255 ; V_32 ++ ) {
F_9 ( V_32 , V_14 + V_34 ) ;
V_33 = F_11 ( V_14 + V_35 ) ;
if ( V_32 != V_33 )
return 1 ;
}
return 0 ;
}
static int F_13 ( int V_36 )
{
int V_37 = F_11 ( V_36 + V_38 ) ;
#if V_26
F_2 ( L_18 , V_37 ) ;
#endif
if ( V_9 != V_12 && ! V_13 && V_39 [ ( V_37 & 0xc0 ) >> 6 ] != V_8 )
return 0 ;
return V_17 [ ( V_37 & 0x0e ) >> 1 ] ;
}
static int F_14 ( int * V_40 , int * V_41 )
{
int V_32 , V_42 ;
int V_36 = 0xdeadbeef ;
int V_43 = 0 ;
#if V_26
F_2 ( L_19 ) ;
#endif
for ( V_32 = 0 ; V_32 < V_44 ; V_32 ++ ) {
void T_1 * V_45 = F_15 ( V_39 [ V_32 ] , 0x2000 ) ;
if ( ! V_45 )
continue;
#if V_26
F_2 ( L_20 , V_39 [ V_32 ] , V_8 ) ;
#endif
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
if ( F_16 ( V_45 + V_47 [ V_42 ] . V_48 ,
V_47 [ V_42 ] . V_49 ,
V_47 [ V_42 ] . V_50 ) ) {
V_3 = V_47 [ V_42 ] . V_51 ;
V_4 = V_47 [ V_42 ] . V_52 ;
V_13 = ( V_47 [ V_42 ] . V_43 == 1 ) ;
V_53 = ( V_47 [ V_42 ] . V_43 > 1 ) ? V_47 [ V_42 ] . V_43 : 0 ;
V_8 = V_39 [ V_32 ] ;
V_54 = V_45 ;
goto V_55;
}
}
F_17 ( V_45 ) ;
}
V_55:
if ( V_3 == 2 ) {
switch ( V_53 ) {
case 2 :
case 3 :
V_36 = F_18 ( V_54 + 0x1fa2 ) + ( F_18 ( V_54 + 0x1fa3 ) << 8 ) ;
break;
case 4 :
V_36 = F_18 ( V_54 + 0x1fa3 ) + ( F_18 ( V_54 + 0x1fa4 ) << 8 ) ;
break;
default:
V_36 = F_18 ( V_54 + 0x1fcc ) + ( F_18 ( V_54 + 0x1fcd ) << 8 ) ;
break;
}
#if V_26
F_2 ( L_21 , V_36 ) ;
#endif
for ( V_32 = 0 ; V_32 < V_56 ; V_32 ++ ) {
if ( V_36 == V_57 [ V_32 ] ) {
if ( ! F_19 ( V_36 , 0x10 , L_22 ) )
break;
if ( ! F_10 ( V_36 ) ) {
F_20 ( V_36 , 0x10 ) ;
break;
}
* V_40 = F_13 ( V_36 ) ;
* V_41 = V_36 ;
return 1 ;
}
}
#if V_26
F_2 ( L_23 ) ;
#endif
}
for ( V_32 = 0 ; V_32 < V_56 ; V_32 ++ ) {
V_36 = V_57 [ V_32 ] ;
if ( ! F_19 ( V_36 , 0x10 , L_22 ) ) {
#if V_26
F_2 ( L_24 , V_36 ) ;
#endif
continue;
}
#if V_26
F_2 ( L_21 , V_36 ) ;
#endif
V_43 = F_10 ( V_36 ) ;
if ( V_43 )
break;
F_20 ( V_36 , 0x10 ) ;
}
#if V_26
if ( V_43 ) F_2 ( L_25 ) ;
else F_2 ( L_26 ) ;
#endif
if ( ! V_43 ) return 0 ;
* V_40 = F_13 ( V_36 ) ;
* V_41 = V_36 ;
return 1 ;
}
static int F_14 ( int * V_40 , int * V_41 )
{
if ( V_40 )
* V_40 = 0 ;
if ( V_41 )
* V_41 = 0 ;
return 0 ;
}
static int F_21 ( int * V_40 , int * V_41 , struct V_58 * * V_59 )
{
unsigned int V_60 ;
unsigned long V_61 ;
struct V_58 * V_62 = NULL ;
#if V_26
F_2 ( L_27 ) ;
F_2 ( L_28
L_29 ,
V_63 ,
V_64 ) ;
#endif
if ( ( V_62 = F_22 ( V_63 , V_64 , V_62 ) ) == NULL )
return 0 ;
if ( F_23 ( V_62 ) )
goto V_65;
#if V_26
F_2 ( L_28
L_30 ,
V_62 -> V_66 -> V_67 ,
F_24 ( V_62 -> V_68 ) ,
F_25 ( V_62 -> V_68 ) ) ;
#endif
V_61 = F_26 ( V_62 , 0 ) ;
V_60 = V_62 -> V_40 ;
if ( ! F_19 ( V_61 , 0x10 , L_22 ) )
goto V_65;
* V_40 = V_60 ;
* V_41 = V_61 ;
* V_59 = V_62 ;
#if V_26
F_2 ( L_28
L_31 , * V_40 , * V_41 , V_61 ) ;
#endif
if ( ! F_10 ( V_61 ) ) {
F_2 ( V_19 L_32 ) ;
F_20 ( V_61 , 0x10 ) ;
goto V_65;
}
V_3 = V_4 = - 1 ;
V_13 = 1 ;
V_69 = V_62 ;
V_53 = 0 ;
V_8 = 0 ;
return 1 ;
V_65:
F_27 ( V_62 ) ;
return 0 ;
}
struct V_1 * F_28 ( struct V_70 * V_71 )
{
int V_72 ;
struct V_1 * V_2 ;
struct V_58 * V_62 = NULL ;
if ( V_18 ) {
#if V_26
F_2 ( L_33 ,
V_14 , V_15 ) ;
#endif
if ( ! F_19 ( V_14 , 0x10 , L_22 ) ) {
F_2 ( L_34 , V_14 ) ;
F_2 ( L_16 ) ;
return NULL ;
}
if ( ! F_10 ( V_14 ) ) {
F_2 ( L_35 ,
V_14 ) ;
F_2 ( L_16 ) ;
F_20 ( V_14 , 0x10 ) ;
return NULL ;
}
} else {
int V_43 = 0 ;
#ifdef F_29
V_43 = F_21 ( & V_15 , & V_14 , & V_62 ) ;
#endif
if ( ! V_43 ) {
V_43 = F_14 ( & V_15 , & V_14 ) ;
if ( ! V_43 ) {
F_2 ( L_36 ) ;
return NULL ;
}
}
}
F_30 ( NULL ) ;
if ( F_12 () ) {
F_2 ( V_19 L_37 , V_14 ) ;
if ( V_18 ) {
F_2 ( V_19 L_16 ) ;
}
goto V_65;
}
if ( V_7 ) {
V_71 -> V_7 = ( V_7 & 0x07 ) ;
V_73 = ( 1 << V_71 -> V_7 ) ;
} else {
if ( V_13 || ( V_3 == 3 && V_4 >= 2 ) || V_3 < 0 ) {
V_71 -> V_7 = 7 ;
V_73 = 0x80 ;
} else {
V_71 -> V_7 = 6 ;
V_73 = 0x40 ;
}
}
V_2 = F_31 ( V_71 , 0 ) ;
if( V_2 == NULL ) {
F_20 ( V_14 , 0x10 ) ;
return NULL ;
}
V_2 -> V_40 = V_15 ;
V_2 -> V_74 = V_14 ;
V_2 -> V_75 = 0x10 ;
F_1 ( V_2 ) ;
if ( ! V_15 ) {
F_2 ( V_19 L_38 ) ;
goto V_65;
} else {
V_72 = F_32 ( V_15 ,
V_76 , V_62 ? V_77 : 0 , L_22 , V_2 ) ;
if ( V_72 < 0 ) {
if ( V_72 == - V_78 ) {
F_2 ( V_19 L_39 , V_15 ) ;
F_2 ( V_19 L_40 ) ;
F_2 ( V_19 L_41 ) ;
} else if ( V_72 == - V_79 ) {
F_2 ( V_19 L_42 , V_15 ) ;
F_2 ( V_19 L_43 ) ;
} else {
F_2 ( V_19 L_44 , V_15 ) ;
F_2 ( V_19 L_40 ) ;
F_2 ( V_19 L_41 ) ;
}
F_2 ( V_19 L_45 ) ;
goto V_65;
}
}
return V_2 ;
V_65:
F_27 ( V_62 ) ;
F_20 ( V_14 , 0x10 ) ;
return NULL ;
}
static int F_33 ( struct V_70 * V_71 )
{
if ( V_80 )
F_3 ( V_80 ) ;
return ( F_28 ( V_71 ) != NULL ) ;
}
static const char * F_34 ( struct V_1 * V_81 )
{
static char V_82 [ 128 ] ;
char * V_83 ;
strcpy ( V_82 , L_46 ) ;
if ( strchr ( V_84 , ':' ) ) {
strcat ( V_82 , strchr ( V_84 , ':' ) + 1 ) ;
V_83 = strrchr ( V_82 , '$' ) - 1 ;
if ( ! V_83 )
V_83 = V_82 + strlen ( V_82 ) - 1 ;
if ( * V_83 != ' ' )
++ V_83 ;
* V_83 = '\0' ;
} else {
strcat ( V_82 , L_47 V_84 ) ;
}
return V_82 ;
}
static int F_35 ( int V_85 )
{
int V_86 ;
unsigned long V_87 ;
#if V_88
static int V_43 = 0 ;
#endif
F_9 ( 0x82 , V_14 + V_21 ) ;
F_9 ( V_73 | ( 1 << V_85 ) , V_14 + V_89 ) ;
F_9 ( V_23 , V_14 + V_24 ) ;
V_87 = 350 ;
do {
V_86 = F_11 ( V_14 + V_90 ) ;
if ( V_86 & 1 ) {
F_9 ( 0x80 , V_14 + V_21 ) ;
return 0 ;
}
F_7 ( 1 ) ;
} while ( -- V_87 );
F_8 () ;
#if V_91
if ( ! V_85 ) F_2 ( L_48 ) ;
#endif
#if V_88
if ( ! V_85 ) {
if ( ! V_43 )
++ V_43 ;
else
F_2 ( L_49 ) ;
}
#endif
return 1 ;
}
static void F_36 ( int error )
{
if ( V_92 ) {
V_92 = 0 ;
F_9 ( 0x00 , V_14 + V_93 ) ;
F_8 () ;
V_94 -> V_33 = error ;
if ( V_94 -> V_95 )
V_94 -> V_95 ( V_94 ) ;
else F_37 ( L_50 ) ;
} else {
F_37 ( L_51 ) ;
}
#if V_96
V_97 = 0 ;
#endif
}
static T_2 V_76 ( int V_40 , void * V_98 )
{
unsigned long V_99 ;
int V_86 ;
int V_100 = 0 ;
unsigned V_101 ;
if ( ( F_11 ( V_14 + V_102 ) & 0x01 ) == 0 )
return V_103 ;
F_9 ( 0x00 , V_14 + V_93 ) ;
if ( ! V_92 || ! V_94 ) {
#if V_91
F_2 ( L_52 ,
V_92 , V_94 ) ;
#endif
return V_103 ;
}
if ( V_94 -> V_104 . V_105 & V_106 ) {
#if V_107
F_2 ( L_53 ) ;
#endif
}
#if V_96
++ V_97 ;
#endif
if ( V_94 -> V_104 . V_105 & V_108 ) {
V_86 = F_11 ( V_14 + V_102 ) ;
if ( ! ( V_86 & 0x02 ) ) {
#if V_91
F_2 ( L_54 ) ;
#endif
F_38 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
F_36 ( V_112 << 16 ) ;
F_39 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
return V_113 ;
}
V_94 -> V_104 . V_105 = V_114 ;
F_9 ( 0x40 | V_115 , V_14 + V_93 ) ;
F_9 ( 0x82 , V_14 + V_21 ) ;
F_9 ( V_73 | ( 1 << F_40 ( V_94 ) ) , V_14 + V_89 ) ;
F_9 ( 0x10 | V_23 , V_14 + V_24 ) ;
#if V_96
V_97 = 0 ;
#endif
return V_113 ;
} else if ( V_94 -> V_104 . V_105 & V_114 ) {
V_86 = F_11 ( V_14 + V_90 ) ;
if ( ! ( V_86 & 0x01 ) ) {
if ( F_35 ( F_40 ( V_94 ) ) ) {
#if V_91
F_2 ( L_55 ) ;
#endif
F_38 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
F_36 ( V_116 << 16 ) ;
F_39 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
return V_113 ;
} else {
#if V_91
F_2 ( L_56 ) ;
#endif
F_9 ( 0x10 | V_23 , V_14 + V_24 ) ;
}
}
V_94 -> V_104 . V_105 = V_117 ;
F_9 ( 0x90 | V_115 , V_14 + V_93 ) ;
F_9 ( 0x80 , V_14 + V_21 ) ;
#if V_96
V_97 = 0 ;
#endif
return V_113 ;
}
V_86 = F_11 ( V_14 + V_90 ) ;
if ( V_86 & 0x10 ) {
switch ( V_86 & 0x0e ) {
case 0x08 :
F_9 ( V_94 -> V_118 [ V_94 -> V_104 . V_119 ++ ] ,
V_14 + V_120 ) ;
#if V_91
F_2 ( L_57 ,
V_94 -> V_118 [ V_94 -> V_104 . V_119 - 1 ] ) ;
#endif
break;
case 0x00 :
if ( V_9 != V_10 && ! V_94 -> V_104 . V_121 ) {
V_94 -> V_104 . V_121 = - 1 ;
F_9 ( 0xd0 | V_23 , V_14 + V_24 ) ;
}
break;
case 0x04 :
if ( V_9 != V_10 && ! V_94 -> V_104 . V_121 ) {
V_94 -> V_104 . V_121 = 1 ;
F_9 ( 0x90 | V_23 , V_14 + V_24 ) ;
}
break;
case 0x0c :
V_94 -> V_104 . V_122 = F_11 ( V_14 + V_123 ) ;
#if V_91
F_2 ( L_58 , V_94 -> V_104 . V_122 ) ;
#endif
#if V_88
if ( V_94 -> V_104 . V_122
&& V_94 -> V_104 . V_122 != 2
&& V_94 -> V_104 . V_122 != 8 ) {
F_2 ( L_59 ,
V_94 -> V_109 -> V_124 ,
V_94 -> V_118 [ 0 ] ,
V_94 -> V_104 . V_122 ) ;
}
#endif
break;
case 0x0a :
F_9 ( V_125 , V_14 + V_120 ) ;
break;
case 0x0e :
V_94 -> V_104 . V_126 = F_11 ( V_14 + V_123 ) ;
#if V_91
F_2 ( L_60 , V_94 -> V_104 . V_126 ) ;
#endif
if ( ! V_94 -> V_104 . V_126 ) ++ V_100 ;
#if V_127 || V_91
if ( V_94 -> V_104 . V_126 ) {
F_2 ( L_61 ,
V_94 -> V_104 . V_126 ) ;
}
#endif
break;
}
}
if ( V_9 == V_10 && ! V_94 -> V_104 . V_121
&& ( V_94 -> V_104 . V_119 >= V_94 -> V_128 ) ) {
if( V_94 -> V_129 == V_130 )
{
V_94 -> V_104 . V_121 = - 1 ;
F_9 ( 0xd0 | V_23 , V_14 + V_24 ) ;
}
else
{
V_94 -> V_104 . V_121 = 1 ;
F_9 ( 0x90 | V_23 , V_14 + V_24 ) ;
}
}
if ( V_94 -> V_104 . V_121 == - 1 ) {
while ( ( V_101 = V_31 - F_41 ( V_14 + V_131 ) ) > 512 ) {
#if V_91
F_2 ( L_62 , V_101 ) ;
#endif
if ( V_101 > V_94 -> V_104 . V_132 )
V_101 = V_94 -> V_104 . V_132 ;
if ( V_101 > 0 ) {
#if V_91
F_2 ( L_63 , V_101 ) ;
#endif
if ( V_101 == 1 ) {
F_9 ( * V_94 -> V_104 . V_133 ++ , V_14 + V_134 ) ;
-- V_94 -> V_104 . V_132 ;
} else {
V_101 >>= 1 ;
F_42 ( V_14 + V_134 , V_94 -> V_104 . V_133 , V_101 ) ;
V_94 -> V_104 . V_133 += 2 * V_101 ;
V_94 -> V_104 . V_132 -= 2 * V_101 ;
}
}
if ( ! V_94 -> V_104 . V_132 ) {
if ( V_94 -> V_104 . V_135 ) {
-- V_94 -> V_104 . V_135 ;
++ V_94 -> V_104 . V_82 ;
V_94 -> V_104 . V_133 = F_43 ( V_94 -> V_104 . V_82 ) ;
V_94 -> V_104 . V_132 = V_94 -> V_104 . V_82 -> V_136 ;
} else
break;
}
}
}
if ( V_94 -> V_104 . V_121 == 1 ) {
while ( ( V_101 = F_41 ( V_14 + V_131 ) ) > 0 ) {
#if V_91
F_2 ( L_62 , V_101 ) ;
#endif
if ( V_101 > V_94 -> V_104 . V_132 )
V_101 = V_94 -> V_104 . V_132 ;
if ( V_101 ) {
#if V_91
F_2 ( L_64 , V_101 ) ;
#endif
if ( V_101 == 1 ) {
* V_94 -> V_104 . V_133 ++ = F_11 ( V_14 + V_137 ) ;
-- V_94 -> V_104 . V_132 ;
} else {
V_101 >>= 1 ;
F_44 ( V_14 + V_137 , V_94 -> V_104 . V_133 , V_101 ) ;
V_94 -> V_104 . V_133 += 2 * V_101 ;
V_94 -> V_104 . V_132 -= 2 * V_101 ;
}
}
if ( ! V_94 -> V_104 . V_132
&& V_94 -> V_104 . V_135 ) {
-- V_94 -> V_104 . V_135 ;
++ V_94 -> V_104 . V_82 ;
V_94 -> V_104 . V_133 = F_43 ( V_94 -> V_104 . V_82 ) ;
V_94 -> V_104 . V_132 = V_94 -> V_104 . V_82 -> V_136 ;
}
}
}
if ( V_100 ) {
#if V_91
F_2 ( L_65 , V_94 -> V_104 . V_121 ) ;
#endif
#if V_88
if ( V_94 -> V_118 [ 0 ] == V_138 && ! V_94 -> V_104 . V_122 ) {
char * V_139 = F_45 ( V_94 ) ;
if ( ( unsigned char ) ( * ( V_139 + 2 ) ) & 0x0f ) {
unsigned char V_140 ;
unsigned char V_141 ;
unsigned char V_142 ;
V_140 = ( unsigned char ) ( * ( V_139 + 2 ) ) & 0x0f ;
V_141 = ( unsigned char ) ( * ( V_139 + 12 ) ) ;
V_142 = ( unsigned char ) ( * ( V_139 + 13 ) ) ;
if ( V_140 != V_143
&& ! ( V_140 == V_144
&& V_141 == 0x04
&& ( ! V_142 || V_142 == 0x02 || V_142 == 0x01 ) )
&& ! ( V_140 == V_145 && ( V_141 == 0x25
|| V_141 == 0x24
|| ! V_141 ) ) )
F_2 ( L_66
L_67 ,
V_140 , V_141 , V_142 ) ;
}
}
#endif
#if V_91
F_2 ( L_68 ) ;
#endif
F_38 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
F_36 ( ( V_94 -> V_104 . V_122 & 0xff )
| ( ( V_94 -> V_104 . V_126 & 0xff ) << 8 ) | ( V_146 << 16 ) ) ;
F_39 ( V_94 -> V_109 -> V_110 -> V_111 , V_99 ) ;
#if V_91
F_2 ( L_69 ) ;
#endif
} else {
if ( V_94 -> V_104 . V_105 & V_147 ) {
F_9 ( 0xd0 | V_115 , V_14 + V_93 ) ;
F_9 ( 0x00 , V_14 + V_21 ) ;
} else {
F_9 ( 0x90 | V_115 , V_14 + V_93 ) ;
}
}
#if V_96
V_97 = 0 ;
#endif
return V_113 ;
}
static int F_46 ( struct V_148 * V_149 ,
void (* V_100)( struct V_148 * ) )
{
if ( V_92 ) {
F_37 ( L_70 ) ;
}
#if V_91
F_2 ( L_71 ,
V_149 -> V_85 ,
* ( unsigned char * ) V_149 -> V_118 ,
F_47 ( V_149 ) ,
F_48 ( V_149 ) ) ;
#endif
F_8 () ;
V_94 = V_149 ;
V_94 -> V_95 = V_100 ;
if ( F_47 ( V_94 ) ) {
V_94 -> V_104 . V_82 = F_45 ( V_94 ) ;
V_94 -> V_104 . V_133 = F_43 ( V_94 -> V_104 . V_82 ) ;
V_94 -> V_104 . V_132 = V_94 -> V_104 . V_82 -> V_136 ;
V_94 -> V_104 . V_135 = F_47 ( V_94 ) - 1 ;
} else {
V_94 -> V_104 . V_133 = NULL ;
V_94 -> V_104 . V_132 = 0 ;
V_94 -> V_104 . V_82 = NULL ;
V_94 -> V_104 . V_135 = 0 ;
}
V_94 -> V_104 . V_122 = 0 ;
V_94 -> V_104 . V_126 = 0 ;
V_94 -> V_104 . V_121 = 0 ;
V_94 -> V_104 . V_119 = 0 ;
V_94 -> V_104 . V_105 = V_108 ;
F_9 ( 0x00 , V_14 + V_93 ) ;
F_9 ( 0x00 , V_14 + V_21 ) ;
F_9 ( V_73 , V_14 + V_89 ) ;
++ V_92 ;
F_9 ( 0x20 , V_14 + V_93 ) ;
F_9 ( 0x14 | V_23 , V_14 + V_24 ) ;
return 0 ;
}
int F_49 ( struct V_148 * V_149 )
{
#if V_91 || V_88 || V_107
F_2 ( L_72 ) ;
#endif
if ( ! V_92 ) {
#if V_91 || V_88
F_2 ( L_73 ) ;
#endif
return V_150 ;
} else F_2 ( L_14 ) ;
#if V_107
F_50 ( V_149 ) ;
#endif
F_8 () ;
V_94 -> V_104 . V_105 |= V_106 ;
V_94 -> V_33 = V_151 << 16 ;
F_36 ( V_151 << 16 ) ;
return V_152 ;
}
int F_30 ( struct V_148 * V_149 )
{
unsigned long V_99 ;
F_51 ( V_99 ) ;
F_9 ( 1 , V_14 + V_21 ) ;
F_6 ( 2 ) ;
F_9 ( 0 , V_14 + V_21 ) ;
F_6 ( 115 ) ;
F_9 ( 0 , V_14 + V_22 ) ;
F_9 ( V_23 , V_14 + V_24 ) ;
F_52 ( V_99 ) ;
return V_152 ;
}
static int F_53 ( struct V_153 * V_154 ,
struct V_155 * V_156 ,
T_3 V_157 , int * V_158 )
{
int V_159 ;
int V_160 = V_157 ;
unsigned long V_161 ;
struct V_162 {
unsigned short V_163 ;
unsigned char V_164 ;
unsigned char V_165 ;
} V_32 ;
if ( F_54 ( V_156 -> V_166 ) != V_167 ) {
F_2 ( L_74 ) ;
return 0 ;
}
V_159 = F_55 ( V_156 -> V_166 ) >> 4 ;
if ( V_3 == 2 ) {
switch ( V_53 ) {
case 2 :
V_161 = 0x1f33 + V_159 * 25 ;
break;
case 3 :
V_161 = 0x1f36 + V_159 * 15 ;
break;
case 4 :
V_161 = 0x1f34 + V_159 * 15 ;
break;
default:
V_161 = 0x1f31 + V_159 * 25 ;
break;
}
F_56 ( & V_32 , V_54 + V_161 , sizeof( struct V_162 ) ) ;
V_158 [ 0 ] = V_32 . V_164 ;
V_158 [ 1 ] = V_32 . V_165 ;
V_158 [ 2 ] = V_32 . V_163 ;
} else if ( V_3 == 3
&& V_4 >= 0
&& V_4 < 4 ) {
F_56 ( & V_32 , V_54 + 0x1f71 + V_159 * 10 ,
sizeof( struct V_162 ) ) ;
V_158 [ 0 ] = V_32 . V_164 + 1 ;
V_158 [ 1 ] = V_32 . V_165 ;
V_158 [ 2 ] = V_32 . V_163 ;
} else {
unsigned char * V_45 = F_57 ( V_156 ) ;
if ( V_45 && V_45 [ 65 ] == 0xaa && V_45 [ 64 ] == 0x55
&& V_45 [ 4 ] ) {
V_158 [ 0 ] = V_45 [ 5 ] + 1 ;
V_158 [ 1 ] = V_45 [ 6 ] & 0x3f ;
} else {
if ( ( unsigned int ) V_160 >= 0x7e0000U ) {
V_158 [ 0 ] = 0xff ;
V_158 [ 1 ] = 0x3f ;
} else if ( ( unsigned int ) V_160 >= 0x200000U ) {
V_158 [ 0 ] = 0x80 ;
V_158 [ 1 ] = 0x3f ;
} else {
V_158 [ 0 ] = 0x40 ;
V_158 [ 1 ] = 0x20 ;
}
}
V_158 [ 2 ] = ( unsigned int ) V_160 / ( V_158 [ 0 ] * V_158 [ 1 ] ) ;
F_58 ( V_45 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 )
F_60 ( V_2 -> V_40 , V_2 ) ;
if ( V_2 -> V_74 && V_2 -> V_75 )
F_20 ( V_2 -> V_74 , V_2 -> V_75 ) ;
if ( V_13 )
F_27 ( V_69 ) ;
return 0 ;
}
