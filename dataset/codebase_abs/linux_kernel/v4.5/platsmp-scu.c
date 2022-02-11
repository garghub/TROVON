static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
unsigned int V_5 = ( long ) V_4 ;
switch ( V_3 ) {
case V_6 :
F_2 ( V_5 , F_3 ( V_7 ) ,
( unsigned long ) V_8 ) ;
break;
} ;
return V_9 ;
}
void T_1 F_4 ( unsigned int V_10 )
{
V_11 = F_3 ( V_12 ) ;
F_5 ( V_8 ) ;
F_6 ( V_8 , V_13 ) ;
F_7 ( & V_14 ) ;
}
void F_8 ( unsigned int V_5 )
{
F_2 ( V_5 , 0 , 0 ) ;
F_9 () ;
F_10 () ;
F_6 ( V_8 , V_15 ) ;
F_11 () ;
}
static int F_12 ( int V_5 )
{
unsigned long V_16 = V_15 << ( V_5 * 8 ) ;
if ( ( F_13 ( V_8 + 8 ) & V_16 ) == V_16 )
return 1 ;
return 0 ;
}
int F_14 ( unsigned int V_5 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 1000 ; V_17 ++ ) {
if ( F_12 ( V_5 ) )
return 1 ;
F_15 ( 1 ) ;
}
return 0 ;
}
