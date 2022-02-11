void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_6 ) ;
}
void F_3 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_7 ) ;
}
void F_4 ( bool V_8 )
{
F_2 ( V_8 , V_5 + V_9 ) ;
}
void F_5 ( bool V_10 )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
if ( V_10 )
F_4 ( V_10 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ V_16 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
}
void F_7 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
F_4 ( false ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int V_19 )
{
unsigned int V_20 = V_18 -> V_21 / 32 - 1 ;
T_1 V_22 ;
if ( V_18 -> V_21 < 32 )
return - V_23 ;
V_22 = 1 << V_18 -> V_21 % 32 ;
V_16 [ V_20 ] = V_19 ? V_16 [ V_20 ] | V_22 :
V_16 [ V_20 ] & ~ V_22 ;
return 0 ;
}
void F_9 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ 0 , V_11 + V_13 * 4 ) ;
}
}
void F_10 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
void F_11 ( unsigned int V_21 )
{
void T_2 * V_24 ;
T_1 V_25 ;
V_24 = V_5 + V_12 + ( V_21 / 32 - 1 ) * 4 ;
V_25 = F_6 ( V_24 ) ;
V_25 &= ~ ( 1 << V_21 % 32 ) ;
F_2 ( V_25 , V_24 ) ;
}
void F_12 ( unsigned int V_21 )
{
void T_2 * V_24 ;
T_1 V_25 ;
V_24 = V_5 + V_12 + ( V_21 / 32 - 1 ) * 4 ;
V_25 = F_6 ( V_24 ) ;
V_25 |= 1 << ( V_21 % 32 ) ;
F_2 ( V_25 , V_24 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
if ( V_18 -> V_21 < 32 )
return;
F_11 ( V_18 -> V_21 ) ;
}
static void F_14 ( struct V_17 * V_18 )
{
if ( V_18 -> V_21 < 32 )
return;
F_12 ( V_18 -> V_21 ) ;
}
void T_3 F_15 ( void )
{
struct V_26 * V_27 ;
int V_13 ;
V_27 = F_16 ( NULL , NULL , L_1 ) ;
V_5 = F_17 ( V_27 , 0 ) ;
F_18 ( ! V_5 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( ~ 0 , V_5 + V_12 + V_13 * 4 ) ;
V_28 . V_29 = F_14 ;
V_28 . V_30 = F_13 ;
V_28 . V_31 = F_8 ;
}
