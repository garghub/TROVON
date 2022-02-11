static inline T_1 F_1 (
const struct V_1 * clock )
{
return ( ( clock -> V_2 & 0xf ) << 12 ) | ( clock -> clock & 0x03ff ) ;
}
static inline T_1 F_2 ( const struct V_3 * V_4 )
{
return ( ( V_4 -> V_5 & 0xf ) << 12 ) |
( ( V_4 -> V_6 & 0xf ) << 8 ) |
( ( V_4 -> V_7 & 0x1 ) << 7 ) |
( ( V_4 -> V_8 & 0x7 ) << 4 ) |
( ( V_4 -> V_9 & 0x1 ) << 1 ) |
( V_4 -> V_10 & 0x1 ) ;
}
static inline void F_3 ( T_1 V_11 , struct V_3 * V_4 )
{
V_4 -> V_5 = ( V_11 >> 12 ) & 0xf ;
V_4 -> V_6 = ( V_11 >> 8 ) & 0xf ;
V_4 -> V_7 = ( V_11 >> 7 ) & 0x1 ;
V_4 -> V_8 = ( V_11 >> 4 ) & 0x7 ;
V_4 -> V_9 = ( V_11 >> 1 ) & 0x1 ;
V_4 -> V_10 = V_11 & 0x1 ;
}
static void F_4 ( const struct V_12 * V_4 ,
struct V_13 * V_14 )
{
F_5 ( & V_14 -> V_15 ) ;
F_6 ( F_1 ( & V_4 -> V_16 ) ,
V_14 -> V_17 + V_18 ) ;
F_6 ( F_1 ( & V_4 -> V_10 ) ,
V_14 -> V_17 + V_19 ) ;
F_7 ( & V_14 -> V_15 ) ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
F_5 ( & V_14 -> V_15 ) ;
F_3 ( F_9 (
V_14 -> V_17 + V_20 ) , V_4 ) ;
F_7 ( & V_14 -> V_15 ) ;
}
static void F_10 ( const struct V_3 * V_4 ,
struct V_13 * V_14 )
{
F_5 ( & V_14 -> V_15 ) ;
F_6 ( F_2 ( V_4 ) ,
V_14 -> V_17 + V_20 ) ;
F_7 ( & V_14 -> V_15 ) ;
}
static enum V_21 F_11 ( T_1 V_11 )
{
if ( V_11 & V_22 ) {
F_12 ( & V_23 . V_24 ,
L_1 ) ;
return V_25 ;
} else if ( V_11 & V_26 ) {
F_12 ( & V_23 . V_24 ,
L_2 ) ;
return V_27 ;
} else if ( V_11 & V_28 ) {
F_12 ( & V_23 . V_24 ,
L_3 ) ;
return V_29 ;
} else if ( V_11 & V_30 ) {
F_12 ( & V_23 . V_24 ,
L_4 ) ;
return V_31 ;
}
F_12 ( & V_23 . V_24 , L_5 ) ;
return V_32 ;
}
static T_2 F_13 ( int V_33 , void * V_34 )
{
struct V_13 * V_14 = V_34 ;
T_1 V_35 = F_9 ( V_14 -> V_17 +
V_36 ) ;
F_6 ( V_35 , V_14 -> V_17 + V_36 ) ;
F_12 ( & V_23 . V_24 , L_6 , V_35 ) ;
if ( ! ( V_35 & V_37 ) )
return V_38 ;
V_14 -> V_39 = F_11 ( V_35 ) ;
F_14 ( & V_14 -> V_40 ) ;
return V_41 ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 = - V_47 ;
V_45 = F_16 ( V_43 , V_48 , 0 ) ;
if ( ! V_45 ) {
F_17 ( & V_43 -> V_24 , L_7 ) ;
goto V_49;
}
if ( ! F_18 ( V_45 -> V_50 , F_19 ( V_45 ) ,
V_43 -> V_51 ) ) {
F_17 ( & V_43 -> V_24 ,
L_8 ,
V_45 -> V_50 ) ;
V_46 = - V_52 ;
goto V_49;
}
V_13 . V_17 = F_20 ( V_45 -> V_50 ,
F_19 ( V_45 ) ) ;
if ( ! V_13 . V_17 ) {
F_17 ( & V_43 -> V_24 ,
L_9 , V_45 -> V_50 ) ;
V_46 = - V_53 ;
goto V_54;
}
V_13 . V_33 = F_21 ( V_43 , 0 ) ;
if ( V_13 . V_33 ) {
V_46 = F_22 ( V_13 . V_33 , & F_13 ,
V_55 , V_43 -> V_51 , & V_13 ) ;
if ( V_46 == 0 ) {
F_6 ( V_37 ,
V_13 . V_17 +
V_56 ) ;
} else {
F_23 ( & V_43 -> V_24 ,
L_10
L_11 ,
V_13 . V_33 ) ;
V_13 . V_33 = 0 ;
}
}
F_24 ( & V_13 . V_40 ) ;
F_25 ( & V_13 . V_15 ) ;
F_4 ( & V_57 , & V_13 ) ;
F_10 ( & V_58 , & V_13 ) ;
F_26 (KERN_INFO DRV_NAME L_12 ) ;
V_23 . V_24 . V_59 = & V_43 -> V_24 ;
F_27 ( V_43 , & V_23 ) ;
F_28 ( & V_23 , & V_13 ) ;
V_46 = F_29 ( & V_23 ) ;
if ( V_46 )
goto V_60;
return 0 ;
V_60:
if ( V_13 . V_33 ) {
F_6 ( 0 ,
V_13 . V_17 + V_56 ) ;
F_30 ( V_13 . V_33 , & V_13 ) ;
}
F_31 ( V_13 . V_17 ) ;
V_54:
F_32 ( V_45 -> V_50 , F_19 ( V_45 ) ) ;
V_49:
return V_46 ;
}
static int F_33 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
F_34 ( & V_23 ) ;
if ( V_13 . V_33 ) {
F_6 ( 0 ,
V_13 . V_17 + V_56 ) ;
F_30 ( V_13 . V_33 , & V_13 ) ;
}
F_31 ( V_13 . V_17 ) ;
V_45 = F_16 ( V_43 , V_48 , 0 ) ;
F_32 ( V_45 -> V_50 , F_19 ( V_45 ) ) ;
return 0 ;
}
static void F_35 ( struct V_13 * V_14 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
T_1 V_63 = F_9 ( V_14 -> V_17 +
V_64 ) ;
if ( V_63 == 0 ) {
T_1 V_35 = F_9 ( V_14 -> V_17 +
V_36 ) ;
F_6 ( V_35 , V_14 -> V_17 +
V_36 ) ;
V_14 -> V_39 = F_11 ( V_35 ) ;
return;
}
F_36 ( V_65 ) ;
}
F_12 ( & V_23 . V_24 , L_13 ) ;
V_14 -> V_39 = V_66 ;
}
static enum V_21 F_37 (
T_1 V_11 , struct V_13 * V_14 )
{
F_12 ( & V_23 . V_24 , L_14 , V_11 ) ;
F_6 ( V_11 , V_14 -> V_17 + V_67 ) ;
if ( V_14 -> V_33 ) {
unsigned long V_68 = F_38 (
& V_14 -> V_40 , V_69 ) ;
if ( V_68 == 0 ) {
F_12 ( & V_23 . V_24 ,
L_15 ) ;
F_14 ( & V_14 -> V_40 ) ;
V_14 -> V_39 = V_66 ;
}
} else
F_35 ( V_14 ) ;
return V_14 -> V_39 ;
}
static inline T_1 F_39 ( const struct V_70 * V_71 )
{
return ( ( V_71 -> type & 0x3 ) << 8 ) |
( ( ( V_71 -> V_72 - 1 ) & 0x7 ) << 4 ) |
( ( V_71 -> V_73 - 1 ) & 0x7 ) ;
}
static enum V_21 F_40 (
struct V_70 * V_71 ,
struct V_13 * V_14 )
{
enum V_21 V_74 ;
if ( ( V_71 -> type == V_75 && V_71 -> V_72 == 0 ) ||
( V_71 -> type == V_76 && V_71 -> V_73 == 0 ) ||
( V_71 -> type == V_77 &&
( V_71 -> V_73 == 0 || V_71 -> V_72 == 0 ) ) ) {
F_17 ( & V_23 . V_24 ,
L_16 ,
V_78 ) ;
return - V_79 ;
}
F_5 ( & V_14 -> V_15 ) ;
F_12 ( & V_23 . V_24 ,
L_17 , V_71 -> V_80 ) ;
F_6 ( V_71 -> V_80 , V_14 -> V_17 + V_81 ) ;
if ( V_71 -> type == V_75 ||
V_71 -> type == V_77 ) {
T_3 V_82 = F_41 ( ( V_83 * ) V_71 -> V_84 ) ;
V_82 >>= ( V_85 - V_71 -> V_72 ) * 8 ;
F_12 ( & V_23 . V_24 , L_18 , V_82 ) ;
F_6 ( V_82 & 0x00000000ffffffffLL ,
V_14 -> V_17 + V_86 ) ;
if ( V_71 -> V_72 > 4 )
F_6 ( V_82 >> 32 ,
V_14 -> V_17 + V_87 ) ;
}
V_74 = F_37 ( F_39 ( V_71 ) , V_14 ) ;
if ( V_74 != V_32 )
goto V_88;
if ( V_71 -> type == V_76 ||
V_71 -> type == V_77 ) {
int V_61 ;
T_3 V_89 = ~ ( 0xffffffffffffffffLL << ( V_71 -> V_73 * 8 ) ) ;
T_3 V_82 = ( T_3 ) F_9 ( V_14 -> V_17 +
V_86 ) ;
if ( V_71 -> V_73 > 4 )
V_82 |= ( T_3 ) F_9 ( V_14 -> V_17 +
V_87 ) << 32 ;
V_82 &= V_89 ;
F_12 ( & V_23 . V_24 , L_19 , V_82 ) ;
for ( V_61 = 0 ; V_61 < V_71 -> V_73 ; V_61 ++ )
V_71 -> V_90 [ V_61 ] = V_82 >> V_61 ;
}
V_88:
F_7 ( & V_14 -> V_15 ) ;
return V_74 ;
}
static int F_42 ( struct V_91 * V_92 ,
struct V_93 * V_94 , int V_95 )
{
struct V_13 * V_14 = F_43 ( V_92 ) ;
struct V_70 V_71 ;
struct V_3 V_96 , V_97 ;
int V_98 ;
if ( V_95 == 2 ) {
struct V_93 * V_99 = V_94 + 1 ;
V_71 . type = V_77 ;
V_71 . V_72 = V_94 -> V_100 ;
V_71 . V_84 = V_94 -> V_101 ;
V_71 . V_73 = V_99 -> V_100 ;
V_71 . V_90 = V_99 -> V_101 ;
} else if ( V_94 -> V_102 & V_103 ) {
V_71 . type = V_76 ;
V_71 . V_73 = V_94 -> V_100 ;
V_71 . V_90 = V_94 -> V_101 ;
V_71 . V_72 = 0 ;
V_71 . V_84 = NULL ;
} else {
V_71 . type = V_75 ;
V_71 . V_73 = 0 ;
V_71 . V_90 = NULL ;
V_71 . V_72 = V_94 -> V_100 ;
V_71 . V_84 = V_94 -> V_101 ;
}
if ( V_94 -> V_100 == 0 ) {
F_17 ( & V_92 -> V_24 , L_20 ) ;
return - V_79 ;
}
V_71 . V_80 = V_94 -> V_80 ;
if ( V_94 -> V_102 & V_104 ) {
F_8 ( & V_97 , V_14 ) ;
memcpy ( & V_96 , & V_97 , sizeof( V_96 ) ) ;
V_97 . V_7 = 1 ;
F_10 ( & V_97 , V_14 ) ;
}
V_98 = F_40 ( & V_71 , V_14 ) ;
if ( V_94 -> V_102 & V_104 )
F_10 ( & V_96 , V_14 ) ;
F_12 ( & V_92 -> V_24 , L_21 ,
( V_94 -> V_102 & V_103 ) ? L_22 : L_23 , V_94 -> V_100 ,
( V_98 == V_32 ) ? L_24 : L_25 ) ;
if ( V_98 != V_32 ) {
return - 1 ;
}
return 0 ;
}
static T_1 F_44 ( struct V_91 * V_105 )
{
return V_106 | V_107 |
V_108 | V_109 |
V_110 | V_111 ;
}
