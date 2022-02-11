static void F_1 ( int * V_1 , int * V_2 )
{
#ifdef F_2
* V_1 = F_3 ( 0 ) ;
* V_2 = F_3 ( 12 ) ;
#else
* V_1 = F_4 ( 0 ) ;
* V_2 = F_4 ( 3 ) ;
#endif
}
int F_5 ( void )
{
int V_1 , V_2 ;
int V_3 , V_4 ;
F_1 ( & V_1 , & V_2 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
int V_6 = V_1 + V_4 ;
if ( V_6 == V_2 )
continue;
V_3 = F_6 ( V_6 , L_1 ) ;
if ( ! V_3 )
V_3 = F_7 ( V_6 , F_8 ( 2 ) ) ;
if ( V_3 ) {
F_9 ( L_2 , V_6 ) ;
for ( -- V_4 ; V_4 >= 0 ; V_4 -- )
F_10 ( V_6 -- ) ;
return V_3 ;
}
F_11 ( V_6 , V_7 ) ;
}
return 0 ;
}
void F_12 ( void )
{
int V_4 , V_1 , V_2 ;
F_1 ( & V_1 , & V_2 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
int V_6 = V_1 + V_4 ;
if ( V_6 != V_2 )
F_10 ( V_6 ) ;
}
}
