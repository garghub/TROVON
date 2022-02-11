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
static int F_17 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_16 = V_4 >> 3 ;
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 ;
int V_21 ;
bool V_22 = false ;
F_18 (p, &gpio->port_list) {
V_18 = F_19 ( V_20 , struct V_17 , V_23 ) ;
if ( V_18 -> V_24 == V_16 ) {
V_22 = true ;
break;
}
}
if ( ! V_22 ) {
F_20 ( V_5 -> V_25 , L_1 ,
V_4 ) ;
return - V_26 ;
}
V_21 = F_21 ( V_18 -> V_27 , ( V_4 & 0x7 ) ) ;
F_22 ( V_5 -> V_25 , L_2 ,
V_4 , V_21 , V_18 -> V_24 ) ;
return V_21 ;
}
int F_23 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_28 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_29 V_30 = (enum V_29 ) * V_28 ;
bool V_31 ;
T_1 V_32 ;
V_31 = ! ! ( F_8 ( F_9 ( V_4 , V_33 ) ) & F_10 ( V_4 ) ) ;
V_32 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_32 &= ( V_13 << ( ( V_4 & 0x07 ) << 1 ) ) ;
V_32 >>= ( ( V_4 & 0x07 ) << 1 ) ;
switch ( V_30 ) {
case V_34 :
* V_28 = 0 ;
if ( V_31 )
return 0 ;
else
return - V_26 ;
break;
case V_35 :
* V_28 = 0 ;
if ( ! V_31 )
return 0 ;
else
return - V_26 ;
break;
case V_36 :
* V_28 = 0 ;
if ( V_32 == V_15 )
return 0 ;
else
return - V_26 ;
break;
case V_37 :
* V_28 = 0 ;
if ( V_32 == V_38 )
return 0 ;
else
return - V_26 ;
break;
case V_39 :
* V_28 = 0 ;
if ( V_32 == V_40 )
return 0 ;
else
return - V_26 ;
break;
default:
break;
}
return - V_41 ;
}
int F_24 ( struct V_2 * V_3 , unsigned V_4 ,
enum V_29 V_30 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
switch ( V_30 ) {
case V_42 :
case V_34 :
V_10 = F_8 ( F_9 ( V_4 , V_33 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
break;
case V_35 :
V_10 = F_8 ( F_9 ( V_4 , V_33 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_33 ) ) ;
break;
case V_36 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_15
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_37 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_38
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_39 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_40
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
default:
F_14 ( V_9 ) ;
F_20 ( V_5 -> V_25 , L_3 ) ;
return - V_26 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_10 ;
V_10 = F_8 ( F_9 ( V_4 , V_43 ) ) ;
if ( F_7 ( & V_5 -> V_3 , V_4 ) ) {
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_43 ) ) ;
F_22 ( V_5 -> V_25 , L_4 ,
V_4 ) ;
} else {
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_43 ) ) ;
F_22 ( V_5 -> V_25 , L_5 ,
V_4 ) ;
}
}
static int F_26 ( struct V_44 * V_45 , unsigned V_46 )
{
struct V_17 * V_18 = F_27 ( V_45 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_24 << 3 ) + V_45 -> V_47 ;
T_1 V_10 ;
if ( ( V_46 & V_48 ) &&
( V_46 & V_49 ) ) {
F_22 ( V_5 -> V_25 ,
L_6 ,
V_4 ) ;
V_18 -> V_50 |= F_10 ( V_4 ) ;
F_25 ( V_5 , V_4 ) ;
} else if ( V_46 & V_48 ) {
F_22 ( V_5 -> V_25 , L_7 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_43 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_43 ) ) ;
V_18 -> V_50 &= ~ F_10 ( V_4 ) ;
} else if ( V_46 & V_49 ) {
F_22 ( V_5 -> V_25 , L_8 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_43 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_43 ) ) ;
V_18 -> V_50 &= ~ F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_28 ( struct V_44 * V_45 )
{
struct V_17 * V_18 = F_27 ( V_45 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_24 << 3 ) + V_45 -> V_47 ;
T_1 V_10 ;
unsigned long V_9 ;
F_22 ( V_5 -> V_25 , L_9 ,
V_45 -> V_47 , V_18 -> V_51 , V_4 ) ;
if ( F_29 ( & V_5 -> V_3 , V_45 -> V_47 ) )
F_20 ( V_5 -> V_25 ,
L_10 ,
V_45 -> V_47 ) ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_52 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_52 ) ) ;
F_14 ( V_9 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_17 * V_18 = F_27 ( V_45 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_24 << 3 ) + V_45 -> V_47 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_52 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_52 ) ) ;
F_14 ( V_9 ) ;
F_31 ( & V_5 -> V_3 , V_45 -> V_47 ) ;
}
static void F_32 ( unsigned V_53 , struct V_54 * V_55 )
{
struct V_17 * V_18 = F_33 ( V_53 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_56 = V_18 -> V_24 << 3 ;
unsigned long V_10 ;
V_55 -> V_44 . V_3 -> V_57 ( & V_55 -> V_44 ) ;
V_10 = F_8 ( F_9 ( V_56 , V_58 ) ) ;
V_10 &= 0xFFU ;
F_13 ( V_10 , F_9 ( V_56 , V_58 ) ) ;
if ( V_10 != 0 ) {
int V_59 ;
F_34 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_60 = F_21 ( V_18 -> V_27 , V_59 ) ;
int V_4 = V_56 + V_59 ;
F_22 ( V_5 -> V_25 , L_11 ,
V_60 , V_4 ) ;
F_35 ( V_60 ) ;
if ( V_18 -> V_50 & F_10 ( V_4 ) )
F_25 ( V_5 , V_4 ) ;
}
}
V_55 -> V_44 . V_3 -> V_61 ( & V_55 -> V_44 ) ;
}
static void T_2 F_36 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_62 * V_63 )
{
if ( V_63 -> V_64 ) {
F_16 ( & V_5 -> V_3 , V_4 , V_63 -> V_65 ) ;
F_24 ( & V_5 -> V_3 , V_4 ,
V_34 ) ;
F_24 ( & V_5 -> V_3 , V_4 ,
V_36 ) ;
F_22 ( V_5 -> V_25 , L_12 ,
V_4 , V_63 -> V_65 ) ;
} else {
F_15 ( & V_5 -> V_3 , V_4 ) ;
F_11 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_24 ( & V_5 -> V_3 , V_4 , V_63 -> V_66 ) ;
F_22 ( V_5 -> V_25 , L_13 ,
V_4 , V_63 -> V_66 ) ;
}
}
static void T_2 F_37 ( struct V_1 * V_5 )
{
int V_67 , V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ ) {
const struct V_62 * V_63 ;
int V_4 = ( V_67 * 8 ) + V_68 ;
V_63 = & V_70 [ V_67 ] [ V_68 ] ;
F_36 ( V_5 , V_4 , V_63 ) ;
}
}
}
static inline void F_38 ( struct V_1 * V_5 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_71 ;
F_39 (p, n, &gpio->port_list) {
V_18 = F_19 ( V_20 , struct V_17 , V_23 ) ;
F_40 ( & V_18 -> V_23 ) ;
if ( V_18 -> V_27 )
F_41 ( V_18 -> V_27 ) ;
F_42 ( V_18 ) ;
}
}
static int T_2 F_43 ( struct V_72 * V_73 )
{
struct V_1 * V_5 ;
struct V_74 * V_75 ;
int V_76 = 0 ;
int V_16 ;
T_1 V_10 ;
T_1 V_77 ;
int V_67 ;
V_5 = F_44 ( & V_73 -> V_25 , sizeof( struct V_1 ) , V_78 ) ;
if ( V_5 == NULL )
return - V_79 ;
V_5 -> V_3 = V_80 ;
V_5 -> V_3 . V_81 = V_69 * V_82 ;
V_5 -> V_3 . V_25 = & V_73 -> V_25 ;
V_5 -> V_3 . V_6 = 0 ;
V_5 -> V_25 = & V_73 -> V_25 ;
V_75 = F_45 ( V_73 , V_83 , 0 ) ;
V_5 -> V_6 = F_46 ( & V_73 -> V_25 , V_75 ) ;
if ( F_47 ( V_5 -> V_6 ) )
return F_48 ( V_5 -> V_6 ) ;
V_5 -> V_84 = F_49 ( V_5 -> V_25 , NULL ) ;
if ( F_47 ( V_5 -> V_84 ) ) {
V_76 = F_48 ( V_5 -> V_84 ) ;
F_20 ( V_5 -> V_25 , L_14 ) ;
return V_76 ;
}
V_76 = F_50 ( V_5 -> V_84 ) ;
if ( V_76 ) {
F_20 ( V_5 -> V_25 , L_15 ) ;
return V_76 ;
}
F_51 ( V_5 -> V_25 ,
L_16 ) ;
V_5 -> V_85 = V_86 ;
V_5 -> V_12 = V_87 ;
V_5 -> V_11 = V_88 ;
V_5 -> V_7 = V_89 ;
V_5 -> V_33 = V_90 ;
V_5 -> V_43 = V_91 ;
V_5 -> V_52 = V_92 ;
V_5 -> V_58 = V_93 ;
V_77 = V_94 ;
V_10 = F_8 ( V_5 -> V_6 + V_95 ) ;
F_51 ( V_5 -> V_25 , L_17 \
L_18 ,
( ( V_10 & 0x000001FC ) >> 2 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_13 ( V_96 ,
V_5 -> V_6 + V_95 ) ;
F_37 ( V_5 ) ;
F_52 ( & V_5 -> V_97 ) ;
for ( V_16 = 0 ; V_16 < V_69 ; V_16 ++ ) {
struct V_17 * V_18 =
F_53 ( sizeof( struct V_17 ) , V_78 ) ;
if ( ! V_18 ) {
F_20 ( V_5 -> V_25 , L_19 ) ;
V_76 = - V_79 ;
goto V_98;
}
snprintf ( V_18 -> V_51 , 8 , L_20 , V_16 ) ;
V_18 -> V_24 = V_16 ;
V_18 -> V_5 = V_5 ;
V_18 -> V_53 = F_54 ( V_73 , V_16 ) ;
F_22 ( V_5 -> V_25 , L_21 , V_18 -> V_53 ,
V_18 -> V_51 ) ;
V_18 -> V_27 = F_55 ( V_73 -> V_25 . V_99 ,
V_82 ,
& V_100 ,
V_18 ) ;
if ( ! V_18 -> V_27 ) {
V_76 = - V_79 ;
goto V_101;
}
F_56 ( V_18 -> V_53 , F_32 ) ;
F_57 ( V_18 -> V_53 , V_18 ) ;
for ( V_67 = 0 ; V_67 < V_82 ; V_67 ++ ) {
int V_102 = F_58 ( V_18 -> V_27 , V_67 ) ;
F_22 ( V_5 -> V_25 , L_22 ,
V_5 -> V_3 . V_6 + ( V_18 -> V_24 << 3 ) + V_67 ,
V_18 -> V_51 , V_102 ) ;
F_59 ( V_102 , & V_103 ,
V_104 ) ;
F_60 ( V_102 , V_105 ) ;
F_61 ( V_102 , V_18 ) ;
}
F_13 ( 0x0 , V_5 -> V_6 + V_16 * V_5 -> V_85 + V_77 ) ;
F_62 ( & V_18 -> V_23 , & V_5 -> V_97 ) ;
}
F_22 ( V_5 -> V_25 , L_23 , V_16 ) ;
#ifdef F_63
V_5 -> V_3 . V_99 = V_73 -> V_25 . V_99 ;
#endif
V_76 = F_64 ( & V_5 -> V_3 ) ;
if ( V_76 ) {
F_20 ( V_5 -> V_25 , L_24 , V_76 ) ;
goto V_106;
}
for ( V_67 = 0 ; V_67 < F_65 ( V_107 ) ; V_67 ++ ) {
struct V_108 * V_20 = & V_107 [ V_67 ] ;
V_76 = F_66 ( & V_5 -> V_3 , L_25 ,
V_20 -> V_4 , V_20 -> V_109 , 1 ) ;
if ( V_76 )
goto V_110;
}
F_67 ( V_73 , V_5 ) ;
return 0 ;
V_110:
if ( F_68 ( & V_5 -> V_3 ) )
F_20 ( & V_73 -> V_25 , L_26 ) ;
V_106:
V_101:
V_98:
F_38 ( V_5 ) ;
F_69 ( V_5 -> V_84 ) ;
F_20 ( & V_73 -> V_25 , L_27 , V_76 ) ;
return V_76 ;
}
static int T_3 F_70 ( struct V_72 * V_73 )
{
struct V_1 * V_5 = F_71 ( V_73 ) ;
int V_76 ;
F_13 ( 0x00000000U , V_5 -> V_6 + V_95 ) ;
V_76 = F_68 ( & V_5 -> V_3 ) ;
if ( V_76 < 0 ) {
F_20 ( V_5 -> V_25 , L_28 , V_76 ) ;
return V_76 ;
}
F_38 ( V_5 ) ;
F_69 ( V_5 -> V_84 ) ;
return 0 ;
}
static int T_2 F_72 ( void )
{
return F_73 ( & V_111 , F_43 ) ;
}
static void T_3 F_74 ( void )
{
F_75 ( & V_111 ) ;
}
