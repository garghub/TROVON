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
F_10 ( L_1
L_2 ,
V_2 -> V_7 -> V_11 , V_2 -> V_9 ) ;
V_4 = - 1 ;
}
F_6 ( V_2 -> V_7 , V_2 -> V_6 ) ;
F_7 ( V_2 -> V_7 , V_2 -> V_8 ) ;
}
if ( V_4 )
F_11 ( L_3 ) ;
else
F_10 ( L_4 ) ;
return 0 ;
}
static int T_2 F_12 ( struct V_12 * V_7 , void * V_13 )
{
struct V_1 * V_2 ;
if ( ! V_7 -> V_14 )
return 0 ;
if ( ! strncmp ( V_7 -> V_11 , L_5 , 3 ) )
return 0 ;
if ( strcmp ( V_7 -> V_11 , L_6 ) )
return 0 ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_17 ;
F_14 ( & V_2 -> V_18 , & V_19 ) ;
return F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
}
static void F_15 ( void )
{
F_16 () ;
F_17 () ;
F_18 () ;
}
int T_2 F_19 ( void )
{
int V_4 ;
struct V_20 * V_21 , * V_22 , * V_23 , * V_24 ;
struct V_20 * V_25 , * V_26 , * V_27 ;
if ( F_20 () == V_28 ) {
F_21 ( 1 , L_7 ) ;
return - V_29 ;
}
F_22 ( L_8 ) ;
V_4 = F_23 ( F_12 , NULL ) ;
if ( V_4 ) {
F_22 ( L_9 ) ;
goto V_30;
}
V_22 = F_24 ( L_10 ) ;
V_21 = F_24 ( L_11 ) ;
V_23 = F_24 ( L_12 ) ;
V_26 = F_24 ( L_13 ) ;
V_27 = F_24 ( L_14 ) ;
V_24 = F_24 ( L_15 ) ;
V_25 = F_24 ( L_16 ) ;
if ( ( ! V_22 ) || ( ! V_21 ) || ( ! V_23 ) || ( ! V_24 ) ||
( ! V_26 ) || ( ! V_25 ) || ( ! V_27 ) )
goto V_30;
V_4 = F_25 ( V_22 , V_21 ) ;
V_4 |= F_25 ( V_22 , V_23 ) ;
V_4 |= F_25 ( V_22 , V_26 ) ;
V_4 |= F_25 ( V_22 , V_27 ) ;
V_4 |= F_25 ( V_22 , V_24 ) ;
V_4 |= F_25 ( V_25 , V_23 ) ;
V_4 |= F_25 ( V_25 , V_26 ) ;
if ( V_4 ) {
F_22 ( L_17
L_18 ) ;
goto V_30;
}
V_4 = F_26 () ;
if ( V_4 ) {
F_22 ( L_19 ) ;
goto V_30;
}
( void ) F_27 ( V_31 , NULL ) ;
#ifdef F_28
V_32 = F_1 ;
#endif
V_33 = F_15 ;
F_29 () ;
V_30:
return V_4 ;
}
