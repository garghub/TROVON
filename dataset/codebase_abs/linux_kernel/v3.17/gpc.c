void F_1 ( bool V_1 )
{
void T_1 * V_2 = V_3 + V_4 ;
int V_5 ;
if ( V_1 )
F_2 ( 0x1 , V_3 + V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_8 [ V_5 ] = F_3 ( V_2 + V_5 * 4 ) ;
F_2 ( ~ V_9 [ V_5 ] , V_2 + V_5 * 4 ) ;
}
}
void F_4 ( void )
{
void T_1 * V_2 = V_3 + V_4 ;
int V_5 ;
F_2 ( 0x0 , V_3 + V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
F_2 ( V_8 [ V_5 ] , V_2 + V_5 * 4 ) ;
}
static int F_5 ( struct V_10 * V_11 , unsigned int V_12 )
{
unsigned int V_13 = V_11 -> V_14 / 32 - 1 ;
T_2 V_15 ;
if ( V_11 -> V_14 < 32 )
return - V_16 ;
V_15 = 1 << V_11 -> V_14 % 32 ;
V_9 [ V_13 ] = V_12 ? V_9 [ V_13 ] | V_15 :
V_9 [ V_13 ] & ~ V_15 ;
return 0 ;
}
void F_6 ( void )
{
void T_1 * V_2 = V_3 + V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_8 [ V_5 ] = F_3 ( V_2 + V_5 * 4 ) ;
F_2 ( ~ 0 , V_2 + V_5 * 4 ) ;
}
}
void F_7 ( void )
{
void T_1 * V_2 = V_3 + V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
F_2 ( V_8 [ V_5 ] , V_2 + V_5 * 4 ) ;
}
void F_8 ( struct V_10 * V_11 )
{
void T_1 * V_17 ;
T_2 V_18 ;
if ( V_11 -> V_14 < 32 )
return;
V_17 = V_3 + V_4 + ( V_11 -> V_14 / 32 - 1 ) * 4 ;
V_18 = F_3 ( V_17 ) ;
V_18 &= ~ ( 1 << V_11 -> V_14 % 32 ) ;
F_2 ( V_18 , V_17 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
void T_1 * V_17 ;
T_2 V_18 ;
if ( V_11 -> V_14 < 32 )
return;
V_17 = V_3 + V_4 + ( V_11 -> V_14 / 32 - 1 ) * 4 ;
V_18 = F_3 ( V_17 ) ;
V_18 |= 1 << ( V_11 -> V_14 % 32 ) ;
F_2 ( V_18 , V_17 ) ;
}
void T_3 F_10 ( void )
{
struct V_19 * V_20 ;
int V_5 ;
V_20 = F_11 ( NULL , NULL , L_1 ) ;
V_3 = F_12 ( V_20 , 0 ) ;
F_13 ( ! V_3 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
F_2 ( ~ 0 , V_3 + V_4 + V_5 * 4 ) ;
V_21 . V_22 = F_9 ;
V_21 . V_23 = F_8 ;
V_21 . V_24 = F_5 ;
}
