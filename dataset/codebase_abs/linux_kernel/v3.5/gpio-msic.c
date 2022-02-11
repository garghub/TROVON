static int F_1 ( unsigned V_1 )
{
if ( V_1 >= V_2 )
return - V_3 ;
if ( V_1 < 8 )
return V_4 - V_1 ;
if ( V_1 < 16 )
return V_5 - V_1 + 8 ;
if ( V_1 < 20 )
return V_6 - V_1 + 16 ;
return V_7 - V_1 + 20 ;
}
static int F_2 ( unsigned V_1 )
{
if ( V_1 >= V_2 )
return - V_3 ;
if ( V_1 < 8 )
return V_8 - V_1 ;
if ( V_1 < 16 )
return V_9 - V_1 + 8 ;
if ( V_1 < 20 )
return V_10 - V_1 + 16 ;
return V_11 + V_1 + 20 ;
}
static int F_3 ( struct V_12 * V_13 , unsigned V_1 )
{
int V_14 ;
V_14 = F_2 ( V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_4 ( V_14 , V_15 , V_16 ) ;
}
static int F_5 ( struct V_12 * V_13 ,
unsigned V_1 , int V_17 )
{
int V_14 ;
unsigned V_18 ;
V_17 = ( ! ! V_17 ) | V_19 ;
V_18 = V_16 | V_20 ;
V_14 = F_2 ( V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_4 ( V_14 , V_17 , V_18 ) ;
}
static int F_6 ( struct V_12 * V_13 , unsigned V_1 )
{
T_1 V_21 ;
int V_22 ;
int V_14 ;
V_14 = F_1 ( V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_22 = F_7 ( V_14 , & V_21 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_21 & V_23 ;
}
static void F_8 ( struct V_12 * V_13 , unsigned V_1 , int V_17 )
{
int V_14 ;
V_14 = F_2 ( V_1 ) ;
if ( V_14 < 0 )
return;
F_4 ( V_14 , ! ! V_17 , V_20 ) ;
}
static int F_9 ( struct V_24 * V_25 , unsigned type )
{
struct V_26 * V_27 = F_10 ( V_25 ) ;
T_2 V_28 = V_25 -> V_29 - V_27 -> V_30 ;
if ( V_28 >= V_27 -> V_13 . V_31 )
return - V_3 ;
V_27 -> V_32 |= ( 1 << V_28 ) ;
V_27 -> V_33 = type ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , unsigned V_1 )
{
struct V_26 * V_27 = F_12 ( V_13 , struct V_26 , V_13 ) ;
return V_27 -> V_30 + V_1 ;
}
static void F_13 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_10 ( V_25 ) ;
F_14 ( & V_27 -> V_34 ) ;
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_10 ( V_25 ) ;
int V_1 ;
int V_14 ;
T_1 V_35 = 0 ;
if ( V_27 -> V_32 ) {
V_1 = F_16 ( V_27 -> V_32 ) ;
V_14 = F_1 ( V_1 ) ;
if ( V_14 < 0 )
goto V_36;
if ( V_27 -> V_33 & V_37 )
V_35 |= V_38 ;
if ( V_27 -> V_33 & V_39 )
V_35 |= V_40 ;
F_4 ( V_14 , V_35 , V_41 ) ;
V_27 -> V_32 = 0 ;
}
V_36:
F_17 ( & V_27 -> V_34 ) ;
}
static void F_18 ( struct V_24 * V_25 ) { }
static void F_19 ( struct V_24 * V_25 ) { }
static void F_20 ( unsigned V_29 , struct V_42 * V_43 )
{
struct V_24 * V_25 = F_21 ( V_43 ) ;
struct V_26 * V_27 = F_22 ( V_25 ) ;
struct V_44 * V_13 = F_23 ( V_25 ) ;
struct V_45 * V_46 = F_24 ( V_27 -> V_47 ) ;
int V_48 ;
int V_49 ;
T_1 V_50 ;
unsigned long V_51 = 0 ;
for ( V_48 = 0 ; V_48 < ( V_27 -> V_13 . V_31 / V_52 ) ; V_48 ++ ) {
F_25 ( V_46 , V_53 + V_48 , & V_50 ) ;
V_51 = V_50 ;
if ( V_51 ) {
F_26 (bitnr, &pending, BITS_PER_BYTE)
F_27 ( V_27 -> V_30 +
( V_48 * V_52 ) + V_49 ) ;
}
}
V_13 -> V_54 ( V_25 ) ;
}
static int T_3 F_28 ( struct V_55 * V_47 )
{
struct V_56 * V_57 = & V_47 -> V_57 ;
struct V_58 * V_59 = V_57 -> V_60 ;
struct V_26 * V_27 ;
int V_29 = F_29 ( V_47 , 0 ) ;
int V_61 ;
int V_48 ;
if ( V_29 < 0 ) {
F_30 ( V_57 , L_1 ) ;
return - V_3 ;
}
if ( ! V_59 || ! V_59 -> V_62 ) {
F_30 ( V_57 , L_2 ) ;
return - V_3 ;
}
V_27 = F_31 ( sizeof( * V_27 ) , V_63 ) ;
if ( ! V_27 )
return - V_64 ;
F_32 ( V_57 , V_27 ) ;
V_27 -> V_47 = V_47 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_30 = V_59 -> V_62 + V_65 ;
V_27 -> V_13 . V_66 = L_3 ;
V_27 -> V_13 . V_67 = F_3 ;
V_27 -> V_13 . V_68 = F_5 ;
V_27 -> V_13 . V_69 = F_6 ;
V_27 -> V_13 . V_70 = F_8 ;
V_27 -> V_13 . V_71 = F_11 ;
V_27 -> V_13 . V_72 = V_59 -> V_62 ;
V_27 -> V_13 . V_31 = V_2 ;
V_27 -> V_13 . V_73 = 1 ;
V_27 -> V_13 . V_57 = V_57 ;
F_33 ( & V_27 -> V_34 ) ;
V_61 = F_34 ( & V_27 -> V_13 ) ;
if ( V_61 ) {
F_30 ( V_57 , L_4 ) ;
goto V_74;
}
for ( V_48 = 0 ; V_48 < V_27 -> V_13 . V_31 ; V_48 ++ ) {
F_35 ( V_48 + V_27 -> V_30 , V_27 ) ;
F_36 ( V_48 + V_27 -> V_30 ,
& V_75 ,
V_76 ,
L_5 ) ;
}
F_37 ( V_27 -> V_29 , F_20 ) ;
F_38 ( V_27 -> V_29 , V_27 ) ;
return 0 ;
V_74:
F_39 ( V_27 ) ;
return V_61 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_77 ) ;
}
