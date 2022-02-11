unsigned char F_1 ( void T_1 * V_1 ,
unsigned char V_2 )
{
unsigned short V_3 , V_4 ;
unsigned char V_5 ;
unsigned char V_6 ;
unsigned char V_7 ;
V_6 = 0xFF ;
F_2 ( V_1 + V_8 , & V_7 ) ;
F_3 ( V_1 + V_8 , ( V_7 & ( ~ V_9 ) ) ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
F_3 ( V_1 + V_11 , V_12 ) ;
F_3 ( V_1 + V_13 , V_2 ) ;
F_3 ( V_1 + V_14 , V_15 ) ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
F_2 ( V_1 + V_14 , & V_5 ) ;
if ( V_5 & ( V_17 | V_18 ) )
break;
F_4 ( V_19 ) ;
}
if ( ( V_3 < V_16 ) &&
( ! ( V_5 & V_18 ) ) ) {
break;
}
}
F_2 ( V_1 + V_20 , & V_6 ) ;
F_3 ( V_1 + V_8 , V_7 ) ;
return V_6 ;
}
void F_5 ( void T_1 * V_1 , unsigned char * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
* V_21 = F_1 ( V_1 ,
( unsigned char ) V_22 ) ;
V_21 ++ ;
}
}
void F_6 ( void T_1 * V_1 ,
unsigned char * V_24 )
{
unsigned char V_22 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
* V_24 = F_1 ( V_1 , V_22 ) ;
V_24 ++ ;
}
}
