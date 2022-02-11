struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (ssp, &ssp_list, node) {
if ( V_4 -> V_6 == V_2 && V_4 -> V_7 == 0 ) {
V_4 -> V_7 ++ ;
V_4 -> V_3 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( & V_4 -> V_8 == & V_9 )
return NULL ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 -- ;
V_4 -> V_3 = NULL ;
} else
F_6 ( & V_4 -> V_10 -> V_11 , L_1 ) ;
F_4 ( & V_5 ) ;
}
static int T_1 F_7 ( struct V_12 * V_10 )
{
const struct V_13 * V_14 = F_8 ( V_10 ) ;
struct V_15 * V_16 ;
struct V_1 * V_4 ;
int V_17 = 0 ;
V_4 = F_9 ( sizeof( struct V_1 ) , V_18 ) ;
if ( V_4 == NULL ) {
F_6 ( & V_10 -> V_11 , L_2 ) ;
return - V_19 ;
}
V_4 -> V_10 = V_10 ;
V_4 -> V_20 = F_10 ( & V_10 -> V_11 , NULL ) ;
if ( F_11 ( V_4 -> V_20 ) ) {
V_17 = F_12 ( V_4 -> V_20 ) ;
goto V_21;
}
V_16 = F_13 ( V_10 , V_22 , 0 ) ;
if ( V_16 == NULL ) {
F_6 ( & V_10 -> V_11 , L_3 ) ;
V_17 = - V_23 ;
goto V_24;
}
V_4 -> V_25 = V_16 -> V_26 ;
V_16 = F_13 ( V_10 , V_22 , 1 ) ;
if ( V_16 == NULL ) {
F_6 ( & V_10 -> V_11 , L_4 ) ;
V_17 = - V_23 ;
goto V_24;
}
V_4 -> V_27 = V_16 -> V_26 ;
V_16 = F_13 ( V_10 , V_28 , 0 ) ;
if ( V_16 == NULL ) {
F_6 ( & V_10 -> V_11 , L_5 ) ;
V_17 = - V_23 ;
goto V_24;
}
V_16 = F_14 ( V_16 -> V_26 , F_15 ( V_16 ) ,
V_10 -> V_29 ) ;
if ( V_16 == NULL ) {
F_6 ( & V_10 -> V_11 , L_6 ) ;
V_17 = - V_30 ;
goto V_24;
}
V_4 -> V_31 = V_16 -> V_26 ;
V_4 -> V_32 = F_16 ( V_16 -> V_26 , F_15 ( V_16 ) ) ;
if ( V_4 -> V_32 == NULL ) {
F_6 ( & V_10 -> V_11 , L_7 ) ;
V_17 = - V_23 ;
goto V_33;
}
V_4 -> V_34 = F_17 ( V_10 , 0 ) ;
if ( V_4 -> V_34 < 0 ) {
F_6 ( & V_10 -> V_11 , L_8 ) ;
V_17 = - V_23 ;
goto V_35;
}
V_4 -> V_6 = V_10 -> V_14 + 1 ;
V_4 -> V_7 = 0 ;
V_4 -> type = ( int ) V_14 -> V_36 ;
F_2 ( & V_5 ) ;
F_18 ( & V_4 -> V_8 , & V_9 ) ;
F_4 ( & V_5 ) ;
F_19 ( V_10 , V_4 ) ;
return 0 ;
V_35:
F_20 ( V_4 -> V_32 ) ;
V_33:
F_21 ( V_16 -> V_26 , F_15 ( V_16 ) ) ;
V_24:
F_22 ( V_4 -> V_20 ) ;
V_21:
F_23 ( V_4 ) ;
return V_17 ;
}
static int T_2 F_24 ( struct V_12 * V_10 )
{
struct V_15 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_25 ( V_10 ) ;
if ( V_4 == NULL )
return - V_23 ;
F_20 ( V_4 -> V_32 ) ;
V_16 = F_13 ( V_10 , V_28 , 0 ) ;
F_21 ( V_16 -> V_26 , F_15 ( V_16 ) ) ;
F_22 ( V_4 -> V_20 ) ;
F_2 ( & V_5 ) ;
F_26 ( & V_4 -> V_8 ) ;
F_4 ( & V_5 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_37 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_37 ) ;
}
