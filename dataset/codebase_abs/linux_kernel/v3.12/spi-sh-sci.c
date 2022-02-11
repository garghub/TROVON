static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( V_4 )
V_2 -> V_5 |= V_3 ;
else
V_2 -> V_5 &= ~ V_3 ;
F_2 ( V_2 -> V_5 , F_3 ( V_2 ) ) ;
}
static inline void F_4 ( struct V_6 * V_7 , int V_4 )
{
F_1 ( F_5 ( V_7 -> V_8 ) , V_9 , V_4 ) ;
}
static inline void F_6 ( struct V_6 * V_7 , int V_4 )
{
F_1 ( F_5 ( V_7 -> V_8 ) , V_10 , V_4 ) ;
}
static inline T_1 F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 -> V_8 ) ;
return ( F_8 ( F_3 ( V_2 ) ) & V_11 ) ? 1 : 0 ;
}
static T_1 F_9 ( struct V_6 * V_12 ,
unsigned V_13 , T_1 V_14 , T_2 V_3 )
{
return F_10 ( V_12 , V_13 , 0 , 0 , V_14 , V_3 ) ;
}
static T_1 F_11 ( struct V_6 * V_12 ,
unsigned V_13 , T_1 V_14 , T_2 V_3 )
{
return F_12 ( V_12 , V_13 , 0 , 0 , V_14 , V_3 ) ;
}
static T_1 F_13 ( struct V_6 * V_12 ,
unsigned V_13 , T_1 V_14 , T_2 V_3 )
{
return F_10 ( V_12 , V_13 , 1 , 0 , V_14 , V_3 ) ;
}
static T_1 F_14 ( struct V_6 * V_12 ,
unsigned V_13 , T_1 V_14 , T_2 V_3 )
{
return F_12 ( V_12 , V_13 , 1 , 0 , V_14 , V_3 ) ;
}
static void F_15 ( struct V_6 * V_7 , int V_15 )
{
struct V_1 * V_2 = F_5 ( V_7 -> V_8 ) ;
if ( V_2 -> V_16 && V_2 -> V_16 -> V_17 )
( V_2 -> V_16 -> V_17 ) ( V_2 -> V_16 , V_7 -> V_17 , V_15 ) ;
}
static int F_16 ( struct V_18 * V_7 )
{
struct V_19 * V_20 ;
struct V_21 * V_8 ;
struct V_1 * V_2 ;
int V_22 ;
V_8 = F_17 ( & V_7 -> V_7 , sizeof( struct V_1 ) ) ;
if ( V_8 == NULL ) {
F_18 ( & V_7 -> V_7 , L_1 ) ;
V_22 = - V_23 ;
goto V_24;
}
V_2 = F_5 ( V_8 ) ;
F_19 ( V_7 , V_2 ) ;
V_2 -> V_16 = F_20 ( & V_7 -> V_7 ) ;
V_2 -> V_25 . V_8 = F_21 ( V_8 ) ;
V_2 -> V_25 . V_8 -> V_26 = V_2 -> V_16 -> V_26 ;
V_2 -> V_25 . V_8 -> V_27 = V_2 -> V_16 -> V_27 ;
V_2 -> V_25 . V_28 = F_15 ;
V_2 -> V_25 . V_29 [ V_30 ] = F_9 ;
V_2 -> V_25 . V_29 [ V_31 ] = F_11 ;
V_2 -> V_25 . V_29 [ V_32 ] = F_13 ;
V_2 -> V_25 . V_29 [ V_33 ] = F_14 ;
V_20 = F_22 ( V_7 , V_34 , 0 ) ;
if ( V_20 == NULL ) {
V_22 = - V_35 ;
goto V_36;
}
V_2 -> V_37 = F_23 ( V_20 -> V_38 , F_24 ( V_20 ) ) ;
if ( ! V_2 -> V_37 ) {
V_22 = - V_39 ;
goto V_36;
}
V_2 -> V_5 = F_8 ( F_3 ( V_2 ) ) ;
F_1 ( V_2 , V_40 , 1 ) ;
V_22 = F_25 ( & V_2 -> V_25 ) ;
if ( ! V_22 )
return 0 ;
F_1 ( V_2 , V_40 , 0 ) ;
F_26 ( V_2 -> V_37 ) ;
V_36:
F_27 ( V_2 -> V_25 . V_8 ) ;
V_24:
return V_22 ;
}
static int F_28 ( struct V_18 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_26 ( V_2 -> V_37 ) ;
F_1 ( V_2 , V_40 , 0 ) ;
F_30 ( & V_2 -> V_25 ) ;
F_27 ( V_2 -> V_25 . V_8 ) ;
return 0 ;
}
