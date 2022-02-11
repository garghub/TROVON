static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = F_3 ( V_6 -> V_9 ) ;
unsigned int V_11 ;
int V_12 ;
V_11 = F_4 ( V_2 -> V_13 + V_14 ) ;
V_11 &= ~ F_5 ( V_8 ) ;
V_11 |= F_6 ( V_8 , V_10 ) ;
F_7 ( V_11 , V_2 -> V_13 + V_14 ) ;
V_11 = V_4 -> V_15 [ V_8 ] ;
for ( V_12 = 0 ; V_12 < V_6 -> V_16 ; V_12 ++ ) {
V_11 = V_7 [ V_12 ] ;
F_7 ( V_11 & 0xff , V_2 -> V_13 + F_8 ( V_8 ) ) ;
F_7 ( ( V_11 >> 8 ) & 0xff , V_2 -> V_13 + F_9 ( V_8 ) ) ;
F_10 ( 2 , 100 ) ;
}
V_4 -> V_15 [ V_8 ] = V_11 ;
return V_6 -> V_16 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_13 + V_17 ) ;
return V_6 -> V_16 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
struct V_3 * V_4 ;
int V_21 ;
V_21 = F_14 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_13 = F_15 ( V_20 , 2 ) ;
V_21 = F_16 ( V_2 , 2 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_22 [ 0 ] ;
V_4 -> type = V_23 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0x0fff ;
V_4 -> V_28 = & V_29 ;
V_4 -> V_30 = F_1 ;
V_21 = F_17 ( V_4 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_22 [ 1 ] ;
V_4 -> type = V_31 ;
V_4 -> V_24 = V_32 ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = & V_33 ;
V_4 -> V_34 = F_11 ;
F_7 ( 0 , V_2 -> V_13 + V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_2 ,
const struct V_36 * V_37 )
{
return F_19 ( V_2 , & V_38 ,
V_37 -> V_39 ) ;
}
