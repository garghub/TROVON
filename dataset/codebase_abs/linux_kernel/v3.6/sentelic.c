static unsigned char F_1 ( unsigned char V_1 )
{
switch ( V_1 ) {
case 10 : case 20 : case 40 : case 60 : case 80 : case 100 : case 200 :
return ( V_1 >> 4 ) | ( V_1 << 4 ) ;
default:
return V_1 ;
}
}
static unsigned char F_2 ( unsigned char V_1 )
{
switch ( V_1 ) {
case 0xe9 : case 0xee : case 0xf2 : case 0xff :
return ~ V_1 ;
default:
return V_1 ;
}
}
static int F_3 ( struct V_2 * V_2 , int V_3 , int * V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 3 ] ;
unsigned char V_6 ;
int V_7 = - 1 ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
F_6 ( V_4 , 0x66 , V_10 ) ;
F_6 ( V_4 , 0x88 , V_10 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
if ( ( V_6 = F_2 ( V_3 ) ) != V_3 ) {
F_6 ( V_4 , 0x68 , V_10 ) ;
} else if ( ( V_6 = F_1 ( V_3 ) ) != V_3 ) {
F_6 ( V_4 , 0xcc , V_10 ) ;
} else {
F_6 ( V_4 , 0x66 , V_10 ) ;
}
F_6 ( V_4 , V_6 , V_8 ) ;
if ( F_7 ( V_4 , V_5 , V_11 ) < 0 )
goto V_9;
* V_1 = V_5 [ 2 ] ;
V_7 = 0 ;
V_9:
F_8 ( V_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ,
L_1 ,
V_3 , * V_1 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_2 * V_2 , int V_3 , int V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_12 ;
int V_7 = - 1 ;
F_5 ( V_4 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
if ( ( V_12 = F_2 ( V_3 ) ) != V_3 ) {
F_6 ( V_4 , 0x74 , V_10 ) ;
} else {
if ( ( V_12 = F_1 ( V_3 ) ) != V_3 ) {
F_6 ( V_4 , 0x77 , V_10 ) ;
} else {
F_6 ( V_4 , 0x55 , V_10 ) ;
}
}
F_6 ( V_4 , V_12 , V_10 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
if ( ( V_12 = F_2 ( V_1 ) ) != V_1 ) {
F_6 ( V_4 , 0x47 , V_10 ) ;
} else if ( ( V_12 = F_1 ( V_1 ) ) != V_1 ) {
F_6 ( V_4 , 0x44 , V_10 ) ;
} else {
F_6 ( V_4 , 0x33 , V_10 ) ;
}
F_6 ( V_4 , V_12 , V_10 ) ;
V_7 = 0 ;
V_9:
F_8 ( V_4 ) ;
F_10 ( V_2 ,
L_2 ,
V_3 , V_1 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_2 * V_2 , bool V_13 )
{
int V_12 , V_14 ;
if ( F_3 ( V_2 , V_15 , & V_12 ) == - 1 )
return - 1 ;
if ( V_13 )
V_14 = V_12 | V_16 ;
else
V_14 = V_12 & ~ V_16 ;
if ( V_14 != V_12 )
if ( F_11 ( V_2 , V_15 , V_14 ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 , int * V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 3 ] ;
int V_7 = - 1 ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
F_6 ( V_4 , 0x66 , V_10 ) ;
F_6 ( V_4 , 0x88 , V_10 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
F_6 ( V_4 , 0x83 , V_10 ) ;
F_6 ( V_4 , 0x88 , V_10 ) ;
if ( F_7 ( V_4 , V_5 , V_11 ) )
goto V_9;
* V_1 = V_5 [ 2 ] ;
V_7 = 0 ;
V_9:
F_8 ( V_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ,
L_3 ,
* V_1 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_2 * V_2 , int V_1 )
{
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_12 ;
int V_7 = - 1 ;
F_5 ( V_4 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
F_6 ( V_4 , 0x38 , V_10 ) ;
F_6 ( V_4 , 0x88 , V_10 ) ;
if ( F_6 ( V_4 , 0xf3 , V_8 ) < 0 )
goto V_9;
if ( ( V_12 = F_2 ( V_1 ) ) != V_1 ) {
F_6 ( V_4 , 0x47 , V_10 ) ;
} else if ( ( V_12 = F_1 ( V_1 ) ) != V_1 ) {
F_6 ( V_4 , 0x44 , V_10 ) ;
} else {
F_6 ( V_4 , 0x33 , V_10 ) ;
}
F_6 ( V_4 , V_12 , V_10 ) ;
V_7 = 0 ;
V_9:
F_8 ( V_4 ) ;
F_10 ( V_2 ,
L_4 ,
V_1 , V_7 ) ;
return V_7 ;
}
static int F_15 ( struct V_2 * V_2 , int * V_17 )
{
if ( F_3 ( V_2 , V_18 , V_17 ) )
return - V_19 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_2 , int * V_20 )
{
if ( F_3 ( V_2 , V_21 , V_20 ) )
return - V_19 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_2 , int * V_22 )
{
int V_23 , V_24 , V_25 ;
int V_7 = - V_19 ;
if ( F_14 ( V_2 , V_26 ) )
goto V_9;
if ( F_3 ( V_2 , V_27 , & V_23 ) )
goto V_9;
if ( F_3 ( V_2 , V_28 , & V_24 ) )
goto V_9;
if ( F_3 ( V_2 , V_29 , & V_25 ) )
goto V_9;
* V_22 = ( V_23 << 16 ) | ( V_24 << 8 ) | V_25 ;
V_7 = 0 ;
V_9:
F_14 ( V_2 , V_30 ) ;
return V_7 ;
}
static int F_18 ( struct V_2 * V_2 , int * V_31 )
{
static const int V_32 [] = {
0x16 ,
0x06 ,
0x04 ,
0x02 ,
} ;
int V_33 ;
if ( F_3 ( V_2 , V_34 , & V_33 ) == - 1 )
return - V_19 ;
* V_31 = V_32 [ ( V_33 & 0x30 ) >> 4 ] ;
return 0 ;
}
static int F_19 ( struct V_2 * V_2 , bool V_13 )
{
int V_12 , V_14 ;
int V_35 = 0 ;
if ( F_3 ( V_2 , V_36 , & V_12 ) == - 1 ) {
F_20 ( V_2 , L_5 ) ;
return - V_19 ;
}
if ( V_13 )
V_14 = V_12 | V_37 ;
else
V_14 = V_12 & ~ V_37 ;
if ( V_14 != V_12 ) {
F_12 ( V_2 , true ) ;
V_35 = F_11 ( V_2 , V_36 , V_14 ) ;
F_12 ( V_2 , false ) ;
}
if ( V_35 != 0 ) {
F_20 ( V_2 , L_6 ) ;
V_35 = - V_19 ;
}
return V_35 ;
}
static int F_21 ( struct V_2 * V_2 , bool V_13 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_33 ;
if ( F_3 ( V_2 , V_41 , & V_33 ) )
return - V_19 ;
V_39 -> V_42 = V_13 ;
if ( V_13 )
V_33 |= ( V_43 | V_44 ) ;
else
V_33 &= ~ V_43 ;
if ( F_11 ( V_2 , V_41 , V_33 ) )
return - V_19 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_2 , bool V_13 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_33 , V_25 ;
if ( F_3 ( V_2 , V_41 , & V_33 ) )
return - V_19 ;
if ( F_3 ( V_2 , V_45 , & V_25 ) )
return - V_19 ;
V_39 -> V_46 = V_13 ;
if ( V_13 ) {
V_33 |= ( V_47 | V_44 ) ;
V_25 |= V_48 ;
} else {
V_33 &= ~ V_47 ;
V_25 &= ~ ( V_48 | V_49 | V_50 ) ;
}
if ( F_11 ( V_2 , V_41 , V_33 ) )
return - V_19 ;
if ( F_11 ( V_2 , V_45 , V_25 ) )
return - V_19 ;
return 0 ;
}
static T_1 F_23 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
int V_54 , V_33 ;
char * V_55 ;
T_1 V_56 ;
V_54 = F_24 ( V_52 , & V_55 , 16 ) ;
if ( V_55 == V_52 || * V_55 != ' ' || V_54 > 0xff )
return - V_57 ;
V_56 = F_25 ( V_55 + 1 , 16 , & V_33 ) ;
if ( V_56 )
return V_56 ;
if ( V_33 > 0xff )
return - V_57 ;
if ( F_12 ( V_2 , true ) )
return - V_19 ;
V_56 = F_11 ( V_2 , V_54 , V_33 ) < 0 ? - V_19 : V_53 ;
F_12 ( V_2 , false ) ;
return V_53 ;
}
static T_1 F_26 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return sprintf ( V_52 , L_7 , V_39 -> V_58 , V_39 -> V_59 ) ;
}
static T_1 F_27 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_54 , V_33 , V_60 ;
V_60 = F_25 ( V_52 , 16 , & V_54 ) ;
if ( V_60 )
return V_60 ;
if ( V_54 > 0xff )
return - V_57 ;
if ( F_3 ( V_2 , V_54 , & V_33 ) )
return - V_19 ;
V_39 -> V_58 = V_54 ;
V_39 -> V_59 = V_33 ;
return V_53 ;
}
static T_1 F_28 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
int V_33 = 0 ;
if ( F_13 ( V_2 , & V_33 ) )
return - V_19 ;
return sprintf ( V_52 , L_8 , V_33 ) ;
}
static T_1 F_29 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
int V_33 , V_60 ;
V_60 = F_25 ( V_52 , 16 , & V_33 ) ;
if ( V_60 )
return V_60 ;
if ( V_33 > 0xff )
return - V_57 ;
if ( F_14 ( V_2 , V_33 ) )
return - V_19 ;
return V_53 ;
}
static T_1 F_30 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return sprintf ( V_52 , L_9 , V_39 -> V_42 ) ;
}
static T_1 F_31 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
unsigned int V_33 ;
int V_60 ;
V_60 = F_32 ( V_52 , 10 , & V_33 ) ;
if ( V_60 )
return V_60 ;
if ( V_33 > 1 )
return - V_57 ;
F_21 ( V_2 , V_33 ) ;
return V_53 ;
}
static T_1 F_33 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return sprintf ( V_52 , L_9 , V_39 -> V_46 ) ;
}
static T_1 F_34 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
unsigned int V_33 ;
int V_60 ;
V_60 = F_32 ( V_52 , 10 , & V_33 ) ;
if ( V_60 )
return V_60 ;
if ( V_33 > 1 )
return - V_57 ;
F_22 ( V_2 , V_33 ) ;
return V_53 ;
}
static T_1 F_35 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return sprintf ( V_52 , L_10 ,
V_39 -> V_61 & V_62 ? 'C' : 'c' ) ;
}
static T_1 F_36 ( struct V_2 * V_2 , void * V_51 ,
const char * V_52 , T_2 V_53 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
T_2 V_63 ;
for ( V_63 = 0 ; V_63 < V_53 ; V_63 ++ ) {
switch ( V_52 [ V_63 ] ) {
case 'C' :
V_39 -> V_61 |= V_62 ;
break;
case 'c' :
V_39 -> V_61 &= ~ V_62 ;
break;
default:
return - V_57 ;
}
}
return V_53 ;
}
static T_1 F_37 ( struct V_2 * V_2 ,
void * V_51 , char * V_52 )
{
return sprintf ( V_52 , L_11 , V_64 ) ;
}
static void F_38 ( struct V_2 * V_2 , unsigned char V_65 [] )
{
static unsigned int V_66 ;
static unsigned int V_67 ;
unsigned int V_68 ;
const char * V_69 = L_12 ;
unsigned short V_70 = 0 , V_71 = 0 ;
switch ( V_65 [ 0 ] >> V_72 ) {
case V_73 :
V_69 = L_13 ;
V_70 = F_39 ( V_65 ) ;
V_71 = F_40 ( V_65 ) ;
break;
case V_74 :
V_69 = L_14 ;
break;
case V_75 :
V_69 = L_15 ;
break;
case V_76 :
V_69 = L_16 ;
break;
}
V_66 ++ ;
V_68 = F_41 ( V_77 ) ;
F_10 ( V_2 ,
L_17
L_18 ,
V_68 , V_69 ,
V_65 [ 0 ] , V_65 [ 1 ] , V_65 [ 2 ] , V_65 [ 3 ] , V_70 , V_71 ) ;
if ( V_68 - V_67 > 1000 ) {
F_10 ( V_2 , L_19 , V_66 ) ;
V_66 = 0 ;
V_67 = V_68 ;
}
}
static void F_38 ( struct V_2 * V_2 , unsigned char V_65 [] )
{
}
static void F_42 ( struct V_78 * V_79 , int V_80 , bool V_81 ,
unsigned int V_82 , unsigned int V_83 )
{
F_43 ( V_79 , V_80 ) ;
F_44 ( V_79 , V_84 , V_81 ) ;
if ( V_81 ) {
F_45 ( V_79 , V_85 , V_82 ) ;
F_45 ( V_79 , V_86 , V_83 ) ;
}
}
static T_3 F_46 ( struct V_2 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_79 ;
struct V_38 * V_87 = V_2 -> V_40 ;
unsigned char * V_65 = V_2 -> V_65 ;
unsigned char V_88 = 0 , V_89 = 0 , V_90 = 0 ;
unsigned short V_70 , V_71 , V_91 = 0 ;
int V_92 , V_93 ;
if ( V_2 -> V_94 < 4 )
return V_95 ;
F_38 ( V_2 , V_65 ) ;
switch ( V_2 -> V_65 [ 0 ] >> V_72 ) {
case V_73 :
if ( ( V_65 [ 0 ] == 0x48 || V_65 [ 0 ] == 0x49 ) &&
V_65 [ 1 ] == 0 && V_65 [ 2 ] == 0 ) {
V_65 [ 3 ] &= 0xf0 ;
}
V_70 = F_39 ( V_65 ) ;
V_71 = F_40 ( V_65 ) ;
if ( V_65 [ 0 ] & V_96 ) {
V_91 = 2 ;
if ( V_65 [ 0 ] & V_97 ) {
if ( V_87 -> V_98 == 2 ) {
V_91 = 1 ;
F_42 ( V_79 , 0 , false , 0 , 0 ) ;
}
V_87 -> V_98 = 2 ;
F_42 ( V_79 , 1 , V_91 == 2 , V_70 , V_71 ) ;
} else {
if ( V_87 -> V_98 == 1 ) {
V_91 = 1 ;
F_42 ( V_79 , 1 , false , 0 , 0 ) ;
}
V_87 -> V_98 = 1 ;
F_42 ( V_79 , 0 , V_91 != 0 , V_70 , V_71 ) ;
}
} else {
if ( ( V_65 [ 0 ] & ( V_99 | V_100 ) ) ==
V_99 ) {
V_65 [ 0 ] &= ~ V_99 ;
}
V_87 -> V_98 = 0 ;
if ( V_70 != 0 && V_71 != 0 )
V_91 = 1 ;
F_42 ( V_79 , 0 , V_91 > 0 , V_70 , V_71 ) ;
F_42 ( V_79 , 1 , false , 0 , 0 ) ;
}
if ( V_91 > 0 ) {
F_45 ( V_79 , V_101 , V_70 ) ;
F_45 ( V_79 , V_102 , V_71 ) ;
}
F_47 ( V_79 , V_103 , V_65 [ 0 ] & 0x01 ) ;
F_47 ( V_79 , V_104 , V_65 [ 0 ] & 0x02 ) ;
F_47 ( V_79 , V_105 , V_91 ) ;
F_47 ( V_79 , V_106 , V_91 == 1 ) ;
F_47 ( V_79 , V_107 , V_91 == 2 ) ;
break;
case V_76 :
if ( ( V_87 -> V_61 & V_62 ) != V_62 )
V_65 [ 0 ] &= ~ V_99 ;
case V_74 :
if ( V_65 [ 3 ] != 0 ) {
if ( V_65 [ 3 ] & F_48 ( 0 ) )
V_88 |= 0x01 ;
if ( V_65 [ 3 ] & F_48 ( 1 ) )
V_88 |= 0x0f ;
if ( V_65 [ 3 ] & F_48 ( 2 ) )
V_88 |= F_48 ( 4 ) ;
if ( V_65 [ 3 ] & F_48 ( 3 ) )
V_88 |= F_48 ( 5 ) ;
if ( V_88 != 0 )
V_65 [ 3 ] = V_88 ;
V_90 = ( V_65 [ 3 ] >> 4 ) & 1 ;
V_89 = ( V_65 [ 3 ] >> 5 ) & 1 ;
}
F_49 ( V_79 , V_108 ,
( int ) ( V_65 [ 3 ] & 8 ) - ( int ) ( V_65 [ 3 ] & 7 ) ) ;
F_49 ( V_79 , V_109 , V_89 - V_90 ) ;
F_47 ( V_79 , V_110 , V_89 ) ;
F_47 ( V_79 , V_111 , V_90 ) ;
F_47 ( V_79 , V_103 , V_65 [ 0 ] & 1 ) ;
F_47 ( V_79 , V_112 , ( V_65 [ 0 ] >> 2 ) & 1 ) ;
F_47 ( V_79 , V_104 , ( V_65 [ 0 ] >> 1 ) & 1 ) ;
V_92 = V_65 [ 1 ] ? ( int ) V_65 [ 1 ] - ( int ) ( ( V_65 [ 0 ] << 4 ) & 0x100 ) : 0 ;
V_93 = V_65 [ 2 ] ? ( int ) ( ( V_65 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_65 [ 2 ] : 0 ;
F_49 ( V_79 , V_113 , V_92 ) ;
F_49 ( V_79 , V_114 , V_93 ) ;
break;
}
F_50 ( V_79 ) ;
return V_115 ;
}
static int F_51 ( struct V_2 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_4 * V_4 = & V_2 -> V_4 ;
unsigned char V_5 [ 2 ] ;
int V_33 ;
V_5 [ 0 ] = 200 ;
F_52 ( V_4 , V_5 , V_116 ) ;
V_5 [ 0 ] = 200 ;
F_52 ( V_4 , V_5 , V_116 ) ;
V_5 [ 0 ] = 80 ;
F_52 ( V_4 , V_5 , V_116 ) ;
F_52 ( V_4 , V_5 , V_117 ) ;
if ( V_5 [ 0 ] != 0x04 ) {
F_20 ( V_2 ,
L_20 ) ;
return - V_19 ;
}
if ( V_39 -> V_118 < V_119 ) {
if ( F_3 ( V_2 , V_45 , & V_33 ) ) {
F_20 ( V_2 ,
L_21 ) ;
return - V_19 ;
}
if ( F_18 ( V_2 , & V_39 -> V_32 ) ) {
F_20 ( V_2 ,
L_22 ) ;
return - V_19 ;
}
V_33 &= ~ ( V_49 | V_50 | V_120 ) ;
V_33 &= ~ V_121 ;
if ( V_39 -> V_32 == 0x06 ) {
V_33 |= V_48 ;
}
if ( F_11 ( V_2 , V_45 , V_33 ) ) {
F_20 ( V_2 ,
L_23 ) ;
return - V_19 ;
}
if ( F_19 ( V_2 , true ) )
F_53 ( V_2 ,
L_24 ) ;
V_39 -> V_61 |= V_62 ;
F_21 ( V_2 , true ) ;
F_22 ( V_2 , true ) ;
} else {
if ( F_11 ( V_2 , V_122 ,
V_123 |
V_124 |
V_125 |
V_126 ) ) {
F_20 ( V_2 ,
L_25 ) ;
return - V_19 ;
}
}
return 0 ;
}
static int F_54 ( struct V_2 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_79 ;
struct V_38 * V_39 = V_2 -> V_40 ;
if ( V_39 -> V_118 < V_119 ) {
F_55 ( V_112 , V_79 -> V_127 ) ;
F_55 ( V_110 , V_79 -> V_127 ) ;
F_55 ( V_111 , V_79 -> V_127 ) ;
F_55 ( V_108 , V_79 -> V_128 ) ;
F_55 ( V_109 , V_79 -> V_128 ) ;
} else {
int V_70 = 967 , V_71 = 711 ;
F_55 ( V_129 , V_79 -> V_130 ) ;
F_56 ( V_131 , V_79 -> V_130 ) ;
F_55 ( V_105 , V_79 -> V_127 ) ;
F_55 ( V_106 , V_79 -> V_127 ) ;
F_55 ( V_107 , V_79 -> V_127 ) ;
F_55 ( V_132 , V_79 -> V_133 ) ;
F_57 ( V_79 , V_101 , 0 , V_70 , 0 , 0 ) ;
F_57 ( V_79 , V_102 , 0 , V_71 , 0 , 0 ) ;
F_58 ( V_79 , 2 ) ;
F_57 ( V_79 , V_85 , 0 , V_70 , 0 , 0 ) ;
F_57 ( V_79 , V_86 , 0 , V_71 , 0 , 0 ) ;
}
return 0 ;
}
int F_59 ( struct V_2 * V_2 , bool V_134 )
{
int V_135 ;
if ( F_3 ( V_2 , V_136 , & V_135 ) )
return - V_19 ;
if ( V_135 != 0x01 )
return - V_137 ;
if ( V_134 ) {
V_2 -> V_138 = L_26 ;
V_2 -> V_139 = L_27 ;
}
return 0 ;
}
static void F_60 ( struct V_2 * V_2 )
{
F_19 ( V_2 , false ) ;
F_21 ( V_2 , false ) ;
F_22 ( V_2 , false ) ;
}
static void F_61 ( struct V_2 * V_2 )
{
F_62 ( & V_2 -> V_4 . V_140 -> V_79 . V_141 ,
& V_142 ) ;
F_60 ( V_2 ) ;
F_63 ( V_2 -> V_40 ) ;
}
static int F_64 ( struct V_2 * V_2 )
{
int V_17 ;
if ( F_59 ( V_2 , 0 ) )
return - V_137 ;
if ( F_15 ( V_2 , & V_17 ) )
return - V_137 ;
if ( F_51 ( V_2 ) )
return - V_19 ;
return 0 ;
}
int F_65 ( struct V_2 * V_2 )
{
struct V_38 * V_143 ;
int V_118 , V_20 , V_22 = 0 ;
int error ;
if ( F_15 ( V_2 , & V_118 ) ||
F_16 ( V_2 , & V_20 ) ) {
return - V_137 ;
}
if ( V_118 >= V_119 ) {
F_17 ( V_2 , & V_22 ) ;
}
F_66 ( V_2 ,
L_28 ,
V_118 >> 4 , V_118 & 0x0F , V_20 , V_22 , V_64 ) ;
V_2 -> V_40 = V_143 = F_67 ( sizeof( struct V_38 ) , V_144 ) ;
if ( ! V_143 )
return - V_145 ;
V_143 -> V_118 = V_118 ;
V_143 -> V_20 = V_20 ;
V_2 -> V_146 = F_46 ;
V_2 -> V_147 = F_61 ;
V_2 -> V_148 = F_64 ;
V_2 -> V_149 = F_60 ;
V_2 -> V_150 = 4 ;
error = F_51 ( V_2 ) ;
if ( error )
goto V_151;
error = F_54 ( V_2 ) ;
if ( error )
goto V_151;
error = F_68 ( & V_2 -> V_4 . V_140 -> V_79 . V_141 ,
& V_142 ) ;
if ( error ) {
F_20 ( V_2 ,
L_29 , error ) ;
goto V_151;
}
return 0 ;
V_151:
F_63 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
return error ;
}
