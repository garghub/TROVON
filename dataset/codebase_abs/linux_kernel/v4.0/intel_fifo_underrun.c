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
void F_6 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
F_7 ( & V_4 -> V_9 ) ;
F_8 (dev_priv->dev, crtc) {
T_1 V_13 = F_9 ( V_7 -> V_8 ) ;
T_1 V_14 ;
if ( V_7 -> V_11 )
continue;
V_14 = F_10 ( V_13 ) & 0xffff0000 ;
if ( ( V_14 & V_15 ) == 0 )
continue;
F_11 ( V_13 , V_14 | V_15 ) ;
F_12 ( V_13 ) ;
F_13 ( L_1 , F_14 ( V_7 -> V_8 ) ) ;
}
F_15 ( & V_4 -> V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
enum V_8 V_8 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_13 = F_9 ( V_8 ) ;
T_1 V_14 = F_10 ( V_13 ) & 0xffff0000 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_16 ) {
F_11 ( V_13 , V_14 | V_15 ) ;
F_12 ( V_13 ) ;
} else {
if ( V_17 && V_14 & V_15 )
F_13 ( L_1 , F_14 ( V_8 ) ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_18 = ( V_8 == V_19 ) ? V_20 :
V_21 ;
if ( V_16 )
F_18 ( V_4 , V_18 ) ;
else
F_19 ( V_4 , V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_8 V_8 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_16 ) {
F_11 ( V_22 , F_21 ( V_8 ) ) ;
if ( ! F_1 ( V_2 ) )
return;
F_18 ( V_4 , V_23 ) ;
} else {
F_19 ( V_4 , V_23 ) ;
if ( V_17 &&
F_10 ( V_22 ) & F_21 ( V_8 ) ) {
F_13 ( L_2 ,
F_14 ( V_8 ) ) ;
}
}
}
static void F_22 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_16 )
V_4 -> V_24 [ V_8 ] &= ~ V_25 ;
else
V_4 -> V_24 [ V_8 ] |= V_25 ;
F_11 ( F_23 ( V_8 ) , V_4 -> V_24 [ V_8 ] ) ;
F_12 ( F_23 ( V_8 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_26 V_27 ,
bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_18 = ( V_27 == V_28 ) ?
V_29 : V_30 ;
if ( V_16 )
F_25 ( V_4 , V_18 ) ;
else
F_26 ( V_4 , V_18 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
enum V_26 V_27 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_16 ) {
F_11 ( V_31 ,
F_28 ( V_27 ) ) ;
if ( ! F_5 ( V_2 ) )
return;
F_25 ( V_4 , V_32 ) ;
} else {
F_26 ( V_4 , V_32 ) ;
if ( V_17 && F_10 ( V_31 ) &
F_28 ( V_27 ) ) {
F_13 ( L_3 ,
F_29 ( V_27 ) ) ;
}
}
}
static bool F_30 ( struct V_1 * V_2 ,
enum V_8 V_8 , bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_7 = V_4 -> V_10 [ V_8 ] ;
struct V_6 * V_6 = F_4 ( V_7 ) ;
bool V_17 ;
F_2 ( & V_4 -> V_9 ) ;
V_17 = ! V_6 -> V_11 ;
V_6 -> V_11 = ! V_16 ;
if ( F_31 ( V_2 ) )
F_16 ( V_2 , V_8 , V_16 , V_17 ) ;
else if ( F_32 ( V_2 ) || F_33 ( V_2 ) )
F_17 ( V_2 , V_8 , V_16 ) ;
else if ( F_34 ( V_2 ) )
F_20 ( V_2 , V_8 , V_16 , V_17 ) ;
else if ( F_35 ( V_2 ) || F_36 ( V_2 ) )
F_22 ( V_2 , V_8 , V_16 ) ;
return V_17 ;
}
bool F_37 ( struct V_3 * V_4 ,
enum V_8 V_8 , bool V_16 )
{
unsigned long V_34 ;
bool V_35 ;
F_38 ( & V_4 -> V_9 , V_34 ) ;
V_35 = F_30 ( V_4 -> V_2 , V_8 ,
V_16 ) ;
F_39 ( & V_4 -> V_9 , V_34 ) ;
return V_35 ;
}
bool F_40 ( struct V_3 * V_4 ,
enum V_26 V_27 ,
bool V_16 )
{
struct V_33 * V_7 = V_4 -> V_10 [ V_27 ] ;
struct V_6 * V_6 = F_4 ( V_7 ) ;
unsigned long V_34 ;
bool V_17 ;
F_38 ( & V_4 -> V_9 , V_34 ) ;
V_17 = ! V_6 -> V_12 ;
V_6 -> V_12 = ! V_16 ;
if ( F_41 ( V_4 -> V_2 ) )
F_24 ( V_4 -> V_2 , V_27 ,
V_16 ) ;
else
F_27 ( V_4 -> V_2 , V_27 ,
V_16 , V_17 ) ;
F_39 ( & V_4 -> V_9 , V_34 ) ;
return V_17 ;
}
void F_42 ( struct V_3 * V_4 ,
enum V_8 V_8 )
{
struct V_33 * V_7 = V_4 -> V_10 [ V_8 ] ;
if ( V_7 == NULL )
return;
if ( F_31 ( V_4 -> V_2 ) &&
F_4 ( V_7 ) -> V_11 )
return;
if ( F_37 ( V_4 , V_8 , false ) )
F_13 ( L_4 ,
F_14 ( V_8 ) ) ;
}
void F_43 ( struct V_3 * V_4 ,
enum V_26 V_27 )
{
if ( F_40 ( V_4 , V_27 ,
false ) )
F_13 ( L_5 ,
F_29 ( V_27 ) ) ;
}
