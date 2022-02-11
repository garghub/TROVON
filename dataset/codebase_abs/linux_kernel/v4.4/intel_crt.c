static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 ) ) ;
}
static bool F_5 ( struct V_2 * V_3 ,
enum V_7 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_14 V_15 ;
T_1 V_16 ;
V_15 = F_6 ( V_3 ) ;
if ( ! F_7 ( V_11 , V_15 ) )
return false ;
V_16 = F_8 ( V_13 -> V_17 ) ;
if ( ! ( V_16 & V_18 ) )
return false ;
if ( F_9 ( V_9 ) )
* V_7 = F_10 ( V_16 ) ;
else
* V_7 = F_11 ( V_16 ) ;
return true ;
}
static unsigned int F_12 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_16 , V_19 = 0 ;
V_16 = F_8 ( V_13 -> V_17 ) ;
if ( V_16 & V_20 )
V_19 |= V_21 ;
else
V_19 |= V_22 ;
if ( V_16 & V_23 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
return V_19 ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
int V_28 ;
V_27 -> V_4 . V_29 . V_19 |= F_12 ( V_3 ) ;
V_28 = V_27 -> V_30 ;
if ( F_14 ( V_9 ) )
F_15 ( V_27 , V_28 ) ;
V_27 -> V_4 . V_29 . V_31 = V_28 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
F_17 ( V_3 , V_27 ) ;
V_27 -> V_4 . V_29 . V_19 &= ~ ( V_21 |
V_22 |
V_24 |
V_25 ) ;
V_27 -> V_4 . V_29 . V_19 |= F_12 ( V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_32 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_33 * V_34 = F_19 ( V_3 -> V_4 . V_34 ) ;
const struct V_35 * V_29 = & V_34 -> V_36 -> V_4 . V_29 ;
T_1 V_37 ;
if ( F_20 ( V_9 ) -> V_38 >= 5 )
V_37 = V_39 ;
else
V_37 = 0 ;
if ( V_29 -> V_19 & V_21 )
V_37 |= V_20 ;
if ( V_29 -> V_19 & V_24 )
V_37 |= V_23 ;
if ( F_21 ( V_9 ) )
;
else if ( F_9 ( V_9 ) )
V_37 |= F_22 ( V_34 -> V_7 ) ;
else if ( V_34 -> V_7 == 0 )
V_37 |= V_40 ;
else
V_37 |= V_41 ;
if ( ! F_14 ( V_9 ) )
F_23 ( F_24 ( V_34 -> V_7 ) , 0 ) ;
switch ( V_32 ) {
case V_42 :
V_37 |= V_18 ;
break;
case V_43 :
V_37 |= V_18 | V_44 ;
break;
case V_45 :
V_37 |= V_18 | V_46 ;
break;
case V_47 :
V_37 |= V_44 | V_46 ;
break;
}
F_23 ( V_13 -> V_17 , V_37 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_18 ( V_3 , V_47 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
}
static void F_27 ( struct V_2 * V_3 )
{
F_25 ( V_3 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_18 ( V_3 , V_13 -> V_6 -> V_4 . V_48 ) ;
}
static enum V_49
F_29 ( struct V_5 * V_6 ,
struct V_35 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_50 = 0 ;
if ( V_32 -> V_19 & V_51 )
return V_52 ;
if ( V_32 -> clock < 25000 )
return V_53 ;
if ( F_30 ( V_9 ) )
V_50 = 350000 ;
else
V_50 = 400000 ;
if ( V_32 -> clock > V_50 )
return V_54 ;
if ( F_21 ( V_9 ) &&
( F_31 ( V_32 -> clock , 270000 , 24 ) > 2 ) )
return V_54 ;
return V_55 ;
}
static bool F_32 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_14 ( V_9 ) )
V_27 -> V_56 = true ;
if ( F_21 ( V_9 ) )
V_27 -> V_57 = 24 ;
if ( F_33 ( V_9 ) ) {
V_27 -> V_58 = V_59 ;
V_27 -> V_30 = 135000 * 2 ;
V_27 -> V_60 . V_61 = 0 ;
V_27 -> V_60 . V_62 =
V_63 | V_64 | V_65 ;
}
return true ;
}
static bool F_34 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_66 ;
if ( V_13 -> V_67 ) {
bool V_68 = F_14 ( V_9 ) ;
T_1 V_69 ;
V_13 -> V_67 = 0 ;
V_69 = V_37 = F_8 ( V_13 -> V_17 ) ;
F_35 ( L_1 , V_37 ) ;
V_37 |= V_70 ;
if ( V_68 )
V_37 &= ~ V_18 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
if ( F_36 ( ( F_8 ( V_13 -> V_17 ) & V_70 ) == 0 ,
1000 ) )
F_35 ( L_2 ) ;
if ( V_68 ) {
F_23 ( V_13 -> V_17 , V_69 ) ;
F_37 ( V_13 -> V_17 ) ;
}
}
V_37 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_37 & V_71 ) != 0 )
V_66 = true ;
else
V_66 = false ;
F_35 ( L_3 , V_37 , V_66 ) ;
return V_66 ;
}
static bool F_38 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_66 ;
T_1 V_69 ;
V_69 = V_37 = F_8 ( V_13 -> V_17 ) ;
F_35 ( L_1 , V_37 ) ;
V_37 |= V_70 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
if ( F_36 ( ( F_8 ( V_13 -> V_17 ) & V_70 ) == 0 ,
1000 ) ) {
F_35 ( L_2 ) ;
F_23 ( V_13 -> V_17 , V_69 ) ;
}
V_37 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_37 & V_71 ) != 0 )
V_66 = true ;
else
V_66 = false ;
F_35 ( L_4 , V_37 , V_66 ) ;
return V_66 ;
}
static bool F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_72 ;
bool V_66 = false ;
int V_73 , V_74 = 0 ;
if ( F_14 ( V_9 ) )
return F_34 ( V_6 ) ;
if ( F_40 ( V_9 ) )
return F_38 ( V_6 ) ;
if ( F_41 ( V_9 ) && ! F_42 ( V_9 ) )
V_74 = 2 ;
else
V_74 = 1 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
F_43 ( V_11 ,
V_75 ,
V_75 ) ;
if ( F_36 ( ( F_8 ( V_76 ) &
V_75 ) == 0 ,
1000 ) )
F_35 ( L_5 ) ;
}
V_72 = F_8 ( V_77 ) ;
if ( ( V_72 & V_78 ) != V_79 )
V_66 = true ;
F_23 ( V_77 , V_80 ) ;
F_43 ( V_11 , V_75 , 0 ) ;
return V_66 ;
}
static struct V_81 * F_44 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
struct V_81 * V_81 ;
V_81 = F_45 ( V_6 , V_83 ) ;
if ( ! V_81 && ! F_46 ( V_83 ) ) {
F_35 ( L_6 ) ;
F_47 ( V_83 , true ) ;
V_81 = F_45 ( V_6 , V_83 ) ;
F_47 ( V_83 , false ) ;
}
return V_81 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_82 * V_84 )
{
struct V_81 * V_81 ;
int V_66 ;
V_81 = F_44 ( V_6 , V_84 ) ;
if ( ! V_81 )
return 0 ;
V_66 = F_49 ( V_6 , V_81 ) ;
F_50 ( V_81 ) ;
return V_66 ;
}
static bool F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_81 * V_81 ;
struct V_82 * V_83 ;
F_52 ( V_13 -> V_4 . type != V_85 ) ;
V_83 = F_53 ( V_11 , V_11 -> V_86 . V_87 ) ;
V_81 = F_44 ( V_6 , V_83 ) ;
if ( V_81 ) {
bool V_88 = V_81 -> V_89 & V_90 ;
if ( ! V_88 ) {
F_35 ( L_7 ) ;
return true ;
}
F_35 ( L_8 ) ;
} else {
F_35 ( L_9 ) ;
}
F_50 ( V_81 ) ;
return false ;
}
static enum V_91
F_54 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_19 ( V_13 -> V_4 . V_4 . V_34 ) -> V_7 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_94 , V_95 ;
T_2 V_96 ;
T_2 V_97 , V_98 , V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
T_2 V_104 ;
T_2 V_105 ;
T_2 V_106 ;
T_3 V_107 ;
enum V_91 V_108 ;
F_35 ( L_10 ) ;
V_101 = F_24 ( V_7 ) ;
V_102 = F_55 ( V_7 ) ;
V_103 = F_56 ( V_7 ) ;
V_104 = F_57 ( V_7 ) ;
V_105 = F_58 ( V_7 ) ;
V_106 = F_59 ( V_7 ) ;
V_92 = F_8 ( V_101 ) ;
V_93 = F_8 ( V_102 ) ;
V_97 = F_8 ( V_103 ) ;
V_94 = ( ( V_93 >> 16 ) & 0xfff ) + 1 ;
V_95 = ( V_93 & 0x7ff ) + 1 ;
V_98 = ( V_97 & 0xfff ) + 1 ;
V_99 = ( ( V_97 >> 16 ) & 0xfff ) + 1 ;
F_23 ( V_101 , 0x500050 ) ;
if ( ! F_30 ( V_9 ) ) {
T_2 V_109 = F_8 ( V_105 ) ;
F_23 ( V_105 , V_109 | V_110 ) ;
F_37 ( V_105 ) ;
F_60 ( V_9 , V_7 ) ;
V_107 = F_61 ( V_111 ) ;
V_108 = ( ( V_107 & ( 1 << 4 ) ) != 0 ) ?
V_112 :
V_113 ;
F_23 ( V_105 , V_109 ) ;
} else {
bool V_114 = false ;
int V_115 , V_116 ;
if ( V_98 <= V_95 && V_99 >= V_94 ) {
T_2 V_117 = F_8 ( V_104 ) ;
T_2 V_118 = ( V_117 & 0xffff ) + 1 ;
V_98 = V_118 ;
F_23 ( V_103 ,
( V_98 - 1 ) |
( ( V_99 - 1 ) << 16 ) ) ;
V_114 = true ;
}
if ( V_98 - V_95 >= V_94 - V_99 )
V_96 = ( V_98 + V_95 ) >> 1 ;
else
V_96 = ( V_94 + V_99 ) >> 1 ;
while ( F_8 ( V_106 ) >= V_95 )
;
while ( ( V_100 = F_8 ( V_106 ) ) <= V_96 )
;
V_116 = 0 ;
V_115 = 0 ;
do {
V_115 ++ ;
V_107 = F_61 ( V_111 ) ;
if ( V_107 & ( 1 << 4 ) )
V_116 ++ ;
} while ( ( F_8 ( V_106 ) == V_100 ) );
if ( V_114 )
F_23 ( V_103 , V_97 ) ;
V_108 = V_116 * 4 > V_115 * 3 ?
V_112 :
V_113 ;
}
F_23 ( V_101 , V_92 ) ;
return V_108 ;
}
static enum V_91
F_62 ( struct V_5 * V_6 , bool V_119 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_91 V_108 ;
struct V_120 V_16 ;
struct V_121 V_122 ;
F_35 ( L_11 ,
V_6 -> V_4 . V_123 , V_6 -> V_124 ,
V_119 ) ;
V_15 = F_6 ( V_2 ) ;
F_63 ( V_11 , V_15 ) ;
if ( F_64 ( V_9 ) ) {
if ( F_39 ( V_6 ) ) {
F_35 ( L_12 ) ;
V_108 = V_112 ;
goto V_125;
} else
F_35 ( L_13 ) ;
}
if ( F_51 ( V_6 ) ) {
V_108 = V_112 ;
goto V_125;
}
if ( F_64 ( V_9 ) && ! V_126 . V_127 ) {
V_108 = V_113 ;
goto V_125;
}
if ( ! V_119 ) {
V_108 = V_6 -> V_108 ;
goto V_125;
}
F_65 ( & V_122 , 0 ) ;
if ( F_66 ( V_6 , NULL , & V_16 , & V_122 ) ) {
if ( F_51 ( V_6 ) )
V_108 = V_112 ;
else if ( F_20 ( V_9 ) -> V_38 < 4 )
V_108 = F_54 ( V_13 ) ;
else
V_108 = V_128 ;
F_67 ( V_6 , & V_16 , & V_122 ) ;
} else
V_108 = V_128 ;
F_68 ( & V_122 ) ;
F_69 ( & V_122 ) ;
V_125:
F_70 ( V_11 , V_15 ) ;
return V_108 ;
}
static void F_71 ( struct V_5 * V_6 )
{
F_72 ( V_6 ) ;
F_50 ( V_6 ) ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_66 ;
struct V_82 * V_83 ;
V_15 = F_6 ( V_2 ) ;
F_63 ( V_11 , V_15 ) ;
V_83 = F_53 ( V_11 , V_11 -> V_86 . V_87 ) ;
V_66 = F_48 ( V_6 , V_83 ) ;
if ( V_66 || ! F_41 ( V_9 ) )
goto V_125;
V_83 = F_53 ( V_11 , V_129 ) ;
V_66 = F_48 ( V_6 , V_83 ) ;
V_125:
F_70 ( V_11 , V_15 ) ;
return V_66 ;
}
static int F_74 ( struct V_5 * V_6 ,
struct V_130 * V_131 ,
T_4 V_132 )
{
return 0 ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_20 ( V_9 ) -> V_38 >= 5 ) {
T_1 V_37 ;
V_37 = F_8 ( V_13 -> V_17 ) ;
V_37 &= ~ V_133 ;
V_37 |= V_39 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
F_37 ( V_13 -> V_17 ) ;
F_35 ( L_14 , V_37 ) ;
V_13 -> V_67 = 1 ;
}
}
static int F_76 ( const struct V_134 * V_123 )
{
F_77 ( L_15 , V_123 -> V_135 ) ;
return 1 ;
}
void F_78 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_136 * V_136 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_79 ( V_137 ) )
return;
V_13 = F_80 ( sizeof( struct V_1 ) , V_138 ) ;
if ( ! V_13 )
return;
V_136 = F_81 () ;
if ( ! V_136 ) {
F_50 ( V_13 ) ;
return;
}
V_6 = & V_136 -> V_4 ;
V_13 -> V_6 = V_136 ;
F_82 ( V_9 , & V_136 -> V_4 ,
& V_139 , V_140 ) ;
F_83 ( V_9 , & V_13 -> V_4 . V_4 , & V_141 ,
V_142 ) ;
F_84 ( V_136 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_85 ;
V_13 -> V_4 . V_143 = ( 1 << V_144 ) | ( 1 << V_145 ) ;
if ( F_85 ( V_9 ) )
V_13 -> V_4 . V_146 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_146 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_30 ( V_9 ) )
V_6 -> V_147 = 0 ;
else
V_6 -> V_147 = 1 ;
V_6 -> V_148 = 0 ;
if ( F_14 ( V_9 ) )
V_13 -> V_17 = V_149 ;
else if ( F_40 ( V_9 ) )
V_13 -> V_17 = V_150 ;
else
V_13 -> V_17 = V_151 ;
V_13 -> V_4 . V_152 = F_32 ;
if ( F_14 ( V_9 ) && ! F_33 ( V_9 ) ) {
V_13 -> V_4 . V_153 = F_26 ;
V_13 -> V_4 . V_154 = F_27 ;
} else {
V_13 -> V_4 . V_153 = F_25 ;
}
V_13 -> V_4 . V_155 = F_28 ;
if ( F_64 ( V_9 ) )
V_13 -> V_4 . V_156 = V_157 ;
if ( F_33 ( V_9 ) ) {
V_13 -> V_4 . V_158 = F_16 ;
V_13 -> V_4 . V_159 = V_160 ;
} else {
V_13 -> V_4 . V_158 = F_13 ;
V_13 -> V_4 . V_159 = F_5 ;
}
V_136 -> V_159 = V_161 ;
V_136 -> V_162 = V_163 ;
F_86 ( V_6 , & V_164 ) ;
F_87 ( V_6 ) ;
if ( ! F_64 ( V_9 ) )
V_136 -> V_165 = V_166 ;
V_13 -> V_67 = 0 ;
if ( F_21 ( V_9 ) ) {
T_1 V_167 = V_168 |
V_169 ;
V_11 -> V_170 = F_8 ( F_88 ( V_171 ) ) & V_167 ;
}
F_75 ( V_6 ) ;
}
