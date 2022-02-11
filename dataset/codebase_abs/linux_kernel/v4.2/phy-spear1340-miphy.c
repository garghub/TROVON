static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 ,
V_6 ) ;
F_2 ( V_2 -> V_3 , V_7 ,
V_8 ,
V_9 ) ;
F_2 ( V_2 -> V_3 , V_10 ,
V_11 ,
V_11 ) ;
F_3 ( 20 ) ;
F_2 ( V_2 -> V_3 , V_12 ,
V_13 , 0 ) ;
F_3 ( 20 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 , 0 ) ;
F_2 ( V_2 -> V_3 , V_7 ,
V_8 , 0 ) ;
F_2 ( V_2 -> V_3 , V_12 ,
V_13 ,
V_13 ) ;
F_3 ( 20 ) ;
F_2 ( V_2 -> V_3 , V_10 ,
V_11 , 0 ) ;
F_3 ( 20 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_7 ,
V_8 ,
V_14 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_5 ,
V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_7 ,
V_8 , 0 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_5 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_17 = 0 ;
if ( V_2 -> V_18 == V_19 )
V_17 = F_1 ( V_2 ) ;
else if ( V_2 -> V_18 == V_20 )
V_17 = F_5 ( V_2 ) ;
return V_17 ;
}
static int F_9 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_17 = 0 ;
if ( V_2 -> V_18 == V_19 )
V_17 = F_4 ( V_2 ) ;
else if ( V_2 -> V_18 == V_20 )
V_17 = F_6 ( V_2 ) ;
return V_17 ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
int V_17 = 0 ;
if ( V_2 -> V_18 == V_19 )
V_17 = F_4 ( V_2 ) ;
return V_17 ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
int V_17 = 0 ;
if ( V_2 -> V_18 == V_19 )
V_17 = F_1 ( V_2 ) ;
return V_17 ;
}
static struct V_16 * F_13 ( struct V_21 * V_22 ,
struct V_23 * args )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
if ( args -> V_24 < 1 ) {
F_14 ( V_22 , L_1 ) ;
return F_15 ( - V_25 ) ;
}
V_2 -> V_18 = args -> args [ 0 ] ;
if ( V_2 -> V_18 != V_19 && V_2 -> V_18 != V_20 ) {
F_14 ( V_22 , L_2 ) ;
return F_15 ( - V_25 ) ;
}
return V_2 -> V_16 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_21 * V_22 = & V_27 -> V_22 ;
struct V_1 * V_2 ;
struct V_28 * V_28 ;
V_2 = F_17 ( V_22 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_2 -> V_3 =
F_18 ( V_22 -> V_31 , L_3 ) ;
if ( F_19 ( V_2 -> V_3 ) ) {
F_14 ( V_22 , L_4 ) ;
return F_20 ( V_2 -> V_3 ) ;
}
V_2 -> V_16 = F_21 ( V_22 , NULL , & V_32 ) ;
if ( F_19 ( V_2 -> V_16 ) ) {
F_14 ( V_22 , L_5 ) ;
return F_20 ( V_2 -> V_16 ) ;
}
F_22 ( V_22 , V_2 ) ;
F_23 ( V_2 -> V_16 , V_2 ) ;
V_28 =
F_24 ( V_22 , F_13 ) ;
if ( F_19 ( V_28 ) ) {
F_14 ( V_22 , L_6 ) ;
return F_20 ( V_28 ) ;
}
return 0 ;
}
