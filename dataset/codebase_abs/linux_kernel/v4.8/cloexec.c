int __weak F_1 ( void )
{
#ifdef F_2
unsigned V_1 ;
int V_2 = F_3 ( F_2 , & V_1 , NULL , NULL ) ;
if ( ! V_2 )
return V_1 ;
#else
V_3 = V_4 ;
#endif
return - 1 ;
}
static int F_4 ( void )
{
struct V_5 V_6 = {
. type = V_7 ,
. V_8 = V_9 ,
. V_10 = 1 ,
} ;
int V_11 ;
int V_2 ;
int V_1 ;
T_1 V_12 = - 1 ;
char V_13 [ V_14 ] ;
V_1 = F_1 () ;
if ( V_1 < 0 )
V_1 = 0 ;
while ( 1 ) {
V_11 = F_5 ( & V_6 , V_12 , V_1 , - 1 ,
V_15 ) ;
if ( V_11 < 0 && V_12 == - 1 && V_3 == V_16 ) {
V_12 = 0 ;
continue;
}
break;
}
V_2 = V_3 ;
if ( V_11 >= 0 ) {
F_6 ( V_11 ) ;
return 1 ;
}
F_7 ( V_2 != V_17 && V_2 != V_18 ,
L_1 ,
V_2 , F_8 ( V_2 , V_13 , sizeof( V_13 ) ) ) ;
while ( 1 ) {
V_11 = F_5 ( & V_6 , V_12 , V_1 , - 1 , 0 ) ;
if ( V_11 < 0 && V_12 == - 1 && V_3 == V_16 ) {
V_12 = 0 ;
continue;
}
break;
}
V_2 = V_3 ;
if ( V_11 >= 0 )
F_6 ( V_11 ) ;
if ( F_7 ( V_11 < 0 && V_2 != V_18 ,
L_2 ,
V_2 , F_8 ( V_2 , V_13 , sizeof( V_13 ) ) ) )
return - 1 ;
return 0 ;
}
unsigned long F_9 ( void )
{
static bool V_19 ;
if ( ! V_19 ) {
if ( F_4 () <= 0 )
V_20 = 0 ;
V_19 = true ;
}
return V_20 ;
}
