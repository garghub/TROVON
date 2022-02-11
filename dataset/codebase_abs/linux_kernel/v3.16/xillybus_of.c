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
static T_1 F_6 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
void * V_9 ,
T_2 V_4 ,
int V_5
)
{
T_1 V_10 = 0 ;
struct V_11 * V_12 ;
V_12 = F_7 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
return 0 ;
V_10 = F_8 ( V_2 -> V_6 , V_9 , V_4 , V_5 ) ;
V_12 -> V_5 = V_5 ;
if ( F_9 ( V_2 -> V_6 , V_10 ) ) {
F_10 ( V_12 ) ;
return 0 ;
}
V_12 -> V_14 = V_10 ;
V_12 -> V_6 = V_2 -> V_6 ;
V_12 -> V_4 = V_4 ;
F_11 ( & V_12 -> V_15 , & V_8 -> V_16 ) ;
return V_10 ;
}
static void F_12 ( struct V_11 * V_17 )
{
F_13 ( V_17 -> V_6 ,
V_17 -> V_14 ,
V_17 -> V_4 ,
V_17 -> V_5 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 ;
int V_22 = 0 ;
int V_23 ;
struct V_24 V_25 ;
struct V_26 * V_27 = & V_28 ;
if ( F_15 ( V_6 -> V_29 , L_1 ) )
V_27 = & V_30 ;
V_21 = F_16 ( NULL , V_6 , V_27 ) ;
if ( ! V_21 )
return - V_31 ;
F_17 ( V_6 , V_21 ) ;
V_22 = F_18 ( V_6 -> V_29 , 0 , & V_25 ) ;
if ( V_22 ) {
F_19 ( V_21 -> V_6 ,
L_2 ) ;
return V_22 ;
}
V_21 -> V_32 = F_20 ( V_6 , & V_25 ) ;
if ( F_21 ( V_21 -> V_32 ) )
return F_22 ( V_21 -> V_32 ) ;
V_23 = F_23 ( V_6 -> V_29 , 0 ) ;
V_22 = F_24 ( V_6 , V_23 , V_33 , 0 , V_34 , V_21 ) ;
if ( V_22 ) {
F_25 ( V_21 -> V_6 ,
L_3 ) ;
return - V_35 ;
}
V_22 = F_26 ( V_21 ) ;
if ( ! V_22 )
return 0 ;
F_27 ( & V_21 -> V_36 , V_21 ) ;
return V_22 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 = F_29 ( V_6 ) ;
F_30 ( V_21 ) ;
F_27 ( & V_21 -> V_36 , V_21 ) ;
return 0 ;
}
