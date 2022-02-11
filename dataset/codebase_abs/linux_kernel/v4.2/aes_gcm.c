void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 3 ] ;
char V_10 [ sizeof( struct V_11 ) +
F_2 ( V_2 ) ]
V_12 ( F_3 ( struct V_11 ) ) ;
struct V_11 * V_13 = ( void * ) V_10 ;
memset ( V_13 , 0 , sizeof( V_10 ) ) ;
F_4 ( V_9 , 3 ) ;
F_5 ( & V_9 [ 0 ] , & V_4 [ 2 ] , F_6 ( ( V_14 * ) V_4 ) ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_9 [ 2 ] , V_7 , V_15 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , V_9 , V_9 , V_6 , V_3 ) ;
F_9 ( V_13 , V_9 [ 0 ] . V_16 ) ;
F_10 ( V_13 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 3 ] ;
char V_10 [ sizeof( struct V_11 ) +
F_2 ( V_2 ) ]
V_12 ( F_3 ( struct V_11 ) ) ;
struct V_11 * V_13 = ( void * ) V_10 ;
if ( V_6 == 0 )
return - V_17 ;
memset ( V_13 , 0 , sizeof( V_10 ) ) ;
F_4 ( V_9 , 3 ) ;
F_5 ( & V_9 [ 0 ] , & V_4 [ 2 ] , F_6 ( ( V_14 * ) V_4 ) ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_9 [ 2 ] , V_7 , V_15 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , V_9 , V_9 ,
V_6 + V_15 , V_3 ) ;
F_9 ( V_13 , V_9 [ 0 ] . V_16 ) ;
return F_12 ( V_13 ) ;
}
struct V_1 * F_13 ( const T_1 V_18 [] ,
T_2 V_19 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_14 ( L_1 , 0 , V_21 ) ;
if ( F_15 ( V_2 ) )
return V_2 ;
V_20 = F_16 ( V_2 , V_18 , V_19 ) ;
if ( V_20 )
goto V_22;
V_20 = F_17 ( V_2 , V_15 ) ;
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
