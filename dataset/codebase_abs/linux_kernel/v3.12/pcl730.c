static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 = V_7 [ 0 ] ;
unsigned int V_11 = V_7 [ 1 ] ;
if ( V_10 ) {
V_4 -> V_12 &= ~ V_10 ;
V_4 -> V_12 |= ( V_11 & V_10 ) ;
if ( V_10 & 0x00ff )
F_2 ( V_4 -> V_12 & 0xff , V_2 -> V_13 + V_8 ) ;
if ( ( V_10 & 0xff00 ) && ( V_4 -> V_14 > 8 ) )
F_2 ( ( V_4 -> V_12 >> 8 ) & 0xff , V_2 -> V_13 + V_8 + 1 ) ;
if ( ( V_10 & 0xff0000 ) && ( V_4 -> V_14 > 16 ) )
F_2 ( ( V_4 -> V_12 >> 16 ) & 0xff , V_2 -> V_13 + V_8 + 2 ) ;
if ( ( V_10 & 0xff000000 ) && ( V_4 -> V_14 > 24 ) )
F_2 ( ( V_4 -> V_12 >> 24 ) & 0xff , V_2 -> V_13 + V_8 + 3 ) ;
}
V_7 [ 1 ] = V_4 -> V_12 ;
return V_6 -> V_15 ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_16 ;
V_16 = F_4 ( V_2 -> V_13 + V_8 ) ;
if ( V_4 -> V_14 > 8 )
V_16 |= ( F_4 ( V_2 -> V_13 + V_8 + 1 ) << 8 ) ;
if ( V_4 -> V_14 > 16 )
V_16 |= ( F_4 ( V_2 -> V_13 + V_8 + 2 ) << 16 ) ;
if ( V_4 -> V_14 > 24 )
V_16 |= ( F_4 ( V_2 -> V_13 + V_8 + 3 ) << 24 ) ;
return V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_3 ( V_2 , V_4 ) ;
return V_6 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_21 ;
int V_22 ;
V_22 = F_8 ( V_2 , V_18 -> V_23 [ 0 ] , V_20 -> V_24 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_9 ( V_2 , V_20 -> V_25 ) ;
if ( V_22 )
return V_22 ;
V_21 = 0 ;
if ( V_20 -> V_26 ) {
V_4 = & V_2 -> V_27 [ V_21 ++ ] ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_14 = V_20 -> V_26 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_9 = ( void * ) 0 ;
if ( V_20 -> V_35 )
V_4 -> V_12 = F_3 ( V_2 , V_4 ) ;
}
if ( V_20 -> V_36 ) {
V_4 = & V_2 -> V_27 [ V_21 ++ ] ;
V_4 -> type = V_37 ;
V_4 -> V_29 = V_38 ;
V_4 -> V_14 = V_20 -> V_36 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_5 ;
V_4 -> V_9 = V_20 -> V_39 ? ( void * ) 2 :
V_20 -> V_40 ? ( void * ) 1 : ( void * ) 0 ;
}
if ( V_20 -> V_41 ) {
V_4 = & V_2 -> V_27 [ V_21 ++ ] ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_14 = V_20 -> V_42 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_9 = ( void * ) 2 ;
V_4 = & V_2 -> V_27 [ V_21 ++ ] ;
V_4 -> type = V_37 ;
V_4 -> V_29 = V_38 ;
V_4 -> V_14 = V_20 -> V_42 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_5 ;
V_4 -> V_9 = ( void * ) 2 ;
}
return 0 ;
}
