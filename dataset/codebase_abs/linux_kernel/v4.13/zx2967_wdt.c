static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 | V_6 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_7 ) ;
V_5 ^= V_8 ;
F_3 ( V_2 , V_7 ,
V_5 & V_9 ) ;
}
static int
F_6 ( struct V_10 * V_11 , unsigned int V_12 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
unsigned int V_13 = V_14 ;
T_1 V_15 ;
V_15 = V_12 * V_16 ;
if ( V_15 > V_13 * V_17 )
V_13 = F_8 ( V_15 , V_17 ) ;
V_15 = F_8 ( V_15 , V_13 ) ;
F_3 ( V_2 , V_18 ,
F_9 ( V_13 ) & V_9 ) ;
F_3 ( V_2 , V_19 ,
V_15 & V_9 ) ;
F_5 ( V_2 ) ;
V_11 -> V_12 = ( V_15 * V_13 ) / V_16 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_20 ) ;
V_5 |= V_21 ;
F_3 ( V_2 , V_20 ,
V_5 & V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_20 ) ;
V_5 &= ~ V_21 ;
F_3 ( V_2 , V_20 ,
V_5 & V_9 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_6 ( V_11 , V_11 -> V_12 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
int V_24 ;
void T_3 * V_25 ;
unsigned int V_26 , V_27 , V_28 ;
struct V_29 V_30 ;
V_24 = F_16 ( V_23 -> V_31 ,
L_1 , 3 , 0 , & V_30 ) ;
if ( V_24 )
return;
V_26 = V_30 . args [ 0 ] ;
V_28 = V_30 . args [ 1 ] ;
V_27 = V_30 . args [ 2 ] ;
V_25 = F_17 ( V_30 . V_32 ) ;
if ( F_18 ( V_25 ) ) {
F_19 ( V_30 . V_32 ) ;
return;
}
F_20 ( V_25 , V_26 , V_27 , V_28 ) ;
F_19 ( V_30 . V_32 ) ;
}
static int F_21 ( struct V_33 * V_34 )
{
struct V_22 * V_23 = & V_34 -> V_23 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_24 ;
struct V_37 * V_38 ;
V_2 = F_22 ( V_23 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
F_23 ( V_34 , V_2 ) ;
V_2 -> V_41 . V_42 = & V_43 ;
V_2 -> V_41 . V_44 = & V_45 ;
V_2 -> V_41 . V_12 = V_46 ;
V_2 -> V_41 . V_47 = V_48 ;
V_2 -> V_41 . V_49 = V_50 ;
V_2 -> V_41 . V_51 = & V_34 -> V_23 ;
V_36 = F_24 ( V_34 , V_52 , 0 ) ;
V_2 -> V_4 = F_25 ( V_23 , V_36 ) ;
if ( F_18 ( V_2 -> V_4 ) )
return F_26 ( V_2 -> V_4 ) ;
F_15 ( V_23 ) ;
V_2 -> clock = F_27 ( V_23 , NULL ) ;
if ( F_18 ( V_2 -> clock ) ) {
F_28 ( V_23 , L_2 ) ;
return F_26 ( V_2 -> clock ) ;
}
V_24 = F_29 ( V_2 -> clock ) ;
if ( V_24 < 0 ) {
F_28 ( V_23 , L_3 ) ;
return V_24 ;
}
F_30 ( V_2 -> clock , V_16 ) ;
V_38 = F_31 ( V_23 , NULL ) ;
if ( F_18 ( V_38 ) ) {
F_28 ( V_23 , L_4 ) ;
V_24 = F_26 ( V_38 ) ;
goto V_53;
}
F_32 ( V_38 ) ;
F_33 ( V_38 ) ;
F_34 ( & V_2 -> V_41 , V_2 ) ;
F_35 ( & V_2 -> V_41 ,
V_46 , V_23 ) ;
F_36 ( & V_2 -> V_41 , V_54 ) ;
V_24 = F_37 ( & V_2 -> V_41 ) ;
if ( V_24 )
goto V_53;
F_38 ( V_23 , L_5 ,
V_2 -> V_41 . V_12 , V_54 ) ;
return 0 ;
V_53:
F_39 ( V_2 -> clock ) ;
return V_24 ;
}
static int F_40 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_41 ( V_34 ) ;
F_42 ( & V_2 -> V_41 ) ;
F_39 ( V_2 -> clock ) ;
return 0 ;
}
