static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_3 ;
#ifdef F_2
int V_4 = V_2 -> V_5 ;
#endif
if ( V_3 > 0x1ff ) {
int V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 )
F_4 ( V_7 L_1
L_2 , V_3 ) ;
return V_6 ;
}
else if ( V_3 != 0 )
return - V_8 ;
if ( F_5 () && ( F_6 ( V_2 ) == 0 ) )
return 0 ;
#ifdef F_2
for ( V_3 = 0 ; V_9 [ V_3 ] != 0 ; V_3 ++ ) {
int V_10 = V_9 [ V_3 ] ;
V_2 -> V_5 = V_4 ;
if ( F_3 ( V_2 , V_10 ) == 0 )
return 0 ;
}
#endif
return - V_11 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_13 [ V_12 ] . V_14 != 0 ; V_12 ++ ) {
struct V_15 * V_16 = NULL ;
while ( ( V_16 = F_7 ( NULL ,
V_13 [ V_12 ] . V_14 ,
V_13 [ V_12 ] . V_17 ,
V_16 ) ) ) {
if ( F_8 ( V_16 ) < 0 )
continue;
if ( F_9 ( V_16 ) < 0 ) {
F_10 ( V_16 ) ;
continue;
}
if ( ! F_11 ( V_16 , 0 ) || ! F_12 ( V_16 , 0 ) ) {
F_10 ( V_16 ) ;
continue;
}
V_2 -> V_3 = F_13 ( V_16 , 0 ) ;
V_2 -> V_5 = F_14 ( V_16 , 0 ) ;
F_4 ( V_18 L_3 ,
( char * ) V_13 [ V_12 ] . V_19 ,
V_2 -> V_3 , V_2 -> V_5 ) ;
if ( F_3 ( V_2 , V_2 -> V_3 ) != 0 ) {
F_4 ( V_20 L_4 , V_2 -> V_3 ) ;
F_10 ( V_16 ) ;
return - V_8 ;
}
V_21 . V_22 = ( unsigned long ) V_16 ;
break;
}
if ( ! V_16 )
continue;
return 0 ;
}
return - V_11 ;
}
static int T_1 F_3 ( struct V_1 * V_2 , unsigned long V_10 )
{
int V_12 ;
unsigned char V_23 [ 32 ] ;
int V_24 = 2 ;
const char * V_25 = NULL ;
int V_26 , V_27 ;
int V_28 , V_29 , V_30 , V_31 ;
int V_32 , V_6 ;
static unsigned V_33 ;
if ( ! F_15 ( V_10 , V_34 , V_35 ) )
return - V_36 ;
V_32 = F_16 ( V_10 ) ;
if ( V_32 == 0xFF ) {
V_6 = - V_11 ;
goto V_37;
}
{
int V_38 ;
F_17 ( V_39 + V_40 + V_41 , V_10 + V_42 ) ;
V_38 = F_16 ( V_10 + 0x0d ) ;
F_17 ( 0xff , V_10 + 0x0d ) ;
F_17 ( V_39 + V_43 , V_10 + V_42 ) ;
F_16 ( V_10 + V_44 ) ;
if ( F_16 ( V_10 + V_44 ) != 0 ) {
F_17 ( V_32 , V_10 ) ;
F_17 ( V_38 , V_10 + 0x0d ) ;
V_6 = - V_11 ;
goto V_37;
}
}
if ( V_45 && V_33 ++ == 0 )
F_4 ( V_18 L_5 , V_46 , V_47 ) ;
F_4 ( V_18 L_6 , V_10 ) ;
V_31 = ( ( V_2 -> V_3 != 0 ) && ( V_2 -> V_48 == V_49 ) ) ;
{
unsigned long V_50 = V_51 ;
F_18 ( F_19 ( V_10 + V_52 ) , V_10 + V_52 ) ;
while ( ( F_16 ( V_10 + V_53 ) & V_54 ) == 0 )
if ( F_20 ( V_51 , V_50 + 2 * V_55 / 100 ) ) {
if ( V_31 ) {
F_4 ( L_7 ) ;
break;
} else {
F_4 ( L_8 ) ;
V_6 = - V_11 ;
goto V_37;
}
}
F_17 ( 0xff , V_10 + V_53 ) ;
}
{
struct { unsigned char V_56 , V_57 ; } V_58 [] =
{
{ V_39 + V_43 + V_41 , V_42 } ,
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
{ V_69 + V_70 , V_42 } ,
} ;
for ( V_12 = 0 ; V_12 < F_21 ( V_58 ) ; V_12 ++ )
F_17 ( V_58 [ V_12 ] . V_56 , V_10 + V_58 [ V_12 ] . V_57 ) ;
}
for( V_12 = 0 ; V_12 < 32 ; V_12 += 2 ) {
V_23 [ V_12 ] = F_19 ( V_10 + V_71 ) ;
V_23 [ V_12 + 1 ] = F_19 ( V_10 + V_71 ) ;
if ( V_23 [ V_12 ] != V_23 [ V_12 + 1 ] )
V_24 = 1 ;
}
if ( V_24 == 2 )
{
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_23 [ V_12 ] = V_23 [ V_12 + V_12 ] ;
F_17 ( V_72 , V_10 + V_59 ) ;
V_26 = V_73 ;
if ( ( V_72 & 0x01 ) == 0 &&
F_19 ( V_10 + V_60 ) == 0x50 &&
F_19 ( V_10 + V_61 ) == 0x70 )
V_27 = 0x60 ;
else
V_27 = V_74 ;
} else {
V_26 = V_75 ;
V_27 = V_76 ;
}
#if F_22 ( V_77 ) || F_22 ( V_78 )
V_28 = ( ( V_23 [ 14 ] == 0x57 && V_23 [ 15 ] == 0x57 )
|| ( V_23 [ 14 ] == 0x42 && V_23 [ 15 ] == 0x42 ) ) ;
#else
V_28 = ( V_23 [ 14 ] == 0x57 && V_23 [ 15 ] == 0x57 ) ;
#endif
V_29 = ( V_23 [ 0 ] == 0x00 && V_23 [ 1 ] == 0x00 && V_23 [ 2 ] == 0x1d ) ;
V_30 = ( V_23 [ 14 ] == 0x49 && V_23 [ 15 ] == 0x00 ) ;
if ( V_28 || V_31 || V_30 ) {
V_25 = ( V_24 == 2 ) ? L_9 : L_10 ;
}
else if ( V_29 )
{
V_25 = ( V_24 == 2 ) ? L_11 : L_12 ;
V_26 = 0x01 ;
V_27 = ( V_24 == 2 ) ? 0x40 : 0x20 ;
}
else
{
#ifdef F_23
for ( V_12 = 0 ; V_79 [ V_12 ] . V_80 ; V_12 ++ )
{
if ( V_23 [ 0 ] == V_79 [ V_12 ] . V_81 [ 0 ] &&
V_23 [ 1 ] == V_79 [ V_12 ] . V_81 [ 1 ] &&
V_23 [ 2 ] == V_79 [ V_12 ] . V_81 [ 2 ] )
{
if ( V_24 == 2 )
{
V_25 = V_79 [ V_12 ] . V_82 ;
} else {
V_25 = V_79 [ V_12 ] . V_80 ;
}
break;
}
}
if ( V_79 [ V_12 ] . V_80 == NULL )
{
F_4 ( L_13 ,
V_23 [ 14 ] , V_23 [ 15 ] ) ;
V_6 = - V_8 ;
goto V_37;
}
#else
F_4 ( L_14 ) ;
V_6 = - V_8 ;
goto V_37;
#endif
}
if ( V_2 -> V_5 < 2 )
{
unsigned long V_83 = F_24 () ;
F_17 ( 0x50 , V_10 + V_62 ) ;
F_17 ( 0x00 , V_10 + V_60 ) ;
F_17 ( 0x00 , V_10 + V_61 ) ;
F_17 ( V_69 + V_70 , V_10 ) ;
F_25 ( 10 ) ;
F_17 ( 0x00 , V_10 + V_62 ) ;
V_2 -> V_5 = F_26 ( V_83 ) ;
if ( V_45 > 2 )
F_4 ( L_15 , V_2 -> V_5 ) ;
} else if ( V_2 -> V_5 == 2 )
V_2 -> V_5 = 9 ;
if ( ! V_2 -> V_5 ) {
F_4 ( L_16 ) ;
V_6 = - V_84 ;
goto V_37;
}
V_6 = F_27 ( V_2 -> V_5 , V_85 , 0 , V_25 , V_2 ) ;
if ( V_6 ) {
F_4 ( L_17 , V_2 -> V_5 , V_6 ) ;
goto V_37;
}
V_2 -> V_3 = V_10 ;
#ifdef V_77
F_17 ( V_39 + V_40 + V_41 ,
V_10 + V_42 ) ;
for ( V_12 = 0 ; V_12 < V_86 ; V_12 ++ ) {
V_2 -> V_87 [ V_12 ] = V_23 [ V_12 ]
= F_16 ( V_10 + F_28 ( V_12 ) ) ;
}
#else
for ( V_12 = 0 ; V_12 < V_86 ; V_12 ++ ) {
V_2 -> V_87 [ V_12 ] = V_23 [ V_12 ] ;
}
#endif
F_4 ( L_18 , V_2 -> V_87 ) ;
V_21 . V_25 = V_25 ;
V_21 . V_88 = V_26 ;
V_21 . V_27 = V_27 ;
V_21 . V_89 = ( V_24 == 2 && ( V_72 & 0x01 ) ) ;
V_21 . V_90 = V_26 + V_91 ;
#ifdef F_29
V_21 . V_27 = V_21 . V_88 + F_29 ;
#endif
V_21 . V_92 = & V_93 ;
V_21 . V_94 = & V_95 ;
V_21 . V_96 = & V_97 ;
V_21 . V_98 = & V_99 ;
V_21 . V_22 = 0 ;
V_2 -> V_100 = & V_101 ;
F_30 ( V_2 , 0 ) ;
V_6 = F_31 ( V_2 ) ;
if ( V_6 )
goto V_102;
F_4 ( V_18 L_19 ,
V_2 -> V_25 , V_25 , V_10 , V_2 -> V_5 ) ;
return 0 ;
V_102:
F_32 ( V_2 -> V_5 , V_2 ) ;
V_37:
F_33 ( V_10 , V_34 ) ;
return V_6 ;
}
static void V_93 ( struct V_1 * V_2 )
{
unsigned long V_50 = V_51 ;
if ( V_45 > 1 )
F_4 ( V_103 L_20 , V_51 ) ;
F_18 ( F_19 ( V_104 + V_52 ) , V_104 + V_52 ) ;
V_21 . V_105 = 0 ;
V_21 . V_106 = 0 ;
while ( ( F_16 ( V_104 + V_53 ) & V_54 ) == 0 )
if ( F_20 ( V_51 , V_50 + 2 * V_55 / 100 ) ) {
F_4 ( V_7 L_21 , V_2 -> V_25 ) ;
break;
}
F_17 ( V_54 , V_104 + V_53 ) ;
}
static void V_99 ( struct V_1 * V_2 , struct V_107 * V_108 , int V_109 )
{
int V_110 = V_2 -> V_3 ;
if ( V_21 . V_106 )
{
F_4 ( V_111 L_22
L_23 ,
V_2 -> V_25 , V_21 . V_106 , V_21 . V_112 ) ;
return;
}
V_21 . V_106 |= 0x01 ;
F_17 ( V_39 + V_43 + V_70 , V_110 + V_113 ) ;
F_17 ( sizeof( struct V_107 ) , V_110 + V_60 ) ;
F_17 ( 0 , V_110 + V_61 ) ;
F_17 ( 0 , V_110 + V_67 ) ;
F_17 ( V_109 , V_110 + V_68 ) ;
F_17 ( V_69 + V_70 , V_110 + V_113 ) ;
if ( V_21 . V_89 )
F_34 ( V_104 + V_71 , V_108 , sizeof( struct V_107 ) >> 1 ) ;
else
F_35 ( V_104 + V_71 , V_108 , sizeof( struct V_107 ) ) ;
F_17 ( V_114 , V_110 + V_53 ) ;
V_21 . V_106 &= ~ 0x01 ;
F_36 ( & V_108 -> V_115 ) ;
}
static void V_95 ( struct V_1 * V_2 , int V_115 , struct V_116 * V_117 , int V_118 )
{
#ifdef F_37
int V_119 = V_115 ;
#endif
int V_110 = V_2 -> V_3 ;
char * V_120 = V_117 -> V_121 ;
if ( V_21 . V_106 )
{
F_4 ( V_111 L_24
L_23 ,
V_2 -> V_25 , V_21 . V_106 , V_21 . V_112 ) ;
return;
}
V_21 . V_106 |= 0x01 ;
F_17 ( V_39 + V_43 + V_70 , V_110 + V_113 ) ;
F_17 ( V_115 & 0xff , V_110 + V_60 ) ;
F_17 ( V_115 >> 8 , V_110 + V_61 ) ;
F_17 ( V_118 & 0xff , V_110 + V_67 ) ;
F_17 ( V_118 >> 8 , V_110 + V_68 ) ;
F_17 ( V_69 + V_70 , V_110 + V_113 ) ;
if ( V_21 . V_89 )
{
F_34 ( V_104 + V_71 , V_120 , V_115 >> 1 ) ;
if ( V_115 & 0x01 )
{
V_120 [ V_115 - 1 ] = F_19 ( V_104 + V_71 ) ;
#ifdef F_37
V_119 ++ ;
#endif
}
} else {
F_35 ( V_104 + V_71 , V_120 , V_115 ) ;
}
#ifdef F_37
if ( V_45 > 1 )
{
int V_122 , V_123 = 20 ;
do {
int V_124 = F_16 ( V_110 + V_68 ) ;
int V_125 = F_16 ( V_110 + V_67 ) ;
V_122 = ( V_124 << 8 ) + V_125 ;
if ( ( ( V_118 + V_119 ) & 0xff ) == V_125 )
break;
} while ( -- V_123 > 0 );
if ( V_123 <= 0 )
F_4 ( V_7 L_25
L_26 ,
V_2 -> V_25 , V_118 + V_119 , V_122 ) ;
}
#endif
F_17 ( V_114 , V_110 + V_53 ) ;
V_21 . V_106 &= ~ 0x01 ;
}
static void V_97 ( struct V_1 * V_2 , int V_115 ,
const unsigned char * V_120 , const int V_26 )
{
int V_110 = V_104 ;
unsigned long V_126 ;
#ifdef F_37
int V_127 = 0 ;
#endif
if ( V_21 . V_89 && ( V_115 & 0x01 ) )
V_115 ++ ;
if ( V_21 . V_106 )
{
F_4 ( V_111 L_27
L_28 ,
V_2 -> V_25 , V_21 . V_106 , V_21 . V_112 ) ;
return;
}
V_21 . V_106 |= 0x01 ;
F_17 ( V_43 + V_70 + V_39 , V_110 + V_113 ) ;
#ifdef F_37
V_128:
#endif
#ifdef F_38
F_17 ( 0x42 , V_110 + V_60 ) ;
F_17 ( 0x00 , V_110 + V_61 ) ;
F_17 ( 0x42 , V_110 + V_67 ) ;
F_17 ( 0x00 , V_110 + V_68 ) ;
F_17 ( V_69 + V_70 , V_110 + V_113 ) ;
F_39 ( 6 ) ;
#endif
F_17 ( V_114 , V_110 + V_53 ) ;
F_17 ( V_115 & 0xff , V_110 + V_60 ) ;
F_17 ( V_115 >> 8 , V_110 + V_61 ) ;
F_17 ( 0x00 , V_110 + V_67 ) ;
F_17 ( V_26 , V_110 + V_68 ) ;
F_17 ( V_129 + V_70 , V_110 + V_113 ) ;
if ( V_21 . V_89 ) {
F_40 ( V_104 + V_71 , V_120 , V_115 >> 1 ) ;
} else {
F_41 ( V_104 + V_71 , V_120 , V_115 ) ;
}
V_126 = V_51 ;
#ifdef F_37
if ( V_45 > 1 )
{
int V_122 , V_123 = 20 ;
do {
int V_124 = F_16 ( V_110 + V_68 ) ;
int V_125 = F_16 ( V_110 + V_67 ) ;
V_122 = ( V_124 << 8 ) + V_125 ;
if ( ( V_26 << 8 ) + V_115 == V_122 )
break;
} while ( -- V_123 > 0 );
if ( V_123 <= 0 )
{
F_4 ( V_7 L_29
L_26 ,
V_2 -> V_25 , ( V_26 << 8 ) + V_115 , V_122 ) ;
if ( V_127 ++ == 0 )
goto V_128;
}
}
#endif
while ( ( F_16 ( V_110 + V_53 ) & V_114 ) == 0 )
if ( F_20 ( V_51 , V_126 + 2 * V_55 / 100 ) ) {
F_4 ( V_7 L_30 , V_2 -> V_25 ) ;
V_93 ( V_2 ) ;
F_30 ( V_2 , 1 ) ;
break;
}
F_17 ( V_114 , V_110 + V_53 ) ;
V_21 . V_106 &= ~ 0x01 ;
}
static int T_1 F_42 ( struct V_130 * V_131 )
{
struct V_1 * V_2 ;
int V_132 , V_133 = V_131 -> V_134 ;
struct V_135 * V_136 ;
V_2 = F_43 () ;
if ( ! V_2 )
return - V_137 ;
V_136 = F_44 ( V_131 , V_138 , 0 ) ;
if ( V_136 ) {
V_2 -> V_3 = V_136 -> V_139 ;
V_2 -> V_5 = F_45 ( V_131 , 0 ) ;
} else {
if ( V_133 < 0 || V_133 >= V_140 ) {
F_46 ( V_2 ) ;
return - V_141 ;
}
V_2 -> V_3 = V_142 [ V_133 ] ;
V_2 -> V_5 = V_5 [ V_133 ] ;
V_2 -> V_48 = V_143 [ V_133 ] ;
}
F_47 ( V_2 , & V_131 -> V_2 ) ;
V_132 = F_1 ( V_2 ) ;
if ( V_132 ) {
F_46 ( V_2 ) ;
return V_132 ;
}
F_48 ( V_131 , V_2 ) ;
if ( ! V_136 ) {
V_142 [ V_133 ] = V_2 -> V_3 ;
V_5 [ V_133 ] = V_2 -> V_5 ;
}
return 0 ;
}
static int F_49 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_50 ( V_131 ) ;
if ( V_2 ) {
struct V_15 * V_16 = (struct V_15 * ) V_21 . V_22 ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_16 )
F_10 ( V_16 ) ;
V_21 . V_22 = 0 ;
F_32 ( V_2 -> V_5 , V_2 ) ;
F_33 ( V_2 -> V_3 , V_34 ) ;
F_46 ( V_2 ) ;
}
return 0 ;
}
static void F_53 ( int V_144 )
{
int V_133 ;
struct V_130 * V_131 ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
V_131 = V_145 [ V_133 ] ;
if ( V_131 && ( ! F_50 ( V_131 ) || V_144 ) ) {
F_49 ( V_131 ) ;
F_54 ( V_131 ) ;
V_145 [ V_133 ] = NULL ;
}
}
}
static int F_55 ( struct V_130 * V_131 , T_2 V_146 )
{
struct V_1 * V_2 = F_50 ( V_131 ) ;
if ( F_56 ( V_2 ) ) {
struct V_15 * V_16 = (struct V_15 * ) V_21 . V_22 ;
F_51 ( V_2 ) ;
if ( V_16 )
F_57 ( V_16 ) ;
}
return 0 ;
}
static int F_58 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_50 ( V_131 ) ;
if ( F_56 ( V_2 ) ) {
struct V_15 * V_16 = (struct V_15 * ) V_21 . V_22 ;
if ( V_16 )
F_59 ( V_16 ) ;
V_93 ( V_2 ) ;
F_30 ( V_2 , 1 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static void T_1 F_61 ( void )
{
int V_133 ;
struct V_130 * V_131 ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
if ( V_145 [ V_133 ] )
continue;
V_131 = F_62 (
V_35 , V_133 , NULL , 0 ) ;
if ( F_63 ( V_131 ) )
continue;
V_145 [ V_133 ] = V_131 ;
}
}
int T_1 F_64 ( void )
{
int V_147 ;
F_61 () ;
V_147 = F_65 ( & V_148 , F_42 ) ;
if ( V_147 ) {
if ( V_142 [ 0 ] == 0 )
F_4 ( V_149 L_31
L_32 ) ;
F_53 ( 1 ) ;
return V_147 ;
}
F_53 ( 0 ) ;
return V_147 ;
}
static int T_1 F_66 ( void )
{
int V_147 = F_65 ( & V_148 , F_42 ) ;
F_53 ( 0 ) ;
return V_147 ;
}
struct V_1 * T_1 F_67 ( int V_150 )
{
int V_133 ;
struct V_1 * V_2 ;
V_133 = 0 ;
while ( ( V_145 [ V_133 ] && F_50 ( V_145 [ V_133 ] ) ) ||
V_142 [ V_133 ] ) {
if ( ++ V_133 == V_140 )
return F_68 ( - V_137 ) ;
}
V_2 = F_43 () ;
if ( ! V_2 )
return F_68 ( - V_137 ) ;
sprintf ( V_2 -> V_25 , L_33 , V_150 ) ;
F_69 ( V_2 ) ;
V_142 [ V_133 ] = V_2 -> V_3 ;
V_5 [ V_133 ] = V_2 -> V_5 ;
V_143 [ V_133 ] = V_2 -> V_48 ;
F_46 ( V_2 ) ;
F_61 () ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
if ( V_145 [ V_133 ] ) {
V_2 = F_50 ( V_145 [ V_133 ] ) ;
if ( V_2 )
return V_2 ;
}
}
return F_68 ( - V_11 ) ;
}
static void T_3 F_70 ( void )
{
F_71 ( & V_148 ) ;
F_53 ( 1 ) ;
}
