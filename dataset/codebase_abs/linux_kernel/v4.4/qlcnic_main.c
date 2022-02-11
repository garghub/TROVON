static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 -> V_6 == V_7 )
return V_4 -> V_8 & V_9 ;
else
return 1 ;
}
inline void F_2 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_12 , V_11 -> V_13 ) ;
}
int F_4 ( struct V_14 * V_15 , int V_16 )
{
int V_17 = sizeof( struct V_18 ) * V_16 ;
V_15 -> V_19 = F_5 ( V_17 , V_20 ) ;
return V_15 -> V_19 == NULL ;
}
void F_6 ( struct V_14 * V_15 )
{
F_7 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
T_2 V_24 [ V_25 ] ;
int V_26 ;
V_26 = F_9 ( V_2 , V_24 ,
V_2 -> V_4 -> V_27 ) ;
if ( V_26 )
return V_26 ;
memcpy ( V_22 -> V_28 , V_24 , V_25 ) ;
memcpy ( V_2 -> V_24 , V_22 -> V_28 , V_22 -> V_29 ) ;
if ( ! F_10 ( V_22 -> V_28 ) )
F_11 ( & V_5 -> V_30 , L_1 ,
V_22 -> V_28 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
F_13 (head, &adapter->mac_list) {
V_32 = F_14 ( V_34 , struct V_31 , V_35 ) ;
if ( F_15 ( V_2 -> V_24 , V_32 -> V_24 ) ) {
F_16 ( V_2 , V_32 -> V_24 ,
0 , V_36 ) ;
F_17 ( & V_32 -> V_35 ) ;
F_7 ( V_32 ) ;
return;
}
}
}
static int F_18 ( struct V_21 * V_22 , void * V_37 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_38 * V_39 = V_37 ;
if ( F_20 ( V_2 ) )
return - V_40 ;
if ( ( V_2 -> V_41 & V_42 ) )
return - V_43 ;
if ( ! F_10 ( V_39 -> V_44 ) )
return - V_40 ;
if ( F_15 ( V_2 -> V_24 , V_39 -> V_44 ) &&
F_15 ( V_22 -> V_28 , V_39 -> V_44 ) )
return 0 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) ) {
F_22 ( V_22 ) ;
F_23 ( V_2 ) ;
}
F_12 ( V_2 ) ;
memcpy ( V_2 -> V_24 , V_39 -> V_44 , V_22 -> V_29 ) ;
memcpy ( V_22 -> V_28 , V_39 -> V_44 , V_22 -> V_29 ) ;
F_24 ( V_2 -> V_22 ) ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) ) {
F_25 ( V_22 ) ;
F_26 ( V_2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 ,
const unsigned char * V_39 , T_3 V_51 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 = - V_43 ;
if ( ! V_2 -> V_53 )
return F_28 ( V_48 , V_50 , V_22 , V_39 , V_51 ) ;
if ( ( V_2 -> V_41 & V_54 ) ||
F_29 ( V_2 ) ) {
if ( F_30 ( V_39 ) ) {
V_52 = F_31 ( V_22 , V_39 ) ;
if ( ! V_52 )
V_52 = F_32 ( V_2 , V_39 ) ;
} else if ( F_33 ( V_39 ) ) {
V_52 = F_34 ( V_22 , V_39 ) ;
} else {
V_52 = - V_40 ;
}
}
return V_52 ;
}
static int F_35 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 ,
const unsigned char * V_39 , T_3 V_51 , T_3 V_41 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 = 0 ;
if ( ! V_2 -> V_53 )
return F_36 ( V_48 , V_50 , V_22 , V_39 , V_51 , V_41 ) ;
if ( ! ( V_2 -> V_41 & V_54 ) &&
! F_29 ( V_2 ) ) {
F_37 ( L_2 , V_55 ) ;
return - V_43 ;
}
if ( F_38 ( V_39 , V_2 -> V_24 ) )
return V_52 ;
if ( F_30 ( V_39 ) ) {
if ( F_39 ( V_22 ) < V_2 -> V_4 -> V_56 )
V_52 = F_40 ( V_22 , V_39 ) ;
else
V_52 = - V_57 ;
} else if ( F_33 ( V_39 ) ) {
V_52 = F_41 ( V_22 , V_39 ) ;
} else {
V_52 = - V_40 ;
}
return V_52 ;
}
static int F_42 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_21 * V_22 ,
struct V_21 * V_62 , int V_63 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( ! V_2 -> V_53 )
return F_43 ( V_59 , V_61 , V_22 , V_62 , V_63 ) ;
if ( ( V_2 -> V_41 & V_54 ) ||
F_29 ( V_2 ) )
V_63 = F_43 ( V_59 , V_61 , V_22 , V_62 , V_63 ) ;
return V_63 ;
}
static void F_44 ( struct V_1 * V_2 )
{
while ( F_45 ( V_64 , & V_2 -> V_46 ) )
F_46 ( 10000 , 11000 ) ;
if ( ! V_2 -> V_65 . V_66 . V_67 )
return;
F_47 ( & V_2 -> V_65 ) ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! ( V_2 -> V_41 & V_70 ) )
return - V_43 ;
V_69 -> V_71 = sizeof( V_4 -> V_72 ) ;
memcpy ( V_69 -> V_73 , V_4 -> V_72 , V_69 -> V_71 ) ;
return 0 ;
}
static void F_49 ( struct V_21 * V_22 ,
T_4 V_74 , T_5 V_75 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) )
return;
if ( ! V_4 -> V_76 ) {
V_4 -> V_76 = 1 ;
V_4 -> V_77 = F_51 ( V_75 ) ;
V_2 -> V_41 |= V_78 ;
return;
}
if ( V_4 -> V_77 == F_51 ( V_75 ) )
V_4 -> V_76 ++ ;
}
static void F_52 ( struct V_21 * V_22 ,
T_4 V_74 , T_5 V_75 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || ! V_4 -> V_76 ||
( V_4 -> V_77 != F_51 ( V_75 ) ) )
return;
V_4 -> V_76 -- ;
if ( ! V_4 -> V_76 )
V_2 -> V_41 |= V_79 ;
}
static T_6 F_53 ( struct V_58 * V_59 ,
struct V_21 * V_30 ,
T_6 V_80 )
{
V_80 = F_54 ( V_59 , V_80 ) ;
return F_55 ( V_59 , V_80 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_57 ( V_2 ) &&
( V_4 -> V_81 [ 0 ] & V_82 ) ) {
F_45 ( V_83 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_58 ( struct V_1 * V_2 , T_2 V_84 ,
int V_85 )
{
int V_86 , V_87 = V_88 ;
if ( V_85 == V_89 )
V_87 = V_2 -> V_90 ;
else if ( V_85 == V_91 )
V_87 = V_2 -> V_92 ;
V_86 = F_59 ( F_60 ( int , F_61 () ,
V_87 ) ) ;
if ( V_84 > V_86 )
return V_86 ;
else
return V_84 ;
}
void F_62 ( struct V_1 * V_2 , T_2 V_93 )
{
if ( V_2 -> V_92 )
V_2 -> V_94 = F_58 ( V_2 , V_93 ,
V_91 ) ;
else
V_2 -> V_94 = V_93 ;
}
void F_63 ( struct V_1 * V_2 , T_2 V_95 )
{
if ( V_2 -> V_90 )
V_2 -> V_96 = F_58 ( V_2 , V_95 ,
V_89 ) ;
else
V_2 -> V_96 = V_95 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_97 = 0 , V_52 = 0 , V_98 ;
V_2 -> V_41 &= ~ V_99 ;
if ( V_2 -> V_100 > 0 )
V_97 += V_2 -> V_100 ;
else
V_97 += V_2 -> V_94 ;
if ( V_2 -> V_101 > 0 )
V_97 += V_2 -> V_101 ;
else
V_97 += V_2 -> V_96 ;
if ( F_65 ( V_2 ) )
V_97 += 1 ;
if ( ! V_2 -> V_102 ) {
V_2 -> V_102 = F_66 ( V_97 ,
sizeof( struct V_103 ) ,
V_20 ) ;
if ( ! V_2 -> V_102 )
return - V_57 ;
}
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ )
V_2 -> V_102 [ V_98 ] . V_104 = V_98 ;
V_105:
V_52 = F_67 ( V_5 , V_2 -> V_102 , V_97 ) ;
if ( V_52 == - V_106 ) {
if ( ! V_2 -> V_100 && ! V_2 -> V_101 )
return V_52 ;
F_68 ( V_2 -> V_22 ,
L_3 ,
V_97 , V_52 ) ;
V_97 = V_2 -> V_94 + V_2 -> V_96 ;
V_2 -> V_100 = 0 ;
V_2 -> V_101 = 0 ;
if ( F_65 ( V_2 ) )
V_97 += 1 ;
F_68 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_94 , V_2 -> V_96 ,
V_97 ) ;
goto V_105;
} else if ( V_52 < 0 ) {
return V_52 ;
}
V_2 -> V_4 -> V_97 = V_97 ;
if ( V_2 -> V_100 > 0 )
V_2 -> V_94 = V_2 -> V_100 ;
if ( V_2 -> V_101 > 0 )
V_2 -> V_96 = V_2 -> V_101 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_97 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_52 , V_98 ;
if ( ! V_2 -> V_102 ) {
V_2 -> V_102 = F_66 ( V_97 ,
sizeof( struct V_103 ) ,
V_20 ) ;
if ( ! V_2 -> V_102 )
return - V_57 ;
}
V_2 -> V_41 &= ~ ( V_107 | V_108 ) ;
if ( V_2 -> V_4 -> V_109 ) {
V_110:
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ )
V_2 -> V_102 [ V_98 ] . V_104 = V_98 ;
V_52 = F_70 ( V_5 ,
V_2 -> V_102 , 1 , V_97 ) ;
if ( V_52 == V_97 ) {
V_2 -> V_41 |= V_108 ;
V_2 -> V_4 -> V_97 = V_97 ;
F_71 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_52 > 0 ) {
F_72 ( V_5 ) ;
F_71 ( & V_5 -> V_30 ,
L_3 ,
V_97 , V_52 ) ;
if ( F_57 ( V_2 ) ) {
V_97 = F_59 ( V_52 ) ;
if ( V_52 < V_111 )
return - V_106 ;
} else {
V_97 = F_59 ( V_52 - 1 ) ;
V_97 += 1 ;
if ( V_52 < V_112 )
return - V_106 ;
}
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) {
V_2 -> V_96 = V_97 ;
V_2 -> V_94 = V_113 ;
} else {
V_2 -> V_94 = V_97 / 2 ;
V_2 -> V_96 = V_2 -> V_94 ;
}
if ( V_97 ) {
F_71 ( & V_5 -> V_30 ,
L_6 ,
V_97 ) ;
goto V_110;
}
} else {
F_71 ( & V_5 -> V_30 ,
L_7 ,
V_97 , V_52 ) ;
return V_52 ;
}
}
return - V_114 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_97 ;
V_97 = V_2 -> V_96 ;
if ( F_73 ( V_2 ) )
V_97 += V_2 -> V_94 ;
else
V_97 += V_113 ;
return V_97 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
T_1 V_115 , V_116 ;
const struct V_117 * V_118 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_119 && ! F_76 ( V_5 ) ) {
V_2 -> V_41 |= V_107 ;
V_115 = V_120 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_121 = F_77 ( V_2 -> V_4 ,
V_115 ) ;
F_71 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_102 [ 0 ] . V_98 = V_5 -> V_122 ;
return V_52 ;
}
if ( V_119 || V_123 )
return - V_43 ;
V_118 = & V_124 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_125 = V_118 -> V_125 ;
V_115 = V_118 -> V_121 ;
V_2 -> V_121 = F_77 ( V_4 , V_115 ) ;
V_116 = V_118 -> V_126 ;
V_2 -> V_126 = F_77 ( V_4 , V_116 ) ;
V_2 -> V_127 = F_77 ( V_4 , V_128 ) ;
V_2 -> V_129 = F_77 ( V_4 , V_130 ) ;
F_71 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_102 [ 0 ] . V_98 = V_5 -> V_122 ;
return V_52 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_97 , V_52 = 0 ;
if ( V_2 -> V_41 & V_99 ) {
V_52 = F_64 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
V_97 = V_2 -> V_4 -> V_97 ;
} else {
V_97 = F_74 ( V_2 ) ;
V_52 = F_69 ( V_2 , V_97 ) ;
if ( V_52 == - V_57 )
return V_52 ;
if ( ! ( V_2 -> V_41 & V_108 ) ) {
F_79 ( V_2 ) ;
V_2 -> V_96 = V_113 ;
V_52 = F_75 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_131 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 , V_132 ;
if ( F_73 ( V_2 ) &&
! V_4 -> V_133 &&
( V_2 -> V_41 & V_108 ) ) {
V_4 -> V_134 = F_81 ( V_4 -> V_97 *
sizeof( struct V_135 ) ) ;
if ( ! V_4 -> V_134 )
return - V_57 ;
for ( V_132 = 0 ; V_132 < V_4 -> V_97 ; V_132 ++ ) {
V_4 -> V_134 [ V_132 ] . type = V_136 ;
V_4 -> V_134 [ V_132 ] . V_73 = V_132 ;
V_4 -> V_134 [ V_132 ] . V_137 = 0 ;
}
V_52 = F_82 ( V_2 , 1 ) ;
if ( V_52 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_97 ) ;
return V_52 ;
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_108 )
F_72 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_107 )
F_85 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
if ( V_2 -> V_4 -> V_134 ) {
F_86 ( V_2 -> V_4 -> V_134 ) ;
V_2 -> V_4 -> V_134 = NULL ;
}
}
static void F_87 ( struct V_3 * V_4 )
{
if ( V_4 -> V_138 != NULL )
F_88 ( V_4 -> V_138 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_139 * V_140 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_54 ) ) {
switch ( V_4 -> V_141 ) {
case V_142 :
V_4 -> V_143 = V_144 ;
break;
case V_145 :
V_4 -> V_143 = V_146 ;
break;
}
return 0 ;
}
if ( V_4 -> V_147 == V_148 )
return 0 ;
V_140 = F_66 ( V_4 -> V_149 , sizeof( * V_140 ) , V_20 ) ;
if ( ! V_140 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_140 ) ;
F_7 ( V_140 ) ;
return V_26 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_92 ( V_2 ) ) {
V_26 = true ;
} else if ( F_65 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_81 [ 0 ] &
V_150 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_139 * V_140 ;
int V_132 , V_73 = 0 , V_26 = 0 , V_151 = 0 ;
T_3 V_152 ;
T_2 V_153 ;
V_140 = F_66 ( V_4 -> V_149 , sizeof( * V_140 ) , V_20 ) ;
if ( ! V_140 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_140 ) ;
if ( V_26 )
goto V_154;
V_152 = V_4 -> V_143 ;
V_2 -> V_155 = F_5 ( sizeof( struct V_156 ) *
V_152 , V_20 ) ;
if ( ! V_2 -> V_155 ) {
V_26 = - V_57 ;
goto V_154;
}
V_2 -> V_157 = F_5 ( sizeof( struct V_158 ) *
V_146 , V_20 ) ;
if ( ! V_2 -> V_157 ) {
V_26 = - V_57 ;
goto V_159;
}
for ( V_132 = 0 ; V_132 < V_4 -> V_149 ; V_132 ++ ) {
V_153 = V_140 [ V_132 ] . V_73 ;
if ( V_153 >= V_4 -> V_149 ) {
V_26 = - V_40 ;
F_83 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_55 , V_153 , V_4 -> V_149 ) ;
goto V_160;
}
if ( ! V_140 [ V_132 ] . V_161 ||
( V_140 [ V_132 ] . type != V_162 ) )
continue;
if ( F_91 ( V_2 ) ) {
if ( ! F_94 ( V_2 , V_153 ,
& V_73 ) )
V_2 -> V_155 [ V_151 ] . V_163 = true ;
else
continue;
} else {
V_2 -> V_155 [ V_151 ] . V_163 = true ;
}
V_2 -> V_155 [ V_151 ] . V_27 = V_153 ;
V_2 -> V_155 [ V_151 ] . V_161 = ( T_2 ) V_140 [ V_132 ] . V_161 ;
V_2 -> V_155 [ V_151 ] . type = ( T_2 ) V_140 [ V_132 ] . type ;
V_2 -> V_155 [ V_151 ] . V_164 = ( T_2 ) V_140 [ V_132 ] . V_165 ;
V_2 -> V_155 [ V_151 ] . V_166 = V_140 [ V_132 ] . V_167 ;
V_2 -> V_155 [ V_151 ] . V_168 = V_140 [ V_132 ] . V_169 ;
memcpy ( & V_2 -> V_155 [ V_151 ] . V_170 , & V_140 [ V_132 ] . V_170 , V_25 ) ;
V_151 ++ ;
}
if ( ! F_91 ( V_2 ) ) {
for ( V_132 = 0 ; V_132 < V_146 ; V_132 ++ )
V_2 -> V_157 [ V_132 ] . V_41 |= V_171 ;
}
F_7 ( V_140 ) ;
return 0 ;
V_160:
F_7 ( V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
V_159:
F_7 ( V_2 -> V_155 ) ;
V_2 -> V_155 = NULL ;
V_154:
F_7 ( V_140 ) ;
return V_26 ;
}
static int
F_95 ( struct V_1 * V_2 )
{
T_2 V_73 ;
int V_26 ;
T_1 V_172 = V_148 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_96 ( V_2 ) ;
if ( V_26 )
goto V_173;
V_73 = V_4 -> V_27 ;
V_172 = F_97 ( V_2 , V_174 ) ;
V_172 = ( V_172 & ~ F_98 ( 0xf , V_73 ) ) |
F_98 ( V_148 , V_73 ) ;
F_99 ( V_2 , V_174 , V_172 ) ;
F_100 ( V_2 ) ;
V_173:
return V_26 ;
}
static void F_101 ( struct V_1 * V_2 ,
const struct V_175 * V_176 )
{
T_1 V_147 , V_177 ;
V_2 -> V_4 -> V_178 = F_97 ( V_2 ,
V_179 ) ;
F_102 ( V_2 ) ;
V_147 = F_97 ( V_2 , V_174 ) ;
if ( V_147 == V_180 )
V_177 = V_148 ;
else
V_177 = F_103 ( V_147 , V_2 -> V_4 -> V_27 ) ;
if ( V_177 == V_181 ) {
V_2 -> V_4 -> V_147 = V_181 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_178 ) ;
V_2 -> V_182 = & V_183 ;
} else
V_2 -> V_182 = & V_184 ;
}
static void F_104 ( T_1 V_185 , T_7 * V_186 )
{
switch ( V_185 ) {
case V_7 :
* V_186 = V_187 ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
* V_186 = V_194 ;
break;
default:
* V_186 = 0 ;
}
}
static int F_105 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_115 ;
void T_8 * V_195 = NULL ;
unsigned long V_196 , V_197 = 0 , V_198 ;
V_196 = F_106 ( V_5 , 0 ) ;
F_104 ( V_5 -> V_6 , & V_198 ) ;
if ( V_196 >= V_198 ) {
V_195 = F_107 ( V_5 , 0 ) ;
if ( V_195 == NULL ) {
F_83 ( & V_5 -> V_30 , L_13 ) ;
return - V_114 ;
}
V_197 = V_196 ;
} else {
return - V_114 ;
}
F_71 ( & V_5 -> V_30 , L_14 , ( int ) ( V_196 >> 10 ) ) ;
V_4 -> V_138 = V_195 ;
V_4 -> V_197 = V_197 ;
V_115 = F_108 ( F_109 ( V_4 -> V_27 ) ) ;
F_77 ( V_4 , V_115 ) ;
return 0 ;
}
static bool F_110 ( struct V_1 * V_2 ,
int V_199 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_200 ;
bool V_26 = true ;
V_200 = V_5 -> V_200 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_188 ) {
if ( V_201 [ V_199 ] . V_202 == V_200 &&
V_201 [ V_199 ] . V_203 == V_5 -> V_204 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_111 ( struct V_1 * V_2 , char * V_205 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_132 , V_206 = 0 ;
for ( V_132 = 0 ; V_132 < V_207 ; ++ V_132 ) {
if ( V_201 [ V_132 ] . V_208 == V_5 -> V_208 &&
V_201 [ V_132 ] . V_6 == V_5 -> V_6 &&
F_110 ( V_2 , V_132 ) ) {
V_206 = 1 ;
break;
}
}
if ( ! V_206 )
sprintf ( V_205 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_205 , L_16 , V_2 -> V_24 ,
V_201 [ V_132 ] . V_209 ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
int V_52 ;
T_1 V_210 , V_211 , V_212 , V_213 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_214 * V_215 = & V_4 -> V_215 ;
V_213 = V_2 -> V_216 ;
V_210 = F_97 ( V_2 , V_217 ) ;
V_211 = F_97 ( V_2 , V_218 ) ;
V_212 = F_97 ( V_2 , V_219 ) ;
V_2 -> V_216 = F_113 ( V_210 , V_211 , V_212 ) ;
V_52 = F_114 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_147 != V_181 ) {
if ( V_215 -> V_220 == NULL ||
V_2 -> V_216 > V_213 ) {
F_86 ( V_215 -> V_220 ) ;
if ( ! F_115 ( V_2 ) )
F_71 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_71 ( & V_5 -> V_30 , L_19 ,
V_221 , V_210 , V_211 , V_212 ) ;
if ( V_2 -> V_4 -> V_141 == V_145 ) {
if ( V_2 -> V_41 & V_54 ) {
V_2 -> V_222 = V_223 ;
V_2 -> V_224 = V_225 ;
} else {
V_2 -> V_222 = V_226 ;
V_2 -> V_224 = V_227 ;
}
V_2 -> V_228 = V_229 ;
V_2 -> V_230 = V_229 ;
} else if ( V_2 -> V_4 -> V_141 == V_142 ) {
V_2 -> V_222 = V_231 ;
V_2 -> V_228 = V_232 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_224 = V_233 ;
}
V_2 -> V_4 -> V_109 = ! ! V_123 ;
V_2 -> V_234 = V_235 ;
V_2 -> V_236 = V_237 ;
}
static int
F_116 ( struct V_1 * V_2 )
{
struct V_238 V_239 ;
int V_52 = 0 ;
memset ( & V_239 , 0 , sizeof( struct V_238 ) ) ;
V_52 = F_117 ( V_2 , & V_239 , V_2 -> V_4 -> V_27 ) ;
if ( V_52 )
return V_52 ;
V_2 -> V_4 -> V_240 = ( T_2 ) V_239 . V_241 ;
V_2 -> V_4 -> V_242 = V_239 . V_242 ;
V_2 -> V_4 -> V_243 = V_239 . V_243 ;
V_2 -> V_4 -> V_244 = V_239 . V_244 ;
V_2 -> V_4 -> V_8 = V_239 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_245 ) {
T_1 V_246 ;
V_246 = F_118 ( V_2 , V_247 , & V_52 ) ;
if ( V_52 == - V_114 )
return V_52 ;
V_2 -> V_4 -> V_81 [ 0 ] = V_246 ;
} else {
V_2 -> V_4 -> V_81 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_248 = V_239 . V_248 ;
V_2 -> V_4 -> V_249 = V_239 . V_249 ;
if ( V_2 -> V_4 -> V_8 & V_250 ) {
V_2 -> V_41 |= V_54 ;
V_2 -> V_4 -> V_251 = V_252 ;
V_2 -> V_92 = V_253 ;
V_2 -> V_90 = V_254 ;
F_71 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_251 = V_255 ;
V_2 -> V_92 = V_256 ;
V_2 -> V_90 = V_88 ;
V_2 -> V_41 &= ~ V_54 ;
}
return V_52 ;
}
void F_119 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
if ( V_258 -> V_259 )
V_2 -> V_41 &= ~ V_260 ;
else
V_2 -> V_41 |= V_260 ;
if ( V_258 -> V_261 ) {
V_2 -> V_262 = V_258 -> V_261 ;
V_2 -> V_263 = V_258 -> V_261 ;
} else {
V_2 -> V_262 = 0 ;
V_2 -> V_263 = 0 ;
}
}
static int
F_120 ( struct V_21 * V_22 , T_5 V_264 , T_3 V_51 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 ;
if ( F_20 ( V_2 ) ) {
V_52 = F_121 ( V_2 , V_51 , 1 ) ;
if ( V_52 ) {
F_122 ( V_22 ,
L_21 ,
V_51 , V_52 ) ;
return V_52 ;
}
}
F_123 ( V_51 , V_2 -> V_265 ) ;
return 0 ;
}
static int
F_124 ( struct V_21 * V_22 , T_5 V_264 , T_3 V_51 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 ;
if ( F_20 ( V_2 ) ) {
V_52 = F_121 ( V_2 , V_51 , 0 ) ;
if ( V_52 ) {
F_122 ( V_22 ,
L_22 ,
V_51 , V_52 ) ;
return V_52 ;
}
}
F_125 ( V_22 , V_266 ) ;
F_126 ( V_51 , V_2 -> V_265 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
V_2 -> V_41 &= ~ ( V_267 | V_42 |
V_268 ) ;
if ( V_258 -> V_269 )
V_2 -> V_41 |= V_267 ;
if ( ! V_258 -> V_270 )
V_2 -> V_41 |= V_42 ;
if ( ! V_258 -> V_271 )
V_2 -> V_41 |= V_268 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_257 V_258 ;
if ( ! ( V_2 -> V_41 & V_54 ) )
return 0 ;
V_258 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_129 ( V_2 , & V_258 ) )
return - V_114 ;
F_119 ( V_2 , & V_258 ) ;
F_127 ( V_2 , & V_258 ) ;
F_130 ( V_2 , & V_258 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_65 ( V_2 ) )
return;
V_2 -> V_272 = V_258 -> V_272 ;
V_2 -> V_41 |= V_273 ;
F_131 ( V_22 ) ;
V_2 -> V_41 &= ~ V_273 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_1 V_147 , V_177 ;
int V_52 = 0 ;
V_52 = F_116 ( V_2 ) ;
if ( V_52 )
return V_52 ;
if ( V_2 -> V_41 & V_274 )
return 0 ;
V_147 = F_97 ( V_2 , V_174 ) ;
V_177 = F_103 ( V_147 , V_2 -> V_4 -> V_27 ) ;
if ( V_147 == V_180 )
V_177 = V_148 ;
else
V_177 = F_103 ( V_147 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_54 ) {
if ( V_177 == V_148 ) {
V_2 -> V_4 -> V_147 = V_148 ;
V_52 = F_93 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_95 ( V_2 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_178 ) ;
} else if ( V_177 == V_275 ) {
V_2 -> V_4 -> V_147 = V_275 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_178 ) ;
}
} else {
V_2 -> V_4 -> V_251 = V_255 ;
}
V_2 -> V_41 |= V_274 ;
return V_52 ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_257 V_258 ;
struct V_156 * V_276 ;
T_2 V_132 ;
if ( V_2 -> V_277 )
return 0 ;
for ( V_132 = 0 ; V_132 < V_2 -> V_4 -> V_143 ; V_132 ++ ) {
if ( ! V_2 -> V_155 [ V_132 ] . V_163 )
continue;
memset ( & V_258 , 0 , sizeof( struct V_257 ) ) ;
V_258 . V_27 = V_2 -> V_155 [ V_132 ] . V_27 ;
V_258 . V_270 = V_278 ;
V_258 . V_271 = V_278 ;
if ( F_57 ( V_2 ) ) {
V_258 . V_272 = V_278 ;
if ( F_134 ( V_2 ) )
V_258 . V_272 |= ( V_279 | V_280 ) ;
}
if ( F_135 ( V_2 , & V_258 ) )
return - V_114 ;
V_276 = & V_2 -> V_155 [ V_132 ] ;
V_276 -> V_281 = V_258 . V_261 ;
V_276 -> V_270 = V_258 . V_270 ;
V_276 -> V_269 = V_258 . V_269 ;
V_276 -> V_259 = V_258 . V_259 ;
V_276 -> V_271 = V_258 . V_271 ;
V_276 -> V_272 = V_258 . V_272 ;
}
return 0 ;
}
static int
F_136 ( struct V_1 * V_2 ,
struct V_156 * V_276 , int V_27 )
{
struct V_257 V_258 ;
V_258 . V_147 = V_282 ;
V_258 . V_27 = V_27 ;
V_258 . V_261 = V_276 -> V_281 ;
V_258 . V_270 = V_276 -> V_270 ;
V_258 . V_259 = V_276 -> V_259 ;
V_258 . V_269 = V_276 -> V_269 ;
V_258 . V_272 = V_276 -> V_272 ;
V_258 . V_271 = V_276 -> V_271 ;
if ( F_135 ( V_2 , & V_258 ) )
return - V_114 ;
V_258 . V_147 = V_283 ;
if ( F_135 ( V_2 , & V_258 ) )
return - V_114 ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_132 , V_52 ;
struct V_156 * V_276 ;
struct V_238 V_239 ;
T_2 V_27 ;
if ( F_57 ( V_2 ) )
if ( ! V_2 -> V_277 )
return 0 ;
for ( V_132 = 0 ; V_132 < V_2 -> V_4 -> V_143 ; V_132 ++ ) {
V_276 = & V_2 -> V_155 [ V_132 ] ;
V_27 = V_276 -> V_27 ;
if ( ! V_2 -> V_155 [ V_132 ] . V_163 )
continue;
memset ( & V_239 , 0 , sizeof( struct V_238 ) ) ;
V_52 = F_117 ( V_2 , & V_239 , V_27 ) ;
if ( V_52 )
return V_52 ;
V_239 . V_284 = V_276 -> V_166 ;
V_239 . V_285 = V_276 -> V_168 ;
V_52 = F_138 ( V_2 , & V_239 ) ;
if ( V_52 )
return V_52 ;
if ( V_276 -> V_286 ) {
V_52 = F_139 ( V_2 ,
V_276 -> V_287 , 1 ,
V_27 ) ;
if ( V_52 )
return V_52 ;
}
V_52 = F_136 ( V_2 , V_276 , V_27 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
T_2 V_288 = V_289 ;
T_1 V_290 ;
if ( V_2 -> V_4 -> V_147 == V_148 )
return 0 ;
V_290 = F_97 ( V_2 ,
V_291 ) ;
while ( V_290 != V_292 && -- V_288 ) {
F_141 ( 1000 ) ;
V_290 = F_97 ( V_2 ,
V_291 ) ;
}
if ( ! V_288 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_114 ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
int V_52 ;
if ( ! ( V_2 -> V_41 & V_54 ) ||
V_2 -> V_4 -> V_147 != V_148 )
return 0 ;
V_52 = F_133 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_137 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_143 ( V_2 ) ;
return V_52 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_145 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
else if ( ! V_52 )
goto V_293;
if ( V_294 )
F_146 ( V_2 ) ;
else {
V_52 = F_147 ( V_2 ) ;
if ( V_52 )
goto V_295;
V_2 -> V_4 -> V_296 = V_297 ;
}
V_52 = F_148 ( V_2 ) ;
if ( V_52 == 0 )
goto V_293;
V_52 = F_149 ( V_2 ) ;
if ( V_52 )
goto V_295;
V_52 = F_150 ( V_2 ) ;
if ( V_52 )
goto V_295;
F_151 ( V_2 ) ;
F_152 ( V_2 , V_298 , V_299 ) ;
V_293:
V_52 = F_153 ( V_2 ) ;
if ( V_52 )
goto V_295;
F_99 ( V_2 , V_300 , V_301 ) ;
F_154 ( V_2 , 1 ) ;
V_52 = F_132 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_295;
}
V_52 = F_142 ( V_2 ) ;
if ( V_52 )
goto V_295;
F_112 ( V_2 ) ;
V_2 -> V_277 = 0 ;
F_151 ( V_2 ) ;
return 0 ;
V_295:
F_99 ( V_2 , V_300 , V_302 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_151 ( V_2 ) ;
return V_52 ;
}
static int
F_155 ( struct V_1 * V_2 )
{
T_9 V_303 ;
struct V_18 * V_304 ;
struct V_10 * V_11 ;
int V_52 , V_305 , V_306 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_133 == V_307 ) {
if ( F_57 ( V_2 ) )
V_303 = V_308 ;
else
V_303 = V_309 ;
if ( ! F_156 ( V_2 ) )
V_41 |= V_310 ;
} else {
if ( V_2 -> V_41 & V_108 )
V_303 = V_311 ;
else if ( V_2 -> V_41 & V_107 )
V_303 = V_312 ;
else {
V_41 |= V_310 ;
if ( F_57 ( V_2 ) )
V_303 = V_313 ;
else
V_303 = V_314 ;
}
}
V_2 -> V_122 = V_22 -> V_122 ;
if ( V_2 -> V_4 -> V_133 != V_315 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_108 ) ) ) {
V_306 = V_2 -> V_96 ;
for ( V_305 = 0 ; V_305 < V_306 ; V_305 ++ ) {
V_304 = & V_15 -> V_19 [ V_305 ] ;
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) &&
( V_305 == ( V_306 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_108 ) )
snprintf ( V_304 -> V_205 ,
sizeof( V_304 -> V_205 ) ,
L_28 ) ;
else
snprintf ( V_304 -> V_205 ,
sizeof( V_304 -> V_205 ) ,
L_29 ,
V_22 -> V_205 , V_305 ) ;
} else {
snprintf ( V_304 -> V_205 ,
sizeof( V_304 -> V_205 ) ,
L_30 ,
V_22 -> V_205 , V_305 ) ;
}
V_52 = F_157 ( V_304 -> V_122 , V_303 , V_41 ,
V_304 -> V_205 , V_304 ) ;
if ( V_52 )
return V_52 ;
}
}
if ( ( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_108 ) &&
! ( V_2 -> V_41 & V_316 ) ) ) {
V_303 = V_317 ;
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ;
V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
snprintf ( V_11 -> V_205 , sizeof( V_11 -> V_205 ) ,
L_31 , V_22 -> V_205 , V_305 ) ;
V_52 = F_157 ( V_11 -> V_122 , V_303 , V_41 ,
V_11 -> V_205 , V_11 ) ;
if ( V_52 )
return V_52 ;
}
}
}
return 0 ;
}
static void
F_158 ( struct V_1 * V_2 )
{
int V_305 ;
struct V_18 * V_304 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_133 != V_315 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_108 ) ) ) {
for ( V_305 = 0 ; V_305 < V_2 -> V_96 ; V_305 ++ ) {
V_304 = & V_15 -> V_19 [ V_305 ] ;
F_159 ( V_304 -> V_122 , V_304 ) ;
}
}
if ( ( F_65 ( V_2 ) &&
! ( V_2 -> V_41 & V_316 ) ) ||
( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ) {
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ;
V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
if ( V_11 -> V_122 )
F_159 ( V_11 -> V_122 , V_11 ) ;
}
}
}
}
static void F_160 ( struct V_1 * V_2 )
{
T_1 V_318 = 0 ;
if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_81 [ 0 ] &
V_319 )
V_2 -> V_41 |= V_320 ;
} else {
V_318 = V_2 -> V_4 -> V_8 ;
if ( F_161 ( V_318 ) )
V_2 -> V_41 |= V_320 ;
}
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 ;
V_4 -> V_321 . V_322 = V_323 ;
if ( F_65 ( V_2 ) ) {
V_4 -> V_321 . type = V_324 ;
V_4 -> V_321 . V_325 = V_326 ;
V_4 -> V_321 . V_327 = V_328 ;
V_4 -> V_321 . V_329 = V_330 ;
V_4 -> V_321 . V_331 = V_332 ;
V_52 = F_163 ( V_2 ) ;
} else {
V_4 -> V_321 . type = V_333 ;
V_4 -> V_321 . V_329 = V_330 ;
V_4 -> V_321 . V_331 = V_332 ;
V_52 = F_164 ( V_2 ) ;
}
return V_52 ;
}
int F_165 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_305 ;
struct V_334 * V_335 ;
if ( V_2 -> V_336 != V_337 )
return - V_114 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_128 ( V_2 ) )
return - V_114 ;
F_160 ( V_2 ) ;
if ( F_166 ( V_2 ) )
return - V_114 ;
for ( V_305 = 0 ; V_305 < V_2 -> V_236 ; V_305 ++ ) {
V_335 = & V_2 -> V_15 -> V_338 [ V_305 ] ;
F_167 ( V_2 , V_335 , V_305 ) ;
}
F_24 ( V_22 ) ;
F_168 ( V_2 , V_22 -> V_339 ) ;
V_2 -> V_4 -> V_340 = 0 ;
if ( V_2 -> V_96 > 1 )
F_169 ( V_2 , 1 ) ;
F_162 ( V_2 ) ;
if ( V_22 -> V_80 & V_341 )
F_170 ( V_2 , V_342 ) ;
F_123 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_171 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_343 = 0 ;
F_172 ( V_22 ) ;
return 0 ;
}
int F_173 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_52 = 0 ;
F_174 () ;
if ( F_175 ( V_22 ) )
V_52 = F_165 ( V_2 , V_22 ) ;
F_176 () ;
return V_52 ;
}
void F_177 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_305 ;
if ( V_2 -> V_336 != V_337 )
return;
if ( ! F_178 ( V_45 , & V_2 -> V_46 ) )
return;
F_179 () ;
F_180 ( V_22 ) ;
V_2 -> V_4 -> V_340 = 0 ;
F_181 ( V_22 ) ;
F_182 ( V_2 ) ;
if ( V_2 -> V_344 . V_345 )
F_183 ( V_2 ) ;
F_184 ( V_2 , V_346 ) ;
if ( F_20 ( V_2 ) )
F_185 ( & V_2 -> V_4 -> V_347 -> V_348 ) ;
F_23 ( V_2 ) ;
F_186 ( V_2 ) ;
V_2 -> V_41 &= ~ V_320 ;
F_187 ( V_2 ) ;
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ )
F_188 ( V_2 , & V_2 -> V_11 [ V_305 ] ) ;
}
void F_189 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_174 () ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_176 () ;
}
int
F_190 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_52 ;
if ( V_2 -> V_336 == V_337 )
return 0 ;
V_52 = F_191 ( V_2 , V_22 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_192 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_32 ) ;
goto V_349;
}
V_52 = F_193 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_33 ) ;
goto V_350;
}
V_52 = F_155 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_34 ) ;
goto V_351;
}
F_194 ( V_2 ) ;
#ifdef F_195
if ( F_50 ( V_2 ) )
F_196 ( V_22 ) ;
#endif
V_2 -> V_336 = V_337 ;
return 0 ;
V_351:
F_197 ( V_2 ) ;
V_350:
F_198 ( V_2 ) ;
V_349:
F_199 ( V_2 ) ;
return V_52 ;
}
void F_200 ( struct V_1 * V_2 )
{
if ( V_2 -> V_336 != V_337 )
return;
F_201 ( V_2 ) ;
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
F_158 ( V_2 ) ;
F_199 ( V_2 ) ;
F_198 ( V_2 ) ;
V_2 -> V_336 = 0 ;
}
void F_203 ( struct V_21 * V_22 , int V_96 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_304 ;
int V_94 = V_2 -> V_94 ;
int V_305 ;
F_126 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_133 == V_307 ) {
for ( V_305 = 0 ; V_305 < V_2 -> V_96 ; V_305 ++ ) {
V_304 = & V_2 -> V_15 -> V_19 [ V_305 ] ;
F_204 ( V_2 , V_304 ) ;
}
}
F_186 ( V_2 ) ;
F_200 ( V_2 ) ;
V_2 -> V_4 -> V_133 = 0 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_94 = V_94 ;
if ( F_190 ( V_2 ) )
goto V_352;
if ( F_175 ( V_22 ) )
F_165 ( V_2 , V_22 ) ;
V_352:
F_25 ( V_22 ) ;
}
static int F_205 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_52 = - V_57 ;
goto V_295;
}
if ( F_65 ( V_2 ) ) {
V_4 -> V_321 . type = V_324 ;
V_4 -> V_321 . V_325 = V_326 ;
V_4 -> V_321 . V_327 = V_328 ;
V_4 -> V_321 . V_329 = V_330 ;
V_4 -> V_321 . V_331 = V_332 ;
} else {
V_4 -> V_321 . type = V_333 ;
V_4 -> V_321 . V_329 = V_330 ;
V_4 -> V_321 . V_331 = V_332 ;
}
memset ( & V_2 -> V_353 , 0 , sizeof( V_2 -> V_353 ) ) ;
V_295:
return V_52 ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_214 * V_215 = & V_2 -> V_4 -> V_215 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_215 -> V_220 ) {
F_86 ( V_215 -> V_220 ) ;
V_215 -> V_220 = NULL ;
}
if ( V_215 -> V_354 ) {
F_207 ( & V_2 -> V_5 -> V_30 , V_355 ,
V_215 -> V_354 , V_215 -> V_356 ) ;
V_215 -> V_354 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_357 . V_358 ) ;
V_2 -> V_4 -> V_215 . V_220 = NULL ;
}
int F_208 ( struct V_21 * V_22 , int V_359 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_304 ;
struct V_334 * V_335 ;
int V_305 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
V_2 -> V_96 = V_113 ;
V_2 -> V_4 -> V_133 = V_359 ;
V_2 -> V_4 -> V_340 = 0 ;
V_26 = F_190 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_166 ( V_2 ) ;
if ( V_26 ) {
F_200 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_305 = 0 ; V_305 < V_2 -> V_236 ; V_305 ++ ) {
V_335 = & V_2 -> V_15 -> V_338 [ V_305 ] ;
F_167 ( V_2 , V_335 , V_305 ) ;
}
if ( V_2 -> V_4 -> V_133 == V_307 ) {
for ( V_305 = 0 ; V_305 < V_2 -> V_96 ; V_305 ++ ) {
V_304 = & V_2 -> V_15 -> V_19 [ V_305 ] ;
F_209 ( V_2 , V_304 ) ;
}
}
if ( V_2 -> V_4 -> V_133 == V_315 ) {
V_2 -> V_4 -> V_360 = 0 ;
F_171 ( V_2 , 1 ) ;
}
F_123 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_210 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_64 , & V_2 -> V_46 ) )
return - V_361 ;
F_22 ( V_22 ) ;
F_189 ( V_2 , V_22 ) ;
F_173 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_68 ( V_2 -> V_22 , L_35 , V_55 ) ;
return 0 ;
}
int
F_211 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_64 , & V_2 -> V_46 ) )
return - V_361 ;
if ( V_2 -> V_336 == V_337 ) {
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( ! V_52 ) {
F_165 ( V_2 , V_22 ) ;
F_125 ( V_22 , V_362 ) ;
}
}
F_25 ( V_22 ) ;
}
F_126 ( V_64 , & V_2 -> V_46 ) ;
return V_52 ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_363 = V_4 -> V_143 ;
T_3 V_16 ;
V_4 -> V_364 = V_365 ;
if ( V_363 <= 2 )
V_16 = ( V_366 - V_365 ) /
V_363 ;
else
V_16 = ( V_367 - V_365 ) /
V_363 ;
V_4 -> V_56 = V_16 ;
}
static int F_213 ( struct V_1 * V_2 ,
T_2 V_368 , T_2 V_369 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_52 = 0 ;
if ( V_368 ) {
V_52 = F_214 ( V_22 , V_368 ) ;
if ( V_52 ) {
F_122 ( V_22 , L_36 ,
V_368 ) ;
return V_52 ;
}
}
if ( V_369 ) {
V_52 = F_215 ( V_22 , V_369 ) ;
if ( V_52 )
F_122 ( V_22 , L_37 ,
V_369 ) ;
}
return V_52 ;
}
int
F_216 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_370 )
{
int V_52 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_371 = 1 ;
V_2 -> V_4 -> V_372 = 0 ;
F_217 ( V_2 ) ;
V_22 -> V_373 = & V_374 ;
V_22 -> V_375 = V_376 * V_377 ;
F_218 ( V_22 , V_22 -> V_339 ) ;
V_22 -> V_378 = ( F_20 ( V_2 ) ) ?
& V_379 : & V_380 ;
V_22 -> V_80 |= ( V_381 | V_382 | V_383 |
V_384 | V_385 |
V_386 ) ;
V_22 -> V_387 |= ( V_381 | V_382 |
V_384 ) ;
if ( F_134 ( V_2 ) ) {
V_22 -> V_80 |= ( V_388 | V_389 ) ;
V_22 -> V_387 |= ( V_388 | V_389 ) ;
}
if ( V_370 ) {
V_22 -> V_80 |= V_390 ;
V_22 -> V_387 |= V_390 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_80 |= ( V_391 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_80 |= V_392 ;
if ( V_2 -> V_4 -> V_8 & V_393 )
V_22 -> V_80 |= V_341 ;
if ( F_219 ( V_2 ) ) {
V_22 -> V_80 |= V_394 ;
V_22 -> V_395 = V_382 |
V_394 |
V_388 |
V_389 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_395 |= V_383 ;
V_22 -> V_396 = V_22 -> V_80 ;
V_22 -> V_397 |= V_398 ;
V_22 -> V_122 = V_2 -> V_102 [ 0 ] . V_98 ;
V_52 = F_213 ( V_2 , V_2 -> V_94 ,
V_2 -> V_96 ) ;
if ( V_52 )
return V_52 ;
F_220 ( V_2 -> V_399 ) ;
V_52 = F_221 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_38 ) ;
return V_52 ;
}
return 0 ;
}
static int F_222 ( struct V_23 * V_5 , int * V_370 )
{
if ( ! F_223 ( V_5 , F_224 ( 64 ) ) &&
! F_225 ( V_5 , F_224 ( 64 ) ) )
* V_370 = 1 ;
else if ( ! F_223 ( V_5 , F_224 ( 32 ) ) &&
! F_225 ( V_5 , F_224 ( 32 ) ) )
* V_370 = 0 ;
else {
F_83 ( & V_5 -> V_30 , L_39 ) ;
return - V_114 ;
}
return 0 ;
}
void F_226 ( struct V_1 * V_2 )
{
int V_305 ;
struct V_10 * V_11 ;
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
if ( V_11 ) {
F_86 ( V_11 -> V_400 ) ;
V_11 -> V_400 = NULL ;
}
}
F_7 ( V_2 -> V_11 ) ;
}
int F_227 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_305 , V_98 , V_199 ;
struct V_10 * V_11 ;
struct V_401 * V_400 ;
V_11 = F_66 ( V_2 -> V_94 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_57 ;
V_2 -> V_11 = V_11 ;
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
V_11 -> V_402 = V_2 -> V_234 ;
V_11 -> V_403 = F_228 ( V_22 , V_305 ) ;
V_400 = F_81 ( F_229 ( V_11 ) ) ;
if ( V_400 == NULL ) {
F_226 ( V_2 ) ;
return - V_57 ;
}
V_11 -> V_400 = V_400 ;
F_230 ( & V_11 -> V_404 ) ;
}
if ( F_65 ( V_2 ) ||
( F_57 ( V_2 ) && F_73 ( V_2 ) ) ) {
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_108 ) {
V_199 = V_2 -> V_96 + V_305 ;
V_98 = V_2 -> V_102 [ V_199 ] . V_98 ;
V_11 -> V_122 = V_98 ;
}
}
}
return 0 ;
}
void F_231 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_405 = 0 ;
if ( F_57 ( V_2 ) )
V_405 = V_406 ;
else if ( F_65 ( V_2 ) )
V_405 = V_407 ;
if ( V_4 -> V_81 [ 0 ] & V_408 )
F_232 ( V_2 , V_405 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
F_100 ( V_2 ) ;
}
static int
F_234 ( struct V_23 * V_5 , const struct V_175 * V_176 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_52 , V_370 = - 1 ;
char V_409 [ V_410 + 19 ] ;
V_52 = F_235 ( V_5 ) ;
if ( V_52 )
return V_52 ;
if ( ! ( F_236 ( V_5 , 0 ) & V_411 ) ) {
V_52 = - V_412 ;
goto V_413;
}
V_52 = F_222 ( V_5 , & V_370 ) ;
if ( V_52 )
goto V_413;
V_52 = F_237 ( V_5 , V_414 ) ;
if ( V_52 )
goto V_413;
F_238 ( V_5 ) ;
F_239 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_52 = - V_57 ;
goto V_415;
}
switch ( V_176 -> V_6 ) {
case V_7 :
V_4 -> V_416 = & V_417 ;
V_4 -> V_418 = ( T_1 * ) V_419 ;
break;
case V_188 :
case V_189 :
case V_190 :
F_240 ( V_4 ) ;
break;
case V_191 :
case V_193 :
case V_192 :
F_241 ( V_4 ) ;
break;
default:
goto V_420;
}
V_52 = F_105 ( V_5 , V_4 ) ;
if ( V_52 )
goto V_420;
V_22 = F_242 ( sizeof( struct V_1 ) ,
V_421 ) ;
if ( ! V_22 ) {
V_52 = - V_57 ;
goto V_422;
}
F_243 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_423 = F_244 ( L_28 ) ;
if ( V_2 -> V_423 == NULL ) {
V_52 = - V_57 ;
F_83 ( & V_5 -> V_30 , L_40 ) ;
goto V_424;
}
V_52 = F_205 ( V_2 ) ;
if ( V_52 )
goto V_425;
V_2 -> V_426 = V_427 ;
V_4 -> V_428 = V_5 -> V_429 ;
V_4 -> V_149 = F_245 ( V_2 ) ;
if ( V_430 == V_431 )
V_2 -> V_53 = true ;
else if ( V_430 == V_432 )
V_2 -> V_433 = true ;
F_246 ( & V_2 -> V_4 -> V_434 ) ;
F_247 ( & V_2 -> V_4 -> V_435 ) ;
F_248 ( & V_2 -> V_436 ) ;
F_249 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_101 ( V_2 , V_176 ) ;
V_2 -> V_437 = V_2 -> V_4 -> V_27 ;
F_233 ( V_2 ) ;
V_52 = F_250 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_438;
}
if ( V_2 -> V_4 -> V_109 ) {
if ( F_56 ( V_2 ) == 1 )
F_62 ( V_2 ,
V_113 ) ;
else
F_62 ( V_2 ,
V_439 ) ;
F_63 ( V_2 ,
V_440 ) ;
} else {
F_62 ( V_2 , V_113 ) ;
F_63 ( V_2 , V_113 ) ;
}
V_52 = F_251 ( V_2 ) ;
if ( V_52 )
goto V_351;
V_2 -> V_41 |= V_441 ;
} else if ( F_65 ( V_2 ) ) {
F_252 ( V_2 , V_176 ) ;
V_2 -> V_437 = V_2 -> V_4 -> V_27 ;
V_52 = F_253 ( V_2 , V_370 ) ;
if ( V_52 ) {
switch ( V_52 ) {
case - V_442 :
F_83 ( & V_5 -> V_30 , L_43 ) ;
F_83 ( & V_5 -> V_30 , L_44 ) ;
goto V_351;
case - V_57 :
F_83 ( & V_5 -> V_30 , L_45 ) ;
goto V_351;
case - V_43 :
F_83 ( & V_5 -> V_30 , L_46 ) ;
goto V_351;
default:
F_83 ( & V_5 -> V_30 , L_47 ) ;
goto V_438;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_83 ( & V_5 -> V_30 ,
L_48 , V_55 ) ;
V_52 = - V_412 ;
goto V_351;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_254 ( V_2 ) ;
if ( V_2 -> V_437 == 0 ) {
F_111 ( V_2 , V_409 ) ;
F_37 ( L_50 ,
F_255 ( V_443 ) ,
V_409 , V_2 -> V_4 -> V_428 ) ;
}
if ( F_65 ( V_2 ) && ! V_123 &&
! ! V_119 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_57 ( V_2 ) ) {
F_256 ( V_2 -> V_399 ) ;
F_257 ( V_2 -> V_399 ) ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_52 ) ;
goto V_444;
}
}
V_52 = F_89 ( V_2 ) ;
if ( V_52 )
goto V_445;
if ( V_2 -> V_437 == 0 )
F_231 ( V_2 ) ;
V_52 = F_216 ( V_2 , V_22 , V_370 ) ;
if ( V_52 )
goto V_445;
F_259 ( V_5 , V_2 ) ;
if ( F_57 ( V_2 ) )
F_260 ( V_2 , V_446 ,
V_447 ) ;
switch ( V_2 -> V_4 -> V_141 ) {
case V_142 :
F_71 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_205 ) ;
break;
case V_145 :
F_71 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_205 ) ;
break;
}
if ( V_2 -> V_433 )
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
F_263 ( V_2 ) ;
return 0 ;
V_445:
if ( F_65 ( V_2 ) )
F_264 ( V_2 ) ;
V_444:
F_84 ( V_2 ) ;
F_265 ( V_2 ) ;
F_266 ( V_2 , 0 ) ;
V_351:
F_206 ( V_2 ) ;
V_425:
F_267 ( V_2 -> V_423 ) ;
V_424:
F_268 ( V_22 ) ;
V_422:
F_87 ( V_4 ) ;
V_420:
F_7 ( V_4 ) ;
V_415:
F_269 ( V_5 ) ;
V_413:
F_270 ( V_5 ) ;
return V_52 ;
V_438:
F_123 ( V_448 , & V_2 -> V_46 ) ;
V_22 -> V_373 = & V_449 ;
V_22 -> V_378 = & V_450 ;
V_4 -> V_141 = V_145 ;
if ( F_65 ( V_2 ) )
V_2 -> V_121 = NULL ;
else
V_4 -> V_451 = V_452 ;
V_52 = F_221 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_55 ) ;
F_266 ( V_2 , 0 ) ;
goto V_351;
}
F_259 ( V_5 , V_2 ) ;
F_262 ( V_2 ) ;
return 0 ;
}
static void F_271 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_272 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_265 ( V_2 ) ;
F_273 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_274 ( V_22 ) ;
F_275 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
F_276 ( V_2 , 0 ) ;
F_47 ( & V_2 -> V_453 ) ;
F_264 ( V_2 ) ;
F_277 ( V_2 ) ;
F_278 ( V_4 -> V_454 ) ;
F_7 ( V_4 -> V_455 ) ;
}
F_279 ( V_2 -> V_399 ) ;
F_200 ( V_2 ) ;
F_7 ( V_2 -> V_155 ) ;
F_7 ( V_2 -> V_157 ) ;
if ( F_57 ( V_2 ) )
F_266 ( V_2 , 0 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_280 ( V_2 ) ;
F_84 ( V_2 ) ;
F_281 ( V_2 ) ;
F_282 ( V_2 ) ;
F_87 ( V_2 -> V_4 ) ;
F_151 ( V_2 ) ;
F_283 ( V_5 ) ;
F_269 ( V_5 ) ;
F_270 ( V_5 ) ;
if ( V_2 -> V_423 ) {
F_267 ( V_2 -> V_423 ) ;
V_2 -> V_423 = NULL ;
}
F_206 ( V_2 ) ;
F_7 ( V_4 ) ;
F_268 ( V_22 ) ;
}
static void F_284 ( struct V_23 * V_5 )
{
if ( F_285 ( V_5 ) )
return;
F_270 ( V_5 ) ;
}
static int F_286 ( struct V_23 * V_5 , T_10 V_46 )
{
int V_456 ;
V_456 = F_285 ( V_5 ) ;
if ( V_456 )
return V_456 ;
F_287 ( V_5 , F_288 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_289 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
int V_52 ;
V_52 = F_235 ( V_5 ) ;
if ( V_52 )
return V_52 ;
F_287 ( V_5 , V_457 ) ;
F_238 ( V_5 ) ;
F_290 ( V_5 ) ;
return F_291 ( V_2 ) ;
}
static int F_292 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 ;
if ( F_21 ( V_448 , & V_2 -> V_46 ) ) {
F_122 ( V_22 , L_56 ,
V_55 ) ;
return - V_114 ;
}
F_180 ( V_22 ) ;
V_52 = F_190 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_165 ( V_2 , V_22 ) ;
if ( V_52 )
F_200 ( V_2 ) ;
return V_52 ;
}
static int F_293 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_177 ( V_2 , V_22 ) ;
return 0 ;
}
void F_261 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_132 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_458 = 0 ;
T_3 V_152 = 0 ;
if ( V_2 -> V_344 . V_459 && V_2 -> V_344 . V_460 )
return;
V_152 = V_2 -> V_4 -> V_143 ;
F_230 ( & V_2 -> V_461 ) ;
F_230 ( & V_2 -> V_462 ) ;
if ( F_20 ( V_2 ) ) {
V_458 = V_463 - 1 ;
V_2 -> V_344 . V_464 = V_465 ;
} else if ( F_57 ( V_2 ) ) {
V_458 = V_367 ;
V_2 -> V_344 . V_464 = V_466 ;
} else {
V_458 = V_467 ;
V_2 -> V_344 . V_464 = V_468 ;
}
V_34 = F_66 ( V_2 -> V_344 . V_464 ,
sizeof( struct V_469 ) , V_470 ) ;
if ( ! V_34 )
return;
V_2 -> V_344 . V_459 = ( V_458 / V_152 ) ;
V_2 -> V_344 . V_460 = V_34 ;
F_68 ( V_22 , L_57 ,
V_152 , V_2 -> V_344 . V_459 ) ;
for ( V_132 = 0 ; V_132 < V_2 -> V_344 . V_464 ; V_132 ++ )
F_294 ( & V_2 -> V_344 . V_460 [ V_132 ] ) ;
V_2 -> V_471 . V_464 = V_2 -> V_344 . V_464 ;
V_34 = F_66 ( V_2 -> V_471 . V_464 ,
sizeof( struct V_469 ) , V_470 ) ;
if ( ! V_34 )
return;
V_2 -> V_471 . V_459 = ( V_458 / V_152 ) ;
V_2 -> V_471 . V_460 = V_34 ;
for ( V_132 = 0 ; V_132 < V_2 -> V_471 . V_464 ; V_132 ++ )
F_294 ( & V_2 -> V_471 . V_460 [ V_132 ] ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
if ( V_2 -> V_344 . V_459 )
F_7 ( V_2 -> V_344 . V_460 ) ;
V_2 -> V_344 . V_460 = NULL ;
V_2 -> V_344 . V_459 = 0 ;
if ( V_2 -> V_471 . V_459 )
F_7 ( V_2 -> V_471 . V_460 ) ;
V_2 -> V_471 . V_459 = 0 ;
V_2 -> V_471 . V_460 = NULL ;
}
int F_295 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_472 , V_473 , V_246 = 0 ;
int V_474 = 0 ;
if ( F_65 ( V_2 ) )
V_246 = F_296 ( V_2 -> V_4 , V_475 ) ;
if ( F_57 ( V_2 ) )
V_246 = F_97 ( V_2 , V_476 ) ;
V_472 = F_297 ( V_246 ) ;
V_473 = F_298 ( V_246 ) ;
if ( V_472 == V_477 ) {
F_83 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_473 ) ;
V_474 = 1 ;
} else if ( V_472 == V_478 ) {
if ( V_2 -> V_4 -> V_246 == V_479 ) {
F_83 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_473 ) ;
}
} else {
if ( V_2 -> V_4 -> V_246 == V_478 ) {
F_71 ( & V_22 -> V_30 ,
L_63
L_64 , V_473 ) ;
}
}
V_2 -> V_4 -> V_246 = V_472 ;
return V_474 ;
}
static inline void F_299 ( struct V_10 * V_11 )
{
int V_132 ;
struct V_480 * V_481 ;
for ( V_132 = 0 ; V_132 < V_11 -> V_402 ; V_132 ++ ) {
V_481 = & V_11 -> V_482 [ V_132 ] ;
F_37 ( L_65 , V_132 ) ;
F_300 ( V_483 , L_66 , V_484 , 16 , 1 ,
& V_11 -> V_482 [ V_132 ] ,
sizeof( struct V_480 ) , true ) ;
}
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_334 * V_335 ;
struct V_18 * V_304 ;
struct V_10 * V_11 ;
int V_305 ;
if ( ! V_22 || ! F_175 ( V_22 ) )
return;
for ( V_305 = 0 ; V_305 < V_2 -> V_236 ; V_305 ++ ) {
V_335 = & V_15 -> V_338 [ V_305 ] ;
if ( ! V_335 )
continue;
F_68 ( V_22 ,
L_67 ,
V_305 , F_302 ( V_335 -> V_485 ) ,
V_335 -> V_12 , V_335 -> V_402 ) ;
}
for ( V_305 = 0 ; V_305 < V_2 -> V_96 ; V_305 ++ ) {
V_304 = & ( V_15 -> V_19 [ V_305 ] ) ;
if ( ! V_304 )
continue;
F_68 ( V_22 ,
L_68 ,
V_305 , F_302 ( V_304 -> V_486 ) ,
V_304 -> V_487 , F_302 ( V_304 -> V_488 ) ,
V_304 -> V_402 ) ;
}
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
if ( ! V_11 )
continue;
F_68 ( V_22 , L_69 ,
V_305 , V_11 -> V_489 ) ;
F_68 ( V_22 ,
L_70 ,
V_11 -> V_490 . V_491 ,
V_11 -> V_490 . V_492 ,
V_11 -> V_490 . V_493 ,
V_11 -> V_490 . V_494 ) ;
if ( V_11 -> V_488 )
F_68 ( V_22 , L_71 ,
F_302 ( V_11 -> V_488 ) ) ;
F_68 ( V_22 ,
L_72 ,
F_302 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_495 ,
F_303 ( * ( V_11 -> V_496 ) ) ) ;
F_68 ( V_22 , L_73 ,
V_11 -> V_402 , F_304 ( V_11 ) ) ;
if ( F_305 ( V_2 -> V_4 ) )
F_299 ( V_11 ) ;
}
}
static void F_306 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
return;
F_301 ( V_2 ) ;
if ( ++ V_2 -> V_497 >= V_498 ||
F_305 ( V_2 -> V_4 ) ) {
F_122 ( V_22 , L_74 ) ;
if ( F_57 ( V_2 ) )
V_2 -> V_277 = 1 ;
else if ( F_65 ( V_2 ) )
F_307 ( V_2 ,
V_499 ) ;
} else {
F_122 ( V_22 , L_75 ) ;
V_2 -> V_4 -> V_343 = 1 ;
}
}
static struct V_500 * F_308 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_500 * V_353 = & V_22 -> V_353 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_309 ( V_2 ) ;
V_353 -> V_331 = V_2 -> V_353 . V_501 + V_2 -> V_353 . V_502 ;
V_353 -> V_327 = V_2 -> V_353 . V_503 ;
V_353 -> V_504 = V_2 -> V_353 . V_505 + V_2 -> V_353 . V_506 ;
V_353 -> V_507 = V_2 -> V_353 . V_508 ;
V_353 -> V_509 = V_2 -> V_353 . V_510 ;
V_353 -> V_511 = V_2 -> V_353 . V_512 ;
return V_353 ;
}
static T_11 F_310 ( struct V_1 * V_2 )
{
T_1 V_513 ;
V_513 = F_302 ( V_2 -> V_127 ) ;
if ( ! ( V_513 & V_2 -> V_4 -> V_125 ) )
return V_514 ;
V_513 = F_302 ( V_2 -> V_129 ) ;
if ( ! F_311 ( V_513 ) )
return V_514 ;
F_3 ( 0xffffffff , V_2 -> V_121 ) ;
F_302 ( V_2 -> V_127 ) ;
F_302 ( V_2 -> V_127 ) ;
return V_515 ;
}
static T_11 V_308 ( int V_122 , void * V_172 )
{
struct V_18 * V_304 = V_172 ;
struct V_1 * V_2 = V_304 -> V_2 ;
if ( V_2 -> V_41 & V_108 )
goto V_516;
else if ( V_2 -> V_41 & V_107 ) {
F_3 ( 0xffffffff , V_2 -> V_121 ) ;
goto V_516;
}
if ( F_312 ( V_2 ) == V_514 )
return V_514 ;
V_516:
V_2 -> V_4 -> V_517 ++ ;
F_209 ( V_2 , V_304 ) ;
return V_515 ;
}
static T_11 V_313 ( int V_122 , void * V_172 )
{
struct V_18 * V_304 = V_172 ;
struct V_1 * V_2 = V_304 -> V_2 ;
if ( F_312 ( V_2 ) == V_514 )
return V_514 ;
F_313 ( & V_304 -> V_518 ) ;
return V_515 ;
}
static T_11 V_312 ( int V_122 , void * V_172 )
{
struct V_18 * V_304 = V_172 ;
struct V_1 * V_2 = V_304 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_121 ) ;
F_313 ( & V_304 -> V_518 ) ;
return V_515 ;
}
static T_11 V_311 ( int V_122 , void * V_172 )
{
struct V_18 * V_304 = V_172 ;
F_313 ( & V_304 -> V_518 ) ;
return V_515 ;
}
static T_11 V_317 ( int V_122 , void * V_172 )
{
struct V_10 * V_11 = V_172 ;
F_313 ( & V_11 -> V_518 ) ;
return V_515 ;
}
static void F_314 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_304 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_305 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_305 = 0 ; V_305 < V_2 -> V_96 ; V_305 ++ ) {
V_304 = & V_15 -> V_19 [ V_305 ] ;
F_204 ( V_2 , V_304 ) ;
F_313 ( & V_304 -> V_518 ) ;
}
if ( V_2 -> V_41 & V_108 ) {
if ( ( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_316 ) ) ||
( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) )
return;
for ( V_305 = 0 ; V_305 < V_2 -> V_94 ; V_305 ++ ) {
V_11 = & V_2 -> V_11 [ V_305 ] ;
F_315 ( V_2 , V_11 ) ;
F_313 ( & V_11 -> V_518 ) ;
}
}
}
static void
F_154 ( struct V_1 * V_2 , T_2 V_519 )
{
T_1 V_520 ;
V_520 = V_2 -> V_437 & 0xf ;
V_520 |= V_519 << 7 ;
V_520 |= ( V_427 - V_2 -> V_426 ) << 8 ;
F_99 ( V_2 , V_521 , V_520 ) ;
V_2 -> V_426 = V_427 ;
}
static int
F_316 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_520 ;
F_317 ( V_46 != V_522 &&
V_46 != V_523 ) ;
if ( F_96 ( V_2 ) )
return - V_114 ;
V_520 = F_97 ( V_2 , V_524 ) ;
if ( V_46 == V_522 )
F_318 ( V_520 , V_2 -> V_437 ) ;
else if ( V_46 == V_523 )
F_319 ( V_520 , V_2 -> V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
static int
F_320 ( struct V_1 * V_2 )
{
T_1 V_520 ;
if ( F_96 ( V_2 ) )
return - V_361 ;
V_520 = F_97 ( V_2 , V_524 ) ;
F_321 ( V_520 , V_2 -> V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
void F_266 ( struct V_1 * V_2 , T_2 V_525 )
{
T_1 V_520 ;
if ( F_96 ( V_2 ) )
goto V_52;
V_520 = F_97 ( V_2 , V_526 ) ;
F_322 ( V_520 , V_2 -> V_437 ) ;
F_99 ( V_2 , V_526 , V_520 ) ;
if ( V_525 ) {
F_99 ( V_2 , V_300 ,
V_302 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_76 ) ;
} else if ( ! ( V_520 & 0x11111111 ) )
F_99 ( V_2 , V_300 ,
V_527 ) ;
V_520 = F_97 ( V_2 , V_524 ) ;
F_321 ( V_520 , V_2 -> V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
F_100 ( V_2 ) ;
V_52:
V_2 -> V_528 = 0 ;
V_2 -> V_41 &= ~ V_529 ;
F_126 ( V_530 , & V_2 -> V_46 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
}
static int
F_323 ( struct V_1 * V_2 )
{
int V_531 , V_46 , V_532 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_97 ( V_2 , V_524 ) ;
V_531 = F_97 ( V_2 , V_526 ) ;
if ( V_2 -> V_41 & V_533 ) {
V_532 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_531 = V_531 & V_532 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_531 & 0x11111111 ) ) ||
( ( V_531 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_324 ( struct V_1 * V_2 )
{
T_1 V_520 = F_97 ( V_2 , V_534 ) ;
if ( V_520 != V_535 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_535 , V_520 ) ;
}
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 )
{
T_1 V_520 , V_536 ;
T_2 V_537 = V_2 -> V_537 ;
T_2 V_437 = V_2 -> V_437 ;
T_2 V_26 ;
if ( F_178 ( V_530 , & V_2 -> V_46 ) )
return 1 ;
if ( F_96 ( V_2 ) )
return - 1 ;
V_520 = F_97 ( V_2 , V_526 ) ;
if ( ! ( V_520 & ( 1 << ( V_437 * 4 ) ) ) ) {
F_325 ( V_520 , V_437 ) ;
F_99 ( V_2 , V_526 , V_520 ) ;
}
V_536 = F_97 ( V_2 , V_300 ) ;
F_326 ( V_2 , V_538 , L_79 , V_536 ) ;
switch ( V_536 ) {
case V_527 :
F_99 ( V_2 , V_300 ,
V_539 ) ;
F_99 ( V_2 , V_534 ,
V_535 ) ;
F_154 ( V_2 , 0 ) ;
F_100 ( V_2 ) ;
return 1 ;
case V_301 :
V_26 = F_324 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
case V_522 :
V_520 = F_97 ( V_2 , V_524 ) ;
F_318 ( V_520 , V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
break;
case V_523 :
V_520 = F_97 ( V_2 , V_524 ) ;
F_319 ( V_520 , V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
break;
case V_302 :
F_83 ( & V_2 -> V_5 -> V_30 , L_80 ) ;
F_100 ( V_2 ) ;
return - 1 ;
case V_539 :
case V_540 :
break;
}
F_100 ( V_2 ) ;
do {
F_141 ( 1000 ) ;
V_536 = F_97 ( V_2 , V_300 ) ;
if ( V_536 == V_540 )
continue;
} while ( ( V_536 != V_301 ) && -- V_537 );
if ( ! V_537 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_81 ) ;
return - 1 ;
}
if ( F_96 ( V_2 ) )
return - 1 ;
V_520 = F_97 ( V_2 , V_524 ) ;
F_321 ( V_520 , V_437 ) ;
F_99 ( V_2 , V_524 , V_520 ) ;
V_26 = F_324 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
}
static void
F_327 ( struct V_541 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
T_1 V_542 = 0xf ;
T_1 V_520 ;
if ( F_96 ( V_2 ) )
goto V_543;
V_542 = F_97 ( V_2 , V_300 ) ;
if ( V_542 == V_540 ||
V_542 == V_523 ) {
F_100 ( V_2 ) ;
F_260 ( V_2 , F_327 ,
V_447 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_147 == V_181 ) {
F_100 ( V_2 ) ;
goto V_544;
}
if ( V_542 == V_539 ||
V_542 == V_301 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_82
L_83 ) ;
goto V_545;
}
if ( V_2 -> V_546 ++ > V_2 -> V_547 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_84 ,
V_2 -> V_547 ) ;
goto V_545;
}
if ( ! F_323 ( V_2 ) ) {
V_545:
V_542 = F_97 ( V_2 , V_300 ) ;
if ( V_542 == V_522 ) {
F_99 ( V_2 , V_300 ,
V_539 ) ;
F_123 ( V_530 , & V_2 -> V_46 ) ;
F_326 ( V_2 , V_548 , L_85 ) ;
F_154 ( V_2 , 0 ) ;
V_520 = F_97 ( V_2 ,
V_524 ) ;
F_318 ( V_520 , V_2 -> V_437 ) ;
F_99 ( V_2 ,
V_524 , V_520 ) ;
}
F_100 ( V_2 ) ;
F_174 () ;
if ( F_329 ( V_2 ) &&
( V_2 -> V_41 & V_533 ) ) {
F_326 ( V_2 , V_548 , L_86 ) ;
F_330 ( V_2 ) ;
V_2 -> V_41 |= V_529 ;
}
F_176 () ;
V_2 -> V_41 &= ~ V_533 ;
if ( ! V_2 -> V_182 -> V_549 ( V_2 ) ) {
F_260 ( V_2 , V_550 , 0 ) ;
V_2 -> V_546 = 0 ;
return;
}
goto V_543;
}
F_100 ( V_2 ) ;
V_544:
V_542 = F_97 ( V_2 , V_300 ) ;
F_326 ( V_2 , V_538 , L_87 , V_542 ) ;
switch ( V_542 ) {
case V_301 :
if ( ! F_250 ( V_2 ) ) {
F_260 ( V_2 , V_550 , 0 ) ;
V_2 -> V_546 = 0 ;
return;
}
case V_302 :
break;
default:
F_260 ( V_2 ,
F_327 , V_447 ) ;
return;
}
V_543:
F_83 ( & V_2 -> V_5 -> V_30 , L_88
L_89 , V_542 , V_2 -> V_546 ) ;
F_25 ( V_2 -> V_22 ) ;
F_266 ( V_2 , 0 ) ;
}
static void
F_331 ( struct V_541 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_513 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_542 == V_523 ) {
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
} else
F_189 ( V_2 , V_22 ) ;
V_513 = F_97 ( V_2 , V_551 ) ;
if ( V_513 & V_552 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_90 ,
V_513 ) ;
if ( F_332 ( V_513 ) == V_553 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_91
L_92 ) ;
F_83 ( & V_2 -> V_5 -> V_30 ,
L_93 ) ;
}
goto V_543;
}
if ( V_2 -> V_4 -> V_246 == V_477 ) {
F_83 ( & V_2 -> V_5 -> V_30 , L_94 ,
V_2 -> V_4 -> V_246 ) ;
goto V_543;
}
if ( ! ( V_2 -> V_41 & V_533 ) ) {
if ( F_316 ( V_2 , V_2 -> V_542 ) ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_95
L_96 ) ;
goto V_543;
}
}
V_2 -> V_546 = 0 ;
F_260 ( V_2 , F_327 , V_447 ) ;
return;
V_543:
F_25 ( V_22 ) ;
F_266 ( V_2 , 1 ) ;
}
static void
F_333 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_97 ( V_2 , V_291 ) ;
if ( V_46 == V_554 )
return;
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_291 ,
V_554 ) ;
F_100 ( V_2 ) ;
}
static void F_334 ( struct V_1 * V_2 ,
T_1 V_555 )
{
T_1 V_46 , V_556 = 0 , V_557 = 0 ;
F_335 ( V_556 ) ;
F_336 ( V_556 ) ;
F_152 ( V_2 , V_558 , V_556 ) ;
F_337 ( V_557 ) ;
F_338 ( V_557 ) ;
F_339 ( V_557 ) ;
F_340 ( V_557 ) ;
F_152 ( V_2 , V_559 , V_557 ) ;
F_71 ( & V_2 -> V_5 -> V_30 , L_97
L_98 ) ;
V_2 -> V_277 = 1 ;
if ( F_96 ( V_2 ) )
return;
V_46 = F_97 ( V_2 , V_300 ) ;
if ( F_21 ( V_448 , & V_2 -> V_46 ) ) {
F_122 ( V_2 -> V_22 , L_56 ,
V_55 ) ;
F_100 ( V_2 ) ;
return;
}
if ( V_46 == V_301 ) {
F_99 ( V_2 , V_300 ,
V_522 ) ;
V_2 -> V_41 |= V_533 ;
F_326 ( V_2 , V_548 , L_99 ) ;
F_154 ( V_2 , 0 ) ;
}
F_99 ( V_2 , V_291 ,
V_554 ) ;
F_100 ( V_2 ) ;
}
static void
F_143 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_291 ,
V_292 ) ;
F_326 ( V_2 , V_548 , L_100 ) ;
F_100 ( V_2 ) ;
}
void F_260 ( struct V_1 * V_2 ,
T_12 V_67 , int V_560 )
{
if ( F_21 ( V_561 , & V_2 -> V_46 ) )
return;
F_341 ( & V_2 -> V_65 , V_67 ) ;
F_342 ( V_2 -> V_423 , & V_2 -> V_65 ,
F_343 ( V_560 ) ) ;
}
static void
V_550 ( struct V_541 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_290 ;
if ( V_2 -> V_4 -> V_147 != V_148 ) {
V_290 = F_97 ( V_2 ,
V_291 ) ;
if ( V_2 -> V_546 ++ > V_289 )
F_266 ( V_2 , 0 ) ;
else if ( V_290 != V_292 )
F_260 ( V_2 , V_550 ,
V_447 ) ;
else
goto V_562;
F_326 ( V_2 , V_548 , L_101 ) ;
return;
}
V_562:
F_257 ( V_2 -> V_399 ) ;
if ( F_175 ( V_22 ) ) {
if ( F_173 ( V_2 , V_22 ) )
goto V_516;
F_125 ( V_22 , V_362 ) ;
}
V_516:
F_25 ( V_22 ) ;
V_2 -> V_528 = 0 ;
V_2 -> V_41 &= ~ V_529 ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
if ( V_2 -> V_437 == 0 )
F_231 ( V_2 ) ;
if ( ! F_320 ( V_2 ) )
F_260 ( V_2 , V_446 ,
V_447 ) ;
}
static int
F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_214 * V_215 = & V_4 -> V_215 ;
T_1 V_46 = 0 , V_563 ;
T_1 V_564 ;
int V_52 = 0 ;
if ( F_295 ( V_2 ) )
goto V_565;
if ( V_2 -> V_277 )
F_345 ( V_2 , 0 ) ;
V_46 = F_97 ( V_2 , V_300 ) ;
if ( V_46 == V_522 ) {
F_333 ( V_2 ) ;
V_2 -> V_277 = 1 ;
} else if ( V_46 == V_523 )
goto V_565;
V_563 = F_97 ( V_2 , V_566 ) ;
if ( V_563 != V_2 -> V_563 ) {
V_2 -> V_563 = V_563 ;
V_2 -> V_528 = 0 ;
if ( V_2 -> V_277 )
goto V_565;
if ( V_4 -> V_343 && V_567 )
F_210 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_528 < V_568 )
return 0 ;
V_2 -> V_41 |= V_529 ;
F_345 ( V_2 , 0 ) ;
if ( V_567 )
F_126 ( V_569 , & V_2 -> V_46 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_102 ) ;
V_564 = F_97 ( V_2 , V_551 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_103
L_104
L_105
L_106
L_107 ,
V_564 ,
F_97 ( V_2 , V_570 ) ,
F_118 ( V_2 , V_571 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_572 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_573 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_574 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_575 + 0x3c , & V_52 ) ) ;
if ( F_332 ( V_564 ) == 0x67 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_108
L_109 ) ;
V_565:
V_2 -> V_542 = ( V_46 == V_523 ) ? V_46 :
V_522 ;
if ( V_567 && ! F_45 ( V_64 ,
& V_2 -> V_46 ) ) {
F_260 ( V_2 , F_331 , 0 ) ;
F_326 ( V_2 , V_548 , L_110 ) ;
} else if ( ! V_567 && V_215 -> V_576 &&
V_2 -> V_41 & V_533 ) {
F_330 ( V_2 ) ;
}
return 1 ;
}
void V_446 ( struct V_541 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
goto V_577;
if ( F_344 ( V_2 ) )
return;
if ( V_2 -> V_344 . V_345 )
F_346 ( V_2 ) ;
V_577:
F_260 ( V_2 , V_446 , V_447 ) ;
}
static int F_347 ( struct V_23 * V_5 )
{
struct V_23 * V_578 ;
int V_520 = V_5 -> V_579 ;
while ( V_520 -- > 0 ) {
V_578 = F_348 ( F_349
( V_5 -> V_580 ) , V_5 -> V_580 -> V_581 ,
F_350 ( F_351 ( V_5 -> V_579 ) , V_520 ) ) ;
if ( ! V_578 )
continue;
if ( V_578 -> V_582 != V_583 ) {
F_352 ( V_578 ) ;
return 0 ;
}
F_352 ( V_578 ) ;
}
return 1 ;
}
static int F_353 ( struct V_23 * V_5 )
{
int V_52 , V_584 ;
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_585 = V_586 ;
V_52 = F_235 ( V_5 ) ;
if ( V_52 )
return V_52 ;
F_238 ( V_5 ) ;
F_290 ( V_5 ) ;
V_584 = F_347 ( V_5 ) ;
if ( F_96 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_147 != V_181 && V_584 ) {
V_2 -> V_277 = 1 ;
F_123 ( V_530 , & V_2 -> V_46 ) ;
F_99 ( V_2 , V_300 ,
V_539 ) ;
F_326 ( V_2 , V_548 , L_85 ) ;
}
F_100 ( V_2 ) ;
V_52 = F_250 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_320 ( V_2 ) ;
F_7 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
F_7 ( V_2 -> V_102 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 ) {
F_266 ( V_2 , 1 ) ;
F_126 ( V_561 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_52 ;
}
V_52 = F_173 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_516;
F_125 ( V_22 , V_362 ) ;
}
V_516:
F_25 ( V_22 ) ;
return V_52 ;
}
static T_13 F_354 ( struct V_23 * V_5 ,
T_14 V_46 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_587 )
return V_588 ;
if ( V_46 == V_586 )
return V_589 ;
F_123 ( V_561 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_65 ) ;
if ( F_175 ( V_22 ) )
F_189 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
F_84 ( V_2 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_355 ( V_5 ) ;
F_270 ( V_5 ) ;
return V_590 ;
}
static T_13 F_356 ( struct V_23 * V_5 )
{
return F_353 ( V_5 ) ? V_588 :
V_589 ;
}
static void F_357 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_272 ( V_5 ) ;
F_358 ( V_5 ) ;
V_46 = F_97 ( V_2 , V_300 ) ;
if ( V_46 == V_301 && F_178 ( V_561 ,
& V_2 -> V_46 ) )
F_260 ( V_2 , V_446 ,
V_447 ) ;
}
static T_13 F_359 ( struct V_23 * V_5 ,
T_14 V_46 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_591 * V_416 = V_2 -> V_4 -> V_416 ;
if ( V_416 -> V_592 ) {
return V_416 -> V_592 ( V_5 , V_46 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_111 ) ;
return V_588 ;
}
}
static T_13 F_360 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_591 * V_416 = V_2 -> V_4 -> V_416 ;
if ( V_416 -> V_593 ) {
return V_416 -> V_593 ( V_5 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_112 ) ;
return V_588 ;
}
}
static void F_361 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_591 * V_416 = V_2 -> V_4 -> V_416 ;
if ( V_416 -> V_594 )
V_416 -> V_594 ( V_5 ) ;
else
F_83 ( & V_5 -> V_30 , L_113 ) ;
}
static int
F_362 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_145 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_140 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_116 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_112 ( V_2 ) ;
V_52 = F_128 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_2 -> V_277 = 0 ;
return V_52 ;
}
int F_363 ( struct V_1 * V_2 , T_15 V_84 ,
int V_85 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_595 = 0 ;
char V_596 [ 8 ] ;
int V_597 ;
if ( V_85 == V_89 ) {
V_595 = V_2 -> V_90 ;
V_597 = V_2 -> V_96 ;
strcpy ( V_596 , L_114 ) ;
} else if ( V_85 == V_91 ) {
V_595 = V_2 -> V_92 ;
V_597 = V_2 -> V_94 ;
strcpy ( V_596 , L_115 ) ;
}
if ( ! F_364 ( V_84 ) ) {
F_122 ( V_22 , L_116 ,
V_596 ) ;
return - V_40 ;
}
if ( F_57 ( V_2 ) && ( V_85 == V_91 ) &&
! F_73 ( V_2 ) ) {
F_122 ( V_22 , L_117 ) ;
return - V_40 ;
}
if ( V_84 > F_61 () ) {
F_122 ( V_22 ,
L_118 ,
V_596 , F_61 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_365 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_598 , V_599 ;
int V_52 ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
return - V_361 ;
V_598 = V_2 -> V_100 ;
V_599 = V_2 -> V_101 ;
F_22 ( V_22 ) ;
V_52 = F_213 ( V_2 , V_598 , V_599 ) ;
if ( V_52 )
goto V_516;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
F_264 ( V_2 ) ;
F_366 ( V_2 ) ;
}
F_84 ( V_2 ) ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
F_7 ( V_2 -> V_102 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( ( V_598 != V_2 -> V_94 ) ||
( V_599 != V_2 -> V_96 ) ) {
V_52 = F_213 ( V_2 ,
V_2 -> V_94 ,
V_2 -> V_96 ) ;
if ( V_52 )
goto V_516;
}
if ( F_65 ( V_2 ) ) {
F_276 ( V_2 , 1 ) ;
V_52 = F_367 ( V_2 ) ;
F_368 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_119 ) ;
goto V_516;
}
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 )
goto V_516;
V_52 = F_165 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_516;
F_125 ( V_22 , V_362 ) ;
}
V_516:
F_25 ( V_22 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
return V_52 ;
}
static void
F_369 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_600 )
{
struct V_601 * V_602 ;
V_602 = F_370 ( V_30 ) ;
if ( ! V_602 )
return;
F_371 (indev) {
switch ( V_600 ) {
case V_362 :
F_372 ( V_2 ,
V_603 -> V_604 , V_605 ) ;
break;
case V_266 :
F_372 ( V_2 ,
V_603 -> V_604 , V_606 ) ;
break;
default:
break;
}
} F_373 ( V_602 ) ;
F_374 ( V_602 ) ;
}
void F_125 ( struct V_21 * V_22 , unsigned long V_600 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_51 ;
F_369 ( V_2 , V_22 , V_600 ) ;
F_375 () ;
F_376 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_377 ( V_22 , F_378 ( V_607 ) , V_51 ) ;
if ( ! V_30 )
continue;
F_369 ( V_2 , V_30 , V_600 ) ;
}
F_379 () ;
}
static int F_380 ( struct V_608 * V_609 ,
unsigned long V_600 , void * V_610 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_381 ( V_610 ) ;
V_611:
if ( V_30 == NULL )
goto V_516;
if ( V_30 -> V_397 & V_612 ) {
V_30 = F_382 ( V_30 ) ;
goto V_611;
}
if ( ! F_383 ( V_30 ) )
goto V_516;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_516;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_516;
F_369 ( V_2 , V_30 , V_600 ) ;
V_516:
return V_613 ;
}
static int
F_384 ( struct V_608 * V_609 ,
unsigned long V_600 , void * V_610 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_614 * V_603 = (struct V_614 * ) V_610 ;
V_30 = V_603 -> V_615 ? V_603 -> V_615 -> V_30 : NULL ;
V_611:
if ( V_30 == NULL )
goto V_516;
if ( V_30 -> V_397 & V_612 ) {
V_30 = F_382 ( V_30 ) ;
goto V_611;
}
if ( ! F_383 ( V_30 ) )
goto V_516;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_516;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_516;
switch ( V_600 ) {
case V_362 :
F_372 ( V_2 , V_603 -> V_604 , V_605 ) ;
break;
case V_266 :
F_372 ( V_2 , V_603 -> V_604 , V_606 ) ;
break;
default:
break;
}
V_516:
return V_613 ;
}
void F_125 ( struct V_21 * V_30 , unsigned long V_600 )
{ }
static int T_16 F_385 ( void )
{
int V_26 ;
F_386 ( V_483 L_120 , V_616 ) ;
#ifdef F_387
F_388 ( & V_617 ) ;
F_389 ( & V_618 ) ;
#endif
V_26 = F_390 ( & V_619 ) ;
if ( V_26 ) {
#ifdef F_387
F_391 ( & V_618 ) ;
F_392 ( & V_617 ) ;
#endif
}
return V_26 ;
}
static void T_17 F_393 ( void )
{
F_394 ( & V_619 ) ;
#ifdef F_387
F_391 ( & V_618 ) ;
F_392 ( & V_617 ) ;
#endif
}
