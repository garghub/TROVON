static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = ( V_2 -> V_5 << 4 ) + V_6 ;
F_2 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_4 , V_8 ;
if ( ! V_2 -> V_9 )
return;
V_4 = F_4 ( V_2 -> V_9 -> V_10 ) ;
F_2 ( V_11 | V_2 -> V_5 , V_2 -> V_7 + V_4 ) ;
V_8 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( V_2 -> V_9 -> V_13 )
V_8 |= 1 << V_2 -> V_5 ;
else
V_8 &= ~ ( 1 << V_2 -> V_5 ) ;
F_2 ( V_8 , V_2 -> V_7 + V_12 ) ;
V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
F_2 ( F_5 ( V_2 -> V_7 + V_4 ) | V_15 , V_2 -> V_7 + V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_4 ;
if ( ! V_2 )
return;
V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
F_2 ( F_5 ( V_2 -> V_7 + V_4 ) & ~ V_15 , V_2 -> V_7 + V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_16 ;
T_2 V_17 = F_5 ( V_2 -> V_7 + V_18 ) ;
T_2 V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
if ( ! ( V_17 & F_8 ( V_2 -> V_5 ) ) )
return - V_19 ;
V_16 = F_5 ( V_2 -> V_7 + V_4 ) ;
F_2 ( V_16 , V_2 -> V_7 + V_4 ) ;
if ( ( V_16 & V_20 ) && ( V_2 -> V_9 ) )
F_9 ( V_2 -> V_9 -> V_21 , L_1 ) ;
return 0 ;
}
static T_3 F_10 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
if ( F_7 ( V_2 ) != 0 )
return V_24 ;
F_11 ( & V_2 -> V_9 -> V_25 ) ;
return V_26 ;
}
static T_3 F_12 ( int V_22 , void * V_23 )
{
struct V_27 * V_28 = V_23 ;
struct V_1 * V_2 ;
T_2 V_17 = F_5 ( V_28 -> V_7 + V_18 ) ;
int V_29 , V_30 ;
int V_31 = 0 ;
while ( V_17 ) {
V_29 = F_13 ( V_17 ) ;
V_17 &= ( V_17 - 1 ) ;
V_2 = & V_28 -> V_2 [ V_29 ] ;
V_30 = F_10 ( V_22 , V_2 ) ;
if ( V_30 == V_26 )
V_31 ++ ;
}
if ( V_31 )
return V_26 ;
return V_24 ;
}
static struct V_1 * F_14 ( struct V_32 * V_33 )
{
int V_34 , V_29 ;
struct V_27 * V_28 = F_15 ( V_33 -> V_35 . V_36 ) ;
struct V_1 * V_2 , * V_37 = NULL ;
unsigned long V_38 ;
F_16 ( & V_28 -> V_39 , V_38 ) ;
for ( V_34 = 0 ; V_34 <= ( ( V_28 -> V_40 - 1 ) & 0xf ) >> 2 ; V_34 ++ ) {
for ( V_29 = 0 ; V_29 < V_28 -> V_40 ; V_29 ++ ) {
if ( V_34 != ( V_29 & 0xf ) >> 2 )
continue;
V_2 = & V_28 -> V_2 [ V_29 ] ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_9 = V_33 ;
V_37 = V_2 ;
goto V_41;
}
}
}
V_41:
F_17 ( & V_28 -> V_39 , V_38 ) ;
return V_37 ;
}
static void F_18 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = F_15 ( V_33 -> V_35 . V_36 ) ;
unsigned long V_38 ;
T_2 V_4 ;
if ( ! V_33 -> V_2 )
return;
V_4 = F_4 ( V_33 -> V_10 ) ;
F_2 ( 0 , V_33 -> V_2 -> V_7 + V_4 ) ;
F_16 ( & V_28 -> V_39 , V_38 ) ;
V_33 -> V_2 -> V_9 = NULL ;
V_33 -> V_2 = NULL ;
F_17 ( & V_28 -> V_39 , V_38 ) ;
}
static void F_19 ( struct V_32 * V_35 )
{
struct V_42 * V_43 ;
if ( ! V_35 -> V_44 ) {
F_20 ( V_35 -> V_21 , L_2 ) ;
return;
}
if ( F_21 ( & V_35 -> V_45 ) ) {
F_18 ( V_35 ) ;
F_20 ( V_35 -> V_21 , L_3 ) ;
return;
}
if ( ! V_35 -> V_2 ) {
V_35 -> V_2 = F_14 ( V_35 ) ;
if ( ! V_35 -> V_2 ) {
F_20 ( V_35 -> V_21 , L_4 ) ;
return;
}
}
V_43 = F_22 ( & V_35 -> V_45 ,
struct V_42 , V_46 ) ;
F_23 ( & V_35 -> V_45 , & V_35 -> V_47 ) ;
F_1 ( V_35 -> V_2 , V_43 -> V_48 . V_49 ) ;
F_3 ( V_35 -> V_2 ) ;
V_35 -> V_44 = false ;
}
static T_4 F_24 ( struct V_50 * V_51 )
{
struct V_32 * V_35 = F_25 ( V_51 -> V_35 ) ;
struct V_42 * V_43 = F_26 ( V_51 ) ;
struct V_42 * V_52 ;
unsigned long V_38 ;
T_4 V_53 = - V_54 ;
F_16 ( & V_35 -> V_55 , V_38 ) ;
F_27 (child, &desc->tx_list, node) {
V_53 = F_28 ( & V_52 -> V_48 ) ;
}
F_23 ( & V_43 -> V_56 , & V_35 -> V_45 ) ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
return V_53 ;
}
static struct V_42 *
F_29 ( struct V_32 * V_35 )
{
struct V_42 * V_43 ;
T_1 V_57 ;
V_43 = F_30 ( V_35 -> V_58 , V_59 , & V_57 ) ;
if ( ! V_43 ) {
F_31 ( V_35 -> V_21 , L_5 ) ;
return NULL ;
}
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
F_32 ( & V_43 -> V_56 ) ;
F_33 ( & V_43 -> V_48 , & V_35 -> V_35 ) ;
V_43 -> V_48 . V_60 = F_24 ;
V_43 -> V_48 . V_49 = V_57 ;
return V_43 ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
if ( V_35 -> V_58 )
return 1 ;
V_35 -> V_58 = F_35 ( F_36 ( & V_62 -> V_21 -> V_36 ) ,
V_35 -> V_21 ,
sizeof( struct V_42 ) ,
F_37 ( struct V_42 ) ,
0 ) ;
if ( ! V_35 -> V_58 ) {
F_31 ( V_35 -> V_21 , L_6 ) ;
return - V_63 ;
}
F_18 ( V_35 ) ;
V_35 -> V_44 = true ;
V_35 -> V_64 = 0 ;
return 1 ;
}
static void F_38 ( struct V_32 * V_35 ,
struct V_65 * V_66 )
{
struct V_42 * V_43 , * V_67 ;
F_39 (desc, _desc, list, node) {
F_40 ( & V_43 -> V_46 ) ;
F_41 ( V_35 -> V_58 , V_43 , V_43 -> V_48 . V_49 ) ;
}
}
static void F_42 ( struct V_61 * V_62 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
unsigned long V_38 ;
F_16 ( & V_35 -> V_55 , V_38 ) ;
F_38 ( V_35 , & V_35 -> V_45 ) ;
F_38 ( V_35 , & V_35 -> V_47 ) ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
F_43 ( V_35 -> V_58 ) ;
V_35 -> V_58 = NULL ;
V_35 -> V_44 = true ;
V_35 -> V_64 = 0 ;
F_18 ( V_35 ) ;
return;
}
static struct V_50 *
F_44 ( struct V_61 * V_62 ,
T_1 V_68 , T_1 V_69 ,
T_5 V_70 , unsigned long V_38 )
{
struct V_32 * V_35 ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 ;
T_5 V_74 = 0 ;
if ( ! V_62 )
return NULL ;
if ( ! V_70 )
return NULL ;
V_35 = F_25 ( V_62 ) ;
V_35 -> V_13 = false ;
if ( ! V_35 -> V_75 ) {
V_35 -> V_75 = V_76 ;
V_35 -> V_77 = V_78 | V_79 ;
V_35 -> V_77 |= V_80 ;
}
do {
V_73 = F_29 ( V_35 ) ;
if ( ! V_73 ) {
F_31 ( V_35 -> V_21 , L_7 ) ;
goto V_81;
}
V_74 = F_45 ( T_5 , V_70 , V_82 ) ;
if ( V_69 & 0x7 || V_68 & 0x7 )
V_35 -> V_13 = true ;
V_73 -> V_43 . V_77 = V_35 -> V_77 | ( V_83 & V_74 ) ;
V_73 -> V_43 . V_84 = V_69 ;
V_73 -> V_43 . V_85 = V_68 ;
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
V_70 -= V_74 ;
if ( V_35 -> V_75 == V_87 ) {
V_69 += V_74 ;
} else if ( V_35 -> V_75 == V_88 ) {
V_68 += V_74 ;
} else if ( V_35 -> V_75 == V_76 ) {
V_69 += V_74 ;
V_68 += V_74 ;
}
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
} while ( V_70 );
V_71 -> V_48 . V_38 = V_38 ;
V_71 -> V_48 . V_53 = - V_54 ;
V_73 -> V_43 . V_86 = V_89 ;
V_73 -> V_43 . V_77 |= V_90 ;
V_35 -> V_91 = NULL ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_35 , & V_71 -> V_56 ) ;
return NULL ;
}
static struct V_50 *
F_48 ( struct V_61 * V_62 , struct V_92 * V_93 ,
unsigned int V_94 , enum V_95 V_75 ,
unsigned long V_38 , void * V_96 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 = NULL ;
T_5 V_70 , V_97 ;
struct V_92 * V_98 ;
T_1 V_3 ;
int V_29 ;
if ( ( V_93 == NULL ) || ( V_94 == 0 ) )
return NULL ;
V_35 -> V_13 = false ;
F_49 (sgl, sg, sg_len, i) {
V_3 = F_50 ( V_98 ) ;
V_97 = F_51 ( V_93 ) ;
do {
V_70 = F_45 ( T_5 , V_97 , V_82 ) ;
if ( V_3 & 0x7 )
V_35 -> V_13 = true ;
V_73 = F_29 ( V_35 ) ;
if ( ! V_73 ) {
F_31 ( V_35 -> V_21 , L_7 ) ;
goto V_81;
}
V_73 -> V_43 . V_77 = V_35 -> V_77 | ( V_83 & V_70 ) ;
if ( V_75 == V_87 ) {
V_73 -> V_43 . V_84 = V_3 ;
V_73 -> V_43 . V_85 = V_35 -> V_64 ;
} else {
V_73 -> V_43 . V_84 = V_35 -> V_64 ;
V_73 -> V_43 . V_85 = V_3 ;
}
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
V_3 += V_70 ;
V_97 -= V_70 ;
} while ( V_97 );
}
V_71 -> V_48 . V_53 = - V_54 ;
V_71 -> V_48 . V_38 = V_38 ;
V_73 -> V_43 . V_86 = V_89 ;
V_73 -> V_43 . V_77 |= V_90 ;
V_35 -> V_75 = V_75 ;
V_35 -> V_91 = NULL ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_35 , & V_71 -> V_56 ) ;
return NULL ;
}
static struct V_50 *
F_52 ( struct V_61 * V_62 ,
T_1 V_99 , T_5 V_70 , T_5 V_100 ,
enum V_95 V_101 ,
unsigned long V_38 , void * V_96 )
{
struct V_32 * V_35 ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 ;
T_1 V_69 , V_68 ;
if ( ! V_62 || ! V_70 || ! V_100 )
return NULL ;
if ( V_70 % V_100 != 0 )
return NULL ;
if ( V_100 > V_82 )
return NULL ;
V_35 = F_25 ( V_62 ) ;
switch ( V_101 ) {
case V_87 :
V_69 = V_99 ;
V_68 = V_35 -> V_64 ;
break;
case V_88 :
V_68 = V_99 ;
V_69 = V_35 -> V_64 ;
break;
default:
F_31 ( V_35 -> V_21 , L_8 ) ;
return NULL ;
}
V_35 -> V_75 = V_101 ;
do {
V_73 = F_29 ( V_35 ) ;
if ( ! V_73 ) {
F_31 ( V_35 -> V_21 , L_7 ) ;
goto V_81;
}
V_73 -> V_43 . V_77 = ( V_35 -> V_77 | V_90 |
( V_83 & V_100 ) ) ;
V_73 -> V_43 . V_84 = V_69 ;
V_73 -> V_43 . V_85 = V_68 ;
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
V_70 -= V_100 ;
if ( V_35 -> V_75 == V_87 )
V_69 += V_100 ;
else
V_68 += V_100 ;
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
} while ( V_70 );
V_71 -> V_48 . V_38 = V_38 ;
V_71 -> V_48 . V_53 = - V_54 ;
V_73 -> V_43 . V_86 = V_71 -> V_48 . V_49 ;
V_35 -> V_91 = V_71 ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_35 , & V_71 -> V_56 ) ;
return NULL ;
}
static int F_53 ( struct V_61 * V_62 , enum V_102 V_103 ,
unsigned long V_104 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
struct V_105 * V_106 = ( void * ) V_104 ;
unsigned long V_38 ;
T_2 V_107 = 0 , V_3 = 0 ;
enum V_108 V_109 = V_110 ;
if ( ! V_62 )
return - V_111 ;
switch ( V_103 ) {
case V_112 :
F_6 ( V_35 -> V_2 ) ;
F_18 ( V_35 ) ;
F_16 ( & V_35 -> V_55 , V_38 ) ;
F_38 ( V_35 , & V_35 -> V_45 ) ;
F_38 ( V_35 , & V_35 -> V_47 ) ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
V_35 -> V_44 = true ;
break;
case V_113 :
if ( V_106 -> V_101 == V_88 ) {
V_35 -> V_77 = V_78 | V_114 ;
V_107 = V_106 -> V_115 ;
V_109 = V_106 -> V_116 ;
V_3 = V_106 -> V_117 ;
} else if ( V_106 -> V_101 == V_87 ) {
V_35 -> V_77 = V_79 | V_118 ;
V_107 = V_106 -> V_119 ;
V_109 = V_106 -> V_120 ;
V_3 = V_106 -> V_121 ;
}
if ( V_109 == V_122 )
V_35 -> V_77 |= V_123 ;
else if ( V_109 == V_124 )
V_35 -> V_77 |= V_125 ;
else if ( V_109 == V_126 )
V_35 -> V_77 |= V_127 ;
if ( V_107 == 8 )
V_35 -> V_77 |= V_128 ;
else if ( V_107 == 16 )
V_35 -> V_77 |= V_129 ;
else if ( V_107 == 32 )
V_35 -> V_77 |= V_80 ;
V_35 -> V_75 = V_106 -> V_101 ;
V_35 -> V_64 = V_3 ;
if ( V_106 -> V_130 )
V_35 -> V_10 = V_106 -> V_130 ;
break;
default:
return - V_131 ;
}
return 0 ;
}
static unsigned int F_54 ( struct V_32 * V_35 ,
T_4 V_53 )
{
struct V_42 * V_132 ;
T_2 V_133 , V_134 = 0 ;
bool V_135 = false ;
bool V_136 = V_35 -> V_91 != NULL ;
if ( ! V_35 -> V_2 )
return 0 ;
if ( V_35 -> V_75 == V_88 )
V_133 = F_5 ( V_35 -> V_2 -> V_7 + F_55 ( V_35 -> V_2 -> V_5 ) ) ;
else
V_133 = F_5 ( V_35 -> V_2 -> V_7 + F_56 ( V_35 -> V_2 -> V_5 ) ) ;
F_27 (sw, &chan->chain_running, node) {
T_2 V_137 , V_138 , V_70 ;
if ( V_35 -> V_75 == V_88 )
V_137 = V_132 -> V_43 . V_85 ;
else
V_137 = V_132 -> V_43 . V_84 ;
V_70 = V_132 -> V_43 . V_77 & V_83 ;
V_138 = V_137 + V_70 ;
if ( V_135 ) {
V_134 += V_70 ;
} else if ( V_133 >= V_137 && V_133 <= V_138 ) {
V_134 += V_138 - V_133 ;
V_135 = true ;
}
if ( V_136 || ! ( V_132 -> V_43 . V_77 & V_90 ) )
continue;
if ( V_132 -> V_48 . V_53 == V_53 ) {
return V_134 ;
} else {
V_134 = 0 ;
V_135 = false ;
}
}
return V_134 ;
}
static enum V_139 F_57 ( struct V_61 * V_62 ,
T_4 V_53 ,
struct V_140 * V_141 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
enum V_139 V_30 ;
V_30 = F_58 ( V_62 , V_53 , V_141 ) ;
if ( F_59 ( V_30 != V_142 ) )
F_60 ( V_141 , F_54 ( V_35 , V_53 ) ) ;
return V_30 ;
}
static void F_61 ( struct V_61 * V_62 )
{
struct V_32 * V_35 = F_25 ( V_62 ) ;
unsigned long V_38 ;
F_16 ( & V_35 -> V_55 , V_38 ) ;
F_19 ( V_35 ) ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
}
static void F_62 ( unsigned long V_143 )
{
struct V_32 * V_35 = (struct V_32 * ) V_143 ;
struct V_42 * V_43 , * V_67 ;
F_63 ( V_144 ) ;
unsigned long V_38 ;
if ( V_35 -> V_91 ) {
T_6 V_145 = NULL ;
void * V_146 = NULL ;
F_16 ( & V_35 -> V_55 , V_38 ) ;
V_43 = V_35 -> V_91 ;
V_145 = V_43 -> V_48 . V_147 ;
V_146 = V_43 -> V_48 . V_148 ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
if ( V_145 )
V_145 ( V_146 ) ;
return;
}
F_16 ( & V_35 -> V_55 , V_38 ) ;
F_39 (desc, _desc, &chan->chain_running, node) {
F_64 ( & V_43 -> V_46 , & V_144 ) ;
if ( V_43 -> V_43 . V_77 & V_90 ) {
T_4 V_53 = V_43 -> V_48 . V_53 ;
F_65 ( & V_43 -> V_48 ) ;
F_20 ( V_35 -> V_21 , L_9 , V_53 ) ;
break;
}
}
V_35 -> V_44 = F_21 ( & V_35 -> V_47 ) ;
F_19 ( V_35 ) ;
F_17 ( & V_35 -> V_55 , V_38 ) ;
F_39 (desc, _desc, &chain_cleanup, node) {
struct V_50 * V_149 = & V_43 -> V_48 ;
F_40 ( & V_43 -> V_46 ) ;
if ( V_149 -> V_147 )
V_149 -> V_147 ( V_149 -> V_148 ) ;
F_41 ( V_35 -> V_58 , V_43 , V_149 -> V_49 ) ;
}
}
static int F_66 ( struct V_150 * V_151 )
{
struct V_27 * V_28 = F_67 ( V_151 ) ;
F_68 ( & V_28 -> V_36 ) ;
return 0 ;
}
static int F_69 ( struct V_27 * V_28 , int V_5 , int V_22 )
{
struct V_1 * V_2 = & V_28 -> V_2 [ V_5 ] ;
struct V_32 * V_35 ;
int V_30 ;
V_35 = F_70 ( V_28 -> V_21 , sizeof( * V_35 ) , V_152 ) ;
if ( V_35 == NULL )
return - V_63 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_28 -> V_7 ;
if ( V_22 ) {
V_30 = F_71 ( V_28 -> V_21 , V_22 , F_10 ,
V_153 , L_10 , V_2 ) ;
if ( V_30 ) {
F_31 ( V_28 -> V_21 , L_11 ) ;
return V_30 ;
}
}
F_72 ( & V_35 -> V_55 ) ;
V_35 -> V_21 = V_28 -> V_21 ;
V_35 -> V_35 . V_36 = & V_28 -> V_36 ;
F_73 ( & V_35 -> V_25 , F_62 , ( unsigned long ) V_35 ) ;
F_32 ( & V_35 -> V_45 ) ;
F_32 ( & V_35 -> V_47 ) ;
F_47 ( & V_35 -> V_35 . V_154 , & V_28 -> V_36 . V_155 ) ;
return 0 ;
}
static struct V_61 * F_74 ( struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_27 * V_160 = V_159 -> V_161 ;
struct V_61 * V_35 ;
V_35 = F_75 ( & V_160 -> V_36 ) ;
if ( ! V_35 )
return NULL ;
F_25 ( V_35 ) -> V_10 = V_157 -> args [ 0 ] ;
return V_35 ;
}
static int F_76 ( struct V_150 * V_151 )
{
struct V_27 * V_28 ;
const struct V_162 * V_163 ;
struct V_164 * V_165 = F_77 ( & V_151 -> V_21 ) ;
struct V_166 * V_167 ;
int V_29 , V_30 , V_22 = 0 ;
int V_40 = 0 , V_31 = 0 ;
V_28 = F_70 ( & V_151 -> V_21 , sizeof( * V_28 ) , V_152 ) ;
if ( ! V_28 )
return - V_63 ;
V_28 -> V_21 = & V_151 -> V_21 ;
F_72 ( & V_28 -> V_39 ) ;
V_167 = F_78 ( V_151 , V_168 , 0 ) ;
V_28 -> V_7 = F_79 ( V_28 -> V_21 , V_167 ) ;
if ( F_80 ( V_28 -> V_7 ) )
return F_81 ( V_28 -> V_7 ) ;
V_163 = F_82 ( V_169 , V_28 -> V_21 ) ;
if ( V_163 )
F_83 ( V_28 -> V_21 -> V_170 , L_12 ,
& V_40 ) ;
else if ( V_165 && V_165 -> V_40 )
V_40 = V_165 -> V_40 ;
else
V_40 = 32 ;
V_28 -> V_40 = V_40 ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ ) {
if ( F_84 ( V_151 , V_29 ) > 0 )
V_31 ++ ;
}
V_28 -> V_2 = F_85 ( V_28 -> V_21 , V_40 , sizeof( * V_28 -> V_2 ) ,
V_152 ) ;
if ( V_28 -> V_2 == NULL )
return - V_63 ;
F_32 ( & V_28 -> V_36 . V_155 ) ;
if ( V_31 != V_40 ) {
V_22 = F_84 ( V_151 , 0 ) ;
V_30 = F_71 ( V_28 -> V_21 , V_22 , F_12 ,
V_153 , L_10 , V_28 ) ;
if ( V_30 )
return V_30 ;
}
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ ) {
V_22 = ( V_31 != V_40 ) ? 0 : F_84 ( V_151 , V_29 ) ;
V_30 = F_69 ( V_28 , V_29 , V_22 ) ;
if ( V_30 )
return V_30 ;
}
F_86 ( V_171 , V_28 -> V_36 . V_172 ) ;
F_86 ( V_173 , V_28 -> V_36 . V_172 ) ;
F_86 ( V_174 , V_28 -> V_36 . V_172 ) ;
F_86 ( V_175 , V_28 -> V_36 . V_172 ) ;
V_28 -> V_36 . V_21 = & V_151 -> V_21 ;
V_28 -> V_36 . V_176 = F_34 ;
V_28 -> V_36 . V_177 = F_42 ;
V_28 -> V_36 . V_178 = F_57 ;
V_28 -> V_36 . V_179 = F_44 ;
V_28 -> V_36 . V_180 = F_48 ;
V_28 -> V_36 . V_181 = F_52 ;
V_28 -> V_36 . V_182 = F_61 ;
V_28 -> V_36 . V_183 = F_53 ;
V_28 -> V_36 . V_184 = V_185 ;
if ( V_28 -> V_21 -> V_186 )
F_87 ( V_28 -> V_21 , V_28 -> V_21 -> V_186 ) ;
else
F_87 ( V_28 -> V_21 , F_88 ( 64 ) ) ;
V_30 = F_89 ( & V_28 -> V_36 ) ;
if ( V_30 ) {
F_31 ( V_28 -> V_36 . V_21 , L_13 ) ;
return V_30 ;
}
if ( V_151 -> V_21 . V_170 ) {
V_30 = F_90 ( V_151 -> V_21 . V_170 ,
F_74 , V_28 ) ;
if ( V_30 < 0 ) {
F_31 ( & V_151 -> V_21 , L_14 ) ;
return V_30 ;
}
}
F_91 ( V_151 , V_28 ) ;
F_92 ( V_28 -> V_36 . V_21 , L_15 , V_40 ) ;
return 0 ;
}
bool F_93 ( struct V_61 * V_35 , void * V_187 )
{
struct V_32 * V_188 = F_25 ( V_35 ) ;
if ( V_35 -> V_36 -> V_21 -> V_189 != & V_190 . V_189 )
return false ;
V_188 -> V_10 = * ( unsigned int * ) V_187 ;
return true ;
}
