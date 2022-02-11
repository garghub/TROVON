static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
V_8 = F_2 ( V_4 , V_7 ) ;
if ( V_8 ) {
if ( V_8 & 0xff )
F_3 ( V_4 -> V_10 & 0xff , V_2 -> V_11 + V_12 ) ;
}
V_9 = V_4 -> V_10 & 0xff ;
V_9 |= F_4 ( V_2 -> V_11 + V_13 ) << 8 ;
V_7 [ 1 ] = V_9 ;
return V_6 -> V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_15 ;
V_15 = F_6 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_15 )
return V_15 ;
V_4 -> V_16 = 0x00ff ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_17 )
{
unsigned int V_18 ;
V_18 = F_4 ( V_2 -> V_11 + V_19 ) ;
if ( ( V_18 & 0x03 ) )
return - V_20 ;
V_18 = F_4 ( V_2 -> V_11 + V_21 ) ;
if ( ( V_18 & 0x02 ) )
return - V_22 ;
if ( ( V_18 & 0x11 ) == 0x01 )
return 0 ;
return - V_23 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_14 , V_24 ;
int V_25 ;
int V_15 ;
V_24 = F_9 ( V_6 -> V_26 ) ;
F_3 ( V_24 | 0x80 , V_2 -> V_11 + V_27 ) ;
F_10 ( 2 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
F_3 ( 0x00 , V_2 -> V_11 + V_28 ) ;
F_3 ( 0x30 , V_2 -> V_11 + V_29 ) ;
F_3 ( 0x32 , V_2 -> V_11 + V_29 ) ;
V_15 = F_11 ( V_2 , V_4 , V_6 , F_7 , 0 ) ;
if ( V_15 )
return V_15 ;
V_25 = F_12 ( V_2 -> V_11 + V_30 ) ;
V_25 &= 0x0fff ;
V_25 ^= 0x0800 ;
V_7 [ V_14 ] = V_25 ;
}
return V_14 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_11 = V_2 -> V_11 ;
F_3 ( 0x80 , V_11 + V_27 ) ;
F_3 ( 0x00 , V_11 + V_28 ) ;
F_3 ( 0x00 , V_11 + V_31 ) ;
F_3 ( 0x32 , V_11 + V_29 ) ;
F_3 ( 0x00 , V_11 + V_32 ) ;
F_3 ( 0x00 , V_11 + V_33 ) ;
F_12 ( V_11 + V_30 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_17 )
{
struct V_34 * V_35 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
int V_15 ;
V_35 -> V_36 |= V_37 ;
V_15 = F_16 ( V_2 , NULL ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_11 = V_35 -> V_38 [ 0 ] -> V_39 ;
V_15 = F_17 ( V_2 , 2 ) ;
if ( V_15 )
return V_15 ;
V_4 = & V_2 -> V_40 [ 0 ] ;
V_4 -> type = V_41 ;
V_4 -> V_42 = V_43 | V_44 ;
V_4 -> V_45 = 16 ;
V_4 -> V_46 = & V_47 ;
V_4 -> V_48 = 1 ;
V_4 -> V_49 = F_1 ;
V_4 -> V_50 = F_5 ;
V_4 -> V_16 = 0x00ff ;
V_4 = & V_2 -> V_40 [ 1 ] ;
V_4 -> type = V_51 ;
V_4 -> V_42 = V_43 | V_52 ;
V_4 -> V_45 = 16 ;
V_4 -> V_48 = ( 1 << 12 ) - 1 ;
V_4 -> V_46 = & V_53 ;
V_4 -> V_54 = F_8 ;
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_34 * V_35 )
{
return F_19 ( V_35 , & V_55 ) ;
}
