static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 =
V_1 -> V_7 -> V_4 . V_8 ;
int V_9 ;
if ( V_2 ) {
V_9 = F_2 ( V_6 -> V_10 , L_1 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_1 , V_6 -> V_10 , V_9 ) ;
goto V_11;
}
V_9 = F_2 ( V_6 -> V_12 , L_3 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_3 , V_6 -> V_12 , V_9 ) ;
goto V_13;
}
V_9 = F_2 ( V_6 -> V_14 , L_4 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_4 , V_6 -> V_14 , V_9 ) ;
goto V_15;
}
if ( V_6 -> V_16 != - 1 ) {
V_9 = F_2 ( V_6 -> V_16 , L_5 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_5 , V_6 -> V_16 , V_9 ) ;
goto V_17;
}
F_4 ( V_6 -> V_16 , 0 ) ;
}
F_5 ( L_6 ) ;
} else {
F_6 ( V_6 -> V_10 ) ;
F_6 ( V_6 -> V_12 ) ;
F_6 ( V_6 -> V_14 ) ;
if ( V_6 -> V_16 != - 1 ) {
F_4 ( V_6 -> V_16 , 1 ) ;
F_6 ( V_6 -> V_16 ) ;
}
F_5 ( L_7 ) ;
}
return 0 ;
V_17:
F_6 ( V_6 -> V_14 ) ;
V_15:
F_6 ( V_6 -> V_12 ) ;
V_13:
F_6 ( V_6 -> V_10 ) ;
V_11:
return V_9 ;
}
static int F_7 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_3 * V_4 = V_18 -> V_19 . V_4 ;
struct V_20 * V_21 = V_1 -> V_21 ;
T_1 V_22 ;
int V_9 ;
V_9 = F_1 ( V_1 , true ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_8 , V_9 ) ;
goto V_23;
}
V_9 = F_8 ( V_1 -> V_24 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_9 , V_9 ) ;
goto V_23;
}
V_9 = F_8 ( V_1 -> V_25 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_10 , V_9 ) ;
goto V_23;
}
V_9 = F_8 ( V_1 -> V_26 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_11 , V_9 ) ;
goto V_23;
}
if ( V_1 -> V_27 )
V_9 = F_9 ( V_1 -> V_27 ) ;
if ( ! V_9 )
V_9 = F_9 ( V_1 -> V_28 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_12 , V_9 ) ;
goto V_23;
}
F_10 ( V_1 , false ) ;
V_21 -> V_29 -> V_30 ( V_21 ) ;
F_10 ( V_1 , true ) ;
F_11 ( V_1 , V_31 , 0x0001001b ) ;
F_11 ( V_1 , V_32 ,
V_33 |
V_34 ) ;
V_22 = F_12 ( V_1 , V_35 ) ;
V_22 |= F_13 ( 0x1fff ) ;
F_11 ( V_1 , V_35 ,
~ V_36 & V_22 ) ;
F_11 ( V_1 , V_35 ,
V_36 | V_22 ) ;
return 0 ;
V_23:
return V_9 ;
}
static int F_14 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_3 * V_4 = V_18 -> V_19 . V_4 ;
int V_9 = 0 ;
F_11 ( V_1 , V_32 , 0 ) ;
F_10 ( V_1 , false ) ;
if ( V_1 -> V_27 )
V_9 = F_15 ( V_1 -> V_27 ) ;
if ( ! V_9 )
V_9 = F_15 ( V_1 -> V_28 ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_12 , V_9 ) ;
goto V_23;
}
F_16 ( V_1 -> V_24 ) ;
F_16 ( V_1 -> V_25 ) ;
F_16 ( V_1 -> V_26 ) ;
V_9 = F_1 ( V_1 , false ) ;
if ( V_9 ) {
F_3 ( V_4 -> V_4 , L_13 , V_9 ) ;
goto V_23;
}
return 0 ;
V_23:
return V_9 ;
}
void F_17 ( struct V_37 * V_38 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
T_1 V_39 , V_40 ;
V_39 = F_12 ( V_1 , V_41 ) ;
V_40 = F_12 ( V_1 , V_32 ) ;
if ( ( V_40 & V_34 ) &&
( V_39 & V_42 ) ) {
bool V_43 = ! ! ( V_39 & V_44 ) ;
F_5 ( L_14 , V_39 , V_40 ) ;
F_11 ( V_1 , V_32 ,
V_40 | V_45 ) ;
F_19 ( V_38 -> V_4 ) ;
V_40 = V_34 ;
if ( ! V_43 )
V_40 |= V_33 ;
F_11 ( V_1 , V_32 , V_40 ) ;
}
}
static enum V_46 F_20 (
struct V_37 * V_38 , bool V_47 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
T_1 V_39 ;
int V_48 = 20 ;
V_39 = F_12 ( V_1 , V_41 ) ;
while ( V_48 -- && ! ( V_39 & V_44 ) ) {
F_21 ( 10 ) ;
V_39 = F_12 ( V_1 , V_41 ) ;
F_5 ( L_15 , V_39 ) ;
}
return ( V_39 & V_44 ) ?
V_49 : V_50 ;
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
F_14 ( V_18 ) ;
F_23 ( V_38 ) ;
F_24 ( V_38 ) ;
F_25 ( V_18 -> V_1 ) ;
F_26 ( V_18 ) ;
}
static int F_27 ( struct V_37 * V_38 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_51 * V_51 ;
T_1 V_52 ;
int V_9 = 0 ;
V_52 = F_12 ( V_1 , V_53 ) ;
F_11 ( V_1 , V_53 , V_52 | V_54 ) ;
V_51 = F_28 ( V_38 , V_1 -> V_55 ) ;
F_11 ( V_1 , V_53 , V_52 ) ;
F_29 ( V_38 , V_51 ) ;
if ( V_51 ) {
V_9 = F_30 ( V_38 , V_51 ) ;
F_26 ( V_51 ) ;
}
return V_9 ;
}
static int F_31 ( struct V_37 * V_38 ,
struct V_56 * V_57 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
struct V_58 * V_59 = V_38 -> V_4 -> V_60 ;
struct V_61 * V_62 = V_59 -> V_62 ;
long V_63 , V_64 ;
V_64 = 1000 * V_57 -> clock ;
V_63 = V_62 -> V_29 -> V_65 ( V_62 ,
V_64 , V_18 -> V_1 -> V_66 ) ;
F_5 ( L_16 , V_64 , V_63 ) ;
if ( V_63 != V_64 )
return V_67 ;
return 0 ;
}
static struct V_68 *
F_32 ( struct V_37 * V_38 )
{
struct V_18 * V_18 = F_18 ( V_38 ) ;
return V_18 -> V_1 -> V_66 ;
}
struct V_37 * F_33 ( struct V_1 * V_1 )
{
struct V_37 * V_38 = NULL ;
struct V_18 * V_18 ;
int V_9 ;
V_18 = F_34 ( sizeof( * V_18 ) , V_69 ) ;
if ( ! V_18 ) {
V_9 = - V_70 ;
goto V_23;
}
V_18 -> V_1 = F_35 ( V_1 ) ;
V_38 = & V_18 -> V_19 ;
F_36 ( V_1 -> V_4 , V_38 , & V_71 ,
V_72 ) ;
F_37 ( V_38 , & V_73 ) ;
V_38 -> V_74 = V_75 ;
V_38 -> V_76 = 1 ;
V_38 -> V_77 = 0 ;
F_38 ( V_38 ) ;
V_9 = F_7 ( V_18 ) ;
if ( V_9 ) {
F_3 ( V_1 -> V_4 -> V_4 , L_17 , V_9 ) ;
goto V_23;
}
F_39 ( V_38 , V_1 -> V_66 ) ;
return V_38 ;
V_23:
if ( V_38 )
F_22 ( V_38 ) ;
return F_40 ( V_9 ) ;
}
