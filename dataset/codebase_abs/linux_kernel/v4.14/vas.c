static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
V_3 = F_2 ( V_10 , L_1 , & V_4 ) ;
if ( V_3 ) {
F_3 ( L_2 , V_2 -> V_13 ) ;
return - V_14 ;
}
if ( V_2 -> V_15 != 4 ) {
F_3 ( L_3 ,
V_2 -> V_13 , V_4 ) ;
return - V_14 ;
}
V_8 = F_4 ( sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
F_5 ( & V_8 -> V_18 ) ;
F_6 ( & V_8 -> V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
V_8 -> V_21 = V_4 ;
V_8 -> V_2 = V_2 ;
V_6 = & V_2 -> V_5 [ 0 ] ;
V_8 -> V_22 = V_6 -> V_23 ;
V_6 = & V_2 -> V_5 [ 1 ] ;
V_8 -> V_24 = V_6 -> V_23 ;
V_6 = & V_2 -> V_5 [ 2 ] ;
V_8 -> V_25 = V_6 -> V_23 ;
V_6 = & V_2 -> V_5 [ 3 ] ;
if ( V_6 -> V_26 > 62 ) {
F_3 ( L_4 , V_6 -> V_26 ) ;
goto V_27;
}
V_8 -> V_28 = 63 - V_6 -> V_26 ;
F_8 ( L_5
L_6 , V_2 -> V_13 , V_4 ,
V_8 -> V_25 , V_8 -> V_28 ) ;
F_9 ( & V_29 ) ;
F_10 ( & V_8 -> V_18 , & V_30 ) ;
F_11 ( & V_29 ) ;
F_12 ( & V_2 -> V_11 , V_8 ) ;
return 0 ;
V_27:
F_13 ( V_8 ) ;
return - V_14 ;
}
struct V_7 * F_14 ( int V_4 )
{
struct V_31 * V_32 ;
struct V_7 * V_8 ;
F_9 ( & V_29 ) ;
F_15 (ent, &vas_instances) {
V_8 = F_16 ( V_32 , struct V_7 , V_18 ) ;
if ( V_8 -> V_21 == V_4 ) {
F_11 ( & V_29 ) ;
return V_8 ;
}
}
F_11 ( & V_29 ) ;
F_8 ( L_7 , V_4 ) ;
return NULL ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
static int T_1 F_18 ( void )
{
int V_33 = 0 ;
struct V_9 * V_10 ;
F_19 ( & V_34 ) ;
F_20 (dn, NULL, L_8 ) {
F_21 ( V_10 , NULL , NULL ) ;
V_33 ++ ;
}
if ( ! V_33 )
return - V_14 ;
F_8 ( L_9 , V_33 ) ;
return 0 ;
}
