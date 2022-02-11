static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
int V_9 ;
unsigned char V_10 [ 8 ] ;
V_8 = F_3 ( V_6 ) ;
V_9 = F_4 ( V_8 , V_11 , V_10 , 8 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_12 = F_5 ( V_10 [ 0 ] ) ;
V_4 -> V_13 = F_5 ( V_10 [ 1 ] ) ;
V_4 -> V_14 = F_5 ( V_10 [ 2 ] & 0x3F ) ;
V_4 -> V_15 = F_5 ( V_10 [ 3 ] ) ;
V_4 -> V_16 = F_5 ( V_10 [ 4 ] ) - 1 ;
V_4 -> V_17 = F_5 ( V_10 [ 5 ] ) - 1 ;
V_4 -> V_18 = F_5 ( V_10 [ 6 ] ) + 100 ;
return F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
unsigned char V_10 [ 8 ] ;
V_8 = F_3 ( V_6 ) ;
V_10 [ 0 ] = F_8 ( V_4 -> V_12 ) ;
V_10 [ 1 ] = F_8 ( V_4 -> V_13 ) ;
V_10 [ 2 ] = ( F_8 ( V_4 -> V_14 ) & 0x3F ) ;
V_10 [ 3 ] = F_8 ( V_4 -> V_15 ) ;
V_10 [ 4 ] = F_8 ( V_4 -> V_16 + 1 ) ;
V_10 [ 5 ] = F_8 ( V_4 -> V_17 + 1 ) ;
V_4 -> V_18 = V_4 -> V_18 % 100 ;
V_10 [ 6 ] = F_8 ( V_4 -> V_18 ) ;
V_10 [ 7 ] = F_8 ( 0x00 ) ;
return F_9 ( V_8 , V_11 , V_10 , 8 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_19 * V_20 ;
struct V_21 V_22 ;
struct V_7 * V_8 ;
unsigned int V_23 ;
int V_24 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_25 = 8 ;
V_22 . V_26 = 8 ;
V_22 . V_27 = 0x80 ;
V_22 . V_28 = 0x3F ;
V_22 . V_29 = & V_30 ;
V_6 -> V_31 = V_32 ;
V_6 -> V_33 = 8 ;
F_11 ( V_6 ) ;
V_8 = F_12 ( V_6 , & V_22 ) ;
if ( F_13 ( V_8 ) ) {
F_14 ( & V_6 -> V_2 , L_1 ) ;
return F_15 ( V_8 ) ;
}
F_16 ( V_6 , V_8 ) ;
V_24 = F_17 ( V_8 , V_34 , & V_23 ) ;
if ( V_24 )
return V_24 ;
F_17 ( V_8 , V_35 , & V_23 ) ;
V_23 = V_23 & ~ ( 1 << 7 ) ;
F_18 ( V_8 , V_35 , V_23 ) ;
F_17 ( V_8 , V_36 , & V_23 ) ;
V_23 = V_23 & 0x1B ;
F_18 ( V_8 , V_36 , V_23 ) ;
F_17 ( V_8 , V_35 , & V_23 ) ;
F_19 ( & V_6 -> V_2 , L_2 , V_23 ) ;
F_17 ( V_8 , V_36 , & V_23 ) ;
F_19 ( & V_6 -> V_2 , L_3 , V_23 ) ;
V_20 = F_20 ( & V_6 -> V_2 , L_4 ,
& V_37 , V_38 ) ;
if ( F_13 ( V_20 ) )
return F_15 ( V_20 ) ;
return 0 ;
}
