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
bool V_17 ;
V_15 = F_6 ( V_3 ) ;
if ( ! F_7 ( V_11 , V_15 ) )
return false ;
V_17 = false ;
V_16 = F_8 ( V_13 -> V_18 ) ;
if ( ! ( V_16 & V_19 ) )
goto V_20;
if ( F_9 ( V_9 ) )
* V_7 = F_10 ( V_16 ) ;
else
* V_7 = F_11 ( V_16 ) ;
V_17 = true ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_17 ;
}
static unsigned int F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_16 , V_21 = 0 ;
V_16 = F_8 ( V_13 -> V_18 ) ;
if ( V_16 & V_22 )
V_21 |= V_23 ;
else
V_21 |= V_24 ;
if ( V_16 & V_25 )
V_21 |= V_26 ;
else
V_21 |= V_27 ;
return V_21 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
int V_30 ;
V_29 -> V_4 . V_31 . V_21 |= F_13 ( V_3 ) ;
V_30 = V_29 -> V_32 ;
if ( F_15 ( V_9 ) )
F_16 ( V_29 , V_30 ) ;
V_29 -> V_4 . V_31 . V_33 = V_30 ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
F_18 ( V_3 , V_29 ) ;
V_29 -> V_4 . V_31 . V_21 &= ~ ( V_23 |
V_24 |
V_26 |
V_27 ) ;
V_29 -> V_4 . V_31 . V_21 |= F_13 ( V_3 ) ;
}
static void F_19 ( struct V_2 * V_3 , int V_34 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_35 * V_36 = F_20 ( V_3 -> V_4 . V_36 ) ;
const struct V_37 * V_31 = & V_36 -> V_38 -> V_4 . V_31 ;
T_1 V_39 ;
if ( F_21 ( V_9 ) -> V_40 >= 5 )
V_39 = V_41 ;
else
V_39 = 0 ;
if ( V_31 -> V_21 & V_23 )
V_39 |= V_22 ;
if ( V_31 -> V_21 & V_26 )
V_39 |= V_25 ;
if ( F_22 ( V_9 ) )
;
else if ( F_9 ( V_9 ) )
V_39 |= F_23 ( V_36 -> V_7 ) ;
else if ( V_36 -> V_7 == 0 )
V_39 |= V_42 ;
else
V_39 |= V_43 ;
if ( ! F_15 ( V_9 ) )
F_24 ( F_25 ( V_36 -> V_7 ) , 0 ) ;
switch ( V_34 ) {
case V_44 :
V_39 |= V_19 ;
break;
case V_45 :
V_39 |= V_19 | V_46 ;
break;
case V_47 :
V_39 |= V_19 | V_48 ;
break;
case V_49 :
V_39 |= V_46 | V_48 ;
break;
}
F_24 ( V_13 -> V_18 , V_39 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
F_19 ( V_3 , V_49 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
}
static void F_28 ( struct V_2 * V_3 )
{
F_26 ( V_3 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_19 ( V_3 , V_44 ) ;
}
static enum V_50
F_30 ( struct V_5 * V_6 ,
struct V_37 * V_34 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_51 = F_31 ( V_9 ) -> V_52 ;
int V_53 = 0 ;
if ( V_34 -> V_21 & V_54 )
return V_55 ;
if ( V_34 -> clock < 25000 )
return V_56 ;
if ( F_32 ( V_9 ) )
V_53 = 350000 ;
else
V_53 = 400000 ;
if ( V_34 -> clock > V_53 )
return V_57 ;
if ( V_34 -> clock > V_51 )
return V_57 ;
if ( F_22 ( V_9 ) &&
( F_33 ( V_34 -> clock , 270000 , 24 ) > 2 ) )
return V_57 ;
return V_58 ;
}
static bool F_34 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_15 ( V_9 ) )
V_29 -> V_59 = true ;
if ( F_22 ( V_9 ) ) {
if ( V_29 -> V_60 && V_29 -> V_61 < 24 ) {
F_35 ( L_1 ) ;
return false ;
}
V_29 -> V_61 = 24 ;
}
if ( F_36 ( V_9 ) ) {
V_29 -> V_62 = V_63 ;
V_29 -> V_32 = 135000 * 2 ;
V_29 -> V_64 . V_65 = 0 ;
V_29 -> V_64 . V_66 =
V_67 | V_68 | V_69 ;
}
return true ;
}
static bool F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_39 ;
bool V_17 ;
if ( V_13 -> V_70 ) {
bool V_71 = F_15 ( V_9 ) ;
T_1 V_72 ;
V_13 -> V_70 = 0 ;
V_72 = V_39 = F_8 ( V_13 -> V_18 ) ;
F_35 ( L_2 , V_39 ) ;
V_39 |= V_73 ;
if ( V_71 )
V_39 &= ~ V_19 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
if ( F_38 ( ( F_8 ( V_13 -> V_18 ) & V_73 ) == 0 ,
1000 ) )
F_35 ( L_3 ) ;
if ( V_71 ) {
F_24 ( V_13 -> V_18 , V_72 ) ;
F_39 ( V_13 -> V_18 ) ;
}
}
V_39 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_39 & V_74 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_35 ( L_4 , V_39 , V_17 ) ;
return V_17 ;
}
static bool F_40 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_39 ;
bool V_17 ;
T_1 V_72 ;
V_72 = V_39 = F_8 ( V_13 -> V_18 ) ;
F_35 ( L_2 , V_39 ) ;
V_39 |= V_73 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
if ( F_38 ( ( F_8 ( V_13 -> V_18 ) & V_73 ) == 0 ,
1000 ) ) {
F_35 ( L_3 ) ;
F_24 ( V_13 -> V_18 , V_72 ) ;
}
V_39 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_39 & V_74 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_35 ( L_5 , V_39 , V_17 ) ;
return V_17 ;
}
static bool F_41 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_75 ;
bool V_17 = false ;
int V_76 , V_77 = 0 ;
if ( F_15 ( V_9 ) )
return F_37 ( V_6 ) ;
if ( F_42 ( V_9 ) )
return F_40 ( V_6 ) ;
if ( F_43 ( V_9 ) && ! F_44 ( V_9 ) )
V_77 = 2 ;
else
V_77 = 1 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
F_45 ( V_11 ,
V_78 ,
V_78 ) ;
if ( F_38 ( ( F_8 ( V_79 ) &
V_78 ) == 0 ,
1000 ) )
F_35 ( L_6 ) ;
}
V_75 = F_8 ( V_80 ) ;
if ( ( V_75 & V_81 ) != V_82 )
V_17 = true ;
F_24 ( V_80 , V_83 ) ;
F_45 ( V_11 , V_78 , 0 ) ;
return V_17 ;
}
static struct V_84 * F_46 ( struct V_5 * V_6 ,
struct V_85 * V_86 )
{
struct V_84 * V_84 ;
V_84 = F_47 ( V_6 , V_86 ) ;
if ( ! V_84 && ! F_48 ( V_86 ) ) {
F_35 ( L_7 ) ;
F_49 ( V_86 , true ) ;
V_84 = F_47 ( V_6 , V_86 ) ;
F_49 ( V_86 , false ) ;
}
return V_84 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_85 * V_87 )
{
struct V_84 * V_84 ;
int V_17 ;
V_84 = F_46 ( V_6 , V_87 ) ;
if ( ! V_84 )
return 0 ;
V_17 = F_51 ( V_6 , V_84 ) ;
F_52 ( V_84 ) ;
return V_17 ;
}
static bool F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_84 * V_84 ;
struct V_85 * V_86 ;
F_54 ( V_13 -> V_4 . type != V_88 ) ;
V_86 = F_55 ( V_11 , V_11 -> V_89 . V_90 ) ;
V_84 = F_46 ( V_6 , V_86 ) ;
if ( V_84 ) {
bool V_91 = V_84 -> V_92 & V_93 ;
if ( ! V_91 ) {
F_35 ( L_8 ) ;
return true ;
}
F_35 ( L_9 ) ;
} else {
F_35 ( L_10 ) ;
}
F_52 ( V_84 ) ;
return false ;
}
static enum V_94
F_56 ( struct V_1 * V_13 , T_2 V_7 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_95 ;
T_2 V_96 ;
T_2 V_97 , V_98 ;
T_2 V_99 ;
T_2 V_100 , V_101 , V_102 ;
T_2 V_103 ;
T_3 V_104 , V_105 ,
V_106 , V_107 , V_108 , V_109 ;
T_4 V_110 ;
enum V_94 V_111 ;
F_35 ( L_11 ) ;
V_104 = F_25 ( V_7 ) ;
V_105 = F_57 ( V_7 ) ;
V_106 = F_58 ( V_7 ) ;
V_107 = F_59 ( V_7 ) ;
V_108 = F_60 ( V_7 ) ;
V_109 = F_61 ( V_7 ) ;
V_95 = F_8 ( V_104 ) ;
V_96 = F_8 ( V_105 ) ;
V_100 = F_8 ( V_106 ) ;
V_97 = ( ( V_96 >> 16 ) & 0xfff ) + 1 ;
V_98 = ( V_96 & 0x7ff ) + 1 ;
V_101 = ( V_100 & 0xfff ) + 1 ;
V_102 = ( ( V_100 >> 16 ) & 0xfff ) + 1 ;
F_24 ( V_104 , 0x500050 ) ;
if ( ! F_32 ( V_9 ) ) {
T_2 V_112 = F_8 ( V_108 ) ;
F_24 ( V_108 , V_112 | V_113 ) ;
F_39 ( V_108 ) ;
F_62 ( V_9 , V_7 ) ;
V_110 = F_63 ( V_114 ) ;
V_111 = ( ( V_110 & ( 1 << 4 ) ) != 0 ) ?
V_115 :
V_116 ;
F_24 ( V_108 , V_112 ) ;
} else {
bool V_117 = false ;
int V_118 , V_119 ;
if ( V_101 <= V_98 && V_102 >= V_97 ) {
T_2 V_120 = F_8 ( V_107 ) ;
T_2 V_121 = ( V_120 & 0xffff ) + 1 ;
V_101 = V_121 ;
F_24 ( V_106 ,
( V_101 - 1 ) |
( ( V_102 - 1 ) << 16 ) ) ;
V_117 = true ;
}
if ( V_101 - V_98 >= V_97 - V_102 )
V_99 = ( V_101 + V_98 ) >> 1 ;
else
V_99 = ( V_97 + V_102 ) >> 1 ;
while ( F_8 ( V_109 ) >= V_98 )
;
while ( ( V_103 = F_8 ( V_109 ) ) <= V_99 )
;
V_119 = 0 ;
V_118 = 0 ;
do {
V_118 ++ ;
V_110 = F_63 ( V_114 ) ;
if ( V_110 & ( 1 << 4 ) )
V_119 ++ ;
} while ( ( F_8 ( V_109 ) == V_103 ) );
if ( V_117 )
F_24 ( V_106 , V_100 ) ;
V_111 = V_119 * 4 > V_118 * 3 ?
V_115 :
V_116 ;
}
F_24 ( V_104 , V_95 ) ;
return V_111 ;
}
static enum V_94
F_64 ( struct V_5 * V_6 , bool V_122 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_94 V_111 ;
struct V_123 V_16 ;
struct V_124 V_125 ;
F_35 ( L_12 ,
V_6 -> V_4 . V_126 , V_6 -> V_127 ,
V_122 ) ;
V_15 = F_6 ( V_2 ) ;
F_65 ( V_11 , V_15 ) ;
if ( F_66 ( V_9 ) ) {
if ( F_41 ( V_6 ) ) {
F_35 ( L_13 ) ;
V_111 = V_115 ;
goto V_20;
} else
F_35 ( L_14 ) ;
}
if ( F_53 ( V_6 ) ) {
V_111 = V_115 ;
goto V_20;
}
if ( F_66 ( V_9 ) && ! V_128 . V_129 ) {
V_111 = V_116 ;
goto V_20;
}
if ( ! V_122 ) {
V_111 = V_6 -> V_111 ;
goto V_20;
}
F_67 ( & V_125 , 0 ) ;
if ( F_68 ( V_6 , NULL , & V_16 , & V_125 ) ) {
if ( F_53 ( V_6 ) )
V_111 = V_115 ;
else if ( F_21 ( V_9 ) -> V_40 < 4 )
V_111 = F_56 ( V_13 ,
F_20 ( V_6 -> V_130 -> V_36 ) -> V_7 ) ;
else
V_111 = V_131 ;
F_69 ( V_6 , & V_16 , & V_125 ) ;
} else
V_111 = V_131 ;
F_70 ( & V_125 ) ;
F_71 ( & V_125 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_111 ;
}
static void F_72 ( struct V_5 * V_6 )
{
F_73 ( V_6 ) ;
F_52 ( V_6 ) ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_17 ;
struct V_85 * V_86 ;
V_15 = F_6 ( V_2 ) ;
F_65 ( V_11 , V_15 ) ;
V_86 = F_55 ( V_11 , V_11 -> V_89 . V_90 ) ;
V_17 = F_50 ( V_6 , V_86 ) ;
if ( V_17 || ! F_43 ( V_9 ) )
goto V_20;
V_86 = F_55 ( V_11 , V_132 ) ;
V_17 = F_50 ( V_6 , V_86 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_17 ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_133 * V_134 ,
T_5 V_135 )
{
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_21 ( V_9 ) -> V_40 >= 5 ) {
T_1 V_39 ;
V_39 = F_8 ( V_13 -> V_18 ) ;
V_39 &= ~ V_136 ;
V_39 |= V_41 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
F_39 ( V_13 -> V_18 ) ;
F_35 ( L_15 , V_39 ) ;
V_13 -> V_70 = 1 ;
}
}
static int F_77 ( const struct V_137 * V_126 )
{
F_78 ( L_16 , V_126 -> V_138 ) ;
return 1 ;
}
void F_79 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_139 * V_139 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_3 V_18 ;
T_1 V_39 ;
if ( F_80 ( V_140 ) )
return;
if ( F_15 ( V_9 ) )
V_18 = V_141 ;
else if ( F_42 ( V_9 ) )
V_18 = V_142 ;
else
V_18 = V_143 ;
V_39 = F_8 ( V_18 ) ;
if ( ( V_39 & V_19 ) == 0 ) {
F_24 ( V_18 , V_39 | V_19 |
V_46 | V_48 ) ;
if ( ( F_8 ( V_18 ) & V_19 ) == 0 )
return;
F_24 ( V_18 , V_39 ) ;
}
V_13 = F_81 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_13 )
return;
V_139 = F_82 () ;
if ( ! V_139 ) {
F_52 ( V_13 ) ;
return;
}
V_6 = & V_139 -> V_4 ;
V_13 -> V_6 = V_139 ;
F_83 ( V_9 , & V_139 -> V_4 ,
& V_145 , V_146 ) ;
F_84 ( V_9 , & V_13 -> V_4 . V_4 , & V_147 ,
V_148 , NULL ) ;
F_85 ( V_139 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_88 ;
V_13 -> V_4 . V_149 = ( 1 << V_150 ) | ( 1 << V_151 ) ;
if ( F_86 ( V_9 ) )
V_13 -> V_4 . V_152 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_152 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_32 ( V_9 ) )
V_6 -> V_153 = 0 ;
else
V_6 -> V_153 = 1 ;
V_6 -> V_154 = 0 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_4 . V_155 = F_34 ;
if ( F_15 ( V_9 ) ) {
V_13 -> V_4 . V_156 = F_27 ;
V_13 -> V_4 . V_157 = F_28 ;
} else {
V_13 -> V_4 . V_156 = F_26 ;
}
V_13 -> V_4 . V_158 = F_29 ;
if ( F_66 ( V_9 ) )
V_13 -> V_4 . V_159 = V_160 ;
if ( F_36 ( V_9 ) ) {
V_13 -> V_4 . V_161 = F_17 ;
V_13 -> V_4 . V_162 = V_163 ;
} else {
V_13 -> V_4 . V_161 = F_14 ;
V_13 -> V_4 . V_162 = F_5 ;
}
V_139 -> V_162 = V_164 ;
V_139 -> V_165 = V_166 ;
F_87 ( V_6 , & V_167 ) ;
F_88 ( V_6 ) ;
if ( ! F_66 ( V_9 ) )
V_139 -> V_168 = V_169 ;
V_13 -> V_70 = 0 ;
if ( F_22 ( V_9 ) ) {
T_1 V_170 = V_171 |
V_172 ;
V_11 -> V_173 = F_8 ( F_89 ( V_174 ) ) & V_170 ;
}
F_76 ( V_6 ) ;
}
