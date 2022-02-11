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
F_12 ( type ) ;
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
F_12 ( type ) ;
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
F_12 ( type ) ;
return 0 ;
}
}
static T_3
F_15 ( struct V_5 * V_6 ,
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
F_12 ( type ) ;
return V_35 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_39 = F_6 ( V_40 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_40 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( V_43 , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( V_43 , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_40 , V_39 ) ;
F_22 ( V_40 ) ;
}
static bool F_23 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
T_2 V_39 = F_6 ( V_40 ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_27 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_30 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_31 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_3 V_53 = F_29 ( V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_32 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
if ( type != V_20 )
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_30 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_33 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 = F_6 ( F_29 ( V_54 ) ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_34 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_36 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_36 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_37 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 = F_6 ( F_35 ( V_54 ) ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_38 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
enum V_32 V_33 = V_51 -> V_57 -> V_33 ;
T_3 V_58 = F_39 ( V_33 ) ;
T_3 V_59 ;
int V_34 ;
T_2 V_39 = F_6 ( V_58 ) ;
V_59 = F_15 ( V_6 , V_33 , type , 0 ) ;
V_39 &= ~ F_14 ( type ) ;
F_20 ( V_58 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , 0 ) ;
F_21 () ;
V_39 |= F_14 ( type ) ;
F_20 ( V_58 , V_39 ) ;
F_22 ( V_58 ) ;
}
static bool F_40 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
T_2 V_39 = F_6 ( F_39 ( V_48 -> V_33 ) ) ;
return V_39 & ( V_60 | V_29 |
V_61 | V_31 |
V_62 | V_30 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
union V_63 * V_36 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_5 V_64 [ V_44 ] ;
T_4 V_37 ;
V_37 = F_42 ( V_36 , V_64 + 1 , sizeof( V_64 ) - 1 ) ;
if ( V_37 < 0 )
return;
V_64 [ 0 ] = V_64 [ 1 ] ;
V_64 [ 1 ] = V_64 [ 2 ] ;
V_64 [ 2 ] = V_64 [ 3 ] ;
V_64 [ 3 ] = 0 ;
V_37 ++ ;
V_2 -> V_65 ( V_13 , V_36 -> V_66 . type , V_64 , V_37 ) ;
}
static void F_43 ( struct V_12 * V_13 ,
const struct V_67 * V_68 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
union V_63 V_36 ;
int V_69 ;
V_69 = F_44 ( & V_36 . V_70 ,
V_68 ) ;
if ( V_69 < 0 ) {
F_45 ( L_3 ) ;
return;
}
if ( V_2 -> V_71 ) {
if ( V_51 -> V_57 -> V_72 )
V_36 . V_70 . V_73 =
V_74 ;
else
V_36 . V_70 . V_73 =
V_75 ;
}
F_41 ( V_13 , & V_36 ) ;
}
static void F_46 ( struct V_12 * V_13 )
{
union V_63 V_36 ;
int V_69 ;
V_69 = F_47 ( & V_36 . V_76 , L_4 , L_5 ) ;
if ( V_69 < 0 ) {
F_45 ( L_6 ) ;
return;
}
V_36 . V_76 . V_77 = V_78 ;
F_41 ( V_13 , & V_36 ) ;
}
static void
F_48 ( struct V_12 * V_13 ,
const struct V_67 * V_68 )
{
union V_63 V_36 ;
int V_69 ;
V_69 = F_49 ( & V_36 . V_79 . V_16 ,
V_68 ) ;
if ( V_69 < 0 )
return;
F_41 ( V_13 , & V_36 ) ;
}
static void F_50 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_53 = V_40 ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
if ( V_50 != ( V_39 & V_49 ) ) {
F_51 ( L_7 ,
( V_39 & V_49 ) >> 29 ) ;
return;
}
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_27 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
if ( V_39 & V_41 ) {
F_51 ( L_8 ,
( V_39 & V_49 ) >> 29 ) ;
return;
}
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_27 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static bool F_52 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_17 * V_18 ;
F_53 ( ! F_54 ( & V_4 -> V_81 . V_82 ) ) ;
F_55 (connector, &dev->mode_config.connector_list, head)
if ( V_18 -> V_13 == V_13 )
return V_18 -> V_83 . V_84 > 8 ;
return false ;
}
static bool F_56 ( int V_85 ,
const struct V_67 * V_86 )
{
unsigned int V_87 ;
switch ( V_85 ) {
case 30 :
V_87 = 4 ;
break;
case 36 :
V_87 = 2 ;
break;
case 48 :
V_87 = 1 ;
break;
default:
return false ;
}
return V_86 -> V_88 % V_87 == 0 &&
V_86 -> V_89 % V_87 == 0 &&
V_86 -> V_90 % V_87 == 0 &&
V_86 -> V_91 % V_87 == 0 &&
V_86 -> V_92 % V_87 == 0 &&
V_86 -> V_93 % V_87 == 0 &&
( ( V_86 -> V_94 & V_95 ) == 0 ||
V_86 -> V_89 / 2 % V_87 == 0 ) ;
}
static bool F_57 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 ;
T_2 V_39 = 0 ;
if ( F_4 ( V_6 ) )
V_53 = F_58 ( V_52 -> V_57 -> V_33 ) ;
else if ( F_59 ( V_6 ) || F_60 ( V_6 ) )
V_53 = F_61 ( V_52 -> V_54 ) ;
else if ( F_62 ( V_6 -> V_4 ) )
V_53 = F_63 ( V_52 -> V_54 ) ;
else
return false ;
if ( F_52 ( V_13 ) )
V_39 |= V_96 ;
if ( F_56 ( V_52 -> V_57 -> V_85 ,
& V_52 -> V_57 -> V_3 . V_68 ) )
V_39 |= V_97 ;
F_20 ( V_53 , V_39 ) ;
return V_39 != 0 ;
}
static void F_64 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
F_5 ( V_39 & V_41 ,
L_9 ,
( V_39 & V_49 ) >> 29 ) ;
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_65 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
V_39 |= V_41 | V_26 ;
V_39 &= ~ ( V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_66 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
F_5 ( V_39 & V_41 ,
L_9 ,
( V_39 & V_49 ) >> 29 ) ;
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_67 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_39 ( V_51 -> V_57 -> V_33 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
F_3 ( V_2 ) ;
V_39 &= ~ ( V_60 | V_29 |
V_61 | V_31 |
V_62 | V_30 ) ;
if ( ! V_80 ) {
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( F_57 ( V_13 ) )
V_39 |= V_61 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_68 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
const struct V_67 * V_68 = & V_52 -> V_57 -> V_3 . V_68 ;
T_2 V_99 ;
V_99 = V_100 ;
if ( ! F_62 ( V_4 ) && V_52 -> V_57 -> V_72 )
V_99 |= V_101 ;
if ( V_68 -> V_94 & V_102 )
V_99 |= V_103 ;
if ( V_68 -> V_94 & V_104 )
V_99 |= V_105 ;
if ( V_52 -> V_57 -> V_85 > 24 )
V_99 |= V_106 ;
else
V_99 |= V_107 ;
if ( V_52 -> V_57 -> V_108 )
V_99 |= V_109 ;
if ( F_69 ( V_4 ) )
V_99 |= F_70 ( V_52 -> V_54 ) ;
else if ( F_60 ( V_4 ) )
V_99 |= F_71 ( V_52 -> V_54 ) ;
else
V_99 |= F_72 ( V_52 -> V_54 ) ;
F_20 ( V_2 -> V_11 , V_99 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_73 ( struct V_98 * V_13 ,
enum V_54 * V_54 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_110 V_111 ;
T_2 V_112 ;
bool V_69 ;
V_111 = F_74 ( V_13 ) ;
if ( ! F_75 ( V_6 , V_111 ) )
return false ;
V_69 = false ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_112 & V_10 ) )
goto V_113;
if ( F_69 ( V_4 ) )
* V_54 = F_76 ( V_112 ) ;
else if ( F_60 ( V_4 ) )
* V_54 = F_77 ( V_112 ) ;
else
* V_54 = F_78 ( V_112 ) ;
V_69 = true ;
V_113:
F_79 ( V_6 , V_111 ) ;
return V_69 ;
}
static void F_80 ( struct V_98 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_112 , V_94 = 0 ;
int V_114 ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( V_112 & V_105 )
V_94 |= V_104 ;
else
V_94 |= V_115 ;
if ( V_112 & V_103 )
V_94 |= V_102 ;
else
V_94 |= V_116 ;
if ( V_112 & V_109 )
V_48 -> V_108 = true ;
if ( V_2 -> V_117 ( & V_13 -> V_3 , V_48 ) )
V_48 -> V_118 = true ;
if ( V_112 & V_119 )
V_48 -> V_120 = true ;
if ( ! F_62 ( V_4 ) &&
V_112 & V_101 )
V_48 -> V_72 = true ;
V_48 -> V_3 . V_68 . V_94 |= V_94 ;
if ( ( V_112 & V_121 ) == V_106 )
V_114 = V_48 -> V_122 * 2 / 3 ;
else
V_114 = V_48 -> V_122 ;
if ( V_48 -> V_123 )
V_114 /= V_48 -> V_123 ;
if ( F_62 ( V_6 -> V_4 ) )
F_81 ( V_48 , V_114 ) ;
V_48 -> V_3 . V_68 . V_124 = V_114 ;
}
static void F_82 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
F_53 ( ! V_52 -> V_57 -> V_108 ) ;
F_83 ( L_10 ,
F_84 ( V_52 -> V_54 ) ) ;
F_85 ( V_13 ) ;
}
static void F_86 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_87 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 &&
V_52 -> V_57 -> V_123 > 1 ) {
F_20 ( V_2 -> V_11 , V_125 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_88 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
F_20 ( F_89 ( V_54 ) ,
F_6 ( F_89 ( V_54 ) ) |
V_126 ) ;
V_125 &= ~ V_121 ;
V_125 |= V_107 ;
}
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
V_125 &= ~ V_121 ;
V_125 |= V_106 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( F_89 ( V_54 ) ,
F_6 ( F_89 ( V_54 ) ) &
~ V_126 ) ;
}
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_90 ( struct V_98 * V_13 )
{
}
static void F_91 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 &= ~ ( V_10 | V_119 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_92 ( V_4 ) && V_52 -> V_54 == V_127 ) {
F_93 ( V_6 , V_128 , false ) ;
F_94 ( V_6 , V_128 , false ) ;
V_125 &= ~ V_129 ;
V_125 |= V_10 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
V_125 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_95 ( V_6 -> V_4 , V_128 ) ;
F_93 ( V_6 , V_128 , true ) ;
F_94 ( V_6 , V_128 , true ) ;
}
V_2 -> V_130 ( & V_13 -> V_3 , false , NULL ) ;
}
static void F_96 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_120 )
F_97 ( V_13 ) ;
F_91 ( V_13 ) ;
}
static void F_98 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_120 )
F_97 ( V_13 ) ;
}
static void F_99 ( struct V_98 * V_13 )
{
F_91 ( V_13 ) ;
}
static int F_100 ( struct V_2 * V_16 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_131 && ! V_16 -> V_108 ) || F_101 ( V_4 ) )
return 165000 ;
else if ( F_102 ( V_4 ) || F_103 ( V_4 ) -> V_132 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_133
F_104 ( struct V_2 * V_16 ,
int clock , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( clock < 25000 )
return V_134 ;
if ( clock > F_100 ( V_16 , V_131 ) )
return V_135 ;
if ( F_105 ( V_4 ) && clock > 223333 && clock < 240000 )
return V_136 ;
if ( F_60 ( V_4 ) && clock > 216000 && clock < 240000 )
return V_136 ;
return V_137 ;
}
static enum V_133
F_106 ( struct V_17 * V_18 ,
struct V_67 * V_86 )
{
struct V_2 * V_16 = F_9 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_16 ) ;
enum V_133 V_138 ;
int clock ;
int V_139 = F_24 ( V_18 -> V_4 ) -> V_140 ;
if ( V_86 -> V_94 & V_141 )
return V_142 ;
clock = V_86 -> clock ;
if ( ( V_86 -> V_94 & V_143 ) == V_144 )
clock *= 2 ;
if ( clock > V_139 )
return V_135 ;
if ( V_86 -> V_94 & V_145 )
clock *= 2 ;
V_138 = F_104 ( V_16 , clock , true ) ;
if ( ! F_107 ( V_4 ) && V_138 != V_137 )
V_138 = F_104 ( V_16 , clock * 3 / 2 , true ) ;
return V_138 ;
}
static bool F_108 ( struct V_47 * V_146 )
{
struct V_1 * V_4 = V_146 -> V_3 . V_52 -> V_4 ;
struct V_147 * V_148 ;
struct V_98 * V_13 ;
struct V_17 * V_18 ;
struct V_149 * V_150 ;
int V_151 = 0 , V_152 = 0 ;
int V_34 ;
if ( F_107 ( V_4 ) )
return false ;
V_148 = V_146 -> V_3 . V_148 ;
F_109 (state, connector, connector_state, i) {
if ( V_150 -> V_52 != V_146 -> V_3 . V_52 )
continue;
V_13 = F_110 ( V_150 -> V_153 ) ;
V_152 += V_13 -> type == V_154 ;
V_151 ++ ;
}
return V_152 > 0 && V_152 == V_151 ;
}
bool F_111 ( struct V_98 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_67 * V_68 = & V_48 -> V_3 . V_68 ;
int V_155 = V_48 -> V_3 . V_68 . V_124 ;
int V_156 = V_155 * 3 / 2 ;
int V_157 ;
V_48 -> V_108 = V_2 -> V_108 ;
if ( V_48 -> V_108 )
V_48 -> V_118 = true ;
if ( V_2 -> V_158 ) {
V_48 -> V_72 =
V_48 -> V_108 &&
F_112 ( V_68 ) > 1 ;
} else {
V_48 -> V_72 =
V_2 -> V_72 ;
}
if ( V_68 -> V_94 & V_145 ) {
V_48 -> V_123 = 2 ;
V_155 *= 2 ;
V_156 *= 2 ;
}
if ( F_62 ( V_4 ) && ! F_4 ( V_4 ) )
V_48 -> V_159 = true ;
if ( V_48 -> V_108 && V_2 -> V_120 )
V_48 -> V_120 = true ;
if ( V_48 -> V_85 > 8 * 3 && V_48 -> V_108 &&
F_104 ( V_2 , V_156 , false ) == V_137 &&
F_108 ( V_48 ) ) {
F_51 ( L_11 ) ;
V_157 = 12 * 3 ;
V_48 -> V_122 = V_156 ;
} else {
F_51 ( L_12 ) ;
V_157 = 8 * 3 ;
V_48 -> V_122 = V_155 ;
}
if ( ! V_48 -> V_160 ) {
F_51 ( L_13 , V_157 ) ;
V_48 -> V_85 = V_157 ;
}
if ( F_104 ( V_2 , V_48 -> V_122 ,
false ) != V_137 ) {
F_51 ( L_14 ) ;
return false ;
}
V_68 -> V_161 = V_2 -> V_162 ;
return true ;
}
static void
F_113 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_108 = false ;
V_2 -> V_120 = false ;
V_2 -> V_71 = false ;
F_114 ( F_115 ( V_18 ) -> V_163 ) ;
F_115 ( V_18 ) -> V_163 = NULL ;
}
static bool
F_116 ( struct V_17 * V_18 , bool V_164 )
{
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_165 * V_165 = NULL ;
bool V_166 = false ;
if ( V_164 ) {
F_117 ( V_6 , V_167 ) ;
V_165 = F_118 ( V_18 ,
F_119 ( V_6 ,
V_2 -> V_168 ) ) ;
F_79 ( V_6 , V_167 ) ;
}
F_115 ( V_18 ) -> V_163 = V_165 ;
if ( V_165 && V_165 -> V_169 & V_170 ) {
V_2 -> V_71 =
F_120 ( V_165 ) ;
V_2 -> V_120 = F_121 ( V_165 ) ;
if ( V_2 -> V_171 != V_172 )
V_2 -> V_120 =
V_2 -> V_171 == V_173 ;
if ( V_2 -> V_171 != V_174 )
V_2 -> V_108 =
F_122 ( V_165 ) ;
V_166 = true ;
}
return V_166 ;
}
static enum V_175
F_123 ( struct V_17 * V_18 , bool V_164 )
{
enum V_175 V_138 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
bool V_176 = false ;
unsigned int V_177 ;
F_51 ( L_15 ,
V_18 -> V_3 . V_178 , V_18 -> V_179 ) ;
F_117 ( V_6 , V_167 ) ;
for ( V_177 = 0 ; ! V_176 && V_177 < 9 ; V_177 ++ ) {
if ( V_177 )
F_124 ( 10 ) ;
V_176 = F_125 ( V_6 ,
F_2 ( V_2 ) ) ;
}
if ( ! V_176 ) {
F_51 ( L_16 ) ;
if ( F_103 ( V_6 ) -> V_132 < 7 || F_126 ( V_6 ) )
V_176 = true ;
}
F_113 ( V_18 ) ;
if ( F_116 ( V_18 , V_176 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_154 ;
V_138 = V_180 ;
} else
V_138 = V_181 ;
F_79 ( V_6 , V_167 ) ;
return V_138 ;
}
static void
F_127 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_51 ( L_15 ,
V_18 -> V_3 . V_178 , V_18 -> V_179 ) ;
F_113 ( V_18 ) ;
if ( V_18 -> V_138 != V_180 )
return;
F_116 ( V_18 , true ) ;
F_2 ( V_2 ) -> V_3 . type = V_154 ;
}
static int F_128 ( struct V_17 * V_18 )
{
struct V_165 * V_165 ;
V_165 = F_115 ( V_18 ) -> V_163 ;
if ( V_165 == NULL )
return 0 ;
return F_129 ( V_18 , V_165 ) ;
}
static bool
F_130 ( struct V_17 * V_18 )
{
bool V_120 = false ;
struct V_165 * V_165 ;
V_165 = F_115 ( V_18 ) -> V_163 ;
if ( V_165 && V_165 -> V_169 & V_170 )
V_120 = F_121 ( V_165 ) ;
return V_120 ;
}
static int
F_131 ( struct V_17 * V_18 ,
struct V_182 * V_183 ,
T_6 V_39 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_69 ;
V_69 = F_132 ( & V_18 -> V_3 , V_183 , V_39 ) ;
if ( V_69 )
return V_69 ;
if ( V_183 == V_6 -> V_184 ) {
enum V_185 V_34 = V_39 ;
bool V_120 ;
if ( V_34 == V_2 -> V_171 )
return 0 ;
V_2 -> V_171 = V_34 ;
if ( V_34 == V_172 )
V_120 = F_130 ( V_18 ) ;
else
V_120 = ( V_34 == V_173 ) ;
if ( V_34 == V_174 )
V_2 -> V_108 = 0 ;
V_2 -> V_120 = V_120 ;
goto V_186;
}
if ( V_183 == V_6 -> V_187 ) {
bool V_188 = V_2 -> V_158 ;
bool V_189 = V_2 -> V_72 ;
switch ( V_39 ) {
case V_190 :
V_2 -> V_158 = true ;
break;
case V_191 :
V_2 -> V_158 = false ;
V_2 -> V_72 = false ;
break;
case V_192 :
V_2 -> V_158 = false ;
V_2 -> V_72 = true ;
break;
default:
return - V_193 ;
}
if ( V_188 == V_2 -> V_158 &&
V_189 == V_2 -> V_72 )
return 0 ;
goto V_186;
}
if ( V_183 == V_18 -> V_4 -> V_81 . V_194 ) {
switch ( V_39 ) {
case V_195 :
V_2 -> V_162 = V_196 ;
break;
case V_197 :
V_2 -> V_162 = V_198 ;
break;
case V_199 :
V_2 -> V_162 = V_200 ;
break;
default:
return - V_193 ;
}
goto V_186;
}
return - V_193 ;
V_186:
if ( V_15 -> V_3 . V_3 . V_52 )
F_133 ( V_15 -> V_3 . V_3 . V_52 ) ;
return 0 ;
}
static void F_134 ( struct V_98 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
F_68 ( V_13 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
}
static void F_135 ( struct V_98 * V_13 )
{
struct V_14 * V_201 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_201 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_202 V_50 = F_136 ( V_201 ) ;
int V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_137 ( & V_6 -> V_203 ) ;
V_39 = F_138 ( V_6 , V_54 , F_139 ( V_50 ) ) ;
V_39 = 0 ;
if ( V_54 )
V_39 |= ( 1 << 21 ) ;
else
V_39 &= ~ ( 1 << 21 ) ;
V_39 |= 0x001000c4 ;
F_140 ( V_6 , V_54 , F_141 ( V_50 ) , V_39 ) ;
F_140 ( V_6 , V_54 , F_142 ( V_50 ) , 0 ) ;
F_140 ( V_6 , V_54 , F_143 ( V_50 ) , 0x2b245f5f ) ;
F_140 ( V_6 , V_54 , F_144 ( V_50 ) , 0x5578b83a ) ;
F_140 ( V_6 , V_54 , F_145 ( V_50 ) , 0x0c782040 ) ;
F_140 ( V_6 , V_54 , F_146 ( V_50 ) , 0x2b247878 ) ;
F_140 ( V_6 , V_54 , F_147 ( V_50 ) , 0x00030000 ) ;
F_140 ( V_6 , V_54 , F_148 ( V_50 ) , 0x00002000 ) ;
F_140 ( V_6 , V_54 , F_142 ( V_50 ) , V_204 ) ;
F_140 ( V_6 , V_54 , F_149 ( V_50 ) , 0x00760018 ) ;
F_140 ( V_6 , V_54 , F_150 ( V_50 ) , 0x00400888 ) ;
F_151 ( & V_6 -> V_203 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
F_86 ( V_13 ) ;
F_152 ( V_6 , V_201 , 0x0 ) ;
}
static void F_153 ( struct V_98 * V_13 )
{
struct V_14 * V_201 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_202 V_50 = F_136 ( V_201 ) ;
int V_54 = V_51 -> V_54 ;
F_68 ( V_13 ) ;
F_137 ( & V_6 -> V_203 ) ;
F_140 ( V_6 , V_54 , F_154 ( V_50 ) ,
V_205 |
V_206 ) ;
F_140 ( V_6 , V_54 , F_155 ( V_50 ) ,
V_207 |
V_208 |
( 1 << V_209 ) |
V_210 ) ;
F_140 ( V_6 , V_54 , F_156 ( V_50 ) , 0x00750f00 ) ;
F_140 ( V_6 , V_54 , F_157 ( V_50 ) , 0x00001500 ) ;
F_140 ( V_6 , V_54 , F_158 ( V_50 ) , 0x40400000 ) ;
F_140 ( V_6 , V_54 , F_148 ( V_50 ) , 0x00002000 ) ;
F_140 ( V_6 , V_54 , F_142 ( V_50 ) , V_204 ) ;
F_151 ( & V_6 -> V_203 ) ;
}
static void F_159 ( struct V_98 * V_13 ,
bool V_211 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_202 V_212 = F_136 ( F_25 ( & V_13 -> V_3 ) ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_1 V_39 ;
V_39 = F_138 ( V_6 , V_54 , F_160 ( V_212 ) ) ;
if ( V_211 )
V_39 &= ~ ( V_205 | V_206 ) ;
else
V_39 |= V_205 | V_206 ;
F_140 ( V_6 , V_54 , F_160 ( V_212 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_213 > 2 ) {
V_39 = F_138 ( V_6 , V_54 , F_161 ( V_212 ) ) ;
if ( V_211 )
V_39 &= ~ ( V_205 | V_206 ) ;
else
V_39 |= V_205 | V_206 ;
F_140 ( V_6 , V_54 , F_161 ( V_212 ) , V_39 ) ;
}
V_39 = F_138 ( V_6 , V_54 , F_162 ( V_212 ) ) ;
V_39 |= V_214 ;
if ( V_211 )
V_39 &= ~ V_210 ;
else
V_39 |= V_210 ;
F_140 ( V_6 , V_54 , F_162 ( V_212 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_213 > 2 ) {
V_39 = F_138 ( V_6 , V_54 , F_163 ( V_212 ) ) ;
V_39 |= V_214 ;
if ( V_211 )
V_39 &= ~ V_210 ;
else
V_39 |= V_210 ;
F_140 ( V_6 , V_54 , F_163 ( V_212 ) , V_39 ) ;
}
}
static void F_164 ( struct V_98 * V_13 )
{
struct V_14 * V_201 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_202 V_212 = F_136 ( V_201 ) ;
enum V_54 V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_68 ( V_13 ) ;
if ( V_212 == V_215 && V_54 == V_127 )
V_201 -> V_216 =
! F_165 ( V_6 , V_217 , V_218 , true ) ;
F_166 ( V_13 , true , 0x0 ) ;
F_137 ( & V_6 -> V_203 ) ;
F_159 ( V_13 , true ) ;
if ( V_54 != V_127 ) {
V_39 = F_138 ( V_6 , V_54 , V_219 ) ;
V_39 &= ~ ( V_220 | V_221 ) ;
if ( V_212 == V_215 )
V_39 |= V_222 ;
if ( V_212 == V_218 )
V_39 |= V_223 ;
F_140 ( V_6 , V_54 , V_219 , V_39 ) ;
} else {
V_39 = F_138 ( V_6 , V_54 , V_224 ) ;
V_39 &= ~ ( V_225 | V_226 ) ;
if ( V_212 == V_215 )
V_39 |= V_227 ;
if ( V_212 == V_218 )
V_39 |= V_228 ;
F_140 ( V_6 , V_54 , V_224 , V_39 ) ;
}
V_39 = F_138 ( V_6 , V_54 , F_139 ( V_212 ) ) ;
V_39 |= V_229 ;
if ( V_54 != V_127 )
V_39 &= ~ V_230 ;
else
V_39 |= V_230 ;
F_140 ( V_6 , V_54 , F_139 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_167 ( V_212 ) ) ;
V_39 |= V_229 ;
if ( V_54 != V_127 )
V_39 &= ~ V_230 ;
else
V_39 |= V_230 ;
F_140 ( V_6 , V_54 , F_167 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_168 ( V_212 ) ) ;
if ( V_54 != V_127 )
V_39 &= ~ V_231 ;
else
V_39 |= V_231 ;
F_140 ( V_6 , V_54 , F_168 ( V_212 ) , V_39 ) ;
F_151 ( & V_6 -> V_203 ) ;
}
static void F_169 ( struct V_98 * V_13 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_54 V_54 = F_28 ( V_13 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 ;
F_137 ( & V_6 -> V_203 ) ;
if ( V_54 != V_127 ) {
V_39 = F_138 ( V_6 , V_54 , V_219 ) ;
V_39 &= ~ ( V_220 | V_221 ) ;
F_140 ( V_6 , V_54 , V_219 , V_39 ) ;
} else {
V_39 = F_138 ( V_6 , V_54 , V_224 ) ;
V_39 &= ~ ( V_225 | V_226 ) ;
F_140 ( V_6 , V_54 , V_224 , V_39 ) ;
}
F_151 ( & V_6 -> V_203 ) ;
F_166 ( V_13 , false , 0x0 ) ;
}
static void F_170 ( struct V_98 * V_13 )
{
struct V_14 * V_201 = F_25 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_202 V_50 = F_136 ( V_201 ) ;
int V_54 = V_51 -> V_54 ;
F_137 ( & V_6 -> V_203 ) ;
F_140 ( V_6 , V_54 , F_154 ( V_50 ) , 0x00000000 ) ;
F_140 ( V_6 , V_54 , F_155 ( V_50 ) , 0x00e00060 ) ;
F_151 ( & V_6 -> V_203 ) ;
}
static void F_171 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_137 ( & V_6 -> V_203 ) ;
F_159 ( V_13 , true ) ;
F_151 ( & V_6 -> V_203 ) ;
}
static void F_172 ( struct V_98 * V_13 )
{
struct V_14 * V_201 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_201 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_202 V_212 = F_136 ( V_201 ) ;
int V_54 = V_51 -> V_54 ;
int V_38 , V_34 , V_232 ;
T_2 V_39 ;
F_137 ( & V_6 -> V_203 ) ;
V_39 = F_138 ( V_6 , V_54 , F_173 ( V_212 ) ) ;
V_39 &= ~ V_233 ;
F_140 ( V_6 , V_54 , F_173 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_174 ( V_212 ) ) ;
V_39 &= ~ V_233 ;
F_140 ( V_6 , V_54 , F_174 ( V_212 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = ( V_34 == 1 ) ? 0x0 : 0x1 ;
F_140 ( V_6 , V_54 , F_175 ( V_212 , V_34 ) ,
V_38 << V_234 ) ;
}
if ( V_51 -> V_57 -> V_122 > 270000 )
V_232 = 0x18 ;
else if ( V_51 -> V_57 -> V_122 > 135000 )
V_232 = 0xd ;
else if ( V_51 -> V_57 -> V_122 > 67500 )
V_232 = 0x7 ;
else if ( V_51 -> V_57 -> V_122 > 33750 )
V_232 = 0x4 ;
else
V_232 = 0x2 ;
V_39 = F_138 ( V_6 , V_54 , F_173 ( V_212 ) ) ;
V_39 |= F_176 ( 0x1f ) ;
F_140 ( V_6 , V_54 , F_173 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_174 ( V_212 ) ) ;
V_39 |= F_176 ( 0x1f ) ;
F_140 ( V_6 , V_54 , F_174 ( V_212 ) , V_39 ) ;
F_140 ( V_6 , V_54 , F_177 ( V_212 ) ,
F_178 ( V_232 ) |
V_235 |
F_179 ( 0x1f ) |
F_180 ( 6 ) |
F_181 ( 0 ) ) ;
F_140 ( V_6 , V_54 , F_182 ( V_212 ) ,
F_178 ( V_232 ) |
V_235 |
F_179 ( 0x1f ) |
F_180 ( 7 ) |
F_181 ( 5 ) ) ;
F_159 ( V_13 , false ) ;
V_39 = F_138 ( V_6 , V_54 , F_183 ( V_212 ) ) ;
V_39 &= ~ ( V_236 | V_237 ) ;
V_39 &= ~ ( V_238 | V_239 ) ;
V_39 |= V_240 | V_241 ;
F_140 ( V_6 , V_54 , F_183 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_184 ( V_212 ) ) ;
V_39 &= ~ ( V_236 | V_237 ) ;
V_39 &= ~ ( V_238 | V_239 ) ;
V_39 |= V_240 | V_241 ;
F_140 ( V_6 , V_54 , F_184 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_185 ( V_212 ) ) ;
V_39 &= ~ ( V_242 | V_243 ) ;
V_39 |= V_244 | V_245 ;
F_140 ( V_6 , V_54 , F_185 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_186 ( V_212 ) ) ;
V_39 &= ~ ( V_242 | V_243 ) ;
V_39 |= V_244 | V_245 ;
F_140 ( V_6 , V_54 , F_186 ( V_212 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_138 ( V_6 , V_54 , F_187 ( V_212 , V_34 ) ) ;
V_39 &= ~ V_246 ;
V_39 |= 128 << V_247 ;
F_140 ( V_6 , V_54 , F_187 ( V_212 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_138 ( V_6 , V_54 , F_188 ( V_212 , V_34 ) ) ;
V_39 &= ~ V_248 ;
V_39 |= 102 << V_249 ;
V_39 &= ~ ( 0xff << V_250 ) ;
V_39 |= 0x9a << V_250 ;
F_140 ( V_6 , V_54 , F_188 ( V_212 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_138 ( V_6 , V_54 , F_189 ( V_212 , V_34 ) ) ;
V_39 &= ~ V_251 ;
F_140 ( V_6 , V_54 , F_189 ( V_212 , V_34 ) , V_39 ) ;
}
V_39 = F_138 ( V_6 , V_54 , F_183 ( V_212 ) ) ;
V_39 |= V_236 | V_237 ;
F_140 ( V_6 , V_54 , F_183 ( V_212 ) , V_39 ) ;
V_39 = F_138 ( V_6 , V_54 , F_184 ( V_212 ) ) ;
V_39 |= V_236 | V_237 ;
F_140 ( V_6 , V_54 , F_184 ( V_212 ) , V_39 ) ;
F_151 ( & V_6 -> V_203 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
F_86 ( V_13 ) ;
F_152 ( V_6 , V_201 , 0x0 ) ;
if ( V_201 -> V_216 ) {
F_165 ( V_6 , V_217 , V_218 , false ) ;
V_201 -> V_216 = false ;
}
}
static void F_190 ( struct V_17 * V_18 )
{
F_114 ( F_115 ( V_18 ) -> V_163 ) ;
F_191 ( V_18 ) ;
F_114 ( V_18 ) ;
}
static void
F_192 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_193 ( V_18 ) ;
F_194 ( V_18 ) ;
V_2 -> V_158 = true ;
F_195 ( V_18 ) ;
V_2 -> V_162 = V_196 ;
}
void F_196 ( struct V_14 * V_15 ,
struct V_252 * V_252 )
{
struct V_17 * V_18 = & V_252 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_98 * V_98 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_98 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_50 V_50 = V_15 -> V_50 ;
T_5 V_253 ;
if ( F_5 ( V_15 -> V_254 < 4 ,
L_17 ,
V_15 -> V_254 , F_197 ( V_50 ) ) )
return;
F_198 ( V_4 , V_18 , & V_255 ,
V_256 ) ;
F_199 ( V_18 , & V_257 ) ;
V_18 -> V_258 = 1 ;
V_18 -> V_259 = 0 ;
V_18 -> V_260 = 1 ;
switch ( V_50 ) {
case V_261 :
if ( F_105 ( V_6 ) )
V_2 -> V_168 = V_262 ;
else
V_2 -> V_168 = V_263 ;
if ( F_200 ( V_6 , 0 , V_264 ) )
V_98 -> V_265 = V_266 ;
else
V_98 -> V_265 = V_267 ;
break;
case V_268 :
if ( F_105 ( V_6 ) )
V_2 -> V_168 = V_269 ;
else
V_2 -> V_168 = V_270 ;
V_98 -> V_265 = V_271 ;
break;
case V_272 :
if ( F_53 ( F_105 ( V_6 ) ) )
V_2 -> V_168 = V_273 ;
else if ( F_60 ( V_6 ) )
V_2 -> V_168 = V_274 ;
else
V_2 -> V_168 = V_275 ;
V_98 -> V_265 = V_276 ;
break;
case V_277 :
V_253 =
V_6 -> V_278 . V_279 [ V_277 ] . V_253 ;
switch ( V_253 ) {
case V_280 :
V_2 -> V_168 = V_263 ;
break;
case V_281 :
V_2 -> V_168 = V_270 ;
break;
case V_282 :
V_2 -> V_168 = V_275 ;
break;
default:
F_12 ( V_253 ) ;
}
V_98 -> V_265 = V_283 ;
break;
case V_284 :
V_98 -> V_265 = V_266 ;
default:
F_201 () ;
}
if ( F_59 ( V_4 ) || F_60 ( V_4 ) ) {
V_2 -> V_65 = F_34 ;
V_2 -> V_130 = F_66 ;
V_2 -> V_117 = F_37 ;
} else if ( F_101 ( V_4 ) ) {
V_2 -> V_65 = F_19 ;
V_2 -> V_130 = F_50 ;
V_2 -> V_117 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_65 = F_38 ;
V_2 -> V_130 = F_67 ;
V_2 -> V_117 = F_40 ;
} else if ( F_92 ( V_4 ) ) {
V_2 -> V_65 = F_27 ;
V_2 -> V_130 = F_64 ;
V_2 -> V_117 = F_31 ;
} else {
V_2 -> V_65 = F_32 ;
V_2 -> V_130 = F_65 ;
V_2 -> V_117 = F_33 ;
}
if ( F_4 ( V_4 ) )
V_252 -> V_285 = V_286 ;
else
V_252 -> V_285 = V_287 ;
V_252 -> V_288 = V_289 ;
F_192 ( V_2 , V_18 ) ;
F_202 ( V_252 , V_98 ) ;
F_203 ( V_18 ) ;
V_2 -> V_290 = V_252 ;
if ( F_101 ( V_4 ) && ! F_204 ( V_4 ) ) {
T_2 V_125 = F_6 ( V_291 ) ;
F_20 ( V_291 , ( V_125 & ~ 0xf ) | 0xd ) ;
}
}
void F_205 ( struct V_1 * V_4 ,
T_3 V_11 , enum V_50 V_50 )
{
struct V_14 * V_15 ;
struct V_98 * V_98 ;
struct V_252 * V_252 ;
V_15 = F_206 ( sizeof( * V_15 ) , V_292 ) ;
if ( ! V_15 )
return;
V_252 = F_207 () ;
if ( ! V_252 ) {
F_114 ( V_15 ) ;
return;
}
V_98 = & V_15 -> V_3 ;
F_208 ( V_4 , & V_98 -> V_3 , & V_293 ,
V_294 , NULL ) ;
V_98 -> V_295 = F_111 ;
if ( F_62 ( V_4 ) ) {
V_98 -> V_296 = F_98 ;
V_98 -> V_297 = F_99 ;
} else {
V_98 -> V_296 = F_96 ;
}
V_98 -> V_285 = F_73 ;
V_98 -> V_298 = F_80 ;
if ( F_60 ( V_4 ) ) {
V_98 -> V_299 = F_164 ;
V_98 -> V_300 = F_172 ;
V_98 -> V_80 = F_90 ;
V_98 -> V_297 = F_171 ;
V_98 -> V_301 = F_169 ;
} else if ( F_59 ( V_4 ) ) {
V_98 -> V_299 = F_153 ;
V_98 -> V_300 = F_135 ;
V_98 -> V_80 = F_90 ;
V_98 -> V_297 = F_170 ;
} else {
V_98 -> V_300 = F_134 ;
if ( F_69 ( V_4 ) )
V_98 -> V_80 = F_88 ;
else if ( F_92 ( V_4 ) )
V_98 -> V_80 = F_87 ;
else
V_98 -> V_80 = F_86 ;
}
V_98 -> type = V_154 ;
if ( F_60 ( V_4 ) ) {
if ( V_50 == V_272 )
V_98 -> V_302 = 1 << 2 ;
else
V_98 -> V_302 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_98 -> V_302 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_98 -> V_303 = 1 << V_304 ;
if ( F_101 ( V_4 ) )
V_98 -> V_303 |= 1 << V_154 ;
V_15 -> V_50 = V_50 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_305 . V_306 = V_35 ;
V_15 -> V_254 = 4 ;
F_196 ( V_15 , V_252 ) ;
}
