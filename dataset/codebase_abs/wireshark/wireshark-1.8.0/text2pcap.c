static unsigned long
F_1 ( const char * V_1 , int V_2 )
{
unsigned long V_3 ;
char * V_4 ;
V_3 = strtoul ( V_1 , & V_4 , V_2 ? V_5 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_6 , L_1 , V_1 ) ;
exit ( - 1 ) ;
}
return V_3 ;
}
static void
F_2 ( const char * V_1 )
{
unsigned long V_3 ;
V_3 = F_1 ( V_1 , FALSE ) ;
V_7 [ V_8 ] = ( unsigned char ) V_3 ;
V_8 ++ ;
if ( V_8 >= V_9 )
F_3 () ;
}
static void
F_4 ( unsigned long V_10 )
{
V_8 -= V_10 ;
}
static T_1
F_5 ( void * V_11 , unsigned long V_12 )
{
unsigned long V_13 = 0 ;
T_1 * V_14 = V_11 ;
while( V_12 > 1 ) {
V_13 += F_6 ( * ( T_1 * ) V_14 ) ;
V_14 ++ ;
V_12 -= 2 ;
}
if( V_12 > 0 )
V_13 += F_6 ( * ( V_15 * ) V_14 ) ;
while ( V_13 >> 16 )
V_13 = ( V_13 & 0xffff ) + ( V_13 >> 16 ) ;
V_13 = ~ V_13 ;
return F_7 ( V_13 ) ;
}
static T_2
F_8 ( const V_15 * V_11 , unsigned int V_16 , T_2 V_17 )
{
unsigned int V_18 ;
T_2 V_19 ;
V_19 = V_17 ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ )
F_9 ( V_19 , V_11 [ V_18 ] ) ;
return ( V_19 ) ;
}
static T_2
F_10 ( T_2 V_19 )
{
T_2 V_20 ;
V_15 V_21 , V_22 , V_23 , V_24 ;
V_20 = ~ V_19 ;
V_21 = V_20 & 0xff ;
V_22 = ( V_20 >> 8 ) & 0xff ;
V_23 = ( V_20 >> 16 ) & 0xff ;
V_24 = ( V_20 >> 24 ) & 0xff ;
V_20 = ( ( V_21 << 24 ) | ( V_22 << 16 ) | ( V_23 << 8 ) | V_24 ) ;
return ( V_20 ) ;
}
static unsigned long
F_11 ( unsigned long V_25 )
{
unsigned long V_26 ;
V_26 = V_25 % 4 ;
if ( V_26 == 0 )
return 0 ;
else
return 4 - V_26 ;
}
static void
F_12 ( void )
{
int V_25 = 0 ;
int V_27 = 0 ;
int V_28 = 0 ;
int V_29 = 0 ;
int V_18 , V_30 ;
T_2 V_31 ;
struct V_32 V_33 ;
if ( V_8 > 0 ) {
V_25 = V_8 ;
if ( V_34 ) { V_25 += sizeof( V_35 ) + F_11 ( V_8 ) ; }
if ( V_36 ) { V_25 += sizeof( V_37 ) ; }
if ( V_38 ) { V_25 += sizeof( V_39 ) ; V_27 = V_25 ; }
if ( V_40 ) { V_25 += sizeof( V_41 ) ; V_27 = V_25 ; }
if ( V_42 ) { V_25 += sizeof( V_43 ) ; V_28 = V_25 ; }
if ( V_44 ) {
V_25 += sizeof( V_45 ) ;
if ( V_25 < 60 ) {
V_29 = 60 - V_25 ;
V_25 = 60 ;
}
}
V_33 . V_46 = ( T_2 ) V_46 ;
V_33 . V_47 = V_47 ;
if ( V_48 == NULL ) { V_47 ++ ; }
V_33 . V_49 = V_25 ;
V_33 . V_50 = V_25 ;
if ( fwrite ( & V_33 , sizeof( V_33 ) , 1 , V_51 ) != 1 )
goto V_52;
if ( V_44 ) {
V_45 . V_53 = F_7 ( V_54 ) ;
if ( fwrite ( & V_45 , sizeof( V_45 ) , 1 , V_51 ) != 1 )
goto V_52;
}
if ( V_42 ) {
V_43 . V_55 = F_7 ( V_28 ) ;
V_43 . V_56 = ( V_15 ) V_57 ;
V_43 . V_58 = 0 ;
V_43 . V_58 = F_5 ( & V_43 , sizeof( V_43 ) ) ;
if ( fwrite ( & V_43 , sizeof( V_43 ) , 1 , V_51 ) != 1 )
goto V_52;
}
V_59 . V_60 = V_43 . V_60 ;
V_59 . V_61 = V_43 . V_61 ;
V_59 . V_62 = 0 ;
V_59 . V_56 = ( V_15 ) V_57 ;
V_59 . V_25 = F_7 ( V_27 ) ;
if ( V_38 ) {
T_1 V_63 ;
V_39 . V_64 = F_7 ( V_65 ) ;
V_39 . V_66 = F_7 ( V_67 ) ;
V_39 . V_25 = F_7 ( V_27 ) ;
V_39 . V_68 = 0 ;
V_63 = F_5 ( & V_59 , sizeof( V_59 ) ) ;
V_31 = F_6 ( V_63 ) ;
V_63 = F_5 ( & V_39 , sizeof( V_39 ) ) ;
V_31 += F_6 ( V_63 ) ;
V_63 = F_5 ( V_7 , V_8 ) ;
V_31 += F_6 ( V_63 ) ;
V_63 = ( V_31 & 0xffff ) + ( V_31 >> 16 ) ;
V_39 . V_68 = F_7 ( V_63 ) ;
if ( V_39 . V_68 == 0 )
V_39 . V_68 = F_7 ( 1 ) ;
if ( fwrite ( & V_39 , sizeof( V_39 ) , 1 , V_51 ) != 1 )
goto V_52;
}
if ( V_40 ) {
T_1 V_63 ;
V_41 . V_64 = F_7 ( V_65 ) ;
V_41 . V_66 = F_7 ( V_67 ) ;
V_41 . V_69 = F_7 ( 0x2000 ) ;
V_41 . V_68 = 0 ;
V_63 = F_5 ( & V_59 , sizeof( V_59 ) ) ;
V_31 = F_6 ( V_63 ) ;
V_63 = F_5 ( & V_41 , sizeof( V_41 ) ) ;
V_31 += F_6 ( V_63 ) ;
V_63 = F_5 ( V_7 , V_8 ) ;
V_31 += F_6 ( V_63 ) ;
V_63 = ( V_31 & 0xffff ) + ( V_31 >> 16 ) ;
V_41 . V_68 = F_7 ( V_63 ) ;
if ( V_41 . V_68 == 0 )
V_41 . V_68 = F_7 ( 1 ) ;
if ( fwrite ( & V_41 , sizeof( V_41 ) , 1 , V_51 ) != 1 )
goto V_52;
}
if ( V_34 ) {
V_35 . type = V_70 ;
V_35 . V_71 = V_72 ;
V_35 . V_25 = F_7 ( V_8 + sizeof( V_35 ) ) ;
V_35 . V_73 = F_13 ( V_74 ) ;
V_35 . V_75 = F_7 ( V_76 ) ;
V_35 . V_77 = F_7 ( V_78 ) ;
V_35 . V_79 = F_13 ( V_80 ) ;
V_30 = F_11 ( V_8 ) ;
for ( V_18 = 0 ; V_18 < V_30 ; V_18 ++ )
F_2 ( L_2 ) ;
}
if ( V_36 ) {
T_2 V_81 ;
V_37 . V_82 = F_7 ( V_83 ) ;
V_37 . V_66 = F_7 ( V_84 ) ;
V_37 . V_85 = F_13 ( V_86 ) ;
V_37 . V_68 = F_13 ( 0 ) ;
V_37 . V_68 = F_8 ( ( V_15 * ) & V_37 , sizeof( V_37 ) , ~ 0L ) ;
if ( V_34 )
V_37 . V_68 = F_8 ( ( V_15 * ) & V_35 , sizeof( V_35 ) , V_37 . V_68 ) ;
V_81 = F_10 ( F_8 ( V_7 , V_8 , V_37 . V_68 ) ) ;
V_37 . V_68 = F_13 ( V_81 ) ;
if ( fwrite ( & V_37 , sizeof( V_37 ) , 1 , V_51 ) != 1 )
goto V_52;
}
if ( V_34 ) {
if ( fwrite ( & V_35 , sizeof( V_35 ) , 1 , V_51 ) != 1 )
goto V_52;
}
if ( fwrite ( V_7 , V_8 , 1 , V_51 ) != 1 )
goto V_52;
if ( V_44 && V_29 > 0 ) {
memset ( V_87 , 0 , V_29 ) ;
if ( fwrite ( V_87 , V_29 , 1 , V_51 ) != 1 )
goto V_52;
}
if ( ! V_88 )
fprintf ( V_6 , L_3 , V_8 , F_14 ( V_41 . V_89 ) ) ;
V_90 ++ ;
}
V_41 . V_89 = F_14 ( V_41 . V_89 ) + V_8 ;
V_41 . V_89 = F_13 ( V_41 . V_89 ) ;
V_91 += V_8 ;
V_8 = 0 ;
return;
V_52:
fprintf ( V_6 , L_4 ,
V_92 , F_15 ( V_93 ) ) ;
exit ( - 1 ) ;
}
static void
F_16 ( void )
{
struct V_94 V_95 ;
V_95 . V_96 = V_97 ;
V_95 . V_98 = 2 ;
V_95 . V_99 = 4 ;
V_95 . V_100 = 0 ;
V_95 . V_101 = 0 ;
V_95 . V_102 = 102400 ;
V_95 . V_103 = V_104 ;
if ( fwrite ( & V_95 , sizeof( V_95 ) , 1 , V_51 ) != 1 ) {
fprintf ( V_6 , L_4 ,
V_92 , F_15 ( V_93 ) ) ;
exit ( - 1 ) ;
}
}
static void
F_17 ( char * V_1 )
{
T_3 V_105 ;
if ( V_106 != 0 ) {
if ( V_106 == V_107 )
return;
V_108 [ V_106 ++ ] = ' ' ;
}
V_105 = strlen ( V_1 ) ;
if ( V_105 != 0 ) {
if ( V_106 + V_105 > V_107 )
return;
F_18 ( & V_108 [ V_106 ] , V_1 , V_107 ) ;
V_106 += ( int ) V_105 ;
if ( V_109 >= 2 ) {
char * V_4 ;
char V_110 [ V_107 ] ;
F_18 ( V_110 , V_108 , V_107 ) ;
while ( ( V_4 = strchr ( V_110 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_5 , V_110 ) ;
}
}
}
static void
F_19 ( void )
{
struct V_111 V_112 ;
char * V_113 ;
char * V_114 ;
int V_115 ;
int V_18 ;
if ( V_48 == NULL )
return;
V_112 = V_116 ;
V_47 = 0 ;
V_108 [ V_106 ] = '\0' ;
if ( strlen ( V_108 ) > 2 ) {
V_113 = strptime ( V_108 , V_48 , & V_112 ) ;
if ( V_113 != NULL ) {
V_46 = mktime ( & V_112 ) ;
} else
V_46 = - 1 ;
if ( - 1 == V_46 )
{
char * V_4 ;
while ( ( V_4 = strchr ( V_108 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_6 ,
V_108 , V_48 ) ;
if ( V_109 >= 2 ) {
fprintf ( V_6 , L_7 ,
V_112 . V_117 , V_112 . V_118 , V_112 . V_119 ,
V_112 . V_120 , V_112 . V_121 , V_112 . V_122 , V_112 . V_123 ) ;
}
V_46 = 0 ;
V_47 = 0 ;
}
else
{
V_47 = strtol ( V_113 , & V_114 , 10 ) ;
if ( V_113 == V_114 ) {
V_47 = 0 ;
} else {
V_115 = ( int ) ( V_114 - V_113 ) ;
if ( V_115 > 6 ) {
for ( V_18 = V_115 - 6 ; V_18 != 0 ; V_18 -- )
V_47 /= 10 ;
} else if ( V_115 < 6 ) {
for ( V_18 = 6 - V_115 ; V_18 != 0 ; V_18 -- )
V_47 *= 10 ;
}
}
}
}
if ( V_109 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_108 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_8 , V_108 ) ;
fprintf ( V_6 , L_9 , V_48 , ( T_2 ) V_46 , V_47 ) ;
}
V_106 = 0 ;
}
static void
F_3 ( void )
{
if ( V_109 >= 1 )
fprintf ( V_6 , L_10 ) ;
F_12 () ;
V_124 ++ ;
F_19 () ;
}
static void
F_20 ( char * V_1 )
{
fprintf ( V_6 , L_11 , V_1 + 10 ) ;
}
void
F_21 ( T_4 V_125 , char * V_1 )
{
unsigned long V_3 ;
int V_126 ;
int V_127 = 0 ;
int V_128 ;
int V_18 ;
char * V_129 ;
char V_130 [ 3 ] ;
if ( V_109 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_12 ,
V_131 [ V_132 ] , V_133 [ V_125 ] , V_1 ? V_1 : L_13 ) ;
}
if ( V_132 == V_134 || V_132 == V_135 ) {
if ( V_48 != NULL && V_136 ) {
V_125 = V_137 ;
}
}
switch( V_132 ) {
case V_134 :
switch( V_125 ) {
case V_137 :
F_17 ( V_1 ) ;
break;
case V_138 :
F_20 ( V_1 ) ;
break;
case V_139 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_132 = V_140 ;
V_141 = V_7 + V_3 ;
}
break;
case V_142 :
V_132 = V_135 ;
break;
default:
break;
}
break;
case V_135 :
switch( V_125 ) {
case V_137 :
F_17 ( V_1 ) ;
break;
case V_138 :
F_20 ( V_1 ) ;
break;
case V_139 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_91 = 0 ;
V_132 = V_140 ;
} else if ( ( V_3 - V_91 ) != V_8 ) {
if ( V_3 < V_8 ) {
F_4 ( V_8 - V_3 ) ;
V_132 = V_140 ;
} else {
if ( V_109 >= 1 )
fprintf ( V_6 , L_14 ,
V_8 , V_3 ) ;
F_12 () ;
V_132 = V_134 ;
}
} else
V_132 = V_140 ;
V_141 = V_7 + V_3 ;
break;
case V_142 :
V_132 = V_135 ;
break;
default:
break;
}
break;
case V_140 :
switch( V_125 ) {
case V_143 :
V_132 = V_144 ;
F_2 ( V_1 ) ;
break;
case V_137 :
case V_138 :
case V_139 :
V_132 = V_145 ;
break;
case V_142 :
V_132 = V_135 ;
break;
default:
break;
}
break;
case V_144 :
switch( V_125 ) {
case V_143 :
F_2 ( V_1 ) ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_142 :
V_126 = 0 ;
V_132 = V_145 ;
if ( V_125 == V_142 ) {
V_126 = 1 ;
V_132 = V_135 ;
}
if ( V_146 ) {
V_127 = 0 ;
V_128 = V_8 - ( int ) ( V_141 - V_7 ) ;
V_129 = ( char * ) F_22 ( ( V_128 + 1 ) / 4 + 1 ) ;
for( V_18 = 0 ; V_18 < ( V_128 + 1 ) / 4 ; V_18 ++ ) {
V_130 [ 0 ] = V_141 [ V_18 * 3 ] ;
V_130 [ 1 ] = V_141 [ V_18 * 3 + 1 ] ;
V_130 [ 2 ] = '\0' ;
if ( ! isxdigit ( V_130 [ 0 ] ) || ! isxdigit ( V_130 [ 0 ] ) ) {
break;
}
V_129 [ V_18 ] = ( char ) strtoul ( V_130 , ( char * * ) NULL , 16 ) ;
V_127 ++ ;
if ( ! ( V_141 [ V_18 * 3 + 2 ] == ' ' ) ) {
if ( V_126 != 1 )
V_127 -- ;
break;
}
}
if ( V_127 > 0 ) {
if ( strncmp ( V_141 + V_128 - V_127 , V_129 , V_127 ) == 0 ) {
F_4 ( V_127 ) ;
}
else {
F_4 ( V_128 ) ;
}
}
F_23 ( V_129 ) ;
}
break;
default:
break;
}
break;
case V_145 :
switch( V_125 ) {
case V_142 :
V_132 = V_135 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_15 , V_132 ) ;
exit ( - 1 ) ;
}
if ( V_109 >= 2 )
fprintf ( V_6 , L_16 , V_131 [ V_132 ] ) ;
}
static void
F_24 ( void )
{
fprintf ( V_6 ,
L_17
#ifdef F_25
L_18 F_25 L_19 V_147 L_20
#endif
L_21
L_22
L_23
L_21
L_24
L_21
L_25
L_26
L_21
L_27
L_28
L_29
L_30
L_31
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
L_21
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_21
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_63
L_64
L_68
L_69
L_70
L_64
L_71
L_72
L_73
L_74
L_75
L_76
L_21
L_77
L_78
L_79
L_80
L_13 ,
V_148 , V_149 ) ;
exit ( - 1 ) ;
}
static void
F_26 ( int V_150 , char * V_151 [] )
{
int V_4 ;
char * V_114 ;
#ifdef F_27
F_28 ( V_150 , V_151 ) ;
#endif
while ( ( V_4 = F_29 ( V_150 , V_151 , L_81 ) ) != - 1 ) {
switch( V_4 ) {
case '?' : F_24 () ; break;
case 'h' : F_24 () ; break;
case 'D' : V_136 = 1 ; break;
case 'd' : if ( ! V_88 ) V_109 ++ ; break;
case 'q' : V_88 = TRUE ; V_109 = FALSE ; break;
case 'l' : V_104 = strtol ( V_152 , NULL , 0 ) ; break;
case 'm' : V_9 = strtol ( V_152 , NULL , 0 ) ; break;
case 'o' :
if ( V_152 [ 0 ] != 'h' && V_152 [ 0 ] != 'o' && V_152 [ 0 ] != 'd' ) {
fprintf ( V_6 , L_82 , V_152 ) ;
F_24 () ;
}
switch( V_152 [ 0 ] ) {
case 'o' : V_5 = 8 ; break;
case 'h' : V_5 = 16 ; break;
case 'd' : V_5 = 10 ; break;
}
break;
case 'e' :
V_44 = TRUE ;
if ( sscanf ( V_152 , L_83 , & V_54 ) < 1 ) {
fprintf ( V_6 , L_84 , V_152 ) ;
F_24 () ;
}
break;
case 'i' :
V_42 = TRUE ;
V_57 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || * V_114 != '\0' || V_57 < 0 ||
V_57 > 255 ) {
fprintf ( V_6 , L_85 , V_152 ) ;
F_24 () ;
}
V_44 = TRUE ;
V_54 = 0x800 ;
break;
case 's' :
V_36 = TRUE ;
V_83 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_86 , V_4 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_87 , V_4 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_84 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_88 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_89 , V_4 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_86 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || * V_114 != '\0' ) {
fprintf ( V_6 , L_90 , V_4 ) ;
F_24 () ;
}
V_42 = TRUE ;
V_57 = 132 ;
V_44 = TRUE ;
V_54 = 0x800 ;
break;
case 'S' :
V_36 = TRUE ;
V_34 = TRUE ;
V_83 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_86 , V_4 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_87 , V_4 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_84 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_88 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_91 , V_4 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_80 = strtoul ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || * V_114 != '\0' ) {
fprintf ( V_6 , L_92 , V_4 ) ;
F_24 () ;
}
V_42 = TRUE ;
V_57 = 132 ;
V_44 = TRUE ;
V_54 = 0x800 ;
break;
case 't' :
V_48 = V_152 ;
break;
case 'u' :
V_38 = TRUE ;
V_40 = FALSE ;
V_65 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_93 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_94 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_67 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || * V_114 != '\0' ) {
fprintf ( V_6 , L_95 ) ;
F_24 () ;
}
V_42 = TRUE ;
V_57 = 17 ;
V_44 = TRUE ;
V_54 = 0x800 ;
break;
case 'T' :
V_40 = TRUE ;
V_38 = FALSE ;
V_65 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || ( * V_114 != ',' && * V_114 != '\0' ) ) {
fprintf ( V_6 , L_96 ) ;
F_24 () ;
}
if ( * V_114 == '\0' ) {
fprintf ( V_6 , L_94 ) ;
F_24 () ;
}
V_114 ++ ;
V_152 = V_114 ;
V_67 = strtol ( V_152 , & V_114 , 10 ) ;
if ( V_114 == V_152 || * V_114 != '\0' ) {
fprintf ( V_6 , L_97 ) ;
F_24 () ;
}
V_42 = TRUE ;
V_57 = 6 ;
V_44 = TRUE ;
V_54 = 0x800 ;
break;
case 'a' :
V_146 = TRUE ;
break;
default:
F_24 () ;
}
}
if ( V_153 >= V_150 || V_150 - V_153 < 2 ) {
fprintf ( V_6 , L_98 ) ;
F_24 () ;
}
if ( strcmp ( V_151 [ V_153 ] , L_99 ) ) {
V_154 = F_30 ( V_151 [ V_153 ] ) ;
V_155 = F_31 ( V_154 , L_100 ) ;
if ( ! V_155 ) {
fprintf ( V_6 , L_101 ,
V_154 , F_15 ( V_93 ) ) ;
exit ( - 1 ) ;
}
} else {
V_154 = L_102 ;
V_155 = V_156 ;
}
if ( strcmp ( V_151 [ V_153 + 1 ] , L_99 ) ) {
V_92 = F_30 ( V_151 [ V_153 + 1 ] ) ;
V_51 = F_31 ( V_92 , L_103 ) ;
if ( ! V_51 ) {
fprintf ( V_6 , L_104 ,
V_92 , F_15 ( V_93 ) ) ;
exit ( - 1 ) ;
}
} else {
V_92 = L_105 ;
V_51 = stdout ;
}
if ( V_104 != 1 && V_44 ) {
fprintf ( V_6 , L_106 ) ;
exit ( - 1 ) ;
}
if ( ! V_155 ) {
V_155 = V_156 ;
V_154 = L_102 ;
}
if ( ! V_51 ) {
V_51 = stdout ;
V_92 = L_105 ;
}
V_46 = time ( 0 ) ;
V_116 = * localtime ( & V_46 ) ;
V_116 . V_123 = - 1 ;
if ( ! V_88 ) {
fprintf ( V_6 , L_107 , V_154 ) ;
fprintf ( V_6 , L_108 , V_92 ) ;
if ( V_44 ) fprintf ( V_6 , L_109 ,
V_54 ) ;
if ( V_42 ) fprintf ( V_6 , L_110 ,
V_57 ) ;
if ( V_38 ) fprintf ( V_6 , L_111 ,
V_65 , V_67 ) ;
if ( V_40 ) fprintf ( V_6 , L_112 ,
V_65 , V_67 ) ;
if ( V_36 ) fprintf ( V_6 , L_113 ,
V_83 , V_84 , V_86 ) ;
if ( V_34 ) fprintf ( V_6 , L_114 ,
V_74 , V_76 , V_78 , V_80 ) ;
}
}
int
main ( int V_150 , char * V_151 [] )
{
F_26 ( V_150 , V_151 ) ;
assert ( V_155 != NULL ) ;
assert ( V_51 != NULL ) ;
F_16 () ;
V_157 = V_155 ;
F_32 () ;
F_12 () ;
fclose ( V_155 ) ;
fclose ( V_51 ) ;
if ( V_109 )
fprintf ( V_6 , L_115 ) ;
if ( ! V_88 ) {
fprintf ( V_6 , L_116 ,
V_124 , ( V_124 == 1 ) ? L_13 : L_117 ,
V_90 , ( V_90 == 1 ) ? L_13 : L_117 ) ;
}
return 0 ;
}
