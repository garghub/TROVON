static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = V_3 | 0x80 ;
return F_3 ( V_6 , V_4 , 1 , V_4 , 1 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 & 0x7F ;
V_7 [ 1 ] = V_4 ;
return F_3 ( V_6 , V_7 , 2 , NULL , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_10 ;
unsigned char V_7 [ 8 ] ;
V_7 [ 0 ] = V_11 | 0x80 ;
V_10 = F_3 ( V_6 , V_7 , 1 , V_7 , 8 ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_12 = F_6 ( V_7 [ 0 ] ) ;
V_9 -> V_13 = F_6 ( V_7 [ 1 ] ) ;
V_9 -> V_14 = F_6 ( V_7 [ 2 ] & 0x3F ) ;
V_9 -> V_15 = F_6 ( V_7 [ 3 ] ) ;
V_9 -> V_16 = F_6 ( V_7 [ 4 ] ) - 1 ;
V_9 -> V_17 = F_6 ( V_7 [ 5 ] ) - 1 ;
V_9 -> V_18 = F_6 ( V_7 [ 6 ] ) + 100 ;
return F_7 ( V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 9 ] ;
if ( V_9 -> V_18 < 100 || V_9 -> V_18 > 199 ) {
F_9 ( & V_6 -> V_2 , L_1 ,
V_9 -> V_18 + 1900 ) ;
return - V_19 ;
}
V_7 [ 0 ] = V_11 & 0x7F ;
V_7 [ 1 ] = F_10 ( V_9 -> V_12 ) ;
V_7 [ 2 ] = F_10 ( V_9 -> V_13 ) ;
V_7 [ 3 ] = ( F_10 ( V_9 -> V_14 ) & 0X3F ) ;
V_7 [ 4 ] = F_10 ( V_9 -> V_15 ) ;
V_7 [ 5 ] = F_10 ( V_9 -> V_16 + 1 ) ;
V_7 [ 6 ] = F_10 ( V_9 -> V_17 + 1 ) ;
V_7 [ 7 ] = F_10 ( V_9 -> V_18 % 100 ) ;
V_7 [ 8 ] = F_10 ( 0x00 ) ;
return F_3 ( V_6 , V_7 , 9 , NULL , 0 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_20 * V_21 ;
unsigned char V_4 ;
int V_22 ;
V_6 -> V_23 = V_24 ;
V_6 -> V_25 = 8 ;
F_12 ( V_6 ) ;
V_22 = F_1 ( & V_6 -> V_2 , V_26 , & V_4 ) ;
if ( V_22 )
return V_22 ;
F_1 ( & V_6 -> V_2 , V_27 , & V_4 ) ;
V_4 = V_4 & ~ ( 1 << 7 ) ;
F_4 ( & V_6 -> V_2 , V_27 , V_4 ) ;
F_1 ( & V_6 -> V_2 , V_28 , & V_4 ) ;
V_4 = V_4 & 0x1B ;
F_4 ( & V_6 -> V_2 , V_28 , V_4 ) ;
F_1 ( & V_6 -> V_2 , V_27 , & V_4 ) ;
F_13 ( & V_6 -> V_2 , L_2 , V_4 ) ;
F_1 ( & V_6 -> V_2 , V_28 , & V_4 ) ;
F_13 ( & V_6 -> V_2 , L_3 , V_4 ) ;
V_21 = F_14 ( & V_6 -> V_2 , L_4 ,
& V_29 , V_30 ) ;
if ( F_15 ( V_21 ) )
return F_16 ( V_21 ) ;
F_17 ( V_6 , V_21 ) ;
return 0 ;
}
