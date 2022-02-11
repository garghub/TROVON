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
return 2 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_8 * V_25 ,
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
struct V_8 * V_25 )
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
for ( V_30 = 0 ; V_30 < V_11 -> V_49 ; V_30 ++ ) {
V_27 = F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
V_28 = F_9 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
V_16 -> V_50 &= ~ ( 0x0880 >> V_27 ) ;
if ( V_28 == 0 )
V_16 -> V_50 |=
( ( V_51 | V_52 ) >> V_27 ) ;
else if ( V_28 == 1 )
V_16 -> V_50 |=
( ( V_51 | V_53 ) >> V_27 ) ;
}
F_5 ( V_16 -> V_50 ,
V_16 -> V_19 + V_54 ) ;
F_7 ( V_16 -> V_19 + V_55 ) ;
for ( V_30 = 0 ; V_30 < V_11 -> V_49 ; V_30 ++ ) {
V_27 = F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ;
F_5 ( ( V_12 [ 0 ] & V_9 -> V_56 ) ,
V_16 -> V_19 + V_57 + ( V_27 << 1 ) ) ;
V_16 -> V_58 [ V_27 ] = ( V_12 [ 0 ] & V_9 -> V_56 ) ;
}
F_7 ( V_16 -> V_19 + V_59 ) ;
return V_30 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned int * V_12 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_11 -> V_49 ; V_30 ++ ) {
V_12 [ V_30 ] =
V_16 -> V_58 [ F_4 ( ( & V_11 -> V_15 ) [ V_30 ] ) ] ;
}
return 1 ;
}
static int F_17 ( struct V_6 * V_7 ,
unsigned char * V_60 ,
unsigned int V_61 )
{
unsigned int V_26 ;
unsigned int V_62 ;
unsigned int V_30 ;
F_18 ( 0x00 , V_16 -> V_63 + V_64 ) ;
V_26 = F_7 ( V_16 -> V_19 + V_65 ) ;
F_1 ( 1 ) ;
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
F_1 ( 1 ) ;
if ( V_61 < 16 )
return - V_66 ;
V_62 = ( ( ( unsigned int ) V_60 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_60 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_60 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_60 [ 3 ] & 0xff ) ;
for ( V_30 = 0 ; V_30 < V_62 ; V_30 ++ )
F_19 ( ( V_60 [ 16 + V_30 ] & 0xff ) ,
V_16 -> V_19 + 0x0 ) ;
for ( V_30 = 0 ; V_30 < 5 ; V_30 ++ )
F_19 ( 0x00 , V_16 -> V_19 + 0x0 ) ;
V_26 = F_20 ( V_16 -> V_63 + V_64 ) ;
if ( V_26 & 0x20 ) {
F_18 ( 0x00 , V_16 -> V_63 + V_64 ) ;
F_11 ( V_42 L_2 ,
V_7 -> V_43 ) ;
return - V_44 ;
}
F_1 ( 1 ) ;
F_18 ( 0x43 , V_16 -> V_63 + V_64 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
F_5 ( 0x00 , V_16 -> V_19 + V_32 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_20 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_35 ) ;
F_5 ( 0x00 , V_16 -> V_19 + V_54 ) ;
V_16 -> V_50 = 0 ;
V_16 -> V_31 = 0 ;
V_16 -> V_17 = 0 ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_67 * V_68 )
{
struct V_69 * V_70 = NULL ;
struct V_8 * V_25 ;
struct V_71 * V_72 ;
T_1 V_73 ;
unsigned long V_74 ;
T_1 V_75 ;
unsigned long V_76 ;
T_1 V_77 ;
unsigned long V_78 ;
T_1 V_79 ;
int V_80 , error , V_30 ;
if ( F_23 ( V_7 , sizeof( struct V_81 ) ) < 0 )
return - V_82 ;
F_24 (pci_device) {
if ( V_70 -> V_83 == V_84 ) {
for ( V_30 = 0 ; V_30 < V_85 ; V_30 ++ ) {
if ( V_86 [ V_30 ] . V_87 ==
V_70 -> V_88 ) {
if ( ( V_68 -> V_89 [ 0 ] != 0 )
|| ( V_68 -> V_89 [ 1 ] != 0 ) ) {
if ( V_70 -> V_90 -> V_91 !=
V_68 -> V_89 [ 0 ]
||
F_25 ( V_70 -> V_92 )
!= V_68 -> V_89 [ 1 ] ) {
continue;
}
}
V_7 -> V_93 = V_86 + V_30 ;
V_72 =
(struct V_71 * ) V_7 -> V_93 ;
V_16 -> V_70 = V_70 ;
goto V_94;
}
}
}
}
F_11 ( V_42
L_3 ,
V_7 -> V_43 , V_68 -> V_89 [ 0 ] , V_68 -> V_89 [ 1 ] ) ;
return - V_44 ;
V_94:
F_11 ( V_95 L_4 ,
V_7 -> V_43 , V_86 [ V_30 ] . V_96 ,
V_70 -> V_90 -> V_91 , F_25 ( V_70 -> V_92 ) ) ;
if ( F_26 ( V_70 , V_97 ) < 0 ) {
F_11 ( V_42 L_5
L_6 , V_7 -> V_43 ) ;
return - V_44 ;
}
V_7 -> V_98 = V_72 -> V_96 ;
V_73 = F_27 ( V_70 , 0 ) ;
V_74 = F_28 ( V_70 , 0 ) ;
V_16 -> V_63 =
F_29 ( V_73 , V_74 ) ;
V_16 -> V_99 = V_74 ;
if ( ! V_16 -> V_63 ) {
F_11 ( L_7 , V_7 -> V_43 ) ;
return - V_82 ;
}
V_77 = F_27 ( V_70 , 5 ) ;
V_78 = F_28 ( V_70 , 5 ) ;
if ( ! V_77 )
F_11 ( V_42 L_8 , V_7 -> V_43 ) ;
if ( V_73 & 0x0080 ) {
F_11 ( V_42 L_9 , V_7 -> V_43 ) ;
if ( V_77 ) {
V_79 = V_73 ;
V_73 = V_77 ;
V_77 = V_79 ;
V_80 = F_30 ( V_70 ,
V_100 ,
V_73 ) ;
if ( V_80 != V_101 )
return - V_44 ;
V_80 = F_30 ( V_70 ,
V_102 ,
V_77 ) ;
if ( V_80 != V_101 )
return - V_44 ;
} else {
V_73 -= 0x80 ;
V_80 = F_30 ( V_70 ,
V_100 ,
V_73 ) ;
if ( V_80 != V_101 )
return - V_44 ;
}
}
V_75 = F_27 ( V_70 , 2 ) ;
V_76 = F_28 ( V_70 , 2 ) ;
V_16 -> V_103 = V_76 ;
V_16 -> V_19 = F_29 ( V_75 , V_76 ) ;
if ( ! V_16 -> V_19 ) {
F_11 ( V_42 L_7 ,
V_7 -> V_43 ) ;
return - V_82 ;
}
if ( V_72 -> V_87 == V_104 ) {
unsigned char * V_105 ;
int V_106 ;
V_105 = F_31 ( V_68 -> V_89 , 0 ) ;
V_106 = V_68 -> V_89 [ V_107 ] ;
if ( ! V_105 || V_106 < 1 ) {
F_32 ( V_7 , L_10
L_11
L_12 ) ;
return - V_66 ;
}
F_17 ( V_7 , V_105 , V_106 ) ;
}
F_21 ( V_7 ) ;
error = F_33 ( V_7 , 3 ) ;
if ( error < 0 )
return error ;
V_25 = V_7 -> V_108 + 0 ;
V_25 -> type = V_109 ;
V_25 -> V_110 = V_111 | V_112 | V_113 ;
V_25 -> V_114 = V_72 -> V_115 ;
V_25 -> V_56 = V_72 -> V_116 ;
V_25 -> V_117 = V_72 -> V_115 ;
V_25 -> V_118 = V_72 -> V_119 ;
V_25 -> V_120 = F_12 ;
V_25 -> V_121 = F_8 ;
V_25 -> V_122 = F_13 ;
V_25 -> V_123 = F_14 ;
V_25 = V_7 -> V_108 + 1 ;
V_25 -> type = V_124 ;
V_25 -> V_110 = V_125 | V_112 ;
V_25 -> V_114 = V_72 -> V_126 ;
V_25 -> V_56 = V_72 -> V_127 ;
V_25 -> V_117 = V_72 -> V_126 ;
V_25 -> V_118 = V_72 -> V_128 ;
V_25 -> V_121 = F_16 ;
V_25 -> V_129 = F_15 ;
V_25 = V_7 -> V_108 + 2 ;
V_25 -> type = V_130 ;
V_25 -> V_110 = V_111 | V_125 ;
V_25 -> V_114 = V_72 -> V_131 ;
V_25 -> V_56 = 1 ;
V_25 -> V_117 = V_72 -> V_131 ;
V_25 -> V_118 = & V_132 ;
V_25 -> V_133 = F_6 ;
V_25 -> V_134 = F_3 ;
V_25 -> V_22 = 0 ;
F_11 ( V_95 L_13 V_97 L_14 ,
V_7 -> V_43 ) ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
if ( V_16 ) {
if ( V_16 -> V_19 ) {
F_21 ( V_7 ) ;
F_35 ( V_16 -> V_19 ) ;
}
if ( V_16 -> V_63 )
F_35 ( V_16 -> V_63 ) ;
if ( V_16 -> V_70 ) {
if ( V_16 -> V_99 )
F_36 ( V_16 -> V_70 ) ;
F_37 ( V_16 -> V_70 ) ;
}
}
}
static int T_2 F_38 ( struct V_69 * V_7 ,
const struct V_135 * V_136 )
{
return F_39 ( V_7 , & V_137 ) ;
}
static void T_3 F_40 ( struct V_69 * V_7 )
{
F_41 ( V_7 ) ;
}
