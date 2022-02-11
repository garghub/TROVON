static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_7 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static bool F_5 ( void T_2 * V_5 , void T_2 * V_9 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_12 , T_1 V_13 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_12 , V_5 ) ;
F_2 ( V_13 , V_9 ) ;
F_2 ( V_16 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_13 )
{
void T_2 * V_5 , * V_9 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_9 = V_2 -> V_17 + V_19 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_5 ( V_5 , V_9 , V_10 , V_11 , V_12 , V_13 ) )
F_9 ( V_2 -> V_22 , L_1 ,
V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static bool F_12 ( void T_2 * V_5 , void T_2 * V_23 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_24 , T_1 * V_25 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_24 , V_5 ) ;
F_2 ( V_26 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
* V_25 = F_6 ( V_23 ) ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_24 , T_1 * V_25 )
{
void T_2 * V_5 , * V_23 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_23 = V_2 -> V_17 + V_27 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_12 ( V_5 , V_23 , V_10 , V_11 , V_24 , V_25 ) )
F_9 ( V_2 -> V_22 , L_2 ,
V_24 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_29 ;
T_3 V_15 = 10 ;
F_4 ( V_2 , V_30 , 0x0 ) ;
do {
F_15 ( 100 , 110 ) ;
F_11 ( V_2 , V_31 , & V_29 ) ;
} while ( ( V_29 != 0xffffffff ) && V_15 -- );
if ( V_29 != 0xffffffff ) {
F_9 ( V_22 , L_3 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_33 , 0 ) ;
F_3 ( V_2 , V_34 , 0 ) ;
F_3 ( V_2 , V_35 , 0 ) ;
F_3 ( V_2 , V_36 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_37 , V_38 ) ;
F_8 ( V_2 , V_37 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 ;
T_3 * V_41 = V_2 -> V_22 -> V_41 ;
V_39 = ( V_41 [ 3 ] << 24 ) | ( V_41 [ 2 ] << 16 ) |
( V_41 [ 1 ] << 8 ) | V_41 [ 0 ] ;
V_40 = ( V_41 [ 5 ] << 24 ) | ( V_41 [ 4 ] << 16 ) ;
F_8 ( V_2 , V_42 , V_39 ) ;
F_8 ( V_2 , V_43 , V_40 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_10 ( V_2 , V_44 , & V_29 ) ;
return V_29 ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_17 ( V_2 ) ;
F_13 ( V_2 , V_45 , & V_29 ) ;
V_29 |= V_46 ;
V_29 &= ~ V_47 ;
F_8 ( V_2 , V_45 , V_29 ) ;
F_8 ( V_2 , V_48 , 0x06000600 ) ;
F_18 ( V_2 ) ;
F_10 ( V_2 , V_49 , & V_29 ) ;
V_29 |= V_50 ;
F_1 ( V_2 , V_49 , V_29 ) ;
F_1 ( V_2 , V_51 , V_52 ) ;
F_1 ( V_2 , V_53 , 0 ) ;
F_10 ( V_2 , V_54 , & V_29 ) ;
V_29 |= F_21 ( 12 ) ;
F_1 ( V_2 , V_54 , V_29 ) ;
F_1 ( V_2 , V_55 , 0x82 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_45 , & V_29 ) ;
F_8 ( V_2 , V_45 , V_29 | V_56 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_45 , & V_29 ) ;
F_8 ( V_2 , V_45 , V_29 | V_57 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_45 , & V_29 ) ;
F_8 ( V_2 , V_45 , V_29 & ~ V_56 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_45 , & V_29 ) ;
F_8 ( V_2 , V_45 , V_29 & ~ V_57 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ! F_27 ( V_2 ) )
return - V_32 ;
if ( ! F_28 ( V_2 -> V_58 ) ) {
F_29 ( V_2 -> V_58 ) ;
F_30 ( V_2 -> V_58 ) ;
F_29 ( V_2 -> V_58 ) ;
}
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
T_1 V_59 , T_4 V_60 )
{
T_1 V_61 , V_62 ;
F_10 ( V_2 , V_63 , & V_61 ) ;
V_61 |= V_64 ;
F_32 ( & V_61 , 3 ) ;
F_1 ( V_2 , V_63 , V_61 ) ;
V_62 = F_33 ( V_60 ) - 0x20 ;
F_10 ( V_2 , V_65 , & V_61 ) ;
F_34 ( & V_61 , V_59 ) ;
F_35 ( & V_61 , V_62 ) ;
F_1 ( V_2 , V_65 , V_61 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 -> V_58 ) )
F_30 ( V_2 -> V_58 ) ;
}
static void F_37 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_38 ( F_39 ( V_67 ) ,
struct V_1 , V_68 ) ;
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_69 , V_70 ;
V_69 = F_19 ( V_2 ) ;
if ( V_69 ) {
if ( ! F_40 ( V_22 ) ) {
F_41 ( V_22 ) ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_42 ( V_22 , L_4 ) ;
}
V_70 = V_71 ;
} else {
if ( F_40 ( V_22 ) ) {
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_43 ( V_22 ) ;
F_42 ( V_22 , L_5 ) ;
}
V_70 = V_72 ;
}
F_44 ( & V_2 -> V_68 , V_70 ) ;
}
