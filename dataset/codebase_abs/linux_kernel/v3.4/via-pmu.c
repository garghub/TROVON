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
}
if ( V_27 == NULL ) {
F_4 ( V_5 L_12 ) ;
goto V_28;
}
} else
V_17 = V_29 ;
V_3 = F_10 ( V_1 , 0x2000 ) ;
if ( V_3 == NULL ) {
F_4 ( V_5 L_13 ) ;
goto V_6;
}
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
V_33 = V_34 ;
if ( ! F_12 () ) {
V_3 = NULL ;
return 0 ;
}
F_4 ( V_35 L_14 ,
V_36 , V_37 [ V_17 ] , V_38 ) ;
V_39 = V_40 ;
return 1 ;
V_6:
F_9 ( V_4 ) ;
F_13 ( V_27 ) ;
V_27 = NULL ;
V_28:
V_4 = NULL ;
return 0 ;
}
static int F_14 ( void )
{
return V_4 == NULL ? - V_41 : 0 ;
}
static int T_1 F_15 ( void )
{
if ( V_4 == NULL )
return - V_41 ;
return 0 ;
}
static int T_1 F_16 ( void )
{
unsigned int V_42 ;
if ( V_4 == NULL )
return - V_41 ;
V_43 . V_44 = 1 ;
V_42 = F_17 ( V_4 , 0 ) ;
if ( V_42 == V_45 ) {
F_4 ( V_5 L_15 ) ;
return - V_41 ;
}
if ( F_18 ( V_42 , V_46 , V_47 ,
L_16 , ( void * ) 0 ) ) {
F_4 ( V_5 L_17 , V_42 ) ;
return - V_41 ;
}
if ( V_17 == V_25 ) {
V_48 = F_2 ( NULL , L_18 ) ;
if ( V_48 == NULL )
V_48 = F_2 ( NULL ,
L_19 ) ;
if ( V_48 )
V_49 = F_17 ( V_48 , 0 ) ;
if ( V_49 != V_45 ) {
if ( F_18 ( V_49 , V_50 , V_51 ,
L_20 , ( void * ) 0 ) )
F_4 ( V_5 L_21
L_22 , V_49 ) ;
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
return - V_41 ;
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
while ( ! V_82 . V_44 ) {
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
V_46 ( 0 , NULL ) ;
F_30 ( 10 ) ;
}
if ( V_17 == V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
while ( ! V_82 . V_44 )
F_19 () ;
}
F_29 ( & V_82 , NULL , 1 , V_91 ) ;
F_31 ( & V_82 ) ;
if ( V_82 . V_92 > 0 )
V_38 = V_82 . V_93 [ 0 ] ;
if ( V_17 == V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_94 ,
V_95 ) ;
F_31 ( & V_82 ) ;
if ( V_82 . V_92 == 2 ) {
if ( V_82 . V_93 [ 1 ] & V_96 )
V_97 = 1 ;
F_4 ( V_35 L_36 ,
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
F_4 ( V_121 L_39 ,
V_82 -> V_92 , V_82 -> V_93 [ 0 ] , V_82 -> V_93 [ 1 ] , V_82 -> V_93 [ 2 ] , V_82 -> V_93 [ 3 ] ) ;
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
F_37 ( void )
{
if ( F_38 ( 0 , & V_119 ) )
return;
if ( V_17 == V_18 )
F_29 ( & V_43 , F_34 ,
1 , V_122 ) ;
else
F_29 ( & V_43 , F_36 ,
2 , V_123 , V_116 + 1 ) ;
}
static int F_39 ( struct V_124 * V_125 , void * V_126 )
{
F_40 ( V_125 , L_40 , V_36 ) ;
F_40 ( V_125 , L_41 , V_38 ) ;
F_40 ( V_125 , L_42 ,
( ( V_112 & V_113 ) != 0 ) || V_60 == 0 ) ;
F_40 ( V_125 , L_43 , V_60 ) ;
return 0 ;
}
static int F_41 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_42 ( V_128 , F_39 , NULL ) ;
}
static int F_43 ( struct V_124 * V_125 , void * V_126 )
{
int V_70 ;
static const char * V_129 [] = {
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54
} ;
for ( V_70 = 0 ; V_70 < 11 ; V_70 ++ ) {
F_40 ( V_125 , L_55 ,
V_70 , V_130 [ V_70 ] , V_129 [ V_70 ] ) ;
}
return 0 ;
}
static int F_44 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_42 ( V_128 , F_43 , NULL ) ;
}
static int F_45 ( struct V_124 * V_125 , void * V_126 )
{
long V_131 = ( long ) V_125 -> V_132 ;
F_46 ( V_125 , '\n' ) ;
F_40 ( V_125 , L_56 , V_62 [ V_131 ] . V_63 ) ;
F_40 ( V_125 , L_57 , V_62 [ V_131 ] . V_103 ) ;
F_40 ( V_125 , L_58 , V_62 [ V_131 ] . V_117 ) ;
F_40 ( V_125 , L_59 , V_62 [ V_131 ] . V_109 ) ;
F_40 ( V_125 , L_60 , V_62 [ V_131 ] . V_110 ) ;
F_40 ( V_125 , L_61 , V_62 [ V_131 ] . V_118 ) ;
return 0 ;
}
static int F_47 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_42 ( V_128 , F_45 , F_48 ( V_127 ) -> V_133 ) ;
}
static int F_49 ( struct V_124 * V_125 , void * V_126 )
{
#if F_50 ( V_134 ) && F_50 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_135 , NULL , 0 , - 1 ) >= 0 )
F_40 ( V_125 , L_62 , V_136 ) ;
#endif
if ( V_17 == V_25 )
F_40 ( V_125 , L_63 , V_97 ) ;
return 0 ;
}
static int F_51 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_42 ( V_128 , F_49 , NULL ) ;
}
static T_4 F_52 ( struct V_128 * V_128 ,
const char T_5 * V_137 , T_6 V_138 , T_7 * V_139 )
{
char V_140 [ 33 ] ;
char * V_141 , * V_142 ;
T_6 V_143 = V_138 ;
if ( ! V_138 )
return - V_144 ;
if ( V_138 > 32 )
V_138 = 32 ;
if ( F_53 ( V_140 , V_137 , V_138 ) )
return - V_145 ;
V_140 [ V_138 ] = 0 ;
V_141 = V_140 ;
while( * V_141 == ' ' )
V_141 ++ ;
V_142 = V_141 ;
while( * V_142 && ( * V_142 != '=' ) ) {
if ( * V_142 == ' ' )
* V_142 = 0 ;
V_142 ++ ;
}
if ( ( * V_142 ) == 0 )
return - V_144 ;
* ( V_142 ++ ) = 0 ;
while( * V_142 == ' ' )
V_142 ++ ;
#if F_50 ( V_134 ) && F_50 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_135 , NULL , 0 , - 1 ) >= 0 )
if ( ! strcmp ( V_141 , L_64 ) )
V_136 = ( ( * V_142 ) == '1' ) ;
#endif
if ( V_17 == V_25 && ! strcmp ( V_141 , L_65 ) ) {
int V_146 ;
V_146 = ( ( * V_142 ) == '1' ) ;
if ( V_146 != V_97 )
F_33 ( V_146 ) ;
}
return V_143 ;
}
static int F_54 ( struct V_81 * V_82 , int V_147 )
{
int V_70 , V_148 ;
if ( ( V_4 == NULL ) || ( ! V_56 ) ) {
V_82 -> V_44 = 1 ;
return - V_149 ;
}
V_148 = - V_144 ;
switch ( V_82 -> V_133 [ 0 ] ) {
case V_150 :
for ( V_70 = 0 ; V_70 < V_82 -> V_151 - 1 ; ++ V_70 )
V_82 -> V_133 [ V_70 ] = V_82 -> V_133 [ V_70 + 1 ] ;
-- V_82 -> V_151 ;
if ( V_152 [ V_82 -> V_133 [ 0 ] ] [ 1 ] != 0 ) {
V_82 -> V_93 [ 0 ] = V_153 ;
V_82 -> V_92 = 1 ;
} else
V_82 -> V_92 = 0 ;
V_148 = F_55 ( V_82 ) ;
break;
case V_154 :
switch ( V_82 -> V_133 [ 1 ] ) {
case V_155 :
if ( V_82 -> V_151 != 2 )
break;
V_82 -> V_133 [ 0 ] = V_156 ;
V_82 -> V_151 = 1 ;
V_82 -> V_92 = 3 ;
V_82 -> V_93 [ 0 ] = V_154 ;
V_82 -> V_93 [ 1 ] = 0 ;
V_82 -> V_93 [ 2 ] = V_155 ;
V_148 = F_55 ( V_82 ) ;
break;
case V_157 :
if ( V_82 -> V_151 != 6 )
break;
V_82 -> V_133 [ 0 ] = V_158 ;
V_82 -> V_151 = 5 ;
for ( V_70 = 1 ; V_70 <= 4 ; ++ V_70 )
V_82 -> V_133 [ V_70 ] = V_82 -> V_133 [ V_70 + 1 ] ;
V_82 -> V_92 = 3 ;
V_82 -> V_93 [ 0 ] = V_154 ;
V_82 -> V_93 [ 1 ] = 0 ;
V_82 -> V_93 [ 2 ] = V_157 ;
V_148 = F_55 ( V_82 ) ;
break;
}
break;
case V_159 :
if ( ! V_9 )
return - V_149 ;
for ( V_70 = V_82 -> V_151 - 1 ; V_70 > 1 ; -- V_70 )
V_82 -> V_133 [ V_70 + 2 ] = V_82 -> V_133 [ V_70 ] ;
V_82 -> V_133 [ 3 ] = V_82 -> V_151 - 2 ;
V_82 -> V_133 [ 2 ] = V_160 ;
V_82 -> V_133 [ 0 ] = V_161 ;
V_82 -> V_151 += 2 ;
V_82 -> V_162 = 1 ;
V_82 -> V_92 = 0 ;
V_148 = F_55 ( V_82 ) ;
break;
}
if ( V_148 ) {
V_82 -> V_44 = 1 ;
return V_148 ;
}
if ( V_147 )
while ( ! V_82 -> V_44 )
F_19 () ;
return 0 ;
}
static int F_56 ( int V_163 )
{
struct V_81 V_82 ;
if ( V_163 ) {
F_29 ( & V_82 , NULL , 5 , V_161 , 0 , 0x86 ,
V_164 >> 8 , V_164 ) ;
V_160 = 2 ;
} else {
F_29 ( & V_82 , NULL , 1 , V_165 ) ;
V_160 = 0 ;
}
while ( ! V_82 . V_44 )
F_19 () ;
return 0 ;
}
static int F_57 ( int V_163 )
{
if ( ( V_4 == NULL ) || ( ! V_56 ) || ! V_9 )
return - V_149 ;
V_164 = V_163 ;
return F_56 ( V_163 ) ;
}
static int F_58 ( void )
{
struct V_81 V_82 ;
int V_166 = V_164 ;
if ( ( V_4 == NULL ) || ( ! V_56 ) || ! V_9 )
return - V_149 ;
F_56 ( 0 ) ;
V_82 . V_151 = 4 ;
V_82 . V_167 = NULL ;
V_82 . V_133 [ 0 ] = V_161 ;
V_82 . V_133 [ 1 ] = V_168 ;
V_82 . V_133 [ 2 ] = 0 ;
V_82 . V_133 [ 3 ] = 0 ;
V_82 . V_133 [ 4 ] = 0 ;
V_82 . V_92 = 0 ;
V_82 . V_162 = 1 ;
if ( F_55 ( & V_82 ) != 0 ) {
F_4 ( V_5 L_66 ) ;
return - V_169 ;
}
F_31 ( & V_82 ) ;
if ( V_166 != 0 )
F_56 ( V_166 ) ;
return 0 ;
}
int
F_29 ( struct V_81 * V_82 , void (* V_167)( struct V_81 * ) ,
int V_151 , ... )
{
T_8 V_170 ;
int V_70 ;
if ( V_4 == NULL )
return - V_149 ;
if ( V_151 < 0 || V_151 > 32 ) {
F_4 ( V_5 L_67 , V_151 ) ;
V_82 -> V_44 = 1 ;
return - V_144 ;
}
V_82 -> V_151 = V_151 ;
V_82 -> V_167 = V_167 ;
va_start ( V_170 , V_151 ) ;
for ( V_70 = 0 ; V_70 < V_151 ; ++ V_70 )
V_82 -> V_133 [ V_70 ] = va_arg ( V_170 , int ) ;
va_end ( V_170 ) ;
V_82 -> V_92 = 0 ;
V_82 -> V_162 = 0 ;
return F_55 ( V_82 ) ;
}
int
F_55 ( struct V_81 * V_82 )
{
unsigned long V_63 ;
int V_171 ;
if ( V_3 == NULL ) {
V_82 -> V_44 = 1 ;
return - V_149 ;
}
if ( V_82 -> V_151 <= 0 ) {
V_82 -> V_44 = 1 ;
return 0 ;
}
V_171 = V_152 [ V_82 -> V_133 [ 0 ] ] [ 0 ] ;
if ( V_171 >= 0 && V_82 -> V_151 != V_171 + 1 ) {
V_82 -> V_44 = 1 ;
return - V_144 ;
}
V_82 -> V_172 = NULL ;
V_82 -> V_173 = 0 ;
V_82 -> V_44 = 0 ;
F_59 ( & V_8 , V_63 ) ;
if ( V_174 != 0 ) {
V_175 -> V_172 = V_82 ;
V_175 = V_82 ;
} else {
V_174 = V_82 ;
V_175 = V_82 ;
if ( V_33 == V_34 )
F_60 () ;
}
F_61 ( & V_8 , V_63 ) ;
return 0 ;
}
static inline void
F_62 ( void )
{
int V_80 = 4000 ;
while ( ( F_63 ( & V_3 [ V_83 ] ) & V_86 ) == 0 ) {
if ( -- V_80 < 0 ) {
F_4 ( V_5 L_68 ) ;
return;
}
F_30 ( 10 ) ;
}
}
static inline void
F_64 ( int V_176 )
{
volatile unsigned char T_9 * V_126 = V_3 ;
F_11 ( & V_126 [ V_177 ] , F_63 ( & V_126 [ V_177 ] ) | V_178 | V_179 ) ;
F_11 ( & V_126 [ V_180 ] , V_176 ) ;
F_11 ( & V_126 [ V_83 ] , F_63 ( & V_126 [ V_83 ] ) & ~ V_84 ) ;
( void ) F_63 ( & V_126 [ V_83 ] ) ;
}
static inline void
F_65 ( void )
{
volatile unsigned char T_9 * V_126 = V_3 ;
F_11 ( & V_126 [ V_177 ] , ( F_63 ( & V_126 [ V_177 ] ) & ~ V_178 ) | V_179 ) ;
F_63 ( & V_126 [ V_180 ] ) ;
F_11 ( & V_126 [ V_83 ] , F_63 ( & V_126 [ V_83 ] ) & ~ V_84 ) ;
( void ) F_63 ( & V_126 [ V_83 ] ) ;
}
static inline void
F_66 ( struct V_81 * V_82 )
{
void (* V_167)( struct V_81 * ) = V_82 -> V_167 ;
V_57 () ;
V_82 -> V_44 = 1 ;
if ( V_167 )
(* V_167)( V_82 ) ;
}
static void
F_60 ( void )
{
struct V_81 * V_82 ;
V_82 = V_174 ;
if ( V_82 == 0 || V_33 != V_34
|| ( V_181 ) )
return;
V_33 = V_182 ;
V_183 = 1 ;
V_184 = V_152 [ V_82 -> V_133 [ 0 ] ] [ 0 ] ;
F_62 () ;
F_64 ( V_82 -> V_133 [ 0 ] ) ;
}
void
F_19 ( void )
{
if ( ! V_3 )
return;
if ( V_185 )
return;
V_46 ( 0 , NULL ) ;
}
void
F_67 ( void )
{
if ( ! V_3 )
return;
if ( V_185 )
return;
V_89 = 1 ;
do {
V_46 ( 0 , NULL ) ;
} while ( V_186 && ( V_89 || V_33 != V_34
|| V_181 ) );
}
void
F_31 ( struct V_81 * V_82 )
{
if ( ! V_3 )
return;
while( ( V_33 != V_34 && V_33 != V_187 ) || ! V_82 -> V_44 )
V_46 ( 0 , NULL ) ;
}
void
F_68 ( void )
{
unsigned long V_63 ;
if ( ! V_3 )
return;
F_59 ( & V_8 , V_63 ) ;
V_186 ++ ;
if ( V_186 > 1 ) {
F_61 ( & V_8 , V_63 ) ;
return;
}
do {
F_61 ( & V_8 , V_63 ) ;
if ( V_181 )
V_89 = 1 ;
V_46 ( 0 , NULL ) ;
F_59 ( & V_8 , V_63 ) ;
if ( ! V_89 && V_33 == V_34 && ! V_181 ) {
if ( V_49 >= 0 )
F_69 ( V_49 ) ;
F_11 ( & V_3 [ V_30 ] , V_55 | V_31 ) ;
F_61 ( & V_8 , V_63 ) ;
break;
}
} while ( 1 );
}
void
F_70 ( void )
{
unsigned long V_63 ;
if ( ! V_3 || ( V_186 < 1 ) )
return;
F_59 ( & V_8 , V_63 ) ;
V_186 -- ;
if ( V_186 > 0 ) {
F_61 ( & V_8 , V_63 ) ;
return;
}
V_89 = 1 ;
if ( V_49 >= 0 )
F_71 ( V_49 ) ;
F_11 ( & V_3 [ V_30 ] , V_55 | V_53 ) ;
F_61 ( & V_8 , V_63 ) ;
F_19 () ;
}
static void
F_72 ( unsigned char * V_133 , int V_188 )
{
unsigned char V_189 , V_190 ;
int V_70 = 0 ;
V_191 = 0 ;
if ( V_192 || V_188 < 1 ) {
V_89 = 0 ;
V_130 [ 8 ] ++ ;
return;
}
V_189 = V_133 [ 0 ] ;
if ( V_189 == 0 )
V_130 [ 9 ] ++ ;
if ( V_189 & V_13 )
V_189 &= ~ ( V_193 | V_194 ) ;
V_172:
if ( V_189 == 0 ) {
if ( V_70 > V_130 [ 10 ] )
V_130 [ 10 ] = V_70 ;
return;
}
for ( V_190 = 0 ; V_190 < 8 ; V_190 ++ )
if ( V_189 & ( 1 << V_190 ) )
break;
V_130 [ V_190 ] ++ ;
V_70 ++ ;
V_189 &= ~ ( 1 << V_190 ) ;
if ( ( 1 << V_190 ) & V_13 ) {
if ( ( V_133 [ 0 ] & V_193 ) == 0 ) {
struct V_81 * V_82 = V_181 ;
if ( V_82 == 0 ) {
F_4 ( V_5 L_69 ) ;
return;
}
V_181 = NULL ;
if ( V_188 <= 2 )
V_82 -> V_92 = 0 ;
else {
memcpy ( V_82 -> V_93 , V_133 + 1 , V_188 - 1 ) ;
V_82 -> V_92 = V_188 - 1 ;
}
F_66 ( V_82 ) ;
} else {
if ( V_188 == 4 && V_133 [ 1 ] == 0x2c ) {
extern int V_195 , V_196 ;
if ( V_195 ) {
V_196 = V_133 [ 2 ] ;
return;
}
}
#ifdef F_73
if ( ! ( V_17 == V_18 && V_188 == 4
&& V_133 [ 1 ] == 0x2c && V_133 [ 3 ] == 0xff
&& ( V_133 [ 2 ] & ~ 1 ) == 0xf4 ) )
F_74 ( V_133 + 1 , V_188 - 1 , 1 ) ;
#endif
}
}
else if ( ( 1 << V_190 ) & V_12 ) {
#ifdef F_21
if ( V_188 == 3 )
F_75 ( V_133 [ 1 ] >> 4 ) ;
#endif
}
else if ( ( 1 << V_190 ) & V_14 ) {
if ( V_60 ) {
if ( ( -- V_197 ) == 0 ) {
F_37 () ;
V_197 = V_198 ;
}
}
}
else if ( ( 1 << V_190 ) & V_26 ) {
if ( V_60 )
F_37 () ;
F_76 ( V_133 , V_188 ) ;
if ( V_188 == 6 ) {
F_77 ( V_199 , ! ! ( V_133 [ 1 ] & 8 ) ) ;
F_77 ( V_200 , V_133 [ 1 ] & 1 ) ;
}
} else {
F_76 ( V_133 , V_188 ) ;
}
goto V_172;
}
static struct V_81 *
F_78 ( void )
{
struct V_81 * V_82 ;
int V_201 = 0 ;
if ( V_3 [ V_83 ] & V_84 ) {
F_4 ( V_5 L_70 , V_3 [ V_83 ] ) ;
F_11 ( & V_3 [ V_32 ] , V_54 ) ;
return NULL ;
}
while ( ( F_63 ( & V_3 [ V_83 ] ) & V_86 ) != 0 )
;
if ( V_33 == V_202 || V_33 == V_203 )
V_201 = F_63 ( & V_3 [ V_180 ] ) ;
F_11 ( & V_3 [ V_83 ] , F_63 ( & V_3 [ V_83 ] ) | V_84 ) ;
F_62 () ;
switch ( V_33 ) {
case V_182 :
V_82 = V_174 ;
if ( V_184 < 0 ) {
V_184 = V_82 -> V_151 - 1 ;
F_64 ( V_184 ) ;
break;
}
if ( V_183 <= V_184 ) {
F_64 ( V_82 -> V_133 [ V_183 ++ ] ) ;
break;
}
V_82 -> V_173 = 1 ;
V_184 = V_152 [ V_82 -> V_133 [ 0 ] ] [ 1 ] ;
if ( V_184 == 0 ) {
V_33 = V_34 ;
V_174 = V_82 -> V_172 ;
if ( V_82 -> V_162 )
V_181 = V_82 ;
else
return V_82 ;
} else {
V_33 = V_202 ;
V_183 = 0 ;
V_204 = V_82 -> V_93 + V_82 -> V_92 ;
F_65 () ;
}
break;
case V_205 :
V_183 = 0 ;
V_184 = - 1 ;
V_33 = V_203 ;
V_204 = V_88 [ V_206 ] ;
F_65 () ;
if ( V_49 >= 0 && ! V_52 ) {
F_71 ( V_49 ) ;
V_52 = 1 ;
}
break;
case V_202 :
case V_203 :
if ( V_184 == - 1 ) {
V_184 = V_201 ;
if ( V_201 > 32 )
F_4 ( V_5 L_71 , V_201 ) ;
} else if ( V_183 < 32 ) {
V_204 [ V_183 ++ ] = V_201 ;
}
if ( V_183 < V_184 ) {
F_65 () ;
break;
}
if ( V_33 == V_203 ) {
V_33 = V_34 ;
V_207 [ V_206 ] = V_208 ;
V_209 [ V_206 ] = V_184 ;
} else {
V_82 = V_174 ;
V_174 = V_82 -> V_172 ;
V_82 -> V_92 += V_183 ;
if ( V_82 -> V_133 [ 0 ] == V_210 || V_82 -> V_133 [ 0 ] == V_211 )
V_33 = V_187 ;
else
V_33 = V_34 ;
return V_82 ;
}
break;
default:
F_4 ( V_5 L_72 ,
V_33 ) ;
}
return NULL ;
}
static T_10
V_46 ( int V_42 , void * V_212 )
{
unsigned long V_63 ;
int V_213 ;
int V_214 = 0 ;
int V_215 = - 1 ;
struct V_81 * V_82 = NULL ;
int V_216 = 0 ;
F_59 ( & V_8 , V_63 ) ;
++ V_185 ;
for (; ; ) {
V_213 = F_63 ( & V_3 [ V_32 ] ) & ( V_54 | V_55 ) ;
if ( V_213 == 0 )
break;
V_216 = 1 ;
if ( ++ V_214 > 1000 ) {
F_4 ( V_217 L_73
L_74 ,
V_213 , F_63 ( & V_3 [ V_30 ] ) , V_33 ) ;
break;
}
F_11 ( & V_3 [ V_32 ] , V_213 ) ;
if ( V_213 & V_55 ) {
V_89 = 1 ;
V_130 [ 0 ] ++ ;
}
if ( V_213 & V_54 ) {
V_82 = F_78 () ;
if ( V_82 )
break;
}
}
V_218:
if ( V_33 == V_34 ) {
if ( V_89 ) {
if ( V_207 [ 0 ] == V_219 )
V_206 = 0 ;
else if ( V_207 [ 1 ] == V_219 )
V_206 = 1 ;
else
goto V_220;
V_33 = V_205 ;
V_207 [ V_206 ] = V_221 ;
F_62 () ;
F_64 ( V_222 ) ;
V_89 = 0 ;
} else if ( V_174 )
F_60 () ;
}
V_220:
if ( V_207 [ ! V_206 ] == V_208 ) {
V_207 [ ! V_206 ] = V_223 ;
V_215 = ! V_206 ;
} else if ( V_207 [ V_206 ] == V_208 ) {
V_207 [ V_206 ] = V_223 ;
V_215 = V_206 ;
}
-- V_185 ;
F_61 ( & V_8 , V_63 ) ;
if ( V_82 ) {
F_66 ( V_82 ) ;
V_82 = NULL ;
}
if ( V_215 >= 0 ) {
F_72 ( V_88 [ V_215 ] , V_209 [ V_215 ] ) ;
F_59 ( & V_8 , V_63 ) ;
++ V_185 ;
V_207 [ V_215 ] = V_219 ;
V_215 = - 1 ;
goto V_218;
}
return F_79 ( V_216 ) ;
}
void
F_80 ( void )
{
unsigned long V_63 ;
F_59 ( & V_8 , V_63 ) ;
if ( V_33 == V_187 )
V_33 = V_34 ;
V_89 = 1 ;
F_61 ( & V_8 , V_63 ) ;
}
static T_10
V_50 ( int V_42 , void * V_212 )
{
unsigned long V_63 ;
if ( ( F_63 ( V_27 + 0x9 ) & 0x02 ) == 0 ) {
F_59 ( & V_8 , V_63 ) ;
if ( V_52 > 0 ) {
F_69 ( V_49 ) ;
V_52 = 0 ;
}
V_130 [ 1 ] ++ ;
V_89 = 1 ;
F_61 ( & V_8 , V_63 ) ;
V_46 ( 0 , NULL ) ;
return V_224 ;
}
return V_225 ;
}
void
F_81 ( int V_226 )
{
struct V_81 V_82 ;
if ( V_4 == NULL )
return ;
if ( V_17 == V_25 )
return ;
F_29 ( & V_82 , NULL , 2 , V_227 , V_228 |
( V_226 ? V_229 : V_230 ) ) ;
F_31 ( & V_82 ) ;
}
void
F_82 ( void )
{
struct V_81 V_82 ;
if ( V_3 == NULL )
return;
F_83 () ;
V_192 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_87 , V_13 |
V_14 ) ;
while( ! V_82 . V_44 )
F_19 () ;
}
F_29 ( & V_82 , NULL , 1 , V_231 ) ;
F_31 ( & V_82 ) ;
for (; ; )
;
}
void
F_84 ( void )
{
struct V_81 V_82 ;
if ( V_3 == NULL )
return;
F_83 () ;
V_192 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_82 , NULL , 2 , V_87 , V_13 |
V_14 ) ;
F_31 ( & V_82 ) ;
} else {
F_33 ( 0 ) ;
}
F_29 ( & V_82 , NULL , 5 , V_232 ,
'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
for (; ; )
;
}
int
F_85 ( void )
{
return V_3 != 0 ;
}
static void
F_86 ( void )
{
V_233 [ 0 ] = F_63 ( & V_3 [ V_234 ] ) ;
V_233 [ 1 ] = F_63 ( & V_3 [ V_235 ] ) ;
V_233 [ 2 ] = F_63 ( & V_3 [ V_83 ] ) ;
V_233 [ 3 ] = F_63 ( & V_3 [ V_85 ] ) ;
V_233 [ 4 ] = F_63 ( & V_3 [ V_236 ] ) ;
V_233 [ 5 ] = F_63 ( & V_3 [ V_177 ] ) ;
V_233 [ 6 ] = F_63 ( & V_3 [ V_237 ] ) ;
V_233 [ 7 ] = F_63 ( & V_3 [ V_238 ] ) ;
}
static void
F_87 ( void )
{
F_11 ( & V_3 [ V_234 ] , V_233 [ 0 ] ) ;
F_11 ( & V_3 [ V_235 ] , V_233 [ 1 ] ) ;
F_11 ( & V_3 [ V_83 ] , V_233 [ 2 ] ) ;
F_11 ( & V_3 [ V_85 ] , V_233 [ 3 ] ) ;
F_11 ( & V_3 [ V_236 ] , V_233 [ 4 ] ) ;
F_11 ( & V_3 [ V_177 ] , V_233 [ 5 ] ) ;
F_11 ( & V_3 [ V_237 ] , V_233 [ 6 ] ) ;
F_11 ( & V_3 [ V_238 ] , V_233 [ 7 ] ) ;
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
F_11 ( & V_3 [ V_30 ] , V_53 | V_54 | V_55 ) ;
}
static int F_88 ( void )
{
unsigned long V_239 ;
unsigned short V_240 ;
struct V_81 V_82 ;
struct V_241 * V_242 ;
V_242 = F_89 ( 0 , 0 ) ;
if ( ! V_242 )
return - V_41 ;
F_29 ( & V_82 , NULL , 2 , V_243 , V_244 | V_245 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_227 ,
V_230 | V_246 | V_228 | V_247 ) ;
F_31 ( & V_82 ) ;
V_239 = F_90 () ;
if ( ! V_248 ) {
F_29 ( & V_82 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
}
F_86 () ;
F_25 ( V_135 , NULL , 0 , 1 ) ;
F_91 ( V_242 , 0x70 , & V_240 ) ;
V_240 &= ~ ( V_249 | V_250 ) ;
V_240 |= V_251 | V_252 ;
F_92 ( V_242 , 0x70 , V_240 ) ;
if ( V_248 )
F_93 ( 5000 ) ;
else
F_94 () ;
F_91 ( V_242 , 0x70 , & V_240 ) ;
V_240 &= ~ ( V_251 | V_249 | V_250 | V_252 ) ;
F_92 ( V_242 , 0x70 , V_240 ) ;
F_95 ( V_242 ) ;
F_25 ( V_135 , NULL , 0 , 0 ) ;
F_87 () ;
if ( V_239 != 0xffffffff && ( V_239 & V_253 ) != 0 )
F_96 ( V_239 ) ;
F_97 ( NULL , V_254 -> V_255 ) ;
F_80 () ;
F_29 ( & V_82 , NULL , 2 , V_87 , V_10 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_243 ,
V_256 | V_245 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_227 ,
V_229 | V_246 | V_257 | V_228 | V_247 ) ;
F_31 ( & V_82 ) ;
return 0 ;
}
static int
F_98 ( void )
{
unsigned long V_239 ;
unsigned long V_258 ;
struct V_81 V_82 ;
if ( F_25 ( V_135 , NULL , 0 , - 1 ) < 0 ) {
F_4 ( V_5 L_75 ) ;
return - V_259 ;
}
if ( F_99 () > 1 || F_100 ( 0 ) )
return - V_260 ;
F_29 ( & V_82 , NULL , 2 , V_87 , 0 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 4 , V_94 , V_261 ,
0xff , 0xff ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 4 , V_94 , V_262 ,
0 , V_263 |
( V_136 ? V_264 : 0 ) ) ;
F_31 ( & V_82 ) ;
V_258 = F_101 () ;
V_239 = F_90 () ;
if ( ! V_248 ) {
F_29 ( & V_82 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_82 ) ;
}
F_86 () ;
F_25 ( V_135 , NULL , 0 , 1 ) ;
if ( V_248 )
F_93 ( 5000 ) ;
else
F_94 () ;
F_25 ( V_135 , NULL , 0 , 0 ) ;
F_87 () ;
V_265 *= 2 ;
F_102 () ;
if ( V_239 != 0xffffffff && ( V_239 & V_253 ) != 0 )
F_96 ( V_239 ) ;
if ( V_258 != 0xffffffff && ( V_258 & V_266 ) != 0 )
F_103 ( V_258 ) ;
F_97 ( NULL , V_254 -> V_255 ) ;
F_80 () ;
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
F_31 ( & V_82 ) ;
F_29 ( & V_82 , NULL , 2 , V_87 , V_10 ) ;
F_31 ( & V_82 ) ;
V_265 /= 2 ;
return 0 ;
}
static void F_104 ( void )
{
V_267 = F_10 ( V_268 , 0x100 ) ;
if ( V_267 == NULL )
F_4 ( V_121 L_76 ) ;
}
static int F_105 ( void )
{
int V_70 , V_176 ;
unsigned int V_269 ;
unsigned long V_270 ;
struct V_81 V_271 ;
unsigned int T_9 * V_272 ;
if ( V_267 == NULL )
return - V_273 ;
V_272 = V_267 + V_274 ;
for ( V_70 = 0x403f ; V_70 >= 0x4000 ; -- V_70 ) {
F_106 ( V_272 , V_70 ) ;
do {
V_176 = ( F_107 ( V_272 ) >> 16 ) & 0x3ff ;
} while ( V_176 == 0 );
if ( V_176 >= 0x100 )
break;
}
F_29 ( & V_271 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_271 ) ;
F_80 () ;
F_25 ( V_135 , NULL , 0 , 1 ) ;
V_191 = 1 ;
V_269 = F_108 ( V_275 ) ;
V_269 = ( V_269 & ~ ( V_276 | V_277 ) ) | V_278 ;
F_109 ( V_275 , V_269 ) ;
F_110 () ;
V_270 = F_111 () | V_279 ;
while ( V_191 ) {
V_57 () ;
F_112 ( V_270 ) ;
F_113 () ;
}
F_83 () ;
F_106 ( V_272 , 0x3f ) ;
F_25 ( V_135 , NULL , 0 , 0 ) ;
return 0 ;
}
static void
F_76 ( unsigned char * V_133 , int V_188 )
{
struct V_280 * V_281 ;
struct V_282 * V_170 ;
int V_70 ;
unsigned long V_63 ;
if ( V_188 > sizeof( V_281 -> V_283 [ 0 ] . V_133 ) )
V_188 = sizeof( V_281 -> V_283 [ 0 ] . V_133 ) ;
F_59 ( & V_284 , V_63 ) ;
for ( V_170 = & V_285 ; ( V_170 = V_170 -> V_172 ) != & V_285 ; ) {
V_281 = F_114 ( V_170 , struct V_280 , V_170 ) ;
F_115 ( & V_281 -> V_286 ) ;
V_70 = V_281 -> V_287 + 1 ;
if ( V_70 >= V_288 )
V_70 = 0 ;
if ( V_70 != V_281 -> V_289 ) {
struct V_290 * V_291 = & V_281 -> V_283 [ V_281 -> V_287 ] ;
V_291 -> V_188 = V_188 ;
memcpy ( V_291 -> V_133 , V_133 , V_188 ) ;
V_281 -> V_287 = V_70 ;
F_116 ( & V_281 -> V_292 ) ;
}
F_117 ( & V_281 -> V_286 ) ;
}
F_61 ( & V_284 , V_63 ) ;
}
static int
F_118 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_280 * V_281 ;
unsigned long V_63 ;
V_281 = F_119 ( sizeof( struct V_280 ) , V_293 ) ;
if ( V_281 == 0 )
return - V_273 ;
V_281 -> V_289 = V_281 -> V_287 = 0 ;
F_6 ( & V_281 -> V_286 ) ;
F_120 ( & V_281 -> V_292 ) ;
F_121 ( & V_294 ) ;
F_59 ( & V_284 , V_63 ) ;
#if F_50 ( V_295 ) && F_50 ( F_21 )
V_281 -> V_296 = 0 ;
#endif
F_122 ( & V_281 -> V_170 , & V_285 ) ;
F_61 ( & V_284 , V_63 ) ;
V_128 -> V_297 = V_281 ;
F_123 ( & V_294 ) ;
return 0 ;
}
static T_4
F_124 ( struct V_128 * V_128 , char T_5 * V_298 ,
T_6 V_138 , T_7 * V_299 )
{
struct V_280 * V_281 = V_128 -> V_297 ;
F_125 ( V_292 , V_254 ) ;
unsigned long V_63 ;
int V_148 = 0 ;
if ( V_138 < 1 || V_281 == 0 )
return - V_144 ;
if ( ! F_126 ( V_300 , V_298 , V_138 ) )
return - V_145 ;
F_59 ( & V_281 -> V_286 , V_63 ) ;
F_127 ( & V_281 -> V_292 , & V_292 ) ;
V_254 -> V_301 = V_302 ;
for (; ; ) {
V_148 = - V_260 ;
if ( V_281 -> V_289 != V_281 -> V_287 ) {
int V_70 = V_281 -> V_289 ;
struct V_290 * V_291 = & V_281 -> V_283 [ V_70 ] ;
V_148 = V_291 -> V_188 ;
F_61 ( & V_281 -> V_286 , V_63 ) ;
if ( V_148 > V_138 )
V_148 = V_138 ;
if ( V_148 > 0 && F_128 ( V_298 , V_291 -> V_133 , V_148 ) )
V_148 = - V_145 ;
if ( ++ V_70 >= V_288 )
V_70 = 0 ;
F_59 ( & V_281 -> V_286 , V_63 ) ;
V_281 -> V_289 = V_70 ;
}
if ( V_148 >= 0 )
break;
if ( V_128 -> V_303 & V_304 )
break;
V_148 = - V_305 ;
if ( F_129 ( V_254 ) )
break;
F_61 ( & V_281 -> V_286 , V_63 ) ;
F_130 () ;
F_59 ( & V_281 -> V_286 , V_63 ) ;
}
V_254 -> V_301 = V_306 ;
F_131 ( & V_281 -> V_292 , & V_292 ) ;
F_61 ( & V_281 -> V_286 , V_63 ) ;
return V_148 ;
}
static T_4
F_132 ( struct V_128 * V_128 , const char T_5 * V_298 ,
T_6 V_138 , T_7 * V_299 )
{
return 0 ;
}
static unsigned int
F_133 ( struct V_128 * V_307 , T_11 * V_292 )
{
struct V_280 * V_281 = V_307 -> V_297 ;
unsigned int V_308 = 0 ;
unsigned long V_63 ;
if ( V_281 == 0 )
return 0 ;
F_134 ( V_307 , & V_281 -> V_292 , V_292 ) ;
F_59 ( & V_281 -> V_286 , V_63 ) ;
if ( V_281 -> V_289 != V_281 -> V_287 )
V_308 |= V_309 ;
F_61 ( & V_281 -> V_286 , V_63 ) ;
return V_308 ;
}
static int
F_135 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_280 * V_281 = V_128 -> V_297 ;
unsigned long V_63 ;
if ( V_281 != 0 ) {
V_128 -> V_297 = NULL ;
F_59 ( & V_284 , V_63 ) ;
F_136 ( & V_281 -> V_170 ) ;
F_61 ( & V_284 , V_63 ) ;
#if F_50 ( V_295 ) && F_50 ( F_21 )
if ( V_281 -> V_296 )
F_137 () ;
#endif
F_138 ( V_281 ) ;
}
return 0 ;
}
static void F_139 ( void )
{
F_140 () ;
F_141 () ;
}
static int F_142 ( T_12 V_301 )
{
int error = 0 ;
while ( ! V_43 . V_44 )
F_19 () ;
F_143 () ;
#ifdef F_144
if ( F_145 ( V_310 ) )
F_146 () ;
#endif
switch ( V_17 ) {
case V_18 :
error = F_105 () ;
break;
case V_20 :
case V_19 :
error = F_88 () ;
break;
case V_25 :
error = F_98 () ;
break;
default:
return - V_259 ;
}
if ( error )
return error ;
F_93 ( 100 ) ;
return 0 ;
}
static void F_147 ( void )
{
V_89 = 1 ;
V_46 ( 0 , NULL ) ;
F_93 ( 10 ) ;
F_148 () ;
F_149 () ;
}
static int F_150 ( T_12 V_301 )
{
return V_301 == V_311
&& ( F_25 ( V_135 , NULL , 0 , - 1 ) >= 0 ) ;
}
static int F_151 ( void )
{
if ( V_17 == V_18 )
F_104 () ;
V_312 . V_313 = F_139 ;
V_312 . V_314 = F_147 ;
F_152 ( & V_315 ) ;
return 0 ;
}
static int F_153 ( struct V_128 * V_307 ,
T_13 V_316 , T_14 V_212 )
{
T_15 T_5 * V_317 = ( T_15 T_5 * ) V_212 ;
int error = - V_144 ;
switch ( V_316 ) {
case V_318 :
if ( ! F_154 ( V_319 ) )
return - V_320 ;
return F_155 ( V_311 ) ;
case V_321 :
if ( F_25 ( V_135 , NULL , 0 , - 1 ) < 0 )
return F_156 ( 0 , V_317 ) ;
else
return F_156 ( 1 , V_317 ) ;
#ifdef F_157
case V_322 :
{
int V_323 ;
V_323 = F_158 () ;
if ( V_323 < 0 )
return V_323 ;
else
return F_156 ( V_323 , V_317 ) ;
}
case V_324 :
{
int V_323 ;
error = F_159 ( V_323 , V_317 ) ;
if ( error )
return error ;
return F_160 ( V_323 ) ;
}
#ifdef V_295
case V_325 : {
struct V_280 * V_281 = V_307 -> V_297 ;
if ( V_281 -> V_296 )
return 0 ;
V_281 -> V_296 = 1 ;
F_161 () ;
return 0 ;
}
#endif
#endif
case V_326 :
return F_156 ( V_17 , V_317 ) ;
case V_327 :
return F_156 ( V_9 , V_317 ) ;
}
return error ;
}
static long F_162 ( struct V_128 * V_307 ,
T_13 V_316 , T_14 V_212 )
{
int V_148 ;
F_121 ( & V_294 ) ;
V_148 = F_153 ( V_307 , V_316 , V_212 ) ;
F_123 ( & V_294 ) ;
return V_148 ;
}
static long F_163 ( struct V_128 * V_307 , T_13 V_316 , T_14 V_212 )
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
return F_162 ( V_307 , V_316 , ( unsigned long ) F_164 ( V_212 ) ) ;
}
static int F_165 ( void )
{
if ( ! V_3 )
return 0 ;
if ( F_166 ( & V_335 ) < 0 )
F_4 ( V_5 L_77 ) ;
return 0 ;
}
static inline void
F_167 ( volatile unsigned char T_9 * V_3 )
{
V_3 [ V_83 ] &= ~ V_84 ; F_168 () ;
while ( ( V_3 [ V_83 ] & V_86 ) != 0 )
;
V_3 [ V_83 ] |= V_84 ; F_168 () ;
while ( ( V_3 [ V_83 ] & V_86 ) == 0 )
;
}
static inline void
F_169 ( volatile unsigned char T_9 * V_3 , int V_176 )
{
V_3 [ V_177 ] |= V_178 | V_179 ; F_168 () ;
V_3 [ V_180 ] = V_176 ; F_168 () ;
F_167 ( V_3 ) ;
}
static inline int
F_170 ( volatile unsigned char T_9 * V_3 )
{
int V_176 ;
V_3 [ V_177 ] = ( V_3 [ V_177 ] & ~ V_178 ) | V_179 ; F_168 () ;
V_176 = V_3 [ V_180 ] ; F_168 () ;
F_167 ( V_3 ) ;
V_176 = V_3 [ V_180 ] ; F_168 () ;
return V_176 ;
}
int
F_171 ( struct V_81 * V_82 )
{
unsigned long V_63 ;
int V_70 , V_336 , V_337 ;
volatile unsigned char T_9 * V_126 = V_3 ;
V_82 -> V_44 = 1 ;
V_337 = V_82 -> V_133 [ 0 ] ;
V_336 = V_152 [ V_337 ] [ 0 ] ;
if ( V_336 >= 0 && V_82 -> V_151 != V_336 + 1 )
return - V_144 ;
F_172 ( V_63 ) ;
while ( V_33 != V_34 )
F_19 () ;
while ( ( V_3 [ V_83 ] & V_86 ) == 0 )
;
F_169 ( V_126 , V_337 ) ;
if ( V_336 < 0 ) {
V_336 = V_82 -> V_151 - 1 ;
F_169 ( V_126 , V_336 ) ;
}
for ( V_70 = 1 ; V_70 <= V_336 ; ++ V_70 )
F_169 ( V_126 , V_82 -> V_133 [ V_70 ] ) ;
V_336 = V_152 [ V_337 ] [ 1 ] ;
if ( V_336 < 0 )
V_336 = F_170 ( V_126 ) ;
for ( V_70 = 0 ; V_70 < V_336 ; ++ V_70 )
V_82 -> V_93 [ V_70 + V_82 -> V_92 ] = F_170 ( V_126 ) ;
if ( V_82 -> V_167 )
(* V_82 -> V_167 )( V_82 ) ;
F_173 ( V_63 ) ;
return 0 ;
}
void F_174 ( int V_338 )
{
struct V_81 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
for (; V_338 > 0 ; -- V_338 ) {
V_82 . V_151 = 4 ;
V_82 . V_167 = NULL ;
V_82 . V_133 [ 0 ] = 0xee ;
V_82 . V_133 [ 1 ] = 4 ;
V_82 . V_133 [ 2 ] = 0 ;
V_82 . V_133 [ 3 ] = 1 ;
V_82 . V_93 [ 0 ] = V_153 ;
V_82 . V_92 = 1 ;
V_82 . V_162 = 0 ;
F_171 ( & V_82 ) ;
F_93 ( 50 ) ;
V_82 . V_151 = 4 ;
V_82 . V_167 = NULL ;
V_82 . V_133 [ 0 ] = 0xee ;
V_82 . V_133 [ 1 ] = 4 ;
V_82 . V_133 [ 2 ] = 0 ;
V_82 . V_133 [ 3 ] = 0 ;
V_82 . V_93 [ 0 ] = V_153 ;
V_82 . V_92 = 1 ;
V_82 . V_162 = 0 ;
F_171 ( & V_82 ) ;
F_93 ( 50 ) ;
}
F_93 ( 50 ) ;
}
static int F_175 ( void )
{
F_68 () ;
V_339 = 1 ;
#ifdef F_21
F_176 ( 1 ) ;
#endif
return 0 ;
}
static void F_177 ( void )
{
struct V_81 V_82 ;
if ( ! V_339 )
return;
F_29 ( & V_82 , NULL , 2 , V_90 , 2 ) ;
F_31 ( & V_82 ) ;
#ifdef F_21
F_176 ( 0 ) ;
#endif
F_70 () ;
V_339 = 0 ;
}
static int F_178 ( void )
{
F_179 ( & V_340 ) ;
return 0 ;
}
