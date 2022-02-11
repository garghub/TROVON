static T_1
F_1 ( const char * V_1 , int V_2 )
{
T_1 V_3 ;
char * V_4 ;
V_3 = ( T_1 ) strtoul ( V_1 , & V_4 , V_2 ? V_5 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_6 , L_1 , V_1 ) ;
exit ( - 1 ) ;
}
return V_3 ;
}
static void
F_2 ( const char * V_1 )
{
T_1 V_3 ;
V_3 = F_1 ( V_1 , FALSE ) ;
V_7 [ V_8 ] = ( V_9 ) V_3 ;
V_8 ++ ;
if ( V_8 - V_10 >= V_11 )
F_3 ( TRUE ) ;
}
static void
F_4 ( const char V_12 [] , T_1 V_13 )
{
T_1 V_14 ;
if ( V_8 + V_13 < V_15 ) {
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
V_7 [ V_8 ] = V_12 [ V_14 ] ;
V_8 ++ ;
}
}
}
static void
F_5 ( T_1 V_13 )
{
V_8 -= V_13 ;
}
static T_2
F_6 ( void * V_16 , T_1 V_17 )
{
T_1 V_18 = 0 ;
T_2 * V_19 = ( T_2 * ) V_16 ;
while ( V_17 > 1 ) {
V_18 += F_7 ( * ( T_2 * ) V_19 ) ;
V_19 ++ ;
V_17 -= 2 ;
}
if ( V_17 > 0 )
V_18 += F_7 ( * ( V_9 * ) V_19 ) ;
while ( V_18 >> 16 )
V_18 = ( V_18 & 0xffff ) + ( V_18 >> 16 ) ;
V_18 = ~ V_18 ;
return F_8 ( V_18 ) ;
}
static T_1
F_9 ( const V_9 * V_16 , unsigned int V_20 , T_1 V_21 )
{
unsigned int V_14 ;
T_1 V_22 ;
V_22 = V_21 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ )
F_10 ( V_22 , V_16 [ V_14 ] ) ;
return ( V_22 ) ;
}
static T_1
F_11 ( T_1 V_22 )
{
T_1 V_23 ;
V_9 V_24 , V_25 , V_26 , V_27 ;
V_23 = ~ V_22 ;
V_24 = V_23 & 0xff ;
V_25 = ( V_23 >> 8 ) & 0xff ;
V_26 = ( V_23 >> 16 ) & 0xff ;
V_27 = ( V_23 >> 24 ) & 0xff ;
V_23 = ( ( V_24 << 24 ) | ( V_25 << 16 ) | ( V_26 << 8 ) | V_27 ) ;
return ( V_23 ) ;
}
static T_2
F_12 ( T_1 V_28 )
{
T_2 V_29 ;
V_29 = V_28 % 4 ;
if ( V_29 == 0 )
return 0 ;
else
return 4 - V_29 ;
}
static void
F_13 ( T_3 V_30 )
{
T_1 V_28 = 0 ;
T_2 V_31 = 0 ;
int V_32 ;
T_2 V_33 ;
T_3 V_34 ;
if ( V_8 > V_10 ) {
if( V_35 ) {
V_36 = 0x86DD ;
V_37 = FALSE ;
}
V_28 = V_8 ;
if ( V_38 ) {
V_31 = F_12 ( V_28 - V_10 ) ;
} else {
V_31 = 0 ;
}
V_8 = 0 ;
if ( V_39 ) {
V_40 . V_41 = F_8 ( V_36 ) ;
F_4 ( ( const char * ) & V_40 , sizeof( V_40 ) ) ;
}
if ( V_37 ) {
if( V_42 ) V_43 . V_44 = V_42 ;
if( V_45 ) V_43 . V_46 = V_45 ;
V_43 . V_47 = F_8 ( V_28 - V_48 + V_31 ) ;
V_43 . V_49 = ( V_9 ) V_50 ;
V_43 . V_51 = 0 ;
V_43 . V_51 = F_6 ( & V_43 , sizeof( V_43 ) ) ;
F_4 ( ( const char * ) & V_43 , sizeof( V_43 ) ) ;
} else if ( V_35 ) {
if( memcmp ( V_52 , V_53 , sizeof( struct V_54 ) ) )
memcpy ( & V_55 . V_56 , & V_52 , sizeof( struct V_54 ) ) ;
if( memcmp ( V_57 , V_53 , sizeof( struct V_54 ) ) )
memcpy ( & V_55 . V_58 , & V_57 , sizeof( struct V_54 ) ) ;
V_55 . V_59 . V_60 &= 0x0F ;
V_55 . V_59 . V_60 |= ( 6 << 4 ) ;
V_55 . V_59 . V_61 . V_62 = F_8 ( V_28 - V_48 + V_31 ) ;
V_55 . V_59 . V_61 . V_63 = ( V_9 ) V_50 ;
V_55 . V_59 . V_61 . V_64 = 32 ;
F_4 ( ( const char * ) & V_55 , sizeof( V_55 ) ) ;
V_65 . V_66 = V_55 . V_56 ;
V_65 . V_67 = V_55 . V_58 ;
V_65 . V_68 = 0 ;
V_65 . V_49 = ( V_9 ) V_50 ;
V_33 = F_7 ( V_55 . V_59 . V_61 . V_62 ) ;
V_69 . V_28 = F_8 ( V_28 - V_33 + sizeof( V_70 ) ) ;
}
if( ! V_35 ) {
V_69 . V_44 = V_43 . V_44 ;
V_69 . V_46 = V_43 . V_46 ;
V_69 . V_68 = 0 ;
V_69 . V_49 = ( V_9 ) V_50 ;
V_69 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_70 ) ) ;
}
if ( V_71 ) {
T_2 V_72 ;
T_1 V_73 ;
V_70 . V_74 = F_8 ( V_75 ) ;
V_70 . V_76 = F_8 ( V_77 ) ;
V_70 . V_28 = V_69 . V_28 ;
V_70 . V_78 = 0 ;
V_72 = V_35 ? F_6 ( & V_65 , sizeof( V_65 ) ) : F_6 ( & V_69 , sizeof( V_69 ) ) ;
V_73 = F_7 ( V_72 ) ;
V_72 = F_6 ( & V_70 , sizeof( V_70 ) ) ;
V_73 += F_7 ( V_72 ) ;
V_72 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_73 += F_7 ( V_72 ) ;
V_72 = ( V_73 & 0xffff ) + ( V_73 >> 16 ) ;
V_70 . V_78 = F_8 ( V_72 ) ;
if ( V_70 . V_78 == 0 )
V_70 . V_78 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_70 , sizeof( V_70 ) ) ;
}
if ( V_79 ) {
T_2 V_72 ;
T_1 V_73 ;
V_69 . V_44 = V_43 . V_44 ;
V_69 . V_46 = V_43 . V_46 ;
V_69 . V_68 = 0 ;
V_69 . V_49 = ( V_9 ) V_50 ;
V_69 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_80 ) ) ;
V_80 . V_74 = F_8 ( V_75 ) ;
V_80 . V_76 = F_8 ( V_77 ) ;
V_80 . V_81 = F_8 ( 0x2000 ) ;
V_80 . V_78 = 0 ;
V_72 = F_6 ( & V_69 , sizeof( V_69 ) ) ;
V_73 = F_7 ( V_72 ) ;
V_72 = F_6 ( & V_80 , sizeof( V_80 ) ) ;
V_73 += F_7 ( V_72 ) ;
V_72 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_73 += F_7 ( V_72 ) ;
V_72 = ( V_73 & 0xffff ) + ( V_73 >> 16 ) ;
V_80 . V_78 = F_8 ( V_72 ) ;
if ( V_80 . V_78 == 0 )
V_80 . V_78 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_80 , sizeof( V_80 ) ) ;
V_80 . V_82 = F_14 ( V_80 . V_82 ) + V_28 - V_10 ;
V_80 . V_82 = F_15 ( V_80 . V_82 ) ;
}
if ( V_83 ) {
V_84 = 0 ;
if ( V_85 == 0 ) {
V_84 |= 0x02 ;
}
if ( ! V_30 ) {
V_84 |= 0x01 ;
}
V_86 . type = V_87 ;
V_86 . V_88 = V_84 ;
V_86 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_86 ) ) ;
V_86 . V_89 = F_15 ( V_90 ) ;
V_86 . V_91 = F_8 ( V_92 ) ;
V_86 . V_93 = F_8 ( V_94 ) ;
V_86 . V_95 = F_15 ( V_96 ) ;
V_90 ++ ;
if ( ! V_30 ) {
V_94 ++ ;
}
}
if ( V_38 ) {
T_1 V_68 = 0 ;
V_97 . V_98 = F_8 ( V_99 ) ;
V_97 . V_76 = F_8 ( V_100 ) ;
V_97 . V_101 = F_15 ( V_102 ) ;
V_97 . V_78 = F_15 ( 0 ) ;
V_97 . V_78 = F_9 ( ( V_9 * ) & V_97 , sizeof( V_97 ) , ~ 0L ) ;
if ( V_83 ) {
V_97 . V_78 = F_9 ( ( V_9 * ) & V_86 , sizeof( V_86 ) , V_97 . V_78 ) ;
V_97 . V_78 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_97 . V_78 ) ;
V_97 . V_78 = F_9 ( ( V_9 * ) & V_68 , V_31 , V_97 . V_78 ) ;
} else {
V_97 . V_78 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_97 . V_78 ) ;
}
V_97 . V_78 = F_11 ( V_97 . V_78 ) ;
V_97 . V_78 = F_15 ( V_97 . V_78 ) ;
F_4 ( ( const char * ) & V_97 , sizeof( V_97 ) ) ;
}
if ( V_83 ) {
F_4 ( ( const char * ) & V_86 , sizeof( V_86 ) ) ;
}
V_8 = V_28 ;
if ( V_83 && ( V_31 > 0 ) ) {
memset ( V_103 , 0 , V_31 ) ;
F_4 ( ( const char * ) & V_103 , V_31 ) ;
V_28 += V_31 ;
}
if ( V_39 && ( V_28 < 60 ) ) {
memset ( V_103 , 0 , 60 - V_28 ) ;
F_4 ( ( const char * ) & V_103 , 60 - V_28 ) ;
V_28 = 60 ;
}
if ( V_104 ) {
V_34 = F_16 ( V_105 ,
NULL ,
V_106 , V_107 ,
V_28 , V_28 ,
0 ,
1000000 ,
V_7 , V_108 ,
& V_109 , & V_32 ) ;
} else {
V_34 = F_17 ( V_105 ,
V_106 , V_107 ,
V_28 , V_28 ,
V_7 ,
& V_109 , & V_32 ) ;
}
if ( ! V_34 ) {
fprintf ( V_6 , L_2 ,
V_110 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
if ( V_111 == NULL ) {
V_107 ++ ;
}
if ( ! V_112 ) {
fprintf ( V_6 , L_3 , V_28 ) ;
}
V_113 ++ ;
}
V_85 += V_8 - V_10 ;
V_8 = V_10 ;
return;
}
static void
F_19 ( void )
{
int V_32 ;
T_3 V_34 ;
if ( V_104 ) {
#ifdef F_20
const char * V_114 = L_4 F_20 L_5 V_115 L_6 ;
#else
const char * V_114 = L_7 ;
#endif
char V_116 [ 100 ] ;
F_21 ( V_116 , sizeof( V_116 ) , L_8 , V_117 ) ;
V_34 = F_22 ( V_105 ,
V_116 ,
NULL ,
NULL ,
V_114 ,
- 1 ,
& V_109 ,
& V_32 ) ;
if ( V_34 ) {
V_34 = F_23 ( V_105 ,
NULL ,
NULL ,
NULL ,
L_9 ,
NULL ,
V_118 ,
V_119 ,
& V_109 ,
0 ,
6 ,
& V_32 ) ;
}
} else {
V_34 = F_24 ( V_105 , V_118 , V_119 ,
FALSE , & V_109 , & V_32 ) ;
}
if ( ! V_34 ) {
fprintf ( V_6 , L_2 ,
V_110 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
}
static void
F_25 ( void )
{
int V_32 ;
T_3 V_34 ;
if ( V_104 ) {
V_34 = F_26 ( V_105 ,
0 ,
& V_109 ,
L_10 ,
0 ,
0 ,
V_113 ,
V_113 - V_113 ,
& V_32 ) ;
} else {
V_34 = TRUE ;
}
if ( ! V_34 ) {
fprintf ( V_6 , L_2 ,
V_110 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
return;
}
static void
F_27 ( char * V_1 )
{
T_4 V_120 ;
if ( V_121 != 0 ) {
if ( V_121 == V_122 )
return;
V_123 [ V_121 ++ ] = ' ' ;
}
V_120 = strlen ( V_1 ) ;
if ( V_120 != 0 ) {
if ( V_121 + V_120 > V_122 )
return;
F_28 ( & V_123 [ V_121 ] , V_1 , V_122 ) ;
V_121 += ( int ) V_120 ;
if ( V_124 >= 2 ) {
char * V_4 ;
char V_125 [ V_122 ] ;
F_28 ( V_125 , V_123 , V_122 ) ;
while ( ( V_4 = strchr ( V_125 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_11 , V_125 ) ;
}
}
}
static void
F_29 ( void )
{
struct V_126 V_127 ;
char * V_128 ;
char * V_129 ;
int V_130 ;
int V_14 ;
V_123 [ V_121 ] = '\0' ;
if ( V_124 > 0 )
fprintf ( V_6 , L_12 , V_123 ) ;
if ( V_131 ) {
switch ( V_123 [ 0 ] ) {
case 'i' :
case 'I' :
V_108 = 0x00000001 ;
V_123 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_108 = 0x00000002 ;
V_123 [ 0 ] = ' ' ;
break;
default:
V_108 = 0x00000000 ;
break;
}
V_14 = 0 ;
while ( V_123 [ V_14 ] == ' ' ||
V_123 [ V_14 ] == '\r' ||
V_123 [ V_14 ] == '\t' ) {
V_14 ++ ;
}
V_121 -= V_14 ;
memmove ( V_123 , V_123 + V_14 , V_121 + 1 ) ;
}
if ( V_111 == NULL ) {
V_121 = 0 ;
return;
}
V_127 = V_132 ;
V_107 = 0 ;
if ( strlen ( V_123 ) > 2 ) {
V_128 = strptime ( V_123 , V_111 , & V_127 ) ;
if ( V_128 != NULL ) {
V_106 = mktime ( & V_127 ) ;
} else
V_106 = - 1 ;
if ( - 1 == V_106 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_123 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_13 ,
V_123 , V_111 ) ;
if ( V_124 >= 2 ) {
fprintf ( V_6 , L_14 ,
V_127 . V_133 , V_127 . V_134 , V_127 . V_135 ,
V_127 . V_136 , V_127 . V_137 , V_127 . V_138 , V_127 . V_139 ) ;
}
V_106 = 0 ;
V_107 = 0 ;
} else {
V_107 = ( T_1 ) strtol ( V_128 , & V_129 , 10 ) ;
if ( V_128 == V_129 ) {
V_107 = 0 ;
} else {
V_130 = ( int ) ( V_129 - V_128 ) ;
if ( V_130 > 6 ) {
for ( V_14 = V_130 - 6 ; V_14 != 0 ; V_14 -- )
V_107 /= 10 ;
} else if ( V_130 < 6 ) {
for ( V_14 = 6 - V_130 ; V_14 != 0 ; V_14 -- )
V_107 *= 10 ;
}
}
}
}
if ( V_124 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_123 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_12 , V_123 ) ;
fprintf ( V_6 , L_15 , V_111 , ( T_1 ) V_106 , V_107 ) ;
}
V_121 = 0 ;
}
static void
F_3 ( T_3 V_30 )
{
if ( V_124 >= 1 )
fprintf ( V_6 , L_16 , V_30 ? L_17 : L_18 ) ;
F_13 ( V_30 ) ;
V_140 ++ ;
F_29 () ;
}
static void
F_30 ( char * V_1 )
{
fprintf ( V_6 , L_19 , V_1 + 10 ) ;
}
void
F_31 ( T_5 V_141 , char * V_1 )
{
T_1 V_3 ;
int V_142 ;
int V_143 = 0 ;
int V_144 ;
int V_14 ;
char * V_145 ;
char V_146 [ 3 ] ;
if ( V_124 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_20 ,
V_147 [ V_148 ] , V_149 [ V_141 ] , V_1 ? V_1 : L_9 ) ;
}
switch( V_148 ) {
case V_150 :
switch( V_141 ) {
case V_151 :
F_27 ( V_1 ) ;
break;
case V_152 :
F_30 ( V_1 ) ;
break;
case V_153 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_148 = V_154 ;
V_155 = V_7 + V_3 ;
}
break;
case V_156 :
V_148 = V_157 ;
break;
default:
break;
}
break;
case V_157 :
switch( V_141 ) {
case V_151 :
F_27 ( V_1 ) ;
break;
case V_152 :
F_30 ( V_1 ) ;
break;
case V_153 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_85 = 0 ;
V_148 = V_154 ;
} else if ( ( V_3 - V_85 ) != V_8 - V_10 ) {
if ( V_3 < V_8 ) {
F_5 ( V_8 - V_3 ) ;
V_148 = V_154 ;
} else {
if ( V_124 >= 1 )
fprintf ( V_6 , L_21 ,
V_8 , V_3 ) ;
F_13 ( FALSE ) ;
V_148 = V_150 ;
}
} else
V_148 = V_154 ;
V_155 = V_7 + V_3 ;
break;
case V_156 :
V_148 = V_157 ;
break;
default:
break;
}
break;
case V_154 :
switch( V_141 ) {
case V_158 :
V_148 = V_159 ;
F_2 ( V_1 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
V_148 = V_160 ;
break;
case V_156 :
V_148 = V_157 ;
break;
default:
break;
}
break;
case V_159 :
switch( V_141 ) {
case V_158 :
F_2 ( V_1 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_156 :
V_142 = 0 ;
V_148 = V_160 ;
if ( V_141 == V_156 ) {
V_142 = 1 ;
V_148 = V_157 ;
}
if ( V_161 ) {
V_143 = 0 ;
V_144 = V_8 - ( int ) ( V_155 - V_7 ) ;
V_145 = ( char * ) F_32 ( ( V_144 + 1 ) / 4 + 1 ) ;
for ( V_14 = 0 ; V_14 < ( V_144 + 1 ) / 4 ; V_14 ++ ) {
V_146 [ 0 ] = V_155 [ V_14 * 3 ] ;
V_146 [ 1 ] = V_155 [ V_14 * 3 + 1 ] ;
V_146 [ 2 ] = '\0' ;
if ( ! isxdigit ( V_146 [ 0 ] ) || ! isxdigit ( V_146 [ 0 ] ) ) {
break;
}
V_145 [ V_14 ] = ( char ) strtoul ( V_146 , ( char * * ) NULL , 16 ) ;
V_143 ++ ;
if ( ! ( V_155 [ V_14 * 3 + 2 ] == ' ' ) ) {
if ( V_142 != 1 )
V_143 -- ;
break;
}
}
if ( V_143 > 0 ) {
if ( strncmp ( V_155 + V_144 - V_143 , V_145 , V_143 ) == 0 ) {
F_5 ( V_143 ) ;
}
else {
F_5 ( V_144 ) ;
}
}
F_33 ( V_145 ) ;
}
break;
default:
break;
}
break;
case V_160 :
switch( V_141 ) {
case V_156 :
V_148 = V_157 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_22 , V_148 ) ;
exit ( - 1 ) ;
}
if ( V_124 >= 2 )
fprintf ( V_6 , L_23 , V_147 [ V_148 ] ) ;
}
static void
F_34 ( void )
{
fprintf ( V_6 ,
L_24
#ifdef F_20
L_25 F_20 L_5 V_115 L_6
#endif
L_26
L_27
L_28
L_26
L_29
L_26
L_30
L_31
L_26
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_26
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_26
L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72
L_73
L_71
L_74
L_75
L_76
L_77
L_78
L_79
L_80
L_76
L_77
L_81
L_82
L_83
L_77
L_84
L_85
L_86
L_87
L_88
L_89
L_26
L_90
L_91
L_92
L_93
L_94
L_9 ,
V_162 , V_15 ) ;
exit ( - 1 ) ;
}
static void
F_35 ( int V_163 , char * V_164 [] )
{
int V_4 ;
char * V_129 ;
#ifdef F_36
F_37 ( V_163 , V_164 ) ;
F_38 () ;
#endif
while ( ( V_4 = F_39 ( V_163 , V_164 , L_95 ) ) != - 1 ) {
switch( V_4 ) {
case '?' : F_34 () ; break;
case 'h' : F_34 () ; break;
case 'd' : if ( ! V_112 ) V_124 ++ ; break;
case 'D' : V_131 = TRUE ; break;
case 'q' : V_112 = TRUE ; V_124 = FALSE ; break;
case 'l' : V_118 = ( T_1 ) strtol ( V_165 , NULL , 0 ) ; break;
case 'm' : V_11 = ( T_1 ) strtol ( V_165 , NULL , 0 ) ; break;
case 'n' : V_104 = TRUE ; break;
case 'o' :
if ( V_165 [ 0 ] != 'h' && V_165 [ 0 ] != 'o' && V_165 [ 0 ] != 'd' ) {
fprintf ( V_6 , L_96 , V_165 ) ;
F_34 () ;
}
switch( V_165 [ 0 ] ) {
case 'o' : V_5 = 8 ; break;
case 'h' : V_5 = 16 ; break;
case 'd' : V_5 = 10 ; break;
}
break;
case 'e' :
V_39 = TRUE ;
if ( sscanf ( V_165 , L_97 , & V_36 ) < 1 ) {
fprintf ( V_6 , L_98 , V_165 ) ;
F_34 () ;
}
break;
case 'i' :
V_37 = TRUE ;
V_50 = strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || * V_129 != '\0' || V_50 < 0 ||
V_50 > 255 ) {
fprintf ( V_6 , L_99 , V_165 ) ;
F_34 () ;
}
V_39 = TRUE ;
V_36 = 0x800 ;
break;
case 's' :
V_38 = TRUE ;
V_83 = FALSE ;
V_79 = FALSE ;
V_71 = FALSE ;
V_99 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_100 , V_4 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_101 , V_4 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_100 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_102 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_103 , V_4 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_102 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || * V_129 != '\0' ) {
fprintf ( V_6 , L_104 , V_4 ) ;
F_34 () ;
}
V_37 = TRUE ;
V_50 = 132 ;
V_39 = TRUE ;
V_36 = 0x800 ;
break;
case 'S' :
V_38 = TRUE ;
V_83 = TRUE ;
V_79 = FALSE ;
V_71 = FALSE ;
V_99 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_100 , V_4 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_101 , V_4 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_100 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_102 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_105 , V_4 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_96 = ( T_1 ) strtoul ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || * V_129 != '\0' ) {
fprintf ( V_6 , L_106 , V_4 ) ;
F_34 () ;
}
V_37 = TRUE ;
V_50 = 132 ;
V_39 = TRUE ;
V_36 = 0x800 ;
break;
case 't' :
V_111 = V_165 ;
break;
case 'u' :
V_71 = TRUE ;
V_79 = FALSE ;
V_38 = FALSE ;
V_83 = FALSE ;
V_75 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_107 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_108 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_77 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || * V_129 != '\0' ) {
fprintf ( V_6 , L_109 ) ;
F_34 () ;
}
V_37 = TRUE ;
V_50 = 17 ;
V_39 = TRUE ;
V_36 = 0x800 ;
break;
case 'T' :
V_79 = TRUE ;
V_71 = FALSE ;
V_38 = FALSE ;
V_83 = FALSE ;
V_75 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || ( * V_129 != ',' && * V_129 != '\0' ) ) {
fprintf ( V_6 , L_110 ) ;
F_34 () ;
}
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_108 ) ;
F_34 () ;
}
V_129 ++ ;
V_165 = V_129 ;
V_77 = ( T_1 ) strtol ( V_165 , & V_129 , 10 ) ;
if ( V_129 == V_165 || * V_129 != '\0' ) {
fprintf ( V_6 , L_111 ) ;
F_34 () ;
}
V_37 = TRUE ;
V_50 = 6 ;
V_39 = TRUE ;
V_36 = 0x800 ;
break;
case 'a' :
V_161 = TRUE ;
break;
case '4' :
case '6' :
V_129 = strchr ( V_165 , ',' ) ;
if ( ! V_129 ) {
fprintf ( V_6 , L_112 , V_4 ) ;
F_34 () ;
}
* V_129 = '\0' ;
if( V_4 == '6' )
{
V_35 = TRUE ;
V_36 = 0x86DD ;
}
else
{
V_37 = TRUE ;
V_36 = 0x800 ;
}
V_39 = TRUE ;
if ( V_35 == TRUE ) {
if( F_40 ( V_166 , V_165 , V_52 ) <= 0 ) {
fprintf ( V_6 , L_113 , V_4 , V_129 ) ;
F_34 () ;
}
} else {
if( F_40 ( V_167 , V_165 , & V_42 ) <= 0 ) {
fprintf ( V_6 , L_113 , V_4 , V_129 ) ;
F_34 () ;
}
}
V_129 ++ ;
if ( * V_129 == '\0' ) {
fprintf ( V_6 , L_114 , V_4 ) ;
F_34 () ;
}
if ( V_35 == TRUE ) {
if( F_40 ( V_166 , V_129 , V_57 ) <= 0 ) {
fprintf ( V_6 , L_115 , V_4 , V_129 ) ;
F_34 () ;
}
} else {
if( F_40 ( V_167 , V_129 , & V_45 ) <= 0 ) {
fprintf ( V_6 , L_115 , V_4 , V_129 ) ;
F_34 () ;
}
}
break;
default:
F_34 () ;
}
}
if ( V_168 >= V_163 || V_163 - V_168 < 2 ) {
fprintf ( V_6 , L_116 ) ;
F_34 () ;
}
if ( strcmp ( V_164 [ V_168 ] , L_117 ) ) {
V_117 = F_41 ( V_164 [ V_168 ] ) ;
V_169 = F_42 ( V_117 , L_118 ) ;
if ( ! V_169 ) {
fprintf ( V_6 , L_119 ,
V_117 , F_18 ( V_170 ) ) ;
exit ( - 1 ) ;
}
} else {
V_117 = L_120 ;
V_169 = V_171 ;
}
if ( strcmp ( V_164 [ V_168 + 1 ] , L_117 ) ) {
V_110 = F_41 ( V_164 [ V_168 + 1 ] ) ;
V_105 = F_42 ( V_110 , L_121 ) ;
if ( ! V_105 ) {
fprintf ( V_6 , L_122 ,
V_110 , F_18 ( V_170 ) ) ;
exit ( - 1 ) ;
}
} else {
V_110 = L_123 ;
V_105 = stdout ;
}
if ( V_118 != 1 && V_39 ) {
fprintf ( V_6 , L_124 ) ;
exit ( - 1 ) ;
}
if ( ! V_169 ) {
V_169 = V_171 ;
V_117 = L_120 ;
}
if ( ! V_105 ) {
V_105 = stdout ;
V_110 = L_123 ;
}
V_106 = time ( 0 ) ;
V_132 = * localtime ( & V_106 ) ;
V_132 . V_139 = - 1 ;
if ( ! V_112 ) {
fprintf ( V_6 , L_125 , V_117 ) ;
fprintf ( V_6 , L_126 , V_110 ) ;
fprintf ( V_6 , L_127 , V_104 ? L_128 : L_129 ) ;
if ( V_39 ) fprintf ( V_6 , L_130 ,
V_36 ) ;
if ( V_37 ) fprintf ( V_6 , L_131 ,
V_50 ) ;
if ( V_71 ) fprintf ( V_6 , L_132 ,
V_75 , V_77 ) ;
if ( V_79 ) fprintf ( V_6 , L_133 ,
V_75 , V_77 ) ;
if ( V_38 ) fprintf ( V_6 , L_134 ,
V_99 , V_100 , V_102 ) ;
if ( V_83 ) fprintf ( V_6 , L_135 ,
V_90 , V_92 , V_94 , V_96 ) ;
}
}
int
main ( int V_163 , char * V_164 [] )
{
F_35 ( V_163 , V_164 ) ;
assert ( V_169 != NULL ) ;
assert ( V_105 != NULL ) ;
F_19 () ;
V_10 = 0 ;
if ( V_39 ) {
V_10 += ( int ) sizeof( V_40 ) ;
}
if ( V_37 ) {
V_48 = V_10 ;
V_10 += ( int ) sizeof( V_43 ) ;
} else if ( V_35 ) {
V_48 = V_10 ;
V_10 += ( int ) sizeof( V_55 ) ;
}
if ( V_38 ) {
V_10 += ( int ) sizeof( V_97 ) ;
}
if ( V_83 ) {
V_10 += ( int ) sizeof( V_86 ) ;
}
if ( V_79 ) {
V_10 += ( int ) sizeof( V_80 ) ;
}
if ( V_71 ) {
V_10 += ( int ) sizeof( V_70 ) ;
}
V_8 = V_10 ;
V_172 = V_169 ;
F_43 () ;
F_13 ( FALSE ) ;
F_25 () ;
fclose ( V_169 ) ;
fclose ( V_105 ) ;
if ( V_124 )
fprintf ( V_6 , L_136 ) ;
if ( ! V_112 ) {
fprintf ( V_6 , L_137 V_173 L_138 ,
V_140 , ( V_140 == 1 ) ? L_9 : L_139 ,
V_113 , ( V_113 == 1 ) ? L_9 : L_139 ,
V_109 , ( V_109 == 1 ) ? L_9 : L_139 ) ;
}
return 0 ;
}
