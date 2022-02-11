static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
F_2 ( V_2 -> V_6 , V_3 , V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
F_4 ( V_2 -> V_6 , V_3 , V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
}
static void F_6 ( void * V_7 )
{
struct V_8 * V_9 = V_7 ;
F_7 ( V_9 -> V_10 , V_9 -> V_11 ,
V_9 -> V_4 , V_9 -> V_5 ) ;
F_8 ( V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
void * V_7 ,
T_2 V_4 ,
int V_5 ,
T_1 * V_12
)
{
T_1 V_13 ;
struct V_8 * V_14 ;
int V_15 ;
V_14 = F_10 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return - V_17 ;
V_13 = F_11 ( V_2 -> V_6 , V_7 , V_4 , V_5 ) ;
if ( F_12 ( V_2 -> V_6 , V_13 ) ) {
F_8 ( V_14 ) ;
return - V_18 ;
}
V_14 -> V_10 = V_2 -> V_6 ;
V_14 -> V_11 = V_13 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_5 = V_5 ;
* V_12 = V_13 ;
V_15 = F_13 ( V_2 -> V_6 , F_6 , V_14 ) ;
if ( V_15 ) {
F_7 ( V_2 -> V_6 , V_13 , V_4 , V_5 ) ;
F_8 ( V_14 ) ;
}
return V_15 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_10 * V_6 = & V_20 -> V_6 ;
struct V_1 * V_21 ;
int V_15 = 0 ;
int V_22 ;
struct V_23 V_24 ;
struct V_25 * V_26 = & V_27 ;
if ( F_15 ( V_6 -> V_28 , L_1 ) )
V_26 = & V_29 ;
V_21 = F_16 ( NULL , V_6 , V_26 ) ;
if ( ! V_21 )
return - V_17 ;
F_17 ( V_6 , V_21 ) ;
V_15 = F_18 ( V_6 -> V_28 , 0 , & V_24 ) ;
V_21 -> V_30 = F_19 ( V_6 , & V_24 ) ;
if ( F_20 ( V_21 -> V_30 ) )
return F_21 ( V_21 -> V_30 ) ;
V_22 = F_22 ( V_6 -> V_28 , 0 ) ;
V_15 = F_23 ( V_6 , V_22 , V_31 , 0 , V_32 , V_21 ) ;
if ( V_15 ) {
F_24 ( V_21 -> V_6 ,
L_2 ) ;
return - V_18 ;
}
return F_25 ( V_21 ) ;
}
static int F_26 ( struct V_19 * V_20 )
{
struct V_10 * V_6 = & V_20 -> V_6 ;
struct V_1 * V_21 = F_27 ( V_6 ) ;
F_28 ( V_21 ) ;
return 0 ;
}
