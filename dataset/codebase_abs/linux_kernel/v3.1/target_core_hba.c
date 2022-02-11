int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_5 ) ;
F_4 (s, &subsystem_list, sub_api_list) {
if ( ! strcmp ( V_3 -> V_6 , V_2 -> V_6 ) ) {
F_5 ( L_1
L_2
L_3 , V_3 , V_3 -> V_6 ) ;
F_6 ( & V_5 ) ;
return - V_7 ;
}
}
F_7 ( & V_2 -> V_4 , & V_8 ) ;
F_6 ( & V_5 ) ;
F_8 ( L_4
L_5 , V_2 -> V_6 , V_2 -> V_9 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_3 ( & V_5 ) ;
F_10 ( & V_2 -> V_4 ) ;
F_6 ( & V_5 ) ;
}
static struct V_1 * F_11 ( const char * V_10 )
{
struct V_1 * V_3 ;
F_3 ( & V_5 ) ;
F_4 (s, &subsystem_list, sub_api_list) {
if ( ! strcmp ( V_3 -> V_6 , V_10 ) )
goto V_11;
}
F_6 ( & V_5 ) ;
return NULL ;
V_11:
if ( V_3 -> V_9 && ! F_12 ( V_3 -> V_9 ) )
V_3 = NULL ;
F_6 ( & V_5 ) ;
return V_3 ;
}
struct V_12 *
F_13 ( const char * V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_12 * V_16 ;
int V_17 = 0 ;
V_16 = F_14 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 ) {
F_5 ( L_6 ) ;
return F_15 ( - V_19 ) ;
}
F_2 ( & V_16 -> V_20 ) ;
F_16 ( & V_16 -> V_21 ) ;
F_17 ( & V_16 -> V_22 ) ;
V_16 -> V_23 = F_18 ( V_24 ) ;
V_16 -> V_15 |= V_15 ;
V_16 -> V_25 = F_11 ( V_13 ) ;
if ( ! V_16 -> V_25 ) {
V_17 = - V_26 ;
goto V_27;
}
V_17 = V_16 -> V_25 -> V_28 ( V_16 , V_14 ) ;
if ( V_17 < 0 )
goto V_29;
F_19 ( & V_30 ) ;
V_16 -> V_31 = V_32 ++ ;
F_7 ( & V_16 -> V_33 , & V_34 ) ;
F_20 ( & V_30 ) ;
F_8 ( L_7
L_8 , V_16 -> V_31 ) ;
return V_16 ;
V_29:
if ( V_16 -> V_25 -> V_9 )
F_21 ( V_16 -> V_25 -> V_9 ) ;
V_16 -> V_25 = NULL ;
V_27:
F_22 ( V_16 ) ;
return F_15 ( V_17 ) ;
}
int
F_23 ( struct V_12 * V_16 )
{
if ( ! F_24 ( & V_16 -> V_20 ) )
F_25 () ;
V_16 -> V_25 -> V_35 ( V_16 ) ;
F_19 ( & V_30 ) ;
F_10 ( & V_16 -> V_33 ) ;
F_20 ( & V_30 ) ;
F_8 ( L_9
L_8 , V_16 -> V_31 ) ;
if ( V_16 -> V_25 -> V_9 )
F_21 ( V_16 -> V_25 -> V_9 ) ;
V_16 -> V_25 = NULL ;
F_22 ( V_16 ) ;
return 0 ;
}
