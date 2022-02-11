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
switch( V_7 ) {
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
if ( V_35 -> V_40 == 0 ) {
if ( F_15 ( V_9 ) )
V_37 |= V_48 ;
else
V_37 |= V_49 ;
} else {
if ( F_15 ( V_9 ) )
V_37 |= V_50 ;
else
V_37 |= V_51 ;
}
if ( ! F_5 ( V_9 ) )
F_7 ( F_16 ( V_35 -> V_40 ) , 0 ) ;
F_7 ( V_39 , V_37 ) ;
}
static bool F_17 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_52 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_37 ;
bool V_53 ;
if ( V_52 -> V_54 ) {
bool V_55 = F_5 ( V_9 ) ;
T_1 V_56 ;
V_52 -> V_54 = 0 ;
V_56 = V_37 = F_6 ( V_15 ) ;
F_18 ( L_1 , V_37 ) ;
V_37 |= V_57 ;
if ( V_55 )
V_37 &= ~ V_19 ;
F_7 ( V_15 , V_37 ) ;
if ( F_19 ( ( F_6 ( V_15 ) & V_57 ) == 0 ,
1000 ) )
F_18 ( L_2 ) ;
if ( V_55 ) {
F_7 ( V_15 , V_56 ) ;
F_20 ( V_15 ) ;
}
}
V_37 = F_6 ( V_15 ) ;
if ( ( V_37 & V_58 ) != 0 )
V_53 = true ;
else
V_53 = false ;
F_18 ( L_3 , V_37 , V_53 ) ;
return V_53 ;
}
static bool F_21 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_59 , V_60 , V_61 ;
bool V_53 = false ;
int V_62 , V_63 = 0 ;
if ( F_5 ( V_9 ) )
return F_17 ( V_3 ) ;
if ( F_22 ( V_9 ) && ! F_23 ( V_9 ) )
V_63 = 2 ;
else
V_63 = 1 ;
V_59 = V_60 = F_6 ( V_64 ) ;
V_59 |= V_65 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
F_7 ( V_64 , V_59 ) ;
if ( F_19 ( ( F_6 ( V_64 ) &
V_65 ) == 0 ,
1000 ) )
F_18 ( L_4 ) ;
}
V_61 = F_6 ( V_66 ) ;
if ( ( V_61 & V_67 ) != V_68 )
V_53 = true ;
F_7 ( V_66 , V_69 ) ;
F_7 ( V_64 , V_60 ) ;
return V_53 ;
}
static bool F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_52 -> V_4 . V_4 . V_9 -> V_12 ;
if ( V_52 -> V_4 . type != V_70 )
return false ;
if ( F_25 ( & V_52 -> V_4 , V_11 -> V_71 ) ) {
struct V_72 * V_72 ;
bool V_73 = false ;
V_72 = F_26 ( V_3 ,
& V_11 -> V_74 [ V_11 -> V_71 ] . V_75 ) ;
if ( V_72 != NULL ) {
V_73 = V_72 -> V_76 & V_77 ;
V_3 -> V_78 . V_79 = NULL ;
F_27 ( V_72 ) ;
}
if ( ! V_73 ) {
F_18 ( L_5 ) ;
return true ;
} else {
F_18 ( L_6 ) ;
}
}
return false ;
}
static enum V_80
F_28 ( struct V_1 * V_52 )
{
struct V_8 * V_9 = V_52 -> V_4 . V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_2 V_40 = F_12 ( V_52 -> V_4 . V_4 . V_34 ) -> V_40 ;
T_2 V_81 ;
T_2 V_82 ;
T_2 V_83 , V_84 ;
T_2 V_85 ;
T_2 V_86 , V_87 , V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 ;
T_3 V_96 ;
enum V_80 V_97 ;
F_18 ( L_7 ) ;
V_90 = F_16 ( V_40 ) ;
V_91 = F_29 ( V_40 ) ;
V_92 = F_30 ( V_40 ) ;
V_93 = F_31 ( V_40 ) ;
V_94 = F_32 ( V_40 ) ;
V_95 = F_33 ( V_40 ) ;
V_81 = F_6 ( V_90 ) ;
V_82 = F_6 ( V_91 ) ;
V_86 = F_6 ( V_92 ) ;
V_83 = ( ( V_82 >> 16 ) & 0xfff ) + 1 ;
V_84 = ( V_82 & 0x7ff ) + 1 ;
V_87 = ( V_86 & 0xfff ) + 1 ;
V_88 = ( ( V_86 >> 16 ) & 0xfff ) + 1 ;
F_7 ( V_90 , 0x500050 ) ;
if ( ! F_9 ( V_9 ) ) {
T_2 V_98 = F_6 ( V_94 ) ;
F_7 ( V_94 , V_98 | V_99 ) ;
F_20 ( V_94 ) ;
F_34 ( V_9 , V_40 ) ;
V_96 = F_35 ( V_100 ) ;
V_97 = ( ( V_96 & ( 1 << 4 ) ) != 0 ) ?
V_101 :
V_102 ;
F_7 ( V_94 , V_98 ) ;
} else {
bool V_103 = false ;
int V_104 , V_105 ;
if ( V_87 <= V_84 && V_88 >= V_83 ) {
T_2 V_106 = F_6 ( V_93 ) ;
T_2 V_107 = ( V_106 & 0xffff ) + 1 ;
V_87 = V_107 ;
F_7 ( V_92 ,
( V_87 - 1 ) |
( ( V_88 - 1 ) << 16 ) ) ;
V_103 = true ;
}
if ( V_87 - V_84 >= V_83 - V_88 )
V_85 = ( V_87 + V_84 ) >> 1 ;
else
V_85 = ( V_83 + V_88 ) >> 1 ;
while ( F_6 ( V_95 ) >= V_84 )
;
while ( ( V_89 = F_6 ( V_95 ) ) <= V_85 )
;
V_105 = 0 ;
V_104 = 0 ;
do {
V_104 ++ ;
V_96 = F_35 ( V_100 ) ;
if ( V_96 & ( 1 << 4 ) )
V_105 ++ ;
} while ( ( F_6 ( V_95 ) == V_89 ) );
if ( V_103 )
F_7 ( V_92 , V_86 ) ;
V_97 = V_105 * 4 > V_104 * 3 ?
V_101 :
V_102 ;
}
F_7 ( V_90 , V_81 ) ;
return V_97 ;
}
static enum V_80
F_36 ( struct V_2 * V_3 , bool V_108 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_52 = F_1 ( V_3 ) ;
struct V_33 * V_34 ;
enum V_80 V_97 ;
if ( F_37 ( V_9 ) ) {
if ( F_21 ( V_3 ) ) {
F_18 ( L_8 ) ;
return V_101 ;
} else {
F_18 ( L_9 ) ;
return V_102 ;
}
}
if ( F_24 ( V_3 ) )
return V_101 ;
if ( ! V_108 )
return V_3 -> V_97 ;
V_34 = V_52 -> V_4 . V_4 . V_34 ;
if ( V_34 && V_34 -> V_109 ) {
V_97 = F_28 ( V_52 ) ;
} else {
struct V_110 V_111 ;
if ( F_38 ( & V_52 -> V_4 , V_3 , NULL ,
& V_111 ) ) {
if ( F_24 ( V_3 ) )
V_97 = V_101 ;
else
V_97 = F_28 ( V_52 ) ;
F_39 ( & V_52 -> V_4 , V_3 ,
& V_111 ) ;
} else
V_97 = V_112 ;
}
return V_97 ;
}
static void F_40 ( struct V_2 * V_3 )
{
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_27 ( V_3 ) ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_53 ;
V_53 = F_44 ( V_3 ,
& V_11 -> V_74 [ V_11 -> V_71 ] . V_75 ) ;
if ( V_53 || ! F_22 ( V_9 ) )
return V_53 ;
return F_44 ( V_3 ,
& V_11 -> V_74 [ V_113 ] . V_75 ) ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_114 * V_115 ,
T_4 V_116 )
{
return 0 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_52 = F_1 ( V_3 ) ;
if ( F_5 ( V_9 ) )
V_52 -> V_54 = 1 ;
}
void F_47 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_52 ;
struct V_117 * V_117 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_52 = F_48 ( sizeof( struct V_1 ) , V_118 ) ;
if ( ! V_52 )
return;
V_117 = F_48 ( sizeof( struct V_117 ) , V_118 ) ;
if ( ! V_117 ) {
F_27 ( V_52 ) ;
return;
}
V_3 = & V_117 -> V_4 ;
F_49 ( V_9 , & V_117 -> V_4 ,
& V_119 , V_120 ) ;
F_50 ( V_9 , & V_52 -> V_4 . V_4 , & V_121 ,
V_122 ) ;
F_51 ( V_117 , & V_52 -> V_4 ) ;
V_52 -> V_4 . type = V_70 ;
V_52 -> V_4 . V_123 = ( 1 << V_124 |
1 << V_125 |
1 << V_126 ) ;
V_52 -> V_4 . V_127 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_3 -> V_128 = 1 ;
V_3 -> V_129 = 0 ;
F_52 ( & V_52 -> V_4 . V_4 , & V_130 ) ;
F_53 ( V_3 , & V_131 ) ;
F_54 ( V_3 ) ;
if ( F_37 ( V_9 ) )
V_3 -> V_132 = V_133 ;
else
V_3 -> V_132 = V_134 ;
V_52 -> V_54 = 0 ;
if ( F_5 ( V_9 ) ) {
T_1 V_37 ;
V_37 = F_6 ( V_15 ) ;
V_37 &= ~ V_135 ;
V_37 |= V_43 ;
F_7 ( V_15 , V_37 ) ;
F_20 ( V_15 ) ;
F_18 ( L_10 , V_37 ) ;
V_52 -> V_54 = 1 ;
}
V_11 -> V_136 |= V_69 ;
}
