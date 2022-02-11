static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
if ( F_2 ( V_3 ) & ( 1 << V_1 -> V_4 ) ) {
V_2 = ( ( ( F_2 ( V_1 -> V_5 ) >> 24 ) & 0x3f ) + 1 ) ;
switch ( V_1 -> V_4 ) {
case 1 :
case 2 :
if ( F_2 ( V_1 -> V_5 ) & ( 1 << 20 ) )
V_2 *= 2 ;
}
}
return V_1 -> V_6 -> V_7 * V_2 ;
}
static int F_3 ( void )
{
int V_8 ;
F_4 ( F_2 ( V_9 ) | ( 1 << 31 ) , V_9 ) ;
for ( V_8 = 1000 ; V_8 ; V_8 -- )
if ( F_2 ( V_9 ) & ( 1 << 31 ) )
F_5 () ;
else
return V_8 ;
return - V_10 ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_3 () ;
}
static unsigned long F_7 ( struct V_1 * V_1 )
{
return F_8 ( V_1 -> V_6 ) / 4 ;
}
static unsigned long F_9 ( struct V_1 * V_1 )
{
T_1 V_11 ;
V_11 = F_2 ( V_1 -> V_12 -> V_13 ) ;
if ( ! ( V_11 & 0x000B8000 ) )
return V_1 -> V_6 -> V_7 ;
V_11 &= 0x3f ;
V_11 += 1 ;
if ( ( V_11 < 12 ) ||
( V_11 > 33 ) ) {
F_10 ( L_1 , V_11 ) ;
return 0 ;
}
return V_1 -> V_6 -> V_7 / V_11 ;
}
static long F_11 ( struct V_1 * V_1 , unsigned long V_7 )
{
return F_12 ( V_1 , 12 , 33 , V_7 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_11 ;
V_11 = F_2 ( V_1 -> V_12 -> V_13 ) ;
V_11 &= ~ 0x000B8000 ;
F_4 ( V_11 , V_1 -> V_12 -> V_13 ) ;
}
static int F_14 ( struct V_1 * V_1 )
{
T_1 V_11 ;
int V_14 ;
V_11 = F_2 ( V_1 -> V_12 -> V_13 ) ;
V_14 = ( V_11 & 0x3f ) + 1 ;
if ( ( V_14 < 12 ) || ( V_14 > 33 ) )
return - V_15 ;
F_4 ( V_11 | 0x000B8000 , V_1 -> V_12 -> V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned long V_7 )
{
T_1 V_11 ;
int V_16 ;
V_16 = V_7 / V_1 -> V_6 -> V_7 ;
if ( ( V_16 < 12 ) || ( V_16 > 33 ) )
return - V_17 ;
V_16 += - 1 ;
V_11 = F_2 ( V_1 -> V_12 -> V_13 ) ;
V_11 = ( V_11 & ~ 0x3f ) + V_16 ;
F_4 ( V_11 , V_1 -> V_12 -> V_13 ) ;
return 0 ;
}
void T_2 F_16 ( void )
{
int V_18 , V_19 = 0 ;
F_4 ( 0x108 , V_20 ) ;
F_4 ( 0x108 , V_21 ) ;
F_4 ( 0x108 , V_22 ) ;
switch ( ( F_2 ( V_23 ) >> 28 ) & 0x03 ) {
case 0 :
V_24 . V_6 = & V_25 ;
break;
case 1 :
V_24 . V_6 = & V_26 ;
break;
case 2 :
V_24 . V_6 = & V_27 ;
break;
case 3 :
V_24 . V_6 = & V_28 ;
break;
}
for ( V_18 = 0 ; ! V_19 && ( V_18 < F_17 ( V_29 ) ) ; V_18 ++ )
V_19 = F_18 ( V_29 [ V_18 ] ) ;
if ( ! V_19 )
V_19 = F_19 ( V_30 , V_31 , & V_32 ) ;
if ( ! V_19 )
V_19 = F_20 ( V_33 , V_34 ) ;
if ( ! V_19 )
V_19 = F_21 ( V_35 , V_36 ) ;
for ( V_18 = 0 ; ! V_19 && ( V_18 < F_17 ( V_37 ) ) ; V_18 ++ )
V_19 = F_18 ( V_37 [ V_18 ] ) ;
F_22 ( V_38 , F_17 ( V_38 ) ) ;
if ( ! V_19 )
F_23 () ;
else
F_24 ( L_2 ) ;
}
