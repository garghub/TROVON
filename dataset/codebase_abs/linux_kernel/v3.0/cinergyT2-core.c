static int F_1 ( struct V_1 * V_2 , int V_3 )
{
char V_4 [] = { V_5 , V_3 ? 1 : 0 } ;
char V_6 [ 64 ] ;
return F_2 ( V_2 -> V_7 , V_4 , sizeof( V_4 ) , V_6 ,
sizeof( V_6 ) , 0 ) ;
}
static int F_3 ( struct V_8 * V_9 , int V_3 )
{
char V_4 [] = { V_10 , V_3 ? 0 : 1 } ;
char V_11 [ 3 ] ;
return F_2 ( V_9 , V_4 , sizeof( V_4 ) , V_11 , sizeof( V_11 ) , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
char V_12 [] = { V_13 } ;
char V_11 [ 3 ] ;
int V_14 ;
V_2 -> V_15 = F_5 ( V_2 -> V_7 ) ;
V_14 = F_2 ( V_2 -> V_7 , V_12 , sizeof( V_12 ) , V_11 ,
sizeof( V_11 ) , 0 ) ;
if ( V_14 < 0 ) {
F_6 ( L_1
L_2 ) ;
}
V_16 = V_2 -> V_7 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , T_1 * V_17 , int * V_11 )
{
struct V_18 * V_19 = V_9 -> V_20 ;
T_2 V_21 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } , V_22 = V_23 ;
int V_24 ;
* V_11 = V_25 ;
F_2 ( V_9 , & V_22 , 1 , V_21 , sizeof( V_21 ) , 0 ) ;
if ( V_21 [ 4 ] == 0xff ) {
V_19 -> V_26 ++ ;
if ( V_19 -> V_26 > V_27 ) {
for ( V_24 = 0 ; V_24 < F_8 ( V_28 ) ; V_24 ++ ) {
if ( V_9 -> V_29 == V_28 [ V_24 ] ) {
* V_11 = V_30 ;
* V_17 = V_9 -> V_29 ;
F_6 ( L_3 ,
* V_17 ) ;
return 0 ;
}
}
F_6 ( L_4 ) ;
}
return 0 ;
}
V_21 [ 2 ] = ~ V_21 [ 1 ] ;
F_9 ( V_9 , V_21 , V_17 , V_11 ) ;
if ( V_21 [ 0 ] != 0 ) {
if ( * V_17 != V_9 -> V_29 )
V_19 -> V_26 = 0 ;
F_6 ( L_5 ,
V_21 [ 0 ] , V_21 [ 1 ] , V_21 [ 2 ] , V_21 [ 3 ] , V_21 [ 4 ] ) ;
}
return 0 ;
}
static int F_10 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
return F_11 ( V_32 , & V_35 ,
V_36 , NULL , V_37 ) ;
}
static int T_3 F_12 ( void )
{
int V_38 ;
V_38 = F_13 ( & V_39 ) ;
if ( V_38 ) {
V_38 ( L_6 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_39 ) ;
}
