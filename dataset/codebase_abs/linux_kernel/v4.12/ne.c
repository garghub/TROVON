static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_3 ;
#ifdef F_2
int V_4 = V_2 -> V_5 ;
#endif
if ( V_3 > 0x1ff ) {
int V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 )
F_4 ( V_2 , L_1
L_2 , V_3 ) ;
return V_6 ;
}
else if ( V_3 != 0 )
return - V_7 ;
if ( F_5 () && ( F_6 ( V_2 ) == 0 ) )
return 0 ;
#ifdef F_2
for ( V_3 = 0 ; V_8 [ V_3 ] != 0 ; V_3 ++ ) {
int V_9 = V_8 [ V_3 ] ;
V_2 -> V_5 = V_4 ;
if ( F_3 ( V_2 , V_9 ) == 0 )
return 0 ;
}
#endif
return - V_10 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_12 [ V_11 ] . V_13 != 0 ; V_11 ++ ) {
struct V_14 * V_15 = NULL ;
while ( ( V_15 = F_7 ( NULL ,
V_12 [ V_11 ] . V_13 ,
V_12 [ V_11 ] . V_16 ,
V_15 ) ) ) {
if ( F_8 ( V_15 ) < 0 )
continue;
if ( F_9 ( V_15 ) < 0 ) {
F_10 ( V_15 ) ;
continue;
}
if ( ! F_11 ( V_15 , 0 ) || ! F_12 ( V_15 , 0 ) ) {
F_10 ( V_15 ) ;
continue;
}
V_2 -> V_3 = F_13 ( V_15 , 0 ) ;
V_2 -> V_5 = F_14 ( V_15 , 0 ) ;
F_15 ( V_2 ,
L_3 ,
( char * ) V_12 [ V_11 ] . V_17 ,
V_2 -> V_3 , V_2 -> V_5 ) ;
if ( F_3 ( V_2 , V_2 -> V_3 ) != 0 ) {
F_16 ( V_2 ,
L_4 ,
V_2 -> V_3 ) ;
F_10 ( V_15 ) ;
return - V_7 ;
}
V_18 . V_19 = ( unsigned long ) V_15 ;
break;
}
if ( ! V_15 )
continue;
return 0 ;
}
return - V_10 ;
}
static int T_1 F_3 ( struct V_1 * V_2 , unsigned long V_9 )
{
int V_11 ;
unsigned char V_20 [ 32 ] ;
int V_21 = 2 ;
const char * V_22 = NULL ;
int V_23 , V_24 ;
int V_25 , V_26 , V_27 , V_28 ;
int V_29 , V_6 ;
static unsigned V_30 ;
struct V_31 * V_32 = F_17 ( V_2 ) ;
if ( ! F_18 ( V_9 , V_33 , V_34 ) )
return - V_35 ;
V_29 = F_19 ( V_9 ) ;
if ( V_29 == 0xFF ) {
V_6 = - V_10 ;
goto V_36;
}
{
int V_37 ;
F_20 ( V_38 + V_39 + V_40 , V_9 + V_41 ) ;
V_37 = F_19 ( V_9 + 0x0d ) ;
F_20 ( 0xff , V_9 + 0x0d ) ;
F_20 ( V_38 + V_42 , V_9 + V_41 ) ;
F_19 ( V_9 + V_43 ) ;
if ( F_19 ( V_9 + V_43 ) != 0 ) {
F_20 ( V_29 , V_9 ) ;
F_20 ( V_37 , V_9 + 0x0d ) ;
V_6 = - V_10 ;
goto V_36;
}
}
if ( ( V_44 & V_45 ) && ( V_30 ++ == 0 ) )
F_15 ( V_2 , L_5 , V_46 , V_47 ) ;
F_15 ( V_2 , L_6 , V_9 ) ;
V_28 = ( ( V_2 -> V_3 != 0 ) && ( V_2 -> V_48 == V_49 ) ) ;
{
unsigned long V_50 = V_51 ;
F_21 ( F_22 ( V_9 + V_52 ) , V_9 + V_52 ) ;
while ( ( F_19 ( V_9 + V_53 ) & V_54 ) == 0 )
if ( F_23 ( V_51 , V_50 + 2 * V_55 / 100 ) ) {
if ( V_28 ) {
F_24 ( L_7 ) ;
break;
} else {
F_24 ( L_8 ) ;
V_6 = - V_10 ;
goto V_36;
}
}
F_20 ( 0xff , V_9 + V_53 ) ;
}
{
struct { unsigned char V_56 , V_57 ; } V_58 [] =
{
{ V_38 + V_42 + V_40 , V_41 } ,
{ 0x48 , V_59 } ,
{ 0x00 , V_60 } ,
{ 0x00 , V_61 } ,
{ 0x00 , V_62 } ,
{ 0xFF , V_53 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ 32 , V_60 } ,
{ 0x00 , V_61 } ,
{ 0x00 , V_67 } ,
{ 0x00 , V_68 } ,
{ V_69 + V_70 , V_41 } ,
} ;
for ( V_11 = 0 ; V_11 < F_25 ( V_58 ) ; V_11 ++ )
F_20 ( V_58 [ V_11 ] . V_56 , V_9 + V_58 [ V_11 ] . V_57 ) ;
}
for( V_11 = 0 ; V_11 < 32 ; V_11 += 2 ) {
V_20 [ V_11 ] = F_22 ( V_9 + V_71 ) ;
V_20 [ V_11 + 1 ] = F_22 ( V_9 + V_71 ) ;
if ( V_20 [ V_11 ] != V_20 [ V_11 + 1 ] )
V_21 = 1 ;
}
if ( V_21 == 2 )
{
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_20 [ V_11 ] = V_20 [ V_11 + V_11 ] ;
F_20 ( V_72 , V_9 + V_59 ) ;
V_23 = V_73 ;
if ( ( V_72 & 0x01 ) == 0 &&
F_22 ( V_9 + V_60 ) == 0x50 &&
F_22 ( V_9 + V_61 ) == 0x70 )
V_24 = 0x60 ;
else
V_24 = V_74 ;
} else {
V_23 = V_75 ;
V_24 = V_76 ;
}
#if F_26 ( V_77 ) || F_26 ( V_78 )
V_25 = ( ( V_20 [ 14 ] == 0x57 && V_20 [ 15 ] == 0x57 )
|| ( V_20 [ 14 ] == 0x42 && V_20 [ 15 ] == 0x42 ) ) ;
#else
V_25 = ( V_20 [ 14 ] == 0x57 && V_20 [ 15 ] == 0x57 ) ;
#endif
V_26 = ( V_20 [ 0 ] == 0x00 && V_20 [ 1 ] == 0x00 && V_20 [ 2 ] == 0x1d ) ;
V_27 = ( V_20 [ 14 ] == 0x49 && V_20 [ 15 ] == 0x00 ) ;
if ( V_25 || V_28 || V_27 ) {
V_22 = ( V_21 == 2 ) ? L_9 : L_10 ;
}
else if ( V_26 )
{
V_22 = ( V_21 == 2 ) ? L_11 : L_12 ;
V_23 = 0x01 ;
V_24 = ( V_21 == 2 ) ? 0x40 : 0x20 ;
}
else
{
#ifdef F_27
for ( V_11 = 0 ; V_79 [ V_11 ] . V_80 ; V_11 ++ )
{
if ( V_20 [ 0 ] == V_79 [ V_11 ] . V_81 [ 0 ] &&
V_20 [ 1 ] == V_79 [ V_11 ] . V_81 [ 1 ] &&
V_20 [ 2 ] == V_79 [ V_11 ] . V_81 [ 2 ] )
{
if ( V_21 == 2 )
{
V_22 = V_79 [ V_11 ] . V_82 ;
} else {
V_22 = V_79 [ V_11 ] . V_80 ;
}
break;
}
}
if ( V_79 [ V_11 ] . V_80 == NULL )
{
F_24 ( L_13 ,
V_20 [ 14 ] , V_20 [ 15 ] ) ;
V_6 = - V_7 ;
goto V_36;
}
#else
F_24 ( L_14 ) ;
V_6 = - V_7 ;
goto V_36;
#endif
}
if ( V_2 -> V_5 < 2 )
{
unsigned long V_83 = F_28 () ;
F_20 ( 0x50 , V_9 + V_62 ) ;
F_20 ( 0x00 , V_9 + V_60 ) ;
F_20 ( 0x00 , V_9 + V_61 ) ;
F_20 ( V_69 + V_70 , V_9 ) ;
F_29 ( 10 ) ;
F_20 ( 0x00 , V_9 + V_62 ) ;
V_2 -> V_5 = F_30 ( V_83 ) ;
if ( F_31 ( V_32 ) )
F_24 ( L_15 , V_2 -> V_5 ) ;
} else if ( V_2 -> V_5 == 2 )
V_2 -> V_5 = 9 ;
if ( ! V_2 -> V_5 ) {
F_24 ( L_16 ) ;
V_6 = - V_84 ;
goto V_36;
}
V_6 = F_32 ( V_2 -> V_5 , V_85 , 0 , V_22 , V_2 ) ;
if ( V_6 ) {
F_24 ( L_17 , V_2 -> V_5 , V_6 ) ;
goto V_36;
}
V_2 -> V_3 = V_9 ;
#ifdef V_77
F_20 ( V_38 + V_39 + V_40 ,
V_9 + V_41 ) ;
for ( V_11 = 0 ; V_11 < V_86 ; V_11 ++ ) {
V_2 -> V_87 [ V_11 ] = V_20 [ V_11 ]
= F_19 ( V_9 + F_33 ( V_11 ) ) ;
}
#else
for ( V_11 = 0 ; V_11 < V_86 ; V_11 ++ ) {
V_2 -> V_87 [ V_11 ] = V_20 [ V_11 ] ;
}
#endif
F_24 ( L_18 , V_2 -> V_87 ) ;
V_18 . V_22 = V_22 ;
V_18 . V_88 = V_23 ;
V_18 . V_24 = V_24 ;
V_18 . V_89 = ( V_21 == 2 && ( V_72 & 0x01 ) ) ;
V_18 . V_90 = V_23 + V_91 ;
#ifdef F_34
V_18 . V_24 = V_18 . V_88 + F_34 ;
#endif
V_18 . V_92 = & V_93 ;
V_18 . V_94 = & V_95 ;
V_18 . V_96 = & V_97 ;
V_18 . V_98 = & V_99 ;
V_18 . V_19 = 0 ;
V_2 -> V_100 = & V_101 ;
F_35 ( V_2 , 0 ) ;
V_32 -> V_102 = V_44 ;
V_6 = F_36 ( V_2 ) ;
if ( V_6 )
goto V_103;
F_15 ( V_2 , L_19 ,
V_22 , V_9 , V_2 -> V_5 ) ;
return 0 ;
V_103:
F_37 ( V_2 -> V_5 , V_2 ) ;
V_36:
F_38 ( V_9 , V_33 ) ;
return V_6 ;
}
static void V_93 ( struct V_1 * V_2 )
{
unsigned long V_50 = V_51 ;
struct V_31 * V_32 = F_17 ( V_2 ) ;
F_39 ( V_32 , V_104 , V_2 , L_20 , V_51 ) ;
F_21 ( F_22 ( V_105 + V_52 ) , V_105 + V_52 ) ;
V_18 . V_106 = 0 ;
V_18 . V_107 = 0 ;
while ( ( F_19 ( V_105 + V_53 ) & V_54 ) == 0 )
if ( F_23 ( V_51 , V_50 + 2 * V_55 / 100 ) ) {
F_16 ( V_2 , L_21 ) ;
break;
}
F_20 ( V_54 , V_105 + V_53 ) ;
}
static void V_99 ( struct V_1 * V_2 , struct V_108 * V_109 , int V_110 )
{
int V_111 = V_2 -> V_3 ;
if ( V_18 . V_107 )
{
F_16 ( V_2 , L_22
L_23 ,
V_18 . V_107 , V_18 . V_112 ) ;
return;
}
V_18 . V_107 |= 0x01 ;
F_20 ( V_38 + V_42 + V_70 , V_111 + V_113 ) ;
F_20 ( sizeof( struct V_108 ) , V_111 + V_60 ) ;
F_20 ( 0 , V_111 + V_61 ) ;
F_20 ( 0 , V_111 + V_67 ) ;
F_20 ( V_110 , V_111 + V_68 ) ;
F_20 ( V_69 + V_70 , V_111 + V_113 ) ;
if ( V_18 . V_89 )
F_40 ( V_105 + V_71 , V_109 , sizeof( struct V_108 ) >> 1 ) ;
else
F_41 ( V_105 + V_71 , V_109 , sizeof( struct V_108 ) ) ;
F_20 ( V_114 , V_111 + V_53 ) ;
V_18 . V_107 &= ~ 0x01 ;
F_42 ( & V_109 -> V_115 ) ;
}
static void V_95 ( struct V_1 * V_2 , int V_115 , struct V_116 * V_117 , int V_118 )
{
#ifdef F_43
int V_119 = V_115 ;
struct V_31 * V_32 = F_17 ( V_2 ) ;
#endif
int V_111 = V_2 -> V_3 ;
char * V_120 = V_117 -> V_121 ;
if ( V_18 . V_107 )
{
F_16 ( V_2 , L_24
L_23 ,
V_18 . V_107 , V_18 . V_112 ) ;
return;
}
V_18 . V_107 |= 0x01 ;
F_20 ( V_38 + V_42 + V_70 , V_111 + V_113 ) ;
F_20 ( V_115 & 0xff , V_111 + V_60 ) ;
F_20 ( V_115 >> 8 , V_111 + V_61 ) ;
F_20 ( V_118 & 0xff , V_111 + V_67 ) ;
F_20 ( V_118 >> 8 , V_111 + V_68 ) ;
F_20 ( V_69 + V_70 , V_111 + V_113 ) ;
if ( V_18 . V_89 )
{
F_40 ( V_105 + V_71 , V_120 , V_115 >> 1 ) ;
if ( V_115 & 0x01 )
{
V_120 [ V_115 - 1 ] = F_22 ( V_105 + V_71 ) ;
#ifdef F_43
V_119 ++ ;
#endif
}
} else {
F_41 ( V_105 + V_71 , V_120 , V_115 ) ;
}
#ifdef F_43
if ( F_44 ( V_32 ) )
{
int V_122 , V_123 = 20 ;
do {
int V_124 = F_19 ( V_111 + V_68 ) ;
int V_125 = F_19 ( V_111 + V_67 ) ;
V_122 = ( V_124 << 8 ) + V_125 ;
if ( ( ( V_118 + V_119 ) & 0xff ) == V_125 )
break;
} while ( -- V_123 > 0 );
if ( V_123 <= 0 )
F_4 ( V_2 , L_25
L_26 ,
V_118 + V_119 , V_122 ) ;
}
#endif
F_20 ( V_114 , V_111 + V_53 ) ;
V_18 . V_107 &= ~ 0x01 ;
}
static void V_97 ( struct V_1 * V_2 , int V_115 ,
const unsigned char * V_120 , const int V_23 )
{
int V_111 = V_105 ;
unsigned long V_126 ;
#ifdef F_43
int V_127 = 0 ;
struct V_31 * V_32 = F_17 ( V_2 ) ;
#endif
if ( V_18 . V_89 && ( V_115 & 0x01 ) )
V_115 ++ ;
if ( V_18 . V_107 )
{
F_16 ( V_2 , L_27
L_28 ,
V_18 . V_107 , V_18 . V_112 ) ;
return;
}
V_18 . V_107 |= 0x01 ;
F_20 ( V_42 + V_70 + V_38 , V_111 + V_113 ) ;
#ifdef F_43
V_128:
#endif
#ifdef F_45
F_20 ( 0x42 , V_111 + V_60 ) ;
F_20 ( 0x00 , V_111 + V_61 ) ;
F_20 ( 0x42 , V_111 + V_67 ) ;
F_20 ( 0x00 , V_111 + V_68 ) ;
F_20 ( V_69 + V_70 , V_111 + V_113 ) ;
F_46 ( 6 ) ;
#endif
F_20 ( V_114 , V_111 + V_53 ) ;
F_20 ( V_115 & 0xff , V_111 + V_60 ) ;
F_20 ( V_115 >> 8 , V_111 + V_61 ) ;
F_20 ( 0x00 , V_111 + V_67 ) ;
F_20 ( V_23 , V_111 + V_68 ) ;
F_20 ( V_129 + V_70 , V_111 + V_113 ) ;
if ( V_18 . V_89 ) {
F_47 ( V_105 + V_71 , V_120 , V_115 >> 1 ) ;
} else {
F_48 ( V_105 + V_71 , V_120 , V_115 ) ;
}
V_126 = V_51 ;
#ifdef F_43
if ( F_49 ( V_32 ) )
{
int V_122 , V_123 = 20 ;
do {
int V_124 = F_19 ( V_111 + V_68 ) ;
int V_125 = F_19 ( V_111 + V_67 ) ;
V_122 = ( V_124 << 8 ) + V_125 ;
if ( ( V_23 << 8 ) + V_115 == V_122 )
break;
} while ( -- V_123 > 0 );
if ( V_123 <= 0 )
{
F_4 ( V_2 , L_29
L_26 ,
( V_23 << 8 ) + V_115 , V_122 ) ;
if ( V_127 ++ == 0 )
goto V_128;
}
}
#endif
while ( ( F_19 ( V_111 + V_53 ) & V_114 ) == 0 )
if ( F_23 ( V_51 , V_126 + 2 * V_55 / 100 ) ) {
F_4 ( V_2 , L_30 ) ;
V_93 ( V_2 ) ;
F_35 ( V_2 , 1 ) ;
break;
}
F_20 ( V_114 , V_111 + V_53 ) ;
V_18 . V_107 &= ~ 0x01 ;
}
static int T_1 F_50 ( struct V_130 * V_131 )
{
struct V_1 * V_2 ;
int V_132 , V_133 = V_131 -> V_134 ;
struct V_135 * V_136 ;
V_2 = F_51 () ;
if ( ! V_2 )
return - V_137 ;
V_136 = F_52 ( V_131 , V_138 , 0 ) ;
if ( V_136 ) {
V_2 -> V_3 = V_136 -> V_139 ;
V_2 -> V_5 = F_53 ( V_131 , 0 ) ;
} else {
if ( V_133 < 0 || V_133 >= V_140 ) {
F_54 ( V_2 ) ;
return - V_141 ;
}
V_2 -> V_3 = V_142 [ V_133 ] ;
V_2 -> V_5 = V_5 [ V_133 ] ;
V_2 -> V_48 = V_143 [ V_133 ] ;
}
F_55 ( V_2 , & V_131 -> V_2 ) ;
V_132 = F_1 ( V_2 ) ;
if ( V_132 ) {
F_54 ( V_2 ) ;
return V_132 ;
}
F_56 ( V_131 , V_2 ) ;
if ( ! V_136 ) {
V_142 [ V_133 ] = V_2 -> V_3 ;
V_5 [ V_133 ] = V_2 -> V_5 ;
}
return 0 ;
}
static int F_57 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_58 ( V_131 ) ;
if ( V_2 ) {
struct V_14 * V_15 = (struct V_14 * ) V_18 . V_19 ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_15 )
F_10 ( V_15 ) ;
V_18 . V_19 = 0 ;
F_37 ( V_2 -> V_5 , V_2 ) ;
F_38 ( V_2 -> V_3 , V_33 ) ;
F_54 ( V_2 ) ;
}
return 0 ;
}
static void F_61 ( int V_144 )
{
int V_133 ;
struct V_130 * V_131 ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
V_131 = V_145 [ V_133 ] ;
if ( V_131 && ( ! F_58 ( V_131 ) || V_144 ) ) {
F_57 ( V_131 ) ;
F_62 ( V_131 ) ;
V_145 [ V_133 ] = NULL ;
}
}
}
static int F_63 ( struct V_130 * V_131 , T_2 V_146 )
{
struct V_1 * V_2 = F_58 ( V_131 ) ;
if ( F_64 ( V_2 ) ) {
struct V_14 * V_15 = (struct V_14 * ) V_18 . V_19 ;
F_59 ( V_2 ) ;
if ( V_15 )
F_65 ( V_15 ) ;
}
return 0 ;
}
static int F_66 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_58 ( V_131 ) ;
if ( F_64 ( V_2 ) ) {
struct V_14 * V_15 = (struct V_14 * ) V_18 . V_19 ;
if ( V_15 )
F_67 ( V_15 ) ;
V_93 ( V_2 ) ;
F_35 ( V_2 , 1 ) ;
F_68 ( V_2 ) ;
}
return 0 ;
}
static void T_1 F_69 ( void )
{
int V_133 ;
struct V_130 * V_131 ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
if ( V_145 [ V_133 ] )
continue;
V_131 = F_70 (
V_34 , V_133 , NULL , 0 ) ;
if ( F_71 ( V_131 ) )
continue;
V_145 [ V_133 ] = V_131 ;
}
}
int T_1 F_72 ( void )
{
int V_147 ;
F_69 () ;
V_147 = F_73 ( & V_148 , F_50 ) ;
if ( V_147 ) {
if ( V_142 [ 0 ] == 0 )
F_74 ( L_31
L_32 ) ;
F_61 ( 1 ) ;
return V_147 ;
}
F_61 ( 0 ) ;
return V_147 ;
}
static int T_1 F_75 ( void )
{
int V_147 = F_73 ( & V_148 , F_50 ) ;
F_61 ( 0 ) ;
return V_147 ;
}
struct V_1 * T_1 F_76 ( int V_149 )
{
int V_133 ;
struct V_1 * V_2 ;
V_133 = 0 ;
while ( ( V_145 [ V_133 ] && F_58 ( V_145 [ V_133 ] ) ) ||
V_142 [ V_133 ] ) {
if ( ++ V_133 == V_140 )
return F_77 ( - V_137 ) ;
}
V_2 = F_51 () ;
if ( ! V_2 )
return F_77 ( - V_137 ) ;
sprintf ( V_2 -> V_22 , L_33 , V_149 ) ;
F_78 ( V_2 ) ;
V_142 [ V_133 ] = V_2 -> V_3 ;
V_5 [ V_133 ] = V_2 -> V_5 ;
V_143 [ V_133 ] = V_2 -> V_48 ;
F_54 ( V_2 ) ;
F_69 () ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
if ( V_145 [ V_133 ] ) {
V_2 = F_58 ( V_145 [ V_133 ] ) ;
if ( V_2 )
return V_2 ;
}
}
return F_77 ( - V_10 ) ;
}
static void T_3 F_79 ( void )
{
F_80 ( & V_148 ) ;
F_61 ( 1 ) ;
}
