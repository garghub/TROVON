static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 = false ;
if ( F_2 ( V_2 ) ) {
V_4 -> V_6 = F_3 ( V_7 ) ;
V_4 -> V_4 = V_7 ;
V_5 = true ;
} else if ( F_4 ( V_2 ) ) {
V_4 -> V_6 = F_3 ( V_8 ) ;
V_4 -> V_4 = V_8 ;
V_5 = true ;
} else {
F_5 ( F_6 ( V_2 ) -> V_9 >= 9 ,
L_1 ) ;
}
return V_5 ;
}
static int F_7 ( struct V_10 * V_11 ,
const struct V_3 * V_4 ,
T_1 V_12 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
unsigned int V_15 ;
int V_16 ;
if ( F_8 ( V_4 -> V_6 > V_17 ) )
return - V_18 ;
V_16 = F_9 ( V_11 , 2 + 2 * V_17 ) ;
if ( V_16 ) {
F_10 ( L_2 , V_16 ) ;
return V_16 ;
}
F_11 ( V_14 ,
F_12 ( V_17 ) ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_6 ; V_15 ++ ) {
F_11 ( V_14 , V_12 + V_15 * 4 ) ;
F_11 ( V_14 ,
V_4 -> V_4 [ V_15 ] . V_19 ) ;
}
for (; V_15 < V_17 ; V_15 ++ ) {
F_11 ( V_14 , V_12 + V_15 * 4 ) ;
F_11 ( V_14 , V_4 -> V_4 [ 0 ] . V_19 ) ;
}
F_11 ( V_14 , V_20 ) ;
F_13 ( V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 ,
const struct V_3 * V_4 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
unsigned int V_21 ;
unsigned int V_22 ;
T_1 V_23 ;
T_1 V_24 = ( V_4 -> V_4 [ 0 ] . V_25 & 0xffff ) |
( ( V_4 -> V_4 [ 0 ] . V_25 & 0xffff ) << 16 ) ;
int V_16 ;
if ( F_8 ( V_4 -> V_6 > V_17 ) )
return - V_18 ;
V_16 = F_9 ( V_11 , 2 + V_17 ) ;
if ( V_16 ) {
F_10 ( L_2 , V_16 ) ;
return V_16 ;
}
F_11 ( V_14 ,
F_12 ( V_17 / 2 ) ) ;
for ( V_22 = 0 , V_21 = 0 ; V_22 < V_4 -> V_6 / 2 ; V_22 ++ , V_21 += 2 ) {
V_23 = ( V_4 -> V_4 [ V_21 ] . V_25 & 0xffff ) |
( ( V_4 -> V_4 [ V_21 + 1 ] . V_25 & 0xffff ) << 16 ) ;
F_11 ( V_14 , V_26 + V_22 * 4 ) ;
F_11 ( V_14 , V_23 ) ;
}
if ( V_4 -> V_6 & 0x01 ) {
V_23 = ( V_4 -> V_4 [ V_21 ] . V_25 & 0xffff ) |
( ( V_4 -> V_4 [ 0 ] . V_25 & 0xffff ) << 16 ) ;
} else
V_23 = V_24 ;
for (; V_22 < V_17 / 2 ; V_22 ++ ) {
F_11 ( V_14 , V_26 + V_22 * 4 ) ;
F_11 ( V_14 , V_23 ) ;
V_23 = V_24 ;
}
F_11 ( V_14 , V_20 ) ;
F_13 ( V_14 ) ;
return 0 ;
}
int F_15 ( struct V_10 * V_11 )
{
struct V_3 V_27 ;
int V_16 ;
if ( F_1 ( V_11 -> V_28 -> V_2 , & V_27 ) ) {
V_16 = F_7 ( V_11 , & V_27 , V_29 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_11 , & V_27 , V_30 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_11 , & V_27 , V_31 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_11 , & V_27 , V_32 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_11 , & V_27 , V_33 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_14 ( V_11 , & V_27 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
