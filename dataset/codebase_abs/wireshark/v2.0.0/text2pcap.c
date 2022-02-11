static T_1
F_1 ( const char * V_1 , int V_2 )
{
T_1 V_3 ;
char * V_4 ;
if ( V_1 == NULL ) {
fprintf ( V_5 , L_1 ) ;
exit ( 1 ) ;
}
V_3 = ( T_1 ) strtoul ( V_1 , & V_4 , V_2 ? V_6 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_5 , L_2 , V_1 ) ;
exit ( 1 ) ;
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
return V_22 ;
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
return V_23 ;
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
T_3 V_35 = V_36 && ( V_37 == 2 ) ;
if ( V_38 ) {
V_39 = 0x86DD ;
V_40 = FALSE ;
}
V_28 = V_8 ;
if ( V_41 ) {
V_31 = F_12 ( V_28 - V_10 ) ;
} else {
V_31 = 0 ;
}
V_8 = 0 ;
if ( V_42 ) {
V_43 . V_44 = F_8 ( V_39 ) ;
F_4 ( ( const char * ) & V_43 , sizeof( V_43 ) ) ;
}
if ( V_40 ) {
if ( V_35 ) {
V_45 . V_46 = V_47 ? V_47 : V_48 ;
V_45 . V_49 = V_50 ? V_50 : V_51 ;
}
else {
V_45 . V_46 = V_50 ? V_50 : V_51 ;
V_45 . V_49 = V_47 ? V_47 : V_48 ;
}
V_45 . V_52 = F_8 ( V_28 - V_53 + V_31 ) ;
V_45 . V_54 = ( V_9 ) V_55 ;
V_45 . V_56 = 0 ;
V_45 . V_56 = F_6 ( & V_45 , sizeof( V_45 ) ) ;
F_4 ( ( const char * ) & V_45 , sizeof( V_45 ) ) ;
} else if ( V_38 ) {
if ( memcmp ( V_35 ? V_57 : V_58 , V_59 , sizeof( struct V_60 ) ) )
memcpy ( & V_61 . V_62 , V_35 ? & V_57 : & V_58 , sizeof( struct V_60 ) ) ;
if ( memcmp ( V_35 ? V_58 : V_57 , V_59 , sizeof( struct V_60 ) ) )
memcpy ( & V_61 . V_63 , V_35 ? & V_58 : & V_57 , sizeof( struct V_60 ) ) ;
V_61 . V_64 . V_65 &= 0x0F ;
V_61 . V_64 . V_65 |= ( 6 << 4 ) ;
V_61 . V_64 . V_66 . V_67 = F_8 ( V_28 - V_53 + V_31 ) ;
V_61 . V_64 . V_66 . V_68 = ( V_9 ) V_55 ;
V_61 . V_64 . V_66 . V_69 = 32 ;
F_4 ( ( const char * ) & V_61 , sizeof( V_61 ) ) ;
V_70 . V_71 = V_61 . V_62 ;
V_70 . V_72 = V_61 . V_63 ;
V_70 . V_73 = 0 ;
V_70 . V_54 = ( V_9 ) V_55 ;
V_33 = F_7 ( V_61 . V_64 . V_66 . V_67 ) ;
V_74 . V_28 = F_8 ( V_28 - V_33 + sizeof( V_75 ) ) ;
}
if ( ! V_38 ) {
V_74 . V_46 = V_45 . V_46 ;
V_74 . V_49 = V_45 . V_49 ;
V_74 . V_73 = 0 ;
V_74 . V_54 = ( V_9 ) V_55 ;
V_74 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_75 ) ) ;
}
if ( V_76 ) {
T_2 V_77 ;
T_1 V_78 ;
V_75 . V_79 = V_35 ? F_8 ( V_80 ) : F_8 ( V_81 ) ;
V_75 . V_82 = V_35 ? F_8 ( V_81 ) : F_8 ( V_80 ) ;
V_75 . V_28 = V_74 . V_28 ;
V_75 . V_83 = 0 ;
V_77 = V_38 ? F_6 ( & V_70 , sizeof( V_70 ) ) : F_6 ( & V_74 , sizeof( V_74 ) ) ;
V_78 = F_7 ( V_77 ) ;
V_77 = F_6 ( & V_75 , sizeof( V_75 ) ) ;
V_78 += F_7 ( V_77 ) ;
V_77 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_78 += F_7 ( V_77 ) ;
V_77 = ( V_78 & 0xffff ) + ( V_78 >> 16 ) ;
V_75 . V_83 = F_8 ( V_77 ) ;
if ( V_75 . V_83 == 0 )
V_75 . V_83 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_75 , sizeof( V_75 ) ) ;
}
if ( V_84 ) {
T_2 V_77 ;
T_1 V_78 ;
V_74 . V_46 = V_45 . V_46 ;
V_74 . V_49 = V_45 . V_49 ;
V_74 . V_73 = 0 ;
V_74 . V_54 = ( V_9 ) V_55 ;
V_74 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_85 ) ) ;
V_85 . V_79 = V_35 ? F_8 ( V_80 ) : F_8 ( V_81 ) ;
V_85 . V_82 = V_35 ? F_8 ( V_81 ) : F_8 ( V_80 ) ;
if ( V_36 ) {
V_85 . V_86 = 0x10 ;
V_85 . V_87 = F_14 ( V_35 ? V_88 : V_89 ) ;
V_85 . V_87 = F_15 ( V_85 . V_87 ) ;
}
else {
V_85 . V_86 = 0 ;
V_85 . V_87 = 0 ;
}
V_85 . V_90 = V_35 ? V_89 : V_88 ;
V_85 . V_91 = F_8 ( 0x2000 ) ;
V_85 . V_83 = 0 ;
V_77 = F_6 ( & V_74 , sizeof( V_74 ) ) ;
V_78 = F_7 ( V_77 ) ;
V_77 = F_6 ( & V_85 , sizeof( V_85 ) ) ;
V_78 += F_7 ( V_77 ) ;
V_77 = F_6 ( V_7 + V_10 , V_28 - V_10 ) ;
V_78 += F_7 ( V_77 ) ;
V_77 = ( V_78 & 0xffff ) + ( V_78 >> 16 ) ;
V_85 . V_83 = F_8 ( V_77 ) ;
if ( V_85 . V_83 == 0 )
V_85 . V_83 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_85 , sizeof( V_85 ) ) ;
if ( V_35 ) {
V_89 = F_14 ( V_89 ) + V_28 - V_10 ;
V_89 = F_15 ( V_89 ) ;
}
else {
V_88 = F_14 ( V_88 ) + V_28 - V_10 ;
V_88 = F_15 ( V_88 ) ;
}
}
if ( V_92 ) {
V_93 = 0 ;
if ( V_94 == 0 ) {
V_93 |= 0x02 ;
}
if ( ! V_30 ) {
V_93 |= 0x01 ;
}
V_95 . type = V_96 ;
V_95 . V_97 = V_93 ;
V_95 . V_28 = F_8 ( V_28 - V_10 + sizeof( V_95 ) ) ;
V_95 . V_98 = F_15 ( V_99 ) ;
V_95 . V_100 = F_8 ( V_101 ) ;
V_95 . V_102 = F_8 ( V_103 ) ;
V_95 . V_104 = F_15 ( V_105 ) ;
V_99 ++ ;
if ( ! V_30 ) {
V_103 ++ ;
}
}
if ( V_41 ) {
T_1 V_73 = 0 ;
V_106 . V_107 = V_35 ? F_8 ( V_108 ) : F_8 ( V_109 ) ;
V_106 . V_82 = V_35 ? F_8 ( V_109 ) : F_8 ( V_108 ) ;
V_106 . V_110 = F_15 ( V_111 ) ;
V_106 . V_83 = F_15 ( 0 ) ;
V_106 . V_83 = F_9 ( ( V_9 * ) & V_106 , sizeof( V_106 ) , ~ 0 ) ;
if ( V_92 ) {
V_106 . V_83 = F_9 ( ( V_9 * ) & V_95 , sizeof( V_95 ) , V_106 . V_83 ) ;
V_106 . V_83 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_106 . V_83 ) ;
V_106 . V_83 = F_9 ( ( V_9 * ) & V_73 , V_31 , V_106 . V_83 ) ;
} else {
V_106 . V_83 = F_9 ( ( V_9 * ) V_7 + V_10 , V_28 - V_10 , V_106 . V_83 ) ;
}
V_106 . V_83 = F_11 ( V_106 . V_83 ) ;
V_106 . V_83 = F_15 ( V_106 . V_83 ) ;
F_4 ( ( const char * ) & V_106 , sizeof( V_106 ) ) ;
}
if ( V_92 ) {
F_4 ( ( const char * ) & V_95 , sizeof( V_95 ) ) ;
}
V_8 = V_28 ;
if ( V_92 && ( V_31 > 0 ) ) {
memset ( V_112 , 0 , V_31 ) ;
F_4 ( ( const char * ) & V_112 , V_31 ) ;
V_28 += V_31 ;
}
if ( V_42 && ( V_28 < 60 ) ) {
memset ( V_112 , 0 , 60 - V_28 ) ;
F_4 ( ( const char * ) & V_112 , 60 - V_28 ) ;
V_28 = 60 ;
}
if ( V_113 ) {
V_34 = F_16 ( V_114 ,
NULL ,
V_115 , V_116 ,
V_28 , V_28 ,
0 ,
1000000000 ,
V_7 , V_37 ,
& V_117 , & V_32 ) ;
} else {
V_34 = F_17 ( V_114 ,
V_115 , V_116 / 1000 ,
V_28 , V_28 ,
V_7 ,
& V_117 , & V_32 ) ;
}
if ( ! V_34 ) {
fprintf ( V_5 , L_3 ,
V_118 , F_18 ( V_32 ) ) ;
exit ( 1 ) ;
}
if ( V_119 == NULL ) {
if ( V_113 )
V_116 ++ ;
else
V_116 += 1000 ;
}
if ( ! V_120 ) {
fprintf ( V_5 , L_4 , V_28 ) ;
}
V_121 ++ ;
}
V_94 += V_8 - V_10 ;
V_8 = V_10 ;
return;
}
static void
F_19 ( void )
{
int V_32 ;
T_3 V_34 ;
if ( V_113 ) {
char * V_122 ;
char * V_123 ;
V_122 = F_20 ( L_5 , F_21 () ) ;
V_123 = F_20 ( L_6 , V_124 ) ;
V_34 = F_22 ( V_114 ,
V_123 ,
NULL ,
NULL ,
V_122 ,
- 1 ,
& V_117 ,
& V_32 ) ;
F_23 ( V_122 ) ;
F_23 ( V_123 ) ;
if ( V_34 ) {
V_34 = F_24 ( V_114 ,
NULL ,
NULL ,
NULL ,
L_7 ,
NULL ,
V_125 ,
V_126 ,
& V_117 ,
0 ,
9 ,
& V_32 ) ;
}
} else {
V_34 = F_25 ( V_114 , V_125 ,
V_126 , FALSE ,
& V_117 , & V_32 ) ;
}
if ( ! V_34 ) {
fprintf ( V_5 , L_3 ,
V_118 , F_18 ( V_32 ) ) ;
exit ( 1 ) ;
}
}
static void
F_26 ( void )
{
int V_32 ;
T_3 V_34 ;
if ( V_113 ) {
V_34 = F_27 ( V_114 ,
0 ,
& V_117 ,
L_8 ,
0 ,
0 ,
V_121 ,
V_121 - V_121 ,
& V_32 ) ;
} else {
V_34 = TRUE ;
}
if ( ! V_34 ) {
fprintf ( V_5 , L_3 ,
V_118 , F_18 ( V_32 ) ) ;
exit ( 1 ) ;
}
return;
}
static void
F_28 ( char * V_1 )
{
T_4 V_127 ;
if ( V_128 != 0 ) {
if ( V_128 == V_129 )
return;
V_130 [ V_128 ++ ] = ' ' ;
}
V_127 = strlen ( V_1 ) ;
if ( V_127 != 0 ) {
if ( V_128 + V_127 > V_129 )
return;
F_29 ( & V_130 [ V_128 ] , V_1 , V_129 ) ;
V_128 += ( int ) V_127 ;
if ( V_131 >= 2 ) {
char * V_4 ;
char V_132 [ V_129 ] ;
F_29 ( V_132 , V_130 , V_129 ) ;
while ( ( V_4 = strchr ( V_132 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_9 , V_132 ) ;
}
}
}
static void
F_30 ( void )
{
struct V_133 V_134 ;
char * V_135 ;
char * V_136 ;
int V_137 ;
int V_14 ;
V_130 [ V_128 ] = '\0' ;
if ( V_131 > 0 )
fprintf ( V_5 , L_10 , V_130 ) ;
if ( V_36 ) {
switch ( V_130 [ 0 ] ) {
case 'i' :
case 'I' :
V_37 = 0x00000001 ;
V_130 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_37 = 0x00000002 ;
V_130 [ 0 ] = ' ' ;
break;
default:
V_37 = 0x00000000 ;
break;
}
V_14 = 0 ;
while ( V_130 [ V_14 ] == ' ' ||
V_130 [ V_14 ] == '\r' ||
V_130 [ V_14 ] == '\t' ) {
V_14 ++ ;
}
V_128 -= V_14 ;
memmove ( V_130 , V_130 + V_14 , V_128 + 1 ) ;
}
if ( V_119 == NULL ) {
V_128 = 0 ;
return;
}
V_134 = V_138 ;
V_116 = 0 ;
if ( strlen ( V_130 ) > 2 ) {
V_135 = strptime ( V_130 , V_119 , & V_134 ) ;
if ( V_135 != NULL ) {
V_115 = mktime ( & V_134 ) ;
} else
V_115 = - 1 ;
if ( - 1 == V_115 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_130 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_11 ,
V_130 , V_119 ) ;
if ( V_131 >= 2 ) {
fprintf ( V_5 , L_12 ,
V_134 . V_139 , V_134 . V_140 , V_134 . V_141 ,
V_134 . V_142 , V_134 . V_143 , V_134 . V_144 , V_134 . V_145 ) ;
}
V_115 = 0 ;
V_116 = 0 ;
} else {
V_116 = ( T_1 ) strtol ( V_135 , & V_136 , 10 ) ;
if ( V_135 == V_136 ) {
V_116 = 0 ;
} else {
V_137 = ( int ) ( V_136 - V_135 ) ;
if ( V_137 > 9 ) {
for ( V_14 = V_137 - 9 ; V_14 != 0 ; V_14 -- )
V_116 /= 10 ;
} else if ( V_137 < 9 ) {
for ( V_14 = 9 - V_137 ; V_14 != 0 ; V_14 -- )
V_116 *= 10 ;
}
}
}
}
if ( V_131 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_130 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_10 , V_130 ) ;
fprintf ( V_5 , L_13 , V_119 , ( T_1 ) V_115 , V_116 ) ;
}
V_128 = 0 ;
}
static void
F_3 ( T_3 V_30 )
{
if ( V_131 >= 1 )
fprintf ( V_5 , L_14 , V_30 ? L_15 : L_16 ) ;
F_13 ( V_30 ) ;
V_146 ++ ;
F_30 () ;
}
static void
F_31 ( char * V_1 )
{
fprintf ( V_5 , L_17 , V_1 + 10 ) ;
}
void
F_32 ( T_5 V_147 , char * V_1 )
{
T_1 V_3 ;
int V_148 ;
int V_149 = 0 ;
int V_150 ;
int V_14 ;
char * V_151 ;
char V_152 [ 3 ] ;
if ( V_131 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_5 , L_18 ,
V_153 [ V_154 ] , V_155 [ V_147 ] , V_1 ? V_1 : L_7 ) ;
}
switch ( V_154 ) {
case V_156 :
if ( ! V_1 && V_147 != V_157 ) goto V_158;
switch ( V_147 ) {
case V_159 :
F_28 ( V_1 ) ;
break;
case V_160 :
F_31 ( V_1 ) ;
break;
case V_161 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_154 = V_162 ;
V_163 = V_7 + V_3 ;
}
break;
case V_157 :
V_154 = V_164 ;
break;
default:
break;
}
break;
case V_164 :
if ( ! V_1 && V_147 != V_157 ) goto V_158;
switch ( V_147 ) {
case V_159 :
F_28 ( V_1 ) ;
break;
case V_160 :
F_31 ( V_1 ) ;
break;
case V_161 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 ( FALSE ) ;
V_94 = 0 ;
V_154 = V_162 ;
} else if ( ( V_3 - V_94 ) != V_8 - V_10 ) {
if ( V_3 < V_8 ) {
F_5 ( V_8 - V_3 ) ;
V_154 = V_162 ;
} else {
if ( V_131 >= 1 )
fprintf ( V_5 , L_19 ,
V_8 , V_3 ) ;
F_13 ( FALSE ) ;
V_154 = V_156 ;
}
} else
V_154 = V_162 ;
V_163 = V_7 + V_3 ;
break;
case V_157 :
V_154 = V_164 ;
break;
default:
break;
}
break;
case V_162 :
switch ( V_147 ) {
case V_165 :
V_154 = V_166 ;
if ( ! V_1 ) goto V_158;
F_2 ( V_1 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
V_154 = V_167 ;
break;
case V_157 :
V_154 = V_164 ;
break;
default:
break;
}
break;
case V_166 :
switch ( V_147 ) {
case V_165 :
F_2 ( V_1 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
case V_157 :
V_148 = 0 ;
V_154 = V_167 ;
if ( V_147 == V_157 ) {
V_148 = 1 ;
V_154 = V_164 ;
}
if ( V_168 ) {
V_149 = 0 ;
V_150 = V_8 - ( int ) ( V_163 - V_7 ) ;
V_151 = ( char * ) F_33 ( ( V_150 + 1 ) / 4 + 1 ) ;
for ( V_14 = 0 ; V_14 < ( V_150 + 1 ) / 4 ; V_14 ++ ) {
V_152 [ 0 ] = V_163 [ V_14 * 3 ] ;
V_152 [ 1 ] = V_163 [ V_14 * 3 + 1 ] ;
V_152 [ 2 ] = '\0' ;
if ( ! F_34 ( V_152 [ 0 ] ) || ! F_34 ( V_152 [ 1 ] ) ) {
break;
}
V_151 [ V_14 ] = ( char ) strtoul ( V_152 , ( char * * ) NULL , 16 ) ;
V_149 ++ ;
if ( ! ( V_163 [ V_14 * 3 + 2 ] == ' ' ) ) {
if ( V_148 != 1 )
V_149 -- ;
break;
}
}
if ( V_149 > 0 ) {
if ( strncmp ( V_163 + V_150 - V_149 , V_151 , V_149 ) == 0 ) {
F_5 ( V_149 ) ;
}
else {
F_5 ( V_150 ) ;
}
}
F_23 ( V_151 ) ;
}
break;
default:
break;
}
break;
case V_167 :
switch ( V_147 ) {
case V_157 :
V_154 = V_164 ;
break;
default:
break;
}
break;
default:
fprintf ( V_5 , L_20 , V_154 ) ;
exit ( 1 ) ;
}
if ( V_131 >= 2 )
fprintf ( V_5 , L_21 , V_153 [ V_154 ] ) ;
return;
V_158:
fprintf ( V_5 , L_22 , V_154 ) ;
exit ( 1 ) ;
}
static void
F_35 ( T_6 * V_169 )
{
fprintf ( V_169 ,
L_23
L_24
L_23
L_25
L_26
L_23
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
L_46
L_47
L_48
L_23
L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_23
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
L_68
L_66
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
L_23
L_85
L_86
L_87
L_88
L_89
L_7 ,
V_15 ) ;
}
static void
F_36 ( T_7 * V_1 )
{
F_37 ( V_1 , L_90 ) ;
#ifdef F_38
F_37 ( V_1 , L_91 ) ;
#ifdef F_39
F_37 ( V_1 , F_39 ) ;
#else
F_37 ( V_1 , L_92 ) ;
#endif
#else
F_37 ( V_1 , L_93 ) ;
#endif
}
static void
F_40 ( T_7 * V_1 )
{
#if F_41 ( F_38 ) && ! F_41 ( V_170 )
F_42 ( V_1 , L_94 , F_43 () ) ;
#endif
}
static void
F_44 ( int V_171 , char * V_172 [] )
{
T_7 * V_173 ;
T_7 * V_174 ;
int V_4 ;
char * V_136 ;
F_45 (cast-qual)
static const struct V_175 V_176 [] = {
{ ( char * ) L_95 , V_177 , NULL , 'h' } ,
{ ( char * ) L_96 , V_177 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_46 (cast-qual)
#ifdef V_170
F_47 ( V_171 , V_172 ) ;
F_48 () ;
#endif
V_173 = F_49 ( NULL , F_36 ) ;
V_174 = F_50 ( F_40 ) ;
F_51 ( L_97
L_23
L_98
L_23
L_98 ,
F_21 () , V_173 -> V_1 , V_174 -> V_1 ) ;
while ( ( V_4 = F_52 ( V_171 , V_172 , L_99 , V_176 , NULL ) ) != - 1 ) {
switch ( V_4 ) {
case 'h' :
printf ( L_97
L_100
L_101 ,
F_21 () ) ;
F_35 ( stdout ) ;
exit ( 0 ) ;
break;
case 'd' : if ( ! V_120 ) V_131 ++ ; break;
case 'D' : V_36 = TRUE ; break;
case 'q' : V_120 = TRUE ; V_131 = FALSE ; break;
case 'l' : V_125 = ( T_1 ) strtol ( V_178 , NULL , 0 ) ; break;
case 'm' : V_11 = ( T_1 ) strtol ( V_178 , NULL , 0 ) ; break;
case 'n' : V_113 = TRUE ; break;
case 'o' :
if ( V_178 [ 0 ] != 'h' && V_178 [ 0 ] != 'o' && V_178 [ 0 ] != 'd' ) {
fprintf ( V_5 , L_102 , V_178 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
switch ( V_178 [ 0 ] ) {
case 'o' : V_6 = 8 ; break;
case 'h' : V_6 = 16 ; break;
case 'd' : V_6 = 10 ; break;
}
break;
case 'e' :
V_42 = TRUE ;
if ( sscanf ( V_178 , L_103 , & V_39 ) < 1 ) {
fprintf ( V_5 , L_104 , V_178 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
break;
case 'i' :
V_40 = TRUE ;
V_55 = strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || * V_136 != '\0' || V_55 < 0 ||
V_55 > 255 ) {
fprintf ( V_5 , L_105 , V_178 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_42 = TRUE ;
V_39 = 0x800 ;
break;
case 's' :
V_41 = TRUE ;
V_92 = FALSE ;
V_84 = FALSE ;
V_76 = FALSE ;
V_109 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_106 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_107 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_108 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_108 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_109 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_111 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || * V_136 != '\0' ) {
fprintf ( V_5 , L_110 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_40 = TRUE ;
V_55 = 132 ;
V_42 = TRUE ;
V_39 = 0x800 ;
break;
case 'S' :
V_41 = TRUE ;
V_92 = TRUE ;
V_84 = FALSE ;
V_76 = FALSE ;
V_109 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_106 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_107 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_108 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_108 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_111 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_105 = ( T_1 ) strtoul ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || * V_136 != '\0' ) {
fprintf ( V_5 , L_112 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_40 = TRUE ;
V_55 = 132 ;
V_42 = TRUE ;
V_39 = 0x800 ;
break;
case 't' :
V_119 = V_178 ;
break;
case 'u' :
V_76 = TRUE ;
V_84 = FALSE ;
V_41 = FALSE ;
V_92 = FALSE ;
V_81 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_113 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_114 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_80 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || * V_136 != '\0' ) {
fprintf ( V_5 , L_115 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_40 = TRUE ;
V_55 = 17 ;
V_42 = TRUE ;
V_39 = 0x800 ;
break;
case 'T' :
V_84 = TRUE ;
V_76 = FALSE ;
V_41 = FALSE ;
V_92 = FALSE ;
V_81 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || ( * V_136 != ',' && * V_136 != '\0' ) ) {
fprintf ( V_5 , L_116 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_114 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_136 ++ ;
V_178 = V_136 ;
V_80 = ( T_1 ) strtol ( V_178 , & V_136 , 10 ) ;
if ( V_136 == V_178 || * V_136 != '\0' ) {
fprintf ( V_5 , L_117 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
V_40 = TRUE ;
V_55 = 6 ;
V_42 = TRUE ;
V_39 = 0x800 ;
break;
case 'a' :
V_168 = TRUE ;
break;
case 'v' :
F_53 ( L_118 , V_173 , V_174 ) ;
F_54 ( V_173 , TRUE ) ;
F_54 ( V_174 , TRUE ) ;
exit ( 0 ) ;
break;
case '4' :
case '6' :
V_136 = strchr ( V_178 , ',' ) ;
if ( ! V_136 ) {
fprintf ( V_5 , L_119 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
* V_136 = '\0' ;
if ( V_4 == '6' )
{
V_38 = TRUE ;
V_39 = 0x86DD ;
}
else
{
V_40 = TRUE ;
V_39 = 0x800 ;
}
V_42 = TRUE ;
if ( V_38 == TRUE ) {
if ( F_55 ( V_179 , V_178 , V_58 ) <= 0 ) {
fprintf ( V_5 , L_120 , V_4 , V_136 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
} else {
if ( F_55 ( V_180 , V_178 , & V_50 ) <= 0 ) {
fprintf ( V_5 , L_120 , V_4 , V_136 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
}
V_136 ++ ;
if ( * V_136 == '\0' ) {
fprintf ( V_5 , L_121 , V_4 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( V_38 == TRUE ) {
if ( F_55 ( V_179 , V_136 , V_57 ) <= 0 ) {
fprintf ( V_5 , L_122 , V_4 , V_136 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
} else {
if ( F_55 ( V_180 , V_136 , & V_47 ) <= 0 ) {
fprintf ( V_5 , L_122 , V_4 , V_136 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
}
break;
case '?' :
default:
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
}
if ( V_181 >= V_171 || V_171 - V_181 < 2 ) {
fprintf ( V_5 , L_123 ) ;
F_35 ( V_5 ) ;
exit ( 1 ) ;
}
if ( strcmp ( V_172 [ V_181 ] , L_124 ) ) {
V_124 = F_56 ( V_172 [ V_181 ] ) ;
V_182 = F_57 ( V_124 , L_125 ) ;
if ( ! V_182 ) {
fprintf ( V_5 , L_126 ,
V_124 , F_18 ( V_183 ) ) ;
exit ( 1 ) ;
}
} else {
V_124 = L_127 ;
V_182 = V_184 ;
}
if ( strcmp ( V_172 [ V_181 + 1 ] , L_124 ) ) {
V_118 = F_56 ( V_172 [ V_181 + 1 ] ) ;
V_114 = F_57 ( V_118 , L_128 ) ;
if ( ! V_114 ) {
fprintf ( V_5 , L_129 ,
V_118 , F_18 ( V_183 ) ) ;
exit ( 1 ) ;
}
} else {
V_118 = L_130 ;
V_114 = stdout ;
}
if ( V_125 != 1 && V_42 ) {
fprintf ( V_5 , L_131 ) ;
exit ( 1 ) ;
}
if ( ! V_182 ) {
V_182 = V_184 ;
V_124 = L_127 ;
}
if ( ! V_114 ) {
V_114 = stdout ;
V_118 = L_130 ;
}
V_115 = time ( 0 ) ;
V_138 = * localtime ( & V_115 ) ;
V_138 . V_145 = - 1 ;
if ( ! V_120 ) {
fprintf ( V_5 , L_132 , V_124 ) ;
fprintf ( V_5 , L_133 , V_118 ) ;
fprintf ( V_5 , L_134 , V_113 ? L_135 : L_136 ) ;
if ( V_42 ) fprintf ( V_5 , L_137 ,
V_39 ) ;
if ( V_40 ) fprintf ( V_5 , L_138 ,
V_55 ) ;
if ( V_76 ) fprintf ( V_5 , L_139 ,
V_81 , V_80 ) ;
if ( V_84 ) fprintf ( V_5 , L_140 ,
V_81 , V_80 ) ;
if ( V_41 ) fprintf ( V_5 , L_141 ,
V_109 , V_108 , V_111 ) ;
if ( V_92 ) fprintf ( V_5 , L_142 ,
V_99 , V_101 , V_103 , V_105 ) ;
}
}
int
main ( int V_171 , char * V_172 [] )
{
F_44 ( V_171 , V_172 ) ;
assert ( V_182 != NULL ) ;
assert ( V_114 != NULL ) ;
F_19 () ;
V_10 = 0 ;
if ( V_42 ) {
V_10 += ( int ) sizeof( V_43 ) ;
}
if ( V_40 ) {
V_53 = V_10 ;
V_10 += ( int ) sizeof( V_45 ) ;
} else if ( V_38 ) {
V_53 = V_10 ;
V_10 += ( int ) sizeof( V_61 ) ;
}
if ( V_41 ) {
V_10 += ( int ) sizeof( V_106 ) ;
}
if ( V_92 ) {
V_10 += ( int ) sizeof( V_95 ) ;
}
if ( V_84 ) {
V_10 += ( int ) sizeof( V_85 ) ;
}
if ( V_76 ) {
V_10 += ( int ) sizeof( V_75 ) ;
}
V_8 = V_10 ;
V_185 = V_182 ;
F_58 () ;
F_13 ( FALSE ) ;
F_26 () ;
fclose ( V_182 ) ;
fclose ( V_114 ) ;
if ( V_131 )
fprintf ( V_5 , L_143 ) ;
if ( ! V_120 ) {
fprintf ( V_5 , L_144 V_186 L_145 ,
V_146 , ( V_146 == 1 ) ? L_7 : L_146 ,
V_121 , ( V_121 == 1 ) ? L_7 : L_146 ,
V_117 , ( V_117 == 1 ) ? L_7 : L_146 ) ;
}
return 0 ;
}
