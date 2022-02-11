static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned char * V_4 ;
int V_5 ;
V_4 = F_2 ( 8 , V_6 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
return;
}
switch ( V_2 -> type ) {
case V_9 : {
unsigned char V_10 = 0x07 ;
if ( V_2 -> V_11 )
V_10 &= ~ 0x04 ;
if ( V_2 -> V_12 )
V_10 &= ~ 0x02 ;
if ( V_2 -> V_13 )
V_10 &= ~ 0x01 ;
F_4 ( & V_2 -> V_7 -> V_8 ,
L_2 ,
V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_13 , V_10 ) ;
V_3 = F_5 ( V_2 -> V_7 ,
F_6 ( V_2 -> V_7 , 0 ) ,
0x12 ,
0xc8 ,
( 0x02 * 0x100 ) + 0x0a ,
( 0x00 * 0x100 ) + V_10 ,
V_4 ,
8 ,
2000 ) ;
break;
}
case V_14 :
F_4 ( & V_2 -> V_7 -> V_8 ,
L_3 ,
V_2 -> V_12 , V_2 -> V_13 , V_2 -> V_11 ) ;
V_4 [ 0 ] = V_2 -> V_12 ;
V_4 [ 1 ] = V_2 -> V_13 ;
V_4 [ 2 ] = V_2 -> V_11 ;
V_4 [ 3 ] = V_4 [ 4 ] = V_4 [ 5 ] = 0 ;
V_4 [ 6 ] = 0x1a ;
V_4 [ 7 ] = 0x05 ;
V_3 = F_5 ( V_2 -> V_7 ,
F_6 ( V_2 -> V_7 , 0 ) ,
0x09 ,
0x21 ,
0x200 ,
0 ,
V_4 ,
8 ,
2000 ) ;
break;
case V_15 :
V_4 [ 0 ] = F_7 ( V_2 -> V_12 , V_2 -> V_13 , V_2 -> V_11 ) ;
V_4 [ 1 ] = 0 ;
V_4 [ 2 ] = 0 ;
V_4 [ 3 ] = 0 ;
V_4 [ 4 ] = 0 ;
V_3 = F_8 ( V_2 -> V_7 ,
F_6 ( V_2 -> V_7 , 2 ) ,
V_4 , 5 , & V_5 , 1000 ) ;
break;
default:
F_3 ( & V_2 -> V_7 -> V_8 , L_4 , V_2 -> type ) ;
}
if ( V_3 )
F_4 ( & V_2 -> V_7 -> V_8 , L_5 , V_3 ) ;
F_9 ( V_4 ) ;
}
static int F_10 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_20 * V_7 = F_11 ( V_17 ) ;
struct V_1 * V_8 = NULL ;
int V_3 = - V_21 ;
V_8 = F_12 ( sizeof( struct V_1 ) , V_6 ) ;
if ( V_8 == NULL ) {
F_3 ( & V_17 -> V_8 , L_1 ) ;
goto V_22;
}
V_8 -> V_7 = F_13 ( V_7 ) ;
V_8 -> type = V_19 -> V_23 ;
F_14 ( V_17 , V_8 ) ;
V_3 = F_15 ( & V_17 -> V_8 , & V_24 ) ;
if ( V_3 )
goto error;
V_3 = F_15 ( & V_17 -> V_8 , & V_25 ) ;
if ( V_3 )
goto error;
V_3 = F_15 ( & V_17 -> V_8 , & V_26 ) ;
if ( V_3 )
goto error;
if ( V_8 -> type == V_14 ) {
unsigned char * V_27 ;
V_27 = F_16 ( L_6 , 8 , V_6 ) ;
if ( ! V_27 ) {
F_3 ( & V_17 -> V_8 , L_1 ) ;
V_3 = - V_21 ;
goto error;
}
V_3 = F_5 ( V_7 ,
F_6 ( V_7 , 0 ) ,
0x09 ,
0x21 ,
0x200 ,
0 ,
V_27 ,
8 ,
2000 ) ;
F_9 ( V_27 ) ;
if ( V_3 != 8 )
goto error;
}
F_17 ( & V_17 -> V_8 , L_7 ) ;
return 0 ;
error:
F_18 ( & V_17 -> V_8 , & V_24 ) ;
F_18 ( & V_17 -> V_8 , & V_25 ) ;
F_18 ( & V_17 -> V_8 , & V_26 ) ;
F_14 ( V_17 , NULL ) ;
F_19 ( V_8 -> V_7 ) ;
F_9 ( V_8 ) ;
V_22:
return V_3 ;
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_8 ;
V_8 = F_21 ( V_17 ) ;
F_18 ( & V_17 -> V_8 , & V_24 ) ;
F_18 ( & V_17 -> V_8 , & V_25 ) ;
F_18 ( & V_17 -> V_8 , & V_26 ) ;
F_14 ( V_17 , NULL ) ;
F_19 ( V_8 -> V_7 ) ;
F_9 ( V_8 ) ;
F_17 ( & V_17 -> V_8 , L_8 ) ;
}
