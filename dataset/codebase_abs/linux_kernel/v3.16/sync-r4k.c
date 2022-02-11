void F_1 ( int V_1 )
{
int V_2 ;
unsigned long V_3 ;
unsigned int V_4 ;
F_2 ( V_5 L_1 , V_1 ) ;
F_3 ( V_3 ) ;
F_4 ( & V_6 , F_5 () ) ;
F_4 ( & V_7 , V_1 ) ;
F_6 () ;
V_4 = F_5 () ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
while ( F_7 ( & V_9 ) != 1 )
F_8 () ;
F_4 ( & V_10 , 0 ) ;
F_6 () ;
F_9 ( & V_9 ) ;
if ( V_2 == V_8 - 1 )
F_10 ( V_4 ) ;
while ( F_7 ( & V_10 ) != 1 )
F_8 () ;
F_4 ( & V_9 , 0 ) ;
F_6 () ;
F_9 ( & V_10 ) ;
}
F_11 ( F_5 () + V_11 ) ;
F_4 ( & V_7 , 0 ) ;
F_12 ( V_3 ) ;
F_2 ( L_2 ) ;
}
void F_13 ( int V_1 )
{
int V_2 ;
unsigned int V_4 ;
while ( F_7 ( & V_7 ) != V_1 )
F_8 () ;
V_4 = F_7 ( & V_6 ) ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
F_9 ( & V_9 ) ;
while ( F_7 ( & V_9 ) != 2 )
F_8 () ;
if ( V_2 == V_8 - 1 )
F_10 ( V_4 ) ;
F_9 ( & V_10 ) ;
while ( F_7 ( & V_10 ) != 2 )
F_8 () ;
}
F_11 ( F_5 () + V_11 ) ;
}
