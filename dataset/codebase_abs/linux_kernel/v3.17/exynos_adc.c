static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_6 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_8 , L_1 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_7 = F_4 ( V_2 -> V_5 ) ;
if ( V_7 ) {
F_2 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_8 ,
L_2 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_7 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_9 ( V_2 -> V_6 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_8 , L_3 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_7 = F_9 ( V_2 -> V_5 ) ;
if ( V_7 ) {
F_7 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_8 ,
L_4 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_11 ( 1 , V_2 -> V_10 ) ;
V_9 = F_12 ( 49 ) | V_11 ;
V_9 |= V_12 ;
F_11 ( V_9 , F_13 ( V_2 -> V_13 ) ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_14 ;
F_11 ( 0 , V_2 -> V_10 ) ;
V_14 = F_15 ( F_13 ( V_2 -> V_13 ) ) ;
V_14 |= V_15 ;
F_11 ( V_14 , F_13 ( V_2 -> V_13 ) ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_11 ( 1 , F_17 ( V_2 -> V_13 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
T_1 V_9 ;
F_11 ( V_16 , F_19 ( V_2 -> V_13 ) ) ;
V_9 = F_15 ( F_13 ( V_2 -> V_13 ) ) ;
F_11 ( V_9 | V_17 , F_13 ( V_2 -> V_13 ) ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_9 , V_18 ;
F_11 ( 1 , V_2 -> V_10 ) ;
V_9 = V_19 ;
F_11 ( V_9 , F_21 ( V_2 -> V_13 ) ) ;
V_18 = V_20 | V_21 |
V_22 | F_22 ( 0 ) ;
F_11 ( V_18 , F_23 ( V_2 -> V_13 ) ) ;
F_11 ( 1 , F_24 ( V_2 -> V_13 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_14 ;
F_11 ( 0 , V_2 -> V_10 ) ;
V_14 = F_15 ( F_21 ( V_2 -> V_13 ) ) ;
V_14 &= ~ V_17 ;
F_11 ( V_14 , F_21 ( V_2 -> V_13 ) ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_11 ( 1 , F_27 ( V_2 -> V_13 ) ) ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
T_1 V_9 , V_18 ;
V_18 = F_15 ( F_23 ( V_2 -> V_13 ) ) ;
V_18 &= ~ V_23 ;
V_18 |= F_29 ( V_16 ) ;
F_11 ( V_18 , F_23 ( V_2 -> V_13 ) ) ;
V_9 = F_15 ( F_21 ( V_2 -> V_13 ) ) ;
F_11 ( V_9 | V_17 , F_21 ( V_2 -> V_13 ) ) ;
}
static struct V_24 * F_30 ( struct V_25 * V_26 )
{
const struct V_27 * V_28 ;
V_28 = F_31 ( V_29 , V_26 -> V_8 . V_30 ) ;
return (struct V_24 * ) V_28 -> V_3 ;
}
static int F_32 ( struct V_31 * V_32 ,
struct V_33 const * V_34 ,
int * V_35 ,
int * V_36 ,
long V_37 )
{
struct V_1 * V_2 = F_33 ( V_32 ) ;
unsigned long V_38 ;
int V_7 ;
if ( V_37 != V_39 )
return - V_40 ;
F_34 ( & V_32 -> V_41 ) ;
F_35 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_3 -> V_43 )
V_2 -> V_3 -> V_43 ( V_2 , V_34 -> V_44 ) ;
V_38 = F_36
( & V_2 -> V_42 , V_45 ) ;
if ( V_38 == 0 ) {
F_37 ( & V_32 -> V_8 , L_5 ) ;
if ( V_2 -> V_3 -> V_46 )
V_2 -> V_3 -> V_46 ( V_2 ) ;
V_7 = - V_47 ;
} else {
* V_35 = V_2 -> V_48 ;
* V_36 = 0 ;
V_7 = V_49 ;
}
F_38 ( & V_32 -> V_41 ) ;
return V_7 ;
}
static T_2 F_39 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = (struct V_1 * ) V_51 ;
V_2 -> V_48 = F_15 ( F_40 ( V_2 -> V_13 ) ) & V_52 ;
if ( V_2 -> V_3 -> V_53 )
V_2 -> V_3 -> V_53 ( V_2 ) ;
F_41 ( & V_2 -> V_42 ) ;
return V_54 ;
}
static int F_42 ( struct V_31 * V_32 ,
unsigned V_55 , unsigned V_56 ,
unsigned * V_57 )
{
struct V_1 * V_2 = F_33 ( V_32 ) ;
if ( V_57 == NULL )
return - V_40 ;
* V_57 = F_15 ( V_2 -> V_13 + V_55 ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_8 , void * V_59 )
{
struct V_25 * V_26 = F_44 ( V_8 ) ;
F_45 ( V_26 ) ;
return 0 ;
}
static int F_46 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = NULL ;
struct V_60 * V_61 = V_26 -> V_8 . V_30 ;
struct V_31 * V_32 = NULL ;
struct V_62 * V_63 ;
int V_7 = - V_64 ;
int V_50 ;
if ( ! V_61 )
return V_7 ;
V_32 = F_47 ( & V_26 -> V_8 , sizeof( struct V_1 ) ) ;
if ( ! V_32 ) {
F_5 ( & V_26 -> V_8 , L_6 ) ;
return - V_65 ;
}
V_2 = F_33 ( V_32 ) ;
V_2 -> V_3 = F_30 ( V_26 ) ;
if ( ! V_2 -> V_3 ) {
F_5 ( & V_26 -> V_8 , L_7 ) ;
return - V_40 ;
}
V_63 = F_48 ( V_26 , V_66 , 0 ) ;
V_2 -> V_13 = F_49 ( & V_26 -> V_8 , V_63 ) ;
if ( F_50 ( V_2 -> V_13 ) )
return F_51 ( V_2 -> V_13 ) ;
V_63 = F_48 ( V_26 , V_66 , 1 ) ;
V_2 -> V_10 = F_49 ( & V_26 -> V_8 , V_63 ) ;
if ( F_50 ( V_2 -> V_10 ) )
return F_51 ( V_2 -> V_10 ) ;
V_50 = F_52 ( V_26 , 0 ) ;
if ( V_50 < 0 ) {
F_5 ( & V_26 -> V_8 , L_8 ) ;
return V_50 ;
}
V_2 -> V_50 = V_50 ;
V_2 -> V_8 = & V_26 -> V_8 ;
F_53 ( & V_2 -> V_42 ) ;
V_2 -> V_6 = F_54 ( & V_26 -> V_8 , L_9 ) ;
if ( F_50 ( V_2 -> V_6 ) ) {
F_5 ( & V_26 -> V_8 , L_10 ,
F_51 ( V_2 -> V_6 ) ) ;
return F_51 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_2 -> V_5 = F_54 ( & V_26 -> V_8 , L_11 ) ;
if ( F_50 ( V_2 -> V_5 ) ) {
F_5 ( & V_26 -> V_8 ,
L_12 ,
F_51 ( V_2 -> V_5 ) ) ;
return F_51 ( V_2 -> V_5 ) ;
}
}
V_2 -> V_67 = F_55 ( & V_26 -> V_8 , L_13 ) ;
if ( F_50 ( V_2 -> V_67 ) ) {
F_5 ( & V_26 -> V_8 , L_14 ,
F_51 ( V_2 -> V_67 ) ) ;
return F_51 ( V_2 -> V_67 ) ;
}
V_7 = F_56 ( V_2 -> V_67 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 ) ;
if ( V_7 )
goto V_68;
V_7 = F_8 ( V_2 ) ;
if ( V_7 )
goto V_69;
F_57 ( V_26 , V_32 ) ;
V_32 -> V_70 = F_58 ( & V_26 -> V_8 ) ;
V_32 -> V_8 . V_71 = & V_26 -> V_8 ;
V_32 -> V_8 . V_30 = V_26 -> V_8 . V_30 ;
V_32 -> V_2 = & V_72 ;
V_32 -> V_73 = V_74 ;
V_32 -> V_75 = V_76 ;
V_32 -> V_77 = V_2 -> V_3 -> V_77 ;
V_7 = F_59 ( V_2 -> V_50 , F_39 ,
0 , F_58 ( & V_26 -> V_8 ) , V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_26 -> V_8 , L_15 ,
V_2 -> V_50 ) ;
goto V_78;
}
V_7 = F_60 ( V_32 ) ;
if ( V_7 )
goto V_79;
if ( V_2 -> V_3 -> V_46 )
V_2 -> V_3 -> V_46 ( V_2 ) ;
V_7 = F_61 ( V_61 , V_29 , NULL , & V_32 -> V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_26 -> V_8 , L_16 ) ;
goto V_80;
}
return 0 ;
V_80:
F_62 ( & V_32 -> V_8 , NULL ,
F_43 ) ;
F_63 ( V_32 ) ;
V_79:
F_64 ( V_2 -> V_50 , V_2 ) ;
V_78:
if ( V_2 -> V_3 -> V_81 )
V_2 -> V_3 -> V_81 ( V_2 ) ;
F_6 ( V_2 ) ;
V_69:
F_1 ( V_2 ) ;
V_68:
F_65 ( V_2 -> V_67 ) ;
return V_7 ;
}
static int F_66 ( struct V_25 * V_26 )
{
struct V_31 * V_32 = F_67 ( V_26 ) ;
struct V_1 * V_2 = F_33 ( V_32 ) ;
F_62 ( & V_32 -> V_8 , NULL ,
F_43 ) ;
F_63 ( V_32 ) ;
F_64 ( V_2 -> V_50 , V_2 ) ;
if ( V_2 -> V_3 -> V_81 )
V_2 -> V_3 -> V_81 ( V_2 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_65 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_68 ( struct V_58 * V_8 )
{
struct V_31 * V_32 = F_69 ( V_8 ) ;
struct V_1 * V_2 = F_33 ( V_32 ) ;
if ( V_2 -> V_3 -> V_81 )
V_2 -> V_3 -> V_81 ( V_2 ) ;
F_6 ( V_2 ) ;
F_65 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_70 ( struct V_58 * V_8 )
{
struct V_31 * V_32 = F_69 ( V_8 ) ;
struct V_1 * V_2 = F_33 ( V_32 ) ;
int V_7 ;
V_7 = F_56 ( V_2 -> V_67 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_8 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_3 -> V_46 )
V_2 -> V_3 -> V_46 ( V_2 ) ;
return 0 ;
}
