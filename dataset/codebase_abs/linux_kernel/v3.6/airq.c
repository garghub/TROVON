static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
if ( ! F_2 ( & V_6 [ V_3 ] [ V_4 ] , NULL , V_2 ) )
return V_4 ;
return - V_7 ;
}
void * F_3 ( T_2 V_8 ,
void * V_9 , T_1 V_3 )
{
struct V_1 * V_2 ;
char V_10 [ 16 ] ;
int V_11 ;
if ( V_3 > V_12 )
return F_4 ( - V_13 ) ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_2 ) {
V_11 = - V_7 ;
goto V_15;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_9 = V_9 ;
V_11 = F_1 ( V_2 , V_3 ) ;
V_15:
snprintf ( V_10 , sizeof( V_10 ) , L_1 , V_11 ) ;
F_6 ( 4 , V_10 ) ;
if ( V_11 < 0 ) {
F_7 ( V_2 ) ;
return F_4 ( V_11 ) ;
} else
return & V_16 [ V_3 ] . V_17 [ V_11 ] ;
}
void F_8 ( void * V_18 , T_1 V_3 )
{
struct V_1 * V_2 ;
char V_10 [ 16 ] ;
int V_4 ;
V_4 = ( int ) ( ( V_19 ) V_18 ) - ( ( V_19 ) & V_16 [ V_3 ] . V_17 [ 0 ] ) ;
snprintf ( V_10 , sizeof( V_10 ) , L_2 , V_4 ) ;
F_6 ( 4 , V_10 ) ;
V_16 [ V_3 ] . V_17 [ V_4 ] = 0 ;
V_2 = F_9 ( & V_6 [ V_3 ] [ V_4 ] , NULL ) ;
F_10 () ;
F_7 ( V_2 ) ;
}
void F_11 ( T_1 V_3 )
{
int V_20 ;
int V_4 ;
unsigned long V_21 ;
struct V_1 * V_2 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_21 = V_16 [ V_3 ] . V_21 [ V_20 ] ;
V_4 = V_20 * V_23 ;
while ( V_21 ) {
if ( V_21 & V_24 ) {
V_2 = V_6 [ V_3 ] [ V_4 ] ;
F_12 () ;
if ( F_13 ( V_2 ) )
V_2 -> V_8 ( & V_16 [ V_3 ] . V_17 [ V_4 ] ,
V_2 -> V_9 ) ;
else
V_16 [ V_3 ] . V_17 [ V_4 ] = 0 ;
}
V_21 <<= 8 ;
V_4 ++ ;
}
}
}
