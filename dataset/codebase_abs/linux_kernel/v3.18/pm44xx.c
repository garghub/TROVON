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
static inline int F_20 ( void )
{
struct V_23 * V_24 , * V_25 , * V_26 ;
struct V_23 * V_27 , * V_28 ;
int V_4 = 0 ;
if ( F_21 () == V_29 ) {
F_22 ( 1 , L_6 ) ;
return - V_30 ;
}
F_23 ( L_7 ) ;
F_12 ( L_8 ) ;
V_4 = F_24 ( F_13 , NULL ) ;
if ( V_4 ) {
F_23 ( L_9 ) ;
return V_4 ;
}
V_25 = F_25 ( L_10 ) ;
V_24 = F_25 ( L_11 ) ;
V_26 = F_25 ( L_12 ) ;
V_28 = F_25 ( L_13 ) ;
V_27 = F_25 ( L_14 ) ;
if ( ( ! V_25 ) || ( ! V_24 ) || ( ! V_26 ) ||
( ! V_28 ) || ( ! V_27 ) )
return - V_31 ;
V_4 = F_26 ( V_25 , V_24 ) ;
V_4 |= F_26 ( V_25 , V_26 ) ;
V_4 |= F_26 ( V_25 , V_28 ) ;
V_4 |= F_26 ( V_27 , V_26 ) ;
V_4 |= F_26 ( V_27 , V_28 ) ;
if ( V_4 ) {
F_23 ( L_15 ) ;
return - V_31 ;
}
return V_4 ;
}
static inline int F_27 ( void )
{
struct V_23 * V_25 , * V_24 ;
int V_4 ;
V_25 = F_25 ( L_16 ) ;
V_24 = F_25 ( L_17 ) ;
if ( ! V_25 || ! V_24 )
return - V_31 ;
V_4 = F_26 ( V_25 , V_24 ) ;
if ( V_4 )
F_23 ( L_18 ) ;
return V_4 ;
}
int T_2 F_28 ( void )
{
if ( F_29 () )
V_32 |= V_33 ;
if ( F_30 () || F_31 () )
V_32 |= V_16 ;
return 0 ;
}
int T_2 F_32 ( void )
{
int V_4 = 0 ;
if ( F_21 () == V_29 ) {
F_22 ( 1 , L_6 ) ;
return - V_30 ;
}
F_10 ( L_19 ) ;
V_4 = F_24 ( F_13 , NULL ) ;
if ( V_4 ) {
F_23 ( L_20 ) ;
goto V_34;
}
if ( F_33 () )
V_4 = F_20 () ;
else if ( F_30 () || F_31 () )
V_4 = F_27 () ;
if ( V_4 ) {
F_23 ( L_21 ) ;
goto V_34;
}
V_4 = F_34 () ;
if ( V_4 ) {
F_23 ( L_22 ) ;
goto V_34;
}
( void ) F_35 ( V_35 , NULL ) ;
F_36 ( F_1 ) ;
V_36 = F_18 ;
if ( F_33 () )
F_37 () ;
V_34:
return V_4 ;
}
