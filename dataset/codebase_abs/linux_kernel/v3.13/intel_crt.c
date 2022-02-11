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
T_1 V_14 ;
V_14 = F_6 ( V_13 -> V_15 ) ;
if ( ! ( V_14 & V_16 ) )
return false ;
if ( F_7 ( V_9 ) )
* V_7 = F_8 ( V_14 ) ;
else
* V_7 = F_9 ( V_14 ) ;
return true ;
}
static unsigned int F_10 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_14 , V_17 = 0 ;
V_14 = F_6 ( V_13 -> V_15 ) ;
if ( V_14 & V_18 )
V_17 |= V_19 ;
else
V_17 |= V_20 ;
if ( V_14 & V_21 )
V_17 |= V_22 ;
else
V_17 |= V_23 ;
return V_17 ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
int V_26 ;
V_25 -> V_27 . V_17 |= F_10 ( V_3 ) ;
V_26 = V_25 -> V_28 ;
if ( F_12 ( V_9 ) )
F_13 ( V_25 , V_26 ) ;
V_25 -> V_27 . V_29 = V_26 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
F_15 ( V_3 , V_25 ) ;
V_25 -> V_27 . V_17 &= ~ ( V_19 |
V_20 |
V_22 |
V_23 ) ;
V_25 -> V_27 . V_17 |= F_10 ( V_3 ) ;
}
static void F_16 ( struct V_2 * V_3 , int V_30 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_31 ;
V_31 = F_6 ( V_13 -> V_15 ) ;
V_31 &= ~ ( V_32 | V_33 ) ;
V_31 &= ~ V_16 ;
switch ( V_30 ) {
case V_34 :
V_31 |= V_16 ;
break;
case V_35 :
V_31 |= V_16 | V_32 ;
break;
case V_36 :
V_31 |= V_16 | V_33 ;
break;
case V_37 :
V_31 |= V_32 | V_33 ;
break;
}
F_17 ( V_13 -> V_15 , V_31 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_16 ( V_3 , V_37 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_16 ( V_3 , V_13 -> V_6 -> V_4 . V_38 ) ;
}
static void F_20 ( struct V_5 * V_6 , int V_30 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_39 * V_40 ;
int V_41 ;
if ( F_21 ( V_9 ) -> V_42 >= 5 && V_30 != V_34 )
V_30 = V_37 ;
if ( V_30 == V_6 -> V_38 )
return;
V_41 = V_6 -> V_38 ;
V_6 -> V_38 = V_30 ;
V_40 = V_3 -> V_4 . V_40 ;
if ( ! V_40 ) {
V_3 -> V_43 = false ;
return;
}
if ( V_30 == V_37 )
V_3 -> V_43 = false ;
else
V_3 -> V_43 = true ;
if ( V_30 < V_41 ) {
F_22 ( V_40 ) ;
F_16 ( V_3 , V_30 ) ;
} else {
F_16 ( V_3 , V_30 ) ;
F_22 ( V_40 ) ;
}
F_23 ( V_6 -> V_9 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_44 * V_30 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_45 = 0 ;
if ( V_30 -> V_17 & V_46 )
return V_47 ;
if ( V_30 -> clock < 25000 )
return V_48 ;
if ( F_25 ( V_9 ) )
V_45 = 350000 ;
else
V_45 = 400000 ;
if ( V_30 -> clock > V_45 )
return V_49 ;
if ( F_26 ( V_9 ) &&
( F_27 ( V_30 -> clock , 270000 , 24 ) > 2 ) )
return V_49 ;
return V_50 ;
}
static bool F_28 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_12 ( V_9 ) )
V_25 -> V_51 = true ;
if ( F_26 ( V_9 ) )
V_25 -> V_52 = 24 ;
return true ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_53 * V_40 = F_30 ( V_3 -> V_4 . V_40 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_44 * V_27 = & V_40 -> V_54 . V_27 ;
T_1 V_55 ;
if ( F_21 ( V_9 ) -> V_42 >= 5 )
V_55 = V_56 ;
else
V_55 = 0 ;
if ( V_27 -> V_17 & V_19 )
V_55 |= V_18 ;
if ( V_27 -> V_17 & V_22 )
V_55 |= V_21 ;
if ( F_26 ( V_9 ) )
;
else if ( F_7 ( V_9 ) )
V_55 |= F_31 ( V_40 -> V_7 ) ;
else if ( V_40 -> V_7 == 0 )
V_55 |= V_57 ;
else
V_55 |= V_58 ;
if ( ! F_12 ( V_9 ) )
F_17 ( F_32 ( V_40 -> V_7 ) , 0 ) ;
F_17 ( V_13 -> V_15 , V_55 ) ;
}
static bool F_33 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_55 ;
bool V_59 ;
if ( V_13 -> V_60 ) {
bool V_61 = F_12 ( V_9 ) ;
T_1 V_62 ;
V_13 -> V_60 = 0 ;
V_62 = V_55 = F_6 ( V_13 -> V_15 ) ;
F_34 ( L_1 , V_55 ) ;
V_55 |= V_63 ;
if ( V_61 )
V_55 &= ~ V_16 ;
F_17 ( V_13 -> V_15 , V_55 ) ;
if ( F_35 ( ( F_6 ( V_13 -> V_15 ) & V_63 ) == 0 ,
1000 ) )
F_34 ( L_2 ) ;
if ( V_61 ) {
F_17 ( V_13 -> V_15 , V_62 ) ;
F_36 ( V_13 -> V_15 ) ;
}
}
V_55 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_55 & V_64 ) != 0 )
V_59 = true ;
else
V_59 = false ;
F_34 ( L_3 , V_55 , V_59 ) ;
return V_59 ;
}
static bool F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_55 ;
bool V_59 ;
T_1 V_62 ;
V_62 = V_55 = F_6 ( V_13 -> V_15 ) ;
F_34 ( L_1 , V_55 ) ;
V_55 |= V_63 ;
F_17 ( V_13 -> V_15 , V_55 ) ;
if ( F_35 ( ( F_6 ( V_13 -> V_15 ) & V_63 ) == 0 ,
1000 ) ) {
F_34 ( L_2 ) ;
F_17 ( V_13 -> V_15 , V_62 ) ;
}
V_55 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_55 & V_64 ) != 0 )
V_59 = true ;
else
V_59 = false ;
F_34 ( L_4 , V_55 , V_59 ) ;
return V_59 ;
}
static bool F_38 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_65 , V_66 , V_67 ;
bool V_59 = false ;
int V_68 , V_69 = 0 ;
if ( F_12 ( V_9 ) )
return F_33 ( V_6 ) ;
if ( F_39 ( V_9 ) )
return F_37 ( V_6 ) ;
if ( F_40 ( V_9 ) && ! F_41 ( V_9 ) )
V_69 = 2 ;
else
V_69 = 1 ;
V_65 = V_66 = F_6 ( V_70 ) ;
V_65 |= V_71 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
F_17 ( V_70 , V_65 ) ;
if ( F_35 ( ( F_6 ( V_70 ) &
V_71 ) == 0 ,
1000 ) )
F_34 ( L_5 ) ;
}
V_67 = F_6 ( V_72 ) ;
if ( ( V_67 & V_73 ) != V_74 )
V_59 = true ;
F_17 ( V_72 , V_75 ) ;
F_17 ( V_70 , V_66 ) ;
return V_59 ;
}
static struct V_76 * F_42 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_76 * V_76 ;
V_76 = F_43 ( V_6 , V_78 ) ;
if ( ! V_76 && ! F_44 ( V_78 ) ) {
F_34 ( L_6 ) ;
F_45 ( V_78 , true ) ;
V_76 = F_43 ( V_6 , V_78 ) ;
F_45 ( V_78 , false ) ;
}
return V_76 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_77 * V_79 )
{
struct V_76 * V_76 ;
int V_59 ;
V_76 = F_42 ( V_6 , V_79 ) ;
if ( ! V_76 )
return 0 ;
V_59 = F_47 ( V_6 , V_76 ) ;
F_48 ( V_76 ) ;
return V_59 ;
}
static bool F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_76 * V_76 ;
struct V_77 * V_78 ;
F_50 ( V_13 -> V_4 . type != V_80 ) ;
V_78 = F_51 ( V_11 , V_11 -> V_81 . V_82 ) ;
V_76 = F_42 ( V_6 , V_78 ) ;
if ( V_76 ) {
bool V_83 = V_76 -> V_84 & V_85 ;
if ( ! V_83 ) {
F_34 ( L_7 ) ;
return true ;
}
F_34 ( L_8 ) ;
} else {
F_34 ( L_9 ) ;
}
F_48 ( V_76 ) ;
return false ;
}
static enum V_86
F_52 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_30 ( V_13 -> V_4 . V_4 . V_40 ) -> V_7 ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 , V_90 ;
T_2 V_91 ;
T_2 V_92 , V_93 , V_94 ;
T_2 V_95 ;
T_2 V_96 ;
T_2 V_97 ;
T_2 V_98 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_3 V_102 ;
enum V_86 V_103 ;
F_34 ( L_10 ) ;
V_96 = F_32 ( V_7 ) ;
V_97 = F_53 ( V_7 ) ;
V_98 = F_54 ( V_7 ) ;
V_99 = F_55 ( V_7 ) ;
V_100 = F_56 ( V_7 ) ;
V_101 = F_57 ( V_7 ) ;
V_87 = F_6 ( V_96 ) ;
V_88 = F_6 ( V_97 ) ;
V_92 = F_6 ( V_98 ) ;
V_89 = ( ( V_88 >> 16 ) & 0xfff ) + 1 ;
V_90 = ( V_88 & 0x7ff ) + 1 ;
V_93 = ( V_92 & 0xfff ) + 1 ;
V_94 = ( ( V_92 >> 16 ) & 0xfff ) + 1 ;
F_17 ( V_96 , 0x500050 ) ;
if ( ! F_25 ( V_9 ) ) {
T_2 V_104 = F_6 ( V_100 ) ;
F_17 ( V_100 , V_104 | V_105 ) ;
F_36 ( V_100 ) ;
F_58 ( V_9 , V_7 ) ;
V_102 = F_59 ( V_106 ) ;
V_103 = ( ( V_102 & ( 1 << 4 ) ) != 0 ) ?
V_107 :
V_108 ;
F_17 ( V_100 , V_104 ) ;
} else {
bool V_109 = false ;
int V_110 , V_111 ;
if ( V_93 <= V_90 && V_94 >= V_89 ) {
T_2 V_112 = F_6 ( V_99 ) ;
T_2 V_113 = ( V_112 & 0xffff ) + 1 ;
V_93 = V_113 ;
F_17 ( V_98 ,
( V_93 - 1 ) |
( ( V_94 - 1 ) << 16 ) ) ;
V_109 = true ;
}
if ( V_93 - V_90 >= V_89 - V_94 )
V_91 = ( V_93 + V_90 ) >> 1 ;
else
V_91 = ( V_89 + V_94 ) >> 1 ;
while ( F_6 ( V_101 ) >= V_90 )
;
while ( ( V_95 = F_6 ( V_101 ) ) <= V_91 )
;
V_111 = 0 ;
V_110 = 0 ;
do {
V_110 ++ ;
V_102 = F_59 ( V_106 ) ;
if ( V_102 & ( 1 << 4 ) )
V_111 ++ ;
} while ( ( F_6 ( V_101 ) == V_95 ) );
if ( V_109 )
F_17 ( V_98 , V_92 ) ;
V_103 = V_111 * 4 > V_110 * 3 ?
V_107 :
V_108 ;
}
F_17 ( V_96 , V_87 ) ;
return V_103 ;
}
static enum V_86
F_60 ( struct V_5 * V_6 , bool V_114 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
enum V_86 V_103 ;
struct V_115 V_14 ;
F_34 ( L_11 ,
V_6 -> V_4 . V_116 , F_61 ( V_6 ) ,
V_114 ) ;
if ( F_62 ( V_9 ) ) {
if ( F_38 ( V_6 ) ) {
F_34 ( L_12 ) ;
return V_107 ;
} else
F_34 ( L_13 ) ;
}
if ( F_49 ( V_6 ) )
return V_107 ;
if ( F_62 ( V_9 ) )
return V_108 ;
if ( ! V_114 )
return V_6 -> V_103 ;
if ( F_63 ( V_6 , NULL , & V_14 ) ) {
if ( F_49 ( V_6 ) )
V_103 = V_107 ;
else
V_103 = F_52 ( V_13 ) ;
F_64 ( V_6 , & V_14 ) ;
} else
V_103 = V_117 ;
return V_103 ;
}
static void F_65 ( struct V_5 * V_6 )
{
F_66 ( V_6 ) ;
F_48 ( V_6 ) ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_59 ;
struct V_77 * V_78 ;
V_78 = F_51 ( V_11 , V_11 -> V_81 . V_82 ) ;
V_59 = F_46 ( V_6 , V_78 ) ;
if ( V_59 || ! F_40 ( V_9 ) )
return V_59 ;
V_78 = F_51 ( V_11 , V_118 ) ;
return F_46 ( V_6 , V_78 ) ;
}
static int F_68 ( struct V_5 * V_6 ,
struct V_119 * V_120 ,
T_4 V_121 )
{
return 0 ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_21 ( V_9 ) -> V_42 >= 5 ) {
T_1 V_55 ;
V_55 = F_6 ( V_13 -> V_15 ) ;
V_55 &= ~ V_122 ;
V_55 |= V_56 ;
F_17 ( V_13 -> V_15 , V_55 ) ;
F_36 ( V_13 -> V_15 ) ;
F_34 ( L_14 , V_55 ) ;
V_13 -> V_60 = 1 ;
}
}
static int T_5 F_70 ( const struct V_123 * V_116 )
{
F_71 ( L_15 , V_116 -> V_124 ) ;
return 1 ;
}
void F_72 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_125 * V_125 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_73 ( V_126 ) )
return;
V_13 = F_74 ( sizeof( struct V_1 ) , V_127 ) ;
if ( ! V_13 )
return;
V_125 = F_74 ( sizeof( * V_125 ) , V_127 ) ;
if ( ! V_125 ) {
F_48 ( V_13 ) ;
return;
}
V_6 = & V_125 -> V_4 ;
V_13 -> V_6 = V_125 ;
F_75 ( V_9 , & V_125 -> V_4 ,
& V_128 , V_129 ) ;
F_76 ( V_9 , & V_13 -> V_4 . V_4 , & V_130 ,
V_131 ) ;
F_77 ( V_125 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_80 ;
V_13 -> V_4 . V_132 = true ;
if ( F_78 ( V_9 ) )
V_13 -> V_4 . V_133 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_133 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_25 ( V_9 ) )
V_6 -> V_134 = 0 ;
else
V_6 -> V_134 = 1 ;
V_6 -> V_135 = 0 ;
if ( F_12 ( V_9 ) )
V_13 -> V_15 = V_136 ;
else if ( F_39 ( V_9 ) )
V_13 -> V_15 = V_137 ;
else
V_13 -> V_15 = V_138 ;
V_13 -> V_4 . V_139 = F_28 ;
V_13 -> V_4 . V_140 = F_29 ;
V_13 -> V_4 . V_141 = F_18 ;
V_13 -> V_4 . V_142 = F_19 ;
if ( F_62 ( V_9 ) )
V_13 -> V_4 . V_143 = V_144 ;
if ( F_79 ( V_9 ) ) {
V_13 -> V_4 . V_145 = F_14 ;
V_13 -> V_4 . V_146 = V_147 ;
} else {
V_13 -> V_4 . V_145 = F_11 ;
V_13 -> V_4 . V_146 = F_5 ;
}
V_125 -> V_146 = V_148 ;
F_80 ( V_6 , & V_149 ) ;
F_81 ( V_6 ) ;
if ( ! F_62 ( V_9 ) )
V_125 -> V_150 = V_151 ;
V_13 -> V_60 = 0 ;
if ( F_26 ( V_9 ) ) {
T_1 V_152 = V_153 |
V_154 ;
V_11 -> V_155 = F_6 ( V_156 ) & V_152 ;
}
}
