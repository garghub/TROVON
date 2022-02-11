static int F_1 ( void )
{
struct V_1 V_2 = {
. type = V_3 ,
. V_4 = V_5 ,
. V_6 = 1 ,
} ;
int V_7 ;
int V_8 ;
int V_9 ;
T_1 V_10 = - 1 ;
char V_11 [ V_12 ] ;
V_9 = F_2 () ;
if ( V_9 < 0 )
V_9 = 0 ;
while ( 1 ) {
V_7 = F_3 ( & V_2 , V_10 , V_9 , - 1 ,
V_13 ) ;
if ( V_7 < 0 && V_10 == - 1 && V_14 == V_15 ) {
V_10 = 0 ;
continue;
}
break;
}
V_8 = V_14 ;
if ( V_7 >= 0 ) {
F_4 ( V_7 ) ;
return 1 ;
}
F_5 ( V_8 != V_16 && V_8 != V_17 ,
L_1 ,
V_8 , F_6 ( V_8 , V_11 , sizeof( V_11 ) ) ) ;
while ( 1 ) {
V_7 = F_3 ( & V_2 , V_10 , V_9 , - 1 , 0 ) ;
if ( V_7 < 0 && V_10 == - 1 && V_14 == V_15 ) {
V_10 = 0 ;
continue;
}
break;
}
V_8 = V_14 ;
if ( V_7 >= 0 )
F_4 ( V_7 ) ;
if ( F_5 ( V_7 < 0 && V_8 != V_17 ,
L_2 ,
V_8 , F_6 ( V_8 , V_11 , sizeof( V_11 ) ) ) )
return - 1 ;
return 0 ;
}
unsigned long F_7 ( void )
{
static bool V_18 ;
if ( ! V_18 ) {
if ( F_1 () <= 0 )
V_19 = 0 ;
V_18 = true ;
}
return V_19 ;
}
