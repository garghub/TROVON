static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_3 && V_2 -> V_4 == V_5 ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return V_6 && V_2 -> V_4 == V_7 ;
}
static const struct V_1 *
F_3 ( struct V_8 * V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
if ( F_1 ( & V_10 [ V_9 ] ) &&
V_8 -> V_11 == V_10 [ V_9 ] . V_12 )
return & V_10 [ V_9 ] ;
return NULL ;
}
static struct V_8 * F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_8 = NULL ;
int V_18 = V_16 -> V_19 [ 0 ] ;
int V_20 = V_16 -> V_19 [ 1 ] ;
F_7 (pci_dev) {
if ( V_18 || V_20 ) {
if ( V_18 != V_8 -> V_18 -> V_21 ||
V_20 != F_8 ( V_8 -> V_22 ) )
continue;
}
if ( V_8 -> V_23 != V_24 )
continue;
if ( V_17 -> V_25 == V_26 ) {
const struct V_1 * V_27 ;
V_27 = F_3 ( V_8 ) ;
if ( V_27 == NULL )
continue;
V_14 -> V_28 = V_27 ;
} else {
if ( V_8 -> V_11 != V_17 -> V_12 )
continue;
}
return V_8 ;
}
F_9 ( V_14 -> V_29 ,
L_1 ,
V_18 , V_20 ) ;
return NULL ;
}
static int
F_10 ( struct V_13 * V_14 ,
unsigned long V_30 , unsigned long V_31 )
{
if ( ! V_30 || ! F_11 ( V_30 , V_31 , V_32 ) ) {
F_9 ( V_14 -> V_29 , L_2 ,
V_30 , V_31 ) ;
return - V_33 ;
}
return 0 ;
}
static int
F_12 ( struct V_13 * V_14 ,
struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
if ( V_40 -> V_42 ) {
V_38 [ 1 ] = F_13 ( V_40 -> V_43 ) & V_40 -> V_44 ;
} else {
V_38 [ 0 ] = 0 ;
}
return V_37 -> V_45 ;
}
static void F_14 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
V_40 -> V_46 = 0 ;
V_40 -> V_47 = 0 ;
if ( V_40 -> V_42 )
F_15 ( 0 , V_40 -> V_43 ) ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
unsigned int V_45 ;
unsigned V_48 ;
struct V_39 * V_40 = V_35 -> V_41 ;
struct V_49 * V_50 = & V_35 -> V_51 -> V_50 ;
int V_52 = 0 ;
if ( ! V_40 -> V_53 && V_40 -> V_54 == 0 ) {
V_35 -> V_51 -> V_55 |= V_56 ;
V_40 -> V_46 = 0 ;
V_52 = 1 ;
} else {
V_48 = 0 ;
if ( V_50 -> V_57 ) {
for ( V_45 = 0 ; V_45 < V_50 -> V_58 ; V_45 ++ )
V_48 |= ( 1U << F_17 ( V_50 -> V_57 [ V_45 ] ) ) ;
}
V_48 &= V_40 -> V_44 ;
V_40 -> V_47 = V_48 ;
if ( V_40 -> V_42 )
F_15 ( V_48 , V_40 -> V_43 ) ;
}
return V_52 ;
}
static int
F_18 ( struct V_13 * V_14 , struct V_34 * V_35 ,
unsigned int V_59 )
{
struct V_39 * V_40 ;
unsigned long V_60 ;
int V_61 = 0 ;
if ( V_59 != 0 )
return - V_62 ;
V_40 = V_35 -> V_41 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
V_35 -> V_51 -> V_64 = NULL ;
if ( V_40 -> V_46 )
V_61 = F_16 ( V_14 , V_35 ) ;
F_20 ( & V_40 -> V_63 , V_60 ) ;
if ( V_61 )
F_21 ( V_14 , V_35 ) ;
return 1 ;
}
static int F_22 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned V_65 ;
unsigned V_66 ;
unsigned V_67 ;
unsigned int V_68 ;
unsigned long V_60 ;
V_65 = 0 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
V_68 = V_35 -> V_51 -> V_55 ;
if ( V_40 -> V_42 ) {
V_67 = V_40 -> V_47 ;
while ( ( V_66 = ( F_13 ( V_40 -> V_43 ) & V_40 -> V_44
& ~ V_65 ) ) != 0 ) {
V_65 |= V_66 ;
V_67 &= ~ V_65 ;
F_15 ( V_67 , V_40 -> V_43 ) ;
}
} else {
V_65 = V_40 -> V_47 ;
}
if ( V_65 ) {
V_67 = V_40 -> V_47 ;
if ( V_40 -> V_42 )
F_15 ( V_67 , V_40 -> V_43 ) ;
if ( V_40 -> V_46 ) {
if ( V_65 & V_40 -> V_47 ) {
short V_69 ;
unsigned int V_45 , V_70 , V_71 ;
V_69 = 0 ;
V_71 = V_35 -> V_51 -> V_50 . V_58 ;
for ( V_45 = 0 ; V_45 < V_71 ; V_45 ++ ) {
V_70 = F_17 ( V_35 -> V_51 -> V_50 . V_57 [ V_45 ] ) ;
if ( V_65 & ( 1U << V_70 ) )
V_69 |= ( 1U << V_45 ) ;
}
if ( F_23 ( V_35 -> V_51 , V_69 ) ) {
V_35 -> V_51 -> V_55 |= ( V_72 |
V_73 ) ;
} else {
F_14 ( V_14 , V_35 ) ;
V_35 -> V_51 -> V_55 |= V_74
| V_75 ;
F_24 ( V_14 , L_3 ) ;
}
if ( ! V_40 -> V_53 ) {
if ( V_40 -> V_54 > 0 ) {
V_40 -> V_54 -- ;
if ( V_40 -> V_54 == 0 ) {
V_35 -> V_51 -> V_55 |=
V_56 ;
F_14 ( V_14 ,
V_35 ) ;
}
}
}
}
}
}
F_20 ( & V_40 -> V_63 , V_60 ) ;
if ( V_68 != V_35 -> V_51 -> V_55 )
F_21 ( V_14 , V_35 ) ;
return ( V_65 != 0 ) ;
}
static int F_25 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned long V_60 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
if ( V_40 -> V_46 )
F_14 ( V_14 , V_35 ) ;
F_20 ( & V_40 -> V_63 , V_60 ) ;
return 0 ;
}
static int
F_26 ( struct V_13 * V_14 ,
struct V_34 * V_35 , struct V_49 * V_50 )
{
int V_76 = 0 ;
V_76 |= F_27 ( & V_50 -> V_77 , V_78 | V_79 ) ;
V_76 |= F_27 ( & V_50 -> V_80 , V_81 ) ;
V_76 |= F_27 ( & V_50 -> V_82 , V_78 ) ;
V_76 |= F_27 ( & V_50 -> V_83 , V_84 ) ;
V_76 |= F_27 ( & V_50 -> V_85 , V_84 | V_86 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_28 ( V_50 -> V_77 ) ;
V_76 |= F_28 ( V_50 -> V_85 ) ;
if ( V_76 )
return 2 ;
if ( V_50 -> V_87 != 0 ) {
V_50 -> V_87 = 0 ;
V_76 ++ ;
}
if ( V_50 -> V_88 != 0 ) {
V_50 -> V_88 = 0 ;
V_76 ++ ;
}
if ( V_50 -> V_89 != 0 ) {
V_50 -> V_89 = 0 ;
V_76 ++ ;
}
if ( V_50 -> V_90 != V_50 -> V_58 ) {
V_50 -> V_90 = V_50 -> V_58 ;
V_76 ++ ;
}
switch ( V_50 -> V_85 ) {
case V_84 :
break;
case V_86 :
if ( V_50 -> V_91 != 0 ) {
V_50 -> V_91 = 0 ;
V_76 ++ ;
}
break;
default:
break;
}
if ( V_76 )
return 3 ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_49 * V_50 = & V_35 -> V_51 -> V_50 ;
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned long V_60 ;
int V_61 = 0 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
V_40 -> V_46 = 1 ;
switch ( V_50 -> V_85 ) {
case V_84 :
V_40 -> V_53 = 0 ;
V_40 -> V_54 = V_50 -> V_91 ;
break;
default:
V_40 -> V_53 = 1 ;
V_40 -> V_54 = 0 ;
break;
}
switch ( V_50 -> V_77 ) {
case V_79 :
V_35 -> V_51 -> V_64 = F_18 ;
break;
default:
V_61 = F_16 ( V_14 , V_35 ) ;
break;
}
F_20 ( & V_40 -> V_63 , V_60 ) ;
if ( V_61 )
F_21 ( V_14 , V_35 ) ;
return 0 ;
}
static int
F_30 ( struct V_13 * V_14 , struct V_34 * V_35 ,
unsigned long V_43 , unsigned V_44 ,
int V_42 )
{
struct V_39 * V_40 ;
V_40 = F_31 ( sizeof( * V_40 ) , V_92 ) ;
if ( ! V_40 ) {
F_9 ( V_14 -> V_29 , L_4 ) ;
return - V_93 ;
}
V_40 -> V_43 = V_43 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_44 = V_44 ;
F_32 ( & V_40 -> V_63 ) ;
if ( V_42 )
F_15 ( 0 , V_40 -> V_43 ) ;
V_35 -> V_41 = V_40 ;
V_35 -> type = V_94 ;
V_35 -> V_95 = V_96 | V_97 ;
if ( V_42 ) {
V_35 -> V_98 = V_99 ;
V_35 -> V_100 = V_99 ;
} else {
V_35 -> V_98 = 1 ;
V_35 -> V_100 = 1 ;
}
V_35 -> V_101 = & V_102 ;
V_35 -> V_103 = 1 ;
V_35 -> V_104 = F_12 ;
V_35 -> V_105 = F_26 ;
V_35 -> V_106 = F_29 ;
V_35 -> V_107 = F_25 ;
return 0 ;
}
static void
F_33 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
F_34 ( V_40 ) ;
}
static T_1 F_35 ( int V_108 , void * V_109 )
{
struct V_13 * V_14 = V_109 ;
struct V_110 * V_111 = V_14 -> V_41 ;
struct V_34 * V_35 ;
int V_112 ;
if ( ! V_14 -> V_113 )
return V_114 ;
if ( V_111 -> V_115 >= 0 ) {
V_35 = & V_14 -> V_116 [ V_111 -> V_115 ] ;
V_112 = F_22 ( V_14 , V_35 ) ;
} else {
V_112 = 0 ;
}
return F_36 ( V_112 ) ;
}
static int
F_37 ( struct V_13 * V_14 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_117 * V_40 = V_35 -> V_41 ;
int V_118 = F_17 ( V_37 -> V_119 ) ;
unsigned long V_60 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
V_38 [ 0 ] = F_38 ( V_40 -> V_43 , 0 , V_118 ) ;
F_20 ( & V_40 -> V_63 , V_60 ) ;
return 1 ;
}
static int
F_39 ( struct V_13 * V_14 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_117 * V_40 = V_35 -> V_41 ;
int V_118 = F_17 ( V_37 -> V_119 ) ;
unsigned long V_60 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
F_40 ( V_40 -> V_43 , 0 , V_118 , V_38 [ 0 ] ) ;
F_20 ( & V_40 -> V_63 , V_60 ) ;
return 1 ;
}
static int
F_41 ( struct V_117 * V_40 ,
unsigned int V_120 , unsigned int V_121 )
{
unsigned char V_122 ;
if ( ! V_40 -> V_123 )
return - 1 ;
if ( V_120 > 2 )
return - 1 ;
if ( V_121 > 7 )
return - 1 ;
V_40 -> V_121 [ V_120 ] = V_121 ;
V_122 = F_42 ( V_40 -> V_124 , V_120 , V_121 ) ;
F_15 ( V_122 , V_40 -> V_125 ) ;
return 0 ;
}
static int
F_43 ( struct V_117 * V_40 ,
unsigned int V_120 )
{
if ( ! V_40 -> V_123 )
return - 1 ;
if ( V_120 > 2 )
return - 1 ;
return V_40 -> V_121 [ V_120 ] ;
}
static int
F_44 ( struct V_117 * V_40 ,
unsigned int V_120 , unsigned int V_126 )
{
unsigned char V_122 ;
if ( ! V_40 -> V_123 )
return - 1 ;
if ( V_120 > 2 )
return - 1 ;
if ( V_126 > 7 )
return - 1 ;
V_40 -> V_126 [ V_120 ] = V_126 ;
V_122 = F_45 ( V_40 -> V_124 , V_120 , V_126 ) ;
F_15 ( V_122 , V_40 -> V_127 ) ;
return 0 ;
}
static int
F_46 ( struct V_117 * V_40 ,
unsigned int V_120 , unsigned int * V_128 )
{
unsigned V_126 ;
if ( ! V_40 -> V_123 )
return - 1 ;
if ( V_120 > 2 )
return - 1 ;
V_126 = V_40 -> V_126 [ V_120 ] ;
* V_128 = V_129 [ V_126 ] ;
return V_126 ;
}
static int
F_47 ( struct V_13 * V_14 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_117 * V_40 = V_35 -> V_41 ;
int V_130 = 0 ;
int V_118 = F_17 ( V_37 -> V_119 ) ;
unsigned long V_60 ;
F_19 ( & V_40 -> V_63 , V_60 ) ;
switch ( V_38 [ 0 ] ) {
case V_131 :
V_130 = F_48 ( V_40 -> V_43 , 0 , V_118 , V_38 [ 1 ] ) ;
if ( V_130 < 0 )
V_130 = - V_62 ;
break;
case V_132 :
V_38 [ 1 ] = F_49 ( V_40 -> V_43 , 0 , V_118 ) ;
break;
case V_133 :
V_130 = F_41 ( V_40 , V_118 , V_38 [ 2 ] ) ;
if ( V_130 < 0 )
V_130 = - V_62 ;
break;
case V_134 :
V_130 = F_43 ( V_40 , V_118 ) ;
if ( V_130 < 0 ) {
V_130 = - V_62 ;
break;
}
V_38 [ 2 ] = V_130 ;
break;
case V_135 :
V_130 = F_44 ( V_40 , V_118 , V_38 [ 1 ] ) ;
if ( V_130 < 0 )
V_130 = - V_62 ;
break;
case V_136 :
V_130 = F_46 ( V_40 , V_118 , & V_38 [ 2 ] ) ;
if ( V_130 < 0 ) {
V_130 = - V_62 ;
break;
}
V_38 [ 1 ] = V_130 ;
break;
default:
V_130 = - V_62 ;
break;
}
F_20 ( & V_40 -> V_63 , V_60 ) ;
return V_130 < 0 ? V_130 : V_37 -> V_45 ;
}
static int
F_50 ( struct V_13 * V_14 , struct V_34 * V_35 ,
unsigned long V_43 , unsigned V_137 ,
int V_123 )
{
struct V_117 * V_40 ;
unsigned int V_118 ;
V_40 = F_31 ( sizeof( * V_40 ) , V_92 ) ;
if ( ! V_40 ) {
F_9 ( V_14 -> V_29 , L_4 ) ;
return - V_93 ;
}
V_35 -> V_41 = V_40 ;
V_35 -> type = V_138 ;
V_35 -> V_95 = V_139 | V_96 ;
V_35 -> V_98 = 3 ;
V_35 -> V_103 = 0xFFFF ;
V_35 -> V_140 = F_37 ;
V_35 -> V_141 = F_39 ;
V_35 -> V_142 = F_47 ;
F_32 ( & V_40 -> V_63 ) ;
V_40 -> V_43 = V_137 + V_43 ;
V_40 -> V_123 = V_123 ;
if ( V_123 ) {
V_40 -> V_127 =
V_143 + ( V_137 >> 3 ) + V_43 ;
V_40 -> V_125 =
V_144 + ( V_137 >> 3 ) + V_43 ;
V_40 -> V_124 = ( V_137 >> 2 ) & 1 ;
}
for ( V_118 = 0 ; V_118 < 3 ; V_118 ++ ) {
F_48 ( V_40 -> V_43 , 0 , V_118 ,
V_145 | V_146 ) ;
if ( V_40 -> V_123 ) {
F_41 ( V_40 , V_118 , 0 ) ;
F_44 ( V_40 , V_118 , 0 ) ;
}
}
return 0 ;
}
static void
F_51 ( struct V_13 * V_14 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
F_34 ( V_40 ) ;
}
static void F_52 ( struct V_13 * V_14 , unsigned int V_108 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_147 = F_53 ( V_14 ) ;
char V_148 [ 60 ] ;
int V_149 ;
if ( F_2 ( V_17 ) )
V_149 = F_54 ( V_148 , sizeof( V_148 ) ,
L_5 , V_14 -> V_43 ) ;
else if ( F_1 ( V_17 ) )
V_149 = F_54 ( V_148 , sizeof( V_148 ) ,
L_6 , F_55 ( V_147 ) ) ;
else
V_149 = 0 ;
if ( V_108 )
V_149 += F_54 ( & V_148 [ V_149 ] , sizeof( V_148 ) - V_149 ,
L_7 , V_108 ,
( V_14 -> V_108 ? L_8 : L_9 ) ) ;
else
V_149 += F_54 ( & V_148 [ V_149 ] , sizeof( V_148 ) - V_149 ,
L_10 ) ;
F_56 ( V_14 -> V_29 , L_11 , V_14 -> V_150 , V_148 ) ;
}
static int F_57 ( struct V_13 * V_14 , unsigned long V_43 ,
unsigned int V_108 , unsigned long V_151 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_110 * V_111 = V_14 -> V_41 ;
const struct V_152 * V_153 =
& V_154 [ V_17 -> V_153 ] ;
struct V_34 * V_35 ;
int V_155 ;
unsigned int V_45 ;
int V_130 ;
V_111 -> V_115 = - 1 ;
V_14 -> V_43 = V_43 ;
V_14 -> V_150 = V_17 -> V_156 ;
V_130 = F_58 ( V_14 , V_153 -> V_157 ) ;
if ( V_130 )
return V_130 ;
for ( V_45 = 0 ; V_45 < V_14 -> V_158 ; V_45 ++ ) {
V_35 = & V_14 -> V_116 [ V_45 ] ;
switch ( V_153 -> V_159 [ V_45 ] ) {
case V_160 :
V_130 = F_50 ( V_14 , V_35 , V_43 ,
V_153 -> V_161 [ V_45 ] ,
V_153 -> V_123 ) ;
if ( V_130 < 0 )
return V_130 ;
break;
case V_162 :
V_130 = F_59 ( V_14 , V_35 , NULL ,
V_43 + V_153 -> V_161 [ V_45 ] ) ;
if ( V_130 < 0 )
return V_130 ;
break;
case V_163 :
if ( V_108 ) {
V_130 = F_30 ( V_14 , V_35 ,
V_43 +
V_164 ,
V_153 -> V_161 [ V_45 ] ,
V_153 ->
V_42 ) ;
if ( V_130 < 0 )
return V_130 ;
V_111 -> V_115 = V_45 ;
} else {
V_35 -> type = V_165 ;
}
break;
default:
V_35 -> type = V_165 ;
break;
}
}
V_155 = V_111 -> V_115 ;
if ( V_155 >= 0 && V_155 < V_14 -> V_158 )
V_14 -> V_166 = & V_14 -> V_116 [ V_155 ] ;
if ( V_108 ) {
if ( F_60 ( V_108 , F_35 , V_151 ,
V_32 , V_14 ) >= 0 ) {
V_14 -> V_108 = V_108 ;
} else {
F_61 ( V_14 -> V_29 ,
L_12 , V_108 ) ;
}
}
F_52 ( V_14 , V_108 ) ;
return 1 ;
}
static int F_62 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
unsigned long V_43 ;
int V_130 ;
F_63 ( V_14 , & V_8 -> V_14 ) ;
V_130 = F_64 ( V_8 , V_32 ) ;
if ( V_130 < 0 ) {
F_9 ( V_14 -> V_29 ,
L_13 ) ;
return V_130 ;
}
V_43 = F_65 ( V_8 , 2 ) ;
return F_57 ( V_14 , V_43 , V_8 -> V_108 , V_167 ) ;
}
static int F_66 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
int V_130 ;
F_56 ( V_14 -> V_29 , V_32 L_14 ) ;
V_130 = F_67 ( V_14 , sizeof( struct V_110 ) ) ;
if ( V_130 < 0 ) {
F_9 ( V_14 -> V_29 , L_4 ) ;
return V_130 ;
}
if ( F_2 ( V_17 ) ) {
unsigned long V_43 ;
unsigned int V_108 ;
V_43 = V_16 -> V_19 [ 0 ] ;
V_108 = V_16 -> V_19 [ 1 ] ;
V_130 = F_10 ( V_14 , V_43 , V_168 ) ;
if ( V_130 < 0 )
return V_130 ;
return F_57 ( V_14 , V_43 , V_108 , 0 ) ;
} else if ( F_1 ( V_17 ) ) {
struct V_8 * V_8 ;
V_8 = F_5 ( V_14 , V_16 ) ;
if ( ! V_8 )
return - V_33 ;
return F_62 ( V_14 , V_8 ) ;
} else {
F_9 ( V_14 -> V_29 , V_32
L_15 ) ;
return - V_62 ;
}
}
static int T_2 F_68 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
int V_130 ;
if ( ! V_3 )
return - V_62 ;
F_56 ( V_14 -> V_29 , V_32 L_16 ,
F_55 ( V_8 ) ) ;
V_130 = F_67 ( V_14 , sizeof( struct V_110 ) ) ;
if ( V_130 < 0 ) {
F_9 ( V_14 -> V_29 , L_4 ) ;
return V_130 ;
}
V_14 -> V_28 = F_3 ( V_8 ) ;
if ( V_14 -> V_28 == NULL ) {
F_9 ( V_14 -> V_29 , L_17 ) ;
return - V_62 ;
}
F_69 ( V_8 ) ;
return F_62 ( V_14 , V_8 ) ;
}
static void F_70 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
const struct V_152 * V_153 ;
unsigned V_45 ;
if ( ! V_17 )
return;
if ( V_14 -> V_108 )
F_71 ( V_14 -> V_108 , V_14 ) ;
if ( V_14 -> V_116 ) {
V_153 = & V_154 [ V_17 -> V_153 ] ;
for ( V_45 = 0 ; V_45 < V_14 -> V_158 ; V_45 ++ ) {
struct V_34 * V_35 = & V_14 -> V_116 [ V_45 ] ;
switch ( V_153 -> V_159 [ V_45 ] ) {
case V_160 :
F_51 ( V_14 , V_35 ) ;
break;
case V_162 :
F_72 ( V_14 , V_35 ) ;
break;
case V_163 :
F_33 ( V_14 , V_35 ) ;
break;
default:
break;
}
}
}
if ( F_2 ( V_17 ) ) {
if ( V_14 -> V_43 )
F_73 ( V_14 -> V_43 , V_168 ) ;
} else if ( F_1 ( V_17 ) ) {
struct V_8 * V_147 = F_53 ( V_14 ) ;
if ( V_147 ) {
if ( V_14 -> V_43 )
F_74 ( V_147 ) ;
F_75 ( V_147 ) ;
}
}
}
static int T_2 F_76 ( struct V_8 * V_14 ,
const struct V_169
* V_170 )
{
return F_77 ( V_14 , & V_171 ) ;
}
static void T_3 F_78 ( struct V_8 * V_14 )
{
F_79 ( V_14 ) ;
}
