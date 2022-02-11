static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 &= V_8 ;
if ( ! V_5 )
return V_9 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
V_4 -> V_10 = 1 ;
F_4 ( & V_4 -> V_11 ) ;
return V_12 ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
T_2 V_15 ;
V_15 = F_2 ( V_4 -> V_6 + V_16 ) ;
V_15 = ( V_15 >> V_17 ) & V_18 ;
switch ( V_15 ) {
case V_19 :
return 0 ;
case V_20 :
F_6 ( V_4 -> V_21 , L_1 ) ;
return - V_22 ;
case V_23 :
F_6 ( V_4 -> V_21 , L_2 , V_14 -> V_24 ) ;
return - V_25 ;
case V_26 :
F_6 ( V_4 -> V_21 , L_3 ) ;
return - V_25 ;
case V_27 :
F_6 ( V_4 -> V_21 , L_4 ) ;
return - V_28 ;
default:
F_6 ( V_4 -> V_21 , L_5 , V_15 ) ;
return - V_29 ;
}
}
static int F_7 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
int V_30 , V_31 ;
T_3 V_24 ;
T_2 V_15 ;
unsigned long V_32 = F_8 ( V_33 ) ;
if ( V_14 -> V_34 > V_35 - 1 ) {
F_9 ( V_4 -> V_21 ,
L_6 ,
V_35 - 1 ) ;
return - V_36 ;
}
if ( ! ! ( F_2 ( V_4 -> V_6 + V_16 ) &
F_10 ( V_37 ) ) ) {
F_11 ( V_4 -> V_21 , L_7 ) ;
return - V_38 ;
}
V_24 = V_14 -> V_24 << 1 | ( V_14 -> V_39 & V_40 ? 1 : 0 ) ;
F_3 ( V_24 , V_4 -> V_6 + V_41 ) ;
if ( ! ( V_14 -> V_39 & V_40 ) ) {
for ( V_31 = 0 ; V_31 < V_14 -> V_34 ; V_31 ++ ) {
V_15 = V_14 -> V_42 [ V_31 ] ;
if ( V_31 == V_14 -> V_34 - 1 )
V_15 |= 1 << V_43 ;
F_3 ( V_15 , V_4 -> V_6 + V_41 ) ;
}
}
F_12 ( & V_4 -> V_11 ) ;
V_4 -> V_10 = 0 ;
F_3 ( 1 << V_44 , V_4 -> V_6 + V_45 ) ;
V_15 = 1 << V_37 ;
if ( V_14 -> V_39 & V_40 ) {
V_15 |= ( V_46 << V_47 ) |
( V_14 -> V_34 << V_48 ) ;
} else {
V_15 |= ( V_49 << V_47 ) ;
}
F_3 ( V_15 , V_4 -> V_6 + V_16 ) ;
V_32 = F_13 ( & V_4 -> V_11 , V_32 ) ;
F_3 ( 0 , V_4 -> V_6 + V_45 ) ;
F_2 ( V_4 -> V_6 + V_45 ) ;
F_14 ( V_4 -> V_1 ) ;
if ( ! V_32 && ! V_4 -> V_10 ) {
F_9 ( V_4 -> V_21 , L_8 ) ;
V_15 = ( 1 << V_50 ) |
( 1 << V_51 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_52 ) ;
return - V_28 ;
}
V_30 = F_5 ( V_4 , V_14 ) ;
if ( V_30 ) {
V_15 = ( 1 << V_50 ) |
( 1 << V_51 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_52 ) ;
return V_30 ;
}
if ( V_14 -> V_39 & V_40 ) {
for ( V_31 = 0 ; V_31 < V_14 -> V_34 ; V_31 ++ ) {
V_14 -> V_42 [ V_31 ] = ( F_2 ( V_4 -> V_6 + V_53 ) >>
V_54 ) & V_55 ;
}
}
return 0 ;
}
static int F_15 ( struct V_56 * V_57 ,
struct V_13 V_58 [] , int V_59 )
{
struct V_3 * V_4 = F_16 ( V_57 ) ;
int V_30 , V_31 ;
for ( V_31 = 0 ; V_31 < V_59 ; V_31 ++ ) {
V_30 = F_7 ( V_4 , & V_58 [ V_31 ] ) ;
if ( V_30 ) {
F_6 ( V_4 -> V_21 , L_9 ) ;
return V_30 ;
}
}
return V_59 ;
}
static T_4 F_17 ( struct V_56 * V_60 )
{
return V_61 | V_62 ;
}
static int F_18 ( struct V_3 * V_4 )
{
unsigned int V_63 ;
T_2 V_15 ;
int V_30 = F_19 ( V_4 -> V_21 -> V_64 ,
L_10 , & V_63 ) ;
if ( V_30 < 0 ) {
F_20 ( V_4 -> V_21 ,
L_11 ) ;
V_63 = 100000 ;
}
if ( V_63 < 100000 ) {
F_9 ( V_4 -> V_21 , L_12 ,
V_63 ) ;
F_9 ( V_4 -> V_21 ,
L_13 ) ;
return - V_65 ;
} else if ( V_63 < 400000 ) {
V_63 = 100000 ;
} else {
V_63 = 400000 ;
}
V_15 = F_2 ( V_4 -> V_6 + V_66 ) ;
V_15 &= ~ ( 1 << V_67 ) ;
V_15 |= ( V_63 == 400000 ) << V_67 ;
F_3 ( V_15 , V_4 -> V_6 + V_66 ) ;
F_20 ( V_4 -> V_21 , L_14 , V_63 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
T_2 V_15 ;
V_15 = F_2 ( V_4 -> V_6 + V_68 ) ;
V_15 |= 1 << V_69 ;
V_15 &= ~ ( 1 << V_70 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_68 ) ;
F_22 ( 100 ) ;
V_15 &= ~ ( 1 << V_69 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_68 ) ;
V_15 = ( 1 << V_50 ) | ( 1 << V_51 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_52 ) ;
F_3 ( 0 , V_4 -> V_6 + V_45 ) ;
F_3 ( 0xffffffff , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 ,
bool V_71 )
{
T_2 V_15 ;
V_15 = F_2 ( V_4 -> V_6 + V_68 ) ;
if ( V_71 )
V_15 |= F_10 ( V_70 ) ;
else
V_15 &= ~ F_10 ( V_70 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_68 ) ;
}
static int F_24 ( struct V_72 * V_73 )
{
int V_1 , V_30 = 0 ;
struct V_3 * V_4 ;
struct V_56 * V_60 ;
struct V_74 * V_75 ;
V_4 = F_25 ( & V_73 -> V_76 , sizeof( * V_4 ) ,
V_77 ) ;
if ( ! V_4 )
return - V_78 ;
F_26 ( V_73 , V_4 ) ;
V_4 -> V_21 = & V_73 -> V_76 ;
F_27 ( & V_4 -> V_11 ) ;
V_75 = F_28 ( V_73 , V_79 , 0 ) ;
V_4 -> V_6 = F_29 ( V_4 -> V_21 , V_75 ) ;
if ( F_30 ( V_4 -> V_6 ) )
return F_31 ( V_4 -> V_6 ) ;
V_30 = F_21 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_18 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_1 = F_32 ( V_73 , 0 ) ;
if ( V_1 <= 0 ) {
F_9 ( V_4 -> V_21 , L_15 ) ;
return V_1 ;
}
V_4 -> V_1 = V_1 ;
V_30 = F_33 ( V_4 -> V_21 , V_1 , F_1 , 0 ,
V_73 -> V_80 , V_4 ) ;
if ( V_30 < 0 ) {
F_9 ( V_4 -> V_21 , L_16 , V_1 ) ;
return V_30 ;
}
F_23 ( V_4 , true ) ;
V_60 = & V_4 -> V_57 ;
F_34 ( V_60 , V_4 ) ;
F_35 ( V_60 -> V_80 , L_17 , sizeof( V_60 -> V_80 ) ) ;
V_60 -> V_81 = & V_82 ;
V_60 -> V_76 . V_83 = & V_73 -> V_76 ;
V_60 -> V_76 . V_64 = V_73 -> V_76 . V_64 ;
V_30 = F_36 ( V_60 ) ;
if ( V_30 ) {
F_9 ( V_4 -> V_21 , L_18 ) ;
return V_30 ;
}
return 0 ;
}
static int F_37 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_38 ( V_73 ) ;
F_3 ( 0 , V_4 -> V_6 + V_45 ) ;
F_2 ( V_4 -> V_6 + V_45 ) ;
F_14 ( V_4 -> V_1 ) ;
F_39 ( & V_4 -> V_57 ) ;
F_23 ( V_4 , false ) ;
return 0 ;
}
