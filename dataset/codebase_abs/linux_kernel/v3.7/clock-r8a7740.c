static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / ( int ) ( V_1 -> V_4 ) ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
unsigned long V_5 = 1 ;
if ( F_3 ( V_6 ) & ( 1 << 14 ) )
V_5 = ( ( F_3 ( V_1 -> V_7 ) >> 24 ) & 0x7f ) + 1 ;
return V_1 -> V_2 -> V_3 * V_5 ;
}
static int F_4 ( struct V_1 * V_1 )
{
F_5 ( F_3 ( V_8 ) & ~ ( 1 << 8 ) , V_8 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_5 ( F_3 ( V_8 ) | ( 1 << 8 ) , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
int V_9 , V_10 ;
T_1 V_11 ;
if ( ! V_1 -> V_12 || ! V_1 -> V_13 )
return - V_14 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_13 ; V_9 ++ )
if ( V_1 -> V_12 [ V_9 ] == V_2 )
break;
if ( V_9 == V_1 -> V_13 )
return - V_15 ;
V_10 = F_8 ( V_1 , V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_11 = F_3 ( V_8 ) ;
V_11 &= ~ ( 1 << 7 ) ;
V_11 |= V_9 << 7 ;
F_5 ( V_11 , V_8 ) ;
return 0 ;
}
static unsigned long F_9 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 /
( ( F_3 ( V_8 ) & ( 1 << 6 ) ) ? 1 : 2 ) ;
}
static int F_10 ( struct V_1 * V_1 , unsigned long V_3 )
{
T_1 V_11 ;
V_11 = F_3 ( V_8 ) ;
V_11 &= ~ ( 1 << 6 ) ;
V_11 |= ( V_3 > ( V_1 -> V_2 -> V_3 / 4 ) * 3 ) << 6 ;
F_5 ( V_11 , V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
V_16 = F_3 ( V_17 ) ;
V_16 |= ( 1 << 31 ) ;
F_5 ( V_16 , V_17 ) ;
}
static unsigned long F_12 ( struct V_1 * V_1 )
{
T_1 V_11 = F_3 ( V_18 ) ;
int V_19 = ( int ) V_1 -> V_4 ;
V_11 >>= V_19 ;
V_11 &= 0x3 ;
return V_1 -> V_2 -> V_3 / ( 1 << V_11 ) ;
}
static int F_13 ( struct V_1 * V_1 , unsigned long V_3 )
{
T_1 V_11 , V_20 ;
int V_9 , V_19 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ )
if ( V_3 == V_1 -> V_2 -> V_3 / ( 1 << V_9 ) )
goto V_21;
return - V_15 ;
V_21:
V_19 = ( int ) V_1 -> V_4 ;
V_11 = F_3 ( V_18 ) ;
V_20 = ~ ( 0x3 << V_19 ) ;
V_11 = ( V_11 & V_20 ) | V_9 << V_19 ;
F_5 ( V_11 , V_18 ) ;
return 0 ;
}
void T_2 F_14 ( T_3 V_22 )
{
int V_23 , V_10 = 0 ;
if ( V_22 & V_24 )
V_25 . V_2 = & V_26 ;
else
V_25 . V_2 = & V_27 ;
switch ( V_22 & ( V_28 | V_24 ) ) {
case V_28 | V_24 :
V_29 . V_2 = & V_30 ;
break;
case V_28 :
V_29 . V_2 = & V_31 ;
break;
case V_24 :
default:
V_29 . V_2 = & V_32 ;
break;
}
for ( V_23 = 0 ; ! V_10 && ( V_23 < F_15 ( V_33 ) ) ; V_23 ++ )
V_10 = F_16 ( V_33 [ V_23 ] ) ;
if ( ! V_10 )
V_10 = F_17 ( V_34 , V_35 , & V_36 ) ;
if ( ! V_10 )
V_10 = F_18 ( V_37 , V_38 ) ;
if ( ! V_10 )
V_10 = F_19 ( V_39 ,
V_40 ) ;
if ( ! V_10 )
V_10 = F_20 ( V_41 , V_42 ) ;
for ( V_23 = 0 ; ! V_10 && ( V_23 < F_15 ( V_43 ) ) ; V_23 ++ )
V_10 = F_16 ( V_43 [ V_23 ] ) ;
F_21 ( V_44 , F_15 ( V_44 ) ) ;
if ( ! V_10 )
F_22 () ;
else
F_23 ( L_1 ) ;
}
