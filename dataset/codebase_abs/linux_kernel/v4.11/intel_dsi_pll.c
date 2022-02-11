static T_1 F_1 ( T_1 V_1 , enum V_2 V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 V_6 = F_2 ( V_3 ) ;
V_5 = F_3 ( V_1 * V_6 , V_4 ) ;
return V_5 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
unsigned int V_12 , V_13 , V_14 = 2 , V_15 = 6 ;
unsigned int V_16 , V_17 , V_18 ;
unsigned int V_19 , V_20 ;
int V_21 , V_22 ;
if ( V_11 < 300000 || V_11 > 1150000 ) {
F_5 ( L_1 ) ;
return - V_23 ;
}
if ( F_6 ( V_8 ) ) {
V_22 = 100000 ;
V_17 = 4 ;
V_12 = 70 ;
V_13 = 96 ;
} else {
V_22 = 25000 ;
V_17 = 1 ;
V_12 = 62 ;
V_13 = 92 ;
}
V_20 = V_14 ;
V_19 = V_12 ;
V_21 = abs ( V_11 - ( V_12 * V_22 ) / ( V_14 * V_17 ) ) ;
for ( V_16 = V_12 ; V_16 <= V_13 && V_21 ; V_16 ++ ) {
for ( V_18 = V_14 ; V_18 <= V_15 && V_21 ; V_18 ++ ) {
int V_24 = ( V_16 * V_22 ) / ( V_18 * V_17 ) ;
int V_25 = abs ( V_11 - V_24 ) ;
if ( V_25 < V_21 ) {
V_21 = V_25 ;
V_19 = V_16 ;
V_20 = V_18 ;
}
}
}
V_10 -> V_26 . V_27 = 1 << ( V_28 + V_20 - 2 ) ;
V_10 -> V_26 . div =
( F_7 ( V_17 ) - 1 ) << V_29 |
( T_1 ) V_30 [ V_19 - 62 ] << V_31 ;
return 0 ;
}
static int F_8 ( struct V_32 * V_33 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
int V_37 ;
T_1 V_38 ;
V_38 = F_1 ( V_36 -> V_1 , V_36 -> V_39 ,
V_36 -> V_4 ) ;
V_37 = F_4 ( V_8 , V_10 , V_38 ) ;
if ( V_37 ) {
F_11 ( L_2 ) ;
return V_37 ;
}
if ( V_36 -> V_40 & ( 1 << V_41 ) )
V_10 -> V_26 . V_27 |= V_42 ;
if ( V_36 -> V_40 & ( 1 << V_43 ) )
V_10 -> V_26 . V_27 |= V_44 ;
V_10 -> V_26 . V_27 |= V_45 ;
F_11 ( L_3 ,
V_10 -> V_26 . div , V_10 -> V_26 . V_27 ) ;
return 0 ;
}
static void F_12 ( struct V_32 * V_33 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
F_11 ( L_4 ) ;
F_13 ( & V_8 -> V_46 ) ;
F_14 ( V_8 , V_47 , 0 ) ;
F_14 ( V_8 , V_48 , V_10 -> V_26 . div ) ;
F_14 ( V_8 , V_47 ,
V_10 -> V_26 . V_27 & ~ V_45 ) ;
F_15 ( 10 , 50 ) ;
F_14 ( V_8 , V_47 , V_10 -> V_26 . V_27 ) ;
if ( F_16 ( F_17 ( V_8 , V_47 ) &
V_49 , 20 ) ) {
F_18 ( & V_8 -> V_46 ) ;
F_5 ( L_5 ) ;
return;
}
F_18 ( & V_8 -> V_46 ) ;
F_11 ( L_6 ) ;
}
static void F_19 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
T_1 V_50 ;
F_11 ( L_4 ) ;
F_13 ( & V_8 -> V_46 ) ;
V_50 = F_17 ( V_8 , V_47 ) ;
V_50 &= ~ V_45 ;
V_50 |= V_51 ;
F_14 ( V_8 , V_47 , V_50 ) ;
F_18 ( & V_8 -> V_46 ) ;
}
static bool F_20 ( struct V_7 * V_8 )
{
bool V_52 ;
T_1 V_53 ;
T_1 V_54 ;
V_54 = V_55 | V_56 ;
V_53 = F_21 ( V_57 ) ;
V_52 = ( V_53 & V_54 ) == V_54 ;
if ( ! V_52 )
return false ;
V_53 = F_21 ( V_58 ) ;
if ( ! ( V_53 & V_59 ) || ! ( V_53 & V_60 ) ) {
F_22 ( L_7 ,
V_53 ) ;
V_52 = false ;
}
return V_52 ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
T_1 V_53 ;
F_11 ( L_4 ) ;
V_53 = F_21 ( V_57 ) ;
V_53 &= ~ V_55 ;
F_24 ( V_57 , V_53 ) ;
if ( F_25 ( V_8 ,
V_57 ,
V_56 ,
0 ,
1 ) )
F_5 ( L_8 ) ;
}
static void F_26 ( enum V_2 V_3 , int V_61 )
{
int V_6 = F_2 ( V_3 ) ;
F_27 ( V_6 != V_61 ,
L_9 ,
V_6 , V_61 ) ;
}
static T_1 F_28 ( struct V_32 * V_33 , int V_61 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
T_1 V_62 , V_1 ;
T_1 V_63 , V_64 ;
T_1 V_16 = 0 , V_18 = 0 , V_17 ;
int V_65 = F_6 ( V_8 ) ? 100000 : 25000 ;
int V_66 ;
F_11 ( L_4 ) ;
F_13 ( & V_8 -> V_46 ) ;
V_63 = F_17 ( V_8 , V_47 ) ;
V_64 = F_17 ( V_8 , V_48 ) ;
F_18 ( & V_8 -> V_46 ) ;
V_10 -> V_26 . V_27 = V_63 & ~ V_49 ;
V_10 -> V_26 . div = V_64 ;
V_63 &= V_67 ;
V_63 = V_63 >> ( V_28 - 2 ) ;
V_17 = ( V_64 & V_68 ) >> V_29 ;
V_17 = 1 << V_17 ;
V_64 &= V_69 ;
V_64 = V_64 >> V_31 ;
while ( V_63 ) {
V_63 = V_63 >> 1 ;
V_18 ++ ;
}
V_18 -- ;
if ( ! V_18 ) {
F_5 ( L_10 ) ;
return 0 ;
}
for ( V_66 = 0 ; V_66 < F_29 ( V_30 ) ; V_66 ++ ) {
if ( V_30 [ V_66 ] == V_64 )
break;
}
if ( V_66 == F_29 ( V_30 ) ) {
F_5 ( L_11 ) ;
return 0 ;
}
V_16 = V_66 + 62 ;
V_62 = ( V_16 * V_65 ) / ( V_18 * V_17 ) ;
F_26 ( V_36 -> V_39 , V_61 ) ;
V_1 = F_3 ( V_62 * V_36 -> V_4 , V_61 ) ;
return V_1 ;
}
static T_1 F_30 ( struct V_32 * V_33 , int V_61 ,
struct V_9 * V_10 )
{
T_1 V_1 ;
T_1 V_38 ;
T_1 V_70 ;
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
if ( ! V_61 ) {
F_5 ( L_12 ) ;
return 0 ;
}
V_10 -> V_26 . V_27 = F_21 ( V_58 ) ;
V_70 = V_10 -> V_26 . V_27 & V_71 ;
V_38 = ( V_70 * V_72 ) / 2 ;
F_26 ( V_36 -> V_39 , V_61 ) ;
V_1 = F_3 ( V_38 * V_36 -> V_4 , V_61 ) ;
F_22 ( L_13 , V_1 ) ;
return V_1 ;
}
T_1 F_31 ( struct V_32 * V_33 , int V_61 ,
struct V_9 * V_10 )
{
if ( F_32 ( F_9 ( V_33 -> V_34 . V_35 ) ) )
return F_30 ( V_33 , V_61 , V_10 ) ;
else
return F_28 ( V_33 , V_61 , V_10 ) ;
}
static void F_33 ( struct V_32 * V_33 , enum V_73 V_73 )
{
T_1 V_74 ;
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
V_74 = F_21 ( F_34 ( V_73 ) ) ;
V_74 &= ~ V_75 ;
F_24 ( F_34 ( V_73 ) , V_74 |
V_36 -> V_76 <<
V_77 ) ;
}
static void F_35 ( struct V_78 * V_35 , enum V_73 V_73 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_35 ) ;
T_1 V_50 ;
T_1 V_79 = 0 ;
T_1 V_80 = 0 ;
T_1 V_81 ;
T_1 V_82 ;
T_1 V_83 ;
T_1 V_84 ;
T_1 V_85 ;
V_50 = F_21 ( V_86 ) ;
V_50 &= ~ ( F_36 ( V_73 ) ) ;
V_50 &= ~ ( F_37 ( V_73 ) ) ;
V_50 &= ~ ( F_38 ( V_73 ) ) ;
V_50 &= ~ ( F_39 ( V_73 ) ) ;
V_80 = V_10 -> V_26 . V_27 & V_71 ;
V_79 = ( V_72 * V_80 ) / 2 ;
V_82 = F_40 ( V_79 , 20000 ) - 1 ;
V_81 = F_40 ( V_79 , 150000 ) - 1 ;
V_84 = V_81 & V_87 ;
V_83 = ( V_81 & V_88 ) >> 2 ;
if ( V_8 -> V_89 . V_90 . V_10 -> V_91 )
V_85 = 0x2 ;
else
V_85 = 0x3 ;
V_50 |= F_41 ( V_73 , V_85 ) ;
V_50 |= F_42 ( V_73 , V_82 ) ;
V_50 |= F_43 ( V_73 , V_84 ) ;
V_50 |= F_44 ( V_73 , V_83 ) ;
F_24 ( V_86 , V_50 ) ;
}
static int F_45 ( struct V_32 * V_33 ,
struct V_9 * V_10 )
{
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
T_2 V_70 ;
T_1 V_38 ;
V_38 = F_1 ( V_36 -> V_1 , V_36 -> V_39 ,
V_36 -> V_4 ) ;
V_70 = F_40 ( V_38 * 2 , V_72 ) ;
if ( V_70 < V_92 ||
V_70 > V_93 ) {
F_5 ( L_14 ) ;
return - V_23 ;
}
V_10 -> V_26 . V_27 = V_70 | V_94 | V_95 ;
if ( V_70 <= 50 )
V_10 -> V_26 . V_27 |= V_96 ;
return 0 ;
}
static void F_46 ( struct V_32 * V_33 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
struct V_36 * V_36 = F_10 ( & V_33 -> V_34 ) ;
enum V_73 V_73 ;
T_1 V_53 ;
F_11 ( L_4 ) ;
F_24 ( V_58 , V_10 -> V_26 . V_27 ) ;
F_47 ( V_58 ) ;
F_48 (port, intel_dsi->ports)
F_35 ( V_33 -> V_34 . V_35 , V_73 , V_10 ) ;
V_53 = F_21 ( V_57 ) ;
V_53 |= V_55 ;
F_24 ( V_57 , V_53 ) ;
if ( F_25 ( V_8 ,
V_57 ,
V_56 ,
V_56 ,
1 ) ) {
F_5 ( L_15 ) ;
return;
}
F_11 ( L_6 ) ;
}
bool F_49 ( struct V_7 * V_8 )
{
if ( F_32 ( V_8 ) )
return F_20 ( V_8 ) ;
F_50 ( F_51 ( V_8 ) ) ;
return false ;
}
int F_52 ( struct V_32 * V_33 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
if ( F_53 ( V_8 ) || F_6 ( V_8 ) )
return F_8 ( V_33 , V_10 ) ;
else if ( F_32 ( V_8 ) )
return F_45 ( V_33 , V_10 ) ;
return - V_97 ;
}
void F_54 ( struct V_32 * V_33 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
if ( F_53 ( V_8 ) || F_6 ( V_8 ) )
F_12 ( V_33 , V_10 ) ;
else if ( F_32 ( V_8 ) )
F_46 ( V_33 , V_10 ) ;
}
void F_55 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
if ( F_53 ( V_8 ) || F_6 ( V_8 ) )
F_19 ( V_33 ) ;
else if ( F_32 ( V_8 ) )
F_23 ( V_33 ) ;
}
static void F_56 ( struct V_32 * V_33 , enum V_73 V_73 )
{
T_1 V_50 ;
struct V_78 * V_35 = V_33 -> V_34 . V_35 ;
struct V_7 * V_8 = F_9 ( V_35 ) ;
V_50 = F_21 ( V_86 ) ;
V_50 &= ~ ( F_36 ( V_73 ) ) ;
V_50 &= ~ ( F_37 ( V_73 ) ) ;
V_50 &= ~ ( F_38 ( V_73 ) ) ;
V_50 &= ~ ( F_39 ( V_73 ) ) ;
F_24 ( V_86 , V_50 ) ;
F_24 ( F_57 ( V_73 ) , V_98 ) ;
}
void F_58 ( struct V_32 * V_33 , enum V_73 V_73 )
{
struct V_7 * V_8 = F_9 ( V_33 -> V_34 . V_35 ) ;
if ( F_32 ( V_8 ) )
F_56 ( V_33 , V_73 ) ;
else if ( F_53 ( V_8 ) || F_6 ( V_8 ) )
F_33 ( V_33 , V_73 ) ;
}
