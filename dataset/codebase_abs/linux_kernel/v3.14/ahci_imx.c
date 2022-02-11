static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 ;
if ( V_4 -> type == V_7 ) {
V_6 = F_3 ( V_4 -> V_8 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_1 ,
V_6 ) ;
return V_6 ;
}
}
V_6 = F_3 ( V_4 -> V_9 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_2 ,
V_6 ) ;
goto V_10;
}
if ( V_4 -> type == V_11 ) {
F_5 ( V_4 -> V_12 , V_13 ,
V_14 ,
V_14 ) ;
}
F_6 ( 1000 , 2000 ) ;
return 0 ;
V_10:
if ( V_4 -> type == V_7 )
F_7 ( V_4 -> V_8 ) ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_4 -> type == V_11 ) {
F_5 ( V_4 -> V_12 , V_13 ,
V_14 ,
! V_14 ) ;
}
F_7 ( V_4 -> V_9 ) ;
if ( V_4 -> type == V_7 )
F_7 ( V_4 -> V_8 ) ;
}
static void F_9 ( struct V_15 * V_16 )
{
T_1 V_17 ;
struct V_18 * V_2 ;
struct V_19 * V_20 = F_2 ( V_16 -> V_2 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
void T_2 * V_24 = V_22 -> V_24 ;
struct V_3 * V_4 = F_2 ( V_16 -> V_2 -> V_5 ) ;
F_10 ( V_16 ) ;
if ( ! ( V_4 -> V_25 ) || V_26 )
return;
V_4 -> V_25 = false ;
F_11 (dev, &ap->link, ENABLED)
return;
V_17 = F_12 ( V_24 + V_27 ) ;
F_13 ( V_17 | V_28 , V_24 + V_27 ) ;
F_8 ( V_16 -> V_2 ) ;
V_4 -> V_29 = true ;
}
static int F_14 ( struct V_30 * V_31 , unsigned int * V_32 ,
unsigned long V_33 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_3 * V_4 = F_2 ( V_16 -> V_2 -> V_5 ) ;
int V_6 = - V_34 ;
if ( V_4 -> type == V_7 )
V_6 = V_35 . V_36 ( V_31 , V_32 , V_33 ) ;
else if ( V_4 -> type == V_11 )
V_6 = V_37 . V_36 ( V_31 , V_32 , V_33 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , void T_2 * V_24 )
{
int V_6 = 0 ;
unsigned int V_17 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_17 = F_12 ( V_24 + V_38 ) ;
if ( ! ( V_17 & V_39 ) ) {
V_17 |= V_39 ;
F_13 ( V_17 , V_24 + V_38 ) ;
}
V_17 = F_12 ( V_24 + V_40 ) ;
if ( ! ( V_17 & 0x1 ) ) {
V_17 |= 0x1 ;
F_13 ( V_17 , V_24 + V_40 ) ;
}
V_17 = F_16 ( V_4 -> V_41 ) / 1000 ;
F_13 ( V_17 , V_24 + V_42 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_29 )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 = 0 ;
if ( ! V_4 -> V_29 )
V_6 = F_1 ( V_2 ) ;
return V_6 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = & V_44 -> V_2 ;
struct V_45 * V_46 , * V_47 , V_48 [ 2 ] ;
const struct V_49 * V_50 ;
enum V_51 type ;
const struct V_52 * V_53 = NULL ;
struct V_3 * V_4 ;
struct V_1 * V_54 ;
struct V_43 * V_55 ;
int V_6 ;
V_50 = F_21 ( V_56 , V_2 ) ;
if ( ! V_50 )
return - V_57 ;
type = (enum V_51 ) V_50 -> V_58 ;
V_53 = & V_59 ;
V_4 = F_22 ( V_2 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 ) {
F_4 ( V_2 , L_3 ) ;
return - V_61 ;
}
V_55 = F_23 ( L_4 , - 1 ) ;
if ( ! V_55 )
return - V_62 ;
V_54 = & V_55 -> V_2 ;
V_54 -> V_5 = V_2 ;
V_4 -> V_29 = false ;
V_4 -> V_25 = true ;
V_4 -> type = type ;
V_4 -> V_41 = F_24 ( V_2 , L_5 ) ;
if ( F_25 ( V_4 -> V_41 ) ) {
F_4 ( V_2 , L_6 ) ;
V_6 = F_26 ( V_4 -> V_41 ) ;
goto V_63;
}
if ( type == V_7 ) {
V_4 -> V_8 = F_24 ( V_2 , L_7 ) ;
if ( F_25 ( V_4 -> V_8 ) ) {
F_4 ( V_2 , L_8 ) ;
V_6 = F_26 ( V_4 -> V_8 ) ;
goto V_63;
}
}
V_4 -> V_9 = F_24 ( V_2 , L_9 ) ;
if ( F_25 ( V_4 -> V_9 ) ) {
F_4 ( V_2 , L_10 ) ;
V_6 = F_26 ( V_4 -> V_9 ) ;
goto V_63;
}
V_4 -> V_55 = V_55 ;
F_27 ( V_44 , V_4 ) ;
V_46 = F_28 ( V_44 , V_64 , 0 ) ;
V_47 = F_28 ( V_44 , V_65 , 0 ) ;
if ( ! V_46 || ! V_47 ) {
F_4 ( V_2 , L_11 ) ;
V_6 = - V_61 ;
goto V_63;
}
V_48 [ 0 ] = * V_46 ;
V_48 [ 1 ] = * V_47 ;
V_54 -> V_66 = F_29 ( 32 ) ;
V_54 -> V_67 = & V_54 -> V_66 ;
V_54 -> V_68 = V_2 -> V_68 ;
if ( type == V_11 ) {
V_4 -> V_12 = F_30 (
L_12 ) ;
if ( F_25 ( V_4 -> V_12 ) ) {
F_4 ( V_2 ,
L_13 ) ;
V_6 = F_26 ( V_4 -> V_12 ) ;
goto V_63;
}
F_5 ( V_4 -> V_12 , V_13 ,
V_69 |
V_70 |
V_71 |
V_72 |
V_73 |
V_74 |
V_75 |
V_76 |
V_14 |
V_77 ,
V_78 |
V_79 |
V_80 |
V_81 |
V_73 |
V_82 |
V_83 |
V_84 ) ;
}
V_6 = F_31 ( V_55 , V_48 , 2 ) ;
if ( V_6 )
goto V_63;
V_6 = F_32 ( V_55 , V_53 , sizeof( * V_53 ) ) ;
if ( V_6 )
goto V_63;
V_6 = F_33 ( V_55 ) ;
if ( V_6 ) {
V_63:
F_34 ( V_55 ) ;
return V_6 ;
}
return 0 ;
}
static int F_35 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_36 ( V_44 ) ;
struct V_43 * V_55 = V_4 -> V_55 ;
F_37 ( V_55 ) ;
return 0 ;
}
