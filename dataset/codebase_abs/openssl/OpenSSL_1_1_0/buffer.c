T_1 * F_1 ( unsigned long V_1 )
{
T_1 * V_2 ;
V_2 = F_2 () ;
if ( V_2 != NULL )
V_2 -> V_1 = V_1 ;
return ( V_2 ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_2 ;
V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_4 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
return ( V_2 ) ;
}
void F_5 ( T_1 * V_5 )
{
if ( V_5 == NULL )
return;
if ( V_5 -> V_6 != NULL ) {
if ( V_5 -> V_1 & V_7 )
F_6 ( V_5 -> V_6 ) ;
else
F_7 ( V_5 -> V_6 , V_5 -> V_8 ) ;
}
F_8 ( V_5 ) ;
}
static char * F_9 ( T_1 * V_9 , T_2 V_10 )
{
char * V_2 ;
V_2 = F_10 ( V_10 ) ;
if ( V_9 -> V_6 != NULL ) {
if ( V_2 != NULL )
memcpy ( V_2 , V_9 -> V_6 , V_9 -> V_11 ) ;
F_6 ( V_9 -> V_6 ) ;
}
return ( V_2 ) ;
}
T_2 F_11 ( T_1 * V_9 , T_2 V_10 )
{
char * V_2 ;
T_2 V_12 ;
if ( V_9 -> V_11 >= V_10 ) {
V_9 -> V_11 = V_10 ;
return ( V_10 ) ;
}
if ( V_9 -> V_8 >= V_10 ) {
if ( V_9 -> V_6 != NULL )
memset ( & V_9 -> V_6 [ V_9 -> V_11 ] , 0 , V_10 - V_9 -> V_11 ) ;
V_9 -> V_11 = V_10 ;
return ( V_10 ) ;
}
if ( V_10 > V_13 ) {
F_4 ( V_14 , V_4 ) ;
return 0 ;
}
V_12 = ( V_10 + 3 ) / 3 * 4 ;
if ( ( V_9 -> V_1 & V_7 ) )
V_2 = F_9 ( V_9 , V_12 ) ;
else
V_2 = F_12 ( V_9 -> V_6 , V_12 ) ;
if ( V_2 == NULL ) {
F_4 ( V_14 , V_4 ) ;
V_10 = 0 ;
} else {
V_9 -> V_6 = V_2 ;
V_9 -> V_8 = V_12 ;
memset ( & V_9 -> V_6 [ V_9 -> V_11 ] , 0 , V_10 - V_9 -> V_11 ) ;
V_9 -> V_11 = V_10 ;
}
return ( V_10 ) ;
}
T_2 F_13 ( T_1 * V_9 , T_2 V_10 )
{
char * V_2 ;
T_2 V_12 ;
if ( V_9 -> V_11 >= V_10 ) {
if ( V_9 -> V_6 != NULL )
memset ( & V_9 -> V_6 [ V_10 ] , 0 , V_9 -> V_11 - V_10 ) ;
V_9 -> V_11 = V_10 ;
return ( V_10 ) ;
}
if ( V_9 -> V_8 >= V_10 ) {
memset ( & V_9 -> V_6 [ V_9 -> V_11 ] , 0 , V_10 - V_9 -> V_11 ) ;
V_9 -> V_11 = V_10 ;
return ( V_10 ) ;
}
if ( V_10 > V_13 ) {
F_4 ( V_15 , V_4 ) ;
return 0 ;
}
V_12 = ( V_10 + 3 ) / 3 * 4 ;
if ( ( V_9 -> V_1 & V_7 ) )
V_2 = F_9 ( V_9 , V_12 ) ;
else
V_2 = F_14 ( V_9 -> V_6 , V_9 -> V_8 , V_12 ) ;
if ( V_2 == NULL ) {
F_4 ( V_15 , V_4 ) ;
V_10 = 0 ;
} else {
V_9 -> V_6 = V_2 ;
V_9 -> V_8 = V_12 ;
memset ( & V_9 -> V_6 [ V_9 -> V_11 ] , 0 , V_10 - V_9 -> V_11 ) ;
V_9 -> V_11 = V_10 ;
}
return ( V_10 ) ;
}
void F_15 ( unsigned char * V_16 , const unsigned char * V_17 , T_2 V_18 )
{
T_2 V_19 ;
if ( V_17 ) {
V_16 += V_18 - 1 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
* V_16 -- = * V_17 ++ ;
} else {
unsigned char * V_20 ;
char V_21 ;
V_20 = V_16 + V_18 - 1 ;
for ( V_19 = 0 ; V_19 < V_18 / 2 ; V_19 ++ ) {
V_21 = * V_20 ;
* V_20 -- = * V_16 ;
* V_16 ++ = V_21 ;
}
}
}
