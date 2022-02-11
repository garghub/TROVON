static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = ( V_2 -> V_5 << 4 ) + V_6 ;
F_2 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_4 ;
if ( ! V_2 -> V_8 )
return;
V_4 = V_2 -> V_8 -> V_9 ;
V_4 = ( ( ( V_4 ) < 64 ) ? 0x0100 : 0x1100 ) + ( ( ( V_4 ) & 0x3f ) << 2 ) ;
F_2 ( V_10 | V_2 -> V_5 , V_2 -> V_7 + V_4 ) ;
V_4 = ( V_2 -> V_5 << 2 ) + V_11 ;
F_2 ( F_4 ( V_2 -> V_7 + V_4 ) | V_12 ,
V_2 -> V_7 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_4 ;
if ( V_2 ) {
V_4 = ( V_2 -> V_5 << 2 ) + V_11 ;
F_2 ( F_4 ( V_2 -> V_7 + V_4 ) & ~ V_12 ,
V_2 -> V_7 + V_4 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
T_2 V_13 ;
T_2 V_14 = F_4 ( V_2 -> V_7 + V_15 ) ;
T_2 V_4 = ( V_2 -> V_5 << 2 ) + V_11 ;
if ( V_14 & F_7 ( V_2 -> V_5 ) ) {
V_13 = F_4 ( V_2 -> V_7 + V_4 ) ;
F_2 ( V_13 , V_2 -> V_7 + V_4 ) ;
if ( ( V_13 & V_16 ) && ( V_2 -> V_8 ) )
F_8 ( V_2 -> V_8 -> V_17 , L_1 ) ;
return 0 ;
}
return - V_18 ;
}
static T_3 F_9 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
if ( F_6 ( V_2 ) == 0 ) {
F_10 ( & V_2 -> V_8 -> V_21 ) ;
return V_22 ;
} else
return V_23 ;
}
static T_3 F_11 ( int V_19 , void * V_20 )
{
struct V_24 * V_25 = V_20 ;
struct V_1 * V_2 ;
T_2 V_14 = F_4 ( V_25 -> V_7 + V_15 ) ;
int V_26 , V_27 ;
int V_28 = 0 ;
while ( V_14 ) {
V_26 = F_12 ( V_14 ) ;
V_14 &= ( V_14 - 1 ) ;
V_2 = & V_25 -> V_2 [ V_26 ] ;
V_27 = F_9 ( V_19 , V_2 ) ;
if ( V_27 == V_22 )
V_28 ++ ;
}
if ( V_28 )
return V_22 ;
else
return V_23 ;
}
static struct V_1 * F_13 ( struct V_29 * V_30 )
{
int V_31 , V_26 ;
struct V_24 * V_25 = F_14 ( V_30 -> V_32 . V_33 ) ;
struct V_1 * V_2 ;
for ( V_31 = 0 ; V_31 <= ( ( ( V_25 -> V_34 - 1 ) & 0xf ) >> 2 ) ; V_31 ++ ) {
for ( V_26 = 0 ; V_26 < V_25 -> V_34 ; V_26 ++ ) {
if ( V_31 != ( ( V_26 & 0xf ) >> 2 ) )
continue;
V_2 = & V_25 -> V_2 [ V_26 ] ;
if ( ! V_2 -> V_8 ) {
V_2 -> V_8 = V_30 ;
return V_2 ;
}
}
}
return NULL ;
}
static void F_15 ( struct V_29 * V_32 ,
struct V_35 * V_36 )
{
struct V_35 * V_37 =
F_16 ( V_32 -> V_38 . V_39 ) ;
if ( F_17 ( & V_32 -> V_38 ) )
goto V_40;
V_37 -> V_36 . V_41 = V_36 -> V_42 . V_43 ;
V_37 -> V_36 . V_44 &= ~ V_45 ;
V_40:
F_18 ( & V_36 -> V_46 , & V_32 -> V_38 ) ;
}
static void F_19 ( struct V_29 * V_32 )
{
struct V_35 * V_36 ;
if ( ! V_32 -> V_47 ) {
F_20 ( V_32 -> V_17 , L_2 ) ;
return;
}
if ( F_17 ( & V_32 -> V_38 ) ) {
if ( V_32 -> V_2 ) {
V_32 -> V_2 -> V_8 = NULL ;
V_32 -> V_2 = NULL ;
}
F_20 ( V_32 -> V_17 , L_3 ) ;
return;
}
if ( ! V_32 -> V_2 ) {
V_32 -> V_2 = F_13 ( V_32 ) ;
if ( ! V_32 -> V_2 ) {
F_20 ( V_32 -> V_17 , L_4 ) ;
return;
}
}
V_36 = F_21 ( & V_32 -> V_38 ,
struct V_35 , V_48 ) ;
F_18 ( & V_32 -> V_38 , & V_32 -> V_49 ) ;
F_1 ( V_32 -> V_2 , V_36 -> V_42 . V_43 ) ;
F_3 ( V_32 -> V_2 ) ;
V_32 -> V_47 = false ;
}
static T_4 F_22 ( struct V_50 * V_51 )
{
struct V_29 * V_32 = F_23 ( V_51 -> V_32 ) ;
struct V_35 * V_36 = F_24 ( V_51 ) ;
struct V_35 * V_52 ;
unsigned long V_53 ;
T_4 V_54 = - V_55 ;
F_25 ( & V_32 -> V_56 , V_53 ) ;
F_26 (child, &desc->tx_list, node) {
V_54 = F_27 ( & V_52 -> V_42 ) ;
}
F_15 ( V_32 , V_36 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
return V_54 ;
}
struct V_35 * F_29 ( struct V_29 * V_32 )
{
struct V_35 * V_36 ;
T_1 V_57 ;
V_36 = F_30 ( V_32 -> V_58 , V_59 , & V_57 ) ;
if ( ! V_36 ) {
F_31 ( V_32 -> V_17 , L_5 ) ;
return NULL ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
F_32 ( & V_36 -> V_46 ) ;
F_33 ( & V_36 -> V_42 , & V_32 -> V_32 ) ;
V_36 -> V_42 . V_60 = F_22 ;
V_36 -> V_42 . V_43 = V_57 ;
return V_36 ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
if ( V_32 -> V_58 )
return 1 ;
V_32 -> V_58 =
F_35 ( F_36 ( & V_62 -> V_17 -> V_33 ) , V_32 -> V_17 ,
sizeof( struct V_35 ) ,
F_37 ( struct V_35 ) , 0 ) ;
if ( ! V_32 -> V_58 ) {
F_31 ( V_32 -> V_17 , L_6 ) ;
return - V_63 ;
}
if ( V_32 -> V_2 ) {
V_32 -> V_2 -> V_8 = NULL ;
V_32 -> V_2 = NULL ;
}
V_32 -> V_47 = true ;
V_32 -> V_64 = 0 ;
return 1 ;
}
static void F_38 ( struct V_29 * V_32 ,
struct V_65 * V_66 )
{
struct V_35 * V_36 , * V_67 ;
F_39 (desc, _desc, list, node) {
F_40 ( & V_36 -> V_48 ) ;
F_41 ( V_32 -> V_58 , V_36 , V_36 -> V_42 . V_43 ) ;
}
}
static void F_42 ( struct V_61 * V_62 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
unsigned long V_53 ;
F_25 ( & V_32 -> V_56 , V_53 ) ;
F_38 ( V_32 , & V_32 -> V_38 ) ;
F_38 ( V_32 , & V_32 -> V_49 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
F_43 ( V_32 -> V_58 ) ;
V_32 -> V_58 = NULL ;
V_32 -> V_47 = true ;
V_32 -> V_64 = 0 ;
if ( V_32 -> V_2 ) {
V_32 -> V_2 -> V_8 = NULL ;
V_32 -> V_2 = NULL ;
}
return;
}
static struct V_50 *
F_44 ( struct V_61 * V_62 ,
T_1 V_68 , T_1 V_69 ,
T_5 V_70 , unsigned long V_53 )
{
struct V_29 * V_32 ;
struct V_35 * V_71 = NULL , * V_39 = NULL , * V_72 ;
T_5 V_73 = 0 ;
if ( ! V_62 )
return NULL ;
if ( ! V_70 )
return NULL ;
V_32 = F_23 ( V_62 ) ;
if ( ! V_32 -> V_74 ) {
V_32 -> V_74 = V_75 ;
V_32 -> V_44 = V_76 | V_77 ;
V_32 -> V_44 |= V_78 ;
}
do {
V_72 = F_29 ( V_32 ) ;
if ( ! V_72 ) {
F_31 ( V_32 -> V_17 , L_7 ) ;
goto V_79;
}
V_73 = F_45 ( T_5 , V_70 , V_80 ) ;
V_72 -> V_36 . V_44 = V_32 -> V_44 | ( V_81 & V_73 ) ;
V_72 -> V_36 . V_82 = V_69 ;
V_72 -> V_36 . V_83 = V_68 ;
if ( ! V_71 )
V_71 = V_72 ;
else
V_39 -> V_36 . V_41 = V_72 -> V_42 . V_43 ;
V_72 -> V_42 . V_54 = 0 ;
F_46 ( & V_72 -> V_42 ) ;
V_39 = V_72 ;
V_70 -= V_73 ;
if ( V_32 -> V_74 == V_84 ) {
V_69 += V_73 ;
} else if ( V_32 -> V_74 == V_85 ) {
V_68 += V_73 ;
} else if ( V_32 -> V_74 == V_75 ) {
V_69 += V_73 ;
V_68 += V_73 ;
}
F_47 ( & V_72 -> V_48 , & V_71 -> V_46 ) ;
} while ( V_70 );
V_71 -> V_42 . V_53 = V_53 ;
V_71 -> V_42 . V_54 = - V_55 ;
V_72 -> V_36 . V_41 = V_86 ;
V_72 -> V_36 . V_44 |= V_45 ;
return & V_71 -> V_42 ;
V_79:
if ( V_71 )
F_38 ( V_32 , & V_71 -> V_46 ) ;
return NULL ;
}
static struct V_50 *
F_48 ( struct V_61 * V_62 , struct V_87 * V_88 ,
unsigned int V_89 , enum V_90 V_74 ,
unsigned long V_53 , void * V_91 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
struct V_35 * V_71 = NULL , * V_39 = NULL , * V_72 = NULL ;
T_5 V_70 , V_92 ;
struct V_87 * V_93 ;
T_1 V_3 ;
int V_26 ;
if ( ( V_88 == NULL ) || ( V_89 == 0 ) )
return NULL ;
F_49 (sgl, sg, sg_len, i) {
V_3 = F_50 ( V_93 ) ;
V_92 = F_51 ( V_88 ) ;
do {
V_70 = F_45 ( T_5 , V_92 , V_80 ) ;
V_72 = F_29 ( V_32 ) ;
if ( ! V_72 ) {
F_31 ( V_32 -> V_17 , L_7 ) ;
goto V_79;
}
V_72 -> V_36 . V_44 = V_32 -> V_44 | ( V_81 & V_70 ) ;
if ( V_74 == V_84 ) {
V_72 -> V_36 . V_82 = V_3 ;
V_72 -> V_36 . V_83 = V_32 -> V_64 ;
} else {
V_72 -> V_36 . V_82 = V_32 -> V_64 ;
V_72 -> V_36 . V_83 = V_3 ;
}
if ( ! V_71 )
V_71 = V_72 ;
else
V_39 -> V_36 . V_41 = V_72 -> V_42 . V_43 ;
V_72 -> V_42 . V_54 = 0 ;
F_46 ( & V_72 -> V_42 ) ;
V_39 = V_72 ;
F_47 ( & V_72 -> V_48 , & V_71 -> V_46 ) ;
V_3 += V_70 ;
V_92 -= V_70 ;
} while ( V_92 );
}
V_71 -> V_42 . V_54 = - V_55 ;
V_71 -> V_42 . V_53 = V_53 ;
V_72 -> V_36 . V_41 = V_86 ;
V_72 -> V_36 . V_44 |= V_45 ;
return & V_71 -> V_42 ;
V_79:
if ( V_71 )
F_38 ( V_32 , & V_71 -> V_46 ) ;
return NULL ;
}
static int F_52 ( struct V_61 * V_62 , enum V_94 V_95 ,
unsigned long V_96 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
struct V_97 * V_98 = ( void * ) V_96 ;
unsigned long V_53 ;
int V_27 = 0 ;
T_2 V_99 = 0 , V_3 = 0 ;
enum V_100 V_101 = V_102 ;
if ( ! V_62 )
return - V_103 ;
switch ( V_95 ) {
case V_104 :
F_5 ( V_32 -> V_2 ) ;
if ( V_32 -> V_2 ) {
V_32 -> V_2 -> V_8 = NULL ;
V_32 -> V_2 = NULL ;
}
F_25 ( & V_32 -> V_56 , V_53 ) ;
F_38 ( V_32 , & V_32 -> V_38 ) ;
F_38 ( V_32 , & V_32 -> V_49 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
V_32 -> V_47 = true ;
break;
case V_105 :
if ( V_98 -> V_106 == V_85 ) {
V_32 -> V_44 = V_76 | V_107 ;
V_99 = V_98 -> V_108 ;
V_101 = V_98 -> V_109 ;
V_3 = V_98 -> V_110 ;
} else if ( V_98 -> V_106 == V_84 ) {
V_32 -> V_44 = V_77 | V_111 ;
V_99 = V_98 -> V_112 ;
V_101 = V_98 -> V_113 ;
V_3 = V_98 -> V_114 ;
}
if ( V_101 == V_115 )
V_32 -> V_44 |= V_116 ;
else if ( V_101 == V_117 )
V_32 -> V_44 |= V_118 ;
else if ( V_101 == V_119 )
V_32 -> V_44 |= V_120 ;
if ( V_99 == 8 )
V_32 -> V_44 |= V_121 ;
else if ( V_99 == 16 )
V_32 -> V_44 |= V_122 ;
else if ( V_99 == 32 )
V_32 -> V_44 |= V_78 ;
if ( V_98 ) {
V_32 -> V_74 = V_98 -> V_106 ;
V_32 -> V_9 = V_98 -> V_123 ;
}
V_32 -> V_64 = V_3 ;
break;
default:
return - V_124 ;
}
return V_27 ;
}
static enum V_125 F_53 ( struct V_61 * V_62 ,
T_4 V_54 , struct V_126 * V_127 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
enum V_125 V_27 ;
unsigned long V_53 ;
F_25 ( & V_32 -> V_56 , V_53 ) ;
V_27 = F_54 ( V_62 , V_54 , V_127 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
return V_27 ;
}
static void F_55 ( struct V_61 * V_62 )
{
struct V_29 * V_32 = F_23 ( V_62 ) ;
unsigned long V_53 ;
F_25 ( & V_32 -> V_56 , V_53 ) ;
F_19 ( V_32 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
}
static void F_56 ( unsigned long V_128 )
{
struct V_29 * V_32 = (struct V_29 * ) V_128 ;
struct V_35 * V_36 , * V_67 ;
F_57 ( V_129 ) ;
unsigned long V_53 ;
F_25 ( & V_32 -> V_56 , V_53 ) ;
if ( ! F_17 ( & V_32 -> V_49 ) ) {
T_4 V_54 ;
V_36 = F_16 ( V_32 -> V_49 . V_39 ) ;
V_54 = V_36 -> V_42 . V_54 ;
F_58 ( & V_36 -> V_42 ) ;
F_20 ( V_32 -> V_17 , L_8 , V_54 ) ;
}
F_18 ( & V_32 -> V_49 , & V_129 ) ;
V_32 -> V_47 = true ;
F_19 ( V_32 ) ;
F_28 ( & V_32 -> V_56 , V_53 ) ;
F_39 (desc, _desc, &chain_cleanup, node) {
struct V_50 * V_130 = & V_36 -> V_42 ;
F_40 ( & V_36 -> V_48 ) ;
if ( V_130 -> V_131 )
V_130 -> V_131 ( V_130 -> V_132 ) ;
F_41 ( V_32 -> V_58 , V_36 , V_130 -> V_43 ) ;
}
}
static int F_59 ( struct V_133 * V_134 )
{
struct V_24 * V_25 = F_60 ( V_134 ) ;
F_61 ( & V_25 -> V_33 ) ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 ,
int V_5 , int V_19 )
{
struct V_1 * V_2 = & V_25 -> V_2 [ V_5 ] ;
struct V_29 * V_32 ;
int V_27 ;
V_32 = F_63 ( V_25 -> V_17 ,
sizeof( struct V_29 ) , V_135 ) ;
if ( V_32 == NULL )
return - V_63 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_25 -> V_7 ;
if ( V_19 ) {
V_27 = F_64 ( V_25 -> V_17 , V_19 ,
F_9 , V_136 , L_9 , V_2 ) ;
if ( V_27 ) {
F_31 ( V_25 -> V_17 , L_10 ) ;
return V_27 ;
}
}
F_65 ( & V_32 -> V_56 ) ;
V_32 -> V_17 = V_25 -> V_17 ;
V_32 -> V_32 . V_33 = & V_25 -> V_33 ;
F_66 ( & V_32 -> V_21 , F_56 , ( unsigned long ) V_32 ) ;
F_32 ( & V_32 -> V_38 ) ;
F_32 ( & V_32 -> V_49 ) ;
F_47 ( & V_32 -> V_32 . V_137 ,
& V_25 -> V_33 . V_138 ) ;
return 0 ;
}
static int F_67 ( struct V_133 * V_134 )
{
struct V_24 * V_25 ;
const struct V_139 * V_140 ;
struct V_141 * V_142 = F_68 ( & V_134 -> V_17 ) ;
struct V_143 * V_144 ;
int V_26 , V_27 , V_19 = 0 ;
int V_34 = 0 , V_28 = 0 ;
V_25 = F_63 ( & V_134 -> V_17 , sizeof( * V_25 ) , V_135 ) ;
if ( ! V_25 )
return - V_63 ;
V_25 -> V_17 = & V_134 -> V_17 ;
V_144 = F_69 ( V_134 , V_145 , 0 ) ;
if ( ! V_144 )
return - V_103 ;
V_25 -> V_7 = F_70 ( V_25 -> V_17 , V_144 ) ;
if ( ! V_25 -> V_7 )
return - V_146 ;
V_140 = F_71 ( V_147 , V_25 -> V_17 ) ;
if ( V_140 )
F_72 ( V_25 -> V_17 -> V_148 ,
L_11 , & V_34 ) ;
else if ( V_142 && V_142 -> V_34 )
V_34 = V_142 -> V_34 ;
else
V_34 = 32 ;
V_25 -> V_34 = V_34 ;
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
if ( F_73 ( V_134 , V_26 ) > 0 )
V_28 ++ ;
}
V_25 -> V_2 = F_63 ( V_25 -> V_17 ,
V_34 * sizeof( struct V_29 ) , V_135 ) ;
if ( V_25 -> V_2 == NULL )
return - V_63 ;
F_32 ( & V_25 -> V_33 . V_138 ) ;
if ( V_28 != V_34 ) {
V_19 = F_73 ( V_134 , 0 ) ;
V_27 = F_64 ( V_25 -> V_17 , V_19 ,
F_11 , V_136 , L_9 , V_25 ) ;
if ( V_27 )
return V_27 ;
}
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
V_19 = ( V_28 != V_34 ) ? 0 : F_73 ( V_134 , V_26 ) ;
V_27 = F_62 ( V_25 , V_26 , V_19 ) ;
if ( V_27 )
return V_27 ;
}
F_74 ( V_149 , V_25 -> V_33 . V_150 ) ;
F_74 ( V_151 , V_25 -> V_33 . V_150 ) ;
F_74 ( V_149 , V_25 -> V_33 . V_150 ) ;
V_25 -> V_33 . V_17 = & V_134 -> V_17 ;
V_25 -> V_33 . V_152 = F_34 ;
V_25 -> V_33 . V_153 = F_42 ;
V_25 -> V_33 . V_154 = F_53 ;
V_25 -> V_33 . V_155 = F_44 ;
V_25 -> V_33 . V_156 = F_48 ;
V_25 -> V_33 . V_157 = F_55 ;
V_25 -> V_33 . V_158 = F_52 ;
V_25 -> V_33 . V_159 = V_160 ;
if ( V_25 -> V_17 -> V_161 )
F_75 ( V_25 -> V_17 , V_25 -> V_17 -> V_161 ) ;
else
F_75 ( V_25 -> V_17 , F_76 ( 64 ) ) ;
V_27 = F_77 ( & V_25 -> V_33 ) ;
if ( V_27 ) {
F_31 ( V_25 -> V_33 . V_17 , L_12 ) ;
return V_27 ;
}
F_78 ( V_25 -> V_33 . V_17 , L_13 ) ;
return 0 ;
}
