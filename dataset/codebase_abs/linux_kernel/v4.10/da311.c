static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 ;
T_2 V_7 = 0 ;
if ( V_3 & 0xff00 ) {
V_6 = F_2 ( V_2 , V_8 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_4 != 0xff ) {
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_7 = V_6 ;
}
V_7 &= ~ V_4 ;
V_7 |= V_5 & V_4 ;
V_6 = F_2 ( V_2 , V_3 & 0xff , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_3 & 0xff00 ) {
V_6 = F_2 ( V_2 , V_8 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
const struct {
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
} V_9 [] = {
{ V_10 , 0xff , 0x08 } ,
{ V_11 , 0xff , 0x80 } ,
{ V_12 , 0x30 , 0x00 } ,
{ V_13 , 0xff , 0x6f } ,
{ V_10 , 0xff , 0x88 } ,
{ V_14 , 0xff , 0x02 } ,
{ V_15 , 0xff , 0x27 } ,
{ V_16 , 0xff , 0x30 } ,
{ V_17 , 0xff , 0x3f } ,
{ V_18 , 0xff , 0xff } ,
{ V_19 , 0xff , 0x0f } ,
} ;
int V_20 , V_6 ;
V_6 = F_1 ( V_2 , V_21 ,
0xff , 0xaa ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_20 = 0 ; V_20 < F_5 ( V_9 ) ; V_20 ++ ) {
V_6 = F_1 ( V_2 ,
V_9 [ V_20 ] . V_3 ,
V_9 [ V_20 ] . V_4 ,
V_9 [ V_20 ] . V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_22 )
{
T_2 V_5 = V_22 ? 0x00 : 0x20 ;
return F_1 ( V_2 , V_10 ,
0x20 , V_5 ) ;
}
static int F_7 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_27 , int * V_28 , long V_4 )
{
struct V_29 * V_5 = F_8 ( V_24 ) ;
int V_6 ;
switch ( V_4 ) {
case V_30 :
V_6 = F_9 ( V_5 -> V_2 , V_26 -> V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_27 = ( short ) V_6 >> 4 ;
return V_32 ;
case V_33 :
* V_27 = 0 ;
* V_28 = V_34 ;
return V_35 ;
default:
return - V_36 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
int V_6 ;
struct V_23 * V_24 ;
struct V_29 * V_5 ;
V_6 = F_3 ( V_2 , V_39 ) ;
if ( V_6 != V_40 )
return ( V_6 < 0 ) ? V_6 : - V_41 ;
V_24 = F_11 ( & V_2 -> V_42 , sizeof( * V_5 ) ) ;
if ( ! V_24 )
return - V_43 ;
V_5 = F_8 ( V_24 ) ;
V_5 -> V_2 = V_2 ;
F_12 ( V_2 , V_24 ) ;
V_24 -> V_42 . V_44 = & V_2 -> V_42 ;
V_24 -> V_45 = & V_46 ;
V_24 -> V_47 = L_1 ;
V_24 -> V_48 = V_49 ;
V_24 -> V_50 = V_51 ;
V_24 -> V_52 = F_5 ( V_51 ) ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_2 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_13 ( V_24 ) ;
if ( V_6 < 0 ) {
F_14 ( & V_2 -> V_42 , L_2 ) ;
F_6 ( V_2 , false ) ;
}
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 ) ;
F_17 ( V_24 ) ;
return F_6 ( V_2 , false ) ;
}
static int F_18 ( struct V_53 * V_42 )
{
return F_6 ( F_19 ( V_42 ) , false ) ;
}
static int F_20 ( struct V_53 * V_42 )
{
return F_6 ( F_19 ( V_42 ) , true ) ;
}
