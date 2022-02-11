static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = V_5 ;
T_1 V_6 = F_2 ( V_7 , V_8 ) ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
V_3 = F_5 ( V_3 , V_7 , V_11 , 1 ) ;
F_6 ( F_4 ( V_9 , 0 ,
V_10 ) , V_3 ) ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
while ( V_3 & V_6 ) {
if ( V_4 <= 0 ) {
F_7 ( L_1 ) ;
break;
}
F_8 ( 1 ) ;
V_4 -= 1 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 , bool V_12 )
{
T_1 V_3 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
V_3 = F_5 ( V_3 , V_7 ,
V_13 , V_12 ? 1 : 0 ) ;
F_6 ( F_4 ( V_9 , 0 , V_10 ) ,
V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
T_1 V_3 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_16 ) ) ;
V_3 = F_5 ( V_3 , V_17 ,
V_18 , V_15 ) ;
F_6 ( F_4 ( V_9 , 0 , V_16 ) ,
V_3 ) ;
F_9 ( V_2 , true ) ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
T_1 V_3 ;
T_1 V_6 = F_2 ( V_7 , V_8 ) ;
if ( V_20 != V_21 ) {
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
if ( ! ( V_3 & V_6 ) )
return - V_22 ;
}
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_23 ) ) ;
if ( V_3 != V_20 )
return - V_22 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_24 = 0 , V_4 = V_5 ;
T_1 V_6 = F_2 ( V_7 , V_25 ) ;
T_1 V_3 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
while ( ! ( V_3 & V_6 ) ) {
if ( V_4 <= 0 ) {
F_7 ( L_2 ) ;
V_24 = - V_26 ;
break;
}
F_8 ( 5 ) ;
V_4 -= 5 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
}
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 , enum V_19 V_20 )
{
int V_24 = 0 , V_4 = V_5 ;
V_24 = F_11 ( V_2 , V_20 ) ;
while ( V_24 ) {
if ( V_4 <= 0 ) {
F_7 ( L_3 , V_20 ) ;
V_24 = - V_26 ;
break;
}
F_8 ( 5 ) ;
V_4 -= 5 ;
V_24 = F_11 ( V_2 , V_20 ) ;
}
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
int V_24 ;
F_10 ( V_2 , V_15 ) ;
V_24 = F_12 ( V_2 ) ;
if ( V_24 )
F_7 ( L_4 ) ;
F_9 ( V_2 , false ) ;
if ( V_15 == V_27 ||
V_15 == V_28 ||
V_15 == V_29 ) {
V_24 = F_13 ( V_2 , V_30 ) ;
if ( V_24 ) {
F_7 ( L_5 ) ;
return V_24 ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_29 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
bool V_31 )
{
enum V_14 V_15 ;
V_15 = V_31 ? V_27 : V_28 ;
return F_14 ( V_2 , V_15 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_31 )
{
enum V_14 V_15 ;
int V_24 = 0 ;
V_15 = V_31 ? V_32 : V_33 ;
V_24 = F_14 ( V_2 , V_15 ) ;
return V_24 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
F_19 ( L_6 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
unsigned type ,
enum V_38 V_39 )
{
T_1 V_40 = F_3 ( F_4 ( V_9 , 0 , V_41 ) ) ;
V_40 = F_5 ( V_40 , V_42 , V_43 ,
( V_39 == V_44 ) ? 1 : 0 ) ;
F_6 ( F_4 ( V_9 , 0 , V_41 ) , V_40 ) ;
return 0 ;
}
static void F_21 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_22 ( V_46 , struct V_47 , V_49 ) ;
struct V_1 * V_2 = F_22 ( V_48 , struct V_1 , V_48 ) ;
if ( F_13 ( V_2 , V_21 ) ) {
F_7 ( L_7 ) ;
return;
}
F_23 ( V_2 , NULL ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_34 * V_50 ,
unsigned type ,
enum V_38 V_39 )
{
T_1 V_40 = F_3 ( F_4 ( V_9 , 0 , V_41 ) ) ;
V_40 = F_5 ( V_40 , V_42 , V_51 ,
( V_39 == V_44 ) ? 1 : 0 ) ;
F_6 ( F_4 ( V_9 , 0 , V_41 ) , V_40 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
int V_24 ;
if ( V_52 == 0 ) {
V_24 = F_11 ( V_2 , V_53 ) ;
if ( ! V_24 )
F_26 ( & V_2 -> V_48 . V_49 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_48 . V_54 . V_55 = 1 ;
V_2 -> V_48 . V_54 . V_56 = & V_57 ;
V_2 -> V_48 . V_58 . V_55 = 1 ;
V_2 -> V_48 . V_58 . V_56 = & V_59 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_29 ( V_2 , V_60 , 135 , & V_2 -> V_48 . V_58 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_29 ( V_2 , V_60 , 138 , & V_2 -> V_48 . V_54 ) ;
if ( V_24 ) {
F_30 ( V_2 , & V_2 -> V_48 . V_58 , 0 ) ;
return V_24 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_32 ( V_2 , & V_2 -> V_48 . V_58 , 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_32 ( V_2 , & V_2 -> V_48 . V_54 , 0 ) ;
if ( V_24 ) {
F_30 ( V_2 , & V_2 -> V_48 . V_58 , 0 ) ;
return V_24 ;
}
F_33 ( & V_2 -> V_48 . V_49 , F_21 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 , & V_2 -> V_48 . V_54 , 0 ) ;
F_30 ( V_2 , & V_2 -> V_48 . V_58 , 0 ) ;
}
