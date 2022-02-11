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
static int F_10 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
T_1 V_3 ;
T_1 V_6 = F_2 ( V_7 , V_8 ) ;
if ( V_15 != V_16 ) {
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
if ( ! ( V_3 & V_6 ) )
return - V_17 ;
}
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_18 ) ) ;
if ( V_3 != V_15 )
return - V_17 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_19 = 0 , V_4 = V_5 ;
T_1 V_6 = F_2 ( V_7 , V_20 ) ;
T_1 V_3 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
while ( ! ( V_3 & V_6 ) ) {
if ( V_4 <= 0 ) {
F_7 ( L_2 ) ;
V_19 = - V_21 ;
break;
}
F_8 ( 5 ) ;
V_4 -= 5 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_10 ) ) ;
}
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 , enum V_14 V_15 )
{
int V_19 = 0 , V_4 = V_5 ;
V_19 = F_10 ( V_2 , V_15 ) ;
while ( V_19 ) {
if ( V_4 <= 0 ) {
F_7 ( L_3 , V_15 ) ;
V_19 = - V_21 ;
break;
}
F_8 ( 5 ) ;
V_4 -= 5 ;
V_19 = F_10 ( V_2 , V_15 ) ;
}
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_1 V_24 , T_1 V_25 , T_1 V_26 ) {
T_1 V_3 ;
int V_19 ;
V_3 = F_3 ( F_4 ( V_9 , 0 ,
V_27 ) ) ;
V_3 = F_5 ( V_3 , V_28 ,
V_29 , V_23 ) ;
F_6 ( F_4 ( V_9 , 0 , V_27 ) ,
V_3 ) ;
F_6 ( F_4 ( V_9 , 0 , V_30 ) ,
V_24 ) ;
F_6 ( F_4 ( V_9 , 0 , V_31 ) ,
V_25 ) ;
F_6 ( F_4 ( V_9 , 0 , V_32 ) ,
V_26 ) ;
F_9 ( V_2 , true ) ;
V_19 = F_11 ( V_2 ) ;
if ( V_19 )
F_7 ( L_4 ) ;
F_9 ( V_2 , false ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_22 V_23 )
{
int V_19 ;
F_13 ( V_2 , V_23 , 0 , 0 , 0 ) ;
if ( V_23 == V_33 ||
V_23 == V_34 ||
V_23 == V_35 ) {
V_19 = F_12 ( V_2 , V_36 ) ;
if ( V_19 ) {
F_7 ( L_5 ) ;
return V_19 ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_35 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
bool V_37 )
{
enum V_22 V_23 ;
V_23 = V_37 ? V_33 : V_34 ;
return F_14 ( V_2 , V_23 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_37 )
{
enum V_22 V_23 ;
int V_19 = 0 ;
V_23 = V_37 ? V_38 : V_39 ;
V_19 = F_14 ( V_2 , V_23 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
F_19 ( L_6 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned type ,
enum V_44 V_45 )
{
T_1 V_46 = F_3 ( F_4 ( V_9 , 0 , V_47 ) ) ;
V_46 = F_5 ( V_46 , V_48 , V_49 ,
( V_45 == V_50 ) ? 1 : 0 ) ;
F_6 ( F_4 ( V_9 , 0 , V_47 ) , V_46 ) ;
return 0 ;
}
static void F_21 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_22 ( V_52 , struct V_53 , V_55 ) ;
struct V_1 * V_2 = F_22 ( V_54 , struct V_1 , V_54 ) ;
if ( F_12 ( V_2 , V_16 ) ) {
F_7 ( L_7 ) ;
return;
}
F_23 ( V_2 , NULL ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_56 ,
unsigned type ,
enum V_44 V_45 )
{
T_1 V_46 = F_3 ( F_4 ( V_9 , 0 , V_47 ) ) ;
V_46 = F_5 ( V_46 , V_48 , V_57 ,
( V_45 == V_50 ) ? 1 : 0 ) ;
F_6 ( F_4 ( V_9 , 0 , V_47 ) , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
int V_19 ;
if ( V_58 == 0 ) {
V_19 = F_10 ( V_2 , V_59 ) ;
if ( ! V_19 )
F_26 ( & V_2 -> V_54 . V_55 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_60 . V_61 = 1 ;
V_2 -> V_54 . V_60 . V_62 = & V_63 ;
V_2 -> V_54 . V_64 . V_61 = 1 ;
V_2 -> V_54 . V_64 . V_62 = & V_65 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_29 ( V_2 , V_66 , 135 , & V_2 -> V_54 . V_64 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_29 ( V_2 , V_66 , 138 , & V_2 -> V_54 . V_60 ) ;
if ( V_19 ) {
F_30 ( V_2 , & V_2 -> V_54 . V_64 , 0 ) ;
return V_19 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_32 ( V_2 , & V_2 -> V_54 . V_64 , 0 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( V_2 , & V_2 -> V_54 . V_60 , 0 ) ;
if ( V_19 ) {
F_30 ( V_2 , & V_2 -> V_54 . V_64 , 0 ) ;
return V_19 ;
}
F_33 ( & V_2 -> V_54 . V_55 , F_21 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 , & V_2 -> V_54 . V_60 , 0 ) ;
F_30 ( V_2 , & V_2 -> V_54 . V_64 , 0 ) ;
}
