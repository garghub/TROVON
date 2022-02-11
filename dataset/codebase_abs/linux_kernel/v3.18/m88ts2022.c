static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 * V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 ;
struct V_12 V_13 [] = {
{ 0x51 , 0x1f - V_3 } ,
{ 0x51 , 0x1f } ,
{ 0x50 , 0x00 + V_3 } ,
{ 0x50 , 0x00 } ,
} ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_2 ( & V_2 -> V_14 -> V_2 ,
L_1 ,
V_10 , V_3 , V_5 , V_6 , V_7 ) ;
for ( V_10 = 0 ; V_10 < F_3 ( V_13 ) ; V_10 ++ ) {
V_9 = F_4 ( V_2 -> V_15 , V_13 [ V_10 ] . V_5 ,
V_13 [ V_10 ] . V_7 ) ;
if ( V_9 )
goto V_16;
}
F_5 ( V_4 * 1000 , V_4 * 10000 ) ;
V_9 = F_6 ( V_2 -> V_15 , V_5 , & V_11 ) ;
if ( V_9 )
goto V_16;
if ( ( V_11 & V_6 ) != V_7 )
break;
}
if ( V_8 )
* V_8 = V_11 ;
V_16:
return V_9 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 ;
int V_9 ;
unsigned int V_11 , V_23 , V_24 , V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ;
T_1 V_32 [ 3 ] , V_33 , V_34 , V_35 , V_36 , V_37 , V_38 ;
T_2 V_39 ;
F_2 ( & V_2 -> V_14 -> V_2 ,
L_2 ,
V_21 -> V_40 , V_21 -> V_41 , V_21 -> V_42 ) ;
V_26 = F_8 ( V_2 -> V_43 . clock , 1000 ) ;
V_28 = F_8 ( V_26 , 2000 ) ;
if ( V_21 -> V_41 < 5000000 )
V_24 = 3000 ;
else
V_24 = 0 ;
V_23 = V_21 -> V_40 + V_24 ;
if ( V_23 < 1103000 ) {
V_29 = 4 ;
V_33 = 0x1b ;
} else {
V_29 = 2 ;
V_33 = 0x0b ;
}
V_32 [ 0 ] = V_33 ;
V_32 [ 1 ] = 0x40 ;
V_9 = F_9 ( V_2 -> V_15 , 0x10 , V_32 , 2 ) ;
if ( V_9 )
goto V_16;
V_27 = V_23 * V_29 ;
V_30 = V_27 * V_28 / V_26 ;
V_30 += V_30 % 2 ;
V_2 -> V_23 = V_30 * V_26 / V_28 / V_29 ;
if ( V_30 < 4095 )
V_39 = V_30 - 1024 ;
else if ( V_30 < 6143 )
V_39 = V_30 + 1024 ;
else
V_39 = V_30 + 3072 ;
V_32 [ 0 ] = ( V_39 >> 8 ) & 0x3f ;
V_32 [ 1 ] = ( V_39 >> 0 ) & 0xff ;
V_32 [ 2 ] = V_28 - 8 ;
V_9 = F_9 ( V_2 -> V_15 , 0x01 , V_32 , 3 ) ;
if ( V_9 )
goto V_16;
F_2 ( & V_2 -> V_14 -> V_2 ,
L_3 ,
V_2 -> V_23 , V_2 -> V_23 - V_21 -> V_40 ,
V_27 , V_30 , V_28 , V_29 ) ;
V_9 = F_1 ( V_2 , 0x10 , 5 , 0x15 , 0x40 , 0x00 , NULL ) ;
if ( V_9 )
goto V_16;
V_9 = F_6 ( V_2 -> V_15 , 0x14 , & V_11 ) ;
if ( V_9 )
goto V_16;
V_11 &= 0x7f ;
if ( V_11 < 64 ) {
V_9 = F_10 ( V_2 -> V_15 , 0x10 , 0x80 , 0x80 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x11 , 0x6f ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x10 , 5 , 0x15 , 0x40 , 0x00 , NULL ) ;
if ( V_9 )
goto V_16;
}
V_9 = F_6 ( V_2 -> V_15 , 0x14 , & V_11 ) ;
if ( V_9 )
goto V_16;
V_11 &= 0x1f ;
if ( V_11 > 19 ) {
V_9 = F_10 ( V_2 -> V_15 , 0x10 , 0x02 , 0x00 ) ;
if ( V_9 )
goto V_16;
}
V_9 = F_1 ( V_2 , 0x08 , 5 , 0x3c , 0xff , 0x00 , NULL ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x25 , 0x00 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x27 , 0x70 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x41 , 0x09 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x08 , 0x0b ) ;
if ( V_9 )
goto V_16;
V_31 = F_8 ( V_26 * 1694U , 1000000U ) ;
V_9 = F_4 ( V_2 -> V_15 , 0x04 , V_31 ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_33 ) ;
if ( V_9 )
goto V_16;
V_34 = V_33 & 0x3f ;
V_9 = F_4 ( V_2 -> V_15 , 0x41 , 0x0d ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_33 ) ;
if ( V_9 )
goto V_16;
V_33 &= 0x3f ;
V_34 = ( V_34 + V_33 ) / 2 ;
V_31 = V_31 * 207 / ( V_34 * 2 + 151 ) ;
V_37 = V_31 * 135 / 100 ;
V_38 = V_31 * 78 / 100 ;
V_37 = F_11 ( V_37 , 0U , 63U ) ;
V_25 = F_12 ( V_21 -> V_41 , 135 , 200 ) ;
V_25 += 2000000U + ( V_24 * 1000U ) ;
V_25 = F_13 ( V_25 , 7000000U , 40000000U ) ;
#define F_14 3200U
V_35 = F_8 ( V_25 * V_31 , F_14 * V_26 ) ;
V_35 = F_11 ( V_35 , 1U , 23U ) ;
V_36 = F_8 ( V_35 * F_14 * V_26 , V_25 ) ;
if ( V_36 < V_38 )
V_36 = F_8 ( ++ V_35 * F_14 * V_26 , V_25 ) ;
V_36 = F_11 ( V_36 , 0U , V_37 ) ;
V_9 = F_4 ( V_2 -> V_15 , 0x04 , V_36 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x06 , V_35 ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_33 ) ;
if ( V_9 )
goto V_16;
V_34 = V_33 & 0x3f ;
V_9 = F_4 ( V_2 -> V_15 , 0x41 , 0x09 ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x04 , 2 , 0x26 , 0xff , 0x00 , & V_33 ) ;
if ( V_9 )
goto V_16;
V_33 &= 0x3f ;
V_34 = ( V_34 + V_33 ) / 2 ;
V_33 = V_34 | 0x80 ;
V_9 = F_4 ( V_2 -> V_15 , 0x25 , V_33 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x27 , 0x30 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x08 , 0x09 ) ;
if ( V_9 )
goto V_16;
V_9 = F_1 ( V_2 , 0x01 , 20 , 0x21 , 0xff , 0x00 , NULL ) ;
if ( V_9 )
goto V_16;
V_16:
if ( V_9 )
F_2 ( & V_2 -> V_14 -> V_2 , L_4 , V_9 ) ;
return V_9 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_9 , V_10 ;
T_1 V_33 ;
static const struct V_12 V_13 [] = {
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
F_2 ( & V_2 -> V_14 -> V_2 , L_5 ) ;
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x01 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x03 ) ;
if ( V_9 )
goto V_16;
switch ( V_2 -> V_43 . V_44 ) {
case V_45 :
V_33 = 0x60 ;
break;
case V_46 :
V_33 = 0x70 ;
V_9 = F_4 ( V_2 -> V_15 , 0x05 , V_2 -> V_43 . V_47 ) ;
if ( V_9 )
goto V_16;
break;
case V_48 :
V_33 = 0x6c ;
break;
default:
goto V_16;
}
V_9 = F_4 ( V_2 -> V_15 , 0x42 , V_33 ) ;
if ( V_9 )
goto V_16;
if ( V_2 -> V_43 . V_49 )
V_33 = 0xec ;
else
V_33 = 0x6c ;
V_9 = F_4 ( V_2 -> V_15 , 0x62 , V_33 ) ;
if ( V_9 )
goto V_16;
for ( V_10 = 0 ; V_10 < F_3 ( V_13 ) ; V_10 ++ ) {
V_9 = F_4 ( V_2 -> V_15 , V_13 [ V_10 ] . V_5 , V_13 [ V_10 ] . V_7 ) ;
if ( V_9 )
goto V_16;
}
V_16:
if ( V_9 )
F_2 ( & V_2 -> V_14 -> V_2 , L_4 , V_9 ) ;
return V_9 ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_9 ;
F_2 ( & V_2 -> V_14 -> V_2 , L_5 ) ;
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x00 ) ;
if ( V_9 )
goto V_16;
V_16:
if ( V_9 )
F_2 ( & V_2 -> V_14 -> V_2 , L_4 , V_9 ) ;
return V_9 ;
}
static int F_17 ( struct V_17 * V_18 , T_3 * V_40 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_2 ( & V_2 -> V_14 -> V_2 , L_5 ) ;
* V_40 = V_2 -> V_23 ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , T_3 * V_40 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_2 ( & V_2 -> V_14 -> V_2 , L_5 ) ;
* V_40 = 0 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , T_2 * V_50 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_9 ;
T_2 V_51 , V_39 ;
unsigned int V_11 , V_52 , V_53 , V_54 ;
V_9 = F_6 ( V_2 -> V_15 , 0x3d , & V_11 ) ;
if ( V_9 )
goto V_16;
V_52 = ( V_11 >> 0 ) & 0x1f ;
V_52 = F_13 ( V_52 , 0U , 15U ) ;
V_9 = F_6 ( V_2 -> V_15 , 0x21 , & V_11 ) ;
if ( V_9 )
goto V_16;
V_53 = ( V_11 >> 0 ) & 0x1f ;
V_53 = F_13 ( V_53 , 2U , 16U ) ;
V_9 = F_6 ( V_2 -> V_15 , 0x66 , & V_11 ) ;
if ( V_9 )
goto V_16;
V_54 = ( V_11 >> 3 ) & 0x07 ;
V_54 = F_13 ( V_54 , 0U , 6U ) ;
V_51 = V_52 * 265 + V_53 * 338 + V_54 * 285 ;
V_39 = ( 0xffff - V_51 ) ;
V_39 = F_11 ( V_39 , 59000U , 61500U ) ;
* V_50 = ( V_39 - 59000 ) * 0xffff / ( 61500 - 59000 ) ;
V_16:
if ( V_9 )
F_2 ( & V_2 -> V_14 -> V_2 , L_4 , V_9 ) ;
return V_9 ;
}
static int F_20 ( struct V_55 * V_14 ,
const struct V_56 * V_57 )
{
struct V_58 * V_43 = V_14 -> V_2 . V_59 ;
struct V_17 * V_18 = V_43 -> V_18 ;
struct V_1 * V_2 ;
int V_9 ;
T_1 V_33 ;
unsigned int V_11 ;
static const struct V_60 V_60 = {
. V_61 = 8 ,
. V_62 = 8 ,
} ;
V_2 = F_21 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 ) {
V_9 = - V_64 ;
F_22 ( & V_14 -> V_2 , L_6 ) ;
goto V_16;
}
memcpy ( & V_2 -> V_43 , V_43 , sizeof( struct V_58 ) ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_15 = F_23 ( V_14 , & V_60 ) ;
if ( F_24 ( V_2 -> V_15 ) ) {
V_9 = F_25 ( V_2 -> V_15 ) ;
goto V_16;
}
V_9 = F_6 ( V_2 -> V_15 , 0x00 , & V_11 ) ;
if ( V_9 )
goto V_16;
if ( ( V_11 & 0x03 ) == 0x00 ) {
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x01 ) ;
if ( V_9 )
goto V_16;
F_5 ( 2000 , 50000 ) ;
}
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x03 ) ;
if ( V_9 )
goto V_16;
F_5 ( 2000 , 50000 ) ;
V_9 = F_6 ( V_2 -> V_15 , 0x00 , & V_11 ) ;
if ( V_9 )
goto V_16;
F_2 ( & V_2 -> V_14 -> V_2 , L_7 , V_11 ) ;
switch ( V_11 ) {
case 0xc3 :
case 0x83 :
break;
default:
goto V_16;
}
switch ( V_2 -> V_43 . V_44 ) {
case V_45 :
V_33 = 0x60 ;
break;
case V_46 :
V_33 = 0x70 ;
V_9 = F_4 ( V_2 -> V_15 , 0x05 , V_2 -> V_43 . V_47 ) ;
if ( V_9 )
goto V_16;
break;
case V_48 :
V_33 = 0x6c ;
break;
default:
goto V_16;
}
V_9 = F_4 ( V_2 -> V_15 , 0x42 , V_33 ) ;
if ( V_9 )
goto V_16;
if ( V_2 -> V_43 . V_49 )
V_33 = 0xec ;
else
V_33 = 0x6c ;
V_9 = F_4 ( V_2 -> V_15 , 0x62 , V_33 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_2 -> V_15 , 0x00 , 0x00 ) ;
if ( V_9 )
goto V_16;
F_26 ( & V_2 -> V_14 -> V_2 , L_8 ) ;
V_18 -> V_19 = V_2 ;
memcpy ( & V_18 -> V_65 . V_66 , & V_67 ,
sizeof( struct V_68 ) ) ;
F_27 ( V_14 , V_2 ) ;
return 0 ;
V_16:
F_2 ( & V_14 -> V_2 , L_4 , V_9 ) ;
F_28 ( V_2 ) ;
return V_9 ;
}
static int F_29 ( struct V_55 * V_14 )
{
struct V_1 * V_2 = F_30 ( V_14 ) ;
struct V_17 * V_18 = V_2 -> V_43 . V_18 ;
F_2 ( & V_14 -> V_2 , L_5 ) ;
memset ( & V_18 -> V_65 . V_66 , 0 , sizeof( struct V_68 ) ) ;
V_18 -> V_19 = NULL ;
F_28 ( V_2 ) ;
return 0 ;
}
