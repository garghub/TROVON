struct V_1 * F_1 ( unsigned int V_2 )
{
int V_3 = 0 ;
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (ssc, &ssc_list, list) {
if ( V_4 -> V_6 -> V_7 == V_2 ) {
V_3 = 1 ;
break;
}
}
if ( ! V_3 ) {
F_4 ( & V_5 ) ;
F_5 ( L_1 , V_2 ) ;
return F_6 ( - V_8 ) ;
}
if ( V_4 -> V_9 ) {
F_4 ( & V_5 ) ;
F_7 ( & V_4 -> V_6 -> V_10 , L_2 ) ;
return F_6 ( - V_11 ) ;
}
V_4 -> V_9 ++ ;
F_4 ( & V_5 ) ;
F_8 ( V_4 -> V_12 ) ;
return V_4 ;
}
void F_9 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_4 -> V_9 ) {
V_4 -> V_9 -- ;
F_10 ( V_4 -> V_12 ) ;
} else {
F_7 ( & V_4 -> V_6 -> V_10 , L_3 ) ;
}
F_4 ( & V_5 ) ;
}
static int T_1 F_11 ( struct V_13 * V_6 )
{
int V_14 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_12 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_4 ) {
F_7 ( & V_6 -> V_10 , L_4 ) ;
V_14 = - V_18 ;
goto V_19;
}
V_16 = F_13 ( V_6 , V_20 , 0 ) ;
if ( ! V_16 ) {
F_7 ( & V_6 -> V_10 , L_5 ) ;
V_14 = - V_21 ;
goto V_22;
}
V_4 -> V_12 = F_14 ( & V_6 -> V_10 , L_6 ) ;
if ( F_15 ( V_4 -> V_12 ) ) {
F_7 ( & V_6 -> V_10 , L_7 ) ;
V_14 = - V_21 ;
goto V_22;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_16 = F_16 ( V_16 -> V_23 , F_17 ( V_16 ) ) ;
if ( ! V_4 -> V_16 ) {
F_7 ( & V_6 -> V_10 , L_8 ) ;
V_14 = - V_24 ;
goto V_25;
}
F_8 ( V_4 -> V_12 ) ;
F_18 ( V_4 -> V_16 , V_26 , ~ 0UL ) ;
F_19 ( V_4 -> V_16 , V_27 ) ;
F_10 ( V_4 -> V_12 ) ;
V_4 -> V_28 = F_20 ( V_6 , 0 ) ;
if ( ! V_4 -> V_28 ) {
F_7 ( & V_6 -> V_10 , L_9 ) ;
V_14 = - V_21 ;
goto V_29;
}
F_2 ( & V_5 ) ;
F_21 ( & V_4 -> V_30 , & V_31 ) ;
F_4 ( & V_5 ) ;
F_22 ( V_6 , V_4 ) ;
F_23 ( & V_6 -> V_10 , L_10 ,
V_4 -> V_16 , V_4 -> V_28 ) ;
goto V_19;
V_29:
F_24 ( V_4 -> V_16 ) ;
V_25:
F_25 ( V_4 -> V_12 ) ;
V_22:
F_26 ( V_4 ) ;
V_19:
return V_14 ;
}
static int T_2 F_27 ( struct V_13 * V_6 )
{
struct V_1 * V_4 = F_28 ( V_6 ) ;
F_2 ( & V_5 ) ;
F_24 ( V_4 -> V_16 ) ;
F_25 ( V_4 -> V_12 ) ;
F_29 ( & V_4 -> V_30 ) ;
F_26 ( V_4 ) ;
F_4 ( & V_5 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_32 , F_11 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_32 ) ;
}
