static int F_1 ( const char * V_1 )
{
unsigned long args [ 5 ] ;
args [ 0 ] = ( unsigned long ) L_1 ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) V_1 ;
args [ 4 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
if ( args [ 4 ] )
return 0 ;
return 1 ;
}
void F_3 ( void )
{
const char * V_2 = L_2 ;
unsigned long args [ 3 ] ;
if ( ! F_1 ( V_2 ) )
return;
args [ 0 ] = ( unsigned long ) V_2 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
}
void F_4 ( const char * V_3 )
{
unsigned long args [ 4 ] ;
#ifdef F_5
if ( V_4 )
F_6 ( V_3 ) ;
#endif
args [ 0 ] = ( unsigned long ) L_3 ;
args [ 1 ] = 1 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned long ) V_3 ;
F_2 ( args ) ;
}
void F_7 ( const char * V_5 )
{
unsigned long args [ 5 ] ;
if ( ! V_5 || V_5 [ 0 ] == 0 )
return;
args [ 0 ] = ( unsigned long ) L_4 ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) V_5 ;
args [ 4 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
}
void F_8 ( void )
{
unsigned long args [ 3 ] ;
unsigned long V_6 ;
F_9 ( V_6 ) ;
#ifdef F_10
F_11 () ;
#endif
args [ 0 ] = ( unsigned long ) L_5 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
#ifdef F_10
F_12 () ;
#endif
F_13 ( V_6 ) ;
}
void T_1 F_14 ( void )
{
unsigned long args [ 3 ] ;
#ifdef F_5
if ( V_4 )
F_15 () ;
#endif
V_7:
args [ 0 ] = ( unsigned long ) L_6 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
goto V_7;
}
void F_16 ( void )
{
unsigned long args [ 3 ] ;
#ifdef F_5
if ( V_4 )
F_15 () ;
#endif
args [ 0 ] = ( unsigned long ) L_7 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
F_14 () ;
}
unsigned char F_17 ( char * V_8 , int V_9 )
{
int V_10 ;
V_10 = F_18 ( V_11 , L_8 ) ;
if ( ( V_10 > V_9 ) || ( V_10 == - 1 ) )
return 0xff ;
if ( ! F_19 ( V_11 , L_8 , V_8 , V_9 ) )
return V_8 [ 0 ] ;
return 0xff ;
}
int F_20 ( void )
{
T_2 V_12 ;
int V_13 ;
if ( V_14 != 0 )
return V_14 ;
V_12 = F_21 ( V_15 ) ;
V_13 = F_22 ( V_12 , V_16 ) ;
if ( V_13 == - 1 || V_13 == 0 )
V_14 = - 1 ;
else
V_14 = V_13 ;
return V_13 ;
}
static int F_23 ( void )
{
static int V_17 ;
T_2 V_12 ;
int V_13 ;
if ( V_17 != 0 )
return V_17 ;
V_12 = F_21 ( L_9 ) ;
V_13 = F_22 ( V_12 , L_10 ) ;
if ( V_13 == - 1 || V_13 == 0 )
V_17 = - 1 ;
else
V_17 = V_13 ;
return V_13 ;
}
static long F_24 ( const char * type , unsigned long V_18 ,
unsigned long V_19 , unsigned long V_20 )
{
unsigned long args [ 9 ] ;
args [ 0 ] = ( unsigned long ) V_21 ;
args [ 1 ] = 5 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) type ;
args [ 4 ] = ( unsigned int ) F_20 () ;
args [ 5 ] = V_20 ;
args [ 6 ] = V_19 ;
args [ 7 ] = V_18 ;
args [ 8 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( long ) args [ 8 ] ;
}
long F_25 ( unsigned long V_18 ,
unsigned long V_19 ,
unsigned long V_20 )
{
return F_24 ( L_11 , V_18 , V_19 , V_20 ) ;
}
long F_26 ( unsigned long V_18 ,
unsigned long V_19 ,
unsigned long V_20 )
{
return F_24 ( L_12 , V_18 , V_19 , V_20 ) ;
}
int F_27 ( int V_22 , unsigned long V_23 ,
unsigned long V_20 , unsigned long V_24 )
{
unsigned long args [ 11 ] ;
int V_13 ;
args [ 0 ] = ( unsigned long ) V_21 ;
args [ 1 ] = 7 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) V_25 ;
args [ 4 ] = ( unsigned int ) F_20 () ;
args [ 5 ] = ( unsigned int ) V_22 ;
args [ 6 ] = V_23 ;
args [ 7 ] = V_20 ;
args [ 8 ] = 0 ;
args [ 9 ] = V_24 ;
args [ 10 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
V_13 = ( int ) args [ 10 ] ;
if ( V_13 == 0 )
V_13 = - 1 ;
return V_13 ;
}
void F_28 ( unsigned long V_23 , unsigned long V_20 )
{
unsigned long args [ 7 ] ;
args [ 0 ] = ( unsigned long ) V_21 ;
args [ 1 ] = 4 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned long ) V_26 ;
args [ 4 ] = ( unsigned int ) F_20 () ;
args [ 5 ] = V_23 ;
args [ 6 ] = V_20 ;
F_2 ( args ) ;
}
int F_29 ( const char * V_27 , unsigned long V_23 ,
unsigned long V_28 , unsigned long * V_24 )
{
unsigned long args [ 11 ] ;
args [ 0 ] = ( unsigned long ) V_21 ;
args [ 1 ] = 5 ;
args [ 2 ] = 3 ;
args [ 3 ] = ( unsigned long ) L_13 ;
args [ 4 ] = ( unsigned int ) F_23 () ;
args [ 5 ] = V_28 ;
args [ 6 ] = V_23 ;
args [ 7 ] = ( unsigned long ) V_27 ;
args [ 8 ] = ( unsigned long ) - 1 ;
args [ 9 ] = ( unsigned long ) - 1 ;
args [ 10 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
if ( args [ 8 ] )
return ( int ) args [ 8 ] ;
* V_24 = args [ 10 ] ;
return 0 ;
}
int F_30 ( int V_29 ,
unsigned long V_30 ,
char * V_31 , int V_32 )
{
unsigned long args [ 12 ] ;
args [ 0 ] = ( unsigned long ) V_21 ;
args [ 1 ] = 7 ;
args [ 2 ] = 2 ;
args [ 3 ] = ( unsigned long ) L_14 ;
args [ 4 ] = ( unsigned int ) F_23 () ;
args [ 5 ] = V_32 ;
args [ 6 ] = ( unsigned long ) V_31 ;
args [ 7 ] = 0 ;
args [ 8 ] = V_30 ;
args [ 9 ] = ( unsigned int ) V_29 ;
args [ 10 ] = ( unsigned long ) - 1 ;
args [ 11 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 10 ] ;
}
void F_31 ( void )
{
unsigned long args [ 3 ] ;
args [ 0 ] = ( unsigned long ) L_15 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
}
int F_32 ( void )
{
unsigned long args [ 4 ] ;
args [ 0 ] = ( unsigned long ) L_16 ;
args [ 1 ] = 0 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 3 ] ;
}
int F_33 ( void )
{
unsigned long args [ 4 ] ;
args [ 0 ] = ( unsigned long ) L_17 ;
args [ 1 ] = 0 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
return ( int ) args [ 3 ] ;
}
void F_34 ( int V_33 , unsigned long V_34 , unsigned long V_35 )
{
unsigned long args [ 6 ] ;
args [ 0 ] = ( unsigned long ) L_18 ;
args [ 1 ] = 3 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned int ) V_33 ;
args [ 4 ] = V_34 ;
args [ 5 ] = V_35 ;
F_2 ( args ) ;
}
void F_35 ( int V_36 , unsigned long V_34 , unsigned long V_35 )
{
unsigned long args [ 6 ] ;
args [ 0 ] = ( unsigned long ) L_19 ;
args [ 1 ] = 3 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned int ) V_36 ;
args [ 4 ] = V_34 ;
args [ 5 ] = V_35 ;
F_2 ( args ) ;
}
void F_36 ( int V_36 )
{
unsigned long args [ 4 ] ;
args [ 0 ] = ( unsigned long ) L_20 ;
args [ 1 ] = 1 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned int ) V_36 ;
F_2 ( args ) ;
}
void F_37 ( void )
{
unsigned long args [ 3 ] ;
args [ 0 ] = ( unsigned long ) L_21 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
}
void F_38 ( void )
{
unsigned long args [ 3 ] ;
args [ 0 ] = ( unsigned long ) L_22 ;
args [ 1 ] = 0 ;
args [ 2 ] = 0 ;
F_2 ( args ) ;
}
void F_39 ( int V_33 )
{
unsigned long args [ 4 ] ;
args [ 0 ] = ( unsigned long ) L_23 ;
args [ 1 ] = 1 ;
args [ 2 ] = 0 ;
args [ 3 ] = ( unsigned int ) V_33 ;
F_2 ( args ) ;
}
