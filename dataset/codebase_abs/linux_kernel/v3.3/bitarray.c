int F_1 ( const unsigned long * V_1 , T_1 V_2 ,
T_1 V_3 )
{
T_2 V_4 , V_5 , V_6 ;
V_4 = V_2 - V_3 ;
if ( V_4 < 0 || V_4 >= V_7 ) {
return 0 ;
} else {
V_6 = ( V_2 - V_3 ) / V_8 ;
V_5 = ( V_2 - V_3 ) % V_8 ;
if ( F_2 ( V_5 , & V_1 [ V_6 ] ) )
return 1 ;
else
return 0 ;
}
}
void F_3 ( unsigned long * V_1 , T_2 V_9 )
{
T_2 V_5 , V_6 ;
if ( V_9 < 0 || V_9 >= V_7 )
return;
V_6 = V_9 / V_8 ;
V_5 = V_9 % V_8 ;
F_4 ( V_5 , & V_1 [ V_6 ] ) ;
}
static void F_5 ( unsigned long * V_1 , T_2 V_9 )
{
T_2 V_5 , V_6 ;
T_2 V_10 ;
if ( V_9 <= 0 || V_9 >= V_7 )
return;
V_5 = V_9 % V_8 ;
V_6 = V_9 / V_8 ;
for ( V_10 = V_11 - 1 ; V_10 > V_6 ; V_10 -- ) {
V_1 [ V_10 ] =
( V_1 [ V_10 - V_6 ] << V_5 ) +
( V_1 [ V_10 - V_6 - 1 ] >>
( V_8 - V_5 ) ) ;
}
V_1 [ V_10 ] = ( V_1 [ V_10 - V_6 ] << V_5 ) ;
V_10 -- ;
for (; V_10 >= 0 ; V_10 -- )
V_1 [ V_10 ] = 0 ;
}
static void F_6 ( unsigned long * V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_1 [ V_10 ] = 0 ;
}
int F_7 ( void * V_12 , unsigned long * V_1 ,
T_2 V_13 , int V_14 )
{
struct V_15 * V_15 = V_12 ;
if ( ( V_13 <= 0 ) && ( V_13 > - V_7 ) ) {
if ( V_14 )
F_3 ( V_1 , - V_13 ) ;
return 0 ;
}
if ( ( V_13 > 0 ) && ( V_13 < V_7 ) ) {
F_5 ( V_1 , V_13 ) ;
if ( V_14 )
F_3 ( V_1 , 0 ) ;
return 1 ;
}
if ( ( V_13 >= V_7 )
&& ( V_13 < V_16 ) ) {
F_8 ( V_17 , V_15 ,
L_1 ,
V_13 - 1 ) ;
F_6 ( V_1 ) ;
if ( V_14 )
F_3 ( V_1 , 0 ) ;
return 1 ;
}
if ( ( V_13 <= - V_7 )
|| ( V_13 >= V_16 ) ) {
F_8 ( V_17 , V_15 ,
L_2 ) ;
F_6 ( V_1 ) ;
if ( V_14 )
F_3 ( V_1 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_9 ( const unsigned long * V_1 )
{
int V_10 , V_18 = 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_18 += F_10 ( V_1 [ V_10 ] ) ;
return V_18 ;
}
