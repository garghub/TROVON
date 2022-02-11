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
F_5 ( V_2 , V_4 ) ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_4 -> V_9 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_3 ( V_4 -> V_9 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
unsigned int V_15 , unsigned int V_16 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_18 ;
F_11 ( & V_2 -> V_19 , L_1 ,
V_20 , V_15 , V_16 ) ;
F_12 ( & V_4 -> V_12 , V_18 ) ;
if ( ( V_15 & V_21 ) && ! ( V_4 -> V_22 == V_21 ) ) {
F_11 ( & V_2 -> V_19 , L_2 , V_20 ) ;
V_4 -> V_23 = 1 ;
}
if ( V_15 & V_21 )
V_4 -> V_22 = V_21 ;
F_13 ( & V_4 -> V_12 , V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_18 ;
int V_24 ;
F_12 ( & V_4 -> V_12 , V_18 ) ;
V_24 = V_4 -> V_22 ;
F_13 ( & V_4 -> V_12 , V_18 ) ;
return V_24 ;
}
static void F_15 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
int V_28 = V_25 -> V_28 ;
if ( V_28 ) {
F_11 ( & V_2 -> V_19 , L_3 , V_20 , V_28 ) ;
return;
}
memset ( V_2 -> V_29 -> V_30 , V_31 , 1 ) ;
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 1 ,
V_34 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
int V_27 ;
char * V_37 = V_2 -> V_29 -> V_30 ;
* V_37 ++ = V_38 ;
* V_37 ++ = V_39 ;
* V_37 ++ = V_36 ;
* V_37 = V_40 ;
F_16 ( V_2 -> V_29 ,
V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 4 , F_15 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
V_4 -> V_23 = 0 ;
return V_27 ;
}
static void F_20 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
T_1 * V_41 ;
int V_28 = V_25 -> V_28 ;
if ( V_28 ) {
F_11 ( & V_2 -> V_19 , L_3 , V_20 , V_28 ) ;
return;
}
V_41 = V_25 -> V_30 ;
F_11 ( & V_2 -> V_19 , L_4 , V_20 ) ;
if ( V_25 -> V_42 == 1 ) {
switch ( V_41 [ 0 ] ) {
case 0x1 :
V_4 -> V_22 = V_43 ;
break;
case 0x0 :
V_4 -> V_22 = V_44 ;
break;
default:
V_4 -> V_22 = V_44 ;
}
}
F_15 ( V_25 ) ;
}
static void F_21 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
int V_28 = V_25 -> V_28 ;
F_11 ( & V_2 -> V_19 , L_3 , V_20 , V_28 ) ;
F_16 ( V_2 -> V_45 , V_2 -> V_32 -> V_19 ,
F_22 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_46 ) ,
V_2 -> V_45 -> V_30 , 256 ,
F_20 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_45 , V_35 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_27 ;
memset ( V_2 -> V_29 -> V_30 , V_47 , 1 ) ;
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 1 ,
F_21 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
return V_27 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_8 , T_1 V_48 )
{
int V_28 ;
struct V_49 * V_32 = V_2 -> V_32 ;
int V_50 = 0 ;
V_28 =
F_25 ( V_32 -> V_19 ,
F_17 ( V_32 -> V_19 ,
V_2 -> V_33 ) , V_8 ,
V_48 , & V_50 , 1000 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_5 , V_20 , V_28 ) ;
else
F_11 ( & V_2 -> V_19 , L_6 , V_20 ) ;
return V_28 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_8 , T_1 V_48 )
{
int V_28 ;
struct V_49 * V_32 = V_2 -> V_32 ;
int V_50 = 0 ;
V_28 =
F_25 ( V_32 -> V_19 ,
F_22 ( V_32 -> V_19 ,
V_2 -> V_46 ) , V_8 ,
V_48 , & V_50 , 1000 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_5 , V_20 , V_28 ) ;
else
F_11 ( & V_2 -> V_19 , L_7 , V_20 ) ;
return V_28 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_52 ,
unsigned int V_53 , unsigned int V_54 , T_1 V_55 )
{
int V_28 ;
T_1 * V_8 ;
V_8 = F_28 ( 8 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_56 ;
V_8 [ 1 ] = V_52 & 0xFF ;
V_8 [ 2 ] = ( V_52 >> 8 ) & 0xFF ;
V_8 [ 3 ] = V_53 & 0xFF ;
V_8 [ 4 ] = ( V_53 >> 8 ) & 0xFF ;
V_8 [ 5 ] = V_54 & 0xFF ;
V_8 [ 6 ] = ( V_54 >> 8 ) & 0xFF ;
V_8 [ 7 ] = V_55 ;
V_28 = F_24 ( V_2 , V_8 , 8 ) ;
F_3 ( V_8 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_8 , V_20 , V_28 ) ;
else
F_11 ( & V_2 -> V_19 , L_9 , V_20 ) ;
return V_51 ;
}
static void F_29 ( T_1 * V_8 , T_1 V_57 , T_1 V_58 , T_1 V_59 , T_1 V_60 , T_1 V_61 ,
T_1 V_62 , T_1 V_63 )
{
* V_8 ++ = V_56 ;
* V_8 ++ = V_57 ;
* V_8 ++ = V_58 ;
* V_8 ++ = V_59 ;
* V_8 ++ = V_60 ;
* V_8 ++ = V_61 ;
* V_8 ++ = V_62 ;
* V_8 = V_63 ;
}
static void F_30 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
char * V_37 = V_2 -> V_29 -> V_30 ;
* V_37 ++ = V_56 ;
if ( V_64 ) {
F_31 ( V_37 , 6 ) ;
* ( V_37 + 7 ) = 1 ;
} else {
F_29 ( V_37 , 255 , 255 , 0 , 0 , 0 , 0 , 255 ) ;
}
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 8 ,
F_15 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
}
static void F_32 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
char * V_37 = V_2 -> V_29 -> V_30 ;
if ( V_64 ) {
F_15 ( V_25 ) ;
return;
} else {
* V_37 ++ = V_56 ;
F_29 ( V_37 , 0 , 0 , 255 , 255 , 0 , 0 , 255 ) ;
}
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 8 ,
F_15 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_65 )
{
int V_28 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
int V_66 = 0 ;
T_1 V_67 = 0x69 ;
T_1 DIV = 0 ;
T_1 V_68 = 0 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
unsigned int V_74 = 0 ;
unsigned int V_75 = 0 ;
int V_76 = ( int ) V_65 ;
if ( V_76 == 0 ) {
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x09 ;
V_4 -> V_8 [ V_66 ++ ] = 0x00 ;
V_28 = F_24 ( V_2 , ( T_1 * ) V_4 -> V_8 , V_66 ) ;
if ( V_28 != 0 ) {
F_11 ( & V_2 -> V_19 , L_10 , V_20 ) ;
return V_28 ;
}
} else if ( V_76 == 3579000 ) {
DIV = 100 ;
V_74 = 1193 ;
V_73 = 40 ;
V_68 = 0 ;
} else if ( V_76 == 3680000 ) {
DIV = 105 ;
V_74 = 161 ;
V_73 = 5 ;
V_68 = 0 ;
} else if ( V_76 == 6000000 ) {
DIV = 66 ;
V_74 = 66 ;
V_73 = 2 ;
V_68 = 0x28 ;
} else {
unsigned int V_27 = 0 ;
unsigned int V_78 = 0 ;
unsigned int V_79 ;
unsigned int V_80 ;
char V_81 = 0x00 ;
unsigned int V_82 = 2 ;
unsigned int V_83 = 2055 ;
unsigned int lDiv = 4 ;
for ( V_82 = 2 ; V_82 <= 47 && ! V_81 ; V_82 ++ )
for ( V_83 = 2055 ; V_83 >= 8 && ! V_81 ; V_83 -- )
for ( lDiv = 4 ; lDiv <= 127 && ! V_81 ; lDiv ++ ) {
V_78 = ( 12000000 / lDiv ) * ( V_83 / V_82 ) ;
if ( abs ( ( int ) ( V_78 - V_76 ) ) <
abs ( ( int ) ( V_76 - V_27 ) ) ) {
V_80 = ( 12000000 / V_82 ) ;
if ( V_80 < 250000 )
continue;
V_79 = ( 12000000 / V_82 ) * V_83 ;
if ( V_79 > 400000000 )
continue;
if ( V_79 < 100000000 )
continue;
if ( lDiv < 4 || lDiv > 127 )
continue;
V_27 = V_78 ;
V_74 = V_83 ;
DIV = lDiv ;
V_73 = V_82 ;
if ( V_27 == V_76 )
V_81 = 0x01 ;
}
}
}
V_75 = ( ( V_74 - V_72 ) / 2 ) - 4 ;
DIV = DIV ;
V_69 = 0x04 ;
V_70 = ( V_75 >> 8 & 0x03 ) ;
V_71 = V_75 & 0xFF ;
V_72 = ( V_74 >> 10 ) & 0x01 ;
V_73 = V_73 - 2 ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x09 ;
V_4 -> V_8 [ V_66 ++ ] = 0x20 ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x0C ;
V_4 -> V_8 [ V_66 ++ ] = DIV ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x12 ;
V_4 -> V_8 [ V_66 ++ ] = V_68 ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x13 ;
V_4 -> V_8 [ V_66 ++ ] = 0x6B ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x40 ;
V_4 -> V_8 [ V_66 ++ ] = ( 0xC0 | ( ( V_69 & 0x07 ) << 2 ) ) |
( V_70 & 0x03 ) ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x41 ;
V_4 -> V_8 [ V_66 ++ ] = V_71 ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x42 ;
V_4 -> V_8 [ V_66 ++ ] = V_73 | ( ( ( V_72 & 0x01 ) << 7 ) ) ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x44 ;
V_4 -> V_8 [ V_66 ++ ] = ( char ) 0xFF ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x45 ;
V_4 -> V_8 [ V_66 ++ ] = ( char ) 0xFE ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x46 ;
V_4 -> V_8 [ V_66 ++ ] = 0x7F ;
V_4 -> V_8 [ V_66 ++ ] = V_77 ;
V_4 -> V_8 [ V_66 ++ ] = V_67 << 1 ;
V_4 -> V_8 [ V_66 ++ ] = 0x47 ;
V_4 -> V_8 [ V_66 ++ ] = ( char ) 0x84 ;
V_28 = F_24 ( V_2 , ( T_1 * ) V_4 -> V_8 , V_66 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_10 , V_20 ) ;
return V_28 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_84 * V_19 = & V_2 -> V_19 ;
int V_85 ;
int V_28 ;
T_1 V_86 = V_31 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
if ( F_27 ( V_2 , 0xF000 , 0 , 0 , 0xFF ) < 0 )
return - V_87 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
V_28 = F_24 ( V_2 , & V_86 , 1 ) ;
if ( V_28 != V_51 ) {
F_11 ( V_19 , L_11 , V_20 ) ;
return V_28 ;
}
V_28 = F_26 ( V_2 , & V_4 -> V_88 , 1 ) ;
if ( V_28 != V_51 ) {
F_11 ( V_19 , L_12 , V_20 ) ;
return V_28 ;
}
if ( V_4 -> V_88 > 0 ) {
F_11 ( V_19 , L_13 , V_20 , V_4 -> V_88 ) ;
V_28 = F_26 ( V_2 , V_4 -> V_8 , V_4 -> V_88 ) ;
if ( V_28 != V_51 ) {
F_11 ( V_19 , L_12 , V_20 ) ;
return V_28 ;
}
}
}
F_11 ( V_19 , L_14 , V_20 ) ;
F_27 ( V_2 , 0 , 0xF000 , 0 , 0xFF ) ;
return V_28 ;
}
static void F_35 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
unsigned char * V_89 = V_25 -> V_30 ;
int V_28 = V_25 -> V_28 ;
if ( V_28 ) {
if ( V_28 == - V_90 ) {
}
return;
}
F_11 ( & V_2 -> V_19 , L_15 , V_20 , V_25 -> V_42 ) ;
if ( V_89 == NULL )
F_11 ( & V_2 -> V_19 , L_16 , V_20 ) ;
if ( V_25 -> V_42 && V_89 ) {
F_36 ( & V_2 -> V_2 , V_89 , V_25 -> V_42 ) ;
F_37 ( & V_2 -> V_2 ) ;
}
F_30 ( V_25 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_18 ;
int V_27 ;
int V_91 ;
char * V_37 = V_2 -> V_29 -> V_30 ;
F_12 ( & V_4 -> V_12 , V_18 ) ;
* V_37 ++ = V_92 ;
* V_37 ++ = V_93 ;
* V_37 ++ = V_4 -> V_94 ;
memcpy ( V_37 , V_4 -> V_9 , V_4 -> V_94 ) ;
V_91 = V_4 -> V_94 ;
V_4 -> V_94 = 0 ;
F_13 ( & V_4 -> V_12 , V_18 ) ;
F_11 ( & V_2 -> V_19 , L_17 , V_20 ,
V_91 , V_91 , V_37 ) ;
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , V_91 + 3 ,
F_15 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_35 ) ;
F_39 ( V_2 ) ;
return V_27 ;
}
static int F_40 ( struct V_1 * V_2 , int V_88 )
{
int V_27 ;
F_16 ( V_2 -> V_45 , V_2 -> V_32 -> V_19 ,
F_22 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_46 ) ,
V_2 -> V_45 -> V_30 , V_88 ,
F_35 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_45 , V_35 ) ;
return V_27 ;
}
static void F_41 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_18 ;
int V_28 = V_25 -> V_28 ;
int error = 0 ;
int V_88 = 0 ;
unsigned char * V_89 = V_25 -> V_30 ;
V_4 -> V_95 ++ ;
if ( V_28 ) {
F_11 ( & V_2 -> V_19 , L_3 , V_20 , V_28 ) ;
return;
}
if ( V_89 == NULL )
F_11 ( & V_2 -> V_19 , L_16 , V_20 ) ;
if ( V_25 -> V_42 == 1 && V_89 != NULL )
V_88 = ( int ) V_89 [ 0 ] ;
if ( V_25 -> V_42 > 1 ) {
F_11 ( & V_2 -> V_19 , L_18 , V_20 ,
V_25 -> V_42 ) ;
error = 1 ;
return;
}
if ( V_88 > 0 && error == 0 ) {
F_11 ( & V_2 -> V_19 , L_19 ,
V_20 , V_88 ) ;
V_28 = F_40 ( V_2 , V_88 ) ;
return;
}
if ( V_4 -> V_95 > 99 ) {
V_28 = F_23 ( V_2 ) ;
V_4 -> V_95 = 0 ;
return;
}
if ( V_4 -> V_23 == 1 ) {
V_28 = F_19 ( V_2 , 0xC ) ;
return;
}
F_12 ( & V_4 -> V_12 , V_18 ) ;
if ( V_4 -> V_94 > 0 ) {
F_13 ( & V_4 -> V_12 , V_18 ) ;
V_28 = F_38 ( V_2 ) ;
return;
}
F_13 ( & V_4 -> V_12 , V_18 ) ;
F_11 ( & V_2 -> V_19 , L_20 , V_20 ) ;
F_32 ( V_25 ) ;
}
static int F_42 ( struct V_13 * V_14 , struct V_1 * V_2 ,
const T_1 * V_8 , int V_48 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_18 ;
if ( V_48 > 256 )
return - V_7 ;
F_12 ( & V_4 -> V_12 , V_18 ) ;
memcpy ( V_4 -> V_9 + V_4 -> V_94 , V_8 , V_48 ) ;
V_4 -> V_94 += V_48 ;
F_13 ( & V_4 -> V_12 , V_18 ) ;
return V_48 ;
}
static void V_34 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
int V_28 = V_25 -> V_28 ;
if ( V_28 ) {
return;
}
F_16 ( V_2 -> V_45 , V_2 -> V_32 -> V_19 ,
F_22 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_46 ) ,
V_2 -> V_45 -> V_30 , 256 ,
F_41 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_45 , V_35 ) ;
F_11 ( & V_2 -> V_19 , L_21 , V_20 , V_27 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_28 ;
T_1 * V_8 ;
V_8 = F_28 ( sizeof( T_1 ) * 4 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_96 ;
V_8 [ 1 ] = ( T_1 ) ( ( V_97 >> 8 ) & 0x00FF ) ;
V_8 [ 2 ] = ( T_1 ) ( 0x00FF & V_97 ) ;
V_8 [ 3 ] = ( T_1 ) ( 0x0F0 & V_98 ) | ( 0x07 & V_99 ) ;
V_28 = F_24 ( V_2 , V_8 , 4 ) ;
if ( V_28 != V_51 ) {
F_11 ( & V_2 -> V_19 , L_22 , V_20 ) ;
goto V_100;
}
V_28 = F_34 ( V_2 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_23 , V_20 ) ;
V_100:
F_3 ( V_8 ) ;
return V_28 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_28 ;
T_1 * V_8 ;
V_8 = F_28 ( 1 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_101 ;
V_28 = F_24 ( V_2 , V_8 , 1 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_24 , V_20 ) ;
F_3 ( V_8 ) ;
return V_28 ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_102 ,
T_2 * V_50 , T_1 V_103 )
{
int V_28 ;
T_2 V_104 ;
T_1 * V_105 ;
T_1 V_106 = 0 ;
T_1 V_107 = 0 ;
T_1 V_108 = 0 ;
unsigned int V_109 = 0 ;
F_11 ( & V_2 -> V_19 , L_25 , V_20 , V_102 ) ;
V_105 = F_28 ( sizeof( T_1 ) * 5 , V_6 ) ;
if ( ! V_105 )
return - V_7 ;
V_104 = V_102 ;
if ( V_104 < 1200 || V_104 > 230400 ) {
F_3 ( V_105 ) ;
return V_110 ;
}
if ( V_104 > 977 ) {
V_107 = 3 ;
V_109 = 500000 ;
}
if ( V_104 > 3906 ) {
V_107 = 2 ;
V_109 = 2000000 ;
}
if ( V_104 > 11718 ) {
V_107 = 1 ;
V_109 = 6000000 ;
}
if ( V_104 > 46875 ) {
V_107 = 0 ;
V_109 = 24000000 ;
}
V_108 = 256 - ( T_1 ) ( V_109 / ( V_104 * 2 ) ) ;
V_105 [ V_106 ++ ] = V_92 ;
V_105 [ V_106 ++ ] = V_111 ;
V_105 [ V_106 ++ ] = V_107 ;
V_105 [ V_106 ++ ] = V_108 ;
* V_50 = ( V_109 / ( 256 - V_108 ) ) / 2 ;
switch ( V_103 & 0x0F ) {
case V_112 :
V_105 [ V_106 ++ ] = 0x00 ;
break;
case V_99 :
V_105 [ V_106 ++ ] = 0x01 ;
break;
case V_113 :
V_105 [ V_106 ++ ] = 0x02 ;
break;
case V_114 :
V_105 [ V_106 ++ ] = 0x03 ;
break;
case V_115 :
V_105 [ V_106 ++ ] = 0x04 ;
break;
default:
F_3 ( V_105 ) ;
return V_110 ;
break;
}
switch ( V_103 & 0xF0 ) {
case V_98 :
V_105 [ V_106 - 1 ] |= V_98 ;
break;
case V_116 :
V_105 [ V_106 - 1 ] |= V_116 ;
break;
default:
F_3 ( V_105 ) ;
return V_110 ;
break;
}
V_28 = F_24 ( V_2 , V_105 , V_106 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_24 , V_20 ) ;
F_3 ( V_105 ) ;
return V_28 ;
}
static void F_46 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_117 * V_118 )
{
const T_2 V_119 = V_120 | V_121 | V_122 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned int V_123 = V_14 -> V_124 . V_125 ;
int V_28 ;
T_2 V_50 ;
T_2 V_103 ;
int V_126 = V_127 ;
int V_104 ;
T_2 V_128 = V_123 & V_119 ;
V_104 = V_14 -> V_124 . V_129 ;
F_11 ( & V_2 -> V_19 , L_26 , V_20 , V_104 ) ;
V_103 = 0 ;
if ( V_123 & V_120 ) {
if ( V_123 & V_122 )
V_103 |= V_115 ;
else
V_103 |= V_114 ;
} else if ( ! ( V_123 & V_121 ) ) {
V_103 |= V_112 ;
V_126 = V_130 ;
} else if ( V_123 & V_122 )
V_103 |= V_113 ;
else
V_103 |= V_99 ;
V_103 |= ( V_123 & V_131 ? V_116 : V_98 ) ;
V_28 = F_45 ( V_2 ,
V_104 * V_4 -> V_132 / 100 ,
& V_50 , V_103 ) ;
if ( V_118 )
F_47 ( & V_14 -> V_124 , V_118 ) ;
if ( V_28 != 0 )
return;
F_48 ( V_14 , V_104 , V_104 ) ;
V_14 -> V_124 . V_125 &= ~ ( V_119 | V_133 ) ;
V_14 -> V_124 . V_125 |= V_128 | V_126 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_50 ( V_2 -> V_29 ) ;
F_50 ( V_2 -> V_45 ) ;
F_27 ( V_2 , 0 , 0 , 0xF000 , 0xFF ) ;
}
static void F_51 ( struct V_13 * V_14 )
{
V_14 -> V_124 = V_134 ;
V_14 -> V_124 . V_125 = V_135 | V_136 | V_130 | V_137
| V_138 | V_131 | V_121 ;
V_14 -> V_124 . V_139 = 9600 ;
V_14 -> V_124 . V_129 = 9600 ;
V_14 -> V_124 . V_140 = 0 ;
V_14 -> V_124 . V_141 = 0 ;
V_14 -> V_124 . V_142 = 0 ;
}
static int F_52 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_49 * V_32 = V_2 -> V_32 ;
struct V_84 * V_19 = & V_2 -> V_19 ;
T_1 * V_8 ;
int V_27 ;
int V_104 ;
T_2 V_50 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
V_104 = V_14 -> V_124 . V_129 ;
V_14 -> V_124 . V_139 = V_104 ;
F_48 ( V_14 , V_104 , V_104 ) ;
F_11 ( V_19 , L_27 , V_20 , V_104 ) ;
F_53 ( V_32 -> V_19 , V_2 -> V_29 -> V_143 ) ;
F_53 ( V_32 -> V_19 , V_2 -> V_45 -> V_143 ) ;
V_8 = F_28 ( 10 , V_6 ) ;
if ( V_8 == NULL )
return - V_7 ;
V_4 -> V_95 = 0 ;
#define F_54 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_rcvctrlpipe(port->serial->dev, 0), \
b, a, c, d, buf, 1, 1000); \
dev_dbg(dev, "0x%x:0x%x:0x%x:0x%x %d - %x\n", a, b, c, d, result, \
buf[0]); } while (0);
#define F_55 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_sndctrlpipe(port->serial->dev, 0), \
b, a, c, d, NULL, 0, 1000); \
dev_dbg(dev, "0x%x:0x%x:0x%x:0x%x %d\n", a, b, c, d, result); } while (0)
F_55 ( 0x03 , 0x02 , 0x02 , 0x0 ) ;
F_3 ( V_8 ) ;
F_27 ( V_2 , 0xF000 , 0xF000 , 0 , 0xFF ) ;
F_43 ( V_2 ) ;
if ( V_132 < 100 )
V_132 = 100 ;
V_4 -> V_132 = V_132 ;
V_4 -> V_104 = V_104 ;
switch ( V_144 ) {
case 2 :
V_4 -> V_145 = V_146 ;
F_33 ( V_2 , V_146 * V_132 / 100 ) ;
V_27 =
F_45 ( V_2 , V_104 * V_132 / 100 , & V_50 ,
V_99 ) ;
break;
case 3 :
F_33 ( V_2 , V_147 * V_132 / 100 ) ;
V_4 -> V_145 = V_147 ;
V_27 =
F_45 ( V_2 , 16457 * V_132 / 100 , & V_50 ,
V_99 ) ;
break;
default:
F_33 ( V_2 , V_148 * V_132 / 100 ) ;
V_4 -> V_145 = V_148 ;
V_27 =
F_45 ( V_2 , V_104 * V_132 / 100 , & V_50 ,
V_99 ) ;
}
switch ( V_149 ) {
case 0 :
V_44 = 0 ;
V_43 = 0 ;
break;
case 1 :
V_44 = V_150 ;
V_43 = 0 ;
break;
case 2 :
V_44 = 0 ;
V_43 = V_150 ;
break;
case 3 :
V_44 = V_151 ;
V_43 = 0 ;
break;
case 4 :
V_44 = 0 ;
V_43 = V_151 ;
break;
case 5 :
V_44 = V_138 ;
V_43 = 0 ;
break;
case 6 :
V_44 = 0 ;
V_43 = V_138 ;
break;
case 7 :
V_44 = V_152 ;
V_43 = 0 ;
break;
case 8 :
V_44 = 0 ;
V_43 = V_152 ;
}
F_34 ( V_2 ) ;
F_11 ( V_19 , L_28 , V_20 ) ;
memset ( V_2 -> V_29 -> V_30 , V_31 , 1 ) ;
F_16 ( V_2 -> V_29 , V_2 -> V_32 -> V_19 ,
F_17 ( V_2 -> V_32 -> V_19 ,
V_2 -> V_33 ) ,
V_2 -> V_29 -> V_30 , 1 ,
V_34 , V_2 ) ;
V_27 = F_18 ( V_2 -> V_29 , V_6 ) ;
if ( V_27 ) {
F_56 ( V_19 , L_29 , V_20 , V_27 ) ;
F_49 ( V_2 ) ;
} else {
F_11 ( V_19 , L_30 , V_20 ) ;
}
return V_27 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_28 ;
T_1 * V_8 ;
V_8 = F_28 ( 5 , V_6 ) ;
if ( ! V_8 )
return - V_7 ;
V_8 [ 0 ] = V_153 ;
V_8 [ 1 ] = V_10 & 0xFF ;
V_8 [ 2 ] = ( V_10 >> 8 ) & 0xFF ;
V_8 [ 3 ] = ( V_10 >> 16 ) & 0xFF ;
V_8 [ 4 ] = ( V_10 >> 24 ) & 0xFF ;
V_28 = F_24 ( V_2 , V_8 , 5 ) ;
F_3 ( V_8 ) ;
if ( V_28 != V_51 )
F_11 ( & V_2 -> V_19 , L_31 , V_20 , V_28 ) ;
else
F_11 ( & V_2 -> V_19 , L_32 , V_20 ) ;
return V_28 ;
}
static T_7 F_58 ( struct V_84 * V_19 ,
struct V_154 * V_155 , char * V_8 )
{
struct V_1 * V_2 = F_59 ( V_19 ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
return sprintf ( V_8 , L_33 , V_4 -> V_10 ) ;
}
static T_7 F_60 ( struct V_84 * V_19 ,
struct V_154 * V_155 , const char * V_8 , T_8 V_48 )
{
struct V_1 * V_2 = F_59 ( V_19 ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_156 ;
if ( F_61 ( V_8 , 10 , & V_156 ) ) {
F_56 ( V_19 , L_34 ,
V_20 , V_8 ) ;
goto V_157;
}
F_11 ( V_19 , L_35 , V_20 , V_156 ) ;
if ( ( V_156 != 3 ) && ( V_156 != 5 ) ) {
F_56 ( V_19 , L_36 , V_20 , V_156 ) ;
} else {
F_57 ( V_2 , V_156 ) ;
V_4 -> V_10 = V_156 ;
}
V_157:
return V_48 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_62 ( & V_2 -> V_19 , & V_158 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_19 , & V_158 ) ;
return 0 ;
}
