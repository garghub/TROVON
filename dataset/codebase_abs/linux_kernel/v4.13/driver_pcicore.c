static inline
T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline
void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static inline
T_2 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_4 , V_3 ) ;
}
static inline
void F_7 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_5 )
{
F_8 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_4 ,
unsigned int V_7 , unsigned int V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 ;
if ( V_2 -> V_11 && ( V_4 > 1 ) )
goto V_12;
if ( V_6 == 0 ) {
if ( F_10 ( V_4 >= V_13 ) )
goto V_12;
V_10 = V_14 ;
V_10 |= ( ( 1 << ( V_4 + 16 ) ) & V_15 ) ;
F_3 ( V_2 , V_16 , V_10 ) ;
V_9 = V_17 ;
V_9 |= ( ( 1 << ( V_4 + 16 ) ) & ~ V_15 ) ;
V_9 |= ( V_7 << 8 ) ;
V_9 |= ( V_8 & ~ 3 ) ;
} else {
F_3 ( V_2 , V_16 ,
V_18 ) ;
V_9 = V_17 ;
V_9 |= ( V_6 << 16 ) ;
V_9 |= ( V_4 << 11 ) ;
V_9 |= ( V_7 << 8 ) ;
V_9 |= ( V_8 & ~ 3 ) ;
}
V_12:
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_4 ,
unsigned int V_7 , unsigned int V_8 ,
void * V_19 , int V_20 )
{
int V_21 = - V_22 ;
T_1 V_9 , V_23 ;
void T_3 * V_24 ;
F_12 ( ! V_2 -> V_25 ) ;
if ( F_10 ( V_20 != 1 && V_20 != 2 && V_20 != 4 ) )
goto V_12;
V_9 = F_9 ( V_2 , V_6 , V_4 , V_7 , V_8 ) ;
if ( F_10 ( ! V_9 ) )
goto V_12;
V_21 = - V_26 ;
V_24 = F_13 ( V_9 , V_20 ) ;
if ( ! V_24 )
goto V_12;
if ( F_14 ( V_23 , V_24 ) ) {
V_23 = 0xffffffff ;
goto V_27;
}
V_23 = F_15 ( V_24 ) ;
V_23 >>= ( 8 * ( V_8 & 3 ) ) ;
switch ( V_20 ) {
case 1 :
* ( ( V_28 * ) V_19 ) = ( V_28 ) V_23 ;
break;
case 2 :
* ( ( T_2 * ) V_19 ) = ( T_2 ) V_23 ;
break;
case 4 :
* ( ( T_1 * ) V_19 ) = ( T_1 ) V_23 ;
break;
}
V_21 = 0 ;
V_27:
F_16 ( V_24 ) ;
V_12:
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_4 ,
unsigned int V_7 , unsigned int V_8 ,
const void * V_19 , int V_20 )
{
int V_21 = - V_22 ;
T_1 V_9 , V_23 = 0 ;
void T_3 * V_24 ;
F_12 ( ! V_2 -> V_25 ) ;
if ( F_10 ( V_20 != 1 && V_20 != 2 && V_20 != 4 ) )
goto V_12;
V_9 = F_9 ( V_2 , V_6 , V_4 , V_7 , V_8 ) ;
if ( F_10 ( ! V_9 ) )
goto V_12;
V_21 = - V_26 ;
V_24 = F_13 ( V_9 , V_20 ) ;
if ( ! V_24 )
goto V_12;
if ( F_14 ( V_23 , V_24 ) ) {
V_23 = 0xffffffff ;
goto V_27;
}
switch ( V_20 ) {
case 1 :
V_23 = F_15 ( V_24 ) ;
V_23 &= ~ ( 0xFF << ( 8 * ( V_8 & 3 ) ) ) ;
V_23 |= * ( ( const V_28 * ) V_19 ) << ( 8 * ( V_8 & 3 ) ) ;
break;
case 2 :
V_23 = F_15 ( V_24 ) ;
V_23 &= ~ ( 0xFFFF << ( 8 * ( V_8 & 3 ) ) ) ;
V_23 |= * ( ( const T_2 * ) V_19 ) << ( 8 * ( V_8 & 3 ) ) ;
break;
case 4 :
V_23 = * ( ( const T_1 * ) V_19 ) ;
break;
}
F_18 ( V_23 , V_24 ) ;
V_21 = 0 ;
V_27:
F_16 ( V_24 ) ;
V_12:
return V_21 ;
}
static int F_19 ( struct V_29 * V_6 , unsigned int V_30 ,
int V_31 , int V_32 , T_1 * V_23 )
{
unsigned long V_33 ;
int V_21 ;
F_20 ( & V_34 , V_33 ) ;
V_21 = F_11 ( V_35 , V_6 -> V_36 , F_21 ( V_30 ) ,
F_22 ( V_30 ) , V_31 , V_23 , V_32 ) ;
F_23 ( & V_34 , V_33 ) ;
return V_21 ? V_37 : V_38 ;
}
static int F_24 ( struct V_29 * V_6 , unsigned int V_30 ,
int V_31 , int V_32 , T_1 V_23 )
{
unsigned long V_33 ;
int V_21 ;
F_20 ( & V_34 , V_33 ) ;
V_21 = F_17 ( V_35 , V_6 -> V_36 , F_21 ( V_30 ) ,
F_22 ( V_30 ) , V_31 , & V_23 , V_32 ) ;
F_23 ( & V_34 , V_33 ) ;
return V_21 ? V_37 : V_38 ;
}
int F_25 ( struct V_39 * V_40 )
{
if ( V_40 -> V_6 -> V_41 != & V_42 ) {
return - V_43 ;
}
F_26 ( L_1 , F_27 ( V_40 ) ) ;
V_40 -> V_44 = F_28 ( V_35 -> V_4 ) + 2 ;
F_29 ( V_40 , V_45 , V_40 -> V_44 ) ;
return 0 ;
}
static void F_30 ( struct V_39 * V_4 )
{
V_28 V_46 ;
if ( V_4 -> V_6 -> V_41 != & V_42 ) {
return;
}
if ( V_4 -> V_6 -> V_36 != 0 || F_21 ( V_4 -> V_30 ) != 0 )
return;
F_26 ( L_2 , F_27 ( V_4 ) ) ;
F_31 ( V_4 ) ;
if ( F_32 ( V_4 , ~ 0 ) < 0 ) {
F_33 ( L_3 ) ;
return;
}
F_34 ( V_4 , V_47 , 3 ) ;
V_46 = 168 ;
F_26 ( L_4 ,
F_27 ( V_4 ) , V_46 ) ;
F_29 ( V_4 , V_48 , V_46 ) ;
}
int F_35 ( const struct V_39 * V_4 , V_28 V_49 , V_28 V_50 )
{
if ( V_4 -> V_6 -> V_41 != & V_42 ) {
return - V_43 ;
}
return F_28 ( V_35 -> V_4 ) + 2 ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_23 ;
if ( F_37 ( V_35 ) )
return;
V_35 = V_2 ;
F_38 ( L_5 ) ;
V_23 = V_51 ;
V_23 |= V_52 ;
F_3 ( V_2 , V_53 , V_23 ) ;
V_23 |= V_54 ;
F_3 ( V_2 , V_53 , V_23 ) ;
F_39 ( 150 ) ;
V_23 |= V_55 ;
F_3 ( V_2 , V_53 , V_23 ) ;
V_23 = V_56 ;
F_3 ( V_2 , V_57 , V_23 ) ;
F_39 ( 1 ) ;
if ( V_2 -> V_4 -> V_6 -> V_58 ) {
F_38 ( L_6 ) ;
V_2 -> V_11 = 1 ;
F_40 ( V_2 -> V_4 -> V_6 , 1 , 1 ) ;
F_41 ( V_2 -> V_4 -> V_6 , 1 , 1 ) ;
F_7 ( V_2 , F_42 ( 0 ) ,
F_5 ( V_2 , F_42 ( 0 ) )
| 0x0400 ) ;
}
F_3 ( V_2 , V_59 ,
V_60 ) ;
F_3 ( V_2 , V_16 ,
V_14 ) ;
F_3 ( V_2 , V_61 ,
V_62 | V_63 ) ;
F_43 ( 1000 , 2000 ) ;
V_23 = V_64 | V_65 ;
F_17 ( V_2 , 0 , 0 , 0 , V_66 , & V_23 , 2 ) ;
V_23 = 0 ;
F_17 ( V_2 , 0 , 0 , 0 , V_67 , & V_23 , 2 ) ;
F_3 ( V_2 , V_68 ,
V_69 ) ;
V_70 . V_71 = ( unsigned long ) F_13 ( V_72 , 0x04000000 ) ;
F_44 ( V_70 . V_71 ) ;
F_45 ( 10 ) ;
F_46 ( & V_70 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_73 * V_6 = V_2 -> V_4 -> V_6 ;
T_2 V_74 ;
T_1 V_10 ;
V_74 = ( V_6 -> V_75 & 0xFF00 ) ;
if ( V_74 != 0x4700 &&
V_74 != 0x5300 )
return 0 ;
if ( V_6 -> V_76 . V_77 & V_78 )
return 0 ;
if ( V_6 -> V_75 == 0x4712 ) {
if ( V_6 -> V_79 == V_80 )
return 0 ;
if ( V_6 -> V_79 == V_81 )
return 0 ;
}
if ( V_6 -> V_75 == 0x5350 )
return 0 ;
return ! F_14 ( V_10 , ( V_6 -> V_24 + ( V_2 -> V_4 -> V_82 * V_83 ) ) ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_2 V_10 = F_5 ( V_2 , F_42 ( 0 ) ) ;
if ( ( ( V_10 & 0xF000 ) >> 12 ) != V_2 -> V_4 -> V_82 ) {
V_10 &= ~ 0xF000 ;
V_10 |= ( V_2 -> V_4 -> V_82 << 12 ) ;
F_7 ( V_2 , F_42 ( 0 ) , V_10 ) ;
}
}
static V_28 F_49 ( struct V_1 * V_2 )
{
return ( F_50 ( V_2 , 0x204 ) & 0x10 ) ? 0xC0 : 0x80 ;
}
static void F_51 ( struct V_1 * V_2 )
{
const V_28 V_84 = 0x1D ;
const V_28 V_85 = 0x1F ;
T_2 V_10 ;
F_52 ( V_2 , V_85 , 1 ,
F_49 ( V_2 ) ) ;
V_10 = F_53 ( V_2 , V_84 , 1 ) ;
if ( V_10 & 0x4000 )
F_52 ( V_2 , V_84 , 1 , V_10 & ~ 0x4000 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_4 ;
struct V_73 * V_6 = V_87 -> V_6 ;
T_1 V_10 ;
V_10 = F_1 ( V_2 , V_61 ) ;
V_10 |= V_88 ;
V_10 |= V_89 ;
F_3 ( V_2 , V_61 , V_10 ) ;
if ( V_87 -> V_90 . V_91 < 5 ) {
V_10 = F_2 ( V_87 , V_92 ) ;
V_10 &= ~ V_93 ;
V_10 |= 2 ;
V_10 &= ~ V_94 ;
V_10 |= 3 << V_95 ;
F_4 ( V_87 , V_92 , V_10 ) ;
F_55 ( V_6 ) ;
} else if ( V_87 -> V_90 . V_91 >= 11 ) {
V_10 = F_1 ( V_2 , V_61 ) ;
V_10 |= V_96 ;
F_3 ( V_2 , V_61 , V_10 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_28 V_97 = V_2 -> V_4 -> V_90 . V_91 ;
if ( V_97 == 0 || V_97 == 1 ) {
V_10 = F_50 ( V_2 , 0x4 ) ;
V_10 |= 0x8 ;
F_57 ( V_2 , 0x4 , V_10 ) ;
}
if ( V_97 == 1 ) {
V_10 = F_50 ( V_2 , 0x100 ) ;
V_10 |= 0x40 ;
F_57 ( V_2 , 0x100 , V_10 ) ;
}
if ( V_97 == 0 ) {
const V_28 V_85 = 0x1F ;
F_52 ( V_2 , V_85 ,
2 , 0x8128 ) ;
F_52 ( V_2 , V_85 ,
6 , 0x0100 ) ;
F_52 ( V_2 , V_85 ,
7 , 0x1466 ) ;
} else if ( V_97 == 3 || V_97 == 4 || V_97 == 5 ) {
F_51 ( V_2 ) ;
} else if ( V_97 == 7 ) {
}
if ( V_97 >= 6 ) {
V_10 = F_5 ( V_2 , F_42 ( 5 ) ) ;
if ( ! ( V_10 & 0x8000 ) )
F_7 ( V_2 , F_42 ( 5 ) ,
V_10 | 0x8000 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_4 ;
struct V_73 * V_6 = V_87 -> V_6 ;
if ( V_6 -> V_98 == V_99 )
F_48 ( V_2 ) ;
F_4 ( V_87 , V_100 , 0 ) ;
if ( V_2 -> V_4 -> V_90 . V_101 == V_102 ) {
F_51 ( V_2 ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
struct V_86 * V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return;
if ( ! F_60 ( V_4 ) )
F_61 ( V_4 , 0 ) ;
#ifdef F_62
V_2 -> V_25 = F_47 ( V_2 ) ;
if ( V_2 -> V_25 )
F_36 ( V_2 ) ;
#endif
if ( ! V_2 -> V_25 )
F_58 ( V_2 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 , T_1 V_103 )
{
F_3 ( V_2 , 0x130 , V_103 ) ;
return F_1 ( V_2 , 0x134 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_103 , T_1 V_104 )
{
F_3 ( V_2 , 0x130 , V_103 ) ;
F_3 ( V_2 , 0x134 , V_104 ) ;
}
static void F_63 ( struct V_1 * V_2 , V_28 V_105 )
{
const T_2 V_106 = 0x128 ;
const T_2 V_107 = 0x12C ;
T_1 V_108 ;
int V_109 ;
V_108 = ( 1 << 30 ) ;
V_108 |= ( 1 << 28 ) ;
V_108 |= ( 1 << 17 ) ;
V_108 |= ( 0x1F << 18 ) ;
V_108 |= ( V_105 << 4 ) ;
F_3 ( V_2 , V_107 , V_108 ) ;
F_39 ( 10 ) ;
for ( V_109 = 0 ; V_109 < 200 ; V_109 ++ ) {
V_108 = F_1 ( V_2 , V_106 ) ;
if ( V_108 & 0x100 )
break;
F_64 ( 1 ) ;
}
}
static T_2 F_53 ( struct V_1 * V_2 , V_28 V_110 , V_28 V_103 )
{
const T_2 V_106 = 0x128 ;
const T_2 V_107 = 0x12C ;
int V_111 = 10 ;
T_2 V_112 = 0 ;
T_1 V_108 ;
int V_109 ;
V_108 = 0x80 ;
V_108 |= 0x2 ;
F_3 ( V_2 , V_106 , V_108 ) ;
if ( V_2 -> V_4 -> V_90 . V_91 >= 10 ) {
V_111 = 200 ;
F_63 ( V_2 , V_110 ) ;
}
V_108 = ( 1 << 30 ) ;
V_108 |= ( 1 << 29 ) ;
V_108 |= ( 1 << 17 ) ;
if ( V_2 -> V_4 -> V_90 . V_91 < 10 )
V_108 |= ( T_1 ) V_110 << 22 ;
V_108 |= ( T_1 ) V_103 << 18 ;
F_3 ( V_2 , V_107 , V_108 ) ;
F_39 ( 10 ) ;
for ( V_109 = 0 ; V_109 < V_111 ; V_109 ++ ) {
V_108 = F_1 ( V_2 , V_106 ) ;
if ( V_108 & 0x100 ) {
F_39 ( 10 ) ;
V_112 = F_1 ( V_2 , V_107 ) ;
break;
}
F_64 ( 1 ) ;
}
F_3 ( V_2 , V_106 , 0 ) ;
return V_112 ;
}
static void F_52 ( struct V_1 * V_2 , V_28 V_110 ,
V_28 V_103 , T_2 V_104 )
{
const T_2 V_106 = 0x128 ;
const T_2 V_107 = 0x12C ;
int V_111 = 10 ;
T_1 V_108 ;
int V_109 ;
V_108 = 0x80 ;
V_108 |= 0x2 ;
F_3 ( V_2 , V_106 , V_108 ) ;
if ( V_2 -> V_4 -> V_90 . V_91 >= 10 ) {
V_111 = 200 ;
F_63 ( V_2 , V_110 ) ;
}
V_108 = ( 1 << 30 ) ;
V_108 |= ( 1 << 28 ) ;
V_108 |= ( 1 << 17 ) ;
if ( V_2 -> V_4 -> V_90 . V_91 < 10 )
V_108 |= ( T_1 ) V_110 << 22 ;
V_108 |= ( T_1 ) V_103 << 18 ;
V_108 |= V_104 ;
F_3 ( V_2 , V_107 , V_108 ) ;
F_39 ( 10 ) ;
for ( V_109 = 0 ; V_109 < V_111 ; V_109 ++ ) {
V_108 = F_1 ( V_2 , V_106 ) ;
if ( V_108 & 0x100 )
break;
F_64 ( 1 ) ;
}
F_3 ( V_2 , V_106 , 0 ) ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_86 * V_4 )
{
struct V_86 * V_87 = V_2 -> V_4 ;
struct V_73 * V_6 ;
int V_21 = 0 ;
T_1 V_10 ;
if ( V_4 -> V_6 -> V_98 != V_99 ) {
goto V_12;
}
if ( ! V_87 )
goto V_12;
V_6 = V_87 -> V_6 ;
F_66 ( V_87 -> V_90 . V_101 != V_113 ) ;
if ( ( V_87 -> V_90 . V_91 >= 6 ) || ( V_87 -> V_90 . V_101 == V_102 ) ) {
T_1 V_114 ;
V_114 = ( 1 << V_4 -> V_82 ) ;
F_12 ( V_6 -> V_98 != V_99 ) ;
V_21 = F_67 ( V_6 -> V_115 , V_116 , & V_10 ) ;
if ( V_21 )
goto V_12;
V_10 |= V_114 << 8 ;
V_21 = F_34 ( V_6 -> V_115 , V_116 , V_10 ) ;
if ( V_21 )
goto V_12;
} else {
T_1 V_117 ;
V_117 = F_2 ( V_87 , V_100 ) ;
V_10 = F_2 ( V_4 , V_118 ) ;
V_10 &= V_119 ;
V_117 |= ( 1 << V_10 ) ;
F_4 ( V_87 , V_100 , V_117 ) ;
}
if ( V_2 -> V_120 )
goto V_12;
if ( V_87 -> V_90 . V_101 == V_113 ) {
F_54 ( V_2 ) ;
} else {
F_37 ( V_87 -> V_90 . V_101 != V_102 ) ;
F_56 ( V_2 ) ;
}
V_2 -> V_120 = 1 ;
V_12:
return V_21 ;
}
