static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned V_3 = F_2 () ;
volatile unsigned * V_4 = & F_3 ( V_5 , V_3 ) ;
unsigned V_6 , V_7 ;
do V_6 = * V_4 ;
while ( F_4 ( V_4 , V_6 , 0 ) != V_6 );
if ( ! V_6 ) return V_8 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ )
if ( V_6 & ( 1U << V_7 ) )
F_5 ( V_7 ) ;
return V_10 ;
}
static void F_6 ( void )
{
}
static void F_7 ( unsigned int V_11 )
{
struct V_12 * V_13 ;
unsigned V_7 , V_14 = 1 ;
V_13 = F_8 ( NULL , NULL , L_1 ) ;
if ( ! V_13 )
goto V_15;
V_16 = F_9 ( V_13 , 0 ) ;
V_17 = F_10 ( V_13 , 0 ) ;
if ( ! V_16 || ! V_17 )
goto V_15;
V_13 = F_8 ( NULL , NULL , L_2 ) ;
if ( ! V_13 )
goto V_15;
V_18 = F_10 ( V_13 , 0 ) ;
if ( ! V_18 )
goto V_15;
if ( F_11 ( V_16 , F_1 , V_19 ,
L_3 , ( void * ) F_1 ) != 0 )
goto V_15;
V_14 = V_11 ;
V_15:
for ( V_7 = V_14 ; V_7 < V_20 ; V_7 ++ ) {
F_12 ( V_7 , false ) ;
F_13 ( V_7 , false ) ;
}
}
static void F_14 ( unsigned int V_3 , unsigned long V_21 )
{
struct V_12 * V_13 ;
T_2 V_22 [ 2 ] ;
void T_3 * V_23 , * V_24 ;
if ( ! V_3 ) return;
V_13 = F_15 ( V_3 , NULL ) ;
if ( ! V_13 ) return;
if ( F_16 ( V_13 , L_4 , V_22 , 2 ) ) return;
V_23 = F_17 ( V_22 [ 0 ] , sizeof( T_2 ) ) ;
V_24 = F_17 ( V_22 [ 1 ] , sizeof( T_2 ) ) ;
F_18 ( V_21 , V_24 ) ;
F_18 ( 1 , V_23 ) ;
F_19 ( V_24 ) ;
F_19 ( V_23 ) ;
F_20 ( L_5 , V_3 ) ;
}
static unsigned int F_21 ( void )
{
return F_22 ( V_18 ) ;
}
static void F_23 ( unsigned int V_3 , unsigned int V_25 )
{
volatile unsigned * V_4 ;
unsigned V_26 ;
unsigned long V_27 ;
V_4 = & F_3 ( V_5 , V_3 ) ;
do V_26 = * V_4 ;
while ( F_4 ( V_4 , V_26 , V_26 | ( 1U << V_25 ) ) != V_26 );
V_27 = F_22 ( V_17 + V_3 ) ;
F_18 ( V_27 | ( 1U << 28 ) , V_17 + V_3 ) ;
}
