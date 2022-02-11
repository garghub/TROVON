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
int V_16 = V_5 -> V_17 + V_4 ;
F_18 ( V_5 -> V_18 , L_1 , V_4 ,
V_16 ) ;
return V_16 ;
}
int F_19 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_19 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_20 V_21 = (enum V_20 ) * V_19 ;
bool V_22 ;
T_1 V_23 ;
V_22 = ! ! ( F_8 ( F_9 ( V_4 , V_24 ) ) & F_10 ( V_4 ) ) ;
V_23 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_23 &= ( V_13 << ( ( V_4 & 0x07 ) << 1 ) ) ;
V_23 >>= ( ( V_4 & 0x07 ) << 1 ) ;
switch( V_21 ) {
case V_25 :
* V_19 = 0 ;
if ( V_22 )
return 0 ;
else
return - V_26 ;
break;
case V_27 :
* V_19 = 0 ;
if ( ! V_22 )
return 0 ;
else
return - V_26 ;
break;
case V_28 :
* V_19 = 0 ;
if ( V_23 == V_15 )
return 0 ;
else
return - V_26 ;
break;
case V_29 :
* V_19 = 0 ;
if ( V_23 == V_30 )
return 0 ;
else
return - V_26 ;
break;
case V_31 :
* V_19 = 0 ;
if ( V_23 == V_32 )
return 0 ;
else
return - V_26 ;
break;
default:
break;
}
return - V_33 ;
}
int F_20 ( struct V_2 * V_3 , unsigned V_4 ,
enum V_20 V_21 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
switch ( V_21 ) {
case V_34 :
case V_25 :
V_10 = F_8 ( F_9 ( V_4 , V_24 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_24 ) ) ;
break;
case V_27 :
V_10 = F_8 ( F_9 ( V_4 , V_24 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_24 ) ) ;
break;
case V_28 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_15
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_29 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_30
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
case V_31 :
V_10 = F_8 ( F_9 ( V_4 , V_12 ) ) ;
V_10 &= ~ ( V_13
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
V_10 |= ( V_32
<< ( ( V_4 & 0x07 ) << 1 ) ) ;
F_13 ( V_10 , F_9 ( V_4 , V_12 ) ) ;
break;
default:
F_14 ( V_9 ) ;
F_21 ( V_5 -> V_18 , L_2 ) ;
return - V_26 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_10 ;
V_10 = F_8 ( F_9 ( V_4 , V_35 ) ) ;
if ( F_7 ( & V_5 -> V_3 , V_4 ) ) {
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_35 ) ) ;
F_18 ( V_5 -> V_18 , L_3 ,
V_4 ) ;
} else {
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_35 ) ) ;
F_18 ( V_5 -> V_18 , L_4 ,
V_4 ) ;
}
}
static int F_23 ( struct V_36 * V_37 , unsigned V_38 )
{
struct V_39 * V_40 = F_24 ( V_37 ) ;
struct V_1 * V_5 = V_40 -> V_5 ;
int V_4 = V_37 -> V_41 - V_5 -> V_17 ;
T_1 V_10 ;
if ( ( V_38 & V_42 ) &&
( V_38 & V_43 ) ) {
F_18 ( V_5 -> V_18 ,
L_5 ,
V_4 ) ;
V_40 -> V_44 |= F_10 ( V_4 ) ;
F_22 ( V_5 , V_4 ) ;
} else if ( V_38 & V_42 ) {
F_18 ( V_5 -> V_18 , L_6 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_35 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_35 ) ) ;
V_40 -> V_44 &= ~ F_10 ( V_4 ) ;
} else if ( V_38 & V_43 ) {
F_18 ( V_5 -> V_18 , L_7 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_35 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_35 ) ) ;
V_40 -> V_44 &= ~ F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_25 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = F_24 ( V_37 ) ;
struct V_1 * V_5 = V_40 -> V_5 ;
int V_4 = V_37 -> V_41 - V_5 -> V_17 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_45 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_45 ) ) ;
F_14 ( V_9 ) ;
}
static void F_26 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = F_24 ( V_37 ) ;
struct V_1 * V_5 = V_40 -> V_5 ;
int V_4 = V_37 -> V_41 - V_5 -> V_17 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_45 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_45 ) ) ;
F_14 ( V_9 ) ;
}
static void F_27 ( unsigned V_41 , struct V_46 * V_47 )
{
struct V_39 * V_40 = F_28 ( V_41 ) ;
struct V_1 * V_5 = V_40 -> V_5 ;
int V_48 = V_40 -> V_49 << 3 ;
unsigned long V_10 ;
V_47 -> V_36 . V_3 -> V_50 ( & V_47 -> V_36 ) ;
V_10 = F_8 ( F_9 ( V_48 , V_51 ) ) ;
V_10 &= 0xFFU ;
F_13 ( V_10 , F_9 ( V_48 , V_51 ) ) ;
if ( V_10 != 0 ) {
int V_52 ;
F_29 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_53 = V_5 -> V_17 + ( V_40 -> V_49 << 3 )
+ V_52 ;
int V_4 = V_48 + V_52 ;
F_18 ( V_5 -> V_18 , L_8 ,
V_53 , V_4 ) ;
F_30 ( V_53 ) ;
if ( V_40 -> V_44 & F_10 ( V_4 ) )
F_22 ( V_5 , V_4 ) ;
}
}
V_47 -> V_36 . V_3 -> V_54 ( & V_47 -> V_36 ) ;
}
static void T_2 F_31 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_55 * V_56 )
{
if ( V_56 -> V_57 ) {
F_16 ( & V_5 -> V_3 , V_4 , V_56 -> V_58 ) ;
F_20 ( & V_5 -> V_3 , V_4 ,
V_25 ) ;
F_20 ( & V_5 -> V_3 , V_4 ,
V_28 ) ;
F_18 ( V_5 -> V_18 , L_9 ,
V_4 , V_56 -> V_58 ) ;
} else {
F_15 ( & V_5 -> V_3 , V_4 ) ;
F_11 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_20 ( & V_5 -> V_3 , V_4 , V_56 -> V_59 ) ;
F_18 ( V_5 -> V_18 , L_10 ,
V_4 , V_56 -> V_59 ) ;
}
}
static void T_2 F_32 ( struct V_1 * V_5 ,
struct V_60 * V_61 )
{
int V_62 , V_63 ;
for ( V_62 = 0 ; V_62 < V_61 -> V_64 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ ) {
const struct V_55 * V_56 ;
int V_4 = ( V_62 * 8 ) + V_63 ;
V_56 = & V_65 [ V_62 ] [ V_63 ] ;
F_31 ( V_5 , V_4 , V_56 ) ;
}
}
}
static inline void F_33 ( struct V_1 * V_5 )
{
struct V_39 * V_40 ;
struct V_66 * V_67 , * V_68 ;
F_34 (p, n, &gpio->port_list) {
V_40 = F_35 ( V_67 , struct V_39 , V_69 ) ;
F_36 ( & V_40 -> V_69 ) ;
F_37 ( V_40 ) ;
}
}
static int T_2 F_38 ( struct V_70 * V_71 )
{
struct V_60 * V_61 = F_39 ( & V_71 -> V_18 ) ;
struct V_1 * V_5 ;
int V_72 = 0 ;
int V_73 ;
T_1 V_10 ;
T_1 V_74 ;
int V_62 ;
V_5 = F_40 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_5 == NULL ) {
F_21 ( & V_71 -> V_18 , L_11 ) ;
return - V_76 ;
}
V_5 -> V_3 = V_77 ;
V_5 -> V_3 . V_78 = V_61 -> V_64 * V_79 ;
V_5 -> V_17 = V_61 -> V_80 ;
V_5 -> V_3 . V_18 = & V_71 -> V_18 ;
V_5 -> V_3 . V_6 = V_61 -> V_81 ;
V_5 -> V_18 = & V_71 -> V_18 ;
V_5 -> V_82 = F_41 ( V_5 -> V_18 , NULL ) ;
if ( F_42 ( V_5 -> V_82 ) ) {
V_72 = F_43 ( V_5 -> V_82 ) ;
F_21 ( V_5 -> V_18 , L_12 ) ;
goto V_83;
}
V_72 = F_44 ( V_5 -> V_82 ) ;
if ( V_72 ) {
F_21 ( V_5 -> V_18 , L_13 ) ;
goto V_84;
}
V_5 -> V_85 = F_45 ( V_71 , V_86 , 0 ) ;
if ( ! V_5 -> V_85 ) {
F_21 ( V_5 -> V_18 , L_14 ) ;
V_72 = - V_87 ;
goto V_88;
}
if ( ! F_46 ( V_5 -> V_85 -> V_89 ,
F_47 ( V_5 -> V_85 ) ,
L_15 ) ) {
V_72 = - V_87 ;
goto V_90;
}
V_5 -> V_6 = F_48 ( V_5 -> V_85 -> V_89 , F_47 ( V_5 -> V_85 ) ) ;
if ( ! V_5 -> V_6 ) {
V_72 = - V_76 ;
goto V_91;
}
F_49 ( V_5 -> V_18 ,
L_16 ) ;
V_5 -> V_92 = V_93 ;
V_5 -> V_12 = V_94 ;
V_5 -> V_11 = V_95 ;
V_5 -> V_7 = V_96 ;
V_5 -> V_24 = V_97 ;
V_5 -> V_35 = V_98 ;
V_5 -> V_45 = V_99 ;
V_5 -> V_51 = V_100 ;
V_74 = V_101 ;
V_10 = F_8 ( V_5 -> V_6 + V_102 ) ;
F_49 ( V_5 -> V_18 , L_17 \
L_18 ,
( ( V_10 & 0x000001FC ) >> 2 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_13 ( V_103 ,
V_5 -> V_6 + V_102 ) ;
F_32 ( V_5 , V_61 ) ;
F_50 ( & V_5 -> V_104 ) ;
for ( V_73 = 0 ; V_73 < V_61 -> V_64 ; V_73 ++ ) {
struct V_39 * V_40 =
F_51 ( sizeof( struct V_39 ) , V_75 ) ;
if ( ! V_40 ) {
F_21 ( V_5 -> V_18 , L_19 ) ;
V_72 = - V_76 ;
goto V_105;
}
snprintf ( V_40 -> V_106 , 8 , L_20 , V_73 ) ;
V_40 -> V_49 = V_73 ;
V_40 -> V_5 = V_5 ;
V_40 -> V_41 = F_52 ( V_71 ,
V_40 -> V_106 ) ;
F_18 ( V_5 -> V_18 , L_21 , V_40 -> V_41 ,
V_40 -> V_106 ) ;
F_53 ( V_40 -> V_41 , F_27 ) ;
F_54 ( V_40 -> V_41 , V_40 ) ;
for ( V_62 = 0 ; V_62 < V_79 ; V_62 ++ ) {
int V_107 = V_5 -> V_17 + ( V_73 << 3 ) + V_62 ;
F_18 ( V_5 -> V_18 , L_22 ,
V_107 , V_40 -> V_106 ) ;
F_55 ( V_107 , & V_108 ,
V_109 ) ;
F_56 ( V_107 , V_110 ) ;
F_57 ( V_107 , V_40 ) ;
}
F_13 ( 0x0 , V_5 -> V_6 + V_73 * V_5 -> V_92 + V_74 ) ;
F_58 ( & V_40 -> V_69 , & V_5 -> V_104 ) ;
}
F_18 ( V_5 -> V_18 , L_23 , V_73 ) ;
V_72 = F_59 ( & V_5 -> V_3 ) ;
if ( V_72 ) {
F_21 ( V_5 -> V_18 , L_24 , V_72 ) ;
goto V_111;
}
V_61 -> V_112 -> V_18 . V_113 = & V_5 -> V_3 ;
V_72 = F_60 ( V_61 -> V_112 ) ;
if ( V_72 )
goto V_114;
F_61 ( V_71 , V_5 ) ;
return 0 ;
V_114:
V_72 = F_62 ( & V_5 -> V_3 ) ;
V_111:
V_105:
F_33 ( V_5 ) ;
F_63 ( V_5 -> V_6 ) ;
V_91:
F_64 ( V_5 -> V_85 -> V_89 , F_47 ( V_5 -> V_85 ) ) ;
V_90:
V_88:
F_65 ( V_5 -> V_82 ) ;
V_84:
F_66 ( V_5 -> V_82 ) ;
V_83:
F_37 ( V_5 ) ;
F_49 ( & V_71 -> V_18 , L_25 , V_72 ) ;
return V_72 ;
}
static int T_3 F_67 ( struct V_70 * V_71 )
{
struct V_1 * V_5 = F_68 ( V_71 ) ;
int V_72 ;
F_13 ( 0x00000000U , V_5 -> V_6 + V_102 ) ;
V_72 = F_62 ( & V_5 -> V_3 ) ;
if ( V_72 < 0 ) {
F_21 ( V_5 -> V_18 , L_26 , V_72 ) ;
return V_72 ;
}
F_33 ( V_5 ) ;
F_63 ( V_5 -> V_6 ) ;
F_64 ( V_5 -> V_85 -> V_89 ,
F_47 ( V_5 -> V_85 ) ) ;
F_65 ( V_5 -> V_82 ) ;
F_66 ( V_5 -> V_82 ) ;
F_61 ( V_71 , NULL ) ;
F_37 ( V_5 ) ;
return 0 ;
}
static int T_2 F_69 ( void )
{
return F_70 ( & V_115 , F_38 ) ;
}
static void T_3 F_71 ( void )
{
F_72 ( & V_115 ) ;
}
