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
int V_20 = F_8 ( F_9 ( V_3 -> V_21 ) ) ;
if ( F_10 ( V_1 -> V_22 ) ) {
F_11 ( V_6 , L_2 ) ;
return - V_23 ;
}
V_16 = V_14 -> V_24 * V_14 -> V_25 ;
if ( ! V_16 ) {
F_11 ( V_6 , L_3 ,
V_26 , V_14 -> V_24 , V_14 -> V_25 ) ;
return - V_23 ;
}
V_19 = F_12 ( V_1 -> V_22 , V_27 ) ;
if ( V_19 <= 0 ) {
F_11 ( V_6 , L_4 ,
V_19 ) ;
return - V_23 ;
}
V_17 = V_19 * 100 / V_16 ;
V_18 = V_28
| V_29 ;
V_18 |= F_13 ( V_17 ) ;
F_14 ( V_1 , F_15 ( V_20 ) , V_18 ) ;
F_14 ( V_1 ,
F_16 ( V_20 ) , 0xfff0 ) ;
F_14 ( V_1 ,
F_17 ( V_20 ) , V_14 -> V_30 ) ;
F_14 ( V_1 , F_18 ( V_20 ) , V_14 -> V_30 + 1 ) ;
F_14 ( V_1 , F_19 ( V_20 ) , V_14 -> V_30 ) ;
F_14 ( V_1 , F_20 ( V_20 ) ,
F_21 ( 4 ) |
F_22 ( 4 ) ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_20 = F_8 ( F_9 ( V_3 -> V_21 ) ) ;
int V_31 ;
V_31 = F_24 ( V_1 -> V_22 ,
F_12 ( V_1 -> V_22 , V_27 ) ) ;
if ( V_31 ) {
F_11 ( V_3 -> V_6 -> V_6 ,
L_5 , V_31 ) ;
return V_31 ;
}
V_31 = F_25 ( V_1 -> V_22 ) ;
if ( V_31 ) {
F_11 ( V_3 -> V_6 -> V_6 ,
L_6 , V_31 ) ;
return V_31 ;
}
F_14 ( V_1 , F_26 ( V_20 ) , 1 ) ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_20 = F_8 ( F_9 ( V_3 -> V_21 ) ) ;
F_14 ( V_1 , F_26 ( V_20 ) , 0 ) ;
F_28 ( V_1 -> V_22 ) ;
}
void F_29 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_13 * V_32 )
{
struct V_9 * V_10 = F_30 ( V_3 ) ;
V_14 = V_32 ;
F_5 ( L_7 ,
V_14 -> V_33 . V_34 , V_14 -> V_35 ,
V_14 -> V_25 , V_14 -> clock ,
V_14 -> V_36 , V_14 -> V_37 ,
V_14 -> V_38 , V_14 -> V_39 ,
V_14 -> V_30 , V_14 -> V_40 ,
V_14 -> V_41 , V_14 -> V_24 ,
V_14 -> type , V_14 -> V_42 ) ;
F_7 ( V_3 , V_14 ) ;
F_31 ( V_3 -> V_21 , & V_10 -> V_43 ,
V_10 -> V_44 ) ;
}
void F_32 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_30 ( V_3 ) ;
struct V_45 * V_44 = V_10 -> V_44 ;
struct V_46 * V_43 = & V_10 -> V_43 ;
if ( F_33 ( ! V_10 -> V_47 ) )
return;
F_27 ( V_3 ) ;
F_34 ( V_44 , false ) ;
F_35 ( V_44 , F_36 ( V_43 ) ) ;
F_4 ( V_10 , 0 ) ;
V_10 -> V_47 = false ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_30 ( V_3 ) ;
struct V_45 * V_44 = V_10 -> V_44 ;
struct V_46 * V_43 = & V_10 -> V_43 ;
if ( F_33 ( V_10 -> V_47 ) )
return;
F_4 ( V_10 , 1 ) ;
if ( F_23 ( V_3 ) )
return;
F_35 ( V_44 , F_36 ( V_43 ) ) ;
F_34 ( V_44 , true ) ;
V_10 -> V_47 = true ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_2 * V_48 )
{
struct V_9 * V_10 = F_30 ( V_3 ) ;
struct V_1 * V_1 ;
int V_49 ;
T_1 V_50 = 0 ;
if ( ! V_3 || ! V_48 )
return - V_23 ;
V_1 = F_1 ( V_3 ) ;
V_49 = V_10 -> V_43 . V_51 ;
if ( V_49 == 1 )
V_50 |= V_52 ;
else if ( V_49 == 2 )
V_50 |= V_53 ;
else
return - V_23 ;
V_50 |= V_54 ;
F_39 ( V_1 ) ;
F_14 ( V_1 , V_55 , V_50 ) ;
F_14 ( V_1 , V_56 ,
V_57 ) ;
F_14 ( V_1 , V_58 , 1 ) ;
F_40 ( V_1 ) ;
return 0 ;
}
