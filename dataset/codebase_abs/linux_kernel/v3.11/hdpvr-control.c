int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
char V_6 = 0x38 , V_7 = 0x01 ;
F_2 ( & V_2 -> V_8 ) ;
V_2 -> V_9 [ 0 ] = V_4 ;
V_5 = F_3 ( V_2 -> V_10 ,
F_4 ( V_2 -> V_10 , 0 ) ,
V_7 , 0x00 | V_6 ,
V_3 , V_11 ,
V_2 -> V_9 , 1 , 10000 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_6 ( V_12 , V_13 , & V_2 -> V_14 ,
L_1 , V_3 ,
V_5 ) ;
return V_5 < 0 ? V_5 : 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_5 ;
V_16 -> V_17 = false ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_2 -> V_10 ,
F_8 ( V_2 -> V_10 , 0 ) ,
0x81 , 0x80 | 0x38 ,
0x1400 , 0x0003 ,
V_2 -> V_9 , 5 ,
1000 ) ;
#ifdef F_9
if ( V_13 & V_12 ) {
char V_18 [ 15 ] ;
F_10 ( V_2 -> V_9 , 5 , 16 , 1 , V_18 ,
sizeof( V_18 ) , 0 ) ;
F_6 ( V_12 , V_13 , & V_2 -> V_14 ,
L_2 , V_5 , V_18 ) ;
}
#endif
F_5 ( & V_2 -> V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_16 -> V_19 = V_2 -> V_9 [ 1 ] << 8 | V_2 -> V_9 [ 0 ] ;
V_16 -> V_20 = V_2 -> V_9 [ 3 ] << 8 | V_2 -> V_9 [ 2 ] ;
V_16 -> V_21 = V_2 -> V_9 [ 4 ] ;
V_16 -> V_17 = V_16 -> V_19 && V_16 -> V_20 && V_16 -> V_21 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
#ifdef F_9
char V_18 [ 9 ] ;
#endif
int V_5 , V_22 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_2 -> V_10 ,
F_8 ( V_2 -> V_10 , 0 ) ,
0x81 , 0x80 | 0x38 ,
0x1800 , 0x0003 ,
V_2 -> V_9 , 3 ,
1000 ) ;
#ifdef F_9
if ( V_13 & V_12 ) {
F_10 ( V_2 -> V_9 , 3 , 16 , 1 , V_18 ,
sizeof( V_18 ) , 0 ) ;
F_6 ( V_12 , V_13 , & V_2 -> V_14 ,
L_3 , V_5 ,
V_18 ) ;
}
#else
( void ) V_5 ;
#endif
V_22 = V_2 -> V_9 [ 1 ] << 8 | V_2 -> V_9 [ 0 ] ;
F_5 ( & V_2 -> V_8 ) ;
return V_22 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
F_2 ( & V_2 -> V_8 ) ;
memset ( V_2 -> V_9 , 0 , 4 ) ;
V_2 -> V_9 [ 0 ] = V_2 -> V_23 . V_24 ;
V_2 -> V_9 [ 2 ] = V_2 -> V_23 . V_25 ;
V_5 = F_3 ( V_2 -> V_10 ,
F_4 ( V_2 -> V_10 , 0 ) ,
0x01 , 0x38 , V_26 ,
V_11 , V_2 -> V_9 , 4 , 1000 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_27 ,
enum V_28 V_29 )
{
int V_5 = 0 ;
if ( V_2 -> V_30 & V_31 ) {
F_2 ( & V_2 -> V_8 ) ;
memset ( V_2 -> V_9 , 0 , 2 ) ;
V_2 -> V_9 [ 0 ] = V_27 ;
if ( V_29 == V_32 )
V_2 -> V_9 [ 1 ] = 0 ;
else if ( V_29 == V_33 )
V_2 -> V_9 [ 1 ] = 1 ;
else {
F_5 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_14 , L_4 ,
V_29 ) ;
V_5 = - V_34 ;
goto error;
}
V_5 = F_3 ( V_2 -> V_10 ,
F_4 ( V_2 -> V_10 , 0 ) ,
0x01 , 0x38 , V_35 ,
V_11 , V_2 -> V_9 , 2 ,
1000 ) ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_5 == 2 )
V_5 = 0 ;
} else
V_5 = F_1 ( V_2 , V_35 , V_27 ) ;
error:
return V_5 ;
}
int F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_36 , V_2 -> V_23 . V_37 ) ;
F_1 ( V_2 , V_38 ,
V_2 -> V_23 . V_39 + 1 ) ;
F_13 ( V_2 , V_2 -> V_23 . V_40 + 1 ,
V_2 -> V_23 . V_41 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , V_42 ,
V_2 -> V_23 . V_43 ) ;
F_1 ( V_2 , V_44 , V_2 -> V_23 . V_45 ) ;
F_1 ( V_2 , V_46 , V_2 -> V_23 . V_47 ) ;
F_1 ( V_2 , V_48 , V_2 -> V_23 . V_49 ) ;
F_1 ( V_2 , V_50 , V_2 -> V_23 . V_51 ) ;
F_1 ( V_2 , V_52 , V_2 -> V_23 . V_53 ) ;
F_1 ( V_2 , V_54 , V_2 -> V_23 . V_55 ) ;
return 0 ;
}
