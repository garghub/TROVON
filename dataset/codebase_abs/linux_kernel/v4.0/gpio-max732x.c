static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = V_5 ? V_4 -> V_10 : V_4 -> V_11 ;
V_9 = F_4 ( V_8 , V_6 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_1 ) ;
return V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = V_5 ? V_4 -> V_10 : V_4 -> V_11 ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_2 ) ;
return V_9 ;
}
* V_6 = ( T_1 ) V_9 ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_4 , unsigned V_13 )
{
return ( 1u << V_13 ) & V_4 -> V_14 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_15 ;
int V_9 ;
V_9 = F_6 ( V_4 , F_8 ( V_4 , V_13 ) , & V_15 ) ;
if ( V_9 < 0 )
return 0 ;
return V_15 & ( 1u << ( V_13 & 0x7 ) ) ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_13 , int V_16 ,
int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_17 ;
int V_9 ;
F_11 ( & V_4 -> V_18 ) ;
V_17 = ( V_13 > 7 ) ? V_4 -> V_17 [ 1 ] : V_4 -> V_17 [ 0 ] ;
V_17 = ( V_17 & ~ V_16 ) | ( V_6 & V_16 ) ;
V_9 = F_3 ( V_4 , F_8 ( V_4 , V_13 ) , V_17 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_13 > 7 )
V_4 -> V_17 [ 1 ] = V_17 ;
else
V_4 -> V_17 [ 0 ] = V_17 ;
V_19:
F_12 ( & V_4 -> V_18 ) ;
}
static void F_13 ( struct V_2 * V_3 , unsigned V_13 , int V_6 )
{
unsigned V_20 = V_13 & ~ 0x7 ;
T_1 V_16 = 1u << ( V_13 & 0x7 ) ;
F_10 ( V_3 , V_20 , V_16 , V_6 << ( V_13 & 0x7 ) ) ;
}
static void F_14 ( struct V_2 * V_3 ,
unsigned long * V_16 , unsigned long * V_21 )
{
unsigned V_22 = V_16 [ 0 ] & 0xff ;
unsigned V_23 = ( V_16 [ 0 ] >> 8 ) & 0xff ;
if ( V_22 )
F_10 ( V_3 , 0 , V_22 , V_21 [ 0 ] & 0xff ) ;
if ( V_23 )
F_10 ( V_3 , 8 , V_23 , ( V_21 [ 0 ] >> 8 ) & 0xff ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_16 = 1u << V_13 ;
if ( ( V_16 & V_4 -> V_24 ) == 0 ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_3 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
if ( ( V_16 & V_4 -> V_27 ) )
F_13 ( V_3 , V_13 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned V_13 , int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_16 = 1u << V_13 ;
if ( ( V_16 & V_4 -> V_27 ) == 0 ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_4 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
F_13 ( V_3 , V_13 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_4 , T_2 V_6 )
{
int V_9 ;
V_6 = F_19 ( V_6 ) ;
V_9 = F_20 ( V_4 -> V_10 , ( char * ) & V_6 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_12 , L_1 ) ;
return V_9 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_4 , T_2 * V_6 )
{
int V_9 ;
V_9 = F_22 ( V_4 -> V_10 , ( char * ) V_6 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_12 , L_2 ) ;
return V_9 ;
}
* V_6 = F_23 ( * V_6 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_4 )
{
T_2 V_28 ;
if ( V_4 -> V_29 == V_4 -> V_30 )
return;
V_4 -> V_29 = V_4 -> V_30 ;
if ( V_4 -> V_31 == V_32 )
return;
F_11 ( & V_4 -> V_18 ) ;
switch ( V_4 -> V_31 ) {
case V_33 :
V_28 = ( V_4 -> V_29 << 8 ) | V_4 -> V_17 [ 0 ] ;
F_18 ( V_4 , V_28 ) ;
break;
case V_34 :
V_28 = V_4 -> V_29 | V_4 -> V_17 [ 0 ] ;
F_3 ( V_4 , 1 , ( T_1 ) V_28 ) ;
break;
}
F_12 ( & V_4 -> V_18 ) ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_35 ) {
return F_26 ( V_4 -> V_35 ,
V_4 -> V_36 + V_13 ) ;
} else {
return - V_37 ;
}
}
static void F_27 ( struct V_38 * V_39 )
{
struct V_1 * V_4 = F_28 ( V_39 ) ;
V_4 -> V_30 &= ~ ( 1 << V_39 -> V_40 ) ;
}
static void F_29 ( struct V_38 * V_39 )
{
struct V_1 * V_4 = F_28 ( V_39 ) ;
V_4 -> V_30 |= 1 << V_39 -> V_40 ;
}
static void F_30 ( struct V_38 * V_39 )
{
struct V_1 * V_4 = F_28 ( V_39 ) ;
F_11 ( & V_4 -> V_41 ) ;
V_4 -> V_30 = V_4 -> V_29 ;
}
static void F_31 ( struct V_38 * V_39 )
{
struct V_1 * V_4 = F_28 ( V_39 ) ;
T_2 V_42 ;
T_2 V_43 ;
F_24 ( V_4 ) ;
V_42 = V_4 -> V_44 | V_4 -> V_45 ;
while ( V_42 ) {
V_43 = F_32 ( V_42 ) ;
F_15 ( & V_4 -> V_2 , V_43 ) ;
V_42 &= ~ ( 1 << V_43 ) ;
}
F_12 ( & V_4 -> V_41 ) ;
}
static int F_33 ( struct V_38 * V_39 , unsigned int type )
{
struct V_1 * V_4 = F_28 ( V_39 ) ;
T_2 V_13 = V_39 -> V_40 ;
T_2 V_16 = 1 << V_13 ;
if ( ! ( V_16 & V_4 -> V_24 ) ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_3 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
if ( ! ( type & V_46 ) ) {
F_5 ( & V_4 -> V_8 -> V_12 , L_5 ,
V_39 -> V_47 , type ) ;
return - V_48 ;
}
if ( type & V_49 )
V_4 -> V_44 |= V_16 ;
else
V_4 -> V_44 &= ~ V_16 ;
if ( type & V_50 )
V_4 -> V_45 |= V_16 ;
else
V_4 -> V_45 &= ~ V_16 ;
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_4 )
{
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
T_2 V_55 ;
int V_9 ;
V_9 = F_21 ( V_4 , & V_55 ) ;
if ( V_9 )
return 0 ;
V_53 = V_55 >> 8 ;
V_53 &= V_4 -> V_29 ;
if ( ! V_53 )
return 0 ;
V_51 = V_55 & 0xFF ;
V_51 &= V_4 -> V_29 ;
V_52 = V_51 ^ V_53 ;
V_54 = ( V_52 & V_4 -> V_44 ) |
( V_51 & V_4 -> V_45 ) ;
V_54 &= V_53 ;
return V_54 ;
}
static T_3 F_35 ( int V_47 , void * V_56 )
{
struct V_1 * V_4 = V_56 ;
T_1 V_54 ;
T_1 V_43 ;
V_54 = F_34 ( V_4 ) ;
if ( ! V_54 )
return V_57 ;
do {
V_43 = F_32 ( V_54 ) ;
F_36 ( F_37 ( V_4 -> V_35 , V_43 ) ) ;
V_54 &= ~ ( 1 << V_43 ) ;
} while ( V_54 );
return V_57 ;
}
static int F_38 ( struct V_35 * V_58 , unsigned int V_59 ,
T_4 V_60 )
{
struct V_1 * V_4 = V_58 -> V_61 ;
if ( ! ( V_4 -> V_24 & ( 1 << V_60 ) ) ) {
F_5 ( & V_4 -> V_8 -> V_12 ,
L_6 ,
V_60 ) ;
return - V_62 ;
}
F_39 ( V_59 , V_4 ) ;
F_40 ( V_59 , & V_63 ,
V_64 ) ;
F_41 ( V_59 , 1 ) ;
#ifdef F_42
F_43 ( V_59 , V_65 ) ;
#else
F_44 ( V_59 ) ;
#endif
return 0 ;
}
static void F_45 ( struct V_1 * V_4 )
{
if ( V_4 -> V_8 -> V_47 && V_4 -> V_35 )
F_46 ( V_4 -> V_35 ) ;
}
static int F_47 ( struct V_1 * V_4 ,
const struct V_66 * V_67 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_68 * V_69 = F_48 ( & V_8 -> V_12 ) ;
int V_70 = V_71 [ V_67 -> V_72 ] >> 32 ;
int V_9 ;
if ( ( ( V_69 && V_69 -> V_36 ) || V_8 -> V_47 )
&& V_70 != V_73 ) {
if ( V_69 )
V_4 -> V_36 = V_69 -> V_36 ;
V_4 -> V_31 = V_70 ;
F_49 ( & V_4 -> V_41 ) ;
V_4 -> V_35 = F_50 ( V_8 -> V_12 . V_74 ,
V_4 -> V_2 . V_75 , V_4 -> V_36 ,
& V_76 , V_4 ) ;
if ( ! V_4 -> V_35 ) {
F_5 ( & V_8 -> V_12 , L_7 ) ;
return - V_77 ;
}
V_9 = F_51 ( V_8 -> V_47 ,
NULL ,
F_35 ,
V_78 | V_79 ,
F_52 ( & V_8 -> V_12 ) , V_4 ) ;
if ( V_9 ) {
F_5 ( & V_8 -> V_12 , L_8 ,
V_8 -> V_47 ) ;
goto V_80;
}
V_4 -> V_2 . V_81 = F_25 ;
}
return 0 ;
V_80:
F_45 ( V_4 ) ;
return V_9 ;
}
static int F_47 ( struct V_1 * V_4 ,
const struct V_66 * V_67 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_68 * V_69 = F_48 ( & V_8 -> V_12 ) ;
int V_70 = V_71 [ V_67 -> V_72 ] >> 32 ;
if ( ( ( V_69 && V_69 -> V_36 ) || V_8 -> V_47 ) && V_70 != V_73 )
F_53 ( & V_8 -> V_12 , L_9 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_4 )
{
}
static int F_54 ( struct V_1 * V_4 ,
const struct V_66 * V_67 ,
unsigned V_82 )
{
struct V_2 * V_3 = & V_4 -> V_2 ;
T_5 V_83 = ( T_5 ) V_71 [ V_67 -> V_72 ] ;
int V_84 , V_85 = 0 ;
for ( V_84 = 0 ; V_84 < 16 ; V_84 ++ , V_83 >>= 2 ) {
unsigned int V_16 = 1 << V_85 ;
switch ( V_83 & 0x3 ) {
case V_86 :
V_4 -> V_27 |= V_16 ;
break;
case V_87 :
V_4 -> V_24 |= V_16 ;
break;
case V_88 :
V_4 -> V_27 |= V_16 ;
V_4 -> V_24 |= V_16 ;
break;
default:
continue;
}
if ( V_84 < 8 )
V_4 -> V_14 |= V_16 ;
V_85 ++ ;
}
if ( V_4 -> V_24 )
V_3 -> V_89 = F_15 ;
if ( V_4 -> V_27 ) {
V_3 -> V_90 = F_17 ;
V_3 -> V_91 = F_13 ;
V_3 -> V_92 = F_14 ;
}
V_3 -> V_93 = F_9 ;
V_3 -> V_94 = true ;
V_3 -> V_20 = V_82 ;
V_3 -> V_75 = V_85 ;
V_3 -> V_95 = V_4 -> V_8 -> V_25 ;
V_3 -> V_96 = V_97 ;
return V_85 ;
}
static struct V_68 * F_55 ( struct V_98 * V_12 )
{
struct V_68 * V_69 ;
V_69 = F_56 ( V_12 , sizeof( * V_69 ) , V_99 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_100 = - 1 ;
return V_69 ;
}
static int F_57 ( struct V_7 * V_8 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_101 * V_102 ;
struct V_1 * V_4 ;
struct V_7 * V_103 ;
T_2 V_104 , V_105 ;
int V_9 , V_106 ;
V_69 = F_48 ( & V_8 -> V_12 ) ;
V_102 = V_8 -> V_12 . V_74 ;
if ( ! V_69 && V_102 )
V_69 = F_55 ( & V_8 -> V_12 ) ;
if ( ! V_69 ) {
F_16 ( & V_8 -> V_12 , L_10 ) ;
return - V_48 ;
}
V_4 = F_56 ( & V_8 -> V_12 , sizeof( * V_4 ) , V_99 ) ;
if ( V_4 == NULL )
return - V_77 ;
V_4 -> V_8 = V_8 ;
V_106 = F_54 ( V_4 , V_67 , V_69 -> V_100 ) ;
V_4 -> V_2 . V_12 = & V_8 -> V_12 ;
V_104 = ( V_8 -> V_107 & 0x0f ) | 0x60 ;
V_105 = ( V_8 -> V_107 & 0x0f ) | 0x50 ;
switch ( V_8 -> V_107 & 0x70 ) {
case 0x60 :
V_4 -> V_10 = V_8 ;
if ( V_106 > 8 ) {
V_103 = F_58 ( V_8 -> V_108 , V_105 ) ;
V_4 -> V_11 = V_4 -> V_109 = V_103 ;
}
break;
case 0x50 :
V_4 -> V_11 = V_8 ;
if ( V_106 > 8 ) {
V_103 = F_58 ( V_8 -> V_108 , V_104 ) ;
V_4 -> V_10 = V_4 -> V_109 = V_103 ;
}
break;
default:
F_5 ( & V_8 -> V_12 , L_11 ,
V_8 -> V_107 ) ;
V_9 = - V_48 ;
goto V_80;
}
if ( V_106 > 8 && ! V_4 -> V_109 ) {
F_5 ( & V_8 -> V_12 ,
L_12 ) ;
V_9 = - V_110 ;
goto V_80;
}
F_49 ( & V_4 -> V_18 ) ;
F_6 ( V_4 , F_8 ( V_4 , 0 ) , & V_4 -> V_17 [ 0 ] ) ;
if ( V_106 > 8 )
F_6 ( V_4 , F_8 ( V_4 , 8 ) , & V_4 -> V_17 [ 1 ] ) ;
V_9 = F_47 ( V_4 , V_67 ) ;
if ( V_9 )
goto V_80;
V_9 = F_59 ( & V_4 -> V_2 ) ;
if ( V_9 )
goto V_80;
if ( V_69 && V_69 -> V_111 ) {
V_9 = V_69 -> V_111 ( V_8 , V_4 -> V_2 . V_20 ,
V_4 -> V_2 . V_75 , V_69 -> V_112 ) ;
if ( V_9 < 0 )
F_53 ( & V_8 -> V_12 , L_13 , V_9 ) ;
}
F_60 ( V_8 , V_4 ) ;
return 0 ;
V_80:
if ( V_4 -> V_109 )
F_61 ( V_4 -> V_109 ) ;
F_45 ( V_4 ) ;
return V_9 ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_68 * V_69 = F_48 ( & V_8 -> V_12 ) ;
struct V_1 * V_4 = F_63 ( V_8 ) ;
if ( V_69 && V_69 -> V_113 ) {
int V_9 ;
V_9 = V_69 -> V_113 ( V_8 , V_4 -> V_2 . V_20 ,
V_4 -> V_2 . V_75 , V_69 -> V_112 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_14 ,
L_15 , V_9 ) ;
return V_9 ;
}
}
F_64 ( & V_4 -> V_2 ) ;
F_45 ( V_4 ) ;
if ( V_4 -> V_109 )
F_61 ( V_4 -> V_109 ) ;
return 0 ;
}
static int T_6 F_65 ( void )
{
return F_66 ( & V_114 ) ;
}
static void T_7 F_67 ( void )
{
F_68 ( & V_114 ) ;
}
