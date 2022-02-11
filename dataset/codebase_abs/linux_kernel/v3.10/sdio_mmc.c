static T_1
F_1 ( int V_1 )
{
T_1 V_2 = V_3 ;
switch ( V_1 ) {
case 0 :
V_2 = V_4 ;
break;
case - V_5 :
case - V_6 :
V_2 = V_7 ;
break;
case - V_8 :
case - V_9 :
V_2 = V_10 ;
break;
case - V_11 :
case - V_12 :
V_2 = V_13 ;
break;
case - V_14 :
V_2 = V_15 ;
break;
case - V_16 :
case - V_17 :
case - V_18 :
case - V_19 :
V_2 = V_3 ;
break;
default:
F_2 ( NULL , L_1 , V_1 ) ;
break;
}
return V_2 ;
}
static int
F_3 ( struct V_20 * V_21 , int V_22 , T_2 V_23 ,
T_3 V_24 , T_2 V_25 , T_2 * V_26 )
{
struct V_27 V_28 ;
int V_29 ;
F_4 ( ! V_21 ) ;
F_4 ( V_23 > 7 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_30 = V_31 ;
V_28 . V_32 = V_22 ? 0x80000000 : 0x00000000 ;
V_28 . V_32 |= V_23 << 28 ;
V_28 . V_32 |= ( V_22 && V_26 ) ? 0x08000000 : 0x00000000 ;
V_28 . V_32 |= V_24 << 9 ;
V_28 . V_32 |= V_25 ;
V_28 . V_33 = V_34 | V_35 | V_36 ;
V_29 = F_5 ( V_21 -> V_37 , & V_28 , 0 ) ;
if ( V_29 )
return V_29 ;
if ( 0 ) {
} else {
if ( V_28 . V_38 [ 0 ] & V_39 ) {
F_6 ( V_40 L_2 ,
V_41 , V_28 . V_38 [ 0 ] ) ;
return - V_5 ;
}
if ( V_28 . V_38 [ 0 ] & V_42 )
return - V_14 ;
if ( V_28 . V_38 [ 0 ] & V_43 )
return - V_18 ;
}
if ( V_26 ) {
if ( 0 ) {
* V_26 = ( V_28 . V_38 [ 0 ] >> 8 ) & 0xFF ;
}
else {
* V_26 = V_28 . V_38 [ 0 ] & 0xFF ;
}
}
return V_4 ;
}
T_1
F_7 ( T_4 * V_44 , T_5 V_45 , T_6 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
* V_46 = F_9 ( V_48 , V_45 , & V_29 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_11 ( T_4 * V_44 , T_5 V_45 , T_6 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
F_12 ( V_48 , V_46 , V_45 , & V_29 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_13 ( T_4 * V_44 , T_5 V_45 , T_7 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
T_2 V_50 , V_51 ;
F_8 ( V_48 ) ;
V_50 = F_9 ( V_48 , V_45 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
V_51 = F_9 ( V_48 , V_45 + 1 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
F_10 ( V_48 ) ;
* V_46 = ( ( V_52 ) V_51 << 8 ) | V_50 ;
return V_4 ;
}
T_1
F_14 ( T_4 * V_44 , T_5 V_45 , T_7 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
T_2 V_50 , V_51 ;
F_8 ( V_48 ) ;
V_51 = ( V_46 >> 8 ) & 0xFF ;
F_12 ( V_48 , V_51 , V_45 + 1 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
V_50 = V_46 & 0xFF ;
F_12 ( V_48 , V_50 , V_45 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
F_10 ( V_48 ) ;
return V_4 ;
}
T_1
F_15 ( T_4 * V_44 , T_5 V_45 , T_6 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
#ifdef F_16
* V_46 = F_17 ( V_48 , V_45 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 0 , 0 , V_45 , 0 , V_46 ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_18 ( T_4 * V_44 , T_5 V_45 , T_6 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
#ifdef F_16
F_19 ( V_48 , V_46 , V_45 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_45 , V_46 , NULL ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_20 ( T_4 * V_44 , T_5 V_45 , void * V_46 , T_5 V_53 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_21 ( V_48 , V_46 , V_45 , V_53 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_22 ( T_4 * V_44 , T_5 V_45 , const void * V_46 , T_5 V_53 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_23 ( V_48 , V_45 , ( void * ) V_46 , V_53 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
return F_1 ( V_29 ) ;
}
return V_4 ;
}
static int
F_24 ( struct V_20 * V_21 )
{
int V_54 ;
T_6 V_55 ;
if ( ! ( V_21 -> V_37 -> V_56 & V_57 ) ) {
F_6 ( V_58 L_3 ) ;
return 0 ;
}
if ( ! V_21 -> V_59 . V_60 )
return 0 ;
#if 1
V_54 = F_3 ( V_21 , 0 , 0 , V_61 , 0 , & V_55 ) ;
if ( V_54 )
return V_54 ;
V_55 |= V_62 ;
#else
V_55 = V_62 | V_63 ;
#endif
V_54 = F_3 ( V_21 , 1 , 0 , V_61 , V_55 , NULL ) ;
if ( V_54 )
return V_54 ;
F_25 ( V_21 ) ;
V_21 -> V_37 -> V_64 . V_65 = V_66 ;
V_21 -> V_37 -> V_67 -> V_68 ( V_21 -> V_37 , & V_21 -> V_37 -> V_64 ) ;
return 0 ;
}
static int
F_26 ( struct V_20 * V_21 )
{
int V_54 ;
T_6 V_55 ;
if ( ! ( V_21 -> V_37 -> V_56 & V_57 ) )
return 0 ;
if ( ! V_21 -> V_59 . V_60 )
return 0 ;
#if 1
V_54 = F_3 ( V_21 , 0 , 0 , V_61 , 0 , & V_55 ) ;
if ( V_54 )
return V_54 ;
V_55 &= ~ V_62 ;
#else
V_55 = V_63 ;
#endif
V_54 = F_3 ( V_21 , 1 , 0 , V_61 , V_55 , NULL ) ;
if ( V_54 )
return V_54 ;
V_21 -> V_69 &= ~ V_70 ;
V_21 -> V_37 -> V_64 . V_65 = V_71 ;
V_21 -> V_37 -> V_67 -> V_68 ( V_21 -> V_37 , & V_21 -> V_37 -> V_64 ) ;
return 0 ;
}
T_1
F_27 ( T_4 * V_44 , T_5 V_72 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_73 * V_37 = V_48 -> V_21 -> V_37 ;
struct V_74 * V_64 = & V_37 -> V_64 ;
unsigned int V_75 ;
int V_29 ;
T_5 V_76 = V_72 / 1000 ;
if ( ! V_76 || V_76 > V_77 ) {
V_76 = V_77 ;
}
F_8 ( V_48 ) ;
V_75 = 1000 * V_76 ;
if ( V_75 > V_37 -> V_78 ) {
V_75 = V_37 -> V_78 ;
}
if ( V_75 > 25000000 ) {
V_29 = F_24 ( V_48 -> V_21 ) ;
} else {
V_29 = F_26 ( V_48 -> V_21 ) ;
}
if ( V_29 ) {
F_6 ( V_40 L_4 ) ;
F_10 ( V_48 ) ;
return V_4 ;
}
V_64 -> clock = V_75 ;
V_37 -> V_67 -> V_68 ( V_37 , V_64 ) ;
F_10 ( V_48 ) ;
return V_4 ;
}
T_1
F_28 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
#ifdef F_29
F_30 ( V_48 ) ;
#else
F_8 ( V_48 ) ;
#ifdef F_16
F_19 ( V_48 , 0x3 , V_79 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x03 , NULL ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
F_6 ( V_40 L_5 , V_41 , V_29 ) ;
return F_1 ( V_29 ) ;
}
#endif
return V_4 ;
}
T_1
F_31 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
#ifdef F_29
F_32 ( V_48 ) ;
#else
F_8 ( V_48 ) ;
#ifdef F_16
F_19 ( V_48 , 0 , V_79 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x00 , NULL ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
F_6 ( V_40 L_5 , V_41 , V_29 ) ;
return F_1 ( V_29 ) ;
}
#endif
return V_4 ;
}
void F_33 ( T_4 * V_44 )
{
}
T_1
F_34 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_35 ( V_48 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_36 ( NULL , L_6 , V_48 -> V_80 ) ;
}
return F_1 ( V_29 ) ;
}
T_1
F_37 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_38 ( V_48 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_36 ( NULL , L_7 , V_48 -> V_80 ) ;
}
return F_1 ( V_29 ) ;
}
void
F_39 ( T_4 * V_44 )
{
}
void
F_40 ( T_4 * V_44 )
{
}
T_1
F_41 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_73 * V_37 = V_48 -> V_21 -> V_37 ;
F_8 ( V_48 ) ;
if ( ! V_81 ) {
F_42 ( V_37 ) ;
V_81 = 1 ;
} else {
F_6 ( V_58 L_8 ) ;
}
F_10 ( V_48 ) ;
return V_4 ;
}
void
F_43 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_73 * V_37 = V_48 -> V_21 -> V_37 ;
F_8 ( V_48 ) ;
if ( V_81 ) {
F_44 ( V_37 ) ;
V_81 = 0 ;
} else {
F_6 ( V_58 L_9 ) ;
}
F_10 ( V_48 ) ;
}
static int
F_45 ( struct V_47 * V_48 , unsigned V_82 )
{
int V_54 ;
if ( V_82 > V_48 -> V_21 -> V_37 -> V_83 )
return - V_14 ;
if ( V_82 == 0 ) {
V_82 = F_46 ( V_48 -> V_84 , V_48 -> V_21 -> V_37 -> V_83 ) ;
V_82 = F_46 ( V_82 , 512u ) ;
}
V_54 = F_3 ( V_48 -> V_21 , 1 , 0 ,
F_47 ( V_48 -> V_80 ) + V_85 ,
V_82 & 0xff , NULL ) ;
if ( V_54 && V_54 != - V_18 )
return V_54 ;
V_54 = F_3 ( V_48 -> V_21 , 1 , 0 ,
F_47 ( V_48 -> V_80 ) + V_85 + 1 ,
( V_82 >> 8 ) & 0xff , NULL ) ;
if ( V_54 )
return V_54 ;
V_48 -> V_86 = V_82 ;
return 0 ;
}
T_1
F_48 ( T_4 * V_44 , T_7 V_87 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 = 0 ;
if ( V_88 > - 1 ) {
V_87 = V_88 ;
}
F_49 ( NULL , V_89 , L_10 ,
V_87 ) ;
F_8 ( V_48 ) ;
V_1 = F_50 ( V_48 , V_87 ) ;
F_10 ( V_48 ) ;
if ( V_1 == - V_18 ) {
F_8 ( V_48 ) ;
V_1 = F_45 ( V_48 , V_87 ) ;
F_10 ( V_48 ) ;
}
if ( V_1 ) {
F_36 ( NULL , L_11 , V_1 ) ;
}
V_44 -> V_87 = V_48 -> V_86 ;
return F_1 ( V_1 ) ;
}
T_1
F_51 ( T_4 * V_44 )
{
return V_3 ;
}
static void
F_52 ( struct V_47 * V_48 )
{
T_4 * V_90 ;
T_8 V_91 ;
int V_1 ;
V_90 = F_53 ( V_48 ) ;
if ( ! V_90 ) {
return;
}
#ifndef F_29
#ifdef F_16
F_19 ( V_48 , 0 , V_79 , & V_1 ) ;
#else
V_1 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x00 , NULL ) ;
#endif
if ( V_1 ) {
F_6 ( V_40 L_12 , V_1 ) ;
}
#endif
if ( V_92 && V_92 -> V_93 ) {
V_91 = V_92 -> V_93 ( V_90 ) ;
if ( V_91 ) {
V_91 ( V_90 ) ;
}
}
}
int F_54 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 ;
F_49 ( NULL , V_89 , L_13 ) ;
F_55 ( V_48 ) ;
V_1 = F_56 ( V_48 ) ;
F_57 ( V_48 ) ;
return V_1 ;
}
int F_58 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 ;
F_49 ( NULL , V_89 , L_14 ) ;
F_55 ( V_48 ) ;
V_1 = F_59 ( V_48 , F_52 ) ;
F_57 ( V_48 ) ;
if ( V_1 == - V_9 )
V_1 = 0 ;
return V_1 ;
}
static struct V_94 *
F_60 ( T_4 * V_90 )
{
struct V_94 * V_95 = F_61 ( sizeof( struct V_94 ) , V_96 ) ;
if ( V_95 )
{
V_95 -> V_90 = V_90 ;
V_95 -> V_97 . V_98 = V_99 ;
F_62 ( & V_95 -> V_100 , & V_101 . V_100 ) ;
if ( F_63 ( & V_95 -> V_97 ) ) {
F_6 ( V_40 L_15 ) ;
}
}
return V_95 ;
}
static void
F_64 ( T_4 * V_90 )
{
struct V_94 * V_95 ;
struct V_102 * V_103 , * V_104 ;
F_65 (node, q, &uf_sdio_mmc_pm_notifiers.list) {
V_95 = F_66 ( V_103 , struct V_94 , V_100 ) ;
if ( V_95 && V_95 -> V_90 == V_90 )
{
if ( F_67 ( & V_95 -> V_97 ) ) {
F_6 ( V_40 L_16 ) ;
}
V_95 -> V_90 = NULL ;
F_68 ( V_103 ) ;
F_69 ( V_95 ) ;
}
}
}
static int
V_99 ( struct V_105 * V_106 , unsigned long V_107 , void * V_108 )
{
struct V_94 * V_95 = F_70 ( V_106 ,
struct V_94 ,
V_97 ) ;
switch ( V_107 ) {
case V_109 :
case V_110 :
F_6 ( V_58 L_17 , V_41 , __LINE__ ) ;
if ( V_92 && V_92 -> V_111 ) {
V_92 -> V_111 ( V_95 -> V_90 ) ;
}
break;
case V_112 :
case V_113 :
F_6 ( V_58 L_18 , V_41 , __LINE__ ) ;
if ( V_92 && V_92 -> V_114 ) {
V_92 -> V_114 ( V_95 -> V_90 ) ;
}
break;
}
return V_115 ;
}
static int
F_71 ( struct V_47 * V_48 ,
const struct V_116 * V_117 )
{
int V_118 ;
T_4 * V_90 ;
F_55 ( V_48 ) ;
V_81 = 1 ;
V_118 = V_48 -> V_21 -> V_37 -> V_119 ;
F_6 ( L_19 ,
F_72 ( V_48 ) , V_118 ) ;
V_90 = F_61 ( sizeof( T_4 ) , V_96 ) ;
if ( V_90 == NULL ) {
F_57 ( V_48 ) ;
return - V_16 ;
}
V_90 -> V_120 . V_121 = V_48 -> V_122 ;
V_90 -> V_120 . V_123 = V_48 -> V_124 ;
V_90 -> V_120 . V_125 = V_48 -> V_80 ;
V_90 -> V_120 . V_126 = V_48 -> V_127 ;
V_90 -> V_87 = V_48 -> V_86 ;
V_90 -> V_49 = ( void * ) V_48 ;
V_90 -> V_128 = 0 ;
if ( V_129 ) {
V_90 -> V_128 |= V_130 ;
}
if ( V_48 -> V_21 -> V_37 -> V_56 & V_57 ) {
F_49 ( NULL , V_89 , L_20 ) ;
}
#ifdef F_16
V_48 -> V_21 -> V_131 |= F_16 ;
#endif
F_73 ( V_48 , V_90 ) ;
#ifdef F_74
if ( F_60 ( V_90 ) == NULL ) {
F_36 ( NULL , L_21 , V_41 ) ;
}
#endif
if ( V_92 && V_92 -> V_132 ) {
F_75 ( V_118 , & V_48 -> V_133 ) ;
V_92 -> V_132 ( V_90 ) ;
}
F_57 ( V_48 ) ;
#ifdef F_76
F_49 ( NULL , V_89 , L_22 ) ;
F_77 ( & V_134 ) ;
#endif
return 0 ;
}
static void
F_78 ( struct V_47 * V_48 )
{
T_4 * V_90 ;
V_90 = F_53 ( V_48 ) ;
if ( ! V_90 ) {
return;
}
F_79 ( NULL , L_23 ) ;
if ( V_92 && V_92 -> V_135 ) {
F_80 ( V_48 -> V_21 -> V_37 -> V_119 ) ;
V_92 -> V_135 ( V_90 ) ;
}
#ifdef F_74
F_64 ( V_90 ) ;
#endif
F_69 ( V_90 ) ;
}
static int
F_81 ( struct V_124 * V_133 )
{
F_49 ( NULL , V_89 , L_24 ) ;
return 0 ;
}
static int
F_82 ( struct V_124 * V_133 )
{
F_49 ( NULL , V_89 , L_25 ) ;
#ifdef F_76
F_49 ( NULL , V_89 , L_26 ) ;
F_77 ( & V_134 ) ;
#endif
return 0 ;
}
T_1
F_83 ( T_9 * V_136 )
{
int V_1 ;
F_6 ( L_27 ) ;
if ( V_92 ) {
F_36 ( NULL , L_28 ) ;
return V_15 ;
}
#ifdef F_76
F_84 ( & V_134 , V_137 , L_29 ) ;
#endif
V_92 = V_136 ;
#ifdef F_74
F_85 ( & V_101 . V_100 ) ;
#endif
V_1 = F_86 ( & V_138 ) ;
if ( V_1 ) {
F_6 ( V_40 L_30 , V_1 ) ;
return F_1 ( V_1 ) ;
}
return V_4 ;
}
void
F_87 ( T_9 * V_136 )
{
F_6 ( V_58 L_31 ) ;
#ifdef F_76
F_88 ( & V_134 ) ;
#endif
F_89 ( & V_138 ) ;
V_92 = NULL ;
}
