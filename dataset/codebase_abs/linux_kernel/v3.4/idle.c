static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
static inline int F_3 ( void )
{
return ! V_2 ;
}
static void F_4 ( void )
{
F_5 () ;
while ( ! F_6 () )
F_7 () ;
}
void F_8 ( void )
{
if ( F_3 () ) {
F_9 ( V_3 ) ;
F_10 () ;
F_11 () ;
if ( ! F_6 () ) {
F_5 () ;
F_12 () ;
} else
F_5 () ;
F_13 ( V_3 ) ;
F_14 () ;
} else
F_4 () ;
}
void F_15 ( void )
{
unsigned int V_4 = F_16 () ;
F_13 ( V_3 ) ;
while ( 1 ) {
F_17 () ;
F_18 () ;
while ( ! F_6 () ) {
F_19 () ;
F_20 () ;
if ( F_21 ( V_4 ) )
F_22 () ;
F_23 () ;
F_24 () ;
if ( F_25 () )
F_26 () ;
F_27 ( F_28 () ) ;
F_29 () ;
}
F_30 () ;
F_31 () ;
F_32 () ;
}
}
void T_1 F_33 ( void )
{
if ( F_26 )
return;
if ( F_3 () )
F_26 = F_8 ;
else
F_26 = F_4 ;
}
static void F_34 ( void * V_5 )
{
}
void F_35 ( void * V_5 )
{
F_23 () ;
F_36 ( F_16 () , false ) ;
for (; ; )
F_12 () ;
}
void F_37 ( void )
{
F_38 () ;
F_39 ( F_34 , NULL , 1 ) ;
}
