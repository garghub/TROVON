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
unsigned int V_64 = 0 ;
unsigned long V_65 ;
T_2 V_39 ;
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
T_3 V_92 ,
T_3 V_93 )
{
V_91 -> V_94 = V_95 ;
V_91 -> V_84 = V_9 -> V_96 ;
V_91 -> V_97 = V_9 -> V_96 -> V_97 + V_92 ;
V_91 -> V_98 = V_91 -> V_97 + V_93 - 1 ;
}
static void F_42 ( struct V_8 * V_9 ,
struct V_79 * V_91 ,
T_3 * V_92 ,
T_3 V_93 )
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
T_3 * V_102 )
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
V_105 = F_47 ( & V_74 -> V_21 ) ;
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
static int F_48 ( struct V_8 * V_9 ,
T_3 * V_102 )
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
static inline struct V_8 * F_49 ( struct V_122 * V_123 )
{
return F_31 ( V_123 , struct V_8 , V_123 ) ;
}
static int F_50 ( struct V_124 * V_125 , unsigned V_106 )
{
struct V_126 * V_127 = F_51 ( V_125 ) ;
unsigned long V_128 ;
V_128 = F_3 ( V_127 -> V_129 + V_130 ) ;
V_128 >>= V_106 ;
return V_128 & 1UL ;
}
static void F_52 ( struct V_126 * V_131 ,
unsigned long V_132 )
{
unsigned long V_133 ;
if ( F_3 ( V_131 -> V_134 ) & V_132 ) {
F_7 ( F_49 ( V_131 -> V_135 ) -> V_21 ,
L_29 , V_132 ) ;
V_133 = F_3 ( V_131 -> V_134 ) ;
V_133 &= ~ V_132 ;
F_16 ( V_133 , V_131 -> V_134 ) ;
F_9 ( F_49 ( V_131 -> V_135 ) ) ;
}
}
static void F_53 ( struct V_124 * V_125 , unsigned V_106 , int V_136 )
{
struct V_126 * V_131 = F_51 ( V_125 ) ;
struct V_122 * V_127 = V_131 -> V_135 ;
unsigned long V_132 = 1 << V_106 ;
void T_1 * V_11 = V_131 -> V_129 ;
unsigned long V_36 ;
unsigned long V_2 ;
F_4 ( F_49 ( V_127 ) -> V_21 , L_30 ,
V_46 , V_125 , V_106 ) ;
F_15 ( & V_127 -> V_137 , V_36 ) ;
V_2 = F_3 ( V_11 + V_130 ) & ~ V_132 ;
if ( V_136 )
V_2 |= V_132 ;
F_16 ( V_2 , V_11 ) ;
F_9 ( F_49 ( V_127 ) ) ;
F_52 ( V_131 , V_132 ) ;
F_17 ( & V_127 -> V_137 , V_36 ) ;
}
static int F_54 ( struct V_124 * V_125 , unsigned V_106 )
{
struct V_126 * V_131 = F_51 ( V_125 ) ;
struct V_122 * V_127 = V_131 -> V_135 ;
void T_1 * V_11 = V_131 -> V_129 ;
unsigned long V_132 = 1 << V_106 ;
unsigned long V_36 ;
unsigned long V_138 ;
F_4 ( F_49 ( V_127 ) -> V_21 , L_30 ,
V_46 , V_125 , V_106 ) ;
F_15 ( & V_127 -> V_137 , V_36 ) ;
V_138 = F_3 ( V_11 + V_139 ) ;
F_16 ( V_138 & ~ V_132 , V_11 + V_139 ) ;
F_9 ( F_49 ( V_127 ) ) ;
F_52 ( V_131 , V_132 ) ;
F_17 ( & V_127 -> V_137 , V_36 ) ;
return 0 ;
}
static int F_55 ( struct V_124 * V_125 ,
unsigned V_106 , int V_136 )
{
struct V_126 * V_131 = F_51 ( V_125 ) ;
struct V_122 * V_127 = V_131 -> V_135 ;
unsigned long V_132 = 1 << V_106 ;
void T_1 * V_11 = V_131 -> V_129 ;
unsigned long V_36 ;
unsigned long V_2 ;
unsigned long V_138 ;
F_4 ( F_49 ( V_127 ) -> V_21 , L_31 ,
V_46 , V_125 , V_106 , V_136 ) ;
F_15 ( & V_127 -> V_137 , V_36 ) ;
V_2 = F_3 ( V_11 + V_130 ) ;
if ( V_136 )
V_2 |= V_132 ;
else
V_2 &= ~ V_132 ;
F_16 ( V_2 , V_11 ) ;
V_138 = F_3 ( V_11 + V_139 ) ;
F_16 ( V_138 | V_132 , V_11 + V_139 ) ;
F_9 ( F_49 ( V_127 ) ) ;
F_16 ( V_2 , V_11 + V_130 ) ;
F_9 ( F_49 ( V_127 ) ) ;
F_17 ( & V_127 -> V_137 , V_36 ) ;
return 0 ;
}
static int F_56 ( struct V_8 * V_9 ,
struct V_122 * V_123 ,
struct V_126 * V_125 )
{
struct V_140 * V_141 = V_9 -> V_142 ;
struct V_124 * V_143 = & V_125 -> V_123 ;
int V_144 = V_141 -> V_145 ;
V_125 -> V_123 = V_146 ;
if ( V_125 == & V_123 -> V_147 ) {
if ( V_144 > 0 )
V_144 += 32 ;
V_125 -> V_129 = V_123 -> V_11 + V_148 ;
V_125 -> V_134 = V_9 -> V_11 + V_25 ;
V_143 -> V_149 = L_32 ;
} else {
V_125 -> V_129 = V_123 -> V_11 + V_130 ;
V_125 -> V_134 = V_9 -> V_11 + V_24 ;
V_143 -> V_149 = L_33 ;
}
V_143 -> V_144 = V_144 ;
V_125 -> V_135 = V_123 ;
return F_57 ( V_143 , V_125 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_122 * V_123 = & V_9 -> V_123 ;
T_3 V_150 = V_9 -> V_96 -> V_97 + V_151 ;
int V_55 ;
F_4 ( V_9 -> V_21 , L_34 ,
( unsigned long long ) V_150 ) ;
F_59 ( & V_123 -> V_137 ) ;
V_123 -> V_152 = F_60 ( V_150 , 0x20 , L_35 ) ;
if ( V_123 -> V_152 == NULL ) {
F_22 ( V_9 -> V_21 , L_36 ) ;
return - V_153 ;
}
V_123 -> V_11 = F_61 ( V_150 , 0x20 ) ;
if ( V_123 -> V_11 == NULL ) {
F_22 ( V_9 -> V_21 , L_37 ) ;
V_55 = - V_153 ;
goto V_154;
}
V_55 = F_56 ( V_9 , V_123 , & V_123 -> V_155 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_38 ) ;
goto V_156;
}
V_55 = F_56 ( V_9 , V_123 , & V_123 -> V_147 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_39 ) ;
goto V_157;
}
V_123 -> V_158 = 1 ;
return 0 ;
V_157:
F_62 ( & V_123 -> V_155 . V_123 ) ;
V_156:
F_63 ( V_123 -> V_11 ) ;
V_154:
F_64 ( V_123 -> V_152 ) ;
F_33 ( V_123 -> V_152 ) ;
return V_55 ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_122 * V_123 = & V_9 -> V_123 ;
if ( ! V_9 -> V_123 . V_158 )
return;
F_62 ( & V_123 -> V_155 . V_123 ) ;
F_62 ( & V_123 -> V_147 . V_123 ) ;
F_63 ( V_123 -> V_11 ) ;
F_64 ( V_123 -> V_152 ) ;
F_33 ( V_123 -> V_152 ) ;
}
static inline int F_66 ( struct V_8 * V_9 , unsigned int V_159 )
{
struct V_122 * V_123 = & V_9 -> V_123 ;
int V_144 = ( V_159 < 32 ) ? V_123 -> V_155 . V_123 . V_144 : V_123 -> V_147 . V_123 . V_144 ;
return ( V_159 % 32 ) + V_144 ;
}
static inline int F_67 ( struct V_8 * V_9 )
{
return V_9 -> V_123 . V_158 ;
}
static inline int F_58 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_65 ( struct V_8 * V_9 )
{
}
static inline int F_66 ( struct V_8 * V_9 , unsigned int V_159 )
{
return - 1 ;
}
static inline int F_67 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_68 ( struct V_8 * V_9 ,
struct V_160 * V_161 )
{
struct V_162 * V_163 ;
struct V_73 * V_74 ;
V_74 = F_35 ( V_9 , L_40 , 0 ,
sizeof( struct V_162 ) ) ;
if ( ! V_74 )
return - V_103 ;
V_163 = F_47 ( & V_74 -> V_21 ) ;
V_163 -> V_164 = F_66 ( V_9 , V_161 -> V_165 ) ;
V_163 -> V_166 = F_66 ( V_9 , V_161 -> V_167 ) ;
V_163 -> V_168 = V_161 -> V_168 ;
V_163 -> V_169 = V_161 -> V_169 ;
V_74 -> V_82 = V_161 -> V_170 ;
F_7 ( V_9 -> V_21 , L_41 ,
V_161 -> V_170 ,
V_163 -> V_164 , V_161 -> V_165 , V_163 -> V_166 , V_161 -> V_167 ) ;
return F_37 ( V_9 , V_74 ) ;
}
static int F_69 ( struct V_8 * V_9 ,
struct V_140 * V_141 )
{
struct V_160 * V_161 = V_141 -> V_171 ;
int V_172 ;
int V_55 ;
for ( V_172 = 0 ; V_172 < V_141 -> V_173 ; V_172 ++ , V_161 ++ ) {
V_55 = F_68 ( V_9 , V_161 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static T_4 F_70 ( struct V_32 * V_21 ,
struct V_174 * V_175 , char * V_176 )
{
struct V_8 * V_9 = F_14 ( V_21 ) ;
unsigned int V_39 ;
char * V_87 = V_176 ;
int V_55 ;
for ( V_39 = 0x00 ; V_39 < 0x70 ; V_39 += 4 ) {
V_55 = sprintf ( V_87 , L_42 ,
V_39 , F_3 ( V_9 -> V_11 + V_39 ) ) ;
V_87 += V_55 ;
}
return V_87 - V_176 ;
}
static inline void F_71 ( struct V_8 * V_9 ,
unsigned long V_39 ,
struct V_177 * V_178 )
{
unsigned long V_179 ;
V_179 = F_3 ( V_9 -> V_11 + V_39 ) ;
V_179 &= ~ V_178 -> V_5 ;
V_179 |= V_178 -> V_33 ;
F_16 ( V_179 , V_9 -> V_11 + V_39 ) ;
}
static void F_72 ( struct V_8 * V_9 ,
struct V_180 * V_181 )
{
F_13 ( V_9 -> V_21 ,
V_181 -> V_182 . V_33 ,
V_181 -> V_182 . V_5 ) ;
F_71 ( V_9 , V_12 , & V_181 -> V_183 ) ;
F_71 ( V_9 , V_24 , & V_181 -> V_184 ) ;
F_71 ( V_9 , V_25 , & V_181 -> V_185 ) ;
if ( V_181 -> V_186 ) {
F_7 ( V_9 -> V_21 , L_43 , V_181 -> V_186 ) ;
F_28 ( V_9 -> V_21 , V_70 , V_181 -> V_186 ) ;
}
if ( V_181 -> V_53 ) {
F_7 ( V_9 -> V_21 , L_44 , V_181 -> V_53 ) ;
F_28 ( V_9 -> V_21 , V_69 , V_181 -> V_53 ) ;
}
}
static int F_73 ( struct V_8 * V_9 )
{
unsigned long V_187 = F_3 ( V_9 -> V_11 + V_29 ) ;
unsigned long V_188 = ( V_187 & V_189 ) ;
unsigned long V_190 = ( V_187 & V_191 ) ;
return ( ( V_188 == 0 && V_190 != 0 ) || ( V_188 != 0 && V_190 == 0 ) ) ;
}
static int F_74 ( struct V_8 * V_9 )
{
struct V_180 * V_192 ;
struct V_140 * V_141 ;
T_3 V_102 ;
unsigned long V_193 ;
unsigned long V_194 ;
int V_55 ;
F_75 ( & V_9 -> V_44 ) ;
F_59 ( & V_9 -> V_38 ) ;
F_76 ( & V_9 -> V_90 ) ;
V_194 = F_3 ( V_9 -> V_11 + V_195 ) ;
if ( ( V_194 & V_196 ) != V_197 ) {
F_22 ( V_9 -> V_21 , L_45 , V_194 ) ;
return - V_198 ;
}
F_16 ( 0 , V_9 -> V_11 + V_118 ) ;
V_193 = F_3 ( V_9 -> V_11 + V_26 ) ;
V_102 = V_199 [ ( V_193 >> 13 ) & 0x7 ] ;
F_7 ( V_9 -> V_21 , L_46 ,
V_9 -> V_11 , V_194 , ( unsigned long ) V_102 >> 20 , V_9 -> V_101 ) ;
V_9 -> V_67 = V_194 & V_200 ;
F_8 ( V_9 ) ;
V_55 = F_77 ( V_9 -> V_21 , & V_201 ) ;
if ( V_55 )
F_22 ( V_9 -> V_21 , L_47 ) ;
F_2 ( V_9 ) ;
V_141 = V_9 -> V_142 ;
V_192 = V_141 ? V_141 -> V_181 : NULL ;
if ( V_192 ) {
F_72 ( V_9 , V_192 ) ;
if ( V_192 -> V_90 & V_202 )
F_44 ( V_9 , & V_102 ) ;
if ( V_192 -> V_90 & ( V_116 | V_119 ) )
F_46 ( V_9 , V_192 -> V_90 ) ;
if ( V_192 -> V_90 & V_203 )
F_58 ( V_9 ) ;
}
if ( V_141 && V_141 -> V_171 != NULL && V_141 -> V_173 > 0 ) {
if ( ! F_67 ( V_9 ) )
F_22 ( V_9 -> V_21 , L_48 ) ;
else
F_69 ( V_9 , V_141 ) ;
}
V_55 = F_73 ( V_9 ) ;
if ( V_55 ) {
F_22 ( V_9 -> V_21 , L_49
L_50 ) ;
return - V_198 ;
}
F_48 ( V_9 , & V_102 ) ;
return 0 ;
}
static int F_78 ( struct V_73 * V_21 )
{
struct V_8 * V_9 ;
int V_55 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_80 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_51 ) ;
V_55 = - V_103 ;
goto V_204;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_83 = V_21 -> V_82 ;
V_9 -> V_142 = F_47 ( & V_21 -> V_21 ) ;
V_55 = F_79 ( V_21 , 0 ) ;
if ( V_55 < 0 ) {
F_22 ( & V_21 -> V_21 , L_52 ) ;
goto V_205;
}
V_9 -> V_101 = V_55 ;
V_9 -> V_96 = F_80 ( V_21 , V_95 , 1 ) ;
V_9 -> V_99 = F_80 ( V_21 , V_95 , 0 ) ;
if ( V_9 -> V_96 == NULL || V_9 -> V_99 == NULL ) {
F_22 ( & V_21 -> V_21 , L_53 ) ;
V_55 = - V_206 ;
goto V_205;
}
V_9 -> V_207 = F_60 ( V_9 -> V_96 -> V_97 ,
0x100 , L_54 ) ;
if ( V_9 -> V_207 == NULL ) {
F_22 ( & V_21 -> V_21 , L_55 ) ;
V_55 = - V_208 ;
goto V_205;
}
F_81 ( V_21 , V_9 ) ;
V_9 -> V_11 = F_61 ( V_9 -> V_96 -> V_97 , F_82 ( V_9 -> V_96 ) ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_56 ) ;
V_55 = - V_209 ;
goto V_210;
}
return F_74 ( V_9 ) ;
V_210:
F_64 ( V_9 -> V_207 ) ;
F_33 ( V_9 -> V_207 ) ;
V_205:
F_33 ( V_9 ) ;
V_204:
return V_55 ;
}
static void F_83 ( struct V_8 * V_9 , int V_211 )
{
struct V_140 * V_212 = V_9 -> V_142 ;
if ( V_212 == NULL )
return;
if ( V_212 -> V_213 ) {
if ( V_212 -> V_213 ( V_9 -> V_21 ) == V_211 ) {
F_4 ( V_9 -> V_21 , L_57 , V_211 ) ;
return;
}
}
if ( V_212 -> V_214 ) {
F_4 ( V_9 -> V_21 , L_58 , V_211 ) ;
V_212 -> V_214 ( V_9 -> V_21 , V_211 ) ;
F_10 ( V_9 , 10 ) ;
}
}
static int F_84 ( struct V_73 * V_74 , T_5 V_215 )
{
struct V_8 * V_9 = F_85 ( V_74 ) ;
V_9 -> V_31 = 1 ;
V_9 -> V_216 = F_3 ( V_9 -> V_11 + V_23 ) ;
F_6 ( V_9 ) ;
if ( V_9 -> V_142 ) {
if ( V_9 -> V_142 -> V_94 & V_217 )
F_83 ( V_9 , 0 ) ;
}
return 0 ;
}
static int F_86 ( struct V_73 * V_74 )
{
struct V_8 * V_9 = F_85 ( V_74 ) ;
F_83 ( V_9 , 1 ) ;
F_6 ( V_9 ) ;
F_8 ( V_9 ) ;
F_2 ( V_9 ) ;
if ( F_3 ( V_9 -> V_11 + V_23 ) != V_9 -> V_216 ) {
F_7 ( V_9 -> V_21 , L_59 ) ;
F_16 ( V_9 -> V_216 , V_9 -> V_11 + V_23 ) ;
if ( V_9 -> V_142 && V_9 -> V_142 -> V_181 ) {
F_72 ( V_9 , V_9 -> V_142 -> V_181 ) ;
}
}
F_6 ( V_9 ) ;
F_2 ( V_9 ) ;
V_9 -> V_31 = 0 ;
return 0 ;
}
static int F_87 ( struct V_218 * V_21 ,
const struct V_219 * V_82 )
{
struct V_8 * V_9 ;
int V_220 ;
V_9 = F_36 ( sizeof( struct V_8 ) , V_80 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_21 -> V_21 , L_51 ) ;
V_220 = - V_103 ;
goto V_204;
}
V_21 -> V_21 . V_86 = V_9 -> V_142 = & V_221 ;
V_9 -> V_83 = 32 + V_21 -> V_222 ;
F_88 ( V_21 , V_9 ) ;
V_220 = F_89 ( V_21 ) ;
if ( V_220 ) {
F_22 ( & V_21 -> V_21 , L_60 ) ;
goto V_223;
}
V_9 -> V_21 = & V_21 -> V_21 ;
V_9 -> V_101 = V_21 -> V_101 ;
#ifdef F_90
V_224 . V_94 |= V_225 ;
#endif
if ( ! ( F_91 ( V_21 , 0 ) & V_95 ) ) {
F_22 ( & V_21 -> V_21 , L_61 ) ;
V_220 = - V_198 ;
goto V_226;
}
if ( ! ( F_91 ( V_21 , 1 ) & V_95 ) ) {
F_22 ( & V_21 -> V_21 , L_62 ) ;
V_220 = - V_198 ;
goto V_226;
}
V_9 -> V_96 = & V_21 -> V_79 [ 1 ] ;
V_9 -> V_99 = & V_21 -> V_79 [ 0 ] ;
V_9 -> V_207 = F_60 ( V_9 -> V_96 -> V_97 ,
0x100 , L_54 ) ;
if ( V_9 -> V_207 == NULL ) {
F_22 ( & V_21 -> V_21 , L_55 ) ;
V_220 = - V_208 ;
goto V_226;
}
V_9 -> V_11 = F_92 ( V_21 , 1 ) ;
if ( V_9 -> V_11 == NULL ) {
F_22 ( & V_21 -> V_21 , L_56 ) ;
V_220 = - V_209 ;
goto V_227;
}
F_74 ( V_9 ) ;
return 0 ;
V_227:
F_64 ( V_9 -> V_207 ) ;
F_33 ( V_9 -> V_207 ) ;
V_226:
F_93 ( V_21 ) ;
V_223:
F_33 ( V_9 ) ;
V_204:
return V_220 ;
}
static void F_94 ( struct V_8 * V_9 ,
struct V_72 * V_78 )
{
F_95 ( & V_78 -> V_89 ) ;
F_96 ( & V_78 -> V_74 ) ;
}
static void F_97 ( struct V_8 * V_9 )
{
struct V_72 * V_78 , * V_179 ;
F_98 (smdev, tmp, &sm->devices, list)
F_94 ( V_9 , V_78 ) ;
F_99 ( V_9 -> V_21 , & V_201 ) ;
F_65 ( V_9 ) ;
}
static void F_100 ( struct V_218 * V_21 )
{
struct V_8 * V_9 = F_101 ( V_21 ) ;
F_97 ( V_9 ) ;
F_63 ( V_9 -> V_11 ) ;
F_64 ( V_9 -> V_207 ) ;
F_33 ( V_9 -> V_207 ) ;
F_93 ( V_21 ) ;
}
static int F_102 ( struct V_73 * V_21 )
{
struct V_8 * V_9 = F_85 ( V_21 ) ;
F_97 ( V_9 ) ;
F_63 ( V_9 -> V_11 ) ;
F_64 ( V_9 -> V_207 ) ;
F_33 ( V_9 -> V_207 ) ;
return 0 ;
}
static int T_6 F_103 ( void )
{
F_104 ( & V_228 ) ;
return F_105 ( & V_229 ) ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_228 ) ;
F_108 ( & V_229 ) ;
}
