void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static struct V_2 * F_3 ( char * V_3 )
{
struct V_2 * V_4 = NULL , * V_5 ;
F_4 (bat_algo_ops_tmp, &batadv_algo_list, list) {
if ( strcmp ( V_5 -> V_3 , V_3 ) != 0 )
continue;
V_4 = V_5 ;
break;
}
return V_4 ;
}
int F_5 ( struct V_2 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_3 ( V_4 -> V_3 ) ;
if ( V_5 ) {
F_6 ( L_1 ,
V_4 -> V_3 ) ;
return - V_6 ;
}
if ( ! V_4 -> V_7 . V_8 ||
! V_4 -> V_7 . V_9 ||
! V_4 -> V_7 . V_10 ||
! V_4 -> V_7 . V_11 ||
! V_4 -> V_12 . V_13 ||
! V_4 -> V_12 . V_14 ) {
F_6 ( L_2 ,
V_4 -> V_3 ) ;
return - V_15 ;
}
F_7 ( & V_4 -> V_16 ) ;
F_8 ( & V_4 -> V_16 , & V_1 ) ;
return 0 ;
}
int F_9 ( struct V_17 * V_18 , char * V_3 )
{
struct V_2 * V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( ! V_4 )
return - V_15 ;
V_18 -> V_19 = V_4 ;
return 0 ;
}
int F_10 ( struct V_20 * V_21 , void * V_22 )
{
struct V_2 * V_4 ;
F_11 ( V_21 , L_3 ) ;
F_4 (bat_algo_ops, &batadv_algo_list, list) {
F_12 ( V_21 , L_4 , V_4 -> V_3 ) ;
}
return 0 ;
}
static int F_13 ( const char * V_23 , const struct V_24 * V_25 )
{
struct V_2 * V_4 ;
char * V_26 = ( char * ) V_23 ;
T_1 V_27 = strlen ( V_26 ) ;
if ( V_27 > 0 && V_26 [ V_27 - 1 ] == '\n' )
V_26 [ V_27 - 1 ] = '\0' ;
V_4 = F_3 ( V_26 ) ;
if ( ! V_4 ) {
F_14 ( L_5 , V_26 ) ;
return - V_15 ;
}
return F_15 ( V_26 , V_25 ) ;
}
static int F_16 ( struct V_28 * V_29 , T_2 V_30 , T_2 V_21 ,
struct V_2 * V_4 )
{
void * V_31 ;
V_31 = F_17 ( V_29 , V_30 , V_21 , & V_32 ,
V_33 , V_34 ) ;
if ( ! V_31 )
return - V_35 ;
if ( F_18 ( V_29 , V_36 , V_4 -> V_3 ) )
goto V_37;
F_19 ( V_29 , V_31 ) ;
return 0 ;
V_37:
F_20 ( V_29 , V_31 ) ;
return - V_35 ;
}
int F_21 ( struct V_28 * V_29 , struct V_38 * V_39 )
{
int V_30 = F_22 ( V_39 -> V_40 ) . V_30 ;
struct V_2 * V_4 ;
int V_41 = V_39 -> args [ 0 ] ;
int V_42 = 0 ;
F_4 (bat_algo_ops, &batadv_algo_list, list) {
if ( V_42 ++ < V_41 )
continue;
if ( F_16 ( V_29 , V_30 , V_39 -> V_43 -> V_44 ,
V_4 ) ) {
V_42 -- ;
break;
}
}
V_39 -> args [ 0 ] = V_42 ;
return V_29 -> V_45 ;
}
