static unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 , V_3 , 0 ,
V_6 , V_4 ) ;
#ifdef F_3
F_4 ( V_7 L_1 , V_4 , V_5 ) ;
#endif
return V_5 ;
}
static void F_5 ( struct V_8 * V_9 ,
const unsigned char * V_10 )
{
int V_11 ;
int V_5 ;
V_5 = F_6 ( V_10 , 1 , 0 , 7 ) ;
V_9 -> V_12 = 0 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ )
if ( V_5 & ( 1 << V_11 ) )
V_9 -> V_12 |= V_13 [ V_11 + 1 ] ;
V_9 -> V_14 = F_6 ( V_10 , 0 , 0 , 3 ) ;
V_9 -> V_14 ++ ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = F_6 ( V_10 , 0 , 3 , 4 ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
F_7 ( V_7
L_2 ) ;
break;
case V_19 :
V_5 = F_6 ( V_10 , 2 , 0 , 3 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
if ( V_5 & ( 1 << V_11 ) )
V_9 -> V_15 |= V_20 [ V_11 + 1 ] ;
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_9 -> V_16 = F_6 ( V_10 , 2 , 0 , 8 ) ;
V_9 -> V_16 *= 8000 ;
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
break;
case V_33 :
V_9 -> V_34 = F_6 ( V_10 , 2 , 0 , 3 ) ;
break;
case V_35 :
V_9 -> V_17 = F_6 ( V_10 , 2 , 3 , 5 ) ;
if ( V_9 -> V_17 == V_36 ||
V_9 -> V_17 >= V_37 ) {
F_7 ( V_7
L_3 ,
V_9 -> V_17 ) ;
V_9 -> V_17 = 0 ;
} else
V_9 -> V_17 += V_38 -
V_39 ;
break;
}
}
static int F_8 ( struct V_40 * V_41 ,
const unsigned char * V_10 , int V_42 )
{
int V_43 ;
int V_11 ;
V_41 -> V_44 = F_6 ( V_10 , 0 , 3 , 5 ) ;
if ( V_41 -> V_44 != V_45 &&
V_41 -> V_44 != V_46 ) {
F_7 ( V_7 L_4 ,
V_41 -> V_44 ) ;
goto V_47;
}
V_41 -> V_48 = V_42 ;
V_41 -> V_49 = F_6 ( V_10 , 2 , 0 , 8 ) ;
V_43 = F_6 ( V_10 , 4 , 0 , 5 ) ;
V_41 -> V_50 = F_6 ( V_10 , 4 , 5 , 3 ) ;
V_41 -> V_51 = F_6 ( V_10 , 5 , 0 , 1 ) ;
V_41 -> V_52 = F_6 ( V_10 , 5 , 1 , 1 ) ;
V_41 -> V_53 = F_6 ( V_10 , 5 , 2 , 2 ) ;
V_41 -> V_54 = F_6 ( V_10 , 5 , 4 , 4 ) ;
V_41 -> V_55 = F_6 ( V_10 , 6 , 0 , 8 ) * 2 ;
V_41 -> V_56 = F_6 ( V_10 , 7 , 0 , 7 ) ;
V_41 -> V_57 = F_9 ( V_10 + 8 ) ;
V_41 -> V_58 = F_10 ( V_10 + 16 ) ;
V_41 -> V_59 = F_10 ( V_10 + 18 ) ;
if ( V_43 > V_60 ) {
F_7 ( V_7 L_5 , V_43 ) ;
goto V_47;
} else if ( V_61 + V_43 > V_42 ) {
F_7 ( V_7 L_6 , V_43 ) ;
goto V_47;
} else
F_11 ( V_41 -> V_62 , V_10 + V_61 , V_43 + 1 ) ;
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ ) {
if ( V_61 + V_43 + 3 * ( V_11 + 1 ) > V_42 ) {
F_7 ( V_7 L_7 , V_11 ) ;
goto V_47;
}
F_5 ( V_41 -> V_63 + V_11 ,
V_10 + V_61 + V_43 + 3 * V_11 ) ;
}
if ( ! V_41 -> V_56 )
V_41 -> V_56 = 0xffff ;
V_41 -> V_64 = true ;
return 0 ;
V_47:
return - V_65 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 , 0 , V_66 ,
V_67 ) ;
}
int F_13 ( struct V_40 * V_68 ,
struct V_1 * V_2 , T_1 V_3 )
{
int V_11 ;
int V_69 ;
int V_42 ;
unsigned char * V_10 ;
V_42 = F_12 ( V_2 , V_3 ) ;
if ( V_42 == 0 ) {
F_7 ( V_7 L_8 ) ;
V_42 = 128 ;
}
if ( V_42 < V_61 || V_42 > V_70 ) {
F_7 ( V_7 L_9 , V_42 ) ;
return - V_71 ;
}
V_10 = V_68 -> V_72 ;
for ( V_11 = 0 ; V_11 < V_42 ; V_11 ++ ) {
unsigned int V_5 = F_1 ( V_2 , V_3 , V_11 ) ;
if ( ! ( V_5 & V_73 ) ) {
F_7 ( V_7
L_10 , V_11 ) ;
V_69 = - V_65 ;
goto error;
}
V_5 &= V_74 ;
if ( ! V_5 && ! V_11 ) {
F_14 ( V_7 L_11 ) ;
V_69 = - V_65 ;
goto error;
}
V_10 [ V_11 ] = V_5 ;
}
V_69 = F_8 ( V_68 , V_10 , V_42 ) ;
error:
return V_69 ;
}
static void F_15 ( int V_75 , char * V_10 , int V_76 )
{
static unsigned int V_77 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 , 64000 ,
88200 , 96000 , 176400 , 192000 , 384000
} ;
int V_11 , V_78 ;
for ( V_11 = 0 , V_78 = 0 ; V_11 < F_16 ( V_77 ) ; V_11 ++ )
if ( V_75 & ( 1 << V_11 ) )
V_78 += snprintf ( V_10 + V_78 , V_76 - V_78 , L_12 ,
V_77 [ V_11 ] ) ;
V_10 [ V_78 ] = '\0' ;
}
static void F_17 ( struct V_8 * V_9 )
{
char V_10 [ V_79 ] ;
char V_80 [ 8 + V_81 ] = L_13 ;
if ( ! V_9 -> V_17 )
return;
F_15 ( V_9 -> V_12 , V_10 , sizeof( V_10 ) ) ;
if ( V_9 -> V_17 == V_19 )
F_18 ( V_9 -> V_15 , V_80 + 8 , sizeof( V_80 ) - 8 ) ;
else if ( V_9 -> V_16 )
snprintf ( V_80 , sizeof( V_80 ) ,
L_14 , V_9 -> V_16 ) ;
else
V_80 [ 0 ] = '\0' ;
F_19 ( V_82 , L_15
L_16 ,
V_83 [ V_9 -> V_17 ] ,
V_9 -> V_14 ,
V_10 ,
V_80 ) ;
}
void F_20 ( int V_56 , char * V_10 , int V_76 )
{
int V_11 , V_78 ;
for ( V_11 = 0 , V_78 = 0 ; V_11 < F_16 ( V_84 ) ; V_11 ++ ) {
if ( V_56 & ( 1 << V_11 ) )
V_78 += snprintf ( V_10 + V_78 , V_76 - V_78 , L_17 ,
V_84 [ V_11 ] ) ;
}
V_10 [ V_78 ] = '\0' ;
}
void F_21 ( struct V_40 * V_41 )
{
int V_11 ;
F_19 ( V_82 , L_18 ,
V_41 -> V_62 ,
V_85 [ V_41 -> V_53 ] ) ;
if ( V_41 -> V_56 ) {
char V_10 [ V_86 ] ;
F_20 ( V_41 -> V_56 , V_10 , sizeof( V_10 ) ) ;
F_19 ( V_82 , L_19 , V_10 ) ;
}
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ )
F_17 ( V_41 -> V_63 + V_11 ) ;
}
static void F_22 ( int V_11 , struct V_8 * V_9 ,
struct V_87 * V_88 )
{
char V_10 [ V_79 ] ;
F_23 ( V_88 , L_20 ,
V_11 , V_9 -> V_17 , V_83 [ V_9 -> V_17 ] ) ;
F_23 ( V_88 , L_21 , V_11 , V_9 -> V_14 ) ;
F_15 ( V_9 -> V_12 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_88 , L_22 , V_11 , V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_17 == V_19 ) {
F_18 ( V_9 -> V_15 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_88 , L_23 ,
V_11 , V_9 -> V_15 , V_10 ) ;
}
if ( V_9 -> V_16 )
F_23 ( V_88 , L_24 ,
V_11 , V_9 -> V_16 ) ;
if ( V_9 -> V_34 )
F_23 ( V_88 , L_25 , V_11 , V_9 -> V_34 ) ;
}
static void F_24 ( struct V_89 * V_90 ,
struct V_87 * V_88 )
{
struct V_40 * V_41 = V_90 -> V_91 ;
char V_10 [ V_86 ] ;
int V_11 ;
static char * V_92 [ 32 ] = {
L_26 ,
L_26 ,
L_27 ,
[ 3 ... 30 ] = L_26 ,
[ 31 ] = L_28
} ;
static char * V_93 [ 8 ] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
[ 4 ... 7 ] = L_26
} ;
F_23 ( V_88 , L_33 , V_41 -> V_94 ) ;
F_23 ( V_88 , L_34 , V_41 -> V_64 ) ;
if ( ! V_41 -> V_64 )
return;
F_23 ( V_88 , L_35 , V_41 -> V_62 ) ;
F_23 ( V_88 , L_36 ,
V_85 [ V_41 -> V_53 ] ) ;
F_23 ( V_88 , L_37 , V_41 -> V_44 ,
V_92 [ V_41 -> V_44 ] ) ;
F_23 ( V_88 , L_38 , V_41 -> V_50 ,
V_93 [ V_41 -> V_50 ] ) ;
F_23 ( V_88 , L_39 , V_41 -> V_58 ) ;
F_23 ( V_88 , L_40 , V_41 -> V_59 ) ;
F_23 ( V_88 , L_41 , ( long long ) V_41 -> V_57 ) ;
F_23 ( V_88 , L_42 , V_41 -> V_51 ) ;
F_23 ( V_88 , L_43 , V_41 -> V_52 ) ;
F_23 ( V_88 , L_44 , V_41 -> V_55 ) ;
F_20 ( V_41 -> V_56 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_88 , L_45 , V_41 -> V_56 , V_10 ) ;
F_23 ( V_88 , L_46 , V_41 -> V_54 ) ;
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ )
F_22 ( V_11 , V_41 -> V_63 + V_11 , V_88 ) ;
}
static void F_25 ( struct V_89 * V_90 ,
struct V_87 * V_88 )
{
struct V_40 * V_41 = V_90 -> V_91 ;
char line [ 64 ] ;
char V_95 [ 64 ] ;
char * V_96 ;
long long V_5 ;
unsigned int V_97 ;
while ( ! F_26 ( V_88 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_47 , V_95 , & V_5 ) != 2 )
continue;
if ( ! strcmp ( V_95 , L_48 ) )
V_41 -> V_94 = V_5 ;
else if ( ! strcmp ( V_95 , L_49 ) )
V_41 -> V_64 = V_5 ;
else if ( ! strcmp ( V_95 , L_50 ) )
V_41 -> V_53 = V_5 ;
else if ( ! strcmp ( V_95 , L_51 ) )
V_41 -> V_57 = V_5 ;
else if ( ! strcmp ( V_95 , L_52 ) )
V_41 -> V_51 = V_5 ;
else if ( ! strcmp ( V_95 , L_53 ) )
V_41 -> V_52 = V_5 ;
else if ( ! strcmp ( V_95 , L_54 ) )
V_41 -> V_55 = V_5 ;
else if ( ! strcmp ( V_95 , L_55 ) )
V_41 -> V_56 = V_5 ;
else if ( ! strcmp ( V_95 , L_56 ) )
V_41 -> V_54 = V_5 ;
else if ( ! strncmp ( V_95 , L_57 , 3 ) ) {
V_96 = V_95 + 4 ;
V_97 = V_95 [ 3 ] - '0' ;
if ( V_95 [ 4 ] >= '0' && V_95 [ 4 ] <= '9' ) {
V_96 ++ ;
V_97 = 10 * V_97 + V_95 [ 4 ] - '0' ;
}
if ( V_97 >= V_98 )
continue;
if ( ! strcmp ( V_96 , L_58 ) )
V_41 -> V_63 [ V_97 ] . V_17 = V_5 ;
else if ( ! strcmp ( V_96 , L_59 ) )
V_41 -> V_63 [ V_97 ] . V_14 = V_5 ;
else if ( ! strcmp ( V_96 , L_60 ) )
V_41 -> V_63 [ V_97 ] . V_12 = V_5 ;
else if ( ! strcmp ( V_96 , L_61 ) )
V_41 -> V_63 [ V_97 ] . V_15 = V_5 ;
else if ( ! strcmp ( V_96 , L_62 ) )
V_41 -> V_63 [ V_97 ] . V_16 = V_5 ;
else if ( ! strcmp ( V_96 , L_63 ) )
V_41 -> V_63 [ V_97 ] . V_34 = V_5 ;
if ( V_97 >= V_41 -> V_54 )
V_41 -> V_54 = V_97 + 1 ;
}
}
}
int F_27 ( struct V_1 * V_2 , struct V_40 * V_68 ,
int V_99 )
{
char V_95 [ 32 ] ;
struct V_89 * V_90 ;
int V_100 ;
snprintf ( V_95 , sizeof( V_95 ) , L_64 , V_2 -> V_101 , V_99 ) ;
V_100 = F_28 ( V_2 -> V_102 -> V_103 , V_95 , & V_90 ) ;
if ( V_100 < 0 )
return V_100 ;
F_29 ( V_90 , V_68 , F_24 ) ;
V_90 -> V_104 . V_105 . V_106 = F_25 ;
V_90 -> V_107 |= V_108 ;
V_68 -> V_109 = V_90 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_40 * V_68 )
{
if ( ! V_2 -> V_102 -> V_110 && V_68 -> V_109 ) {
F_31 ( V_2 -> V_102 -> V_103 , V_68 -> V_109 ) ;
V_68 -> V_109 = NULL ;
}
}
void F_32 ( struct V_40 * V_68 ,
struct V_111 * V_112 )
{
T_2 V_12 ;
T_3 V_113 ;
unsigned int V_114 ;
unsigned int V_115 ;
int V_11 ;
V_12 = V_116 | V_117 |
V_118 ;
V_113 = V_119 ;
V_114 = 16 ;
V_115 = 2 ;
for ( V_11 = 0 ; V_11 < V_68 -> V_54 ; V_11 ++ ) {
struct V_8 * V_9 = & V_68 -> V_63 [ V_11 ] ;
V_12 |= V_9 -> V_12 ;
if ( V_9 -> V_14 > V_115 )
V_115 = V_9 -> V_14 ;
if ( V_9 -> V_17 == V_19 ) {
if ( V_9 -> V_15 & V_120 ) {
V_113 |= V_121 ;
if ( V_114 < 20 )
V_114 = 20 ;
}
if ( V_9 -> V_15 & V_122 ) {
V_113 |= V_121 ;
if ( V_114 < 24 )
V_114 = 24 ;
}
}
}
V_112 -> V_12 &= V_12 ;
V_112 -> V_113 &= V_113 ;
V_112 -> V_114 = F_33 ( V_112 -> V_114 , V_114 ) ;
V_112 -> V_115 = F_33 ( V_112 -> V_115 , V_115 ) ;
}
