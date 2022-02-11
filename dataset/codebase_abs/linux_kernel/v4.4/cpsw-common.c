static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , T_2 * V_5 )
{
T_3 V_6 ;
T_3 V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 -> V_10 , L_1 ) ;
if ( F_3 ( V_9 ) ) {
if ( F_4 ( V_9 ) == - V_11 )
return 0 ;
return F_4 ( V_9 ) ;
}
F_5 ( V_9 , F_6 ( V_3 , V_4 ) , & V_6 ) ;
F_5 ( V_9 , F_7 ( V_3 , V_4 ) , & V_7 ) ;
V_5 [ 0 ] = ( V_7 >> 16 ) & 0xff ;
V_5 [ 1 ] = ( V_7 >> 8 ) & 0xff ;
V_5 [ 2 ] = V_7 & 0xff ;
V_5 [ 3 ] = ( V_6 >> 16 ) & 0xff ;
V_5 [ 4 ] = ( V_6 >> 8 ) & 0xff ;
V_5 [ 5 ] = V_6 & 0xff ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_2 * V_5 )
{
T_3 V_12 ;
T_3 V_13 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 -> V_10 , L_1 ) ;
if ( F_3 ( V_9 ) ) {
if ( F_4 ( V_9 ) == - V_11 )
return 0 ;
return F_4 ( V_9 ) ;
}
F_5 ( V_9 , F_6 ( V_3 , V_4 ) , & V_12 ) ;
F_5 ( V_9 , F_7 ( V_3 , V_4 ) , & V_13 ) ;
V_5 [ 5 ] = ( V_12 >> 8 ) & 0xff ;
V_5 [ 4 ] = V_12 & 0xff ;
V_5 [ 3 ] = ( V_13 >> 24 ) & 0xff ;
V_5 [ 2 ] = ( V_13 >> 16 ) & 0xff ;
V_5 [ 1 ] = ( V_13 >> 8 ) & 0xff ;
V_5 [ 0 ] = V_13 & 0xff ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_4 , T_2 * V_5 )
{
if ( F_10 ( L_2 ) )
return F_8 ( V_2 , 0x630 , V_4 , V_5 ) ;
if ( F_10 ( L_3 ) )
return F_8 ( V_2 , 0x630 , V_4 , V_5 ) ;
if ( F_11 ( V_2 -> V_10 , L_4 ) )
return F_1 ( V_2 , 0x110 , V_4 , V_5 ) ;
if ( F_11 ( V_2 -> V_10 , L_5 ) )
return F_8 ( V_2 , 0x30 , V_4 , V_5 ) ;
if ( F_10 ( L_6 ) )
return F_8 ( V_2 , 0x630 , V_4 , V_5 ) ;
if ( F_10 ( L_7 ) )
return F_1 ( V_2 , 0x514 , V_4 , V_5 ) ;
F_12 ( V_2 , L_8 ) ;
return - V_14 ;
}
