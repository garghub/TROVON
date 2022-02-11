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
F_7 ( V_2 -> V_7 , V_2 -> V_10 ) ;
}
F_8 ( V_5 , V_11 ) ;
F_3 (pwrst, &pwrst_list, node) {
V_3 = F_9 ( V_2 -> V_7 ) ;
if ( V_3 > V_2 -> V_9 ) {
F_10 ( L_1 ,
V_2 -> V_7 -> V_12 , V_2 -> V_9 ) ;
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
static int T_2 F_13 ( struct V_13 * V_7 , void * V_14 )
{
struct V_1 * V_2 ;
if ( ! V_7 -> V_15 )
return 0 ;
if ( ! strncmp ( V_7 -> V_12 , L_5 , 3 ) ) {
if ( F_14 ( V_16 ) )
V_11 = V_17 ;
return 0 ;
}
V_2 = F_15 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = F_16 ( V_7 , false ,
V_17 ) ;
V_2 -> V_10 = F_16 ( V_7 , true ,
V_20 ) ;
F_17 ( & V_2 -> V_21 , & V_22 ) ;
return F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
}
static void F_18 ( void )
{
F_19 () ;
}
static inline int F_20 ( const struct V_23 * V_24 )
{
int V_4 ;
struct V_25 * V_26 , * V_27 ;
if ( ! V_24 )
return 0 ;
while ( V_24 -> V_26 ) {
V_26 = F_21 ( V_24 -> V_26 ) ;
V_27 = F_21 ( V_24 -> V_27 ) ;
if ( ! V_26 || ! V_27 ) {
F_22 ( L_6 ,
V_24 -> V_26 , V_24 -> V_27 ) ;
return - V_28 ;
}
V_4 = F_23 ( V_26 , V_27 ) ;
if ( V_4 ) {
F_22 ( L_7 ,
V_24 -> V_26 , V_24 -> V_27 , V_4 ) ;
return V_4 ;
}
V_24 ++ ;
} ;
return 0 ;
}
int T_2 F_24 ( void )
{
if ( F_25 () )
V_29 |= V_30 ;
if ( F_26 () || F_27 () )
V_29 |= V_16 ;
return 0 ;
}
int T_2 F_28 ( void )
{
int V_4 = 0 ;
if ( F_29 () == V_31 ) {
F_30 ( 1 , L_8 ) ;
return - V_32 ;
}
F_10 ( L_9 ) ;
if ( F_31 () )
F_12 ( L_10 ) ;
V_4 = F_32 ( F_13 , NULL ) ;
if ( V_4 ) {
F_22 ( L_11 ) ;
goto V_33;
}
if ( F_31 () )
V_4 = F_20 ( V_34 ) ;
else if ( F_26 () || F_27 () )
V_4 = F_20 ( V_35 ) ;
if ( V_4 ) {
F_22 ( L_12 ) ;
goto V_33;
}
V_4 = F_33 () ;
if ( V_4 ) {
F_22 ( L_13 ) ;
goto V_33;
}
( void ) F_34 ( V_36 , NULL ) ;
F_35 ( F_1 ) ;
V_37 = F_18 ;
if ( F_31 () )
F_36 () ;
V_33:
return V_4 ;
}
