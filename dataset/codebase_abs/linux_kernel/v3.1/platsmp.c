static void F_1 ( int V_1 )
{
V_2 = V_1 ;
F_2 () ;
F_3 ( ( void * ) & V_2 , sizeof( V_2 ) ) ;
F_4 ( F_5 ( & V_2 ) , F_5 ( & V_2 + 1 ) ) ;
}
static void T_1 * F_6 ( void )
{
return ( void T_1 * ) ( V_3 ) ;
}
static void T_2 F_7 ( void )
{
void T_1 * V_4 = V_5 +
( V_6 * F_8 () ) ;
void T_1 * V_7 = V_8 +
( V_6 * F_8 () ) ;
int V_9 ;
F_9 ( 0xffff0000 , V_4 + V_10 ) ;
F_9 ( 0x0000ffff , V_4 + V_11 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 += 4 )
F_9 ( 0xa0a0a0a0 , V_4 + V_12 + V_9 * 4 / 4 ) ;
F_9 ( 0xf0 , V_7 + V_13 ) ;
F_9 ( 1 , V_7 + V_14 ) ;
}
void T_2 F_10 ( unsigned int V_15 )
{
F_7 () ;
F_1 ( - 1 ) ;
F_11 ( & V_16 ) ;
F_12 ( & V_16 ) ;
F_13 ( V_15 , true ) ;
}
int T_2 F_14 ( unsigned int V_15 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_11 ( & V_16 ) ;
F_1 ( V_15 ) ;
if ( ! ( F_15 ( V_20 ) & V_21 ) ) {
F_9 ( V_21 ,
V_22 ) ;
V_19 = 10 ;
while ( ( F_15 ( V_20 )
& V_21 ) != V_21 ) {
if ( V_19 -- == 0 )
break;
F_16 ( 1 ) ;
}
if ( V_19 == 0 ) {
F_17 ( V_23 L_1 ) ;
F_12 ( & V_16 ) ;
return - V_24 ;
}
}
V_19 = V_25 + ( 1 * V_26 ) ;
while ( F_18 ( V_25 , V_19 ) ) {
F_19 () ;
F_9 ( F_20 ( F_21 ( V_27 ) ) ,
V_28 ) ;
F_22 ( F_23 ( V_15 ) , 1 ) ;
if ( V_2 == - 1 )
break;
F_24 ( 10 ) ;
}
F_12 ( & V_16 ) ;
return V_2 != - 1 ? - V_29 : 0 ;
}
void T_3 F_25 ( void )
{
void T_1 * V_30 = F_6 () ;
unsigned int V_9 , V_31 ;
V_31 = V_30 ? F_26 ( V_30 ) : 1 ;
if ( V_31 > V_32 ) {
F_17 ( V_33
L_2
L_3 ,
V_31 , V_32 ) ;
V_31 = V_32 ;
}
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ )
F_27 ( V_9 , true ) ;
F_28 ( F_22 ) ;
}
void T_3 F_29 ( unsigned int V_34 )
{
F_30 ( F_6 () ) ;
F_9 ( F_20 ( F_21 ( V_27 ) ) , V_35 ) ;
}
