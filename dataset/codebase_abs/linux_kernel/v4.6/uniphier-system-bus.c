static int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
T_2 V_7 , V_8 ;
F_2 ( V_2 -> V_9 ,
L_1 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( V_3 >= F_3 ( V_2 -> V_3 ) ) {
F_4 ( V_2 -> V_9 , L_2 , V_3 ) ;
return - V_10 ;
}
if ( V_2 -> V_3 [ V_3 ] . V_11 || V_2 -> V_3 [ V_3 ] . V_7 ) {
F_4 ( V_2 -> V_9 ,
L_3 , V_3 ) ;
return - V_10 ;
}
if ( V_5 > V_12 ) {
F_4 ( V_2 -> V_9 , L_4 , V_5 ) ;
return - V_10 ;
}
V_7 = V_5 + V_6 ;
if ( V_4 > V_5 ) {
F_4 ( V_2 -> V_9 ,
L_5 ,
V_4 , V_5 ) ;
return - V_10 ;
}
V_5 -= V_4 ;
V_5 = F_5 ( V_5 , 0x00020000 ) ;
V_7 = F_6 ( V_7 , 0x00020000 ) ;
if ( V_7 > V_12 ) {
F_4 ( V_2 -> V_9 , L_6 , V_7 ) ;
return - V_10 ;
}
V_8 = V_5 ^ ( V_7 - 1 ) ;
V_8 = F_7 ( V_8 ) ;
V_5 = F_5 ( V_5 , V_8 ) ;
V_7 = F_6 ( V_7 , V_8 ) ;
V_2 -> V_3 [ V_3 ] . V_11 = V_5 ;
V_2 -> V_3 [ V_3 ] . V_7 = V_7 ;
F_2 ( V_2 -> V_9 , L_7 ,
V_3 , V_2 -> V_3 [ V_3 ] . V_11 , V_2 -> V_3 [ V_3 ] . V_7 ) ;
return 0 ;
}
static int F_8 (
const struct V_1 * V_2 )
{
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_2 -> V_3 ) ; V_13 ++ ) {
for ( V_14 = V_13 + 1 ; V_14 < F_3 ( V_2 -> V_3 ) ; V_14 ++ ) {
if ( V_2 -> V_3 [ V_13 ] . V_7 > V_2 -> V_3 [ V_14 ] . V_11 &&
V_2 -> V_3 [ V_13 ] . V_11 < V_2 -> V_3 [ V_14 ] . V_7 ) {
F_4 ( V_2 -> V_9 ,
L_8 ,
V_13 , V_14 ) ;
return - V_10 ;
}
}
}
return 0 ;
}
static void F_9 (
struct V_1 * V_2 )
{
void T_3 * V_15 = V_2 -> V_16 + V_17 ;
int V_18 ;
V_18 = ! ( F_10 ( V_15 ) & V_19 ) ;
F_2 ( V_2 -> V_9 , L_9 , V_18 ? L_10 : L_11 ) ;
if ( V_18 )
F_11 ( V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
}
static void F_12 (
const struct V_1 * V_2 )
{
void T_3 * V_15 = V_2 -> V_16 + V_17 ;
T_1 V_11 , V_7 , V_8 , V_20 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_2 -> V_3 ) ; V_13 ++ ) {
V_11 = V_2 -> V_3 [ V_13 ] . V_11 ;
V_7 = V_2 -> V_3 [ V_13 ] . V_7 ;
if ( V_11 == V_7 ) {
if ( V_13 < 2 )
V_20 = V_21 ;
else
V_20 = 0 ;
} else {
V_8 = V_11 ^ ( V_7 - 1 ) ;
V_20 = V_11 & 0xfffe0000 ;
V_20 |= ( ~ V_8 >> 16 ) & 0xfffe ;
V_20 |= V_19 ;
}
F_2 ( V_2 -> V_9 , L_12 , V_13 , V_20 ) ;
F_13 ( V_20 , V_15 + V_22 * V_13 ) ;
}
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_25 * V_9 = & V_24 -> V_9 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const T_4 * V_28 ;
T_1 V_29 , V_4 , V_6 ;
T_2 V_5 ;
int V_30 , V_3 , V_31 , V_32 , V_33 ;
V_2 = F_15 ( V_9 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_27 = F_16 ( V_24 , V_36 , 0 ) ;
V_2 -> V_16 = F_17 ( V_9 , V_27 ) ;
if ( F_18 ( V_2 -> V_16 ) )
return F_19 ( V_2 -> V_16 ) ;
V_2 -> V_9 = V_9 ;
V_30 = F_20 ( V_9 -> V_37 ) ;
V_33 = F_21 ( V_9 -> V_37 , L_13 , & V_29 ) ;
if ( V_33 ) {
F_4 ( V_9 , L_14 ) ;
return V_33 ;
}
if ( V_29 != 2 ) {
F_4 ( V_9 , L_15 ) ;
return - V_10 ;
}
V_33 = F_21 ( V_9 -> V_37 , L_16 , & V_29 ) ;
if ( V_33 ) {
F_4 ( V_9 , L_17 ) ;
return V_33 ;
}
if ( V_29 != 1 ) {
F_4 ( V_9 , L_18 ) ;
return - V_10 ;
}
V_28 = F_22 ( V_9 -> V_37 , L_19 , & V_31 ) ;
if ( ! V_28 ) {
F_4 ( V_9 , L_20 ) ;
return - V_38 ;
}
V_31 /= sizeof( * V_28 ) ;
V_32 = V_30 + 2 ;
for (; V_31 >= V_32 ; V_31 -= V_32 ) {
V_3 = F_23 ( V_28 ++ ) ;
V_4 = F_23 ( V_28 ++ ) ;
V_5 = F_24 ( V_9 -> V_37 , V_28 ) ;
if ( V_5 == V_39 )
return - V_10 ;
V_28 += V_30 ;
V_6 = F_23 ( V_28 ++ ) ;
V_33 = F_1 ( V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_8 ( V_2 ) ;
if ( V_33 )
return V_33 ;
F_9 ( V_2 ) ;
F_12 ( V_2 ) ;
return F_25 ( V_9 -> V_37 , V_40 ,
NULL , V_9 ) ;
}
