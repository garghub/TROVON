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
static int F_9 ( struct V_1 * V_1 , unsigned long V_7 )
{
int V_11 ;
if ( ! V_1 -> V_6 || ! F_10 ( V_1 -> V_6 ) )
return - V_12 ;
if ( F_11 ( V_9 ) & ( 1 << 31 ) )
return - V_13 ;
if ( V_7 == F_8 ( V_1 -> V_6 ) ) {
F_4 ( F_2 ( V_9 ) & ~ ( 1 << 28 ) , V_9 ) ;
V_11 = V_14 -> V_15 ( V_1 , V_7 / 2 ) ;
if ( ! V_11 )
V_11 = F_3 () ;
if ( V_11 > 0 )
V_11 = 0 ;
} else {
F_4 ( F_2 ( V_9 ) | ( 1 << 28 ) , V_9 ) ;
V_11 = F_3 () ;
if ( V_11 >= 0 )
V_11 = V_14 -> V_15 ( V_1 , V_7 ) ;
if ( V_11 < 0 )
goto V_16;
}
V_16:
F_12 ( V_1 -> V_6 ) ;
return V_11 ;
}
static long F_13 ( struct V_1 * V_1 , unsigned long V_7 )
{
unsigned long V_17 = V_14 -> V_18 ( V_1 , V_7 ) ,
V_19 = F_8 ( V_1 -> V_6 ) ;
if ( V_7 > V_17 && abs ( V_19 - V_7 ) < V_7 - V_17 )
return V_19 ;
return V_17 ;
}
static unsigned long F_14 ( struct V_1 * V_1 )
{
unsigned long V_17 = V_14 -> V_20 ( V_1 ) ;
if ( F_2 ( V_9 ) & ( 1 << 28 ) )
return V_17 ;
return F_8 ( V_1 -> V_6 ) ;
}
static int F_15 ( struct V_1 * V_1 , unsigned long V_7 )
{
if ( F_2 ( V_9 ) & ( 1 << 31 ) )
return - V_13 ;
return V_14 -> V_15 ( V_1 , V_7 ) ;
}
static void F_16 ( void )
{
int V_8 ;
V_14 = V_21 [ 0 ] . V_22 ;
V_23 = * V_14 ;
V_24 = * V_14 ;
V_23 . V_15 = F_15 ;
V_24 . V_15 = F_9 ;
V_24 . V_18 = F_13 ;
V_24 . V_20 = F_14 ;
for ( V_8 = 0 ; V_8 < V_25 ; V_8 ++ )
V_21 [ V_8 ] . V_22 = V_8 == V_26 ? & V_24 : & V_23 ;
}
static unsigned long F_17 ( struct V_1 * V_1 )
{
T_1 V_27 ;
V_27 = F_2 ( V_1 -> V_28 -> V_29 ) ;
if ( ! ( V_27 & 0x000B8000 ) )
return V_1 -> V_6 -> V_7 ;
V_27 &= 0x3f ;
V_27 += 1 ;
if ( ( V_27 < 12 ) ||
( V_27 > 33 ) ) {
F_18 ( L_1 , V_27 ) ;
return 0 ;
}
return V_1 -> V_6 -> V_7 / V_27 ;
}
static long F_19 ( struct V_1 * V_1 , unsigned long V_7 )
{
return F_20 ( V_1 , 12 , 33 , V_7 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
T_1 V_27 ;
V_27 = F_2 ( V_1 -> V_28 -> V_29 ) ;
V_27 &= ~ 0x000B8000 ;
F_4 ( V_27 , V_1 -> V_28 -> V_29 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
T_1 V_27 ;
int V_30 ;
V_27 = F_2 ( V_1 -> V_28 -> V_29 ) ;
V_30 = ( V_27 & 0x3f ) + 1 ;
if ( ( V_30 < 12 ) || ( V_30 > 33 ) )
return - V_31 ;
F_4 ( V_27 | 0x000B8000 , V_1 -> V_28 -> V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_7 )
{
T_1 V_27 ;
int V_32 ;
V_32 = V_7 / V_1 -> V_6 -> V_7 ;
if ( ( V_32 < 12 ) || ( V_32 > 33 ) )
return - V_33 ;
V_32 += - 1 ;
V_27 = F_2 ( V_1 -> V_28 -> V_29 ) ;
V_27 = ( V_27 & ~ 0x3f ) + V_32 ;
F_4 ( V_27 , V_1 -> V_28 -> V_29 ) ;
return 0 ;
}
void T_2 F_24 ( void )
{
int V_34 , V_11 = 0 ;
F_4 ( 0x108 , V_35 ) ;
F_4 ( 0x108 , V_36 ) ;
F_4 ( 0x108 , V_37 ) ;
switch ( ( F_2 ( V_38 ) >> 28 ) & 0x03 ) {
case 0 :
V_39 . V_6 = & V_40 ;
break;
case 1 :
V_39 . V_6 = & V_41 ;
break;
case 2 :
V_39 . V_6 = & V_42 ;
break;
case 3 :
V_39 . V_6 = & V_43 ;
break;
}
for ( V_34 = 0 ; ! V_11 && ( V_34 < F_25 ( V_44 ) ) ; V_34 ++ )
V_11 = F_26 ( V_44 [ V_34 ] ) ;
if ( ! V_11 ) {
V_11 = F_27 ( V_21 , V_25 , & V_45 ) ;
if ( ! V_11 )
F_16 () ;
}
if ( ! V_11 )
V_11 = F_28 ( V_46 , V_47 ) ;
if ( ! V_11 )
V_11 = F_29 ( V_48 , V_49 ) ;
for ( V_34 = 0 ; ! V_11 && ( V_34 < F_25 ( V_50 ) ) ; V_34 ++ )
V_11 = F_26 ( V_50 [ V_34 ] ) ;
F_30 ( V_51 , F_25 ( V_51 ) ) ;
if ( ! V_11 )
F_31 () ;
else
F_32 ( L_2 ) ;
}
