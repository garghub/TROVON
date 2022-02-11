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
if ( ! V_43 ) {
F_4 ( V_5 L_15 ) ;
return - V_42 ;
}
if ( F_18 ( V_43 , V_46 , V_47 ,
L_16 , ( void * ) 0 ) ) {
F_4 ( V_5 L_17 , V_43 ) ;
return - V_42 ;
}
if ( V_17 == V_25 ) {
V_48 = F_2 ( NULL , L_18 ) ;
if ( V_48 == NULL )
V_48 = F_2 ( NULL ,
L_19 ) ;
if ( V_48 )
V_49 = F_17 ( V_48 , 0 ) ;
if ( V_49 ) {
if ( F_18 ( V_49 , V_50 ,
V_47 , L_20 ,
( void * ) 0 ) )
F_4 ( V_5 L_21
L_22 , V_49 ) ;
else
V_51 = 1 ;
}
}
F_11 ( & V_3 [ V_30 ] , V_52 | V_53 | V_54 ) ;
V_55 = 1 ;
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
int V_56 = F_25 ( V_57 ,
NULL , V_58 , 0 ) ;
V_59 = 1 ;
if ( V_56 == V_60 )
V_61 [ 0 ] . V_62 |= V_63 ;
else
V_61 [ 0 ] . V_62 |= V_64 ;
} else if ( F_24 ( L_25 ) ||
F_24 ( L_26 ) ) {
V_59 = 2 ;
V_61 [ 0 ] . V_62 |= V_65 ;
V_61 [ 1 ] . V_62 |= V_65 ;
} else {
struct V_21 * V_66 =
F_2 ( NULL , L_27 ) ;
const T_3 * V_67 = NULL ;
if ( V_66 )
V_67 = F_3 ( V_66 , L_28 , NULL ) ;
if ( V_67 ) {
V_59 = ( V_67 [ 6 ] >> 16 ) & 0xff ;
V_61 [ 0 ] . V_62 |= V_65 ;
if ( V_59 > 1 )
V_61 [ 1 ] . V_62 |= V_65 ;
}
F_9 ( V_66 ) ;
}
#endif
V_68 = F_26 ( L_29 , NULL ) ;
if ( V_68 ) {
long V_69 ;
for ( V_69 = 0 ; V_69 < V_59 ; V_69 ++ ) {
char V_70 [ 16 ] ;
sprintf ( V_70 , L_30 , V_69 ) ;
V_71 [ V_69 ] = F_27 ( V_70 , 0 , V_68 ,
& V_72 , ( void * ) V_69 ) ;
}
V_73 = F_28 ( L_31 , 0 , V_68 , & V_74 ) ;
V_75 = F_28 ( L_32 , 0 , V_68 ,
& V_76 ) ;
V_77 = F_28 ( L_33 , 0600 , V_68 ,
& V_78 ) ;
}
return 0 ;
}
static int
F_12 ( void )
{
int V_79 ;
struct V_80 V_81 ;
F_11 ( & V_3 [ V_82 ] , V_3 [ V_82 ] | V_83 ) ;
F_11 ( & V_3 [ V_84 ] , ( V_3 [ V_84 ] | V_83 ) & ~ V_85 ) ;
F_29 ( & V_81 , NULL , 2 , V_86 , V_10 ) ;
V_79 = 100000 ;
while ( ! V_81 . V_45 ) {
if ( -- V_79 < 0 ) {
F_4 ( V_5 L_34 ) ;
return 0 ;
}
F_30 ( 10 ) ;
F_19 () ;
}
V_79 = 100000 ;
V_87 [ 0 ] [ 0 ] = 1 ;
while ( V_87 [ 0 ] [ 0 ] || V_33 != V_34 ) {
if ( -- V_79 < 0 ) {
F_4 ( V_5 L_35 ) ;
return 0 ;
}
if ( V_33 == V_34 )
V_88 = 1 ;
V_46 ( 0 , NULL ) ;
F_30 ( 10 ) ;
}
if ( V_17 == V_25 ) {
F_29 ( & V_81 , NULL , 2 , V_89 , 2 ) ;
while ( ! V_81 . V_45 )
F_19 () ;
}
F_29 ( & V_81 , NULL , 1 , V_90 ) ;
F_31 ( & V_81 ) ;
if ( V_81 . V_91 > 0 )
V_39 = V_81 . V_92 [ 0 ] ;
if ( V_17 == V_25 ) {
F_29 ( & V_81 , NULL , 2 , V_93 ,
V_94 ) ;
F_31 ( & V_81 ) ;
if ( V_81 . V_91 == 2 ) {
if ( V_81 . V_92 [ 1 ] & V_95 )
V_96 = 1 ;
F_4 ( V_36 L_36 ,
V_96 ? L_37 : L_38 ) ;
}
}
return 1 ;
}
int
F_32 ( void )
{
return V_17 ;
}
static void F_33 ( int V_97 )
{
struct V_80 V_81 ;
if ( V_17 != V_25 )
return;
V_96 = V_97 ;
F_29 ( & V_81 , NULL , 2 , V_93 , V_94 ) ;
F_31 ( & V_81 ) ;
if ( V_81 . V_91 < 2 )
return;
if ( V_97 )
F_29 ( & V_81 , NULL , 4 , V_93 ,
V_98 ,
V_81 . V_92 [ 0 ] , V_95 ) ;
else
F_29 ( & V_81 , NULL , 4 , V_93 ,
V_99 ,
V_81 . V_92 [ 0 ] , V_95 ) ;
F_31 ( & V_81 ) ;
}
static void
F_34 ( struct V_80 * V_81 )
{
unsigned int V_100 = V_64 ;
long V_101 , V_102 , V_103 , V_104 , V_105 ;
long V_106 , V_107 ;
long V_108 , V_109 , time , V_110 ;
int V_56 = F_25 ( V_57 ,
NULL , V_58 , 0 ) ;
if ( V_81 -> V_92 [ 0 ] & 0x01 )
V_111 |= V_112 ;
else
V_111 &= ~ V_112 ;
if ( V_56 == V_60 ) {
V_107 = 189 ;
V_106 = 213 ;
V_105 = 6500 ;
} else {
V_107 = 330 ;
V_106 = 330 ;
V_105 = 6500 ;
}
V_104 = V_107 ;
if ( V_81 -> V_92 [ 0 ] & 0x04 ) {
V_100 |= V_113 ;
if ( V_81 -> V_92 [ 0 ] & 0x02 )
V_100 |= V_114 ;
V_103 = ( V_81 -> V_92 [ 1 ] << 8 ) | V_81 -> V_92 [ 2 ] ;
V_109 = ( V_103 * 265 + 72665 ) / 10 ;
V_108 = V_81 -> V_92 [ 5 ] ;
if ( ( V_81 -> V_92 [ 0 ] & 0x01 ) == 0 ) {
if ( V_108 > 200 )
V_103 += ( ( V_108 - 200 ) * 15 ) / 100 ;
} else if ( V_81 -> V_92 [ 0 ] & 0x02 ) {
V_103 = ( V_103 * 97 ) / 100 ;
V_104 = V_106 ;
}
V_102 = ( 100 * V_103 ) / V_104 ;
if ( V_81 -> V_92 [ 0 ] & 0x40 ) {
V_101 = ( V_81 -> V_92 [ 6 ] << 8 ) + V_81 -> V_92 [ 7 ] ;
if ( V_101 > V_105 )
V_101 = V_105 ;
V_101 *= 100 ;
V_101 = 100 - V_101 / V_105 ;
if ( V_101 < V_102 )
V_102 = V_101 ;
}
if ( V_108 > 0 )
time = ( V_102 * 16440 ) / V_108 ;
else
time = 0 ;
V_110 = 100 ;
V_108 = - V_108 ;
} else
V_102 = V_110 = V_108 = V_109 = time = 0 ;
V_61 [ V_115 ] . V_62 = V_100 ;
V_61 [ V_115 ] . V_102 = V_102 ;
V_61 [ V_115 ] . V_116 = V_110 ;
V_61 [ V_115 ] . V_108 = V_108 ;
V_61 [ V_115 ] . V_109 = V_109 ;
V_61 [ V_115 ] . V_117 = time ;
F_35 ( 0 , & V_118 ) ;
}
static void
F_36 ( struct V_80 * V_81 )
{
unsigned int V_100 = V_65 ;
int V_108 ;
unsigned int V_119 , V_110 , V_109 ;
if ( V_81 -> V_92 [ 1 ] & 0x01 )
V_111 |= V_112 ;
else
V_111 &= ~ V_112 ;
V_119 = V_110 = V_108 = V_109 = 0 ;
if ( V_81 -> V_92 [ 1 ] & 0x04 ) {
V_100 |= V_113 ;
switch( V_81 -> V_92 [ 0 ] ) {
case 3 :
case 4 : V_119 = V_81 -> V_92 [ 2 ] ;
V_110 = V_81 -> V_92 [ 3 ] ;
V_108 = * ( ( signed char * ) & V_81 -> V_92 [ 4 ] ) ;
V_109 = V_81 -> V_92 [ 5 ] ;
break;
case 5 : V_119 = ( V_81 -> V_92 [ 2 ] << 8 ) | V_81 -> V_92 [ 3 ] ;
V_110 = ( V_81 -> V_92 [ 4 ] << 8 ) | V_81 -> V_92 [ 5 ] ;
V_108 = * ( ( signed short * ) & V_81 -> V_92 [ 6 ] ) ;
V_109 = ( V_81 -> V_92 [ 8 ] << 8 ) | V_81 -> V_92 [ 9 ] ;
break;
default:
F_37 ( L_39
L_40 , V_81 -> V_91 ,
V_81 -> V_92 ) ;
break;
}
}
if ( ( V_81 -> V_92 [ 1 ] & 0x01 ) && ( V_108 > 0 ) )
V_100 |= V_114 ;
V_61 [ V_115 ] . V_62 = V_100 ;
V_61 [ V_115 ] . V_102 = V_119 ;
V_61 [ V_115 ] . V_116 = V_110 ;
V_61 [ V_115 ] . V_108 = V_108 ;
V_61 [ V_115 ] . V_109 = V_109 ;
if ( V_108 ) {
if ( ( V_81 -> V_92 [ 1 ] & 0x01 ) && ( V_108 > 0 ) )
V_61 [ V_115 ] . V_117
= ( ( V_110 - V_119 ) * 3600 ) / V_108 ;
else
V_61 [ V_115 ] . V_117
= ( V_119 * 3600 ) / ( - V_108 ) ;
} else
V_61 [ V_115 ] . V_117 = 0 ;
V_115 = ( V_115 + 1 ) % V_59 ;
F_35 ( 0 , & V_118 ) ;
}
static void
F_38 ( void )
{
if ( F_39 ( 0 , & V_118 ) )
return;
if ( V_17 == V_18 )
F_29 ( & V_44 , F_34 ,
1 , V_120 ) ;
else
F_29 ( & V_44 , F_36 ,
2 , V_121 , V_115 + 1 ) ;
}
static int F_40 ( struct V_122 * V_123 , void * V_124 )
{
F_41 ( V_123 , L_41 , V_37 ) ;
F_41 ( V_123 , L_42 , V_39 ) ;
F_41 ( V_123 , L_43 ,
( ( V_111 & V_112 ) != 0 ) || V_59 == 0 ) ;
F_41 ( V_123 , L_44 , V_59 ) ;
return 0 ;
}
static int F_42 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_43 ( V_126 , F_40 , NULL ) ;
}
static int F_44 ( struct V_122 * V_123 , void * V_124 )
{
int V_69 ;
static const char * V_127 [] = {
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
for ( V_69 = 0 ; V_69 < 11 ; V_69 ++ ) {
F_41 ( V_123 , L_56 ,
V_69 , V_128 [ V_69 ] , V_127 [ V_69 ] ) ;
}
return 0 ;
}
static int F_45 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_43 ( V_126 , F_44 , NULL ) ;
}
static int F_46 ( struct V_122 * V_123 , void * V_124 )
{
long V_129 = ( long ) V_123 -> V_130 ;
F_47 ( V_123 , '\n' ) ;
F_41 ( V_123 , L_57 , V_61 [ V_129 ] . V_62 ) ;
F_41 ( V_123 , L_58 , V_61 [ V_129 ] . V_102 ) ;
F_41 ( V_123 , L_59 , V_61 [ V_129 ] . V_116 ) ;
F_41 ( V_123 , L_60 , V_61 [ V_129 ] . V_108 ) ;
F_41 ( V_123 , L_61 , V_61 [ V_129 ] . V_109 ) ;
F_41 ( V_123 , L_62 , V_61 [ V_129 ] . V_117 ) ;
return 0 ;
}
static int F_48 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_43 ( V_126 , F_46 , F_49 ( V_125 ) ) ;
}
static int F_50 ( struct V_122 * V_123 , void * V_124 )
{
#if F_51 ( V_131 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_132 , NULL , 0 , - 1 ) >= 0 )
F_41 ( V_123 , L_63 , V_133 ) ;
#endif
if ( V_17 == V_25 )
F_41 ( V_123 , L_64 , V_96 ) ;
return 0 ;
}
static int F_52 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_43 ( V_126 , F_50 , NULL ) ;
}
static T_4 F_53 ( struct V_126 * V_126 ,
const char T_5 * V_134 , T_6 V_135 , T_7 * V_136 )
{
char V_137 [ 33 ] ;
char * V_138 , * V_139 ;
T_6 V_140 = V_135 ;
if ( ! V_135 )
return - V_141 ;
if ( V_135 > 32 )
V_135 = 32 ;
if ( F_54 ( V_137 , V_134 , V_135 ) )
return - V_142 ;
V_137 [ V_135 ] = 0 ;
V_138 = V_137 ;
while( * V_138 == ' ' )
V_138 ++ ;
V_139 = V_138 ;
while( * V_139 && ( * V_139 != '=' ) ) {
if ( * V_139 == ' ' )
* V_139 = 0 ;
V_139 ++ ;
}
if ( ( * V_139 ) == 0 )
return - V_141 ;
* ( V_139 ++ ) = 0 ;
while( * V_139 == ' ' )
V_139 ++ ;
#if F_51 ( V_131 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_132 , NULL , 0 , - 1 ) >= 0 )
if ( ! strcmp ( V_138 , L_65 ) )
V_133 = ( ( * V_139 ) == '1' ) ;
#endif
if ( V_17 == V_25 && ! strcmp ( V_138 , L_66 ) ) {
int V_143 ;
V_143 = ( ( * V_139 ) == '1' ) ;
if ( V_143 != V_96 )
F_33 ( V_143 ) ;
}
return V_140 ;
}
static int F_55 ( struct V_80 * V_81 , int V_144 )
{
int V_69 , V_145 ;
if ( ( V_4 == NULL ) || ( ! V_55 ) ) {
V_81 -> V_45 = 1 ;
return - V_146 ;
}
V_145 = - V_141 ;
switch ( V_81 -> V_147 [ 0 ] ) {
case V_148 :
for ( V_69 = 0 ; V_69 < V_81 -> V_149 - 1 ; ++ V_69 )
V_81 -> V_147 [ V_69 ] = V_81 -> V_147 [ V_69 + 1 ] ;
-- V_81 -> V_149 ;
if ( V_150 [ V_81 -> V_147 [ 0 ] ] [ 1 ] != 0 ) {
V_81 -> V_92 [ 0 ] = V_151 ;
V_81 -> V_91 = 1 ;
} else
V_81 -> V_91 = 0 ;
V_145 = F_56 ( V_81 ) ;
break;
case V_152 :
switch ( V_81 -> V_147 [ 1 ] ) {
case V_153 :
if ( V_81 -> V_149 != 2 )
break;
V_81 -> V_147 [ 0 ] = V_154 ;
V_81 -> V_149 = 1 ;
V_81 -> V_91 = 3 ;
V_81 -> V_92 [ 0 ] = V_152 ;
V_81 -> V_92 [ 1 ] = 0 ;
V_81 -> V_92 [ 2 ] = V_153 ;
V_145 = F_56 ( V_81 ) ;
break;
case V_155 :
if ( V_81 -> V_149 != 6 )
break;
V_81 -> V_147 [ 0 ] = V_156 ;
V_81 -> V_149 = 5 ;
for ( V_69 = 1 ; V_69 <= 4 ; ++ V_69 )
V_81 -> V_147 [ V_69 ] = V_81 -> V_147 [ V_69 + 1 ] ;
V_81 -> V_91 = 3 ;
V_81 -> V_92 [ 0 ] = V_152 ;
V_81 -> V_92 [ 1 ] = 0 ;
V_81 -> V_92 [ 2 ] = V_155 ;
V_145 = F_56 ( V_81 ) ;
break;
}
break;
case V_157 :
if ( ! V_9 )
return - V_146 ;
for ( V_69 = V_81 -> V_149 - 1 ; V_69 > 1 ; -- V_69 )
V_81 -> V_147 [ V_69 + 2 ] = V_81 -> V_147 [ V_69 ] ;
V_81 -> V_147 [ 3 ] = V_81 -> V_149 - 2 ;
V_81 -> V_147 [ 2 ] = V_158 ;
V_81 -> V_147 [ 0 ] = V_159 ;
V_81 -> V_149 += 2 ;
V_81 -> V_160 = 1 ;
V_81 -> V_91 = 0 ;
V_145 = F_56 ( V_81 ) ;
break;
}
if ( V_145 ) {
V_81 -> V_45 = 1 ;
return V_145 ;
}
if ( V_144 )
while ( ! V_81 -> V_45 )
F_19 () ;
return 0 ;
}
static int F_57 ( int V_161 )
{
struct V_80 V_81 ;
if ( V_161 ) {
F_29 ( & V_81 , NULL , 5 , V_159 , 0 , 0x86 ,
V_162 >> 8 , V_162 ) ;
V_158 = 2 ;
} else {
F_29 ( & V_81 , NULL , 1 , V_163 ) ;
V_158 = 0 ;
}
while ( ! V_81 . V_45 )
F_19 () ;
return 0 ;
}
static int F_58 ( int V_161 )
{
if ( ( V_4 == NULL ) || ( ! V_55 ) || ! V_9 )
return - V_146 ;
V_162 = V_161 ;
return F_57 ( V_161 ) ;
}
static int F_59 ( void )
{
struct V_80 V_81 ;
int V_164 = V_162 ;
if ( ( V_4 == NULL ) || ( ! V_55 ) || ! V_9 )
return - V_146 ;
F_57 ( 0 ) ;
V_81 . V_149 = 4 ;
V_81 . V_165 = NULL ;
V_81 . V_147 [ 0 ] = V_159 ;
V_81 . V_147 [ 1 ] = V_166 ;
V_81 . V_147 [ 2 ] = 0 ;
V_81 . V_147 [ 3 ] = 0 ;
V_81 . V_147 [ 4 ] = 0 ;
V_81 . V_91 = 0 ;
V_81 . V_160 = 1 ;
if ( F_56 ( & V_81 ) != 0 ) {
F_4 ( V_5 L_67 ) ;
return - V_167 ;
}
F_31 ( & V_81 ) ;
if ( V_164 != 0 )
F_57 ( V_164 ) ;
return 0 ;
}
int
F_29 ( struct V_80 * V_81 , void (* V_165)( struct V_80 * ) ,
int V_149 , ... )
{
T_8 V_168 ;
int V_69 ;
if ( V_4 == NULL )
return - V_146 ;
if ( V_149 < 0 || V_149 > 32 ) {
F_4 ( V_5 L_68 , V_149 ) ;
V_81 -> V_45 = 1 ;
return - V_141 ;
}
V_81 -> V_149 = V_149 ;
V_81 -> V_165 = V_165 ;
va_start ( V_168 , V_149 ) ;
for ( V_69 = 0 ; V_69 < V_149 ; ++ V_69 )
V_81 -> V_147 [ V_69 ] = va_arg ( V_168 , int ) ;
va_end ( V_168 ) ;
V_81 -> V_91 = 0 ;
V_81 -> V_160 = 0 ;
return F_56 ( V_81 ) ;
}
int
F_56 ( struct V_80 * V_81 )
{
unsigned long V_62 ;
int V_169 ;
if ( V_3 == NULL ) {
V_81 -> V_45 = 1 ;
return - V_146 ;
}
if ( V_81 -> V_149 <= 0 ) {
V_81 -> V_45 = 1 ;
return 0 ;
}
V_169 = V_150 [ V_81 -> V_147 [ 0 ] ] [ 0 ] ;
if ( V_169 >= 0 && V_81 -> V_149 != V_169 + 1 ) {
V_81 -> V_45 = 1 ;
return - V_141 ;
}
V_81 -> V_170 = NULL ;
V_81 -> V_171 = 0 ;
V_81 -> V_45 = 0 ;
F_60 ( & V_8 , V_62 ) ;
if ( V_172 != 0 ) {
V_173 -> V_170 = V_81 ;
V_173 = V_81 ;
} else {
V_172 = V_81 ;
V_173 = V_81 ;
if ( V_33 == V_34 )
F_61 () ;
}
F_62 ( & V_8 , V_62 ) ;
return 0 ;
}
static inline void
F_63 ( void )
{
int V_79 = 4000 ;
while ( ( F_64 ( & V_3 [ V_82 ] ) & V_85 ) == 0 ) {
if ( -- V_79 < 0 ) {
F_4 ( V_5 L_69 ) ;
return;
}
F_30 ( 10 ) ;
}
}
static inline void
F_65 ( int V_174 )
{
volatile unsigned char T_9 * V_124 = V_3 ;
F_11 ( & V_124 [ V_175 ] , F_64 ( & V_124 [ V_175 ] ) | V_176 | V_177 ) ;
F_11 ( & V_124 [ V_178 ] , V_174 ) ;
F_11 ( & V_124 [ V_82 ] , F_64 ( & V_124 [ V_82 ] ) & ~ V_83 ) ;
( void ) F_64 ( & V_124 [ V_82 ] ) ;
}
static inline void
F_66 ( void )
{
volatile unsigned char T_9 * V_124 = V_3 ;
F_11 ( & V_124 [ V_175 ] , ( F_64 ( & V_124 [ V_175 ] ) & ~ V_176 ) | V_177 ) ;
F_64 ( & V_124 [ V_178 ] ) ;
F_11 ( & V_124 [ V_82 ] , F_64 ( & V_124 [ V_82 ] ) & ~ V_83 ) ;
( void ) F_64 ( & V_124 [ V_82 ] ) ;
}
static inline void
F_67 ( struct V_80 * V_81 )
{
void (* V_165)( struct V_80 * ) = V_81 -> V_165 ;
V_56 () ;
V_81 -> V_45 = 1 ;
if ( V_165 )
(* V_165)( V_81 ) ;
}
static void
F_61 ( void )
{
struct V_80 * V_81 ;
V_81 = V_172 ;
if ( V_81 == 0 || V_33 != V_34
|| ( V_179 ) )
return;
V_33 = V_180 ;
V_181 = 1 ;
V_182 = V_150 [ V_81 -> V_147 [ 0 ] ] [ 0 ] ;
F_63 () ;
F_65 ( V_81 -> V_147 [ 0 ] ) ;
}
void
F_19 ( void )
{
if ( ! V_3 )
return;
if ( V_183 )
return;
V_46 ( 0 , NULL ) ;
}
void
F_68 ( void )
{
if ( ! V_3 )
return;
if ( V_183 )
return;
V_88 = 1 ;
do {
V_46 ( 0 , NULL ) ;
} while ( V_184 && ( V_88 || V_33 != V_34
|| V_179 ) );
}
void
F_31 ( struct V_80 * V_81 )
{
if ( ! V_3 )
return;
while( ( V_33 != V_34 && V_33 != V_185 ) || ! V_81 -> V_45 )
V_46 ( 0 , NULL ) ;
}
void
F_69 ( void )
{
unsigned long V_62 ;
if ( ! V_3 )
return;
F_60 ( & V_8 , V_62 ) ;
V_184 ++ ;
if ( V_184 > 1 ) {
F_62 ( & V_8 , V_62 ) ;
return;
}
do {
F_62 ( & V_8 , V_62 ) ;
if ( V_179 )
V_88 = 1 ;
V_46 ( 0 , NULL ) ;
F_60 ( & V_8 , V_62 ) ;
if ( ! V_88 && V_33 == V_34 && ! V_179 ) {
if ( V_49 >= 0 )
F_70 ( V_49 ) ;
F_11 ( & V_3 [ V_30 ] , V_54 | V_31 ) ;
F_62 ( & V_8 , V_62 ) ;
break;
}
} while ( 1 );
}
void
F_71 ( void )
{
unsigned long V_62 ;
if ( ! V_3 || ( V_184 < 1 ) )
return;
F_60 ( & V_8 , V_62 ) ;
V_184 -- ;
if ( V_184 > 0 ) {
F_62 ( & V_8 , V_62 ) ;
return;
}
V_88 = 1 ;
if ( V_49 >= 0 )
F_72 ( V_49 ) ;
F_11 ( & V_3 [ V_30 ] , V_54 | V_52 ) ;
F_62 ( & V_8 , V_62 ) ;
F_19 () ;
}
static void
F_73 ( unsigned char * V_147 , int V_186 )
{
unsigned char V_187 , V_188 ;
int V_69 = 0 ;
V_189 = 0 ;
if ( V_190 || V_186 < 1 ) {
V_88 = 0 ;
V_128 [ 8 ] ++ ;
return;
}
V_187 = V_147 [ 0 ] ;
if ( V_187 == 0 )
V_128 [ 9 ] ++ ;
if ( V_187 & V_13 )
V_187 &= ~ ( V_191 | V_192 ) ;
V_170:
if ( V_187 == 0 ) {
if ( V_69 > V_128 [ 10 ] )
V_128 [ 10 ] = V_69 ;
return;
}
for ( V_188 = 0 ; V_188 < 8 ; V_188 ++ )
if ( V_187 & ( 1 << V_188 ) )
break;
V_128 [ V_188 ] ++ ;
V_69 ++ ;
V_187 &= ~ ( 1 << V_188 ) ;
if ( ( 1 << V_188 ) & V_13 ) {
if ( ( V_147 [ 0 ] & V_191 ) == 0 ) {
struct V_80 * V_81 = V_179 ;
if ( V_81 == 0 ) {
F_4 ( V_5 L_70 ) ;
return;
}
V_179 = NULL ;
if ( V_186 <= 2 )
V_81 -> V_91 = 0 ;
else {
memcpy ( V_81 -> V_92 , V_147 + 1 , V_186 - 1 ) ;
V_81 -> V_91 = V_186 - 1 ;
}
F_67 ( V_81 ) ;
} else {
if ( V_186 == 4 && V_147 [ 1 ] == 0x2c ) {
extern int V_193 , V_194 ;
if ( V_193 ) {
V_194 = V_147 [ 2 ] ;
return;
}
}
#ifdef F_74
if ( ! ( V_17 == V_18 && V_186 == 4
&& V_147 [ 1 ] == 0x2c && V_147 [ 3 ] == 0xff
&& ( V_147 [ 2 ] & ~ 1 ) == 0xf4 ) )
F_75 ( V_147 + 1 , V_186 - 1 , 1 ) ;
#endif
}
}
else if ( ( 1 << V_188 ) & V_12 ) {
#ifdef F_21
if ( V_186 == 3 )
F_76 ( V_147 [ 1 ] >> 4 ) ;
#endif
}
else if ( ( 1 << V_188 ) & V_14 ) {
if ( V_59 ) {
if ( ( -- V_195 ) == 0 ) {
F_38 () ;
V_195 = V_196 ;
}
}
}
else if ( ( 1 << V_188 ) & V_26 ) {
if ( V_59 )
F_38 () ;
F_77 ( V_147 , V_186 ) ;
if ( V_186 == 6 ) {
F_78 ( V_197 , ! ! ( V_147 [ 1 ] & 8 ) ) ;
F_78 ( V_198 , V_147 [ 1 ] & 1 ) ;
}
} else {
F_77 ( V_147 , V_186 ) ;
}
goto V_170;
}
static struct V_80 *
F_79 ( void )
{
struct V_80 * V_81 ;
int V_199 = 0 ;
if ( V_3 [ V_82 ] & V_83 ) {
F_4 ( V_5 L_71 , V_3 [ V_82 ] ) ;
F_11 ( & V_3 [ V_32 ] , V_53 ) ;
return NULL ;
}
while ( ( F_64 ( & V_3 [ V_82 ] ) & V_85 ) != 0 )
;
if ( V_33 == V_200 || V_33 == V_201 )
V_199 = F_64 ( & V_3 [ V_178 ] ) ;
F_11 ( & V_3 [ V_82 ] , F_64 ( & V_3 [ V_82 ] ) | V_83 ) ;
F_63 () ;
switch ( V_33 ) {
case V_180 :
V_81 = V_172 ;
if ( V_182 < 0 ) {
V_182 = V_81 -> V_149 - 1 ;
F_65 ( V_182 ) ;
break;
}
if ( V_181 <= V_182 ) {
F_65 ( V_81 -> V_147 [ V_181 ++ ] ) ;
break;
}
V_81 -> V_171 = 1 ;
V_182 = V_150 [ V_81 -> V_147 [ 0 ] ] [ 1 ] ;
if ( V_182 == 0 ) {
V_33 = V_34 ;
V_172 = V_81 -> V_170 ;
if ( V_81 -> V_160 )
V_179 = V_81 ;
else
return V_81 ;
} else {
V_33 = V_200 ;
V_181 = 0 ;
V_202 = V_81 -> V_92 + V_81 -> V_91 ;
F_66 () ;
}
break;
case V_203 :
V_181 = 0 ;
V_182 = - 1 ;
V_33 = V_201 ;
V_202 = V_87 [ V_204 ] ;
F_66 () ;
if ( V_49 >= 0 && ! V_51 ) {
F_72 ( V_49 ) ;
V_51 = 1 ;
}
break;
case V_200 :
case V_201 :
if ( V_182 == - 1 ) {
V_182 = V_199 ;
if ( V_199 > 32 )
F_4 ( V_5 L_72 , V_199 ) ;
} else if ( V_181 < 32 ) {
V_202 [ V_181 ++ ] = V_199 ;
}
if ( V_181 < V_182 ) {
F_66 () ;
break;
}
if ( V_33 == V_201 ) {
V_33 = V_34 ;
V_205 [ V_204 ] = V_206 ;
V_207 [ V_204 ] = V_182 ;
} else {
V_81 = V_172 ;
V_172 = V_81 -> V_170 ;
V_81 -> V_91 += V_181 ;
if ( V_81 -> V_147 [ 0 ] == V_208 || V_81 -> V_147 [ 0 ] == V_209 )
V_33 = V_185 ;
else
V_33 = V_34 ;
return V_81 ;
}
break;
default:
F_4 ( V_5 L_73 ,
V_33 ) ;
}
return NULL ;
}
static T_10
V_46 ( int V_43 , void * V_210 )
{
unsigned long V_62 ;
int V_211 ;
int V_212 = 0 ;
int V_213 = - 1 ;
struct V_80 * V_81 = NULL ;
int V_214 = 0 ;
F_60 ( & V_8 , V_62 ) ;
++ V_183 ;
for (; ; ) {
V_211 = F_64 ( & V_3 [ V_32 ] ) & ( V_53 | V_54 ) ;
if ( V_211 == 0 )
break;
V_214 = 1 ;
if ( ++ V_212 > 1000 ) {
F_4 ( V_215 L_74
L_75 ,
V_211 , F_64 ( & V_3 [ V_30 ] ) , V_33 ) ;
break;
}
F_11 ( & V_3 [ V_32 ] , V_211 ) ;
if ( V_211 & V_54 ) {
V_88 = 1 ;
V_128 [ 0 ] ++ ;
}
if ( V_211 & V_53 ) {
V_81 = F_79 () ;
if ( V_81 )
break;
}
}
V_216:
if ( V_33 == V_34 ) {
if ( V_88 ) {
if ( V_205 [ 0 ] == V_217 )
V_204 = 0 ;
else if ( V_205 [ 1 ] == V_217 )
V_204 = 1 ;
else
goto V_218;
V_33 = V_203 ;
V_205 [ V_204 ] = V_219 ;
F_63 () ;
F_65 ( V_220 ) ;
V_88 = 0 ;
} else if ( V_172 )
F_61 () ;
}
V_218:
if ( V_205 [ ! V_204 ] == V_206 ) {
V_205 [ ! V_204 ] = V_221 ;
V_213 = ! V_204 ;
} else if ( V_205 [ V_204 ] == V_206 ) {
V_205 [ V_204 ] = V_221 ;
V_213 = V_204 ;
}
-- V_183 ;
F_62 ( & V_8 , V_62 ) ;
if ( V_81 ) {
F_67 ( V_81 ) ;
V_81 = NULL ;
}
if ( V_213 >= 0 ) {
F_73 ( V_87 [ V_213 ] , V_207 [ V_213 ] ) ;
F_60 ( & V_8 , V_62 ) ;
++ V_183 ;
V_205 [ V_213 ] = V_217 ;
V_213 = - 1 ;
goto V_216;
}
return F_80 ( V_214 ) ;
}
void
F_81 ( void )
{
unsigned long V_62 ;
F_60 ( & V_8 , V_62 ) ;
if ( V_33 == V_185 )
V_33 = V_34 ;
V_88 = 1 ;
F_62 ( & V_8 , V_62 ) ;
}
static T_10
V_50 ( int V_43 , void * V_210 )
{
unsigned long V_62 ;
if ( ( F_64 ( V_27 + 0x9 ) & 0x02 ) == 0 ) {
F_60 ( & V_8 , V_62 ) ;
if ( V_51 > 0 ) {
F_70 ( V_49 ) ;
V_51 = 0 ;
}
V_128 [ 1 ] ++ ;
V_88 = 1 ;
F_62 ( & V_8 , V_62 ) ;
V_46 ( 0 , NULL ) ;
return V_222 ;
}
return V_223 ;
}
void
F_82 ( int V_224 )
{
struct V_80 V_81 ;
if ( V_4 == NULL )
return ;
if ( V_17 == V_25 )
return ;
F_29 ( & V_81 , NULL , 2 , V_225 , V_226 |
( V_224 ? V_227 : V_228 ) ) ;
F_31 ( & V_81 ) ;
}
void
F_83 ( void )
{
struct V_80 V_81 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_190 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_81 , NULL , 2 , V_86 , V_13 |
V_14 ) ;
while( ! V_81 . V_45 )
F_19 () ;
}
F_29 ( & V_81 , NULL , 1 , V_229 ) ;
F_31 ( & V_81 ) ;
for (; ; )
;
}
void
F_85 ( void )
{
struct V_80 V_81 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_190 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_81 , NULL , 2 , V_86 , V_13 |
V_14 ) ;
F_31 ( & V_81 ) ;
} else {
F_33 ( 0 ) ;
}
F_29 ( & V_81 , NULL , 5 , V_230 ,
'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_81 ) ;
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
V_231 [ 0 ] = F_64 ( & V_3 [ V_232 ] ) ;
V_231 [ 1 ] = F_64 ( & V_3 [ V_233 ] ) ;
V_231 [ 2 ] = F_64 ( & V_3 [ V_82 ] ) ;
V_231 [ 3 ] = F_64 ( & V_3 [ V_84 ] ) ;
V_231 [ 4 ] = F_64 ( & V_3 [ V_234 ] ) ;
V_231 [ 5 ] = F_64 ( & V_3 [ V_175 ] ) ;
V_231 [ 6 ] = F_64 ( & V_3 [ V_235 ] ) ;
V_231 [ 7 ] = F_64 ( & V_3 [ V_236 ] ) ;
}
static void
F_88 ( void )
{
F_11 ( & V_3 [ V_232 ] , V_231 [ 0 ] ) ;
F_11 ( & V_3 [ V_233 ] , V_231 [ 1 ] ) ;
F_11 ( & V_3 [ V_82 ] , V_231 [ 2 ] ) ;
F_11 ( & V_3 [ V_84 ] , V_231 [ 3 ] ) ;
F_11 ( & V_3 [ V_234 ] , V_231 [ 4 ] ) ;
F_11 ( & V_3 [ V_175 ] , V_231 [ 5 ] ) ;
F_11 ( & V_3 [ V_235 ] , V_231 [ 6 ] ) ;
F_11 ( & V_3 [ V_236 ] , V_231 [ 7 ] ) ;
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
F_11 ( & V_3 [ V_30 ] , V_52 | V_53 | V_54 ) ;
}
static int F_89 ( void )
{
unsigned long V_237 ;
unsigned short V_238 ;
struct V_80 V_81 ;
struct V_239 * V_240 ;
V_240 = F_90 ( 0 , 0 ) ;
if ( ! V_240 )
return - V_42 ;
F_29 ( & V_81 , NULL , 2 , V_241 , V_242 | V_243 ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 2 , V_225 ,
V_228 | V_244 | V_226 | V_245 ) ;
F_31 ( & V_81 ) ;
V_237 = F_91 () ;
if ( ! V_246 ) {
F_29 ( & V_81 , NULL , 5 , V_208 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_81 ) ;
}
F_87 () ;
F_25 ( V_132 , NULL , 0 , 1 ) ;
F_92 ( V_240 , 0x70 , & V_238 ) ;
V_238 &= ~ ( V_247 | V_248 ) ;
V_238 |= V_249 | V_250 ;
F_93 ( V_240 , 0x70 , V_238 ) ;
if ( V_246 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_92 ( V_240 , 0x70 , & V_238 ) ;
V_238 &= ~ ( V_249 | V_247 | V_248 | V_250 ) ;
F_93 ( V_240 , 0x70 , V_238 ) ;
F_96 ( V_240 ) ;
F_25 ( V_132 , NULL , 0 , 0 ) ;
F_88 () ;
if ( V_237 != 0xffffffff && ( V_237 & V_251 ) != 0 )
F_97 ( V_237 ) ;
F_98 ( NULL , V_252 -> V_253 , NULL ) ;
F_81 () ;
F_29 ( & V_81 , NULL , 2 , V_86 , V_10 ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 2 , V_241 ,
V_254 | V_243 ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 2 , V_225 ,
V_227 | V_244 | V_255 | V_226 | V_245 ) ;
F_31 ( & V_81 ) ;
return 0 ;
}
static int
F_99 ( void )
{
unsigned long V_237 ;
unsigned long V_256 ;
struct V_80 V_81 ;
if ( F_25 ( V_132 , NULL , 0 , - 1 ) < 0 ) {
F_4 ( V_5 L_76 ) ;
return - V_257 ;
}
if ( F_100 () > 1 || F_101 ( 0 ) )
return - V_258 ;
F_29 ( & V_81 , NULL , 2 , V_86 , 0 ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 4 , V_93 , V_259 ,
0xff , 0xff ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 4 , V_93 , V_260 ,
0 , V_261 |
( V_133 ? V_262 : 0 ) ) ;
F_31 ( & V_81 ) ;
V_256 = F_102 () ;
V_237 = F_91 () ;
if ( ! V_246 ) {
F_29 ( & V_81 , NULL , 5 , V_208 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_81 ) ;
}
F_87 () ;
F_25 ( V_132 , NULL , 0 , 1 ) ;
if ( V_246 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_25 ( V_132 , NULL , 0 , 0 ) ;
F_88 () ;
V_263 *= 2 ;
F_103 () ;
if ( V_237 != 0xffffffff && ( V_237 & V_251 ) != 0 )
F_97 ( V_237 ) ;
if ( V_256 != 0xffffffff && ( V_256 & V_264 ) != 0 )
F_104 ( V_256 ) ;
F_98 ( NULL , V_252 -> V_253 , NULL ) ;
F_81 () ;
F_29 ( & V_81 , NULL , 2 , V_89 , 2 ) ;
F_31 ( & V_81 ) ;
F_29 ( & V_81 , NULL , 2 , V_86 , V_10 ) ;
F_31 ( & V_81 ) ;
V_263 /= 2 ;
return 0 ;
}
static void F_105 ( void )
{
V_265 = F_10 ( V_266 , 0x100 ) ;
if ( V_265 == NULL )
F_4 ( V_267 L_77 ) ;
}
static int F_106 ( void )
{
int V_69 , V_174 ;
unsigned int V_268 ;
unsigned long V_269 ;
struct V_80 V_270 ;
unsigned int T_9 * V_271 ;
if ( V_265 == NULL )
return - V_272 ;
V_271 = V_265 + V_273 ;
for ( V_69 = 0x403f ; V_69 >= 0x4000 ; -- V_69 ) {
F_107 ( V_271 , V_69 ) ;
do {
V_174 = ( F_108 ( V_271 ) >> 16 ) & 0x3ff ;
} while ( V_174 == 0 );
if ( V_174 >= 0x100 )
break;
}
F_29 ( & V_270 , NULL , 5 , V_208 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_270 ) ;
F_81 () ;
F_25 ( V_132 , NULL , 0 , 1 ) ;
V_189 = 1 ;
V_268 = F_109 ( V_274 ) ;
V_268 = ( V_268 & ~ ( V_275 | V_276 ) ) | V_277 ;
F_110 ( V_274 , V_268 ) ;
F_111 () ;
V_269 = F_112 () | V_278 ;
while ( V_189 ) {
V_56 () ;
F_113 ( V_269 ) ;
F_114 () ;
}
F_84 () ;
F_107 ( V_271 , 0x3f ) ;
F_25 ( V_132 , NULL , 0 , 0 ) ;
return 0 ;
}
static void
F_77 ( unsigned char * V_147 , int V_186 )
{
struct V_279 * V_280 ;
struct V_281 * V_168 ;
int V_69 ;
unsigned long V_62 ;
if ( V_186 > sizeof( V_280 -> V_282 [ 0 ] . V_147 ) )
V_186 = sizeof( V_280 -> V_282 [ 0 ] . V_147 ) ;
F_60 ( & V_283 , V_62 ) ;
for ( V_168 = & V_284 ; ( V_168 = V_168 -> V_170 ) != & V_284 ; ) {
V_280 = F_115 ( V_168 , struct V_279 , V_168 ) ;
F_116 ( & V_280 -> V_285 ) ;
V_69 = V_280 -> V_286 + 1 ;
if ( V_69 >= V_287 )
V_69 = 0 ;
if ( V_69 != V_280 -> V_288 ) {
struct V_289 * V_290 = & V_280 -> V_282 [ V_280 -> V_286 ] ;
V_290 -> V_186 = V_186 ;
memcpy ( V_290 -> V_147 , V_147 , V_186 ) ;
V_280 -> V_286 = V_69 ;
F_117 ( & V_280 -> V_291 ) ;
}
F_118 ( & V_280 -> V_285 ) ;
}
F_62 ( & V_283 , V_62 ) ;
}
static int
F_119 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
struct V_279 * V_280 ;
unsigned long V_62 ;
V_280 = F_120 ( sizeof( struct V_279 ) , V_292 ) ;
if ( V_280 == 0 )
return - V_272 ;
V_280 -> V_288 = V_280 -> V_286 = 0 ;
F_6 ( & V_280 -> V_285 ) ;
F_121 ( & V_280 -> V_291 ) ;
F_122 ( & V_293 ) ;
F_60 ( & V_283 , V_62 ) ;
#if F_51 ( V_294 ) && F_51 ( F_21 )
V_280 -> V_295 = 0 ;
#endif
F_123 ( & V_280 -> V_168 , & V_284 ) ;
F_62 ( & V_283 , V_62 ) ;
V_126 -> V_296 = V_280 ;
F_124 ( & V_293 ) ;
return 0 ;
}
static T_4
F_125 ( struct V_126 * V_126 , char T_5 * V_297 ,
T_6 V_135 , T_7 * V_298 )
{
struct V_279 * V_280 = V_126 -> V_296 ;
F_126 ( V_291 , V_252 ) ;
unsigned long V_62 ;
int V_145 = 0 ;
if ( V_135 < 1 || V_280 == 0 )
return - V_141 ;
if ( ! F_127 ( V_299 , V_297 , V_135 ) )
return - V_142 ;
F_60 ( & V_280 -> V_285 , V_62 ) ;
F_128 ( & V_280 -> V_291 , & V_291 ) ;
F_129 ( V_300 ) ;
for (; ; ) {
V_145 = - V_258 ;
if ( V_280 -> V_288 != V_280 -> V_286 ) {
int V_69 = V_280 -> V_288 ;
struct V_289 * V_290 = & V_280 -> V_282 [ V_69 ] ;
V_145 = V_290 -> V_186 ;
F_62 ( & V_280 -> V_285 , V_62 ) ;
if ( V_145 > V_135 )
V_145 = V_135 ;
if ( V_145 > 0 && F_130 ( V_297 , V_290 -> V_147 , V_145 ) )
V_145 = - V_142 ;
if ( ++ V_69 >= V_287 )
V_69 = 0 ;
F_60 ( & V_280 -> V_285 , V_62 ) ;
V_280 -> V_288 = V_69 ;
}
if ( V_145 >= 0 )
break;
if ( V_126 -> V_301 & V_302 )
break;
V_145 = - V_303 ;
if ( F_131 ( V_252 ) )
break;
F_62 ( & V_280 -> V_285 , V_62 ) ;
F_132 () ;
F_60 ( & V_280 -> V_285 , V_62 ) ;
}
F_133 ( V_304 ) ;
F_134 ( & V_280 -> V_291 , & V_291 ) ;
F_62 ( & V_280 -> V_285 , V_62 ) ;
return V_145 ;
}
static T_4
F_135 ( struct V_126 * V_126 , const char T_5 * V_297 ,
T_6 V_135 , T_7 * V_298 )
{
return 0 ;
}
static unsigned int
F_136 ( struct V_126 * V_305 , T_11 * V_291 )
{
struct V_279 * V_280 = V_305 -> V_296 ;
unsigned int V_306 = 0 ;
unsigned long V_62 ;
if ( V_280 == 0 )
return 0 ;
F_137 ( V_305 , & V_280 -> V_291 , V_291 ) ;
F_60 ( & V_280 -> V_285 , V_62 ) ;
if ( V_280 -> V_288 != V_280 -> V_286 )
V_306 |= V_307 ;
F_62 ( & V_280 -> V_285 , V_62 ) ;
return V_306 ;
}
static int
F_138 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
struct V_279 * V_280 = V_126 -> V_296 ;
unsigned long V_62 ;
if ( V_280 != 0 ) {
V_126 -> V_296 = NULL ;
F_60 ( & V_283 , V_62 ) ;
F_139 ( & V_280 -> V_168 ) ;
F_62 ( & V_283 , V_62 ) ;
#if F_51 ( V_294 ) && F_51 ( F_21 )
if ( V_280 -> V_295 )
F_140 () ;
#endif
F_141 ( V_280 ) ;
}
return 0 ;
}
static void F_142 ( void )
{
F_143 () ;
F_144 () ;
}
static int F_145 ( T_12 V_308 )
{
int error = 0 ;
while ( ! V_44 . V_45 )
F_19 () ;
F_146 () ;
#ifdef F_147
if ( F_148 ( V_309 ) )
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
return - V_257 ;
}
if ( error )
return error ;
F_94 ( 100 ) ;
return 0 ;
}
static void F_150 ( void )
{
V_88 = 1 ;
V_46 ( 0 , NULL ) ;
F_94 ( 10 ) ;
F_151 () ;
F_152 () ;
}
static int F_153 ( T_12 V_308 )
{
return V_308 == V_310
&& ( F_25 ( V_132 , NULL , 0 , - 1 ) >= 0 ) ;
}
static int F_154 ( void )
{
if ( V_17 == V_18 )
F_105 () ;
V_311 . V_312 = F_142 ;
V_311 . V_313 = F_150 ;
F_155 ( & V_314 ) ;
return 0 ;
}
static int F_156 ( struct V_126 * V_305 ,
T_13 V_315 , T_14 V_210 )
{
T_15 T_5 * V_316 = ( T_15 T_5 * ) V_210 ;
int error = - V_141 ;
switch ( V_315 ) {
case V_317 :
if ( ! F_157 ( V_318 ) )
return - V_319 ;
return F_158 ( V_310 ) ;
case V_320 :
if ( F_25 ( V_132 , NULL , 0 , - 1 ) < 0 )
return F_159 ( 0 , V_316 ) ;
else
return F_159 ( 1 , V_316 ) ;
#ifdef F_160
case V_321 :
{
int V_322 ;
V_322 = F_161 () ;
if ( V_322 < 0 )
return V_322 ;
else
return F_159 ( V_322 , V_316 ) ;
}
case V_323 :
{
int V_322 ;
error = F_162 ( V_322 , V_316 ) ;
if ( error )
return error ;
return F_163 ( V_322 ) ;
}
#ifdef V_294
case V_324 : {
struct V_279 * V_280 = V_305 -> V_296 ;
if ( V_280 -> V_295 )
return 0 ;
V_280 -> V_295 = 1 ;
F_164 () ;
return 0 ;
}
#endif
#endif
case V_325 :
return F_159 ( V_17 , V_316 ) ;
case V_326 :
return F_159 ( V_9 , V_316 ) ;
}
return error ;
}
static long F_165 ( struct V_126 * V_305 ,
T_13 V_315 , T_14 V_210 )
{
int V_145 ;
F_122 ( & V_293 ) ;
V_145 = F_156 ( V_305 , V_315 , V_210 ) ;
F_124 ( & V_293 ) ;
return V_145 ;
}
static long F_166 ( struct V_126 * V_305 , T_13 V_315 , T_14 V_210 )
{
switch ( V_315 ) {
case V_317 :
break;
case V_327 :
V_315 = V_321 ;
break;
case V_328 :
V_315 = V_323 ;
break;
case V_329 :
V_315 = V_325 ;
break;
case V_330 :
V_315 = V_326 ;
break;
case V_331 :
V_315 = V_320 ;
break;
case V_332 :
V_315 = V_324 ;
break;
default:
return - V_333 ;
}
return F_165 ( V_305 , V_315 , ( unsigned long ) F_167 ( V_210 ) ) ;
}
static int F_168 ( void )
{
if ( ! V_3 )
return 0 ;
if ( F_169 ( & V_334 ) < 0 )
F_4 ( V_5 L_78 ) ;
return 0 ;
}
static inline void
F_170 ( volatile unsigned char T_9 * V_3 )
{
V_3 [ V_82 ] &= ~ V_83 ; F_171 () ;
while ( ( V_3 [ V_82 ] & V_85 ) != 0 )
;
V_3 [ V_82 ] |= V_83 ; F_171 () ;
while ( ( V_3 [ V_82 ] & V_85 ) == 0 )
;
}
static inline void
F_172 ( volatile unsigned char T_9 * V_3 , int V_174 )
{
V_3 [ V_175 ] |= V_176 | V_177 ; F_171 () ;
V_3 [ V_178 ] = V_174 ; F_171 () ;
F_170 ( V_3 ) ;
}
static inline int
F_173 ( volatile unsigned char T_9 * V_3 )
{
int V_174 ;
V_3 [ V_175 ] = ( V_3 [ V_175 ] & ~ V_176 ) | V_177 ; F_171 () ;
V_174 = V_3 [ V_178 ] ; F_171 () ;
F_170 ( V_3 ) ;
V_174 = V_3 [ V_178 ] ; F_171 () ;
return V_174 ;
}
int
F_174 ( struct V_80 * V_81 )
{
unsigned long V_62 ;
int V_69 , V_335 , V_336 ;
volatile unsigned char T_9 * V_124 = V_3 ;
V_81 -> V_45 = 1 ;
V_336 = V_81 -> V_147 [ 0 ] ;
V_335 = V_150 [ V_336 ] [ 0 ] ;
if ( V_335 >= 0 && V_81 -> V_149 != V_335 + 1 )
return - V_141 ;
F_175 ( V_62 ) ;
while ( V_33 != V_34 )
F_19 () ;
while ( ( V_3 [ V_82 ] & V_85 ) == 0 )
;
F_172 ( V_124 , V_336 ) ;
if ( V_335 < 0 ) {
V_335 = V_81 -> V_149 - 1 ;
F_172 ( V_124 , V_335 ) ;
}
for ( V_69 = 1 ; V_69 <= V_335 ; ++ V_69 )
F_172 ( V_124 , V_81 -> V_147 [ V_69 ] ) ;
V_335 = V_150 [ V_336 ] [ 1 ] ;
if ( V_335 < 0 )
V_335 = F_173 ( V_124 ) ;
for ( V_69 = 0 ; V_69 < V_335 ; ++ V_69 )
V_81 -> V_92 [ V_69 + V_81 -> V_91 ] = F_173 ( V_124 ) ;
if ( V_81 -> V_165 )
(* V_81 -> V_165 )( V_81 ) ;
F_176 ( V_62 ) ;
return 0 ;
}
void F_177 ( int V_337 )
{
struct V_80 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
for (; V_337 > 0 ; -- V_337 ) {
V_81 . V_149 = 4 ;
V_81 . V_165 = NULL ;
V_81 . V_147 [ 0 ] = 0xee ;
V_81 . V_147 [ 1 ] = 4 ;
V_81 . V_147 [ 2 ] = 0 ;
V_81 . V_147 [ 3 ] = 1 ;
V_81 . V_92 [ 0 ] = V_151 ;
V_81 . V_91 = 1 ;
V_81 . V_160 = 0 ;
F_174 ( & V_81 ) ;
F_94 ( 50 ) ;
V_81 . V_149 = 4 ;
V_81 . V_165 = NULL ;
V_81 . V_147 [ 0 ] = 0xee ;
V_81 . V_147 [ 1 ] = 4 ;
V_81 . V_147 [ 2 ] = 0 ;
V_81 . V_147 [ 3 ] = 0 ;
V_81 . V_92 [ 0 ] = V_151 ;
V_81 . V_91 = 1 ;
V_81 . V_160 = 0 ;
F_174 ( & V_81 ) ;
F_94 ( 50 ) ;
}
F_94 ( 50 ) ;
}
static int F_178 ( void )
{
F_69 () ;
V_338 = 1 ;
#ifdef F_21
F_179 ( 1 ) ;
#endif
return 0 ;
}
static void F_180 ( void )
{
struct V_80 V_81 ;
if ( ! V_338 )
return;
F_29 ( & V_81 , NULL , 2 , V_89 , 2 ) ;
F_31 ( & V_81 ) ;
#ifdef F_21
F_179 ( 0 ) ;
#endif
F_71 () ;
V_338 = 0 ;
}
static int F_181 ( void )
{
F_182 ( & V_339 ) ;
return 0 ;
}
