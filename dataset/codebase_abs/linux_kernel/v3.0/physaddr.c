unsigned long F_1 ( unsigned long V_1 )
{
if ( V_1 >= V_2 ) {
V_1 -= V_2 ;
F_2 ( V_1 >= V_3 ) ;
V_1 += V_4 ;
} else {
F_2 ( V_1 < V_5 ) ;
V_1 -= V_5 ;
F_2 ( ! F_3 ( V_1 ) ) ;
}
return V_1 ;
}
bool F_4 ( unsigned long V_1 )
{
if ( V_1 >= V_2 ) {
V_1 -= V_2 ;
if ( V_1 >= V_3 )
return false ;
V_1 += V_4 ;
} else {
if ( V_1 < V_5 )
return false ;
V_1 -= V_5 ;
if ( ! F_3 ( V_1 ) )
return false ;
}
return F_5 ( V_1 >> V_6 ) ;
}
unsigned long F_1 ( unsigned long V_1 )
{
F_2 ( V_1 < V_5 ) ;
F_2 ( V_7 && F_6 ( ( void * ) V_1 ) ) ;
return V_1 - V_5 ;
}
bool F_4 ( unsigned long V_1 )
{
if ( V_1 < V_5 )
return false ;
if ( V_7 && F_6 ( ( void * ) V_1 ) )
return false ;
if ( V_1 >= V_8 )
return false ;
return F_5 ( ( V_1 - V_5 ) >> V_6 ) ;
}
