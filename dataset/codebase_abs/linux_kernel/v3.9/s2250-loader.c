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
F_7 ( & V_6 -> V_14 , L_1 ) ;
return - 1 ;
}
F_8 ( & V_6 -> V_14 , L_2 ) ;
F_8 ( & V_6 -> V_14 , L_3 ,
V_10 -> V_15 . V_16 , V_10 -> V_15 . V_17 ,
V_10 -> V_18 ) ;
if ( V_10 -> V_15 . V_19 != 1 ) {
F_7 ( & V_6 -> V_14 , L_4 ) ;
return - 1 ;
}
F_9 ( & V_20 ) ;
for ( V_4 = 0 ; V_4 < V_21 ; V_4 ++ ) {
if ( V_3 [ V_4 ] == NULL )
break;
}
if ( V_4 < 0 || V_4 >= V_21 ) {
F_7 ( & V_6 -> V_14 , L_5 , V_4 ) ;
goto V_22;
}
V_2 = F_10 ( sizeof( V_23 ) , V_24 ) ;
if ( V_2 == NULL )
goto V_22;
V_3 [ V_4 ] = V_2 ;
F_8 ( & V_6 -> V_14 ,
L_6 ,
V_10 -> V_18 , V_10 -> V_25 -> V_26 , V_4 ) ;
memset ( V_2 , 0 , sizeof( V_23 ) ) ;
V_2 -> V_10 = V_10 ;
F_8 ( & V_6 -> V_14 , L_7 ) ;
F_11 ( & ( V_2 -> V_1 ) ) ;
F_12 ( & V_20 ) ;
if ( F_13 ( & V_13 , V_27 , & V_10 -> V_14 ) ) {
F_7 ( & V_6 -> V_14 ,
L_8 ,
V_27 ) ;
goto V_28;
}
V_11 = F_14 ( V_10 , V_13 , V_29 ) ;
F_15 ( V_13 ) ;
if ( 0 != V_11 ) {
F_7 ( & V_6 -> V_14 , L_9 ) ;
goto V_28;
}
if ( F_13 ( & V_13 , V_30 , & V_10 -> V_14 ) ) {
F_7 ( & V_6 -> V_14 ,
L_8 ,
V_30 ) ;
goto V_28;
}
V_11 = F_14 ( V_10 , V_13 , V_29 ) ;
F_15 ( V_13 ) ;
if ( 0 != V_11 ) {
F_7 ( & V_6 -> V_14 , L_10 ) ;
goto V_28;
}
F_16 ( V_6 , V_2 ) ;
return 0 ;
V_22:
F_12 ( & V_20 ) ;
V_28:
if ( V_2 )
F_17 ( & ( V_2 -> V_1 ) , F_1 ) ;
F_7 ( & V_6 -> V_14 , L_11 ) ;
return - 1 ;
}
static void F_18 ( struct V_5 * V_6 )
{
T_1 V_2 ;
F_8 ( & V_6 -> V_14 , L_12 ) ;
V_2 = F_19 ( V_6 ) ;
F_16 ( V_6 , NULL ) ;
F_17 ( & ( V_2 -> V_1 ) , F_1 ) ;
}
