static T_1 F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 = V_2 -> V_4 - V_2 -> V_5 ;
return V_3 > 0 ? V_3 : V_2 -> V_6 + V_3 ;
}
static void F_2 ( struct V_7 * V_8 ,
const void * V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_12 = V_2 -> V_6 - V_11 ;
T_3 * V_13 = & V_2 -> V_14 [ V_11 ] ;
T_2 V_3 = V_10 - V_12 ;
if ( V_3 <= 0 ) {
memcpy ( V_13 , V_9 , V_10 ) ;
} else {
memcpy ( V_13 , V_9 , V_12 ) ;
memcpy ( & V_2 -> V_14 [ 0 ] , ( T_3 * ) V_9 + V_12 , V_3 ) ;
}
}
static void F_3 ( struct V_15 * V_16 )
{
struct V_17 * V_9 ;
V_9 = F_4 ( V_16 , sizeof( * V_9 ) , V_18 , V_19 ) ;
if ( ! V_9 )
return;
V_9 -> V_20 = 0 ;
F_5 ( V_16 , V_9 ) ;
F_6 ( V_16 , V_9 ) ;
}
bool F_7 ( struct V_7 * V_8 , struct V_15 * V_16 ,
const void * V_9 , T_1 V_10 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
T_1 V_23 ;
V_2 = V_8 -> V_2 ;
V_22 = V_8 -> V_22 ;
if ( ! V_2 || V_8 -> V_24 ||
! V_22 || ! ( V_22 -> V_25 & V_26 ) )
return false ;
V_23 = F_1 ( V_2 ) ;
while ( V_10 > 0 ) {
T_1 V_27 = V_10 ;
if ( V_27 >= V_23 ) {
F_3 ( V_16 ) ;
V_23 = F_1 ( V_2 ) ;
}
if ( V_27 >= V_23 ) {
if ( F_8 ( V_23 <= V_2 -> V_28 ) ) {
V_8 -> V_24 = true ;
return false ;
}
V_27 = V_23 - V_2 -> V_28 ;
}
F_2 ( V_8 , V_9 , V_27 ,
V_2 -> V_5 ) ;
V_2 -> V_5 = ( V_2 -> V_5 + V_27 ) %
V_2 -> V_6 ;
V_22 -> V_25 += V_27 ;
V_23 -= V_27 ;
V_10 -= V_27 ;
V_9 += V_27 ;
}
return true ;
}
static bool F_9 ( struct V_7 * V_8 ,
struct V_15 * V_16 , T_2 V_29 , bool V_30 )
{
struct V_31 * V_9 ;
bool V_32 ;
V_9 = F_4 ( V_16 , sizeof( * V_9 ) , V_18 , V_33 ) ;
if ( ! V_9 )
return false ;
V_9 -> V_34 . V_35 = V_30 ? V_36 : V_37 ;
V_9 -> V_34 . V_11 = V_8 -> V_38 ;
V_9 -> V_34 . V_39 = V_40 ;
if ( V_29 >= 0 ) {
V_9 -> V_34 . V_35 |= V_41 | V_42 ;
V_9 -> V_43 = V_29 ;
}
F_5 ( V_16 , V_9 ) ;
if ( V_30 )
V_32 = F_10 ( V_9 -> V_34 . V_39 ) ;
else
V_32 = true ;
F_6 ( V_16 , V_9 ) ;
return V_32 ;
}
bool F_11 ( struct V_7 * V_8 , struct V_15 * V_16 ,
struct V_1 * V_2 , T_2 V_29 )
{
bool V_32 = false ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_28 = 256 ;
V_2 -> V_6 = V_8 -> V_44 - sizeof( struct V_1 ) ;
V_8 -> V_2 = V_2 ;
V_32 = F_9 ( V_8 , V_16 , V_29 , true ) ;
if ( ! V_32 )
F_12 ( V_8 , V_16 , V_29 ) ;
return V_32 ;
}
void F_12 ( struct V_7 * V_8 , struct V_15 * V_16 ,
T_2 V_29 )
{
V_8 -> V_24 = false ;
V_8 -> V_22 = NULL ;
V_8 -> V_2 = NULL ;
F_9 ( V_8 , V_16 , V_29 , false ) ;
}
bool F_13 ( struct V_7 * V_8 ,
struct V_15 * V_16 )
{
struct V_21 * V_22 ;
T_1 V_45 ;
if ( ! V_8 -> V_2 ||
! ( V_8 -> V_2 -> V_46 . V_47 & V_48 ) )
return false ;
F_8 ( V_8 -> V_24 || V_8 -> V_22 ) ;
V_45 = ( V_8 -> V_2 -> V_49 + 1 ) % V_50 ;
if ( V_45 == V_8 -> V_2 -> V_51 )
F_3 ( V_16 ) ;
if ( V_45 == V_8 -> V_2 -> V_51 )
return false ;
V_22 = & V_8 -> V_2 -> V_52 [ V_8 -> V_2 -> V_49 ] ;
V_22 -> V_25 = V_26 ;
V_8 -> V_2 -> V_49 = V_45 ;
V_8 -> V_22 = V_22 ;
return true ;
}
void F_14 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = V_8 -> V_22 ;
F_8 ( ! V_8 -> V_2 || ! V_22 ||
! ( V_22 -> V_25 & V_26 ) ) ;
V_22 -> V_25 &= ~ V_26 ;
V_8 -> V_24 = false ;
V_8 -> V_22 = NULL ;
}
void F_15 ( struct V_7 * V_8 ,
T_1 V_38 , T_1 V_44 )
{
V_8 -> V_38 = V_38 ;
V_8 -> V_44 = V_44 ;
}
