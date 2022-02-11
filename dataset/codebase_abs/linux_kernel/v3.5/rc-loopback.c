static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ( V_3 & ( V_7 | V_8 ) ) != V_3 ) {
F_2 ( L_1 , V_3 ) ;
return - V_9 ;
}
F_2 ( L_2 , V_3 ) ;
V_5 -> V_10 = V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( L_3 , V_11 ) ;
V_5 -> V_12 = V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 < 1 || V_13 > 99 ) {
F_2 ( L_4 , V_13 ) ;
return - V_9 ;
}
F_2 ( L_5 , V_13 ) ;
V_5 -> V_14 = V_13 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_15 , T_1 V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_15 < 1 || V_15 > V_16 ) {
F_2 ( L_6 , V_15 , V_16 ) ;
return - V_9 ;
}
F_2 ( L_7 , V_15 , V_16 ) ;
V_5 -> V_17 = V_15 ;
V_5 -> V_18 = V_16 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned * V_19 , unsigned V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_21 ;
unsigned V_22 = 0 ;
unsigned V_23 ;
F_7 ( V_24 ) ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ )
V_22 += abs ( V_19 [ V_23 ] ) ;
if ( V_22 == 0 ) {
F_2 ( L_8 ) ;
return - V_9 ;
}
if ( V_5 -> V_12 < V_5 -> V_17 ||
V_5 -> V_12 > V_5 -> V_18 ) {
F_2 ( L_9 ) ;
goto V_25;
}
if ( V_5 -> V_26 )
V_21 = V_8 ;
else
V_21 = V_7 ;
if ( ! ( V_21 & V_5 -> V_10 ) ) {
F_2 ( L_10 ) ;
goto V_25;
}
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
V_24 . V_27 = V_23 % 2 ? false : true ;
V_24 . V_28 = V_19 [ V_23 ] * 1000 ;
if ( V_24 . V_28 )
F_8 ( V_2 , & V_24 ) ;
}
V_24 . V_27 = false ;
V_24 . V_28 = V_2 -> V_29 ;
F_8 ( V_2 , & V_24 ) ;
F_9 ( V_2 ) ;
V_25:
F_10 ( V_30 ) ;
F_11 ( F_12 ( V_22 ) ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , bool V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_32 != V_31 ) {
F_2 ( L_11 , V_31 ? L_12 : L_13 ) ;
V_5 -> V_32 = V_31 ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_26 != V_31 ) {
F_2 ( L_14 , V_31 ? L_12 : L_13 ) ;
V_5 -> V_26 = ! ! V_31 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_33 != V_31 ) {
F_2 ( L_15 , V_31 ? L_16 : L_17 ) ;
V_5 -> V_33 = ! ! V_31 ;
}
return 0 ;
}
static int T_2 F_16 ( void )
{
struct V_1 * V_34 ;
int V_35 ;
V_34 = F_17 () ;
if ( ! V_34 ) {
F_18 (KERN_ERR DRIVER_NAME L_18 ) ;
return - V_36 ;
}
V_34 -> V_37 = L_19 ;
V_34 -> V_38 = L_20 ;
V_34 -> V_39 . V_40 = V_41 ;
V_34 -> V_39 . V_42 = 1 ;
V_34 -> V_43 = V_44 ;
V_34 -> V_45 = V_46 ;
V_34 -> V_6 = & V_47 ;
V_34 -> V_48 = V_49 ;
V_34 -> V_50 = V_51 ;
V_34 -> V_29 = 100 * 1000 * 1000 ;
V_34 -> V_52 = 1 ;
V_34 -> V_53 = V_54 ;
V_34 -> V_55 = 1000 ;
V_34 -> V_56 = 1000 ;
V_34 -> V_57 = F_1 ;
V_34 -> V_58 = F_3 ;
V_34 -> V_59 = F_4 ;
V_34 -> V_60 = F_5 ;
V_34 -> V_61 = F_6 ;
V_34 -> V_62 = F_13 ;
V_34 -> V_63 = F_14 ;
V_34 -> V_64 = F_15 ;
V_47 . V_10 = V_7 ;
V_47 . V_12 = 36000 ;
V_47 . V_14 = 50 ;
V_47 . V_17 = 1 ;
V_47 . V_18 = ~ 0 ;
V_47 . V_32 = true ;
V_47 . V_26 = false ;
V_47 . V_33 = false ;
V_35 = F_19 ( V_34 ) ;
if ( V_35 < 0 ) {
F_18 (KERN_ERR DRIVER_NAME L_21 ) ;
F_20 ( V_34 ) ;
return V_35 ;
}
V_47 . V_2 = V_34 ;
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( V_47 . V_2 ) ;
}
