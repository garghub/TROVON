static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 & 0x7f ;
V_7 [ 1 ] = V_4 ;
return F_3 ( V_6 , V_7 , 2 , NULL , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = V_3 | 0x80 ;
return F_3 ( V_6 , V_4 , 1 , V_4 , 1 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
int V_10 , V_11 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 8 ] ;
V_7 [ 0 ] = 0xbf ;
V_10 = F_3 ( V_6 , V_7 , 1 , V_7 , 8 ) ;
if ( V_10 != 0 )
return V_10 ;
V_9 -> V_12 = F_6 ( V_7 [ 0 ] ) ;
V_9 -> V_13 = F_6 ( V_7 [ 1 ] ) ;
V_9 -> V_14 = F_6 ( V_7 [ 2 ] ) ;
V_9 -> V_15 = F_6 ( V_7 [ 3 ] ) ;
V_9 -> V_16 = F_6 ( V_7 [ 4 ] ) - 1 ;
V_9 -> V_17 = F_6 ( V_7 [ 5 ] ) ;
V_9 -> V_18 = F_6 ( V_7 [ 6 ] ) ;
V_10 = F_4 ( V_2 , V_19 , & V_7 [ 0 ] ) ;
if ( V_10 != 0 )
return V_10 ;
V_11 = F_6 ( V_7 [ 0 ] ) * 100 ;
V_9 -> V_18 += V_11 ;
V_9 -> V_18 -= 1900 ;
return F_7 ( V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
V_9 -> V_18 = V_9 -> V_18 + 1900 ;
F_1 ( V_2 , V_20 , 0 ) ;
F_1 ( V_2 , V_21 , F_9 ( V_9 -> V_12 ) ) ;
F_1 ( V_2 , V_22 , F_9 ( V_9 -> V_13 ) ) ;
F_1 ( V_2 , V_23 , F_9 ( V_9 -> V_14 ) ) ;
F_1 ( V_2 , V_24 , F_9 ( V_9 -> V_15 ) ) ;
F_1 ( V_2 , V_25 , F_9 ( V_9 -> V_16 + 1 ) ) ;
F_1 ( V_2 , V_26 , F_9 ( V_9 -> V_17 ) ) ;
F_1 ( V_2 , V_27 , F_9 ( V_9 -> V_18 % 100 ) ) ;
F_1 ( V_2 , V_19 , F_9 ( V_9 -> V_18 / 100 ) ) ;
F_1 ( V_2 , V_20 , 0x80 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
unsigned char V_30 ;
int V_31 ;
V_6 -> V_32 = V_33 ;
V_6 -> V_34 = 8 ;
F_11 ( V_6 ) ;
V_31 = F_4 ( & V_6 -> V_2 , V_21 , & V_30 ) ;
if ( V_31 != 0 )
return V_31 ;
V_29 = F_12 ( & V_6 -> V_2 , L_1 ,
& V_35 , V_36 ) ;
if ( F_13 ( V_29 ) )
return F_14 ( V_29 ) ;
F_15 ( V_6 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
return 0 ;
}
