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
return NULL ;
}
V_2 -> V_13 = args -> args [ 0 ] ;
if ( V_2 -> V_13 != V_19 && V_2 -> V_13 != V_14 ) {
F_11 ( V_16 , L_2 ) ;
return NULL ;
}
return V_2 -> V_11 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = & V_21 -> V_16 ;
struct V_1 * V_2 ;
struct V_22 * V_22 ;
V_2 = F_13 ( V_16 , sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 ) {
F_11 ( V_16 , L_3 ) ;
return - V_24 ;
}
V_2 -> V_4 =
F_14 ( V_16 -> V_25 , L_4 ) ;
if ( F_15 ( V_2 -> V_4 ) ) {
F_11 ( V_16 , L_5 ) ;
return F_16 ( V_2 -> V_4 ) ;
}
if ( F_17 ( V_16 -> V_25 , L_6 , & V_2 -> V_8 ) ) {
F_11 ( V_16 , L_7 ) ;
return - V_9 ;
}
V_2 -> V_11 = F_18 ( V_16 , NULL , & V_26 , NULL ) ;
if ( F_15 ( V_2 -> V_11 ) ) {
F_11 ( V_16 , L_8 ) ;
return F_16 ( V_2 -> V_11 ) ;
}
F_19 ( V_16 , V_2 ) ;
F_20 ( V_2 -> V_11 , V_2 ) ;
V_22 =
F_21 ( V_16 , F_9 ) ;
if ( F_15 ( V_22 ) ) {
F_11 ( V_16 , L_9 ) ;
return F_16 ( V_22 ) ;
}
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_27 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_27 ) ;
}
