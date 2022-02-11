int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
unsigned char V_5 [ 2 ] ;
struct V_6 V_7 [] = {
{
. V_3 = V_8 ,
. V_9 = 0 ,
. V_5 = & V_5 [ 0 ] ,
. V_10 = 1
} , {
. V_3 = V_8 ,
. V_9 = V_11 ,
. V_5 = & V_5 [ 1 ] ,
. V_10 = 1
}
} ;
V_5 [ 0 ] = V_3 ;
V_5 [ 1 ] = 0x0 ;
V_4 = F_2 ( V_2 , V_7 , 2 ) ;
if ( V_4 != 2 ) {
F_3 ( V_12 L_1 , V_4 ) ;
return - 1 ;
}
return V_5 [ 1 ] ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 )
{
int V_4 ;
unsigned char V_14 [ 2 ] ;
struct V_6 V_7 [] = {
{
. V_3 = V_8 ,
. V_9 = 0 ,
. V_5 = & V_14 [ 0 ] ,
. V_10 = 2
}
} ;
V_14 [ 0 ] = V_3 ;
V_14 [ 1 ] = V_13 ;
V_4 = F_2 ( V_2 , V_7 , 1 ) ;
if ( V_4 != 1 ) {
F_3 ( V_12 L_2 , V_4 ) ;
return - 1 ;
}
F_5 ( 10 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_17 , V_18 ;
V_16 -> V_19 = F_1 ( V_2 , 63 ) ;
for ( V_17 = 64 , V_18 = 0 ; V_17 < 70 ; V_17 ++ , V_18 ++ )
V_16 -> V_20 [ 0 ] . V_21 [ V_18 ] = F_1 ( V_2 , V_17 ) ;
for ( V_17 = 70 , V_18 = 0 ; V_17 < 76 ; V_17 ++ , V_18 ++ )
V_16 -> V_20 [ 1 ] . V_21 [ V_18 ] = F_1 ( V_2 , V_17 ) ;
}
