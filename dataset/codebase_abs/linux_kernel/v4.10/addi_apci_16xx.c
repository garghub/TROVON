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
if ( F_7 ( V_4 , V_7 ) )
F_4 ( V_4 -> V_16 , V_2 -> V_13 + F_8 ( V_4 -> V_14 ) ) ;
V_7 [ 1 ] = F_9 ( V_2 -> V_13 + F_10 ( V_4 -> V_14 ) ) ;
return V_6 -> V_15 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_17 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
const struct V_20 * V_21 = NULL ;
struct V_3 * V_4 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_24 ;
int V_11 ;
if ( V_17 < F_13 ( V_25 ) )
V_21 = & V_25 [ V_17 ] ;
if ( ! V_21 )
return - V_26 ;
V_2 -> V_27 = V_21 ;
V_2 -> V_28 = V_21 -> V_29 ;
V_11 = F_14 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_13 = F_15 ( V_19 , 0 ) ;
V_22 = V_21 -> V_30 / 32 ;
if ( ( V_22 * 32 ) < V_21 -> V_30 ) {
V_23 = V_21 -> V_30 - ( V_22 * 32 ) ;
V_22 ++ ;
} else {
V_23 = 0 ;
}
V_11 = F_16 ( V_2 , V_22 ) ;
if ( V_11 )
return V_11 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
V_4 = & V_2 -> V_31 [ V_24 ] ;
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 | V_35 ;
V_4 -> V_30 = ( ( V_24 * 32 ) < V_21 -> V_30 ) ? 32 : V_23 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = F_1 ;
V_4 -> V_40 = F_6 ;
V_4 -> V_12 = 0 ;
F_4 ( V_4 -> V_12 , V_2 -> V_13 + F_5 ( V_24 ) ) ;
}
return 0 ;
}
static int F_17 ( struct V_18 * V_2 ,
const struct V_41 * V_42 )
{
return F_18 ( V_2 , & V_43 , V_42 -> V_44 ) ;
}
