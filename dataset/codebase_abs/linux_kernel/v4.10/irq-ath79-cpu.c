T_1 void F_1 ( void )
{
unsigned long V_1 ;
int V_2 ;
V_1 = F_2 () & F_3 () & V_3 ;
if ( ! V_1 ) {
F_4 () ;
return;
}
V_1 >>= V_4 ;
while ( V_1 ) {
V_2 = F_5 ( V_1 ) - 1 ;
if ( V_2 < F_6 ( V_5 ) && V_5 [ V_2 ] != - 1 )
F_7 ( V_5 [ V_2 ] ) ;
F_8 ( V_6 + V_2 ) ;
V_1 &= ~ F_9 ( V_2 ) ;
}
}
static int T_2 F_10 (
struct V_7 * V_8 , struct V_7 * V_9 )
{
int V_10 , V_11 , V_12 ;
V_12 = F_11 (
V_8 , L_1 , L_2 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
struct V_13 args ;
T_3 V_2 = V_11 ;
F_12 (
V_8 , L_3 , V_11 , & V_2 ) ;
if ( V_2 >= F_6 ( V_5 ) )
continue;
V_10 = F_13 (
V_8 , L_1 ,
L_2 ,
V_11 , & args ) ;
if ( V_10 )
return V_10 ;
V_5 [ V_2 ] = args . args [ 0 ] ;
}
return F_14 ( V_8 , V_9 ) ;
}
void T_2 F_15 ( unsigned V_14 , unsigned V_15 )
{
V_5 [ 2 ] = V_14 ;
V_5 [ 3 ] = V_15 ;
F_16 () ;
}
