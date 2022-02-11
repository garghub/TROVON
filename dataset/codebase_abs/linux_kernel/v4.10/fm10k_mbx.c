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
V_10 -> V_30 ++ ;
F_23 ( V_23 , V_25 + V_6 ++ , * ( V_5 ++ ) ) ;
} while ( -- V_8 && -- V_16 );
}
}
static void F_24 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
T_2 V_11 , V_8 , V_31 = F_11 ( V_10 , V_5 , V_10 -> V_6 ) ;
struct V_1 * V_2 = & V_10 -> V_24 ;
V_10 -> V_29 += V_10 -> V_28 - V_31 ;
V_11 = V_10 -> V_11 - 1 ;
V_8 = F_2 ( V_2 ) - V_10 -> V_29 ;
if ( V_8 > V_11 )
V_8 = V_11 ;
V_10 -> V_6 = F_12 ( V_10 , V_8 - V_31 ) ;
V_10 -> V_28 = V_8 ;
for ( V_8 = F_7 ( V_2 ) ;
V_8 && ( V_10 -> V_29 >= V_8 ) ;
V_8 = F_7 ( V_2 ) ) {
V_10 -> V_29 -= F_9 ( V_2 ) ;
V_10 -> V_32 ++ ;
V_10 -> V_33 += V_8 ;
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
V_8 = V_10 -> V_34 ;
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
V_10 -> V_35 ++ ;
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
T_2 V_8 , V_36 = F_11 ( V_10 , V_10 -> V_5 , V_6 ) ;
V_8 = F_3 ( V_2 ) - V_10 -> V_13 ;
if ( V_8 > V_36 )
V_8 = V_36 ;
V_10 -> V_5 = F_14 ( V_10 , V_8 ) ;
V_10 -> V_34 = V_8 ;
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
V_10 -> V_37 ++ ;
V_10 -> V_38 += V_8 ;
}
return 0 ;
}
static T_2 F_28 ( const T_1 * V_39 , T_2 V_40 , T_2 V_8 )
{
T_1 V_41 = V_40 ;
while ( V_8 -- ) {
V_41 ^= * ( V_39 ++ ) ;
V_41 = ( V_41 >> 8 ) ^ V_42 [ V_41 & 0xFF ] ;
V_41 = ( V_41 >> 8 ) ^ V_42 [ V_41 & 0xFF ] ;
if ( ! ( V_8 -- ) )
break;
V_41 = ( V_41 >> 8 ) ^ V_42 [ V_41 & 0xFF ] ;
V_41 = ( V_41 >> 8 ) ^ V_42 [ V_41 & 0xFF ] ;
}
return ( T_2 ) V_41 ;
}
static T_2 F_29 ( struct V_1 * V_2 , T_2 V_7 ,
T_2 V_8 , T_2 V_40 )
{
T_1 * V_39 = V_2 -> V_3 + V_7 ;
V_7 = V_2 -> V_4 - V_7 ;
if ( V_7 < V_8 ) {
V_40 = F_28 ( V_39 , V_40 , V_7 * 2 ) ;
V_39 = V_2 -> V_3 ;
V_8 -= V_7 ;
}
return F_28 ( V_39 , V_40 , V_8 * 2 ) ;
}
static void F_30 ( struct V_9 * V_10 , T_2 V_5 )
{
T_2 V_8 = V_10 -> V_28 - F_11 ( V_10 , V_5 , V_10 -> V_6 ) ;
V_5 = F_5 ( & V_10 -> V_24 , V_10 -> V_29 ) ;
V_10 -> V_43 = F_29 ( & V_10 -> V_24 , V_5 , V_8 , V_10 -> V_43 ) ;
}
static T_3 F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_2 V_8 = V_10 -> V_34 ;
T_2 V_7 = F_6 ( V_2 , V_10 -> V_13 ) - V_8 ;
T_2 V_44 ;
if ( V_8 )
V_10 -> V_45 = F_29 ( V_2 , V_7 , V_8 , V_10 -> V_45 ) ;
V_44 = F_28 ( & V_10 -> V_46 , V_10 -> V_45 , 1 ) ;
return V_44 ? V_47 : 0 ;
}
static bool F_32 ( struct V_9 * V_10 )
{
T_2 V_48 = F_7 ( & V_10 -> V_12 ) ;
return V_48 && ( F_2 ( & V_10 -> V_12 ) >= V_48 ) ;
}
static bool F_33 ( struct V_9 * V_10 , T_2 V_8 )
{
T_2 V_49 = F_3 ( & V_10 -> V_24 ) ;
return ( V_10 -> V_50 == V_51 ) && ( V_49 >= V_8 ) ;
}
static bool F_34 ( struct V_9 * V_10 )
{
return F_4 ( & V_10 -> V_24 ) ;
}
static T_2 F_35 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
T_3 V_52 ;
T_2 V_53 ;
for ( V_53 = 0 ; ! F_4 ( V_2 ) ; V_53 ++ ) {
V_52 = F_36 ( V_23 , V_2 -> V_3 + V_2 -> V_5 ,
V_10 , V_10 -> V_54 ) ;
if ( V_52 < 0 )
V_10 -> V_55 ++ ;
F_9 ( V_2 ) ;
}
memmove ( V_2 -> V_3 , V_2 -> V_3 + V_2 -> V_6 , V_10 -> V_13 << 2 ) ;
V_2 -> V_6 -= V_2 -> V_5 ;
V_2 -> V_5 = 0 ;
return V_53 ;
}
static T_3 F_37 ( struct V_22 * V_23 ,
struct V_9 * V_10 , const T_1 * V_14 )
{
T_1 V_56 = V_10 -> V_57 ;
T_3 V_52 ;
switch ( V_10 -> V_50 ) {
case V_58 :
case V_59 :
return V_60 ;
default:
break;
}
V_52 = F_18 ( & V_10 -> V_24 , V_14 ) ;
while ( V_52 && V_56 ) {
V_56 -- ;
F_38 ( V_10 -> F_38 ) ;
V_10 -> V_61 . V_62 ( V_23 , V_10 ) ;
V_52 = F_18 ( & V_10 -> V_24 , V_14 ) ;
}
if ( V_52 ) {
V_10 -> V_57 = 0 ;
V_10 -> V_63 ++ ;
}
if ( ! V_10 -> V_28 )
V_10 -> V_61 . V_62 ( V_23 , V_10 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( V_10 -> V_46 )
return V_64 ;
if ( F_26 ( V_23 , V_10 -> V_65 ) & V_66 )
V_10 -> V_67 = V_68 ;
F_23 ( V_23 , V_10 -> V_65 ,
V_66 | V_69 ) ;
V_10 -> V_46 = F_26 ( V_23 , V_10 -> V_26 ^ V_10 -> V_11 ) ;
return 0 ;
}
static void F_40 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
T_1 V_25 = V_10 -> V_26 ;
F_23 ( V_23 , V_25 , V_10 -> V_46 ) ;
if ( V_10 -> V_67 )
F_23 ( V_23 , V_10 -> V_65 , V_10 -> V_67 ) ;
V_10 -> V_46 = 0 ;
V_10 -> V_67 = 0 ;
}
static void F_41 ( struct V_9 * V_10 )
{
V_10 -> V_67 |= V_70 ;
V_10 -> V_46 = F_42 ( V_71 , TYPE ) |
F_42 ( V_10 -> V_5 , V_72 ) |
F_42 ( V_10 -> V_12 . V_4 - 1 , V_73 ) ;
}
static void F_43 ( struct V_9 * V_10 )
{
T_1 V_74 = F_42 ( V_75 , TYPE ) |
F_42 ( V_10 -> V_6 , V_76 ) |
F_42 ( V_10 -> V_5 , V_72 ) ;
struct V_1 * V_2 = & V_10 -> V_24 ;
T_2 V_44 ;
if ( V_10 -> V_28 )
V_10 -> V_67 |= V_70 ;
V_44 = F_29 ( V_2 , F_5 ( V_2 , V_10 -> V_29 ) ,
V_10 -> V_28 , V_10 -> V_43 ) ;
V_44 = F_28 ( & V_74 , V_44 , 1 ) ;
V_10 -> V_46 = V_74 | F_42 ( V_44 , V_77 ) ;
}
static void F_44 ( struct V_9 * V_10 )
{
T_1 V_74 = F_42 ( V_78 , TYPE ) |
F_42 ( V_10 -> V_6 , V_76 ) |
F_42 ( V_10 -> V_5 , V_72 ) ;
T_2 V_44 = F_28 ( & V_74 , V_10 -> V_43 , 1 ) ;
V_10 -> V_67 |= V_68 ;
V_10 -> V_46 = V_74 | F_42 ( V_44 , V_77 ) ;
}
static void F_45 ( struct V_9 * V_10 )
{
T_1 V_74 = F_42 ( V_78 , TYPE ) |
F_42 ( V_10 -> V_5 , V_76 ) |
F_42 ( V_10 -> V_6 , V_72 ) ;
T_2 V_44 = F_28 ( & V_74 , V_10 -> V_43 , 1 ) ;
V_10 -> V_67 |= V_68 ;
V_10 -> V_46 = V_74 | F_42 ( V_44 , V_77 ) ;
}
static void F_46 ( struct V_9 * V_10 , T_3 V_52 )
{
switch ( V_52 ) {
case V_79 :
case V_80 :
case V_81 :
case V_17 :
case V_82 :
case V_47 :
break;
default:
return;
}
V_10 -> V_67 |= V_70 ;
V_10 -> V_46 = F_42 ( V_83 , TYPE ) |
F_42 ( V_52 , V_84 ) |
F_42 ( V_10 -> V_5 , V_72 ) ;
}
static T_3 F_47 ( struct V_9 * V_10 )
{
T_2 type , V_85 , V_5 , V_6 , V_4 ;
const T_1 * V_74 = & V_10 -> V_46 ;
type = F_48 ( * V_74 , TYPE ) ;
V_85 = F_48 ( * V_74 , V_86 ) ;
V_6 = F_48 ( * V_74 , V_76 ) ;
V_5 = F_48 ( * V_74 , V_72 ) ;
V_4 = F_48 ( * V_74 , V_73 ) ;
if ( V_85 )
return V_82 ;
switch ( type ) {
case V_78 :
if ( V_6 != V_10 -> V_5 )
return V_79 ;
case V_75 :
if ( ! V_5 || ( V_5 == F_49 ( V_72 ) ) )
return V_80 ;
if ( F_11 ( V_10 , V_5 , V_10 -> V_6 ) > V_10 -> V_28 )
return V_80 ;
if ( ! V_6 || ( V_6 == F_49 ( V_76 ) ) )
return V_79 ;
if ( F_11 ( V_10 , V_10 -> V_5 , V_6 ) < V_10 -> V_11 )
break;
return V_79 ;
case V_71 :
if ( ( V_4 < V_87 ) || ( V_4 & ( V_4 + 1 ) ) )
return V_17 ;
case V_83 :
if ( ! V_5 || ( V_5 == F_49 ( V_72 ) ) )
return V_80 ;
if ( V_6 )
return V_79 ;
break;
default:
return V_81 ;
}
return 0 ;
}
static T_3 F_50 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
switch ( V_10 -> V_50 ) {
case V_51 :
case V_59 :
F_30 ( V_10 , V_5 ) ;
F_24 ( V_23 , V_10 , V_5 ) ;
if ( V_10 -> V_28 || ( V_10 -> V_50 == V_51 ) )
F_43 ( V_10 ) ;
else
F_44 ( V_10 ) ;
break;
case V_88 :
F_41 ( V_10 ) ;
break;
case V_58 :
F_44 ( V_10 ) ;
default:
break;
}
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
T_2 V_8 , V_5 , V_31 ;
V_10 -> V_21 = V_10 -> V_12 . V_4 - 1 ;
V_5 = F_48 ( V_10 -> V_46 , V_72 ) ;
V_31 = F_11 ( V_10 , V_5 , V_10 -> V_6 ) ;
V_10 -> V_29 += V_10 -> V_28 - V_31 ;
while ( F_7 ( & V_10 -> V_24 ) && V_10 -> V_29 ) {
V_8 = F_9 ( & V_10 -> V_24 ) ;
V_10 -> V_89 ++ ;
if ( V_10 -> V_29 >= V_8 )
V_10 -> V_29 -= V_8 ;
else
V_10 -> V_29 = 0 ;
}
V_10 -> V_13 = 0 ;
V_10 -> V_29 = 0 ;
V_10 -> V_28 = 0 ;
V_10 -> V_34 = 0 ;
V_10 -> V_12 . V_6 = 0 ;
V_10 -> V_12 . V_5 = 0 ;
}
static void F_52 ( struct V_9 * V_10 , T_2 V_4 )
{
T_2 V_8 ;
V_10 -> V_21 = V_4 ;
for ( V_8 = F_7 ( & V_10 -> V_24 ) ;
V_8 > V_4 ;
V_8 = F_7 ( & V_10 -> V_24 ) ) {
F_9 ( & V_10 -> V_24 ) ;
V_10 -> V_89 ++ ;
}
}
static void F_53 ( struct V_9 * V_10 )
{
F_51 ( V_10 ) ;
V_10 -> V_43 = V_90 ;
V_10 -> V_45 = V_90 ;
if ( V_10 -> V_50 == V_51 )
V_10 -> V_50 = V_88 ;
else
V_10 -> V_50 = V_58 ;
}
static T_3 F_54 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_91 V_50 = V_10 -> V_50 ;
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_4 , V_5 ;
V_4 = F_48 ( * V_74 , V_73 ) ;
V_5 = F_48 ( * V_74 , V_72 ) ;
switch ( V_50 ) {
case V_59 :
case V_51 :
F_53 ( V_10 ) ;
break;
case V_88 :
if ( V_4 > V_10 -> V_12 . V_4 ) {
V_10 -> V_21 = V_10 -> V_12 . V_4 - 1 ;
} else {
V_10 -> V_50 = V_51 ;
F_52 ( V_10 , V_4 ) ;
}
break;
default:
break;
}
V_10 -> V_6 = V_5 ;
return F_50 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_55 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_5 , V_6 ;
T_3 V_52 ;
V_5 = F_48 ( * V_74 , V_72 ) ;
V_6 = F_48 ( * V_74 , V_76 ) ;
if ( V_10 -> V_50 == V_88 ) {
V_10 -> V_6 = V_5 ;
V_10 -> V_50 = V_51 ;
}
V_52 = F_27 ( V_23 , V_10 , V_6 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_31 ( V_10 ) ;
if ( V_52 )
return V_52 ;
F_35 ( V_23 , V_10 ) ;
return F_50 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_56 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_91 V_50 = V_10 -> V_50 ;
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_5 ;
T_3 V_52 ;
V_5 = F_48 ( * V_74 , V_72 ) ;
if ( V_10 -> V_13 )
return V_79 ;
V_10 -> V_34 = 0 ;
V_52 = F_31 ( V_10 ) ;
if ( V_52 )
return V_52 ;
switch ( V_50 ) {
case V_59 :
case V_51 :
if ( ! F_34 ( V_10 ) )
break;
if ( V_5 != V_10 -> V_6 )
return V_80 ;
F_53 ( V_10 ) ;
break;
default:
break;
}
return F_50 ( V_23 , V_10 , V_5 ) ;
}
static T_3 F_57 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_5 ;
V_5 = F_48 ( * V_74 , V_72 ) ;
switch ( V_10 -> V_50 ) {
case V_51 :
case V_59 :
F_51 ( V_10 ) ;
V_10 -> V_43 = V_90 ;
V_10 -> V_45 = V_90 ;
V_10 -> V_6 = V_5 ;
if ( V_10 -> V_50 == V_51 ) {
V_10 -> V_50 = V_88 ;
break;
}
F_41 ( V_10 ) ;
return 0 ;
default:
break;
}
return F_50 ( V_23 , V_10 , V_10 -> V_6 ) ;
}
static T_3 F_58 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
T_3 V_52 ;
if ( V_10 -> V_50 == V_58 )
return 0 ;
V_52 = F_39 ( V_23 , V_10 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_47 ( V_10 ) ;
if ( V_52 < 0 )
goto V_92;
switch ( F_48 ( V_10 -> V_46 , TYPE ) ) {
case V_71 :
V_52 = F_54 ( V_23 , V_10 ) ;
break;
case V_75 :
V_52 = F_55 ( V_23 , V_10 ) ;
break;
case V_78 :
V_52 = F_56 ( V_23 , V_10 ) ;
break;
case V_83 :
V_52 = F_57 ( V_23 , V_10 ) ;
break;
default:
V_52 = V_81 ;
break;
}
V_92:
if ( V_52 < 0 )
F_46 ( V_10 , V_52 ) ;
F_40 ( V_23 , V_10 ) ;
return V_52 ;
}
static void F_59 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
int V_57 = V_10 -> V_57 ? V_93 : 0 ;
V_10 -> V_50 = V_59 ;
F_23 ( V_23 , V_10 -> V_65 , V_70 |
V_94 ) ;
do {
F_38 ( V_95 ) ;
V_10 -> V_61 . V_62 ( V_23 , V_10 ) ;
V_57 -= V_95 ;
} while ( ( V_57 > 0 ) && ( V_10 -> V_50 != V_58 ) );
F_53 ( V_10 ) ;
F_10 ( & V_10 -> V_24 ) ;
F_23 ( V_23 , V_10 -> V_26 , 0 ) ;
}
static T_3 F_60 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( ! V_10 -> V_12 . V_3 )
return V_18 ;
if ( V_10 -> V_50 != V_58 )
return V_64 ;
V_10 -> V_57 = V_96 ;
V_10 -> V_50 = V_88 ;
F_51 ( V_10 ) ;
F_45 ( V_10 ) ;
F_23 ( V_23 , V_10 -> V_26 ^ V_10 -> V_11 , V_10 -> V_46 ) ;
V_10 -> V_67 = V_66 | V_69 |
V_97 ;
F_41 ( V_10 ) ;
F_40 ( V_23 , V_10 ) ;
return 0 ;
}
static T_3 F_61 ( const struct V_98 * V_54 )
{
const struct V_99 * V_100 ;
unsigned int V_101 ;
if ( ! V_54 )
return 0 ;
while ( V_54 -> V_101 != V_102 ) {
if ( ! V_54 -> V_103 )
return V_104 ;
V_100 = V_54 -> V_100 ;
if ( V_100 ) {
while ( V_100 -> V_101 != V_102 ) {
V_101 = V_100 -> V_101 ;
V_100 ++ ;
if ( V_101 >= V_100 -> V_101 )
return V_104 ;
if ( V_101 >= V_105 )
return V_104 ;
}
if ( V_100 -> V_101 != V_102 )
return V_104 ;
}
V_101 = V_54 -> V_101 ;
V_54 ++ ;
if ( V_101 >= V_54 -> V_101 )
return V_104 ;
}
if ( ( V_54 -> V_101 != V_102 ) || ! V_54 -> V_103 )
return V_104 ;
return 0 ;
}
static T_3 F_62 ( struct V_9 * V_10 ,
const struct V_98 * V_54 )
{
if ( F_61 ( V_54 ) )
return V_104 ;
V_10 -> V_54 = V_54 ;
return 0 ;
}
T_3 F_63 ( struct V_22 * V_23 , struct V_9 * V_10 ,
const struct V_98 * V_54 , T_4 V_101 )
{
switch ( V_23 -> V_106 . type ) {
case V_107 :
V_10 -> V_65 = V_108 ;
V_10 -> V_26 = F_64 ( V_109 ) ;
break;
case V_110 :
if ( V_101 < 64 ) {
V_10 -> V_65 = F_65 ( V_101 ) ;
V_10 -> V_26 = F_66 ( V_101 , 0 ) ;
break;
}
default:
return V_60 ;
}
V_10 -> V_50 = V_58 ;
if ( F_61 ( V_54 ) )
return V_104 ;
V_10 -> V_54 = V_54 ;
V_10 -> V_57 = 0 ;
V_10 -> F_38 = V_111 ;
V_10 -> V_6 = 1 ;
V_10 -> V_5 = 1 ;
V_10 -> V_43 = V_90 ;
V_10 -> V_45 = V_90 ;
V_10 -> V_21 = V_112 ;
V_10 -> V_11 = V_109 ;
F_1 ( & V_10 -> V_24 , V_10 -> V_3 , V_113 ) ;
F_1 ( & V_10 -> V_12 , & V_10 -> V_3 [ V_113 ] ,
V_114 ) ;
V_10 -> V_61 . V_115 = F_60 ;
V_10 -> V_61 . V_116 = F_59 ;
V_10 -> V_61 . V_117 = F_32 ;
V_10 -> V_61 . V_118 = F_33 ;
V_10 -> V_61 . V_119 = F_34 ;
V_10 -> V_61 . V_120 = F_37 ;
V_10 -> V_61 . V_62 = F_58 ;
V_10 -> V_61 . V_121 = F_62 ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
if ( V_10 -> V_28 )
V_10 -> V_67 |= V_70 ;
V_10 -> V_46 = F_42 ( V_10 -> V_6 , V_122 ) |
F_42 ( V_10 -> V_45 , V_123 ) |
F_42 ( V_10 -> V_5 , V_124 ) ;
}
static void F_68 ( struct V_9 * V_10 , T_4 V_52 )
{
if ( V_10 -> V_43 )
V_10 -> V_67 |= V_70 ;
V_10 -> V_46 = F_42 ( V_10 -> V_6 , V_122 ) |
F_42 ( V_10 -> V_45 , V_123 ) |
F_42 ( V_10 -> V_5 , V_124 ) |
F_42 ( V_52 , V_125 ) ;
}
static void F_69 ( struct V_9 * V_10 )
{
F_51 ( V_10 ) ;
V_10 -> V_43 = V_126 ;
V_10 -> V_45 = 0 ;
V_10 -> V_6 = 1 ;
V_10 -> V_5 = 1 ;
V_10 -> V_50 = V_88 ;
}
static T_3 F_70 ( struct V_22 * V_23 , struct V_9 * V_10 )
{
if ( ! V_10 -> V_12 . V_3 )
return V_18 ;
if ( V_10 -> V_50 != V_58 )
return V_64 ;
V_10 -> V_57 = V_96 ;
V_10 -> V_50 = V_88 ;
V_10 -> V_21 = V_112 ;
F_69 ( V_10 ) ;
V_10 -> V_67 = V_66 | V_69 |
V_97 ;
F_68 ( V_10 , 0 ) ;
F_40 ( V_23 , V_10 ) ;
return 0 ;
}
static void F_71 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
int V_57 = V_10 -> V_57 ? V_93 : 0 ;
V_10 -> V_50 = V_59 ;
F_23 ( V_23 , V_10 -> V_65 , V_70 |
V_94 ) ;
do {
F_38 ( V_95 ) ;
V_10 -> V_61 . V_62 ( V_23 , V_10 ) ;
V_57 -= V_95 ;
} while ( ( V_57 > 0 ) && ( V_10 -> V_50 != V_58 ) );
V_10 -> V_50 = V_58 ;
V_10 -> V_45 = 0 ;
F_51 ( V_10 ) ;
F_10 ( & V_10 -> V_24 ) ;
F_23 ( V_23 , V_10 -> V_26 , 0 ) ;
}
static T_3 F_72 ( struct V_9 * V_10 )
{
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_6 , V_5 , V_127 ;
V_6 = F_48 ( * V_74 , V_122 ) ;
V_127 = F_48 ( * V_74 , V_123 ) ;
V_5 = F_48 ( * V_74 , V_124 ) ;
switch ( V_127 ) {
case 0 :
break;
case V_126 :
if ( ! V_5 || V_5 > V_128 )
return V_80 ;
if ( ! V_6 || V_6 > V_128 )
return V_79 ;
if ( V_10 -> V_6 < V_5 )
V_5 += V_10 -> V_11 - 1 ;
if ( V_6 < V_10 -> V_5 )
V_6 += V_10 -> V_11 - 1 ;
if ( F_11 ( V_10 , V_5 , V_10 -> V_6 ) > V_10 -> V_28 )
return V_80 ;
if ( F_11 ( V_10 , V_10 -> V_5 , V_6 ) < V_10 -> V_11 )
break;
return V_79 ;
default:
return V_129 ;
}
return 0 ;
}
static void F_73 ( struct V_9 * V_10 )
{
const enum V_91 V_50 = V_10 -> V_50 ;
switch ( V_50 ) {
case V_59 :
V_10 -> V_45 = 0 ;
break;
case V_51 :
F_69 ( V_10 ) ;
break;
case V_88 :
if ( V_10 -> V_45 ) {
while ( V_10 -> V_43 > 1 )
V_10 -> V_43 -- ;
V_10 -> V_45 = 0 ;
}
break;
default:
break;
}
F_68 ( V_10 , 0 ) ;
}
static void F_74 ( struct V_9 * V_10 , T_3 V_52 )
{
switch ( V_52 ) {
case V_79 :
case V_80 :
case V_129 :
case V_17 :
case V_82 :
break;
default:
return;
}
F_73 ( V_10 ) ;
F_68 ( V_10 , 1 ) ;
}
static T_3 F_75 ( struct V_22 * V_23 ,
struct V_9 * V_10 ,
T_2 V_6 )
{
T_2 V_11 = V_10 -> V_11 - 1 ;
T_3 V_52 ;
if ( V_6 < V_10 -> V_5 )
V_6 += V_11 ;
V_52 = F_27 ( V_23 , V_10 , V_6 ) ;
if ( V_52 < 0 )
return V_52 ;
F_35 ( V_23 , V_10 ) ;
V_10 -> V_5 = F_15 ( V_10 , V_10 -> V_13 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_5 > V_11 )
V_10 -> V_5 -= V_11 ;
return V_52 ;
}
static void F_76 ( struct V_22 * V_23 ,
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
static void F_77 ( struct V_22 * V_23 ,
struct V_9 * V_10 , T_2 V_5 )
{
switch ( V_10 -> V_50 ) {
case V_51 :
case V_59 :
F_76 ( V_23 , V_10 , V_5 ) ;
if ( V_10 -> V_28 || ( V_10 -> V_50 == V_51 ) ) {
F_67 ( V_10 ) ;
} else {
V_10 -> V_45 = 0 ;
F_68 ( V_10 , 0 ) ;
}
break;
case V_88 :
case V_58 :
F_68 ( V_10 , 0 ) ;
break;
default:
break;
}
}
static void F_78 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const enum V_91 V_50 = V_10 -> V_50 ;
switch ( V_50 ) {
case V_59 :
V_10 -> V_50 = V_58 ;
V_10 -> V_45 = 0 ;
V_10 -> V_43 = 0 ;
break;
case V_51 :
F_69 ( V_10 ) ;
break;
case V_88 :
V_10 -> V_45 = V_10 -> V_43 ;
default:
break;
}
F_77 ( V_23 , V_10 , V_10 -> V_6 ) ;
}
static T_3 F_79 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
const T_1 * V_74 = & V_10 -> V_46 ;
T_2 V_5 , V_6 ;
T_3 V_8 ;
V_6 = F_48 ( * V_74 , V_122 ) ;
V_5 = F_48 ( * V_74 , V_124 ) ;
if ( V_10 -> V_50 == V_88 ) {
if ( ! V_10 -> V_45 )
goto V_130;
if ( V_10 -> V_45 != 1 )
return V_129 ;
V_10 -> V_50 = V_51 ;
}
do {
V_8 = F_75 ( V_23 , V_10 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
} while ( V_8 );
V_130:
F_77 ( V_23 , V_10 , V_5 ) ;
return 0 ;
}
static T_3 F_80 ( struct V_22 * V_23 ,
struct V_9 * V_10 )
{
T_3 V_52 ;
if ( V_10 -> V_50 == V_58 )
return 0 ;
V_52 = F_39 ( V_23 , V_10 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_72 ( V_10 ) ;
if ( V_52 < 0 )
goto V_131;
if ( F_48 ( V_10 -> V_46 , V_125 ) ) {
F_73 ( V_10 ) ;
goto V_131;
}
switch ( F_48 ( V_10 -> V_46 , V_123 ) ) {
case 0 :
F_78 ( V_23 , V_10 ) ;
break;
case V_126 :
V_52 = F_79 ( V_23 , V_10 ) ;
break;
}
V_131:
if ( V_52 < 0 )
F_74 ( V_10 , V_52 ) ;
F_40 ( V_23 , V_10 ) ;
return V_52 ;
}
T_3 F_81 ( struct V_22 * V_23 , struct V_9 * V_10 ,
const struct V_98 * V_54 )
{
V_10 -> V_65 = V_132 ;
V_10 -> V_26 = F_82 ( 0 ) ;
V_10 -> V_50 = V_58 ;
if ( F_61 ( V_54 ) )
return V_104 ;
V_10 -> V_54 = V_54 ;
V_10 -> V_57 = 0 ;
V_10 -> F_38 = V_111 ;
V_10 -> V_21 = V_112 ;
V_10 -> V_11 = V_133 ;
F_1 ( & V_10 -> V_24 , V_10 -> V_3 , V_113 ) ;
F_1 ( & V_10 -> V_12 , & V_10 -> V_3 [ V_113 ] ,
V_114 ) ;
V_10 -> V_61 . V_115 = F_70 ;
V_10 -> V_61 . V_116 = F_71 ;
V_10 -> V_61 . V_117 = F_32 ;
V_10 -> V_61 . V_118 = F_33 ;
V_10 -> V_61 . V_119 = F_34 ;
V_10 -> V_61 . V_120 = F_37 ;
V_10 -> V_61 . V_62 = F_80 ;
V_10 -> V_61 . V_121 = F_62 ;
return 0 ;
}
