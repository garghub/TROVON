static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned char * V_4 ;
V_4 = F_2 ( 8 , V_5 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return;
}
switch ( V_2 -> type ) {
case V_8 : {
unsigned char V_9 = 0x07 ;
if ( V_2 -> V_10 )
V_9 &= ~ 0x04 ;
if ( V_2 -> V_11 )
V_9 &= ~ 0x02 ;
if ( V_2 -> V_12 )
V_9 &= ~ 0x01 ;
F_4 ( & V_2 -> V_6 -> V_7 ,
L_2 ,
V_2 -> V_10 , V_2 -> V_11 , V_2 -> V_12 , V_9 ) ;
V_3 = F_5 ( V_2 -> V_6 ,
F_6 ( V_2 -> V_6 , 0 ) ,
0x12 ,
0xc8 ,
( 0x02 * 0x100 ) + 0x0a ,
( 0x00 * 0x100 ) + V_9 ,
V_4 ,
8 ,
2000 ) ;
break;
}
case V_13 :
F_4 ( & V_2 -> V_6 -> V_7 ,
L_3 ,
V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_10 ) ;
V_4 [ 0 ] = V_2 -> V_11 ;
V_4 [ 1 ] = V_2 -> V_12 ;
V_4 [ 2 ] = V_2 -> V_10 ;
V_4 [ 3 ] = V_4 [ 4 ] = V_4 [ 5 ] = 0 ;
V_4 [ 6 ] = 0x1a ;
V_4 [ 7 ] = 0x05 ;
V_3 = F_5 ( V_2 -> V_6 ,
F_6 ( V_2 -> V_6 , 0 ) ,
0x09 ,
0x21 ,
0x200 ,
0 ,
V_4 ,
8 ,
2000 ) ;
break;
default:
F_3 ( & V_2 -> V_6 -> V_7 , L_4 , V_2 -> type ) ;
}
if ( V_3 )
F_4 ( & V_2 -> V_6 -> V_7 , L_5 , V_3 ) ;
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_14 * V_15 , const struct V_16 * V_17 )
{
struct V_18 * V_6 = F_9 ( V_15 ) ;
struct V_1 * V_7 = NULL ;
int V_3 = - V_19 ;
V_7 = F_10 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_7 == NULL ) {
F_3 ( & V_15 -> V_7 , L_1 ) ;
goto V_20;
}
V_7 -> V_6 = F_11 ( V_6 ) ;
V_7 -> type = V_17 -> V_21 ;
F_12 ( V_15 , V_7 ) ;
V_3 = F_13 ( & V_15 -> V_7 , & V_22 ) ;
if ( V_3 )
goto error;
V_3 = F_13 ( & V_15 -> V_7 , & V_23 ) ;
if ( V_3 )
goto error;
V_3 = F_13 ( & V_15 -> V_7 , & V_24 ) ;
if ( V_3 )
goto error;
if ( V_7 -> type == V_13 ) {
unsigned char * V_25 ;
V_25 = F_14 ( L_6 , 8 , V_5 ) ;
if ( ! V_25 ) {
F_3 ( & V_15 -> V_7 , L_1 ) ;
V_3 = - V_19 ;
goto error;
}
V_3 = F_5 ( V_6 ,
F_6 ( V_6 , 0 ) ,
0x09 ,
0x21 ,
0x200 ,
0 ,
V_25 ,
8 ,
2000 ) ;
F_7 ( V_25 ) ;
if ( V_3 != 8 )
goto error;
}
F_15 ( & V_15 -> V_7 , L_7 ) ;
return 0 ;
error:
F_16 ( & V_15 -> V_7 , & V_22 ) ;
F_16 ( & V_15 -> V_7 , & V_23 ) ;
F_16 ( & V_15 -> V_7 , & V_24 ) ;
F_12 ( V_15 , NULL ) ;
F_17 ( V_7 -> V_6 ) ;
F_7 ( V_7 ) ;
V_20:
return V_3 ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_7 ;
V_7 = F_19 ( V_15 ) ;
F_16 ( & V_15 -> V_7 , & V_22 ) ;
F_16 ( & V_15 -> V_7 , & V_23 ) ;
F_16 ( & V_15 -> V_7 , & V_24 ) ;
F_12 ( V_15 , NULL ) ;
F_17 ( V_7 -> V_6 ) ;
F_7 ( V_7 ) ;
F_15 ( & V_15 -> V_7 , L_8 ) ;
}
static int T_1 F_20 ( void )
{
int V_3 = 0 ;
V_3 = F_21 ( & V_26 ) ;
if ( V_3 )
F_22 ( L_9 , V_3 ) ;
return V_3 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_26 ) ;
}
