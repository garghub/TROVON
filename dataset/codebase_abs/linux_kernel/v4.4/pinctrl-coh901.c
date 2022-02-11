static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_4 ( F_5 ( V_4 , V_6 ) ) & F_6 ( V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_4 , int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_10 ) ) ;
if ( V_7 )
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_10 ) ) ;
else
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_10 ) ) ;
F_10 ( V_8 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_9 &= ~ ( V_12 << ( ( V_4 & 0x07 ) << 1 ) ) ;
F_9 ( V_9 , F_5 ( V_4 , V_11 ) ) ;
F_10 ( V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_4 ,
int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_13 ;
T_1 V_9 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_13 = V_9 & ( V_12 <<
( ( V_4 & 0x07 ) << 1 ) ) ;
if ( V_13 == 0 ) {
V_9 &= ~ ( V_12 <<
( ( V_4 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_14
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_9 ( V_9 , F_5 ( V_4 , V_11 ) ) ;
}
F_7 ( V_3 , V_4 , V_7 ) ;
F_10 ( V_8 ) ;
return 0 ;
}
int F_13 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_16 V_17 = (enum V_16 ) * V_15 ;
bool V_18 ;
T_1 V_19 ;
V_18 = ! ! ( F_4 ( F_5 ( V_4 , V_20 ) ) & F_6 ( V_4 ) ) ;
V_19 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_19 &= ( V_12 << ( ( V_4 & 0x07 ) << 1 ) ) ;
V_19 >>= ( ( V_4 & 0x07 ) << 1 ) ;
switch ( V_17 ) {
case V_21 :
* V_15 = 0 ;
if ( V_18 )
return 0 ;
else
return - V_22 ;
break;
case V_23 :
* V_15 = 0 ;
if ( ! V_18 )
return 0 ;
else
return - V_22 ;
break;
case V_24 :
* V_15 = 0 ;
if ( V_19 == V_14 )
return 0 ;
else
return - V_22 ;
break;
case V_25 :
* V_15 = 0 ;
if ( V_19 == V_26 )
return 0 ;
else
return - V_22 ;
break;
case V_27 :
* V_15 = 0 ;
if ( V_19 == V_28 )
return 0 ;
else
return - V_22 ;
break;
default:
break;
}
return - V_29 ;
}
int F_14 ( struct V_2 * V_3 , unsigned V_4 ,
enum V_16 V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_8 ( V_8 ) ;
switch ( V_17 ) {
case V_30 :
case V_21 :
V_9 = F_4 ( F_5 ( V_4 , V_20 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_20 ) ) ;
break;
case V_23 :
V_9 = F_4 ( F_5 ( V_4 , V_20 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_20 ) ) ;
break;
case V_24 :
V_9 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_14
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_9 ( V_9 , F_5 ( V_4 , V_11 ) ) ;
break;
case V_25 :
V_9 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_26
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_9 ( V_9 , F_5 ( V_4 , V_11 ) ) ;
break;
case V_27 :
V_9 = F_4 ( F_5 ( V_4 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_28
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_9 ( V_9 , F_5 ( V_4 , V_11 ) ) ;
break;
default:
F_10 ( V_8 ) ;
F_15 ( V_5 -> V_31 , L_1 ) ;
return - V_22 ;
}
F_10 ( V_8 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_9 ;
V_9 = F_4 ( F_5 ( V_4 , V_32 ) ) ;
if ( F_3 ( & V_5 -> V_3 , V_4 ) ) {
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_32 ) ) ;
F_17 ( V_5 -> V_31 , L_2 ,
V_4 ) ;
} else {
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_32 ) ) ;
F_17 ( V_5 -> V_31 , L_3 ,
V_4 ) ;
}
}
static int F_18 ( struct V_33 * V_34 , unsigned V_35 )
{
struct V_2 * V_3 = F_19 ( V_34 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_34 -> V_39 >> 3 ] ;
int V_4 = V_34 -> V_39 ;
T_1 V_9 ;
if ( ( V_35 & V_40 ) &&
( V_35 & V_41 ) ) {
F_17 ( V_5 -> V_31 ,
L_4 ,
V_4 ) ;
V_37 -> V_42 |= F_6 ( V_4 ) ;
F_16 ( V_5 , V_4 ) ;
} else if ( V_35 & V_40 ) {
F_17 ( V_5 -> V_31 , L_5 ,
V_4 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_32 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_32 ) ) ;
V_37 -> V_42 &= ~ F_6 ( V_4 ) ;
} else if ( V_35 & V_41 ) {
F_17 ( V_5 -> V_31 , L_6 ,
V_4 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_32 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_32 ) ) ;
V_37 -> V_42 &= ~ F_6 ( V_4 ) ;
}
return 0 ;
}
static void F_20 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_19 ( V_34 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_34 -> V_39 >> 3 ] ;
int V_4 = V_34 -> V_39 ;
T_1 V_9 ;
unsigned long V_8 ;
F_17 ( V_5 -> V_31 , L_7 ,
V_34 -> V_39 , V_37 -> V_43 , V_4 ) ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_44 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_44 ) ) ;
F_10 ( V_8 ) ;
}
static void F_21 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_19 ( V_34 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_4 = V_34 -> V_39 ;
T_1 V_9 ;
unsigned long V_8 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_44 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_44 ) ) ;
F_10 ( V_8 ) ;
}
static void F_22 ( struct V_45 * V_46 )
{
unsigned int V_47 = F_23 ( V_46 ) ;
struct V_48 * V_49 = F_24 ( V_46 ) ;
struct V_2 * V_3 = F_25 ( V_46 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_47 - V_3 -> V_50 ] ;
int V_51 = V_37 -> V_52 << 3 ;
unsigned long V_9 ;
F_26 ( V_49 , V_46 ) ;
V_9 = F_4 ( F_5 ( V_51 , V_53 ) ) ;
V_9 &= 0xFFU ;
F_9 ( V_9 , F_5 ( V_51 , V_53 ) ) ;
if ( V_9 != 0 ) {
int V_54 ;
F_27 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_4 = V_51 + V_54 ;
int V_55 = F_28 ( V_3 -> V_56 , V_4 ) ;
F_17 ( V_5 -> V_31 , L_8 ,
V_55 , V_4 ) ;
F_29 ( V_55 ) ;
if ( V_37 -> V_42 & F_6 ( V_4 ) )
F_16 ( V_5 , V_4 ) ;
}
}
F_30 ( V_49 , V_46 ) ;
}
static void T_2 F_31 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_57 * V_58 )
{
if ( V_58 -> V_59 ) {
F_12 ( & V_5 -> V_3 , V_4 , V_58 -> V_60 ) ;
F_14 ( & V_5 -> V_3 , V_4 ,
V_21 ) ;
F_14 ( & V_5 -> V_3 , V_4 ,
V_24 ) ;
F_17 ( V_5 -> V_31 , L_9 ,
V_4 , V_58 -> V_60 ) ;
} else {
F_11 ( & V_5 -> V_3 , V_4 ) ;
F_7 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_14 ( & V_5 -> V_3 , V_4 , V_58 -> V_61 ) ;
F_17 ( V_5 -> V_31 , L_10 ,
V_4 , V_58 -> V_61 ) ;
}
}
static void T_2 F_32 ( struct V_1 * V_5 )
{
int V_62 , V_63 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ ) {
const struct V_57 * V_58 ;
int V_4 = ( V_62 * 8 ) + V_63 ;
V_58 = & V_65 [ V_62 ] [ V_63 ] ;
F_31 ( V_5 , V_4 , V_58 ) ;
}
}
}
static int T_2 F_33 ( struct V_66 * V_67 )
{
struct V_1 * V_5 ;
struct V_68 * V_69 ;
int V_70 = 0 ;
int V_71 ;
T_1 V_9 ;
T_1 V_72 ;
int V_62 ;
V_5 = F_34 ( & V_67 -> V_31 , sizeof( struct V_1 ) , V_73 ) ;
if ( V_5 == NULL )
return - V_74 ;
V_5 -> V_3 = V_75 ;
V_5 -> V_3 . V_76 = V_64 * V_77 ;
V_5 -> V_3 . V_31 = & V_67 -> V_31 ;
V_5 -> V_3 . V_50 = 0 ;
V_5 -> V_31 = & V_67 -> V_31 ;
V_69 = F_35 ( V_67 , V_78 , 0 ) ;
V_5 -> V_50 = F_36 ( & V_67 -> V_31 , V_69 ) ;
if ( F_37 ( V_5 -> V_50 ) )
return F_38 ( V_5 -> V_50 ) ;
V_5 -> V_79 = F_39 ( V_5 -> V_31 , NULL ) ;
if ( F_37 ( V_5 -> V_79 ) ) {
V_70 = F_38 ( V_5 -> V_79 ) ;
F_15 ( V_5 -> V_31 , L_11 ) ;
return V_70 ;
}
V_70 = F_40 ( V_5 -> V_79 ) ;
if ( V_70 ) {
F_15 ( V_5 -> V_31 , L_12 ) ;
return V_70 ;
}
F_41 ( V_5 -> V_31 ,
L_13 ) ;
V_5 -> V_80 = V_81 ;
V_5 -> V_11 = V_82 ;
V_5 -> V_10 = V_83 ;
V_5 -> V_6 = V_84 ;
V_5 -> V_20 = V_85 ;
V_5 -> V_32 = V_86 ;
V_5 -> V_44 = V_87 ;
V_5 -> V_53 = V_88 ;
V_72 = V_89 ;
V_9 = F_4 ( V_5 -> V_50 + V_90 ) ;
F_41 ( V_5 -> V_31 , L_14 \
L_15 ,
( ( V_9 & 0x000001FC ) >> 2 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_9 ( V_91 ,
V_5 -> V_50 + V_90 ) ;
F_32 ( V_5 ) ;
#ifdef F_42
V_5 -> V_3 . V_92 = V_67 -> V_31 . V_92 ;
#endif
V_70 = F_43 ( & V_5 -> V_3 ) ;
if ( V_70 ) {
F_15 ( V_5 -> V_31 , L_16 , V_70 ) ;
goto V_93;
}
V_70 = F_44 ( & V_5 -> V_3 ,
& V_94 ,
0 ,
V_95 ,
V_96 ) ;
if ( V_70 ) {
F_15 ( V_5 -> V_31 , L_17 ) ;
goto V_97;
}
for ( V_71 = 0 ; V_71 < V_64 ; V_71 ++ ) {
struct V_36 * V_37 = & V_5 -> V_38 [ V_71 ] ;
snprintf ( V_37 -> V_43 , 8 , L_18 , V_71 ) ;
V_37 -> V_52 = V_71 ;
V_37 -> V_5 = V_5 ;
V_37 -> V_47 = F_45 ( V_67 , V_71 ) ;
F_46 ( & V_5 -> V_3 ,
& V_94 ,
V_37 -> V_47 ,
F_22 ) ;
F_9 ( 0x0 , V_5 -> V_50 + V_71 * V_5 -> V_80 + V_72 ) ;
}
F_17 ( V_5 -> V_31 , L_19 , V_71 ) ;
for ( V_62 = 0 ; V_62 < F_47 ( V_98 ) ; V_62 ++ ) {
struct V_99 * V_100 = & V_98 [ V_62 ] ;
V_70 = F_48 ( & V_5 -> V_3 , L_20 ,
V_100 -> V_4 , V_100 -> V_101 , 1 ) ;
if ( V_70 )
goto V_102;
}
F_49 ( V_67 , V_5 ) ;
return 0 ;
V_102:
V_97:
F_50 ( & V_5 -> V_3 ) ;
V_93:
F_51 ( V_5 -> V_79 ) ;
F_15 ( & V_67 -> V_31 , L_21 , V_70 ) ;
return V_70 ;
}
static int T_3 F_52 ( struct V_66 * V_67 )
{
struct V_1 * V_5 = F_53 ( V_67 ) ;
F_9 ( 0x00000000U , V_5 -> V_50 + V_90 ) ;
F_50 ( & V_5 -> V_3 ) ;
F_51 ( V_5 -> V_79 ) ;
return 0 ;
}
static int T_2 F_54 ( void )
{
return F_55 ( & V_103 , F_33 ) ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_103 ) ;
}
