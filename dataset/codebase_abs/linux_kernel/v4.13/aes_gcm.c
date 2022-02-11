int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 3 ] ;
struct V_10 * V_11 ;
int V_12 = sizeof( * V_11 ) + F_2 ( V_2 ) ;
T_1 * V_13 ;
V_11 = F_3 ( V_12 + V_14 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_13 = ( T_1 * ) V_11 + V_12 ;
memcpy ( V_13 , V_4 , V_14 ) ;
F_4 ( V_9 , 3 ) ;
F_5 ( & V_9 [ 0 ] , & V_13 [ 2 ] , F_6 ( ( V_17 * ) V_13 ) ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_9 [ 2 ] , V_7 , V_18 ) ;
F_7 ( V_11 , V_2 ) ;
F_8 ( V_11 , V_9 , V_9 , V_6 , V_3 ) ;
F_9 ( V_11 , V_9 [ 0 ] . V_19 ) ;
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 3 ] ;
struct V_10 * V_11 ;
int V_12 = sizeof( * V_11 ) + F_2 ( V_2 ) ;
T_1 * V_13 ;
int V_20 ;
if ( V_6 == 0 )
return - V_21 ;
V_11 = F_3 ( V_12 + V_14 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_13 = ( T_1 * ) V_11 + V_12 ;
memcpy ( V_13 , V_4 , V_14 ) ;
F_4 ( V_9 , 3 ) ;
F_5 ( & V_9 [ 0 ] , & V_13 [ 2 ] , F_6 ( ( V_17 * ) V_13 ) ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 ) ;
F_5 ( & V_9 [ 2 ] , V_7 , V_18 ) ;
F_7 ( V_11 , V_2 ) ;
F_8 ( V_11 , V_9 , V_9 ,
V_6 + V_18 , V_3 ) ;
F_9 ( V_11 , V_9 [ 0 ] . V_19 ) ;
V_20 = F_13 ( V_11 ) ;
F_11 ( V_11 ) ;
return V_20 ;
}
struct V_1 * F_14 ( const T_1 V_22 [] ,
T_2 V_23 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_15 ( L_1 , 0 , V_24 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
V_20 = F_17 ( V_2 , V_22 , V_23 ) ;
if ( V_20 )
goto V_25;
V_20 = F_18 ( V_2 , V_18 ) ;
if ( V_20 )
goto V_25;
return V_2 ;
V_25:
F_19 ( V_2 ) ;
return F_20 ( V_20 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
