struct V_1 * F_1 ( struct V_2 * V_3 , int type )
{
while( V_3 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 && V_6 [ V_4 ] . V_7 ; V_4 ++ )
if ( V_3 == V_6 [ V_4 ] . V_7 &&
( ! type || V_6 [ V_4 ] . type == type ) )
return & V_6 [ V_4 ] ;
V_3 = V_3 -> V_8 ;
}
return NULL ;
}
static inline int F_2 ( struct V_2 * V_9 , int type ,
int V_10 , T_1 V_11 , int V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
V_13 = F_1 ( V_9 , type ) ;
if ( ! V_13 )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 )
F_4 ( V_10 , V_11 ) ;
else
F_5 ( V_10 , V_11 ) ;
( void ) F_6 ( V_10 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long F_8 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_17 ;
unsigned long V_18 ;
unsigned long V_14 ;
int V_19 , V_20 ;
unsigned long V_21 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( ! strcmp ( V_9 -> V_22 , L_1 ) )
V_17 = V_23 ;
else if ( ! strcmp ( V_9 -> V_22 , L_2 ) )
V_17 = V_24 ;
else
return - V_15 ;
V_19 = ( V_13 -> type == V_25 || V_13 -> type == V_26
|| V_13 -> type == V_27 ) ;
V_20 = ( V_28 . V_29 != V_30 &&
V_28 . V_29 != V_31 ) ;
if ( V_12 ) {
#ifdef F_9
if ( ( V_16 & 0xfff ) == V_32 )
F_10 ( 1 ) ;
#endif
F_3 ( V_14 ) ;
V_18 = F_6 ( V_33 ) ;
if ( ! ( V_18 & V_34 ) ) {
V_18 |= V_34 ;
if ( V_19 ) {
if ( V_20 )
V_18 &= ~ V_35 ;
F_11 ( V_33 , V_18 ) ;
V_18 |= ( V_21 = V_36 ) ;
F_11 ( V_33 , V_18 ) ;
} else {
V_18 |= ( V_21 = V_37 ) ;
F_11 ( V_33 , V_18 ) ;
}
F_7 ( V_14 ) ;
( void ) F_6 ( V_33 ) ;
F_12 ( 15 ) ;
F_3 ( V_14 ) ;
V_18 &= ~ V_21 ;
F_11 ( V_33 , V_18 ) ;
}
if ( V_17 & V_23 )
V_18 |= V_38 ;
if ( V_17 & V_24 )
V_18 |= V_39 ;
F_11 ( V_33 , V_18 ) ;
V_13 -> V_14 |= V_17 ;
F_7 ( V_14 ) ;
if ( V_16 & V_40 )
V_13 -> V_14 |= V_41 ;
} else {
if ( V_13 -> V_14 & V_41 )
return - V_42 ;
F_3 ( V_14 ) ;
V_18 = F_6 ( V_33 ) ;
if ( V_17 & V_23 )
V_18 &= ~ V_38 ;
if ( V_17 & V_24 )
V_18 &= ~ V_39 ;
F_11 ( V_33 , V_18 ) ;
if ( ( V_18 & ( V_38 | V_39 ) ) == 0 ) {
V_18 &= ~ V_34 ;
if ( V_19 && V_20 )
V_18 |= V_35 ;
F_11 ( V_33 , V_18 ) ;
}
V_13 -> V_14 &= ~ ( V_17 ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
#ifdef F_9
if ( ( V_16 & 0xfff ) == V_32 )
F_10 ( 0 ) ;
#endif
}
return 0 ;
}
static long F_13 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
return F_2 ( V_9 , V_43 ,
V_33 , V_44 , V_12 ) ;
}
static long F_14 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
return F_2 ( V_9 , V_43 ,
V_33 , V_45 , V_12 ) ;
}
static long F_15 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
switch( V_16 ) {
case 0 :
if ( V_12 )
F_2 ( V_9 , V_43 ,
V_33 , V_46 , 1 ) ;
return F_2 ( V_9 , V_43 ,
V_33 , V_47 , V_12 ) ;
case 1 :
return F_2 ( V_9 , V_43 ,
V_33 , V_48 , V_12 ) ;
default:
return - V_15 ;
}
}
static long F_16 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
switch( V_16 ) {
case 0 :
return F_2 ( V_9 , V_43 ,
V_33 , V_49 , ! V_12 ) ;
case 1 :
return F_2 ( V_9 , V_43 ,
V_33 , V_50 , ! V_12 ) ;
default:
return - V_15 ;
}
}
static long F_17 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
if ( ( V_28 . V_51 & V_52 ) == 0 )
return - V_42 ;
if ( V_12 == 1 ) {
F_5 ( V_33 , V_46 ) ;
} else if ( V_12 == 0 ) {
F_4 ( V_33 , V_46 ) ;
}
return 0 ;
}
static long F_18 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
struct V_1 * V_13 ;
T_2 V_53 ;
unsigned long V_14 ;
V_13 = F_1 ( V_9 , V_54 ) ;
if ( ! V_13 )
return - V_15 ;
V_53 = F_19 ( V_55 ) & ~ 1 ;
if ( ! V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_55 , V_53 ) ;
F_7 ( V_14 ) ;
( void ) F_19 ( V_55 ) ;
F_12 ( 250 ) ;
}
if ( V_28 . V_29 != V_30 &&
V_28 . V_29 != V_31 ) {
F_3 ( V_14 ) ;
if ( V_12 )
F_5 ( V_56 , V_35 ) ;
else
F_4 ( V_56 , V_35 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_56 ) ;
F_12 ( 250 ) ;
}
if ( V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_55 , V_53 | 1 ) ;
( void ) F_19 ( V_55 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_55 , V_53 ) ;
( void ) F_19 ( V_55 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_55 , V_53 | 1 ) ;
( void ) F_19 ( V_55 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ;
}
return 0 ;
}
static long F_21 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
return F_2 ( V_9 , V_54 ,
V_56 ,
V_57 | V_58 ,
V_12 ) ;
}
static long F_22 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
V_13 = F_1 ( V_9 , V_54 ) ;
if ( ! V_13 )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 )
F_4 ( V_56 , V_59 ) ;
else
F_5 ( V_56 , V_59 ) ;
( void ) F_6 ( V_56 ) ;
F_23 ( 10 ) ;
if ( V_12 )
F_5 ( V_60 , 0x04000000 ) ;
else
F_4 ( V_60 , 0x04000000 ) ;
( void ) F_6 ( V_60 ) ;
F_23 ( 10 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long F_24 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
switch( V_16 ) {
case 0 :
return F_2 ( V_9 , V_54 ,
V_56 , V_61 , V_12 ) ;
case 1 :
return F_2 ( V_9 , V_54 ,
V_56 , V_62 , V_12 ) ;
default:
return - V_15 ;
}
}
static long F_25 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
switch( V_16 ) {
case 0 :
return F_2 ( V_9 , V_54 ,
V_56 , V_63 , ! V_12 ) ;
case 1 :
return F_2 ( V_9 , V_54 ,
V_56 , V_64 , ! V_12 ) ;
default:
return - V_15 ;
}
}
static long F_26 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( V_12 ) {
F_3 ( V_14 ) ;
F_4 ( V_56 , V_65 ) ;
F_4 ( V_56 , V_66 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_56 ) ;
F_12 ( 10 ) ;
F_3 ( V_14 ) ;
F_5 ( V_56 , V_66 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_56 ) ;
F_12 ( 10 ) ;
} else {
F_3 ( V_14 ) ;
F_5 ( V_56 , V_65 ) ;
F_7 ( V_14 ) ;
}
return 0 ;
}
static long F_27 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
if ( V_28 . V_29 == V_30 ||
V_28 . V_29 == V_31 )
return 0 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( V_12 ) {
F_3 ( V_14 ) ;
F_4 ( V_56 , V_67 ) ;
F_5 ( V_56 , V_68 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_56 ) ;
} else {
F_3 ( V_14 ) ;
F_4 ( V_56 , V_68 ) ;
F_5 ( V_56 , V_67 ) ;
F_7 ( V_14 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_13 , struct V_69 * V_70 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 13 ; V_4 ++ ) {
volatile struct V_69 T_3 * V_71 = ( void T_3 * )
( V_13 -> V_72 + ( ( 0x8000 + V_4 * 0x100 ) >> 2 ) ) ;
V_70 [ V_4 ] . V_73 = F_29 ( & V_71 -> V_73 ) ;
V_70 [ V_4 ] . V_74 = F_29 ( & V_71 -> V_74 ) ;
V_70 [ V_4 ] . V_75 = F_29 ( & V_71 -> V_75 ) ;
V_70 [ V_4 ] . V_76 = F_29 ( & V_71 -> V_76 ) ;
V_70 [ V_4 ] . V_77 = F_29 ( & V_71 -> V_77 ) ;
}
}
static void F_30 ( struct V_1 * V_13 , struct V_69 * V_70 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 13 ; V_4 ++ ) {
volatile struct V_69 T_3 * V_71 = ( void T_3 * )
( V_13 -> V_72 + ( ( 0x8000 + V_4 * 0x100 ) >> 2 ) ) ;
F_31 ( & V_71 -> V_78 , ( V_79 | V_80 | V_81 | V_82 | V_83 | V_84 ) << 16 ) ;
while ( F_29 ( & V_71 -> V_85 ) & V_79 )
F_32 () ;
F_31 ( & V_71 -> V_73 , V_70 [ V_4 ] . V_73 ) ;
F_31 ( & V_71 -> V_74 , V_70 [ V_4 ] . V_74 ) ;
F_31 ( & V_71 -> V_75 , V_70 [ V_4 ] . V_75 ) ;
F_31 ( & V_71 -> V_76 , V_70 [ V_4 ] . V_76 ) ;
F_31 ( & V_71 -> V_77 , V_70 [ V_4 ] . V_77 ) ;
}
}
static void F_33 ( struct V_1 * V_13 , int V_86 )
{
if ( V_86 ) {
F_28 ( V_13 , V_87 ) ;
V_88 [ 2 ] = F_6 ( 0x38 ) ;
V_88 [ 3 ] = F_6 ( 0x3c ) ;
} else {
F_28 ( V_13 , V_89 ) ;
V_88 [ 0 ] = F_6 ( 0x38 ) ;
V_88 [ 1 ] = F_6 ( 0x3c ) ;
V_90 = F_6 ( 0x34 ) ;
F_4 ( V_56 , V_68 ) ;
F_5 ( V_56 , V_67 ) ;
F_5 ( V_56 , V_91 ) ;
F_5 ( V_56 , V_63 ) ;
F_5 ( V_56 , V_65 | V_66 ) ;
}
F_20 ( V_55 ,
F_19 ( V_55 ) & ~ 1 ) ;
F_4 ( V_56 , V_35 ) ;
F_5 ( V_56 , V_38 | V_39 | V_92 ) ;
( void ) F_6 ( V_56 ) ;
}
static void F_34 ( struct V_1 * V_13 , int V_86 )
{
if ( V_86 ) {
F_11 ( 0x38 , V_88 [ 2 ] ) ;
( void ) F_6 ( 0x38 ) ;
F_12 ( 1 ) ;
F_11 ( 0x3c , V_88 [ 3 ] ) ;
( void ) F_6 ( 0x38 ) ;
F_12 ( 10 ) ;
F_30 ( V_13 , V_87 ) ;
} else {
F_11 ( 0x38 , V_88 [ 0 ] | V_91 ) ;
( void ) F_6 ( 0x38 ) ;
F_12 ( 1 ) ;
F_11 ( 0x3c , V_88 [ 1 ] ) ;
( void ) F_6 ( 0x38 ) ;
F_12 ( 1 ) ;
F_11 ( 0x34 , V_90 ) ;
( void ) F_6 ( 0x38 ) ;
F_12 ( 10 ) ;
F_30 ( V_13 , V_89 ) ;
}
}
static long F_35 ( struct V_2 * V_9 , long V_16 ,
long V_12 )
{
if ( ( V_28 . V_51 & V_52 ) == 0 )
return - V_42 ;
if ( V_12 == 1 ) {
if ( V_6 [ 1 ] . type == V_27 )
F_33 ( & V_6 [ 0 ] , 1 ) ;
F_33 ( & V_6 [ 0 ] , 0 ) ;
} else if ( V_12 == 0 ) {
F_34 ( & V_6 [ 0 ] , 0 ) ;
if ( V_6 [ 1 ] . type == V_27 )
F_34 ( & V_6 [ 0 ] , 1 ) ;
}
return 0 ;
}
static long F_36 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
unsigned long V_17 ;
T_1 V_18 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( ! strcmp ( V_9 -> V_22 , L_1 ) )
V_17 = V_23 ;
else if ( ! strcmp ( V_9 -> V_22 , L_2 ) )
V_17 = V_24 ;
else
return - V_15 ;
if ( V_12 ) {
int V_93 = 0 ;
int V_94 = 0 ;
F_3 ( V_14 ) ;
V_18 = F_6 ( V_95 ) ;
if ( ! ( V_18 & V_96 ) ) {
V_18 |= V_96 ;
V_93 = 1 ;
}
if ( V_17 & V_23 ) {
V_18 |= V_97 ;
if ( ( V_16 & 0xfff ) == V_98 )
V_18 &= ~ V_99 ;
else
V_18 |= V_99 ;
}
if ( V_17 & V_24 ) {
V_18 |= V_100 ;
if ( ( V_16 & 0xfff ) == V_32 ) {
V_18 &= ~ V_101 ;
V_18 |= V_102 ;
V_18 |= V_103 | V_104 ;
V_18 |= V_105 ;
V_18 &= ~ ( V_106 | V_107 | V_108 ) ;
V_18 &= ~ ( V_109 | V_110 ) ;
V_94 = 1 ;
} else
V_18 |= V_101 ;
}
F_11 ( V_95 , V_18 ) ;
V_13 -> V_14 |= V_17 ;
if ( V_93 ) {
F_4 ( V_95 , V_111 ) ;
( void ) F_6 ( V_95 ) ;
F_7 ( V_14 ) ;
F_12 ( 15 ) ;
F_3 ( V_14 ) ;
F_5 ( V_95 , V_111 ) ;
}
if ( V_94 ) {
F_4 ( V_95 , V_112 ) ;
( void ) F_6 ( V_95 ) ;
F_7 ( V_14 ) ;
F_12 ( 15 ) ;
F_3 ( V_14 ) ;
F_5 ( V_95 , V_112 ) ;
}
F_7 ( V_14 ) ;
if ( V_16 & V_40 )
V_13 -> V_14 |= V_41 ;
} else {
if ( V_13 -> V_14 & V_41 )
return - V_42 ;
F_3 ( V_14 ) ;
V_18 = F_6 ( V_95 ) ;
if ( V_17 & V_23 )
V_18 &= ~ V_97 ;
if ( V_17 & V_24 ) {
V_18 &= ~ V_100 ;
if ( ( V_16 & 0xfff ) == V_32 ) {
V_18 &= ~ V_102 ;
V_18 &= ~ ( V_103 | V_104 ) ;
V_18 &= ~ ( V_106 | V_107 | V_108 ) ;
V_18 &= ~ ( V_105 | V_109 | V_110 ) ;
}
}
F_11 ( V_95 , V_18 ) ;
if ( ( V_18 & ( V_97 | V_100 ) ) == 0 ) {
V_18 &= ~ V_96 ;
F_11 ( V_95 , V_18 ) ;
}
V_13 -> V_14 &= ~ ( V_17 ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
}
return 0 ;
}
static long
F_37 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
T_2 V_53 ;
unsigned long V_14 ;
if ( V_9 == NULL ) {
if ( V_6 [ 0 ] . type != V_113 )
return - V_15 ;
V_9 = V_6 [ 0 ] . V_7 ;
}
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
V_53 = F_19 ( V_114 ) ;
V_53 |= V_115 ;
V_53 &= ~ V_116 ;
if ( ! V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 ) ;
F_7 ( V_14 ) ;
( void ) F_19 ( V_114 ) ;
F_12 ( 250 ) ;
}
F_3 ( V_14 ) ;
if ( V_12 ) {
F_5 ( V_117 , V_118 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_117 ) ;
F_12 ( 250 ) ;
} else {
F_4 ( V_117 , V_118 ) ;
F_7 ( V_14 ) ;
}
if ( V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 | V_116 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 | V_116 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ;
}
return 0 ;
}
static long
F_38 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
T_2 V_53 ;
unsigned long V_14 ;
if ( V_9 == NULL ) {
if ( V_6 [ 0 ] . type != V_119 &&
V_6 [ 0 ] . type != V_120 )
return - V_15 ;
V_9 = V_6 [ 0 ] . V_7 ;
}
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
V_53 = F_19 ( V_114 ) ;
V_53 |= V_115 ;
V_53 &= ~ V_116 ;
if ( ! V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 ) ;
F_7 ( V_14 ) ;
( void ) F_19 ( V_114 ) ;
F_12 ( 250 ) ;
}
F_3 ( V_14 ) ;
if ( V_12 ) {
F_20 ( V_121 ,
V_115 ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_117 ) ;
F_12 ( 250 ) ;
} else {
F_20 ( V_121 ,
V_115 | V_116 ) ;
F_7 ( V_14 ) ;
}
if ( V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 | V_116 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ; F_3 ( V_14 ) ;
F_20 ( V_114 , V_53 | V_116 ) ;
( void ) F_19 ( V_114 ) ;
F_7 ( V_14 ) ; F_12 ( 250 ) ;
}
return 0 ;
}
static long
F_39 ( struct V_2 * V_9 , long V_12 )
{
unsigned long V_14 ;
struct V_122 * V_123 = NULL ;
T_2 V_124 , V_125 ;
int V_126 ;
if ( V_127 < 0x24 )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 )
F_40 ( V_128 , V_129 ) ;
else
F_41 ( V_128 , V_129 ) ;
( void ) F_42 ( V_128 ) ;
F_7 ( V_14 ) ;
F_23 ( 20 ) ;
if ( V_12 ) {
if ( F_43 ( V_9 , & V_124 , & V_125 ) == 0 )
V_123 = F_44 ( V_124 , V_125 ) ;
if ( V_123 == NULL )
return 0 ;
V_126 = F_45 ( V_123 ) ;
if ( V_126 == 0 )
F_46 ( V_123 ) ;
F_47 ( V_123 ) ;
if ( V_126 )
return V_126 ;
}
return 0 ;
}
static long
F_48 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
switch( V_16 ) {
case 0 :
return F_2 ( V_9 , V_54 ,
V_130 , V_131 , V_12 ) ;
case 1 :
return F_2 ( V_9 , V_54 ,
V_130 , V_132 , V_12 ) ;
case 2 :
return F_2 ( V_9 , V_54 ,
V_130 , V_133 , V_12 ) ;
case 3 :
return F_39 ( V_9 , V_12 ) ;
default:
return - V_15 ;
}
}
static long
F_49 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
switch( V_16 ) {
case 0 :
return F_2 ( V_9 , V_54 ,
V_130 , V_134 , ! V_12 ) ;
case 1 :
return F_2 ( V_9 , V_54 ,
V_130 , V_135 , ! V_12 ) ;
case 2 :
return F_2 ( V_9 , V_54 ,
V_130 , V_136 , ! V_12 ) ;
default:
return - V_15 ;
}
}
static long
F_50 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
F_3 ( V_14 ) ;
if ( V_12 )
F_40 ( V_128 , V_137 ) ;
else
F_41 ( V_128 , V_137 ) ;
( void ) F_42 ( V_128 ) ;
F_7 ( V_14 ) ;
F_23 ( 20 ) ;
return 0 ;
}
static long
F_51 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
struct V_1 * V_13 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
F_3 ( V_14 ) ;
F_20 ( V_138 , V_115 ) ;
( void ) F_19 ( V_138 ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
F_3 ( V_14 ) ;
F_20 ( V_138 ,
V_116 ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
return 0 ;
}
static long
F_52 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( V_28 . V_29 == V_139 ||
V_28 . V_29 == V_140 ) {
F_3 ( V_14 ) ;
if ( V_12 )
F_20 ( V_141 ,
V_115 |
V_116 ) ;
else
F_20 ( V_141 ,
V_115 ) ;
( void ) F_19 ( V_141 ) ;
F_7 ( V_14 ) ;
}
return 0 ;
}
static long
F_53 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
int V_142 ;
V_13 = F_1 ( V_9 , 0 ) ;
if ( ! V_13 )
return - V_15 ;
if ( V_9 != V_13 -> V_7 &&
( ! V_9 -> V_8 || V_9 -> V_8 != V_13 -> V_7 ) )
return - V_15 ;
V_142 = ( V_13 -> V_14 & V_143 ) != 0 ;
if ( V_12 == V_142 )
return 0 ;
if ( V_12 ) {
F_3 ( V_14 ) ;
F_20 ( V_144 + 0xf , 5 ) ;
( void ) F_19 ( V_144 + 0xf ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
F_3 ( V_14 ) ;
F_20 ( V_144 + 0xf , 4 ) ;
( void ) F_19 ( V_144 + 0xf ) ;
F_7 ( V_14 ) ;
F_12 ( 10 ) ;
F_3 ( V_14 ) ;
F_5 ( V_117 , V_145 ) ;
( void ) F_6 ( V_117 ) ;
F_23 ( 10 ) ;
F_20 ( V_146 + 0xb , 0 ) ;
( void ) F_19 ( V_146 + 0xb ) ;
F_23 ( 10 ) ;
F_20 ( V_146 + 0xa , 0x28 ) ;
( void ) F_19 ( V_146 + 0xa ) ;
F_23 ( 10 ) ;
F_20 ( V_146 + 0xd , 0x28 ) ;
( void ) F_19 ( V_146 + 0xd ) ;
F_23 ( 10 ) ;
F_20 ( V_144 + 0xd , 0x28 ) ;
( void ) F_19 ( V_144 + 0xd ) ;
F_23 ( 10 ) ;
F_20 ( V_144 + 0xe , 0x28 ) ;
( void ) F_19 ( V_144 + 0xe ) ;
F_7 ( V_14 ) ;
F_23 ( 10 ) ;
F_11 ( 0x1c000 , 0 ) ;
F_12 ( 1 ) ;
F_20 ( 0x1a3e0 , 0x41 ) ;
( void ) F_19 ( 0x1a3e0 ) ;
F_23 ( 10 ) ;
F_3 ( V_14 ) ;
F_4 ( V_117 , V_145 ) ;
( void ) F_6 ( V_117 ) ;
F_7 ( V_14 ) ;
F_12 ( 100 ) ;
V_13 -> V_14 |= V_143 ;
} else {
F_3 ( V_14 ) ;
F_5 ( V_117 , V_145 ) ;
( void ) F_6 ( V_117 ) ;
F_20 ( V_147 , 0 ) ;
F_20 ( V_148 , 0 ) ;
F_20 ( V_149 , 0 ) ;
F_20 ( V_150 , 0 ) ;
F_20 ( V_151 , 0 ) ;
( void ) F_19 ( V_151 ) ;
F_7 ( V_14 ) ;
V_13 -> V_14 &= ~ V_143 ;
}
return 0 ;
}
static long
F_54 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned int V_152 = 0 ;
unsigned long V_14 ;
struct V_1 * V_13 ;
struct V_2 * V_153 ;
struct V_2 * V_154 ;
const int V_155 [] = { V_156 ,
V_157 ,
V_158 ,
V_159 } ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 )
return - V_15 ;
V_154 = F_55 ( L_3 ) ;
if ( V_154 == NULL )
return - V_15 ;
for ( V_153 = V_154 -> V_3 ; V_153 != NULL ; V_153 = V_153 -> V_160 ) {
const T_1 * V_161 = F_56 ( V_153 , L_4 , NULL ) ;
const T_1 * V_162 = F_56 ( V_153 , L_5 , NULL ) ;
if ( V_161 == NULL || V_162 == NULL )
continue;
if ( V_16 == * V_161 ) {
V_152 = * V_162 ;
break;
}
}
F_57 ( V_154 ) ;
if ( V_153 == NULL || V_152 == 0 )
V_152 = V_155 [ V_16 ] ;
F_3 ( V_14 ) ;
F_20 ( V_152 , V_115 ) ;
( void ) F_19 ( V_152 ) ;
F_23 ( 1 ) ;
F_20 ( V_152 , 0 ) ;
( void ) F_19 ( V_152 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long
F_58 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
const char * V_163 ;
int V_164 ;
T_1 V_10 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
V_163 = F_56 ( V_9 , L_6 , NULL ) ;
if ( ! V_163 )
return - V_15 ;
if ( strncmp ( V_163 , L_7 , 8 ) == 0 )
V_164 = 0 ;
else if ( strncmp ( V_163 , L_8 , 8 ) == 0 )
V_164 = 2 ;
else if ( strncmp ( V_163 , L_9 , 8 ) == 0 )
V_164 = 4 ;
else
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 ) {
if ( V_164 == 0 ) {
F_5 ( V_95 , ( V_165 | V_166 ) ) ;
( void ) F_6 ( V_95 ) ;
F_7 ( V_14 ) ;
F_12 ( 1 ) ;
F_3 ( V_14 ) ;
F_4 ( V_95 , V_167 ) ;
} else if ( V_164 == 2 ) {
F_5 ( V_95 , ( V_168 | V_169 ) ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_95 ) ;
F_12 ( 1 ) ;
F_3 ( V_14 ) ;
F_4 ( V_95 , V_170 ) ;
} else if ( V_164 == 4 ) {
F_5 ( V_130 , ( V_171 | V_172 ) ) ;
F_7 ( V_14 ) ;
( void ) F_6 ( V_130 ) ;
F_12 ( 1 ) ;
F_3 ( V_14 ) ;
F_4 ( V_130 , V_173 ) ;
}
if ( V_164 < 4 ) {
V_10 = F_6 ( V_174 ) ;
V_10 &= ~ ( F_59 ( V_164 ) | F_60 ( V_164 ) |
F_61 ( V_164 ) | F_62 ( V_164 ) ) ;
V_10 &= ~ ( F_59 ( V_164 + 1 ) | F_60 ( V_164 + 1 ) |
F_61 ( V_164 + 1 ) | F_62 ( V_164 + 1 ) ) ;
F_11 ( V_174 , V_10 ) ;
( void ) F_6 ( V_174 ) ;
F_23 ( 10 ) ;
} else {
V_10 = F_6 ( V_175 ) ;
V_10 &= ~ ( F_63 ( 0 ) | F_64 ( 0 ) |
F_65 ( 0 ) | F_66 ( 0 ) ) ;
V_10 &= ~ ( F_63 ( 1 ) | F_64 ( 1 ) |
F_65 ( 1 ) | F_66 ( 1 ) ) ;
F_11 ( V_175 , V_10 ) ;
( void ) F_6 ( V_175 ) ;
F_23 ( 10 ) ;
}
if ( V_13 -> type == V_120 ) {
T_1 V_176 = 0 , V_177 = 0 ;
T_1 V_178 , V_179 ;
int V_180 = 1000 ;
F_7 ( V_14 ) ;
switch ( V_164 ) {
case 0 :
V_176 = V_181 ;
V_177 = V_182 ;
break;
case 2 :
V_176 = V_183 ;
V_177 = V_184 ;
break;
case 4 :
V_176 = V_185 ;
V_177 = V_186 ;
break;
}
do {
if ( -- V_180 <= 0 ) {
F_67 ( V_187 L_10
L_11 ) ;
break;
}
F_12 ( 1 ) ;
V_178 = F_42 ( V_188 ) ;
V_179 = F_42 ( V_189 ) ;
} while ( ( V_178 & V_176 ) | ( V_179 & V_177 ) );
F_3 ( V_14 ) ;
}
} else {
if ( V_164 < 4 ) {
V_10 = F_6 ( V_174 ) ;
V_10 |= F_59 ( V_164 ) | F_60 ( V_164 ) |
F_61 ( V_164 ) | F_62 ( V_164 ) ;
V_10 |= F_59 ( V_164 + 1 ) | F_60 ( V_164 + 1 ) |
F_61 ( V_164 + 1 ) | F_62 ( V_164 + 1 ) ;
F_11 ( V_174 , V_10 ) ;
( void ) F_6 ( V_174 ) ;
F_23 ( 1 ) ;
} else {
V_10 = F_6 ( V_175 ) ;
V_10 |= F_63 ( 0 ) | F_64 ( 0 ) |
F_65 ( 0 ) | F_66 ( 0 ) ;
V_10 |= F_63 ( 1 ) | F_64 ( 1 ) |
F_65 ( 1 ) | F_66 ( 1 ) ;
F_11 ( V_175 , V_10 ) ;
( void ) F_6 ( V_175 ) ;
F_23 ( 1 ) ;
}
if ( V_164 == 0 ) {
if ( V_13 -> type != V_120 )
F_5 ( V_95 , V_167 ) ;
( void ) F_6 ( V_95 ) ;
F_23 ( 1 ) ;
F_4 ( V_95 , ( V_165 | V_166 ) ) ;
( void ) F_6 ( V_95 ) ;
} else if ( V_164 == 2 ) {
if ( V_13 -> type != V_120 )
F_5 ( V_95 , V_170 ) ;
( void ) F_6 ( V_95 ) ;
F_23 ( 1 ) ;
F_4 ( V_95 , ( V_168 | V_169 ) ) ;
( void ) F_6 ( V_95 ) ;
} else if ( V_164 == 4 ) {
F_23 ( 1 ) ;
F_4 ( V_130 , ( V_171 | V_172 ) ) ;
( void ) F_6 ( V_130 ) ;
}
F_23 ( 1 ) ;
}
F_7 ( V_14 ) ;
return 0 ;
}
static long
F_68 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
struct V_1 * V_13 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
if ( ! ( V_13 -> V_14 & V_190 ) )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 ) {
F_40 ( V_128 , V_191 ) ;
( void ) F_42 ( V_128 ) ;
} else {
F_41 ( V_128 , V_191 ) ;
( void ) F_42 ( V_128 ) ;
}
F_7 ( V_14 ) ;
F_12 ( 1 ) ;
return 0 ;
}
static long
F_69 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
struct V_1 * V_13 ;
if ( ( V_28 . V_51 & V_192 ) == 0 )
return - V_15 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
if ( ! ( V_13 -> V_14 & V_190 ) )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 ) {
F_20 ( V_193 , 0 ) ;
F_19 ( V_193 ) ;
F_23 ( 10 ) ;
} else {
F_20 ( V_193 , 4 ) ;
F_19 ( V_193 ) ; F_23 ( 10 ) ;
}
F_7 ( V_14 ) ;
F_12 ( 1 ) ;
return 0 ;
}
static long
F_70 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
if ( V_127 < 0xd2 )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_16 )
F_40 ( V_194 , V_195 ) ;
else
F_41 ( V_194 , V_195 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long
F_71 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
return F_19 ( V_16 ) ;
}
static long
F_72 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
F_20 ( V_16 , ( T_2 ) ( V_12 & 0xff ) ) ;
return 0 ;
}
static long F_73 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
unsigned long V_14 ;
if ( V_9 == NULL )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 ) {
F_4 ( V_130 , V_196 ) ;
F_32 () ;
V_197 [ 0 ] = NULL ;
} else {
V_197 [ 0 ] = V_9 ;
F_32 () ;
F_5 ( V_130 , V_196 ) ;
}
F_7 ( V_14 ) ;
F_12 ( 1 ) ;
return 0 ;
}
static long F_74 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
unsigned long V_14 ;
if ( V_9 == NULL )
return - V_15 ;
F_3 ( V_14 ) ;
if ( V_12 ) {
F_4 ( V_130 , V_198 ) ;
F_32 () ;
V_197 [ 1 ] = NULL ;
} else {
V_197 [ 1 ] = V_9 ;
F_32 () ;
F_5 ( V_130 , V_198 ) ;
}
F_7 ( V_14 ) ;
F_12 ( 1 ) ;
return 0 ;
}
static long F_75 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned long V_14 ;
struct V_2 * V_8 = F_76 ( V_9 ) ;
int V_199 ;
if ( V_8 == NULL )
return 0 ;
V_199 = strcmp ( V_8 -> V_22 , L_12 ) == 0 ||
strcmp ( V_8 -> V_22 , L_13 ) == 0 ;
F_57 ( V_8 ) ;
if ( ! V_199 )
return 0 ;
F_3 ( V_14 ) ;
F_40 ( V_200 , V_201 | V_202 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long F_77 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
struct V_2 * V_203 ;
int V_204 ;
V_203 = F_78 ( V_9 , NULL ) ;
if ( ! V_203 )
return - V_15 ;
V_204 = F_79 ( V_203 , L_14 ) ;
F_57 ( V_203 ) ;
if ( ! V_204 )
return 0 ;
F_20 ( V_205 + 29 ,
V_115 | V_116 ) ;
F_80 ( 10 ) ;
F_20 ( V_205 + 29 , 0 ) ;
return 0 ;
}
static long F_81 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
struct V_1 * V_13 = & V_6 [ 0 ] ;
unsigned long V_14 ;
int V_206 ;
T_1 V_207 [ 3 ] [ 3 ] = {
{ 0 ,
V_208 |
V_209 | V_210 ,
V_211
} ,
{ V_99 ,
V_212 |
V_213 | V_214 ,
V_215
} ,
{ V_101 ,
V_216 |
V_217 | V_218 ,
V_219
} ,
} ;
if ( V_13 -> type != V_220 && V_13 -> type != V_221 )
return - V_15 ;
if ( strncmp ( V_9 -> V_22 , L_15 , 4 ) )
return - V_15 ;
V_206 = V_9 -> V_22 [ 4 ] - 'a' ;
switch( V_206 ) {
case 0 :
case 1 :
break;
case 2 :
if ( V_13 -> type == V_221 )
break;
default:
return - V_15 ;
}
F_3 ( V_14 ) ;
if ( V_12 ) {
F_5 ( V_95 , V_207 [ V_206 ] [ 0 ] ) ;
F_4 ( V_130 , V_207 [ V_206 ] [ 1 ] ) ;
F_4 ( V_175 , V_207 [ V_206 ] [ 2 ] ) ;
} else {
F_5 ( V_175 , V_207 [ V_206 ] [ 2 ] ) ;
F_5 ( V_130 , V_207 [ V_206 ] [ 1 ] ) ;
F_4 ( V_95 , V_207 [ V_206 ] [ 0 ] ) ;
}
F_23 ( 10 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
static long F_82 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
unsigned int V_152 = 0 ;
unsigned long V_14 ;
struct V_1 * V_13 ;
struct V_2 * V_153 ;
struct V_2 * V_154 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_220 && V_13 -> type != V_221 )
return - V_15 ;
V_154 = F_55 ( L_3 ) ;
if ( V_154 == NULL )
return - V_15 ;
for ( V_153 = V_154 -> V_3 ; V_153 != NULL ; V_153 = V_153 -> V_160 ) {
const T_1 * V_161 = F_56 ( V_153 , L_4 , NULL ) ;
const T_1 * V_162 = F_56 ( V_153 , L_5 , NULL ) ;
if ( V_161 == NULL || V_162 == NULL )
continue;
if ( V_16 == * V_161 ) {
V_152 = * V_162 ;
break;
}
}
F_57 ( V_154 ) ;
if ( V_153 == NULL || V_152 == 0 )
return - V_15 ;
F_3 ( V_14 ) ;
F_20 ( V_152 , V_115 ) ;
( void ) F_19 ( V_152 ) ;
F_23 ( 1 ) ;
F_20 ( V_152 , 0 ) ;
( void ) F_19 ( V_152 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
void F_83 ( void )
{
if ( V_222 == 3 )
F_84 ( V_223 , 0 ) ;
}
static void F_85 ( struct V_1 * V_13 , int V_224 )
{
T_1 V_225 ;
if ( V_224 ) {
F_12 ( 1 ) ;
F_4 ( V_95 , V_226 ) ;
( void ) F_6 ( V_95 ) ;
F_12 ( 1 ) ;
}
F_5 ( V_95 , V_97 | V_100 |
V_96 |
V_102 | V_103 |
V_104 ) ;
F_5 ( V_227 , V_228 ) ;
F_4 ( V_227 , V_229 ) ;
F_5 ( V_130 ,
V_230 | V_231 |
V_232 | V_233 |
V_234 | V_235 |
V_236 | V_237 |
V_238 | V_239 |
V_131 | V_134 |
V_132 | V_135 |
V_133 ) ;
F_4 ( V_117 , V_118 ) ;
F_5 ( V_117 , V_240 ) ;
V_225 = F_6 ( V_175 ) ;
if ( V_13 -> V_241 >= 2 ) {
V_225 |= V_242 ;
if ( V_224 )
V_225 |= V_243 ;
}
V_225 |= V_244 | V_245 |
V_246 ;
if ( V_224 )
V_225 |= V_247 ;
V_225 &= ~ ( V_248 | V_249 | V_250
| V_251 | V_215 | V_211 ) ;
if ( V_224 )
V_225 &= ~ ( V_252 | V_253 ) ;
F_11 ( V_175 , V_225 ) ;
( void ) F_6 ( V_95 ) ; F_12 ( 1 ) ;
}
static void F_86 ( struct V_1 * V_13 , int V_224 )
{
T_1 V_225 ;
F_5 ( V_95 , V_97 | V_100 |
V_96 |
V_167 | V_170 ) ;
F_5 ( V_130 ,
V_230 | V_231 |
V_232 | V_233 |
V_234 | V_235 |
V_236 | V_237 |
V_238 | V_239 |
V_133 ) ;
if ( V_28 . V_51 & V_254 )
F_5 ( V_130 , V_136 ) ;
F_4 ( V_117 , V_118 ) ;
V_225 = F_6 ( V_175 ) ;
V_225 |= V_244 | V_245 |
V_246 ;
V_225 &= ~ ( V_249 | V_250 | V_251
| V_211 | V_215 ) ;
if ( V_224 )
V_225 &= ~ ( V_253 | V_252 ) ;
F_11 ( V_175 , V_225 ) ;
( void ) F_6 ( V_95 ) ; F_12 ( 1 ) ;
}
static void F_87 ( struct V_1 * V_13 , int V_224 )
{
T_1 V_225 ;
F_5 ( V_95 , V_97 | V_100 |
V_96 ) ;
F_5 ( V_130 ,
V_234 | V_235 |
V_236 | V_237 |
V_238 | V_239 |
V_131 ) ;
if ( V_28 . V_51 & V_254 )
F_5 ( V_130 , V_136 ) ;
V_225 = F_6 ( V_175 ) ;
V_225 &= ~ ( V_249 | V_250 |
V_215 | V_211 ) ;
if ( V_224 )
V_225 &= ~ ( V_252 | V_255 ) ;
F_11 ( V_175 , V_225 ) ;
( void ) F_6 ( V_95 ) ;
F_12 ( 10 ) ;
}
static int
F_88 ( void )
{
struct V_1 * V_13 ;
int V_4 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
if ( V_13 -> V_14 & V_143 )
F_53 ( V_13 -> V_7 , 0 , 0 ) ;
if ( V_13 -> V_14 & V_190 ) {
F_68 ( NULL , 0 , 0 ) ;
F_69 ( NULL , 0 , 0 ) ;
}
if ( V_13 -> type == V_113 )
F_37 ( V_13 -> V_7 , 0 , 0 ) ;
else
F_38 ( V_13 -> V_7 , 0 , 0 ) ;
F_52 ( V_13 -> V_7 , 0 , 0 ) ;
V_256 [ 0 ] = F_6 ( V_257 ) ;
V_256 [ 1 ] = F_6 ( V_258 ) ;
for ( V_4 = 0 ; V_4 < V_259 ; V_4 ++ )
V_260 [ V_4 ] = F_19 ( V_146 + V_4 ) ;
for ( V_4 = 0 ; V_4 < V_261 ; V_4 ++ )
V_262 [ V_4 ] = F_19 ( V_144 + V_4 ) ;
if ( V_13 -> type == V_113 )
V_90 = F_6 ( V_227 ) ;
V_88 [ 0 ] = F_6 ( V_95 ) ;
V_88 [ 1 ] = F_6 ( V_130 ) ;
V_88 [ 2 ] = F_6 ( V_117 ) ;
V_88 [ 3 ] = F_6 ( V_175 ) ;
V_88 [ 4 ] = F_6 ( V_174 ) ;
if ( V_13 -> type == V_119 || V_13 -> type == V_120 )
V_88 [ 5 ] = F_6 ( V_263 ) ;
F_28 ( V_13 , V_89 ) ;
if ( V_13 -> type == V_119 )
F_86 ( V_13 , 1 ) ;
else if ( V_13 -> type == V_120 )
F_87 ( V_13 , 1 ) ;
else if ( V_13 -> type == V_113 )
F_85 ( V_13 , 1 ) ;
V_264 = F_42 ( V_128 ) ;
F_84 ( V_128 , V_264 &
~ ( V_191 ) ) ;
F_23 ( 100 ) ;
F_84 ( V_265 , V_266 ) ;
F_84 ( V_267 , V_268 ) ;
F_12 ( 10 ) ;
if ( V_28 . V_29 == V_269 ) {
F_4 ( 0x506e0 , 0x00400000 ) ;
F_4 ( 0x506e0 , 0x80000000 ) ;
}
return 0 ;
}
static int
F_89 ( void )
{
struct V_1 * V_13 ;
int V_4 ;
V_13 = & V_6 [ 0 ] ;
if ( V_13 -> type != V_113 && V_13 -> type != V_119 &&
V_13 -> type != V_120 )
return - V_15 ;
F_84 ( V_267 , V_270 ) ;
F_23 ( 10 ) ;
F_84 ( V_265 , V_271 ) ;
F_23 ( 10 ) ;
if ( V_13 -> type == V_113 ) {
F_11 ( V_227 , V_90 ) ;
( void ) F_6 ( V_227 ) ; F_23 ( 10 ) ;
}
F_11 ( V_95 , V_88 [ 0 ] ) ;
( void ) F_6 ( V_95 ) ; F_23 ( 10 ) ;
F_11 ( V_130 , V_88 [ 1 ] ) ;
( void ) F_6 ( V_130 ) ; F_23 ( 10 ) ;
F_11 ( V_117 , V_88 [ 2 ] ) ;
( void ) F_6 ( V_117 ) ; F_23 ( 10 ) ;
F_11 ( V_175 , V_88 [ 3 ] ) ;
( void ) F_6 ( V_175 ) ; F_23 ( 10 ) ;
F_11 ( V_174 , V_88 [ 4 ] ) ;
( void ) F_6 ( V_174 ) ; F_23 ( 10 ) ;
if ( V_13 -> type == V_119 || V_13 -> type == V_120 ) {
F_11 ( V_263 , V_88 [ 5 ] ) ;
( void ) F_6 ( V_263 ) ; F_23 ( 10 ) ;
}
F_30 ( V_13 , V_89 ) ;
F_11 ( V_257 , V_256 [ 0 ] ) ;
F_11 ( V_258 , V_256 [ 1 ] ) ;
for ( V_4 = 0 ; V_4 < V_259 ; V_4 ++ )
F_20 ( V_146 + V_4 , V_260 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_261 ; V_4 ++ )
F_20 ( V_144 + V_4 , V_262 [ V_4 ] ) ;
if ( V_28 . V_29 == V_269 ) {
F_5 ( 0x506e0 , 0x00400000 ) ;
F_5 ( 0x506e0 , 0x80000000 ) ;
}
F_84 ( V_128 , V_264 ) ;
F_23 ( 100 ) ;
return 0 ;
}
static long
F_90 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
if ( V_16 == 1 ) {
if ( V_12 == 1 ) {
F_84 ( V_265 , V_266 ) ;
F_84 ( V_267 , V_272 ) ;
} else {
F_84 ( V_267 , V_270 ) ;
F_23 ( 10 ) ;
F_84 ( V_265 , V_271 ) ;
F_23 ( 10 ) ;
}
return 0 ;
}
if ( ( V_28 . V_51 & V_52 ) == 0 )
return - V_42 ;
#ifdef F_91
if ( V_12 == 1 )
return F_88 () ;
else if ( V_12 == 0 )
return F_89 () ;
#endif
return 0 ;
}
static long
F_92 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
if ( V_28 . V_51 & V_273 )
V_28 . V_51 |= V_52 ;
return 0 ;
}
static long F_93 ( struct V_2 * V_9 , long V_16 , long V_12 )
{
switch( V_16 ) {
case V_274 :
return V_28 . V_29 ;
case V_275 :
return V_28 . V_51 ;
case V_276 :
* ( ( const char * * ) V_12 ) = V_28 . V_277 ;
return 0 ;
}
return - V_278 ;
}
long F_94 ( unsigned int V_279 , ... )
{
struct V_2 * V_9 ;
long V_16 , V_12 ;
int V_4 ;
T_4 V_280 = NULL ;
T_5 args ;
if ( V_28 . V_281 )
for ( V_4 = 0 ; V_28 . V_281 [ V_4 ] . V_282 ; V_4 ++ )
if ( V_28 . V_281 [ V_4 ] . V_279 == V_279 ) {
V_280 = V_28 . V_281 [ V_4 ] . V_282 ;
break;
}
if ( ! V_280 )
for ( V_4 = 0 ; V_283 [ V_4 ] . V_282 ; V_4 ++ )
if ( V_283 [ V_4 ] . V_279 == V_279 ) {
V_280 = V_283 [ V_4 ] . V_282 ;
break;
}
if ( ! V_280 )
return - V_15 ;
va_start ( args , V_279 ) ;
V_9 = (struct V_2 * ) va_arg ( args , void * ) ;
V_16 = va_arg ( args , long ) ;
V_12 = va_arg ( args , long ) ;
va_end ( args ) ;
return V_280 ( V_9 , V_16 , V_12 ) ;
}
static int T_6 F_95 ( void )
{
int V_4 ;
struct V_1 * V_13 = & V_6 [ 0 ] ;
const char * V_284 = NULL ;
struct V_2 * V_285 ;
int V_286 = 0 ;
V_285 = F_96 ( NULL , L_16 ) ;
if ( V_285 != NULL )
V_284 = F_56 ( V_285 , L_17 , NULL ) ;
for( V_4 = 0 ; V_284 && V_4 < F_97 ( V_287 ) ; V_4 ++ ) {
if ( strcmp ( V_284 , V_287 [ V_4 ] . V_288 ) == 0 ) {
V_28 = V_287 [ V_4 ] ;
goto V_289;
}
}
for( V_4 = 0 ; V_4 < F_97 ( V_287 ) ; V_4 ++ ) {
if ( F_98 ( V_287 [ V_4 ] . V_288 ) ) {
V_28 = V_287 [ V_4 ] ;
goto V_289;
}
}
switch( V_13 -> type ) {
#ifndef F_99
case V_290 :
V_28 . V_29 = V_291 ;
V_28 . V_277 = L_18 ;
break;
case V_43 :
V_28 . V_29 = V_292 ;
V_28 . V_277 = L_19 ;
break;
case V_25 :
V_28 . V_29 = V_293 ;
V_28 . V_277 = L_20 ;
V_28 . V_281 = V_294 ;
break;
case V_26 :
V_28 . V_29 = V_295 ;
V_28 . V_277 = L_21 ;
V_28 . V_281 = V_296 ;
break;
case V_113 :
V_28 . V_29 = V_297 ;
V_28 . V_277 = L_22 ;
V_28 . V_281 = V_298 ;
break;
case V_119 :
V_28 . V_29 = V_299 ;
V_28 . V_277 = L_23 ;
V_28 . V_281 = V_300 ;
break;
case V_120 :
V_28 . V_29 = V_301 ;
V_28 . V_277 = L_24 ;
V_28 . V_281 = V_302 ;
break;
#else
case V_220 :
V_28 . V_29 = V_303 ;
V_28 . V_277 = L_25 ;
V_28 . V_281 = V_304 ;
break;
case V_221 :
V_28 . V_29 = V_305 ;
V_28 . V_277 = L_26 ;
V_28 . V_281 = V_304 ;
break;
#endif
default:
V_286 = - V_15 ;
goto V_306;
}
V_289:
#ifndef F_99
if ( V_28 . V_29 == V_307 ) {
T_1 T_3 * V_308 = F_100 ( 0xf3000034 , 4 ) ;
if ( ! V_308 ) {
V_286 = - V_15 ;
goto V_306;
}
if ( F_101 ( V_308 ) & 0x20000000UL )
V_28 . V_29 = V_309 ;
F_102 ( V_308 ) ;
}
while ( V_310 && V_127 > 3 ) {
struct V_2 * V_154 = F_55 ( L_3 ) ;
struct V_2 * V_153 ;
if ( ! V_154 || ! V_154 -> V_3 ) {
F_67 ( V_311 L_27 ) ;
F_57 ( V_154 ) ;
break;
}
V_153 = V_154 -> V_3 ;
if ( V_153 -> V_160 ) {
F_57 ( V_154 ) ;
break;
}
if ( F_56 ( V_153 , L_28 , NULL ) ) {
F_57 ( V_154 ) ;
break;
}
F_57 ( V_154 ) ;
V_312 = 1 ;
F_67 ( V_313 L_29 ) ;
break;
}
V_314 = 1 ;
#else
V_312 = 1 ;
#endif
if ( V_284 && ( strncmp ( V_284 , L_30 , 9 ) == 0
|| strncmp ( V_284 , L_31 , 5 ) == 0 ) )
V_28 . V_51 |= V_254 ;
F_67 ( V_315 L_32 , V_28 . V_277 ) ;
V_306:
F_57 ( V_285 ) ;
return V_286 ;
}
static void T_6 F_103 ( void )
{
const T_1 * V_316 ;
T_7 V_317 ;
unsigned long V_318 ;
V_319 = F_96 ( NULL , L_33 ) ;
V_222 = 1 ;
if ( V_319 == NULL ) {
V_319 = F_96 ( NULL , L_12 ) ;
V_222 = 3 ;
}
if ( V_319 == NULL ) {
V_319 = F_96 ( NULL , L_13 ) ;
V_222 = 4 ;
}
if ( V_319 == NULL ) {
V_222 = 0 ;
return;
}
V_316 = F_56 ( V_319 , L_4 , NULL ) ;
if ( V_316 == NULL )
return;
V_317 = F_104 ( V_319 , V_316 ) ;
if ( V_317 == 0 )
return;
V_310 = F_100 ( V_317 , 0x40000 ) ;
if ( V_310 == NULL )
return;
V_127 = F_105 ( F_106 ( V_320 ) ) ;
if ( V_222 == 3 || V_222 == 4 ) {
V_321 = F_100 ( V_317 + V_322 , 0x1000 ) ;
if ( V_321 == NULL ) {
F_102 ( V_310 ) ;
return;
}
}
F_67 ( V_315 L_34
L_35 , V_222 == 3 ? L_36 :
V_222 == 4 ? L_37 : L_38 ,
( unsigned int ) V_317 , V_127 ) ;
F_67 ( V_315 L_39 , ( unsigned long ) V_310 ) ;
if ( V_127 < 0x11 ) {
V_318 = F_42 ( V_323 ) & ~ V_324 ;
V_318 |= ( ( V_127 < 3 ) ? V_325 :
V_326 ) <<
V_327 ;
F_84 ( V_323 , V_318 ) ;
}
if ( ( V_127 >= 0x11 && V_127 <= 0x24 ) ||
V_127 == 0xc0 )
F_84 ( 0x2160 , F_42 ( 0x2160 ) & 0x00ffffff ) ;
}
static void T_6 F_107 ( const char * V_22 , const char * V_328 , int type )
{
struct V_2 * V_9 ;
int V_4 ;
volatile T_1 T_3 * V_72 ;
const T_1 * V_316 , * V_329 ;
T_7 V_330 ;
T_8 V_331 ;
for ( V_9 = NULL ; ( V_9 = F_96 ( V_9 , V_22 ) ) != NULL ; ) {
if ( ! V_328 )
break;
if ( F_79 ( V_9 , V_328 ) )
break;
}
if ( ! V_9 )
return;
for( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( ! V_6 [ V_4 ] . V_7 )
break;
if ( V_6 [ V_4 ] . V_7 == V_9 )
return;
}
if ( V_4 >= V_5 ) {
F_67 ( V_187 L_40 ) ;
F_67 ( V_187 L_41 , V_9 -> V_332 ) ;
return;
}
V_316 = F_108 ( V_9 , 0 , & V_331 , NULL ) ;
if ( V_316 == NULL ) {
F_67 ( V_187 L_42 ,
V_9 -> V_332 ) ;
return;
}
V_330 = F_104 ( V_9 , V_316 ) ;
if ( V_330 == 0 ) {
F_67 ( V_187 L_43 ,
V_9 -> V_332 ) ;
return;
}
V_72 = F_100 ( V_330 , ( unsigned long ) V_331 ) ;
if ( ! V_72 ) {
F_67 ( V_187 L_44 ,
V_9 -> V_332 ) ;
return;
}
if ( type == V_113 || type == V_220 ) {
const T_1 * V_333 = F_56 ( V_9 , L_45 , NULL ) ;
if ( * V_333 == 0x00000025 )
type = V_119 ;
if ( * V_333 == 0x0000003e )
type = V_120 ;
if ( * V_333 == 0x0000004f )
type = V_221 ;
}
V_6 [ V_4 ] . V_7 = V_9 ;
V_6 [ V_4 ] . type = type ;
V_6 [ V_4 ] . V_72 = V_72 ;
V_6 [ V_4 ] . V_14 = V_23 | V_24 ;
V_6 [ V_4 ] . V_22 = V_334 [ type ] ;
V_329 = F_56 ( V_9 , L_46 , NULL ) ;
if ( V_329 )
V_6 [ V_4 ] . V_241 = * V_329 ;
F_67 ( V_315 L_47 ,
V_334 [ type ] , V_6 [ V_4 ] . V_241 , V_6 [ V_4 ] . V_72 ) ;
}
static int T_6
F_109 ( void )
{
F_107 ( L_48 , NULL , V_290 ) ;
F_107 ( L_49 , NULL , V_43 ) ;
F_107 ( L_50 , NULL , V_335 ) ;
F_107 ( L_51 , L_52 , V_113 ) ;
F_107 ( L_51 , L_53 , V_26 ) ;
F_107 ( L_51 , L_54 , V_27 ) ;
F_107 ( L_51 , L_55 , V_25 ) ;
F_107 ( L_51 , L_56 , V_220 ) ;
if ( V_6 [ 0 ] . type == V_27
&& V_6 [ 1 ] . type == V_25 ) {
struct V_1 V_225 = V_6 [ 0 ] ;
V_6 [ 0 ] = V_6 [ 1 ] ;
V_6 [ 1 ] = V_225 ;
}
if ( V_6 [ 0 ] . type == V_335
&& V_6 [ 1 ] . type == V_43 ) {
struct V_1 V_225 = V_6 [ 0 ] ;
V_6 [ 0 ] = V_6 [ 1 ] ;
V_6 [ 1 ] = V_225 ;
}
V_6 [ 0 ] . V_336 . V_337 = 0 ;
V_6 [ 1 ] . V_336 . V_337 = 1 ;
return ( V_6 [ 0 ] . V_7 == NULL ) ? - V_15 : 0 ;
}
static void T_6
F_110 ( struct V_2 * V_153 )
{
int V_338 ;
const struct V_339 {
int V_340 ;
char V_22 [ 1 ] ;
} * V_341 ;
const char * V_342 ;
int V_343 = V_344 ;
int V_345 = 0 ;
V_341 = F_56 ( V_153 , L_57 , & V_338 ) ;
V_342 = F_56 ( V_153 , L_58 , & V_338 ) ;
if ( V_342 && ( strcmp ( V_342 , L_59 ) == 0 ) )
V_343 = V_32 ;
else if ( F_79 ( V_153 , L_60 ) )
V_345 = 1 ;
else if ( V_341 && V_341 -> V_340 > 0 ) {
if ( strcmp ( V_341 -> V_22 , L_61 ) == 0 )
V_343 = V_32 ;
else if ( strcmp ( V_341 -> V_22 , L_62 ) == 0 )
V_345 = 1 ;
}
if ( V_345 )
F_111 ( V_346 , V_153 , 0 , 0 ) ;
F_111 ( V_347 , V_153 , V_343 , 0 ) ;
}
static void T_6
F_112 ( void )
{
struct V_2 * V_153 ;
if ( V_6 [ 0 ] . type == V_43 ) {
struct V_1 * V_13 = & V_6 [ 0 ] ;
V_153 = F_96 ( NULL , L_63 ) ;
if ( V_153 )
F_4 ( V_33 , V_46 ) ;
else
F_11 ( V_33 , V_348 ) ;
F_57 ( V_153 ) ;
} else if ( V_6 [ 1 ] . type == V_43 ) {
struct V_1 * V_13 = & V_6 [ 1 ] ;
F_4 ( V_33 , V_46 ) ;
}
#ifdef F_99
if ( V_6 [ 0 ] . type == V_220 ||
V_6 [ 0 ] . type == V_221 ) {
#ifndef F_113
V_153 = F_114 ( NULL , L_64 ) ;
if ( V_153 != NULL )
V_153 = F_114 ( V_153 , L_64 ) ;
if ( V_153 != NULL ) {
F_83 () ;
F_57 ( V_153 ) ;
}
#endif
F_115 (np, L_65 )
if ( F_79 ( V_153 , L_66 ) )
F_73 ( V_153 , 0 , 1 ) ;
F_115 (np, L_67 ) {
if ( F_79 ( V_153 , L_68 ) ) {
V_6 [ 0 ] . V_14 |= V_190 ;
F_74 ( V_153 , 0 , 1 ) ;
}
}
}
#else
if ( V_6 [ 0 ] . type == V_113 ||
V_6 [ 0 ] . type == V_119 ||
V_6 [ 0 ] . type == V_120 ) {
F_115 (np, L_65 ) {
if ( V_153 -> V_8
&& F_79 ( V_153 -> V_8 , L_69 )
&& F_79 ( V_153 , L_70 ) )
F_50 ( V_153 , 0 , 1 ) ;
}
F_115 (np, L_67 ) {
if ( V_153 -> V_8
&& F_79 ( V_153 -> V_8 , L_69 )
&& ( F_79 ( V_153 , L_71 ) ||
F_79 ( V_153 , L_72 ) ||
F_79 ( V_153 , L_73 ) ) ) {
V_6 [ 0 ] . V_14 |= V_190 ;
F_68 ( V_153 , 0 , 1 ) ;
}
}
V_153 = F_96 ( NULL , L_74 ) ;
F_115 (np, L_74 ) {
if ( V_153 -> V_8
&& F_79 ( V_153 -> V_8 , L_69 )
&& F_79 ( V_153 , L_75 ) ) {
F_39 ( V_153 , 1 ) ;
}
}
F_115 (np, L_76 ) {
if ( V_153 -> V_8 == V_6 [ 0 ] . V_7 ) {
V_6 [ 0 ] . V_14 |= V_143 ;
F_53 ( V_153 , 0 , 0 ) ;
}
}
}
if ( V_6 [ 0 ] . V_7 )
F_94 ( V_349 ,
V_6 [ 0 ] . V_7 , 0 , 0 ) ;
if ( V_6 [ 0 ] . V_7 && V_6 [ 0 ] . type == V_25
&& ( V_28 . V_29 == V_350 ||
V_28 . V_29 == V_351 ) ) {
struct V_1 * V_13 = & V_6 [ 0 ] ;
F_4 ( V_56 , V_67 ) ;
F_5 ( V_56 , V_68 ) ;
}
#endif
F_115 (np, L_1 )
F_110 ( V_153 ) ;
F_57 ( V_153 ) ;
F_115 (np, L_2 )
F_110 ( V_153 ) ;
F_57 ( V_153 ) ;
}
void T_6
F_116 ( void )
{
F_103 () ;
if ( F_109 () ) {
F_67 ( V_311 L_77 ) ;
return;
}
if ( F_95 () )
F_67 ( V_311 L_78 ) ;
F_112 () ;
}
void F_117 ( void (* F_118)( void * V_352 ) , void * V_352 )
{
if ( ! F_119 ( V_353 ) )
return;
F_120 () ;
V_354 = F_118 ;
V_355 = V_352 ;
F_121 () ;
}
void F_122 ( void )
{
if ( V_354 )
V_354 ( V_355 ) ;
}
void F_123 ( struct V_122 * V_356 ,
int (* F_124)( struct V_122 * V_356 ) ,
int (* F_125)( struct V_122 * V_356 ) )
{
if ( F_124 || F_125 ) {
V_357 = V_356 ;
V_358 = F_124 ;
V_359 = F_125 ;
return;
}
if ( V_356 != V_357 )
return;
V_358 = V_359 = NULL ;
return;
}
void F_126 ( struct V_122 * V_360 )
{
if ( V_357 == NULL || V_358 == NULL )
return;
if ( V_357 -> V_361 != V_360 -> V_361 )
return;
V_358 ( V_357 ) ;
}
void F_127 ( struct V_122 * V_360 )
{
if ( V_357 == NULL || V_359 == NULL )
return;
if ( V_357 -> V_361 != V_360 -> V_361 )
return;
V_359 ( V_357 ) ;
}
int F_128 ( void )
{
return V_222 ;
}
