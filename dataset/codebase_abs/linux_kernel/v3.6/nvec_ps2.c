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
F_8 ( L_2 , & V_16 [ 2 ] , V_16 [ 1 ] ) ;
return V_18 ;
case V_19 :
if ( V_16 [ 2 ] == 1 ) {
for ( V_15 = 0 ; V_15 < ( V_16 [ 1 ] - 2 ) ; V_15 ++ )
F_7 ( V_5 . V_2 , V_16 [ V_15 + 4 ] , 0 ) ;
F_8 ( L_3 , & V_16 [ 4 ] , V_16 [ 1 ] - 2 ) ;
}
else if ( V_16 [ 1 ] != 2 )
F_8 ( L_4 , V_16 , V_16 [ 1 ] + 2 ) ;
return V_18 ;
}
return V_20 ;
}
static int T_1 F_9 ( struct V_21 * V_22 )
{
struct V_23 * V_6 = F_10 ( V_22 -> V_10 . V_24 ) ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_22 -> V_10 , sizeof( struct V_1 ) , V_25 ) ;
if ( V_2 == NULL )
return - V_26 ;
V_2 -> V_27 . type = V_28 ;
V_2 -> V_29 = F_4 ;
V_2 -> V_30 = F_1 ;
V_2 -> V_31 = F_3 ;
F_12 ( V_2 -> V_32 , L_5 , sizeof( V_2 -> V_32 ) ) ;
F_12 ( V_2 -> V_33 , L_6 , sizeof( V_2 -> V_33 ) ) ;
V_5 . V_2 = V_2 ;
V_5 . V_34 . V_35 = F_6 ;
V_5 . V_6 = V_6 ;
F_13 ( V_6 , & V_5 . V_34 , 0 ) ;
F_14 ( V_2 ) ;
F_2 ( V_6 , V_36 , 4 ) ;
return 0 ;
}
static int T_2 F_15 ( struct V_21 * V_22 )
{
F_16 ( V_5 . V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_37 * V_10 )
{
struct V_21 * V_22 = F_18 ( V_10 ) ;
struct V_23 * V_6 = F_10 ( V_22 -> V_10 . V_24 ) ;
F_2 ( V_6 , L_7 , 2 ) ;
F_2 ( V_6 , L_8 , 2 ) ;
return 0 ;
}
static int F_19 ( struct V_37 * V_10 )
{
struct V_21 * V_22 = F_18 ( V_10 ) ;
struct V_23 * V_6 = F_10 ( V_22 -> V_10 . V_24 ) ;
F_1 ( V_5 . V_2 ) ;
F_2 ( V_6 , L_9 , 2 ) ;
return 0 ;
}
