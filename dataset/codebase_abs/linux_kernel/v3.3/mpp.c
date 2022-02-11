static T_1 unsigned long F_1 ( unsigned int V_1 ,
unsigned long V_2 )
{
return V_2 + ( V_1 ) * 4 ;
}
void T_1 F_2 ( unsigned int * V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_2 )
{
unsigned int V_6 = ( 1 + V_5 / 8 ) ;
T_2 V_7 [ V_6 ] ;
int V_1 ;
F_3 ( V_8 L_1 ) ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
V_7 [ V_1 ] = F_4 ( F_1 ( V_1 , V_2 ) ) ;
F_3 ( L_2 , V_7 [ V_1 ] ) ;
}
F_3 ( L_3 ) ;
for ( ; * V_3 ; V_3 ++ ) {
unsigned int V_9 = F_5 ( * V_3 ) ;
unsigned int V_10 = F_6 ( * V_3 ) ;
int V_11 , V_12 ;
if ( V_9 > V_5 ) {
F_3 ( V_13 L_4
L_5 , V_9 ) ;
continue;
}
if ( V_4 & ! ( * V_3 & V_4 ) ) {
F_3 ( V_14
L_6
L_7 , V_9 ) ;
continue;
}
V_11 = ( V_9 & 7 ) << 2 ;
V_7 [ V_9 / 8 ] &= ~ ( 0xf << V_11 ) ;
V_7 [ V_9 / 8 ] |= V_10 << V_11 ;
V_12 = 0 ;
if ( * V_3 & V_15 )
V_12 |= V_16 ;
if ( * V_3 & V_17 )
V_12 |= V_18 ;
F_7 ( V_9 , V_12 ) ;
}
F_3 ( V_8 L_8 ) ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
F_8 ( V_7 [ V_1 ] , F_1 ( V_1 , V_2 ) ) ;
F_3 ( L_2 , V_7 [ V_1 ] ) ;
}
F_3 ( L_3 ) ;
}
