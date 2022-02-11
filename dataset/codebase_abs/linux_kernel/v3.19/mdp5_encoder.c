static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
V_9 -> V_10 = F_5 (
& V_11 ) ;
F_6 ( L_1 , V_9 -> V_10 ) ;
}
static void F_7 ( struct V_9 * V_9 )
{
if ( V_9 -> V_10 ) {
F_8 ( V_9 -> V_10 ) ;
V_9 -> V_10 = 0 ;
}
}
static void F_9 ( struct V_9 * V_9 , int V_12 )
{
if ( V_9 -> V_10 ) {
F_6 ( L_2 , V_12 ) ;
V_12 = 1 ;
F_10 ( V_9 -> V_10 , V_12 ) ;
}
}
static void F_4 ( struct V_9 * V_9 ) {}
static void F_7 ( struct V_9 * V_9 ) {}
static void F_9 ( struct V_9 * V_9 , int V_12 ) {}
static void F_11 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
F_7 ( V_9 ) ;
F_13 ( V_3 ) ;
F_14 ( V_9 ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_13 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_14 = V_9 -> V_14 ;
bool V_15 = ( V_13 == V_16 ) ;
unsigned long V_17 ;
F_6 ( L_3 , V_13 ) ;
if ( V_15 == V_9 -> V_15 )
return;
if ( V_15 ) {
F_9 ( V_9 , 1 ) ;
F_16 ( & V_9 -> V_18 , V_17 ) ;
F_17 ( V_1 , F_18 ( V_14 ) , 1 ) ;
F_19 ( & V_9 -> V_18 , V_17 ) ;
} else {
F_16 ( & V_9 -> V_18 , V_17 ) ;
F_17 ( V_1 , F_18 ( V_14 ) , 0 ) ;
F_19 ( & V_9 -> V_18 , V_17 ) ;
F_20 ( & V_1 -> V_19 , F_21 ( V_14 ) ) ;
F_9 ( V_9 , 0 ) ;
}
V_9 -> V_15 = V_15 ;
}
static bool F_22 ( struct V_2 * V_3 ,
const struct V_20 * V_13 ,
struct V_20 * V_21 )
{
return true ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_20 * V_13 ,
struct V_20 * V_21 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_14 = V_9 -> V_14 ;
T_1 V_22 , V_23 , V_24 , V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 , V_29 ;
T_1 V_30 ;
unsigned long V_17 ;
V_13 = V_21 ;
F_6 ( L_4 ,
V_13 -> V_19 . V_31 , V_13 -> V_32 ,
V_13 -> V_33 , V_13 -> clock ,
V_13 -> V_34 , V_13 -> V_35 ,
V_13 -> V_36 , V_13 -> V_37 ,
V_13 -> V_38 , V_13 -> V_39 ,
V_13 -> V_40 , V_13 -> V_41 ,
V_13 -> type , V_13 -> V_17 ) ;
V_25 = 0 ;
if ( V_13 -> V_17 & V_42 )
V_25 |= V_43 ;
if ( V_13 -> V_17 & V_44 )
V_25 |= V_45 ;
V_22 = 0 ;
V_30 = 0x213f ;
V_28 = ( V_13 -> V_37 - V_13 -> V_35 ) ;
V_29 = V_13 -> V_37 - ( V_13 -> V_35 - V_13 -> V_34 ) - 1 ;
V_23 = V_13 -> V_41 * V_13 -> V_37 ;
V_24 = ( V_13 -> V_40 - V_13 -> V_39 ) * V_13 -> V_37 ;
V_26 = ( V_13 -> V_41 - V_13 -> V_39 ) * V_13 -> V_37 + V_22 ;
V_27 = V_23 - ( ( V_13 -> V_39 - V_13 -> V_38 ) * V_13 -> V_37 ) + V_22 - 1 ;
F_16 ( & V_9 -> V_18 , V_17 ) ;
F_17 ( V_1 , F_24 ( V_14 ) ,
F_25 ( V_13 -> V_36 - V_13 -> V_35 ) |
F_26 ( V_13 -> V_37 ) ) ;
F_17 ( V_1 , F_27 ( V_14 ) , V_23 ) ;
F_17 ( V_1 , F_28 ( V_14 ) , V_24 ) ;
F_17 ( V_1 , F_29 ( V_14 ) ,
F_30 ( V_28 ) |
F_31 ( V_29 ) ) ;
F_17 ( V_1 , F_32 ( V_14 ) , V_26 ) ;
F_17 ( V_1 , F_33 ( V_14 ) , V_27 ) ;
F_17 ( V_1 , F_34 ( V_14 ) , 0 ) ;
F_17 ( V_1 , F_35 ( V_14 ) , 0xff ) ;
F_17 ( V_1 , F_36 ( V_14 ) , V_22 ) ;
F_17 ( V_1 , F_37 ( V_14 ) , V_25 ) ;
F_17 ( V_1 , F_38 ( V_14 ) ,
F_39 ( 0 ) |
F_40 ( 0 ) ) ;
F_17 ( V_1 , F_41 ( V_14 ) , 0 ) ;
F_17 ( V_1 , F_42 ( V_14 ) , 0 ) ;
F_17 ( V_1 , F_43 ( V_14 ) , V_30 ) ;
F_17 ( V_1 , F_44 ( V_14 ) , 0x3 ) ;
F_19 ( & V_9 -> V_18 , V_17 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
F_15 ( V_3 , V_46 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
F_47 ( V_3 -> V_47 , V_9 -> V_14 ,
V_9 -> V_48 ) ;
F_15 ( V_3 , V_16 ) ;
}
struct V_2 * F_48 ( struct V_49 * V_6 , int V_14 ,
enum V_50 V_48 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_51 ;
V_9 = F_49 ( sizeof( * V_9 ) , V_52 ) ;
if ( ! V_9 ) {
V_51 = - V_53 ;
goto V_54;
}
V_9 -> V_14 = V_14 ;
V_9 -> V_48 = V_48 ;
V_3 = & V_9 -> V_19 ;
F_50 ( & V_9 -> V_18 ) ;
F_51 ( V_6 , V_3 , & V_55 ,
V_56 ) ;
F_52 ( V_3 , & V_57 ) ;
F_4 ( V_9 ) ;
return V_3 ;
V_54:
if ( V_3 )
F_11 ( V_3 ) ;
return F_53 ( V_51 ) ;
}
