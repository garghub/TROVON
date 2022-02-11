static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
V_4 -> V_8 = F_2 ( 256 , V_6 ) ;
if ( ! V_4 -> V_8 ) {
F_3 ( V_4 ) ;
return - V_7 ;
}
V_4 -> V_9 = F_2 ( 256 , V_6 ) ;
if ( ! V_4 -> V_9 ) {
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return - V_7 ;
}
V_4 -> V_10 = V_11 ;
F_4 ( & V_4 -> V_12 ) ;
F_5 ( & V_4 -> V_13 ) ;
F_6 ( V_2 , V_4 ) ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_4 -> V_9 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_3 ( V_4 -> V_9 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_19 ;
F_12 ( & V_2 -> V_20 , L_1 ,
V_21 , V_16 , V_17 ) ;
F_13 ( & V_4 -> V_12 , V_19 ) ;
if ( ( V_16 & V_22 ) && ! ( V_4 -> V_23 == V_22 ) ) {
F_12 ( & V_2 -> V_20 , L_2 , V_21 ) ;
V_4 -> V_24 = 1 ;
}
if ( V_16 & V_22 )
V_4 -> V_23 = V_22 ;
F_14 ( & V_4 -> V_12 , V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_19 ;
int V_25 ;
F_13 ( & V_4 -> V_12 , V_19 ) ;
V_25 = V_4 -> V_23 ;
F_14 ( & V_4 -> V_12 , V_19 ) ;
return V_25 ;
}
static void F_16 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_28 ;
int V_29 = V_26 -> V_29 ;
if ( V_29 ) {
F_12 ( & V_2 -> V_20 , L_3 , V_21 , V_29 ) ;
return;
}
memset ( V_2 -> V_30 -> V_31 , V_32 , 1 ) ;
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 1 ,
V_35 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
int V_28 ;
char * V_38 = V_2 -> V_30 -> V_31 ;
* V_38 ++ = V_39 ;
* V_38 ++ = V_40 ;
* V_38 ++ = V_37 ;
* V_38 = V_41 ;
F_17 ( V_2 -> V_30 ,
V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 4 , F_16 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
V_4 -> V_24 = 0 ;
return V_28 ;
}
static void F_21 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
T_1 * V_42 ;
int V_29 = V_26 -> V_29 ;
if ( V_29 ) {
F_12 ( & V_2 -> V_20 , L_3 , V_21 , V_29 ) ;
return;
}
V_42 = V_26 -> V_31 ;
F_12 ( & V_2 -> V_20 , L_4 , V_21 ) ;
if ( V_26 -> V_43 == 1 ) {
switch ( V_42 [ 0 ] ) {
case 0x1 :
V_4 -> V_23 = V_44 ;
break;
case 0x0 :
V_4 -> V_23 = V_45 ;
break;
default:
V_4 -> V_23 = V_45 ;
}
}
F_16 ( V_26 ) ;
}
static void F_22 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_28 ;
int V_29 = V_26 -> V_29 ;
F_12 ( & V_2 -> V_20 , L_3 , V_21 , V_29 ) ;
F_17 ( V_2 -> V_46 , V_2 -> V_33 -> V_20 ,
F_23 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_47 ) ,
V_2 -> V_46 -> V_31 , 256 ,
F_21 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_46 , V_36 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_28 ;
memset ( V_2 -> V_30 -> V_31 , V_48 , 1 ) ;
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 1 ,
F_22 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
return V_28 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_8 , T_1 V_49 )
{
int V_29 ;
struct V_50 * V_33 = V_2 -> V_33 ;
int V_51 = 0 ;
V_29 =
F_26 ( V_33 -> V_20 ,
F_18 ( V_33 -> V_20 ,
V_2 -> V_34 ) , V_8 ,
V_49 , & V_51 , V_52 * 1 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_5 , V_21 , V_29 ) ;
else
F_12 ( & V_2 -> V_20 , L_6 , V_21 ) ;
return V_29 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_8 , T_1 V_49 )
{
int V_29 ;
struct V_50 * V_33 = V_2 -> V_33 ;
int V_51 = 0 ;
V_29 =
F_26 ( V_33 -> V_20 ,
F_23 ( V_33 -> V_20 ,
V_2 -> V_47 ) , V_8 ,
V_49 , & V_51 , V_52 * 1 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_5 , V_21 , V_29 ) ;
else
F_12 ( & V_2 -> V_20 , L_7 , V_21 ) ;
return V_29 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned int V_55 , unsigned int V_56 , T_1 V_57 )
{
int V_29 ;
T_1 * V_8 ;
V_8 = F_29 ( 8 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_58 ;
V_8 [ 1 ] = V_54 & 0xFF ;
V_8 [ 2 ] = ( V_54 >> 8 ) & 0xFF ;
V_8 [ 3 ] = V_55 & 0xFF ;
V_8 [ 4 ] = ( V_55 >> 8 ) & 0xFF ;
V_8 [ 5 ] = V_56 & 0xFF ;
V_8 [ 6 ] = ( V_56 >> 8 ) & 0xFF ;
V_8 [ 7 ] = V_57 ;
V_29 = F_25 ( V_2 , V_8 , 8 ) ;
F_3 ( V_8 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_8 , V_21 , V_29 ) ;
else
F_12 ( & V_2 -> V_20 , L_9 , V_21 ) ;
return V_53 ;
}
static void F_30 ( T_1 * V_8 , T_1 V_59 , T_1 V_60 , T_1 V_61 , T_1 V_62 , T_1 V_63 ,
T_1 V_64 , T_1 V_65 )
{
* V_8 ++ = V_58 ;
* V_8 ++ = V_59 ;
* V_8 ++ = V_60 ;
* V_8 ++ = V_61 ;
* V_8 ++ = V_62 ;
* V_8 ++ = V_63 ;
* V_8 ++ = V_64 ;
* V_8 = V_65 ;
}
static void F_31 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_28 ;
char * V_38 = V_2 -> V_30 -> V_31 ;
* V_38 ++ = V_58 ;
if ( V_66 == 1 ) {
F_32 ( V_38 , 6 ) ;
* ( V_38 + 7 ) = 1 ;
} else {
F_30 ( V_38 , 255 , 255 , 0 , 0 , 0 , 0 , 255 ) ;
}
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 8 ,
F_16 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
}
static void F_33 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_28 ;
char * V_38 = V_2 -> V_30 -> V_31 ;
if ( V_66 == 1 ) {
F_16 ( V_26 ) ;
return;
} else {
* V_38 ++ = V_58 ;
F_30 ( V_38 , 0 , 0 , 255 , 255 , 0 , 0 , 255 ) ;
}
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 8 ,
F_16 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_67 )
{
int V_29 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
int V_68 = 0 ;
T_1 V_69 = 0x69 ;
T_1 DIV = 0 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
unsigned int V_76 = 0 ;
unsigned int V_77 = 0 ;
int V_78 = ( int ) V_67 ;
if ( V_78 == 0 ) {
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x09 ;
V_4 -> V_8 [ V_68 ++ ] = 0x00 ;
V_29 = F_25 ( V_2 , ( T_1 * ) V_4 -> V_8 , V_68 ) ;
if ( V_29 != 0 ) {
F_12 ( & V_2 -> V_20 , L_10 , V_21 ) ;
return V_29 ;
}
} else if ( V_78 == 3579000 ) {
DIV = 100 ;
V_76 = 1193 ;
V_75 = 40 ;
V_70 = 0 ;
} else if ( V_78 == 3680000 ) {
DIV = 105 ;
V_76 = 161 ;
V_75 = 5 ;
V_70 = 0 ;
} else if ( V_78 == 6000000 ) {
DIV = 66 ;
V_76 = 66 ;
V_75 = 2 ;
V_70 = 0x28 ;
} else {
unsigned int V_28 = 0 ;
unsigned int V_80 = 0 ;
unsigned int V_81 ;
unsigned int V_82 ;
char V_83 = 0x00 ;
unsigned int V_84 = 2 ;
unsigned int V_85 = 2055 ;
unsigned int lDiv = 4 ;
for ( V_84 = 2 ; V_84 <= 47 && ! V_83 ; V_84 ++ )
for ( V_85 = 2055 ; V_85 >= 8 && ! V_83 ; V_85 -- )
for ( lDiv = 4 ; lDiv <= 127 && ! V_83 ; lDiv ++ ) {
V_80 = ( 12000000 / lDiv ) * ( V_85 / V_84 ) ;
if ( abs ( ( int ) ( V_80 - V_78 ) ) <
abs ( ( int ) ( V_78 - V_28 ) ) ) {
V_82 = ( 12000000 / V_84 ) ;
if ( V_82 < 250000 )
continue;
V_81 = ( 12000000 / V_84 ) * V_85 ;
if ( V_81 > 400000000 )
continue;
if ( V_81 < 100000000 )
continue;
if ( lDiv < 4 || lDiv > 127 )
continue;
V_28 = V_80 ;
V_76 = V_85 ;
DIV = lDiv ;
V_75 = V_84 ;
if ( V_28 == V_78 )
V_83 = 0x01 ;
}
}
}
V_77 = ( ( V_76 - V_74 ) / 2 ) - 4 ;
DIV = DIV ;
V_71 = 0x04 ;
V_72 = ( V_77 >> 8 & 0x03 ) ;
V_73 = V_77 & 0xFF ;
V_74 = ( V_76 >> 10 ) & 0x01 ;
V_75 = V_75 - 2 ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x09 ;
V_4 -> V_8 [ V_68 ++ ] = 0x20 ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x0C ;
V_4 -> V_8 [ V_68 ++ ] = DIV ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x12 ;
V_4 -> V_8 [ V_68 ++ ] = V_70 ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x13 ;
V_4 -> V_8 [ V_68 ++ ] = 0x6B ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x40 ;
V_4 -> V_8 [ V_68 ++ ] = ( 0xC0 | ( ( V_71 & 0x07 ) << 2 ) ) |
( V_72 & 0x03 ) ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x41 ;
V_4 -> V_8 [ V_68 ++ ] = V_73 ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x42 ;
V_4 -> V_8 [ V_68 ++ ] = V_75 | ( ( ( V_74 & 0x01 ) << 7 ) ) ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x44 ;
V_4 -> V_8 [ V_68 ++ ] = ( char ) 0xFF ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x45 ;
V_4 -> V_8 [ V_68 ++ ] = ( char ) 0xFE ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x46 ;
V_4 -> V_8 [ V_68 ++ ] = 0x7F ;
V_4 -> V_8 [ V_68 ++ ] = V_79 ;
V_4 -> V_8 [ V_68 ++ ] = V_69 << 1 ;
V_4 -> V_8 [ V_68 ++ ] = 0x47 ;
V_4 -> V_8 [ V_68 ++ ] = ( char ) 0x84 ;
V_29 = F_25 ( V_2 , ( T_1 * ) V_4 -> V_8 , V_68 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_10 , V_21 ) ;
return V_29 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_86 * V_20 = & V_2 -> V_20 ;
int V_87 ;
int V_29 ;
T_1 V_88 = V_32 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
if ( F_28 ( V_2 , 0xF000 , 0 , 0 , 0xFF ) < 0 )
return - V_89 ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
V_29 = F_25 ( V_2 , & V_88 , 1 ) ;
if ( V_29 != V_53 ) {
F_12 ( V_20 , L_11 , V_21 ) ;
return V_29 ;
}
V_29 = F_27 ( V_2 , & V_4 -> V_90 , 1 ) ;
if ( V_29 != V_53 ) {
F_12 ( V_20 , L_12 , V_21 ) ;
return V_29 ;
}
if ( V_4 -> V_90 > 0 ) {
F_12 ( V_20 , L_13 , V_21 , V_4 -> V_90 ) ;
V_29 = F_27 ( V_2 , V_4 -> V_8 , V_4 -> V_90 ) ;
if ( V_29 != V_53 ) {
F_12 ( V_20 , L_12 , V_21 ) ;
return V_29 ;
}
}
}
F_12 ( V_20 , L_14 , V_21 ) ;
F_28 ( V_2 , 0 , 0xF000 , 0 , 0xFF ) ;
return V_29 ;
}
static void F_36 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
unsigned char * V_91 = V_26 -> V_31 ;
int V_29 = V_26 -> V_29 ;
if ( V_29 ) {
if ( V_29 == - V_92 ) {
}
return;
}
F_12 ( & V_2 -> V_20 , L_15 , V_21 , V_26 -> V_43 ) ;
if ( V_91 == NULL )
F_12 ( & V_2 -> V_20 , L_16 , V_21 ) ;
if ( V_26 -> V_43 && V_91 ) {
F_37 ( & V_2 -> V_2 , V_91 , V_26 -> V_43 ) ;
F_38 ( & V_2 -> V_2 ) ;
}
F_31 ( V_26 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_19 ;
int V_28 ;
int V_93 ;
char * V_38 = V_2 -> V_30 -> V_31 ;
F_13 ( & V_4 -> V_12 , V_19 ) ;
* V_38 ++ = V_94 ;
* V_38 ++ = V_95 ;
* V_38 ++ = V_4 -> V_96 ;
memcpy ( V_38 , V_4 -> V_9 , V_4 -> V_96 ) ;
V_93 = V_4 -> V_96 ;
V_4 -> V_96 = 0 ;
F_14 ( & V_4 -> V_12 , V_19 ) ;
F_12 ( & V_2 -> V_20 , L_17 , V_21 ,
V_93 , V_93 , V_38 ) ;
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , V_93 + 3 ,
F_16 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_36 ) ;
F_40 ( V_2 ) ;
return V_28 ;
}
static int F_41 ( struct V_1 * V_2 , int V_90 )
{
int V_28 ;
F_17 ( V_2 -> V_46 , V_2 -> V_33 -> V_20 ,
F_23 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_47 ) ,
V_2 -> V_46 -> V_31 , V_90 ,
F_36 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_46 , V_36 ) ;
return V_28 ;
}
static void F_42 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_19 ;
int V_29 = V_26 -> V_29 ;
int error = 0 ;
int V_90 = 0 ;
unsigned char * V_91 = V_26 -> V_31 ;
V_4 -> V_97 ++ ;
if ( V_29 ) {
F_12 ( & V_2 -> V_20 , L_3 , V_21 , V_29 ) ;
return;
}
if ( V_91 == NULL )
F_12 ( & V_2 -> V_20 , L_16 , V_21 ) ;
if ( V_26 -> V_43 == 1 && V_91 != NULL )
V_90 = ( int ) V_91 [ 0 ] ;
if ( V_26 -> V_43 > 1 ) {
F_12 ( & V_2 -> V_20 , L_18 , V_21 ,
V_26 -> V_43 ) ;
error = 1 ;
return;
}
if ( V_90 > 0 && error == 0 ) {
F_12 ( & V_2 -> V_20 , L_19 ,
V_21 , V_90 ) ;
V_29 = F_41 ( V_2 , V_90 ) ;
return;
}
if ( V_4 -> V_97 > 99 ) {
V_29 = F_24 ( V_2 ) ;
V_4 -> V_97 = 0 ;
return;
}
if ( V_4 -> V_24 == 1 ) {
V_29 = F_20 ( V_2 , 0xC ) ;
return;
}
F_13 ( & V_4 -> V_12 , V_19 ) ;
if ( V_4 -> V_96 > 0 ) {
F_14 ( & V_4 -> V_12 , V_19 ) ;
V_29 = F_39 ( V_2 ) ;
return;
}
F_14 ( & V_4 -> V_12 , V_19 ) ;
F_12 ( & V_2 -> V_20 , L_20 , V_21 ) ;
F_33 ( V_26 ) ;
}
static int F_43 ( struct V_14 * V_15 , struct V_1 * V_2 ,
const T_1 * V_8 , int V_49 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_19 ;
if ( V_49 > 256 )
return - V_7 ;
F_13 ( & V_4 -> V_12 , V_19 ) ;
memcpy ( V_4 -> V_9 + V_4 -> V_96 , V_8 , V_49 ) ;
V_4 -> V_96 += V_49 ;
F_14 ( & V_4 -> V_12 , V_19 ) ;
return V_49 ;
}
static void V_35 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_28 ;
int V_29 = V_26 -> V_29 ;
if ( V_29 ) {
return;
}
F_17 ( V_2 -> V_46 , V_2 -> V_33 -> V_20 ,
F_23 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_47 ) ,
V_2 -> V_46 -> V_31 , 256 ,
F_42 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_46 , V_36 ) ;
F_12 ( & V_2 -> V_20 , L_21 , V_21 , V_28 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_29 ;
T_1 * V_8 ;
V_8 = F_29 ( sizeof( T_1 ) * 4 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_98 ;
V_8 [ 1 ] = ( T_1 ) ( ( V_99 >> 8 ) & 0x00FF ) ;
V_8 [ 2 ] = ( T_1 ) ( 0x00FF & V_99 ) ;
V_8 [ 3 ] = ( T_1 ) ( 0x0F0 & V_100 ) | ( 0x07 & V_101 ) ;
V_29 = F_25 ( V_2 , V_8 , 4 ) ;
if ( V_29 != V_53 ) {
F_12 ( & V_2 -> V_20 , L_22 , V_21 ) ;
goto V_102;
}
V_29 = F_35 ( V_2 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_23 , V_21 ) ;
V_102:
F_3 ( V_8 ) ;
return V_29 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_29 ;
T_1 * V_8 ;
V_8 = F_29 ( 1 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_103 ;
V_29 = F_25 ( V_2 , V_8 , 1 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_24 , V_21 ) ;
F_3 ( V_8 ) ;
return V_29 ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_104 ,
T_2 * V_51 , T_1 V_105 )
{
int V_29 ;
T_2 V_106 ;
T_1 * V_107 ;
T_1 V_108 = 0 ;
T_1 V_109 = 0 ;
T_1 V_110 = 0 ;
unsigned int V_111 = 0 ;
F_12 ( & V_2 -> V_20 , L_25 , V_21 , V_104 ) ;
V_107 = F_29 ( sizeof( T_1 ) * 5 , V_6 ) ;
if ( ! V_107 )
return - V_7 ;
V_106 = V_104 ;
if ( V_106 < 1200 || V_106 > 230400 ) {
F_3 ( V_107 ) ;
return V_112 ;
}
if ( V_106 > 977 ) {
V_109 = 3 ;
V_111 = 500000 ;
}
if ( V_106 > 3906 ) {
V_109 = 2 ;
V_111 = 2000000 ;
}
if ( V_106 > 11718 ) {
V_109 = 1 ;
V_111 = 6000000 ;
}
if ( V_106 > 46875 ) {
V_109 = 0 ;
V_111 = 24000000 ;
}
V_110 = 256 - ( T_1 ) ( V_111 / ( V_106 * 2 ) ) ;
V_107 [ V_108 ++ ] = V_94 ;
V_107 [ V_108 ++ ] = V_113 ;
V_107 [ V_108 ++ ] = V_109 ;
V_107 [ V_108 ++ ] = V_110 ;
* V_51 = ( V_111 / ( 256 - V_110 ) ) / 2 ;
switch ( V_105 & 0x0F ) {
case V_114 :
V_107 [ V_108 ++ ] = 0x00 ;
break;
case V_101 :
V_107 [ V_108 ++ ] = 0x01 ;
break;
case V_115 :
V_107 [ V_108 ++ ] = 0x02 ;
break;
case V_116 :
V_107 [ V_108 ++ ] = 0x03 ;
break;
case V_117 :
V_107 [ V_108 ++ ] = 0x04 ;
break;
default:
F_3 ( V_107 ) ;
return V_112 ;
break;
}
switch ( V_105 & 0xF0 ) {
case V_100 :
V_107 [ V_108 - 1 ] |= V_100 ;
break;
case V_118 :
V_107 [ V_108 - 1 ] |= V_118 ;
break;
default:
F_3 ( V_107 ) ;
return V_112 ;
break;
}
V_29 = F_25 ( V_2 , V_107 , V_108 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_24 , V_21 ) ;
F_3 ( V_107 ) ;
return V_29 ;
}
static void F_47 ( struct V_14 * V_15 ,
struct V_1 * V_2 , struct V_119 * V_120 )
{
const T_2 V_121 = V_122 | V_123 | V_124 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned int V_125 = V_15 -> V_126 . V_127 ;
int V_29 ;
T_2 V_51 ;
T_2 V_105 ;
int V_128 = V_129 ;
int V_106 ;
T_2 V_130 = V_125 & V_121 ;
V_106 = V_15 -> V_126 . V_131 ;
F_12 ( & V_2 -> V_20 , L_26 , V_21 , V_106 ) ;
V_105 = 0 ;
if ( V_125 & V_122 ) {
if ( V_125 & V_124 )
V_105 |= V_117 ;
else
V_105 |= V_116 ;
} else if ( ! ( V_125 & V_123 ) ) {
V_105 |= V_114 ;
V_128 = V_132 ;
} else if ( V_125 & V_124 )
V_105 |= V_115 ;
else
V_105 |= V_101 ;
V_105 |= ( V_125 & V_133 ? V_118 : V_100 ) ;
V_29 = F_46 ( V_2 ,
V_106 * V_4 -> V_134 / 100 ,
& V_51 , V_105 ) ;
if ( V_120 )
F_48 ( & V_15 -> V_126 , V_120 ) ;
if ( V_29 != 0 )
return;
F_49 ( V_15 , V_106 , V_106 ) ;
V_15 -> V_126 . V_127 &= ~ ( V_121 | V_135 ) ;
V_15 -> V_126 . V_127 |= V_130 | V_128 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_50 * V_33 ;
V_33 = V_2 -> V_33 ;
if ( ! V_33 )
return;
F_45 ( V_2 ) ;
if ( V_33 -> V_20 ) {
F_12 ( & V_2 -> V_20 , L_27 , V_21 ) ;
F_51 ( V_2 -> V_30 ) ;
F_51 ( V_2 -> V_46 ) ;
F_51 ( V_2 -> V_136 ) ;
F_28 ( V_2 , 0 , 0 , 0xF000 , 0xFF ) ;
}
}
static void F_52 ( struct V_14 * V_15 )
{
V_15 -> V_126 = V_137 ;
V_15 -> V_126 . V_127 = V_138 | V_139 | V_132 | V_140
| V_141 | V_133 | V_123 ;
V_15 -> V_126 . V_142 = 9600 ;
V_15 -> V_126 . V_131 = 9600 ;
V_15 -> V_126 . V_143 = 0 ;
V_15 -> V_126 . V_144 = 0 ;
V_15 -> V_126 . V_145 = 0 ;
}
static int F_53 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_50 * V_33 = V_2 -> V_33 ;
struct V_86 * V_20 = & V_2 -> V_20 ;
T_1 * V_8 ;
int V_28 ;
int V_106 ;
T_2 V_51 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
V_106 = V_15 -> V_126 . V_131 ;
V_15 -> V_126 . V_142 = V_106 ;
F_49 ( V_15 , V_106 , V_106 ) ;
F_12 ( V_20 , L_28 , V_21 , V_106 ) ;
F_54 ( V_33 -> V_20 , V_2 -> V_30 -> V_146 ) ;
F_54 ( V_33 -> V_20 , V_2 -> V_46 -> V_146 ) ;
V_8 = F_29 ( 10 , V_6 ) ;
if ( V_8 == NULL )
return - V_7 ;
V_4 -> V_97 = 0 ;
#define F_55 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_rcvctrlpipe(port->serial->dev, 0), \
b, a, c, d, buf, 1, 1000); \
dev_dbg(dev, "0x%x:0x%x:0x%x:0x%x %d - %x\n", a, b, c, d, result, \
buf[0]); } while (0);
#define F_56 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_sndctrlpipe(port->serial->dev, 0), \
b, a, c, d, NULL, 0, 1000); \
dev_dbg(dev, "0x%x:0x%x:0x%x:0x%x %d\n", a, b, c, d, result); } while (0)
F_56 ( 0x03 , 0x02 , 0x02 , 0x0 ) ;
F_3 ( V_8 ) ;
F_28 ( V_2 , 0xF000 , 0xF000 , 0 , 0xFF ) ;
F_44 ( V_2 ) ;
if ( V_134 < 100 )
V_134 = 100 ;
V_4 -> V_134 = V_134 ;
V_4 -> V_106 = V_106 ;
switch ( V_147 ) {
case 2 :
V_4 -> V_148 = V_149 ;
F_34 ( V_2 , V_149 * V_134 / 100 ) ;
V_28 =
F_46 ( V_2 , V_106 * V_134 / 100 , & V_51 ,
V_101 ) ;
break;
case 3 :
F_34 ( V_2 , V_150 * V_134 / 100 ) ;
V_4 -> V_148 = V_150 ;
V_28 =
F_46 ( V_2 , 16457 * V_134 / 100 , & V_51 ,
V_101 ) ;
break;
default:
F_34 ( V_2 , V_151 * V_134 / 100 ) ;
V_4 -> V_148 = V_151 ;
V_28 =
F_46 ( V_2 , V_106 * V_134 / 100 , & V_51 ,
V_101 ) ;
}
switch ( V_152 ) {
case 0 :
V_45 = 0 ;
V_44 = 0 ;
break;
case 1 :
V_45 = V_153 ;
V_44 = 0 ;
break;
case 2 :
V_45 = 0 ;
V_44 = V_153 ;
break;
case 3 :
V_45 = V_154 ;
V_44 = 0 ;
break;
case 4 :
V_45 = 0 ;
V_44 = V_154 ;
break;
case 5 :
V_45 = V_141 ;
V_44 = 0 ;
break;
case 6 :
V_45 = 0 ;
V_44 = V_141 ;
break;
case 7 :
V_45 = V_155 ;
V_44 = 0 ;
break;
case 8 :
V_45 = 0 ;
V_44 = V_155 ;
}
F_35 ( V_2 ) ;
F_12 ( V_20 , L_29 , V_21 ) ;
memset ( V_2 -> V_30 -> V_31 , V_32 , 1 ) ;
F_17 ( V_2 -> V_30 , V_2 -> V_33 -> V_20 ,
F_18 ( V_2 -> V_33 -> V_20 ,
V_2 -> V_34 ) ,
V_2 -> V_30 -> V_31 , 1 ,
V_35 , V_2 ) ;
V_28 = F_19 ( V_2 -> V_30 , V_6 ) ;
if ( V_28 ) {
F_57 ( V_20 , L_30 , V_21 , V_28 ) ;
F_50 ( V_2 ) ;
} else {
F_12 ( V_20 , L_31 , V_21 ) ;
}
return V_28 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_29 ;
T_1 * V_8 ;
V_8 = F_29 ( 5 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_156 ;
V_8 [ 1 ] = V_10 & 0xFF ;
V_8 [ 2 ] = ( V_10 >> 8 ) & 0xFF ;
V_8 [ 3 ] = ( V_10 >> 16 ) & 0xFF ;
V_8 [ 4 ] = ( V_10 >> 24 ) & 0xFF ;
V_29 = F_25 ( V_2 , V_8 , 5 ) ;
F_3 ( V_8 ) ;
if ( V_29 != V_53 )
F_12 ( & V_2 -> V_20 , L_32 , V_21 , V_29 ) ;
else
F_12 ( & V_2 -> V_20 , L_33 , V_21 ) ;
return V_29 ;
}
static T_7 F_59 ( struct V_86 * V_20 ,
struct V_157 * V_158 , char * V_8 )
{
struct V_1 * V_2 = F_60 ( V_20 ) ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
return sprintf ( V_8 , L_34 , V_4 -> V_10 ) ;
}
static T_7 F_61 ( struct V_86 * V_20 ,
struct V_157 * V_158 , const char * V_8 , T_8 V_49 )
{
struct V_1 * V_2 = F_60 ( V_20 ) ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_159 ;
if ( F_62 ( V_8 , 10 , & V_159 ) ) {
F_57 ( V_20 , L_35 ,
V_21 , V_8 ) ;
goto V_160;
}
F_12 ( V_20 , L_36 , V_21 , V_159 ) ;
if ( ( V_159 != 3 ) && ( V_159 != 5 ) ) {
F_57 ( V_20 , L_37 , V_21 , V_159 ) ;
} else {
F_58 ( V_2 , V_159 ) ;
V_4 -> V_10 = V_159 ;
}
V_160:
return V_49 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_63 ( & V_2 -> V_20 , & V_161 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_20 , & V_161 ) ;
return 0 ;
}
