T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_6 -> V_9 + V_10 ) ;
if ( V_8 & F_3 ( 1 ) ) {
F_4 ( F_3 ( 1 ) ,
V_6 -> V_9 + V_10 ) ;
F_5 ( V_4 , 0 ) ;
}
return V_11 ;
}
static int T_3 F_6 ( struct V_12 * V_4 )
{
struct V_13 * V_14 = F_7 ( V_4 ) ;
struct V_3 * V_15 = F_8 ( V_14 ) ;
struct V_5 * V_6 = V_15 -> V_7 ;
F_9 ( V_15 ) ;
V_6 -> V_16 = F_10 ( V_15 ) ;
if ( F_11 ( V_6 -> V_16 ) ) {
F_12 ( L_1 ,
F_13 ( V_6 -> V_16 ) ) ;
F_14 ( V_15 ) ;
return F_13 ( V_6 -> V_16 ) ;
}
return 0 ;
}
static int T_3 F_15 ( struct V_12 * V_4 )
{
struct V_13 * V_14 = F_7 ( V_4 ) ;
struct V_3 * V_15 = F_8 ( V_14 ) ;
struct V_5 * V_6 = V_15 -> V_7 ;
F_16 ( V_15 , V_6 -> V_16 ) ;
F_14 ( V_15 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
int V_17 ;
F_18 ( V_6 -> V_4 ) ;
V_6 -> V_18 = true ;
V_6 -> V_4 -> V_19 . V_20 = 0 ;
V_6 -> V_4 -> V_19 . V_21 = 0 ;
V_6 -> V_4 -> V_19 . V_22 = 1920 ;
V_6 -> V_4 -> V_19 . V_23 = 1440 ;
V_6 -> V_4 -> V_19 . V_24 = V_6 -> V_24 ;
V_6 -> V_4 -> V_19 . V_25 = 24 ;
V_6 -> V_4 -> V_19 . V_26 = 0 ;
V_6 -> V_4 -> V_19 . V_27 = ( void * ) & V_28 ;
V_17 = F_19 ( V_6 ) ;
if ( V_17 ) {
F_12 ( L_2 , V_17 ) ;
return V_17 ;
}
V_17 = F_20 ( V_6 ) ;
if ( V_17 ) {
F_12 ( L_3 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
static void F_21 ( struct V_5 * V_6 )
{
if ( V_6 -> V_18 ) {
F_22 ( V_6 -> V_4 ) ;
V_6 -> V_18 = false ;
}
}
void F_23 ( struct V_5 * V_6 ,
unsigned int V_29 )
{
unsigned int V_30 = 0 ;
void T_4 * V_9 = V_6 -> V_9 ;
unsigned int V_31 = 1 ;
if ( V_29 > V_32 )
return;
if ( V_29 == V_32 )
V_31 = 0 ;
V_30 = F_2 ( V_9 + V_33 ) ;
V_30 &= ~ ( V_34 |
V_35 ) ;
V_30 |= F_24 ( V_36 , V_29 ) ;
V_30 |= F_24 ( V_37 , V_31 ) ;
F_4 ( V_30 , V_9 + V_33 ) ;
}
void F_25 ( struct V_5 * V_6 , unsigned int V_38 )
{
unsigned int V_39 ;
unsigned int V_40 ;
void T_4 * V_9 = V_6 -> V_9 ;
V_40 = ( F_2 ( V_9 + V_33 ) &
V_34 ) >> V_41 ;
switch ( V_40 ) {
case V_42 :
V_39 = V_43 ;
break;
case V_44 :
V_39 = V_45 ;
break;
default:
V_39 = V_43 ;
break;
}
F_4 ( V_38 , V_9 + V_39 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
unsigned int V_46 ;
F_23 ( V_6 , V_42 ) ;
V_46 = F_2 ( V_6 -> V_9 + V_47 ) ;
V_46 &= ~ V_48 ;
V_46 &= ~ V_49 ;
V_46 |= F_27 ( 1 ) ;
V_46 |= F_28 ( 1 ) ;
F_25 ( V_6 , V_46 ) ;
V_46 = F_2 ( V_6 -> V_9 + V_50 ) ;
V_46 &= ~ V_51 ;
V_46 |= F_29 ( 0 ) ;
F_4 ( V_46 , V_6 -> V_9 + V_50 ) ;
V_46 &= ~ V_51 ;
V_46 |= F_29 ( 1 ) ;
F_4 ( V_46 , V_6 -> V_9 + V_50 ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_5 V_52 , V_53 , V_54 , V_55 ;
V_54 = F_31 ( V_14 , 1 ) ;
V_55 = F_32 ( V_14 , 1 ) ;
V_6 -> V_9 = F_33 ( V_4 -> V_4 , V_54 , V_55 ) ;
if ( ! V_6 -> V_9 ) {
F_12 ( L_4 ) ;
return - V_56 ;
}
V_52 = F_31 ( V_14 , 0 ) ;
V_53 = F_32 ( V_14 , 0 ) ;
V_6 -> V_57 = F_34 ( V_4 -> V_4 , V_52 , V_53 ) ;
if ( ! V_6 -> V_57 ) {
F_12 ( L_5 ) ;
return - V_56 ;
}
V_6 -> V_24 = V_52 ;
V_6 -> V_58 = V_53 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
int V_17 ;
V_17 = F_30 ( V_6 ) ;
if ( V_17 )
return V_17 ;
F_26 ( V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_37 ( V_6 ) ;
F_38 ( V_4 ) ;
if ( V_4 -> V_59 )
F_39 ( V_4 ) ;
if ( V_6 -> V_60 )
F_40 ( V_4 -> V_14 ) ;
F_21 ( V_6 ) ;
F_41 ( V_6 ) ;
V_4 -> V_7 = NULL ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_17 ;
V_6 = F_43 ( V_4 -> V_4 , sizeof( * V_6 ) , V_61 ) ;
if ( ! V_6 ) {
F_12 ( L_6 ) ;
return - V_56 ;
}
V_4 -> V_7 = V_6 ;
V_6 -> V_4 = V_4 ;
V_17 = F_35 ( V_6 ) ;
if ( V_17 )
goto V_62;
V_17 = F_44 ( V_6 ) ;
if ( V_17 )
goto V_62;
V_17 = F_17 ( V_6 ) ;
if ( V_17 )
goto V_62;
V_17 = F_45 ( V_4 , V_4 -> V_19 . V_63 ) ;
if ( V_17 ) {
F_12 ( L_7 , V_17 ) ;
goto V_62;
}
V_6 -> V_60 = 0 ;
V_17 = F_46 ( V_4 -> V_14 ) ;
if ( V_17 ) {
F_47 ( L_8 , V_17 ) ;
} else {
V_6 -> V_60 = 1 ;
V_17 = F_48 ( V_4 , V_4 -> V_14 -> V_1 ) ;
if ( V_17 )
F_47 ( L_9 , V_17 ) ;
}
F_49 ( V_4 ) ;
V_17 = F_50 ( V_6 ) ;
if ( V_17 ) {
F_12 ( L_10 , V_17 ) ;
goto V_62;
}
return 0 ;
V_62:
F_36 ( V_4 ) ;
F_12 ( L_11 , V_17 ) ;
return V_17 ;
}
static int F_51 ( struct V_13 * V_14 ,
const struct V_64 * V_65 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_52 ( & V_66 , & V_14 -> V_4 ) ;
if ( F_11 ( V_4 ) ) {
F_12 ( L_12 ) ;
return F_13 ( V_4 ) ;
}
V_4 -> V_14 = V_14 ;
F_53 ( V_14 , V_4 ) ;
V_17 = F_54 ( V_14 ) ;
if ( V_17 ) {
F_12 ( L_13 , V_17 ) ;
goto V_67;
}
V_17 = F_42 ( V_4 ) ;
if ( V_17 ) {
F_12 ( L_14 , V_17 ) ;
goto V_68;
}
V_17 = F_55 ( V_4 , 0 ) ;
if ( V_17 ) {
F_12 ( L_15 ,
V_17 ) ;
goto V_69;
}
return 0 ;
V_69:
F_36 ( V_4 ) ;
V_68:
F_56 ( V_14 ) ;
V_67:
F_57 ( V_4 ) ;
return V_17 ;
}
static void F_58 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_8 ( V_14 ) ;
F_59 ( V_4 ) ;
F_36 ( V_4 ) ;
F_57 ( V_4 ) ;
}
static int T_6 F_60 ( void )
{
return F_61 ( & V_70 ) ;
}
static void T_7 F_62 ( void )
{
return F_63 ( & V_70 ) ;
}
