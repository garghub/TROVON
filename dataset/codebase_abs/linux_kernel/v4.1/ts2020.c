static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_3 ;
T_1 V_8 [] = { V_4 , V_5 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_7 -> V_12 ,
. V_13 = 0 ,
. V_8 = V_8 ,
. V_14 = 2
}
} ;
int V_15 ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 1 ) ;
V_15 = F_4 ( V_7 -> V_18 , V_10 , 1 ) ;
if ( V_15 != 1 ) {
F_5 ( V_19
L_1 ,
V_20 , V_15 , V_4 , V_5 ) ;
return - V_21 ;
}
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_6 * V_7 = V_2 -> V_3 ;
int V_22 ;
T_1 V_23 [] = { V_4 } ;
T_1 V_24 [] = { 0 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_7 -> V_12 ,
. V_13 = 0 ,
. V_8 = V_23 ,
. V_14 = 1
} , {
. V_11 = V_7 -> V_12 ,
. V_13 = V_25 ,
. V_8 = V_24 ,
. V_14 = 1
}
} ;
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 1 ) ;
V_22 = F_4 ( V_7 -> V_18 , V_10 , 2 ) ;
if ( V_22 != 2 ) {
F_5 ( V_19 L_2 ,
V_20 , V_4 , V_22 ) ;
return V_22 ;
}
if ( V_2 -> V_16 . V_17 )
V_2 -> V_16 . V_17 ( V_2 , 0 ) ;
return V_24 [ 0 ] ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_3 ;
T_1 V_26 ;
if ( V_7 -> V_27 == V_28 )
V_26 = 0x0a ;
else
V_26 = 0x00 ;
return F_3 ( V_2 , V_26 , 0x00 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_3 ;
int V_29 ;
T_1 V_26 ;
if ( V_7 -> V_27 == V_28 ) {
F_3 ( V_2 , 0x42 , 0x73 ) ;
F_3 ( V_2 , 0x05 , V_7 -> V_30 ) ;
F_3 ( V_2 , 0x20 , 0x27 ) ;
F_3 ( V_2 , 0x07 , 0x02 ) ;
F_3 ( V_2 , 0x11 , 0xff ) ;
F_3 ( V_2 , 0x60 , 0xf9 ) ;
F_3 ( V_2 , 0x08 , 0x01 ) ;
F_3 ( V_2 , 0x00 , 0x41 ) ;
} else {
static const struct V_31 V_32 [] = {
{ 0x7d , 0x9d } ,
{ 0x7c , 0x9a } ,
{ 0x7a , 0x76 } ,
{ 0x3b , 0x01 } ,
{ 0x63 , 0x88 } ,
{ 0x61 , 0x85 } ,
{ 0x22 , 0x30 } ,
{ 0x30 , 0x40 } ,
{ 0x20 , 0x23 } ,
{ 0x24 , 0x02 } ,
{ 0x12 , 0xa0 } ,
} ;
F_3 ( V_2 , 0x00 , 0x01 ) ;
F_3 ( V_2 , 0x00 , 0x03 ) ;
switch ( V_7 -> V_33 ) {
case V_34 :
V_26 = 0x60 ;
break;
case V_35 :
V_26 = 0x70 ;
F_3 ( V_2 , 0x05 , V_7 -> V_30 ) ;
break;
case V_36 :
V_26 = 0x6c ;
break;
default:
V_26 = 0x60 ;
break;
}
F_3 ( V_2 , 0x42 , V_26 ) ;
if ( V_7 -> V_37 )
V_26 = 0xec ;
else
V_26 = 0x6c ;
F_3 ( V_2 , 0x62 , V_26 ) ;
for ( V_29 = 0 ; V_29 < F_9 ( V_32 ) ; V_29 ++ )
F_3 ( V_2 , V_32 [ V_29 ] . V_4 , V_32 [ V_29 ] . V_38 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_39 )
{
int V_22 ;
V_22 = F_3 ( V_2 , 0x51 , 0x1f - V_39 ) ;
V_22 |= F_3 ( V_2 , 0x51 , 0x1f ) ;
V_22 |= F_3 ( V_2 , 0x50 , V_39 ) ;
V_22 |= F_3 ( V_2 , 0x50 , 0x00 ) ;
F_11 ( 20 ) ;
return V_22 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_6 ( V_2 , 0x3d ) ;
V_4 &= 0x7f ;
if ( V_4 < 0x16 )
V_4 = 0xa1 ;
else if ( V_4 == 0x16 )
V_4 = 0x99 ;
else
V_4 = 0xf9 ;
F_3 ( V_2 , 0x60 , V_4 ) ;
V_4 = F_10 ( V_2 , 0x08 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_42 ;
struct V_6 * V_7 = V_2 -> V_3 ;
int V_22 ;
T_2 V_43 = V_41 -> V_43 ;
T_3 V_44 ;
T_2 V_45 = ( V_41 -> V_45 / 1000 ) ;
T_2 V_46 , V_47 ;
T_4 V_48 , V_49 , V_50 ;
T_1 V_51 , V_52 , V_53 , V_54 ;
T_1 V_55 = 0x01 , V_56 = 0x0 ;
if ( V_43 < V_7 -> V_57 ) {
V_55 |= 0x10 ;
V_56 = 0x1 ;
V_49 = ( V_43 * 14 * 4 ) / V_58 ;
} else
V_49 = ( V_43 * 14 * 2 ) / V_58 ;
V_49 = V_49 + V_49 % 2 ;
V_49 = V_49 - 1024 ;
if ( V_7 -> V_27 == V_28 ) {
V_50 = 2766 ;
V_22 = F_3 ( V_2 , 0x10 , 0x80 | V_55 ) ;
} else {
V_50 = 3200 ;
V_22 = F_3 ( V_2 , 0x10 , 0x0b ) ;
V_22 |= F_3 ( V_2 , 0x11 , 0x40 ) ;
}
V_22 |= F_3 ( V_2 , 0x01 , ( V_49 >> 8 ) & 0xf ) ;
V_22 |= F_3 ( V_2 , 0x02 , V_49 & 0xff ) ;
V_22 |= F_3 ( V_2 , 0x03 , 0x06 ) ;
V_22 |= F_10 ( V_2 , 0x10 ) ;
if ( V_22 < 0 )
return - V_59 ;
V_22 = F_3 ( V_2 , 0x10 , V_55 ) ;
V_22 |= F_10 ( V_2 , 0x08 ) ;
if ( V_7 -> V_27 == V_28 )
V_22 |= F_12 ( V_2 ) ;
V_47 = ( V_58 / 1000 * 1694 + 500 ) / 1000 ;
V_22 |= F_3 ( V_2 , 0x04 , V_47 & 0xff ) ;
V_22 |= F_10 ( V_2 , 0x04 ) ;
if ( V_22 < 0 )
return - V_59 ;
if ( V_7 -> V_27 == V_60 ) {
V_22 = F_3 ( V_2 , 0x25 , 0x00 ) ;
V_22 |= F_3 ( V_2 , 0x27 , 0x70 ) ;
V_22 |= F_3 ( V_2 , 0x41 , 0x09 ) ;
V_22 |= F_3 ( V_2 , 0x08 , 0x0b ) ;
if ( V_22 < 0 )
return - V_59 ;
}
V_48 = F_6 ( V_2 , 0x26 ) ;
V_46 = ( V_45 * 135 ) / 200 + 2000 ;
V_46 += V_61 ;
if ( V_46 < 7000 )
V_46 = 7000 ;
if ( V_46 > 40000 )
V_46 = 40000 ;
V_47 = V_47 * 207 / ( V_48 * 2 + 151 ) ;
V_52 = V_47 * 135 / 100 ;
V_53 = V_47 * 78 / 100 ;
if ( V_52 > 63 )
V_52 = 63 ;
V_54 = ( V_46 * V_47 * 2 / V_50 /
( V_58 / 1000 ) + 1 ) / 2 ;
if ( V_54 > 23 )
V_54 = 23 ;
if ( V_54 < 1 )
V_54 = 1 ;
V_51 = ( V_54 * ( V_58 / 1000 )
* V_50 * 2 / V_46 + 1 ) / 2 ;
if ( V_51 < V_53 ) {
V_54 ++ ;
V_51 = ( V_54 * ( V_58 / 1000 )
* V_50 * 2 / V_46 + 1 ) / 2 ;
}
if ( V_51 > V_52 )
V_51 = V_52 ;
V_22 = F_3 ( V_2 , 0x04 , V_51 ) ;
V_22 |= F_3 ( V_2 , 0x06 , V_54 ) ;
V_22 |= F_10 ( V_2 , 0x04 ) ;
V_22 |= F_10 ( V_2 , 0x01 ) ;
F_11 ( 80 ) ;
V_44 = ( V_49 - V_49 % 2 + 1024 ) * V_58
/ ( 6 + 8 ) / ( V_56 + 1 ) / 2 ;
V_7 -> V_43 = V_44 ;
return ( V_22 < 0 ) ? - V_62 : 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 * V_43 )
{
struct V_6 * V_7 = V_2 -> V_3 ;
* V_43 = V_7 -> V_43 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_43 )
{
* V_43 = 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_4 * V_63 )
{
T_4 V_64 , V_65 ;
T_1 V_66 , V_67 ;
V_66 = F_6 ( V_2 , 0x3d ) & 0x1f ;
V_67 = F_6 ( V_2 , 0x21 ) & 0x1f ;
if ( V_66 > 15 )
V_66 = 15 ;
if ( V_67 > 13 )
V_67 = 13 ;
V_64 = V_66 * 2 + V_67 * 3 ;
V_65 = 40 + ( 64 - V_64 ) * 50 / 64 ;
* V_63 = V_65 * 1000 ;
return 0 ;
}
struct V_1 * F_17 ( struct V_1 * V_2 ,
const struct V_68 * V_69 ,
struct V_70 * V_18 )
{
struct V_6 * V_7 = NULL ;
T_1 V_8 ;
V_7 = F_18 ( sizeof( struct V_6 ) , V_71 ) ;
if ( V_7 == NULL )
return NULL ;
V_7 -> V_12 = V_69 -> V_72 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_33 = V_69 -> V_33 ;
V_7 -> V_30 = V_69 -> V_30 ;
V_7 -> V_57 = V_69 -> V_57 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_3 = V_7 ;
if ( ! V_7 -> V_57 )
V_7 -> V_57 = 1060000 ;
if ( ( 0x03 & F_6 ( V_2 , 0x00 ) ) == 0x00 ) {
F_3 ( V_2 , 0x00 , 0x01 ) ;
F_11 ( 2 ) ;
}
F_3 ( V_2 , 0x00 , 0x03 ) ;
F_11 ( 2 ) ;
V_8 = F_6 ( V_2 , 0x00 ) ;
if ( ( V_8 == 0x01 ) || ( V_8 == 0x41 ) || ( V_8 == 0x81 ) ) {
F_5 ( V_73 L_3 , V_20 ) ;
V_7 -> V_27 = V_28 ;
} else if ( ( V_8 == 0x83 ) || ( V_8 == 0xc3 ) ) {
F_5 ( V_73 L_4 , V_20 ) ;
V_7 -> V_27 = V_60 ;
} else {
F_5 ( V_19 L_5 , V_20 , V_8 ) ;
F_2 ( V_7 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_16 . V_74 , & V_75 ,
sizeof( struct V_76 ) ) ;
return V_2 ;
}
static int F_19 ( struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
struct V_68 * V_81 = V_78 -> V_82 . V_83 ;
struct V_1 * V_2 = V_81 -> V_2 ;
struct V_6 * V_82 ;
int V_22 ;
T_1 V_26 ;
unsigned int V_84 ;
char * V_85 ;
V_82 = F_18 ( sizeof( * V_82 ) , V_71 ) ;
if ( ! V_82 ) {
V_22 = - V_86 ;
goto V_15;
}
V_82 -> V_18 = V_78 -> V_87 ;
V_82 -> V_12 = V_78 -> V_11 ;
V_82 -> V_33 = V_81 -> V_33 ;
V_82 -> V_30 = V_81 -> V_30 ;
V_82 -> V_57 = V_81 -> V_57 ;
V_82 -> V_2 = V_2 ;
V_2 -> V_3 = V_82 ;
V_22 = F_6 ( V_2 , 0x00 ) ;
if ( V_22 < 0 )
goto V_15;
V_84 = V_22 ;
if ( ( V_84 & 0x03 ) == 0x00 ) {
V_22 = F_3 ( V_2 , 0x00 , 0x01 ) ;
if ( V_22 )
goto V_15;
F_20 ( 2000 , 50000 ) ;
}
V_22 = F_3 ( V_2 , 0x00 , 0x03 ) ;
if ( V_22 )
goto V_15;
F_20 ( 2000 , 50000 ) ;
V_22 = F_6 ( V_2 , 0x00 ) ;
if ( V_22 < 0 )
goto V_15;
V_84 = V_22 ;
F_21 ( & V_78 -> V_82 , L_6 , V_84 ) ;
switch ( V_84 ) {
case 0x01 :
case 0x41 :
case 0x81 :
V_82 -> V_27 = V_28 ;
V_85 = L_7 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = 1060000 ;
break;
case 0xc3 :
case 0x83 :
V_82 -> V_27 = V_60 ;
V_85 = L_8 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = 1103000 ;
break;
default:
V_22 = - V_59 ;
goto V_15;
}
if ( V_82 -> V_27 == V_60 ) {
switch ( V_82 -> V_33 ) {
case V_34 :
V_26 = 0x60 ;
break;
case V_35 :
V_26 = 0x70 ;
V_22 = F_3 ( V_2 , 0x05 , V_82 -> V_30 ) ;
if ( V_22 )
goto V_15;
break;
case V_36 :
V_26 = 0x6c ;
break;
default:
V_22 = - V_62 ;
goto V_15;
}
V_22 = F_3 ( V_2 , 0x42 , V_26 ) ;
if ( V_22 )
goto V_15;
if ( V_82 -> V_37 )
V_26 = 0xec ;
else
V_26 = 0x6c ;
V_22 = F_3 ( V_2 , 0x62 , V_26 ) ;
if ( V_22 )
goto V_15;
}
V_22 = F_3 ( V_2 , 0x00 , 0x00 ) ;
if ( V_22 )
goto V_15;
F_22 ( & V_78 -> V_82 ,
L_9 , V_85 ) ;
memcpy ( & V_2 -> V_16 . V_74 , & V_75 ,
sizeof( struct V_76 ) ) ;
V_2 -> V_16 . V_74 . V_88 = NULL ;
F_23 ( V_78 , V_82 ) ;
return 0 ;
V_15:
F_21 ( & V_78 -> V_82 , L_10 , V_22 ) ;
F_2 ( V_82 ) ;
return V_22 ;
}
static int F_24 ( struct V_77 * V_78 )
{
struct V_6 * V_82 = F_25 ( V_78 ) ;
struct V_1 * V_2 = V_82 -> V_2 ;
F_21 ( & V_78 -> V_82 , L_11 ) ;
memset ( & V_2 -> V_16 . V_74 , 0 , sizeof( struct V_76 ) ) ;
V_2 -> V_3 = NULL ;
F_2 ( V_82 ) ;
return 0 ;
}
