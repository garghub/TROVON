unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_1 - V_3 ;
if ( F_2 ( V_1 > V_2 ) ) {
V_1 = V_2 + V_4 ;
F_3 ( V_2 >= V_5 ) ;
} else {
V_1 = V_2 + ( V_3 - V_6 ) ;
F_3 ( ( V_1 > V_2 ) || ! F_4 ( V_1 ) ) ;
}
return V_1 ;
}
unsigned long F_5 ( unsigned long V_1 )
{
unsigned long V_2 = V_1 - V_3 ;
F_3 ( V_2 >= V_5 ) ;
return V_2 + V_4 ;
}
bool F_6 ( unsigned long V_1 )
{
unsigned long V_2 = V_1 - V_3 ;
if ( F_2 ( V_1 > V_2 ) ) {
V_1 = V_2 + V_4 ;
if ( V_2 >= V_5 )
return false ;
} else {
V_1 = V_2 + ( V_3 - V_6 ) ;
if ( ( V_1 > V_2 ) || ! F_4 ( V_1 ) )
return false ;
}
return F_7 ( V_1 >> V_7 ) ;
}
unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_8 = V_1 - V_6 ;
F_3 ( V_1 < V_6 ) ;
F_3 ( V_9 && F_8 ( ( void * ) V_1 ) ) ;
if ( V_10 ) {
F_3 ( ( V_8 >> V_7 ) > V_10 ) ;
F_9 ( F_10 ( ( void * ) V_1 ) != V_8 ) ;
}
return V_8 ;
}
bool F_6 ( unsigned long V_1 )
{
if ( V_1 < V_6 )
return false ;
if ( V_9 && F_8 ( ( void * ) V_1 ) )
return false ;
if ( V_1 >= V_11 )
return false ;
return F_7 ( ( V_1 - V_6 ) >> V_7 ) ;
}
