unsigned short F_1 ( unsigned short V_1 , char * V_2 ,
unsigned short V_3 )
{
unsigned char V_4 = 0 ;
unsigned char V_5 = 0 ;
unsigned char V_6 = 0 ;
unsigned char V_7 = 0 ;
unsigned char V_8 = 0 ;
unsigned char V_9 = 0 ;
unsigned short V_10 = 0 ;
if ( ( ! strcmp ( V_2 , L_1 ) ) ||
( ! strcmp ( V_2 , L_2 ) ) )
{
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ )
{
V_8 = ( V_3 + V_4 ) % 256 ;
V_9 = ( V_3 + V_4 ) / 256 ;
F_2 ( V_11 , V_1 + 0x3F ) ;
F_3 ( V_1 ) ;
F_2 ( V_8 ,
V_1 + 0x3E ) ;
F_3 ( V_1 ) ;
F_2 ( V_12 , V_1 + 0x3F ) ;
F_3 ( V_1 ) ;
F_2 ( V_9 ,
V_1 + 0x3E ) ;
F_3 ( V_1 ) ;
F_2 ( V_13 , V_1 + 0x3F ) ;
F_3 ( V_1 ) ;
V_5 = F_4 ( V_1 + 0x3E ) ;
F_3 ( V_1 ) ;
if ( V_4 == 0 )
{
V_6 = V_5 ;
}
else
{
V_7 = V_5 ;
}
}
V_10 = ( V_6 | ( ( ( unsigned short ) V_7 ) * 256 ) ) ;
}
if ( ! strcmp ( V_2 , L_3 ) )
{
F_5 ( V_1 , V_3 ,
& V_10 ) ;
}
return V_10 ;
}
void F_3 ( unsigned short V_1 )
{
unsigned char V_14 = 0 ;
do
{
V_14 = F_4 ( V_1 + 0x3F ) ;
V_14 = V_14 & 0x80 ;
} while ( V_14 == 0x80 );
}
void F_6 ( unsigned int V_15 , unsigned int V_16 )
{
F_7 ( V_16 & 0x6 , V_15 ) ;
F_8 ( 100 ) ;
F_7 ( V_16 | 0x1 , V_15 ) ;
F_8 ( 100 ) ;
}
void F_9 ( unsigned int V_15 , unsigned int V_17 ,
unsigned char V_18 )
{
char V_19 = 0 ;
unsigned int V_16 = 0 ;
V_16 = 0x2 ;
F_7 ( V_16 , V_15 ) ;
F_8 ( 100 ) ;
for ( V_19 = ( V_18 - 1 ) ; V_19 >= 0 ; V_19 -- )
{
if ( V_17 & ( 1 << V_19 ) )
{
V_16 = V_16 | 0x4 ;
}
else
{
V_16 = V_16 & 0x3 ;
}
F_7 ( V_16 , V_15 ) ;
F_8 ( 100 ) ;
F_6 ( V_15 , V_16 ) ;
}
}
void F_5 ( unsigned int V_15 , unsigned short V_20 , unsigned short * V_21 )
{
char V_19 = 0 ;
unsigned int V_16 = 0 ;
unsigned int V_22 = 0 ;
F_9 ( V_15 , ( V_23 << 4 ) | ( V_20 / 2 ) ,
V_24 ) ;
V_16 = ( ( ( V_20 / 2 ) & 0x1 ) << 2 ) | 0x2 ;
* V_21 = 0 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
{
F_6 ( V_15 , V_16 ) ;
V_22 = F_10 ( V_15 ) ;
F_8 ( 100 ) ;
if ( V_22 & 0x8 )
{
* V_21 = ( * V_21 << 1 ) | 0x1 ;
}
else
{
* V_21 = ( * V_21 << 1 ) ;
}
}
V_16 = 0x0 ;
F_7 ( V_16 , V_15 ) ;
F_8 ( 100 ) ;
}
int F_11 ( unsigned short V_1 ,
char * V_2 , struct V_25 * V_26 )
{
unsigned short V_27 , V_28 , V_29 = 0 ;
unsigned int V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
struct V_39 V_40 ;
V_32 . V_41 =
F_1 ( V_1 , V_2 ,
0x100 + 8 ) ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + 10 ) ;
V_32 . V_42 = ( unsigned char ) V_27 & 0x00FF ;
for ( V_28 = 0 ; V_28 < V_32 . V_42 ; V_28 ++ ) {
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + 12 + V_29 ) ;
V_32 . V_43 [ V_28 ] . V_44 = ( unsigned char ) V_27 & 0x3F ;
V_29 = V_29 + 2 ;
V_32 . V_43 [ V_28 ] . V_45 =
F_1 ( V_1 ,
V_2 , 0x100 + 12 + V_29 ) ;
V_29 = V_29 + 2 ;
}
for ( V_28 = 0 ; V_28 < V_32 . V_42 ; V_28 ++ ) {
switch ( V_32 . V_43 [ V_28 ] . V_44 ) {
case V_46 :
F_12 ( V_1 ,
V_2 ,
V_32 . V_43 [ V_28 ] . V_45 ,
& V_34 ) ;
V_47 -> V_48 . V_49 =
V_34 . V_50 ;
break;
case V_51 :
F_13 ( V_1 ,
V_2 ,
V_32 . V_43 [ V_28 ] . V_45 ,
& V_36 ) ;
V_47 -> V_48 . V_52 =
V_36 . V_50 ;
V_30 = 0xffffffff ;
V_47 -> V_48 . V_53 =
V_30 >> ( 32 -
V_47 -> V_48 . V_52 ) ;
break;
case V_54 :
F_14 ( V_1 ,
V_2 ,
V_32 . V_43 [ V_28 ] . V_45 ,
& V_40 ) ;
if ( ! ( strcmp ( V_55 -> V_56 , L_4 ) ) )
V_47 -> V_48 . V_57 =
V_40 . V_50 * 4 ;
else
V_47 -> V_48 . V_57 =
V_40 . V_50 ;
V_47 -> V_48 . V_58 =
V_40 . V_59 ;
V_47 -> V_48 . V_60 =
( unsigned int ) V_40 . V_61 *
1000 ;
V_47 -> V_48 . V_62 =
( unsigned int ) V_40 . V_63 *
1000 ;
V_30 = 0xffff ;
V_47 -> V_48 . V_64 =
V_30 >> ( 16 -
V_40 . V_65 ) ;
break;
case V_66 :
F_15 ( V_1 ,
V_2 ,
V_32 . V_43 [ V_28 ] . V_45 ,
& V_38 ) ;
V_47 -> V_48 . V_67 =
V_38 . V_50 ;
V_30 = 0xffff ;
V_47 -> V_48 . V_68 =
V_30 >> ( 16 -
V_38 . V_65 ) ;
break;
case V_69 :
V_47 -> V_48 . V_70 = 1 ;
break;
case V_71 :
V_47 -> V_48 . V_70 = 1 ;
break;
case V_72 :
V_47 -> V_48 . V_70 = 1 ;
break;
}
}
return 0 ;
}
int F_12 ( unsigned short V_1 ,
char * V_2 , unsigned short V_45 ,
struct V_33 * V_73 )
{
unsigned short V_27 ;
V_73 -> V_50 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 6 ) ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + 8 ) ;
V_73 -> V_74 = ( unsigned char ) ( V_27 >> 7 ) & 0x01 ;
V_73 -> V_75 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 10 ) ;
return 0 ;
}
int F_13 ( unsigned short V_1 ,
char * V_2 , unsigned short V_45 ,
struct V_35 * V_73 )
{
V_73 -> V_50 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 6 ) ;
return 0 ;
}
int F_16 ( unsigned short V_1 ,
char * V_2 , unsigned short V_45 ,
struct V_76 * V_73 )
{
unsigned short V_28 , V_77 = 0 , V_27 ;
V_73 -> V_78 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 6 ) ;
for ( V_28 = 0 ; V_28 < V_73 -> V_78 ; V_28 ++ ) {
V_73 -> V_79 [ V_28 ] . V_41 =
F_1 ( V_1 ,
V_2 ,
0x100 + V_45 + 8 + V_77 + 0 ) ;
V_27 = F_1 ( V_1 ,
V_2 ,
0x100 + V_45 + 8 + V_77 + 2 ) ;
V_73 -> V_79 [ V_28 ] . V_65 =
( unsigned char ) ( V_27 >> 10 ) & 0x3F ;
V_73 -> V_79 [ V_28 ] . V_80 =
( unsigned char ) ( V_27 >> 4 ) & 0x3F ;
V_27 = F_1 ( V_1 ,
V_2 ,
0x100 + V_45 + 8 + V_77 + 4 ) ;
V_73 -> V_79 [ V_28 ] . V_81 = ( V_27 >> 6 ) & 0x3FF ;
V_73 -> V_79 [ V_28 ] . V_82 = ( unsigned char ) ( V_27 ) & 0x3F ;
V_77 += V_73 -> V_79 [ V_28 ] . V_41 ;
}
return 0 ;
}
int F_15 ( unsigned short V_1 ,
char * V_2 , unsigned short V_45 ,
struct V_37 * V_73 )
{
unsigned short V_27 ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + 10 ) ;
V_73 -> V_50 = ( V_27 >> 4 ) & 0x03FF ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + 16 ) ;
V_73 -> V_65 = ( unsigned char ) ( V_27 >> 8 ) & 0xFF ;
return 0 ;
}
int F_14 ( unsigned short V_1 ,
char * V_2 , unsigned short V_45 ,
struct V_39 * V_73 )
{
unsigned short V_27 , V_83 ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + 10 ) ;
V_73 -> V_50 = ( V_27 >> 4 ) & 0x03FF ;
V_73 -> V_61 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 16 ) ;
V_73 -> V_63 =
F_1 ( V_1 , V_2 ,
0x100 + V_45 + 30 ) ;
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + 20 ) ;
V_73 -> V_59 = ( V_27 >> 13 ) & 0x01 ;
V_27 = F_1 ( V_1 , V_2 , 0x100 + V_45 + 72 ) ;
V_27 = V_27 & 0x00FF ;
if ( V_27 )
{
V_83 = 74 + ( 2 * V_27 ) + ( 10 * ( 1 + ( V_27 / 16 ) ) ) ;
V_83 = V_83 + 2 ;
} else
{
V_83 = 74 ;
V_83 = V_83 + 2 ;
}
V_27 = F_1 ( V_1 ,
V_2 , 0x100 + V_45 + V_83 ) ;
V_73 -> V_65 = V_27 & 0x001F ;
return 0 ;
}
