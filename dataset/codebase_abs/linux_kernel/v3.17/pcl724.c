static int F_1 ( int V_1 , int V_2 , int V_3 ,
unsigned long V_4 )
{
int V_5 = V_6 * ( V_4 >> 12 ) ;
V_4 &= 0x0fff ;
F_2 ( V_2 + V_5 , V_4 ) ;
if ( V_1 ) {
F_2 ( V_3 , V_4 + 1 ) ;
return 0 ;
}
return F_3 ( V_4 + 1 ) ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 = F_5 ( V_8 ) ;
struct V_13 * V_14 ;
unsigned long V_4 ;
unsigned int V_15 ;
int V_16 ;
int V_17 ;
int V_18 ;
V_15 = V_12 -> V_19 ;
V_16 = V_12 -> V_20 ;
if ( V_12 -> V_21 &&
( V_10 -> V_22 [ 2 ] == 1 || V_10 -> V_22 [ 2 ] == 96 ) ) {
V_15 = 0x10 ;
V_16 = 4 ;
}
V_17 = F_6 ( V_8 , V_10 -> V_22 [ 0 ] , V_15 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_8 , V_16 ) ;
if ( V_17 )
return V_17 ;
for ( V_18 = 0 ; V_18 < V_8 -> V_16 ; V_18 ++ ) {
V_14 = & V_8 -> V_23 [ V_18 ] ;
if ( V_12 -> V_24 ) {
V_4 = V_8 -> V_4 + ( V_18 * 0x1000 ) ;
V_17 = F_8 ( V_8 , V_14 , F_1 ,
V_4 ) ;
} else {
V_4 = V_8 -> V_4 + ( V_18 * V_6 ) ;
V_17 = F_8 ( V_8 , V_14 , NULL , V_4 ) ;
}
if ( V_17 )
return V_17 ;
}
return 0 ;
}
