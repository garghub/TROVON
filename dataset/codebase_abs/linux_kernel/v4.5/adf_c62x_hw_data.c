static T_1 F_1 ( T_1 V_1 )
{
return ( ~ V_1 ) >> V_2 &
V_3 ;
}
static T_1 F_2 ( T_1 V_1 )
{
return ( ~ V_1 ) & V_4 ;
}
static T_1 F_3 ( struct V_5 * V_6 )
{
T_1 V_7 , V_8 = 0 ;
if ( ! V_6 || ! V_6 -> V_9 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
if ( V_6 -> V_9 & ( 1 << V_7 ) )
V_8 ++ ;
}
return V_8 ;
}
static T_1 F_4 ( struct V_5 * V_6 )
{
T_1 V_7 , V_8 = 0 ;
if ( ! V_6 || ! V_6 -> V_11 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
if ( V_6 -> V_11 & ( 1 << V_7 ) )
V_8 ++ ;
}
return V_8 ;
}
static T_1 F_5 ( struct V_5 * V_6 )
{
return V_13 ;
}
static T_1 F_6 ( struct V_5 * V_6 )
{
return V_14 ;
}
static T_1 F_7 ( struct V_5 * V_6 )
{
return V_15 ;
}
static enum V_16 F_8 ( struct V_5 * V_6 )
{
int V_17 = F_4 ( V_6 ) ;
if ( V_17 == 8 )
return V_18 ;
else if ( V_17 == 10 )
return V_19 ;
return V_20 ;
}
static void F_9 ( struct V_21 * V_22 ,
T_1 const * * V_23 )
{
switch ( V_22 -> V_24 . V_25 ) {
case V_18 :
* V_23 = V_26 ;
break;
case V_19 :
* V_23 = V_27 ;
break;
default:
F_10 ( & F_11 ( V_22 ) ,
L_1 ) ;
* V_23 = NULL ;
}
}
static T_1 F_12 ( T_1 V_7 )
{
return F_13 ( V_7 ) ;
}
static T_1 F_14 ( T_1 V_7 )
{
return F_15 ( V_7 ) ;
}
static void F_16 ( struct V_21 * V_22 )
{
struct V_5 * V_28 = V_22 -> V_28 ;
struct V_29 * V_30 = & F_17 ( V_22 ) [ V_13 ] ;
void T_2 * V_31 = V_30 -> V_32 ;
unsigned int V_33 , V_7 ;
for ( V_7 = 0 ; V_7 < V_28 -> F_4 ( V_28 ) ; V_7 ++ ) {
V_33 = F_18 ( V_31 , F_19 ( V_7 ) ) ;
V_33 |= V_34 ;
F_20 ( V_31 , F_19 ( V_7 ) , V_33 ) ;
V_33 = F_18 ( V_31 , F_21 ( V_7 ) ) ;
V_33 |= V_35 ;
F_20 ( V_31 , F_21 ( V_7 ) , V_33 ) ;
}
for ( V_7 = 0 ; V_7 < V_28 -> F_3 ( V_28 ) ; V_7 ++ ) {
V_33 = F_18 ( V_31 , F_22 ( V_7 ) ) ;
V_33 |= V_36 ;
F_20 ( V_31 , F_22 ( V_7 ) , V_33 ) ;
V_33 = F_18 ( V_31 , F_23 ( V_7 ) ) ;
V_33 |= V_36 ;
F_20 ( V_31 , F_23 ( V_7 ) , V_33 ) ;
}
}
static void F_24 ( struct V_21 * V_22 )
{
void T_2 * V_37 ;
V_37 = ( & F_17 ( V_22 ) [ V_13 ] ) -> V_32 ;
F_20 ( V_37 , V_38 ,
V_39 ) ;
F_20 ( V_37 , V_40 ,
V_41 ) ;
}
static int F_25 ( struct V_21 * V_22 )
{
return 0 ;
}
void F_26 ( struct V_5 * V_42 )
{
V_42 -> V_43 = & V_44 ;
V_42 -> V_45 = V_44 . V_46 ++ ;
V_42 -> V_47 = V_48 ;
V_42 -> V_49 = V_10 ;
V_42 -> V_50 = 1 ;
V_42 -> V_51 = V_12 ;
V_42 -> V_52 = V_53 ;
V_42 -> V_54 = V_55 ;
V_42 -> V_56 = V_57 ;
V_42 -> V_58 = V_59 ;
V_42 -> V_60 = F_16 ;
V_42 -> F_1 = F_1 ;
V_42 -> F_2 = F_2 ;
V_42 -> F_3 = F_3 ;
V_42 -> F_4 = F_4 ;
V_42 -> F_7 = F_7 ;
V_42 -> F_6 = F_6 ;
V_42 -> F_5 = F_5 ;
V_42 -> F_12 = F_12 ;
V_42 -> F_14 = F_14 ;
V_42 -> F_8 = F_8 ;
V_42 -> V_61 = V_62 ;
V_42 -> V_63 = V_64 ;
V_42 -> V_65 = V_66 ;
V_42 -> V_67 = V_68 ;
V_42 -> V_69 = V_70 ;
V_42 -> V_71 = V_72 ;
V_42 -> V_73 = V_74 ;
V_42 -> V_75 = V_76 ;
V_42 -> V_77 = F_9 ;
V_42 -> V_78 = F_24 ;
V_42 -> V_79 = F_25 ;
V_42 -> V_80 = V_81 ;
}
void F_27 ( struct V_5 * V_42 )
{
V_42 -> V_43 -> V_46 -- ;
}
