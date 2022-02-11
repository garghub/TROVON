static void F_1 ( int V_1 )
{
int V_2 = F_2 ( V_3 , V_1 ) ;
if ( V_2 == - 1 )
return;
F_3 ( V_1 , V_4 ) ;
}
static void F_4 ( T_1 * V_5 , T_1 V_6 )
{
int V_2 = F_5 ( V_3 ) ;
if ( V_2 == - 1 )
return;
F_6 ( V_2 ) ;
F_7 () ;
if ( F_8 ( * V_5 ) != V_6 )
return;
F_9 ( V_2 ) ;
}
static T_2 F_10 ( int V_2 , void * V_7 )
{
F_11 () ;
return V_8 ;
}
void F_12 ( int V_1 )
{
int V_2 ;
char * V_9 ;
if ( ! V_10 )
return;
F_13 ( F_2 ( V_3 , V_1 ) >= 0 , L_1 ,
V_1 , F_2 ( V_3 , V_1 ) ) ;
V_9 = F_14 ( V_11 , L_2 , V_1 ) ;
V_2 = F_15 ( V_4 ,
V_1 ,
F_10 ,
V_12 | V_13 ,
V_9 ,
NULL ) ;
if ( V_2 >= 0 ) {
F_16 ( V_2 ) ;
F_2 ( V_3 , V_1 ) = V_2 ;
F_2 ( V_14 , V_1 ) = V_9 ;
}
F_17 ( L_3 , V_1 , V_2 ) ;
}
void F_18 ( int V_1 )
{
if ( ! V_10 )
return;
F_19 ( F_2 ( V_3 , V_1 ) , NULL ) ;
F_2 ( V_3 , V_1 ) = - 1 ;
F_20 ( F_2 ( V_14 , V_1 ) ) ;
F_2 ( V_14 , V_1 ) = NULL ;
}
void T_3 F_21 ( void )
{
if ( ! V_10 ) {
F_17 ( V_15 L_4 ) ;
return;
}
F_17 ( V_15 L_5 ) ;
F_22 () ;
V_16 . V_17 = V_18 ;
V_16 . V_19 = F_23 ( V_20 ) ;
V_16 . V_21 = F_4 ;
V_16 . V_22 = F_1 ;
}
static T_3 int F_24 ( void )
{
if ( ! V_10 )
return 0 ;
if ( ! F_25 () )
return 0 ;
F_26 ( & V_23 ) ;
return 0 ;
}
static T_3 int F_27 ( char * V_24 )
{
V_10 = false ;
return 0 ;
}
