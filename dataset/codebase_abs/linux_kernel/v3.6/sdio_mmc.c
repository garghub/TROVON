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
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_12 ( T_4 * V_44 , T_5 V_45 , T_6 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
F_13 ( V_48 , V_46 , V_45 , & V_29 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_14 ( T_4 * V_44 , T_5 V_45 , T_7 * V_46 )
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
F_15 ( T_4 * V_44 , T_5 V_45 , T_7 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
T_2 V_50 , V_51 ;
F_8 ( V_48 ) ;
V_51 = ( V_46 >> 8 ) & 0xFF ;
F_13 ( V_48 , V_51 , V_45 + 1 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
V_50 = V_46 & 0xFF ;
F_13 ( V_48 , V_50 , V_45 , & V_29 ) ;
if ( V_29 ) {
F_10 ( V_48 ) ;
return F_1 ( V_29 ) ;
}
F_10 ( V_48 ) ;
return V_4 ;
}
T_1
F_16 ( T_4 * V_44 , T_5 V_45 , T_6 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
#ifdef F_17
* V_46 = F_18 ( V_48 , V_45 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 0 , 0 , V_45 , 0 , V_46 ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_19 ( T_4 * V_44 , T_5 V_45 , T_6 V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
F_8 ( V_48 ) ;
#ifdef F_17
F_20 ( V_48 , V_46 , V_45 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_45 , V_46 , NULL ) ;
#endif
F_10 ( V_48 ) ;
if ( V_29 ) {
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_21 ( T_4 * V_44 , T_5 V_45 , void * V_46 , T_5 V_53 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_22 ( V_48 , V_46 , V_45 , V_53 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
T_1
F_23 ( T_4 * V_44 , T_5 V_45 , const void * V_46 , T_5 V_53 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_8 ( V_48 ) ;
V_29 = F_24 ( V_48 , V_45 , ( void * ) V_46 , V_53 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_11 ( V_29 ) ;
return F_1 ( V_29 ) ;
}
return V_4 ;
}
static int
F_25 ( struct V_20 * V_21 )
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
F_26 ( V_21 ) ;
V_21 -> V_37 -> V_64 . V_65 = V_66 ;
V_21 -> V_37 -> V_67 -> V_68 ( V_21 -> V_37 , & V_21 -> V_37 -> V_64 ) ;
return 0 ;
}
static int
F_27 ( struct V_20 * V_21 )
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
F_28 ( T_4 * V_44 , T_5 V_72 )
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
V_29 = F_25 ( V_48 -> V_21 ) ;
} else {
V_29 = F_27 ( V_48 -> V_21 ) ;
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
F_29 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
#ifdef F_30
F_31 ( V_48 ) ;
#else
F_8 ( V_48 ) ;
#ifdef F_17
F_20 ( V_48 , 0x3 , V_79 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x03 , NULL ) ;
#endif
F_10 ( V_48 ) ;
F_32 () ;
if ( V_29 ) {
F_6 ( V_40 L_5 , V_41 , V_29 ) ;
return F_1 ( V_29 ) ;
}
#endif
return V_4 ;
}
T_1
F_33 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 = 0 ;
#ifdef F_30
F_34 ( V_48 ) ;
#else
F_8 ( V_48 ) ;
#ifdef F_17
F_20 ( V_48 , 0 , V_79 , & V_29 ) ;
#else
V_29 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x00 , NULL ) ;
#endif
F_10 ( V_48 ) ;
F_32 () ;
if ( V_29 ) {
F_6 ( V_40 L_5 , V_41 , V_29 ) ;
return F_1 ( V_29 ) ;
}
#endif
return V_4 ;
}
void F_35 ( T_4 * V_44 )
{
}
T_1
F_36 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_37 () ;
F_8 ( V_48 ) ;
V_29 = F_38 ( V_48 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_39 ( NULL , L_6 , V_48 -> V_80 ) ;
}
F_32 () ;
return F_1 ( V_29 ) ;
}
T_1
F_40 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_29 ;
F_37 () ;
F_8 ( V_48 ) ;
V_29 = F_41 ( V_48 ) ;
F_10 ( V_48 ) ;
if ( V_29 ) {
F_39 ( NULL , L_7 , V_48 -> V_80 ) ;
}
F_32 () ;
return F_1 ( V_29 ) ;
}
void
F_42 ( T_4 * V_44 )
{
}
void
F_43 ( T_4 * V_44 )
{
}
T_1
F_44 ( T_4 * V_44 )
{
#if V_81 >= F_45 ( 2 , 6 , 32 )
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_73 * V_37 = V_48 -> V_21 -> V_37 ;
F_8 ( V_48 ) ;
if ( ! V_82 ) {
F_46 ( V_37 ) ;
V_82 = 1 ;
} else {
F_6 ( V_58 L_8 ) ;
}
F_10 ( V_48 ) ;
#endif
return V_4 ;
}
void
F_47 ( T_4 * V_44 )
{
#if V_81 >= F_45 ( 2 , 6 , 32 )
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
struct V_73 * V_37 = V_48 -> V_21 -> V_37 ;
F_8 ( V_48 ) ;
if ( V_82 ) {
F_48 ( V_37 ) ;
V_82 = 0 ;
} else {
F_6 ( V_58 L_9 ) ;
}
F_10 ( V_48 ) ;
#endif
}
static int
F_49 ( struct V_47 * V_48 , unsigned V_83 )
{
int V_54 ;
if ( V_83 > V_48 -> V_21 -> V_37 -> V_84 )
return - V_14 ;
if ( V_83 == 0 ) {
V_83 = F_50 ( V_48 -> V_85 , V_48 -> V_21 -> V_37 -> V_84 ) ;
V_83 = F_50 ( V_83 , 512u ) ;
}
V_54 = F_3 ( V_48 -> V_21 , 1 , 0 ,
F_51 ( V_48 -> V_80 ) + V_86 ,
V_83 & 0xff , NULL ) ;
if ( V_54 && V_54 != - V_18 )
return V_54 ;
V_54 = F_3 ( V_48 -> V_21 , 1 , 0 ,
F_51 ( V_48 -> V_80 ) + V_86 + 1 ,
( V_83 >> 8 ) & 0xff , NULL ) ;
if ( V_54 )
return V_54 ;
V_48 -> V_87 = V_83 ;
return 0 ;
}
T_1
F_52 ( T_4 * V_44 , T_7 V_88 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 = 0 ;
if ( V_89 > - 1 ) {
V_88 = V_89 ;
}
F_53 ( NULL , V_90 , L_10 ,
V_88 ) ;
F_8 ( V_48 ) ;
V_1 = F_54 ( V_48 , V_88 ) ;
F_10 ( V_48 ) ;
if ( V_1 == - V_18 ) {
F_8 ( V_48 ) ;
V_1 = F_49 ( V_48 , V_88 ) ;
F_10 ( V_48 ) ;
}
if ( V_1 ) {
F_39 ( NULL , L_11 , V_1 ) ;
}
V_44 -> V_88 = V_48 -> V_87 ;
return F_1 ( V_1 ) ;
}
T_1
F_55 ( T_4 * V_44 )
{
return V_3 ;
}
static void
F_56 ( struct V_47 * V_48 )
{
T_4 * V_91 ;
T_8 V_92 ;
int V_1 ;
V_91 = F_57 ( V_48 ) ;
if ( ! V_91 ) {
return;
}
#ifndef F_30
#ifdef F_17
F_20 ( V_48 , 0 , V_79 , & V_1 ) ;
#else
V_1 = F_3 ( V_48 -> V_21 , 1 , 0 , V_79 , 0x00 , NULL ) ;
#endif
if ( V_1 ) {
F_6 ( V_40 L_12 , V_1 ) ;
}
#endif
if ( V_93 && V_93 -> V_94 ) {
V_92 = V_93 -> V_94 ( V_91 ) ;
if ( V_92 ) {
V_92 ( V_91 ) ;
}
}
}
int
F_58 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 ;
F_53 ( NULL , V_90 , L_13 ) ;
F_59 ( V_48 ) ;
V_1 = F_60 ( V_48 ) ;
F_61 ( V_48 ) ;
return V_1 ;
}
int
F_62 ( T_4 * V_44 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
int V_1 ;
F_53 ( NULL , V_90 , L_14 ) ;
F_59 ( V_48 ) ;
V_1 = F_63 ( V_48 , F_56 ) ;
F_61 ( V_48 ) ;
if ( V_1 == - V_9 ) {
V_1 = 0 ;
}
return V_1 ;
}
static struct V_95 *
F_64 ( T_4 * V_91 )
{
struct V_95 * V_96 = F_65 ( sizeof( struct V_95 ) , V_97 ) ;
if ( V_96 )
{
V_96 -> V_91 = V_91 ;
V_96 -> V_98 . V_99 = V_100 ;
F_66 ( & V_96 -> V_101 , & V_102 . V_101 ) ;
if ( F_67 ( & V_96 -> V_98 ) ) {
F_6 ( V_40 L_15 ) ;
}
}
return V_96 ;
}
static void
F_68 ( T_4 * V_91 )
{
struct V_95 * V_96 ;
struct V_103 * V_104 , * V_105 ;
F_69 (node, q, &uf_sdio_mmc_pm_notifiers.list) {
V_96 = F_70 ( V_104 , struct V_95 , V_101 ) ;
if ( V_96 && V_96 -> V_91 == V_91 )
{
if ( F_71 ( & V_96 -> V_98 ) ) {
F_6 ( V_40 L_16 ) ;
}
V_96 -> V_91 = NULL ;
F_72 ( V_104 ) ;
F_73 ( V_96 ) ;
}
}
}
static int
V_100 ( struct V_106 * V_107 , unsigned long V_108 , void * V_109 )
{
struct V_95 * V_96 = F_74 ( V_107 ,
struct V_95 ,
V_98 ) ;
switch ( V_108 ) {
case V_110 :
case V_111 :
F_6 ( V_58 L_17 , V_41 , __LINE__ ) ;
if ( V_93 && V_93 -> V_112 ) {
V_93 -> V_112 ( V_96 -> V_91 ) ;
}
break;
case V_113 :
case V_114 :
F_6 ( V_58 L_18 , V_41 , __LINE__ ) ;
if ( V_93 && V_93 -> V_115 ) {
V_93 -> V_115 ( V_96 -> V_91 ) ;
}
break;
}
return V_116 ;
}
static int
F_75 ( struct V_47 * V_48 ,
const struct V_117 * V_118 )
{
int V_119 ;
T_4 * V_91 ;
F_37 () ;
F_59 ( V_48 ) ;
#if V_81 >= F_45 ( 2 , 6 , 32 )
V_82 = 1 ;
#endif
V_119 = V_48 -> V_21 -> V_37 -> V_120 ;
F_6 ( L_19 ,
F_76 ( V_48 ) , V_119 ) ;
V_91 = ( T_4 * ) F_65 ( sizeof( T_4 ) ,
V_97 ) ;
if ( V_91 == NULL ) {
F_61 ( V_48 ) ;
return - V_16 ;
}
V_91 -> V_121 . V_122 = V_48 -> V_123 ;
V_91 -> V_121 . V_124 = V_48 -> V_125 ;
V_91 -> V_121 . V_126 = V_48 -> V_80 ;
V_91 -> V_121 . V_127 = V_48 -> V_128 ;
V_91 -> V_88 = V_48 -> V_87 ;
V_91 -> V_49 = ( void * ) V_48 ;
V_91 -> V_129 = 0 ;
if ( V_130 ) {
V_91 -> V_129 |= V_131 ;
}
if ( V_48 -> V_21 -> V_37 -> V_56 & V_57 ) {
F_53 ( NULL , V_90 , L_20 ) ;
}
#ifdef F_17
V_48 -> V_21 -> V_132 |= F_17 ;
#endif
F_77 ( V_48 , V_91 ) ;
#if V_81 >= F_45 ( 2 , 6 , 32 )
#ifdef F_78
if ( F_64 ( V_91 ) == NULL ) {
F_39 ( NULL , L_21 , V_41 ) ;
}
#endif
#endif
if ( V_93 && V_93 -> V_133 ) {
F_79 ( V_119 , & V_48 -> V_134 ) ;
V_93 -> V_133 ( V_91 ) ;
}
F_61 ( V_48 ) ;
#ifdef F_80
F_53 ( NULL , V_90 , L_22 ) ;
F_81 ( & V_135 ) ;
#endif
F_32 () ;
return 0 ;
}
static void
F_82 ( struct V_47 * V_48 )
{
T_4 * V_91 ;
V_91 = F_57 ( V_48 ) ;
if ( ! V_91 ) {
return;
}
F_37 () ;
F_83 ( NULL , L_23 ) ;
if ( V_93 && V_93 -> V_136 ) {
F_84 ( V_48 -> V_21 -> V_37 -> V_120 ) ;
V_93 -> V_136 ( V_91 ) ;
}
#if V_81 >= F_45 ( 2 , 6 , 32 )
#ifdef F_78
F_68 ( V_91 ) ;
#endif
#endif
F_73 ( V_91 ) ;
F_32 () ;
}
static int
F_85 ( struct V_125 * V_134 )
{
F_37 () ;
F_53 ( NULL , V_90 , L_24 ) ;
F_32 () ;
return 0 ;
}
static int
F_86 ( struct V_125 * V_134 )
{
F_37 () ;
F_53 ( NULL , V_90 , L_25 ) ;
#ifdef F_80
F_53 ( NULL , V_90 , L_26 ) ;
F_81 ( & V_135 ) ;
#endif
F_32 () ;
return 0 ;
}
T_1
F_87 ( T_9 * V_137 )
{
int V_1 ;
F_6 ( L_27 ) ;
if ( V_93 ) {
F_39 ( NULL , L_28 ) ;
return V_15 ;
}
#ifdef F_80
F_88 ( & V_135 , V_138 , L_29 ) ;
#endif
V_93 = V_137 ;
#if V_81 >= F_45 ( 2 , 6 , 32 )
#ifdef F_78
F_89 ( & V_102 . V_101 ) ;
#endif
#endif
V_1 = F_90 ( & V_139 ) ;
if ( V_1 ) {
F_6 ( V_40 L_30 , V_1 ) ;
return F_1 ( V_1 ) ;
}
return V_4 ;
}
void
F_91 ( T_9 * V_137 )
{
F_6 ( V_58 L_31 ) ;
#ifdef F_80
F_92 ( & V_135 ) ;
#endif
F_93 ( & V_139 ) ;
V_93 = NULL ;
}
