static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( L_1 , V_5 , V_2 ) ;
if ( V_2 ) {
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_7 ) ;
V_4 -> V_6 = false ;
}
} else {
if ( ! V_4 -> V_6 ) {
F_4 ( V_4 -> V_7 ) ;
V_4 -> V_6 = true ;
}
}
F_2 ( L_2 , V_5 ,
F_5 ( V_4 -> V_7 ) ) ;
return 0 ;
}
static int T_1 F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
struct V_3 * V_4 ;
struct V_14 * V_7 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
if ( V_11 == NULL ) {
F_7 ( & V_9 -> V_12 , L_3 ) ;
return - V_18 ;
}
if ( V_11 -> V_19 == NULL || V_11 -> type == 0 ) {
F_7 ( & V_9 -> V_12 , L_4 ) ;
return - V_20 ;
}
V_7 = F_8 ( & V_9 -> V_12 , L_5 ) ;
if ( F_9 ( V_7 ) ) {
F_7 ( & V_9 -> V_12 , L_6 , V_11 -> V_19 ) ;
V_17 = F_10 ( V_7 ) ;
goto V_21;
}
V_4 = F_11 ( sizeof( * V_4 ) , V_22 ) ;
if ( V_4 == NULL ) {
V_17 = - V_23 ;
goto V_24;
}
V_16 = F_12 ( V_11 -> V_19 , & V_9 -> V_12 ,
V_11 -> type ,
& V_25 , V_4 ) ;
if ( V_16 == NULL ) {
V_17 = - V_23 ;
goto V_26;
}
if ( F_5 ( V_7 ) ) {
F_13 ( & V_9 -> V_12 , L_7 ) ;
V_4 -> V_6 = true ;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_16 = V_16 ;
V_17 = F_14 ( V_16 ) ;
if ( V_17 ) {
F_7 ( & V_9 -> V_12 , L_8 ) ;
goto V_27;
}
F_15 ( V_9 , V_4 ) ;
F_16 ( & V_9 -> V_12 , L_9 , V_11 -> V_19 ) ;
return 0 ;
V_27:
F_17 ( V_16 ) ;
V_26:
F_18 ( V_4 ) ;
V_24:
F_19 ( V_7 ) ;
V_21:
return V_17 ;
}
static int T_2 F_20 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_21 ( V_9 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
F_22 ( V_16 ) ;
F_17 ( V_16 ) ;
F_19 ( V_4 -> V_7 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
