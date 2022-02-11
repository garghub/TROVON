static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case V_5 :
case V_6 :
return 0 ;
default:
V_4 = F_2 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
switch ( V_3 ) {
case V_8 :
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
V_4 &= ~ V_9 ;
break;
default:
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static int T_3 F_5 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_4 ;
V_15 = F_6 ( & V_11 -> V_16 , sizeof( struct V_14 ) ,
V_17 ) ;
if ( ! V_15 ) {
F_7 ( & V_11 -> V_16 , L_1 ) ;
return - V_18 ;
}
V_15 -> V_19 = F_8 ( & V_11 -> V_16 , NULL ) ;
if ( ! F_9 ( V_15 -> V_19 ) )
F_10 ( V_15 -> V_19 ) ;
V_4 = F_11 ( V_11 , & V_20 ) ;
if ( V_4 )
goto V_21;
V_2 = F_12 ( V_11 ) ;
V_13 = F_13 ( V_2 ) ;
V_13 -> V_15 = V_15 ;
return 0 ;
V_21:
if ( ! F_9 ( V_15 -> V_19 ) ) {
F_14 ( V_15 -> V_19 ) ;
F_15 ( V_15 -> V_19 ) ;
}
return V_4 ;
}
static int T_4 F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_12 * V_13 = F_13 ( V_2 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_17 ( V_11 ) ;
if ( ! F_9 ( V_15 -> V_19 ) ) {
F_14 ( V_15 -> V_19 ) ;
F_15 ( V_15 -> V_19 ) ;
}
return 0 ;
}
