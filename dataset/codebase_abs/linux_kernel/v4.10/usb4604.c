static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ) ;
if ( V_3 )
F_3 ( 250 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
int V_9 ;
T_1 V_10 [] = { 0xaa , 0x55 , 0x00 } ;
F_1 ( V_2 , 1 ) ;
V_9 = F_6 ( V_8 , V_10 , F_7 ( V_10 ) ) ;
if ( V_9 < 0 ) {
F_1 ( V_2 , 0 ) ;
return V_9 ;
}
V_2 -> V_11 = V_12 ;
F_8 ( V_6 , L_1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , enum V_13 V_11 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_9 = 0 ;
switch ( V_11 ) {
case V_12 :
V_9 = F_4 ( V_2 ) ;
break;
case V_14 :
F_1 ( V_2 , 0 ) ;
F_8 ( V_6 , L_2 ) ;
break;
default:
F_10 ( V_6 , L_3 ) ;
V_9 = - V_15 ;
break;
}
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = V_6 -> V_18 ;
struct V_19 * V_20 ;
T_2 V_11 = V_12 ;
V_20 = F_12 ( V_6 , L_4 , V_21 ) ;
if ( F_13 ( V_20 ) )
return F_14 ( V_20 ) ;
V_2 -> V_4 = V_20 ;
if ( F_15 ( V_17 , L_5 , & V_2 -> V_11 ) )
V_2 -> V_11 = V_11 ;
return F_9 ( V_2 , V_2 -> V_11 ) ;
}
static int F_16 ( struct V_7 * V_22 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( & V_22 -> V_6 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
F_18 ( V_22 , V_2 ) ;
V_2 -> V_6 = & V_22 -> V_6 ;
return F_11 ( V_2 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_1 * V_2 = F_20 ( V_8 ) ;
F_9 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_1 * V_2 = F_20 ( V_8 ) ;
F_9 ( V_2 , V_2 -> V_11 ) ;
return 0 ;
}
