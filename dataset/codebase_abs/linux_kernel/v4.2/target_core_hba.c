int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
V_4 -> V_2 = V_2 ;
F_3 ( & V_8 ) ;
F_4 (old, &backend_list, list) {
if ( ! strcmp ( V_5 -> V_2 -> V_9 , V_2 -> V_9 ) ) {
F_5 ( L_1 , V_2 -> V_9 ) ;
F_6 ( & V_8 ) ;
F_7 ( V_4 ) ;
return - V_10 ;
}
}
F_8 ( V_4 ) ;
F_9 ( & V_4 -> V_11 , & V_12 ) ;
F_6 ( & V_8 ) ;
F_10 ( L_2 ,
V_2 -> V_9 , V_2 -> V_13 ) ;
return 0 ;
}
void F_11 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_3 ( & V_8 ) ;
F_4 (tb, &backend_list, list) {
if ( V_4 -> V_2 == V_2 ) {
F_12 ( & V_4 -> V_11 ) ;
F_6 ( & V_8 ) ;
F_13 () ;
F_7 ( V_4 ) ;
return;
}
}
F_6 ( & V_8 ) ;
}
static struct V_3 * F_14 ( const char * V_9 )
{
struct V_3 * V_4 ;
F_3 ( & V_8 ) ;
F_4 (tb, &backend_list, list) {
if ( ! strcmp ( V_4 -> V_2 -> V_9 , V_9 ) )
goto V_14;
}
F_6 ( & V_8 ) ;
return NULL ;
V_14:
if ( V_4 -> V_2 -> V_13 && ! F_15 ( V_4 -> V_2 -> V_13 ) )
V_4 = NULL ;
F_6 ( & V_8 ) ;
return V_4 ;
}
struct V_15 *
F_16 ( const char * V_16 , T_1 V_17 , T_1 V_18 )
{
struct V_15 * V_19 ;
int V_20 = 0 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_6 ) ;
if ( ! V_19 ) {
F_5 ( L_3 ) ;
return F_17 ( - V_7 ) ;
}
F_18 ( & V_19 -> V_21 ) ;
F_19 ( & V_19 -> V_22 ) ;
V_19 -> V_23 = F_20 ( V_24 ) ;
V_19 -> V_18 |= V_18 ;
V_19 -> V_25 = F_14 ( V_16 ) ;
if ( ! V_19 -> V_25 ) {
V_20 = - V_26 ;
goto V_27;
}
V_20 = V_19 -> V_25 -> V_2 -> V_28 ( V_19 , V_17 ) ;
if ( V_20 < 0 )
goto V_29;
F_21 ( & V_30 ) ;
V_19 -> V_31 = V_32 ++ ;
F_9 ( & V_19 -> V_33 , & V_34 ) ;
F_22 ( & V_30 ) ;
F_10 ( L_4
L_5 , V_19 -> V_31 ) ;
return V_19 ;
V_29:
F_23 ( V_19 -> V_25 -> V_2 -> V_13 ) ;
V_19 -> V_25 = NULL ;
V_27:
F_7 ( V_19 ) ;
return F_17 ( V_20 ) ;
}
int
F_24 ( struct V_15 * V_19 )
{
F_25 ( V_19 -> V_35 ) ;
V_19 -> V_25 -> V_2 -> V_36 ( V_19 ) ;
F_21 ( & V_30 ) ;
F_12 ( & V_19 -> V_33 ) ;
F_22 ( & V_30 ) ;
F_10 ( L_6
L_5 , V_19 -> V_31 ) ;
F_23 ( V_19 -> V_25 -> V_2 -> V_13 ) ;
V_19 -> V_25 = NULL ;
F_7 ( V_19 ) ;
return 0 ;
}
