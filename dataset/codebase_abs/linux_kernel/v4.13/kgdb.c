char * F_1 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
if ( V_1 >= V_5 || V_1 < 0 )
return NULL ;
* ( ( unsigned long * ) V_2 ) = * ( ( unsigned long * ) ( ( void * ) V_4 +
V_6 [ V_1 ] . V_7 ) ) ;
return V_6 [ V_1 ] . V_8 ;
}
int F_2 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
if ( V_1 >= V_5 || V_1 < 0 )
return - V_9 ;
* ( ( unsigned long * ) ( ( void * ) V_4 + V_6 [ V_1 ] . V_7 ) ) =
* ( ( unsigned long * ) V_2 ) ;
return 0 ;
}
void F_3 ( struct V_3 * V_4 , unsigned long V_10 )
{
F_4 ( V_4 ) = V_10 ;
}
static void F_5 ( void * V_11 )
{
F_6 ( F_7 () , F_8 () ) ;
}
void F_9 ( unsigned long V_12 )
{
F_10 () ;
F_11 ( F_5 , NULL , 0 ) ;
F_12 () ;
}
void F_13 ( unsigned long * V_13 ,
struct V_14 * V_15 )
{
struct V_3 * V_16 ;
if ( V_15 == NULL )
return;
memset ( V_13 , 0 , V_17 ) ;
V_16 = F_14 ( V_15 ) ;
V_13 [ 0 ] = V_16 -> V_18 ;
}
int F_15 ( int V_19 , int V_20 , int V_21 ,
char * V_22 , char * V_23 ,
struct V_3 * V_24 )
{
switch ( V_22 [ 0 ] ) {
case 's' :
case 'c' :
return 0 ;
}
return - 1 ;
}
static int F_16 ( struct V_25 * args , unsigned long V_26 )
{
if ( F_17 ( & V_27 ) != - 1 ) {
F_6 ( F_18 () , args -> V_4 ) ;
return V_28 ;
}
if ( F_19 ( args -> V_4 ) )
return V_29 ;
if ( F_20 ( args -> V_30 & 0xff , args -> V_31 , args -> V_32 ,
args -> V_4 ) )
return V_29 ;
return V_28 ;
}
static int
F_21 ( struct V_33 * V_34 , unsigned long V_26 , void * V_35 )
{
unsigned long V_12 ;
int V_36 ;
F_22 ( V_12 ) ;
V_36 = F_16 ( V_35 , V_26 ) ;
F_23 ( V_12 ) ;
return V_36 ;
}
int F_24 ( void )
{
return F_25 ( & V_37 ) ;
}
void F_26 ( void )
{
F_27 ( & V_37 ) ;
}
