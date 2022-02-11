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
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
unsigned short V_26 ;
int V_27 = F_4 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_28 = F_9 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_29 = F_10 ( ( & V_11 -> V_15 ) [ 0 ] ) ;
int V_30 ;
V_16 -> V_31 &= 0xFFFC ;
F_5 ( V_16 -> V_31 , V_16 -> V_19 + V_32 ) ;
V_16 -> V_17 &= ~ ( V_33 | V_34 ) ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_35 ) ;
V_16 -> V_17 |= ( V_33 | V_34 ) ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
V_26 = V_27 & 0x0f ;
V_26 |= ( V_28 & 0x03 ) << 4 ;
V_26 |= ( V_28 & 0x04 ) << 4 ;
V_26 |= ( ( V_29 & V_36 ) ? 0x80 : 0 ) ;
F_5 ( V_26 & 0xff , V_16 -> V_19 + V_37 ) ;
V_16 -> V_31 |= V_38 ;
F_5 ( V_16 -> V_31 , V_16 -> V_19 + V_32 ) ;
F_7 ( V_16 -> V_19 + V_39 ) ;
for ( V_30 = 100000 ; V_30 > 0 ; V_30 -- )
if ( ! ( F_7 ( V_16 -> V_19 + V_40 ) & 0x0004 ) )
break;
if ( V_30 ) {
V_12 [ 0 ] =
( F_7 ( V_16 -> V_19 +
V_41 ) ^ 0x800 ) & 0x0FFF ;
} else {
F_11 ( V_42 L_1 ,
V_7 -> V_43 ) ;
return - V_44 ;
}
V_16 -> V_31 &= 0xFFFC ;
F_5 ( V_16 -> V_31 , V_16 -> V_19 + V_32 ) ;
return 1 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_16 -> V_31 &= 0xFFFC ;
F_5 ( V_16 -> V_31 , V_16 -> V_19 + V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_45 * V_46 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
int V_27 ;
int V_28 ;
int V_30 ;
V_16 -> V_17 |= V_47 ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
V_16 -> V_17 |= V_48 ;
F_5 ( V_16 -> V_17 , V_16 -> V_19 + V_20 ) ;
for ( V_30 = 0 ; V_30 < V_11 -> V_25 ; V_30 ++ ) {
V_27 = F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
V_28 = F_9 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
V_16 -> V_49 &= ~ ( 0x0880 >> V_27 ) ;
if ( V_28 == 0 )
V_16 -> V_49 |=
( ( V_50 | V_51 ) >> V_27 ) ;
else if ( V_28 == 1 )
V_16 -> V_49 |=
( ( V_50 | V_52 ) >> V_27 ) ;
}
F_5 ( V_16 -> V_49 ,
V_16 -> V_19 + V_53 ) ;
F_7 ( V_16 -> V_19 + V_54 ) ;
for ( V_30 = 0 ; V_30 < V_11 -> V_25 ; V_30 ++ ) {
V_27 = F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
F_5 ( ( V_12 [ 0 ] & V_9 -> V_55 ) ,
V_16 -> V_19 + V_56 + ( V_27 << 1 ) ) ;
V_16 -> V_57 [ V_27 ] = ( V_12 [ 0 ] & V_9 -> V_55 ) ;
}
F_7 ( V_16 -> V_19 + V_58 ) ;
return V_30 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned int * V_12 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_11 -> V_25 ; V_30 ++ ) {
V_12 [ V_30 ] =
V_16 -> V_57 [ F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ] ;
}
return 1 ;
}
static int F_17 ( struct V_6 * V_7 ,
const T_1 * V_12 , T_2 V_59 )
{
unsigned int V_26 ;
unsigned int V_60 ;
unsigned int V_30 ;
F_18 ( 0x00 , V_16 -> V_61 + V_62 ) ;
V_26 = F_7 ( V_16 -> V_19 + V_63 ) ;
F_1 ( 1 ) ;
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_59 < 16 )
return - V_64 ;
V_60 = ( ( ( unsigned int ) V_12 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_12 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_12 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_12 [ 3 ] & 0xff ) ;
for ( V_30 = 0 ; V_30 < V_60 ; V_30 ++ )
F_19 ( ( V_12 [ 16 + V_30 ] & 0xff ) ,
V_16 -> V_19 + 0x0 ) ;
for ( V_30 = 0 ; V_30 < 5 ; V_30 ++ )
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
V_26 = F_20 ( V_16 -> V_61 + V_62 ) ;
if ( V_26 & 0x20 ) {
F_18 ( 0x00 , V_16 -> V_61 + V_62 ) ;
F_11 ( V_42 L_2 ,
V_7 -> V_43 ) ;
return - V_44 ;
}
F_1 ( 1 ) ;
F_18 ( 0x43 , V_16 -> V_61 + V_62 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_65 * V_66 = F_22 ( V_7 ) ;
const struct V_67 * V_68 ;
int V_69 ;
V_69 = F_23 ( & V_68 , V_70 , & V_66 -> V_7 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_17 ( V_7 , V_68 -> V_12 , V_68 -> V_59 ) ;
F_24 ( V_68 ) ;
return V_69 ;
}
static int F_25 ( struct V_6 * V_7 )
{
F_5 ( 0x00 , V_16 -> V_19 + V_32 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_20 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_35 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_53 ) ;
V_16 -> V_49 = 0 ;
V_16 -> V_31 = 0 ;
V_16 -> V_17 = 0 ;
return 0 ;
}
static const void * F_26 ( struct V_6 * V_7 ,
struct V_65 * V_66 )
{
const struct V_71 * V_72 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_27 ( V_73 ) ; V_30 ++ ) {
V_72 = & V_73 [ V_30 ] ;
if ( V_72 -> V_74 == V_66 -> V_75 )
return V_72 ;
}
return NULL ;
}
static int F_28 ( struct V_6 * V_7 , struct V_65 * V_66 )
{
const struct V_71 * V_72 ;
struct V_8 * V_9 ;
T_3 V_76 ;
unsigned long V_77 ;
T_3 V_78 ;
unsigned long V_79 ;
T_3 V_80 ;
unsigned long V_81 ;
T_3 V_82 ;
int V_83 , error ;
F_29 ( V_7 , & V_66 -> V_7 ) ;
V_72 = F_26 ( V_7 , V_66 ) ;
if ( ! V_72 )
return - V_84 ;
V_7 -> V_85 = V_72 ;
V_7 -> V_86 = V_72 -> V_87 ;
if ( F_30 ( V_7 , sizeof( struct V_88 ) ) < 0 )
return - V_89 ;
if ( F_31 ( V_66 , V_7 -> V_86 ) < 0 ) {
F_11 ( V_42 L_3
L_4 , V_7 -> V_43 ) ;
return - V_44 ;
}
V_76 = F_32 ( V_66 , 0 ) ;
V_77 = F_33 ( V_66 , 0 ) ;
V_16 -> V_61 =
F_34 ( V_76 , V_77 ) ;
V_16 -> V_90 = V_77 ;
if ( ! V_16 -> V_61 ) {
F_11 ( L_5 , V_7 -> V_43 ) ;
return - V_89 ;
}
V_80 = F_32 ( V_66 , 5 ) ;
V_81 = F_33 ( V_66 , 5 ) ;
if ( ! V_80 )
F_11 ( V_42 L_6 , V_7 -> V_43 ) ;
if ( V_76 & 0x0080 ) {
F_11 ( V_42 L_7 , V_7 -> V_43 ) ;
if ( V_80 ) {
V_82 = V_76 ;
V_76 = V_80 ;
V_80 = V_82 ;
V_83 = F_35 ( V_66 ,
V_91 ,
V_76 ) ;
if ( V_83 != V_92 )
return - V_44 ;
V_83 = F_35 ( V_66 ,
V_93 ,
V_80 ) ;
if ( V_83 != V_92 )
return - V_44 ;
} else {
V_76 -= 0x80 ;
V_83 = F_35 ( V_66 ,
V_91 ,
V_76 ) ;
if ( V_83 != V_92 )
return - V_44 ;
}
}
V_78 = F_32 ( V_66 , 2 ) ;
V_79 = F_33 ( V_66 , 2 ) ;
V_16 -> V_94 = V_79 ;
V_16 -> V_19 = F_34 ( V_78 , V_79 ) ;
if ( ! V_16 -> V_19 ) {
F_11 ( V_42 L_5 ,
V_7 -> V_43 ) ;
return - V_89 ;
}
if ( V_72 -> V_74 == V_95 ) {
V_83 = F_21 ( V_7 ) ;
if ( V_83 < 0 )
return V_83 ;
}
F_25 ( V_7 ) ;
error = F_36 ( V_7 , 3 ) ;
if ( error )
return error ;
V_9 = & V_7 -> V_96 [ 0 ] ;
V_9 -> type = V_97 ;
V_9 -> V_98 = V_99 | V_100 | V_101 ;
V_9 -> V_102 = V_72 -> V_103 ;
V_9 -> V_55 = V_72 -> V_104 ;
V_9 -> V_105 = V_72 -> V_103 ;
V_9 -> V_106 = V_72 -> V_107 ;
V_9 -> V_108 = F_12 ;
V_9 -> V_109 = F_8 ;
V_9 -> V_110 = F_13 ;
V_9 -> V_111 = F_14 ;
V_9 = & V_7 -> V_96 [ 1 ] ;
V_9 -> type = V_112 ;
V_9 -> V_98 = V_113 | V_100 ;
V_9 -> V_102 = V_72 -> V_114 ;
V_9 -> V_55 = V_72 -> V_115 ;
V_9 -> V_105 = V_72 -> V_114 ;
V_9 -> V_106 = V_72 -> V_116 ;
V_9 -> V_109 = F_16 ;
V_9 -> V_117 = F_15 ;
V_9 = & V_7 -> V_96 [ 2 ] ;
V_9 -> type = V_118 ;
V_9 -> V_98 = V_99 | V_113 ;
V_9 -> V_102 = V_72 -> V_119 ;
V_9 -> V_55 = 1 ;
V_9 -> V_105 = V_72 -> V_119 ;
V_9 -> V_106 = & V_120 ;
V_9 -> V_121 = F_6 ;
V_9 -> V_122 = F_3 ;
V_9 -> V_22 = 0 ;
F_37 ( V_7 -> V_123 , L_8 ,
V_7 -> V_124 -> V_125 , V_7 -> V_86 ) ;
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_65 * V_66 = F_22 ( V_7 ) ;
if ( V_16 ) {
if ( V_16 -> V_19 ) {
F_25 ( V_7 ) ;
F_39 ( V_16 -> V_19 ) ;
}
if ( V_16 -> V_61 )
F_39 ( V_16 -> V_61 ) ;
}
if ( V_66 ) {
if ( V_16 -> V_90 )
F_40 ( V_66 ) ;
F_41 ( V_66 ) ;
}
}
static int T_4 F_42 ( struct V_65 * V_7 ,
const struct V_126 * V_127 )
{
return F_43 ( V_7 , & V_128 ) ;
}
static void T_5 F_44 ( struct V_65 * V_7 )
{
F_45 ( V_7 ) ;
}
