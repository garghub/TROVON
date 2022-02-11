static T_1 F_1 ( T_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 [ V_4 ] ;
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_3 [ V_5 ] = V_1 [ V_5 ] ;
for ( V_5 = 0 ; V_5 < V_4 - 1 ; V_5 ++ ) {
for ( V_6 = 1 ; V_6 < V_4 - V_5 ; V_6 ++ ) {
if ( V_3 [ V_6 ] > V_3 [ V_6 - 1 ] ) {
V_2 = V_3 [ V_6 ] ;
V_3 [ V_6 ] = V_3 [ V_6 - 1 ] ;
V_3 [ V_6 - 1 ] = V_2 ;
}
}
}
V_2 = V_3 [ ( V_4 - 1 ) >> 1 ] ;
return V_2 ;
}
static struct V_7 * F_2 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_12 ;
if ( ! V_11 || F_3 ( V_11 ) )
V_12 = & V_9 -> V_13 ;
else
V_12 = & V_9 -> V_14 ;
return V_12 ;
}
static T_2 F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
return F_2 ( V_9 , V_11 ) -> V_15 ;
}
T_2 F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
T_3 V_16 = V_17 ;
if ( V_11 && V_11 -> V_18 ) {
T_3 V_19 = V_11 -> V_18 -
F_4 ( V_9 , V_11 ) ;
if ( V_19 > 0 )
V_16 += V_19 ;
}
return V_16 ;
}
static void F_6 ( struct V_8 * V_9 ,
struct V_20 * V_21 ,
T_1 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_9 ) ;
struct V_7 * V_12 ;
struct V_25 * V_26 ;
bool V_27 = false ;
T_4 V_28 = ( V_9 -> V_29 << 3 ) | V_9 -> V_29 ;
int V_5 ;
V_26 = V_21 -> V_30 ;
V_12 = F_2 ( V_9 , V_9 -> V_31 ) ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! ( V_28 & ( 1 << V_5 ) ) ||
( ( V_5 >= V_33 ) && ! F_8 ( V_9 -> V_31 ) ) )
continue;
V_26 [ V_5 ] . V_1 [ V_26 [ V_5 ] . V_34 ] = V_22 [ V_5 ] ;
if ( ++ V_26 [ V_5 ] . V_34 >= V_4 )
V_26 [ V_5 ] . V_34 = 0 ;
if ( V_26 [ V_5 ] . V_35 > 0 ) {
V_26 [ V_5 ] . V_35 -- ;
V_26 [ V_5 ] . V_36 = V_22 [ V_5 ] ;
} else {
V_26 [ V_5 ] . V_36 =
F_1 ( V_26 [ V_5 ] . V_1 ) ;
}
if ( ! V_26 [ V_5 ] . V_36 )
continue;
if ( V_26 [ V_5 ] . V_36 > V_12 -> V_37 ) {
V_27 = true ;
F_9 ( V_24 , V_38 ,
L_1 ,
V_5 , V_26 [ V_5 ] . V_36 , V_12 -> V_37 ,
( V_21 -> V_39 ?
L_2 :
L_3 ) ) ;
if ( ! V_21 -> V_39 )
V_26 [ V_5 ] . V_36 = V_12 -> V_37 ;
}
}
if ( ! V_27 )
V_21 -> V_39 = false ;
}
static bool F_10 ( struct V_8 * V_9 ,
enum V_40 V_41 ,
T_1 * V_42 )
{
switch ( V_41 ) {
case V_43 :
* V_42 = ( V_44 ) V_9 -> V_45 -> V_46 ( V_9 , V_47 ) ;
break;
case V_48 :
* V_42 = ( V_44 ) V_9 -> V_45 -> V_46 ( V_9 , V_49 ) ;
break;
default:
F_11 ( 1 ) ;
return false ;
}
return true ;
}
void F_12 ( struct V_8 * V_9 ,
struct V_50 * V_51 )
{
int V_5 ;
F_13 ( V_9 , V_51 ) ;
V_51 -> V_52 = V_53 ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
V_9 -> V_54 . V_55 [ V_5 ] = 0 ;
V_9 -> V_56 . V_55 [ V_5 ] = 0 ;
V_9 -> V_57 . V_55 [ V_5 ] = 0 ;
V_9 -> V_58 . V_55 [ V_5 ] = 0 ;
}
V_9 -> V_59 = 0 ;
}
bool F_14 ( struct V_8 * V_9 )
{
struct V_23 * V_24 = F_7 ( V_9 ) ;
struct V_60 * V_61 = & V_24 -> V_62 -> V_61 ;
struct V_50 * V_51 = V_9 -> V_63 ;
if ( ! V_9 -> V_64 )
return true ;
if ( ! F_15 ( V_9 ) && ! F_16 ( V_9 ) )
return true ;
if ( V_51 == NULL )
return true ;
if ( V_51 -> V_52 != V_65 ) {
F_9 ( V_24 , V_38 , L_4 ,
V_51 -> V_52 ) ;
return true ;
}
if ( ! ( V_9 -> V_66 & V_51 -> V_67 -> V_68 ) )
return true ;
F_9 ( V_24 , V_38 , L_5 ,
V_51 -> V_67 -> V_68 , V_61 -> V_69 -> V_70 ) ;
V_9 -> V_64 -> V_71 &= ~ V_51 -> V_67 -> V_68 ;
V_51 -> V_52 = V_72 ;
return false ;
}
void F_17 ( struct V_8 * V_9 , bool V_73 )
{
if ( V_9 -> V_64 )
V_9 -> V_64 -> V_74 = true ;
F_18 ( V_9 , V_75 ,
V_76 ) ;
if ( V_73 )
F_19 ( V_9 , V_75 ,
V_77 ) ;
else
F_18 ( V_9 , V_75 ,
V_77 ) ;
F_18 ( V_9 , V_75 , V_78 ) ;
}
void F_20 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_25 * V_26 = NULL ;
unsigned V_5 , V_6 ;
T_5 V_79 ;
T_4 V_28 = ( V_9 -> V_29 << 3 ) | V_9 -> V_29 ;
struct V_23 * V_24 = F_7 ( V_9 ) ;
struct V_60 * V_61 = & V_24 -> V_62 -> V_61 ;
T_2 V_80 = F_4 ( V_9 , V_11 ) ;
if ( V_9 -> V_64 )
V_26 = V_9 -> V_64 -> V_30 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( V_28 & ( 1 << V_5 ) ) {
T_2 V_2 ;
if ( ( V_5 >= V_33 ) && ! F_21 ( V_61 ) )
continue;
if ( V_26 )
V_2 = V_26 [ V_5 ] . V_36 ;
else
V_2 = V_80 ;
V_79 = F_22 ( V_9 , V_9 -> V_81 [ V_5 ] ) ;
V_79 &= 0xFFFFFE00 ;
V_79 |= ( ( ( V_82 ) V_2 << 1 ) & 0x1ff ) ;
F_23 ( V_9 , V_9 -> V_81 [ V_5 ] , V_79 ) ;
}
}
F_19 ( V_9 , V_75 ,
V_76 ) ;
F_19 ( V_9 , V_75 ,
V_77 ) ;
F_18 ( V_9 , V_75 , V_78 ) ;
for ( V_6 = 0 ; V_6 < 10000 ; V_6 ++ ) {
if ( ( F_22 ( V_9 , V_75 ) &
V_78 ) == 0 )
break;
F_24 ( 10 ) ;
}
if ( V_6 == 10000 ) {
F_9 ( V_24 , V_83 ,
L_6 ,
F_22 ( V_9 , V_75 ) ) ;
return;
}
F_25 ( V_9 ) ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( V_28 & ( 1 << V_5 ) ) {
if ( ( V_5 >= V_33 ) && ! F_21 ( V_61 ) )
continue;
V_79 = F_22 ( V_9 , V_9 -> V_81 [ V_5 ] ) ;
V_79 &= 0xFFFFFE00 ;
V_79 |= ( ( ( V_82 ) ( - 50 ) << 1 ) & 0x1ff ) ;
F_23 ( V_9 , V_9 -> V_81 [ V_5 ] , V_79 ) ;
}
}
F_26 ( V_9 ) ;
}
static void F_27 ( struct V_8 * V_9 , T_2 * V_84 )
{
struct V_23 * V_24 = F_7 ( V_9 ) ;
struct V_7 * V_12 ;
int V_5 ;
if ( F_3 ( V_9 -> V_31 ) )
V_12 = & V_9 -> V_13 ;
else
V_12 = & V_9 -> V_14 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( ! V_84 [ V_5 ] )
continue;
F_9 ( V_24 , V_38 ,
L_7 ,
( V_5 >= 3 ? L_8 : L_9 ) , V_5 % 3 , V_84 [ V_5 ] ) ;
if ( V_84 [ V_5 ] > V_12 -> V_37 ) {
F_9 ( V_24 , V_38 ,
L_10 ,
V_5 , V_84 [ V_5 ] , V_12 -> V_37 ) ;
V_84 [ V_5 ] = V_12 -> V_37 ;
} else if ( V_84 [ V_5 ] < V_12 -> V_85 ) {
F_9 ( V_24 , V_38 ,
L_11 ,
V_5 , V_84 [ V_5 ] , V_12 -> V_85 ) ;
V_84 [ V_5 ] = V_12 -> V_15 ;
}
}
}
bool F_28 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_23 * V_24 = F_7 ( V_9 ) ;
T_1 V_84 , V_86 ;
T_1 V_22 [ V_32 ] = { 0 } ;
struct V_25 * V_26 ;
struct V_87 * V_88 = V_11 -> V_11 ;
struct V_20 * V_64 = V_9 -> V_64 ;
V_11 -> V_89 &= ( ~ V_90 ) ;
if ( F_22 ( V_9 , V_75 ) & V_78 ) {
F_9 ( V_24 , V_38 ,
L_12 ) ;
return false ;
}
F_29 ( V_9 , V_22 ) ;
F_27 ( V_9 , V_22 ) ;
V_84 = V_22 [ 0 ] ;
if ( F_10 ( V_9 , V_88 -> V_41 , & V_86 )
&& V_84 > V_86 ) {
F_9 ( V_24 , V_38 ,
L_13 ,
V_84 , V_86 ) ;
V_11 -> V_89 |= V_90 ;
}
if ( ! V_64 ) {
V_11 -> V_18 = V_84 ;
V_9 -> V_16 = F_5 ( V_9 , V_11 ) ;
return false ;
}
V_26 = V_64 -> V_30 ;
V_64 -> V_74 = false ;
F_6 ( V_9 , V_64 , V_22 ) ;
V_11 -> V_18 = V_26 [ 0 ] . V_36 ;
V_9 -> V_16 = F_5 ( V_9 , V_11 ) ;
return true ;
}
void F_30 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_25 * V_26 ;
T_2 V_80 ;
int V_5 , V_6 ;
V_9 -> V_64 -> V_69 = V_11 -> V_69 ;
V_9 -> V_64 -> V_89 = V_11 -> V_89 & ~ V_90 ;
V_26 = V_9 -> V_64 -> V_30 ;
V_80 = F_4 ( V_9 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
V_26 [ V_5 ] . V_34 = 0 ;
V_26 [ V_5 ] . V_36 = V_80 ;
V_26 [ V_5 ] . V_35 = V_91 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_26 [ V_5 ] . V_1 [ V_6 ] = V_80 ;
}
}
}
void F_31 ( struct V_8 * V_9 )
{
struct V_20 * V_64 = V_9 -> V_64 ;
if ( F_32 ( ! V_64 ) )
return;
if ( ! V_64 -> V_74 )
F_17 ( V_9 , true ) ;
else if ( ! ( F_22 ( V_9 , V_75 ) & V_78 ) )
F_28 ( V_9 , V_9 -> V_31 ) ;
V_64 -> V_39 = true ;
}
