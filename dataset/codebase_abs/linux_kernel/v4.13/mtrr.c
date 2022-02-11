static bool F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case 0x200 ... 0x200 + 2 * V_2 - 1 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
}
return false ;
}
static bool F_2 ( unsigned V_16 )
{
return V_16 < 8 && ( 1 << V_16 ) & 0xf3 ;
}
static bool F_3 ( unsigned V_16 )
{
return V_16 < 8 && ( 1 << V_16 ) & 0x73 ;
}
bool F_4 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
int V_20 ;
T_2 V_21 ;
if ( ! F_1 ( V_1 ) )
return false ;
if ( V_1 == V_15 ) {
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
if ( ! F_2 ( ( V_19 >> ( V_20 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_1 == V_14 ) {
if ( V_19 & ~ 0xcff )
return false ;
return F_3 ( V_19 & 0xff ) ;
} else if ( V_1 >= V_3 && V_1 <= V_13 ) {
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
if ( ! F_3 ( ( V_19 >> ( V_20 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
F_5 ( ! ( V_1 >= 0x200 && V_1 < 0x200 + 2 * V_2 ) ) ;
V_21 = ( ~ 0ULL ) << F_6 ( V_18 ) ;
if ( ( V_1 & 1 ) == 0 ) {
if ( ! F_3 ( V_19 & 0xff ) )
return false ;
V_21 |= 0xf00 ;
} else
V_21 |= 0x7ff ;
if ( V_19 & V_21 ) {
F_7 ( V_18 , 0 ) ;
return false ;
}
return true ;
}
static bool F_8 ( struct V_22 * V_23 )
{
return ! ! ( V_23 -> V_24 & V_25 ) ;
}
static bool F_9 ( struct V_22 * V_23 )
{
return ! ! ( V_23 -> V_24 & V_26 ) ;
}
static T_3 F_10 ( struct V_22 * V_23 )
{
return V_23 -> V_24 & V_27 ;
}
static T_3 F_11 ( struct V_17 * V_18 )
{
if ( F_12 ( V_18 ) )
return V_28 ;
else
return V_29 ;
}
static T_2 F_13 ( int V_30 )
{
return 8 << V_31 [ V_30 ] . V_32 ;
}
static bool F_14 ( T_1 V_1 , int * V_30 , int * V_33 )
{
switch ( V_1 ) {
case V_3 :
* V_30 = 0 ;
* V_33 = 0 ;
break;
case V_4 ... V_5 :
* V_30 = 1 ;
* V_33 = V_1 - V_4 ;
break;
case V_6 ... V_13 :
* V_30 = 2 ;
* V_33 = V_1 - V_6 ;
break;
default:
return false ;
}
return true ;
}
static void F_15 ( int V_30 , int V_33 , T_2 * V_34 , T_2 * V_35 )
{
struct V_36 * V_37 = & V_31 [ V_30 ] ;
T_2 V_38 = F_13 ( V_30 ) ;
* V_34 = V_37 -> V_34 + V_33 * V_38 ;
* V_35 = * V_34 + V_38 ;
F_5 ( * V_35 > V_37 -> V_35 ) ;
}
static int F_16 ( int V_30 , int V_33 )
{
struct V_36 * V_37 = & V_31 [ V_30 ] ;
F_5 ( V_37 -> V_34 + V_33 * F_13 ( V_30 )
> V_37 -> V_35 ) ;
return V_37 -> V_39 + 8 * V_33 ;
}
static int F_17 ( int V_30 )
{
struct V_36 * V_37 = & V_31 [ V_30 ] ;
int V_40 ;
V_40 = ( V_37 -> V_35 - V_37 -> V_34 ) >> V_37 -> V_32 ;
return V_37 -> V_39 + V_40 - 1 ;
}
static bool F_18 ( T_1 V_1 , T_2 * V_34 , T_2 * V_35 )
{
int V_30 , V_33 ;
if ( ! F_14 ( V_1 , & V_30 , & V_33 ) )
return false ;
F_15 ( V_30 , V_33 , V_34 , V_35 ) ;
return true ;
}
static int F_19 ( T_1 V_1 )
{
int V_30 , V_33 ;
if ( ! F_14 ( V_1 , & V_30 , & V_33 ) )
return - 1 ;
return F_16 ( V_30 , V_33 ) ;
}
static int F_20 ( T_2 V_41 )
{
struct V_36 * V_37 ;
int V_30 , V_42 = F_21 ( V_31 ) ;
for ( V_30 = 0 ; V_30 < V_42 ; V_30 ++ ) {
V_37 = & V_31 [ V_30 ] ;
if ( V_37 -> V_34 <= V_41 && V_41 < V_37 -> V_35 )
return V_30 ;
}
return - 1 ;
}
static int F_22 ( T_2 V_41 , int V_30 )
{
struct V_36 * V_37 ;
int V_43 ;
V_37 = & V_31 [ V_30 ] ;
V_43 = V_37 -> V_39 ;
V_43 += ( V_41 - V_37 -> V_34 ) >> V_37 -> V_32 ;
return V_43 ;
}
static T_2 F_23 ( int V_30 , int V_43 )
{
struct V_36 * V_37 = & V_31 [ V_30 ] ;
int V_44 = V_43 - V_37 -> V_39 ;
return V_37 -> V_34 + ( ( V_44 + 1 ) << V_37 -> V_32 ) ;
}
static void F_24 ( struct V_45 * V_46 , T_2 * V_34 , T_2 * V_35 )
{
T_2 V_21 ;
* V_34 = V_46 -> V_47 & V_48 ;
V_21 = V_46 -> V_21 & V_48 ;
* V_35 = ( * V_34 | ~ V_21 ) + 1 ;
}
static void F_25 ( struct V_17 * V_18 , T_1 V_1 )
{
struct V_22 * V_23 = & V_18 -> V_49 . V_23 ;
T_4 V_34 , V_35 ;
int V_43 ;
if ( V_1 == V_15 || ! V_50 ||
! F_26 ( V_18 -> V_51 ) )
return;
if ( ! F_8 ( V_23 ) && V_1 != V_14 )
return;
if ( F_18 ( V_1 , & V_34 , & V_35 ) ) {
if ( ! F_9 ( V_23 ) )
return;
} else if ( V_1 == V_14 ) {
V_34 = 0x0 ;
V_35 = ~ 0ULL ;
} else {
V_43 = ( V_1 - 0x200 ) / 2 ;
F_24 ( & V_23 -> V_52 [ V_43 ] , & V_34 , & V_35 ) ;
}
F_27 ( V_18 -> V_51 , F_28 ( V_34 ) , F_28 ( V_35 ) ) ;
}
static bool F_29 ( struct V_45 * V_46 )
{
return ( V_46 -> V_21 & ( 1 << 11 ) ) != 0 ;
}
static void F_30 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
struct V_22 * V_23 = & V_18 -> V_49 . V_23 ;
struct V_45 * V_53 , * V_54 ;
int V_43 , V_55 ;
V_43 = ( V_1 - 0x200 ) / 2 ;
V_55 = V_1 - 0x200 - 2 * V_43 ;
V_54 = & V_23 -> V_52 [ V_43 ] ;
if ( F_29 ( V_54 ) )
F_31 ( & V_23 -> V_52 [ V_43 ] . V_56 ) ;
if ( ! V_55 )
V_54 -> V_47 = V_19 ;
else
V_54 -> V_21 = V_19 | ( - 1LL << F_6 ( V_18 ) ) ;
if ( F_29 ( V_54 ) ) {
F_32 (tmp, &mtrr_state->head, node)
if ( V_54 -> V_47 >= V_53 -> V_47 )
break;
F_33 ( & V_54 -> V_56 , & V_53 -> V_56 ) ;
}
}
int F_34 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
int V_43 ;
if ( ! F_4 ( V_18 , V_1 , V_19 ) )
return 1 ;
V_43 = F_19 ( V_1 ) ;
if ( V_43 >= 0 )
* ( T_2 * ) & V_18 -> V_49 . V_23 . V_57 [ V_43 ] = V_19 ;
else if ( V_1 == V_14 )
V_18 -> V_49 . V_23 . V_24 = V_19 ;
else if ( V_1 == V_15 )
V_18 -> V_49 . V_58 = V_19 ;
else
F_30 ( V_18 , V_1 , V_19 ) ;
F_25 ( V_18 , V_1 ) ;
return 0 ;
}
int F_35 ( struct V_17 * V_18 , T_1 V_1 , T_2 * V_59 )
{
int V_43 ;
if ( V_1 == V_60 ) {
* V_59 = 0x500 | V_2 ;
return 0 ;
}
if ( ! F_1 ( V_1 ) )
return 1 ;
V_43 = F_19 ( V_1 ) ;
if ( V_43 >= 0 )
* V_59 = * ( T_2 * ) & V_18 -> V_49 . V_23 . V_57 [ V_43 ] ;
else if ( V_1 == V_14 )
* V_59 = V_18 -> V_49 . V_23 . V_24 ;
else if ( V_1 == V_15 )
* V_59 = V_18 -> V_49 . V_58 ;
else {
int V_55 ;
V_43 = ( V_1 - 0x200 ) / 2 ;
V_55 = V_1 - 0x200 - 2 * V_43 ;
if ( ! V_55 )
* V_59 = V_18 -> V_49 . V_23 . V_52 [ V_43 ] . V_47 ;
else
* V_59 = V_18 -> V_49 . V_23 . V_52 [ V_43 ] . V_21 ;
* V_59 &= ( 1ULL << F_6 ( V_18 ) ) - 1 ;
}
return 0 ;
}
void F_36 ( struct V_17 * V_18 )
{
F_37 ( & V_18 -> V_49 . V_23 . V_61 ) ;
}
static bool F_38 ( struct V_62 * V_63 )
{
int V_30 , V_43 ;
if ( ! F_9 ( V_63 -> V_23 ) )
return false ;
V_30 = F_20 ( V_63 -> V_34 ) ;
if ( V_30 < 0 )
return false ;
V_63 -> V_64 = true ;
V_43 = F_22 ( V_63 -> V_34 , V_30 ) ;
V_63 -> V_43 = V_43 ;
V_63 -> V_30 = V_30 ;
return true ;
}
static bool F_39 ( struct V_62 * V_63 ,
struct V_45 * V_46 )
{
T_2 V_34 , V_35 ;
F_24 ( V_46 , & V_34 , & V_35 ) ;
if ( ! ( V_34 >= V_63 -> V_35 || V_35 <= V_63 -> V_34 ) ) {
V_63 -> V_46 = V_46 ;
V_63 -> V_65 |= V_63 -> V_66 < V_34 ;
V_63 -> V_66 = F_40 ( V_63 -> V_66 , V_35 ) ;
return true ;
}
return false ;
}
static void F_41 ( struct V_62 * V_63 )
{
struct V_22 * V_23 = V_63 -> V_23 ;
F_42 (iter->range, &mtrr_state->head, node)
if ( F_39 ( V_63 , V_63 -> V_46 ) )
return;
V_63 -> V_46 = NULL ;
V_63 -> V_65 |= V_63 -> V_66 < V_63 -> V_35 ;
}
static void F_43 ( struct V_62 * V_63 )
{
struct V_22 * V_23 = V_63 -> V_23 ;
V_63 -> V_64 = false ;
V_63 -> V_66 = V_63 -> V_34 ;
V_63 -> V_46 = NULL ;
V_63 -> V_46 = F_44 ( V_63 -> V_46 , & V_23 -> V_61 , V_56 ) ;
F_41 ( V_63 ) ;
}
static void F_45 ( struct V_62 * V_63 )
{
if ( F_23 ( V_63 -> V_30 , V_63 -> V_43 ) >= V_63 -> V_35 ) {
V_63 -> V_64 = false ;
V_63 -> V_46 = NULL ;
return;
}
V_63 -> V_43 ++ ;
if ( V_63 -> V_43 >= F_21 ( V_63 -> V_23 -> V_57 ) )
return F_43 ( V_63 ) ;
if ( V_63 -> V_43 > F_17 ( V_63 -> V_30 ) )
V_63 -> V_30 ++ ;
}
static void F_46 ( struct V_62 * V_63 )
{
F_41 ( V_63 ) ;
}
static void F_47 ( struct V_62 * V_63 )
{
if ( ! F_8 ( V_63 -> V_23 ) ) {
V_63 -> V_67 = true ;
return;
}
if ( ! F_38 ( V_63 ) )
F_43 ( V_63 ) ;
}
static void F_48 ( struct V_62 * V_63 ,
struct V_22 * V_23 , T_2 V_34 , T_2 V_35 )
{
V_63 -> V_23 = V_23 ;
V_63 -> V_34 = V_34 ;
V_63 -> V_35 = V_35 ;
V_63 -> V_67 = false ;
V_63 -> V_65 = false ;
V_63 -> V_64 = false ;
V_63 -> V_46 = NULL ;
F_47 ( V_63 ) ;
}
static bool F_49 ( struct V_62 * V_63 )
{
if ( V_63 -> V_64 ) {
V_63 -> V_68 = V_63 -> V_23 -> V_57 [ V_63 -> V_43 ] ;
return true ;
}
if ( V_63 -> V_46 ) {
V_63 -> V_68 = V_63 -> V_46 -> V_47 & 0xff ;
return true ;
}
return false ;
}
static void F_50 ( struct V_62 * V_63 )
{
if ( V_63 -> V_64 )
F_45 ( V_63 ) ;
else
F_46 ( V_63 ) ;
}
T_3 F_51 ( struct V_17 * V_18 , T_4 V_69 )
{
struct V_22 * V_23 = & V_18 -> V_49 . V_23 ;
struct V_62 V_63 ;
T_2 V_34 , V_35 ;
int type = - 1 ;
const int V_70 = ( 1 << V_29 )
| ( 1 << V_71 ) ;
V_34 = F_52 ( V_69 ) ;
V_35 = V_34 + V_72 ;
F_53 (&iter, mtrr_state, start, end) {
int V_73 = V_63 . V_68 ;
if ( type == - 1 ) {
type = V_73 ;
continue;
}
if ( type == V_73 )
continue;
if ( V_73 == V_28 )
return V_28 ;
if ( ( ( 1 << type ) & V_70 ) &&
( ( 1 << V_73 ) & V_70 ) ) {
type = V_71 ;
continue;
}
return V_29 ;
}
if ( V_63 . V_67 )
return F_11 ( V_18 ) ;
if ( type == - 1 )
return F_10 ( V_23 ) ;
F_5 ( V_63 . V_65 ) ;
return type ;
}
bool F_54 ( struct V_17 * V_18 , T_4 V_69 ,
int V_74 )
{
struct V_22 * V_23 = & V_18 -> V_49 . V_23 ;
struct V_62 V_63 ;
T_2 V_34 , V_35 ;
int type = - 1 ;
V_34 = F_52 ( V_69 ) ;
V_35 = F_52 ( V_69 + V_74 ) ;
F_53 (&iter, mtrr_state, start, end) {
if ( type == - 1 ) {
type = V_63 . V_68 ;
continue;
}
if ( type != V_63 . V_68 )
return false ;
}
if ( V_63 . V_67 )
return true ;
if ( ! V_63 . V_65 )
return true ;
if ( type == - 1 )
return true ;
return type == F_10 ( V_23 ) ;
}
