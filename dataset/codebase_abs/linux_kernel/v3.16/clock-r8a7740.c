static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
if ( F_2 ( V_3 ) & ( 1 << 14 ) )
V_2 = ( ( F_2 ( V_1 -> V_4 ) >> 24 ) & 0x7f ) + 1 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
static int F_3 ( struct V_1 * V_1 )
{
F_4 ( F_2 ( V_7 ) & ~ ( 1 << 8 ) , V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_4 ( F_2 ( V_7 ) | ( 1 << 8 ) , V_7 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_1 * V_5 )
{
int V_8 , V_9 ;
T_1 V_10 ;
if ( ! V_1 -> V_11 || ! V_1 -> V_12 )
return - V_13 ;
for ( V_8 = 0 ; V_8 < V_1 -> V_12 ; V_8 ++ )
if ( V_1 -> V_11 [ V_8 ] == V_5 )
break;
if ( V_8 == V_1 -> V_12 )
return - V_14 ;
V_9 = F_7 ( V_1 , V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
V_10 = F_2 ( V_7 ) ;
V_10 &= ~ ( 1 << 7 ) ;
V_10 |= V_8 << 7 ;
F_4 ( V_10 , V_7 ) ;
return 0 ;
}
static unsigned long F_8 ( struct V_1 * V_1 )
{
return V_1 -> V_5 -> V_6 /
( ( F_2 ( V_7 ) & ( 1 << 6 ) ) ? 1 : 2 ) ;
}
static int F_9 ( struct V_1 * V_1 , unsigned long V_6 )
{
T_1 V_10 ;
V_10 = F_2 ( V_7 ) ;
V_10 &= ~ ( 1 << 6 ) ;
V_10 |= ( V_6 > ( V_1 -> V_5 -> V_6 / 4 ) * 3 ) << 6 ;
F_4 ( V_10 , V_7 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
unsigned long V_15 ;
V_15 = F_2 ( V_16 ) ;
V_15 |= ( 1 << 31 ) ;
F_4 ( V_15 , V_16 ) ;
}
static unsigned long F_11 ( struct V_1 * V_1 )
{
T_1 V_10 = F_2 ( V_17 ) ;
int V_18 = ( int ) V_1 -> V_19 ;
V_10 >>= V_18 ;
V_10 &= 0x3 ;
return V_1 -> V_5 -> V_6 / ( 1 << V_10 ) ;
}
static int F_12 ( struct V_1 * V_1 , unsigned long V_6 )
{
T_1 V_10 , V_20 ;
int V_8 , V_18 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
if ( V_6 == V_1 -> V_5 -> V_6 / ( 1 << V_8 ) )
goto V_21;
return - V_14 ;
V_21:
V_18 = ( int ) V_1 -> V_19 ;
V_10 = F_2 ( V_17 ) ;
V_20 = ~ ( 0x3 << V_18 ) ;
V_10 = ( V_10 & V_20 ) | V_8 << V_18 ;
F_4 ( V_10 , V_17 ) ;
return 0 ;
}
void T_2 F_13 ( T_3 V_22 )
{
int V_23 , V_9 = 0 ;
if ( V_22 & V_24 )
V_25 . V_5 = & V_26 ;
else
V_25 . V_5 = & V_27 ;
switch ( V_22 & ( V_28 | V_24 ) ) {
case V_28 | V_24 :
V_29 . V_5 = & V_30 ;
break;
case V_28 :
V_29 . V_5 = & V_31 ;
break;
case V_24 :
default:
V_29 . V_5 = & V_32 ;
break;
}
for ( V_23 = 0 ; ! V_9 && ( V_23 < F_14 ( V_33 ) ) ; V_23 ++ )
V_9 = F_15 ( V_33 [ V_23 ] ) ;
if ( ! V_9 )
V_9 = F_16 ( V_34 , V_35 , & V_36 ) ;
if ( ! V_9 )
V_9 = F_17 ( V_37 , V_38 ) ;
if ( ! V_9 )
V_9 = F_18 ( V_39 ,
V_40 ) ;
if ( ! V_9 )
V_9 = F_19 ( V_41 , V_42 ) ;
for ( V_23 = 0 ; ! V_9 && ( V_23 < F_14 ( V_43 ) ) ; V_23 ++ )
V_9 = F_15 ( V_43 [ V_23 ] ) ;
if ( ! V_9 )
V_9 = F_20 ( V_44 , V_45 ) ;
F_21 ( V_46 , F_14 ( V_46 ) ) ;
if ( ! V_9 )
F_22 () ;
else
F_23 ( L_1 ) ;
}
