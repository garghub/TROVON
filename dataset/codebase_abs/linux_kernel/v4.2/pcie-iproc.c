static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void T_1 * F_2 ( struct V_5 * V_6 ,
unsigned int V_7 ,
int V_8 )
{
struct V_2 * V_3 = V_6 -> V_9 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned V_11 = F_3 ( V_7 ) ;
unsigned V_12 = F_4 ( V_7 ) ;
unsigned V_13 = V_6 -> V_14 ;
T_2 V_15 ;
if ( V_13 == 0 ) {
if ( V_11 >= 1 )
return NULL ;
F_5 ( V_8 & V_16 ,
V_10 -> V_17 + V_18 ) ;
return ( V_10 -> V_17 + V_19 ) ;
}
if ( V_12 > 1 )
return NULL ;
V_15 = ( V_13 << V_20 ) |
( V_11 << V_21 ) |
( V_12 << V_22 ) |
( V_8 & V_23 ) |
( 1 & V_24 ) ;
F_5 ( V_15 , V_10 -> V_17 + V_25 ) ;
return ( V_10 -> V_17 + V_26 ) ;
}
static void F_6 ( struct V_1 * V_10 )
{
T_2 V_15 ;
V_15 = V_27 | V_28 ;
F_5 ( V_15 , V_10 -> V_17 + V_29 ) ;
F_7 ( 250 ) ;
V_15 &= ~ V_27 ;
F_5 ( V_15 , V_10 -> V_17 + V_29 ) ;
F_8 ( 250 ) ;
}
static int F_9 ( struct V_1 * V_10 , struct V_5 * V_6 )
{
T_3 V_30 ;
T_2 V_31 ;
T_4 V_32 , V_33 ;
int V_34 = 0 ;
F_10 ( V_6 , 0 , V_35 , & V_30 ) ;
if ( ( V_30 & 0x7f ) != V_36 ) {
F_11 ( V_10 -> V_37 , L_1 , V_30 ) ;
return - V_38 ;
}
F_12 ( V_6 , 0 , V_39 ,
V_40 ) ;
V_32 = F_13 ( V_6 , 0 , V_41 ) ;
F_14 ( V_6 , 0 , V_32 + V_42 , & V_33 ) ;
if ( V_33 & V_43 )
V_34 = 1 ;
if ( ! V_34 ) {
#define F_15 0x0dc
#define F_16 0xf
#define F_17 0x2
#define F_18 0x1
F_19 ( V_6 , 0 ,
F_15 ,
& V_31 ) ;
if ( ( V_31 & F_16 ) ==
F_17 ) {
V_31 &= ~ F_16 ;
V_31 |= F_18 ;
F_20 ( V_6 , 0 ,
F_15 ,
V_31 ) ;
F_8 ( 100 ) ;
V_32 = F_13 ( V_6 , 0 , V_41 ) ;
F_14 ( V_6 , 0 , V_32 + V_42 ,
& V_33 ) ;
if ( V_33 & V_43 )
V_34 = 1 ;
}
}
F_21 ( V_10 -> V_37 , L_2 , V_34 ? L_3 : L_4 ) ;
return V_34 ? 0 : - V_44 ;
}
static void F_22 ( struct V_1 * V_10 )
{
F_5 ( V_45 , V_10 -> V_17 + V_46 ) ;
}
int F_23 ( struct V_1 * V_10 , struct V_47 * V_48 )
{
int V_49 ;
struct V_5 * V_6 ;
if ( ! V_10 || ! V_10 -> V_37 || ! V_10 -> V_17 )
return - V_50 ;
if ( V_10 -> V_51 ) {
V_49 = F_24 ( V_10 -> V_51 ) ;
if ( V_49 ) {
F_11 ( V_10 -> V_37 , L_5 ) ;
return V_49 ;
}
V_49 = F_25 ( V_10 -> V_51 ) ;
if ( V_49 ) {
F_11 ( V_10 -> V_37 , L_6 ) ;
goto V_52;
}
}
F_6 ( V_10 ) ;
V_10 -> V_9 . V_4 = V_10 ;
V_6 = F_26 ( V_10 -> V_37 , 0 , & V_53 ,
& V_10 -> V_9 , V_48 ) ;
if ( ! V_6 ) {
F_11 ( V_10 -> V_37 , L_7 ) ;
V_49 = - V_54 ;
goto V_55;
}
V_10 -> V_56 = V_6 ;
V_49 = F_9 ( V_10 , V_6 ) ;
if ( V_49 ) {
F_11 ( V_10 -> V_37 , L_8 ) ;
goto V_57;
}
F_22 ( V_10 ) ;
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
F_29 ( V_58 , V_10 -> V_59 ) ;
F_30 ( V_6 ) ;
return 0 ;
V_57:
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
V_55:
if ( V_10 -> V_51 )
F_33 ( V_10 -> V_51 ) ;
V_52:
if ( V_10 -> V_51 )
F_34 ( V_10 -> V_51 ) ;
return V_49 ;
}
int F_35 ( struct V_1 * V_10 )
{
F_31 ( V_10 -> V_56 ) ;
F_32 ( V_10 -> V_56 ) ;
if ( V_10 -> V_51 ) {
F_33 ( V_10 -> V_51 ) ;
F_34 ( V_10 -> V_51 ) ;
}
return 0 ;
}
