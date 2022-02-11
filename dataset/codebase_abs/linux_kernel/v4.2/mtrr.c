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
case 0x2f8 :
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
static T_3 F_11 ( void )
{
return V_28 ;
}
static T_2 F_12 ( int V_29 )
{
return 8 << V_30 [ V_29 ] . V_31 ;
}
static bool F_13 ( T_1 V_1 , int * V_29 , int * V_32 )
{
switch ( V_1 ) {
case V_3 :
* V_29 = 0 ;
* V_32 = 0 ;
break;
case V_4 ... V_5 :
* V_29 = 1 ;
* V_32 = V_1 - V_4 ;
break;
case V_6 ... V_13 :
* V_29 = 2 ;
* V_32 = V_1 - V_6 ;
break;
default:
return false ;
}
return true ;
}
static void F_14 ( int V_29 , int V_32 , T_2 * V_33 , T_2 * V_34 )
{
struct V_35 * V_36 = & V_30 [ V_29 ] ;
T_2 V_37 = F_12 ( V_29 ) ;
* V_33 = V_36 -> V_33 + V_32 * V_37 ;
* V_34 = * V_33 + V_37 ;
F_5 ( * V_34 > V_36 -> V_34 ) ;
}
static int F_15 ( int V_29 , int V_32 )
{
struct V_35 * V_36 = & V_30 [ V_29 ] ;
F_5 ( V_36 -> V_33 + V_32 * F_12 ( V_29 )
> V_36 -> V_34 ) ;
return V_36 -> V_38 + 8 * V_32 ;
}
static int F_16 ( int V_29 )
{
struct V_35 * V_36 = & V_30 [ V_29 ] ;
int V_39 ;
V_39 = ( V_36 -> V_34 - V_36 -> V_33 ) >> V_36 -> V_31 ;
return V_36 -> V_38 + V_39 - 1 ;
}
static bool F_17 ( T_1 V_1 , T_2 * V_33 , T_2 * V_34 )
{
int V_29 , V_32 ;
if ( ! F_13 ( V_1 , & V_29 , & V_32 ) )
return false ;
F_14 ( V_29 , V_32 , V_33 , V_34 ) ;
return true ;
}
static int F_18 ( T_1 V_1 )
{
int V_29 , V_32 ;
if ( ! F_13 ( V_1 , & V_29 , & V_32 ) )
return - 1 ;
return F_15 ( V_29 , V_32 ) ;
}
static int F_19 ( T_2 V_40 )
{
struct V_35 * V_36 ;
int V_29 , V_41 = F_20 ( V_30 ) ;
for ( V_29 = 0 ; V_29 < V_41 ; V_29 ++ ) {
V_36 = & V_30 [ V_29 ] ;
if ( V_36 -> V_33 >= V_40 && V_40 < V_36 -> V_34 )
return V_29 ;
}
return - 1 ;
}
static int F_21 ( T_2 V_40 , int V_29 )
{
struct V_35 * V_36 ;
int V_42 ;
V_36 = & V_30 [ V_29 ] ;
V_42 = V_36 -> V_38 ;
V_42 += ( V_40 - V_36 -> V_33 ) >> V_36 -> V_31 ;
return V_42 ;
}
static T_2 F_22 ( int V_29 , int V_42 )
{
struct V_35 * V_36 = & V_30 [ V_29 ] ;
int V_43 = V_42 - V_36 -> V_38 ;
return V_36 -> V_33 + ( ( V_43 + 1 ) << V_36 -> V_31 ) ;
}
static void F_23 ( struct V_44 * V_45 , T_2 * V_33 , T_2 * V_34 )
{
T_2 V_21 ;
* V_33 = V_45 -> V_46 & V_47 ;
V_21 = V_45 -> V_21 & V_47 ;
V_21 |= ~ 0ULL << V_48 . V_49 ;
* V_34 = ( * V_33 | ~ V_21 ) + 1 ;
}
static void F_24 ( struct V_17 * V_18 , T_1 V_1 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
T_4 V_33 , V_34 ;
int V_42 ;
if ( V_1 == V_15 || ! V_51 ||
! F_25 ( V_18 -> V_52 ) )
return;
if ( ! F_8 ( V_23 ) && V_1 != V_14 )
return;
if ( F_17 ( V_1 , & V_33 , & V_34 ) ) {
if ( ! F_9 ( V_23 ) )
return;
} else if ( V_1 == V_14 ) {
V_33 = 0x0 ;
V_34 = ~ 0ULL ;
} else {
V_42 = ( V_1 - 0x200 ) / 2 ;
F_23 ( & V_23 -> V_53 [ V_42 ] , & V_33 , & V_34 ) ;
}
F_26 ( V_18 -> V_52 , F_27 ( V_33 ) , F_27 ( V_34 ) ) ;
}
static bool F_28 ( struct V_44 * V_45 )
{
return ( V_45 -> V_21 & ( 1 << 11 ) ) != 0 ;
}
static void F_29 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_44 * V_54 , * V_55 ;
int V_42 , V_56 ;
V_42 = ( V_1 - 0x200 ) / 2 ;
V_56 = V_1 - 0x200 - 2 * V_42 ;
V_55 = & V_23 -> V_53 [ V_42 ] ;
if ( F_28 ( V_55 ) )
F_30 ( & V_23 -> V_53 [ V_42 ] . V_57 ) ;
if ( ! V_56 )
V_55 -> V_46 = V_19 ;
else
V_55 -> V_21 = V_19 ;
if ( F_28 ( V_55 ) ) {
F_31 (tmp, &mtrr_state->head, node)
if ( V_55 -> V_46 >= V_54 -> V_46 )
break;
F_32 ( & V_55 -> V_57 , & V_54 -> V_57 ) ;
}
}
int F_33 ( struct V_17 * V_18 , T_1 V_1 , T_2 V_19 )
{
int V_42 ;
if ( ! F_4 ( V_18 , V_1 , V_19 ) )
return 1 ;
V_42 = F_18 ( V_1 ) ;
if ( V_42 >= 0 )
* ( T_2 * ) & V_18 -> V_50 . V_23 . V_58 [ V_42 ] = V_19 ;
else if ( V_1 == V_14 )
V_18 -> V_50 . V_23 . V_24 = V_19 ;
else if ( V_1 == V_15 )
V_18 -> V_50 . V_59 = V_19 ;
else
F_29 ( V_18 , V_1 , V_19 ) ;
F_24 ( V_18 , V_1 ) ;
return 0 ;
}
int F_34 ( struct V_17 * V_18 , T_1 V_1 , T_2 * V_60 )
{
int V_42 ;
if ( V_1 == V_61 ) {
* V_60 = 0x500 | V_2 ;
return 0 ;
}
if ( ! F_1 ( V_1 ) )
return 1 ;
V_42 = F_18 ( V_1 ) ;
if ( V_42 >= 0 )
* V_60 = * ( T_2 * ) & V_18 -> V_50 . V_23 . V_58 [ V_42 ] ;
else if ( V_1 == V_14 )
* V_60 = V_18 -> V_50 . V_23 . V_24 ;
else if ( V_1 == V_15 )
* V_60 = V_18 -> V_50 . V_59 ;
else {
int V_56 ;
V_42 = ( V_1 - 0x200 ) / 2 ;
V_56 = V_1 - 0x200 - 2 * V_42 ;
if ( ! V_56 )
* V_60 = V_18 -> V_50 . V_23 . V_53 [ V_42 ] . V_46 ;
else
* V_60 = V_18 -> V_50 . V_23 . V_53 [ V_42 ] . V_21 ;
}
return 0 ;
}
void F_35 ( struct V_17 * V_18 )
{
F_36 ( & V_18 -> V_50 . V_23 . V_62 ) ;
}
static bool F_37 ( struct V_63 * V_64 )
{
int V_29 , V_42 ;
if ( ! F_9 ( V_64 -> V_23 ) )
return false ;
V_29 = F_19 ( V_64 -> V_33 ) ;
if ( V_29 < 0 )
return false ;
V_64 -> V_65 = true ;
V_42 = F_21 ( V_64 -> V_33 , V_29 ) ;
V_64 -> V_42 = V_42 ;
V_64 -> V_29 = V_29 ;
return true ;
}
static bool F_38 ( struct V_63 * V_64 ,
struct V_44 * V_45 )
{
T_2 V_33 , V_34 ;
F_23 ( V_45 , & V_33 , & V_34 ) ;
if ( ! ( V_33 >= V_64 -> V_34 || V_34 <= V_64 -> V_33 ) ) {
V_64 -> V_45 = V_45 ;
V_64 -> V_66 |= V_64 -> V_67 < V_33 ;
V_64 -> V_67 = F_39 ( V_64 -> V_67 , V_34 ) ;
return true ;
}
return false ;
}
static void F_40 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_23 ;
F_41 (iter->range, &mtrr_state->head, node)
if ( F_38 ( V_64 , V_64 -> V_45 ) )
return;
V_64 -> V_45 = NULL ;
V_64 -> V_66 |= V_64 -> V_67 < V_64 -> V_34 ;
}
static void F_42 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_23 ;
V_64 -> V_65 = false ;
V_64 -> V_67 = V_64 -> V_33 ;
V_64 -> V_45 = F_43 ( V_64 -> V_45 , & V_23 -> V_62 , V_57 ) ;
F_40 ( V_64 ) ;
}
static void F_44 ( struct V_63 * V_64 )
{
if ( F_22 ( V_64 -> V_29 , V_64 -> V_42 ) >= V_64 -> V_34 ) {
V_64 -> V_65 = false ;
V_64 -> V_45 = NULL ;
return;
}
V_64 -> V_42 ++ ;
if ( V_64 -> V_42 >= F_20 ( V_64 -> V_23 -> V_58 ) )
return F_42 ( V_64 ) ;
if ( V_64 -> V_42 > F_16 ( V_64 -> V_29 ) )
V_64 -> V_29 ++ ;
}
static void F_45 ( struct V_63 * V_64 )
{
F_40 ( V_64 ) ;
}
static void F_46 ( struct V_63 * V_64 )
{
if ( ! F_8 ( V_64 -> V_23 ) ) {
V_64 -> V_68 = true ;
return;
}
if ( ! F_37 ( V_64 ) )
F_42 ( V_64 ) ;
}
static void F_47 ( struct V_63 * V_64 ,
struct V_22 * V_23 , T_2 V_33 , T_2 V_34 )
{
V_64 -> V_23 = V_23 ;
V_64 -> V_33 = V_33 ;
V_64 -> V_34 = V_34 ;
V_64 -> V_68 = false ;
V_64 -> V_66 = false ;
V_64 -> V_65 = false ;
V_64 -> V_45 = NULL ;
F_46 ( V_64 ) ;
}
static bool F_48 ( struct V_63 * V_64 )
{
if ( V_64 -> V_65 ) {
V_64 -> V_69 = V_64 -> V_23 -> V_58 [ V_64 -> V_42 ] ;
return true ;
}
if ( V_64 -> V_45 ) {
V_64 -> V_69 = V_64 -> V_45 -> V_46 & 0xff ;
return true ;
}
return false ;
}
static void F_49 ( struct V_63 * V_64 )
{
if ( V_64 -> V_65 )
F_44 ( V_64 ) ;
else
F_45 ( V_64 ) ;
}
T_3 F_50 ( struct V_17 * V_18 , T_4 V_70 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_63 V_64 ;
T_2 V_33 , V_34 ;
int type = - 1 ;
const int V_71 = ( 1 << V_72 )
| ( 1 << V_73 ) ;
V_33 = F_51 ( V_70 ) ;
V_34 = V_33 + V_74 ;
F_52 (&iter, mtrr_state, start, end) {
int V_75 = V_64 . V_69 ;
if ( type == - 1 ) {
type = V_75 ;
continue;
}
if ( type == V_75 )
continue;
if ( V_75 == V_28 )
return V_28 ;
if ( ( ( 1 << type ) & V_71 ) &&
( ( 1 << V_75 ) & V_71 ) ) {
type = V_73 ;
continue;
}
return V_72 ;
}
if ( V_64 . V_68 )
return F_11 () ;
if ( type == - 1 )
return F_10 ( V_23 ) ;
F_5 ( V_64 . V_66 ) ;
return type ;
}
bool F_53 ( struct V_17 * V_18 , T_4 V_70 ,
int V_76 )
{
struct V_22 * V_23 = & V_18 -> V_50 . V_23 ;
struct V_63 V_64 ;
T_2 V_33 , V_34 ;
int type = - 1 ;
V_33 = F_51 ( V_70 ) ;
V_34 = F_51 ( V_70 + V_76 ) ;
F_52 (&iter, mtrr_state, start, end) {
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
