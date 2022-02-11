static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
V_2 -> V_7 . V_8 -> V_9 ( & V_2 -> V_7 ) ;
V_5 = F_3 ( V_4 -> V_10 + V_11 ) & 0x0f00 ;
if ( V_5 ) {
unsigned int V_12 ;
V_12 = V_4 -> V_13 ;
for ( V_6 = 0 ; V_6 <= 3 ; V_6 ++ , V_12 ++ ) {
if ( V_5 & ( 0x0100 << V_6 ) ) {
F_4 ( V_12 ) ;
}
}
}
}
static void F_5 ( struct V_7 * V_14 )
{
}
static void F_6 ( struct V_7 * V_14 )
{
struct V_3 * V_4 = F_7 ( V_14 ) ;
unsigned int V_15 ;
V_15 = F_3 ( V_4 -> V_10 + V_11 ) ;
V_15 &= ~ ( 0x0010 << ( V_14 -> V_12 - V_4 -> V_13 ) ) ;
F_8 ( V_15 , V_4 -> V_10 + V_11 ) ;
}
static void F_9 ( struct V_7 * V_14 )
{
struct V_3 * V_4 = F_7 ( V_14 ) ;
unsigned int V_15 ;
V_15 = F_3 ( V_4 -> V_10 + V_11 ) ;
V_15 |= ( 0x0010 << ( V_14 -> V_12 - V_4 -> V_13 ) ) ;
F_8 ( V_15 , V_4 -> V_10 + V_11 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
int V_12 = V_4 -> V_13 ;
F_11 ( V_4 -> V_12 , V_16 ) ;
F_12 ( V_4 -> V_12 , F_1 , V_4 ) ;
for ( ; V_12 <= V_4 -> V_13 + 3 ; V_12 ++ ) {
F_13 ( V_12 , & V_17 , V_18 ) ;
F_14 ( V_12 , V_4 ) ;
F_15 ( V_12 , V_19 | V_20 ) ;
}
}
static void F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_17 ( V_22 ) ;
F_18 ( V_24 ) ;
}
static int
F_19 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_20 ( sizeof( struct V_23 ) , V_28 ) ;
if ( ! V_24 ) {
V_27 = - V_29 ;
goto V_30;
}
if ( V_4 -> V_24 -> V_31 ) {
V_24 -> V_31 = * V_4 -> V_24 -> V_31 ;
V_24 -> V_24 . V_31 = & V_24 -> V_31 ;
}
F_21 ( & V_24 -> V_24 , L_1 , V_26 -> V_32 ) ;
V_24 -> V_33 = V_26 -> V_33 ;
V_24 -> V_24 . V_34 = V_4 -> V_24 ;
V_24 -> V_24 . V_35 = & V_36 ;
V_24 -> V_24 . V_37 = F_16 ;
V_24 -> V_24 . V_38 = V_4 -> V_24 -> V_38 ;
if ( V_26 -> V_39 )
V_24 -> V_40 = V_4 -> V_10 + V_26 -> V_39 ;
else
V_24 -> V_40 = 0 ;
V_24 -> V_41 = V_26 -> V_41 ;
V_24 -> V_12 [ 0 ] = ( V_4 -> V_13 == V_42 ) ?
V_42 : V_4 -> V_13 + V_26 -> V_12 [ 0 ] ;
V_27 = F_22 ( & V_24 -> V_24 ) ;
if ( V_27 ) {
V_30:
F_18 ( V_24 ) ;
}
return V_27 ;
}
static int F_23 ( struct V_43 * V_24 , T_1 V_44 )
{
struct V_3 * V_4 = F_24 ( V_24 ) ;
struct V_45 * V_46 ;
unsigned long V_47 ;
V_46 = F_25 ( sizeof( struct V_45 ) , V_28 ) ;
if ( ! V_46 )
return - V_29 ;
V_4 -> V_48 = V_46 ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
V_46 -> V_50 = F_3 ( V_4 -> V_10 + V_51 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_51 ) ;
V_46 -> V_52 = F_3 ( V_4 -> V_10 + V_53 + V_54 ) ;
F_8 ( 0x40 , V_4 -> V_10 + V_53 + V_54 ) ;
V_46 -> V_55 = F_3 ( V_4 -> V_10 + V_56 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_56 ) ;
V_46 -> V_57 = F_3 ( V_4 -> V_10 + V_58 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_58 ) ;
V_46 -> V_59 = F_3 ( V_4 -> V_10 + V_53 + V_60 ) ;
F_8 ( 0x3C14 , V_4 -> V_10 + V_53 + V_60 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_61 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_62 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_63 + V_64 ) ;
if ( ( F_3 ( V_4 -> V_10 + V_65 + V_66 ) & 0x88 ) && ( F_3 ( V_4 -> V_10 + V_65 + V_67 ) & 0x88 ) )
F_8 ( 0x00 , V_4 -> V_10 + V_68 ) ;
else
F_8 ( 0xc1 , V_4 -> V_10 + V_68 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_69 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_70 + V_71 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_72 + V_73 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
return 0 ;
}
static int F_28 ( struct V_43 * V_24 )
{
struct V_3 * V_4 = F_24 ( V_24 ) ;
struct V_45 * V_46 ;
unsigned long V_15 ;
unsigned long V_47 ;
V_46 = V_4 -> V_48 ;
if ( ! V_46 )
return 0 ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
F_8 ( V_46 -> V_50 , V_4 -> V_10 + V_51 ) ;
F_8 ( V_46 -> V_52 , V_4 -> V_10 + V_53 + V_54 ) ;
F_8 ( V_46 -> V_55 , V_4 -> V_10 + V_56 ) ;
F_8 ( V_46 -> V_57 , V_4 -> V_10 + V_58 ) ;
F_8 ( V_46 -> V_59 , V_4 -> V_10 + V_53 + V_60 ) ;
F_8 ( 0x00 , V_4 -> V_10 + V_68 ) ;
F_8 ( 0x90 , V_4 -> V_10 + V_69 ) ;
F_8 ( 0 , V_4 -> V_10 + V_74 + V_75 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_74 + V_76 ) ;
V_15 &= 0xFEFF ;
F_8 ( V_15 , V_4 -> V_10 + V_74 + V_76 ) ;
F_8 ( 0x1 , V_4 -> V_10 + V_74 + V_77 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
V_4 -> V_48 = NULL ;
F_18 ( V_46 ) ;
return 0 ;
}
static int
F_29 ( struct V_21 * V_78 , struct V_79 * V_80 , int V_12 )
{
struct V_81 * V_82 = V_78 -> V_83 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
int V_6 , V_27 = - V_84 ;
V_4 = F_20 ( sizeof( struct V_3 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
F_30 ( & V_4 -> V_49 ) ;
V_4 -> V_24 = V_78 ;
F_31 ( V_4 -> V_24 , V_4 ) ;
V_4 -> V_85 = V_80 -> V_86 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_13 = ( V_82 ) ? V_82 -> V_13 : V_42 ;
V_4 -> V_10 = F_32 ( V_80 -> V_86 , V_87 ) ;
if ( ! V_4 -> V_10 ) {
V_27 = - V_29 ;
goto V_30;
}
F_8 ( 0 , V_4 -> V_10 + V_11 ) ;
F_8 ( 0 , V_4 -> V_10 + V_74 + V_76 ) ;
F_8 ( 0 , V_4 -> V_10 + V_51 ) ;
F_8 ( ( F_33 ( 1 ) | F_33 ( 2 ) | F_33 ( 13 ) | F_33 ( 14 ) )
, V_4 -> V_10 + V_56 ) ;
F_8 ( ( F_33 ( 1 ) | F_33 ( 2 ) | F_33 ( 13 ) | F_33 ( 14 ) )
, V_4 -> V_10 + V_88 ) ;
F_8 ( 0 , V_4 -> V_10 + V_89 ) ;
F_8 ( 0 , V_4 -> V_10 + V_72 + V_73 ) ;
F_8 ( 0 , V_4 -> V_10 + V_72 + V_90 ) ;
F_8 ( 0 , V_4 -> V_10 + V_91 ) ;
F_8 ( 0 , V_4 -> V_10 + V_53 + V_92 ) ;
F_8 ( 6 + 8 + 320 + 30 - 10 , V_4 -> V_10 + V_58 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_58 ) ;
V_15 |= 0x8000 ;
F_8 ( V_15 , V_4 -> V_10 + V_58 ) ;
F_8 ( 6 + 8 + 320 + 30 - 10 - 128 + 4 , V_4 -> V_10 + V_93 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_93 ) ;
V_15 |= 0x8000 ;
F_8 ( V_15 , V_4 -> V_10 + V_93 ) ;
F_8 ( 128 / 8 , V_4 -> V_10 + V_94 ) ;
F_8 ( 0x80 , V_4 -> V_10 + V_69 ) ;
F_34 ( 1000 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_69 ) ;
V_15 |= 0x10 ;
F_8 ( V_15 , V_4 -> V_10 + V_69 ) ;
F_34 ( 100 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_62 ) ;
V_15 |= V_95 | V_96 ;
F_8 ( V_15 , V_4 -> V_10 + V_62 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_97 ) ;
F_35 ( V_98 L_2 , ( V_15 >> 8 ) , ( V_15 & 0xff ) ) ;
if ( V_4 -> V_12 != V_42 && V_4 -> V_13 != V_42 )
F_10 ( V_4 ) ;
for ( V_6 = 0 ; V_6 < F_36 ( V_99 ) ; V_6 ++ )
F_19 ( V_4 , & V_99 [ V_6 ] ) ;
return 0 ;
V_30:
F_18 ( V_4 ) ;
return V_27 ;
}
static int F_37 ( struct V_21 * V_24 , void * V_100 )
{
F_38 ( V_24 ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_24 , NULL , F_37 ) ;
if ( V_4 -> V_12 != V_42 ) {
F_12 ( V_4 -> V_12 , NULL , NULL ) ;
}
F_41 ( V_4 -> V_10 ) ;
F_18 ( V_4 ) ;
}
static int F_42 ( struct V_43 * V_24 )
{
struct V_79 * V_80 ;
int V_12 ;
V_80 = F_43 ( V_24 , V_101 , 0 ) ;
if ( ! V_80 )
return - V_102 ;
V_12 = F_44 ( V_24 , 0 ) ;
if ( V_12 < 0 )
return - V_103 ;
return F_29 ( & V_24 -> V_24 , V_80 , V_12 ) ;
}
static int F_45 ( struct V_43 * V_24 )
{
struct V_3 * V_4 = F_24 ( V_24 ) ;
if ( V_4 ) {
F_39 ( V_4 ) ;
F_46 ( V_24 , NULL ) ;
}
return 0 ;
}
static inline struct V_3 * F_47 ( struct V_23 * V_104 )
{
return (struct V_3 * ) F_48 ( V_104 -> V_24 . V_34 ) ;
}
void F_49 ( struct V_21 * V_24 , unsigned int V_105 , unsigned int V_106 )
{
struct V_3 * V_4 = F_48 ( V_24 ) ;
unsigned long V_47 ;
unsigned int V_15 ;
if ( ! V_4 )
return;
F_26 ( & V_4 -> V_49 , V_47 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_88 ) ;
if ( V_106 )
V_15 |= V_105 ;
else
V_15 &= ~ V_105 ;
F_8 ( V_15 , V_4 -> V_10 + V_88 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_56 ) ;
if ( V_106 )
V_15 |= V_105 ;
else
V_15 &= ~ V_105 ;
F_8 ( V_15 , V_4 -> V_10 + V_56 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
}
int F_50 ( struct V_21 * V_24 , unsigned int V_105 )
{
struct V_3 * V_4 = F_48 ( V_24 ) ;
unsigned long V_47 ;
unsigned int V_27 ;
if ( ! V_4 )
return - V_84 ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
V_27 = F_3 ( V_4 -> V_10 + V_107 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
V_27 &= V_105 ;
return V_27 ;
}
int F_51 ( struct V_21 * V_24 , unsigned int V_105 )
{
struct V_3 * V_4 = F_48 ( V_24 ) ;
unsigned long V_47 ;
unsigned int V_27 ;
if ( ! V_4 )
return - V_84 ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
V_27 = F_3 ( V_4 -> V_10 + V_51 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
V_27 &= V_105 ;
return V_27 ;
}
void F_52 ( struct V_21 * V_24 , unsigned int V_105 , unsigned int V_108 )
{
struct V_3 * V_4 = F_48 ( V_24 ) ;
unsigned long V_47 ;
unsigned int V_15 ;
if ( ! V_4 )
return;
F_26 ( & V_4 -> V_49 , V_47 ) ;
V_15 = F_3 ( V_4 -> V_10 + V_51 ) ;
if ( V_108 )
V_15 |= V_105 ;
else
V_15 &= ~ V_105 ;
F_8 ( V_15 , V_4 -> V_10 + V_51 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
}
static void F_53 ( void * V_40 , int V_109 )
{
unsigned int V_15 ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_111 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
if ( V_109 & 1 ) {
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_96 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
} else {
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_96 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
}
F_34 ( V_114 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
}
void F_54 ( struct V_23 * V_104 , unsigned int V_116 , int V_117 )
{
struct V_3 * V_4 = F_47 ( V_104 ) ;
int V_6 ;
unsigned char V_100 ;
unsigned int V_15 ;
void * V_40 = V_4 -> V_10 ;
unsigned long V_47 ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
F_34 ( V_118 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 | V_96 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_96 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_119 ) ;
F_34 ( V_111 ) ;
V_100 = ( V_120 << 1 ) | V_121 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
F_53 ( V_40 , V_100 >> ( 8 - V_6 ) ) ;
}
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_96 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
if ( F_3 ( V_40 + V_62 ) & V_96 ) {
F_35 ( V_122 L_3 ) ;
goto V_30;
}
V_100 = V_123 + V_117 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
F_53 ( V_40 , V_100 >> ( 8 - V_6 ) ) ;
}
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_96 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
if ( F_3 ( V_40 + V_62 ) & V_96 ) {
F_35 ( V_122 L_4 ) ;
goto V_30;
}
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
F_53 ( V_40 , V_116 >> ( 8 - V_6 ) ) ;
}
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_96 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
if ( F_3 ( V_40 + V_62 ) & V_96 ) {
F_35 ( V_122 L_5 ) ;
}
V_30:
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 &= ~ ( V_95 ) ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_96 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_113 ) ;
F_34 ( V_115 ) ;
V_15 = F_3 ( V_40 + V_62 ) ;
V_15 |= V_95 | V_96 ;
F_8 ( V_15 , V_40 + V_62 ) ;
F_34 ( V_110 ) ;
F_34 ( V_112 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
}
void F_55 ( struct V_23 * V_24 , int V_124 , int V_125 , int V_126 )
{
unsigned long V_47 ;
struct V_3 * V_4 = F_47 ( V_24 ) ;
if ( V_125 )
F_52 ( V_24 -> V_24 . V_34 , V_127 , 1 ) ;
else
F_52 ( V_24 -> V_24 . V_34 , V_127 , 0 ) ;
F_26 ( & V_4 -> V_49 , V_47 ) ;
F_8 ( V_126 , V_4 -> V_10 + V_72 + V_73 ) ;
F_34 ( 100 ) ;
F_8 ( V_124 , V_4 -> V_10 + V_72 + V_90 ) ;
F_8 ( V_126 | V_128 , V_4 -> V_10 + V_72 + V_73 ) ;
F_27 ( & V_4 -> V_49 , V_47 ) ;
}
static int F_56 ( struct V_21 * V_22 , struct V_129 * V_130 )
{
struct V_23 * V_24 = F_17 ( V_22 ) ;
struct V_131 * V_132 = F_57 ( V_130 ) ;
return V_24 -> V_33 == V_132 -> V_33 ;
}
static int F_58 ( struct V_21 * V_24 , T_1 V_44 )
{
struct V_23 * V_104 = F_17 ( V_24 ) ;
struct V_131 * V_132 = F_57 ( V_24 -> V_133 ) ;
int V_27 = 0 ;
if ( V_132 && V_132 -> V_134 )
V_27 = V_132 -> V_134 ( V_104 , V_44 ) ;
return V_27 ;
}
static int F_59 ( struct V_21 * V_24 )
{
struct V_23 * V_104 = F_17 ( V_24 ) ;
struct V_131 * V_132 = F_57 ( V_24 -> V_133 ) ;
int V_27 = 0 ;
if ( V_132 && V_132 -> V_135 )
V_27 = V_132 -> V_135 ( V_104 ) ;
return V_27 ;
}
static int F_60 ( struct V_21 * V_24 )
{
struct V_23 * V_104 = F_17 ( V_24 ) ;
struct V_131 * V_132 = F_57 ( V_24 -> V_133 ) ;
int V_27 = - V_84 ;
if ( V_132 -> V_136 )
V_27 = V_132 -> V_136 ( V_104 ) ;
return V_27 ;
}
static int F_61 ( struct V_21 * V_24 )
{
struct V_23 * V_104 = F_17 ( V_24 ) ;
struct V_131 * V_132 = F_57 ( V_24 -> V_133 ) ;
int V_27 = 0 ;
if ( V_132 -> remove )
V_27 = V_132 -> remove ( V_104 ) ;
return V_27 ;
}
int F_62 ( struct V_131 * V_133 )
{
V_133 -> V_132 . V_35 = & V_36 ;
return F_63 ( & V_133 -> V_132 ) ;
}
void F_64 ( struct V_131 * V_133 )
{
F_65 ( & V_133 -> V_132 ) ;
}
static int T_2 F_66 ( void )
{
int V_27 = F_67 ( & V_36 ) ;
if ( V_27 == 0 )
F_68 ( & V_137 ) ;
return V_27 ;
}
static void T_3 F_69 ( void )
{
F_70 ( & V_137 ) ;
F_71 ( & V_36 ) ;
}
