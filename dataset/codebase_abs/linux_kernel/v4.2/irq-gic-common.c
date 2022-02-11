int F_1 ( unsigned int V_1 , unsigned int type ,
void T_1 * V_2 , void (* F_2)( void ) )
{
T_2 V_3 = 0x2 << ( ( V_1 % 16 ) * 2 ) ;
T_2 V_4 = ( V_1 / 16 ) * 4 ;
T_2 V_5 , V_6 ;
int V_7 = 0 ;
V_5 = V_6 = F_3 ( V_2 + V_8 + V_4 ) ;
if ( type & V_9 )
V_5 &= ~ V_3 ;
else if ( type & V_10 )
V_5 |= V_3 ;
F_4 ( V_5 , V_2 + V_8 + V_4 ) ;
if ( F_3 ( V_2 + V_8 + V_4 ) != V_5 && V_5 != V_6 )
V_7 = - V_11 ;
if ( F_2 )
F_2 () ;
return V_7 ;
}
void T_3 F_5 ( void T_1 * V_2 , int V_12 ,
void (* F_2)( void ) )
{
unsigned int V_13 ;
for ( V_13 = 32 ; V_13 < V_12 ; V_13 += 16 )
F_4 ( V_14 ,
V_2 + V_8 + V_13 / 4 ) ;
for ( V_13 = 32 ; V_13 < V_12 ; V_13 += 4 )
F_4 ( V_15 , V_2 + V_16 + V_13 ) ;
for ( V_13 = 32 ; V_13 < V_12 ; V_13 += 32 )
F_4 ( V_17 ,
V_2 + V_18 + V_13 / 8 ) ;
if ( F_2 )
F_2 () ;
}
void F_6 ( void T_1 * V_2 , void (* F_2)( void ) )
{
int V_13 ;
F_4 ( V_19 , V_2 + V_18 ) ;
F_4 ( V_20 , V_2 + V_21 ) ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 += 4 )
F_4 ( V_15 ,
V_2 + V_16 + V_13 * 4 / 4 ) ;
if ( F_2 )
F_2 () ;
}
