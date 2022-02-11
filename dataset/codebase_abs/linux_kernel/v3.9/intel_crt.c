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
static bool F_22 ( struct V_39 * V_6 ,
const struct V_31 * V_17 ,
struct V_31 * V_40 )
{
return true ;
}
static void F_23 ( struct V_39 * V_6 ,
struct V_31 * V_17 ,
struct V_31 * V_40 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_26 * V_27 = V_6 -> V_27 ;
struct V_1 * V_13 =
F_4 ( F_24 ( V_6 ) ) ;
struct V_41 * V_41 = F_25 ( V_27 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
if ( F_26 ( V_9 ) )
V_42 = V_43 ;
else
V_42 = 0 ;
if ( V_40 -> V_33 & V_44 )
V_42 |= V_45 ;
if ( V_40 -> V_33 & V_46 )
V_42 |= V_47 ;
if ( F_20 ( V_9 ) )
;
else if ( F_7 ( V_9 ) )
V_42 |= F_27 ( V_41 -> V_7 ) ;
else if ( V_41 -> V_7 == 0 )
V_42 |= V_48 ;
else
V_42 |= V_49 ;
if ( ! F_26 ( V_9 ) )
F_11 ( F_28 ( V_41 -> V_7 ) , 0 ) ;
F_11 ( V_13 -> V_15 , V_42 ) ;
}
static bool F_29 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
bool V_50 ;
if ( V_13 -> V_51 ) {
bool V_52 = F_26 ( V_9 ) ;
T_1 V_53 ;
V_13 -> V_51 = 0 ;
V_53 = V_42 = F_6 ( V_13 -> V_15 ) ;
F_30 ( L_1 , V_42 ) ;
V_42 |= V_54 ;
if ( V_52 )
V_42 &= ~ V_16 ;
F_11 ( V_13 -> V_15 , V_42 ) ;
if ( F_31 ( ( F_6 ( V_13 -> V_15 ) & V_54 ) == 0 ,
1000 ) )
F_30 ( L_2 ) ;
if ( V_52 ) {
F_11 ( V_13 -> V_15 , V_53 ) ;
F_32 ( V_13 -> V_15 ) ;
}
}
V_42 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_42 & V_55 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_30 ( L_3 , V_42 , V_50 ) ;
return V_50 ;
}
static bool F_33 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
bool V_50 ;
T_1 V_53 ;
V_53 = V_42 = F_6 ( V_13 -> V_15 ) ;
F_30 ( L_1 , V_42 ) ;
V_42 |= V_54 ;
F_11 ( V_13 -> V_15 , V_42 ) ;
if ( F_31 ( ( F_6 ( V_13 -> V_15 ) & V_54 ) == 0 ,
1000 ) ) {
F_30 ( L_2 ) ;
F_11 ( V_13 -> V_15 , V_53 ) ;
}
V_42 = F_6 ( V_13 -> V_15 ) ;
if ( ( V_42 & V_55 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_30 ( L_4 , V_42 , V_50 ) ;
V_50 = true ;
return V_50 ;
}
static bool F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_56 , V_57 , V_58 ;
bool V_50 = false ;
int V_59 , V_60 = 0 ;
if ( F_26 ( V_9 ) )
return F_29 ( V_3 ) ;
if ( F_35 ( V_9 ) )
return F_33 ( V_3 ) ;
if ( F_36 ( V_9 ) && ! F_37 ( V_9 ) )
V_60 = 2 ;
else
V_60 = 1 ;
V_56 = V_57 = F_6 ( V_61 ) ;
V_56 |= V_62 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
F_11 ( V_61 , V_56 ) ;
if ( F_31 ( ( F_6 ( V_61 ) &
V_62 ) == 0 ,
1000 ) )
F_30 ( L_5 ) ;
}
V_58 = F_6 ( V_63 ) ;
if ( ( V_58 & V_64 ) != V_65 )
V_50 = true ;
F_11 ( V_63 , V_66 ) ;
F_11 ( V_61 , V_57 ) ;
return V_50 ;
}
static struct V_67 * F_38 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_67 * V_67 ;
V_67 = F_39 ( V_3 , V_69 ) ;
if ( ! V_67 && ! F_40 ( V_69 ) ) {
F_30 ( L_6 ) ;
F_41 ( V_69 , true ) ;
V_67 = F_39 ( V_3 , V_69 ) ;
F_41 ( V_69 , false ) ;
}
return V_67 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_68 * V_70 )
{
struct V_67 * V_67 ;
int V_50 ;
V_67 = F_38 ( V_3 , V_70 ) ;
if ( ! V_67 )
return 0 ;
V_50 = F_43 ( V_3 , V_67 ) ;
F_44 ( V_67 ) ;
return V_50 ;
}
static bool F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_67 * V_67 ;
struct V_68 * V_69 ;
F_46 ( V_13 -> V_4 . type != V_71 ) ;
V_69 = F_47 ( V_11 , V_11 -> V_72 ) ;
V_67 = F_38 ( V_3 , V_69 ) ;
if ( V_67 ) {
bool V_73 = V_67 -> V_74 & V_75 ;
if ( ! V_73 ) {
F_30 ( L_7 ) ;
return true ;
}
F_30 ( L_8 ) ;
} else {
F_30 ( L_9 ) ;
}
F_44 ( V_67 ) ;
return false ;
}
static enum V_76
F_48 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_25 ( V_13 -> V_4 . V_4 . V_27 ) -> V_7 ;
T_2 V_77 ;
T_2 V_78 ;
T_2 V_79 , V_80 ;
T_2 V_81 ;
T_2 V_82 , V_83 , V_84 ;
T_2 V_85 ;
T_2 V_86 ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_3 V_92 ;
enum V_76 V_93 ;
F_30 ( L_10 ) ;
V_86 = F_28 ( V_7 ) ;
V_87 = F_49 ( V_7 ) ;
V_88 = F_50 ( V_7 ) ;
V_89 = F_51 ( V_7 ) ;
V_90 = F_52 ( V_7 ) ;
V_91 = F_53 ( V_7 ) ;
V_77 = F_6 ( V_86 ) ;
V_78 = F_6 ( V_87 ) ;
V_82 = F_6 ( V_88 ) ;
V_79 = ( ( V_78 >> 16 ) & 0xfff ) + 1 ;
V_80 = ( V_78 & 0x7ff ) + 1 ;
V_83 = ( V_82 & 0xfff ) + 1 ;
V_84 = ( ( V_82 >> 16 ) & 0xfff ) + 1 ;
F_11 ( V_86 , 0x500050 ) ;
if ( ! F_19 ( V_9 ) ) {
T_2 V_94 = F_6 ( V_90 ) ;
F_11 ( V_90 , V_94 | V_95 ) ;
F_32 ( V_90 ) ;
F_54 ( V_9 , V_7 ) ;
V_92 = F_55 ( V_96 ) ;
V_93 = ( ( V_92 & ( 1 << 4 ) ) != 0 ) ?
V_97 :
V_98 ;
F_11 ( V_90 , V_94 ) ;
} else {
bool V_99 = false ;
int V_100 , V_101 ;
if ( V_83 <= V_80 && V_84 >= V_79 ) {
T_2 V_102 = F_6 ( V_89 ) ;
T_2 V_103 = ( V_102 & 0xffff ) + 1 ;
V_83 = V_103 ;
F_11 ( V_88 ,
( V_83 - 1 ) |
( ( V_84 - 1 ) << 16 ) ) ;
V_99 = true ;
}
if ( V_83 - V_80 >= V_79 - V_84 )
V_81 = ( V_83 + V_80 ) >> 1 ;
else
V_81 = ( V_79 + V_84 ) >> 1 ;
while ( F_6 ( V_91 ) >= V_80 )
;
while ( ( V_85 = F_6 ( V_91 ) ) <= V_81 )
;
V_101 = 0 ;
V_100 = 0 ;
do {
V_100 ++ ;
V_92 = F_55 ( V_96 ) ;
if ( V_92 & ( 1 << 4 ) )
V_101 ++ ;
} while ( ( F_6 ( V_91 ) == V_85 ) );
if ( V_99 )
F_11 ( V_88 , V_82 ) ;
V_93 = V_101 * 4 > V_100 * 3 ?
V_97 :
V_98 ;
}
F_11 ( V_86 , V_77 ) ;
return V_93 ;
}
static enum V_76
F_56 ( struct V_2 * V_3 , bool V_104 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_76 V_93 ;
struct V_105 V_14 ;
if ( F_57 ( V_9 ) ) {
if ( F_34 ( V_3 ) ) {
F_30 ( L_11 ) ;
return V_97 ;
} else
F_30 ( L_12 ) ;
}
if ( F_45 ( V_3 ) )
return V_97 ;
if ( F_57 ( V_9 ) )
return V_98 ;
if ( ! V_104 )
return V_3 -> V_93 ;
if ( F_58 ( V_3 , NULL , & V_14 ) ) {
if ( F_45 ( V_3 ) )
V_93 = V_97 ;
else
V_93 = F_48 ( V_13 ) ;
F_59 ( V_3 , & V_14 ) ;
} else
V_93 = V_106 ;
return V_93 ;
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
int V_50 ;
struct V_68 * V_69 ;
V_69 = F_47 ( V_11 , V_11 -> V_72 ) ;
V_50 = F_42 ( V_3 , V_69 ) ;
if ( V_50 || ! F_36 ( V_9 ) )
return V_50 ;
V_69 = F_47 ( V_11 , V_107 ) ;
return F_42 ( V_3 , V_69 ) ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_108 * V_109 ,
T_4 V_110 )
{
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_26 ( V_9 ) ) {
T_1 V_42 ;
V_42 = F_6 ( V_13 -> V_15 ) ;
V_42 &= ~ V_111 ;
V_42 |= V_43 ;
F_11 ( V_13 -> V_15 , V_42 ) ;
F_32 ( V_13 -> V_15 ) ;
F_30 ( L_13 , V_42 ) ;
V_13 -> V_51 = 1 ;
}
}
static int T_5 F_66 ( const struct V_112 * V_113 )
{
F_67 ( L_14 , V_113 -> V_114 ) ;
return 1 ;
}
void F_68 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_115 * V_115 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_69 ( V_116 ) )
return;
V_13 = F_70 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_13 )
return;
V_115 = F_70 ( sizeof( struct V_115 ) , V_117 ) ;
if ( ! V_115 ) {
F_44 ( V_13 ) ;
return;
}
V_3 = & V_115 -> V_4 ;
V_13 -> V_3 = V_115 ;
F_71 ( V_9 , & V_115 -> V_4 ,
& V_118 , V_119 ) ;
F_72 ( V_9 , & V_13 -> V_4 . V_4 , & V_120 ,
V_121 ) ;
F_73 ( V_115 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_71 ;
V_13 -> V_4 . V_122 = true ;
if ( F_74 ( V_9 ) )
V_13 -> V_4 . V_123 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_123 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_19 ( V_9 ) )
V_3 -> V_124 = 0 ;
else
V_3 -> V_124 = 1 ;
V_3 -> V_125 = 0 ;
if ( F_26 ( V_9 ) )
V_13 -> V_15 = V_126 ;
else if ( F_35 ( V_9 ) )
V_13 -> V_15 = V_127 ;
else
V_13 -> V_15 = V_128 ;
V_13 -> V_4 . V_129 = F_12 ;
V_13 -> V_4 . V_130 = F_13 ;
if ( F_75 ( V_9 ) )
V_13 -> V_4 . V_131 = V_132 ;
else
V_13 -> V_4 . V_131 = F_5 ;
V_115 -> V_131 = V_133 ;
F_76 ( & V_13 -> V_4 . V_4 , & V_134 ) ;
F_77 ( V_3 , & V_135 ) ;
F_78 ( V_3 ) ;
if ( F_57 ( V_9 ) )
V_3 -> V_136 = V_137 ;
else
V_3 -> V_136 = V_138 ;
V_13 -> V_51 = 0 ;
V_11 -> V_139 |= V_66 ;
if ( F_20 ( V_9 ) ) {
T_1 V_140 = V_141 |
V_142 ;
V_11 -> V_143 = F_6 ( V_144 ) & V_140 ;
}
}
