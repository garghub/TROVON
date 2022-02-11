static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = V_4 -> V_7 ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_9 = V_4 -> V_9 ;
V_2 -> V_10 = V_4 -> V_10 ;
V_2 -> V_11 = V_4 -> V_11 ;
V_2 -> V_12 = V_4 -> V_12 ;
memcpy ( & V_2 -> V_13 , & V_4 -> V_13 , sizeof( V_4 -> V_13 ) ) ;
memcpy ( & V_2 -> V_14 , & V_4 -> V_14 , sizeof( V_4 -> V_14 ) ) ;
memcpy ( & V_2 -> V_15 , & V_4 -> V_15 , sizeof( V_4 -> V_15 ) ) ;
}
struct V_1 * F_2 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 , * V_21 = NULL ;
struct V_3 * V_22 , * V_23 ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 ;
T_1 V_26 ;
V_20 = F_3 ( V_17 , 0 ) ;
if ( ! V_20 ) {
F_4 ( V_27 L_1 ) ;
return NULL ;
}
V_22 = (struct V_3 * ) V_20 -> V_28 ;
V_25 = F_5 ( V_17 ) ;
if ( F_6 ( V_25 , V_22 -> V_5 ) != V_29 ) {
if ( ! V_18 ) {
F_4 ( V_27 L_2
L_3 ) ;
goto V_30;
}
}
if ( F_6 ( V_25 , V_22 -> V_6 ) !=
F_7 ( 0 , ( char * ) ( V_20 -> V_28 + 8 ) , 504 ) ) {
F_4 ( V_27 L_4 ) ;
goto V_30;
}
V_26 = F_6 ( V_25 , V_22 -> V_11 ) + V_31 /
F_6 ( V_25 , V_22 -> V_8 ) ;
if ( ! F_8 ( V_17 , F_6 ( V_25 , V_22 -> V_8 ) ) ) {
F_4 ( V_27 L_5 ) ;
goto V_30;
}
F_9 ( V_20 ) ;
V_20 = F_3 ( V_17 , 0 ) ;
if ( ! V_20 )
goto V_30;
V_22 = (struct V_3 * ) V_20 -> V_28 ;
V_21 = F_3 ( V_17 , V_26 ) ;
if ( ! V_21 ) {
F_4 ( V_27 L_6 ) ;
goto V_30;
}
V_23 = (struct V_3 * ) V_21 -> V_28 ;
if ( F_6 ( V_25 , V_23 -> V_5 ) != V_29 ) {
if ( ! V_18 )
F_4 ( V_27 L_2
L_7 ) ;
goto V_30;
}
if ( F_6 ( V_25 , V_23 -> V_6 )
!= F_7 ( 0 , ( char * ) ( V_21 -> V_28 + 8 ) , 504 ) ) {
F_4 ( V_27 L_4 ) ;
goto V_30;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_4 ( V_27 L_8 ) ;
goto V_30;
}
if ( F_11 ( V_25 , V_22 -> V_7 ) >
F_11 ( V_25 , V_23 -> V_7 ) ) {
F_1 ( V_2 , V_22 ) ;
#ifdef F_12
F_13 ( V_2 , V_17 ) ;
#endif
memcpy ( V_20 -> V_28 , V_2 , sizeof( struct V_1 ) ) ;
V_25 -> V_33 = V_20 ;
V_25 -> V_4 = (struct V_1 * ) V_20 -> V_28 ;
F_9 ( V_21 ) ;
F_4 ( V_34 L_9 ) ;
} else {
F_1 ( V_2 , V_23 ) ;
#ifdef F_12
F_13 ( V_2 , V_17 ) ;
#endif
memcpy ( V_21 -> V_28 , V_2 , sizeof( struct V_1 ) ) ;
V_25 -> V_33 = V_21 ;
V_25 -> V_4 = (struct V_1 * ) V_21 -> V_28 ;
F_9 ( V_20 ) ;
F_4 ( V_34 L_10 ) ;
}
F_14 ( V_2 ) ;
V_25 -> V_35 = V_31 / V_17 -> V_36 ;
return V_25 -> V_4 ;
V_30:
if ( V_20 != NULL )
F_9 ( V_20 ) ;
if ( V_21 != NULL )
F_9 ( V_21 ) ;
return NULL ;
}
