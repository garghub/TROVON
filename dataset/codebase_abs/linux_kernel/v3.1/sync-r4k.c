void T_1 F_1 ( void )
{
int V_1 ;
unsigned long V_2 ;
unsigned int V_3 ;
int V_4 ;
#ifdef F_2
return;
#endif
F_3 ( V_5 L_1 ,
F_4 () ) ;
F_5 ( V_2 ) ;
F_6 ( & V_6 , F_7 () ) ;
F_6 ( & V_7 , 1 ) ;
F_8 () ;
V_3 = F_7 () ;
V_4 = F_4 () - 1 ;
for ( V_1 = 0 ; V_1 < V_8 ; V_1 ++ ) {
while ( F_9 ( & V_9 ) != V_4 )
F_10 () ;
F_6 ( & V_10 , 0 ) ;
F_8 () ;
F_11 ( & V_9 ) ;
if ( V_1 == V_8 - 1 )
F_12 ( V_3 ) ;
while ( F_9 ( & V_10 ) != V_4 )
F_10 () ;
F_6 ( & V_9 , 0 ) ;
F_8 () ;
F_11 ( & V_10 ) ;
}
F_13 ( F_7 () + V_11 ) ;
F_14 ( V_2 ) ;
F_3 ( L_2 ) ;
}
void T_1 F_15 ( void )
{
int V_1 ;
unsigned long V_2 ;
unsigned int V_3 ;
int V_12 ;
#ifdef F_2
return;
#endif
F_5 ( V_2 ) ;
while ( ! F_9 ( & V_7 ) )
F_10 () ;
V_3 = F_9 ( & V_6 ) ;
V_12 = F_4 () ;
for ( V_1 = 0 ; V_1 < V_8 ; V_1 ++ ) {
F_11 ( & V_9 ) ;
while ( F_9 ( & V_9 ) != V_12 )
F_10 () ;
if ( V_1 == V_8 - 1 )
F_12 ( V_3 ) ;
F_11 ( & V_10 ) ;
while ( F_9 ( & V_10 ) != V_12 )
F_10 () ;
}
F_13 ( F_7 () + V_11 ) ;
F_14 ( V_2 ) ;
}
