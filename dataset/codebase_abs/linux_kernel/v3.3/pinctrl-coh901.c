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
static int F_19 ( struct V_2 * V_3 , unsigned V_4 ,
T_2 V_19 , unsigned long * V_20 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_12 ( V_9 ) ;
switch ( V_19 ) {
case V_21 :
case V_22 :
V_10 = F_8 ( F_9 ( V_4 , V_23 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_23 ) ) ;
break;
case V_24 :
V_10 = F_8 ( F_9 ( V_4 , V_23 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_23 ) ) ;
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
F_20 ( V_5 -> V_18 , L_2 ) ;
return - V_30 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_10 ;
V_10 = F_8 ( F_9 ( V_4 , V_31 ) ) ;
if ( F_7 ( & V_5 -> V_3 , V_4 ) ) {
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_31 ) ) ;
F_18 ( V_5 -> V_18 , L_3 ,
V_4 ) ;
} else {
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_31 ) ) ;
F_18 ( V_5 -> V_18 , L_4 ,
V_4 ) ;
}
}
static int F_22 ( struct V_32 * V_33 , unsigned V_34 )
{
struct V_35 * V_36 = F_23 ( V_33 ) ;
struct V_1 * V_5 = V_36 -> V_5 ;
int V_4 = V_33 -> V_37 - V_5 -> V_17 ;
T_1 V_10 ;
if ( ( V_34 & V_38 ) &&
( V_34 & V_39 ) ) {
F_18 ( V_5 -> V_18 ,
L_5 ,
V_4 ) ;
V_36 -> V_40 |= F_10 ( V_4 ) ;
F_21 ( V_5 , V_4 ) ;
} else if ( V_34 & V_38 ) {
F_18 ( V_5 -> V_18 , L_6 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_31 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_31 ) ) ;
V_36 -> V_40 &= ~ F_10 ( V_4 ) ;
} else if ( V_34 & V_39 ) {
F_18 ( V_5 -> V_18 , L_7 ,
V_4 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_31 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_31 ) ) ;
V_36 -> V_40 &= ~ F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_24 ( struct V_32 * V_33 )
{
struct V_35 * V_36 = F_23 ( V_33 ) ;
struct V_1 * V_5 = V_36 -> V_5 ;
int V_4 = V_33 -> V_37 - V_5 -> V_17 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_41 ) ) ;
F_13 ( V_10 | F_10 ( V_4 ) , F_9 ( V_4 , V_41 ) ) ;
F_14 ( V_9 ) ;
}
static void F_25 ( struct V_32 * V_33 )
{
struct V_35 * V_36 = F_23 ( V_33 ) ;
struct V_1 * V_5 = V_36 -> V_5 ;
int V_4 = V_33 -> V_37 - V_5 -> V_17 ;
T_1 V_10 ;
unsigned long V_9 ;
F_12 ( V_9 ) ;
V_10 = F_8 ( F_9 ( V_4 , V_41 ) ) ;
F_13 ( V_10 & ~ F_10 ( V_4 ) , F_9 ( V_4 , V_41 ) ) ;
F_14 ( V_9 ) ;
}
static void F_26 ( unsigned V_37 , struct V_42 * V_43 )
{
struct V_35 * V_36 = F_27 ( V_37 ) ;
struct V_1 * V_5 = V_36 -> V_5 ;
int V_44 = V_36 -> V_45 << 3 ;
unsigned long V_10 ;
V_43 -> V_32 . V_3 -> V_46 ( & V_43 -> V_32 ) ;
V_10 = F_8 ( F_9 ( V_44 , V_47 ) ) ;
V_10 &= 0xFFU ;
F_13 ( V_10 , F_9 ( V_44 , V_47 ) ) ;
if ( V_10 != 0 ) {
int V_48 ;
F_28 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_49 = V_5 -> V_17 + ( V_36 -> V_45 << 3 )
+ V_48 ;
int V_4 = V_44 + V_48 ;
F_18 ( V_5 -> V_18 , L_8 ,
V_49 , V_4 ) ;
F_29 ( V_49 ) ;
if ( V_36 -> V_40 & F_10 ( V_4 ) )
F_21 ( V_5 , V_4 ) ;
}
}
V_43 -> V_32 . V_3 -> V_50 ( & V_43 -> V_32 ) ;
}
static void T_3 F_30 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_51 * V_52 )
{
if ( V_52 -> V_53 ) {
F_16 ( & V_5 -> V_3 , V_4 , V_52 -> V_54 ) ;
F_19 ( & V_5 -> V_3 , V_4 ,
V_22 ,
NULL ) ;
F_19 ( & V_5 -> V_3 , V_4 ,
V_25 , NULL ) ;
F_18 ( V_5 -> V_18 , L_9 ,
V_4 , V_52 -> V_54 ) ;
} else {
F_15 ( & V_5 -> V_3 , V_4 ) ;
F_11 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_19 ( & V_5 -> V_3 , V_4 , V_52 -> V_55 , NULL ) ;
F_18 ( V_5 -> V_18 , L_10 ,
V_4 , V_52 -> V_55 ) ;
}
}
static void T_3 F_31 ( struct V_1 * V_5 ,
struct V_56 * V_57 )
{
int V_58 , V_59 ;
for ( V_58 = 0 ; V_58 < V_57 -> V_60 ; V_58 ++ ) {
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
const struct V_51 * V_52 ;
int V_4 = ( V_58 * 8 ) + V_59 ;
if ( V_57 -> V_61 == V_62 )
V_52 = & V_63 [ V_58 ] [ V_59 ] ;
else if ( V_57 -> V_61 == V_64 )
V_52 = & V_65 [ V_58 ] [ V_59 ] ;
else
break;
F_30 ( V_5 , V_4 , V_52 ) ;
}
}
}
static inline void F_32 ( struct V_1 * V_5 )
{
struct V_35 * V_36 ;
struct V_66 * V_67 , * V_68 ;
F_33 (p, n, &gpio->port_list) {
V_36 = F_34 ( V_67 , struct V_35 , V_69 ) ;
F_35 ( & V_36 -> V_69 ) ;
F_36 ( V_36 -> V_37 , V_36 ) ;
F_37 ( V_36 ) ;
}
}
static int T_3 F_38 ( struct V_70 * V_71 )
{
struct V_56 * V_57 = F_39 ( & V_71 -> V_18 ) ;
struct V_1 * V_5 ;
int V_72 = 0 ;
int V_73 ;
T_1 V_10 ;
T_1 V_74 ;
int V_58 ;
V_5 = F_40 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_5 == NULL ) {
F_20 ( & V_71 -> V_18 , L_11 ) ;
return - V_76 ;
}
V_5 -> V_3 = V_77 ;
V_5 -> V_3 . V_78 = V_57 -> V_60 * V_79 ;
V_5 -> V_17 = V_57 -> V_80 ;
V_5 -> V_3 . V_18 = & V_71 -> V_18 ;
V_5 -> V_3 . V_6 = V_57 -> V_81 ;
V_5 -> V_18 = & V_71 -> V_18 ;
V_5 -> V_82 = F_41 ( V_5 -> V_18 , NULL ) ;
if ( F_42 ( V_5 -> V_82 ) ) {
V_72 = F_43 ( V_5 -> V_82 ) ;
F_20 ( V_5 -> V_18 , L_12 ) ;
goto V_83;
}
V_72 = F_44 ( V_5 -> V_82 ) ;
if ( V_72 ) {
F_20 ( V_5 -> V_18 , L_13 ) ;
goto V_84;
}
V_5 -> V_85 = F_45 ( V_71 , V_86 , 0 ) ;
if ( ! V_5 -> V_85 ) {
F_20 ( V_5 -> V_18 , L_14 ) ;
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
if ( V_57 -> V_61 == V_92 ) {
F_49 ( V_5 -> V_18 ,
L_16 ) ;
V_5 -> V_93 = V_94 ;
V_5 -> V_12 = V_95 ;
V_5 -> V_11 = V_96 ;
V_5 -> V_7 = V_97 ;
V_5 -> V_23 = V_98 ;
V_5 -> V_31 = V_99 ;
V_5 -> V_41 = V_100 ;
V_5 -> V_47 = V_101 ;
V_74 = V_102 ;
F_13 ( V_103 ,
V_5 -> V_6 + V_104 ) ;
} else if ( V_57 -> V_61 == V_62 ||
V_57 -> V_61 == V_64 ) {
F_49 ( V_5 -> V_18 ,
L_17 ) ;
V_5 -> V_93 = V_105 ;
V_5 -> V_12 = V_106 ;
V_5 -> V_11 = V_107 ;
V_5 -> V_7 = V_108 ;
V_5 -> V_23 = V_109 ;
V_5 -> V_31 = V_110 ;
V_5 -> V_41 = V_111 ;
V_5 -> V_47 = V_112 ;
V_74 = V_113 ;
V_10 = F_8 ( V_5 -> V_6 + V_114 ) ;
F_49 ( V_5 -> V_18 , L_18 \
L_19 ,
( ( V_10 & 0x000001FC ) >> 2 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) ,
( ( V_10 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_13 ( V_115 ,
V_5 -> V_6 + V_114 ) ;
F_31 ( V_5 , V_57 ) ;
} else {
F_20 ( V_5 -> V_18 , L_20 ) ;
V_72 = - V_87 ;
goto V_116;
}
F_50 ( & V_5 -> V_117 ) ;
for ( V_73 = 0 ; V_73 < V_57 -> V_60 ; V_73 ++ ) {
struct V_35 * V_36 =
F_51 ( sizeof( struct V_35 ) , V_75 ) ;
if ( ! V_36 ) {
F_20 ( V_5 -> V_18 , L_21 ) ;
V_72 = - V_76 ;
goto V_118;
}
snprintf ( V_36 -> V_119 , 8 , L_22 , V_73 ) ;
V_36 -> V_45 = V_73 ;
V_36 -> V_5 = V_5 ;
V_36 -> V_37 = F_52 ( V_71 ,
V_36 -> V_119 ) ;
F_18 ( V_5 -> V_18 , L_23 , V_36 -> V_37 ,
V_36 -> V_119 ) ;
F_53 ( V_36 -> V_37 , F_26 ) ;
F_54 ( V_36 -> V_37 , V_36 ) ;
for ( V_58 = 0 ; V_58 < V_79 ; V_58 ++ ) {
int V_120 = V_5 -> V_17 + ( V_73 << 3 ) + V_58 ;
F_18 ( V_5 -> V_18 , L_24 ,
V_120 , V_36 -> V_119 ) ;
F_55 ( V_120 , & V_121 ,
V_122 ) ;
F_56 ( V_120 , V_123 ) ;
F_57 ( V_120 , V_36 ) ;
}
F_13 ( 0x0 , V_5 -> V_6 + V_73 * V_5 -> V_93 + V_74 ) ;
F_58 ( & V_36 -> V_69 , & V_5 -> V_117 ) ;
}
F_18 ( V_5 -> V_18 , L_25 , V_73 ) ;
V_72 = F_59 ( & V_5 -> V_3 ) ;
if ( V_72 ) {
F_20 ( V_5 -> V_18 , L_26 , V_72 ) ;
goto V_124;
}
F_60 ( V_71 , V_5 ) ;
return 0 ;
V_124:
V_118:
F_32 ( V_5 ) ;
V_116:
F_61 ( V_5 -> V_6 ) ;
V_91:
F_62 ( V_5 -> V_85 -> V_89 , F_47 ( V_5 -> V_85 ) ) ;
V_90:
V_88:
F_63 ( V_5 -> V_82 ) ;
V_84:
F_64 ( V_5 -> V_82 ) ;
V_83:
F_37 ( V_5 ) ;
F_49 ( & V_71 -> V_18 , L_27 , V_72 ) ;
return V_72 ;
}
static int T_4 F_65 ( struct V_70 * V_71 )
{
struct V_56 * V_57 = F_39 ( & V_71 -> V_18 ) ;
struct V_1 * V_5 = F_66 ( V_71 ) ;
int V_72 ;
if ( V_57 -> V_61 == V_92 )
F_13 ( 0x00000000U , V_5 -> V_6 + V_104 ) ;
if ( V_57 -> V_61 == V_62 ||
V_57 -> V_61 == V_64 )
F_13 ( 0x00000000U , V_5 -> V_6 + V_114 ) ;
V_72 = F_67 ( & V_5 -> V_3 ) ;
if ( V_72 < 0 ) {
F_20 ( V_5 -> V_18 , L_28 , V_72 ) ;
return V_72 ;
}
F_32 ( V_5 ) ;
F_61 ( V_5 -> V_6 ) ;
F_62 ( V_5 -> V_85 -> V_89 ,
F_47 ( V_5 -> V_85 ) ) ;
F_63 ( V_5 -> V_82 ) ;
F_64 ( V_5 -> V_82 ) ;
F_60 ( V_71 , NULL ) ;
F_37 ( V_5 ) ;
return 0 ;
}
static int T_3 F_68 ( void )
{
return F_69 ( & V_125 , F_38 ) ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_125 ) ;
}
