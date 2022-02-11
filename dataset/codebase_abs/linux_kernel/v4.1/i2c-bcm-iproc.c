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
if ( ! ! ( F_2 ( V_4 -> V_6 + V_16 ) &
F_9 ( V_34 ) ) ) {
F_10 ( V_4 -> V_21 , L_6 ) ;
return - V_35 ;
}
V_24 = V_14 -> V_24 << 1 | ( V_14 -> V_36 & V_37 ? 1 : 0 ) ;
F_3 ( V_24 , V_4 -> V_6 + V_38 ) ;
if ( ! ( V_14 -> V_36 & V_37 ) ) {
for ( V_31 = 0 ; V_31 < V_14 -> V_39 ; V_31 ++ ) {
V_15 = V_14 -> V_40 [ V_31 ] ;
if ( V_31 == V_14 -> V_39 - 1 )
V_15 |= 1 << V_41 ;
F_3 ( V_15 , V_4 -> V_6 + V_38 ) ;
}
}
F_11 ( & V_4 -> V_11 ) ;
V_4 -> V_10 = 0 ;
F_3 ( 1 << V_42 , V_4 -> V_6 + V_43 ) ;
V_15 = 1 << V_34 ;
if ( V_14 -> V_36 & V_37 ) {
V_15 |= ( V_44 << V_45 ) |
( V_14 -> V_39 << V_46 ) ;
} else {
V_15 |= ( V_47 << V_45 ) ;
}
F_3 ( V_15 , V_4 -> V_6 + V_16 ) ;
V_32 = F_12 ( & V_4 -> V_11 , V_32 ) ;
F_3 ( 0 , V_4 -> V_6 + V_43 ) ;
F_2 ( V_4 -> V_6 + V_43 ) ;
F_13 ( V_4 -> V_1 ) ;
if ( ! V_32 && ! V_4 -> V_10 ) {
F_14 ( V_4 -> V_21 , L_7 ) ;
V_15 = ( 1 << V_48 ) |
( 1 << V_49 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_50 ) ;
return - V_28 ;
}
V_30 = F_5 ( V_4 , V_14 ) ;
if ( V_30 ) {
V_15 = ( 1 << V_48 ) |
( 1 << V_49 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_50 ) ;
return V_30 ;
}
if ( V_14 -> V_36 & V_37 ) {
for ( V_31 = 0 ; V_31 < V_14 -> V_39 ; V_31 ++ ) {
V_14 -> V_40 [ V_31 ] = ( F_2 ( V_4 -> V_6 + V_51 ) >>
V_52 ) & V_53 ;
}
}
return 0 ;
}
static int F_15 ( struct V_54 * V_55 ,
struct V_13 V_56 [] , int V_57 )
{
struct V_3 * V_4 = F_16 ( V_55 ) ;
int V_30 , V_31 ;
for ( V_31 = 0 ; V_31 < V_57 ; V_31 ++ ) {
V_30 = F_7 ( V_4 , & V_56 [ V_31 ] ) ;
if ( V_30 ) {
F_6 ( V_4 -> V_21 , L_8 ) ;
return V_30 ;
}
}
return V_57 ;
}
static T_4 F_17 ( struct V_54 * V_58 )
{
return V_59 | V_60 ;
}
static int F_18 ( struct V_3 * V_4 )
{
unsigned int V_61 ;
T_2 V_15 ;
int V_30 = F_19 ( V_4 -> V_21 -> V_62 ,
L_9 , & V_61 ) ;
if ( V_30 < 0 ) {
F_20 ( V_4 -> V_21 ,
L_10 ) ;
V_61 = 100000 ;
}
if ( V_61 < 100000 ) {
F_14 ( V_4 -> V_21 , L_11 ,
V_61 ) ;
F_14 ( V_4 -> V_21 ,
L_12 ) ;
return - V_63 ;
} else if ( V_61 < 400000 ) {
V_61 = 100000 ;
} else {
V_61 = 400000 ;
}
V_15 = F_2 ( V_4 -> V_6 + V_64 ) ;
V_15 &= ~ ( 1 << V_65 ) ;
V_15 |= ( V_61 == 400000 ) << V_65 ;
F_3 ( V_15 , V_4 -> V_6 + V_64 ) ;
F_20 ( V_4 -> V_21 , L_13 , V_61 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
T_2 V_15 ;
V_15 = F_2 ( V_4 -> V_6 + V_66 ) ;
V_15 |= 1 << V_67 ;
V_15 &= ~ ( 1 << V_68 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_66 ) ;
F_22 ( 100 ) ;
V_15 &= ~ ( 1 << V_67 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_66 ) ;
V_15 = ( 1 << V_48 ) | ( 1 << V_49 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_50 ) ;
F_3 ( 0 , V_4 -> V_6 + V_43 ) ;
F_3 ( 0xffffffff , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 ,
bool V_69 )
{
T_2 V_15 ;
V_15 = F_2 ( V_4 -> V_6 + V_66 ) ;
if ( V_69 )
V_15 |= F_9 ( V_68 ) ;
else
V_15 &= ~ F_9 ( V_68 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_66 ) ;
}
static int F_24 ( struct V_70 * V_71 )
{
int V_1 , V_30 = 0 ;
struct V_3 * V_4 ;
struct V_54 * V_58 ;
struct V_72 * V_73 ;
V_4 = F_25 ( & V_71 -> V_74 , sizeof( * V_4 ) ,
V_75 ) ;
if ( ! V_4 )
return - V_76 ;
F_26 ( V_71 , V_4 ) ;
V_4 -> V_21 = & V_71 -> V_74 ;
F_27 ( & V_4 -> V_11 ) ;
V_73 = F_28 ( V_71 , V_77 , 0 ) ;
V_4 -> V_6 = F_29 ( V_4 -> V_21 , V_73 ) ;
if ( F_30 ( V_4 -> V_6 ) )
return F_31 ( V_4 -> V_6 ) ;
V_30 = F_21 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_18 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_1 = F_32 ( V_71 , 0 ) ;
if ( V_1 <= 0 ) {
F_14 ( V_4 -> V_21 , L_14 ) ;
return V_1 ;
}
V_4 -> V_1 = V_1 ;
V_30 = F_33 ( V_4 -> V_21 , V_1 , F_1 , 0 ,
V_71 -> V_78 , V_4 ) ;
if ( V_30 < 0 ) {
F_14 ( V_4 -> V_21 , L_15 , V_1 ) ;
return V_30 ;
}
F_23 ( V_4 , true ) ;
V_58 = & V_4 -> V_55 ;
F_34 ( V_58 , V_4 ) ;
F_35 ( V_58 -> V_78 , L_16 , sizeof( V_58 -> V_78 ) ) ;
V_58 -> V_79 = & V_80 ;
V_58 -> V_81 = & V_82 ;
V_58 -> V_74 . V_83 = & V_71 -> V_74 ;
V_58 -> V_74 . V_62 = V_71 -> V_74 . V_62 ;
V_30 = F_36 ( V_58 ) ;
if ( V_30 ) {
F_14 ( V_4 -> V_21 , L_17 ) ;
return V_30 ;
}
return 0 ;
}
static int F_37 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = F_38 ( V_71 ) ;
F_3 ( 0 , V_4 -> V_6 + V_43 ) ;
F_2 ( V_4 -> V_6 + V_43 ) ;
F_13 ( V_4 -> V_1 ) ;
F_39 ( & V_4 -> V_55 ) ;
F_23 ( V_4 , false ) ;
return 0 ;
}
