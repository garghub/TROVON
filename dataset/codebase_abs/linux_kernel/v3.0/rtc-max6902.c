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
F_1 ( V_2 , 0xF , 0 ) ;
F_1 ( V_2 , 0x01 , F_9 ( V_9 -> V_12 ) ) ;
F_1 ( V_2 , 0x03 , F_9 ( V_9 -> V_13 ) ) ;
F_1 ( V_2 , 0x05 , F_9 ( V_9 -> V_14 ) ) ;
F_1 ( V_2 , 0x07 , F_9 ( V_9 -> V_15 ) ) ;
F_1 ( V_2 , 0x09 , F_9 ( V_9 -> V_16 + 1 ) ) ;
F_1 ( V_2 , 0x0B , F_9 ( V_9 -> V_17 ) ) ;
F_1 ( V_2 , 0x0D , F_9 ( V_9 -> V_18 % 100 ) ) ;
F_1 ( V_2 , 0x13 , F_9 ( V_9 -> V_18 / 100 ) ) ;
F_1 ( V_2 , 0xF , 0x80 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_5 * V_6 )
{
struct V_20 * V_21 ;
unsigned char V_22 ;
int V_23 ;
V_6 -> V_24 = V_25 ;
V_6 -> V_26 = 8 ;
F_11 ( V_6 ) ;
V_23 = F_4 ( & V_6 -> V_2 , V_27 , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
V_21 = F_12 ( L_1 ,
& V_6 -> V_2 , & V_28 , V_29 ) ;
if ( F_13 ( V_21 ) )
return F_14 ( V_21 ) ;
F_15 ( & V_6 -> V_2 , V_21 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = F_17 ( & V_6 -> V_2 ) ;
F_18 ( V_21 ) ;
return 0 ;
}
static T_3 int F_19 ( void )
{
return F_20 ( & V_30 ) ;
}
static T_4 void F_21 ( void )
{
F_22 ( & V_30 ) ;
}
