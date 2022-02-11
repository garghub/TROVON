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
F_3 ( L_1 , V_4 ) ;
return - 1 ;
}
return V_5 [ 1 ] ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
int V_4 ;
unsigned char V_13 [ 2 ] ;
struct V_6 V_7 [] = {
{
. V_3 = V_8 ,
. V_9 = 0 ,
. V_5 = & V_13 [ 0 ] ,
. V_10 = 2
}
} ;
V_13 [ 0 ] = V_3 ;
V_13 [ 1 ] = V_12 ;
V_4 = F_2 ( V_2 , V_7 , 1 ) ;
if ( V_4 != 1 ) {
F_3 ( L_2 , V_4 ) ;
return - 1 ;
}
F_5 ( 10 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_16 , V_17 ;
V_15 -> V_18 = F_1 ( V_2 , 63 ) ;
for ( V_16 = 64 , V_17 = 0 ; V_16 < 70 ; V_16 ++ , V_17 ++ )
V_15 -> V_19 [ 0 ] . V_20 [ V_17 ] = F_1 ( V_2 , V_16 ) ;
for ( V_16 = 70 , V_17 = 0 ; V_16 < 76 ; V_16 ++ , V_17 ++ )
V_15 -> V_19 [ 1 ] . V_20 [ V_17 ] = F_1 ( V_2 , V_16 ) ;
}
