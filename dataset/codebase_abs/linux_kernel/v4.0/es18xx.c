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
static int F_16 ( struct V_1 * V_2 )
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
F_36 ( 100 ) ;
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
F_36 ( 25 ) ;
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
F_36 ( 100 ) ;
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
F_36 ( 100 ) ;
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
F_36 ( 25 ) ;
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
static T_1 F_44 ( int V_71 , void * V_72 )
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
static T_2 F_48 ( struct V_23 * V_24 )
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
static T_2 F_50 ( struct V_23 * V_24 )
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
static const char * const V_106 [ 5 ] = {
L_10 , L_11 , L_12 , L_13 , L_14
} ;
static const char * const V_107 [ 8 ] = {
L_10 , L_15 , L_11 , L_16 ,
L_17 , L_14 , L_12 , L_13
} ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
switch ( V_2 -> V_108 ) {
case 0x1868 :
case 0x1878 :
return F_59 ( V_105 , 1 , 4 , V_106 ) ;
case 0x1887 :
case 0x1888 :
return F_59 ( V_105 , 1 , 5 , V_106 ) ;
case 0x1869 :
case 0x1879 :
return F_59 ( V_105 , 1 , 8 , V_107 ) ;
default:
return - V_8 ;
}
}
static int F_60 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
static unsigned char V_111 [ 8 ] = { 0 , 0 , 1 , 1 , 0 , 0 , 2 , 3 } ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_112 = F_13 ( V_2 , 0x1c ) & 0x07 ;
if ( ! ( V_2 -> V_108 == 0x1869 || V_2 -> V_108 == 0x1879 ) ) {
V_112 = V_111 [ V_112 ] ;
if ( V_112 == 3 &&
( V_2 -> V_108 == 0x1887 || V_2 -> V_108 == 0x1888 ) &&
( F_13 ( V_2 , 0x7a ) & 0x08 )
)
V_112 = 4 ;
}
V_110 -> V_113 . V_114 . V_115 [ 0 ] = V_112 ;
return 0 ;
}
static int F_61 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
static unsigned char V_116 [ 4 ] = { 0 , 2 , 6 , 7 } ;
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_3 = V_110 -> V_113 . V_114 . V_115 [ 0 ] ;
unsigned char V_117 = 0 ;
switch ( V_2 -> V_108 ) {
case 0x1887 :
case 0x1888 :
if ( V_3 > 4 )
return - V_8 ;
if ( V_3 == 4 ) {
V_117 = F_14 ( V_2 , 0x7a , 0x08 , 0x08 ) != 0x08 ;
V_3 = 3 ;
} else
V_117 = F_14 ( V_2 , 0x7a , 0x08 , 0x00 ) != 0x00 ;
case 0x1868 :
case 0x1878 :
if ( V_3 > 3 )
return - V_8 ;
V_3 = V_116 [ V_3 ] ;
break;
case 0x1869 :
case 0x1879 :
if ( V_3 > 7 )
return - V_8 ;
break;
default:
return - V_8 ;
}
return ( F_14 ( V_2 , 0x1c , 0x07 , V_3 ) != V_3 ) || V_117 ;
}
static int F_62 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_3 = F_13 ( V_2 , 0x50 ) ;
V_110 -> V_113 . integer . V_113 [ 0 ] = ! ! ( V_3 & 8 ) ;
return 0 ;
}
static int F_63 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
unsigned char V_20 , V_118 ;
int V_119 ;
V_118 = V_110 -> V_113 . integer . V_113 [ 0 ] ? 0x0c : 0x04 ;
V_20 = F_13 ( V_2 , 0x50 ) & 0x0c ;
V_119 = V_118 != V_20 ;
if ( V_119 ) {
F_12 ( V_2 , 0x50 , V_118 & ~ 0x04 ) ;
F_12 ( V_2 , 0x50 , V_118 ) ;
}
return V_119 ;
}
static int F_64 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
V_105 -> type = V_120 ;
V_105 -> V_52 = 2 ;
V_105 -> V_113 . integer . V_121 = 0 ;
V_105 -> V_113 . integer . V_122 = 63 ;
return 0 ;
}
static int F_65 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_110 -> V_113 . integer . V_113 [ 0 ] = F_13 ( V_2 , 0x61 ) & 0x3f ;
V_110 -> V_113 . integer . V_113 [ 1 ] = F_13 ( V_2 , 0x63 ) & 0x3f ;
return 0 ;
}
static int F_66 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_110 -> V_113 . integer . V_113 [ 0 ] = ! ( F_13 ( V_2 , 0x61 ) & 0x40 ) ;
V_110 -> V_113 . integer . V_113 [ 1 ] = ! ( F_13 ( V_2 , 0x63 ) & 0x40 ) ;
return 0 ;
}
static void F_67 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
V_2 -> V_92 = NULL ;
V_2 -> V_91 = NULL ;
V_2 -> V_90 = NULL ;
V_2 -> V_88 = NULL ;
}
static int F_68 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_17 , unsigned char V_3 )
{
if ( V_10 < 0xa0 )
return F_14 ( V_2 , V_10 , V_17 , V_3 ) ;
else
return F_11 ( V_2 , V_10 , V_17 , V_3 ) ;
}
static int F_69 ( struct V_1 * V_2 , unsigned char V_10 )
{
if ( V_10 < 0xa0 )
return F_13 ( V_2 , V_10 ) ;
else
return F_10 ( V_2 , V_10 ) ;
}
static int F_70 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
int V_17 = ( V_103 -> V_123 >> 16 ) & 0xff ;
V_105 -> type = V_17 == 1 ? V_124 : V_120 ;
V_105 -> V_52 = 1 ;
V_105 -> V_113 . integer . V_121 = 0 ;
V_105 -> V_113 . integer . V_122 = V_17 ;
return 0 ;
}
static int F_71 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_10 = V_103 -> V_123 & 0xff ;
int V_42 = ( V_103 -> V_123 >> 8 ) & 0xff ;
int V_17 = ( V_103 -> V_123 >> 16 ) & 0xff ;
int V_125 = ( V_103 -> V_123 >> 24 ) & V_126 ;
int V_127 = ( V_103 -> V_123 >> 24 ) & V_128 ;
int V_3 ;
if ( V_127 )
V_3 = F_2 ( V_2 -> V_6 + V_129 ) ;
else
V_3 = F_69 ( V_2 , V_10 ) ;
V_110 -> V_113 . integer . V_113 [ 0 ] = ( V_3 >> V_42 ) & V_17 ;
if ( V_125 )
V_110 -> V_113 . integer . V_113 [ 0 ] = V_17 - V_110 -> V_113 . integer . V_113 [ 0 ] ;
return 0 ;
}
static int F_72 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_10 = V_103 -> V_123 & 0xff ;
int V_42 = ( V_103 -> V_123 >> 8 ) & 0xff ;
int V_17 = ( V_103 -> V_123 >> 16 ) & 0xff ;
int V_125 = ( V_103 -> V_123 >> 24 ) & V_126 ;
int V_127 = ( V_103 -> V_123 >> 24 ) & V_128 ;
unsigned char V_3 ;
V_3 = ( V_110 -> V_113 . integer . V_113 [ 0 ] & V_17 ) ;
if ( V_125 )
V_3 = V_17 - V_3 ;
V_17 <<= V_42 ;
V_3 <<= V_42 ;
if ( V_127 ) {
unsigned char V_130 = F_2 ( V_2 -> V_6 + V_129 ) ;
if ( ( V_130 & V_17 ) == V_3 )
return 0 ;
F_3 ( ( V_130 & ~ V_17 ) | V_3 , V_2 -> V_6 + V_129 ) ;
return 1 ;
}
return F_68 ( V_2 , V_10 , V_17 , V_3 ) != V_3 ;
}
static int F_73 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
int V_17 = ( V_103 -> V_123 >> 24 ) & 0xff ;
V_105 -> type = V_17 == 1 ? V_124 : V_120 ;
V_105 -> V_52 = 2 ;
V_105 -> V_113 . integer . V_121 = 0 ;
V_105 -> V_113 . integer . V_122 = V_17 ;
return 0 ;
}
static int F_74 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_131 = V_103 -> V_123 & 0xff ;
int V_132 = ( V_103 -> V_123 >> 8 ) & 0xff ;
int V_133 = ( V_103 -> V_123 >> 16 ) & 0x07 ;
int V_134 = ( V_103 -> V_123 >> 19 ) & 0x07 ;
int V_17 = ( V_103 -> V_123 >> 24 ) & 0xff ;
int V_125 = ( V_103 -> V_123 >> 22 ) & 1 ;
unsigned char V_135 , V_136 ;
V_135 = F_69 ( V_2 , V_131 ) ;
if ( V_131 != V_132 )
V_136 = F_69 ( V_2 , V_132 ) ;
else
V_136 = V_135 ;
V_110 -> V_113 . integer . V_113 [ 0 ] = ( V_135 >> V_133 ) & V_17 ;
V_110 -> V_113 . integer . V_113 [ 1 ] = ( V_136 >> V_134 ) & V_17 ;
if ( V_125 ) {
V_110 -> V_113 . integer . V_113 [ 0 ] = V_17 - V_110 -> V_113 . integer . V_113 [ 0 ] ;
V_110 -> V_113 . integer . V_113 [ 1 ] = V_17 - V_110 -> V_113 . integer . V_113 [ 1 ] ;
}
return 0 ;
}
static int F_75 ( struct V_102 * V_103 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_103 ) ;
int V_131 = V_103 -> V_123 & 0xff ;
int V_132 = ( V_103 -> V_123 >> 8 ) & 0xff ;
int V_133 = ( V_103 -> V_123 >> 16 ) & 0x07 ;
int V_134 = ( V_103 -> V_123 >> 19 ) & 0x07 ;
int V_17 = ( V_103 -> V_123 >> 24 ) & 0xff ;
int V_125 = ( V_103 -> V_123 >> 22 ) & 1 ;
int V_119 ;
unsigned char V_137 , V_138 , V_139 , V_140 ;
V_137 = V_110 -> V_113 . integer . V_113 [ 0 ] & V_17 ;
V_138 = V_110 -> V_113 . integer . V_113 [ 1 ] & V_17 ;
if ( V_125 ) {
V_137 = V_17 - V_137 ;
V_138 = V_17 - V_138 ;
}
V_137 <<= V_133 ;
V_138 <<= V_134 ;
V_139 = V_17 << V_133 ;
V_140 = V_17 << V_134 ;
if ( V_131 != V_132 ) {
V_119 = 0 ;
if ( F_68 ( V_2 , V_131 , V_139 , V_137 ) != V_137 )
V_119 = 1 ;
if ( F_68 ( V_2 , V_132 , V_140 , V_138 ) != V_138 )
V_119 = 1 ;
} else {
V_119 = ( F_68 ( V_2 , V_131 , V_139 | V_140 ,
V_137 | V_138 ) != ( V_137 | V_138 ) ) ;
}
return V_119 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned char V_10 )
{
int V_11 ;
F_3 ( V_10 , V_2 -> V_78 ) ;
V_11 = F_2 ( V_2 -> V_78 + 1 ) ;
return V_11 ;
}
static void F_77 ( struct V_1 * V_2 ,
unsigned char V_10 , unsigned char V_11 )
{
F_3 ( V_10 , V_2 -> V_78 ) ;
F_3 ( V_11 , V_2 -> V_78 + 1 ) ;
#ifdef F_9
F_4 ( V_16 L_18 , V_10 , V_11 ) ;
#endif
}
static int F_78 ( struct V_1 * V_2 ,
unsigned long V_141 ,
unsigned long V_142 )
{
int V_17 = 0 ;
F_1 ( V_2 , 0xC6 ) ;
F_12 ( V_2 , 0x00 , 0x00 ) ;
F_6 ( V_2 , 0xB9 , 2 ) ;
if ( V_2 -> V_30 & V_77 ) {
F_77 ( V_2 , 0x27 , V_2 -> V_71 ) ;
if ( V_142 > 0 && V_142 != V_143 ) {
F_77 ( V_2 , 0x62 , V_142 >> 8 ) ;
F_77 ( V_2 , 0x63 , V_142 & 0xff ) ;
}
if ( V_141 > 0 && V_141 != V_143 ) {
F_77 ( V_2 , 0x64 , V_141 >> 8 ) ;
F_77 ( V_2 , 0x65 , V_141 & 0xff ) ;
F_77 ( V_2 , 0x28 , V_2 -> V_71 ) ;
}
F_77 ( V_2 , 0x70 , V_2 -> V_71 ) ;
F_77 ( V_2 , 0x72 , V_2 -> V_71 ) ;
F_77 ( V_2 , 0x74 , V_2 -> V_68 ) ;
F_77 ( V_2 , 0x75 , V_2 -> V_55 ) ;
F_6 ( V_2 , 0xB1 , 0x50 ) ;
F_12 ( V_2 , 0x7A , 0x40 ) ;
F_6 ( V_2 , 0xB2 , 0x50 ) ;
F_12 ( V_2 , 0x64 , 0x42 ) ;
F_14 ( V_2 , 0x48 , 0x10 , 0x10 ) ;
}
else {
int V_144 , V_145 , V_146 ;
switch ( V_2 -> V_71 ) {
case 2 :
case 9 :
V_144 = 0 ;
break;
case 5 :
V_144 = 1 ;
break;
case 7 :
V_144 = 2 ;
break;
case 10 :
V_144 = 3 ;
break;
default:
F_4 ( V_7 L_19 , V_2 -> V_71 ) ;
return - V_9 ;
}
switch ( V_2 -> V_68 ) {
case 0 :
V_145 = 1 ;
break;
case 1 :
V_145 = 2 ;
break;
case 3 :
V_145 = 3 ;
break;
default:
F_4 ( V_7 L_20 , V_2 -> V_68 ) ;
return - V_9 ;
}
switch ( V_2 -> V_55 ) {
case 0 :
V_146 = 0 ;
break;
case 1 :
V_146 = 1 ;
break;
case 3 :
V_146 = 2 ;
break;
case 5 :
V_146 = 3 ;
break;
default:
F_4 ( V_7 L_21 , V_2 -> V_55 ) ;
return - V_9 ;
}
F_6 ( V_2 , 0xB1 , 0x50 | ( V_144 << 2 ) ) ;
F_6 ( V_2 , 0xB2 , 0x50 | ( V_145 << 2 ) ) ;
F_14 ( V_2 , 0x7d , 0x07 , 0x04 | V_146 ) ;
F_12 ( V_2 , 0x7A , 0x68 ) ;
F_12 ( V_2 , 0x64 , 0x06 ) ;
if ( V_141 > 0 && V_141 != V_143 ) {
F_12 ( V_2 , 0x40 ,
0x43 | ( V_141 & 0xf0 ) >> 1 ) ;
}
F_12 ( V_2 , 0x7f , ( ( V_144 + 1 ) << 1 ) | 0x01 ) ;
}
if ( V_2 -> V_30 & V_31 ) {
F_12 ( V_2 , 0x71 , 0x32 ) ;
}
if ( ! ( V_2 -> V_30 & V_38 ) ) {
F_6 ( V_2 , 0xB7 , 0x80 ) ;
}
if ( V_2 -> V_30 & V_147 ) {
F_12 ( V_2 , 0x54 , 0x8f ) ;
F_12 ( V_2 , 0x56 , 0x95 ) ;
F_12 ( V_2 , 0x58 , 0x94 ) ;
F_12 ( V_2 , 0x5a , 0x80 ) ;
}
switch ( V_2 -> V_108 ) {
case 0x1879 :
case 0x1878 :
F_77 ( V_2 , 0x29 , F_76 ( V_2 , 0x29 ) | 0x40 ) ;
break;
}
if ( V_2 -> V_30 & V_148 )
V_17 = 0x10 ;
if ( V_2 -> V_30 & V_149 )
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
static int F_79 ( struct V_1 * V_2 )
{
int V_150 , V_151 ;
if ( F_16 ( V_2 ) < 0 ) {
F_4 ( V_7 L_22 , V_2 -> V_6 ) ;
return - V_9 ;
}
F_1 ( V_2 , 0xe7 ) ;
V_150 = F_5 ( V_2 ) ;
if ( V_150 < 0 ) {
return V_150 ;
}
V_151 = F_5 ( V_2 ) ;
if ( ( V_151 & 0xf0 ) != 0x80 ) {
return - V_9 ;
}
if ( V_150 == 0x48 ) {
V_2 -> V_108 = 0x488 ;
return 0 ;
}
if ( V_150 != 0x68 ) {
return - V_9 ;
}
if ( ( V_151 & 0x0f ) < 8 ) {
V_2 -> V_108 = 0x688 ;
return 0 ;
}
F_3 ( 0x40 , V_2 -> V_6 + 0x04 ) ;
F_80 ( 10 ) ;
V_150 = F_2 ( V_2 -> V_6 + 0x05 ) ;
F_80 ( 10 ) ;
V_151 = F_2 ( V_2 -> V_6 + 0x05 ) ;
if ( V_150 != V_151 ) {
V_2 -> V_108 = V_150 << 8 | V_151 ;
V_2 -> V_78 = F_2 ( V_2 -> V_6 + 0x05 ) << 8 ;
F_80 ( 10 ) ;
V_2 -> V_78 += F_2 ( V_2 -> V_6 + 0x05 ) ;
if ( ( V_2 -> V_152 = F_81 ( V_2 -> V_78 , 8 , L_23 ) ) == NULL ) {
F_4 (KERN_ERR PFX L_24 , chip->ctrl_port) ;
return - V_48 ;
}
return 0 ;
}
if ( F_15 ( V_2 , 0x64 , 0x04 ) ) {
if ( F_15 ( V_2 , 0x70 , 0x7f ) ) {
if ( F_15 ( V_2 , 0x64 , 0x20 ) ) {
V_2 -> V_108 = 0x1887 ;
} else {
V_2 -> V_108 = 0x1888 ;
}
} else {
V_2 -> V_108 = 0x1788 ;
}
}
else
V_2 -> V_108 = 0x1688 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
unsigned long V_141 ,
unsigned long V_142 )
{
if ( F_79 ( V_2 ) < 0 ) {
F_4 (KERN_ERR PFX L_25 , chip->port) ;
return - V_9 ;
}
switch ( V_2 -> V_108 ) {
case 0x1868 :
V_2 -> V_30 = V_45 | V_153 | V_77 | V_154 ;
break;
case 0x1869 :
V_2 -> V_30 = V_38 | V_147 | V_149 | V_31 | V_155 | V_156 | V_148 | V_77 | V_86 | V_154 ;
break;
case 0x1878 :
V_2 -> V_30 = V_45 | V_153 | V_157 | V_77 ;
break;
case 0x1879 :
V_2 -> V_30 = V_38 | V_147 | V_149 | V_31 | V_155 | V_157 | V_77 | V_86 ;
break;
case 0x1887 :
case 0x1888 :
V_2 -> V_30 = V_38 | V_149 | V_155 | V_153 | V_154 ;
break;
default:
F_4 ( V_7 L_26 ,
V_2 -> V_6 , V_2 -> V_108 ) ;
return - V_9 ;
}
F_83 ( L_27 , V_2 -> V_6 , V_2 -> V_108 ) ;
if ( V_2 -> V_68 == V_2 -> V_55 )
V_2 -> V_30 &= ~ ( V_38 | V_153 ) ;
return F_78 ( V_2 , V_141 , V_142 ) ;
}
static int F_84 ( struct V_73 * V_74 , int V_158 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_159 * V_160 ;
char V_161 [ 16 ] ;
int V_43 ;
sprintf ( V_161 , L_28 , V_2 -> V_108 ) ;
if ( V_2 -> V_30 & V_38 )
V_43 = F_85 ( V_74 , V_161 , V_158 , 2 , 1 , & V_160 ) ;
else
V_43 = F_85 ( V_74 , V_161 , V_158 , 1 , 1 , & V_160 ) ;
if ( V_43 < 0 )
return V_43 ;
F_86 ( V_160 , V_162 , & V_163 ) ;
F_86 ( V_160 , V_164 , & V_165 ) ;
V_160 -> V_75 = V_2 ;
V_160 -> V_166 = 0 ;
if ( V_2 -> V_30 & V_153 )
V_160 -> V_166 |= V_167 ;
if ( ! ( V_2 -> V_30 & V_38 ) )
V_160 -> V_166 |= V_168 ;
sprintf ( V_160 -> V_169 , L_29 , V_2 -> V_108 ) ;
V_2 -> V_160 = V_160 ;
F_87 ( V_160 , V_170 ,
F_88 () ,
64 * 1024 ,
V_2 -> V_68 > 3 || V_2 -> V_55 > 3 ? 128 * 1024 : 64 * 1024 ) ;
return 0 ;
}
static int F_89 ( struct V_73 * V_74 , T_3 V_171 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_90 ( V_74 , V_172 ) ;
F_91 ( V_2 -> V_160 ) ;
V_2 -> V_173 = ( unsigned char ) F_10 ( V_2 , V_129 ) ;
V_2 -> V_173 |= ( V_174 | V_175 ) ;
F_6 ( V_2 , V_129 , V_2 -> V_173 ) ;
F_6 ( V_2 , V_129 , V_2 -> V_173 ^= V_175 ) ;
return 0 ;
}
static int F_92 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_6 ( V_2 , V_129 , V_2 -> V_173 ^= V_174 ) ;
F_90 ( V_74 , V_176 ) ;
return 0 ;
}
static int F_93 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
F_94 ( V_2 -> V_177 ) ;
F_94 ( V_2 -> V_152 ) ;
F_94 ( V_2 -> V_178 ) ;
if ( V_2 -> V_71 >= 0 )
F_95 ( V_2 -> V_71 , ( void * ) V_74 ) ;
if ( V_2 -> V_68 >= 0 ) {
F_96 ( V_2 -> V_68 ) ;
F_97 ( V_2 -> V_68 ) ;
}
if ( V_2 -> V_55 >= 0 && V_2 -> V_68 != V_2 -> V_55 ) {
F_96 ( V_2 -> V_55 ) ;
F_97 ( V_2 -> V_55 ) ;
}
return 0 ;
}
static int F_98 ( struct V_179 * V_158 )
{
return F_93 ( V_158 -> V_74 ) ;
}
static int F_99 ( struct V_73 * V_74 ,
unsigned long V_6 ,
unsigned long V_141 ,
unsigned long V_142 ,
int V_71 , int V_68 , int V_55 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
static struct V_180 V_181 = {
. V_182 = F_98 ,
} ;
int V_43 ;
F_100 ( & V_2 -> V_14 ) ;
F_100 ( & V_2 -> V_21 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_71 = - 1 ;
V_2 -> V_68 = - 1 ;
V_2 -> V_55 = - 1 ;
V_2 -> V_63 = 0x00 ;
V_2 -> V_62 = 0 ;
V_2 -> V_177 = F_81 ( V_6 , 16 , L_30 ) ;
if ( V_2 -> V_177 == NULL ) {
F_93 ( V_74 ) ;
F_4 (KERN_ERR PFX L_31 , port, port + 16 - 1 ) ;
return - V_48 ;
}
if ( F_101 ( V_71 , F_44 , 0 , L_30 ,
( void * ) V_74 ) ) {
F_93 ( V_74 ) ;
F_4 (KERN_ERR PFX L_32 , irq) ;
return - V_48 ;
}
V_2 -> V_71 = V_71 ;
if ( F_102 ( V_68 , L_33 ) ) {
F_93 ( V_74 ) ;
F_4 (KERN_ERR PFX L_34 , dma1) ;
return - V_48 ;
}
V_2 -> V_68 = V_68 ;
if ( V_55 != V_68 && F_102 ( V_55 , L_35 ) ) {
F_93 ( V_74 ) ;
F_4 (KERN_ERR PFX L_36 , dma2) ;
return - V_48 ;
}
V_2 -> V_55 = V_55 ;
if ( F_82 ( V_2 , V_141 , V_142 ) < 0 ) {
F_93 ( V_74 ) ;
return - V_9 ;
}
V_43 = F_103 ( V_74 , V_183 , V_2 , & V_181 ) ;
if ( V_43 < 0 ) {
F_93 ( V_74 ) ;
return V_43 ;
}
return 0 ;
}
static int F_104 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
int V_43 ;
unsigned int V_184 ;
strcpy ( V_74 -> V_185 , V_2 -> V_160 -> V_169 ) ;
for ( V_184 = 0 ; V_184 < F_105 ( V_186 ) ; V_184 ++ ) {
struct V_102 * V_187 ;
V_187 = F_106 ( & V_186 [ V_184 ] , V_2 ) ;
if ( V_2 -> V_30 & V_86 ) {
switch ( V_184 ) {
case 0 :
V_2 -> V_92 = V_187 ;
V_187 -> V_188 = F_67 ;
break;
case 1 :
V_2 -> V_91 = V_187 ;
V_187 -> V_188 = F_67 ;
break;
}
}
if ( ( V_43 = F_107 ( V_74 , V_187 ) ) < 0 )
return V_43 ;
}
if ( V_2 -> V_30 & V_38 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_189 ) ; V_184 ++ ) {
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_189 [ V_184 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
} else {
for ( V_184 = 0 ; V_184 < F_105 ( V_190 ) ; V_184 ++ ) {
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_190 [ V_184 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_30 & V_149 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_191 ) ; V_184 ++ ) {
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_191 [ V_184 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
switch ( V_2 -> V_108 ) {
default:
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_192 , V_2 ) ) ) < 0 )
return V_43 ;
break;
case 0x1869 :
case 0x1879 :
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_193 , V_2 ) ) ) < 0 )
return V_43 ;
break;
}
if ( V_2 -> V_30 & V_147 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_194 ) ; V_184 ++ ) {
if ( ( V_43 = F_107 ( V_74 , F_106 ( & V_194 [ V_184 ] , V_2 ) ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_30 & V_86 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_195 ) ; V_184 ++ ) {
struct V_102 * V_187 ;
V_187 = F_106 ( & V_195 [ V_184 ] , V_2 ) ;
if ( V_184 == 0 )
V_2 -> V_90 = V_187 ;
else
V_2 -> V_88 = V_187 ;
V_187 -> V_188 = F_67 ;
if ( ( V_43 = F_107 ( V_74 , V_187 ) ) < 0 )
return V_43 ;
}
}
if ( V_2 -> V_108 != 0x1868 ) {
V_43 = F_107 ( V_74 , F_106 ( & V_196 ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_2 -> V_108 == 0x1869 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_197 ) ; V_184 ++ ) {
V_43 = F_107 ( V_74 ,
F_106 ( & V_197 [ V_184 ] ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
} else if ( V_2 -> V_108 == 0x1878 ) {
V_43 = F_107 ( V_74 , F_106 ( & V_198 ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
} else if ( V_2 -> V_108 == 0x1879 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_199 ) ; V_184 ++ ) {
V_43 = F_107 ( V_74 ,
F_106 ( & V_199 [ V_184 ] ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_2 -> V_30 & V_154 ) {
for ( V_184 = 0 ; V_184 < F_105 ( V_200 ) ; V_184 ++ ) {
V_43 = F_107 ( V_74 ,
F_106 ( & V_200 [ V_184 ] ,
V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
return 0 ;
}
static int F_108 ( int V_201 , struct V_202 * V_203 )
{
if ( F_109 ( V_203 ) < 0 ) {
F_4 (KERN_ERR PFX L_37 ) ;
return - V_48 ;
}
if ( F_110 ( V_203 ) ) {
F_111 ( F_112 ( V_203 ) , F_113 ( V_203 ) ) ;
F_114 ( 0x27 , F_115 ( V_203 , 0 ) ) ;
if ( V_141 [ V_201 ] != V_143 )
F_114 ( 0x28 , F_115 ( V_203 , 0 ) ) ;
F_114 ( 0x72 , F_115 ( V_203 , 0 ) ) ;
F_116 () ;
}
V_6 [ V_201 ] = F_117 ( V_203 , 0 ) ;
V_142 [ V_201 ] = F_117 ( V_203 , 1 ) ;
V_141 [ V_201 ] = F_117 ( V_203 , 2 ) ;
V_68 [ V_201 ] = F_118 ( V_203 , 0 ) ;
V_55 [ V_201 ] = F_118 ( V_203 , 1 ) ;
V_71 [ V_201 ] = F_115 ( V_203 , 0 ) ;
F_119 ( L_38 , V_6 [ V_201 ] , V_142 [ V_201 ] , V_141 [ V_201 ] ) ;
F_119 ( L_39 , V_68 [ V_201 ] , V_55 [ V_201 ] , V_71 [ V_201 ] ) ;
return 0 ;
}
static int F_120 ( int V_201 , struct V_1 * V_2 ,
struct V_202 * V_203 )
{
V_2 -> V_201 = V_203 ;
if ( F_108 ( V_201 , V_2 -> V_201 ) < 0 )
return - V_48 ;
return 0 ;
}
static int F_121 ( int V_201 , struct V_1 * V_2 ,
struct V_204 * V_74 ,
const struct V_205 * V_89 )
{
V_2 -> V_201 = F_122 ( V_74 , V_89 -> V_206 [ 0 ] . V_89 , NULL ) ;
if ( V_2 -> V_201 == NULL )
return - V_48 ;
V_2 -> V_207 = F_122 ( V_74 , V_89 -> V_206 [ 1 ] . V_89 , NULL ) ;
if ( V_2 -> V_207 == NULL )
return - V_48 ;
if ( F_109 ( V_2 -> V_207 ) < 0 ) {
F_4 (KERN_ERR PFX L_40 ) ;
return - V_95 ;
}
F_119 ( L_41 ,
( unsigned long long ) F_117 ( V_2 -> V_207 , 0 ) ) ;
if ( F_108 ( V_201 , V_2 -> V_201 ) < 0 )
return - V_48 ;
return 0 ;
}
static int F_123 ( struct V_158 * V_203 , int V_201 ,
struct V_73 * * V_208 )
{
return F_124 ( V_203 , V_209 [ V_201 ] , V_89 [ V_201 ] , V_210 ,
sizeof( struct V_1 ) , V_208 ) ;
}
static int F_125 ( struct V_73 * V_74 , int V_201 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_211 * V_212 ;
int V_43 ;
V_43 = F_99 ( V_74 ,
V_6 [ V_201 ] , V_141 [ V_201 ] , V_142 [ V_201 ] ,
V_71 [ V_201 ] , V_68 [ V_201 ] , V_55 [ V_201 ] ) ;
if ( V_43 < 0 )
return V_43 ;
sprintf ( V_74 -> V_213 , L_28 , V_2 -> V_108 ) ;
sprintf ( V_74 -> V_214 , L_29 , V_2 -> V_108 ) ;
if ( V_68 [ V_201 ] != V_55 [ V_201 ] )
sprintf ( V_74 -> V_215 , L_42 ,
V_74 -> V_214 ,
V_2 -> V_6 ,
V_71 [ V_201 ] , V_68 [ V_201 ] , V_55 [ V_201 ] ) ;
else
sprintf ( V_74 -> V_215 , L_43 ,
V_74 -> V_214 ,
V_2 -> V_6 ,
V_71 [ V_201 ] , V_68 [ V_201 ] ) ;
V_43 = F_84 ( V_74 , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_104 ( V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_142 [ V_201 ] > 0 && V_142 [ V_201 ] != V_143 ) {
if ( F_126 ( V_74 , V_142 [ V_201 ] , V_142 [ V_201 ] + 2 ,
V_216 , 0 , & V_212 ) < 0 ) {
F_4 (KERN_WARNING PFX
L_44 ,
fm_port[dev]) ;
} else {
V_43 = F_127 ( V_212 , 0 , 1 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_141 [ V_201 ] > 0 && V_141 [ V_201 ] != V_143 ) {
V_43 = F_128 ( V_74 , 0 , V_217 ,
V_141 [ V_201 ] , V_218 ,
- 1 , & V_2 -> V_83 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return F_129 ( V_74 ) ;
}
static int F_130 ( struct V_158 * V_203 , unsigned int V_201 )
{
return V_219 [ V_201 ] && ! F_131 ( V_201 ) ;
}
static int F_132 ( int V_201 , struct V_158 * V_220 )
{
struct V_73 * V_74 ;
int V_43 ;
V_43 = F_123 ( V_220 , V_201 , & V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ( V_43 = F_125 ( V_74 , V_201 ) ) < 0 ) {
F_133 ( V_74 ) ;
return V_43 ;
}
F_134 ( V_220 , V_74 ) ;
return 0 ;
}
static int F_135 ( struct V_158 * V_203 , unsigned int V_201 )
{
int V_43 ;
static int V_221 [] = { 5 , 9 , 10 , 7 , 11 , 12 , - 1 } ;
static int V_222 [] = { 1 , 0 , 3 , 5 , - 1 } ;
if ( V_71 [ V_201 ] == V_223 ) {
if ( ( V_71 [ V_201 ] = F_136 ( V_221 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_45 ) ;
return - V_48 ;
}
}
if ( V_68 [ V_201 ] == V_224 ) {
if ( ( V_68 [ V_201 ] = F_137 ( V_222 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_46 ) ;
return - V_48 ;
}
}
if ( V_55 [ V_201 ] == V_224 ) {
if ( ( V_55 [ V_201 ] = F_137 ( V_222 ) ) < 0 ) {
F_4 (KERN_ERR PFX L_47 ) ;
return - V_48 ;
}
}
if ( V_6 [ V_201 ] != V_143 ) {
return F_132 ( V_201 , V_203 ) ;
} else {
static unsigned long V_225 [] = { 0x220 , 0x240 , 0x260 , 0x280 } ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_105 ( V_225 ) ; V_4 ++ ) {
V_6 [ V_201 ] = V_225 [ V_4 ] ;
V_43 = F_132 ( V_201 , V_203 ) ;
if ( ! V_43 )
return 0 ;
}
return V_43 ;
}
}
static int F_138 ( struct V_158 * V_220 ,
unsigned int V_201 )
{
F_133 ( F_139 ( V_220 ) ) ;
return 0 ;
}
static int F_140 ( struct V_158 * V_201 , unsigned int V_226 ,
T_3 V_171 )
{
return F_89 ( F_139 ( V_201 ) , V_171 ) ;
}
static int F_141 ( struct V_158 * V_201 , unsigned int V_226 )
{
return F_92 ( F_139 ( V_201 ) ) ;
}
static int F_142 ( struct V_202 * V_203 ,
const struct V_227 * V_89 )
{
static int V_201 ;
int V_43 ;
struct V_73 * V_74 ;
if ( F_110 ( V_203 ) )
return - V_228 ;
for (; V_201 < V_229 ; V_201 ++ ) {
if ( V_219 [ V_201 ] && V_230 [ V_201 ] )
break;
}
if ( V_201 >= V_229 )
return - V_9 ;
V_43 = F_123 ( & V_203 -> V_201 , V_201 , & V_74 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ( V_43 = F_120 ( V_201 , V_74 -> V_75 , V_203 ) ) < 0 ) {
F_133 ( V_74 ) ;
return V_43 ;
}
if ( ( V_43 = F_125 ( V_74 , V_201 ) ) < 0 ) {
F_133 ( V_74 ) ;
return V_43 ;
}
F_143 ( V_203 , V_74 ) ;
V_201 ++ ;
return 0 ;
}
static void F_144 ( struct V_202 * V_203 )
{
F_133 ( F_145 ( V_203 ) ) ;
}
static int F_146 ( struct V_202 * V_203 , T_3 V_171 )
{
return F_89 ( F_145 ( V_203 ) , V_171 ) ;
}
static int F_147 ( struct V_202 * V_203 )
{
return F_92 ( F_145 ( V_203 ) ) ;
}
static int F_148 ( struct V_204 * V_231 ,
const struct V_205 * V_232 )
{
static int V_201 ;
struct V_73 * V_74 ;
int V_233 ;
for ( ; V_201 < V_229 ; V_201 ++ ) {
if ( V_219 [ V_201 ] && V_230 [ V_201 ] )
break;
}
if ( V_201 >= V_229 )
return - V_9 ;
V_233 = F_123 ( & V_231 -> V_74 -> V_201 , V_201 , & V_74 ) ;
if ( V_233 < 0 )
return V_233 ;
if ( ( V_233 = F_121 ( V_201 , V_74 -> V_75 , V_231 , V_232 ) ) < 0 ) {
F_133 ( V_74 ) ;
return V_233 ;
}
if ( ( V_233 = F_125 ( V_74 , V_201 ) ) < 0 ) {
F_133 ( V_74 ) ;
return V_233 ;
}
F_149 ( V_231 , V_74 ) ;
V_201 ++ ;
return 0 ;
}
static void F_150 ( struct V_204 * V_231 )
{
F_133 ( F_151 ( V_231 ) ) ;
F_149 ( V_231 , NULL ) ;
}
static int F_152 ( struct V_204 * V_231 , T_3 V_171 )
{
return F_89 ( F_151 ( V_231 ) , V_171 ) ;
}
static int F_153 ( struct V_204 * V_231 )
{
return F_92 ( F_151 ( V_231 ) ) ;
}
static int T_4 F_154 ( void )
{
int V_43 ;
V_43 = F_155 ( & V_234 , V_229 ) ;
#ifdef F_156
if ( ! V_43 )
V_235 = 1 ;
V_43 = F_157 ( & V_236 ) ;
if ( ! V_43 )
V_237 = 1 ;
V_43 = F_158 ( & V_238 ) ;
if ( ! V_43 )
V_239 = 1 ;
if ( V_235 || V_237 )
V_43 = 0 ;
#endif
return V_43 ;
}
static void T_5 F_159 ( void )
{
#ifdef F_156
if ( V_239 )
F_160 ( & V_238 ) ;
if ( V_237 )
F_161 ( & V_236 ) ;
if ( V_235 )
#endif
F_162 ( & V_234 ) ;
}
