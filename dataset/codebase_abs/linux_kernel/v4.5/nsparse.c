T_1
F_1 ( T_2 V_1 ,
T_2 V_2 ,
struct V_3 * V_4 )
{
union V_5 * V_6 ;
T_1 V_7 ;
T_2 V_8 ;
T_3 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_4 V_14 ;
F_2 ( V_15 ) ;
V_7 = F_3 ( V_2 , & V_13 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_7 ) ;
}
if ( V_13 -> V_16 < sizeof( struct V_12 ) ) {
F_5 ( V_17 ) ;
}
V_9 = ( T_3 * ) V_13 + sizeof( struct V_12 ) ;
V_8 = V_13 -> V_16 - sizeof( struct V_12 ) ;
V_7 = F_6 ( V_2 , & V_14 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_7 ) ;
}
V_6 = F_7 ( V_9 ) ;
if ( ! V_6 ) {
F_5 ( V_18 ) ;
}
V_11 = F_8 ( V_14 , NULL , NULL , NULL ) ;
if ( ! V_11 ) {
F_9 ( V_6 ) ;
F_5 ( V_18 ) ;
}
V_7 = F_10 ( V_11 , V_6 , NULL ,
V_9 , V_8 , NULL ,
( T_3 ) V_1 ) ;
if ( F_4 ( V_7 ) ) {
F_11 ( V_11 ) ;
goto V_19;
}
if ( F_12 ( V_13 -> V_20 , V_21 ) &&
V_1 == V_22 ) {
V_11 -> V_23 = TRUE ;
}
if ( V_4 && V_4 != V_24 ) {
V_7 =
F_13 ( V_4 , V_25 ,
V_11 ) ;
if ( F_4 ( V_7 ) ) {
F_11 ( V_11 ) ;
goto V_19;
}
}
F_14 ( ( V_26 ,
L_1 , V_1 ) ) ;
V_7 = F_15 ( V_11 ) ;
V_19:
F_16 ( V_6 ) ;
F_5 ( V_7 ) ;
}
T_1
F_17 ( T_2 V_2 , struct V_3 * V_4 )
{
T_1 V_7 ;
F_2 ( V_27 ) ;
F_14 ( ( V_26 , L_2 ) ) ;
V_7 = F_1 ( V_22 ,
V_2 , V_4 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_7 ) ;
}
F_14 ( ( V_26 , L_3 ) ) ;
V_7 = F_1 ( V_28 ,
V_2 , V_4 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( V_7 ) ;
}
F_5 ( V_7 ) ;
}
