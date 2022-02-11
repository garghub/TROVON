int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const enum V_5 type , const T_1 V_6 )
{
int V_7 ;
T_2 V_8 ;
T_1 V_9 ;
T_1 V_10 ;
void * V_11 ;
struct V_12 * V_13 = & V_2 -> V_12 ;
F_2 ( & V_4 -> V_14 ) ;
F_2 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = 0 ;
if ( type != V_17 && type != V_18 ) {
F_3 ( V_13 , L_1 , type , V_4 ) ;
return - V_19 ;
}
if ( ! V_6 ) {
F_3 ( V_13 , L_2 , V_4 ) ;
return - V_19 ;
}
V_8 = F_4 ( V_2 -> V_20 ,
& V_4 -> V_21 ,
type ,
V_6 ,
& V_4 -> V_22 ,
& V_4 -> V_6 ,
& V_9 , & V_4 -> V_23 ) ;
if ( V_8 != V_24 ) {
F_3 ( V_13 , L_3 , V_4 ) ;
return - V_19 ;
}
V_7 = F_5 ( NULL , & V_4 -> V_25 , V_9 ,
V_26 , sizeof( struct V_27 ) , 0 , 0 ) ;
if ( ! V_7 ) {
F_3 ( V_13 , L_4 , V_4 ) ;
goto V_28;
}
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
T_2 V_29 ;
V_11 = F_6 ( & V_4 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_7 ( V_11 ) ;
V_8 = F_8 ( V_2 -> V_20 ,
V_4 -> V_22 ,
& V_4 -> V_21 ,
0 , 0 , V_29 , 1 ) ;
if ( V_10 == ( V_9 - 1 ) ) {
V_11 = F_6 ( & V_4 -> V_25 ) ;
if ( V_8 != V_24 || V_11 )
goto V_30;
} else {
if ( V_8 != V_31 )
goto V_30;
}
}
F_9 ( & V_4 -> V_25 ) ;
if ( type == V_17 ) {
F_10 ( & V_4 -> V_32 , V_33 , ( long ) V_2 ) ;
V_7 = F_11 ( V_4 -> V_23 , V_34 ,
V_35 , L_5 ,
( void * ) V_2 ) ;
if ( V_7 < 0 )
F_3 ( V_13 , L_6 ) ;
} else if ( type == V_18 ) {
F_10 ( & V_4 -> V_32 , V_36 , ( long ) V_2 ) ;
V_7 = F_11 ( V_4 -> V_23 , V_37 ,
V_35 , L_7 ,
( void * ) V_2 ) ;
if ( V_7 < 0 )
F_3 ( V_13 , L_6 ) ;
}
V_4 -> V_16 = 1 ;
return 0 ;
V_30:
F_12 ( NULL , & V_4 -> V_25 ) ;
V_28:
F_13 ( V_2 -> V_20 , V_4 ) ;
return - V_19 ;
}
void * F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_38 ;
void * V_39 ;
F_15 ( & V_4 -> V_14 , V_38 ) ;
V_39 = F_16 ( & V_4 -> V_25 ) ;
F_17 ( & V_4 -> V_14 , V_38 ) ;
return V_39 ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_38 ;
T_2 V_8 ;
F_19 ( V_4 -> V_23 , ( void * ) V_2 ) ;
F_15 ( & V_40 , V_38 ) ;
V_4 -> V_16 = 0 ;
F_17 ( & V_40 , V_38 ) ;
F_20 ( & V_4 -> V_32 ) ;
V_8 = F_13 ( V_2 -> V_20 , V_4 ) ;
if ( V_8 != V_24 ) {
F_3 ( & V_2 -> V_12 , L_8 ) ;
return - V_19 ;
}
F_12 ( NULL , & V_4 -> V_25 ) ;
return 0 ;
}
