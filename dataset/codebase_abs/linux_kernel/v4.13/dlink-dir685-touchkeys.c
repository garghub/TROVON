static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
const int V_5 = F_2 ( int , F_3 ( V_4 -> V_6 ) , 16 ) ;
unsigned long V_7 ;
T_2 V_8 [ 6 ] ;
unsigned long V_9 ;
int V_10 ;
int V_11 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_11 = F_4 ( V_4 -> V_12 , V_8 , sizeof( V_8 ) ) ;
if ( V_11 != sizeof( V_8 ) ) {
F_5 ( V_4 -> V_13 , L_1 , V_11 ) ;
return V_14 ;
}
F_6 ( V_4 -> V_13 , L_2 , ( int ) sizeof( V_8 ) , V_8 ) ;
V_9 = F_7 ( ( V_15 * ) & V_8 [ 4 ] ) ;
V_7 = V_4 -> V_16 ^ V_9 ;
F_8 (i, &changed, num_bits) {
F_6 ( V_4 -> V_13 , L_3 , V_10 ,
F_9 ( V_10 , & V_9 ) ? L_4 : L_5 ) ;
F_10 ( V_4 -> V_17 , V_4 -> V_6 [ V_10 ] , F_9 ( V_10 , & V_9 ) ) ;
}
V_4 -> V_16 = V_9 ;
F_11 ( V_4 -> V_17 ) ;
return V_14 ;
}
static int F_12 ( struct V_18 * V_12 ,
const struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_21 * V_13 = & V_12 -> V_13 ;
T_2 V_22 [] = { 0xa7 , 0x40 } ;
int V_11 ;
int V_10 ;
V_4 = F_13 ( & V_12 -> V_13 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_17 = F_14 ( V_13 ) ;
if ( ! V_4 -> V_17 )
return - V_24 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_17 -> V_25 = sizeof( V_26 ) ;
V_4 -> V_17 -> V_27 = F_3 ( V_4 -> V_6 ) ;
V_4 -> V_17 -> V_28 = V_4 -> V_6 ;
V_4 -> V_6 [ 0 ] = V_29 ;
V_4 -> V_6 [ 1 ] = V_30 ;
V_4 -> V_6 [ 2 ] = V_31 ;
V_4 -> V_6 [ 3 ] = V_32 ;
V_4 -> V_6 [ 4 ] = V_33 ;
V_4 -> V_6 [ 5 ] = V_34 ;
V_4 -> V_6 [ 6 ] = V_35 ;
F_15 ( V_36 , V_4 -> V_17 -> V_37 ) ;
for ( V_10 = 0 ; V_10 < F_3 ( V_4 -> V_6 ) ; V_10 ++ )
F_15 ( V_4 -> V_6 [ V_10 ] , V_4 -> V_17 -> V_38 ) ;
F_16 ( V_35 , V_4 -> V_17 -> V_38 ) ;
V_4 -> V_17 -> V_39 = L_6 ;
V_4 -> V_17 -> V_20 . V_40 = V_41 ;
V_11 = F_17 ( V_4 -> V_17 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_18 ( V_12 , V_22 , sizeof( V_22 ) ) ;
if ( V_11 != sizeof( V_22 ) )
F_19 ( V_4 -> V_13 , L_7 ) ;
if ( ! V_12 -> V_1 ) {
F_5 ( V_13 , L_8 ) ;
return - V_42 ;
}
V_11 = F_20 ( V_13 , V_12 -> V_1 ,
NULL , F_1 ,
V_43 ,
L_9 , V_4 ) ;
if ( V_11 ) {
F_5 ( V_13 , L_10 ) ;
return V_11 ;
}
return 0 ;
}
