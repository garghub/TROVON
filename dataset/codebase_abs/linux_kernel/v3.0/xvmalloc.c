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
static void * F_7 ( struct V_7 * V_7 , T_2 V_8 , enum V_9 type )
{
unsigned char * V_10 ;
V_10 = F_8 ( V_7 , type ) ;
return V_10 + V_8 ;
}
static void F_9 ( void * V_11 , enum V_9 type )
{
F_10 ( V_11 , type ) ;
}
static T_3 F_11 ( struct V_2 * V_3 )
{
return V_3 -> V_6 & V_12 ;
}
static void F_12 ( struct V_2 * V_3 , T_2 V_13 )
{
V_3 -> V_6 = V_13 | ( V_3 -> V_6 & V_14 ) ;
}
static struct V_2 * F_13 ( struct V_2 * V_3 )
{
return (struct V_2 * )
( ( char * ) V_3 + V_3 -> V_15 + V_16 ) ;
}
static T_3 F_14 ( T_3 V_15 )
{
if ( F_15 ( V_15 > V_17 ) )
V_15 = V_17 ;
V_15 &= ~ V_18 ;
return ( V_15 - V_19 ) >> V_20 ;
}
static T_3 F_16 ( T_3 V_15 )
{
if ( F_15 ( V_15 < V_19 ) )
V_15 = V_19 ;
V_15 = F_17 ( V_15 , V_21 ) ;
return ( V_15 - V_19 ) >> V_20 ;
}
static T_3 F_18 ( struct V_22 * V_23 , T_3 V_15 ,
struct V_7 * * V_7 , T_3 * V_8 )
{
T_4 V_24 , V_25 ;
T_3 V_26 , V_27 , V_28 ;
if ( ! V_23 -> V_24 )
return 0 ;
V_27 = F_16 ( V_15 ) ;
V_25 = V_23 -> V_25 [ V_27 / V_29 ] ;
V_28 = V_27 % V_29 ;
if ( F_19 ( V_28 , & V_25 ) ) {
* V_7 = V_23 -> V_30 [ V_27 ] . V_7 ;
* V_8 = V_23 -> V_30 [ V_27 ] . V_8 ;
return V_27 ;
}
V_28 ++ ;
V_25 >>= V_28 ;
if ( ( V_28 != V_29 ) && V_25 ) {
V_27 += F_20 ( V_25 ) + 1 ;
* V_7 = V_23 -> V_30 [ V_27 ] . V_7 ;
* V_8 = V_23 -> V_30 [ V_27 ] . V_8 ;
return V_27 ;
}
V_26 = V_27 / V_29 ;
V_24 = ( V_23 -> V_24 ) >> ( V_26 + 1 ) ;
if ( ! V_24 )
return 0 ;
V_26 += F_20 ( V_24 ) + 1 ;
V_25 = V_23 -> V_25 [ V_26 ] ;
V_27 = ( V_26 * V_29 ) + F_20 ( V_25 ) ;
* V_7 = V_23 -> V_30 [ V_27 ] . V_7 ;
* V_8 = V_23 -> V_30 [ V_27 ] . V_8 ;
return V_27 ;
}
static void F_21 ( struct V_22 * V_23 , struct V_7 * V_7 , T_3 V_8 ,
struct V_2 * V_3 )
{
T_3 V_26 , V_27 ;
struct V_2 * V_31 ;
V_27 = F_14 ( V_3 -> V_15 ) ;
V_26 = V_27 / V_29 ;
V_3 -> V_32 . V_33 = NULL ;
V_3 -> V_32 . V_34 = 0 ;
V_3 -> V_32 . V_35 = V_23 -> V_30 [ V_27 ] . V_7 ;
V_3 -> V_32 . V_36 = V_23 -> V_30 [ V_27 ] . V_8 ;
V_23 -> V_30 [ V_27 ] . V_7 = V_7 ;
V_23 -> V_30 [ V_27 ] . V_8 = V_8 ;
if ( V_3 -> V_32 . V_35 ) {
V_31 = F_7 ( V_3 -> V_32 . V_35 ,
V_3 -> V_32 . V_36 , V_37 ) ;
V_31 -> V_32 . V_33 = V_7 ;
V_31 -> V_32 . V_34 = V_8 ;
F_9 ( V_31 , V_37 ) ;
return;
}
F_22 ( V_27 % V_29 , & V_23 -> V_25 [ V_26 ] ) ;
F_22 ( V_26 , & V_23 -> V_24 ) ;
}
static void F_23 ( struct V_22 * V_23 , struct V_7 * V_7 , T_3 V_8 ,
struct V_2 * V_3 , T_3 V_27 )
{
T_3 V_26 = V_27 / V_29 ;
struct V_2 * V_38 ;
if ( V_3 -> V_32 . V_33 ) {
V_38 = F_7 ( V_3 -> V_32 . V_33 ,
V_3 -> V_32 . V_34 , V_37 ) ;
V_38 -> V_32 . V_35 = V_3 -> V_32 . V_35 ;
V_38 -> V_32 . V_36 = V_3 -> V_32 . V_36 ;
F_9 ( V_38 , V_37 ) ;
}
if ( V_3 -> V_32 . V_35 ) {
V_38 = F_7 ( V_3 -> V_32 . V_35 ,
V_3 -> V_32 . V_36 , V_37 ) ;
V_38 -> V_32 . V_33 = V_3 -> V_32 . V_33 ;
V_38 -> V_32 . V_34 = V_3 -> V_32 . V_34 ;
F_9 ( V_38 , V_37 ) ;
}
if ( V_23 -> V_30 [ V_27 ] . V_7 == V_7
&& V_23 -> V_30 [ V_27 ] . V_8 == V_8 ) {
V_23 -> V_30 [ V_27 ] . V_7 = V_3 -> V_32 . V_35 ;
V_23 -> V_30 [ V_27 ] . V_8 = V_3 -> V_32 . V_36 ;
if ( V_23 -> V_30 [ V_27 ] . V_7 ) {
struct V_2 * V_38 ;
V_38 = F_7 ( V_23 -> V_30 [ V_27 ] . V_7 ,
V_23 -> V_30 [ V_27 ] . V_8 ,
V_37 ) ;
V_38 -> V_32 . V_33 = NULL ;
V_38 -> V_32 . V_34 = 0 ;
F_9 ( V_38 , V_37 ) ;
} else {
F_24 ( V_27 % V_29 ,
& V_23 -> V_25 [ V_26 ] ) ;
if ( ! V_23 -> V_25 [ V_26 ] )
F_24 ( V_26 , & V_23 -> V_24 ) ;
}
}
V_3 -> V_32 . V_33 = NULL ;
V_3 -> V_32 . V_34 = 0 ;
V_3 -> V_32 . V_35 = NULL ;
V_3 -> V_32 . V_36 = 0 ;
}
static int F_25 ( struct V_22 * V_23 , T_5 V_39 )
{
struct V_7 * V_7 ;
struct V_2 * V_3 ;
V_7 = F_26 ( V_39 ) ;
if ( F_15 ( ! V_7 ) )
return - V_40 ;
F_1 ( & V_23 -> V_41 ) ;
F_27 ( & V_23 -> V_42 ) ;
V_3 = F_7 ( V_7 , 0 , V_43 ) ;
V_3 -> V_15 = V_44 - V_16 ;
F_5 ( V_3 , V_45 ) ;
F_6 ( V_3 , V_46 ) ;
F_12 ( V_3 , 0 ) ;
F_21 ( V_23 , V_7 , 0 , V_3 ) ;
F_9 ( V_3 , V_43 ) ;
F_28 ( & V_23 -> V_42 ) ;
return 0 ;
}
struct V_22 * F_29 ( void )
{
T_3 V_47 ;
struct V_22 * V_23 ;
V_47 = F_30 ( sizeof( * V_23 ) , V_44 ) ;
V_23 = F_31 ( V_47 , V_48 ) ;
if ( ! V_23 )
return NULL ;
F_32 ( & V_23 -> V_42 ) ;
return V_23 ;
}
void F_33 ( struct V_22 * V_23 )
{
F_34 ( V_23 ) ;
}
int F_35 ( struct V_22 * V_23 , T_3 V_15 , struct V_7 * * V_7 ,
T_3 * V_8 , T_5 V_39 )
{
int error ;
T_3 V_49 , V_50 , V_51 , V_52 ;
struct V_2 * V_3 , * V_38 ;
* V_7 = NULL ;
* V_8 = 0 ;
V_51 = V_15 ;
if ( F_15 ( ! V_15 || V_15 > V_17 ) )
return - V_40 ;
V_15 = F_17 ( V_15 , V_16 ) ;
F_27 ( & V_23 -> V_42 ) ;
V_49 = F_18 ( V_23 , V_15 , V_7 , V_8 ) ;
if ( ! * V_7 ) {
F_28 ( & V_23 -> V_42 ) ;
if ( V_39 & V_53 )
return - V_40 ;
error = F_25 ( V_23 , V_39 ) ;
if ( F_15 ( error ) )
return error ;
F_27 ( & V_23 -> V_42 ) ;
V_49 = F_18 ( V_23 , V_15 , V_7 , V_8 ) ;
}
if ( ! * V_7 ) {
F_28 ( & V_23 -> V_42 ) ;
return - V_40 ;
}
V_3 = F_7 ( * V_7 , * V_8 , V_43 ) ;
F_23 ( V_23 , * V_7 , * V_8 , V_3 , V_49 ) ;
V_52 = * V_8 + V_15 + V_16 ;
V_50 = V_3 -> V_15 - V_15 ;
V_38 = (struct V_2 * ) ( ( char * ) V_3 + V_15 + V_16 ) ;
if ( V_50 ) {
V_38 -> V_15 = V_50 - V_16 ;
F_5 ( V_38 , V_45 ) ;
F_6 ( V_38 , V_46 ) ;
F_12 ( V_38 , * V_8 ) ;
if ( V_38 -> V_15 >= V_19 )
F_21 ( V_23 , * V_7 , V_52 , V_38 ) ;
if ( V_52 + V_16 + V_38 -> V_15 != V_44 ) {
V_38 = F_13 ( V_38 ) ;
F_12 ( V_38 , V_52 ) ;
}
} else {
if ( V_52 != V_44 )
F_6 ( V_38 , V_46 ) ;
}
V_3 -> V_15 = V_51 ;
F_6 ( V_3 , V_45 ) ;
F_9 ( V_3 , V_43 ) ;
F_28 ( & V_23 -> V_42 ) ;
* V_8 += V_16 ;
return 0 ;
}
void F_36 ( struct V_22 * V_23 , struct V_7 * V_7 , T_3 V_8 )
{
void * V_54 ;
struct V_2 * V_3 , * V_38 ;
V_8 -= V_16 ;
F_27 ( & V_23 -> V_42 ) ;
V_54 = F_7 ( V_7 , 0 , V_43 ) ;
V_3 = (struct V_2 * ) ( ( char * ) V_54 + V_8 ) ;
F_37 ( F_3 ( V_3 , V_45 ) ) ;
V_3 -> V_15 = F_17 ( V_3 -> V_15 , V_16 ) ;
V_38 = F_13 ( V_3 ) ;
if ( V_8 + V_3 -> V_15 + V_16 == V_44 )
V_38 = NULL ;
if ( V_38 && F_3 ( V_38 , V_45 ) ) {
if ( V_38 -> V_15 >= V_19 ) {
F_23 ( V_23 , V_7 ,
V_8 + V_3 -> V_15 + V_16 , V_38 ,
F_14 ( V_38 -> V_15 ) ) ;
}
V_3 -> V_15 += V_38 -> V_15 + V_16 ;
}
if ( F_3 ( V_3 , V_46 ) ) {
V_38 = (struct V_2 * ) ( ( char * ) ( V_54 ) +
F_11 ( V_3 ) ) ;
V_8 = V_8 - V_38 -> V_15 - V_16 ;
if ( V_38 -> V_15 >= V_19 )
F_23 ( V_23 , V_7 , V_8 , V_38 ,
F_14 ( V_38 -> V_15 ) ) ;
V_38 -> V_15 += V_3 -> V_15 + V_16 ;
V_3 = V_38 ;
}
if ( V_3 -> V_15 == V_44 - V_16 ) {
F_9 ( V_54 , V_43 ) ;
F_28 ( & V_23 -> V_42 ) ;
F_38 ( V_7 ) ;
F_2 ( & V_23 -> V_41 ) ;
return;
}
F_5 ( V_3 , V_45 ) ;
if ( V_3 -> V_15 >= V_19 )
F_21 ( V_23 , V_7 , V_8 , V_3 ) ;
if ( V_8 + V_3 -> V_15 + V_16 != V_44 ) {
V_38 = F_13 ( V_3 ) ;
F_5 ( V_38 , V_46 ) ;
F_12 ( V_38 , V_8 ) ;
}
F_9 ( V_54 , V_43 ) ;
F_28 ( & V_23 -> V_42 ) ;
}
T_3 F_39 ( void * V_55 )
{
struct V_2 * V_56 ;
V_56 = (struct V_2 * ) ( ( char * ) ( V_55 ) - V_16 ) ;
return V_56 -> V_15 ;
}
T_1 F_40 ( struct V_22 * V_23 )
{
return V_23 -> V_41 << V_57 ;
}
