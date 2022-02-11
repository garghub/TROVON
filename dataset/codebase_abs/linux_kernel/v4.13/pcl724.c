static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 ,
unsigned long V_6 )
{
int V_7 = V_8 * ( V_6 >> 12 ) ;
V_6 &= 0x0fff ;
F_2 ( V_4 + V_7 , V_6 ) ;
if ( V_3 ) {
F_2 ( V_5 , V_6 + 1 ) ;
return 0 ;
}
return F_3 ( V_6 + 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
unsigned long V_6 ;
unsigned int V_16 ;
int V_17 ;
int V_18 ;
int V_19 ;
V_16 = V_12 -> V_20 ;
V_17 = V_12 -> V_21 ;
if ( V_12 -> V_22 &&
( V_10 -> V_23 [ 2 ] == 1 || V_10 -> V_23 [ 2 ] == 96 ) ) {
V_16 = 0x10 ;
V_17 = 4 ;
}
V_18 = F_5 ( V_2 , V_10 -> V_23 [ 0 ] , V_16 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_6 ( V_2 , V_17 ) ;
if ( V_18 )
return V_18 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_17 ; V_19 ++ ) {
V_15 = & V_2 -> V_24 [ V_19 ] ;
if ( V_12 -> V_25 ) {
V_6 = V_2 -> V_6 + ( V_19 * 0x1000 ) ;
V_18 = F_7 ( V_2 , V_15 , F_1 ,
V_6 ) ;
} else {
V_18 = F_7 ( V_2 , V_15 , NULL , V_19 * V_8 ) ;
}
if ( V_18 )
return V_18 ;
}
return 0 ;
}
