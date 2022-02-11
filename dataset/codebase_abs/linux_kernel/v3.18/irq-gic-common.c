void F_1 ( unsigned int V_1 , unsigned int type ,
void T_1 * V_2 , void (* F_2)( void ) )
{
T_2 V_3 = 1 << ( V_1 % 32 ) ;
T_2 V_4 = ( V_1 / 32 ) * 4 ;
T_2 V_5 = 0x2 << ( ( V_1 % 16 ) * 2 ) ;
T_2 V_6 = ( V_1 / 16 ) * 4 ;
bool V_7 = false ;
T_2 V_8 ;
V_8 = F_3 ( V_2 + V_9 + V_6 ) ;
if ( type == V_10 )
V_8 &= ~ V_5 ;
else if ( type == V_11 )
V_8 |= V_5 ;
if ( F_3 ( V_2 + V_12 + V_4 ) & V_3 ) {
F_4 ( V_3 , V_2 + V_13 + V_4 ) ;
if ( F_2 )
F_2 () ;
V_7 = true ;
}
F_4 ( V_8 , V_2 + V_9 + V_6 ) ;
if ( V_7 )
F_4 ( V_3 , V_2 + V_12 + V_4 ) ;
if ( F_2 )
F_2 () ;
}
void T_3 F_5 ( void T_1 * V_2 , int V_14 ,
void (* F_2)( void ) )
{
unsigned int V_15 ;
for ( V_15 = 32 ; V_15 < V_14 ; V_15 += 16 )
F_4 ( V_16 ,
V_2 + V_9 + V_15 / 4 ) ;
for ( V_15 = 32 ; V_15 < V_14 ; V_15 += 4 )
F_4 ( V_17 , V_2 + V_18 + V_15 ) ;
for ( V_15 = 32 ; V_15 < V_14 ; V_15 += 32 )
F_4 ( V_19 ,
V_2 + V_13 + V_15 / 8 ) ;
if ( F_2 )
F_2 () ;
}
void F_6 ( void T_1 * V_2 , void (* F_2)( void ) )
{
int V_15 ;
F_4 ( V_20 , V_2 + V_13 ) ;
F_4 ( V_21 , V_2 + V_12 ) ;
for ( V_15 = 0 ; V_15 < 32 ; V_15 += 4 )
F_4 ( V_17 ,
V_2 + V_18 + V_15 * 4 / 4 ) ;
if ( F_2 )
F_2 () ;
}
