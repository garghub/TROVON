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
static enum V_44
F_24 ( struct V_5 * V_6 ,
struct V_45 * V_30 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
int V_46 = 0 ;
if ( V_30 -> V_17 & V_47 )
return V_48 ;
if ( V_30 -> clock < 25000 )
return V_49 ;
if ( F_25 ( V_9 ) )
V_46 = 350000 ;
else
V_46 = 400000 ;
if ( V_30 -> clock > V_46 )
return V_50 ;
if ( F_26 ( V_9 ) &&
( F_27 ( V_30 -> clock , 270000 , 24 ) > 2 ) )
return V_50 ;
return V_51 ;
}
static bool F_28 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
if ( F_12 ( V_9 ) )
V_25 -> V_52 = true ;
if ( F_26 ( V_9 ) )
V_25 -> V_53 = 24 ;
return true ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_54 * V_40 = F_30 ( V_3 -> V_4 . V_40 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_45 * V_27 = & V_40 -> V_55 . V_27 ;
T_1 V_56 ;
if ( F_21 ( V_9 ) -> V_42 >= 5 )
V_56 = V_57 ;
else
V_56 = 0 ;
if ( V_27 -> V_17 & V_19 )
V_56 |= V_18 ;
if ( V_27 -> V_17 & V_22 )
V_56 |= V_21 ;
if ( F_26 ( V_9 ) )
;
else if ( F_7 ( V_9 ) )
V_56 |= F_31 ( V_40 -> V_7 ) ;
else if ( V_40 -> V_7 == 0 )
V_56 |= V_58 ;
else
V_56 |= V_59 ;
if ( ! F_12 ( V_9 ) )
F_17 ( F_32 ( V_40 -> V_7 ) , 0 ) ;
F_17 ( V_13 -> V_15 , V_56 ) ;
}
static bool F_33 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_56 ;
bool V_60 ;
if ( V_13 -> V_61 ) {
bool V_62 = F_12 ( V_9 ) ;
T_1 V_63 ;
V_13 -> V_61 = 0 ;
V_63 = V_56 = F_6 ( V_13 -> V_15 ) ;
F_34 ( L_1 , V_56 ) ;
V_56 |= V_64 ;
if ( V_62 )
V_56 &= ~ V_16 ;
F_17 ( V_13 -> V_15 , V_56 ) ;
if ( F_35 ( ( F_6 ( V_13 -> V_15 ) & V_64 ) == 0 ,
1000 ) )
F_34 ( L_2 ) ;
if ( V_62 ) {
F_17 ( V_13 -> V_15 , V_63 ) ;
F_36 ( V_13 -> V_15 ) ;
}
}
V_56 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_56 & V_65 ) != 0 )
V_60 = true ;
else
V_60 = false ;
F_34 ( L_3 , V_56 , V_60 ) ;
return V_60 ;
}
static bool F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_56 ;
bool V_60 ;
T_1 V_63 ;
V_63 = V_56 = F_6 ( V_13 -> V_15 ) ;
F_34 ( L_1 , V_56 ) ;
V_56 |= V_64 ;
F_17 ( V_13 -> V_15 , V_56 ) ;
if ( F_35 ( ( F_6 ( V_13 -> V_15 ) & V_64 ) == 0 ,
1000 ) ) {
F_34 ( L_2 ) ;
F_17 ( V_13 -> V_15 , V_63 ) ;
}
V_56 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_56 & V_65 ) != 0 )
V_60 = true ;
else
V_60 = false ;
F_34 ( L_4 , V_56 , V_60 ) ;
return V_60 ;
}
static bool F_38 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_66 , V_67 , V_68 ;
bool V_60 = false ;
int V_69 , V_70 = 0 ;
if ( F_12 ( V_9 ) )
return F_33 ( V_6 ) ;
if ( F_39 ( V_9 ) )
return F_37 ( V_6 ) ;
if ( F_40 ( V_9 ) && ! F_41 ( V_9 ) )
V_70 = 2 ;
else
V_70 = 1 ;
V_66 = V_67 = F_6 ( V_71 ) ;
V_66 |= V_72 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
F_17 ( V_71 , V_66 ) ;
if ( F_35 ( ( F_6 ( V_71 ) &
V_72 ) == 0 ,
1000 ) )
F_34 ( L_5 ) ;
}
V_68 = F_6 ( V_73 ) ;
if ( ( V_68 & V_74 ) != V_75 )
V_60 = true ;
F_17 ( V_73 , V_76 ) ;
F_17 ( V_71 , V_67 ) ;
return V_60 ;
}
static struct V_77 * F_42 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_77 * V_77 ;
V_77 = F_43 ( V_6 , V_79 ) ;
if ( ! V_77 && ! F_44 ( V_79 ) ) {
F_34 ( L_6 ) ;
F_45 ( V_79 , true ) ;
V_77 = F_43 ( V_6 , V_79 ) ;
F_45 ( V_79 , false ) ;
}
return V_77 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_78 * V_80 )
{
struct V_77 * V_77 ;
int V_60 ;
V_77 = F_42 ( V_6 , V_80 ) ;
if ( ! V_77 )
return 0 ;
V_60 = F_47 ( V_6 , V_77 ) ;
F_48 ( V_77 ) ;
return V_60 ;
}
static bool F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_77 * V_77 ;
struct V_78 * V_79 ;
F_50 ( V_13 -> V_4 . type != V_81 ) ;
V_79 = F_51 ( V_11 , V_11 -> V_82 . V_83 ) ;
V_77 = F_42 ( V_6 , V_79 ) ;
if ( V_77 ) {
bool V_84 = V_77 -> V_85 & V_86 ;
if ( ! V_84 ) {
F_34 ( L_7 ) ;
return true ;
}
F_34 ( L_8 ) ;
} else {
F_34 ( L_9 ) ;
}
F_48 ( V_77 ) ;
return false ;
}
static enum V_87
F_52 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_30 ( V_13 -> V_4 . V_4 . V_40 ) -> V_7 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 , V_91 ;
T_2 V_92 ;
T_2 V_93 , V_94 , V_95 ;
T_2 V_96 ;
T_2 V_97 ;
T_2 V_98 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_3 V_103 ;
enum V_87 V_104 ;
F_34 ( L_10 ) ;
V_97 = F_32 ( V_7 ) ;
V_98 = F_53 ( V_7 ) ;
V_99 = F_54 ( V_7 ) ;
V_100 = F_55 ( V_7 ) ;
V_101 = F_56 ( V_7 ) ;
V_102 = F_57 ( V_7 ) ;
V_88 = F_6 ( V_97 ) ;
V_89 = F_6 ( V_98 ) ;
V_93 = F_6 ( V_99 ) ;
V_90 = ( ( V_89 >> 16 ) & 0xfff ) + 1 ;
V_91 = ( V_89 & 0x7ff ) + 1 ;
V_94 = ( V_93 & 0xfff ) + 1 ;
V_95 = ( ( V_93 >> 16 ) & 0xfff ) + 1 ;
F_17 ( V_97 , 0x500050 ) ;
if ( ! F_25 ( V_9 ) ) {
T_2 V_105 = F_6 ( V_101 ) ;
F_17 ( V_101 , V_105 | V_106 ) ;
F_36 ( V_101 ) ;
F_58 ( V_9 , V_7 ) ;
V_103 = F_59 ( V_107 ) ;
V_104 = ( ( V_103 & ( 1 << 4 ) ) != 0 ) ?
V_108 :
V_109 ;
F_17 ( V_101 , V_105 ) ;
} else {
bool V_110 = false ;
int V_111 , V_112 ;
if ( V_94 <= V_91 && V_95 >= V_90 ) {
T_2 V_113 = F_6 ( V_100 ) ;
T_2 V_114 = ( V_113 & 0xffff ) + 1 ;
V_94 = V_114 ;
F_17 ( V_99 ,
( V_94 - 1 ) |
( ( V_95 - 1 ) << 16 ) ) ;
V_110 = true ;
}
if ( V_94 - V_91 >= V_90 - V_95 )
V_92 = ( V_94 + V_91 ) >> 1 ;
else
V_92 = ( V_90 + V_95 ) >> 1 ;
while ( F_6 ( V_102 ) >= V_91 )
;
while ( ( V_96 = F_6 ( V_102 ) ) <= V_92 )
;
V_112 = 0 ;
V_111 = 0 ;
do {
V_111 ++ ;
V_103 = F_59 ( V_107 ) ;
if ( V_103 & ( 1 << 4 ) )
V_112 ++ ;
} while ( ( F_6 ( V_102 ) == V_96 ) );
if ( V_110 )
F_17 ( V_99 , V_93 ) ;
V_104 = V_112 * 4 > V_111 * 3 ?
V_108 :
V_109 ;
}
F_17 ( V_97 , V_88 ) ;
return V_104 ;
}
static enum V_87
F_60 ( struct V_5 * V_6 , bool V_115 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
enum V_87 V_104 ;
struct V_116 V_14 ;
F_34 ( L_11 ,
V_6 -> V_4 . V_117 , F_61 ( V_6 ) ,
V_115 ) ;
if ( F_62 ( V_9 ) ) {
if ( F_38 ( V_6 ) ) {
F_34 ( L_12 ) ;
return V_108 ;
} else
F_34 ( L_13 ) ;
}
if ( F_49 ( V_6 ) )
return V_108 ;
if ( F_62 ( V_9 ) )
return V_109 ;
if ( ! V_115 )
return V_6 -> V_104 ;
if ( F_63 ( V_6 , NULL , & V_14 ) ) {
if ( F_49 ( V_6 ) )
V_104 = V_108 ;
else
V_104 = F_52 ( V_13 ) ;
F_64 ( V_6 , & V_14 ) ;
} else
V_104 = V_118 ;
return V_104 ;
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
int V_60 ;
struct V_78 * V_79 ;
V_79 = F_51 ( V_11 , V_11 -> V_82 . V_83 ) ;
V_60 = F_46 ( V_6 , V_79 ) ;
if ( V_60 || ! F_40 ( V_9 ) )
return V_60 ;
V_79 = F_51 ( V_11 , V_119 ) ;
return F_46 ( V_6 , V_79 ) ;
}
static int F_68 ( struct V_5 * V_6 ,
struct V_120 * V_121 ,
T_4 V_122 )
{
return 0 ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_3 ( V_6 ) ;
if ( F_21 ( V_9 ) -> V_42 >= 5 ) {
T_1 V_56 ;
V_56 = F_6 ( V_13 -> V_15 ) ;
V_56 &= ~ V_123 ;
V_56 |= V_57 ;
F_17 ( V_13 -> V_15 , V_56 ) ;
F_36 ( V_13 -> V_15 ) ;
F_34 ( L_14 , V_56 ) ;
V_13 -> V_61 = 1 ;
}
}
static int T_5 F_70 ( const struct V_124 * V_117 )
{
F_71 ( L_15 , V_117 -> V_125 ) ;
return 1 ;
}
void F_72 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_1 * V_13 ;
struct V_126 * V_126 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_73 ( V_127 ) )
return;
V_13 = F_74 ( sizeof( struct V_1 ) , V_128 ) ;
if ( ! V_13 )
return;
V_126 = F_74 ( sizeof( * V_126 ) , V_128 ) ;
if ( ! V_126 ) {
F_48 ( V_13 ) ;
return;
}
V_6 = & V_126 -> V_4 ;
V_13 -> V_6 = V_126 ;
F_75 ( V_9 , & V_126 -> V_4 ,
& V_129 , V_130 ) ;
F_76 ( V_9 , & V_13 -> V_4 . V_4 , & V_131 ,
V_132 ) ;
F_77 ( V_126 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_81 ;
V_13 -> V_4 . V_133 = true ;
if ( F_78 ( V_9 ) )
V_13 -> V_4 . V_134 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_134 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_25 ( V_9 ) )
V_6 -> V_135 = 0 ;
else
V_6 -> V_135 = 1 ;
V_6 -> V_136 = 0 ;
if ( F_12 ( V_9 ) )
V_13 -> V_15 = V_137 ;
else if ( F_39 ( V_9 ) )
V_13 -> V_15 = V_138 ;
else
V_13 -> V_15 = V_139 ;
V_13 -> V_4 . V_140 = F_28 ;
V_13 -> V_4 . V_141 = F_29 ;
V_13 -> V_4 . V_142 = F_18 ;
V_13 -> V_4 . V_143 = F_19 ;
if ( F_62 ( V_9 ) )
V_13 -> V_4 . V_144 = V_145 ;
if ( F_79 ( V_9 ) ) {
V_13 -> V_4 . V_146 = F_14 ;
V_13 -> V_4 . V_147 = V_148 ;
} else {
V_13 -> V_4 . V_146 = F_11 ;
V_13 -> V_4 . V_147 = F_5 ;
}
V_126 -> V_147 = V_149 ;
F_80 ( V_6 , & V_150 ) ;
F_81 ( V_6 ) ;
if ( ! F_62 ( V_9 ) )
V_126 -> V_151 = V_152 ;
V_13 -> V_61 = 0 ;
if ( F_26 ( V_9 ) ) {
T_1 V_153 = V_154 |
V_155 ;
V_11 -> V_156 = F_6 ( V_157 ) & V_153 ;
}
}
