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
struct V_33 * V_34 = F_19 ( V_3 -> V_4 . V_34 ) ;
struct V_35 * V_29 = & V_34 -> V_36 . V_29 ;
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
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_18 ( V_3 , V_13 -> V_6 -> V_4 . V_48 ) ;
}
static void F_27 ( struct V_5 * V_6 , int V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_49 * V_34 ;
int V_50 ;
if ( F_20 ( V_9 ) -> V_38 >= 5 && V_32 != V_42 )
V_32 = V_47 ;
if ( V_32 == V_6 -> V_48 )
return;
V_50 = V_6 -> V_48 ;
V_6 -> V_48 = V_32 ;
V_34 = V_3 -> V_4 . V_34 ;
if ( ! V_34 ) {
V_3 -> V_51 = false ;
return;
}
if ( V_32 == V_47 )
V_3 -> V_51 = false ;
else
V_3 -> V_51 = true ;
if ( V_32 < V_50 ) {
F_28 ( V_34 ) ;
F_18 ( V_3 , V_32 ) ;
} else {
F_18 ( V_3 , V_32 ) ;
F_28 ( V_34 ) ;
}
F_29 ( V_6 -> V_9 ) ;
}
static enum V_52
F_30 ( struct V_5 * V_6 ,
struct V_35 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_53 = 0 ;
if ( V_32 -> V_19 & V_54 )
return V_55 ;
if ( V_32 -> clock < 25000 )
return V_56 ;
if ( F_31 ( V_9 ) )
V_53 = 350000 ;
else
V_53 = 400000 ;
if ( V_32 -> clock > V_53 )
return V_57 ;
if ( F_21 ( V_9 ) &&
( F_32 ( V_32 -> clock , 270000 , 24 ) > 2 ) )
return V_57 ;
return V_58 ;
}
static bool F_33 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_14 ( V_9 ) )
V_27 -> V_59 = true ;
if ( F_21 ( V_9 ) )
V_27 -> V_60 = 24 ;
if ( F_34 ( V_9 ) )
V_27 -> V_30 = 135000 * 2 ;
return true ;
}
static bool F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_61 ;
if ( V_13 -> V_62 ) {
bool V_63 = F_14 ( V_9 ) ;
T_1 V_64 ;
V_13 -> V_62 = 0 ;
V_64 = V_37 = F_8 ( V_13 -> V_17 ) ;
F_36 ( L_1 , V_37 ) ;
V_37 |= V_65 ;
if ( V_63 )
V_37 &= ~ V_18 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
if ( F_37 ( ( F_8 ( V_13 -> V_17 ) & V_65 ) == 0 ,
1000 ) )
F_36 ( L_2 ) ;
if ( V_63 ) {
F_23 ( V_13 -> V_17 , V_64 ) ;
F_38 ( V_13 -> V_17 ) ;
}
}
V_37 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_37 & V_66 ) != 0 )
V_61 = true ;
else
V_61 = false ;
F_36 ( L_3 , V_37 , V_61 ) ;
return V_61 ;
}
static bool F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_61 ;
T_1 V_64 ;
V_64 = V_37 = F_8 ( V_13 -> V_17 ) ;
F_36 ( L_1 , V_37 ) ;
V_37 |= V_65 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
if ( F_37 ( ( F_8 ( V_13 -> V_17 ) & V_65 ) == 0 ,
1000 ) ) {
F_36 ( L_2 ) ;
F_23 ( V_13 -> V_17 , V_64 ) ;
}
V_37 = F_8 ( V_13 -> V_17 ) ;
if ( ( V_37 & V_66 ) != 0 )
V_61 = true ;
else
V_61 = false ;
F_36 ( L_4 , V_37 , V_61 ) ;
return V_61 ;
}
static bool F_40 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_67 , V_68 , V_69 ;
bool V_61 = false ;
int V_70 , V_71 = 0 ;
if ( F_14 ( V_9 ) )
return F_35 ( V_6 ) ;
if ( F_41 ( V_9 ) )
return F_39 ( V_6 ) ;
if ( F_42 ( V_9 ) && ! F_43 ( V_9 ) )
V_71 = 2 ;
else
V_71 = 1 ;
V_67 = V_68 = F_8 ( V_72 ) ;
V_67 |= V_73 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
F_23 ( V_72 , V_67 ) ;
if ( F_37 ( ( F_8 ( V_72 ) &
V_73 ) == 0 ,
1000 ) )
F_36 ( L_5 ) ;
}
V_69 = F_8 ( V_74 ) ;
if ( ( V_69 & V_75 ) != V_76 )
V_61 = true ;
F_23 ( V_74 , V_77 ) ;
F_23 ( V_72 , V_68 ) ;
return V_61 ;
}
static struct V_78 * F_44 ( struct V_5 * V_6 ,
struct V_79 * V_80 )
{
struct V_78 * V_78 ;
V_78 = F_45 ( V_6 , V_80 ) ;
if ( ! V_78 && ! F_46 ( V_80 ) ) {
F_36 ( L_6 ) ;
F_47 ( V_80 , true ) ;
V_78 = F_45 ( V_6 , V_80 ) ;
F_47 ( V_80 , false ) ;
}
return V_78 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_79 * V_81 )
{
struct V_78 * V_78 ;
int V_61 ;
V_78 = F_44 ( V_6 , V_81 ) ;
if ( ! V_78 )
return 0 ;
V_61 = F_49 ( V_6 , V_78 ) ;
F_50 ( V_78 ) ;
return V_61 ;
}
static bool F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_78 * V_78 ;
struct V_79 * V_80 ;
F_52 ( V_13 -> V_4 . type != V_82 ) ;
V_80 = F_53 ( V_11 , V_11 -> V_83 . V_84 ) ;
V_78 = F_44 ( V_6 , V_80 ) ;
if ( V_78 ) {
bool V_85 = V_78 -> V_86 & V_87 ;
if ( ! V_85 ) {
F_36 ( L_7 ) ;
return true ;
}
F_36 ( L_8 ) ;
} else {
F_36 ( L_9 ) ;
}
F_50 ( V_78 ) ;
return false ;
}
static enum V_88
F_54 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_19 ( V_13 -> V_4 . V_4 . V_34 ) -> V_7 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 , V_92 ;
T_2 V_93 ;
T_2 V_94 , V_95 , V_96 ;
T_2 V_97 ;
T_2 V_98 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
T_3 V_104 ;
enum V_88 V_105 ;
F_36 ( L_10 ) ;
V_98 = F_24 ( V_7 ) ;
V_99 = F_55 ( V_7 ) ;
V_100 = F_56 ( V_7 ) ;
V_101 = F_57 ( V_7 ) ;
V_102 = F_58 ( V_7 ) ;
V_103 = F_59 ( V_7 ) ;
V_89 = F_8 ( V_98 ) ;
V_90 = F_8 ( V_99 ) ;
V_94 = F_8 ( V_100 ) ;
V_91 = ( ( V_90 >> 16 ) & 0xfff ) + 1 ;
V_92 = ( V_90 & 0x7ff ) + 1 ;
V_95 = ( V_94 & 0xfff ) + 1 ;
V_96 = ( ( V_94 >> 16 ) & 0xfff ) + 1 ;
F_23 ( V_98 , 0x500050 ) ;
if ( ! F_31 ( V_9 ) ) {
T_2 V_106 = F_8 ( V_102 ) ;
F_23 ( V_102 , V_106 | V_107 ) ;
F_38 ( V_102 ) ;
F_60 ( V_9 , V_7 ) ;
V_104 = F_61 ( V_108 ) ;
V_105 = ( ( V_104 & ( 1 << 4 ) ) != 0 ) ?
V_109 :
V_110 ;
F_23 ( V_102 , V_106 ) ;
} else {
bool V_111 = false ;
int V_112 , V_113 ;
if ( V_95 <= V_92 && V_96 >= V_91 ) {
T_2 V_114 = F_8 ( V_101 ) ;
T_2 V_115 = ( V_114 & 0xffff ) + 1 ;
V_95 = V_115 ;
F_23 ( V_100 ,
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
V_104 = F_61 ( V_108 ) ;
if ( V_104 & ( 1 << 4 ) )
V_113 ++ ;
} while ( ( F_8 ( V_103 ) == V_97 ) );
if ( V_111 )
F_23 ( V_100 , V_94 ) ;
V_105 = V_113 * 4 > V_112 * 3 ?
V_109 :
V_110 ;
}
F_23 ( V_98 , V_89 ) ;
return V_105 ;
}
static enum V_88
F_62 ( struct V_5 * V_6 , bool V_116 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_88 V_105 ;
struct V_117 V_16 ;
struct V_118 V_119 ;
F_63 ( V_11 ) ;
F_36 ( L_11 ,
V_6 -> V_4 . V_120 , V_6 -> V_121 ,
V_116 ) ;
V_15 = F_6 ( V_2 ) ;
F_64 ( V_11 , V_15 ) ;
if ( F_65 ( V_9 ) ) {
if ( F_40 ( V_6 ) ) {
F_36 ( L_12 ) ;
V_105 = V_109 ;
goto V_122;
} else
F_36 ( L_13 ) ;
}
if ( F_51 ( V_6 ) ) {
V_105 = V_109 ;
goto V_122;
}
if ( F_65 ( V_9 ) ) {
V_105 = V_110 ;
goto V_122;
}
if ( ! V_116 ) {
V_105 = V_6 -> V_105 ;
goto V_122;
}
if ( F_66 ( V_6 , NULL , & V_16 , & V_119 ) ) {
if ( F_51 ( V_6 ) )
V_105 = V_109 ;
else
V_105 = F_54 ( V_13 ) ;
F_67 ( V_6 , & V_16 , & V_119 ) ;
} else
V_105 = V_123 ;
V_122:
F_68 ( V_11 , V_15 ) ;
F_69 ( V_11 ) ;
return V_105 ;
}
static void F_70 ( struct V_5 * V_6 )
{
F_71 ( V_6 ) ;
F_50 ( V_6 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_61 ;
struct V_79 * V_80 ;
V_15 = F_6 ( V_2 ) ;
F_64 ( V_11 , V_15 ) ;
V_80 = F_53 ( V_11 , V_11 -> V_83 . V_84 ) ;
V_61 = F_48 ( V_6 , V_80 ) ;
if ( V_61 || ! F_42 ( V_9 ) )
goto V_122;
V_80 = F_53 ( V_11 , V_124 ) ;
V_61 = F_48 ( V_6 , V_80 ) ;
V_122:
F_68 ( V_11 , V_15 ) ;
return V_61 ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_125 * V_126 ,
T_4 V_127 )
{
return 0 ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_20 ( V_9 ) -> V_38 >= 5 ) {
T_1 V_37 ;
V_37 = F_8 ( V_13 -> V_17 ) ;
V_37 &= ~ V_128 ;
V_37 |= V_39 ;
F_23 ( V_13 -> V_17 , V_37 ) ;
F_38 ( V_13 -> V_17 ) ;
F_36 ( L_14 , V_37 ) ;
V_13 -> V_62 = 1 ;
}
}
static int T_5 F_75 ( const struct V_129 * V_120 )
{
F_76 ( L_15 , V_120 -> V_130 ) ;
return 1 ;
}
void F_77 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_131 * V_131 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_78 ( V_132 ) )
return;
V_13 = F_79 ( sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_13 )
return;
V_131 = F_79 ( sizeof( * V_131 ) , V_133 ) ;
if ( ! V_131 ) {
F_50 ( V_13 ) ;
return;
}
V_6 = & V_131 -> V_4 ;
V_13 -> V_6 = V_131 ;
F_80 ( V_9 , & V_131 -> V_4 ,
& V_134 , V_135 ) ;
F_81 ( V_9 , & V_13 -> V_4 . V_4 , & V_136 ,
V_137 ) ;
F_82 ( V_131 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_82 ;
V_13 -> V_4 . V_138 = ( 1 << V_139 ) | ( 1 << V_140 ) ;
if ( F_83 ( V_9 ) )
V_13 -> V_4 . V_141 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_141 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_31 ( V_9 ) )
V_6 -> V_142 = 0 ;
else
V_6 -> V_142 = 1 ;
V_6 -> V_143 = 0 ;
if ( F_14 ( V_9 ) )
V_13 -> V_17 = V_144 ;
else if ( F_41 ( V_9 ) )
V_13 -> V_17 = V_145 ;
else
V_13 -> V_17 = V_146 ;
V_13 -> V_4 . V_147 = F_33 ;
V_13 -> V_4 . V_148 = F_25 ;
V_13 -> V_4 . V_149 = F_26 ;
if ( F_65 ( V_9 ) )
V_13 -> V_4 . V_150 = V_151 ;
if ( F_34 ( V_9 ) ) {
V_13 -> V_4 . V_152 = F_16 ;
V_13 -> V_4 . V_153 = V_154 ;
} else {
V_13 -> V_4 . V_152 = F_13 ;
V_13 -> V_4 . V_153 = F_5 ;
}
V_131 -> V_153 = V_155 ;
V_131 -> V_156 = V_157 ;
F_84 ( V_6 , & V_158 ) ;
F_85 ( V_6 ) ;
if ( ! F_65 ( V_9 ) )
V_131 -> V_159 = V_160 ;
V_13 -> V_62 = 0 ;
if ( F_21 ( V_9 ) ) {
T_1 V_161 = V_162 |
V_163 ;
V_11 -> V_164 = F_8 ( V_165 ) & V_161 ;
}
F_74 ( V_6 ) ;
}
