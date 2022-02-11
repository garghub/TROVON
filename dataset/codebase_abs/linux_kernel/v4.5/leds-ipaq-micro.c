static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 -> V_8 ) ;
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 = 4 ,
} ;
V_10 . V_14 [ 0 ] = V_15 ;
V_10 . V_14 [ 1 ] = 0 ;
if ( V_4 ) {
V_10 . V_14 [ 2 ] = 0 ;
V_10 . V_14 [ 3 ] = 1 ;
} else {
V_10 . V_14 [ 2 ] = 1 ;
V_10 . V_14 [ 3 ] = 0 ;
}
return F_3 ( V_6 , & V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long * V_16 ,
unsigned long * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 -> V_8 ) ;
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 = 4 ,
} ;
V_10 . V_14 [ 0 ] = V_15 ;
if ( * V_16 > V_18 ||
* V_17 > V_18 )
return - V_19 ;
if ( * V_16 == 0 && * V_17 == 0 ) {
* V_16 = 100 ;
* V_17 = 100 ;
}
V_10 . V_14 [ 1 ] = 0 ;
if ( * V_16 >= V_18 )
V_10 . V_14 [ 2 ] = 0 ;
else
V_10 . V_14 [ 2 ] = ( V_20 ) F_5 ( * V_16 , 100 ) ;
if ( * V_17 >= V_18 )
V_10 . V_14 [ 3 ] = 0 ;
else
V_10 . V_14 [ 3 ] = ( V_20 ) F_5 ( * V_17 , 100 ) ;
return F_3 ( V_6 , & V_10 ) ;
}
static int F_6 ( struct V_21 * V_22 )
{
int V_23 ;
V_23 = F_7 ( & V_22 -> V_7 , & V_24 ) ;
if ( V_23 ) {
F_8 ( & V_22 -> V_7 , L_1 , V_23 ) ;
return V_23 ;
}
F_9 ( & V_22 -> V_7 , L_2 ) ;
return 0 ;
}
