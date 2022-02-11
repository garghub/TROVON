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
static void F_5 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
T_1 * V_18 )
{
struct V_19 * V_20 = F_6 ( V_9 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_22 ;
struct V_7 * V_12 ;
struct V_24 * V_25 ;
bool V_26 = false ;
T_3 V_27 = ( V_9 -> V_28 << 3 ) | V_9 -> V_28 ;
int V_5 ;
V_25 = V_17 -> V_29 ;
V_12 = F_2 ( V_9 , V_9 -> V_30 ) ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( ! ( V_27 & ( 1 << V_5 ) ) ||
( ( V_5 >= V_32 ) && ! F_7 ( V_22 ) ) )
continue;
V_25 [ V_5 ] . V_1 [ V_25 [ V_5 ] . V_33 ] = V_18 [ V_5 ] ;
if ( ++ V_25 [ V_5 ] . V_33 >= V_4 )
V_25 [ V_5 ] . V_33 = 0 ;
if ( V_25 [ V_5 ] . V_34 > 0 ) {
V_25 [ V_5 ] . V_34 -- ;
V_25 [ V_5 ] . V_35 = V_18 [ V_5 ] ;
} else {
V_25 [ V_5 ] . V_35 =
F_1 ( V_25 [ V_5 ] . V_1 ) ;
}
if ( ! V_25 [ V_5 ] . V_35 )
continue;
if ( V_25 [ V_5 ] . V_35 > V_12 -> V_36 ) {
V_26 = true ;
F_8 ( V_20 , V_37 ,
L_1 ,
V_5 , V_25 [ V_5 ] . V_35 , V_12 -> V_36 ,
( V_17 -> V_38 ?
L_2 :
L_3 ) ) ;
if ( ! V_17 -> V_38 )
V_25 [ V_5 ] . V_35 = V_12 -> V_36 ;
}
}
if ( ! V_26 )
V_17 -> V_38 = false ;
}
static bool F_9 ( struct V_8 * V_9 ,
enum V_39 V_40 ,
T_1 * V_41 )
{
switch ( V_40 ) {
case V_42 :
* V_41 = ( V_43 ) V_9 -> V_44 -> V_45 ( V_9 , V_46 ) ;
break;
case V_47 :
* V_41 = ( V_43 ) V_9 -> V_44 -> V_45 ( V_9 , V_48 ) ;
break;
default:
F_10 ( 1 ) ;
return false ;
}
return true ;
}
void F_11 ( struct V_8 * V_9 ,
struct V_49 * V_50 )
{
int V_5 ;
F_12 ( V_9 , V_50 ) ;
V_50 -> V_51 = V_52 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
V_9 -> V_53 . V_54 [ V_5 ] = 0 ;
V_9 -> V_55 . V_54 [ V_5 ] = 0 ;
V_9 -> V_56 . V_54 [ V_5 ] = 0 ;
V_9 -> V_57 . V_54 [ V_5 ] = 0 ;
}
V_9 -> V_58 = 0 ;
}
bool F_13 ( struct V_8 * V_9 )
{
struct V_19 * V_20 = F_6 ( V_9 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_22 ;
struct V_49 * V_50 = V_9 -> V_59 ;
if ( ! V_9 -> V_60 )
return true ;
if ( ! F_14 ( V_9 ) && ! F_15 ( V_9 ) )
return true ;
if ( V_50 == NULL )
return true ;
if ( V_50 -> V_51 != V_61 ) {
F_8 ( V_20 , V_37 ,
L_4 ,
V_50 -> V_51 ) ;
return true ;
}
if ( ! ( V_9 -> V_62 & V_50 -> V_63 -> V_64 ) )
return true ;
F_8 ( V_20 , V_37 ,
L_5 ,
V_50 -> V_63 -> V_64 , V_22 -> V_65 -> V_66 ) ;
V_9 -> V_60 -> V_67 &= ~ V_50 -> V_63 -> V_64 ;
V_50 -> V_51 = V_68 ;
return false ;
}
void F_16 ( struct V_8 * V_9 , bool V_69 )
{
if ( V_9 -> V_60 )
V_9 -> V_60 -> V_70 = true ;
F_17 ( V_9 , V_71 ,
V_72 ) ;
if ( V_69 )
F_18 ( V_9 , V_71 ,
V_73 ) ;
else
F_17 ( V_9 , V_71 ,
V_73 ) ;
F_17 ( V_9 , V_71 , V_74 ) ;
}
void F_19 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_24 * V_25 = NULL ;
unsigned V_5 , V_6 ;
T_4 V_75 ;
T_3 V_27 = ( V_9 -> V_28 << 3 ) | V_9 -> V_28 ;
struct V_19 * V_20 = F_6 ( V_9 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_22 ;
T_2 V_76 = F_4 ( V_9 , V_11 ) ;
if ( V_9 -> V_60 )
V_25 = V_9 -> V_60 -> V_29 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( V_27 & ( 1 << V_5 ) ) {
T_2 V_2 ;
if ( ( V_5 >= V_32 ) && ! F_7 ( V_22 ) )
continue;
if ( V_25 )
V_2 = V_25 [ V_5 ] . V_35 ;
else
V_2 = V_76 ;
V_75 = F_20 ( V_9 , V_9 -> V_77 [ V_5 ] ) ;
V_75 &= 0xFFFFFE00 ;
V_75 |= ( ( ( V_78 ) V_2 << 1 ) & 0x1ff ) ;
F_21 ( V_9 , V_9 -> V_77 [ V_5 ] , V_75 ) ;
}
}
F_18 ( V_9 , V_71 ,
V_72 ) ;
F_18 ( V_9 , V_71 ,
V_73 ) ;
F_17 ( V_9 , V_71 , V_74 ) ;
for ( V_6 = 0 ; V_6 < 10000 ; V_6 ++ ) {
if ( ( F_20 ( V_9 , V_71 ) &
V_74 ) == 0 )
break;
F_22 ( 10 ) ;
}
if ( V_6 == 10000 ) {
F_8 ( V_20 , V_79 ,
L_6 ,
F_20 ( V_9 , V_71 ) ) ;
return;
}
F_23 ( V_9 ) ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( V_27 & ( 1 << V_5 ) ) {
if ( ( V_5 >= V_32 ) && ! F_7 ( V_22 ) )
continue;
V_75 = F_20 ( V_9 , V_9 -> V_77 [ V_5 ] ) ;
V_75 &= 0xFFFFFE00 ;
V_75 |= ( ( ( V_78 ) ( - 50 ) << 1 ) & 0x1ff ) ;
F_21 ( V_9 , V_9 -> V_77 [ V_5 ] , V_75 ) ;
}
}
F_24 ( V_9 ) ;
}
static void F_25 ( struct V_8 * V_9 , T_2 * V_80 )
{
struct V_19 * V_20 = F_6 ( V_9 ) ;
struct V_7 * V_12 ;
int V_5 ;
if ( F_3 ( V_9 -> V_30 ) )
V_12 = & V_9 -> V_13 ;
else
V_12 = & V_9 -> V_14 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
if ( ! V_80 [ V_5 ] )
continue;
F_8 ( V_20 , V_37 ,
L_7 ,
( V_5 >= 3 ? L_8 : L_9 ) , V_5 % 3 , V_80 [ V_5 ] ) ;
if ( V_80 [ V_5 ] > V_81 ) {
F_8 ( V_20 , V_37 ,
L_10 ,
V_5 , V_80 [ V_5 ] , V_81 ) ;
V_80 [ V_5 ] = V_12 -> V_36 ;
} else if ( V_80 [ V_5 ] < V_12 -> V_82 ) {
F_8 ( V_20 , V_37 ,
L_11 ,
V_5 , V_80 [ V_5 ] , V_12 -> V_82 ) ;
V_80 [ V_5 ] = V_12 -> V_15 ;
}
}
}
bool F_26 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_19 * V_20 = F_6 ( V_9 ) ;
T_1 V_80 , V_83 ;
T_1 V_18 [ V_31 ] = { 0 } ;
struct V_24 * V_25 ;
struct V_84 * V_85 = V_11 -> V_11 ;
struct V_16 * V_60 = V_9 -> V_60 ;
V_11 -> V_86 &= ( ~ V_87 ) ;
if ( F_20 ( V_9 , V_71 ) & V_74 ) {
F_8 ( V_20 , V_37 ,
L_12 ) ;
return false ;
}
F_27 ( V_9 , V_18 ) ;
F_25 ( V_9 , V_18 ) ;
V_80 = V_18 [ 0 ] ;
if ( F_9 ( V_9 , V_85 -> V_40 , & V_83 )
&& V_80 > V_83 ) {
F_8 ( V_20 , V_37 ,
L_13 ,
V_80 , V_83 ) ;
V_11 -> V_86 |= V_87 ;
}
if ( ! V_60 ) {
V_11 -> V_88 = V_80 ;
return false ;
}
V_25 = V_60 -> V_29 ;
V_60 -> V_70 = false ;
F_5 ( V_9 , V_60 , V_18 ) ;
V_11 -> V_88 = V_25 [ 0 ] . V_35 ;
return true ;
}
void F_28 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_24 * V_25 ;
T_2 V_76 ;
int V_5 , V_6 ;
V_9 -> V_60 -> V_65 = V_11 -> V_65 ;
V_9 -> V_60 -> V_86 = V_11 -> V_86 & ~ V_87 ;
V_25 = V_9 -> V_60 -> V_29 ;
V_76 = F_4 ( V_9 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
V_25 [ V_5 ] . V_33 = 0 ;
V_25 [ V_5 ] . V_35 = V_76 ;
V_25 [ V_5 ] . V_34 = V_89 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_25 [ V_5 ] . V_1 [ V_6 ] = V_76 ;
}
}
}
void F_29 ( struct V_8 * V_9 )
{
struct V_16 * V_60 = V_9 -> V_60 ;
if ( F_30 ( ! V_60 ) )
return;
if ( ! V_60 -> V_70 )
F_16 ( V_9 , true ) ;
else if ( ! ( F_20 ( V_9 , V_71 ) & V_74 ) )
F_26 ( V_9 , V_9 -> V_30 ) ;
V_60 -> V_38 = true ;
}
