int F_1 ( struct V_1 * V_1 )
{
int V_2 = - V_3 ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
enum V_6 V_7 ;
F_3 () ;
F_4 ( 3 , V_5 , L_1 , V_1 ) ;
F_5 ( & V_1 -> V_8 ) ;
F_6 ( V_1 -> V_9 ) ;
V_7 = V_1 -> V_7 ;
F_7 ( & V_1 -> V_8 ) ;
if ( V_7 >= V_10 ) {
F_5 ( & V_1 -> V_11 ) ;
V_2 = V_1 -> V_12 ( V_1 ) ;
F_7 ( & V_1 -> V_11 ) ;
}
F_8 ( V_1 -> V_9 ) ;
F_9 ( 3 , V_5 , L_2 , V_1 , V_2 ) ;
return V_2 ;
}
static
int F_10 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
int V_2 , V_17 ;
struct V_1 * V_1 ;
F_4 ( 3 , NULL , L_3 , V_14 , V_16 ) ;
V_2 = - V_18 ;
if ( V_16 -> V_19 [ V_20 ] == NULL ) {
F_11 ( V_21 L_4
L_5 ) ;
goto V_22;
}
V_17 = F_12 ( V_16 -> V_19 [ V_20 ] ) ;
V_1 = F_13 ( V_16 , V_17 ) ;
if ( V_1 == NULL )
goto V_22;
V_2 = F_1 ( V_1 ) ;
F_8 ( V_1 -> V_9 ) ;
V_22:
F_9 ( 3 , NULL , L_6 , V_14 , V_16 , V_2 ) ;
return V_2 ;
}
