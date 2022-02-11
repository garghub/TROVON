static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
int V_5 = V_3 -> V_6 + V_4 ;
return F_4 ( V_5 ) ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
int V_5 = V_3 -> V_6 + V_4 ;
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_8 ( F_9 ( V_4 , V_7 ) ) & F_10 ( V_4 ) ;
}
static void F_11 ( struct V_2 * V_3 , unsigned V_4 , int V_8 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_11 ) ) ;
if ( V_8 )
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_11 ) ) ;
else
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_11 ) ) ;
F_14 ( V_9 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13 << ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
F_14 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_4 ,
int V_8 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_14 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_14 = V_10 & ( V_13 <<
( ( V_4 & 0x07 ) << 1 ) ) ;
if ( V_14 == 0 ) {
V_10 &= ~ ( V_13 <<
( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_15
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
}
F_11 ( V_3 , V_4 , V_8 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
int F_17 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_16 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_17 V_18 = (enum V_17 ) * V_16 ;
bool V_19 ;
T_1 V_20 ;
V_19 = ! ! ( F_8 ( F_9 ( V_4 , V_21 ) ) & F_10 ( V_4 ) ) ;
V_20 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_20 &= ( V_13 << ( ( V_4 & 0x07 ) << 1 ) ) ;
V_20 >>= ( ( V_4 & 0x07 ) << 1 ) ;
switch ( V_18 ) {
case V_22 :
* V_16 = 0 ;
if ( V_19 )
return 0 ;
else
return - V_23 ;
break;
case V_24 :
* V_16 = 0 ;
if ( ! V_19 )
return 0 ;
else
return - V_23 ;
break;
case V_25 :
* V_16 = 0 ;
if ( V_20 == V_15 )
return 0 ;
else
return - V_23 ;
break;
case V_26 :
* V_16 = 0 ;
if ( V_20 == V_27 )
return 0 ;
else
return - V_23 ;
break;
case V_28 :
* V_16 = 0 ;
if ( V_20 == V_29 )
return 0 ;
else
return - V_23 ;
break;
default:
break;
}
return - V_30 ;
}
int F_18 ( struct V_2 * V_3 , unsigned V_4 ,
enum V_17 V_18 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
switch ( V_18 ) {
case V_31 :
case V_22 :
V_10 = F_8 ( F_9 ( V_4 , V_21 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_21 ) ) ;
break;
case V_24 :
V_10 = F_8 ( F_9 ( V_4 , V_21 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_21 ) ) ;
break;
case V_25 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_15
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_26 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_27
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_28 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_29
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
default:
F_14 ( V_9 ) ;
F_19 ( V_5 -> V_32 , L_1 ) ;
return - V_23 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_10 ;
V_10 = F_8 ( F_9 ( V_4 , V_33 ) ) ;
if ( F_7 ( & V_5 -> V_3 , V_4 ) ) {
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
F_21 ( V_5 -> V_32 , L_2 ,
V_4 ) ;
} else {
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
F_21 ( V_5 -> V_32 , L_3 ,
V_4 ) ;
}
}
static int F_22 ( struct V_34 * V_35 , unsigned V_36 )
{
struct V_2 * V_3 = F_23 ( V_35 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_37 * V_38 = & V_5 -> V_39 [ V_35 -> V_40 >> 3 ] ;
int V_4 = V_35 -> V_40 ;
T_1 V_10 ;
if ( ( V_36 & V_41 ) &&
( V_36 & V_42 ) ) {
F_21 ( V_5 -> V_32 ,
L_4 ,
V_4 ) ;
V_38 -> V_43 |= F_10 ( V_4 ) ;
F_20 ( V_5 , V_4 ) ;
} else if ( V_36 & V_41 ) {
F_21 ( V_5 -> V_32 , L_5 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_33 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
V_38 -> V_43 &= ~ F_10 ( V_4 ) ;
} else if ( V_36 & V_42 ) {
F_21 ( V_5 -> V_32 , L_6 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_33 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
V_38 -> V_43 &= ~ F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_24 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_23 ( V_35 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_37 * V_38 = & V_5 -> V_39 [ V_35 -> V_40 >> 3 ] ;
int V_4 = V_35 -> V_40 ;
T_1 V_10 ;
unsigned long V_9 ;
F_21 ( V_5 -> V_32 , L_7 ,
V_35 -> V_40 , V_38 -> V_44 , V_4 ) ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_45 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_45 ) ) ;
F_14 ( V_9 ) ;
}
static void F_25 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_23 ( V_35 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_4 = V_35 -> V_40 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_45 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_45 ) ) ;
F_14 ( V_9 ) ;
}
static void F_26 ( unsigned V_46 , struct V_47 * V_48 )
{
struct V_49 * V_50 = F_27 ( V_46 ) ;
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_37 * V_38 = & V_5 -> V_39 [ V_46 - V_3 -> V_6 ] ;
int V_51 = V_38 -> V_52 << 3 ;
unsigned long V_10 ;
F_29 ( V_50 , V_48 ) ;
V_10 = F_8 ( F_9 ( V_51 , V_53 ) ) ;
V_10 &= 0xFFU ;
F_13 ( V_10 , F_9 ( V_51 , V_53 ) ) ;
if ( V_10 != 0 ) {
int V_54 ;
F_30 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_4 = V_51 + V_54 ;
int V_55 = F_31 ( V_3 -> V_56 , V_4 ) ;
F_21 ( V_5 -> V_32 , L_8 ,
V_55 , V_4 ) ;
F_32 ( V_55 ) ;
if ( V_38 -> V_43 & F_10 ( V_4 ) )
F_20 ( V_5 , V_4 ) ;
}
}
F_33 ( V_50 , V_48 ) ;
}
static void T_2 F_34 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_57 * V_58 )
{
if ( V_58 -> V_59 ) {
F_16 ( & V_5 -> V_3 , V_4 , V_58 -> V_60 ) ;
F_18 ( & V_5 -> V_3 , V_4 ,
V_22 ) ;
F_18 ( & V_5 -> V_3 , V_4 ,
V_25 ) ;
F_21 ( V_5 -> V_32 , L_9 ,
V_4 , V_58 -> V_60 ) ;
} else {
F_15 ( & V_5 -> V_3 , V_4 ) ;
F_11 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_18 ( & V_5 -> V_3 , V_4 , V_58 -> V_61 ) ;
F_21 ( V_5 -> V_32 , L_10 ,
V_4 , V_58 -> V_61 ) ;
}
}
static void T_2 F_35 ( struct V_1 * V_5 )
{
int V_62 , V_63 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ ) {
const struct V_57 * V_58 ;
int V_4 = ( V_62 * 8 ) + V_63 ;
V_58 = & V_65 [ V_62 ] [ V_63 ] ;
F_34 ( V_5 , V_4 , V_58 ) ;
}
}
}
static int T_2 F_36 ( struct V_66 * V_67 )
{
struct V_1 * V_5 ;
struct V_68 * V_69 ;
int V_70 = 0 ;
int V_71 ;
T_1 V_10 ;
T_1 V_72 ;
int V_62 ;
V_5 = F_37 ( & V_67 -> V_32 , sizeof( struct V_1 ) , V_73 ) ;
if ( V_5 == NULL )
return - V_74 ;
V_5 -> V_3 = V_75 ;
V_5 -> V_3 . V_76 = V_64 * V_77 ;
V_5 -> V_3 . V_32 = & V_67 -> V_32 ;
V_5 -> V_3 . V_6 = 0 ;
V_5 -> V_32 = & V_67 -> V_32 ;
V_69 = F_38 ( V_67 , V_78 , 0 ) ;
V_5 -> V_6 = F_39 ( & V_67 -> V_32 , V_69 ) ;
if ( F_40 ( V_5 -> V_6 ) )
return F_41 ( V_5 -> V_6 ) ;
V_5 -> V_79 = F_42 ( V_5 -> V_32 , NULL ) ;
if ( F_40 ( V_5 -> V_79 ) ) {
V_70 = F_41 ( V_5 -> V_79 ) ;
F_19 ( V_5 -> V_32 , L_11 ) ;
return V_70 ;
}
V_70 = F_43 ( V_5 -> V_79 ) ;
if ( V_70 ) {
F_19 ( V_5 -> V_32 , L_12 ) ;
return V_70 ;
}
F_44 ( V_5 -> V_32 ,
L_13 ) ;
V_5 -> V_80 = V_81 ;
V_5 -> V_12 = V_82 ;
V_5 -> V_11 = V_83 ;
V_5 -> V_7 = V_84 ;
V_5 -> V_21 = V_85 ;
V_5 -> V_33 = V_86 ;
V_5 -> V_45 = V_87 ;
V_5 -> V_53 = V_88 ;
V_72 = V_89 ;
V_10 = F_8 ( V_5 -> V_6 + V_90 ) ;
F_44 ( V_5 -> V_32 , L_14 \
L_15 ,
( ( V_10 & 0x000001FC ) >> 2 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_13 ( V_91 ,
V_5 -> V_6 + V_90 ) ;
F_35 ( V_5 ) ;
#ifdef F_45
V_5 -> V_3 . V_92 = V_67 -> V_32 . V_92 ;
#endif
V_70 = F_46 ( & V_5 -> V_3 ) ;
if ( V_70 ) {
F_19 ( V_5 -> V_32 , L_16 , V_70 ) ;
goto V_93;
}
V_70 = F_47 ( & V_5 -> V_3 ,
& V_94 ,
0 ,
V_95 ,
V_96 ) ;
if ( V_70 ) {
F_19 ( V_5 -> V_32 , L_17 ) ;
goto V_97;
}
for ( V_71 = 0 ; V_71 < V_64 ; V_71 ++ ) {
struct V_37 * V_38 = & V_5 -> V_39 [ V_71 ] ;
snprintf ( V_38 -> V_44 , 8 , L_18 , V_71 ) ;
V_38 -> V_52 = V_71 ;
V_38 -> V_5 = V_5 ;
V_38 -> V_46 = F_48 ( V_67 , V_71 ) ;
F_49 ( & V_5 -> V_3 ,
& V_94 ,
V_38 -> V_46 ,
F_26 ) ;
F_13 ( 0x0 , V_5 -> V_6 + V_71 * V_5 -> V_80 + V_72 ) ;
}
F_21 ( V_5 -> V_32 , L_19 , V_71 ) ;
for ( V_62 = 0 ; V_62 < F_50 ( V_98 ) ; V_62 ++ ) {
struct V_99 * V_100 = & V_98 [ V_62 ] ;
V_70 = F_51 ( & V_5 -> V_3 , L_20 ,
V_100 -> V_4 , V_100 -> V_101 , 1 ) ;
if ( V_70 )
goto V_102;
}
F_52 ( V_67 , V_5 ) ;
return 0 ;
V_102:
V_97:
F_53 ( & V_5 -> V_3 ) ;
V_93:
F_54 ( V_5 -> V_79 ) ;
F_19 ( & V_67 -> V_32 , L_21 , V_70 ) ;
return V_70 ;
}
static int T_3 F_55 ( struct V_66 * V_67 )
{
struct V_1 * V_5 = F_56 ( V_67 ) ;
F_13 ( 0x00000000U , V_5 -> V_6 + V_90 ) ;
F_53 ( & V_5 -> V_3 ) ;
F_54 ( V_5 -> V_79 ) ;
return 0 ;
}
static int T_2 F_57 ( void )
{
return F_58 ( & V_103 , F_36 ) ;
}
static void T_3 F_59 ( void )
{
F_60 ( & V_103 ) ;
}
