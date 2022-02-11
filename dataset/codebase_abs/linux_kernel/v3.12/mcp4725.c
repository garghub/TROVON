static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 (
F_4 ( V_2 ) ) ) ;
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = ( V_4 -> V_6 + 1 ) << 4 ;
V_5 [ 1 ] = 0 ;
V_4 -> V_7 = true ;
return F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 (
F_4 ( V_2 ) ) ) ;
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = ( V_4 -> V_9 >> 8 ) & 0xf ;
V_5 [ 1 ] = V_4 -> V_9 & 0xff ;
V_4 -> V_7 = false ;
return F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 , const char * V_12 , T_3 V_13 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_15 ) ;
int V_16 = 20 ;
T_1 V_17 [ 3 ] ;
bool V_18 ;
int V_19 ;
V_19 = F_9 ( V_12 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_18 )
return 0 ;
V_17 [ 0 ] = 0x60 ;
V_17 [ 1 ] = V_4 -> V_9 >> 4 ;
V_17 [ 2 ] = ( V_4 -> V_9 & 0xf ) << 4 ;
V_19 = F_5 ( V_4 -> V_8 , V_17 , 3 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 3 )
return - V_20 ;
while ( V_16 -- ) {
F_10 ( 20 ) ;
V_19 = F_11 ( V_4 -> V_8 , V_17 , 3 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 3 )
return - V_20 ;
if ( V_17 [ 0 ] & 0x80 )
break;
}
if ( V_16 < 0 ) {
F_12 ( & V_4 -> V_8 -> V_2 ,
L_1 ) ;
return - V_20 ;
}
return V_13 ;
}
static int F_13 ( struct V_14 * V_15 ,
const struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
return V_4 -> V_6 ;
}
static int F_14 ( struct V_14 * V_15 ,
const struct V_21 * V_22 , unsigned V_23 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
V_4 -> V_6 = V_23 ;
return 0 ;
}
static T_2 F_15 ( struct V_14 * V_15 ,
T_4 V_24 , const struct V_21 * V_22 , char * V_12 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
return sprintf ( V_12 , L_2 , V_4 -> V_7 ) ;
}
static T_2 F_16 ( struct V_14 * V_15 ,
T_4 V_24 , const struct V_21 * V_22 ,
const char * V_12 , T_3 V_13 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
bool V_18 ;
int V_19 ;
V_19 = F_9 ( V_12 , & V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_18 )
V_19 = F_1 ( & V_4 -> V_8 -> V_2 ) ;
else
V_19 = F_6 ( & V_4 -> V_8 -> V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_13 ;
}
static int F_17 ( struct V_14 * V_15 , int V_25 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
T_1 V_5 [ 2 ] ;
int V_19 ;
if ( V_25 >= ( 1 << 12 ) || V_25 < 0 )
return - V_26 ;
V_5 [ 0 ] = ( V_25 >> 8 ) & 0xf ;
V_5 [ 1 ] = V_25 & 0xff ;
V_19 = F_5 ( V_4 -> V_8 , V_5 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 2 )
return - V_20 ;
else
return 0 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_21 const * V_22 ,
int * V_25 , int * V_27 , long V_28 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
unsigned long V_29 ;
switch ( V_28 ) {
case V_30 :
* V_25 = V_4 -> V_9 ;
return V_31 ;
case V_32 :
V_29 = ( V_4 -> V_33 * 1000 ) >> 12 ;
* V_25 = V_29 / 1000000 ;
* V_27 = V_29 % 1000000 ;
return V_34 ;
}
return - V_26 ;
}
static int F_19 ( struct V_14 * V_15 ,
struct V_21 const * V_22 ,
int V_25 , int V_27 , long V_28 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
int V_19 ;
switch ( V_28 ) {
case V_30 :
V_19 = F_17 ( V_15 , V_25 ) ;
V_4 -> V_9 = V_25 ;
break;
default:
V_19 = - V_26 ;
break;
}
return V_19 ;
}
static int F_20 ( struct V_35 * V_8 ,
const struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_38 * V_39 = V_8 -> V_2 . V_39 ;
T_1 V_40 [ 3 ] ;
T_1 V_41 ;
int V_42 ;
if ( ! V_39 || ! V_39 -> V_33 ) {
F_12 ( & V_8 -> V_2 , L_3 ) ;
return - V_26 ;
}
V_15 = F_21 ( & V_8 -> V_2 , sizeof( * V_4 ) ) ;
if ( V_15 == NULL )
return - V_43 ;
V_4 = F_2 ( V_15 ) ;
F_22 ( V_8 , V_15 ) ;
V_4 -> V_8 = V_8 ;
V_15 -> V_2 . V_44 = & V_8 -> V_2 ;
V_15 -> V_45 = & V_46 ;
V_15 -> V_47 = & V_48 ;
V_15 -> V_49 = 1 ;
V_15 -> V_50 = V_51 ;
V_4 -> V_33 = V_39 -> V_33 ;
V_42 = F_11 ( V_8 , V_40 , 3 ) ;
if ( V_42 < 0 ) {
F_12 ( & V_8 -> V_2 , L_4 ) ;
return V_42 ;
}
V_41 = ( V_40 [ 0 ] >> 1 ) & 0x3 ;
V_4 -> V_7 = V_41 > 0 ? true : false ;
V_4 -> V_6 = V_41 ? V_41 - 1 : 2 ;
V_4 -> V_9 = ( V_40 [ 1 ] << 4 ) | ( V_40 [ 2 ] >> 4 ) ;
V_42 = F_23 ( V_15 ) ;
if ( V_42 )
return V_42 ;
F_24 ( & V_8 -> V_2 , L_5 ) ;
return 0 ;
}
static int F_25 ( struct V_35 * V_8 )
{
F_26 ( F_3 ( V_8 ) ) ;
return 0 ;
}
