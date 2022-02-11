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
unsigned int V_12 = 0 , V_13 = 0 ;
unsigned int V_14 , V_15 , V_16 = 2 , V_17 = 6 ;
unsigned int V_18 , V_19 , V_20 ;
int V_21 ;
int V_22 = V_11 ;
T_1 V_23 ;
if ( V_11 < 300000 || V_11 > 1150000 ) {
F_5 ( L_1 ) ;
return - V_24 ;
}
if ( F_6 ( V_8 ) ) {
V_21 = 100000 ;
V_19 = 4 ;
V_14 = 70 ;
V_15 = 96 ;
} else {
V_21 = 25000 ;
V_19 = 1 ;
V_14 = 62 ;
V_15 = 92 ;
}
for ( V_18 = V_14 ; V_18 <= V_15 && V_22 ; V_18 ++ ) {
for ( V_20 = V_16 ; V_20 <= V_17 && V_22 ; V_20 ++ ) {
int V_25 = ( V_18 * V_21 ) / ( V_20 * V_19 ) ;
int V_26 = abs ( V_11 - V_25 ) ;
if ( V_26 < V_22 ) {
V_22 = V_26 ;
V_12 = V_18 ;
V_13 = V_20 ;
}
}
}
V_19 = F_7 ( V_19 ) - 1 ;
V_23 = V_27 [ V_12 - 62 ] ;
V_10 -> V_28 . V_29 = 1 << ( V_30 + V_13 - 2 ) ;
V_10 -> V_28 . div = V_19 << V_31 |
V_23 << V_32 ;
return 0 ;
}
static int F_8 ( struct V_33 * V_34 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 = V_34 -> V_35 . V_36 -> V_37 ;
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
int V_39 ;
T_1 V_40 ;
V_40 = F_1 ( V_38 -> V_1 , V_38 -> V_41 ,
V_38 -> V_4 ) ;
V_39 = F_4 ( V_8 , V_10 , V_40 ) ;
if ( V_39 ) {
F_10 ( L_2 ) ;
return V_39 ;
}
if ( V_38 -> V_42 & ( 1 << V_43 ) )
V_10 -> V_28 . V_29 |= V_44 ;
if ( V_38 -> V_42 & ( 1 << V_45 ) )
V_10 -> V_28 . V_29 |= V_46 ;
V_10 -> V_28 . V_29 |= V_47 ;
F_10 ( L_3 ,
V_10 -> V_28 . div , V_10 -> V_28 . V_29 ) ;
return 0 ;
}
static void F_11 ( struct V_33 * V_34 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = F_12 ( V_34 -> V_35 . V_36 ) ;
F_10 ( L_4 ) ;
F_13 ( & V_8 -> V_48 ) ;
F_14 ( V_8 , V_49 , 0 ) ;
F_14 ( V_8 , V_50 , V_10 -> V_28 . div ) ;
F_14 ( V_8 , V_49 ,
V_10 -> V_28 . V_29 & ~ V_47 ) ;
F_15 ( 1 , 10 ) ;
F_14 ( V_8 , V_49 , V_10 -> V_28 . V_29 ) ;
if ( F_16 ( F_17 ( V_8 , V_49 ) &
V_51 , 20 ) ) {
F_18 ( & V_8 -> V_48 ) ;
F_5 ( L_5 ) ;
return;
}
F_18 ( & V_8 -> V_48 ) ;
F_10 ( L_6 ) ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = F_12 ( V_34 -> V_35 . V_36 ) ;
T_1 V_52 ;
F_10 ( L_4 ) ;
F_13 ( & V_8 -> V_48 ) ;
V_52 = F_17 ( V_8 , V_49 ) ;
V_52 &= ~ V_47 ;
V_52 |= V_53 ;
F_14 ( V_8 , V_49 , V_52 ) ;
F_18 ( & V_8 -> V_48 ) ;
}
static bool F_20 ( struct V_7 * V_8 )
{
bool V_54 ;
T_1 V_55 ;
T_1 V_56 ;
V_56 = V_57 | V_58 ;
V_55 = F_21 ( V_59 ) ;
V_54 = ( V_55 & V_56 ) == V_56 ;
if ( ! V_54 )
return false ;
V_55 = F_21 ( V_60 ) ;
if ( ! ( V_55 & V_61 ) || ! ( V_55 & V_62 ) ) {
F_22 ( L_7 ,
V_55 ) ;
V_54 = false ;
}
return V_54 ;
}
static void F_23 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = F_12 ( V_34 -> V_35 . V_36 ) ;
T_1 V_55 ;
F_10 ( L_4 ) ;
V_55 = F_21 ( V_59 ) ;
V_55 &= ~ V_57 ;
F_24 ( V_59 , V_55 ) ;
if ( F_16 ( ( F_21 ( V_59 )
& V_58 ) == 0 , 1 ) )
F_5 ( L_8 ) ;
}
static void F_25 ( enum V_2 V_3 , int V_63 )
{
int V_6 = F_2 ( V_3 ) ;
F_26 ( V_6 != V_63 ,
L_9 ,
V_6 , V_63 ) ;
}
static T_1 F_27 ( struct V_33 * V_34 , int V_63 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 = F_12 ( V_34 -> V_35 . V_36 ) ;
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
T_1 V_64 , V_1 ;
T_1 V_65 , V_66 ;
T_1 V_18 = 0 , V_20 = 0 , V_19 ;
int V_67 = F_6 ( V_8 ) ? 100000 : 25000 ;
int V_68 ;
F_10 ( L_4 ) ;
F_13 ( & V_8 -> V_48 ) ;
V_65 = F_17 ( V_8 , V_49 ) ;
V_66 = F_17 ( V_8 , V_50 ) ;
F_18 ( & V_8 -> V_48 ) ;
V_10 -> V_28 . V_29 = V_65 & ~ V_51 ;
V_10 -> V_28 . div = V_66 ;
V_65 &= V_69 ;
V_65 = V_65 >> ( V_30 - 2 ) ;
V_19 = ( V_66 & V_70 ) >> V_31 ;
V_19 = 1 << V_19 ;
V_66 &= V_71 ;
V_66 = V_66 >> V_32 ;
while ( V_65 ) {
V_65 = V_65 >> 1 ;
V_20 ++ ;
}
V_20 -- ;
if ( ! V_20 ) {
F_5 ( L_10 ) ;
return 0 ;
}
for ( V_68 = 0 ; V_68 < F_28 ( V_27 ) ; V_68 ++ ) {
if ( V_27 [ V_68 ] == V_66 )
break;
}
if ( V_68 == F_28 ( V_27 ) ) {
F_5 ( L_11 ) ;
return 0 ;
}
V_18 = V_68 + 62 ;
V_64 = ( V_18 * V_67 ) / ( V_20 * V_19 ) ;
F_25 ( V_38 -> V_41 , V_63 ) ;
V_1 = F_3 ( V_64 * V_38 -> V_4 , V_63 ) ;
return V_1 ;
}
static T_1 F_29 ( struct V_33 * V_34 , int V_63 ,
struct V_9 * V_10 )
{
T_1 V_1 ;
T_1 V_40 ;
T_1 V_72 ;
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
struct V_7 * V_8 = V_34 -> V_35 . V_36 -> V_37 ;
if ( ! V_63 ) {
F_5 ( L_12 ) ;
return 0 ;
}
V_10 -> V_28 . V_29 = F_21 ( V_60 ) ;
V_72 = V_10 -> V_28 . V_29 & V_73 ;
V_40 = ( V_72 * V_74 ) / 2 ;
F_25 ( V_38 -> V_41 , V_63 ) ;
V_1 = F_3 ( V_40 * V_38 -> V_4 , V_63 ) ;
F_22 ( L_13 , V_1 ) ;
return V_1 ;
}
T_1 F_30 ( struct V_33 * V_34 , int V_63 ,
struct V_9 * V_10 )
{
if ( F_31 ( V_34 -> V_35 . V_36 ) )
return F_29 ( V_34 , V_63 , V_10 ) ;
else
return F_27 ( V_34 , V_63 , V_10 ) ;
}
static void F_32 ( struct V_33 * V_34 , enum V_75 V_75 )
{
T_1 V_76 ;
struct V_7 * V_8 = V_34 -> V_35 . V_36 -> V_37 ;
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
V_76 = F_21 ( F_33 ( V_75 ) ) ;
V_76 &= ~ V_77 ;
F_24 ( F_33 ( V_75 ) , V_76 |
V_38 -> V_78 <<
V_79 ) ;
}
static void F_34 ( struct V_80 * V_36 , enum V_75 V_75 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = V_36 -> V_37 ;
T_1 V_52 ;
T_1 V_81 = 0 ;
T_1 V_82 = 0 ;
T_1 V_83 ;
T_1 V_84 ;
T_1 V_85 ;
T_1 V_86 ;
T_1 V_87 ;
V_52 = F_21 ( V_88 ) ;
V_52 &= ~ ( F_35 ( V_75 ) ) ;
V_52 &= ~ ( F_36 ( V_75 ) ) ;
V_52 &= ~ ( F_37 ( V_75 ) ) ;
V_52 &= ~ ( F_38 ( V_75 ) ) ;
V_82 = V_10 -> V_28 . V_29 & V_73 ;
V_81 = ( V_74 * V_82 ) / 2 ;
V_84 = F_39 ( V_81 , 20000 ) - 1 ;
V_83 = F_39 ( V_81 , 150000 ) - 1 ;
V_86 = V_83 & V_89 ;
V_85 = ( V_83 & V_90 ) >> 2 ;
if ( V_8 -> V_91 . V_92 . V_10 -> V_93 )
V_87 = 0x2 ;
else
V_87 = 0x3 ;
V_52 |= F_40 ( V_75 , V_87 ) ;
V_52 |= F_41 ( V_75 , V_84 ) ;
V_52 |= F_42 ( V_75 , V_86 ) ;
V_52 |= F_43 ( V_75 , V_85 ) ;
F_24 ( V_88 , V_52 ) ;
}
static int F_44 ( struct V_33 * V_34 ,
struct V_9 * V_10 )
{
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
T_2 V_72 ;
T_1 V_40 ;
V_40 = F_1 ( V_38 -> V_1 , V_38 -> V_41 ,
V_38 -> V_4 ) ;
V_72 = F_39 ( V_40 * 2 , V_74 ) ;
if ( V_72 < V_94 ||
V_72 > V_95 ) {
F_5 ( L_14 ) ;
return - V_24 ;
}
V_10 -> V_28 . V_29 = V_72 | V_96 | V_97 ;
if ( V_72 <= 50 )
V_10 -> V_28 . V_29 |= V_98 ;
return 0 ;
}
static void F_45 ( struct V_33 * V_34 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = V_34 -> V_35 . V_36 -> V_37 ;
struct V_38 * V_38 = F_9 ( & V_34 -> V_35 ) ;
enum V_75 V_75 ;
T_1 V_55 ;
F_10 ( L_4 ) ;
F_24 ( V_60 , V_10 -> V_28 . V_29 ) ;
F_46 ( V_60 ) ;
F_47 (port, intel_dsi->ports)
F_34 ( V_34 -> V_35 . V_36 , V_75 , V_10 ) ;
V_55 = F_21 ( V_59 ) ;
V_55 |= V_57 ;
F_24 ( V_59 , V_55 ) ;
if ( F_16 ( F_21 ( V_59 ) & V_58 , 1 ) ) {
F_5 ( L_15 ) ;
return;
}
F_10 ( L_6 ) ;
}
bool F_48 ( struct V_7 * V_8 )
{
if ( F_31 ( V_8 ) )
return F_20 ( V_8 ) ;
F_49 ( F_50 ( V_8 ) ) ;
return false ;
}
int F_51 ( struct V_33 * V_34 ,
struct V_9 * V_10 )
{
struct V_80 * V_36 = V_34 -> V_35 . V_36 ;
if ( F_52 ( V_36 ) || F_6 ( V_36 ) )
return F_8 ( V_34 , V_10 ) ;
else if ( F_31 ( V_36 ) )
return F_44 ( V_34 , V_10 ) ;
return - V_99 ;
}
void F_53 ( struct V_33 * V_34 ,
const struct V_9 * V_10 )
{
struct V_80 * V_36 = V_34 -> V_35 . V_36 ;
if ( F_52 ( V_36 ) || F_6 ( V_36 ) )
F_11 ( V_34 , V_10 ) ;
else if ( F_31 ( V_36 ) )
F_45 ( V_34 , V_10 ) ;
}
void F_54 ( struct V_33 * V_34 )
{
struct V_80 * V_36 = V_34 -> V_35 . V_36 ;
if ( F_52 ( V_36 ) || F_6 ( V_36 ) )
F_19 ( V_34 ) ;
else if ( F_31 ( V_36 ) )
F_23 ( V_34 ) ;
}
static void F_55 ( struct V_33 * V_34 , enum V_75 V_75 )
{
T_1 V_52 ;
struct V_80 * V_36 = V_34 -> V_35 . V_36 ;
struct V_7 * V_8 = V_36 -> V_37 ;
V_52 = F_21 ( V_88 ) ;
V_52 &= ~ ( F_35 ( V_75 ) ) ;
V_52 &= ~ ( F_36 ( V_75 ) ) ;
V_52 &= ~ ( F_37 ( V_75 ) ) ;
V_52 &= ~ ( F_38 ( V_75 ) ) ;
F_24 ( V_88 , V_52 ) ;
F_24 ( F_56 ( V_75 ) , V_100 ) ;
}
void F_57 ( struct V_33 * V_34 , enum V_75 V_75 )
{
struct V_80 * V_36 = V_34 -> V_35 . V_36 ;
if ( F_31 ( V_36 ) )
F_55 ( V_34 , V_75 ) ;
else if ( F_52 ( V_36 ) || F_6 ( V_36 ) )
F_32 ( V_34 , V_75 ) ;
}
