static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 , V_9 ;
static const struct V_10 V_11 [] = {
{ 0x1e , 0x6512 } ,
{ 0x25 , 0xb888 } ,
{ 0x39 , 0x5460 } ,
{ 0x3b , 0x00c0 } ,
{ 0x3a , 0xf000 } ,
{ 0x08 , 0x0000 } ,
{ 0x32 , 0x0030 } ,
{ 0x41 , 0x703a } ,
{ 0x40 , 0x1c78 } ,
{ 0x2c , 0x1c00 } ,
{ 0x36 , 0xc013 } ,
{ 0x37 , 0x6f18 } ,
{ 0x27 , 0x0008 } ,
{ 0x2a , 0x0001 } ,
{ 0x34 , 0x0a40 } ,
} ;
F_2 ( & V_7 -> V_4 , L_1 ) ;
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_15 , 0 ) ;
if ( V_8 )
goto V_16;
}
for ( V_9 = 0 ; V_9 < F_3 ( V_11 ) ; V_9 ++ ) {
V_8 = F_4 ( V_4 -> V_17 , V_11 [ V_9 ] . V_18 , V_11 [ V_9 ] . V_19 ) ;
if ( V_8 )
goto V_16;
}
return 0 ;
V_16:
F_2 ( & V_7 -> V_4 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 ;
F_2 ( & V_7 -> V_4 , L_1 ) ;
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_15 , 1 ) ;
if ( V_8 )
goto V_16;
}
return 0 ;
V_16:
F_2 ( & V_7 -> V_4 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_20 * V_21 = & V_2 -> V_22 ;
int V_8 , V_9 ;
T_1 V_19 ;
struct V_10 V_11 [ 2 ] ;
F_2 ( & V_7 -> V_4 ,
L_3 ,
V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_25 ) ;
switch ( V_21 -> V_23 ) {
case V_26 :
switch ( V_21 -> V_25 ) {
case 8000000 :
V_19 = 0x0000 ;
break;
case 7000000 :
V_19 = 0x1000 ;
break;
case 6000000 :
V_19 = 0x2000 ;
break;
case 5000000 :
V_19 = 0x3000 ;
break;
default:
V_8 = - V_27 ;
goto V_16;
}
break;
default:
V_8 = - V_27 ;
goto V_16;
}
V_11 [ 0 ] . V_18 = 0x04 ;
V_11 [ 0 ] . V_19 = V_19 ;
V_11 [ 1 ] . V_18 = 0x1f ;
V_11 [ 1 ] . V_19 = F_7 ( ( V_28 ) ( V_21 -> V_24 - 150000000 ) * 48 , 1000000 ) ;
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_29 , 0 ) ;
if ( V_8 )
goto V_16;
}
for ( V_9 = 0 ; V_9 < F_3 ( V_11 ) ; V_9 ++ ) {
V_8 = F_4 ( V_4 -> V_17 , V_11 [ V_9 ] . V_18 , V_11 [ V_9 ] . V_19 ) ;
if ( V_8 )
goto V_16;
}
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_29 , 1 ) ;
if ( V_8 )
goto V_16;
}
return 0 ;
V_16:
F_2 ( & V_7 -> V_4 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_7 -> V_4 , L_1 ) ;
* V_24 = 0 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 ,
const struct V_30 * V_31 )
{
struct V_3 * V_4 ;
struct V_32 * V_33 = V_7 -> V_4 . V_34 ;
struct V_1 * V_2 = V_33 -> V_1 ;
int V_8 ;
static const struct V_35 V_35 = {
. V_36 = 8 ,
. V_37 = 16 ,
} ;
V_4 = F_10 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
V_8 = - V_39 ;
goto V_16;
}
V_4 -> V_2 = V_33 -> V_1 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_17 = F_11 ( V_7 , & V_35 ) ;
if ( F_12 ( V_4 -> V_17 ) ) {
V_8 = F_13 ( V_4 -> V_17 ) ;
goto V_40;
}
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_41 , 1 ) ;
if ( V_8 )
goto V_40;
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_29 , 0 ) ;
if ( V_8 )
goto V_40;
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_15 , 1 ) ;
if ( V_8 )
goto V_40;
}
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_42 . V_43 , & V_44 ,
sizeof( struct V_45 ) ) ;
F_14 ( V_7 , V_4 ) ;
F_15 ( & V_7 -> V_4 , L_4 ) ;
return 0 ;
V_40:
F_16 ( V_4 ) ;
V_16:
F_2 ( & V_7 -> V_4 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_18 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_8 ;
F_2 ( & V_7 -> V_4 , L_1 ) ;
if ( V_2 -> V_12 ) {
V_8 = V_2 -> V_12 ( V_7 -> V_13 ,
V_14 ,
V_41 , 0 ) ;
if ( V_8 )
goto V_40;
}
F_16 ( V_4 ) ;
return 0 ;
V_40:
F_16 ( V_4 ) ;
F_2 ( & V_7 -> V_4 , L_2 , V_8 ) ;
return V_8 ;
}
