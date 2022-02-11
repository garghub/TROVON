const struct V_1 * F_1 ( void )
{
return V_1 ;
}
void F_2 ( const struct V_1 * V_2 )
{
F_3 ( V_1 != NULL ) ;
V_1 = V_2 ;
}
void F_4 ( T_1 V_3 , const struct V_4 * V_5 ,
void * V_6 )
{
for (; V_5 -> V_7 ; V_5 ++ ) {
if ( V_5 -> V_3 != ( V_5 -> V_8 & V_3 ) )
continue;
V_5 -> V_9 ( V_6 ) ;
F_5 ( L_1 , V_5 -> V_7 ) ;
}
}
int F_6 ( unsigned int V_10 , unsigned int type ,
void T_2 * V_11 , void (* F_7)( void ) )
{
T_1 V_12 = 0x2 << ( ( V_10 % 16 ) * 2 ) ;
T_1 V_13 = ( V_10 / 16 ) * 4 ;
T_1 V_14 , V_15 ;
int V_16 = 0 ;
V_14 = V_15 = F_8 ( V_11 + V_17 + V_13 ) ;
if ( type & V_18 )
V_14 &= ~ V_12 ;
else if ( type & V_19 )
V_14 |= V_12 ;
if ( V_14 == V_15 )
return 0 ;
F_9 ( V_14 , V_11 + V_17 + V_13 ) ;
if ( F_8 ( V_11 + V_17 + V_13 ) != V_14 ) {
if ( F_10 ( V_10 >= 32 ) )
V_16 = - V_20 ;
else
F_11 ( L_2 ,
V_10 - 16 ) ;
}
if ( F_7 )
F_7 () ;
return V_16 ;
}
void T_3 F_12 ( void T_2 * V_11 , int V_21 ,
void (* F_7)( void ) )
{
unsigned int V_22 ;
for ( V_22 = 32 ; V_22 < V_21 ; V_22 += 16 )
F_9 ( V_23 ,
V_11 + V_17 + V_22 / 4 ) ;
for ( V_22 = 32 ; V_22 < V_21 ; V_22 += 4 )
F_9 ( V_24 , V_11 + V_25 + V_22 ) ;
for ( V_22 = 32 ; V_22 < V_21 ; V_22 += 32 ) {
F_9 ( V_26 ,
V_11 + V_27 + V_22 / 8 ) ;
F_9 ( V_26 ,
V_11 + V_28 + V_22 / 8 ) ;
}
if ( F_7 )
F_7 () ;
}
void F_13 ( void T_2 * V_11 , void (* F_7)( void ) )
{
int V_22 ;
F_9 ( V_26 , V_11 + V_27 ) ;
F_9 ( V_29 , V_11 + V_28 ) ;
F_9 ( V_30 , V_11 + V_31 ) ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 += 4 )
F_9 ( V_24 ,
V_11 + V_25 + V_22 * 4 / 4 ) ;
if ( F_7 )
F_7 () ;
}
