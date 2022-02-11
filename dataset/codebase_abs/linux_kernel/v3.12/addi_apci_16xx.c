static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
int V_11 ;
if ( V_8 < 8 )
V_10 = 0x000000ff ;
else if ( V_8 < 16 )
V_10 = 0x0000ff00 ;
else if ( V_8 < 24 )
V_10 = 0x00ff0000 ;
else
V_10 = 0xff000000 ;
V_11 = F_3 ( V_2 , V_4 , V_6 , V_7 , V_10 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_4 -> V_12 , V_2 -> V_13 + F_5 ( V_4 -> V_14 ) ) ;
return V_6 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_10 = V_7 [ 0 ] ;
unsigned int V_16 = V_7 [ 1 ] ;
V_10 &= V_4 -> V_12 ;
if ( V_10 ) {
V_4 -> V_17 &= ~ V_10 ;
V_4 -> V_17 |= ( V_16 & V_10 ) ;
F_4 ( V_4 -> V_17 , V_2 -> V_13 + F_7 ( V_4 -> V_14 ) ) ;
}
V_7 [ 1 ] = F_8 ( V_2 -> V_13 + F_9 ( V_4 -> V_14 ) ) ;
return V_6 -> V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_19 * V_20 = F_11 ( V_2 ) ;
const struct V_21 * V_22 = NULL ;
struct V_3 * V_4 ;
unsigned int V_23 ;
unsigned int V_24 ;
int V_25 ;
int V_11 ;
if ( V_18 < F_12 ( V_26 ) )
V_22 = & V_26 [ V_18 ] ;
if ( ! V_22 )
return - V_27 ;
V_2 -> V_28 = V_22 ;
V_2 -> V_29 = V_22 -> V_30 ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_13 = F_14 ( V_20 , 0 ) ;
V_23 = V_22 -> V_31 / 32 ;
if ( ( V_23 * 32 ) < V_22 -> V_31 ) {
V_24 = V_22 -> V_31 - ( V_23 * 32 ) ;
V_23 ++ ;
} else {
V_24 = 0 ;
}
V_11 = F_15 ( V_2 , V_23 ) ;
if ( V_11 )
return V_11 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
V_4 = & V_2 -> V_32 [ V_25 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_31 = ( ( V_25 * 32 ) < V_22 -> V_31 ) ? 32 : V_24 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_40 = F_1 ;
V_4 -> V_41 = F_6 ;
V_4 -> V_12 = 0 ;
F_4 ( V_4 -> V_12 , V_2 -> V_13 + F_5 ( V_25 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_19 * V_2 ,
const struct V_42 * V_43 )
{
return F_17 ( V_2 , & V_44 , V_43 -> V_45 ) ;
}
