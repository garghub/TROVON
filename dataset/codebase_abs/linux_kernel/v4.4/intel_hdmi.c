static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 ) -> V_3 . V_3 . V_4 ;
}
static void
F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
V_8 = F_4 ( V_4 ) ? V_9 : V_10 ;
F_5 ( F_6 ( V_2 -> V_11 ) & V_8 ,
L_1 ) ;
}
struct V_2 * F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_8 ( V_13 , struct V_14 , V_3 . V_3 ) ;
return & V_15 -> V_16 ;
}
static struct V_2 * F_9 ( struct V_17 * V_18 )
{
return F_7 ( & F_10 ( V_18 ) -> V_3 ) ;
}
static T_2 F_11 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_13 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_26 ;
case V_22 :
return V_27 ;
case V_24 :
return V_28 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_14 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_29 ;
case V_22 :
return V_30 ;
case V_24 :
return V_31 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_15 ( struct V_5 * V_6 ,
enum V_32 V_33 ,
enum V_19 type ,
int V_34 )
{
switch ( type ) {
case V_20 :
return F_16 ( V_33 , V_34 ) ;
case V_22 :
return F_17 ( V_33 , V_34 ) ;
case V_24 :
return F_18 ( V_33 , V_34 ) ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_35 , T_3 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_38 = F_6 ( V_39 ) ;
int V_34 ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_11 ( type ) ;
V_38 &= ~ F_13 ( type ) ;
F_20 ( V_39 , V_38 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 += 4 ) {
F_20 ( V_42 , * V_37 ) ;
V_37 ++ ;
}
for (; V_34 < V_43 ; V_34 += 4 )
F_20 ( V_42 , 0 ) ;
F_21 () ;
V_38 |= F_13 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_39 , V_38 ) ;
F_22 ( V_39 ) ;
}
static bool F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
T_2 V_38 = F_6 ( V_39 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_38 & ( V_26 |
V_28 | V_27 ) ;
}
static void F_26 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_35 , T_3 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_34 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_11 ( type ) ;
V_38 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_38 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_34 < V_43 ; V_34 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_38 |= F_13 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
}
static bool F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_38 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_35 , T_3 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_34 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_11 ( type ) ;
if ( type != V_20 )
V_38 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_38 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_34 < V_43 ; V_34 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_38 |= F_13 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
}
static bool F_32 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
return V_38 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_35 , T_3 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_34 , V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_11 ( type ) ;
V_38 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_38 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 += 4 ) {
F_20 ( F_35 ( V_48 -> V_51 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_34 < V_43 ; V_34 += 4 )
F_20 ( F_35 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_38 |= F_13 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
}
static bool F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_38 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_35 , T_3 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
enum V_32 V_33 = V_48 -> V_54 -> V_33 ;
T_2 V_55 = F_38 ( V_33 ) ;
T_2 V_56 ;
int V_34 ;
T_2 V_38 = F_6 ( V_55 ) ;
V_56 = F_15 ( V_6 , V_33 , type , 0 ) ;
if ( V_56 == 0 )
return;
V_38 &= ~ F_14 ( type ) ;
F_20 ( V_55 , V_38 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 += 4 ) {
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_34 < V_43 ; V_34 += 4 )
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , 0 ) ;
F_21 () ;
V_38 |= F_14 ( type ) ;
F_20 ( V_55 , V_38 ) ;
F_22 ( V_55 ) ;
}
static bool F_39 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_55 = F_38 ( V_48 -> V_54 -> V_33 ) ;
T_2 V_38 = F_6 ( V_55 ) ;
return V_38 & ( V_57 | V_29 |
V_58 | V_31 |
V_59 | V_30 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
union V_60 * V_35 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_4 V_61 [ V_43 ] ;
T_3 V_36 ;
V_36 = F_41 ( V_35 , V_61 + 1 , sizeof( V_61 ) - 1 ) ;
if ( V_36 < 0 )
return;
V_61 [ 0 ] = V_61 [ 1 ] ;
V_61 [ 1 ] = V_61 [ 2 ] ;
V_61 [ 2 ] = V_61 [ 3 ] ;
V_61 [ 3 ] = 0 ;
V_36 ++ ;
V_2 -> V_62 ( V_13 , V_35 -> V_63 . type , V_61 , V_36 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
const struct V_64 * V_65 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
union V_60 V_35 ;
int V_66 ;
V_66 = F_43 ( & V_35 . V_67 ,
V_65 ) ;
if ( V_66 < 0 ) {
F_44 ( L_4 ) ;
return;
}
if ( V_2 -> V_68 ) {
if ( V_48 -> V_54 -> V_69 )
V_35 . V_67 . V_70 =
V_71 ;
else
V_35 . V_67 . V_70 =
V_72 ;
}
F_40 ( V_13 , & V_35 ) ;
}
static void F_45 ( struct V_12 * V_13 )
{
union V_60 V_35 ;
int V_66 ;
V_66 = F_46 ( & V_35 . V_73 , L_5 , L_6 ) ;
if ( V_66 < 0 ) {
F_44 ( L_7 ) ;
return;
}
V_35 . V_73 . V_74 = V_75 ;
F_40 ( V_13 , & V_35 ) ;
}
static void
F_47 ( struct V_12 * V_13 ,
const struct V_64 * V_65 )
{
union V_60 V_35 ;
int V_66 ;
V_66 = F_48 ( & V_35 . V_76 . V_16 ,
V_65 ) ;
if ( V_66 < 0 )
return;
F_40 ( V_13 , & V_35 ) ;
}
static void F_49 ( struct V_12 * V_13 ,
bool V_77 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = V_39 ;
T_2 V_38 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_38 |= V_21 | V_45 ;
if ( ! V_77 ) {
if ( ! ( V_38 & V_40 ) )
return;
if ( V_47 != ( V_38 & V_46 ) ) {
F_50 ( L_8 ,
( V_38 & V_46 ) >> 29 ) ;
return;
}
V_38 &= ~ ( V_40 | V_26 |
V_28 | V_27 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_38 & V_46 ) ) {
if ( V_38 & V_40 ) {
F_50 ( L_9 ,
( V_38 & V_46 ) >> 29 ) ;
return;
}
V_38 &= ~ V_46 ;
V_38 |= V_47 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_26 |
V_28 | V_27 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static bool F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_17 * V_18 ;
F_52 ( ! F_53 ( & V_4 -> V_78 . V_79 ) ) ;
F_54 (connector, &dev->mode_config.connector_list, head)
if ( V_18 -> V_13 == V_13 )
return V_18 -> V_80 . V_81 > 8 ;
return false ;
}
static bool F_55 ( int V_82 ,
const struct V_64 * V_83 )
{
unsigned int V_84 ;
switch ( V_82 ) {
case 30 :
V_84 = 4 ;
break;
case 36 :
V_84 = 2 ;
break;
case 48 :
V_84 = 1 ;
break;
default:
return false ;
}
return V_83 -> V_85 % V_84 == 0 &&
V_83 -> V_86 % V_84 == 0 &&
V_83 -> V_87 % V_84 == 0 &&
V_83 -> V_88 % V_84 == 0 &&
V_83 -> V_89 % V_84 == 0 &&
V_83 -> V_90 % V_84 == 0 &&
( ( V_83 -> V_91 & V_92 ) == 0 ||
V_83 -> V_86 / 2 % V_84 == 0 ) ;
}
static bool F_56 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_49 ) ;
T_2 V_50 , V_38 = 0 ;
if ( F_4 ( V_6 ) )
V_50 = F_57 ( V_49 -> V_54 -> V_33 ) ;
else if ( F_58 ( V_6 ) )
V_50 = F_59 ( V_49 -> V_51 ) ;
else if ( F_60 ( V_6 -> V_4 ) )
V_50 = F_61 ( V_49 -> V_51 ) ;
else
return false ;
if ( F_51 ( V_13 ) )
V_38 |= V_93 ;
if ( F_55 ( V_49 -> V_54 -> V_82 ,
& V_49 -> V_54 -> V_3 . V_65 ) )
V_38 |= V_94 ;
F_20 ( V_50 , V_38 ) ;
return V_38 != 0 ;
}
static void F_62 ( struct V_12 * V_13 ,
bool V_77 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_38 |= V_21 | V_45 ;
if ( ! V_77 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_38 & V_46 ) ) {
F_5 ( V_38 & V_40 ,
L_10 ,
( V_38 & V_46 ) >> 29 ) ;
V_38 &= ~ V_46 ;
V_38 |= V_47 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_38 |= V_53 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_63 ( struct V_12 * V_13 ,
bool V_77 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
V_38 |= V_21 | V_45 ;
if ( ! V_77 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
return;
}
V_38 |= V_40 | V_26 ;
V_38 &= ~ ( V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_38 |= V_53 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_64 ( struct V_12 * V_13 ,
bool V_77 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_38 |= V_21 | V_45 ;
if ( ! V_77 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_38 & V_46 ) ) {
F_5 ( V_38 & V_40 ,
L_10 ,
( V_38 & V_46 ) >> 29 ) ;
V_38 &= ~ V_46 ;
V_38 |= V_47 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_38 |= V_53 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_65 ( struct V_12 * V_13 ,
bool V_77 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_38 ( V_48 -> V_54 -> V_33 ) ;
T_2 V_38 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
V_38 &= ~ ( V_57 | V_29 |
V_58 | V_31 |
V_59 | V_30 ) ;
if ( ! V_77 ) {
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
return;
}
if ( F_56 ( V_13 ) )
V_38 |= V_58 ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_66 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
const struct V_64 * V_65 = & V_49 -> V_54 -> V_3 . V_65 ;
T_2 V_96 ;
V_96 = V_97 ;
if ( ! F_60 ( V_4 ) && V_49 -> V_54 -> V_69 )
V_96 |= V_98 ;
if ( V_65 -> V_91 & V_99 )
V_96 |= V_100 ;
if ( V_65 -> V_91 & V_101 )
V_96 |= V_102 ;
if ( V_49 -> V_54 -> V_82 > 24 )
V_96 |= V_103 ;
else
V_96 |= V_104 ;
if ( V_49 -> V_54 -> V_105 )
V_96 |= V_106 ;
if ( F_67 ( V_4 ) )
V_96 |= F_68 ( V_49 -> V_51 ) ;
else if ( F_69 ( V_4 ) )
V_96 |= F_70 ( V_49 -> V_51 ) ;
else
V_96 |= F_71 ( V_49 -> V_51 ) ;
F_20 ( V_2 -> V_11 , V_96 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_72 ( struct V_95 * V_13 ,
enum V_51 * V_51 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_107 V_108 ;
T_2 V_109 ;
V_108 = F_73 ( V_13 ) ;
if ( ! F_74 ( V_6 , V_108 ) )
return false ;
V_109 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_109 & V_10 ) )
return false ;
if ( F_67 ( V_4 ) )
* V_51 = F_75 ( V_109 ) ;
else if ( F_69 ( V_4 ) )
* V_51 = F_76 ( V_109 ) ;
else
* V_51 = F_77 ( V_109 ) ;
return true ;
}
static void F_78 ( struct V_95 * V_13 ,
struct V_110 * V_111 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_109 , V_91 = 0 ;
int V_112 ;
V_109 = F_6 ( V_2 -> V_11 ) ;
if ( V_109 & V_102 )
V_91 |= V_101 ;
else
V_91 |= V_113 ;
if ( V_109 & V_100 )
V_91 |= V_99 ;
else
V_91 |= V_114 ;
if ( V_109 & V_106 )
V_111 -> V_105 = true ;
if ( V_2 -> V_115 ( & V_13 -> V_3 ) )
V_111 -> V_116 = true ;
if ( V_109 & V_117 )
V_111 -> V_118 = true ;
if ( ! F_60 ( V_4 ) &&
V_109 & V_98 )
V_111 -> V_69 = true ;
V_111 -> V_3 . V_65 . V_91 |= V_91 ;
if ( ( V_109 & V_119 ) == V_103 )
V_112 = V_111 -> V_120 * 2 / 3 ;
else
V_112 = V_111 -> V_120 ;
if ( V_111 -> V_121 )
V_112 /= V_111 -> V_121 ;
if ( F_60 ( V_6 -> V_4 ) )
F_79 ( V_111 , V_112 ) ;
V_111 -> V_3 . V_65 . V_122 = V_112 ;
}
static void F_80 ( struct V_95 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
F_52 ( ! V_49 -> V_54 -> V_105 ) ;
F_12 ( L_11 ,
F_81 ( V_49 -> V_51 ) ) ;
F_82 ( V_13 ) ;
}
static void F_83 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_123 ;
V_123 = F_6 ( V_2 -> V_11 ) ;
V_123 |= V_10 ;
if ( V_49 -> V_54 -> V_118 )
V_123 |= V_117 ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_54 -> V_118 )
F_80 ( V_13 ) ;
}
static void F_84 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_123 ;
V_123 = F_6 ( V_2 -> V_11 ) ;
V_123 |= V_10 ;
if ( V_49 -> V_54 -> V_118 )
V_123 |= V_117 ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_54 -> V_82 > 24 &&
V_49 -> V_54 -> V_121 > 1 ) {
F_20 ( V_2 -> V_11 , V_123 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_49 -> V_54 -> V_118 )
F_80 ( V_13 ) ;
}
static void F_85 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_51 V_51 = V_49 -> V_51 ;
T_2 V_123 ;
V_123 = F_6 ( V_2 -> V_11 ) ;
V_123 |= V_10 ;
if ( V_49 -> V_54 -> V_118 )
V_123 |= V_117 ;
if ( V_49 -> V_54 -> V_82 > 24 ) {
F_20 ( F_86 ( V_51 ) ,
F_6 ( F_86 ( V_51 ) ) |
V_124 ) ;
V_123 &= ~ V_119 ;
V_123 |= V_104 ;
}
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_54 -> V_82 > 24 ) {
V_123 &= ~ V_119 ;
V_123 |= V_103 ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( F_86 ( V_51 ) ,
F_6 ( F_86 ( V_51 ) ) &
~ V_124 ) ;
}
if ( V_49 -> V_54 -> V_118 )
F_80 ( V_13 ) ;
}
static void F_87 ( struct V_95 * V_13 )
{
}
static void F_88 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
T_2 V_123 ;
V_123 = F_6 ( V_2 -> V_11 ) ;
V_123 &= ~ ( V_10 | V_117 ) ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_89 ( V_4 ) && V_49 -> V_51 == V_125 ) {
V_123 &= ~ V_126 ;
V_123 |= V_10 ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
V_123 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_123 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_2 -> V_127 ( & V_13 -> V_3 , false , NULL ) ;
}
static void F_90 ( struct V_95 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_54 -> V_118 )
F_91 ( V_13 ) ;
F_88 ( V_13 ) ;
}
static void F_92 ( struct V_95 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_54 -> V_118 )
F_91 ( V_13 ) ;
}
static void F_93 ( struct V_95 * V_13 )
{
F_88 ( V_13 ) ;
}
static int F_94 ( struct V_2 * V_16 , bool V_128 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_128 && ! V_16 -> V_105 ) || F_95 ( V_4 ) )
return 165000 ;
else if ( F_96 ( V_4 ) || F_97 ( V_4 ) -> V_129 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_130
F_98 ( struct V_2 * V_16 ,
int clock , bool V_128 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( clock < 25000 )
return V_131 ;
if ( clock > F_94 ( V_16 , V_128 ) )
return V_132 ;
if ( F_99 ( V_4 ) && clock > 223333 && clock < 240000 )
return V_133 ;
if ( F_69 ( V_4 ) && clock > 216000 && clock < 240000 )
return V_133 ;
return V_134 ;
}
static enum V_130
F_100 ( struct V_17 * V_18 ,
struct V_64 * V_83 )
{
struct V_2 * V_16 = F_9 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_16 ) ;
enum V_130 V_135 ;
int clock ;
if ( V_83 -> V_91 & V_136 )
return V_137 ;
clock = V_83 -> clock ;
if ( V_83 -> V_91 & V_138 )
clock *= 2 ;
V_135 = F_98 ( V_16 , clock , true ) ;
if ( ! F_101 ( V_4 ) && V_135 != V_134 )
V_135 = F_98 ( V_16 , clock * 3 / 2 , true ) ;
return V_135 ;
}
static bool F_102 ( struct V_110 * V_139 )
{
struct V_1 * V_4 = V_139 -> V_3 . V_49 -> V_4 ;
struct V_140 * V_141 ;
struct V_95 * V_13 ;
struct V_17 * V_18 ;
struct V_142 * V_143 ;
int V_144 = 0 , V_145 = 0 ;
int V_34 ;
if ( F_101 ( V_4 ) )
return false ;
V_141 = V_139 -> V_3 . V_141 ;
F_103 (state, connector, connector_state, i) {
if ( V_143 -> V_49 != V_139 -> V_3 . V_49 )
continue;
V_13 = F_104 ( V_143 -> V_146 ) ;
V_145 += V_13 -> type == V_147 ;
V_144 ++ ;
}
return V_145 > 0 && V_145 == V_144 ;
}
bool F_105 ( struct V_95 * V_13 ,
struct V_110 * V_111 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_64 * V_65 = & V_111 -> V_3 . V_65 ;
int V_148 = V_111 -> V_3 . V_65 . V_122 ;
int V_149 = V_148 * 3 / 2 ;
int V_150 ;
V_111 -> V_105 = V_2 -> V_105 ;
if ( V_111 -> V_105 )
V_111 -> V_116 = true ;
if ( V_2 -> V_151 ) {
V_111 -> V_69 =
V_111 -> V_105 &&
F_106 ( V_65 ) > 1 ;
} else {
V_111 -> V_69 =
V_2 -> V_69 ;
}
if ( V_65 -> V_91 & V_138 ) {
V_111 -> V_121 = 2 ;
V_148 *= 2 ;
V_149 *= 2 ;
}
if ( F_60 ( V_4 ) && ! F_4 ( V_4 ) )
V_111 -> V_152 = true ;
if ( V_111 -> V_105 && V_2 -> V_118 )
V_111 -> V_118 = true ;
if ( V_111 -> V_82 > 8 * 3 && V_111 -> V_105 &&
F_98 ( V_2 , V_149 , false ) == V_134 &&
F_102 ( V_111 ) ) {
F_50 ( L_12 ) ;
V_150 = 12 * 3 ;
V_111 -> V_120 = V_149 ;
} else {
F_50 ( L_13 ) ;
V_150 = 8 * 3 ;
V_111 -> V_120 = V_148 ;
}
if ( ! V_111 -> V_153 ) {
F_50 ( L_14 , V_150 ) ;
V_111 -> V_82 = V_150 ;
}
if ( F_98 ( V_2 , V_111 -> V_120 ,
false ) != V_134 ) {
F_50 ( L_15 ) ;
return false ;
}
V_65 -> V_154 = V_2 -> V_155 ;
return true ;
}
static void
F_107 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_105 = false ;
V_2 -> V_118 = false ;
V_2 -> V_68 = false ;
F_108 ( F_109 ( V_18 ) -> V_156 ) ;
F_109 ( V_18 ) -> V_156 = NULL ;
}
static bool
F_110 ( struct V_17 * V_18 , bool V_157 )
{
struct V_5 * V_6 = F_111 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_158 * V_158 = NULL ;
bool V_159 = false ;
F_112 ( V_6 , V_160 ) ;
if ( V_157 )
V_158 = F_113 ( V_18 ,
F_114 ( V_6 ,
V_2 -> V_161 ) ) ;
F_115 ( V_6 , V_160 ) ;
F_109 ( V_18 ) -> V_156 = V_158 ;
if ( V_158 && V_158 -> V_162 & V_163 ) {
V_2 -> V_68 =
F_116 ( V_158 ) ;
V_2 -> V_118 = F_117 ( V_158 ) ;
if ( V_2 -> V_164 != V_165 )
V_2 -> V_118 =
V_2 -> V_164 == V_166 ;
if ( V_2 -> V_164 != V_167 )
V_2 -> V_105 =
F_118 ( V_158 ) ;
V_159 = true ;
}
return V_159 ;
}
static enum V_168
F_119 ( struct V_17 * V_18 , bool V_157 )
{
enum V_168 V_135 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = F_111 ( V_18 -> V_4 ) ;
bool V_169 = false ;
unsigned int V_170 ;
F_50 ( L_16 ,
V_18 -> V_3 . V_171 , V_18 -> V_172 ) ;
F_112 ( V_6 , V_160 ) ;
for ( V_170 = 0 ; ! V_169 && V_170 < 9 ; V_170 ++ ) {
if ( V_170 )
F_120 ( 10 ) ;
V_169 = F_121 ( V_6 ,
F_2 ( V_2 ) ) ;
}
if ( ! V_169 )
F_50 ( L_17 ) ;
F_107 ( V_18 ) ;
if ( F_110 ( V_18 , V_169 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_147 ;
V_135 = V_173 ;
} else
V_135 = V_174 ;
F_115 ( V_6 , V_160 ) ;
return V_135 ;
}
static void
F_122 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_50 ( L_16 ,
V_18 -> V_3 . V_171 , V_18 -> V_172 ) ;
F_107 ( V_18 ) ;
if ( V_18 -> V_135 != V_173 )
return;
F_110 ( V_18 , true ) ;
F_2 ( V_2 ) -> V_3 . type = V_147 ;
}
static int F_123 ( struct V_17 * V_18 )
{
struct V_158 * V_158 ;
V_158 = F_109 ( V_18 ) -> V_156 ;
if ( V_158 == NULL )
return 0 ;
return F_124 ( V_18 , V_158 ) ;
}
static bool
F_125 ( struct V_17 * V_18 )
{
bool V_118 = false ;
struct V_158 * V_158 ;
V_158 = F_109 ( V_18 ) -> V_156 ;
if ( V_158 && V_158 -> V_162 & V_163 )
V_118 = F_117 ( V_158 ) ;
return V_118 ;
}
static int
F_126 ( struct V_17 * V_18 ,
struct V_175 * V_176 ,
T_5 V_38 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_66 ;
V_66 = F_127 ( & V_18 -> V_3 , V_176 , V_38 ) ;
if ( V_66 )
return V_66 ;
if ( V_176 == V_6 -> V_177 ) {
enum V_178 V_34 = V_38 ;
bool V_118 ;
if ( V_34 == V_2 -> V_164 )
return 0 ;
V_2 -> V_164 = V_34 ;
if ( V_34 == V_165 )
V_118 = F_125 ( V_18 ) ;
else
V_118 = ( V_34 == V_166 ) ;
if ( V_34 == V_167 )
V_2 -> V_105 = 0 ;
V_2 -> V_118 = V_118 ;
goto V_179;
}
if ( V_176 == V_6 -> V_180 ) {
bool V_181 = V_2 -> V_151 ;
bool V_182 = V_2 -> V_69 ;
switch ( V_38 ) {
case V_183 :
V_2 -> V_151 = true ;
break;
case V_184 :
V_2 -> V_151 = false ;
V_2 -> V_69 = false ;
break;
case V_185 :
V_2 -> V_151 = false ;
V_2 -> V_69 = true ;
break;
default:
return - V_186 ;
}
if ( V_181 == V_2 -> V_151 &&
V_182 == V_2 -> V_69 )
return 0 ;
goto V_179;
}
if ( V_176 == V_18 -> V_4 -> V_78 . V_187 ) {
switch ( V_38 ) {
case V_188 :
V_2 -> V_155 = V_189 ;
break;
case V_190 :
V_2 -> V_155 = V_191 ;
break;
case V_192 :
V_2 -> V_155 = V_193 ;
break;
default:
return - V_186 ;
}
goto V_179;
}
return - V_186 ;
V_179:
if ( V_15 -> V_3 . V_3 . V_49 )
F_128 ( V_15 -> V_3 . V_3 . V_49 ) ;
return 0 ;
}
static void F_129 ( struct V_95 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
const struct V_64 * V_65 = & V_48 -> V_54 -> V_3 . V_65 ;
F_66 ( V_13 ) ;
V_2 -> V_127 ( & V_13 -> V_3 ,
V_48 -> V_54 -> V_105 ,
V_65 ) ;
}
static void F_130 ( struct V_95 * V_13 )
{
struct V_14 * V_194 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_194 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
const struct V_64 * V_65 = & V_48 -> V_54 -> V_3 . V_65 ;
enum V_195 V_47 = F_131 ( V_194 ) ;
int V_51 = V_48 -> V_51 ;
T_2 V_38 ;
F_132 ( & V_6 -> V_196 ) ;
V_38 = F_133 ( V_6 , V_51 , F_134 ( V_47 ) ) ;
V_38 = 0 ;
if ( V_51 )
V_38 |= ( 1 << 21 ) ;
else
V_38 &= ~ ( 1 << 21 ) ;
V_38 |= 0x001000c4 ;
F_135 ( V_6 , V_51 , F_136 ( V_47 ) , V_38 ) ;
F_135 ( V_6 , V_51 , F_137 ( V_47 ) , 0 ) ;
F_135 ( V_6 , V_51 , F_138 ( V_47 ) , 0x2b245f5f ) ;
F_135 ( V_6 , V_51 , F_139 ( V_47 ) , 0x5578b83a ) ;
F_135 ( V_6 , V_51 , F_140 ( V_47 ) , 0x0c782040 ) ;
F_135 ( V_6 , V_51 , F_141 ( V_47 ) , 0x2b247878 ) ;
F_135 ( V_6 , V_51 , F_142 ( V_47 ) , 0x00030000 ) ;
F_135 ( V_6 , V_51 , F_143 ( V_47 ) , 0x00002000 ) ;
F_135 ( V_6 , V_51 , F_137 ( V_47 ) , V_197 ) ;
F_135 ( V_6 , V_51 , F_144 ( V_47 ) , 0x00760018 ) ;
F_135 ( V_6 , V_51 , F_145 ( V_47 ) , 0x00400888 ) ;
F_146 ( & V_6 -> V_196 ) ;
V_2 -> V_127 ( & V_13 -> V_3 ,
V_48 -> V_54 -> V_105 ,
V_65 ) ;
F_83 ( V_13 ) ;
F_147 ( V_6 , V_194 , 0x0 ) ;
}
static void F_148 ( struct V_95 * V_13 )
{
struct V_14 * V_194 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_195 V_47 = F_131 ( V_194 ) ;
int V_51 = V_48 -> V_51 ;
F_66 ( V_13 ) ;
F_132 ( & V_6 -> V_196 ) ;
F_135 ( V_6 , V_51 , F_149 ( V_47 ) ,
V_198 |
V_199 ) ;
F_135 ( V_6 , V_51 , F_150 ( V_47 ) ,
V_200 |
V_201 |
( 1 << V_202 ) |
V_203 ) ;
F_135 ( V_6 , V_51 , F_151 ( V_47 ) , 0x00750f00 ) ;
F_135 ( V_6 , V_51 , F_152 ( V_47 ) , 0x00001500 ) ;
F_135 ( V_6 , V_51 , F_153 ( V_47 ) , 0x40400000 ) ;
F_135 ( V_6 , V_51 , F_143 ( V_47 ) , 0x00002000 ) ;
F_135 ( V_6 , V_51 , F_137 ( V_47 ) , V_197 ) ;
F_146 ( & V_6 -> V_196 ) ;
}
static void F_154 ( struct V_95 * V_13 ,
bool V_204 )
{
struct V_5 * V_6 = F_111 ( V_13 -> V_3 . V_4 ) ;
enum V_195 V_205 = F_131 ( F_24 ( & V_13 -> V_3 ) ) ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_51 V_51 = V_49 -> V_51 ;
T_1 V_38 ;
V_38 = F_133 ( V_6 , V_51 , F_155 ( V_205 ) ) ;
if ( V_204 )
V_38 &= ~ ( V_198 | V_199 ) ;
else
V_38 |= V_198 | V_199 ;
F_135 ( V_6 , V_51 , F_155 ( V_205 ) , V_38 ) ;
if ( V_49 -> V_54 -> V_206 > 2 ) {
V_38 = F_133 ( V_6 , V_51 , F_156 ( V_205 ) ) ;
if ( V_204 )
V_38 &= ~ ( V_198 | V_199 ) ;
else
V_38 |= V_198 | V_199 ;
F_135 ( V_6 , V_51 , F_156 ( V_205 ) , V_38 ) ;
}
V_38 = F_133 ( V_6 , V_51 , F_157 ( V_205 ) ) ;
V_38 |= V_207 ;
if ( V_204 )
V_38 &= ~ V_203 ;
else
V_38 |= V_203 ;
F_135 ( V_6 , V_51 , F_157 ( V_205 ) , V_38 ) ;
if ( V_49 -> V_54 -> V_206 > 2 ) {
V_38 = F_133 ( V_6 , V_51 , F_158 ( V_205 ) ) ;
V_38 |= V_207 ;
if ( V_204 )
V_38 &= ~ V_203 ;
else
V_38 |= V_203 ;
F_135 ( V_6 , V_51 , F_158 ( V_205 ) , V_38 ) ;
}
}
static void F_159 ( struct V_95 * V_13 )
{
struct V_14 * V_194 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_195 V_205 = F_131 ( V_194 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_38 ;
F_66 ( V_13 ) ;
if ( V_205 == V_208 && V_51 == V_125 )
V_194 -> V_209 =
! F_160 ( V_6 , V_210 , V_211 , true ) ;
F_161 ( V_13 , true , 0x0 ) ;
F_132 ( & V_6 -> V_196 ) ;
F_154 ( V_13 , true ) ;
if ( V_51 != V_125 ) {
V_38 = F_133 ( V_6 , V_51 , V_212 ) ;
V_38 &= ~ ( V_213 | V_214 ) ;
if ( V_205 == V_208 )
V_38 |= V_215 ;
if ( V_205 == V_211 )
V_38 |= V_216 ;
F_135 ( V_6 , V_51 , V_212 , V_38 ) ;
} else {
V_38 = F_133 ( V_6 , V_51 , V_217 ) ;
V_38 &= ~ ( V_218 | V_219 ) ;
if ( V_205 == V_208 )
V_38 |= V_220 ;
if ( V_205 == V_211 )
V_38 |= V_221 ;
F_135 ( V_6 , V_51 , V_217 , V_38 ) ;
}
V_38 = F_133 ( V_6 , V_51 , F_134 ( V_205 ) ) ;
V_38 |= V_222 ;
if ( V_51 != V_125 )
V_38 &= ~ V_223 ;
else
V_38 |= V_223 ;
F_135 ( V_6 , V_51 , F_134 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_162 ( V_205 ) ) ;
V_38 |= V_222 ;
if ( V_51 != V_125 )
V_38 &= ~ V_223 ;
else
V_38 |= V_223 ;
F_135 ( V_6 , V_51 , F_162 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_163 ( V_205 ) ) ;
if ( V_51 != V_125 )
V_38 &= ~ V_224 ;
else
V_38 |= V_224 ;
F_135 ( V_6 , V_51 , F_163 ( V_205 ) , V_38 ) ;
F_146 ( & V_6 -> V_196 ) ;
}
static void F_164 ( struct V_95 * V_13 )
{
struct V_5 * V_6 = F_111 ( V_13 -> V_3 . V_4 ) ;
enum V_51 V_51 = F_27 ( V_13 -> V_3 . V_49 ) -> V_51 ;
T_2 V_38 ;
F_132 ( & V_6 -> V_196 ) ;
if ( V_51 != V_125 ) {
V_38 = F_133 ( V_6 , V_51 , V_212 ) ;
V_38 &= ~ ( V_213 | V_214 ) ;
F_135 ( V_6 , V_51 , V_212 , V_38 ) ;
} else {
V_38 = F_133 ( V_6 , V_51 , V_217 ) ;
V_38 &= ~ ( V_218 | V_219 ) ;
F_135 ( V_6 , V_51 , V_217 , V_38 ) ;
}
F_146 ( & V_6 -> V_196 ) ;
F_161 ( V_13 , false , 0x0 ) ;
}
static void F_165 ( struct V_95 * V_13 )
{
struct V_14 * V_194 = F_24 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_195 V_47 = F_131 ( V_194 ) ;
int V_51 = V_48 -> V_51 ;
F_132 ( & V_6 -> V_196 ) ;
F_135 ( V_6 , V_51 , F_149 ( V_47 ) , 0x00000000 ) ;
F_135 ( V_6 , V_51 , F_150 ( V_47 ) , 0x00e00060 ) ;
F_146 ( & V_6 -> V_196 ) ;
}
static void F_166 ( struct V_95 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_132 ( & V_6 -> V_196 ) ;
F_154 ( V_13 , true ) ;
F_146 ( & V_6 -> V_196 ) ;
}
static void F_167 ( struct V_95 * V_13 )
{
struct V_14 * V_194 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_194 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
const struct V_64 * V_65 = & V_48 -> V_54 -> V_3 . V_65 ;
enum V_195 V_205 = F_131 ( V_194 ) ;
int V_51 = V_48 -> V_51 ;
int V_37 , V_34 , V_225 ;
T_2 V_38 ;
F_132 ( & V_6 -> V_196 ) ;
V_38 = F_133 ( V_6 , V_51 , F_168 ( V_205 ) ) ;
V_38 &= ~ V_226 ;
F_135 ( V_6 , V_51 , F_168 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_169 ( V_205 ) ) ;
V_38 &= ~ V_226 ;
F_135 ( V_6 , V_51 , F_169 ( V_205 ) , V_38 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_37 = ( V_34 == 1 ) ? 0x0 : 0x1 ;
F_135 ( V_6 , V_51 , F_170 ( V_205 , V_34 ) ,
V_37 << V_227 ) ;
}
if ( V_48 -> V_54 -> V_120 > 270000 )
V_225 = 0x18 ;
else if ( V_48 -> V_54 -> V_120 > 135000 )
V_225 = 0xd ;
else if ( V_48 -> V_54 -> V_120 > 67500 )
V_225 = 0x7 ;
else if ( V_48 -> V_54 -> V_120 > 33750 )
V_225 = 0x4 ;
else
V_225 = 0x2 ;
V_38 = F_133 ( V_6 , V_51 , F_168 ( V_205 ) ) ;
V_38 |= F_171 ( 0x1f ) ;
F_135 ( V_6 , V_51 , F_168 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_169 ( V_205 ) ) ;
V_38 |= F_171 ( 0x1f ) ;
F_135 ( V_6 , V_51 , F_169 ( V_205 ) , V_38 ) ;
F_135 ( V_6 , V_51 , F_172 ( V_205 ) ,
F_173 ( V_225 ) |
V_228 |
F_174 ( 0x1f ) |
F_175 ( 6 ) |
F_176 ( 0 ) ) ;
F_135 ( V_6 , V_51 , F_177 ( V_205 ) ,
F_173 ( V_225 ) |
V_228 |
F_174 ( 0x1f ) |
F_175 ( 7 ) |
F_176 ( 5 ) ) ;
F_154 ( V_13 , false ) ;
V_38 = F_133 ( V_6 , V_51 , F_178 ( V_205 ) ) ;
V_38 &= ~ ( V_229 | V_230 ) ;
V_38 &= ~ ( V_231 | V_232 ) ;
V_38 |= V_233 | V_234 ;
F_135 ( V_6 , V_51 , F_178 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_179 ( V_205 ) ) ;
V_38 &= ~ ( V_229 | V_230 ) ;
V_38 &= ~ ( V_231 | V_232 ) ;
V_38 |= V_233 | V_234 ;
F_135 ( V_6 , V_51 , F_179 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_180 ( V_205 ) ) ;
V_38 &= ~ ( V_235 | V_236 ) ;
V_38 |= V_237 | V_238 ;
F_135 ( V_6 , V_51 , F_180 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_181 ( V_205 ) ) ;
V_38 &= ~ ( V_235 | V_236 ) ;
V_38 |= V_237 | V_238 ;
F_135 ( V_6 , V_51 , F_181 ( V_205 ) , V_38 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = F_133 ( V_6 , V_51 , F_182 ( V_205 , V_34 ) ) ;
V_38 &= ~ V_239 ;
V_38 |= 128 << V_240 ;
F_135 ( V_6 , V_51 , F_182 ( V_205 , V_34 ) , V_38 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = F_133 ( V_6 , V_51 , F_183 ( V_205 , V_34 ) ) ;
V_38 &= ~ V_241 ;
V_38 |= 102 << V_242 ;
V_38 &= ~ ( 0xff << V_243 ) ;
V_38 |= 0x9a << V_243 ;
F_135 ( V_6 , V_51 , F_183 ( V_205 , V_34 ) , V_38 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = F_133 ( V_6 , V_51 , F_184 ( V_205 , V_34 ) ) ;
V_38 &= ~ V_244 ;
F_135 ( V_6 , V_51 , F_184 ( V_205 , V_34 ) , V_38 ) ;
}
V_38 = F_133 ( V_6 , V_51 , F_178 ( V_205 ) ) ;
V_38 |= V_229 | V_230 ;
F_135 ( V_6 , V_51 , F_178 ( V_205 ) , V_38 ) ;
V_38 = F_133 ( V_6 , V_51 , F_179 ( V_205 ) ) ;
V_38 |= V_229 | V_230 ;
F_135 ( V_6 , V_51 , F_179 ( V_205 ) , V_38 ) ;
F_146 ( & V_6 -> V_196 ) ;
V_2 -> V_127 ( & V_13 -> V_3 ,
V_48 -> V_54 -> V_105 ,
V_65 ) ;
F_83 ( V_13 ) ;
F_147 ( V_6 , V_194 , 0x0 ) ;
if ( V_194 -> V_209 ) {
F_160 ( V_6 , V_210 , V_211 , false ) ;
V_194 -> V_209 = false ;
}
}
static void F_185 ( struct V_17 * V_18 )
{
F_108 ( F_109 ( V_18 ) -> V_156 ) ;
F_186 ( V_18 ) ;
F_108 ( V_18 ) ;
}
static void
F_187 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_188 ( V_18 ) ;
F_189 ( V_18 ) ;
V_2 -> V_151 = true ;
F_190 ( V_18 ) ;
V_2 -> V_155 = V_189 ;
}
void F_191 ( struct V_14 * V_15 ,
struct V_245 * V_245 )
{
struct V_17 * V_18 = & V_245 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_95 * V_95 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_95 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_47 V_47 = V_15 -> V_47 ;
T_4 V_246 ;
F_192 ( V_4 , V_18 , & V_247 ,
V_248 ) ;
F_193 ( V_18 , & V_249 ) ;
V_18 -> V_250 = 1 ;
V_18 -> V_251 = 0 ;
V_18 -> V_252 = 1 ;
switch ( V_47 ) {
case V_253 :
if ( F_99 ( V_6 ) )
V_2 -> V_161 = V_254 ;
else
V_2 -> V_161 = V_255 ;
if ( F_99 ( V_6 ) && ( F_194 ( V_4 ) < V_256 ) )
V_95 -> V_257 = V_258 ;
else
V_95 -> V_257 = V_259 ;
break;
case V_260 :
if ( F_99 ( V_6 ) )
V_2 -> V_161 = V_261 ;
else
V_2 -> V_161 = V_262 ;
V_95 -> V_257 = V_263 ;
break;
case V_264 :
if ( F_52 ( F_99 ( V_6 ) ) )
V_2 -> V_161 = V_265 ;
else if ( F_69 ( V_6 ) )
V_2 -> V_161 = V_266 ;
else
V_2 -> V_161 = V_267 ;
V_95 -> V_257 = V_268 ;
break;
case V_269 :
V_246 =
V_6 -> V_270 . V_271 [ V_269 ] . V_246 ;
switch ( V_246 ) {
case V_272 :
V_2 -> V_161 = V_255 ;
break;
case V_273 :
V_2 -> V_161 = V_262 ;
break;
case V_274 :
V_2 -> V_161 = V_267 ;
break;
default:
F_195 ( V_246 ) ;
}
V_95 -> V_257 = V_275 ;
break;
case V_276 :
V_95 -> V_257 = V_258 ;
default:
F_196 () ;
}
if ( F_58 ( V_4 ) ) {
V_2 -> V_62 = F_33 ;
V_2 -> V_127 = F_64 ;
V_2 -> V_115 = F_36 ;
} else if ( F_95 ( V_4 ) ) {
V_2 -> V_62 = F_19 ;
V_2 -> V_127 = F_49 ;
V_2 -> V_115 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_62 = F_37 ;
V_2 -> V_127 = F_65 ;
V_2 -> V_115 = F_39 ;
} else if ( F_89 ( V_4 ) ) {
V_2 -> V_62 = F_26 ;
V_2 -> V_127 = F_62 ;
V_2 -> V_115 = F_30 ;
} else {
V_2 -> V_62 = F_31 ;
V_2 -> V_127 = F_63 ;
V_2 -> V_115 = F_32 ;
}
if ( F_4 ( V_4 ) )
V_245 -> V_277 = V_278 ;
else
V_245 -> V_277 = V_279 ;
V_245 -> V_280 = V_281 ;
F_187 ( V_2 , V_18 ) ;
F_197 ( V_245 , V_95 ) ;
F_198 ( V_18 ) ;
V_2 -> V_282 = V_245 ;
if ( F_95 ( V_4 ) && ! F_199 ( V_4 ) ) {
T_2 V_123 = F_6 ( V_283 ) ;
F_20 ( V_283 , ( V_123 & ~ 0xf ) | 0xd ) ;
}
}
void F_200 ( struct V_1 * V_4 , int V_11 , enum V_47 V_47 )
{
struct V_14 * V_15 ;
struct V_95 * V_95 ;
struct V_245 * V_245 ;
V_15 = F_201 ( sizeof( * V_15 ) , V_284 ) ;
if ( ! V_15 )
return;
V_245 = F_202 () ;
if ( ! V_245 ) {
F_108 ( V_15 ) ;
return;
}
V_95 = & V_15 -> V_3 ;
F_203 ( V_4 , & V_95 -> V_3 , & V_285 ,
V_286 ) ;
V_95 -> V_287 = F_105 ;
if ( F_60 ( V_4 ) ) {
V_95 -> V_288 = F_92 ;
V_95 -> V_289 = F_93 ;
} else {
V_95 -> V_288 = F_90 ;
}
V_95 -> V_277 = F_72 ;
V_95 -> V_290 = F_78 ;
if ( F_69 ( V_4 ) ) {
V_95 -> V_291 = F_159 ;
V_95 -> V_292 = F_167 ;
V_95 -> V_77 = F_87 ;
V_95 -> V_289 = F_166 ;
V_95 -> V_293 = F_164 ;
} else if ( F_58 ( V_4 ) ) {
V_95 -> V_291 = F_148 ;
V_95 -> V_292 = F_130 ;
V_95 -> V_77 = F_87 ;
V_95 -> V_289 = F_165 ;
} else {
V_95 -> V_292 = F_129 ;
if ( F_67 ( V_4 ) )
V_95 -> V_77 = F_85 ;
else if ( F_89 ( V_4 ) )
V_95 -> V_77 = F_84 ;
else
V_95 -> V_77 = F_83 ;
}
V_95 -> type = V_147 ;
if ( F_69 ( V_4 ) ) {
if ( V_47 == V_264 )
V_95 -> V_294 = 1 << 2 ;
else
V_95 -> V_294 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_95 -> V_294 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_95 -> V_295 = 1 << V_296 ;
if ( F_95 ( V_4 ) )
V_95 -> V_295 |= 1 << V_147 ;
V_15 -> V_47 = V_47 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_297 . V_298 = 0 ;
F_191 ( V_15 , V_245 ) ;
}
