static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_13 ;
V_13 = F_5 ( V_14 ) ;
V_13 &= ~ V_15 ;
switch ( V_7 ) {
case V_16 :
V_13 |= V_15 ;
break;
case V_17 :
case V_18 :
case V_19 :
break;
}
F_6 ( V_14 , V_13 ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_13 ;
V_13 = F_5 ( V_20 ) ;
V_13 &= ~ ( V_21 | V_22 ) ;
V_13 &= ~ V_15 ;
if ( F_8 ( V_9 ) && V_7 != V_16 )
V_7 = V_19 ;
switch ( V_7 ) {
case V_16 :
V_13 |= V_15 ;
break;
case V_17 :
V_13 |= V_15 | V_21 ;
break;
case V_18 :
V_13 |= V_15 | V_22 ;
break;
case V_19 :
V_13 |= V_21 | V_22 ;
break;
}
F_6 ( V_20 , V_13 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_23 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_24 = 0 ;
if ( V_7 -> V_25 & V_26 )
return V_27 ;
if ( V_7 -> clock < 25000 )
return V_28 ;
if ( F_10 ( V_9 ) )
V_24 = 350000 ;
else
V_24 = 400000 ;
if ( V_7 -> clock > V_24 )
return V_29 ;
return V_30 ;
}
static bool F_11 ( struct V_5 * V_6 ,
const struct V_23 * V_7 ,
struct V_23 * V_31 )
{
return true ;
}
static void F_12 ( struct V_5 * V_6 ,
struct V_23 * V_7 ,
struct V_23 * V_31 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_32 * V_33 = V_6 -> V_33 ;
struct V_34 * V_34 = F_13 ( V_33 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_35 ;
T_1 V_36 , V_37 ;
T_1 V_38 ;
V_35 = F_14 ( V_34 -> V_39 ) ;
if ( F_15 ( V_9 ) )
V_38 = V_14 ;
else
V_38 = V_20 ;
if ( F_16 ( V_9 ) -> V_40 >= 4 && ! F_15 ( V_9 ) ) {
V_37 = F_5 ( V_35 ) ;
F_6 ( V_35 ,
V_37 & ~ V_41 ) ;
}
V_36 = V_42 ;
if ( V_31 -> V_25 & V_43 )
V_36 |= V_44 ;
if ( V_31 -> V_25 & V_45 )
V_36 |= V_46 ;
if ( F_17 ( V_9 ) )
V_36 |= F_18 ( V_34 -> V_39 ) ;
else if ( V_34 -> V_39 == 0 )
V_36 |= V_47 ;
else
V_36 |= V_48 ;
if ( ! F_15 ( V_9 ) )
F_6 ( F_19 ( V_34 -> V_39 ) , 0 ) ;
F_6 ( V_38 , V_36 ) ;
}
static bool F_20 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_36 ;
bool V_50 ;
if ( V_49 -> V_51 ) {
bool V_52 = F_15 ( V_9 ) ;
T_1 V_53 ;
V_49 -> V_51 = 0 ;
V_53 = V_36 = F_5 ( V_14 ) ;
F_21 ( L_1 , V_36 ) ;
V_36 |= V_54 ;
if ( V_52 )
V_36 &= ~ V_15 ;
F_6 ( V_14 , V_36 ) ;
if ( F_22 ( ( F_5 ( V_14 ) & V_54 ) == 0 ,
1000 ) )
F_21 ( L_2 ) ;
if ( V_52 ) {
F_6 ( V_14 , V_53 ) ;
F_23 ( V_14 ) ;
}
}
V_36 = F_5 ( V_14 ) ;
if ( ( V_36 & V_55 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_21 ( L_3 , V_36 , V_50 ) ;
return V_50 ;
}
static bool F_24 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_36 ;
bool V_50 ;
T_1 V_53 ;
V_53 = V_36 = F_5 ( V_20 ) ;
F_21 ( L_1 , V_36 ) ;
V_36 |= V_54 ;
F_6 ( V_20 , V_36 ) ;
if ( F_22 ( ( F_5 ( V_20 ) & V_54 ) == 0 ,
1000 ) ) {
F_21 ( L_2 ) ;
F_6 ( V_20 , V_53 ) ;
}
V_36 = F_5 ( V_20 ) ;
if ( ( V_36 & V_55 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_21 ( L_4 , V_36 , V_50 ) ;
V_50 = true ;
return V_50 ;
}
static bool F_25 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_56 , V_57 , V_58 ;
bool V_50 = false ;
int V_59 , V_60 = 0 ;
if ( F_15 ( V_9 ) )
return F_20 ( V_3 ) ;
if ( F_8 ( V_9 ) )
return F_24 ( V_3 ) ;
if ( F_26 ( V_9 ) && ! F_27 ( V_9 ) )
V_60 = 2 ;
else
V_60 = 1 ;
V_56 = V_57 = F_5 ( V_61 ) ;
V_56 |= V_62 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
F_6 ( V_61 , V_56 ) ;
if ( F_22 ( ( F_5 ( V_61 ) &
V_62 ) == 0 ,
1000 ) )
F_21 ( L_5 ) ;
}
V_58 = F_5 ( V_63 ) ;
if ( ( V_58 & V_64 ) != V_65 )
V_50 = true ;
F_6 ( V_63 , V_66 ) ;
F_6 ( V_61 , V_57 ) ;
return V_50 ;
}
static struct V_67 * F_28 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_67 * V_67 ;
V_67 = F_29 ( V_3 , V_69 ) ;
if ( ! V_67 && ! F_30 ( V_69 ) ) {
F_21 ( L_6 ) ;
F_31 ( V_69 , true ) ;
V_67 = F_29 ( V_3 , V_69 ) ;
F_31 ( V_69 , false ) ;
}
return V_67 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_68 * V_70 )
{
struct V_67 * V_67 ;
V_67 = F_28 ( V_3 , V_70 ) ;
if ( ! V_67 )
return 0 ;
return F_33 ( V_3 , V_67 ) ;
}
static bool F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_49 -> V_4 . V_4 . V_9 -> V_12 ;
struct V_67 * V_67 ;
struct V_68 * V_69 ;
F_35 ( V_49 -> V_4 . type != V_71 ) ;
V_69 = F_36 ( V_11 , V_11 -> V_72 ) ;
V_67 = F_28 ( V_3 , V_69 ) ;
if ( V_67 ) {
bool V_73 = V_67 -> V_74 & V_75 ;
if ( ! V_73 ) {
F_21 ( L_7 ) ;
return true ;
}
F_21 ( L_8 ) ;
} else {
F_21 ( L_9 ) ;
}
F_37 ( V_67 ) ;
return false ;
}
static enum V_76
F_38 ( struct V_1 * V_49 )
{
struct V_8 * V_9 = V_49 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_39 = F_13 ( V_49 -> V_4 . V_4 . V_33 ) -> V_39 ;
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
F_21 ( L_10 ) ;
V_86 = F_19 ( V_39 ) ;
V_87 = F_39 ( V_39 ) ;
V_88 = F_40 ( V_39 ) ;
V_89 = F_41 ( V_39 ) ;
V_90 = F_42 ( V_39 ) ;
V_91 = F_43 ( V_39 ) ;
V_77 = F_5 ( V_86 ) ;
V_78 = F_5 ( V_87 ) ;
V_82 = F_5 ( V_88 ) ;
V_79 = ( ( V_78 >> 16 ) & 0xfff ) + 1 ;
V_80 = ( V_78 & 0x7ff ) + 1 ;
V_83 = ( V_82 & 0xfff ) + 1 ;
V_84 = ( ( V_82 >> 16 ) & 0xfff ) + 1 ;
F_6 ( V_86 , 0x500050 ) ;
if ( ! F_10 ( V_9 ) ) {
T_2 V_94 = F_5 ( V_90 ) ;
F_6 ( V_90 , V_94 | V_95 ) ;
F_23 ( V_90 ) ;
F_44 ( V_9 , V_39 ) ;
V_92 = F_45 ( V_96 ) ;
V_93 = ( ( V_92 & ( 1 << 4 ) ) != 0 ) ?
V_97 :
V_98 ;
F_6 ( V_90 , V_94 ) ;
} else {
bool V_99 = false ;
int V_100 , V_101 ;
if ( V_83 <= V_80 && V_84 >= V_79 ) {
T_2 V_102 = F_5 ( V_89 ) ;
T_2 V_103 = ( V_102 & 0xffff ) + 1 ;
V_83 = V_103 ;
F_6 ( V_88 ,
( V_83 - 1 ) |
( ( V_84 - 1 ) << 16 ) ) ;
V_99 = true ;
}
if ( V_83 - V_80 >= V_79 - V_84 )
V_81 = ( V_83 + V_80 ) >> 1 ;
else
V_81 = ( V_79 + V_84 ) >> 1 ;
while ( F_5 ( V_91 ) >= V_80 )
;
while ( ( V_85 = F_5 ( V_91 ) ) <= V_81 )
;
V_101 = 0 ;
V_100 = 0 ;
do {
V_100 ++ ;
V_92 = F_45 ( V_96 ) ;
if ( V_92 & ( 1 << 4 ) )
V_101 ++ ;
} while ( ( F_5 ( V_91 ) == V_85 ) );
if ( V_99 )
F_6 ( V_88 , V_82 ) ;
V_93 = V_101 * 4 > V_100 * 3 ?
V_97 :
V_98 ;
}
F_6 ( V_86 , V_77 ) ;
return V_93 ;
}
static enum V_76
F_46 ( struct V_2 * V_3 , bool V_104 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
enum V_76 V_93 ;
struct V_105 V_106 ;
if ( F_47 ( V_9 ) ) {
if ( F_25 ( V_3 ) ) {
F_21 ( L_11 ) ;
return V_97 ;
} else
F_21 ( L_12 ) ;
}
if ( F_34 ( V_3 ) )
return V_97 ;
if ( F_47 ( V_9 ) )
return V_98 ;
if ( ! V_104 )
return V_3 -> V_93 ;
if ( F_48 ( & V_49 -> V_4 , V_3 , NULL ,
& V_106 ) ) {
if ( F_34 ( V_3 ) )
V_93 = V_97 ;
else
V_93 = F_38 ( V_49 ) ;
F_49 ( & V_49 -> V_4 , V_3 ,
& V_106 ) ;
} else
V_93 = V_107 ;
return V_93 ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_51 ( V_3 ) ;
F_52 ( V_3 ) ;
F_37 ( V_3 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_50 ;
struct V_68 * V_69 ;
V_69 = F_36 ( V_11 , V_11 -> V_72 ) ;
V_50 = F_32 ( V_3 , V_69 ) ;
if ( V_50 || ! F_26 ( V_9 ) )
return V_50 ;
V_69 = F_36 ( V_11 , V_108 ) ;
return F_32 ( V_3 , V_69 ) ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
T_4 V_111 )
{
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( F_15 ( V_9 ) )
V_49 -> V_51 = 1 ;
}
static int T_5 F_56 ( const struct V_112 * V_113 )
{
F_57 ( L_13 , V_113 -> V_114 ) ;
return 1 ;
}
void F_58 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_49 ;
struct V_115 * V_115 ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_116 * V_117 ;
if ( F_59 ( V_118 ) )
return;
V_49 = F_60 ( sizeof( struct V_1 ) , V_119 ) ;
if ( ! V_49 )
return;
V_115 = F_60 ( sizeof( struct V_115 ) , V_119 ) ;
if ( ! V_115 ) {
F_37 ( V_49 ) ;
return;
}
V_3 = & V_115 -> V_4 ;
F_61 ( V_9 , & V_115 -> V_4 ,
& V_120 , V_121 ) ;
F_62 ( V_9 , & V_49 -> V_4 . V_4 , & V_122 ,
V_123 ) ;
F_63 ( V_115 , & V_49 -> V_4 ) ;
V_49 -> V_4 . type = V_71 ;
V_49 -> V_4 . V_124 = ( 1 << V_125 |
1 << V_126 |
1 << V_127 ) ;
if ( F_64 ( V_9 ) )
V_49 -> V_4 . V_128 = ( 1 << 0 ) ;
else
V_49 -> V_4 . V_128 = ( 1 << 0 ) | ( 1 << 1 ) ;
if ( F_10 ( V_9 ) )
V_3 -> V_129 = 0 ;
else
V_3 -> V_129 = 1 ;
V_3 -> V_130 = 0 ;
if ( F_15 ( V_9 ) )
V_117 = & V_131 ;
else
V_117 = & V_132 ;
F_65 ( & V_49 -> V_4 . V_4 , V_117 ) ;
F_66 ( V_3 , & V_133 ) ;
F_67 ( V_3 ) ;
if ( F_47 ( V_9 ) )
V_3 -> V_134 = V_135 ;
else
V_3 -> V_134 = V_136 ;
V_49 -> V_51 = 0 ;
if ( F_15 ( V_9 ) ) {
T_1 V_36 ;
V_36 = F_5 ( V_14 ) ;
V_36 &= ~ V_137 ;
V_36 |= V_42 ;
F_6 ( V_14 , V_36 ) ;
F_23 ( V_14 ) ;
F_21 ( L_14 , V_36 ) ;
V_49 -> V_51 = 1 ;
}
V_11 -> V_138 |= V_66 ;
}
