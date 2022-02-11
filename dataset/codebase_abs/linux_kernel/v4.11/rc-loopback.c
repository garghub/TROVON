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
unsigned V_22 ;
F_7 ( V_23 ) ;
if ( V_5 -> V_12 < V_5 -> V_17 ||
V_5 -> V_12 > V_5 -> V_18 ) {
F_2 ( L_8 ) ;
goto V_24;
}
if ( V_5 -> V_25 )
V_21 = V_8 ;
else
V_21 = V_7 ;
if ( ! ( V_21 & V_5 -> V_10 ) ) {
F_2 ( L_9 ) ;
goto V_24;
}
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
V_23 . V_26 = V_22 % 2 ? false : true ;
V_23 . V_27 = V_19 [ V_22 ] * 1000 ;
if ( V_23 . V_27 )
F_8 ( V_2 , & V_23 ) ;
}
V_23 . V_26 = false ;
V_23 . V_27 = V_2 -> V_28 ;
F_8 ( V_2 , & V_23 ) ;
F_9 ( V_2 ) ;
V_24:
return V_20 ;
}
static void F_10 ( struct V_1 * V_2 , bool V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_30 != V_29 ) {
F_2 ( L_10 , V_29 ? L_11 : L_12 ) ;
V_5 -> V_30 = V_29 ;
}
}
static int F_11 ( struct V_1 * V_2 , int V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_25 != V_29 ) {
F_2 ( L_13 , V_29 ? L_11 : L_12 ) ;
V_5 -> V_25 = ! ! V_29 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_31 != V_29 ) {
F_2 ( L_14 , V_29 ? L_15 : L_16 ) ;
V_5 -> V_31 = ! ! V_29 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
static const unsigned int V_16 = 512 ;
struct V_34 * V_35 ;
int V_36 ;
int V_22 ;
if ( ! V_33 -> V_3 )
return 0 ;
V_35 = F_14 ( V_16 , sizeof( * V_35 ) , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
V_36 = F_15 ( V_2 -> V_39 , V_33 -> V_40 , V_35 , V_16 ) ;
if ( V_36 == - V_41 )
V_36 = V_16 ;
if ( V_36 >= 0 ) {
for ( V_22 = 0 ; V_22 < V_36 ; ++ V_22 )
F_16 ( V_2 , & V_35 [ V_22 ] ) ;
F_9 ( V_2 ) ;
V_36 = 0 ;
}
F_17 ( V_35 ) ;
return V_36 ;
}
static int T_2 F_18 ( void )
{
struct V_1 * V_42 ;
int V_36 ;
V_42 = F_19 ( V_43 ) ;
if ( ! V_42 ) {
F_20 (KERN_ERR DRIVER_NAME L_17 ) ;
return - V_38 ;
}
V_42 -> V_44 = L_18 ;
V_42 -> V_45 = L_19 ;
V_42 -> V_46 . V_47 = V_48 ;
V_42 -> V_46 . V_49 = 1 ;
V_42 -> V_50 = V_51 ;
V_42 -> V_52 = V_53 ;
V_42 -> V_6 = & V_54 ;
V_42 -> V_55 = V_56 ;
V_42 -> V_57 = V_58 ;
V_42 -> V_59 = true ;
V_42 -> V_28 = 100 * 1000 * 1000 ;
V_42 -> V_60 = 1 ;
V_42 -> V_61 = V_62 ;
V_42 -> V_63 = 1000 ;
V_42 -> V_64 = 1000 ;
V_42 -> V_65 = F_1 ;
V_42 -> V_66 = F_3 ;
V_42 -> V_67 = F_4 ;
V_42 -> V_68 = F_5 ;
V_42 -> V_69 = F_6 ;
V_42 -> V_70 = F_10 ;
V_42 -> V_71 = F_11 ;
V_42 -> V_72 = F_12 ;
V_42 -> V_73 = F_13 ;
V_54 . V_10 = V_7 ;
V_54 . V_12 = 36000 ;
V_54 . V_14 = 50 ;
V_54 . V_17 = 1 ;
V_54 . V_18 = ~ 0 ;
V_54 . V_30 = true ;
V_54 . V_25 = false ;
V_54 . V_31 = false ;
V_36 = F_21 ( V_42 ) ;
if ( V_36 < 0 ) {
F_20 (KERN_ERR DRIVER_NAME L_20 ) ;
F_22 ( V_42 ) ;
return V_36 ;
}
V_54 . V_2 = V_42 ;
return 0 ;
}
static void T_3 F_23 ( void )
{
F_24 ( V_54 . V_2 ) ;
}
