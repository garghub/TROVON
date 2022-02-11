static const struct V_1 *
F_1 ( struct V_2 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_5 == V_6 &&
V_2 -> V_7 == V_4 [ V_3 ] . V_8 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static struct V_2 * F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_2 = NULL ;
int V_14 = V_12 -> V_15 [ 0 ] ;
int V_16 = V_12 -> V_15 [ 1 ] ;
F_5 (pci_dev) {
if ( V_14 || V_16 ) {
if ( V_14 != V_2 -> V_14 -> V_17 ||
V_16 != F_6 ( V_2 -> V_18 ) )
continue;
}
if ( V_2 -> V_19 != V_20 )
continue;
if ( V_13 -> V_21 == V_22 ) {
const struct V_1 * V_23 ;
V_23 = F_1 ( V_2 ) ;
if ( V_23 == NULL )
continue;
V_10 -> V_24 = V_23 ;
} else {
if ( V_2 -> V_7 != V_13 -> V_8 )
continue;
}
return V_2 ;
}
F_7 ( V_10 -> V_25 ,
L_1 ,
V_14 , V_16 ) ;
return NULL ;
}
static int
F_8 ( struct V_9 * V_10 ,
unsigned long V_26 , unsigned long V_27 )
{
if ( ! V_26 || ! F_9 ( V_26 , V_27 , V_28 ) ) {
F_7 ( V_10 -> V_25 , L_2 ,
V_26 , V_27 ) ;
return - V_29 ;
}
return 0 ;
}
static int
F_10 ( struct V_9 * V_10 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_34 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
if ( V_36 -> V_38 ) {
V_34 [ 1 ] = F_11 ( V_36 -> V_39 ) & V_36 -> V_40 ;
} else {
V_34 [ 0 ] = 0 ;
}
return V_33 -> V_41 ;
}
static void F_12 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
V_36 -> V_42 = 0 ;
V_36 -> V_43 = 0 ;
if ( V_36 -> V_38 )
F_13 ( 0 , V_36 -> V_39 ) ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
unsigned int V_41 ;
unsigned V_44 ;
struct V_35 * V_36 = V_31 -> V_37 ;
struct V_45 * V_46 = & V_31 -> V_47 -> V_46 ;
int V_48 = 0 ;
if ( ! V_36 -> V_49 && V_36 -> V_50 == 0 ) {
V_31 -> V_47 -> V_51 |= V_52 ;
V_36 -> V_42 = 0 ;
V_48 = 1 ;
} else {
V_44 = 0 ;
if ( V_46 -> V_53 ) {
for ( V_41 = 0 ; V_41 < V_46 -> V_54 ; V_41 ++ )
V_44 |= ( 1U << F_15 ( V_46 -> V_53 [ V_41 ] ) ) ;
}
V_44 &= V_36 -> V_40 ;
V_36 -> V_43 = V_44 ;
if ( V_36 -> V_38 )
F_13 ( V_44 , V_36 -> V_39 ) ;
}
return V_48 ;
}
static int
F_16 ( struct V_9 * V_10 , struct V_30 * V_31 ,
unsigned int V_55 )
{
struct V_35 * V_36 ;
unsigned long V_56 ;
int V_57 = 0 ;
if ( V_55 != 0 )
return - V_58 ;
V_36 = V_31 -> V_37 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
V_31 -> V_47 -> V_60 = NULL ;
if ( V_36 -> V_42 )
V_57 = F_14 ( V_10 , V_31 ) ;
F_18 ( & V_36 -> V_59 , V_56 ) ;
if ( V_57 )
F_19 ( V_10 , V_31 ) ;
return 1 ;
}
static int F_20 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
unsigned V_61 ;
unsigned V_62 ;
unsigned V_63 ;
unsigned int V_64 ;
unsigned long V_56 ;
V_61 = 0 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
V_64 = V_31 -> V_47 -> V_51 ;
if ( V_36 -> V_38 ) {
V_63 = V_36 -> V_43 ;
while ( ( V_62 = ( F_11 ( V_36 -> V_39 ) & V_36 -> V_40
& ~ V_61 ) ) != 0 ) {
V_61 |= V_62 ;
V_63 &= ~ V_61 ;
F_13 ( V_63 , V_36 -> V_39 ) ;
}
} else {
V_61 = V_36 -> V_43 ;
}
if ( V_61 ) {
V_63 = V_36 -> V_43 ;
if ( V_36 -> V_38 )
F_13 ( V_63 , V_36 -> V_39 ) ;
if ( V_36 -> V_42 ) {
if ( V_61 & V_36 -> V_43 ) {
short V_65 ;
unsigned int V_41 , V_66 , V_67 ;
V_65 = 0 ;
V_67 = V_31 -> V_47 -> V_46 . V_54 ;
for ( V_41 = 0 ; V_41 < V_67 ; V_41 ++ ) {
V_66 = F_15 ( V_31 -> V_47 -> V_46 . V_53 [ V_41 ] ) ;
if ( V_61 & ( 1U << V_66 ) )
V_65 |= ( 1U << V_41 ) ;
}
if ( F_21 ( V_31 -> V_47 , V_65 ) ) {
V_31 -> V_47 -> V_51 |= ( V_68 |
V_69 ) ;
} else {
F_12 ( V_10 , V_31 ) ;
V_31 -> V_47 -> V_51 |= V_70
| V_71 ;
F_22 ( V_10 , L_3 ) ;
}
if ( ! V_36 -> V_49 ) {
if ( V_36 -> V_50 > 0 ) {
V_36 -> V_50 -- ;
if ( V_36 -> V_50 == 0 ) {
V_31 -> V_47 -> V_51 |=
V_52 ;
F_12 ( V_10 ,
V_31 ) ;
}
}
}
}
}
}
F_18 ( & V_36 -> V_59 , V_56 ) ;
if ( V_64 != V_31 -> V_47 -> V_51 )
F_19 ( V_10 , V_31 ) ;
return ( V_61 != 0 ) ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
unsigned long V_56 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
if ( V_36 -> V_42 )
F_12 ( V_10 , V_31 ) ;
F_18 ( & V_36 -> V_59 , V_56 ) ;
return 0 ;
}
static int
F_24 ( struct V_9 * V_10 ,
struct V_30 * V_31 , struct V_45 * V_46 )
{
int V_72 = 0 ;
unsigned int V_73 ;
V_73 = V_46 -> V_74 ;
V_46 -> V_74 &= ( V_75 | V_76 ) ;
if ( ! V_46 -> V_74 || V_73 != V_46 -> V_74 )
V_72 ++ ;
V_73 = V_46 -> V_77 ;
V_46 -> V_77 &= V_78 ;
if ( ! V_46 -> V_77 || V_73 != V_46 -> V_77 )
V_72 ++ ;
V_73 = V_46 -> V_79 ;
V_46 -> V_79 &= V_75 ;
if ( ! V_46 -> V_79 || V_73 != V_46 -> V_79 )
V_72 ++ ;
V_73 = V_46 -> V_80 ;
V_46 -> V_80 &= V_81 ;
if ( ! V_46 -> V_80 || V_73 != V_46 -> V_80 )
V_72 ++ ;
V_73 = V_46 -> V_82 ;
V_46 -> V_82 &= ( V_81 | V_83 ) ;
if ( ! V_46 -> V_82 || V_73 != V_46 -> V_82 )
V_72 ++ ;
if ( V_72 )
return 1 ;
if ( ( V_46 -> V_74 & ( V_46 -> V_74 - 1 ) ) != 0 )
V_72 ++ ;
if ( ( V_46 -> V_77 & ( V_46 -> V_77 - 1 ) ) != 0 )
V_72 ++ ;
if ( ( V_46 -> V_79 & ( V_46 -> V_79 - 1 ) ) != 0 )
V_72 ++ ;
if ( ( V_46 -> V_80 & ( V_46 -> V_80 - 1 ) ) != 0 )
V_72 ++ ;
if ( ( V_46 -> V_82 & ( V_46 -> V_82 - 1 ) ) != 0 )
V_72 ++ ;
if ( V_72 )
return 2 ;
if ( V_46 -> V_84 != 0 ) {
V_46 -> V_84 = 0 ;
V_72 ++ ;
}
if ( V_46 -> V_85 != 0 ) {
V_46 -> V_85 = 0 ;
V_72 ++ ;
}
if ( V_46 -> V_86 != 0 ) {
V_46 -> V_86 = 0 ;
V_72 ++ ;
}
if ( V_46 -> V_87 != V_46 -> V_54 ) {
V_46 -> V_87 = V_46 -> V_54 ;
V_72 ++ ;
}
switch ( V_46 -> V_82 ) {
case V_81 :
break;
case V_83 :
if ( V_46 -> V_88 != 0 ) {
V_46 -> V_88 = 0 ;
V_72 ++ ;
}
break;
default:
break;
}
if ( V_72 )
return 3 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_45 * V_46 = & V_31 -> V_47 -> V_46 ;
struct V_35 * V_36 = V_31 -> V_37 ;
unsigned long V_56 ;
int V_57 = 0 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
V_36 -> V_42 = 1 ;
switch ( V_46 -> V_82 ) {
case V_81 :
V_36 -> V_49 = 0 ;
V_36 -> V_50 = V_46 -> V_88 ;
break;
default:
V_36 -> V_49 = 1 ;
V_36 -> V_50 = 0 ;
break;
}
switch ( V_46 -> V_74 ) {
case V_76 :
V_31 -> V_47 -> V_60 = F_16 ;
break;
default:
V_57 = F_14 ( V_10 , V_31 ) ;
break;
}
F_18 ( & V_36 -> V_59 , V_56 ) ;
if ( V_57 )
F_19 ( V_10 , V_31 ) ;
return 0 ;
}
static int
F_26 ( struct V_9 * V_10 , struct V_30 * V_31 ,
unsigned long V_39 , unsigned V_40 ,
int V_38 )
{
struct V_35 * V_36 ;
V_36 = F_27 ( sizeof( * V_36 ) , V_89 ) ;
if ( ! V_36 ) {
F_7 ( V_10 -> V_25 , L_4 ) ;
return - V_90 ;
}
V_36 -> V_39 = V_39 ;
V_36 -> V_38 = V_38 ;
V_36 -> V_40 = V_40 ;
F_28 ( & V_36 -> V_59 ) ;
if ( V_38 )
F_13 ( 0 , V_36 -> V_39 ) ;
V_31 -> V_37 = V_36 ;
V_31 -> type = V_91 ;
V_31 -> V_92 = V_93 | V_94 ;
if ( V_38 ) {
V_31 -> V_95 = V_96 ;
V_31 -> V_97 = V_96 ;
} else {
V_31 -> V_95 = 1 ;
V_31 -> V_97 = 1 ;
}
V_31 -> V_98 = & V_99 ;
V_31 -> V_100 = 1 ;
V_31 -> V_101 = F_10 ;
V_31 -> V_102 = F_24 ;
V_31 -> V_103 = F_25 ;
V_31 -> V_104 = F_23 ;
return 0 ;
}
static void
F_29 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
F_30 ( V_36 ) ;
}
static T_1 F_31 ( int V_105 , void * V_106 )
{
struct V_9 * V_10 = V_106 ;
struct V_107 * V_108 = V_10 -> V_37 ;
int V_109 ;
if ( ! V_10 -> V_110 )
return V_111 ;
if ( V_108 -> V_112 >= 0 ) {
V_109 = F_20 ( V_10 ,
V_10 -> V_113 +
V_108 -> V_112 ) ;
} else {
V_109 = 0 ;
}
return F_32 ( V_109 ) ;
}
static int
F_33 ( struct V_9 * V_10 , struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_34 )
{
struct V_114 * V_36 = V_31 -> V_37 ;
int V_115 = F_15 ( V_33 -> V_116 ) ;
unsigned long V_56 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
V_34 [ 0 ] = F_34 ( V_36 -> V_39 , 0 , V_115 ) ;
F_18 ( & V_36 -> V_59 , V_56 ) ;
return 1 ;
}
static int
F_35 ( struct V_9 * V_10 , struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_34 )
{
struct V_114 * V_36 = V_31 -> V_37 ;
int V_115 = F_15 ( V_33 -> V_116 ) ;
unsigned long V_56 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
F_36 ( V_36 -> V_39 , 0 , V_115 , V_34 [ 0 ] ) ;
F_18 ( & V_36 -> V_59 , V_56 ) ;
return 1 ;
}
static int
F_37 ( struct V_114 * V_36 ,
unsigned int V_117 , unsigned int V_118 )
{
unsigned char V_119 ;
if ( ! V_36 -> V_120 )
return - 1 ;
if ( V_117 > 2 )
return - 1 ;
if ( V_118 > 7 )
return - 1 ;
V_36 -> V_118 [ V_117 ] = V_118 ;
V_119 = F_38 ( V_36 -> V_121 , V_117 , V_118 ) ;
F_13 ( V_119 , V_36 -> V_122 ) ;
return 0 ;
}
static int
F_39 ( struct V_114 * V_36 ,
unsigned int V_117 )
{
if ( ! V_36 -> V_120 )
return - 1 ;
if ( V_117 > 2 )
return - 1 ;
return V_36 -> V_118 [ V_117 ] ;
}
static int
F_40 ( struct V_114 * V_36 ,
unsigned int V_117 , unsigned int V_123 )
{
unsigned char V_119 ;
if ( ! V_36 -> V_120 )
return - 1 ;
if ( V_117 > 2 )
return - 1 ;
if ( V_123 > 7 )
return - 1 ;
V_36 -> V_123 [ V_117 ] = V_123 ;
V_119 = F_41 ( V_36 -> V_121 , V_117 , V_123 ) ;
F_13 ( V_119 , V_36 -> V_124 ) ;
return 0 ;
}
static int
F_42 ( struct V_114 * V_36 ,
unsigned int V_117 , unsigned int * V_125 )
{
unsigned V_123 ;
if ( ! V_36 -> V_120 )
return - 1 ;
if ( V_117 > 2 )
return - 1 ;
V_123 = V_36 -> V_123 [ V_117 ] ;
* V_125 = V_126 [ V_123 ] ;
return V_123 ;
}
static int
F_43 ( struct V_9 * V_10 , struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_34 )
{
struct V_114 * V_36 = V_31 -> V_37 ;
int V_127 = 0 ;
int V_115 = F_15 ( V_33 -> V_116 ) ;
unsigned long V_56 ;
F_17 ( & V_36 -> V_59 , V_56 ) ;
switch ( V_34 [ 0 ] ) {
case V_128 :
V_127 = F_44 ( V_36 -> V_39 , 0 , V_115 , V_34 [ 1 ] ) ;
if ( V_127 < 0 )
V_127 = - V_58 ;
break;
case V_129 :
V_34 [ 1 ] = F_45 ( V_36 -> V_39 , 0 , V_115 ) ;
break;
case V_130 :
V_127 = F_37 ( V_36 , V_115 , V_34 [ 2 ] ) ;
if ( V_127 < 0 )
V_127 = - V_58 ;
break;
case V_131 :
V_127 = F_39 ( V_36 , V_115 ) ;
if ( V_127 < 0 ) {
V_127 = - V_58 ;
break;
}
V_34 [ 2 ] = V_127 ;
break;
case V_132 :
V_127 = F_40 ( V_36 , V_115 , V_34 [ 1 ] ) ;
if ( V_127 < 0 )
V_127 = - V_58 ;
break;
case V_133 :
V_127 = F_42 ( V_36 , V_115 , & V_34 [ 2 ] ) ;
if ( V_127 < 0 ) {
V_127 = - V_58 ;
break;
}
V_34 [ 1 ] = V_127 ;
break;
default:
V_127 = - V_58 ;
break;
}
F_18 ( & V_36 -> V_59 , V_56 ) ;
return V_127 < 0 ? V_127 : V_33 -> V_41 ;
}
static int
F_46 ( struct V_9 * V_10 , struct V_30 * V_31 ,
unsigned long V_39 , unsigned V_134 ,
int V_120 )
{
struct V_114 * V_36 ;
unsigned int V_115 ;
V_36 = F_27 ( sizeof( * V_36 ) , V_89 ) ;
if ( ! V_36 ) {
F_7 ( V_10 -> V_25 , L_4 ) ;
return - V_90 ;
}
V_31 -> V_37 = V_36 ;
V_31 -> type = V_135 ;
V_31 -> V_92 = V_136 | V_93 ;
V_31 -> V_95 = 3 ;
V_31 -> V_100 = 0xFFFF ;
V_31 -> V_137 = F_33 ;
V_31 -> V_138 = F_35 ;
V_31 -> V_139 = F_43 ;
F_28 ( & V_36 -> V_59 ) ;
V_36 -> V_39 = V_134 + V_39 ;
V_36 -> V_120 = V_120 ;
if ( V_120 ) {
V_36 -> V_124 =
V_140 + ( V_134 >> 3 ) + V_39 ;
V_36 -> V_122 =
V_141 + ( V_134 >> 3 ) + V_39 ;
V_36 -> V_121 = ( V_134 >> 2 ) & 1 ;
}
for ( V_115 = 0 ; V_115 < 3 ; V_115 ++ ) {
F_44 ( V_36 -> V_39 , 0 , V_115 ,
V_142 | V_143 ) ;
if ( V_36 -> V_120 ) {
F_37 ( V_36 , V_115 , 0 ) ;
F_40 ( V_36 , V_115 , 0 ) ;
}
}
return 0 ;
}
static void
F_47 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_35 * V_36 = V_31 -> V_37 ;
F_30 ( V_36 ) ;
}
static void F_48 ( struct V_9 * V_10 , unsigned int V_105 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_144 = F_49 ( V_10 ) ;
char V_145 [ 60 ] ;
int V_146 ;
if ( F_50 ( V_147 ) &&
V_13 -> V_5 == V_148 )
V_146 = F_51 ( V_145 , sizeof( V_145 ) ,
L_5 , V_10 -> V_39 ) ;
else if ( F_50 ( V_149 ) &&
V_13 -> V_5 == V_6 )
V_146 = F_51 ( V_145 , sizeof( V_145 ) ,
L_6 , F_52 ( V_144 ) ) ;
else
V_146 = 0 ;
if ( V_105 )
V_146 += F_51 ( & V_145 [ V_146 ] , sizeof( V_145 ) - V_146 ,
L_7 , V_105 ,
( V_10 -> V_105 ? L_8 : L_9 ) ) ;
else
V_146 += F_51 ( & V_145 [ V_146 ] , sizeof( V_145 ) - V_146 ,
L_10 ) ;
F_53 ( V_10 -> V_25 , L_11 , V_10 -> V_150 , V_145 ) ;
}
static int F_54 ( struct V_9 * V_10 , unsigned long V_39 ,
unsigned int V_105 , unsigned long V_151 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_107 * V_108 = V_10 -> V_37 ;
const struct V_152 * V_153 =
& V_154 [ V_13 -> V_153 ] ;
struct V_30 * V_31 ;
int V_155 ;
unsigned int V_41 ;
int V_127 ;
V_108 -> V_112 = - 1 ;
V_10 -> V_39 = V_39 ;
V_10 -> V_150 = V_13 -> V_156 ;
V_127 = F_55 ( V_10 , V_153 -> V_157 ) ;
if ( V_127 )
return V_127 ;
for ( V_41 = 0 ; V_41 < V_10 -> V_158 ; V_41 ++ ) {
V_31 = & V_10 -> V_113 [ V_41 ] ;
switch ( V_153 -> V_159 [ V_41 ] ) {
case V_160 :
V_127 = F_46 ( V_10 , V_31 , V_39 ,
V_153 -> V_161 [ V_41 ] ,
V_153 -> V_120 ) ;
if ( V_127 < 0 )
return V_127 ;
break;
case V_162 :
V_127 = F_56 ( V_10 , V_31 , NULL ,
V_39 + V_153 -> V_161 [ V_41 ] ) ;
if ( V_127 < 0 )
return V_127 ;
break;
case V_163 :
if ( V_105 ) {
V_127 = F_26 ( V_10 , V_31 ,
V_39 +
V_164 ,
V_153 -> V_161 [ V_41 ] ,
V_153 ->
V_38 ) ;
if ( V_127 < 0 )
return V_127 ;
V_108 -> V_112 = V_41 ;
} else {
V_31 -> type = V_165 ;
}
break;
default:
V_31 -> type = V_165 ;
break;
}
}
V_155 = V_108 -> V_112 ;
if ( V_155 >= 0 && V_155 < V_10 -> V_158 )
V_10 -> V_166 = & V_10 -> V_113 [ V_155 ] ;
if ( V_105 ) {
if ( F_57 ( V_105 , F_31 , V_151 ,
V_28 , V_10 ) >= 0 ) {
V_10 -> V_105 = V_105 ;
} else {
F_58 ( V_10 -> V_25 ,
L_12 , V_105 ) ;
}
}
F_48 ( V_10 , V_105 ) ;
return 1 ;
}
static int F_59 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
unsigned long V_39 ;
int V_127 ;
F_60 ( V_10 , & V_2 -> V_10 ) ;
V_127 = F_61 ( V_2 , V_28 ) ;
if ( V_127 < 0 ) {
F_7 ( V_10 -> V_25 ,
L_13 ) ;
return V_127 ;
}
V_39 = F_62 ( V_2 , 2 ) ;
return F_54 ( V_10 , V_39 , V_2 -> V_105 , V_167 ) ;
}
static int F_63 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
int V_127 ;
F_53 ( V_10 -> V_25 , V_28 L_14 ) ;
V_127 = F_64 ( V_10 , sizeof( struct V_107 ) ) ;
if ( V_127 < 0 ) {
F_7 ( V_10 -> V_25 , L_4 ) ;
return V_127 ;
}
if ( F_50 ( V_147 ) &&
V_13 -> V_5 == V_148 ) {
unsigned long V_39 ;
unsigned int V_105 ;
V_39 = V_12 -> V_15 [ 0 ] ;
V_105 = V_12 -> V_15 [ 1 ] ;
V_127 = F_8 ( V_10 , V_39 , V_168 ) ;
if ( V_127 < 0 )
return V_127 ;
return F_54 ( V_10 , V_39 , V_105 , 0 ) ;
} else if ( F_50 ( V_149 ) &&
V_13 -> V_5 == V_6 ) {
struct V_2 * V_2 ;
V_2 = F_3 ( V_10 , V_12 ) ;
if ( ! V_2 )
return - V_29 ;
return F_59 ( V_10 , V_2 ) ;
} else {
F_7 ( V_10 -> V_25 , V_28
L_15 ) ;
return - V_58 ;
}
}
static int T_2 F_65 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
int V_127 ;
if ( ! F_50 ( V_149 ) )
return - V_58 ;
F_53 ( V_10 -> V_25 , V_28 L_16 ,
F_52 ( V_2 ) ) ;
V_127 = F_64 ( V_10 , sizeof( struct V_107 ) ) ;
if ( V_127 < 0 ) {
F_7 ( V_10 -> V_25 , L_4 ) ;
return V_127 ;
}
V_10 -> V_24 = F_1 ( V_2 ) ;
if ( V_10 -> V_24 == NULL ) {
F_7 ( V_10 -> V_25 , L_17 ) ;
return - V_58 ;
}
F_66 ( V_2 ) ;
return F_59 ( V_10 , V_2 ) ;
}
static void F_67 ( struct V_9 * V_10 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_144 = F_49 ( V_10 ) ;
const struct V_152 * V_153 ;
unsigned V_41 ;
if ( V_10 -> V_105 )
F_68 ( V_10 -> V_105 , V_10 ) ;
if ( V_10 -> V_113 ) {
V_153 = & V_154 [ V_13 -> V_153 ] ;
for ( V_41 = 0 ; V_41 < V_10 -> V_158 ; V_41 ++ ) {
struct V_30 * V_31 = & V_10 -> V_113 [ V_41 ] ;
switch ( V_153 -> V_159 [ V_41 ] ) {
case V_160 :
F_47 ( V_10 , V_31 ) ;
break;
case V_162 :
F_69 ( V_10 , V_31 ) ;
break;
case V_163 :
F_29 ( V_10 , V_31 ) ;
break;
default:
break;
}
}
}
if ( V_144 ) {
if ( V_10 -> V_39 )
F_70 ( V_144 ) ;
F_71 ( V_144 ) ;
} else {
if ( V_10 -> V_39 )
F_72 ( V_10 -> V_39 , V_168 ) ;
}
}
static int T_2 F_73 ( struct V_2 * V_10 ,
const struct V_169
* V_170 )
{
return F_74 ( V_10 , & V_171 ) ;
}
static void T_3 F_75 ( struct V_2 * V_10 )
{
F_76 ( V_10 ) ;
}
