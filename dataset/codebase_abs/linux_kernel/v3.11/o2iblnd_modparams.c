void
F_1 ( char * V_1 , char * V_2 , int V_3 )
{
strncpy ( V_1 , V_2 , V_3 ) ;
V_1 [ V_3 - 1 ] = 0 ;
}
void
F_2 ( void )
{
F_1 ( V_4 , V_5 ,
sizeof( V_4 ) ) ;
V_6 . V_7 =
F_3 ( V_8 , 0 ) ;
if ( V_6 . V_7 == NULL )
F_4 ( L_1 ) ;
}
void
F_5 ( void )
{
if ( V_6 . V_7 != NULL )
F_6 ( V_6 . V_7 ) ;
}
void
F_2 ( void )
{
}
void
F_5 ( void )
{
}
int
F_7 ( void )
{
if ( F_8 ( * V_6 . V_9 ) < 0 ) {
F_9 ( L_2 ,
* V_6 . V_9 ) ;
return - V_10 ;
}
if ( * V_6 . V_11 < V_12 )
* V_6 . V_11 = V_12 ;
if ( * V_6 . V_11 > V_13 )
* V_6 . V_11 = V_13 ;
if ( * V_6 . V_11 > * V_6 . V_14 )
* V_6 . V_11 = * V_6 . V_14 ;
if ( * V_6 . V_15 < * V_6 . V_11 / 2 )
* V_6 . V_15 = * V_6 . V_11 / 2 ;
if ( * V_6 . V_15 >= * V_6 . V_11 )
* V_6 . V_15 = * V_6 . V_11 - 1 ;
if ( * V_6 . V_16 < 0 ||
* V_6 . V_16 > V_17 )
* V_6 . V_16 = 0 ;
if ( * V_6 . V_16 == 1 )
* V_6 . V_16 = 2 ;
if ( * V_6 . V_18 == 0 ) {
if ( * V_6 . V_16 > 0 &&
* V_6 . V_16 <= V_17 / 8 )
* V_6 . V_18 = ( * V_6 . V_11 ) * 2 ;
else
* V_6 . V_18 = ( * V_6 . V_11 ) ;
}
if ( * V_6 . V_18 > * V_6 . V_11 * 2 )
* V_6 . V_18 = * V_6 . V_11 * 2 ;
if ( * V_6 . V_18 < * V_6 . V_11 / 2 )
* V_6 . V_18 = * V_6 . V_11 / 2 ;
if ( * V_6 . V_18 < * V_6 . V_11 ) {
F_4 ( L_3
L_4 ,
* V_6 . V_18 , * V_6 . V_11 ) ;
}
F_2 () ;
return 0 ;
}
void
F_10 ( void )
{
F_5 () ;
}
