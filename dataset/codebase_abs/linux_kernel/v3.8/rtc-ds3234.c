static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 | 0x80 ;
V_7 [ 1 ] = V_4 ;
return F_3 ( V_6 , V_7 , 2 , NULL , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = V_3 & 0x7f ;
return F_3 ( V_6 , V_4 , 1 , V_4 , 1 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
int V_10 ;
unsigned char V_7 [ 8 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_7 [ 0 ] = 0x00 ;
V_10 = F_3 ( V_6 , V_7 , 1 , V_7 , 8 ) ;
if ( V_10 != 0 )
return V_10 ;
V_9 -> V_11 = F_6 ( V_7 [ 0 ] ) ;
V_9 -> V_12 = F_6 ( V_7 [ 1 ] ) ;
V_9 -> V_13 = F_6 ( V_7 [ 2 ] & 0x3f ) ;
V_9 -> V_14 = F_6 ( V_7 [ 3 ] ) - 1 ;
V_9 -> V_15 = F_6 ( V_7 [ 4 ] ) ;
V_9 -> V_16 = F_6 ( V_7 [ 5 ] & 0x1f ) - 1 ;
V_9 -> V_17 = F_6 ( V_7 [ 6 ] & 0xff ) + 100 ;
return F_7 ( V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_1 ( V_2 , V_18 , F_9 ( V_9 -> V_11 ) ) ;
F_1 ( V_2 , V_19 , F_9 ( V_9 -> V_12 ) ) ;
F_1 ( V_2 , V_20 , F_9 ( V_9 -> V_13 ) & 0x3f ) ;
F_1 ( V_2 , V_21 , F_9 ( V_9 -> V_14 + 1 ) ) ;
F_1 ( V_2 , V_22 , F_9 ( V_9 -> V_15 ) ) ;
F_1 ( V_2 , V_23 , F_9 ( V_9 -> V_16 + 1 ) ) ;
if ( V_9 -> V_17 > 100 )
V_9 -> V_17 -= 100 ;
F_1 ( V_2 , V_24 , F_9 ( V_9 -> V_17 ) ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_25 * V_26 ;
unsigned char V_27 ;
int V_28 ;
V_6 -> V_29 = V_30 ;
V_6 -> V_31 = 8 ;
F_11 ( V_6 ) ;
V_28 = F_4 ( & V_6 -> V_2 , V_18 , & V_27 ) ;
if ( V_28 != 0 )
return V_28 ;
F_4 ( & V_6 -> V_2 , V_32 , & V_27 ) ;
F_1 ( & V_6 -> V_2 , V_32 , V_27 & 0x1c ) ;
F_4 ( & V_6 -> V_2 , V_33 , & V_27 ) ;
F_1 ( & V_6 -> V_2 , V_33 , V_27 & 0x88 ) ;
F_4 ( & V_6 -> V_2 , V_32 , & V_27 ) ;
F_12 ( & V_6 -> V_2 , L_1 , V_27 ) ;
F_4 ( & V_6 -> V_2 , V_33 , & V_27 ) ;
F_12 ( & V_6 -> V_2 , L_2 , V_27 ) ;
V_26 = F_13 ( L_3 ,
& V_6 -> V_2 , & V_34 , V_35 ) ;
if ( F_14 ( V_26 ) )
return F_15 ( V_26 ) ;
F_16 ( & V_6 -> V_2 , V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_18 ( V_6 ) ;
F_19 ( V_26 ) ;
return 0 ;
}
