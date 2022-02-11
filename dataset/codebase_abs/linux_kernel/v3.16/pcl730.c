static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 ;
V_10 = F_2 ( V_4 , V_7 ) ;
if ( V_10 ) {
if ( V_10 & 0x00ff )
F_3 ( V_4 -> V_11 & 0xff , V_2 -> V_12 + V_8 ) ;
if ( ( V_10 & 0xff00 ) && ( V_4 -> V_13 > 8 ) )
F_3 ( ( V_4 -> V_11 >> 8 ) & 0xff , V_2 -> V_12 + V_8 + 1 ) ;
if ( ( V_10 & 0xff0000 ) && ( V_4 -> V_13 > 16 ) )
F_3 ( ( V_4 -> V_11 >> 16 ) & 0xff , V_2 -> V_12 + V_8 + 2 ) ;
if ( ( V_10 & 0xff000000 ) && ( V_4 -> V_13 > 24 ) )
F_3 ( ( V_4 -> V_11 >> 24 ) & 0xff , V_2 -> V_12 + V_8 + 3 ) ;
}
V_7 [ 1 ] = V_4 -> V_11 ;
return V_6 -> V_14 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_15 ;
V_15 = F_5 ( V_2 -> V_12 + V_8 ) ;
if ( V_4 -> V_13 > 8 )
V_15 |= ( F_5 ( V_2 -> V_12 + V_8 + 1 ) << 8 ) ;
if ( V_4 -> V_13 > 16 )
V_15 |= ( F_5 ( V_2 -> V_12 + V_8 + 2 ) << 16 ) ;
if ( V_4 -> V_13 > 24 )
V_15 |= ( F_5 ( V_2 -> V_12 + V_8 + 3 ) << 24 ) ;
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 , V_4 ) ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
const struct V_18 * V_19 = F_8 ( V_2 ) ;
struct V_3 * V_4 ;
int V_20 ;
int V_21 ;
V_21 = F_9 ( V_2 , V_17 -> V_22 [ 0 ] , V_19 -> V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_2 , V_19 -> V_24 ) ;
if ( V_21 )
return V_21 ;
V_20 = 0 ;
if ( V_19 -> V_25 ) {
V_4 = & V_2 -> V_26 [ V_20 ++ ] ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_13 = V_19 -> V_25 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = F_1 ;
V_4 -> V_9 = ( void * ) 0 ;
if ( V_19 -> V_34 )
V_4 -> V_11 = F_4 ( V_2 , V_4 ) ;
}
if ( V_19 -> V_35 ) {
V_4 = & V_2 -> V_26 [ V_20 ++ ] ;
V_4 -> type = V_36 ;
V_4 -> V_28 = V_37 ;
V_4 -> V_13 = V_19 -> V_35 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = F_6 ;
V_4 -> V_9 = V_19 -> V_38 ? ( void * ) 2 :
V_19 -> V_39 ? ( void * ) 1 : ( void * ) 0 ;
}
if ( V_19 -> V_40 ) {
V_4 = & V_2 -> V_26 [ V_20 ++ ] ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_13 = V_19 -> V_41 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = F_1 ;
V_4 -> V_9 = ( void * ) 2 ;
V_4 = & V_2 -> V_26 [ V_20 ++ ] ;
V_4 -> type = V_36 ;
V_4 -> V_28 = V_37 ;
V_4 -> V_13 = V_19 -> V_41 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = F_6 ;
V_4 -> V_9 = ( void * ) 2 ;
}
return 0 ;
}
