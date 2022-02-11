static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_4 ( 256 , V_6 ) ;
V_2 -> V_4 = F_4 ( 256 , V_6 ) ;
V_2 -> V_5 = F_4 ( 256 , V_6 ) ;
if ( ! V_2 -> V_3 || ! V_2 -> V_4 || ! V_2 -> V_5 ) {
F_1 ( V_2 ) ;
F_5 ( L_1 , V_7 ) ;
return - V_8 ;
}
F_5 ( L_2 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_6 ) ;
F_5 ( L_3 , V_7 ) ;
if ( ! V_2 )
return - V_8 ;
if ( F_3 ( V_2 ) ) {
F_2 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_11 = V_12 ;
F_7 ( & V_2 -> V_13 ) ;
F_8 ( & V_2 -> V_14 ) ;
F_9 ( V_10 -> V_15 [ 0 ] , V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_16 * V_15 = V_10 -> V_15 [ 0 ] ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
if ( ! V_15 )
return;
F_5 ( L_4 , V_7 ) ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_5 ( L_5 , V_7 ) ;
F_9 ( V_15 , NULL ) ;
F_5 ( L_6 , V_7 ) ;
F_2 ( V_2 ) ;
F_5 ( L_7 , V_7 ) ;
}
}
static int F_12 ( struct V_17 * V_18 ,
unsigned int V_19 , unsigned int V_20 )
{
struct V_16 * V_15 = V_18 -> V_21 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_22 ;
F_5 ( L_8 , V_7 ,
V_15 -> V_23 , V_19 , V_20 ) ;
F_13 ( & V_2 -> V_13 , V_22 ) ;
if ( ( V_19 & V_24 ) && ! ( V_2 -> V_25 == V_24 ) ) {
F_5 ( L_9 , V_7 ) ;
V_2 -> V_26 = 1 ;
}
if ( V_19 & V_24 )
V_2 -> V_25 = V_24 ;
F_14 ( & V_2 -> V_13 , V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_16 * V_15 = V_18 -> V_21 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_22 ;
int V_27 ;
F_13 ( & V_2 -> V_13 , V_22 ) ;
V_27 = V_2 -> V_25 ;
F_14 ( & V_2 -> V_13 , V_22 ) ;
return V_27 ;
}
static void F_16 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
int V_30 ;
int V_31 = V_28 -> V_31 ;
F_5 ( L_10 , V_7 ) ;
if ( V_31 ) {
F_5 ( L_11 , V_7 , V_31 ) ;
return;
}
memset ( V_15 -> V_32 -> V_33 , V_34 , 1 ) ;
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 1 ,
V_37 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
}
static int F_20 ( struct V_16 * V_15 , T_1 V_39 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_30 ;
char * V_40 = V_15 -> V_32 -> V_33 ;
F_5 ( L_10 , V_7 ) ;
* V_40 ++ = V_41 ;
* V_40 ++ = V_42 ;
* V_40 ++ = V_39 ;
* V_40 = V_43 ;
F_17 ( V_15 -> V_32 ,
V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 4 , F_16 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
V_2 -> V_26 = 0 ;
return V_30 ;
}
static void F_21 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
T_1 * V_44 ;
int V_31 = V_28 -> V_31 ;
F_5 ( L_10 , V_7 ) ;
if ( V_31 ) {
F_5 ( L_11 , V_7 , V_31 ) ;
return;
}
V_44 = V_28 -> V_33 ;
F_5 ( L_10 , V_7 ) ;
if ( V_28 -> V_45 == 1 ) {
switch ( V_44 [ 0 ] ) {
case 0x1 :
V_2 -> V_25 = V_46 ;
break;
case 0x0 :
V_2 -> V_25 = V_47 ;
break;
default:
V_2 -> V_25 = V_47 ;
}
}
F_16 ( V_28 ) ;
}
static void F_22 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
int V_30 ;
int V_31 = V_28 -> V_31 ;
F_5 ( L_11 , V_7 , V_31 ) ;
F_17 ( V_15 -> V_48 , V_15 -> V_10 -> V_35 ,
F_23 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_49 ) ,
V_15 -> V_48 -> V_33 , 256 ,
F_21 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_48 , V_38 ) ;
}
static int F_24 ( struct V_16 * V_15 )
{
int V_30 ;
F_5 ( L_10 , V_7 ) ;
memset ( V_15 -> V_32 -> V_33 , V_50 , 1 ) ;
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 1 ,
F_22 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
return V_30 ;
}
static int F_25 ( struct V_16 * V_15 , T_1 * V_3 , T_1 V_51 )
{
int V_31 ;
struct V_9 * V_10 = V_15 -> V_10 ;
int V_52 = 0 ;
F_5 ( L_10 , V_7 ) ;
V_31 =
F_26 ( V_10 -> V_35 ,
F_18 ( V_10 -> V_35 ,
V_15 -> V_36 ) , V_3 ,
V_51 , & V_52 , V_53 * 1 ) ;
if ( V_31 != V_54 )
F_5 ( L_12 , V_7 , V_31 ) ;
else
F_5 ( L_13 , V_7 ) ;
return V_31 ;
}
static int F_27 ( struct V_16 * V_15 , T_1 * V_3 , T_1 V_51 )
{
int V_31 ;
struct V_9 * V_10 = V_15 -> V_10 ;
int V_52 = 0 ;
F_5 ( L_10 , V_7 ) ;
V_31 =
F_26 ( V_10 -> V_35 ,
F_23 ( V_10 -> V_35 ,
V_15 -> V_49 ) , V_3 ,
V_51 , & V_52 , V_53 * 1 ) ;
if ( V_31 != V_54 )
F_5 ( L_12 , V_7 , V_31 ) ;
else
F_5 ( L_14 , V_7 ) ;
return V_31 ;
}
static int F_28 ( struct V_16 * V_15 , unsigned int V_55 ,
unsigned int V_56 , unsigned int V_57 , T_1 V_58 )
{
int V_31 ;
T_1 * V_3 ;
V_3 = F_29 ( 8 , V_6 ) ;
if ( ! V_3 )
return - V_8 ;
F_5 ( L_10 , V_7 ) ;
V_3 [ 0 ] = V_59 ;
V_3 [ 1 ] = V_55 & 0xFF ;
V_3 [ 2 ] = ( V_55 >> 8 ) & 0xFF ;
V_3 [ 3 ] = V_56 & 0xFF ;
V_3 [ 4 ] = ( V_56 >> 8 ) & 0xFF ;
V_3 [ 5 ] = V_57 & 0xFF ;
V_3 [ 6 ] = ( V_57 >> 8 ) & 0xFF ;
V_3 [ 7 ] = V_58 ;
V_31 = F_25 ( V_15 , V_3 , 8 ) ;
F_2 ( V_3 ) ;
if ( V_31 != V_54 )
F_5 ( L_15 , V_7 , V_31 ) ;
else
F_5 ( L_16 , V_7 ) ;
return V_54 ;
}
static void F_30 ( T_1 * V_3 , T_1 V_60 , T_1 V_61 , T_1 V_62 , T_1 V_63 , T_1 V_64 ,
T_1 V_65 , T_1 V_66 )
{
* V_3 ++ = V_59 ;
* V_3 ++ = V_60 ;
* V_3 ++ = V_61 ;
* V_3 ++ = V_62 ;
* V_3 ++ = V_63 ;
* V_3 ++ = V_64 ;
* V_3 ++ = V_65 ;
* V_3 = V_66 ;
}
static void F_31 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
int V_30 ;
char * V_40 = V_15 -> V_32 -> V_33 ;
* V_40 ++ = V_59 ;
if ( V_67 == 1 ) {
F_32 ( V_40 , 6 ) ;
* ( V_40 + 7 ) = 1 ;
} else {
F_30 ( V_40 , 255 , 255 , 0 , 0 , 0 , 0 , 255 ) ;
}
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 8 ,
F_16 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
}
static void F_33 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
int V_30 ;
char * V_40 = V_15 -> V_32 -> V_33 ;
if ( V_67 == 1 ) {
F_16 ( V_28 ) ;
return;
} else {
* V_40 ++ = V_59 ;
F_30 ( V_40 , 0 , 0 , 255 , 255 , 0 , 0 , 255 ) ;
}
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 8 ,
F_16 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
}
static int F_34 ( struct V_16 * V_15 , int V_68 )
{
int V_31 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_69 = 0 ;
T_1 V_70 = 0x69 ;
T_1 DIV = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
T_1 V_76 = 0 ;
unsigned int V_77 = 0 ;
unsigned int V_78 = 0 ;
int V_79 = ( int ) V_68 ;
F_5 ( L_10 , V_7 ) ;
if ( V_79 == 0 ) {
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x09 ;
V_2 -> V_3 [ V_69 ++ ] = 0x00 ;
V_31 = F_25 ( V_15 , ( T_1 * ) V_2 -> V_3 , V_69 ) ;
if ( V_31 != 0 ) {
F_5 ( L_17 , V_7 ) ;
return V_31 ;
}
} else if ( V_79 == 3579000 ) {
DIV = 100 ;
V_77 = 1193 ;
V_76 = 40 ;
V_71 = 0 ;
} else if ( V_79 == 3680000 ) {
DIV = 105 ;
V_77 = 161 ;
V_76 = 5 ;
V_71 = 0 ;
} else if ( V_79 == 6000000 ) {
DIV = 66 ;
V_77 = 66 ;
V_76 = 2 ;
V_71 = 0x28 ;
} else {
unsigned int V_30 = 0 ;
unsigned int V_81 = 0 ;
unsigned int V_82 ;
unsigned int V_83 ;
char V_84 = 0x00 ;
unsigned int V_85 = 2 ;
unsigned int V_86 = 2055 ;
unsigned int lDiv = 4 ;
for ( V_85 = 2 ; V_85 <= 47 && ! V_84 ; V_85 ++ )
for ( V_86 = 2055 ; V_86 >= 8 && ! V_84 ; V_86 -- )
for ( lDiv = 4 ; lDiv <= 127 && ! V_84 ; lDiv ++ ) {
V_81 = ( 12000000 / lDiv ) * ( V_86 / V_85 ) ;
if ( abs ( ( int ) ( V_81 - V_79 ) ) <
abs ( ( int ) ( V_79 - V_30 ) ) ) {
V_83 = ( 12000000 / V_85 ) ;
if ( V_83 < 250000 )
continue;
V_82 = ( 12000000 / V_85 ) * V_86 ;
if ( V_82 > 400000000 )
continue;
if ( V_82 < 100000000 )
continue;
if ( lDiv < 4 || lDiv > 127 )
continue;
V_30 = V_81 ;
V_77 = V_86 ;
DIV = lDiv ;
V_76 = V_85 ;
if ( V_30 == V_79 )
V_84 = 0x01 ;
}
}
}
V_78 = ( ( V_77 - V_75 ) / 2 ) - 4 ;
DIV = DIV ;
V_72 = 0x04 ;
V_73 = ( V_78 >> 8 & 0x03 ) ;
V_74 = V_78 & 0xFF ;
V_75 = ( V_77 >> 10 ) & 0x01 ;
V_76 = V_76 - 2 ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x09 ;
V_2 -> V_3 [ V_69 ++ ] = 0x20 ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x0C ;
V_2 -> V_3 [ V_69 ++ ] = DIV ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x12 ;
V_2 -> V_3 [ V_69 ++ ] = V_71 ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x13 ;
V_2 -> V_3 [ V_69 ++ ] = 0x6B ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x40 ;
V_2 -> V_3 [ V_69 ++ ] = ( 0xC0 | ( ( V_72 & 0x07 ) << 2 ) ) |
( V_73 & 0x03 ) ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x41 ;
V_2 -> V_3 [ V_69 ++ ] = V_74 ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x42 ;
V_2 -> V_3 [ V_69 ++ ] = V_76 | ( ( ( V_75 & 0x01 ) << 7 ) ) ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x44 ;
V_2 -> V_3 [ V_69 ++ ] = ( char ) 0xFF ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x45 ;
V_2 -> V_3 [ V_69 ++ ] = ( char ) 0xFE ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x46 ;
V_2 -> V_3 [ V_69 ++ ] = 0x7F ;
V_2 -> V_3 [ V_69 ++ ] = V_80 ;
V_2 -> V_3 [ V_69 ++ ] = V_70 << 1 ;
V_2 -> V_3 [ V_69 ++ ] = 0x47 ;
V_2 -> V_3 [ V_69 ++ ] = ( char ) 0x84 ;
V_31 = F_25 ( V_15 , ( T_1 * ) V_2 -> V_3 , V_69 ) ;
if ( V_31 != V_54 )
F_5 ( L_17 , V_7 ) ;
return V_31 ;
}
static int F_35 ( struct V_16 * V_15 )
{
int V_87 ;
int V_31 ;
T_1 V_88 = V_34 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_5 ( L_10 , V_7 ) ;
if ( F_28 ( V_15 , 0xF000 , 0 , 0 , 0xFF ) < 0 )
return - V_89 ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
V_31 = F_25 ( V_15 , & V_88 , 1 ) ;
if ( V_31 != V_54 ) {
F_5 ( L_18 , V_7 ) ;
return V_31 ;
}
V_31 = F_27 ( V_15 , & V_2 -> V_90 , 1 ) ;
if ( V_31 != V_54 ) {
F_5 ( L_19 , V_7 ) ;
return V_31 ;
}
if ( V_2 -> V_90 > 0 ) {
F_5 ( L_20 , V_7 ,
V_2 -> V_90 ) ;
V_31 = F_27 ( V_15 , V_2 -> V_3 , V_2 -> V_90 ) ;
if ( V_31 != V_54 ) {
F_5 ( L_19 , V_7 ) ;
return V_31 ;
}
}
}
F_5 ( L_21 , V_7 ) ;
F_28 ( V_15 , 0 , 0xF000 , 0 , 0xFF ) ;
return V_31 ;
}
static void F_36 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
unsigned char * V_91 = V_28 -> V_33 ;
struct V_17 * V_18 ;
int V_31 = V_28 -> V_31 ;
F_5 ( L_11 , V_7 , V_31 ) ;
if ( V_31 ) {
if ( V_31 == - V_92 ) {
}
return;
}
F_5 ( L_22 , V_7 , V_28 -> V_45 ) ;
V_18 = F_37 ( & V_15 -> V_15 ) ;
if ( V_91 == NULL )
F_5 ( L_23 , V_7 ) ;
if ( V_18 && V_28 -> V_45 && V_91 ) {
F_38 ( V_18 , V_91 , V_28 -> V_45 ) ;
F_39 ( V_18 ) ;
}
F_40 ( V_18 ) ;
F_31 ( V_28 ) ;
}
static int F_41 ( struct V_16 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_22 ;
int V_30 ;
int V_87 ;
int V_93 ;
char * V_40 = V_15 -> V_32 -> V_33 ;
F_5 ( L_10 , V_7 ) ;
F_13 ( & V_2 -> V_13 , V_22 ) ;
* V_40 ++ = V_94 ;
* V_40 ++ = V_95 ;
* V_40 ++ = V_2 -> V_96 ;
memcpy ( V_40 , V_2 -> V_5 , V_2 -> V_96 ) ;
V_93 = V_2 -> V_96 ;
V_2 -> V_96 = 0 ;
F_14 ( & V_2 -> V_13 , V_22 ) ;
if ( V_97 == 1 ) {
for ( V_87 = 0 ; V_87 < V_93 ; V_87 ++ )
sprintf ( V_2 -> V_4 + V_87 * 2 ,
L_24 , V_2 -> V_5 [ V_87 ] ) ;
V_2 -> V_4 [ V_93 + V_87 * 2 ] = 0 ;
F_5 ( L_25 , V_7 ,
V_93 , V_2 -> V_4 ) ;
}
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , V_93 + 3 ,
F_16 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_38 ) ;
F_42 ( V_15 ) ;
return V_30 ;
}
static int F_43 ( struct V_16 * V_15 , int V_90 )
{
int V_30 ;
F_5 ( L_10 , V_7 ) ;
F_17 ( V_15 -> V_48 , V_15 -> V_10 -> V_35 ,
F_23 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_49 ) ,
V_15 -> V_48 -> V_33 , V_90 ,
F_36 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_48 , V_38 ) ;
return V_30 ;
}
static void F_44 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_22 ;
int V_31 = V_28 -> V_31 ;
int error = 0 ;
int V_90 = 0 ;
unsigned char * V_91 = V_28 -> V_33 ;
V_2 -> V_98 ++ ;
F_5 ( L_10 , V_7 ) ;
if ( V_31 ) {
F_5 ( L_11 , V_7 , V_31 ) ;
return;
}
if ( V_91 == NULL )
F_5 ( L_23 , V_7 ) ;
if ( V_28 -> V_45 == 1 && V_91 != NULL )
V_90 = ( int ) V_91 [ 0 ] ;
if ( V_28 -> V_45 > 1 ) {
F_5 ( L_26 , V_7 ,
V_28 -> V_45 ) ;
error = 1 ;
return;
}
if ( V_90 > 0 && error == 0 ) {
F_5 ( L_27 ,
V_7 , V_90 ) ;
V_31 = F_43 ( V_15 , V_90 ) ;
return;
}
if ( V_2 -> V_98 > 99 ) {
V_31 = F_24 ( V_15 ) ;
V_2 -> V_98 = 0 ;
return;
}
if ( V_2 -> V_26 == 1 ) {
V_31 = F_20 ( V_15 , 0xC ) ;
return;
}
F_13 ( & V_2 -> V_13 , V_22 ) ;
if ( V_2 -> V_96 > 0 ) {
F_14 ( & V_2 -> V_13 , V_22 ) ;
V_31 = F_41 ( V_15 ) ;
return;
}
F_14 ( & V_2 -> V_13 , V_22 ) ;
F_5 ( L_28 , V_7 ) ;
F_33 ( V_28 ) ;
}
static int F_45 ( struct V_17 * V_18 , struct V_16 * V_15 ,
const T_1 * V_3 , int V_51 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_22 ;
F_5 ( L_10 , V_7 ) ;
if ( V_51 > 256 )
return - V_8 ;
F_13 ( & V_2 -> V_13 , V_22 ) ;
memcpy ( V_2 -> V_5 + V_2 -> V_96 , V_3 , V_51 ) ;
V_2 -> V_96 += V_51 ;
F_14 ( & V_2 -> V_13 , V_22 ) ;
return V_51 ;
}
static void V_37 ( struct V_28 * V_28 )
{
struct V_16 * V_15 = V_28 -> V_29 ;
int V_30 ;
int V_31 = V_28 -> V_31 ;
F_5 ( L_11 , V_7 , V_31 ) ;
if ( V_31 ) {
return;
}
F_17 ( V_15 -> V_48 , V_15 -> V_10 -> V_35 ,
F_23 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_49 ) ,
V_15 -> V_48 -> V_33 , 256 ,
F_44 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_48 , V_38 ) ;
F_5 ( L_29 , V_7 , V_30 ) ;
}
static int F_46 ( struct V_16 * V_15 )
{
int V_31 ;
T_1 * V_3 ;
V_3 = F_29 ( sizeof( T_1 ) * 4 , V_6 ) ;
if ( ! V_3 )
return - V_8 ;
V_3 [ 0 ] = V_99 ;
V_3 [ 1 ] = ( T_1 ) ( ( V_100 >> 8 ) & 0x00FF ) ;
V_3 [ 2 ] = ( T_1 ) ( 0x00FF & V_100 ) ;
V_3 [ 3 ] = ( T_1 ) ( 0x0F0 & V_101 ) | ( 0x07 & V_102 ) ;
V_31 = F_25 ( V_15 , V_3 , 4 ) ;
if ( V_31 != V_54 ) {
F_5 ( L_30 , V_7 ) ;
goto V_103;
}
V_31 = F_35 ( V_15 ) ;
if ( V_31 != V_54 )
F_5 ( L_31 , V_7 ) ;
V_103:
F_2 ( V_3 ) ;
return V_31 ;
}
static int F_47 ( struct V_16 * V_15 )
{
int V_31 ;
T_1 * V_3 ;
V_3 = F_29 ( 1 , V_6 ) ;
if ( ! V_3 )
return - V_8 ;
V_3 [ 0 ] = V_104 ;
V_31 = F_25 ( V_15 , V_3 , 1 ) ;
if ( V_31 != V_54 )
F_5 ( L_32 , V_7 ) ;
F_2 ( V_3 ) ;
return V_31 ;
}
static int F_48 ( struct V_16 * V_15 , T_2 V_105 ,
T_2 * V_52 , T_1 V_106 )
{
int V_31 ;
T_2 V_107 ;
T_1 * V_108 ;
T_1 V_109 = 0 ;
T_1 V_110 = 0 ;
T_1 V_111 = 0 ;
unsigned int V_112 = 0 ;
F_5 ( L_33 , V_7 , V_105 ) ;
V_108 = F_29 ( sizeof( T_1 ) * 5 , V_6 ) ;
if ( ! V_108 )
return - V_8 ;
V_107 = V_105 ;
if ( V_107 < 1200 || V_107 > 230400 ) {
F_2 ( V_108 ) ;
return V_113 ;
}
if ( V_107 > 977 ) {
V_110 = 3 ;
V_112 = 500000 ;
}
if ( V_107 > 3906 ) {
V_110 = 2 ;
V_112 = 2000000 ;
}
if ( V_107 > 11718 ) {
V_110 = 1 ;
V_112 = 6000000 ;
}
if ( V_107 > 46875 ) {
V_110 = 0 ;
V_112 = 24000000 ;
}
V_111 = 256 - ( T_1 ) ( V_112 / ( V_107 * 2 ) ) ;
V_108 [ V_109 ++ ] = V_94 ;
V_108 [ V_109 ++ ] = V_114 ;
V_108 [ V_109 ++ ] = V_110 ;
V_108 [ V_109 ++ ] = V_111 ;
* V_52 = ( V_112 / ( 256 - V_111 ) ) / 2 ;
switch ( V_106 & 0x0F ) {
case V_115 :
V_108 [ V_109 ++ ] = 0x00 ;
break;
case V_102 :
V_108 [ V_109 ++ ] = 0x01 ;
break;
case V_116 :
V_108 [ V_109 ++ ] = 0x02 ;
break;
case V_117 :
V_108 [ V_109 ++ ] = 0x03 ;
break;
case V_118 :
V_108 [ V_109 ++ ] = 0x04 ;
break;
default:
F_2 ( V_108 ) ;
return V_113 ;
break;
}
switch ( V_106 & 0xF0 ) {
case V_101 :
V_108 [ V_109 - 1 ] |= V_101 ;
break;
case V_119 :
V_108 [ V_109 - 1 ] |= V_119 ;
break;
default:
F_2 ( V_108 ) ;
return V_113 ;
break;
}
V_31 = F_25 ( V_15 , V_108 , V_109 ) ;
if ( V_31 != V_54 )
F_5 ( L_32 , V_7 ) ;
F_2 ( V_108 ) ;
return V_31 ;
}
static void F_49 ( struct V_17 * V_18 ,
struct V_16 * V_15 , struct V_120 * V_121 )
{
const T_2 V_122 = V_123 | V_124 | V_125 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned int V_126 = V_18 -> V_127 -> V_128 ;
int V_31 ;
T_2 V_52 ;
T_2 V_106 ;
int V_129 = V_130 ;
int V_107 ;
T_2 V_131 = V_126 & V_122 ;
V_107 = V_18 -> V_127 -> V_132 ;
F_5 ( L_34 , V_7 , V_107 ) ;
V_106 = 0 ;
if ( V_126 & V_123 ) {
if ( V_126 & V_125 )
V_106 |= V_118 ;
else
V_106 |= V_117 ;
} else if ( ! ( V_126 & V_124 ) ) {
V_106 |= V_115 ;
V_129 = V_133 ;
} else if ( V_126 & V_125 )
V_106 |= V_116 ;
else
V_106 |= V_102 ;
V_106 |= ( V_126 & V_134 ? V_119 : V_101 ) ;
V_31 = F_48 ( V_15 ,
V_107 * V_2 -> V_135 / 100 ,
& V_52 , V_106 ) ;
if ( V_121 )
F_50 ( V_18 -> V_127 , V_121 ) ;
if ( V_31 != 0 )
return;
F_51 ( V_18 , V_107 , V_107 ) ;
V_18 -> V_127 -> V_128 &= ~ ( V_122 | V_136 ) ;
V_18 -> V_127 -> V_128 |= V_131 | V_129 ;
}
static void F_52 ( struct V_16 * V_15 )
{
struct V_9 * V_10 ;
V_10 = V_15 -> V_10 ;
if ( ! V_10 )
return;
F_5 ( L_35 , V_7 , V_15 -> V_23 ) ;
F_47 ( V_15 ) ;
if ( V_10 -> V_35 ) {
F_5 ( L_36 , V_7 ) ;
F_53 ( V_15 -> V_32 ) ;
F_53 ( V_15 -> V_48 ) ;
F_53 ( V_15 -> V_137 ) ;
F_28 ( V_15 , 0 , 0 , 0xF000 , 0xFF ) ;
}
}
static void F_54 ( struct V_17 * V_18 )
{
F_5 ( L_10 , V_7 ) ;
* ( V_18 -> V_127 ) = V_138 ;
V_18 -> V_127 -> V_128 = V_139 | V_140 | V_133 | V_141
| V_142 | V_134 | V_124 ;
V_18 -> V_127 -> V_143 = 9600 ;
V_18 -> V_127 -> V_132 = 9600 ;
V_18 -> V_127 -> V_144 = 0 ;
V_18 -> V_127 -> V_145 = 0 ;
V_18 -> V_127 -> V_146 = 0 ;
}
static int F_55 ( struct V_17 * V_18 , struct V_16 * V_15 )
{
struct V_9 * V_10 = V_15 -> V_10 ;
T_1 * V_3 ;
int V_30 ;
int V_107 ;
T_2 V_52 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
V_107 = V_18 -> V_127 -> V_132 ;
V_18 -> V_127 -> V_143 = V_107 ;
F_51 ( V_18 , V_107 , V_107 ) ;
F_5 ( L_37 , V_7 , V_15 -> V_23 , V_107 ) ;
F_56 ( V_10 -> V_35 , V_15 -> V_32 -> V_147 ) ;
F_56 ( V_10 -> V_35 , V_15 -> V_48 -> V_147 ) ;
V_3 = F_29 ( 10 , V_6 ) ;
if ( V_3 == NULL )
return - V_8 ;
V_2 -> V_98 = 0 ;
#define F_57 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_rcvctrlpipe(port->serial->dev, 0), \
b, a, c, d, buf, 1, 1000); \
dbg("0x%x:0x%x:0x%x:0x%x %d - %x", a, b, c, d, result, \
buf[0]); } while (0);
#define F_58 ( T_3 , T_4 , T_5 , T_6 ) do { \
result = usb_control_msg(port->serial->dev, \
usb_sndctrlpipe(port->serial->dev, 0), \
b, a, c, d, NULL, 0, 1000); \
dbg("0x%x:0x%x:0x%x:0x%x %d", a, b, c, d, result); } while (0)
F_58 ( 0x03 , 0x02 , 0x02 , 0x0 ) ;
F_2 ( V_3 ) ;
F_28 ( V_15 , 0xF000 , 0xF000 , 0 , 0xFF ) ;
F_46 ( V_15 ) ;
if ( V_135 < 100 )
V_135 = 100 ;
V_2 -> V_135 = V_135 ;
V_2 -> V_107 = V_107 ;
switch ( V_148 ) {
case 2 :
V_2 -> V_149 = V_150 ;
F_34 ( V_15 , V_150 * V_135 / 100 ) ;
V_30 =
F_48 ( V_15 , V_107 * V_135 / 100 , & V_52 ,
V_102 ) ;
break;
case 3 :
F_34 ( V_15 , V_151 * V_135 / 100 ) ;
V_2 -> V_149 = V_151 ;
V_30 =
F_48 ( V_15 , 16457 * V_135 / 100 , & V_52 ,
V_102 ) ;
break;
default:
F_34 ( V_15 , V_152 * V_135 / 100 ) ;
V_2 -> V_149 = V_152 ;
V_30 =
F_48 ( V_15 , V_107 * V_135 / 100 , & V_52 ,
V_102 ) ;
}
switch ( V_153 ) {
case 0 :
V_47 = 0 ;
V_46 = 0 ;
break;
case 1 :
V_47 = V_154 ;
V_46 = 0 ;
break;
case 2 :
V_47 = 0 ;
V_46 = V_154 ;
break;
case 3 :
V_47 = V_155 ;
V_46 = 0 ;
break;
case 4 :
V_47 = 0 ;
V_46 = V_155 ;
break;
case 5 :
V_47 = V_142 ;
V_46 = 0 ;
break;
case 6 :
V_47 = 0 ;
V_46 = V_142 ;
break;
case 7 :
V_47 = V_156 ;
V_46 = 0 ;
break;
case 8 :
V_47 = 0 ;
V_46 = V_156 ;
}
F_35 ( V_15 ) ;
F_5 ( L_38 , V_7 ) ;
memset ( V_15 -> V_32 -> V_33 , V_34 , 1 ) ;
F_17 ( V_15 -> V_32 , V_15 -> V_10 -> V_35 ,
F_18 ( V_15 -> V_10 -> V_35 ,
V_15 -> V_36 ) ,
V_15 -> V_32 -> V_33 , 1 ,
V_37 , V_15 ) ;
V_30 = F_19 ( V_15 -> V_32 , V_6 ) ;
if ( V_30 ) {
F_59 ( & V_15 -> V_35 , L_39
L_40 , V_7 , V_30 ) ;
F_52 ( V_15 ) ;
} else {
F_5 ( L_41 , V_7 ) ;
}
return V_30 ;
}
static int F_60 ( struct V_16 * V_15 , unsigned int V_11 )
{
int V_31 ;
T_1 * V_3 ;
V_3 = F_29 ( 5 , V_6 ) ;
if ( ! V_3 )
return - V_8 ;
F_5 ( L_10 , V_7 ) ;
V_3 [ 0 ] = V_157 ;
V_3 [ 1 ] = V_11 & 0xFF ;
V_3 [ 2 ] = ( V_11 >> 8 ) & 0xFF ;
V_3 [ 3 ] = ( V_11 >> 16 ) & 0xFF ;
V_3 [ 4 ] = ( V_11 >> 24 ) & 0xFF ;
V_31 = F_25 ( V_15 , V_3 , 5 ) ;
F_2 ( V_3 ) ;
if ( V_31 != V_54 )
F_5 ( L_42 , V_7 , V_31 ) ;
else
F_5 ( L_43 , V_7 ) ;
return V_31 ;
}
static T_7 F_61 ( struct V_158 * V_35 ,
struct V_159 * V_160 , char * V_3 )
{
struct V_16 * V_15 = F_62 ( V_35 ) ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
return sprintf ( V_3 , L_44 , V_2 -> V_11 ) ;
}
static T_7 F_63 ( struct V_158 * V_35 ,
struct V_159 * V_160 , const char * V_3 , T_8 V_51 )
{
struct V_16 * V_15 = F_62 ( V_35 ) ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned long V_161 ;
if ( F_64 ( V_3 , 10 , & V_161 ) ) {
F_59 ( V_35 , L_45 ,
V_7 , V_3 ) ;
goto V_162;
}
F_5 ( L_46 , V_7 , V_161 ) ;
if ( ( V_161 != 3 ) && ( V_161 != 5 ) ) {
F_59 ( V_35 , L_47 , V_7 , V_161 ) ;
} else {
F_60 ( V_15 , V_161 ) ;
V_2 -> V_11 = V_161 ;
}
V_162:
return V_51 ;
}
static int F_65 ( struct V_16 * V_15 )
{
F_5 ( L_4 , V_7 ) ;
return F_66 ( & V_15 -> V_35 , & V_163 ) ;
}
static int F_67 ( struct V_16 * V_15 )
{
F_5 ( L_4 , V_7 ) ;
F_68 ( & V_15 -> V_35 , & V_163 ) ;
return 0 ;
}
static int T_9 F_69 ( void )
{
int V_164 ;
V_164 = F_70 ( & V_165 ) ;
if ( V_164 )
goto V_166;
V_164 = F_71 ( & V_167 ) ;
if ( V_164 )
goto V_168;
F_72 (KERN_INFO KBUILD_MODNAME L_48 DRIVER_VERSION L_49
DRIVER_DESC L_50 ) ;
return 0 ;
V_168:
F_73 ( & V_165 ) ;
V_166:
return V_164 ;
}
static void T_10 F_74 ( void )
{
F_75 ( & V_167 ) ;
F_73 ( & V_165 ) ;
}
