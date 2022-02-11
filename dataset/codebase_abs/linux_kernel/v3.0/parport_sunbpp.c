static void F_1 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 &= ~ V_8 ;
F_3 ( V_6 , & V_4 -> V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 |= V_8 ;
F_3 ( V_6 , & V_4 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned char V_9 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
F_6 ( V_9 , & V_4 -> V_10 ) ;
F_7 ( ( V_11 L_1 , V_9 ) ) ;
}
static unsigned char F_8 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
return F_9 ( & V_4 -> V_10 ) ;
}
static unsigned char F_10 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
unsigned char V_12 = 0 ;
unsigned char V_13 = F_9 ( & V_4 -> V_14 ) ;
unsigned char V_15 = F_9 ( & V_4 -> V_16 ) ;
if ( ! ( V_15 & V_17 ) )
V_12 |= V_18 ;
if ( ! ( V_15 & V_19 ) )
V_12 |= V_20 ;
if ( ! ( V_15 & V_21 ) )
V_12 |= V_22 ;
if ( V_13 & V_23 )
V_12 |= V_24 ;
if ( ! ( V_13 & V_25 ) )
V_12 |= V_26 ;
F_7 ( ( V_11 L_2 , V_13 , V_15 ) ) ;
F_7 ( ( V_11 L_3 , V_12 ) ) ;
return V_12 ;
}
static unsigned char F_11 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
unsigned char V_12 = 0 ;
unsigned char V_13 = F_9 ( & V_4 -> V_14 ) ;
unsigned char V_27 = F_9 ( & V_4 -> V_28 ) ;
if ( ! ( V_13 & V_29 ) )
V_12 |= V_30 ;
if ( ! ( V_27 & V_31 ) )
V_12 |= V_32 ;
if ( ! ( V_27 & V_33 ) )
V_12 |= V_34 ;
if ( V_27 & V_35 )
V_12 |= V_36 ;
F_7 ( ( V_11 L_4 , V_13 , V_27 ) ) ;
F_7 ( ( V_11 L_5 , V_12 ) ) ;
return V_12 ;
}
static unsigned char F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 ) ;
}
static unsigned char F_13 ( struct V_1 * V_2 ,
unsigned char V_37 ,
unsigned char V_38 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
unsigned char V_13 = F_9 ( & V_4 -> V_14 ) ;
unsigned char V_27 = F_9 ( & V_4 -> V_28 ) ;
F_7 ( ( V_11 L_6 ,
V_13 , V_27 ) ) ;
if ( V_37 & V_30 ) {
if ( V_38 & V_30 ) {
V_13 &= ~ V_29 ;
} else {
V_13 |= V_29 ;
}
}
if ( V_37 & V_32 ) {
if ( V_38 & V_32 ) {
V_27 &= ~ V_31 ;
} else {
V_27 |= V_31 ;
}
}
if ( V_37 & V_34 ) {
if ( V_38 & V_34 ) {
V_27 &= ~ V_33 ;
} else {
V_27 |= V_33 ;
}
}
if ( V_37 & V_36 ) {
if ( V_38 & V_36 ) {
V_27 |= V_35 ;
} else {
V_27 &= ~ V_35 ;
}
}
F_6 ( V_27 , & V_4 -> V_28 ) ;
F_6 ( V_13 , & V_4 -> V_14 ) ;
F_7 ( ( V_11 L_7 ,
V_13 , V_27 ) ) ;
return F_12 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned char V_9 )
{
const unsigned char V_39 = ( V_30 |
V_32 |
V_34 |
V_36 ) ;
F_13 ( V_2 , V_39 , V_9 & V_39 ) ;
}
static unsigned char F_15 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
unsigned char V_13 = F_9 ( & V_4 -> V_14 ) ;
F_7 ( ( V_11 L_8 ) ) ;
V_13 &= ~ V_40 ;
F_6 ( V_13 , & V_4 -> V_14 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
T_3 V_38 = F_9 ( & V_4 -> V_14 ) ;
F_7 ( ( V_11 L_9 ) ) ;
V_38 |= V_40 ;
F_6 ( V_38 , & V_4 -> V_14 ) ;
}
static void F_18 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
V_44 -> V_45 . V_46 . V_47 = 0xc ;
V_44 -> V_45 . V_46 . V_48 = 0x0 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
V_44 -> V_45 . V_46 . V_47 = F_12 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_14 ( V_2 , V_44 -> V_45 . V_46 . V_47 ) ;
}
static int T_4 F_21 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_3 T_1 * V_4 ;
int V_53 , V_54 , V_55 = 0 , V_56 ;
unsigned char V_13 ;
void T_1 * V_5 ;
struct V_1 * V_2 ;
V_53 = V_50 -> V_57 . V_58 [ 0 ] ;
V_5 = F_22 ( & V_50 -> V_59 [ 0 ] , 0 ,
F_23 ( & V_50 -> V_59 [ 0 ] ) ,
L_10 ) ;
if ( ! V_5 )
return - V_60 ;
V_56 = F_23 ( & V_50 -> V_59 [ 0 ] ) ;
V_54 = V_61 ;
V_52 = F_24 ( sizeof( struct V_51 ) , V_62 ) ;
if ( ! V_52 )
goto V_63;
memcpy ( V_52 , & V_64 , sizeof( struct V_51 ) ) ;
F_7 ( ( L_11 ) ) ;
if ( ! ( V_2 = F_25 ( ( unsigned long ) V_5 , V_53 , V_54 , V_52 ) ) )
goto V_65;
V_2 -> V_56 = V_56 ;
V_2 -> V_42 = & V_50 -> V_42 ;
if ( ( V_55 = F_26 ( V_2 -> V_53 , V_66 ,
V_67 , V_2 -> V_68 , V_2 ) ) != 0 ) {
goto V_69;
}
F_4 ( V_2 ) ;
V_4 = (struct V_3 T_1 * ) V_2 -> V_5 ;
V_13 = F_9 ( & V_4 -> V_14 ) ;
V_13 &= ~ V_40 ;
F_6 ( V_13 , & V_4 -> V_14 ) ;
F_27 ( V_70 L_12 , V_2 -> V_68 , V_2 -> V_5 ) ;
F_28 ( & V_50 -> V_42 , V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
V_69:
F_30 ( V_2 ) ;
V_65:
F_31 ( V_52 ) ;
V_63:
F_32 ( & V_50 -> V_59 [ 0 ] , V_5 , V_56 ) ;
return V_55 ;
}
static int T_5 F_33 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_34 ( & V_50 -> V_42 ) ;
struct V_51 * V_52 = V_2 -> V_52 ;
F_35 ( V_2 ) ;
if ( V_2 -> V_53 != V_71 ) {
F_1 ( V_2 ) ;
F_36 ( V_2 -> V_53 , V_2 ) ;
}
F_32 ( & V_50 -> V_59 [ 0 ] , ( void T_1 * ) V_2 -> V_5 , V_2 -> V_56 ) ;
F_30 ( V_2 ) ;
F_31 ( V_52 ) ;
F_28 ( & V_50 -> V_42 , NULL ) ;
return 0 ;
}
static int T_6 F_37 ( void )
{
return F_38 ( & V_72 ) ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_72 ) ;
}
