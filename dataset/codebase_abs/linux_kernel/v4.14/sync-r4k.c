void F_1 ( int V_1 )
{
int V_2 ;
unsigned long V_3 ;
F_2 ( L_1 , V_1 ) ;
F_3 ( V_3 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
while ( F_4 ( & V_5 ) != 1 )
F_5 () ;
F_6 ( & V_6 , 0 ) ;
F_7 () ;
F_8 ( & V_5 ) ;
if ( V_2 == 1 )
V_7 = F_9 () ;
if ( V_2 == V_4 - 1 )
F_10 ( V_7 ) ;
while ( F_4 ( & V_6 ) != 1 )
F_5 () ;
F_6 ( & V_5 , 0 ) ;
F_7 () ;
F_8 ( & V_6 ) ;
}
F_11 ( F_9 () + V_8 ) ;
F_12 ( V_3 ) ;
F_13 ( L_2 ) ;
}
void F_14 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
F_8 ( & V_5 ) ;
while ( F_4 ( & V_5 ) != 2 )
F_5 () ;
if ( V_2 == V_4 - 1 )
F_10 ( V_7 ) ;
F_8 ( & V_6 ) ;
while ( F_4 ( & V_6 ) != 2 )
F_5 () ;
}
F_11 ( F_9 () + V_8 ) ;
}
