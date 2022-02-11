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
if ( F_18 ( V_50 , V_51 , V_52 ,
L_20 , ( void * ) 0 ) )
F_4 ( V_5 L_21
L_22 , V_50 ) ;
else
V_53 = 1 ;
}
}
F_11 ( & V_3 [ V_30 ] , V_54 | V_55 | V_56 ) ;
V_57 = 1 ;
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
int V_58 = F_25 ( V_59 ,
NULL , V_60 , 0 ) ;
V_61 = 1 ;
if ( V_58 == V_62 )
V_63 [ 0 ] . V_64 |= V_65 ;
else
V_63 [ 0 ] . V_64 |= V_66 ;
} else if ( F_24 ( L_25 ) ||
F_24 ( L_26 ) ) {
V_61 = 2 ;
V_63 [ 0 ] . V_64 |= V_67 ;
V_63 [ 1 ] . V_64 |= V_67 ;
} else {
struct V_21 * V_68 =
F_2 ( NULL , L_27 ) ;
const T_3 * V_69 = NULL ;
if ( V_68 )
V_69 = F_3 ( V_68 , L_28 , NULL ) ;
if ( V_69 ) {
V_61 = ( V_69 [ 6 ] >> 16 ) & 0xff ;
V_63 [ 0 ] . V_64 |= V_67 ;
if ( V_61 > 1 )
V_63 [ 1 ] . V_64 |= V_67 ;
}
F_9 ( V_68 ) ;
}
#endif
V_70 = F_26 ( L_29 , NULL ) ;
if ( V_70 ) {
long V_71 ;
for ( V_71 = 0 ; V_71 < V_61 ; V_71 ++ ) {
char V_72 [ 16 ] ;
sprintf ( V_72 , L_30 , V_71 ) ;
V_73 [ V_71 ] = F_27 ( V_72 , 0 , V_70 ,
& V_74 , ( void * ) V_71 ) ;
}
V_75 = F_28 ( L_31 , 0 , V_70 , & V_76 ) ;
V_77 = F_28 ( L_32 , 0 , V_70 ,
& V_78 ) ;
V_79 = F_28 ( L_33 , 0600 , V_70 ,
& V_80 ) ;
}
return 0 ;
}
static int
F_12 ( void )
{
int V_81 ;
struct V_82 V_83 ;
F_11 ( & V_3 [ V_84 ] , V_3 [ V_84 ] | V_85 ) ;
F_11 ( & V_3 [ V_86 ] , ( V_3 [ V_86 ] | V_85 ) & ~ V_87 ) ;
F_29 ( & V_83 , NULL , 2 , V_88 , V_10 ) ;
V_81 = 100000 ;
while ( ! V_83 . V_45 ) {
if ( -- V_81 < 0 ) {
F_4 ( V_5 L_34 ) ;
return 0 ;
}
F_30 ( 10 ) ;
F_19 () ;
}
V_81 = 100000 ;
V_89 [ 0 ] [ 0 ] = 1 ;
while ( V_89 [ 0 ] [ 0 ] || V_33 != V_34 ) {
if ( -- V_81 < 0 ) {
F_4 ( V_5 L_35 ) ;
return 0 ;
}
if ( V_33 == V_34 )
V_90 = 1 ;
V_47 ( 0 , NULL ) ;
F_30 ( 10 ) ;
}
if ( V_17 == V_25 ) {
F_29 ( & V_83 , NULL , 2 , V_91 , 2 ) ;
while ( ! V_83 . V_45 )
F_19 () ;
}
F_29 ( & V_83 , NULL , 1 , V_92 ) ;
F_31 ( & V_83 ) ;
if ( V_83 . V_93 > 0 )
V_39 = V_83 . V_94 [ 0 ] ;
if ( V_17 == V_25 ) {
F_29 ( & V_83 , NULL , 2 , V_95 ,
V_96 ) ;
F_31 ( & V_83 ) ;
if ( V_83 . V_93 == 2 ) {
if ( V_83 . V_94 [ 1 ] & V_97 )
V_98 = 1 ;
F_4 ( V_36 L_36 ,
V_98 ? L_37 : L_38 ) ;
}
}
return 1 ;
}
int
F_32 ( void )
{
return V_17 ;
}
static void F_33 ( int V_99 )
{
struct V_82 V_83 ;
if ( V_17 != V_25 )
return;
V_98 = V_99 ;
F_29 ( & V_83 , NULL , 2 , V_95 , V_96 ) ;
F_31 ( & V_83 ) ;
if ( V_83 . V_93 < 2 )
return;
if ( V_99 )
F_29 ( & V_83 , NULL , 4 , V_95 ,
V_100 ,
V_83 . V_94 [ 0 ] , V_97 ) ;
else
F_29 ( & V_83 , NULL , 4 , V_95 ,
V_101 ,
V_83 . V_94 [ 0 ] , V_97 ) ;
F_31 ( & V_83 ) ;
}
static void
F_34 ( struct V_82 * V_83 )
{
unsigned int V_102 = V_66 ;
long V_103 , V_104 , V_105 , V_106 , V_107 ;
long V_108 , V_109 ;
long V_110 , V_111 , time , V_112 ;
int V_58 = F_25 ( V_59 ,
NULL , V_60 , 0 ) ;
if ( V_83 -> V_94 [ 0 ] & 0x01 )
V_113 |= V_114 ;
else
V_113 &= ~ V_114 ;
if ( V_58 == V_62 ) {
V_109 = 189 ;
V_108 = 213 ;
V_107 = 6500 ;
} else {
V_109 = 330 ;
V_108 = 330 ;
V_107 = 6500 ;
}
V_106 = V_109 ;
if ( V_83 -> V_94 [ 0 ] & 0x04 ) {
V_102 |= V_115 ;
if ( V_83 -> V_94 [ 0 ] & 0x02 )
V_102 |= V_116 ;
V_105 = ( V_83 -> V_94 [ 1 ] << 8 ) | V_83 -> V_94 [ 2 ] ;
V_111 = ( V_105 * 265 + 72665 ) / 10 ;
V_110 = V_83 -> V_94 [ 5 ] ;
if ( ( V_83 -> V_94 [ 0 ] & 0x01 ) == 0 ) {
if ( V_110 > 200 )
V_105 += ( ( V_110 - 200 ) * 15 ) / 100 ;
} else if ( V_83 -> V_94 [ 0 ] & 0x02 ) {
V_105 = ( V_105 * 97 ) / 100 ;
V_106 = V_108 ;
}
V_104 = ( 100 * V_105 ) / V_106 ;
if ( V_83 -> V_94 [ 0 ] & 0x40 ) {
V_103 = ( V_83 -> V_94 [ 6 ] << 8 ) + V_83 -> V_94 [ 7 ] ;
if ( V_103 > V_107 )
V_103 = V_107 ;
V_103 *= 100 ;
V_103 = 100 - V_103 / V_107 ;
if ( V_103 < V_104 )
V_104 = V_103 ;
}
if ( V_110 > 0 )
time = ( V_104 * 16440 ) / V_110 ;
else
time = 0 ;
V_112 = 100 ;
V_110 = - V_110 ;
} else
V_104 = V_112 = V_110 = V_111 = time = 0 ;
V_63 [ V_117 ] . V_64 = V_102 ;
V_63 [ V_117 ] . V_104 = V_104 ;
V_63 [ V_117 ] . V_118 = V_112 ;
V_63 [ V_117 ] . V_110 = V_110 ;
V_63 [ V_117 ] . V_111 = V_111 ;
V_63 [ V_117 ] . V_119 = time ;
F_35 ( 0 , & V_120 ) ;
}
static void
F_36 ( struct V_82 * V_83 )
{
unsigned int V_102 = V_67 ;
int V_110 ;
unsigned int V_121 , V_112 , V_111 ;
if ( V_83 -> V_94 [ 1 ] & 0x01 )
V_113 |= V_114 ;
else
V_113 &= ~ V_114 ;
V_121 = V_112 = V_110 = V_111 = 0 ;
if ( V_83 -> V_94 [ 1 ] & 0x04 ) {
V_102 |= V_115 ;
switch( V_83 -> V_94 [ 0 ] ) {
case 3 :
case 4 : V_121 = V_83 -> V_94 [ 2 ] ;
V_112 = V_83 -> V_94 [ 3 ] ;
V_110 = * ( ( signed char * ) & V_83 -> V_94 [ 4 ] ) ;
V_111 = V_83 -> V_94 [ 5 ] ;
break;
case 5 : V_121 = ( V_83 -> V_94 [ 2 ] << 8 ) | V_83 -> V_94 [ 3 ] ;
V_112 = ( V_83 -> V_94 [ 4 ] << 8 ) | V_83 -> V_94 [ 5 ] ;
V_110 = * ( ( signed short * ) & V_83 -> V_94 [ 6 ] ) ;
V_111 = ( V_83 -> V_94 [ 8 ] << 8 ) | V_83 -> V_94 [ 9 ] ;
break;
default:
F_37 ( L_39
L_40 , V_83 -> V_93 ,
V_83 -> V_94 ) ;
break;
}
}
if ( ( V_83 -> V_94 [ 1 ] & 0x01 ) && ( V_110 > 0 ) )
V_102 |= V_116 ;
V_63 [ V_117 ] . V_64 = V_102 ;
V_63 [ V_117 ] . V_104 = V_121 ;
V_63 [ V_117 ] . V_118 = V_112 ;
V_63 [ V_117 ] . V_110 = V_110 ;
V_63 [ V_117 ] . V_111 = V_111 ;
if ( V_110 ) {
if ( ( V_83 -> V_94 [ 1 ] & 0x01 ) && ( V_110 > 0 ) )
V_63 [ V_117 ] . V_119
= ( ( V_112 - V_121 ) * 3600 ) / V_110 ;
else
V_63 [ V_117 ] . V_119
= ( V_121 * 3600 ) / ( - V_110 ) ;
} else
V_63 [ V_117 ] . V_119 = 0 ;
V_117 = ( V_117 + 1 ) % V_61 ;
F_35 ( 0 , & V_120 ) ;
}
static void
F_38 ( void )
{
if ( F_39 ( 0 , & V_120 ) )
return;
if ( V_17 == V_18 )
F_29 ( & V_44 , F_34 ,
1 , V_122 ) ;
else
F_29 ( & V_44 , F_36 ,
2 , V_123 , V_117 + 1 ) ;
}
static int F_40 ( struct V_124 * V_125 , void * V_126 )
{
F_41 ( V_125 , L_41 , V_37 ) ;
F_41 ( V_125 , L_42 , V_39 ) ;
F_41 ( V_125 , L_43 ,
( ( V_113 & V_114 ) != 0 ) || V_61 == 0 ) ;
F_41 ( V_125 , L_44 , V_61 ) ;
return 0 ;
}
static int F_42 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_43 ( V_128 , F_40 , NULL ) ;
}
static int F_44 ( struct V_124 * V_125 , void * V_126 )
{
int V_71 ;
static const char * V_129 [] = {
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
for ( V_71 = 0 ; V_71 < 11 ; V_71 ++ ) {
F_41 ( V_125 , L_56 ,
V_71 , V_130 [ V_71 ] , V_129 [ V_71 ] ) ;
}
return 0 ;
}
static int F_45 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_43 ( V_128 , F_44 , NULL ) ;
}
static int F_46 ( struct V_124 * V_125 , void * V_126 )
{
long V_131 = ( long ) V_125 -> V_132 ;
F_47 ( V_125 , '\n' ) ;
F_41 ( V_125 , L_57 , V_63 [ V_131 ] . V_64 ) ;
F_41 ( V_125 , L_58 , V_63 [ V_131 ] . V_104 ) ;
F_41 ( V_125 , L_59 , V_63 [ V_131 ] . V_118 ) ;
F_41 ( V_125 , L_60 , V_63 [ V_131 ] . V_110 ) ;
F_41 ( V_125 , L_61 , V_63 [ V_131 ] . V_111 ) ;
F_41 ( V_125 , L_62 , V_63 [ V_131 ] . V_119 ) ;
return 0 ;
}
static int F_48 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_43 ( V_128 , F_46 , F_49 ( V_127 ) ) ;
}
static int F_50 ( struct V_124 * V_125 , void * V_126 )
{
#if F_51 ( V_133 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_134 , NULL , 0 , - 1 ) >= 0 )
F_41 ( V_125 , L_63 , V_135 ) ;
#endif
if ( V_17 == V_25 )
F_41 ( V_125 , L_64 , V_98 ) ;
return 0 ;
}
static int F_52 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_43 ( V_128 , F_50 , NULL ) ;
}
static T_4 F_53 ( struct V_128 * V_128 ,
const char T_5 * V_136 , T_6 V_137 , T_7 * V_138 )
{
char V_139 [ 33 ] ;
char * V_140 , * V_141 ;
T_6 V_142 = V_137 ;
if ( ! V_137 )
return - V_143 ;
if ( V_137 > 32 )
V_137 = 32 ;
if ( F_54 ( V_139 , V_136 , V_137 ) )
return - V_144 ;
V_139 [ V_137 ] = 0 ;
V_140 = V_139 ;
while( * V_140 == ' ' )
V_140 ++ ;
V_141 = V_140 ;
while( * V_141 && ( * V_141 != '=' ) ) {
if ( * V_141 == ' ' )
* V_141 = 0 ;
V_141 ++ ;
}
if ( ( * V_141 ) == 0 )
return - V_143 ;
* ( V_141 ++ ) = 0 ;
while( * V_141 == ' ' )
V_141 ++ ;
#if F_51 ( V_133 ) && F_51 ( F_23 )
if ( V_17 == V_25 &&
F_25 ( V_134 , NULL , 0 , - 1 ) >= 0 )
if ( ! strcmp ( V_140 , L_65 ) )
V_135 = ( ( * V_141 ) == '1' ) ;
#endif
if ( V_17 == V_25 && ! strcmp ( V_140 , L_66 ) ) {
int V_145 ;
V_145 = ( ( * V_141 ) == '1' ) ;
if ( V_145 != V_98 )
F_33 ( V_145 ) ;
}
return V_142 ;
}
static int F_55 ( struct V_82 * V_83 , int V_146 )
{
int V_71 , V_147 ;
if ( ( V_4 == NULL ) || ( ! V_57 ) ) {
V_83 -> V_45 = 1 ;
return - V_148 ;
}
V_147 = - V_143 ;
switch ( V_83 -> V_149 [ 0 ] ) {
case V_150 :
for ( V_71 = 0 ; V_71 < V_83 -> V_151 - 1 ; ++ V_71 )
V_83 -> V_149 [ V_71 ] = V_83 -> V_149 [ V_71 + 1 ] ;
-- V_83 -> V_151 ;
if ( V_152 [ V_83 -> V_149 [ 0 ] ] [ 1 ] != 0 ) {
V_83 -> V_94 [ 0 ] = V_153 ;
V_83 -> V_93 = 1 ;
} else
V_83 -> V_93 = 0 ;
V_147 = F_56 ( V_83 ) ;
break;
case V_154 :
switch ( V_83 -> V_149 [ 1 ] ) {
case V_155 :
if ( V_83 -> V_151 != 2 )
break;
V_83 -> V_149 [ 0 ] = V_156 ;
V_83 -> V_151 = 1 ;
V_83 -> V_93 = 3 ;
V_83 -> V_94 [ 0 ] = V_154 ;
V_83 -> V_94 [ 1 ] = 0 ;
V_83 -> V_94 [ 2 ] = V_155 ;
V_147 = F_56 ( V_83 ) ;
break;
case V_157 :
if ( V_83 -> V_151 != 6 )
break;
V_83 -> V_149 [ 0 ] = V_158 ;
V_83 -> V_151 = 5 ;
for ( V_71 = 1 ; V_71 <= 4 ; ++ V_71 )
V_83 -> V_149 [ V_71 ] = V_83 -> V_149 [ V_71 + 1 ] ;
V_83 -> V_93 = 3 ;
V_83 -> V_94 [ 0 ] = V_154 ;
V_83 -> V_94 [ 1 ] = 0 ;
V_83 -> V_94 [ 2 ] = V_157 ;
V_147 = F_56 ( V_83 ) ;
break;
}
break;
case V_159 :
if ( ! V_9 )
return - V_148 ;
for ( V_71 = V_83 -> V_151 - 1 ; V_71 > 1 ; -- V_71 )
V_83 -> V_149 [ V_71 + 2 ] = V_83 -> V_149 [ V_71 ] ;
V_83 -> V_149 [ 3 ] = V_83 -> V_151 - 2 ;
V_83 -> V_149 [ 2 ] = V_160 ;
V_83 -> V_149 [ 0 ] = V_161 ;
V_83 -> V_151 += 2 ;
V_83 -> V_162 = 1 ;
V_83 -> V_93 = 0 ;
V_147 = F_56 ( V_83 ) ;
break;
}
if ( V_147 ) {
V_83 -> V_45 = 1 ;
return V_147 ;
}
if ( V_146 )
while ( ! V_83 -> V_45 )
F_19 () ;
return 0 ;
}
static int F_57 ( int V_163 )
{
struct V_82 V_83 ;
if ( V_163 ) {
F_29 ( & V_83 , NULL , 5 , V_161 , 0 , 0x86 ,
V_164 >> 8 , V_164 ) ;
V_160 = 2 ;
} else {
F_29 ( & V_83 , NULL , 1 , V_165 ) ;
V_160 = 0 ;
}
while ( ! V_83 . V_45 )
F_19 () ;
return 0 ;
}
static int F_58 ( int V_163 )
{
if ( ( V_4 == NULL ) || ( ! V_57 ) || ! V_9 )
return - V_148 ;
V_164 = V_163 ;
return F_57 ( V_163 ) ;
}
static int F_59 ( void )
{
struct V_82 V_83 ;
int V_166 = V_164 ;
if ( ( V_4 == NULL ) || ( ! V_57 ) || ! V_9 )
return - V_148 ;
F_57 ( 0 ) ;
V_83 . V_151 = 4 ;
V_83 . V_167 = NULL ;
V_83 . V_149 [ 0 ] = V_161 ;
V_83 . V_149 [ 1 ] = V_168 ;
V_83 . V_149 [ 2 ] = 0 ;
V_83 . V_149 [ 3 ] = 0 ;
V_83 . V_149 [ 4 ] = 0 ;
V_83 . V_93 = 0 ;
V_83 . V_162 = 1 ;
if ( F_56 ( & V_83 ) != 0 ) {
F_4 ( V_5 L_67 ) ;
return - V_169 ;
}
F_31 ( & V_83 ) ;
if ( V_166 != 0 )
F_57 ( V_166 ) ;
return 0 ;
}
int
F_29 ( struct V_82 * V_83 , void (* V_167)( struct V_82 * ) ,
int V_151 , ... )
{
T_8 V_170 ;
int V_71 ;
if ( V_4 == NULL )
return - V_148 ;
if ( V_151 < 0 || V_151 > 32 ) {
F_4 ( V_5 L_68 , V_151 ) ;
V_83 -> V_45 = 1 ;
return - V_143 ;
}
V_83 -> V_151 = V_151 ;
V_83 -> V_167 = V_167 ;
va_start ( V_170 , V_151 ) ;
for ( V_71 = 0 ; V_71 < V_151 ; ++ V_71 )
V_83 -> V_149 [ V_71 ] = va_arg ( V_170 , int ) ;
va_end ( V_170 ) ;
V_83 -> V_93 = 0 ;
V_83 -> V_162 = 0 ;
return F_56 ( V_83 ) ;
}
int
F_56 ( struct V_82 * V_83 )
{
unsigned long V_64 ;
int V_171 ;
if ( V_3 == NULL ) {
V_83 -> V_45 = 1 ;
return - V_148 ;
}
if ( V_83 -> V_151 <= 0 ) {
V_83 -> V_45 = 1 ;
return 0 ;
}
V_171 = V_152 [ V_83 -> V_149 [ 0 ] ] [ 0 ] ;
if ( V_171 >= 0 && V_83 -> V_151 != V_171 + 1 ) {
V_83 -> V_45 = 1 ;
return - V_143 ;
}
V_83 -> V_172 = NULL ;
V_83 -> V_173 = 0 ;
V_83 -> V_45 = 0 ;
F_60 ( & V_8 , V_64 ) ;
if ( V_174 != 0 ) {
V_175 -> V_172 = V_83 ;
V_175 = V_83 ;
} else {
V_174 = V_83 ;
V_175 = V_83 ;
if ( V_33 == V_34 )
F_61 () ;
}
F_62 ( & V_8 , V_64 ) ;
return 0 ;
}
static inline void
F_63 ( void )
{
int V_81 = 4000 ;
while ( ( F_64 ( & V_3 [ V_84 ] ) & V_87 ) == 0 ) {
if ( -- V_81 < 0 ) {
F_4 ( V_5 L_69 ) ;
return;
}
F_30 ( 10 ) ;
}
}
static inline void
F_65 ( int V_176 )
{
volatile unsigned char T_9 * V_126 = V_3 ;
F_11 ( & V_126 [ V_177 ] , F_64 ( & V_126 [ V_177 ] ) | V_178 | V_179 ) ;
F_11 ( & V_126 [ V_180 ] , V_176 ) ;
F_11 ( & V_126 [ V_84 ] , F_64 ( & V_126 [ V_84 ] ) & ~ V_85 ) ;
( void ) F_64 ( & V_126 [ V_84 ] ) ;
}
static inline void
F_66 ( void )
{
volatile unsigned char T_9 * V_126 = V_3 ;
F_11 ( & V_126 [ V_177 ] , ( F_64 ( & V_126 [ V_177 ] ) & ~ V_178 ) | V_179 ) ;
F_64 ( & V_126 [ V_180 ] ) ;
F_11 ( & V_126 [ V_84 ] , F_64 ( & V_126 [ V_84 ] ) & ~ V_85 ) ;
( void ) F_64 ( & V_126 [ V_84 ] ) ;
}
static inline void
F_67 ( struct V_82 * V_83 )
{
void (* V_167)( struct V_82 * ) = V_83 -> V_167 ;
V_58 () ;
V_83 -> V_45 = 1 ;
if ( V_167 )
(* V_167)( V_83 ) ;
}
static void
F_61 ( void )
{
struct V_82 * V_83 ;
V_83 = V_174 ;
if ( V_83 == 0 || V_33 != V_34
|| ( V_181 ) )
return;
V_33 = V_182 ;
V_183 = 1 ;
V_184 = V_152 [ V_83 -> V_149 [ 0 ] ] [ 0 ] ;
F_63 () ;
F_65 ( V_83 -> V_149 [ 0 ] ) ;
}
void
F_19 ( void )
{
if ( ! V_3 )
return;
if ( V_185 )
return;
V_47 ( 0 , NULL ) ;
}
void
F_68 ( void )
{
if ( ! V_3 )
return;
if ( V_185 )
return;
V_90 = 1 ;
do {
V_47 ( 0 , NULL ) ;
} while ( V_186 && ( V_90 || V_33 != V_34
|| V_181 ) );
}
void
F_31 ( struct V_82 * V_83 )
{
if ( ! V_3 )
return;
while( ( V_33 != V_34 && V_33 != V_187 ) || ! V_83 -> V_45 )
V_47 ( 0 , NULL ) ;
}
void
F_69 ( void )
{
unsigned long V_64 ;
if ( ! V_3 )
return;
F_60 ( & V_8 , V_64 ) ;
V_186 ++ ;
if ( V_186 > 1 ) {
F_62 ( & V_8 , V_64 ) ;
return;
}
do {
F_62 ( & V_8 , V_64 ) ;
if ( V_181 )
V_90 = 1 ;
V_47 ( 0 , NULL ) ;
F_60 ( & V_8 , V_64 ) ;
if ( ! V_90 && V_33 == V_34 && ! V_181 ) {
if ( V_50 >= 0 )
F_70 ( V_50 ) ;
F_11 ( & V_3 [ V_30 ] , V_56 | V_31 ) ;
F_62 ( & V_8 , V_64 ) ;
break;
}
} while ( 1 );
}
void
F_71 ( void )
{
unsigned long V_64 ;
if ( ! V_3 || ( V_186 < 1 ) )
return;
F_60 ( & V_8 , V_64 ) ;
V_186 -- ;
if ( V_186 > 0 ) {
F_62 ( & V_8 , V_64 ) ;
return;
}
V_90 = 1 ;
if ( V_50 >= 0 )
F_72 ( V_50 ) ;
F_11 ( & V_3 [ V_30 ] , V_56 | V_54 ) ;
F_62 ( & V_8 , V_64 ) ;
F_19 () ;
}
static void
F_73 ( unsigned char * V_149 , int V_188 )
{
unsigned char V_189 , V_190 ;
int V_71 = 0 ;
V_191 = 0 ;
if ( V_192 || V_188 < 1 ) {
V_90 = 0 ;
V_130 [ 8 ] ++ ;
return;
}
V_189 = V_149 [ 0 ] ;
if ( V_189 == 0 )
V_130 [ 9 ] ++ ;
if ( V_189 & V_13 )
V_189 &= ~ ( V_193 | V_194 ) ;
V_172:
if ( V_189 == 0 ) {
if ( V_71 > V_130 [ 10 ] )
V_130 [ 10 ] = V_71 ;
return;
}
for ( V_190 = 0 ; V_190 < 8 ; V_190 ++ )
if ( V_189 & ( 1 << V_190 ) )
break;
V_130 [ V_190 ] ++ ;
V_71 ++ ;
V_189 &= ~ ( 1 << V_190 ) ;
if ( ( 1 << V_190 ) & V_13 ) {
if ( ( V_149 [ 0 ] & V_193 ) == 0 ) {
struct V_82 * V_83 = V_181 ;
if ( V_83 == 0 ) {
F_4 ( V_5 L_70 ) ;
return;
}
V_181 = NULL ;
if ( V_188 <= 2 )
V_83 -> V_93 = 0 ;
else {
memcpy ( V_83 -> V_94 , V_149 + 1 , V_188 - 1 ) ;
V_83 -> V_93 = V_188 - 1 ;
}
F_67 ( V_83 ) ;
} else {
if ( V_188 == 4 && V_149 [ 1 ] == 0x2c ) {
extern int V_195 , V_196 ;
if ( V_195 ) {
V_196 = V_149 [ 2 ] ;
return;
}
}
#ifdef F_74
if ( ! ( V_17 == V_18 && V_188 == 4
&& V_149 [ 1 ] == 0x2c && V_149 [ 3 ] == 0xff
&& ( V_149 [ 2 ] & ~ 1 ) == 0xf4 ) )
F_75 ( V_149 + 1 , V_188 - 1 , 1 ) ;
#endif
}
}
else if ( ( 1 << V_190 ) & V_12 ) {
#ifdef F_21
if ( V_188 == 3 )
F_76 ( V_149 [ 1 ] >> 4 ) ;
#endif
}
else if ( ( 1 << V_190 ) & V_14 ) {
if ( V_61 ) {
if ( ( -- V_197 ) == 0 ) {
F_38 () ;
V_197 = V_198 ;
}
}
}
else if ( ( 1 << V_190 ) & V_26 ) {
if ( V_61 )
F_38 () ;
F_77 ( V_149 , V_188 ) ;
if ( V_188 == 6 ) {
F_78 ( V_199 , ! ! ( V_149 [ 1 ] & 8 ) ) ;
F_78 ( V_200 , V_149 [ 1 ] & 1 ) ;
}
} else {
F_77 ( V_149 , V_188 ) ;
}
goto V_172;
}
static struct V_82 *
F_79 ( void )
{
struct V_82 * V_83 ;
int V_201 = 0 ;
if ( V_3 [ V_84 ] & V_85 ) {
F_4 ( V_5 L_71 , V_3 [ V_84 ] ) ;
F_11 ( & V_3 [ V_32 ] , V_55 ) ;
return NULL ;
}
while ( ( F_64 ( & V_3 [ V_84 ] ) & V_87 ) != 0 )
;
if ( V_33 == V_202 || V_33 == V_203 )
V_201 = F_64 ( & V_3 [ V_180 ] ) ;
F_11 ( & V_3 [ V_84 ] , F_64 ( & V_3 [ V_84 ] ) | V_85 ) ;
F_63 () ;
switch ( V_33 ) {
case V_182 :
V_83 = V_174 ;
if ( V_184 < 0 ) {
V_184 = V_83 -> V_151 - 1 ;
F_65 ( V_184 ) ;
break;
}
if ( V_183 <= V_184 ) {
F_65 ( V_83 -> V_149 [ V_183 ++ ] ) ;
break;
}
V_83 -> V_173 = 1 ;
V_184 = V_152 [ V_83 -> V_149 [ 0 ] ] [ 1 ] ;
if ( V_184 == 0 ) {
V_33 = V_34 ;
V_174 = V_83 -> V_172 ;
if ( V_83 -> V_162 )
V_181 = V_83 ;
else
return V_83 ;
} else {
V_33 = V_202 ;
V_183 = 0 ;
V_204 = V_83 -> V_94 + V_83 -> V_93 ;
F_66 () ;
}
break;
case V_205 :
V_183 = 0 ;
V_184 = - 1 ;
V_33 = V_203 ;
V_204 = V_89 [ V_206 ] ;
F_66 () ;
if ( V_50 >= 0 && ! V_53 ) {
F_72 ( V_50 ) ;
V_53 = 1 ;
}
break;
case V_202 :
case V_203 :
if ( V_184 == - 1 ) {
V_184 = V_201 ;
if ( V_201 > 32 )
F_4 ( V_5 L_72 , V_201 ) ;
} else if ( V_183 < 32 ) {
V_204 [ V_183 ++ ] = V_201 ;
}
if ( V_183 < V_184 ) {
F_66 () ;
break;
}
if ( V_33 == V_203 ) {
V_33 = V_34 ;
V_207 [ V_206 ] = V_208 ;
V_209 [ V_206 ] = V_184 ;
} else {
V_83 = V_174 ;
V_174 = V_83 -> V_172 ;
V_83 -> V_93 += V_183 ;
if ( V_83 -> V_149 [ 0 ] == V_210 || V_83 -> V_149 [ 0 ] == V_211 )
V_33 = V_187 ;
else
V_33 = V_34 ;
return V_83 ;
}
break;
default:
F_4 ( V_5 L_73 ,
V_33 ) ;
}
return NULL ;
}
static T_10
V_47 ( int V_43 , void * V_212 )
{
unsigned long V_64 ;
int V_213 ;
int V_214 = 0 ;
int V_215 = - 1 ;
struct V_82 * V_83 = NULL ;
int V_216 = 0 ;
F_60 ( & V_8 , V_64 ) ;
++ V_185 ;
for (; ; ) {
V_213 = F_64 ( & V_3 [ V_32 ] ) & ( V_55 | V_56 ) ;
if ( V_213 == 0 )
break;
V_216 = 1 ;
if ( ++ V_214 > 1000 ) {
F_4 ( V_217 L_74
L_75 ,
V_213 , F_64 ( & V_3 [ V_30 ] ) , V_33 ) ;
break;
}
F_11 ( & V_3 [ V_32 ] , V_213 ) ;
if ( V_213 & V_56 ) {
V_90 = 1 ;
V_130 [ 0 ] ++ ;
}
if ( V_213 & V_55 ) {
V_83 = F_79 () ;
if ( V_83 )
break;
}
}
V_218:
if ( V_33 == V_34 ) {
if ( V_90 ) {
if ( V_207 [ 0 ] == V_219 )
V_206 = 0 ;
else if ( V_207 [ 1 ] == V_219 )
V_206 = 1 ;
else
goto V_220;
V_33 = V_205 ;
V_207 [ V_206 ] = V_221 ;
F_63 () ;
F_65 ( V_222 ) ;
V_90 = 0 ;
} else if ( V_174 )
F_61 () ;
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
F_62 ( & V_8 , V_64 ) ;
if ( V_83 ) {
F_67 ( V_83 ) ;
V_83 = NULL ;
}
if ( V_215 >= 0 ) {
F_73 ( V_89 [ V_215 ] , V_209 [ V_215 ] ) ;
F_60 ( & V_8 , V_64 ) ;
++ V_185 ;
V_207 [ V_215 ] = V_219 ;
V_215 = - 1 ;
goto V_218;
}
return F_80 ( V_216 ) ;
}
void
F_81 ( void )
{
unsigned long V_64 ;
F_60 ( & V_8 , V_64 ) ;
if ( V_33 == V_187 )
V_33 = V_34 ;
V_90 = 1 ;
F_62 ( & V_8 , V_64 ) ;
}
static T_10
V_51 ( int V_43 , void * V_212 )
{
unsigned long V_64 ;
if ( ( F_64 ( V_27 + 0x9 ) & 0x02 ) == 0 ) {
F_60 ( & V_8 , V_64 ) ;
if ( V_53 > 0 ) {
F_70 ( V_50 ) ;
V_53 = 0 ;
}
V_130 [ 1 ] ++ ;
V_90 = 1 ;
F_62 ( & V_8 , V_64 ) ;
V_47 ( 0 , NULL ) ;
return V_224 ;
}
return V_225 ;
}
void
F_82 ( int V_226 )
{
struct V_82 V_83 ;
if ( V_4 == NULL )
return ;
if ( V_17 == V_25 )
return ;
F_29 ( & V_83 , NULL , 2 , V_227 , V_228 |
( V_226 ? V_229 : V_230 ) ) ;
F_31 ( & V_83 ) ;
}
void
F_83 ( void )
{
struct V_82 V_83 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_192 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_83 , NULL , 2 , V_88 , V_13 |
V_14 ) ;
while( ! V_83 . V_45 )
F_19 () ;
}
F_29 ( & V_83 , NULL , 1 , V_231 ) ;
F_31 ( & V_83 ) ;
for (; ; )
;
}
void
F_85 ( void )
{
struct V_82 V_83 ;
if ( V_3 == NULL )
return;
F_84 () ;
V_192 = 1 ;
if ( V_17 != V_25 ) {
F_29 ( & V_83 , NULL , 2 , V_88 , V_13 |
V_14 ) ;
F_31 ( & V_83 ) ;
} else {
F_33 ( 0 ) ;
}
F_29 ( & V_83 , NULL , 5 , V_232 ,
'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_83 ) ;
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
V_233 [ 0 ] = F_64 ( & V_3 [ V_234 ] ) ;
V_233 [ 1 ] = F_64 ( & V_3 [ V_235 ] ) ;
V_233 [ 2 ] = F_64 ( & V_3 [ V_84 ] ) ;
V_233 [ 3 ] = F_64 ( & V_3 [ V_86 ] ) ;
V_233 [ 4 ] = F_64 ( & V_3 [ V_236 ] ) ;
V_233 [ 5 ] = F_64 ( & V_3 [ V_177 ] ) ;
V_233 [ 6 ] = F_64 ( & V_3 [ V_237 ] ) ;
V_233 [ 7 ] = F_64 ( & V_3 [ V_238 ] ) ;
}
static void
F_88 ( void )
{
F_11 ( & V_3 [ V_234 ] , V_233 [ 0 ] ) ;
F_11 ( & V_3 [ V_235 ] , V_233 [ 1 ] ) ;
F_11 ( & V_3 [ V_84 ] , V_233 [ 2 ] ) ;
F_11 ( & V_3 [ V_86 ] , V_233 [ 3 ] ) ;
F_11 ( & V_3 [ V_236 ] , V_233 [ 4 ] ) ;
F_11 ( & V_3 [ V_177 ] , V_233 [ 5 ] ) ;
F_11 ( & V_3 [ V_237 ] , V_233 [ 6 ] ) ;
F_11 ( & V_3 [ V_238 ] , V_233 [ 7 ] ) ;
F_11 ( & V_3 [ V_30 ] , V_31 | 0x7f ) ;
F_11 ( & V_3 [ V_32 ] , 0x7f ) ;
F_11 ( & V_3 [ V_30 ] , V_54 | V_55 | V_56 ) ;
}
static int F_89 ( void )
{
unsigned long V_239 ;
unsigned short V_240 ;
struct V_82 V_83 ;
struct V_241 * V_242 ;
V_242 = F_90 ( 0 , 0 ) ;
if ( ! V_242 )
return - V_42 ;
F_29 ( & V_83 , NULL , 2 , V_243 , V_244 | V_245 ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 2 , V_227 ,
V_230 | V_246 | V_228 | V_247 ) ;
F_31 ( & V_83 ) ;
V_239 = F_91 () ;
if ( ! V_248 ) {
F_29 ( & V_83 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_83 ) ;
}
F_87 () ;
F_25 ( V_134 , NULL , 0 , 1 ) ;
F_92 ( V_242 , 0x70 , & V_240 ) ;
V_240 &= ~ ( V_249 | V_250 ) ;
V_240 |= V_251 | V_252 ;
F_93 ( V_242 , 0x70 , V_240 ) ;
if ( V_248 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_92 ( V_242 , 0x70 , & V_240 ) ;
V_240 &= ~ ( V_251 | V_249 | V_250 | V_252 ) ;
F_93 ( V_242 , 0x70 , V_240 ) ;
F_96 ( V_242 ) ;
F_25 ( V_134 , NULL , 0 , 0 ) ;
F_88 () ;
if ( V_239 != 0xffffffff && ( V_239 & V_253 ) != 0 )
F_97 ( V_239 ) ;
F_98 ( NULL , V_254 -> V_255 ) ;
F_81 () ;
F_29 ( & V_83 , NULL , 2 , V_88 , V_10 ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 2 , V_243 ,
V_256 | V_245 ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 2 , V_227 ,
V_229 | V_246 | V_257 | V_228 | V_247 ) ;
F_31 ( & V_83 ) ;
return 0 ;
}
static int
F_99 ( void )
{
unsigned long V_239 ;
unsigned long V_258 ;
struct V_82 V_83 ;
if ( F_25 ( V_134 , NULL , 0 , - 1 ) < 0 ) {
F_4 ( V_5 L_76 ) ;
return - V_259 ;
}
if ( F_100 () > 1 || F_101 ( 0 ) )
return - V_260 ;
F_29 ( & V_83 , NULL , 2 , V_88 , 0 ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 4 , V_95 , V_261 ,
0xff , 0xff ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 4 , V_95 , V_262 ,
0 , V_263 |
( V_135 ? V_264 : 0 ) ) ;
F_31 ( & V_83 ) ;
V_258 = F_102 () ;
V_239 = F_91 () ;
if ( ! V_248 ) {
F_29 ( & V_83 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_83 ) ;
}
F_87 () ;
F_25 ( V_134 , NULL , 0 , 1 ) ;
if ( V_248 )
F_94 ( 5000 ) ;
else
F_95 () ;
F_25 ( V_134 , NULL , 0 , 0 ) ;
F_88 () ;
V_265 *= 2 ;
F_103 () ;
if ( V_239 != 0xffffffff && ( V_239 & V_253 ) != 0 )
F_97 ( V_239 ) ;
if ( V_258 != 0xffffffff && ( V_258 & V_266 ) != 0 )
F_104 ( V_258 ) ;
F_98 ( NULL , V_254 -> V_255 ) ;
F_81 () ;
F_29 ( & V_83 , NULL , 2 , V_91 , 2 ) ;
F_31 ( & V_83 ) ;
F_29 ( & V_83 , NULL , 2 , V_88 , V_10 ) ;
F_31 ( & V_83 ) ;
V_265 /= 2 ;
return 0 ;
}
static void F_105 ( void )
{
V_267 = F_10 ( V_268 , 0x100 ) ;
if ( V_267 == NULL )
F_4 ( V_269 L_77 ) ;
}
static int F_106 ( void )
{
int V_71 , V_176 ;
unsigned int V_270 ;
unsigned long V_271 ;
struct V_82 V_272 ;
unsigned int T_9 * V_273 ;
if ( V_267 == NULL )
return - V_274 ;
V_273 = V_267 + V_275 ;
for ( V_71 = 0x403f ; V_71 >= 0x4000 ; -- V_71 ) {
F_107 ( V_273 , V_71 ) ;
do {
V_176 = ( F_108 ( V_273 ) >> 16 ) & 0x3ff ;
} while ( V_176 == 0 );
if ( V_176 >= 0x100 )
break;
}
F_29 ( & V_272 , NULL , 5 , V_210 , 'M' , 'A' , 'T' , 'T' ) ;
F_31 ( & V_272 ) ;
F_81 () ;
F_25 ( V_134 , NULL , 0 , 1 ) ;
V_191 = 1 ;
V_270 = F_109 ( V_276 ) ;
V_270 = ( V_270 & ~ ( V_277 | V_278 ) ) | V_279 ;
F_110 ( V_276 , V_270 ) ;
F_111 () ;
V_271 = F_112 () | V_280 ;
while ( V_191 ) {
V_58 () ;
F_113 ( V_271 ) ;
F_114 () ;
}
F_84 () ;
F_107 ( V_273 , 0x3f ) ;
F_25 ( V_134 , NULL , 0 , 0 ) ;
return 0 ;
}
static void
F_77 ( unsigned char * V_149 , int V_188 )
{
struct V_281 * V_282 ;
struct V_283 * V_170 ;
int V_71 ;
unsigned long V_64 ;
if ( V_188 > sizeof( V_282 -> V_284 [ 0 ] . V_149 ) )
V_188 = sizeof( V_282 -> V_284 [ 0 ] . V_149 ) ;
F_60 ( & V_285 , V_64 ) ;
for ( V_170 = & V_286 ; ( V_170 = V_170 -> V_172 ) != & V_286 ; ) {
V_282 = F_115 ( V_170 , struct V_281 , V_170 ) ;
F_116 ( & V_282 -> V_287 ) ;
V_71 = V_282 -> V_288 + 1 ;
if ( V_71 >= V_289 )
V_71 = 0 ;
if ( V_71 != V_282 -> V_290 ) {
struct V_291 * V_292 = & V_282 -> V_284 [ V_282 -> V_288 ] ;
V_292 -> V_188 = V_188 ;
memcpy ( V_292 -> V_149 , V_149 , V_188 ) ;
V_282 -> V_288 = V_71 ;
F_117 ( & V_282 -> V_293 ) ;
}
F_118 ( & V_282 -> V_287 ) ;
}
F_62 ( & V_285 , V_64 ) ;
}
static int
F_119 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_281 * V_282 ;
unsigned long V_64 ;
V_282 = F_120 ( sizeof( struct V_281 ) , V_294 ) ;
if ( V_282 == 0 )
return - V_274 ;
V_282 -> V_290 = V_282 -> V_288 = 0 ;
F_6 ( & V_282 -> V_287 ) ;
F_121 ( & V_282 -> V_293 ) ;
F_122 ( & V_295 ) ;
F_60 ( & V_285 , V_64 ) ;
#if F_51 ( V_296 ) && F_51 ( F_21 )
V_282 -> V_297 = 0 ;
#endif
F_123 ( & V_282 -> V_170 , & V_286 ) ;
F_62 ( & V_285 , V_64 ) ;
V_128 -> V_298 = V_282 ;
F_124 ( & V_295 ) ;
return 0 ;
}
static T_4
F_125 ( struct V_128 * V_128 , char T_5 * V_299 ,
T_6 V_137 , T_7 * V_300 )
{
struct V_281 * V_282 = V_128 -> V_298 ;
F_126 ( V_293 , V_254 ) ;
unsigned long V_64 ;
int V_147 = 0 ;
if ( V_137 < 1 || V_282 == 0 )
return - V_143 ;
if ( ! F_127 ( V_301 , V_299 , V_137 ) )
return - V_144 ;
F_60 ( & V_282 -> V_287 , V_64 ) ;
F_128 ( & V_282 -> V_293 , & V_293 ) ;
F_129 ( V_302 ) ;
for (; ; ) {
V_147 = - V_260 ;
if ( V_282 -> V_290 != V_282 -> V_288 ) {
int V_71 = V_282 -> V_290 ;
struct V_291 * V_292 = & V_282 -> V_284 [ V_71 ] ;
V_147 = V_292 -> V_188 ;
F_62 ( & V_282 -> V_287 , V_64 ) ;
if ( V_147 > V_137 )
V_147 = V_137 ;
if ( V_147 > 0 && F_130 ( V_299 , V_292 -> V_149 , V_147 ) )
V_147 = - V_144 ;
if ( ++ V_71 >= V_289 )
V_71 = 0 ;
F_60 ( & V_282 -> V_287 , V_64 ) ;
V_282 -> V_290 = V_71 ;
}
if ( V_147 >= 0 )
break;
if ( V_128 -> V_303 & V_304 )
break;
V_147 = - V_305 ;
if ( F_131 ( V_254 ) )
break;
F_62 ( & V_282 -> V_287 , V_64 ) ;
F_132 () ;
F_60 ( & V_282 -> V_287 , V_64 ) ;
}
F_133 ( V_306 ) ;
F_134 ( & V_282 -> V_293 , & V_293 ) ;
F_62 ( & V_282 -> V_287 , V_64 ) ;
return V_147 ;
}
static T_4
F_135 ( struct V_128 * V_128 , const char T_5 * V_299 ,
T_6 V_137 , T_7 * V_300 )
{
return 0 ;
}
static unsigned int
F_136 ( struct V_128 * V_307 , T_11 * V_293 )
{
struct V_281 * V_282 = V_307 -> V_298 ;
unsigned int V_308 = 0 ;
unsigned long V_64 ;
if ( V_282 == 0 )
return 0 ;
F_137 ( V_307 , & V_282 -> V_293 , V_293 ) ;
F_60 ( & V_282 -> V_287 , V_64 ) ;
if ( V_282 -> V_290 != V_282 -> V_288 )
V_308 |= V_309 ;
F_62 ( & V_282 -> V_287 , V_64 ) ;
return V_308 ;
}
static int
F_138 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_281 * V_282 = V_128 -> V_298 ;
unsigned long V_64 ;
if ( V_282 != 0 ) {
V_128 -> V_298 = NULL ;
F_60 ( & V_285 , V_64 ) ;
F_139 ( & V_282 -> V_170 ) ;
F_62 ( & V_285 , V_64 ) ;
#if F_51 ( V_296 ) && F_51 ( F_21 )
if ( V_282 -> V_297 )
F_140 () ;
#endif
F_141 ( V_282 ) ;
}
return 0 ;
}
static void F_142 ( void )
{
F_143 () ;
F_144 () ;
}
static int F_145 ( T_12 V_310 )
{
int error = 0 ;
while ( ! V_44 . V_45 )
F_19 () ;
F_146 () ;
#ifdef F_147
if ( F_148 ( V_311 ) )
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
return - V_259 ;
}
if ( error )
return error ;
F_94 ( 100 ) ;
return 0 ;
}
static void F_150 ( void )
{
V_90 = 1 ;
V_47 ( 0 , NULL ) ;
F_94 ( 10 ) ;
F_151 () ;
F_152 () ;
}
static int F_153 ( T_12 V_310 )
{
return V_310 == V_312
&& ( F_25 ( V_134 , NULL , 0 , - 1 ) >= 0 ) ;
}
static int F_154 ( void )
{
if ( V_17 == V_18 )
F_105 () ;
V_313 . V_314 = F_142 ;
V_313 . V_315 = F_150 ;
F_155 ( & V_316 ) ;
return 0 ;
}
static int F_156 ( struct V_128 * V_307 ,
T_13 V_317 , T_14 V_212 )
{
T_15 T_5 * V_318 = ( T_15 T_5 * ) V_212 ;
int error = - V_143 ;
switch ( V_317 ) {
case V_319 :
if ( ! F_157 ( V_320 ) )
return - V_321 ;
return F_158 ( V_312 ) ;
case V_322 :
if ( F_25 ( V_134 , NULL , 0 , - 1 ) < 0 )
return F_159 ( 0 , V_318 ) ;
else
return F_159 ( 1 , V_318 ) ;
#ifdef F_160
case V_323 :
{
int V_324 ;
V_324 = F_161 () ;
if ( V_324 < 0 )
return V_324 ;
else
return F_159 ( V_324 , V_318 ) ;
}
case V_325 :
{
int V_324 ;
error = F_162 ( V_324 , V_318 ) ;
if ( error )
return error ;
return F_163 ( V_324 ) ;
}
#ifdef V_296
case V_326 : {
struct V_281 * V_282 = V_307 -> V_298 ;
if ( V_282 -> V_297 )
return 0 ;
V_282 -> V_297 = 1 ;
F_164 () ;
return 0 ;
}
#endif
#endif
case V_327 :
return F_159 ( V_17 , V_318 ) ;
case V_328 :
return F_159 ( V_9 , V_318 ) ;
}
return error ;
}
static long F_165 ( struct V_128 * V_307 ,
T_13 V_317 , T_14 V_212 )
{
int V_147 ;
F_122 ( & V_295 ) ;
V_147 = F_156 ( V_307 , V_317 , V_212 ) ;
F_124 ( & V_295 ) ;
return V_147 ;
}
static long F_166 ( struct V_128 * V_307 , T_13 V_317 , T_14 V_212 )
{
switch ( V_317 ) {
case V_319 :
break;
case V_329 :
V_317 = V_323 ;
break;
case V_330 :
V_317 = V_325 ;
break;
case V_331 :
V_317 = V_327 ;
break;
case V_332 :
V_317 = V_328 ;
break;
case V_333 :
V_317 = V_322 ;
break;
case V_334 :
V_317 = V_326 ;
break;
default:
return - V_335 ;
}
return F_165 ( V_307 , V_317 , ( unsigned long ) F_167 ( V_212 ) ) ;
}
static int F_168 ( void )
{
if ( ! V_3 )
return 0 ;
if ( F_169 ( & V_336 ) < 0 )
F_4 ( V_5 L_78 ) ;
return 0 ;
}
static inline void
F_170 ( volatile unsigned char T_9 * V_3 )
{
V_3 [ V_84 ] &= ~ V_85 ; F_171 () ;
while ( ( V_3 [ V_84 ] & V_87 ) != 0 )
;
V_3 [ V_84 ] |= V_85 ; F_171 () ;
while ( ( V_3 [ V_84 ] & V_87 ) == 0 )
;
}
static inline void
F_172 ( volatile unsigned char T_9 * V_3 , int V_176 )
{
V_3 [ V_177 ] |= V_178 | V_179 ; F_171 () ;
V_3 [ V_180 ] = V_176 ; F_171 () ;
F_170 ( V_3 ) ;
}
static inline int
F_173 ( volatile unsigned char T_9 * V_3 )
{
int V_176 ;
V_3 [ V_177 ] = ( V_3 [ V_177 ] & ~ V_178 ) | V_179 ; F_171 () ;
V_176 = V_3 [ V_180 ] ; F_171 () ;
F_170 ( V_3 ) ;
V_176 = V_3 [ V_180 ] ; F_171 () ;
return V_176 ;
}
int
F_174 ( struct V_82 * V_83 )
{
unsigned long V_64 ;
int V_71 , V_337 , V_338 ;
volatile unsigned char T_9 * V_126 = V_3 ;
V_83 -> V_45 = 1 ;
V_338 = V_83 -> V_149 [ 0 ] ;
V_337 = V_152 [ V_338 ] [ 0 ] ;
if ( V_337 >= 0 && V_83 -> V_151 != V_337 + 1 )
return - V_143 ;
F_175 ( V_64 ) ;
while ( V_33 != V_34 )
F_19 () ;
while ( ( V_3 [ V_84 ] & V_87 ) == 0 )
;
F_172 ( V_126 , V_338 ) ;
if ( V_337 < 0 ) {
V_337 = V_83 -> V_151 - 1 ;
F_172 ( V_126 , V_337 ) ;
}
for ( V_71 = 1 ; V_71 <= V_337 ; ++ V_71 )
F_172 ( V_126 , V_83 -> V_149 [ V_71 ] ) ;
V_337 = V_152 [ V_338 ] [ 1 ] ;
if ( V_337 < 0 )
V_337 = F_173 ( V_126 ) ;
for ( V_71 = 0 ; V_71 < V_337 ; ++ V_71 )
V_83 -> V_94 [ V_71 + V_83 -> V_93 ] = F_173 ( V_126 ) ;
if ( V_83 -> V_167 )
(* V_83 -> V_167 )( V_83 ) ;
F_176 ( V_64 ) ;
return 0 ;
}
void F_177 ( int V_339 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
for (; V_339 > 0 ; -- V_339 ) {
V_83 . V_151 = 4 ;
V_83 . V_167 = NULL ;
V_83 . V_149 [ 0 ] = 0xee ;
V_83 . V_149 [ 1 ] = 4 ;
V_83 . V_149 [ 2 ] = 0 ;
V_83 . V_149 [ 3 ] = 1 ;
V_83 . V_94 [ 0 ] = V_153 ;
V_83 . V_93 = 1 ;
V_83 . V_162 = 0 ;
F_174 ( & V_83 ) ;
F_94 ( 50 ) ;
V_83 . V_151 = 4 ;
V_83 . V_167 = NULL ;
V_83 . V_149 [ 0 ] = 0xee ;
V_83 . V_149 [ 1 ] = 4 ;
V_83 . V_149 [ 2 ] = 0 ;
V_83 . V_149 [ 3 ] = 0 ;
V_83 . V_94 [ 0 ] = V_153 ;
V_83 . V_93 = 1 ;
V_83 . V_162 = 0 ;
F_174 ( & V_83 ) ;
F_94 ( 50 ) ;
}
F_94 ( 50 ) ;
}
static int F_178 ( void )
{
F_69 () ;
V_340 = 1 ;
#ifdef F_21
F_179 ( 1 ) ;
#endif
return 0 ;
}
static void F_180 ( void )
{
struct V_82 V_83 ;
if ( ! V_340 )
return;
F_29 ( & V_83 , NULL , 2 , V_91 , 2 ) ;
F_31 ( & V_83 ) ;
#ifdef F_21
F_179 ( 0 ) ;
#endif
F_71 () ;
V_340 = 0 ;
}
static int F_181 ( void )
{
F_182 ( & V_341 ) ;
return 0 ;
}
