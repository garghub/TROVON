int F_1 ( T_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = ( F_2 ( V_1 [ 0 ] ) >> 16 ) & 0xff ;
V_3 = F_3 ( 0 , ( V_4 * ) & V_1 [ 1 ] , V_2 * 4 ) ;
* V_1 |= F_4 ( V_3 ) ;
return V_2 ;
}
static void F_5 ( struct V_5 * V_6 , T_1 * V_7 )
{
struct V_8 * V_9 ;
int V_10 , V_11 , V_12 , V_2 ;
V_7 [ 0 ] = F_4 (
F_6 ( 4 ) | F_7 ( 4 ) | F_8 ( 0 ) ) ;
V_7 [ 1 ] = F_4 ( V_13 ) ;
V_7 [ 2 ] = F_4 (
F_9 ( V_6 -> V_14 ) |
F_10 ( V_6 -> V_15 ++ % 14 + 2 ) |
F_11 ( 2 ) |
F_12 ( V_6 -> V_16 ) |
V_17 | V_18 | V_19 | V_20 ) ;
V_7 [ 3 ] = F_4 ( V_6 -> V_21 >> 32 ) ;
V_7 [ 4 ] = F_4 ( V_6 -> V_21 ) ;
V_7 [ 6 ] = F_4 ( V_22 ) ;
V_10 = 7 ;
V_11 = 7 + V_23 ;
F_13 (desc, &descriptor_list, link) {
if ( V_9 -> V_24 > 0 )
V_7 [ V_10 ++ ] = F_4 ( V_9 -> V_24 ) ;
V_7 [ V_10 ] = F_4 ( V_9 -> V_25 | ( V_11 - V_10 ) ) ;
V_10 ++ ;
V_11 += V_9 -> V_2 ;
}
V_7 [ 5 ] = F_4 ( ( V_10 - 5 - 1 ) << 16 ) ;
F_13 (desc, &descriptor_list, link) {
for ( V_12 = 0 ; V_12 < V_9 -> V_2 ; V_12 ++ )
V_7 [ V_10 + V_12 ] = F_4 ( V_9 -> V_26 [ V_12 ] ) ;
V_10 += V_9 -> V_2 ;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 += V_2 + 1 )
V_2 = F_1 ( V_7 + V_10 ) ;
F_14 ( V_11 != V_27 ) ;
}
static void F_15 ( void )
{
struct V_5 * V_6 ;
F_13 (card, &card_list, link) {
F_5 ( V_6 , V_28 ) ;
V_6 -> V_29 -> V_30 ( V_6 , V_28 ,
V_27 ) ;
}
}
static T_3 F_16 ( struct V_8 * V_9 )
{
return V_9 -> V_2 + 1 + ( V_9 -> V_24 > 0 ? 1 : 0 ) ;
}
int F_17 ( struct V_8 * V_9 )
{
T_3 V_10 ;
int V_31 ;
V_10 = 0 ;
while ( V_10 < V_9 -> V_2 )
V_10 += ( V_9 -> V_26 [ V_10 ] >> 16 ) + 1 ;
if ( V_10 != V_9 -> V_2 )
return - V_32 ;
F_18 ( & V_33 ) ;
if ( V_27 + F_16 ( V_9 ) > 256 ) {
V_31 = - V_34 ;
} else {
F_19 ( & V_9 -> V_35 , & V_36 ) ;
V_27 += F_16 ( V_9 ) ;
V_23 ++ ;
if ( V_9 -> V_24 > 0 )
V_23 ++ ;
F_15 () ;
V_31 = 0 ;
}
F_20 ( & V_33 ) ;
return V_31 ;
}
void F_21 ( struct V_8 * V_9 )
{
F_18 ( & V_33 ) ;
F_22 ( & V_9 -> V_35 ) ;
V_27 -= F_16 ( V_9 ) ;
V_23 -- ;
if ( V_9 -> V_24 > 0 )
V_23 -- ;
F_15 () ;
F_20 ( & V_33 ) ;
}
static int F_23 ( struct V_5 * V_6 , bool V_37 )
{
int V_38 = V_37 ? 5 : 1 ;
int V_39 = V_37 ? V_40 : V_41 ;
return V_6 -> V_29 -> V_42 ( V_6 , V_38 , 0 , V_39 ) ;
}
void F_24 ( struct V_5 * V_6 , bool V_43 , bool V_37 )
{
V_6 -> V_44 = V_37 ;
F_25 ( V_6 ) ;
if ( ! F_26 ( V_45 , & V_6 -> V_46 ,
V_43 ? F_27 ( V_47 , 100 ) : 0 ) )
F_28 ( V_6 ) ;
}
static void V_46 ( struct V_48 * V_49 )
{
struct V_5 * V_6 = F_29 ( V_49 , struct V_5 , V_46 . V_49 ) ;
if ( V_6 -> V_50 != 0 &&
F_30 ( F_31 () , V_6 -> V_50 + 2 * V_47 ) ) {
if ( ! F_26 ( V_45 , & V_6 -> V_46 , 2 * V_47 ) )
F_28 ( V_6 ) ;
return;
}
F_32 ( V_6 , V_51 , V_6 -> V_52 ,
V_53 ) ;
F_23 ( V_6 , V_6 -> V_44 ) ;
F_28 ( V_6 ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_52 )
{
int V_54 , V_55 = 0 ;
if ( ! V_6 -> V_56 ) {
F_34 ( V_6 , V_52 , 1ULL << 31 ,
& V_54 , & V_55 , true ) ;
if ( V_54 != 31 ) {
F_35 ( L_1 ) ;
return;
}
V_6 -> V_56 = true ;
}
F_36 ( V_6 -> V_57 , ( void * ) ( long ) V_52 ,
V_58 ) ;
}
void F_37 ( struct V_5 * V_6 , unsigned long V_59 )
{
F_25 ( V_6 ) ;
if ( ! F_38 ( & V_6 -> V_60 , V_59 ) )
F_28 ( V_6 ) ;
}
static void V_60 ( struct V_48 * V_49 )
{
struct V_5 * V_6 = F_29 ( V_49 , struct V_5 , V_60 . V_49 ) ;
struct V_61 * V_62 , * V_63 ;
struct V_64 * V_65 ;
int V_66 , V_67 , V_68 , V_69 , V_70 ;
int V_71 , V_52 , V_72 , V_73 ;
bool V_74 = false ;
bool V_75 ;
bool V_76 ;
bool V_77 ;
bool V_78 ;
T_1 V_79 [ 2 ] ;
F_39 ( & V_6 -> V_80 ) ;
if ( V_6 -> V_81 == NULL ) {
F_40 ( & V_6 -> V_80 ) ;
goto V_82;
}
V_52 = V_6 -> V_52 ;
V_65 = V_6 -> V_65 ;
F_41 ( V_65 ) ;
V_62 = V_65 -> V_26 ;
V_75 = V_62 &&
F_42 ( & V_62 -> V_83 ) == V_84 ;
V_76 = V_62 && V_62 -> V_85 ;
V_63 = V_6 -> V_86 -> V_26 ;
V_77 = V_63 && V_63 -> V_7 &&
( V_63 -> V_7 [ 2 ] & 0x000000f0 ) == 0 ;
V_78 = V_63 && V_63 -> V_7 &&
V_63 -> V_7 [ 3 ] >> 8 == V_87 ;
V_66 = V_65 -> V_88 ;
V_68 = V_6 -> V_86 -> V_88 ;
V_70 = V_6 -> V_81 -> V_88 ;
V_72 = F_43 ( F_31 () ,
V_6 -> V_50 + F_27 ( V_47 , 8 ) ) ;
if ( ( F_44 ( V_52 , V_6 -> V_89 ) &&
! V_6 -> V_90 ) ||
( V_6 -> V_89 != V_52 && V_72 ) ) {
if ( ! V_6 -> V_86 -> V_91 ) {
V_67 = V_70 ;
F_35 ( L_2 ,
L_3 , V_67 ) ;
goto V_92;
}
if ( V_77 && ! V_78 ) {
V_67 = V_70 ;
F_35 ( L_2 ,
L_4 , V_67 ) ;
goto V_92;
}
V_79 [ 0 ] = F_4 ( 0x3f ) ;
V_79 [ 1 ] = F_4 ( V_70 ) ;
F_40 ( & V_6 -> V_80 ) ;
V_73 = F_45 ( V_6 , V_93 ,
V_68 , V_52 , V_94 ,
V_95 + V_96 ,
V_79 , 8 ) ;
if ( V_73 == V_97 )
goto V_98;
V_69 = F_2 ( V_79 [ 0 ] ) ;
F_39 ( & V_6 -> V_80 ) ;
if ( V_73 == V_99 && V_52 == V_6 -> V_52 )
V_6 -> V_100 =
V_69 == 0x3f ? V_70 : 0xffc0 | V_69 ;
F_40 ( & V_6 -> V_80 ) ;
if ( V_73 == V_99 && V_69 != 0x3f ) {
if ( V_70 == V_68 )
F_33 ( V_6 , V_52 ) ;
goto V_98;
}
if ( V_73 == V_101 ) {
F_37 ( V_6 , F_27 ( V_47 , 8 ) ) ;
goto V_98;
}
F_39 ( & V_6 -> V_80 ) ;
if ( V_73 != V_99 && ! V_78 ) {
V_67 = V_70 ;
F_35 ( L_2 ,
L_5 , V_67 ) ;
goto V_92;
}
} else if ( V_6 -> V_89 != V_52 ) {
F_40 ( & V_6 -> V_80 ) ;
F_37 ( V_6 , F_27 ( V_47 , 8 ) ) ;
goto V_98;
}
V_6 -> V_89 = V_52 ;
if ( V_62 == NULL ) {
V_67 = V_70 ;
} else if ( ! V_75 ) {
F_40 ( & V_6 -> V_80 ) ;
goto V_98;
} else if ( V_76 ) {
V_67 = V_66 ;
} else {
V_67 = V_70 ;
}
V_92:
if ( ! V_6 -> V_102 &&
V_65 -> V_103 < F_46 ( V_104 ) )
V_71 = V_104 [ V_65 -> V_103 ] ;
else
V_71 = 63 ;
if ( V_6 -> V_105 ++ < 5 &&
( V_6 -> V_71 != V_71 || V_67 != V_66 ) )
V_74 = true ;
F_40 ( & V_6 -> V_80 ) ;
if ( V_74 ) {
F_35 ( L_6 ,
V_6 -> V_106 , V_67 , V_71 ) ;
F_32 ( V_6 , V_67 , V_52 , V_71 ) ;
F_23 ( V_6 , true ) ;
goto V_98;
}
if ( V_76 ) {
V_79 [ 0 ] = F_4 ( V_107 ) ;
V_73 = F_45 ( V_6 , V_108 ,
V_66 , V_52 , V_94 ,
V_95 + V_109 ,
V_79 , 4 ) ;
if ( V_73 == V_97 )
goto V_98;
}
if ( V_70 == V_68 )
F_33 ( V_6 , V_52 ) ;
V_98:
F_47 ( V_65 ) ;
V_82:
F_28 ( V_6 ) ;
}
void F_48 ( struct V_5 * V_6 ,
const struct V_110 * V_29 ,
struct V_57 * V_57 )
{
static T_4 V_106 = F_49 ( - 1 ) ;
V_6 -> V_106 = F_50 ( & V_106 ) ;
V_6 -> V_29 = V_29 ;
V_6 -> V_57 = V_57 ;
V_6 -> V_111 = 0 ;
V_6 -> V_112 = 0 ;
V_6 -> V_113 = V_114 / 8000 ;
V_6 -> V_115 = ( V_114 % 8000 ) << 19 ;
V_6 -> V_116 = V_114 ;
V_6 -> V_117 =
F_27 ( V_114 * V_47 , 8000 ) ;
V_6 -> V_118 = 0 ;
V_6 -> V_119 = V_120 ;
F_51 ( & V_6 -> V_121 ) ;
F_52 ( & V_6 -> V_122 ) ;
F_53 ( & V_6 -> V_123 ) ;
F_53 ( & V_6 -> V_124 ) ;
F_54 ( & V_6 -> V_80 ) ;
V_6 -> V_81 = NULL ;
F_55 ( & V_6 -> V_46 , V_46 ) ;
F_55 ( & V_6 -> V_60 , V_60 ) ;
}
int F_56 ( struct V_5 * V_6 ,
T_5 V_16 , T_5 V_14 , T_6 V_21 )
{
int V_31 ;
V_6 -> V_16 = V_16 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_21 = V_21 ;
F_18 ( & V_33 ) ;
F_5 ( V_6 , V_28 ) ;
V_31 = V_6 -> V_29 -> V_125 ( V_6 , V_28 , V_27 ) ;
if ( V_31 == 0 )
F_19 ( & V_6 -> V_35 , & V_126 ) ;
F_20 ( & V_33 ) ;
return V_31 ;
}
static int F_57 ( struct V_5 * V_6 , int V_127 )
{
return - V_128 ;
}
static int F_58 ( struct V_5 * V_6 , int V_127 ,
int V_129 , int V_130 )
{
return - V_128 ;
}
static void F_59 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
V_132 -> V_133 ( V_132 , V_6 , V_134 ) ;
}
static void F_60 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
V_132 -> V_133 ( V_132 , V_6 , V_134 ) ;
}
static int F_61 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
return - V_135 ;
}
static int F_62 ( struct V_5 * V_6 ,
int V_88 , int V_52 )
{
return - V_128 ;
}
static struct V_136 * F_63 ( struct V_5 * V_6 ,
int type , int V_54 , T_3 V_137 )
{
return F_64 ( - V_128 ) ;
}
static int F_65 ( struct V_136 * V_138 ,
T_7 V_139 , T_5 V_140 , T_5 V_141 )
{
return - V_128 ;
}
static int F_66 ( struct V_136 * V_138 , T_6 * V_142 )
{
return - V_128 ;
}
static int F_67 ( struct V_136 * V_138 , struct V_143 * V_144 ,
struct V_145 * V_146 , unsigned long V_147 )
{
return - V_128 ;
}
static void F_68 ( struct V_136 * V_138 )
{
}
void F_69 ( struct V_121 * V_121 )
{
struct V_5 * V_6 = F_29 ( V_121 , struct V_5 , V_121 ) ;
F_70 ( & V_6 -> V_122 ) ;
}
void F_71 ( struct V_5 * V_6 )
{
struct V_110 V_148 = V_149 ;
V_6 -> V_29 -> V_42 ( V_6 , 4 ,
V_150 | V_151 , 0 ) ;
F_24 ( V_6 , false , true ) ;
F_18 ( & V_33 ) ;
F_72 ( & V_6 -> V_35 ) ;
F_20 ( & V_33 ) ;
V_148 . V_152 = V_6 -> V_29 -> V_152 ;
V_148 . V_153 = V_6 -> V_29 -> V_153 ;
V_6 -> V_29 = & V_148 ;
F_73 ( V_6 ) ;
F_28 ( V_6 ) ;
F_74 ( & V_6 -> V_122 ) ;
F_14 ( ! F_75 ( & V_6 -> V_123 ) ) ;
}
