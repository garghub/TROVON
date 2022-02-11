int F_1 ( unsigned int V_1 , unsigned int type ,
void T_1 * V_2 , void (* F_2)( void ) )
{
T_2 V_3 = 1 << ( V_1 % 32 ) ;
T_2 V_4 = ( V_1 / 32 ) * 4 ;
T_2 V_5 = 0x2 << ( ( V_1 % 16 ) * 2 ) ;
T_2 V_6 = ( V_1 / 16 ) * 4 ;
bool V_7 = false ;
T_2 V_8 , V_9 ;
int V_10 = 0 ;
V_8 = V_9 = F_3 ( V_2 + V_11 + V_6 ) ;
if ( type & V_12 )
V_8 &= ~ V_5 ;
else if ( type & V_13 )
V_8 |= V_5 ;
if ( F_3 ( V_2 + V_14 + V_4 ) & V_3 ) {
F_4 ( V_3 , V_2 + V_15 + V_4 ) ;
if ( F_2 )
F_2 () ;
V_7 = true ;
}
F_4 ( V_8 , V_2 + V_11 + V_6 ) ;
if ( F_3 ( V_2 + V_11 + V_6 ) != V_8 && V_8 != V_9 )
V_10 = - V_16 ;
if ( V_7 )
F_4 ( V_3 , V_2 + V_14 + V_4 ) ;
if ( F_2 )
F_2 () ;
return V_10 ;
}
void T_3 F_5 ( void T_1 * V_2 , int V_17 ,
void (* F_2)( void ) )
{
unsigned int V_18 ;
for ( V_18 = 32 ; V_18 < V_17 ; V_18 += 16 )
F_4 ( V_19 ,
V_2 + V_11 + V_18 / 4 ) ;
for ( V_18 = 32 ; V_18 < V_17 ; V_18 += 4 )
F_4 ( V_20 , V_2 + V_21 + V_18 ) ;
for ( V_18 = 32 ; V_18 < V_17 ; V_18 += 32 )
F_4 ( V_22 ,
V_2 + V_15 + V_18 / 8 ) ;
if ( F_2 )
F_2 () ;
}
void F_6 ( void T_1 * V_2 , void (* F_2)( void ) )
{
int V_18 ;
F_4 ( V_23 , V_2 + V_15 ) ;
F_4 ( V_24 , V_2 + V_14 ) ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 += 4 )
F_4 ( V_20 ,
V_2 + V_21 + V_18 * 4 / 4 ) ;
if ( F_2 )
F_2 () ;
}
