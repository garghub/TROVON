static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_4 ) ;
}
static bool F_5 ( struct V_5 * V_6 ,
enum V_7 * V_7 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
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
static void F_10 ( struct V_5 * V_6 ,
struct V_17 * V_18 )
{
struct V_10 * V_11 = V_6 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_14 , V_19 = 0 ;
V_14 = F_6 ( V_13 -> V_15 ) ;
if ( V_14 & V_20 )
V_19 |= V_21 ;
else
V_19 |= V_22 ;
if ( V_14 & V_23 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
V_18 -> V_26 . V_19 |= V_19 ;
}
static void F_11 ( struct V_5 * V_6 , int V_27 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_28 ;
V_28 = F_6 ( V_13 -> V_15 ) ;
V_28 &= ~ ( V_29 | V_30 ) ;
V_28 &= ~ V_16 ;
switch ( V_27 ) {
case V_31 :
V_28 |= V_16 ;
break;
case V_32 :
V_28 |= V_16 | V_29 ;
break;
case V_33 :
V_28 |= V_16 | V_30 ;
break;
case V_34 :
V_28 |= V_29 | V_30 ;
break;
}
F_12 ( V_13 -> V_15 , V_28 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
F_11 ( V_6 , V_34 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_4 ( V_6 ) ;
F_11 ( V_6 , V_13 -> V_3 -> V_4 . V_35 ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_27 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_5 * V_6 = F_3 ( V_3 ) ;
struct V_36 * V_37 ;
int V_38 ;
if ( F_16 ( V_9 ) -> V_39 >= 5 && V_27 != V_31 )
V_27 = V_34 ;
if ( V_27 == V_3 -> V_35 )
return;
V_38 = V_3 -> V_35 ;
V_3 -> V_35 = V_27 ;
V_37 = V_6 -> V_4 . V_37 ;
if ( ! V_37 ) {
V_6 -> V_40 = false ;
return;
}
if ( V_27 == V_34 )
V_6 -> V_40 = false ;
else
V_6 -> V_40 = true ;
if ( V_27 < V_38 ) {
F_17 ( V_37 ) ;
F_11 ( V_6 , V_27 ) ;
} else {
F_11 ( V_6 , V_27 ) ;
F_17 ( V_37 ) ;
}
F_18 ( V_3 -> V_9 ) ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_41 * V_27 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_42 = 0 ;
if ( V_27 -> V_19 & V_43 )
return V_44 ;
if ( V_27 -> clock < 25000 )
return V_45 ;
if ( F_20 ( V_9 ) )
V_42 = 350000 ;
else
V_42 = 400000 ;
if ( V_27 -> clock > V_42 )
return V_46 ;
if ( F_21 ( V_9 ) &&
( F_22 ( V_27 -> clock , 270000 , 24 ) > 2 ) )
return V_46 ;
return V_47 ;
}
static bool F_23 ( struct V_5 * V_6 ,
struct V_17 * V_18 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
if ( F_24 ( V_9 ) )
V_18 -> V_48 = true ;
if ( F_21 ( V_9 ) )
V_18 -> V_49 = 24 ;
return true ;
}
static void F_25 ( struct V_50 * V_6 ,
struct V_41 * V_27 ,
struct V_41 * V_26 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_1 * V_13 =
F_4 ( F_26 ( V_6 ) ) ;
struct V_51 * V_51 = F_27 ( V_37 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_52 ;
if ( F_24 ( V_9 ) )
V_52 = V_53 ;
else
V_52 = 0 ;
if ( V_26 -> V_19 & V_21 )
V_52 |= V_20 ;
if ( V_26 -> V_19 & V_24 )
V_52 |= V_23 ;
if ( F_21 ( V_9 ) )
;
else if ( F_7 ( V_9 ) )
V_52 |= F_28 ( V_51 -> V_7 ) ;
else if ( V_51 -> V_7 == 0 )
V_52 |= V_54 ;
else
V_52 |= V_55 ;
if ( ! F_24 ( V_9 ) )
F_12 ( F_29 ( V_51 -> V_7 ) , 0 ) ;
F_12 ( V_13 -> V_15 , V_52 ) ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_52 ;
bool V_56 ;
if ( V_13 -> V_57 ) {
bool V_58 = F_24 ( V_9 ) ;
T_1 V_59 ;
V_13 -> V_57 = 0 ;
V_59 = V_52 = F_6 ( V_13 -> V_15 ) ;
F_31 ( L_1 , V_52 ) ;
V_52 |= V_60 ;
if ( V_58 )
V_52 &= ~ V_16 ;
F_12 ( V_13 -> V_15 , V_52 ) ;
if ( F_32 ( ( F_6 ( V_13 -> V_15 ) & V_60 ) == 0 ,
1000 ) )
F_31 ( L_2 ) ;
if ( V_58 ) {
F_12 ( V_13 -> V_15 , V_59 ) ;
F_33 ( V_13 -> V_15 ) ;
}
}
V_52 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_52 & V_61 ) != 0 )
V_56 = true ;
else
V_56 = false ;
F_31 ( L_3 , V_52 , V_56 ) ;
return V_56 ;
}
static bool F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_52 ;
bool V_56 ;
T_1 V_59 ;
V_59 = V_52 = F_6 ( V_13 -> V_15 ) ;
F_31 ( L_1 , V_52 ) ;
V_52 |= V_60 ;
F_12 ( V_13 -> V_15 , V_52 ) ;
if ( F_32 ( ( F_6 ( V_13 -> V_15 ) & V_60 ) == 0 ,
1000 ) ) {
F_31 ( L_2 ) ;
F_12 ( V_13 -> V_15 , V_59 ) ;
}
V_52 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_52 & V_61 ) != 0 )
V_56 = true ;
else
V_56 = false ;
F_31 ( L_4 , V_52 , V_56 ) ;
V_56 = true ;
return V_56 ;
}
static bool F_35 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_62 , V_63 , V_64 ;
bool V_56 = false ;
int V_65 , V_66 = 0 ;
if ( F_24 ( V_9 ) )
return F_30 ( V_3 ) ;
if ( F_36 ( V_9 ) )
return F_34 ( V_3 ) ;
if ( F_37 ( V_9 ) && ! F_38 ( V_9 ) )
V_66 = 2 ;
else
V_66 = 1 ;
V_62 = V_63 = F_6 ( V_67 ) ;
V_62 |= V_68 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
F_12 ( V_67 , V_62 ) ;
if ( F_32 ( ( F_6 ( V_67 ) &
V_68 ) == 0 ,
1000 ) )
F_31 ( L_5 ) ;
}
V_64 = F_6 ( V_69 ) ;
if ( ( V_64 & V_70 ) != V_71 )
V_56 = true ;
F_12 ( V_69 , V_72 ) ;
F_12 ( V_67 , V_63 ) ;
return V_56 ;
}
static struct V_73 * F_39 ( struct V_2 * V_3 ,
struct V_74 * V_75 )
{
struct V_73 * V_73 ;
V_73 = F_40 ( V_3 , V_75 ) ;
if ( ! V_73 && ! F_41 ( V_75 ) ) {
F_31 ( L_6 ) ;
F_42 ( V_75 , true ) ;
V_73 = F_40 ( V_3 , V_75 ) ;
F_42 ( V_75 , false ) ;
}
return V_73 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_74 * V_76 )
{
struct V_73 * V_73 ;
int V_56 ;
V_73 = F_39 ( V_3 , V_76 ) ;
if ( ! V_73 )
return 0 ;
V_56 = F_44 ( V_3 , V_73 ) ;
F_45 ( V_73 ) ;
return V_56 ;
}
static bool F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_73 * V_73 ;
struct V_74 * V_75 ;
F_47 ( V_13 -> V_4 . type != V_77 ) ;
V_75 = F_48 ( V_11 , V_11 -> V_78 . V_79 ) ;
V_73 = F_39 ( V_3 , V_75 ) ;
if ( V_73 ) {
bool V_80 = V_73 -> V_81 & V_82 ;
if ( ! V_80 ) {
F_31 ( L_7 ) ;
return true ;
}
F_31 ( L_8 ) ;
} else {
F_31 ( L_9 ) ;
}
F_45 ( V_73 ) ;
return false ;
}
static enum V_83
F_49 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_27 ( V_13 -> V_4 . V_4 . V_37 ) -> V_7 ;
T_2 V_84 ;
T_2 V_85 ;
T_2 V_86 , V_87 ;
T_2 V_88 ;
T_2 V_89 , V_90 , V_91 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 ;
T_2 V_96 ;
T_2 V_97 ;
T_2 V_98 ;
T_3 V_99 ;
enum V_83 V_100 ;
F_31 ( L_10 ) ;
V_93 = F_29 ( V_7 ) ;
V_94 = F_50 ( V_7 ) ;
V_95 = F_51 ( V_7 ) ;
V_96 = F_52 ( V_7 ) ;
V_97 = F_53 ( V_7 ) ;
V_98 = F_54 ( V_7 ) ;
V_84 = F_6 ( V_93 ) ;
V_85 = F_6 ( V_94 ) ;
V_89 = F_6 ( V_95 ) ;
V_86 = ( ( V_85 >> 16 ) & 0xfff ) + 1 ;
V_87 = ( V_85 & 0x7ff ) + 1 ;
V_90 = ( V_89 & 0xfff ) + 1 ;
V_91 = ( ( V_89 >> 16 ) & 0xfff ) + 1 ;
F_12 ( V_93 , 0x500050 ) ;
if ( ! F_20 ( V_9 ) ) {
T_2 V_101 = F_6 ( V_97 ) ;
F_12 ( V_97 , V_101 | V_102 ) ;
F_33 ( V_97 ) ;
F_55 ( V_9 , V_7 ) ;
V_99 = F_56 ( V_103 ) ;
V_100 = ( ( V_99 & ( 1 << 4 ) ) != 0 ) ?
V_104 :
V_105 ;
F_12 ( V_97 , V_101 ) ;
} else {
bool V_106 = false ;
int V_107 , V_108 ;
if ( V_90 <= V_87 && V_91 >= V_86 ) {
T_2 V_109 = F_6 ( V_96 ) ;
T_2 V_110 = ( V_109 & 0xffff ) + 1 ;
V_90 = V_110 ;
F_12 ( V_95 ,
( V_90 - 1 ) |
( ( V_91 - 1 ) << 16 ) ) ;
V_106 = true ;
}
if ( V_90 - V_87 >= V_86 - V_91 )
V_88 = ( V_90 + V_87 ) >> 1 ;
else
V_88 = ( V_86 + V_91 ) >> 1 ;
while ( F_6 ( V_98 ) >= V_87 )
;
while ( ( V_92 = F_6 ( V_98 ) ) <= V_88 )
;
V_108 = 0 ;
V_107 = 0 ;
do {
V_107 ++ ;
V_99 = F_56 ( V_103 ) ;
if ( V_99 & ( 1 << 4 ) )
V_108 ++ ;
} while ( ( F_6 ( V_98 ) == V_92 ) );
if ( V_106 )
F_12 ( V_95 , V_89 ) ;
V_100 = V_108 * 4 > V_107 * 3 ?
V_104 :
V_105 ;
}
F_12 ( V_93 , V_84 ) ;
return V_100 ;
}
static enum V_83
F_57 ( struct V_2 * V_3 , bool V_111 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_83 V_100 ;
struct V_112 V_14 ;
if ( F_58 ( V_9 ) ) {
if ( F_35 ( V_3 ) ) {
F_31 ( L_11 ) ;
return V_104 ;
} else
F_31 ( L_12 ) ;
}
if ( F_46 ( V_3 ) )
return V_104 ;
if ( F_58 ( V_9 ) )
return V_105 ;
if ( ! V_111 )
return V_3 -> V_100 ;
if ( F_59 ( V_3 , NULL , & V_14 ) ) {
if ( F_46 ( V_3 ) )
V_100 = V_104 ;
else
V_100 = F_49 ( V_13 ) ;
F_60 ( V_3 , & V_14 ) ;
} else
V_100 = V_113 ;
return V_100 ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_62 ( V_3 ) ;
F_63 ( V_3 ) ;
F_45 ( V_3 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_56 ;
struct V_74 * V_75 ;
V_75 = F_48 ( V_11 , V_11 -> V_78 . V_79 ) ;
V_56 = F_43 ( V_3 , V_75 ) ;
if ( V_56 || ! F_37 ( V_9 ) )
return V_56 ;
V_75 = F_48 ( V_11 , V_114 ) ;
return F_43 ( V_3 , V_75 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_115 * V_116 ,
T_4 V_117 )
{
return 0 ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_24 ( V_9 ) ) {
T_1 V_52 ;
V_52 = F_6 ( V_13 -> V_15 ) ;
V_52 &= ~ V_118 ;
V_52 |= V_53 ;
F_12 ( V_13 -> V_15 , V_52 ) ;
F_33 ( V_13 -> V_15 ) ;
F_31 ( L_13 , V_52 ) ;
V_13 -> V_57 = 1 ;
}
}
static int T_5 F_67 ( const struct V_119 * V_120 )
{
F_68 ( L_14 , V_120 -> V_121 ) ;
return 1 ;
}
void F_69 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_122 * V_122 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_70 ( V_123 ) )
return;
V_13 = F_71 ( sizeof( struct V_1 ) , V_124 ) ;
if ( ! V_13 )
return;
V_122 = F_71 ( sizeof( struct V_122 ) , V_124 ) ;
if ( ! V_122 ) {
F_45 ( V_13 ) ;
return;
}
V_3 = & V_122 -> V_4 ;
V_13 -> V_3 = V_122 ;
F_72 ( V_9 , & V_122 -> V_4 ,
& V_125 , V_126 ) ;
F_73 ( V_9 , & V_13 -> V_4 . V_4 , & V_127 ,
V_128 ) ;
F_74 ( V_122 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_77 ;
V_13 -> V_4 . V_129 = true ;
if ( F_75 ( V_9 ) )
V_13 -> V_4 . V_130 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_130 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_20 ( V_9 ) )
V_3 -> V_131 = 0 ;
else
V_3 -> V_131 = 1 ;
V_3 -> V_132 = 0 ;
if ( F_24 ( V_9 ) )
V_13 -> V_15 = V_133 ;
else if ( F_36 ( V_9 ) )
V_13 -> V_15 = V_134 ;
else
V_13 -> V_15 = V_135 ;
V_13 -> V_4 . V_136 = F_23 ;
V_13 -> V_4 . V_137 = F_13 ;
V_13 -> V_4 . V_138 = F_14 ;
V_13 -> V_4 . V_139 = F_10 ;
if ( F_58 ( V_9 ) )
V_13 -> V_4 . V_140 = V_141 ;
if ( F_76 ( V_9 ) )
V_13 -> V_4 . V_142 = V_143 ;
else
V_13 -> V_4 . V_142 = F_5 ;
V_122 -> V_142 = V_144 ;
F_77 ( & V_13 -> V_4 . V_4 , & V_145 ) ;
F_78 ( V_3 , & V_146 ) ;
F_79 ( V_3 ) ;
if ( ! F_58 ( V_9 ) )
V_122 -> V_147 = V_148 ;
V_13 -> V_57 = 0 ;
if ( F_21 ( V_9 ) ) {
T_1 V_149 = V_150 |
V_151 ;
V_11 -> V_152 = F_6 ( V_153 ) & V_149 ;
}
}
