static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_9 ;
if ( ! V_4 )
return - V_10 ;
V_8 -> V_11 [ 0 ] = V_3 & 0x7f ;
V_9 = F_4 ( V_6 , V_8 -> V_11 , 1 , V_8 -> V_11 , 1 ) ;
if ( V_9 != 0 )
return V_9 ;
* V_4 = V_8 -> V_11 [ 1 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_9 ;
V_8 -> V_11 [ 0 ] = V_14 ;
V_9 = F_4 ( V_6 , V_8 -> V_11 , 1 , V_8 -> V_11 , 8 ) ;
if ( V_9 != 0 )
return V_9 ;
V_13 -> V_15 = F_6 ( V_8 -> V_11 [ 0 ] ) ;
V_13 -> V_16 = F_6 ( V_8 -> V_11 [ 1 ] ) ;
V_13 -> V_17 = F_6 ( V_8 -> V_11 [ 2 ] ) ;
V_13 -> V_18 = F_6 ( V_8 -> V_11 [ 3 ] ) ;
V_13 -> V_19 = F_6 ( V_8 -> V_11 [ 4 ] ) ;
V_13 -> V_20 = F_6 ( V_8 -> V_11 [ 5 ] & 0x7f ) - 1 ;
V_13 -> V_21 = F_6 ( V_8 -> V_11 [ 6 ] ) + ( ( V_8 -> V_11 [ 5 ] & 0x80 ) ? 100 : 0 ) ;
return F_7 ( V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_11 [ 0 ] = V_14 | 0x80 ;
V_8 -> V_11 [ 1 ] = F_9 ( V_13 -> V_15 ) ;
V_8 -> V_11 [ 2 ] = F_9 ( V_13 -> V_16 ) ;
V_8 -> V_11 [ 3 ] = F_9 ( V_13 -> V_17 ) ;
V_8 -> V_11 [ 4 ] = F_9 ( V_13 -> V_18 ) ;
V_8 -> V_11 [ 5 ] = F_9 ( V_13 -> V_19 ) ;
V_8 -> V_11 [ 6 ] = F_9 ( V_13 -> V_20 + 1 ) |
( ( V_13 -> V_21 > 99 ) ? 0x80 : 0x00 ) ;
V_8 -> V_11 [ 7 ] = F_9 ( V_13 -> V_21 % 100 ) ;
return F_4 ( V_6 , V_8 -> V_11 , 8 , NULL , 0 ) ;
}
static int T_1 F_10 ( struct V_5 * V_6 )
{
unsigned char V_22 ;
struct V_7 * V_8 ;
int V_23 ;
V_6 -> V_24 = V_25 ;
V_6 -> V_26 = 8 ;
F_11 ( V_6 ) ;
V_8 = F_12 ( sizeof *V_8 , V_27 ) ;
if ( ! V_8 ) {
F_13 ( & V_6 -> V_2 , L_1 ) ;
return - V_28 ;
}
F_14 ( & V_6 -> V_2 , V_8 ) ;
V_23 = F_1 ( & V_6 -> V_2 , V_14 , & V_22 ) ;
if ( V_23 != 0 ) {
F_13 ( & V_6 -> V_2 , L_2 ) ;
F_15 ( V_8 ) ;
return V_23 ;
}
V_8 -> V_29 = F_16 ( L_3 ,
& V_6 -> V_2 , & V_30 , V_31 ) ;
if ( F_17 ( V_8 -> V_29 ) ) {
F_13 ( & V_6 -> V_2 , L_4 ) ;
V_23 = F_18 ( V_8 -> V_29 ) ;
F_15 ( V_8 ) ;
}
return V_23 ;
}
static int T_2 F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_20 ( V_6 ) ;
F_21 ( V_8 -> V_29 ) ;
F_15 ( V_8 ) ;
return 0 ;
}
