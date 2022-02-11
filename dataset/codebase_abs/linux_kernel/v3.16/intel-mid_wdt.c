static inline int F_1 ( int V_1 , T_1 * V_2 , int V_3 )
{
return F_2 ( V_4 , V_1 , V_2 , V_3 , NULL , 0 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
int V_7 , V_8 ;
int V_9 = V_6 -> V_9 ;
struct V_10 {
T_1 V_11 ;
T_1 V_9 ;
} V_10 = { V_9 - V_12 , V_9 } ;
V_8 = F_4 ( sizeof( V_10 ) , 4 ) ;
V_7 = F_1 ( V_13 , ( T_1 * ) & V_10 , V_8 ) ;
if ( V_7 ) {
struct V_14 * V_15 = F_5 ( V_6 ) ;
F_6 ( V_15 , L_1 , V_7 ) ;
}
return V_7 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_1 ( V_16 , NULL , 0 ) ;
if ( V_7 ) {
struct V_14 * V_15 = F_5 ( V_6 ) ;
F_6 ( V_15 , L_2 , V_7 ) ;
}
return V_7 ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_1 ( V_17 , NULL , 0 ) ;
if ( V_7 ) {
struct V_14 * V_15 = F_5 ( V_6 ) ;
F_6 ( V_15 , L_3 , V_7 ) ;
}
return V_7 ;
}
static T_2 F_9 ( int V_18 , void * V_19 )
{
F_10 ( L_4 ) ;
return V_20 ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_5 * V_23 ;
struct V_24 * V_25 = V_22 -> V_15 . V_26 ;
int V_7 ;
if ( ! V_25 ) {
F_12 ( & V_22 -> V_15 , L_5 ) ;
return - V_27 ;
}
if ( V_25 -> V_28 ) {
V_7 = V_25 -> V_28 ( V_22 ) ;
if ( V_7 )
return V_7 ;
}
V_23 = F_13 ( & V_22 -> V_15 , sizeof( * V_23 ) , V_29 ) ;
if ( ! V_23 )
return - V_30 ;
V_23 -> V_31 = & V_32 ;
V_23 -> V_33 = & V_34 ;
V_23 -> V_35 = V_36 ;
V_23 -> V_37 = V_38 ;
V_23 -> V_9 = V_39 ;
F_14 ( V_23 , & V_22 -> V_15 ) ;
F_15 ( V_22 , V_23 ) ;
V_7 = F_16 ( & V_22 -> V_15 , V_25 -> V_18 , F_9 ,
V_40 | V_41 , L_6 ,
V_23 ) ;
if ( V_7 ) {
F_12 ( & V_22 -> V_15 , L_7 ,
V_25 -> V_18 ) ;
return V_7 ;
}
V_7 = F_17 ( V_23 ) ;
if ( V_7 ) {
F_12 ( & V_22 -> V_15 , L_8 ) ;
return V_7 ;
}
F_18 ( & V_22 -> V_15 , L_9 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_20 ( V_22 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
