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
T_1 V_13 ;
bool V_14 ;
if ( ! F_7 ( V_11 ,
V_3 -> V_15 ) )
return false ;
V_14 = false ;
V_13 = F_8 ( V_12 -> V_16 ) ;
if ( ! ( V_13 & V_17 ) )
goto V_18;
if ( F_9 ( V_11 ) )
* V_7 = F_10 ( V_13 ) ;
else
* V_7 = F_11 ( V_13 ) ;
V_14 = true ;
V_18:
F_12 ( V_11 , V_3 -> V_15 ) ;
return V_14 ;
}
static unsigned int F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_19 = 0 ;
V_13 = F_8 ( V_12 -> V_16 ) ;
if ( V_13 & V_20 )
V_19 |= V_21 ;
else
V_19 |= V_22 ;
if ( V_13 & V_23 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
return V_19 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
V_27 -> V_4 . V_28 . V_19 |= F_13 ( V_3 ) ;
V_27 -> V_4 . V_28 . V_29 = V_27 -> V_30 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
F_16 ( V_3 , V_27 ) ;
V_27 -> V_4 . V_28 . V_19 &= ~ ( V_21 |
V_22 |
V_24 |
V_25 ) ;
V_27 -> V_4 . V_28 . V_19 |= F_13 ( V_3 ) ;
V_27 -> V_4 . V_28 . V_29 = F_17 ( V_11 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_26 * V_31 ,
int V_32 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_33 * V_34 = F_19 ( V_31 -> V_4 . V_34 ) ;
const struct V_35 * V_28 = & V_31 -> V_4 . V_28 ;
T_1 V_36 ;
if ( F_20 ( V_11 ) >= 5 )
V_36 = V_37 ;
else
V_36 = 0 ;
if ( V_28 -> V_19 & V_21 )
V_36 |= V_20 ;
if ( V_28 -> V_19 & V_24 )
V_36 |= V_23 ;
if ( F_21 ( V_11 ) )
;
else if ( F_9 ( V_11 ) )
V_36 |= F_22 ( V_34 -> V_7 ) ;
else if ( V_34 -> V_7 == 0 )
V_36 |= V_38 ;
else
V_36 |= V_39 ;
if ( ! F_23 ( V_11 ) )
F_24 ( F_25 ( V_34 -> V_7 ) , 0 ) ;
switch ( V_32 ) {
case V_40 :
V_36 |= V_17 ;
break;
case V_41 :
V_36 |= V_17 | V_42 ;
break;
case V_43 :
V_36 |= V_17 | V_44 ;
break;
case V_45 :
V_36 |= V_42 | V_44 ;
break;
}
F_24 ( V_12 -> V_16 , V_36 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_26 * V_46 ,
struct V_47 * V_48 )
{
F_18 ( V_3 , V_46 , V_45 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_26 * V_46 ,
struct V_47 * V_48 )
{
}
static void F_28 ( struct V_2 * V_3 ,
struct V_26 * V_46 ,
struct V_47 * V_48 )
{
F_26 ( V_3 , V_46 , V_48 ) ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_26 * V_46 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
F_28 ( V_3 , V_46 , V_48 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_3 , V_46 , V_48 ) ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_47 * V_49 )
{
F_18 ( V_3 , V_27 , V_40 ) ;
}
static enum V_50
F_34 ( struct V_5 * V_6 ,
struct V_35 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
int V_51 = V_11 -> V_52 ;
int V_53 ;
if ( V_32 -> V_19 & V_54 )
return V_55 ;
if ( V_32 -> clock < 25000 )
return V_56 ;
if ( F_21 ( V_11 ) )
V_53 = 180000 ;
else if ( F_35 ( V_11 ) )
V_53 = 270000 ;
else if ( F_36 ( V_11 ) || F_37 ( V_11 ) )
V_53 = 400000 ;
else
V_53 = 350000 ;
if ( V_32 -> clock > V_53 )
return V_57 ;
if ( V_32 -> clock > V_51 )
return V_57 ;
if ( F_21 ( V_11 ) &&
( F_38 ( V_32 -> clock , 270000 , 24 ) > 2 ) )
return V_57 ;
return V_58 ;
}
static bool F_39 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_47 * V_49 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
if ( F_23 ( V_11 ) )
V_27 -> V_59 = true ;
if ( F_21 ( V_11 ) ) {
if ( V_27 -> V_60 && V_27 -> V_61 < 24 ) {
F_40 ( L_1 ) ;
return false ;
}
V_27 -> V_61 = 24 ;
}
if ( F_41 ( V_11 ) )
V_27 -> V_30 = 135000 * 2 ;
return true ;
}
static bool F_42 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_36 ;
bool V_14 ;
if ( V_12 -> V_62 ) {
bool V_63 = F_23 ( V_11 ) ;
T_1 V_64 ;
V_12 -> V_62 = 0 ;
V_64 = V_36 = F_8 ( V_12 -> V_16 ) ;
F_40 ( L_2 , V_36 ) ;
V_36 |= V_65 ;
if ( V_63 )
V_36 &= ~ V_17 ;
F_24 ( V_12 -> V_16 , V_36 ) ;
if ( F_43 ( V_11 ,
V_12 -> V_16 ,
V_65 , 0 ,
1000 ) )
F_40 ( L_3 ) ;
if ( V_63 ) {
F_24 ( V_12 -> V_16 , V_64 ) ;
F_44 ( V_12 -> V_16 ) ;
}
}
V_36 = F_8 ( V_12 -> V_16 ) ;
if ( ( V_36 & V_66 ) != 0 )
V_14 = true ;
else
V_14 = false ;
F_40 ( L_4 , V_36 , V_14 ) ;
return V_14 ;
}
static bool F_45 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
bool V_67 ;
T_1 V_36 ;
bool V_14 ;
T_1 V_64 ;
V_67 = F_46 ( V_11 , V_12 -> V_4 . V_68 ) ;
V_64 = V_36 = F_8 ( V_12 -> V_16 ) ;
F_40 ( L_2 , V_36 ) ;
V_36 |= V_65 ;
F_24 ( V_12 -> V_16 , V_36 ) ;
if ( F_43 ( V_11 ,
V_12 -> V_16 ,
V_65 , 0 ,
1000 ) ) {
F_40 ( L_3 ) ;
F_24 ( V_12 -> V_16 , V_64 ) ;
}
V_36 = F_8 ( V_12 -> V_16 ) ;
if ( ( V_36 & V_66 ) != 0 )
V_14 = true ;
else
V_14 = false ;
F_40 ( L_5 , V_36 , V_14 ) ;
if ( V_67 )
F_47 ( V_11 , V_12 -> V_4 . V_68 ) ;
return V_14 ;
}
static bool F_48 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_69 ;
bool V_14 = false ;
int V_70 , V_71 = 0 ;
if ( F_23 ( V_11 ) )
return F_42 ( V_6 ) ;
if ( F_35 ( V_11 ) )
return F_45 ( V_6 ) ;
if ( F_49 ( V_11 ) && ! F_50 ( V_11 ) )
V_71 = 2 ;
else
V_71 = 1 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
F_51 ( V_11 ,
V_72 ,
V_72 ) ;
if ( F_43 ( V_11 , V_73 ,
V_72 , 0 ,
1000 ) )
F_40 ( L_6 ) ;
}
V_69 = F_8 ( V_74 ) ;
if ( ( V_69 & V_75 ) != V_76 )
V_14 = true ;
F_24 ( V_74 , V_77 ) ;
F_51 ( V_11 , V_72 , 0 ) ;
return V_14 ;
}
static struct V_78 * F_52 ( struct V_5 * V_6 ,
struct V_79 * V_80 )
{
struct V_78 * V_78 ;
V_78 = F_53 ( V_6 , V_80 ) ;
if ( ! V_78 && ! F_54 ( V_80 ) ) {
F_40 ( L_7 ) ;
F_55 ( V_80 , true ) ;
V_78 = F_53 ( V_6 , V_80 ) ;
F_55 ( V_80 , false ) ;
}
return V_78 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_79 * V_81 )
{
struct V_78 * V_78 ;
int V_14 ;
V_78 = F_52 ( V_6 , V_81 ) ;
if ( ! V_78 )
return 0 ;
V_14 = F_57 ( V_6 , V_78 ) ;
F_58 ( V_78 ) ;
return V_14 ;
}
static bool F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_12 -> V_4 . V_4 . V_9 ) ;
struct V_78 * V_78 ;
struct V_79 * V_80 ;
bool V_14 = false ;
F_60 ( V_12 -> V_4 . type != V_82 ) ;
V_80 = F_61 ( V_11 , V_11 -> V_83 . V_84 ) ;
V_78 = F_52 ( V_6 , V_80 ) ;
if ( V_78 ) {
bool V_85 = V_78 -> V_86 & V_87 ;
if ( ! V_85 ) {
F_40 ( L_8 ) ;
V_14 = true ;
} else {
F_40 ( L_9 ) ;
}
} else {
F_40 ( L_10 ) ;
}
F_58 ( V_78 ) ;
return V_14 ;
}
static enum V_88
F_62 ( struct V_1 * V_12 , T_2 V_7 )
{
struct V_8 * V_9 = V_12 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 , V_92 ;
T_2 V_93 ;
T_2 V_94 , V_95 , V_96 ;
T_2 V_97 ;
T_3 V_98 , V_99 ,
V_100 , V_101 , V_102 , V_103 ;
T_4 V_104 ;
enum V_88 V_105 ;
F_40 ( L_11 ) ;
V_98 = F_25 ( V_7 ) ;
V_99 = F_63 ( V_7 ) ;
V_100 = F_64 ( V_7 ) ;
V_101 = F_65 ( V_7 ) ;
V_102 = F_66 ( V_7 ) ;
V_103 = F_67 ( V_7 ) ;
V_89 = F_8 ( V_98 ) ;
V_90 = F_8 ( V_99 ) ;
V_94 = F_8 ( V_100 ) ;
V_91 = ( ( V_90 >> 16 ) & 0xfff ) + 1 ;
V_92 = ( V_90 & 0x7ff ) + 1 ;
V_95 = ( V_94 & 0xfff ) + 1 ;
V_96 = ( ( V_94 >> 16 ) & 0xfff ) + 1 ;
F_24 ( V_98 , 0x500050 ) ;
if ( ! F_68 ( V_11 ) ) {
T_2 V_106 = F_8 ( V_102 ) ;
F_24 ( V_102 , V_106 | V_107 ) ;
F_44 ( V_102 ) ;
F_69 ( V_11 , V_7 ) ;
V_104 = F_70 ( V_108 ) ;
V_105 = ( ( V_104 & ( 1 << 4 ) ) != 0 ) ?
V_109 :
V_110 ;
F_24 ( V_102 , V_106 ) ;
} else {
bool V_111 = false ;
int V_112 , V_113 ;
if ( V_95 <= V_92 && V_96 >= V_91 ) {
T_2 V_114 = F_8 ( V_101 ) ;
T_2 V_115 = ( V_114 & 0xffff ) + 1 ;
V_95 = V_115 ;
F_24 ( V_100 ,
( V_95 - 1 ) |
( ( V_96 - 1 ) << 16 ) ) ;
V_111 = true ;
}
if ( V_95 - V_92 >= V_91 - V_96 )
V_93 = ( V_95 + V_92 ) >> 1 ;
else
V_93 = ( V_91 + V_96 ) >> 1 ;
while ( F_8 ( V_103 ) >= V_92 )
;
while ( ( V_97 = F_8 ( V_103 ) ) <= V_93 )
;
V_113 = 0 ;
V_112 = 0 ;
do {
V_112 ++ ;
V_104 = F_70 ( V_108 ) ;
if ( V_104 & ( 1 << 4 ) )
V_113 ++ ;
} while ( ( F_8 ( V_103 ) == V_97 ) );
if ( V_111 )
F_24 ( V_100 , V_94 ) ;
V_105 = V_113 * 4 > V_112 * 3 ?
V_109 :
V_110 ;
}
F_24 ( V_98 , V_89 ) ;
return V_105 ;
}
static int F_71 ( const struct V_116 * V_117 )
{
F_72 ( L_12 , V_117 -> V_118 ) ;
return 1 ;
}
static int
F_73 ( struct V_5 * V_6 ,
struct V_119 * V_120 ,
bool V_121 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
int V_105 , V_14 ;
struct V_122 V_13 ;
F_40 ( L_13 ,
V_6 -> V_4 . V_117 , V_6 -> V_123 ,
V_121 ) ;
if ( F_74 ( V_124 ) )
return V_110 ;
F_75 ( V_11 , V_2 -> V_15 ) ;
if ( F_76 ( V_11 ) ) {
if ( F_48 ( V_6 ) ) {
F_40 ( L_14 ) ;
V_105 = V_109 ;
goto V_18;
} else
F_40 ( L_15 ) ;
}
if ( F_59 ( V_6 ) ) {
V_105 = V_109 ;
goto V_18;
}
if ( F_76 ( V_11 ) && ! V_125 . V_126 ) {
V_105 = V_110 ;
goto V_18;
}
if ( ! V_121 ) {
V_105 = V_6 -> V_105 ;
goto V_18;
}
V_14 = F_77 ( V_6 , NULL , & V_13 , V_120 ) ;
if ( V_14 > 0 ) {
if ( F_59 ( V_6 ) )
V_105 = V_109 ;
else if ( F_20 ( V_11 ) < 4 )
V_105 = F_62 ( V_12 ,
F_19 ( V_6 -> V_127 -> V_34 ) -> V_7 ) ;
else if ( V_125 . V_126 )
V_105 = V_110 ;
else
V_105 = V_128 ;
F_78 ( V_6 , & V_13 , V_120 ) ;
} else if ( V_14 == 0 )
V_105 = V_128 ;
else if ( V_14 < 0 )
V_105 = V_14 ;
V_18:
F_12 ( V_11 , V_2 -> V_15 ) ;
return V_105 ;
}
static void F_79 ( struct V_5 * V_6 )
{
F_80 ( V_6 ) ;
F_58 ( V_6 ) ;
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
int V_14 ;
struct V_79 * V_80 ;
F_75 ( V_11 , V_2 -> V_15 ) ;
V_80 = F_61 ( V_11 , V_11 -> V_83 . V_84 ) ;
V_14 = F_56 ( V_6 , V_80 ) ;
if ( V_14 || ! F_49 ( V_11 ) )
goto V_18;
V_80 = F_61 ( V_11 , V_129 ) ;
V_14 = F_56 ( V_6 , V_80 ) ;
V_18:
F_12 ( V_11 , V_2 -> V_15 ) ;
return V_14 ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_130 * V_131 ,
T_5 V_132 )
{
return 0 ;
}
void F_83 ( struct V_133 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
struct V_1 * V_12 = F_1 ( F_84 ( V_3 ) ) ;
if ( F_20 ( V_11 ) >= 5 ) {
T_1 V_36 ;
V_36 = F_8 ( V_12 -> V_16 ) ;
V_36 &= ~ V_134 ;
V_36 |= V_37 ;
F_24 ( V_12 -> V_16 , V_36 ) ;
F_44 ( V_12 -> V_16 ) ;
F_40 ( L_16 , V_36 ) ;
V_12 -> V_62 = 1 ;
}
}
void F_85 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
struct V_1 * V_12 ;
struct V_135 * V_135 ;
T_3 V_16 ;
T_1 V_36 ;
if ( F_23 ( V_11 ) )
V_16 = V_136 ;
else if ( F_35 ( V_11 ) )
V_16 = V_137 ;
else
V_16 = V_138 ;
V_36 = F_8 ( V_16 ) ;
if ( ( V_36 & V_17 ) == 0 ) {
F_24 ( V_16 , V_36 | V_17 |
V_42 | V_44 ) ;
if ( ( F_8 ( V_16 ) & V_17 ) == 0 )
return;
F_24 ( V_16 , V_36 ) ;
}
V_12 = F_86 ( sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_12 )
return;
V_135 = F_87 () ;
if ( ! V_135 ) {
F_58 ( V_12 ) ;
return;
}
V_6 = & V_135 -> V_4 ;
V_12 -> V_6 = V_135 ;
F_88 ( & V_11 -> V_140 , & V_135 -> V_4 ,
& V_141 , V_142 ) ;
F_89 ( & V_11 -> V_140 , & V_12 -> V_4 . V_4 , & V_143 ,
V_144 , L_17 ) ;
F_90 ( V_135 , & V_12 -> V_4 ) ;
V_12 -> V_4 . type = V_82 ;
V_12 -> V_4 . V_145 = ( 1 << V_146 ) | ( 1 << V_147 ) ;
if ( F_91 ( V_11 ) )
V_12 -> V_4 . V_148 = ( 1 << 0 ) ;
else
V_12 -> V_4 . V_148 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_68 ( V_11 ) )
V_6 -> V_149 = 0 ;
else
V_6 -> V_149 = 1 ;
V_6 -> V_150 = 0 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_4 . V_15 = V_151 ;
V_12 -> V_4 . V_152 = F_39 ;
if ( F_23 ( V_11 ) ) {
V_12 -> V_4 . V_153 = F_27 ;
V_12 -> V_4 . V_154 = F_28 ;
} else {
V_12 -> V_4 . V_153 = F_26 ;
}
V_12 -> V_4 . V_155 = F_33 ;
if ( F_76 ( V_11 ) &&
! F_74 ( V_124 ) )
V_12 -> V_4 . V_68 = V_156 ;
if ( F_41 ( V_11 ) ) {
V_12 -> V_4 . V_157 = V_158 ;
V_12 -> V_4 . V_159 = F_15 ;
V_12 -> V_4 . V_160 = V_161 ;
V_12 -> V_4 . V_154 = F_29 ;
} else {
V_12 -> V_4 . V_157 = V_162 ;
V_12 -> V_4 . V_159 = F_14 ;
V_12 -> V_4 . V_160 = F_5 ;
}
V_135 -> V_160 = V_163 ;
F_92 ( V_6 , & V_164 ) ;
if ( ! F_76 ( V_11 ) )
V_135 -> V_165 = V_166 ;
V_12 -> V_62 = 0 ;
if ( F_21 ( V_11 ) ) {
T_1 V_167 = V_168 |
V_169 ;
V_11 -> V_170 = F_8 ( F_93 ( V_171 ) ) & V_167 ;
}
F_83 ( & V_12 -> V_4 . V_4 ) ;
}
