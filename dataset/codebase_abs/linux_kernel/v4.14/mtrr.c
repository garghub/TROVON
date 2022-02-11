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
if ( F_12 ( V_18 , V_28 ) )
return V_29 ;
else
return V_30 ;
}
static T_2 F_13 ( int V_31 )
{
return 8 << V_32 [ V_31 ] . V_33 ;
}
static bool F_14 ( T_1 V_1 , int * V_31 , int * V_34 )
{
switch ( V_1 ) {
case V_3 :
* V_31 = 0 ;
* V_34 = 0 ;
break;
case V_4 ... V_5 :
* V_31 = 1 ;
* V_34 = V_1 - V_4 ;
break;
case V_6 ... V_13 :
* V_31 = 2 ;
* V_34 = V_1 - V_6 ;
break;
default:
return false ;
}
return true ;
}
static void F_15 ( int V_31 , int V_34 , T_2 * V_35 , T_2 * V_36 )
{
struct V_37 * V_38 = & V_32 [ V_31 ] ;
T_2 V_39 = F_13 ( V_31 ) ;
* V_35 = V_38 -> V_35 + V_34 * V_39 ;
* V_36 = * V_35 + V_39 ;
F_5 ( * V_36 > V_38 -> V_36 ) ;
}
static int F_16 ( int V_31 , int V_34 )
{
struct V_37 * V_38 = & V_32 [ V_31 ] ;
F_5 ( V_38 -> V_35 + V_34 * F_13 ( V_31 )
> V_38 -> V_36 ) ;
return V_38 -> V_40 + 8 * V_34 ;
}
static int F_17 ( int V_31 )
{
struct V_37 * V_38 = & V_32 [ V_31 ] ;
int V_41 ;
V_41 = ( V_38 -> V_36 - V_38 -> V_35 ) >> V_38 -> V_33 ;
return V_38 -> V_40 + V_41 - 1 ;
}
static bool F_18 ( T_1 V_1 , T_2 * V_35 , T_2 * V_36 )
{
int V_31 , V_34 ;
if ( ! F_14 ( V_1 , & V_31 , & V_34 ) )
return false ;
F_15 ( V_31 , V_34 , V_35 , V_36 ) ;
return true ;
}
static int F_19 ( T_1 V_1 )
{
int V_31 , V_34 ;
if ( ! F_14 ( V_1 , & V_31 , & V_34 ) )
return - 1 ;
return F_16 ( V_31 , V_34 ) ;
}
static int F_20 ( T_2 V_42 )
{
struct V_37 * V_38 ;
int V_31 , V_43 = F_21 ( V_32 ) ;
for ( V_31 = 0 ; V_31 < V_43 ; V_31 ++ ) {
V_38 = & V_32 [ V_31 ] ;
if ( V_38 -> V_35 <= V_42 && V_42 < V_38 -> V_36 )
return V_31 ;
}
return - 1 ;
}
static int F_22 ( T_2 V_42 , int V_31 )
{
struct V_37 * V_38 ;
int V_44 ;
V_38 = & V_32 [ V_31 ] ;
V_44 = V_38 -> V_40 ;
V_44 += ( V_42 - V_38 -> V_35 ) >> V_38 -> V_33 ;
return V_44 ;
}
static T_2 F_23 ( int V_31 , int V_44 )
{
struct V_37 * V_38 = & V_32 [ V_31 ] ;
int V_45 = V_44 - V_38 -> V_40 ;
return V_38 -> V_35 + ( ( V_45 + 1 ) << V_38 -> V_33 ) ;
}
static void F_24 ( struct V_46 * V_47 , T_2 * V_35 , T_2 * V_36 )
{
T_2 V_21 ;
* V_35 = V_47 -> V_48 & V_49 ;
V_21 = V_47 -> V_21 & V_49 ;
* V_36 = ( * V_35 | ~ V_21 ) + 1 ;
}
static void F_25 ( struct V_17 * V_18 , T_1 V_1 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
T_4 V_35 , V_36 ;
int V_44 ;
if ( V_1 == V_15 || ! V_51 ||
! F_26 ( V_18 -> V_52 ) )
return;
if ( ! F_8 ( V_23 ) && V_1 != V_14 )
return;
if ( F_18 ( V_1 , & V_35 , & V_36 ) ) {
if ( ! F_9 ( V_23 ) )
return;
} else if ( V_1 == V_14 ) {
V_35 = 0x0 ;
V_36 = ~ 0ULL ;
} else {
V_44 = ( V_1 - 0x200 ) / 2 ;
F_24 ( & V_23 -> V_53 [ V_44 ] , & V_35 , & V_36 ) ;
}
F_27 ( V_18 -> V_52 , F_28 ( V_35 ) , F_28 ( V_36 ) ) ;
}
static bool F_29 ( struct V_46 * V_47 )
{
return ( V_47 -> V_21 & ( 1 << 11 ) ) != 0 ;
}
static void F_30 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_46 * V_54 , * V_55 ;
int V_44 , V_56 ;
V_44 = ( V_1 - 0x200 ) / 2 ;
V_56 = V_1 - 0x200 - 2 * V_44 ;
V_55 = & V_23 -> V_53 [ V_44 ] ;
if ( F_29 ( V_55 ) )
F_31 ( & V_23 -> V_53 [ V_44 ] . V_57 ) ;
if ( ! V_56 )
V_55 -> V_48 = V_19 ;
else
V_55 -> V_21 = V_19 | ( - 1LL << F_6 ( V_18 ) ) ;
if ( F_29 ( V_55 ) ) {
F_32 (tmp, &mtrr_state->head, node)
if ( V_55 -> V_48 >= V_54 -> V_48 )
break;
F_33 ( & V_55 -> V_57 , & V_54 -> V_57 ) ;
}
}
int F_34 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
int V_44 ;
if ( ! F_4 ( V_18 , V_1 , V_19 ) )
return 1 ;
V_44 = F_19 ( V_1 ) ;
if ( V_44 >= 0 )
* ( T_2 * ) & V_18 -> V_50 . V_23 . V_58 [ V_44 ] = V_19 ;
else if ( V_1 == V_14 )
V_18 -> V_50 . V_23 . V_24 = V_19 ;
else if ( V_1 == V_15 )
V_18 -> V_50 . V_59 = V_19 ;
else
F_30 ( V_18 , V_1 , V_19 ) ;
F_25 ( V_18 , V_1 ) ;
return 0 ;
}
int F_35 ( struct V_17 * V_18 , T_1 V_1 , T_2 * V_60 )
{
int V_44 ;
if ( V_1 == V_61 ) {
* V_60 = 0x500 | V_2 ;
return 0 ;
}
if ( ! F_1 ( V_1 ) )
return 1 ;
V_44 = F_19 ( V_1 ) ;
if ( V_44 >= 0 )
* V_60 = * ( T_2 * ) & V_18 -> V_50 . V_23 . V_58 [ V_44 ] ;
else if ( V_1 == V_14 )
* V_60 = V_18 -> V_50 . V_23 . V_24 ;
else if ( V_1 == V_15 )
* V_60 = V_18 -> V_50 . V_59 ;
else {
int V_56 ;
V_44 = ( V_1 - 0x200 ) / 2 ;
V_56 = V_1 - 0x200 - 2 * V_44 ;
if ( ! V_56 )
* V_60 = V_18 -> V_50 . V_23 . V_53 [ V_44 ] . V_48 ;
else
* V_60 = V_18 -> V_50 . V_23 . V_53 [ V_44 ] . V_21 ;
* V_60 &= ( 1ULL << F_6 ( V_18 ) ) - 1 ;
}
return 0 ;
}
void F_36 ( struct V_17 * V_18 )
{
F_37 ( & V_18 -> V_50 . V_23 . V_62 ) ;
}
static bool F_38 ( struct V_63 * V_64 )
{
int V_31 , V_44 ;
if ( ! F_9 ( V_64 -> V_23 ) )
return false ;
V_31 = F_20 ( V_64 -> V_35 ) ;
if ( V_31 < 0 )
return false ;
V_64 -> V_65 = true ;
V_44 = F_22 ( V_64 -> V_35 , V_31 ) ;
V_64 -> V_44 = V_44 ;
V_64 -> V_31 = V_31 ;
return true ;
}
static bool F_39 ( struct V_63 * V_64 ,
struct V_46 * V_47 )
{
T_2 V_35 , V_36 ;
F_24 ( V_47 , & V_35 , & V_36 ) ;
if ( ! ( V_35 >= V_64 -> V_36 || V_36 <= V_64 -> V_35 ) ) {
V_64 -> V_47 = V_47 ;
V_64 -> V_66 |= V_64 -> V_67 < V_35 ;
V_64 -> V_67 = F_40 ( V_64 -> V_67 , V_36 ) ;
return true ;
}
return false ;
}
static void F_41 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_23 ;
F_42 (iter->range, &mtrr_state->head, node)
if ( F_39 ( V_64 , V_64 -> V_47 ) )
return;
V_64 -> V_47 = NULL ;
V_64 -> V_66 |= V_64 -> V_67 < V_64 -> V_36 ;
}
static void F_43 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_23 ;
V_64 -> V_65 = false ;
V_64 -> V_67 = V_64 -> V_35 ;
V_64 -> V_47 = NULL ;
V_64 -> V_47 = F_44 ( V_64 -> V_47 , & V_23 -> V_62 , V_57 ) ;
F_41 ( V_64 ) ;
}
static void F_45 ( struct V_63 * V_64 )
{
if ( F_23 ( V_64 -> V_31 , V_64 -> V_44 ) >= V_64 -> V_36 ) {
V_64 -> V_65 = false ;
V_64 -> V_47 = NULL ;
return;
}
V_64 -> V_44 ++ ;
if ( V_64 -> V_44 >= F_21 ( V_64 -> V_23 -> V_58 ) )
return F_43 ( V_64 ) ;
if ( V_64 -> V_44 > F_17 ( V_64 -> V_31 ) )
V_64 -> V_31 ++ ;
}
static void F_46 ( struct V_63 * V_64 )
{
F_41 ( V_64 ) ;
}
static void F_47 ( struct V_63 * V_64 )
{
if ( ! F_8 ( V_64 -> V_23 ) ) {
V_64 -> V_68 = true ;
return;
}
if ( ! F_38 ( V_64 ) )
F_43 ( V_64 ) ;
}
static void F_48 ( struct V_63 * V_64 ,
struct V_22 * V_23 , T_2 V_35 , T_2 V_36 )
{
V_64 -> V_23 = V_23 ;
V_64 -> V_35 = V_35 ;
V_64 -> V_36 = V_36 ;
V_64 -> V_68 = false ;
V_64 -> V_66 = false ;
V_64 -> V_65 = false ;
V_64 -> V_47 = NULL ;
F_47 ( V_64 ) ;
}
static bool F_49 ( struct V_63 * V_64 )
{
if ( V_64 -> V_65 ) {
V_64 -> V_69 = V_64 -> V_23 -> V_58 [ V_64 -> V_44 ] ;
return true ;
}
if ( V_64 -> V_47 ) {
V_64 -> V_69 = V_64 -> V_47 -> V_48 & 0xff ;
return true ;
}
return false ;
}
static void F_50 ( struct V_63 * V_64 )
{
if ( V_64 -> V_65 )
F_45 ( V_64 ) ;
else
F_46 ( V_64 ) ;
}
T_3 F_51 ( struct V_17 * V_18 , T_4 V_70 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_63 V_64 ;
T_2 V_35 , V_36 ;
int type = - 1 ;
const int V_71 = ( 1 << V_30 )
| ( 1 << V_72 ) ;
V_35 = F_52 ( V_70 ) ;
V_36 = V_35 + V_73 ;
F_53 (&iter, mtrr_state, start, end) {
int V_74 = V_64 . V_69 ;
if ( type == - 1 ) {
type = V_74 ;
continue;
}
if ( type == V_74 )
continue;
if ( V_74 == V_29 )
return V_29 ;
if ( ( ( 1 << type ) & V_71 ) &&
( ( 1 << V_74 ) & V_71 ) ) {
type = V_72 ;
continue;
}
return V_30 ;
}
if ( V_64 . V_68 )
return F_11 ( V_18 ) ;
if ( type == - 1 )
return F_10 ( V_23 ) ;
F_5 ( V_64 . V_66 ) ;
return type ;
}
bool F_54 ( struct V_17 * V_18 , T_4 V_70 ,
int V_75 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_63 V_64 ;
T_2 V_35 , V_36 ;
int type = - 1 ;
V_35 = F_52 ( V_70 ) ;
V_36 = F_52 ( V_70 + V_75 ) ;
F_53 (&iter, mtrr_state, start, end) {
if ( type == - 1 ) {
type = V_64 . V_69 ;
continue;
}
if ( type != V_64 . V_69 )
return false ;
}
if ( V_64 . V_68 )
return true ;
if ( ! V_64 . V_66 )
return true ;
if ( type == - 1 )
return true ;
return type == F_10 ( V_23 ) ;
}
