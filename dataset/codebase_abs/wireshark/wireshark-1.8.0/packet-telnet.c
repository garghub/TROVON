static void
F_1 ( T_1 * T_2 V_1 , const char * V_2 )
{
int V_3 ;
char V_4 [ 2 ] ;
if ( ( strcmp ( V_2 , L_1 ) == 0 ) || ( strcmp ( V_2 , L_2 ) == 0 ) ||
( strcmp ( V_2 , L_3 ) == 0 ) || ( strcmp ( V_2 , L_4 ) == 0 ) ||
( strcmp ( V_2 , L_5 ) == 0 ) || ( strcmp ( V_2 , L_6 ) == 0 ) ||
( strcmp ( V_2 , L_7 ) == 0 ) || ( strcmp ( V_2 , L_8 ) == 0 ) ||
( strcmp ( V_2 , L_9 ) == 0 ) || ( strcmp ( V_2 , L_10 ) == 0 ) ||
( strcmp ( V_2 , L_11 ) == 0 ) ) {
V_4 [ 0 ] = V_2 [ 9 ] ;
V_4 [ 1 ] = '\0' ;
V_3 = atoi ( V_4 ) ;
F_2 ( T_2 , 0 , V_3 ) ;
}
}
static void
F_3 ( T_1 * T_2 V_1 , const char * V_5 , const char * V_2 )
{
if ( strcmp ( V_5 , L_12 ) != 0 ) {
return;
}
F_1 ( T_2 , V_2 ) ;
if ( ( strcmp ( V_2 , L_13 ) == 0 ) ||
( strcmp ( V_2 , L_14 ) == 0 ) ||
( strcmp ( V_2 , L_15 ) == 0 ) ||
( strcmp ( V_2 , L_16 ) == 0 ) ||
( strcmp ( V_2 , L_17 ) == 0 ) ||
( strcmp ( V_2 , L_18 ) == 0 ) ||
( strcmp ( V_2 , L_19 ) == 0 ) ||
( strcmp ( V_2 , L_20 ) == 0 ) ||
( strcmp ( V_2 , L_21 ) == 0 ) ||
( strcmp ( V_2 , L_22 ) == 0 ) )
F_4 ( T_2 , 0 ) ;
}
static void
F_5 ( T_1 * T_2 V_1 , const char * V_5 , T_3 * V_6 , int V_7 , int V_8 ,
T_4 * V_9 )
{
T_5 V_10 ;
V_10 = F_6 ( V_6 , V_7 ) ;
switch ( V_10 ) {
case 0 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_23 , V_5 ) ;
V_7 ++ ;
V_8 -- ;
if ( V_8 > 0 ) {
F_7 ( V_9 , V_6 , V_7 , V_8 , L_24 ,
F_8 ( V_6 , V_7 , V_8 ) ) ;
}
F_3 ( T_2 , V_5 , F_8 ( V_6 , V_7 , V_8 ) ) ;
break;
case 1 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_25 , V_5 ) ;
V_7 ++ ;
V_8 -- ;
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_26 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_27 ,
V_5 , V_10 ) ;
V_7 ++ ;
V_8 -- ;
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_28 ) ;
break;
}
}
static void
F_9 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 ,
int V_8 , T_4 * V_9 )
{
#define F_10 0x01
#define F_11 0x00
T_5 V_10 ;
while ( V_8 > 0 ) {
V_10 = F_6 ( V_6 , V_7 ) ;
switch ( V_10 ) {
case F_10 :
case F_11 :
if ( V_10 == F_10 ) {
F_7 ( V_9 , V_6 , V_7 , 1 , L_29 ) ;
F_2 ( T_2 , 0 , 0 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 , L_30 ) ;
}
F_7 ( V_9 , V_6 , V_7 + 1 , V_8 - 1 , L_31 ,
F_8 ( V_6 , V_7 + 1 , V_8 - 1 ) ) ;
V_7 += V_8 ;
V_8 -= V_8 ;
return;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_32 , V_10 ) ;
break;
}
V_7 ++ ;
V_8 -- ;
}
}
static void
F_12 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 ,
int V_8 , T_4 * V_9 )
{
T_5 V_10 ;
int V_11 ;
int V_12 = 0 ;
int V_13 = 0 ;
int V_14 = 0 ;
while ( V_8 > 0 ) {
V_10 = F_6 ( V_6 , V_7 ) ;
switch ( V_10 ) {
case V_15 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_33 ) ;
break;
case V_16 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_34 ) ;
F_7 ( V_9 , V_6 , V_7 + 1 , V_8 , L_31 ,
F_8 ( V_6 , V_7 + 1 , V_8 - 1 ) ) ;
V_7 += ( V_8 - 1 ) ;
V_8 -= ( V_8 - 1 ) ;
break;
case V_17 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_35 ) ;
break;
case V_18 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_36 ) ;
break;
case V_19 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_30 ) ;
V_13 = F_6 ( V_6 , V_7 - 1 ) ;
if ( V_13 == V_17 ) {
V_12 = F_13 ( V_6 , V_7 + 1 , V_8 , V_16 ) ;
if ( V_12 != - 1 ) {
V_11 = V_12 - ( V_7 + 1 ) ;
if ( V_11 > 0 ) {
F_7 ( V_9 , V_6 , V_7 + 1 , V_11 , L_31 ,
F_8 ( V_6 , V_7 + 1 , V_11 ) ) ;
F_1 ( T_2 , F_8 ( V_6 , V_7 + 1 , V_11 ) ) ;
V_7 += V_11 ;
V_8 -= V_11 ;
}
}
}
break;
case V_20 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_37 ) ;
V_7 ++ ;
V_8 -- ;
V_14 = F_6 ( V_6 , V_7 ) ;
switch ( V_14 ) {
case V_21 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_38 ) ;
break;
case V_22 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_39 ) ;
break;
case V_23 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_40 ) ;
break;
case V_24 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_41 ) ;
break;
case V_25 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_42 ) ;
break;
case V_26 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_43 ) ;
break;
case V_27 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_44 ) ;
break;
case V_28 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_45 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_32 , V_14 ) ;
break;
}
break;
case V_29 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_46 ) ;
break;
case V_30 :
F_2 ( T_2 , 1 , 0 ) ;
F_7 ( V_9 , V_6 , V_7 , 1 , L_47 ) ;
V_13 = F_6 ( V_6 , V_7 - 1 ) ;
if ( V_13 == V_17 ) {
F_7 ( V_9 , V_6 , V_7 + 1 , V_8 , L_31 ,
F_8 ( V_6 , V_7 + 1 , V_8 - 1 ) ) ;
V_7 += ( V_8 - 1 ) ;
V_8 -= ( V_8 - 1 ) ;
} else if ( V_13 == V_18 ) {
int V_31 = 0 ;
while ( V_8 > 0 && V_31 < 5 ) {
V_14 = F_6 ( V_6 , V_7 ) ;
switch ( V_14 ) {
case V_32 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_48 ) ;
break;
case V_33 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_49 ) ;
break;
case V_34 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_50 ) ;
break;
case V_35 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_51 ) ;
break;
case V_36 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_52 ) ;
break;
default:
V_31 = 5 ;
break;
}
V_7 ++ ;
V_8 -- ;
}
}
break;
case V_37 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_53 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_32 , V_10 ) ;
break;
}
V_7 ++ ;
V_8 -- ;
}
}
static void
F_14 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 ,
int V_8 , T_4 * V_9 )
{
T_5 V_10 ;
int V_38 , V_11 ;
while ( V_8 > 0 ) {
V_10 = F_6 ( V_6 , V_7 ) ;
switch ( V_10 ) {
case 6 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_54 ) ;
break;
case 21 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_55 ) ;
break;
case 'D' :
F_7 ( V_9 , V_6 , V_7 , 1 , L_56 ) ;
break;
case 'T' :
F_7 ( V_9 , V_6 , V_7 , 1 , L_57 ) ;
break;
case 'B' :
F_7 ( V_9 , V_6 , V_7 , 1 , L_58 ) ;
break;
case 'L' :
F_7 ( V_9 , V_6 , V_7 , 1 , L_59 ) ;
break;
case 'R' :
F_7 ( V_9 , V_6 , V_7 , 1 , L_60 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_32 , V_10 ) ;
break;
}
V_7 ++ ;
V_8 -- ;
V_38 = F_13 ( V_6 , V_7 , V_8 , 29 ) ;
if ( V_38 == - 1 ) {
V_38 = V_7 + V_8 ;
}
V_11 = V_38 - V_7 ;
if ( V_11 > 0 ) {
F_7 ( V_9 , V_6 , V_7 , V_11 , L_61 ,
F_8 ( V_6 , V_7 , V_11 ) ) ;
V_7 += V_11 ;
V_8 -= V_11 ;
}
}
}
static void
F_15 ( T_1 * T_2 V_1 , const char * V_5 , T_3 * V_6 , int V_7 , int V_8 ,
T_4 * V_9 )
{
T_5 V_10 ;
T_5 V_39 ;
V_10 = F_6 ( V_6 , V_7 ) ;
switch ( V_10 ) {
case 0 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_23 , V_5 ) ;
V_7 ++ ;
V_8 -- ;
break;
case 1 :
F_7 ( V_9 , V_6 , V_7 , 1 , L_25 , V_5 ) ;
V_7 ++ ;
V_8 -- ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_27 ,
V_5 , V_10 ) ;
V_7 ++ ;
V_8 -- ;
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_28 ) ;
return;
}
while ( V_8 > 0 ) {
V_39 = F_6 ( V_6 , V_7 ) ;
switch ( V_39 ) {
case 0 :
F_7 ( V_9 , V_6 , V_7 , 1 ,
L_62 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 ,
L_63 ,
V_39 ) ;
break;
case 251 :
case 252 :
case 253 :
case 254 :
F_7 ( V_9 , V_6 , V_7 , 1 ,
L_64 , V_39 ) ;
break;
case 255 :
F_7 ( V_9 , V_6 , V_7 , 1 ,
L_65 ) ;
break;
}
V_7 ++ ;
V_8 -- ;
}
}
static void
F_16 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 ,
int V_8 V_1 , T_4 * V_9 )
{
F_7 ( V_9 , V_6 , V_7 , 2 , L_66 ,
F_17 ( V_6 , V_7 ) ) ;
V_7 += 2 ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_67 ,
F_17 ( V_6 , V_7 ) ) ;
}
static void
F_18 ( T_1 * T_2 V_1 , const char * V_5 , T_3 * V_6 , int V_7 , int V_8 ,
T_4 * V_9 )
{
static const char * V_40 [] = {
L_68 ,
L_69 ,
L_69 ,
L_69 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73
} ;
static const char * V_41 [] = {
L_68 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78
} ;
static const char * V_42 [] = {
L_68 ,
L_79 ,
L_80 ,
L_81
} ;
static const char * V_43 [] = {
L_82 ,
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
L_90 ,
L_91 ,
L_92 ,
L_93 ,
L_94 ,
L_95 ,
L_96 ,
L_97 ,
L_98 ,
L_99 ,
L_100 ,
L_101
} ;
static const char * V_44 [] = {
L_102 ,
L_103 ,
L_104 ,
L_105 ,
L_106 ,
L_107 ,
L_108 ,
L_109
} ;
static const char * V_45 [] = {
L_110 ,
L_111 ,
L_112 ,
L_113 ,
L_114 ,
L_115 ,
L_116 ,
L_117
} ;
static const char * V_46 [] = {
L_118 ,
L_119 ,
L_120 ,
L_121
} ;
T_5 V_10 ;
T_5 V_47 ;
const char * V_48 ;
V_10 = F_6 ( V_6 , V_7 ) ;
V_47 = V_10 > 99 ;
V_10 = ( V_47 ) ? ( V_10 - 100 ) : V_10 ;
V_48 = ( V_47 ) ? L_122 : L_123 ;
switch ( V_10 ) {
case V_49 :
V_8 -- ;
if ( V_8 == 0 ) {
F_7 ( V_9 , V_6 , V_7 , 1 , L_124 , V_48 ) ;
} else {
T_5 * V_50 = F_19 ( V_6 , V_7 + 1 , V_8 ) ;
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_125 , V_48 , V_50 ) ;
}
break;
case V_51 :
V_8 -- ;
if ( V_8 >= 4 ) {
T_6 V_52 = F_20 ( V_6 , V_7 + 1 ) ;
if ( V_52 == 0 ) {
F_7 ( V_9 , V_6 , V_7 , 5 , L_126 , V_48 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 5 , L_127 , V_48 , V_52 ) ;
}
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_128 , V_48 ) ;
}
break;
case V_53 :
V_8 -- ;
if ( V_8 >= 1 ) {
T_5 V_54 = F_6 ( V_6 , V_7 + 1 ) ;
const char * V_55 = ( V_54 > 8 ) ? L_69 : V_40 [ V_54 ] ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_129 , V_48 , V_55 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_130 , V_48 ) ;
}
break;
case V_56 :
V_8 -- ;
if ( V_8 >= 1 ) {
T_5 V_57 = F_6 ( V_6 , V_7 + 1 ) ;
const char * V_58 = ( V_57 > 5 ) ? L_69 : V_41 [ V_57 ] ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_131 , V_48 , V_58 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_132 , V_48 ) ;
}
break;
case V_59 :
V_8 -- ;
if ( V_8 >= 1 ) {
T_5 V_60 = F_6 ( V_6 , V_7 + 1 ) ;
const char * V_61 = ( V_60 > 3 ) ? L_69 : V_42 [ V_60 ] ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_133 , V_48 , V_61 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_134 , V_48 ) ;
}
break;
case V_62 :
V_8 -- ;
if ( V_8 >= 1 ) {
T_5 V_63 = F_6 ( V_6 , V_7 + 1 ) ;
const char * V_64 = ( V_63 > 19 ) ? L_135 : V_43 [ V_63 ] ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_136 , V_48 , V_64 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_137 , V_48 ) ;
}
break;
case V_65 :
case V_66 :
V_8 -- ;
if ( V_8 >= 1 ) {
const char * V_67 = ( V_10 == V_65 ) ?
L_138 : L_139 ;
char V_68 [ 512 ] ;
T_5 V_69 = F_6 ( V_6 , V_7 + 1 ) ;
int V_70 = 0 ;
int V_71 ;
V_68 [ 0 ] = '\0' ;
for ( V_71 = 0 ; V_71 < 8 ; V_71 ++ ) {
int V_72 = V_69 & 1 ;
if ( V_72 ) {
if ( V_70 != 0 ) {
F_21 ( V_68 , L_140 , 512 ) ;
}
F_21 ( V_68 , V_44 [ V_71 ] , 512 ) ;
V_70 ++ ;
}
V_69 = V_69 >> 1 ;
}
F_7 ( V_9 , V_6 , V_7 , 2 , V_67 , V_48 , V_68 ) ;
} else {
const char * V_67 = ( V_10 == V_65 ) ?
L_141 : L_142 ;
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , V_67 , V_48 ) ;
}
break;
case V_73 :
case V_74 :
V_8 -- ;
if ( V_8 >= 1 ) {
const char * V_67 = ( V_10 == V_73 ) ?
L_143 : L_144 ;
char V_75 [ 256 ] ;
T_5 V_76 = F_6 ( V_6 , V_7 + 1 ) ;
int V_70 = 0 ;
int V_71 ;
V_75 [ 0 ] = '\0' ;
for ( V_71 = 0 ; V_71 < 8 ; V_71 ++ ) {
int V_72 = V_76 & 1 ;
if ( V_72 ) {
if ( V_70 != 0 ) {
F_21 ( V_75 , L_140 , 256 ) ;
}
F_21 ( V_75 , V_45 [ V_71 ] , 256 ) ;
V_70 ++ ;
}
V_76 = V_76 >> 1 ;
}
F_7 ( V_9 , V_6 , V_7 , 2 , V_67 , V_48 , V_75 ) ;
} else {
const char * V_67 = ( V_10 == V_73 ) ?
L_145 : L_146 ;
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , V_67 , V_48 ) ;
}
break;
case V_77 :
V_8 -- ;
F_7 ( V_9 , V_6 , V_7 , 1 , L_147 , V_48 ) ;
break;
case V_78 :
V_8 -- ;
F_7 ( V_9 , V_6 , V_7 , 1 , L_148 , V_48 ) ;
break;
case V_79 :
V_8 -- ;
if ( V_8 >= 1 ) {
T_5 V_80 = F_6 ( V_6 , V_7 + 1 ) ;
const char * V_81 = ( V_80 > 3 ) ? L_149 : V_46 [ V_80 ] ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_136 , V_48 , V_81 ) ;
} else {
F_7 ( V_9 , V_6 , V_7 , 1 + V_8 , L_150 , V_48 ) ;
}
break;
default:
F_7 ( V_9 , V_6 , V_7 , 1 , L_27 ,
V_5 , V_10 ) ;
V_7 ++ ;
V_8 -- ;
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_28 ) ;
return;
}
}
static void
F_22 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 ,
int V_8 V_1 , T_4 * V_9 )
{
T_5 V_10 ;
V_10 = F_6 ( V_6 , V_7 ) ;
F_7 ( V_9 , V_6 , V_7 , 2 , L_31 ,
F_23 ( V_10 , V_82 , L_151 ) ) ;
}
static void
F_24 ( T_1 * T_2 V_1 , T_3 * V_6 , int V_7 , T_4 * V_9 )
{
T_5 type , V_83 ;
type = F_6 ( V_6 , V_7 ) ;
F_25 ( V_9 , V_84 , V_6 , V_7 , 1 , type ) ;
V_83 = F_6 ( V_6 , V_7 + 1 ) ;
F_25 ( V_9 , V_85 , V_6 , V_7 + 1 , 1 , V_83 ) ;
F_26 ( V_9 , V_86 , V_6 , V_7 + 1 , 1 , V_83 ) ;
F_26 ( V_9 , V_87 , V_6 , V_7 + 1 , 1 , V_83 ) ;
F_26 ( V_9 , V_88 , V_6 , V_7 + 1 , 1 , V_83 ) ;
}
static T_3 *
F_27 ( T_1 * T_2 , T_3 * V_6 , int V_7 , int V_8 )
{
T_3 * V_89 ;
T_5 * V_90 ;
const T_5 * V_91 ;
T_5 * V_92 ;
int V_93 , V_94 ;
if( V_8 >= V_95 )
return NULL ;
V_91 = F_28 ( V_6 , V_7 , V_8 ) ;
V_90 = F_29 ( V_8 ) ;
V_92 = V_90 ;
V_93 = 0 ;
V_94 = V_8 ;
while( V_94 > 0 ) {
if( ( V_91 [ 0 ] == 0xff ) && ( V_91 [ 1 ] == 0xff ) ) {
V_93 ++ ;
V_94 -= 2 ;
* ( V_92 ++ ) = 0xff ;
V_91 += 2 ;
continue;
}
* ( V_92 ++ ) = * ( V_91 ++ ) ;
V_94 -- ;
}
V_89 = F_30 ( V_6 , V_90 , V_8 - V_93 , V_8 - V_93 ) ;
F_31 ( V_89 , V_96 ) ;
F_32 ( T_2 , V_89 , L_152 ) ;
return V_89 ;
}
static void
F_33 ( T_1 * T_2 , T_3 * V_6 , int V_7 , int V_8 , T_4 * V_9 , T_5 V_97 )
{
T_3 * V_89 ;
T_5 V_98 ;
F_24 ( T_2 , V_6 , V_7 , V_9 ) ;
V_7 += 2 ;
V_8 -= 2 ;
V_98 = F_6 ( V_6 , V_7 ) ;
F_25 ( V_9 , V_99 , V_6 , V_7 , 1 , V_98 ) ;
V_7 ++ ;
V_8 -- ;
if( ( V_97 == V_100 ) && ( V_98 == V_101 ) ) {
if( V_8 ) {
V_89 = F_27 ( T_2 , V_6 , V_7 , V_8 ) ;
if( V_89 )
F_34 ( V_89 , T_2 , V_9 , FALSE , NULL ) ;
else
F_7 ( V_9 , V_6 , V_7 , V_8 , L_153 ,
V_8 , V_95 ) ;
}
}
if( ( V_97 == V_102 ) && ( V_98 == V_103 ) ) {
if( V_8 ) {
V_89 = F_27 ( T_2 , V_6 , V_7 , V_8 ) ;
F_34 ( V_89 , T_2 , V_9 , FALSE , NULL ) ;
}
}
}
static void
F_35 ( T_1 * T_2 , const char * V_5 V_1 , T_3 * V_6 , int V_7 , int V_8 , T_4 * V_9 )
{
T_5 V_97 ;
char * V_104 ;
V_97 = F_6 ( V_6 , V_7 ) ;
F_25 ( V_9 , V_105 , V_6 , V_7 , 1 , V_97 ) ;
V_7 ++ ;
V_8 -- ;
switch( V_97 ) {
case V_102 :
case V_100 :
F_33 ( T_2 , V_6 , V_7 , V_8 , V_9 , V_97 ) ;
break;
case V_106 :
while( V_8 > 0 ) {
F_24 ( T_2 , V_6 , V_7 , V_9 ) ;
V_7 += 2 ;
V_8 -= 2 ;
}
break;
case V_107 :
if( V_8 < 255 ) {
V_104 = F_36 ( 256 ) ;
F_37 ( V_6 , ( T_5 * ) V_104 , V_7 , V_8 ) ;
V_104 [ V_8 ] = 0 ;
} else {
V_104 = L_154 ;
}
F_38 ( V_9 , V_108 , V_6 , V_7 , V_8 , V_104 ) ;
break;
}
}
static void F_39 ( T_3 * V_6 , int V_7 , T_4 * V_9 ) {
T_5 V_109 ;
V_109 = F_6 ( V_6 , V_7 ) ;
F_25 ( V_9 , V_110 , V_6 , V_7 , 1 , V_109 ) ;
}
static void
F_40 ( T_1 * T_2 V_1 , const char * V_5 V_1 , T_3 * V_6 , int V_7 , int V_8 , T_4 * V_9 )
{
T_5 V_111 , V_112 ;
V_111 = F_6 ( V_6 , V_7 ) ;
F_25 ( V_9 , V_113 , V_6 , V_7 , 1 , V_111 ) ;
V_7 ++ ;
V_8 -- ;
switch( V_111 ) {
case V_114 :
case V_115 :
if ( V_8 > 0 ) {
F_39 ( V_6 , V_7 , V_9 ) ;
V_7 ++ ;
V_8 -- ;
F_7 ( V_9 , V_6 , V_7 , V_8 , L_155 ) ;
}
break;
case V_116 :
while ( V_8 > 0 ) {
F_39 ( V_6 , V_7 , V_9 ) ;
V_7 ++ ;
V_8 -- ;
}
break;
case V_117 :
if ( V_8 > 0 ) {
V_112 = F_6 ( V_6 , V_7 ) ;
F_7 ( V_9 , V_6 , V_7 , V_8 , ( V_112 == 0 ) ? L_156 : L_157 ) ;
}
break;
case V_118 :
break;
case V_119 :
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_158 ) ;
break;
case V_120 :
break;
case V_121 :
case V_122 :
if ( V_8 > 0 )
F_7 ( V_9 , V_6 , V_7 , V_8 , L_157 ) ;
break;
default:
F_7 ( V_9 , V_6 , V_7 , V_8 , L_159 ) ;
}
}
static int
F_41 ( T_1 * T_2 , T_4 * V_123 , T_3 * V_6 , int V_124 )
{
T_4 * V_125 , * V_126 ;
int V_7 = V_124 ;
T_5 V_127 ;
int V_128 ;
const char * V_129 ;
T_7 V_130 = V_131 ;
int V_132 ;
T_8 V_8 ;
T_3 * V_133 ;
void (* F_42)( T_1 * , const char * , T_3 * , int , int , T_4 * );
T_7 V_134 ;
T_9 V_135 ;
int V_136 = 0 ;
V_7 += 2 ;
V_127 = F_6 ( V_6 , V_7 ) ;
if ( V_127 >= V_137 ) {
V_129 = L_160 ;
F_42 = NULL ;
} else {
V_129 = V_138 [ V_127 ] . V_104 ;
if ( V_138 [ V_127 ] . V_139 != NULL )
V_130 = * ( V_138 [ V_127 ] . V_139 ) ;
F_42 = V_138 [ V_127 ] . F_42 ;
}
V_7 ++ ;
V_134 = V_7 ;
V_135 = FALSE ;
V_8 = F_43 ( V_6 , V_7 ) ;
do {
V_132 = F_13 ( V_6 , V_134 , V_8 , V_140 ) ;
V_135 = TRUE ;
if ( V_132 == - 1 ) {
V_7 += V_8 ;
} else {
if ( ( ( T_8 ) ( V_132 + 1 ) >= V_8 ) ||
( F_6 ( V_6 , V_132 + 1 ) != V_140 ) ) {
V_7 = V_132 ;
} else {
V_135 = FALSE ;
V_134 = V_132 + 2 ;
V_136 += 1 ;
}
}
} while ( ! V_135 );
V_128 = V_7 - V_124 ;
V_125 = F_7 ( V_123 , V_6 , V_124 , V_128 ,
L_161 , V_129 ) ;
V_126 = F_44 ( V_125 , V_130 ) ;
V_124 += 3 ;
V_128 -= 3 ;
if ( V_128 > 0 ) {
if ( F_42 != NULL ) {
switch ( V_138 [ V_127 ] . V_141 ) {
case V_142 :
F_7 ( V_126 , V_6 , V_124 , V_128 ,
L_162 ) ;
return V_7 ;
case V_143 :
if ( V_128 - V_136 != V_138 [ V_127 ] . V_144 ) {
F_7 ( V_126 , V_6 , V_124 , V_128 ,
L_163 ,
V_128 , V_138 [ V_127 ] . V_144 ) ;
return V_7 ;
}
break;
case V_145 :
if ( V_128 - V_136 < V_138 [ V_127 ] . V_144 ) {
F_7 ( V_126 , V_6 , V_124 , V_128 ,
L_164 ,
V_128 , V_138 [ V_127 ] . V_144 ) ;
return V_7 ;
}
break;
}
if ( V_136 > 0 ) {
V_133 = F_27 ( T_2 , V_6 , V_124 , V_128 ) ;
(* F_42)( T_2 , V_129 , V_133 , 0 , V_128 - V_136 , V_126 ) ;
} else {
(* F_42)( T_2 , V_129 , V_6 , V_124 , V_128 , V_126 ) ;
}
} else {
if ( V_136 > 0 ) {
V_133 = F_27 ( T_2 , V_6 , V_124 , V_128 ) ;
F_7 ( V_126 , V_133 , 0 , V_128 - V_136 ,
L_165 ) ;
} else {
F_7 ( V_126 , V_6 , V_124 , V_128 ,
L_165 ) ;
}
}
}
return V_7 ;
}
static int
F_45 ( T_4 * V_123 , T_3 * V_6 ,
int V_124 , const char * type )
{
int V_7 = V_124 ;
T_5 V_127 ;
const char * V_129 ;
V_7 += 2 ;
V_127 = F_6 ( V_6 , V_7 ) ;
if ( V_127 >= V_137 )
V_129 = L_160 ;
else
V_129 = V_138 [ V_127 ] . V_104 ;
V_7 ++ ;
F_7 ( V_123 , V_6 , V_124 , 3 ,
L_166 , type , V_129 ) ;
return V_7 ;
}
static int
F_46 ( T_1 * T_2 , T_4 * V_123 , T_3 * V_6 , int V_124 )
{
int V_7 = V_124 ;
T_10 V_146 ;
V_7 += 1 ;
V_146 = F_6 ( V_6 , V_7 ) ;
V_7 ++ ;
switch( V_146 ) {
case V_147 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_167 ) ;
break;
case V_148 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_168 ) ;
break;
case V_149 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_169 ) ;
break;
case V_150 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_170 ) ;
break;
case V_151 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_171 ) ;
break;
case V_152 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_172 ) ;
break;
case V_153 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_173 ) ;
break;
case V_154 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_174 ) ;
break;
case V_155 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_175 ) ;
break;
case V_156 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_176 ) ;
break;
case V_157 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_177 ) ;
break;
case V_158 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_178 ) ;
break;
case V_159 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_179 ) ;
break;
case V_160 :
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_180 ) ;
break;
case V_161 :
V_7 = F_41 ( T_2 , V_123 , V_6 , V_124 ) ;
break;
case V_162 :
V_7 = F_45 ( V_123 , V_6 , V_124 ,
L_181 ) ;
break;
case V_163 :
V_7 = F_45 ( V_123 , V_6 , V_124 ,
L_182 ) ;
break;
case V_164 :
V_7 = F_45 ( V_123 , V_6 , V_124 ,
L_183 ) ;
break;
case V_165 :
V_7 = F_45 ( V_123 , V_6 , V_124 ,
L_184 ) ;
break;
default:
F_7 ( V_123 , V_6 , V_124 , 2 ,
L_185 , V_146 ) ;
break;
}
return V_7 ;
}
static void
F_47 ( T_4 * V_9 , T_3 * V_6 , int V_7 , int V_8 )
{
T_7 V_166 ;
int V_167 ;
T_5 V_64 ;
T_9 V_168 ;
while ( V_8 != 0 && F_48 ( V_6 , V_7 ) ) {
V_167 = F_49 ( V_6 , V_7 , V_8 , & V_166 , FALSE ) ;
V_8 -= V_166 - V_7 ;
if ( V_166 == V_7 + V_167 + 1 && V_8 >= 1 ) {
if ( F_6 ( V_6 , V_7 + V_167 ) == '\r' ) {
V_168 = TRUE ;
while ( V_8 != 0 && F_48 ( V_6 , V_166 ) ) {
V_64 = F_6 ( V_6 , V_166 ) ;
V_166 ++ ;
V_8 -- ;
if ( V_64 == '\n' || ( V_64 == '\0' && V_168 ) ) {
break;
}
V_168 = ( V_64 == '\r' ) ;
}
}
}
V_167 = V_166 - V_7 ;
F_50 ( V_9 , V_169 , V_6 , V_7 , V_167 , V_170 | V_171 ) ;
V_7 = V_166 ;
}
}
static int F_51 ( T_3 * V_6 , int V_7 , int V_8 )
{
int V_132 = V_7 ;
while ( ( V_132 = F_13 ( V_6 , V_132 , V_8 , V_140 ) ) != - 1 &&
( F_6 ( V_6 , V_132 + 1 ) == V_140 ) )
{
V_132 += 2 ;
V_8 = F_43 ( V_6 , V_132 ) ;
}
return V_132 ;
}
static void
F_52 ( T_3 * V_6 , T_1 * T_2 , T_4 * V_9 )
{
T_4 * V_123 , * V_125 ;
T_3 * V_172 ;
T_7 V_7 = 0 ;
T_8 V_8 = 0 ;
T_8 V_173 = 0 ;
T_8 V_174 = 0 ;
int V_175 ;
T_7 V_132 ;
F_53 ( T_2 -> V_176 , V_177 , L_186 ) ;
F_53 ( T_2 -> V_176 , V_178 , L_187 ) ;
V_173 = F_54 ( T_2 ) ;
V_174 = F_55 ( T_2 ) ;
V_125 = F_50 ( V_9 , V_179 , V_6 , V_7 , - 1 , V_171 ) ;
V_123 = F_44 ( V_125 , V_180 ) ;
while ( ( V_8 = F_43 ( V_6 , V_7 ) ) > 0 ) {
V_132 = F_51 ( V_6 , V_7 , V_8 ) ;
if ( V_132 != - 1 ) {
V_175 = V_132 - V_7 ;
if ( V_175 > 0 ) {
if ( V_173 ) {
V_172 = F_56 ( V_6 , V_7 , V_175 , V_175 ) ;
F_57 ( V_181 , V_172 , T_2 , V_123 ) ;
} else if ( V_174 ) {
V_172 = F_56 ( V_6 , V_7 , V_175 , V_175 ) ;
F_57 ( V_182 , V_172 , T_2 , V_123 ) ;
} else
F_47 ( V_123 , V_6 , V_7 , V_175 ) ;
}
V_7 = F_46 ( T_2 , V_123 , V_6 , V_132 ) ;
} else {
if ( V_173 || V_174 ) {
T_2 -> V_183 = V_7 ;
T_2 -> V_184 = V_185 ;
return;
}
F_47 ( V_123 , V_6 , V_7 , V_8 ) ;
break;
}
}
}
void
F_58 ( void )
{
static T_11 V_186 [] = {
{ & V_108 ,
{ L_188 , L_189 , V_187 , V_188 ,
NULL , 0 , L_190 , V_189 }
} ,
{ & V_105 ,
{ L_191 , L_192 , V_190 , V_191 ,
F_59 ( V_192 ) , 0 , L_193 , V_189 }
} ,
{ & V_84 ,
{ L_194 , L_195 , V_190 , V_191 ,
F_59 ( V_193 ) , 0 , L_196 , V_189 }
} ,
{ & V_86 ,
{ L_197 , L_198 , V_194 , 8 ,
F_60 ( & V_195 ) , 0x08 , L_199 , V_189 }
} ,
{ & V_88 ,
{ L_200 , L_201 , V_194 , 8 ,
F_60 ( & V_196 ) , 0x01 , L_202 , V_189 }
} ,
{ & V_87 ,
{ L_203 , L_204 , V_194 , 8 ,
F_60 ( & V_197 ) , 0x02 , L_205 , V_189 }
} ,
{ & V_85 ,
{ L_206 , L_207 , V_190 , V_191 ,
F_59 ( V_198 ) , 0x14 , L_208 , V_189 }
} ,
{ & V_99 ,
{ L_209 , L_210 , V_190 , V_191 ,
F_59 ( V_199 ) , 0 , L_211 , V_189 }
} ,
{ & V_113 ,
{ L_212 , L_213 , V_190 , V_191 ,
F_59 ( V_200 ) , 0 , L_214 , V_189 }
} ,
{ & V_110 ,
{ L_215 , L_216 , V_190 , V_191 ,
F_59 ( V_201 ) , 0 , L_217 , V_189 }
} ,
{ & V_169 ,
{ L_218 , L_219 , V_187 , V_188 ,
NULL , 0 , NULL , V_189 }
} ,
} ;
static T_7 * V_130 [] = {
& V_180 ,
& V_131 ,
& V_202 ,
& V_203 ,
& V_204 ,
& V_205 ,
& V_206 ,
& V_207 ,
& V_208 ,
& V_209 ,
& V_210 ,
& V_211 ,
& V_212 ,
& V_213 ,
& V_214 ,
& V_215 ,
& V_216 ,
& V_217 ,
& V_218 ,
& V_219 ,
& V_220 ,
& V_221 ,
& V_222 ,
& V_223 ,
& V_224 ,
& V_225 ,
& V_226 ,
& V_227 ,
& V_228 ,
& V_229 ,
& V_230 ,
& V_231 ,
& V_232 ,
& V_233 ,
& V_234 ,
& V_235 ,
& V_236 ,
& V_237
} ;
V_179 = F_61 ( L_220 , L_186 , L_221 ) ;
F_62 ( V_179 , V_186 , F_63 ( V_186 ) ) ;
F_64 ( V_130 , F_63 ( V_130 ) ) ;
}
void
F_65 ( void )
{
T_12 V_238 ;
V_238 = F_66 ( F_52 , V_179 ) ;
F_67 ( L_222 , V_239 , V_238 ) ;
V_181 = F_68 ( L_223 ) ;
V_182 = F_68 ( L_224 ) ;
}
