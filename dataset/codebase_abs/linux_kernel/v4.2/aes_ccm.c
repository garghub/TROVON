void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 ,
T_2 V_8 )
{
struct V_9 V_10 [ 3 ] ;
char V_11 [ sizeof( struct V_12 ) +
F_2 ( V_2 ) ]
V_13 ( F_3 ( struct V_12 ) ) ;
struct V_12 * V_14 = ( void * ) V_11 ;
memset ( V_14 , 0 , sizeof( V_11 ) ) ;
F_4 ( V_10 , 3 ) ;
F_5 ( & V_10 [ 0 ] , & V_4 [ 2 ] , F_6 ( ( V_15 * ) V_4 ) ) ;
F_5 ( & V_10 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_10 [ 2 ] , V_7 , V_8 ) ;
F_7 ( V_14 , V_2 ) ;
F_8 ( V_14 , V_10 , V_10 , V_6 , V_3 ) ;
F_9 ( V_14 , V_10 [ 0 ] . V_16 ) ;
F_10 ( V_14 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 ,
T_2 V_8 )
{
struct V_9 V_10 [ 3 ] ;
char V_11 [ sizeof( struct V_12 ) +
F_2 ( V_2 ) ]
V_13 ( F_3 ( struct V_12 ) ) ;
struct V_12 * V_14 = ( void * ) V_11 ;
if ( V_6 == 0 )
return - V_17 ;
memset ( V_14 , 0 , sizeof( V_11 ) ) ;
F_4 ( V_10 , 3 ) ;
F_5 ( & V_10 [ 0 ] , & V_4 [ 2 ] , F_6 ( ( V_15 * ) V_4 ) ) ;
F_5 ( & V_10 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_10 [ 2 ] , V_7 , V_8 ) ;
F_7 ( V_14 , V_2 ) ;
F_8 ( V_14 , V_10 , V_10 , V_6 + V_8 , V_3 ) ;
F_9 ( V_14 , V_10 [ 0 ] . V_16 ) ;
return F_12 ( V_14 ) ;
}
struct V_1 * F_13 ( const T_1 V_18 [] ,
T_2 V_19 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_14 ( L_1 , 0 , V_21 ) ;
if ( F_15 ( V_2 ) )
return V_2 ;
V_20 = F_16 ( V_2 , V_18 , V_19 ) ;
if ( V_20 )
goto V_22;
V_20 = F_17 ( V_2 , V_8 ) ;
if ( V_20 )
goto V_22;
return V_2 ;
V_22:
F_18 ( V_2 ) ;
return F_19 ( V_20 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
}
