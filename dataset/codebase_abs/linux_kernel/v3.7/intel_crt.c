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
static void F_10 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_17 ;
V_17 = F_6 ( V_13 -> V_15 ) ;
V_17 &= ~ ( V_18 | V_19 ) ;
V_17 &= ~ V_16 ;
F_11 ( V_13 -> V_15 , V_17 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_17 ;
V_17 = F_6 ( V_13 -> V_15 ) ;
V_17 |= V_16 ;
F_11 ( V_13 -> V_15 , V_17 ) ;
}
static void F_13 ( struct V_5 * V_6 , int V_20 )
{
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_13 = F_4 ( V_6 ) ;
T_1 V_17 ;
V_17 = F_6 ( V_13 -> V_15 ) ;
V_17 &= ~ ( V_18 | V_19 ) ;
V_17 &= ~ V_16 ;
switch ( V_20 ) {
case V_21 :
V_17 |= V_16 ;
break;
case V_22 :
V_17 |= V_16 | V_18 ;
break;
case V_23 :
V_17 |= V_16 | V_19 ;
break;
case V_24 :
V_17 |= V_18 | V_19 ;
break;
}
F_11 ( V_13 -> V_15 , V_17 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_20 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_5 * V_6 = F_3 ( V_3 ) ;
struct V_25 * V_26 ;
int V_27 ;
if ( F_15 ( V_9 ) -> V_28 >= 5 && V_20 != V_21 )
V_20 = V_24 ;
if ( V_20 == V_3 -> V_29 )
return;
V_27 = V_3 -> V_29 ;
V_3 -> V_29 = V_20 ;
V_26 = V_6 -> V_4 . V_26 ;
if ( ! V_26 ) {
V_6 -> V_30 = false ;
return;
}
if ( V_20 == V_24 )
V_6 -> V_30 = false ;
else
V_6 -> V_30 = true ;
if ( V_20 < V_27 ) {
F_16 ( V_26 ) ;
F_13 ( V_6 , V_20 ) ;
} else {
F_13 ( V_6 , V_20 ) ;
F_16 ( V_26 ) ;
}
F_17 ( V_3 -> V_9 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_31 * V_20 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_32 = 0 ;
if ( V_20 -> V_33 & V_34 )
return V_35 ;
if ( V_20 -> clock < 25000 )
return V_36 ;
if ( F_19 ( V_9 ) )
V_32 = 350000 ;
else
V_32 = 400000 ;
if ( V_20 -> clock > V_32 )
return V_37 ;
return V_38 ;
}
static bool F_20 ( struct V_39 * V_6 ,
const struct V_31 * V_20 ,
struct V_31 * V_40 )
{
return true ;
}
static void F_21 ( struct V_39 * V_6 ,
struct V_31 * V_20 ,
struct V_31 * V_40 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_25 * V_26 = V_6 -> V_26 ;
struct V_1 * V_13 =
F_4 ( F_22 ( V_6 ) ) ;
struct V_41 * V_41 = F_23 ( V_26 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
V_42 = V_43 ;
if ( V_40 -> V_33 & V_44 )
V_42 |= V_45 ;
if ( V_40 -> V_33 & V_46 )
V_42 |= V_47 ;
if ( F_7 ( V_9 ) )
V_42 |= F_24 ( V_41 -> V_7 ) ;
else if ( V_41 -> V_7 == 0 )
V_42 |= V_48 ;
else
V_42 |= V_49 ;
if ( ! F_25 ( V_9 ) )
F_11 ( F_26 ( V_41 -> V_7 ) , 0 ) ;
F_11 ( V_13 -> V_15 , V_42 ) ;
}
static bool F_27 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
bool V_50 ;
if ( V_13 -> V_51 ) {
bool V_52 = F_25 ( V_9 ) ;
T_1 V_53 ;
V_13 -> V_51 = 0 ;
V_53 = V_42 = F_6 ( V_54 ) ;
F_28 ( L_1 , V_42 ) ;
V_42 |= V_55 ;
if ( V_52 )
V_42 &= ~ V_16 ;
F_11 ( V_54 , V_42 ) ;
if ( F_29 ( ( F_6 ( V_54 ) & V_55 ) == 0 ,
1000 ) )
F_28 ( L_2 ) ;
if ( V_52 ) {
F_11 ( V_54 , V_53 ) ;
F_30 ( V_54 ) ;
}
}
V_42 = F_6 ( V_54 ) ;
if ( ( V_42 & V_56 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_28 ( L_3 , V_42 , V_50 ) ;
return V_50 ;
}
static bool F_31 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_42 ;
bool V_50 ;
T_1 V_53 ;
V_53 = V_42 = F_6 ( V_57 ) ;
F_28 ( L_1 , V_42 ) ;
V_42 |= V_55 ;
F_11 ( V_57 , V_42 ) ;
if ( F_29 ( ( F_6 ( V_57 ) & V_55 ) == 0 ,
1000 ) ) {
F_28 ( L_2 ) ;
F_11 ( V_57 , V_53 ) ;
}
V_42 = F_6 ( V_57 ) ;
if ( ( V_42 & V_56 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_28 ( L_4 , V_42 , V_50 ) ;
V_50 = true ;
return V_50 ;
}
static bool F_32 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_58 , V_59 , V_60 ;
bool V_50 = false ;
int V_61 , V_62 = 0 ;
if ( F_25 ( V_9 ) )
return F_27 ( V_3 ) ;
if ( F_33 ( V_9 ) )
return F_31 ( V_3 ) ;
if ( F_34 ( V_9 ) && ! F_35 ( V_9 ) )
V_62 = 2 ;
else
V_62 = 1 ;
V_58 = V_59 = F_6 ( V_63 ) ;
V_58 |= V_64 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
F_11 ( V_63 , V_58 ) ;
if ( F_29 ( ( F_6 ( V_63 ) &
V_64 ) == 0 ,
1000 ) )
F_28 ( L_5 ) ;
}
V_60 = F_6 ( V_65 ) ;
if ( ( V_60 & V_66 ) != V_67 )
V_50 = true ;
F_11 ( V_65 , V_68 ) ;
F_11 ( V_63 , V_59 ) ;
return V_50 ;
}
static struct V_69 * F_36 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
struct V_69 * V_69 ;
V_69 = F_37 ( V_3 , V_71 ) ;
if ( ! V_69 && ! F_38 ( V_71 ) ) {
F_28 ( L_6 ) ;
F_39 ( V_71 , true ) ;
V_69 = F_37 ( V_3 , V_71 ) ;
F_39 ( V_71 , false ) ;
}
return V_69 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_70 * V_72 )
{
struct V_69 * V_69 ;
V_69 = F_36 ( V_3 , V_72 ) ;
if ( ! V_69 )
return 0 ;
return F_41 ( V_3 , V_69 ) ;
}
static bool F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_13 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_69 * V_69 ;
struct V_70 * V_71 ;
F_43 ( V_13 -> V_4 . type != V_73 ) ;
V_71 = F_44 ( V_11 , V_11 -> V_74 ) ;
V_69 = F_36 ( V_3 , V_71 ) ;
if ( V_69 ) {
bool V_75 = V_69 -> V_76 & V_77 ;
if ( ! V_75 ) {
F_28 ( L_7 ) ;
return true ;
}
F_28 ( L_8 ) ;
} else {
F_28 ( L_9 ) ;
}
F_45 ( V_69 ) ;
return false ;
}
static enum V_78
F_46 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_7 = F_23 ( V_13 -> V_4 . V_4 . V_26 ) -> V_7 ;
T_2 V_79 ;
T_2 V_80 ;
T_2 V_81 , V_82 ;
T_2 V_83 ;
T_2 V_84 , V_85 , V_86 ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 ;
T_2 V_93 ;
T_3 V_94 ;
enum V_78 V_95 ;
F_28 ( L_10 ) ;
V_88 = F_26 ( V_7 ) ;
V_89 = F_47 ( V_7 ) ;
V_90 = F_48 ( V_7 ) ;
V_91 = F_49 ( V_7 ) ;
V_92 = F_50 ( V_7 ) ;
V_93 = F_51 ( V_7 ) ;
V_79 = F_6 ( V_88 ) ;
V_80 = F_6 ( V_89 ) ;
V_84 = F_6 ( V_90 ) ;
V_81 = ( ( V_80 >> 16 ) & 0xfff ) + 1 ;
V_82 = ( V_80 & 0x7ff ) + 1 ;
V_85 = ( V_84 & 0xfff ) + 1 ;
V_86 = ( ( V_84 >> 16 ) & 0xfff ) + 1 ;
F_11 ( V_88 , 0x500050 ) ;
if ( ! F_19 ( V_9 ) ) {
T_2 V_96 = F_6 ( V_92 ) ;
F_11 ( V_92 , V_96 | V_97 ) ;
F_30 ( V_92 ) ;
F_52 ( V_9 , V_7 ) ;
V_94 = F_53 ( V_98 ) ;
V_95 = ( ( V_94 & ( 1 << 4 ) ) != 0 ) ?
V_99 :
V_100 ;
F_11 ( V_92 , V_96 ) ;
} else {
bool V_101 = false ;
int V_102 , V_103 ;
if ( V_85 <= V_82 && V_86 >= V_81 ) {
T_2 V_104 = F_6 ( V_91 ) ;
T_2 V_105 = ( V_104 & 0xffff ) + 1 ;
V_85 = V_105 ;
F_11 ( V_90 ,
( V_85 - 1 ) |
( ( V_86 - 1 ) << 16 ) ) ;
V_101 = true ;
}
if ( V_85 - V_82 >= V_81 - V_86 )
V_83 = ( V_85 + V_82 ) >> 1 ;
else
V_83 = ( V_81 + V_86 ) >> 1 ;
while ( F_6 ( V_93 ) >= V_82 )
;
while ( ( V_87 = F_6 ( V_93 ) ) <= V_83 )
;
V_103 = 0 ;
V_102 = 0 ;
do {
V_102 ++ ;
V_94 = F_53 ( V_98 ) ;
if ( V_94 & ( 1 << 4 ) )
V_103 ++ ;
} while ( ( F_6 ( V_93 ) == V_87 ) );
if ( V_101 )
F_11 ( V_90 , V_84 ) ;
V_95 = V_103 * 4 > V_102 * 3 ?
V_99 :
V_100 ;
}
F_11 ( V_88 , V_79 ) ;
return V_95 ;
}
static enum V_78
F_54 ( struct V_2 * V_3 , bool V_106 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_78 V_95 ;
struct V_107 V_14 ;
if ( F_55 ( V_9 ) ) {
if ( F_32 ( V_3 ) ) {
F_28 ( L_11 ) ;
return V_99 ;
} else
F_28 ( L_12 ) ;
}
if ( F_42 ( V_3 ) )
return V_99 ;
if ( F_55 ( V_9 ) )
return V_100 ;
if ( ! V_106 )
return V_3 -> V_95 ;
if ( F_56 ( V_3 , NULL , & V_14 ) ) {
if ( F_42 ( V_3 ) )
V_95 = V_99 ;
else
V_95 = F_46 ( V_13 ) ;
F_57 ( V_3 , & V_14 ) ;
} else
V_95 = V_108 ;
return V_95 ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_59 ( V_3 ) ;
F_60 ( V_3 ) ;
F_45 ( V_3 ) ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_50 ;
struct V_70 * V_71 ;
V_71 = F_44 ( V_11 , V_11 -> V_74 ) ;
V_50 = F_40 ( V_3 , V_71 ) ;
if ( V_50 || ! F_34 ( V_9 ) )
return V_50 ;
V_71 = F_44 ( V_11 , V_109 ) ;
return F_40 ( V_3 , V_71 ) ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_110 * V_111 ,
T_4 V_112 )
{
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_25 ( V_9 ) )
V_13 -> V_51 = 1 ;
}
static int T_5 F_64 ( const struct V_113 * V_114 )
{
F_65 ( L_13 , V_114 -> V_115 ) ;
return 1 ;
}
void F_66 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_116 * V_116 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_67 ( V_117 ) )
return;
V_13 = F_68 ( sizeof( struct V_1 ) , V_118 ) ;
if ( ! V_13 )
return;
V_116 = F_68 ( sizeof( struct V_116 ) , V_118 ) ;
if ( ! V_116 ) {
F_45 ( V_13 ) ;
return;
}
V_3 = & V_116 -> V_4 ;
F_69 ( V_9 , & V_116 -> V_4 ,
& V_119 , V_120 ) ;
F_70 ( V_9 , & V_13 -> V_4 . V_4 , & V_121 ,
V_122 ) ;
F_71 ( V_116 , & V_13 -> V_4 ) ;
V_13 -> V_4 . type = V_73 ;
V_13 -> V_4 . V_123 = true ;
if ( F_72 ( V_9 ) || F_73 ( V_9 ) )
V_13 -> V_4 . V_124 = ( 1 << 0 ) ;
else
V_13 -> V_4 . V_124 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( F_19 ( V_9 ) )
V_3 -> V_125 = 0 ;
else
V_3 -> V_125 = 1 ;
V_3 -> V_126 = 0 ;
if ( F_25 ( V_9 ) )
V_13 -> V_15 = V_54 ;
else if ( F_33 ( V_9 ) )
V_13 -> V_15 = V_127 ;
else
V_13 -> V_15 = V_57 ;
V_13 -> V_4 . V_128 = F_10 ;
V_13 -> V_4 . V_129 = F_12 ;
V_13 -> V_4 . V_130 = F_5 ;
V_116 -> V_130 = V_131 ;
F_74 ( & V_13 -> V_4 . V_4 , & V_132 ) ;
F_75 ( V_3 , & V_133 ) ;
F_76 ( V_3 ) ;
if ( F_55 ( V_9 ) )
V_3 -> V_134 = V_135 ;
else
V_3 -> V_134 = V_136 ;
V_13 -> V_51 = 0 ;
if ( F_25 ( V_9 ) ) {
T_1 V_42 ;
V_42 = F_6 ( V_54 ) ;
V_42 &= ~ V_137 ;
V_42 |= V_43 ;
F_11 ( V_54 , V_42 ) ;
F_30 ( V_54 ) ;
F_28 ( L_14 , V_42 ) ;
V_13 -> V_51 = 1 ;
}
V_11 -> V_138 |= V_68 ;
}
