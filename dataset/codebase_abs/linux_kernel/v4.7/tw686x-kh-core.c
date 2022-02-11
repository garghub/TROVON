static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_2 V_5 = F_2 ( V_4 , V_6 ) ;
unsigned long V_7 ;
unsigned int V_8 = 0 ;
if ( V_5 ) {
F_3 ( & V_4 -> V_9 , V_7 ) ;
V_4 -> V_10 |= V_5 ;
F_4 ( & V_4 -> V_9 , V_7 ) ;
if ( V_5 & 0xFF0000FF )
V_8 = F_5 ( V_4 ) ;
}
return F_6 ( V_8 ) ;
}
static int F_7 ( struct V_11 * V_11 ,
const struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_14 ;
V_4 = F_8 ( & V_11 -> V_4 , sizeof( * V_4 ) +
( V_13 -> V_15 & V_16 ) *
sizeof( V_4 -> V_17 [ 0 ] ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
sprintf ( V_4 -> V_20 , L_1 , V_11 -> V_21 ) ;
V_4 -> type = V_13 -> V_15 ;
F_9 ( L_2 , V_4 -> V_20 ,
F_10 ( V_11 ) , V_11 -> V_1 ,
( unsigned long ) F_11 ( V_11 , 0 ) ) ;
V_4 -> V_11 = V_11 ;
if ( F_12 ( V_11 ) )
return - V_22 ;
F_13 ( V_11 ) ;
if ( F_14 ( V_11 , F_15 ( 32 ) ) ) {
F_16 ( L_3 , V_4 -> V_20 ) ;
return - V_22 ;
}
V_14 = F_17 ( V_11 , V_4 -> V_20 ) ;
if ( V_14 < 0 ) {
F_16 ( L_4 , V_4 -> V_20 ) ;
return V_14 ;
}
V_4 -> V_23 = F_18 ( V_11 , 0 ) ;
if ( ! V_4 -> V_23 ) {
F_16 ( L_5 , V_4 -> V_20 ) ;
return - V_22 ;
}
F_19 ( V_4 , V_24 , 0x0F ) ;
F_20 ( 1 ) ;
F_19 ( V_4 , V_25 [ 0 ] , 0x3F ) ;
if ( F_21 ( V_4 ) > 4 )
F_19 ( V_4 , V_25 [ 1 ] , 0x3F ) ;
F_19 ( V_4 , V_26 , 0 ) ;
F_19 ( V_4 , V_27 , 0 ) ;
F_19 ( V_4 , V_28 , 0x3EFF0FF0 ) ;
F_19 ( V_4 , V_29 , 0x38000 ) ;
F_19 ( V_4 , V_30 , 0xFFFFFF04 ) ;
F_22 ( & V_4 -> V_9 ) ;
V_14 = F_23 ( & V_11 -> V_4 , V_11 -> V_1 , F_1 ,
V_31 , V_4 -> V_20 , V_4 ) ;
if ( V_14 < 0 ) {
F_16 ( L_6 , V_4 -> V_20 ) ;
return V_14 ;
}
V_14 = F_24 ( V_4 ) ;
if ( V_14 )
return V_14 ;
F_25 ( V_11 , V_4 ) ;
return 0 ;
}
static void F_26 ( struct V_11 * V_11 )
{
struct V_3 * V_4 = F_27 ( V_11 ) ;
F_28 ( V_4 ) ;
}
