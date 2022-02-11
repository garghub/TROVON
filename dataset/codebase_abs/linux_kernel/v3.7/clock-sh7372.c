static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 2 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
if ( F_3 ( V_5 ) & ( 1 << 14 ) )
V_4 = ( ( ( F_3 ( V_1 -> V_6 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_2 -> V_3 * V_4 ;
}
static void F_4 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) - 2 ; V_7 ++ ) {
V_8 [ V_7 ] . V_9 = V_1 -> V_2 -> V_3 * ( V_7 + 20 ) * 2 ;
V_8 [ V_7 ] . V_10 = V_7 ;
}
V_8 [ V_7 ] . V_9 = V_1 -> V_2 -> V_3 ;
V_8 [ V_7 ] . V_10 = V_7 ;
V_8 [ ++ V_7 ] . V_9 = V_11 ;
V_8 [ V_7 ] . V_10 = V_7 ;
}
static unsigned long F_6 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
F_4 ( V_1 ) ;
if ( F_3 ( V_12 ) & ( 1 << 31 ) )
V_4 = ( ( ( F_3 ( V_12 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_2 -> V_3 * V_4 ;
}
static long F_7 ( struct V_1 * V_1 , unsigned long V_3 )
{
return F_8 ( V_1 , V_1 -> V_13 , V_3 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_7 ;
F_10 ( F_3 ( V_12 ) | 0x80000000 , V_12 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ )
if ( F_3 ( V_12 ) & 0x80000000 ) {
V_1 -> V_3 = F_6 ( V_1 ) ;
return 0 ;
}
F_11 ( L_1 , V_14 ) ;
return - V_15 ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_10 ( F_3 ( V_12 ) & ~ 0x80000000 , V_12 ) ;
}
static int F_13 ( struct V_1 * V_1 , unsigned long V_3 )
{
unsigned long V_16 ;
int V_17 ;
V_17 = F_14 ( V_1 , V_1 -> V_13 , V_3 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_3 == V_1 -> V_2 -> V_3 )
return - V_18 ;
V_16 = F_3 ( V_12 ) & ~ ( 0x3f << 24 ) ;
F_10 ( V_16 | ( ( V_17 + 19 ) << 24 ) , V_12 ) ;
V_1 -> V_3 = V_1 -> V_13 [ V_17 ] . V_9 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
T_1 V_16 ;
int V_19 , V_7 ;
if ( ! V_1 -> V_20 || ! V_1 -> V_21 )
return - V_18 ;
for ( V_7 = 0 ; V_7 < V_1 -> V_21 ; V_7 ++ )
if ( V_1 -> V_20 [ V_7 ] == V_2 )
break;
if ( V_7 == V_1 -> V_21 )
return - V_22 ;
V_19 = F_16 ( V_1 , V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_16 = F_3 ( V_12 ) & ~ ( 3 << 6 ) ;
F_10 ( V_16 | ( V_7 << 6 ) , V_12 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
V_16 = F_3 ( V_23 ) ;
V_16 |= ( 1 << 31 ) ;
F_10 ( V_16 , V_23 ) ;
}
static unsigned long F_18 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
V_16 = F_3 ( V_1 -> V_24 -> V_25 ) ;
V_16 >>= 16 ;
if ( V_16 < 2 )
return 0 ;
return V_1 -> V_2 -> V_3 / V_16 ;
}
static long F_19 ( struct V_1 * V_1 , unsigned long V_3 )
{
return F_20 ( V_1 , 2 , 0xffff , V_3 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
F_10 ( 0 , V_1 -> V_24 -> V_25 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
V_16 = F_3 ( V_1 -> V_24 -> V_25 ) >> 16 ;
if ( V_16 < 2 )
return - V_26 ;
F_10 ( ( V_16 << 16 ) | 0x3 , V_1 -> V_24 -> V_25 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_3 )
{
int V_17 ;
V_17 = ( V_1 -> V_2 -> V_3 / V_3 ) & 0xffff ;
if ( V_17 < 2 )
return - V_18 ;
F_10 ( V_17 << 16 , V_1 -> V_24 -> V_25 ) ;
return 0 ;
}
void T_2 F_24 ( void )
{
int V_27 , V_19 = 0 ;
F_10 ( 0xe4ef8087 , V_28 ) ;
F_10 ( 0xffffffff , V_29 ) ;
F_10 ( 0x37c7f7ff , V_30 ) ;
F_10 ( 0xffffffff , V_31 ) ;
F_10 ( 0xffe0fffd , V_32 ) ;
for ( V_27 = 0 ; ! V_19 && ( V_27 < F_5 ( V_33 ) ) ; V_27 ++ )
V_19 = F_25 ( V_33 [ V_27 ] ) ;
if ( ! V_19 )
V_19 = F_26 ( V_34 , V_35 , & V_36 ) ;
if ( ! V_19 )
V_19 = F_27 ( V_37 , V_38 ) ;
if ( ! V_19 )
V_19 = F_28 ( V_39 , V_40 ) ;
if ( ! V_19 )
V_19 = F_29 ( V_41 , V_42 ) ;
for ( V_27 = 0 ; ! V_19 && ( V_27 < F_5 ( V_43 ) ) ; V_27 ++ )
V_19 = F_25 ( V_43 [ V_27 ] ) ;
F_30 ( V_44 , F_5 ( V_44 ) ) ;
if ( ! V_19 )
F_31 () ;
else
F_32 ( L_2 ) ;
}
