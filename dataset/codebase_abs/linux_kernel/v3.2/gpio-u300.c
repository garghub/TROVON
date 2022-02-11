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
static int F_13 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_15 = V_5 -> V_16 + V_4 ;
F_14 ( V_5 -> V_17 , L_1 , V_4 ,
V_15 ) ;
return V_15 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_4 ,
T_2 V_18 , unsigned long * V_19 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_8 ( V_8 ) ;
switch ( V_18 ) {
case V_20 :
case V_21 :
V_9 = F_4 ( F_5 ( V_4 , V_22 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_22 ) ) ;
break;
case V_23 :
V_9 = F_4 ( F_5 ( V_4 , V_22 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_22 ) ) ;
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
F_16 ( V_5 -> V_17 , L_2 ) ;
return - V_29 ;
}
F_10 ( V_8 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_5 , unsigned V_4 )
{
T_1 V_9 ;
V_9 = F_4 ( F_5 ( V_4 , V_30 ) ) ;
if ( F_3 ( & V_5 -> V_3 , V_4 ) ) {
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_30 ) ) ;
F_14 ( V_5 -> V_17 , L_3 ,
V_4 ) ;
} else {
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_30 ) ) ;
F_14 ( V_5 -> V_17 , L_4 ,
V_4 ) ;
}
}
static int F_18 ( struct V_31 * V_32 , unsigned V_33 )
{
struct V_34 * V_35 = F_19 ( V_32 ) ;
struct V_1 * V_5 = V_35 -> V_5 ;
int V_4 = V_32 -> V_36 - V_5 -> V_16 ;
T_1 V_9 ;
if ( ( V_33 & V_37 ) &&
( V_33 & V_38 ) ) {
F_14 ( V_5 -> V_17 ,
L_5 ,
V_4 ) ;
V_35 -> V_39 |= F_6 ( V_4 ) ;
F_17 ( V_5 , V_4 ) ;
} else if ( V_33 & V_37 ) {
F_14 ( V_5 -> V_17 , L_6 ,
V_4 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_30 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_30 ) ) ;
V_35 -> V_39 &= ~ F_6 ( V_4 ) ;
} else if ( V_33 & V_38 ) {
F_14 ( V_5 -> V_17 , L_7 ,
V_4 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_30 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_30 ) ) ;
V_35 -> V_39 &= ~ F_6 ( V_4 ) ;
}
return 0 ;
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = F_19 ( V_32 ) ;
struct V_1 * V_5 = V_35 -> V_5 ;
int V_4 = V_32 -> V_36 - V_5 -> V_16 ;
T_1 V_9 ;
unsigned long V_8 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_40 ) ) ;
F_9 ( V_9 | F_6 ( V_4 ) , F_5 ( V_4 , V_40 ) ) ;
F_10 ( V_8 ) ;
}
static void F_21 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = F_19 ( V_32 ) ;
struct V_1 * V_5 = V_35 -> V_5 ;
int V_4 = V_32 -> V_36 - V_5 -> V_16 ;
T_1 V_9 ;
unsigned long V_8 ;
F_8 ( V_8 ) ;
V_9 = F_4 ( F_5 ( V_4 , V_40 ) ) ;
F_9 ( V_9 & ~ F_6 ( V_4 ) , F_5 ( V_4 , V_40 ) ) ;
F_10 ( V_8 ) ;
}
static void F_22 ( unsigned V_36 , struct V_41 * V_42 )
{
struct V_34 * V_35 = F_23 ( V_36 ) ;
struct V_1 * V_5 = V_35 -> V_5 ;
int V_43 = V_35 -> V_44 << 3 ;
unsigned long V_9 ;
V_42 -> V_31 . V_3 -> V_45 ( & V_42 -> V_31 ) ;
V_9 = F_4 ( F_5 ( V_43 , V_46 ) ) ;
V_9 &= 0xFFU ;
F_9 ( V_9 , F_5 ( V_43 , V_46 ) ) ;
if ( V_9 != 0 ) {
int V_47 ;
F_24 (irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int V_48 = V_5 -> V_16 + ( V_35 -> V_44 << 3 )
+ V_47 ;
int V_4 = V_43 + V_47 ;
F_14 ( V_5 -> V_17 , L_8 ,
V_48 , V_4 ) ;
F_25 ( V_48 ) ;
if ( V_35 -> V_39 & F_6 ( V_4 ) )
F_17 ( V_5 , V_4 ) ;
}
}
V_42 -> V_31 . V_3 -> V_49 ( & V_42 -> V_31 ) ;
}
static void T_3 F_26 ( struct V_1 * V_5 ,
int V_4 ,
const struct V_50 * V_51 )
{
if ( V_51 -> V_52 ) {
F_12 ( & V_5 -> V_3 , V_4 , V_51 -> V_53 ) ;
F_15 ( & V_5 -> V_3 , V_4 ,
V_21 ,
NULL ) ;
F_15 ( & V_5 -> V_3 , V_4 ,
V_24 , NULL ) ;
F_14 ( V_5 -> V_17 , L_9 ,
V_4 , V_51 -> V_53 ) ;
} else {
F_11 ( & V_5 -> V_3 , V_4 ) ;
F_7 ( & V_5 -> V_3 , V_4 , 0 ) ;
F_15 ( & V_5 -> V_3 , V_4 , V_51 -> V_54 , NULL ) ;
F_14 ( V_5 -> V_17 , L_10 ,
V_4 , V_51 -> V_54 ) ;
}
}
static void T_3 F_27 ( struct V_1 * V_5 ,
struct V_55 * V_56 )
{
int V_57 , V_58 ;
for ( V_57 = 0 ; V_57 < V_56 -> V_59 ; V_57 ++ ) {
for ( V_58 = 0 ; V_58 < 8 ; V_58 ++ ) {
const struct V_50 * V_51 ;
int V_4 = ( V_57 * 8 ) + V_58 ;
if ( V_56 -> V_60 == V_61 )
V_51 = & V_62 [ V_57 ] [ V_58 ] ;
else if ( V_56 -> V_60 == V_63 )
V_51 = & V_64 [ V_57 ] [ V_58 ] ;
else
break;
F_26 ( V_5 , V_4 , V_51 ) ;
}
}
}
static inline void F_28 ( struct V_1 * V_5 )
{
struct V_34 * V_35 ;
struct V_65 * V_66 , * V_67 ;
F_29 (p, n, &gpio->port_list) {
V_35 = F_30 ( V_66 , struct V_34 , V_68 ) ;
F_31 ( & V_35 -> V_68 ) ;
F_32 ( V_35 -> V_36 , V_35 ) ;
F_33 ( V_35 ) ;
}
}
static int T_3 F_34 ( struct V_69 * V_70 )
{
struct V_55 * V_56 = F_35 ( & V_70 -> V_17 ) ;
struct V_1 * V_5 ;
int V_71 = 0 ;
int V_72 ;
T_1 V_9 ;
T_1 V_73 ;
int V_57 ;
V_5 = F_36 ( sizeof( struct V_1 ) , V_74 ) ;
if ( V_5 == NULL ) {
F_16 ( & V_70 -> V_17 , L_11 ) ;
return - V_75 ;
}
V_5 -> V_3 = V_76 ;
V_5 -> V_3 . V_77 = V_56 -> V_59 * V_78 ;
V_5 -> V_16 = V_56 -> V_79 ;
V_5 -> V_3 . V_17 = & V_70 -> V_17 ;
V_5 -> V_3 . V_80 = V_56 -> V_81 ;
V_5 -> V_17 = & V_70 -> V_17 ;
V_5 -> V_82 = F_37 ( V_5 -> V_17 , NULL ) ;
if ( F_38 ( V_5 -> V_82 ) ) {
V_71 = F_39 ( V_5 -> V_82 ) ;
F_16 ( V_5 -> V_17 , L_12 ) ;
goto V_83;
}
V_71 = F_40 ( V_5 -> V_82 ) ;
if ( V_71 ) {
F_16 ( V_5 -> V_17 , L_13 ) ;
goto V_84;
}
V_5 -> V_85 = F_41 ( V_70 , V_86 , 0 ) ;
if ( ! V_5 -> V_85 ) {
F_16 ( V_5 -> V_17 , L_14 ) ;
V_71 = - V_87 ;
goto V_88;
}
if ( ! F_42 ( V_5 -> V_85 -> V_89 ,
F_43 ( V_5 -> V_85 ) ,
L_15 ) ) {
V_71 = - V_87 ;
goto V_90;
}
V_5 -> V_80 = F_44 ( V_5 -> V_85 -> V_89 , F_43 ( V_5 -> V_85 ) ) ;
if ( ! V_5 -> V_80 ) {
V_71 = - V_75 ;
goto V_91;
}
if ( V_56 -> V_60 == V_92 ) {
F_45 ( V_5 -> V_17 ,
L_16 ) ;
V_5 -> V_93 = V_94 ;
V_5 -> V_11 = V_95 ;
V_5 -> V_10 = V_96 ;
V_5 -> V_6 = V_97 ;
V_5 -> V_22 = V_98 ;
V_5 -> V_30 = V_99 ;
V_5 -> V_40 = V_100 ;
V_5 -> V_46 = V_101 ;
V_73 = V_102 ;
F_9 ( V_103 ,
V_5 -> V_80 + V_104 ) ;
} else if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_63 ) {
F_45 ( V_5 -> V_17 ,
L_17 ) ;
V_5 -> V_93 = V_105 ;
V_5 -> V_11 = V_106 ;
V_5 -> V_10 = V_107 ;
V_5 -> V_6 = V_108 ;
V_5 -> V_22 = V_109 ;
V_5 -> V_30 = V_110 ;
V_5 -> V_40 = V_111 ;
V_5 -> V_46 = V_112 ;
V_73 = V_113 ;
V_9 = F_4 ( V_5 -> V_80 + V_114 ) ;
F_45 ( V_5 -> V_17 , L_18 \
L_19 ,
( ( V_9 & 0x000001FC ) >> 2 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) ,
( ( V_9 & 0x0000FE00 ) >> 9 ) * 8 ) ;
F_9 ( V_115 ,
V_5 -> V_80 + V_114 ) ;
F_27 ( V_5 , V_56 ) ;
} else {
F_16 ( V_5 -> V_17 , L_20 ) ;
V_71 = - V_87 ;
goto V_116;
}
F_46 ( & V_5 -> V_117 ) ;
for ( V_72 = 0 ; V_72 < V_56 -> V_59 ; V_72 ++ ) {
struct V_34 * V_35 =
F_47 ( sizeof( struct V_34 ) , V_74 ) ;
if ( ! V_35 ) {
F_16 ( V_5 -> V_17 , L_21 ) ;
V_71 = - V_75 ;
goto V_118;
}
snprintf ( V_35 -> V_119 , 8 , L_22 , V_72 ) ;
V_35 -> V_44 = V_72 ;
V_35 -> V_5 = V_5 ;
V_35 -> V_36 = F_48 ( V_70 ,
V_35 -> V_119 ) ;
F_14 ( V_5 -> V_17 , L_23 , V_35 -> V_36 ,
V_35 -> V_119 ) ;
F_49 ( V_35 -> V_36 , F_22 ) ;
F_50 ( V_35 -> V_36 , V_35 ) ;
for ( V_57 = 0 ; V_57 < V_78 ; V_57 ++ ) {
int V_120 = V_5 -> V_16 + ( V_72 << 3 ) + V_57 ;
F_14 ( V_5 -> V_17 , L_24 ,
V_120 , V_35 -> V_119 ) ;
F_51 ( V_120 , & V_121 ,
V_122 ) ;
F_52 ( V_120 , V_123 ) ;
F_53 ( V_120 , V_35 ) ;
}
F_9 ( 0x0 , V_5 -> V_80 + V_72 * V_5 -> V_93 + V_73 ) ;
F_54 ( & V_35 -> V_68 , & V_5 -> V_117 ) ;
}
F_14 ( V_5 -> V_17 , L_25 , V_72 ) ;
V_71 = F_55 ( & V_5 -> V_3 ) ;
if ( V_71 ) {
F_16 ( V_5 -> V_17 , L_26 , V_71 ) ;
goto V_124;
}
F_56 ( V_70 , V_5 ) ;
return 0 ;
V_124:
V_118:
F_28 ( V_5 ) ;
V_116:
F_57 ( V_5 -> V_80 ) ;
V_91:
F_58 ( V_5 -> V_85 -> V_89 , F_43 ( V_5 -> V_85 ) ) ;
V_90:
V_88:
F_59 ( V_5 -> V_82 ) ;
V_84:
F_60 ( V_5 -> V_82 ) ;
V_83:
F_33 ( V_5 ) ;
F_45 ( & V_70 -> V_17 , L_27 , V_71 ) ;
return V_71 ;
}
static int T_4 F_61 ( struct V_69 * V_70 )
{
struct V_55 * V_56 = F_35 ( & V_70 -> V_17 ) ;
struct V_1 * V_5 = F_62 ( V_70 ) ;
int V_71 ;
if ( V_56 -> V_60 == V_92 )
F_9 ( 0x00000000U , V_5 -> V_80 + V_104 ) ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_63 )
F_9 ( 0x00000000U , V_5 -> V_80 + V_114 ) ;
V_71 = F_63 ( & V_5 -> V_3 ) ;
if ( V_71 < 0 ) {
F_16 ( V_5 -> V_17 , L_28 , V_71 ) ;
return V_71 ;
}
F_28 ( V_5 ) ;
F_57 ( V_5 -> V_80 ) ;
F_58 ( V_5 -> V_85 -> V_89 ,
F_43 ( V_5 -> V_85 ) ) ;
F_59 ( V_5 -> V_82 ) ;
F_60 ( V_5 -> V_82 ) ;
F_56 ( V_70 , NULL ) ;
F_33 ( V_5 ) ;
return 0 ;
}
static int T_3 F_64 ( void )
{
return F_65 ( & V_125 , F_34 ) ;
}
static void T_4 F_66 ( void )
{
F_67 ( & V_125 ) ;
}
