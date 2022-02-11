int F_1 ( int V_1 , int V_2 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
if ( V_3 == NULL )
{
F_2 ( V_6 L_1 ) ;
return - V_7 ;
}
if ( V_3 -> V_8 & V_9 && V_2 & V_10 )
{
if ( V_2 == V_10 )
return - V_11 ;
}
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( V_3 -> V_13 )
{
F_4 ( & V_3 -> V_12 , V_5 ) ;
return - V_14 ;
}
if ( V_3 -> V_15 != - 1 && V_3 -> V_15 != V_3 -> V_16 && ! V_3 -> V_17 )
{
if ( F_5 ( V_3 -> V_15 , L_2 ) )
{
F_4 ( & V_3 -> V_12 , V_5 ) ;
return - V_14 ;
}
}
V_3 -> V_13 = V_2 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_18 = V_19 ;
V_3 -> V_20 = V_19 ;
V_3 -> V_21 = V_3 -> V_17 &&
( ( V_2 & V_10 ) && ( V_2 & V_22 ) ) ;
F_6 ( V_3 ) ;
if ( V_3 -> V_23 == V_24 ) F_7 ( V_3 , V_25 ) ;
if ( V_3 -> V_26 == V_27 )
{
if ( V_2 & V_10 )
F_8 ( V_3 , V_28 ,
F_9 ( V_3 , V_28 ) & 0xf9 ) ;
else
F_8 ( V_3 , V_28 ,
F_9 ( V_3 , V_28 ) | 0x06 ) ;
}
return 0 ;
}
void F_10 ( int V_1 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if( V_3 -> V_17
&& ! V_3 -> V_21
&& ( V_3 -> V_13 & V_10 ) && ( V_3 -> V_13 & V_22 ) )
F_11 ( V_4 [ V_1 ] -> V_29 , V_4 [ V_1 ] -> V_30 ) ;
V_4 [ V_1 ] -> V_29 -> V_31 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_30 -> V_31 = ( V_3 -> V_17 ) ?
V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_15 != - 1 && V_3 -> V_15 != V_3 -> V_16 && ! V_3 -> V_17 )
F_12 ( V_3 -> V_15 ) ;
if ( ( V_3 -> V_26 == V_27 ) && ( V_3 -> V_13 & V_10 ) )
{
F_8 ( V_3 , V_28 ,
F_9 ( V_3 , V_28 ) | 0x06 ) ;
}
V_3 -> V_13 = 0 ;
}
static void F_13 ( int V_1 , unsigned long V_32 , int V_33 ,
int V_34 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_35 == V_36 )
{
V_3 -> V_37 = V_32 ;
V_3 -> V_38 = V_33 ;
V_3 -> V_39 = V_34 ;
V_3 -> V_18 = V_40 ;
}
else
{
V_3 -> V_41 = V_32 ;
V_3 -> V_42 = V_33 ;
V_3 -> V_43 = V_34 ;
V_3 -> V_20 = V_40 ;
}
}
static void F_14 ( int V_1 , unsigned long V_32 , int V_44 , int V_34 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_35 != V_36 )
{
V_3 -> V_37 = V_32 ;
V_3 -> V_38 = V_44 ;
V_3 -> V_39 = V_34 ;
V_3 -> V_18 = V_45 ;
}
else
{
V_3 -> V_41 = V_32 ;
V_3 -> V_42 = V_44 ;
V_3 -> V_43 = V_34 ;
V_3 -> V_20 = V_45 ;
}
}
static void F_15 ( int V_1 , unsigned long V_32 , int V_33 , int V_34 )
{
unsigned long V_5 ;
int V_44 = V_33 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_4 [ V_1 ] -> V_29 -> V_31 > 3 )
V_44 >>= 1 ;
V_44 -- ;
V_3 -> V_18 = V_40 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x14 ) )
{
F_16 ( V_3 , ( unsigned char ) ( V_44 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_44 >> 8 ) & 0xff ) ) ;
}
else
F_2 ( V_46 L_3 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_47 = 1 ;
}
static void F_17 ( int V_1 , unsigned long V_32 , int V_33 , int V_34 )
{
unsigned long V_5 ;
int V_44 = V_33 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_4 [ V_1 ] -> V_29 -> V_31 > 3 )
V_44 >>= 1 ;
V_44 -- ;
V_3 -> V_18 = V_45 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x24 ) )
{
F_16 ( V_3 , ( unsigned char ) ( V_44 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_44 >> 8 ) & 0xff ) ) ;
}
else
F_2 ( V_6 L_4 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_47 = 1 ;
}
static void F_18 ( int V_1 , int V_35 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_35 &= V_3 -> V_18 ;
if ( ! V_35 )
F_16 ( V_3 , 0xd0 ) ;
else
{
switch ( V_3 -> V_18 )
{
case V_45 :
F_17 ( V_1 , V_3 -> V_37 , V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
case V_40 :
F_15 ( V_1 , V_3 -> V_37 , V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
}
}
V_3 -> V_48 = V_35 ;
}
static int F_19 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x40 ) )
F_16 ( V_3 , V_3 -> V_51 ) ;
F_16 ( V_3 , V_52 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_48 = 0 ;
return 0 ;
}
static int F_20 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x40 ) )
F_16 ( V_3 , V_3 -> V_51 ) ;
F_16 ( V_3 , V_53 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_48 = 0 ;
return 0 ;
}
static int F_21 ( int V_1 , int V_54 )
{
int V_55 = 23000 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_56 ;
if ( V_3 -> V_13 & V_10 )
V_55 = 13000 ;
if ( V_54 > 0 )
{
if ( V_54 < 4000 )
V_54 = 4000 ;
if ( V_54 > V_55 )
V_54 = V_55 ;
V_3 -> V_51 = ( 256 - ( ( 1000000 + V_54 / 2 ) / V_54 ) ) & 0xff ;
V_56 = 256 - V_3 -> V_51 ;
V_54 = ( 1000000 + V_56 / 2 ) / V_56 ;
V_3 -> V_54 = V_54 ;
}
return V_3 -> V_54 ;
}
static short F_22 ( int V_1 , short V_57 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
return V_3 -> V_57 = 1 ;
}
static unsigned int F_23 ( int V_1 , unsigned int V_35 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
return V_3 -> V_35 = 8 ;
}
static void F_24 ( int V_1 )
{
unsigned long V_5 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_6 ( V_3 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_25 ( int V_1 , unsigned long V_32 , int V_33 ,
int V_34 )
{
unsigned long V_5 ;
int V_44 = V_33 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned char V_58 ;
if ( V_4 [ V_1 ] -> V_29 -> V_31 > 3 )
V_44 >>= 1 ;
V_44 -- ;
V_3 -> V_18 = V_40 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x48 ) )
{
F_16 ( V_3 , ( unsigned char ) ( V_44 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_44 >> 8 ) & 0xff ) ) ;
if ( V_3 -> V_54 * V_3 -> V_57 <= 23000 )
V_58 = 0x1c ;
else
V_58 = 0x90 ;
if ( ! F_16 ( V_3 , V_58 ) )
F_2 ( V_6 L_3 ) ;
}
else
F_2 ( V_6 L_5 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_47 = 1 ;
}
static void F_26 ( int V_1 , unsigned long V_32 , int V_33 , int V_34 )
{
unsigned long V_5 ;
int V_44 = V_33 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned char V_58 ;
if ( V_4 [ V_1 ] -> V_29 -> V_31 > 3 )
V_44 >>= 1 ;
V_44 -- ;
V_3 -> V_18 = V_45 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x48 ) )
{
F_16 ( V_3 , ( unsigned char ) ( V_44 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_44 >> 8 ) & 0xff ) ) ;
if ( V_3 -> V_54 * V_3 -> V_57 <= ( V_3 -> V_59 == 3 ? 23000 : 13000 ) )
V_58 = 0x2c ;
else
V_58 = 0x98 ;
if ( ! F_16 ( V_3 , V_58 ) )
F_2 ( V_6 L_4 ) ;
}
else
F_2 ( V_6 L_4 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_47 = 1 ;
}
static void F_27 ( int V_1 , int V_35 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_35 &= V_3 -> V_18 ;
if ( ! V_35 )
F_16 ( V_3 , 0xd0 ) ;
else
{
switch ( V_3 -> V_18 )
{
case V_45 :
F_26 ( V_1 , V_3 -> V_37 , V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
case V_40 :
F_25 ( V_1 , V_3 -> V_37 , V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
}
}
V_3 -> V_48 = V_35 ;
}
static int F_28 ( int V_1 , int V_54 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_56 ;
int V_60 ;
if ( V_54 > 0 )
{
if ( V_54 < 4000 )
V_54 = 4000 ;
if ( V_54 > 44100 )
V_54 = 44100 ;
if ( V_3 -> V_13 & V_10 && V_54 > 15000 )
V_54 = 15000 ;
V_60 = V_54 * V_3 -> V_57 ;
V_3 -> V_51 = ( 256 - ( ( 1000000 + V_60 / 2 ) / V_60 ) ) & 0xff ;
V_56 = 256 - V_3 -> V_51 ;
V_54 = ( ( 1000000 + V_56 / 2 ) / V_56 ) / V_3 -> V_57 ;
V_3 -> V_54 = V_54 ;
}
return V_3 -> V_54 ;
}
static int F_29 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
unsigned char V_35 = 0 ;
if ( V_3 -> V_15 >= 0 && V_3 -> V_15 != V_3 -> V_16 )
V_4 [ V_1 ] -> V_29 -> V_31 = V_4 [ V_1 ] -> V_30 -> V_31 =
V_3 -> V_35 == 16 ? V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_23 == V_61 || V_3 -> V_23 == V_62 )
if ( V_3 -> V_35 == V_36 )
V_35 = 0x04 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x40 ) )
F_16 ( V_3 , V_3 -> V_51 ) ;
F_16 ( V_3 , V_52 ) ;
if ( V_3 -> V_57 == 1 )
F_16 ( V_3 , 0xa0 | V_35 ) ;
else
F_16 ( V_3 , 0xa8 | V_35 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_48 = 0 ;
return 0 ;
}
static int F_30 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
unsigned char V_56 ;
unsigned char V_35 = 0 ;
if ( V_3 -> V_15 >= 0 && V_3 -> V_15 != V_3 -> V_16 )
V_4 [ V_1 ] -> V_29 -> V_31 = V_4 [ V_1 ] -> V_30 -> V_31 = V_3 -> V_35 == 16 ? V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_23 == V_63 )
F_31 ( V_3 , V_3 -> V_57 == 2 ) ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_16 ( V_3 , 0x40 ) )
F_16 ( V_3 , V_3 -> V_51 ) ;
F_16 ( V_3 , V_53 ) ;
if ( V_3 -> V_23 == V_61 || V_3 -> V_23 == V_62 )
{
if ( V_3 -> V_35 == V_36 )
V_35 = 0x04 ;
if ( V_3 -> V_57 == 1 )
F_16 ( V_3 , 0xa0 | V_35 ) ;
else
F_16 ( V_3 , 0xa8 | V_35 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
else
{
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_56 = F_9 ( V_3 , 0x0e ) ;
if ( V_3 -> V_57 == 1 )
V_56 &= ~ 0x02 ;
else
V_56 |= 0x02 ;
F_8 ( V_3 , 0x0e , V_56 ) ;
}
V_3 -> V_48 = 0 ;
return 0 ;
}
static int F_32 ( int V_1 , int V_54 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_54 > 0 )
{
if ( V_54 < 4000 )
V_54 = 4000 ;
if ( V_54 > 44100 )
V_54 = 44100 ;
if ( V_3 -> V_57 > 1 && V_54 > 22050 )
V_54 = 22050 ;
F_28 ( V_1 , V_54 ) ;
}
return V_3 -> V_54 ;
}
static short F_33 ( int V_1 , short V_57 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_57 == 1 || V_57 == 2 )
{
if ( V_57 != V_3 -> V_57 )
{
V_3 -> V_57 = V_57 ;
if ( V_3 -> V_23 == V_63 && V_3 -> V_57 == 2 )
F_32 ( V_1 , V_3 -> V_54 ) ;
}
}
return V_3 -> V_57 ;
}
static int F_34 ( int V_1 , int V_54 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_54 > 0 )
{
int V_56 ;
int V_60 ;
if ( V_54 < 5000 )
V_54 = 5000 ;
if ( V_54 > 44100 )
V_54 = 44100 ;
V_60 = V_54 * V_3 -> V_57 ;
V_3 -> V_51 = ( 256 - ( ( 1000000 + V_60 / 2 ) / V_60 ) ) & 0xff ;
V_56 = 256 - V_3 -> V_51 ;
V_54 = ( ( 1000000 + V_56 / 2 ) / V_56 ) / V_3 -> V_57 ;
V_3 -> V_54 = V_54 ;
}
return V_3 -> V_54 ;
}
static int F_35 ( int V_1 , int V_54 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_55 = V_3 -> V_26 == V_64 ? 48000 : 44100 ;
if ( V_54 > 0 )
{
if ( V_54 < 5000 )
V_54 = 5000 ;
if ( V_54 > V_55 )
V_54 = V_55 ;
V_3 -> V_54 = V_54 ;
}
return V_3 -> V_54 ;
}
static unsigned int F_36 ( int V_1 , unsigned int V_35 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_35 != 0 )
{
if ( V_35 == V_65 || V_35 == V_36 )
V_3 -> V_35 = V_35 ;
else
V_3 -> V_35 = V_65 ;
}
return V_3 -> V_35 ;
}
static int F_37 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 )
{
V_4 [ V_1 ] -> V_29 -> V_31 =
V_4 [ V_1 ] -> V_30 -> V_31 =
V_3 -> V_35 == V_36 ?
V_3 -> V_15 : V_3 -> V_16 ;
}
else if ( V_3 -> V_35 == V_36 )
{
V_4 [ V_1 ] -> V_29 -> V_31 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_30 -> V_31 = V_3 -> V_15 ;
}
else
{
V_4 [ V_1 ] -> V_29 -> V_31 = V_3 -> V_15 ;
V_4 [ V_1 ] -> V_30 -> V_31 = V_3 -> V_16 ;
}
V_3 -> V_48 = 0 ;
return 0 ;
}
static int F_38 ( int V_1 , int V_49 , int V_50 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 )
{
V_4 [ V_1 ] -> V_29 -> V_31 =
V_4 [ V_1 ] -> V_30 -> V_31 =
V_3 -> V_35 == V_36 ?
V_3 -> V_15 : V_3 -> V_16 ;
}
else if ( V_3 -> V_35 == V_36 )
{
V_4 [ V_1 ] -> V_29 -> V_31 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_30 -> V_31 = V_3 -> V_15 ;
}
else
{
V_4 [ V_1 ] -> V_29 -> V_31 = V_3 -> V_15 ;
V_4 [ V_1 ] -> V_30 -> V_31 = V_3 -> V_16 ;
}
V_3 -> V_48 = 0 ;
return 0 ;
}
static void F_39 ( int V_1 , unsigned long V_32 , int V_44 ,
int V_34 )
{
unsigned long V_5 , V_66 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_35 ;
if ( ! V_3 -> V_21 || V_3 -> V_35 == V_36 )
{
V_3 -> V_18 = V_40 ;
V_3 -> V_47 = 1 ;
}
else
{
V_3 -> V_20 = V_40 ;
V_3 -> V_67 = 1 ;
}
F_3 ( & V_3 -> V_12 , V_5 ) ;
V_35 = V_3 -> V_35 ;
if ( V_3 -> V_21 )
V_3 -> V_35 = ( V_3 -> V_35 == V_36 ) ?
V_65 : V_36 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_66 = V_44 ;
if ( V_3 -> V_35 == V_36 )
V_66 >>= 1 ;
V_66 -- ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_16 ( V_3 , 0x41 ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_3 -> V_54 >> 8 ) & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_3 -> V_54 & 0xff ) ) ;
F_16 ( V_3 , ( V_3 -> V_35 == V_36 ? 0xb6 : 0xc6 ) ) ;
F_16 ( V_3 , ( ( V_3 -> V_57 == 2 ? 0x20 : 0 ) +
( V_3 -> V_35 == V_36 ? 0x10 : 0 ) ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_66 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_66 >> 8 ) ) ;
V_3 -> V_35 = V_35 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_40 ( int V_1 , unsigned long V_32 , int V_44 , int V_34 )
{
unsigned long V_5 , V_66 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_35 != V_36 )
{
V_3 -> V_18 = V_45 ;
V_3 -> V_47 = 1 ;
}
else
{
V_3 -> V_20 = V_45 ;
V_3 -> V_67 = 1 ;
}
V_66 = V_44 ;
if ( V_3 -> V_35 == V_36 )
V_66 >>= 1 ;
V_66 -- ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_16 ( V_3 , 0x42 ) ;
F_16 ( V_3 , ( unsigned char ) ( ( V_3 -> V_54 >> 8 ) & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_3 -> V_54 & 0xff ) ) ;
F_16 ( V_3 , ( V_3 -> V_35 == V_36 ? 0xbe : 0xce ) ) ;
F_16 ( V_3 , ( ( V_3 -> V_57 == 2 ? 0x20 : 0 ) +
( V_3 -> V_35 == V_36 ? 0x10 : 0 ) ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_66 & 0xff ) ) ;
F_16 ( V_3 , ( unsigned char ) ( V_66 >> 8 ) ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_41 ( int V_1 , int V_35 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_68 = V_35 & V_3 -> V_20 ;
V_35 &= V_3 -> V_18 ;
if ( ! V_35 && ! V_68 )
F_16 ( V_3 , 0xd0 ) ;
else
{
if ( V_35 )
{
switch ( V_3 -> V_18 )
{
case V_45 :
F_40 ( V_1 ,
V_3 -> V_37 ,
V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
case V_40 :
F_39 ( V_1 ,
V_3 -> V_37 ,
V_3 -> V_38 ,
V_3 -> V_39 ) ;
break;
}
}
if ( V_68 )
{
switch ( V_3 -> V_20 )
{
case V_45 :
F_40 ( V_1 ,
V_3 -> V_41 ,
V_3 -> V_42 ,
V_3 -> V_43 ) ;
break;
case V_40 :
F_39 ( V_1 ,
V_3 -> V_41 ,
V_3 -> V_42 ,
V_3 -> V_43 ) ;
break;
}
}
}
V_3 -> V_48 = V_35 | V_68 ;
}
static void
F_42 ( int V_1 ,
char * V_69 , int V_70 ,
const char T_2 * V_71 , int V_72 ,
int V_73 , int V_74 ,
int * V_75 , int * V_76 ,
int V_77 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_78 , V_79 , V_80 , V_81 ;
unsigned char * V_82 ;
signed short * V_83 ;
if ( ! V_3 -> V_21 )
{
if ( F_43 ( V_69 + V_70 ,
V_71 + V_72 , V_77 ) )
return;
* V_75 = V_77 ;
* V_76 = V_77 ;
}
else if ( V_3 -> V_35 == V_36 )
{
V_77 = ( ( V_73 >> 1 ) > V_74 ) ? V_74 : ( V_73 >> 1 ) ;
V_79 = V_77 ;
V_80 = 0 ;
V_82 = ( unsigned char * ) ( V_69 + V_70 ) ;
while ( V_79 )
{
V_81 = ( V_79 >= V_84 ? V_84 : V_79 ) ;
if ( F_43 ( V_85 ,
V_71 + V_72 + ( V_80 << 1 ) ,
V_81 << 1 ) )
return;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ )
{
V_82 [ V_80 + V_78 ] = ~ ( ( V_85 [ V_78 ] >> 8 ) & 0xff ) ^ 0x80 ;
}
V_79 -= V_81 ; V_80 += V_81 ;
}
* V_75 = V_73 > ( V_74 << 1 ) ? ( V_74 << 1 ) : V_73 ;
* V_76 = V_77 ;
}
else
{
V_77 = V_73 > ( V_74 >> 1 ) ? ( V_74 >> 1 ) : V_73 ;
V_79 = V_77 ;
V_80 = 0 ;
V_83 = ( signed short * ) ( V_69 + V_70 ) ;
while ( V_79 )
{
V_81 = ( V_79 >= V_84 ? V_84 : V_79 ) ;
if ( F_43 ( V_86 ,
V_71 + V_72 + V_80 ,
V_81 ) )
return;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ )
{
V_83 [ V_80 + V_78 ] = ( ~ V_86 [ V_78 ] ^ 0x80 ) << 8 ;
}
V_79 -= V_81 ; V_80 += V_81 ;
}
* V_75 = V_77 ;
* V_76 = V_77 << 1 ;
}
}
static void
F_44 ( int V_1 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_3 -> V_21 = 0 ;
}
void F_45 ( T_1 * V_3 , char * V_87 , struct V_88 * V_89 )
{
int V_90 = 0 ;
int V_91 = V_65 ;
struct V_92 * V_93 = & V_94 ;
switch ( V_3 -> V_23 )
{
case V_95 :
F_46 ( F_2 ( L_6 ) ) ;
V_90 = V_96 ;
break;
case V_97 :
F_46 ( F_2 ( L_7 ) ) ;
V_90 = V_98 ;
V_93 = & V_99 ;
break;
case V_100 :
F_46 ( F_2 ( L_8 ) ) ;
V_90 = V_98 ;
V_93 = & V_101 ;
break;
case V_61 :
case V_62 :
F_46 ( F_2 ( L_9 ) ) ;
V_90 = V_98 ;
V_91 |= V_36 ;
V_93 = & V_102 ;
break;
case V_24 :
F_46 ( F_2 ( L_10 ) ) ;
V_93 = F_47 ( V_3 , & V_90 , & V_91 ) ;
break;
case V_103 :
F_46 ( F_2 ( L_11 ) ) ;
V_90 = V_98 ;
V_91 |= V_36 ;
if ( V_3 -> V_16 != V_3 -> V_15 && V_3 -> V_15 != - 1 )
{
V_90 |= V_104 ;
V_3 -> V_17 = 1 ;
}
V_93 = & V_105 ;
break;
default:
F_46 ( F_2 ( L_12 ) ) ;
V_90 = V_98 ;
V_93 = & V_106 ;
}
if ( V_89 )
V_93 -> V_89 = V_89 ;
if ( ( V_3 -> V_1 = F_48 ( V_107 ,
V_87 , V_93 , sizeof( struct V_92 ) ,
V_90 , V_91 , V_3 ,
V_3 -> V_16 ,
V_3 -> V_17 ? V_3 -> V_15 : V_3 -> V_16 ) ) < 0 )
{
F_2 ( V_6 L_13 ) ;
return;
}
V_4 [ V_3 -> V_1 ] -> V_108 = V_3 -> V_109 ;
V_4 [ V_3 -> V_1 ] -> V_110 = 5 ;
}
