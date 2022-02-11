static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 &= V_8 ;
if ( ! V_5 )
return V_9 ;
if ( V_5 & F_3 ( V_10 ) ) {
struct V_11 * V_12 = V_4 -> V_12 ;
unsigned int V_13 = V_12 -> V_14 - V_4 -> V_13 ;
unsigned int V_15 ;
T_2 V_16 ;
V_13 = F_4 (unsigned int, tx_bytes, M_TX_RX_FIFO_SIZE) ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
unsigned int V_17 = V_4 -> V_13 + V_15 ;
V_16 = V_12 -> V_18 [ V_17 ] ;
if ( V_17 == V_12 -> V_14 - 1 ) {
T_2 V_19 ;
V_16 |= F_3 ( V_20 ) ;
V_19 = F_2 ( V_4 -> V_6 + V_21 ) ;
V_19 &= ~ F_3 ( V_22 ) ;
F_5 ( V_19 , V_4 -> V_6 + V_21 ) ;
}
F_5 ( V_16 , V_4 -> V_6 + V_23 ) ;
}
V_4 -> V_13 += V_13 ;
}
if ( V_5 & F_3 ( V_24 ) ) {
V_4 -> V_25 = 1 ;
F_6 ( & V_4 -> V_26 ) ;
}
F_5 ( V_5 , V_4 -> V_6 + V_7 ) ;
return V_27 ;
}
static int F_7 ( struct V_3 * V_4 )
{
T_2 V_16 ;
V_16 = F_2 ( V_4 -> V_6 + V_28 ) ;
V_16 |= 1 << V_29 ;
V_16 &= ~ ( 1 << V_30 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_28 ) ;
F_8 ( 100 ) ;
V_16 &= ~ ( 1 << V_29 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_28 ) ;
V_16 = ( 1 << V_31 ) | ( 1 << V_32 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_33 ) ;
F_5 ( 0 , V_4 -> V_6 + V_21 ) ;
F_5 ( 0xffffffff , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_9 ( struct V_3 * V_4 ,
bool V_34 )
{
T_2 V_16 ;
V_16 = F_2 ( V_4 -> V_6 + V_28 ) ;
if ( V_34 )
V_16 |= F_3 ( V_30 ) ;
else
V_16 &= ~ F_3 ( V_30 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_28 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
T_2 V_16 ;
V_16 = F_2 ( V_4 -> V_6 + V_35 ) ;
V_16 = ( V_16 >> V_36 ) & V_37 ;
switch ( V_16 ) {
case V_38 :
return 0 ;
case V_39 :
F_11 ( V_4 -> V_40 , L_1 ) ;
return - V_41 ;
case V_42 :
F_11 ( V_4 -> V_40 , L_2 , V_12 -> V_43 ) ;
return - V_44 ;
case V_45 :
F_11 ( V_4 -> V_40 , L_3 ) ;
return - V_44 ;
case V_46 :
F_11 ( V_4 -> V_40 , L_4 ) ;
return - V_47 ;
default:
F_11 ( V_4 -> V_40 , L_5 , V_16 ) ;
F_9 ( V_4 , false ) ;
F_7 ( V_4 ) ;
F_9 ( V_4 , true ) ;
return - V_48 ;
}
}
static int F_12 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
int V_49 , V_15 ;
T_3 V_43 ;
T_2 V_16 ;
unsigned int V_13 ;
unsigned long V_50 = F_13 ( V_51 ) ;
if ( ! ! ( F_2 ( V_4 -> V_6 + V_35 ) &
F_3 ( V_52 ) ) ) {
F_14 ( V_4 -> V_40 , L_6 ) ;
return - V_53 ;
}
V_4 -> V_12 = V_12 ;
V_43 = V_12 -> V_43 << 1 | ( V_12 -> V_54 & V_55 ? 1 : 0 ) ;
F_5 ( V_43 , V_4 -> V_6 + V_23 ) ;
V_13 = F_4 (unsigned int, msg->len, M_TX_RX_FIFO_SIZE - 1 ) ;
if ( ! ( V_12 -> V_54 & V_55 ) ) {
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
V_16 = V_12 -> V_18 [ V_15 ] ;
if ( V_15 == V_12 -> V_14 - 1 )
V_16 |= 1 << V_20 ;
F_5 ( V_16 , V_4 -> V_6 + V_23 ) ;
}
V_4 -> V_13 = V_13 ;
}
F_15 ( & V_4 -> V_26 ) ;
V_4 -> V_25 = 0 ;
V_16 = F_3 ( V_56 ) ;
if ( ! ( V_12 -> V_54 & V_55 ) &&
V_12 -> V_14 > V_4 -> V_13 )
V_16 |= F_3 ( V_22 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_21 ) ;
V_16 = F_3 ( V_52 ) ;
if ( V_12 -> V_54 & V_55 ) {
V_16 |= ( V_57 << V_58 ) |
( V_12 -> V_14 << V_59 ) ;
} else {
V_16 |= ( V_60 << V_58 ) ;
}
F_5 ( V_16 , V_4 -> V_6 + V_35 ) ;
V_50 = F_16 ( & V_4 -> V_26 , V_50 ) ;
F_5 ( 0 , V_4 -> V_6 + V_21 ) ;
F_2 ( V_4 -> V_6 + V_21 ) ;
F_17 ( V_4 -> V_1 ) ;
if ( ! V_50 && ! V_4 -> V_25 ) {
F_18 ( V_4 -> V_40 , L_7 ) ;
V_16 = ( 1 << V_31 ) |
( 1 << V_32 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_33 ) ;
return - V_47 ;
}
V_49 = F_10 ( V_4 , V_12 ) ;
if ( V_49 ) {
V_16 = ( 1 << V_31 ) |
( 1 << V_32 ) ;
F_5 ( V_16 , V_4 -> V_6 + V_33 ) ;
return V_49 ;
}
if ( V_12 -> V_54 & V_55 ) {
for ( V_15 = 0 ; V_15 < V_12 -> V_14 ; V_15 ++ ) {
V_12 -> V_18 [ V_15 ] = ( F_2 ( V_4 -> V_6 + V_61 ) >>
V_62 ) & V_63 ;
}
}
return 0 ;
}
static int F_19 ( struct V_64 * V_65 ,
struct V_11 V_66 [] , int V_67 )
{
struct V_3 * V_4 = F_20 ( V_65 ) ;
int V_49 , V_15 ;
for ( V_15 = 0 ; V_15 < V_67 ; V_15 ++ ) {
V_49 = F_12 ( V_4 , & V_66 [ V_15 ] ) ;
if ( V_49 ) {
F_11 ( V_4 -> V_40 , L_8 ) ;
return V_49 ;
}
}
return V_67 ;
}
static T_4 F_21 ( struct V_64 * V_68 )
{
return V_69 | V_70 ;
}
static int F_22 ( struct V_3 * V_4 )
{
unsigned int V_71 ;
T_2 V_16 ;
int V_49 = F_23 ( V_4 -> V_40 -> V_72 ,
L_9 , & V_71 ) ;
if ( V_49 < 0 ) {
F_24 ( V_4 -> V_40 ,
L_10 ) ;
V_71 = 100000 ;
}
if ( V_71 < 100000 ) {
F_18 ( V_4 -> V_40 , L_11 ,
V_71 ) ;
F_18 ( V_4 -> V_40 ,
L_12 ) ;
return - V_73 ;
} else if ( V_71 < 400000 ) {
V_71 = 100000 ;
} else {
V_71 = 400000 ;
}
V_4 -> V_71 = V_71 ;
V_16 = F_2 ( V_4 -> V_6 + V_74 ) ;
V_16 &= ~ ( 1 << V_75 ) ;
V_16 |= ( V_71 == 400000 ) << V_75 ;
F_5 ( V_16 , V_4 -> V_6 + V_74 ) ;
F_24 ( V_4 -> V_40 , L_13 , V_71 ) ;
return 0 ;
}
static int F_25 ( struct V_76 * V_77 )
{
int V_1 , V_49 = 0 ;
struct V_3 * V_4 ;
struct V_64 * V_68 ;
struct V_78 * V_79 ;
V_4 = F_26 ( & V_77 -> V_80 , sizeof( * V_4 ) ,
V_81 ) ;
if ( ! V_4 )
return - V_82 ;
F_27 ( V_77 , V_4 ) ;
V_4 -> V_40 = & V_77 -> V_80 ;
F_28 ( & V_4 -> V_26 ) ;
V_79 = F_29 ( V_77 , V_83 , 0 ) ;
V_4 -> V_6 = F_30 ( V_4 -> V_40 , V_79 ) ;
if ( F_31 ( V_4 -> V_6 ) )
return F_32 ( V_4 -> V_6 ) ;
V_49 = F_7 ( V_4 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_22 ( V_4 ) ;
if ( V_49 )
return V_49 ;
V_1 = F_33 ( V_77 , 0 ) ;
if ( V_1 <= 0 ) {
F_18 ( V_4 -> V_40 , L_14 ) ;
return V_1 ;
}
V_4 -> V_1 = V_1 ;
V_49 = F_34 ( V_4 -> V_40 , V_1 , F_1 , 0 ,
V_77 -> V_84 , V_4 ) ;
if ( V_49 < 0 ) {
F_18 ( V_4 -> V_40 , L_15 , V_1 ) ;
return V_49 ;
}
F_9 ( V_4 , true ) ;
V_68 = & V_4 -> V_65 ;
F_35 ( V_68 , V_4 ) ;
F_36 ( V_68 -> V_84 , L_16 , sizeof( V_68 -> V_84 ) ) ;
V_68 -> V_85 = & V_86 ;
V_68 -> V_87 = & V_88 ;
V_68 -> V_80 . V_89 = & V_77 -> V_80 ;
V_68 -> V_80 . V_72 = V_77 -> V_80 . V_72 ;
V_49 = F_37 ( V_68 ) ;
if ( V_49 ) {
F_18 ( V_4 -> V_40 , L_17 ) ;
return V_49 ;
}
return 0 ;
}
static int F_38 ( struct V_76 * V_77 )
{
struct V_3 * V_4 = F_39 ( V_77 ) ;
F_5 ( 0 , V_4 -> V_6 + V_21 ) ;
F_2 ( V_4 -> V_6 + V_21 ) ;
F_17 ( V_4 -> V_1 ) ;
F_40 ( & V_4 -> V_65 ) ;
F_9 ( V_4 , false ) ;
return 0 ;
}
static int F_41 ( struct V_40 * V_80 )
{
struct V_76 * V_77 = F_42 ( V_80 ) ;
struct V_3 * V_4 = F_39 ( V_77 ) ;
F_5 ( 0 , V_4 -> V_6 + V_21 ) ;
F_2 ( V_4 -> V_6 + V_21 ) ;
F_17 ( V_4 -> V_1 ) ;
F_9 ( V_4 , false ) ;
return 0 ;
}
static int F_43 ( struct V_40 * V_80 )
{
struct V_76 * V_77 = F_42 ( V_80 ) ;
struct V_3 * V_4 = F_39 ( V_77 ) ;
int V_49 ;
T_2 V_16 ;
V_49 = F_7 ( V_4 ) ;
if ( V_49 )
return V_49 ;
V_16 = F_2 ( V_4 -> V_6 + V_74 ) ;
V_16 &= ~ ( 1 << V_75 ) ;
V_16 |= ( V_4 -> V_71 == 400000 ) << V_75 ;
F_5 ( V_16 , V_4 -> V_6 + V_74 ) ;
F_9 ( V_4 , true ) ;
return 0 ;
}
