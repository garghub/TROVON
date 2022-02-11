static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ( V_3 == V_4 ) ||
( V_3 == V_5 ) ||
( V_3 > V_6 ) )
return true ;
return false ;
}
static int F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
unsigned int V_15 ;
switch ( F_3 ( V_10 ) ) {
case 96000 :
V_15 = 1 << 5 ;
break;
case 32000 :
V_15 = 1 << 4 ;
break;
case 48000 :
V_15 = 1 << 3 ;
break;
case 44100 :
V_15 = 1 << 2 ;
break;
case 16000 :
V_15 = 1 << 1 ;
break;
case 8000 :
V_15 = 1 << 0 ;
break;
default:
F_4 ( V_14 -> V_2 , L_1 ) ;
return - V_16 ;
}
F_5 ( V_14 , V_17 , 0x03F , V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
int V_18 , unsigned int V_19 , int V_20 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
unsigned int V_15 ;
F_5 ( V_14 , V_21 ,
V_22 , 0 ) ;
switch ( V_19 ) {
case 26000000 :
V_15 = 1 << 7 ;
break;
case 19200000 :
V_15 = 1 << 6 ;
break;
case 13000000 :
V_15 = 1 << 5 ;
break;
case 12288000 :
V_15 = 1 << 4 ;
break;
case 12000000 :
V_15 = 1 << 3 ;
break;
case 11289600 :
V_15 = 1 << 2 ;
break;
default:
F_4 ( V_14 -> V_2 , L_2 ) ;
return - V_16 ;
}
F_5 ( V_14 , V_23 , 0xFD , V_15 ) ;
F_5 ( V_14 , V_21 ,
V_22 , V_22 ) ;
F_7 ( V_12 -> V_2 , L_3 , V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
unsigned int V_24 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
int V_25 ;
T_1 V_15 ;
switch ( V_24 & V_26 ) {
case V_27 :
V_25 = 1 ;
break;
case V_28 :
V_25 = 0 ;
break;
default:
F_4 ( V_14 -> V_2 , L_4 ) ;
return - V_16 ;
}
switch ( V_24 & V_26 ) {
case V_29 :
V_15 = ( V_25 ) ? V_30 : V_31 ;
break;
case V_32 :
V_15 = ( V_25 ) ? V_33 : V_34 ;
break;
case V_35 :
V_15 = ( V_25 ) ? V_36 : V_37 ;
break;
default:
F_4 ( V_14 -> V_2 , L_5 ) ;
return - V_16 ;
}
F_5 ( V_14 , V_38 ,
V_39 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_40 * V_41 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_42 ;
V_14 -> V_43 = V_41 -> V_44 ;
V_42 = F_11 ( V_14 , 8 , 8 , V_45 ) ;
if ( V_42 < 0 ) {
F_4 ( V_2 , L_6 , V_42 ) ;
return V_42 ;
}
F_5 ( V_14 , V_21 ,
V_22 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_13 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 = & V_47 -> V_2 ;
unsigned int V_15 ;
int V_42 ;
V_41 = F_14 ( V_2 , sizeof( struct V_40 ) ,
V_50 ) ;
if ( ! V_41 )
return - V_51 ;
V_41 -> V_44 = F_15 ( V_47 , & V_52 ) ;
if ( F_16 ( V_41 -> V_44 ) ) {
V_42 = F_17 ( V_41 -> V_44 ) ;
F_4 ( V_2 , L_7 , V_42 ) ;
return V_42 ;
}
F_18 ( V_47 , V_41 ) ;
V_42 = F_19 ( V_41 -> V_44 , V_53 , & V_15 ) ;
if ( V_42 < 0 ) {
F_4 ( V_2 , L_8 , V_42 ) ;
return V_42 ;
}
F_20 ( V_2 , L_9 , V_15 ) ;
V_42 = F_21 ( V_2 ,
& V_54 ,
& V_55 , 1 ) ;
return V_42 ;
}
static int F_22 ( struct V_46 * V_56 )
{
F_23 ( & V_56 -> V_2 ) ;
return 0 ;
}
