static int F_1 ( const char * V_1 )
{
int V_2 = - V_3 ;
if ( F_2 () || F_3 () ) {
if ( ! strncmp ( V_1 , L_1 , 20 ) )
V_2 = 0 ;
else
V_2 = - V_4 ;
} else if ( ( F_4 () || F_5 () )
&& ! strcmp ( V_1 , L_2 ) )
V_2 = 0 ;
else if ( F_6 () ) {
if ( ! strcmp ( V_1 , L_3 ) ||
! strcmp ( V_1 , L_4 ) )
V_2 = 0 ;
else
V_2 = - V_4 ;
}
return V_2 ;
}
static int F_7 ( void )
{
return ( F_8 () ||
F_6 () ) ? 1 : 0 ;
}
static void T_1 F_9 ( void )
{
void * V_5 ;
unsigned long V_6 ;
if ( F_6 () )
V_6 = V_7 ;
else
V_6 = V_8 ;
V_5 = F_10 ( V_6 ) ;
if ( ! V_5 )
F_11 ( L_5 ) ;
V_9 [ 0 ] . V_10 = F_12 ( V_5 ) ;
V_9 [ 0 ] . V_11 = V_9 [ 0 ] . V_10 + V_6 - 1 ;
F_13 ( L_6 ,
V_6 , ( unsigned long ) V_5 ) ;
}
static int F_14 ( int V_12 )
{
if ( F_8 () ) {
if ( V_12 ) {
F_15 ( 32 , 1 ) ;
F_16 ( 100 ) ;
F_15 ( 20 , 1 ) ;
F_15 ( 17 , 1 ) ;
F_15 ( 19 , 1 ) ;
} else {
F_15 ( 17 , 0 ) ;
F_15 ( 19 , 0 ) ;
F_15 ( 20 , 0 ) ;
F_16 ( 100 ) ;
F_15 ( 32 , 0 ) ;
}
} else if ( F_6 () ) {
if ( V_12 ) {
F_15 ( 17 , 1 ) ;
F_15 ( 19 , 1 ) ;
F_15 ( 20 , 1 ) ;
F_15 ( 22 , 0 ) ;
F_15 ( 32 , 1 ) ;
F_15 ( 155 , 1 ) ;
F_15 ( 22 , 1 ) ;
} else {
F_15 ( 17 , 0 ) ;
F_15 ( 19 , 0 ) ;
F_15 ( 22 , 0 ) ;
F_15 ( 32 , 0 ) ;
F_15 ( 155 , 0 ) ;
}
}
return 0 ;
}
static void T_1 F_17 ( struct V_13 * V_14 , void * V_15 )
{
int V_2 ;
V_14 -> V_16 . V_17 = V_15 ;
V_2 = F_18 ( V_14 ) ;
if ( V_2 )
F_19 ( & V_14 -> V_16 ,
L_7 ,
V_18 , V_2 ) ;
}
void T_1 F_20 ( char * V_1 , void * V_15 )
{
if ( ! strncmp ( V_1 , L_8 , 3 ) )
F_17 ( & V_19 , V_15 ) ;
if ( ! strncmp ( V_1 , L_9 , 4 ) )
F_17 ( & V_20 , V_15 ) ;
}
static void T_1 F_21 ( void )
{
int V_21 ;
F_20 ( L_8 , & V_22 ) ;
if ( F_6 () ) {
V_21 = F_22 (
V_23 ,
F_23 ( V_23 ) ) ;
if ( V_21 ) {
F_11 ( V_24 L_10 ,
V_18 ) ;
return;
}
F_20 ( L_9 , & V_25 ) ;
} else
F_20 ( L_9 , 0 ) ;
}
int T_1 F_24 ( void )
{
F_9 () ;
return 0 ;
}
int T_1 F_25 ( void )
{
F_26 ( V_26 , F_23 ( V_26 ) ) ;
F_21 () ;
return 0 ;
}
