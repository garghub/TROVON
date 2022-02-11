static int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 , V_4 = 0 ;
T_1 V_5 = F_2 () ;
F_3 (pwrst, &pwrst_list, node) {
V_2 -> V_6 = F_4 ( V_2 -> V_7 ) ;
V_2 -> V_8 = F_5 ( V_2 -> V_7 ) ;
}
F_3 (pwrst, &pwrst_list, node) {
F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
F_7 ( V_2 -> V_7 , V_10 ) ;
}
F_8 ( V_5 , V_10 ) ;
F_3 (pwrst, &pwrst_list, node) {
V_3 = F_9 ( V_2 -> V_7 ) ;
if ( V_3 > V_2 -> V_9 ) {
F_10 ( L_1 ,
V_2 -> V_7 -> V_11 , V_2 -> V_9 ) ;
V_4 = - 1 ;
}
F_6 ( V_2 -> V_7 , V_2 -> V_6 ) ;
F_7 ( V_2 -> V_7 , V_2 -> V_8 ) ;
}
if ( V_4 ) {
F_11 ( L_2 ) ;
F_12 ( L_3 ) ;
} else {
F_10 ( L_4 ) ;
}
return 0 ;
}
static int T_2 F_13 ( struct V_12 * V_7 , void * V_13 )
{
struct V_1 * V_2 ;
if ( ! V_7 -> V_14 )
return 0 ;
if ( ! strncmp ( V_7 -> V_11 , L_5 , 3 ) )
return 0 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_17 ;
F_15 ( & V_2 -> V_18 , & V_19 ) ;
return F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
}
static void F_16 ( void )
{
F_17 () ;
}
int T_2 F_18 ( void )
{
int V_4 ;
struct V_20 * V_21 , * V_22 , * V_23 ;
struct V_20 * V_24 , * V_25 ;
if ( F_19 () == V_26 ) {
F_20 ( 1 , L_6 ) ;
return - V_27 ;
}
F_21 ( L_7 ) ;
F_12 ( L_8 ) ;
V_4 = F_22 ( F_13 , NULL ) ;
if ( V_4 ) {
F_21 ( L_9 ) ;
goto V_28;
}
V_22 = F_23 ( L_10 ) ;
V_21 = F_23 ( L_11 ) ;
V_23 = F_23 ( L_12 ) ;
V_25 = F_23 ( L_13 ) ;
V_24 = F_23 ( L_14 ) ;
if ( ( ! V_22 ) || ( ! V_21 ) || ( ! V_23 ) ||
( ! V_25 ) || ( ! V_24 ) )
goto V_28;
V_4 = F_24 ( V_22 , V_21 ) ;
V_4 |= F_24 ( V_22 , V_23 ) ;
V_4 |= F_24 ( V_22 , V_25 ) ;
V_4 |= F_24 ( V_24 , V_23 ) ;
V_4 |= F_24 ( V_24 , V_25 ) ;
if ( V_4 ) {
F_21 ( L_15 ) ;
goto V_28;
}
V_4 = F_25 () ;
if ( V_4 ) {
F_21 ( L_16 ) ;
goto V_28;
}
( void ) F_26 ( V_29 , NULL ) ;
#ifdef F_27
V_30 = F_1 ;
#endif
V_31 = F_16 ;
F_28 () ;
V_28:
return V_4 ;
}
