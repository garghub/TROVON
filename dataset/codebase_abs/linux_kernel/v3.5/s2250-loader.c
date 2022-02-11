static void F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = F_2 ( V_1 ) ;
V_3 [ V_2 -> V_4 ] = NULL ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_4 , V_11 ;
T_1 V_2 = NULL ;
const struct V_12 * V_13 ;
V_10 = F_5 ( F_6 ( V_6 ) ) ;
if ( ! V_10 ) {
F_7 ( V_14 L_1 ) ;
return - 1 ;
}
F_7 ( V_15 L_2 ) ;
F_7 ( V_15 L_3 ,
V_10 -> V_16 . V_17 , V_10 -> V_16 . V_18 ,
V_10 -> V_19 ) ;
if ( V_10 -> V_16 . V_20 != 1 ) {
F_7 ( V_14 L_4 ) ;
return - 1 ;
}
F_8 ( & V_21 ) ;
for ( V_4 = 0 ; V_4 < V_22 ; V_4 ++ ) {
if ( V_3 [ V_4 ] == NULL )
break;
}
if ( V_4 < 0 || V_4 >= V_22 ) {
F_7 ( V_14 L_5 , V_4 ) ;
goto V_23;
}
V_2 = F_9 ( sizeof( V_24 ) , V_25 ) ;
if ( V_2 == NULL ) {
F_7 ( V_14 L_6 ) ;
goto V_23;
}
V_3 [ V_4 ] = V_2 ;
F_7 ( V_15 L_7 ,
V_10 -> V_19 , V_10 -> V_26 -> V_27 , V_4 ) ;
memset ( V_2 , 0 , sizeof( V_24 ) ) ;
V_2 -> V_10 = V_10 ;
F_7 ( V_15 L_8 ) ;
F_10 ( & ( V_2 -> V_1 ) ) ;
F_11 ( & V_21 ) ;
if ( F_12 ( & V_13 , V_28 , & V_10 -> V_29 ) ) {
F_7 ( V_14
L_9 ,
V_28 ) ;
goto V_30;
}
V_11 = F_13 ( V_10 , V_13 , V_31 ) ;
F_14 ( V_13 ) ;
if ( 0 != V_11 ) {
F_7 ( V_14 L_10 ) ;
goto V_30;
}
if ( F_12 ( & V_13 , V_32 , & V_10 -> V_29 ) ) {
F_7 ( V_14
L_9 ,
V_32 ) ;
goto V_30;
}
V_11 = F_13 ( V_10 , V_13 , V_31 ) ;
F_14 ( V_13 ) ;
if ( 0 != V_11 ) {
F_7 ( V_14 L_11 ) ;
goto V_30;
}
F_15 ( V_6 , V_2 ) ;
return 0 ;
V_23:
F_11 ( & V_21 ) ;
V_30:
if ( V_2 )
F_16 ( & ( V_2 -> V_1 ) , F_1 ) ;
F_7 ( V_14 L_12 ) ;
return - 1 ;
}
static void F_17 ( struct V_5 * V_6 )
{
T_1 V_2 ;
F_7 ( V_15 L_13 ) ;
V_2 = F_18 ( V_6 ) ;
F_15 ( V_6 , NULL ) ;
F_16 ( & ( V_2 -> V_1 ) , F_1 ) ;
}
