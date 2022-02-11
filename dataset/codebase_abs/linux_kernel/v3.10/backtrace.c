static unsigned int F_1 ( unsigned int V_1 , int V_2 )
{
unsigned int V_3 [ 2 ] ;
void T_1 * V_4 = F_2 ( V_1 ) ;
if ( ! F_3 ( V_5 , V_4 , sizeof( V_3 ) ) )
return 0 ;
if ( F_4 ( V_3 , V_4 , sizeof( V_3 ) ) )
return 0 ;
if ( ! V_2 )
F_5 ( F_6 ( V_3 ) ) ;
return F_7 ( V_3 ) ;
}
static unsigned long F_8 ( unsigned long V_1 , int V_2 )
{
unsigned long V_3 [ 3 ] ;
if ( ! F_3 ( V_5 , ( void T_1 * ) V_1 , sizeof( V_3 ) ) )
return 0 ;
if ( F_4 ( V_3 , ( void T_1 * ) V_1 ,
sizeof( V_3 ) ) )
return 0 ;
if ( ! V_2 )
F_5 ( F_9 ( V_3 ) ) ;
return F_7 ( V_3 ) ;
}
static unsigned long F_10 ( unsigned long V_1 , int V_2 )
{
unsigned long * V_3 = ( unsigned long * ) V_1 ;
if ( ! F_11 ( V_1 , V_6 , V_7 ) )
return 0 ;
if ( ! V_2 )
F_5 ( F_12 ( V_3 ) ) ;
return F_7 ( V_3 ) ;
}
void F_13 ( struct V_8 * const V_9 , unsigned int V_10 )
{
unsigned long V_1 = V_9 -> V_11 [ 1 ] ;
int V_12 = 1 ;
V_10 += 1 ;
if ( ! F_14 ( V_9 ) ) {
while ( V_10 -- ) {
V_1 = F_10 ( V_1 , V_12 ) ;
if ( ! V_1 )
break;
V_12 = 0 ;
}
} else {
#ifdef F_15
if ( ! F_16 () ) {
while ( V_10 -- ) {
V_1 = F_8 ( V_1 , V_12 ) ;
if ( ! V_1 )
break;
V_12 = 0 ;
}
return;
}
#endif
while ( V_10 -- ) {
V_1 = F_1 ( V_1 , V_12 ) ;
if ( ! V_1 )
break;
V_12 = 0 ;
}
}
}
