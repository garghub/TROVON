static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
unsigned long V_5 = V_4 ;
unsigned char V_6 ;
if ( V_1 ) {
F_2 ( V_3 , V_5 + V_2 ) ;
return 0 ;
} else {
V_6 = F_3 ( V_5 + V_2 ) ;
return V_6 ;
}
}
static int F_4 ( int V_7 , int V_8 , struct V_9 * V_10 )
{
if ( V_10 -> V_11 & 0x0000ff ) {
if ( V_8 == 0 )
V_7 |= V_12 ;
else
V_7 |= V_13 ;
}
if ( V_10 -> V_11 & 0x00ff00 ) {
if ( V_8 == 0 )
V_7 |= V_14 ;
else
V_7 |= V_15 ;
}
if ( V_10 -> V_11 & 0xff0000 ) {
if ( V_8 == 0 )
V_7 |= V_16 ;
else
V_7 |= V_17 ;
}
return V_7 ;
}
static void F_5 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
struct V_9 * V_21 = & V_19 -> V_22 [ 0 ] ;
struct V_9 * V_23 = & V_19 -> V_22 [ 1 ] ;
int V_7 ;
int V_24 ;
unsigned long V_25 ;
V_7 = V_26 ;
V_24 = 0 ;
if ( ! ( V_10 -> V_11 & 0x0000ff ) )
V_7 |= V_27 ;
if ( ! ( V_10 -> V_11 & 0x00ff00 ) )
V_7 |= V_28 ;
if ( ! ( V_10 -> V_11 & 0xff0000 ) )
V_7 |= V_29 ;
V_24 = F_4 ( 0 , 0 , V_21 ) ;
V_24 = F_4 ( V_24 , 1 , V_23 ) ;
if ( V_10 == V_21 )
V_25 = V_19 -> V_5 + V_30 ;
else
V_25 = V_19 -> V_5 + V_31 + V_30 ;
F_2 ( V_24 , V_19 -> V_5 + 8 ) ;
F_2 ( V_7 , V_25 ) ;
}
static void F_6 ( struct V_18 * V_19 , struct V_9 * V_10 ,
int V_20 )
{
struct V_32 * V_33 = V_19 -> V_34 ;
struct V_9 * V_21 = & V_19 -> V_22 [ 0 ] ;
unsigned int V_35 ;
int V_36 ;
V_36 = 0 ;
V_35 = 1 << F_7 ( V_20 ) ;
if ( V_10 == V_21 )
V_33 -> V_37 |= V_35 ;
else
V_33 -> V_38 |= V_35 ;
if ( V_33 -> V_37 & 0xff0000 )
V_36 |= V_39 ;
if ( V_33 -> V_37 & 0xff00 )
V_36 |= V_40 ;
if ( V_33 -> V_37 & 0xff )
V_36 |= V_41 ;
if ( V_33 -> V_38 & 0xff0000 )
V_36 |= V_42 ;
if ( V_33 -> V_38 & 0xff00 )
V_36 |= V_43 ;
if ( V_33 -> V_38 & 0xff )
V_36 |= V_44 ;
F_2 ( V_36 , V_19 -> V_5 + 9 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned int * V_3 )
{
unsigned int V_47 = F_7 ( V_46 -> V_20 ) ;
unsigned int V_35 ;
int V_48 ;
if ( V_47 < 8 )
V_35 = 0x0000ff ;
else if ( V_47 < 16 )
V_35 = 0x00ff00 ;
else if ( V_47 < 20 )
V_35 = 0x0f0000 ;
else
V_35 = 0xf00000 ;
V_48 = F_9 ( V_19 , V_10 , V_46 , V_3 , V_35 ) ;
if ( V_48 )
return V_48 ;
F_5 ( V_19 , V_10 , V_46 -> V_20 ) ;
F_6 ( V_19 , V_10 , V_46 -> V_20 ) ;
return V_46 -> V_49 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_50 * V_51 )
{
struct V_32 * V_33 ;
struct V_9 * V_10 ;
int V_48 , V_52 ;
V_33 = F_11 ( V_19 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
return - V_53 ;
V_48 = F_12 ( V_19 , V_51 -> V_54 [ 0 ] , V_55 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_13 ( V_19 , 2 ) ;
if ( V_48 )
return V_48 ;
for ( V_52 = 0 ; V_52 < V_19 -> V_56 ; V_52 ++ ) {
V_10 = & V_19 -> V_22 [ V_52 ] ;
V_48 = F_14 ( V_19 , V_10 , F_1 ,
V_19 -> V_5 + V_31 * V_52 ) ;
if ( V_48 )
return V_48 ;
V_10 -> V_57 = F_8 ;
}
return 0 ;
}
