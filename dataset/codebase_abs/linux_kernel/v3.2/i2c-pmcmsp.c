static inline T_1 F_1 (
const struct V_1 * clock )
{
return ( ( clock -> V_2 & 0xf ) << 12 ) | ( clock -> clock & 0x03ff ) ;
}
static inline void F_2 (
T_1 V_3 , struct V_1 * clock )
{
clock -> V_2 = ( V_3 >> 12 ) & 0xf ;
clock -> clock = V_3 & 0x03ff ;
}
static inline T_1 F_3 ( const struct V_4 * V_5 )
{
return ( ( V_5 -> V_6 & 0xf ) << 12 ) |
( ( V_5 -> V_7 & 0xf ) << 8 ) |
( ( V_5 -> V_8 & 0x1 ) << 7 ) |
( ( V_5 -> V_9 & 0x7 ) << 4 ) |
( ( V_5 -> V_10 & 0x1 ) << 1 ) |
( V_5 -> V_11 & 0x1 ) ;
}
static inline void F_4 ( T_1 V_3 , struct V_4 * V_5 )
{
V_5 -> V_6 = ( V_3 >> 12 ) & 0xf ;
V_5 -> V_7 = ( V_3 >> 8 ) & 0xf ;
V_5 -> V_8 = ( V_3 >> 7 ) & 0x1 ;
V_5 -> V_9 = ( V_3 >> 4 ) & 0x7 ;
V_5 -> V_10 = ( V_3 >> 1 ) & 0x1 ;
V_5 -> V_11 = V_3 & 0x1 ;
}
static void F_5 ( const struct V_12 * V_5 ,
struct V_13 * V_14 )
{
F_6 ( & V_14 -> V_15 ) ;
F_7 ( F_1 ( & V_5 -> V_16 ) ,
V_14 -> V_17 + V_18 ) ;
F_7 ( F_1 ( & V_5 -> V_11 ) ,
V_14 -> V_17 + V_19 ) ;
F_8 ( & V_14 -> V_15 ) ;
}
static void F_9 ( struct V_4 * V_5 ,
struct V_13 * V_14 )
{
F_6 ( & V_14 -> V_15 ) ;
F_4 ( F_10 (
V_14 -> V_17 + V_20 ) , V_5 ) ;
F_8 ( & V_14 -> V_15 ) ;
}
static void F_11 ( const struct V_4 * V_5 ,
struct V_13 * V_14 )
{
F_6 ( & V_14 -> V_15 ) ;
F_7 ( F_3 ( V_5 ) ,
V_14 -> V_17 + V_20 ) ;
F_8 ( & V_14 -> V_15 ) ;
}
static enum V_21 F_12 ( T_1 V_3 )
{
if ( V_3 & V_22 ) {
F_13 ( & V_23 . V_24 ,
L_1 ) ;
return V_25 ;
} else if ( V_3 & V_26 ) {
F_13 ( & V_23 . V_24 ,
L_2 ) ;
return V_27 ;
} else if ( V_3 & V_28 ) {
F_13 ( & V_23 . V_24 ,
L_3 ) ;
return V_29 ;
} else if ( V_3 & V_30 ) {
F_13 ( & V_23 . V_24 ,
L_4 ) ;
return V_31 ;
}
F_13 ( & V_23 . V_24 , L_5 ) ;
return V_32 ;
}
static T_2 F_14 ( int V_33 , void * V_34 )
{
struct V_13 * V_14 = V_34 ;
T_1 V_35 = F_10 ( V_14 -> V_17 +
V_36 ) ;
F_7 ( V_35 , V_14 -> V_17 + V_36 ) ;
F_13 ( & V_23 . V_24 , L_6 , V_35 ) ;
if ( ! ( V_35 & V_37 ) )
return V_38 ;
V_14 -> V_39 = F_12 ( V_35 ) ;
F_15 ( & V_14 -> V_40 ) ;
return V_41 ;
}
static int T_3 F_16 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 = - V_47 ;
V_45 = F_17 ( V_43 , V_48 , 0 ) ;
if ( ! V_45 ) {
F_18 ( & V_43 -> V_24 , L_7 ) ;
goto V_49;
}
if ( ! F_19 ( V_45 -> V_50 , F_20 ( V_45 ) ,
V_43 -> V_51 ) ) {
F_18 ( & V_43 -> V_24 ,
L_8 ,
V_45 -> V_50 ) ;
V_46 = - V_52 ;
goto V_49;
}
V_13 . V_17 = F_21 ( V_45 -> V_50 ,
F_20 ( V_45 ) ) ;
if ( ! V_13 . V_17 ) {
F_18 ( & V_43 -> V_24 ,
L_9 , V_45 -> V_50 ) ;
V_46 = - V_53 ;
goto V_54;
}
V_13 . V_33 = F_22 ( V_43 , 0 ) ;
if ( V_13 . V_33 ) {
V_46 = F_23 ( V_13 . V_33 , & F_14 ,
V_55 | V_56 ,
V_43 -> V_51 , & V_13 ) ;
if ( V_46 == 0 ) {
F_7 ( V_37 ,
V_13 . V_17 +
V_57 ) ;
} else {
F_24 ( & V_43 -> V_24 ,
L_10
L_11 ,
V_13 . V_33 ) ;
V_13 . V_33 = 0 ;
}
}
F_25 ( & V_13 . V_40 ) ;
F_26 ( & V_13 . V_15 ) ;
F_5 ( & V_58 , & V_13 ) ;
F_11 ( & V_59 , & V_13 ) ;
F_27 (KERN_INFO DRV_NAME L_12 ) ;
V_23 . V_24 . V_60 = & V_43 -> V_24 ;
F_28 ( V_43 , & V_23 ) ;
F_29 ( & V_23 , & V_13 ) ;
V_46 = F_30 ( & V_23 ) ;
if ( V_46 ) {
F_18 ( & V_43 -> V_24 , L_13 ) ;
goto V_61;
}
return 0 ;
V_61:
F_28 ( V_43 , NULL ) ;
if ( V_13 . V_33 ) {
F_7 ( 0 ,
V_13 . V_17 + V_57 ) ;
F_31 ( V_13 . V_33 , & V_13 ) ;
}
F_32 ( V_13 . V_17 ) ;
V_54:
F_33 ( V_45 -> V_50 , F_20 ( V_45 ) ) ;
V_49:
return V_46 ;
}
static int T_4 F_34 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
F_35 ( & V_23 ) ;
F_28 ( V_43 , NULL ) ;
if ( V_13 . V_33 ) {
F_7 ( 0 ,
V_13 . V_17 + V_57 ) ;
F_31 ( V_13 . V_33 , & V_13 ) ;
}
F_32 ( V_13 . V_17 ) ;
V_45 = F_17 ( V_43 , V_48 , 0 ) ;
F_33 ( V_45 -> V_50 , F_20 ( V_45 ) ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_14 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
T_1 V_64 = F_10 ( V_14 -> V_17 +
V_65 ) ;
if ( V_64 == 0 ) {
T_1 V_35 = F_10 ( V_14 -> V_17 +
V_36 ) ;
F_7 ( V_35 , V_14 -> V_17 +
V_36 ) ;
V_14 -> V_39 = F_12 ( V_35 ) ;
return;
}
F_37 ( V_66 ) ;
}
F_13 ( & V_23 . V_24 , L_14 ) ;
V_14 -> V_39 = V_67 ;
}
static enum V_21 F_38 (
T_1 V_3 , struct V_13 * V_14 )
{
F_13 ( & V_23 . V_24 , L_15 , V_3 ) ;
F_7 ( V_3 , V_14 -> V_17 + V_68 ) ;
if ( V_14 -> V_33 ) {
unsigned long V_69 = F_39 (
& V_14 -> V_40 , V_70 ) ;
if ( V_69 == 0 ) {
F_13 ( & V_23 . V_24 ,
L_16 ) ;
F_15 ( & V_14 -> V_40 ) ;
V_14 -> V_39 = V_67 ;
}
} else
F_36 ( V_14 ) ;
return V_14 -> V_39 ;
}
static inline T_1 F_40 ( const struct V_71 * V_72 )
{
return ( ( V_72 -> type & 0x3 ) << 8 ) |
( ( ( V_72 -> V_73 - 1 ) & 0x7 ) << 4 ) |
( ( V_72 -> V_74 - 1 ) & 0x7 ) ;
}
static enum V_21 F_41 (
struct V_71 * V_72 ,
struct V_13 * V_14 )
{
enum V_21 V_75 ;
if ( ( V_72 -> type == V_76 && V_72 -> V_73 == 0 ) ||
( V_72 -> type == V_77 && V_72 -> V_74 == 0 ) ||
( V_72 -> type == V_78 &&
( V_72 -> V_74 == 0 || V_72 -> V_73 == 0 ) ) ) {
F_18 ( & V_23 . V_24 ,
L_17 ,
V_79 ) ;
return - V_80 ;
}
if ( V_72 -> V_74 > V_81 ||
V_72 -> V_73 > V_81 ) {
F_18 ( & V_23 . V_24 ,
L_18 ,
V_79 , V_81 ) ;
return - V_80 ;
}
F_6 ( & V_14 -> V_15 ) ;
F_13 ( & V_23 . V_24 ,
L_19 , V_72 -> V_82 ) ;
F_7 ( V_72 -> V_82 , V_14 -> V_17 + V_83 ) ;
if ( V_72 -> type == V_76 ||
V_72 -> type == V_78 ) {
T_5 V_84 = F_42 ( ( V_85 * ) V_72 -> V_86 ) ;
V_84 >>= ( V_81 - V_72 -> V_73 ) * 8 ;
F_13 ( & V_23 . V_24 , L_20 , V_84 ) ;
F_7 ( V_84 & 0x00000000ffffffffLL ,
V_14 -> V_17 + V_87 ) ;
if ( V_72 -> V_73 > 4 )
F_7 ( V_84 >> 32 ,
V_14 -> V_17 + V_88 ) ;
}
V_75 = F_38 ( F_40 ( V_72 ) , V_14 ) ;
if ( V_75 != V_32 )
goto V_89;
if ( V_72 -> type == V_77 ||
V_72 -> type == V_78 ) {
int V_62 ;
T_5 V_90 = ~ ( 0xffffffffffffffffLL << ( V_72 -> V_74 * 8 ) ) ;
T_5 V_84 = ( T_5 ) F_10 ( V_14 -> V_17 +
V_87 ) ;
if ( V_72 -> V_74 > 4 )
V_84 |= ( T_5 ) F_10 ( V_14 -> V_17 +
V_88 ) << 32 ;
V_84 &= V_90 ;
F_13 ( & V_23 . V_24 , L_21 , V_84 ) ;
for ( V_62 = 0 ; V_62 < V_72 -> V_74 ; V_62 ++ )
V_72 -> V_91 [ V_62 ] = V_84 >> V_62 ;
}
V_89:
F_8 ( & V_14 -> V_15 ) ;
return V_75 ;
}
static int F_43 ( struct V_92 * V_93 ,
struct V_94 * V_95 , int V_96 )
{
struct V_13 * V_14 = F_44 ( V_93 ) ;
struct V_71 V_72 ;
struct V_4 V_97 , V_98 ;
int V_99 ;
if ( V_96 > 2 ) {
F_13 ( & V_93 -> V_24 , L_22 , V_96 ) ;
return - V_80 ;
} else if ( V_96 == 2 ) {
struct V_94 * V_100 = V_95 + 1 ;
if ( ! ( V_95 -> V_101 & V_102 ) &&
( V_100 -> V_101 & V_102 ) &&
V_95 -> V_82 == V_100 -> V_82 ) {
V_72 . type = V_78 ;
V_72 . V_73 = V_95 -> V_103 ;
V_72 . V_86 = V_95 -> V_104 ;
V_72 . V_74 = V_100 -> V_103 ;
V_72 . V_91 = V_100 -> V_104 ;
} else {
F_13 ( & V_93 -> V_24 ,
L_23 ) ;
return - V_80 ;
}
} else if ( V_95 -> V_101 & V_102 ) {
V_72 . type = V_77 ;
V_72 . V_74 = V_95 -> V_103 ;
V_72 . V_91 = V_95 -> V_104 ;
V_72 . V_73 = 0 ;
V_72 . V_86 = NULL ;
} else {
V_72 . type = V_76 ;
V_72 . V_74 = 0 ;
V_72 . V_91 = NULL ;
V_72 . V_73 = V_95 -> V_103 ;
V_72 . V_86 = V_95 -> V_104 ;
}
if ( V_95 -> V_103 == 0 ) {
F_18 ( & V_93 -> V_24 , L_24 ) ;
return - V_80 ;
}
V_72 . V_82 = V_95 -> V_82 ;
if ( V_95 -> V_101 & V_105 ) {
F_9 ( & V_98 , V_14 ) ;
memcpy ( & V_97 , & V_98 , sizeof( V_97 ) ) ;
V_98 . V_8 = 1 ;
F_11 ( & V_98 , V_14 ) ;
}
V_99 = F_41 ( & V_72 , V_14 ) ;
if ( V_95 -> V_101 & V_105 )
F_11 ( & V_97 , V_14 ) ;
F_13 ( & V_93 -> V_24 , L_25 ,
( V_95 -> V_101 & V_102 ) ? L_26 : L_27 , V_95 -> V_103 ,
( V_99 == V_32 ) ? L_28 : L_29 ) ;
if ( V_99 != V_32 ) {
return - 1 ;
}
return 0 ;
}
static T_1 F_45 ( struct V_92 * V_106 )
{
return V_107 | V_108 |
V_109 | V_110 |
V_111 | V_112 ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_113 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_113 ) ;
}
