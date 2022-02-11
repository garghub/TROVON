int T_1 F_1 ( void )
{
T_2 V_1 ;
const T_3 * V_2 ;
if ( V_3 != 0 )
return 1 ;
V_4 = F_2 ( NULL , L_1 ) ;
if ( V_4 == NULL )
return 0 ;
V_2 = F_3 ( V_4 , L_2 , NULL ) ;
if ( V_2 == NULL ) {
F_4 ( V_5 L_3 ) ;
goto V_6;
}
V_1 = F_5 ( V_4 , V_2 ) ;
if ( V_1 == V_7 ) {
F_4 ( V_5 L_4 ) ;
goto V_6;
}
F_6 ( & V_8 ) ;
V_9 = 1 ;
V_10 = V_11 |
V_12 |
V_13 |
V_14 ;
if ( V_4 -> V_15 -> V_16 && ( ( strcmp ( V_4 -> V_15 -> V_16 , L_5 ) == 0 )
|| F_7 ( V_4 -> V_15 , L_5 ) ) )
V_17 = V_18 ;
else if ( F_7 ( V_4 -> V_15 , L_6 ) )
V_17 = V_19 ;
else if ( F_7 ( V_4 -> V_15 , L_7 ) )
V_17 = V_20 ;
else if ( F_7 ( V_4 -> V_15 , L_8 )
|| F_7 ( V_4 -> V_15 , L_9 ) ) {
struct V_21 * V_22 ;
struct V_21 * V_23 ;
T_2 V_24 = V_7 ;
V_17 = V_25 ;
V_23 = F_8 ( NULL , L_10 ) ;
V_9 = ( V_23 != NULL ) ;
F_9 ( V_23 ) ;
V_10 = V_11 |
V_12 |
V_13 |
V_14 |
V_26 ;
V_22 = F_2 ( NULL , L_11 ) ;
if ( V_22 ) {
V_2 = F_3 ( V_22 , L_2 , NULL ) ;
if ( V_2 )
V_24 = F_5 ( V_22 , V_2 ) ;
if ( V_24 != V_7 )
V_27 = F_10 ( V_24 , 0x10 ) ;
F_9 ( V_22 ) ;
}
if ( V_27 == NULL ) {
F_4 ( V_5 L_12 ) ;
goto V_6;
}
} else
V_17 = V_28 ;
V_3 = F_10 ( V_1 , 0x2000 ) ;
if ( V_3 == NULL ) {
F_4 ( V_5 L_13 ) ;
goto V_29;
}
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
V_33 = V_34 ;
if ( ! F_12 () )
goto V_35;
F_4 ( V_36 L_14 ,
V_37 , V_38 [ V_17 ] , V_39 ) ;
V_40 = V_41 ;
return 1 ;
V_35:
F_13 ( V_3 ) ;
V_3 = NULL ;
V_29:
F_13 ( V_27 ) ;
V_27 = NULL ;
V_6:
F_9 ( V_4 ) ;
V_4 = NULL ;
return 0 ;
}
static int F_14 ( void )
{
return V_4 == NULL ? - V_42 : 0 ;
}
static int T_1 F_15 ( void )
{
if ( V_4 == NULL )
return - V_42 ;
return 0 ;
}
static int T_1 F_16 ( void )
{
unsigned int V_43 ;
if ( V_4 == NULL )
return - V_42 ;
V_44 . V_45 = 1 ;
V_43 = F_17 ( V_4 , 0 ) ;
if ( V_43 == V_46 ) {
F_4 ( V_5 L_15 ) ;
return - V_42 ;
}
if ( F_18 ( V_43 , V_47 , V_48 ,
L_16 , ( void * ) 0 ) ) {
F_4 ( V_5 L_17 , V_43 ) ;
return - V_42 ;
}
if ( V_17 == V_25 ) {
V_49 = F_2 ( NULL , L_18 ) ;
if ( V_49 == NULL )
V_49 = F_2 ( NULL ,
L_19 ) ;
if ( V_49 )
V_50 = F_17 ( V_49 , 0 ) ;
if ( V_50 != V_46 ) {
if ( F_18 ( V_50 , V_51 ,
V_48 , L_20 ,
( void * ) 0 ) )
F_4 ( V_5 L_21
L_22 , V_50 ) ;
else
V_52 = 1 ;
}
}
F_11 ( & V_3 [ V_30 ] , V_53 | V_54 | V_55 ) ;
V_56 = 1 ;
do {
F_19 () ;
} while ( V_33 != V_34 );
return 0 ;
}
static int T_1 F_20 ( void )
{
if ( V_4 == NULL )
return - V_42 ;
#ifdef F_21
F_22 () ;
#endif
#ifdef F_23
if ( F_24 ( L_23 ) ||
F_24 ( L_24 ) ) {
int V_57 = F_25 ( V_58 ,
NULL , V_59 , 0 ) ;
V_60 = 1 ;
if ( V_57 == V_61 )
V_62 [ 0 ] . V_63 |= V_64 ;
else
V_62 [ 0 ] . V_63 |= V_65 ;
} else if ( F_24 ( L_25 ) ||
F_24 ( L_26 ) ) {
V_60 = 2 ;
V_62 [ 0 ] . V_63 |= V_66 ;
V_62 [ 1 ] . V_63 |= V_66 ;
} else {
struct V_21 * V_67 =
F_2 ( NULL , L_27 ) ;
const T_3 * V_68 = NULL ;
if ( V_67 )
V_68 = F_3 ( V_67 , L_28 , NULL ) ;
if ( V_68 ) {
V_60 = ( V_68 [ 6 ] >> 16 ) & 0xff ;
V_62 [ 0 ] . V_63 |= V_66 ;
if ( V_60 > 1 )
V_62 [ 1 ] . V_63 |= V_66 ;
}
F_9 ( V_67 ) ;
}
#endif
V_69 = F_26 ( L_29 , NULL ) ;
if ( V_69 ) {
long V_70 ;
for ( V_70 = 0 ; V_70 < V_60 ; V_70 ++ ) {
char V_71 [ 16 ] ;
sprintf ( V_71 , L_30 , V_70 ) ;
V_72 [ V_70 ] = F_27 ( V_71 , 0 , V_69 ,
& V_73 , ( void * ) V_70 ) ;
}
V_74 = F_28 ( L_31 , 0 , V_69 , & V_75 ) ;
V_76 = F_28 ( L_32 , 0 , V_69 ,
& V_77 ) ;
V_78 = F_28 ( L_33 , 0600 , V_69 ,
& V_79 ) ;
}
return 0 ;
}
static int
F_12 ( void )
{
int V_80 ;
struct V_81 V_82 ;
F_11 ( & V_3 [ V_83 ] , V_3 [ V_83 ] | V_84 ) ;
F_11 ( & V_3 [ V_85 ] , ( V_3 [ V_85 ] | V_84 ) & ~ V_86 ) ;
F_29 ( & V_82 , NULL , 2 , V_87 , V_10 ) ;
V_80 = 100000 ;
while ( ! V_82 . V_45 ) {
if ( -- V_80 < 0 ) {
F_4 ( V_5 L_34 ) ;
return 0 ;
}
F_30 ( 10 ) ;
F_19 () ;
}
V_80 = 100000 ;
V_88 [ 0 ] [ 0 ] = 1 ;
while ( V_88 [ 0 ] [ 0 ] || V_33 != V_34 ) {
if ( -- V_80 < 0 ) {
F_4 ( V_5 L_35 ) ;
return 0 ;
}
if ( V_33 == V_34 )
V_89 = 1 ;
V_47 ( 0 , NULL ) ;
F_30 ( 10 ) ;
}
if ( V_17 == V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
while ( ! V_82 . V_45 )
F_19 () ;
}
F_29 ( & V_82 , NULL , 1 , V_91 ) ;
F_31 ( & V_82 ) ;
if ( V_82 . V_92 > 0 )
V_39 = V_82 . V_93 [ 0 ] ;
if ( V_17 == V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_94 ,
V_95 ) ;
F_31 ( & V_82 ) ;
if ( V_82 . V_92 == 2 ) {
if ( V_82 . V_93 [ 1 ] & V_96 )
V_97 = 1 ;
F_4 ( V_36 L_36 ,
V_97 ? L_37 : L_38 ) ;
}
}
return 1 ;
}
int
F_32 ( void )
{
return V_17 ;
}
static void F_33 ( int V_98 )
{
struct V_81 V_82 ;
if ( V_17 != V_25 )
return;
V_97 = V_98 ;
F_29 ( & V_82 , NULL , 2 , V_94 , V_95 ) ;
F_31 ( & V_82 ) ;
if ( V_82 . V_92 < 2 )
return;
if ( V_98 )
F_29 ( & V_82 , NULL , 4 , V_94 ,
V_99 ,
V_82 . V_93 [ 0 ] , V_96 ) ;
else
F_29 ( & V_82 , NULL , 4 , V_94 ,
V_100 ,
V_82 . V_93 [ 0 ] , V_96 ) ;
F_31 ( & V_82 ) ;
}
static void
F_34 ( struct V_81 * V_82 )
{
unsigned int V_101 = V_65 ;
long V_102 , V_103 , V_104 , V_105 , V_106 ;
long V_107 , V_108 ;
long V_109 , V_110 , time , V_111 ;
int V_57 = F_25 ( V_58 ,
NULL , V_59 , 0 ) ;
if ( V_82 -> V_93 [ 0 ] & 0x01 )
V_112 |= V_113 ;
else
V_112 &= ~ V_113 ;
if ( V_57 == V_61 ) {
V_108 = 189 ;
V_107 = 213 ;
V_106 = 6500 ;
} else {
V_108 = 330 ;
V_107 = 330 ;
V_106 = 6500 ;
}
V_105 = V_108 ;
if ( V_82 -> V_93 [ 0 ] & 0x04 ) {
V_101 |= V_114 ;
if ( V_82 -> V_93 [ 0 ] & 0x02 )
V_101 |= V_115 ;
V_104 = ( V_82 -> V_93 [ 1 ] << 8 ) | V_82 -> V_93 [ 2 ] ;
V_110 = ( V_104 * 265 + 72665 ) / 10 ;
V_109 = V_82 -> V_93 [ 5 ] ;
if ( ( V_82 -> V_93 [ 0 ] & 0x01 ) == 0 ) {
if ( V_109 > 200 )
V_104 += ( ( V_109 - 200 ) * 15 ) / 100 ;
} else if ( V_82 -> V_93 [ 0 ] & 0x02 ) {
V_104 = ( V_104 * 97 ) / 100 ;
V_105 = V_107 ;
}
V_103 = ( 100 * V_104 ) / V_105 ;
if ( V_82 -> V_93 [ 0 ] & 0x40 ) {
V_102 = ( V_82 -> V_93 [ 6 ] << 8 ) + V_82 -> V_93 [ 7 ] ;
if ( V_102 > V_106 )
V_102 = V_106 ;
V_102 *= 100 ;
V_102 = 100 - V_102 / V_106 ;
if ( V_102 < V_103 )
V_103 = V_102 ;
}
if ( V_109 > 0 )
time = ( V_103 * 16440 ) / V_109 ;
else
time = 0 ;
V_111 = 100 ;
V_109 = - V_109 ;
} else
V_103 = V_111 = V_109 = V_110 = time = 0 ;
V_62 [ V_116 ] . V_63 = V_101 ;
V_62 [ V_116 ] . V_103 = V_103 ;
V_62 [ V_116 ] . V_117 = V_111 ;
V_62 [ V_116 ] . V_109 = V_109 ;
V_62 [ V_116 ] . V_110 = V_110 ;
V_62 [ V_116 ] . V_118 = time ;
F_35 ( 0 , & V_119 ) ;
}
static void
F_36 ( struct V_81 * V_82 )
{
unsigned int V_101 = V_66 ;
int V_109 ;
unsigned int V_120 , V_111 , V_110 ;
if ( V_82 -> V_93 [ 1 ] & 0x01 )
V_112 |= V_113 ;
else
V_112 &= ~ V_113 ;
V_120 = V_111 = V_109 = V_110 = 0 ;
if ( V_82 -> V_93 [ 1 ] & 0x04 ) {
V_101 |= V_114 ;
switch( V_82 -> V_93 [ 0 ] ) {
case 3 :
case 4 : V_120 = V_82 -> V_93 [ 2 ] ;
V_111 = V_82 -> V_93 [ 3 ] ;
V_109 = * ( ( signed char * ) & V_82 -> V_93 [ 4 ] ) ;
V_110 = V_82 -> V_93 [ 5 ] ;
break;
case 5 : V_120 = ( V_82 -> V_93 [ 2 ] << 8 ) | V_82 -> V_93 [ 3 ] ;
V_111 = ( V_82 -> V_93 [ 4 ] << 8 ) | V_82 -> V_93 [ 5 ] ;
V_109 = * ( ( signed short * ) & V_82 -> V_93 [ 6 ] ) ;
V_110 = ( V_82 -> V_93 [ 8 ] << 8 ) | V_82 -> V_93 [ 9 ] ;
break;
default:
F_37 ( L_39
L_40 , V_82 -> V_92 ,
V_82 -> V_93 ) ;
break;
}
}
if ( ( V_82 -> V_93 [ 1 ] & 0x01 ) && ( V_109 > 0 ) )
V_101 |= V_115 ;
V_62 [ V_116 ] . V_63 = V_101 ;
V_62 [ V_116 ] . V_103 = V_120 ;
V_62 [ V_116 ] . V_117 = V_111 ;
V_62 [ V_116 ] . V_109 = V_109 ;
V_62 [ V_116 ] . V_110 = V_110 ;
if ( V_109 ) {
if ( ( V_82 -> V_93 [ 1 ] & 0x01 ) && ( V_109 > 0 ) )
V_62 [ V_116 ] . V_118
= ( ( V_111 - V_120 ) * 3600 ) / V_109 ;
else
V_62 [ V_116 ] . V_118
= ( V_120 * 3600 ) / ( - V_109 ) ;
} else
V_62 [ V_116 ] . V_118 = 0 ;
V_116 = ( V_116 + 1 ) % V_60 ;
F_35 ( 0 , & V_119 ) ;
}
static void
F_38 ( void )
{
if ( F_39 ( 0 , & V_119 ) )
return;
if ( V_17 == V_18 )
F_29 ( & V_44 , F_34 ,
1 , V_121 ) ;
else
F_29 ( & V_44 , F_36 ,
2 , V_122 , V_116 + 1 ) ;
}
static int F_40 ( struct V_123 * V_124 , void * V_125 )
{
F_41 ( V_124 , L_41 , V_37 ) ;
F_41 ( V_124 , L_42 , V_39 ) ;
F_41 ( V_124 , L_43 ,
( ( V_112 & V_113 ) != 0 ) || V_60 == 0 ) ;
F_41 ( V_124 , L_44 , V_60 ) ;
return 0 ;
}
static int F_42 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_43 ( V_127 , F_40 , NULL ) ;
}
static int F_44 ( struct V_123 * V_124 , void * V_125 )
{
int V_70 ;
static const char * V_128 [] = {
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55
} ;
for ( V_70 = 0 ; V_70 < 11 ; V_70 ++ ) {
F_41 ( V_124 , L_56 ,
V_70 , V_129 [ V_70 ] , V_128 [ V_70 ] ) ;
}
return 0 ;
}
static int F_45 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_43 ( V_127 , F_44 , NULL ) ;
}
static int F_46 ( struct V_123 * V_124 , void * V_125 )
{
long V_130 = ( long ) V_124 -> V_131 ;
F_47 ( V_124 , '\n' ) ;
F_41 ( V_124 , L_57 , V_62 [ V_130 ] . V_63 ) ;
F_41 ( V_124 , L_58 , V_62 [ V_130 ] . V_103 ) ;
F_41 ( V_124 , L_59 , V_62 [ V_130 ] . V_117 ) ;
F_41 ( V_124 , L_60 , V_62 [ V_130 ] . V_109 ) ;
F_41 ( V_124 , L_61 , V_62 [ V_130 ] . V_110 ) ;
F_41 ( V_124 , L_62 , V_62 [ V_130 ] . V_118 ) ;
return 0 ;
}
static int F_48 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_43 ( V_127 , F_46 , F_49 ( V_126 ) ) ;
}
static int F_50 ( struct V_123 * V_124 , void * V_125 )
{
#if F_51 ( V_132 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_133 , NULL , 0 , - 1 ) >= 0 )
F_41 ( V_124 , L_63 , V_134 ) ;
#endif
if ( V_17 == V_25 )
F_41 ( V_124 , L_64 , V_97 ) ;
return 0 ;
}
static int F_52 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_43 ( V_127 , F_50 , NULL ) ;
}
static T_4 F_53 ( struct V_127 * V_127 ,
const char T_5 * V_135 , T_6 V_136 , T_7 * V_137 )
{
char V_138 [ 33 ] ;
char * V_139 , * V_140 ;
T_6 V_141 = V_136 ;
if ( ! V_136 )
return - V_142 ;
if ( V_136 > 32 )
V_136 = 32 ;
if ( F_54 ( V_138 , V_135 , V_136 ) )
return - V_143 ;
V_138 [ V_136 ] = 0 ;
V_139 = V_138 ;
while( * V_139 == ' ' )
V_139 ++ ;
V_140 = V_139 ;
while( * V_140 && ( * V_140 != '=' ) ) {
if ( * V_140 == ' ' )
* V_140 = 0 ;
V_140 ++ ;
}
if ( ( * V_140 ) == 0 )
return - V_142 ;
* ( V_140 ++ ) = 0 ;
while( * V_140 == ' ' )
V_140 ++ ;
#if F_51 ( V_132 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_133 , NULL , 0 , - 1 ) >= 0 )
if ( ! strcmp ( V_139 , L_65 ) )
V_134 = ( ( * V_140 ) == '1' ) ;
#endif
if ( V_17 == V_25 && ! strcmp ( V_139 , L_66 ) ) {
int V_144 ;
V_144 = ( ( * V_140 ) == '1' ) ;
if ( V_144 != V_97 )
F_33 ( V_144 ) ;
}
return V_141 ;
}
static int F_55 ( struct V_81 * V_82 , int V_145 )
{
int V_70 , V_146 ;
if ( ( V_4 == NULL ) || ( ! V_56 ) ) {
V_82 -> V_45 = 1 ;
return - V_147 ;
}
V_146 = - V_142 ;
switch ( V_82 -> V_148 [ 0 ] ) {
case V_149 :
for ( V_70 = 0 ; V_70 < V_82 -> V_150 - 1 ; ++ V_70 )
V_82 -> V_148 [ V_70 ] = V_82 -> V_148 [ V_70 + 1 ] ;
-- V_82 -> V_150 ;
if ( V_151 [ V_82 -> V_148 [ 0 ] ] [ 1 ] != 0 ) {
V_82 -> V_93 [ 0 ] = V_152 ;
V_82 -> V_92 = 1 ;
} else
V_82 -> V_92 = 0 ;
V_146 = F_56 ( V_82 ) ;
break;
case V_153 :
switch ( V_82 -> V_148 [ 1 ] ) {
case V_154 :
if ( V_82 -> V_150 != 2 )
break;
V_82 -> V_148 [ 0 ] = V_155 ;
V_82 -> V_150 = 1 ;
V_82 -> V_92 = 3 ;
V_82 -> V_93 [ 0 ] = V_153 ;
V_82 -> V_93 [ 1 ] = 0 ;
V_82 -> V_93 [ 2 ] = V_154 ;
V_146 = F_56 ( V_82 ) ;
break;
case V_156 :
if ( V_82 -> V_150 != 6 )
break;
V_82 -> V_148 [ 0 ] = V_157 ;
V_82 -> V_150 = 5 ;
for ( V_70 = 1 ; V_70 <= 4 ; ++ V_70 )
V_82 -> V_148 [ V_70 ] = V_82 -> V_148 [ V_70 + 1 ] ;
V_82 -> V_92 = 3 ;
V_82 -> V_93 [ 0 ] = V_153 ;
V_82 -> V_93 [ 1 ] = 0 ;
V_82 -> V_93 [ 2 ] = V_156 ;
V_146 = F_56 ( V_82 ) ;
break;
}
break;
case V_158 :
if ( ! V_9 )
return - V_147 ;
for ( V_70 = V_82 -> V_150 - 1 ; V_70 > 1 ; -- V_70 )
V_82 -> V_148 [ V_70 + 2 ] = V_82 -> V_148 [ V_70 ] ;
V_82 -> V_148 [ 3 ] = V_82 -> V_150 - 2 ;
V_82 -> V_148 [ 2 ] = V_159 ;
V_82 -> V_148 [ 0 ] = V_160 ;
V_82 -> V_150 += 2 ;
V_82 -> V_161 = 1 ;
V_82 -> V_92 = 0 ;
V_146 = F_56 ( V_82 ) ;
break;
}
if ( V_146 ) {
V_82 -> V_45 = 1 ;
return V_146 ;
}
if ( V_145 )
while ( ! V_82 -> V_45 )
F_19 () ;
return 0 ;
}
static int F_57 ( int V_162 )
{
struct V_81 V_82 ;
if ( V_162 ) {
F_29 ( & V_82 , NULL , 5 , V_160 , 0 , 0x86 ,
V_163 >> 8 , V_163 ) ;
V_159 = 2 ;
} else {
F_29 ( & V_82 , NULL , 1 , V_164 ) ;
V_159 = 0 ;
}
while ( ! V_82 . V_45 )
F_19 () ;
return 0 ;
}
static int F_58 ( int V_162 )
{
if ( ( V_4 == NULL ) || ( ! V_56 ) || ! V_9 )
return - V_147 ;
V_163 = V_162 ;
return F_57 ( V_162 ) ;
}
static int F_59 ( void )
{
struct V_81 V_82 ;
int V_165 = V_163 ;
if ( ( V_4 == NULL ) || ( ! V_56 ) || ! V_9 )
return - V_147 ;
F_57 ( 0 ) ;
V_82 . V_150 = 4 ;
V_82 . V_166 = NULL ;
V_82 . V_148 [ 0 ] = V_160 ;
V_82 . V_148 [ 1 ] = V_167 ;
V_82 . V_148 [ 2 ] = 0 ;
V_82 . V_148 [ 3 ] = 0 ;
V_82 . V_148 [ 4 ] = 0 ;
V_82 . V_92 = 0 ;
V_82 . V_161 = 1 ;
if ( F_56 ( & V_82 ) != 0 ) {
F_4 ( V_5 L_67 ) ;
return - V_168 ;
}
F_31 ( & V_82 ) ;
if ( V_165 != 0 )
F_57 ( V_165 ) ;
return 0 ;
}
int
F_29 ( struct V_81 * V_82 , void (* V_166)( struct V_81 * ) ,
int V_150 , ... )
{
T_8 V_169 ;
int V_70 ;
if ( V_4 == NULL )
return - V_147 ;
if ( V_150 < 0 || V_150 > 32 ) {
F_4 ( V_5 L_68 , V_150 ) ;
V_82 -> V_45 = 1 ;
return - V_142 ;
}
V_82 -> V_150 = V_150 ;
V_82 -> V_166 = V_166 ;
va_start ( V_169 , V_150 ) ;
for ( V_70 = 0 ; V_70 < V_150 ; ++ V_70 )
V_82 -> V_148 [ V_70 ] = va_arg ( V_169 , int ) ;
va_end ( V_169 ) ;
V_82 -> V_92 = 0 ;
V_82 -> V_161 = 0 ;
return F_56 ( V_82 ) ;
}
int
F_56 ( struct V_81 * V_82 )
{
unsigned long V_63 ;
int V_170 ;
if ( V_3 == NULL ) {
V_82 -> V_45 = 1 ;
return - V_147 ;
}
if ( V_82 -> V_150 <= 0 ) {
V_82 -> V_45 = 1 ;
return 0 ;
}
V_170 = V_151 [ V_82 -> V_148 [ 0 ] ] [ 0 ] ;
if ( V_170 >= 0 && V_82 -> V_150 != V_170 + 1 ) {
V_82 -> V_45 = 1 ;
return - V_142 ;
}
V_82 -> V_171 = NULL ;
V_82 -> V_172 = 0 ;
V_82 -> V_45 = 0 ;
F_60 ( & V_8 , V_63 ) ;
if ( V_173 != 0 ) {
V_174 -> V_171 = V_82 ;
V_174 = V_82 ;
} else {
V_173 = V_82 ;
V_174 = V_82 ;
if ( V_33 == V_34 )
F_61 () ;
}
F_62 ( & V_8 , V_63 ) ;
return 0 ;
}
static inline void
F_63 ( void )
{
int V_80 = 4000 ;
while ( ( F_64 ( & V_3 [ V_83 ] ) & V_86 ) == 0 ) {
if ( -- V_80 < 0 ) {
F_4 ( V_5 L_69 ) ;
return;
}
F_30 ( 10 ) ;
}
}
static inline void
F_65 ( int V_175 )
{
volatile unsigned char T_9 * V_125 = V_3 ;
F_11 ( & V_125 [ V_176 ] , F_64 ( & V_125 [ V_176 ] ) | V_177 | V_178 ) ;
F_11 ( & V_125 [ V_179 ] , V_175 ) ;
F_11 ( & V_125 [ V_83 ] , F_64 ( & V_125 [ V_83 ] ) & ~ V_84 ) ;
( void ) F_64 ( & V_125 [ V_83 ] ) ;
}
static inline void
F_66 ( void )
{
volatile unsigned char T_9 * V_125 = V_3 ;
F_11 ( & V_125 [ V_176 ] , ( F_64 ( & V_125 [ V_176 ] ) & ~ V_177 ) | V_178 ) ;
F_64 ( & V_125 [ V_179 ] ) ;
F_11 ( & V_125 [ V_83 ] , F_64 ( & V_125 [ V_83 ] ) & ~ V_84 ) ;
( void ) F_64 ( & V_125 [ V_83 ] ) ;
}
static inline void
F_67 ( struct V_81 * V_82 )
{
void (* V_166)( struct V_81 * ) = V_82 -> V_166 ;
V_57 () ;
V_82 -> V_45 = 1 ;
if ( V_166 )
(* V_166)( V_82 ) ;
}
static void
F_61 ( void )
{
struct V_81 * V_82 ;
V_82 = V_173 ;
if ( V_82 == 0 || V_33 != V_34
|| ( V_180 ) )
return;
V_33 = V_181 ;
V_182 = 1 ;
V_183 = V_151 [ V_82 -> V_148 [ 0 ] ] [ 0 ] ;
F_63 () ;
F_65 ( V_82 -> V_148 [ 0 ] ) ;
}
void
F_19 ( void )
{
if ( ! V_3 )
return;
if ( V_184 )
return;
V_47 ( 0 , NULL ) ;
}
void
F_68 ( void )
{
if ( ! V_3 )
return;
if ( V_184 )
return;
V_89 = 1 ;
do {
V_47 ( 0 , NULL ) ;
} while ( V_185 && ( V_89 || V_33 != V_34
|| V_180 ) );
}
void
F_31 ( struct V_81 * V_82 )
{
if ( ! V_3 )
return;
while( ( V_33 != V_34 && V_33 != V_186 ) || ! V_82 -> V_45 )
V_47 ( 0 , NULL ) ;
}
void
F_69 ( void )
{
unsigned long V_63 ;
if ( ! V_3 )
return;
F_60 ( & V_8 , V_63 ) ;
V_185 ++ ;
if ( V_185 > 1 ) {
F_62 ( & V_8 , V_63 ) ;
return;
}
do {
F_62 ( & V_8 , V_63 ) ;
if ( V_180 )
V_89 = 1 ;
V_47 ( 0 , NULL ) ;
F_60 ( & V_8 , V_63 ) ;
if ( ! V_89 && V_33 == V_34 && ! V_180 ) {
if ( V_50 >= 0 )
F_70 ( V_50 ) ;
F_11 ( & V_3 [ V_30 ] , V_55 | V_31 ) ;
F_62 ( & V_8 , V_63 ) ;
break;
}
} while ( 1 );
}
void
F_71 ( void )
{
unsigned long V_63 ;
if ( ! V_3 || ( V_185 < 1 ) )
return;
F_60 ( & V_8 , V_63 ) ;
V_185 -- ;
if ( V_185 > 0 ) {
F_62 ( & V_8 , V_63 ) ;
return;
}
V_89 = 1 ;
if ( V_50 >= 0 )
F_72 ( V_50 ) ;
F_11 ( & V_3 [ V_30 ] , V_55 | V_53 ) ;
F_62 ( & V_8 , V_63 ) ;
F_19 () ;
}
static void
F_73 ( unsigned char * V_148 , int V_187 )
{
unsigned char V_188 , V_189 ;
int V_70 = 0 ;
V_190 = 0 ;
if ( V_191 || V_187 < 1 ) {
V_89 = 0 ;
V_129 [ 8 ] ++ ;
return;
}
V_188 = V_148 [ 0 ] ;
if ( V_188 == 0 )
V_129 [ 9 ] ++ ;
if ( V_188 & V_13 )
V_188 &= ~ ( V_192 | V_193 ) ;
V_171:
if ( V_188 == 0 ) {
if ( V_70 > V_129 [ 10 ] )
V_129 [ 10 ] = V_70 ;
return;
}
for ( V_189 = 0 ; V_189 < 8 ; V_189 ++ )
if ( V_188 & ( 1 << V_189 ) )
break;
V_129 [ V_189 ] ++ ;
V_70 ++ ;
V_188 &= ~ ( 1 << V_189 ) ;
if ( ( 1 << V_189 ) & V_13 ) {
if ( ( V_148 [ 0 ] & V_192 ) == 0 ) {
struct V_81 * V_82 = V_180 ;
if ( V_82 == 0 ) {
F_4 ( V_5 L_70 ) ;
return;
}
V_180 = NULL ;
if ( V_187 <= 2 )
V_82 -> V_92 = 0 ;
else {
memcpy ( V_82 -> V_93 , V_148 + 1 , V_187 - 1 ) ;
V_82 -> V_92 = V_187 - 1 ;
}
F_67 ( V_82 ) ;
} else {
if ( V_187 == 4 && V_148 [ 1 ] == 0x2c ) {
extern int V_194 , V_195 ;
if ( V_194 ) {
V_195 = V_148 [ 2 ] ;
return;
}
}
#ifdef F_74
if ( ! ( V_17 == V_18 && V_187 == 4
&& V_148 [ 1 ] == 0x2c && V_148 [ 3 ] == 0xff
&& ( V_148 [ 2 ] & ~ 1 ) == 0xf4 ) )
F_75 ( V_148 + 1 , V_187 - 1 , 1 ) ;
#endif
}
}
else if ( ( 1 << V_189 ) & V_12 ) {
#ifdef F_21
if ( V_187 == 3 )
F_76 ( V_148 [ 1 ] >> 4 ) ;
#endif
}
else if ( ( 1 << V_189 ) & V_14 ) {
if ( V_60 ) {
if ( ( -- V_196 ) == 0 ) {
F_38 () ;
V_196 = V_197 ;
}
}
}
else if ( ( 1 << V_189 ) & V_26 ) {
if ( V_60 )
F_38 () ;
F_77 ( V_148 , V_187 ) ;
if ( V_187 == 6 ) {
F_78 ( V_198 , ! ! ( V_148 [ 1 ] & 8 ) ) ;
F_78 ( V_199 , V_148 [ 1 ] & 1 ) ;
}
} else {
F_77 ( V_148 , V_187 ) ;
}
goto V_171;
}
static struct V_81 *
F_79 ( void )
{
struct V_81 * V_82 ;
int V_200 = 0 ;
if ( V_3 [ V_83 ] & V_84 ) {
F_4 ( V_5 L_71 , V_3 [ V_83 ] ) ;
F_11 ( & V_3 [ V_32 ] , V_54 ) ;
return NULL ;
}
while ( ( F_64 ( & V_3 [ V_83 ] ) & V_86 ) != 0 )
;
if ( V_33 == V_201 || V_33 == V_202 )
V_200 = F_64 ( & V_3 [ V_179 ] ) ;
F_11 ( & V_3 [ V_83 ] , F_64 ( & V_3 [ V_83 ] ) | V_84 ) ;
F_63 () ;
switch ( V_33 ) {
case V_181 :
V_82 = V_173 ;
if ( V_183 < 0 ) {
V_183 = V_82 -> V_150 - 1 ;
F_65 ( V_183 ) ;
break;
}
if ( V_182 <= V_183 ) {
F_65 ( V_82 -> V_148 [ V_182 ++ ] ) ;
break;
}
V_82 -> V_172 = 1 ;
V_183 = V_151 [ V_82 -> V_148 [ 0 ] ] [ 1 ] ;
if ( V_183 == 0 ) {
V_33 = V_34 ;
V_173 = V_82 -> V_171 ;
if ( V_82 -> V_161 )
V_180 = V_82 ;
else
return V_82 ;
} else {
V_33 = V_201 ;
V_182 = 0 ;
V_203 = V_82 -> V_93 + V_82 -> V_92 ;
F_66 () ;
}
break;
case V_204 :
V_182 = 0 ;
V_183 = - 1 ;
V_33 = V_202 ;
V_203 = V_88 [ V_205 ] ;
F_66 () ;
if ( V_50 >= 0 && ! V_52 ) {
F_72 ( V_50 ) ;
V_52 = 1 ;
}
break;
case V_201 :
case V_202 :
if ( V_183 == - 1 ) {
V_183 = V_200 ;
if ( V_200 > 32 )
F_4 ( V_5 L_72 , V_200 ) ;
} else if ( V_182 < 32 ) {
V_203 [ V_182 ++ ] = V_200 ;
}
if ( V_182 < V_183 ) {
F_66 () ;
break;
}
if ( V_33 == V_202 ) {
V_33 = V_34 ;
V_206 [ V_205 ] = V_207 ;
V_208 [ V_205 ] = V_183 ;
} else {
V_82 = V_173 ;
V_173 = V_82 -> V_171 ;
V_82 -> V_92 += V_182 ;
if ( V_82 -> V_148 [ 0 ] == V_209 || V_82 -> V_148 [ 0 ] == V_210 )
V_33 = V_186 ;
else
V_33 = V_34 ;
return V_82 ;
}
break;
default:
F_4 ( V_5 L_73 ,
V_33 ) ;
}
return NULL ;
}
static T_10
V_47 ( int V_43 , void * V_211 )
{
unsigned long V_63 ;
int V_212 ;
int V_213 = 0 ;
int V_214 = - 1 ;
struct V_81 * V_82 = NULL ;
int V_215 = 0 ;
F_60 ( & V_8 , V_63 ) ;
++ V_184 ;
for (; ; ) {
V_212 = F_64 ( & V_3 [ V_32 ] ) & ( V_54 | V_55 ) ;
if ( V_212 == 0 )
break;
V_215 = 1 ;
if ( ++ V_213 > 1000 ) {
F_4 ( V_216 L_74
L_75 ,
V_212 , F_64 ( & V_3 [ V_30 ] ) , V_33 ) ;
break;
}
F_11 ( & V_3 [ V_32 ] , V_212 ) ;
if ( V_212 & V_55 ) {
V_89 = 1 ;
V_129 [ 0 ] ++ ;
}
if ( V_212 & V_54 ) {
V_82 = F_79 () ;
if ( V_82 )
break;
}
}
V_217:
if ( V_33 == V_34 ) {
if ( V_89 ) {
if ( V_206 [ 0 ] == V_218 )
V_205 = 0 ;
else if ( V_206 [ 1 ] == V_218 )
V_205 = 1 ;
else
goto V_219;
V_33 = V_204 ;
V_206 [ V_205 ] = V_220 ;
F_63 () ;
F_65 ( V_221 ) ;
V_89 = 0 ;
} else if ( V_173 )
F_61 () ;
}
V_219:
if ( V_206 [ ! V_205 ] == V_207 ) {
V_206 [ ! V_205 ] = V_222 ;
V_214 = ! V_205 ;
} else if ( V_206 [ V_205 ] == V_207 ) {
V_206 [ V_205 ] = V_222 ;
V_214 = V_205 ;
}
-- V_184 ;
F_62 ( & V_8 , V_63 ) ;
if ( V_82 ) {
F_67 ( V_82 ) ;
V_82 = NULL ;
}
if ( V_214 >= 0 ) {
F_73 ( V_88 [ V_214 ] , V_208 [ V_214 ] ) ;
F_60 ( & V_8 , V_63 ) ;
++ V_184 ;
V_206 [ V_214 ] = V_218 ;
V_214 = - 1 ;
goto V_217;
}
return F_80 ( V_215 ) ;
}
void
F_81 ( void )
{
unsigned long V_63 ;
F_60 ( & V_8 , V_63 ) ;
if ( V_33 == V_186 )
V_33 = V_34 ;
V_89 = 1 ;
F_62 ( & V_8 , V_63 ) ;
}
static T_10
V_51 ( int V_43 , void * V_211 )
{
unsigned long V_63 ;
if ( ( F_64 ( V_27 + 0x9 ) & 0x02 ) == 0 ) {
F_60 ( & V_8 , V_63 ) ;
if ( V_52 > 0 ) {
F_70 ( V_50 ) ;
V_52 = 0 ;
}
V_129 [ 1 ] ++ ;
V_89 = 1 ;
F_62 ( & V_8 , V_63 ) ;
V_47 ( 0 , NULL ) ;
return V_223 ;
}
return V_224 ;
}
void
F_82 ( int V_225 )
{
struct V_81 V_82 ;
if ( V_4 == NULL )
return ;
if ( V_17 == V_25 )
return ;
F_29 ( & V_82 , NULL , 2 , V_226 , V_227 |
( V_225 ? V_228 : V_229 ) ) ;
F_31 ( & V_82 ) ;
}
void
F_83 ( void )
{
struct V_81 V_82 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_191 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_87 , V_13 |
V_14 ) ;
while( ! V_82 . V_45 )
F_19 () ;
}
F_29 ( & V_82 , NULL , 1 , V_230 ) ;
F_31 ( & V_82 ) ;
for (; ; )
;
}
void
F_85 ( void )
{
struct V_81 V_82 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_191 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_87 , V_13 |
V_14 ) ;
F_31 ( & V_82 ) ;
} else {
F_33 ( 0 ) ;
}
F_29 ( & V_82 , NULL , 5 , V_231 ,
'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
for (; ; )
;
}
int
F_86 ( void )
{
return V_3 != 0 ;
}
static void
F_87 ( void )
{
V_232 [ 0 ] = F_64 ( & V_3 [ V_233 ] ) ;
V_232 [ 1 ] = F_64 ( & V_3 [ V_234 ] ) ;
V_232 [ 2 ] = F_64 ( & V_3 [ V_83 ] ) ;
V_232 [ 3 ] = F_64 ( & V_3 [ V_85 ] ) ;
V_232 [ 4 ] = F_64 ( & V_3 [ V_235 ] ) ;
V_232 [ 5 ] = F_64 ( & V_3 [ V_176 ] ) ;
V_232 [ 6 ] = F_64 ( & V_3 [ V_236 ] ) ;
V_232 [ 7 ] = F_64 ( & V_3 [ V_237 ] ) ;
}
static void
F_88 ( void )
{
F_11 ( & V_3 [ V_233 ] , V_232 [ 0 ] ) ;
F_11 ( & V_3 [ V_234 ] , V_232 [ 1 ] ) ;
F_11 ( & V_3 [ V_83 ] , V_232 [ 2 ] ) ;
F_11 ( & V_3 [ V_85 ] , V_232 [ 3 ] ) ;
F_11 ( & V_3 [ V_235 ] , V_232 [ 4 ] ) ;
F_11 ( & V_3 [ V_176 ] , V_232 [ 5 ] ) ;
F_11 ( & V_3 [ V_236 ] , V_232 [ 6 ] ) ;
F_11 ( & V_3 [ V_237 ] , V_232 [ 7 ] ) ;
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
F_11 ( & V_3 [ V_30 ] , V_53 | V_54 | V_55 ) ;
}
static int F_89 ( void )
{
unsigned long V_238 ;
unsigned short V_239 ;
struct V_81 V_82 ;
struct V_240 * V_241 ;
V_241 = F_90 ( 0 , 0 ) ;
if ( ! V_241 )
return - V_42 ;
F_29 ( & V_82 , NULL , 2 , V_242 , V_243 | V_244 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_226 ,
V_229 | V_245 | V_227 | V_246 ) ;
F_31 ( & V_82 ) ;
V_238 = F_91 () ;
if ( ! V_247 ) {
F_29 ( & V_82 , NULL , 5 , V_209 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
}
F_87 () ;
F_25 ( V_133 , NULL , 0 , 1 ) ;
F_92 ( V_241 , 0x70 , & V_239 ) ;
V_239 &= ~ ( V_248 | V_249 ) ;
V_239 |= V_250 | V_251 ;
F_93 ( V_241 , 0x70 , V_239 ) ;
if ( V_247 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_92 ( V_241 , 0x70 , & V_239 ) ;
V_239 &= ~ ( V_250 | V_248 | V_249 | V_251 ) ;
F_93 ( V_241 , 0x70 , V_239 ) ;
F_96 ( V_241 ) ;
F_25 ( V_133 , NULL , 0 , 0 ) ;
F_88 () ;
if ( V_238 != 0xffffffff && ( V_238 & V_252 ) != 0 )
F_97 ( V_238 ) ;
F_98 ( NULL , V_253 -> V_254 ) ;
F_81 () ;
F_29 ( & V_82 , NULL , 2 , V_87 , V_10 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_242 ,
V_255 | V_244 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_226 ,
V_228 | V_245 | V_256 | V_227 | V_246 ) ;
F_31 ( & V_82 ) ;
return 0 ;
}
static int
F_99 ( void )
{
unsigned long V_238 ;
unsigned long V_257 ;
struct V_81 V_82 ;
if ( F_25 ( V_133 , NULL , 0 , - 1 ) < 0 ) {
F_4 ( V_5 L_76 ) ;
return - V_258 ;
}
if ( F_100 () > 1 || F_101 ( 0 ) )
return - V_259 ;
F_29 ( & V_82 , NULL , 2 , V_87 , 0 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 4 , V_94 , V_260 ,
0xff , 0xff ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 4 , V_94 , V_261 ,
0 , V_262 |
( V_134 ? V_263 : 0 ) ) ;
F_31 ( & V_82 ) ;
V_257 = F_102 () ;
V_238 = F_91 () ;
if ( ! V_247 ) {
F_29 ( & V_82 , NULL , 5 , V_209 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
}
F_87 () ;
F_25 ( V_133 , NULL , 0 , 1 ) ;
if ( V_247 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_25 ( V_133 , NULL , 0 , 0 ) ;
F_88 () ;
V_264 *= 2 ;
F_103 () ;
if ( V_238 != 0xffffffff && ( V_238 & V_252 ) != 0 )
F_97 ( V_238 ) ;
if ( V_257 != 0xffffffff && ( V_257 & V_265 ) != 0 )
F_104 ( V_257 ) ;
F_98 ( NULL , V_253 -> V_254 ) ;
F_81 () ;
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_87 , V_10 ) ;
F_31 ( & V_82 ) ;
V_264 /= 2 ;
return 0 ;
}
static void F_105 ( void )
{
V_266 = F_10 ( V_267 , 0x100 ) ;
if ( V_266 == NULL )
F_4 ( V_268 L_77 ) ;
}
static int F_106 ( void )
{
int V_70 , V_175 ;
unsigned int V_269 ;
unsigned long V_270 ;
struct V_81 V_271 ;
unsigned int T_9 * V_272 ;
if ( V_266 == NULL )
return - V_273 ;
V_272 = V_266 + V_274 ;
for ( V_70 = 0x403f ; V_70 >= 0x4000 ; -- V_70 ) {
F_107 ( V_272 , V_70 ) ;
do {
V_175 = ( F_108 ( V_272 ) >> 16 ) & 0x3ff ;
} while ( V_175 == 0 );
if ( V_175 >= 0x100 )
break;
}
F_29 ( & V_271 , NULL , 5 , V_209 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_271 ) ;
F_81 () ;
F_25 ( V_133 , NULL , 0 , 1 ) ;
V_190 = 1 ;
V_269 = F_109 ( V_275 ) ;
V_269 = ( V_269 & ~ ( V_276 | V_277 ) ) | V_278 ;
F_110 ( V_275 , V_269 ) ;
F_111 () ;
V_270 = F_112 () | V_279 ;
while ( V_190 ) {
V_57 () ;
F_113 ( V_270 ) ;
F_114 () ;
}
F_84 () ;
F_107 ( V_272 , 0x3f ) ;
F_25 ( V_133 , NULL , 0 , 0 ) ;
return 0 ;
}
static void
F_77 ( unsigned char * V_148 , int V_187 )
{
struct V_280 * V_281 ;
struct V_282 * V_169 ;
int V_70 ;
unsigned long V_63 ;
if ( V_187 > sizeof( V_281 -> V_283 [ 0 ] . V_148 ) )
V_187 = sizeof( V_281 -> V_283 [ 0 ] . V_148 ) ;
F_60 ( & V_284 , V_63 ) ;
for ( V_169 = & V_285 ; ( V_169 = V_169 -> V_171 ) != & V_285 ; ) {
V_281 = F_115 ( V_169 , struct V_280 , V_169 ) ;
F_116 ( & V_281 -> V_286 ) ;
V_70 = V_281 -> V_287 + 1 ;
if ( V_70 >= V_288 )
V_70 = 0 ;
if ( V_70 != V_281 -> V_289 ) {
struct V_290 * V_291 = & V_281 -> V_283 [ V_281 -> V_287 ] ;
V_291 -> V_187 = V_187 ;
memcpy ( V_291 -> V_148 , V_148 , V_187 ) ;
V_281 -> V_287 = V_70 ;
F_117 ( & V_281 -> V_292 ) ;
}
F_118 ( & V_281 -> V_286 ) ;
}
F_62 ( & V_284 , V_63 ) ;
}
static int
F_119 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
struct V_280 * V_281 ;
unsigned long V_63 ;
V_281 = F_120 ( sizeof( struct V_280 ) , V_293 ) ;
if ( V_281 == 0 )
return - V_273 ;
V_281 -> V_289 = V_281 -> V_287 = 0 ;
F_6 ( & V_281 -> V_286 ) ;
F_121 ( & V_281 -> V_292 ) ;
F_122 ( & V_294 ) ;
F_60 ( & V_284 , V_63 ) ;
#if F_51 ( V_295 ) && F_51 ( F_21 )
V_281 -> V_296 = 0 ;
#endif
F_123 ( & V_281 -> V_169 , & V_285 ) ;
F_62 ( & V_284 , V_63 ) ;
V_127 -> V_297 = V_281 ;
F_124 ( & V_294 ) ;
return 0 ;
}
static T_4
F_125 ( struct V_127 * V_127 , char T_5 * V_298 ,
T_6 V_136 , T_7 * V_299 )
{
struct V_280 * V_281 = V_127 -> V_297 ;
F_126 ( V_292 , V_253 ) ;
unsigned long V_63 ;
int V_146 = 0 ;
if ( V_136 < 1 || V_281 == 0 )
return - V_142 ;
if ( ! F_127 ( V_300 , V_298 , V_136 ) )
return - V_143 ;
F_60 ( & V_281 -> V_286 , V_63 ) ;
F_128 ( & V_281 -> V_292 , & V_292 ) ;
F_129 ( V_301 ) ;
for (; ; ) {
V_146 = - V_259 ;
if ( V_281 -> V_289 != V_281 -> V_287 ) {
int V_70 = V_281 -> V_289 ;
struct V_290 * V_291 = & V_281 -> V_283 [ V_70 ] ;
V_146 = V_291 -> V_187 ;
F_62 ( & V_281 -> V_286 , V_63 ) ;
if ( V_146 > V_136 )
V_146 = V_136 ;
if ( V_146 > 0 && F_130 ( V_298 , V_291 -> V_148 , V_146 ) )
V_146 = - V_143 ;
if ( ++ V_70 >= V_288 )
V_70 = 0 ;
F_60 ( & V_281 -> V_286 , V_63 ) ;
V_281 -> V_289 = V_70 ;
}
if ( V_146 >= 0 )
break;
if ( V_127 -> V_302 & V_303 )
break;
V_146 = - V_304 ;
if ( F_131 ( V_253 ) )
break;
F_62 ( & V_281 -> V_286 , V_63 ) ;
F_132 () ;
F_60 ( & V_281 -> V_286 , V_63 ) ;
}
F_133 ( V_305 ) ;
F_134 ( & V_281 -> V_292 , & V_292 ) ;
F_62 ( & V_281 -> V_286 , V_63 ) ;
return V_146 ;
}
static T_4
F_135 ( struct V_127 * V_127 , const char T_5 * V_298 ,
T_6 V_136 , T_7 * V_299 )
{
return 0 ;
}
static unsigned int
F_136 ( struct V_127 * V_306 , T_11 * V_292 )
{
struct V_280 * V_281 = V_306 -> V_297 ;
unsigned int V_307 = 0 ;
unsigned long V_63 ;
if ( V_281 == 0 )
return 0 ;
F_137 ( V_306 , & V_281 -> V_292 , V_292 ) ;
F_60 ( & V_281 -> V_286 , V_63 ) ;
if ( V_281 -> V_289 != V_281 -> V_287 )
V_307 |= V_308 ;
F_62 ( & V_281 -> V_286 , V_63 ) ;
return V_307 ;
}
static int
F_138 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
struct V_280 * V_281 = V_127 -> V_297 ;
unsigned long V_63 ;
if ( V_281 != 0 ) {
V_127 -> V_297 = NULL ;
F_60 ( & V_284 , V_63 ) ;
F_139 ( & V_281 -> V_169 ) ;
F_62 ( & V_284 , V_63 ) ;
#if F_51 ( V_295 ) && F_51 ( F_21 )
if ( V_281 -> V_296 )
F_140 () ;
#endif
F_141 ( V_281 ) ;
}
return 0 ;
}
static void F_142 ( void )
{
F_143 () ;
F_144 () ;
}
static int F_145 ( T_12 V_309 )
{
int error = 0 ;
while ( ! V_44 . V_45 )
F_19 () ;
F_146 () ;
#ifdef F_147
if ( F_148 ( V_310 ) )
F_149 () ;
#endif
switch ( V_17 ) {
case V_18 :
error = F_106 () ;
break;
case V_20 :
case V_19 :
error = F_89 () ;
break;
case V_25 :
error = F_99 () ;
break;
default:
return - V_258 ;
}
if ( error )
return error ;
F_94 ( 100 ) ;
return 0 ;
}
static void F_150 ( void )
{
V_89 = 1 ;
V_47 ( 0 , NULL ) ;
F_94 ( 10 ) ;
F_151 () ;
F_152 () ;
}
static int F_153 ( T_12 V_309 )
{
return V_309 == V_311
&& ( F_25 ( V_133 , NULL , 0 , - 1 ) >= 0 ) ;
}
static int F_154 ( void )
{
if ( V_17 == V_18 )
F_105 () ;
V_312 . V_313 = F_142 ;
V_312 . V_314 = F_150 ;
F_155 ( & V_315 ) ;
return 0 ;
}
static int F_156 ( struct V_127 * V_306 ,
T_13 V_316 , T_14 V_211 )
{
T_15 T_5 * V_317 = ( T_15 T_5 * ) V_211 ;
int error = - V_142 ;
switch ( V_316 ) {
case V_318 :
if ( ! F_157 ( V_319 ) )
return - V_320 ;
return F_158 ( V_311 ) ;
case V_321 :
if ( F_25 ( V_133 , NULL , 0 , - 1 ) < 0 )
return F_159 ( 0 , V_317 ) ;
else
return F_159 ( 1 , V_317 ) ;
#ifdef F_160
case V_322 :
{
int V_323 ;
V_323 = F_161 () ;
if ( V_323 < 0 )
return V_323 ;
else
return F_159 ( V_323 , V_317 ) ;
}
case V_324 :
{
int V_323 ;
error = F_162 ( V_323 , V_317 ) ;
if ( error )
return error ;
return F_163 ( V_323 ) ;
}
#ifdef V_295
case V_325 : {
struct V_280 * V_281 = V_306 -> V_297 ;
if ( V_281 -> V_296 )
return 0 ;
V_281 -> V_296 = 1 ;
F_164 () ;
return 0 ;
}
#endif
#endif
case V_326 :
return F_159 ( V_17 , V_317 ) ;
case V_327 :
return F_159 ( V_9 , V_317 ) ;
}
return error ;
}
static long F_165 ( struct V_127 * V_306 ,
T_13 V_316 , T_14 V_211 )
{
int V_146 ;
F_122 ( & V_294 ) ;
V_146 = F_156 ( V_306 , V_316 , V_211 ) ;
F_124 ( & V_294 ) ;
return V_146 ;
}
static long F_166 ( struct V_127 * V_306 , T_13 V_316 , T_14 V_211 )
{
switch ( V_316 ) {
case V_318 :
break;
case V_328 :
V_316 = V_322 ;
break;
case V_329 :
V_316 = V_324 ;
break;
case V_330 :
V_316 = V_326 ;
break;
case V_331 :
V_316 = V_327 ;
break;
case V_332 :
V_316 = V_321 ;
break;
case V_333 :
V_316 = V_325 ;
break;
default:
return - V_334 ;
}
return F_165 ( V_306 , V_316 , ( unsigned long ) F_167 ( V_211 ) ) ;
}
static int F_168 ( void )
{
if ( ! V_3 )
return 0 ;
if ( F_169 ( & V_335 ) < 0 )
F_4 ( V_5 L_78 ) ;
return 0 ;
}
static inline void
F_170 ( volatile unsigned char T_9 * V_3 )
{
V_3 [ V_83 ] &= ~ V_84 ; F_171 () ;
while ( ( V_3 [ V_83 ] & V_86 ) != 0 )
;
V_3 [ V_83 ] |= V_84 ; F_171 () ;
while ( ( V_3 [ V_83 ] & V_86 ) == 0 )
;
}
static inline void
F_172 ( volatile unsigned char T_9 * V_3 , int V_175 )
{
V_3 [ V_176 ] |= V_177 | V_178 ; F_171 () ;
V_3 [ V_179 ] = V_175 ; F_171 () ;
F_170 ( V_3 ) ;
}
static inline int
F_173 ( volatile unsigned char T_9 * V_3 )
{
int V_175 ;
V_3 [ V_176 ] = ( V_3 [ V_176 ] & ~ V_177 ) | V_178 ; F_171 () ;
V_175 = V_3 [ V_179 ] ; F_171 () ;
F_170 ( V_3 ) ;
V_175 = V_3 [ V_179 ] ; F_171 () ;
return V_175 ;
}
int
F_174 ( struct V_81 * V_82 )
{
unsigned long V_63 ;
int V_70 , V_336 , V_337 ;
volatile unsigned char T_9 * V_125 = V_3 ;
V_82 -> V_45 = 1 ;
V_337 = V_82 -> V_148 [ 0 ] ;
V_336 = V_151 [ V_337 ] [ 0 ] ;
if ( V_336 >= 0 && V_82 -> V_150 != V_336 + 1 )
return - V_142 ;
F_175 ( V_63 ) ;
while ( V_33 != V_34 )
F_19 () ;
while ( ( V_3 [ V_83 ] & V_86 ) == 0 )
;
F_172 ( V_125 , V_337 ) ;
if ( V_336 < 0 ) {
V_336 = V_82 -> V_150 - 1 ;
F_172 ( V_125 , V_336 ) ;
}
for ( V_70 = 1 ; V_70 <= V_336 ; ++ V_70 )
F_172 ( V_125 , V_82 -> V_148 [ V_70 ] ) ;
V_336 = V_151 [ V_337 ] [ 1 ] ;
if ( V_336 < 0 )
V_336 = F_173 ( V_125 ) ;
for ( V_70 = 0 ; V_70 < V_336 ; ++ V_70 )
V_82 -> V_93 [ V_70 + V_82 -> V_92 ] = F_173 ( V_125 ) ;
if ( V_82 -> V_166 )
(* V_82 -> V_166 )( V_82 ) ;
F_176 ( V_63 ) ;
return 0 ;
}
void F_177 ( int V_338 )
{
struct V_81 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
for (; V_338 > 0 ; -- V_338 ) {
V_82 . V_150 = 4 ;
V_82 . V_166 = NULL ;
V_82 . V_148 [ 0 ] = 0xee ;
V_82 . V_148 [ 1 ] = 4 ;
V_82 . V_148 [ 2 ] = 0 ;
V_82 . V_148 [ 3 ] = 1 ;
V_82 . V_93 [ 0 ] = V_152 ;
V_82 . V_92 = 1 ;
V_82 . V_161 = 0 ;
F_174 ( & V_82 ) ;
F_94 ( 50 ) ;
V_82 . V_150 = 4 ;
V_82 . V_166 = NULL ;
V_82 . V_148 [ 0 ] = 0xee ;
V_82 . V_148 [ 1 ] = 4 ;
V_82 . V_148 [ 2 ] = 0 ;
V_82 . V_148 [ 3 ] = 0 ;
V_82 . V_93 [ 0 ] = V_152 ;
V_82 . V_92 = 1 ;
V_82 . V_161 = 0 ;
F_174 ( & V_82 ) ;
F_94 ( 50 ) ;
}
F_94 ( 50 ) ;
}
static int F_178 ( void )
{
F_69 () ;
V_339 = 1 ;
#ifdef F_21
F_179 ( 1 ) ;
#endif
return 0 ;
}
static void F_180 ( void )
{
struct V_81 V_82 ;
if ( ! V_339 )
return;
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
F_31 ( & V_82 ) ;
#ifdef F_21
F_179 ( 0 ) ;
#endif
F_71 () ;
V_339 = 0 ;
}
static int F_181 ( void )
{
F_182 ( & V_340 ) ;
return 0 ;
}
