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
if ( F_10 ( V_9 ) )
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
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_20 ( V_32 -> V_4 . V_35 ) ;
const struct V_36 * V_29 = & V_32 -> V_4 . V_29 ;
T_1 V_37 ;
if ( F_21 ( V_9 ) -> V_38 >= 5 )
V_37 = V_39 ;
else
V_37 = 0 ;
if ( V_29 -> V_20 & V_22 )
V_37 |= V_21 ;
if ( V_29 -> V_20 & V_25 )
V_37 |= V_24 ;
if ( F_22 ( V_9 ) )
;
else if ( F_10 ( V_9 ) )
V_37 |= F_23 ( V_35 -> V_7 ) ;
else if ( V_35 -> V_7 == 0 )
V_37 |= V_40 ;
else
V_37 |= V_41 ;
if ( ! F_24 ( V_9 ) )
F_25 ( F_26 ( V_35 -> V_7 ) , 0 ) ;
switch ( V_33 ) {
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
F_25 ( V_12 -> V_17 , V_37 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_27 * V_48 ,
struct V_49 * V_50 )
{
F_19 ( V_3 , V_48 , V_47 ) ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_27 * V_48 ,
struct V_49 * V_50 )
{
}
static void F_29 ( struct V_2 * V_3 ,
struct V_27 * V_48 ,
struct V_49 * V_50 )
{
F_27 ( V_3 , V_48 , V_50 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_27 * V_48 ,
struct V_49 * V_50 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
F_29 ( V_3 , V_48 , V_50 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_3 , V_48 , V_50 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_49 * V_51 )
{
F_19 ( V_3 , V_28 , V_42 ) ;
}
static enum V_52
F_35 ( struct V_5 * V_6 ,
struct V_36 * V_33 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_53 = F_6 ( V_9 ) -> V_54 ;
int V_55 ;
if ( V_33 -> V_20 & V_56 )
return V_57 ;
if ( V_33 -> clock < 25000 )
return V_58 ;
if ( F_22 ( V_9 ) )
V_55 = 180000 ;
else if ( F_36 ( V_9 ) )
V_55 = 270000 ;
else if ( F_37 ( V_9 ) || F_38 ( V_9 ) )
V_55 = 400000 ;
else
V_55 = 350000 ;
if ( V_33 -> clock > V_55 )
return V_59 ;
if ( V_33 -> clock > V_53 )
return V_59 ;
if ( F_22 ( V_9 ) &&
( F_39 ( V_33 -> clock , 270000 , 24 ) > 2 ) )
return V_59 ;
return V_60 ;
}
static bool F_40 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_49 * V_51 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_24 ( V_9 ) )
V_28 -> V_61 = true ;
if ( F_22 ( V_9 ) ) {
if ( V_28 -> V_62 && V_28 -> V_63 < 24 ) {
F_41 ( L_1 ) ;
return false ;
}
V_28 -> V_63 = 24 ;
}
if ( F_42 ( V_9 ) )
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
if ( V_12 -> V_64 ) {
bool V_65 = F_24 ( V_9 ) ;
T_1 V_66 ;
V_12 -> V_64 = 0 ;
V_66 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_41 ( L_2 , V_37 ) ;
V_37 |= V_67 ;
if ( V_65 )
V_37 &= ~ V_18 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_44 ( V_11 ,
V_12 -> V_17 ,
V_67 , 0 ,
1000 ) )
F_41 ( L_3 ) ;
if ( V_65 ) {
F_25 ( V_12 -> V_17 , V_66 ) ;
F_45 ( V_12 -> V_17 ) ;
}
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_68 ) != 0 )
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
bool V_69 ;
T_1 V_37 ;
bool V_16 ;
T_1 V_66 ;
V_69 = F_47 ( V_11 , V_12 -> V_4 . V_70 ) ;
V_66 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_41 ( L_2 , V_37 ) ;
V_37 |= V_67 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_44 ( V_11 ,
V_12 -> V_17 ,
V_67 , 0 ,
1000 ) ) {
F_41 ( L_3 ) ;
F_25 ( V_12 -> V_17 , V_66 ) ;
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_68 ) != 0 )
V_16 = true ;
else
V_16 = false ;
F_41 ( L_5 , V_37 , V_16 ) ;
if ( V_69 )
F_48 ( V_11 , V_12 -> V_4 . V_70 ) ;
return V_16 ;
}
static bool F_49 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_71 ;
bool V_16 = false ;
int V_72 , V_73 = 0 ;
if ( F_24 ( V_9 ) )
return F_43 ( V_6 ) ;
if ( F_36 ( V_9 ) )
return F_46 ( V_6 ) ;
if ( F_50 ( V_9 ) && ! F_51 ( V_9 ) )
V_73 = 2 ;
else
V_73 = 1 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
F_52 ( V_11 ,
V_74 ,
V_74 ) ;
if ( F_44 ( V_11 , V_75 ,
V_74 , 0 ,
1000 ) )
F_41 ( L_6 ) ;
}
V_71 = F_9 ( V_76 ) ;
if ( ( V_71 & V_77 ) != V_78 )
V_16 = true ;
F_25 ( V_76 , V_79 ) ;
F_52 ( V_11 , V_74 , 0 ) ;
return V_16 ;
}
static struct V_80 * F_53 ( struct V_5 * V_6 ,
struct V_81 * V_82 )
{
struct V_80 * V_80 ;
V_80 = F_54 ( V_6 , V_82 ) ;
if ( ! V_80 && ! F_55 ( V_82 ) ) {
F_41 ( L_7 ) ;
F_56 ( V_82 , true ) ;
V_80 = F_54 ( V_6 , V_82 ) ;
F_56 ( V_82 , false ) ;
}
return V_80 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_81 * V_83 )
{
struct V_80 * V_80 ;
int V_16 ;
V_80 = F_53 ( V_6 , V_83 ) ;
if ( ! V_80 )
return 0 ;
V_16 = F_58 ( V_6 , V_80 ) ;
F_59 ( V_80 ) ;
return V_16 ;
}
static bool F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_12 -> V_4 . V_4 . V_9 ) ;
struct V_80 * V_80 ;
struct V_81 * V_82 ;
F_61 ( V_12 -> V_4 . type != V_84 ) ;
V_82 = F_62 ( V_11 , V_11 -> V_85 . V_86 ) ;
V_80 = F_53 ( V_6 , V_82 ) ;
if ( V_80 ) {
bool V_87 = V_80 -> V_88 & V_89 ;
if ( ! V_87 ) {
F_41 ( L_8 ) ;
return true ;
}
F_41 ( L_9 ) ;
} else {
F_41 ( L_10 ) ;
}
F_59 ( V_80 ) ;
return false ;
}
static enum V_90
F_63 ( struct V_1 * V_12 , T_2 V_7 )
{
struct V_8 * V_9 = V_12 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_2 V_91 ;
T_2 V_92 ;
T_2 V_93 , V_94 ;
T_2 V_95 ;
T_2 V_96 , V_97 , V_98 ;
T_2 V_99 ;
T_3 V_100 , V_101 ,
V_102 , V_103 , V_104 , V_105 ;
T_4 V_106 ;
enum V_90 V_107 ;
F_41 ( L_11 ) ;
V_100 = F_26 ( V_7 ) ;
V_101 = F_64 ( V_7 ) ;
V_102 = F_65 ( V_7 ) ;
V_103 = F_66 ( V_7 ) ;
V_104 = F_67 ( V_7 ) ;
V_105 = F_68 ( V_7 ) ;
V_91 = F_9 ( V_100 ) ;
V_92 = F_9 ( V_101 ) ;
V_96 = F_9 ( V_102 ) ;
V_93 = ( ( V_92 >> 16 ) & 0xfff ) + 1 ;
V_94 = ( V_92 & 0x7ff ) + 1 ;
V_97 = ( V_96 & 0xfff ) + 1 ;
V_98 = ( ( V_96 >> 16 ) & 0xfff ) + 1 ;
F_25 ( V_100 , 0x500050 ) ;
if ( ! F_69 ( V_9 ) ) {
T_2 V_108 = F_9 ( V_104 ) ;
F_25 ( V_104 , V_108 | V_109 ) ;
F_45 ( V_104 ) ;
F_70 ( V_9 , V_7 ) ;
V_106 = F_71 ( V_110 ) ;
V_107 = ( ( V_106 & ( 1 << 4 ) ) != 0 ) ?
V_111 :
V_112 ;
F_25 ( V_104 , V_108 ) ;
} else {
bool V_113 = false ;
int V_114 , V_115 ;
if ( V_97 <= V_94 && V_98 >= V_93 ) {
T_2 V_116 = F_9 ( V_103 ) ;
T_2 V_117 = ( V_116 & 0xffff ) + 1 ;
V_97 = V_117 ;
F_25 ( V_102 ,
( V_97 - 1 ) |
( ( V_98 - 1 ) << 16 ) ) ;
V_113 = true ;
}
if ( V_97 - V_94 >= V_93 - V_98 )
V_95 = ( V_97 + V_94 ) >> 1 ;
else
V_95 = ( V_93 + V_98 ) >> 1 ;
while ( F_9 ( V_105 ) >= V_94 )
;
while ( ( V_99 = F_9 ( V_105 ) ) <= V_95 )
;
V_115 = 0 ;
V_114 = 0 ;
do {
V_114 ++ ;
V_106 = F_71 ( V_110 ) ;
if ( V_106 & ( 1 << 4 ) )
V_115 ++ ;
} while ( ( F_9 ( V_105 ) == V_99 ) );
if ( V_113 )
F_25 ( V_102 , V_96 ) ;
V_107 = V_115 * 4 > V_114 * 3 ?
V_111 :
V_112 ;
}
F_25 ( V_100 , V_91 ) ;
return V_107 ;
}
static enum V_90
F_72 ( struct V_5 * V_6 , bool V_118 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
enum V_90 V_107 ;
struct V_119 V_15 ;
struct V_120 V_121 ;
F_41 ( L_12 ,
V_6 -> V_4 . V_122 , V_6 -> V_123 ,
V_118 ) ;
V_14 = F_7 ( V_2 ) ;
F_73 ( V_11 , V_14 ) ;
if ( F_74 ( V_9 ) ) {
if ( F_49 ( V_6 ) ) {
F_41 ( L_13 ) ;
V_107 = V_111 ;
goto V_19;
} else
F_41 ( L_14 ) ;
}
if ( F_60 ( V_6 ) ) {
V_107 = V_111 ;
goto V_19;
}
if ( F_74 ( V_9 ) && ! V_124 . V_125 ) {
V_107 = V_112 ;
goto V_19;
}
if ( ! V_118 ) {
V_107 = V_6 -> V_107 ;
goto V_19;
}
F_75 ( & V_121 , 0 ) ;
if ( F_76 ( V_6 , NULL , & V_15 , & V_121 ) ) {
if ( F_60 ( V_6 ) )
V_107 = V_111 ;
else if ( F_21 ( V_9 ) -> V_38 < 4 )
V_107 = F_63 ( V_12 ,
F_20 ( V_6 -> V_126 -> V_35 ) -> V_7 ) ;
else if ( V_124 . V_125 )
V_107 = V_112 ;
else
V_107 = V_127 ;
F_77 ( V_6 , & V_15 , & V_121 ) ;
} else
V_107 = V_127 ;
F_78 ( & V_121 ) ;
F_79 ( & V_121 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_107 ;
}
static void F_80 ( struct V_5 * V_6 )
{
F_81 ( V_6 ) ;
F_59 ( V_6 ) ;
}
static int F_82 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
int V_16 ;
struct V_81 * V_82 ;
V_14 = F_7 ( V_2 ) ;
F_73 ( V_11 , V_14 ) ;
V_82 = F_62 ( V_11 , V_11 -> V_85 . V_86 ) ;
V_16 = F_57 ( V_6 , V_82 ) ;
if ( V_16 || ! F_50 ( V_9 ) )
goto V_19;
V_82 = F_62 ( V_11 , V_128 ) ;
V_16 = F_57 ( V_6 , V_82 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_16 ;
}
static int F_83 ( struct V_5 * V_6 ,
struct V_129 * V_130 ,
T_5 V_131 )
{
return 0 ;
}
void F_84 ( struct V_132 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_1 ( F_85 ( V_3 ) ) ;
if ( F_21 ( V_9 ) -> V_38 >= 5 ) {
T_1 V_37 ;
V_37 = F_9 ( V_12 -> V_17 ) ;
V_37 &= ~ V_133 ;
V_37 |= V_39 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
F_45 ( V_12 -> V_17 ) ;
F_41 ( L_15 , V_37 ) ;
V_12 -> V_64 = 1 ;
}
}
static int F_86 ( const struct V_134 * V_122 )
{
F_87 ( L_16 , V_122 -> V_135 ) ;
return 1 ;
}
void F_88 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_12 ;
struct V_136 * V_136 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_3 V_17 ;
T_1 V_37 ;
if ( F_89 ( V_137 ) )
return;
if ( F_24 ( V_9 ) )
V_17 = V_138 ;
else if ( F_36 ( V_9 ) )
V_17 = V_139 ;
else
V_17 = V_140 ;
V_37 = F_9 ( V_17 ) ;
if ( ( V_37 & V_18 ) == 0 ) {
F_25 ( V_17 , V_37 | V_18 |
V_44 | V_46 ) ;
if ( ( F_9 ( V_17 ) & V_18 ) == 0 )
return;
F_25 ( V_17 , V_37 ) ;
}
V_12 = F_90 ( sizeof( struct V_1 ) , V_141 ) ;
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
& V_142 , V_143 ) ;
F_93 ( V_9 , & V_12 -> V_4 . V_4 , & V_144 ,
V_145 , L_17 ) ;
F_94 ( V_136 , & V_12 -> V_4 ) ;
V_12 -> V_4 . type = V_84 ;
V_12 -> V_4 . V_146 = ( 1 << V_147 ) | ( 1 << V_148 ) ;
if ( F_95 ( V_9 ) )
V_12 -> V_4 . V_149 = ( 1 << 0 ) ;
else
V_12 -> V_4 . V_149 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_69 ( V_9 ) )
V_6 -> V_150 = 0 ;
else
V_6 -> V_150 = 1 ;
V_6 -> V_151 = 0 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_4 . V_152 = F_40 ;
if ( F_24 ( V_9 ) ) {
V_12 -> V_4 . V_153 = F_28 ;
V_12 -> V_4 . V_154 = F_29 ;
} else {
V_12 -> V_4 . V_153 = F_27 ;
}
V_12 -> V_4 . V_155 = F_34 ;
if ( F_74 ( V_9 ) )
V_12 -> V_4 . V_70 = V_156 ;
if ( F_42 ( V_9 ) ) {
V_12 -> V_4 . V_157 = F_16 ;
V_12 -> V_4 . V_158 = V_159 ;
V_12 -> V_4 . V_154 = F_30 ;
} else {
V_12 -> V_4 . V_157 = F_15 ;
V_12 -> V_4 . V_158 = F_5 ;
}
V_136 -> V_158 = V_160 ;
F_96 ( V_6 , & V_161 ) ;
if ( ! F_74 ( V_9 ) )
V_136 -> V_162 = V_163 ;
V_12 -> V_64 = 0 ;
if ( F_22 ( V_9 ) ) {
T_1 V_164 = V_165 |
V_166 ;
V_11 -> V_167 = F_9 ( F_97 ( V_168 ) ) & V_164 ;
}
F_84 ( & V_12 -> V_4 . V_4 ) ;
}
