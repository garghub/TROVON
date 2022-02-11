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
V_1 |= V_23 | V_24 ;
V_18 = F_1 ( 0 , 0 , V_15 ) ;
V_18 = F_1 ( V_18 , 1 , V_17 ) ;
if ( V_4 == V_15 )
V_19 = V_13 -> V_25 + V_26 ;
else
V_19 = V_13 -> V_25 + V_27 + V_26 ;
F_3 ( V_18 , V_13 -> V_25 + 8 ) ;
F_3 ( V_1 , V_19 ) ;
}
static void F_4 ( struct V_12 * V_13 , struct V_3 * V_4 ,
int V_14 )
{
struct V_28 * V_29 = V_13 -> V_30 ;
struct V_3 * V_15 = & V_13 -> V_16 [ 0 ] ;
unsigned int V_31 ;
int V_32 ;
V_32 = 0 ;
V_31 = 1 << F_5 ( V_14 ) ;
if ( V_4 == V_15 )
V_29 -> V_33 |= V_31 ;
else
V_29 -> V_34 |= V_31 ;
if ( V_29 -> V_33 & 0xff0000 )
V_32 |= V_35 ;
if ( V_29 -> V_33 & 0xff00 )
V_32 |= V_36 ;
if ( V_29 -> V_33 & 0xff )
V_32 |= V_37 ;
if ( V_29 -> V_34 & 0xff0000 )
V_32 |= V_38 ;
if ( V_29 -> V_34 & 0xff00 )
V_32 |= V_39 ;
if ( V_29 -> V_34 & 0xff )
V_32 |= V_40 ;
F_3 ( V_32 , V_13 -> V_25 + 9 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_43 )
{
unsigned int V_44 = F_5 ( V_42 -> V_14 ) ;
unsigned int V_31 ;
int V_45 ;
if ( V_44 < 8 )
V_31 = 0x0000ff ;
else if ( V_44 < 16 )
V_31 = 0x00ff00 ;
else if ( V_44 < 20 )
V_31 = 0x0f0000 ;
else
V_31 = 0xf00000 ;
V_45 = F_7 ( V_13 , V_4 , V_42 , V_43 , V_31 ) ;
if ( V_45 )
return V_45 ;
F_2 ( V_13 , V_4 , V_42 -> V_14 ) ;
F_4 ( V_13 , V_4 , V_42 -> V_14 ) ;
return V_42 -> V_46 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_47 * V_48 )
{
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_45 , V_49 ;
V_29 = F_9 ( V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_50 ;
V_45 = F_10 ( V_13 , V_48 -> V_51 [ 0 ] , 0x10 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_11 ( V_13 , 2 ) ;
if ( V_45 )
return V_45 ;
for ( V_49 = 0 ; V_49 < V_13 -> V_52 ; V_49 ++ ) {
V_4 = & V_13 -> V_16 [ V_49 ] ;
V_45 = F_12 ( V_13 , V_4 , NULL , V_49 * V_27 ) ;
if ( V_45 )
return V_45 ;
V_4 -> V_53 = F_6 ;
}
return 0 ;
}
