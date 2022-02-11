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
int V_14 = V_15 ;
V_6 V_16 = F_6 ( V_17 , V_18 ) ;
V_13 = F_7 ( V_19 ) ;
V_13 = F_8 ( V_13 , V_17 , V_20 , 1 ) ;
F_9 ( V_19 , V_13 ) ;
V_13 = F_7 ( V_19 ) ;
while ( V_13 & V_16 ) {
if ( V_14 <= 0 ) {
F_10 ( L_2 ) ;
break;
}
F_11 ( 1 ) ;
V_14 -= 1 ;
V_13 = F_7 ( V_19 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , bool V_21 )
{
V_6 V_13 ;
V_13 = F_7 ( V_19 ) ;
V_13 = F_8 ( V_13 , V_17 ,
V_22 , V_21 ? 1 : 0 ) ;
F_9 ( V_19 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_23 V_24 )
{
V_6 V_13 ;
V_13 = F_7 ( V_25 ) ;
V_13 = F_8 ( V_13 , V_26 ,
V_27 , V_24 ) ;
F_9 ( V_25 , V_13 ) ;
F_12 ( V_2 , true ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_28 V_29 )
{
V_6 V_13 ;
V_6 V_16 = F_6 ( V_17 , V_18 ) ;
if ( V_29 != V_30 ) {
V_13 = F_7 ( V_19 ) ;
if ( ! ( V_13 & V_16 ) )
return - V_31 ;
}
V_13 = F_7 ( V_32 ) ;
if ( V_13 != V_29 )
return - V_31 ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_33 = 0 , V_14 = V_15 ;
V_6 V_16 = F_6 ( V_17 , V_34 ) ;
V_6 V_13 ;
V_13 = F_7 ( V_19 ) ;
while ( ! ( V_13 & V_16 ) ) {
if ( V_14 <= 0 ) {
F_10 ( L_3 ) ;
V_33 = - V_35 ;
break;
}
F_16 ( 1 ) ;
V_14 -= 1 ;
V_13 = F_7 ( V_19 ) ;
}
return V_33 ;
}
static int F_17 ( struct V_1 * V_2 , enum V_28 V_29 )
{
int V_33 = 0 , V_14 = V_15 ;
V_33 = F_14 ( V_2 , V_29 ) ;
while ( V_33 ) {
if ( V_14 <= 0 ) {
F_10 ( L_3 ) ;
V_33 = - V_35 ;
break;
}
F_16 ( 1 ) ;
V_14 -= 1 ;
V_33 = F_14 ( V_2 , V_29 ) ;
}
return V_33 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_23 V_36 )
{
int V_33 ;
F_13 ( V_2 , V_36 ) ;
V_33 = F_15 ( V_2 ) ;
if ( V_33 )
return V_33 ;
F_12 ( V_2 , false ) ;
if ( V_36 == V_37 ||
V_36 == V_38 ||
V_36 == V_39 ) {
V_33 = F_17 ( V_2 , V_40 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_18 ( V_2 , V_39 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
bool V_41 )
{
enum V_23 V_24 ;
V_24 = V_41 ? V_37 : V_38 ;
return F_18 ( V_2 , V_24 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
bool V_41 )
{
enum V_23 V_24 ;
int V_33 = 0 ;
V_24 = V_41 ? V_42 : V_43 ;
V_33 = F_18 ( V_2 , V_24 ) ;
return V_33 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
F_23 ( L_4 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_44 * V_48 ,
unsigned type ,
enum V_49 V_50 )
{
V_6 V_51 = F_7 ( V_52 ) ;
V_51 = F_8 ( V_51 , V_53 , V_54 ,
( V_50 == V_55 ) ? 1 : 0 ) ;
F_9 ( V_52 , V_51 ) ;
return 0 ;
}
static void F_25 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_57 , struct V_58 , V_60 ) ;
struct V_1 * V_2 = F_26 ( V_59 , struct V_1 , V_59 ) ;
if ( F_17 ( V_2 , V_30 ) ) {
F_10 ( L_5 ) ;
return;
}
F_27 ( V_2 , false ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_44 * V_48 ,
unsigned type ,
enum V_49 V_50 )
{
V_6 V_51 = F_7 ( V_52 ) ;
V_51 = F_8 ( V_51 , V_53 , V_61 ,
( V_50 == V_55 ) ? 1 : 0 ) ;
F_9 ( V_52 , V_51 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
int V_33 ;
V_33 = F_14 ( V_2 , V_62 ) ;
if ( ! V_33 )
F_30 ( & V_2 -> V_59 . V_60 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_59 . V_63 . V_64 = 1 ;
V_2 -> V_59 . V_63 . V_65 = & V_66 ;
V_2 -> V_59 . V_67 . V_64 = 1 ;
V_2 -> V_59 . V_67 . V_65 = & V_68 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_33 ( V_2 , V_69 , 135 , & V_2 -> V_59 . V_67 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_33 ( V_2 , V_69 , 138 , & V_2 -> V_59 . V_63 ) ;
if ( V_33 ) {
F_34 ( V_2 , & V_2 -> V_59 . V_67 , 0 ) ;
return V_33 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_36 ( V_2 , & V_2 -> V_59 . V_67 , 0 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_36 ( V_2 , & V_2 -> V_59 . V_63 , 0 ) ;
if ( V_33 ) {
F_34 ( V_2 , & V_2 -> V_59 . V_67 , 0 ) ;
return V_33 ;
}
F_37 ( & V_2 -> V_59 . V_60 , F_25 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_34 ( V_2 , & V_2 -> V_59 . V_63 , 0 ) ;
F_34 ( V_2 , & V_2 -> V_59 . V_67 , 0 ) ;
}
