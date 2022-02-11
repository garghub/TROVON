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
static int F_24 ( unsigned long V_50 ,
struct V_51 * clock ,
int V_52 ,
unsigned long V_53 ,
long * V_54 )
{
int V_55 = 0 ;
int V_56 ;
int V_57 ;
long V_58 ;
for ( V_56 = 1 ; V_56 <= V_52 ; V_56 += 2 ) {
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_58 = F_25 ( V_53 , V_56 << V_57 ) - V_50 ;
if ( V_58 < 0 )
V_58 = - V_58 ;
if ( V_58 < * V_54 ) {
* V_54 = V_58 ;
clock -> V_53 = V_53 ;
clock -> V_56 = V_56 ;
clock -> V_57 = V_57 ;
V_55 = 1 ;
}
}
}
return V_55 ;
}
static unsigned long F_26 ( unsigned long V_50 ,
struct V_51 * clock ,
int V_52 )
{
unsigned long V_53 ;
unsigned int V_59 , V_60 , V_61 ;
long V_54 = 999999999 ;
for ( V_59 = 2 ; V_59 <= 255 ; V_59 ++ ) {
for ( V_60 = 2 ; V_60 <= 127 ; V_60 ++ ) {
for ( V_61 = 0 ; V_61 <= 1 ; V_61 ++ ) {
V_53 = ( 24000000UL * V_59 / V_60 ) >> V_61 ;
if ( F_24 ( V_50 , clock , V_52 ,
V_53 , & V_54 ) ) {
clock -> V_59 = V_59 ;
clock -> V_60 = V_60 ;
clock -> V_61 = V_61 ;
}
}
}
}
return clock -> V_53 / ( clock -> V_56 << clock -> V_57 ) ;
}
static unsigned long F_27 ( unsigned long V_50 ,
struct V_51 * clock ,
int V_52 )
{
unsigned long V_53 ;
long V_54 = 999999999 ;
for ( V_53 = 288000000 ; V_53 <= 336000000 ; V_53 += 48000000 ) {
F_24 ( V_50 , clock , V_52 , V_53 , & V_54 ) ;
}
return clock -> V_53 / ( clock -> V_56 << clock -> V_57 ) ;
}
unsigned long F_28 ( struct V_32 * V_21 ,
int V_62 ,
unsigned long V_63 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_42 = F_3 ( V_9 -> V_11 + V_18 ) ;
unsigned long V_43 = F_3 ( V_9 -> V_11 + V_28 ) ;
unsigned long clock = F_3 ( V_9 -> V_11 + V_29 ) ;
unsigned char V_39 ;
unsigned int V_64 = 0 ;
unsigned long V_65 ;
struct V_51 V_37 ;
switch ( V_62 ) {
case V_66 :
if ( V_9 -> V_67 >= 0xC0 ) {
V_65 = ( F_26 ( 2 * V_63 ,
& V_37 , 5 ) / 2 ) ;
V_39 = V_37 . V_57 & 0x07 ;
if ( V_37 . V_56 == 3 )
V_39 |= 0x08 ;
else if ( V_37 . V_56 == 5 )
V_39 |= 0x10 ;
V_39 |= 0x40 ;
V_64 = 0x20000 | ( V_37 . V_61 << 15 ) | ( V_37 . V_60 << 8 ) | V_37 . V_59 ;
} else {
V_65 = ( F_27 ( 2 * V_63 ,
& V_37 , 5 ) / 2 ) ;
V_39 = V_37 . V_57 & 0x07 ;
if ( V_37 . V_56 == 3 )
V_39 |= 0x08 ;
else if ( V_37 . V_56 == 5 )
V_39 |= 0x10 ;
if ( V_37 . V_53 != 288000000 )
V_39 |= 0x20 ;
}
break;
case V_68 :
V_65 = ( F_27 ( 2 * V_63 , & V_37 , 3 ) / 2 ) ;
V_39 = V_37 . V_57 & 0x07 ;
if ( V_37 . V_56 == 3 )
V_39 |= 0x08 ;
if ( V_37 . V_53 != 288000000 )
V_39 |= 0x10 ;
break;
case V_69 :
case V_70 :
V_65 = F_27 ( V_63 , & V_37 , 3 ) ;
V_39 = V_37 . V_57 & 0x07 ;
if ( V_37 . V_56 == 3 )
V_39 |= 0x08 ;
if ( V_37 . V_53 != 288000000 )
V_39 |= 0x10 ;
break;
default:
return 0 ;
}
F_20 ( & V_9 -> V_44 ) ;
V_42 = F_3 ( V_9 -> V_11 + V_18 ) ;
V_43 = F_3 ( V_9 -> V_11 + V_28 ) ;
clock = F_3 ( V_9 -> V_11 + V_29 ) ;
clock = clock & ~ ( 0xFF << V_62 ) ;
clock |= V_39 << V_62 ;
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
if ( V_64 )
F_16 ( V_64 ,
V_9 -> V_11 + V_71 ) ;
F_9 ( V_9 ) ;
F_4 ( V_9 -> V_21 , L_22 ,
V_43 , clock , V_42 ) ;
F_10 ( V_9 , 16 ) ;
F_23 ( & V_9 -> V_44 ) ;
F_2 ( V_9 ) ;
return V_65 ;
}
unsigned long F_29 ( struct V_32 * V_21 ,
int V_62 ,
unsigned long V_63 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned long V_65 ;
struct V_51 V_37 ;
switch ( V_62 ) {
case V_66 :
if ( V_9 -> V_67 >= 0xC0 ) {
V_65 = ( F_26 ( 2 * V_63 ,
& V_37 , 5 ) / 2 ) ;
} else {
V_65 = ( F_27 ( 2 * V_63 ,
& V_37 , 5 ) / 2 ) ;
}
break;
case V_68 :
V_65 = ( F_27 ( 2 * V_63 , & V_37 , 3 ) / 2 ) ;
break;
case V_69 :
case V_70 :
V_65 = F_27 ( V_63 , & V_37 , 3 ) ;
break;
default:
V_65 = 0 ;
}
return V_65 ;
}
static struct V_72 * F_30 ( struct V_73 * V_74 )
{
return F_31 ( V_74 , struct V_72 , V_74 ) ;
}
static void F_32 ( struct V_32 * V_21 )
{
F_33 ( F_30 ( F_34 ( V_21 ) ) ) ;
}
static struct V_73 *
F_35 ( struct V_8 * V_9 , char * V_75 ,
unsigned int V_76 , unsigned int V_77 )
{
struct V_72 * V_78 ;
V_78 = F_36 ( sizeof( struct V_72 ) +
( sizeof( struct V_79 ) * V_76 ) +
V_77 , V_80 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> V_74 . V_21 . V_81 = F_32 ;
V_78 -> V_74 . V_75 = V_75 ;
V_78 -> V_74 . V_82 = V_9 -> V_83 ;
V_78 -> V_74 . V_21 . V_84 = V_9 -> V_21 ;
if ( V_76 ) {
V_78 -> V_74 . V_79 = (struct V_79 * ) ( V_78 + 1 ) ;
V_78 -> V_74 . V_85 = V_76 ;
}
if ( V_77 )
V_78 -> V_74 . V_21 . V_86 = ( void * ) ( V_78 + 1 ) ;
return & V_78 -> V_74 ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_73 * V_74 )
{
struct V_72 * V_78 = F_30 ( V_74 ) ;
int V_87 ;
int V_55 ;
for ( V_87 = 0 ; V_87 < V_74 -> V_85 ; V_87 ++ ) {
F_38 ( V_88 L_23 ,
V_74 -> V_75 , V_87 , & V_74 -> V_79 [ V_87 ] ) ;
}
V_55 = F_39 ( V_74 ) ;
if ( V_55 >= 0 ) {
F_4 ( V_9 -> V_21 , L_24 , V_74 -> V_75 ) ;
F_40 ( & V_78 -> V_89 , & V_9 -> V_90 ) ;
} else
F_22 ( V_9 -> V_21 , L_25 ,
V_74 -> V_75 , V_55 ) ;
return V_55 ;
}
static void F_41 ( struct V_8 * V_9 ,
struct V_79 * V_91 ,
T_2 V_92 ,
T_2 V_93 )
{
V_91 -> V_94 = V_95 ;
V_91 -> V_84 = V_9 -> V_96 ;
V_91 -> V_97 = V_9 -> V_96 -> V_97 + V_92 ;
V_91 -> V_98 = V_91 -> V_97 + V_93 - 1 ;
}
static void F_42 ( struct V_8 * V_9 ,
struct V_79 * V_91 ,
T_2 * V_92 ,
T_2 V_93 )
{
* V_92 -= V_93 ;
V_91 -> V_94 = V_95 ;
V_91 -> V_84 = V_9 -> V_99 ;
V_91 -> V_97 = V_9 -> V_99 -> V_97 + * V_92 ;
V_91 -> V_98 = V_91 -> V_97 + V_93 - 1 ;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_79 * V_91 )
{
V_91 -> V_94 = V_100 ;
V_91 -> V_84 = NULL ;
V_91 -> V_97 = V_91 -> V_98 = V_9 -> V_101 ;
}
static int F_44 ( struct V_8 * V_9 ,
T_2 * V_102 )
{
struct V_73 * V_74 ;
V_74 = F_35 ( V_9 , L_26 , 3 , 0 ) ;
if ( ! V_74 )
return - V_103 ;
F_41 ( V_9 , & V_74 -> V_79 [ 0 ] , 0x40000 , 0x20000 ) ;
F_42 ( V_9 , & V_74 -> V_79 [ 1 ] , V_102 , 256 * 1024 ) ;
F_43 ( V_9 , & V_74 -> V_79 [ 2 ] ) ;
return F_37 ( V_9 , V_74 ) ;
}
static void F_45 ( struct V_8 * V_9 ,
struct V_104 * V_105 ,
unsigned int V_106 )
{
V_105 -> V_107 = V_9 -> V_11 + V_106 ;
V_105 -> V_108 = V_9 -> V_96 -> V_97 + V_106 ;
V_105 -> V_109 = V_110 ;
V_105 -> V_101 = V_9 -> V_101 ;
V_105 -> V_94 = V_111 | V_112 | V_113 ;
V_105 -> V_114 = 2 ;
V_105 -> V_115 = ( 9600 * 16 ) ;
}
static int F_46 ( struct V_8 * V_9 , int V_90 )
{
struct V_73 * V_74 ;
struct V_104 * V_105 ;
V_74 = F_35 ( V_9 , L_27 , 0 ,
sizeof( struct V_104 ) * 3 ) ;
if ( ! V_74 )
return - V_103 ;
V_105 = V_74 -> V_21 . V_86 ;
if ( V_90 & V_116 ) {
F_45 ( V_9 , V_105 ++ , 0x30000 ) ;
F_19 ( V_9 -> V_21 , V_117 , 1 ) ;
F_18 ( V_9 -> V_21 , V_118 , 1 << 12 , 0 ) ;
F_18 ( V_9 -> V_21 , V_25 , 0x01e0 , 0 ) ;
}
if ( V_90 & V_119 ) {
F_45 ( V_9 , V_105 ++ , 0x30020 ) ;
F_19 ( V_9 -> V_21 , V_120 , 1 ) ;
F_18 ( V_9 -> V_21 , V_118 , 1 << 13 , 0 ) ;
F_18 ( V_9 -> V_21 , V_25 , 0x1e00 , 0 ) ;
}
V_74 -> V_82 = V_121 ;
return F_37 ( V_9 , V_74 ) ;
}
static int F_47 ( struct V_8 * V_9 ,
T_2 * V_102 )
{
struct V_73 * V_74 ;
V_74 = F_35 ( V_9 , L_28 , 4 , 0 ) ;
if ( ! V_74 )
return - V_103 ;
F_41 ( V_9 , & V_74 -> V_79 [ 0 ] , 0x80000 , 0x10000 ) ;
F_41 ( V_9 , & V_74 -> V_79 [ 1 ] , 0x100000 , 0x50000 ) ;
F_42 ( V_9 , & V_74 -> V_79 [ 2 ] , V_102 , * V_102 ) ;
F_43 ( V_9 , & V_74 -> V_79 [ 3 ] ) ;
return F_37 ( V_9 , V_74 ) ;
}
static inline struct V_122 * F_48 ( struct V_123 * V_124 )
{
return F_31 ( V_124 , struct V_122 , V_125 ) ;
}
static inline struct V_8 * F_49 ( struct V_126 * V_125 )
{
return F_31 ( V_125 , struct V_8 , V_125 ) ;
}
static int F_50 ( struct V_123 * V_127 , unsigned V_106 )
{
struct V_122 * V_128 = F_48 ( V_127 ) ;
unsigned long V_129 ;
V_129 = F_3 ( V_128 -> V_130 + V_131 ) ;
V_129 >>= V_106 ;
return V_129 & 1UL ;
}
static void F_51 ( struct V_122 * V_132 ,
unsigned long V_133 )
{
unsigned long V_134 ;
if ( F_3 ( V_132 -> V_135 ) & V_133 ) {
F_7 ( F_49 ( V_132 -> V_136 ) -> V_21 ,
L_29 , V_133 ) ;
V_134 = F_3 ( V_132 -> V_135 ) ;
V_134 &= ~ V_133 ;
F_16 ( V_134 , V_132 -> V_135 ) ;
F_9 ( F_49 ( V_132 -> V_136 ) ) ;
}
}
static void F_52 ( struct V_123 * V_127 , unsigned V_106 , int V_137 )
{
struct V_122 * V_132 = F_48 ( V_127 ) ;
struct V_126 * V_128 = V_132 -> V_136 ;
unsigned long V_133 = 1 << V_106 ;
void T_1 * V_11 = V_132 -> V_130 ;
unsigned long V_36 ;
unsigned long V_2 ;
F_4 ( F_49 ( V_128 ) -> V_21 , L_30 ,
V_46 , V_127 , V_106 ) ;
F_15 ( & V_128 -> V_138 , V_36 ) ;
V_2 = F_3 ( V_11 + V_131 ) & ~ V_133 ;
if ( V_137 )
V_2 |= V_133 ;
F_16 ( V_2 , V_11 ) ;
F_9 ( F_49 ( V_128 ) ) ;
F_51 ( V_132 , V_133 ) ;
F_17 ( & V_128 -> V_138 , V_36 ) ;
}
static int F_53 ( struct V_123 * V_127 , unsigned V_106 )
{
struct V_122 * V_132 = F_48 ( V_127 ) ;
struct V_126 * V_128 = V_132 -> V_136 ;
void T_1 * V_11 = V_132 -> V_130 ;
unsigned long V_133 = 1 << V_106 ;
unsigned long V_36 ;
unsigned long V_139 ;
F_4 ( F_49 ( V_128 ) -> V_21 , L_30 ,
V_46 , V_127 , V_106 ) ;
F_15 ( & V_128 -> V_138 , V_36 ) ;
V_139 = F_3 ( V_11 + V_140 ) ;
F_16 ( V_139 & ~ V_133 , V_11 + V_140 ) ;
F_9 ( F_49 ( V_128 ) ) ;
F_51 ( V_132 , V_133 ) ;
F_17 ( & V_128 -> V_138 , V_36 ) ;
return 0 ;
}
static int F_54 ( struct V_123 * V_127 ,
unsigned V_106 , int V_137 )
{
struct V_122 * V_132 = F_48 ( V_127 ) ;
struct V_126 * V_128 = V_132 -> V_136 ;
unsigned long V_133 = 1 << V_106 ;
void T_1 * V_11 = V_132 -> V_130 ;
unsigned long V_36 ;
unsigned long V_2 ;
unsigned long V_139 ;
F_4 ( F_49 ( V_128 ) -> V_21 , L_31 ,
V_46 , V_127 , V_106 , V_137 ) ;
F_15 ( & V_128 -> V_138 , V_36 ) ;
V_2 = F_3 ( V_11 + V_131 ) ;
if ( V_137 )
V_2 |= V_133 ;
else
V_2 &= ~ V_133 ;
F_16 ( V_2 , V_11 ) ;
V_139 = F_3 ( V_11 + V_140 ) ;
F_16 ( V_139 | V_133 , V_11 + V_140 ) ;
F_9 ( F_49 ( V_128 ) ) ;
F_16 ( V_2 , V_11 + V_131 ) ;
F_9 ( F_49 ( V_128 ) ) ;
F_17 ( & V_128 -> V_138 , V_36 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_126 * V_125 ,
struct V_122 * V_127 )
{
struct V_141 * V_142 = V_9 -> V_143 ;
struct V_123 * V_144 = & V_127 -> V_125 ;
int V_145 = V_142 -> V_146 ;
V_127 -> V_125 = V_147 ;
if ( V_127 == & V_125 -> V_148 ) {
if ( V_145 > 0 )
V_145 += 32 ;
V_127 -> V_130 = V_125 -> V_11 + V_149 ;
V_127 -> V_135 = V_9 -> V_11 + V_25 ;
V_144 -> V_150 = L_32 ;
} else {
V_127 -> V_130 = V_125 -> V_11 + V_131 ;
V_127 -> V_135 = V_9 -> V_11 + V_24 ;
V_144 -> V_150 = L_33 ;
}
V_144 -> V_145 = V_145 ;
V_127 -> V_136 = V_125 ;
return F_56 ( V_144 ) ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_126 * V_125 = & V_9 -> V_125 ;
T_2 V_151 = V_9 -> V_96 -> V_97 + V_152 ;
int V_55 ;
int V_153 ;
F_4 ( V_9 -> V_21 , L_34 ,
( unsigned long long ) V_151 ) ;
F_58 ( & V_125 -> V_138 ) ;
V_125 -> V_154 = F_59 ( V_151 , 0x20 , L_35 ) ;
if ( V_125 -> V_154 == NULL ) {
F_22 ( V_9 -> V_21 , L_36 ) ;
return - V_155 ;
}
V_125 -> V_11 = F_60 ( V_151 , 0x20 ) ;
if ( V_125 -> V_11 == NULL ) {
F_22 ( V_9 -> V_21 , L_37 ) ;
V_55 = - V_155 ;
goto V_156;
}
V_55 = F_55 ( V_9 , V_125 , & V_125 -> V_157 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_38 ) ;
goto V_158;
}
V_55 = F_55 ( V_9 , V_125 , & V_125 -> V_148 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_39 ) ;
goto V_159;
}
V_125 -> V_160 = 1 ;
return 0 ;
V_159:
V_153 = F_61 ( & V_125 -> V_157 . V_125 ) ;
if ( V_153 ) {
F_22 ( V_9 -> V_21 , L_40 ) ;
return V_55 ;
}
V_158:
F_62 ( V_125 -> V_11 ) ;
V_156:
F_63 ( V_125 -> V_154 ) ;
F_33 ( V_125 -> V_154 ) ;
return V_55 ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_126 * V_125 = & V_9 -> V_125 ;
int V_55 ;
if ( ! V_9 -> V_125 . V_160 )
return;
V_55 = F_61 ( & V_125 -> V_157 . V_125 ) ;
if ( V_55 )
F_22 ( V_9 -> V_21 , L_40 ) ;
V_55 = F_61 ( & V_125 -> V_148 . V_125 ) ;
if ( V_55 )
F_22 ( V_9 -> V_21 , L_41 ) ;
F_62 ( V_125 -> V_11 ) ;
F_63 ( V_125 -> V_154 ) ;
F_33 ( V_125 -> V_154 ) ;
}
static inline int F_65 ( struct V_8 * V_9 , unsigned int V_161 )
{
struct V_126 * V_125 = & V_9 -> V_125 ;
int V_145 = ( V_161 < 32 ) ? V_125 -> V_157 . V_125 . V_145 : V_125 -> V_148 . V_125 . V_145 ;
return ( V_161 % 32 ) + V_145 ;
}
static inline int F_66 ( struct V_8 * V_9 )
{
return V_9 -> V_125 . V_160 ;
}
static inline int F_57 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_64 ( struct V_8 * V_9 )
{
}
static inline int F_65 ( struct V_8 * V_9 , unsigned int V_161 )
{
return - 1 ;
}
static inline int F_66 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_67 ( struct V_8 * V_9 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_73 * V_74 ;
V_74 = F_35 ( V_9 , L_42 , 0 ,
sizeof( struct V_164 ) ) ;
if ( ! V_74 )
return - V_103 ;
V_165 = V_74 -> V_21 . V_86 ;
V_165 -> V_166 = F_65 ( V_9 , V_163 -> V_167 ) ;
V_165 -> V_168 = F_65 ( V_9 , V_163 -> V_169 ) ;
V_165 -> V_170 = V_163 -> V_170 ;
V_165 -> V_171 = V_163 -> V_171 ;
V_74 -> V_82 = V_163 -> V_172 ;
F_7 ( V_9 -> V_21 , L_43 ,
V_163 -> V_172 ,
V_165 -> V_166 , V_163 -> V_167 , V_165 -> V_168 , V_163 -> V_169 ) ;
return F_37 ( V_9 , V_74 ) ;
}
static int F_68 ( struct V_8 * V_9 ,
struct V_141 * V_142 )
{
struct V_162 * V_163 = V_142 -> V_173 ;
int V_174 ;
int V_55 ;
for ( V_174 = 0 ; V_174 < V_142 -> V_175 ; V_174 ++ , V_163 ++ ) {
V_55 = F_67 ( V_9 , V_163 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static T_3 F_69 ( struct V_32 * V_21 ,
struct V_176 * V_177 , char * V_178 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned int V_39 ;
char * V_87 = V_178 ;
int V_55 ;
for ( V_39 = 0x00 ; V_39 < 0x70 ; V_39 += 4 ) {
V_55 = sprintf ( V_87 , L_44 ,
V_39 , F_3 ( V_9 -> V_11 + V_39 ) ) ;
V_87 += V_55 ;
}
return V_87 - V_178 ;
}
static inline void F_70 ( struct V_8 * V_9 ,
unsigned long V_39 ,
struct V_179 * V_180 )
{
unsigned long V_153 ;
V_153 = F_3 ( V_9 -> V_11 + V_39 ) ;
V_153 &= ~ V_180 -> V_5 ;
V_153 |= V_180 -> V_33 ;
F_16 ( V_153 , V_9 -> V_11 + V_39 ) ;
}
static void F_71 ( struct V_8 * V_9 ,
struct V_181 * V_182 )
{
F_13 ( V_9 -> V_21 ,
V_182 -> V_183 . V_33 ,
V_182 -> V_183 . V_5 ) ;
F_70 ( V_9 , V_12 , & V_182 -> V_184 ) ;
F_70 ( V_9 , V_24 , & V_182 -> V_185 ) ;
F_70 ( V_9 , V_25 , & V_182 -> V_186 ) ;
if ( V_182 -> V_187 ) {
F_7 ( V_9 -> V_21 , L_45 , V_182 -> V_187 ) ;
F_28 ( V_9 -> V_21 , V_70 , V_182 -> V_187 ) ;
}
if ( V_182 -> V_53 ) {
F_7 ( V_9 -> V_21 , L_46 , V_182 -> V_53 ) ;
F_28 ( V_9 -> V_21 , V_69 , V_182 -> V_53 ) ;
}
}
static int F_72 ( struct V_8 * V_9 )
{
unsigned long V_188 = F_3 ( V_9 -> V_11 + V_29 ) ;
unsigned long V_189 = ( V_188 & V_190 ) ;
unsigned long V_191 = ( V_188 & V_192 ) ;
return ( ( V_189 == 0 && V_191 != 0 ) || ( V_189 != 0 && V_191 == 0 ) ) ;
}
static int F_73 ( struct V_8 * V_9 )
{
struct V_181 * V_193 ;
struct V_141 * V_142 ;
T_2 V_102 ;
unsigned long V_194 ;
unsigned long V_195 ;
int V_55 ;
F_74 ( & V_9 -> V_44 ) ;
F_58 ( & V_9 -> V_38 ) ;
F_75 ( & V_9 -> V_90 ) ;
V_195 = F_3 ( V_9 -> V_11 + V_196 ) ;
if ( ( V_195 & V_197 ) != V_198 ) {
F_22 ( V_9 -> V_21 , L_47 , V_195 ) ;
return - V_199 ;
}
F_16 ( 0 , V_9 -> V_11 + V_118 ) ;
V_194 = F_3 ( V_9 -> V_11 + V_26 ) ;
V_102 = V_200 [ ( V_194 >> 13 ) & 0x7 ] ;
F_7 ( V_9 -> V_21 , L_48 ,
V_9 -> V_11 , V_195 , ( unsigned long ) V_102 >> 20 , V_9 -> V_101 ) ;
V_9 -> V_67 = V_195 & V_201 ;
F_8 ( V_9 ) ;
V_55 = F_76 ( V_9 -> V_21 , & V_202 ) ;
if ( V_55 )
F_22 ( V_9 -> V_21 , L_49 ) ;
F_2 ( V_9 ) ;
V_142 = V_9 -> V_143 ;
V_193 = V_142 ? V_142 -> V_182 : NULL ;
if ( V_193 ) {
F_71 ( V_9 , V_193 ) ;
if ( V_193 -> V_90 & V_203 )
F_44 ( V_9 , & V_102 ) ;
if ( V_193 -> V_90 & ( V_116 | V_119 ) )
F_46 ( V_9 , V_193 -> V_90 ) ;
if ( V_193 -> V_90 & V_204 )
F_57 ( V_9 ) ;
}
if ( V_142 && V_142 -> V_173 != NULL && V_142 -> V_175 > 0 ) {
if ( ! F_66 ( V_9 ) )
F_22 ( V_9 -> V_21 , L_50 ) ;
else
F_68 ( V_9 , V_142 ) ;
}
V_55 = F_72 ( V_9 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_51
L_52 ) ;
return - V_199 ;
}
F_47 ( V_9 , & V_102 ) ;
return 0 ;
}
static int F_77 ( struct V_73 * V_21 )
{
struct V_8 * V_9 ;
int V_55 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_80 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_53 ) ;
V_55 = - V_103 ;
goto V_205;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_83 = V_21 -> V_82 ;
V_9 -> V_143 = V_21 -> V_21 . V_86 ;
V_55 = F_78 ( V_21 , 0 ) ;
if ( V_55 < 0 ) {
F_22 ( & V_21 -> V_21 , L_54 ) ;
goto V_206;
}
V_9 -> V_101 = V_55 ;
V_9 -> V_96 = F_79 ( V_21 , V_95 , 1 ) ;
V_9 -> V_99 = F_79 ( V_21 , V_95 , 0 ) ;
if ( V_9 -> V_96 == NULL || V_9 -> V_99 == NULL ) {
F_22 ( & V_21 -> V_21 , L_55 ) ;
V_55 = - V_207 ;
goto V_206;
}
V_9 -> V_208 = F_59 ( V_9 -> V_96 -> V_97 ,
0x100 , L_56 ) ;
if ( V_9 -> V_208 == NULL ) {
F_22 ( & V_21 -> V_21 , L_57 ) ;
V_55 = - V_209 ;
goto V_206;
}
F_80 ( V_21 , V_9 ) ;
V_9 -> V_11 = F_60 ( V_9 -> V_96 -> V_97 , F_81 ( V_9 -> V_96 ) ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_58 ) ;
V_55 = - V_210 ;
goto V_211;
}
return F_73 ( V_9 ) ;
V_211:
F_63 ( V_9 -> V_208 ) ;
F_33 ( V_9 -> V_208 ) ;
V_206:
F_33 ( V_9 ) ;
V_205:
return V_55 ;
}
static void F_82 ( struct V_8 * V_9 , int V_212 )
{
struct V_141 * V_213 = V_9 -> V_143 ;
if ( V_213 == NULL )
return;
if ( V_213 -> V_214 ) {
if ( V_213 -> V_214 ( V_9 -> V_21 ) == V_212 ) {
F_4 ( V_9 -> V_21 , L_59 , V_212 ) ;
return;
}
}
if ( V_213 -> V_215 ) {
F_4 ( V_9 -> V_21 , L_60 , V_212 ) ;
V_213 -> V_215 ( V_9 -> V_21 , V_212 ) ;
F_10 ( V_9 , 10 ) ;
}
}
static int F_83 ( struct V_73 * V_74 , T_4 V_216 )
{
struct V_8 * V_9 = F_84 ( V_74 ) ;
V_9 -> V_31 = 1 ;
V_9 -> V_217 = F_3 ( V_9 -> V_11 + V_23 ) ;
F_6 ( V_9 ) ;
if ( V_9 -> V_143 ) {
if ( V_9 -> V_143 -> V_94 & V_218 )
F_82 ( V_9 , 0 ) ;
}
return 0 ;
}
static int F_85 ( struct V_73 * V_74 )
{
struct V_8 * V_9 = F_84 ( V_74 ) ;
F_82 ( V_9 , 1 ) ;
F_6 ( V_9 ) ;
F_8 ( V_9 ) ;
F_2 ( V_9 ) ;
if ( F_3 ( V_9 -> V_11 + V_23 ) != V_9 -> V_217 ) {
F_7 ( V_9 -> V_21 , L_61 ) ;
F_16 ( V_9 -> V_217 , V_9 -> V_11 + V_23 ) ;
if ( V_9 -> V_143 && V_9 -> V_143 -> V_182 ) {
F_71 ( V_9 , V_9 -> V_143 -> V_182 ) ;
}
}
F_6 ( V_9 ) ;
F_2 ( V_9 ) ;
V_9 -> V_31 = 0 ;
return 0 ;
}
static int F_86 ( struct V_219 * V_21 ,
const struct V_220 * V_82 )
{
struct V_8 * V_9 ;
int V_221 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_80 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_53 ) ;
V_221 = - V_103 ;
goto V_205;
}
V_21 -> V_21 . V_86 = V_9 -> V_143 = & V_222 ;
V_9 -> V_83 = 32 + V_21 -> V_223 ;
F_87 ( V_21 , V_9 ) ;
V_221 = F_88 ( V_21 ) ;
if ( V_221 ) {
F_22 ( & V_21 -> V_21 , L_62 ) ;
goto V_224;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_101 = V_21 -> V_101 ;
#ifdef F_89
V_225 . V_94 |= V_226 ;
#endif
if ( ! ( F_90 ( V_21 , 0 ) & V_95 ) ) {
F_22 ( & V_21 -> V_21 , L_63 ) ;
V_221 = - V_199 ;
goto V_227;
}
if ( ! ( F_90 ( V_21 , 1 ) & V_95 ) ) {
F_22 ( & V_21 -> V_21 , L_64 ) ;
V_221 = - V_199 ;
goto V_227;
}
V_9 -> V_96 = & V_21 -> V_79 [ 1 ] ;
V_9 -> V_99 = & V_21 -> V_79 [ 0 ] ;
V_9 -> V_208 = F_59 ( V_9 -> V_96 -> V_97 ,
0x100 , L_56 ) ;
if ( V_9 -> V_208 == NULL ) {
F_22 ( & V_21 -> V_21 , L_57 ) ;
V_221 = - V_209 ;
goto V_227;
}
V_9 -> V_11 = F_91 ( V_21 , 1 ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_58 ) ;
V_221 = - V_210 ;
goto V_228;
}
F_73 ( V_9 ) ;
return 0 ;
V_228:
F_63 ( V_9 -> V_208 ) ;
F_33 ( V_9 -> V_208 ) ;
V_227:
F_92 ( V_21 ) ;
V_224:
F_87 ( V_21 , NULL ) ;
F_33 ( V_9 ) ;
V_205:
return V_221 ;
}
static void F_93 ( struct V_8 * V_9 ,
struct V_72 * V_78 )
{
F_94 ( & V_78 -> V_89 ) ;
F_95 ( & V_78 -> V_74 ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_72 * V_78 , * V_153 ;
F_97 (smdev, tmp, &sm->devices, list)
F_93 ( V_9 , V_78 ) ;
F_98 ( V_9 -> V_21 , & V_202 ) ;
F_64 ( V_9 ) ;
}
static void F_99 ( struct V_219 * V_21 )
{
struct V_8 * V_9 = F_100 ( V_21 ) ;
F_96 ( V_9 ) ;
F_62 ( V_9 -> V_11 ) ;
F_63 ( V_9 -> V_208 ) ;
F_33 ( V_9 -> V_208 ) ;
F_87 ( V_21 , NULL ) ;
F_92 ( V_21 ) ;
}
static int F_101 ( struct V_73 * V_21 )
{
struct V_8 * V_9 = F_84 ( V_21 ) ;
F_96 ( V_9 ) ;
F_62 ( V_9 -> V_11 ) ;
F_63 ( V_9 -> V_208 ) ;
F_33 ( V_9 -> V_208 ) ;
return 0 ;
}
static int T_5 F_102 ( void )
{
F_103 ( & V_229 ) ;
return F_104 ( & V_230 ) ;
}
static void T_6 F_105 ( void )
{
F_106 ( & V_229 ) ;
F_107 ( & V_230 ) ;
}
