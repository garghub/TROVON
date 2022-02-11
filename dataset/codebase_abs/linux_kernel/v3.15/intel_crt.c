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
static void F_18 ( struct V_2 * V_3 , int V_32 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_33 ;
V_33 = F_8 ( V_13 -> V_17 ) ;
V_33 &= ~ ( V_34 | V_35 ) ;
V_33 &= ~ V_18 ;
switch ( V_32 ) {
case V_36 :
V_33 |= V_18 ;
break;
case V_37 :
V_33 |= V_18 | V_34 ;
break;
case V_38 :
V_33 |= V_18 | V_35 ;
break;
case V_39 :
V_33 |= V_34 | V_35 ;
break;
}
F_19 ( V_13 -> V_17 , V_33 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_18 ( V_3 , V_39 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_18 ( V_3 , V_13 -> V_6 -> V_4 . V_40 ) ;
}
static void F_22 ( struct V_5 * V_6 , int V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_41 * V_42 ;
int V_43 ;
if ( F_23 ( V_9 ) -> V_44 >= 5 && V_32 != V_36 )
V_32 = V_39 ;
if ( V_32 == V_6 -> V_40 )
return;
V_43 = V_6 -> V_40 ;
V_6 -> V_40 = V_32 ;
V_42 = V_3 -> V_4 . V_42 ;
if ( ! V_42 ) {
V_3 -> V_45 = false ;
return;
}
if ( V_32 == V_39 )
V_3 -> V_45 = false ;
else
V_3 -> V_45 = true ;
if ( V_32 < V_43 ) {
F_24 ( V_42 ) ;
F_18 ( V_3 , V_32 ) ;
} else {
F_18 ( V_3 , V_32 ) ;
F_24 ( V_42 ) ;
}
F_25 ( V_6 -> V_9 ) ;
}
static enum V_46
F_26 ( struct V_5 * V_6 ,
struct V_47 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_48 = 0 ;
if ( V_32 -> V_19 & V_49 )
return V_50 ;
if ( V_32 -> clock < 25000 )
return V_51 ;
if ( F_27 ( V_9 ) )
V_48 = 350000 ;
else
V_48 = 400000 ;
if ( V_32 -> clock > V_48 )
return V_52 ;
if ( F_28 ( V_9 ) &&
( F_29 ( V_32 -> clock , 270000 , 24 ) > 2 ) )
return V_52 ;
return V_53 ;
}
static bool F_30 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_14 ( V_9 ) )
V_27 -> V_54 = true ;
if ( F_28 ( V_9 ) )
V_27 -> V_55 = 24 ;
if ( F_31 ( V_9 ) )
V_27 -> V_30 = 135000 * 2 ;
return true ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_56 * V_42 = F_33 ( V_3 -> V_4 . V_42 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_47 * V_29 = & V_42 -> V_57 . V_29 ;
T_1 V_58 ;
if ( F_23 ( V_9 ) -> V_44 >= 5 )
V_58 = V_59 ;
else
V_58 = 0 ;
if ( V_29 -> V_19 & V_21 )
V_58 |= V_20 ;
if ( V_29 -> V_19 & V_24 )
V_58 |= V_23 ;
if ( F_28 ( V_9 ) )
;
else if ( F_9 ( V_9 ) )
V_58 |= F_34 ( V_42 -> V_7 ) ;
else if ( V_42 -> V_7 == 0 )
V_58 |= V_60 ;
else
V_58 |= V_61 ;
if ( ! F_14 ( V_9 ) )
F_19 ( F_35 ( V_42 -> V_7 ) , 0 ) ;
F_19 ( V_13 -> V_17 , V_58 ) ;
}
static bool F_36 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_58 ;
bool V_62 ;
if ( V_13 -> V_63 ) {
bool V_64 = F_14 ( V_9 ) ;
T_1 V_65 ;
V_13 -> V_63 = 0 ;
V_65 = V_58 = F_8 ( V_13 -> V_17 ) ;
F_37 ( L_1 , V_58 ) ;
V_58 |= V_66 ;
if ( V_64 )
V_58 &= ~ V_18 ;
F_19 ( V_13 -> V_17 , V_58 ) ;
if ( F_38 ( ( F_8 ( V_13 -> V_17 ) & V_66 ) == 0 ,
1000 ) )
F_37 ( L_2 ) ;
if ( V_64 ) {
F_19 ( V_13 -> V_17 , V_65 ) ;
F_39 ( V_13 -> V_17 ) ;
}
}
V_58 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_58 & V_67 ) != 0 )
V_62 = true ;
else
V_62 = false ;
F_37 ( L_3 , V_58 , V_62 ) ;
return V_62 ;
}
static bool F_40 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_58 ;
bool V_62 ;
T_1 V_65 ;
V_65 = V_58 = F_8 ( V_13 -> V_17 ) ;
F_37 ( L_1 , V_58 ) ;
V_58 |= V_66 ;
F_19 ( V_13 -> V_17 , V_58 ) ;
if ( F_38 ( ( F_8 ( V_13 -> V_17 ) & V_66 ) == 0 ,
1000 ) ) {
F_37 ( L_2 ) ;
F_19 ( V_13 -> V_17 , V_65 ) ;
}
V_58 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_58 & V_67 ) != 0 )
V_62 = true ;
else
V_62 = false ;
F_37 ( L_4 , V_58 , V_62 ) ;
return V_62 ;
}
static bool F_41 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_68 , V_69 , V_70 ;
bool V_62 = false ;
int V_71 , V_72 = 0 ;
if ( F_14 ( V_9 ) )
return F_36 ( V_6 ) ;
if ( F_42 ( V_9 ) )
return F_40 ( V_6 ) ;
if ( F_43 ( V_9 ) && ! F_44 ( V_9 ) )
V_72 = 2 ;
else
V_72 = 1 ;
V_68 = V_69 = F_8 ( V_73 ) ;
V_68 |= V_74 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
F_19 ( V_73 , V_68 ) ;
if ( F_38 ( ( F_8 ( V_73 ) &
V_74 ) == 0 ,
1000 ) )
F_37 ( L_5 ) ;
}
V_70 = F_8 ( V_75 ) ;
if ( ( V_70 & V_76 ) != V_77 )
V_62 = true ;
F_19 ( V_75 , V_78 ) ;
F_19 ( V_73 , V_69 ) ;
return V_62 ;
}
static struct V_79 * F_45 ( struct V_5 * V_6 ,
struct V_80 * V_81 )
{
struct V_79 * V_79 ;
V_79 = F_46 ( V_6 , V_81 ) ;
if ( ! V_79 && ! F_47 ( V_81 ) ) {
F_37 ( L_6 ) ;
F_48 ( V_81 , true ) ;
V_79 = F_46 ( V_6 , V_81 ) ;
F_48 ( V_81 , false ) ;
}
return V_79 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_80 * V_82 )
{
struct V_79 * V_79 ;
int V_62 ;
V_79 = F_45 ( V_6 , V_82 ) ;
if ( ! V_79 )
return 0 ;
V_62 = F_50 ( V_6 , V_79 ) ;
F_51 ( V_79 ) ;
return V_62 ;
}
static bool F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_79 * V_79 ;
struct V_80 * V_81 ;
F_53 ( V_13 -> V_4 . type != V_83 ) ;
V_81 = F_54 ( V_11 , V_11 -> V_84 . V_85 ) ;
V_79 = F_45 ( V_6 , V_81 ) ;
if ( V_79 ) {
bool V_86 = V_79 -> V_87 & V_88 ;
if ( ! V_86 ) {
F_37 ( L_7 ) ;
return true ;
}
F_37 ( L_8 ) ;
} else {
F_37 ( L_9 ) ;
}
F_51 ( V_79 ) ;
return false ;
}
static enum V_89
F_55 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_33 ( V_13 -> V_4 . V_4 . V_42 ) -> V_7 ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 , V_93 ;
T_2 V_94 ;
T_2 V_95 , V_96 , V_97 ;
T_2 V_98 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
T_2 V_104 ;
T_3 V_105 ;
enum V_89 V_106 ;
F_37 ( L_10 ) ;
V_99 = F_35 ( V_7 ) ;
V_100 = F_56 ( V_7 ) ;
V_101 = F_57 ( V_7 ) ;
V_102 = F_58 ( V_7 ) ;
V_103 = F_59 ( V_7 ) ;
V_104 = F_60 ( V_7 ) ;
V_90 = F_8 ( V_99 ) ;
V_91 = F_8 ( V_100 ) ;
V_95 = F_8 ( V_101 ) ;
V_92 = ( ( V_91 >> 16 ) & 0xfff ) + 1 ;
V_93 = ( V_91 & 0x7ff ) + 1 ;
V_96 = ( V_95 & 0xfff ) + 1 ;
V_97 = ( ( V_95 >> 16 ) & 0xfff ) + 1 ;
F_19 ( V_99 , 0x500050 ) ;
if ( ! F_27 ( V_9 ) ) {
T_2 V_107 = F_8 ( V_103 ) ;
F_19 ( V_103 , V_107 | V_108 ) ;
F_39 ( V_103 ) ;
F_61 ( V_9 , V_7 ) ;
V_105 = F_62 ( V_109 ) ;
V_106 = ( ( V_105 & ( 1 << 4 ) ) != 0 ) ?
V_110 :
V_111 ;
F_19 ( V_103 , V_107 ) ;
} else {
bool V_112 = false ;
int V_113 , V_114 ;
if ( V_96 <= V_93 && V_97 >= V_92 ) {
T_2 V_115 = F_8 ( V_102 ) ;
T_2 V_116 = ( V_115 & 0xffff ) + 1 ;
V_96 = V_116 ;
F_19 ( V_101 ,
( V_96 - 1 ) |
( ( V_97 - 1 ) << 16 ) ) ;
V_112 = true ;
}
if ( V_96 - V_93 >= V_92 - V_97 )
V_94 = ( V_96 + V_93 ) >> 1 ;
else
V_94 = ( V_92 + V_97 ) >> 1 ;
while ( F_8 ( V_104 ) >= V_93 )
;
while ( ( V_98 = F_8 ( V_104 ) ) <= V_94 )
;
V_114 = 0 ;
V_113 = 0 ;
do {
V_113 ++ ;
V_105 = F_62 ( V_109 ) ;
if ( V_105 & ( 1 << 4 ) )
V_114 ++ ;
} while ( ( F_8 ( V_104 ) == V_98 ) );
if ( V_112 )
F_19 ( V_101 , V_95 ) ;
V_106 = V_114 * 4 > V_113 * 3 ?
V_110 :
V_111 ;
}
F_19 ( V_99 , V_90 ) ;
return V_106 ;
}
static enum V_89
F_63 ( struct V_5 * V_6 , bool V_117 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_89 V_106 ;
struct V_118 V_16 ;
F_64 ( V_11 ) ;
F_37 ( L_11 ,
V_6 -> V_4 . V_119 , F_65 ( V_6 ) ,
V_117 ) ;
V_15 = F_6 ( V_2 ) ;
F_66 ( V_11 , V_15 ) ;
if ( F_67 ( V_9 ) ) {
if ( F_41 ( V_6 ) ) {
F_37 ( L_12 ) ;
V_106 = V_110 ;
goto V_120;
} else
F_37 ( L_13 ) ;
}
if ( F_52 ( V_6 ) ) {
V_106 = V_110 ;
goto V_120;
}
if ( F_67 ( V_9 ) ) {
V_106 = V_111 ;
goto V_120;
}
if ( ! V_117 ) {
V_106 = V_6 -> V_106 ;
goto V_120;
}
if ( F_68 ( V_6 , NULL , & V_16 ) ) {
if ( F_52 ( V_6 ) )
V_106 = V_110 ;
else
V_106 = F_55 ( V_13 ) ;
F_69 ( V_6 , & V_16 ) ;
} else
V_106 = V_121 ;
V_120:
F_70 ( V_11 , V_15 ) ;
F_71 ( V_11 ) ;
return V_106 ;
}
static void F_72 ( struct V_5 * V_6 )
{
F_73 ( V_6 ) ;
F_51 ( V_6 ) ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_62 ;
struct V_80 * V_81 ;
V_15 = F_6 ( V_2 ) ;
F_66 ( V_11 , V_15 ) ;
V_81 = F_54 ( V_11 , V_11 -> V_84 . V_85 ) ;
V_62 = F_49 ( V_6 , V_81 ) ;
if ( V_62 || ! F_43 ( V_9 ) )
goto V_120;
V_81 = F_54 ( V_11 , V_122 ) ;
V_62 = F_49 ( V_6 , V_81 ) ;
V_120:
F_70 ( V_11 , V_15 ) ;
return V_62 ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_123 * V_124 ,
T_4 V_125 )
{
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_23 ( V_9 ) -> V_44 >= 5 ) {
T_1 V_58 ;
V_58 = F_8 ( V_13 -> V_17 ) ;
V_58 &= ~ V_126 ;
V_58 |= V_59 ;
F_19 ( V_13 -> V_17 , V_58 ) ;
F_39 ( V_13 -> V_17 ) ;
F_37 ( L_14 , V_58 ) ;
V_13 -> V_63 = 1 ;
}
}
static int T_5 F_77 ( const struct V_127 * V_119 )
{
F_78 ( L_15 , V_119 -> V_128 ) ;
return 1 ;
}
void F_79 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_129 * V_129 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_80 ( V_130 ) )
return;
V_13 = F_81 ( sizeof( struct V_1 ) , V_131 ) ;
if ( ! V_13 )
return;
V_129 = F_81 ( sizeof( * V_129 ) , V_131 ) ;
if ( ! V_129 ) {
F_51 ( V_13 ) ;
return;
}
V_6 = & V_129 -> V_4 ;
V_13 -> V_6 = V_129 ;
F_82 ( V_9 , & V_129 -> V_4 ,
& V_132 , V_133 ) ;
F_83 ( V_9 , & V_13 -> V_4 . V_4 , & V_134 ,
V_135 ) ;
F_84 ( V_129 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_83 ;
V_13 -> V_4 . V_136 = ( 1 << V_137 ) | ( 1 << V_138 ) ;
if ( F_85 ( V_9 ) )
V_13 -> V_4 . V_139 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_139 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_27 ( V_9 ) )
V_6 -> V_140 = 0 ;
else
V_6 -> V_140 = 1 ;
V_6 -> V_141 = 0 ;
if ( F_14 ( V_9 ) )
V_13 -> V_17 = V_142 ;
else if ( F_42 ( V_9 ) )
V_13 -> V_17 = V_143 ;
else
V_13 -> V_17 = V_144 ;
V_13 -> V_4 . V_145 = F_30 ;
V_13 -> V_4 . V_146 = F_32 ;
V_13 -> V_4 . V_147 = F_20 ;
V_13 -> V_4 . V_148 = F_21 ;
if ( F_67 ( V_9 ) )
V_13 -> V_4 . V_149 = V_150 ;
if ( F_31 ( V_9 ) ) {
V_13 -> V_4 . V_151 = F_16 ;
V_13 -> V_4 . V_152 = V_153 ;
} else {
V_13 -> V_4 . V_151 = F_13 ;
V_13 -> V_4 . V_152 = F_5 ;
}
V_129 -> V_152 = V_154 ;
V_129 -> V_155 = V_156 ;
F_86 ( V_6 , & V_157 ) ;
F_87 ( V_6 ) ;
if ( ! F_67 ( V_9 ) )
V_129 -> V_158 = V_159 ;
V_13 -> V_63 = 0 ;
if ( F_28 ( V_9 ) ) {
T_1 V_160 = V_161 |
V_162 ;
V_11 -> V_163 = F_8 ( V_164 ) & V_160 ;
}
F_76 ( V_6 ) ;
}
