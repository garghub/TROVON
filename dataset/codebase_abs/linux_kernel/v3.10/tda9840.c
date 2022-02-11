static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 , V_3 , V_4 ) )
F_4 ( 1 , V_7 , V_2 , L_1 ,
V_4 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_8 ;
if ( 1 != F_6 ( V_6 , & V_8 , 1 ) ) {
F_4 ( 1 , V_7 , V_2 ,
L_2 ) ;
return - V_9 ;
}
if ( V_8 & 0x80 ) {
F_4 ( 1 , V_7 , V_2 ,
L_3 ) ;
return - V_10 ;
}
F_4 ( 1 , V_7 , V_2 , L_4 , V_8 ) ;
return V_8 & 0x60 ;
}
static int F_7 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
int V_13 = F_5 ( V_2 ) ;
int V_8 ;
if ( V_12 -> V_14 )
return - V_10 ;
V_13 = V_13 < 0 ? 0 : V_13 ;
if ( V_13 == 0 || V_13 == 0x60 )
V_8 = V_15 ;
else if ( V_13 == 0x40 )
V_8 = ( V_12 -> V_16 == V_17 ) ?
V_15 : V_18 ;
else {
switch ( V_12 -> V_16 ) {
case V_19 :
V_8 = V_20 ;
break;
case V_21 :
V_8 = V_22 ;
break;
default:
V_8 = V_23 ;
break;
}
}
F_4 ( 1 , V_7 , V_2 , L_5 , V_8 ) ;
F_1 ( V_2 , SWITCH , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_13 = F_5 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 -> V_24 = V_25 ;
switch ( V_13 & 0x60 ) {
case 0x00 :
V_12 -> V_24 = V_25 ;
break;
case 0x20 :
V_12 -> V_24 = V_26 | V_27 ;
break;
case 0x40 :
V_12 -> V_24 = V_28 | V_25 ;
break;
default:
V_12 -> V_24 = V_17 ;
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_10 ( V_6 , V_30 , V_31 , 0 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 ;
if ( ! F_12 ( V_6 -> V_34 ,
V_35 |
V_36 ) )
return - V_9 ;
F_13 ( V_6 , L_6 ,
V_6 -> V_37 << 1 , V_6 -> V_34 -> V_38 ) ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_39 ) ;
if ( V_2 == NULL )
return - V_40 ;
F_15 ( V_2 , V_6 , & V_41 ) ;
F_1 ( V_2 , V_42 , 0 ) ;
F_1 ( V_2 , V_43 , 0 ) ;
F_1 ( V_2 , SWITCH , V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_17 ( V_6 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
