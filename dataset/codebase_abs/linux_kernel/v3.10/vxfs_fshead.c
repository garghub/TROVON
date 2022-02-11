static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_2 ( L_2 ) ;
F_2 ( L_3 , V_2 -> V_3 ) ;
F_2 ( L_4 , V_2 -> V_4 ) ;
F_2 ( L_5 ,
V_2 -> V_5 , V_2 -> V_6 ) ;
F_2 ( L_6 ,
V_2 -> V_7 , V_2 -> V_8 ) ;
F_2 ( L_7 , V_2 -> V_9 ) ;
F_2 ( L_8 ,
V_2 -> V_10 [ 0 ] , V_2 -> V_10 [ 1 ] ) ;
}
static struct V_1 *
F_3 ( struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 ;
V_15 = F_4 ( V_12 , V_13 ) ;
if ( V_15 ) {
struct V_1 * V_2 ;
if ( ! ( V_2 = F_5 ( sizeof( * V_2 ) , V_16 ) ) )
goto V_17;
memcpy ( V_2 , V_15 -> V_18 , sizeof( * V_2 ) ) ;
F_6 ( V_15 ) ;
return ( V_2 ) ;
}
V_17:
F_7 ( V_15 ) ;
return NULL ;
}
int
F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_9 ( V_20 ) ;
struct V_1 * V_23 , * V_24 ;
struct V_25 * V_26 , * V_27 ;
V_26 = F_10 ( V_20 , V_22 -> V_28 , V_22 -> V_29 ) ;
if ( ! V_26 ) {
F_2 ( V_30 L_9 ) ;
return - V_31 ;
}
if ( ! F_11 ( V_26 ) ) {
F_2 ( V_30 L_10 ,
V_26 -> V_32 & V_33 ) ;
goto V_34;
}
#ifdef F_12
F_2 ( L_11 ) ;
F_13 ( V_26 , V_22 -> V_29 ) ;
#endif
V_22 -> V_35 = F_14 ( V_20 , V_26 ) ;
if ( ! V_22 -> V_35 ) {
F_2 ( V_30 L_12 ) ;
goto V_34;
}
V_24 = F_3 ( V_22 -> V_35 , 0 ) ;
if ( ! V_24 ) {
F_2 ( V_30 L_13 ) ;
goto V_36;
}
#ifdef F_12
F_1 ( V_24 ) ;
#endif
V_23 = F_3 ( V_22 -> V_35 , 1 ) ;
if ( ! V_23 ) {
F_2 ( V_30 L_14 ) ;
goto V_37;
}
#ifdef F_12
F_1 ( V_23 ) ;
#endif
V_27 = F_10 ( V_20 , V_22 -> V_28 , V_24 -> V_10 [ 0 ] ) ;
if ( ! V_27 )
goto V_38;
V_22 -> V_39 = F_14 ( V_20 , V_27 ) ;
if ( ! V_22 -> V_39 ) {
F_2 ( V_30 L_15 ) ;
F_15 ( V_27 ) ;
goto V_38;
}
if ( ! F_16 ( F_17 ( V_22 -> V_39 ) ) ) {
F_2 ( V_30 L_16 ,
F_17 ( V_22 -> V_39 ) -> V_32 & V_33 ) ;
goto V_40;
}
V_27 = F_18 ( V_20 , V_23 -> V_10 [ 0 ] ) ;
if ( ! V_27 )
goto V_40;
V_22 -> V_41 = F_14 ( V_20 , V_27 ) ;
if ( ! V_22 -> V_41 ) {
F_2 ( V_30 L_17 ) ;
F_15 ( V_27 ) ;
goto V_40;
}
if ( ! F_16 ( F_17 ( V_22 -> V_41 ) ) ) {
F_2 ( V_30 L_18 ,
F_17 ( V_22 -> V_41 ) -> V_32 & V_33 ) ;
goto V_42;
}
return 0 ;
V_42:
F_19 ( V_22 -> V_41 ) ;
V_40:
F_19 ( V_22 -> V_39 ) ;
V_38:
F_15 ( V_23 ) ;
V_37:
F_15 ( V_24 ) ;
V_36:
F_19 ( V_22 -> V_35 ) ;
return - V_31 ;
V_34:
F_15 ( V_26 ) ;
return - V_31 ;
}
