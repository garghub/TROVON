static unsigned int F_1 ( const T_1 * V_1 )
{
return 1 + ( V_1 [ 0 ] & 7 ) ;
}
static int F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_3 , V_5 -> V_8 ) ;
struct V_6 * V_9 ;
unsigned int V_10 = 7 , V_11 ;
const T_1 * V_1 , * V_12 = V_5 -> V_13 ;
V_1 = F_4 ( V_12 ) ;
if ( V_1 ) {
V_9 = F_3 ( V_3 , V_14 ) ;
for ( V_11 = F_5 ( V_12 ) ; V_11 > 0 ; V_11 -- , V_1 += 3 ) {
unsigned V_15 = F_1 ( V_1 ) ;
if ( V_9 -> V_16 <= V_15 )
V_10 |= V_1 [ 1 ] ;
}
}
return F_6 ( V_7 , F_7 ( V_17 ) , V_17 ,
V_10 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_9 = F_3 ( V_3 , V_5 -> V_8 ) ;
struct V_6 * V_7 ;
struct V_6 V_18 = { . V_16 = 1 , . V_19 = 2 , . integer = 1 , } ;
unsigned int V_11 ;
const T_1 * V_1 , * V_12 = V_5 -> V_13 ;
V_1 = F_4 ( V_12 ) ;
if ( V_1 ) {
unsigned int V_10 = 0 ;
V_7 = F_3 ( V_3 , V_20 ) ;
for ( V_11 = 0 ; V_11 < F_7 ( V_17 ) ; V_11 ++ )
if ( V_7 -> V_16 <= V_17 [ V_11 ] && V_7 -> V_19 >= V_17 [ V_11 ] )
V_10 |= F_9 ( V_11 ) ;
for ( V_11 = F_5 ( V_12 ) ; V_11 > 0 ; V_11 -- , V_1 += 3 )
if ( V_10 & V_1 [ 1 ] )
V_18 . V_19 = V_19 ( V_18 . V_19 , F_1 ( V_1 ) ) ;
}
return F_10 ( V_9 , & V_18 ) ;
}
int F_11 ( struct V_21 * V_22 , void * V_12 )
{
int V_23 ;
V_23 = F_12 ( V_22 , 0 , V_20 ,
F_2 , V_12 ,
V_14 , - 1 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_12 ( V_22 , 0 , V_14 ,
F_8 , V_12 ,
V_20 , - 1 ) ;
return V_23 ;
}
