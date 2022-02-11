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
static int F_8 ( struct V_2 * V_3 ,
struct V_23 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_24 = 0 ;
if ( V_7 -> V_25 & V_26 )
return V_27 ;
if ( V_7 -> clock < 25000 )
return V_28 ;
if ( F_9 ( V_9 ) )
V_24 = 350000 ;
else
V_24 = 400000 ;
if ( V_7 -> clock > V_24 )
return V_29 ;
return V_30 ;
}
static bool F_10 ( struct V_5 * V_6 ,
struct V_23 * V_7 ,
struct V_23 * V_31 )
{
return true ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_23 * V_7 ,
struct V_23 * V_31 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_32 * V_33 = V_6 -> V_33 ;
struct V_34 * V_34 = F_12 ( V_33 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_35 ;
T_1 V_36 , V_37 ;
T_1 V_38 ;
V_35 = F_13 ( V_34 -> V_39 ) ;
if ( F_14 ( V_9 ) )
V_38 = V_14 ;
else
V_38 = V_20 ;
if ( F_15 ( V_9 ) -> V_40 >= 4 && ! F_14 ( V_9 ) ) {
V_37 = F_5 ( V_35 ) ;
F_6 ( V_35 ,
V_37 & ~ V_41 ) ;
}
V_36 = V_42 ;
if ( V_31 -> V_25 & V_43 )
V_36 |= V_44 ;
if ( V_31 -> V_25 & V_45 )
V_36 |= V_46 ;
if ( F_16 ( V_9 ) )
V_36 |= F_17 ( V_34 -> V_39 ) ;
else if ( V_34 -> V_39 == 0 )
V_36 |= V_47 ;
else
V_36 |= V_48 ;
if ( ! F_14 ( V_9 ) )
F_6 ( F_18 ( V_34 -> V_39 ) , 0 ) ;
F_6 ( V_38 , V_36 ) ;
}
static bool F_19 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_36 ;
bool V_50 ;
if ( V_49 -> V_51 ) {
bool V_52 = F_14 ( V_9 ) ;
T_1 V_53 ;
V_49 -> V_51 = 0 ;
V_53 = V_36 = F_5 ( V_14 ) ;
F_20 ( L_1 , V_36 ) ;
V_36 |= V_54 ;
if ( V_52 )
V_36 &= ~ V_15 ;
F_6 ( V_14 , V_36 ) ;
if ( F_21 ( ( F_5 ( V_14 ) & V_54 ) == 0 ,
1000 ) )
F_20 ( L_2 ) ;
if ( V_52 ) {
F_6 ( V_14 , V_53 ) ;
F_22 ( V_14 ) ;
}
}
V_36 = F_5 ( V_14 ) ;
if ( ( V_36 & V_55 ) != 0 )
V_50 = true ;
else
V_50 = false ;
F_20 ( L_3 , V_36 , V_50 ) ;
return V_50 ;
}
static bool F_23 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_56 , V_57 , V_58 ;
bool V_50 = false ;
int V_59 , V_60 = 0 ;
if ( F_14 ( V_9 ) )
return F_19 ( V_3 ) ;
if ( F_24 ( V_9 ) && ! F_25 ( V_9 ) )
V_60 = 2 ;
else
V_60 = 1 ;
V_56 = V_57 = F_5 ( V_61 ) ;
V_56 |= V_62 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
F_6 ( V_61 , V_56 ) ;
if ( F_21 ( ( F_5 ( V_61 ) &
V_62 ) == 0 ,
1000 ) )
F_20 ( L_4 ) ;
}
V_58 = F_5 ( V_63 ) ;
if ( ( V_58 & V_64 ) != V_65 )
V_50 = true ;
F_6 ( V_63 , V_66 ) ;
F_6 ( V_61 , V_57 ) ;
return V_50 ;
}
static bool F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_49 -> V_4 . V_4 . V_9 -> V_12 ;
if ( V_49 -> V_4 . type != V_67 )
return false ;
if ( F_27 ( & V_49 -> V_4 , V_11 -> V_68 ) ) {
struct V_69 * V_69 ;
bool V_70 = false ;
struct V_71 * V_72 ;
V_72 = F_28 ( V_11 , V_11 -> V_68 ) ;
V_69 = F_29 ( V_3 , V_72 ) ;
if ( V_69 != NULL ) {
V_70 = V_69 -> V_73 & V_74 ;
V_3 -> V_75 . V_76 = NULL ;
F_30 ( V_69 ) ;
}
if ( ! V_70 ) {
F_20 ( L_5 ) ;
return true ;
} else {
F_20 ( L_6 ) ;
}
}
return false ;
}
static enum V_77
F_31 ( struct V_1 * V_49 )
{
struct V_8 * V_9 = V_49 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_39 = F_12 ( V_49 -> V_4 . V_4 . V_33 ) -> V_39 ;
T_2 V_78 ;
T_2 V_79 ;
T_2 V_80 , V_81 ;
T_2 V_82 ;
T_2 V_83 , V_84 , V_85 ;
T_2 V_86 ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 ;
T_3 V_93 ;
enum V_77 V_94 ;
F_20 ( L_7 ) ;
V_87 = F_18 ( V_39 ) ;
V_88 = F_32 ( V_39 ) ;
V_89 = F_33 ( V_39 ) ;
V_90 = F_34 ( V_39 ) ;
V_91 = F_35 ( V_39 ) ;
V_92 = F_36 ( V_39 ) ;
V_78 = F_5 ( V_87 ) ;
V_79 = F_5 ( V_88 ) ;
V_83 = F_5 ( V_89 ) ;
V_80 = ( ( V_79 >> 16 ) & 0xfff ) + 1 ;
V_81 = ( V_79 & 0x7ff ) + 1 ;
V_84 = ( V_83 & 0xfff ) + 1 ;
V_85 = ( ( V_83 >> 16 ) & 0xfff ) + 1 ;
F_6 ( V_87 , 0x500050 ) ;
if ( ! F_9 ( V_9 ) ) {
T_2 V_95 = F_5 ( V_91 ) ;
F_6 ( V_91 , V_95 | V_96 ) ;
F_22 ( V_91 ) ;
F_37 ( V_9 , V_39 ) ;
V_93 = F_38 ( V_97 ) ;
V_94 = ( ( V_93 & ( 1 << 4 ) ) != 0 ) ?
V_98 :
V_99 ;
F_6 ( V_91 , V_95 ) ;
} else {
bool V_100 = false ;
int V_101 , V_102 ;
if ( V_84 <= V_81 && V_85 >= V_80 ) {
T_2 V_103 = F_5 ( V_90 ) ;
T_2 V_104 = ( V_103 & 0xffff ) + 1 ;
V_84 = V_104 ;
F_6 ( V_89 ,
( V_84 - 1 ) |
( ( V_85 - 1 ) << 16 ) ) ;
V_100 = true ;
}
if ( V_84 - V_81 >= V_80 - V_85 )
V_82 = ( V_84 + V_81 ) >> 1 ;
else
V_82 = ( V_80 + V_85 ) >> 1 ;
while ( F_5 ( V_92 ) >= V_81 )
;
while ( ( V_86 = F_5 ( V_92 ) ) <= V_82 )
;
V_102 = 0 ;
V_101 = 0 ;
do {
V_101 ++ ;
V_93 = F_38 ( V_97 ) ;
if ( V_93 & ( 1 << 4 ) )
V_102 ++ ;
} while ( ( F_5 ( V_92 ) == V_86 ) );
if ( V_100 )
F_6 ( V_89 , V_83 ) ;
V_94 = V_102 * 4 > V_101 * 3 ?
V_98 :
V_99 ;
}
F_6 ( V_87 , V_78 ) ;
return V_94 ;
}
static enum V_77
F_39 ( struct V_2 * V_3 , bool V_105 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
enum V_77 V_94 ;
struct V_106 V_107 ;
if ( F_40 ( V_9 ) ) {
if ( F_23 ( V_3 ) ) {
F_20 ( L_8 ) ;
return V_98 ;
} else {
F_20 ( L_9 ) ;
return V_99 ;
}
}
if ( F_26 ( V_3 ) )
return V_98 ;
if ( ! V_105 )
return V_3 -> V_94 ;
if ( F_41 ( & V_49 -> V_4 , V_3 , NULL ,
& V_107 ) ) {
if ( F_26 ( V_3 ) )
V_94 = V_98 ;
else
V_94 = F_31 ( V_49 ) ;
F_42 ( & V_49 -> V_4 , V_3 ,
& V_107 ) ;
} else
V_94 = V_108 ;
return V_94 ;
}
static void F_43 ( struct V_2 * V_3 )
{
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_30 ( V_3 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_50 ;
struct V_71 * V_72 ;
V_72 = F_28 ( V_11 , V_11 -> V_68 ) ;
V_50 = F_47 ( V_3 , V_72 ) ;
if ( V_50 || ! F_24 ( V_9 ) )
return V_50 ;
V_72 = F_28 ( V_11 , V_109 ) ;
return F_47 ( V_3 , V_72 ) ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_110 * V_111 ,
T_4 V_112 )
{
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( F_14 ( V_9 ) )
V_49 -> V_51 = 1 ;
}
static int T_5 F_50 ( const struct V_113 * V_114 )
{
F_51 ( L_10 , V_114 -> V_115 ) ;
return 1 ;
}
void F_52 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_49 ;
struct V_116 * V_116 ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_117 * V_118 ;
if ( F_53 ( V_119 ) )
return;
V_49 = F_54 ( sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_49 )
return;
V_116 = F_54 ( sizeof( struct V_116 ) , V_120 ) ;
if ( ! V_116 ) {
F_30 ( V_49 ) ;
return;
}
V_3 = & V_116 -> V_4 ;
F_55 ( V_9 , & V_116 -> V_4 ,
& V_121 , V_122 ) ;
F_56 ( V_9 , & V_49 -> V_4 . V_4 , & V_123 ,
V_124 ) ;
F_57 ( V_116 , & V_49 -> V_4 ) ;
V_49 -> V_4 . type = V_67 ;
V_49 -> V_4 . V_125 = ( 1 << V_126 |
1 << V_127 |
1 << V_128 ) ;
if ( F_58 ( V_9 ) )
V_49 -> V_4 . V_129 = ( 1 << 0 ) ;
else
V_49 -> V_4 . V_129 = ( 1 << 0 ) | ( 1 << 1 ) ;
if ( F_9 ( V_9 ) )
V_3 -> V_130 = 0 ;
else
V_3 -> V_130 = 1 ;
V_3 -> V_131 = 0 ;
if ( F_14 ( V_9 ) )
V_118 = & V_132 ;
else
V_118 = & V_133 ;
F_59 ( & V_49 -> V_4 . V_4 , V_118 ) ;
F_60 ( V_3 , & V_134 ) ;
F_61 ( V_3 ) ;
if ( F_40 ( V_9 ) )
V_3 -> V_135 = V_136 ;
else
V_3 -> V_135 = V_137 ;
V_49 -> V_51 = 0 ;
if ( F_14 ( V_9 ) ) {
T_1 V_36 ;
V_36 = F_5 ( V_14 ) ;
V_36 &= ~ V_138 ;
V_36 |= V_42 ;
F_6 ( V_14 , V_36 ) ;
F_22 ( V_14 ) ;
F_20 ( L_11 , V_36 ) ;
V_49 -> V_51 = 1 ;
}
V_11 -> V_139 |= V_66 ;
}
