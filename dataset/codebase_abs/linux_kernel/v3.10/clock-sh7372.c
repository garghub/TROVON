static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
if ( F_2 ( V_3 ) & ( 1 << 14 ) )
V_2 = ( ( ( F_2 ( V_1 -> V_4 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
static void F_3 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) - 2 ; V_7 ++ ) {
V_8 [ V_7 ] . V_9 = V_1 -> V_5 -> V_6 * ( V_7 + 20 ) * 2 ;
V_8 [ V_7 ] . V_10 = V_7 ;
}
V_8 [ V_7 ] . V_9 = V_1 -> V_5 -> V_6 ;
V_8 [ V_7 ] . V_10 = V_7 ;
V_8 [ ++ V_7 ] . V_9 = V_11 ;
V_8 [ V_7 ] . V_10 = V_7 ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
F_3 ( V_1 ) ;
if ( F_2 ( V_12 ) & ( 1 << 31 ) )
V_2 = ( ( ( F_2 ( V_12 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
static long F_6 ( struct V_1 * V_1 , unsigned long V_6 )
{
return F_7 ( V_1 , V_1 -> V_13 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_7 ;
F_9 ( F_2 ( V_12 ) | 0x80000000 , V_12 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ )
if ( F_2 ( V_12 ) & 0x80000000 ) {
V_1 -> V_6 = F_5 ( V_1 ) ;
return 0 ;
}
F_10 ( L_1 , V_14 ) ;
return - V_15 ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_9 ( F_2 ( V_12 ) & ~ 0x80000000 , V_12 ) ;
}
static int F_12 ( struct V_1 * V_1 , unsigned long V_6 )
{
unsigned long V_16 ;
int V_17 ;
V_17 = F_13 ( V_1 , V_1 -> V_13 , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_6 == V_1 -> V_5 -> V_6 )
return - V_18 ;
V_16 = F_2 ( V_12 ) & ~ ( 0x3f << 24 ) ;
F_9 ( V_16 | ( ( V_17 + 19 ) << 24 ) , V_12 ) ;
V_1 -> V_6 = V_1 -> V_13 [ V_17 ] . V_9 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , struct V_1 * V_5 )
{
T_1 V_16 ;
int V_19 , V_7 ;
if ( ! V_1 -> V_20 || ! V_1 -> V_21 )
return - V_18 ;
for ( V_7 = 0 ; V_7 < V_1 -> V_21 ; V_7 ++ )
if ( V_1 -> V_20 [ V_7 ] == V_5 )
break;
if ( V_7 == V_1 -> V_21 )
return - V_22 ;
V_19 = F_15 ( V_1 , V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
V_16 = F_2 ( V_12 ) & ~ ( 3 << 6 ) ;
F_9 ( V_16 | ( V_7 << 6 ) , V_12 ) ;
F_3 ( V_1 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
V_16 = F_2 ( V_23 ) ;
V_16 |= ( 1 << 31 ) ;
F_9 ( V_16 , V_23 ) ;
}
void T_2 F_17 ( void )
{
int V_24 , V_19 = 0 ;
F_9 ( 0xe4ef8087 , V_25 ) ;
F_9 ( 0xffffffff , V_26 ) ;
F_9 ( 0x37c7f7ff , V_27 ) ;
F_9 ( 0xffffffff , V_28 ) ;
F_9 ( 0xffe0fffd , V_29 ) ;
for ( V_24 = 0 ; ! V_19 && ( V_24 < F_4 ( V_30 ) ) ; V_24 ++ )
V_19 = F_18 ( V_30 [ V_24 ] ) ;
if ( ! V_19 )
V_19 = F_19 ( V_31 , V_32 , & V_33 ) ;
if ( ! V_19 )
V_19 = F_20 ( V_34 , V_35 ) ;
if ( ! V_19 )
V_19 = F_21 ( V_36 , V_37 ) ;
if ( ! V_19 )
V_19 = F_22 ( V_38 , V_39 ) ;
if ( ! V_19 )
V_19 = F_23 ( V_40 , V_41 ) ;
F_24 ( V_42 , F_4 ( V_42 ) ) ;
if ( ! V_19 )
F_25 () ;
else
F_26 ( L_2 ) ;
}
