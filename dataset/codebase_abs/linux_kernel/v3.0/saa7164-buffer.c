void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 ;
F_2 ( V_7 , L_1 ,
V_8 , V_2 , V_2 -> V_9 ) ;
F_2 ( V_7 , L_2 ,
V_2 -> V_10 , ( long long ) V_2 -> V_11 , V_2 -> V_12 ) ;
F_2 ( V_7 , L_3 ,
V_2 -> V_13 , ( long long ) V_2 -> V_14 , V_2 -> V_15 ) ;
for ( V_6 = 0 ; V_6 < V_16 ; V_6 ++ ) {
F_2 ( V_7 , L_4 ,
V_6 , V_2 -> V_13 , ( V_17 ) * ( V_2 -> V_13 ) ) ;
}
}
struct V_1 * F_3 ( struct V_18 * V_5 ,
T_1 V_19 )
{
struct V_20 * V_21 = & V_5 -> V_22 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_6 ;
if ( ( V_19 == 0 ) || ( V_19 >= 65536 ) || ( V_19 % sizeof( V_17 ) ) ) {
F_4 ( L_5 , V_8 ) ;
goto V_23;
}
V_2 = F_5 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_2 ) {
F_4 ( L_6 , V_8 ) ;
goto V_23;
}
V_2 -> V_9 = - 1 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = V_21 -> V_29 * V_21 -> V_30 ;
V_2 -> V_31 = 0 ;
V_2 -> V_12 = V_16 * 0x1000 ;
V_2 -> V_15 = ( V_16 * sizeof( V_17 ) ) + 0x1000 ;
V_2 -> V_10 = F_6 ( V_5 -> V_4 -> V_32 , V_2 -> V_12 ,
& V_2 -> V_11 ) ;
if ( ! V_2 -> V_10 )
goto V_33;
V_2 -> V_13 = F_6 ( V_5 -> V_4 -> V_32 , V_2 -> V_15 ,
& V_2 -> V_14 ) ;
if ( ! V_2 -> V_13 )
goto V_34;
F_7 ( V_2 -> V_10 , 0xff , V_2 -> V_12 ) ;
V_2 -> V_31 = F_8 ( 0 , V_2 -> V_10 , V_2 -> V_28 ) ;
F_7 ( V_2 -> V_13 , 0xff , V_2 -> V_15 ) ;
F_2 ( V_7 , L_7 ,
V_8 , V_2 , V_21 -> V_35 ) ;
F_2 ( V_7 , L_8 ,
V_2 -> V_10 , ( long ) V_2 -> V_11 , V_2 -> V_12 ) ;
F_2 ( V_7 , L_9 ,
V_2 -> V_13 , ( long ) V_2 -> V_14 , V_2 -> V_15 ) ;
for ( V_6 = 0 ; V_6 < V_21 -> V_35 ; V_6 ++ ) {
* ( V_2 -> V_13 + V_6 ) = V_2 -> V_11 + ( V_6 * 0x1000 ) ;
F_2 ( V_7 , L_4 ,
V_6 , V_2 -> V_13 , ( V_17 ) * ( V_2 -> V_13 ) ) ;
}
goto V_23;
V_34:
F_9 ( V_5 -> V_4 -> V_32 , V_2 -> V_12 , V_2 -> V_10 , V_2 -> V_11 ) ;
V_33:
F_10 ( V_2 ) ;
V_2 = NULL ;
V_23:
return V_2 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return V_36 ;
V_4 = V_2 -> V_5 -> V_4 ;
F_2 ( V_7 , L_10 ,
V_8 , V_2 ) ;
if ( V_2 -> V_25 != V_26 )
F_4 ( L_11 ) ;
F_9 ( V_4 -> V_32 , V_2 -> V_12 , V_2 -> V_10 , V_2 -> V_11 ) ;
F_9 ( V_4 -> V_32 , V_2 -> V_15 , V_2 -> V_13 , V_2 -> V_14 ) ;
F_10 ( V_2 ) ;
return V_37 ;
}
int F_12 ( struct V_18 * V_5 , int V_6 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
if ( ( V_6 < 0 ) || ( V_6 >= V_5 -> V_38 . V_39 ) )
return - V_40 ;
F_2 ( V_7 , L_12 , V_8 , V_6 ) ;
F_13 ( V_5 -> V_41 + ( sizeof( T_1 ) * V_6 ) , 0 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_6 )
{
struct V_18 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_5 -> V_4 ;
if ( ( V_6 < 0 ) || ( V_6 >= V_5 -> V_38 . V_39 ) )
return - V_40 ;
F_2 ( V_7 , L_12 , V_8 , V_6 ) ;
V_2 -> V_9 = V_6 ;
V_2 -> V_25 = V_42 ;
V_2 -> V_27 = 0 ;
F_13 ( V_5 -> V_41 + ( sizeof( T_1 ) * V_6 ) , 0 ) ;
F_13 ( V_5 -> V_43 + ( ( sizeof( T_1 ) * 2 ) * V_6 ) , V_2 -> V_14 ) ;
F_13 ( V_5 -> V_44 + ( ( sizeof( T_1 ) * 2 ) * V_6 ) , 0 ) ;
F_2 ( V_7 , L_13
L_14 ,
V_2 -> V_9 ,
( V_17 ) V_5 -> V_41 + ( V_6 * sizeof( T_1 ) ) ,
F_15 ( V_5 -> V_41 + ( sizeof( T_1 ) * V_6 ) ) ,
( V_17 ) V_5 -> V_43 + ( ( sizeof( T_1 ) * 2 ) * V_6 ) ,
( V_17 ) V_5 -> V_44 + ( ( sizeof( T_1 ) * 2 ) * V_6 ) ,
F_15 ( V_5 -> V_43 + ( ( sizeof( T_1 ) * V_6 ) * 2 ) ) ,
F_15 ( V_5 -> V_44 + ( ( sizeof( T_1 ) * V_6 ) * 2 ) ) ,
V_2 -> V_9 ) ;
return 0 ;
}
int F_16 ( struct V_18 * V_5 )
{
struct V_20 * V_21 = & V_5 -> V_22 ;
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_1 * V_2 ;
struct V_45 * V_46 , * V_47 ;
int V_6 = 0 ;
F_2 ( V_7 , L_15 , V_8 , V_5 -> V_48 ) ;
F_13 ( V_5 -> V_49 , 0 ) ;
F_13 ( V_5 -> V_29 , V_21 -> V_29 ) ;
F_13 ( V_5 -> V_50 , V_21 -> V_29 * V_21 -> V_30 ) ;
F_2 ( V_7 , L_16 ) ;
F_2 ( V_7 , L_17 , V_4 -> V_51 ) ;
F_2 ( V_7 , L_18 , V_5 -> V_49 ,
F_15 ( V_5 -> V_49 ) ) ;
F_2 ( V_7 , L_19 , V_5 -> V_29 ,
F_15 ( V_5 -> V_29 ) ) ;
F_2 ( V_7 , L_20 , V_5 -> V_50 ,
F_15 ( V_5 -> V_50 ) ) ;
F_2 ( V_7 , L_21 , V_5 -> V_38 . V_39 ) ;
F_2 ( V_7 , L_22 , V_5 -> V_41 ) ;
F_2 ( V_7 , L_23 , V_5 -> V_43 ) ;
F_2 ( V_7 , L_24 , V_5 -> V_44 ) ;
F_17 ( & V_5 -> V_52 ) ;
F_18 (c, n, &port->dmaqueue.list) {
V_2 = F_19 ( V_46 , struct V_1 , V_53 ) ;
if ( V_2 -> V_25 != V_26 )
F_20 () ;
F_14 ( V_2 , V_6 ) ;
if ( V_6 ++ > V_5 -> V_38 . V_39 )
F_20 () ;
}
F_21 ( & V_5 -> V_52 ) ;
return 0 ;
}
struct V_54 * F_22 ( struct V_3 * V_4 ,
T_1 V_19 )
{
struct V_54 * V_2 ;
V_2 = F_5 ( sizeof( struct V_54 ) , V_24 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_55 = F_5 ( V_19 , V_24 ) ;
if ( ! V_2 -> V_55 ) {
F_10 ( V_2 ) ;
return NULL ;
}
V_2 -> V_28 = V_19 ;
V_2 -> V_27 = 0 ;
V_2 -> V_31 = 0 ;
F_2 ( V_7 , L_25 ,
V_8 , V_2 ) ;
return V_2 ;
}
void F_23 ( struct V_54 * V_2 )
{
if ( ! V_2 )
return;
F_10 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
F_10 ( V_2 ) ;
}
