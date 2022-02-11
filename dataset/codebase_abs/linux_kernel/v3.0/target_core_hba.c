int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_5 ) ;
F_4 (s, &subsystem_list, sub_api_list) {
if ( ! ( strcmp ( V_3 -> V_6 , V_2 -> V_6 ) ) ) {
F_5 ( V_7 L_1
L_2
L_3 , V_3 , V_3 -> V_6 ) ;
F_6 ( & V_5 ) ;
return - V_8 ;
}
}
F_7 ( & V_2 -> V_4 , & V_9 ) ;
F_6 ( & V_5 ) ;
F_5 ( V_10 L_4
L_5 , V_2 -> V_6 , V_2 -> V_11 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_3 ( & V_5 ) ;
F_9 ( & V_2 -> V_4 ) ;
F_6 ( & V_5 ) ;
}
static struct V_1 * F_10 ( const char * V_12 )
{
struct V_1 * V_3 ;
F_3 ( & V_5 ) ;
F_4 (s, &subsystem_list, sub_api_list) {
if ( ! strcmp ( V_3 -> V_6 , V_12 ) )
goto V_13;
}
F_6 ( & V_5 ) ;
return NULL ;
V_13:
if ( V_3 -> V_11 && ! F_11 ( V_3 -> V_11 ) )
V_3 = NULL ;
F_6 ( & V_5 ) ;
return V_3 ;
}
struct V_14 *
F_12 ( const char * V_15 , T_1 V_16 , T_1 V_17 )
{
struct V_14 * V_18 ;
int V_19 = 0 ;
V_18 = F_13 ( sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 ) {
F_5 ( V_7 L_6 ) ;
return F_14 ( - V_21 ) ;
}
F_2 ( & V_18 -> V_22 ) ;
F_15 ( & V_18 -> V_23 ) ;
F_15 ( & V_18 -> V_24 ) ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_26 = F_17 ( V_27 ) ;
V_18 -> V_17 |= V_17 ;
F_18 ( & V_18 -> V_28 , 0 ) ;
F_18 ( & V_18 -> V_29 , 0 ) ;
V_18 -> V_30 = F_10 ( V_15 ) ;
if ( ! V_18 -> V_30 ) {
V_19 = - V_31 ;
goto V_32;
}
V_19 = V_18 -> V_30 -> V_33 ( V_18 , V_16 ) ;
if ( V_19 < 0 )
goto V_34;
F_19 ( & V_35 -> V_36 ) ;
V_18 -> V_37 = V_35 -> V_38 ++ ;
F_7 ( & V_18 -> V_39 , & V_35 -> V_40 ) ;
F_20 ( & V_35 -> V_36 ) ;
F_5 ( V_10 L_7
L_8 , V_18 -> V_37 ) ;
return V_18 ;
V_34:
if ( V_18 -> V_30 -> V_11 )
F_21 ( V_18 -> V_30 -> V_11 ) ;
V_18 -> V_30 = NULL ;
V_32:
F_22 ( V_18 ) ;
return F_14 ( V_19 ) ;
}
int
F_23 ( struct V_14 * V_18 )
{
if ( ! F_24 ( & V_18 -> V_22 ) )
F_25 () ;
V_18 -> V_30 -> V_41 ( V_18 ) ;
F_19 ( & V_35 -> V_36 ) ;
F_9 ( & V_18 -> V_39 ) ;
F_20 ( & V_35 -> V_36 ) ;
F_5 ( V_10 L_9
L_8 , V_18 -> V_37 ) ;
if ( V_18 -> V_30 -> V_11 )
F_21 ( V_18 -> V_30 -> V_11 ) ;
V_18 -> V_30 = NULL ;
F_22 ( V_18 ) ;
return 0 ;
}
