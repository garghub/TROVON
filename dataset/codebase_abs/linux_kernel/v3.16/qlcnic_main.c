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
if ( V_15 -> V_19 != NULL )
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
if ( F_15 ( V_2 -> V_24 , V_39 -> V_44 ) )
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
struct V_21 * V_22 , const unsigned char * V_39 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 = - V_43 ;
if ( ! V_2 -> V_52 )
return F_28 ( V_48 , V_50 , V_22 , V_39 ) ;
if ( ( V_2 -> V_41 & V_53 ) ||
F_29 ( V_2 ) ) {
if ( F_30 ( V_39 ) ) {
V_51 = F_31 ( V_22 , V_39 ) ;
if ( ! V_51 )
V_51 = F_32 ( V_2 , V_39 ) ;
} else if ( F_33 ( V_39 ) ) {
V_51 = F_34 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
}
return V_51 ;
}
static int F_35 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 ,
const unsigned char * V_39 , T_3 V_41 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 = 0 ;
if ( ! V_2 -> V_52 )
return F_36 ( V_48 , V_50 , V_22 , V_39 , V_41 ) ;
if ( ! ( V_2 -> V_41 & V_53 ) &&
! F_29 ( V_2 ) ) {
F_37 ( L_2 , V_54 ) ;
return - V_43 ;
}
if ( F_38 ( V_39 , V_2 -> V_24 ) )
return V_51 ;
if ( F_30 ( V_39 ) ) {
if ( F_39 ( V_22 ) < V_2 -> V_4 -> V_55 )
V_51 = F_40 ( V_22 , V_39 ) ;
else
V_51 = - V_56 ;
} else if ( F_33 ( V_39 ) ) {
V_51 = F_41 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
return V_51 ;
}
static int F_42 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_21 * V_22 , int V_61 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( ! V_2 -> V_52 )
return F_43 ( V_58 , V_60 , V_22 , V_61 ) ;
if ( ( V_2 -> V_41 & V_53 ) ||
F_29 ( V_2 ) )
V_61 = F_43 ( V_58 , V_60 , V_22 , V_61 ) ;
return V_61 ;
}
static void F_44 ( struct V_1 * V_2 )
{
while ( F_45 ( V_62 , & V_2 -> V_46 ) )
F_46 ( 10000 , 11000 ) ;
if ( ! V_2 -> V_63 . V_64 . V_65 )
return;
F_47 ( & V_2 -> V_63 ) ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! ( V_2 -> V_41 & V_68 ) )
return - V_43 ;
V_67 -> V_69 = sizeof( V_4 -> V_70 ) ;
memcpy ( V_67 -> V_71 , V_4 -> V_70 , V_67 -> V_69 ) ;
return 0 ;
}
static void F_49 ( struct V_21 * V_22 ,
T_4 V_72 , T_5 V_73 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || V_4 -> V_74 )
return;
V_4 -> V_74 = F_51 ( V_73 ) ;
V_2 -> V_41 |= V_75 ;
}
static void F_52 ( struct V_21 * V_22 ,
T_4 V_72 , T_5 V_73 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || ! V_4 -> V_74 ||
( V_4 -> V_74 != F_51 ( V_73 ) ) )
return;
V_2 -> V_41 |= V_76 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_54 ( V_2 ) &&
( V_4 -> V_77 [ 0 ] & V_78 ) ) {
F_45 ( V_79 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_55 ( struct V_1 * V_2 , T_2 V_80 ,
int V_81 )
{
int V_82 , V_83 = V_84 ;
if ( V_81 == V_85 )
V_83 = V_2 -> V_86 ;
else if ( V_81 == V_87 )
V_83 = V_2 -> V_88 ;
V_82 = F_56 ( F_57 ( int , F_58 () ,
V_83 ) ) ;
if ( V_80 > V_82 )
return V_82 ;
else
return V_80 ;
}
void F_59 ( struct V_1 * V_2 , T_2 V_89 )
{
if ( V_2 -> V_88 )
V_2 -> V_90 = F_55 ( V_2 , V_89 ,
V_87 ) ;
else
V_2 -> V_90 = V_89 ;
}
void F_60 ( struct V_1 * V_2 , T_2 V_91 )
{
if ( V_2 -> V_86 )
V_2 -> V_92 = F_55 ( V_2 , V_91 ,
V_85 ) ;
else
V_2 -> V_92 = V_91 ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_93 = 0 , V_51 = 0 , V_94 ;
V_2 -> V_41 &= ~ V_95 ;
if ( V_2 -> V_96 > 0 )
V_93 += V_2 -> V_96 ;
else
V_93 += V_2 -> V_90 ;
if ( V_2 -> V_97 > 0 )
V_93 += V_2 -> V_97 ;
else
V_93 += V_2 -> V_92 ;
if ( F_62 ( V_2 ) )
V_93 += 1 ;
if ( ! V_2 -> V_98 ) {
V_2 -> V_98 = F_63 ( V_93 ,
sizeof( struct V_99 ) ,
V_20 ) ;
if ( ! V_2 -> V_98 )
return - V_56 ;
}
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ )
V_2 -> V_98 [ V_94 ] . V_100 = V_94 ;
V_101:
V_51 = F_64 ( V_5 , V_2 -> V_98 , V_93 ) ;
if ( V_51 == - V_102 ) {
if ( ! V_2 -> V_96 && ! V_2 -> V_97 )
return V_51 ;
F_65 ( V_2 -> V_22 ,
L_3 ,
V_93 , V_51 ) ;
V_93 = V_2 -> V_90 + V_2 -> V_92 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = 0 ;
if ( F_62 ( V_2 ) )
V_93 += 1 ;
F_65 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_90 , V_2 -> V_92 ,
V_93 ) ;
goto V_101;
} else if ( V_51 < 0 ) {
return V_51 ;
}
V_2 -> V_4 -> V_93 = V_93 ;
if ( V_2 -> V_96 > 0 )
V_2 -> V_90 = V_2 -> V_96 ;
if ( V_2 -> V_97 > 0 )
V_2 -> V_92 = V_2 -> V_97 ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 , V_94 ;
if ( ! V_2 -> V_98 ) {
V_2 -> V_98 = F_63 ( V_93 ,
sizeof( struct V_99 ) ,
V_20 ) ;
if ( ! V_2 -> V_98 )
return - V_56 ;
}
V_2 -> V_41 &= ~ ( V_103 | V_104 ) ;
if ( V_2 -> V_4 -> V_105 ) {
V_106:
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ )
V_2 -> V_98 [ V_94 ] . V_100 = V_94 ;
V_51 = F_67 ( V_5 ,
V_2 -> V_98 , 1 , V_93 ) ;
if ( V_51 == V_93 ) {
V_2 -> V_41 |= V_104 ;
V_2 -> V_4 -> V_93 = V_93 ;
F_68 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_51 > 0 ) {
F_69 ( V_5 ) ;
F_68 ( & V_5 -> V_30 ,
L_3 ,
V_93 , V_51 ) ;
if ( F_54 ( V_2 ) ) {
V_93 = F_56 ( V_51 ) ;
if ( V_51 < V_107 )
return - V_102 ;
} else {
V_93 = F_56 ( V_51 - 1 ) ;
V_93 += 1 ;
if ( V_51 < V_108 )
return - V_102 ;
}
if ( F_54 ( V_2 ) &&
! F_70 ( V_2 ) ) {
V_2 -> V_92 = V_93 ;
V_2 -> V_90 = V_109 ;
} else {
V_2 -> V_90 = V_93 / 2 ;
V_2 -> V_92 = V_2 -> V_90 ;
}
if ( V_93 ) {
F_68 ( & V_5 -> V_30 ,
L_6 ,
V_93 ) ;
goto V_106;
}
} else {
F_68 ( & V_5 -> V_30 ,
L_7 ,
V_93 , V_51 ) ;
return V_51 ;
}
}
return - V_110 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_93 ;
V_93 = V_2 -> V_92 ;
if ( F_70 ( V_2 ) )
V_93 += V_2 -> V_90 ;
else
V_93 += V_109 ;
return V_93 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_111 , V_112 ;
const struct V_113 * V_114 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_115 && ! F_73 ( V_5 ) ) {
V_2 -> V_41 |= V_103 ;
V_111 = V_116 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_117 = F_74 ( V_2 -> V_4 ,
V_111 ) ;
F_68 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_98 [ 0 ] . V_94 = V_5 -> V_118 ;
return V_51 ;
}
if ( V_115 || V_119 )
return - V_43 ;
V_114 = & V_120 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_121 = V_114 -> V_121 ;
V_111 = V_114 -> V_117 ;
V_2 -> V_117 = F_74 ( V_4 , V_111 ) ;
V_112 = V_114 -> V_122 ;
V_2 -> V_122 = F_74 ( V_4 , V_112 ) ;
V_2 -> V_123 = F_74 ( V_4 , V_124 ) ;
V_2 -> V_125 = F_74 ( V_4 , V_126 ) ;
F_68 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_98 [ 0 ] . V_94 = V_5 -> V_118 ;
return V_51 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_93 , V_51 = 0 ;
if ( V_2 -> V_41 & V_95 ) {
V_51 = F_61 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_93 = V_2 -> V_4 -> V_93 ;
} else {
V_93 = F_71 ( V_2 ) ;
V_51 = F_66 ( V_2 , V_93 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_104 ) ) {
F_76 ( V_2 ) ;
V_2 -> V_92 = V_109 ;
V_51 = F_72 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , int V_127 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_128 ;
if ( F_70 ( V_2 ) &&
! V_4 -> V_129 &&
( V_2 -> V_41 & V_104 ) ) {
V_4 -> V_130 = F_78 ( V_4 -> V_93 *
sizeof( struct V_131 ) ) ;
if ( ! V_4 -> V_130 )
return - V_56 ;
for ( V_128 = 0 ; V_128 < V_4 -> V_93 ; V_128 ++ ) {
V_4 -> V_130 [ V_128 ] . type = V_132 ;
V_4 -> V_130 [ V_128 ] . V_71 = V_128 ;
V_4 -> V_130 [ V_128 ] . V_133 = 0 ;
}
V_51 = F_79 ( V_2 , 1 ) ;
if ( V_51 )
F_80 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_93 ) ;
return V_51 ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_104 )
F_69 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_103 )
F_82 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
if ( V_2 -> V_4 -> V_130 ) {
F_83 ( V_2 -> V_4 -> V_130 ) ;
V_2 -> V_4 -> V_130 = NULL ;
}
}
static void F_84 ( struct V_3 * V_4 )
{
if ( V_4 -> V_134 != NULL )
F_85 ( V_4 -> V_134 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_135 * V_136 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
switch ( V_4 -> V_137 ) {
case V_138 :
V_4 -> V_139 = V_140 ;
break;
case V_141 :
V_4 -> V_139 = V_142 ;
break;
}
return 0 ;
}
if ( V_4 -> V_143 == V_144 )
return 0 ;
V_136 = F_63 ( V_4 -> V_145 , sizeof( * V_136 ) , V_20 ) ;
if ( ! V_136 )
return - V_56 ;
V_26 = F_87 ( V_2 , V_136 ) ;
F_7 ( V_136 ) ;
return V_26 ;
}
static bool F_88 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_89 ( V_2 ) ) {
V_26 = true ;
} else if ( F_62 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_77 [ 0 ] &
V_146 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_135 * V_136 ;
int V_128 , V_71 = 0 , V_26 = 0 , V_147 = 0 ;
T_3 V_148 ;
T_2 V_149 ;
V_136 = F_63 ( V_4 -> V_145 , sizeof( * V_136 ) , V_20 ) ;
if ( ! V_136 )
return - V_56 ;
V_26 = F_87 ( V_2 , V_136 ) ;
if ( V_26 )
goto V_150;
V_148 = V_4 -> V_139 ;
V_2 -> V_151 = F_5 ( sizeof( struct V_152 ) *
V_148 , V_20 ) ;
if ( ! V_2 -> V_151 ) {
V_26 = - V_56 ;
goto V_150;
}
V_2 -> V_153 = F_5 ( sizeof( struct V_154 ) *
V_142 , V_20 ) ;
if ( ! V_2 -> V_153 ) {
V_26 = - V_56 ;
goto V_155;
}
for ( V_128 = 0 ; V_128 < V_4 -> V_145 ; V_128 ++ ) {
V_149 = V_136 [ V_128 ] . V_71 ;
if ( V_149 >= V_4 -> V_145 ) {
V_26 = V_156 ;
F_80 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_54 , V_149 , V_4 -> V_145 ) ;
goto V_157;
}
if ( ! V_136 [ V_128 ] . V_158 ||
( V_136 [ V_128 ] . type != V_159 ) )
continue;
if ( F_88 ( V_2 ) ) {
if ( ! F_91 ( V_2 , V_149 ,
& V_71 ) )
V_2 -> V_151 [ V_147 ] . V_160 = true ;
else
continue;
} else {
V_2 -> V_151 [ V_147 ] . V_160 = true ;
}
V_2 -> V_151 [ V_147 ] . V_27 = V_149 ;
V_2 -> V_151 [ V_147 ] . V_158 = ( T_2 ) V_136 [ V_128 ] . V_158 ;
V_2 -> V_151 [ V_147 ] . type = ( T_2 ) V_136 [ V_128 ] . type ;
V_2 -> V_151 [ V_147 ] . V_161 = ( T_2 ) V_136 [ V_128 ] . V_162 ;
V_2 -> V_151 [ V_147 ] . V_163 = V_136 [ V_128 ] . V_164 ;
V_2 -> V_151 [ V_147 ] . V_165 = V_136 [ V_128 ] . V_166 ;
memcpy ( & V_2 -> V_151 [ V_147 ] . V_167 , & V_136 [ V_128 ] . V_167 , V_25 ) ;
V_147 ++ ;
}
if ( ! F_88 ( V_2 ) ) {
for ( V_128 = 0 ; V_128 < V_142 ; V_128 ++ )
V_2 -> V_153 [ V_128 ] . V_41 |= V_168 ;
}
F_7 ( V_136 ) ;
return 0 ;
V_157:
F_7 ( V_2 -> V_153 ) ;
V_2 -> V_153 = NULL ;
V_155:
F_7 ( V_2 -> V_151 ) ;
V_2 -> V_151 = NULL ;
V_150:
F_7 ( V_136 ) ;
return V_26 ;
}
static int
F_92 ( struct V_1 * V_2 )
{
T_2 V_71 ;
int V_26 ;
T_1 V_169 = V_144 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_93 ( V_2 ) ;
if ( V_26 )
goto V_170;
V_71 = V_4 -> V_27 ;
V_169 = F_94 ( V_2 , V_171 ) ;
V_169 = ( V_169 & ~ F_95 ( 0xf , V_71 ) ) |
F_95 ( V_144 , V_71 ) ;
F_96 ( V_2 , V_171 , V_169 ) ;
F_97 ( V_2 ) ;
V_170:
return V_26 ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_172 * V_173 )
{
T_1 V_143 , V_174 ;
V_2 -> V_4 -> V_175 = F_94 ( V_2 ,
V_176 ) ;
F_99 ( V_2 ) ;
V_143 = F_94 ( V_2 , V_171 ) ;
if ( V_143 == V_177 )
V_174 = V_144 ;
else
V_174 = F_100 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_174 == V_178 ) {
V_2 -> V_4 -> V_143 = V_178 ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_175 ) ;
V_2 -> V_179 = & V_180 ;
} else
V_2 -> V_179 = & V_181 ;
}
static void F_101 ( T_1 V_182 , T_6 * V_183 )
{
switch ( V_182 ) {
case V_7 :
* V_183 = V_184 ;
break;
case V_185 :
case V_186 :
case V_187 :
case V_188 :
* V_183 = V_189 ;
break;
default:
* V_183 = 0 ;
}
}
static int F_102 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_111 ;
void T_7 * V_190 = NULL ;
unsigned long V_191 , V_192 = 0 , V_193 ;
V_191 = F_103 ( V_5 , 0 ) ;
F_101 ( V_5 -> V_6 , & V_193 ) ;
if ( V_191 >= V_193 ) {
V_190 = F_104 ( V_5 , 0 ) ;
if ( V_190 == NULL ) {
F_80 ( & V_5 -> V_30 , L_13 ) ;
return - V_110 ;
}
V_192 = V_191 ;
} else {
return - V_110 ;
}
F_68 ( & V_5 -> V_30 , L_14 , ( int ) ( V_191 >> 10 ) ) ;
V_4 -> V_134 = V_190 ;
V_4 -> V_192 = V_192 ;
V_111 = F_105 ( F_106 ( V_4 -> V_27 ) ) ;
F_74 ( V_4 , V_111 ) ;
return 0 ;
}
static bool F_107 ( struct V_1 * V_2 ,
int V_194 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_195 ;
bool V_26 = true ;
V_195 = V_5 -> V_195 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_185 ) {
if ( V_196 [ V_194 ] . V_197 == V_195 &&
V_196 [ V_194 ] . V_198 == V_5 -> V_199 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_108 ( struct V_1 * V_2 , char * V_200 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_128 , V_201 = 0 ;
for ( V_128 = 0 ; V_128 < V_202 ; ++ V_128 ) {
if ( V_196 [ V_128 ] . V_203 == V_5 -> V_203 &&
V_196 [ V_128 ] . V_6 == V_5 -> V_6 &&
F_107 ( V_2 , V_128 ) ) {
V_201 = 1 ;
break;
}
}
if ( ! V_201 )
sprintf ( V_200 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_200 , L_16 , V_2 -> V_24 ,
V_196 [ V_128 ] . V_204 ) ;
}
static void
F_109 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_205 , V_206 , V_207 , V_208 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_209 * V_210 = & V_4 -> V_210 ;
V_208 = V_2 -> V_211 ;
V_205 = F_94 ( V_2 , V_212 ) ;
V_206 = F_94 ( V_2 , V_213 ) ;
V_207 = F_94 ( V_2 , V_214 ) ;
V_2 -> V_211 = F_110 ( V_205 , V_206 , V_207 ) ;
V_51 = F_111 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_143 != V_178 ) {
if ( V_210 -> V_215 == NULL ||
V_2 -> V_211 > V_208 ) {
if ( V_210 -> V_215 )
F_83 ( V_210 -> V_215 ) ;
if ( ! F_112 ( V_2 ) )
F_68 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_68 ( & V_5 -> V_30 , L_19 ,
V_216 , V_205 , V_206 , V_207 ) ;
if ( V_2 -> V_4 -> V_137 == V_141 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_217 = V_218 ;
V_2 -> V_219 = V_220 ;
} else {
V_2 -> V_217 = V_221 ;
V_2 -> V_219 = V_222 ;
}
V_2 -> V_223 = V_224 ;
V_2 -> V_225 = V_224 ;
} else if ( V_2 -> V_4 -> V_137 == V_138 ) {
V_2 -> V_217 = V_226 ;
V_2 -> V_223 = V_227 ;
V_2 -> V_225 = V_227 ;
V_2 -> V_219 = V_228 ;
}
V_2 -> V_4 -> V_105 = ! ! V_119 ;
V_2 -> V_229 = V_230 ;
V_2 -> V_231 = V_232 ;
}
static int
F_113 ( struct V_1 * V_2 )
{
struct V_233 V_234 ;
int V_51 = 0 ;
memset ( & V_234 , 0 , sizeof( struct V_233 ) ) ;
V_51 = F_114 ( V_2 , & V_234 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_235 = ( T_2 ) V_234 . V_236 ;
V_2 -> V_4 -> V_237 = V_234 . V_237 ;
V_2 -> V_4 -> V_238 = V_234 . V_238 ;
V_2 -> V_4 -> V_239 = V_234 . V_239 ;
V_2 -> V_4 -> V_8 = V_234 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_240 ) {
T_1 V_241 ;
V_241 = F_115 ( V_2 , V_242 , & V_51 ) ;
if ( V_51 == - V_110 )
return V_51 ;
V_2 -> V_4 -> V_77 [ 0 ] = V_241 ;
} else {
V_2 -> V_4 -> V_77 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_243 = V_234 . V_243 ;
V_2 -> V_4 -> V_244 = V_234 . V_244 ;
if ( V_2 -> V_4 -> V_8 & V_245 ) {
V_2 -> V_41 |= V_53 ;
V_2 -> V_4 -> V_246 = V_247 ;
V_2 -> V_88 = V_248 ;
V_2 -> V_86 = V_249 ;
F_68 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_246 = V_250 ;
V_2 -> V_88 = V_251 ;
V_2 -> V_86 = V_84 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_116 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
if ( V_253 -> V_254 )
V_2 -> V_41 &= ~ V_255 ;
else
V_2 -> V_41 |= V_255 ;
if ( V_253 -> V_256 ) {
V_2 -> V_257 = V_253 -> V_256 ;
V_2 -> V_258 = V_253 -> V_256 ;
} else {
V_2 -> V_257 = 0 ;
V_2 -> V_258 = 0 ;
}
}
static int
F_117 ( struct V_21 * V_22 , T_5 V_259 , T_3 V_260 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_118 ( V_2 , V_260 , 1 ) ;
if ( V_51 ) {
F_119 ( V_22 ,
L_21 ,
V_260 , V_51 ) ;
return V_51 ;
}
}
F_120 ( V_260 , V_2 -> V_261 ) ;
return 0 ;
}
static int
F_121 ( struct V_21 * V_22 , T_5 V_259 , T_3 V_260 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_118 ( V_2 , V_260 , 0 ) ;
if ( V_51 ) {
F_119 ( V_22 ,
L_22 ,
V_260 , V_51 ) ;
return V_51 ;
}
}
F_122 ( V_22 , V_262 ) ;
F_123 ( V_260 , V_2 -> V_261 ) ;
return 0 ;
}
void F_124 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
V_2 -> V_41 &= ~ ( V_263 | V_42 |
V_264 ) ;
if ( V_253 -> V_265 )
V_2 -> V_41 |= V_263 ;
if ( ! V_253 -> V_266 )
V_2 -> V_41 |= V_42 ;
if ( ! V_253 -> V_267 )
V_2 -> V_41 |= V_264 ;
}
int F_125 ( struct V_1 * V_2 )
{
struct V_252 V_253 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_253 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_126 ( V_2 , & V_253 ) )
return - V_110 ;
F_116 ( V_2 , & V_253 ) ;
F_124 ( V_2 , & V_253 ) ;
F_127 ( V_2 , & V_253 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_62 ( V_2 ) )
return;
V_2 -> V_268 = V_253 -> V_268 ;
V_2 -> V_41 |= V_269 ;
F_128 ( V_22 ) ;
V_2 -> V_41 &= ~ V_269 ;
}
static int
F_129 ( struct V_1 * V_2 )
{
T_1 V_143 , V_174 ;
int V_51 = 0 ;
V_51 = F_113 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_270 )
return 0 ;
V_143 = F_94 ( V_2 , V_171 ) ;
V_174 = F_100 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_143 == V_177 )
V_174 = V_144 ;
else
V_174 = F_100 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_174 == V_144 ) {
V_2 -> V_4 -> V_143 = V_144 ;
V_51 = F_90 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_92 ( V_2 ) ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_175 ) ;
} else if ( V_174 == V_271 ) {
V_2 -> V_4 -> V_143 = V_271 ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_175 ) ;
}
} else {
V_2 -> V_4 -> V_246 = V_250 ;
}
V_2 -> V_41 |= V_270 ;
return V_51 ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_252 V_253 ;
struct V_152 * V_272 ;
T_2 V_128 ;
if ( V_2 -> V_273 )
return 0 ;
for ( V_128 = 0 ; V_128 < V_2 -> V_4 -> V_139 ; V_128 ++ ) {
if ( ! V_2 -> V_151 [ V_128 ] . V_160 )
continue;
memset ( & V_253 , 0 , sizeof( struct V_252 ) ) ;
V_253 . V_27 = V_2 -> V_151 [ V_128 ] . V_27 ;
V_253 . V_266 = V_274 ;
V_253 . V_267 = V_274 ;
if ( F_54 ( V_2 ) ) {
V_253 . V_268 = V_274 ;
if ( F_131 ( V_2 ) )
V_253 . V_268 |= ( V_275 | V_276 ) ;
}
if ( F_132 ( V_2 , & V_253 ) )
return - V_110 ;
V_272 = & V_2 -> V_151 [ V_128 ] ;
V_272 -> V_277 = V_253 . V_256 ;
V_272 -> V_266 = V_253 . V_266 ;
V_272 -> V_265 = V_253 . V_265 ;
V_272 -> V_254 = V_253 . V_254 ;
V_272 -> V_267 = V_253 . V_267 ;
V_272 -> V_268 = V_253 . V_268 ;
}
return 0 ;
}
static int
F_133 ( struct V_1 * V_2 ,
struct V_152 * V_272 , int V_27 )
{
struct V_252 V_253 ;
V_253 . V_143 = V_278 ;
V_253 . V_27 = V_27 ;
V_253 . V_256 = V_272 -> V_277 ;
V_253 . V_266 = V_272 -> V_266 ;
V_253 . V_254 = V_272 -> V_254 ;
V_253 . V_265 = V_272 -> V_265 ;
V_253 . V_268 = V_272 -> V_268 ;
V_253 . V_267 = V_272 -> V_267 ;
if ( F_132 ( V_2 , & V_253 ) )
return - V_110 ;
V_253 . V_143 = V_279 ;
if ( F_132 ( V_2 , & V_253 ) )
return - V_110 ;
return 0 ;
}
int F_134 ( struct V_1 * V_2 )
{
int V_128 , V_51 ;
struct V_152 * V_272 ;
struct V_233 V_234 ;
T_2 V_27 ;
if ( F_54 ( V_2 ) )
if ( ! V_2 -> V_273 )
return 0 ;
for ( V_128 = 0 ; V_128 < V_2 -> V_4 -> V_139 ; V_128 ++ ) {
V_272 = & V_2 -> V_151 [ V_128 ] ;
V_27 = V_272 -> V_27 ;
if ( ! V_2 -> V_151 [ V_128 ] . V_160 )
continue;
memset ( & V_234 , 0 , sizeof( struct V_233 ) ) ;
V_51 = F_114 ( V_2 , & V_234 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_234 . V_280 = V_272 -> V_163 ;
V_234 . V_281 = V_272 -> V_165 ;
V_51 = F_135 ( V_2 , & V_234 ) ;
if ( V_51 )
return V_51 ;
if ( V_272 -> V_282 ) {
V_51 = F_136 ( V_2 ,
V_272 -> V_283 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_133 ( V_2 , V_272 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_2 V_284 = V_285 ;
T_1 V_286 ;
if ( V_2 -> V_4 -> V_143 == V_144 )
return 0 ;
V_286 = F_94 ( V_2 ,
V_287 ) ;
while ( V_286 != V_288 && -- V_284 ) {
F_138 ( 1000 ) ;
V_286 = F_94 ( V_2 ,
V_287 ) ;
}
if ( ! V_284 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_110 ;
}
return 0 ;
}
static int
F_139 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_143 != V_144 )
return 0 ;
V_51 = F_130 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_134 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_140 ( V_2 ) ;
return V_51 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_142 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_289;
if ( V_290 )
F_143 ( V_2 ) ;
else {
V_51 = F_144 ( V_2 ) ;
if ( V_51 )
goto V_291;
V_2 -> V_4 -> V_292 = V_293 ;
}
V_51 = F_145 ( V_2 ) ;
if ( V_51 == 0 )
goto V_289;
V_51 = F_146 ( V_2 ) ;
if ( V_51 )
goto V_291;
V_51 = F_147 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_148 ( V_2 ) ;
F_149 ( V_2 , V_294 , V_295 ) ;
V_289:
V_51 = F_150 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_96 ( V_2 , V_296 , V_297 ) ;
F_151 ( V_2 , 1 ) ;
V_51 = F_129 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_291;
}
V_51 = F_139 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_109 ( V_2 ) ;
V_2 -> V_273 = 0 ;
F_148 ( V_2 ) ;
return 0 ;
V_291:
F_96 ( V_2 , V_296 , V_298 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_148 ( V_2 ) ;
return V_51 ;
}
static int
F_152 ( struct V_1 * V_2 )
{
T_8 V_299 ;
struct V_18 * V_300 ;
struct V_10 * V_11 ;
int V_51 , V_301 , V_302 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_129 == V_303 ) {
if ( F_54 ( V_2 ) )
V_299 = V_304 ;
else
V_299 = V_305 ;
if ( ! F_153 ( V_2 ) )
V_41 |= V_306 ;
} else {
if ( V_2 -> V_41 & V_104 )
V_299 = V_307 ;
else if ( V_2 -> V_41 & V_103 )
V_299 = V_308 ;
else {
V_41 |= V_306 ;
if ( F_54 ( V_2 ) )
V_299 = V_309 ;
else
V_299 = V_310 ;
}
}
V_2 -> V_118 = V_22 -> V_118 ;
if ( V_2 -> V_4 -> V_129 != V_311 ) {
if ( F_54 ( V_2 ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) ) ) {
V_302 = V_2 -> V_92 ;
for ( V_301 = 0 ; V_301 < V_302 ; V_301 ++ ) {
V_300 = & V_15 -> V_19 [ V_301 ] ;
if ( F_54 ( V_2 ) &&
! F_70 ( V_2 ) &&
( V_301 == ( V_302 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_104 ) )
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_28 ) ;
else
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_29 ,
V_22 -> V_200 , V_301 ) ;
} else {
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_30 ,
V_22 -> V_200 , V_301 ) ;
}
V_51 = F_154 ( V_300 -> V_118 , V_299 , V_41 ,
V_300 -> V_200 , V_300 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_54 ( V_2 ) &&
F_70 ( V_2 ) ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) &&
! ( V_2 -> V_41 & V_312 ) ) ) {
V_299 = V_313 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ;
V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
snprintf ( V_11 -> V_200 , sizeof( V_11 -> V_200 ) ,
L_31 , V_22 -> V_200 , V_301 ) ;
V_51 = F_154 ( V_11 -> V_118 , V_299 , V_41 ,
V_11 -> V_200 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_155 ( struct V_1 * V_2 )
{
int V_301 ;
struct V_18 * V_300 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_129 != V_311 ) {
if ( F_54 ( V_2 ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) ) ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_15 -> V_19 [ V_301 ] ;
F_156 ( V_300 -> V_118 , V_300 ) ;
}
}
if ( ( F_62 ( V_2 ) &&
! ( V_2 -> V_41 & V_312 ) ) ||
( F_54 ( V_2 ) &&
F_70 ( V_2 ) ) ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ;
V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
if ( V_11 -> V_118 )
F_156 ( V_11 -> V_118 , V_11 ) ;
}
}
}
}
static void F_157 ( struct V_1 * V_2 )
{
T_1 V_314 = 0 ;
if ( F_54 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_77 [ 0 ] &
V_315 )
V_2 -> V_41 |= V_316 ;
} else {
V_314 = V_2 -> V_4 -> V_8 ;
if ( F_158 ( V_314 ) )
V_2 -> V_41 |= V_316 ;
}
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 ;
V_4 -> V_317 . V_318 = V_319 ;
if ( F_62 ( V_2 ) ) {
V_4 -> V_317 . type = V_320 ;
V_4 -> V_317 . V_321 = V_322 ;
V_4 -> V_317 . V_323 = V_324 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
V_51 = F_160 ( V_2 ) ;
} else {
V_4 -> V_317 . type = V_329 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
V_51 = F_161 ( V_2 ) ;
}
return V_51 ;
}
int F_162 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_301 ;
struct V_330 * V_331 ;
if ( V_2 -> V_332 != V_333 )
return - V_110 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_125 ( V_2 ) )
return - V_110 ;
F_157 ( V_2 ) ;
if ( F_163 ( V_2 ) )
return - V_110 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_231 ; V_301 ++ ) {
V_331 = & V_2 -> V_15 -> V_334 [ V_301 ] ;
F_164 ( V_2 , V_331 , V_301 ) ;
}
F_24 ( V_22 ) ;
F_165 ( V_2 , V_22 -> V_335 ) ;
V_2 -> V_4 -> V_336 = 0 ;
if ( V_2 -> V_92 > 1 )
F_166 ( V_2 , 1 ) ;
F_159 ( V_2 ) ;
if ( V_22 -> V_337 & V_338 )
F_167 ( V_2 , V_339 ) ;
F_120 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_168 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_340 = 0 ;
F_169 ( V_22 ) ;
return 0 ;
}
int F_170 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_171 () ;
if ( F_172 ( V_22 ) )
V_51 = F_162 ( V_2 , V_22 ) ;
F_173 () ;
return V_51 ;
}
void F_174 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_301 ;
if ( V_2 -> V_332 != V_333 )
return;
if ( ! F_175 ( V_45 , & V_2 -> V_46 ) )
return;
F_176 () ;
F_177 ( V_22 ) ;
V_2 -> V_4 -> V_336 = 0 ;
F_178 ( V_22 ) ;
F_179 ( V_2 ) ;
if ( V_2 -> V_341 . V_342 )
F_180 ( V_2 ) ;
F_181 ( V_2 , V_343 ) ;
if ( F_20 ( V_2 ) )
F_182 ( & V_2 -> V_4 -> V_344 -> V_345 ) ;
F_23 ( V_2 ) ;
F_183 ( V_2 ) ;
V_2 -> V_41 &= ~ V_316 ;
F_184 ( V_2 ) ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ )
F_185 ( V_2 , & V_2 -> V_11 [ V_301 ] ) ;
}
void F_186 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_171 () ;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_173 () ;
}
int
F_187 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_332 == V_333 )
return 0 ;
V_51 = F_188 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_189 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_32 ) ;
goto V_346;
}
V_51 = F_190 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_33 ) ;
goto V_347;
}
V_51 = F_152 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_34 ) ;
goto V_348;
}
F_191 ( V_2 ) ;
#ifdef F_192
if ( F_50 ( V_2 ) )
F_193 ( V_22 ) ;
#endif
V_2 -> V_332 = V_333 ;
return 0 ;
V_348:
F_194 ( V_2 ) ;
V_347:
F_195 ( V_2 ) ;
V_346:
F_196 ( V_2 ) ;
return V_51 ;
}
void F_197 ( struct V_1 * V_2 )
{
if ( V_2 -> V_332 != V_333 )
return;
F_198 ( V_2 ) ;
F_194 ( V_2 ) ;
F_199 ( V_2 ) ;
F_155 ( V_2 ) ;
F_196 ( V_2 ) ;
F_195 ( V_2 ) ;
V_2 -> V_332 = 0 ;
}
void F_200 ( struct V_21 * V_22 , int V_92 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_300 ;
int V_90 = V_2 -> V_90 ;
int V_301 ;
F_123 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_129 == V_303 ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_2 -> V_15 -> V_19 [ V_301 ] ;
F_201 ( V_2 , V_300 ) ;
}
}
F_183 ( V_2 ) ;
F_197 ( V_2 ) ;
V_2 -> V_4 -> V_129 = 0 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_90 = V_90 ;
if ( F_187 ( V_2 ) )
goto V_349;
if ( F_172 ( V_22 ) )
F_162 ( V_2 , V_22 ) ;
V_349:
F_25 ( V_22 ) ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_291;
}
if ( F_62 ( V_2 ) ) {
V_4 -> V_317 . type = V_320 ;
V_4 -> V_317 . V_321 = V_322 ;
V_4 -> V_317 . V_323 = V_324 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
} else {
V_4 -> V_317 . type = V_329 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
}
memset ( & V_2 -> V_350 , 0 , sizeof( V_2 -> V_350 ) ) ;
V_291:
return V_51 ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = & V_2 -> V_4 -> V_210 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_210 -> V_215 ) {
F_83 ( V_210 -> V_215 ) ;
V_210 -> V_215 = NULL ;
}
if ( V_210 -> V_351 ) {
F_204 ( & V_2 -> V_5 -> V_30 , V_352 ,
V_210 -> V_351 , V_210 -> V_353 ) ;
V_210 -> V_351 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_354 . V_355 ) ;
V_2 -> V_4 -> V_210 . V_215 = NULL ;
}
int F_205 ( struct V_21 * V_22 , int V_356 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_300 ;
struct V_330 * V_331 ;
int V_301 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
V_2 -> V_92 = V_109 ;
V_2 -> V_4 -> V_129 = V_356 ;
V_2 -> V_4 -> V_336 = 0 ;
V_26 = F_187 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_163 ( V_2 ) ;
if ( V_26 ) {
F_197 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_301 = 0 ; V_301 < V_2 -> V_231 ; V_301 ++ ) {
V_331 = & V_2 -> V_15 -> V_334 [ V_301 ] ;
F_164 ( V_2 , V_331 , V_301 ) ;
}
if ( V_2 -> V_4 -> V_129 == V_303 ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_2 -> V_15 -> V_19 [ V_301 ] ;
F_206 ( V_2 , V_300 ) ;
}
}
if ( V_2 -> V_4 -> V_129 == V_311 ) {
V_2 -> V_4 -> V_357 = 0 ;
F_168 ( V_2 , 1 ) ;
}
F_120 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_207 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_62 , & V_2 -> V_46 ) )
return - V_358 ;
F_22 ( V_22 ) ;
F_186 ( V_2 , V_22 ) ;
F_170 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
F_65 ( V_2 -> V_22 , L_35 , V_54 ) ;
return 0 ;
}
int
F_208 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_62 , & V_2 -> V_46 ) )
return - V_358 ;
if ( V_2 -> V_332 == V_333 ) {
F_22 ( V_22 ) ;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( ! V_51 ) {
F_162 ( V_2 , V_22 ) ;
F_122 ( V_22 , V_359 ) ;
}
}
F_25 ( V_22 ) ;
}
F_123 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_360 = V_4 -> V_139 ;
T_3 V_16 ;
V_4 -> V_361 = V_362 ;
if ( V_360 <= 2 )
V_16 = ( V_363 - V_362 ) /
V_360 ;
else
V_16 = ( V_364 - V_362 ) /
V_360 ;
V_4 -> V_55 = V_16 ;
}
static int F_210 ( struct V_1 * V_2 ,
T_2 V_365 , T_2 V_366 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 = 0 ;
if ( V_365 ) {
V_51 = F_211 ( V_22 , V_365 ) ;
if ( V_51 ) {
F_119 ( V_22 , L_36 ,
V_365 ) ;
return V_51 ;
}
}
if ( V_366 ) {
V_51 = F_212 ( V_22 , V_366 ) ;
if ( V_51 )
F_119 ( V_22 , L_37 ,
V_366 ) ;
}
return V_51 ;
}
int
F_213 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_367 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_368 = 1 ;
V_2 -> V_4 -> V_369 = 0 ;
F_214 ( V_2 ) ;
V_22 -> V_370 = & V_371 ;
V_22 -> V_372 = V_373 * V_374 ;
F_215 ( V_22 , V_22 -> V_335 ) ;
V_22 -> V_375 = ( F_20 ( V_2 ) ) ?
& V_376 : & V_377 ;
V_22 -> V_337 |= ( V_378 | V_379 | V_380 |
V_381 | V_382 |
V_383 ) ;
V_22 -> V_384 |= ( V_378 | V_379 |
V_381 ) ;
if ( F_131 ( V_2 ) ) {
V_22 -> V_337 |= ( V_385 | V_386 ) ;
V_22 -> V_384 |= ( V_385 | V_386 ) ;
}
if ( V_367 ) {
V_22 -> V_337 |= V_387 ;
V_22 -> V_384 |= V_387 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_337 |= ( V_388 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_337 |= V_389 ;
if ( V_2 -> V_4 -> V_8 & V_390 )
V_22 -> V_337 |= V_338 ;
if ( F_216 ( V_2 ) ) {
V_22 -> V_337 |= V_391 ;
V_22 -> V_392 = V_379 |
V_391 |
V_385 |
V_386 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_392 |= V_380 ;
V_22 -> V_393 = V_22 -> V_337 ;
V_22 -> V_394 |= V_395 ;
V_22 -> V_118 = V_2 -> V_98 [ 0 ] . V_94 ;
V_51 = F_210 ( V_2 , V_2 -> V_90 ,
V_2 -> V_92 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_217 ( V_22 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_38 ) ;
return V_51 ;
}
F_218 ( V_2 -> V_396 ) ;
return 0 ;
}
static int F_219 ( struct V_23 * V_5 , int * V_367 )
{
if ( ! F_220 ( V_5 , F_221 ( 64 ) ) &&
! F_222 ( V_5 , F_221 ( 64 ) ) )
* V_367 = 1 ;
else if ( ! F_220 ( V_5 , F_221 ( 32 ) ) &&
! F_222 ( V_5 , F_221 ( 32 ) ) )
* V_367 = 0 ;
else {
F_80 ( & V_5 -> V_30 , L_39 ) ;
return - V_110 ;
}
return 0 ;
}
void F_223 ( struct V_1 * V_2 )
{
int V_301 ;
struct V_10 * V_11 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
if ( V_11 && V_11 -> V_397 != NULL ) {
F_83 ( V_11 -> V_397 ) ;
V_11 -> V_397 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_224 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_301 , V_94 , V_194 ;
struct V_10 * V_11 ;
struct V_398 * V_397 ;
V_11 = F_63 ( V_2 -> V_90 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
V_11 -> V_399 = V_2 -> V_229 ;
V_11 -> V_400 = F_225 ( V_22 , V_301 ) ;
V_397 = F_78 ( F_226 ( V_11 ) ) ;
if ( V_397 == NULL ) {
F_223 ( V_2 ) ;
return - V_56 ;
}
memset ( V_397 , 0 , F_226 ( V_11 ) ) ;
V_11 -> V_397 = V_397 ;
F_227 ( & V_11 -> V_401 ) ;
}
if ( F_62 ( V_2 ) ||
( F_54 ( V_2 ) && F_70 ( V_2 ) ) ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_104 ) {
V_194 = V_2 -> V_92 + V_301 ;
V_94 = V_2 -> V_98 [ V_194 ] . V_94 ;
V_11 -> V_118 = V_94 ;
}
}
}
return 0 ;
}
void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_402 = 0 ;
if ( F_54 ( V_2 ) )
V_402 = V_403 ;
else if ( F_62 ( V_2 ) )
V_402 = V_404 ;
if ( V_4 -> V_77 [ 0 ] & V_405 )
F_229 ( V_2 , V_402 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
F_93 ( V_2 ) ;
F_97 ( V_2 ) ;
}
static int
F_231 ( struct V_23 * V_5 , const struct V_172 * V_173 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_367 = - 1 ;
char V_406 [ V_407 + 19 ] ;
V_51 = F_232 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_233 ( V_5 , 0 ) & V_408 ) ) {
V_51 = - V_409 ;
goto V_410;
}
V_51 = F_219 ( V_5 , & V_367 ) ;
if ( V_51 )
goto V_410;
V_51 = F_234 ( V_5 , V_411 ) ;
if ( V_51 )
goto V_410;
F_235 ( V_5 ) ;
F_236 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_412;
}
switch ( V_173 -> V_6 ) {
case V_7 :
V_4 -> V_413 = & V_414 ;
V_4 -> V_415 = ( T_1 * ) V_416 ;
break;
case V_185 :
case V_186 :
F_237 ( V_4 ) ;
break;
case V_187 :
case V_188 :
F_238 ( V_4 ) ;
break;
default:
goto V_417;
}
V_51 = F_102 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_417;
V_22 = F_239 ( sizeof( struct V_1 ) ,
V_418 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_419;
}
F_240 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_420 = F_241 ( L_28 ) ;
if ( V_2 -> V_420 == NULL ) {
V_51 = - V_56 ;
F_80 ( & V_5 -> V_30 , L_40 ) ;
goto V_421;
}
V_51 = F_202 ( V_2 ) ;
if ( V_51 )
goto V_422;
V_2 -> V_423 = V_424 ;
V_4 -> V_425 = V_5 -> V_426 ;
V_4 -> V_145 = F_242 ( V_2 ) ;
if ( V_427 == V_428 )
V_2 -> V_52 = true ;
else if ( V_427 == V_429 )
V_2 -> V_430 = true ;
F_243 ( & V_2 -> V_4 -> V_431 ) ;
F_244 ( & V_2 -> V_4 -> V_432 ) ;
F_245 ( & V_2 -> V_433 ) ;
F_246 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
F_98 ( V_2 , V_173 ) ;
V_2 -> V_434 = V_2 -> V_4 -> V_27 ;
F_230 ( V_2 ) ;
V_51 = F_247 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_435;
}
if ( V_2 -> V_4 -> V_105 ) {
if ( F_53 ( V_2 ) == 1 )
F_59 ( V_2 ,
V_109 ) ;
else
F_59 ( V_2 ,
V_436 ) ;
F_60 ( V_2 ,
V_437 ) ;
} else {
F_59 ( V_2 , V_109 ) ;
F_60 ( V_2 , V_109 ) ;
}
V_51 = F_248 ( V_2 ) ;
if ( V_51 )
goto V_348;
V_2 -> V_41 |= V_438 ;
} else if ( F_62 ( V_2 ) ) {
F_249 ( V_2 , V_173 ) ;
V_2 -> V_434 = V_2 -> V_4 -> V_27 ;
V_51 = F_250 ( V_2 , V_367 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_439 :
F_80 ( & V_5 -> V_30 , L_43 ) ;
F_80 ( & V_5 -> V_30 , L_44 ) ;
goto V_348;
case - V_56 :
F_80 ( & V_5 -> V_30 , L_45 ) ;
goto V_348;
case - V_43 :
F_80 ( & V_5 -> V_30 , L_46 ) ;
goto V_348;
default:
F_80 ( & V_5 -> V_30 , L_47 ) ;
goto V_435;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_80 ( & V_5 -> V_30 ,
L_48 , V_54 ) ;
goto V_348;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_251 ( V_2 ) ;
if ( V_2 -> V_434 == 0 ) {
F_108 ( V_2 , V_406 ) ;
F_37 ( L_50 ,
F_252 ( V_440 ) ,
V_406 , V_2 -> V_4 -> V_425 ) ;
}
if ( F_62 ( V_2 ) && ! V_119 &&
! ! V_115 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_54 ( V_2 ) ) {
F_253 ( V_2 -> V_396 ) ;
F_254 ( V_2 -> V_396 ) ;
V_51 = F_255 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_52 ) ;
goto V_441;
}
}
V_51 = F_86 ( V_2 ) ;
if ( V_51 )
goto V_442;
V_51 = F_213 ( V_2 , V_22 , V_367 ) ;
if ( V_51 )
goto V_442;
if ( V_2 -> V_434 == 0 )
F_228 ( V_2 ) ;
F_256 ( V_5 , V_2 ) ;
if ( F_54 ( V_2 ) )
F_257 ( V_2 , V_443 ,
V_444 ) ;
switch ( V_2 -> V_4 -> V_137 ) {
case V_138 :
F_68 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_200 ) ;
break;
case V_141 :
F_68 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_200 ) ;
break;
}
if ( V_2 -> V_430 )
F_258 ( V_2 ) ;
F_259 ( V_2 ) ;
F_260 ( V_2 ) ;
return 0 ;
V_442:
if ( F_62 ( V_2 ) )
F_261 ( V_2 ) ;
V_441:
F_81 ( V_2 ) ;
F_262 ( V_2 ) ;
F_263 ( V_2 , 0 ) ;
V_348:
F_203 ( V_2 ) ;
V_422:
F_264 ( V_2 -> V_420 ) ;
V_421:
F_265 ( V_22 ) ;
V_419:
F_84 ( V_4 ) ;
V_417:
F_7 ( V_4 ) ;
V_412:
F_266 ( V_5 ) ;
V_410:
F_267 ( V_5 ) ;
return V_51 ;
V_435:
F_120 ( V_445 , & V_2 -> V_46 ) ;
V_22 -> V_370 = & V_446 ;
V_22 -> V_375 = & V_447 ;
V_4 -> V_137 = V_141 ;
if ( F_62 ( V_2 ) )
V_2 -> V_117 = NULL ;
else
V_4 -> V_448 = V_449 ;
V_51 = F_217 ( V_22 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_55 ) ;
F_263 ( V_2 , 0 ) ;
goto V_348;
}
F_256 ( V_5 , V_2 ) ;
F_259 ( V_2 ) ;
return 0 ;
}
static void F_268 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_269 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_262 ( V_2 ) ;
F_270 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_271 ( V_22 ) ;
F_272 ( V_2 ) ;
if ( F_62 ( V_2 ) ) {
F_273 ( V_2 , 0 ) ;
F_47 ( & V_2 -> V_450 ) ;
F_261 ( V_2 ) ;
F_274 ( V_2 ) ;
F_275 ( V_4 -> V_451 ) ;
F_7 ( V_4 -> V_452 ) ;
}
F_276 ( V_2 -> V_396 ) ;
F_197 ( V_2 ) ;
if ( V_2 -> V_151 != NULL )
F_7 ( V_2 -> V_151 ) ;
if ( V_2 -> V_153 != NULL )
F_7 ( V_2 -> V_153 ) ;
if ( F_54 ( V_2 ) )
F_263 ( V_2 , 0 ) ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
F_277 ( V_2 ) ;
F_81 ( V_2 ) ;
F_278 ( V_2 ) ;
F_279 ( V_2 ) ;
F_84 ( V_2 -> V_4 ) ;
F_148 ( V_2 ) ;
F_280 ( V_5 ) ;
F_266 ( V_5 ) ;
F_267 ( V_5 ) ;
if ( V_2 -> V_420 ) {
F_264 ( V_2 -> V_420 ) ;
V_2 -> V_420 = NULL ;
}
F_203 ( V_2 ) ;
F_7 ( V_4 ) ;
F_265 ( V_22 ) ;
}
static void F_281 ( struct V_23 * V_5 )
{
if ( F_282 ( V_5 ) )
return;
F_267 ( V_5 ) ;
}
static int F_283 ( struct V_23 * V_5 , T_9 V_46 )
{
int V_453 ;
V_453 = F_282 ( V_5 ) ;
if ( V_453 )
return V_453 ;
F_284 ( V_5 , F_285 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_286 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
int V_51 ;
V_51 = F_232 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_284 ( V_5 , V_454 ) ;
F_235 ( V_5 ) ;
F_287 ( V_5 ) ;
return F_288 ( V_2 ) ;
}
static int F_289 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_21 ( V_445 , & V_2 -> V_46 ) ) {
F_119 ( V_22 , L_56 ,
V_54 ) ;
return - V_110 ;
}
F_177 ( V_22 ) ;
V_51 = F_187 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_162 ( V_2 , V_22 ) ;
if ( V_51 )
F_197 ( V_2 ) ;
return V_51 ;
}
static int F_290 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_174 ( V_2 , V_22 ) ;
return 0 ;
}
void F_258 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_128 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_455 = 0 ;
T_3 V_148 = 0 ;
if ( V_2 -> V_341 . V_456 && V_2 -> V_341 . V_457 )
return;
V_148 = V_2 -> V_4 -> V_139 ;
F_227 ( & V_2 -> V_458 ) ;
F_227 ( & V_2 -> V_459 ) ;
if ( F_20 ( V_2 ) ) {
V_455 = V_460 - 1 ;
V_2 -> V_341 . V_461 = V_462 ;
} else if ( F_54 ( V_2 ) ) {
V_455 = V_364 ;
V_2 -> V_341 . V_461 = V_463 ;
} else {
V_455 = V_464 ;
V_2 -> V_341 . V_461 = V_465 ;
}
V_34 = F_63 ( V_2 -> V_341 . V_461 ,
sizeof( struct V_466 ) , V_467 ) ;
if ( ! V_34 )
return;
V_2 -> V_341 . V_456 = ( V_455 / V_148 ) ;
V_2 -> V_341 . V_457 = V_34 ;
F_65 ( V_22 , L_57 ,
V_148 , V_2 -> V_341 . V_456 ) ;
for ( V_128 = 0 ; V_128 < V_2 -> V_341 . V_461 ; V_128 ++ )
F_291 ( & V_2 -> V_341 . V_457 [ V_128 ] ) ;
V_2 -> V_468 . V_461 = V_2 -> V_341 . V_461 ;
V_34 = F_63 ( V_2 -> V_468 . V_461 ,
sizeof( struct V_466 ) , V_467 ) ;
if ( ! V_34 )
return;
V_2 -> V_468 . V_456 = ( V_455 / V_148 ) ;
V_2 -> V_468 . V_457 = V_34 ;
for ( V_128 = 0 ; V_128 < V_2 -> V_468 . V_461 ; V_128 ++ )
F_291 ( & V_2 -> V_468 . V_457 [ V_128 ] ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
if ( V_2 -> V_341 . V_456 && V_2 -> V_341 . V_457 )
F_7 ( V_2 -> V_341 . V_457 ) ;
V_2 -> V_341 . V_457 = NULL ;
V_2 -> V_341 . V_456 = 0 ;
if ( V_2 -> V_468 . V_456 && V_2 -> V_468 . V_457 )
F_7 ( V_2 -> V_468 . V_457 ) ;
V_2 -> V_468 . V_456 = 0 ;
V_2 -> V_468 . V_457 = NULL ;
}
int F_292 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_469 , V_470 , V_241 = 0 ;
int V_471 = 0 ;
if ( F_62 ( V_2 ) )
V_241 = F_293 ( V_2 -> V_4 , V_472 ) ;
if ( F_54 ( V_2 ) )
V_241 = F_94 ( V_2 , V_473 ) ;
V_469 = F_294 ( V_241 ) ;
V_470 = F_295 ( V_241 ) ;
if ( V_469 == V_474 ) {
F_80 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_470 ) ;
V_471 = 1 ;
} else if ( V_469 == V_475 ) {
if ( V_2 -> V_4 -> V_241 == V_476 ) {
F_80 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_470 ) ;
}
} else {
if ( V_2 -> V_4 -> V_241 == V_475 ) {
F_68 ( & V_22 -> V_30 ,
L_63
L_64 , V_470 ) ;
}
}
V_2 -> V_4 -> V_241 = V_469 ;
return V_471 ;
}
static inline void F_296 ( struct V_10 * V_11 )
{
int V_128 ;
struct V_477 * V_478 ;
for ( V_128 = 0 ; V_128 < V_11 -> V_399 ; V_128 ++ ) {
V_478 = & V_11 -> V_479 [ V_128 ] ;
F_37 ( L_65 , V_128 ) ;
F_297 ( V_480 , L_66 , V_481 , 16 , 1 ,
& V_11 -> V_479 [ V_128 ] ,
sizeof( struct V_477 ) , true ) ;
}
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_10 * V_11 ;
int V_301 ;
if ( ! V_22 || ! F_172 ( V_22 ) )
return;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
F_65 ( V_22 , L_67 ,
V_301 , V_11 -> V_482 ) ;
F_65 ( V_22 ,
L_68 ,
V_11 -> V_483 . V_484 ,
V_11 -> V_483 . V_485 ,
V_11 -> V_483 . V_486 ,
V_11 -> V_483 . V_487 ) ;
if ( V_11 -> V_488 )
F_65 ( V_22 , L_69 ,
F_299 ( V_11 -> V_488 ) ) ;
F_65 ( V_22 ,
L_70 ,
F_299 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_489 ,
F_300 ( * ( V_11 -> V_490 ) ) ) ;
F_65 ( V_22 , L_71 ,
V_11 -> V_399 , F_301 ( V_11 ) ) ;
if ( F_302 ( V_2 -> V_4 ) )
F_296 ( V_11 ) ;
}
}
static void F_303 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return;
if ( ++ V_2 -> V_491 >= V_492 ) {
F_65 ( V_22 , L_72 ) ;
if ( F_54 ( V_2 ) )
V_2 -> V_273 = 1 ;
else if ( F_62 ( V_2 ) )
F_304 ( V_2 ,
V_493 ) ;
} else {
F_65 ( V_22 , L_73 ) ;
F_298 ( V_2 ) ;
V_2 -> V_4 -> V_340 = 1 ;
}
}
static struct V_494 * F_305 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_494 * V_350 = & V_22 -> V_350 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_306 ( V_2 ) ;
V_350 -> V_327 = V_2 -> V_350 . V_495 + V_2 -> V_350 . V_496 ;
V_350 -> V_323 = V_2 -> V_350 . V_497 ;
V_350 -> V_498 = V_2 -> V_350 . V_499 + V_2 -> V_350 . V_500 ;
V_350 -> V_501 = V_2 -> V_350 . V_502 ;
V_350 -> V_503 = V_2 -> V_350 . V_504 ;
V_350 -> V_505 = V_2 -> V_350 . V_506 ;
return V_350 ;
}
static T_10 F_307 ( struct V_1 * V_2 )
{
T_1 V_507 ;
V_507 = F_299 ( V_2 -> V_123 ) ;
if ( ! ( V_507 & V_2 -> V_4 -> V_121 ) )
return V_508 ;
V_507 = F_299 ( V_2 -> V_125 ) ;
if ( ! F_308 ( V_507 ) )
return V_508 ;
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
F_299 ( V_2 -> V_123 ) ;
F_299 ( V_2 -> V_123 ) ;
return V_509 ;
}
static T_10 V_304 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
if ( V_2 -> V_41 & V_104 )
goto V_510;
else if ( V_2 -> V_41 & V_103 ) {
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
goto V_510;
}
if ( F_309 ( V_2 ) == V_508 )
return V_508 ;
V_510:
V_2 -> V_4 -> V_511 ++ ;
F_206 ( V_2 , V_300 ) ;
return V_509 ;
}
static T_10 V_309 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
if ( F_309 ( V_2 ) == V_508 )
return V_508 ;
F_310 ( & V_300 -> V_512 ) ;
return V_509 ;
}
static T_10 V_308 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
F_310 ( & V_300 -> V_512 ) ;
return V_509 ;
}
static T_10 V_307 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
F_310 ( & V_300 -> V_512 ) ;
return V_509 ;
}
static T_10 V_313 ( int V_118 , void * V_169 )
{
struct V_10 * V_11 = V_169 ;
F_310 ( & V_11 -> V_512 ) ;
return V_509 ;
}
static void F_311 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_300 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_301 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_15 -> V_19 [ V_301 ] ;
F_201 ( V_2 , V_300 ) ;
F_310 ( & V_300 -> V_512 ) ;
}
if ( V_2 -> V_41 & V_104 ) {
if ( ( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_312 ) ) ||
( F_54 ( V_2 ) &&
! F_70 ( V_2 ) ) )
return;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
F_312 ( V_2 , V_11 ) ;
F_310 ( & V_11 -> V_512 ) ;
}
}
}
static void
F_151 ( struct V_1 * V_2 , T_2 V_513 )
{
T_1 V_514 ;
V_514 = V_2 -> V_434 & 0xf ;
V_514 |= V_513 << 7 ;
V_514 |= ( V_424 - V_2 -> V_423 ) << 8 ;
F_96 ( V_2 , V_515 , V_514 ) ;
V_2 -> V_423 = V_424 ;
}
static int
F_313 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_514 ;
F_314 ( V_46 != V_516 &&
V_46 != V_517 ) ;
if ( F_93 ( V_2 ) )
return - V_110 ;
V_514 = F_94 ( V_2 , V_518 ) ;
if ( V_46 == V_516 )
F_315 ( V_514 , V_2 -> V_434 ) ;
else if ( V_46 == V_517 )
F_316 ( V_514 , V_2 -> V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int
F_317 ( struct V_1 * V_2 )
{
T_1 V_514 ;
if ( F_93 ( V_2 ) )
return - V_358 ;
V_514 = F_94 ( V_2 , V_518 ) ;
F_318 ( V_514 , V_2 -> V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
void F_263 ( struct V_1 * V_2 , T_2 V_519 )
{
T_1 V_514 ;
if ( F_93 ( V_2 ) )
goto V_51;
V_514 = F_94 ( V_2 , V_520 ) ;
F_319 ( V_514 , V_2 -> V_434 ) ;
F_96 ( V_2 , V_520 , V_514 ) ;
if ( V_519 ) {
F_96 ( V_2 , V_296 ,
V_298 ) ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_74 ) ;
} else if ( ! ( V_514 & 0x11111111 ) )
F_96 ( V_2 , V_296 ,
V_521 ) ;
V_514 = F_94 ( V_2 , V_518 ) ;
F_318 ( V_514 , V_2 -> V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
F_97 ( V_2 ) ;
V_51:
V_2 -> V_522 = 0 ;
V_2 -> V_41 &= ~ V_523 ;
F_123 ( V_524 , & V_2 -> V_46 ) ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
}
static int
F_320 ( struct V_1 * V_2 )
{
int V_525 , V_46 , V_526 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_94 ( V_2 , V_518 ) ;
V_525 = F_94 ( V_2 , V_520 ) ;
if ( V_2 -> V_41 & V_527 ) {
V_526 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_525 = V_525 & V_526 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_525 & 0x11111111 ) ) ||
( ( V_525 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_321 ( struct V_1 * V_2 )
{
T_1 V_514 = F_94 ( V_2 , V_528 ) ;
if ( V_514 != V_529 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_75
L_76 , V_529 , V_514 ) ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
T_1 V_514 , V_530 ;
T_2 V_531 = V_2 -> V_531 ;
T_2 V_434 = V_2 -> V_434 ;
T_2 V_26 ;
if ( F_175 ( V_524 , & V_2 -> V_46 ) )
return 1 ;
if ( F_93 ( V_2 ) )
return - 1 ;
V_514 = F_94 ( V_2 , V_520 ) ;
if ( ! ( V_514 & ( 1 << ( V_434 * 4 ) ) ) ) {
F_322 ( V_514 , V_434 ) ;
F_96 ( V_2 , V_520 , V_514 ) ;
}
V_530 = F_94 ( V_2 , V_296 ) ;
F_323 ( V_2 , V_532 , L_77 , V_530 ) ;
switch ( V_530 ) {
case V_521 :
F_96 ( V_2 , V_296 ,
V_533 ) ;
F_96 ( V_2 , V_528 ,
V_529 ) ;
F_151 ( V_2 , 0 ) ;
F_97 ( V_2 ) ;
return 1 ;
case V_297 :
V_26 = F_321 ( V_2 ) ;
F_97 ( V_2 ) ;
return V_26 ;
case V_516 :
V_514 = F_94 ( V_2 , V_518 ) ;
F_315 ( V_514 , V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
break;
case V_517 :
V_514 = F_94 ( V_2 , V_518 ) ;
F_316 ( V_514 , V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
break;
case V_298 :
F_80 ( & V_2 -> V_5 -> V_30 , L_78 ) ;
F_97 ( V_2 ) ;
return - 1 ;
case V_533 :
case V_534 :
break;
}
F_97 ( V_2 ) ;
do {
F_138 ( 1000 ) ;
V_530 = F_94 ( V_2 , V_296 ) ;
if ( V_530 == V_534 )
continue;
} while ( ( V_530 != V_297 ) && -- V_531 );
if ( ! V_531 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_79 ) ;
return - 1 ;
}
if ( F_93 ( V_2 ) )
return - 1 ;
V_514 = F_94 ( V_2 , V_518 ) ;
F_318 ( V_514 , V_434 ) ;
F_96 ( V_2 , V_518 , V_514 ) ;
V_26 = F_321 ( V_2 ) ;
F_97 ( V_2 ) ;
return V_26 ;
}
static void
F_324 ( struct V_535 * V_64 )
{
struct V_1 * V_2 = F_325 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
T_1 V_536 = 0xf ;
T_1 V_514 ;
if ( F_93 ( V_2 ) )
goto V_537;
V_536 = F_94 ( V_2 , V_296 ) ;
if ( V_536 == V_534 ||
V_536 == V_517 ) {
F_97 ( V_2 ) ;
F_257 ( V_2 , F_324 ,
V_444 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_143 == V_178 ) {
F_97 ( V_2 ) ;
goto V_538;
}
if ( V_536 == V_533 ||
V_536 == V_297 ) {
F_68 ( & V_2 -> V_5 -> V_30 , L_80
L_81 ) ;
goto V_539;
}
if ( V_2 -> V_540 ++ > V_2 -> V_541 ) {
F_68 ( & V_2 -> V_5 -> V_30 , L_82 ,
V_2 -> V_541 ) ;
goto V_539;
}
if ( ! F_320 ( V_2 ) ) {
V_539:
V_536 = F_94 ( V_2 , V_296 ) ;
if ( V_536 == V_516 ) {
F_96 ( V_2 , V_296 ,
V_533 ) ;
F_120 ( V_524 , & V_2 -> V_46 ) ;
F_323 ( V_2 , V_542 , L_83 ) ;
F_151 ( V_2 , 0 ) ;
V_514 = F_94 ( V_2 ,
V_518 ) ;
F_315 ( V_514 , V_2 -> V_434 ) ;
F_96 ( V_2 ,
V_518 , V_514 ) ;
}
F_97 ( V_2 ) ;
F_171 () ;
if ( F_326 ( V_2 ) &&
( V_2 -> V_41 & V_527 ) ) {
F_323 ( V_2 , V_542 , L_84 ) ;
F_327 ( V_2 ) ;
V_2 -> V_41 |= V_523 ;
}
F_173 () ;
V_2 -> V_41 &= ~ V_527 ;
if ( ! V_2 -> V_179 -> V_543 ( V_2 ) ) {
F_257 ( V_2 , V_544 , 0 ) ;
V_2 -> V_540 = 0 ;
return;
}
goto V_537;
}
F_97 ( V_2 ) ;
V_538:
V_536 = F_94 ( V_2 , V_296 ) ;
F_323 ( V_2 , V_532 , L_85 , V_536 ) ;
switch ( V_536 ) {
case V_297 :
if ( ! F_247 ( V_2 ) ) {
F_257 ( V_2 , V_544 , 0 ) ;
V_2 -> V_540 = 0 ;
return;
}
case V_298 :
break;
default:
F_257 ( V_2 ,
F_324 , V_444 ) ;
return;
}
V_537:
F_80 ( & V_2 -> V_5 -> V_30 , L_86
L_87 , V_536 , V_2 -> V_540 ) ;
F_25 ( V_2 -> V_22 ) ;
F_263 ( V_2 , 0 ) ;
}
static void
F_328 ( struct V_535 * V_64 )
{
struct V_1 * V_2 = F_325 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_507 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_536 == V_517 ) {
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
} else
F_186 ( V_2 , V_22 ) ;
V_507 = F_94 ( V_2 , V_545 ) ;
if ( V_507 & V_546 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_88 ,
V_507 ) ;
if ( F_329 ( V_507 ) == V_547 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_89
L_90 ) ;
F_80 ( & V_2 -> V_5 -> V_30 ,
L_91 ) ;
}
goto V_537;
}
if ( V_2 -> V_4 -> V_241 == V_474 ) {
F_80 ( & V_2 -> V_5 -> V_30 , L_92 ,
V_2 -> V_4 -> V_241 ) ;
goto V_537;
}
if ( ! ( V_2 -> V_41 & V_527 ) ) {
if ( F_313 ( V_2 , V_2 -> V_536 ) ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_93
L_94 ) ;
goto V_537;
}
}
V_2 -> V_540 = 0 ;
F_257 ( V_2 , F_324 , V_444 ) ;
return;
V_537:
F_25 ( V_22 ) ;
F_263 ( V_2 , 1 ) ;
}
static void
F_330 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_94 ( V_2 , V_287 ) ;
if ( V_46 == V_548 )
return;
if ( F_93 ( V_2 ) )
return;
F_96 ( V_2 , V_287 ,
V_548 ) ;
F_97 ( V_2 ) ;
}
static void F_331 ( struct V_1 * V_2 ,
T_1 V_549 )
{
T_1 V_46 , V_550 = 0 , V_551 = 0 ;
F_332 ( V_550 ) ;
F_333 ( V_550 ) ;
F_149 ( V_2 , V_552 , V_550 ) ;
F_334 ( V_551 ) ;
F_335 ( V_551 ) ;
F_336 ( V_551 ) ;
F_337 ( V_551 ) ;
F_149 ( V_2 , V_553 , V_551 ) ;
F_68 ( & V_2 -> V_5 -> V_30 , L_95
L_96 ) ;
V_2 -> V_273 = 1 ;
if ( F_93 ( V_2 ) )
return;
V_46 = F_94 ( V_2 , V_296 ) ;
if ( F_21 ( V_445 , & V_2 -> V_46 ) ) {
F_119 ( V_2 -> V_22 , L_56 ,
V_54 ) ;
F_97 ( V_2 ) ;
return;
}
if ( V_46 == V_297 ) {
F_96 ( V_2 , V_296 ,
V_516 ) ;
V_2 -> V_41 |= V_527 ;
F_323 ( V_2 , V_542 , L_97 ) ;
F_151 ( V_2 , 0 ) ;
}
F_96 ( V_2 , V_287 ,
V_548 ) ;
F_97 ( V_2 ) ;
}
static void
F_140 ( struct V_1 * V_2 )
{
if ( F_93 ( V_2 ) )
return;
F_96 ( V_2 , V_287 ,
V_288 ) ;
F_323 ( V_2 , V_542 , L_98 ) ;
F_97 ( V_2 ) ;
}
void F_257 ( struct V_1 * V_2 ,
T_11 V_65 , int V_554 )
{
if ( F_21 ( V_555 , & V_2 -> V_46 ) )
return;
F_338 ( & V_2 -> V_63 , V_65 ) ;
F_339 ( V_2 -> V_420 , & V_2 -> V_63 ,
F_340 ( V_554 ) ) ;
}
static void
V_544 ( struct V_535 * V_64 )
{
struct V_1 * V_2 = F_325 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_286 ;
if ( V_2 -> V_4 -> V_143 != V_144 ) {
V_286 = F_94 ( V_2 ,
V_287 ) ;
if ( V_2 -> V_540 ++ > V_285 )
F_263 ( V_2 , 0 ) ;
else if ( V_286 != V_288 )
F_257 ( V_2 , V_544 ,
V_444 ) ;
else
goto V_556;
F_323 ( V_2 , V_542 , L_99 ) ;
return;
}
V_556:
F_254 ( V_2 -> V_396 ) ;
if ( F_172 ( V_22 ) ) {
if ( F_170 ( V_2 , V_22 ) )
goto V_510;
F_122 ( V_22 , V_359 ) ;
}
V_510:
F_25 ( V_22 ) ;
V_2 -> V_522 = 0 ;
V_2 -> V_41 &= ~ V_523 ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
if ( V_2 -> V_434 == 0 )
F_228 ( V_2 ) ;
if ( ! F_317 ( V_2 ) )
F_257 ( V_2 , V_443 ,
V_444 ) ;
}
static int
F_341 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_209 * V_210 = & V_4 -> V_210 ;
T_1 V_46 = 0 , V_557 ;
T_1 V_558 ;
int V_51 = 0 ;
if ( F_292 ( V_2 ) )
goto V_559;
if ( V_2 -> V_273 )
F_342 ( V_2 , 0 ) ;
V_46 = F_94 ( V_2 , V_296 ) ;
if ( V_46 == V_516 ) {
F_330 ( V_2 ) ;
V_2 -> V_273 = 1 ;
} else if ( V_46 == V_517 )
goto V_559;
V_557 = F_94 ( V_2 , V_560 ) ;
if ( V_557 != V_2 -> V_557 ) {
V_2 -> V_557 = V_557 ;
V_2 -> V_522 = 0 ;
if ( V_2 -> V_273 )
goto V_559;
if ( V_4 -> V_340 && V_561 )
F_207 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_522 < V_562 )
return 0 ;
V_2 -> V_41 |= V_523 ;
F_342 ( V_2 , 0 ) ;
if ( V_561 )
F_123 ( V_563 , & V_2 -> V_46 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_100 ) ;
V_558 = F_94 ( V_2 , V_545 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_101
L_102
L_103
L_104
L_105 ,
V_558 ,
F_94 ( V_2 , V_564 ) ,
F_115 ( V_2 , V_565 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_566 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_567 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_568 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_569 + 0x3c , & V_51 ) ) ;
if ( F_329 ( V_558 ) == 0x67 )
F_80 ( & V_2 -> V_5 -> V_30 ,
L_106
L_107 ) ;
V_559:
V_2 -> V_536 = ( V_46 == V_517 ) ? V_46 :
V_516 ;
if ( V_561 && ! F_45 ( V_62 ,
& V_2 -> V_46 ) ) {
F_257 ( V_2 , F_328 , 0 ) ;
F_323 ( V_2 , V_542 , L_108 ) ;
} else if ( ! V_561 && V_210 -> V_570 &&
V_2 -> V_41 & V_527 ) {
F_327 ( V_2 ) ;
}
return 1 ;
}
void V_443 ( struct V_535 * V_64 )
{
struct V_1 * V_2 = F_325 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
goto V_571;
if ( F_341 ( V_2 ) )
return;
if ( V_2 -> V_341 . V_342 )
F_343 ( V_2 ) ;
V_571:
F_257 ( V_2 , V_443 , V_444 ) ;
}
static int F_344 ( struct V_23 * V_5 )
{
struct V_23 * V_572 ;
int V_514 = V_5 -> V_573 ;
while ( V_514 -- > 0 ) {
V_572 = F_345 ( F_346
( V_5 -> V_574 ) , V_5 -> V_574 -> V_575 ,
F_347 ( F_348 ( V_5 -> V_573 ) , V_514 ) ) ;
if ( ! V_572 )
continue;
if ( V_572 -> V_576 != V_577 ) {
F_349 ( V_572 ) ;
return 0 ;
}
F_349 ( V_572 ) ;
}
return 1 ;
}
static int F_350 ( struct V_23 * V_5 )
{
int V_51 , V_578 ;
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_579 = V_580 ;
V_51 = F_232 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_235 ( V_5 ) ;
F_287 ( V_5 ) ;
V_578 = F_344 ( V_5 ) ;
if ( F_93 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_143 != V_178 && V_578 ) {
V_2 -> V_273 = 1 ;
F_120 ( V_524 , & V_2 -> V_46 ) ;
F_96 ( V_2 , V_296 ,
V_533 ) ;
F_323 ( V_2 , V_542 , L_83 ) ;
}
F_97 ( V_2 ) ;
V_51 = F_247 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_317 ( V_2 ) ;
F_7 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
V_51 = F_255 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_98 ) ;
F_119 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( V_51 ) {
F_263 ( V_2 , 1 ) ;
F_123 ( V_555 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_51 ;
}
V_51 = F_170 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_510;
F_122 ( V_22 , V_359 ) ;
}
V_510:
F_25 ( V_22 ) ;
return V_51 ;
}
static T_12 F_351 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_581 )
return V_582 ;
if ( V_46 == V_580 )
return V_583 ;
F_120 ( V_555 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_63 ) ;
if ( F_172 ( V_22 ) )
F_186 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
F_81 ( V_2 ) ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
F_352 ( V_5 ) ;
F_267 ( V_5 ) ;
return V_584 ;
}
static T_12 F_353 ( struct V_23 * V_5 )
{
return F_350 ( V_5 ) ? V_582 :
V_583 ;
}
static void F_354 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_269 ( V_5 ) ;
F_355 ( V_5 ) ;
V_46 = F_94 ( V_2 , V_296 ) ;
if ( V_46 == V_297 && F_175 ( V_555 ,
& V_2 -> V_46 ) )
F_257 ( V_2 , V_443 ,
V_444 ) ;
}
static T_12 F_356 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_585 * V_413 = V_2 -> V_4 -> V_413 ;
if ( V_413 -> V_586 ) {
return V_413 -> V_586 ( V_5 , V_46 ) ;
} else {
F_80 ( & V_5 -> V_30 , L_109 ) ;
return V_582 ;
}
}
static T_12 F_357 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_585 * V_413 = V_2 -> V_4 -> V_413 ;
if ( V_413 -> V_587 ) {
return V_413 -> V_587 ( V_5 ) ;
} else {
F_80 ( & V_5 -> V_30 , L_110 ) ;
return V_582 ;
}
}
static void F_358 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_585 * V_413 = V_2 -> V_4 -> V_413 ;
if ( V_413 -> V_588 )
V_413 -> V_588 ( V_5 ) ;
else
F_80 ( & V_5 -> V_30 , L_111 ) ;
}
static int
F_359 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_142 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_137 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_113 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_109 ( V_2 ) ;
V_51 = F_125 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_273 = 0 ;
return V_51 ;
}
int F_360 ( struct V_1 * V_2 , T_14 V_80 ,
int V_81 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_589 = 0 ;
char V_590 [ 8 ] ;
int V_591 ;
if ( V_81 == V_85 ) {
V_589 = V_2 -> V_86 ;
V_591 = V_2 -> V_92 ;
strcpy ( V_590 , L_112 ) ;
} else if ( V_81 == V_87 ) {
V_589 = V_2 -> V_88 ;
V_591 = V_2 -> V_90 ;
strcpy ( V_590 , L_113 ) ;
}
if ( ! F_361 ( V_80 ) ) {
F_119 ( V_22 , L_114 ,
V_590 ) ;
return - V_40 ;
}
if ( F_54 ( V_2 ) && ( V_81 == V_87 ) &&
! F_70 ( V_2 ) ) {
F_119 ( V_22 , L_115 ) ;
return - V_40 ;
}
if ( V_80 > F_58 () ) {
F_119 ( V_22 ,
L_116 ,
V_590 , F_58 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_362 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_592 , V_593 ;
int V_51 ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return - V_358 ;
V_592 = V_2 -> V_96 ;
V_593 = V_2 -> V_97 ;
F_22 ( V_22 ) ;
V_51 = F_210 ( V_2 , V_592 , V_593 ) ;
if ( V_51 )
goto V_510;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
if ( F_62 ( V_2 ) ) {
F_261 ( V_2 ) ;
F_363 ( V_2 ) ;
}
F_81 ( V_2 ) ;
V_51 = F_255 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_98 ) ;
F_119 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( ( V_592 != V_2 -> V_90 ) ||
( V_593 != V_2 -> V_92 ) ) {
V_51 = F_210 ( V_2 ,
V_2 -> V_90 ,
V_2 -> V_92 ) ;
if ( V_51 )
goto V_510;
}
if ( F_62 ( V_2 ) ) {
F_273 ( V_2 , 1 ) ;
V_51 = F_364 ( V_2 ) ;
F_365 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_117 ) ;
goto V_510;
}
}
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( V_51 )
goto V_510;
V_51 = F_162 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_510;
F_122 ( V_22 , V_359 ) ;
}
V_510:
F_25 ( V_22 ) ;
F_123 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_366 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_594 )
{
struct V_595 * V_596 ;
V_596 = F_367 ( V_30 ) ;
if ( ! V_596 )
return;
F_368 (indev) {
switch ( V_594 ) {
case V_359 :
F_369 ( V_2 ,
V_597 -> V_598 , V_599 ) ;
break;
case V_262 :
F_369 ( V_2 ,
V_597 -> V_598 , V_600 ) ;
break;
default:
break;
}
} F_370 ( V_596 ) ;
F_371 ( V_596 ) ;
}
void F_122 ( struct V_21 * V_22 , unsigned long V_594 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_260 ;
F_366 ( V_2 , V_22 , V_594 ) ;
F_372 () ;
F_373 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_374 ( V_22 , F_375 ( V_601 ) , V_260 ) ;
if ( ! V_30 )
continue;
F_366 ( V_2 , V_30 , V_594 ) ;
}
F_376 () ;
}
static int F_377 ( struct V_602 * V_603 ,
unsigned long V_594 , void * V_604 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_378 ( V_604 ) ;
V_605:
if ( V_30 == NULL )
goto V_510;
if ( V_30 -> V_394 & V_606 ) {
V_30 = F_379 ( V_30 ) ;
goto V_605;
}
if ( ! F_380 ( V_30 ) )
goto V_510;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_510;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_510;
F_366 ( V_2 , V_30 , V_594 ) ;
V_510:
return V_607 ;
}
static int
F_381 ( struct V_602 * V_603 ,
unsigned long V_594 , void * V_604 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_608 * V_597 = (struct V_608 * ) V_604 ;
V_30 = V_597 -> V_609 ? V_597 -> V_609 -> V_30 : NULL ;
V_605:
if ( V_30 == NULL )
goto V_510;
if ( V_30 -> V_394 & V_606 ) {
V_30 = F_379 ( V_30 ) ;
goto V_605;
}
if ( ! F_380 ( V_30 ) )
goto V_510;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_510;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_510;
switch ( V_594 ) {
case V_359 :
F_369 ( V_2 , V_597 -> V_598 , V_599 ) ;
break;
case V_262 :
F_369 ( V_2 , V_597 -> V_598 , V_600 ) ;
break;
default:
break;
}
V_510:
return V_607 ;
}
void F_122 ( struct V_21 * V_30 , unsigned long V_594 )
{ }
static int T_15 F_382 ( void )
{
int V_26 ;
F_383 ( V_480 L_118 , V_610 ) ;
#ifdef F_384
F_385 ( & V_611 ) ;
F_386 ( & V_612 ) ;
#endif
V_26 = F_387 ( & V_613 ) ;
if ( V_26 ) {
#ifdef F_384
F_388 ( & V_612 ) ;
F_389 ( & V_611 ) ;
#endif
}
return V_26 ;
}
static void T_16 F_390 ( void )
{
F_391 ( & V_613 ) ;
#ifdef F_384
F_388 ( & V_612 ) ;
F_389 ( & V_611 ) ;
#endif
}
