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
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = F_3 ( V_16 ) ;
struct V_2 * V_21 = V_20 -> V_22 . V_21 ;
if ( ! F_4 ( V_23 , & V_14 -> V_24 ) || ! V_21 )
return;
F_5 ( V_25 , & V_18 -> V_26 ) ;
V_18 -> V_1 = F_1 ( V_21 ) ;
if ( V_21 -> V_26 & V_27 )
F_5 ( V_28 , & V_18 -> V_26 ) ;
V_18 -> V_29 = V_21 -> V_30 ;
V_18 -> V_31 = V_18 -> V_32 ;
V_18 -> V_33 = V_21 -> V_33 ;
if ( ! ( V_21 -> V_26 & V_34 ) )
F_5 ( V_35 , & V_18 -> V_26 ) ;
if ( ! ( V_21 -> V_26 & V_36 ) )
F_5 ( V_37 , & V_18 -> V_26 ) ;
}
unsigned int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_19 * V_20 = F_3 ( V_16 ) ;
struct V_2 * V_3 = V_20 -> V_22 . V_21 ;
unsigned int V_38 = 0 ;
if ( ! F_4 ( V_23 , & V_14 -> V_24 ) || ! V_3 )
return V_38 ;
V_38 += V_3 -> V_39 ;
if ( ! ( V_3 -> V_26 & V_34 ) )
V_38 += V_3 -> V_33 ;
if ( ! ( V_3 -> V_26 & V_36 ) ) {
if ( V_3 -> V_1 == V_8 )
V_38 += 8 ;
}
return V_38 ;
}
void F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_40 * V_41 = F_8 ( V_16 ) ;
if ( F_9 ( ! V_18 -> V_33 ) )
return;
memcpy ( V_41 -> V_42 , V_16 -> V_43 + V_18 -> V_31 , V_18 -> V_33 ) ;
}
void F_10 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_40 * V_41 = F_8 ( V_16 ) ;
if ( F_9 ( ! V_18 -> V_33 ) )
return;
memcpy ( V_41 -> V_42 , V_16 -> V_43 + V_18 -> V_31 , V_18 -> V_33 ) ;
memmove ( V_16 -> V_43 + V_18 -> V_33 , V_16 -> V_43 , V_18 -> V_31 ) ;
F_11 ( V_16 , V_18 -> V_33 ) ;
V_18 -> V_44 -= V_18 -> V_33 ;
V_41 -> V_26 |= V_45 ;
}
void F_12 ( struct V_15 * V_16 , unsigned int V_32 )
{
struct V_40 * V_41 = F_8 ( V_16 ) ;
const unsigned int V_33 =
( ( ! ! ( V_41 -> V_42 [ 0 ] ) ) * 4 ) + ( ( ! ! ( V_41 -> V_42 [ 1 ] ) ) * 4 ) ;
if ( ! ( V_41 -> V_26 & V_45 ) )
return;
F_13 ( V_16 , V_33 ) ;
memmove ( V_16 -> V_43 , V_16 -> V_43 + V_33 , V_32 ) ;
memcpy ( V_16 -> V_43 + V_32 , V_41 -> V_42 , V_33 ) ;
V_41 -> V_26 &= ~ V_45 ;
}
void F_14 ( struct V_15 * V_16 ,
unsigned int V_32 ,
struct V_46 * V_47 )
{
unsigned int V_48 = V_47 -> V_49 - V_32 ;
unsigned int V_50 = F_15 ( V_16 , V_32 ) ;
unsigned int V_33 ;
unsigned int V_39 ;
unsigned int V_51 = 0 ;
switch ( V_47 -> V_1 ) {
case V_5 :
case V_7 :
V_33 = 4 ;
V_39 = 4 ;
break;
case V_9 :
V_33 = 8 ;
V_39 = 4 ;
break;
case V_11 :
V_33 = 8 ;
V_39 = 8 ;
break;
default:
return;
}
if ( V_47 -> V_52 & V_53 ) {
F_13 ( V_16 , V_33 - V_50 ) ;
F_16 ( V_16 , V_39 ) ;
memmove ( V_16 -> V_43 + V_51 ,
V_16 -> V_43 + V_51 + ( V_33 - V_50 ) ,
V_32 ) ;
V_51 += V_32 ;
} else {
F_13 ( V_16 , V_33 + V_50 ) ;
if ( V_50 < V_39 )
F_16 ( V_16 , V_39 - V_50 ) ;
else if ( V_50 > V_39 )
F_17 ( V_16 , V_47 -> V_49 + V_33 + V_39 ) ;
memmove ( V_16 -> V_43 + V_51 ,
V_16 -> V_43 + V_51 + V_33 + V_50 ,
V_32 ) ;
V_51 += V_32 ;
}
memcpy ( V_16 -> V_43 + V_51 , V_47 -> V_42 , V_33 ) ;
V_51 += V_33 ;
if ( ! ( V_47 -> V_52 & V_53 ) ) {
memmove ( V_16 -> V_43 + V_51 ,
V_16 -> V_43 + V_51 + V_50 ,
V_48 ) ;
}
V_51 += V_48 ;
memcpy ( V_16 -> V_43 + V_51 , & V_47 -> V_54 , 4 ) ;
V_51 += V_39 ;
V_47 -> V_49 = V_51 ;
V_47 -> V_26 &= ~ V_55 ;
}
