static int
F_1 ( struct V_1 * V_2 , char * V_3 )
{
return 0 ;
}
static void
F_2 ( struct V_1 * V_2 , const char * V_4 , unsigned V_5 )
{
unsigned long V_6 ;
while ( V_5 -- > 0 ) {
V_6 = * V_4 ++ ;
F_3 ( V_6 , 0 , 0 , 0 , V_7 ) ;
if ( V_6 == '\n' )
F_3 ( '\r' , 0 , 0 , 0 , V_7 ) ;
}
}
static struct V_8 * F_4 ( struct V_1 * V_9 , int * V_10 )
{
* V_10 = V_9 -> V_10 ;
return V_11 ;
}
int F_5 ( void )
{
if ( ! F_6 ( L_1 ) )
return 1 ;
if ( V_12 . V_13 & V_14 )
return 1 ;
F_7 ( & V_12 ) ;
return 0 ;
}
