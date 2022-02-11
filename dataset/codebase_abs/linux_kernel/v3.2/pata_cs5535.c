static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 -> V_7 ) ;
F_3 ( V_5 , V_8 , & V_3 ) ;
if ( V_3 & 1 )
return V_9 ;
else
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
static const T_2 V_13 [ 5 ] = {
0xF7F4 , 0xF173 , 0x8141 , 0x5131 , 0x1131
} ;
static const T_2 V_14 [ 5 ] = {
0xF7F4 , 0x53F3 , 0x13F1 , 0x5131 , 0x1131
} ;
T_3 V_15 , V_16 ;
struct V_11 * V_17 = F_5 ( V_12 ) ;
int V_18 = V_12 -> V_19 - V_20 ;
int V_21 = V_18 ;
if ( V_17 ) {
int V_22 = V_17 -> V_19 - V_20 ;
V_21 = F_6 ( V_18 , V_22 ) ;
if ( V_21 < V_22 )
F_7 ( V_23 + 2 * V_17 -> V_24 ,
V_14 [ V_21 ] << 16 | V_13 [ V_22 ] , 0 ) ;
}
F_7 ( V_23 + 2 * V_12 -> V_24 ,
V_14 [ V_21 ] << 16 | V_13 [ V_18 ] , 0 ) ;
F_8 ( V_25 + 2 * V_12 -> V_24 , V_15 , V_16 ) ;
F_7 ( V_25 + 2 * V_12 -> V_24 , V_15 | 0x80000000UL , 0 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
static const T_3 V_26 [ 5 ] = {
0x7F7436A1 , 0x7F733481 , 0x7F723261 , 0x7F713161 , 0x7F703061
} ;
static const T_3 V_27 [ 3 ] = {
0x7F0FFFF3 , 0x7F035352 , 0x7F024241
} ;
T_3 V_15 , V_16 ;
int V_18 = V_12 -> V_28 ;
F_8 ( V_25 + 2 * V_12 -> V_24 , V_15 , V_16 ) ;
V_15 &= 0x80000000UL ;
if ( V_18 >= V_29 )
V_15 |= V_26 [ V_18 - V_29 ] ;
else
V_15 |= V_27 [ V_18 - V_30 ] ;
F_7 ( V_25 + 2 * V_12 -> V_24 , V_15 , 0 ) ;
}
static int F_10 ( struct V_4 * V_7 , const struct V_31 * V_32 )
{
static const struct V_33 V_34 = {
. V_35 = V_36 ,
. V_37 = V_38 ,
. V_39 = V_40 ,
. V_41 = V_42 ,
. V_43 = & V_44
} ;
const struct V_33 * V_45 [] = { & V_34 , & V_46 } ;
return F_11 ( V_7 , V_45 , & V_47 , NULL , 0 ) ;
}
static int T_4 F_12 ( void )
{
return F_13 ( & V_48 ) ;
}
static void T_5 F_14 ( void )
{
F_15 ( & V_48 ) ;
}
