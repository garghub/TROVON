void F_1 ( unsigned int V_1 , T_1 V_2 )
{
F_2 ( V_1 < V_3 ) ;
V_4 [ V_1 ] -> V_5 = V_2 ;
F_3 () ;
}
T_1 F_4 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return V_4 [ V_1 ] -> V_5 ;
}
void F_5 ( unsigned int V_1 , T_1 V_6 )
{
F_2 ( V_1 < V_3 ) ;
V_4 [ V_1 ] -> V_6 = V_6 ;
F_3 () ;
}
T_1 F_6 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return V_4 [ V_1 ] -> V_6 ;
}
T_1 F_7 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return V_4 [ V_1 ] -> V_7 ;
}
T_1 F_8 ( unsigned int V_8 )
{
F_2 ( V_8 < V_9 ) ;
return V_10 [ V_8 ] -> V_11 ;
}
void F_9 ( unsigned int V_8 , T_1 V_2 )
{
F_2 ( V_8 < V_9 ) ;
V_10 [ V_8 ] -> V_11 = V_2 ;
F_3 () ;
}
int F_10 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return ! ! ( V_10 [ F_11 ( V_1 ) ] -> V_11 & V_12 [ V_1 ] ) ;
}
void F_12 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
V_10 [ F_11 ( V_1 ) ] -> V_11 = V_12 [ V_1 ] ;
}
int F_13 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return ! ! ( V_10 [ F_11 ( V_1 ) ] -> V_11 & V_13 [ V_1 ] ) ;
}
void F_14 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
V_10 [ F_11 ( V_1 ) ] -> V_11 = V_13 [ V_1 ] ;
}
int F_15 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return ! ! ( V_10 [ F_11 ( V_1 ) ] -> V_11 & V_14 [ V_1 ] ) ;
}
void F_16 ( unsigned int V_1 , T_2 V_15 )
{
F_2 ( V_1 < V_3 ) ;
V_4 [ V_1 ] -> V_15 = V_15 ;
F_3 () ;
}
T_2 F_17 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
return V_4 [ V_1 ] -> V_15 ;
}
void F_18 ( T_2 V_16 )
{
int V_17 ;
F_2 ( ( V_16 & ~ V_18 ) == 0 ) ;
for ( V_17 = 0 ; V_17 < V_9 ; ++ V_17 ) {
V_10 [ V_17 ] -> V_19 = V_16 & 0xFF ;
V_16 >>= 8 ;
}
F_3 () ;
}
static void F_19 ( T_2 V_16 )
{
int V_17 ;
T_2 V_20 = V_16 ;
F_2 ( ( V_16 & ~ V_18 ) == 0 ) ;
for ( V_17 = 0 ; V_17 < V_9 ; ++ V_17 ) {
V_10 [ V_17 ] -> V_21 = V_20 & 0xFF ;
V_20 >>= 8 ;
}
}
void F_20 ( T_2 V_16 )
{
int V_17 ;
F_19 ( V_16 ) ;
for ( V_17 = 0 ; V_17 < V_3 ; ++ V_17 )
if ( V_16 & ( 1 << V_17 ) )
V_10 [ F_11 ( V_17 ) ] -> V_11 = V_14 [ V_17 ] ;
F_3 () ;
}
void F_21 ( T_2 V_16 )
{
F_19 ( V_16 ) ;
F_3 () ;
}
void F_22 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
V_4 [ V_1 ] -> V_15 |= V_22 ;
F_3 () ;
}
void F_23 ( unsigned int V_1 )
{
F_2 ( V_1 < V_3 ) ;
V_4 [ V_1 ] -> V_15 &= ~ V_22 ;
F_3 () ;
}
T_2 F_24 ( void )
{
int V_17 ;
T_2 V_23 = 0 ;
for ( V_17 = 0 ; V_17 < V_9 ; ++ V_17 )
V_23 |= ( V_10 [ V_17 ] -> V_19 << ( V_17 << 3 ) ) ;
return V_23 ;
}
