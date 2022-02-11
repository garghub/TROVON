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
static int F_15 ( struct V_19 * V_20 ,
const struct V_3 * V_4 ,
enum V_10 V_11 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned int V_12 ;
int V_23 ;
if ( F_16 ( V_4 -> V_6 > V_24 ) )
return - V_25 ;
V_23 = F_17 ( V_20 , 2 + 2 * V_24 ) ;
if ( V_23 ) {
F_18 ( L_2 , V_23 ) ;
return V_23 ;
}
F_19 ( V_22 ,
F_20 ( V_24 ) ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_6 ; V_12 ++ ) {
F_21 ( V_22 , F_8 ( V_11 , V_12 ) ) ;
F_19 ( V_22 ,
V_4 -> V_4 [ V_12 ] . V_26 ) ;
}
for (; V_12 < V_24 ; V_12 ++ ) {
F_21 ( V_22 , F_8 ( V_11 , V_12 ) ) ;
F_19 ( V_22 , V_4 -> V_4 [ 0 ] . V_26 ) ;
}
F_19 ( V_22 , V_27 ) ;
F_22 ( V_22 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 ,
const struct V_3 * V_4 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned int V_28 ;
unsigned int V_29 ;
T_2 V_30 ;
T_2 V_31 = ( V_4 -> V_4 [ 0 ] . V_32 & 0xffff ) |
( ( V_4 -> V_4 [ 0 ] . V_32 & 0xffff ) << 16 ) ;
int V_23 ;
if ( F_16 ( V_4 -> V_6 > V_24 ) )
return - V_25 ;
V_23 = F_17 ( V_20 , 2 + V_24 ) ;
if ( V_23 ) {
F_18 ( L_2 , V_23 ) ;
return V_23 ;
}
F_19 ( V_22 ,
F_20 ( V_24 / 2 ) ) ;
for ( V_29 = 0 , V_28 = 0 ; V_29 < V_4 -> V_6 / 2 ; V_29 ++ , V_28 += 2 ) {
V_30 = ( V_4 -> V_4 [ V_28 ] . V_32 & 0xffff ) |
( ( V_4 -> V_4 [ V_28 + 1 ] . V_32 & 0xffff ) << 16 ) ;
F_21 ( V_22 , F_24 ( V_29 ) ) ;
F_19 ( V_22 , V_30 ) ;
}
if ( V_4 -> V_6 & 0x01 ) {
V_30 = ( V_4 -> V_4 [ V_28 ] . V_32 & 0xffff ) |
( ( V_4 -> V_4 [ 0 ] . V_32 & 0xffff ) << 16 ) ;
} else
V_30 = V_31 ;
for (; V_29 < V_24 / 2 ; V_29 ++ ) {
F_21 ( V_22 , F_24 ( V_29 ) ) ;
F_19 ( V_22 , V_30 ) ;
V_30 = V_31 ;
}
F_19 ( V_22 , V_27 ) ;
F_22 ( V_22 ) ;
return 0 ;
}
int F_25 ( struct V_19 * V_20 )
{
struct V_3 V_33 ;
int V_23 ;
if ( F_1 ( V_20 -> V_11 -> V_2 , & V_33 ) ) {
struct V_34 * V_35 = V_20 -> V_36 ;
struct V_37 * V_11 ;
enum V_10 V_38 ;
F_26 (ring, dev_priv, ring_id) {
V_23 = F_15 ( V_20 , & V_33 , V_38 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_23 ( V_20 , & V_33 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
