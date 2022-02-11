static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_7 V_7 ;
F_3 ( & V_4 -> V_8 ) ;
F_4 (dev_priv, pipe) {
V_6 = F_5 ( V_4 , V_7 ) ;
if ( V_6 -> V_9 )
return false ;
}
return true ;
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_7 V_7 ;
struct V_5 * V_6 ;
F_3 ( & V_4 -> V_8 ) ;
F_4 (dev_priv, pipe) {
V_6 = F_5 ( V_4 , V_7 ) ;
if ( V_6 -> V_10 )
return false ;
}
return true ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_11 . V_2 ) ;
T_1 V_12 = F_8 ( V_6 -> V_7 ) ;
T_2 V_13 = F_9 ( V_12 ) & 0xffff0000 ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_13 & V_14 ) == 0 )
return;
F_10 ( V_12 , V_13 | V_14 ) ;
F_11 ( V_12 ) ;
F_12 ( V_4 , V_6 -> V_7 ) ;
F_13 ( L_1 , F_14 ( V_6 -> V_7 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
enum V_7 V_7 ,
bool V_15 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 = F_8 ( V_7 ) ;
T_2 V_13 = F_9 ( V_12 ) & 0xffff0000 ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_15 ) {
F_10 ( V_12 , V_13 | V_14 ) ;
F_11 ( V_12 ) ;
} else {
if ( V_16 && V_13 & V_14 )
F_13 ( L_1 , F_14 ( V_7 ) ) ;
}
}
static void F_16 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_17 = ( V_7 == V_18 ) ? V_19 :
V_20 ;
if ( V_15 )
F_17 ( V_4 , V_17 ) ;
else
F_18 ( V_4 , V_17 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_11 . V_2 ) ;
enum V_7 V_7 = V_6 -> V_7 ;
T_3 V_21 = F_9 ( V_22 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_21 & F_20 ( V_7 ) ) == 0 )
return;
F_10 ( V_22 , F_20 ( V_7 ) ) ;
F_11 ( V_22 ) ;
F_12 ( V_4 , V_7 ) ;
F_13 ( L_2 , F_14 ( V_7 ) ) ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_7 V_7 ,
bool V_15 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_15 ) {
F_10 ( V_22 , F_20 ( V_7 ) ) ;
if ( ! F_1 ( V_2 ) )
return;
F_17 ( V_4 , V_23 ) ;
} else {
F_18 ( V_4 , V_23 ) ;
if ( V_16 &&
F_9 ( V_22 ) & F_20 ( V_7 ) ) {
F_13 ( L_3 ,
F_14 ( V_7 ) ) ;
}
}
}
static void F_22 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_15 )
F_23 ( V_4 , V_7 , V_24 ) ;
else
F_24 ( V_4 , V_7 , V_24 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
enum V_7 V_25 ,
bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_17 = ( V_25 == V_18 ) ?
V_26 : V_27 ;
if ( V_15 )
F_26 ( V_4 , V_17 ) ;
else
F_27 ( V_4 , V_17 ) ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_11 . V_2 ) ;
enum V_7 V_25 = V_6 -> V_7 ;
T_3 V_28 = F_9 ( V_29 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_28 & F_29 ( V_25 ) ) == 0 )
return;
F_10 ( V_29 , F_29 ( V_25 ) ) ;
F_11 ( V_29 ) ;
F_30 ( V_4 , V_25 ) ;
F_13 ( L_4 ,
F_14 ( V_25 ) ) ;
}
static void F_31 ( struct V_1 * V_2 ,
enum V_7 V_25 ,
bool V_15 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_15 ) {
F_10 ( V_29 ,
F_29 ( V_25 ) ) ;
if ( ! F_6 ( V_2 ) )
return;
F_26 ( V_4 , V_30 ) ;
} else {
F_27 ( V_4 , V_30 ) ;
if ( V_16 && F_9 ( V_29 ) &
F_29 ( V_25 ) ) {
F_13 ( L_5 ,
F_14 ( V_25 ) ) ;
}
}
}
static bool F_32 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_5 ( V_4 , V_7 ) ;
bool V_16 ;
F_3 ( & V_4 -> V_8 ) ;
V_16 = ! V_6 -> V_9 ;
V_6 -> V_9 = ! V_15 ;
if ( F_33 ( V_4 ) )
F_15 ( V_2 , V_7 , V_15 , V_16 ) ;
else if ( F_34 ( V_4 ) || F_35 ( V_4 ) )
F_16 ( V_2 , V_7 , V_15 ) ;
else if ( F_36 ( V_4 ) )
F_21 ( V_2 , V_7 , V_15 , V_16 ) ;
else if ( F_37 ( V_4 ) >= 8 )
F_22 ( V_2 , V_7 , V_15 ) ;
return V_16 ;
}
bool F_38 ( struct V_3 * V_4 ,
enum V_7 V_7 , bool V_15 )
{
unsigned long V_31 ;
bool V_32 ;
F_39 ( & V_4 -> V_8 , V_31 ) ;
V_32 = F_32 ( & V_4 -> V_33 , V_7 ,
V_15 ) ;
F_40 ( & V_4 -> V_8 , V_31 ) ;
return V_32 ;
}
bool F_41 ( struct V_3 * V_4 ,
enum V_7 V_25 ,
bool V_15 )
{
struct V_5 * V_6 =
F_5 ( V_4 , V_25 ) ;
unsigned long V_31 ;
bool V_16 ;
F_39 ( & V_4 -> V_8 , V_31 ) ;
V_16 = ! V_6 -> V_10 ;
V_6 -> V_10 = ! V_15 ;
if ( F_42 ( V_4 ) )
F_25 ( & V_4 -> V_33 ,
V_25 ,
V_15 ) ;
else
F_31 ( & V_4 -> V_33 ,
V_25 ,
V_15 , V_16 ) ;
F_40 ( & V_4 -> V_8 , V_31 ) ;
return V_16 ;
}
void F_43 ( struct V_3 * V_4 ,
enum V_7 V_7 )
{
struct V_5 * V_6 = F_5 ( V_4 , V_7 ) ;
if ( V_6 == NULL )
return;
if ( F_33 ( V_4 ) &&
V_6 -> V_9 )
return;
if ( F_38 ( V_4 , V_7 , false ) ) {
F_12 ( V_4 , V_7 ) ;
F_13 ( L_6 ,
F_14 ( V_7 ) ) ;
}
F_44 ( V_4 ) ;
}
void F_45 ( struct V_3 * V_4 ,
enum V_7 V_25 )
{
if ( F_41 ( V_4 , V_25 ,
false ) ) {
F_30 ( V_4 , V_25 ) ;
F_13 ( L_7 ,
F_14 ( V_25 ) ) ;
}
}
void F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_47 ( & V_4 -> V_8 ) ;
F_48 (&dev_priv->drm, crtc) {
if ( V_6 -> V_9 )
continue;
if ( F_33 ( V_4 ) )
F_7 ( V_6 ) ;
else if ( F_36 ( V_4 ) )
F_19 ( V_6 ) ;
}
F_49 ( & V_4 -> V_8 ) ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_47 ( & V_4 -> V_8 ) ;
F_48 (&dev_priv->drm, crtc) {
if ( V_6 -> V_10 )
continue;
if ( F_51 ( V_4 ) )
F_28 ( V_6 ) ;
}
F_49 ( & V_4 -> V_8 ) ;
}
