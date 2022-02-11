void T_1 F_1 ( int V_1 )
{
int V_2 ;
unsigned long V_3 ;
unsigned int V_4 ;
#ifdef F_2
return;
#endif
F_3 ( V_5 L_1 , V_1 ) ;
F_4 ( V_3 ) ;
F_5 ( & V_6 , F_6 () ) ;
F_5 ( & V_7 , V_1 ) ;
F_7 () ;
V_4 = F_6 () ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
while ( F_8 ( & V_9 ) != 1 )
F_9 () ;
F_5 ( & V_10 , 0 ) ;
F_7 () ;
F_10 ( & V_9 ) ;
if ( V_2 == V_8 - 1 )
F_11 ( V_4 ) ;
while ( F_8 ( & V_10 ) != 1 )
F_9 () ;
F_5 ( & V_9 , 0 ) ;
F_7 () ;
F_10 ( & V_10 ) ;
}
F_12 ( F_6 () + V_11 ) ;
F_5 ( & V_7 , 0 ) ;
F_13 ( V_3 ) ;
F_3 ( L_2 ) ;
}
void T_1 F_14 ( int V_1 )
{
int V_2 ;
unsigned int V_4 ;
#ifdef F_2
return;
#endif
while ( F_8 ( & V_7 ) != V_1 )
F_9 () ;
V_4 = F_8 ( & V_6 ) ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
F_10 ( & V_9 ) ;
while ( F_8 ( & V_9 ) != 2 )
F_9 () ;
if ( V_2 == V_8 - 1 )
F_11 ( V_4 ) ;
F_10 ( & V_10 ) ;
while ( F_8 ( & V_10 ) != 2 )
F_9 () ;
}
F_12 ( F_6 () + V_11 ) ;
}
