int F_1 ( void )
{
if ( ! V_1 . V_2 )
return - 1 ;
return V_1 . V_2 () ;
}
void F_2 ( unsigned int V_3 )
{
if ( V_1 . V_4 )
V_1 . V_4 ( V_3 ) ;
}
static int T_1 F_3 ( char * V_5 )
{
int V_6 , V_7 , V_8 ;
for ( V_6 = 0 ; V_6 < 6 && * V_5 ; V_6 ++ , V_5 += 3 ) {
if ( ! isxdigit ( V_5 [ 0 ] ) || ! isxdigit ( V_5 [ 1 ] ) )
return 0 ;
if ( V_5 [ 2 ] != ( ( V_6 < 5 ) ? ':' : '\0' ) )
return 0 ;
for ( V_7 = 0 , V_8 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_8 = V_8 << 4 ;
V_8 |= isdigit ( V_5 [ V_7 ] ) ?
V_5 [ V_7 ] - '0' : toupper ( V_5 [ V_7 ] ) - 'A' + 10 ;
}
V_9 [ V_6 ] = V_8 ;
}
return 1 ;
}
int F_4 ( unsigned int V_10 , T_2 * V_11 )
{
int V_7 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ ) {
if ( V_9 [ V_7 ] )
V_13 = 1 ;
if ( V_15 [ V_7 ] )
V_14 = 1 ;
if ( V_11 [ V_7 ] )
V_12 = 1 ;
}
if ( V_13 )
memcpy ( V_11 , V_9 , 6 ) ;
else if ( ! V_12 ) {
if ( V_14 )
memcpy ( V_11 , V_15 , 6 ) ;
else
F_5 ( V_11 ) ;
}
V_11 [ 5 ] += V_10 * V_16 ;
return 1 ;
}
