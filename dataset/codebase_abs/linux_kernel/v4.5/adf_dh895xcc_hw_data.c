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
int V_17 = ( V_6 -> V_18 & V_19 )
>> V_20 ;
switch ( V_17 ) {
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
default:
return V_29 ;
}
return V_29 ;
}
static void F_9 ( struct V_30 * V_31 ,
T_2 const * * V_32 )
{
switch ( V_31 -> V_33 . V_17 ) {
case V_22 :
* V_32 = V_34 ;
break;
case V_24 :
case V_28 :
* V_32 = V_35 ;
break;
default:
F_10 ( & F_11 ( V_31 ) ,
L_1 ) ;
* V_32 = NULL ;
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
static void F_16 ( struct V_30 * V_31 )
{
struct V_5 * V_36 = V_31 -> V_36 ;
struct V_37 * V_38 = & F_17 ( V_31 ) [ V_13 ] ;
void T_3 * V_39 = V_38 -> V_40 ;
unsigned int V_41 , V_7 ;
for ( V_7 = 0 ; V_7 < V_36 -> F_4 ( V_36 ) ; V_7 ++ ) {
V_41 = F_18 ( V_39 , F_19 ( V_7 ) ) ;
V_41 |= V_42 ;
F_20 ( V_39 , F_19 ( V_7 ) , V_41 ) ;
V_41 = F_18 ( V_39 , F_21 ( V_7 ) ) ;
V_41 |= V_43 ;
F_20 ( V_39 , F_21 ( V_7 ) , V_41 ) ;
}
for ( V_7 = 0 ; V_7 < V_36 -> F_3 ( V_36 ) ; V_7 ++ ) {
V_41 = F_18 ( V_39 , F_22 ( V_7 ) ) ;
V_41 |= V_44 ;
F_20 ( V_39 , F_22 ( V_7 ) , V_41 ) ;
V_41 = F_18 ( V_39 , F_23 ( V_7 ) ) ;
V_41 |= V_44 ;
F_20 ( V_39 , F_23 ( V_7 ) , V_41 ) ;
}
}
static void F_24 ( struct V_30 * V_31 )
{
void T_3 * V_45 ;
V_45 = ( & F_17 ( V_31 ) [ V_13 ] ) -> V_40 ;
F_20 ( V_45 , V_46 ,
V_31 -> V_47 . V_48 ? 0 :
F_25 ( F_26 ( V_31 ) - 1 , 0 ) ) ;
F_20 ( V_45 , V_49 ,
V_50 ) ;
}
static int F_27 ( struct V_30 * V_31 )
{
return 0 ;
}
void F_28 ( struct V_5 * V_51 )
{
V_51 -> V_52 = & V_53 ;
V_51 -> V_54 = V_53 . V_55 ++ ;
V_51 -> V_56 = V_57 ;
V_51 -> V_58 = V_10 ;
V_51 -> V_59 = 1 ;
V_51 -> V_60 = V_12 ;
V_51 -> V_61 = V_62 ;
V_51 -> V_63 = V_64 ;
V_51 -> V_65 = V_66 ;
V_51 -> V_67 = V_68 ;
V_51 -> V_69 = F_16 ;
V_51 -> F_1 = F_1 ;
V_51 -> F_2 = F_2 ;
V_51 -> F_3 = F_3 ;
V_51 -> F_4 = F_4 ;
V_51 -> F_6 = F_6 ;
V_51 -> F_5 = F_5 ;
V_51 -> F_12 = F_12 ;
V_51 -> F_14 = F_14 ;
V_51 -> F_7 = F_7 ;
V_51 -> F_8 = F_8 ;
V_51 -> V_70 = V_71 ;
V_51 -> V_72 = V_73 ;
V_51 -> V_74 = V_75 ;
V_51 -> V_76 = V_77 ;
V_51 -> V_78 = V_79 ;
V_51 -> V_80 = V_81 ;
V_51 -> V_82 = V_83 ;
V_51 -> V_84 = V_85 ;
V_51 -> V_86 = F_9 ;
V_51 -> V_87 = F_24 ;
V_51 -> V_88 = F_27 ;
V_51 -> V_89 = V_90 ;
}
void F_29 ( struct V_5 * V_51 )
{
V_51 -> V_52 -> V_55 -- ;
}
