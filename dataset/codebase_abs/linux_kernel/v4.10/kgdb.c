char * F_1 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
if ( V_1 >= V_5 || V_1 < 0 )
return NULL ;
if ( V_6 [ V_1 ] . V_7 != - 1 )
memcpy ( V_2 , ( void * ) V_4 + V_6 [ V_1 ] . V_7 ,
V_6 [ V_1 ] . V_8 ) ;
else
memset ( V_2 , 0 , V_6 [ V_1 ] . V_8 ) ;
return V_6 [ V_1 ] . V_9 ;
}
int F_2 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
if ( V_1 >= V_5 || V_1 < 0 )
return - V_10 ;
if ( V_6 [ V_1 ] . V_7 != - 1 )
memcpy ( ( void * ) V_4 + V_6 [ V_1 ] . V_7 , V_2 ,
V_6 [ V_1 ] . V_8 ) ;
return 0 ;
}
void F_3 ( unsigned long * V_11 , struct V_12 * V_13 )
{
memset ( ( char * ) V_11 , 0 , V_14 ) ;
V_11 [ V_15 ] = V_13 -> V_16 . V_17 -> V_18 ;
V_11 [ V_19 ] = V_13 -> V_16 . V_17 -> V_20 ;
}
void F_4 ( struct V_3 * V_4 , unsigned long V_21 )
{
V_4 -> V_20 = V_21 ;
}
int F_5 ( int V_22 , int V_23 , int V_24 ,
char * V_25 , char * V_26 ,
struct V_3 * V_4 )
{
char * V_27 ;
unsigned long V_28 ;
switch ( V_25 [ 0 ] ) {
case 's' :
case 'c' :
V_27 = & V_25 [ 1 ] ;
if ( F_6 ( & V_27 , & V_28 ) )
V_4 -> V_20 = V_28 ;
return 0 ;
}
return - 1 ;
}
T_1 void F_7 ( struct V_3 * V_4 )
{
if ( ! V_29 )
V_4 -> V_20 -= 4 ;
else
V_29 = 0 ;
F_8 ( 30 , V_30 , 0 , V_4 ) ;
}
int F_9 ( void )
{
V_29 = 1 ;
return 0 ;
}
void F_10 ( void )
{
}
