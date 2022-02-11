static T_1 F_1 ( void T_2 * V_1 , T_3 V_2 )
{
return F_2 ( V_1 + F_3 ( V_2 ) ) ;
}
static T_4 F_4 ( void T_2 * V_1 , T_3 V_2 )
{
return F_5 ( V_1 + F_6 ( V_2 ) ) ;
}
static void F_7 ( T_3 V_3 , void T_2 * V_1 , T_3 V_2 )
{
F_8 ( V_3 , V_1 + F_9 ( V_2 ) ) ;
}
static void F_10 ( T_1 V_3 , void T_2 * V_1 , T_3 V_2 )
{
F_11 ( V_3 , V_1 + F_3 ( V_2 ) ) ;
}
static void F_12 ( T_4 V_3 , void T_2 * V_1 , T_3 V_2 )
{
F_13 ( V_3 , V_1 + F_6 ( V_2 ) ) ;
}
static void F_14 ( T_5 * V_4 , T_6 * V_5 )
{
int V_6 = V_5 -> V_7 ;
T_3 V_8 , V_3 ;
const T_4 V_9 = V_5 -> V_10 - V_11 ;
T_4 V_12 = V_9 ;
T_6 * V_13 ;
V_13 = F_15 ( V_5 ) ;
if ( V_13 )
V_12 = F_16 ( T_4 , V_12 , V_13 -> V_10 - V_11 ) ;
V_8 = V_6 ? 0x07f00000 : 0x000007f0 ;
V_3 = ( ( V_12 << 8 ) | ( V_9 << 4 ) ) << ( V_6 ? 16 : 0 ) ;
V_4 -> V_14 = ( V_4 -> V_14 & ~ V_8 ) | V_3 ;
}
static void F_17 ( T_5 * V_4 , T_6 * V_5 )
{
T_3 V_8 , V_3 ;
const T_4 V_15 = V_5 -> V_16 ;
if ( V_15 >= V_17 )
V_3 = V_15 - V_17 + 8 ;
else
V_3 = V_15 - V_18 + 5 ;
if ( V_5 -> V_7 ) {
V_8 = 0x00f00000 ;
V_3 <<= 20 ;
} else {
V_8 = 0x000000f0 ;
V_3 <<= 4 ;
}
V_4 -> V_14 = ( V_4 -> V_14 & ~ V_8 ) | V_3 ;
}
static T_1 F_18 ( T_5 * V_4 )
{
void T_2 * V_1 = F_19 ( V_4 ) ;
T_1 V_19 = F_1 ( V_1 , V_20 ) ;
if ( V_19 & V_21 ) {
T_1 V_22 = F_1 ( V_1 , V_23 ) ;
F_10 ( V_22 | 0x4000 , V_1 , V_23 ) ;
F_20 () ;
F_21 ( 270 ) ;
F_10 ( V_22 , V_1 , V_23 ) ;
}
if ( V_19 & ( V_24 |
V_25 | V_21 ) )
F_22 ( L_1 ,
V_4 -> V_26 , V_19 ,
V_19 & V_24 ? L_2 : L_3 ,
V_19 & V_25 ? L_4 : L_3 ,
V_19 & V_21 ? L_5 : L_3 ) ;
return V_19 ;
}
static void F_23 ( T_6 * V_5 )
{
T_5 * V_4 ;
void T_2 * V_1 ;
T_1 V_19 ;
if ( V_5 -> V_27 )
return;
V_4 = V_5 -> V_4 ;
V_1 = F_19 ( V_4 ) ;
V_19 = F_18 ( V_4 ) ;
F_10 ( V_19 , V_1 , V_20 ) ;
}
static T_4 F_24 ( T_5 * V_4 )
{
void T_2 * V_1 = F_19 ( V_4 ) ;
return F_1 ( V_1 , V_23 ) & 0x2000 ?
V_28 : V_29 ;
}
static void F_25 ( T_6 * V_5 , int V_30 )
{
T_5 * V_4 = V_5 -> V_4 ;
T_4 V_31 = V_5 -> V_7 ;
void T_2 * V_1 = F_19 ( V_4 ) ;
T_4 V_32 = F_4 ( V_1 , V_33 ) ;
if ( V_30 )
V_32 |= ( 1 << ( 5 + V_31 ) ) ;
else
V_32 &= ~ ( 1 << ( 5 + V_31 ) ) ;
F_12 ( V_32 , V_1 , V_33 ) ;
}
static T_4 F_26 ( void T_2 * V_1 )
{
T_4 V_32 ;
V_32 = F_4 ( V_1 , V_33 ) ;
F_12 ( V_32 | V_34 | V_35 , V_1 ,
V_33 ) ;
F_10 ( V_36 << 8 , V_1 , V_20 ) ;
return V_32 ;
}
static int F_27 ( T_6 * V_5 , struct V_37 * V_38 )
{
T_5 * V_4 = V_5 -> V_4 ;
T_3 * V_39 = ( T_3 * ) V_4 -> V_40 ;
unsigned int V_41 = 0 ;
int V_42 ;
struct V_43 * V_44 ;
F_28 (hwif->sg_table, sg, cmd->sg_nents, i) {
T_3 V_45 , V_46 , V_47 ;
V_45 = F_29 ( V_44 ) ;
V_46 = F_30 ( V_44 ) ;
while ( V_46 ) {
if ( V_41 ++ >= V_48 )
goto V_49;
V_47 = 0x10000 - ( V_45 & 0xffff ) ;
if ( V_47 > V_46 )
V_47 = V_46 ;
if ( V_47 == 0x10000 )
V_47 = 0x8000 ;
* V_39 ++ = V_47 & 0xffff ;
* V_39 ++ = V_45 ;
V_45 += V_47 ;
V_46 -= V_47 ;
}
}
if ( V_41 ) {
* ( V_39 - 2 ) |= 0x80000000 ;
return V_41 ;
}
V_49:
F_31 ( V_50 L_6 , V_5 -> V_26 ,
V_41 ? L_7 : L_8 ) ;
return 0 ;
}
static int F_32 ( T_6 * V_5 , struct V_37 * V_38 )
{
T_5 * V_4 = V_5 -> V_4 ;
void T_2 * V_1 = F_19 ( V_4 ) ;
T_4 V_51 = ( V_38 -> V_52 & V_53 ) ? 0 : V_54 ;
if ( F_27 ( V_5 , V_38 ) == 0 )
return 1 ;
F_7 ( V_4 -> V_55 , V_1 , V_56 ) ;
F_12 ( V_51 , V_1 , V_57 ) ;
F_26 ( V_1 ) ;
F_10 ( V_58 / 2 , V_1 , V_5 -> V_7 ?
V_59 : V_60 ) ;
F_10 ( F_33 ( V_38 -> V_61 ) , V_1 , V_62 ) ;
return 0 ;
}
static int F_34 ( T_6 * V_5 )
{
T_5 * V_4 = V_5 -> V_4 ;
T_4 V_32 , V_63 ;
void T_2 * V_1 = F_19 ( V_4 ) ;
T_1 V_19 = F_1 ( V_1 , V_20 ) ;
V_63 = F_4 ( V_1 , V_57 ) ;
F_12 ( V_63 & ~ V_64 , V_1 , V_57 ) ;
V_32 = F_26 ( V_1 ) ;
#define F_35 (ATA_DMA_ACTIVE | ATA_DMA_ERR | ATA_DMA_INTR)
if ( ( V_32 & F_35 ) == 0 &&
( V_19 & ( V_65 | V_66 ) ) ==
( V_65 | V_66 ) )
return 0 ;
return ( ( V_32 & F_35 ) !=
V_34 ) ? 0x10 | V_32 : 0 ;
}
static int F_36 ( T_6 * V_5 )
{
T_5 * V_4 = V_5 -> V_4 ;
void T_2 * V_1 = F_19 ( V_4 ) ;
T_1 V_19 , V_67 ;
T_4 V_32 , V_68 ;
int V_69 = 0 ;
V_19 = F_18 ( V_4 ) ;
V_67 = V_19 & ( V_65 | V_66 ) ;
switch ( V_67 ) {
case V_66 :
V_68 = F_4 ( V_1 , V_70 ) ;
if ( ( V_68 & ( V_71 | V_72 | V_73 ) ) == V_73 )
V_69 = 1 ;
else
V_19 &= ~ V_65 << 8 ;
V_19 |= V_67 << 8 ;
break;
case V_66 | V_65 :
V_32 = F_4 ( V_1 , V_33 ) ;
if ( ! ( V_32 & V_34 ) )
F_37 ( L_9
L_10 ,
V_4 -> V_26 , V_32 , V_19 ) ;
V_69 = 1 ;
break;
}
V_19 &= ~ V_67 ;
F_10 ( V_19 , V_1 , V_20 ) ;
return V_69 ;
}
static T_4 F_38 ( T_5 * V_4 )
{
void T_2 * V_1 = F_19 ( V_4 ) ;
return F_4 ( V_1 , V_33 ) ;
}
static void F_39 ( T_5 * V_4 )
{
void T_2 * V_1 = F_19 ( V_4 ) ;
F_10 ( 0x8000 , V_1 , V_23 ) ;
F_20 () ;
F_21 ( 450 ) ;
F_10 ( 0x0000 , V_1 , V_23 ) ;
F_10 ( ( V_36 << 8 ) | 0xff , V_1 ,
V_20 ) ;
F_10 ( 0x0008 , V_1 , V_74 ) ;
F_10 ( 0 , V_1 , V_75 ) ;
}
static int F_40 ( T_5 * V_4 , const struct V_76 * V_77 )
{
V_4 -> V_78 =
V_4 -> V_79 + F_6 ( V_57 ) ;
return F_41 ( V_4 ) ;
}
static void F_42 ( T_6 * V_5 )
{
T_5 * V_4 = V_5 -> V_4 ;
void T_2 * V_1 = F_19 ( V_4 ) ;
T_1 V_22 = V_4 -> V_14 >> ( V_5 -> V_7 ? 16 : 0 ) ;
F_10 ( V_22 , V_1 , V_23 ) ;
}
static void F_43 ( T_6 * V_5 , struct V_80 * V_81 ,
T_4 V_82 )
{
F_44 ( V_5 , V_81 , V_82 ) ;
if ( V_82 & V_83 )
F_42 ( V_5 ) ;
}
static void F_45 ( T_6 * V_5 , struct V_37 * V_38 ,
void * V_84 , unsigned int V_85 )
{
unsigned long V_86 = V_5 -> V_4 -> V_87 . V_88 ;
unsigned short * V_89 = V_84 ;
unsigned int V_41 = ( V_85 + 1 ) / 2 ;
while ( V_41 -- )
* V_89 ++ = F_46 ( F_2 ( ( void T_2 * ) V_86 ) ) ;
F_47 ( ( unsigned long ) V_84 , F_48 ( V_85 , 2 ) ) ;
}
static void F_49 ( T_6 * V_5 , struct V_37 * V_38 ,
void * V_84 , unsigned int V_85 )
{
unsigned long V_86 = V_5 -> V_4 -> V_87 . V_88 ;
unsigned short * V_89 = V_84 ;
unsigned int V_41 = ( V_85 + 1 ) / 2 ;
while ( V_41 -- ) {
F_11 ( F_50 ( * V_89 ) , ( void T_2 * ) V_86 ) ;
V_89 ++ ;
}
F_47 ( ( unsigned long ) V_84 , F_48 ( V_85 , 2 ) ) ;
}
static int T_7 F_51 ( struct V_90 * V_91 )
{
struct V_92 V_93 , * V_94 [] = { & V_93 } ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
int V_99 , V_100 ;
unsigned long V_101 ;
V_99 = F_52 ( V_91 , 0 ) ;
if ( V_99 < 0 )
return - V_102 ;
V_98 = F_53 ( V_91 , V_103 , 0 ) ;
if ( ! V_98 )
return - V_102 ;
if ( ! F_54 ( & V_91 -> V_104 , V_98 -> V_105 ,
F_55 ( V_98 ) , L_11 ) )
return - V_106 ;
V_101 = ( unsigned long ) F_56 ( & V_91 -> V_104 , V_98 -> V_105 ,
F_55 ( V_98 ) ) ;
if ( ! V_101 )
return - V_106 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_87 . V_88 =
V_101 + F_3 ( V_107 ) ;
V_93 . V_87 . V_108 =
V_101 + F_6 ( V_109 ) ;
V_93 . V_87 . V_110 =
V_101 + F_6 ( V_111 ) ;
V_93 . V_87 . V_112 =
V_101 + F_6 ( V_113 ) ;
V_93 . V_87 . V_114 =
V_101 + F_6 ( V_115 ) ;
V_93 . V_87 . V_116 =
V_101 + F_6 ( V_117 ) ;
V_93 . V_87 . V_118 =
V_101 + F_6 ( V_119 ) ;
V_93 . V_87 . V_120 =
V_101 + F_6 ( V_121 ) ;
V_93 . V_87 . V_122 =
V_101 + F_6 ( V_70 ) ;
V_93 . V_99 = V_99 ;
V_93 . V_104 = & V_91 -> V_104 ;
F_57 ( L_12 , V_101 , V_99 ) ;
V_96 = F_58 ( & V_123 , V_94 , 1 ) ;
if ( ! V_96 )
return - V_124 ;
V_96 -> V_125 [ 0 ] -> V_79 = V_101 ;
V_100 = F_59 ( V_96 , & V_123 , V_94 ) ;
if ( V_100 ) {
F_60 ( V_96 ) ;
return V_100 ;
}
F_61 ( V_91 , V_96 ) ;
return 0 ;
}
static int T_8 F_62 ( struct V_90 * V_91 )
{
struct V_95 * V_96 = F_63 ( V_91 ) ;
F_64 ( V_96 ) ;
return 0 ;
}
static int F_65 ( struct V_90 * V_104 )
{
struct V_95 * V_96 = F_63 ( V_104 ) ;
T_5 * V_4 = V_96 -> V_125 [ 0 ] ;
F_39 ( V_4 ) ;
return 0 ;
}
static int T_7 F_66 ( void )
{
return F_67 ( & V_126 , F_51 ) ;
}
static void T_8 F_68 ( void )
{
F_69 ( & V_126 ) ;
}
