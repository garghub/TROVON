static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 * V_6 ;
}
int F_4 ( T_1 * V_7 )
{
struct V_1 * V_2 = & V_8 ;
T_1 V_5 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
V_5 = F_1 ( V_2 , V_11 ) ;
* V_7 = F_3 ( V_5 ) ;
return 0 ;
}
static int F_5 ( void * V_7 , T_2 * V_12 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_11 ) ;
* V_12 = F_3 ( V_5 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_16 ;
V_15 = F_9 ( L_1 , NULL ) ;
if ( F_10 ( V_15 ) )
return - V_17 ;
V_2 -> V_13 = V_15 ;
V_16 = F_11 ( L_2 , V_18 | V_19 ,
V_15 , V_2 , & V_20 ) ;
if ( ! V_16 ) {
F_6 ( V_2 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , const struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_23 -> V_23 ;
struct V_1 * V_2 = & V_8 ;
const struct V_28 * V_29 ;
int V_30 ;
V_29 = F_13 ( V_31 ) ;
if ( ! V_29 ) {
F_14 ( & V_23 -> V_23 , L_3 ) ;
return - V_32 ;
}
V_30 = F_15 ( V_23 ) ;
if ( V_30 < 0 ) {
F_14 ( & V_23 -> V_23 , L_4 ) ;
return V_30 ;
}
V_30 = F_16 ( V_23 ,
V_33 ,
& V_2 -> V_34 ) ;
if ( V_30 < 0 ) {
F_14 ( & V_23 -> V_23 , L_5 ) ;
return V_30 ;
}
F_14 ( & V_23 -> V_23 , L_6 , V_2 -> V_34 ) ;
V_2 -> V_4 = F_17 ( V_27 ,
V_2 -> V_34 ,
V_35 ) ;
if ( ! V_2 -> V_4 ) {
F_14 ( & V_23 -> V_23 , L_7 ) ;
return - V_17 ;
}
V_30 = F_8 ( V_2 ) ;
if ( V_30 < 0 )
F_18 ( & V_23 -> V_23 , L_8 ) ;
V_8 . V_9 = true ;
return 0 ;
}
