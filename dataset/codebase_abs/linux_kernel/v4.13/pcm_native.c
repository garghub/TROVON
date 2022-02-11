static inline void F_1 ( struct V_1 * V_2 )
{
while ( ! F_2 ( V_2 ) )
F_3 () ;
}
void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 ) {
F_5 ( & V_7 , V_8 ) ;
F_6 ( & V_4 -> V_9 . V_10 ) ;
} else {
F_7 ( & V_11 ) ;
F_8 ( & V_4 -> V_9 . V_2 ) ;
}
}
void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 ) {
F_10 ( & V_4 -> V_9 . V_10 ) ;
F_11 ( & V_7 ) ;
} else {
F_12 ( & V_4 -> V_9 . V_2 ) ;
F_13 ( & V_11 ) ;
}
}
void F_14 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 -> V_6 )
F_15 () ;
F_4 ( V_4 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
F_9 ( V_4 ) ;
if ( ! V_4 -> V_5 -> V_6 )
F_17 () ;
}
unsigned long F_18 ( struct V_3 * V_4 )
{
unsigned long V_12 = 0 ;
if ( ! V_4 -> V_5 -> V_6 )
F_19 ( V_12 ) ;
F_4 ( V_4 ) ;
return V_12 ;
}
void F_20 ( struct V_3 * V_4 ,
unsigned long V_12 )
{
F_9 ( V_4 ) ;
if ( ! V_4 -> V_5 -> V_6 )
F_21 ( V_12 ) ;
}
int F_22 ( struct V_3 * V_4 , struct F_22 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_5 = V_4 -> V_5 ;
struct V_17 * V_18 = V_4 -> V_18 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_19 = V_5 -> V_19 -> V_20 ;
V_13 -> V_21 = V_5 -> V_21 ;
V_13 -> V_22 = V_4 -> V_22 ;
V_13 -> V_23 = V_4 -> V_20 ;
F_23 ( V_13 -> V_24 , V_5 -> V_24 , sizeof( V_13 -> V_24 ) ) ;
F_23 ( V_13 -> V_25 , V_5 -> V_25 , sizeof( V_13 -> V_25 ) ) ;
V_13 -> V_26 = V_5 -> V_26 ;
V_13 -> V_27 = V_5 -> V_27 ;
V_13 -> V_28 = V_18 -> V_29 ;
V_13 -> V_30 = V_18 -> V_29 - V_18 -> V_31 ;
F_23 ( V_13 -> V_32 , V_4 -> V_25 , sizeof( V_13 -> V_32 ) ) ;
V_15 = V_4 -> V_15 ;
return 0 ;
}
int F_24 ( struct V_3 * V_4 ,
struct F_22 T_1 * V_33 )
{
struct F_22 * V_13 ;
int V_34 ;
V_13 = F_25 ( sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
return - V_36 ;
V_34 = F_22 ( V_4 , V_13 ) ;
if ( V_34 >= 0 ) {
if ( F_26 ( V_33 , V_13 , sizeof( * V_13 ) ) )
V_34 = - V_37 ;
}
F_27 ( V_13 ) ;
return V_34 ;
}
static bool F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_15 -> V_38 . V_13 & V_39 ) )
return false ;
#if F_29 ( V_40 ) || ! F_29 ( V_41 )
if ( ! V_4 -> V_42 -> V_43 &&
V_4 -> V_44 . V_45 . type == V_46 )
return false ;
#endif
return true ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 =
& V_4 -> V_15 -> V_51 ;
struct V_52 * V_53 ;
unsigned int V_54 ;
struct V_52 V_55 ;
int V_56 ;
for ( V_54 = V_57 ; V_54 <= V_58 ; V_54 ++ ) {
V_53 = F_31 ( V_48 , V_54 ) ;
if ( F_32 ( V_53 ) )
return - V_59 ;
if ( ! ( V_48 -> V_60 & ( 1 << V_54 ) ) )
continue;
if ( F_33 () )
V_55 = * V_53 ;
V_56 = F_34 ( V_53 , F_35 ( V_50 , V_54 ) ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 == 0 )
continue;
F_36 ( V_4 , V_54 , 0 , & V_55 , V_53 ) ;
V_48 -> V_61 |= 1 << V_54 ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 =
& V_4 -> V_15 -> V_51 ;
struct V_62 * V_63 ;
unsigned int V_54 ;
struct V_62 V_64 ;
int V_56 ;
for ( V_54 = V_65 ; V_54 <= V_66 ; V_54 ++ ) {
V_63 = F_38 ( V_48 , V_54 ) ;
if ( F_39 ( V_63 ) )
return - V_59 ;
if ( ! ( V_48 -> V_60 & ( 1 << V_54 ) ) )
continue;
if ( F_40 () )
V_64 = * V_63 ;
V_56 = F_41 ( V_63 , F_42 ( V_50 , V_54 ) ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 == 0 )
continue;
F_43 ( V_4 , V_54 , 0 , & V_64 , V_63 ) ;
V_48 -> V_61 |= 1 << V_54 ;
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 =
& V_4 -> V_15 -> V_51 ;
unsigned int V_54 ;
unsigned int V_67 [ V_50 -> V_68 ] ;
unsigned int V_69 [ V_66 + 1 ] ;
unsigned int V_70 ;
struct V_71 * V_72 ;
unsigned int V_73 ;
struct V_52 V_55 ;
struct V_62 V_64 ;
bool V_74 ;
int V_56 ;
for ( V_54 = 0 ; V_54 < V_50 -> V_68 ; V_54 ++ )
V_67 [ V_54 ] = 0 ;
for ( V_54 = 0 ; V_54 <= V_66 ; V_54 ++ )
V_69 [ V_54 ] = ( V_48 -> V_60 & ( 1 << V_54 ) ) ? 1 : 0 ;
V_70 = 2 ;
V_75:
V_74 = false ;
for ( V_54 = 0 ; V_54 < V_50 -> V_68 ; V_54 ++ ) {
V_72 = & V_50 -> V_76 [ V_54 ] ;
if ( V_72 -> V_77 && ! ( V_72 -> V_77 & V_48 -> V_12 ) )
continue;
for ( V_73 = 0 ; V_72 -> V_78 [ V_73 ] >= 0 ; V_73 ++ ) {
if ( V_69 [ V_72 -> V_78 [ V_73 ] ] > V_67 [ V_54 ] )
break;
}
if ( V_72 -> V_78 [ V_73 ] < 0 )
continue;
if ( F_33 () ) {
if ( F_45 ( V_72 -> V_79 ) )
V_55 = * F_31 ( V_48 , V_72 -> V_79 ) ;
}
if ( F_40 () ) {
if ( F_46 ( V_72 -> V_79 ) )
V_64 = * F_38 ( V_48 , V_72 -> V_79 ) ;
}
V_56 = V_72 -> V_80 ( V_48 , V_72 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 && V_72 -> V_79 >= 0 ) {
if ( F_45 ( V_72 -> V_79 ) ) {
F_36 ( V_4 , V_72 -> V_79 ,
V_54 + 1 , & V_55 ,
F_31 ( V_48 , V_72 -> V_79 ) ) ;
}
if ( F_46 ( V_72 -> V_79 ) ) {
F_43 ( V_4 , V_72 -> V_79 ,
V_54 + 1 , & V_64 ,
F_38 ( V_48 , V_72 -> V_79 ) ) ;
}
V_48 -> V_61 |= ( 1 << V_72 -> V_79 ) ;
V_69 [ V_72 -> V_79 ] = V_70 ;
V_74 = true ;
}
V_67 [ V_54 ] = V_70 ++ ;
}
if ( V_74 )
goto V_75;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
const struct V_62 * V_63 ;
const struct V_52 * V_53 ;
int V_34 ;
if ( ! V_48 -> V_81 ) {
V_63 = F_48 ( V_48 , V_82 ) ;
if ( F_49 ( V_63 ) )
V_48 -> V_81 = F_50 ( V_63 ) ;
}
if ( ! V_48 -> V_83 ) {
V_63 = F_48 ( V_48 , V_84 ) ;
if ( F_49 ( V_63 ) ) {
V_48 -> V_85 = F_50 ( V_63 ) ;
V_48 -> V_83 = 1 ;
}
}
if ( ! V_48 -> V_86 ) {
V_53 = F_51 ( V_48 , V_87 ) ;
V_63 = F_48 ( V_48 , V_88 ) ;
if ( F_52 ( V_53 ) && F_49 ( V_63 ) ) {
V_34 = V_4 -> V_42 -> V_89 ( V_4 ,
V_90 , V_48 ) ;
if ( V_34 < 0 )
return V_34 ;
}
}
if ( ! V_48 -> V_13 ) {
V_48 -> V_13 = V_4 -> V_15 -> V_38 . V_13 ;
V_48 -> V_13 &= ~ ( V_91 |
V_92 ) ;
if ( ! F_28 ( V_4 ) )
V_48 -> V_13 &= ~ ( V_39 |
V_93 ) ;
}
return 0 ;
}
int F_53 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
int V_34 ;
V_48 -> V_13 = 0 ;
V_48 -> V_86 = 0 ;
if ( V_48 -> V_60 & ( 1 << V_82 ) )
V_48 -> V_81 = 0 ;
if ( V_48 -> V_60 & ( 1 << V_84 ) ) {
V_48 -> V_85 = 0 ;
V_48 -> V_83 = 0 ;
}
V_34 = F_30 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_37 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_44 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
return V_34 ;
V_48 -> V_60 = 0 ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_47 T_1 * V_94 )
{
struct V_47 * V_48 ;
int V_34 ;
V_48 = F_55 ( V_94 , sizeof( * V_48 ) ) ;
if ( F_56 ( V_48 ) )
return F_57 ( V_48 ) ;
V_34 = F_53 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_95;
V_34 = F_47 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_95;
if ( F_26 ( V_94 , V_48 , sizeof( * V_48 ) ) )
V_34 = - V_37 ;
V_95:
F_27 ( V_48 ) ;
return V_34 ;
}
static int F_58 ( struct V_14 * V_15 )
{
int V_96 ;
if ( ! V_15 -> V_97 )
return - 1 ;
V_96 = ( 750000 / V_15 -> V_97 ) * V_15 -> V_98 ;
V_96 += ( ( 750000 % V_15 -> V_97 ) * V_15 -> V_98 ) /
V_15 -> V_97 ;
return V_96 ;
}
static void F_59 ( struct V_3 * V_4 , int V_99 )
{
F_14 ( V_4 ) ;
if ( V_4 -> V_15 -> V_100 -> V_99 != V_101 )
V_4 -> V_15 -> V_100 -> V_99 = V_99 ;
F_16 ( V_4 ) ;
}
static inline void F_60 ( struct V_3 * V_4 ,
int V_102 )
{
#ifdef F_61
if ( V_4 -> V_103 )
F_62 ( V_4 -> V_103 , V_102 ,
& V_4 -> V_15 -> V_104 ) ;
#endif
}
static int F_63 ( struct V_3 * V_5 ,
struct V_47 * V_48 )
{
static const int V_105 [] = {
V_106 ,
V_87 ,
V_107 ,
V_88 ,
V_84 ,
V_108 ,
V_109 ,
V_110 ,
- 1
} ;
const int * V_111 ;
struct V_52 V_55 ;
struct V_62 V_64 ;
int V_56 ;
for ( V_111 = V_105 ; * V_111 != - 1 ; V_111 ++ ) {
if ( F_33 () ) {
if ( F_45 ( * V_111 ) )
V_55 = * F_31 ( V_48 , * V_111 ) ;
}
if ( F_40 () ) {
if ( F_46 ( * V_111 ) )
V_64 = * F_38 ( V_48 , * V_111 ) ;
}
if ( * V_111 != V_109 )
V_56 = F_64 ( V_5 , V_48 , * V_111 , NULL ) ;
else
V_56 = F_65 ( V_5 , V_48 , * V_111 , NULL ) ;
if ( F_66 ( V_56 < 0 ) )
return V_56 ;
if ( V_56 == 0 )
continue;
if ( F_45 ( * V_111 ) ) {
F_36 ( V_5 , * V_111 , 0 , & V_55 ,
F_31 ( V_48 , * V_111 ) ) ;
}
if ( F_46 ( * V_111 ) ) {
F_43 ( V_5 , * V_111 , 0 , & V_64 ,
F_38 ( V_48 , * V_111 ) ) ;
}
}
return 0 ;
}
static int V_47 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 ;
int V_34 , V_96 ;
unsigned int V_112 ;
T_2 V_113 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
F_14 ( V_4 ) ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_115 :
case V_116 :
case V_117 :
break;
default:
F_16 ( V_4 ) ;
return - V_118 ;
}
F_16 ( V_4 ) ;
#if F_68 ( V_119 )
if ( ! V_4 -> V_120 . V_120 )
#endif
if ( F_69 ( & V_4 -> V_121 ) )
return - V_118 ;
V_48 -> V_60 = ~ 0U ;
V_34 = F_53 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_122;
V_34 = F_63 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_122;
V_34 = F_47 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_122;
if ( V_4 -> V_42 -> V_123 != NULL ) {
V_34 = V_4 -> V_42 -> V_123 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_122;
}
V_15 -> V_124 = F_70 ( V_48 ) ;
V_15 -> V_125 = F_71 ( V_48 ) ;
V_15 -> V_126 = F_72 ( V_48 ) ;
V_15 -> V_127 = F_73 ( V_48 ) ;
V_15 -> V_97 = F_74 ( V_48 ) ;
V_15 -> V_98 = F_75 ( V_48 ) ;
V_15 -> V_128 = F_76 ( V_48 ) ;
V_15 -> V_129 = F_77 ( V_48 ) ;
V_15 -> V_13 = V_48 -> V_13 ;
V_15 -> V_85 = V_48 -> V_85 ;
V_15 -> V_83 = V_48 -> V_83 ;
V_15 -> V_130 =
( V_48 -> V_13 & V_131 ) &&
( V_48 -> V_12 & V_132 ) ;
V_112 = F_78 ( V_15 -> V_125 ) ;
V_15 -> V_133 = V_112 ;
V_112 *= V_15 -> V_127 ;
V_15 -> V_134 = V_112 ;
V_113 = 1 ;
while ( V_112 % 8 != 0 ) {
V_112 *= 2 ;
V_113 *= 2 ;
}
V_15 -> V_135 = V_112 / 8 ;
V_15 -> V_136 = V_113 ;
V_15 -> V_137 = V_138 ;
V_15 -> V_139 = 1 ;
V_15 -> V_140 -> V_141 = V_15 -> V_98 ;
V_15 -> V_142 = 1 ;
V_15 -> V_143 = V_15 -> V_129 ;
V_15 -> V_144 = 0 ;
V_15 -> V_145 = 0 ;
V_15 -> V_146 = V_15 -> V_129 ;
while ( V_15 -> V_146 * 2 <= V_147 - V_15 -> V_129 )
V_15 -> V_146 *= 2 ;
F_79 ( V_4 ) ;
F_59 ( V_4 , V_116 ) ;
if ( F_80 ( & V_4 -> V_148 ) )
F_81 ( & V_4 -> V_148 ) ;
if ( ( V_96 = F_58 ( V_15 ) ) >= 0 )
F_82 ( & V_4 -> V_148 ,
V_149 , V_96 ) ;
return 0 ;
V_122:
F_59 ( V_4 , V_115 ) ;
if ( V_4 -> V_42 -> V_150 != NULL )
V_4 -> V_42 -> V_150 ( V_4 ) ;
return V_34 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_47 T_1 * V_94 )
{
struct V_47 * V_48 ;
int V_34 ;
V_48 = F_55 ( V_94 , sizeof( * V_48 ) ) ;
if ( F_56 ( V_48 ) )
return F_57 ( V_48 ) ;
V_34 = V_47 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_95;
if ( F_26 ( V_94 , V_48 , sizeof( * V_48 ) ) )
V_34 = - V_37 ;
V_95:
F_27 ( V_48 ) ;
return V_34 ;
}
static int F_84 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
int V_151 = 0 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
F_14 ( V_4 ) ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_116 :
case V_117 :
break;
default:
F_16 ( V_4 ) ;
return - V_118 ;
}
F_16 ( V_4 ) ;
if ( F_69 ( & V_4 -> V_121 ) )
return - V_118 ;
if ( V_4 -> V_42 -> V_150 )
V_151 = V_4 -> V_42 -> V_150 ( V_4 ) ;
F_59 ( V_4 , V_115 ) ;
F_81 ( & V_4 -> V_148 ) ;
return V_151 ;
}
static int F_85 ( struct V_3 * V_4 ,
struct F_85 * V_48 )
{
struct V_14 * V_15 ;
int V_34 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
F_14 ( V_4 ) ;
if ( V_15 -> V_100 -> V_99 == V_115 ) {
F_16 ( V_4 ) ;
return - V_118 ;
}
F_16 ( V_4 ) ;
if ( V_48 -> V_137 < 0 ||
V_48 -> V_137 > V_152 )
return - V_59 ;
if ( V_48 -> V_153 >= F_86 ( 2 , 0 , 12 ) &&
V_48 -> V_154 > V_155 )
return - V_59 ;
if ( V_48 -> V_141 == 0 )
return - V_59 ;
if ( V_48 -> V_145 >= V_15 -> V_146 ) {
if ( V_48 -> V_144 != 0 )
return - V_59 ;
} else {
if ( V_48 -> V_145 > V_48 -> V_144 )
return - V_59 ;
if ( V_48 -> V_144 > V_15 -> V_129 )
return - V_59 ;
}
V_34 = 0 ;
F_14 ( V_4 ) ;
V_15 -> V_137 = V_48 -> V_137 ;
if ( V_48 -> V_153 >= F_86 ( 2 , 0 , 12 ) )
V_15 -> V_154 = V_48 -> V_154 ;
V_15 -> V_139 = V_48 -> V_139 ;
V_15 -> V_140 -> V_141 = V_48 -> V_141 ;
V_15 -> V_142 = V_48 -> V_142 ;
V_15 -> V_143 = V_48 -> V_143 ;
V_15 -> V_144 = V_48 -> V_144 ;
V_15 -> V_145 = V_48 -> V_145 ;
V_48 -> V_146 = V_15 -> V_146 ;
if ( F_87 ( V_4 ) ) {
if ( V_4 -> V_22 == V_156 &&
V_15 -> V_145 > 0 )
F_88 ( V_4 , V_157 ) ;
V_34 = F_89 ( V_4 , V_15 ) ;
}
F_16 ( V_4 ) ;
return V_34 ;
}
static int F_90 ( struct V_3 * V_4 ,
struct F_85 T_1 * V_94 )
{
struct F_85 V_48 ;
int V_34 ;
if ( F_91 ( & V_48 , V_94 , sizeof( V_48 ) ) )
return - V_37 ;
V_34 = F_85 ( V_4 , & V_48 ) ;
if ( F_26 ( V_94 , & V_48 , sizeof( V_48 ) ) )
return - V_37 ;
return V_34 ;
}
int F_92 ( struct V_3 * V_4 ,
struct F_92 * V_100 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
F_14 ( V_4 ) ;
F_93 ( V_100 -> V_158 ,
& V_15 -> V_159 ) ;
if ( V_15 -> V_159 . V_160 ==
V_161 ) {
if ( V_15 -> V_38 . V_13 & V_162 )
V_15 -> V_159 . V_160 =
V_163 ;
else
V_15 -> V_159 . V_160 =
V_164 ;
V_15 -> V_165 . V_166 = 0 ;
} else
V_15 -> V_165 . V_166 = 1 ;
V_100 -> V_99 = V_15 -> V_100 -> V_99 ;
V_100 -> V_167 = V_15 -> V_100 -> V_167 ;
if ( V_100 -> V_99 == V_115 )
goto V_168;
V_100 -> V_104 = V_15 -> V_104 ;
if ( F_87 ( V_4 ) ) {
F_94 ( V_4 ) ;
if ( V_15 -> V_137 == V_169 ) {
V_100 -> V_170 = V_15 -> V_100 -> V_170 ;
V_100 -> V_171 = V_15 -> V_171 ;
V_100 -> V_172 =
V_15 -> V_100 -> V_172 ;
if ( V_15 -> V_165 . V_166 == 1 )
F_95 ( & V_100 -> V_158 ,
& V_100 -> V_173 ,
& V_15 -> V_165 ) ;
goto V_174;
}
} else {
if ( V_15 -> V_137 == V_169 )
F_96 ( V_15 , & V_100 -> V_170 ) ;
}
V_174:
V_100 -> V_175 = V_15 -> V_140 -> V_175 ;
V_100 -> V_176 = V_15 -> V_100 -> V_176 ;
if ( V_4 -> V_22 == V_156 ) {
V_100 -> V_177 = F_97 ( V_15 ) ;
if ( V_15 -> V_100 -> V_99 == V_178 ||
V_15 -> V_100 -> V_99 == V_179 ) {
V_100 -> V_180 = V_15 -> V_129 - V_100 -> V_177 ;
V_100 -> V_180 += V_15 -> V_180 ;
} else
V_100 -> V_180 = 0 ;
} else {
V_100 -> V_177 = F_98 ( V_15 ) ;
if ( V_15 -> V_100 -> V_99 == V_178 )
V_100 -> V_180 = V_100 -> V_177 + V_15 -> V_180 ;
else
V_100 -> V_180 = 0 ;
}
V_100 -> V_181 = V_15 -> V_181 ;
V_100 -> V_182 = V_15 -> V_182 ;
V_15 -> V_181 = 0 ;
V_15 -> V_182 = 0 ;
V_168:
F_16 ( V_4 ) ;
return 0 ;
}
static int F_99 ( struct V_3 * V_4 ,
struct F_92 T_1 * V_183 ,
bool V_184 )
{
struct F_92 V_100 ;
int V_185 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
if ( V_184 && F_100 ( V_100 . V_158 ,
( V_186 T_1 * ) ( & V_183 -> V_158 ) ) )
return - V_37 ;
V_185 = F_92 ( V_4 , & V_100 ) ;
if ( V_185 < 0 )
return V_185 ;
if ( F_26 ( V_183 , & V_100 , sizeof( V_100 ) ) )
return - V_37 ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 ,
struct F_101 * V_13 )
{
struct V_14 * V_15 ;
unsigned int V_187 ;
V_187 = V_13 -> V_187 ;
V_15 = V_4 -> V_15 ;
F_14 ( V_4 ) ;
if ( V_15 -> V_100 -> V_99 == V_115 ) {
F_16 ( V_4 ) ;
return - V_118 ;
}
F_16 ( V_4 ) ;
if ( V_187 >= V_15 -> V_127 )
return - V_59 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_187 = V_187 ;
return V_4 -> V_42 -> V_89 ( V_4 , V_188 , V_13 ) ;
}
static int F_102 ( struct V_3 * V_4 ,
struct F_101 T_1 * V_33 )
{
struct F_101 V_13 ;
int V_185 ;
if ( F_91 ( & V_13 , V_33 , sizeof( V_13 ) ) )
return - V_37 ;
V_185 = F_101 ( V_4 , & V_13 ) ;
if ( V_185 < 0 )
return V_185 ;
if ( F_26 ( V_33 , & V_13 , sizeof( V_13 ) ) )
return - V_37 ;
return 0 ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_189 == NULL )
return;
if ( V_15 -> V_189 == V_4 ) {
if ( ! V_15 -> V_190 )
F_96 ( V_15 , & V_15 -> V_104 ) ;
} else {
F_103 ( V_15 -> V_189 ) ;
V_15 -> V_104 = V_15 -> V_189 -> V_15 -> V_104 ;
}
V_15 -> V_189 = NULL ;
}
static int F_104 ( const struct V_191 * V_42 ,
struct V_3 * V_4 ,
int V_99 , int V_192 )
{
struct V_3 * V_193 = NULL ;
struct V_3 * V_194 ;
int V_185 = 0 , V_195 = 1 ;
F_105 (s, substream) {
if ( V_192 && V_193 != V_4 ) {
if ( V_193 -> V_5 -> V_6 )
F_106 ( & V_193 -> V_9 . V_10 , V_195 ) ;
else
F_107 ( & V_193 -> V_9 . V_2 , V_195 ) ;
V_195 ++ ;
}
V_185 = V_42 -> V_196 ( V_193 , V_99 ) ;
if ( V_185 < 0 )
goto V_197;
}
F_105 (s, substream) {
V_185 = V_42 -> V_198 ( V_193 , V_99 ) ;
if ( V_185 < 0 ) {
if ( V_42 -> V_199 ) {
F_105 (s1, substream) {
if ( V_194 == V_193 )
break;
V_42 -> V_199 ( V_194 , V_99 ) ;
}
}
V_193 = NULL ;
goto V_197;
}
}
F_105 (s, substream) {
V_42 -> V_200 ( V_193 , V_99 ) ;
}
V_197:
if ( V_192 ) {
F_105 (s1, substream) {
if ( V_194 != V_4 ) {
if ( V_194 -> V_5 -> V_6 )
F_10 ( & V_194 -> V_9 . V_10 ) ;
else
F_12 ( & V_194 -> V_9 . V_2 ) ;
}
if ( V_194 == V_193 )
break;
}
}
return V_185 ;
}
static int F_108 ( const struct V_191 * V_42 ,
struct V_3 * V_4 ,
int V_99 )
{
int V_185 ;
V_185 = V_42 -> V_196 ( V_4 , V_99 ) ;
if ( V_185 < 0 )
return V_185 ;
V_185 = V_42 -> V_198 ( V_4 , V_99 ) ;
if ( V_185 == 0 )
V_42 -> V_200 ( V_4 , V_99 ) ;
else if ( V_42 -> V_199 )
V_42 -> V_199 ( V_4 , V_99 ) ;
return V_185 ;
}
static int F_109 ( const struct V_191 * V_42 ,
struct V_3 * V_4 ,
int V_99 )
{
int V_185 ;
if ( ! F_110 ( V_4 ) )
return F_108 ( V_42 , V_4 , V_99 ) ;
if ( V_4 -> V_5 -> V_6 ) {
if ( ! F_111 ( & V_4 -> V_201 -> V_10 ) ) {
F_10 ( & V_4 -> V_9 . V_10 ) ;
F_6 ( & V_4 -> V_201 -> V_10 ) ;
F_6 ( & V_4 -> V_9 . V_10 ) ;
}
V_185 = F_104 ( V_42 , V_4 , V_99 , 1 ) ;
F_10 ( & V_4 -> V_201 -> V_10 ) ;
} else {
if ( ! F_112 ( & V_4 -> V_201 -> V_2 ) ) {
F_12 ( & V_4 -> V_9 . V_2 ) ;
F_8 ( & V_4 -> V_201 -> V_2 ) ;
F_8 ( & V_4 -> V_9 . V_2 ) ;
}
V_185 = F_104 ( V_42 , V_4 , V_99 , 1 ) ;
F_12 ( & V_4 -> V_201 -> V_2 ) ;
}
return V_185 ;
}
static int F_113 ( const struct V_191 * V_42 ,
struct V_3 * V_4 ,
int V_99 )
{
int V_185 ;
F_14 ( V_4 ) ;
V_185 = F_109 ( V_42 , V_4 , V_99 ) ;
F_16 ( V_4 ) ;
return V_185 ;
}
static int F_114 ( const struct V_191 * V_42 ,
struct V_3 * V_4 ,
int V_99 )
{
int V_185 ;
F_115 ( & V_7 ) ;
if ( F_110 ( V_4 ) )
V_185 = F_104 ( V_42 , V_4 , V_99 , 0 ) ;
else
V_185 = F_108 ( V_42 , V_4 , V_99 ) ;
F_11 ( & V_7 ) ;
return V_185 ;
}
static int F_116 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 != V_117 )
return - V_118 ;
if ( V_4 -> V_22 == V_156 &&
! F_117 ( V_4 ) )
return - V_202 ;
V_15 -> V_190 = false ;
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_118 ( struct V_3 * V_4 , int V_99 )
{
if ( V_4 -> V_15 -> V_189 != V_4 )
return 0 ;
return V_4 -> V_42 -> V_203 ( V_4 , V_204 ) ;
}
static void F_119 ( struct V_3 * V_4 , int V_99 )
{
if ( V_4 -> V_15 -> V_189 == V_4 )
V_4 -> V_42 -> V_203 ( V_4 , V_205 ) ;
}
static void F_120 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
F_103 ( V_4 ) ;
V_15 -> V_206 = V_207 ;
V_15 -> V_208 = ( V_15 -> V_129 * V_209 ) /
V_15 -> V_97 ;
V_15 -> V_100 -> V_99 = V_99 ;
if ( V_4 -> V_22 == V_156 &&
V_15 -> V_145 > 0 )
F_88 ( V_4 , V_157 ) ;
F_60 ( V_4 , V_210 ) ;
}
int F_121 ( struct V_3 * V_4 )
{
return F_109 ( & V_211 , V_4 ,
V_178 ) ;
}
static int F_122 ( struct V_3 * V_4 )
{
return F_113 ( & V_211 , V_4 ,
V_178 ) ;
}
static int F_123 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_124 ( struct V_3 * V_4 , int V_99 )
{
if ( V_4 -> V_15 -> V_189 == V_4 &&
F_87 ( V_4 ) )
V_4 -> V_42 -> V_203 ( V_4 , V_205 ) ;
return 0 ;
}
static void F_125 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 != V_99 ) {
F_103 ( V_4 ) ;
V_15 -> V_100 -> V_99 = V_99 ;
F_60 ( V_4 , V_212 ) ;
}
F_126 ( & V_15 -> V_213 ) ;
F_126 ( & V_15 -> V_214 ) ;
}
int F_127 ( struct V_3 * V_4 , T_3 V_99 )
{
return F_109 ( & V_215 , V_4 , V_99 ) ;
}
int F_128 ( struct V_3 * V_4 )
{
return F_108 ( & V_215 , V_4 ,
V_116 ) ;
}
int F_129 ( struct V_3 * V_4 )
{
unsigned long V_12 ;
int V_216 = 0 ;
F_130 ( V_4 , V_12 ) ;
if ( F_87 ( V_4 ) )
V_216 = F_127 ( V_4 , V_217 ) ;
F_20 ( V_4 , V_12 ) ;
return V_216 ;
}
static int F_131 ( struct V_3 * V_4 , int V_218 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_219 ) )
return - V_220 ;
if ( V_218 ) {
if ( V_15 -> V_100 -> V_99 != V_178 )
return - V_118 ;
} else if ( V_15 -> V_100 -> V_99 != V_221 )
return - V_118 ;
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_132 ( struct V_3 * V_4 , int V_218 )
{
if ( V_4 -> V_15 -> V_189 != V_4 )
return 0 ;
if ( V_218 )
F_94 ( V_4 ) ;
V_4 -> V_15 -> V_206 = V_207 - V_209 * 1000 ;
return V_4 -> V_42 -> V_203 ( V_4 ,
V_218 ? V_222 :
V_223 ) ;
}
static void F_133 ( struct V_3 * V_4 , int V_218 )
{
if ( V_4 -> V_15 -> V_189 == V_4 )
V_4 -> V_42 -> V_203 ( V_4 ,
V_218 ? V_223 :
V_222 ) ;
}
static void F_134 ( struct V_3 * V_4 , int V_218 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
F_103 ( V_4 ) ;
if ( V_218 ) {
V_15 -> V_100 -> V_99 = V_221 ;
F_60 ( V_4 , V_224 ) ;
F_126 ( & V_15 -> V_213 ) ;
F_126 ( & V_15 -> V_214 ) ;
} else {
V_15 -> V_100 -> V_99 = V_178 ;
F_60 ( V_4 , V_225 ) ;
}
}
static int F_135 ( struct V_3 * V_4 , int V_218 )
{
return F_109 ( & V_226 , V_4 , V_218 ) ;
}
static int F_136 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_227 )
return - V_228 ;
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_137 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_189 != V_4 )
return 0 ;
if ( ! F_87 ( V_4 ) )
return 0 ;
V_4 -> V_42 -> V_203 ( V_4 , V_229 ) ;
return 0 ;
}
static void F_138 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
F_103 ( V_4 ) ;
V_15 -> V_100 -> V_167 = V_15 -> V_100 -> V_99 ;
V_15 -> V_100 -> V_99 = V_227 ;
F_60 ( V_4 , V_230 ) ;
F_126 ( & V_15 -> V_213 ) ;
F_126 ( & V_15 -> V_214 ) ;
}
int F_139 ( struct V_3 * V_4 )
{
int V_34 ;
unsigned long V_12 ;
if ( ! V_4 )
return 0 ;
F_130 ( V_4 , V_12 ) ;
V_34 = F_109 ( & V_231 , V_4 , 0 ) ;
F_20 ( V_4 , V_12 ) ;
return V_34 ;
}
int F_140 ( struct V_16 * V_5 )
{
struct V_3 * V_4 ;
int V_22 , V_34 = 0 ;
if ( ! V_5 )
return 0 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
for ( V_4 = V_5 -> V_232 [ V_22 ] . V_4 ;
V_4 ; V_4 = V_4 -> V_233 ) {
if ( V_4 -> V_15 == NULL )
continue;
V_34 = F_139 ( V_4 ) ;
if ( V_34 < 0 && V_34 != - V_228 )
return V_34 ;
}
}
return 0 ;
}
static int F_141 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_234 ) )
return - V_220 ;
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_189 != V_4 )
return 0 ;
if ( V_15 -> V_100 -> V_167 != V_178 &&
( V_15 -> V_100 -> V_167 != V_179 ||
V_4 -> V_22 != V_156 ) )
return 0 ;
return V_4 -> V_42 -> V_203 ( V_4 , V_235 ) ;
}
static void F_143 ( struct V_3 * V_4 , int V_99 )
{
if ( V_4 -> V_15 -> V_189 == V_4 &&
F_87 ( V_4 ) )
V_4 -> V_42 -> V_203 ( V_4 , V_229 ) ;
}
static void F_144 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
F_103 ( V_4 ) ;
V_15 -> V_100 -> V_99 = V_15 -> V_100 -> V_167 ;
F_60 ( V_4 , V_236 ) ;
}
static int F_145 ( struct V_3 * V_4 )
{
return F_113 ( & V_237 , V_4 , 0 ) ;
}
static int F_145 ( struct V_3 * V_4 )
{
return - V_220 ;
}
static int F_146 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_151 ;
F_14 ( V_4 ) ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_217 :
V_151 = 0 ;
break;
case V_178 :
V_151 = F_127 ( V_4 , V_217 ) ;
break;
default:
V_151 = - V_118 ;
}
F_16 ( V_4 ) ;
return V_151 ;
}
static int F_147 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_178 :
case V_117 :
case V_221 :
case V_227 :
return 0 ;
default:
return - V_118 ;
}
}
static int F_148 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_34 = V_4 -> V_42 -> V_89 ( V_4 , V_238 , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
V_15 -> V_239 = 0 ;
V_15 -> V_240 = V_15 -> V_100 -> V_176 -
V_15 -> V_100 -> V_176 % V_15 -> V_98 ;
V_15 -> V_241 = V_15 -> V_100 -> V_176 ;
V_15 -> V_242 = 0 ;
return 0 ;
}
static void F_149 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
V_15 -> V_140 -> V_175 = V_15 -> V_100 -> V_176 ;
if ( V_4 -> V_22 == V_156 &&
V_15 -> V_145 > 0 )
F_88 ( V_4 , V_157 ) ;
}
static int F_150 ( struct V_3 * V_4 )
{
return F_114 ( & V_243 , V_4 , 0 ) ;
}
static int F_151 ( struct V_3 * V_4 ,
int V_244 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 ||
V_15 -> V_100 -> V_99 == V_101 )
return - V_118 ;
if ( F_87 ( V_4 ) )
return - V_228 ;
V_4 -> V_244 = V_244 ;
return 0 ;
}
static int F_152 ( struct V_3 * V_4 , int V_99 )
{
int V_34 ;
V_34 = V_4 -> V_42 -> V_245 ( V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
return F_148 ( V_4 , 0 ) ;
}
static void F_153 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
V_15 -> V_140 -> V_175 = V_15 -> V_100 -> V_176 ;
F_59 ( V_4 , V_117 ) ;
}
static int F_154 ( struct V_3 * V_4 ,
struct V_246 * V_246 )
{
int V_244 ;
if ( V_246 )
V_244 = V_246 -> V_244 ;
else
V_244 = V_4 -> V_244 ;
F_14 ( V_4 ) ;
switch ( V_4 -> V_15 -> V_100 -> V_99 ) {
case V_221 :
F_135 ( V_4 , 0 ) ;
case V_227 :
F_127 ( V_4 , V_116 ) ;
break;
}
F_16 ( V_4 ) ;
return F_114 ( & V_247 ,
V_4 , V_244 ) ;
}
static int F_155 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_115 :
case V_101 :
case V_227 :
return - V_118 ;
}
V_15 -> V_189 = V_4 ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 , int V_99 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_4 -> V_22 == V_156 ) {
switch ( V_15 -> V_100 -> V_99 ) {
case V_117 :
if ( ! F_157 ( V_4 ) ) {
F_118 ( V_4 , V_179 ) ;
F_120 ( V_4 , V_179 ) ;
} else {
V_15 -> V_100 -> V_99 = V_116 ;
}
break;
case V_178 :
V_15 -> V_100 -> V_99 = V_179 ;
break;
case V_217 :
V_15 -> V_100 -> V_99 = V_116 ;
break;
default:
break;
}
} else {
if ( V_15 -> V_100 -> V_99 == V_178 ) {
int V_248 = F_98 ( V_15 ) > 0 ?
V_179 : V_116 ;
F_124 ( V_4 , V_248 ) ;
F_125 ( V_4 , V_248 ) ;
}
}
if ( V_15 -> V_100 -> V_99 == V_179 &&
V_15 -> V_189 == V_4 &&
( V_15 -> V_38 . V_13 & V_92 ) )
return V_4 -> V_42 -> V_203 ( V_4 ,
V_249 ) ;
return 0 ;
}
static void F_158 ( struct V_3 * V_4 , int V_99 )
{
}
static int F_159 ( struct V_3 * V_4 ,
struct V_246 * V_246 )
{
struct V_250 * V_19 ;
struct V_14 * V_15 ;
struct V_3 * V_193 ;
T_4 V_251 ;
int V_151 = 0 ;
int V_252 = 0 ;
V_19 = V_4 -> V_5 -> V_19 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( V_246 ) {
if ( V_246 -> V_244 & V_253 )
V_252 = 1 ;
} else if ( V_4 -> V_244 & V_253 )
V_252 = 1 ;
F_115 ( & V_7 ) ;
F_14 ( V_4 ) ;
if ( V_15 -> V_100 -> V_99 == V_221 )
F_135 ( V_4 , 0 ) ;
V_151 = F_109 ( & V_254 , V_4 , 0 ) ;
if ( V_151 < 0 )
goto V_255;
if ( V_252 ) {
V_151 = - V_256 ;
goto V_255;
}
for (; ; ) {
long V_257 ;
struct V_14 * V_258 ;
if ( F_160 ( V_259 ) ) {
V_151 = - V_260 ;
break;
}
V_258 = NULL ;
F_105 (s, substream) {
if ( V_193 -> V_22 != V_156 )
continue;
V_15 = V_193 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_179 ) {
V_258 = V_15 ;
break;
}
}
if ( ! V_258 )
break;
F_161 ( & V_251 , V_259 ) ;
F_162 ( & V_258 -> V_213 , & V_251 ) ;
F_16 ( V_4 ) ;
F_11 ( & V_7 ) ;
F_163 ( V_19 ) ;
if ( V_15 -> V_130 )
V_257 = V_261 ;
else {
V_257 = 10 ;
if ( V_15 -> V_97 ) {
long V_262 = V_15 -> V_98 * 2 / V_15 -> V_97 ;
V_257 = F_164 ( V_262 , V_257 ) ;
}
V_257 = F_165 ( V_257 * 1000 ) ;
}
V_257 = F_166 ( V_257 ) ;
F_167 ( V_19 ) ;
F_115 ( & V_7 ) ;
F_14 ( V_4 ) ;
F_168 ( & V_258 -> V_213 , & V_251 ) ;
if ( V_19 -> V_263 ) {
V_151 = - V_264 ;
break;
}
if ( V_257 == 0 ) {
if ( V_4 -> V_15 -> V_100 -> V_99 == V_227 )
V_151 = - V_265 ;
else {
F_169 ( V_4 -> V_5 -> V_19 -> V_45 ,
L_1 ) ;
F_127 ( V_4 , V_116 ) ;
V_151 = - V_266 ;
}
break;
}
}
V_255:
F_16 ( V_4 ) ;
F_11 ( & V_7 ) ;
return V_151 ;
}
static int F_170 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
int V_151 = 0 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 ||
V_15 -> V_100 -> V_99 == V_101 )
return - V_118 ;
F_14 ( V_4 ) ;
if ( V_15 -> V_100 -> V_99 == V_221 )
F_135 ( V_4 , 0 ) ;
F_127 ( V_4 , V_116 ) ;
F_16 ( V_4 ) ;
return V_151 ;
}
static bool F_171 ( struct V_246 * V_246 )
{
struct V_267 * V_267 = F_172 ( V_246 ) ;
unsigned int V_268 ;
if ( ! F_173 ( V_267 -> V_269 ) || F_174 ( V_267 ) != V_270 )
return false ;
V_268 = F_175 ( V_267 ) ;
return F_176 ( V_268 , V_271 ) ||
F_176 ( V_268 , V_272 ) ;
}
static int F_177 ( struct V_3 * V_4 , int V_273 )
{
int V_185 = 0 ;
struct V_274 * V_275 ;
struct V_3 * V_276 ;
struct V_277 * V_201 ;
struct V_273 V_278 = F_178 ( V_273 ) ;
if ( ! V_278 . V_246 )
return - V_118 ;
if ( ! F_171 ( V_278 . V_246 ) ) {
V_185 = - V_118 ;
goto V_279;
}
V_275 = V_278 . V_246 -> V_280 ;
V_276 = V_275 -> V_4 ;
V_201 = F_25 ( sizeof( * V_201 ) , V_35 ) ;
if ( ! V_201 ) {
V_185 = - V_36 ;
goto V_281;
}
F_1 ( & V_7 ) ;
F_179 ( & V_11 ) ;
if ( V_4 -> V_15 -> V_100 -> V_99 == V_115 ||
V_4 -> V_15 -> V_100 -> V_99 != V_276 -> V_15 -> V_100 -> V_99 ||
V_4 -> V_5 -> V_6 != V_276 -> V_5 -> V_6 ) {
V_185 = - V_118 ;
goto V_168;
}
if ( F_110 ( V_276 ) ) {
V_185 = - V_282 ;
goto V_168;
}
if ( ! F_110 ( V_4 ) ) {
V_4 -> V_201 = V_201 ;
V_201 = NULL ;
F_180 ( & V_4 -> V_201 -> V_2 ) ;
F_181 ( & V_4 -> V_201 -> V_10 ) ;
F_182 ( & V_4 -> V_201 -> V_283 ) ;
F_183 ( & V_4 -> V_284 , & V_4 -> V_201 -> V_283 ) ;
V_4 -> V_201 -> V_285 = 1 ;
}
F_183 ( & V_276 -> V_284 , & V_4 -> V_201 -> V_283 ) ;
V_4 -> V_201 -> V_285 ++ ;
V_276 -> V_201 = V_4 -> V_201 ;
V_168:
F_184 ( & V_11 ) ;
F_185 ( & V_7 ) ;
V_281:
F_186 ( V_276 -> V_5 -> V_19 ) ;
F_27 ( V_201 ) ;
V_279:
F_187 ( V_278 ) ;
return V_185 ;
}
static void F_188 ( struct V_3 * V_4 )
{
V_4 -> V_201 = & V_4 -> V_9 ;
F_182 ( & V_4 -> V_9 . V_283 ) ;
F_183 ( & V_4 -> V_284 , & V_4 -> V_9 . V_283 ) ;
}
static int F_189 ( struct V_3 * V_4 )
{
struct V_3 * V_193 ;
int V_185 = 0 ;
F_1 ( & V_7 ) ;
F_179 ( & V_11 ) ;
if ( ! F_110 ( V_4 ) ) {
V_185 = - V_282 ;
goto V_168;
}
F_190 ( & V_4 -> V_284 ) ;
V_4 -> V_201 -> V_285 -- ;
if ( V_4 -> V_201 -> V_285 == 1 ) {
F_105 (s, substream) {
F_188 ( V_193 ) ;
break;
}
F_27 ( V_4 -> V_201 ) ;
}
F_188 ( V_4 ) ;
V_168:
F_184 ( & V_11 ) ;
F_185 ( & V_7 ) ;
return V_185 ;
}
static int F_191 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
F_192 ( F_48 ( V_48 , V_286 -> V_78 [ 0 ] ) ,
F_48 ( V_48 , V_286 -> V_78 [ 1 ] ) , & V_262 ) ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
static int F_193 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
F_194 ( F_48 ( V_48 , V_286 -> V_78 [ 0 ] ) ,
F_48 ( V_48 , V_286 -> V_78 [ 1 ] ) , & V_262 ) ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
static int F_195 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
F_196 ( F_48 ( V_48 , V_286 -> V_78 [ 0 ] ) ,
F_48 ( V_48 , V_286 -> V_78 [ 1 ] ) ,
( unsigned long ) V_286 -> V_287 , & V_262 ) ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
static int F_197 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
F_198 ( F_48 ( V_48 , V_286 -> V_78 [ 0 ] ) ,
( unsigned long ) V_286 -> V_287 ,
F_48 ( V_48 , V_286 -> V_78 [ 1 ] ) , & V_262 ) ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
static int F_199 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
unsigned int V_54 ;
const struct V_62 * V_63 =
F_48 ( V_48 , V_286 -> V_78 [ 0 ] ) ;
struct V_52 V_53 ;
struct V_52 * V_288 = F_31 ( V_48 , V_87 ) ;
F_200 ( & V_53 ) ;
for ( V_54 = 0 ; V_54 <= V_289 ; ++ V_54 ) {
int V_112 ;
if ( ! F_201 ( V_288 , V_54 ) )
continue;
V_112 = F_78 ( V_54 ) ;
if ( V_112 <= 0 )
continue;
if ( ( unsigned ) V_112 < V_63 -> V_290 || ( unsigned ) V_112 > V_63 -> F_164 )
F_202 ( & V_53 , V_54 ) ;
}
return F_34 ( V_288 , & V_53 ) ;
}
static int F_203 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
unsigned int V_54 ;
V_262 . V_290 = V_291 ;
V_262 . F_164 = 0 ;
V_262 . V_292 = 0 ;
V_262 . V_293 = 0 ;
for ( V_54 = 0 ; V_54 <= V_289 ; ++ V_54 ) {
int V_112 ;
if ( ! F_201 ( F_31 ( V_48 , V_87 ) , V_54 ) )
continue;
V_112 = F_78 ( V_54 ) ;
if ( V_112 <= 0 )
continue;
if ( V_262 . V_290 > ( unsigned ) V_112 )
V_262 . V_290 = V_112 ;
if ( V_262 . F_164 < ( unsigned ) V_112 )
V_262 . F_164 = V_112 ;
}
V_262 . integer = 1 ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
static int F_204 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_294 * V_38 = V_286 -> V_287 ;
return F_205 ( F_38 ( V_48 , V_286 -> V_79 ) ,
V_295 . V_285 ,
V_295 . V_296 , V_38 -> V_297 ) ;
}
static int F_206 ( struct V_47 * V_48 ,
struct V_71 * V_286 )
{
struct V_62 V_262 ;
struct V_3 * V_4 = V_286 -> V_287 ;
V_262 . V_290 = 0 ;
V_262 . F_164 = V_4 -> V_298 ;
V_262 . V_292 = 0 ;
V_262 . V_293 = 0 ;
V_262 . integer = 1 ;
return F_41 ( F_38 ( V_48 , V_286 -> V_79 ) , & V_262 ) ;
}
int F_207 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_49 * V_50 = & V_15 -> V_51 ;
int V_54 , V_34 ;
for ( V_54 = V_57 ; V_54 <= V_58 ; V_54 ++ ) {
F_200 ( F_35 ( V_50 , V_54 ) ) ;
}
for ( V_54 = V_65 ; V_54 <= V_66 ; V_54 ++ ) {
F_208 ( F_42 ( V_50 , V_54 ) ) ;
}
F_209 ( F_42 ( V_50 , V_88 ) ) ;
F_209 ( F_42 ( V_50 , V_109 ) ) ;
F_209 ( F_42 ( V_50 , V_299 ) ) ;
F_209 ( F_42 ( V_50 , V_82 ) ) ;
F_209 ( F_42 ( V_50 , V_300 ) ) ;
V_34 = F_210 ( V_15 , 0 , V_87 ,
F_199 , NULL ,
V_82 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_82 ,
F_203 , NULL ,
V_87 ,
V_82 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_82 ,
F_193 , NULL ,
V_300 , V_88 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_300 ,
F_191 , NULL ,
V_82 , V_88 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_300 ,
F_197 , ( void * ) 8 ,
V_301 , V_302 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_300 ,
F_197 , ( void * ) 8 ,
V_299 , V_109 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_88 ,
F_193 , NULL ,
V_300 , V_82 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_84 ,
F_197 , ( void * ) 1000000 ,
V_302 , V_108 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_84 ,
F_197 , ( void * ) 1000000 ,
V_109 , V_303 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_304 ,
F_193 , NULL ,
V_109 , V_302 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_302 ,
F_193 , NULL ,
V_109 , V_304 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_302 ,
F_197 , ( void * ) 8 ,
V_301 , V_300 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_302 ,
F_195 , ( void * ) 1000000 ,
V_108 , V_84 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_109 ,
F_191 , NULL ,
V_302 , V_304 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_109 ,
F_197 , ( void * ) 8 ,
V_299 , V_300 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_109 ,
F_195 , ( void * ) 1000000 ,
V_303 , V_84 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_301 ,
F_195 , ( void * ) 8 ,
V_302 , V_300 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_299 ,
F_195 , ( void * ) 8 ,
V_109 , V_300 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_108 ,
F_197 , ( void * ) 1000000 ,
V_302 , V_84 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_303 ,
F_197 , ( void * ) 1000000 ,
V_109 , V_84 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
return 0 ;
}
int F_211 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_294 * V_38 = & V_15 -> V_38 ;
int V_34 ;
unsigned int V_288 = 0 ;
if ( V_38 -> V_13 & V_305 )
V_288 |= 1 << V_306 ;
if ( V_38 -> V_13 & V_307 )
V_288 |= 1 << V_308 ;
if ( F_28 ( V_4 ) ) {
if ( V_38 -> V_13 & V_305 )
V_288 |= 1 << V_309 ;
if ( V_38 -> V_13 & V_307 )
V_288 |= 1 << V_310 ;
if ( V_38 -> V_13 & V_311 )
V_288 |= 1 << V_312 ;
}
V_34 = F_212 ( V_15 , V_106 , V_288 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_213 ( V_15 , V_87 , V_38 -> V_313 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_212 ( V_15 , V_107 , 1 << V_314 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_214 ( V_15 , V_88 ,
V_38 -> V_315 , V_38 -> V_316 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_214 ( V_15 , V_84 ,
V_38 -> V_317 , V_38 -> V_318 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_214 ( V_15 , V_301 ,
V_38 -> V_319 , V_38 -> V_320 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_214 ( V_15 , V_304 ,
V_38 -> V_321 , V_38 -> V_322 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_214 ( V_15 , V_299 ,
V_38 -> V_319 , V_38 -> V_298 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_210 ( V_15 , 0 , V_299 ,
F_206 , V_4 ,
V_299 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_15 -> V_323 ) {
V_34 = F_214 ( V_15 , V_299 , 0 , V_15 -> V_323 ) ;
if ( V_34 < 0 )
return V_34 ;
}
if ( ! ( V_38 -> V_297 & ( V_324 | V_325 ) ) ) {
V_34 = F_210 ( V_15 , 0 , V_84 ,
F_204 , V_38 ,
V_84 , - 1 ) ;
if ( V_34 < 0 )
return V_34 ;
}
F_215 ( V_15 , V_302 ) ;
return 0 ;
}
static void F_216 ( struct V_3 * V_4 )
{
F_189 ( V_4 ) ;
}
void F_217 ( struct V_3 * V_4 )
{
V_4 -> V_326 -- ;
if ( V_4 -> V_326 > 0 )
return;
F_170 ( V_4 ) ;
if ( V_4 -> V_327 ) {
if ( V_4 -> V_42 -> V_150 &&
V_4 -> V_15 -> V_100 -> V_99 != V_115 )
V_4 -> V_42 -> V_150 ( V_4 ) ;
V_4 -> V_42 -> V_328 ( V_4 ) ;
V_4 -> V_327 = 0 ;
}
if ( F_80 ( & V_4 -> V_148 ) )
F_81 ( & V_4 -> V_148 ) ;
if ( V_4 -> V_329 ) {
V_4 -> V_329 ( V_4 ) ;
V_4 -> V_329 = NULL ;
}
F_218 ( V_4 ) ;
}
int F_219 ( struct V_16 * V_5 , int V_22 ,
struct V_246 * V_246 ,
struct V_3 * * V_330 )
{
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_220 ( V_5 , V_22 , V_246 , & V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_4 -> V_326 > 1 ) {
* V_330 = V_4 ;
return 0 ;
}
V_34 = F_207 ( V_4 ) ;
if ( V_34 < 0 ) {
F_221 ( V_5 , L_2 ) ;
goto error;
}
if ( ( V_34 = V_4 -> V_42 -> V_331 ( V_4 ) ) < 0 )
goto error;
V_4 -> V_327 = 1 ;
V_34 = F_211 ( V_4 ) ;
if ( V_34 < 0 ) {
F_221 ( V_5 , L_3 ) ;
goto error;
}
* V_330 = V_4 ;
return 0 ;
error:
F_217 ( V_4 ) ;
return V_34 ;
}
static int F_222 ( struct V_246 * V_246 ,
struct V_16 * V_5 ,
int V_22 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_219 ( V_5 , V_22 , V_246 , & V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
V_275 = F_223 ( sizeof( * V_275 ) , V_35 ) ;
if ( V_275 == NULL ) {
F_217 ( V_4 ) ;
return - V_36 ;
}
V_275 -> V_4 = V_4 ;
if ( V_4 -> V_326 == 1 ) {
V_4 -> V_246 = V_275 ;
V_4 -> V_329 = F_216 ;
}
V_246 -> V_280 = V_275 ;
return 0 ;
}
static int F_224 ( struct V_267 * V_267 , struct V_246 * V_246 )
{
struct V_16 * V_5 ;
int V_34 = F_225 ( V_267 , V_246 ) ;
if ( V_34 < 0 )
return V_34 ;
V_5 = F_176 ( F_175 ( V_267 ) ,
V_271 ) ;
V_34 = F_226 ( V_246 , V_5 , V_156 ) ;
if ( V_5 )
F_186 ( V_5 -> V_19 ) ;
return V_34 ;
}
static int F_227 ( struct V_267 * V_267 , struct V_246 * V_246 )
{
struct V_16 * V_5 ;
int V_34 = F_225 ( V_267 , V_246 ) ;
if ( V_34 < 0 )
return V_34 ;
V_5 = F_176 ( F_175 ( V_267 ) ,
V_272 ) ;
V_34 = F_226 ( V_246 , V_5 , V_332 ) ;
if ( V_5 )
F_186 ( V_5 -> V_19 ) ;
return V_34 ;
}
static int F_226 ( struct V_246 * V_246 , struct V_16 * V_5 , int V_22 )
{
int V_34 ;
T_4 V_251 ;
if ( V_5 == NULL ) {
V_34 = - V_264 ;
goto V_333;
}
V_34 = F_228 ( V_5 -> V_19 , V_246 ) ;
if ( V_34 < 0 )
goto V_333;
if ( ! F_229 ( V_5 -> V_19 -> V_334 ) ) {
V_34 = - V_37 ;
goto V_335;
}
F_161 ( & V_251 , V_259 ) ;
F_162 ( & V_5 -> V_336 , & V_251 ) ;
F_6 ( & V_5 -> V_337 ) ;
while ( 1 ) {
V_34 = F_222 ( V_246 , V_5 , V_22 ) ;
if ( V_34 >= 0 )
break;
if ( V_34 == - V_256 ) {
if ( V_246 -> V_244 & V_253 ) {
V_34 = - V_228 ;
break;
}
} else
break;
F_230 ( V_338 ) ;
F_10 ( & V_5 -> V_337 ) ;
F_231 () ;
F_6 ( & V_5 -> V_337 ) ;
if ( V_5 -> V_19 -> V_263 ) {
V_34 = - V_264 ;
break;
}
if ( F_160 ( V_259 ) ) {
V_34 = - V_260 ;
break;
}
}
F_168 ( & V_5 -> V_336 , & V_251 ) ;
F_10 ( & V_5 -> V_337 ) ;
if ( V_34 < 0 )
goto V_339;
return V_34 ;
V_339:
F_232 ( V_5 -> V_19 -> V_334 ) ;
V_335:
F_233 ( V_5 -> V_19 , V_246 ) ;
V_333:
return V_34 ;
}
static int F_234 ( struct V_267 * V_267 , struct V_246 * V_246 )
{
struct V_16 * V_5 ;
struct V_3 * V_4 ;
struct V_274 * V_275 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_66 ( ! V_4 ) )
return - V_114 ;
V_5 = V_4 -> V_5 ;
F_6 ( & V_5 -> V_337 ) ;
F_217 ( V_4 ) ;
F_27 ( V_275 ) ;
F_10 ( & V_5 -> V_337 ) ;
F_126 ( & V_5 -> V_336 ) ;
F_232 ( V_5 -> V_19 -> V_334 ) ;
F_233 ( V_5 -> V_19 , V_246 ) ;
return 0 ;
}
static int F_235 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_15 -> V_100 -> V_99 ) {
case V_179 :
if ( V_4 -> V_22 == V_332 )
return - V_118 ;
case V_178 :
return F_94 ( V_4 ) ;
case V_117 :
case V_221 :
return 0 ;
case V_227 :
return - V_265 ;
case V_217 :
return - V_202 ;
default:
return - V_118 ;
}
}
static T_5 F_236 ( struct V_3 * V_4 ,
T_2 V_113 ,
T_5 V_177 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_175 ;
int V_216 ;
if ( V_177 <= 0 )
return 0 ;
if ( V_113 > ( T_2 ) V_177 )
V_113 = V_177 ;
V_175 = V_15 -> V_140 -> V_175 + V_113 ;
if ( V_175 >= ( T_5 ) V_15 -> V_146 )
V_175 -= V_15 -> V_146 ;
V_216 = F_237 ( V_4 , V_175 ) ;
return V_216 < 0 ? V_216 : V_113 ;
}
static T_5 F_238 ( struct V_3 * V_4 ,
T_2 V_113 ,
T_5 V_177 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_175 ;
int V_216 ;
if ( V_177 <= 0 )
return 0 ;
if ( V_113 > ( T_2 ) V_177 )
V_113 = V_177 ;
V_175 = V_15 -> V_140 -> V_175 - V_113 ;
if ( V_175 < 0 )
V_175 += V_15 -> V_146 ;
V_216 = F_237 ( V_4 , V_175 ) ;
return V_216 < 0 ? V_216 : V_113 ;
}
static T_5 F_239 ( struct V_3 * V_4 ,
T_2 V_113 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_216 ;
if ( V_113 == 0 )
return 0 ;
F_14 ( V_4 ) ;
V_216 = F_235 ( V_4 ) ;
if ( ! V_216 )
V_216 = F_238 ( V_4 , V_113 ,
F_240 ( V_15 ) ) ;
F_16 ( V_4 ) ;
return V_216 ;
}
static T_5 F_241 ( struct V_3 * V_4 ,
T_2 V_113 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_216 ;
if ( V_113 == 0 )
return 0 ;
F_14 ( V_4 ) ;
V_216 = F_235 ( V_4 ) ;
if ( ! V_216 )
V_216 = F_238 ( V_4 , V_113 ,
F_242 ( V_15 ) ) ;
F_16 ( V_4 ) ;
return V_216 ;
}
static T_5 F_243 ( struct V_3 * V_4 ,
T_2 V_113 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_216 ;
if ( V_113 == 0 )
return 0 ;
F_14 ( V_4 ) ;
V_216 = F_235 ( V_4 ) ;
if ( ! V_216 )
V_216 = F_236 ( V_4 , V_113 ,
F_97 ( V_15 ) ) ;
F_16 ( V_4 ) ;
return V_216 ;
}
static T_5 F_244 ( struct V_3 * V_4 ,
T_2 V_113 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_216 ;
if ( V_113 == 0 )
return 0 ;
F_14 ( V_4 ) ;
V_216 = F_235 ( V_4 ) ;
if ( ! V_216 )
V_216 = F_236 ( V_4 , V_113 ,
F_98 ( V_15 ) ) ;
F_16 ( V_4 ) ;
return V_216 ;
}
static int F_245 ( struct V_3 * V_4 )
{
int V_34 ;
F_14 ( V_4 ) ;
V_34 = F_235 ( V_4 ) ;
F_16 ( V_4 ) ;
return V_34 ;
}
static T_5 F_246 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_34 ;
T_5 V_340 = 0 ;
F_14 ( V_4 ) ;
V_34 = F_235 ( V_4 ) ;
if ( ! V_34 ) {
if ( V_4 -> V_22 == V_156 )
V_340 = F_240 ( V_15 ) ;
else
V_340 = F_98 ( V_15 ) ;
V_340 += V_15 -> V_180 ;
}
F_16 ( V_4 ) ;
return V_34 < 0 ? V_34 : V_340 ;
}
static int F_247 ( struct V_3 * V_4 ,
struct F_247 T_1 * V_341 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct F_247 V_342 ;
volatile struct V_343 * V_100 ;
volatile struct V_344 * V_140 ;
int V_34 ;
memset ( & V_342 , 0 , sizeof( V_342 ) ) ;
if ( F_100 ( V_342 . V_12 , ( unsigned T_1 * ) & ( V_341 -> V_12 ) ) )
return - V_37 ;
if ( F_91 ( & V_342 . V_345 . V_140 , & ( V_341 -> V_345 . V_140 ) , sizeof( struct V_344 ) ) )
return - V_37 ;
V_100 = V_15 -> V_100 ;
V_140 = V_15 -> V_140 ;
if ( V_342 . V_12 & V_346 ) {
V_34 = F_245 ( V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
}
F_14 ( V_4 ) ;
if ( ! ( V_342 . V_12 & V_347 ) ) {
V_34 = F_237 ( V_4 ,
V_342 . V_345 . V_140 . V_175 ) ;
if ( V_34 < 0 ) {
F_16 ( V_4 ) ;
return V_34 ;
}
} else {
V_342 . V_345 . V_140 . V_175 = V_140 -> V_175 ;
}
if ( ! ( V_342 . V_12 & V_348 ) )
V_140 -> V_141 = V_342 . V_345 . V_140 . V_141 ;
else
V_342 . V_345 . V_140 . V_141 = V_140 -> V_141 ;
V_342 . V_193 . V_100 . V_99 = V_100 -> V_99 ;
V_342 . V_193 . V_100 . V_176 = V_100 -> V_176 ;
V_342 . V_193 . V_100 . V_170 = V_100 -> V_170 ;
V_342 . V_193 . V_100 . V_167 = V_100 -> V_167 ;
F_16 ( V_4 ) ;
if ( F_26 ( V_341 , & V_342 , sizeof( V_342 ) ) )
return - V_37 ;
return 0 ;
}
static int F_248 ( struct V_3 * V_4 , int T_1 * V_349 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_350 ;
if ( F_100 ( V_350 , V_349 ) )
return - V_37 ;
if ( V_350 < 0 || V_350 > V_155 )
return - V_59 ;
V_15 -> V_154 = V_350 ;
return 0 ;
}
static int F_249 ( struct V_246 * V_246 ,
struct V_3 * V_4 ,
unsigned int V_351 , void T_1 * V_350 )
{
struct V_274 * V_275 = V_246 -> V_280 ;
switch ( V_351 ) {
case V_352 :
return F_250 ( V_353 , ( int T_1 * ) V_350 ) ? - V_37 : 0 ;
case V_354 :
return F_24 ( V_4 , V_350 ) ;
case V_355 :
return 0 ;
case V_356 :
return F_248 ( V_4 , V_350 ) ;
case V_357 :
if ( F_100 ( V_275 -> V_358 ,
( unsigned int T_1 * ) V_350 ) )
return - V_37 ;
return 0 ;
case V_359 :
return F_54 ( V_4 , V_350 ) ;
case V_360 :
return F_83 ( V_4 , V_350 ) ;
case V_361 :
return F_84 ( V_4 ) ;
case V_362 :
return F_90 ( V_4 , V_350 ) ;
case V_363 :
return F_99 ( V_4 , V_350 , false ) ;
case V_364 :
return F_99 ( V_4 , V_350 , true ) ;
case V_365 :
return F_102 ( V_4 , V_350 ) ;
case V_366 :
return F_154 ( V_4 , V_246 ) ;
case V_367 :
return F_150 ( V_4 ) ;
case V_368 :
return F_122 ( V_4 ) ;
case V_369 :
return F_177 ( V_4 , ( int ) ( unsigned long ) V_350 ) ;
case V_370 :
return F_189 ( V_4 ) ;
case V_371 :
return F_145 ( V_4 ) ;
case V_372 :
return F_146 ( V_4 ) ;
case V_373 :
return F_245 ( V_4 ) ;
case V_374 :
{
T_5 V_180 = F_246 ( V_4 ) ;
T_5 T_1 * V_185 = V_350 ;
if ( V_180 < 0 )
return V_180 ;
if ( F_250 ( V_180 , V_185 ) )
return - V_37 ;
return 0 ;
}
case V_375 :
return F_247 ( V_4 , V_350 ) ;
#ifdef F_251
case V_376 :
return F_252 ( V_4 , V_350 ) ;
case V_377 :
return F_253 ( V_4 , V_350 ) ;
#endif
case V_378 :
return F_159 ( V_4 , V_246 ) ;
case V_379 :
return F_170 ( V_4 ) ;
case V_380 :
return F_113 ( & V_226 ,
V_4 ,
( int ) ( unsigned long ) V_350 ) ;
}
F_221 ( V_4 -> V_5 , L_4 , V_351 ) ;
return - V_381 ;
}
static int F_254 ( struct V_246 * V_246 ,
struct V_3 * V_4 ,
unsigned int V_351 , void T_1 * V_350 )
{
struct V_250 * V_19 = V_4 -> V_5 -> V_19 ;
int V_185 ;
F_167 ( V_19 ) ;
V_185 = F_255 ( V_19 , V_382 ) ;
if ( V_185 >= 0 )
V_185 = F_249 ( V_246 , V_4 , V_351 , V_350 ) ;
F_163 ( V_19 ) ;
return V_185 ;
}
static int F_256 ( struct V_246 * V_246 ,
struct V_3 * V_4 ,
unsigned int V_351 , void T_1 * V_350 )
{
if ( F_67 ( V_4 ) )
return - V_114 ;
if ( F_66 ( V_4 -> V_22 != V_156 ) )
return - V_59 ;
switch ( V_351 ) {
case V_383 :
{
struct V_384 V_385 ;
struct V_384 T_1 * V_386 = V_350 ;
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_151 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( F_250 ( 0 , & V_386 -> V_151 ) )
return - V_37 ;
if ( F_91 ( & V_385 , V_386 , sizeof( V_385 ) ) )
return - V_37 ;
V_151 = F_257 ( V_4 , V_385 . V_387 , V_385 . V_113 ) ;
F_258 ( V_151 , & V_386 -> V_151 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_388 :
{
struct V_389 V_390 ;
struct V_389 T_1 * V_391 = V_350 ;
struct V_14 * V_15 = V_4 -> V_15 ;
void T_1 * * V_392 ;
T_5 V_151 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( V_15 -> V_127 > 128 )
return - V_59 ;
if ( F_250 ( 0 , & V_391 -> V_151 ) )
return - V_37 ;
if ( F_91 ( & V_390 , V_391 , sizeof( V_390 ) ) )
return - V_37 ;
V_392 = F_55 ( V_390 . V_392 ,
sizeof( void * ) * V_15 -> V_127 ) ;
if ( F_56 ( V_392 ) )
return F_57 ( V_392 ) ;
V_151 = F_259 ( V_4 , V_392 , V_390 . V_113 ) ;
F_27 ( V_392 ) ;
F_258 ( V_151 , & V_391 -> V_151 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_393 :
{
T_2 V_113 ;
T_2 T_1 * V_394 = V_350 ;
T_5 V_151 ;
if ( F_100 ( V_113 , V_394 ) )
return - V_37 ;
if ( F_250 ( 0 , V_394 ) )
return - V_37 ;
V_151 = F_239 ( V_4 , V_113 ) ;
F_258 ( V_151 , V_394 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_395 :
{
T_2 V_113 ;
T_2 T_1 * V_394 = V_350 ;
T_5 V_151 ;
if ( F_100 ( V_113 , V_394 ) )
return - V_37 ;
if ( F_250 ( 0 , V_394 ) )
return - V_37 ;
V_151 = F_243 ( V_4 , V_113 ) ;
F_258 ( V_151 , V_394 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
}
return F_254 ( V_246 , V_4 , V_351 , V_350 ) ;
}
static int F_260 ( struct V_246 * V_246 ,
struct V_3 * V_4 ,
unsigned int V_351 , void T_1 * V_350 )
{
if ( F_67 ( V_4 ) )
return - V_114 ;
if ( F_66 ( V_4 -> V_22 != V_332 ) )
return - V_59 ;
switch ( V_351 ) {
case V_396 :
{
struct V_384 V_385 ;
struct V_384 T_1 * V_386 = V_350 ;
struct V_14 * V_15 = V_4 -> V_15 ;
T_5 V_151 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( F_250 ( 0 , & V_386 -> V_151 ) )
return - V_37 ;
if ( F_91 ( & V_385 , V_386 , sizeof( V_385 ) ) )
return - V_37 ;
V_151 = F_261 ( V_4 , V_385 . V_387 , V_385 . V_113 ) ;
F_258 ( V_151 , & V_386 -> V_151 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_397 :
{
struct V_389 V_390 ;
struct V_389 T_1 * V_391 = V_350 ;
struct V_14 * V_15 = V_4 -> V_15 ;
void * V_392 ;
T_5 V_151 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( V_15 -> V_127 > 128 )
return - V_59 ;
if ( F_250 ( 0 , & V_391 -> V_151 ) )
return - V_37 ;
if ( F_91 ( & V_390 , V_391 , sizeof( V_390 ) ) )
return - V_37 ;
V_392 = F_55 ( V_390 . V_392 ,
sizeof( void * ) * V_15 -> V_127 ) ;
if ( F_56 ( V_392 ) )
return F_57 ( V_392 ) ;
V_151 = F_262 ( V_4 , V_392 , V_390 . V_113 ) ;
F_27 ( V_392 ) ;
F_258 ( V_151 , & V_391 -> V_151 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_393 :
{
T_2 V_113 ;
T_2 T_1 * V_394 = V_350 ;
T_5 V_151 ;
if ( F_100 ( V_113 , V_394 ) )
return - V_37 ;
if ( F_250 ( 0 , V_394 ) )
return - V_37 ;
V_151 = F_241 ( V_4 , V_113 ) ;
F_258 ( V_151 , V_394 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_395 :
{
T_2 V_113 ;
T_2 T_1 * V_394 = V_350 ;
T_5 V_151 ;
if ( F_100 ( V_113 , V_394 ) )
return - V_37 ;
if ( F_250 ( 0 , V_394 ) )
return - V_37 ;
V_151 = F_244 ( V_4 , V_113 ) ;
F_258 ( V_151 , V_394 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
}
return F_254 ( V_246 , V_4 , V_351 , V_350 ) ;
}
static long F_263 ( struct V_246 * V_246 , unsigned int V_351 ,
unsigned long V_350 )
{
struct V_274 * V_275 ;
V_275 = V_246 -> V_280 ;
if ( ( ( V_351 >> 8 ) & 0xff ) != 'A' )
return - V_381 ;
return F_256 ( V_246 , V_275 -> V_4 , V_351 ,
( void T_1 * ) V_350 ) ;
}
static long F_264 ( struct V_246 * V_246 , unsigned int V_351 ,
unsigned long V_350 )
{
struct V_274 * V_275 ;
V_275 = V_246 -> V_280 ;
if ( ( ( V_351 >> 8 ) & 0xff ) != 'A' )
return - V_381 ;
return F_260 ( V_246 , V_275 -> V_4 , V_351 ,
( void T_1 * ) V_350 ) ;
}
int F_265 ( struct V_3 * V_4 ,
unsigned int V_351 , void * V_350 )
{
T_2 * V_113 = V_350 ;
T_5 V_151 ;
int V_34 ;
switch ( V_351 ) {
case V_395 :
{
if ( V_4 -> V_22 != V_332 )
return - V_59 ;
V_151 = F_244 ( V_4 , * V_113 ) ;
return V_151 < 0 ? V_151 : 0 ;
}
case V_360 :
return V_47 ( V_4 , V_350 ) ;
case V_362 :
return F_85 ( V_4 , V_350 ) ;
case V_366 :
return F_154 ( V_4 , NULL ) ;
case V_368 :
return F_122 ( V_4 ) ;
case V_378 :
F_167 ( V_4 -> V_5 -> V_19 ) ;
V_34 = F_159 ( V_4 , NULL ) ;
F_163 ( V_4 -> V_5 -> V_19 ) ;
return V_34 ;
case V_379 :
return F_170 ( V_4 ) ;
case V_374 :
{
V_151 = F_246 ( V_4 ) ;
if ( V_151 < 0 )
return V_151 ;
* V_113 = V_151 ;
return 0 ;
}
default:
return - V_59 ;
}
}
static T_6 F_266 ( struct V_246 * V_246 , char T_1 * V_387 , T_7 V_285 ,
T_8 * V_398 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
T_5 V_151 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( ! F_267 ( V_15 , V_285 ) )
return - V_59 ;
V_285 = F_268 ( V_15 , V_285 ) ;
V_151 = F_261 ( V_4 , V_387 , V_285 ) ;
if ( V_151 > 0 )
V_151 = F_269 ( V_15 , V_151 ) ;
return V_151 ;
}
static T_6 F_270 ( struct V_246 * V_246 , const char T_1 * V_387 ,
T_7 V_285 , T_8 * V_398 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
T_5 V_151 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( ! F_267 ( V_15 , V_285 ) )
return - V_59 ;
V_285 = F_268 ( V_15 , V_285 ) ;
V_151 = F_257 ( V_4 , V_387 , V_285 ) ;
if ( V_151 > 0 )
V_151 = F_269 ( V_15 , V_151 ) ;
return V_151 ;
}
static T_6 F_271 ( struct V_399 * V_400 , struct V_401 * V_402 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
T_5 V_151 ;
unsigned long V_63 ;
void T_1 * * V_392 ;
T_2 V_113 ;
V_275 = V_400 -> V_403 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( ! F_272 ( V_402 ) )
return - V_59 ;
if ( V_402 -> V_404 > 1024 || V_402 -> V_404 != V_15 -> V_127 )
return - V_59 ;
if ( ! F_267 ( V_15 , V_402 -> V_405 -> V_406 ) )
return - V_59 ;
V_113 = F_273 ( V_15 , V_402 -> V_405 -> V_406 ) ;
V_392 = F_25 ( sizeof( void * ) * V_402 -> V_404 , V_35 ) ;
if ( V_392 == NULL )
return - V_36 ;
for ( V_63 = 0 ; V_63 < V_402 -> V_404 ; ++ V_63 )
V_392 [ V_63 ] = V_402 -> V_405 [ V_63 ] . V_407 ;
V_151 = F_262 ( V_4 , V_392 , V_113 ) ;
if ( V_151 > 0 )
V_151 = F_269 ( V_15 , V_151 ) ;
F_27 ( V_392 ) ;
return V_151 ;
}
static T_6 F_274 ( struct V_399 * V_400 , struct V_401 * V_408 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
T_5 V_151 ;
unsigned long V_63 ;
void T_1 * * V_392 ;
T_2 V_113 ;
V_275 = V_400 -> V_403 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( ! F_272 ( V_408 ) )
return - V_59 ;
if ( V_408 -> V_404 > 128 || V_408 -> V_404 != V_15 -> V_127 ||
! F_267 ( V_15 , V_408 -> V_405 -> V_406 ) )
return - V_59 ;
V_113 = F_273 ( V_15 , V_408 -> V_405 -> V_406 ) ;
V_392 = F_25 ( sizeof( void * ) * V_408 -> V_404 , V_35 ) ;
if ( V_392 == NULL )
return - V_36 ;
for ( V_63 = 0 ; V_63 < V_408 -> V_404 ; ++ V_63 )
V_392 [ V_63 ] = V_408 -> V_405 [ V_63 ] . V_407 ;
V_151 = F_259 ( V_4 , V_392 , V_113 ) ;
if ( V_151 > 0 )
V_151 = F_269 ( V_15 , V_151 ) ;
F_27 ( V_392 ) ;
return V_151 ;
}
static unsigned int F_275 ( struct V_246 * V_246 , T_9 * V_251 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
unsigned int V_288 ;
T_2 V_177 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return V_409 | V_410 | V_411 ;
V_15 = V_4 -> V_15 ;
F_276 ( V_246 , & V_15 -> V_213 , V_251 ) ;
F_14 ( V_4 ) ;
V_177 = F_97 ( V_15 ) ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_178 :
case V_117 :
case V_221 :
if ( V_177 >= V_15 -> V_140 -> V_141 ) {
V_288 = V_409 | V_410 ;
break;
}
case V_179 :
V_288 = 0 ;
break;
default:
V_288 = V_409 | V_410 | V_411 ;
break;
}
F_16 ( V_4 ) ;
return V_288 ;
}
static unsigned int F_277 ( struct V_246 * V_246 , T_9 * V_251 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
unsigned int V_288 ;
T_2 V_177 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return V_412 | V_413 | V_411 ;
V_15 = V_4 -> V_15 ;
F_276 ( V_246 , & V_15 -> V_213 , V_251 ) ;
F_14 ( V_4 ) ;
V_177 = F_98 ( V_15 ) ;
switch ( V_15 -> V_100 -> V_99 ) {
case V_178 :
case V_117 :
case V_221 :
if ( V_177 >= V_15 -> V_140 -> V_141 ) {
V_288 = V_412 | V_413 ;
break;
}
V_288 = 0 ;
break;
case V_179 :
if ( V_177 > 0 ) {
V_288 = V_412 | V_413 ;
break;
}
default:
V_288 = V_412 | V_413 | V_411 ;
break;
}
F_16 ( V_4 ) ;
return V_288 ;
}
static int F_278 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = V_415 -> V_416 -> V_417 ;
struct V_14 * V_15 ;
if ( V_4 == NULL )
return V_418 ;
V_15 = V_4 -> V_15 ;
V_415 -> V_419 = F_279 ( V_15 -> V_100 ) ;
F_280 ( V_415 -> V_419 ) ;
return 0 ;
}
static int V_343 ( struct V_3 * V_4 , struct V_246 * V_246 ,
struct V_420 * V_421 )
{
long V_422 ;
if ( ! ( V_421 -> V_423 & V_424 ) )
return - V_59 ;
V_422 = V_421 -> V_425 - V_421 -> V_426 ;
if ( V_422 != F_281 ( sizeof( struct V_343 ) ) )
return - V_59 ;
V_421 -> V_427 = & V_428 ;
V_421 -> V_417 = V_4 ;
V_421 -> V_423 |= V_429 | V_430 ;
return 0 ;
}
static int F_282 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = V_415 -> V_416 -> V_417 ;
struct V_14 * V_15 ;
if ( V_4 == NULL )
return V_418 ;
V_15 = V_4 -> V_15 ;
V_415 -> V_419 = F_279 ( V_15 -> V_140 ) ;
F_280 ( V_415 -> V_419 ) ;
return 0 ;
}
static int V_344 ( struct V_3 * V_4 , struct V_246 * V_246 ,
struct V_420 * V_421 )
{
long V_422 ;
if ( ! ( V_421 -> V_423 & V_424 ) )
return - V_59 ;
V_422 = V_421 -> V_425 - V_421 -> V_426 ;
if ( V_422 != F_281 ( sizeof( struct V_344 ) ) )
return - V_59 ;
V_421 -> V_427 = & V_431 ;
V_421 -> V_417 = V_4 ;
V_421 -> V_423 |= V_429 | V_430 ;
return 0 ;
}
static bool F_283 ( struct V_274 * V_275 )
{
if ( V_275 -> V_432 )
return false ;
if ( V_275 -> V_358 < F_86 ( 2 , 0 , 14 ) &&
( V_275 -> V_4 -> V_15 -> V_38 . V_13 & V_433 ) )
return false ;
return true ;
}
static bool F_284 ( struct V_274 * V_275 )
{
if ( V_275 -> V_432 )
return false ;
if ( V_275 -> V_4 -> V_15 -> V_38 . V_13 & V_433 )
return false ;
return true ;
}
static int V_343 ( struct V_3 * V_4 , struct V_246 * V_246 ,
struct V_420 * V_421 )
{
return - V_114 ;
}
static int V_344 ( struct V_3 * V_4 , struct V_246 * V_246 ,
struct V_420 * V_421 )
{
return - V_114 ;
}
static inline struct V_419 *
F_285 ( struct V_3 * V_4 , unsigned long V_434 )
{
void * V_435 = V_4 -> V_15 -> V_436 + V_434 ;
return F_279 ( V_435 ) ;
}
static int F_286 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = V_415 -> V_416 -> V_417 ;
struct V_14 * V_15 ;
unsigned long V_398 ;
struct V_419 * V_419 ;
T_7 V_323 ;
if ( V_4 == NULL )
return V_418 ;
V_15 = V_4 -> V_15 ;
V_398 = V_415 -> V_437 << V_438 ;
V_323 = F_281 ( V_15 -> V_323 ) ;
if ( V_398 > V_323 - V_439 )
return V_418 ;
if ( V_4 -> V_42 -> V_419 )
V_419 = V_4 -> V_42 -> V_419 ( V_4 , V_398 ) ;
else
V_419 = F_285 ( V_4 , V_398 ) ;
if ( ! V_419 )
return V_418 ;
F_280 ( V_419 ) ;
V_415 -> V_419 = V_419 ;
return 0 ;
}
int F_287 ( struct V_3 * V_4 ,
struct V_420 * V_421 )
{
V_421 -> V_423 |= V_429 | V_430 ;
#ifdef F_288
if ( V_4 -> V_44 . V_45 . type == V_440 ) {
V_421 -> V_441 = F_289 ( V_421 -> V_441 ) ;
return F_290 ( V_421 , V_421 -> V_426 ,
V_4 -> V_44 . V_442 >> V_438 ,
V_421 -> V_425 - V_421 -> V_426 , V_421 -> V_441 ) ;
}
#endif
#ifndef F_291
if ( F_68 ( V_41 ) && ! V_4 -> V_42 -> V_419 &&
V_4 -> V_44 . V_45 . type == V_46 )
return F_292 ( V_4 -> V_44 . V_45 . V_45 ,
V_421 ,
V_4 -> V_15 -> V_436 ,
V_4 -> V_15 -> V_443 ,
V_421 -> V_425 - V_421 -> V_426 ) ;
#endif
V_421 -> V_427 = & V_444 ;
return 0 ;
}
int F_293 ( struct V_3 * V_4 ,
struct V_420 * V_421 )
{
struct V_14 * V_15 = V_4 -> V_15 ; ;
V_421 -> V_441 = F_294 ( V_421 -> V_441 ) ;
return F_295 ( V_421 , V_15 -> V_443 , V_15 -> V_323 ) ;
}
int F_296 ( struct V_3 * V_4 , struct V_246 * V_246 ,
struct V_420 * V_421 )
{
struct V_14 * V_15 ;
long V_422 ;
unsigned long V_398 ;
T_7 V_323 ;
int V_34 ;
if ( V_4 -> V_22 == V_156 ) {
if ( ! ( V_421 -> V_423 & ( V_445 | V_424 ) ) )
return - V_59 ;
} else {
if ( ! ( V_421 -> V_423 & V_424 ) )
return - V_59 ;
}
V_15 = V_4 -> V_15 ;
if ( V_15 -> V_100 -> V_99 == V_115 )
return - V_118 ;
if ( ! ( V_15 -> V_13 & V_39 ) )
return - V_114 ;
if ( V_15 -> V_124 == V_306 ||
V_15 -> V_124 == V_308 )
return - V_59 ;
V_422 = V_421 -> V_425 - V_421 -> V_426 ;
V_398 = V_421 -> V_446 << V_438 ;
V_323 = F_281 ( V_15 -> V_323 ) ;
if ( ( T_7 ) V_422 > V_323 )
return - V_59 ;
if ( V_398 > V_323 - V_422 )
return - V_59 ;
V_421 -> V_427 = & V_447 ;
V_421 -> V_417 = V_4 ;
if ( V_4 -> V_42 -> V_43 )
V_34 = V_4 -> V_42 -> V_43 ( V_4 , V_421 ) ;
else
V_34 = F_287 ( V_4 , V_421 ) ;
if ( ! V_34 )
F_297 ( & V_4 -> V_121 ) ;
return V_34 ;
}
static int F_298 ( struct V_246 * V_246 , struct V_420 * V_421 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
unsigned long V_398 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_398 = V_421 -> V_446 << V_438 ;
switch ( V_398 ) {
case V_448 :
if ( ! F_283 ( V_275 ) )
return - V_114 ;
return V_343 ( V_4 , V_246 , V_421 ) ;
case V_449 :
if ( ! F_284 ( V_275 ) )
return - V_114 ;
return V_344 ( V_4 , V_246 , V_421 ) ;
default:
return F_296 ( V_4 , V_246 , V_421 ) ;
}
return 0 ;
}
static int F_299 ( int V_273 , struct V_246 * V_246 , int V_450 )
{
struct V_274 * V_275 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
V_275 = V_246 -> V_280 ;
V_4 = V_275 -> V_4 ;
if ( F_67 ( V_4 ) )
return - V_114 ;
V_15 = V_4 -> V_15 ;
return F_300 ( V_273 , V_246 , V_450 , & V_15 -> V_451 ) ;
}
static void F_301 ( struct V_47 * V_48 ,
struct V_452 * V_453 )
{
unsigned int V_63 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_12 = V_453 -> V_12 ;
for ( V_63 = 0 ; V_63 < F_302 ( V_453 -> V_454 ) ; V_63 ++ )
V_48 -> V_454 [ V_63 ] . V_112 [ 0 ] = V_453 -> V_454 [ V_63 ] ;
memcpy ( V_48 -> V_455 , V_453 -> V_455 , sizeof( V_453 -> V_455 ) ) ;
V_48 -> V_60 = F_303 ( V_453 -> V_60 ) ;
V_48 -> V_61 = F_303 ( V_453 -> V_61 ) ;
V_48 -> V_13 = V_453 -> V_13 ;
V_48 -> V_81 = V_453 -> V_81 ;
V_48 -> V_85 = V_453 -> V_85 ;
V_48 -> V_83 = V_453 -> V_83 ;
V_48 -> V_86 = V_453 -> V_86 ;
}
static void F_304 ( struct V_452 * V_453 ,
struct V_47 * V_48 )
{
unsigned int V_63 ;
memset ( V_453 , 0 , sizeof( * V_453 ) ) ;
V_453 -> V_12 = V_48 -> V_12 ;
for ( V_63 = 0 ; V_63 < F_302 ( V_453 -> V_454 ) ; V_63 ++ )
V_453 -> V_454 [ V_63 ] = V_48 -> V_454 [ V_63 ] . V_112 [ 0 ] ;
memcpy ( V_453 -> V_455 , V_48 -> V_455 , sizeof( V_453 -> V_455 ) ) ;
V_453 -> V_60 = F_305 ( V_48 -> V_60 ) ;
V_453 -> V_61 = F_305 ( V_48 -> V_61 ) ;
V_453 -> V_13 = V_48 -> V_13 ;
V_453 -> V_81 = V_48 -> V_81 ;
V_453 -> V_85 = V_48 -> V_85 ;
V_453 -> V_83 = V_48 -> V_83 ;
V_453 -> V_86 = V_48 -> V_86 ;
}
static int F_252 ( struct V_3 * V_4 ,
struct V_452 T_1 * V_456 )
{
struct V_47 * V_48 ;
struct V_452 * V_453 = NULL ;
int V_34 ;
V_48 = F_25 ( sizeof( * V_48 ) , V_35 ) ;
if ( ! V_48 )
return - V_36 ;
V_453 = F_55 ( V_456 , sizeof( * V_453 ) ) ;
if ( F_56 ( V_453 ) ) {
V_34 = F_57 ( V_453 ) ;
goto V_457;
}
F_301 ( V_48 , V_453 ) ;
V_34 = F_53 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_458;
V_34 = F_47 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_458;
F_304 ( V_453 , V_48 ) ;
if ( F_26 ( V_456 , V_453 , sizeof( * V_453 ) ) )
V_34 = - V_37 ;
V_458:
F_27 ( V_453 ) ;
V_457:
F_27 ( V_48 ) ;
return V_34 ;
}
static int F_253 ( struct V_3 * V_4 ,
struct V_452 T_1 * V_456 )
{
struct V_47 * V_48 ;
struct V_452 * V_453 = NULL ;
int V_34 ;
V_48 = F_25 ( sizeof( * V_48 ) , V_35 ) ;
if ( ! V_48 )
return - V_36 ;
V_453 = F_55 ( V_456 , sizeof( * V_453 ) ) ;
if ( F_56 ( V_453 ) ) {
V_34 = F_57 ( V_453 ) ;
goto V_457;
}
F_301 ( V_48 , V_453 ) ;
V_34 = V_47 ( V_4 , V_48 ) ;
if ( V_34 < 0 )
goto V_458;
F_304 ( V_453 , V_48 ) ;
if ( F_26 ( V_456 , V_453 , sizeof( * V_453 ) ) )
V_34 = - V_37 ;
V_458:
F_27 ( V_453 ) ;
V_457:
F_27 ( V_48 ) ;
return V_34 ;
}
static unsigned long F_306 ( struct V_246 * V_246 ,
unsigned long V_442 ,
unsigned long V_459 ,
unsigned long V_437 ,
unsigned long V_12 )
{
struct V_274 * V_275 = V_246 -> V_280 ;
struct V_3 * V_4 = V_275 -> V_4 ;
struct V_14 * V_15 = V_4 -> V_15 ;
unsigned long V_398 = V_437 << V_438 ;
switch ( V_398 ) {
case V_448 :
return ( unsigned long ) V_15 -> V_100 ;
case V_449 :
return ( unsigned long ) V_15 -> V_140 ;
default:
return ( unsigned long ) V_15 -> V_436 + V_398 ;
}
}
