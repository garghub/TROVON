static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 2 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 7 ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 13 ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
if ( F_5 ( V_5 ) & ( 1 << V_1 -> V_6 ) ) {
V_4 = ( ( ( F_5 ( V_1 -> V_7 ) >> 24 ) & 0x3f ) + 1 ) ;
switch ( V_1 -> V_6 ) {
case 1 :
case 2 :
if ( F_5 ( V_1 -> V_7 ) & ( 1 << 20 ) )
V_4 *= 2 ;
}
}
return V_1 -> V_2 -> V_3 * V_4 ;
}
static void F_6 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
V_8 = F_5 ( V_9 ) ;
V_8 |= ( 1 << 31 ) ;
F_7 ( V_8 , V_9 ) ;
}
static unsigned long F_8 ( struct V_1 * V_1 )
{
T_1 V_8 ;
V_8 = F_5 ( V_1 -> V_10 -> V_11 ) ;
if ( ! ( V_8 & 0x000B8000 ) )
return V_1 -> V_2 -> V_3 ;
V_8 &= 0x3f ;
V_8 += 1 ;
if ( ( V_8 < 12 ) ||
( V_8 > 33 ) ) {
F_9 ( L_1 , V_8 ) ;
return 0 ;
}
return V_1 -> V_2 -> V_3 / V_8 ;
}
static long F_10 ( struct V_1 * V_1 , unsigned long V_3 )
{
return F_11 ( V_1 , 12 , 33 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 V_8 ;
V_8 = F_5 ( V_1 -> V_10 -> V_11 ) ;
V_8 &= ~ 0x000B8000 ;
F_7 ( V_8 , V_1 -> V_10 -> V_11 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
T_1 V_8 ;
int V_12 ;
V_8 = F_5 ( V_1 -> V_10 -> V_11 ) ;
V_12 = ( V_8 & 0x3f ) + 1 ;
if ( ( V_12 < 12 ) || ( V_12 > 33 ) )
return - V_13 ;
F_7 ( V_8 | 0x000B8000 , V_1 -> V_10 -> V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_3 )
{
T_1 V_8 ;
int V_14 ;
V_14 = V_3 / V_1 -> V_2 -> V_3 ;
if ( ( V_14 < 12 ) || ( V_14 > 33 ) )
return - V_15 ;
V_14 += - 1 ;
V_8 = F_5 ( V_1 -> V_10 -> V_11 ) ;
V_8 = ( V_8 & ~ 0x3f ) + V_14 ;
F_7 ( V_8 , V_1 -> V_10 -> V_11 ) ;
return 0 ;
}
void T_2 F_15 ( void )
{
int V_16 , V_17 = 0 ;
F_7 ( 0x108 , V_18 ) ;
F_7 ( 0x108 , V_19 ) ;
F_7 ( 0x108 , V_20 ) ;
switch ( ( F_5 ( V_21 ) >> 28 ) & 0x03 ) {
case 0 :
V_22 . V_2 = & V_23 ;
break;
case 1 :
V_22 . V_2 = & V_24 ;
break;
case 2 :
V_22 . V_2 = & V_25 ;
break;
case 3 :
V_22 . V_2 = & V_26 ;
break;
}
for ( V_16 = 0 ; ! V_17 && ( V_16 < F_16 ( V_27 ) ) ; V_16 ++ )
V_17 = F_17 ( V_27 [ V_16 ] ) ;
if ( ! V_17 )
V_17 = F_18 ( V_28 , V_29 , & V_30 ) ;
if ( ! V_17 )
V_17 = F_19 ( V_31 , V_32 ) ;
if ( ! V_17 )
V_17 = F_20 ( V_33 , V_34 ) ;
for ( V_16 = 0 ; ! V_17 && ( V_16 < F_16 ( V_35 ) ) ; V_16 ++ )
V_17 = F_17 ( V_35 [ V_16 ] ) ;
F_21 ( V_36 , F_16 ( V_36 ) ) ;
if ( ! V_17 )
F_22 () ;
else
F_23 ( L_2 ) ;
}
