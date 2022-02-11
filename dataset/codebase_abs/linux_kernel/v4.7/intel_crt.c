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
V_29 -> V_4 . V_30 . V_21 |= F_13 ( V_3 ) ;
V_29 -> V_4 . V_30 . V_31 = V_29 -> V_32 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_10 * V_11 = F_16 ( V_3 -> V_4 . V_9 ) ;
F_17 ( V_3 , V_29 ) ;
V_29 -> V_4 . V_30 . V_21 &= ~ ( V_23 |
V_24 |
V_26 |
V_27 ) ;
V_29 -> V_4 . V_30 . V_21 |= F_13 ( V_3 ) ;
V_29 -> V_4 . V_30 . V_31 = F_18 ( V_11 ) ;
}
static void F_19 ( struct V_2 * V_3 , int V_33 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_20 ( V_3 -> V_4 . V_35 ) ;
const struct V_36 * V_30 = & V_35 -> V_37 -> V_4 . V_30 ;
T_1 V_38 ;
if ( F_21 ( V_9 ) -> V_39 >= 5 )
V_38 = V_40 ;
else
V_38 = 0 ;
if ( V_30 -> V_21 & V_23 )
V_38 |= V_22 ;
if ( V_30 -> V_21 & V_26 )
V_38 |= V_25 ;
if ( F_22 ( V_9 ) )
;
else if ( F_9 ( V_9 ) )
V_38 |= F_23 ( V_35 -> V_7 ) ;
else if ( V_35 -> V_7 == 0 )
V_38 |= V_41 ;
else
V_38 |= V_42 ;
if ( ! F_24 ( V_9 ) )
F_25 ( F_26 ( V_35 -> V_7 ) , 0 ) ;
switch ( V_33 ) {
case V_43 :
V_38 |= V_19 ;
break;
case V_44 :
V_38 |= V_19 | V_45 ;
break;
case V_46 :
V_38 |= V_19 | V_47 ;
break;
case V_48 :
V_38 |= V_45 | V_47 ;
break;
}
F_25 ( V_13 -> V_18 , V_38 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_19 ( V_3 , V_48 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
}
static void F_29 ( struct V_2 * V_3 )
{
F_27 ( V_3 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
F_19 ( V_3 , V_43 ) ;
}
static enum V_49
F_31 ( struct V_5 * V_6 ,
struct V_36 * V_33 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_50 = F_16 ( V_9 ) -> V_51 ;
int V_52 ;
if ( V_33 -> V_21 & V_53 )
return V_54 ;
if ( V_33 -> clock < 25000 )
return V_55 ;
if ( F_22 ( V_9 ) )
V_52 = 180000 ;
else if ( F_32 ( V_9 ) )
V_52 = 270000 ;
else if ( F_33 ( V_9 ) || F_34 ( V_9 ) )
V_52 = 400000 ;
else
V_52 = 350000 ;
if ( V_33 -> clock > V_52 )
return V_56 ;
if ( V_33 -> clock > V_50 )
return V_56 ;
if ( F_22 ( V_9 ) &&
( F_35 ( V_33 -> clock , 270000 , 24 ) > 2 ) )
return V_56 ;
return V_57 ;
}
static bool F_36 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_24 ( V_9 ) )
V_29 -> V_58 = true ;
if ( F_22 ( V_9 ) ) {
if ( V_29 -> V_59 && V_29 -> V_60 < 24 ) {
F_37 ( L_1 ) ;
return false ;
}
V_29 -> V_60 = 24 ;
}
if ( F_38 ( V_9 ) )
V_29 -> V_32 = 135000 * 2 ;
return true ;
}
static bool F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_38 ;
bool V_17 ;
if ( V_13 -> V_61 ) {
bool V_62 = F_24 ( V_9 ) ;
T_1 V_63 ;
V_13 -> V_61 = 0 ;
V_63 = V_38 = F_8 ( V_13 -> V_18 ) ;
F_37 ( L_2 , V_38 ) ;
V_38 |= V_64 ;
if ( V_62 )
V_38 &= ~ V_19 ;
F_25 ( V_13 -> V_18 , V_38 ) ;
if ( F_40 ( ( F_8 ( V_13 -> V_18 ) & V_64 ) == 0 ,
1000 ) )
F_37 ( L_3 ) ;
if ( V_62 ) {
F_25 ( V_13 -> V_18 , V_63 ) ;
F_41 ( V_13 -> V_18 ) ;
}
}
V_38 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_38 & V_65 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_37 ( L_4 , V_38 , V_17 ) ;
return V_17 ;
}
static bool F_42 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_38 ;
bool V_17 ;
T_1 V_63 ;
V_63 = V_38 = F_8 ( V_13 -> V_18 ) ;
F_37 ( L_2 , V_38 ) ;
V_38 |= V_64 ;
F_25 ( V_13 -> V_18 , V_38 ) ;
if ( F_40 ( ( F_8 ( V_13 -> V_18 ) & V_64 ) == 0 ,
1000 ) ) {
F_37 ( L_3 ) ;
F_25 ( V_13 -> V_18 , V_63 ) ;
}
V_38 = F_8 ( V_13 -> V_18 ) ;
if ( ( V_38 & V_65 ) != 0 )
V_17 = true ;
else
V_17 = false ;
F_37 ( L_5 , V_38 , V_17 ) ;
return V_17 ;
}
static bool F_43 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_66 ;
bool V_17 = false ;
int V_67 , V_68 = 0 ;
if ( F_24 ( V_9 ) )
return F_39 ( V_6 ) ;
if ( F_32 ( V_9 ) )
return F_42 ( V_6 ) ;
if ( F_44 ( V_9 ) && ! F_45 ( V_9 ) )
V_68 = 2 ;
else
V_68 = 1 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
F_46 ( V_11 ,
V_69 ,
V_69 ) ;
if ( F_40 ( ( F_8 ( V_70 ) &
V_69 ) == 0 ,
1000 ) )
F_37 ( L_6 ) ;
}
V_66 = F_8 ( V_71 ) ;
if ( ( V_66 & V_72 ) != V_73 )
V_17 = true ;
F_25 ( V_71 , V_74 ) ;
F_46 ( V_11 , V_69 , 0 ) ;
return V_17 ;
}
static struct V_75 * F_47 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_75 * V_75 ;
V_75 = F_48 ( V_6 , V_77 ) ;
if ( ! V_75 && ! F_49 ( V_77 ) ) {
F_37 ( L_7 ) ;
F_50 ( V_77 , true ) ;
V_75 = F_48 ( V_6 , V_77 ) ;
F_50 ( V_77 , false ) ;
}
return V_75 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_76 * V_78 )
{
struct V_75 * V_75 ;
int V_17 ;
V_75 = F_47 ( V_6 , V_78 ) ;
if ( ! V_75 )
return 0 ;
V_17 = F_52 ( V_6 , V_75 ) ;
F_53 ( V_75 ) ;
return V_17 ;
}
static bool F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_75 * V_75 ;
struct V_76 * V_77 ;
F_55 ( V_13 -> V_4 . type != V_79 ) ;
V_77 = F_56 ( V_11 , V_11 -> V_80 . V_81 ) ;
V_75 = F_47 ( V_6 , V_77 ) ;
if ( V_75 ) {
bool V_82 = V_75 -> V_83 & V_84 ;
if ( ! V_82 ) {
F_37 ( L_8 ) ;
return true ;
}
F_37 ( L_9 ) ;
} else {
F_37 ( L_10 ) ;
}
F_53 ( V_75 ) ;
return false ;
}
static enum V_85
F_57 ( struct V_1 * V_13 , T_2 V_7 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_86 ;
T_2 V_87 ;
T_2 V_88 , V_89 ;
T_2 V_90 ;
T_2 V_91 , V_92 , V_93 ;
T_2 V_94 ;
T_3 V_95 , V_96 ,
V_97 , V_98 , V_99 , V_100 ;
T_4 V_101 ;
enum V_85 V_102 ;
F_37 ( L_11 ) ;
V_95 = F_26 ( V_7 ) ;
V_96 = F_58 ( V_7 ) ;
V_97 = F_59 ( V_7 ) ;
V_98 = F_60 ( V_7 ) ;
V_99 = F_61 ( V_7 ) ;
V_100 = F_62 ( V_7 ) ;
V_86 = F_8 ( V_95 ) ;
V_87 = F_8 ( V_96 ) ;
V_91 = F_8 ( V_97 ) ;
V_88 = ( ( V_87 >> 16 ) & 0xfff ) + 1 ;
V_89 = ( V_87 & 0x7ff ) + 1 ;
V_92 = ( V_91 & 0xfff ) + 1 ;
V_93 = ( ( V_91 >> 16 ) & 0xfff ) + 1 ;
F_25 ( V_95 , 0x500050 ) ;
if ( ! F_63 ( V_9 ) ) {
T_2 V_103 = F_8 ( V_99 ) ;
F_25 ( V_99 , V_103 | V_104 ) ;
F_41 ( V_99 ) ;
F_64 ( V_9 , V_7 ) ;
V_101 = F_65 ( V_105 ) ;
V_102 = ( ( V_101 & ( 1 << 4 ) ) != 0 ) ?
V_106 :
V_107 ;
F_25 ( V_99 , V_103 ) ;
} else {
bool V_108 = false ;
int V_109 , V_110 ;
if ( V_92 <= V_89 && V_93 >= V_88 ) {
T_2 V_111 = F_8 ( V_98 ) ;
T_2 V_112 = ( V_111 & 0xffff ) + 1 ;
V_92 = V_112 ;
F_25 ( V_97 ,
( V_92 - 1 ) |
( ( V_93 - 1 ) << 16 ) ) ;
V_108 = true ;
}
if ( V_92 - V_89 >= V_88 - V_93 )
V_90 = ( V_92 + V_89 ) >> 1 ;
else
V_90 = ( V_88 + V_93 ) >> 1 ;
while ( F_8 ( V_100 ) >= V_89 )
;
while ( ( V_94 = F_8 ( V_100 ) ) <= V_90 )
;
V_110 = 0 ;
V_109 = 0 ;
do {
V_109 ++ ;
V_101 = F_65 ( V_105 ) ;
if ( V_101 & ( 1 << 4 ) )
V_110 ++ ;
} while ( ( F_8 ( V_100 ) == V_94 ) );
if ( V_108 )
F_25 ( V_97 , V_91 ) ;
V_102 = V_110 * 4 > V_109 * 3 ?
V_106 :
V_107 ;
}
F_25 ( V_95 , V_86 ) ;
return V_102 ;
}
static enum V_85
F_66 ( struct V_5 * V_6 , bool V_113 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
enum V_85 V_102 ;
struct V_114 V_16 ;
struct V_115 V_116 ;
F_37 ( L_12 ,
V_6 -> V_4 . V_117 , V_6 -> V_118 ,
V_113 ) ;
V_15 = F_6 ( V_2 ) ;
F_67 ( V_11 , V_15 ) ;
if ( F_68 ( V_9 ) ) {
if ( F_43 ( V_6 ) ) {
F_37 ( L_13 ) ;
V_102 = V_106 ;
goto V_20;
} else
F_37 ( L_14 ) ;
}
if ( F_54 ( V_6 ) ) {
V_102 = V_106 ;
goto V_20;
}
if ( F_68 ( V_9 ) && ! V_119 . V_120 ) {
V_102 = V_107 ;
goto V_20;
}
if ( ! V_113 ) {
V_102 = V_6 -> V_102 ;
goto V_20;
}
F_69 ( & V_116 , 0 ) ;
if ( F_70 ( V_6 , NULL , & V_16 , & V_116 ) ) {
if ( F_54 ( V_6 ) )
V_102 = V_106 ;
else if ( F_21 ( V_9 ) -> V_39 < 4 )
V_102 = F_57 ( V_13 ,
F_20 ( V_6 -> V_121 -> V_35 ) -> V_7 ) ;
else if ( V_119 . V_120 )
V_102 = V_107 ;
else
V_102 = V_122 ;
F_71 ( V_6 , & V_16 , & V_116 ) ;
} else
V_102 = V_122 ;
F_72 ( & V_116 ) ;
F_73 ( & V_116 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_102 ;
}
static void F_74 ( struct V_5 * V_6 )
{
F_75 ( V_6 ) ;
F_53 ( V_6 ) ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_13 -> V_4 ;
enum V_14 V_15 ;
int V_17 ;
struct V_76 * V_77 ;
V_15 = F_6 ( V_2 ) ;
F_67 ( V_11 , V_15 ) ;
V_77 = F_56 ( V_11 , V_11 -> V_80 . V_81 ) ;
V_17 = F_51 ( V_6 , V_77 ) ;
if ( V_17 || ! F_44 ( V_9 ) )
goto V_20;
V_77 = F_56 ( V_11 , V_123 ) ;
V_17 = F_51 ( V_6 , V_77 ) ;
V_20:
F_12 ( V_11 , V_15 ) ;
return V_17 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_124 * V_125 ,
T_5 V_126 )
{
return 0 ;
}
static void F_78 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_21 ( V_9 ) -> V_39 >= 5 ) {
T_1 V_38 ;
V_38 = F_8 ( V_13 -> V_18 ) ;
V_38 &= ~ V_127 ;
V_38 |= V_40 ;
F_25 ( V_13 -> V_18 , V_38 ) ;
F_41 ( V_13 -> V_18 ) ;
F_37 ( L_15 , V_38 ) ;
V_13 -> V_61 = 1 ;
}
}
static int F_79 ( const struct V_128 * V_117 )
{
F_80 ( L_16 , V_117 -> V_129 ) ;
return 1 ;
}
void F_81 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_130 * V_130 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_3 V_18 ;
T_1 V_38 ;
if ( F_82 ( V_131 ) )
return;
if ( F_24 ( V_9 ) )
V_18 = V_132 ;
else if ( F_32 ( V_9 ) )
V_18 = V_133 ;
else
V_18 = V_134 ;
V_38 = F_8 ( V_18 ) ;
if ( ( V_38 & V_19 ) == 0 ) {
F_25 ( V_18 , V_38 | V_19 |
V_45 | V_47 ) ;
if ( ( F_8 ( V_18 ) & V_19 ) == 0 )
return;
F_25 ( V_18 , V_38 ) ;
}
V_13 = F_83 ( sizeof( struct V_1 ) , V_135 ) ;
if ( ! V_13 )
return;
V_130 = F_84 () ;
if ( ! V_130 ) {
F_53 ( V_13 ) ;
return;
}
V_6 = & V_130 -> V_4 ;
V_13 -> V_6 = V_130 ;
F_85 ( V_9 , & V_130 -> V_4 ,
& V_136 , V_137 ) ;
F_86 ( V_9 , & V_13 -> V_4 . V_4 , & V_138 ,
V_139 , NULL ) ;
F_87 ( V_130 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_79 ;
V_13 -> V_4 . V_140 = ( 1 << V_141 ) | ( 1 << V_142 ) ;
if ( F_88 ( V_9 ) )
V_13 -> V_4 . V_143 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_143 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_63 ( V_9 ) )
V_6 -> V_144 = 0 ;
else
V_6 -> V_144 = 1 ;
V_6 -> V_145 = 0 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_4 . V_146 = F_36 ;
if ( F_24 ( V_9 ) ) {
V_13 -> V_4 . V_147 = F_28 ;
V_13 -> V_4 . V_148 = F_29 ;
} else {
V_13 -> V_4 . V_147 = F_27 ;
}
V_13 -> V_4 . V_149 = F_30 ;
if ( F_68 ( V_9 ) )
V_13 -> V_4 . V_150 = V_151 ;
if ( F_38 ( V_9 ) ) {
V_13 -> V_4 . V_152 = F_15 ;
V_13 -> V_4 . V_153 = V_154 ;
} else {
V_13 -> V_4 . V_152 = F_14 ;
V_13 -> V_4 . V_153 = F_5 ;
}
V_130 -> V_153 = V_155 ;
V_130 -> V_156 = V_157 ;
F_89 ( V_6 , & V_158 ) ;
F_90 ( V_6 ) ;
if ( ! F_68 ( V_9 ) )
V_130 -> V_159 = V_160 ;
V_13 -> V_61 = 0 ;
if ( F_22 ( V_9 ) ) {
T_1 V_161 = V_162 |
V_163 ;
V_11 -> V_164 = F_8 ( F_91 ( V_165 ) ) & V_161 ;
}
F_78 ( V_6 ) ;
}
