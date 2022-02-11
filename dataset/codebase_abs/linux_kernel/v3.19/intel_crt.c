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
V_27 -> V_29 . V_19 |= F_12 ( V_3 ) ;
V_28 = V_27 -> V_30 ;
if ( F_14 ( V_9 ) )
F_15 ( V_27 , V_28 ) ;
V_27 -> V_29 . V_31 = V_28 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
F_17 ( V_3 , V_27 ) ;
V_27 -> V_29 . V_19 &= ~ ( V_21 |
V_22 |
V_24 |
V_25 ) ;
V_27 -> V_29 . V_19 |= F_12 ( V_3 ) ;
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
struct V_39 * V_29 = & V_38 -> V_40 . V_29 ;
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
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_52 ;
F_31 ( L_2 ) ;
V_52 = F_8 ( V_32 ) ;
F_32 ( ! ( V_52 & V_33 ) ) ;
F_20 ( V_32 , V_52 & ~ V_33 ) ;
F_21 ( V_32 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_23 ( V_3 , V_13 -> V_6 -> V_4 . V_53 ) ;
}
static void F_34 ( struct V_5 * V_6 , int V_36 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_54 * V_38 ;
int V_55 ;
if ( F_25 ( V_9 ) -> V_42 >= 5 && V_36 != V_46 )
V_36 = V_51 ;
if ( V_36 == V_6 -> V_53 )
return;
V_55 = V_6 -> V_53 ;
V_6 -> V_53 = V_36 ;
V_38 = V_3 -> V_4 . V_38 ;
if ( ! V_38 ) {
V_3 -> V_56 = false ;
return;
}
if ( V_36 == V_51 )
V_3 -> V_56 = false ;
else
V_3 -> V_56 = true ;
if ( V_36 < V_55 ) {
F_35 ( V_38 ) ;
F_23 ( V_3 , V_36 ) ;
} else {
F_23 ( V_3 , V_36 ) ;
F_35 ( V_38 ) ;
}
F_36 ( V_6 -> V_9 ) ;
}
static enum V_57
F_37 ( struct V_5 * V_6 ,
struct V_39 * V_36 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_58 = 0 ;
if ( V_36 -> V_19 & V_59 )
return V_60 ;
if ( V_36 -> clock < 25000 )
return V_61 ;
if ( F_38 ( V_9 ) )
V_58 = 350000 ;
else
V_58 = 400000 ;
if ( V_36 -> clock > V_58 )
return V_62 ;
if ( F_26 ( V_9 ) &&
( F_39 ( V_36 -> clock , 270000 , 24 ) > 2 ) )
return V_62 ;
return V_63 ;
}
static bool F_40 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_14 ( V_9 ) )
V_27 -> V_64 = true ;
if ( F_26 ( V_9 ) )
V_27 -> V_65 = 24 ;
if ( F_41 ( V_9 ) ) {
V_27 -> V_66 = V_67 ;
V_27 -> V_30 = 135000 * 2 ;
}
return true ;
}
static bool F_42 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_41 ;
bool V_68 ;
if ( V_13 -> V_69 ) {
bool V_70 = F_14 ( V_9 ) ;
T_1 V_71 ;
V_13 -> V_69 = 0 ;
V_71 = V_41 = F_8 ( V_13 -> V_17 ) ;
F_31 ( L_3 , V_41 ) ;
V_41 |= V_72 ;
if ( V_70 )
V_41 &= ~ V_18 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
if ( F_43 ( ( F_8 ( V_13 -> V_17 ) & V_72 ) == 0 ,
1000 ) )
F_31 ( L_4 ) ;
if ( V_70 ) {
F_20 ( V_13 -> V_17 , V_71 ) ;
F_21 ( V_13 -> V_17 ) ;
}
}
V_41 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_41 & V_73 ) != 0 )
V_68 = true ;
else
V_68 = false ;
F_31 ( L_5 , V_41 , V_68 ) ;
return V_68 ;
}
static bool F_44 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_41 ;
bool V_68 ;
T_1 V_71 ;
V_71 = V_41 = F_8 ( V_13 -> V_17 ) ;
F_31 ( L_3 , V_41 ) ;
V_41 |= V_72 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
if ( F_43 ( ( F_8 ( V_13 -> V_17 ) & V_72 ) == 0 ,
1000 ) ) {
F_31 ( L_4 ) ;
F_20 ( V_13 -> V_17 , V_71 ) ;
}
V_41 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_41 & V_73 ) != 0 )
V_68 = true ;
else
V_68 = false ;
F_31 ( L_6 , V_41 , V_68 ) ;
return V_68 ;
}
static bool F_45 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_74 , V_75 , V_76 ;
bool V_68 = false ;
int V_77 , V_78 = 0 ;
if ( F_14 ( V_9 ) )
return F_42 ( V_6 ) ;
if ( F_46 ( V_9 ) )
return F_44 ( V_6 ) ;
if ( F_47 ( V_9 ) && ! F_48 ( V_9 ) )
V_78 = 2 ;
else
V_78 = 1 ;
V_74 = V_75 = F_8 ( V_79 ) ;
V_74 |= V_80 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
F_20 ( V_79 , V_74 ) ;
if ( F_43 ( ( F_8 ( V_79 ) &
V_80 ) == 0 ,
1000 ) )
F_31 ( L_7 ) ;
}
V_76 = F_8 ( V_81 ) ;
if ( ( V_76 & V_82 ) != V_83 )
V_68 = true ;
F_20 ( V_81 , V_84 ) ;
F_20 ( V_79 , V_75 ) ;
return V_68 ;
}
static struct V_85 * F_49 ( struct V_5 * V_6 ,
struct V_86 * V_87 )
{
struct V_85 * V_85 ;
V_85 = F_50 ( V_6 , V_87 ) ;
if ( ! V_85 && ! F_51 ( V_87 ) ) {
F_31 ( L_8 ) ;
F_52 ( V_87 , true ) ;
V_85 = F_50 ( V_6 , V_87 ) ;
F_52 ( V_87 , false ) ;
}
return V_85 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_86 * V_88 )
{
struct V_85 * V_85 ;
int V_68 ;
V_85 = F_49 ( V_6 , V_88 ) ;
if ( ! V_85 )
return 0 ;
V_68 = F_54 ( V_6 , V_85 ) ;
F_55 ( V_85 ) ;
return V_68 ;
}
static bool F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_85 * V_85 ;
struct V_86 * V_87 ;
F_57 ( V_13 -> V_4 . type != V_89 ) ;
V_87 = F_58 ( V_11 , V_11 -> V_90 . V_91 ) ;
V_85 = F_49 ( V_6 , V_87 ) ;
if ( V_85 ) {
bool V_92 = V_85 -> V_93 & V_94 ;
if ( ! V_92 ) {
F_31 ( L_9 ) ;
return true ;
}
F_31 ( L_10 ) ;
} else {
F_31 ( L_11 ) ;
}
F_55 ( V_85 ) ;
return false ;
}
static enum V_95
F_59 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_24 ( V_13 -> V_4 . V_4 . V_38 ) -> V_7 ;
T_2 V_96 ;
T_2 V_97 ;
T_2 V_98 , V_99 ;
T_2 V_100 ;
T_2 V_101 , V_102 , V_103 ;
T_2 V_104 ;
T_2 V_105 ;
T_2 V_106 ;
T_2 V_107 ;
T_2 V_108 ;
T_2 V_109 ;
T_2 V_110 ;
T_3 V_111 ;
enum V_95 V_112 ;
F_31 ( L_12 ) ;
V_105 = F_28 ( V_7 ) ;
V_106 = F_60 ( V_7 ) ;
V_107 = F_61 ( V_7 ) ;
V_108 = F_62 ( V_7 ) ;
V_109 = F_63 ( V_7 ) ;
V_110 = F_64 ( V_7 ) ;
V_96 = F_8 ( V_105 ) ;
V_97 = F_8 ( V_106 ) ;
V_101 = F_8 ( V_107 ) ;
V_98 = ( ( V_97 >> 16 ) & 0xfff ) + 1 ;
V_99 = ( V_97 & 0x7ff ) + 1 ;
V_102 = ( V_101 & 0xfff ) + 1 ;
V_103 = ( ( V_101 >> 16 ) & 0xfff ) + 1 ;
F_20 ( V_105 , 0x500050 ) ;
if ( ! F_38 ( V_9 ) ) {
T_2 V_113 = F_8 ( V_109 ) ;
F_20 ( V_109 , V_113 | V_114 ) ;
F_21 ( V_109 ) ;
F_65 ( V_9 , V_7 ) ;
V_111 = F_66 ( V_115 ) ;
V_112 = ( ( V_111 & ( 1 << 4 ) ) != 0 ) ?
V_116 :
V_117 ;
F_20 ( V_109 , V_113 ) ;
} else {
bool V_118 = false ;
int V_119 , V_120 ;
if ( V_102 <= V_99 && V_103 >= V_98 ) {
T_2 V_121 = F_8 ( V_108 ) ;
T_2 V_122 = ( V_121 & 0xffff ) + 1 ;
V_102 = V_122 ;
F_20 ( V_107 ,
( V_102 - 1 ) |
( ( V_103 - 1 ) << 16 ) ) ;
V_118 = true ;
}
if ( V_102 - V_99 >= V_98 - V_103 )
V_100 = ( V_102 + V_99 ) >> 1 ;
else
V_100 = ( V_98 + V_103 ) >> 1 ;
while ( F_8 ( V_110 ) >= V_99 )
;
while ( ( V_104 = F_8 ( V_110 ) ) <= V_100 )
;
V_120 = 0 ;
V_119 = 0 ;
do {
V_119 ++ ;
V_111 = F_66 ( V_115 ) ;
if ( V_111 & ( 1 << 4 ) )
V_120 ++ ;
} while ( ( F_8 ( V_110 ) == V_104 ) );
if ( V_118 )
F_20 ( V_107 , V_101 ) ;
V_112 = V_120 * 4 > V_119 * 3 ?
V_116 :
V_117 ;
}
F_20 ( V_105 , V_96 ) ;
return V_112 ;
}
static enum V_95
F_67 ( struct V_5 * V_6 , bool V_123 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_95 V_112 ;
struct V_124 V_16 ;
struct V_125 V_126 ;
F_31 ( L_13 ,
V_6 -> V_4 . V_127 , V_6 -> V_128 ,
V_123 ) ;
V_15 = F_6 ( V_2 ) ;
F_68 ( V_11 , V_15 ) ;
if ( F_69 ( V_9 ) ) {
if ( F_45 ( V_6 ) ) {
F_31 ( L_14 ) ;
V_112 = V_116 ;
goto V_129;
} else
F_31 ( L_15 ) ;
}
if ( F_56 ( V_6 ) ) {
V_112 = V_116 ;
goto V_129;
}
if ( F_69 ( V_9 ) ) {
V_112 = V_117 ;
goto V_129;
}
if ( ! V_123 ) {
V_112 = V_6 -> V_112 ;
goto V_129;
}
F_70 ( & V_126 , 0 ) ;
if ( F_71 ( V_6 , NULL , & V_16 , & V_126 ) ) {
if ( F_56 ( V_6 ) )
V_112 = V_116 ;
else
V_112 = F_59 ( V_13 ) ;
F_72 ( V_6 , & V_16 ) ;
} else
V_112 = V_130 ;
F_73 ( & V_126 ) ;
F_74 ( & V_126 ) ;
V_129:
F_75 ( V_11 , V_15 ) ;
return V_112 ;
}
static void F_76 ( struct V_5 * V_6 )
{
F_77 ( V_6 ) ;
F_55 ( V_6 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_68 ;
struct V_86 * V_87 ;
V_15 = F_6 ( V_2 ) ;
F_68 ( V_11 , V_15 ) ;
V_87 = F_58 ( V_11 , V_11 -> V_90 . V_91 ) ;
V_68 = F_53 ( V_6 , V_87 ) ;
if ( V_68 || ! F_47 ( V_9 ) )
goto V_129;
V_87 = F_58 ( V_11 , V_131 ) ;
V_68 = F_53 ( V_6 , V_87 ) ;
V_129:
F_75 ( V_11 , V_15 ) ;
return V_68 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_132 * V_133 ,
T_4 V_134 )
{
return 0 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_25 ( V_9 ) -> V_42 >= 5 ) {
T_1 V_41 ;
V_41 = F_8 ( V_13 -> V_17 ) ;
V_41 &= ~ V_135 ;
V_41 |= V_43 ;
F_20 ( V_13 -> V_17 , V_41 ) ;
F_21 ( V_13 -> V_17 ) ;
F_31 ( L_16 , V_41 ) ;
V_13 -> V_69 = 1 ;
}
}
static int F_81 ( const struct V_136 * V_127 )
{
F_82 ( L_17 , V_127 -> V_137 ) ;
return 1 ;
}
void F_83 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_138 * V_138 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_84 ( V_139 ) )
return;
V_13 = F_85 ( sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_13 )
return;
V_138 = F_85 ( sizeof( * V_138 ) , V_140 ) ;
if ( ! V_138 ) {
F_55 ( V_13 ) ;
return;
}
V_6 = & V_138 -> V_4 ;
V_13 -> V_6 = V_138 ;
F_86 ( V_9 , & V_138 -> V_4 ,
& V_141 , V_142 ) ;
F_87 ( V_9 , & V_13 -> V_4 . V_4 , & V_143 ,
V_144 ) ;
F_88 ( V_138 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_89 ;
V_13 -> V_4 . V_145 = ( 1 << V_146 ) | ( 1 << V_147 ) ;
if ( F_89 ( V_9 ) )
V_13 -> V_4 . V_148 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_148 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_38 ( V_9 ) )
V_6 -> V_149 = 0 ;
else
V_6 -> V_149 = 1 ;
V_6 -> V_150 = 0 ;
if ( F_14 ( V_9 ) )
V_13 -> V_17 = V_151 ;
else if ( F_46 ( V_9 ) )
V_13 -> V_17 = V_152 ;
else
V_13 -> V_17 = V_153 ;
V_13 -> V_4 . V_154 = F_40 ;
V_13 -> V_4 . V_155 = F_29 ;
V_13 -> V_4 . V_156 = F_33 ;
if ( F_69 ( V_9 ) )
V_13 -> V_4 . V_157 = V_158 ;
if ( F_41 ( V_9 ) ) {
V_13 -> V_4 . V_159 = F_16 ;
V_13 -> V_4 . V_160 = V_161 ;
V_13 -> V_4 . V_162 = F_18 ;
V_13 -> V_4 . V_163 = F_30 ;
} else {
V_13 -> V_4 . V_159 = F_13 ;
V_13 -> V_4 . V_160 = F_5 ;
}
V_138 -> V_160 = V_164 ;
V_138 -> V_165 = V_166 ;
F_90 ( V_6 , & V_167 ) ;
F_91 ( V_6 ) ;
if ( ! F_69 ( V_9 ) )
V_138 -> V_168 = V_169 ;
V_13 -> V_69 = 0 ;
if ( F_26 ( V_9 ) ) {
T_1 V_170 = V_171 |
V_172 ;
V_11 -> V_173 = F_8 ( V_174 ) & V_170 ;
}
F_80 ( V_6 ) ;
}
