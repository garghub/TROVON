unsigned char F_1 ( int V_1 )
{
return F_2 ( V_1 + V_2 ) ;
}
void F_3 ( unsigned char V_3 , int V_1 )
{
F_4 ( ( V_3 ) , V_1 + V_2 ) ;
}
static T_1 F_5 ( int V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_1 ( 0x0B89 ) ;
F_3 ( V_6 , 0x0B89 ) ;
if ( V_6 & 0x08 )
{
F_6 ( V_6 , 1 ) ;
V_6 &= ~ 0x08 ;
}
if ( V_6 & 0x10 )
{
F_7 () ;
V_6 &= ~ 0x10 ;
}
return V_7 ;
}
int F_8 ( int V_8 )
{
if ( ! V_8 )
return 0 ;
V_9 |= V_8 ;
F_3 ( V_9 , 0x0B8B ) ;
return 0 ;
}
int F_9 ( int V_8 )
{
if ( ! V_8 )
return 0 ;
V_9 &= ~ V_8 ;
F_3 ( V_9 , 0x0B8B ) ;
return 0 ;
}
static int T_2 F_10 ( struct V_10 * V_11 )
{
char V_12 = 1 ;
unsigned V_13 ;
V_14 = V_11 -> V_4 ;
F_3 ( 0x00 , 0x0B8B ) ;
F_3 ( 0x36 , 0x138B ) ;
F_3 ( 0x36 , 0x1388 ) ;
F_3 ( 0 , 0x1388 ) ;
F_3 ( 0x74 , 0x138B ) ;
F_3 ( 0x74 , 0x1389 ) ;
F_3 ( 0 , 0x1389 ) ;
F_3 ( 0x80 | 0x40 | 0x20 | 1 , 0x0B8A ) ;
F_3 ( 0x80 | 0x20 | 0x10 | 0x08 | 0x01 , 0xF8A ) ;
F_3 ( 0x01 | 0x02 | 0x04 | 0x10 , 0xB88 ) ;
F_3 ( 0x80 | ( V_15 ? 0x40 : 0 ) , 0xF388 ) ;
if ( V_14 < 0 || V_14 > 15 )
{
F_11 ( V_16 L_1 , V_14 ) ;
V_11 -> V_4 = - 1 ;
V_12 = 0 ;
}
else
{
V_13 = F_1 ( 0xF38A ) ;
V_13 = ( V_13 & 0xf0 ) | V_17 [ V_14 ] ;
F_3 ( V_13 , 0xF38A ) ;
if ( ! V_17 [ V_14 ] )
{
F_11 ( V_16 L_1 , V_14 ) ;
V_11 -> V_4 = - 1 ;
V_12 = 0 ;
}
else
{
if ( F_12 ( V_14 , F_5 , 0 , L_2 , V_11 ) < 0 ) {
F_11 ( V_16 L_3 , V_14 ) ;
V_11 -> V_4 = - 1 ;
V_12 = 0 ;
}
}
}
if ( V_11 -> V_18 < 0 || V_11 -> V_18 > 7 )
{
F_11 ( V_16 L_4 , V_11 -> V_18 ) ;
V_11 -> V_18 = - 1 ;
V_12 = 0 ;
}
else
{
F_3 ( V_19 [ V_11 -> V_18 ] , 0xF389 ) ;
if ( ! V_19 [ V_11 -> V_18 ] )
{
F_11 ( V_16 L_4 , V_11 -> V_18 ) ;
V_11 -> V_18 = - 1 ;
V_12 = 0 ;
}
else
{
if ( F_13 ( V_11 -> V_18 , L_2 ) )
{
F_11 ( V_16 L_5 ) ;
V_11 -> V_18 = - 1 ;
V_12 = 0 ;
}
}
}
if( V_20 )
{
F_4 ( ( 0x05 ) , 0xa8 ) ;
F_4 ( ( 0x60 ) , 0xa9 ) ;
}
if( V_21 )
F_3 ( 0x01 | 0x10 | 0x20 | 0x04 , 0x8388 ) ;
else
F_3 ( 0x01 | 0x10 | 0x20 , 0x8388 ) ;
F_3 ( 0x18 , 0x838A ) ;
F_3 ( 0x20 | 0x01 , 0x0B8A ) ;
F_3 ( 8 , 0xBF8A ) ;
F_14 ( 0x80 | 5 , 0x078B ) ;
F_14 ( 5 , 0x078B ) ;
{
struct V_10 * V_22 ;
V_22 = & V_23 ;
if ( V_22 -> V_24 )
{
unsigned char V_25 ;
F_3 ( 0x02 , 0xF788 ) ;
F_3 ( ( V_22 -> V_24 >> 4 ) & 0x0f , 0xF789 ) ;
V_26 = V_22 -> V_24 ;
if ( ! V_27 [ V_22 -> V_18 ] )
F_11 ( V_16 L_6 , V_22 -> V_18 ) ;
if ( ! V_28 [ V_22 -> V_4 ] )
F_11 ( V_16 L_7 , V_22 -> V_4 ) ;
V_25 = V_27 [ V_22 -> V_18 ] |
V_28 [ V_22 -> V_4 ] ;
F_3 ( V_25 , 0xFB8A ) ;
}
else
F_3 ( 0x00 , 0xF788 ) ;
}
if ( ! V_12 )
F_11 ( V_29 L_8 ) ;
return V_12 ;
}
static int T_2 F_15 ( struct V_10 * V_11 )
{
unsigned char V_30 , V_31 ;
F_4 ( ( 0xBC ) , 0x9A01 ) ;
F_4 ( ( V_11 -> V_24 >> 2 ) , 0x9A01 ) ;
V_2 = V_11 -> V_24 - 0x388 ;
F_3 ( 1 , 0xBF88 ) ;
V_30 = F_1 ( 0x0B8B ) ;
if ( V_30 == 0xff )
return 0 ;
V_31 = V_30 ^ 0xe0 ;
F_3 ( V_31 , 0x0B8B ) ;
V_31 = F_1 ( 0x0B8B ) ;
F_3 ( V_30 , 0x0B8B ) ;
if ( V_30 != V_31 )
return 0 ;
V_32 = F_1 ( 0xFF88 ) ;
return V_32 ;
}
static void T_2 F_16 ( struct V_10 * V_11 )
{
V_14 = V_11 -> V_4 ;
if ( F_15 ( V_11 ) )
{
if ( ( V_32 = F_1 ( 0xFF88 ) ) )
{
char V_33 [ 100 ] ;
sprintf ( V_33 ,
L_9 , V_34 [ ( int ) V_32 ] ,
F_1 ( 0x2789 ) ) ;
F_17 ( V_33 , V_11 ) ;
}
if ( F_10 ( V_11 ) )
{
F_18 ( V_11 ) ;
F_19 () ;
F_20 () ;
}
}
}
static inline int T_2 F_21 ( struct V_10 * V_11 )
{
return F_15 ( V_11 ) ;
}
static void T_3 F_22 ( struct V_10 * V_11 )
{
extern int V_35 ;
extern int V_36 ;
if ( V_11 -> V_18 > 0 )
F_23 ( V_11 -> V_18 ) ;
if ( V_11 -> V_4 > 0 )
F_24 ( V_11 -> V_4 , V_11 ) ;
if( V_35 != - 1 )
F_25 ( V_37 [ V_35 ] -> V_38 ) ;
if( V_36 != - 1 )
F_26 ( V_36 ) ;
if( V_35 != - 1 )
F_27 ( V_35 ) ;
}
static int T_2 F_28 ( void )
{
F_11 ( V_39 L_10 ) ;
V_40 . V_24 = V_41 ;
V_40 . V_4 = V_4 ;
V_40 . V_18 = V_18 ;
V_40 . V_42 = V_43 ;
V_23 . V_24 = V_44 ;
V_23 . V_4 = V_45 ;
V_23 . V_18 = V_46 ;
V_23 . V_42 = V_47 ;
if ( V_40 . V_24 == - 1 || V_40 . V_18 == - 1 || V_40 . V_4 == - 1 ) {
F_11 ( V_39 L_11 ) ;
return - V_48 ;
}
if ( ! F_21 ( & V_40 ) )
return - V_49 ;
F_16 ( & V_40 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
F_22 ( & V_40 ) ;
}
static int T_2 F_30 ( char * V_50 )
{
int V_51 [ 9 ] ;
V_50 = F_31 ( V_50 , F_32 ( V_51 ) , V_51 ) ;
V_41 = V_51 [ 1 ] ;
V_4 = V_51 [ 2 ] ;
V_18 = V_51 [ 3 ] ;
V_43 = V_51 [ 4 ] ;
V_44 = V_51 [ 5 ] ;
V_45 = V_51 [ 6 ] ;
V_46 = V_51 [ 7 ] ;
V_47 = V_51 [ 8 ] ;
return 1 ;
}
