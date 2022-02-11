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
static void F_18 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_19 ( F_8 ( V_32 ) & V_33 , L_1 ) ;
F_20 ( V_32 ,
V_33 | V_34 | V_35 ) ;
F_21 ( V_32 ) ;
F_22 ( 20 ) ;
}
static void F_23 ( struct V_2 * V_3 , int V_36 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_37 * V_38 = F_24 ( V_3 -> V_4 . V_38 ) ;
struct V_39 * V_29 = & V_38 -> V_40 -> V_4 . V_29 ;
T_1 V_41 ;
if ( F_25 ( V_9 ) -> V_42 >= 5 )
V_41 = V_43 ;
else
V_41 = 0 ;
if ( V_29 -> V_19 & V_21 )
V_41 |= V_20 ;
if ( V_29 -> V_19 & V_24 )
V_41 |= V_23 ;
if ( F_26 ( V_9 ) )
;
else if ( F_9 ( V_9 ) )
V_41 |= F_27 ( V_38 -> V_7 ) ;
else if ( V_38 -> V_7 == 0 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
if ( ! F_14 ( V_9 ) )
F_20 ( F_28 ( V_38 -> V_7 ) , 0 ) ;
switch ( V_36 ) {
case V_46 :
V_41 |= V_18 ;
break;
case V_47 :
V_41 |= V_18 | V_48 ;
break;
case V_49 :
V_41 |= V_18 | V_50 ;
break;
case V_51 :
V_41 |= V_48 | V_50 ;
break;
}
F_20 ( V_13 -> V_17 , V_41 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_51 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
}
static void F_31 ( struct V_2 * V_3 )
{
F_29 ( V_3 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_52 ;
F_33 ( L_2 ) ;
V_52 = F_8 ( V_32 ) ;
F_34 ( ! ( V_52 & V_33 ) ) ;
F_20 ( V_32 , V_52 & ~ V_33 ) ;
F_21 ( V_32 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_23 ( V_3 , V_13 -> V_6 -> V_4 . V_53 ) ;
}
static enum V_54
F_36 ( struct V_5 * V_6 ,
struct V_39 * V_36 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_55 = 0 ;
if ( V_36 -> V_19 & V_56 )
return V_57 ;
if ( V_36 -> clock < 25000 )
return V_58 ;
if ( F_37 ( V_9 ) )
V_55 = 350000 ;
else
V_55 = 400000 ;
if ( V_36 -> clock > V_55 )
return V_59 ;
if ( F_26 ( V_9 ) &&
( F_38 ( V_36 -> clock , 270000 , 24 ) > 2 ) )
return V_59 ;
return V_60 ;
}
static bool F_39 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_14 ( V_9 ) )
V_27 -> V_61 = true ;
if ( F_26 ( V_9 ) )
V_27 -> V_62 = 24 ;
if ( F_40 ( V_9 ) ) {
V_27 -> V_63 = V_64 ;
V_27 -> V_30 = 135000 * 2 ;
}
return true ;
}
static bool F_41 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_41 ;
bool V_65 ;
if ( V_13 -> V_66 ) {
bool V_67 = F_14 ( V_9 ) ;
T_1 V_68 ;
V_13 -> V_66 = 0 ;
V_68 = V_41 = F_8 ( V_13 -> V_17 ) ;
F_33 ( L_3 , V_41 ) ;
V_41 |= V_69 ;
if ( V_67 )
V_41 &= ~ V_18 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
if ( F_42 ( ( F_8 ( V_13 -> V_17 ) & V_69 ) == 0 ,
1000 ) )
F_33 ( L_4 ) ;
if ( V_67 ) {
F_20 ( V_13 -> V_17 , V_68 ) ;
F_21 ( V_13 -> V_17 ) ;
}
}
V_41 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_41 & V_70 ) != 0 )
V_65 = true ;
else
V_65 = false ;
F_33 ( L_5 , V_41 , V_65 ) ;
return V_65 ;
}
static bool F_43 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_41 ;
bool V_65 ;
T_1 V_68 ;
V_68 = V_41 = F_8 ( V_13 -> V_17 ) ;
F_33 ( L_3 , V_41 ) ;
V_41 |= V_69 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
if ( F_42 ( ( F_8 ( V_13 -> V_17 ) & V_69 ) == 0 ,
1000 ) ) {
F_33 ( L_4 ) ;
F_20 ( V_13 -> V_17 , V_68 ) ;
}
V_41 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_41 & V_70 ) != 0 )
V_65 = true ;
else
V_65 = false ;
F_33 ( L_6 , V_41 , V_65 ) ;
return V_65 ;
}
static bool F_44 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_71 , V_72 , V_73 ;
bool V_65 = false ;
int V_74 , V_75 = 0 ;
if ( F_14 ( V_9 ) )
return F_41 ( V_6 ) ;
if ( F_45 ( V_9 ) )
return F_43 ( V_6 ) ;
if ( F_46 ( V_9 ) && ! F_47 ( V_9 ) )
V_75 = 2 ;
else
V_75 = 1 ;
V_71 = V_72 = F_8 ( V_76 ) ;
V_71 |= V_77 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
F_20 ( V_76 , V_71 ) ;
if ( F_42 ( ( F_8 ( V_76 ) &
V_77 ) == 0 ,
1000 ) )
F_33 ( L_7 ) ;
}
V_73 = F_8 ( V_78 ) ;
if ( ( V_73 & V_79 ) != V_80 )
V_65 = true ;
F_20 ( V_78 , V_81 ) ;
F_20 ( V_76 , V_72 ) ;
return V_65 ;
}
static struct V_82 * F_48 ( struct V_5 * V_6 ,
struct V_83 * V_84 )
{
struct V_82 * V_82 ;
V_82 = F_49 ( V_6 , V_84 ) ;
if ( ! V_82 && ! F_50 ( V_84 ) ) {
F_33 ( L_8 ) ;
F_51 ( V_84 , true ) ;
V_82 = F_49 ( V_6 , V_84 ) ;
F_51 ( V_84 , false ) ;
}
return V_82 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_83 * V_85 )
{
struct V_82 * V_82 ;
int V_65 ;
V_82 = F_48 ( V_6 , V_85 ) ;
if ( ! V_82 )
return 0 ;
V_65 = F_53 ( V_6 , V_82 ) ;
F_54 ( V_82 ) ;
return V_65 ;
}
static bool F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
F_56 ( V_13 -> V_4 . type != V_86 ) ;
V_84 = F_57 ( V_11 , V_11 -> V_87 . V_88 ) ;
V_82 = F_48 ( V_6 , V_84 ) ;
if ( V_82 ) {
bool V_89 = V_82 -> V_90 & V_91 ;
if ( ! V_89 ) {
F_33 ( L_9 ) ;
return true ;
}
F_33 ( L_10 ) ;
} else {
F_33 ( L_11 ) ;
}
F_54 ( V_82 ) ;
return false ;
}
static enum V_92
F_58 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_24 ( V_13 -> V_4 . V_4 . V_38 ) -> V_7 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 , V_96 ;
T_2 V_97 ;
T_2 V_98 , V_99 , V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
T_2 V_104 ;
T_2 V_105 ;
T_2 V_106 ;
T_2 V_107 ;
T_3 V_108 ;
enum V_92 V_109 ;
F_33 ( L_12 ) ;
V_102 = F_28 ( V_7 ) ;
V_103 = F_59 ( V_7 ) ;
V_104 = F_60 ( V_7 ) ;
V_105 = F_61 ( V_7 ) ;
V_106 = F_62 ( V_7 ) ;
V_107 = F_63 ( V_7 ) ;
V_93 = F_8 ( V_102 ) ;
V_94 = F_8 ( V_103 ) ;
V_98 = F_8 ( V_104 ) ;
V_95 = ( ( V_94 >> 16 ) & 0xfff ) + 1 ;
V_96 = ( V_94 & 0x7ff ) + 1 ;
V_99 = ( V_98 & 0xfff ) + 1 ;
V_100 = ( ( V_98 >> 16 ) & 0xfff ) + 1 ;
F_20 ( V_102 , 0x500050 ) ;
if ( ! F_37 ( V_9 ) ) {
T_2 V_110 = F_8 ( V_106 ) ;
F_20 ( V_106 , V_110 | V_111 ) ;
F_21 ( V_106 ) ;
F_64 ( V_9 , V_7 ) ;
V_108 = F_65 ( V_112 ) ;
V_109 = ( ( V_108 & ( 1 << 4 ) ) != 0 ) ?
V_113 :
V_114 ;
F_20 ( V_106 , V_110 ) ;
} else {
bool V_115 = false ;
int V_116 , V_117 ;
if ( V_99 <= V_96 && V_100 >= V_95 ) {
T_2 V_118 = F_8 ( V_105 ) ;
T_2 V_119 = ( V_118 & 0xffff ) + 1 ;
V_99 = V_119 ;
F_20 ( V_104 ,
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
V_108 = F_65 ( V_112 ) ;
if ( V_108 & ( 1 << 4 ) )
V_117 ++ ;
} while ( ( F_8 ( V_107 ) == V_101 ) );
if ( V_115 )
F_20 ( V_104 , V_98 ) ;
V_109 = V_117 * 4 > V_116 * 3 ?
V_113 :
V_114 ;
}
F_20 ( V_102 , V_93 ) ;
return V_109 ;
}
static enum V_92
F_66 ( struct V_5 * V_6 , bool V_120 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_92 V_109 ;
struct V_121 V_16 ;
struct V_122 V_123 ;
F_33 ( L_13 ,
V_6 -> V_4 . V_124 , V_6 -> V_125 ,
V_120 ) ;
V_15 = F_6 ( V_2 ) ;
F_67 ( V_11 , V_15 ) ;
if ( F_68 ( V_9 ) ) {
if ( F_44 ( V_6 ) ) {
F_33 ( L_14 ) ;
V_109 = V_113 ;
goto V_126;
} else
F_33 ( L_15 ) ;
}
if ( F_55 ( V_6 ) ) {
V_109 = V_113 ;
goto V_126;
}
if ( F_68 ( V_9 ) && ! V_127 . V_128 ) {
V_109 = V_114 ;
goto V_126;
}
if ( ! V_120 ) {
V_109 = V_6 -> V_109 ;
goto V_126;
}
F_69 ( & V_123 , 0 ) ;
if ( F_70 ( V_6 , NULL , & V_16 , & V_123 ) ) {
if ( F_55 ( V_6 ) )
V_109 = V_113 ;
else if ( F_25 ( V_9 ) -> V_42 < 4 )
V_109 = F_58 ( V_13 ) ;
else
V_109 = V_129 ;
F_71 ( V_6 , & V_16 , & V_123 ) ;
} else
V_109 = V_129 ;
F_72 ( & V_123 ) ;
F_73 ( & V_123 ) ;
V_126:
F_74 ( V_11 , V_15 ) ;
return V_109 ;
}
static void F_75 ( struct V_5 * V_6 )
{
F_76 ( V_6 ) ;
F_54 ( V_6 ) ;
}
static int F_77 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_65 ;
struct V_83 * V_84 ;
V_15 = F_6 ( V_2 ) ;
F_67 ( V_11 , V_15 ) ;
V_84 = F_57 ( V_11 , V_11 -> V_87 . V_88 ) ;
V_65 = F_52 ( V_6 , V_84 ) ;
if ( V_65 || ! F_46 ( V_9 ) )
goto V_126;
V_84 = F_57 ( V_11 , V_130 ) ;
V_65 = F_52 ( V_6 , V_84 ) ;
V_126:
F_74 ( V_11 , V_15 ) ;
return V_65 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_131 * V_132 ,
T_4 V_133 )
{
return 0 ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_25 ( V_9 ) -> V_42 >= 5 ) {
T_1 V_41 ;
V_41 = F_8 ( V_13 -> V_17 ) ;
V_41 &= ~ V_134 ;
V_41 |= V_43 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
F_21 ( V_13 -> V_17 ) ;
F_33 ( L_16 , V_41 ) ;
V_13 -> V_66 = 1 ;
}
}
static int F_80 ( const struct V_135 * V_124 )
{
F_81 ( L_17 , V_124 -> V_136 ) ;
return 1 ;
}
void F_82 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_137 * V_137 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_83 ( V_138 ) )
return;
V_13 = F_84 ( sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_13 )
return;
V_137 = F_85 () ;
if ( ! V_137 ) {
F_54 ( V_13 ) ;
return;
}
V_6 = & V_137 -> V_4 ;
V_13 -> V_6 = V_137 ;
F_86 ( V_9 , & V_137 -> V_4 ,
& V_140 , V_141 ) ;
F_87 ( V_9 , & V_13 -> V_4 . V_4 , & V_142 ,
V_143 ) ;
F_88 ( V_137 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_86 ;
V_13 -> V_4 . V_144 = ( 1 << V_145 ) | ( 1 << V_146 ) ;
if ( F_89 ( V_9 ) )
V_13 -> V_4 . V_147 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_147 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_37 ( V_9 ) )
V_6 -> V_148 = 0 ;
else
V_6 -> V_148 = 1 ;
V_6 -> V_149 = 0 ;
if ( F_14 ( V_9 ) )
V_13 -> V_17 = V_150 ;
else if ( F_45 ( V_9 ) )
V_13 -> V_17 = V_151 ;
else
V_13 -> V_17 = V_152 ;
V_13 -> V_4 . V_153 = F_39 ;
if ( F_14 ( V_9 ) && ! F_40 ( V_9 ) ) {
V_13 -> V_4 . V_154 = F_30 ;
V_13 -> V_4 . V_155 = F_31 ;
} else {
V_13 -> V_4 . V_154 = F_29 ;
}
V_13 -> V_4 . V_156 = F_35 ;
if ( F_68 ( V_9 ) )
V_13 -> V_4 . V_157 = V_158 ;
if ( F_40 ( V_9 ) ) {
V_13 -> V_4 . V_159 = F_16 ;
V_13 -> V_4 . V_160 = V_161 ;
V_13 -> V_4 . V_162 = F_18 ;
V_13 -> V_4 . V_155 = F_32 ;
} else {
V_13 -> V_4 . V_159 = F_13 ;
V_13 -> V_4 . V_160 = F_5 ;
}
V_137 -> V_160 = V_163 ;
V_137 -> V_164 = V_165 ;
F_90 ( V_6 , & V_166 ) ;
F_91 ( V_6 ) ;
if ( ! F_68 ( V_9 ) )
V_137 -> V_167 = V_168 ;
V_13 -> V_66 = 0 ;
if ( F_26 ( V_9 ) ) {
T_1 V_169 = V_170 |
V_171 ;
V_11 -> V_172 = F_8 ( V_173 ) & V_169 ;
}
F_79 ( V_6 ) ;
}
