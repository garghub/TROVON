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
return V_5 ;
}
static T_1 F_8 ( enum V_10 V_11 , int V_12 )
{
switch ( V_11 ) {
case V_13 :
return F_9 ( V_12 ) ;
case V_14 :
return F_10 ( V_12 ) ;
case V_15 :
return F_11 ( V_12 ) ;
case V_16 :
return F_12 ( V_12 ) ;
case V_17 :
return F_13 ( V_12 ) ;
default:
F_14 ( V_11 ) ;
return V_18 ;
}
}
int F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_16 ( V_20 -> V_21 ) ;
struct V_3 V_4 ;
unsigned int V_12 ;
if ( ! F_1 ( V_2 , & V_4 ) )
return 0 ;
if ( F_17 ( V_4 . V_6 > V_22 ) )
return - V_23 ;
for ( V_12 = 0 ; V_12 < V_4 . V_6 ; V_12 ++ )
F_18 ( F_8 ( V_20 -> V_24 , V_12 ) ,
V_4 . V_4 [ V_12 ] . V_25 ) ;
for (; V_12 < V_22 ; V_12 ++ )
F_18 ( F_8 ( V_20 -> V_24 , V_12 ) ,
V_4 . V_4 [ 0 ] . V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
const struct V_3 * V_4 )
{
struct V_28 * V_29 = V_27 -> V_29 ;
enum V_10 V_20 = V_27 -> V_20 -> V_24 ;
unsigned int V_12 ;
int V_30 ;
if ( F_17 ( V_4 -> V_6 > V_22 ) )
return - V_23 ;
V_30 = F_20 ( V_27 , 2 + 2 * V_22 ) ;
if ( V_30 )
return V_30 ;
F_21 ( V_29 ,
F_22 ( V_22 ) ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_6 ; V_12 ++ ) {
F_23 ( V_29 ,
F_8 ( V_20 , V_12 ) ) ;
F_21 ( V_29 ,
V_4 -> V_4 [ V_12 ] . V_25 ) ;
}
for (; V_12 < V_22 ; V_12 ++ ) {
F_23 ( V_29 ,
F_8 ( V_20 , V_12 ) ) ;
F_21 ( V_29 ,
V_4 -> V_4 [ 0 ] . V_25 ) ;
}
F_21 ( V_29 , V_31 ) ;
F_24 ( V_29 ) ;
return 0 ;
}
static inline T_2 F_25 ( const struct V_3 * V_4 ,
T_3 V_32 ,
T_3 V_33 )
{
return V_4 -> V_4 [ V_32 ] . V_34 |
V_4 -> V_4 [ V_33 ] . V_34 << 16 ;
}
static int F_26 ( struct V_26 * V_27 ,
const struct V_3 * V_4 )
{
struct V_28 * V_29 = V_27 -> V_29 ;
unsigned int V_35 ;
int V_30 ;
if ( F_17 ( V_4 -> V_6 > V_22 ) )
return - V_23 ;
V_30 = F_20 ( V_27 , 2 + V_22 ) ;
if ( V_30 )
return V_30 ;
F_21 ( V_29 ,
F_22 ( V_22 / 2 ) ) ;
for ( V_35 = 0 ; V_35 < V_4 -> V_6 / 2 ; V_35 ++ ) {
F_23 ( V_29 , F_27 ( V_35 ) ) ;
F_21 ( V_29 ,
F_25 ( V_4 , 2 * V_35 , 2 * V_35 + 1 ) ) ;
}
if ( V_4 -> V_6 & 0x01 ) {
F_23 ( V_29 , F_27 ( V_35 ) ) ;
F_21 ( V_29 , F_25 ( V_4 , 2 * V_35 , 0 ) ) ;
V_35 ++ ;
}
for (; V_35 < V_22 / 2 ; V_35 ++ ) {
F_23 ( V_29 , F_27 ( V_35 ) ) ;
F_21 ( V_29 , F_25 ( V_4 , 0 , 0 ) ) ;
}
F_21 ( V_29 , V_31 ) ;
F_24 ( V_29 ) ;
return 0 ;
}
void F_28 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_3 V_4 ;
unsigned int V_35 ;
if ( ! F_1 ( V_2 , & V_4 ) )
return;
for ( V_35 = 0 ; V_35 < V_4 . V_6 / 2 ; V_35 ++ )
F_18 ( F_27 ( V_35 ) , F_25 ( & V_4 , 2 * V_35 , 2 * V_35 + 1 ) ) ;
if ( V_4 . V_6 & 0x01 ) {
F_18 ( F_27 ( V_35 ) , F_25 ( & V_4 , 2 * V_35 , 0 ) ) ;
V_35 ++ ;
}
for (; V_35 < ( V_22 / 2 ) ; V_35 ++ )
F_18 ( F_27 ( V_35 ) , F_25 ( & V_4 , 0 , 0 ) ) ;
}
int F_29 ( struct V_26 * V_27 )
{
struct V_3 V_37 ;
int V_30 ;
if ( F_1 ( V_27 -> V_38 , & V_37 ) ) {
V_30 = F_19 ( V_27 , & V_37 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_26 ( V_27 , & V_37 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
