static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_6 = 0 ;
V_6 |= ( V_3 & V_7 ) ? V_8 : 0 ;
V_6 |= ( V_3 & V_9 ) ? V_10 : 0 ;
V_6 |= ( V_3 & V_11 ) ? 0 : V_12 | V_8 ;
F_2 ( V_6 , V_4 -> V_13 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_4 ( V_4 -> V_13 ) ;
return ( V_6 & V_8 ) ? V_7 : 0 |
( V_6 & V_14 ) ? V_15 : 0 ;
}
static void F_5 ( struct V_1 * V_2 , bool V_16 )
{
}
static void F_6 ( struct V_4 * V_4 , T_1 V_3 )
{
if ( ! V_4 -> V_2 . V_17 )
V_3 |= V_12 ;
F_2 ( V_3 , V_4 -> V_13 ) ;
}
static void F_7 ( struct V_4 * V_4 , int V_18 , T_2 V_19 )
{
int V_20 ;
T_2 V_21 ;
T_1 V_22 ;
V_21 = F_8 ( V_18 / 10 ) | F_9 ( ( V_18 % 10 ) / 2 ) ;
V_21 |= V_19 ;
for ( V_20 = 0 ; V_20 < 18 ; V_20 ++ ) {
V_22 = V_21 & ( 1 << V_20 ) ? V_23 : 0 ;
F_6 ( V_4 , V_22 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , V_22 | V_24 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , V_22 ) ;
}
F_10 ( 5 ) ;
F_6 ( V_4 , V_25 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , 0 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 -> V_28 , struct V_1 , V_29 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_30 , V_31 , V_32 , V_33 ;
switch ( V_27 -> V_34 ) {
case V_35 :
V_30 = V_27 -> V_36 ;
V_31 = V_4 -> V_31 -> V_37 . V_36 ;
break;
case V_38 :
V_31 = V_27 -> V_36 ;
V_30 = V_4 -> V_30 -> V_37 . V_36 ;
break;
default:
return - V_39 ;
}
V_32 = V_33 = V_30 ;
if ( V_31 < 0 )
V_33 = F_13 ( 0 , V_33 + V_31 ) ;
if ( V_31 > 0 )
V_32 = F_13 ( 0 , V_32 - V_31 ) ;
F_7 ( V_4 , abs ( V_32 - 68 ) , V_40 ) ;
F_7 ( V_4 , abs ( V_33 - 68 ) , V_41 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
if ( F_4 ( V_4 -> V_13 ) & V_42 ) {
V_4 -> V_30 = F_15 ( & V_2 -> V_29 , & V_43 , V_35 , 0 , 68 , 2 , 56 ) ;
V_4 -> V_31 = F_15 ( & V_2 -> V_29 , & V_43 , V_38 , - 68 , 68 , 2 , 0 ) ;
if ( V_2 -> V_29 . error ) {
F_16 ( V_44 L_1 ) ;
return V_2 -> V_29 . error ;
}
}
return 0 ;
}
static int T_3 F_17 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_4 * V_4 ;
int V_48 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_49 ) ;
if ( V_4 == NULL )
return - V_50 ;
F_19 ( V_4 -> V_51 . V_52 , F_20 ( V_46 ) ,
sizeof( V_4 -> V_51 . V_52 ) ) ;
V_4 -> V_13 = V_53 ;
if ( ! F_21 ( V_4 -> V_13 , 2 , V_4 -> V_51 . V_52 ) ) {
F_16 ( V_44 L_2 , V_4 -> V_13 ) ;
F_22 ( V_4 ) ;
return - V_54 ;
}
F_23 ( V_46 , V_4 ) ;
V_48 = F_24 ( V_46 , & V_4 -> V_51 ) ;
if ( V_48 < 0 ) {
F_25 ( & V_4 -> V_51 , L_3 ) ;
F_26 ( V_4 -> V_13 , 2 ) ;
F_22 ( V_4 ) ;
return V_48 ;
}
V_4 -> V_2 . V_51 = & V_4 -> V_51 ;
V_4 -> V_2 . V_5 = V_4 ;
V_4 -> V_2 . V_55 = V_55 ;
V_4 -> V_2 . V_56 = & V_57 ;
V_4 -> V_2 . V_58 = F_14 ;
F_19 ( V_4 -> V_2 . V_59 , L_4 , sizeof( V_4 -> V_2 . V_59 ) ) ;
snprintf ( V_4 -> V_2 . V_60 , sizeof( V_4 -> V_2 . V_60 ) , L_5 ,
V_4 -> V_51 . V_52 ) ;
if ( F_27 ( & V_4 -> V_2 ) ) {
F_16 ( V_44 L_6 ) ;
F_26 ( V_4 -> V_13 , 2 ) ;
F_22 ( V_4 ) ;
return - V_61 ;
}
F_16 ( V_62 L_7 , V_4 -> V_13 ) ;
return 0 ;
}
static int T_4 F_28 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_4 * V_4 = F_29 ( V_46 ) ;
F_30 ( & V_4 -> V_2 ) ;
F_26 ( V_4 -> V_13 , 2 ) ;
F_31 ( & V_4 -> V_51 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_63 , 1 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_63 ) ;
}
