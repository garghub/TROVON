static int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
void T_2 * V_4 ;
V_3 = F_2 ( NULL , NULL , L_1 ) ;
V_4 = F_3 ( V_3 , 0 ) ;
F_4 ( V_3 ) ;
if ( ! V_4 )
return - V_5 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
F_5 ( 0x0 , V_4 + V_6 +
V_1 * V_7 ) ;
F_5 ( 0x0 , V_4 + V_8 +
V_1 * V_7 ) ;
}
F_6 ( V_4 ) ;
return 0 ;
}
static void F_7 ( unsigned long V_9 , unsigned V_10 )
{
}
static void T_1 F_8 ( void )
{
struct V_2 * V_3 ;
struct V_11 V_12 ;
F_9 () ;
V_3 = F_2 ( NULL , NULL , L_2 ) ;
F_10 ( V_3 , 0 , & V_12 ) ;
F_4 ( V_3 ) ;
if ( ! V_12 . V_13 ) {
F_11 ( L_3 ) ;
return;
}
F_12 ( V_12 . V_13 , V_12 . V_14 - V_12 . V_13 ) ;
F_13 ( V_12 . V_13 , V_12 . V_14 - V_12 . V_13 ) ;
F_1 () ;
V_15 . V_16 = F_7 ;
}
static void F_14 ( enum V_17 V_18 , const char * V_19 )
{
F_15 () ;
F_16 () ;
F_17 ( 0 ) ;
}
static T_3 F_18 ( int V_20 , void * V_21 , T_4 V_22 )
{
T_3 V_23 = V_22 ( V_20 , V_21 ) ;
int V_24 = ! F_19 () ;
if ( V_23 == V_25 && F_20 ( V_24 ) )
F_21 ( V_20 , F_22 ( V_24 ) ) ;
return V_23 ;
}
static void T_1 F_23 ( void )
{
if ( F_24 ( L_4 ) )
F_25 ( NULL , V_26 ,
V_27 , NULL ) ;
else
F_25 ( NULL , V_26 ,
V_28 , NULL ) ;
}
