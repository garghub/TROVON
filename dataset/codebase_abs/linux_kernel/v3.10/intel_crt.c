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
static void F_10 ( struct V_5 * V_6 , int V_17 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_18 ;
V_18 = F_6 ( V_13 -> V_15 ) ;
V_18 &= ~ ( V_19 | V_20 ) ;
V_18 &= ~ V_16 ;
switch ( V_17 ) {
case V_21 :
V_18 |= V_16 ;
break;
case V_22 :
V_18 |= V_16 | V_19 ;
break;
case V_23 :
V_18 |= V_16 | V_20 ;
break;
case V_24 :
V_18 |= V_19 | V_20 ;
break;
}
F_11 ( V_13 -> V_15 , V_18 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
F_10 ( V_6 , V_24 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_4 ( V_6 ) ;
F_10 ( V_6 , V_13 -> V_3 -> V_4 . V_25 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_17 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_5 * V_6 = F_3 ( V_3 ) ;
struct V_26 * V_27 ;
int V_28 ;
if ( F_15 ( V_9 ) -> V_29 >= 5 && V_17 != V_21 )
V_17 = V_24 ;
if ( V_17 == V_3 -> V_25 )
return;
V_28 = V_3 -> V_25 ;
V_3 -> V_25 = V_17 ;
V_27 = V_6 -> V_4 . V_27 ;
if ( ! V_27 ) {
V_6 -> V_30 = false ;
return;
}
if ( V_17 == V_24 )
V_6 -> V_30 = false ;
else
V_6 -> V_30 = true ;
if ( V_17 < V_28 ) {
F_16 ( V_27 ) ;
F_10 ( V_6 , V_17 ) ;
} else {
F_10 ( V_6 , V_17 ) ;
F_16 ( V_27 ) ;
}
F_17 ( V_3 -> V_9 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_31 * V_17 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_32 = 0 ;
if ( V_17 -> V_33 & V_34 )
return V_35 ;
if ( V_17 -> clock < 25000 )
return V_36 ;
if ( F_19 ( V_9 ) )
V_32 = 350000 ;
else
V_32 = 400000 ;
if ( V_17 -> clock > V_32 )
return V_37 ;
if ( F_20 ( V_9 ) &&
( F_21 ( V_17 -> clock , 270000 , 24 ) > 2 ) )
return V_37 ;
return V_38 ;
}
static bool F_22 ( struct V_5 * V_6 ,
struct V_39 * V_40 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
if ( F_23 ( V_9 ) )
V_40 -> V_41 = true ;
return true ;
}
static void F_24 ( struct V_42 * V_6 ,
struct V_31 * V_17 ,
struct V_31 * V_43 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_26 * V_27 = V_6 -> V_27 ;
struct V_1 * V_13 =
F_4 ( F_25 ( V_6 ) ) ;
struct V_44 * V_44 = F_26 ( V_27 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_45 ;
if ( F_23 ( V_9 ) )
V_45 = V_46 ;
else
V_45 = 0 ;
if ( V_43 -> V_33 & V_47 )
V_45 |= V_48 ;
if ( V_43 -> V_33 & V_49 )
V_45 |= V_50 ;
if ( F_20 ( V_9 ) )
;
else if ( F_7 ( V_9 ) )
V_45 |= F_27 ( V_44 -> V_7 ) ;
else if ( V_44 -> V_7 == 0 )
V_45 |= V_51 ;
else
V_45 |= V_52 ;
if ( ! F_23 ( V_9 ) )
F_11 ( F_28 ( V_44 -> V_7 ) , 0 ) ;
F_11 ( V_13 -> V_15 , V_45 ) ;
}
static bool F_29 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_45 ;
bool V_53 ;
if ( V_13 -> V_54 ) {
bool V_55 = F_23 ( V_9 ) ;
T_1 V_56 ;
V_13 -> V_54 = 0 ;
V_56 = V_45 = F_6 ( V_13 -> V_15 ) ;
F_30 ( L_1 , V_45 ) ;
V_45 |= V_57 ;
if ( V_55 )
V_45 &= ~ V_16 ;
F_11 ( V_13 -> V_15 , V_45 ) ;
if ( F_31 ( ( F_6 ( V_13 -> V_15 ) & V_57 ) == 0 ,
1000 ) )
F_30 ( L_2 ) ;
if ( V_55 ) {
F_11 ( V_13 -> V_15 , V_56 ) ;
F_32 ( V_13 -> V_15 ) ;
}
}
V_45 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_45 & V_58 ) != 0 )
V_53 = true ;
else
V_53 = false ;
F_30 ( L_3 , V_45 , V_53 ) ;
return V_53 ;
}
static bool F_33 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_45 ;
bool V_53 ;
T_1 V_56 ;
V_56 = V_45 = F_6 ( V_13 -> V_15 ) ;
F_30 ( L_1 , V_45 ) ;
V_45 |= V_57 ;
F_11 ( V_13 -> V_15 , V_45 ) ;
if ( F_31 ( ( F_6 ( V_13 -> V_15 ) & V_57 ) == 0 ,
1000 ) ) {
F_30 ( L_2 ) ;
F_11 ( V_13 -> V_15 , V_56 ) ;
}
V_45 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_45 & V_58 ) != 0 )
V_53 = true ;
else
V_53 = false ;
F_30 ( L_4 , V_45 , V_53 ) ;
V_53 = true ;
return V_53 ;
}
static bool F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_59 , V_60 , V_61 ;
bool V_53 = false ;
int V_62 , V_63 = 0 ;
if ( F_23 ( V_9 ) )
return F_29 ( V_3 ) ;
if ( F_35 ( V_9 ) )
return F_33 ( V_3 ) ;
if ( F_36 ( V_9 ) && ! F_37 ( V_9 ) )
V_63 = 2 ;
else
V_63 = 1 ;
V_59 = V_60 = F_6 ( V_64 ) ;
V_59 |= V_65 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
F_11 ( V_64 , V_59 ) ;
if ( F_31 ( ( F_6 ( V_64 ) &
V_65 ) == 0 ,
1000 ) )
F_30 ( L_5 ) ;
}
V_61 = F_6 ( V_66 ) ;
if ( ( V_61 & V_67 ) != V_68 )
V_53 = true ;
F_11 ( V_66 , V_69 ) ;
F_11 ( V_64 , V_60 ) ;
return V_53 ;
}
static struct V_70 * F_38 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_70 * V_70 ;
V_70 = F_39 ( V_3 , V_72 ) ;
if ( ! V_70 && ! F_40 ( V_72 ) ) {
F_30 ( L_6 ) ;
F_41 ( V_72 , true ) ;
V_70 = F_39 ( V_3 , V_72 ) ;
F_41 ( V_72 , false ) ;
}
return V_70 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_71 * V_73 )
{
struct V_70 * V_70 ;
int V_53 ;
V_70 = F_38 ( V_3 , V_73 ) ;
if ( ! V_70 )
return 0 ;
V_53 = F_43 ( V_3 , V_70 ) ;
F_44 ( V_70 ) ;
return V_53 ;
}
static bool F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_70 * V_70 ;
struct V_71 * V_72 ;
F_46 ( V_13 -> V_4 . type != V_74 ) ;
V_72 = F_47 ( V_11 , V_11 -> V_75 ) ;
V_70 = F_38 ( V_3 , V_72 ) ;
if ( V_70 ) {
bool V_76 = V_70 -> V_77 & V_78 ;
if ( ! V_76 ) {
F_30 ( L_7 ) ;
return true ;
}
F_30 ( L_8 ) ;
} else {
F_30 ( L_9 ) ;
}
F_44 ( V_70 ) ;
return false ;
}
static enum V_79
F_48 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_26 ( V_13 -> V_4 . V_4 . V_27 ) -> V_7 ;
T_2 V_80 ;
T_2 V_81 ;
T_2 V_82 , V_83 ;
T_2 V_84 ;
T_2 V_85 , V_86 , V_87 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_94 ;
T_3 V_95 ;
enum V_79 V_96 ;
F_30 ( L_10 ) ;
V_89 = F_28 ( V_7 ) ;
V_90 = F_49 ( V_7 ) ;
V_91 = F_50 ( V_7 ) ;
V_92 = F_51 ( V_7 ) ;
V_93 = F_52 ( V_7 ) ;
V_94 = F_53 ( V_7 ) ;
V_80 = F_6 ( V_89 ) ;
V_81 = F_6 ( V_90 ) ;
V_85 = F_6 ( V_91 ) ;
V_82 = ( ( V_81 >> 16 ) & 0xfff ) + 1 ;
V_83 = ( V_81 & 0x7ff ) + 1 ;
V_86 = ( V_85 & 0xfff ) + 1 ;
V_87 = ( ( V_85 >> 16 ) & 0xfff ) + 1 ;
F_11 ( V_89 , 0x500050 ) ;
if ( ! F_19 ( V_9 ) ) {
T_2 V_97 = F_6 ( V_93 ) ;
F_11 ( V_93 , V_97 | V_98 ) ;
F_32 ( V_93 ) ;
F_54 ( V_9 , V_7 ) ;
V_95 = F_55 ( V_99 ) ;
V_96 = ( ( V_95 & ( 1 << 4 ) ) != 0 ) ?
V_100 :
V_101 ;
F_11 ( V_93 , V_97 ) ;
} else {
bool V_102 = false ;
int V_103 , V_104 ;
if ( V_86 <= V_83 && V_87 >= V_82 ) {
T_2 V_105 = F_6 ( V_92 ) ;
T_2 V_106 = ( V_105 & 0xffff ) + 1 ;
V_86 = V_106 ;
F_11 ( V_91 ,
( V_86 - 1 ) |
( ( V_87 - 1 ) << 16 ) ) ;
V_102 = true ;
}
if ( V_86 - V_83 >= V_82 - V_87 )
V_84 = ( V_86 + V_83 ) >> 1 ;
else
V_84 = ( V_82 + V_87 ) >> 1 ;
while ( F_6 ( V_94 ) >= V_83 )
;
while ( ( V_88 = F_6 ( V_94 ) ) <= V_84 )
;
V_104 = 0 ;
V_103 = 0 ;
do {
V_103 ++ ;
V_95 = F_55 ( V_99 ) ;
if ( V_95 & ( 1 << 4 ) )
V_104 ++ ;
} while ( ( F_6 ( V_94 ) == V_88 ) );
if ( V_102 )
F_11 ( V_91 , V_85 ) ;
V_96 = V_104 * 4 > V_103 * 3 ?
V_100 :
V_101 ;
}
F_11 ( V_89 , V_80 ) ;
return V_96 ;
}
static enum V_79
F_56 ( struct V_2 * V_3 , bool V_107 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_79 V_96 ;
struct V_108 V_14 ;
if ( F_57 ( V_9 ) ) {
if ( F_34 ( V_3 ) ) {
F_30 ( L_11 ) ;
return V_100 ;
} else
F_30 ( L_12 ) ;
}
if ( F_45 ( V_3 ) )
return V_100 ;
if ( F_57 ( V_9 ) )
return V_101 ;
if ( ! V_107 )
return V_3 -> V_96 ;
if ( F_58 ( V_3 , NULL , & V_14 ) ) {
if ( F_45 ( V_3 ) )
V_96 = V_100 ;
else
V_96 = F_48 ( V_13 ) ;
F_59 ( V_3 , & V_14 ) ;
} else
V_96 = V_109 ;
return V_96 ;
}
static void F_60 ( struct V_2 * V_3 )
{
F_61 ( V_3 ) ;
F_62 ( V_3 ) ;
F_44 ( V_3 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_53 ;
struct V_71 * V_72 ;
V_72 = F_47 ( V_11 , V_11 -> V_75 ) ;
V_53 = F_42 ( V_3 , V_72 ) ;
if ( V_53 || ! F_36 ( V_9 ) )
return V_53 ;
V_72 = F_47 ( V_11 , V_110 ) ;
return F_42 ( V_3 , V_72 ) ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_111 * V_112 ,
T_4 V_113 )
{
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_23 ( V_9 ) ) {
T_1 V_45 ;
V_45 = F_6 ( V_13 -> V_15 ) ;
V_45 &= ~ V_114 ;
V_45 |= V_46 ;
F_11 ( V_13 -> V_15 , V_45 ) ;
F_32 ( V_13 -> V_15 ) ;
F_30 ( L_13 , V_45 ) ;
V_13 -> V_54 = 1 ;
}
}
static int T_5 F_66 ( const struct V_115 * V_116 )
{
F_67 ( L_14 , V_116 -> V_117 ) ;
return 1 ;
}
void F_68 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_118 * V_118 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_69 ( V_119 ) )
return;
V_13 = F_70 ( sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_13 )
return;
V_118 = F_70 ( sizeof( struct V_118 ) , V_120 ) ;
if ( ! V_118 ) {
F_44 ( V_13 ) ;
return;
}
V_3 = & V_118 -> V_4 ;
V_13 -> V_3 = V_118 ;
F_71 ( V_9 , & V_118 -> V_4 ,
& V_121 , V_122 ) ;
F_72 ( V_9 , & V_13 -> V_4 . V_4 , & V_123 ,
V_124 ) ;
F_73 ( V_118 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_74 ;
V_13 -> V_4 . V_125 = true ;
if ( F_74 ( V_9 ) )
V_13 -> V_4 . V_126 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_126 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_19 ( V_9 ) )
V_3 -> V_127 = 0 ;
else
V_3 -> V_127 = 1 ;
V_3 -> V_128 = 0 ;
if ( F_23 ( V_9 ) )
V_13 -> V_15 = V_129 ;
else if ( F_35 ( V_9 ) )
V_13 -> V_15 = V_130 ;
else
V_13 -> V_15 = V_131 ;
V_13 -> V_4 . V_132 = F_22 ;
V_13 -> V_4 . V_133 = F_12 ;
V_13 -> V_4 . V_134 = F_13 ;
if ( F_57 ( V_9 ) )
V_13 -> V_4 . V_135 = V_136 ;
if ( F_75 ( V_9 ) )
V_13 -> V_4 . V_137 = V_138 ;
else
V_13 -> V_4 . V_137 = F_5 ;
V_118 -> V_137 = V_139 ;
F_76 ( & V_13 -> V_4 . V_4 , & V_140 ) ;
F_77 ( V_3 , & V_141 ) ;
F_78 ( V_3 ) ;
if ( ! F_57 ( V_9 ) )
V_118 -> V_142 = V_143 ;
V_13 -> V_54 = 0 ;
if ( F_20 ( V_9 ) ) {
T_1 V_144 = V_145 |
V_146 ;
V_11 -> V_147 = F_6 ( V_148 ) & V_144 ;
}
}
