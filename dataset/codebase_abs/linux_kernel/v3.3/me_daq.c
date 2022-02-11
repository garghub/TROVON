static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static inline void F_11 ( unsigned V_10 )
{
V_11 -> V_12 = V_13 ;
F_12 ( V_10 * V_14 ) ;
}
static int F_13 ( struct V_15 * V_2 ,
struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
int V_21 ;
int V_22 = 1 << F_14 ( V_19 -> V_23 ) ;
if ( V_22 & 0x0000ffff ) {
V_21 = 0x0000ffff ;
V_24 -> V_25 |= V_26 ;
F_15 ( V_24 -> V_25 ,
V_24 -> V_27 + V_28 ) ;
} else {
V_21 = 0xffff0000 ;
V_24 -> V_25 |= V_29 ;
F_15 ( V_24 -> V_25 ,
V_24 -> V_27 + V_28 ) ;
}
if ( V_20 [ 0 ] ) {
V_17 -> V_30 |= V_21 ;
} else {
V_17 -> V_30 &= ~ V_21 ;
}
return 1 ;
}
static int F_16 ( struct V_15 * V_2 ,
struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
unsigned int V_22 = V_20 [ 0 ] ;
V_17 -> V_12 &= ~ V_22 ;
V_17 -> V_12 |= ( V_22 & V_20 [ 1 ] ) ;
V_22 &= V_17 -> V_30 ;
if ( V_22 & 0x0000ffff ) {
F_15 ( ( V_17 -> V_12 & 0xffff ) ,
V_24 -> V_27 + V_31 ) ;
} else {
V_20 [ 1 ] &= ~ 0x0000ffff ;
V_20 [ 1 ] |= F_17 ( V_24 -> V_27 + V_31 ) ;
}
if ( V_22 & 0xffff0000 ) {
F_15 ( ( ( V_17 -> V_12 >> 16 ) & 0xffff ) ,
V_24 -> V_27 + V_32 ) ;
} else {
V_20 [ 1 ] &= ~ 0xffff0000 ;
V_20 [ 1 ] |= F_17 ( V_24 -> V_27 + V_32 ) << 16 ;
}
return 2 ;
}
static int F_18 ( struct V_15 * V_2 ,
struct V_16 * V_33 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
unsigned short V_34 ;
int V_35 = F_14 ( ( & V_19 -> V_23 ) [ 0 ] ) ;
int V_36 = F_19 ( ( & V_19 -> V_23 ) [ 0 ] ) ;
int V_37 = F_20 ( ( & V_19 -> V_23 ) [ 0 ] ) ;
int V_38 ;
V_24 -> V_39 &= 0xFFFC ;
F_15 ( V_24 -> V_39 , V_24 -> V_27 + V_40 ) ;
V_24 -> V_25 &= ~ ( V_41 | V_42 ) ;
F_15 ( V_24 -> V_25 , V_24 -> V_27 + V_28 ) ;
F_15 ( 0x00 , V_24 -> V_27 + V_43 ) ;
V_24 -> V_25 |= ( V_41 | V_42 ) ;
F_15 ( V_24 -> V_25 , V_24 -> V_27 + V_28 ) ;
V_34 = V_35 & 0x0f ;
V_34 |= ( V_36 & 0x03 ) << 4 ;
V_34 |= ( V_36 & 0x04 ) << 4 ;
V_34 |= ( ( V_37 & V_44 ) ? 0x80 : 0 ) ;
F_15 ( V_34 & 0xff , V_24 -> V_27 + V_45 ) ;
V_24 -> V_39 |= V_46 ;
F_15 ( V_24 -> V_39 , V_24 -> V_27 + V_40 ) ;
F_17 ( V_24 -> V_27 + V_47 ) ;
for ( V_38 = 100000 ; V_38 > 0 ; V_38 -- )
if ( ! ( F_17 ( V_24 -> V_27 + V_48 ) & 0x0004 ) )
break;
if ( V_38 ) {
V_20 [ 0 ] =
( F_17 ( V_24 -> V_27 +
V_49 ) ^ 0x800 ) & 0x0FFF ;
} else {
F_21 ( V_50 L_1 ,
V_2 -> V_51 ) ;
return - V_52 ;
}
V_24 -> V_39 &= 0xFFFC ;
F_15 ( V_24 -> V_39 , V_24 -> V_27 + V_40 ) ;
return 1 ;
}
static int F_22 ( struct V_15 * V_2 , struct V_16 * V_17 )
{
V_24 -> V_39 &= 0xFFFC ;
F_15 ( V_24 -> V_39 , V_24 -> V_27 + V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_15 * V_2 ,
struct V_16 * V_17 , struct V_53 * V_54 )
{
return 0 ;
}
static int F_24 ( struct V_15 * V_2 ,
struct V_16 * V_33 )
{
return 0 ;
}
static int F_25 ( struct V_15 * V_2 ,
struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
int V_35 ;
int V_36 ;
int V_38 ;
V_24 -> V_25 |= V_55 ;
F_15 ( V_24 -> V_25 , V_24 -> V_27 + V_28 ) ;
V_24 -> V_25 |= V_56 ;
F_15 ( V_24 -> V_25 , V_24 -> V_27 + V_28 ) ;
for ( V_38 = 0 ; V_38 < V_19 -> V_57 ; V_38 ++ ) {
V_35 = F_14 ( ( & V_19 -> V_23 ) [ V_38 ] ) ;
V_36 = F_19 ( ( & V_19 -> V_23 ) [ V_38 ] ) ;
V_24 -> V_58 &= ~ ( 0x0880 >> V_35 ) ;
if ( V_36 == 0 )
V_24 -> V_58 |=
( ( V_59 | V_60 ) >> V_35 ) ;
else if ( V_36 == 1 )
V_24 -> V_58 |=
( ( V_59 | V_61 ) >> V_35 ) ;
}
F_15 ( V_24 -> V_58 ,
V_24 -> V_27 + V_62 ) ;
F_17 ( V_24 -> V_27 + V_63 ) ;
for ( V_38 = 0 ; V_38 < V_19 -> V_57 ; V_38 ++ ) {
V_35 = F_14 ( ( & V_19 -> V_23 ) [ V_38 ] ) ;
F_15 ( ( V_20 [ 0 ] & V_17 -> V_64 ) ,
V_24 -> V_27 + V_65 + ( V_35 << 1 ) ) ;
V_24 -> V_66 [ V_35 ] = ( V_20 [ 0 ] & V_17 -> V_64 ) ;
}
F_17 ( V_24 -> V_27 + V_67 ) ;
return V_38 ;
}
static int F_26 ( struct V_15 * V_2 ,
struct V_16 * V_17 , struct V_18 * V_19 ,
unsigned int * V_20 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_19 -> V_57 ; V_38 ++ ) {
V_20 [ V_38 ] =
V_24 -> V_66 [ F_14 ( ( & V_19 -> V_23 ) [ V_38 ] ) ] ;
}
return 1 ;
}
static int F_27 ( struct V_15 * V_2 ,
unsigned char * V_68 ,
unsigned int V_69 )
{
unsigned int V_34 ;
unsigned int V_70 ;
unsigned int V_38 ;
F_28 ( 0x00 , V_24 -> V_71 + V_72 ) ;
V_34 = F_17 ( V_24 -> V_27 + V_73 ) ;
F_11 ( 1 ) ;
F_29 ( 0x00 , V_24 -> V_27 + 0x0 ) ;
F_11 ( 1 ) ;
if ( V_69 < 16 )
return - V_74 ;
V_70 = ( ( ( unsigned int ) V_68 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_68 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_68 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_68 [ 3 ] & 0xff ) ;
for ( V_38 = 0 ; V_38 < V_70 ; V_38 ++ )
F_29 ( ( V_68 [ 16 + V_38 ] & 0xff ) ,
V_24 -> V_27 + 0x0 ) ;
for ( V_38 = 0 ; V_38 < 5 ; V_38 ++ )
F_29 ( 0x00 , V_24 -> V_27 + 0x0 ) ;
V_34 = F_30 ( V_24 -> V_71 + V_72 ) ;
if ( V_34 & 0x20 ) {
F_28 ( 0x00 , V_24 -> V_71 + V_72 ) ;
F_21 ( V_50 L_2 ,
V_2 -> V_51 ) ;
return - V_52 ;
}
F_11 ( 1 ) ;
F_28 ( 0x43 , V_24 -> V_71 + V_72 ) ;
return 0 ;
}
static int F_31 ( struct V_15 * V_2 )
{
F_15 ( 0x00 , V_24 -> V_27 + V_40 ) ;
F_15 ( 0x00 , V_24 -> V_27 + V_28 ) ;
F_15 ( 0x00 , V_24 -> V_27 + V_43 ) ;
F_15 ( 0x00 , V_24 -> V_27 + V_62 ) ;
V_24 -> V_58 = 0 ;
V_24 -> V_39 = 0 ;
V_24 -> V_25 = 0 ;
return 0 ;
}
static int F_32 ( struct V_15 * V_2 , struct V_75 * V_76 )
{
struct V_1 * V_77 = NULL ;
struct V_16 * V_33 ;
struct V_78 * V_79 ;
T_5 V_80 ;
unsigned long V_81 ;
T_5 V_82 ;
unsigned long V_83 ;
T_5 V_84 ;
unsigned long V_85 ;
T_5 V_86 ;
int V_87 , error , V_38 ;
if ( F_33 ( V_2 , sizeof( struct V_88 ) ) < 0 )
return - V_89 ;
F_34 (pci_device) {
if ( V_77 -> V_90 == V_91 ) {
for ( V_38 = 0 ; V_38 < V_92 ; V_38 ++ ) {
if ( V_93 [ V_38 ] . V_94 ==
V_77 -> V_95 ) {
if ( ( V_76 -> V_96 [ 0 ] != 0 )
|| ( V_76 -> V_96 [ 1 ] != 0 ) ) {
if ( V_77 -> V_97 -> V_98 !=
V_76 -> V_96 [ 0 ]
||
F_35 ( V_77 -> V_99 )
!= V_76 -> V_96 [ 1 ] ) {
continue;
}
}
V_2 -> V_100 = V_93 + V_38 ;
V_79 =
(struct V_78 * ) V_2 -> V_100 ;
V_24 -> V_77 = V_77 ;
goto V_101;
}
}
}
}
F_21 ( V_50
L_3 ,
V_2 -> V_51 , V_76 -> V_96 [ 0 ] , V_76 -> V_96 [ 1 ] ) ;
return - V_52 ;
V_101:
F_21 ( V_102 L_4 ,
V_2 -> V_51 , V_93 [ V_38 ] . V_9 ,
V_77 -> V_97 -> V_98 , F_35 ( V_77 -> V_99 ) ) ;
if ( F_36 ( V_77 , V_103 ) < 0 ) {
F_21 ( V_50 L_5
L_6 , V_2 -> V_51 ) ;
return - V_52 ;
}
V_2 -> V_104 = V_79 -> V_9 ;
V_80 = F_37 ( V_77 , 0 ) ;
V_81 = F_38 ( V_77 , 0 ) ;
V_24 -> V_71 =
F_39 ( V_80 , V_81 ) ;
V_24 -> V_105 = V_81 ;
if ( ! V_24 -> V_71 ) {
F_21 ( L_7 , V_2 -> V_51 ) ;
return - V_89 ;
}
V_84 = F_37 ( V_77 , 5 ) ;
V_85 = F_38 ( V_77 , 5 ) ;
if ( ! V_84 )
F_21 ( V_50 L_8 , V_2 -> V_51 ) ;
if ( V_80 & 0x0080 ) {
F_21 ( V_50 L_9 , V_2 -> V_51 ) ;
if ( V_84 ) {
V_86 = V_80 ;
V_80 = V_84 ;
V_84 = V_86 ;
V_87 = F_40 ( V_77 ,
V_106 ,
V_80 ) ;
if ( V_87 != V_107 )
return - V_52 ;
V_87 = F_40 ( V_77 ,
V_108 ,
V_84 ) ;
if ( V_87 != V_107 )
return - V_52 ;
} else {
V_80 -= 0x80 ;
V_87 = F_40 ( V_77 ,
V_106 ,
V_80 ) ;
if ( V_87 != V_107 )
return - V_52 ;
}
}
V_82 = F_37 ( V_77 , 2 ) ;
V_83 = F_38 ( V_77 , 2 ) ;
V_24 -> V_109 = V_83 ;
V_24 -> V_27 = F_39 ( V_82 , V_83 ) ;
if ( ! V_24 -> V_27 ) {
F_21 ( V_50 L_7 ,
V_2 -> V_51 ) ;
return - V_89 ;
}
if ( V_79 -> V_94 == V_110 ) {
unsigned char * V_111 ;
int V_112 ;
V_111 = F_41 ( V_76 -> V_96 , 0 ) ;
V_112 = V_76 -> V_96 [ V_113 ] ;
if ( ! V_111 || V_112 < 1 ) {
F_42 ( V_2 , L_10
L_11
L_12 ) ;
return - V_74 ;
}
F_27 ( V_2 , V_111 , V_112 ) ;
}
F_31 ( V_2 ) ;
error = F_43 ( V_2 , 3 ) ;
if ( error < 0 )
return error ;
V_33 = V_2 -> V_114 + 0 ;
V_33 -> type = V_115 ;
V_33 -> V_116 = V_117 | V_118 | V_119 ;
V_33 -> V_120 = V_79 -> V_121 ;
V_33 -> V_64 = V_79 -> V_122 ;
V_33 -> V_123 = V_79 -> V_121 ;
V_33 -> V_124 = V_79 -> V_125 ;
V_33 -> V_126 = F_22 ;
V_33 -> V_127 = F_18 ;
V_33 -> V_128 = F_23 ;
V_33 -> V_129 = F_24 ;
V_33 = V_2 -> V_114 + 1 ;
V_33 -> type = V_130 ;
V_33 -> V_116 = V_131 | V_118 ;
V_33 -> V_120 = V_79 -> V_132 ;
V_33 -> V_64 = V_79 -> V_133 ;
V_33 -> V_123 = V_79 -> V_132 ;
V_33 -> V_124 = V_79 -> V_134 ;
V_33 -> V_127 = F_26 ;
V_33 -> V_135 = F_25 ;
V_33 = V_2 -> V_114 + 2 ;
V_33 -> type = V_136 ;
V_33 -> V_116 = V_117 | V_131 ;
V_33 -> V_120 = V_79 -> V_137 ;
V_33 -> V_64 = 1 ;
V_33 -> V_123 = V_79 -> V_137 ;
V_33 -> V_124 = & V_138 ;
V_33 -> V_139 = F_16 ;
V_33 -> V_140 = F_13 ;
V_33 -> V_30 = 0 ;
F_21 ( V_102 L_13 V_103 L_14 ,
V_2 -> V_51 ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_2 )
{
if ( V_24 ) {
if ( V_24 -> V_27 ) {
F_31 ( V_2 ) ;
F_45 ( V_24 -> V_27 ) ;
}
if ( V_24 -> V_71 )
F_45 ( V_24 -> V_71 ) ;
if ( V_24 -> V_77 ) {
if ( V_24 -> V_105 )
F_46 ( V_24 -> V_77 ) ;
F_47 ( V_24 -> V_77 ) ;
}
}
return 0 ;
}
