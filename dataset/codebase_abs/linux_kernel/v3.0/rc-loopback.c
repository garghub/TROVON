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
static int F_6 ( struct V_1 * V_2 , int * V_19 , T_1 V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_21 ;
unsigned V_22 ;
unsigned V_23 = 0 ;
unsigned V_24 ;
F_7 ( V_25 ) ;
if ( V_20 == 0 || V_20 % sizeof( int ) ) {
F_2 ( L_8 ) ;
return - V_9 ;
}
V_22 = V_20 / sizeof( int ) ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
V_23 += abs ( V_19 [ V_24 ] ) ;
if ( V_23 == 0 ) {
F_2 ( L_9 ) ;
return - V_9 ;
}
if ( V_5 -> V_12 < V_5 -> V_17 ||
V_5 -> V_12 > V_5 -> V_18 ) {
F_2 ( L_10 ) ;
goto V_26;
}
if ( V_5 -> V_27 )
V_21 = V_8 ;
else
V_21 = V_7 ;
if ( ! ( V_21 & V_5 -> V_10 ) ) {
F_2 ( L_11 ) ;
goto V_26;
}
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
V_25 . V_28 = V_24 % 2 ? false : true ;
V_25 . V_29 = abs ( V_19 [ V_24 ] ) * 1000 ;
if ( V_25 . V_29 )
F_8 ( V_2 , & V_25 ) ;
}
V_25 . V_28 = false ;
V_25 . V_29 = V_2 -> V_30 ;
F_8 ( V_2 , & V_25 ) ;
F_9 ( V_2 ) ;
V_26:
F_10 ( V_31 ) ;
F_11 ( F_12 ( V_23 ) ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , bool V_32 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_33 != V_32 ) {
F_2 ( L_12 , V_32 ? L_13 : L_14 ) ;
V_5 -> V_33 = V_32 ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_32 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_27 != V_32 ) {
F_2 ( L_15 , V_32 ? L_13 : L_14 ) ;
V_5 -> V_27 = ! ! V_32 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_32 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_34 != V_32 ) {
F_2 ( L_16 , V_32 ? L_17 : L_18 ) ;
V_5 -> V_34 = ! ! V_32 ;
}
return 0 ;
}
static int T_2 F_16 ( void )
{
struct V_1 * V_35 ;
int V_36 ;
V_35 = F_17 () ;
if ( ! V_35 ) {
F_18 (KERN_ERR DRIVER_NAME L_19 ) ;
return - V_37 ;
}
V_35 -> V_38 = L_20 ;
V_35 -> V_39 = L_21 ;
V_35 -> V_40 . V_41 = V_42 ;
V_35 -> V_40 . V_43 = 1 ;
V_35 -> V_44 = V_45 ;
V_35 -> V_46 = V_47 ;
V_35 -> V_6 = & V_48 ;
V_35 -> V_49 = V_50 ;
V_35 -> V_51 = V_52 ;
V_35 -> V_30 = 100 * 1000 * 1000 ;
V_35 -> V_53 = 1 ;
V_35 -> V_54 = V_55 ;
V_35 -> V_56 = 1000 ;
V_35 -> V_57 = 1000 ;
V_35 -> V_58 = F_1 ;
V_35 -> V_59 = F_3 ;
V_35 -> V_60 = F_4 ;
V_35 -> V_61 = F_5 ;
V_35 -> V_62 = F_6 ;
V_35 -> V_63 = F_13 ;
V_35 -> V_64 = F_14 ;
V_35 -> V_65 = F_15 ;
V_35 -> V_6 = & V_48 ;
V_48 . V_10 = V_7 ;
V_48 . V_12 = 36000 ;
V_48 . V_14 = 50 ;
V_48 . V_17 = 1 ;
V_48 . V_18 = ~ 0 ;
V_48 . V_33 = true ;
V_48 . V_27 = false ;
V_48 . V_34 = false ;
V_36 = F_19 ( V_35 ) ;
if ( V_36 < 0 ) {
F_18 (KERN_ERR DRIVER_NAME L_22 ) ;
F_20 ( V_35 ) ;
return V_36 ;
}
V_48 . V_2 = V_35 ;
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( V_48 . V_2 ) ;
}
