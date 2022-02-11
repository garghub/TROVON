static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = ( unsigned int ) ( long ) V_2 ;
unsigned int V_4 = F_2 () ;
unsigned int V_5 = 4 * V_4 ;
unsigned int V_6 ;
V_6 = F_3 ( 0xfe410070 + V_5 ) ;
V_6 &= ( 1 << ( V_3 << 2 ) ) ;
F_4 ( V_6 , 0xfe410080 + V_5 ) ;
F_5 ( V_3 ) ;
return V_7 ;
}
static void F_6 ( void )
{
unsigned int V_4 = 0 ;
int V_8 , V_9 ;
F_7 ( F_8 ( V_4 ) ) ;
F_4 ( F_3 ( F_9 ( V_4 ) ) | V_10 , F_9 ( V_4 ) ) ;
V_11 [ 0 ] = 0 ;
V_12 [ 0 ] = 0 ;
for ( V_8 = 1 , V_9 = 0 ; V_8 < V_13 ; V_8 ++ ) {
F_10 ( V_8 , true ) ;
V_11 [ V_8 ] = ++ V_9 ;
V_12 [ V_9 ] = V_8 ;
}
F_11 ( V_14 L_1 , V_9 ) ;
}
static void F_12 ( unsigned int V_15 )
{
int V_8 ;
F_13 ( 0 ) ;
F_14 ( V_16 >= 8 ) ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ )
F_15 ( 104 + V_8 , F_1 ,
V_17 , L_2 , ( void * ) ( long ) V_8 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ )
F_16 ( V_8 , true ) ;
}
static void F_17 ( unsigned int V_4 , unsigned long V_18 )
{
if ( F_18 () )
F_4 ( V_18 , F_19 ( V_4 ) ) ;
else
F_4 ( F_20 ( V_18 ) , F_19 ( V_4 ) ) ;
if ( ! ( F_3 ( F_9 ( V_4 ) ) & V_19 ) )
F_4 ( V_19 , F_9 ( V_4 ) ) ;
while ( ! ( F_3 ( F_9 ( V_4 ) ) & V_19 ) )
F_21 () ;
F_4 ( V_20 | V_10 , F_9 ( V_4 ) ) ;
}
static unsigned int F_22 ( void )
{
return F_3 ( 0xff000048 ) ;
}
static void F_23 ( unsigned int V_4 , unsigned int V_3 )
{
unsigned long V_21 = 0xfe410070 + ( V_4 * 4 ) ;
F_24 ( V_4 >= 4 ) ;
F_4 ( 1 << ( V_3 << 2 ) , V_21 ) ;
}
static void F_25 ( unsigned int V_4 )
{
F_4 ( V_19 , F_9 ( V_4 ) ) ;
while ( ! ( F_3 ( F_9 ( V_4 ) ) & V_19 ) )
F_21 () ;
F_4 ( V_20 , F_9 ( V_4 ) ) ;
}
static int T_2
F_26 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
unsigned int V_4 = ( unsigned int ) V_25 ;
switch ( V_24 ) {
case V_26 :
F_25 ( V_4 ) ;
break;
case V_27 :
F_27 ( L_3 , V_4 ) ;
break;
case V_28 :
break;
}
return V_29 ;
}
static int T_2 F_28 ( void )
{
F_29 ( & V_30 ) ;
return 0 ;
}
