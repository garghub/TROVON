static inline void F_1 ( unsigned V_1 )
{
V_2 -> V_3 = V_4 ;
F_2 ( V_1 * V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
int V_13 ;
int V_14 = 1 << F_4 ( V_11 -> V_15 ) ;
if ( V_14 & 0x0000ffff ) {
V_13 = 0x0000ffff ;
V_16 -> V_17 |= V_18 ;
F_5 ( V_16 -> V_17 ,
V_16 -> V_19 + V_20 ) ;
} else {
V_13 = 0xffff0000 ;
V_16 -> V_17 |= V_21 ;
F_5 ( V_16 -> V_17 ,
V_16 -> V_19 + V_20 ) ;
}
if ( V_12 [ 0 ] ) {
V_9 -> V_22 |= V_13 ;
} else {
V_9 -> V_22 &= ~ V_13 ;
}
return 1 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
unsigned int V_14 = V_12 [ 0 ] ;
V_9 -> V_3 &= ~ V_14 ;
V_9 -> V_3 |= ( V_14 & V_12 [ 1 ] ) ;
V_14 &= V_9 -> V_22 ;
if ( V_14 & 0x0000ffff ) {
F_5 ( ( V_9 -> V_3 & 0xffff ) ,
V_16 -> V_19 + V_23 ) ;
} else {
V_12 [ 1 ] &= ~ 0x0000ffff ;
V_12 [ 1 ] |= F_7 ( V_16 -> V_19 + V_23 ) ;
}
if ( V_14 & 0xffff0000 ) {
F_5 ( ( ( V_9 -> V_3 >> 16 ) & 0xffff ) ,
V_16 -> V_19 + V_24 ) ;
} else {
V_12 [ 1 ] &= ~ 0xffff0000 ;
V_12 [ 1 ] |= F_7 ( V_16 -> V_19 + V_24 ) << 16 ;
}
return V_11 -> V_25 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_8 * V_26 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
unsigned short V_27 ;
int V_28 = F_4 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_29 = F_9 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_30 = F_10 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_31 ;
V_16 -> V_32 &= 0xFFFC ;
F_5 ( V_16 -> V_32 , V_16 -> V_19 + V_33 ) ;
V_16 -> V_17 &= ~ ( V_34 | V_35 ) ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_36 ) ;
V_16 -> V_17 |= ( V_34 | V_35 ) ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
V_27 = V_28 & 0x0f ;
V_27 |= ( V_29 & 0x03 ) << 4 ;
V_27 |= ( V_29 & 0x04 ) << 4 ;
V_27 |= ( ( V_30 & V_37 ) ? 0x80 : 0 ) ;
F_5 ( V_27 & 0xff , V_16 -> V_19 + V_38 ) ;
V_16 -> V_32 |= V_39 ;
F_5 ( V_16 -> V_32 , V_16 -> V_19 + V_33 ) ;
F_7 ( V_16 -> V_19 + V_40 ) ;
for ( V_31 = 100000 ; V_31 > 0 ; V_31 -- )
if ( ! ( F_7 ( V_16 -> V_19 + V_41 ) & 0x0004 ) )
break;
if ( V_31 ) {
V_12 [ 0 ] =
( F_7 ( V_16 -> V_19 +
V_42 ) ^ 0x800 ) & 0x0FFF ;
} else {
F_11 ( V_43 L_1 ,
V_7 -> V_44 ) ;
return - V_45 ;
}
V_16 -> V_32 &= 0xFFFC ;
F_5 ( V_16 -> V_32 , V_16 -> V_19 + V_33 ) ;
return 1 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_16 -> V_32 &= 0xFFFC ;
F_5 ( V_16 -> V_32 , V_16 -> V_19 + V_33 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_46 * V_47 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_8 * V_26 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
int V_28 ;
int V_29 ;
int V_31 ;
V_16 -> V_17 |= V_48 ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
V_16 -> V_17 |= V_49 ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
for ( V_31 = 0 ; V_31 < V_11 -> V_25 ; V_31 ++ ) {
V_28 = F_4 ( ( & V_11 -> V_15 ) [ V_31 ] ) ;
V_29 = F_9 ( ( & V_11 -> V_15 ) [ V_31 ] ) ;
V_16 -> V_50 &= ~ ( 0x0880 >> V_28 ) ;
if ( V_29 == 0 )
V_16 -> V_50 |=
( ( V_51 | V_52 ) >> V_28 ) ;
else if ( V_29 == 1 )
V_16 -> V_50 |=
( ( V_51 | V_53 ) >> V_28 ) ;
}
F_5 ( V_16 -> V_50 ,
V_16 -> V_19 + V_54 ) ;
F_7 ( V_16 -> V_19 + V_55 ) ;
for ( V_31 = 0 ; V_31 < V_11 -> V_25 ; V_31 ++ ) {
V_28 = F_4 ( ( & V_11 -> V_15 ) [ V_31 ] ) ;
F_5 ( ( V_12 [ 0 ] & V_9 -> V_56 ) ,
V_16 -> V_19 + V_57 + ( V_28 << 1 ) ) ;
V_16 -> V_58 [ V_28 ] = ( V_12 [ 0 ] & V_9 -> V_56 ) ;
}
F_7 ( V_16 -> V_19 + V_59 ) ;
return V_31 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned int * V_12 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_11 -> V_25 ; V_31 ++ ) {
V_12 [ V_31 ] =
V_16 -> V_58 [ F_4 ( ( & V_11 -> V_15 ) [ V_31 ] ) ] ;
}
return 1 ;
}
static int F_17 ( struct V_6 * V_7 ,
unsigned char * V_60 ,
unsigned int V_61 )
{
unsigned int V_27 ;
unsigned int V_62 ;
unsigned int V_31 ;
F_18 ( 0x00 , V_16 -> V_63 + V_64 ) ;
V_27 = F_7 ( V_16 -> V_19 + V_65 ) ;
F_1 ( 1 ) ;
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_61 < 16 )
return - V_66 ;
V_62 = ( ( ( unsigned int ) V_60 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_60 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_60 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_60 [ 3 ] & 0xff ) ;
for ( V_31 = 0 ; V_31 < V_62 ; V_31 ++ )
F_19 ( ( V_60 [ 16 + V_31 ] & 0xff ) ,
V_16 -> V_19 + 0x0 ) ;
for ( V_31 = 0 ; V_31 < 5 ; V_31 ++ )
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
V_27 = F_20 ( V_16 -> V_63 + V_64 ) ;
if ( V_27 & 0x20 ) {
F_18 ( 0x00 , V_16 -> V_63 + V_64 ) ;
F_11 ( V_43 L_2 ,
V_7 -> V_44 ) ;
return - V_45 ;
}
F_1 ( 1 ) ;
F_18 ( 0x43 , V_16 -> V_63 + V_64 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
F_5 ( 0x00 , V_16 -> V_19 + V_33 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_20 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_36 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_54 ) ;
V_16 -> V_50 = 0 ;
V_16 -> V_32 = 0 ;
V_16 -> V_17 = 0 ;
return 0 ;
}
static struct V_67 * F_22 ( struct V_6 * V_7 ,
struct V_68 * V_69 )
{
const struct V_70 * V_71 ;
struct V_67 * V_72 = NULL ;
int V_73 = V_69 -> V_74 [ 0 ] ;
int V_75 = V_69 -> V_74 [ 1 ] ;
int V_31 ;
F_23 (pcidev) {
if ( V_73 || V_75 ) {
if ( V_72 -> V_73 -> V_76 != V_73 ||
F_24 ( V_72 -> V_77 ) != V_75 )
continue;
}
if ( V_72 -> V_78 != V_79 )
continue;
for ( V_31 = 0 ; V_31 < F_25 ( V_80 ) ; V_31 ++ ) {
V_71 = & V_80 [ V_31 ] ;
if ( V_71 -> V_81 != V_72 -> V_82 )
continue;
V_7 -> V_83 = V_71 ;
return V_72 ;
}
}
F_26 ( V_7 -> V_84 ,
L_3 ,
V_73 , V_75 ) ;
return NULL ;
}
static int F_27 ( struct V_6 * V_7 , struct V_68 * V_69 )
{
struct V_67 * V_85 ;
struct V_8 * V_26 ;
struct V_70 * V_71 ;
T_1 V_86 ;
unsigned long V_87 ;
T_1 V_88 ;
unsigned long V_89 ;
T_1 V_90 ;
unsigned long V_91 ;
T_1 V_92 ;
int V_93 , error ;
if ( F_28 ( V_7 , sizeof( struct V_94 ) ) < 0 )
return - V_95 ;
V_85 = F_22 ( V_7 , V_69 ) ;
if ( ! V_85 )
return - V_45 ;
F_29 ( V_7 , & V_85 -> V_7 ) ;
V_71 = (struct V_70 * ) V_7 -> V_83 ;
if ( F_30 ( V_85 , V_96 ) < 0 ) {
F_11 ( V_43 L_4
L_5 , V_7 -> V_44 ) ;
return - V_45 ;
}
V_7 -> V_97 = V_71 -> V_98 ;
V_86 = F_31 ( V_85 , 0 ) ;
V_87 = F_32 ( V_85 , 0 ) ;
V_16 -> V_63 =
F_33 ( V_86 , V_87 ) ;
V_16 -> V_99 = V_87 ;
if ( ! V_16 -> V_63 ) {
F_11 ( L_6 , V_7 -> V_44 ) ;
return - V_95 ;
}
V_90 = F_31 ( V_85 , 5 ) ;
V_91 = F_32 ( V_85 , 5 ) ;
if ( ! V_90 )
F_11 ( V_43 L_7 , V_7 -> V_44 ) ;
if ( V_86 & 0x0080 ) {
F_11 ( V_43 L_8 , V_7 -> V_44 ) ;
if ( V_90 ) {
V_92 = V_86 ;
V_86 = V_90 ;
V_90 = V_92 ;
V_93 = F_34 ( V_85 ,
V_100 ,
V_86 ) ;
if ( V_93 != V_101 )
return - V_45 ;
V_93 = F_34 ( V_85 ,
V_102 ,
V_90 ) ;
if ( V_93 != V_101 )
return - V_45 ;
} else {
V_86 -= 0x80 ;
V_93 = F_34 ( V_85 ,
V_100 ,
V_86 ) ;
if ( V_93 != V_101 )
return - V_45 ;
}
}
V_88 = F_31 ( V_85 , 2 ) ;
V_89 = F_32 ( V_85 , 2 ) ;
V_16 -> V_103 = V_89 ;
V_16 -> V_19 = F_33 ( V_88 , V_89 ) ;
if ( ! V_16 -> V_19 ) {
F_11 ( V_43 L_6 ,
V_7 -> V_44 ) ;
return - V_95 ;
}
if ( V_71 -> V_81 == V_104 ) {
unsigned char * V_105 ;
int V_106 ;
V_105 = F_35 ( V_69 -> V_74 , 0 ) ;
V_106 = V_69 -> V_74 [ V_107 ] ;
if ( ! V_105 || V_106 < 1 ) {
F_36 ( V_7 , L_9
L_10
L_11 ) ;
return - V_66 ;
}
F_17 ( V_7 , V_105 , V_106 ) ;
}
F_21 ( V_7 ) ;
error = F_37 ( V_7 , 3 ) ;
if ( error )
return error ;
V_26 = V_7 -> V_108 + 0 ;
V_26 -> type = V_109 ;
V_26 -> V_110 = V_111 | V_112 | V_113 ;
V_26 -> V_114 = V_71 -> V_115 ;
V_26 -> V_56 = V_71 -> V_116 ;
V_26 -> V_117 = V_71 -> V_115 ;
V_26 -> V_118 = V_71 -> V_119 ;
V_26 -> V_120 = F_12 ;
V_26 -> V_121 = F_8 ;
V_26 -> V_122 = F_13 ;
V_26 -> V_123 = F_14 ;
V_26 = V_7 -> V_108 + 1 ;
V_26 -> type = V_124 ;
V_26 -> V_110 = V_125 | V_112 ;
V_26 -> V_114 = V_71 -> V_126 ;
V_26 -> V_56 = V_71 -> V_127 ;
V_26 -> V_117 = V_71 -> V_126 ;
V_26 -> V_118 = V_71 -> V_128 ;
V_26 -> V_121 = F_16 ;
V_26 -> V_129 = F_15 ;
V_26 = V_7 -> V_108 + 2 ;
V_26 -> type = V_130 ;
V_26 -> V_110 = V_111 | V_125 ;
V_26 -> V_114 = V_71 -> V_131 ;
V_26 -> V_56 = 1 ;
V_26 -> V_117 = V_71 -> V_131 ;
V_26 -> V_118 = & V_132 ;
V_26 -> V_133 = F_6 ;
V_26 -> V_134 = F_3 ;
V_26 -> V_22 = 0 ;
F_11 ( V_135 L_12 V_96 L_13 ,
V_7 -> V_44 ) ;
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_67 * V_72 = F_39 ( V_7 ) ;
if ( V_16 ) {
if ( V_16 -> V_19 ) {
F_21 ( V_7 ) ;
F_40 ( V_16 -> V_19 ) ;
}
if ( V_16 -> V_63 )
F_40 ( V_16 -> V_63 ) ;
}
if ( V_72 ) {
if ( V_16 -> V_99 )
F_41 ( V_72 ) ;
F_42 ( V_72 ) ;
}
}
static int T_2 F_43 ( struct V_67 * V_7 ,
const struct V_136 * V_137 )
{
return F_44 ( V_7 , & V_138 ) ;
}
static void T_3 F_45 ( struct V_67 * V_7 )
{
F_46 ( V_7 ) ;
}
