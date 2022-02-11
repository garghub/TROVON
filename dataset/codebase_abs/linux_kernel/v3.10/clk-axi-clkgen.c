static T_1 F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 0 :
return 0x01001990 ;
case 1 :
return 0x01001190 ;
case 2 :
return 0x01009890 ;
case 3 :
return 0x01001890 ;
case 4 :
return 0x01008890 ;
case 5 ... 8 :
return 0x01009090 ;
case 9 ... 11 :
return 0x01000890 ;
case 12 :
return 0x08009090 ;
case 13 ... 22 :
return 0x01001090 ;
case 23 ... 36 :
return 0x01008090 ;
case 37 ... 46 :
return 0x08001090 ;
default:
return 0x08008090 ;
}
}
static T_1 F_2 ( unsigned int V_1 )
{
if ( V_1 < F_3 ( V_2 ) )
return V_2 [ V_1 ] ;
return 0x1f1f00fa ;
}
static void F_4 ( unsigned long V_3 , unsigned long V_4 ,
unsigned int * V_5 , unsigned int * V_6 , unsigned int * V_7 )
{
unsigned long V_8 , V_9 , V_10 , V_11 , V_12 ;
unsigned long V_1 , V_13 , V_14 ;
unsigned long V_15 , V_16 , V_17 , V_18 ;
V_3 /= 1000 ;
V_4 /= 1000 ;
V_17 = V_19 ;
* V_5 = 0 ;
* V_6 = 0 ;
* V_7 = 0 ;
V_9 = F_5 (unsigned long, DIV_ROUND_UP(fin, fpfd_max), 1 ) ;
V_10 = F_6 (unsigned long, fin / fpfd_min, 80 ) ;
V_13 = F_5 (unsigned long, DIV_ROUND_UP(fvco_min, fin) * d_min, 1 ) ;
V_14 = F_6 (unsigned long, fvco_max * d_max / fin, 64 ) ;
for ( V_1 = V_13 ; V_1 <= V_14 ; V_1 ++ ) {
V_11 = F_7 ( V_9 , F_8 ( V_3 * V_1 , V_20 ) ) ;
V_12 = F_9 ( V_10 , V_3 * V_1 / V_21 ) ;
for ( V_8 = V_11 ; V_8 <= V_12 ; V_8 ++ ) {
V_18 = V_3 * V_1 / V_8 ;
V_16 = F_10 ( V_18 , V_4 ) ;
V_16 = F_11 (unsigned long, dout, 1 , 128 ) ;
V_15 = V_18 / V_16 ;
if ( abs ( V_15 - V_4 ) < abs ( V_17 - V_4 ) ) {
V_17 = V_15 ;
* V_5 = V_8 ;
* V_6 = V_1 ;
* V_7 = V_16 ;
if ( V_17 == V_4 )
return;
}
}
}
}
static void F_12 ( unsigned int V_22 , unsigned int * V_23 ,
unsigned int * V_24 , unsigned int * V_25 , unsigned int * V_26 )
{
if ( V_22 == 1 )
* V_26 = 1 ;
else
* V_26 = 0 ;
* V_24 = V_22 / 2 ;
* V_25 = V_22 % 2 ;
* V_23 = V_22 - * V_24 ;
}
static void F_13 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int V_29 )
{
F_14 ( V_29 , V_27 -> V_30 + V_28 ) ;
}
static void F_15 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int * V_29 )
{
* V_29 = F_16 ( V_27 -> V_30 + V_28 ) ;
}
static struct V_27 * F_17 ( struct V_31 * V_31 )
{
return F_18 ( V_31 , struct V_27 , V_31 ) ;
}
static int F_19 ( struct V_31 * V_31 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_27 * V_27 = F_17 ( V_31 ) ;
unsigned int V_8 , V_1 , V_16 ;
unsigned int V_26 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_23 ;
T_1 V_34 ;
T_1 V_35 ;
if ( V_33 == 0 || V_32 == 0 )
return - V_36 ;
F_4 ( V_33 , V_32 , & V_8 , & V_1 , & V_16 ) ;
if ( V_8 == 0 || V_16 == 0 || V_1 == 0 )
return - V_36 ;
V_34 = F_1 ( V_1 - 1 ) ;
V_35 = F_2 ( V_1 - 1 ) ;
F_13 ( V_27 , V_37 , 0 ) ;
F_12 ( V_16 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_13 ( V_27 , V_38 ,
( V_24 << 6 ) | V_23 ) ;
F_13 ( V_27 , V_39 ,
( V_25 << 7 ) | ( V_26 << 6 ) ) ;
F_12 ( V_8 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_13 ( V_27 , V_40 ,
( V_25 << 13 ) | ( V_26 << 12 ) | ( V_24 << 6 ) | V_23 ) ;
F_12 ( V_1 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_13 ( V_27 , V_41 ,
( V_24 << 6 ) | V_23 ) ;
F_13 ( V_27 , V_42 ,
( V_25 << 7 ) | ( V_26 << 6 ) ) ;
F_13 ( V_27 , V_43 , V_35 & 0x3ff ) ;
F_13 ( V_27 , V_44 ,
( ( ( V_35 >> 16 ) & 0x1f ) << 10 ) | 0x1 ) ;
F_13 ( V_27 , V_45 ,
( ( ( V_35 >> 24 ) & 0x1f ) << 10 ) | 0x3e9 ) ;
F_13 ( V_27 , V_46 , V_34 >> 16 ) ;
F_13 ( V_27 , V_47 , V_34 ) ;
F_13 ( V_27 , V_37 , 1 ) ;
return 0 ;
}
static long F_20 ( struct V_31 * V_48 , unsigned long V_32 ,
unsigned long * V_33 )
{
unsigned int V_8 , V_1 , V_16 ;
F_4 ( * V_33 , V_32 , & V_8 , & V_1 , & V_16 ) ;
if ( V_8 == 0 || V_16 == 0 || V_1 == 0 )
return - V_36 ;
return * V_33 / V_8 * V_1 / V_16 ;
}
static unsigned long F_21 ( struct V_31 * V_31 ,
unsigned long V_33 )
{
struct V_27 * V_27 = F_17 ( V_31 ) ;
unsigned int V_8 , V_1 , V_16 ;
unsigned int V_28 ;
unsigned long long V_49 ;
F_15 ( V_27 , V_38 , & V_28 ) ;
V_16 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
F_15 ( V_27 , V_40 , & V_28 ) ;
V_8 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
F_15 ( V_27 , V_41 , & V_28 ) ;
V_1 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
if ( V_8 == 0 || V_16 == 0 )
return 0 ;
V_49 = ( unsigned long long ) ( V_33 / V_8 ) * V_1 ;
F_22 ( V_49 , V_16 ) ;
if ( V_49 > V_19 )
return V_19 ;
return V_49 ;
}
static int F_23 ( struct V_50 * V_51 )
{
struct V_27 * V_27 ;
struct V_52 V_53 ;
const char * V_54 ;
const char * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_58 ;
V_27 = F_24 ( & V_51 -> V_59 , sizeof( * V_27 ) , V_60 ) ;
if ( ! V_27 )
return - V_61 ;
V_57 = F_25 ( V_51 , V_62 , 0 ) ;
V_27 -> V_30 = F_26 ( & V_51 -> V_59 , V_57 ) ;
if ( F_27 ( V_27 -> V_30 ) )
return F_28 ( V_27 -> V_30 ) ;
V_54 = F_29 ( V_51 -> V_59 . V_63 , 0 ) ;
if ( ! V_54 )
return - V_36 ;
V_55 = V_51 -> V_59 . V_63 -> V_64 ;
F_30 ( V_51 -> V_59 . V_63 , L_1 ,
& V_55 ) ;
V_53 . V_64 = V_55 ;
V_53 . V_65 = & V_66 ;
V_53 . V_67 = 0 ;
V_53 . V_68 = & V_54 ;
V_53 . V_69 = 1 ;
V_27 -> V_31 . V_53 = & V_53 ;
V_58 = F_31 ( & V_51 -> V_59 , & V_27 -> V_31 ) ;
if ( F_27 ( V_58 ) )
return F_28 ( V_58 ) ;
return F_32 ( V_51 -> V_59 . V_63 , V_70 ,
V_58 ) ;
}
static int F_33 ( struct V_50 * V_51 )
{
F_34 ( V_51 -> V_59 . V_63 ) ;
return 0 ;
}
