static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
unsigned int V_5 = ( long ) V_4 ;
switch ( V_3 ) {
case V_6 :
F_2 ( V_5 , F_3 ( V_7 ) ,
V_8 ) ;
break;
} ;
return V_9 ;
}
void T_1 F_4 ( T_2 V_10 ,
unsigned int V_11 )
{
V_12 = F_3 ( V_13 ) ;
V_8 = V_10 ;
V_14 = F_5 ( V_10 , V_15 ) ;
F_6 ( V_14 ) ;
F_7 ( V_14 , V_16 ) ;
F_8 ( & V_17 ) ;
}
void F_9 ( unsigned int V_5 )
{
F_2 ( V_5 , 0 , 0 ) ;
F_10 () ;
F_11 () ;
F_7 ( V_14 , V_18 ) ;
F_12 () ;
}
static int F_13 ( int V_5 )
{
unsigned long V_19 = V_18 << ( V_5 * 8 ) ;
if ( ( F_14 ( V_14 + 8 ) & V_19 ) == V_19 )
return 1 ;
return 0 ;
}
int F_15 ( unsigned int V_5 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < 1000 ; V_20 ++ ) {
if ( F_13 ( V_5 ) )
return 1 ;
F_16 ( 1 ) ;
}
return 0 ;
}
