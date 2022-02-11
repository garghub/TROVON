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
{
struct V_29 * V_30 ;
V_30 = V_4 [ V_1 ] -> V_31 ;
V_4 [ V_1 ] -> V_31 = V_4 [ V_1 ] -> V_32 ;
V_4 [ V_1 ] -> V_32 = V_30 ;
}
V_4 [ V_1 ] -> V_31 -> V_33 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_32 -> V_33 = ( V_3 -> V_17 ) ?
V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_15 != - 1 && V_3 -> V_15 != V_3 -> V_16 && ! V_3 -> V_17 )
F_11 ( V_3 -> V_15 ) ;
if ( ( V_3 -> V_26 == V_27 ) && ( V_3 -> V_13 & V_10 ) )
{
F_8 ( V_3 , V_28 ,
F_9 ( V_3 , V_28 ) | 0x06 ) ;
}
V_3 -> V_13 = 0 ;
}
static void F_12 ( int V_1 , unsigned long V_34 , int V_35 ,
int V_36 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_37 == V_38 )
{
V_3 -> V_39 = V_34 ;
V_3 -> V_40 = V_35 ;
V_3 -> V_41 = V_36 ;
V_3 -> V_18 = V_42 ;
}
else
{
V_3 -> V_43 = V_34 ;
V_3 -> V_44 = V_35 ;
V_3 -> V_45 = V_36 ;
V_3 -> V_20 = V_42 ;
}
}
static void F_13 ( int V_1 , unsigned long V_34 , int V_46 , int V_36 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_37 != V_38 )
{
V_3 -> V_39 = V_34 ;
V_3 -> V_40 = V_46 ;
V_3 -> V_41 = V_36 ;
V_3 -> V_18 = V_47 ;
}
else
{
V_3 -> V_43 = V_34 ;
V_3 -> V_44 = V_46 ;
V_3 -> V_45 = V_36 ;
V_3 -> V_20 = V_47 ;
}
}
static void F_14 ( int V_1 , unsigned long V_34 , int V_35 , int V_36 )
{
unsigned long V_5 ;
int V_46 = V_35 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_4 [ V_1 ] -> V_31 -> V_33 > 3 )
V_46 >>= 1 ;
V_46 -- ;
V_3 -> V_18 = V_42 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x14 ) )
{
F_15 ( V_3 , ( unsigned char ) ( V_46 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_46 >> 8 ) & 0xff ) ) ;
}
else
F_2 ( V_48 L_3 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_49 = 1 ;
}
static void F_16 ( int V_1 , unsigned long V_34 , int V_35 , int V_36 )
{
unsigned long V_5 ;
int V_46 = V_35 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_4 [ V_1 ] -> V_31 -> V_33 > 3 )
V_46 >>= 1 ;
V_46 -- ;
V_3 -> V_18 = V_47 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x24 ) )
{
F_15 ( V_3 , ( unsigned char ) ( V_46 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_46 >> 8 ) & 0xff ) ) ;
}
else
F_2 ( V_6 L_4 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_49 = 1 ;
}
static void F_17 ( int V_1 , int V_37 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_37 &= V_3 -> V_18 ;
if ( ! V_37 )
F_15 ( V_3 , 0xd0 ) ;
else
{
switch ( V_3 -> V_18 )
{
case V_47 :
F_16 ( V_1 , V_3 -> V_39 , V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
case V_42 :
F_14 ( V_1 , V_3 -> V_39 , V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
}
}
V_3 -> V_50 = V_37 ;
}
static int F_18 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x40 ) )
F_15 ( V_3 , V_3 -> V_53 ) ;
F_15 ( V_3 , V_54 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_50 = 0 ;
return 0 ;
}
static int F_19 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x40 ) )
F_15 ( V_3 , V_3 -> V_53 ) ;
F_15 ( V_3 , V_55 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_50 = 0 ;
return 0 ;
}
static int F_20 ( int V_1 , int V_56 )
{
int V_57 = 23000 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_58 ;
if ( V_3 -> V_13 & V_10 )
V_57 = 13000 ;
if ( V_56 > 0 )
{
if ( V_56 < 4000 )
V_56 = 4000 ;
if ( V_56 > V_57 )
V_56 = V_57 ;
V_3 -> V_53 = ( 256 - ( ( 1000000 + V_56 / 2 ) / V_56 ) ) & 0xff ;
V_58 = 256 - V_3 -> V_53 ;
V_56 = ( 1000000 + V_58 / 2 ) / V_58 ;
V_3 -> V_56 = V_56 ;
}
return V_3 -> V_56 ;
}
static short F_21 ( int V_1 , short V_59 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
return V_3 -> V_59 = 1 ;
}
static unsigned int F_22 ( int V_1 , unsigned int V_37 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
return V_3 -> V_37 = 8 ;
}
static void F_23 ( int V_1 )
{
unsigned long V_5 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_6 ( V_3 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_24 ( int V_1 , unsigned long V_34 , int V_35 ,
int V_36 )
{
unsigned long V_5 ;
int V_46 = V_35 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned char V_60 ;
if ( V_4 [ V_1 ] -> V_31 -> V_33 > 3 )
V_46 >>= 1 ;
V_46 -- ;
V_3 -> V_18 = V_42 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x48 ) )
{
F_15 ( V_3 , ( unsigned char ) ( V_46 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_46 >> 8 ) & 0xff ) ) ;
if ( V_3 -> V_56 * V_3 -> V_59 <= 23000 )
V_60 = 0x1c ;
else
V_60 = 0x90 ;
if ( ! F_15 ( V_3 , V_60 ) )
F_2 ( V_6 L_3 ) ;
}
else
F_2 ( V_6 L_5 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_49 = 1 ;
}
static void F_25 ( int V_1 , unsigned long V_34 , int V_35 , int V_36 )
{
unsigned long V_5 ;
int V_46 = V_35 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned char V_60 ;
if ( V_4 [ V_1 ] -> V_31 -> V_33 > 3 )
V_46 >>= 1 ;
V_46 -- ;
V_3 -> V_18 = V_47 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x48 ) )
{
F_15 ( V_3 , ( unsigned char ) ( V_46 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_46 >> 8 ) & 0xff ) ) ;
if ( V_3 -> V_56 * V_3 -> V_59 <= ( V_3 -> V_61 == 3 ? 23000 : 13000 ) )
V_60 = 0x2c ;
else
V_60 = 0x98 ;
if ( ! F_15 ( V_3 , V_60 ) )
F_2 ( V_6 L_4 ) ;
}
else
F_2 ( V_6 L_4 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_49 = 1 ;
}
static void F_26 ( int V_1 , int V_37 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_37 &= V_3 -> V_18 ;
if ( ! V_37 )
F_15 ( V_3 , 0xd0 ) ;
else
{
switch ( V_3 -> V_18 )
{
case V_47 :
F_25 ( V_1 , V_3 -> V_39 , V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
case V_42 :
F_24 ( V_1 , V_3 -> V_39 , V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
}
}
V_3 -> V_50 = V_37 ;
}
static int F_27 ( int V_1 , int V_56 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_58 ;
int V_62 = V_56 * V_3 -> V_59 ;
if ( V_56 > 0 )
{
if ( V_56 < 4000 )
V_56 = 4000 ;
if ( V_56 > 44100 )
V_56 = 44100 ;
if ( V_3 -> V_13 & V_10 && V_56 > 15000 )
V_56 = 15000 ;
V_3 -> V_53 = ( 256 - ( ( 1000000 + V_62 / 2 ) / V_62 ) ) & 0xff ;
V_58 = 256 - V_3 -> V_53 ;
V_56 = ( ( 1000000 + V_58 / 2 ) / V_58 ) / V_3 -> V_59 ;
V_3 -> V_56 = V_56 ;
}
return V_3 -> V_56 ;
}
static int F_28 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
unsigned char V_37 = 0 ;
if ( V_3 -> V_15 >= 0 && V_3 -> V_15 != V_3 -> V_16 )
V_4 [ V_1 ] -> V_31 -> V_33 = V_4 [ V_1 ] -> V_32 -> V_33 =
V_3 -> V_37 == 16 ? V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_23 == V_63 || V_3 -> V_23 == V_64 )
if ( V_3 -> V_37 == V_38 )
V_37 = 0x04 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x40 ) )
F_15 ( V_3 , V_3 -> V_53 ) ;
F_15 ( V_3 , V_54 ) ;
if ( V_3 -> V_59 == 1 )
F_15 ( V_3 , 0xa0 | V_37 ) ;
else
F_15 ( V_3 , 0xa8 | V_37 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_50 = 0 ;
return 0 ;
}
static int F_29 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_5 ;
unsigned char V_58 ;
unsigned char V_37 = 0 ;
if ( V_3 -> V_15 >= 0 && V_3 -> V_15 != V_3 -> V_16 )
V_4 [ V_1 ] -> V_31 -> V_33 = V_4 [ V_1 ] -> V_32 -> V_33 = V_3 -> V_37 == 16 ? V_3 -> V_15 : V_3 -> V_16 ;
if ( V_3 -> V_23 == V_65 )
F_30 ( V_3 , V_3 -> V_59 == 2 ) ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( F_15 ( V_3 , 0x40 ) )
F_15 ( V_3 , V_3 -> V_53 ) ;
F_15 ( V_3 , V_55 ) ;
if ( V_3 -> V_23 == V_63 || V_3 -> V_23 == V_64 )
{
if ( V_3 -> V_37 == V_38 )
V_37 = 0x04 ;
if ( V_3 -> V_59 == 1 )
F_15 ( V_3 , 0xa0 | V_37 ) ;
else
F_15 ( V_3 , 0xa8 | V_37 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
else
{
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_58 = F_9 ( V_3 , 0x0e ) ;
if ( V_3 -> V_59 == 1 )
V_58 &= ~ 0x02 ;
else
V_58 |= 0x02 ;
F_8 ( V_3 , 0x0e , V_58 ) ;
}
V_3 -> V_50 = 0 ;
return 0 ;
}
static int F_31 ( int V_1 , int V_56 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_56 > 0 )
{
if ( V_56 < 4000 )
V_56 = 4000 ;
if ( V_56 > 44100 )
V_56 = 44100 ;
if ( V_3 -> V_59 > 1 && V_56 > 22050 )
V_56 = 22050 ;
F_27 ( V_1 , V_56 ) ;
}
return V_3 -> V_56 ;
}
static short F_32 ( int V_1 , short V_59 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_59 == 1 || V_59 == 2 )
{
if ( V_59 != V_3 -> V_59 )
{
V_3 -> V_59 = V_59 ;
if ( V_3 -> V_23 == V_65 && V_3 -> V_59 == 2 )
F_31 ( V_1 , V_3 -> V_56 ) ;
}
}
return V_3 -> V_59 ;
}
static int F_33 ( int V_1 , int V_56 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_56 > 0 )
{
int V_58 ;
int V_62 = V_56 * V_3 -> V_59 ;
if ( V_56 < 5000 )
V_56 = 5000 ;
if ( V_56 > 44100 )
V_56 = 44100 ;
V_3 -> V_53 = ( 256 - ( ( 1000000 + V_62 / 2 ) / V_62 ) ) & 0xff ;
V_58 = 256 - V_3 -> V_53 ;
V_56 = ( ( 1000000 + V_58 / 2 ) / V_58 ) / V_3 -> V_59 ;
V_3 -> V_56 = V_56 ;
}
return V_3 -> V_56 ;
}
static int F_34 ( int V_1 , int V_56 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_57 = V_3 -> V_26 == V_66 ? 48000 : 44100 ;
if ( V_56 > 0 )
{
if ( V_56 < 5000 )
V_56 = 5000 ;
if ( V_56 > V_57 )
V_56 = V_57 ;
V_3 -> V_56 = V_56 ;
}
return V_3 -> V_56 ;
}
static unsigned int F_35 ( int V_1 , unsigned int V_37 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( V_37 != 0 )
{
if ( V_37 == V_67 || V_37 == V_38 )
V_3 -> V_37 = V_37 ;
else
V_3 -> V_37 = V_67 ;
}
return V_3 -> V_37 ;
}
static int F_36 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 )
{
V_4 [ V_1 ] -> V_31 -> V_33 =
V_4 [ V_1 ] -> V_32 -> V_33 =
V_3 -> V_37 == V_38 ?
V_3 -> V_15 : V_3 -> V_16 ;
}
else if ( V_3 -> V_37 == V_38 )
{
V_4 [ V_1 ] -> V_31 -> V_33 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_32 -> V_33 = V_3 -> V_15 ;
}
else
{
V_4 [ V_1 ] -> V_31 -> V_33 = V_3 -> V_15 ;
V_4 [ V_1 ] -> V_32 -> V_33 = V_3 -> V_16 ;
}
V_3 -> V_50 = 0 ;
return 0 ;
}
static int F_37 ( int V_1 , int V_51 , int V_52 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 )
{
V_4 [ V_1 ] -> V_31 -> V_33 =
V_4 [ V_1 ] -> V_32 -> V_33 =
V_3 -> V_37 == V_38 ?
V_3 -> V_15 : V_3 -> V_16 ;
}
else if ( V_3 -> V_37 == V_38 )
{
V_4 [ V_1 ] -> V_31 -> V_33 = V_3 -> V_16 ;
V_4 [ V_1 ] -> V_32 -> V_33 = V_3 -> V_15 ;
}
else
{
V_4 [ V_1 ] -> V_31 -> V_33 = V_3 -> V_15 ;
V_4 [ V_1 ] -> V_32 -> V_33 = V_3 -> V_16 ;
}
V_3 -> V_50 = 0 ;
return 0 ;
}
static void F_38 ( int V_1 , unsigned long V_34 , int V_46 ,
int V_36 )
{
unsigned long V_5 , V_68 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
unsigned long V_37 ;
if ( ! V_3 -> V_21 || V_3 -> V_37 == V_38 )
{
V_3 -> V_18 = V_42 ;
V_3 -> V_49 = 1 ;
}
else
{
V_3 -> V_20 = V_42 ;
V_3 -> V_69 = 1 ;
}
F_3 ( & V_3 -> V_12 , V_5 ) ;
V_37 = V_3 -> V_37 ;
if ( V_3 -> V_21 )
V_3 -> V_37 = ( V_3 -> V_37 == V_38 ) ?
V_67 : V_38 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
V_68 = V_46 ;
if ( V_3 -> V_37 == V_38 )
V_68 >>= 1 ;
V_68 -- ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_15 ( V_3 , 0x41 ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_3 -> V_56 >> 8 ) & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_3 -> V_56 & 0xff ) ) ;
F_15 ( V_3 , ( V_3 -> V_37 == V_38 ? 0xb6 : 0xc6 ) ) ;
F_15 ( V_3 , ( ( V_3 -> V_59 == 2 ? 0x20 : 0 ) +
( V_3 -> V_37 == V_38 ? 0x10 : 0 ) ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_68 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_68 >> 8 ) ) ;
V_3 -> V_37 = V_37 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_39 ( int V_1 , unsigned long V_34 , int V_46 , int V_36 )
{
unsigned long V_5 , V_68 ;
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
if ( ! V_3 -> V_21 || V_3 -> V_37 != V_38 )
{
V_3 -> V_18 = V_47 ;
V_3 -> V_49 = 1 ;
}
else
{
V_3 -> V_20 = V_47 ;
V_3 -> V_69 = 1 ;
}
V_68 = V_46 ;
if ( V_3 -> V_37 == V_38 )
V_68 >>= 1 ;
V_68 -- ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
F_15 ( V_3 , 0x42 ) ;
F_15 ( V_3 , ( unsigned char ) ( ( V_3 -> V_56 >> 8 ) & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_3 -> V_56 & 0xff ) ) ;
F_15 ( V_3 , ( V_3 -> V_37 == V_38 ? 0xbe : 0xce ) ) ;
F_15 ( V_3 , ( ( V_3 -> V_59 == 2 ? 0x20 : 0 ) +
( V_3 -> V_37 == V_38 ? 0x10 : 0 ) ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_68 & 0xff ) ) ;
F_15 ( V_3 , ( unsigned char ) ( V_68 >> 8 ) ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
static void F_40 ( int V_1 , int V_37 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_70 = V_37 & V_3 -> V_20 ;
V_37 &= V_3 -> V_18 ;
if ( ! V_37 && ! V_70 )
F_15 ( V_3 , 0xd0 ) ;
else
{
if ( V_37 )
{
switch ( V_3 -> V_18 )
{
case V_47 :
F_39 ( V_1 ,
V_3 -> V_39 ,
V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
case V_42 :
F_38 ( V_1 ,
V_3 -> V_39 ,
V_3 -> V_40 ,
V_3 -> V_41 ) ;
break;
}
}
if ( V_70 )
{
switch ( V_3 -> V_20 )
{
case V_47 :
F_39 ( V_1 ,
V_3 -> V_43 ,
V_3 -> V_44 ,
V_3 -> V_45 ) ;
break;
case V_42 :
F_38 ( V_1 ,
V_3 -> V_43 ,
V_3 -> V_44 ,
V_3 -> V_45 ) ;
break;
}
}
}
V_3 -> V_50 = V_37 | V_70 ;
}
static void
F_41 ( int V_1 ,
char * V_71 , int V_72 ,
const char T_2 * V_73 , int V_74 ,
int V_75 , int V_76 ,
int * V_77 , int * V_78 ,
int V_79 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
int V_80 , V_81 , V_82 , V_83 ;
unsigned char * V_84 ;
signed short * V_85 ;
if ( ! V_3 -> V_21 )
{
if ( F_42 ( V_71 + V_72 ,
V_73 + V_74 , V_79 ) )
return;
* V_77 = V_79 ;
* V_78 = V_79 ;
}
else if ( V_3 -> V_37 == V_38 )
{
V_79 = ( ( V_75 >> 1 ) > V_76 ) ? V_76 : ( V_75 >> 1 ) ;
V_81 = V_79 ;
V_82 = 0 ;
V_84 = ( unsigned char * ) ( V_71 + V_72 ) ;
while ( V_81 )
{
V_83 = ( V_81 >= V_86 ? V_86 : V_81 ) ;
if ( F_42 ( V_87 ,
V_73 + V_74 + ( V_82 << 1 ) ,
V_83 << 1 ) )
return;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ )
{
V_84 [ V_82 + V_80 ] = ~ ( ( V_87 [ V_80 ] >> 8 ) & 0xff ) ^ 0x80 ;
}
V_81 -= V_83 ; V_82 += V_83 ;
}
* V_77 = V_75 > ( V_76 << 1 ) ? ( V_76 << 1 ) : V_75 ;
* V_78 = V_79 ;
}
else
{
V_79 = V_75 > ( V_76 >> 1 ) ? ( V_76 >> 1 ) : V_75 ;
V_81 = V_79 ;
V_82 = 0 ;
V_85 = ( signed short * ) ( V_71 + V_72 ) ;
while ( V_81 )
{
V_83 = ( V_81 >= V_86 ? V_86 : V_81 ) ;
if ( F_42 ( V_88 ,
V_73 + V_74 + V_82 ,
V_83 ) )
return;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ )
{
V_85 [ V_82 + V_80 ] = ( ~ V_88 [ V_80 ] ^ 0x80 ) << 8 ;
}
V_81 -= V_83 ; V_82 += V_83 ;
}
* V_77 = V_79 ;
* V_78 = V_79 << 1 ;
}
}
static void
F_43 ( int V_1 )
{
T_1 * V_3 = V_4 [ V_1 ] -> V_3 ;
V_3 -> V_21 = 0 ;
}
void F_44 ( T_1 * V_3 , char * V_89 , struct V_90 * V_91 )
{
int V_92 = 0 ;
int V_93 = V_67 ;
struct V_94 * V_95 = & V_96 ;
switch ( V_3 -> V_23 )
{
case V_97 :
F_45 ( F_2 ( L_6 ) ) ;
V_92 = V_98 ;
break;
case V_99 :
F_45 ( F_2 ( L_7 ) ) ;
V_92 = V_100 ;
V_95 = & V_101 ;
break;
case V_102 :
F_45 ( F_2 ( L_8 ) ) ;
V_92 = V_100 ;
V_95 = & V_103 ;
break;
case V_63 :
case V_64 :
F_45 ( F_2 ( L_9 ) ) ;
V_92 = V_100 ;
V_93 |= V_38 ;
V_95 = & V_104 ;
break;
case V_24 :
F_45 ( F_2 ( L_10 ) ) ;
V_95 = F_46 ( V_3 , & V_92 , & V_93 ) ;
break;
case V_105 :
F_45 ( F_2 ( L_11 ) ) ;
V_92 = V_100 ;
V_93 |= V_38 ;
if ( V_3 -> V_16 != V_3 -> V_15 && V_3 -> V_15 != - 1 )
{
V_92 |= V_106 ;
V_3 -> V_17 = 1 ;
}
V_95 = & V_107 ;
break;
default:
F_45 ( F_2 ( L_12 ) ) ;
V_92 = V_100 ;
V_95 = & V_108 ;
}
if ( V_91 )
V_95 -> V_91 = V_91 ;
if ( ( V_3 -> V_1 = F_47 ( V_109 ,
V_89 , V_95 , sizeof( struct V_94 ) ,
V_92 , V_93 , V_3 ,
V_3 -> V_16 ,
V_3 -> V_17 ? V_3 -> V_15 : V_3 -> V_16 ) ) < 0 )
{
F_2 ( V_6 L_13 ) ;
return;
}
V_4 [ V_3 -> V_1 ] -> V_110 = V_3 -> V_111 ;
V_4 [ V_3 -> V_1 ] -> V_112 = 5 ;
}
