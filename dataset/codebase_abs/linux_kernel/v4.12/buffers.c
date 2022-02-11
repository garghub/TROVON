void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] && V_3 [ V_1 ] -> V_4 )
continue;
if ( ( V_5 [ V_1 ] . V_6 ) && ( V_5 [ V_1 ] . V_6 -> V_7 . V_8 ) )
F_2 ( V_5 [ V_1 ] . V_6 -> V_7 . V_8 ) ;
}
}
static void F_3 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
if ( ( V_5 [ V_1 ] . V_6 && ( V_5 [ V_1 ] . V_6 -> V_7 . V_8 ) ) )
F_4 ( V_5 [ V_1 ] . V_6 -> V_7 . V_8 ) ;
}
static int F_5 ( void )
{
int V_9 ;
if ( V_10 >= V_11 )
V_9 = V_12 - ( V_10 - V_11 ) ;
else
V_9 = V_11 - V_10 ;
return V_9 ;
}
int F_6 ( void )
{
return ( V_10 == V_11 ) ;
}
void F_7 ( T_1 V_13 )
{
if ( ! V_14 -> V_15 ) {
return;
}
if ( F_5 () <= 100 ) {
F_8 () ;
F_3 () ;
}
if ( F_5 () <= 1 )
return;
* V_10 ++ = V_13 ;
if ( V_10 > V_16 )
V_10 = V_17 ;
}
T_1 F_9 ( void )
{
T_1 V_13 ;
if ( V_11 == V_10 )
return 0 ;
V_13 = * V_11 ++ ;
if ( V_11 > V_16 )
V_11 = V_17 ;
return V_13 ;
}
T_1 F_10 ( void )
{
if ( V_11 == V_10 )
return 0 ;
return * V_11 ;
}
void F_11 ( void )
{
while ( V_11 != V_10 ) {
if ( * V_11 < 0x100 )
return;
V_11 ++ ;
if ( V_11 > V_16 )
V_11 = V_17 ;
}
}
void F_12 ( void )
{
V_10 = V_17 ;
V_11 = V_17 ;
}
