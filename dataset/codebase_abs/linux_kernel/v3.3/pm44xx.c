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
static int F_12 ( T_2 V_12 )
{
int V_4 = 0 ;
switch ( V_12 ) {
case V_13 :
case V_14 :
V_4 = F_1 () ;
break;
default:
V_4 = - V_15 ;
}
return V_4 ;
}
static int F_13 ( T_2 V_3 )
{
F_14 () ;
return 0 ;
}
static void F_15 ( void )
{
F_16 () ;
return;
}
static int T_3 F_17 ( struct V_16 * V_17 , void * V_18 )
{
if ( V_17 -> V_19 & V_20 )
F_18 ( V_17 ) ;
else if ( V_17 -> V_19 & V_21 &&
F_19 ( & V_17 -> V_22 ) == 0 )
F_20 ( V_17 ) ;
return 0 ;
}
static int T_3 F_21 ( struct V_23 * V_7 , void * V_18 )
{
struct V_1 * V_2 ;
if ( ! V_7 -> V_24 )
return 0 ;
if ( ! strncmp ( V_7 -> V_11 , L_5 , 3 ) )
return 0 ;
if ( strcmp ( V_7 -> V_11 , L_6 ) )
return 0 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_27 ;
F_23 ( & V_2 -> V_28 , & V_29 ) ;
return F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
}
static void F_24 ( void )
{
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
}
static int T_3 F_30 ( void )
{
int V_4 ;
struct V_16 * V_30 , * V_31 , * V_32 ;
struct V_16 * V_33 , * V_34 , * V_35 ;
if ( ! F_31 () )
return - V_36 ;
if ( F_32 () == V_37 ) {
F_33 ( 1 , L_7 ) ;
return - V_36 ;
}
F_34 ( L_8 ) ;
V_4 = F_35 ( F_21 , NULL ) ;
if ( V_4 ) {
F_34 ( L_9 ) ;
goto V_38;
}
V_31 = F_36 ( L_10 ) ;
V_30 = F_36 ( L_11 ) ;
V_32 = F_36 ( L_12 ) ;
V_34 = F_36 ( L_13 ) ;
V_35 = F_36 ( L_14 ) ;
V_33 = F_36 ( L_15 ) ;
if ( ( ! V_31 ) || ( ! V_30 ) || ( ! V_32 ) ||
( ! V_34 ) || ( ! V_33 ) || ( ! V_35 ) )
goto V_38;
V_4 = F_37 ( V_31 , V_30 ) ;
V_4 |= F_37 ( V_31 , V_32 ) ;
V_4 |= F_37 ( V_31 , V_34 ) ;
V_4 |= F_37 ( V_31 , V_35 ) ;
V_4 |= F_37 ( V_33 , V_32 ) ;
V_4 |= F_37 ( V_33 , V_34 ) ;
if ( V_4 ) {
F_34 ( L_16
L_17 ) ;
goto V_38;
}
V_4 = F_38 () ;
if ( V_4 ) {
F_34 ( L_18 ) ;
goto V_38;
}
( void ) F_39 ( F_17 , NULL ) ;
#ifdef F_40
F_41 ( & V_39 ) ;
#endif
V_40 = F_24 ;
F_42 () ;
V_38:
return V_4 ;
}
