static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 , V_3 , V_4 ) )
F_4 ( 1 , V_7 , V_2 , L_1 ,
V_4 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
int V_10 ;
if ( V_9 -> V_11 )
return - V_12 ;
switch ( V_9 -> V_13 ) {
case V_14 :
V_10 = V_15 ;
break;
case V_16 :
V_10 = V_17 ;
break;
case V_18 :
V_10 = V_19 ;
break;
case V_20 :
V_10 = V_21 ;
break;
default:
V_10 = V_22 ;
break;
}
F_4 ( 1 , V_7 , V_2 , L_2 , V_10 ) ;
F_1 ( V_2 , SWITCH , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 ;
V_9 -> V_23 = V_24 ;
if ( 1 != F_7 ( V_6 , & V_10 , 1 ) ) {
F_4 ( 1 , V_7 , V_2 ,
L_3 ) ;
return - V_25 ;
}
if ( V_10 & 0x80 ) {
F_4 ( 1 , V_7 , V_2 ,
L_4 ) ;
return - V_12 ;
}
F_4 ( 1 , V_7 , V_2 , L_5 , V_10 ) ;
switch ( V_10 & 0x60 ) {
case 0x00 :
V_9 -> V_23 = V_24 ;
break;
case 0x20 :
V_9 -> V_23 = V_26 | V_27 ;
break;
case 0x40 :
V_9 -> V_23 = V_28 | V_24 ;
break;
default:
V_9 -> V_23 = V_29 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_9 ( V_6 , V_31 , V_32 , 0 ) ;
}
static int F_10 ( struct V_5 * V_6 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 ;
if ( ! F_11 ( V_6 -> V_35 ,
V_36 |
V_37 ) )
return - V_25 ;
F_12 ( V_6 , L_6 ,
V_6 -> V_38 << 1 , V_6 -> V_35 -> V_39 ) ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_40 ) ;
if ( V_2 == NULL )
return - V_41 ;
F_14 ( V_2 , V_6 , & V_42 ) ;
F_1 ( V_2 , V_43 , 0 ) ;
F_1 ( V_2 , V_44 , 0 ) ;
F_1 ( V_2 , SWITCH , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static T_2 int F_19 ( void )
{
return F_20 ( & V_45 ) ;
}
static T_3 void F_21 ( void )
{
F_22 ( & V_45 ) ;
}
