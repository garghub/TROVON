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
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_19 ( V_3 , V_13 -> V_6 -> V_4 . V_50 ) ;
}
static enum V_51
F_30 ( struct V_5 * V_6 ,
struct V_37 * V_34 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_52 = 0 ;
if ( V_34 -> V_21 & V_53 )
return V_54 ;
if ( V_34 -> clock < 25000 )
return V_55 ;
if ( F_31 ( V_9 ) )
V_52 = 350000 ;
else
V_52 = 400000 ;
if ( V_34 -> clock > V_52 )
return V_56 ;
if ( F_22 ( V_9 ) &&
( F_32 ( V_34 -> clock , 270000 , 24 ) > 2 ) )
return V_56 ;
return V_57 ;
}
static bool F_33 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_15 ( V_9 ) )
V_29 -> V_58 = true ;
if ( F_22 ( V_9 ) )
V_29 -> V_59 = 24 ;
if ( F_34 ( V_9 ) ) {
V_29 -> V_60 = V_61 ;
V_29 -> V_32 = 135000 * 2 ;
V_29 -> V_62 . V_63 = 0 ;
V_29 -> V_62 . V_64 =
V_65 | V_66 | V_67 ;
}
return true ;
}
static bool F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_39 ;
bool V_17 ;
if ( V_13 -> V_68 ) {
bool V_69 = F_15 ( V_9 ) ;
T_1 V_70 ;
V_13 -> V_68 = 0 ;
V_70 = V_39 = F_8 ( V_13 -> V_18 ) ;
F_36 ( L_1 , V_39 ) ;
V_39 |= V_71 ;
if ( V_69 )
V_39 &= ~ V_19 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
if ( F_37 ( ( F_8 ( V_13 -> V_18 ) & V_71 ) == 0 ,
1000 ) )
F_36 ( L_2 ) ;
if ( V_69 ) {
F_24 ( V_13 -> V_18 , V_70 ) ;
F_38 ( V_13 -> V_18 ) ;
}
}
V_39 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_39 & V_72 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_36 ( L_3 , V_39 , V_17 ) ;
return V_17 ;
}
static bool F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_39 ;
bool V_17 ;
T_1 V_70 ;
V_70 = V_39 = F_8 ( V_13 -> V_18 ) ;
F_36 ( L_1 , V_39 ) ;
V_39 |= V_71 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
if ( F_37 ( ( F_8 ( V_13 -> V_18 ) & V_71 ) == 0 ,
1000 ) ) {
F_36 ( L_2 ) ;
F_24 ( V_13 -> V_18 , V_70 ) ;
}
V_39 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_39 & V_72 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_36 ( L_4 , V_39 , V_17 ) ;
return V_17 ;
}
static bool F_40 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_73 ;
bool V_17 = false ;
int V_74 , V_75 = 0 ;
if ( F_15 ( V_9 ) )
return F_35 ( V_6 ) ;
if ( F_41 ( V_9 ) )
return F_39 ( V_6 ) ;
if ( F_42 ( V_9 ) && ! F_43 ( V_9 ) )
V_75 = 2 ;
else
V_75 = 1 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
F_44 ( V_11 ,
V_76 ,
V_76 ) ;
if ( F_37 ( ( F_8 ( V_77 ) &
V_76 ) == 0 ,
1000 ) )
F_36 ( L_5 ) ;
}
V_73 = F_8 ( V_78 ) ;
if ( ( V_73 & V_79 ) != V_80 )
V_17 = true ;
F_24 ( V_78 , V_81 ) ;
F_44 ( V_11 , V_76 , 0 ) ;
return V_17 ;
}
static struct V_82 * F_45 ( struct V_5 * V_6 ,
struct V_83 * V_84 )
{
struct V_82 * V_82 ;
V_82 = F_46 ( V_6 , V_84 ) ;
if ( ! V_82 && ! F_47 ( V_84 ) ) {
F_36 ( L_6 ) ;
F_48 ( V_84 , true ) ;
V_82 = F_46 ( V_6 , V_84 ) ;
F_48 ( V_84 , false ) ;
}
return V_82 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_83 * V_85 )
{
struct V_82 * V_82 ;
int V_17 ;
V_82 = F_45 ( V_6 , V_85 ) ;
if ( ! V_82 )
return 0 ;
V_17 = F_50 ( V_6 , V_82 ) ;
F_51 ( V_82 ) ;
return V_17 ;
}
static bool F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
F_53 ( V_13 -> V_4 . type != V_86 ) ;
V_84 = F_54 ( V_11 , V_11 -> V_87 . V_88 ) ;
V_82 = F_45 ( V_6 , V_84 ) ;
if ( V_82 ) {
bool V_89 = V_82 -> V_90 & V_91 ;
if ( ! V_89 ) {
F_36 ( L_7 ) ;
return true ;
}
F_36 ( L_8 ) ;
} else {
F_36 ( L_9 ) ;
}
F_51 ( V_82 ) ;
return false ;
}
static enum V_92
F_55 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_20 ( V_13 -> V_4 . V_4 . V_36 ) -> V_7 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 , V_96 ;
T_2 V_97 ;
T_2 V_98 , V_99 , V_100 ;
T_2 V_101 ;
T_3 V_102 , V_103 ,
V_104 , V_105 , V_106 , V_107 ;
T_4 V_108 ;
enum V_92 V_109 ;
F_36 ( L_10 ) ;
V_102 = F_25 ( V_7 ) ;
V_103 = F_56 ( V_7 ) ;
V_104 = F_57 ( V_7 ) ;
V_105 = F_58 ( V_7 ) ;
V_106 = F_59 ( V_7 ) ;
V_107 = F_60 ( V_7 ) ;
V_93 = F_8 ( V_102 ) ;
V_94 = F_8 ( V_103 ) ;
V_98 = F_8 ( V_104 ) ;
V_95 = ( ( V_94 >> 16 ) & 0xfff ) + 1 ;
V_96 = ( V_94 & 0x7ff ) + 1 ;
V_99 = ( V_98 & 0xfff ) + 1 ;
V_100 = ( ( V_98 >> 16 ) & 0xfff ) + 1 ;
F_24 ( V_102 , 0x500050 ) ;
if ( ! F_31 ( V_9 ) ) {
T_2 V_110 = F_8 ( V_106 ) ;
F_24 ( V_106 , V_110 | V_111 ) ;
F_38 ( V_106 ) ;
F_61 ( V_9 , V_7 ) ;
V_108 = F_62 ( V_112 ) ;
V_109 = ( ( V_108 & ( 1 << 4 ) ) != 0 ) ?
V_113 :
V_114 ;
F_24 ( V_106 , V_110 ) ;
} else {
bool V_115 = false ;
int V_116 , V_117 ;
if ( V_99 <= V_96 && V_100 >= V_95 ) {
T_2 V_118 = F_8 ( V_105 ) ;
T_2 V_119 = ( V_118 & 0xffff ) + 1 ;
V_99 = V_119 ;
F_24 ( V_104 ,
( V_99 - 1 ) |
( ( V_100 - 1 ) << 16 ) ) ;
V_115 = true ;
}
if ( V_99 - V_96 >= V_95 - V_100 )
V_97 = ( V_99 + V_96 ) >> 1 ;
else
V_97 = ( V_95 + V_100 ) >> 1 ;
while ( F_8 ( V_107 ) >= V_96 )
;
while ( ( V_101 = F_8 ( V_107 ) ) <= V_97 )
;
V_117 = 0 ;
V_116 = 0 ;
do {
V_116 ++ ;
V_108 = F_62 ( V_112 ) ;
if ( V_108 & ( 1 << 4 ) )
V_117 ++ ;
} while ( ( F_8 ( V_107 ) == V_101 ) );
if ( V_115 )
F_24 ( V_104 , V_98 ) ;
V_109 = V_117 * 4 > V_116 * 3 ?
V_113 :
V_114 ;
}
F_24 ( V_102 , V_93 ) ;
return V_109 ;
}
static enum V_92
F_63 ( struct V_5 * V_6 , bool V_120 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_92 V_109 ;
struct V_121 V_16 ;
struct V_122 V_123 ;
F_36 ( L_11 ,
V_6 -> V_4 . V_124 , V_6 -> V_125 ,
V_120 ) ;
V_15 = F_6 ( V_2 ) ;
F_64 ( V_11 , V_15 ) ;
if ( F_65 ( V_9 ) ) {
if ( F_40 ( V_6 ) ) {
F_36 ( L_12 ) ;
V_109 = V_113 ;
goto V_20;
} else
F_36 ( L_13 ) ;
}
if ( F_52 ( V_6 ) ) {
V_109 = V_113 ;
goto V_20;
}
if ( F_65 ( V_9 ) && ! V_126 . V_127 ) {
V_109 = V_114 ;
goto V_20;
}
if ( ! V_120 ) {
V_109 = V_6 -> V_109 ;
goto V_20;
}
F_66 ( & V_123 , 0 ) ;
if ( F_67 ( V_6 , NULL , & V_16 , & V_123 ) ) {
if ( F_52 ( V_6 ) )
V_109 = V_113 ;
else if ( F_21 ( V_9 ) -> V_40 < 4 )
V_109 = F_55 ( V_13 ) ;
else
V_109 = V_128 ;
F_68 ( V_6 , & V_16 , & V_123 ) ;
} else
V_109 = V_128 ;
F_69 ( & V_123 ) ;
F_70 ( & V_123 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_109 ;
}
static void F_71 ( struct V_5 * V_6 )
{
F_72 ( V_6 ) ;
F_51 ( V_6 ) ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_17 ;
struct V_83 * V_84 ;
V_15 = F_6 ( V_2 ) ;
F_64 ( V_11 , V_15 ) ;
V_84 = F_54 ( V_11 , V_11 -> V_87 . V_88 ) ;
V_17 = F_49 ( V_6 , V_84 ) ;
if ( V_17 || ! F_42 ( V_9 ) )
goto V_20;
V_84 = F_54 ( V_11 , V_129 ) ;
V_17 = F_49 ( V_6 , V_84 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_17 ;
}
static int F_74 ( struct V_5 * V_6 ,
struct V_130 * V_131 ,
T_5 V_132 )
{
return 0 ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_21 ( V_9 ) -> V_40 >= 5 ) {
T_1 V_39 ;
V_39 = F_8 ( V_13 -> V_18 ) ;
V_39 &= ~ V_133 ;
V_39 |= V_41 ;
F_24 ( V_13 -> V_18 , V_39 ) ;
F_38 ( V_13 -> V_18 ) ;
F_36 ( L_14 , V_39 ) ;
V_13 -> V_68 = 1 ;
}
}
static int F_76 ( const struct V_134 * V_124 )
{
F_77 ( L_15 , V_124 -> V_135 ) ;
return 1 ;
}
void F_78 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_136 * V_136 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_3 V_18 ;
T_1 V_39 ;
if ( F_79 ( V_137 ) )
return;
if ( F_15 ( V_9 ) )
V_18 = V_138 ;
else if ( F_41 ( V_9 ) )
V_18 = V_139 ;
else
V_18 = V_140 ;
V_39 = F_8 ( V_18 ) ;
if ( ( V_39 & V_19 ) == 0 ) {
F_24 ( V_18 , V_39 | V_19 |
V_46 | V_48 ) ;
if ( ( F_8 ( V_18 ) & V_19 ) == 0 )
return;
F_24 ( V_18 , V_39 ) ;
}
V_13 = F_80 ( sizeof( struct V_1 ) , V_141 ) ;
if ( ! V_13 )
return;
V_136 = F_81 () ;
if ( ! V_136 ) {
F_51 ( V_13 ) ;
return;
}
V_6 = & V_136 -> V_4 ;
V_13 -> V_6 = V_136 ;
F_82 ( V_9 , & V_136 -> V_4 ,
& V_142 , V_143 ) ;
F_83 ( V_9 , & V_13 -> V_4 . V_4 , & V_144 ,
V_145 , NULL ) ;
F_84 ( V_136 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_86 ;
V_13 -> V_4 . V_146 = ( 1 << V_147 ) | ( 1 << V_148 ) ;
if ( F_85 ( V_9 ) )
V_13 -> V_4 . V_149 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_149 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_31 ( V_9 ) )
V_6 -> V_150 = 0 ;
else
V_6 -> V_150 = 1 ;
V_6 -> V_151 = 0 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_4 . V_152 = F_33 ;
if ( F_15 ( V_9 ) ) {
V_13 -> V_4 . V_153 = F_27 ;
V_13 -> V_4 . V_154 = F_28 ;
} else {
V_13 -> V_4 . V_153 = F_26 ;
}
V_13 -> V_4 . V_155 = F_29 ;
if ( F_65 ( V_9 ) )
V_13 -> V_4 . V_156 = V_157 ;
if ( F_34 ( V_9 ) ) {
V_13 -> V_4 . V_158 = F_17 ;
V_13 -> V_4 . V_159 = V_160 ;
} else {
V_13 -> V_4 . V_158 = F_14 ;
V_13 -> V_4 . V_159 = F_5 ;
}
V_136 -> V_159 = V_161 ;
V_136 -> V_162 = V_163 ;
F_86 ( V_6 , & V_164 ) ;
F_87 ( V_6 ) ;
if ( ! F_65 ( V_9 ) )
V_136 -> V_165 = V_166 ;
V_13 -> V_68 = 0 ;
if ( F_22 ( V_9 ) ) {
T_1 V_167 = V_168 |
V_169 ;
V_11 -> V_170 = F_8 ( F_88 ( V_171 ) ) & V_167 ;
}
F_75 ( V_6 ) ;
}
