static int F_1 ( int V_1 )
{
int V_2 , V_3 ;
unsigned long V_4 ;
if ( V_1 == 0 )
return V_5 ;
if ( V_1 > 44100 )
V_1 = 44100 ;
if ( V_1 < 5000 )
V_1 = 5000 ;
if ( V_6 & 2 )
{
V_2 = ( ( V_7 / 2 ) + ( V_1 / 2 ) ) / V_1 ;
V_1 = ( ( V_7 / 2 ) + ( V_2 / 2 ) ) / V_2 ;
}
else
{
V_2 = ( V_7 + ( V_1 / 2 ) ) / V_1 ;
V_1 = ( V_7 + ( V_2 / 2 ) ) / V_2 ;
}
V_5 = V_1 ;
V_3 = F_2 ( 0x0B8A ) ;
#if ! V_8 V_9
V_3 &= 0xe0 ;
if ( V_5 >= 2 * 17897 )
V_3 |= 0x01 ;
else if ( V_5 >= 2 * 15909 )
V_3 |= 0x02 ;
else if ( V_5 >= 2 * 11931 )
V_3 |= 0x09 ;
else if ( V_5 >= 2 * 8948 )
V_3 |= 0x11 ;
else if ( V_5 >= 2 * 5965 )
V_3 |= 0x19 ;
else if ( V_5 >= 2 * 2982 )
V_3 |= 0x04 ;
V_10 = V_3 ;
#endif
F_3 ( & V_11 , V_4 ) ;
F_4 ( V_3 & ~ ( 0x40 | 0x80 ) , 0x0B8A ) ;
F_4 ( 0x00 | 0x30 | 0x04 , 0x138B ) ;
F_4 ( V_2 & 0xff , 0x1388 ) ;
F_4 ( ( V_2 >> 8 ) & 0xff , 0x1388 ) ;
F_4 ( V_3 , 0x0B8A ) ;
F_5 ( & V_11 , V_4 ) ;
return V_5 ;
}
static int F_6 ( int V_1 )
{
if ( ( V_1 != 1 ) && ( V_1 != 2 ) )
return V_6 ;
if ( V_1 != V_6 )
{
F_4 ( F_2 ( 0xF8A ) ^ 0x20 , 0xF8A ) ;
V_6 = V_1 ;
F_1 ( V_5 ) ;
}
return V_6 ;
}
static int F_7 ( int V_1 )
{
if ( V_1 == 0 )
return V_12 ;
if ( ( V_1 & V_13 ) != V_1 )
return V_12 ;
if ( V_1 != V_12 )
{
F_4 ( F_2 ( 0x8389 ) ^ 0x04 , 0x8389 ) ;
V_12 = V_1 ;
}
return V_12 ;
}
static int F_8 ( int V_14 , unsigned int V_15 , void T_1 * V_1 )
{
int V_16 , V_17 ;
int T_1 * V_18 = V_1 ;
switch ( V_15 )
{
case V_19 :
if ( F_9 ( V_16 , V_18 ) )
return - V_20 ;
V_17 = F_1 ( V_16 ) ;
break;
case V_21 :
V_17 = V_5 ;
break;
case V_22 :
if ( F_9 ( V_16 , V_18 ) )
return - V_20 ;
V_17 = F_6 ( V_16 + 1 ) - 1 ;
break;
case V_23 :
if ( F_9 ( V_16 , V_18 ) )
return - V_20 ;
V_17 = F_6 ( V_16 ) ;
break;
case V_24 :
V_17 = V_6 ;
break;
case V_25 :
if ( F_9 ( V_16 , V_18 ) )
return - V_20 ;
V_17 = F_7 ( V_16 ) ;
break;
case V_26 :
V_17 = V_12 ;
break;
default:
return - V_27 ;
}
return F_10 ( V_17 , V_18 ) ;
}
static void F_11 ( int V_14 )
{
F_4 ( F_2 ( 0xF8A ) & ~ 0x40 , 0xF8A ) ;
}
static int F_12 ( int V_14 , int V_28 )
{
int V_29 ;
unsigned long V_4 ;
F_3 ( & V_11 , V_4 ) ;
if ( V_30 )
{
F_5 ( & V_11 , V_4 ) ;
return - V_31 ;
}
V_30 = 1 ;
F_5 ( & V_11 , V_4 ) ;
if ( ( V_29 = F_13 ( V_32 ) ) < 0 )
return V_29 ;
V_33 = 0 ;
V_34 = V_28 ;
return 0 ;
}
static void F_14 ( int V_14 )
{
unsigned long V_4 ;
F_3 ( & V_11 , V_4 ) ;
F_11 ( V_14 ) ;
F_15 ( V_32 ) ;
V_35 = V_36 ;
V_30 = 0 ;
F_5 ( & V_11 , V_4 ) ;
}
static void F_16 ( int V_14 , unsigned long V_37 , int V_38 ,
int V_39 )
{
unsigned long V_4 , V_40 ;
V_40 = V_38 ;
if ( V_41 [ V_14 ] -> V_42 -> V_43 > 3 )
V_40 >>= 1 ;
if ( V_41 [ V_14 ] -> V_4 & V_44 &&
V_39 &&
V_40 == V_33 )
return;
F_3 ( & V_11 , V_4 ) ;
F_4 ( F_2 ( 0xF8A ) & ~ 0x40 ,
0xF8A ) ;
if ( V_41 [ V_14 ] -> V_42 -> V_43 > 3 )
V_38 >>= 1 ;
if ( V_38 != V_33 )
{
F_4 ( F_2 ( 0x0B8A ) & ~ 0x80 , 0x0B8A ) ;
F_4 ( 0x40 | 0x30 | 0x04 , 0x138B ) ;
F_4 ( V_38 & 0xff , 0x1389 ) ;
F_4 ( ( V_38 >> 8 ) & 0xff , 0x1389 ) ;
F_4 ( F_2 ( 0x0B8A ) | 0x80 , 0x0B8A ) ;
V_33 = V_38 ;
}
F_4 ( F_2 ( 0x0B8A ) | 0x80 | 0x40 , 0x0B8A ) ;
#ifdef F_17
F_4 ( F_2 ( 0xF8A ) | 0x40 | 0x10 , 0xF8A ) ;
#endif
V_35 = V_45 ;
F_5 ( & V_11 , V_4 ) ;
}
static void F_18 ( int V_14 , unsigned long V_37 , int V_38 ,
int V_39 )
{
unsigned long V_4 ;
int V_40 ;
V_40 = V_38 ;
if ( V_41 [ V_14 ] -> V_42 -> V_43 > 3 )
V_40 >>= 1 ;
if ( V_41 [ V_46 ] -> V_4 & V_44 &&
V_39 &&
V_40 == V_33 )
return;
F_3 ( & V_11 , V_4 ) ;
if ( V_41 [ V_14 ] -> V_42 -> V_43 > 3 )
V_38 >>= 1 ;
if ( V_38 != V_33 )
{
F_4 ( F_2 ( 0x0B8A ) & ~ 0x80 , 0x0B8A ) ;
F_4 ( 0x40 | 0x30 | 0x04 , 0x138B ) ;
F_4 ( V_38 & 0xff , 0x1389 ) ;
F_4 ( ( V_38 >> 8 ) & 0xff , 0x1389 ) ;
F_4 ( F_2 ( 0x0B8A ) | 0x80 , 0x0B8A ) ;
V_33 = V_38 ;
}
F_4 ( F_2 ( 0x0B8A ) | 0x80 | 0x40 , 0x0B8A ) ;
#ifdef F_17
F_4 ( ( F_2 ( 0xF8A ) | 0x40 ) & ~ 0x10 , 0xF8A ) ;
#endif
V_35 = V_47 ;
F_5 ( & V_11 , V_4 ) ;
}
static void F_19 ( int V_14 , int V_48 )
{
unsigned long V_4 ;
F_3 ( & V_11 , V_4 ) ;
V_48 &= V_34 ;
if ( V_48 & V_49 )
F_4 ( F_2 ( 0xF8A ) | 0x40 | 0x10 , 0xF8A ) ;
else if ( V_48 & V_50 )
F_4 ( ( F_2 ( 0xF8A ) | 0x40 ) & ~ 0x10 , 0xF8A ) ;
else
F_4 ( F_2 ( 0xF8A ) & ~ 0x40 , 0xF8A ) ;
F_5 ( & V_11 , V_4 ) ;
}
static int F_20 ( int V_14 , int V_51 , int V_52 )
{
F_11 ( V_14 ) ;
return 0 ;
}
static int F_21 ( int V_14 , int V_51 , int V_52 )
{
F_11 ( V_14 ) ;
return 0 ;
}
void T_2 F_22 ( struct V_53 * V_54 )
{
V_13 = 8 ;
if ( F_2 ( 0xEF8B ) & 0x08 )
V_13 |= 16 ;
F_1 ( V_55 ) ;
if ( ( V_46 = F_23 ( V_56 ,
L_1 ,
& V_57 ,
sizeof( struct V_58 ) ,
V_44 ,
V_59 | V_60 ,
NULL ,
V_54 -> V_43 ,
V_54 -> V_43 ) ) < 0 )
F_24 ( V_61 L_2 ) ;
}
void F_25 ( unsigned char V_62 , int V_63 )
{
if ( V_63 == 1 )
{
if ( ! ( V_41 [ V_46 ] -> V_4 & V_44 ) )
F_4 ( F_2 ( 0xF8A ) & ~ 0x40 , 0xF8A ) ;
switch ( V_35 )
{
case V_45 :
F_26 ( V_46 , 1 ) ;
break;
case V_47 :
F_27 ( V_46 ) ;
break;
default:
F_24 ( V_61 L_3 ) ;
}
}
}
