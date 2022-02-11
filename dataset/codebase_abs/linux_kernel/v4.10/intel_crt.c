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
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
enum V_13 V_14 ;
T_1 V_15 ;
bool V_16 ;
V_14 = F_7 ( V_3 ) ;
if ( ! F_8 ( V_11 , V_14 ) )
return false ;
V_16 = false ;
V_15 = F_9 ( V_12 -> V_17 ) ;
if ( ! ( V_15 & V_18 ) )
goto V_19;
if ( F_10 ( V_11 ) )
* V_7 = F_11 ( V_15 ) ;
else
* V_7 = F_12 ( V_15 ) ;
V_16 = true ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_16 ;
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_15 , V_20 = 0 ;
V_15 = F_9 ( V_12 -> V_17 ) ;
if ( V_15 & V_21 )
V_20 |= V_22 ;
else
V_20 |= V_23 ;
if ( V_15 & V_24 )
V_20 |= V_25 ;
else
V_20 |= V_26 ;
return V_20 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
V_28 -> V_4 . V_29 . V_20 |= F_14 ( V_3 ) ;
V_28 -> V_4 . V_29 . V_30 = V_28 -> V_31 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
F_17 ( V_3 , V_28 ) ;
V_28 -> V_4 . V_29 . V_20 &= ~ ( V_22 |
V_23 |
V_25 |
V_26 ) ;
V_28 -> V_4 . V_29 . V_20 |= F_14 ( V_3 ) ;
V_28 -> V_4 . V_29 . V_30 = F_18 ( V_11 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_27 * V_32 ,
int V_33 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_20 ( V_32 -> V_4 . V_35 ) ;
const struct V_36 * V_29 = & V_32 -> V_4 . V_29 ;
T_1 V_37 ;
if ( F_21 ( V_11 ) >= 5 )
V_37 = V_38 ;
else
V_37 = 0 ;
if ( V_29 -> V_20 & V_22 )
V_37 |= V_21 ;
if ( V_29 -> V_20 & V_25 )
V_37 |= V_24 ;
if ( F_22 ( V_11 ) )
;
else if ( F_10 ( V_11 ) )
V_37 |= F_23 ( V_35 -> V_7 ) ;
else if ( V_35 -> V_7 == 0 )
V_37 |= V_39 ;
else
V_37 |= V_40 ;
if ( ! F_24 ( V_11 ) )
F_25 ( F_26 ( V_35 -> V_7 ) , 0 ) ;
switch ( V_33 ) {
case V_41 :
V_37 |= V_18 ;
break;
case V_42 :
V_37 |= V_18 | V_43 ;
break;
case V_44 :
V_37 |= V_18 | V_45 ;
break;
case V_46 :
V_37 |= V_43 | V_45 ;
break;
}
F_25 ( V_12 -> V_17 , V_37 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_27 * V_47 ,
struct V_48 * V_49 )
{
F_19 ( V_3 , V_47 , V_46 ) ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_27 * V_47 ,
struct V_48 * V_49 )
{
}
static void F_29 ( struct V_2 * V_3 ,
struct V_27 * V_47 ,
struct V_48 * V_49 )
{
F_27 ( V_3 , V_47 , V_49 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_27 * V_47 ,
struct V_48 * V_49 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
F_29 ( V_3 , V_47 , V_49 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_3 , V_47 , V_49 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_48 * V_50 )
{
F_19 ( V_3 , V_28 , V_41 ) ;
}
static enum V_51
F_35 ( struct V_5 * V_6 ,
struct V_36 * V_33 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
int V_52 = V_11 -> V_53 ;
int V_54 ;
if ( V_33 -> V_20 & V_55 )
return V_56 ;
if ( V_33 -> clock < 25000 )
return V_57 ;
if ( F_22 ( V_11 ) )
V_54 = 180000 ;
else if ( F_36 ( V_11 ) )
V_54 = 270000 ;
else if ( F_37 ( V_11 ) || F_38 ( V_11 ) )
V_54 = 400000 ;
else
V_54 = 350000 ;
if ( V_33 -> clock > V_54 )
return V_58 ;
if ( V_33 -> clock > V_52 )
return V_58 ;
if ( F_22 ( V_11 ) &&
( F_39 ( V_33 -> clock , 270000 , 24 ) > 2 ) )
return V_58 ;
return V_59 ;
}
static bool F_40 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_48 * V_50 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
if ( F_24 ( V_11 ) )
V_28 -> V_60 = true ;
if ( F_22 ( V_11 ) ) {
if ( V_28 -> V_61 && V_28 -> V_62 < 24 ) {
F_41 ( L_1 ) ;
return false ;
}
V_28 -> V_62 = 24 ;
}
if ( F_42 ( V_11 ) )
V_28 -> V_31 = 135000 * 2 ;
return true ;
}
static bool F_43 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_37 ;
bool V_16 ;
if ( V_12 -> V_63 ) {
bool V_64 = F_24 ( V_11 ) ;
T_1 V_65 ;
V_12 -> V_63 = 0 ;
V_65 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_41 ( L_2 , V_37 ) ;
V_37 |= V_66 ;
if ( V_64 )
V_37 &= ~ V_18 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_44 ( V_11 ,
V_12 -> V_17 ,
V_66 , 0 ,
1000 ) )
F_41 ( L_3 ) ;
if ( V_64 ) {
F_25 ( V_12 -> V_17 , V_65 ) ;
F_45 ( V_12 -> V_17 ) ;
}
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_67 ) != 0 )
V_16 = true ;
else
V_16 = false ;
F_41 ( L_4 , V_37 , V_16 ) ;
return V_16 ;
}
static bool F_46 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
bool V_68 ;
T_1 V_37 ;
bool V_16 ;
T_1 V_65 ;
V_68 = F_47 ( V_11 , V_12 -> V_4 . V_69 ) ;
V_65 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_41 ( L_2 , V_37 ) ;
V_37 |= V_66 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_44 ( V_11 ,
V_12 -> V_17 ,
V_66 , 0 ,
1000 ) ) {
F_41 ( L_3 ) ;
F_25 ( V_12 -> V_17 , V_65 ) ;
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_67 ) != 0 )
V_16 = true ;
else
V_16 = false ;
F_41 ( L_5 , V_37 , V_16 ) ;
if ( V_68 )
F_48 ( V_11 , V_12 -> V_4 . V_69 ) ;
return V_16 ;
}
static bool F_49 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_70 ;
bool V_16 = false ;
int V_71 , V_72 = 0 ;
if ( F_24 ( V_11 ) )
return F_43 ( V_6 ) ;
if ( F_36 ( V_11 ) )
return F_46 ( V_6 ) ;
if ( F_50 ( V_11 ) && ! F_51 ( V_11 ) )
V_72 = 2 ;
else
V_72 = 1 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
F_52 ( V_11 ,
V_73 ,
V_73 ) ;
if ( F_44 ( V_11 , V_74 ,
V_73 , 0 ,
1000 ) )
F_41 ( L_6 ) ;
}
V_70 = F_9 ( V_75 ) ;
if ( ( V_70 & V_76 ) != V_77 )
V_16 = true ;
F_25 ( V_75 , V_78 ) ;
F_52 ( V_11 , V_73 , 0 ) ;
return V_16 ;
}
static struct V_79 * F_53 ( struct V_5 * V_6 ,
struct V_80 * V_81 )
{
struct V_79 * V_79 ;
V_79 = F_54 ( V_6 , V_81 ) ;
if ( ! V_79 && ! F_55 ( V_81 ) ) {
F_41 ( L_7 ) ;
F_56 ( V_81 , true ) ;
V_79 = F_54 ( V_6 , V_81 ) ;
F_56 ( V_81 , false ) ;
}
return V_79 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_80 * V_82 )
{
struct V_79 * V_79 ;
int V_16 ;
V_79 = F_53 ( V_6 , V_82 ) ;
if ( ! V_79 )
return 0 ;
V_16 = F_58 ( V_6 , V_79 ) ;
F_59 ( V_79 ) ;
return V_16 ;
}
static bool F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_12 -> V_4 . V_4 . V_9 ) ;
struct V_79 * V_79 ;
struct V_80 * V_81 ;
bool V_16 = false ;
F_61 ( V_12 -> V_4 . type != V_83 ) ;
V_81 = F_62 ( V_11 , V_11 -> V_84 . V_85 ) ;
V_79 = F_53 ( V_6 , V_81 ) ;
if ( V_79 ) {
bool V_86 = V_79 -> V_87 & V_88 ;
if ( ! V_86 ) {
F_41 ( L_8 ) ;
V_16 = true ;
} else {
F_41 ( L_9 ) ;
}
} else {
F_41 ( L_10 ) ;
}
F_59 ( V_79 ) ;
return V_16 ;
}
static enum V_89
F_63 ( struct V_1 * V_12 , T_2 V_7 )
{
struct V_8 * V_9 = V_12 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 , V_93 ;
T_2 V_94 ;
T_2 V_95 , V_96 , V_97 ;
T_2 V_98 ;
T_3 V_99 , V_100 ,
V_101 , V_102 , V_103 , V_104 ;
T_4 V_105 ;
enum V_89 V_106 ;
F_41 ( L_11 ) ;
V_99 = F_26 ( V_7 ) ;
V_100 = F_64 ( V_7 ) ;
V_101 = F_65 ( V_7 ) ;
V_102 = F_66 ( V_7 ) ;
V_103 = F_67 ( V_7 ) ;
V_104 = F_68 ( V_7 ) ;
V_90 = F_9 ( V_99 ) ;
V_91 = F_9 ( V_100 ) ;
V_95 = F_9 ( V_101 ) ;
V_92 = ( ( V_91 >> 16 ) & 0xfff ) + 1 ;
V_93 = ( V_91 & 0x7ff ) + 1 ;
V_96 = ( V_95 & 0xfff ) + 1 ;
V_97 = ( ( V_95 >> 16 ) & 0xfff ) + 1 ;
F_25 ( V_99 , 0x500050 ) ;
if ( ! F_69 ( V_11 ) ) {
T_2 V_107 = F_9 ( V_103 ) ;
F_25 ( V_103 , V_107 | V_108 ) ;
F_45 ( V_103 ) ;
F_70 ( V_11 , V_7 ) ;
V_105 = F_71 ( V_109 ) ;
V_106 = ( ( V_105 & ( 1 << 4 ) ) != 0 ) ?
V_110 :
V_111 ;
F_25 ( V_103 , V_107 ) ;
} else {
bool V_112 = false ;
int V_113 , V_114 ;
if ( V_96 <= V_93 && V_97 >= V_92 ) {
T_2 V_115 = F_9 ( V_102 ) ;
T_2 V_116 = ( V_115 & 0xffff ) + 1 ;
V_96 = V_116 ;
F_25 ( V_101 ,
( V_96 - 1 ) |
( ( V_97 - 1 ) << 16 ) ) ;
V_112 = true ;
}
if ( V_96 - V_93 >= V_92 - V_97 )
V_94 = ( V_96 + V_93 ) >> 1 ;
else
V_94 = ( V_92 + V_97 ) >> 1 ;
while ( F_9 ( V_104 ) >= V_93 )
;
while ( ( V_98 = F_9 ( V_104 ) ) <= V_94 )
;
V_114 = 0 ;
V_113 = 0 ;
do {
V_113 ++ ;
V_105 = F_71 ( V_109 ) ;
if ( V_105 & ( 1 << 4 ) )
V_114 ++ ;
} while ( ( F_9 ( V_104 ) == V_98 ) );
if ( V_112 )
F_25 ( V_101 , V_95 ) ;
V_106 = V_114 * 4 > V_113 * 3 ?
V_110 :
V_111 ;
}
F_25 ( V_99 , V_90 ) ;
return V_106 ;
}
static int F_72 ( const struct V_117 * V_118 )
{
F_73 ( L_12 , V_118 -> V_119 ) ;
return 1 ;
}
static enum V_89
F_74 ( struct V_5 * V_6 , bool V_120 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
enum V_89 V_106 ;
struct V_121 V_15 ;
struct V_122 V_123 ;
F_41 ( L_13 ,
V_6 -> V_4 . V_118 , V_6 -> V_124 ,
V_120 ) ;
if ( F_75 ( V_125 ) )
return V_111 ;
V_14 = F_7 ( V_2 ) ;
F_76 ( V_11 , V_14 ) ;
if ( F_77 ( V_11 ) ) {
if ( F_49 ( V_6 ) ) {
F_41 ( L_14 ) ;
V_106 = V_110 ;
goto V_19;
} else
F_41 ( L_15 ) ;
}
if ( F_60 ( V_6 ) ) {
V_106 = V_110 ;
goto V_19;
}
if ( F_77 ( V_11 ) && ! V_126 . V_127 ) {
V_106 = V_111 ;
goto V_19;
}
if ( ! V_120 ) {
V_106 = V_6 -> V_106 ;
goto V_19;
}
F_78 ( & V_123 , 0 ) ;
if ( F_79 ( V_6 , NULL , & V_15 , & V_123 ) ) {
if ( F_60 ( V_6 ) )
V_106 = V_110 ;
else if ( F_21 ( V_11 ) < 4 )
V_106 = F_63 ( V_12 ,
F_20 ( V_6 -> V_128 -> V_35 ) -> V_7 ) ;
else if ( V_126 . V_127 )
V_106 = V_111 ;
else
V_106 = V_129 ;
F_80 ( V_6 , & V_15 , & V_123 ) ;
} else
V_106 = V_129 ;
F_81 ( & V_123 ) ;
F_82 ( & V_123 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_106 ;
}
static void F_83 ( struct V_5 * V_6 )
{
F_84 ( V_6 ) ;
F_59 ( V_6 ) ;
}
static int F_85 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
int V_16 ;
struct V_80 * V_81 ;
V_14 = F_7 ( V_2 ) ;
F_76 ( V_11 , V_14 ) ;
V_81 = F_62 ( V_11 , V_11 -> V_84 . V_85 ) ;
V_16 = F_57 ( V_6 , V_81 ) ;
if ( V_16 || ! F_50 ( V_11 ) )
goto V_19;
V_81 = F_62 ( V_11 , V_130 ) ;
V_16 = F_57 ( V_6 , V_81 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_16 ;
}
static int F_86 ( struct V_5 * V_6 ,
struct V_131 * V_132 ,
T_5 V_133 )
{
return 0 ;
}
void F_87 ( struct V_134 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
struct V_1 * V_12 = F_1 ( F_88 ( V_3 ) ) ;
if ( F_21 ( V_11 ) >= 5 ) {
T_1 V_37 ;
V_37 = F_9 ( V_12 -> V_17 ) ;
V_37 &= ~ V_135 ;
V_37 |= V_38 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
F_45 ( V_12 -> V_17 ) ;
F_41 ( L_16 , V_37 ) ;
V_12 -> V_63 = 1 ;
}
}
void F_89 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_12 ;
struct V_136 * V_136 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_3 V_17 ;
T_1 V_37 ;
if ( F_24 ( V_11 ) )
V_17 = V_137 ;
else if ( F_36 ( V_11 ) )
V_17 = V_138 ;
else
V_17 = V_139 ;
V_37 = F_9 ( V_17 ) ;
if ( ( V_37 & V_18 ) == 0 ) {
F_25 ( V_17 , V_37 | V_18 |
V_43 | V_45 ) ;
if ( ( F_9 ( V_17 ) & V_18 ) == 0 )
return;
F_25 ( V_17 , V_37 ) ;
}
V_12 = F_90 ( sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_12 )
return;
V_136 = F_91 () ;
if ( ! V_136 ) {
F_59 ( V_12 ) ;
return;
}
V_6 = & V_136 -> V_4 ;
V_12 -> V_6 = V_136 ;
F_92 ( V_9 , & V_136 -> V_4 ,
& V_141 , V_142 ) ;
F_93 ( V_9 , & V_12 -> V_4 . V_4 , & V_143 ,
V_144 , L_17 ) ;
F_94 ( V_136 , & V_12 -> V_4 ) ;
V_12 -> V_4 . type = V_83 ;
V_12 -> V_4 . V_145 = ( 1 << V_146 ) | ( 1 << V_147 ) ;
if ( F_95 ( V_11 ) )
V_12 -> V_4 . V_148 = ( 1 << 0 ) ;
else
V_12 -> V_4 . V_148 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_69 ( V_11 ) )
V_6 -> V_149 = 0 ;
else
V_6 -> V_149 = 1 ;
V_6 -> V_150 = 0 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_4 . V_151 = F_40 ;
if ( F_24 ( V_11 ) ) {
V_12 -> V_4 . V_152 = F_28 ;
V_12 -> V_4 . V_153 = F_29 ;
} else {
V_12 -> V_4 . V_152 = F_27 ;
}
V_12 -> V_4 . V_154 = F_34 ;
if ( F_77 ( V_11 ) &&
! F_75 ( V_125 ) )
V_12 -> V_4 . V_69 = V_155 ;
if ( F_42 ( V_11 ) ) {
V_12 -> V_4 . V_156 = V_157 ;
V_12 -> V_4 . V_158 = F_16 ;
V_12 -> V_4 . V_159 = V_160 ;
V_12 -> V_4 . V_153 = F_30 ;
} else {
V_12 -> V_4 . V_156 = V_161 ;
V_12 -> V_4 . V_158 = F_15 ;
V_12 -> V_4 . V_159 = F_5 ;
}
V_136 -> V_159 = V_162 ;
F_96 ( V_6 , & V_163 ) ;
if ( ! F_77 ( V_11 ) )
V_136 -> V_164 = V_165 ;
V_12 -> V_63 = 0 ;
if ( F_22 ( V_11 ) ) {
T_1 V_166 = V_167 |
V_168 ;
V_11 -> V_169 = F_9 ( F_97 ( V_170 ) ) & V_166 ;
}
F_87 ( & V_12 -> V_4 . V_4 ) ;
}
