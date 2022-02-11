struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
void F_5 ( struct V_7 * V_8 )
{
T_1 * V_9 = ( T_1 * ) V_8 ;
T_1 V_10 = 0 ;
unsigned V_11 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_14 + V_15 ; V_11 ++ )
V_10 += V_9 [ V_11 ] ;
V_8 -> V_12 = 0x100 - V_10 ;
}
static T_2 F_6 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
default:
F_7 ( L_1 , V_8 -> type ) ;
return 0 ;
}
}
static T_2 F_8 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_16 :
return V_20 ;
case V_18 :
return V_21 ;
default:
F_7 ( L_1 , V_8 -> type ) ;
return 0 ;
}
}
static T_2 F_9 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_16 :
return V_22 ;
case V_18 :
return V_23 ;
default:
F_7 ( L_1 , V_8 -> type ) ;
return 0 ;
}
}
static T_2 F_10 ( struct V_7 * V_8 , enum V_24 V_24 )
{
switch ( V_8 -> type ) {
case V_16 :
return F_11 ( V_24 ) ;
case V_18 :
return F_12 ( V_24 ) ;
default:
F_7 ( L_1 , V_8 -> type ) ;
return 0 ;
}
}
static void F_13 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_30 = F_14 ( V_31 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
V_30 &= ~ V_32 ;
if ( V_1 -> V_33 == V_34 )
V_30 |= V_35 ;
else if ( V_1 -> V_33 == V_36 )
V_30 |= V_37 ;
else
return;
V_30 &= ~ ( V_38 | 0xf ) ;
V_30 |= F_6 ( V_8 ) ;
V_30 &= ~ F_8 ( V_8 ) ;
V_30 |= V_39 ;
F_15 ( V_31 , V_30 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_15 ( V_40 , * V_9 ) ;
V_9 ++ ;
}
V_30 |= F_8 ( V_8 ) ;
V_30 &= ~ V_41 ;
V_30 |= V_42 ;
F_15 ( V_31 , V_30 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_43 * V_43 = F_17 ( V_3 -> V_44 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_45 = F_18 ( V_43 -> V_24 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
T_2 V_30 = F_14 ( V_45 ) ;
V_30 &= ~ V_32 ;
switch ( V_1 -> V_33 ) {
case V_46 :
V_30 |= V_35 ;
break;
case V_47 :
V_30 |= V_37 ;
break;
case V_48 :
V_30 |= V_49 ;
break;
default:
return;
}
F_19 ( V_26 , V_43 -> V_24 ) ;
V_30 &= ~ ( V_38 | 0xf ) ;
V_30 |= F_6 ( V_8 ) ;
V_30 &= ~ F_8 ( V_8 ) ;
V_30 |= V_39 ;
F_15 ( V_45 , V_30 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_15 ( F_20 ( V_43 -> V_24 ) , * V_9 ) ;
V_9 ++ ;
}
V_30 |= F_8 ( V_8 ) ;
V_30 &= ~ V_41 ;
V_30 |= V_42 ;
F_15 ( V_45 , V_30 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_43 * V_43 = F_17 ( V_3 -> V_44 ) ;
int V_45 = F_18 ( V_43 -> V_24 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
T_2 V_30 = F_14 ( V_45 ) ;
F_19 ( V_26 , V_43 -> V_24 ) ;
V_30 &= ~ ( V_38 | 0xf ) ;
V_30 |= F_6 ( V_8 ) ;
if ( V_8 -> type == V_16 )
V_30 |= V_20 ;
else
V_30 &= ~ F_8 ( V_8 ) ;
V_30 |= V_39 ;
F_15 ( V_45 , V_30 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_15 ( F_20 ( V_43 -> V_24 ) , * V_9 ) ;
V_9 ++ ;
}
V_30 |= F_8 ( V_8 ) ;
V_30 &= ~ V_41 ;
V_30 |= V_42 ;
F_15 ( V_45 , V_30 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_43 * V_43 = F_17 ( V_3 -> V_44 ) ;
int V_45 = F_23 ( V_43 -> V_24 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
T_2 V_30 = F_14 ( V_45 ) ;
F_19 ( V_26 , V_43 -> V_24 ) ;
V_30 &= ~ ( V_38 | 0xf ) ;
V_30 |= F_6 ( V_8 ) ;
V_30 &= ~ F_8 ( V_8 ) ;
V_30 |= V_39 ;
F_15 ( V_45 , V_30 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_15 ( F_24 ( V_43 -> V_24 ) , * V_9 ) ;
V_9 ++ ;
}
V_30 |= F_8 ( V_8 ) ;
V_30 &= ~ V_41 ;
V_30 |= V_42 ;
F_15 ( V_45 , V_30 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_43 * V_43 = F_17 ( V_3 -> V_44 ) ;
T_2 V_50 = F_26 ( V_43 -> V_24 ) ;
T_2 V_51 = F_10 ( V_8 , V_43 -> V_24 ) ;
unsigned int V_11 , V_14 = V_15 + V_8 -> V_14 ;
T_2 V_30 = F_14 ( V_50 ) ;
if ( V_51 == 0 )
return;
F_19 ( V_26 , V_43 -> V_24 ) ;
V_30 &= ~ F_9 ( V_8 ) ;
F_15 ( V_50 , V_30 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_15 ( V_51 + V_11 , * V_9 ) ;
V_9 ++ ;
}
V_30 |= F_9 ( V_8 ) ;
F_15 ( V_50 , V_30 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_52 )
return;
F_5 ( V_8 ) ;
V_1 -> V_53 ( V_3 , V_8 ) ;
}
void F_28 ( struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_7 V_56 = {
. type = V_16 ,
. V_57 = V_58 ,
. V_14 = V_59 ,
} ;
if ( V_55 -> V_60 & V_61 )
V_56 . V_62 . V_63 . V_64 |= V_65 ;
F_27 ( V_3 , & V_56 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_7 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_18 ;
V_66 . V_57 = V_67 ;
V_66 . V_14 = V_68 ;
strcpy ( V_66 . V_62 . V_69 . V_70 , L_2 ) ;
strcpy ( V_66 . V_62 . V_69 . V_71 , L_3 ) ;
V_66 . V_62 . V_69 . V_72 = V_73 ;
F_27 ( V_3 , & V_66 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_54 * V_74 ,
struct V_54 * V_55 )
{
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_43 * V_43 = F_17 ( V_3 -> V_44 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_75 ;
V_75 = V_76 | V_77 ;
if ( ! F_31 ( V_26 ) )
V_75 |= V_1 -> V_78 ;
if ( V_55 -> V_60 & V_79 )
V_75 |= V_80 ;
if ( V_55 -> V_60 & V_81 )
V_75 |= V_82 ;
if ( V_43 -> V_83 > 24 )
V_75 |= V_84 ;
else
V_75 |= V_85 ;
if ( V_1 -> V_52 && F_32 ( V_26 ) )
V_75 |= V_86 ;
if ( V_1 -> V_87 ) {
F_7 ( L_4 ,
F_33 ( V_43 -> V_24 ) ) ;
V_75 |= V_88 ;
V_75 |= V_89 ;
F_34 ( V_3 , V_55 ) ;
}
if ( F_32 ( V_26 ) )
V_75 |= F_35 ( V_43 -> V_24 ) ;
else if ( V_43 -> V_24 == 1 )
V_75 |= V_90 ;
F_15 ( V_1 -> V_33 , V_75 ) ;
F_36 ( V_1 -> V_33 ) ;
F_28 ( V_3 , V_55 ) ;
F_29 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_74 )
{
struct V_25 * V_26 = V_3 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_91 ;
T_2 V_92 = V_93 ;
if ( V_1 -> V_87 )
V_92 |= V_88 ;
V_91 = F_14 ( V_1 -> V_33 ) ;
if ( F_31 ( V_26 ) ) {
F_15 ( V_1 -> V_33 , V_91 & ~ V_93 ) ;
F_36 ( V_1 -> V_33 ) ;
}
if ( V_74 != V_94 ) {
V_91 &= ~ V_92 ;
} else {
V_91 |= V_92 ;
}
F_15 ( V_1 -> V_33 , V_91 ) ;
F_36 ( V_1 -> V_33 ) ;
if ( F_31 ( V_26 ) ) {
F_15 ( V_1 -> V_33 , V_91 ) ;
F_36 ( V_1 -> V_33 ) ;
}
}
static int F_38 ( struct V_5 * V_6 ,
struct V_54 * V_74 )
{
if ( V_74 -> clock > 165000 )
return V_95 ;
if ( V_74 -> clock < 20000 )
return V_96 ;
if ( V_74 -> V_60 & V_97 )
return V_98 ;
return V_99 ;
}
static bool F_39 ( struct V_2 * V_3 ,
struct V_54 * V_74 ,
struct V_54 * V_55 )
{
return true ;
}
static enum V_100
F_40 ( struct V_5 * V_6 , bool V_101 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_27 * V_28 = V_6 -> V_26 -> V_29 ;
struct V_102 * V_102 ;
enum V_100 V_103 = V_104 ;
V_1 -> V_52 = false ;
V_1 -> V_87 = false ;
V_102 = F_41 ( V_6 ,
F_42 ( V_28 ,
V_1 -> V_105 ) ) ;
if ( V_102 ) {
if ( V_102 -> V_106 & V_107 ) {
V_103 = V_108 ;
if ( V_1 -> V_109 != V_110 )
V_1 -> V_52 =
F_43 ( V_102 ) ;
V_1 -> V_87 = F_44 ( V_102 ) ;
}
V_6 -> V_111 . V_112 = NULL ;
F_45 ( V_102 ) ;
}
if ( V_103 == V_108 ) {
if ( V_1 -> V_109 != V_113 )
V_1 -> V_87 =
( V_1 -> V_109 == V_114 ) ;
}
return V_103 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_27 * V_28 = V_6 -> V_26 -> V_29 ;
return F_47 ( V_6 ,
F_42 ( V_28 ,
V_1 -> V_105 ) ) ;
}
static bool
F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_27 * V_28 = V_6 -> V_26 -> V_29 ;
struct V_102 * V_102 ;
bool V_87 = false ;
V_102 = F_41 ( V_6 ,
F_42 ( V_28 ,
V_1 -> V_105 ) ) ;
if ( V_102 ) {
if ( V_102 -> V_106 & V_107 )
V_87 = F_44 ( V_102 ) ;
V_6 -> V_111 . V_112 = NULL ;
F_45 ( V_102 ) ;
}
return V_87 ;
}
static int
F_49 ( struct V_5 * V_6 ,
struct V_115 * V_116 ,
T_4 V_30 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_27 * V_28 = V_6 -> V_26 -> V_29 ;
int V_117 ;
V_117 = F_50 ( V_6 , V_116 , V_30 ) ;
if ( V_117 )
return V_117 ;
if ( V_116 == V_28 -> V_118 ) {
enum V_119 V_11 = V_30 ;
bool V_87 ;
if ( V_11 == V_1 -> V_109 )
return 0 ;
V_1 -> V_109 = V_11 ;
if ( V_11 == V_113 )
V_87 = F_48 ( V_6 ) ;
else
V_87 = ( V_11 == V_114 ) ;
if ( V_11 == V_110 )
V_1 -> V_52 = 0 ;
V_1 -> V_87 = V_87 ;
goto V_120;
}
if ( V_116 == V_28 -> V_121 ) {
if ( V_30 == ! ! V_1 -> V_78 )
return 0 ;
V_1 -> V_78 = V_30 ? V_122 : 0 ;
goto V_120;
}
return - V_123 ;
V_120:
if ( V_1 -> V_4 . V_4 . V_44 ) {
struct V_124 * V_44 = V_1 -> V_4 . V_4 . V_44 ;
F_51 ( V_44 , & V_44 -> V_74 ,
V_44 -> V_125 , V_44 -> V_126 ,
V_44 -> V_127 ) ;
}
return 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_45 ( V_6 ) ;
}
static void
F_55 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_56 ( V_6 ) ;
F_57 ( V_6 ) ;
}
void F_58 ( struct V_25 * V_26 , int V_33 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_5 * V_6 ;
struct V_128 * V_128 ;
struct V_129 * V_129 ;
struct V_1 * V_1 ;
int V_11 ;
V_1 = F_59 ( sizeof( struct V_1 ) , V_130 ) ;
if ( ! V_1 )
return;
V_129 = F_59 ( sizeof( struct V_129 ) , V_130 ) ;
if ( ! V_129 ) {
F_45 ( V_1 ) ;
return;
}
V_128 = & V_1 -> V_4 ;
F_60 ( V_26 , & V_128 -> V_4 , & V_131 ,
V_132 ) ;
V_6 = & V_129 -> V_4 ;
F_61 ( V_26 , V_6 , & V_133 ,
V_134 ) ;
F_62 ( V_6 , & V_135 ) ;
V_128 -> type = V_136 ;
V_6 -> V_137 = V_138 ;
V_6 -> V_139 = 1 ;
V_6 -> V_140 = 0 ;
V_128 -> V_141 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( V_33 == V_34 ) {
V_128 -> V_142 = ( 1 << V_143 ) ;
V_1 -> V_105 = V_144 ;
V_28 -> V_145 |= V_146 ;
} else if ( V_33 == V_36 ) {
V_128 -> V_142 = ( 1 << V_147 ) ;
V_1 -> V_105 = V_148 ;
V_28 -> V_145 |= V_149 ;
} else if ( V_33 == V_46 ) {
V_128 -> V_142 = ( 1 << V_150 ) ;
V_1 -> V_105 = V_144 ;
V_28 -> V_145 |= V_146 ;
} else if ( V_33 == V_47 ) {
V_128 -> V_142 = ( 1 << V_151 ) ;
V_1 -> V_105 = V_148 ;
V_28 -> V_145 |= V_149 ;
} else if ( V_33 == V_48 ) {
V_128 -> V_142 = ( 1 << V_152 ) ;
V_1 -> V_105 = V_153 ;
V_28 -> V_145 |= V_154 ;
} else if ( V_33 == F_63 ( V_155 ) ) {
F_7 ( L_5 ) ;
V_128 -> V_142 = ( 1 << V_143 ) ;
V_1 -> V_105 = V_144 ;
V_1 -> V_156 = V_155 ;
V_28 -> V_145 |= V_146 ;
} else if ( V_33 == F_63 ( V_157 ) ) {
F_7 ( L_6 ) ;
V_128 -> V_142 = ( 1 << V_147 ) ;
V_1 -> V_105 = V_148 ;
V_1 -> V_156 = V_157 ;
V_28 -> V_145 |= V_149 ;
} else if ( V_33 == F_63 ( V_158 ) ) {
F_7 ( L_7 ) ;
V_128 -> V_142 = ( 1 << V_150 ) ;
V_1 -> V_105 = V_153 ;
V_1 -> V_156 = V_158 ;
V_28 -> V_145 |= V_154 ;
} else {
F_64 () ;
}
V_1 -> V_33 = V_33 ;
if ( ! F_31 ( V_26 ) ) {
V_1 -> V_53 = F_13 ;
F_15 ( V_31 , 0 ) ;
} else if ( F_65 ( V_26 ) ) {
V_1 -> V_53 = F_22 ;
F_66 (i)
F_15 ( F_23 ( V_11 ) , 0 ) ;
} else if ( F_67 ( V_26 ) ) {
V_1 -> V_53 = F_25 ;
F_66 (i)
F_15 ( F_26 ( V_11 ) , 0 ) ;
} else if ( F_68 ( V_26 ) ) {
V_1 -> V_53 = F_16 ;
F_66 (i)
F_15 ( F_18 ( V_11 ) , 0 ) ;
} else {
V_1 -> V_53 = F_21 ;
F_66 (i)
F_15 ( F_18 ( V_11 ) , 0 ) ;
}
if ( F_67 ( V_26 ) )
F_69 ( & V_128 -> V_4 , & V_159 ) ;
else
F_69 ( & V_128 -> V_4 , & V_160 ) ;
F_55 ( V_1 , V_6 ) ;
F_70 ( V_129 , V_128 ) ;
F_71 ( V_6 ) ;
if ( F_72 ( V_26 ) && ! F_73 ( V_26 ) ) {
T_2 V_91 = F_14 ( V_161 ) ;
F_15 ( V_161 , ( V_91 & ~ 0xf ) | 0xd ) ;
}
}
