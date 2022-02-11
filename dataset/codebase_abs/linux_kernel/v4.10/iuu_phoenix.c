static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 = V_2 -> V_3 ;
if ( V_2 -> V_4 < V_3 || V_2 -> V_5 < V_3 )
return - V_6 ;
return 0 ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_10 = F_3 ( sizeof( struct V_9 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_10 -> V_14 = F_3 ( 256 , V_12 ) ;
if ( ! V_10 -> V_14 ) {
F_4 ( V_10 ) ;
return - V_13 ;
}
V_10 -> V_15 = F_3 ( 256 , V_12 ) ;
if ( ! V_10 -> V_15 ) {
F_4 ( V_10 -> V_14 ) ;
F_4 ( V_10 ) ;
return - V_13 ;
}
V_10 -> V_16 = V_17 ;
F_5 ( & V_10 -> V_18 ) ;
F_6 ( V_8 , V_10 ) ;
V_11 = F_7 ( V_8 ) ;
if ( V_11 ) {
F_4 ( V_10 -> V_15 ) ;
F_4 ( V_10 -> V_14 ) ;
F_4 ( V_10 ) ;
return V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
F_4 ( V_10 -> V_15 ) ;
F_4 ( V_10 -> V_14 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
struct V_7 * V_8 = V_20 -> V_23 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_24 ;
F_12 ( & V_8 -> V_25 , L_1 ,
V_26 , V_21 , V_22 ) ;
F_13 ( & V_10 -> V_18 , V_24 ) ;
if ( ( V_21 & V_27 ) && ! ( V_10 -> V_28 == V_27 ) ) {
F_12 ( & V_8 -> V_25 , L_2 , V_26 ) ;
V_10 -> V_29 = 1 ;
}
if ( V_21 & V_27 )
V_10 -> V_28 = V_27 ;
F_14 ( & V_10 -> V_18 , V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_23 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_24 ;
int V_30 ;
F_13 ( & V_10 -> V_18 , V_24 ) ;
V_30 = V_10 -> V_28 ;
F_14 ( & V_10 -> V_18 , V_24 ) ;
return V_30 ;
}
static void F_16 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 ;
int V_34 = V_31 -> V_34 ;
if ( V_34 ) {
F_12 ( & V_8 -> V_25 , L_3 , V_26 , V_34 ) ;
return;
}
memset ( V_8 -> V_35 -> V_36 , V_37 , 1 ) ;
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 1 ,
V_39 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
}
static int F_20 ( struct V_7 * V_8 , T_1 V_41 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
int V_33 ;
char * V_42 = V_8 -> V_35 -> V_36 ;
* V_42 ++ = V_43 ;
* V_42 ++ = V_44 ;
* V_42 ++ = V_41 ;
* V_42 = V_45 ;
F_17 ( V_8 -> V_35 ,
V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 4 , F_16 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
V_10 -> V_29 = 0 ;
return V_33 ;
}
static void F_21 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
T_1 * V_46 ;
int V_34 = V_31 -> V_34 ;
if ( V_34 ) {
F_12 ( & V_8 -> V_25 , L_3 , V_26 , V_34 ) ;
return;
}
V_46 = V_31 -> V_36 ;
F_12 ( & V_8 -> V_25 , L_4 , V_26 ) ;
if ( V_31 -> V_47 == 1 ) {
switch ( V_46 [ 0 ] ) {
case 0x1 :
V_10 -> V_28 = V_48 ;
break;
case 0x0 :
V_10 -> V_28 = V_49 ;
break;
default:
V_10 -> V_28 = V_49 ;
}
}
F_16 ( V_31 ) ;
}
static void F_22 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 ;
int V_34 = V_31 -> V_34 ;
F_12 ( & V_8 -> V_25 , L_3 , V_26 , V_34 ) ;
F_17 ( V_8 -> V_50 , V_8 -> V_2 -> V_25 ,
F_23 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_51 ) ,
V_8 -> V_50 -> V_36 , 256 ,
F_21 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_50 , V_40 ) ;
}
static int F_24 ( struct V_7 * V_8 )
{
int V_33 ;
memset ( V_8 -> V_35 -> V_36 , V_52 , 1 ) ;
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 1 ,
F_22 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
return V_33 ;
}
static int F_25 ( struct V_7 * V_8 , T_1 * V_14 , T_1 V_53 )
{
int V_34 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_54 = 0 ;
V_34 =
F_26 ( V_2 -> V_25 ,
F_18 ( V_2 -> V_25 ,
V_8 -> V_38 ) , V_14 ,
V_53 , & V_54 , 1000 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_5 , V_26 , V_34 ) ;
else
F_12 ( & V_8 -> V_25 , L_6 , V_26 ) ;
return V_34 ;
}
static int F_27 ( struct V_7 * V_8 , T_1 * V_14 , T_1 V_53 )
{
int V_34 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_54 = 0 ;
V_34 =
F_26 ( V_2 -> V_25 ,
F_23 ( V_2 -> V_25 ,
V_8 -> V_51 ) , V_14 ,
V_53 , & V_54 , 1000 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_5 , V_26 , V_34 ) ;
else
F_12 ( & V_8 -> V_25 , L_7 , V_26 ) ;
return V_34 ;
}
static int F_28 ( struct V_7 * V_8 , unsigned int V_56 ,
unsigned int V_57 , unsigned int V_58 , T_1 V_59 )
{
int V_34 ;
T_1 * V_14 ;
V_14 = F_29 ( 8 , V_12 ) ;
if ( ! V_14 )
return - V_13 ;
V_14 [ 0 ] = V_60 ;
V_14 [ 1 ] = V_56 & 0xFF ;
V_14 [ 2 ] = ( V_56 >> 8 ) & 0xFF ;
V_14 [ 3 ] = V_57 & 0xFF ;
V_14 [ 4 ] = ( V_57 >> 8 ) & 0xFF ;
V_14 [ 5 ] = V_58 & 0xFF ;
V_14 [ 6 ] = ( V_58 >> 8 ) & 0xFF ;
V_14 [ 7 ] = V_59 ;
V_34 = F_25 ( V_8 , V_14 , 8 ) ;
F_4 ( V_14 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_8 , V_26 , V_34 ) ;
else
F_12 ( & V_8 -> V_25 , L_9 , V_26 ) ;
return V_55 ;
}
static void F_30 ( T_1 * V_14 , T_1 V_61 , T_1 V_62 , T_1 V_63 , T_1 V_64 , T_1 V_65 ,
T_1 V_66 , T_1 V_67 )
{
* V_14 ++ = V_60 ;
* V_14 ++ = V_61 ;
* V_14 ++ = V_62 ;
* V_14 ++ = V_63 ;
* V_14 ++ = V_64 ;
* V_14 ++ = V_65 ;
* V_14 ++ = V_66 ;
* V_14 = V_67 ;
}
static void F_31 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 ;
char * V_42 = V_8 -> V_35 -> V_36 ;
* V_42 ++ = V_60 ;
if ( V_68 ) {
F_32 ( V_42 , 6 ) ;
* ( V_42 + 7 ) = 1 ;
} else {
F_30 ( V_42 , 255 , 255 , 0 , 0 , 0 , 0 , 255 ) ;
}
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 8 ,
F_16 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
}
static void F_33 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 ;
char * V_42 = V_8 -> V_35 -> V_36 ;
if ( V_68 ) {
F_16 ( V_31 ) ;
return;
} else {
* V_42 ++ = V_60 ;
F_30 ( V_42 , 0 , 0 , 255 , 255 , 0 , 0 , 255 ) ;
}
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 8 ,
F_16 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
}
static int F_34 ( struct V_7 * V_8 , int V_69 )
{
int V_34 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
int V_70 = 0 ;
T_1 V_71 = 0x69 ;
T_1 DIV = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
unsigned int V_78 = 0 ;
unsigned int V_79 = 0 ;
int V_80 = ( int ) V_69 ;
if ( V_80 == 0 ) {
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x09 ;
V_10 -> V_14 [ V_70 ++ ] = 0x00 ;
V_34 = F_25 ( V_8 , ( T_1 * ) V_10 -> V_14 , V_70 ) ;
if ( V_34 != 0 ) {
F_12 ( & V_8 -> V_25 , L_10 , V_26 ) ;
return V_34 ;
}
} else if ( V_80 == 3579000 ) {
DIV = 100 ;
V_78 = 1193 ;
V_77 = 40 ;
V_72 = 0 ;
} else if ( V_80 == 3680000 ) {
DIV = 105 ;
V_78 = 161 ;
V_77 = 5 ;
V_72 = 0 ;
} else if ( V_80 == 6000000 ) {
DIV = 66 ;
V_78 = 66 ;
V_77 = 2 ;
V_72 = 0x28 ;
} else {
unsigned int V_33 = 0 ;
unsigned int V_82 = 0 ;
unsigned int V_83 ;
unsigned int V_84 ;
char V_85 = 0x00 ;
unsigned int V_86 = 2 ;
unsigned int V_87 = 2055 ;
unsigned int lDiv = 4 ;
for ( V_86 = 2 ; V_86 <= 47 && ! V_85 ; V_86 ++ )
for ( V_87 = 2055 ; V_87 >= 8 && ! V_85 ; V_87 -- )
for ( lDiv = 4 ; lDiv <= 127 && ! V_85 ; lDiv ++ ) {
V_82 = ( 12000000 / lDiv ) * ( V_87 / V_86 ) ;
if ( abs ( ( int ) ( V_82 - V_80 ) ) <
abs ( ( int ) ( V_80 - V_33 ) ) ) {
V_84 = ( 12000000 / V_86 ) ;
if ( V_84 < 250000 )
continue;
V_83 = ( 12000000 / V_86 ) * V_87 ;
if ( V_83 > 400000000 )
continue;
if ( V_83 < 100000000 )
continue;
if ( lDiv < 4 || lDiv > 127 )
continue;
V_33 = V_82 ;
V_78 = V_87 ;
DIV = lDiv ;
V_77 = V_86 ;
if ( V_33 == V_80 )
V_85 = 0x01 ;
}
}
}
V_79 = ( ( V_78 - V_76 ) / 2 ) - 4 ;
DIV = DIV ;
V_73 = 0x04 ;
V_74 = ( V_79 >> 8 & 0x03 ) ;
V_75 = V_79 & 0xFF ;
V_76 = ( V_78 >> 10 ) & 0x01 ;
V_77 = V_77 - 2 ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x09 ;
V_10 -> V_14 [ V_70 ++ ] = 0x20 ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x0C ;
V_10 -> V_14 [ V_70 ++ ] = DIV ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x12 ;
V_10 -> V_14 [ V_70 ++ ] = V_72 ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x13 ;
V_10 -> V_14 [ V_70 ++ ] = 0x6B ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x40 ;
V_10 -> V_14 [ V_70 ++ ] = ( 0xC0 | ( ( V_73 & 0x07 ) << 2 ) ) |
( V_74 & 0x03 ) ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x41 ;
V_10 -> V_14 [ V_70 ++ ] = V_75 ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x42 ;
V_10 -> V_14 [ V_70 ++ ] = V_77 | ( ( ( V_76 & 0x01 ) << 7 ) ) ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x44 ;
V_10 -> V_14 [ V_70 ++ ] = ( char ) 0xFF ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x45 ;
V_10 -> V_14 [ V_70 ++ ] = ( char ) 0xFE ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x46 ;
V_10 -> V_14 [ V_70 ++ ] = 0x7F ;
V_10 -> V_14 [ V_70 ++ ] = V_81 ;
V_10 -> V_14 [ V_70 ++ ] = V_71 << 1 ;
V_10 -> V_14 [ V_70 ++ ] = 0x47 ;
V_10 -> V_14 [ V_70 ++ ] = ( char ) 0x84 ;
V_34 = F_25 ( V_8 , ( T_1 * ) V_10 -> V_14 , V_70 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_10 , V_26 ) ;
return V_34 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_88 * V_25 = & V_8 -> V_25 ;
int V_89 ;
int V_34 ;
T_1 V_90 = V_37 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
if ( F_28 ( V_8 , 0xF000 , 0 , 0 , 0xFF ) < 0 )
return - V_91 ;
for ( V_89 = 0 ; V_89 < 2 ; V_89 ++ ) {
V_34 = F_25 ( V_8 , & V_90 , 1 ) ;
if ( V_34 != V_55 ) {
F_12 ( V_25 , L_11 , V_26 ) ;
return V_34 ;
}
V_34 = F_27 ( V_8 , & V_10 -> V_92 , 1 ) ;
if ( V_34 != V_55 ) {
F_12 ( V_25 , L_12 , V_26 ) ;
return V_34 ;
}
if ( V_10 -> V_92 > 0 ) {
F_12 ( V_25 , L_13 , V_26 , V_10 -> V_92 ) ;
V_34 = F_27 ( V_8 , V_10 -> V_14 , V_10 -> V_92 ) ;
if ( V_34 != V_55 ) {
F_12 ( V_25 , L_12 , V_26 ) ;
return V_34 ;
}
}
}
F_12 ( V_25 , L_14 , V_26 ) ;
F_28 ( V_8 , 0 , 0xF000 , 0 , 0xFF ) ;
return V_34 ;
}
static void F_36 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
unsigned char * V_93 = V_31 -> V_36 ;
int V_34 = V_31 -> V_34 ;
if ( V_34 ) {
if ( V_34 == - V_94 ) {
}
return;
}
F_12 ( & V_8 -> V_25 , L_15 , V_26 , V_31 -> V_47 ) ;
if ( V_93 == NULL )
F_12 ( & V_8 -> V_25 , L_16 , V_26 ) ;
if ( V_31 -> V_47 && V_93 ) {
F_37 ( & V_8 -> V_8 , V_93 , V_31 -> V_47 ) ;
F_38 ( & V_8 -> V_8 ) ;
}
F_31 ( V_31 ) ;
}
static int F_39 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_24 ;
int V_33 ;
int V_95 ;
char * V_42 = V_8 -> V_35 -> V_36 ;
F_13 ( & V_10 -> V_18 , V_24 ) ;
* V_42 ++ = V_96 ;
* V_42 ++ = V_97 ;
* V_42 ++ = V_10 -> V_98 ;
memcpy ( V_42 , V_10 -> V_15 , V_10 -> V_98 ) ;
V_95 = V_10 -> V_98 ;
V_10 -> V_98 = 0 ;
F_14 ( & V_10 -> V_18 , V_24 ) ;
F_12 ( & V_8 -> V_25 , L_17 , V_26 ,
V_95 , V_95 , V_42 ) ;
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , V_95 + 3 ,
F_16 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_40 ) ;
F_40 ( V_8 ) ;
return V_33 ;
}
static int F_41 ( struct V_7 * V_8 , int V_92 )
{
int V_33 ;
F_17 ( V_8 -> V_50 , V_8 -> V_2 -> V_25 ,
F_23 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_51 ) ,
V_8 -> V_50 -> V_36 , V_92 ,
F_36 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_50 , V_40 ) ;
return V_33 ;
}
static void F_42 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_24 ;
int V_34 = V_31 -> V_34 ;
int error = 0 ;
int V_92 = 0 ;
unsigned char * V_93 = V_31 -> V_36 ;
V_10 -> V_99 ++ ;
if ( V_34 ) {
F_12 ( & V_8 -> V_25 , L_3 , V_26 , V_34 ) ;
return;
}
if ( V_93 == NULL )
F_12 ( & V_8 -> V_25 , L_16 , V_26 ) ;
if ( V_31 -> V_47 == 1 && V_93 != NULL )
V_92 = ( int ) V_93 [ 0 ] ;
if ( V_31 -> V_47 > 1 ) {
F_12 ( & V_8 -> V_25 , L_18 , V_26 ,
V_31 -> V_47 ) ;
error = 1 ;
return;
}
if ( V_92 > 0 && error == 0 ) {
F_12 ( & V_8 -> V_25 , L_19 ,
V_26 , V_92 ) ;
V_34 = F_41 ( V_8 , V_92 ) ;
return;
}
if ( V_10 -> V_99 > 99 ) {
V_34 = F_24 ( V_8 ) ;
V_10 -> V_99 = 0 ;
return;
}
if ( V_10 -> V_29 == 1 ) {
V_34 = F_20 ( V_8 , 0xC ) ;
return;
}
F_13 ( & V_10 -> V_18 , V_24 ) ;
if ( V_10 -> V_98 > 0 ) {
F_14 ( & V_10 -> V_18 , V_24 ) ;
V_34 = F_39 ( V_8 ) ;
return;
}
F_14 ( & V_10 -> V_18 , V_24 ) ;
F_12 ( & V_8 -> V_25 , L_20 , V_26 ) ;
F_33 ( V_31 ) ;
}
static int F_43 ( struct V_19 * V_20 , struct V_7 * V_8 ,
const T_1 * V_14 , int V_53 )
{
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_24 ;
if ( V_53 > 256 )
return - V_13 ;
F_13 ( & V_10 -> V_18 , V_24 ) ;
memcpy ( V_10 -> V_15 + V_10 -> V_98 , V_14 , V_53 ) ;
V_10 -> V_98 += V_53 ;
F_14 ( & V_10 -> V_18 , V_24 ) ;
return V_53 ;
}
static void V_39 ( struct V_31 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_32 ;
int V_33 ;
int V_34 = V_31 -> V_34 ;
if ( V_34 ) {
return;
}
F_17 ( V_8 -> V_50 , V_8 -> V_2 -> V_25 ,
F_23 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_51 ) ,
V_8 -> V_50 -> V_36 , 256 ,
F_42 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_50 , V_40 ) ;
F_12 ( & V_8 -> V_25 , L_21 , V_26 , V_33 ) ;
}
static int F_44 ( struct V_7 * V_8 )
{
int V_34 ;
T_1 * V_14 ;
V_14 = F_29 ( sizeof( T_1 ) * 4 , V_12 ) ;
if ( ! V_14 )
return - V_13 ;
V_14 [ 0 ] = V_100 ;
V_14 [ 1 ] = ( T_1 ) ( ( V_101 >> 8 ) & 0x00FF ) ;
V_14 [ 2 ] = ( T_1 ) ( 0x00FF & V_101 ) ;
V_14 [ 3 ] = ( T_1 ) ( 0x0F0 & V_102 ) | ( 0x07 & V_103 ) ;
V_34 = F_25 ( V_8 , V_14 , 4 ) ;
if ( V_34 != V_55 ) {
F_12 ( & V_8 -> V_25 , L_22 , V_26 ) ;
goto V_104;
}
V_34 = F_35 ( V_8 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_23 , V_26 ) ;
V_104:
F_4 ( V_14 ) ;
return V_34 ;
}
static int F_45 ( struct V_7 * V_8 )
{
int V_34 ;
T_1 * V_14 ;
V_14 = F_29 ( 1 , V_12 ) ;
if ( ! V_14 )
return - V_13 ;
V_14 [ 0 ] = V_105 ;
V_34 = F_25 ( V_8 , V_14 , 1 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_24 , V_26 ) ;
F_4 ( V_14 ) ;
return V_34 ;
}
static int F_46 ( struct V_7 * V_8 , T_2 V_106 ,
T_2 * V_54 , T_1 V_107 )
{
int V_34 ;
T_2 V_108 ;
T_1 * V_109 ;
T_1 V_110 = 0 ;
T_1 V_111 = 0 ;
T_1 V_112 = 0 ;
unsigned int V_113 = 0 ;
F_12 ( & V_8 -> V_25 , L_25 , V_26 , V_106 ) ;
V_109 = F_29 ( sizeof( T_1 ) * 5 , V_12 ) ;
if ( ! V_109 )
return - V_13 ;
V_108 = V_106 ;
if ( V_108 < 1200 || V_108 > 230400 ) {
F_4 ( V_109 ) ;
return V_114 ;
}
if ( V_108 > 977 ) {
V_111 = 3 ;
V_113 = 500000 ;
}
if ( V_108 > 3906 ) {
V_111 = 2 ;
V_113 = 2000000 ;
}
if ( V_108 > 11718 ) {
V_111 = 1 ;
V_113 = 6000000 ;
}
if ( V_108 > 46875 ) {
V_111 = 0 ;
V_113 = 24000000 ;
}
V_112 = 256 - ( T_1 ) ( V_113 / ( V_108 * 2 ) ) ;
V_109 [ V_110 ++ ] = V_96 ;
V_109 [ V_110 ++ ] = V_115 ;
V_109 [ V_110 ++ ] = V_111 ;
V_109 [ V_110 ++ ] = V_112 ;
* V_54 = ( V_113 / ( 256 - V_112 ) ) / 2 ;
switch ( V_107 & 0x0F ) {
case V_116 :
V_109 [ V_110 ++ ] = 0x00 ;
break;
case V_103 :
V_109 [ V_110 ++ ] = 0x01 ;
break;
case V_117 :
V_109 [ V_110 ++ ] = 0x02 ;
break;
case V_118 :
V_109 [ V_110 ++ ] = 0x03 ;
break;
case V_119 :
V_109 [ V_110 ++ ] = 0x04 ;
break;
default:
F_4 ( V_109 ) ;
return V_114 ;
break;
}
switch ( V_107 & 0xF0 ) {
case V_102 :
V_109 [ V_110 - 1 ] |= V_102 ;
break;
case V_120 :
V_109 [ V_110 - 1 ] |= V_120 ;
break;
default:
F_4 ( V_109 ) ;
return V_114 ;
break;
}
V_34 = F_25 ( V_8 , V_109 , V_110 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_24 , V_26 ) ;
F_4 ( V_109 ) ;
return V_34 ;
}
static void F_47 ( struct V_19 * V_20 ,
struct V_7 * V_8 , struct V_121 * V_122 )
{
const T_2 V_123 = V_124 | V_125 | V_126 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned int V_127 = V_20 -> V_128 . V_129 ;
int V_34 ;
T_2 V_54 ;
T_2 V_107 ;
int V_130 = V_131 ;
int V_108 ;
T_2 V_132 = V_127 & V_123 ;
V_108 = V_20 -> V_128 . V_133 ;
F_12 ( & V_8 -> V_25 , L_26 , V_26 , V_108 ) ;
V_107 = 0 ;
if ( V_127 & V_124 ) {
if ( V_127 & V_126 )
V_107 |= V_119 ;
else
V_107 |= V_118 ;
} else if ( ! ( V_127 & V_125 ) ) {
V_107 |= V_116 ;
V_130 = V_134 ;
} else if ( V_127 & V_126 )
V_107 |= V_117 ;
else
V_107 |= V_103 ;
V_107 |= ( V_127 & V_135 ? V_120 : V_102 ) ;
V_34 = F_46 ( V_8 ,
V_108 * V_10 -> V_136 / 100 ,
& V_54 , V_107 ) ;
if ( V_122 )
F_48 ( & V_20 -> V_128 , V_122 ) ;
if ( V_34 != 0 )
return;
F_49 ( V_20 , V_108 , V_108 ) ;
V_20 -> V_128 . V_129 &= ~ ( V_123 | V_137 ) ;
V_20 -> V_128 . V_129 |= V_132 | V_130 ;
}
static void F_50 ( struct V_7 * V_8 )
{
F_45 ( V_8 ) ;
F_51 ( V_8 -> V_35 ) ;
F_51 ( V_8 -> V_50 ) ;
F_28 ( V_8 , 0 , 0 , 0xF000 , 0xFF ) ;
}
static void F_52 ( struct V_19 * V_20 )
{
V_20 -> V_128 = V_138 ;
V_20 -> V_128 . V_129 = V_139 | V_140 | V_134 | V_141
| V_142 | V_135 | V_125 ;
V_20 -> V_128 . V_143 = 9600 ;
V_20 -> V_128 . V_133 = 9600 ;
V_20 -> V_128 . V_144 = 0 ;
V_20 -> V_128 . V_145 = 0 ;
V_20 -> V_128 . V_146 = 0 ;
}
static int F_53 ( struct V_19 * V_20 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_88 * V_25 = & V_8 -> V_25 ;
T_1 * V_14 ;
int V_33 ;
int V_108 ;
T_2 V_54 ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
V_108 = V_20 -> V_128 . V_133 ;
V_20 -> V_128 . V_143 = V_108 ;
F_49 ( V_20 , V_108 , V_108 ) ;
F_12 ( V_25 , L_27 , V_26 , V_108 ) ;
F_54 ( V_2 -> V_25 , V_8 -> V_35 -> V_147 ) ;
F_54 ( V_2 -> V_25 , V_8 -> V_50 -> V_147 ) ;
V_14 = F_29 ( 10 , V_12 ) ;
if ( V_14 == NULL )
return - V_13 ;
V_10 -> V_99 = 0 ;
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
F_4 ( V_14 ) ;
F_28 ( V_8 , 0xF000 , 0xF000 , 0 , 0xFF ) ;
F_44 ( V_8 ) ;
if ( V_136 < 100 )
V_136 = 100 ;
V_10 -> V_136 = V_136 ;
V_10 -> V_108 = V_108 ;
switch ( V_148 ) {
case 2 :
V_10 -> V_149 = V_150 ;
F_34 ( V_8 , V_150 * V_136 / 100 ) ;
V_33 =
F_46 ( V_8 , V_108 * V_136 / 100 , & V_54 ,
V_103 ) ;
break;
case 3 :
F_34 ( V_8 , V_151 * V_136 / 100 ) ;
V_10 -> V_149 = V_151 ;
V_33 =
F_46 ( V_8 , 16457 * V_136 / 100 , & V_54 ,
V_103 ) ;
break;
default:
F_34 ( V_8 , V_152 * V_136 / 100 ) ;
V_10 -> V_149 = V_152 ;
V_33 =
F_46 ( V_8 , V_108 * V_136 / 100 , & V_54 ,
V_103 ) ;
}
switch ( V_153 ) {
case 0 :
V_49 = 0 ;
V_48 = 0 ;
break;
case 1 :
V_49 = V_154 ;
V_48 = 0 ;
break;
case 2 :
V_49 = 0 ;
V_48 = V_154 ;
break;
case 3 :
V_49 = V_155 ;
V_48 = 0 ;
break;
case 4 :
V_49 = 0 ;
V_48 = V_155 ;
break;
case 5 :
V_49 = V_142 ;
V_48 = 0 ;
break;
case 6 :
V_49 = 0 ;
V_48 = V_142 ;
break;
case 7 :
V_49 = V_156 ;
V_48 = 0 ;
break;
case 8 :
V_49 = 0 ;
V_48 = V_156 ;
}
F_35 ( V_8 ) ;
F_12 ( V_25 , L_28 , V_26 ) ;
memset ( V_8 -> V_35 -> V_36 , V_37 , 1 ) ;
F_17 ( V_8 -> V_35 , V_8 -> V_2 -> V_25 ,
F_18 ( V_8 -> V_2 -> V_25 ,
V_8 -> V_38 ) ,
V_8 -> V_35 -> V_36 , 1 ,
V_39 , V_8 ) ;
V_33 = F_19 ( V_8 -> V_35 , V_12 ) ;
if ( V_33 ) {
F_57 ( V_25 , L_29 , V_26 , V_33 ) ;
F_50 ( V_8 ) ;
} else {
F_12 ( V_25 , L_30 , V_26 ) ;
}
return V_33 ;
}
static int F_58 ( struct V_7 * V_8 , unsigned int V_16 )
{
int V_34 ;
T_1 * V_14 ;
V_14 = F_29 ( 5 , V_12 ) ;
if ( ! V_14 )
return - V_13 ;
V_14 [ 0 ] = V_157 ;
V_14 [ 1 ] = V_16 & 0xFF ;
V_14 [ 2 ] = ( V_16 >> 8 ) & 0xFF ;
V_14 [ 3 ] = ( V_16 >> 16 ) & 0xFF ;
V_14 [ 4 ] = ( V_16 >> 24 ) & 0xFF ;
V_34 = F_25 ( V_8 , V_14 , 5 ) ;
F_4 ( V_14 ) ;
if ( V_34 != V_55 )
F_12 ( & V_8 -> V_25 , L_31 , V_26 , V_34 ) ;
else
F_12 ( & V_8 -> V_25 , L_32 , V_26 ) ;
return V_34 ;
}
static T_7 F_59 ( struct V_88 * V_25 ,
struct V_158 * V_159 , char * V_14 )
{
struct V_7 * V_8 = F_60 ( V_25 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
return sprintf ( V_14 , L_33 , V_10 -> V_16 ) ;
}
static T_7 F_61 ( struct V_88 * V_25 ,
struct V_158 * V_159 , const char * V_14 , T_8 V_53 )
{
struct V_7 * V_8 = F_60 ( V_25 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
unsigned long V_160 ;
if ( F_62 ( V_14 , 10 , & V_160 ) ) {
F_57 ( V_25 , L_34 ,
V_26 , V_14 ) ;
goto V_161;
}
F_12 ( V_25 , L_35 , V_26 , V_160 ) ;
if ( ( V_160 != 3 ) && ( V_160 != 5 ) ) {
F_57 ( V_25 , L_36 , V_26 , V_160 ) ;
} else {
F_58 ( V_8 , V_160 ) ;
V_10 -> V_16 = V_160 ;
}
V_161:
return V_53 ;
}
static int F_7 ( struct V_7 * V_8 )
{
return F_63 ( & V_8 -> V_25 , & V_162 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
F_64 ( & V_8 -> V_25 , & V_162 ) ;
return 0 ;
}
