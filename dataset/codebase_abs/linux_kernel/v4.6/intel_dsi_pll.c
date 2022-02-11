int F_1 ( int V_1 )
{
int V_2 ;
switch ( V_1 ) {
default:
case V_3 :
case V_4 :
V_2 = 24 ;
break;
case V_5 :
V_2 = 18 ;
break;
case V_6 :
V_2 = 16 ;
break;
}
return V_2 ;
}
static T_1 F_2 ( T_1 V_7 , int V_1 , int V_8 )
{
T_1 V_9 ;
T_1 V_2 = F_1 ( V_1 ) ;
V_9 = F_3 ( V_7 * V_2 , V_8 ) ;
return V_9 ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_12 * V_12 , int V_13 )
{
unsigned int V_14 = 0 , V_15 = 0 ;
unsigned int V_16 , V_17 , V_18 = 2 , V_19 = 6 ;
unsigned int V_20 , V_21 , V_22 ;
int V_23 ;
int V_24 = V_13 ;
T_1 V_25 ;
if ( V_13 < 300000 || V_13 > 1150000 ) {
F_5 ( L_1 ) ;
return - V_26 ;
}
if ( F_6 ( V_11 ) ) {
V_23 = 100000 ;
V_21 = 4 ;
V_16 = 70 ;
V_17 = 96 ;
} else {
V_23 = 25000 ;
V_21 = 1 ;
V_16 = 62 ;
V_17 = 92 ;
}
for ( V_20 = V_16 ; V_20 <= V_17 && V_24 ; V_20 ++ ) {
for ( V_22 = V_18 ; V_22 <= V_19 && V_24 ; V_22 ++ ) {
int V_27 = ( V_20 * V_23 ) / ( V_22 * V_21 ) ;
int V_28 = abs ( V_13 - V_27 ) ;
if ( V_28 < V_24 ) {
V_24 = V_28 ;
V_14 = V_20 ;
V_15 = V_22 ;
}
}
}
V_21 = F_7 ( V_21 ) - 1 ;
V_25 = V_29 [ V_14 - 62 ] ;
V_12 -> V_30 = 1 << ( V_31 + V_15 - 2 ) ;
V_12 -> V_32 = V_21 << V_33 |
V_25 << V_34 ;
return 0 ;
}
static void F_8 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
int V_41 ;
struct V_12 V_12 ;
T_1 V_42 ;
V_42 = F_2 ( V_40 -> V_7 , V_40 -> V_1 ,
V_40 -> V_8 ) ;
V_41 = F_4 ( V_11 , & V_12 , V_42 ) ;
if ( V_41 ) {
F_10 ( L_2 ) ;
return;
}
if ( V_40 -> V_43 & ( 1 << V_44 ) )
V_12 . V_30 |= V_45 ;
if ( V_40 -> V_43 & ( 1 << V_46 ) )
V_12 . V_30 |= V_47 ;
F_10 ( L_3 ,
V_12 . V_32 , V_12 . V_30 ) ;
F_11 ( V_11 , V_48 , 0 ) ;
F_11 ( V_11 , V_49 , V_12 . V_32 ) ;
F_11 ( V_11 , V_48 , V_12 . V_30 ) ;
}
static void F_12 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
T_1 V_50 ;
F_10 ( L_4 ) ;
F_13 ( & V_11 -> V_51 ) ;
F_8 ( V_36 ) ;
F_14 ( 1 , 10 ) ;
V_50 = F_15 ( V_11 , V_48 ) ;
V_50 |= V_52 ;
F_11 ( V_11 , V_48 , V_50 ) ;
if ( F_16 ( F_15 ( V_11 , V_48 ) &
V_53 , 20 ) ) {
F_17 ( & V_11 -> V_51 ) ;
F_5 ( L_5 ) ;
return;
}
F_17 ( & V_11 -> V_51 ) ;
F_10 ( L_6 ) ;
}
static void F_18 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
T_1 V_50 ;
F_10 ( L_4 ) ;
F_13 ( & V_11 -> V_51 ) ;
V_50 = F_15 ( V_11 , V_48 ) ;
V_50 &= ~ V_52 ;
V_50 |= V_54 ;
F_11 ( V_11 , V_48 , V_50 ) ;
F_17 ( & V_11 -> V_51 ) ;
}
static void F_19 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
T_1 V_55 ;
F_10 ( L_4 ) ;
V_55 = F_20 ( V_56 ) ;
V_55 &= ~ V_57 ;
F_21 ( V_56 , V_55 ) ;
if ( F_16 ( ( F_20 ( V_56 )
& V_58 ) == 0 , 1 ) )
F_5 ( L_7 ) ;
}
static void F_22 ( int V_1 , int V_59 )
{
int V_2 = F_1 ( V_1 ) ;
F_23 ( V_2 != V_59 ,
L_8 ,
V_2 , V_59 ) ;
}
static T_1 F_24 ( struct V_35 * V_36 , int V_59 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
T_1 V_60 , V_7 ;
T_1 V_61 , V_62 ;
T_1 V_20 = 0 , V_22 = 0 , V_21 ;
int V_63 = 25000 ;
int V_64 ;
F_10 ( L_4 ) ;
F_13 ( & V_11 -> V_51 ) ;
V_61 = F_15 ( V_11 , V_48 ) ;
V_62 = F_15 ( V_11 , V_49 ) ;
F_17 ( & V_11 -> V_51 ) ;
V_61 &= V_65 ;
V_61 = V_61 >> ( V_31 - 2 ) ;
V_21 = ( V_62 & V_66 ) >> V_33 ;
V_21 = 1 << V_21 ;
V_62 &= V_67 ;
V_62 = V_62 >> V_34 ;
while ( V_61 ) {
V_61 = V_61 >> 1 ;
V_22 ++ ;
}
V_22 -- ;
if ( ! V_22 ) {
F_5 ( L_9 ) ;
return 0 ;
}
for ( V_64 = 0 ; V_64 < F_25 ( V_29 ) ; V_64 ++ ) {
if ( V_29 [ V_64 ] == V_62 )
break;
}
if ( V_64 == F_25 ( V_29 ) ) {
F_5 ( L_10 ) ;
return 0 ;
}
V_20 = V_64 + 62 ;
V_60 = ( V_20 * V_63 ) / ( V_22 * V_21 ) ;
F_22 ( V_40 -> V_1 , V_59 ) ;
V_7 = F_3 ( V_60 * V_40 -> V_8 , V_59 ) ;
return V_7 ;
}
static T_1 F_26 ( struct V_35 * V_36 , int V_59 )
{
T_1 V_7 ;
T_1 V_42 ;
T_1 V_68 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
if ( ! V_59 ) {
F_5 ( L_11 ) ;
return 0 ;
}
V_68 = F_20 ( V_69 ) &
V_70 ;
if ( V_68 < V_71 ||
V_68 > V_72 ) {
F_5 ( L_12 , V_68 ) ;
return 0 ;
}
V_42 = ( V_68 * V_73 ) / 2 ;
F_22 ( V_40 -> V_1 , V_59 ) ;
V_7 = F_3 ( V_42 * V_40 -> V_8 , V_59 ) ;
F_27 ( L_13 , V_7 ) ;
return V_7 ;
}
T_1 F_28 ( struct V_35 * V_36 , int V_59 )
{
if ( F_29 ( V_36 -> V_37 . V_38 ) )
return F_26 ( V_36 , V_59 ) ;
else
return F_24 ( V_36 , V_59 ) ;
}
static void F_30 ( struct V_35 * V_36 , enum V_74 V_74 )
{
T_1 V_75 ;
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
V_75 = F_20 ( F_31 ( V_74 ) ) ;
V_75 &= ~ V_76 ;
F_21 ( F_31 ( V_74 ) , V_75 |
V_40 -> V_77 <<
V_78 ) ;
}
static void F_32 ( struct V_79 * V_38 , enum V_74 V_74 )
{
T_1 V_50 ;
T_1 V_80 ;
T_1 V_81 ;
T_1 V_82 ;
struct V_10 * V_11 = V_38 -> V_39 ;
V_50 = F_20 ( V_83 ) ;
V_50 &= ~ ( F_33 ( V_74 ) ) ;
V_50 &= ~ ( F_34 ( V_74 ) ) ;
V_50 &= ~ ( F_35 ( V_74 ) ) ;
V_50 &= ~ ( F_36 ( V_74 ) ) ;
V_82 = F_20 ( V_69 ) &
V_70 ;
V_81 = ( V_73 * V_82 ) / 2 ;
V_80 = ( V_81 / V_84 ) - 1 ;
V_50 |= F_37 ( V_74 , V_80 ) ;
V_50 |= F_38 ( V_74 ) ;
V_50 |= F_39 ( V_74 ) ;
F_21 ( V_83 , V_50 ) ;
}
static bool F_40 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
T_2 V_68 ;
T_1 V_42 ;
T_1 V_55 ;
V_42 = F_2 ( V_40 -> V_7 , V_40 -> V_1 ,
V_40 -> V_8 ) ;
V_68 = F_41 ( V_42 * 2 , V_73 ) ;
if ( V_68 < V_71 ||
V_68 > V_72 ) {
F_5 ( L_14 ) ;
return false ;
}
V_55 = F_20 ( V_69 ) ;
V_55 &= ~ V_85 ;
V_55 &= ~ V_86 ;
V_55 &= ~ V_70 ;
V_55 |= ( V_68 | V_87 | V_88 ) ;
if ( V_68 <= 50 ) {
V_55 &= ~ V_85 ;
V_55 |= V_89 ;
}
F_21 ( V_69 , V_55 ) ;
F_42 ( V_69 ) ;
return true ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_40 = F_9 ( & V_36 -> V_37 ) ;
enum V_74 V_74 ;
T_1 V_55 ;
F_10 ( L_4 ) ;
V_55 = F_20 ( V_56 ) ;
if ( V_55 & V_57 ) {
F_23 ( 1 , L_15 ) ;
V_55 &= ~ V_57 ;
F_21 ( V_56 , V_55 ) ;
}
if ( ! F_40 ( V_36 ) ) {
F_5 ( L_16 ) ;
return;
}
F_44 (port, intel_dsi->ports)
F_32 ( V_36 -> V_37 . V_38 , V_74 ) ;
V_55 = F_20 ( V_56 ) ;
V_55 |= V_57 ;
F_21 ( V_56 , V_55 ) ;
if ( F_16 ( F_20 ( V_56 ) & V_58 , 1 ) ) {
F_5 ( L_17 ) ;
return;
}
F_10 ( L_6 ) ;
}
void F_45 ( struct V_35 * V_36 )
{
struct V_79 * V_38 = V_36 -> V_37 . V_38 ;
if ( F_46 ( V_38 ) || F_6 ( V_38 ) )
F_12 ( V_36 ) ;
else if ( F_29 ( V_38 ) )
F_43 ( V_36 ) ;
}
void F_47 ( struct V_35 * V_36 )
{
struct V_79 * V_38 = V_36 -> V_37 . V_38 ;
if ( F_46 ( V_38 ) || F_6 ( V_38 ) )
F_18 ( V_36 ) ;
else if ( F_29 ( V_38 ) )
F_19 ( V_36 ) ;
}
static void F_48 ( struct V_35 * V_36 , enum V_74 V_74 )
{
T_1 V_50 ;
struct V_79 * V_38 = V_36 -> V_37 . V_38 ;
struct V_10 * V_11 = V_38 -> V_39 ;
V_50 = F_20 ( V_83 ) ;
V_50 &= ~ ( F_33 ( V_74 ) ) ;
V_50 &= ~ ( F_34 ( V_74 ) ) ;
V_50 &= ~ ( F_35 ( V_74 ) ) ;
V_50 &= ~ ( F_36 ( V_74 ) ) ;
F_21 ( V_83 , V_50 ) ;
F_21 ( F_49 ( V_74 ) , V_90 ) ;
}
void F_50 ( struct V_35 * V_36 , enum V_74 V_74 )
{
struct V_79 * V_38 = V_36 -> V_37 . V_38 ;
if ( F_29 ( V_38 ) )
F_48 ( V_36 , V_74 ) ;
else if ( F_46 ( V_38 ) || F_6 ( V_38 ) )
F_30 ( V_36 , V_74 ) ;
}
