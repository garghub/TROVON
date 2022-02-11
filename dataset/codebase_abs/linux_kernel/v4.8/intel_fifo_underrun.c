static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_7 V_7 ;
F_3 ( & V_4 -> V_8 ) ;
F_4 (dev_priv, pipe) {
V_6 = F_5 ( V_4 -> V_9 [ V_7 ] ) ;
if ( V_6 -> V_10 )
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
V_6 = F_5 ( V_4 -> V_9 [ V_7 ] ) ;
if ( V_6 -> V_11 )
return false ;
}
return true ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_12 . V_2 ) ;
T_1 V_13 = F_8 ( V_6 -> V_7 ) ;
T_2 V_14 = F_9 ( V_13 ) & 0xffff0000 ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_14 & V_15 ) == 0 )
return;
F_10 ( V_13 , V_14 | V_15 ) ;
F_11 ( V_13 ) ;
F_12 ( L_1 , F_13 ( V_6 -> V_7 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_7 V_7 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 = F_8 ( V_7 ) ;
T_2 V_14 = F_9 ( V_13 ) & 0xffff0000 ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_16 ) {
F_10 ( V_13 , V_14 | V_15 ) ;
F_11 ( V_13 ) ;
} else {
if ( V_17 && V_14 & V_15 )
F_12 ( L_1 , F_13 ( V_7 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_18 = ( V_7 == V_19 ) ? V_20 :
V_21 ;
if ( V_16 )
F_16 ( V_4 , V_18 ) ;
else
F_17 ( V_4 , V_18 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_12 . V_2 ) ;
enum V_7 V_7 = V_6 -> V_7 ;
T_3 V_22 = F_9 ( V_23 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_22 & F_19 ( V_7 ) ) == 0 )
return;
F_10 ( V_23 , F_19 ( V_7 ) ) ;
F_11 ( V_23 ) ;
F_12 ( L_2 , F_13 ( V_7 ) ) ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_7 V_7 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_16 ) {
F_10 ( V_23 , F_19 ( V_7 ) ) ;
if ( ! F_1 ( V_2 ) )
return;
F_16 ( V_4 , V_24 ) ;
} else {
F_17 ( V_4 , V_24 ) ;
if ( V_17 &&
F_9 ( V_23 ) & F_19 ( V_7 ) ) {
F_12 ( L_3 ,
F_13 ( V_7 ) ) ;
}
}
}
static void F_21 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_16 )
F_22 ( V_4 , V_7 , V_25 ) ;
else
F_23 ( V_4 , V_7 , V_25 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_26 V_27 ,
bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_18 = ( V_27 == V_28 ) ?
V_29 : V_30 ;
if ( V_16 )
F_25 ( V_4 , V_18 ) ;
else
F_26 ( V_4 , V_18 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_6 -> V_12 . V_2 ) ;
enum V_26 V_27 = (enum V_26 ) V_6 -> V_7 ;
T_3 V_31 = F_9 ( V_32 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( ( V_31 & F_28 ( V_27 ) ) == 0 )
return;
F_10 ( V_32 , F_28 ( V_27 ) ) ;
F_11 ( V_32 ) ;
F_12 ( L_4 ,
F_29 ( V_27 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
enum V_26 V_27 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_16 ) {
F_10 ( V_32 ,
F_28 ( V_27 ) ) ;
if ( ! F_6 ( V_2 ) )
return;
F_25 ( V_4 , V_33 ) ;
} else {
F_26 ( V_4 , V_33 ) ;
if ( V_17 && F_9 ( V_32 ) &
F_28 ( V_27 ) ) {
F_12 ( L_5 ,
F_29 ( V_27 ) ) ;
}
}
}
static bool F_31 ( struct V_1 * V_2 ,
enum V_7 V_7 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_6 = V_4 -> V_9 [ V_7 ] ;
struct V_5 * V_5 = F_5 ( V_6 ) ;
bool V_17 ;
F_3 ( & V_4 -> V_8 ) ;
V_17 = ! V_5 -> V_10 ;
V_5 -> V_10 = ! V_16 ;
if ( F_32 ( V_2 ) )
F_14 ( V_2 , V_7 , V_16 , V_17 ) ;
else if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_15 ( V_2 , V_7 , V_16 ) ;
else if ( F_35 ( V_2 ) )
F_20 ( V_2 , V_7 , V_16 , V_17 ) ;
else if ( F_36 ( V_2 ) || F_37 ( V_2 ) )
F_21 ( V_2 , V_7 , V_16 ) ;
return V_17 ;
}
bool F_38 ( struct V_3 * V_4 ,
enum V_7 V_7 , bool V_16 )
{
unsigned long V_35 ;
bool V_36 ;
F_39 ( & V_4 -> V_8 , V_35 ) ;
V_36 = F_31 ( & V_4 -> V_37 , V_7 ,
V_16 ) ;
F_40 ( & V_4 -> V_8 , V_35 ) ;
return V_36 ;
}
bool F_41 ( struct V_3 * V_4 ,
enum V_26 V_27 ,
bool V_16 )
{
struct V_34 * V_6 = V_4 -> V_9 [ V_27 ] ;
struct V_5 * V_5 = F_5 ( V_6 ) ;
unsigned long V_35 ;
bool V_17 ;
F_39 ( & V_4 -> V_8 , V_35 ) ;
V_17 = ! V_5 -> V_11 ;
V_5 -> V_11 = ! V_16 ;
if ( F_42 ( V_4 ) )
F_24 ( & V_4 -> V_37 ,
V_27 ,
V_16 ) ;
else
F_30 ( & V_4 -> V_37 ,
V_27 ,
V_16 , V_17 ) ;
F_40 ( & V_4 -> V_8 , V_35 ) ;
return V_17 ;
}
void F_43 ( struct V_3 * V_4 ,
enum V_7 V_7 )
{
struct V_34 * V_6 = V_4 -> V_9 [ V_7 ] ;
if ( V_6 == NULL )
return;
if ( F_32 ( V_4 ) &&
F_5 ( V_6 ) -> V_10 )
return;
if ( F_38 ( V_4 , V_7 , false ) )
F_12 ( L_6 ,
F_13 ( V_7 ) ) ;
}
void F_44 ( struct V_3 * V_4 ,
enum V_26 V_27 )
{
if ( F_41 ( V_4 , V_27 ,
false ) )
F_12 ( L_7 ,
F_29 ( V_27 ) ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_46 ( & V_4 -> V_8 ) ;
F_47 (&dev_priv->drm, crtc) {
if ( V_6 -> V_10 )
continue;
if ( F_32 ( V_4 ) )
F_7 ( V_6 ) ;
else if ( F_35 ( V_4 ) )
F_18 ( V_6 ) ;
}
F_48 ( & V_4 -> V_8 ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_46 ( & V_4 -> V_8 ) ;
F_47 (&dev_priv->drm, crtc) {
if ( V_6 -> V_11 )
continue;
if ( F_50 ( V_4 ) )
F_27 ( V_6 ) ;
}
F_48 ( & V_4 -> V_8 ) ;
}
