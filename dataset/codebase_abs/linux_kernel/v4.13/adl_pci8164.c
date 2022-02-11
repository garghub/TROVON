static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 = F_2 ( V_6 -> V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ )
V_7 [ V_12 ] = F_3 ( V_2 -> V_14 + F_4 ( V_10 ) + V_8 ) ;
return V_6 -> V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 = F_2 ( V_6 -> V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ )
F_6 ( V_7 [ V_12 ] , V_2 -> V_14 + F_4 ( V_10 ) + V_8 ) ;
return V_6 -> V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_14 = F_10 ( V_17 , 2 ) ;
V_18 = F_11 ( V_2 , 4 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_19 [ 0 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 | V_23 ;
V_4 -> V_24 = 4 ;
V_4 -> V_25 = 0xffff ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = F_1 ;
V_4 -> V_28 = F_5 ;
V_4 -> V_9 = ( void * ) V_29 ;
V_4 = & V_2 -> V_19 [ 1 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 | V_23 ;
V_4 -> V_24 = 4 ;
V_4 -> V_25 = 0xffff ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = F_1 ;
V_4 -> V_28 = F_5 ;
V_4 -> V_9 = ( void * ) V_30 ;
V_4 = & V_2 -> V_19 [ 2 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 | V_23 ;
V_4 -> V_24 = 4 ;
V_4 -> V_25 = 0xffff ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = F_1 ;
V_4 -> V_28 = F_5 ;
V_4 -> V_9 = ( void * ) V_31 ;
V_4 = & V_2 -> V_19 [ 3 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 | V_23 ;
V_4 -> V_24 = 4 ;
V_4 -> V_25 = 0xffff ;
V_4 -> V_26 = 4 ;
V_4 -> V_27 = F_1 ;
V_4 -> V_28 = F_5 ;
V_4 -> V_9 = ( void * ) V_32 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_2 ,
const struct V_33 * V_34 )
{
return F_13 ( V_2 , & V_35 ,
V_34 -> V_36 ) ;
}
