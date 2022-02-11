void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 ,
T_2 V_8 )
{
struct V_9 V_10 , V_11 , V_12 [ 2 ] ;
char V_13 [ sizeof( struct V_14 ) +
F_2 ( V_2 ) ]
V_15 ( F_3 ( struct V_14 ) ) ;
struct V_14 * V_16 = ( void * ) V_13 ;
memset ( V_16 , 0 , sizeof( V_13 ) ) ;
F_4 ( & V_11 , V_5 , V_6 ) ;
F_4 ( & V_10 , & V_4 [ 2 ] , F_5 ( ( V_17 * ) V_4 ) ) ;
F_6 ( V_12 , 2 ) ;
F_7 ( & V_12 [ 0 ] , V_5 , V_6 ) ;
F_7 ( & V_12 [ 1 ] , V_7 , V_8 ) ;
F_8 ( V_16 , V_2 ) ;
F_9 ( V_16 , & V_10 , V_10 . V_18 ) ;
F_10 ( V_16 , & V_11 , V_12 , V_6 , V_3 ) ;
F_11 ( V_16 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 ,
T_2 V_8 )
{
struct V_9 V_10 , V_11 , V_12 [ 2 ] ;
char V_13 [ sizeof( struct V_14 ) +
F_2 ( V_2 ) ]
V_15 ( F_3 ( struct V_14 ) ) ;
struct V_14 * V_16 = ( void * ) V_13 ;
if ( V_6 == 0 )
return - V_19 ;
memset ( V_16 , 0 , sizeof( V_13 ) ) ;
F_4 ( & V_11 , V_5 , V_6 ) ;
F_4 ( & V_10 , & V_4 [ 2 ] , F_5 ( ( V_17 * ) V_4 ) ) ;
F_6 ( V_12 , 2 ) ;
F_7 ( & V_12 [ 0 ] , V_5 , V_6 ) ;
F_7 ( & V_12 [ 1 ] , V_7 , V_8 ) ;
F_8 ( V_16 , V_2 ) ;
F_9 ( V_16 , & V_10 , V_10 . V_18 ) ;
F_10 ( V_16 , V_12 , & V_11 , V_6 + V_8 , V_3 ) ;
return F_13 ( V_16 ) ;
}
struct V_1 * F_14 ( const T_1 V_20 [] ,
T_2 V_21 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_15 ( L_1 , 0 , V_23 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
V_22 = F_17 ( V_2 , V_20 , V_21 ) ;
if ( V_22 )
goto V_24;
V_22 = F_18 ( V_2 , V_8 ) ;
if ( V_22 )
goto V_24;
return V_2 ;
V_24:
F_19 ( V_2 ) ;
return F_20 ( V_22 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
