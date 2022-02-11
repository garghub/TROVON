static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned F_3 ( const struct V_4 * V_5 )
{
return F_4 ( V_5 ) ;
}
static inline unsigned F_5 ( const struct V_4 * V_5 )
{
return F_6 ( V_5 ) ;
}
static inline unsigned F_7 ( const struct V_4 * V_5 )
{
return F_8 ( V_5 ) ;
}
static inline unsigned F_9 ( const struct V_4 * V_5 )
{
return F_10 ( V_5 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_6 )
{
struct V_7 * V_8 = F_12 ( V_3 ) ;
return F_13 ( V_8 , V_6 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_9 )
{
struct V_7 * V_8 = F_12 ( V_3 ) ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_15 ( V_8 , V_6 , V_9 ) ;
if ( V_10 == 0 )
return 0 ;
}
F_16 ( V_3 , L_1 ) ;
return V_10 ;
}
static inline void
F_17 ( struct V_2 * V_3 , T_1 V_6 ,
T_2 V_12 , T_2 V_13 )
{
F_14 ( V_3 , V_6 , ( F_11 ( V_3 , V_6 ) & V_12 ) | V_13 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_14 * V_6 )
{
V_6 -> V_9 = F_11 ( V_3 , V_6 -> V_6 & 0xff ) ;
V_6 -> V_15 = 1 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
const struct V_14 * V_6 )
{
F_14 ( V_3 , V_6 -> V_6 & 0xff , V_6 -> V_9 & 0xff ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_2 V_17 = F_11 ( V_3 , V_18 ) ;
F_21 ( V_3 , L_2 ) ;
F_21 ( V_3 , L_3 , V_16 -> V_19 ) ;
F_21 ( V_3 , L_4 , ( V_17 & 0x0c ) ? L_5 : L_6 ) ;
F_21 ( V_3 , L_7 , ( V_17 & 0x01 ) ? L_5 : L_6 ) ;
F_21 ( V_3 , L_8 ,
( V_17 & 0x20 ) ? L_9 : L_10 ) ;
F_21 ( V_3 , L_11 ,
F_11 ( V_3 , V_20 ) * 256 +
F_11 ( V_3 , V_21 ) ,
( F_11 ( V_3 , V_22 ) & 0x07 ) * 256 +
F_11 ( V_3 , V_23 ) ) ;
F_22 ( V_3 -> V_24 , L_12 ,
& V_16 -> V_25 , true ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_26 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_24 ( 1 , V_27 , V_3 , L_13 , V_28 , V_26 ? L_6 : L_5 ) ;
V_16 -> V_29 = V_26 ;
F_17 ( V_3 , V_18 , 0xf2 , ( V_26 ? 0x00 : 0x0c ) ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , int V_30 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_30 && ! V_16 -> V_29 )
F_23 ( V_3 , true ) ;
F_17 ( V_3 , V_18 , 0xfe ,
( V_30 ? 0x01 : 0x00 ) ) ;
F_24 ( 1 , V_27 , V_3 , L_14 ,
V_28 , ( V_30 ? L_15 : L_16 ) ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
F_17 ( V_3 , V_18 , 0x3f , 0xc0 ) ;
F_14 ( V_3 , V_31 , 0x70 ) ;
F_14 ( V_3 , V_32 , 0x87 ) ;
F_14 ( V_3 , V_33 , 0x2a ) ;
F_14 ( V_3 , V_34 , 0x2a ) ;
}
static void F_27 ( struct V_2 * V_3 , struct V_4 * V_35 )
{
T_2 V_36 = 0 ;
T_3 V_37 = ( V_35 -> V_38 + V_35 -> V_39 ) ;
T_3 V_40 = ( F_9 ( V_35 ) - V_35 -> V_41 ) ;
F_25 ( V_3 , false ) ;
F_14 ( V_3 , V_42 , V_35 -> V_43 ) ;
F_14 ( V_3 , V_44 , V_35 -> V_45 ) ;
if ( ! V_35 -> V_46 )
F_14 ( V_3 , V_47 , 0x00 ) ;
F_14 ( V_3 , V_48 ,
( V_35 -> V_49 + V_35 -> V_43 ) & 0xff ) ;
F_14 ( V_3 , V_50 , 0x00 ) ;
F_14 ( V_3 , V_51 ,
( ( V_35 -> V_49 + V_35 -> V_43 ) & 0x100 ) >> 1 ) ;
F_14 ( V_3 , V_52 , ( V_35 -> V_45 ) & 0xff ) ;
F_14 ( V_3 , V_53 ,
( ( V_35 -> V_45 ) & 0x700 ) >> 8 ) ;
F_14 ( V_3 , V_54 , ( F_5 ( V_35 ) / 2 ) & 0xff ) ;
F_14 ( V_3 , V_55 ,
( ( F_5 ( V_35 ) / 2 ) >> 8 ) & 0x0f ) ;
F_14 ( V_3 , V_56 , F_5 ( V_35 ) >> 8 ) ;
F_14 ( V_3 , V_57 , F_5 ( V_35 ) & 0xff ) ;
F_14 ( V_3 , V_58 ,
( ( F_9 ( V_35 ) >> 4 ) & 0xf0 ) + 0x7 ) ;
F_14 ( V_3 , V_59 , F_9 ( V_35 ) & 0xff ) ;
if ( ! V_35 -> V_46 )
F_14 ( V_3 , V_60 , 0xff ) ;
F_17 ( V_3 , V_61 , 0x88 ,
( ( V_37 >> 4 ) & 0x70 ) +
( ( V_40 >> 8 ) & 0x07 ) ) ;
F_14 ( V_3 , V_62 , ( ( F_9 ( V_35 ) ) >> 4 ) & 0x70 ) ;
F_14 ( V_3 , V_63 , V_37 & 0xff ) ;
F_14 ( V_3 , V_64 , V_40 & 0xff ) ;
F_14 ( V_3 , V_65 , ( F_9 ( V_35 ) ) & 0xff ) ;
F_14 ( V_3 , V_66 , 0x90 ) ;
F_14 ( V_3 , V_67 , 0x90 ) ;
F_14 ( V_3 , V_68 , V_35 -> V_43 & 0xff ) ;
F_17 ( V_3 , V_69 , 0x3f ,
( V_35 -> V_43 >> 2 ) & 0xc0 ) ;
F_17 ( V_3 , V_69 , 0xe0 ,
( F_5 ( V_35 ) >> 8 ) & 0x1f ) ;
F_14 ( V_3 , V_70 , F_5 ( V_35 ) ) ;
F_14 ( V_3 , V_71 , ( V_35 -> V_38 ) & 0xff ) ;
F_17 ( V_3 , V_72 , 0x3f ,
( ( V_35 -> V_38 ) >> 2 ) & 0xc0 ) ;
F_17 ( V_3 , V_72 , 0xf8 ,
( F_9 ( V_35 ) >> 8 ) & 0x7 ) ;
F_14 ( V_3 , V_73 , F_9 ( V_35 ) ) ;
F_14 ( V_3 , V_74 , 0x00 ) ;
F_14 ( V_3 , V_75 , 0x07 ) ;
F_14 ( V_3 , V_76 , 0xff ) ;
F_14 ( V_3 , V_77 , ( F_5 ( V_35 ) >> 8 ) & 0x1f ) ;
F_14 ( V_3 , V_78 , ( F_5 ( V_35 ) - 4 ) & 0xff ) ;
F_14 ( V_3 , V_79 , 0 ) ;
F_14 ( V_3 , V_80 , 1 ) ;
if ( V_35 -> V_81 & V_82 ) {
V_36 |= 0x01 ;
V_36 |= 0x08 ;
}
if ( V_35 -> V_81 & V_83 ) {
V_36 |= 0x02 ;
V_36 |= 0x10 ;
}
F_14 ( V_3 , V_84 , 0x47 | V_36 ) ;
F_25 ( V_3 , true ) ;
F_24 ( 1 , V_27 , V_3 , L_17
L_18
L_19 , V_28 , F_5 ( V_35 ) , F_9 ( V_35 ) ,
V_36 , V_35 -> V_45 , V_35 -> V_49 ,
V_35 -> V_43 , V_35 -> V_38 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_24 ( 1 , V_27 , V_3 , L_20 , V_28 ) ;
if ( ! F_29 ( V_86 , & V_87 ,
NULL , NULL ) )
return - V_88 ;
if ( ! F_30 ( V_86 , & V_87 , 10 ,
NULL , NULL ) ) {
F_24 ( 1 , V_27 , V_3 , L_21 ) ;
return - V_88 ;
}
V_86 -> V_35 . V_89 &= ~ V_90 ;
V_16 -> V_25 = * V_86 ;
F_27 ( V_3 , & V_86 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_24 ( 1 , V_27 , V_3 , L_20 , V_28 ) ;
* V_86 = V_16 -> V_25 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_91 * V_86 )
{
return F_33 ( V_86 , & V_87 ,
NULL , NULL ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_92 * V_93 )
{
* V_93 = V_87 ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 ,
const struct V_94 * V_95 )
{
struct V_1 * V_16 ;
struct V_2 * V_3 ;
int error ;
if ( ! F_36 ( V_8 -> V_96 , V_97 ) )
return - V_98 ;
V_16 = F_37 ( & V_8 -> V_99 , sizeof( * V_16 ) , V_100 ) ;
if ( ! V_16 )
return - V_101 ;
V_3 = & V_16 -> V_3 ;
F_38 ( V_3 , V_8 , & V_102 ) ;
V_16 -> V_19 = F_11 ( V_3 , V_103 ) ;
F_24 ( 1 , V_27 , V_3 , L_22 , V_16 -> V_19 ) ;
F_26 ( V_3 ) ;
error = F_39 ( & V_16 -> V_3 ) ;
if ( error )
return error ;
F_21 ( V_3 , L_23 , V_8 -> V_24 ,
V_8 -> V_104 << 1 , V_8 -> V_96 -> V_24 ) ;
return 0 ;
}
static int F_40 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_41 ( V_8 ) ;
struct V_1 * V_105 = F_1 ( V_3 ) ;
F_24 ( 1 , V_27 , V_3 , L_24 , V_8 -> V_24 ,
V_8 -> V_104 << 1 , V_8 -> V_96 -> V_24 ) ;
F_23 ( V_3 , false ) ;
F_42 ( & V_105 -> V_3 ) ;
F_43 ( V_3 ) ;
return 0 ;
}
