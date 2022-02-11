void F_1 ( void )
{
void T_1 * V_1 = V_2 + V_3 ;
int V_4 ;
F_2 ( 0x1 , V_2 + V_5 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_7 [ V_4 ] = F_3 ( V_1 + V_4 * 4 ) ;
F_2 ( ~ V_8 [ V_4 ] , V_1 + V_4 * 4 ) ;
}
}
void F_4 ( void )
{
void T_1 * V_1 = V_2 + V_3 ;
int V_4 ;
F_2 ( 0x0 , V_2 + V_5 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_2 ( V_7 [ V_4 ] , V_1 + V_4 * 4 ) ;
}
static int F_5 ( struct V_9 * V_10 , unsigned int V_11 )
{
unsigned int V_12 = V_10 -> V_13 / 32 - 1 ;
T_2 V_14 ;
if ( V_10 -> V_13 < 32 )
return - V_15 ;
V_14 = 1 << V_10 -> V_13 % 32 ;
V_8 [ V_12 ] = V_11 ? V_8 [ V_12 ] | V_14 :
V_8 [ V_12 ] & ~ V_14 ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 )
{
void T_1 * V_16 ;
T_2 V_17 ;
if ( V_10 -> V_13 < 32 )
return;
V_16 = V_2 + V_3 + ( V_10 -> V_13 / 32 - 1 ) * 4 ;
V_17 = F_3 ( V_16 ) ;
V_17 &= ~ ( 1 << V_10 -> V_13 % 32 ) ;
F_2 ( V_17 , V_16 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
void T_1 * V_16 ;
T_2 V_17 ;
if ( V_10 -> V_13 < 32 )
return;
V_16 = V_2 + V_3 + ( V_10 -> V_13 / 32 - 1 ) * 4 ;
V_17 = F_3 ( V_16 ) ;
V_17 |= 1 << ( V_10 -> V_13 % 32 ) ;
F_2 ( V_17 , V_16 ) ;
}
void T_3 F_8 ( void )
{
struct V_18 * V_19 ;
int V_4 ;
V_19 = F_9 ( NULL , NULL , L_1 ) ;
V_2 = F_10 ( V_19 , 0 ) ;
F_11 ( ! V_2 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_2 ( ~ 0 , V_2 + V_3 + V_4 * 4 ) ;
V_20 . V_21 = F_7 ;
V_20 . V_22 = F_6 ;
V_20 . V_23 = F_5 ;
}
