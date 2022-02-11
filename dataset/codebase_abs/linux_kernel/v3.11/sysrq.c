void F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
unsigned long V_4 ;
if ( ! V_3 ) {
V_3 = ( unsigned long * ) & V_3 ;
F_2 ( 1 ) ;
}
F_3 ( V_5 L_1 ) ;
while ( ( ( long ) V_3 & ( V_6 - 1 ) ) != 0 ) {
V_4 = * V_3 ;
if ( F_4 ( V_4 ) ) {
F_3 ( V_5 L_2 ,
( unsigned long ) V_3 , V_4 ) ;
F_5 ( V_7 L_3 , V_4 ) ;
F_3 ( V_7 L_4 ) ;
}
V_3 ++ ;
}
F_3 ( V_5 L_4 ) ;
}
void F_6 ( struct V_1 * V_2 , unsigned long * V_8 )
{
unsigned long * V_3 ;
int V_9 ;
if ( V_8 == NULL ) {
if ( V_2 != V_10 && V_2 != NULL ) {
V_8 = ( unsigned long * ) F_7 ( V_2 ) ;
} else {
V_8 = ( unsigned long * ) & V_8 ;
}
}
V_3 = V_8 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( F_8 ( V_3 ) )
break;
if ( V_9 && ( ( V_9 % 8 ) == 0 ) )
F_3 ( V_5 L_5 ) ;
F_3 ( V_7 L_6 , * V_3 ++ ) ;
}
F_1 ( V_2 , V_8 ) ;
}
