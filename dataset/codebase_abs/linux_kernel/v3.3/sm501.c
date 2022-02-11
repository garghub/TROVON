static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
if ( V_2 & V_4 )
V_1 = 288 * V_6 ;
return V_1 / V_7 [ ( V_2 >> V_3 ) & V_5 ] ;
}
static void F_2 ( struct V_8 * V_9 )
{
unsigned long V_10 = F_3 ( V_9 -> V_11 + V_12 ) ;
unsigned long V_13 = F_3 ( V_9 -> V_11 + V_14 ) ;
unsigned long V_15 = F_3 ( V_9 -> V_11 + V_16 ) ;
unsigned long V_17 = F_3 ( V_9 -> V_11 + V_18 ) ;
unsigned long V_19 , V_20 ;
unsigned long V_1 = 0 ;
switch ( V_10 & 0x30 ) {
case 0x00 :
V_1 = 336 * V_6 ;
break;
case 0x10 :
V_1 = 288 * V_6 ;
break;
case 0x20 :
V_1 = 240 * V_6 ;
break;
case 0x30 :
V_1 = 192 * V_6 ;
break;
}
V_19 = ( V_10 & ( 1 << 12 ) ) ? V_1 : 288 * V_6 ;
V_19 /= V_7 [ ( ( V_10 >> 8 ) & 0xf ) ] ;
V_20 = ( V_10 & ( 1 << 20 ) ) ? V_1 : 288 * V_6 ;
V_20 /= V_7 [ ( ( V_10 >> 16 ) & 0xf ) ] ;
F_4 ( V_9 -> V_21 , L_1 ,
V_10 , V_13 , V_15 ) ;
F_4 ( V_9 -> V_21 , L_2 ,
F_5 ( V_1 ) , V_19 , V_20 ) ;
F_4 ( V_9 -> V_21 , L_3 , V_19 , V_20 ) ;
F_4 ( V_9 -> V_21 , L_4
L_5
L_6 ,
( V_17 & 3 ) == 0 ? '*' : '-' ,
F_5 ( F_1 ( V_1 , V_13 , 24 , 1 << 29 , 31 ) ) ,
F_5 ( F_1 ( V_1 , V_13 , 16 , 1 << 20 , 15 ) ) ,
F_5 ( F_1 ( V_1 , V_13 , 8 , 1 << 12 , 15 ) ) ,
F_5 ( F_1 ( V_1 , V_13 , 0 , 1 << 4 , 15 ) ) ) ;
F_4 ( V_9 -> V_21 , L_7
L_5
L_6 ,
( V_17 & 3 ) == 1 ? '*' : '-' ,
F_5 ( F_1 ( V_1 , V_15 , 24 , 1 << 29 , 31 ) ) ,
F_5 ( F_1 ( V_1 , V_15 , 16 , 1 << 20 , 15 ) ) ,
F_5 ( F_1 ( V_1 , V_15 , 8 , 1 << 12 , 15 ) ) ,
F_5 ( F_1 ( V_1 , V_15 , 0 , 1 << 4 , 15 ) ) ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
void T_1 * V_11 = V_9 -> V_11 ;
F_7 ( V_9 -> V_21 , L_8 ,
F_3 ( V_11 + V_22 ) ) ;
F_7 ( V_9 -> V_21 , L_9 ,
F_3 ( V_11 + V_23 ) ) ;
F_7 ( V_9 -> V_21 , L_10 ,
F_3 ( V_11 + V_24 ) ) ;
F_7 ( V_9 -> V_21 , L_11 ,
F_3 ( V_11 + V_25 ) ) ;
F_7 ( V_9 -> V_21 , L_12 ,
F_3 ( V_11 + V_26 ) ) ;
F_7 ( V_9 -> V_21 , L_13 ,
F_3 ( V_11 + V_27 ) ) ;
F_7 ( V_9 -> V_21 , L_14 ,
F_3 ( V_11 + V_12 ) ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
F_7 ( V_9 -> V_21 , L_15 ,
F_3 ( V_9 -> V_11 + V_28 ) ) ;
F_7 ( V_9 -> V_21 , L_16 ,
F_3 ( V_9 -> V_11 + V_29 ) ) ;
F_7 ( V_9 -> V_21 , L_17 ,
F_3 ( V_9 -> V_11 + V_18 ) ) ;
}
static inline void F_8 ( struct V_8 * V_9 ) { }
static inline void F_6 ( struct V_8 * V_9 ) { }
static inline void F_2 ( struct V_8 * V_9 ) { }
static void F_9 ( struct V_8 * V_9 )
{
F_3 ( V_9 -> V_11 ) ;
}
static inline void F_10 ( struct V_8 * V_9 , unsigned int V_30 )
{
if ( V_9 -> V_31 )
F_11 ( V_30 ) ;
else
F_12 ( V_30 ) ;
}
int F_13 ( struct V_32 * V_21 ,
unsigned long V_33 , unsigned long V_34 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_35 ;
unsigned long V_36 ;
unsigned long V_37 ;
F_15 ( & V_9 -> V_38 , V_36 ) ;
V_35 = F_3 ( V_9 -> V_11 + V_23 ) ;
V_37 = ( V_35 & ~ V_34 ) | V_33 ;
if ( V_37 != V_35 ) {
F_16 ( V_37 , V_9 -> V_11 + V_23 ) ;
F_9 ( V_9 ) ;
F_4 ( V_9 -> V_21 , L_18 , V_35 ) ;
}
F_17 ( & V_9 -> V_38 , V_36 ) ;
return V_37 ;
}
unsigned long F_18 ( struct V_32 * V_21 ,
unsigned long V_39 ,
unsigned long V_33 ,
unsigned long V_34 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_40 ;
unsigned long V_36 ;
F_15 ( & V_9 -> V_38 , V_36 ) ;
V_40 = F_3 ( V_9 -> V_11 + V_39 ) ;
V_40 |= V_33 ;
V_40 &= ~ V_34 ;
F_16 ( V_40 , V_9 -> V_11 + V_39 ) ;
F_9 ( V_9 ) ;
F_17 ( & V_9 -> V_38 , V_36 ) ;
return V_40 ;
}
int F_19 ( struct V_32 * V_21 , unsigned int V_41 , unsigned int V_37 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_42 ;
unsigned long V_43 ;
unsigned long clock ;
F_20 ( & V_9 -> V_44 ) ;
V_42 = F_3 ( V_9 -> V_11 + V_18 ) ;
V_43 = F_3 ( V_9 -> V_11 + V_28 ) ;
clock = F_3 ( V_9 -> V_11 + V_29 ) ;
V_42 &= 3 ;
if ( V_41 >= F_21 ( V_9 -> V_45 ) ) {
F_22 ( V_21 , L_19 , V_46 , V_41 ) ;
goto V_47;
}
F_4 ( V_9 -> V_21 , L_20 , V_46 , V_41 ,
V_9 -> V_45 [ V_41 ] , V_37 ) ;
if ( V_37 == 0 && V_9 -> V_45 [ V_41 ] == 0 ) {
F_22 ( V_9 -> V_21 , L_21 , V_41 ) ;
goto V_47;
}
V_9 -> V_45 [ V_41 ] += V_37 ? 1 : - 1 ;
V_37 = V_9 -> V_45 [ V_41 ] ? 1 : 0 ;
if ( V_37 ) {
if ( V_43 & ( 1 << V_41 ) )
goto V_47;
V_43 |= ( 1 << V_41 ) ;
} else {
if ( ! ( V_43 & ( 1 << V_41 ) ) )
goto V_47;
V_43 &= ~ ( 1 << V_41 ) ;
}
switch ( V_42 ) {
case 1 :
F_16 ( V_43 , V_9 -> V_11 + V_48 ) ;
F_16 ( clock , V_9 -> V_11 + V_14 ) ;
V_42 = 0 ;
break;
case 2 :
case 0 :
F_16 ( V_43 , V_9 -> V_11 + V_49 ) ;
F_16 ( clock , V_9 -> V_11 + V_16 ) ;
V_42 = 1 ;
break;
default:
V_43 = - 1 ;
goto V_47;
}
F_16 ( V_42 , V_9 -> V_11 + V_18 ) ;
F_9 ( V_9 ) ;
F_4 ( V_9 -> V_21 , L_22 ,
V_43 , clock , V_42 ) ;
F_10 ( V_9 , 16 ) ;
V_47:
F_23 ( & V_9 -> V_44 ) ;
return V_43 ;
}
static long F_24 ( long V_50 , long V_51 )
{
return ( 2 * V_50 + V_51 ) / ( 2 * V_51 ) ;
}
static int F_25 ( unsigned long V_52 ,
struct V_53 * clock ,
int V_54 ,
unsigned long V_55 ,
long * V_56 )
{
int V_57 = 0 ;
int V_58 ;
int V_59 ;
long V_60 ;
for ( V_58 = 1 ; V_58 <= V_54 ; V_58 += 2 ) {
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_60 = F_24 ( V_55 , V_58 << V_59 ) - V_52 ;
if ( V_60 < 0 )
V_60 = - V_60 ;
if ( V_60 < * V_56 ) {
* V_56 = V_60 ;
clock -> V_55 = V_55 ;
clock -> V_58 = V_58 ;
clock -> V_59 = V_59 ;
V_57 = 1 ;
}
}
}
return V_57 ;
}
static unsigned long F_26 ( unsigned long V_52 ,
struct V_53 * clock ,
int V_54 )
{
unsigned long V_55 ;
unsigned int V_61 , V_62 , V_63 ;
long V_56 = 999999999 ;
for ( V_61 = 2 ; V_61 <= 255 ; V_61 ++ ) {
for ( V_62 = 2 ; V_62 <= 127 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 <= 1 ; V_63 ++ ) {
V_55 = ( 24000000UL * V_61 / V_62 ) >> V_63 ;
if ( F_25 ( V_52 , clock , V_54 ,
V_55 , & V_56 ) ) {
clock -> V_61 = V_61 ;
clock -> V_62 = V_62 ;
clock -> V_63 = V_63 ;
}
}
}
}
return clock -> V_55 / ( clock -> V_58 << clock -> V_59 ) ;
}
static unsigned long F_27 ( unsigned long V_52 ,
struct V_53 * clock ,
int V_54 )
{
unsigned long V_55 ;
long V_56 = 999999999 ;
for ( V_55 = 288000000 ; V_55 <= 336000000 ; V_55 += 48000000 ) {
F_25 ( V_52 , clock , V_54 , V_55 , & V_56 ) ;
}
return clock -> V_55 / ( clock -> V_58 << clock -> V_59 ) ;
}
unsigned long F_28 ( struct V_32 * V_21 ,
int V_64 ,
unsigned long V_65 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_42 = F_3 ( V_9 -> V_11 + V_18 ) ;
unsigned long V_43 = F_3 ( V_9 -> V_11 + V_28 ) ;
unsigned long clock = F_3 ( V_9 -> V_11 + V_29 ) ;
unsigned char V_39 ;
unsigned int V_66 = 0 ;
unsigned long V_67 ;
struct V_53 V_37 ;
switch ( V_64 ) {
case V_68 :
if ( V_9 -> V_69 >= 0xC0 ) {
V_67 = ( F_26 ( 2 * V_65 ,
& V_37 , 5 ) / 2 ) ;
V_39 = V_37 . V_59 & 0x07 ;
if ( V_37 . V_58 == 3 )
V_39 |= 0x08 ;
else if ( V_37 . V_58 == 5 )
V_39 |= 0x10 ;
V_39 |= 0x40 ;
V_66 = 0x20000 | ( V_37 . V_63 << 15 ) | ( V_37 . V_62 << 8 ) | V_37 . V_61 ;
} else {
V_67 = ( F_27 ( 2 * V_65 ,
& V_37 , 5 ) / 2 ) ;
V_39 = V_37 . V_59 & 0x07 ;
if ( V_37 . V_58 == 3 )
V_39 |= 0x08 ;
else if ( V_37 . V_58 == 5 )
V_39 |= 0x10 ;
if ( V_37 . V_55 != 288000000 )
V_39 |= 0x20 ;
}
break;
case V_70 :
V_67 = ( F_27 ( 2 * V_65 , & V_37 , 3 ) / 2 ) ;
V_39 = V_37 . V_59 & 0x07 ;
if ( V_37 . V_58 == 3 )
V_39 |= 0x08 ;
if ( V_37 . V_55 != 288000000 )
V_39 |= 0x10 ;
break;
case V_71 :
case V_72 :
V_67 = F_27 ( V_65 , & V_37 , 3 ) ;
V_39 = V_37 . V_59 & 0x07 ;
if ( V_37 . V_58 == 3 )
V_39 |= 0x08 ;
if ( V_37 . V_55 != 288000000 )
V_39 |= 0x10 ;
break;
default:
return 0 ;
}
F_20 ( & V_9 -> V_44 ) ;
V_42 = F_3 ( V_9 -> V_11 + V_18 ) ;
V_43 = F_3 ( V_9 -> V_11 + V_28 ) ;
clock = F_3 ( V_9 -> V_11 + V_29 ) ;
clock = clock & ~ ( 0xFF << V_64 ) ;
clock |= V_39 << V_64 ;
V_42 &= 3 ;
switch ( V_42 ) {
case 1 :
F_16 ( V_43 , V_9 -> V_11 + V_48 ) ;
F_16 ( clock , V_9 -> V_11 + V_14 ) ;
V_42 = 0 ;
break;
case 2 :
case 0 :
F_16 ( V_43 , V_9 -> V_11 + V_49 ) ;
F_16 ( clock , V_9 -> V_11 + V_16 ) ;
V_42 = 1 ;
break;
default:
F_23 ( & V_9 -> V_44 ) ;
return - 1 ;
}
F_16 ( V_42 , V_9 -> V_11 + V_18 ) ;
if ( V_66 )
F_16 ( V_66 ,
V_9 -> V_11 + V_73 ) ;
F_9 ( V_9 ) ;
F_4 ( V_9 -> V_21 , L_22 ,
V_43 , clock , V_42 ) ;
F_10 ( V_9 , 16 ) ;
F_23 ( & V_9 -> V_44 ) ;
F_2 ( V_9 ) ;
return V_67 ;
}
unsigned long F_29 ( struct V_32 * V_21 ,
int V_64 ,
unsigned long V_65 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_67 ;
struct V_53 V_37 ;
switch ( V_64 ) {
case V_68 :
if ( V_9 -> V_69 >= 0xC0 ) {
V_67 = ( F_26 ( 2 * V_65 ,
& V_37 , 5 ) / 2 ) ;
} else {
V_67 = ( F_27 ( 2 * V_65 ,
& V_37 , 5 ) / 2 ) ;
}
break;
case V_70 :
V_67 = ( F_27 ( 2 * V_65 , & V_37 , 3 ) / 2 ) ;
break;
case V_71 :
case V_72 :
V_67 = F_27 ( V_65 , & V_37 , 3 ) ;
break;
default:
V_67 = 0 ;
}
return V_67 ;
}
static struct V_74 * F_30 ( struct V_75 * V_76 )
{
return F_31 ( V_76 , struct V_74 , V_76 ) ;
}
static void F_32 ( struct V_32 * V_21 )
{
F_33 ( F_30 ( F_34 ( V_21 ) ) ) ;
}
static struct V_75 *
F_35 ( struct V_8 * V_9 , char * V_77 ,
unsigned int V_78 , unsigned int V_79 )
{
struct V_74 * V_80 ;
V_80 = F_36 ( sizeof( struct V_74 ) +
( sizeof( struct V_81 ) * V_78 ) +
V_79 , V_82 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_76 . V_21 . V_83 = F_32 ;
V_80 -> V_76 . V_77 = V_77 ;
V_80 -> V_76 . V_84 = V_9 -> V_85 ;
V_80 -> V_76 . V_21 . V_86 = V_9 -> V_21 ;
if ( V_78 ) {
V_80 -> V_76 . V_81 = (struct V_81 * ) ( V_80 + 1 ) ;
V_80 -> V_76 . V_87 = V_78 ;
}
if ( V_79 )
V_80 -> V_76 . V_21 . V_88 = ( void * ) ( V_80 + 1 ) ;
return & V_80 -> V_76 ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_75 * V_76 )
{
struct V_74 * V_80 = F_30 ( V_76 ) ;
int V_89 ;
int V_57 ;
for ( V_89 = 0 ; V_89 < V_76 -> V_87 ; V_89 ++ ) {
F_38 ( V_90 L_23 ,
V_76 -> V_77 , V_89 , & V_76 -> V_81 [ V_89 ] ) ;
}
V_57 = F_39 ( V_76 ) ;
if ( V_57 >= 0 ) {
F_4 ( V_9 -> V_21 , L_24 , V_76 -> V_77 ) ;
F_40 ( & V_80 -> V_91 , & V_9 -> V_92 ) ;
} else
F_22 ( V_9 -> V_21 , L_25 ,
V_76 -> V_77 , V_57 ) ;
return V_57 ;
}
static void F_41 ( struct V_8 * V_9 ,
struct V_81 * V_93 ,
T_2 V_94 ,
T_2 V_95 )
{
V_93 -> V_96 = V_97 ;
V_93 -> V_86 = V_9 -> V_98 ;
V_93 -> V_99 = V_9 -> V_98 -> V_99 + V_94 ;
V_93 -> V_100 = V_93 -> V_99 + V_95 - 1 ;
}
static void F_42 ( struct V_8 * V_9 ,
struct V_81 * V_93 ,
T_2 * V_94 ,
T_2 V_95 )
{
* V_94 -= V_95 ;
V_93 -> V_96 = V_97 ;
V_93 -> V_86 = V_9 -> V_101 ;
V_93 -> V_99 = V_9 -> V_101 -> V_99 + * V_94 ;
V_93 -> V_100 = V_93 -> V_99 + V_95 - 1 ;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_81 * V_93 )
{
V_93 -> V_96 = V_102 ;
V_93 -> V_86 = NULL ;
V_93 -> V_99 = V_93 -> V_100 = V_9 -> V_103 ;
}
static int F_44 ( struct V_8 * V_9 ,
T_2 * V_104 )
{
struct V_75 * V_76 ;
V_76 = F_35 ( V_9 , L_26 , 3 , 0 ) ;
if ( ! V_76 )
return - V_105 ;
F_41 ( V_9 , & V_76 -> V_81 [ 0 ] , 0x40000 , 0x20000 ) ;
F_42 ( V_9 , & V_76 -> V_81 [ 1 ] , V_104 , 256 * 1024 ) ;
F_43 ( V_9 , & V_76 -> V_81 [ 2 ] ) ;
return F_37 ( V_9 , V_76 ) ;
}
static void F_45 ( struct V_8 * V_9 ,
struct V_106 * V_107 ,
unsigned int V_108 )
{
V_107 -> V_109 = V_9 -> V_11 + V_108 ;
V_107 -> V_110 = V_9 -> V_98 -> V_99 + V_108 ;
V_107 -> V_111 = V_112 ;
V_107 -> V_103 = V_9 -> V_103 ;
V_107 -> V_96 = V_113 | V_114 | V_115 ;
V_107 -> V_116 = 2 ;
V_107 -> V_117 = ( 9600 * 16 ) ;
}
static int F_46 ( struct V_8 * V_9 , int V_92 )
{
struct V_75 * V_76 ;
struct V_106 * V_107 ;
V_76 = F_35 ( V_9 , L_27 , 0 ,
sizeof( struct V_106 ) * 3 ) ;
if ( ! V_76 )
return - V_105 ;
V_107 = V_76 -> V_21 . V_88 ;
if ( V_92 & V_118 ) {
F_45 ( V_9 , V_107 ++ , 0x30000 ) ;
F_19 ( V_9 -> V_21 , V_119 , 1 ) ;
F_18 ( V_9 -> V_21 , V_120 , 1 << 12 , 0 ) ;
F_18 ( V_9 -> V_21 , V_25 , 0x01e0 , 0 ) ;
}
if ( V_92 & V_121 ) {
F_45 ( V_9 , V_107 ++ , 0x30020 ) ;
F_19 ( V_9 -> V_21 , V_122 , 1 ) ;
F_18 ( V_9 -> V_21 , V_120 , 1 << 13 , 0 ) ;
F_18 ( V_9 -> V_21 , V_25 , 0x1e00 , 0 ) ;
}
V_76 -> V_84 = V_123 ;
return F_37 ( V_9 , V_76 ) ;
}
static int F_47 ( struct V_8 * V_9 ,
T_2 * V_104 )
{
struct V_75 * V_76 ;
V_76 = F_35 ( V_9 , L_28 , 4 , 0 ) ;
if ( ! V_76 )
return - V_105 ;
F_41 ( V_9 , & V_76 -> V_81 [ 0 ] , 0x80000 , 0x10000 ) ;
F_41 ( V_9 , & V_76 -> V_81 [ 1 ] , 0x100000 , 0x50000 ) ;
F_42 ( V_9 , & V_76 -> V_81 [ 2 ] , V_104 , * V_104 ) ;
F_43 ( V_9 , & V_76 -> V_81 [ 3 ] ) ;
return F_37 ( V_9 , V_76 ) ;
}
static inline struct V_124 * F_48 ( struct V_125 * V_126 )
{
return F_31 ( V_126 , struct V_124 , V_127 ) ;
}
static inline struct V_8 * F_49 ( struct V_128 * V_127 )
{
return F_31 ( V_127 , struct V_8 , V_127 ) ;
}
static int F_50 ( struct V_125 * V_129 , unsigned V_108 )
{
struct V_124 * V_130 = F_48 ( V_129 ) ;
unsigned long V_131 ;
V_131 = F_3 ( V_130 -> V_132 + V_133 ) ;
V_131 >>= V_108 ;
return V_131 & 1UL ;
}
static void F_51 ( struct V_124 * V_134 ,
unsigned long V_135 )
{
unsigned long V_136 ;
if ( F_3 ( V_134 -> V_137 ) & V_135 ) {
F_7 ( F_49 ( V_134 -> V_138 ) -> V_21 ,
L_29 , V_135 ) ;
V_136 = F_3 ( V_134 -> V_137 ) ;
V_136 &= ~ V_135 ;
F_16 ( V_136 , V_134 -> V_137 ) ;
F_9 ( F_49 ( V_134 -> V_138 ) ) ;
}
}
static void F_52 ( struct V_125 * V_129 , unsigned V_108 , int V_139 )
{
struct V_124 * V_134 = F_48 ( V_129 ) ;
struct V_128 * V_130 = V_134 -> V_138 ;
unsigned long V_135 = 1 << V_108 ;
void T_1 * V_11 = V_134 -> V_132 ;
unsigned long V_36 ;
unsigned long V_2 ;
F_4 ( F_49 ( V_130 ) -> V_21 , L_30 ,
V_46 , V_129 , V_108 ) ;
F_15 ( & V_130 -> V_140 , V_36 ) ;
V_2 = F_3 ( V_11 + V_133 ) & ~ V_135 ;
if ( V_139 )
V_2 |= V_135 ;
F_16 ( V_2 , V_11 ) ;
F_9 ( F_49 ( V_130 ) ) ;
F_51 ( V_134 , V_135 ) ;
F_17 ( & V_130 -> V_140 , V_36 ) ;
}
static int F_53 ( struct V_125 * V_129 , unsigned V_108 )
{
struct V_124 * V_134 = F_48 ( V_129 ) ;
struct V_128 * V_130 = V_134 -> V_138 ;
void T_1 * V_11 = V_134 -> V_132 ;
unsigned long V_135 = 1 << V_108 ;
unsigned long V_36 ;
unsigned long V_141 ;
F_4 ( F_49 ( V_130 ) -> V_21 , L_30 ,
V_46 , V_129 , V_108 ) ;
F_15 ( & V_130 -> V_140 , V_36 ) ;
V_141 = F_3 ( V_11 + V_142 ) ;
F_16 ( V_141 & ~ V_135 , V_11 + V_142 ) ;
F_9 ( F_49 ( V_130 ) ) ;
F_51 ( V_134 , V_135 ) ;
F_17 ( & V_130 -> V_140 , V_36 ) ;
return 0 ;
}
static int F_54 ( struct V_125 * V_129 ,
unsigned V_108 , int V_139 )
{
struct V_124 * V_134 = F_48 ( V_129 ) ;
struct V_128 * V_130 = V_134 -> V_138 ;
unsigned long V_135 = 1 << V_108 ;
void T_1 * V_11 = V_134 -> V_132 ;
unsigned long V_36 ;
unsigned long V_2 ;
unsigned long V_141 ;
F_4 ( F_49 ( V_130 ) -> V_21 , L_31 ,
V_46 , V_129 , V_108 , V_139 ) ;
F_15 ( & V_130 -> V_140 , V_36 ) ;
V_2 = F_3 ( V_11 + V_133 ) ;
if ( V_139 )
V_2 |= V_135 ;
else
V_2 &= ~ V_135 ;
F_16 ( V_2 , V_11 ) ;
V_141 = F_3 ( V_11 + V_142 ) ;
F_16 ( V_141 | V_135 , V_11 + V_142 ) ;
F_9 ( F_49 ( V_130 ) ) ;
F_16 ( V_2 , V_11 + V_133 ) ;
F_9 ( F_49 ( V_130 ) ) ;
F_17 ( & V_130 -> V_140 , V_36 ) ;
return 0 ;
}
static int T_3 F_55 ( struct V_8 * V_9 ,
struct V_128 * V_127 ,
struct V_124 * V_129 )
{
struct V_143 * V_144 = V_9 -> V_145 ;
struct V_125 * V_146 = & V_129 -> V_127 ;
int V_147 = V_144 -> V_148 ;
V_129 -> V_127 = V_149 ;
if ( V_129 == & V_127 -> V_150 ) {
if ( V_147 > 0 )
V_147 += 32 ;
V_129 -> V_132 = V_127 -> V_11 + V_151 ;
V_129 -> V_137 = V_9 -> V_11 + V_25 ;
V_146 -> V_152 = L_32 ;
} else {
V_129 -> V_132 = V_127 -> V_11 + V_133 ;
V_129 -> V_137 = V_9 -> V_11 + V_24 ;
V_146 -> V_152 = L_33 ;
}
V_146 -> V_147 = V_147 ;
V_129 -> V_138 = V_127 ;
return F_56 ( V_146 ) ;
}
static int T_3 F_57 ( struct V_8 * V_9 )
{
struct V_128 * V_127 = & V_9 -> V_127 ;
T_2 V_153 = V_9 -> V_98 -> V_99 + V_154 ;
int V_57 ;
int V_155 ;
F_4 ( V_9 -> V_21 , L_34 ,
( unsigned long long ) V_153 ) ;
F_58 ( & V_127 -> V_140 ) ;
V_127 -> V_156 = F_59 ( V_153 , 0x20 , L_35 ) ;
if ( V_127 -> V_156 == NULL ) {
F_22 ( V_9 -> V_21 , L_36 ) ;
return - V_157 ;
}
V_127 -> V_11 = F_60 ( V_153 , 0x20 ) ;
if ( V_127 -> V_11 == NULL ) {
F_22 ( V_9 -> V_21 , L_37 ) ;
V_57 = - V_157 ;
goto V_158;
}
V_57 = F_55 ( V_9 , V_127 , & V_127 -> V_159 ) ;
if ( V_57 ) {
F_22 ( V_9 -> V_21 , L_38 ) ;
goto V_160;
}
V_57 = F_55 ( V_9 , V_127 , & V_127 -> V_150 ) ;
if ( V_57 ) {
F_22 ( V_9 -> V_21 , L_39 ) ;
goto V_161;
}
V_127 -> V_162 = 1 ;
return 0 ;
V_161:
V_155 = F_61 ( & V_127 -> V_159 . V_127 ) ;
if ( V_155 ) {
F_22 ( V_9 -> V_21 , L_40 ) ;
return V_57 ;
}
V_160:
F_62 ( V_127 -> V_11 ) ;
V_158:
F_63 ( V_127 -> V_156 ) ;
F_33 ( V_127 -> V_156 ) ;
return V_57 ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_128 * V_127 = & V_9 -> V_127 ;
int V_57 ;
if ( ! V_9 -> V_127 . V_162 )
return;
V_57 = F_61 ( & V_127 -> V_159 . V_127 ) ;
if ( V_57 )
F_22 ( V_9 -> V_21 , L_40 ) ;
V_57 = F_61 ( & V_127 -> V_150 . V_127 ) ;
if ( V_57 )
F_22 ( V_9 -> V_21 , L_41 ) ;
F_62 ( V_127 -> V_11 ) ;
F_63 ( V_127 -> V_156 ) ;
F_33 ( V_127 -> V_156 ) ;
}
static inline int F_65 ( struct V_8 * V_9 , unsigned int V_163 )
{
struct V_128 * V_127 = & V_9 -> V_127 ;
int V_147 = ( V_163 < 32 ) ? V_127 -> V_159 . V_127 . V_147 : V_127 -> V_150 . V_127 . V_147 ;
return ( V_163 % 32 ) + V_147 ;
}
static inline int F_66 ( struct V_8 * V_9 )
{
return V_9 -> V_127 . V_162 ;
}
static inline int F_57 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_64 ( struct V_8 * V_9 )
{
}
static inline int F_65 ( struct V_8 * V_9 , unsigned int V_163 )
{
return - 1 ;
}
static inline int F_66 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_67 ( struct V_8 * V_9 ,
struct V_164 * V_165 )
{
struct V_166 * V_167 ;
struct V_75 * V_76 ;
V_76 = F_35 ( V_9 , L_42 , 0 ,
sizeof( struct V_166 ) ) ;
if ( ! V_76 )
return - V_105 ;
V_167 = V_76 -> V_21 . V_88 ;
V_167 -> V_168 = F_65 ( V_9 , V_165 -> V_169 ) ;
V_167 -> V_170 = F_65 ( V_9 , V_165 -> V_171 ) ;
V_167 -> V_172 = V_165 -> V_172 ;
V_167 -> V_173 = V_165 -> V_173 ;
V_76 -> V_84 = V_165 -> V_174 ;
F_7 ( V_9 -> V_21 , L_43 ,
V_165 -> V_174 ,
V_167 -> V_168 , V_165 -> V_169 , V_167 -> V_170 , V_165 -> V_171 ) ;
return F_37 ( V_9 , V_76 ) ;
}
static int F_68 ( struct V_8 * V_9 ,
struct V_143 * V_144 )
{
struct V_164 * V_165 = V_144 -> V_175 ;
int V_176 ;
int V_57 ;
for ( V_176 = 0 ; V_176 < V_144 -> V_177 ; V_176 ++ , V_165 ++ ) {
V_57 = F_67 ( V_9 , V_165 ) ;
if ( V_57 < 0 )
return V_57 ;
}
return 0 ;
}
static T_4 F_69 ( struct V_32 * V_21 ,
struct V_178 * V_179 , char * V_180 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned int V_39 ;
char * V_89 = V_180 ;
int V_57 ;
for ( V_39 = 0x00 ; V_39 < 0x70 ; V_39 += 4 ) {
V_57 = sprintf ( V_89 , L_44 ,
V_39 , F_3 ( V_9 -> V_11 + V_39 ) ) ;
V_89 += V_57 ;
}
return V_89 - V_180 ;
}
static inline void F_70 ( struct V_8 * V_9 ,
unsigned long V_39 ,
struct V_181 * V_182 )
{
unsigned long V_155 ;
V_155 = F_3 ( V_9 -> V_11 + V_39 ) ;
V_155 &= ~ V_182 -> V_5 ;
V_155 |= V_182 -> V_33 ;
F_16 ( V_155 , V_9 -> V_11 + V_39 ) ;
}
static void F_71 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
F_13 ( V_9 -> V_21 ,
V_184 -> V_185 . V_33 ,
V_184 -> V_185 . V_5 ) ;
F_70 ( V_9 , V_12 , & V_184 -> V_186 ) ;
F_70 ( V_9 , V_24 , & V_184 -> V_187 ) ;
F_70 ( V_9 , V_25 , & V_184 -> V_188 ) ;
if ( V_184 -> V_189 ) {
F_7 ( V_9 -> V_21 , L_45 , V_184 -> V_189 ) ;
F_28 ( V_9 -> V_21 , V_72 , V_184 -> V_189 ) ;
}
if ( V_184 -> V_55 ) {
F_7 ( V_9 -> V_21 , L_46 , V_184 -> V_55 ) ;
F_28 ( V_9 -> V_21 , V_71 , V_184 -> V_55 ) ;
}
}
static int F_72 ( struct V_8 * V_9 )
{
unsigned long V_190 = F_3 ( V_9 -> V_11 + V_29 ) ;
unsigned long V_191 = ( V_190 & V_192 ) ;
unsigned long V_193 = ( V_190 & V_194 ) ;
return ( ( V_191 == 0 && V_193 != 0 ) || ( V_191 != 0 && V_193 == 0 ) ) ;
}
static int T_3 F_73 ( struct V_8 * V_9 )
{
struct V_183 * V_195 ;
struct V_143 * V_144 ;
T_2 V_104 ;
unsigned long V_196 ;
unsigned long V_197 ;
int V_57 ;
F_74 ( & V_9 -> V_44 ) ;
F_58 ( & V_9 -> V_38 ) ;
F_75 ( & V_9 -> V_92 ) ;
V_197 = F_3 ( V_9 -> V_11 + V_198 ) ;
if ( ( V_197 & V_199 ) != V_200 ) {
F_22 ( V_9 -> V_21 , L_47 , V_197 ) ;
return - V_201 ;
}
F_16 ( 0 , V_9 -> V_11 + V_120 ) ;
V_196 = F_3 ( V_9 -> V_11 + V_26 ) ;
V_104 = V_202 [ ( V_196 >> 13 ) & 0x7 ] ;
F_7 ( V_9 -> V_21 , L_48 ,
V_9 -> V_11 , V_197 , ( unsigned long ) V_104 >> 20 , V_9 -> V_103 ) ;
V_9 -> V_69 = V_197 & V_203 ;
F_8 ( V_9 ) ;
V_57 = F_76 ( V_9 -> V_21 , & V_204 ) ;
if ( V_57 )
F_22 ( V_9 -> V_21 , L_49 ) ;
F_2 ( V_9 ) ;
V_144 = V_9 -> V_145 ;
V_195 = V_144 ? V_144 -> V_184 : NULL ;
if ( V_195 ) {
F_71 ( V_9 , V_195 ) ;
if ( V_195 -> V_92 & V_205 )
F_44 ( V_9 , & V_104 ) ;
if ( V_195 -> V_92 & ( V_118 | V_121 ) )
F_46 ( V_9 , V_195 -> V_92 ) ;
if ( V_195 -> V_92 & V_206 )
F_57 ( V_9 ) ;
}
if ( V_144 && V_144 -> V_175 != NULL && V_144 -> V_177 > 0 ) {
if ( ! F_66 ( V_9 ) )
F_22 ( V_9 -> V_21 , L_50 ) ;
else
F_68 ( V_9 , V_144 ) ;
}
V_57 = F_72 ( V_9 ) ;
if ( V_57 ) {
F_22 ( V_9 -> V_21 , L_51
L_52 ) ;
return - V_201 ;
}
F_47 ( V_9 , & V_104 ) ;
return 0 ;
}
static int T_3 F_77 ( struct V_75 * V_21 )
{
struct V_8 * V_9 ;
int V_57 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_82 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_53 ) ;
V_57 = - V_105 ;
goto V_207;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_85 = V_21 -> V_84 ;
V_9 -> V_145 = V_21 -> V_21 . V_88 ;
V_57 = F_78 ( V_21 , 0 ) ;
if ( V_57 < 0 ) {
F_22 ( & V_21 -> V_21 , L_54 ) ;
goto V_208;
}
V_9 -> V_103 = V_57 ;
V_9 -> V_98 = F_79 ( V_21 , V_97 , 1 ) ;
V_9 -> V_101 = F_79 ( V_21 , V_97 , 0 ) ;
if ( V_9 -> V_98 == NULL || V_9 -> V_101 == NULL ) {
F_22 ( & V_21 -> V_21 , L_55 ) ;
V_57 = - V_209 ;
goto V_208;
}
V_9 -> V_210 = F_59 ( V_9 -> V_98 -> V_99 ,
0x100 , L_56 ) ;
if ( V_9 -> V_210 == NULL ) {
F_22 ( & V_21 -> V_21 , L_57 ) ;
V_57 = - V_211 ;
goto V_208;
}
F_80 ( V_21 , V_9 ) ;
V_9 -> V_11 = F_60 ( V_9 -> V_98 -> V_99 , F_81 ( V_9 -> V_98 ) ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_58 ) ;
V_57 = - V_212 ;
goto V_213;
}
return F_73 ( V_9 ) ;
V_213:
F_63 ( V_9 -> V_210 ) ;
F_33 ( V_9 -> V_210 ) ;
V_208:
F_33 ( V_9 ) ;
V_207:
return V_57 ;
}
static void F_82 ( struct V_8 * V_9 , int V_214 )
{
struct V_143 * V_215 = V_9 -> V_145 ;
if ( V_215 == NULL )
return;
if ( V_215 -> V_216 ) {
if ( V_215 -> V_216 ( V_9 -> V_21 ) == V_214 ) {
F_4 ( V_9 -> V_21 , L_59 , V_214 ) ;
return;
}
}
if ( V_215 -> V_217 ) {
F_4 ( V_9 -> V_21 , L_60 , V_214 ) ;
V_215 -> V_217 ( V_9 -> V_21 , V_214 ) ;
F_10 ( V_9 , 10 ) ;
}
}
static int F_83 ( struct V_75 * V_76 , T_5 V_218 )
{
struct V_8 * V_9 = F_84 ( V_76 ) ;
V_9 -> V_31 = 1 ;
V_9 -> V_219 = F_3 ( V_9 -> V_11 + V_23 ) ;
F_6 ( V_9 ) ;
if ( V_9 -> V_145 ) {
if ( V_9 -> V_145 -> V_96 & V_220 )
F_82 ( V_9 , 0 ) ;
}
return 0 ;
}
static int F_85 ( struct V_75 * V_76 )
{
struct V_8 * V_9 = F_84 ( V_76 ) ;
F_82 ( V_9 , 1 ) ;
F_6 ( V_9 ) ;
F_8 ( V_9 ) ;
F_2 ( V_9 ) ;
if ( F_3 ( V_9 -> V_11 + V_23 ) != V_9 -> V_219 ) {
F_7 ( V_9 -> V_21 , L_61 ) ;
F_16 ( V_9 -> V_219 , V_9 -> V_11 + V_23 ) ;
if ( V_9 -> V_145 && V_9 -> V_145 -> V_184 ) {
F_71 ( V_9 , V_9 -> V_145 -> V_184 ) ;
}
}
F_6 ( V_9 ) ;
F_2 ( V_9 ) ;
V_9 -> V_31 = 0 ;
return 0 ;
}
static int T_3 F_86 ( struct V_221 * V_21 ,
const struct V_222 * V_84 )
{
struct V_8 * V_9 ;
int V_223 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_82 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_53 ) ;
V_223 = - V_105 ;
goto V_207;
}
V_21 -> V_21 . V_88 = V_9 -> V_145 = & V_224 ;
V_9 -> V_85 = 32 + V_21 -> V_225 ;
F_87 ( V_21 , V_9 ) ;
V_223 = F_88 ( V_21 ) ;
if ( V_223 ) {
F_22 ( & V_21 -> V_21 , L_62 ) ;
goto V_226;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_103 = V_21 -> V_103 ;
#ifdef F_89
V_227 . V_96 |= V_228 ;
#endif
if ( ! ( F_90 ( V_21 , 0 ) & V_97 ) ) {
F_22 ( & V_21 -> V_21 , L_63 ) ;
V_223 = - V_201 ;
goto V_229;
}
if ( ! ( F_90 ( V_21 , 1 ) & V_97 ) ) {
F_22 ( & V_21 -> V_21 , L_64 ) ;
V_223 = - V_201 ;
goto V_229;
}
V_9 -> V_98 = & V_21 -> V_81 [ 1 ] ;
V_9 -> V_101 = & V_21 -> V_81 [ 0 ] ;
V_9 -> V_210 = F_59 ( V_9 -> V_98 -> V_99 ,
0x100 , L_56 ) ;
if ( V_9 -> V_210 == NULL ) {
F_22 ( & V_21 -> V_21 , L_57 ) ;
V_223 = - V_211 ;
goto V_229;
}
V_9 -> V_11 = F_91 ( V_21 , 1 ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_58 ) ;
V_223 = - V_212 ;
goto V_230;
}
F_73 ( V_9 ) ;
return 0 ;
V_230:
F_63 ( V_9 -> V_210 ) ;
F_33 ( V_9 -> V_210 ) ;
V_229:
F_92 ( V_21 ) ;
V_226:
F_87 ( V_21 , NULL ) ;
F_33 ( V_9 ) ;
V_207:
return V_223 ;
}
static void F_93 ( struct V_8 * V_9 ,
struct V_74 * V_80 )
{
F_94 ( & V_80 -> V_91 ) ;
F_95 ( & V_80 -> V_76 ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_74 * V_80 , * V_155 ;
F_97 (smdev, tmp, &sm->devices, list)
F_93 ( V_9 , V_80 ) ;
F_98 ( V_9 -> V_21 , & V_204 ) ;
F_64 ( V_9 ) ;
}
static void T_6 F_99 ( struct V_221 * V_21 )
{
struct V_8 * V_9 = F_100 ( V_21 ) ;
F_96 ( V_9 ) ;
F_62 ( V_9 -> V_11 ) ;
F_63 ( V_9 -> V_210 ) ;
F_33 ( V_9 -> V_210 ) ;
F_87 ( V_21 , NULL ) ;
F_92 ( V_21 ) ;
}
static int F_101 ( struct V_75 * V_21 )
{
struct V_8 * V_9 = F_84 ( V_21 ) ;
F_96 ( V_9 ) ;
F_62 ( V_9 -> V_11 ) ;
F_63 ( V_9 -> V_210 ) ;
F_33 ( V_9 -> V_210 ) ;
return 0 ;
}
static int T_7 F_102 ( void )
{
F_103 ( & V_231 ) ;
return F_104 ( & V_232 ) ;
}
static void T_8 F_105 ( void )
{
F_106 ( & V_231 ) ;
F_107 ( & V_232 ) ;
}
