static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_11 ; V_10 ++ ) {
unsigned int V_12 = V_7 [ V_10 ] ;
F_3 ( V_12 , V_2 -> V_13 + F_4 ( V_8 ) ) ;
V_4 -> V_14 [ V_8 ] = V_12 ;
}
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_15 = ( V_8 < 8 ) ? 0x00ff : 0xff00 ;
unsigned short V_16 = 0x0000 ;
int V_17 ;
V_17 = F_6 ( V_2 , V_4 , V_6 , V_7 , V_15 ) ;
if ( V_17 )
return V_17 ;
if ( ! ( V_4 -> V_18 & 0x00ff ) )
V_16 |= V_19 ;
if ( ! ( V_4 -> V_18 & 0xff00 ) )
V_16 |= V_20 ;
F_3 ( V_16 , V_2 -> V_13 + V_21 ) ;
return V_6 -> V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_8 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_22 , V_2 -> V_13 + V_23 ) ;
V_7 [ 1 ] = F_9 ( V_2 -> V_13 + V_23 ) ;
return V_6 -> V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_25 * V_26 = F_11 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_12 ;
int V_17 ;
int V_10 ;
V_17 = F_12 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 = F_13 ( V_26 , 2 ) ;
V_17 = F_14 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_27 [ 0 ] ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 | V_31 | V_32 ;
V_4 -> V_33 = 8 ;
V_4 -> V_34 = 0xffff ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_37 = F_1 ;
V_17 = F_15 ( V_4 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_38 , V_2 -> V_13 + V_39 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_33 ; V_10 ++ ) {
F_3 ( F_16 ( 0 ) | F_17 ( V_10 ) ,
V_40 ) ;
F_3 ( 0 , V_2 -> V_13 + V_41 ) ;
F_3 ( 0x8000 , V_2 -> V_13 + F_4 ( V_10 ) ) ;
V_4 -> V_14 [ V_10 ] = 0x8000 ;
}
F_3 ( 0 , V_2 -> V_13 + V_42 ) ;
F_3 ( V_43 , V_2 -> V_13 + V_39 ) ;
V_4 = & V_2 -> V_27 [ 1 ] ;
V_4 -> type = V_44 ;
V_4 -> V_29 = V_45 | V_30 ;
V_4 -> V_33 = 16 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = & V_46 ;
V_4 -> V_47 = F_5 ;
V_4 -> V_48 = F_7 ;
V_12 = F_9 ( V_2 -> V_13 + V_21 ) ;
if ( ! ( V_12 & V_19 ) )
V_4 -> V_18 |= 0x00ff ;
if ( ! ( V_12 & V_20 ) )
V_4 -> V_18 |= 0xff00 ;
V_4 -> V_22 = F_9 ( V_2 -> V_13 + V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_2 ,
const struct V_49 * V_50 )
{
return F_19 ( V_2 , & V_51 ,
V_50 -> V_52 ) ;
}
