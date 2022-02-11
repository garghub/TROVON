static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ! ( F_3 ( F_4 ( V_3 , V_6 ) ) & F_5 ( V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_7 ( V_8 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_10 ) ) ;
if ( V_7 )
F_8 ( V_9 | F_5 ( V_3 ) , F_4 ( V_3 , V_10 ) ) ;
else
F_8 ( V_9 & ~ F_5 ( V_3 ) , F_4 ( V_3 , V_10 ) ) ;
F_9 ( V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_7 ( V_8 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_9 &= ~ ( V_12 << ( ( V_3 & 0x07 ) << 1 ) ) ;
F_8 ( V_9 , F_4 ( V_3 , V_11 ) ) ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
T_1 V_13 ;
T_1 V_9 ;
F_7 ( V_8 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_13 = V_9 & ( V_12 <<
( ( V_3 & 0x07 ) << 1 ) ) ;
if ( V_13 == 0 ) {
V_9 &= ~ ( V_12 <<
( ( V_3 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_14
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
F_8 ( V_9 , F_4 ( V_3 , V_11 ) ) ;
}
F_6 ( V_2 , V_3 , V_7 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned long * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
enum V_16 V_17 = (enum V_16 ) * V_15 ;
bool V_18 ;
T_1 V_19 ;
V_18 = ! ! ( F_3 ( F_4 ( V_3 , V_20 ) ) & F_5 ( V_3 ) ) ;
V_19 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_19 &= ( V_12 << ( ( V_3 & 0x07 ) << 1 ) ) ;
V_19 >>= ( ( V_3 & 0x07 ) << 1 ) ;
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
int F_13 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_16 V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_7 ( V_8 ) ;
switch ( V_17 ) {
case V_30 :
case V_21 :
V_9 = F_3 ( F_4 ( V_3 , V_20 ) ) ;
F_8 ( V_9 | F_5 ( V_3 ) , F_4 ( V_3 , V_20 ) ) ;
break;
case V_23 :
V_9 = F_3 ( F_4 ( V_3 , V_20 ) ) ;
F_8 ( V_9 & ~ F_5 ( V_3 ) , F_4 ( V_3 , V_20 ) ) ;
break;
case V_24 :
V_9 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_14
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
F_8 ( V_9 , F_4 ( V_3 , V_11 ) ) ;
break;
case V_25 :
V_9 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_26
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
F_8 ( V_9 , F_4 ( V_3 , V_11 ) ) ;
break;
case V_27 :
V_9 = F_3 ( F_4 ( V_3 , V_11 ) ) ;
V_9 &= ~ ( V_12
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
V_9 |= ( V_28
<< ( ( V_3 & 0x07 ) << 1 ) ) ;
F_8 ( V_9 , F_4 ( V_3 , V_11 ) ) ;
break;
default:
F_9 ( V_8 ) ;
F_14 ( V_5 -> V_31 , L_1 ) ;
return - V_22 ;
}
F_9 ( V_8 ) ;
return 0 ;
}
static void F_15 ( struct V_4 * V_5 , unsigned V_3 )
{
T_1 V_9 ;
V_9 = F_3 ( F_4 ( V_3 , V_32 ) ) ;
if ( F_1 ( & V_5 -> V_2 , V_3 ) ) {
F_8 ( V_9 & ~ F_5 ( V_3 ) , F_4 ( V_3 , V_32 ) ) ;
F_16 ( V_5 -> V_31 , L_2 ,
V_3 ) ;
} else {
F_8 ( V_9 | F_5 ( V_3 ) , F_4 ( V_3 , V_32 ) ) ;
F_16 ( V_5 -> V_31 , L_3 ,
V_3 ) ;
}
}
static int F_17 ( struct V_33 * V_34 , unsigned V_35 )
{
struct V_1 * V_2 = F_18 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_34 -> V_39 >> 3 ] ;
int V_3 = V_34 -> V_39 ;
T_1 V_9 ;
if ( ( V_35 & V_40 ) &&
( V_35 & V_41 ) ) {
F_16 ( V_5 -> V_31 ,
L_4 ,
V_3 ) ;
V_37 -> V_42 |= F_5 ( V_3 ) ;
F_15 ( V_5 , V_3 ) ;
} else if ( V_35 & V_40 ) {
F_16 ( V_5 -> V_31 , L_5 ,
V_3 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_32 ) ) ;
F_8 ( V_9 | F_5 ( V_3 ) , F_4 ( V_3 , V_32 ) ) ;
V_37 -> V_42 &= ~ F_5 ( V_3 ) ;
} else if ( V_35 & V_41 ) {
F_16 ( V_5 -> V_31 , L_6 ,
V_3 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_32 ) ) ;
F_8 ( V_9 & ~ F_5 ( V_3 ) , F_4 ( V_3 , V_32 ) ) ;
V_37 -> V_42 &= ~ F_5 ( V_3 ) ;
}
return 0 ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_18 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_34 -> V_39 >> 3 ] ;
int V_3 = V_34 -> V_39 ;
T_1 V_9 ;
unsigned long V_8 ;
F_16 ( V_5 -> V_31 , L_7 ,
V_34 -> V_39 , V_37 -> V_43 , V_3 ) ;
F_7 ( V_8 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_44 ) ) ;
F_8 ( V_9 | F_5 ( V_3 ) , F_4 ( V_3 , V_44 ) ) ;
F_9 ( V_8 ) ;
}
static void F_20 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_18 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 = V_34 -> V_39 ;
T_1 V_9 ;
unsigned long V_8 ;
F_7 ( V_8 ) ;
V_9 = F_3 ( F_4 ( V_3 , V_44 ) ) ;
F_8 ( V_9 & ~ F_5 ( V_3 ) , F_4 ( V_3 , V_44 ) ) ;
F_9 ( V_8 ) ;
}
static void F_21 ( struct V_45 * V_46 )
{
unsigned int V_47 = F_22 ( V_46 ) ;
struct V_48 * V_49 = F_23 ( V_46 ) ;
struct V_1 * V_2 = F_24 ( V_46 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_36 * V_37 = & V_5 -> V_38 [ V_47 - V_2 -> V_50 ] ;
int V_51 = V_37 -> V_52 << 3 ;
unsigned long V_9 ;
F_25 ( V_49 , V_46 ) ;
V_9 = F_3 ( F_4 ( V_51 , V_53 ) ) ;
V_9 &= 0xFFU ;
F_8 ( V_9 , F_4 ( V_51 , V_53 ) ) ;
if ( V_9 != 0 ) {
int V_54 ;
F_26 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_3 = V_51 + V_54 ;
int V_55 = F_27 ( V_2 -> V_56 , V_3 ) ;
F_16 ( V_5 -> V_31 , L_8 ,
V_55 , V_3 ) ;
F_28 ( V_55 ) ;
if ( V_37 -> V_42 & F_5 ( V_3 ) )
F_15 ( V_5 , V_3 ) ;
}
}
F_29 ( V_49 , V_46 ) ;
}
static void T_2 F_30 ( struct V_4 * V_5 ,
int V_3 ,
const struct V_57 * V_58 )
{
if ( V_58 -> V_59 ) {
F_11 ( & V_5 -> V_2 , V_3 , V_58 -> V_60 ) ;
F_13 ( & V_5 -> V_2 , V_3 ,
V_21 ) ;
F_13 ( & V_5 -> V_2 , V_3 ,
V_24 ) ;
F_16 ( V_5 -> V_31 , L_9 ,
V_3 , V_58 -> V_60 ) ;
} else {
F_10 ( & V_5 -> V_2 , V_3 ) ;
F_6 ( & V_5 -> V_2 , V_3 , 0 ) ;
F_13 ( & V_5 -> V_2 , V_3 , V_58 -> V_61 ) ;
F_16 ( V_5 -> V_31 , L_10 ,
V_3 , V_58 -> V_61 ) ;
}
}
static void T_2 F_31 ( struct V_4 * V_5 )
{
int V_62 , V_63 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ ) {
const struct V_57 * V_58 ;
int V_3 = ( V_62 * 8 ) + V_63 ;
V_58 = & V_65 [ V_62 ] [ V_63 ] ;
F_30 ( V_5 , V_3 , V_58 ) ;
}
}
}
static int T_2 F_32 ( struct V_66 * V_67 )
{
struct V_4 * V_5 ;
struct V_68 * V_69 ;
int V_70 = 0 ;
int V_71 ;
T_1 V_9 ;
T_1 V_72 ;
int V_62 ;
V_5 = F_33 ( & V_67 -> V_31 , sizeof( struct V_4 ) , V_73 ) ;
if ( V_5 == NULL )
return - V_74 ;
V_5 -> V_2 = V_75 ;
V_5 -> V_2 . V_76 = V_64 * V_77 ;
V_5 -> V_2 . V_78 = & V_67 -> V_31 ;
V_5 -> V_2 . V_50 = 0 ;
V_5 -> V_31 = & V_67 -> V_31 ;
V_69 = F_34 ( V_67 , V_79 , 0 ) ;
V_5 -> V_50 = F_35 ( & V_67 -> V_31 , V_69 ) ;
if ( F_36 ( V_5 -> V_50 ) )
return F_37 ( V_5 -> V_50 ) ;
V_5 -> V_80 = F_38 ( V_5 -> V_31 , NULL ) ;
if ( F_36 ( V_5 -> V_80 ) ) {
V_70 = F_37 ( V_5 -> V_80 ) ;
F_14 ( V_5 -> V_31 , L_11 ) ;
return V_70 ;
}
V_70 = F_39 ( V_5 -> V_80 ) ;
if ( V_70 ) {
F_14 ( V_5 -> V_31 , L_12 ) ;
return V_70 ;
}
F_40 ( V_5 -> V_31 ,
L_13 ) ;
V_5 -> V_81 = V_82 ;
V_5 -> V_11 = V_83 ;
V_5 -> V_10 = V_84 ;
V_5 -> V_6 = V_85 ;
V_5 -> V_20 = V_86 ;
V_5 -> V_32 = V_87 ;
V_5 -> V_44 = V_88 ;
V_5 -> V_53 = V_89 ;
V_72 = V_90 ;
V_9 = F_3 ( V_5 -> V_50 + V_91 ) ;
F_40 ( V_5 -> V_31 , L_14 \
L_15 ,
( ( V_9 & 0x000001FC ) >> 2 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_8 ( V_92 ,
V_5 -> V_50 + V_91 ) ;
F_31 ( V_5 ) ;
#ifdef F_41
V_5 -> V_2 . V_93 = V_67 -> V_31 . V_93 ;
#endif
V_70 = F_42 ( & V_5 -> V_2 , V_5 ) ;
if ( V_70 ) {
F_14 ( V_5 -> V_31 , L_16 , V_70 ) ;
goto V_94;
}
V_70 = F_43 ( & V_5 -> V_2 ,
& V_95 ,
0 ,
V_96 ,
V_97 ) ;
if ( V_70 ) {
F_14 ( V_5 -> V_31 , L_17 ) ;
goto V_98;
}
for ( V_71 = 0 ; V_71 < V_64 ; V_71 ++ ) {
struct V_36 * V_37 = & V_5 -> V_38 [ V_71 ] ;
snprintf ( V_37 -> V_43 , 8 , L_18 , V_71 ) ;
V_37 -> V_52 = V_71 ;
V_37 -> V_5 = V_5 ;
V_37 -> V_47 = F_44 ( V_67 , V_71 ) ;
F_45 ( & V_5 -> V_2 ,
& V_95 ,
V_37 -> V_47 ,
F_21 ) ;
F_8 ( 0x0 , V_5 -> V_50 + V_71 * V_5 -> V_81 + V_72 ) ;
}
F_16 ( V_5 -> V_31 , L_19 , V_71 ) ;
for ( V_62 = 0 ; V_62 < F_46 ( V_99 ) ; V_62 ++ ) {
struct V_100 * V_101 = & V_99 [ V_62 ] ;
V_70 = F_47 ( & V_5 -> V_2 , L_20 ,
V_101 -> V_3 , V_101 -> V_102 , 1 ) ;
if ( V_70 )
goto V_103;
}
F_48 ( V_67 , V_5 ) ;
return 0 ;
V_103:
V_98:
F_49 ( & V_5 -> V_2 ) ;
V_94:
F_50 ( V_5 -> V_80 ) ;
F_14 ( & V_67 -> V_31 , L_21 , V_70 ) ;
return V_70 ;
}
static int T_3 F_51 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_52 ( V_67 ) ;
F_8 ( 0x00000000U , V_5 -> V_50 + V_91 ) ;
F_49 ( & V_5 -> V_2 ) ;
F_50 ( V_5 -> V_80 ) ;
return 0 ;
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_104 , F_32 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_104 ) ;
}
