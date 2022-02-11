static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 = false ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
V_4 -> V_6 = F_4 ( V_7 ) ;
V_4 -> V_4 = V_7 ;
V_5 = true ;
} else if ( F_5 ( V_2 ) ) {
V_4 -> V_6 = F_4 ( V_8 ) ;
V_4 -> V_4 = V_8 ;
V_5 = true ;
} else {
F_6 ( F_7 ( V_2 ) -> V_9 >= 9 ,
L_1 ) ;
}
if ( F_8 ( V_2 ) ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_6 ; V_10 ++ )
if ( F_9 ( V_4 -> V_4 [ V_10 ] . V_11 &
( F_10 ( 1 ) | F_11 ( 0x7 ) ) ) )
return false ;
}
return V_5 ;
}
static T_1 F_12 ( enum V_12 V_13 , int V_14 )
{
switch ( V_13 ) {
case V_15 :
return F_13 ( V_14 ) ;
case V_16 :
return F_14 ( V_14 ) ;
case V_17 :
return F_15 ( V_14 ) ;
case V_18 :
return F_16 ( V_14 ) ;
case V_19 :
return F_17 ( V_14 ) ;
default:
F_18 ( V_13 ) ;
return V_20 ;
}
}
int F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_3 V_4 ;
unsigned int V_14 ;
if ( ! F_1 ( V_2 , & V_4 ) )
return 0 ;
if ( F_9 ( V_4 . V_6 > V_24 ) )
return - V_25 ;
for ( V_14 = 0 ; V_14 < V_4 . V_6 ; V_14 ++ )
F_20 ( F_12 ( V_22 -> V_26 , V_14 ) ,
V_4 . V_4 [ V_14 ] . V_27 ) ;
for (; V_14 < V_24 ; V_14 ++ )
F_20 ( F_12 ( V_22 -> V_26 , V_14 ) ,
V_4 . V_4 [ 0 ] . V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
const struct V_3 * V_4 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
enum V_12 V_22 = V_29 -> V_22 -> V_26 ;
unsigned int V_14 ;
int V_32 ;
if ( F_9 ( V_4 -> V_6 > V_24 ) )
return - V_25 ;
V_32 = F_22 ( V_29 , 2 + 2 * V_24 ) ;
if ( V_32 )
return V_32 ;
F_23 ( V_31 , F_24 ( V_24 ) ) ;
for ( V_14 = 0 ; V_14 < V_4 -> V_6 ; V_14 ++ ) {
F_25 ( V_31 , F_12 ( V_22 , V_14 ) ) ;
F_23 ( V_31 , V_4 -> V_4 [ V_14 ] . V_27 ) ;
}
for (; V_14 < V_24 ; V_14 ++ ) {
F_25 ( V_31 , F_12 ( V_22 , V_14 ) ) ;
F_23 ( V_31 , V_4 -> V_4 [ 0 ] . V_27 ) ;
}
F_23 ( V_31 , V_33 ) ;
F_26 ( V_31 ) ;
return 0 ;
}
static inline T_2 F_27 ( const struct V_3 * V_4 ,
T_3 V_34 ,
T_3 V_35 )
{
return V_4 -> V_4 [ V_34 ] . V_11 |
V_4 -> V_4 [ V_35 ] . V_11 << 16 ;
}
static int F_28 ( struct V_28 * V_29 ,
const struct V_3 * V_4 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
unsigned int V_10 ;
int V_32 ;
if ( F_9 ( V_4 -> V_6 > V_24 ) )
return - V_25 ;
V_32 = F_22 ( V_29 , 2 + V_24 ) ;
if ( V_32 )
return V_32 ;
F_23 ( V_31 ,
F_24 ( V_24 / 2 ) ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_6 / 2 ; V_10 ++ ) {
F_25 ( V_31 , F_29 ( V_10 ) ) ;
F_23 ( V_31 , F_27 ( V_4 , 2 * V_10 , 2 * V_10 + 1 ) ) ;
}
if ( V_4 -> V_6 & 0x01 ) {
F_25 ( V_31 , F_29 ( V_10 ) ) ;
F_23 ( V_31 , F_27 ( V_4 , 2 * V_10 , 0 ) ) ;
V_10 ++ ;
}
for (; V_10 < V_24 / 2 ; V_10 ++ ) {
F_25 ( V_31 , F_29 ( V_10 ) ) ;
F_23 ( V_31 , F_27 ( V_4 , 0 , 0 ) ) ;
}
F_23 ( V_31 , V_33 ) ;
F_26 ( V_31 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned int V_10 ;
if ( ! F_1 ( V_2 , & V_4 ) )
return;
for ( V_10 = 0 ; V_10 < V_4 . V_6 / 2 ; V_10 ++ )
F_20 ( F_29 ( V_10 ) , F_27 ( & V_4 , 2 * V_10 , 2 * V_10 + 1 ) ) ;
if ( V_4 . V_6 & 0x01 ) {
F_20 ( F_29 ( V_10 ) , F_27 ( & V_4 , 2 * V_10 , 0 ) ) ;
V_10 ++ ;
}
for (; V_10 < ( V_24 / 2 ) ; V_10 ++ )
F_20 ( F_29 ( V_10 ) , F_27 ( & V_4 , 0 , 0 ) ) ;
}
int F_31 ( struct V_28 * V_29 )
{
struct V_3 V_36 ;
int V_32 ;
if ( F_1 ( V_29 -> V_23 , & V_36 ) ) {
V_32 = F_21 ( V_29 , & V_36 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_28 ( V_29 , & V_36 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
