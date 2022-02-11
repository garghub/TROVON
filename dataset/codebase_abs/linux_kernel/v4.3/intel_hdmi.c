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
static T_2 F_15 ( enum V_19 type ,
enum V_32 V_33 ,
struct V_5 * V_6 )
{
switch ( type ) {
case V_20 :
return F_16 ( V_33 ) ;
case V_22 :
return F_17 ( V_33 ) ;
case V_24 :
return F_18 ( V_33 ) ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_37 = F_6 ( V_38 ) ;
int V_39 ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_38 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( V_42 , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( V_42 , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_38 , V_37 ) ;
F_22 ( V_38 ) ;
}
static bool F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
T_2 V_37 = F_6 ( V_38 ) ;
if ( ( V_37 & V_40 ) == 0 )
return false ;
if ( ( V_37 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_37 & ( V_26 |
V_28 | V_27 ) ;
}
static void F_26 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
if ( ( V_37 & V_40 ) == 0 )
return false ;
if ( ( V_37 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_37 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
if ( type != V_20 )
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_32 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
if ( ( V_37 & V_40 ) == 0 )
return false ;
return V_37 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_35 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_35 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
if ( ( V_37 & V_40 ) == 0 )
return false ;
if ( ( V_37 & V_46 ) != F_25 ( V_15 -> V_47 ) )
return false ;
return V_37 & ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_54 = F_38 ( V_48 -> V_55 -> V_33 ) ;
T_2 V_56 ;
int V_39 ;
T_2 V_37 = F_6 ( V_54 ) ;
V_56 = F_15 ( type ,
V_48 -> V_55 -> V_33 ,
V_6 ) ;
if ( V_56 == 0 )
return;
V_37 &= ~ F_14 ( type ) ;
F_20 ( V_54 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( V_56 + V_39 , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( V_56 + V_39 , 0 ) ;
F_21 () ;
V_37 |= F_14 ( type ) ;
F_20 ( V_54 , V_37 ) ;
F_22 ( V_54 ) ;
}
static bool F_39 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_54 = F_38 ( V_48 -> V_55 -> V_33 ) ;
T_2 V_37 = F_6 ( V_54 ) ;
return V_37 & ( V_57 | V_29 |
V_58 | V_31 |
V_59 | V_30 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
union V_60 * V_34 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_4 V_61 [ V_43 ] ;
T_3 V_35 ;
V_35 = F_41 ( V_34 , V_61 + 1 , sizeof( V_61 ) - 1 ) ;
if ( V_35 < 0 )
return;
V_61 [ 0 ] = V_61 [ 1 ] ;
V_61 [ 1 ] = V_61 [ 2 ] ;
V_61 [ 2 ] = V_61 [ 3 ] ;
V_61 [ 3 ] = 0 ;
V_35 ++ ;
V_2 -> V_62 ( V_13 , V_34 -> V_63 . type , V_61 , V_35 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_64 * V_65 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
union V_60 V_34 ;
int V_66 ;
V_65 -> V_67 = V_2 -> V_68 ;
V_66 = F_43 ( & V_34 . V_69 ,
V_65 ) ;
if ( V_66 < 0 ) {
F_44 ( L_4 ) ;
return;
}
if ( V_2 -> V_70 ) {
if ( V_48 -> V_55 -> V_71 )
V_34 . V_69 . V_72 =
V_73 ;
else
V_34 . V_69 . V_72 =
V_74 ;
}
F_40 ( V_13 , & V_34 ) ;
}
static void F_45 ( struct V_12 * V_13 )
{
union V_60 V_34 ;
int V_66 ;
V_66 = F_46 ( & V_34 . V_75 , L_5 , L_6 ) ;
if ( V_66 < 0 ) {
F_44 ( L_7 ) ;
return;
}
V_34 . V_75 . V_76 = V_77 ;
F_40 ( V_13 , & V_34 ) ;
}
static void
F_47 ( struct V_12 * V_13 ,
struct V_64 * V_65 )
{
union V_60 V_34 ;
int V_66 ;
V_66 = F_48 ( & V_34 . V_78 . V_16 ,
V_65 ) ;
if ( V_66 < 0 )
return;
F_40 ( V_13 , & V_34 ) ;
}
static void F_49 ( struct V_12 * V_13 ,
bool V_79 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = V_38 ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_37 & V_40 ) )
return;
if ( V_47 != ( V_37 & V_46 ) ) {
F_50 ( L_8 ,
( V_37 & V_46 ) >> 29 ) ;
return;
}
V_37 &= ~ ( V_40 | V_26 |
V_28 | V_27 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_37 & V_46 ) ) {
if ( V_37 & V_40 ) {
F_50 ( L_9 ,
( V_37 & V_46 ) >> 29 ) ;
return;
}
V_37 &= ~ V_46 ;
V_37 |= V_47 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_26 |
V_28 | V_27 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static bool F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_17 * V_18 ;
F_52 ( ! F_53 ( & V_4 -> V_80 . V_81 ) ) ;
F_54 (connector, &dev->mode_config.connector_list, head)
if ( V_18 -> V_13 == V_13 )
return V_18 -> V_82 . V_83 > 8 ;
return false ;
}
static bool F_55 ( int V_84 ,
const struct V_64 * V_85 )
{
unsigned int V_86 ;
switch ( V_84 ) {
case 30 :
V_86 = 4 ;
break;
case 36 :
V_86 = 2 ;
break;
case 48 :
V_86 = 1 ;
break;
default:
return false ;
}
return V_85 -> V_87 % V_86 == 0 &&
V_85 -> V_88 % V_86 == 0 &&
V_85 -> V_89 % V_86 == 0 &&
V_85 -> V_90 % V_86 == 0 &&
V_85 -> V_91 % V_86 == 0 &&
V_85 -> V_92 % V_86 == 0 &&
( ( V_85 -> V_93 & V_94 ) == 0 ||
V_85 -> V_88 / 2 % V_86 == 0 ) ;
}
static bool F_56 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_49 ) ;
T_2 V_50 , V_37 = 0 ;
if ( F_4 ( V_6 ) )
V_50 = F_57 ( V_49 -> V_55 -> V_33 ) ;
else if ( F_58 ( V_6 ) )
V_50 = F_59 ( V_49 -> V_51 ) ;
else if ( F_60 ( V_6 -> V_4 ) )
V_50 = F_61 ( V_49 -> V_51 ) ;
else
return false ;
if ( F_51 ( V_13 ) )
V_37 |= V_95 ;
if ( F_55 ( V_49 -> V_55 -> V_84 ,
& V_49 -> V_55 -> V_3 . V_65 ) )
V_37 |= V_96 ;
F_20 ( V_50 , V_37 ) ;
return V_37 != 0 ;
}
static void F_62 ( struct V_12 * V_13 ,
bool V_79 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_37 & V_46 ) ) {
F_5 ( V_37 & V_40 ,
L_10 ,
( V_37 & V_46 ) >> 29 ) ;
V_37 &= ~ V_46 ;
V_37 |= V_47 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_37 |= V_53 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_63 ( struct V_12 * V_13 ,
bool V_79 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
V_37 |= V_40 | V_26 ;
V_37 &= ~ ( V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_37 |= V_53 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_64 ( struct V_12 * V_13 ,
bool V_79 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_47 = F_25 ( V_15 -> V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_47 != ( V_37 & V_46 ) ) {
F_5 ( V_37 & V_40 ,
L_10 ,
( V_37 & V_46 ) >> 29 ) ;
V_37 &= ~ V_46 ;
V_37 |= V_47 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_26 |
V_28 | V_52 |
V_27 | V_53 ) ;
if ( F_56 ( V_13 ) )
V_37 |= V_53 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_65 ( struct V_12 * V_13 ,
bool V_79 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_38 ( V_48 -> V_55 -> V_33 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
V_37 &= ~ ( V_57 | V_29 |
V_58 | V_31 |
V_59 | V_30 ) ;
if ( ! V_79 ) {
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( F_56 ( V_13 ) )
V_37 |= V_58 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_65 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_65 ) ;
}
static void F_66 ( struct V_97 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_64 * V_65 = & V_49 -> V_55 -> V_3 . V_65 ;
T_2 V_98 ;
V_98 = V_99 ;
if ( ! F_60 ( V_4 ) )
V_98 |= V_2 -> V_100 ;
if ( V_65 -> V_93 & V_101 )
V_98 |= V_102 ;
if ( V_65 -> V_93 & V_103 )
V_98 |= V_104 ;
if ( V_49 -> V_55 -> V_84 > 24 )
V_98 |= V_105 ;
else
V_98 |= V_106 ;
if ( V_49 -> V_55 -> V_107 )
V_98 |= V_108 ;
if ( F_67 ( V_4 ) )
V_98 |= F_68 ( V_49 -> V_51 ) ;
else if ( F_69 ( V_4 ) )
V_98 |= F_70 ( V_49 -> V_51 ) ;
else
V_98 |= F_71 ( V_49 -> V_51 ) ;
F_20 ( V_2 -> V_11 , V_98 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_72 ( struct V_97 * V_13 ,
enum V_51 * V_51 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_109 V_110 ;
T_2 V_111 ;
V_110 = F_73 ( V_13 ) ;
if ( ! F_74 ( V_6 , V_110 ) )
return false ;
V_111 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_111 & V_10 ) )
return false ;
if ( F_67 ( V_4 ) )
* V_51 = F_75 ( V_111 ) ;
else if ( F_69 ( V_4 ) )
* V_51 = F_76 ( V_111 ) ;
else
* V_51 = F_77 ( V_111 ) ;
return true ;
}
static void F_78 ( struct V_97 * V_13 ,
struct V_112 * V_113 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_111 , V_93 = 0 ;
int V_114 ;
V_111 = F_6 ( V_2 -> V_11 ) ;
if ( V_111 & V_104 )
V_93 |= V_103 ;
else
V_93 |= V_115 ;
if ( V_111 & V_102 )
V_93 |= V_101 ;
else
V_93 |= V_116 ;
if ( V_111 & V_108 )
V_113 -> V_107 = true ;
if ( V_2 -> V_117 ( & V_13 -> V_3 ) )
V_113 -> V_118 = true ;
if ( V_111 & V_119 )
V_113 -> V_120 = true ;
if ( ! F_60 ( V_4 ) &&
V_111 & V_121 )
V_113 -> V_71 = true ;
V_113 -> V_3 . V_65 . V_93 |= V_93 ;
if ( ( V_111 & V_122 ) == V_105 )
V_114 = V_113 -> V_123 * 2 / 3 ;
else
V_114 = V_113 -> V_123 ;
if ( V_113 -> V_124 )
V_114 /= V_113 -> V_124 ;
if ( F_60 ( V_6 -> V_4 ) )
F_79 ( V_113 , V_114 ) ;
V_113 -> V_3 . V_65 . V_125 = V_114 ;
}
static void F_80 ( struct V_97 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
F_52 ( ! V_49 -> V_55 -> V_107 ) ;
F_12 ( L_11 ,
F_81 ( V_49 -> V_51 ) ) ;
F_82 ( V_13 ) ;
}
static void F_83 ( struct V_97 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_126 ;
V_126 = F_6 ( V_2 -> V_11 ) ;
V_126 |= V_10 ;
if ( V_49 -> V_55 -> V_120 )
V_126 |= V_119 ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_55 -> V_120 )
F_80 ( V_13 ) ;
}
static void F_84 ( struct V_97 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_126 ;
V_126 = F_6 ( V_2 -> V_11 ) ;
V_126 |= V_10 ;
if ( V_49 -> V_55 -> V_120 )
V_126 |= V_119 ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_55 -> V_84 > 24 &&
V_49 -> V_55 -> V_124 > 1 ) {
F_20 ( V_2 -> V_11 , V_126 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_49 -> V_55 -> V_120 )
F_80 ( V_13 ) ;
}
static void F_85 ( struct V_97 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_51 V_51 = V_49 -> V_51 ;
T_2 V_126 ;
V_126 = F_6 ( V_2 -> V_11 ) ;
V_126 |= V_10 ;
if ( V_49 -> V_55 -> V_120 )
V_126 |= V_119 ;
if ( V_49 -> V_55 -> V_84 > 24 ) {
F_20 ( F_86 ( V_51 ) ,
F_6 ( F_86 ( V_51 ) ) |
V_127 ) ;
V_126 &= ~ V_122 ;
V_126 |= V_106 ;
}
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 -> V_55 -> V_84 > 24 ) {
V_126 &= ~ V_122 ;
V_126 |= V_105 ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( F_86 ( V_51 ) ,
F_6 ( F_86 ( V_51 ) ) &
~ V_127 ) ;
}
if ( V_49 -> V_55 -> V_120 )
F_80 ( V_13 ) ;
}
static void F_87 ( struct V_97 * V_13 )
{
}
static void F_88 ( struct V_97 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
T_2 V_126 ;
V_126 = F_6 ( V_2 -> V_11 ) ;
V_126 &= ~ ( V_10 | V_119 ) ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_89 ( V_4 ) && V_49 -> V_51 == V_128 ) {
V_126 &= ~ V_129 ;
V_126 |= V_10 ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
V_126 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_126 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_2 -> V_130 ( & V_13 -> V_3 , false , NULL ) ;
}
static void F_90 ( struct V_97 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_55 -> V_120 )
F_91 ( V_13 ) ;
F_88 ( V_13 ) ;
}
static void F_92 ( struct V_97 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_55 -> V_120 )
F_91 ( V_13 ) ;
}
static void F_93 ( struct V_97 * V_13 )
{
F_88 ( V_13 ) ;
}
static int F_94 ( struct V_2 * V_16 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_131 && ! V_16 -> V_107 ) || F_95 ( V_4 ) )
return 165000 ;
else if ( F_96 ( V_4 ) || F_97 ( V_4 ) -> V_132 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_133
F_98 ( struct V_2 * V_16 ,
int clock , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( clock < 25000 )
return V_134 ;
if ( clock > F_94 ( V_16 , V_131 ) )
return V_135 ;
if ( F_99 ( V_4 ) && clock > 223333 && clock < 240000 )
return V_136 ;
if ( F_69 ( V_4 ) && clock > 216000 && clock < 240000 )
return V_136 ;
return V_137 ;
}
static enum V_133
F_100 ( struct V_17 * V_18 ,
struct V_64 * V_85 )
{
struct V_2 * V_16 = F_9 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_16 ) ;
enum V_133 V_138 ;
int clock ;
if ( V_85 -> V_93 & V_139 )
return V_140 ;
clock = V_85 -> clock ;
if ( V_85 -> V_93 & V_141 )
clock *= 2 ;
V_138 = F_98 ( V_16 , clock , true ) ;
if ( ! F_101 ( V_4 ) && V_138 != V_137 )
V_138 = F_98 ( V_16 , clock * 3 / 2 , true ) ;
return V_138 ;
}
static bool F_102 ( struct V_112 * V_142 )
{
struct V_1 * V_4 = V_142 -> V_3 . V_49 -> V_4 ;
struct V_143 * V_144 ;
struct V_97 * V_13 ;
struct V_17 * V_18 ;
struct V_145 * V_146 ;
int V_147 = 0 , V_148 = 0 ;
int V_39 ;
if ( F_101 ( V_4 ) )
return false ;
V_144 = V_142 -> V_3 . V_144 ;
F_103 (state, connector, connector_state, i) {
if ( V_146 -> V_49 != V_142 -> V_3 . V_49 )
continue;
V_13 = F_104 ( V_146 -> V_149 ) ;
V_148 += V_13 -> type == V_150 ;
V_147 ++ ;
}
return V_148 > 0 && V_148 == V_147 ;
}
bool F_105 ( struct V_97 * V_13 ,
struct V_112 * V_113 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_64 * V_65 = & V_113 -> V_3 . V_65 ;
int V_151 = V_113 -> V_3 . V_65 . V_125 ;
int V_152 = V_151 * 3 / 2 ;
int V_153 ;
V_113 -> V_107 = V_2 -> V_107 ;
if ( V_113 -> V_107 )
V_113 -> V_118 = true ;
if ( V_2 -> V_154 ) {
if ( V_113 -> V_107 &&
F_106 ( V_65 ) > 1 )
V_2 -> V_100 = V_121 ;
else
V_2 -> V_100 = 0 ;
}
if ( V_65 -> V_93 & V_141 ) {
V_113 -> V_124 = 2 ;
V_151 *= 2 ;
V_152 *= 2 ;
}
if ( V_2 -> V_100 )
V_113 -> V_71 = true ;
if ( F_60 ( V_4 ) && ! F_4 ( V_4 ) )
V_113 -> V_155 = true ;
if ( V_113 -> V_107 && V_2 -> V_120 )
V_113 -> V_120 = true ;
if ( V_113 -> V_84 > 8 * 3 && V_113 -> V_107 &&
F_98 ( V_2 , V_152 , false ) == V_137 &&
F_102 ( V_113 ) ) {
F_50 ( L_12 ) ;
V_153 = 12 * 3 ;
V_113 -> V_123 = V_152 ;
} else {
F_50 ( L_13 ) ;
V_153 = 8 * 3 ;
V_113 -> V_123 = V_151 ;
}
if ( ! V_113 -> V_156 ) {
F_50 ( L_14 , V_153 ) ;
V_113 -> V_84 = V_153 ;
}
if ( F_98 ( V_2 , V_113 -> V_123 ,
false ) != V_137 ) {
F_50 ( L_15 ) ;
return false ;
}
return true ;
}
static void
F_107 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_107 = false ;
V_2 -> V_120 = false ;
V_2 -> V_70 = false ;
F_108 ( F_109 ( V_18 ) -> V_157 ) ;
F_109 ( V_18 ) -> V_157 = NULL ;
}
static bool
F_110 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_111 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_97 * V_97 =
& F_2 ( V_2 ) -> V_3 ;
enum V_109 V_110 ;
struct V_158 * V_158 ;
bool V_159 = false ;
V_110 = F_73 ( V_97 ) ;
F_112 ( V_6 , V_110 ) ;
V_158 = F_113 ( V_18 ,
F_114 ( V_6 ,
V_2 -> V_160 ) ) ;
F_115 ( V_6 , V_110 ) ;
F_109 ( V_18 ) -> V_157 = V_158 ;
if ( V_158 && V_158 -> V_161 & V_162 ) {
V_2 -> V_70 =
F_116 ( V_158 ) ;
V_2 -> V_120 = F_117 ( V_158 ) ;
if ( V_2 -> V_163 != V_164 )
V_2 -> V_120 =
V_2 -> V_163 == V_165 ;
if ( V_2 -> V_163 != V_166 )
V_2 -> V_107 =
F_118 ( V_158 ) ;
V_159 = true ;
}
return V_159 ;
}
static enum V_167
F_119 ( struct V_17 * V_18 , bool V_168 )
{
enum V_167 V_138 ;
F_50 ( L_16 ,
V_18 -> V_3 . V_169 , V_18 -> V_170 ) ;
F_107 ( V_18 ) ;
if ( F_110 ( V_18 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_150 ;
V_138 = V_171 ;
} else
V_138 = V_172 ;
return V_138 ;
}
static void
F_120 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_50 ( L_16 ,
V_18 -> V_3 . V_169 , V_18 -> V_170 ) ;
F_107 ( V_18 ) ;
if ( V_18 -> V_138 != V_171 )
return;
F_110 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_150 ;
}
static int F_121 ( struct V_17 * V_18 )
{
struct V_158 * V_158 ;
V_158 = F_109 ( V_18 ) -> V_157 ;
if ( V_158 == NULL )
return 0 ;
return F_122 ( V_18 , V_158 ) ;
}
static bool
F_123 ( struct V_17 * V_18 )
{
bool V_120 = false ;
struct V_158 * V_158 ;
V_158 = F_109 ( V_18 ) -> V_157 ;
if ( V_158 && V_158 -> V_161 & V_162 )
V_120 = F_117 ( V_158 ) ;
return V_120 ;
}
static int
F_124 ( struct V_17 * V_18 ,
struct V_173 * V_174 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_66 ;
V_66 = F_125 ( & V_18 -> V_3 , V_174 , V_37 ) ;
if ( V_66 )
return V_66 ;
if ( V_174 == V_6 -> V_175 ) {
enum V_176 V_39 = V_37 ;
bool V_120 ;
if ( V_39 == V_2 -> V_163 )
return 0 ;
V_2 -> V_163 = V_39 ;
if ( V_39 == V_164 )
V_120 = F_123 ( V_18 ) ;
else
V_120 = ( V_39 == V_165 ) ;
if ( V_39 == V_166 )
V_2 -> V_107 = 0 ;
V_2 -> V_120 = V_120 ;
goto V_177;
}
if ( V_174 == V_6 -> V_178 ) {
bool V_179 = V_2 -> V_154 ;
T_1 V_180 = V_2 -> V_100 ;
switch ( V_37 ) {
case V_181 :
V_2 -> V_154 = true ;
break;
case V_182 :
V_2 -> V_154 = false ;
V_2 -> V_100 = 0 ;
break;
case V_183 :
V_2 -> V_154 = false ;
V_2 -> V_100 = V_121 ;
break;
default:
return - V_184 ;
}
if ( V_179 == V_2 -> V_154 &&
V_180 == V_2 -> V_100 )
return 0 ;
goto V_177;
}
if ( V_174 == V_18 -> V_4 -> V_80 . V_185 ) {
switch ( V_37 ) {
case V_186 :
V_2 -> V_68 = V_187 ;
break;
case V_188 :
V_2 -> V_68 = V_189 ;
break;
case V_190 :
V_2 -> V_68 = V_191 ;
break;
default:
return - V_184 ;
}
goto V_177;
}
return - V_184 ;
V_177:
if ( V_15 -> V_3 . V_3 . V_49 )
F_126 ( V_15 -> V_3 . V_3 . V_49 ) ;
return 0 ;
}
static void F_127 ( struct V_97 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_64 * V_65 =
& V_48 -> V_55 -> V_3 . V_65 ;
F_66 ( V_13 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_48 -> V_55 -> V_107 ,
V_65 ) ;
}
static void F_128 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_192 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_64 * V_65 =
& V_48 -> V_55 -> V_3 . V_65 ;
enum V_193 V_47 = F_129 ( V_192 ) ;
int V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_130 ( & V_6 -> V_194 ) ;
V_37 = F_131 ( V_6 , V_51 , F_132 ( V_47 ) ) ;
V_37 = 0 ;
if ( V_51 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_133 ( V_6 , V_51 , F_134 ( V_47 ) , V_37 ) ;
F_133 ( V_6 , V_51 , F_135 ( V_47 ) , 0 ) ;
F_133 ( V_6 , V_51 , F_136 ( V_47 ) , 0x2b245f5f ) ;
F_133 ( V_6 , V_51 , F_137 ( V_47 ) , 0x5578b83a ) ;
F_133 ( V_6 , V_51 , F_138 ( V_47 ) , 0x0c782040 ) ;
F_133 ( V_6 , V_51 , F_139 ( V_47 ) , 0x2b247878 ) ;
F_133 ( V_6 , V_51 , F_140 ( V_47 ) , 0x00030000 ) ;
F_133 ( V_6 , V_51 , F_141 ( V_47 ) , 0x00002000 ) ;
F_133 ( V_6 , V_51 , F_135 ( V_47 ) , V_195 ) ;
F_133 ( V_6 , V_51 , F_142 ( V_47 ) , 0x00760018 ) ;
F_133 ( V_6 , V_51 , F_143 ( V_47 ) , 0x00400888 ) ;
F_144 ( & V_6 -> V_194 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_48 -> V_55 -> V_107 ,
V_65 ) ;
F_83 ( V_13 ) ;
F_145 ( V_6 , V_192 , 0x0 ) ;
}
static void F_146 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_193 V_47 = F_129 ( V_192 ) ;
int V_51 = V_48 -> V_51 ;
F_66 ( V_13 ) ;
F_130 ( & V_6 -> V_194 ) ;
F_133 ( V_6 , V_51 , F_147 ( V_47 ) ,
V_196 |
V_197 ) ;
F_133 ( V_6 , V_51 , F_148 ( V_47 ) ,
V_198 |
V_199 |
( 1 << V_200 ) |
V_201 ) ;
F_133 ( V_6 , V_51 , F_149 ( V_47 ) , 0x00750f00 ) ;
F_133 ( V_6 , V_51 , F_150 ( V_47 ) , 0x00001500 ) ;
F_133 ( V_6 , V_51 , F_151 ( V_47 ) , 0x40400000 ) ;
F_133 ( V_6 , V_51 , F_141 ( V_47 ) , 0x00002000 ) ;
F_133 ( V_6 , V_51 , F_135 ( V_47 ) , V_195 ) ;
F_144 ( & V_6 -> V_194 ) ;
}
static void F_152 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_193 V_202 = F_129 ( V_192 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_66 ( V_13 ) ;
F_130 ( & V_6 -> V_194 ) ;
if ( V_51 != V_128 ) {
V_37 = F_131 ( V_6 , V_51 , V_203 ) ;
V_37 &= ~ ( V_204 | V_205 ) ;
if ( V_202 == V_206 )
V_37 |= V_207 ;
if ( V_202 == V_208 )
V_37 |= V_209 ;
F_133 ( V_6 , V_51 , V_203 , V_37 ) ;
} else {
V_37 = F_131 ( V_6 , V_51 , V_210 ) ;
V_37 &= ~ ( V_211 | V_212 ) ;
if ( V_202 == V_206 )
V_37 |= V_213 ;
if ( V_202 == V_208 )
V_37 |= V_214 ;
F_133 ( V_6 , V_51 , V_210 , V_37 ) ;
}
V_37 = F_131 ( V_6 , V_51 , F_132 ( V_202 ) ) ;
V_37 |= V_215 ;
if ( V_51 != V_128 )
V_37 &= ~ V_216 ;
else
V_37 |= V_216 ;
F_133 ( V_6 , V_51 , F_132 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_153 ( V_202 ) ) ;
V_37 |= V_215 ;
if ( V_51 != V_128 )
V_37 &= ~ V_216 ;
else
V_37 |= V_216 ;
F_133 ( V_6 , V_51 , F_153 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_154 ( V_202 ) ) ;
if ( V_51 != V_128 )
V_37 &= ~ V_217 ;
else
V_37 |= V_217 ;
F_133 ( V_6 , V_51 , F_154 ( V_202 ) , V_37 ) ;
F_144 ( & V_6 -> V_194 ) ;
}
static void F_155 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_193 V_47 = F_129 ( V_192 ) ;
int V_51 = V_48 -> V_51 ;
F_130 ( & V_6 -> V_194 ) ;
F_133 ( V_6 , V_51 , F_147 ( V_47 ) , 0x00000000 ) ;
F_133 ( V_6 , V_51 , F_148 ( V_47 ) , 0x00e00060 ) ;
F_144 ( & V_6 -> V_194 ) ;
}
static void F_156 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_193 V_202 = F_129 ( V_192 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_130 ( & V_6 -> V_194 ) ;
V_37 = F_131 ( V_6 , V_51 , F_157 ( V_202 ) ) ;
V_37 |= V_218 ;
F_133 ( V_6 , V_51 , F_157 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_158 ( V_202 ) ) ;
V_37 |= V_218 ;
F_133 ( V_6 , V_51 , F_158 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_159 ( V_202 ) ) ;
V_37 &= ~ ( V_196 | V_197 ) ;
F_133 ( V_6 , V_51 , F_159 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_160 ( V_202 ) ) ;
V_37 &= ~ ( V_196 | V_197 ) ;
F_133 ( V_6 , V_51 , F_160 ( V_202 ) , V_37 ) ;
F_144 ( & V_6 -> V_194 ) ;
}
static void F_161 ( struct V_97 * V_13 )
{
struct V_14 * V_192 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_192 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_64 * V_65 =
& V_48 -> V_55 -> V_3 . V_65 ;
enum V_193 V_202 = F_129 ( V_192 ) ;
int V_51 = V_48 -> V_51 ;
int V_36 , V_39 , V_219 ;
T_2 V_37 ;
F_130 ( & V_6 -> V_194 ) ;
V_37 = F_131 ( V_6 , V_51 , F_162 ( V_202 ) ) ;
V_37 &= ~ V_220 ;
F_133 ( V_6 , V_51 , F_162 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_163 ( V_202 ) ) ;
V_37 &= ~ V_220 ;
F_133 ( V_6 , V_51 , F_163 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_157 ( V_202 ) ) ;
V_37 |= V_218 ;
F_133 ( V_6 , V_51 , F_157 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_158 ( V_202 ) ) ;
V_37 |= V_218 ;
F_133 ( V_6 , V_51 , F_158 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_159 ( V_202 ) ) ;
V_37 |= ( V_196 | V_197 ) ;
F_133 ( V_6 , V_51 , F_159 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_160 ( V_202 ) ) ;
V_37 |= ( V_196 | V_197 ) ;
F_133 ( V_6 , V_51 , F_160 ( V_202 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_36 = ( V_39 == 1 ) ? 0x0 : 0x1 ;
F_133 ( V_6 , V_51 , F_164 ( V_202 , V_39 ) ,
V_36 << V_221 ) ;
}
if ( V_48 -> V_55 -> V_123 > 270000 )
V_219 = 0x18 ;
else if ( V_48 -> V_55 -> V_123 > 135000 )
V_219 = 0xd ;
else if ( V_48 -> V_55 -> V_123 > 67500 )
V_219 = 0x7 ;
else if ( V_48 -> V_55 -> V_123 > 33750 )
V_219 = 0x4 ;
else
V_219 = 0x2 ;
V_37 = F_131 ( V_6 , V_51 , F_162 ( V_202 ) ) ;
V_37 |= F_165 ( 0x1f ) ;
F_133 ( V_6 , V_51 , F_162 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_163 ( V_202 ) ) ;
V_37 |= F_165 ( 0x1f ) ;
F_133 ( V_6 , V_51 , F_163 ( V_202 ) , V_37 ) ;
F_133 ( V_6 , V_51 , F_166 ( V_202 ) ,
F_167 ( V_219 ) |
V_222 |
F_168 ( 0x1f ) |
F_169 ( 6 ) |
F_170 ( 0 ) ) ;
F_133 ( V_6 , V_51 , F_171 ( V_202 ) ,
F_167 ( V_219 ) |
V_222 |
F_168 ( 0x1f ) |
F_169 ( 7 ) |
F_170 ( 5 ) ) ;
V_37 = F_131 ( V_6 , V_51 , F_172 ( V_202 ) ) ;
V_37 &= ~ ( V_223 | V_224 ) ;
V_37 &= ~ ( V_225 | V_226 ) ;
V_37 |= V_227 | V_228 ;
F_133 ( V_6 , V_51 , F_172 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_173 ( V_202 ) ) ;
V_37 &= ~ ( V_223 | V_224 ) ;
V_37 &= ~ ( V_225 | V_226 ) ;
V_37 |= V_227 | V_228 ;
F_133 ( V_6 , V_51 , F_173 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_174 ( V_202 ) ) ;
V_37 &= ~ ( V_229 | V_230 ) ;
V_37 |= V_231 | V_232 ;
F_133 ( V_6 , V_51 , F_174 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_175 ( V_202 ) ) ;
V_37 &= ~ ( V_229 | V_230 ) ;
V_37 |= V_231 | V_232 ;
F_133 ( V_6 , V_51 , F_175 ( V_202 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_131 ( V_6 , V_51 , F_176 ( V_202 , V_39 ) ) ;
V_37 &= ~ V_233 ;
V_37 |= 128 << V_234 ;
F_133 ( V_6 , V_51 , F_176 ( V_202 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_131 ( V_6 , V_51 , F_177 ( V_202 , V_39 ) ) ;
V_37 &= ~ V_235 ;
V_37 |= 102 << V_236 ;
F_133 ( V_6 , V_51 , F_177 ( V_202 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_131 ( V_6 , V_51 , F_178 ( V_202 , V_39 ) ) ;
V_37 &= ~ V_237 ;
F_133 ( V_6 , V_51 , F_178 ( V_202 , V_39 ) , V_37 ) ;
}
#if 0
val = vlv_dpio_read(dev_priv, pipe, VLV_TX_DW3(ch));
if (ch)
val |= DPIO_TX_UNIQ_TRANS_SCALE_CH1;
else
val |= DPIO_TX_UNIQ_TRANS_SCALE_CH0;
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW3(ch), val);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW2(ch),
vlv_dpio_read(dev_priv, pipe, VLV_TX_DW2(ch)) |
(0x9a << DPIO_UNIQ_TRANS_SCALE_SHIFT));
#endif
V_37 = F_131 ( V_6 , V_51 , F_172 ( V_202 ) ) ;
V_37 |= V_223 | V_224 ;
F_133 ( V_6 , V_51 , F_172 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , F_173 ( V_202 ) ) ;
V_37 |= V_223 | V_224 ;
F_133 ( V_6 , V_51 , F_173 ( V_202 ) , V_37 ) ;
V_37 = F_131 ( V_6 , V_51 , V_238 ) ;
V_37 |= V_239 ;
F_133 ( V_6 , V_51 , V_238 , V_37 ) ;
F_144 ( & V_6 -> V_194 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_48 -> V_55 -> V_107 ,
V_65 ) ;
F_83 ( V_13 ) ;
F_145 ( V_6 , V_192 , 0x0 ) ;
}
static void F_179 ( struct V_17 * V_18 )
{
F_108 ( F_109 ( V_18 ) -> V_157 ) ;
F_180 ( V_18 ) ;
F_108 ( V_18 ) ;
}
static void
F_181 ( struct V_17 * V_18 )
{
if ( ! F_182 ( V_18 -> V_4 ) )
F_183 ( & V_18 -> V_3 ,
V_18 -> V_4 -> V_80 . V_185 ,
V_186 ) ;
}
static void
F_184 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_185 ( V_18 ) ;
F_186 ( V_18 ) ;
V_2 -> V_154 = true ;
F_181 ( V_18 ) ;
V_2 -> V_68 = V_187 ;
}
void F_187 ( struct V_14 * V_15 ,
struct V_240 * V_240 )
{
struct V_17 * V_18 = & V_240 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_97 * V_97 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_97 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_47 V_47 = V_15 -> V_47 ;
T_4 V_241 ;
F_188 ( V_4 , V_18 , & V_242 ,
V_243 ) ;
F_189 ( V_18 , & V_244 ) ;
V_18 -> V_245 = 1 ;
V_18 -> V_246 = 0 ;
V_18 -> V_247 = 1 ;
switch ( V_47 ) {
case V_248 :
if ( F_99 ( V_6 ) )
V_2 -> V_160 = V_249 ;
else
V_2 -> V_160 = V_250 ;
V_97 -> V_251 = V_252 ;
break;
case V_253 :
if ( F_99 ( V_6 ) )
V_2 -> V_160 = V_254 ;
else
V_2 -> V_160 = V_255 ;
V_97 -> V_251 = V_256 ;
break;
case V_257 :
if ( F_52 ( F_99 ( V_6 ) ) )
V_2 -> V_160 = V_258 ;
else if ( F_69 ( V_6 ) )
V_2 -> V_160 = V_259 ;
else
V_2 -> V_160 = V_260 ;
V_97 -> V_251 = V_261 ;
break;
case V_262 :
V_241 =
V_6 -> V_263 . V_264 [ V_262 ] . V_241 ;
switch ( V_241 ) {
case V_265 :
V_2 -> V_160 = V_250 ;
break;
case V_266 :
V_2 -> V_160 = V_255 ;
break;
case V_267 :
V_2 -> V_160 = V_260 ;
break;
default:
F_190 ( V_241 ) ;
}
V_97 -> V_251 = V_268 ;
break;
case V_269 :
V_97 -> V_251 = V_270 ;
default:
F_191 () ;
}
if ( F_58 ( V_4 ) ) {
V_2 -> V_62 = F_33 ;
V_2 -> V_130 = F_64 ;
V_2 -> V_117 = F_36 ;
} else if ( F_95 ( V_4 ) ) {
V_2 -> V_62 = F_19 ;
V_2 -> V_130 = F_49 ;
V_2 -> V_117 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_62 = F_37 ;
V_2 -> V_130 = F_65 ;
V_2 -> V_117 = F_39 ;
} else if ( F_89 ( V_4 ) ) {
V_2 -> V_62 = F_26 ;
V_2 -> V_130 = F_62 ;
V_2 -> V_117 = F_30 ;
} else {
V_2 -> V_62 = F_31 ;
V_2 -> V_130 = F_63 ;
V_2 -> V_117 = F_32 ;
}
if ( F_4 ( V_4 ) )
V_240 -> V_271 = V_272 ;
else
V_240 -> V_271 = V_273 ;
V_240 -> V_274 = V_275 ;
F_184 ( V_2 , V_18 ) ;
F_192 ( V_240 , V_97 ) ;
F_193 ( V_18 ) ;
if ( F_95 ( V_4 ) && ! F_194 ( V_4 ) ) {
T_2 V_126 = F_6 ( V_276 ) ;
F_20 ( V_276 , ( V_126 & ~ 0xf ) | 0xd ) ;
}
}
void F_195 ( struct V_1 * V_4 , int V_11 , enum V_47 V_47 )
{
struct V_14 * V_15 ;
struct V_97 * V_97 ;
struct V_240 * V_240 ;
V_15 = F_196 ( sizeof( * V_15 ) , V_277 ) ;
if ( ! V_15 )
return;
V_240 = F_197 () ;
if ( ! V_240 ) {
F_108 ( V_15 ) ;
return;
}
V_97 = & V_15 -> V_3 ;
F_198 ( V_4 , & V_97 -> V_3 , & V_278 ,
V_279 ) ;
V_97 -> V_280 = F_105 ;
if ( F_60 ( V_4 ) ) {
V_97 -> V_281 = F_92 ;
V_97 -> V_282 = F_93 ;
} else {
V_97 -> V_281 = F_90 ;
}
V_97 -> V_271 = F_72 ;
V_97 -> V_283 = F_78 ;
if ( F_69 ( V_4 ) ) {
V_97 -> V_284 = F_152 ;
V_97 -> V_285 = F_161 ;
V_97 -> V_79 = F_87 ;
V_97 -> V_282 = F_156 ;
} else if ( F_58 ( V_4 ) ) {
V_97 -> V_284 = F_146 ;
V_97 -> V_285 = F_128 ;
V_97 -> V_79 = F_87 ;
V_97 -> V_282 = F_155 ;
} else {
V_97 -> V_285 = F_127 ;
if ( F_67 ( V_4 ) )
V_97 -> V_79 = F_85 ;
else if ( F_89 ( V_4 ) )
V_97 -> V_79 = F_84 ;
else
V_97 -> V_79 = F_83 ;
}
V_97 -> type = V_150 ;
if ( F_69 ( V_4 ) ) {
if ( V_47 == V_257 )
V_97 -> V_286 = 1 << 2 ;
else
V_97 -> V_286 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_97 -> V_286 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_97 -> V_287 = 1 << V_288 ;
if ( F_95 ( V_4 ) )
V_97 -> V_287 |= 1 << V_150 ;
V_15 -> V_47 = V_47 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_289 . V_290 = 0 ;
F_187 ( V_15 , V_240 ) ;
}
