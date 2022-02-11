static int F_1 ( int V_1 , int V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 & 0x0000ff ) {
if ( V_2 == 0 )
V_1 |= V_6 ;
else
V_1 |= V_7 ;
}
if ( V_4 -> V_5 & 0x00ff00 ) {
if ( V_2 == 0 )
V_1 |= V_8 ;
else
V_1 |= V_9 ;
}
if ( V_4 -> V_5 & 0xff0000 ) {
if ( V_2 == 0 )
V_1 |= V_10 ;
else
V_1 |= V_11 ;
}
return V_1 ;
}
static void F_2 ( struct V_12 * V_13 ,
struct V_3 * V_4 , int V_14 )
{
struct V_3 * V_15 = & V_13 -> V_16 [ 0 ] ;
struct V_3 * V_17 = & V_13 -> V_16 [ 1 ] ;
int V_1 ;
int V_18 ;
unsigned long V_19 ;
V_1 = V_20 ;
V_18 = 0 ;
if ( ! ( V_4 -> V_5 & 0x0000ff ) )
V_1 |= V_21 ;
if ( ! ( V_4 -> V_5 & 0x00ff00 ) )
V_1 |= V_22 ;
if ( ! ( V_4 -> V_5 & 0xff0000 ) )
V_1 |= V_23 ;
V_18 = F_1 ( 0 , 0 , V_15 ) ;
V_18 = F_1 ( V_18 , 1 , V_17 ) ;
if ( V_4 == V_15 )
V_19 = V_13 -> V_24 + V_25 ;
else
V_19 = V_13 -> V_24 + V_26 + V_25 ;
F_3 ( V_18 , V_13 -> V_24 + 8 ) ;
F_3 ( V_1 , V_19 ) ;
}
static void F_4 ( struct V_12 * V_13 , struct V_3 * V_4 ,
int V_14 )
{
struct V_27 * V_28 = V_13 -> V_29 ;
struct V_3 * V_15 = & V_13 -> V_16 [ 0 ] ;
unsigned int V_30 ;
int V_31 ;
V_31 = 0 ;
V_30 = 1 << F_5 ( V_14 ) ;
if ( V_4 == V_15 )
V_28 -> V_32 |= V_30 ;
else
V_28 -> V_33 |= V_30 ;
if ( V_28 -> V_32 & 0xff0000 )
V_31 |= V_34 ;
if ( V_28 -> V_32 & 0xff00 )
V_31 |= V_35 ;
if ( V_28 -> V_32 & 0xff )
V_31 |= V_36 ;
if ( V_28 -> V_33 & 0xff0000 )
V_31 |= V_37 ;
if ( V_28 -> V_33 & 0xff00 )
V_31 |= V_38 ;
if ( V_28 -> V_33 & 0xff )
V_31 |= V_39 ;
F_3 ( V_31 , V_13 -> V_24 + 9 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_3 * V_4 ,
struct V_40 * V_41 ,
unsigned int * V_42 )
{
unsigned int V_43 = F_5 ( V_41 -> V_14 ) ;
unsigned int V_30 ;
int V_44 ;
if ( V_43 < 8 )
V_30 = 0x0000ff ;
else if ( V_43 < 16 )
V_30 = 0x00ff00 ;
else if ( V_43 < 20 )
V_30 = 0x0f0000 ;
else
V_30 = 0xf00000 ;
V_44 = F_7 ( V_13 , V_4 , V_41 , V_42 , V_30 ) ;
if ( V_44 )
return V_44 ;
F_2 ( V_13 , V_4 , V_41 -> V_14 ) ;
F_4 ( V_13 , V_4 , V_41 -> V_14 ) ;
return V_41 -> V_45 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_46 * V_47 )
{
struct V_27 * V_28 ;
struct V_3 * V_4 ;
int V_44 , V_48 ;
V_28 = F_9 ( V_13 , sizeof( * V_28 ) ) ;
if ( ! V_28 )
return - V_49 ;
V_44 = F_10 ( V_13 , V_47 -> V_50 [ 0 ] , 0x10 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_11 ( V_13 , 2 ) ;
if ( V_44 )
return V_44 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_51 ; V_48 ++ ) {
V_4 = & V_13 -> V_16 [ V_48 ] ;
V_44 = F_12 ( V_13 , V_4 , NULL ,
V_13 -> V_24 + V_26 * V_48 ) ;
if ( V_44 )
return V_44 ;
V_4 -> V_52 = F_6 ;
}
return 0 ;
}
