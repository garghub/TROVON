static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , const T_1 * V_4 , int V_5 )
{
#define F_2 3
#define F_3 (MAX_WR_LEN + 1)
int V_6 ;
T_1 V_7 [ F_3 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_10 ,
. V_12 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( F_4 ( V_5 > F_2 ) )
return - V_13 ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_5 ( V_2 -> V_11 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_6 ( & V_2 -> V_11 -> V_15 ,
L_1 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 )
{
#define F_8 1
#define F_9 (MAX_RD_LEN)
int V_6 ;
T_1 V_7 [ F_9 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 -> V_10 ,
. V_12 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 -> V_10 ,
. V_12 = V_18 ,
. V_5 = V_5 ,
. V_7 = V_7 ,
}
} ;
if ( F_4 ( V_5 > F_8 ) )
return - V_13 ;
V_6 = F_5 ( V_2 -> V_11 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_6 ( & V_2 -> V_11 -> V_15 ,
L_2 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_7 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_19 )
{
int V_6 ;
T_1 V_20 ;
if ( V_19 != 0xff ) {
V_6 = F_7 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_19 ;
V_20 &= ~ V_19 ;
V_4 |= V_20 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_13 ( struct V_21 * V_22 ,
int V_23 , int V_24 , T_1 V_3 , T_1 V_19 , T_1 V_4 , T_1 * V_25 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_6 , V_27 ;
T_1 V_20 ;
struct V_28 V_29 [] = {
{ 0x51 , 0x1f - V_23 } ,
{ 0x51 , 0x1f } ,
{ 0x50 , 0x00 + V_23 } ,
{ 0x50 , 0x00 } ,
} ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
F_14 ( & V_2 -> V_11 -> V_15 ,
L_3 ,
V_30 , V_27 , V_23 , V_3 , V_19 , V_4 ) ;
for ( V_27 = 0 ; V_27 < F_15 ( V_29 ) ; V_27 ++ ) {
V_6 = F_10 ( V_2 , V_29 [ V_27 ] . V_3 ,
V_29 [ V_27 ] . V_4 ) ;
if ( V_6 )
goto V_31;
}
F_16 ( V_24 * 1000 , V_24 * 10000 ) ;
V_6 = F_11 ( V_2 , V_3 , & V_20 ) ;
if ( V_6 )
goto V_31;
if ( ( V_20 & V_19 ) != V_4 )
break;
}
if ( V_25 )
* V_25 = V_20 ;
V_31:
return V_6 ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
struct V_32 * V_33 = & V_22 -> V_34 ;
int V_6 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 , V_39 , V_40 , V_41 , V_42 , V_43 ;
T_1 V_7 [ 3 ] , V_20 , V_44 , V_45 , V_46 , V_47 , V_48 ;
T_2 V_49 ;
F_14 ( & V_2 -> V_11 -> V_15 ,
L_4 ,
V_30 , V_33 -> V_50 , V_33 -> V_51 , V_33 -> V_52 ) ;
V_38 = F_18 ( V_2 -> V_53 . clock , 1000 ) ;
V_40 = F_18 ( V_38 , 2000 ) ;
if ( V_33 -> V_51 < 5000000 )
V_36 = 3000 ;
else
V_36 = 0 ;
V_35 = V_33 -> V_50 + V_36 ;
if ( V_35 < 1103000 ) {
V_41 = 4 ;
V_20 = 0x1b ;
} else {
V_41 = 2 ;
V_20 = 0x0b ;
}
V_7 [ 0 ] = V_20 ;
V_7 [ 1 ] = 0x40 ;
V_6 = F_1 ( V_2 , 0x10 , V_7 , 2 ) ;
if ( V_6 )
goto V_31;
V_39 = V_35 * V_41 ;
V_42 = V_39 * V_40 / V_38 ;
V_42 += V_42 % 2 ;
V_2 -> V_35 = V_42 * V_38 / V_40 / V_41 ;
if ( V_42 < 4095 )
V_49 = V_42 - 1024 ;
else if ( V_42 < 6143 )
V_49 = V_42 + 1024 ;
else
V_49 = V_42 + 3072 ;
V_7 [ 0 ] = ( V_49 >> 8 ) & 0x3f ;
V_7 [ 1 ] = ( V_49 >> 0 ) & 0xff ;
V_7 [ 2 ] = V_40 - 8 ;
V_6 = F_1 ( V_2 , 0x01 , V_7 , 3 ) ;
if ( V_6 )
goto V_31;
F_14 ( & V_2 -> V_11 -> V_15 ,
L_5 ,
V_30 , V_2 -> V_35 ,
V_2 -> V_35 - V_33 -> V_50 , V_39 , V_42 ,
V_40 , V_41 ) ;
V_6 = F_13 ( V_22 , 0x10 , 5 , 0x15 , 0x40 , 0x00 , NULL ) ;
if ( V_6 )
goto V_31;
V_6 = F_11 ( V_2 , 0x14 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_20 &= 0x7f ;
if ( V_20 < 64 ) {
V_6 = F_12 ( V_2 , 0x10 , 0x80 , 0x80 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x11 , 0x6f ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x10 , 5 , 0x15 , 0x40 , 0x00 , NULL ) ;
if ( V_6 )
goto V_31;
}
V_6 = F_11 ( V_2 , 0x14 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_20 &= 0x1f ;
if ( V_20 > 19 ) {
V_6 = F_12 ( V_2 , 0x10 , 0x00 , 0x02 ) ;
if ( V_6 )
goto V_31;
}
V_6 = F_13 ( V_22 , 0x08 , 5 , 0x3c , 0xff , 0x00 , NULL ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x25 , 0x00 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x27 , 0x70 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x41 , 0x09 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x08 , 0x0b ) ;
if ( V_6 )
goto V_31;
V_43 = F_18 ( V_38 * 1694U , 1000000U ) ;
V_6 = F_10 ( V_2 , 0x04 , V_43 ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_44 = V_20 & 0x3f ;
V_6 = F_10 ( V_2 , 0x41 , 0x0d ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_20 &= 0x3f ;
V_44 = ( V_44 + V_20 ) / 2 ;
V_43 = V_43 * 207 / ( V_44 * 2 + 151 ) ;
V_47 = V_43 * 135 / 100 ;
V_48 = V_43 * 78 / 100 ;
V_47 = F_19 ( V_47 , 0U , 63U ) ;
V_37 = V_33 -> V_51 * 135UL / 200UL ;
V_37 += 2000000U + ( V_36 * 1000U ) ;
V_37 = F_20 ( V_37 , 7000000U , 40000000U ) ;
#define F_21 3200U
V_45 = F_18 ( V_37 * V_43 , F_21 * V_38 ) ;
V_45 = F_19 ( V_45 , 1U , 23U ) ;
V_46 = F_18 ( V_45 * F_21 * V_38 , V_37 ) ;
if ( V_46 < V_48 )
V_46 = F_18 ( ++ V_45 * F_21 * V_38 , V_37 ) ;
V_46 = F_19 ( V_46 , 0U , V_47 ) ;
V_6 = F_10 ( V_2 , 0x04 , V_46 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x06 , V_45 ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_44 = V_20 & 0x3f ;
V_6 = F_10 ( V_2 , 0x41 , 0x09 ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_20 &= 0x3f ;
V_44 = ( V_44 + V_20 ) / 2 ;
V_20 = V_44 | 0x80 ;
V_6 = F_10 ( V_2 , 0x25 , V_20 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x27 , 0x30 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x08 , 0x09 ) ;
if ( V_6 )
goto V_31;
V_6 = F_13 ( V_22 , 0x01 , 20 , 0x21 , 0xff , 0x00 , NULL ) ;
if ( V_6 )
goto V_31;
V_31:
if ( V_6 )
F_14 ( & V_2 -> V_11 -> V_15 , L_6 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_6 , V_27 ;
T_1 V_20 ;
static const struct V_28 V_29 [] = {
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
F_14 ( & V_2 -> V_11 -> V_15 , L_7 , V_30 ) ;
V_6 = F_10 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x00 , 0x03 ) ;
if ( V_6 )
goto V_31;
switch ( V_2 -> V_53 . V_54 ) {
case V_55 :
V_20 = 0x60 ;
break;
case V_56 :
V_20 = 0x70 ;
V_6 = F_10 ( V_2 , 0x05 , V_2 -> V_53 . V_57 ) ;
if ( V_6 )
goto V_31;
break;
case V_58 :
V_20 = 0x6c ;
break;
default:
goto V_31;
}
V_6 = F_10 ( V_2 , 0x42 , V_20 ) ;
if ( V_6 )
goto V_31;
if ( V_2 -> V_53 . V_59 )
V_20 = 0xec ;
else
V_20 = 0x6c ;
V_6 = F_10 ( V_2 , 0x62 , V_20 ) ;
if ( V_6 )
goto V_31;
for ( V_27 = 0 ; V_27 < F_15 ( V_29 ) ; V_27 ++ ) {
V_6 = F_10 ( V_2 , V_29 [ V_27 ] . V_3 , V_29 [ V_27 ] . V_4 ) ;
if ( V_6 )
goto V_31;
}
V_31:
if ( V_6 )
F_14 ( & V_2 -> V_11 -> V_15 , L_6 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_6 ;
F_14 ( & V_2 -> V_11 -> V_15 , L_7 , V_30 ) ;
V_6 = F_10 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_31;
V_31:
if ( V_6 )
F_14 ( & V_2 -> V_11 -> V_15 , L_6 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_21 * V_22 , T_3 * V_50 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_14 ( & V_2 -> V_11 -> V_15 , L_7 , V_30 ) ;
* V_50 = V_2 -> V_35 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , T_3 * V_50 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_14 ( & V_2 -> V_11 -> V_15 , L_7 , V_30 ) ;
* V_50 = 0 ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 , T_2 * V_60 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_6 ;
T_1 V_20 ;
T_2 V_61 , V_49 ;
unsigned int V_62 , V_63 , V_64 ;
V_6 = F_11 ( V_2 , 0x3d , & V_20 ) ;
if ( V_6 )
goto V_31;
V_62 = ( V_20 >> 0 ) & 0x1f ;
V_62 = F_20 ( V_62 , 0U , 15U ) ;
V_6 = F_11 ( V_2 , 0x21 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_63 = ( V_20 >> 0 ) & 0x1f ;
V_63 = F_20 ( V_63 , 2U , 16U ) ;
V_6 = F_11 ( V_2 , 0x66 , & V_20 ) ;
if ( V_6 )
goto V_31;
V_64 = ( V_20 >> 3 ) & 0x07 ;
V_64 = F_20 ( V_64 , 0U , 6U ) ;
V_61 = V_62 * 265 + V_63 * 338 + V_64 * 285 ;
V_49 = ( 0xffff - V_61 ) ;
V_49 = F_19 ( V_49 , 59000U , 61500U ) ;
* V_60 = ( V_49 - 59000 ) * 0xffff / ( 61500 - 59000 ) ;
V_31:
if ( V_6 )
F_14 ( & V_2 -> V_11 -> V_15 , L_6 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_27 ( struct V_65 * V_11 ,
const struct V_66 * V_67 )
{
struct V_68 * V_53 = V_11 -> V_15 . V_69 ;
struct V_21 * V_22 = V_53 -> V_22 ;
struct V_1 * V_2 ;
int V_6 ;
T_1 V_70 , V_20 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 ) {
V_6 = - V_72 ;
F_29 ( & V_11 -> V_15 , L_8 , V_16 ) ;
goto V_31;
}
memcpy ( & V_2 -> V_53 , V_53 , sizeof( struct V_68 ) ) ;
V_2 -> V_11 = V_11 ;
V_6 = F_11 ( V_2 , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_31;
if ( ( V_20 & 0x03 ) == 0x00 ) {
V_6 = F_10 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_31;
F_16 ( 2000 , 50000 ) ;
}
V_6 = F_10 ( V_2 , 0x00 , 0x03 ) ;
if ( V_6 )
goto V_31;
F_16 ( 2000 , 50000 ) ;
V_6 = F_11 ( V_2 , 0x00 , & V_70 ) ;
if ( V_6 )
goto V_31;
F_14 ( & V_2 -> V_11 -> V_15 , L_9 , V_30 , V_70 ) ;
switch ( V_70 ) {
case 0xc3 :
case 0x83 :
break;
default:
goto V_31;
}
switch ( V_2 -> V_53 . V_54 ) {
case V_55 :
V_20 = 0x60 ;
break;
case V_56 :
V_20 = 0x70 ;
V_6 = F_10 ( V_2 , 0x05 , V_2 -> V_53 . V_57 ) ;
if ( V_6 )
goto V_31;
break;
case V_58 :
V_20 = 0x6c ;
break;
default:
goto V_31;
}
V_6 = F_10 ( V_2 , 0x42 , V_20 ) ;
if ( V_6 )
goto V_31;
if ( V_2 -> V_53 . V_59 )
V_20 = 0xec ;
else
V_20 = 0x6c ;
V_6 = F_10 ( V_2 , 0x62 , V_20 ) ;
if ( V_6 )
goto V_31;
V_6 = F_10 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_31;
F_30 ( & V_2 -> V_11 -> V_15 ,
L_10 ,
V_16 ) ;
V_22 -> V_26 = V_2 ;
memcpy ( & V_22 -> V_73 . V_74 , & V_75 ,
sizeof( struct V_76 ) ) ;
F_31 ( V_11 , V_2 ) ;
return 0 ;
V_31:
F_14 ( & V_11 -> V_15 , L_6 , V_30 , V_6 ) ;
F_32 ( V_2 ) ;
return V_6 ;
}
static int F_33 ( struct V_65 * V_11 )
{
struct V_1 * V_2 = F_34 ( V_11 ) ;
struct V_21 * V_22 = V_2 -> V_53 . V_22 ;
F_14 ( & V_11 -> V_15 , L_7 , V_30 ) ;
memset ( & V_22 -> V_73 . V_74 , 0 , sizeof( struct V_76 ) ) ;
V_22 -> V_26 = NULL ;
F_32 ( V_2 ) ;
return 0 ;
}
