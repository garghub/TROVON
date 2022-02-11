void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
F_2 ( V_2 ,
V_5 ,
( const V_6 ) F_3 (
V_5 ) ) ;
F_2 ( V_2 ,
V_7 ,
( const V_6 ) F_3 (
V_7 ) ) ;
F_2 ( V_2 ,
V_8 ,
( const V_6 ) F_3 (
V_8 ) ) ;
break;
case V_9 :
F_2 ( V_2 ,
V_10 ,
( const V_6 ) F_3 (
V_10 ) ) ;
F_2 ( V_2 ,
V_11 ,
( const V_6 ) F_3 (
V_11 ) ) ;
F_2 ( V_2 ,
V_12 ,
( const V_6 ) F_3 (
V_12 ) ) ;
break;
default:
F_4 ( L_1 ) ;
break;
}
}
static void F_5 ( struct V_1 * V_2 )
{
V_6 V_13 ;
V_13 = F_6 ( V_14 ) ;
V_13 = F_7 ( V_13 , V_15 , V_16 , 1 ) ;
F_8 ( V_14 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 , bool V_17 )
{
V_6 V_13 ;
V_13 = F_6 ( V_14 ) ;
V_13 = F_7 ( V_13 , V_15 ,
V_18 , V_17 ? 1 : 0 ) ;
F_8 ( V_14 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
V_6 V_13 ;
V_13 = F_6 ( V_21 ) ;
V_13 = F_7 ( V_13 , V_22 ,
V_23 , V_20 ) ;
F_8 ( V_21 , V_13 ) ;
F_9 ( V_2 , true ) ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
V_6 V_13 ;
V_13 = F_6 ( V_24 ) ;
if ( V_13 != V_20 )
return - V_25 ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_26 = 0 , V_27 = V_28 ;
V_6 V_29 = F_13 ( V_15 , V_30 ) ;
V_6 V_13 ;
V_13 = F_6 ( V_14 ) ;
while ( ! ( V_13 & V_29 ) ) {
if ( V_27 <= 0 ) {
F_14 ( L_2 ) ;
V_26 = - V_31 ;
break;
}
F_15 ( 1 ) ;
V_27 -= 1 ;
V_13 = F_6 ( V_14 ) ;
}
return V_26 ;
}
static int F_16 ( struct V_1 * V_2 , enum V_19 V_20 )
{
int V_26 = 0 , V_27 = V_28 ;
V_26 = F_11 ( V_2 , V_20 ) ;
while ( V_26 ) {
if ( V_27 <= 0 ) {
F_14 ( L_2 ) ;
V_26 = - V_31 ;
break;
}
F_15 ( 1 ) ;
V_27 -= 1 ;
V_26 = F_11 ( V_2 , V_20 ) ;
}
return V_26 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
int V_26 ;
F_10 ( V_2 , V_33 ) ;
V_26 = F_12 ( V_2 ) ;
if ( V_26 )
return V_26 ;
F_9 ( V_2 , false ) ;
if ( V_33 == V_34 ) {
V_26 = F_16 ( V_2 , V_35 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_36 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
bool V_37 )
{
enum V_19 V_20 ;
V_20 = V_37 ? V_34 : V_38 ;
return F_17 ( V_2 , V_20 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
bool V_37 )
{
enum V_19 V_20 ;
int V_26 = 0 ;
V_20 = V_37 ? V_39 : V_40 ;
V_26 = F_17 ( V_2 , V_20 ) ;
return V_26 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
F_22 ( L_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_41 * V_45 ,
unsigned type ,
enum V_46 V_47 )
{
V_6 V_48 = F_6 ( V_49 ) ;
V_48 = F_7 ( V_48 , V_50 , V_51 ,
( V_47 == V_52 ) ? 1 : 0 ) ;
F_8 ( V_49 , V_48 ) ;
return 0 ;
}
static void F_24 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_25 ( V_54 ,
struct V_55 , V_57 . V_54 ) ;
struct V_1 * V_2 = F_25 ( V_56 ,
struct V_1 , V_56 ) ;
int V_26 = 0 ;
V_26 = F_16 ( V_2 , V_58 ) ;
if ( V_26 )
F_26 ( L_4 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_41 * V_45 ,
unsigned type ,
enum V_46 V_47 )
{
V_6 V_48 = F_6 ( V_49 ) ;
V_48 = F_7 ( V_48 , V_50 , V_59 ,
( V_47 == V_52 ) ? 1 : 0 ) ;
F_8 ( V_49 , V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
int V_26 ;
V_2 -> V_56 . V_60 &= ~ V_61 ;
V_26 = F_11 ( V_2 , V_62 ) ;
if ( V_26 )
return 0 ;
F_29 ( & V_2 -> V_56 . V_57 ,
F_30 ( V_63 ) ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_56 . V_64 . V_65 = 1 ;
V_2 -> V_56 . V_64 . V_66 = & V_67 ;
V_2 -> V_56 . V_68 . V_65 = 1 ;
V_2 -> V_56 . V_68 . V_66 = & V_69 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_33 ( V_2 , 135 , & V_2 -> V_56 . V_68 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_33 ( V_2 , 138 , & V_2 -> V_56 . V_64 ) ;
if ( V_26 ) {
F_34 ( V_2 , & V_2 -> V_56 . V_68 , 0 ) ;
return V_26 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_36 ( V_2 , & V_2 -> V_56 . V_68 , 0 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_36 ( V_2 , & V_2 -> V_56 . V_64 , 0 ) ;
if ( V_26 ) {
F_34 ( V_2 , & V_2 -> V_56 . V_68 , 0 ) ;
return V_26 ;
}
F_37 ( & V_2 -> V_56 . V_57 , F_24 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_56 . V_57 ) ;
F_34 ( V_2 , & V_2 -> V_56 . V_64 , 0 ) ;
F_34 ( V_2 , & V_2 -> V_56 . V_68 , 0 ) ;
}
