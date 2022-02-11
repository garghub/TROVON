void F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 ,
unsigned char V_5 )
{
V_2 -> V_6 . V_7 ( V_2 , V_3 ) ;
V_2 -> V_6 . V_8 ( V_2 , V_3 , V_4 , V_5 ) ;
F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
V_2 -> V_6 . V_9 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_10 )
{
unsigned int V_3 ;
unsigned char V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_11 / 2 ; V_3 ++ ) {
F_1 ( V_2 , V_3 , 0x01 , V_10 ? 0x00 : 0x03 ) ;
if ( V_10 )
continue;
for ( V_4 = 0x04 ; V_4 < V_2 -> V_12 ; V_4 ++ )
F_1 ( V_2 , V_3 , V_4 ,
F_4 ( V_2 , V_3 , V_4 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 , int V_10 )
{
unsigned char V_4 ;
if ( V_10 ) {
F_1 ( V_2 , 0 , 0x01 , 0x02 ) ;
return;
}
for ( V_4 = 0x00 ; V_4 < V_2 -> V_12 ; V_4 ++ )
if ( V_4 != 0x01 )
F_1 ( V_2 , 0 , V_4 ,
F_4 ( V_2 , 0 , V_4 ) ) ;
F_1 ( V_2 , 0 , 0x01 , 0x01 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_10 )
{
unsigned int V_3 ;
unsigned char V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_11 / 2 ; V_3 ++ ) {
F_1 ( V_2 , V_3 , 0x00 , V_10 ? 0x0c : 0x0f ) ;
if ( V_10 )
continue;
for ( V_4 = 0x01 ; V_4 < V_2 -> V_12 ; V_4 ++ )
F_1 ( V_2 , V_3 , V_4 ,
F_4 ( V_2 , V_3 , V_4 ) ) ;
}
}
void F_7 ( struct V_1 * V_2 , int V_10 )
{
switch ( V_2 -> type ) {
case V_13 :
case V_14 :
case V_15 :
F_3 ( V_2 , V_10 ) ;
break;
case V_16 :
break;
case V_17 :
F_5 ( V_2 , V_10 ) ;
break;
case V_18 :
F_5 ( V_2 , V_10 ) ;
break;
case V_19 :
F_6 ( V_2 , V_10 ) ;
break;
default:
break;
}
}
void F_8 ( struct V_1 * V_2 )
{
static const unsigned char V_20 [] = {
0x00 , 0x07 ,
0x01 , 0x00 ,
0x02 , 0x60 ,
0x03 , 0x19 ,
0x01 , 0x03 ,
0x04 , 0x00 ,
0x05 , 0x00 ,
0x06 , 0x00 ,
0x07 , 0x00 ,
0xff , 0xff
} ;
static const unsigned char V_21 [] = {
0x00 , 0x07 ,
0x01 , 0x00 ,
0x02 , 0x60 ,
0x03 , 0x0d ,
0x01 , 0x03 ,
0x04 , 0x00 ,
0x05 , 0x00 ,
0xff , 0xff
} ;
static const unsigned char V_22 [] = {
0x09 , 0x01 ,
0x0a , 0x3f ,
0x00 , 0x0c ,
0x01 , 0x00 ,
0x02 , 0xff ,
0x03 , 0xff ,
0x04 , 0xff ,
0x05 , 0xff ,
0x06 , 0xff ,
0x07 , 0xff ,
0x0b , 0xff ,
0x0c , 0xff ,
0x08 , 0x55 ,
0xff , 0xff
} ;
static const unsigned char V_23 [] = {
0x01 , 0x02 ,
0x00 , 0x06 ,
0x02 , 0x0e ,
0x03 , 0x01 ,
0x04 , 0x00 ,
0x05 , 0x00 ,
0x06 , 0x00 ,
0x07 , 0x00 ,
0x08 , 0x00 ,
0x09 , 0x00 ,
0x0a , 0x00 ,
0x01 , 0x01 ,
0xff , 0xff
} ;
static const unsigned char V_24 [] = {
0x01 , 0x02 ,
0x00 , 0x06 ,
0x02 , 0x4e ,
0x03 , 0x01 ,
0x04 , 0x00 ,
0x05 , 0x00 ,
0x06 , 0x00 ,
0x07 , 0x00 ,
0x08 , 0x00 ,
0x09 , 0x00 ,
0x0b , 0x00 ,
0x0c , 0x00 ,
0x0a , 0x00 ,
0x01 , 0x01 ,
0xff , 0xff
} ;
static const unsigned char V_25 [] = {
0x00 , 0x0c ,
0x01 , 0x02 ,
0x02 , 0x00 ,
0x03 , 0x00 ,
0x04 , 0x00 ,
0x00 , 0x0f ,
0xff , 0xff
} ;
static const unsigned char V_26 [] = {
0x00 , 0x07 ,
0x01 , 0x00 ,
0x01 , 0x02 ,
0x01 , 0x03 ,
0x01 , 0x0f ,
0x02 , 0x60 ,
0x03 , 0x01 ,
0x04 , 0x00 ,
0x05 , 0x00 ,
0x06 , 0x00 ,
0x07 , 0x00 ,
0xff , 0xff
} ;
int V_3 ;
const unsigned char * V_27 , * V_28 ;
unsigned char V_4 , V_29 ;
memset ( V_2 -> V_30 , 0 , sizeof( V_2 -> V_30 ) ) ;
memset ( V_2 -> V_31 , 0 , sizeof( V_2 -> V_31 ) ) ;
switch ( V_2 -> type ) {
case V_13 :
V_28 = V_20 ;
V_2 -> V_32 = V_2 -> V_11 / 2 ;
V_2 -> V_33 = L_1 ;
V_2 -> V_12 = 0x08 ;
break;
case V_14 :
V_28 = V_21 ;
V_2 -> V_32 = V_2 -> V_11 / 2 ;
V_2 -> V_33 = L_2 ;
V_2 -> V_12 = 0x06 ;
break;
case V_16 :
V_28 = V_22 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = L_3 ;
V_2 -> V_12 = 0x0d ;
break;
case V_17 :
V_28 = V_23 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = L_4 ;
V_2 -> V_12 = 0x0b ;
break;
case V_18 :
V_28 = V_24 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = L_5 ;
V_2 -> V_12 = 0x10 ;
break;
case V_19 :
V_28 = V_25 ;
V_2 -> V_32 = V_2 -> V_11 / 2 ;
V_2 -> V_33 = L_6 ;
V_2 -> V_12 = 0x05 ;
break;
case V_34 :
V_2 -> V_32 = 1 ;
V_2 -> V_33 = L_7 ;
V_2 -> V_12 = 0x08 ;
return;
case V_15 :
V_28 = V_26 ;
V_2 -> V_32 = V_2 -> V_11 / 2 ;
V_2 -> V_33 = L_8 ;
V_2 -> V_12 = 0x08 ;
break;
default:
F_9 () ;
return;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_32 ; V_3 ++ ) {
V_27 = V_28 ;
while ( * V_27 != 0xff ) {
V_4 = * V_27 ++ ;
V_29 = * V_27 ++ ;
F_1 ( V_2 , V_3 , V_4 , V_29 ) ;
F_10 ( 10 ) ;
}
}
}
static int F_11 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
unsigned int V_39 = F_12 ( V_36 -> V_40 ) ;
V_38 -> type = V_41 ;
V_38 -> V_42 = 1 ;
V_38 -> V_43 . integer . V_44 = 0 ;
V_38 -> V_43 . integer . V_45 = V_39 ;
return 0 ;
}
static int F_13 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
V_47 -> V_43 . integer . V_43 [ 0 ] = F_17 ( V_2 , V_3 , V_48 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 , int V_48 ,
unsigned char V_49 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
unsigned int V_39 = F_12 ( V_36 -> V_40 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
if ( F_17 ( V_2 , V_3 , V_48 ) == V_49 )
return 0 ;
F_19 ( V_2 , V_3 , V_48 , V_49 ) ;
if ( F_20 ( V_36 -> V_40 ) && V_49 < 128 )
V_49 = V_50 [ V_49 ] ;
if ( F_21 ( V_36 -> V_40 ) && V_49 >= 128 )
V_49 ++ ;
if ( F_22 ( V_36 -> V_40 ) )
V_49 = V_39 - V_49 ;
if ( F_23 ( V_36 -> V_40 ) )
V_49 |= 0x80 ;
F_1 ( V_2 , V_3 , V_48 , V_49 ) ;
return 1 ;
}
static int F_24 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
unsigned int V_39 = F_12 ( V_36 -> V_40 ) ;
unsigned int V_5 = V_47 -> V_43 . integer . V_43 [ 0 ] ;
if ( V_5 > V_39 )
return - V_51 ;
return F_18 ( V_36 , F_16 ( V_36 -> V_40 ) , V_5 ) ;
}
static int F_25 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
unsigned int V_39 = F_12 ( V_36 -> V_40 ) ;
V_38 -> type = V_41 ;
V_38 -> V_42 = 2 ;
V_38 -> V_43 . integer . V_44 = 0 ;
V_38 -> V_43 . integer . V_45 = V_39 ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
V_47 -> V_43 . integer . V_43 [ 0 ] = F_17 ( V_2 , V_3 , V_48 ) ;
V_47 -> V_43 . integer . V_43 [ 1 ] = F_17 ( V_2 , V_3 , V_48 + 1 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
int V_48 = F_16 ( V_36 -> V_40 ) ;
unsigned int V_39 = F_12 ( V_36 -> V_40 ) ;
unsigned int V_5 [ 2 ] ;
int V_52 ;
V_5 [ 0 ] = V_47 -> V_43 . integer . V_43 [ 0 ] ;
V_5 [ 1 ] = V_47 -> V_43 . integer . V_43 [ 1 ] ;
if ( V_5 [ 0 ] > V_39 || V_5 [ 1 ] > V_39 )
return - V_51 ;
V_52 = F_18 ( V_36 , V_48 , V_5 [ 0 ] ) ;
V_52 |= F_18 ( V_36 , V_48 + 1 , V_5 [ 1 ] ) ;
return V_52 ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
static char * V_53 [ 4 ] = {
L_9 , L_10 , L_11 , L_12 ,
} ;
V_38 -> type = V_54 ;
V_38 -> V_42 = 1 ;
V_38 -> V_43 . V_55 . V_56 = 4 ;
if ( V_38 -> V_43 . V_55 . V_57 >= 4 )
V_38 -> V_43 . V_55 . V_57 = 3 ;
strcpy ( V_38 -> V_43 . V_55 . V_33 ,
V_53 [ V_38 -> V_43 . V_55 . V_57 ] ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_58 = F_30 ( V_36 -> V_40 ) ;
V_47 -> V_43 . V_55 . V_57 [ 0 ] =
( F_4 ( V_2 , V_3 , V_48 ) >> V_58 ) & 3 ;
return 0 ;
}
static int F_31 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_58 = F_30 ( V_36 -> V_40 ) ;
unsigned char V_49 = V_47 -> V_43 . V_55 . V_57 [ 0 ] & 3 ;
int V_52 ;
V_49 = ( V_49 << V_58 ) |
( F_4 ( V_2 , V_3 , V_48 ) & ~ ( 3 << V_58 ) ) ;
V_52 = F_4 ( V_2 , V_3 , V_48 ) != V_49 ;
if ( V_52 )
F_1 ( V_2 , V_3 , V_48 , V_49 ) ;
return V_52 ;
}
static int F_32 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_58 = F_30 ( V_36 -> V_40 ) ;
int V_59 = F_22 ( V_36 -> V_40 ) ;
unsigned char V_5 = F_4 ( V_2 , V_3 , V_48 ) & ( 1 << V_58 ) ;
if ( V_59 )
V_5 = ! V_5 ;
V_47 -> V_43 . integer . V_43 [ 0 ] = ( V_5 & ( 1 << V_58 ) ) != 0 ;
return 0 ;
}
static int F_33 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_58 = F_30 ( V_36 -> V_40 ) ;
int V_59 = F_22 ( V_36 -> V_40 ) ;
long V_60 = V_47 -> V_43 . integer . V_43 [ 0 ] ;
unsigned char V_5 , V_61 ;
int V_52 ;
if ( V_59 )
V_60 = ! V_60 ;
V_61 = F_4 ( V_2 , V_3 , V_48 ) ;
if ( V_60 )
V_5 = V_61 | ( 1 << V_58 ) ;
else
V_5 = V_61 & ~ ( 1 << V_58 ) ;
V_52 = ( V_61 != V_5 ) ;
if ( V_52 )
F_1 ( V_2 , V_3 , V_48 , V_5 ) ;
return V_52 ;
}
static int F_34 ( struct V_1 * V_2 , int V_62 )
{
int V_63 ;
const char * * V_64 ;
V_64 = V_2 -> V_65 [ V_62 ] . V_64 ;
V_63 = 0 ;
while ( V_63 < V_66 && V_64 [ V_63 ] )
++ V_63 ;
return V_63 ;
}
static int F_35 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_62 = F_30 ( V_36 -> V_40 ) ;
const char * * V_64 ;
int V_63 , V_67 ;
V_63 = F_34 ( V_2 , V_62 ) ;
if ( ! V_63 )
return - V_51 ;
V_38 -> type = V_54 ;
V_38 -> V_42 = 1 ;
V_38 -> V_43 . V_55 . V_56 = V_63 ;
V_67 = V_38 -> V_43 . V_55 . V_57 ;
if ( V_67 >= V_63 )
return - V_51 ;
V_64 = V_2 -> V_65 [ V_62 ] . V_64 ;
strncpy ( V_38 -> V_43 . V_55 . V_33 , V_64 [ V_67 ] ,
sizeof( V_38 -> V_43 . V_55 . V_33 ) ) ;
return 0 ;
}
static int F_36 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_39 = F_12 ( V_36 -> V_40 ) ;
unsigned char V_5 ;
V_5 = F_4 ( V_2 , V_3 , V_48 ) & V_39 ;
V_47 -> V_43 . V_55 . V_57 [ 0 ] = V_5 ;
return 0 ;
}
static int F_37 ( struct V_35 * V_36 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_62 = F_30 ( V_36 -> V_40 ) ;
int V_3 = F_15 ( V_36 -> V_40 ) ;
int V_48 = F_16 ( V_36 -> V_40 ) ;
int V_39 = F_12 ( V_36 -> V_40 ) ;
unsigned char V_61 , V_5 ;
int V_63 = F_34 ( V_2 , V_62 ) ;
if ( V_47 -> V_43 . V_55 . V_57 [ 0 ] >= V_63 )
return - V_51 ;
V_61 = F_4 ( V_2 , V_3 , V_48 ) ;
V_5 = V_61 & ~ V_39 ;
V_5 |= V_47 -> V_43 . V_55 . V_57 [ 0 ] & V_39 ;
if ( V_5 != V_61 ) {
F_1 ( V_2 , V_3 , V_48 , V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_67 , V_68 , V_62 , V_69 ;
struct V_70 V_71 ;
V_62 = 0 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_11 ; ) {
if ( V_2 -> type == V_19
&& V_2 -> V_72 [ V_62 ] . V_73 ) {
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_74 = V_75 ;
V_71 . V_42 = 1 ;
V_71 . V_76 = V_77 ;
V_71 . V_33 = V_2 -> V_72 [ V_62 ] . V_73 ;
V_71 . V_78 = V_79 ;
V_71 . V_80 = F_32 ;
V_71 . V_81 = F_33 ;
V_71 . V_76 = 0 ;
V_71 . V_40 =
F_39 ( V_67 / 2 , 1 , 0 , 0 ) | V_82 ;
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
if ( ! V_2 -> V_72 || ! V_2 -> V_72 [ V_62 ] . V_33 ) {
V_71 . V_33 = L_13 ;
V_71 . V_84 = V_62 + V_2 -> V_85 * 2 ;
V_69 = 1 ;
} else {
V_71 . V_33 = V_2 -> V_72 [ V_62 ] . V_33 ;
V_69 = V_2 -> V_72 [ V_62 ] . V_86 ;
}
V_71 . V_74 = V_75 ;
V_71 . V_42 = 1 ;
V_71 . V_76 = V_77 |
V_87 ;
if ( V_69 == 2 ) {
V_71 . V_78 = F_25 ;
V_71 . V_80 = F_26 ;
V_71 . V_81 = F_27 ;
} else {
V_71 . V_78 = F_11 ;
V_71 . V_80 = F_13 ;
V_71 . V_81 = F_24 ;
}
switch ( V_2 -> type ) {
case V_13 :
V_71 . V_40 =
F_39 ( V_67 / 2 , ( V_67 % 2 ) + 6 , 0 , 127 ) |
V_88 ;
V_71 . V_89 . V_90 = V_91 ;
break;
case V_14 :
V_71 . V_40 =
F_39 ( V_67 / 2 , ( V_67 % 2 ) + 4 , 0 , 127 ) |
V_88 ;
V_71 . V_89 . V_90 = V_91 ;
break;
case V_16 : {
int V_5 = V_67 < 6 ? V_67 + 2 : ( V_67 - 6 ) + 0xb ;
V_71 . V_40 =
F_39 ( 0 , V_5 , 0 , 255 ) | V_82 ;
V_71 . V_89 . V_90 = V_92 ;
break;
}
case V_17 :
V_71 . V_40 = F_39 ( 0 , V_67 + 4 , 0 , 255 ) ;
V_71 . V_89 . V_90 = V_92 ;
break;
case V_18 : {
int V_48 = V_67 < 6 ? V_67 + 4 : V_67 + 5 ;
V_71 . V_40 =
F_39 ( 0 , V_48 , 0 , 127 ) | V_93 ;
V_71 . V_89 . V_90 = V_94 ;
break;
}
case V_19 :
V_71 . V_40 =
F_39 ( V_67 / 2 , ( V_67 % 2 ) + 3 , 0 , 255 ) ;
V_71 . V_89 . V_90 = V_95 ;
break;
case V_15 :
V_71 . V_40 =
F_39 ( V_67 / 2 , ( V_67 % 2 ) + 6 , 0 , 255 ) ;
V_71 . V_89 . V_90 = V_95 ;
break;
default:
return - V_51 ;
}
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
V_67 += V_69 ;
V_62 ++ ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_67 , V_68 , V_62 , V_69 , V_96 ;
struct V_70 V_71 ;
V_62 = 0 ;
if ( V_2 -> type == V_14 )
return 0 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_97 ; ) {
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
if ( ! V_2 -> V_65 || ! V_2 -> V_65 [ V_62 ] . V_33 ) {
V_71 . V_33 = L_14 ;
V_71 . V_84 = V_62 + V_2 -> V_85 * 2 ;
V_69 = 1 ;
} else {
V_71 . V_33 = V_2 -> V_65 [ V_62 ] . V_33 ;
V_69 = V_2 -> V_65 [ V_62 ] . V_86 ;
}
V_71 . V_74 = V_75 ;
V_71 . V_42 = 1 ;
V_71 . V_76 = V_77 |
V_87 ;
if ( V_69 == 2 ) {
V_71 . V_78 = F_25 ;
V_71 . V_80 = F_26 ;
V_71 . V_81 = F_27 ;
} else {
V_71 . V_78 = F_11 ;
V_71 . V_80 = F_13 ;
V_71 . V_81 = F_24 ;
}
if ( V_2 -> type == V_34 )
V_96 = 152 ;
else
V_96 = 164 ;
V_71 . V_40 =
F_39 ( V_67 / 2 , ( V_67 % 2 ) + 4 , 0 , V_96 ) |
V_88 | V_98 ;
V_71 . V_89 . V_90 = V_91 ;
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_2 -> type == V_34 && ( V_67 % 2 ) == 0 ) {
if ( ! V_2 -> V_65 ||
! V_2 -> V_65 [ V_62 ] . V_73 ) {
V_71 . V_33 = L_15 ;
V_71 . V_84 = V_62 + V_2 -> V_85 * 2 ;
} else
V_71 . V_33 = V_2 -> V_65 [ V_62 ] . V_73 ;
V_71 . V_78 = V_79 ;
V_71 . V_80 = F_32 ;
V_71 . V_81 = F_33 ;
V_71 . V_76 = 0 ;
V_71 . V_40 =
F_39 ( V_67 / 2 , 2 , 0 , 0 ) | V_82 ;
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_33 = V_2 -> V_65 [ V_62 ] . V_99 ;
if ( ! V_71 . V_33 ) {
V_71 . V_33 = L_16 ;
V_71 . V_84 = V_62 + V_2 -> V_85 * 2 ;
}
V_71 . V_74 = V_75 ;
V_71 . V_78 = F_35 ;
V_71 . V_80 = F_36 ;
V_71 . V_81 = F_37 ;
V_71 . V_76 = 0 ;
V_71 . V_40
= F_39 ( V_67 / 2 , 1 , V_62 , 0x07 ) ;
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
}
V_67 += V_69 ;
V_62 ++ ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_100 )
{
int V_67 , V_68 ;
struct V_70 V_71 ;
for ( V_67 = 0 ; V_67 < V_100 ; V_67 ++ ) {
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_33 = L_17 ;
V_71 . V_84 = V_67 + V_2 -> V_85 ;
V_71 . V_74 = V_75 ;
V_71 . V_42 = 1 ;
V_71 . V_78 = F_28 ;
V_71 . V_80 = F_29 ;
V_71 . V_81 = F_31 ;
switch ( V_2 -> type ) {
case V_13 :
case V_14 :
case V_15 :
V_71 . V_40 = F_39 ( V_67 , 3 , 0 , 0 ) ;
break;
case V_16 : {
int V_58 = V_67 == 3 ? 6 : ( 2 - V_67 ) * 2 ;
V_71 . V_40 = F_39 ( 0 , 8 , V_58 , 0 ) ;
break;
}
case V_17 :
case V_18 :
V_71 . V_40 = F_39 ( V_67 , 3 , 0 , 0 ) ;
break;
case V_19 :
V_71 . V_40 = F_39 ( V_67 , 1 , 1 , 0 ) ;
break;
default:
return - V_51 ;
}
V_68 = F_40 ( V_2 -> V_83 , F_41 ( & V_71 , V_2 ) ) ;
if ( V_68 < 0 )
return V_68 ;
}
return 0 ;
}
static void F_44 ( struct V_101 * V_102 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_102 -> V_105 ;
int V_4 , V_5 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_32 ; V_3 ++ ) {
for ( V_4 = 0 ; V_4 < V_2 -> V_12 ; V_4 ++ ) {
V_5 = F_4 ( V_2 , V_3 , V_4 ) ;
F_45 ( V_104 , L_18 , V_3 ,
V_4 , V_5 ) ;
}
}
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_101 * V_102 ;
int V_68 ;
V_68 = F_47 ( V_2 -> V_83 , V_2 -> V_33 , & V_102 ) ;
if ( V_68 < 0 )
return V_68 ;
F_48 ( V_102 , V_2 , F_44 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ) { return 0 ; }
int F_49 ( struct V_1 * V_2 )
{
int V_68 , V_100 ;
V_68 = F_38 ( V_2 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_42 ( V_2 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_2 -> type == V_17 || V_2 -> type == V_18 )
V_100 = 1 ;
else if ( V_2 -> type == V_15 )
V_100 = 0 ;
else
V_100 = V_2 -> V_11 / 2 ;
V_68 = F_43 ( V_2 , V_100 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_46 ( V_2 ) ;
if ( V_68 < 0 )
return V_68 ;
return 0 ;
}
static int T_1 F_50 ( void )
{
return 0 ;
}
static void T_2 F_51 ( void )
{
}
