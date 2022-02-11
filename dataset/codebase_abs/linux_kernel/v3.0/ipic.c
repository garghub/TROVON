static inline T_1 F_1 ( volatile T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static inline void F_3 ( volatile T_1 T_2 * V_1 , unsigned int V_2 , T_1 V_3 )
{
F_4 ( V_1 + ( V_2 >> 2 ) , V_3 ) ;
}
static inline struct V_4 * F_5 ( unsigned int V_5 )
{
return V_6 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_4 * V_4 = F_5 ( V_8 -> V_9 ) ;
unsigned int V_10 = F_7 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 ;
F_8 ( & V_13 , V_11 ) ;
V_12 = F_1 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 ) ;
V_12 |= ( 1 << ( 31 - V_15 [ V_10 ] . V_17 ) ) ;
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 , V_12 ) ;
F_9 ( & V_13 , V_11 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_4 * V_4 = F_5 ( V_8 -> V_9 ) ;
unsigned int V_10 = F_7 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 ;
F_8 ( & V_13 , V_11 ) ;
V_12 = F_1 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 ) ;
V_12 &= ~ ( 1 << ( 31 - V_15 [ V_10 ] . V_17 ) ) ;
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 , V_12 ) ;
F_11 () ;
F_9 ( & V_13 , V_11 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_4 * V_4 = F_5 ( V_8 -> V_9 ) ;
unsigned int V_10 = F_7 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 ;
F_8 ( & V_13 , V_11 ) ;
V_12 = 1 << ( 31 - V_15 [ V_10 ] . V_17 ) ;
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_18 , V_12 ) ;
F_11 () ;
F_9 ( & V_13 , V_11 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_4 * V_4 = F_5 ( V_8 -> V_9 ) ;
unsigned int V_10 = F_7 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 ;
F_8 ( & V_13 , V_11 ) ;
V_12 = F_1 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 ) ;
V_12 &= ~ ( 1 << ( 31 - V_15 [ V_10 ] . V_17 ) ) ;
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_16 , V_12 ) ;
V_12 = 1 << ( 31 - V_15 [ V_10 ] . V_17 ) ;
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_18 , V_12 ) ;
F_11 () ;
F_9 ( & V_13 , V_11 ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned int V_19 )
{
struct V_4 * V_4 = F_5 ( V_8 -> V_9 ) ;
unsigned int V_10 = F_7 ( V_8 ) ;
unsigned int V_20 , V_21 , V_22 ;
if ( V_19 == V_23 )
V_19 = V_24 ;
if ( ! ( V_19 & ( V_24 | V_25 ) ) ) {
F_15 ( V_26 L_1 ,
V_19 ) ;
return - V_27 ;
}
if ( ( V_19 & V_25 ) && ! V_15 [ V_10 ] . V_18 ) {
F_15 ( V_26 L_2
L_3 ) ;
return - V_27 ;
}
F_16 ( V_8 , V_19 ) ;
if ( V_19 & V_24 ) {
F_17 ( V_8 -> V_9 , V_28 ) ;
V_8 -> V_29 = & V_30 ;
} else {
F_17 ( V_8 -> V_9 , V_31 ) ;
V_8 -> V_29 = & V_32 ;
}
if ( V_10 == V_33 )
V_22 = 15 ;
else
if ( V_10 >= V_34 && V_10 <= V_35 )
V_22 = ( 14 - ( V_10 - V_34 ) ) ;
else
return ( V_19 & V_24 ) ? 0 : - V_27 ;
V_20 = F_1 ( V_4 -> V_14 , V_36 ) ;
if ( ( V_19 & V_37 ) == V_25 ) {
V_21 = V_20 | ( 1 << V_22 ) ;
} else {
V_21 = V_20 & ~ ( 1 << V_22 ) ;
}
if ( V_20 != V_21 )
F_3 ( V_4 -> V_14 , V_36 , V_21 ) ;
return V_38 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
return V_40 -> V_43 == NULL || V_40 -> V_43 == V_42 ;
}
static int F_19 ( struct V_39 * V_40 , unsigned int V_5 ,
T_3 V_44 )
{
struct V_4 * V_4 = V_40 -> V_45 ;
F_20 ( V_5 , V_4 ) ;
F_21 ( V_5 , & V_30 , V_28 ) ;
F_22 ( V_5 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 , struct V_41 * V_46 ,
const T_1 * V_47 , unsigned int V_48 ,
T_3 * V_49 , unsigned int * V_50 )
{
* V_49 = V_47 [ 0 ] ;
if ( V_48 > 1 )
* V_50 = V_47 [ 1 ] ;
else
* V_50 = V_23 ;
return 0 ;
}
struct V_4 * T_4 F_24 ( struct V_41 * V_42 , unsigned int V_11 )
{
struct V_4 * V_4 ;
struct V_51 V_52 ;
T_1 V_12 = 0 , V_53 ;
V_53 = F_25 ( V_42 , 0 , & V_52 ) ;
if ( V_53 )
return NULL ;
V_4 = F_26 ( sizeof( * V_4 ) , V_54 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_55 = F_27 ( V_42 , V_56 ,
V_57 ,
& V_58 , 0 ) ;
if ( V_4 -> V_55 == NULL ) {
F_28 ( V_4 ) ;
return NULL ;
}
V_4 -> V_14 = F_29 ( V_52 . V_59 , V_52 . V_60 - V_52 . V_59 + 1 ) ;
V_4 -> V_55 -> V_45 = V_4 ;
F_3 ( V_4 -> V_14 , V_61 , 0x0 ) ;
if ( V_11 & V_62 )
V_12 |= V_63 ;
if ( V_11 & V_64 )
V_12 |= V_65 ;
if ( V_11 & V_66 )
V_12 |= V_67 ;
if ( V_11 & V_68 )
V_12 |= V_69 ;
if ( V_11 & V_70 )
V_12 |= V_71 ;
if ( V_11 & V_72 )
V_12 |= V_73 ;
F_3 ( V_4 -> V_14 , V_74 , V_12 ) ;
V_12 = 0 ;
if ( V_11 & V_75 )
V_12 = V_76 ;
F_3 ( V_4 -> V_14 , V_77 , V_12 ) ;
V_12 = F_1 ( V_4 -> V_14 , V_78 ) ;
if ( V_11 & V_79 )
V_12 |= V_80 ;
else
V_12 &= ~ V_80 ;
F_3 ( V_4 -> V_14 , V_78 , V_12 ) ;
V_6 = V_4 ;
F_30 ( V_6 -> V_55 ) ;
F_3 ( V_4 -> V_14 , V_81 , 0 ) ;
F_3 ( V_4 -> V_14 , V_82 , 0 ) ;
F_15 ( L_4 , V_57 ,
V_6 -> V_14 ) ;
return V_4 ;
}
int F_31 ( unsigned int V_5 , unsigned int V_83 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_10 = F_32 ( V_5 ) ;
T_1 V_12 ;
if ( V_83 > 7 )
return - V_27 ;
if ( V_10 > 127 )
return - V_27 ;
if ( V_15 [ V_10 ] . V_84 == 0 )
return - V_27 ;
V_12 = F_1 ( V_4 -> V_14 , V_15 [ V_10 ] . V_84 ) ;
if ( V_83 < 4 ) {
V_12 &= ~ ( 0x7 << ( 20 + ( 3 - V_83 ) * 3 ) ) ;
V_12 |= V_15 [ V_10 ] . V_85 << ( 20 + ( 3 - V_83 ) * 3 ) ;
} else {
V_12 &= ~ ( 0x7 << ( 4 + ( 7 - V_83 ) * 3 ) ) ;
V_12 |= V_15 [ V_10 ] . V_85 << ( 4 + ( 7 - V_83 ) * 3 ) ;
}
F_3 ( V_4 -> V_14 , V_15 [ V_10 ] . V_84 , V_12 ) ;
return 0 ;
}
void F_33 ( unsigned int V_5 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_10 = F_32 ( V_5 ) ;
T_1 V_12 ;
V_12 = F_1 ( V_4 -> V_14 , V_74 ) ;
V_12 &= 0x7f000000 ;
V_12 |= ( V_10 & 0x7f ) << 24 ;
F_3 ( V_4 -> V_14 , V_74 , V_12 ) ;
}
void F_34 ( void )
{
F_3 ( V_6 -> V_14 , V_86 , V_87 ) ;
F_3 ( V_6 -> V_14 , V_88 , V_87 ) ;
F_3 ( V_6 -> V_14 , V_89 , V_87 ) ;
F_3 ( V_6 -> V_14 , V_90 , V_87 ) ;
F_3 ( V_6 -> V_14 , V_91 , V_87 ) ;
F_3 ( V_6 -> V_14 , V_92 , V_87 ) ;
}
void F_35 ( enum V_93 V_94 )
{
struct V_4 * V_4 = V_6 ;
T_1 V_12 ;
V_12 = F_1 ( V_4 -> V_14 , V_95 ) ;
V_12 |= ( 1 << ( 31 - V_94 ) ) ;
F_3 ( V_4 -> V_14 , V_95 , V_12 ) ;
}
void F_36 ( enum V_93 V_94 )
{
struct V_4 * V_4 = V_6 ;
T_1 V_12 ;
V_12 = F_1 ( V_4 -> V_14 , V_95 ) ;
V_12 &= ( 1 << ( 31 - V_94 ) ) ;
F_3 ( V_4 -> V_14 , V_95 , V_12 ) ;
}
T_1 F_37 ( void )
{
return F_1 ( V_6 -> V_14 , V_95 ) ;
}
void F_38 ( T_1 V_16 )
{
F_3 ( V_6 -> V_14 , V_95 , V_16 ) ;
}
unsigned int F_39 ( void )
{
int V_9 ;
F_40 ( V_6 == NULL ) ;
#define F_41 0x7f
V_9 = F_1 ( V_6 -> V_14 , V_96 ) & F_41 ;
if ( V_9 == 0 )
return V_97 ;
return F_42 ( V_6 -> V_55 , V_9 ) ;
}
static int F_43 ( void )
{
struct V_4 * V_4 = V_6 ;
V_98 . V_99 = F_1 ( V_4 -> V_14 , V_74 ) ;
V_98 . V_100 [ 0 ] = F_1 ( V_4 -> V_14 , V_86 ) ;
V_98 . V_100 [ 1 ] = F_1 ( V_4 -> V_14 , V_90 ) ;
V_98 . V_101 [ 0 ] = F_1 ( V_4 -> V_14 , V_81 ) ;
V_98 . V_101 [ 1 ] = F_1 ( V_4 -> V_14 , V_82 ) ;
V_98 . V_102 = F_1 ( V_4 -> V_14 , V_61 ) ;
V_98 . V_103 [ 0 ] = F_1 ( V_4 -> V_14 , V_91 ) ;
V_98 . V_103 [ 1 ] = F_1 ( V_4 -> V_14 , V_92 ) ;
V_98 . V_104 = F_1 ( V_4 -> V_14 , V_78 ) ;
V_98 . V_105 = F_1 ( V_4 -> V_14 , V_36 ) ;
V_98 . V_106 = F_1 ( V_4 -> V_14 , V_95 ) ;
V_98 . V_107 = F_1 ( V_4 -> V_14 , V_77 ) ;
if ( F_44 () ) {
F_3 ( V_4 -> V_14 , V_81 , 0 ) ;
F_3 ( V_4 -> V_14 , V_82 , 0 ) ;
F_3 ( V_4 -> V_14 , V_78 , 0 ) ;
F_3 ( V_4 -> V_14 , V_95 , 0 ) ;
}
return 0 ;
}
static void F_45 ( void )
{
struct V_4 * V_4 = V_6 ;
F_3 ( V_4 -> V_14 , V_74 , V_98 . V_99 ) ;
F_3 ( V_4 -> V_14 , V_86 , V_98 . V_100 [ 0 ] ) ;
F_3 ( V_4 -> V_14 , V_90 , V_98 . V_100 [ 1 ] ) ;
F_3 ( V_4 -> V_14 , V_81 , V_98 . V_101 [ 0 ] ) ;
F_3 ( V_4 -> V_14 , V_82 , V_98 . V_101 [ 1 ] ) ;
F_3 ( V_4 -> V_14 , V_61 , V_98 . V_102 ) ;
F_3 ( V_4 -> V_14 , V_91 , V_98 . V_103 [ 0 ] ) ;
F_3 ( V_4 -> V_14 , V_92 , V_98 . V_103 [ 1 ] ) ;
F_3 ( V_4 -> V_14 , V_78 , V_98 . V_104 ) ;
F_3 ( V_4 -> V_14 , V_36 , V_98 . V_105 ) ;
F_3 ( V_4 -> V_14 , V_95 , V_98 . V_106 ) ;
F_3 ( V_4 -> V_14 , V_77 , V_98 . V_107 ) ;
}
static int T_4 F_46 ( void )
{
if ( ! V_6 || ! V_6 -> V_14 )
return - V_108 ;
F_15 ( V_109 L_5 ) ;
F_47 ( & V_110 ) ;
return 0 ;
}
