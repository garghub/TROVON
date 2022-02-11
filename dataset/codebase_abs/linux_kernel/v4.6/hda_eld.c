static unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 , V_3 , 0 ,
V_6 , V_4 ) ;
#ifdef F_3
F_4 ( V_2 , L_1 , V_4 , V_5 ) ;
#endif
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
const unsigned char * V_9 )
{
int V_10 ;
int V_5 ;
V_5 = F_6 ( V_9 , 1 , 0 , 7 ) ;
V_8 -> V_11 = 0 ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ )
if ( V_5 & ( 1 << V_10 ) )
V_8 -> V_11 |= V_12 [ V_10 + 1 ] ;
V_8 -> V_13 = F_6 ( V_9 , 0 , 0 , 3 ) ;
V_8 -> V_13 ++ ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = F_6 ( V_9 , 0 , 3 , 4 ) ;
switch ( V_8 -> V_16 ) {
case V_17 :
F_4 ( V_2 , L_2 ) ;
break;
case V_18 :
V_5 = F_6 ( V_9 , 2 , 0 , 3 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
if ( V_5 & ( 1 << V_10 ) )
V_8 -> V_14 |= V_19 [ V_10 + 1 ] ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_8 -> V_15 = F_6 ( V_9 , 2 , 0 , 8 ) ;
V_8 -> V_15 *= 8000 ;
break;
case V_27 :
break;
case V_28 :
break;
case V_29 :
break;
case V_30 :
break;
case V_31 :
break;
case V_32 :
V_8 -> V_33 = F_6 ( V_9 , 2 , 0 , 3 ) ;
break;
case V_34 :
V_8 -> V_16 = F_6 ( V_9 , 2 , 3 , 5 ) ;
if ( V_8 -> V_16 == V_35 ||
V_8 -> V_16 >= V_36 ) {
F_4 ( V_2 ,
L_3 ,
V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
} else
V_8 -> V_16 += V_37 -
V_38 ;
break;
}
}
int F_7 ( struct V_1 * V_2 , struct V_39 * V_40 ,
const unsigned char * V_9 , int V_41 )
{
int V_42 ;
int V_10 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_43 = F_6 ( V_9 , 0 , 3 , 5 ) ;
if ( V_40 -> V_43 != V_44 &&
V_40 -> V_43 != V_45 ) {
F_4 ( V_2 , L_4 , V_40 -> V_43 ) ;
goto V_46;
}
V_40 -> V_47 = F_6 ( V_9 , 2 , 0 , 8 ) ;
V_42 = F_6 ( V_9 , 4 , 0 , 5 ) ;
V_40 -> V_48 = F_6 ( V_9 , 4 , 5 , 3 ) ;
V_40 -> V_49 = F_6 ( V_9 , 5 , 0 , 1 ) ;
V_40 -> V_50 = F_6 ( V_9 , 5 , 1 , 1 ) ;
V_40 -> V_51 = F_6 ( V_9 , 5 , 2 , 2 ) ;
V_40 -> V_52 = F_6 ( V_9 , 5 , 4 , 4 ) ;
V_40 -> V_53 = F_6 ( V_9 , 6 , 0 , 8 ) * 2 ;
V_40 -> V_54 = F_6 ( V_9 , 7 , 0 , 7 ) ;
V_40 -> V_55 = F_8 ( V_9 + 8 ) ;
V_40 -> V_56 = F_9 ( V_9 + 16 ) ;
V_40 -> V_57 = F_9 ( V_9 + 18 ) ;
if ( V_42 > V_58 ) {
F_4 ( V_2 , L_5 , V_42 ) ;
goto V_46;
} else if ( V_59 + V_42 > V_41 ) {
F_4 ( V_2 , L_6 , V_42 ) ;
goto V_46;
} else
F_10 ( V_40 -> V_60 , V_9 + V_59 , V_42 + 1 ) ;
for ( V_10 = 0 ; V_10 < V_40 -> V_52 ; V_10 ++ ) {
if ( V_59 + V_42 + 3 * ( V_10 + 1 ) > V_41 ) {
F_4 ( V_2 , L_7 , V_10 ) ;
goto V_46;
}
F_5 ( V_2 , V_40 -> V_61 + V_10 ,
V_9 + V_59 + V_42 + 3 * V_10 ) ;
}
if ( ! V_40 -> V_54 )
V_40 -> V_54 = 0xffff ;
return 0 ;
V_46:
return - V_62 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 , 0 , V_63 ,
V_64 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char * V_9 , int * V_65 )
{
int V_10 ;
int V_66 = 0 ;
int V_41 ;
V_41 = F_11 ( V_2 , V_3 ) ;
if ( V_41 == 0 ) {
F_4 ( V_2 , L_8 ) ;
V_41 = 128 ;
}
if ( V_41 < V_59 || V_41 > V_67 ) {
F_4 ( V_2 , L_9 , V_41 ) ;
return - V_68 ;
}
for ( V_10 = 0 ; V_10 < V_41 ; V_10 ++ ) {
unsigned int V_5 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! ( V_5 & V_69 ) ) {
F_4 ( V_2 , L_10 , V_10 ) ;
V_66 = - V_62 ;
goto error;
}
V_5 &= V_70 ;
if ( ! V_5 && ! V_10 ) {
F_13 ( V_2 , L_11 ) ;
V_66 = - V_62 ;
goto error;
}
V_9 [ V_10 ] = V_5 ;
}
* V_65 = V_41 ;
error:
return V_66 ;
}
static void F_14 ( int V_71 , char * V_9 , int V_72 )
{
static unsigned int V_73 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 64000 ,
88200 , 96000 , 176400 , 192000 , 384000
} ;
int V_10 , V_74 ;
for ( V_10 = 0 , V_74 = 0 ; V_10 < F_15 ( V_73 ) ; V_10 ++ )
if ( V_71 & ( 1 << V_10 ) )
V_74 += snprintf ( V_9 + V_74 , V_72 - V_74 , L_12 ,
V_73 [ V_10 ] ) ;
V_9 [ V_74 ] = '\0' ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
char V_9 [ V_75 ] ;
char V_76 [ 8 + V_77 ] = L_13 ;
if ( ! V_8 -> V_16 )
return;
F_14 ( V_8 -> V_11 , V_9 , sizeof( V_9 ) ) ;
if ( V_8 -> V_16 == V_18 )
F_17 ( V_8 -> V_14 , V_76 + 8 , sizeof( V_76 ) - 8 ) ;
else if ( V_8 -> V_15 )
snprintf ( V_76 , sizeof( V_76 ) ,
L_14 , V_8 -> V_15 ) ;
else
V_76 [ 0 ] = '\0' ;
F_13 ( V_2 ,
L_15 ,
V_78 [ V_8 -> V_16 ] ,
V_8 -> V_13 , V_9 , V_76 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
int V_10 ;
F_13 ( V_2 , L_16 ,
V_40 -> V_60 ,
V_79 [ V_40 -> V_51 ] ) ;
if ( V_40 -> V_54 ) {
char V_9 [ V_80 ] ;
F_19 ( V_40 -> V_54 , V_9 , sizeof( V_9 ) ) ;
F_13 ( V_2 , L_17 , V_9 ) ;
}
for ( V_10 = 0 ; V_10 < V_40 -> V_52 ; V_10 ++ )
F_16 ( V_2 , V_40 -> V_61 + V_10 ) ;
}
static void F_20 ( int V_10 , struct V_7 * V_8 ,
struct V_81 * V_82 )
{
char V_9 [ V_75 ] ;
F_21 ( V_82 , L_18 ,
V_10 , V_8 -> V_16 , V_78 [ V_8 -> V_16 ] ) ;
F_21 ( V_82 , L_19 , V_10 , V_8 -> V_13 ) ;
F_14 ( V_8 -> V_11 , V_9 , sizeof( V_9 ) ) ;
F_21 ( V_82 , L_20 , V_10 , V_8 -> V_11 , V_9 ) ;
if ( V_8 -> V_16 == V_18 ) {
F_17 ( V_8 -> V_14 , V_9 , sizeof( V_9 ) ) ;
F_21 ( V_82 , L_21 ,
V_10 , V_8 -> V_14 , V_9 ) ;
}
if ( V_8 -> V_15 )
F_21 ( V_82 , L_22 ,
V_10 , V_8 -> V_15 ) ;
if ( V_8 -> V_33 )
F_21 ( V_82 , L_23 , V_10 , V_8 -> V_33 ) ;
}
void F_22 ( struct V_83 * V_84 ,
struct V_81 * V_82 )
{
struct V_39 * V_40 = & V_84 -> V_85 ;
char V_9 [ V_80 ] ;
int V_10 ;
static const char * const V_86 [ 32 ] = {
L_24 ,
L_24 ,
L_25 ,
[ 3 ... 30 ] = L_24 ,
[ 31 ] = L_26
} ;
static const char * const V_87 [ 8 ] = {
L_27 ,
L_28 ,
L_29 ,
L_30 ,
[ 4 ... 7 ] = L_24
} ;
F_21 ( V_82 , L_31 , V_84 -> V_88 ) ;
F_21 ( V_82 , L_32 , V_84 -> V_89 ) ;
if ( ! V_84 -> V_89 )
return;
F_21 ( V_82 , L_33 , V_40 -> V_60 ) ;
F_21 ( V_82 , L_34 ,
V_79 [ V_40 -> V_51 ] ) ;
F_21 ( V_82 , L_35 , V_40 -> V_43 ,
V_86 [ V_40 -> V_43 ] ) ;
F_21 ( V_82 , L_36 , V_40 -> V_48 ,
V_87 [ V_40 -> V_48 ] ) ;
F_21 ( V_82 , L_37 , V_40 -> V_56 ) ;
F_21 ( V_82 , L_38 , V_40 -> V_57 ) ;
F_21 ( V_82 , L_39 , ( long long ) V_40 -> V_55 ) ;
F_21 ( V_82 , L_40 , V_40 -> V_49 ) ;
F_21 ( V_82 , L_41 , V_40 -> V_50 ) ;
F_21 ( V_82 , L_42 , V_40 -> V_53 ) ;
F_19 ( V_40 -> V_54 , V_9 , sizeof( V_9 ) ) ;
F_21 ( V_82 , L_43 , V_40 -> V_54 , V_9 ) ;
F_21 ( V_82 , L_44 , V_40 -> V_52 ) ;
for ( V_10 = 0 ; V_10 < V_40 -> V_52 ; V_10 ++ )
F_20 ( V_10 , V_40 -> V_61 + V_10 , V_82 ) ;
}
void F_23 ( struct V_83 * V_84 ,
struct V_81 * V_82 )
{
struct V_39 * V_40 = & V_84 -> V_85 ;
char line [ 64 ] ;
char V_90 [ 64 ] ;
char * V_91 ;
long long V_5 ;
unsigned int V_92 ;
while ( ! F_24 ( V_82 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_45 , V_90 , & V_5 ) != 2 )
continue;
if ( ! strcmp ( V_90 , L_46 ) )
V_84 -> V_88 = V_5 ;
else if ( ! strcmp ( V_90 , L_47 ) )
V_84 -> V_89 = V_5 ;
else if ( ! strcmp ( V_90 , L_48 ) )
V_40 -> V_51 = V_5 ;
else if ( ! strcmp ( V_90 , L_49 ) )
V_40 -> V_55 = V_5 ;
else if ( ! strcmp ( V_90 , L_50 ) )
V_40 -> V_49 = V_5 ;
else if ( ! strcmp ( V_90 , L_51 ) )
V_40 -> V_50 = V_5 ;
else if ( ! strcmp ( V_90 , L_52 ) )
V_40 -> V_53 = V_5 ;
else if ( ! strcmp ( V_90 , L_53 ) )
V_40 -> V_54 = V_5 ;
else if ( ! strcmp ( V_90 , L_54 ) )
V_40 -> V_52 = V_5 ;
else if ( ! strncmp ( V_90 , L_55 , 3 ) ) {
V_91 = V_90 + 4 ;
V_92 = V_90 [ 3 ] - '0' ;
if ( V_90 [ 4 ] >= '0' && V_90 [ 4 ] <= '9' ) {
V_91 ++ ;
V_92 = 10 * V_92 + V_90 [ 4 ] - '0' ;
}
if ( V_92 >= V_93 )
continue;
if ( ! strcmp ( V_91 , L_56 ) )
V_40 -> V_61 [ V_92 ] . V_16 = V_5 ;
else if ( ! strcmp ( V_91 , L_57 ) )
V_40 -> V_61 [ V_92 ] . V_13 = V_5 ;
else if ( ! strcmp ( V_91 , L_58 ) )
V_40 -> V_61 [ V_92 ] . V_11 = V_5 ;
else if ( ! strcmp ( V_91 , L_59 ) )
V_40 -> V_61 [ V_92 ] . V_14 = V_5 ;
else if ( ! strcmp ( V_91 , L_60 ) )
V_40 -> V_61 [ V_92 ] . V_15 = V_5 ;
else if ( ! strcmp ( V_91 , L_61 ) )
V_40 -> V_61 [ V_92 ] . V_33 = V_5 ;
if ( V_92 >= V_40 -> V_52 )
V_40 -> V_52 = V_92 + 1 ;
}
}
}
void F_25 ( struct V_39 * V_40 ,
struct V_94 * V_95 )
{
T_2 V_11 ;
T_3 V_96 ;
unsigned int V_97 ;
unsigned int V_98 ;
int V_10 ;
V_11 = V_99 | V_100 |
V_101 ;
V_96 = V_102 ;
V_97 = 16 ;
V_98 = 2 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_52 ; V_10 ++ ) {
struct V_7 * V_8 = & V_40 -> V_61 [ V_10 ] ;
V_11 |= V_8 -> V_11 ;
if ( V_8 -> V_13 > V_98 )
V_98 = V_8 -> V_13 ;
if ( V_8 -> V_16 == V_18 ) {
if ( V_8 -> V_14 & V_103 ) {
V_96 |= V_104 ;
if ( V_97 < 20 )
V_97 = 20 ;
}
if ( V_8 -> V_14 & V_105 ) {
V_96 |= V_104 ;
if ( V_97 < 24 )
V_97 = 24 ;
}
}
}
V_95 -> V_11 &= V_11 ;
V_95 -> V_96 &= V_96 ;
V_95 -> V_97 = F_26 ( V_95 -> V_97 , V_97 ) ;
V_95 -> V_98 = F_26 ( V_95 -> V_98 , V_98 ) ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char * V_9 , int * V_65 , bool V_106 )
{
int V_107 , V_108 , V_109 ;
int V_110 = 0 ;
int V_111 , V_10 ;
V_107 = F_2 ( V_2 , V_3 , 0 , V_112 , 0 ) ;
if ( V_107 <= 0 ) {
F_4 ( V_2 , L_62 ) ;
return - V_62 ;
}
memset ( V_9 , 0 , V_59 + V_58 + V_93 * 3 ) ;
V_9 [ 0 ] = V_44 << 3 ;
V_9 [ 7 ] = V_107 & V_113 ;
if ( V_107 & V_114 )
V_9 [ 5 ] |= 0x04 ;
V_111 = V_59 ;
if ( V_106 ) {
int V_115 ;
F_28 ( V_2 , V_3 , 0 , V_116 , V_117 ) ;
V_115 = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
F_29 ( V_115 , V_9 + 8 ) ;
F_28 ( V_2 , V_3 , 0 , V_116 , V_119 ) ;
V_115 = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
F_29 ( V_115 , V_9 + 12 ) ;
F_28 ( V_2 , V_3 , 0 , V_116 , V_120 ) ;
V_115 = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
F_30 ( V_115 , V_9 + 16 ) ;
F_28 ( V_2 , V_3 , 0 , V_116 , V_121 ) ;
V_115 = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
F_30 ( V_115 , V_9 + 18 ) ;
F_28 ( V_2 , V_3 , 0 , V_116 , V_122 ) ;
V_110 = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
if ( V_110 > V_58 ) {
F_4 ( V_2 , L_63 ,
V_110 ) ;
V_110 = V_58 ;
}
V_9 [ 4 ] |= V_110 ;
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ ) {
F_28 ( V_2 , V_3 , 0 , V_116 , V_123 + V_10 ) ;
V_9 [ V_111 ++ ] = F_2 ( V_2 , V_3 , 0 , V_118 , 0 ) ;
}
}
for ( V_10 = V_18 ; V_10 <= V_32 ; V_10 ++ ) {
if ( V_10 == V_27 || V_10 == V_31 )
continue;
F_28 ( V_2 , V_3 , 0 , V_124 , V_10 << 3 ) ;
V_108 = F_2 ( V_2 , V_3 , 0 , V_125 , 0 ) ;
if ( V_108 <= 0 )
continue;
if ( V_108 & V_126 ) {
V_9 [ V_111 ++ ] = ( V_108 & 0x0000ff ) >> 0 ;
V_9 [ V_111 ++ ] = ( V_108 & 0x00ff00 ) >> 8 ;
V_9 [ V_111 ++ ] = ( V_108 & 0xff0000 ) >> 16 ;
}
if ( V_10 == V_18
&& ( V_108 & V_127 )
&& ( V_108 & V_127 ) >> 16 != ( V_108 & V_126 ) ) {
V_9 [ V_111 ++ ] = ( ( V_108 & 0x000000ff ) & ~ V_128 ) | 0x1 ;
V_9 [ V_111 ++ ] = ( V_108 & 0xff000000 ) >> 24 ;
V_9 [ V_111 ++ ] = ( V_108 & 0x00ff0000 ) >> 16 ;
}
}
if ( V_111 == V_59 + V_110 ) {
F_4 ( V_2 , L_64 ) ;
return - V_62 ;
}
V_109 = F_2 ( V_2 , V_3 , 0 , V_129 , 0 ) ;
if ( ( V_109 & V_130 ) && ( V_109 & V_131 ) ) {
int V_132 = ( V_109 & V_130 ) ;
int V_133 = ( V_109 & V_131 ) >> 8 ;
if ( V_132 <= 0xfb && V_133 <= 0xfb &&
V_132 > V_133 )
V_9 [ 6 ] = V_132 - V_133 ;
}
V_9 [ 5 ] |= ( ( V_111 - V_59 - V_110 ) / 3 ) << 4 ;
V_111 = F_31 ( V_111 , 4 ) ;
V_9 [ 2 ] = ( V_111 - 4 ) / 4 ;
* V_65 = V_111 ;
return 0 ;
}
