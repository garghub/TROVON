static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
T_2 V_6 = F_2 ( V_3 , V_4 ) ;
T_2 V_7 = F_2 ( V_2 -> V_8 , V_4 ) ;
struct V_9 * V_10 ;
V_10 = F_3 ( V_2 , V_11 + V_4 ) ;
if ( V_7 == V_6 )
continue;
F_4 ( V_10 , V_6 , V_4 ) ;
}
V_2 -> V_8 = V_3 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_12 ;
T_1 V_13 = V_2 -> V_14 ^ V_3 ;
V_2 -> V_14 = V_3 ;
F_6 (bit, (unsigned long *)&diff, X86_PMC_IDX_MAX)
F_7 ( V_2 , V_12 ) ;
}
static unsigned F_8 ( struct V_1 * V_2 ,
T_2 V_15 ,
T_2 V_16 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_9 ( V_17 ) ; V_4 ++ )
if ( V_17 [ V_4 ] . V_18 == V_15
&& V_17 [ V_4 ] . V_16 == V_16
&& ( V_2 -> V_19 & ( 1 << V_4 ) ) )
break;
if ( V_4 == F_9 ( V_17 ) )
return V_20 ;
return V_17 [ V_4 ] . V_21 ;
}
static unsigned F_10 ( int V_22 )
{
if ( V_22 >= F_9 ( V_23 ) )
return V_20 ;
return V_17 [ V_23 [ V_22 ] ] . V_21 ;
}
static bool F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
return F_13 ( V_10 -> V_22 , ( unsigned long * ) & V_2 -> V_14 ) ;
}
static struct V_9 * F_14 ( struct V_1 * V_2 , int V_24 )
{
if ( V_24 < V_25 )
return F_15 ( V_2 , V_26 + V_24 ,
V_26 ) ;
else {
T_3 V_22 = V_24 - V_25 ;
return F_3 ( V_2 , V_22 + V_11 ) ;
}
}
static int F_16 ( struct V_27 * V_28 , unsigned V_22 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
bool V_29 = V_22 & ( 1u << 30 ) ;
V_22 &= ~ ( 3u << 30 ) ;
return ( ! V_29 && V_22 >= V_2 -> V_30 ) ||
( V_29 && V_22 >= V_2 -> V_5 ) ;
}
static struct V_9 * F_18 ( struct V_27 * V_28 ,
unsigned V_22 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
bool V_29 = V_22 & ( 1u << 30 ) ;
struct V_9 * V_31 ;
V_22 &= ~ ( 3u << 30 ) ;
if ( ! V_29 && V_22 >= V_2 -> V_30 )
return NULL ;
if ( V_29 && V_22 >= V_2 -> V_5 )
return NULL ;
V_31 = V_29 ? V_2 -> V_32 : V_2 -> V_33 ;
return & V_31 [ V_22 ] ;
}
static bool F_19 ( struct V_27 * V_28 , T_3 V_34 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_35 ;
switch ( V_34 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_35 = V_2 -> V_40 > 1 ;
break;
default:
V_35 = F_15 ( V_2 , V_34 , V_41 ) ||
F_15 ( V_2 , V_34 , V_26 ) ||
F_3 ( V_2 , V_34 ) ;
break;
}
return V_35 ;
}
static int F_20 ( struct V_27 * V_28 , T_3 V_34 , T_1 * V_3 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
struct V_9 * V_10 ;
switch ( V_34 ) {
case V_36 :
* V_3 = V_2 -> V_8 ;
return 0 ;
case V_37 :
* V_3 = V_2 -> V_42 ;
return 0 ;
case V_38 :
* V_3 = V_2 -> V_14 ;
return 0 ;
case V_39 :
* V_3 = V_2 -> V_43 ;
return 0 ;
default:
if ( ( V_10 = F_15 ( V_2 , V_34 , V_41 ) ) ||
( V_10 = F_3 ( V_2 , V_34 ) ) ) {
* V_3 = F_21 ( V_10 ) ;
return 0 ;
} else if ( ( V_10 = F_15 ( V_2 , V_34 , V_26 ) ) ) {
* V_3 = V_10 -> V_18 ;
return 0 ;
}
}
return 1 ;
}
static int F_22 ( struct V_27 * V_28 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
struct V_9 * V_10 ;
T_3 V_34 = V_45 -> V_46 ;
T_1 V_3 = V_45 -> V_3 ;
switch ( V_34 ) {
case V_36 :
if ( V_2 -> V_8 == V_3 )
return 0 ;
if ( ! ( V_3 & 0xfffffffffffff444ull ) ) {
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
break;
case V_37 :
if ( V_45 -> V_47 ) {
V_2 -> V_42 = V_3 ;
return 0 ;
}
break;
case V_38 :
if ( V_2 -> V_14 == V_3 )
return 0 ;
if ( ! ( V_3 & V_2 -> V_48 ) ) {
F_5 ( V_2 , V_3 ) ;
return 0 ;
}
break;
case V_39 :
if ( ! ( V_3 & ( V_2 -> V_48 & ~ ( 3ull << 62 ) ) ) ) {
if ( ! V_45 -> V_47 )
V_2 -> V_42 &= ~ V_3 ;
V_2 -> V_43 = V_3 ;
return 0 ;
}
break;
default:
if ( ( V_10 = F_15 ( V_2 , V_34 , V_41 ) ) ||
( V_10 = F_3 ( V_2 , V_34 ) ) ) {
if ( ! V_45 -> V_47 )
V_3 = ( V_49 ) ( V_50 ) V_3 ;
V_10 -> V_51 += V_3 - F_21 ( V_10 ) ;
return 0 ;
} else if ( ( V_10 = F_15 ( V_2 , V_34 , V_26 ) ) ) {
if ( V_3 == V_10 -> V_18 )
return 0 ;
if ( ! ( V_3 & V_2 -> V_52 ) ) {
F_23 ( V_10 , V_3 ) ;
return 0 ;
}
}
}
return 1 ;
}
static void F_24 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
struct V_53 * V_54 ;
union V_55 V_56 ;
union V_57 V_58 ;
V_2 -> V_30 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_59 [ V_60 ] = 0 ;
V_2 -> V_59 [ V_61 ] = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_52 = 0xffffffff00200000ull ;
V_54 = F_25 ( V_28 , 0xa , 0 ) ;
if ( ! V_54 )
return;
V_56 . V_62 = V_54 -> V_56 ;
V_58 . V_62 = V_54 -> V_58 ;
V_2 -> V_40 = V_56 . V_63 . V_64 ;
if ( ! V_2 -> V_40 )
return;
V_2 -> V_30 = F_26 ( int , V_56 . V_63 . V_65 ,
V_66 ) ;
V_2 -> V_59 [ V_60 ] = ( ( T_1 ) 1 << V_56 . V_63 . V_67 ) - 1 ;
V_2 -> V_19 = ~ V_54 -> V_68 &
( ( 1ull << V_56 . V_63 . V_69 ) - 1 ) ;
if ( V_2 -> V_40 == 1 ) {
V_2 -> V_5 = 0 ;
} else {
V_2 -> V_5 =
F_26 ( int , V_58 . V_63 . V_70 ,
V_71 ) ;
V_2 -> V_59 [ V_61 ] =
( ( T_1 ) 1 << V_58 . V_63 . V_72 ) - 1 ;
}
V_2 -> V_14 = ( ( 1 << V_2 -> V_30 ) - 1 ) |
( ( ( 1ull << V_2 -> V_5 ) - 1 ) << V_25 ) ;
V_2 -> V_48 = ~ V_2 -> V_14 ;
V_54 = F_25 ( V_28 , 7 , 0 ) ;
if ( V_54 &&
( F_27 ( V_73 ) || F_27 ( V_74 ) ) &&
( V_54 -> V_68 & ( V_73 | V_74 ) ) )
V_2 -> V_52 ^= V_75 | V_76 ;
}
static void F_28 ( struct V_27 * V_28 )
{
int V_4 ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
for ( V_4 = 0 ; V_4 < V_66 ; V_4 ++ ) {
V_2 -> V_33 [ V_4 ] . type = V_60 ;
V_2 -> V_33 [ V_4 ] . V_28 = V_28 ;
V_2 -> V_33 [ V_4 ] . V_22 = V_4 ;
}
for ( V_4 = 0 ; V_4 < V_71 ; V_4 ++ ) {
V_2 -> V_32 [ V_4 ] . type = V_61 ;
V_2 -> V_32 [ V_4 ] . V_28 = V_28 ;
V_2 -> V_32 [ V_4 ] . V_22 = V_4 + V_25 ;
}
}
static void F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_66 ; V_4 ++ ) {
struct V_9 * V_10 = & V_2 -> V_33 [ V_4 ] ;
F_30 ( V_10 ) ;
V_10 -> V_51 = V_10 -> V_18 = 0 ;
}
for ( V_4 = 0 ; V_4 < V_71 ; V_4 ++ )
F_30 ( & V_2 -> V_32 [ V_4 ] ) ;
V_2 -> V_8 = V_2 -> V_14 = V_2 -> V_42 =
V_2 -> V_43 = 0 ;
}
