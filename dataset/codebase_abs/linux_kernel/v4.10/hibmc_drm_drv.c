static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 -> V_6 ;
F_2 ( F_3 ( 1 ) ,
V_5 -> V_7 + V_8 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 -> V_6 ;
F_2 ( F_3 ( 0 ) ,
V_5 -> V_7 + V_8 ) ;
}
T_1 F_5 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
struct V_4 * V_5 =
(struct V_4 * ) V_2 -> V_6 ;
T_2 V_11 ;
V_11 = F_6 ( V_5 -> V_7 + V_12 ) ;
if ( V_11 & F_7 ( 1 ) ) {
F_2 ( F_7 ( 1 ) ,
V_5 -> V_7 + V_12 ) ;
F_8 ( V_2 , 0 ) ;
}
return V_13 ;
}
static int T_3 F_9 ( struct V_14 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_1 * V_17 = F_11 ( V_16 ) ;
struct V_4 * V_5 = V_17 -> V_6 ;
F_12 ( V_17 ) ;
V_5 -> V_18 = F_13 ( V_17 ) ;
if ( F_14 ( V_5 -> V_18 ) ) {
F_15 ( L_1 ,
F_16 ( V_5 -> V_18 ) ) ;
F_17 ( V_17 ) ;
return F_16 ( V_5 -> V_18 ) ;
}
return 0 ;
}
static int T_3 F_18 ( struct V_14 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_1 * V_17 = F_11 ( V_16 ) ;
struct V_4 * V_5 = V_17 -> V_6 ;
F_19 ( V_17 , V_5 -> V_18 ) ;
F_17 ( V_17 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_19 ;
F_21 ( V_5 -> V_2 ) ;
V_5 -> V_20 = true ;
V_5 -> V_2 -> V_21 . V_22 = 0 ;
V_5 -> V_2 -> V_21 . V_23 = 0 ;
V_5 -> V_2 -> V_21 . V_24 = 1920 ;
V_5 -> V_2 -> V_21 . V_25 = 1440 ;
V_5 -> V_2 -> V_21 . V_26 = V_5 -> V_26 ;
V_5 -> V_2 -> V_21 . V_27 = 24 ;
V_5 -> V_2 -> V_21 . V_28 = 0 ;
V_5 -> V_2 -> V_21 . V_29 = ( void * ) & V_30 ;
V_19 = F_22 ( V_5 ) ;
if ( V_19 ) {
F_15 ( L_2 , V_19 ) ;
return V_19 ;
}
V_19 = F_23 ( V_5 ) ;
if ( V_19 ) {
F_15 ( L_3 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( V_5 -> V_20 ) {
F_25 ( V_5 -> V_2 ) ;
V_5 -> V_20 = false ;
}
}
void F_26 ( struct V_4 * V_5 ,
unsigned int V_31 )
{
unsigned int V_32 = 0 ;
void T_4 * V_7 = V_5 -> V_7 ;
unsigned int V_33 = 1 ;
if ( V_31 > V_34 )
return;
if ( V_31 == V_34 )
V_33 = 0 ;
V_32 = F_6 ( V_7 + V_35 ) ;
V_32 &= ~ ( V_36 |
V_37 ) ;
V_32 |= F_27 ( V_38 , V_31 ) ;
V_32 |= F_27 ( V_39 , V_33 ) ;
F_2 ( V_32 , V_7 + V_35 ) ;
}
void F_28 ( struct V_4 * V_5 , unsigned int V_40 )
{
unsigned int V_41 ;
unsigned int V_42 ;
void T_4 * V_7 = V_5 -> V_7 ;
V_42 = ( F_6 ( V_7 + V_35 ) &
V_36 ) >> V_43 ;
switch ( V_42 ) {
case V_44 :
V_41 = V_45 ;
break;
case V_46 :
V_41 = V_47 ;
break;
default:
V_41 = V_45 ;
break;
}
F_2 ( V_40 , V_7 + V_41 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
unsigned int V_48 ;
F_26 ( V_5 , V_44 ) ;
V_48 = F_6 ( V_5 -> V_7 + V_49 ) ;
V_48 &= ~ V_50 ;
V_48 &= ~ V_51 ;
V_48 |= F_30 ( 1 ) ;
V_48 |= F_31 ( 1 ) ;
F_28 ( V_5 , V_48 ) ;
V_48 = F_6 ( V_5 -> V_7 + V_52 ) ;
V_48 &= ~ V_53 ;
V_48 |= F_32 ( 0 ) ;
F_2 ( V_48 , V_5 -> V_7 + V_52 ) ;
V_48 &= ~ V_53 ;
V_48 |= F_32 ( 1 ) ;
F_2 ( V_48 , V_5 -> V_7 + V_52 ) ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_5 V_54 , V_55 , V_56 , V_57 ;
V_56 = F_34 ( V_16 , 1 ) ;
V_57 = F_35 ( V_16 , 1 ) ;
V_5 -> V_7 = F_36 ( V_2 -> V_2 , V_56 , V_57 ) ;
if ( ! V_5 -> V_7 ) {
F_15 ( L_4 ) ;
return - V_58 ;
}
V_54 = F_34 ( V_16 , 0 ) ;
V_55 = F_35 ( V_16 , 0 ) ;
V_5 -> V_59 = F_37 ( V_2 -> V_2 , V_54 , V_55 ) ;
if ( ! V_5 -> V_59 ) {
F_15 ( L_5 ) ;
return - V_58 ;
}
V_5 -> V_26 = V_54 ;
V_5 -> V_60 = V_55 ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 )
{
int V_19 ;
V_19 = F_33 ( V_5 ) ;
if ( V_19 )
return V_19 ;
F_29 ( V_5 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_40 ( V_5 ) ;
if ( V_2 -> V_61 )
F_41 ( V_2 ) ;
if ( V_5 -> V_62 )
F_42 ( V_2 -> V_16 ) ;
F_43 ( V_2 ) ;
F_24 ( V_5 ) ;
F_44 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_19 ;
V_5 = F_46 ( V_2 -> V_2 , sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 ) {
F_15 ( L_6 ) ;
return - V_58 ;
}
V_2 -> V_6 = V_5 ;
V_5 -> V_2 = V_2 ;
V_19 = F_38 ( V_5 ) ;
if ( V_19 )
goto V_64;
V_19 = F_47 ( V_5 ) ;
if ( V_19 )
goto V_64;
V_19 = F_20 ( V_5 ) ;
if ( V_19 )
goto V_64;
V_19 = F_48 ( V_2 , V_2 -> V_21 . V_65 ) ;
if ( V_19 ) {
F_15 ( L_7 , V_19 ) ;
goto V_64;
}
V_5 -> V_62 = 0 ;
V_19 = F_49 ( V_2 -> V_16 ) ;
if ( V_19 ) {
F_50 ( L_8 , V_19 ) ;
} else {
V_5 -> V_62 = 1 ;
V_19 = F_51 ( V_2 , V_2 -> V_16 -> V_9 ) ;
if ( V_19 )
F_50 ( L_9 , V_19 ) ;
}
F_52 ( V_2 ) ;
V_19 = F_53 ( V_5 ) ;
if ( V_19 ) {
F_15 ( L_10 , V_19 ) ;
goto V_64;
}
return 0 ;
V_64:
F_39 ( V_2 ) ;
F_15 ( L_11 , V_19 ) ;
return V_19 ;
}
static int F_54 ( struct V_15 * V_16 ,
const struct V_66 * V_67 )
{
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_55 ( & V_68 , & V_16 -> V_2 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( L_12 ) ;
return F_16 ( V_2 ) ;
}
V_2 -> V_16 = V_16 ;
F_56 ( V_16 , V_2 ) ;
V_19 = F_57 ( V_16 ) ;
if ( V_19 ) {
F_15 ( L_13 , V_19 ) ;
goto V_69;
}
V_19 = F_45 ( V_2 ) ;
if ( V_19 ) {
F_15 ( L_14 , V_19 ) ;
goto V_70;
}
V_19 = F_58 ( V_2 , 0 ) ;
if ( V_19 ) {
F_15 ( L_15 ,
V_19 ) ;
goto V_71;
}
return 0 ;
V_71:
F_39 ( V_2 ) ;
V_70:
F_59 ( V_16 ) ;
V_69:
F_60 ( V_2 ) ;
return V_19 ;
}
static void F_61 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
F_62 ( V_2 ) ;
F_39 ( V_2 ) ;
F_60 ( V_2 ) ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_72 ) ;
}
static void T_7 F_65 ( void )
{
return F_66 ( & V_72 ) ;
}
