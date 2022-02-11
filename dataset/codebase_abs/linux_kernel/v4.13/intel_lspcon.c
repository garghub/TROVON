static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
return & V_5 -> V_6 ;
}
static const char * F_3 ( enum V_7 V_8 )
{
switch ( V_8 ) {
case V_9 :
return L_1 ;
case V_10 :
return L_2 ;
case V_11 :
return L_3 ;
default:
F_4 ( V_8 ) ;
return L_3 ;
}
}
static enum V_7 F_5 ( struct V_2 * V_3 )
{
enum V_7 V_12 ;
struct V_13 * V_14 = & F_1 ( V_3 ) -> V_15 . V_16 ;
if ( F_6 ( V_14 , & V_12 ) ) {
F_7 ( L_4 ) ;
return V_11 ;
}
return V_12 ;
}
static enum V_7 F_8 ( struct V_2 * V_3 ,
enum V_7 V_8 )
{
enum V_7 V_12 ;
V_12 = F_5 ( V_3 ) ;
if ( V_12 == V_8 || V_12 == V_11 )
goto V_17;
F_9 ( L_5 ,
F_3 ( V_8 ) ) ;
F_10 ( ( V_12 = F_5 ( V_3 ) ) == V_8 ||
V_12 == V_11 , 100 ) ;
if ( V_12 != V_8 )
F_9 ( L_6 ) ;
V_17:
F_9 ( L_7 ,
F_3 ( V_12 ) ) ;
return V_12 ;
}
static int F_11 ( struct V_2 * V_3 ,
enum V_7 V_8 )
{
int V_18 ;
enum V_7 V_12 ;
struct V_13 * V_14 = & F_1 ( V_3 ) -> V_15 . V_16 ;
V_18 = F_6 ( V_14 , & V_12 ) ;
if ( V_18 ) {
F_7 ( L_4 ) ;
return V_18 ;
}
if ( V_12 == V_8 ) {
F_9 ( L_8 ) ;
return 0 ;
}
V_18 = F_12 ( V_14 , V_8 ) ;
if ( V_18 < 0 ) {
F_7 ( L_9 ) ;
return V_18 ;
}
V_3 -> V_8 = V_8 ;
F_9 ( L_10 ) ;
return 0 ;
}
static bool F_13 ( struct V_2 * V_3 )
{
T_1 V_19 ;
if ( F_14 ( & F_1 ( V_3 ) -> V_15 , V_20 ,
& V_19 ) != 1 ) {
F_9 ( L_11 ) ;
return false ;
}
F_9 ( L_12 ,
V_19 >> 4 , V_19 & 0xf ) ;
return true ;
}
static bool F_15 ( struct V_2 * V_3 )
{
enum V_21 V_22 ;
struct V_13 * V_14 = & F_1 ( V_3 ) -> V_15 . V_16 ;
enum V_7 V_23 ;
V_23 = F_13 ( V_3 ) ?
V_9 : V_10 ;
V_22 = F_16 ( V_14 ) ;
if ( V_22 != V_24 ) {
F_9 ( L_13 ,
F_17 ( V_22 ) ) ;
return false ;
}
F_9 ( L_14 ) ;
V_3 -> V_8 = F_8 ( V_3 , V_23 ) ;
V_3 -> V_25 = true ;
return true ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_19 ( V_1 ) ;
struct V_26 * V_27 = F_20 ( V_5 -> V_28 . V_28 . V_29 ) ;
unsigned long V_30 = V_31 ;
while ( 1 ) {
if ( F_21 ( V_27 , V_5 ) ) {
F_9 ( L_15 ,
F_22 ( V_31 - V_30 ) ) ;
return;
}
if ( F_23 ( V_31 , V_30 + F_24 ( 1000 ) ) )
break;
F_25 ( 10000 , 15000 ) ;
}
F_9 ( L_16 ) ;
}
void F_26 ( struct V_2 * V_3 )
{
enum V_7 V_23 ;
if ( F_13 ( V_3 ) ) {
V_23 = V_9 ;
F_18 ( V_3 ) ;
} else {
V_23 = V_10 ;
}
if ( F_8 ( V_3 , V_23 ) == V_9 )
return;
if ( F_11 ( V_3 , V_9 ) )
F_7 ( L_17 ) ;
else
F_9 ( L_18 ) ;
}
void F_27 ( struct V_2 * V_3 )
{
F_8 ( V_3 , V_9 ) ;
}
bool F_28 ( struct V_4 * V_32 )
{
struct V_1 * V_6 = & V_32 -> V_6 ;
struct V_2 * V_3 = & V_32 -> V_3 ;
struct V_33 * V_29 = V_32 -> V_28 . V_28 . V_29 ;
struct V_26 * V_27 = F_20 ( V_29 ) ;
if ( ! F_29 ( V_27 ) ) {
F_7 ( L_19 ) ;
return false ;
}
V_3 -> V_25 = false ;
V_3 -> V_8 = V_11 ;
if ( ! F_15 ( V_3 ) ) {
F_7 ( L_20 ) ;
return false ;
}
if ( V_3 -> V_25 && V_3 -> V_8 != V_9 ) {
if ( F_11 ( V_3 , V_9 ) < 0 ) {
F_7 ( L_21 ) ;
return false ;
}
}
if ( ! F_30 ( V_6 ) ) {
F_7 ( L_22 ) ;
return false ;
}
F_31 ( & V_6 -> V_15 , & V_6 -> V_34 , F_32 ( V_6 -> V_35 ) ) ;
F_9 ( L_23 ) ;
return true ;
}
