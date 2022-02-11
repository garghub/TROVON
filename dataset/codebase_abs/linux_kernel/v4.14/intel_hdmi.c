static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 ) -> V_3 . V_3 . V_4 ;
}
static void
F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_1 V_7 ;
V_7 = F_5 ( V_6 ) ? V_8 : V_9 ;
F_6 ( F_7 ( V_2 -> V_10 ) & V_7 ,
L_1 ) ;
}
struct V_2 * F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 =
F_9 ( V_12 , struct V_13 , V_3 . V_3 ) ;
return & V_14 -> V_15 ;
}
static struct V_2 * F_10 ( struct V_16 * V_17 )
{
return F_8 ( & F_11 ( V_17 ) -> V_3 ) ;
}
static T_2 F_12 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_2 F_14 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_25 ;
case V_21 :
return V_26 ;
case V_23 :
return V_27 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_2 F_15 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_28 ;
case V_21 :
return V_29 ;
case V_23 :
return V_30 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_3
F_16 ( struct V_5 * V_6 ,
enum V_31 V_32 ,
enum V_18 type ,
int V_33 )
{
switch ( type ) {
case V_19 :
return F_17 ( V_32 , V_33 ) ;
case V_21 :
return F_18 ( V_32 , V_33 ) ;
case V_23 :
return F_19 ( V_32 , V_33 ) ;
default:
F_13 ( type ) ;
return V_34 ;
}
}
static void F_20 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_40 = F_7 ( V_41 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_41 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( V_44 , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( V_44 , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_41 , V_40 ) ;
F_23 ( V_41 ) ;
}
static bool F_24 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
T_2 V_40 = F_7 ( V_41 ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_26 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_30 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_31 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_3 V_53 = F_29 ( V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_32 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
if ( type != V_19 )
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_30 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_33 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_40 = F_7 ( F_29 ( V_54 ) ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_34 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_36 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_36 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_37 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_40 = F_7 ( F_35 ( V_54 ) ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_38 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_31 V_32 = V_36 -> V_32 ;
T_3 V_57 = F_39 ( V_32 ) ;
T_3 V_58 ;
int V_33 ;
T_2 V_40 = F_7 ( V_57 ) ;
V_58 = F_16 ( V_6 , V_32 , type , 0 ) ;
V_40 &= ~ F_15 ( type ) ;
F_21 ( V_57 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , 0 ) ;
F_22 () ;
V_40 |= F_15 ( type ) ;
F_21 ( V_57 , V_40 ) ;
F_23 ( V_57 ) ;
}
static bool F_40 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
T_2 V_40 = F_7 ( F_39 ( V_48 -> V_32 ) ) ;
return V_40 & ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
union V_62 * V_37 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_5 V_63 [ V_45 ] ;
T_4 V_38 ;
V_38 = F_42 ( V_37 , V_63 + 1 , sizeof( V_63 ) - 1 ) ;
if ( V_38 < 0 )
return;
V_63 [ 0 ] = V_63 [ 1 ] ;
V_63 [ 1 ] = V_63 [ 2 ] ;
V_63 [ 2 ] = V_63 [ 3 ] ;
V_63 [ 3 ] = 0 ;
V_38 ++ ;
V_2 -> V_64 ( V_12 , V_36 , V_37 -> V_65 . type , V_63 , V_38 ) ;
}
static void F_43 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
const struct V_66 * V_67 =
& V_36 -> V_3 . V_67 ;
struct V_16 * V_17 = & V_2 -> V_68 -> V_3 ;
bool V_69 = V_17 -> V_70 . V_15 . V_71 . V_72 ;
union V_62 V_37 ;
int V_73 ;
V_73 = F_44 ( & V_37 . V_74 ,
V_67 ,
V_69 ) ;
if ( V_73 < 0 ) {
F_45 ( L_3 ) ;
return;
}
if ( V_36 -> V_75 )
V_37 . V_74 . V_76 = V_77 ;
else
V_37 . V_74 . V_76 = V_78 ;
F_46 ( & V_37 . V_74 , V_67 ,
V_36 -> V_79 ?
V_80 :
V_81 ,
V_2 -> V_82 ) ;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
union V_62 V_37 ;
int V_73 ;
V_73 = F_48 ( & V_37 . V_83 , L_4 , L_5 ) ;
if ( V_73 < 0 ) {
F_45 ( L_6 ) ;
return;
}
V_37 . V_83 . V_84 = V_85 ;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void
F_49 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
union V_62 V_37 ;
int V_73 ;
V_73 = F_50 ( & V_37 . V_86 . V_15 ,
& V_36 -> V_3 . V_67 ) ;
if ( V_73 < 0 )
return;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void F_51 ( struct V_11 * V_12 ,
bool V_87 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_53 = V_41 ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_87 ) {
if ( ! ( V_40 & V_42 ) )
return;
if ( V_50 != ( V_40 & V_49 ) ) {
F_52 ( L_7 ,
( V_40 & V_49 ) >> 29 ) ;
return;
}
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_26 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
if ( V_40 & V_42 ) {
F_52 ( L_8 ,
( V_40 & V_49 ) >> 29 ) ;
return;
}
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_26 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static bool F_53 ( const struct V_88 * V_89 )
{
struct V_16 * V_17 = V_89 -> V_17 ;
return V_17 -> V_70 . V_90 > 8 ;
}
static bool F_54 ( int V_91 ,
const struct V_66 * V_92 )
{
unsigned int V_93 ;
switch ( V_91 ) {
case 30 :
V_93 = 4 ;
break;
case 36 :
V_93 = 2 ;
break;
case 48 :
V_93 = 1 ;
break;
default:
return false ;
}
return V_92 -> V_94 % V_93 == 0 &&
V_92 -> V_95 % V_93 == 0 &&
V_92 -> V_96 % V_93 == 0 &&
V_92 -> V_97 % V_93 == 0 &&
V_92 -> V_98 % V_93 == 0 &&
V_92 -> V_99 % V_93 == 0 &&
( ( V_92 -> V_100 & V_101 ) == 0 ||
V_92 -> V_95 / 2 % V_93 == 0 ) ;
}
static bool F_55 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_52 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 ;
T_2 V_40 = 0 ;
if ( F_5 ( V_6 ) )
V_53 = F_56 ( V_36 -> V_32 ) ;
else if ( F_57 ( V_6 ) || F_58 ( V_6 ) )
V_53 = F_59 ( V_52 -> V_54 ) ;
else if ( F_60 ( V_6 ) )
V_53 = F_61 ( V_52 -> V_54 ) ;
else
return false ;
if ( F_53 ( V_89 ) )
V_40 |= V_102 ;
if ( F_54 ( V_36 -> V_91 ,
& V_36 -> V_3 . V_67 ) )
V_40 |= V_103 ;
F_21 ( V_53 , V_40 ) ;
return V_40 != 0 ;
}
static void F_62 ( struct V_11 * V_12 ,
bool V_87 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_87 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
F_6 ( V_40 & V_42 ,
L_9 ,
( V_40 & V_49 ) >> 29 ) ;
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_89 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_63 ( struct V_11 * V_12 ,
bool V_87 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_87 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
V_40 |= V_42 | V_25 ;
V_40 &= ~ ( V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_89 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_64 ( struct V_11 * V_12 ,
bool V_87 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_87 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
F_6 ( V_40 & V_42 ,
L_9 ,
( V_40 & V_49 ) >> 29 ) ;
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_89 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_65 ( struct V_11 * V_12 ,
bool V_87 ,
const struct V_35 * V_36 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_39 ( V_36 -> V_32 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
F_3 ( V_2 ) ;
V_40 &= ~ ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
if ( ! V_87 ) {
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( F_55 ( V_12 , V_36 , V_89 ) )
V_40 |= V_60 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
void F_66 ( struct V_2 * V_15 , bool V_87 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
struct V_104 * V_105 =
F_67 ( V_6 , V_15 -> V_106 ) ;
if ( V_15 -> V_107 . type < V_108 )
return;
F_52 ( L_10 ,
V_87 ? L_11 : L_12 ) ;
F_68 ( V_15 -> V_107 . type ,
V_105 , V_87 ) ;
}
static void F_69 ( struct V_109 * V_12 ,
const struct V_35 * V_36 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_52 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
const struct V_66 * V_67 = & V_36 -> V_3 . V_67 ;
T_2 V_110 ;
F_66 ( V_2 , true ) ;
V_110 = V_111 ;
if ( ! F_60 ( V_6 ) && V_36 -> V_79 )
V_110 |= V_112 ;
if ( V_67 -> V_100 & V_113 )
V_110 |= V_114 ;
if ( V_67 -> V_100 & V_115 )
V_110 |= V_116 ;
if ( V_36 -> V_91 > 24 )
V_110 |= V_117 ;
else
V_110 |= V_118 ;
if ( V_36 -> V_119 )
V_110 |= V_120 ;
if ( F_70 ( V_6 ) )
V_110 |= F_71 ( V_52 -> V_54 ) ;
else if ( F_58 ( V_6 ) )
V_110 |= F_72 ( V_52 -> V_54 ) ;
else
V_110 |= F_73 ( V_52 -> V_54 ) ;
F_21 ( V_2 -> V_10 , V_110 ) ;
F_23 ( V_2 -> V_10 ) ;
}
static bool F_74 ( struct V_109 * V_12 ,
enum V_54 * V_54 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_121 ;
bool V_73 ;
if ( ! F_75 ( V_6 ,
V_12 -> V_122 ) )
return false ;
V_73 = false ;
V_121 = F_7 ( V_2 -> V_10 ) ;
if ( ! ( V_121 & V_9 ) )
goto V_123;
if ( F_70 ( V_6 ) )
* V_54 = F_76 ( V_121 ) ;
else if ( F_58 ( V_6 ) )
* V_54 = F_77 ( V_121 ) ;
else
* V_54 = F_78 ( V_121 ) ;
V_73 = true ;
V_123:
F_79 ( V_6 , V_12 -> V_122 ) ;
return V_73 ;
}
static void F_80 ( struct V_109 * V_12 ,
struct V_35 * V_48 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_121 , V_100 = 0 ;
int V_124 ;
V_121 = F_7 ( V_2 -> V_10 ) ;
if ( V_121 & V_116 )
V_100 |= V_115 ;
else
V_100 |= V_125 ;
if ( V_121 & V_114 )
V_100 |= V_113 ;
else
V_100 |= V_126 ;
if ( V_121 & V_120 )
V_48 -> V_119 = true ;
if ( V_2 -> V_127 ( & V_12 -> V_3 , V_48 ) )
V_48 -> V_128 = true ;
if ( V_121 & V_129 )
V_48 -> V_130 = true ;
if ( ! F_60 ( V_6 ) &&
V_121 & V_112 )
V_48 -> V_79 = true ;
V_48 -> V_3 . V_67 . V_100 |= V_100 ;
if ( ( V_121 & V_131 ) == V_117 )
V_124 = V_48 -> V_132 * 2 / 3 ;
else
V_124 = V_48 -> V_132 ;
if ( V_48 -> V_133 )
V_124 /= V_48 -> V_133 ;
V_48 -> V_3 . V_67 . V_134 = V_124 ;
V_48 -> V_135 = 4 ;
}
static void F_81 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
F_82 ( ! V_48 -> V_119 ) ;
F_83 ( L_13 ,
F_84 ( V_52 -> V_54 ) ) ;
F_85 ( V_12 , V_48 , V_89 ) ;
}
static void F_86 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_136 ;
V_136 = F_7 ( V_2 -> V_10 ) ;
V_136 |= V_9 ;
if ( V_48 -> V_130 )
V_136 |= V_129 ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_130 )
F_81 ( V_12 , V_48 , V_89 ) ;
}
static void F_87 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_136 ;
V_136 = F_7 ( V_2 -> V_10 ) ;
V_136 |= V_9 ;
if ( V_48 -> V_130 )
V_136 |= V_129 ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_91 > 24 &&
V_48 -> V_133 > 1 ) {
F_21 ( V_2 -> V_10 , V_136 & ~ V_9 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
}
if ( V_48 -> V_130 )
F_81 ( V_12 , V_48 , V_89 ) ;
}
static void F_88 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_136 ;
V_136 = F_7 ( V_2 -> V_10 ) ;
V_136 |= V_9 ;
if ( V_48 -> V_130 )
V_136 |= V_129 ;
if ( V_48 -> V_91 > 24 ) {
F_21 ( F_89 ( V_54 ) ,
F_7 ( F_89 ( V_54 ) ) |
V_137 ) ;
V_136 &= ~ V_131 ;
V_136 |= V_118 ;
}
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_91 > 24 ) {
V_136 &= ~ V_131 ;
V_136 |= V_117 ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( F_89 ( V_54 ) ,
F_7 ( F_89 ( V_54 ) ) &
~ V_137 ) ;
}
if ( V_48 -> V_130 )
F_81 ( V_12 , V_48 , V_89 ) ;
}
static void F_90 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
}
static void F_91 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_138 -> V_3 . V_52 ) ;
T_2 V_136 ;
V_136 = F_7 ( V_2 -> V_10 ) ;
V_136 &= ~ ( V_9 | V_129 ) ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( F_92 ( V_6 ) && V_52 -> V_54 == V_140 ) {
F_93 ( V_6 , V_141 , false ) ;
F_94 ( V_6 , V_141 , false ) ;
V_136 &= ~ V_142 ;
V_136 |= V_9 ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
V_136 &= ~ V_9 ;
F_21 ( V_2 -> V_10 , V_136 ) ;
F_23 ( V_2 -> V_10 ) ;
F_95 ( V_6 , V_141 ) ;
F_93 ( V_6 , V_141 , true ) ;
F_94 ( V_6 , V_141 , true ) ;
}
V_2 -> V_143 ( & V_12 -> V_3 , false , V_138 , V_139 ) ;
F_66 ( V_2 , false ) ;
}
static void F_96 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
if ( V_138 -> V_130 )
F_97 ( V_12 ) ;
F_91 ( V_12 , V_138 , V_139 ) ;
}
static void F_98 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
if ( V_138 -> V_130 )
F_97 ( V_12 ) ;
}
static void F_99 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
F_91 ( V_12 , V_138 , V_139 ) ;
}
static int F_100 ( struct V_5 * V_6 )
{
if ( F_101 ( V_6 ) )
return 165000 ;
else if ( F_102 ( V_6 ) )
return 594000 ;
else if ( F_103 ( V_6 ) || F_104 ( V_6 ) -> V_144 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_105 ( struct V_2 * V_15 ,
bool V_145 ,
bool V_146 )
{
struct V_1 * V_4 = F_1 ( V_15 ) ;
int V_147 = F_100 ( F_4 ( V_4 ) ) ;
if ( V_145 ) {
struct V_148 * V_17 = V_15 -> V_68 ;
const struct V_149 * V_150 = & V_17 -> V_3 . V_70 ;
if ( V_15 -> V_107 . V_147 )
V_147 = F_106 ( V_147 ,
V_15 -> V_107 . V_147 ) ;
if ( V_150 -> V_147 )
V_147 = F_106 ( V_147 ,
V_150 -> V_147 ) ;
else if ( ! V_15 -> V_119 || V_146 )
V_147 = F_106 ( V_147 , 165000 ) ;
}
return V_147 ;
}
static enum V_151
F_107 ( struct V_2 * V_15 ,
int clock , bool V_145 ,
bool V_146 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
if ( clock < 25000 )
return V_152 ;
if ( clock > F_105 ( V_15 , V_145 , V_146 ) )
return V_153 ;
if ( F_108 ( V_6 ) && clock > 223333 && clock < 240000 )
return V_154 ;
if ( F_58 ( V_6 ) && clock > 216000 && clock < 240000 )
return V_154 ;
return V_155 ;
}
static enum V_151
F_109 ( struct V_16 * V_17 ,
struct V_66 * V_92 )
{
struct V_2 * V_15 = F_10 ( V_17 ) ;
struct V_1 * V_4 = F_1 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_151 V_156 ;
int clock ;
int V_157 = F_4 ( V_17 -> V_4 ) -> V_158 ;
bool V_146 =
F_110 ( F_111 ( V_17 -> V_159 ) -> V_160 ) == V_161 ;
if ( V_92 -> V_100 & V_162 )
return V_163 ;
clock = V_92 -> clock ;
if ( ( V_92 -> V_100 & V_164 ) == V_165 )
clock *= 2 ;
if ( clock > V_157 )
return V_153 ;
if ( V_92 -> V_100 & V_166 )
clock *= 2 ;
if ( F_112 ( & V_17 -> V_70 , V_92 ) )
clock /= 2 ;
V_156 = F_107 ( V_15 , clock , true , V_146 ) ;
if ( ! F_113 ( V_6 ) && V_156 != V_155 && V_15 -> V_119 && ! V_146 )
V_156 = F_107 ( V_15 , clock * 3 / 2 , true , V_146 ) ;
return V_156 ;
}
static bool F_114 ( struct V_35 * V_36 )
{
struct V_5 * V_6 =
F_4 ( V_36 -> V_3 . V_52 -> V_4 ) ;
struct V_167 * V_159 = V_36 -> V_3 . V_159 ;
struct V_88 * V_168 ;
struct V_16 * V_17 ;
int V_33 ;
if ( F_113 ( V_6 ) )
return false ;
if ( V_36 -> V_169 != 1 << V_170 )
return false ;
F_115 (state, connector, connector_state, i) {
const struct V_149 * V_150 = & V_17 -> V_70 ;
if ( V_168 -> V_52 != V_36 -> V_3 . V_52 )
continue;
if ( V_36 -> V_75 ) {
const struct V_171 * V_15 = & V_150 -> V_15 ;
if ( ! ( V_15 -> V_172 & V_173 ) )
return false ;
} else {
if ( ! ( V_150 -> V_174 & V_175 ) )
return false ;
}
}
if ( F_116 ( V_6 , 0 , V_176 ) &&
V_36 -> V_3 . V_67 . V_177 > 5460 )
return false ;
return true ;
}
static bool
F_117 ( struct V_16 * V_17 ,
struct V_35 * V_178 ,
int * V_179 , int * V_180 )
{
struct V_51 * V_51 = F_28 ( V_178 -> V_3 . V_52 ) ;
if ( ! V_17 -> V_181 ) {
F_45 ( L_14 ) ;
return false ;
}
V_178 -> V_132 /= 2 ;
* V_179 /= 2 ;
* V_180 /= 2 ;
V_178 -> V_75 = true ;
if ( F_118 ( V_178 ) ) {
F_52 ( L_15 ) ;
return false ;
}
F_119 ( V_51 , V_178 ,
V_182 ) ;
return true ;
}
bool F_120 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_5 * V_6 = F_4 ( V_12 -> V_3 . V_4 ) ;
struct V_66 * V_67 = & V_48 -> V_3 . V_67 ;
struct V_16 * V_17 = V_89 -> V_17 ;
struct V_183 * V_71 = & V_17 -> V_70 . V_15 . V_71 ;
struct V_184 * V_185 =
F_111 ( V_89 ) ;
int V_180 = V_48 -> V_3 . V_67 . V_134 ;
int V_179 = V_180 * 3 / 2 ;
int V_186 ;
bool V_146 = V_185 -> V_160 == V_161 ;
V_48 -> V_119 = ! V_146 && V_2 -> V_119 ;
if ( V_48 -> V_119 )
V_48 -> V_128 = true ;
if ( V_185 -> V_187 == V_188 ) {
V_48 -> V_79 =
V_48 -> V_119 &&
F_121 ( V_67 ) ==
V_80 ;
} else {
V_48 -> V_79 =
V_185 -> V_187 == V_189 ;
}
if ( V_67 -> V_100 & V_166 ) {
V_48 -> V_133 = 2 ;
V_180 *= 2 ;
V_179 *= 2 ;
}
if ( F_112 ( & V_17 -> V_70 , V_67 ) ) {
if ( ! F_117 ( V_17 , V_48 ,
& V_179 , & V_180 ) ) {
F_45 ( L_16 ) ;
return false ;
}
}
if ( F_60 ( V_6 ) && ! F_5 ( V_6 ) )
V_48 -> V_190 = true ;
if ( V_48 -> V_119 ) {
if ( V_185 -> V_160 == V_191 )
V_48 -> V_130 = V_2 -> V_130 ;
else
V_48 -> V_130 =
V_185 -> V_160 == V_192 ;
}
if ( V_48 -> V_91 > 8 * 3 && V_48 -> V_119 && ! V_146 &&
F_107 ( V_2 , V_179 , true , V_146 ) == V_155 &&
F_114 ( V_48 ) ) {
F_52 ( L_17 ) ;
V_186 = 12 * 3 ;
V_48 -> V_132 = V_179 ;
} else {
F_52 ( L_18 ) ;
V_186 = 8 * 3 ;
V_48 -> V_132 = V_180 ;
}
if ( ! V_48 -> V_193 ) {
F_52 ( L_19 , V_186 ) ;
V_48 -> V_91 = V_186 ;
}
if ( F_107 ( V_2 , V_48 -> V_132 ,
false , V_146 ) != V_155 ) {
F_52 ( L_20 ) ;
return false ;
}
V_67 -> V_194 = V_89 -> V_194 ;
V_48 -> V_135 = 4 ;
if ( V_71 -> V_195 . V_72 && F_102 ( V_6 ) ) {
if ( V_71 -> V_195 . V_196 )
V_48 -> V_197 = true ;
if ( V_48 -> V_132 > 340000 ) {
V_48 -> V_197 = true ;
V_48 -> V_198 = true ;
}
}
return true ;
}
static void
F_122 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
V_2 -> V_119 = false ;
V_2 -> V_130 = false ;
V_2 -> V_82 = false ;
V_2 -> V_107 . type = V_199 ;
V_2 -> V_107 . V_147 = 0 ;
F_123 ( F_124 ( V_17 ) -> V_200 ) ;
F_124 ( V_17 ) -> V_200 = NULL ;
}
static void
F_125 ( struct V_16 * V_17 , bool V_201 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_15 = F_10 ( V_17 ) ;
enum V_50 V_50 = F_2 ( V_15 ) -> V_50 ;
struct V_104 * V_105 =
F_67 ( V_6 , V_15 -> V_106 ) ;
enum V_202 type = F_126 ( V_105 ) ;
if ( type == V_203 ) {
if ( V_201 &&
F_127 ( V_6 , V_50 ) ) {
F_52 ( L_21 ) ;
type = V_204 ;
} else {
type = V_199 ;
}
}
if ( type == V_199 )
return;
V_15 -> V_107 . type = type ;
V_15 -> V_107 . V_147 =
F_128 ( type , V_105 ) ;
F_52 ( L_22 ,
F_129 ( type ) ,
V_15 -> V_107 . V_147 ) ;
}
static bool
F_130 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_205 * V_205 ;
bool V_206 = false ;
F_131 ( V_6 , V_207 ) ;
V_205 = F_132 ( V_17 ,
F_67 ( V_6 ,
V_2 -> V_106 ) ) ;
F_125 ( V_17 , V_205 != NULL ) ;
F_79 ( V_6 , V_207 ) ;
F_124 ( V_17 ) -> V_200 = V_205 ;
if ( V_205 && V_205 -> V_208 & V_209 ) {
V_2 -> V_82 =
F_133 ( V_205 ) ;
V_2 -> V_130 = F_134 ( V_205 ) ;
V_2 -> V_119 = F_135 ( V_205 ) ;
V_206 = true ;
}
return V_206 ;
}
static enum V_210
F_136 ( struct V_16 * V_17 , bool V_211 )
{
enum V_210 V_156 ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
F_52 ( L_23 ,
V_17 -> V_3 . V_212 , V_17 -> V_213 ) ;
F_131 ( V_6 , V_207 ) ;
F_122 ( V_17 ) ;
if ( F_130 ( V_17 ) ) {
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_170 ;
V_156 = V_214 ;
} else
V_156 = V_215 ;
F_79 ( V_6 , V_207 ) ;
return V_156 ;
}
static void
F_137 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_52 ( L_23 ,
V_17 -> V_3 . V_212 , V_17 -> V_213 ) ;
F_122 ( V_17 ) ;
if ( V_17 -> V_156 != V_214 )
return;
F_130 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_170 ;
}
static int F_138 ( struct V_16 * V_17 )
{
struct V_205 * V_205 ;
V_205 = F_124 ( V_17 ) -> V_200 ;
if ( V_205 == NULL )
return 0 ;
return F_139 ( V_17 , V_205 ) ;
}
static void F_140 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
F_69 ( V_12 , V_48 ) ;
V_2 -> V_143 ( & V_12 -> V_3 ,
V_48 -> V_119 ,
V_48 , V_89 ) ;
}
static void F_141 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_13 * V_216 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_216 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_142 ( V_12 ) ;
F_143 ( V_12 , 0x2b245f5f , 0x00002000 , 0x5578b83a ,
0x2b247878 ) ;
V_2 -> V_143 ( & V_12 -> V_3 ,
V_48 -> V_119 ,
V_48 , V_89 ) ;
F_86 ( V_12 , V_48 , V_89 ) ;
F_144 ( V_6 , V_216 , 0x0 ) ;
}
static void F_145 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
F_69 ( V_12 , V_48 ) ;
F_146 ( V_12 ) ;
}
static void F_147 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
F_69 ( V_12 , V_48 ) ;
F_148 ( V_12 ) ;
}
static void F_149 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
F_150 ( V_12 ) ;
}
static void F_151 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
F_152 ( V_12 ) ;
}
static void F_153 ( struct V_109 * V_12 ,
struct V_35 * V_138 ,
struct V_88 * V_139 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_154 ( & V_6 -> V_217 ) ;
F_155 ( V_12 , true ) ;
F_156 ( & V_6 -> V_217 ) ;
}
static void F_157 ( struct V_109 * V_12 ,
struct V_35 * V_48 ,
struct V_88 * V_89 )
{
struct V_13 * V_216 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_216 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_158 ( V_12 ) ;
F_159 ( V_12 , 128 , 102 , false ) ;
V_2 -> V_143 ( & V_12 -> V_3 ,
V_48 -> V_119 ,
V_48 , V_89 ) ;
F_86 ( V_12 , V_48 , V_89 ) ;
F_144 ( V_6 , V_216 , 0x0 ) ;
F_160 ( V_12 ) ;
}
static void F_161 ( struct V_16 * V_17 )
{
F_123 ( F_124 ( V_17 ) -> V_200 ) ;
F_162 ( V_17 ) ;
F_123 ( V_17 ) ;
}
static void
F_163 ( struct V_2 * V_2 , struct V_16 * V_17 )
{
F_164 ( V_17 ) ;
F_165 ( V_17 ) ;
F_166 ( V_17 ) ;
V_17 -> V_159 -> V_194 = V_218 ;
}
void F_167 ( struct V_109 * V_12 ,
struct V_16 * V_17 ,
bool V_219 ,
bool V_195 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_5 * V_6 = V_17 -> V_4 -> V_220 ;
struct V_221 * V_222 =
& V_17 -> V_70 . V_15 . V_71 . V_195 ;
struct V_104 * V_223 = F_67 ( V_6 ,
V_2 -> V_106 ) ;
bool V_73 ;
if ( ! V_222 -> V_72 )
return;
F_52 ( L_24 ,
V_12 -> V_3 . V_213 , V_17 -> V_213 ) ;
V_73 = F_168 ( V_223 , V_219 ) ;
if ( ! V_73 ) {
F_45 ( L_25 ) ;
return;
}
V_73 = F_169 ( V_223 , V_195 ) ;
if ( ! V_73 ) {
F_45 ( L_26 ) ;
return;
}
F_52 ( L_27 ) ;
}
static T_6 F_170 ( struct V_5 * V_6 , enum V_50 V_50 )
{
T_6 V_224 ;
switch ( V_50 ) {
case V_225 :
V_224 = V_226 ;
break;
case V_227 :
V_224 = V_228 ;
break;
case V_229 :
V_224 = V_230 ;
break;
default:
F_13 ( V_50 ) ;
V_224 = V_226 ;
break;
}
return V_224 ;
}
static T_6 F_171 ( struct V_5 * V_6 , enum V_50 V_50 )
{
T_6 V_224 ;
switch ( V_50 ) {
case V_225 :
V_224 = V_231 ;
break;
case V_227 :
V_224 = V_232 ;
break;
default:
F_13 ( V_50 ) ;
V_224 = V_231 ;
break;
}
return V_224 ;
}
static T_6 F_172 ( struct V_5 * V_6 ,
enum V_50 V_50 )
{
T_6 V_224 ;
switch ( V_50 ) {
case V_225 :
V_224 = V_231 ;
break;
case V_227 :
V_224 = V_232 ;
break;
case V_229 :
V_224 = V_233 ;
break;
default:
F_13 ( V_50 ) ;
V_224 = V_231 ;
break;
}
return V_224 ;
}
static T_6 F_173 ( struct V_5 * V_6 ,
enum V_50 V_50 )
{
T_6 V_224 ;
switch ( V_50 ) {
case V_225 :
V_224 = V_226 ;
break;
case V_227 :
V_224 = V_228 ;
break;
case V_229 :
V_224 = V_234 ;
break;
default:
F_13 ( V_50 ) ;
V_224 = V_226 ;
break;
}
return V_224 ;
}
static T_6 F_174 ( struct V_5 * V_6 ,
enum V_50 V_50 )
{
const struct V_235 * V_150 =
& V_6 -> V_236 . V_237 [ V_50 ] ;
T_6 V_224 ;
if ( V_150 -> V_238 ) {
F_52 ( L_28 ,
V_150 -> V_238 , F_175 ( V_50 ) ) ;
return V_150 -> V_238 ;
}
if ( F_58 ( V_6 ) )
V_224 = F_170 ( V_6 , V_50 ) ;
else if ( F_108 ( V_6 ) )
V_224 = F_171 ( V_6 , V_50 ) ;
else if ( F_176 ( V_6 ) )
V_224 = F_172 ( V_6 , V_50 ) ;
else
V_224 = F_173 ( V_6 , V_50 ) ;
F_52 ( L_29 ,
V_224 , F_175 ( V_50 ) ) ;
return V_224 ;
}
void F_177 ( struct V_13 * V_14 ,
struct V_148 * V_148 )
{
struct V_16 * V_17 = & V_148 -> V_3 ;
struct V_2 * V_2 = & V_14 -> V_15 ;
struct V_109 * V_109 = & V_14 -> V_3 ;
struct V_1 * V_4 = V_109 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_50 V_50 = V_14 -> V_50 ;
F_52 ( L_30 ,
F_175 ( V_50 ) ) ;
if ( F_6 ( V_14 -> V_239 < 4 ,
L_31 ,
V_14 -> V_239 , F_175 ( V_50 ) ) )
return;
F_178 ( V_4 , V_17 , & V_240 ,
V_241 ) ;
F_179 ( V_17 , & V_242 ) ;
V_17 -> V_243 = 1 ;
V_17 -> V_244 = 0 ;
V_17 -> V_245 = 1 ;
if ( F_102 ( V_6 ) )
V_17 -> V_181 = true ;
V_2 -> V_106 = F_174 ( V_6 , V_50 ) ;
if ( F_82 ( V_50 == V_246 ) )
return;
V_109 -> V_247 = F_180 ( V_50 ) ;
if ( F_57 ( V_6 ) || F_58 ( V_6 ) ) {
V_2 -> V_64 = F_34 ;
V_2 -> V_143 = F_64 ;
V_2 -> V_127 = F_37 ;
} else if ( F_101 ( V_6 ) ) {
V_2 -> V_64 = F_20 ;
V_2 -> V_143 = F_51 ;
V_2 -> V_127 = F_24 ;
} else if ( F_5 ( V_6 ) ) {
V_2 -> V_64 = F_38 ;
V_2 -> V_143 = F_65 ;
V_2 -> V_127 = F_40 ;
} else if ( F_92 ( V_6 ) ) {
V_2 -> V_64 = F_27 ;
V_2 -> V_143 = F_62 ;
V_2 -> V_127 = F_31 ;
} else {
V_2 -> V_64 = F_32 ;
V_2 -> V_143 = F_63 ;
V_2 -> V_127 = F_33 ;
}
if ( F_5 ( V_6 ) )
V_148 -> V_248 = V_249 ;
else
V_148 -> V_248 = V_250 ;
F_163 ( V_2 , V_17 ) ;
F_181 ( V_148 , V_109 ) ;
V_2 -> V_68 = V_148 ;
if ( F_101 ( V_6 ) && ! F_182 ( V_6 ) ) {
T_2 V_136 = F_7 ( V_251 ) ;
F_21 ( V_251 , ( V_136 & ~ 0xf ) | 0xd ) ;
}
}
void F_183 ( struct V_5 * V_6 ,
T_3 V_10 , enum V_50 V_50 )
{
struct V_13 * V_14 ;
struct V_109 * V_109 ;
struct V_148 * V_148 ;
V_14 = F_184 ( sizeof( * V_14 ) , V_252 ) ;
if ( ! V_14 )
return;
V_148 = F_185 () ;
if ( ! V_148 ) {
F_123 ( V_14 ) ;
return;
}
V_109 = & V_14 -> V_3 ;
F_186 ( & V_6 -> V_253 , & V_109 -> V_3 ,
& V_254 , V_255 ,
L_32 , F_175 ( V_50 ) ) ;
V_109 -> V_256 = F_120 ;
if ( F_60 ( V_6 ) ) {
V_109 -> V_257 = F_98 ;
V_109 -> V_258 = F_99 ;
} else {
V_109 -> V_257 = F_96 ;
}
V_109 -> V_248 = F_74 ;
V_109 -> V_259 = F_80 ;
if ( F_58 ( V_6 ) ) {
V_109 -> V_260 = F_147 ;
V_109 -> V_261 = F_157 ;
V_109 -> V_87 = F_90 ;
V_109 -> V_258 = F_153 ;
V_109 -> V_262 = F_149 ;
} else if ( F_57 ( V_6 ) ) {
V_109 -> V_260 = F_145 ;
V_109 -> V_261 = F_141 ;
V_109 -> V_87 = F_90 ;
V_109 -> V_258 = F_151 ;
} else {
V_109 -> V_261 = F_140 ;
if ( F_70 ( V_6 ) )
V_109 -> V_87 = F_88 ;
else if ( F_92 ( V_6 ) )
V_109 -> V_87 = F_87 ;
else
V_109 -> V_87 = F_86 ;
}
V_109 -> type = V_170 ;
V_109 -> V_122 = F_187 ( V_50 ) ;
V_109 -> V_50 = V_50 ;
if ( F_58 ( V_6 ) ) {
if ( V_50 == V_229 )
V_109 -> V_263 = 1 << 2 ;
else
V_109 -> V_263 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_109 -> V_263 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_109 -> V_264 = 1 << V_265 ;
if ( F_101 ( V_6 ) )
V_109 -> V_264 |= 1 << V_170 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_15 . V_10 = V_10 ;
V_14 -> V_266 . V_267 = V_34 ;
V_14 -> V_239 = 4 ;
F_177 ( V_14 , V_148 ) ;
}
