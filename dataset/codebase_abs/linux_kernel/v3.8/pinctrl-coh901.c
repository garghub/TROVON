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
F_18 (p, &gpio->port_list) {
V_18 = F_19 ( V_20 , struct V_17 , V_22 ) ;
if ( V_18 -> V_23 == V_16 )
break;
}
if ( V_18 == NULL ) {
F_20 ( V_5 -> V_24 , L_1 ,
V_4 ) ;
return - V_25 ;
}
V_21 = F_21 ( V_18 -> V_26 , ( V_4 & 0x7 ) ) ;
F_22 ( V_5 -> V_24 , L_2 ,
V_4 , V_21 , V_18 -> V_23 ) ;
return V_21 ;
}
int F_23 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_27 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_28 V_29 = (enum V_28 ) * V_27 ;
bool V_30 ;
T_1 V_31 ;
V_30 = ! ! ( F_8 ( F_9 ( V_4 , V_32 ) ) & F_10 ( V_4 ) ) ;
V_31 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_31 &= ( V_13 << ( ( V_4 & 0x07 ) << 1 ) ) ;
V_31 >>= ( ( V_4 & 0x07 ) << 1 ) ;
switch( V_29 ) {
case V_33 :
* V_27 = 0 ;
if ( V_30 )
return 0 ;
else
return - V_25 ;
break;
case V_34 :
* V_27 = 0 ;
if ( ! V_30 )
return 0 ;
else
return - V_25 ;
break;
case V_35 :
* V_27 = 0 ;
if ( V_31 == V_15 )
return 0 ;
else
return - V_25 ;
break;
case V_36 :
* V_27 = 0 ;
if ( V_31 == V_37 )
return 0 ;
else
return - V_25 ;
break;
case V_38 :
* V_27 = 0 ;
if ( V_31 == V_39 )
return 0 ;
else
return - V_25 ;
break;
default:
break;
}
return - V_40 ;
}
int F_24 ( struct V_2 * V_3 , unsigned V_4 ,
enum V_28 V_29 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
switch ( V_29 ) {
case V_41 :
case V_33 :
V_10 = F_8 ( F_9 ( V_4 , V_32 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_32 ) ) ;
break;
case V_34 :
V_10 = F_8 ( F_9 ( V_4 , V_32 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_32 ) ) ;
break;
case V_35 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_15
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_36 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_37
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_38 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_39
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
default:
F_14 ( V_9 ) ;
F_20 ( V_5 -> V_24 , L_3 ) ;
return - V_25 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_10 ;
V_10 = F_8 ( F_9 ( V_4 , V_42 ) ) ;
if ( F_7 ( & V_5 -> V_3 , V_4 ) ) {
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_42 ) ) ;
F_22 ( V_5 -> V_24 , L_4 ,
V_4 ) ;
} else {
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_42 ) ) ;
F_22 ( V_5 -> V_24 , L_5 ,
V_4 ) ;
}
}
static int F_26 ( struct V_43 * V_44 , unsigned V_45 )
{
struct V_17 * V_18 = F_27 ( V_44 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_23 << 3 ) + V_44 -> V_46 ;
T_1 V_10 ;
if ( ( V_45 & V_47 ) &&
( V_45 & V_48 ) ) {
F_22 ( V_5 -> V_24 ,
L_6 ,
V_4 ) ;
V_18 -> V_49 |= F_10 ( V_4 ) ;
F_25 ( V_5 , V_4 ) ;
} else if ( V_45 & V_47 ) {
F_22 ( V_5 -> V_24 , L_7 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_42 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_42 ) ) ;
V_18 -> V_49 &= ~ F_10 ( V_4 ) ;
} else if ( V_45 & V_48 ) {
F_22 ( V_5 -> V_24 , L_8 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_42 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_42 ) ) ;
V_18 -> V_49 &= ~ F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_28 ( struct V_43 * V_44 )
{
struct V_17 * V_18 = F_27 ( V_44 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_23 << 3 ) + V_44 -> V_46 ;
T_1 V_10 ;
unsigned long V_9 ;
F_22 ( V_5 -> V_24 , L_9 ,
V_44 -> V_46 , V_18 -> V_50 , V_4 ) ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_51 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_51 ) ) ;
F_14 ( V_9 ) ;
}
static void F_29 ( struct V_43 * V_44 )
{
struct V_17 * V_18 = F_27 ( V_44 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_4 = ( V_18 -> V_23 << 3 ) + V_44 -> V_46 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_51 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_51 ) ) ;
F_14 ( V_9 ) ;
}
static void F_30 ( unsigned V_52 , struct V_53 * V_54 )
{
struct V_17 * V_18 = F_31 ( V_52 ) ;
struct V_1 * V_5 = V_18 -> V_5 ;
int V_55 = V_18 -> V_23 << 3 ;
unsigned long V_10 ;
V_54 -> V_43 . V_3 -> V_56 ( & V_54 -> V_43 ) ;
V_10 = F_8 ( F_9 ( V_55 , V_57 ) ) ;
V_10 &= 0xFFU ;
F_13 ( V_10 , F_9 ( V_55 , V_57 ) ) ;
if ( V_10 != 0 ) {
int V_58 ;
F_32 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_59 = F_21 ( V_18 -> V_26 , V_58 ) ;
int V_4 = V_55 + V_58 ;
F_22 ( V_5 -> V_24 , L_10 ,
V_59 , V_4 ) ;
F_33 ( V_59 ) ;
if ( V_18 -> V_49 & F_10 ( V_4 ) )
F_25 ( V_5 , V_4 ) ;
}
}
V_54 -> V_43 . V_3 -> V_60 ( & V_54 -> V_43 ) ;
}
static void T_2 F_34 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_61 * V_62 )
{
if ( V_62 -> V_63 ) {
F_16 ( & V_5 -> V_3 , V_4 , V_62 -> V_64 ) ;
F_24 ( & V_5 -> V_3 , V_4 ,
V_33 ) ;
F_24 ( & V_5 -> V_3 , V_4 ,
V_35 ) ;
F_22 ( V_5 -> V_24 , L_11 ,
V_4 , V_62 -> V_64 ) ;
} else {
F_15 ( & V_5 -> V_3 , V_4 ) ;
F_11 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_24 ( & V_5 -> V_3 , V_4 , V_62 -> V_65 ) ;
F_22 ( V_5 -> V_24 , L_12 ,
V_4 , V_62 -> V_65 ) ;
}
}
static void T_2 F_35 ( struct V_1 * V_5 ,
struct V_66 * V_67 )
{
int V_68 , V_69 ;
for ( V_68 = 0 ; V_68 < V_67 -> V_70 ; V_68 ++ ) {
for ( V_69 = 0 ; V_69 < 8 ; V_69 ++ ) {
const struct V_61 * V_62 ;
int V_4 = ( V_68 * 8 ) + V_69 ;
V_62 = & V_71 [ V_68 ] [ V_69 ] ;
F_34 ( V_5 , V_4 , V_62 ) ;
}
}
}
static inline void F_36 ( struct V_1 * V_5 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_72 ;
F_37 (p, n, &gpio->port_list) {
V_18 = F_19 ( V_20 , struct V_17 , V_22 ) ;
F_38 ( & V_18 -> V_22 ) ;
if ( V_18 -> V_26 )
F_39 ( V_18 -> V_26 ) ;
F_40 ( V_18 ) ;
}
}
static int T_2 F_41 ( struct V_73 * V_74 )
{
struct V_66 * V_67 = F_42 ( & V_74 -> V_24 ) ;
struct V_1 * V_5 ;
struct V_75 * V_76 ;
int V_77 = 0 ;
int V_16 ;
T_1 V_10 ;
T_1 V_78 ;
int V_68 ;
V_5 = F_43 ( & V_74 -> V_24 , sizeof( struct V_1 ) , V_79 ) ;
if ( V_5 == NULL )
return - V_80 ;
V_5 -> V_3 = V_81 ;
V_5 -> V_3 . V_82 = V_67 -> V_70 * V_83 ;
V_5 -> V_3 . V_24 = & V_74 -> V_24 ;
V_5 -> V_3 . V_6 = V_67 -> V_84 ;
V_5 -> V_24 = & V_74 -> V_24 ;
V_76 = F_44 ( V_74 , V_85 , 0 ) ;
if ( ! V_76 ) {
F_20 ( V_5 -> V_24 , L_13 ) ;
return - V_86 ;
}
V_5 -> V_6 = F_45 ( & V_74 -> V_24 , V_76 ) ;
if ( ! V_5 -> V_6 ) {
F_20 ( V_5 -> V_24 , L_14 ) ;
return - V_80 ;
}
V_5 -> V_87 = F_46 ( V_5 -> V_24 , NULL ) ;
if ( F_47 ( V_5 -> V_87 ) ) {
V_77 = F_48 ( V_5 -> V_87 ) ;
F_20 ( V_5 -> V_24 , L_15 ) ;
return V_77 ;
}
V_77 = F_49 ( V_5 -> V_87 ) ;
if ( V_77 ) {
F_20 ( V_5 -> V_24 , L_16 ) ;
return V_77 ;
}
F_50 ( V_5 -> V_24 ,
L_17 ) ;
V_5 -> V_88 = V_89 ;
V_5 -> V_12 = V_90 ;
V_5 -> V_11 = V_91 ;
V_5 -> V_7 = V_92 ;
V_5 -> V_32 = V_93 ;
V_5 -> V_42 = V_94 ;
V_5 -> V_51 = V_95 ;
V_5 -> V_57 = V_96 ;
V_78 = V_97 ;
V_10 = F_8 ( V_5 -> V_6 + V_98 ) ;
F_50 ( V_5 -> V_24 , L_18 \
L_19 ,
( ( V_10 & 0x000001FC ) >> 2 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_13 ( V_99 ,
V_5 -> V_6 + V_98 ) ;
F_35 ( V_5 , V_67 ) ;
F_51 ( & V_5 -> V_100 ) ;
for ( V_16 = 0 ; V_16 < V_67 -> V_70 ; V_16 ++ ) {
struct V_17 * V_18 =
F_52 ( sizeof( struct V_17 ) , V_79 ) ;
if ( ! V_18 ) {
F_20 ( V_5 -> V_24 , L_20 ) ;
V_77 = - V_80 ;
goto V_101;
}
snprintf ( V_18 -> V_50 , 8 , L_21 , V_16 ) ;
V_18 -> V_23 = V_16 ;
V_18 -> V_5 = V_5 ;
V_18 -> V_52 = F_53 ( V_74 ,
V_18 -> V_50 ) ;
F_22 ( V_5 -> V_24 , L_22 , V_18 -> V_52 ,
V_18 -> V_50 ) ;
V_18 -> V_26 = F_54 ( V_74 -> V_24 . V_102 ,
V_83 ,
& V_103 ,
V_18 ) ;
if ( ! V_18 -> V_26 ) {
V_77 = - V_80 ;
goto V_104;
}
F_55 ( V_18 -> V_52 , F_30 ) ;
F_56 ( V_18 -> V_52 , V_18 ) ;
for ( V_68 = 0 ; V_68 < V_83 ; V_68 ++ ) {
int V_105 = F_57 ( V_18 -> V_26 , V_68 ) ;
F_22 ( V_5 -> V_24 , L_23 ,
V_5 -> V_3 . V_6 + ( V_18 -> V_23 << 3 ) + V_68 ,
V_18 -> V_50 , V_105 ) ;
F_58 ( V_105 , & V_106 ,
V_107 ) ;
F_59 ( V_105 , V_108 ) ;
F_60 ( V_105 , V_18 ) ;
}
F_13 ( 0x0 , V_5 -> V_6 + V_16 * V_5 -> V_88 + V_78 ) ;
F_61 ( & V_18 -> V_22 , & V_5 -> V_100 ) ;
}
F_22 ( V_5 -> V_24 , L_24 , V_16 ) ;
V_77 = F_62 ( & V_5 -> V_3 ) ;
if ( V_77 ) {
F_20 ( V_5 -> V_24 , L_25 , V_77 ) ;
goto V_109;
}
for ( V_68 = 0 ; V_68 < F_63 ( V_110 ) ; V_68 ++ ) {
struct V_111 * V_20 = & V_110 [ V_68 ] ;
V_77 = F_64 ( & V_5 -> V_3 , L_26 ,
V_20 -> V_4 , V_20 -> V_112 , 1 ) ;
if ( V_77 )
goto V_113;
}
F_65 ( V_74 , V_5 ) ;
return 0 ;
V_113:
V_77 = F_66 ( & V_5 -> V_3 ) ;
V_109:
V_104:
V_101:
F_36 ( V_5 ) ;
F_67 ( V_5 -> V_87 ) ;
F_20 ( & V_74 -> V_24 , L_27 , V_77 ) ;
return V_77 ;
}
static int T_3 F_68 ( struct V_73 * V_74 )
{
struct V_1 * V_5 = F_69 ( V_74 ) ;
int V_77 ;
F_13 ( 0x00000000U , V_5 -> V_6 + V_98 ) ;
V_77 = F_66 ( & V_5 -> V_3 ) ;
if ( V_77 < 0 ) {
F_20 ( V_5 -> V_24 , L_28 , V_77 ) ;
return V_77 ;
}
F_36 ( V_5 ) ;
F_67 ( V_5 -> V_87 ) ;
F_65 ( V_74 , NULL ) ;
return 0 ;
}
static int T_2 F_70 ( void )
{
return F_71 ( & V_114 , F_41 ) ;
}
static void T_3 F_72 ( void )
{
F_73 ( & V_114 ) ;
}
