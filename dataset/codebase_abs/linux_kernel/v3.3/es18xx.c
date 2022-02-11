static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_4 ;
for( V_4 = V_5 ; V_4 ; V_4 -- )
if ( ( F_2 ( V_2 -> V_6 + 0x0C ) & 0x80 ) == 0 ) {
F_3 ( V_3 , V_2 -> V_6 + 0x0C ) ;
return 0 ;
}
F_4 ( V_7 L_1 , V_3 ) ;
return - V_8 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
for( V_4 = V_5 / 10 ; V_4 ; V_4 -- )
if ( F_2 ( V_2 -> V_6 + 0x0C ) & 0x40 )
return F_2 ( V_2 -> V_6 + 0x0A ) ;
F_4 ( V_7 L_2 ,
V_2 -> V_6 + 0x0A , F_2 ( V_2 -> V_6 + 0x0A ) ) ;
return - V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char V_10 , unsigned char V_11 )
{
unsigned long V_12 ;
int V_13 ;
F_7 ( & V_2 -> V_14 , V_12 ) ;
V_13 = F_1 ( V_2 , V_10 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_1 ( V_2 , V_11 ) ;
V_15:
F_8 ( & V_2 -> V_14 , V_12 ) ;
#ifdef F_9
F_4 ( V_16 L_3 , V_10 , V_11 ) ;
#endif
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned char V_10 )
{
unsigned long V_12 ;
int V_13 , V_11 ;
F_7 ( & V_2 -> V_14 , V_12 ) ;
V_13 = F_1 ( V_2 , 0xC0 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_1 ( V_2 , V_10 ) ;
if ( V_13 < 0 )
goto V_15;
V_11 = F_5 ( V_2 ) ;
V_13 = V_11 ;
#ifdef F_9
F_4 ( V_16 L_4 , V_10 , V_11 , V_13 ) ;
#endif
V_15:
F_8 ( & V_2 -> V_14 , V_12 ) ;
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_17 , unsigned char V_3 )
{
int V_13 ;
unsigned char V_18 , V_19 , V_20 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_14 , V_12 ) ;
V_13 = F_1 ( V_2 , 0xC0 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_1 ( V_2 , V_10 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_5 ( V_2 ) ;
if ( V_13 < 0 ) {
goto V_15;
}
V_18 = V_13 ;
V_20 = V_18 & V_17 ;
if ( V_3 != V_20 ) {
V_13 = F_1 ( V_2 , V_10 ) ;
if ( V_13 < 0 )
goto V_15;
V_19 = ( V_18 & ~ V_17 ) | ( V_3 & V_17 ) ;
V_13 = F_1 ( V_2 , V_19 ) ;
if ( V_13 < 0 )
goto V_15;
#ifdef F_9
F_4 ( V_16 L_5 ,
V_10 , V_18 , V_19 , V_13 ) ;
#endif
}
V_13 = V_20 ;
V_15:
F_8 ( & V_2 -> V_14 , V_12 ) ;
return V_13 ;
}
static inline void F_12 ( struct V_1 * V_2 ,
unsigned char V_10 , unsigned char V_11 )
{
unsigned long V_12 ;
F_7 ( & V_2 -> V_21 , V_12 ) ;
F_3 ( V_10 , V_2 -> V_6 + 0x04 ) ;
F_3 ( V_11 , V_2 -> V_6 + 0x05 ) ;
F_8 ( & V_2 -> V_21 , V_12 ) ;
#ifdef F_9
F_4 ( V_16 L_6 , V_10 , V_11 ) ;
#endif
}
static inline int F_13 ( struct V_1 * V_2 , unsigned char V_10 )
{
unsigned long V_12 ;
int V_11 ;
F_7 ( & V_2 -> V_21 , V_12 ) ;
F_3 ( V_10 , V_2 -> V_6 + 0x04 ) ;
V_11 = F_2 ( V_2 -> V_6 + 0x05 ) ;
F_8 ( & V_2 -> V_21 , V_12 ) ;
#ifdef F_9
F_4 ( V_16 L_7 , V_10 , V_11 ) ;
#endif
return V_11 ;
}
static inline int F_14 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_17 , unsigned char V_3 )
{
unsigned char V_18 , V_19 , V_20 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_21 , V_12 ) ;
F_3 ( V_10 , V_2 -> V_6 + 0x04 ) ;
V_18 = F_2 ( V_2 -> V_6 + 0x05 ) ;
V_20 = V_18 & V_17 ;
if ( V_3 != V_20 ) {
V_19 = ( V_18 & ~ V_17 ) | ( V_3 & V_17 ) ;
F_3 ( V_19 , V_2 -> V_6 + 0x05 ) ;
#ifdef F_9
F_4 ( V_16 L_8 ,
V_10 , V_18 , V_19 ) ;
#endif
}
F_8 ( & V_2 -> V_21 , V_12 ) ;
return V_20 ;
}
static inline int F_15 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_17 )
{
int V_18 , V_22 , V_19 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_21 , V_12 ) ;
F_3 ( V_10 , V_2 -> V_6 + 0x04 ) ;
V_18 = F_2 ( V_2 -> V_6 + 0x05 ) ;
V_22 = V_18 ^ V_17 ;
F_3 ( V_22 , V_2 -> V_6 + 0x05 ) ;
V_19 = F_2 ( V_2 -> V_6 + 0x05 ) ;
F_8 ( & V_2 -> V_21 , V_12 ) ;
#ifdef F_9
F_4 ( V_16 L_9 ,
V_10 , V_18 , V_22 , V_19 ) ;
#endif
return V_22 == V_19 ;
}
static int T_1 F_16 ( struct V_1 * V_2 )
{
int V_4 ;
F_3 ( 0x03 , V_2 -> V_6 + 0x06 ) ;
F_2 ( V_2 -> V_6 + 0x06 ) ;
F_3 ( 0x00 , V_2 -> V_6 + 0x06 ) ;
for( V_4 = 0 ; V_4 < V_5 && ! ( F_2 ( V_2 -> V_6 + 0x0E ) & 0x80 ) ; V_4 ++ ) ;
if ( F_2 ( V_2 -> V_6 + 0x0A ) != 0xAA )
return - 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_3 ( 0x02 , V_2 -> V_6 + 0x06 ) ;
F_2 ( V_2 -> V_6 + 0x06 ) ;
F_3 ( 0x00 , V_2 -> V_6 + 0x06 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_25 )
{
unsigned int V_26 , V_27 ;
struct V_28 * V_29 = V_24 -> V_29 ;
if ( V_2 -> V_30 & V_31 ) {
if ( V_29 -> V_32 == V_33 [ 0 ] . V_34 )
V_26 = 128 - V_29 -> V_35 ;
else
V_26 = 256 - V_29 -> V_35 ;
} else {
if ( V_29 -> V_32 == V_36 [ 0 ] . V_34 )
V_26 = 256 - V_29 -> V_35 ;
else
V_26 = 128 - V_29 -> V_35 ;
}
V_27 = 256 - 7160000 * 20 / ( 8 * 82 * V_29 -> V_37 ) ;
if ( ( V_2 -> V_30 & V_38 ) && V_25 == V_39 ) {
F_12 ( V_2 , 0x70 , V_26 ) ;
F_6 ( V_2 , 0xA2 , V_27 ) ;
F_12 ( V_2 , 0x72 , V_27 ) ;
} else {
F_6 ( V_2 , 0xA1 , V_26 ) ;
F_6 ( V_2 , 0xA2 , V_27 ) ;
}
}
static int F_19 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
int V_42 , V_43 ;
V_42 = 0 ;
if ( F_21 ( V_41 ) == 2 )
V_42 ++ ;
if ( F_22 ( F_23 ( V_41 ) ) == 16 )
V_42 ++ ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) ) {
if ( ( V_2 -> V_30 & V_45 ) &&
( V_2 -> V_46 ) &&
F_21 ( V_41 ) != 1 ) {
F_24 ( V_41 , V_47 ) ;
return - V_48 ;
}
V_2 -> V_49 = V_42 ;
} else {
V_2 -> V_50 = V_42 ;
}
if ( ( V_43 = F_25 ( V_24 , F_26 ( V_41 ) ) ) < 0 )
return V_43 ;
return 0 ;
}
static int F_27 ( struct V_23 * V_24 )
{
return F_28 ( V_24 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_29 ;
unsigned int V_51 = F_30 ( V_24 ) ;
unsigned int V_52 = F_31 ( V_24 ) ;
F_18 ( V_2 , V_24 , V_39 ) ;
V_52 = 0x10000 - V_52 ;
F_12 ( V_2 , 0x74 , V_52 & 0xff ) ;
F_12 ( V_2 , 0x76 , V_52 >> 8 ) ;
F_14 ( V_2 , 0x7A , 0x07 ,
( ( V_29 -> V_53 == 1 ) ? 0x00 : 0x02 ) |
( F_22 ( V_29 -> V_54 ) == 16 ? 0x01 : 0x00 ) |
( F_32 ( V_29 -> V_54 ) ? 0x00 : 0x04 ) ) ;
F_33 ( V_2 -> V_55 , V_29 -> V_56 , V_51 , V_57 | V_58 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_59 )
{
switch ( V_59 ) {
case V_60 :
case V_61 :
if ( V_2 -> V_62 & V_39 )
return 0 ;
V_2 -> V_62 |= V_39 ;
if ( V_2 -> V_55 >= 4 )
F_12 ( V_2 , 0x78 , 0xb3 ) ;
else
F_12 ( V_2 , 0x78 , 0x93 ) ;
#ifdef F_35
F_36 ( 100000 ) ;
if ( V_2 -> V_30 & V_38 )
F_12 ( V_2 , 0x7C , V_2 -> V_63 ) ;
else
F_1 ( V_2 , 0xD1 ) ;
#endif
break;
case V_64 :
case V_65 :
if ( ! ( V_2 -> V_62 & V_39 ) )
return 0 ;
V_2 -> V_62 &= ~ V_39 ;
F_12 ( V_2 , 0x78 , 0x00 ) ;
#ifdef F_35
F_36 ( 25000 ) ;
if ( V_2 -> V_30 & V_38 )
F_12 ( V_2 , 0x7C , 0 ) ;
else
F_1 ( V_2 , 0xD3 ) ;
#endif
break;
default:
return - V_8 ;
}
return 0 ;
}
static int F_37 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
int V_42 , V_43 ;
V_42 = 0 ;
if ( ( V_2 -> V_30 & V_45 ) &&
V_2 -> V_66 &&
F_21 ( V_41 ) != 1 ) {
F_24 ( V_41 , V_47 ) ;
return - V_48 ;
}
if ( F_21 ( V_41 ) == 2 )
V_42 ++ ;
if ( F_22 ( F_23 ( V_41 ) ) == 16 )
V_42 ++ ;
V_2 -> V_50 = V_42 ;
if ( ( V_43 = F_25 ( V_24 , F_26 ( V_41 ) ) ) < 0 )
return V_43 ;
return 0 ;
}
static int F_38 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
struct V_28 * V_29 = V_24 -> V_29 ;
unsigned int V_51 = F_30 ( V_24 ) ;
unsigned int V_52 = F_31 ( V_24 ) ;
F_17 ( V_2 ) ;
F_11 ( V_2 , 0xA8 , 0x03 , V_29 -> V_53 == 1 ? 0x02 : 0x01 ) ;
F_18 ( V_2 , V_24 , V_67 ) ;
V_52 = 0x10000 - V_52 ;
F_6 ( V_2 , 0xA4 , V_52 & 0xff ) ;
F_6 ( V_2 , 0xA5 , V_52 >> 8 ) ;
#ifdef F_35
F_36 ( 100000 ) ;
#endif
F_6 ( V_2 , 0xB7 ,
F_32 ( V_29 -> V_54 ) ? 0x51 : 0x71 ) ;
F_6 ( V_2 , 0xB7 , 0x90 |
( ( V_29 -> V_53 == 1 ) ? 0x40 : 0x08 ) |
( F_22 ( V_29 -> V_54 ) == 16 ? 0x04 : 0x00 ) |
( F_32 ( V_29 -> V_54 ) ? 0x00 : 0x20 ) ) ;
F_33 ( V_2 -> V_68 , V_29 -> V_56 , V_51 , V_69 | V_58 ) ;
return 0 ;
}
static int F_39 ( struct V_23 * V_24 ,
int V_59 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
switch ( V_59 ) {
case V_60 :
case V_61 :
if ( V_2 -> V_62 & V_67 )
return 0 ;
V_2 -> V_62 |= V_67 ;
F_6 ( V_2 , 0xB8 , 0x0f ) ;
break;
case V_64 :
case V_65 :
if ( ! ( V_2 -> V_62 & V_67 ) )
return 0 ;
V_2 -> V_62 &= ~ V_67 ;
F_6 ( V_2 , 0xB8 , 0x00 ) ;
break;
default:
return - V_8 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_29 ;
unsigned int V_51 = F_30 ( V_24 ) ;
unsigned int V_52 = F_31 ( V_24 ) ;
F_17 ( V_2 ) ;
F_11 ( V_2 , 0xA8 , 0x03 , V_29 -> V_53 == 1 ? 0x02 : 0x01 ) ;
F_18 ( V_2 , V_24 , V_70 ) ;
V_52 = 0x10000 - V_52 ;
F_6 ( V_2 , 0xA4 , V_52 & 0xff ) ;
F_6 ( V_2 , 0xA5 , V_52 >> 8 ) ;
F_6 ( V_2 , 0xB6 ,
F_32 ( V_29 -> V_54 ) ? 0x80 : 0x00 ) ;
F_6 ( V_2 , 0xB7 ,
F_32 ( V_29 -> V_54 ) ? 0x51 : 0x71 ) ;
F_6 ( V_2 , 0xB7 , 0x90 |
( V_29 -> V_53 == 1 ? 0x40 : 0x08 ) |
( F_22 ( V_29 -> V_54 ) == 16 ? 0x04 : 0x00 ) |
( F_32 ( V_29 -> V_54 ) ? 0x00 : 0x20 ) ) ;
F_33 ( V_2 -> V_68 , V_29 -> V_56 , V_51 , V_57 | V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_59 )
{
switch ( V_59 ) {
case V_60 :
case V_61 :
if ( V_2 -> V_62 & V_70 )
return 0 ;
V_2 -> V_62 |= V_70 ;
F_6 ( V_2 , 0xB8 , 0x05 ) ;
#ifdef F_35
F_36 ( 100000 ) ;
F_1 ( V_2 , 0xD1 ) ;
#endif
break;
case V_64 :
case V_65 :
if ( ! ( V_2 -> V_62 & V_70 ) )
return 0 ;
V_2 -> V_62 &= ~ V_70 ;
F_6 ( V_2 , 0xB8 , 0x00 ) ;
#ifdef F_35
F_36 ( 25000 ) ;
F_1 ( V_2 , 0xD3 ) ;
#endif
break;
default:
return - V_8 ;
}
return 0 ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) )
return F_29 ( V_2 , V_24 ) ;
else
return F_40 ( V_2 , V_24 ) ;
}
static int F_43 ( struct V_23 * V_24 ,
int V_59 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) )
return F_34 ( V_2 , V_24 , V_59 ) ;
else
return F_41 ( V_2 , V_24 , V_59 ) ;
}
static T_2 F_44 ( int V_71 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
struct V_1 * V_2 = V_74 -> V_75 ;
unsigned char V_76 ;
if ( V_2 -> V_30 & V_77 ) {
V_76 = F_2 ( V_2 -> V_78 + 6 ) ;
} else {
V_76 = F_13 ( V_2 , 0x7f ) >> 4 ;
}
#if 0
else {
status = 0;
if (inb(chip->port + 0x0C) & 0x01)
status |= AUDIO1_IRQ;
if (snd_es18xx_mixer_read(chip, 0x7A) & 0x80)
status |= AUDIO2_IRQ;
if ((chip->caps & ES18XX_HWV) &&
snd_es18xx_mixer_read(chip, 0x64) & 0x10)
status |= HWV_IRQ;
}
#endif
if ( V_76 & V_79 ) {
if ( V_2 -> V_62 & V_39 )
F_45 ( V_2 -> V_66 ) ;
F_14 ( V_2 , 0x7A , 0x80 , 0x00 ) ;
}
if ( V_76 & V_80 ) {
if ( V_2 -> V_62 & V_67 )
F_45 ( V_2 -> V_46 ) ;
else if ( V_2 -> V_62 & V_70 )
F_45 ( V_2 -> V_81 ) ;
F_2 ( V_2 -> V_6 + 0x0E ) ;
}
if ( ( V_76 & V_82 ) && V_2 -> V_83 )
F_46 ( V_71 , V_2 -> V_83 -> V_75 ) ;
if ( V_76 & V_84 ) {
int V_85 = 0 ;
if ( V_2 -> V_30 & V_86 ) {
V_85 = F_13 ( V_2 , 0x64 ) & 0x80 ;
F_47 ( V_74 , V_87 ,
& V_2 -> V_88 -> V_89 ) ;
F_47 ( V_74 , V_87 ,
& V_2 -> V_90 -> V_89 ) ;
}
if ( ! V_85 ) {
F_47 ( V_74 , V_87 ,
& V_2 -> V_91 -> V_89 ) ;
F_47 ( V_74 , V_87 ,
& V_2 -> V_92 -> V_89 ) ;
}
F_12 ( V_2 , 0x66 , 0x00 ) ;
}
return V_93 ;
}
static T_3 F_48 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned int V_51 = F_30 ( V_24 ) ;
int V_94 ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) ) {
if ( ! ( V_2 -> V_62 & V_39 ) )
return 0 ;
V_94 = F_49 ( V_2 -> V_55 , V_51 ) ;
return V_94 >> V_2 -> V_49 ;
} else {
if ( ! ( V_2 -> V_62 & V_70 ) )
return 0 ;
V_94 = F_49 ( V_2 -> V_68 , V_51 ) ;
return V_94 >> V_2 -> V_50 ;
}
}
static T_3 F_50 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned int V_51 = F_30 ( V_24 ) ;
int V_94 ;
if ( ! ( V_2 -> V_62 & V_67 ) )
return 0 ;
V_94 = F_49 ( V_2 -> V_68 , V_51 ) ;
return V_94 >> V_2 -> V_50 ;
}
static int F_51 ( struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_29 ;
struct V_1 * V_2 = F_20 ( V_24 ) ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) ) {
if ( ( V_2 -> V_30 & V_45 ) &&
V_2 -> V_46 &&
V_2 -> V_46 -> V_29 -> V_53 != 1 )
return - V_95 ;
V_2 -> V_66 = V_24 ;
} else if ( V_24 -> V_44 <= 1 ) {
if ( V_2 -> V_46 )
return - V_95 ;
V_2 -> V_81 = V_24 ;
} else {
F_52 () ;
return - V_8 ;
}
V_24 -> V_29 -> V_96 = V_97 ;
F_53 ( V_29 , 0 , V_98 ,
( V_2 -> V_30 & V_31 ) ? & V_99 : & V_100 ) ;
return 0 ;
}
static int F_54 ( struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_29 ;
struct V_1 * V_2 = F_20 ( V_24 ) ;
if ( V_2 -> V_81 )
return - V_95 ;
if ( ( V_2 -> V_30 & V_45 ) &&
V_2 -> V_66 &&
V_2 -> V_66 -> V_29 -> V_53 != 1 )
return - V_95 ;
V_2 -> V_46 = V_24 ;
V_24 -> V_29 -> V_96 = V_101 ;
F_53 ( V_29 , 0 , V_98 ,
( V_2 -> V_30 & V_31 ) ? & V_99 : & V_100 ) ;
return 0 ;
}
static int F_55 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
if ( V_24 -> V_44 == 0 && ( V_2 -> V_30 & V_38 ) )
V_2 -> V_66 = NULL ;
else
V_2 -> V_81 = NULL ;
F_28 ( V_24 ) ;
return 0 ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
V_2 -> V_46 = NULL ;
F_28 ( V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
static char * V_106 [ 5 ] = {
L_10 , L_11 , L_12 , L_13 , L_14
} ;
static char * V_107 [ 8 ] = {
L_10 , L_15 , L_11 , L_16 ,
L_17 , L_14 , L_12 , L_13
} ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_105 -> type = V_108 ;
V_105 -> V_52 = 1 ;
switch ( V_2 -> V_109 ) {
case 0x1868 :
case 0x1878 :
V_105 -> V_110 . V_111 . V_112 = 4 ;
if ( V_105 -> V_110 . V_111 . V_113 > 3 )
V_105 -> V_110 . V_111 . V_113 = 3 ;
strcpy ( V_105 -> V_110 . V_111 . V_114 ,
V_106 [ V_105 -> V_110 . V_111 . V_113 ] ) ;
break;
case 0x1887 :
case 0x1888 :
V_105 -> V_110 . V_111 . V_112 = 5 ;
if ( V_105 -> V_110 . V_111 . V_113 > 4 )
V_105 -> V_110 . V_111 . V_113 = 4 ;
strcpy ( V_105 -> V_110 . V_111 . V_114 , V_106 [ V_105 -> V_110 . V_111 . V_113 ] ) ;
break;
case 0x1869 :
case 0x1879 :
V_105 -> V_110 . V_111 . V_112 = 8 ;
if ( V_105 -> V_110 . V_111 . V_113 > 7 )
V_105 -> V_110 . V_111 . V_113 = 7 ;
strcpy ( V_105 -> V_110 . V_111 . V_114 , V_107 [ V_105 -> V_110 . V_111 . V_113 ] ) ;
break;
default:
return - V_8 ;
}
return 0 ;
}
static int F_59 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
static unsigned char V_117 [ 8 ] = { 0 , 0 , 1 , 1 , 0 , 0 , 2 , 3 } ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_118 = F_13 ( V_2 , 0x1c ) & 0x07 ;
if ( ! ( V_2 -> V_109 == 0x1869 || V_2 -> V_109 == 0x1879 ) ) {
V_118 = V_117 [ V_118 ] ;
if ( V_118 == 3 &&
( V_2 -> V_109 == 0x1887 || V_2 -> V_109 == 0x1888 ) &&
( F_13 ( V_2 , 0x7a ) & 0x08 )
)
V_118 = 4 ;
}
V_116 -> V_110 . V_111 . V_113 [ 0 ] = V_118 ;
return 0 ;
}
static int F_60 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
static unsigned char V_119 [ 4 ] = { 0 , 2 , 6 , 7 } ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_3 = V_116 -> V_110 . V_111 . V_113 [ 0 ] ;
unsigned char V_120 = 0 ;
switch ( V_2 -> V_109 ) {
case 0x1887 :
case 0x1888 :
if ( V_3 > 4 )
return - V_8 ;
if ( V_3 == 4 ) {
V_120 = F_14 ( V_2 , 0x7a , 0x08 , 0x08 ) != 0x08 ;
V_3 = 3 ;
} else
V_120 = F_14 ( V_2 , 0x7a , 0x08 , 0x00 ) != 0x00 ;
case 0x1868 :
case 0x1878 :
if ( V_3 > 3 )
return - V_8 ;
V_3 = V_119 [ V_3 ] ;
break;
case 0x1869 :
case 0x1879 :
if ( V_3 > 7 )
return - V_8 ;
break;
default:
return - V_8 ;
}
return ( F_14 ( V_2 , 0x1c , 0x07 , V_3 ) != V_3 ) || V_120 ;
}
static int F_61 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_3 = F_13 ( V_2 , 0x50 ) ;
V_116 -> V_110 . integer . V_110 [ 0 ] = ! ! ( V_3 & 8 ) ;
return 0 ;
}
static int F_62 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_20 , V_121 ;
int V_122 ;
V_121 = V_116 -> V_110 . integer . V_110 [ 0 ] ? 0x0c : 0x04 ;
V_20 = F_13 ( V_2 , 0x50 ) & 0x0c ;
V_122 = V_121 != V_20 ;
if ( V_122 ) {
F_12 ( V_2 , 0x50 , V_121 & ~ 0x04 ) ;
F_12 ( V_2 , 0x50 , V_121 ) ;
}
return V_122 ;
}
static int F_63 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
V_105 -> type = V_123 ;
V_105 -> V_52 = 2 ;
V_105 -> V_110 . integer . V_124 = 0 ;
V_105 -> V_110 . integer . V_125 = 63 ;
return 0 ;
}
static int F_64 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_116 -> V_110 . integer . V_110 [ 0 ] = F_13 ( V_2 , 0x61 ) & 0x3f ;
V_116 -> V_110 . integer . V_110 [ 1 ] = F_13 ( V_2 , 0x63 ) & 0x3f ;
return 0 ;
}
static int F_65 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_116 -> V_110 . integer . V_110 [ 0 ] = ! ( F_13 ( V_2 , 0x61 ) & 0x40 ) ;
V_116 -> V_110 . integer . V_110 [ 1 ] = ! ( F_13 ( V_2 , 0x63 ) & 0x40 ) ;
return 0 ;
}
static void F_66 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_2 -> V_92 = NULL ;
V_2 -> V_91 = NULL ;
V_2 -> V_90 = NULL ;
V_2 -> V_88 = NULL ;
}
static int F_67 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_17 , unsigned char V_3 )
{
if ( V_10 < 0xa0 )
return F_14 ( V_2 , V_10 , V_17 , V_3 ) ;
else
return F_11 ( V_2 , V_10 , V_17 , V_3 ) ;
}
static int F_68 ( struct V_1 * V_2 , unsigned char V_10 )
{
if ( V_10 < 0xa0 )
return F_13 ( V_2 , V_10 ) ;
else
return F_10 ( V_2 , V_10 ) ;
}
static int F_69 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
int V_17 = ( V_103 -> V_126 >> 16 ) & 0xff ;
V_105 -> type = V_17 == 1 ? V_127 : V_123 ;
V_105 -> V_52 = 1 ;
V_105 -> V_110 . integer . V_124 = 0 ;
V_105 -> V_110 . integer . V_125 = V_17 ;
return 0 ;
}
static int F_70 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_10 = V_103 -> V_126 & 0xff ;
int V_42 = ( V_103 -> V_126 >> 8 ) & 0xff ;
int V_17 = ( V_103 -> V_126 >> 16 ) & 0xff ;
int V_128 = ( V_103 -> V_126 >> 24 ) & 0xff ;
int V_3 ;
V_3 = F_68 ( V_2 , V_10 ) ;
V_116 -> V_110 . integer . V_110 [ 0 ] = ( V_3 >> V_42 ) & V_17 ;
if ( V_128 )
V_116 -> V_110 . integer . V_110 [ 0 ] = V_17 - V_116 -> V_110 . integer . V_110 [ 0 ] ;
return 0 ;
}
static int F_71 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_10 = V_103 -> V_126 & 0xff ;
int V_42 = ( V_103 -> V_126 >> 8 ) & 0xff ;
int V_17 = ( V_103 -> V_126 >> 16 ) & 0xff ;
int V_128 = ( V_103 -> V_126 >> 24 ) & 0xff ;
unsigned char V_3 ;
V_3 = ( V_116 -> V_110 . integer . V_110 [ 0 ] & V_17 ) ;
if ( V_128 )
V_3 = V_17 - V_3 ;
V_17 <<= V_42 ;
V_3 <<= V_42 ;
return F_67 ( V_2 , V_10 , V_17 , V_3 ) != V_3 ;
}
static int F_72 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
int V_17 = ( V_103 -> V_126 >> 24 ) & 0xff ;
V_105 -> type = V_17 == 1 ? V_127 : V_123 ;
V_105 -> V_52 = 2 ;
V_105 -> V_110 . integer . V_124 = 0 ;
V_105 -> V_110 . integer . V_125 = V_17 ;
return 0 ;
}
static int F_73 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_129 = V_103 -> V_126 & 0xff ;
int V_130 = ( V_103 -> V_126 >> 8 ) & 0xff ;
int V_131 = ( V_103 -> V_126 >> 16 ) & 0x07 ;
int V_132 = ( V_103 -> V_126 >> 19 ) & 0x07 ;
int V_17 = ( V_103 -> V_126 >> 24 ) & 0xff ;
int V_128 = ( V_103 -> V_126 >> 22 ) & 1 ;
unsigned char V_133 , V_134 ;
V_133 = F_68 ( V_2 , V_129 ) ;
if ( V_129 != V_130 )
V_134 = F_68 ( V_2 , V_130 ) ;
else
V_134 = V_133 ;
V_116 -> V_110 . integer . V_110 [ 0 ] = ( V_133 >> V_131 ) & V_17 ;
V_116 -> V_110 . integer . V_110 [ 1 ] = ( V_134 >> V_132 ) & V_17 ;
if ( V_128 ) {
V_116 -> V_110 . integer . V_110 [ 0 ] = V_17 - V_116 -> V_110 . integer . V_110 [ 0 ] ;
V_116 -> V_110 . integer . V_110 [ 1 ] = V_17 - V_116 -> V_110 . integer . V_110 [ 1 ] ;
}
return 0 ;
}
static int F_74 ( struct V_102 * V_103 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_129 = V_103 -> V_126 & 0xff ;
int V_130 = ( V_103 -> V_126 >> 8 ) & 0xff ;
int V_131 = ( V_103 -> V_126 >> 16 ) & 0x07 ;
int V_132 = ( V_103 -> V_126 >> 19 ) & 0x07 ;
int V_17 = ( V_103 -> V_126 >> 24 ) & 0xff ;
int V_128 = ( V_103 -> V_126 >> 22 ) & 1 ;
int V_122 ;
unsigned char V_135 , V_136 , V_137 , V_138 ;
V_135 = V_116 -> V_110 . integer . V_110 [ 0 ] & V_17 ;
V_136 = V_116 -> V_110 . integer . V_110 [ 1 ] & V_17 ;
if ( V_128 ) {
V_135 = V_17 - V_135 ;
V_136 = V_17 - V_136 ;
}
V_135 <<= V_131 ;
V_136 <<= V_132 ;
V_137 = V_17 << V_131 ;
V_138 = V_17 << V_132 ;
if ( V_129 != V_130 ) {
V_122 = 0 ;
if ( F_67 ( V_2 , V_129 , V_137 , V_135 ) != V_135 )
V_122 = 1 ;
if ( F_67 ( V_2 , V_130 , V_138 , V_136 ) != V_136 )
V_122 = 1 ;
} else {
V_122 = ( F_67 ( V_2 , V_129 , V_137 | V_138 ,
V_135 | V_136 ) != ( V_135 | V_136 ) ) ;
}
return V_122 ;
}
static int T_1 F_75 ( struct V_1 * V_2 , unsigned char V_10 )
{
int V_11 ;
F_3 ( V_10 , V_2 -> V_78 ) ;
V_11 = F_2 ( V_2 -> V_78 + 1 ) ;
return V_11 ;
}
static void T_1 F_76 ( struct V_1 * V_2 ,
unsigned char V_10 , unsigned char V_11 )
{
F_3 ( V_10 , V_2 -> V_78 ) ;
F_3 ( V_11 , V_2 -> V_78 + 1 ) ;
#ifdef F_9
F_4 ( V_16 L_18 , V_10 , V_11 ) ;
#endif
}
static int T_1 F_77 ( struct V_1 * V_2 ,
unsigned long V_139 ,
unsigned long V_140 )
{
int V_17 = 0 ;
F_1 ( V_2 , 0xC6 ) ;
F_12 ( V_2 , 0x00 , 0x00 ) ;
F_6 ( V_2 , 0xB9 , 2 ) ;
if ( V_2 -> V_30 & V_77 ) {
F_76 ( V_2 , 0x27 , V_2 -> V_71 ) ;
if ( V_140 > 0 && V_140 != V_141 ) {
F_76 ( V_2 , 0x62 , V_140 >> 8 ) ;
F_76 ( V_2 , 0x63 , V_140 & 0xff ) ;
}
if ( V_139 > 0 && V_139 != V_141 ) {
F_76 ( V_2 , 0x64 , V_139 >> 8 ) ;
F_76 ( V_2 , 0x65 , V_139 & 0xff ) ;
F_76 ( V_2 , 0x28 , V_2 -> V_71 ) ;
}
F_76 ( V_2 , 0x70 , V_2 -> V_71 ) ;
F_76 ( V_2 , 0x72 , V_2 -> V_71 ) ;
F_76 ( V_2 , 0x74 , V_2 -> V_68 ) ;
F_76 ( V_2 , 0x75 , V_2 -> V_55 ) ;
F_6 ( V_2 , 0xB1 , 0x50 ) ;
F_12 ( V_2 , 0x7A , 0x40 ) ;
F_6 ( V_2 , 0xB2 , 0x50 ) ;
F_12 ( V_2 , 0x64 , 0x42 ) ;
F_14 ( V_2 , 0x48 , 0x10 , 0x10 ) ;
}
else {
int V_142 , V_143 , V_144 ;
switch ( V_2 -> V_71 ) {
case 2 :
case 9 :
V_142 = 0 ;
break;
case 5 :
V_142 = 1 ;
break;
case 7 :
V_142 = 2 ;
break;
case 10 :
V_142 = 3 ;
break;
default:
F_4 ( V_7 L_19 , V_2 -> V_71 ) ;
return - V_9 ;
}
switch ( V_2 -> V_68 ) {
case 0 :
V_143 = 1 ;
break;
case 1 :
V_143 = 2 ;
break;
case 3 :
V_143 = 3 ;
break;
default:
F_4 ( V_7 L_20 , V_2 -> V_68 ) ;
return - V_9 ;
}
switch ( V_2 -> V_55 ) {
case 0 :
V_144 = 0 ;
break;
case 1 :
V_144 = 1 ;
break;
case 3 :
V_144 = 2 ;
break;
case 5 :
V_144 = 3 ;
break;
default:
F_4 ( V_7 L_21 , V_2 -> V_55 ) ;
return - V_9 ;
}
F_6 ( V_2 , 0xB1 , 0x50 | ( V_142 << 2 ) ) ;
F_6 ( V_2 , 0xB2 , 0x50 | ( V_143 << 2 ) ) ;
F_14 ( V_2 , 0x7d , 0x07 , 0x04 | V_144 ) ;
F_12 ( V_2 , 0x7A , 0x68 ) ;
F_12 ( V_2 , 0x64 , 0x06 ) ;
if ( V_139 > 0 && V_139 != V_141 ) {
F_12 ( V_2 , 0x40 ,
0x43 | ( V_139 & 0xf0 ) >> 1 ) ;
}
F_12 ( V_2 , 0x7f , ( ( V_142 + 1 ) << 1 ) | 0x01 ) ;
}
if ( V_2 -> V_30 & V_31 ) {
F_12 ( V_2 , 0x71 , 0x32 ) ;
}
if ( ! ( V_2 -> V_30 & V_38 ) ) {
F_6 ( V_2 , 0xB7 , 0x80 ) ;
}
if ( V_2 -> V_30 & V_145 ) {
F_12 ( V_2 , 0x54 , 0x8f ) ;
F_12 ( V_2 , 0x56 , 0x95 ) ;
F_12 ( V_2 , 0x58 , 0x94 ) ;
F_12 ( V_2 , 0x5a , 0x80 ) ;
}
switch ( V_2 -> V_109 ) {
case 0x1879 :
case 0x1878 :
F_76 ( V_2 , 0x29 , F_75 ( V_2 , 0x29 ) | 0x40 ) ;
break;
}
if ( V_2 -> V_30 & V_146 )
V_17 = 0x10 ;
if ( V_2 -> V_30 & V_147 )
F_12 ( V_2 , 0x1c , 0x05 | V_17 ) ;
else {
F_12 ( V_2 , 0x1c , 0x00 | V_17 ) ;
F_6 ( V_2 , 0xb4 , 0x00 ) ;
}
#ifndef F_35
F_1 ( V_2 , 0xD1 ) ;
#endif
return 0 ;
}
static int T_1 F_78 ( struct V_1 * V_2 )
{
int V_148 , V_149 ;
if ( F_16 ( V_2 ) < 0 ) {
F_4 ( V_7 L_22 , V_2 -> V_6 ) ;
return - V_9 ;
}
F_1 ( V_2 , 0xe7 ) ;
V_148 = F_5 ( V_2 ) ;
if ( V_148 < 0 ) {
return V_148 ;
}
V_149 = F_5 ( V_2 ) ;
if ( ( V_149 & 0xf0 ) != 0x80 ) {
return - V_9 ;
}
if ( V_148 == 0x48 ) {
V_2 -> V_109 = 0x488 ;
return 0 ;
}
if ( V_148 != 0x68 ) {
return - V_9 ;
}
if ( ( V_149 & 0x0f ) < 8 ) {
V_2 -> V_109 = 0x688 ;
return 0 ;
}
F_3 ( 0x40 , V_2 -> V_6 + 0x04 ) ;
F_36 ( 10 ) ;
V_148 = F_2 ( V_2 -> V_6 + 0x05 ) ;
F_36 ( 10 ) ;
V_149 = F_2 ( V_2 -> V_6 + 0x05 ) ;
if ( V_148 != V_149 ) {
V_2 -> V_109 = V_148 << 8 | V_149 ;
V_2 -> V_78 = F_2 ( V_2 -> V_6 + 0x05 ) << 8 ;
F_36 ( 10 ) ;
V_2 -> V_78 += F_2 ( V_2 -> V_6 + 0x05 ) ;
if ( ( V_2 -> V_150 = F_79 ( V_2 -> V_78 , 8 , L_23 ) ) == NULL ) {
F_4 (KERN_ERR PFX L_24 , chip->ctrl_port) ;
return - V_48 ;
}
return 0 ;
}
if ( F_15 ( V_2 , 0x64 , 0x04 ) ) {
if ( F_15 ( V_2 , 0x70 , 0x7f ) ) {
if ( F_15 ( V_2 , 0x64 , 0x20 ) ) {
V_2 -> V_109 = 0x1887 ;
} else {
V_2 -> V_109 = 0x1888 ;
}
} else {
V_2 -> V_109 = 0x1788 ;
}
}
else
V_2 -> V_109 = 0x1688 ;
return 0 ;
}
static int T_1 F_80 ( struct V_1 * V_2 ,
unsigned long V_139 ,
unsigned long V_140 )
{
if ( F_78 ( V_2 ) < 0 ) {
F_4 (KERN_ERR PFX L_25 , chip->port) ;
return - V_9 ;
}
switch ( V_2 -> V_109 ) {
case 0x1868 :
V_2 -> V_30 = V_45 | V_151 | V_77 ;
break;
case 0x1869 :
V_2 -> V_30 = V_38 | V_145 | V_147 | V_31 | V_152 | V_153 | V_146 | V_77 | V_86 ;
break;
case 0x1878 :
V_2 -> V_30 = V_45 | V_151 | V_154 | V_77 ;
break;
case 0x1879 :
V_2 -> V_30 = V_38 | V_145 | V_147 | V_31 | V_152 | V_154 | V_77 | V_86 ;
break;
case 0x1887 :
case 0x1888 :
V_2 -> V_30 = V_38 | V_147 | V_152 | V_151 ;
break;
default:
F_4 ( V_7 L_26 ,
V_2 -> V_6 , V_2 -> V_109 ) ;
return - V_9 ;
}
F_81 ( L_27 , V_2 -> V_6 , V_2 -> V_109 ) ;
if ( V_2 -> V_68 == V_2 -> V_55 )
V_2 -> V_30 &= ~ ( V_38 | V_151 ) ;
return F_77 ( V_2 , V_139 , V_140 ) ;
}
static int T_1 F_82 ( struct V_73 * V_74 , int V_155 ,
struct V_156 * * V_157 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_156 * V_158 ;
char V_159 [ 16 ] ;
int V_43 ;
if ( V_157 )
* V_157 = NULL ;
sprintf ( V_159 , L_28 , V_2 -> V_109 ) ;
if ( V_2 -> V_30 & V_38 )
V_43 = F_83 ( V_74 , V_159 , V_155 , 2 , 1 , & V_158 ) ;
else
V_43 = F_83 ( V_74 , V_159 , V_155 , 1 , 1 , & V_158 ) ;
if ( V_43 < 0 )
return V_43 ;
F_84 ( V_158 , V_160 , & V_161 ) ;
F_84 ( V_158 , V_162 , & V_163 ) ;
V_158 -> V_75 = V_2 ;
V_158 -> V_164 = 0 ;
if ( V_2 -> V_30 & V_151 )
V_158 -> V_164 |= V_165 ;
if ( ! ( V_2 -> V_30 & V_38 ) )
V_158 -> V_164 |= V_166 ;
sprintf ( V_158 -> V_114 , L_29 , V_2 -> V_109 ) ;
V_2 -> V_158 = V_158 ;
F_85 ( V_158 , V_167 ,
F_86 () ,
64 * 1024 ,
V_2 -> V_68 > 3 || V_2 -> V_55 > 3 ? 128 * 1024 : 64 * 1024 ) ;
if ( V_157 )
* V_157 = V_158 ;
return 0 ;
}
static int F_87 ( struct V_73 * V_74 , T_4 V_168 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_88 ( V_74 , V_169 ) ;
F_89 ( V_2 -> V_158 ) ;
V_2 -> V_170 = ( unsigned char ) F_10 ( V_2 , V_171 ) ;
V_2 -> V_170 |= ( V_172 | V_173 ) ;
F_6 ( V_2 , V_171 , V_2 -> V_170 ) ;
F_6 ( V_2 , V_171 , V_2 -> V_170 ^= V_173 ) ;
return 0 ;
}
static int F_90 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_6 ( V_2 , V_171 , V_2 -> V_170 ^= V_172 ) ;
F_88 ( V_74 , V_174 ) ;
return 0 ;
}
static int F_91 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_92 ( V_2 -> V_175 ) ;
F_92 ( V_2 -> V_150 ) ;
F_92 ( V_2 -> V_176 ) ;
if ( V_2 -> V_71 >= 0 )
F_93 ( V_2 -> V_71 , ( void * ) V_74 ) ;
if ( V_2 -> V_68 >= 0 ) {
F_94 ( V_2 -> V_68 ) ;
F_95 ( V_2 -> V_68 ) ;
}
if ( V_2 -> V_55 >= 0 && V_2 -> V_68 != V_2 -> V_55 ) {
F_94 ( V_2 -> V_55 ) ;
F_95 ( V_2 -> V_55 ) ;
}
return 0 ;
}
static int F_96 ( struct V_177 * V_155 )
{
return F_91 ( V_155 -> V_74 ) ;
}
static int T_1 F_97 ( struct V_73 * V_74 ,
unsigned long V_6 ,
unsigned long V_139 ,
unsigned long V_140 ,
int V_71 , int V_68 , int V_55 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
static struct V_178 V_179 = {
. V_180 = F_96 ,
} ;
int V_43 ;
F_98 ( & V_2 -> V_14 ) ;
F_98 ( & V_2 -> V_21 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_71 = - 1 ;
V_2 -> V_68 = - 1 ;
V_2 -> V_55 = - 1 ;
V_2 -> V_63 = 0x00 ;
V_2 -> V_62 = 0 ;
V_2 -> V_175 = F_79 ( V_6 , 16 , L_30 ) ;
if ( V_2 -> V_175 == NULL ) {
F_91 ( V_74 ) ;
F_4 (KERN_ERR PFX L_31 , port, port + 16 - 1 ) ;
return - V_48 ;
}
if ( F_99 ( V_71 , F_44 , 0 , L_30 ,
( void * ) V_74 ) ) {
F_91 ( V_74 ) ;
F_4 (KERN_ERR PFX L_32 , irq) ;
return - V_48 ;
}
V_2 -> V_71 = V_71 ;
if ( F_100 ( V_68 , L_33 ) ) {
F_91 ( V_74 ) ;
F_4 (KERN_ERR PFX L_34 , dma1) ;
return - V_48 ;
}
V_2 -> V_68 = V_68 ;
if ( V_55 != V_68 && F_100 ( V_55 , L_35 ) ) {
F_91 ( V_74 ) ;
F_4 (KERN_ERR PFX L_36 , dma2) ;
return - V_48 ;
}
V_2 -> V_55 = V_55 ;
if ( F_80 ( V_2 , V_139 , V_140 ) < 0 ) {
F_91 ( V_74 ) ;
return - V_9 ;
}
V_43 = F_101 ( V_74 , V_181 , V_2 , & V_179 ) ;
if ( V_43 < 0 ) {
F_91 ( V_74 ) ;
return V_43 ;
}
return 0 ;
}
static int T_1 F_102 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
int V_43 ;
unsigned int V_182 ;
strcpy ( V_74 -> V_183 , V_2 -> V_158 -> V_114 ) ;
for ( V_182 = 0 ; V_182 < F_103 ( V_184 ) ; V_182 ++ ) {
struct V_102 * V_185 ;
V_185 = F_104 ( & V_184 [ V_182 ] , V_2 ) ;
if ( V_2 -> V_30 & V_86 ) {
switch ( V_182 ) {
case 0 :
V_2 -> V_92 = V_185 ;
V_185 -> V_186 = F_66 ;
break;
case 1 :
V_2 -> V_91 = V_185 ;
V_185 -> V_186 = F_66 ;
break;
}
}
if ( ( V_43 = F_105 ( V_74 , V_185 ) ) < 0 )
return V_43 ;
}
if ( V_2 -> V_30 & V_38 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_187 ) ; V_182 ++ ) {
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_187 [ V_182 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
} else {
for ( V_182 = 0 ; V_182 < F_103 ( V_188 ) ; V_182 ++ ) {
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_188 [ V_182 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_30 & V_147 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_189 ) ; V_182 ++ ) {
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_189 [ V_182 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
switch ( V_2 -> V_109 ) {
default:
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_190 , V_2 ) ) ) < 0 )
return V_43 ;
break;
case 0x1869 :
case 0x1879 :
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_191 , V_2 ) ) ) < 0 )
return V_43 ;
break;
}
if ( V_2 -> V_30 & V_145 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_192 ) ; V_182 ++ ) {
if ( ( V_43 = F_105 ( V_74 , F_104 ( & V_192 [ V_182 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_30 & V_86 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_193 ) ; V_182 ++ ) {
struct V_102 * V_185 ;
V_185 = F_104 ( & V_193 [ V_182 ] , V_2 ) ;
if ( V_182 == 0 )
V_2 -> V_90 = V_185 ;
else
V_2 -> V_88 = V_185 ;
V_185 -> V_186 = F_66 ;
if ( ( V_43 = F_105 ( V_74 , V_185 ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_109 != 0x1868 ) {
V_43 = F_105 ( V_74 , F_104 ( & V_194 ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_2 -> V_109 == 0x1869 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_195 ) ; V_182 ++ ) {
V_43 = F_105 ( V_74 ,
F_104 ( & V_195 [ V_182 ] ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
} else if ( V_2 -> V_109 == 0x1878 ) {
V_43 = F_105 ( V_74 , F_104 ( & V_196 ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
} else if ( V_2 -> V_109 == 0x1879 ) {
for ( V_182 = 0 ; V_182 < F_103 ( V_197 ) ; V_182 ++ ) {
V_43 = F_105 ( V_74 ,
F_104 ( & V_197 [ V_182 ] ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
return 0 ;
}
static int T_1 F_106 ( int V_198 , struct V_199 * V_200 )
{
if ( F_107 ( V_200 ) < 0 ) {
F_4 (KERN_ERR PFX L_37 ) ;
return - V_48 ;
}
if ( F_108 ( V_200 ) ) {
F_109 ( F_110 ( V_200 ) , F_111 ( V_200 ) ) ;
F_112 ( 0x27 , F_113 ( V_200 , 0 ) ) ;
if ( V_139 [ V_198 ] != V_141 )
F_112 ( 0x28 , F_113 ( V_200 , 0 ) ) ;
F_112 ( 0x72 , F_113 ( V_200 , 0 ) ) ;
F_114 () ;
}
V_6 [ V_198 ] = F_115 ( V_200 , 0 ) ;
V_140 [ V_198 ] = F_115 ( V_200 , 1 ) ;
V_139 [ V_198 ] = F_115 ( V_200 , 2 ) ;
V_68 [ V_198 ] = F_116 ( V_200 , 0 ) ;
V_55 [ V_198 ] = F_116 ( V_200 , 1 ) ;
V_71 [ V_198 ] = F_113 ( V_200 , 0 ) ;
F_117 ( L_38 , V_6 [ V_198 ] , V_140 [ V_198 ] , V_139 [ V_198 ] ) ;
F_117 ( L_39 , V_68 [ V_198 ] , V_55 [ V_198 ] , V_71 [ V_198 ] ) ;
return 0 ;
}
static int T_1 F_118 ( int V_198 , struct V_1 * V_2 ,
struct V_199 * V_200 )
{
V_2 -> V_198 = V_200 ;
if ( F_106 ( V_198 , V_2 -> V_198 ) < 0 )
return - V_48 ;
return 0 ;
}
static int T_1 F_119 ( int V_198 , struct V_1 * V_2 ,
struct V_201 * V_74 ,
const struct V_202 * V_89 )
{
V_2 -> V_198 = F_120 ( V_74 , V_89 -> V_203 [ 0 ] . V_89 , NULL ) ;
if ( V_2 -> V_198 == NULL )
return - V_48 ;
V_2 -> V_204 = F_120 ( V_74 , V_89 -> V_203 [ 1 ] . V_89 , NULL ) ;
if ( V_2 -> V_204 == NULL )
return - V_48 ;
if ( F_107 ( V_2 -> V_204 ) < 0 ) {
F_4 (KERN_ERR PFX L_40 ) ;
return - V_95 ;
}
F_117 ( L_41 ,
( unsigned long long ) F_115 ( V_2 -> V_204 , 0 ) ) ;
if ( F_106 ( V_198 , V_2 -> V_198 ) < 0 )
return - V_48 ;
return 0 ;
}
static int F_121 ( int V_198 , struct V_73 * * V_205 )
{
return F_122 ( V_206 [ V_198 ] , V_89 [ V_198 ] , V_207 ,
sizeof( struct V_1 ) , V_205 ) ;
}
static int T_1 F_123 ( struct V_73 * V_74 , int V_198 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_208 * V_209 ;
int V_43 ;
V_43 = F_97 ( V_74 ,
V_6 [ V_198 ] , V_139 [ V_198 ] , V_140 [ V_198 ] ,
V_71 [ V_198 ] , V_68 [ V_198 ] , V_55 [ V_198 ] ) ;
if ( V_43 < 0 )
return V_43 ;
sprintf ( V_74 -> V_210 , L_28 , V_2 -> V_109 ) ;
sprintf ( V_74 -> V_211 , L_29 , V_2 -> V_109 ) ;
if ( V_68 [ V_198 ] != V_55 [ V_198 ] )
sprintf ( V_74 -> V_212 , L_42 ,
V_74 -> V_211 ,
V_2 -> V_6 ,
V_71 [ V_198 ] , V_68 [ V_198 ] , V_55 [ V_198 ] ) ;
else
sprintf ( V_74 -> V_212 , L_43 ,
V_74 -> V_211 ,
V_2 -> V_6 ,
V_71 [ V_198 ] , V_68 [ V_198 ] ) ;
V_43 = F_82 ( V_74 , 0 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_102 ( V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_140 [ V_198 ] > 0 && V_140 [ V_198 ] != V_141 ) {
if ( F_124 ( V_74 , V_140 [ V_198 ] , V_140 [ V_198 ] + 2 ,
V_213 , 0 , & V_209 ) < 0 ) {
F_4 (KERN_WARNING PFX
L_44 ,
fm_port[dev]) ;
} else {
V_43 = F_125 ( V_209 , 0 , 1 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_139 [ V_198 ] > 0 && V_139 [ V_198 ] != V_141 ) {
V_43 = F_126 ( V_74 , 0 , V_214 ,
V_139 [ V_198 ] , V_215 ,
- 1 , & V_2 -> V_83 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return F_127 ( V_74 ) ;
}
static int T_1 F_128 ( struct V_155 * V_200 , unsigned int V_198 )
{
return V_216 [ V_198 ] && ! F_129 ( V_198 ) ;
}
static int T_1 F_130 ( int V_198 , struct V_155 * V_217 )
{
struct V_73 * V_74 ;
int V_43 ;
V_43 = F_121 ( V_198 , & V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
F_131 ( V_74 , V_217 ) ;
if ( ( V_43 = F_123 ( V_74 , V_198 ) ) < 0 ) {
F_132 ( V_74 ) ;
return V_43 ;
}
F_133 ( V_217 , V_74 ) ;
return 0 ;
}
static int T_1 F_134 ( struct V_155 * V_200 , unsigned int V_198 )
{
int V_43 ;
static int V_218 [] = { 5 , 9 , 10 , 7 , 11 , 12 , - 1 } ;
static int V_219 [] = { 1 , 0 , 3 , 5 , - 1 } ;
if ( V_71 [ V_198 ] == V_220 ) {
if ( ( V_71 [ V_198 ] = F_135 ( V_218 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_45 ) ;
return - V_48 ;
}
}
if ( V_68 [ V_198 ] == V_221 ) {
if ( ( V_68 [ V_198 ] = F_136 ( V_219 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_46 ) ;
return - V_48 ;
}
}
if ( V_55 [ V_198 ] == V_221 ) {
if ( ( V_55 [ V_198 ] = F_136 ( V_219 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_47 ) ;
return - V_48 ;
}
}
if ( V_6 [ V_198 ] != V_141 ) {
return F_130 ( V_198 , V_200 ) ;
} else {
static unsigned long V_222 [] = { 0x220 , 0x240 , 0x260 , 0x280 } ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_103 ( V_222 ) ; V_4 ++ ) {
V_6 [ V_198 ] = V_222 [ V_4 ] ;
V_43 = F_130 ( V_198 , V_200 ) ;
if ( ! V_43 )
return 0 ;
}
return V_43 ;
}
}
static int T_5 F_137 ( struct V_155 * V_217 ,
unsigned int V_198 )
{
F_132 ( F_138 ( V_217 ) ) ;
F_133 ( V_217 , NULL ) ;
return 0 ;
}
static int F_139 ( struct V_155 * V_198 , unsigned int V_223 ,
T_4 V_168 )
{
return F_87 ( F_138 ( V_198 ) , V_168 ) ;
}
static int F_140 ( struct V_155 * V_198 , unsigned int V_223 )
{
return F_90 ( F_138 ( V_198 ) ) ;
}
static int T_1 F_141 ( struct V_199 * V_200 ,
const struct V_224 * V_89 )
{
static int V_198 ;
int V_43 ;
struct V_73 * V_74 ;
if ( F_108 ( V_200 ) )
return - V_225 ;
for (; V_198 < V_226 ; V_198 ++ ) {
if ( V_216 [ V_198 ] && V_227 [ V_198 ] )
break;
}
if ( V_198 >= V_226 )
return - V_9 ;
V_43 = F_121 ( V_198 , & V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ( V_43 = F_118 ( V_198 , V_74 -> V_75 , V_200 ) ) < 0 ) {
F_132 ( V_74 ) ;
return V_43 ;
}
F_131 ( V_74 , & V_200 -> V_198 ) ;
if ( ( V_43 = F_123 ( V_74 , V_198 ) ) < 0 ) {
F_132 ( V_74 ) ;
return V_43 ;
}
F_142 ( V_200 , V_74 ) ;
V_198 ++ ;
return 0 ;
}
static void T_5 F_143 ( struct V_199 * V_200 )
{
F_132 ( F_144 ( V_200 ) ) ;
F_142 ( V_200 , NULL ) ;
}
static int F_145 ( struct V_199 * V_200 , T_4 V_168 )
{
return F_87 ( F_144 ( V_200 ) , V_168 ) ;
}
static int F_146 ( struct V_199 * V_200 )
{
return F_90 ( F_144 ( V_200 ) ) ;
}
static int T_1 F_147 ( struct V_201 * V_228 ,
const struct V_202 * V_229 )
{
static int V_198 ;
struct V_73 * V_74 ;
int V_230 ;
for ( ; V_198 < V_226 ; V_198 ++ ) {
if ( V_216 [ V_198 ] && V_227 [ V_198 ] )
break;
}
if ( V_198 >= V_226 )
return - V_9 ;
V_230 = F_121 ( V_198 , & V_74 ) ;
if ( V_230 < 0 )
return V_230 ;
if ( ( V_230 = F_119 ( V_198 , V_74 -> V_75 , V_228 , V_229 ) ) < 0 ) {
F_132 ( V_74 ) ;
return V_230 ;
}
F_131 ( V_74 , & V_228 -> V_74 -> V_198 ) ;
if ( ( V_230 = F_123 ( V_74 , V_198 ) ) < 0 ) {
F_132 ( V_74 ) ;
return V_230 ;
}
F_148 ( V_228 , V_74 ) ;
V_198 ++ ;
return 0 ;
}
static void T_5 F_149 ( struct V_201 * V_228 )
{
F_132 ( F_150 ( V_228 ) ) ;
F_148 ( V_228 , NULL ) ;
}
static int F_151 ( struct V_201 * V_228 , T_4 V_168 )
{
return F_87 ( F_150 ( V_228 ) , V_168 ) ;
}
static int F_152 ( struct V_201 * V_228 )
{
return F_90 ( F_150 ( V_228 ) ) ;
}
static int T_6 F_153 ( void )
{
int V_43 ;
V_43 = F_154 ( & V_231 , V_226 ) ;
#ifdef F_155
if ( ! V_43 )
V_232 = 1 ;
V_43 = F_156 ( & V_233 ) ;
if ( ! V_43 )
V_234 = 1 ;
V_43 = F_157 ( & V_235 ) ;
if ( ! V_43 )
V_236 = 1 ;
if ( V_232 || V_234 )
V_43 = 0 ;
#endif
return V_43 ;
}
static void T_7 F_158 ( void )
{
#ifdef F_155
if ( V_236 )
F_159 ( & V_235 ) ;
if ( V_234 )
F_160 ( & V_233 ) ;
if ( V_232 )
#endif
F_161 ( & V_231 ) ;
}
