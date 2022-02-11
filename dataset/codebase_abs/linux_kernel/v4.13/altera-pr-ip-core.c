static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
const char * V_6 = L_1 ;
enum V_1 V_7 = V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_5 -> V_10 + V_11 ) ;
V_9 &= V_12 ;
switch ( V_9 ) {
case V_13 :
return V_14 ;
case V_15 :
V_6 = L_2 ;
V_7 = V_16 ;
break;
case V_17 :
V_6 = L_3 ;
V_7 = V_16 ;
break;
case V_18 :
V_6 = L_4 ;
V_7 = V_16 ;
break;
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
default:
break;
}
F_3 ( & V_3 -> V_23 , L_5 ,
V_9 , V_6 , V_24 ) ;
return V_7 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
const char * V_27 , T_2 V_28 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 V_9 ;
if ( ! ( V_26 -> V_29 & V_30 ) ) {
F_3 ( & V_3 -> V_23 , L_6 ,
V_24 ) ;
return - V_31 ;
}
V_9 = F_2 ( V_5 -> V_10 + V_11 ) ;
if ( V_9 & V_32 ) {
F_3 ( & V_3 -> V_23 ,
L_7 ,
V_24 ) ;
return - V_31 ;
}
F_5 ( V_9 | V_32 , V_5 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , const char * V_27 ,
T_2 V_28 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 * V_33 = ( T_1 * ) V_27 ;
T_2 V_34 = 0 ;
if ( V_28 <= 0 )
return - V_31 ;
while ( V_28 >= sizeof( T_1 ) ) {
F_5 ( V_33 [ V_34 ++ ] , V_5 -> V_10 ) ;
V_28 -= sizeof( T_1 ) ;
}
switch ( V_28 ) {
case 3 :
F_5 ( V_33 [ V_34 ++ ] & 0x00ffffff , V_5 -> V_10 ) ;
break;
case 2 :
F_5 ( V_33 [ V_34 ++ ] & 0x0000ffff , V_5 -> V_10 ) ;
break;
case 1 :
F_5 ( V_33 [ V_34 ++ ] & 0x000000ff , V_5 -> V_10 ) ;
break;
case 0 :
break;
default:
return - V_35 ;
}
if ( F_1 ( V_3 ) == V_16 )
return - V_36 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
T_1 V_34 = 0 ;
do {
switch ( F_1 ( V_3 ) ) {
case V_16 :
return - V_36 ;
case V_22 :
F_8 ( & V_3 -> V_23 ,
L_8 ) ;
return 0 ;
default:
break;
}
F_9 ( 1 ) ;
} while ( V_26 -> V_37 > V_34 ++ );
F_3 ( & V_3 -> V_23 , L_9 ) ;
return - V_38 ;
}
int F_10 ( struct V_39 * V_23 , void T_3 * V_10 )
{
struct V_4 * V_5 ;
T_1 V_9 ;
V_5 = F_11 ( V_23 , sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_5 -> V_10 = V_10 ;
V_9 = F_2 ( V_5 -> V_10 + V_11 ) ;
F_12 ( V_23 , L_10 , V_24 ,
( V_9 & V_12 ) >> V_42 ,
( int ) ( V_9 & V_32 ) ) ;
return F_13 ( V_23 , F_14 ( V_23 ) , & V_43 , V_5 ) ;
}
int F_15 ( struct V_39 * V_23 )
{
F_12 ( V_23 , L_11 , V_24 ) ;
F_16 ( V_23 ) ;
return 0 ;
}
