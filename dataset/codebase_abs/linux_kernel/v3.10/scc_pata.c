static T_1 F_1 ( unsigned long V_1 )
{
T_2 V_2 = F_2 ( ( void * ) V_1 ) ;
return ( T_1 ) V_2 ;
}
static void F_3 ( T_3 * V_3 , T_1 V_4 )
{
F_4 ( ( void * ) V_3 -> V_5 . V_6 , V_4 ) ;
F_5 () ;
F_2 ( ( void * ) ( V_3 -> V_7 + 0x01c ) ) ;
F_5 () ;
}
static T_1 F_6 ( T_3 * V_3 )
{
return ( T_1 ) F_2 ( ( void * ) V_3 -> V_5 . V_8 ) ;
}
static T_1 F_7 ( T_3 * V_3 )
{
return ( T_1 ) F_2 ( ( void * ) V_3 -> V_5 . V_9 ) ;
}
static T_1 F_8 ( T_3 * V_3 )
{
return ( T_1 ) F_2 ( ( void * ) ( V_3 -> V_7 + 4 ) ) ;
}
static void F_9 ( T_3 * V_3 , T_1 V_10 )
{
F_4 ( ( void * ) V_3 -> V_5 . V_9 , V_10 ) ;
F_5 () ;
F_2 ( ( void * ) ( V_3 -> V_7 + 0x01c ) ) ;
F_5 () ;
}
static void F_10 ( unsigned long V_1 , void * V_11 , T_2 V_12 )
{
T_4 * V_13 = ( T_4 * ) V_11 ;
while ( V_12 -- ) {
* V_13 ++ = F_11 ( F_2 ( ( void * ) V_1 ) ) ;
}
}
static void F_12 ( unsigned long V_1 , void * V_11 , T_2 V_12 )
{
T_4 * V_13 = ( T_4 * ) V_11 ;
while ( V_12 -- ) {
* V_13 ++ = F_11 ( F_2 ( ( void * ) V_1 ) ) ;
* V_13 ++ = F_11 ( F_2 ( ( void * ) V_1 ) ) ;
}
}
static void F_13 ( T_1 V_11 , unsigned long V_1 )
{
F_4 ( ( void * ) V_1 , V_11 ) ;
}
static void
F_14 ( unsigned long V_1 , void * V_11 , T_2 V_12 )
{
T_4 * V_13 = ( T_4 * ) V_11 ;
while ( V_12 -- ) {
F_4 ( ( void * ) V_1 , F_15 ( * V_13 ++ ) ) ;
}
}
static void
F_16 ( unsigned long V_1 , void * V_11 , T_2 V_12 )
{
T_4 * V_13 = ( T_4 * ) V_11 ;
while ( V_12 -- ) {
F_4 ( ( void * ) V_1 , F_15 ( * V_13 ++ ) ) ;
F_4 ( ( void * ) V_1 , F_15 ( * V_13 ++ ) ) ;
}
}
static void F_17 ( T_3 * V_3 , T_5 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_3 ) ;
unsigned long V_17 = V_16 -> V_10 ;
unsigned long V_18 = V_17 + 0xff0 ;
unsigned long V_19 = V_17 + 0x000 ;
unsigned long V_20 = V_17 + 0x004 ;
unsigned long V_21 ;
int V_22 ;
const T_1 V_23 = V_14 -> V_24 - V_25 ;
V_21 = F_2 ( ( void V_26 * ) V_18 ) ;
if ( V_21 & V_27 ) {
V_22 = 1 ;
} else {
V_22 = 0 ;
}
V_21 = V_28 [ V_22 ] [ V_23 ] << 16 | V_29 [ V_22 ] [ V_23 ] ;
F_4 ( ( void V_26 * ) V_19 , V_21 ) ;
V_21 = V_30 [ V_22 ] [ V_23 ] ;
F_4 ( ( void V_26 * ) V_20 , V_21 ) ;
}
static void F_19 ( T_3 * V_3 , T_5 * V_14 )
{
struct V_15 * V_16 = F_18 ( V_3 ) ;
unsigned long V_17 = V_16 -> V_10 ;
unsigned long V_18 = V_17 + 0xff0 ;
unsigned long V_31 = V_17 + 0x008 ;
unsigned long V_32 = V_17 + 0x00c ;
unsigned long V_33 = V_17 + 0x010 ;
unsigned long V_34 = V_17 + 0x014 ;
unsigned long V_35 = V_17 + 0x018 ;
unsigned long V_36 = V_17 + 0x020 ;
int V_37 = V_14 -> V_38 & 1 ;
int V_22 , V_39 ;
unsigned long V_21 ;
unsigned long V_40 ;
const T_1 V_41 = V_14 -> V_42 ;
V_21 = F_2 ( ( void V_26 * ) V_18 ) ;
if ( V_21 & V_27 ) {
V_22 = 1 ;
} else {
V_22 = 0 ;
}
V_39 = V_41 - V_43 ;
V_40 = V_44 [ V_22 ] [ V_39 ] ;
if ( V_37 ) {
F_4 ( ( void V_26 * ) V_33 , V_45 [ V_22 ] [ V_39 ] ) ;
F_4 ( ( void V_26 * ) V_34 , V_46 [ V_22 ] [ V_39 ] ) ;
V_40 = V_40 << 2 ;
F_4 ( ( void V_26 * ) V_36 , ( F_2 ( ( void V_26 * ) V_36 ) & ~ V_47 ) | V_40 ) ;
} else {
F_4 ( ( void V_26 * ) V_31 , V_45 [ V_22 ] [ V_39 ] ) ;
F_4 ( ( void V_26 * ) V_32 , V_46 [ V_22 ] [ V_39 ] ) ;
F_4 ( ( void V_26 * ) V_36 , ( F_2 ( ( void V_26 * ) V_36 ) & ~ V_48 ) | V_40 ) ;
}
V_21 = V_49 [ V_22 ] [ V_39 ] << 16 | V_50 [ V_22 ] [ V_39 ] ;
F_4 ( ( void V_26 * ) V_35 , V_21 ) ;
}
static void F_20 ( T_5 * V_14 , int V_51 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_1 V_52 = V_14 -> V_38 & 1 ;
T_1 V_53 = F_8 ( V_3 ) ;
if ( V_51 )
V_53 |= ( 1 << ( 5 + V_52 ) ) ;
else
V_53 &= ~ ( 1 << ( 5 + V_52 ) ) ;
F_13 ( V_53 , V_3 -> V_7 + 4 ) ;
}
static int F_21 ( T_5 * V_14 , struct V_54 * V_4 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_2 V_55 = ( V_4 -> V_56 & V_57 ) ? 0 : V_58 ;
T_1 V_53 ;
if ( F_22 ( V_14 , V_4 ) == 0 )
return 1 ;
F_4 ( ( void V_26 * ) ( V_3 -> V_7 + 8 ) , V_3 -> V_59 ) ;
F_4 ( ( void V_26 * ) V_3 -> V_7 , V_55 ) ;
V_53 = F_8 ( V_3 ) ;
F_4 ( ( void V_26 * ) ( V_3 -> V_7 + 4 ) , V_53 | 6 ) ;
return 0 ;
}
static void F_23 ( T_5 * V_14 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_1 V_60 = F_1 ( V_3 -> V_7 ) ;
F_13 ( V_60 | 1 , V_3 -> V_7 ) ;
}
static int F_24 ( T_5 * V_14 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_1 V_53 , V_60 ;
V_60 = F_1 ( V_3 -> V_7 ) ;
F_13 ( V_60 & ~ 1 , V_3 -> V_7 ) ;
V_53 = F_8 ( V_3 ) ;
F_13 ( V_53 | 6 , V_3 -> V_7 + 4 ) ;
return ( V_53 & 7 ) != 4 ? ( 0x10 | V_53 ) : 0 ;
}
static int F_25 ( T_5 * V_14 )
{
T_3 * V_3 = V_14 -> V_3 ;
void V_26 * V_7 = ( void V_26 * ) V_3 -> V_7 ;
unsigned long V_61 = V_3 -> V_7 + 0x014 ;
T_2 V_21 ;
int V_53 , V_62 = 0 ;
static int V_63 = 0 ;
if ( ! ( F_2 ( ( void V_26 * ) V_3 -> V_5 . V_9 )
& V_64 ) &&
V_14 -> V_65 == V_66 && V_14 -> V_67 > V_68 ) {
V_21 = F_2 ( ( void V_26 * ) V_61 ) ;
if ( ! ( V_21 & V_69 ) ) {
F_26 ( V_70 L_1 ,
V_14 -> V_71 ) ;
V_62 = 1 ;
if ( V_63 ++ ) {
struct V_72 * V_73 = V_3 -> V_73 ;
T_5 * V_14 ;
int V_74 ;
if ( V_73 )
V_73 -> V_75 |= V_76 ;
F_27 (i, drive, hwif)
V_14 -> V_77 ++ ;
}
}
}
while ( 1 ) {
V_21 = F_2 ( ( void V_26 * ) V_61 ) ;
if ( V_21 & V_78 ) {
F_26 ( V_70 L_2 , V_79 ) ;
F_4 ( ( void V_26 * ) V_61 , V_78 | V_80 ) ;
F_4 ( V_7 , F_2 ( V_7 ) & ~ V_81 ) ;
continue;
}
if ( V_21 & V_82 ) {
T_2 V_83 , V_84 ;
unsigned long V_17 = V_3 -> V_85 ;
V_83 = F_2 ( ( void V_26 * ) ( V_17 + 0xF50 ) ) ;
V_84 = F_2 ( ( void V_26 * ) ( V_17 + 0xF54 ) ) ;
F_26 ( V_70 L_3 , V_79 , V_83 , V_84 ) ;
F_4 ( ( void V_26 * ) V_61 , V_82 | V_80 ) ;
F_4 ( V_7 , F_2 ( V_7 ) & ~ V_81 ) ;
continue;
}
if ( V_21 & V_86 ) {
F_26 ( V_70 L_4 , V_79 ) ;
F_4 ( ( void V_26 * ) V_61 , V_86 | V_80 ) ;
F_4 ( V_7 , F_2 ( V_7 ) & ~ V_81 ) ;
continue;
}
if ( V_21 & V_87 ) {
F_4 ( V_7 , F_2 ( V_7 ) & ~ V_81 ) ;
F_26 ( V_70 L_5 , V_79 ) ;
F_4 ( ( void V_26 * ) V_61 , V_87 | V_80 ) ;
continue;
}
if ( V_21 & V_80 ) {
F_26 ( V_70 L_6 , V_79 ) ;
F_4 ( ( void V_26 * ) V_61 , V_80 ) ;
F_28 ( V_14 ) ;
continue;
}
if ( V_21 & V_88 ) {
F_4 ( ( void V_26 * ) V_61 , V_88 ) ;
continue;
}
if ( V_21 & V_69 ) {
F_4 ( ( void V_26 * ) V_61 , V_69 ) ;
continue;
}
if ( V_21 & V_89 ) {
F_4 ( ( void V_26 * ) V_61 , V_89 ) ;
continue;
}
break;
}
V_53 = F_24 ( V_14 ) ;
if ( V_62 )
V_53 |= 2 ;
return V_53 ;
}
static int F_29 ( T_5 * V_14 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_2 V_90 = F_2 ( ( void V_26 * ) V_3 -> V_7 + 0x014 ) ;
if ( ( F_2 ( ( void V_26 * ) V_3 -> V_5 . V_9 )
& V_64 ) &&
( V_90 & V_91 ) )
return 1 ;
if ( V_90 & V_89 )
return 1 ;
return 0 ;
}
static T_1 F_30 ( T_5 * V_14 )
{
T_3 * V_3 = V_14 -> V_3 ;
T_1 V_92 = V_3 -> V_93 ;
if ( ( V_14 -> V_65 != V_66 ) && ( V_92 & 0xE0 ) ) {
F_26 ( V_94 L_7 ,
V_79 , V_14 -> V_71 ) ;
V_92 = V_95 ;
}
return V_92 ;
}
static int F_31 ( struct V_96 * V_97 , const char * V_71 )
{
void V_26 * V_9 ;
void V_26 * V_98 ;
int V_74 , V_99 ;
for ( V_74 = 0 ; V_74 < V_100 ; V_74 ++ ) {
if ( V_15 [ V_74 ] . V_10 == 0 )
break;
}
if ( V_74 >= V_100 )
return - V_101 ;
V_99 = F_32 ( V_97 , ( 1 << 2 ) - 1 , V_71 ) ;
if ( V_99 < 0 ) {
F_26 ( V_102 L_8 , V_71 ) ;
return V_99 ;
}
V_9 = F_33 ( V_97 , 0 ) ;
if ( ! V_9 )
goto V_103;
V_98 = F_33 ( V_97 , 1 ) ;
if ( ! V_98 )
goto V_104;
F_34 ( V_97 ) ;
V_15 [ V_74 ] . V_10 = ( unsigned long ) V_9 ;
V_15 [ V_74 ] . V_105 = ( unsigned long ) V_98 ;
F_35 ( V_97 , ( void * ) & V_15 [ V_74 ] ) ;
return 1 ;
V_104:
F_36 ( V_9 ) ;
V_103:
return - V_101 ;
}
static int F_37 ( struct V_96 * V_97 ,
const struct V_106 * V_107 )
{
struct V_15 * V_16 = F_38 ( V_97 ) ;
struct V_108 * V_109 ;
struct V_110 V_111 , * V_112 [] = { & V_111 } ;
int V_74 , V_113 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
for ( V_74 = 0 ; V_74 <= 8 ; V_74 ++ )
V_111 . V_114 [ V_74 ] = V_16 -> V_105 + 0x20 + V_74 * 4 ;
V_111 . V_115 = V_97 -> V_115 ;
V_111 . V_97 = & V_97 -> V_97 ;
V_113 = F_39 ( V_107 , V_112 , 1 , & V_109 ) ;
if ( V_113 )
return V_113 ;
V_16 -> V_109 = V_109 ;
return 0 ;
}
static int F_40 ( struct V_96 * V_97 , const struct V_106 * V_107 )
{
unsigned long V_17 ;
unsigned long V_7 ;
unsigned long V_18 ;
unsigned long V_116 ;
unsigned long V_117 ;
unsigned long V_118 ;
T_2 V_21 = 0 ;
struct V_15 * V_16 ;
int V_113 ;
V_113 = F_41 ( V_97 ) ;
if ( V_113 )
goto V_119;
V_113 = F_31 ( V_97 , V_107 -> V_71 ) ;
if ( V_113 < 0 )
goto V_119;
V_16 = F_38 ( V_97 ) ;
V_17 = V_16 -> V_10 ;
V_7 = V_16 -> V_105 ;
V_18 = V_17 + 0xff0 ;
V_116 = V_7 + 0x010 ;
V_117 = V_17 + 0x024 ;
V_118 = V_17 + 0xf00 ;
V_21 = 0 ;
F_4 ( ( void * ) V_18 , V_21 ) ;
V_21 |= V_27 ;
F_4 ( ( void * ) V_18 , V_21 ) ;
V_21 |= V_120 | V_121 ;
F_4 ( ( void * ) V_18 , V_21 ) ;
V_21 |= V_122 ;
F_4 ( ( void * ) V_18 , V_21 ) ;
for (; ; ) {
V_21 = F_2 ( ( void * ) V_18 ) ;
if ( V_21 & V_122 )
break;
F_42 ( 5000 ) ;
}
V_21 |= V_123 ;
F_4 ( ( void * ) V_18 , V_21 ) ;
F_4 ( ( void * ) V_118 , V_124 ) ;
F_4 ( ( void * ) V_117 , V_125 ) ;
F_4 ( ( void * ) V_116 , V_126 ) ;
V_113 = F_37 ( V_97 , V_107 ) ;
V_119:
return V_113 ;
}
static void F_43 ( T_5 * V_14 , struct V_127 * V_128 , T_1 V_129 )
{
struct V_130 * V_5 = & V_14 -> V_3 -> V_5 ;
if ( V_129 & V_131 )
F_13 ( V_128 -> V_132 , V_5 -> V_133 ) ;
if ( V_129 & V_134 )
F_13 ( V_128 -> V_135 , V_5 -> V_136 ) ;
if ( V_129 & V_137 )
F_13 ( V_128 -> V_138 , V_5 -> V_139 ) ;
if ( V_129 & V_140 )
F_13 ( V_128 -> V_141 , V_5 -> V_142 ) ;
if ( V_129 & V_143 )
F_13 ( V_128 -> V_144 , V_5 -> V_145 ) ;
if ( V_129 & V_146 )
F_13 ( V_128 -> V_147 , V_5 -> V_148 ) ;
}
static void F_44 ( T_5 * V_14 , struct V_127 * V_128 , T_1 V_129 )
{
struct V_130 * V_5 = & V_14 -> V_3 -> V_5 ;
if ( V_129 & V_149 )
V_128 -> error = F_1 ( V_5 -> V_133 ) ;
if ( V_129 & V_134 )
V_128 -> V_135 = F_1 ( V_5 -> V_136 ) ;
if ( V_129 & V_137 )
V_128 -> V_138 = F_1 ( V_5 -> V_139 ) ;
if ( V_129 & V_140 )
V_128 -> V_141 = F_1 ( V_5 -> V_142 ) ;
if ( V_129 & V_143 )
V_128 -> V_144 = F_1 ( V_5 -> V_145 ) ;
if ( V_129 & V_146 )
V_128 -> V_147 = F_1 ( V_5 -> V_148 ) ;
}
static void F_45 ( T_5 * V_14 , struct V_54 * V_4 ,
void * V_150 , unsigned int V_151 )
{
unsigned long V_152 = V_14 -> V_3 -> V_5 . V_152 ;
V_151 ++ ;
if ( V_14 -> V_153 ) {
F_12 ( V_152 , V_150 , V_151 / 4 ) ;
if ( ( V_151 & 3 ) >= 2 )
F_10 ( V_152 , ( T_1 * ) V_150 + ( V_151 & ~ 3 ) , 1 ) ;
} else
F_10 ( V_152 , V_150 , V_151 / 2 ) ;
}
static void F_46 ( T_5 * V_14 , struct V_54 * V_4 ,
void * V_150 , unsigned int V_151 )
{
unsigned long V_152 = V_14 -> V_3 -> V_5 . V_152 ;
V_151 ++ ;
if ( V_14 -> V_153 ) {
F_16 ( V_152 , V_150 , V_151 / 4 ) ;
if ( ( V_151 & 3 ) >= 2 )
F_14 ( V_152 , ( T_1 * ) V_150 + ( V_151 & ~ 3 ) , 1 ) ;
} else
F_14 ( V_152 , V_150 , V_151 / 2 ) ;
}
static void F_47 ( T_3 * V_3 )
{
struct V_96 * V_97 = F_48 ( V_3 -> V_97 ) ;
struct V_15 * V_16 = F_38 ( V_97 ) ;
unsigned long V_7 = V_16 -> V_105 ;
F_49 ( V_3 , V_16 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_85 = V_16 -> V_10 ;
}
static void F_50 ( T_3 * V_3 )
{
struct V_96 * V_97 = F_48 ( V_3 -> V_97 ) ;
V_3 -> V_154 = NULL ;
if ( F_38 ( V_97 ) == NULL )
return;
F_47 ( V_3 ) ;
}
static int F_51 ( T_3 * V_3 , const struct V_106 * V_107 )
{
return F_52 ( V_3 ) ;
}
static T_1 F_53 ( T_3 * V_3 )
{
return V_155 ;
}
static void F_54 ( T_3 * V_3 )
{
F_4 ( ( void V_26 * ) ( V_3 -> V_7 + 0x018 ) , V_3 -> V_59 ) ;
if ( F_2 ( ( void V_26 * ) ( V_3 -> V_85 + 0xff0 ) ) & V_27 )
V_3 -> V_93 = V_156 ;
else
V_3 -> V_93 = V_157 ;
}
static int F_55 ( struct V_96 * V_97 , const struct V_158 * V_159 )
{
return F_40 ( V_97 , & V_160 ) ;
}
static void F_56 ( struct V_96 * V_97 )
{
struct V_15 * V_16 = F_38 ( V_97 ) ;
struct V_108 * V_109 = V_16 -> V_109 ;
F_57 ( V_109 ) ;
F_36 ( ( void * ) V_16 -> V_105 ) ;
F_36 ( ( void * ) V_16 -> V_10 ) ;
F_58 ( V_97 , ( 1 << 2 ) - 1 ) ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
static int T_6 F_59 ( void )
{
return F_60 ( & V_161 ) ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_161 ) ;
}
