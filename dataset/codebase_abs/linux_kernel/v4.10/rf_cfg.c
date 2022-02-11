static bool F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 -> V_7 ;
T_1 V_8 = V_5 -> V_9 ;
T_1 V_10 = V_5 -> V_11 ;
T_1 V_12 = V_5 -> V_13 ;
T_1 V_14 = V_3 ;
if ( V_3 == 0xCDCDCDCD )
return true ;
V_14 = V_3 & 0x000000FF ;
if ( ( V_8 == V_14 ) && V_14 != 0x00 )
return false ;
V_14 = V_3 & 0x0000FF00 ;
V_14 >>= 8 ;
if ( ( V_12 & V_14 ) == 0 && V_14 != 0x07 )
return false ;
V_14 = V_3 & 0x00FF0000 ;
V_14 >>= 16 ;
if ( ( V_10 & V_14 ) == 0 && V_14 != 0x0F )
return false ;
return true ;
}
static void F_2 ( struct V_1 * V_2 , enum V_15 V_16 , T_1 V_17 , T_1 V_18 , T_1 V_19 )
{
if ( V_17 == 0xfe ) {
F_3 ( 50 ) ;
} else if ( V_17 == 0xfd ) {
F_3 ( 5 ) ;
} else if ( V_17 == 0xfc ) {
F_3 ( 1 ) ;
} else if ( V_17 == 0xfb ) {
F_4 ( 50 ) ;
} else if ( V_17 == 0xfa ) {
F_4 ( 5 ) ;
} else if ( V_17 == 0xf9 ) {
F_4 ( 1 ) ;
} else {
F_5 ( V_2 , V_16 , V_17 , V_18 , V_19 ) ;
F_4 ( 1 ) ;
}
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_19 )
{
T_1 V_20 = 0x1000 ;
T_1 V_21 = V_20 & 0xE000 ;
F_2 ( V_2 , V_22 , V_17 | V_21 ,
V_23 ,
V_19 ) ;
}
static bool F_7 ( struct V_1 * V_2 )
{
T_1 V_24 ;
T_1 V_25 = F_8 ( V_26 ) ;
T_1 * V_27 = V_26 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 += 2 ) {
T_1 V_28 = V_27 [ V_24 ] ;
T_1 V_29 = V_27 [ V_24 + 1 ] ;
if ( V_28 < 0xCDCDCDCD ) {
F_6 ( V_2 , V_28 , V_29 ) ;
continue;
} else {
if ( ! F_1 ( V_2 , V_27 [ V_24 ] ) ) {
F_9 ( V_28 , V_29 , V_24 ) ;
while ( V_29 != 0xDEAD && V_29 != 0xCDEF &&
V_29 != 0xCDCD && V_24 < V_25 - 2 )
F_9 ( V_28 , V_29 , V_24 ) ;
V_24 -= 2 ;
} else {
F_9 ( V_28 , V_29 , V_24 ) ;
while ( V_29 != 0xDEAD && V_29 != 0xCDEF &&
V_29 != 0xCDCD && V_24 < V_25 - 2 ) {
F_6 ( V_2 , V_28 , V_29 ) ;
F_9 ( V_28 , V_29 , V_24 ) ;
}
while ( V_29 != 0xDEAD && V_24 < V_25 - 2 )
F_9 ( V_28 , V_29 , V_24 ) ;
}
}
}
return true ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_6 ;
T_1 V_32 = 0 ;
bool V_33 = true ;
struct V_34 * V_35 ;
V_35 = & V_31 -> V_36 [ V_22 ] ;
V_32 = F_11 ( V_2 , V_35 -> V_37 , V_38 ) ;
F_12 ( V_2 , V_35 -> V_39 , V_38 << 16 , 0x1 ) ;
F_4 ( 1 ) ;
F_12 ( V_2 , V_35 -> V_40 , V_38 , 0x1 ) ;
F_4 ( 1 ) ;
F_12 ( V_2 , V_35 -> V_41 , V_42 , 0x0 ) ;
F_4 ( 1 ) ;
F_12 ( V_2 , V_35 -> V_41 , V_43 , 0x0 ) ;
F_4 ( 1 ) ;
V_33 = F_7 ( V_2 ) ;
F_12 ( V_2 , V_35 -> V_37 , V_38 , V_32 ) ;
return V_33 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) ;
}
bool F_14 ( struct V_1 * V_2 )
{
return F_13 ( V_2 ) ;
}
