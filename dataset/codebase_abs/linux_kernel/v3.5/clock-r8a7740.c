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
void T_2 F_12 ( T_3 V_18 )
{
int V_19 , V_10 = 0 ;
if ( V_18 & V_20 )
V_21 . V_2 = & V_22 ;
else
V_21 . V_2 = & V_23 ;
switch ( V_18 & ( V_24 | V_20 ) ) {
case V_24 | V_20 :
V_25 . V_2 = & V_26 ;
break;
case V_24 :
V_25 . V_2 = & V_27 ;
break;
case V_20 :
default:
V_25 . V_2 = & V_28 ;
break;
}
for ( V_19 = 0 ; ! V_10 && ( V_19 < F_13 ( V_29 ) ) ; V_19 ++ )
V_10 = F_14 ( V_29 [ V_19 ] ) ;
if ( ! V_10 )
V_10 = F_15 ( V_30 , V_31 , & V_32 ) ;
if ( ! V_10 )
V_10 = F_16 ( V_33 , V_34 ) ;
if ( ! V_10 )
V_10 = F_17 ( V_35 , V_36 ) ;
F_18 ( V_37 , F_13 ( V_37 ) ) ;
if ( ! V_10 )
F_19 () ;
else
F_20 ( L_1 ) ;
}
