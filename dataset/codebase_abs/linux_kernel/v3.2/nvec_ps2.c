static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 [] = V_4 ;
return F_2 ( V_5 . V_6 , V_3 , sizeof( V_3 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned char V_3 [] = V_7 ;
F_2 ( V_5 . V_6 , V_3 , sizeof( V_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_8 )
{
unsigned char V_3 [] = V_9 ;
V_3 [ 2 ] = V_8 & 0xff ;
F_5 ( & V_2 -> V_10 , L_1 , V_8 ) ;
return F_2 ( V_5 . V_6 , V_3 , sizeof( V_3 ) ) ;
}
static int F_6 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
int V_15 ;
unsigned char * V_16 = ( unsigned char * ) V_14 ;
switch ( V_13 ) {
case V_17 :
for ( V_15 = 0 ; V_15 < V_16 [ 1 ] ; V_15 ++ )
F_7 ( V_5 . V_2 , V_16 [ 2 + V_15 ] , 0 ) ;
return V_18 ;
case V_19 :
if ( V_16 [ 2 ] == 1 )
for ( V_15 = 0 ; V_15 < ( V_16 [ 1 ] - 2 ) ; V_15 ++ )
F_7 ( V_5 . V_2 , V_16 [ V_15 + 4 ] , 0 ) ;
else if ( V_16 [ 1 ] != 2 ) {
F_8 ( V_20 , L_2 ,
V_21 , 16 , 1 ,
V_16 , V_16 [ 1 ] + 2 , true ) ;
}
return V_18 ;
}
return V_22 ;
}
static int T_1 F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_6 = F_10 ( V_24 -> V_10 . V_26 ) ;
struct V_1 * V_2 = F_11 ( sizeof( struct V_1 ) , V_27 ) ;
V_2 -> V_28 . type = V_29 ;
V_2 -> V_30 = F_4 ;
V_2 -> V_31 = F_1 ;
V_2 -> V_32 = F_3 ;
F_12 ( V_2 -> V_33 , L_3 , sizeof( V_2 -> V_33 ) ) ;
F_12 ( V_2 -> V_34 , L_4 , sizeof( V_2 -> V_34 ) ) ;
V_5 . V_2 = V_2 ;
V_5 . V_35 . V_36 = F_6 ;
V_5 . V_6 = V_6 ;
F_13 ( V_6 , & V_5 . V_35 , 0 ) ;
F_14 ( V_2 ) ;
F_2 ( V_6 , V_37 , 4 ) ;
return 0 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_38 ) ;
}
