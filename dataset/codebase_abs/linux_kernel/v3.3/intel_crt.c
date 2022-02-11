static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_13 , V_14 ;
if ( F_5 ( V_9 ) )
V_14 = V_15 ;
else
V_14 = V_16 ;
V_13 = F_6 ( V_14 ) ;
V_13 &= ~ ( V_17 | V_18 ) ;
V_13 &= ~ V_19 ;
switch ( V_7 ) {
case V_20 :
V_13 |= V_19 ;
break;
case V_21 :
V_13 |= V_19 | V_17 ;
break;
case V_22 :
V_13 |= V_19 | V_18 ;
break;
case V_23 :
V_13 |= V_17 | V_18 ;
break;
}
F_7 ( V_14 , V_13 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_24 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
int V_25 = 0 ;
if ( V_7 -> V_26 & V_27 )
return V_28 ;
if ( V_7 -> clock < 25000 )
return V_29 ;
if ( F_9 ( V_9 ) )
V_25 = 350000 ;
else
V_25 = 400000 ;
if ( V_7 -> clock > V_25 )
return V_30 ;
return V_31 ;
}
static bool F_10 ( struct V_5 * V_6 ,
struct V_24 * V_7 ,
struct V_24 * V_32 )
{
return true ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_24 * V_7 ,
struct V_24 * V_32 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_33 * V_34 = V_6 -> V_34 ;
struct V_35 * V_35 = F_12 ( V_34 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_36 ;
T_1 V_37 , V_38 ;
T_1 V_39 ;
V_36 = F_13 ( V_35 -> V_40 ) ;
if ( F_5 ( V_9 ) )
V_39 = V_15 ;
else
V_39 = V_16 ;
if ( F_14 ( V_9 ) -> V_41 >= 4 && ! F_5 ( V_9 ) ) {
V_38 = F_6 ( V_36 ) ;
F_7 ( V_36 ,
V_38 & ~ V_42 ) ;
}
V_37 = V_43 ;
if ( V_32 -> V_26 & V_44 )
V_37 |= V_45 ;
if ( V_32 -> V_26 & V_46 )
V_37 |= V_47 ;
if ( F_15 ( V_9 ) )
V_37 |= F_16 ( V_35 -> V_40 ) ;
else if ( V_35 -> V_40 == 0 )
V_37 |= V_48 ;
else
V_37 |= V_49 ;
if ( ! F_5 ( V_9 ) )
F_7 ( F_17 ( V_35 -> V_40 ) , 0 ) ;
F_7 ( V_39 , V_37 ) ;
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_51 ;
if ( V_50 -> V_52 ) {
bool V_53 = F_5 ( V_9 ) ;
T_1 V_54 ;
V_50 -> V_52 = 0 ;
V_54 = V_37 = F_6 ( V_15 ) ;
F_19 ( L_1 , V_37 ) ;
V_37 |= V_55 ;
if ( V_53 )
V_37 &= ~ V_19 ;
F_7 ( V_15 , V_37 ) ;
if ( F_20 ( ( F_6 ( V_15 ) & V_55 ) == 0 ,
1000 ) )
F_19 ( L_2 ) ;
if ( V_53 ) {
F_7 ( V_15 , V_54 ) ;
F_21 ( V_15 ) ;
}
}
V_37 = F_6 ( V_15 ) ;
if ( ( V_37 & V_56 ) != 0 )
V_51 = true ;
else
V_51 = false ;
F_19 ( L_3 , V_37 , V_51 ) ;
return V_51 ;
}
static bool F_22 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_57 , V_58 , V_59 ;
bool V_51 = false ;
int V_60 , V_61 = 0 ;
if ( F_5 ( V_9 ) )
return F_18 ( V_3 ) ;
if ( F_23 ( V_9 ) && ! F_24 ( V_9 ) )
V_61 = 2 ;
else
V_61 = 1 ;
V_57 = V_58 = F_6 ( V_62 ) ;
V_57 |= V_63 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
F_7 ( V_62 , V_57 ) ;
if ( F_20 ( ( F_6 ( V_62 ) &
V_63 ) == 0 ,
1000 ) )
F_19 ( L_4 ) ;
}
V_59 = F_6 ( V_64 ) ;
if ( ( V_59 & V_65 ) != V_66 )
V_51 = true ;
F_7 ( V_64 , V_67 ) ;
F_7 ( V_62 , V_58 ) ;
return V_51 ;
}
static bool F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_50 -> V_4 . V_4 . V_9 -> V_12 ;
if ( V_50 -> V_4 . type != V_68 )
return false ;
if ( F_26 ( & V_50 -> V_4 , V_11 -> V_69 ) ) {
struct V_70 * V_70 ;
bool V_71 = false ;
V_70 = F_27 ( V_3 ,
& V_11 -> V_72 [ V_11 -> V_69 ] . V_73 ) ;
if ( V_70 != NULL ) {
V_71 = V_70 -> V_74 & V_75 ;
V_3 -> V_76 . V_77 = NULL ;
F_28 ( V_70 ) ;
}
if ( ! V_71 ) {
F_19 ( L_5 ) ;
return true ;
} else {
F_19 ( L_6 ) ;
}
}
return false ;
}
static enum V_78
F_29 ( struct V_1 * V_50 )
{
struct V_8 * V_9 = V_50 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_40 = F_12 ( V_50 -> V_4 . V_4 . V_34 ) -> V_40 ;
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
F_19 ( L_7 ) ;
V_88 = F_17 ( V_40 ) ;
V_89 = F_30 ( V_40 ) ;
V_90 = F_31 ( V_40 ) ;
V_91 = F_32 ( V_40 ) ;
V_92 = F_33 ( V_40 ) ;
V_93 = F_34 ( V_40 ) ;
V_79 = F_6 ( V_88 ) ;
V_80 = F_6 ( V_89 ) ;
V_84 = F_6 ( V_90 ) ;
V_81 = ( ( V_80 >> 16 ) & 0xfff ) + 1 ;
V_82 = ( V_80 & 0x7ff ) + 1 ;
V_85 = ( V_84 & 0xfff ) + 1 ;
V_86 = ( ( V_84 >> 16 ) & 0xfff ) + 1 ;
F_7 ( V_88 , 0x500050 ) ;
if ( ! F_9 ( V_9 ) ) {
T_2 V_96 = F_6 ( V_92 ) ;
F_7 ( V_92 , V_96 | V_97 ) ;
F_21 ( V_92 ) ;
F_35 ( V_9 , V_40 ) ;
V_94 = F_36 ( V_98 ) ;
V_95 = ( ( V_94 & ( 1 << 4 ) ) != 0 ) ?
V_99 :
V_100 ;
F_7 ( V_92 , V_96 ) ;
} else {
bool V_101 = false ;
int V_102 , V_103 ;
if ( V_85 <= V_82 && V_86 >= V_81 ) {
T_2 V_104 = F_6 ( V_91 ) ;
T_2 V_105 = ( V_104 & 0xffff ) + 1 ;
V_85 = V_105 ;
F_7 ( V_90 ,
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
V_94 = F_36 ( V_98 ) ;
if ( V_94 & ( 1 << 4 ) )
V_103 ++ ;
} while ( ( F_6 ( V_93 ) == V_87 ) );
if ( V_101 )
F_7 ( V_90 , V_84 ) ;
V_95 = V_103 * 4 > V_102 * 3 ?
V_99 :
V_100 ;
}
F_7 ( V_88 , V_79 ) ;
return V_95 ;
}
static enum V_78
F_37 ( struct V_2 * V_3 , bool V_106 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_33 * V_34 ;
enum V_78 V_95 ;
if ( F_38 ( V_9 ) ) {
if ( F_22 ( V_3 ) ) {
F_19 ( L_8 ) ;
return V_99 ;
} else {
F_19 ( L_9 ) ;
return V_100 ;
}
}
if ( F_25 ( V_3 ) )
return V_99 ;
if ( ! V_106 )
return V_3 -> V_95 ;
V_34 = V_50 -> V_4 . V_4 . V_34 ;
if ( V_34 && V_34 -> V_107 ) {
V_95 = F_29 ( V_50 ) ;
} else {
struct V_108 V_109 ;
if ( F_39 ( & V_50 -> V_4 , V_3 , NULL ,
& V_109 ) ) {
if ( F_25 ( V_3 ) )
V_95 = V_99 ;
else
V_95 = F_29 ( V_50 ) ;
F_40 ( & V_50 -> V_4 , V_3 ,
& V_109 ) ;
} else
V_95 = V_110 ;
}
return V_95 ;
}
static void F_41 ( struct V_2 * V_3 )
{
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
F_28 ( V_3 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_51 ;
V_51 = F_45 ( V_3 ,
& V_11 -> V_72 [ V_11 -> V_69 ] . V_73 ) ;
if ( V_51 || ! F_23 ( V_9 ) )
return V_51 ;
return F_45 ( V_3 ,
& V_11 -> V_72 [ V_111 ] . V_73 ) ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_112 * V_113 ,
T_4 V_114 )
{
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_50 = F_1 ( V_3 ) ;
if ( F_5 ( V_9 ) )
V_50 -> V_52 = 1 ;
}
static int T_5 F_48 ( const struct V_115 * V_116 )
{
F_19 ( L_10 , V_116 -> V_117 ) ;
return 1 ;
}
void F_49 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_50 ;
struct V_118 * V_118 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( F_50 ( V_119 ) )
return;
V_50 = F_51 ( sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_50 )
return;
V_118 = F_51 ( sizeof( struct V_118 ) , V_120 ) ;
if ( ! V_118 ) {
F_28 ( V_50 ) ;
return;
}
V_3 = & V_118 -> V_4 ;
F_52 ( V_9 , & V_118 -> V_4 ,
& V_121 , V_122 ) ;
F_53 ( V_9 , & V_50 -> V_4 . V_4 , & V_123 ,
V_124 ) ;
F_54 ( V_118 , & V_50 -> V_4 ) ;
V_50 -> V_4 . type = V_68 ;
V_50 -> V_4 . V_125 = ( 1 << V_126 |
1 << V_127 |
1 << V_128 ) ;
V_50 -> V_4 . V_129 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_3 -> V_130 = 1 ;
V_3 -> V_131 = 0 ;
F_55 ( & V_50 -> V_4 . V_4 , & V_132 ) ;
F_56 ( V_3 , & V_133 ) ;
F_57 ( V_3 ) ;
if ( F_38 ( V_9 ) )
V_3 -> V_134 = V_135 ;
else
V_3 -> V_134 = V_136 ;
V_50 -> V_52 = 0 ;
if ( F_5 ( V_9 ) ) {
T_1 V_37 ;
V_37 = F_6 ( V_15 ) ;
V_37 &= ~ V_137 ;
V_37 |= V_43 ;
F_7 ( V_15 , V_37 ) ;
F_21 ( V_15 ) ;
F_19 ( L_11 , V_37 ) ;
V_50 -> V_52 = 1 ;
}
V_11 -> V_138 |= V_67 ;
}
