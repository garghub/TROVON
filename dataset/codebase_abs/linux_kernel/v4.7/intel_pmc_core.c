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
static int F_5 ( struct V_12 * V_13 , void * V_14 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
T_1 V_16 ;
V_16 = F_1 ( V_2 ,
V_11 ) ;
F_6 ( V_13 , L_1 , F_3 ( V_16 ) ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
return F_8 ( V_18 , F_5 , V_17 -> V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_20 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_21 * V_22 , * V_18 ;
V_22 = F_12 ( L_2 , NULL ) ;
if ( ! V_22 )
return - V_23 ;
V_2 -> V_20 = V_22 ;
V_18 = F_13 ( L_3 , V_24 | V_25 ,
V_22 , V_2 , & V_26 ) ;
if ( ! V_18 ) {
F_9 ( V_2 ) ;
return - V_27 ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
}
static int F_14 ( struct V_28 * V_29 , const struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_29 -> V_29 ;
struct V_1 * V_2 = & V_8 ;
const struct V_34 * V_35 ;
int V_36 ;
V_35 = F_15 ( V_37 ) ;
if ( ! V_35 ) {
F_16 ( & V_29 -> V_29 , L_4 ) ;
return - V_38 ;
}
V_36 = F_17 ( V_29 ) ;
if ( V_36 < 0 ) {
F_16 ( & V_29 -> V_29 , L_5 ) ;
return V_36 ;
}
V_36 = F_18 ( V_29 ,
V_39 ,
& V_2 -> V_40 ) ;
if ( V_36 < 0 ) {
F_16 ( & V_29 -> V_29 , L_6 ) ;
return V_36 ;
}
F_16 ( & V_29 -> V_29 , L_7 , V_2 -> V_40 ) ;
V_2 -> V_4 = F_19 ( V_33 ,
V_2 -> V_40 ,
V_41 ) ;
if ( ! V_2 -> V_4 ) {
F_16 ( & V_29 -> V_29 , L_8 ) ;
return - V_23 ;
}
V_36 = F_11 ( V_2 ) ;
if ( V_36 < 0 ) {
F_20 ( & V_29 -> V_29 , L_9 ) ;
return V_36 ;
}
V_8 . V_9 = true ;
return 0 ;
}
