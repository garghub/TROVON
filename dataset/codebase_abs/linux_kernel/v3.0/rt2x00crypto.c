enum V_1 F_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_1 ) {
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
default:
return V_12 ;
}
}
void F_2 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 -> V_19 -> V_18 ;
struct V_20 * V_21 = F_3 ( V_14 -> V_22 ) ;
struct V_2 * V_23 = V_21 -> V_24 . V_23 ;
if ( ! F_4 ( V_25 , & V_18 -> V_26 ) || ! V_23 )
return;
F_5 ( V_27 , & V_16 -> V_28 ) ;
V_16 -> V_1 = F_1 ( V_23 ) ;
if ( V_23 -> V_28 & V_29 )
F_5 ( V_30 , & V_16 -> V_28 ) ;
V_16 -> V_31 = V_23 -> V_32 ;
V_16 -> V_33 = V_16 -> V_34 ;
V_16 -> V_35 = V_23 -> V_35 ;
if ( ! ( V_23 -> V_28 & V_36 ) )
F_5 ( V_37 , & V_16 -> V_28 ) ;
if ( ! ( V_23 -> V_28 & V_38 ) )
F_5 ( V_39 , & V_16 -> V_28 ) ;
}
unsigned int F_6 ( struct V_17 * V_18 ,
struct V_40 * V_22 )
{
struct V_20 * V_21 = F_3 ( V_22 ) ;
struct V_2 * V_3 = V_21 -> V_24 . V_23 ;
unsigned int V_41 = 0 ;
if ( ! F_4 ( V_25 , & V_18 -> V_26 ) || ! V_3 )
return V_41 ;
V_41 += V_3 -> V_42 ;
if ( ! ( V_3 -> V_28 & V_36 ) )
V_41 += V_3 -> V_35 ;
if ( ! ( V_3 -> V_28 & V_38 ) ) {
if ( V_3 -> V_1 == V_8 )
V_41 += 8 ;
}
return V_41 ;
}
void F_7 ( struct V_40 * V_22 , struct V_15 * V_16 )
{
struct V_43 * V_44 = F_8 ( V_22 ) ;
if ( F_9 ( ! V_16 -> V_35 ) )
return;
memcpy ( V_44 -> V_45 , V_22 -> V_46 + V_16 -> V_33 , V_16 -> V_35 ) ;
}
void F_10 ( struct V_40 * V_22 , struct V_15 * V_16 )
{
struct V_43 * V_44 = F_8 ( V_22 ) ;
if ( F_9 ( ! V_16 -> V_35 ) )
return;
memcpy ( V_44 -> V_45 , V_22 -> V_46 + V_16 -> V_33 , V_16 -> V_35 ) ;
memmove ( V_22 -> V_46 + V_16 -> V_35 , V_22 -> V_46 , V_16 -> V_33 ) ;
F_11 ( V_22 , V_16 -> V_35 ) ;
V_16 -> V_47 -= V_16 -> V_35 ;
V_44 -> V_28 |= V_48 ;
}
void F_12 ( struct V_40 * V_22 , unsigned int V_34 )
{
struct V_43 * V_44 = F_8 ( V_22 ) ;
const unsigned int V_35 =
( ( ! ! ( V_44 -> V_45 [ 0 ] ) ) * 4 ) + ( ( ! ! ( V_44 -> V_45 [ 1 ] ) ) * 4 ) ;
if ( ! ( V_44 -> V_28 & V_48 ) )
return;
F_13 ( V_22 , V_35 ) ;
memmove ( V_22 -> V_46 , V_22 -> V_46 + V_35 , V_34 ) ;
memcpy ( V_22 -> V_46 + V_34 , V_44 -> V_45 , V_35 ) ;
V_44 -> V_28 &= ~ V_48 ;
}
void F_14 ( struct V_40 * V_22 ,
unsigned int V_34 ,
struct V_49 * V_50 )
{
unsigned int V_51 = V_50 -> V_52 - V_34 ;
unsigned int V_53 = F_15 ( V_22 , V_34 ) ;
unsigned int V_35 ;
unsigned int V_42 ;
unsigned int V_54 = 0 ;
switch ( V_50 -> V_1 ) {
case V_5 :
case V_7 :
V_35 = 4 ;
V_42 = 4 ;
break;
case V_9 :
V_35 = 8 ;
V_42 = 4 ;
break;
case V_11 :
V_35 = 8 ;
V_42 = 8 ;
break;
default:
return;
}
if ( V_50 -> V_55 & V_56 ) {
F_13 ( V_22 , V_35 - V_53 ) ;
F_16 ( V_22 , V_42 ) ;
memmove ( V_22 -> V_46 + V_54 ,
V_22 -> V_46 + V_54 + ( V_35 - V_53 ) ,
V_34 ) ;
V_54 += V_34 ;
} else {
F_13 ( V_22 , V_35 + V_53 ) ;
if ( V_53 < V_42 )
F_16 ( V_22 , V_42 - V_53 ) ;
else if ( V_53 > V_42 )
F_17 ( V_22 , V_50 -> V_52 + V_35 + V_42 ) ;
memmove ( V_22 -> V_46 + V_54 ,
V_22 -> V_46 + V_54 + V_35 + V_53 ,
V_34 ) ;
V_54 += V_34 ;
}
memcpy ( V_22 -> V_46 + V_54 , V_50 -> V_45 , V_35 ) ;
V_54 += V_35 ;
if ( ! ( V_50 -> V_55 & V_56 ) ) {
memmove ( V_22 -> V_46 + V_54 ,
V_22 -> V_46 + V_54 + V_53 ,
V_51 ) ;
}
V_54 += V_51 ;
memcpy ( V_22 -> V_46 + V_54 , & V_50 -> V_57 , 4 ) ;
V_54 += V_42 ;
V_50 -> V_52 = V_54 ;
V_50 -> V_28 &= ~ V_58 ;
}
