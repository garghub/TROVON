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
T_3 V_33 ;
if ( V_8 > V_10 ) {
V_28 = V_8 ;
if ( V_34 ) {
V_31 = F_12 ( V_28 - V_10 ) ;
} else {
V_31 = 0 ;
}
V_8 = 0 ;
if ( V_35 ) {
V_36 . V_37 = F_8 ( V_38 ) ;
F_4 ( ( const char * ) & V_36 , sizeof( V_36 ) ) ;
}
if ( V_39 ) {
V_40 . V_41 = F_8 ( V_28 - V_42 + V_31 ) ;
V_40 . V_43 = ( V_9 ) V_44 ;
V_40 . V_45 = 0 ;
V_40 . V_45 = F_6 ( & V_40 , sizeof( V_40 ) ) ;
F_4 ( ( const char * ) & V_40 , sizeof( V_40 ) ) ;
}
if ( V_46 ) {
T_2 V_47 ;
T_1 V_48 ;
V_49 . V_50 = V_40 . V_50 ;
V_49 . V_51 = V_40 . V_51 ;
V_49 . V_52 = 0 ;
V_49 . V_43 = ( V_9 ) V_44 ;
V_49 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_53 ) ) ;
V_53 . V_54 = F_8 ( V_55 ) ;
V_53 . V_56 = F_8 ( V_57 ) ;
V_53 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_53 ) ) ;
V_53 . V_58 = 0 ;
V_47 = F_6 ( & V_49 , sizeof( V_49 ) ) ;
V_48 = F_7 ( V_47 ) ;
V_47 = F_6 ( & V_53 , sizeof( V_53 ) ) ;
V_48 += F_7 ( V_47 ) ;
V_47 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_48 += F_7 ( V_47 ) ;
V_47 = ( V_48 & 0xffff ) + ( V_48 >> 16 ) ;
V_53 . V_58 = F_8 ( V_47 ) ;
if ( V_53 . V_58 == 0 )
V_53 . V_58 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_53 , sizeof( V_53 ) ) ;
}
if ( V_59 ) {
T_2 V_47 ;
T_1 V_48 ;
V_49 . V_50 = V_40 . V_50 ;
V_49 . V_51 = V_40 . V_51 ;
V_49 . V_52 = 0 ;
V_49 . V_43 = ( V_9 ) V_44 ;
V_49 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_60 ) ) ;
V_60 . V_54 = F_8 ( V_55 ) ;
V_60 . V_56 = F_8 ( V_57 ) ;
V_60 . V_61 = F_8 ( 0x2000 ) ;
V_60 . V_58 = 0 ;
V_47 = F_6 ( & V_49 , sizeof( V_49 ) ) ;
V_48 = F_7 ( V_47 ) ;
V_47 = F_6 ( & V_60 , sizeof( V_60 ) ) ;
V_48 += F_7 ( V_47 ) ;
V_47 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_48 += F_7 ( V_47 ) ;
V_47 = ( V_48 & 0xffff ) + ( V_48 >> 16 ) ;
V_60 . V_58 = F_8 ( V_47 ) ;
if ( V_60 . V_58 == 0 )
V_60 . V_58 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_60 , sizeof( V_60 ) ) ;
V_60 . V_62 = F_14 ( V_60 . V_62 ) + V_28 - V_10 ;
V_60 . V_62 = F_15 ( V_60 . V_62 ) ;
}
if ( V_63 ) {
V_64 = 0 ;
if ( V_65 == 0 ) {
V_64 |= 0x02 ;
}
if ( ! V_30 ) {
V_64 |= 0x01 ;
}
V_66 . type = V_67 ;
V_66 . V_68 = V_64 ;
V_66 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_66 ) ) ;
V_66 . V_69 = F_15 ( V_70 ) ;
V_66 . V_71 = F_8 ( V_72 ) ;
V_66 . V_73 = F_8 ( V_74 ) ;
V_66 . V_75 = F_15 ( V_76 ) ;
V_70 ++ ;
if ( ! V_30 ) {
V_74 ++ ;
}
}
if ( V_34 ) {
T_1 V_52 = 0 ;
V_77 . V_78 = F_8 ( V_79 ) ;
V_77 . V_56 = F_8 ( V_80 ) ;
V_77 . V_81 = F_15 ( V_82 ) ;
V_77 . V_58 = F_15 ( 0 ) ;
V_77 . V_58 = F_9 ( ( V_9 * ) & V_77 , sizeof( V_77 ) , ~ 0L ) ;
if ( V_63 ) {
V_77 . V_58 = F_9 ( ( V_9 * ) & V_66 , sizeof( V_66 ) , V_77 . V_58 ) ;
V_77 . V_58 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_77 . V_58 ) ;
V_77 . V_58 = F_9 ( ( V_9 * ) & V_52 , V_31 , V_77 . V_58 ) ;
} else {
V_77 . V_58 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_77 . V_58 ) ;
}
V_77 . V_58 = F_11 ( V_77 . V_58 ) ;
V_77 . V_58 = F_15 ( V_77 . V_58 ) ;
F_4 ( ( const char * ) & V_77 , sizeof( V_77 ) ) ;
}
if ( V_63 ) {
F_4 ( ( const char * ) & V_66 , sizeof( V_66 ) ) ;
}
V_8 = V_28 ;
if ( V_63 && ( V_31 > 0 ) ) {
memset ( V_83 , 0 , V_31 ) ;
F_4 ( ( const char * ) & V_83 , V_31 ) ;
V_28 += V_31 ;
}
if ( V_35 && ( V_28 < 60 ) ) {
memset ( V_83 , 0 , 60 - V_28 ) ;
F_4 ( ( const char * ) & V_83 , 60 - V_28 ) ;
V_28 = 60 ;
}
if ( V_84 ) {
V_33 = F_16 ( V_85 , V_86 ,
NULL ,
V_87 , V_88 ,
V_28 , V_28 ,
0 ,
1000000 ,
V_7 , V_89 ,
& V_90 , & V_32 ) ;
} else {
V_33 = F_17 ( V_85 , V_86 ,
V_87 , V_88 ,
V_28 , V_28 ,
V_7 ,
& V_90 , & V_32 ) ;
}
if ( ! V_33 ) {
fprintf ( V_6 , L_2 ,
V_91 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
if ( V_92 == NULL ) {
V_88 ++ ;
}
if ( ! V_93 ) {
fprintf ( V_6 , L_3 , V_28 ) ;
}
V_94 ++ ;
}
V_65 += V_8 - V_10 ;
V_8 = V_10 ;
return;
}
static void
F_19 ( void )
{
int V_32 ;
T_3 V_33 ;
if ( V_84 ) {
#ifdef F_20
const char * V_95 = L_4 F_20 L_5 V_96 L_6 ;
#else
const char * V_95 = L_7 ;
#endif
char V_97 [ 100 ] ;
F_21 ( V_97 , sizeof( V_97 ) , L_8 , V_98 ) ;
V_33 = F_22 ( V_85 , V_86 ,
V_97 ,
NULL ,
NULL ,
V_95 ,
- 1 ,
& V_90 ,
& V_32 ) ;
if ( V_33 ) {
V_33 = F_23 ( V_85 , V_86 ,
NULL ,
NULL ,
NULL ,
L_9 ,
NULL ,
V_99 ,
V_100 ,
& V_90 ,
0 ,
6 ,
& V_32 ) ;
}
} else {
V_33 = F_24 ( V_85 , V_86 , V_99 , V_100 ,
FALSE , & V_90 , & V_32 ) ;
}
if ( ! V_33 ) {
fprintf ( V_6 , L_2 ,
V_91 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
}
static void
F_25 ( void )
{
int V_32 ;
T_3 V_33 ;
if ( V_84 ) {
V_33 = F_26 ( V_85 , V_86 ,
0 ,
& V_90 ,
L_10 ,
0 ,
0 ,
V_94 ,
V_94 - V_94 ,
& V_32 ) ;
} else {
V_33 = TRUE ;
}
if ( ! V_33 ) {
fprintf ( V_6 , L_2 ,
V_91 , F_18 ( V_32 ) ) ;
exit ( - 1 ) ;
}
return;
}
static void
F_27 ( char * V_1 )
{
T_4 V_101 ;
if ( V_102 != 0 ) {
if ( V_102 == V_103 )
return;
V_104 [ V_102 ++ ] = ' ' ;
}
V_101 = strlen ( V_1 ) ;
if ( V_101 != 0 ) {
if ( V_102 + V_101 > V_103 )
return;
F_28 ( & V_104 [ V_102 ] , V_1 , V_103 ) ;
V_102 += ( int ) V_101 ;
if ( V_105 >= 2 ) {
char * V_4 ;
char V_106 [ V_103 ] ;
F_28 ( V_106 , V_104 , V_103 ) ;
while ( ( V_4 = strchr ( V_106 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_11 , V_106 ) ;
}
}
}
static void
F_29 ( void )
{
struct V_107 V_108 ;
char * V_109 ;
char * V_110 ;
int V_111 ;
int V_14 ;
V_104 [ V_102 ] = '\0' ;
if ( V_105 > 0 )
fprintf ( V_6 , L_12 , V_104 ) ;
if ( V_112 ) {
switch ( V_104 [ 0 ] ) {
case 'i' :
case 'I' :
V_89 = 0x00000001 ;
V_104 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_89 = 0x00000002 ;
V_104 [ 0 ] = ' ' ;
break;
default:
V_89 = 0x00000000 ;
break;
}
V_14 = 0 ;
while ( V_104 [ V_14 ] == ' ' ||
V_104 [ V_14 ] == '\r' ||
V_104 [ V_14 ] == '\t' ) {
V_14 ++ ;
}
V_102 -= V_14 ;
memmove ( V_104 , V_104 + V_14 , V_102 + 1 ) ;
}
if ( V_92 == NULL ) {
V_102 = 0 ;
return;
}
V_108 = V_113 ;
V_88 = 0 ;
if ( strlen ( V_104 ) > 2 ) {
V_109 = strptime ( V_104 , V_92 , & V_108 ) ;
if ( V_109 != NULL ) {
V_87 = mktime ( & V_108 ) ;
} else
V_87 = - 1 ;
if ( - 1 == V_87 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_104 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_13 ,
V_104 , V_92 ) ;
if ( V_105 >= 2 ) {
fprintf ( V_6 , L_14 ,
V_108 . V_114 , V_108 . V_115 , V_108 . V_116 ,
V_108 . V_117 , V_108 . V_118 , V_108 . V_119 , V_108 . V_120 ) ;
}
V_87 = 0 ;
V_88 = 0 ;
} else {
V_88 = ( T_1 ) strtol ( V_109 , & V_110 , 10 ) ;
if ( V_109 == V_110 ) {
V_88 = 0 ;
} else {
V_111 = ( int ) ( V_110 - V_109 ) ;
if ( V_111 > 6 ) {
for ( V_14 = V_111 - 6 ; V_14 != 0 ; V_14 -- )
V_88 /= 10 ;
} else if ( V_111 < 6 ) {
for ( V_14 = 6 - V_111 ; V_14 != 0 ; V_14 -- )
V_88 *= 10 ;
}
}
}
}
if ( V_105 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_104 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_12 , V_104 ) ;
fprintf ( V_6 , L_15 , V_92 , ( T_1 ) V_87 , V_88 ) ;
}
V_102 = 0 ;
}
static void
F_3 ( T_3 V_30 )
{
if ( V_105 >= 1 )
fprintf ( V_6 , L_16 , V_30 ? L_17 : L_18 ) ;
F_13 ( V_30 ) ;
V_121 ++ ;
F_29 () ;
}
static void
F_30 ( char * V_1 )
{
fprintf ( V_6 , L_19 , V_1 + 10 ) ;
}
void
F_31 ( T_5 V_122 , char * V_1 )
{
T_1 V_3 ;
int V_123 ;
int V_124 = 0 ;
int V_125 ;
int V_14 ;
char * V_126 ;
char V_127 [ 3 ] ;
if ( V_105 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_20 ,
V_128 [ V_129 ] , V_130 [ V_122 ] , V_1 ? V_1 : L_9 ) ;
}
switch( V_129 ) {
case V_131 :
switch( V_122 ) {
case V_132 :
F_27 ( V_1 ) ;
break;
case V_133 :
F_30 ( V_1 ) ;
break;
case V_134 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_129 = V_135 ;
V_136 = V_7 + V_3 ;
}
break;
case V_137 :
V_129 = V_138 ;
break;
default:
break;
}
break;
case V_138 :
switch( V_122 ) {
case V_132 :
F_27 ( V_1 ) ;
break;
case V_133 :
F_30 ( V_1 ) ;
break;
case V_134 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_65 = 0 ;
V_129 = V_135 ;
} else if ( ( V_3 - V_65 ) != V_8 - V_10 ) {
if ( V_3 < V_8 ) {
F_5 ( V_8 - V_3 ) ;
V_129 = V_135 ;
} else {
if ( V_105 >= 1 )
fprintf ( V_6 , L_21 ,
V_8 , V_3 ) ;
F_13 ( FALSE ) ;
V_129 = V_131 ;
}
} else
V_129 = V_135 ;
V_136 = V_7 + V_3 ;
break;
case V_137 :
V_129 = V_138 ;
break;
default:
break;
}
break;
case V_135 :
switch( V_122 ) {
case V_139 :
V_129 = V_140 ;
F_2 ( V_1 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
V_129 = V_141 ;
break;
case V_137 :
V_129 = V_138 ;
break;
default:
break;
}
break;
case V_140 :
switch( V_122 ) {
case V_139 :
F_2 ( V_1 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_137 :
V_123 = 0 ;
V_129 = V_141 ;
if ( V_122 == V_137 ) {
V_123 = 1 ;
V_129 = V_138 ;
}
if ( V_142 ) {
V_124 = 0 ;
V_125 = V_8 - ( int ) ( V_136 - V_7 ) ;
V_126 = ( char * ) F_32 ( ( V_125 + 1 ) / 4 + 1 ) ;
for ( V_14 = 0 ; V_14 < ( V_125 + 1 ) / 4 ; V_14 ++ ) {
V_127 [ 0 ] = V_136 [ V_14 * 3 ] ;
V_127 [ 1 ] = V_136 [ V_14 * 3 + 1 ] ;
V_127 [ 2 ] = '\0' ;
if ( ! isxdigit ( V_127 [ 0 ] ) || ! isxdigit ( V_127 [ 0 ] ) ) {
break;
}
V_126 [ V_14 ] = ( char ) strtoul ( V_127 , ( char * * ) NULL , 16 ) ;
V_124 ++ ;
if ( ! ( V_136 [ V_14 * 3 + 2 ] == ' ' ) ) {
if ( V_123 != 1 )
V_124 -- ;
break;
}
}
if ( V_124 > 0 ) {
if ( strncmp ( V_136 + V_125 - V_124 , V_126 , V_124 ) == 0 ) {
F_5 ( V_124 ) ;
}
else {
F_5 ( V_125 ) ;
}
}
F_33 ( V_126 ) ;
}
break;
default:
break;
}
break;
case V_141 :
switch( V_122 ) {
case V_137 :
V_129 = V_138 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_22 , V_129 ) ;
exit ( - 1 ) ;
}
if ( V_105 >= 2 )
fprintf ( V_6 , L_23 , V_128 [ V_129 ] ) ;
}
static void
F_34 ( void )
{
fprintf ( V_6 ,
L_24
#ifdef F_20
L_25 F_20 L_5 V_96 L_6
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
L_74
L_75
L_71
L_72
L_76
L_77
L_78
L_72
L_79
L_80
L_81
L_82
L_83
L_84
L_26
L_85
L_86
L_87
L_88
L_89
L_9 ,
V_143 , V_15 ) ;
exit ( - 1 ) ;
}
static void
F_35 ( int V_144 , char * V_145 [] )
{
int V_4 ;
char * V_110 ;
#ifdef F_36
F_37 ( V_144 , V_145 ) ;
F_38 () ;
#endif
while ( ( V_4 = F_39 ( V_144 , V_145 , L_90 ) ) != - 1 ) {
switch( V_4 ) {
case '?' : F_34 () ; break;
case 'h' : F_34 () ; break;
case 'd' : if ( ! V_93 ) V_105 ++ ; break;
case 'D' : V_112 = TRUE ; break;
case 'q' : V_93 = TRUE ; V_105 = FALSE ; break;
case 'l' : V_99 = ( T_1 ) strtol ( V_146 , NULL , 0 ) ; break;
case 'm' : V_11 = ( T_1 ) strtol ( V_146 , NULL , 0 ) ; break;
case 'n' : V_84 = TRUE ; break;
case 'o' :
if ( V_146 [ 0 ] != 'h' && V_146 [ 0 ] != 'o' && V_146 [ 0 ] != 'd' ) {
fprintf ( V_6 , L_91 , V_146 ) ;
F_34 () ;
}
switch( V_146 [ 0 ] ) {
case 'o' : V_5 = 8 ; break;
case 'h' : V_5 = 16 ; break;
case 'd' : V_5 = 10 ; break;
}
break;
case 'e' :
V_35 = TRUE ;
if ( sscanf ( V_146 , L_92 , & V_38 ) < 1 ) {
fprintf ( V_6 , L_93 , V_146 ) ;
F_34 () ;
}
break;
case 'i' :
V_39 = TRUE ;
V_44 = strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || * V_110 != '\0' || V_44 < 0 ||
V_44 > 255 ) {
fprintf ( V_6 , L_94 , V_146 ) ;
F_34 () ;
}
V_35 = TRUE ;
V_38 = 0x800 ;
break;
case 's' :
V_34 = TRUE ;
V_63 = FALSE ;
V_59 = FALSE ;
V_46 = FALSE ;
V_79 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_95 , V_4 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_96 , V_4 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_80 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_97 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_98 , V_4 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_82 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || * V_110 != '\0' ) {
fprintf ( V_6 , L_99 , V_4 ) ;
F_34 () ;
}
V_39 = TRUE ;
V_44 = 132 ;
V_35 = TRUE ;
V_38 = 0x800 ;
break;
case 'S' :
V_34 = TRUE ;
V_63 = TRUE ;
V_59 = FALSE ;
V_46 = FALSE ;
V_79 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_95 , V_4 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_96 , V_4 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_80 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_97 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_100 , V_4 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_76 = ( T_1 ) strtoul ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || * V_110 != '\0' ) {
fprintf ( V_6 , L_101 , V_4 ) ;
F_34 () ;
}
V_39 = TRUE ;
V_44 = 132 ;
V_35 = TRUE ;
V_38 = 0x800 ;
break;
case 't' :
V_92 = V_146 ;
break;
case 'u' :
V_46 = TRUE ;
V_59 = FALSE ;
V_34 = FALSE ;
V_63 = FALSE ;
V_55 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_102 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_103 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_57 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || * V_110 != '\0' ) {
fprintf ( V_6 , L_104 ) ;
F_34 () ;
}
V_39 = TRUE ;
V_44 = 17 ;
V_35 = TRUE ;
V_38 = 0x800 ;
break;
case 'T' :
V_59 = TRUE ;
V_46 = FALSE ;
V_34 = FALSE ;
V_63 = FALSE ;
V_55 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || ( * V_110 != ',' && * V_110 != '\0' ) ) {
fprintf ( V_6 , L_105 ) ;
F_34 () ;
}
if ( * V_110 == '\0' ) {
fprintf ( V_6 , L_103 ) ;
F_34 () ;
}
V_110 ++ ;
V_146 = V_110 ;
V_57 = ( T_1 ) strtol ( V_146 , & V_110 , 10 ) ;
if ( V_110 == V_146 || * V_110 != '\0' ) {
fprintf ( V_6 , L_106 ) ;
F_34 () ;
}
V_39 = TRUE ;
V_44 = 6 ;
V_35 = TRUE ;
V_38 = 0x800 ;
break;
case 'a' :
V_142 = TRUE ;
break;
default:
F_34 () ;
}
}
if ( V_147 >= V_144 || V_144 - V_147 < 2 ) {
fprintf ( V_6 , L_107 ) ;
F_34 () ;
}
if ( strcmp ( V_145 [ V_147 ] , L_108 ) ) {
V_98 = F_40 ( V_145 [ V_147 ] ) ;
V_148 = F_41 ( V_98 , L_109 ) ;
if ( ! V_148 ) {
fprintf ( V_6 , L_110 ,
V_98 , F_18 ( V_149 ) ) ;
exit ( - 1 ) ;
}
} else {
V_98 = L_111 ;
V_148 = V_150 ;
}
if ( strcmp ( V_145 [ V_147 + 1 ] , L_108 ) ) {
V_91 = F_40 ( V_145 [ V_147 + 1 ] ) ;
V_86 = F_41 ( V_91 , L_112 ) ;
if ( ! V_86 ) {
fprintf ( V_6 , L_113 ,
V_91 , F_18 ( V_149 ) ) ;
exit ( - 1 ) ;
}
} else {
V_91 = L_114 ;
V_86 = stdout ;
}
if ( V_99 != 1 && V_35 ) {
fprintf ( V_6 , L_115 ) ;
exit ( - 1 ) ;
}
if ( ! V_148 ) {
V_148 = V_150 ;
V_98 = L_111 ;
}
if ( ! V_86 ) {
V_86 = stdout ;
V_91 = L_114 ;
}
V_87 = time ( 0 ) ;
V_113 = * localtime ( & V_87 ) ;
V_113 . V_120 = - 1 ;
if ( ! V_93 ) {
fprintf ( V_6 , L_116 , V_98 ) ;
fprintf ( V_6 , L_117 , V_91 ) ;
fprintf ( V_6 , L_118 , V_84 ? L_119 : L_120 ) ;
if ( V_35 ) fprintf ( V_6 , L_121 ,
V_38 ) ;
if ( V_39 ) fprintf ( V_6 , L_122 ,
V_44 ) ;
if ( V_46 ) fprintf ( V_6 , L_123 ,
V_55 , V_57 ) ;
if ( V_59 ) fprintf ( V_6 , L_124 ,
V_55 , V_57 ) ;
if ( V_34 ) fprintf ( V_6 , L_125 ,
V_79 , V_80 , V_82 ) ;
if ( V_63 ) fprintf ( V_6 , L_126 ,
V_70 , V_72 , V_74 , V_76 ) ;
}
}
int
main ( int V_144 , char * V_145 [] )
{
F_35 ( V_144 , V_145 ) ;
assert ( V_148 != NULL ) ;
assert ( V_86 != NULL ) ;
F_19 () ;
V_10 = 0 ;
if ( V_35 ) {
V_10 += ( int ) sizeof( V_36 ) ;
}
if ( V_39 ) {
V_42 = V_10 ;
V_10 += ( int ) sizeof( V_40 ) ;
}
if ( V_34 ) {
V_10 += ( int ) sizeof( V_77 ) ;
}
if ( V_63 ) {
V_10 += ( int ) sizeof( V_66 ) ;
}
if ( V_59 ) {
V_10 += ( int ) sizeof( V_60 ) ;
}
if ( V_46 ) {
V_10 += ( int ) sizeof( V_53 ) ;
}
V_8 = V_10 ;
V_151 = V_148 ;
F_42 () ;
F_13 ( FALSE ) ;
F_25 () ;
fclose ( V_148 ) ;
fclose ( V_86 ) ;
if ( V_105 )
fprintf ( V_6 , L_127 ) ;
if ( ! V_93 ) {
fprintf ( V_6 , L_128 V_152 L_129 ,
V_121 , ( V_121 == 1 ) ? L_9 : L_130 ,
V_94 , ( V_94 == 1 ) ? L_9 : L_130 ,
V_90 , ( V_90 == 1 ) ? L_9 : L_130 ) ;
}
return 0 ;
}
