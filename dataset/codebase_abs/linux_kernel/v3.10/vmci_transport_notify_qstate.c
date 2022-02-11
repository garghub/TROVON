static bool F_1 ( struct V_1 * V_2 )
{
bool V_3 ;
T_1 V_4 ;
if ( ! F_2 ( V_2 , V_5 ) )
return false ;
if ( ! F_2 ( V_2 , V_6 ) ) {
F_2 ( V_2 , V_6 ) = true ;
if ( F_2 ( V_2 , V_7 ) < V_8 ) {
F_2 ( V_2 , V_7 ) =
F_2 ( V_2 , V_9 ) ;
} else {
F_2 ( V_2 , V_7 ) -= V_8 ;
if ( F_2 ( V_2 , V_7 ) <
F_2 ( V_2 , V_9 ) )
F_2 ( V_2 , V_7 ) =
F_2 ( V_2 , V_9 ) ;
}
}
V_4 = F_3 ( V_2 ) -> V_10 -
F_2 ( V_2 , V_7 ) ;
V_3 = F_4 ( F_3 ( V_2 ) -> V_11 ) >
V_4 ;
if ( V_3 ) {
F_2 ( V_2 , V_6 ) = false ;
}
return V_3 ;
}
static void
F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
bool V_16 ,
struct V_17 * V_18 , struct V_17 * V_19 )
{
V_13 -> V_20 ( V_13 ) ;
}
static void
F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
bool V_16 ,
struct V_17 * V_18 , struct V_17 * V_19 )
{
V_13 -> V_21 ( V_13 , 0 ) ;
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
if ( F_2 ( V_2 , V_7 ) < F_3 ( V_2 ) -> V_10 )
F_2 ( V_2 , V_7 ) =
F_9 ( F_2 ( V_2 , V_7 ) + V_8 ,
F_3 ( V_2 ) -> V_10 ) ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
bool V_22 ;
unsigned int V_23 ;
int V_24 ;
V_2 = F_8 ( V_13 ) ;
V_22 = false ;
V_23 = 0 ;
V_24 = 0 ;
if ( F_1 ( V_2 ) ) {
while ( ! ( V_2 -> V_25 & V_26 ) &&
! V_22 &&
V_23 < V_27 ) {
V_24 = F_11 ( V_13 ) ;
if ( V_24 >= 0 )
V_22 = true ;
V_23 ++ ;
}
if ( V_23 >= V_27 && ! V_22 )
F_12 ( L_1 ,
V_13 ) ;
else
F_2 ( V_2 , V_5 ) = false ;
}
return V_24 ;
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_2 ( V_2 , V_7 ) = V_8 ;
F_2 ( V_2 , V_9 ) = V_8 ;
F_2 ( V_2 , V_5 ) = false ;
F_2 ( V_2 , V_6 ) = false ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_7 ) = V_8 ;
F_2 ( V_2 , V_9 ) = V_8 ;
F_2 ( V_2 , V_5 ) = false ;
F_2 ( V_2 , V_6 ) = false ;
}
static int
F_15 ( struct V_12 * V_13 ,
T_2 V_28 , bool * V_29 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
if ( F_16 ( V_2 ) ) {
* V_29 = true ;
} else {
if ( V_13 -> V_30 == V_31 )
F_7 ( V_13 ) ;
* V_29 = false ;
}
return 0 ;
}
static int
F_17 ( struct V_12 * V_13 ,
T_2 V_28 , bool * V_32 )
{
T_3 V_33 ;
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_33 = F_18 ( V_2 ) ;
if ( V_33 > 0 ) {
* V_32 = true ;
return 0 ;
} else if ( V_33 == 0 ) {
* V_32 = false ;
}
return 0 ;
}
static int
F_19 (
struct V_12 * V_13 ,
T_2 V_28 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_35 -> V_36 = 0 ;
V_35 -> V_37 = 0 ;
V_35 -> V_38 = false ;
if ( F_2 ( V_2 , V_9 ) < V_28 + 1 ) {
F_2 ( V_2 , V_9 ) = V_28 + 1 ;
if ( F_2 ( V_2 , V_7 ) <
F_2 ( V_2 , V_9 ) ) {
F_2 ( V_2 , V_7 ) =
F_2 ( V_2 , V_9 ) ;
V_35 -> V_38 = true ;
}
}
return 0 ;
}
static int
F_20 (
struct V_12 * V_13 ,
T_2 V_28 ,
struct V_34 * V_35 )
{
int V_24 = 0 ;
F_7 ( V_13 ) ;
if ( V_35 -> V_38 ) {
V_24 = F_10 ( V_13 ) ;
if ( V_24 < 0 )
return V_24 ;
V_35 -> V_38 = false ;
}
return V_24 ;
}
static int
F_21 (
struct V_12 * V_13 ,
T_2 V_28 ,
T_4 V_39 ,
bool V_40 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_24 ;
bool V_41 = false ;
T_1 V_42 ;
V_2 = F_8 ( V_13 ) ;
V_24 = 0 ;
if ( V_40 ) {
F_22 () ;
V_42 =
F_4 ( F_3 ( V_2 ) -> V_11 ) ;
V_41 = V_42 == V_39 ;
if ( V_41 )
F_2 ( V_2 , V_5 ) = true ;
V_24 = F_10 ( V_13 ) ;
if ( V_24 < 0 )
return V_24 ;
V_13 -> V_21 ( V_13 , 0 ) ;
}
return V_24 ;
}
static int
F_23 (
struct V_12 * V_13 ,
struct V_43 * V_35 )
{
V_35 -> V_36 = 0 ;
V_35 -> V_37 = 0 ;
return 0 ;
}
static int
F_24 (
struct V_12 * V_13 ,
T_4 V_44 ,
struct V_43 * V_35 )
{
int V_24 = 0 ;
struct V_1 * V_2 ;
bool V_45 = false ;
bool V_46 ;
int V_23 = 0 ;
V_2 = F_8 ( V_13 ) ;
F_22 () ;
V_46 =
F_25 ( F_3 ( V_2 ) -> V_11 ) == V_44 ;
if ( V_46 ) {
while ( ! ( V_2 -> V_25 & V_26 ) &&
! V_45 &&
V_23 < V_27 ) {
V_24 = F_26 ( V_13 ) ;
if ( V_24 >= 0 )
V_45 = true ;
V_23 ++ ;
}
}
if ( V_23 >= V_27 && ! V_45 ) {
F_12 ( L_2 ,
V_13 ) ;
return V_24 ;
}
return V_24 ;
}
static void
F_27 (
struct V_12 * V_13 ,
struct V_14 * V_15 ,
bool V_16 ,
struct V_17 * V_18 ,
struct V_17 * V_19 , bool * V_47 )
{
bool V_48 = false ;
switch ( V_15 -> type ) {
case V_49 :
F_6 ( V_13 , V_15 , V_16 , V_18 , V_19 ) ;
V_48 = true ;
break;
case V_50 :
F_5 ( V_13 , V_15 , V_16 , V_18 , V_19 ) ;
V_48 = true ;
break;
}
if ( V_47 )
* V_47 = V_48 ;
}
static void F_28 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_2 ( V_2 , V_7 ) = F_3 ( V_2 ) -> V_10 ;
if ( F_3 ( V_2 ) -> V_10 <
F_2 ( V_2 , V_9 ) )
F_2 ( V_2 , V_9 ) =
F_3 ( V_2 ) -> V_10 ;
}
static void F_29 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_2 ( V_2 , V_7 ) = F_3 ( V_2 ) -> V_10 ;
if ( F_3 ( V_2 ) -> V_10 <
F_2 ( V_2 , V_9 ) )
F_2 ( V_2 , V_9 ) =
F_3 ( V_2 ) -> V_10 ;
}
static int
F_30 (
struct V_12 * V_13 ,
T_2 V_28 ,
struct V_34 * V_35 )
{
return 0 ;
}
static int
F_31 (
struct V_12 * V_13 ,
struct V_43 * V_35 )
{
return 0 ;
}
static int
F_32 (
struct V_12 * V_13 ,
struct V_43 * V_35 )
{
return 0 ;
}
