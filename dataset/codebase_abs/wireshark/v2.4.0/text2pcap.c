static int
F_1 ( const char * V_1 , int V_2 , T_1 * V_3 )
{
char * V_4 ;
if ( V_1 == NULL ) {
fprintf ( V_5 , L_1 ) ;
return V_6 ;
}
* V_3 = ( T_1 ) strtoul ( V_1 , & V_4 , V_2 ? V_7 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_5 , L_2 , V_1 ) ;
return V_6 ;
}
return V_8 ;
}
static int
F_2 ( const char * V_1 )
{
T_1 V_3 ;
if ( F_1 ( V_1 , FALSE , & V_3 ) != V_8 )
return V_6 ;
V_9 [ V_10 ] = ( V_11 ) V_3 ;
V_10 ++ ;
if ( V_10 - V_12 >= V_13 )
if ( F_3 ( TRUE ) != V_8 )
return V_6 ;
return V_8 ;
}
static void
F_4 ( const char V_14 [] , T_1 V_15 )
{
T_1 V_16 ;
if ( V_10 + V_15 < V_17 ) {
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
V_9 [ V_10 ] = V_14 [ V_16 ] ;
V_10 ++ ;
}
}
}
static void
F_5 ( T_1 V_15 )
{
V_10 -= V_15 ;
}
static T_2
F_6 ( void * V_18 , T_1 V_19 )
{
T_1 V_20 = 0 ;
T_2 * V_21 = ( T_2 * ) V_18 ;
while ( V_19 > 1 ) {
V_20 += F_7 ( * ( T_2 * ) V_21 ) ;
V_21 ++ ;
V_19 -= 2 ;
}
if ( V_19 > 0 )
V_20 += F_7 ( * ( V_11 * ) V_21 ) ;
while ( V_20 >> 16 )
V_20 = ( V_20 & 0xffff ) + ( V_20 >> 16 ) ;
V_20 = ~ V_20 ;
return F_8 ( V_20 ) ;
}
static T_1
F_9 ( const V_11 * V_18 , unsigned int V_22 , T_1 V_23 )
{
unsigned int V_16 ;
T_1 V_24 ;
V_24 = V_23 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ )
F_10 ( V_24 , V_18 [ V_16 ] ) ;
return V_24 ;
}
static T_1
F_11 ( T_1 V_24 )
{
T_1 V_25 ;
V_11 V_26 , V_27 , V_28 , V_29 ;
V_25 = ~ V_24 ;
V_26 = V_25 & 0xff ;
V_27 = ( V_25 >> 8 ) & 0xff ;
V_28 = ( V_25 >> 16 ) & 0xff ;
V_29 = ( V_25 >> 24 ) & 0xff ;
V_25 = ( ( V_26 << 24 ) | ( V_27 << 16 ) | ( V_28 << 8 ) | V_29 ) ;
return V_25 ;
}
static T_2
F_12 ( T_1 V_30 )
{
T_2 V_31 ;
V_31 = V_30 % 4 ;
if ( V_31 == 0 )
return 0 ;
else
return 4 - V_31 ;
}
static int
F_13 ( T_3 V_32 )
{
T_1 V_30 = 0 ;
T_2 V_33 = 0 ;
int V_34 ;
T_2 V_35 ;
T_3 V_36 ;
if ( V_10 > V_12 ) {
T_3 V_37 = V_38 && ( V_39 == 2 ) ;
if ( V_40 ) {
V_41 = 0x86DD ;
V_42 = FALSE ;
}
V_30 = V_10 ;
if ( V_43 ) {
V_33 = F_12 ( V_30 - V_12 ) ;
} else {
V_33 = 0 ;
}
V_10 = 0 ;
if ( V_44 ) {
V_45 . V_46 = F_8 ( V_41 ) ;
F_4 ( ( const char * ) & V_45 , sizeof( V_45 ) ) ;
}
if ( V_42 ) {
if ( V_37 ) {
V_47 . V_48 = V_49 ? V_49 : V_50 ;
V_47 . V_51 = V_52 ? V_52 : V_53 ;
}
else {
V_47 . V_48 = V_52 ? V_52 : V_53 ;
V_47 . V_51 = V_49 ? V_49 : V_50 ;
}
V_47 . V_54 = F_8 ( V_30 - V_55 + V_33 ) ;
V_47 . V_56 = ( V_11 ) V_57 ;
V_47 . V_58 = 0 ;
V_47 . V_58 = F_6 ( & V_47 , sizeof( V_47 ) ) ;
F_4 ( ( const char * ) & V_47 , sizeof( V_47 ) ) ;
} else if ( V_40 ) {
if ( memcmp ( V_37 ? & V_59 : & V_60 , & V_61 , sizeof( struct V_62 ) ) )
memcpy ( & V_63 . V_64 , V_37 ? & V_59 : & V_60 , sizeof( struct V_62 ) ) ;
if ( memcmp ( V_37 ? & V_60 : & V_59 , & V_61 , sizeof( struct V_62 ) ) )
memcpy ( & V_63 . V_65 , V_37 ? & V_60 : & V_59 , sizeof( struct V_62 ) ) ;
V_63 . V_66 . V_67 &= 0x0F ;
V_63 . V_66 . V_67 |= ( 6 << 4 ) ;
V_63 . V_66 . V_68 . V_69 = F_8 ( V_30 - V_55 + V_33 ) ;
V_63 . V_66 . V_68 . V_70 = ( V_11 ) V_57 ;
V_63 . V_66 . V_68 . V_71 = 32 ;
F_4 ( ( const char * ) & V_63 , sizeof( V_63 ) ) ;
V_72 . V_73 = V_63 . V_64 ;
V_72 . V_74 = V_63 . V_65 ;
V_72 . V_75 = 0 ;
V_72 . V_56 = ( V_11 ) V_57 ;
V_35 = F_7 ( V_63 . V_66 . V_68 . V_69 ) ;
V_76 . V_30 = F_8 ( V_30 - V_35 + sizeof( V_77 ) ) ;
}
if ( ! V_40 ) {
V_76 . V_48 = V_47 . V_48 ;
V_76 . V_51 = V_47 . V_51 ;
V_76 . V_75 = 0 ;
V_76 . V_56 = ( V_11 ) V_57 ;
V_76 . V_30 = F_8 ( V_30 - V_12 + sizeof( V_77 ) ) ;
}
if ( V_78 ) {
T_2 V_79 ;
T_1 V_80 ;
V_77 . V_81 = V_37 ? F_8 ( V_82 ) : F_8 ( V_83 ) ;
V_77 . V_84 = V_37 ? F_8 ( V_83 ) : F_8 ( V_82 ) ;
V_77 . V_30 = V_76 . V_30 ;
V_77 . V_85 = 0 ;
V_79 = V_40 ? F_6 ( & V_72 , sizeof( V_72 ) ) : F_6 ( & V_76 , sizeof( V_76 ) ) ;
V_80 = F_7 ( V_79 ) ;
V_79 = F_6 ( & V_77 , sizeof( V_77 ) ) ;
V_80 += F_7 ( V_79 ) ;
V_79 = F_6 ( V_9 + V_12 , V_30 - V_12 ) ;
V_80 += F_7 ( V_79 ) ;
V_79 = ( V_80 & 0xffff ) + ( V_80 >> 16 ) ;
V_77 . V_85 = F_8 ( V_79 ) ;
if ( V_77 . V_85 == 0 )
V_77 . V_85 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_77 , sizeof( V_77 ) ) ;
}
if ( V_86 ) {
T_2 V_79 ;
T_1 V_80 ;
V_76 . V_48 = V_47 . V_48 ;
V_76 . V_51 = V_47 . V_51 ;
V_76 . V_75 = 0 ;
V_76 . V_56 = ( V_11 ) V_57 ;
V_76 . V_30 = F_8 ( V_30 - V_12 + sizeof( V_87 ) ) ;
V_87 . V_81 = V_37 ? F_8 ( V_82 ) : F_8 ( V_83 ) ;
V_87 . V_84 = V_37 ? F_8 ( V_83 ) : F_8 ( V_82 ) ;
if ( V_38 ) {
V_87 . V_88 = 0x10 ;
V_87 . V_89 = F_14 ( V_37 ? V_90 : V_91 ) ;
V_87 . V_89 = F_15 ( V_87 . V_89 ) ;
}
else {
V_87 . V_88 = 0 ;
V_87 . V_89 = 0 ;
}
V_87 . V_92 = V_37 ? V_91 : V_90 ;
V_87 . V_93 = F_8 ( 0x2000 ) ;
V_87 . V_85 = 0 ;
V_79 = F_6 ( & V_76 , sizeof( V_76 ) ) ;
V_80 = F_7 ( V_79 ) ;
V_79 = F_6 ( & V_87 , sizeof( V_87 ) ) ;
V_80 += F_7 ( V_79 ) ;
V_79 = F_6 ( V_9 + V_12 , V_30 - V_12 ) ;
V_80 += F_7 ( V_79 ) ;
V_79 = ( V_80 & 0xffff ) + ( V_80 >> 16 ) ;
V_87 . V_85 = F_8 ( V_79 ) ;
if ( V_87 . V_85 == 0 )
V_87 . V_85 = F_8 ( 1 ) ;
F_4 ( ( const char * ) & V_87 , sizeof( V_87 ) ) ;
if ( V_37 ) {
V_91 = F_14 ( V_91 ) + V_30 - V_12 ;
V_91 = F_15 ( V_91 ) ;
}
else {
V_90 = F_14 ( V_90 ) + V_30 - V_12 ;
V_90 = F_15 ( V_90 ) ;
}
}
if ( V_94 ) {
V_95 = 0 ;
if ( V_96 == 0 ) {
V_95 |= 0x02 ;
}
if ( ! V_32 ) {
V_95 |= 0x01 ;
}
V_97 . type = V_98 ;
V_97 . V_99 = V_95 ;
V_97 . V_30 = F_8 ( V_30 - V_12 + sizeof( V_97 ) ) ;
V_97 . V_100 = F_15 ( V_101 ) ;
V_97 . V_102 = F_8 ( V_103 ) ;
V_97 . V_104 = F_8 ( V_105 ) ;
V_97 . V_106 = F_15 ( V_107 ) ;
V_101 ++ ;
if ( ! V_32 ) {
V_105 ++ ;
}
}
if ( V_43 ) {
T_1 V_75 = 0 ;
V_108 . V_109 = V_37 ? F_8 ( V_110 ) : F_8 ( V_111 ) ;
V_108 . V_84 = V_37 ? F_8 ( V_111 ) : F_8 ( V_110 ) ;
V_108 . V_112 = F_15 ( V_113 ) ;
V_108 . V_85 = F_15 ( 0 ) ;
V_108 . V_85 = F_9 ( ( V_11 * ) & V_108 , sizeof( V_108 ) , ~ 0 ) ;
if ( V_94 ) {
V_108 . V_85 = F_9 ( ( V_11 * ) & V_97 , sizeof( V_97 ) , V_108 . V_85 ) ;
V_108 . V_85 = F_9 ( ( V_11 * ) V_9 + V_12 , V_30 - V_12 , V_108 . V_85 ) ;
V_108 . V_85 = F_9 ( ( V_11 * ) & V_75 , V_33 , V_108 . V_85 ) ;
} else {
V_108 . V_85 = F_9 ( ( V_11 * ) V_9 + V_12 , V_30 - V_12 , V_108 . V_85 ) ;
}
V_108 . V_85 = F_11 ( V_108 . V_85 ) ;
V_108 . V_85 = F_15 ( V_108 . V_85 ) ;
F_4 ( ( const char * ) & V_108 , sizeof( V_108 ) ) ;
}
if ( V_94 ) {
F_4 ( ( const char * ) & V_97 , sizeof( V_97 ) ) ;
}
V_10 = V_30 ;
if ( V_94 && ( V_33 > 0 ) ) {
memset ( V_114 , 0 , V_33 ) ;
F_4 ( ( const char * ) & V_114 , V_33 ) ;
V_30 += V_33 ;
}
if ( V_44 && ( V_30 < 60 ) ) {
memset ( V_114 , 0 , 60 - V_30 ) ;
F_4 ( ( const char * ) & V_114 , 60 - V_30 ) ;
V_30 = 60 ;
}
if ( V_115 ) {
V_36 = F_16 ( V_116 ,
NULL ,
V_117 , V_118 ,
V_30 , V_30 ,
0 ,
1000000000 ,
V_9 , V_39 ,
& V_119 , & V_34 ) ;
} else {
V_36 = F_17 ( V_116 ,
V_117 , V_118 / 1000 ,
V_30 , V_30 ,
V_9 ,
& V_119 , & V_34 ) ;
}
if ( ! V_36 ) {
fprintf ( V_5 , L_3 ,
V_120 , F_18 ( V_34 ) ) ;
return V_6 ;
}
if ( V_121 == NULL ) {
if ( V_115 )
V_118 ++ ;
else
V_118 += 1000 ;
}
if ( ! V_122 ) {
fprintf ( V_5 , L_4 , V_30 ) ;
}
V_123 ++ ;
}
V_96 += V_10 - V_12 ;
V_10 = V_12 ;
return V_8 ;
}
static int
F_19 ( void )
{
int V_34 ;
T_3 V_36 ;
if ( V_115 ) {
char * V_124 ;
char * V_125 ;
V_124 = F_20 ( L_5 , F_21 () ) ;
V_125 = F_20 ( L_6 , V_126 ) ;
V_36 = F_22 ( V_116 ,
V_125 ,
NULL ,
NULL ,
V_124 ,
- 1 ,
& V_119 ,
& V_34 ) ;
F_23 ( V_124 ) ;
F_23 ( V_125 ) ;
if ( V_36 ) {
V_36 = F_24 ( V_116 ,
NULL ,
NULL ,
NULL ,
L_7 ,
NULL ,
V_127 ,
V_128 ,
& V_119 ,
0 ,
9 ,
& V_34 ) ;
}
} else {
V_36 = F_25 ( V_116 , V_127 ,
V_128 , FALSE ,
& V_119 , & V_34 ) ;
}
if ( ! V_36 ) {
fprintf ( V_5 , L_3 ,
V_120 , F_18 ( V_34 ) ) ;
return V_6 ;
}
return V_8 ;
}
static void
F_26 ( char * V_1 )
{
T_4 V_129 ;
if ( V_130 != 0 ) {
if ( V_130 == V_131 )
return;
V_132 [ V_130 ++ ] = ' ' ;
}
V_129 = strlen ( V_1 ) ;
if ( V_129 != 0 ) {
if ( V_130 + V_129 > V_131 )
return;
F_27 ( & V_132 [ V_130 ] , V_1 , V_131 ) ;
V_130 += ( int ) V_129 ;
if ( V_133 >= 2 ) {
char * V_4 ;
char V_134 [ V_131 ] ;
F_27 ( V_134 , V_132 , V_131 ) ;
while ( ( V_4 = strchr ( V_134 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_8 , V_134 ) ;
}
}
}
static void
F_28 ( void )
{
struct V_135 V_136 ;
char * V_137 ;
char * V_138 ;
int V_139 ;
int V_16 ;
V_132 [ V_130 ] = '\0' ;
if ( V_133 > 0 )
fprintf ( V_5 , L_9 , V_132 ) ;
if ( V_38 ) {
switch ( V_132 [ 0 ] ) {
case 'i' :
case 'I' :
V_39 = 0x00000001 ;
V_132 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_39 = 0x00000002 ;
V_132 [ 0 ] = ' ' ;
break;
default:
V_39 = 0x00000000 ;
break;
}
V_16 = 0 ;
while ( V_132 [ V_16 ] == ' ' ||
V_132 [ V_16 ] == '\r' ||
V_132 [ V_16 ] == '\t' ) {
V_16 ++ ;
}
V_130 -= V_16 ;
memmove ( V_132 , V_132 + V_16 , V_130 + 1 ) ;
}
if ( V_121 == NULL ) {
V_130 = 0 ;
return;
}
V_136 = V_140 ;
V_118 = 0 ;
if ( strlen ( V_132 ) > 2 ) {
V_137 = strptime ( V_132 , V_121 , & V_136 ) ;
if ( V_137 != NULL ) {
V_117 = mktime ( & V_136 ) ;
} else
V_117 = - 1 ;
if ( - 1 == V_117 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_132 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_10 ,
V_132 , V_121 ) ;
if ( V_133 >= 2 ) {
fprintf ( V_5 , L_11 ,
V_136 . V_141 , V_136 . V_142 , V_136 . V_143 ,
V_136 . V_144 , V_136 . V_145 , V_136 . V_146 , V_136 . V_147 ) ;
}
V_117 = 0 ;
V_118 = 0 ;
} else {
V_118 = ( T_1 ) strtol ( V_137 , & V_138 , 10 ) ;
if ( V_137 == V_138 ) {
V_118 = 0 ;
} else {
V_139 = ( int ) ( V_138 - V_137 ) ;
if ( V_139 > 9 ) {
for ( V_16 = V_139 - 9 ; V_16 != 0 ; V_16 -- )
V_118 /= 10 ;
} else if ( V_139 < 9 ) {
for ( V_16 = 9 - V_139 ; V_16 != 0 ; V_16 -- )
V_118 *= 10 ;
}
}
}
}
if ( V_133 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_132 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_9 , V_132 ) ;
fprintf ( V_5 , L_12 , V_121 , ( T_1 ) V_117 , V_118 ) ;
}
V_130 = 0 ;
}
static int
F_3 ( T_3 V_32 )
{
if ( V_133 >= 1 )
fprintf ( V_5 , L_13 , V_32 ? L_14 : L_15 ) ;
if ( F_13 ( V_32 ) != V_8 )
return V_6 ;
V_148 ++ ;
F_28 () ;
return V_8 ;
}
static void
F_29 ( char * V_1 )
{
fprintf ( V_5 , L_16 , V_1 + 10 ) ;
}
int
F_30 ( T_5 V_149 , char * V_1 )
{
T_1 V_3 ;
int V_150 ;
int V_151 = 0 ;
int V_152 ;
int V_16 ;
char * V_153 ;
char V_154 [ 3 ] ;
if ( V_133 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_5 , L_17 ,
V_155 [ V_156 ] , V_157 [ V_149 ] , V_1 ? V_1 : L_7 ) ;
}
switch ( V_156 ) {
case V_158 :
if ( ! V_1 && V_149 != V_159 ) goto V_160;
switch ( V_149 ) {
case V_161 :
F_26 ( V_1 ) ;
break;
case V_162 :
F_29 ( V_1 ) ;
break;
case V_163 :
if ( F_1 ( V_1 , TRUE , & V_3 ) != V_8 )
return V_6 ;
if ( V_3 == 0 ) {
if ( F_3 ( FALSE ) != V_8 )
return V_6 ;
V_156 = V_164 ;
V_165 = V_9 + V_3 ;
}
break;
case V_159 :
V_156 = V_166 ;
break;
default:
break;
}
break;
case V_166 :
if ( ! V_1 && V_149 != V_159 ) goto V_160;
switch ( V_149 ) {
case V_161 :
F_26 ( V_1 ) ;
break;
case V_162 :
F_29 ( V_1 ) ;
break;
case V_163 :
if ( F_1 ( V_1 , TRUE , & V_3 ) != V_8 )
return V_6 ;
if ( V_3 == 0 ) {
if ( F_3 ( FALSE ) != V_8 )
return V_6 ;
V_96 = 0 ;
V_156 = V_164 ;
} else if ( ( V_3 - V_96 ) != V_10 - V_12 ) {
if ( V_3 < V_10 ) {
F_5 ( V_10 - V_3 ) ;
V_156 = V_164 ;
} else {
if ( V_133 >= 1 )
fprintf ( V_5 , L_18 ,
V_10 , V_3 ) ;
if ( F_13 ( FALSE ) != V_8 )
return V_6 ;
V_156 = V_158 ;
}
} else {
V_156 = V_164 ;
}
V_165 = V_9 + V_3 ;
break;
case V_159 :
V_156 = V_166 ;
break;
default:
break;
}
break;
case V_164 :
switch ( V_149 ) {
case V_167 :
V_156 = V_168 ;
if ( ! V_1 ) goto V_160;
if ( F_2 ( V_1 ) != V_8 )
return V_6 ;
break;
case V_161 :
case V_162 :
case V_163 :
V_156 = V_169 ;
break;
case V_159 :
V_156 = V_166 ;
break;
default:
break;
}
break;
case V_168 :
switch ( V_149 ) {
case V_167 :
if ( F_2 ( V_1 ) != V_8 )
return V_6 ;
break;
case V_161 :
case V_162 :
case V_163 :
case V_159 :
V_150 = 0 ;
V_156 = V_169 ;
if ( V_149 == V_159 ) {
V_150 = 1 ;
V_156 = V_166 ;
}
if ( V_170 ) {
V_151 = 0 ;
V_152 = V_10 - ( int ) ( V_165 - V_9 ) ;
V_153 = ( char * ) F_31 ( ( V_152 + 1 ) / 4 + 1 ) ;
for ( V_16 = 0 ; V_16 < ( V_152 + 1 ) / 4 ; V_16 ++ ) {
V_154 [ 0 ] = V_165 [ V_16 * 3 ] ;
V_154 [ 1 ] = V_165 [ V_16 * 3 + 1 ] ;
V_154 [ 2 ] = '\0' ;
if ( ! F_32 ( V_154 [ 0 ] ) || ! F_32 ( V_154 [ 1 ] ) ) {
break;
}
V_153 [ V_16 ] = ( char ) strtoul ( V_154 , ( char * * ) NULL , 16 ) ;
V_151 ++ ;
if ( ! ( V_165 [ V_16 * 3 + 2 ] == ' ' ) ) {
if ( V_150 != 1 )
V_151 -- ;
break;
}
}
if ( V_151 > 0 ) {
if ( strncmp ( V_165 + V_152 - V_151 , V_153 , V_151 ) == 0 ) {
F_5 ( V_151 ) ;
}
else {
F_5 ( V_152 ) ;
}
}
F_23 ( V_153 ) ;
}
break;
default:
break;
}
break;
case V_169 :
switch ( V_149 ) {
case V_159 :
V_156 = V_166 ;
break;
default:
break;
}
break;
default:
fprintf ( V_5 , L_19 , V_156 ) ;
return V_6 ;
}
if ( V_133 >= 2 )
fprintf ( V_5 , L_20 , V_155 [ V_156 ] ) ;
return V_8 ;
V_160:
fprintf ( V_5 , L_21 , V_156 ) ;
return V_6 ;
}
static void
F_33 ( T_6 * V_171 )
{
fprintf ( V_171 ,
L_22
L_23
L_22
L_24
L_25
L_22
L_26
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
L_22
L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_22
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
L_65
L_68
L_69
L_70
L_71
L_72
L_73
L_74
L_70
L_71
L_75
L_76
L_77
L_71
L_78
L_79
L_80
L_81
L_82
L_83
L_22
L_84
L_85
L_86
L_87
L_88
L_7 ,
V_17 ) ;
}
static int
F_34 ( int V_172 , char * V_173 [] )
{
T_7 * V_174 ;
T_7 * V_175 ;
int V_4 ;
char * V_138 ;
static const struct V_176 V_177 [] = {
{ L_89 , V_178 , NULL , 'h' } ,
{ L_90 , V_178 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_135 * V_179 ;
#ifdef F_35
F_36 ( V_172 , V_173 ) ;
F_37 () ;
#endif
V_174 = F_38 ( NULL , NULL ) ;
V_175 = F_39 ( NULL ) ;
F_40 ( L_91
L_22
L_92
L_22
L_92 ,
F_21 () , V_174 -> V_1 , V_175 -> V_1 ) ;
F_41 ( V_174 , TRUE ) ;
F_41 ( V_175 , TRUE ) ;
while ( ( V_4 = F_42 ( V_172 , V_173 , L_93 , V_177 , NULL ) ) != - 1 ) {
switch ( V_4 ) {
case 'h' :
printf ( L_91
L_94
L_95 ,
F_21 () ) ;
F_33 ( stdout ) ;
exit ( 0 ) ;
break;
case 'd' : if ( ! V_122 ) V_133 ++ ; break;
case 'D' : V_38 = TRUE ; break;
case 'q' : V_122 = TRUE ; V_133 = FALSE ; break;
case 'l' : V_127 = ( T_1 ) strtol ( V_180 , NULL , 0 ) ; break;
case 'm' : V_13 = ( T_1 ) strtol ( V_180 , NULL , 0 ) ; break;
case 'n' : V_115 = TRUE ; break;
case 'o' :
if ( V_180 [ 0 ] != 'h' && V_180 [ 0 ] != 'o' && V_180 [ 0 ] != 'd' ) {
fprintf ( V_5 , L_96 , V_180 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
switch ( V_180 [ 0 ] ) {
case 'o' : V_7 = 8 ; break;
case 'h' : V_7 = 16 ; break;
case 'd' : V_7 = 10 ; break;
}
break;
case 'e' :
V_44 = TRUE ;
if ( sscanf ( V_180 , L_97 , & V_41 ) < 1 ) {
fprintf ( V_5 , L_98 , V_180 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
break;
case 'i' :
V_42 = TRUE ;
V_57 = strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || * V_138 != '\0' || V_57 < 0 ||
V_57 > 255 ) {
fprintf ( V_5 , L_99 , V_180 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_44 = TRUE ;
V_41 = 0x800 ;
break;
case 's' :
V_43 = TRUE ;
V_94 = FALSE ;
V_86 = FALSE ;
V_78 = FALSE ;
V_111 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_100 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_101 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_110 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_102 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_103 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_113 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || * V_138 != '\0' ) {
fprintf ( V_5 , L_104 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_42 = TRUE ;
V_57 = 132 ;
V_44 = TRUE ;
V_41 = 0x800 ;
break;
case 'S' :
V_43 = TRUE ;
V_94 = TRUE ;
V_86 = FALSE ;
V_78 = FALSE ;
V_111 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_100 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_101 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_110 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_102 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_105 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_107 = ( T_1 ) strtoul ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || * V_138 != '\0' ) {
fprintf ( V_5 , L_106 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_42 = TRUE ;
V_57 = 132 ;
V_44 = TRUE ;
V_41 = 0x800 ;
break;
case 't' :
V_121 = V_180 ;
break;
case 'u' :
V_78 = TRUE ;
V_86 = FALSE ;
V_43 = FALSE ;
V_94 = FALSE ;
V_83 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_107 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_108 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_82 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || * V_138 != '\0' ) {
fprintf ( V_5 , L_109 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_42 = TRUE ;
V_57 = 17 ;
V_44 = TRUE ;
V_41 = 0x800 ;
break;
case 'T' :
V_86 = TRUE ;
V_78 = FALSE ;
V_43 = FALSE ;
V_94 = FALSE ;
V_83 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || ( * V_138 != ',' && * V_138 != '\0' ) ) {
fprintf ( V_5 , L_110 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_108 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_138 ++ ;
V_180 = V_138 ;
V_82 = ( T_1 ) strtol ( V_180 , & V_138 , 10 ) ;
if ( V_138 == V_180 || * V_138 != '\0' ) {
fprintf ( V_5 , L_111 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
V_42 = TRUE ;
V_57 = 6 ;
V_44 = TRUE ;
V_41 = 0x800 ;
break;
case 'a' :
V_170 = TRUE ;
break;
case 'v' :
V_174 = F_38 ( NULL , NULL ) ;
V_175 = F_39 ( NULL ) ;
F_43 ( L_112 , V_174 , V_175 ) ;
F_41 ( V_174 , TRUE ) ;
F_41 ( V_175 , TRUE ) ;
exit ( 0 ) ;
break;
case '4' :
case '6' :
V_138 = strchr ( V_180 , ',' ) ;
if ( ! V_138 ) {
fprintf ( V_5 , L_113 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
* V_138 = '\0' ;
if ( V_4 == '6' )
{
V_40 = TRUE ;
V_41 = 0x86DD ;
}
else
{
V_42 = TRUE ;
V_41 = 0x800 ;
}
V_44 = TRUE ;
if ( V_40 == TRUE ) {
if ( ! F_44 ( V_180 , & V_60 ) ) {
fprintf ( V_5 , L_114 , V_4 , V_138 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
} else {
if ( ! F_45 ( V_180 , & V_52 ) ) {
fprintf ( V_5 , L_114 , V_4 , V_138 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
}
V_138 ++ ;
if ( * V_138 == '\0' ) {
fprintf ( V_5 , L_115 , V_4 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( V_40 == TRUE ) {
if ( ! F_44 ( V_138 , & V_59 ) ) {
fprintf ( V_5 , L_116 , V_4 , V_138 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
} else {
if ( ! F_45 ( V_138 , & V_49 ) ) {
fprintf ( V_5 , L_116 , V_4 , V_138 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
}
break;
case '?' :
default:
F_33 ( V_5 ) ;
return V_6 ;
}
}
if ( V_181 >= V_172 || V_172 - V_181 < 2 ) {
fprintf ( V_5 , L_117 ) ;
F_33 ( V_5 ) ;
return V_6 ;
}
if ( strcmp ( V_173 [ V_181 ] , L_118 ) != 0 ) {
V_126 = V_173 [ V_181 ] ;
V_182 = F_46 ( V_126 , L_119 ) ;
if ( ! V_182 ) {
fprintf ( V_5 , L_120 ,
V_126 , F_18 ( V_183 ) ) ;
return V_6 ;
}
} else {
V_126 = L_121 ;
V_182 = V_184 ;
}
if ( strcmp ( V_173 [ V_181 + 1 ] , L_118 ) != 0 ) {
V_120 = V_173 [ V_181 + 1 ] ;
V_116 = F_46 ( V_120 , L_122 ) ;
if ( ! V_116 ) {
fprintf ( V_5 , L_123 ,
V_120 , F_18 ( V_183 ) ) ;
return V_6 ;
}
} else {
#ifdef F_35
if ( F_47 ( 1 , V_185 ) == - 1 ) {
fprintf ( V_5 , L_124 ,
F_18 ( V_183 ) ) ;
return V_6 ;
}
#endif
V_120 = L_125 ;
V_116 = stdout ;
}
if ( V_127 != 1 && V_44 ) {
fprintf ( V_5 , L_126 ) ;
return V_6 ;
}
if ( ! V_182 ) {
V_182 = V_184 ;
V_126 = L_121 ;
}
if ( ! V_116 ) {
V_116 = stdout ;
V_120 = L_125 ;
}
V_117 = time ( 0 ) ;
V_179 = localtime ( & V_117 ) ;
if ( V_179 == NULL ) {
fprintf ( V_5 , L_127 ) ;
return V_6 ;
}
V_140 = * V_179 ;
V_140 . V_147 = - 1 ;
if ( ! V_122 ) {
fprintf ( V_5 , L_128 , V_126 ) ;
fprintf ( V_5 , L_129 , V_120 ) ;
fprintf ( V_5 , L_130 , V_115 ? L_131 : L_132 ) ;
if ( V_44 ) fprintf ( V_5 , L_133 ,
V_41 ) ;
if ( V_42 ) fprintf ( V_5 , L_134 ,
V_57 ) ;
if ( V_78 ) fprintf ( V_5 , L_135 ,
V_83 , V_82 ) ;
if ( V_86 ) fprintf ( V_5 , L_136 ,
V_83 , V_82 ) ;
if ( V_43 ) fprintf ( V_5 , L_137 ,
V_111 , V_110 , V_113 ) ;
if ( V_94 ) fprintf ( V_5 , L_138 ,
V_101 , V_103 , V_105 , V_107 ) ;
}
return V_8 ;
}
int
main ( int V_172 , char * V_173 [] )
{
int V_186 = V_8 ;
F_34 ( V_172 , V_173 ) ;
assert ( V_182 != NULL ) ;
assert ( V_116 != NULL ) ;
if ( F_19 () != V_8 ) {
V_186 = V_6 ;
goto V_187;
}
V_12 = 0 ;
if ( V_44 ) {
V_12 += ( int ) sizeof( V_45 ) ;
}
if ( V_42 ) {
V_55 = V_12 ;
V_12 += ( int ) sizeof( V_47 ) ;
} else if ( V_40 ) {
V_55 = V_12 ;
V_12 += ( int ) sizeof( V_63 ) ;
}
if ( V_43 ) {
V_12 += ( int ) sizeof( V_108 ) ;
}
if ( V_94 ) {
V_12 += ( int ) sizeof( V_97 ) ;
}
if ( V_86 ) {
V_12 += ( int ) sizeof( V_87 ) ;
}
if ( V_78 ) {
V_12 += ( int ) sizeof( V_77 ) ;
}
V_10 = V_12 ;
V_188 = V_182 ;
if ( F_48 () == V_8 ) {
if ( F_13 ( FALSE ) != V_8 )
V_186 = V_6 ;
} else {
V_186 = V_6 ;
}
if ( V_133 )
fprintf ( V_5 , L_139 ) ;
if ( ! V_122 ) {
fprintf ( V_5 , L_140 V_189 L_141 ,
V_148 , ( V_148 == 1 ) ? L_7 : L_142 ,
V_123 , ( V_123 == 1 ) ? L_7 : L_142 ,
V_119 , ( V_119 == 1 ) ? L_7 : L_142 ) ;
}
V_187:
F_49 () ;
fclose ( V_182 ) ;
fclose ( V_116 ) ;
return V_186 ;
}
