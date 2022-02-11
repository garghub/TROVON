static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
enum V_8 V_8 ;
F_2 ( & V_4 -> V_9 ) ;
F_3 (dev_priv, pipe) {
V_7 = F_4 ( V_4 -> V_10 [ V_8 ] ) ;
if ( V_7 -> V_11 )
return false ;
}
return true ;
}
static bool F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_8 V_8 ;
struct V_6 * V_7 ;
F_2 ( & V_4 -> V_9 ) ;
F_3 (dev_priv, pipe) {
V_7 = F_4 ( V_4 -> V_10 [ V_8 ] ) ;
if ( V_7 -> V_12 )
return false ;
}
return true ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_7 ( V_7 -> V_13 . V_2 ) ;
T_1 V_14 = F_8 ( V_7 -> V_8 ) ;
T_2 V_15 = F_9 ( V_14 ) & 0xffff0000 ;
F_2 ( & V_4 -> V_9 ) ;
if ( ( V_15 & V_16 ) == 0 )
return;
F_10 ( V_14 , V_15 | V_16 ) ;
F_11 ( V_14 ) ;
F_12 ( L_1 , F_13 ( V_7 -> V_8 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_8 V_8 ,
bool V_17 , bool V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_14 = F_8 ( V_8 ) ;
T_2 V_15 = F_9 ( V_14 ) & 0xffff0000 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_17 ) {
F_10 ( V_14 , V_15 | V_16 ) ;
F_11 ( V_14 ) ;
} else {
if ( V_18 && V_15 & V_16 )
F_12 ( L_1 , F_13 ( V_8 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_19 = ( V_8 == V_20 ) ? V_21 :
V_22 ;
if ( V_17 )
F_16 ( V_4 , V_19 ) ;
else
F_17 ( V_4 , V_19 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_7 ( V_7 -> V_13 . V_2 ) ;
enum V_8 V_8 = V_7 -> V_8 ;
T_3 V_23 = F_9 ( V_24 ) ;
F_2 ( & V_4 -> V_9 ) ;
if ( ( V_23 & F_19 ( V_8 ) ) == 0 )
return;
F_10 ( V_24 , F_19 ( V_8 ) ) ;
F_11 ( V_24 ) ;
F_12 ( L_2 , F_13 ( V_8 ) ) ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_8 V_8 ,
bool V_17 , bool V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_17 ) {
F_10 ( V_24 , F_19 ( V_8 ) ) ;
if ( ! F_1 ( V_2 ) )
return;
F_16 ( V_4 , V_25 ) ;
} else {
F_17 ( V_4 , V_25 ) ;
if ( V_18 &&
F_9 ( V_24 ) & F_19 ( V_8 ) ) {
F_12 ( L_3 ,
F_13 ( V_8 ) ) ;
}
}
}
static void F_21 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_17 )
F_22 ( V_4 , V_8 , V_26 ) ;
else
F_23 ( V_4 , V_8 , V_26 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_27 V_28 ,
bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_19 = ( V_28 == V_29 ) ?
V_30 : V_31 ;
if ( V_17 )
F_25 ( V_4 , V_19 ) ;
else
F_26 ( V_4 , V_19 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_7 ( V_7 -> V_13 . V_2 ) ;
enum V_27 V_28 = (enum V_27 ) V_7 -> V_8 ;
T_3 V_32 = F_9 ( V_33 ) ;
F_2 ( & V_4 -> V_9 ) ;
if ( ( V_32 & F_28 ( V_28 ) ) == 0 )
return;
F_10 ( V_33 , F_28 ( V_28 ) ) ;
F_11 ( V_33 ) ;
F_12 ( L_4 ,
F_29 ( V_28 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
enum V_27 V_28 ,
bool V_17 , bool V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_17 ) {
F_10 ( V_33 ,
F_28 ( V_28 ) ) ;
if ( ! F_5 ( V_2 ) )
return;
F_25 ( V_4 , V_34 ) ;
} else {
F_26 ( V_4 , V_34 ) ;
if ( V_18 && F_9 ( V_33 ) &
F_28 ( V_28 ) ) {
F_12 ( L_5 ,
F_29 ( V_28 ) ) ;
}
}
}
static bool F_31 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_7 = V_4 -> V_10 [ V_8 ] ;
struct V_6 * V_6 = F_4 ( V_7 ) ;
bool V_18 ;
F_2 ( & V_4 -> V_9 ) ;
V_18 = ! V_6 -> V_11 ;
V_6 -> V_11 = ! V_17 ;
if ( F_32 ( V_2 ) )
F_14 ( V_2 , V_8 , V_17 , V_18 ) ;
else if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_15 ( V_2 , V_8 , V_17 ) ;
else if ( F_35 ( V_2 ) )
F_20 ( V_2 , V_8 , V_17 , V_18 ) ;
else if ( F_36 ( V_2 ) || F_37 ( V_2 ) )
F_21 ( V_2 , V_8 , V_17 ) ;
return V_18 ;
}
bool F_38 ( struct V_3 * V_4 ,
enum V_8 V_8 , bool V_17 )
{
unsigned long V_36 ;
bool V_37 ;
F_39 ( & V_4 -> V_9 , V_36 ) ;
V_37 = F_31 ( V_4 -> V_2 , V_8 ,
V_17 ) ;
F_40 ( & V_4 -> V_9 , V_36 ) ;
return V_37 ;
}
bool F_41 ( struct V_3 * V_4 ,
enum V_27 V_28 ,
bool V_17 )
{
struct V_35 * V_7 = V_4 -> V_10 [ V_28 ] ;
struct V_6 * V_6 = F_4 ( V_7 ) ;
unsigned long V_36 ;
bool V_18 ;
F_39 ( & V_4 -> V_9 , V_36 ) ;
V_18 = ! V_6 -> V_12 ;
V_6 -> V_12 = ! V_17 ;
if ( F_42 ( V_4 -> V_2 ) )
F_24 ( V_4 -> V_2 , V_28 ,
V_17 ) ;
else
F_30 ( V_4 -> V_2 , V_28 ,
V_17 , V_18 ) ;
F_40 ( & V_4 -> V_9 , V_36 ) ;
return V_18 ;
}
void F_43 ( struct V_3 * V_4 ,
enum V_8 V_8 )
{
struct V_35 * V_7 = V_4 -> V_10 [ V_8 ] ;
if ( V_7 == NULL )
return;
if ( F_32 ( V_4 -> V_2 ) &&
F_4 ( V_7 ) -> V_11 )
return;
if ( F_38 ( V_4 , V_8 , false ) )
F_12 ( L_6 ,
F_13 ( V_8 ) ) ;
}
void F_44 ( struct V_3 * V_4 ,
enum V_27 V_28 )
{
if ( F_41 ( V_4 , V_28 ,
false ) )
F_12 ( L_7 ,
F_29 ( V_28 ) ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
F_46 ( & V_4 -> V_9 ) ;
F_47 (dev_priv->dev, crtc) {
if ( V_7 -> V_11 )
continue;
if ( F_32 ( V_4 ) )
F_6 ( V_7 ) ;
else if ( F_35 ( V_4 ) )
F_18 ( V_7 ) ;
}
F_48 ( & V_4 -> V_9 ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
F_46 ( & V_4 -> V_9 ) ;
F_47 (dev_priv->dev, crtc) {
if ( V_7 -> V_12 )
continue;
if ( F_50 ( V_4 ) )
F_27 ( V_7 ) ;
}
F_48 ( & V_4 -> V_9 ) ;
}
