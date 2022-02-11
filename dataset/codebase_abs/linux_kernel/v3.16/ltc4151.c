static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
F_3 ( & V_4 -> V_8 ) ;
if ( F_4 ( V_9 , V_4 -> V_10 + V_11 / 6 ) || ! V_4 -> V_12 ) {
int V_13 ;
F_5 ( & V_6 -> V_3 , L_1 ) ;
for ( V_13 = 0 ; V_13 < F_6 ( V_4 -> V_14 ) ; V_13 ++ ) {
int V_15 ;
V_15 = F_7 ( V_6 , V_13 ) ;
if ( F_8 ( V_15 < 0 ) ) {
F_5 ( V_3 ,
L_2 ,
V_15 ) ;
V_7 = F_9 ( V_15 ) ;
goto abort;
}
V_4 -> V_14 [ V_13 ] = V_15 ;
}
V_4 -> V_10 = V_9 ;
V_4 -> V_12 = 1 ;
}
abort:
F_10 ( & V_4 -> V_8 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_4 , T_1 V_16 )
{
T_2 V_15 ;
V_15 = ( V_4 -> V_14 [ V_16 ] << 4 ) + ( V_4 -> V_14 [ V_16 + 1 ] >> 4 ) ;
switch ( V_16 ) {
case V_17 :
V_15 = V_15 * 500 / 1000 ;
break;
case V_18 :
V_15 = V_15 * 20 ;
break;
case V_19 :
V_15 = V_15 * 25 ;
break;
default:
F_12 ( 1 ) ;
V_15 = 0 ;
break;
}
return V_15 ;
}
static T_3 F_13 ( struct V_2 * V_3 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 = F_14 ( V_21 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_25 ;
if ( F_15 ( V_4 ) )
return F_16 ( V_4 ) ;
V_25 = F_11 ( V_4 , V_24 -> V_26 ) ;
return snprintf ( V_22 , V_27 , L_3 , V_25 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
const struct V_28 * V_29 )
{
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_32 ;
if ( ! F_18 ( V_31 , V_33 ) )
return - V_34 ;
V_4 = F_19 ( V_3 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_6 = V_6 ;
F_20 ( & V_4 -> V_8 ) ;
V_32 = F_21 ( V_3 , V_6 -> V_37 ,
V_4 ,
V_38 ) ;
return F_22 ( V_32 ) ;
}
