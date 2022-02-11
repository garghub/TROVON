int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_2 ( V_2 , V_7 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_6 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_7 ) ;
F_2 ( V_2 , V_6 , 0 ) ;
return V_4 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_8 )
{
F_2 ( V_2 , V_9 , V_8 |
V_8 << V_10 ) ;
return F_4 ( V_2 , V_9 ) ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_4 )
{
return F_2 ( V_2 , V_9 , V_8 | V_4 ) ;
}
int F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_11 , T_1 V_4 )
{
int V_5 ;
int V_12 ;
V_5 = F_2 ( V_2 , V_9 ,
V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
V_12 = F_4 ( V_2 , V_9 ) ;
V_12 |= V_14 ;
V_5 = F_2 ( V_2 , V_9 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_12 = ( V_11 * V_15 ) | V_3 ;
V_5 = F_1 ( V_2 , V_12 , V_4 ) ;
return V_5 ;
}
int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_11 )
{
int V_5 ;
int V_12 ;
V_5 = F_2 ( V_2 , V_9 ,
V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
V_12 = F_4 ( V_2 , V_9 ) ;
V_12 |= V_14 ;
V_5 = F_2 ( V_2 , V_9 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_12 = ( V_11 * V_15 ) | V_3 ;
V_5 = F_3 ( V_2 , V_12 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_18 == V_19 )
V_3 &= ~ V_20 ;
else
V_3 |= V_20 ;
return F_2 ( V_2 , V_17 , V_3 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_21 )
{
F_2 ( V_2 , V_22 , F_12 ( V_21 ) ) ;
return F_13 ( F_4 ( V_2 , V_22 ) ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_21 ,
T_1 V_4 )
{
return F_2 ( V_2 , V_22 ,
V_23 |
F_12 ( V_21 ) |
F_13 ( V_4 ) ) ;
}
int F_15 ( struct V_1 * V_2 , bool V_24 )
{
int V_4 ;
if ( V_24 ) {
V_4 = F_11 ( V_2 , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 |= V_26 ;
F_14 ( V_2 , V_25 , V_4 ) ;
}
V_4 = F_11 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 &= V_28 ;
if ( V_2 -> V_29 == V_30 )
V_4 |= V_31 ;
else
V_4 |= V_32 ;
V_4 |= V_33 ;
return F_14 ( V_2 , V_27 , V_4 ) ;
}
int F_16 ( struct V_1 * V_2 , bool V_34 )
{
int V_4 ;
V_4 = F_17 ( V_2 , V_35 , V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_34 )
V_4 |= V_37 | V_38 ;
else
V_4 &= ~ ( V_37 | V_38 ) ;
F_18 ( V_2 , V_35 , V_36 , ( V_39 ) V_4 ) ;
V_4 = F_17 ( V_2 , V_35 , V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_34 )
V_4 |= ( V_41 | V_42 ) ;
else
V_4 &= ~ ( V_41 | V_42 ) ;
F_18 ( V_2 , V_35 , V_40 , ( V_39 ) V_4 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_2 * V_43 )
{
int V_4 ;
V_4 = F_5 ( V_2 , V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_44 ) ) {
* V_43 = V_45 ;
return 0 ;
}
V_4 = F_11 ( V_2 , V_46 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_47 ) {
* V_43 = 1 ;
} else {
V_4 >>= V_48 ;
V_4 &= V_49 ;
* V_43 = V_4 + V_50 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_2 V_43 )
{
int V_4 = 0 , V_51 = 0 ;
if ( V_43 - V_50 >
V_49 &&
V_43 != V_52 ) {
return - V_53 ;
}
V_4 = F_5 ( V_2 , V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 |= V_54 ;
if ( V_43 == V_45 ) {
V_4 &= ~ V_44 ;
return F_6 ( V_2 ,
V_13 ,
V_4 ) ;
} else {
V_4 |= V_44 ;
V_51 = F_6 ( V_2 ,
V_13 ,
V_4 ) ;
if ( V_51 < 0 )
return V_51 ;
}
V_4 = F_11 ( V_2 , V_46 ) ;
V_4 &= ~ ( V_49 <<
V_48 |
V_47 ) ;
switch ( V_43 ) {
case 1 :
V_4 |= V_47 ;
break;
case V_52 :
V_4 |= 1 << V_48 ;
break;
default:
V_4 |= ( V_43 - V_50 ) <<
V_48 ;
break;
}
return F_14 ( V_2 , V_46 , V_4 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_55 ) ;
}
void F_23 ( struct V_1 * V_2 , T_2 * V_56 )
{
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < F_22 ( V_55 ) ; V_57 ++ )
memcpy ( V_56 + V_57 * V_58 ,
V_55 [ V_57 ] . string , V_58 ) ;
}
static T_3 F_24 ( struct V_1 * V_2 , T_3 * V_21 ,
unsigned int V_57 )
{
struct V_59 V_60 = V_55 [ V_57 ] ;
int V_4 ;
T_3 V_51 ;
V_4 = F_4 ( V_2 , V_60 . V_3 ) ;
if ( V_4 < 0 ) {
V_51 = V_61 ;
} else {
V_4 >>= V_60 . V_62 ;
V_4 = V_4 & ( ( 1 << V_60 . V_63 ) - 1 ) ;
V_21 [ V_57 ] += V_4 ;
V_51 = V_21 [ V_57 ] ;
}
return V_51 ;
}
void F_25 ( struct V_1 * V_2 , T_3 * V_21 ,
struct V_64 * V_65 , T_3 * V_56 )
{
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < F_22 ( V_55 ) ; V_57 ++ )
V_56 [ V_57 ] = F_24 ( V_2 , V_21 , V_57 ) ;
}
