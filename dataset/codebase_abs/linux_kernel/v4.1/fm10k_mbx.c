static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
}
static T_2 F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_6 - V_2 -> V_5 ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 + V_2 -> V_5 - V_2 -> V_6 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_2 -> V_6 ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_2 V_7 )
{
return ( V_2 -> V_5 + V_7 ) & ( V_2 -> V_4 - 1 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_2 V_7 )
{
return ( V_2 -> V_6 + V_7 ) & ( V_2 -> V_4 - 1 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 )
{
T_1 * V_5 = V_2 -> V_3 + F_5 ( V_2 , 0 ) ;
if ( F_4 ( V_2 ) )
return 0 ;
return F_8 ( * V_5 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
T_2 V_8 = F_7 ( V_2 ) ;
V_2 -> V_5 += V_8 ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_5 = V_2 -> V_6 ;
}
static T_2 F_11 ( struct V_9 * V_10 , T_2 V_5 , T_2 V_6 )
{
T_2 V_8 = V_6 - V_5 ;
if ( V_8 > V_6 )
V_8 -= 2 ;
return V_8 & ( ( V_10 -> V_11 << 1 ) - 1 ) ;
}
static T_2 F_12 ( struct V_9 * V_10 , T_2 V_7 )
{
T_2 V_6 = ( V_10 -> V_6 + V_7 + 1 ) & ( ( V_10 -> V_11 << 1 ) - 1 ) ;
return ( V_6 > V_10 -> V_6 ) ? -- V_6 : ++ V_6 ;
}
static T_2 F_13 ( struct V_9 * V_10 , T_2 V_7 )
{
T_2 V_6 = ( V_10 -> V_6 - V_7 - 1 ) & ( ( V_10 -> V_11 << 1 ) - 1 ) ;
return ( V_6 < V_10 -> V_6 ) ? ++ V_6 : -- V_6 ;
}
static T_2 F_14 ( struct V_9 * V_10 , T_2 V_7 )
{
T_2 V_5 = ( V_10 -> V_5 + V_7 + 1 ) & ( ( V_10 -> V_11 << 1 ) - 1 ) ;
return ( V_5 > V_10 -> V_5 ) ? -- V_5 : ++ V_5 ;
}
static T_2 F_15 ( struct V_9 * V_10 , T_2 V_7 )
{
T_2 V_5 = ( V_10 -> V_5 - V_7 - 1 ) & ( ( V_10 -> V_11 << 1 ) - 1 ) ;
return ( V_5 < V_10 -> V_5 ) ? ++ V_5 : -- V_5 ;
}
static T_2 F_16 ( struct V_9 * V_10 )
{
T_1 * V_6 = V_10 -> V_12 . V_3 + F_6 ( & V_10 -> V_12 , 0 ) ;
if ( ! V_10 -> V_13 )
return 0 ;
return F_8 ( * V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
const T_1 * V_14 , T_2 V_15 , T_2 V_8 )
{
T_2 V_16 = F_6 ( V_2 , V_15 ) ;
T_1 * V_6 = V_2 -> V_3 + V_16 ;
V_16 = V_2 -> V_4 - V_16 ;
if ( V_16 < V_8 )
memcpy ( V_2 -> V_3 , V_14 + V_16 , ( V_8 - V_16 ) << 2 ) ;
else
V_16 = V_8 ;
memcpy ( V_6 , V_14 , V_16 << 2 ) ;
}
static T_3 F_18 ( struct V_1 * V_2 , const T_1 * V_14 )
{
T_2 V_8 = F_8 ( * V_14 ) ;
if ( V_8 > V_2 -> V_4 )
return V_17 ;
if ( V_8 > F_3 ( V_2 ) )
return V_18 ;
F_17 ( V_2 , V_14 , 0 , V_8 ) ;
F_19 () ;
V_2 -> V_6 += V_8 ;
return 0 ;
}
static T_2 F_20 ( struct V_9 * V_10 , T_2 V_8 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_2 V_19 = 0 , V_20 ;
T_1 * V_14 ;
V_8 += V_10 -> V_13 ;
do {
V_14 = V_2 -> V_3 + F_6 ( V_2 , V_19 ) ;
V_20 = F_8 ( * V_14 ) ;
V_19 += V_20 ;
} while ( V_19 < V_8 );
if ( ( V_8 < V_19 ) && ( V_20 <= V_10 -> V_21 ) )
return 0 ;
return ( V_8 < V_19 ) ? V_8 : ( V_8 - V_19 ) ;
}
static void F_21 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_24 ;
T_1 V_25 = V_10 -> V_26 ;
T_1 * V_5 = V_2 -> V_3 ;
T_2 V_16 , V_8 , V_6 , V_27 ;
if ( ! V_10 -> V_28 )
return;
V_27 = V_10 -> V_11 - 1 ;
V_8 = V_10 -> V_28 ;
V_6 = F_13 ( V_10 , V_8 ) ;
if ( V_6 > V_27 )
V_6 ++ ;
V_16 = F_5 ( V_2 , V_10 -> V_29 ) ;
V_5 += V_16 ;
F_22 () ;
for ( V_16 = V_2 -> V_4 - V_16 ; V_8 ; V_5 = V_2 -> V_3 ) {
do {
V_6 &= V_27 ;
if ( ! V_6 )
V_6 ++ ;
F_23 ( V_23 , V_25 + V_6 ++ , * ( V_5 ++ ) ) ;
} while ( -- V_8 && -- V_16 );
}
}
static void F_24 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
T_2 V_11 , V_8 , V_30 = F_11 ( V_10 , V_5 , V_10 -> V_6 ) ;
struct V_1 * V_2 = & V_10 -> V_24 ;
V_10 -> V_29 += V_10 -> V_28 - V_30 ;
V_11 = V_10 -> V_11 - 1 ;
V_8 = F_2 ( V_2 ) - V_10 -> V_29 ;
if ( V_8 > V_11 )
V_8 = V_11 ;
V_10 -> V_6 = F_12 ( V_10 , V_8 - V_30 ) ;
V_10 -> V_28 = V_8 ;
for ( V_8 = F_7 ( V_2 ) ;
V_8 && ( V_10 -> V_29 >= V_8 ) ;
V_8 = F_7 ( V_2 ) ) {
V_10 -> V_29 -= F_9 ( V_2 ) ;
V_10 -> V_31 ++ ;
V_10 -> V_32 += V_8 ;
}
F_21 ( V_23 , V_10 ) ;
}
static void F_25 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_1 V_25 = V_10 -> V_26 ^ V_10 -> V_11 ;
T_1 * V_6 = V_2 -> V_3 ;
T_2 V_16 , V_8 , V_5 ;
V_8 = V_10 -> V_33 ;
V_5 = F_15 ( V_10 , V_8 ) ;
if ( V_5 >= V_10 -> V_11 )
V_5 ++ ;
V_16 = F_6 ( V_2 , V_10 -> V_13 ) ;
V_6 += V_16 ;
for ( V_16 = V_2 -> V_4 - V_16 ; V_8 ; V_6 = V_2 -> V_3 ) {
do {
V_5 &= V_10 -> V_11 - 1 ;
if ( ! V_5 )
V_5 ++ ;
* ( V_6 ++ ) = F_26 ( V_23 , V_25 + V_5 ++ ) ;
} while ( -- V_8 && -- V_16 );
}
F_19 () ;
}
static T_3 F_27 ( struct V_22 * V_23 ,
struct V_9 * V_10 ,
T_2 V_6 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_2 V_8 , V_34 = F_11 ( V_10 , V_10 -> V_5 , V_6 ) ;
V_8 = F_3 ( V_2 ) - V_10 -> V_13 ;
if ( V_8 > V_34 )
V_8 = V_34 ;
V_10 -> V_5 = F_14 ( V_10 , V_8 ) ;
V_10 -> V_33 = V_8 ;
if ( ! V_8 )
return 0 ;
F_25 ( V_23 , V_10 ) ;
if ( F_20 ( V_10 , V_8 ) )
return V_17 ;
V_10 -> V_13 += V_8 ;
for ( V_8 = F_16 ( V_10 ) ;
V_8 && ( V_10 -> V_13 >= V_8 ) ;
V_8 = F_16 ( V_10 ) ) {
V_2 -> V_6 += V_8 ;
V_10 -> V_13 -= V_8 ;
V_10 -> V_35 ++ ;
V_10 -> V_36 += V_8 ;
}
return 0 ;
}
static T_2 F_28 ( const T_1 * V_37 , T_2 V_38 , T_2 V_8 )
{
T_1 V_39 = V_38 ;
while ( V_8 -- ) {
V_39 ^= * ( V_37 ++ ) ;
V_39 = ( V_39 >> 8 ) ^ V_40 [ V_39 & 0xFF ] ;
V_39 = ( V_39 >> 8 ) ^ V_40 [ V_39 & 0xFF ] ;
if ( ! ( V_8 -- ) )
break;
V_39 = ( V_39 >> 8 ) ^ V_40 [ V_39 & 0xFF ] ;
V_39 = ( V_39 >> 8 ) ^ V_40 [ V_39 & 0xFF ] ;
}
return ( T_2 ) V_39 ;
}
static T_2 F_29 ( struct V_1 * V_2 , T_2 V_7 ,
T_2 V_8 , T_2 V_38 )
{
T_1 * V_37 = V_2 -> V_3 + V_7 ;
V_7 = V_2 -> V_4 - V_7 ;
if ( V_7 < V_8 ) {
V_38 = F_28 ( V_37 , V_38 , V_7 * 2 ) ;
V_37 = V_2 -> V_3 ;
V_8 -= V_7 ;
}
return F_28 ( V_37 , V_38 , V_8 * 2 ) ;
}
static void F_30 ( struct V_9 * V_10 , T_2 V_5 )
{
T_2 V_8 = V_10 -> V_28 - F_11 ( V_10 , V_5 , V_10 -> V_6 ) ;
V_5 = F_5 ( & V_10 -> V_24 , V_10 -> V_29 ) ;
V_10 -> V_41 = F_29 ( & V_10 -> V_24 , V_5 , V_8 , V_10 -> V_41 ) ;
}
static T_3 F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_2 V_8 = V_10 -> V_33 ;
T_2 V_7 = F_6 ( V_2 , V_10 -> V_13 ) - V_8 ;
T_2 V_42 ;
if ( V_8 )
V_10 -> V_43 = F_29 ( V_2 , V_7 , V_8 , V_10 -> V_43 ) ;
V_42 = F_28 ( & V_10 -> V_44 , V_10 -> V_43 , 1 ) ;
return V_42 ? V_45 : 0 ;
}
static bool F_32 ( struct V_9 * V_10 )
{
T_2 V_46 = F_7 ( & V_10 -> V_12 ) ;
return V_46 && ( F_2 ( & V_10 -> V_12 ) >= V_46 ) ;
}
static bool F_33 ( struct V_9 * V_10 , T_2 V_8 )
{
T_2 V_47 = F_3 ( & V_10 -> V_24 ) ;
return ( V_10 -> V_48 == V_49 ) && ( V_47 >= V_8 ) ;
}
static bool F_34 ( struct V_9 * V_10 )
{
return F_4 ( & V_10 -> V_24 ) ;
}
static T_2 F_35 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_3 V_50 ;
T_2 V_51 ;
for ( V_51 = 0 ; ! F_4 ( V_2 ) ; V_51 ++ ) {
V_50 = F_36 ( V_23 , V_2 -> V_3 + V_2 -> V_5 ,
V_10 , V_10 -> V_52 ) ;
if ( V_50 < 0 )
V_10 -> V_53 ++ ;
F_9 ( V_2 ) ;
}
memmove ( V_2 -> V_3 , V_2 -> V_3 + V_2 -> V_6 , V_10 -> V_13 << 2 ) ;
V_2 -> V_6 -= V_2 -> V_5 ;
V_2 -> V_5 = 0 ;
return V_51 ;
}
static T_3 F_37 ( struct V_22 * V_23 ,
struct V_9 * V_10 , const T_1 * V_14 )
{
T_1 V_54 = V_10 -> V_55 ;
T_3 V_50 ;
switch ( V_10 -> V_48 ) {
case V_56 :
case V_57 :
return V_58 ;
default:
break;
}
V_50 = F_18 ( & V_10 -> V_24 , V_14 ) ;
while ( V_50 && V_54 ) {
V_54 -- ;
F_38 ( V_10 -> F_38 ) ;
V_10 -> V_59 . V_60 ( V_23 , V_10 ) ;
V_50 = F_18 ( & V_10 -> V_24 , V_14 ) ;
}
if ( V_50 ) {
V_10 -> V_55 = 0 ;
V_10 -> V_61 ++ ;
}
if ( ! V_10 -> V_28 )
V_10 -> V_59 . V_60 ( V_23 , V_10 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( V_10 -> V_44 )
return V_62 ;
if ( F_26 ( V_23 , V_10 -> V_63 ) & V_64 )
V_10 -> V_65 = V_66 ;
F_23 ( V_23 , V_10 -> V_63 ,
V_64 | V_67 ) ;
V_10 -> V_44 = F_26 ( V_23 , V_10 -> V_26 ^ V_10 -> V_11 ) ;
return 0 ;
}
static void F_40 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
T_1 V_25 = V_10 -> V_26 ;
F_23 ( V_23 , V_25 , V_10 -> V_44 ) ;
if ( V_10 -> V_65 )
F_23 ( V_23 , V_10 -> V_63 , V_10 -> V_65 ) ;
V_10 -> V_44 = 0 ;
V_10 -> V_65 = 0 ;
}
static void F_41 ( struct V_9 * V_10 )
{
V_10 -> V_65 |= V_68 ;
V_10 -> V_44 = F_42 ( V_69 , TYPE ) |
F_42 ( V_10 -> V_5 , V_70 ) |
F_42 ( V_10 -> V_12 . V_4 - 1 , V_71 ) ;
}
static void F_43 ( struct V_9 * V_10 )
{
T_1 V_72 = F_42 ( V_73 , TYPE ) |
F_42 ( V_10 -> V_6 , V_74 ) |
F_42 ( V_10 -> V_5 , V_70 ) ;
struct V_1 * V_2 = & V_10 -> V_24 ;
T_2 V_42 ;
if ( V_10 -> V_28 )
V_10 -> V_65 |= V_68 ;
V_42 = F_29 ( V_2 , F_5 ( V_2 , V_10 -> V_29 ) ,
V_10 -> V_28 , V_10 -> V_41 ) ;
V_42 = F_28 ( & V_72 , V_42 , 1 ) ;
V_10 -> V_44 = V_72 | F_42 ( V_42 , V_75 ) ;
}
static void F_44 ( struct V_9 * V_10 )
{
T_1 V_72 = F_42 ( V_76 , TYPE ) |
F_42 ( V_10 -> V_6 , V_74 ) |
F_42 ( V_10 -> V_5 , V_70 ) ;
T_2 V_42 = F_28 ( & V_72 , V_10 -> V_41 , 1 ) ;
V_10 -> V_65 |= V_66 ;
V_10 -> V_44 = V_72 | F_42 ( V_42 , V_75 ) ;
}
static void F_45 ( struct V_9 * V_10 , T_3 V_50 )
{
switch ( V_50 ) {
case V_77 :
case V_78 :
case V_79 :
case V_17 :
case V_80 :
case V_45 :
break;
default:
return;
}
V_10 -> V_65 |= V_68 ;
V_10 -> V_44 = F_42 ( V_81 , TYPE ) |
F_42 ( V_50 , V_82 ) |
F_42 ( V_10 -> V_5 , V_70 ) ;
}
static T_3 F_46 ( struct V_9 * V_10 )
{
T_2 type , V_83 , V_5 , V_6 , V_4 ;
const T_1 * V_72 = & V_10 -> V_44 ;
type = F_47 ( * V_72 , TYPE ) ;
V_83 = F_47 ( * V_72 , V_84 ) ;
V_6 = F_47 ( * V_72 , V_74 ) ;
V_5 = F_47 ( * V_72 , V_70 ) ;
V_4 = F_47 ( * V_72 , V_71 ) ;
if ( V_83 )
return V_80 ;
switch ( type ) {
case V_76 :
if ( V_6 != V_10 -> V_5 )
return V_77 ;
case V_73 :
if ( ! V_5 || ( V_5 == F_48 ( V_70 ) ) )
return V_78 ;
if ( F_11 ( V_10 , V_5 , V_10 -> V_6 ) > V_10 -> V_28 )
return V_78 ;
if ( ! V_6 || ( V_6 == F_48 ( V_74 ) ) )
return V_77 ;
if ( F_11 ( V_10 , V_10 -> V_5 , V_6 ) < V_10 -> V_11 )
break;
return V_77 ;
case V_69 :
if ( ( V_4 < V_85 ) || ( V_4 & ( V_4 + 1 ) ) )
return V_17 ;
case V_81 :
if ( ! V_5 || ( V_5 == F_48 ( V_70 ) ) )
return V_78 ;
if ( V_6 )
return V_77 ;
break;
default:
return V_79 ;
}
return 0 ;
}
static T_3 F_49 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
switch ( V_10 -> V_48 ) {
case V_49 :
case V_57 :
F_30 ( V_10 , V_5 ) ;
F_24 ( V_23 , V_10 , V_5 ) ;
if ( V_10 -> V_28 || ( V_10 -> V_48 == V_49 ) )
F_43 ( V_10 ) ;
else
F_44 ( V_10 ) ;
break;
case V_86 :
F_41 ( V_10 ) ;
break;
case V_56 :
F_44 ( V_10 ) ;
default:
break;
}
return 0 ;
}
static void F_50 ( struct V_9 * V_10 )
{
V_10 -> V_21 = V_10 -> V_12 . V_4 - 1 ;
V_10 -> V_13 = 0 ;
V_10 -> V_29 = 0 ;
V_10 -> V_28 = 0 ;
V_10 -> V_33 = 0 ;
V_10 -> V_12 . V_6 = 0 ;
V_10 -> V_12 . V_5 = 0 ;
}
static void F_51 ( struct V_9 * V_10 , T_2 V_4 )
{
T_2 V_8 ;
V_10 -> V_21 = V_4 ;
for ( V_8 = F_7 ( & V_10 -> V_24 ) ;
V_8 > V_4 ;
V_8 = F_7 ( & V_10 -> V_24 ) ) {
F_9 ( & V_10 -> V_24 ) ;
V_10 -> V_87 ++ ;
}
}
static void F_52 ( struct V_9 * V_10 )
{
F_50 ( V_10 ) ;
V_10 -> V_41 = V_88 ;
V_10 -> V_43 = V_88 ;
if ( V_10 -> V_48 == V_49 )
V_10 -> V_48 = V_86 ;
else
V_10 -> V_48 = V_56 ;
}
static T_3 F_53 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_89 V_48 = V_10 -> V_48 ;
const T_1 * V_72 = & V_10 -> V_44 ;
T_2 V_4 , V_5 ;
V_4 = F_47 ( * V_72 , V_71 ) ;
V_5 = F_47 ( * V_72 , V_70 ) ;
switch ( V_48 ) {
case V_57 :
case V_49 :
F_52 ( V_10 ) ;
break;
case V_86 :
if ( V_4 > V_10 -> V_12 . V_4 ) {
V_10 -> V_21 = V_10 -> V_12 . V_4 - 1 ;
} else {
V_10 -> V_48 = V_49 ;
F_51 ( V_10 , V_4 ) ;
}
break;
default:
break;
}
V_10 -> V_6 = V_5 ;
return F_49 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_54 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_72 = & V_10 -> V_44 ;
T_2 V_5 , V_6 ;
T_3 V_50 ;
V_5 = F_47 ( * V_72 , V_70 ) ;
V_6 = F_47 ( * V_72 , V_74 ) ;
if ( V_10 -> V_48 == V_86 ) {
V_10 -> V_6 = V_5 ;
V_10 -> V_48 = V_49 ;
}
V_50 = F_27 ( V_23 , V_10 , V_6 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_31 ( V_10 ) ;
if ( V_50 )
return V_50 ;
F_35 ( V_23 , V_10 ) ;
return F_49 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_55 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_89 V_48 = V_10 -> V_48 ;
const T_1 * V_72 = & V_10 -> V_44 ;
T_2 V_5 ;
T_3 V_50 ;
V_5 = F_47 ( * V_72 , V_70 ) ;
if ( V_10 -> V_13 )
return V_77 ;
V_10 -> V_33 = 0 ;
V_50 = F_31 ( V_10 ) ;
if ( V_50 )
return V_50 ;
switch ( V_48 ) {
case V_57 :
case V_49 :
if ( ! F_34 ( V_10 ) )
break;
if ( V_5 != V_10 -> V_6 )
return V_78 ;
F_52 ( V_10 ) ;
break;
default:
break;
}
return F_49 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_56 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_72 = & V_10 -> V_44 ;
T_3 V_90 ;
T_2 V_5 ;
V_5 = F_47 ( * V_72 , V_70 ) ;
V_90 = F_47 ( * V_72 , V_82 ) ;
V_90 |= ~ F_48 ( V_82 ) ;
switch ( V_10 -> V_48 ) {
case V_49 :
case V_57 :
F_50 ( V_10 ) ;
V_10 -> V_41 = V_88 ;
V_10 -> V_43 = V_88 ;
V_10 -> V_6 = V_5 ;
if ( V_10 -> V_48 == V_49 ) {
V_10 -> V_48 = V_86 ;
break;
}
F_41 ( V_10 ) ;
return 0 ;
default:
break;
}
return F_49 ( V_23 , V_10 , V_10 -> V_6 ) ;
}
static T_3 F_57 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
T_3 V_50 ;
if ( V_10 -> V_48 == V_56 )
return 0 ;
V_50 = F_39 ( V_23 , V_10 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_46 ( V_10 ) ;
if ( V_50 < 0 )
goto V_91;
switch ( F_47 ( V_10 -> V_44 , TYPE ) ) {
case V_69 :
V_50 = F_53 ( V_23 , V_10 ) ;
break;
case V_73 :
V_50 = F_54 ( V_23 , V_10 ) ;
break;
case V_76 :
V_50 = F_55 ( V_23 , V_10 ) ;
break;
case V_81 :
V_50 = F_56 ( V_23 , V_10 ) ;
break;
default:
V_50 = V_79 ;
break;
}
V_91:
if ( V_50 < 0 )
F_45 ( V_10 , V_50 ) ;
F_40 ( V_23 , V_10 ) ;
return V_50 ;
}
static void F_58 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
int V_55 = V_10 -> V_55 ? V_92 : 0 ;
V_10 -> V_48 = V_57 ;
F_23 ( V_23 , V_10 -> V_63 , V_68 |
V_93 ) ;
do {
F_38 ( V_94 ) ;
V_10 -> V_59 . V_60 ( V_23 , V_10 ) ;
V_55 -= V_94 ;
} while ( ( V_55 > 0 ) && ( V_10 -> V_48 != V_56 ) );
F_52 ( V_10 ) ;
F_10 ( & V_10 -> V_24 ) ;
F_23 ( V_23 , V_10 -> V_26 , 0 ) ;
}
static T_3 F_59 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( ! V_10 -> V_12 . V_3 )
return V_18 ;
if ( V_10 -> V_48 != V_56 )
return V_62 ;
V_10 -> V_55 = V_95 ;
V_10 -> V_48 = V_86 ;
F_44 ( V_10 ) ;
F_23 ( V_23 , V_10 -> V_26 ^ V_10 -> V_11 , V_10 -> V_44 ) ;
V_10 -> V_65 = V_64 | V_67 |
V_96 ;
F_41 ( V_10 ) ;
F_40 ( V_23 , V_10 ) ;
return 0 ;
}
static T_3 F_60 ( const struct V_97 * V_52 )
{
const struct V_98 * V_99 ;
unsigned int V_100 ;
if ( ! V_52 )
return 0 ;
while ( V_52 -> V_100 != V_101 ) {
if ( ! V_52 -> V_102 )
return V_103 ;
V_99 = V_52 -> V_99 ;
if ( V_99 ) {
while ( V_99 -> V_100 != V_101 ) {
V_100 = V_99 -> V_100 ;
V_99 ++ ;
if ( V_100 >= V_99 -> V_100 )
return V_103 ;
if ( V_100 >= V_104 )
return V_103 ;
}
if ( V_99 -> V_100 != V_101 )
return V_103 ;
}
V_100 = V_52 -> V_100 ;
V_52 ++ ;
if ( V_100 >= V_52 -> V_100 )
return V_103 ;
}
if ( ( V_52 -> V_100 != V_101 ) || ! V_52 -> V_102 )
return V_103 ;
return 0 ;
}
static T_3 F_61 ( struct V_9 * V_10 ,
const struct V_97 * V_52 )
{
if ( F_60 ( V_52 ) )
return V_103 ;
V_10 -> V_52 = V_52 ;
return 0 ;
}
T_3 F_62 ( struct V_22 * V_23 , struct V_9 * V_10 ,
const struct V_97 * V_52 , T_4 V_100 )
{
switch ( V_23 -> V_105 . type ) {
case V_106 :
V_10 -> V_63 = V_107 ;
V_10 -> V_26 = F_63 ( V_108 ) ;
break;
case V_109 :
if ( V_100 < 64 ) {
V_10 -> V_63 = F_64 ( V_100 ) ;
V_10 -> V_26 = F_65 ( V_100 , 0 ) ;
break;
}
default:
return V_58 ;
}
V_10 -> V_48 = V_56 ;
if ( F_60 ( V_52 ) )
return V_103 ;
V_10 -> V_52 = V_52 ;
V_10 -> V_55 = 0 ;
V_10 -> F_38 = V_110 ;
V_10 -> V_6 = 1 ;
V_10 -> V_5 = 1 ;
V_10 -> V_41 = V_88 ;
V_10 -> V_43 = V_88 ;
V_10 -> V_21 = V_111 ;
V_10 -> V_11 = V_108 ;
F_1 ( & V_10 -> V_24 , V_10 -> V_3 , V_112 ) ;
F_1 ( & V_10 -> V_12 , & V_10 -> V_3 [ V_112 ] ,
V_113 ) ;
V_10 -> V_59 . V_114 = F_59 ;
V_10 -> V_59 . V_115 = F_58 ;
V_10 -> V_59 . V_116 = F_32 ;
V_10 -> V_59 . V_117 = F_33 ;
V_10 -> V_59 . V_118 = F_34 ;
V_10 -> V_59 . V_119 = F_37 ;
V_10 -> V_59 . V_60 = F_57 ;
V_10 -> V_59 . V_120 = F_61 ;
return 0 ;
}
static void F_66 ( struct V_9 * V_10 )
{
if ( V_10 -> V_28 )
V_10 -> V_65 |= V_68 ;
V_10 -> V_44 = F_42 ( V_10 -> V_6 , V_121 ) |
F_42 ( V_10 -> V_43 , V_122 ) |
F_42 ( V_10 -> V_5 , V_123 ) ;
}
static void F_67 ( struct V_9 * V_10 , T_4 V_50 )
{
if ( V_10 -> V_41 )
V_10 -> V_65 |= V_68 ;
V_10 -> V_44 = F_42 ( V_10 -> V_6 , V_121 ) |
F_42 ( V_10 -> V_43 , V_122 ) |
F_42 ( V_10 -> V_5 , V_123 ) |
F_42 ( V_50 , V_124 ) ;
}
static void F_68 ( struct V_9 * V_10 )
{
F_50 ( V_10 ) ;
V_10 -> V_41 = V_125 ;
V_10 -> V_43 = 0 ;
V_10 -> V_6 = 1 ;
V_10 -> V_5 = 1 ;
V_10 -> V_48 = V_86 ;
}
static T_3 F_69 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( ! V_10 -> V_12 . V_3 )
return V_18 ;
if ( V_10 -> V_48 != V_56 )
return V_62 ;
V_10 -> V_55 = V_95 ;
V_10 -> V_48 = V_86 ;
V_10 -> V_21 = V_111 ;
F_68 ( V_10 ) ;
V_10 -> V_65 = V_64 | V_67 |
V_96 ;
F_67 ( V_10 , 0 ) ;
F_40 ( V_23 , V_10 ) ;
return 0 ;
}
static void F_70 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
int V_55 = V_10 -> V_55 ? V_92 : 0 ;
V_10 -> V_48 = V_57 ;
F_23 ( V_23 , V_10 -> V_63 , V_68 |
V_93 ) ;
do {
F_38 ( V_94 ) ;
V_10 -> V_59 . V_60 ( V_23 , V_10 ) ;
V_55 -= V_94 ;
} while ( ( V_55 > 0 ) && ( V_10 -> V_48 != V_56 ) );
V_10 -> V_48 = V_56 ;
V_10 -> V_43 = 0 ;
F_50 ( V_10 ) ;
F_51 ( V_10 , 0 ) ;
F_23 ( V_23 , V_10 -> V_26 , 0 ) ;
}
static T_3 F_71 ( struct V_9 * V_10 )
{
const T_1 * V_72 = & V_10 -> V_44 ;
T_2 V_6 , V_5 , V_126 ;
V_6 = F_47 ( * V_72 , V_121 ) ;
V_126 = F_47 ( * V_72 , V_122 ) ;
V_5 = F_47 ( * V_72 , V_123 ) ;
switch ( V_126 ) {
case 0 :
break;
case V_125 :
if ( ! V_5 || V_5 > V_127 )
return V_78 ;
if ( ! V_6 || V_6 > V_127 )
return V_77 ;
if ( V_10 -> V_6 < V_5 )
V_5 += V_10 -> V_11 - 1 ;
if ( V_6 < V_10 -> V_5 )
V_6 += V_10 -> V_11 - 1 ;
if ( F_11 ( V_10 , V_5 , V_10 -> V_6 ) > V_10 -> V_28 )
return V_78 ;
if ( F_11 ( V_10 , V_10 -> V_5 , V_6 ) < V_10 -> V_11 )
break;
return V_77 ;
default:
return V_128 ;
}
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
const enum V_89 V_48 = V_10 -> V_48 ;
switch ( V_48 ) {
case V_57 :
V_10 -> V_43 = 0 ;
break;
case V_49 :
F_68 ( V_10 ) ;
break;
case V_86 :
if ( V_10 -> V_43 ) {
while ( V_10 -> V_41 > 1 )
V_10 -> V_41 -- ;
V_10 -> V_43 = 0 ;
}
break;
default:
break;
}
F_67 ( V_10 , 0 ) ;
}
static void F_73 ( struct V_9 * V_10 , T_3 V_50 )
{
switch ( V_50 ) {
case V_77 :
case V_78 :
case V_128 :
case V_17 :
case V_80 :
break;
default:
return;
}
F_72 ( V_10 ) ;
F_67 ( V_10 , 1 ) ;
}
static T_3 F_74 ( struct V_22 * V_23 ,
struct V_9 * V_10 ,
T_2 V_6 )
{
T_2 V_11 = V_10 -> V_11 - 1 ;
T_3 V_50 ;
if ( V_6 < V_10 -> V_5 )
V_6 += V_11 ;
V_50 = F_27 ( V_23 , V_10 , V_6 ) ;
if ( V_50 < 0 )
return V_50 ;
F_35 ( V_23 , V_10 ) ;
V_10 -> V_5 = F_15 ( V_10 , V_10 -> V_13 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_5 > V_11 )
V_10 -> V_5 -= V_11 ;
return V_50 ;
}
static void F_75 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
struct V_1 * V_2 = & V_10 -> V_24 ;
T_2 V_11 = V_10 -> V_11 - 1 ;
T_2 V_28 , V_8 = 0 ;
T_1 * V_14 ;
if ( V_10 -> V_6 < V_5 )
V_5 += V_11 ;
F_24 ( V_23 , V_10 , V_5 ) ;
do {
V_14 = V_2 -> V_3 + F_5 ( V_2 , V_8 ) ;
V_28 = V_8 ;
V_8 += F_8 ( * V_14 ) ;
} while ( ( V_8 <= V_10 -> V_28 ) && ( V_8 < V_11 ) );
if ( V_10 -> V_28 > V_28 ) {
V_10 -> V_6 = F_13 ( V_10 , V_10 -> V_28 - V_28 ) ;
V_10 -> V_28 = V_28 ;
}
if ( V_10 -> V_6 > V_11 )
V_10 -> V_6 -= V_11 ;
}
static void F_76 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
switch ( V_10 -> V_48 ) {
case V_49 :
case V_57 :
F_75 ( V_23 , V_10 , V_5 ) ;
if ( V_10 -> V_28 || ( V_10 -> V_48 == V_49 ) ) {
F_66 ( V_10 ) ;
} else {
V_10 -> V_43 = 0 ;
F_67 ( V_10 , 0 ) ;
}
break;
case V_86 :
case V_56 :
F_67 ( V_10 , 0 ) ;
break;
default:
break;
}
}
static void F_77 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_89 V_48 = V_10 -> V_48 ;
switch ( V_48 ) {
case V_57 :
V_10 -> V_48 = V_56 ;
V_10 -> V_43 = 0 ;
V_10 -> V_41 = 0 ;
break;
case V_49 :
F_68 ( V_10 ) ;
break;
case V_86 :
V_10 -> V_43 = V_10 -> V_41 ;
default:
break;
}
F_76 ( V_23 , V_10 , V_10 -> V_6 ) ;
}
static T_3 F_78 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_72 = & V_10 -> V_44 ;
T_2 V_5 , V_6 ;
T_3 V_8 ;
V_6 = F_47 ( * V_72 , V_121 ) ;
V_5 = F_47 ( * V_72 , V_123 ) ;
if ( V_10 -> V_48 == V_86 ) {
if ( ! V_10 -> V_43 )
goto V_129;
if ( V_10 -> V_43 != 1 )
return V_128 ;
V_10 -> V_48 = V_49 ;
}
do {
V_8 = F_74 ( V_23 , V_10 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
} while ( V_8 );
V_129:
F_76 ( V_23 , V_10 , V_5 ) ;
return 0 ;
}
static T_3 F_79 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
T_3 V_50 ;
if ( V_10 -> V_48 == V_56 )
return 0 ;
V_50 = F_39 ( V_23 , V_10 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_71 ( V_10 ) ;
if ( V_50 < 0 )
goto V_130;
if ( F_47 ( V_10 -> V_44 , V_124 ) ) {
F_72 ( V_10 ) ;
goto V_130;
}
switch ( F_47 ( V_10 -> V_44 , V_122 ) ) {
case 0 :
F_77 ( V_23 , V_10 ) ;
break;
case V_125 :
V_50 = F_78 ( V_23 , V_10 ) ;
break;
}
V_130:
if ( V_50 < 0 )
F_73 ( V_10 , V_50 ) ;
F_40 ( V_23 , V_10 ) ;
return V_50 ;
}
T_3 F_80 ( struct V_22 * V_23 , struct V_9 * V_10 ,
const struct V_97 * V_52 )
{
V_10 -> V_63 = V_131 ;
V_10 -> V_26 = F_81 ( 0 ) ;
V_10 -> V_48 = V_56 ;
if ( F_60 ( V_52 ) )
return V_103 ;
V_10 -> V_52 = V_52 ;
V_10 -> V_55 = 0 ;
V_10 -> F_38 = V_110 ;
V_10 -> V_21 = V_111 ;
V_10 -> V_11 = V_132 ;
F_1 ( & V_10 -> V_24 , V_10 -> V_3 , V_112 ) ;
F_1 ( & V_10 -> V_12 , & V_10 -> V_3 [ V_112 ] ,
V_113 ) ;
V_10 -> V_59 . V_114 = F_69 ;
V_10 -> V_59 . V_115 = F_70 ;
V_10 -> V_59 . V_116 = F_32 ;
V_10 -> V_59 . V_117 = F_33 ;
V_10 -> V_59 . V_118 = F_34 ;
V_10 -> V_59 . V_119 = F_37 ;
V_10 -> V_59 . V_60 = F_79 ;
V_10 -> V_59 . V_120 = F_61 ;
return 0 ;
}
