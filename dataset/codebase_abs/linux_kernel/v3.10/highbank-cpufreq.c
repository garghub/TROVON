static int F_1 ( unsigned int V_1 )
{
T_1 V_2 [ V_3 ] = { V_4 , V_1 / 1000000 } ;
return F_2 ( V_2 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned long V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
int V_11 = 0 ;
if ( V_7 == V_12 ) {
if ( V_10 -> V_13 > V_10 -> V_14 )
while ( F_1 ( V_10 -> V_13 ) )
if ( V_11 ++ > V_15 )
return V_16 ;
} else if ( V_7 == V_17 ) {
if ( V_10 -> V_13 < V_10 -> V_14 )
while ( F_1 ( V_10 -> V_13 ) )
if ( V_11 ++ > V_15 )
return V_16 ;
}
return V_18 ;
}
static int F_4 ( void )
{
struct V_19 V_20 = { . V_21 = L_1 , } ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
if ( ! F_5 ( L_2 ) )
return - V_29 ;
F_6 (of_find_node_by_path(L_3), np)
if ( F_7 ( V_27 , L_4 , NULL ) )
break;
if ( ! V_27 ) {
F_8 ( L_5 ) ;
return - V_30 ;
}
V_23 = F_9 ( 0 ) ;
if ( ! V_23 ) {
F_8 ( L_6 ) ;
V_28 = - V_29 ;
goto V_31;
}
V_23 -> V_32 = V_27 ;
V_25 = F_10 ( V_23 , NULL ) ;
if ( F_11 ( V_25 ) ) {
V_28 = F_12 ( V_25 ) ;
F_8 ( L_7 , V_28 ) ;
goto V_31;
}
V_28 = F_13 ( V_25 , & V_33 ) ;
if ( V_28 ) {
F_8 ( L_8 , V_28 ) ;
goto V_31;
}
F_14 ( & V_20 ) ;
V_31:
F_15 ( V_27 ) ;
return V_28 ;
}
