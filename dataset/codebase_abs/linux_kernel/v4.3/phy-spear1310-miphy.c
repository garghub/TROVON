static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_7 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
V_3 = F_3 ( 0 ) ;
break;
case 1 :
V_3 = F_3 ( 1 ) ;
break;
case 2 :
V_3 = F_3 ( 2 ) ;
break;
default:
return - V_9 ;
}
F_2 ( V_2 -> V_4 , V_10 ,
F_4 ( V_2 -> V_8 ) , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_4 , V_10 ,
F_4 ( V_2 -> V_8 ) , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_12 = F_1 ( V_2 ) ;
return V_12 ;
}
static int F_8 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_12 = F_5 ( V_2 ) ;
return V_12 ;
}
static struct V_11 * F_9 ( struct V_15 * V_16 ,
struct V_17 * args )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( args -> V_18 < 1 ) {
F_11 ( V_16 , L_1 ) ;
return F_12 ( - V_19 ) ;
}
V_2 -> V_13 = args -> args [ 0 ] ;
if ( V_2 -> V_13 != V_20 && V_2 -> V_13 != V_14 ) {
F_11 ( V_16 , L_2 ) ;
return F_12 ( - V_19 ) ;
}
return V_2 -> V_11 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_15 * V_16 = & V_22 -> V_16 ;
struct V_1 * V_2 ;
struct V_23 * V_23 ;
V_2 = F_14 ( V_16 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_2 -> V_4 =
F_15 ( V_16 -> V_26 , L_3 ) ;
if ( F_16 ( V_2 -> V_4 ) ) {
F_11 ( V_16 , L_4 ) ;
return F_17 ( V_2 -> V_4 ) ;
}
if ( F_18 ( V_16 -> V_26 , L_5 , & V_2 -> V_8 ) ) {
F_11 ( V_16 , L_6 ) ;
return - V_9 ;
}
V_2 -> V_11 = F_19 ( V_16 , NULL , & V_27 ) ;
if ( F_16 ( V_2 -> V_11 ) ) {
F_11 ( V_16 , L_7 ) ;
return F_17 ( V_2 -> V_11 ) ;
}
F_20 ( V_16 , V_2 ) ;
F_21 ( V_2 -> V_11 , V_2 ) ;
V_23 =
F_22 ( V_16 , F_9 ) ;
if ( F_16 ( V_23 ) ) {
F_11 ( V_16 , L_8 ) ;
return F_17 ( V_23 ) ;
}
return 0 ;
}
