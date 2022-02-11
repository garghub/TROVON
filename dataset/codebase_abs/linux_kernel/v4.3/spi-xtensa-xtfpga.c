static inline void F_1 ( const struct V_1 * V_2 ,
unsigned V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( const struct V_1 * V_2 ,
unsigned V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_6 )
{
unsigned V_7 ;
for ( V_7 = 0 ; F_3 ( V_6 , V_8 ) &&
V_7 < V_9 ; ++ V_7 )
F_6 ( 1 ) ;
F_7 ( V_7 == V_9 ) ;
}
static T_1 F_8 ( struct V_10 * V_2 , unsigned V_11 ,
T_1 V_12 , T_2 V_13 )
{
struct V_1 * V_6 = F_9 ( V_2 -> V_14 ) ;
V_6 -> V_15 = ( V_6 -> V_15 << V_13 ) | ( V_12 & F_10 ( V_13 - 1 , 0 ) ) ;
V_6 -> V_16 += V_13 ;
if ( V_6 -> V_16 >= 16 ) {
F_1 ( V_6 , V_17 ,
V_6 -> V_15 >> ( V_6 -> V_16 - 16 ) ) ;
V_6 -> V_16 -= 16 ;
F_1 ( V_6 , V_18 , 1 ) ;
F_5 ( V_6 ) ;
F_1 ( V_6 , V_18 , 0 ) ;
}
return 0 ;
}
static void F_11 ( struct V_10 * V_2 , int V_19 )
{
struct V_1 * V_6 = F_9 ( V_2 -> V_14 ) ;
F_12 ( V_6 -> V_16 != 0 ) ;
V_6 -> V_16 = 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_6 ;
struct V_22 * V_23 ;
int V_24 ;
struct V_25 * V_14 ;
V_14 = F_14 ( & V_21 -> V_26 , sizeof( struct V_1 ) ) ;
if ( ! V_14 )
return - V_27 ;
V_14 -> V_28 = V_29 ;
V_14 -> V_30 = F_15 ( 1 , 16 ) ;
V_14 -> V_31 = V_21 -> V_26 . V_32 ;
V_14 -> V_26 . V_33 = V_21 -> V_26 . V_33 ;
V_6 = F_9 ( V_14 ) ;
V_6 -> V_34 . V_14 = V_14 ;
V_6 -> V_34 . V_35 = F_11 ;
V_6 -> V_34 . V_36 [ V_37 ] = F_8 ;
V_23 = F_16 ( V_21 , V_38 , 0 ) ;
if ( ! V_23 ) {
F_17 ( & V_21 -> V_26 , L_1 ) ;
V_24 = - V_39 ;
goto V_40;
}
V_6 -> V_5 = F_18 ( & V_21 -> V_26 , V_23 ) ;
if ( F_19 ( V_6 -> V_5 ) ) {
V_24 = F_20 ( V_6 -> V_5 ) ;
goto V_40;
}
F_1 ( V_6 , V_18 , 0 ) ;
F_21 ( 1000 , 2000 ) ;
if ( F_3 ( V_6 , V_8 ) ) {
F_17 ( & V_21 -> V_26 , L_2 ) ;
V_24 = - V_41 ;
goto V_40;
}
V_24 = F_22 ( & V_6 -> V_34 ) ;
if ( V_24 < 0 ) {
F_17 ( & V_21 -> V_26 , L_3 ) ;
goto V_40;
}
F_23 ( V_21 , V_14 ) ;
return 0 ;
V_40:
F_24 ( V_14 ) ;
return V_24 ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_25 * V_14 = F_26 ( V_21 ) ;
struct V_1 * V_6 = F_9 ( V_14 ) ;
F_27 ( & V_6 -> V_34 ) ;
F_24 ( V_14 ) ;
return 0 ;
}
