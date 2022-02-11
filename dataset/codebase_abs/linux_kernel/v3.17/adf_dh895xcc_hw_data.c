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
static enum V_15 F_7 ( struct V_5 * V_6 )
{
int V_16 = ( V_6 -> V_17 & V_18 )
>> V_19 ;
switch ( V_16 ) {
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
default:
return V_28 ;
}
return V_28 ;
}
void F_8 ( struct V_29 * V_30 ,
T_1 const * * V_31 )
{
switch ( V_30 -> V_32 . V_16 ) {
case V_21 :
* V_31 = V_33 ;
break;
case V_23 :
case V_27 :
* V_31 = V_34 ;
break;
default:
F_9 ( L_1 ) ;
* V_31 = NULL ;
}
}
static void F_10 ( struct V_29 * V_30 )
{
struct V_5 * V_35 = V_30 -> V_35 ;
struct V_36 * V_37 = & F_11 ( V_30 ) [ V_13 ] ;
void T_2 * V_38 = V_37 -> V_39 ;
unsigned int V_40 , V_7 ;
for ( V_7 = 0 ; V_7 < V_35 -> F_4 ( V_35 ) ; V_7 ++ ) {
V_40 = F_12 ( V_38 , F_13 ( V_7 ) ) ;
V_40 |= V_41 ;
F_14 ( V_38 , F_13 ( V_7 ) , V_40 ) ;
V_40 = F_12 ( V_38 , F_15 ( V_7 ) ) ;
V_40 |= V_42 ;
F_14 ( V_38 , F_15 ( V_7 ) , V_40 ) ;
}
for ( V_7 = 0 ; V_7 < V_35 -> F_3 ( V_35 ) ; V_7 ++ ) {
V_40 = F_12 ( V_38 , F_16 ( V_7 ) ) ;
V_40 |= V_43 ;
F_14 ( V_38 , F_16 ( V_7 ) , V_40 ) ;
V_40 = F_12 ( V_38 , F_17 ( V_7 ) ) ;
V_40 |= V_43 ;
F_14 ( V_38 , F_17 ( V_7 ) , V_40 ) ;
}
}
void F_18 ( struct V_5 * V_44 )
{
V_44 -> V_45 = & V_46 ;
V_44 -> V_47 = V_46 . V_48 ++ ;
V_44 -> V_49 = V_50 ;
V_44 -> V_51 = V_10 ;
V_44 -> V_52 = V_53 ;
V_44 -> V_54 = 1 ;
V_44 -> V_55 = V_12 ;
V_44 -> V_56 = V_57 ;
V_44 -> V_58 = V_59 ;
V_44 -> V_60 = V_61 ;
V_44 -> V_62 = V_63 ;
V_44 -> V_64 = F_10 ;
V_44 -> V_65 = V_66 ;
V_44 -> V_67 = V_66 ;
V_44 -> F_1 = F_1 ;
V_44 -> F_2 = F_2 ;
V_44 -> F_3 = F_3 ;
V_44 -> F_4 = F_4 ;
V_44 -> F_6 = F_6 ;
V_44 -> F_5 = F_5 ;
V_44 -> F_7 = F_7 ;
V_44 -> V_68 = V_69 ;
}
void F_19 ( struct V_5 * V_44 )
{
V_44 -> V_45 -> V_48 -- ;
}
