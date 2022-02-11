static void F_1 ( T_1 * V_1 )
{
* V_1 = * V_1 + 1 ;
}
static void F_2 ( T_1 * V_1 )
{
* V_1 = * V_1 - 1 ;
}
static int F_3 ( struct V_2 * V_3 , enum V_4 V_5 )
{
return V_3 -> V_6 & F_4 ( V_5 ) ;
}
static void F_5 ( struct V_2 * V_3 , enum V_4 V_5 )
{
V_3 -> V_6 |= F_4 ( V_5 ) ;
}
static void F_6 ( struct V_2 * V_3 , enum V_4 V_5 )
{
V_3 -> V_6 &= ~ F_4 ( V_5 ) ;
}
static void * F_7 ( struct V_7 * V_7 , T_2 V_8 )
{
unsigned char * V_9 ;
V_9 = F_8 ( V_7 ) ;
return V_9 + V_8 ;
}
static void F_9 ( void * V_10 )
{
F_10 ( V_10 ) ;
}
static T_3 F_11 ( struct V_2 * V_3 )
{
return V_3 -> V_6 & V_11 ;
}
static void F_12 ( struct V_2 * V_3 , T_2 V_12 )
{
V_3 -> V_6 = V_12 | ( V_3 -> V_6 & V_13 ) ;
}
static struct V_2 * F_13 ( struct V_2 * V_3 )
{
return (struct V_2 * )
( ( char * ) V_3 + V_3 -> V_14 + V_15 ) ;
}
static T_3 F_14 ( T_3 V_14 )
{
if ( F_15 ( V_14 > V_16 ) )
V_14 = V_16 ;
V_14 &= ~ V_17 ;
return ( V_14 - V_18 ) >> V_19 ;
}
static T_3 F_16 ( T_3 V_14 )
{
if ( F_15 ( V_14 < V_18 ) )
V_14 = V_18 ;
V_14 = F_17 ( V_14 , V_20 ) ;
return ( V_14 - V_18 ) >> V_19 ;
}
static T_3 F_18 ( struct V_21 * V_22 , T_3 V_14 ,
struct V_7 * * V_7 , T_3 * V_8 )
{
T_4 V_23 , V_24 ;
T_3 V_25 , V_26 , V_27 ;
if ( ! V_22 -> V_23 )
return 0 ;
V_26 = F_16 ( V_14 ) ;
V_24 = V_22 -> V_24 [ V_26 / V_28 ] ;
V_27 = V_26 % V_28 ;
if ( F_19 ( V_27 , & V_24 ) ) {
* V_7 = V_22 -> V_29 [ V_26 ] . V_7 ;
* V_8 = V_22 -> V_29 [ V_26 ] . V_8 ;
return V_26 ;
}
V_27 ++ ;
V_24 >>= V_27 ;
if ( ( V_27 != V_28 ) && V_24 ) {
V_26 += F_20 ( V_24 ) + 1 ;
* V_7 = V_22 -> V_29 [ V_26 ] . V_7 ;
* V_8 = V_22 -> V_29 [ V_26 ] . V_8 ;
return V_26 ;
}
V_25 = V_26 / V_28 ;
V_23 = ( V_22 -> V_23 ) >> ( V_25 + 1 ) ;
if ( ! V_23 )
return 0 ;
V_25 += F_20 ( V_23 ) + 1 ;
V_24 = V_22 -> V_24 [ V_25 ] ;
V_26 = ( V_25 * V_28 ) + F_20 ( V_24 ) ;
* V_7 = V_22 -> V_29 [ V_26 ] . V_7 ;
* V_8 = V_22 -> V_29 [ V_26 ] . V_8 ;
return V_26 ;
}
static void F_21 ( struct V_21 * V_22 , struct V_7 * V_7 , T_3 V_8 ,
struct V_2 * V_3 )
{
T_3 V_25 , V_26 ;
struct V_2 * V_30 ;
V_26 = F_14 ( V_3 -> V_14 ) ;
V_25 = V_26 / V_28 ;
V_3 -> V_31 . V_32 = NULL ;
V_3 -> V_31 . V_33 = 0 ;
V_3 -> V_31 . V_34 = V_22 -> V_29 [ V_26 ] . V_7 ;
V_3 -> V_31 . V_35 = V_22 -> V_29 [ V_26 ] . V_8 ;
V_22 -> V_29 [ V_26 ] . V_7 = V_7 ;
V_22 -> V_29 [ V_26 ] . V_8 = V_8 ;
if ( V_3 -> V_31 . V_34 ) {
V_30 = F_7 ( V_3 -> V_31 . V_34 ,
V_3 -> V_31 . V_35 ) ;
V_30 -> V_31 . V_32 = V_7 ;
V_30 -> V_31 . V_33 = V_8 ;
F_9 ( V_30 ) ;
return;
}
F_22 ( V_26 % V_28 , & V_22 -> V_24 [ V_25 ] ) ;
F_22 ( V_25 , & V_22 -> V_23 ) ;
}
static void F_23 ( struct V_21 * V_22 , struct V_7 * V_7 , T_3 V_8 ,
struct V_2 * V_3 , T_3 V_26 )
{
T_3 V_25 = V_26 / V_28 ;
struct V_2 * V_36 ;
if ( V_3 -> V_31 . V_32 ) {
V_36 = F_7 ( V_3 -> V_31 . V_32 ,
V_3 -> V_31 . V_33 ) ;
V_36 -> V_31 . V_34 = V_3 -> V_31 . V_34 ;
V_36 -> V_31 . V_35 = V_3 -> V_31 . V_35 ;
F_9 ( V_36 ) ;
}
if ( V_3 -> V_31 . V_34 ) {
V_36 = F_7 ( V_3 -> V_31 . V_34 ,
V_3 -> V_31 . V_35 ) ;
V_36 -> V_31 . V_32 = V_3 -> V_31 . V_32 ;
V_36 -> V_31 . V_33 = V_3 -> V_31 . V_33 ;
F_9 ( V_36 ) ;
}
if ( V_22 -> V_29 [ V_26 ] . V_7 == V_7
&& V_22 -> V_29 [ V_26 ] . V_8 == V_8 ) {
V_22 -> V_29 [ V_26 ] . V_7 = V_3 -> V_31 . V_34 ;
V_22 -> V_29 [ V_26 ] . V_8 = V_3 -> V_31 . V_35 ;
if ( V_22 -> V_29 [ V_26 ] . V_7 ) {
struct V_2 * V_36 ;
V_36 = F_7 ( V_22 -> V_29 [ V_26 ] . V_7 ,
V_22 -> V_29 [ V_26 ] . V_8 ) ;
V_36 -> V_31 . V_32 = NULL ;
V_36 -> V_31 . V_33 = 0 ;
F_9 ( V_36 ) ;
} else {
F_24 ( V_26 % V_28 ,
& V_22 -> V_24 [ V_25 ] ) ;
if ( ! V_22 -> V_24 [ V_25 ] )
F_24 ( V_25 , & V_22 -> V_23 ) ;
}
}
V_3 -> V_31 . V_32 = NULL ;
V_3 -> V_31 . V_33 = 0 ;
V_3 -> V_31 . V_34 = NULL ;
V_3 -> V_31 . V_35 = 0 ;
}
static int F_25 ( struct V_21 * V_22 , T_5 V_37 )
{
struct V_7 * V_7 ;
struct V_2 * V_3 ;
V_7 = F_26 ( V_37 ) ;
if ( F_15 ( ! V_7 ) )
return - V_38 ;
F_1 ( & V_22 -> V_39 ) ;
F_27 ( & V_22 -> V_40 ) ;
V_3 = F_7 ( V_7 , 0 ) ;
V_3 -> V_14 = V_41 - V_15 ;
F_5 ( V_3 , V_42 ) ;
F_6 ( V_3 , V_43 ) ;
F_12 ( V_3 , 0 ) ;
F_21 ( V_22 , V_7 , 0 , V_3 ) ;
F_9 ( V_3 ) ;
F_28 ( & V_22 -> V_40 ) ;
return 0 ;
}
struct V_21 * F_29 ( void )
{
T_3 V_44 ;
struct V_21 * V_22 ;
V_44 = F_30 ( sizeof( * V_22 ) , V_41 ) ;
V_22 = F_31 ( V_44 , V_45 ) ;
if ( ! V_22 )
return NULL ;
F_32 ( & V_22 -> V_40 ) ;
return V_22 ;
}
void F_33 ( struct V_21 * V_22 )
{
F_34 ( V_22 ) ;
}
int F_35 ( struct V_21 * V_22 , T_3 V_14 , struct V_7 * * V_7 ,
T_3 * V_8 , T_5 V_37 )
{
int error ;
T_3 V_46 , V_47 , V_48 , V_49 ;
struct V_2 * V_3 , * V_36 ;
* V_7 = NULL ;
* V_8 = 0 ;
V_48 = V_14 ;
if ( F_15 ( ! V_14 || V_14 > V_16 ) )
return - V_38 ;
V_14 = F_17 ( V_14 , V_15 ) ;
F_27 ( & V_22 -> V_40 ) ;
V_46 = F_18 ( V_22 , V_14 , V_7 , V_8 ) ;
if ( ! * V_7 ) {
F_28 ( & V_22 -> V_40 ) ;
if ( V_37 & V_50 )
return - V_38 ;
error = F_25 ( V_22 , V_37 ) ;
if ( F_15 ( error ) )
return error ;
F_27 ( & V_22 -> V_40 ) ;
V_46 = F_18 ( V_22 , V_14 , V_7 , V_8 ) ;
}
if ( ! * V_7 ) {
F_28 ( & V_22 -> V_40 ) ;
return - V_38 ;
}
V_3 = F_7 ( * V_7 , * V_8 ) ;
F_23 ( V_22 , * V_7 , * V_8 , V_3 , V_46 ) ;
V_49 = * V_8 + V_14 + V_15 ;
V_47 = V_3 -> V_14 - V_14 ;
V_36 = (struct V_2 * ) ( ( char * ) V_3 + V_14 + V_15 ) ;
if ( V_47 ) {
V_36 -> V_14 = V_47 - V_15 ;
F_5 ( V_36 , V_42 ) ;
F_6 ( V_36 , V_43 ) ;
F_12 ( V_36 , * V_8 ) ;
if ( V_36 -> V_14 >= V_18 )
F_21 ( V_22 , * V_7 , V_49 , V_36 ) ;
if ( V_49 + V_15 + V_36 -> V_14 != V_41 ) {
V_36 = F_13 ( V_36 ) ;
F_12 ( V_36 , V_49 ) ;
}
} else {
if ( V_49 != V_41 )
F_6 ( V_36 , V_43 ) ;
}
V_3 -> V_14 = V_48 ;
F_6 ( V_3 , V_42 ) ;
F_9 ( V_3 ) ;
F_28 ( & V_22 -> V_40 ) ;
* V_8 += V_15 ;
return 0 ;
}
void F_36 ( struct V_21 * V_22 , struct V_7 * V_7 , T_3 V_8 )
{
void * V_51 ;
struct V_2 * V_3 , * V_36 ;
V_8 -= V_15 ;
F_27 ( & V_22 -> V_40 ) ;
V_51 = F_7 ( V_7 , 0 ) ;
V_3 = (struct V_2 * ) ( ( char * ) V_51 + V_8 ) ;
F_37 ( F_3 ( V_3 , V_42 ) ) ;
V_3 -> V_14 = F_17 ( V_3 -> V_14 , V_15 ) ;
V_36 = F_13 ( V_3 ) ;
if ( V_8 + V_3 -> V_14 + V_15 == V_41 )
V_36 = NULL ;
if ( V_36 && F_3 ( V_36 , V_42 ) ) {
if ( V_36 -> V_14 >= V_18 ) {
F_23 ( V_22 , V_7 ,
V_8 + V_3 -> V_14 + V_15 , V_36 ,
F_14 ( V_36 -> V_14 ) ) ;
}
V_3 -> V_14 += V_36 -> V_14 + V_15 ;
}
if ( F_3 ( V_3 , V_43 ) ) {
V_36 = (struct V_2 * ) ( ( char * ) ( V_51 ) +
F_11 ( V_3 ) ) ;
V_8 = V_8 - V_36 -> V_14 - V_15 ;
if ( V_36 -> V_14 >= V_18 )
F_23 ( V_22 , V_7 , V_8 , V_36 ,
F_14 ( V_36 -> V_14 ) ) ;
V_36 -> V_14 += V_3 -> V_14 + V_15 ;
V_3 = V_36 ;
}
if ( V_3 -> V_14 == V_41 - V_15 ) {
F_9 ( V_51 ) ;
F_28 ( & V_22 -> V_40 ) ;
F_38 ( V_7 ) ;
F_2 ( & V_22 -> V_39 ) ;
return;
}
F_5 ( V_3 , V_42 ) ;
if ( V_3 -> V_14 >= V_18 )
F_21 ( V_22 , V_7 , V_8 , V_3 ) ;
if ( V_8 + V_3 -> V_14 + V_15 != V_41 ) {
V_36 = F_13 ( V_3 ) ;
F_5 ( V_36 , V_43 ) ;
F_12 ( V_36 , V_8 ) ;
}
F_9 ( V_51 ) ;
F_28 ( & V_22 -> V_40 ) ;
}
T_3 F_39 ( void * V_52 )
{
struct V_2 * V_53 ;
V_53 = (struct V_2 * ) ( ( char * ) ( V_52 ) - V_15 ) ;
return V_53 -> V_14 ;
}
T_1 F_40 ( struct V_21 * V_22 )
{
return V_22 -> V_39 << V_54 ;
}
