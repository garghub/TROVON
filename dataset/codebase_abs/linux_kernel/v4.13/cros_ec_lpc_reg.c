static T_1 F_1 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_3 )
{
int V_4 ;
int V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 ; ++ V_4 ) {
V_3 [ V_4 ] = F_2 ( V_1 + V_4 ) ;
V_5 += V_3 [ V_4 ] ;
}
return V_5 ;
}
static T_1 F_3 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_6 )
{
int V_4 ;
int V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 ; ++ V_4 ) {
F_4 ( V_6 [ V_4 ] , V_1 + V_4 ) ;
V_5 += V_6 [ V_4 ] ;
}
return V_5 ;
}
T_1 F_5 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_3 )
{
if ( V_2 == 0 )
return 0 ;
if ( V_1 >= V_7 && V_1 <= V_8 ) {
if ( F_6 ( V_1 + V_2 - 1 > V_8 ) )
return 0 ;
return F_7 ( V_9 , V_1 , V_2 ,
V_3 ) ;
}
if ( F_6 ( V_1 + V_2 > V_7 &&
V_1 < V_7 ) )
return 0 ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
T_1 F_8 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_6 )
{
if ( V_2 == 0 )
return 0 ;
if ( V_1 >= V_7 && V_1 <= V_8 ) {
if ( F_6 ( V_1 + V_2 - 1 > V_8 ) )
return 0 ;
return F_7 ( V_10 , V_1 , V_2 ,
V_6 ) ;
}
if ( F_6 ( V_1 + V_2 > V_7 &&
V_1 < V_7 ) )
return 0 ;
return F_3 ( V_1 , V_2 , V_6 ) ;
}
void F_9 ( void )
{
F_10 () ;
}
void F_11 ( void )
{
F_12 () ;
}
T_1 F_5 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
T_1 F_8 ( unsigned int V_1 , unsigned int V_2 , T_1 * V_6 )
{
return F_3 ( V_1 , V_2 , V_6 ) ;
}
void F_9 ( void )
{
}
void F_11 ( void )
{
}
