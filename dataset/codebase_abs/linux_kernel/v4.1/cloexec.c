int __weak F_1 ( void )
{
V_1 = V_2 ;
return - 1 ;
}
static int F_2 ( void )
{
struct V_3 V_4 = {
. type = V_5 ,
. V_6 = V_7 ,
. V_8 = 1 ,
} ;
int V_9 ;
int V_10 ;
int V_11 ;
T_1 V_12 = - 1 ;
char V_13 [ V_14 ] ;
V_11 = F_1 () ;
if ( V_11 < 0 )
V_11 = 0 ;
while ( 1 ) {
V_9 = F_3 ( & V_4 , V_12 , V_11 , - 1 ,
V_15 ) ;
if ( V_9 < 0 && V_12 == - 1 && V_1 == V_16 ) {
V_12 = 0 ;
continue;
}
break;
}
V_10 = V_1 ;
if ( V_9 >= 0 ) {
F_4 ( V_9 ) ;
return 1 ;
}
F_5 ( V_10 != V_17 && V_10 != V_18 ,
L_1 ,
V_10 , F_6 ( V_10 , V_13 , sizeof( V_13 ) ) ) ;
while ( 1 ) {
V_9 = F_3 ( & V_4 , V_12 , V_11 , - 1 , 0 ) ;
if ( V_9 < 0 && V_12 == - 1 && V_1 == V_16 ) {
V_12 = 0 ;
continue;
}
break;
}
V_10 = V_1 ;
if ( V_9 >= 0 )
F_4 ( V_9 ) ;
if ( F_5 ( V_9 < 0 && V_10 != V_18 ,
L_2 ,
V_10 , F_6 ( V_10 , V_13 , sizeof( V_13 ) ) ) )
return - 1 ;
return 0 ;
}
unsigned long F_7 ( void )
{
static bool V_19 ;
if ( ! V_19 ) {
if ( F_2 () <= 0 )
V_20 = 0 ;
V_19 = true ;
}
return V_20 ;
}
