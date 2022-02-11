void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
if ( F_3 () || F_4 () > V_2 )
F_5 ( V_3 ) ;
else
F_5 ( 0 ) ;
F_6 ( V_4 , V_5 ) ;
F_6 ( V_6 , V_5 ) ;
F_6 ( V_7 , V_8 ) ;
}
void T_1 F_7 ( void )
{
F_2 ( & V_1 ) ;
}
static void F_8 ( void )
{
int V_9 ;
const struct V_10 V_11 [] = {
{ V_12 , V_13 ,
L_1 } ,
{ V_14 . V_15 , V_16 ,
L_2 } ,
{ V_14 . V_17 , V_13 ,
L_3 } ,
} ;
V_9 = F_9 ( V_11 , F_10 ( V_11 ) ) ;
if ( V_9 )
F_11 ( L_4 , V_9 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
F_13 ( V_20 , 0 ) ;
F_13 ( V_12 , 1 ) ;
return 0 ;
}
static void F_14 ( struct V_18 * V_19 )
{
F_13 ( V_12 , 0 ) ;
F_13 ( V_20 , 1 ) ;
}
void T_1 F_15 ( void )
{
int V_9 ;
V_9 = F_16 ( V_20 , V_21 ,
L_5 ) ;
if ( V_9 )
F_11 ( L_6 , V_22 ) ;
F_8 () ;
F_2 ( & V_23 ) ;
if ( F_3 () || F_4 () > V_2 )
F_5 ( V_3 ) ;
else
F_5 ( 0 ) ;
F_6 ( V_4 , V_5 ) ;
F_6 ( V_6 , V_5 ) ;
F_6 ( V_7 , V_8 ) ;
}
void T_1 F_17 ( void )
{
int V_9 ;
V_9 = F_16 ( V_20 , V_21 ,
L_5 ) ;
if ( V_9 )
F_11 ( L_6 , V_22 ) ;
F_8 () ;
F_2 ( & V_23 ) ;
}
