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
if ( ! F_4 ( V_14 ) || ! V_21 )
return;
F_5 ( V_23 , & V_18 -> V_24 ) ;
V_18 -> V_1 = F_1 ( V_21 ) ;
if ( V_21 -> V_24 & V_25 )
F_5 ( V_26 , & V_18 -> V_24 ) ;
V_18 -> V_27 = V_21 -> V_28 ;
V_18 -> V_29 = V_18 -> V_30 ;
V_18 -> V_31 = V_21 -> V_31 ;
if ( ! ( V_21 -> V_24 & V_32 ) )
F_5 ( V_33 , & V_18 -> V_24 ) ;
if ( ! ( V_21 -> V_24 & V_34 ) )
F_5 ( V_35 , & V_18 -> V_24 ) ;
}
unsigned int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_19 * V_20 = F_3 ( V_16 ) ;
struct V_2 * V_3 = V_20 -> V_22 . V_21 ;
unsigned int V_36 = 0 ;
if ( ! F_4 ( V_14 ) || ! V_3 )
return V_36 ;
V_36 += V_3 -> V_37 ;
if ( ! ( V_3 -> V_24 & V_32 ) )
V_36 += V_3 -> V_31 ;
if ( ! ( V_3 -> V_24 & V_34 ) ) {
if ( V_3 -> V_1 == V_8 )
V_36 += 8 ;
}
return V_36 ;
}
void F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_38 * V_39 = F_8 ( V_16 ) ;
if ( F_9 ( ! V_18 -> V_31 ) )
return;
memcpy ( V_39 -> V_40 , V_16 -> V_41 + V_18 -> V_29 , V_18 -> V_31 ) ;
}
void F_10 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_38 * V_39 = F_8 ( V_16 ) ;
if ( F_9 ( ! V_18 -> V_31 ) )
return;
memcpy ( V_39 -> V_40 , V_16 -> V_41 + V_18 -> V_29 , V_18 -> V_31 ) ;
memmove ( V_16 -> V_41 + V_18 -> V_31 , V_16 -> V_41 , V_18 -> V_29 ) ;
F_11 ( V_16 , V_18 -> V_31 ) ;
V_18 -> V_42 -= V_18 -> V_31 ;
V_39 -> V_24 |= V_43 ;
}
void F_12 ( struct V_15 * V_16 , unsigned int V_30 )
{
struct V_38 * V_39 = F_8 ( V_16 ) ;
const unsigned int V_31 =
( ( ! ! ( V_39 -> V_40 [ 0 ] ) ) * 4 ) + ( ( ! ! ( V_39 -> V_40 [ 1 ] ) ) * 4 ) ;
if ( ! ( V_39 -> V_24 & V_43 ) )
return;
F_13 ( V_16 , V_31 ) ;
memmove ( V_16 -> V_41 , V_16 -> V_41 + V_31 , V_30 ) ;
memcpy ( V_16 -> V_41 + V_30 , V_39 -> V_40 , V_31 ) ;
V_39 -> V_24 &= ~ V_43 ;
}
void F_14 ( struct V_15 * V_16 ,
unsigned int V_30 ,
struct V_44 * V_45 )
{
unsigned int V_46 = V_45 -> V_47 - V_30 ;
unsigned int V_48 = F_15 ( V_16 , V_30 ) ;
unsigned int V_31 ;
unsigned int V_37 ;
unsigned int V_49 = 0 ;
switch ( V_45 -> V_1 ) {
case V_5 :
case V_7 :
V_31 = 4 ;
V_37 = 4 ;
break;
case V_9 :
V_31 = 8 ;
V_37 = 4 ;
break;
case V_11 :
V_31 = 8 ;
V_37 = 8 ;
break;
default:
return;
}
if ( V_45 -> V_50 & V_51 ) {
F_13 ( V_16 , V_31 - V_48 ) ;
F_16 ( V_16 , V_37 ) ;
memmove ( V_16 -> V_41 + V_49 ,
V_16 -> V_41 + V_49 + ( V_31 - V_48 ) ,
V_30 ) ;
V_49 += V_30 ;
} else {
F_13 ( V_16 , V_31 + V_48 ) ;
if ( V_48 < V_37 )
F_16 ( V_16 , V_37 - V_48 ) ;
else if ( V_48 > V_37 )
F_17 ( V_16 , V_45 -> V_47 + V_31 + V_37 ) ;
memmove ( V_16 -> V_41 + V_49 ,
V_16 -> V_41 + V_49 + V_31 + V_48 ,
V_30 ) ;
V_49 += V_30 ;
}
memcpy ( V_16 -> V_41 + V_49 , V_45 -> V_40 , V_31 ) ;
V_49 += V_31 ;
if ( ! ( V_45 -> V_50 & V_51 ) ) {
memmove ( V_16 -> V_41 + V_49 ,
V_16 -> V_41 + V_49 + V_48 ,
V_46 ) ;
}
V_49 += V_46 ;
memcpy ( V_16 -> V_41 + V_49 , & V_45 -> V_52 , 4 ) ;
V_49 += V_37 ;
V_45 -> V_47 = V_49 ;
V_45 -> V_24 &= ~ V_53 ;
}
