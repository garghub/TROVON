static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 [] = V_4 ;
F_2 ( V_5 . V_6 , V_3 , sizeof( V_3 ) ) ;
return 0 ;
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
F_2 ( V_5 . V_6 , V_3 , sizeof( V_3 ) ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
int V_15 ;
unsigned char * V_16 = ( unsigned char * ) V_14 ;
switch ( V_13 ) {
case V_17 :
F_7 ( V_5 . V_2 , V_16 [ 2 ] , 0 ) ;
return V_18 ;
case V_19 :
if ( V_16 [ 2 ] == 1 )
for( V_15 = 0 ; V_15 < ( V_16 [ 1 ] - 2 ) ; V_15 ++ )
F_7 ( V_5 . V_2 , V_16 [ V_15 + 4 ] , 0 ) ;
else if ( V_16 [ 1 ] != 2 )
{
F_8 ( L_2 ) ;
for( V_15 = 0 ; V_15 <= ( V_16 [ 1 ] + 1 ) ; V_15 ++ )
F_8 ( L_3 , V_16 [ V_15 ] ) ;
F_8 ( L_4 ) ;
}
return V_18 ;
}
return V_20 ;
}
int T_1 F_9 ( struct V_21 * V_6 )
{
struct V_1 * V_2 = F_10 ( sizeof( struct V_1 ) , V_22 ) ;
V_2 -> V_23 . type = V_24 ;
V_2 -> V_25 = F_4 ;
V_2 -> V_26 = F_1 ;
V_2 -> V_27 = F_3 ;
F_11 ( V_2 -> V_28 , L_5 , sizeof( V_2 -> V_28 ) ) ;
F_11 ( V_2 -> V_29 , L_6 , sizeof( V_2 -> V_29 ) ) ;
V_5 . V_2 = V_2 ;
V_5 . V_30 . V_31 = F_6 ;
V_5 . V_6 = V_6 ;
F_12 ( V_6 , & V_5 . V_30 , 0 ) ;
F_13 ( V_2 ) ;
F_2 ( V_6 , L_7 , 4 ) ;
return 0 ;
}
