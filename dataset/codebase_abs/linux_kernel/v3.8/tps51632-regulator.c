static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
unsigned int V_7 = V_8 ;
int V_9 ;
if ( V_4 -> V_10 )
V_7 = V_11 ;
V_6 = F_3 ( V_4 -> V_12 , V_7 , & V_5 ) ;
if ( V_6 < 0 ) {
F_4 ( V_4 -> V_13 , L_1 , V_6 ) ;
return V_6 ;
}
V_9 = V_5 & V_14 ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
unsigned int V_7 = V_8 ;
if ( V_4 -> V_10 )
V_7 = V_11 ;
if ( V_15 > V_16 )
return - V_17 ;
V_6 = F_6 ( V_4 -> V_12 , V_7 , V_15 ) ;
if ( V_6 < 0 )
F_4 ( V_4 -> V_13 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_19 = V_18 / 6000 ;
int V_6 ;
if ( V_19 )
V_19 -- ;
V_6 = F_6 ( V_4 -> V_12 , V_20 , F_8 ( V_19 ) ) ;
if ( V_6 < 0 )
F_4 ( V_4 -> V_13 , L_3 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
int V_6 ;
T_1 V_23 = 0 ;
int V_9 ;
if ( ! V_22 -> V_10 )
goto V_24;
V_23 |= V_25 ;
V_4 -> V_10 = V_22 -> V_10 ;
V_9 = F_10 ( V_22 -> V_26 ) ;
V_6 = F_6 ( V_4 -> V_12 , V_11 , V_9 ) ;
if ( V_6 < 0 ) {
F_4 ( V_4 -> V_13 , L_4 , V_6 ) ;
return V_6 ;
}
if ( V_22 -> V_27 )
V_23 |= V_28 ;
if ( V_22 -> V_29 ) {
unsigned int V_30 ;
V_6 = F_3 ( V_4 -> V_12 , V_31 , & V_30 ) ;
if ( V_6 < 0 ) {
F_4 ( V_4 -> V_13 , L_5 , V_6 ) ;
return V_6 ;
}
if ( ! ( V_30 & V_32 ) ) {
V_9 = F_10 ( V_22 -> V_29 ) ;
V_6 = F_6 ( V_4 -> V_12 , V_31 ,
V_9 ) ;
if ( V_6 < 0 ) {
F_4 ( V_4 -> V_13 ,
L_6 , V_6 ) ;
return V_6 ;
}
}
}
V_24:
V_6 = F_6 ( V_4 -> V_12 , V_33 , V_23 ) ;
if ( V_6 < 0 )
F_4 ( V_4 -> V_13 , L_7 , V_6 ) ;
return V_6 ;
}
static bool F_11 ( struct V_34 * V_13 , unsigned int V_7 )
{
if ( ( V_7 >= 0x8 ) && ( V_7 <= 0x10 ) )
return false ;
return true ;
}
static int F_12 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_6 ;
struct V_39 V_40 = { } ;
V_22 = V_36 -> V_13 . V_41 ;
if ( ! V_22 ) {
F_4 ( & V_36 -> V_13 , L_8 ) ;
return - V_17 ;
}
if ( V_22 -> V_10 ) {
if ( ( V_22 -> V_26 < V_42 ) ||
( V_22 -> V_26 > V_43 ) ) {
F_4 ( & V_36 -> V_13 , L_9 ) ;
return - V_17 ;
}
if ( ( V_22 -> V_29 ) &&
( ( V_22 -> V_29 < V_42 ) ||
( V_22 -> V_29 > V_43 ) ) ) {
F_4 ( & V_36 -> V_13 , L_10 ) ;
return - V_17 ;
}
}
V_4 = F_13 ( & V_36 -> V_13 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_4 ( & V_36 -> V_13 , L_11 ) ;
return - V_45 ;
}
V_4 -> V_13 = & V_36 -> V_13 ;
V_4 -> V_46 . V_47 = V_38 -> V_47 ;
V_4 -> V_46 . V_38 = 0 ;
V_4 -> V_46 . V_18 = V_48 ;
V_4 -> V_46 . V_49 = V_42 ;
V_4 -> V_46 . V_50 = V_51 ;
V_4 -> V_46 . V_52 = V_53 ;
V_4 -> V_46 . V_54 = V_16 + 1 ;
V_4 -> V_46 . V_55 = & V_56 ;
V_4 -> V_46 . type = V_57 ;
V_4 -> V_46 . V_58 = V_59 ;
V_4 -> V_12 = F_14 ( V_36 , & V_60 ) ;
if ( F_15 ( V_4 -> V_12 ) ) {
V_6 = F_16 ( V_4 -> V_12 ) ;
F_4 ( & V_36 -> V_13 , L_12 , V_6 ) ;
return V_6 ;
}
F_17 ( V_36 , V_4 ) ;
V_6 = F_9 ( V_4 , V_22 ) ;
if ( V_6 < 0 ) {
F_4 ( V_4 -> V_13 , L_13 , V_6 ) ;
return V_6 ;
}
V_40 . V_13 = & V_36 -> V_13 ;
V_40 . V_61 = V_22 -> V_62 ;
V_40 . V_63 = V_4 ;
V_40 . V_12 = V_4 -> V_12 ;
V_40 . V_64 = V_36 -> V_13 . V_64 ;
V_2 = F_18 ( & V_4 -> V_46 , & V_40 ) ;
if ( F_15 ( V_2 ) ) {
F_4 ( V_4 -> V_13 , L_14 ) ;
return F_16 ( V_2 ) ;
}
V_4 -> V_2 = V_2 ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 )
{
struct V_3 * V_4 = F_20 ( V_36 ) ;
F_21 ( V_4 -> V_2 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_65 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_65 ) ;
}
