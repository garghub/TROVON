static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_10 , int V_11 )
{
if ( V_10 -> V_12 ) {
F_5 ( L_1 , V_11 ) ;
V_11 = 1 ;
F_6 ( V_10 -> V_12 , V_11 ) ;
}
}
static void F_4 ( struct V_9 * V_10 , int V_11 ) {}
static int F_7 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_15 * V_6 = V_3 -> V_6 -> V_6 ;
T_1 V_16 , V_17 , V_18 ;
long V_19 ;
struct V_20 * V_21 = F_8 ( V_3 -> V_22 ) ;
int V_23 = V_21 -> V_24 ;
if ( F_9 ( V_1 -> V_25 ) ) {
F_10 ( V_6 , L_2 ) ;
return - V_26 ;
}
V_16 = V_14 -> V_27 * V_14 -> V_28 ;
if ( ! V_16 ) {
F_10 ( V_6 , L_3 ,
V_29 , V_14 -> V_27 , V_14 -> V_28 ) ;
return - V_26 ;
}
V_19 = F_11 ( V_1 -> V_25 , V_30 ) ;
if ( V_19 <= 0 ) {
F_10 ( V_6 , L_4 ,
V_19 ) ;
return - V_26 ;
}
V_17 = V_19 * 100 / V_16 ;
V_18 = V_31
| V_32 ;
V_18 |= F_12 ( V_17 ) ;
F_13 ( V_1 , F_14 ( V_23 ) , V_18 ) ;
F_13 ( V_1 ,
F_15 ( V_23 ) , 0xfff0 ) ;
F_13 ( V_1 ,
F_16 ( V_23 ) , V_14 -> V_33 ) ;
F_13 ( V_1 , F_17 ( V_23 ) , V_14 -> V_33 + 1 ) ;
F_13 ( V_1 , F_18 ( V_23 ) , V_14 -> V_33 ) ;
F_13 ( V_1 , F_19 ( V_23 ) ,
F_20 ( 4 ) |
F_21 ( 4 ) ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_8 ( V_3 -> V_22 ) ;
int V_23 = V_21 -> V_24 ;
int V_34 ;
V_34 = F_23 ( V_1 -> V_25 ,
F_11 ( V_1 -> V_25 , V_30 ) ) ;
if ( V_34 ) {
F_10 ( V_3 -> V_6 -> V_6 ,
L_5 , V_34 ) ;
return V_34 ;
}
V_34 = F_24 ( V_1 -> V_25 ) ;
if ( V_34 ) {
F_10 ( V_3 -> V_6 -> V_6 ,
L_6 , V_34 ) ;
return V_34 ;
}
F_13 ( V_1 , F_25 ( V_23 ) , 1 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_8 ( V_3 -> V_22 ) ;
int V_23 = V_21 -> V_24 ;
F_13 ( V_1 , F_25 ( V_23 ) , 0 ) ;
F_27 ( V_1 -> V_25 ) ;
}
void F_28 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_13 * V_35 )
{
V_14 = V_35 ;
F_5 ( L_7 ,
V_14 -> V_36 . V_37 , V_14 -> V_38 ,
V_14 -> V_28 , V_14 -> clock ,
V_14 -> V_39 , V_14 -> V_40 ,
V_14 -> V_41 , V_14 -> V_42 ,
V_14 -> V_33 , V_14 -> V_43 ,
V_14 -> V_44 , V_14 -> V_27 ,
V_14 -> type , V_14 -> V_45 ) ;
F_7 ( V_3 , V_14 ) ;
F_29 ( V_3 -> V_22 ) ;
}
void F_30 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_31 ( V_3 ) ;
struct V_46 * V_47 = V_10 -> V_47 ;
struct V_48 * V_49 = V_10 -> V_49 ;
struct V_50 * V_51 = F_32 ( V_3 -> V_22 ) ;
if ( F_33 ( ! V_10 -> V_52 ) )
return;
F_26 ( V_3 ) ;
F_34 ( V_47 , V_51 , false ) ;
F_35 ( V_47 , V_51 , F_36 ( V_49 ) ) ;
F_4 ( V_10 , 0 ) ;
V_10 -> V_52 = false ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_31 ( V_3 ) ;
struct V_46 * V_47 = V_10 -> V_47 ;
struct V_48 * V_49 = V_10 -> V_49 ;
struct V_50 * V_51 = F_32 ( V_3 -> V_22 ) ;
if ( F_33 ( V_10 -> V_52 ) )
return;
F_4 ( V_10 , 1 ) ;
if ( F_22 ( V_3 ) )
return;
F_35 ( V_47 , V_51 , F_36 ( V_49 ) ) ;
F_34 ( V_47 , V_51 , true ) ;
V_10 -> V_52 = true ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_2 * V_53 )
{
struct V_9 * V_10 = F_31 ( V_3 ) ;
struct V_1 * V_1 ;
int V_54 ;
T_1 V_55 = 0 ;
if ( ! V_3 || ! V_53 )
return - V_26 ;
V_1 = F_1 ( V_3 ) ;
V_54 = V_10 -> V_49 -> V_56 ;
if ( V_54 == 1 )
V_55 |= V_57 ;
else if ( V_54 == 2 )
V_55 |= V_58 ;
else
return - V_26 ;
V_55 |= V_59 ;
F_39 ( V_1 ) ;
F_13 ( V_1 , V_60 , V_55 ) ;
F_13 ( V_1 , V_61 ,
V_62 ) ;
F_13 ( V_1 , V_63 , 1 ) ;
F_40 ( V_1 ) ;
return 0 ;
}
