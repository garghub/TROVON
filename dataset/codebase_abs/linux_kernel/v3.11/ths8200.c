static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned F_3 ( const struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_7 + V_5 -> V_8 ;
}
static inline unsigned F_4 ( const struct V_4 * V_5 )
{
return V_5 -> V_9 + V_5 -> V_6 + V_5 -> V_7 + V_5 -> V_8 ;
}
static inline unsigned F_5 ( const struct V_4 * V_5 )
{
return V_5 -> V_10 + V_5 -> V_11 + V_5 -> V_12 ;
}
static inline unsigned F_6 ( const struct V_4 * V_5 )
{
return V_5 -> V_13 + V_5 -> V_10 + V_5 -> V_11 + V_5 -> V_12 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_15 * V_16 = F_8 ( V_3 ) ;
return F_9 ( V_16 , V_14 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_14 , T_1 V_17 )
{
struct V_15 * V_16 = F_8 ( V_3 ) ;
int V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
V_18 = F_11 ( V_16 , V_14 , V_17 ) ;
if ( V_18 == 0 )
return 0 ;
}
F_12 ( V_3 , L_1 ) ;
return V_18 ;
}
static inline void
F_13 ( struct V_2 * V_3 , T_1 V_14 ,
T_2 V_20 , T_2 V_21 )
{
F_10 ( V_3 , V_14 , ( F_7 ( V_3 , V_14 ) & V_20 ) | V_21 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_22 * V_14 )
{
V_14 -> V_17 = F_7 ( V_3 , V_14 -> V_14 & 0xff ) ;
V_14 -> V_23 = 1 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_22 * V_14 )
{
F_10 ( V_3 , V_14 -> V_14 & 0xff , V_14 -> V_17 & 0xff ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_24 * V_25 ,
const char * V_26 , bool V_27 )
{
struct V_4 * V_28 = & V_25 -> V_28 ;
T_3 V_29 , V_30 ;
if ( V_25 -> type != V_31 )
return;
V_29 = F_4 ( V_28 ) ;
V_30 = F_6 ( V_28 ) ;
F_17 ( V_3 , L_2 ,
V_26 , V_28 -> V_9 , V_28 -> V_13 , V_28 -> V_32 ? L_3 : L_4 ,
( V_29 * V_30 ) > 0 ? ( ( T_3 ) V_28 -> V_33 / ( V_29 * V_30 ) ) : 0 ,
V_29 , V_30 ) ;
if ( V_27 ) {
F_17 ( V_3 , L_5 ,
V_28 -> V_6 ,
( V_28 -> V_34 & V_35 ) ? L_6 : L_7 ,
V_28 -> V_7 , V_28 -> V_8 ) ;
F_17 ( V_3 , L_8 ,
V_28 -> V_10 ,
( V_28 -> V_34 & V_36 ) ? L_6 : L_7 ,
V_28 -> V_11 , V_28 -> V_12 ) ;
F_17 ( V_3 ,
L_9 ,
V_28 -> V_33 , V_28 -> V_37 , V_28 -> V_38 ) ;
}
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
T_2 V_40 = F_7 ( V_3 , V_41 ) ;
F_17 ( V_3 , L_10 ) ;
F_17 ( V_3 , L_11 , V_39 -> V_42 ) ;
F_17 ( V_3 , L_12 , ( V_40 & 0x0c ) ? L_13 : L_14 ) ;
F_17 ( V_3 , L_15 , ( V_40 & 0x01 ) ? L_13 : L_14 ) ;
F_17 ( V_3 , L_16 ,
( V_40 & 0x20 ) ? L_17 : L_18 ) ;
F_17 ( V_3 , L_19 ,
F_7 ( V_3 , V_43 ) * 256 +
F_7 ( V_3 , V_44 ) ,
( F_7 ( V_3 , V_45 ) & 0x07 ) * 256 +
F_7 ( V_3 , V_46 ) ) ;
F_16 ( V_3 , & V_39 -> V_47 ,
L_20 , true ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , int V_48 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
F_20 ( 1 , V_49 , V_3 , L_21 , V_50 , V_48 ? L_14 : L_13 ) ;
V_39 -> V_51 = V_48 ;
F_13 ( V_3 , V_41 , 0xf2 , ( V_48 ? 0x00 : 0x0c ) ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_52 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
if ( V_52 && ! V_39 -> V_51 )
F_19 ( V_3 , true ) ;
F_13 ( V_3 , V_41 , 0xfe ,
( V_52 ? 0x01 : 0x00 ) ) ;
F_20 ( 1 , V_49 , V_3 , L_22 ,
V_50 , ( V_52 ? L_23 : L_24 ) ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_3 )
{
F_13 ( V_3 , V_41 , 0x3f , 0xc0 ) ;
F_10 ( V_3 , V_53 , 0x70 ) ;
F_10 ( V_3 , V_54 , 0x87 ) ;
F_10 ( V_3 , V_55 , 0x2a ) ;
F_10 ( V_3 , V_56 , 0x2a ) ;
}
static void F_23 ( struct V_2 * V_3 , struct V_4 * V_28 )
{
T_2 V_57 = 0 ;
T_4 V_58 = ( V_28 -> V_11 + V_28 -> V_12 ) ;
T_4 V_59 = ( F_6 ( V_28 ) - V_28 -> V_10 ) ;
F_21 ( V_3 , false ) ;
F_10 ( V_3 , V_60 , V_28 -> V_7 ) ;
F_10 ( V_3 , V_61 , V_28 -> V_6 ) ;
if ( ! V_28 -> V_32 )
F_10 ( V_3 , V_62 , 0x00 ) ;
F_10 ( V_3 , V_63 ,
( V_28 -> V_8 + V_28 -> V_7 ) & 0xff ) ;
F_10 ( V_3 , V_64 , 0x00 ) ;
F_10 ( V_3 , V_65 ,
( ( V_28 -> V_8 + V_28 -> V_7 ) & 0x100 ) >> 1 ) ;
F_10 ( V_3 , V_66 , ( V_28 -> V_6 ) & 0xff ) ;
F_10 ( V_3 , V_67 ,
( ( V_28 -> V_6 ) & 0x700 ) >> 8 ) ;
F_10 ( V_3 , V_68 , ( F_4 ( V_28 ) / 2 ) & 0xff ) ;
F_10 ( V_3 , V_69 ,
( ( F_4 ( V_28 ) / 2 ) >> 8 ) & 0x0f ) ;
F_10 ( V_3 , V_70 , F_4 ( V_28 ) >> 8 ) ;
F_10 ( V_3 , V_71 , F_4 ( V_28 ) & 0xff ) ;
F_10 ( V_3 , V_72 ,
( ( F_6 ( V_28 ) >> 4 ) & 0xf0 ) + 0x7 ) ;
F_10 ( V_3 , V_73 , F_6 ( V_28 ) & 0xff ) ;
if ( ! V_28 -> V_32 )
F_10 ( V_3 , V_74 , 0xff ) ;
F_13 ( V_3 , V_75 , 0x88 ,
( ( V_58 >> 4 ) & 0x70 ) +
( ( V_59 >> 8 ) & 0x07 ) ) ;
F_10 ( V_3 , V_76 , ( ( F_6 ( V_28 ) ) >> 4 ) & 0x70 ) ;
F_10 ( V_3 , V_77 , V_58 & 0xff ) ;
F_10 ( V_3 , V_78 , V_59 & 0xff ) ;
F_10 ( V_3 , V_79 , ( F_6 ( V_28 ) ) & 0xff ) ;
F_10 ( V_3 , V_80 , 0x90 ) ;
F_10 ( V_3 , V_81 , 0x90 ) ;
F_10 ( V_3 , V_82 , V_28 -> V_7 & 0xff ) ;
F_13 ( V_3 , V_83 , 0x3f ,
( V_28 -> V_7 >> 2 ) & 0xc0 ) ;
F_13 ( V_3 , V_83 , 0xe0 ,
( F_4 ( V_28 ) >> 8 ) & 0x1f ) ;
F_10 ( V_3 , V_84 , F_4 ( V_28 ) ) ;
F_10 ( V_3 , V_85 , ( V_28 -> V_11 ) & 0xff ) ;
F_13 ( V_3 , V_86 , 0x3f ,
( ( V_28 -> V_11 ) >> 2 ) & 0xc0 ) ;
F_13 ( V_3 , V_86 , 0xf8 ,
( F_6 ( V_28 ) >> 8 ) & 0x7 ) ;
F_10 ( V_3 , V_87 , F_6 ( V_28 ) ) ;
F_10 ( V_3 , V_88 , 0x00 ) ;
F_10 ( V_3 , V_89 , 0x07 ) ;
F_10 ( V_3 , V_90 , 0xff ) ;
F_10 ( V_3 , V_91 , ( F_4 ( V_28 ) >> 8 ) & 0x1f ) ;
F_10 ( V_3 , V_92 , ( F_4 ( V_28 ) - 4 ) & 0xff ) ;
F_10 ( V_3 , V_93 , 0 ) ;
F_10 ( V_3 , V_94 , 1 ) ;
if ( V_28 -> V_34 & V_35 ) {
V_57 |= 0x01 ;
V_57 |= 0x08 ;
}
if ( V_28 -> V_34 & V_36 ) {
V_57 |= 0x02 ;
V_57 |= 0x10 ;
}
F_10 ( V_3 , V_95 , 0x47 | V_57 ) ;
F_21 ( V_3 , true ) ;
F_20 ( 1 , V_49 , V_3 , L_25
L_26
L_27 , V_50 , F_4 ( V_28 ) , F_6 ( V_28 ) ,
V_57 , V_28 -> V_6 , V_28 -> V_8 ,
V_28 -> V_7 , V_28 -> V_11 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
int V_19 ;
F_20 ( 1 , V_49 , V_3 , L_28 , V_50 ) ;
if ( V_25 -> type != V_31 )
return - V_96 ;
if ( V_25 -> V_28 . V_32 ) {
F_20 ( 1 , V_49 , V_3 , L_29 ) ;
return - V_96 ;
}
for ( V_19 = 0 ; V_19 < F_25 ( V_97 ) ; V_19 ++ ) {
if ( F_26 ( & V_97 [ V_19 ] , V_25 , 10 ) )
break;
}
if ( V_19 == F_25 ( V_97 ) ) {
F_20 ( 1 , V_49 , V_3 , L_30 ) ;
return - V_96 ;
}
V_25 -> V_28 . V_37 &= ~ V_98 ;
V_39 -> V_47 = * V_25 ;
F_23 ( V_3 , & V_25 -> V_28 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
F_20 ( 1 , V_49 , V_3 , L_28 , V_50 ) ;
* V_25 = V_39 -> V_47 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_99 * V_25 )
{
if ( V_25 -> V_100 >= F_25 ( V_97 ) )
return - V_96 ;
V_25 -> V_25 = V_97 [ V_25 -> V_100 ] ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_101 * V_102 )
{
V_102 -> type = V_31 ;
V_102 -> V_28 . V_103 = 1920 ;
V_102 -> V_28 . V_104 = 1080 ;
V_102 -> V_28 . V_105 = 27000000 ;
V_102 -> V_28 . V_106 = 148500000 ;
V_102 -> V_28 . V_38 = V_107 ;
V_102 -> V_28 . V_108 = V_109 ;
return 0 ;
}
static int F_30 ( struct V_15 * V_16 ,
const struct V_110 * V_111 )
{
struct V_1 * V_39 ;
struct V_2 * V_3 ;
if ( ! F_31 ( V_16 -> V_112 , V_113 ) )
return - V_114 ;
V_39 = F_32 ( & V_16 -> V_115 , sizeof( * V_39 ) , V_116 ) ;
if ( ! V_39 )
return - V_117 ;
V_3 = & V_39 -> V_3 ;
F_33 ( V_3 , V_16 , & V_118 ) ;
V_39 -> V_42 = F_7 ( V_3 , V_119 ) ;
F_20 ( 1 , V_49 , V_3 , L_31 , V_39 -> V_42 ) ;
F_22 ( V_3 ) ;
F_17 ( V_3 , L_32 , V_16 -> V_120 ,
V_16 -> V_121 << 1 , V_16 -> V_112 -> V_120 ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_35 ( V_16 ) ;
F_20 ( 1 , V_49 , V_3 , L_33 , V_16 -> V_120 ,
V_16 -> V_121 << 1 , V_16 -> V_112 -> V_120 ) ;
F_19 ( V_3 , false ) ;
F_36 ( V_3 ) ;
return 0 ;
}
