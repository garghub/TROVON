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
static void F_19 ( struct V_2 * V_3 , int V_32 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_33 * V_34 = F_20 ( V_3 -> V_4 . V_34 ) ;
const struct V_35 * V_29 = & V_34 -> V_36 -> V_4 . V_29 ;
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
V_37 |= F_23 ( V_34 -> V_7 ) ;
else if ( V_34 -> V_7 == 0 )
V_37 |= V_40 ;
else
V_37 |= V_41 ;
if ( ! F_24 ( V_9 ) )
F_25 ( F_26 ( V_34 -> V_7 ) , 0 ) ;
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
F_25 ( V_12 -> V_17 , V_37 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_19 ( V_3 , V_47 ) ;
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
F_19 ( V_3 , V_42 ) ;
}
static enum V_48
F_31 ( struct V_5 * V_6 ,
struct V_35 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_49 = F_6 ( V_9 ) -> V_50 ;
int V_51 ;
if ( V_32 -> V_20 & V_52 )
return V_53 ;
if ( V_32 -> clock < 25000 )
return V_54 ;
if ( F_22 ( V_9 ) )
V_51 = 180000 ;
else if ( F_32 ( V_9 ) )
V_51 = 270000 ;
else if ( F_33 ( V_9 ) || F_34 ( V_9 ) )
V_51 = 400000 ;
else
V_51 = 350000 ;
if ( V_32 -> clock > V_51 )
return V_55 ;
if ( V_32 -> clock > V_49 )
return V_55 ;
if ( F_22 ( V_9 ) &&
( F_35 ( V_32 -> clock , 270000 , 24 ) > 2 ) )
return V_55 ;
return V_56 ;
}
static bool F_36 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_24 ( V_9 ) )
V_28 -> V_57 = true ;
if ( F_22 ( V_9 ) ) {
if ( V_28 -> V_58 && V_28 -> V_59 < 24 ) {
F_37 ( L_1 ) ;
return false ;
}
V_28 -> V_59 = 24 ;
}
if ( F_38 ( V_9 ) )
V_28 -> V_31 = 135000 * 2 ;
return true ;
}
static bool F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_37 ;
bool V_16 ;
if ( V_12 -> V_60 ) {
bool V_61 = F_24 ( V_9 ) ;
T_1 V_62 ;
V_12 -> V_60 = 0 ;
V_62 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_37 ( L_2 , V_37 ) ;
V_37 |= V_63 ;
if ( V_61 )
V_37 &= ~ V_18 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_40 ( V_11 ,
V_12 -> V_17 ,
V_63 , 0 ,
1000 ) )
F_37 ( L_3 ) ;
if ( V_61 ) {
F_25 ( V_12 -> V_17 , V_62 ) ;
F_41 ( V_12 -> V_17 ) ;
}
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_64 ) != 0 )
V_16 = true ;
else
V_16 = false ;
F_37 ( L_4 , V_37 , V_16 ) ;
return V_16 ;
}
static bool F_42 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
bool V_65 ;
T_1 V_37 ;
bool V_16 ;
T_1 V_62 ;
V_65 = F_43 ( V_11 , V_12 -> V_4 . V_66 ) ;
V_62 = V_37 = F_9 ( V_12 -> V_17 ) ;
F_37 ( L_2 , V_37 ) ;
V_37 |= V_63 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
if ( F_40 ( V_11 ,
V_12 -> V_17 ,
V_63 , 0 ,
1000 ) ) {
F_37 ( L_3 ) ;
F_25 ( V_12 -> V_17 , V_62 ) ;
}
V_37 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_37 & V_64 ) != 0 )
V_16 = true ;
else
V_16 = false ;
F_37 ( L_5 , V_37 , V_16 ) ;
if ( V_65 )
F_44 ( V_11 , V_12 -> V_4 . V_66 ) ;
return V_16 ;
}
static bool F_45 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_67 ;
bool V_16 = false ;
int V_68 , V_69 = 0 ;
if ( F_24 ( V_9 ) )
return F_39 ( V_6 ) ;
if ( F_32 ( V_9 ) )
return F_42 ( V_6 ) ;
if ( F_46 ( V_9 ) && ! F_47 ( V_9 ) )
V_69 = 2 ;
else
V_69 = 1 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
F_48 ( V_11 ,
V_70 ,
V_70 ) ;
if ( F_40 ( V_11 , V_71 ,
V_70 , 0 ,
1000 ) )
F_37 ( L_6 ) ;
}
V_67 = F_9 ( V_72 ) ;
if ( ( V_67 & V_73 ) != V_74 )
V_16 = true ;
F_25 ( V_72 , V_75 ) ;
F_48 ( V_11 , V_70 , 0 ) ;
return V_16 ;
}
static struct V_76 * F_49 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_76 * V_76 ;
V_76 = F_50 ( V_6 , V_78 ) ;
if ( ! V_76 && ! F_51 ( V_78 ) ) {
F_37 ( L_7 ) ;
F_52 ( V_78 , true ) ;
V_76 = F_50 ( V_6 , V_78 ) ;
F_52 ( V_78 , false ) ;
}
return V_76 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_77 * V_79 )
{
struct V_76 * V_76 ;
int V_16 ;
V_76 = F_49 ( V_6 , V_79 ) ;
if ( ! V_76 )
return 0 ;
V_16 = F_54 ( V_6 , V_76 ) ;
F_55 ( V_76 ) ;
return V_16 ;
}
static bool F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_6 ( V_12 -> V_4 . V_4 . V_9 ) ;
struct V_76 * V_76 ;
struct V_77 * V_78 ;
F_57 ( V_12 -> V_4 . type != V_80 ) ;
V_78 = F_58 ( V_11 , V_11 -> V_81 . V_82 ) ;
V_76 = F_49 ( V_6 , V_78 ) ;
if ( V_76 ) {
bool V_83 = V_76 -> V_84 & V_85 ;
if ( ! V_83 ) {
F_37 ( L_8 ) ;
return true ;
}
F_37 ( L_9 ) ;
} else {
F_37 ( L_10 ) ;
}
F_55 ( V_76 ) ;
return false ;
}
static enum V_86
F_59 ( struct V_1 * V_12 , T_2 V_7 )
{
struct V_8 * V_9 = V_12 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 , V_90 ;
T_2 V_91 ;
T_2 V_92 , V_93 , V_94 ;
T_2 V_95 ;
T_3 V_96 , V_97 ,
V_98 , V_99 , V_100 , V_101 ;
T_4 V_102 ;
enum V_86 V_103 ;
F_37 ( L_11 ) ;
V_96 = F_26 ( V_7 ) ;
V_97 = F_60 ( V_7 ) ;
V_98 = F_61 ( V_7 ) ;
V_99 = F_62 ( V_7 ) ;
V_100 = F_63 ( V_7 ) ;
V_101 = F_64 ( V_7 ) ;
V_87 = F_9 ( V_96 ) ;
V_88 = F_9 ( V_97 ) ;
V_92 = F_9 ( V_98 ) ;
V_89 = ( ( V_88 >> 16 ) & 0xfff ) + 1 ;
V_90 = ( V_88 & 0x7ff ) + 1 ;
V_93 = ( V_92 & 0xfff ) + 1 ;
V_94 = ( ( V_92 >> 16 ) & 0xfff ) + 1 ;
F_25 ( V_96 , 0x500050 ) ;
if ( ! F_65 ( V_9 ) ) {
T_2 V_104 = F_9 ( V_100 ) ;
F_25 ( V_100 , V_104 | V_105 ) ;
F_41 ( V_100 ) ;
F_66 ( V_9 , V_7 ) ;
V_102 = F_67 ( V_106 ) ;
V_103 = ( ( V_102 & ( 1 << 4 ) ) != 0 ) ?
V_107 :
V_108 ;
F_25 ( V_100 , V_104 ) ;
} else {
bool V_109 = false ;
int V_110 , V_111 ;
if ( V_93 <= V_90 && V_94 >= V_89 ) {
T_2 V_112 = F_9 ( V_99 ) ;
T_2 V_113 = ( V_112 & 0xffff ) + 1 ;
V_93 = V_113 ;
F_25 ( V_98 ,
( V_93 - 1 ) |
( ( V_94 - 1 ) << 16 ) ) ;
V_109 = true ;
}
if ( V_93 - V_90 >= V_89 - V_94 )
V_91 = ( V_93 + V_90 ) >> 1 ;
else
V_91 = ( V_89 + V_94 ) >> 1 ;
while ( F_9 ( V_101 ) >= V_90 )
;
while ( ( V_95 = F_9 ( V_101 ) ) <= V_91 )
;
V_111 = 0 ;
V_110 = 0 ;
do {
V_110 ++ ;
V_102 = F_67 ( V_106 ) ;
if ( V_102 & ( 1 << 4 ) )
V_111 ++ ;
} while ( ( F_9 ( V_101 ) == V_95 ) );
if ( V_109 )
F_25 ( V_98 , V_92 ) ;
V_103 = V_111 * 4 > V_110 * 3 ?
V_107 :
V_108 ;
}
F_25 ( V_96 , V_87 ) ;
return V_103 ;
}
static enum V_86
F_68 ( struct V_5 * V_6 , bool V_114 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
enum V_86 V_103 ;
struct V_115 V_15 ;
struct V_116 V_117 ;
F_37 ( L_12 ,
V_6 -> V_4 . V_118 , V_6 -> V_119 ,
V_114 ) ;
V_14 = F_7 ( V_2 ) ;
F_69 ( V_11 , V_14 ) ;
if ( F_70 ( V_9 ) ) {
if ( F_45 ( V_6 ) ) {
F_37 ( L_13 ) ;
V_103 = V_107 ;
goto V_19;
} else
F_37 ( L_14 ) ;
}
if ( F_56 ( V_6 ) ) {
V_103 = V_107 ;
goto V_19;
}
if ( F_70 ( V_9 ) && ! V_120 . V_121 ) {
V_103 = V_108 ;
goto V_19;
}
if ( ! V_114 ) {
V_103 = V_6 -> V_103 ;
goto V_19;
}
F_71 ( & V_117 , 0 ) ;
if ( F_72 ( V_6 , NULL , & V_15 , & V_117 ) ) {
if ( F_56 ( V_6 ) )
V_103 = V_107 ;
else if ( F_21 ( V_9 ) -> V_38 < 4 )
V_103 = F_59 ( V_12 ,
F_20 ( V_6 -> V_122 -> V_34 ) -> V_7 ) ;
else if ( V_120 . V_121 )
V_103 = V_108 ;
else
V_103 = V_123 ;
F_73 ( V_6 , & V_15 , & V_117 ) ;
} else
V_103 = V_123 ;
F_74 ( & V_117 ) ;
F_75 ( & V_117 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_103 ;
}
static void F_76 ( struct V_5 * V_6 )
{
F_77 ( V_6 ) ;
F_55 ( V_6 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_3 ( V_6 ) ;
struct V_2 * V_2 = & V_12 -> V_4 ;
enum V_13 V_14 ;
int V_16 ;
struct V_77 * V_78 ;
V_14 = F_7 ( V_2 ) ;
F_69 ( V_11 , V_14 ) ;
V_78 = F_58 ( V_11 , V_11 -> V_81 . V_82 ) ;
V_16 = F_53 ( V_6 , V_78 ) ;
if ( V_16 || ! F_46 ( V_9 ) )
goto V_19;
V_78 = F_58 ( V_11 , V_124 ) ;
V_16 = F_53 ( V_6 , V_78 ) ;
V_19:
F_13 ( V_11 , V_14 ) ;
return V_16 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_125 * V_126 ,
T_5 V_127 )
{
return 0 ;
}
void F_80 ( struct V_128 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_12 = F_1 ( F_81 ( V_3 ) ) ;
if ( F_21 ( V_9 ) -> V_38 >= 5 ) {
T_1 V_37 ;
V_37 = F_9 ( V_12 -> V_17 ) ;
V_37 &= ~ V_129 ;
V_37 |= V_39 ;
F_25 ( V_12 -> V_17 , V_37 ) ;
F_41 ( V_12 -> V_17 ) ;
F_37 ( L_15 , V_37 ) ;
V_12 -> V_60 = 1 ;
}
}
static int F_82 ( const struct V_130 * V_118 )
{
F_83 ( L_16 , V_118 -> V_131 ) ;
return 1 ;
}
void F_84 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_12 ;
struct V_132 * V_132 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_3 V_17 ;
T_1 V_37 ;
if ( F_85 ( V_133 ) )
return;
if ( F_24 ( V_9 ) )
V_17 = V_134 ;
else if ( F_32 ( V_9 ) )
V_17 = V_135 ;
else
V_17 = V_136 ;
V_37 = F_9 ( V_17 ) ;
if ( ( V_37 & V_18 ) == 0 ) {
F_25 ( V_17 , V_37 | V_18 |
V_44 | V_46 ) ;
if ( ( F_9 ( V_17 ) & V_18 ) == 0 )
return;
F_25 ( V_17 , V_37 ) ;
}
V_12 = F_86 ( sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_12 )
return;
V_132 = F_87 () ;
if ( ! V_132 ) {
F_55 ( V_12 ) ;
return;
}
V_6 = & V_132 -> V_4 ;
V_12 -> V_6 = V_132 ;
F_88 ( V_9 , & V_132 -> V_4 ,
& V_138 , V_139 ) ;
F_89 ( V_9 , & V_12 -> V_4 . V_4 , & V_140 ,
V_141 , L_17 ) ;
F_90 ( V_132 , & V_12 -> V_4 ) ;
V_12 -> V_4 . type = V_80 ;
V_12 -> V_4 . V_142 = ( 1 << V_143 ) | ( 1 << V_144 ) ;
if ( F_91 ( V_9 ) )
V_12 -> V_4 . V_145 = ( 1 << 0 ) ;
else
V_12 -> V_4 . V_145 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_65 ( V_9 ) )
V_6 -> V_146 = 0 ;
else
V_6 -> V_146 = 1 ;
V_6 -> V_147 = 0 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_4 . V_148 = F_36 ;
if ( F_24 ( V_9 ) ) {
V_12 -> V_4 . V_149 = F_28 ;
V_12 -> V_4 . V_150 = F_29 ;
} else {
V_12 -> V_4 . V_149 = F_27 ;
}
V_12 -> V_4 . V_151 = F_30 ;
if ( F_70 ( V_9 ) )
V_12 -> V_4 . V_66 = V_152 ;
if ( F_38 ( V_9 ) ) {
V_12 -> V_4 . V_153 = F_16 ;
V_12 -> V_4 . V_154 = V_155 ;
} else {
V_12 -> V_4 . V_153 = F_15 ;
V_12 -> V_4 . V_154 = F_5 ;
}
V_132 -> V_154 = V_156 ;
F_92 ( V_6 , & V_157 ) ;
if ( ! F_70 ( V_9 ) )
V_132 -> V_158 = V_159 ;
V_12 -> V_60 = 0 ;
if ( F_22 ( V_9 ) ) {
T_1 V_160 = V_161 |
V_162 ;
V_11 -> V_163 = F_9 ( F_93 ( V_164 ) ) & V_160 ;
}
F_80 ( & V_12 -> V_4 . V_4 ) ;
}
