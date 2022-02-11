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
if ( V_2 -> V_41 & V_53 ) {
if ( F_29 ( V_39 ) ) {
V_51 = F_30 ( V_22 , V_39 ) ;
if ( ! V_51 )
V_51 = F_31 ( V_2 , V_39 ) ;
} else if ( F_32 ( V_39 ) ) {
V_51 = F_33 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
}
return V_51 ;
}
static int F_34 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 ,
const unsigned char * V_39 , T_3 V_41 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 = 0 ;
if ( ! V_2 -> V_52 )
return F_35 ( V_48 , V_50 , V_22 , V_39 , V_41 ) ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
F_36 ( L_2 , V_54 ) ;
return - V_43 ;
}
if ( F_37 ( V_39 , V_2 -> V_24 ) )
return V_51 ;
if ( F_29 ( V_39 ) ) {
if ( F_38 ( V_22 ) < V_2 -> V_4 -> V_55 )
V_51 = F_39 ( V_22 , V_39 ) ;
else
V_51 = - V_56 ;
} else if ( F_32 ( V_39 ) ) {
V_51 = F_40 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
return V_51 ;
}
static int F_41 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_21 * V_22 , int V_61 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( ! V_2 -> V_52 )
return F_42 ( V_58 , V_60 , V_22 , V_61 ) ;
if ( V_2 -> V_41 & V_53 )
V_61 = F_42 ( V_58 , V_60 , V_22 , V_61 ) ;
return V_61 ;
}
static void F_43 ( struct V_1 * V_2 )
{
while ( F_44 ( V_62 , & V_2 -> V_46 ) )
F_45 ( 10000 , 11000 ) ;
if ( ! V_2 -> V_63 . V_64 . V_65 )
return;
F_46 ( & V_2 -> V_63 ) ;
}
static int F_47 ( struct V_21 * V_22 ,
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
static void F_48 ( struct V_21 * V_22 ,
T_4 V_72 , T_5 V_73 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_49 ( V_2 ) || V_4 -> V_74 )
return;
V_4 -> V_74 = F_50 ( V_73 ) ;
V_2 -> V_41 |= V_75 ;
}
static void F_51 ( struct V_21 * V_22 ,
T_4 V_72 , T_5 V_73 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_49 ( V_2 ) || ! V_4 -> V_74 ||
( V_4 -> V_74 != F_50 ( V_73 ) ) )
return;
V_2 -> V_41 |= V_76 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_53 ( V_2 ) &&
( V_4 -> V_77 [ 0 ] & V_78 ) ) {
F_44 ( V_79 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_54 ( struct V_1 * V_2 , T_2 V_80 ,
int V_81 )
{
int V_82 , V_83 = V_84 ;
if ( V_81 == V_85 )
V_83 = V_2 -> V_86 ;
else if ( V_81 == V_87 )
V_83 = V_2 -> V_88 ;
V_82 = F_55 ( F_56 ( int , F_57 () ,
V_83 ) ) ;
if ( V_80 > V_82 )
return V_82 ;
else
return V_80 ;
}
void F_58 ( struct V_1 * V_2 , T_2 V_89 )
{
if ( V_2 -> V_88 )
V_2 -> V_90 = F_54 ( V_2 , V_89 ,
V_87 ) ;
else
V_2 -> V_90 = V_89 ;
}
void F_59 ( struct V_1 * V_2 , T_2 V_91 )
{
if ( V_2 -> V_86 )
V_2 -> V_92 = F_54 ( V_2 , V_91 ,
V_85 ) ;
else
V_2 -> V_92 = V_91 ;
}
int F_60 ( struct V_1 * V_2 )
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
if ( F_61 ( V_2 ) )
V_93 += 1 ;
if ( ! V_2 -> V_98 ) {
V_2 -> V_98 = F_62 ( V_93 ,
sizeof( struct V_99 ) ,
V_20 ) ;
if ( ! V_2 -> V_98 )
return - V_56 ;
}
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ )
V_2 -> V_98 [ V_94 ] . V_100 = V_94 ;
V_101:
V_51 = F_63 ( V_5 , V_2 -> V_98 , V_93 ) ;
if ( V_51 > 0 ) {
if ( ! V_2 -> V_96 && ! V_2 -> V_97 )
return - V_102 ;
F_64 ( V_2 -> V_22 ,
L_3 ,
V_93 , V_51 ) ;
V_93 = V_2 -> V_90 + V_2 -> V_92 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = 0 ;
if ( F_61 ( V_2 ) )
V_93 += 1 ;
F_64 ( V_2 -> V_22 ,
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
int F_65 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 , V_94 ;
if ( ! V_2 -> V_98 ) {
V_2 -> V_98 = F_62 ( V_93 ,
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
V_51 = F_66 ( V_5 ,
V_2 -> V_98 , 1 , V_93 ) ;
if ( V_51 == V_93 ) {
V_2 -> V_41 |= V_104 ;
V_2 -> V_4 -> V_93 = V_93 ;
F_67 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_51 > 0 ) {
F_68 ( V_5 ) ;
F_67 ( & V_5 -> V_30 ,
L_3 ,
V_93 , V_51 ) ;
if ( F_53 ( V_2 ) ) {
V_93 = F_55 ( V_51 ) ;
if ( V_51 < V_107 )
return - V_102 ;
} else {
V_93 = F_55 ( V_51 - 1 ) ;
V_93 += 1 ;
if ( V_51 < V_108 )
return - V_102 ;
}
if ( F_53 ( V_2 ) &&
! F_69 ( V_2 ) ) {
V_2 -> V_92 = V_93 ;
V_2 -> V_90 = V_109 ;
} else {
V_2 -> V_90 = V_93 / 2 ;
V_2 -> V_92 = V_2 -> V_90 ;
}
if ( V_93 ) {
F_67 ( & V_5 -> V_30 ,
L_6 ,
V_93 ) ;
goto V_106;
}
} else {
F_67 ( & V_5 -> V_30 ,
L_7 ,
V_93 , V_51 ) ;
return V_51 ;
}
}
return - V_110 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_93 ;
V_93 = V_2 -> V_92 ;
if ( F_69 ( V_2 ) )
V_93 += V_2 -> V_90 ;
else
V_93 += V_109 ;
return V_93 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_111 , V_112 ;
const struct V_113 * V_114 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_115 && ! F_72 ( V_5 ) ) {
V_2 -> V_41 |= V_103 ;
V_111 = V_116 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_117 = F_73 ( V_2 -> V_4 ,
V_111 ) ;
F_67 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_98 [ 0 ] . V_94 = V_5 -> V_118 ;
return V_51 ;
}
if ( V_115 || V_119 )
return - V_43 ;
V_114 = & V_120 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_121 = V_114 -> V_121 ;
V_111 = V_114 -> V_117 ;
V_2 -> V_117 = F_73 ( V_4 , V_111 ) ;
V_112 = V_114 -> V_122 ;
V_2 -> V_122 = F_73 ( V_4 , V_112 ) ;
V_2 -> V_123 = F_73 ( V_4 , V_124 ) ;
V_2 -> V_125 = F_73 ( V_4 , V_126 ) ;
F_67 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_98 [ 0 ] . V_94 = V_5 -> V_118 ;
return V_51 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_93 , V_51 = 0 ;
if ( V_2 -> V_41 & V_95 ) {
V_51 = F_60 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_93 = V_2 -> V_4 -> V_93 ;
} else {
V_93 = F_70 ( V_2 ) ;
V_51 = F_65 ( V_2 , V_93 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_104 ) ) {
F_75 ( V_2 ) ;
V_2 -> V_92 = V_109 ;
V_51 = F_71 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , int V_127 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_128 ;
if ( F_69 ( V_2 ) &&
! V_4 -> V_129 &&
( V_2 -> V_41 & V_104 ) ) {
V_4 -> V_130 = F_77 ( V_4 -> V_93 *
sizeof( struct V_131 ) ) ;
if ( ! V_4 -> V_130 )
return - V_56 ;
for ( V_128 = 0 ; V_128 < V_4 -> V_93 ; V_128 ++ ) {
V_4 -> V_130 [ V_128 ] . type = V_132 ;
V_4 -> V_130 [ V_128 ] . V_71 = V_128 ;
V_4 -> V_130 [ V_128 ] . V_133 = 0 ;
}
V_51 = F_78 ( V_2 , 1 ) ;
if ( V_51 )
F_79 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_93 ) ;
return V_51 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_104 )
F_68 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_103 )
F_81 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
if ( V_2 -> V_4 -> V_130 ) {
F_82 ( V_2 -> V_4 -> V_130 ) ;
V_2 -> V_4 -> V_130 = NULL ;
}
}
static void F_83 ( struct V_3 * V_4 )
{
if ( V_4 -> V_134 != NULL )
F_84 ( V_4 -> V_134 ) ;
}
static int F_85 ( struct V_1 * V_2 )
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
V_136 = F_62 ( V_4 -> V_145 , sizeof( * V_136 ) , V_20 ) ;
if ( ! V_136 )
return - V_56 ;
V_26 = F_86 ( V_2 , V_136 ) ;
F_7 ( V_136 ) ;
return V_26 ;
}
static bool F_87 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_88 ( V_2 ) ) {
V_26 = true ;
} else if ( F_61 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_77 [ 0 ] &
V_146 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_135 * V_136 ;
int V_128 , V_71 = 0 , V_26 = 0 , V_147 = 0 ;
T_3 V_148 ;
T_2 V_149 ;
V_136 = F_62 ( V_4 -> V_145 , sizeof( * V_136 ) , V_20 ) ;
if ( ! V_136 )
return - V_56 ;
V_26 = F_86 ( V_2 , V_136 ) ;
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
goto V_157;
}
if ( ! V_136 [ V_128 ] . V_158 ||
( V_136 [ V_128 ] . type != V_159 ) )
continue;
if ( F_87 ( V_2 ) ) {
if ( ! F_90 ( V_2 , V_149 ,
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
if ( ! F_87 ( V_2 ) ) {
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
F_91 ( struct V_1 * V_2 )
{
T_2 V_71 ;
int V_26 ;
T_1 V_169 = V_144 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_92 ( V_2 ) ;
if ( V_26 )
goto V_170;
V_71 = V_4 -> V_27 ;
V_169 = F_93 ( V_2 , V_171 ) ;
V_169 = ( V_169 & ~ F_94 ( 0xf , V_71 ) ) |
F_94 ( V_144 , V_71 ) ;
F_95 ( V_2 , V_171 , V_169 ) ;
F_96 ( V_2 ) ;
V_170:
return V_26 ;
}
static void F_97 ( struct V_1 * V_2 ,
const struct V_172 * V_173 )
{
T_1 V_143 , V_174 ;
V_2 -> V_4 -> V_175 = F_93 ( V_2 ,
V_176 ) ;
F_98 ( V_2 ) ;
V_143 = F_93 ( V_2 , V_171 ) ;
if ( V_143 == V_177 )
V_174 = V_144 ;
else
V_174 = F_99 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_174 == V_178 ) {
V_2 -> V_4 -> V_143 = V_178 ;
F_67 ( & V_2 -> V_5 -> V_30 ,
L_11 ,
V_2 -> V_4 -> V_175 ) ;
V_2 -> V_179 = & V_180 ;
} else
V_2 -> V_179 = & V_181 ;
}
static void F_100 ( T_1 V_182 , T_6 * V_183 )
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
static int F_101 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_111 ;
void T_7 * V_190 = NULL ;
unsigned long V_191 , V_192 = 0 , V_193 ;
V_191 = F_102 ( V_5 , 0 ) ;
F_100 ( V_5 -> V_6 , & V_193 ) ;
if ( V_191 >= V_193 ) {
V_190 = F_103 ( V_5 , 0 ) ;
if ( V_190 == NULL ) {
F_79 ( & V_5 -> V_30 , L_12 ) ;
return - V_110 ;
}
V_192 = V_191 ;
} else {
return - V_110 ;
}
F_67 ( & V_5 -> V_30 , L_13 , ( int ) ( V_191 >> 10 ) ) ;
V_4 -> V_134 = V_190 ;
V_4 -> V_192 = V_192 ;
V_111 = F_104 ( F_105 ( V_4 -> V_27 ) ) ;
F_73 ( V_4 , V_111 ) ;
return 0 ;
}
static bool F_106 ( struct V_1 * V_2 ,
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
static void F_107 ( struct V_1 * V_2 , char * V_200 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_128 , V_201 = 0 ;
for ( V_128 = 0 ; V_128 < V_202 ; ++ V_128 ) {
if ( V_196 [ V_128 ] . V_203 == V_5 -> V_203 &&
V_196 [ V_128 ] . V_6 == V_5 -> V_6 &&
F_106 ( V_2 , V_128 ) ) {
V_201 = 1 ;
break;
}
}
if ( ! V_201 )
sprintf ( V_200 , L_14 , V_2 -> V_24 ) ;
else
sprintf ( V_200 , L_15 , V_2 -> V_24 ,
V_196 [ V_128 ] . V_204 ) ;
}
static void
F_108 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_205 , V_206 , V_207 , V_208 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_209 * V_210 = & V_4 -> V_210 ;
V_208 = V_2 -> V_211 ;
V_205 = F_93 ( V_2 , V_212 ) ;
V_206 = F_93 ( V_2 , V_213 ) ;
V_207 = F_93 ( V_2 , V_214 ) ;
V_2 -> V_211 = F_109 ( V_205 , V_206 , V_207 ) ;
V_51 = F_110 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_16 ) ;
return;
}
if ( V_4 -> V_143 != V_178 ) {
if ( V_210 -> V_215 == NULL ||
V_2 -> V_211 > V_208 ) {
if ( V_210 -> V_215 )
F_82 ( V_210 -> V_215 ) ;
if ( ! F_111 ( V_2 ) )
F_67 ( & V_5 -> V_30 ,
L_17 ) ;
}
}
F_67 ( & V_5 -> V_30 , L_18 ,
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
F_112 ( struct V_1 * V_2 )
{
struct V_233 V_234 ;
int V_51 = 0 ;
memset ( & V_234 , 0 , sizeof( struct V_233 ) ) ;
V_51 = F_113 ( V_2 , & V_234 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_235 = ( T_2 ) V_234 . V_236 ;
V_2 -> V_4 -> V_237 = V_234 . V_237 ;
V_2 -> V_4 -> V_238 = V_234 . V_238 ;
V_2 -> V_4 -> V_239 = V_234 . V_239 ;
V_2 -> V_4 -> V_8 = V_234 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_240 ) {
T_1 V_241 ;
V_241 = F_114 ( V_2 , V_242 , & V_51 ) ;
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
F_67 ( & V_2 -> V_5 -> V_30 , L_19 ) ;
} else {
V_2 -> V_4 -> V_246 = V_250 ;
V_2 -> V_88 = V_251 ;
V_2 -> V_86 = V_84 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_115 ( struct V_1 * V_2 ,
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
F_116 ( struct V_21 * V_22 , T_5 V_259 , T_3 V_260 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_117 ( V_2 , V_260 , 1 ) ;
if ( V_51 ) {
F_118 ( V_22 ,
L_20 ,
V_260 , V_51 ) ;
return V_51 ;
}
}
F_119 ( V_260 , V_2 -> V_261 ) ;
return 0 ;
}
static int
F_120 ( struct V_21 * V_22 , T_5 V_259 , T_3 V_260 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_117 ( V_2 , V_260 , 0 ) ;
if ( V_51 ) {
F_118 ( V_22 ,
L_21 ,
V_260 , V_51 ) ;
return V_51 ;
}
}
F_121 ( V_22 , V_262 ) ;
F_122 ( V_260 , V_2 -> V_261 ) ;
return 0 ;
}
void F_123 ( struct V_1 * V_2 ,
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
int F_124 ( struct V_1 * V_2 )
{
struct V_252 V_253 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_253 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_125 ( V_2 , & V_253 ) )
return - V_110 ;
F_115 ( V_2 , & V_253 ) ;
F_123 ( V_2 , & V_253 ) ;
F_126 ( V_2 , & V_253 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_61 ( V_2 ) )
return;
V_2 -> V_268 = V_253 -> V_268 ;
V_2 -> V_41 |= V_269 ;
F_127 ( V_22 ) ;
V_2 -> V_41 &= ~ V_269 ;
}
static int
F_128 ( struct V_1 * V_2 )
{
T_1 V_143 , V_174 ;
int V_51 = 0 ;
V_51 = F_112 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_270 )
return 0 ;
V_143 = F_93 ( V_2 , V_171 ) ;
V_174 = F_99 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_143 == V_177 )
V_174 = V_144 ;
else
V_174 = F_99 ( V_143 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_174 == V_144 ) {
V_2 -> V_4 -> V_143 = V_144 ;
V_51 = F_89 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_91 ( V_2 ) ;
F_67 ( & V_2 -> V_5 -> V_30 ,
L_22 ,
V_2 -> V_4 -> V_175 ) ;
} else if ( V_174 == V_271 ) {
V_2 -> V_4 -> V_143 = V_271 ;
F_67 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_175 ) ;
}
} else {
V_2 -> V_4 -> V_246 = V_250 ;
}
V_2 -> V_41 |= V_270 ;
return V_51 ;
}
int F_129 ( struct V_1 * V_2 )
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
if ( F_53 ( V_2 ) ) {
V_253 . V_268 = V_274 ;
if ( F_130 ( V_2 ) )
V_253 . V_268 |= ( V_275 | V_276 ) ;
}
if ( F_131 ( V_2 , & V_253 ) )
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
F_132 ( struct V_1 * V_2 ,
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
if ( F_131 ( V_2 , & V_253 ) )
return - V_110 ;
V_253 . V_143 = V_279 ;
if ( F_131 ( V_2 , & V_253 ) )
return - V_110 ;
return 0 ;
}
int F_133 ( struct V_1 * V_2 )
{
int V_128 , V_51 ;
struct V_152 * V_272 ;
struct V_233 V_234 ;
T_2 V_27 ;
if ( F_53 ( V_2 ) )
if ( ! V_2 -> V_273 )
return 0 ;
for ( V_128 = 0 ; V_128 < V_2 -> V_4 -> V_139 ; V_128 ++ ) {
V_272 = & V_2 -> V_151 [ V_128 ] ;
V_27 = V_272 -> V_27 ;
if ( ! V_2 -> V_151 [ V_128 ] . V_160 )
continue;
memset ( & V_234 , 0 , sizeof( struct V_233 ) ) ;
V_51 = F_113 ( V_2 , & V_234 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_234 . V_280 = V_272 -> V_163 ;
V_234 . V_281 = V_272 -> V_165 ;
V_51 = F_134 ( V_2 , & V_234 ) ;
if ( V_51 )
return V_51 ;
if ( V_272 -> V_282 ) {
V_51 = F_135 ( V_2 ,
V_272 -> V_283 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_132 ( V_2 , V_272 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_136 ( struct V_1 * V_2 )
{
T_2 V_284 = V_285 ;
T_1 V_286 ;
if ( V_2 -> V_4 -> V_143 == V_144 )
return 0 ;
V_286 = F_93 ( V_2 ,
V_287 ) ;
while ( V_286 != V_288 && -- V_284 ) {
F_137 ( 1000 ) ;
V_286 = F_93 ( V_2 ,
V_287 ) ;
}
if ( ! V_284 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_24 ) ;
return - V_110 ;
}
return 0 ;
}
static int
F_138 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_143 != V_144 )
return 0 ;
V_51 = F_129 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_133 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_139 ( V_2 ) ;
return V_51 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_141 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_289;
if ( V_290 )
F_142 ( V_2 ) ;
else {
V_51 = F_143 ( V_2 ) ;
if ( V_51 )
goto V_291;
V_2 -> V_4 -> V_292 = V_293 ;
}
V_51 = F_144 ( V_2 ) ;
if ( V_51 == 0 )
goto V_289;
V_51 = F_145 ( V_2 ) ;
if ( V_51 )
goto V_291;
V_51 = F_146 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_147 ( V_2 ) ;
F_148 ( V_2 , V_294 , V_295 ) ;
V_289:
V_51 = F_149 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_95 ( V_2 , V_296 , V_297 ) ;
F_150 ( V_2 , 1 ) ;
V_51 = F_128 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
goto V_291;
}
V_51 = F_138 ( V_2 ) ;
if ( V_51 )
goto V_291;
F_108 ( V_2 ) ;
V_2 -> V_273 = 0 ;
F_147 ( V_2 ) ;
return 0 ;
V_291:
F_95 ( V_2 , V_296 , V_298 ) ;
F_79 ( & V_2 -> V_5 -> V_30 , L_26 ) ;
F_147 ( V_2 ) ;
return V_51 ;
}
static int
F_151 ( struct V_1 * V_2 )
{
T_8 V_299 ;
struct V_18 * V_300 ;
struct V_10 * V_11 ;
int V_51 , V_301 , V_302 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_129 == V_303 ) {
if ( F_53 ( V_2 ) )
V_299 = V_304 ;
else
V_299 = V_305 ;
if ( ! F_152 ( V_2 ) )
V_41 |= V_306 ;
} else {
if ( V_2 -> V_41 & V_104 )
V_299 = V_307 ;
else if ( V_2 -> V_41 & V_103 )
V_299 = V_308 ;
else {
V_41 |= V_306 ;
if ( F_53 ( V_2 ) )
V_299 = V_309 ;
else
V_299 = V_310 ;
}
}
V_2 -> V_118 = V_22 -> V_118 ;
if ( V_2 -> V_4 -> V_129 != V_311 ) {
if ( F_53 ( V_2 ) ||
( F_61 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) ) ) {
V_302 = V_2 -> V_92 ;
for ( V_301 = 0 ; V_301 < V_302 ; V_301 ++ ) {
V_300 = & V_15 -> V_19 [ V_301 ] ;
if ( F_53 ( V_2 ) &&
! F_69 ( V_2 ) &&
( V_301 == ( V_302 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_104 ) )
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_27 ) ;
else
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_28 ,
V_22 -> V_200 , V_301 ) ;
} else {
snprintf ( V_300 -> V_200 ,
sizeof( V_300 -> V_200 ) ,
L_29 ,
V_22 -> V_200 , V_301 ) ;
}
V_51 = F_153 ( V_300 -> V_118 , V_299 , V_41 ,
V_300 -> V_200 , V_300 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_53 ( V_2 ) &&
F_69 ( V_2 ) ) ||
( F_61 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) &&
! ( V_2 -> V_41 & V_312 ) ) ) {
V_299 = V_313 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ;
V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
snprintf ( V_11 -> V_200 , sizeof( V_11 -> V_200 ) ,
L_30 , V_22 -> V_200 , V_301 ) ;
V_51 = F_153 ( V_11 -> V_118 , V_299 , V_41 ,
V_11 -> V_200 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_154 ( struct V_1 * V_2 )
{
int V_301 ;
struct V_18 * V_300 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_129 != V_311 ) {
if ( F_53 ( V_2 ) ||
( F_61 ( V_2 ) &&
( V_2 -> V_41 & V_104 ) ) ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_15 -> V_19 [ V_301 ] ;
F_155 ( V_300 -> V_118 , V_300 ) ;
}
}
if ( ( F_61 ( V_2 ) &&
! ( V_2 -> V_41 & V_312 ) ) ||
( F_53 ( V_2 ) &&
F_69 ( V_2 ) ) ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ;
V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
if ( V_11 -> V_118 )
F_155 ( V_11 -> V_118 , V_11 ) ;
}
}
}
}
static void F_156 ( struct V_1 * V_2 )
{
T_1 V_314 = 0 ;
if ( F_53 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_77 [ 0 ] &
V_315 )
V_2 -> V_41 |= V_316 ;
} else {
V_314 = V_2 -> V_4 -> V_8 ;
if ( F_157 ( V_314 ) )
V_2 -> V_41 |= V_316 ;
}
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 ;
V_4 -> V_317 . V_318 = V_319 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_317 . type = V_320 ;
V_4 -> V_317 . V_321 = V_322 ;
V_4 -> V_317 . V_323 = V_324 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
V_51 = F_159 ( V_2 ) ;
} else {
V_4 -> V_317 . type = V_329 ;
V_4 -> V_317 . V_325 = V_326 ;
V_4 -> V_317 . V_327 = V_328 ;
V_51 = F_160 ( V_2 ) ;
}
return V_51 ;
}
int F_161 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_301 ;
struct V_330 * V_331 ;
if ( V_2 -> V_332 != V_333 )
return - V_110 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_124 ( V_2 ) )
return - V_110 ;
F_156 ( V_2 ) ;
if ( F_162 ( V_2 ) )
return - V_110 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_231 ; V_301 ++ ) {
V_331 = & V_2 -> V_15 -> V_334 [ V_301 ] ;
F_163 ( V_2 , V_331 , V_301 ) ;
}
F_24 ( V_22 ) ;
F_164 ( V_2 , V_22 -> V_335 ) ;
V_2 -> V_4 -> V_336 = 0 ;
if ( V_2 -> V_92 > 1 )
F_165 ( V_2 , 1 ) ;
F_158 ( V_2 ) ;
if ( V_22 -> V_337 & V_338 )
F_166 ( V_2 , V_339 ) ;
F_119 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_167 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_340 = 0 ;
F_168 ( V_22 ) ;
return 0 ;
}
int F_169 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_170 () ;
if ( F_171 ( V_22 ) )
V_51 = F_161 ( V_2 , V_22 ) ;
F_172 () ;
return V_51 ;
}
void F_173 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_301 ;
if ( V_2 -> V_332 != V_333 )
return;
if ( ! F_174 ( V_45 , & V_2 -> V_46 ) )
return;
if ( F_20 ( V_2 ) )
F_175 ( & V_2 -> V_4 -> V_341 -> V_342 ) ;
F_176 () ;
F_177 ( V_22 ) ;
V_2 -> V_4 -> V_336 = 0 ;
F_178 ( V_22 ) ;
F_179 ( V_2 ) ;
if ( V_2 -> V_343 . V_344 )
F_180 ( V_2 ) ;
F_181 ( V_2 , V_345 ) ;
F_23 ( V_2 ) ;
F_182 ( V_2 ) ;
V_2 -> V_41 &= ~ V_316 ;
F_183 ( V_2 ) ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ )
F_184 ( V_2 , & V_2 -> V_11 [ V_301 ] ) ;
}
void F_185 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_170 () ;
if ( F_171 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
F_172 () ;
}
int
F_186 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_332 == V_333 )
return 0 ;
V_51 = F_187 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_188 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_31 ) ;
goto V_346;
}
V_51 = F_189 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_32 ) ;
goto V_347;
}
V_51 = F_151 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_33 ) ;
goto V_348;
}
F_190 ( V_2 ) ;
#ifdef F_191
if ( F_49 ( V_2 ) )
F_192 ( V_22 ) ;
#endif
V_2 -> V_332 = V_333 ;
return 0 ;
V_348:
F_193 ( V_2 ) ;
V_347:
F_194 ( V_2 ) ;
V_346:
F_195 ( V_2 ) ;
return V_51 ;
}
void F_196 ( struct V_1 * V_2 )
{
if ( V_2 -> V_332 != V_333 )
return;
F_197 ( V_2 ) ;
F_193 ( V_2 ) ;
F_198 ( V_2 ) ;
F_154 ( V_2 ) ;
F_195 ( V_2 ) ;
F_194 ( V_2 ) ;
V_2 -> V_332 = 0 ;
}
void F_199 ( struct V_21 * V_22 , int V_92 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_300 ;
int V_90 = V_2 -> V_90 ;
int V_301 ;
F_122 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_129 == V_303 ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_2 -> V_15 -> V_19 [ V_301 ] ;
F_200 ( V_2 , V_300 ) ;
}
}
F_182 ( V_2 ) ;
F_196 ( V_2 ) ;
V_2 -> V_4 -> V_129 = 0 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_90 = V_90 ;
if ( F_186 ( V_2 ) )
goto V_349;
if ( F_171 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
V_349:
F_25 ( V_22 ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_291;
}
memset ( & V_2 -> V_350 , 0 , sizeof( V_2 -> V_350 ) ) ;
V_291:
return V_51 ;
}
static void F_202 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_210 . V_215 ) {
F_82 ( V_2 -> V_4 -> V_210 . V_215 ) ;
V_2 -> V_4 -> V_210 . V_215 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_351 . V_352 ) ;
V_2 -> V_4 -> V_210 . V_215 = NULL ;
}
int F_203 ( struct V_21 * V_22 , int V_353 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_300 ;
struct V_330 * V_331 ;
int V_301 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_171 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
F_196 ( V_2 ) ;
V_2 -> V_92 = V_109 ;
V_2 -> V_4 -> V_129 = V_353 ;
V_2 -> V_4 -> V_336 = 0 ;
V_26 = F_186 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_162 ( V_2 ) ;
if ( V_26 ) {
F_196 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_301 = 0 ; V_301 < V_2 -> V_231 ; V_301 ++ ) {
V_331 = & V_2 -> V_15 -> V_334 [ V_301 ] ;
F_163 ( V_2 , V_331 , V_301 ) ;
}
if ( V_2 -> V_4 -> V_129 == V_303 ) {
for ( V_301 = 0 ; V_301 < V_2 -> V_92 ; V_301 ++ ) {
V_300 = & V_2 -> V_15 -> V_19 [ V_301 ] ;
F_204 ( V_2 , V_300 ) ;
}
}
if ( V_2 -> V_4 -> V_129 == V_311 ) {
V_2 -> V_4 -> V_354 = 0 ;
F_167 ( V_2 , 1 ) ;
}
F_119 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_205 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_44 ( V_62 , & V_2 -> V_46 ) )
return - V_355 ;
F_22 ( V_22 ) ;
F_185 ( V_2 , V_22 ) ;
F_169 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
F_64 ( V_2 -> V_22 , L_34 , V_54 ) ;
return 0 ;
}
int
F_206 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_44 ( V_62 , & V_2 -> V_46 ) )
return - V_355 ;
if ( V_2 -> V_332 == V_333 ) {
F_22 ( V_22 ) ;
if ( F_171 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
F_196 ( V_2 ) ;
if ( F_171 ( V_22 ) ) {
V_51 = F_186 ( V_2 ) ;
if ( ! V_51 ) {
F_161 ( V_2 , V_22 ) ;
F_121 ( V_22 , V_356 ) ;
}
}
F_25 ( V_22 ) ;
}
F_122 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_357 = V_4 -> V_139 ;
T_3 V_16 ;
V_4 -> V_358 = V_359 ;
if ( V_357 <= 2 )
V_16 = ( V_360 - V_359 ) /
V_357 ;
else
V_16 = ( V_361 - V_359 ) /
V_357 ;
V_4 -> V_55 = V_16 ;
}
static int F_208 ( struct V_1 * V_2 ,
T_2 V_362 , T_2 V_363 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 = 0 ;
if ( V_362 ) {
V_51 = F_209 ( V_22 , V_362 ) ;
if ( V_51 ) {
F_118 ( V_22 , L_35 ,
V_362 ) ;
return V_51 ;
}
}
if ( V_363 ) {
V_51 = F_210 ( V_22 , V_363 ) ;
if ( V_51 )
F_118 ( V_22 , L_36 ,
V_363 ) ;
}
return V_51 ;
}
int
F_211 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_364 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_365 = 1 ;
V_2 -> V_4 -> V_366 = 0 ;
F_212 ( V_2 ) ;
V_22 -> V_367 = & V_368 ;
V_22 -> V_369 = V_370 * V_371 ;
F_213 ( V_22 , V_22 -> V_335 ) ;
if ( F_20 ( V_2 ) )
F_214 ( V_22 , & V_372 ) ;
else
F_214 ( V_22 , & V_373 ) ;
V_22 -> V_337 |= ( V_374 | V_375 | V_376 |
V_377 | V_378 |
V_379 ) ;
V_22 -> V_380 |= ( V_374 | V_375 |
V_377 ) ;
if ( F_130 ( V_2 ) ) {
V_22 -> V_337 |= ( V_381 | V_382 ) ;
V_22 -> V_380 |= ( V_381 | V_382 ) ;
}
if ( V_364 ) {
V_22 -> V_337 |= V_383 ;
V_22 -> V_380 |= V_383 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_337 |= ( V_384 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_337 |= V_385 ;
if ( V_2 -> V_4 -> V_8 & V_386 )
V_22 -> V_337 |= V_338 ;
if ( F_215 ( V_2 ) ) {
V_22 -> V_337 |= V_387 ;
V_22 -> V_388 = V_375 |
V_387 |
V_381 |
V_382 ;
}
if ( F_49 ( V_2 ) )
V_22 -> V_388 |= V_376 ;
V_22 -> V_389 = V_22 -> V_337 ;
V_22 -> V_390 |= V_391 ;
V_22 -> V_118 = V_2 -> V_98 [ 0 ] . V_94 ;
V_51 = F_208 ( V_2 , V_2 -> V_90 ,
V_2 -> V_92 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_216 ( V_22 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_37 ) ;
return V_51 ;
}
F_217 ( V_2 -> V_392 ) ;
return 0 ;
}
static int F_218 ( struct V_23 * V_5 , int * V_364 )
{
if ( ! F_219 ( V_5 , F_220 ( 64 ) ) &&
! F_221 ( V_5 , F_220 ( 64 ) ) )
* V_364 = 1 ;
else if ( ! F_219 ( V_5 , F_220 ( 32 ) ) &&
! F_221 ( V_5 , F_220 ( 32 ) ) )
* V_364 = 0 ;
else {
F_79 ( & V_5 -> V_30 , L_38 ) ;
return - V_110 ;
}
return 0 ;
}
void F_222 ( struct V_1 * V_2 )
{
int V_301 ;
struct V_10 * V_11 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
if ( V_11 && V_11 -> V_393 != NULL ) {
F_82 ( V_11 -> V_393 ) ;
V_11 -> V_393 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_223 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_301 , V_94 , V_194 ;
struct V_10 * V_11 ;
struct V_394 * V_393 ;
V_11 = F_62 ( V_2 -> V_90 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
V_11 -> V_395 = V_2 -> V_229 ;
V_11 -> V_396 = F_224 ( V_22 , V_301 ) ;
V_393 = F_77 ( F_225 ( V_11 ) ) ;
if ( V_393 == NULL ) {
F_222 ( V_2 ) ;
return - V_56 ;
}
memset ( V_393 , 0 , F_225 ( V_11 ) ) ;
V_11 -> V_393 = V_393 ;
F_226 ( & V_11 -> V_397 ) ;
}
if ( F_61 ( V_2 ) ||
( F_53 ( V_2 ) && F_69 ( V_2 ) ) ) {
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
void F_227 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_398 = 0 ;
if ( F_53 ( V_2 ) )
V_398 = V_399 ;
else if ( F_61 ( V_2 ) )
V_398 = V_400 ;
if ( V_4 -> V_77 [ 0 ] & V_401 )
F_228 ( V_2 , V_398 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
F_92 ( V_2 ) ;
F_96 ( V_2 ) ;
}
static int
F_230 ( struct V_23 * V_5 , const struct V_172 * V_173 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_364 = - 1 ;
char V_402 [ V_403 + 19 ] ;
if ( V_5 -> V_404 )
return - V_405 ;
V_51 = F_231 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_232 ( V_5 , 0 ) & V_406 ) ) {
V_51 = - V_405 ;
goto V_407;
}
V_51 = F_218 ( V_5 , & V_364 ) ;
if ( V_51 )
goto V_407;
V_51 = F_233 ( V_5 , V_408 ) ;
if ( V_51 )
goto V_407;
F_234 ( V_5 ) ;
F_235 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_409;
}
switch ( V_173 -> V_6 ) {
case V_7 :
V_4 -> V_410 = & V_411 ;
V_4 -> V_412 = ( T_1 * ) V_413 ;
break;
case V_185 :
case V_186 :
F_236 ( V_4 ) ;
break;
case V_187 :
case V_188 :
F_237 ( V_4 ) ;
break;
default:
goto V_414;
}
V_51 = F_101 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_414;
V_22 = F_238 ( sizeof( struct V_1 ) ,
V_415 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_416;
}
F_239 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_417 = F_240 ( L_27 ) ;
if ( V_2 -> V_417 == NULL ) {
V_51 = - V_56 ;
F_79 ( & V_5 -> V_30 , L_39 ) ;
goto V_418;
}
V_51 = F_201 ( V_2 ) ;
if ( V_51 )
goto V_419;
V_2 -> V_420 = V_421 ;
V_4 -> V_422 = V_5 -> V_423 ;
V_4 -> V_145 = F_241 ( V_2 ) ;
if ( V_424 == V_425 )
V_2 -> V_52 = true ;
else if ( V_424 == V_426 )
V_2 -> V_427 = true ;
F_242 ( & V_2 -> V_4 -> V_428 ) ;
F_243 ( & V_2 -> V_4 -> V_429 ) ;
F_244 ( & V_2 -> V_430 ) ;
F_245 ( V_2 ) ;
if ( F_53 ( V_2 ) ) {
F_97 ( V_2 , V_173 ) ;
V_2 -> V_431 = V_2 -> V_4 -> V_27 ;
F_229 ( V_2 ) ;
V_51 = F_246 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_40
L_41 ) ;
goto V_432;
}
if ( V_2 -> V_4 -> V_105 ) {
if ( F_52 ( V_2 ) == 1 )
F_58 ( V_2 ,
V_109 ) ;
else
F_58 ( V_2 ,
V_433 ) ;
F_59 ( V_2 ,
V_434 ) ;
} else {
F_58 ( V_2 , V_109 ) ;
F_59 ( V_2 , V_109 ) ;
}
V_51 = F_247 ( V_2 ) ;
if ( V_51 )
goto V_348;
V_2 -> V_41 |= V_435 ;
} else if ( F_61 ( V_2 ) ) {
F_248 ( V_2 , V_173 ) ;
V_2 -> V_431 = V_2 -> V_4 -> V_27 ;
V_51 = F_249 ( V_2 , V_364 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_436 :
F_79 ( & V_5 -> V_30 , L_42 ) ;
F_79 ( & V_5 -> V_30 , L_43 ) ;
goto V_348;
case - V_56 :
F_79 ( & V_5 -> V_30 , L_44 ) ;
goto V_348;
default:
F_79 ( & V_5 -> V_30 , L_45 ) ;
F_79 ( & V_5 -> V_30 , L_46 ) ;
goto V_432;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_79 ( & V_5 -> V_30 ,
L_47 , V_54 ) ;
goto V_348;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_48 ) ;
F_250 ( V_2 ) ;
if ( V_2 -> V_431 == 0 ) {
F_107 ( V_2 , V_402 ) ;
F_36 ( L_49 ,
F_251 ( V_437 ) ,
V_402 , V_2 -> V_4 -> V_422 ) ;
}
if ( F_61 ( V_2 ) && ! V_119 &&
! ! V_115 )
F_11 ( & V_5 -> V_30 ,
L_50 ) ;
if ( F_53 ( V_2 ) ) {
F_252 ( V_2 -> V_392 ) ;
F_253 ( V_2 -> V_392 ) ;
V_51 = F_254 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_51 ) ;
goto V_438;
}
}
V_51 = F_85 ( V_2 ) ;
if ( V_51 )
goto V_439;
V_51 = F_211 ( V_2 , V_22 , V_364 ) ;
if ( V_51 )
goto V_439;
if ( V_2 -> V_431 == 0 )
F_227 ( V_2 ) ;
F_255 ( V_5 , V_2 ) ;
if ( F_53 ( V_2 ) )
F_256 ( V_2 , V_440 ,
V_441 ) ;
switch ( V_2 -> V_4 -> V_137 ) {
case V_138 :
F_67 ( & V_2 -> V_5 -> V_30 , L_52 ,
V_2 -> V_22 -> V_200 ) ;
break;
case V_141 :
F_67 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_200 ) ;
break;
}
if ( V_2 -> V_427 )
F_257 ( V_2 ) ;
F_258 ( V_2 ) ;
return 0 ;
V_439:
if ( F_61 ( V_2 ) )
F_259 ( V_2 ) ;
V_438:
F_80 ( V_2 ) ;
F_260 ( V_2 ) ;
F_261 ( V_2 , 0 ) ;
V_348:
F_202 ( V_2 ) ;
V_419:
F_262 ( V_2 -> V_417 ) ;
V_418:
F_263 ( V_22 ) ;
V_416:
F_83 ( V_4 ) ;
V_414:
F_7 ( V_4 ) ;
V_409:
F_264 ( V_5 ) ;
V_407:
F_265 ( V_5 ) ;
return V_51 ;
V_432:
F_119 ( V_442 , & V_2 -> V_46 ) ;
V_22 -> V_367 = & V_443 ;
F_214 ( V_22 , & V_444 ) ;
V_4 -> V_137 = V_141 ;
if ( F_61 ( V_2 ) )
V_2 -> V_117 = NULL ;
else
V_4 -> V_445 = V_446 ;
V_51 = F_216 ( V_22 ) ;
if ( V_51 ) {
F_79 ( & V_5 -> V_30 , L_54 ) ;
F_261 ( V_2 , 0 ) ;
goto V_348;
}
F_255 ( V_5 , V_2 ) ;
F_258 ( V_2 ) ;
return 0 ;
}
static void F_266 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_267 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_268 ( V_2 ) ;
F_260 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_269 ( V_22 ) ;
F_270 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
F_271 ( V_2 , 0 ) ;
F_46 ( & V_2 -> V_447 ) ;
F_259 ( V_2 ) ;
F_272 ( V_2 ) ;
F_273 ( V_4 -> V_448 ) ;
F_7 ( V_4 -> V_449 ) ;
}
F_274 ( V_2 -> V_392 ) ;
F_196 ( V_2 ) ;
if ( V_2 -> V_151 != NULL )
F_7 ( V_2 -> V_151 ) ;
if ( V_2 -> V_153 != NULL )
F_7 ( V_2 -> V_153 ) ;
if ( F_53 ( V_2 ) )
F_261 ( V_2 , 0 ) ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
F_275 ( V_2 ) ;
F_80 ( V_2 ) ;
F_276 ( V_2 ) ;
F_83 ( V_2 -> V_4 ) ;
F_147 ( V_2 ) ;
F_277 ( V_5 ) ;
F_264 ( V_5 ) ;
F_265 ( V_5 ) ;
if ( V_2 -> V_417 ) {
F_262 ( V_2 -> V_417 ) ;
V_2 -> V_417 = NULL ;
}
F_202 ( V_2 ) ;
F_7 ( V_4 ) ;
F_263 ( V_22 ) ;
}
static void F_278 ( struct V_23 * V_5 )
{
if ( F_279 ( V_5 ) )
return;
F_265 ( V_5 ) ;
}
static int F_280 ( struct V_23 * V_5 , T_9 V_46 )
{
int V_450 ;
V_450 = F_279 ( V_5 ) ;
if ( V_450 )
return V_450 ;
F_281 ( V_5 , F_282 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_283 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_267 ( V_5 ) ;
int V_51 ;
V_51 = F_231 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_281 ( V_5 , V_451 ) ;
F_234 ( V_5 ) ;
F_284 ( V_5 ) ;
return F_285 ( V_2 ) ;
}
static int F_286 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_21 ( V_442 , & V_2 -> V_46 ) ) {
F_118 ( V_22 , L_55 ,
V_54 ) ;
return - V_110 ;
}
F_177 ( V_22 ) ;
V_51 = F_186 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_161 ( V_2 , V_22 ) ;
if ( V_51 )
F_196 ( V_2 ) ;
return V_51 ;
}
static int F_287 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_173 ( V_2 , V_22 ) ;
return 0 ;
}
void F_257 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_128 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_452 = 0 ;
T_3 V_148 = 0 ;
if ( V_2 -> V_343 . V_453 && V_2 -> V_343 . V_454 )
return;
V_148 = V_2 -> V_4 -> V_139 ;
F_226 ( & V_2 -> V_455 ) ;
F_226 ( & V_2 -> V_456 ) ;
if ( F_53 ( V_2 ) ) {
V_452 = V_361 ;
V_2 -> V_343 . V_457 = V_458 ;
} else {
V_452 = V_459 ;
V_2 -> V_343 . V_457 = V_460 ;
}
V_34 = F_62 ( V_2 -> V_343 . V_457 ,
sizeof( struct V_461 ) , V_462 ) ;
if ( ! V_34 )
return;
V_2 -> V_343 . V_453 = ( V_452 / V_148 ) ;
V_2 -> V_343 . V_454 = V_34 ;
F_64 ( V_22 , L_56 ,
V_148 , V_2 -> V_343 . V_453 ) ;
for ( V_128 = 0 ; V_128 < V_2 -> V_343 . V_457 ; V_128 ++ )
F_288 ( & V_2 -> V_343 . V_454 [ V_128 ] ) ;
V_2 -> V_463 . V_457 = V_2 -> V_343 . V_457 ;
V_34 = F_62 ( V_2 -> V_463 . V_457 ,
sizeof( struct V_461 ) , V_462 ) ;
if ( ! V_34 )
return;
V_2 -> V_463 . V_453 = ( V_452 / V_148 ) ;
V_2 -> V_463 . V_454 = V_34 ;
for ( V_128 = 0 ; V_128 < V_2 -> V_463 . V_457 ; V_128 ++ )
F_288 ( & V_2 -> V_463 . V_454 [ V_128 ] ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
if ( V_2 -> V_343 . V_453 && V_2 -> V_343 . V_454 )
F_7 ( V_2 -> V_343 . V_454 ) ;
V_2 -> V_343 . V_454 = NULL ;
V_2 -> V_343 . V_453 = 0 ;
if ( V_2 -> V_463 . V_453 && V_2 -> V_463 . V_454 )
F_7 ( V_2 -> V_463 . V_454 ) ;
V_2 -> V_463 . V_453 = 0 ;
V_2 -> V_463 . V_454 = NULL ;
}
int F_289 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_464 , V_465 , V_241 = 0 ;
int V_466 = 0 ;
if ( F_61 ( V_2 ) )
V_241 = F_290 ( V_2 -> V_4 , V_467 ) ;
if ( F_53 ( V_2 ) )
V_241 = F_93 ( V_2 , V_468 ) ;
V_464 = F_291 ( V_241 ) ;
V_465 = F_292 ( V_241 ) ;
if ( V_464 == V_469 ) {
F_79 ( & V_22 -> V_30 ,
L_57
L_58 ,
V_465 ) ;
V_466 = 1 ;
} else if ( V_464 == V_470 ) {
if ( V_2 -> V_4 -> V_241 == V_471 ) {
F_79 ( & V_22 -> V_30 ,
L_59
L_60
L_61 ,
V_465 ) ;
}
} else {
if ( V_2 -> V_4 -> V_241 == V_470 ) {
F_67 ( & V_22 -> V_30 ,
L_62
L_63 , V_465 ) ;
}
}
V_2 -> V_4 -> V_241 = V_464 ;
return V_466 ;
}
static inline void F_293 ( struct V_10 * V_11 )
{
int V_128 ;
struct V_472 * V_473 ;
for ( V_128 = 0 ; V_128 < V_11 -> V_395 ; V_128 ++ ) {
V_473 = & V_11 -> V_474 [ V_128 ] ;
F_36 ( L_64 , V_128 ) ;
F_294 ( V_475 , L_65 , V_476 , 16 , 1 ,
& V_11 -> V_474 [ V_128 ] ,
sizeof( struct V_472 ) , true ) ;
}
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_10 * V_11 ;
int V_301 ;
if ( ! V_22 || ! F_171 ( V_22 ) )
return;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
F_64 ( V_22 , L_66 ,
V_301 , V_11 -> V_477 ) ;
F_64 ( V_22 ,
L_67 ,
V_11 -> V_478 . V_479 ,
V_11 -> V_478 . V_480 ,
V_11 -> V_478 . V_481 ,
V_11 -> V_478 . V_482 ) ;
if ( V_11 -> V_483 )
F_64 ( V_22 , L_68 ,
F_296 ( V_11 -> V_483 ) ) ;
F_64 ( V_22 ,
L_69 ,
F_296 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_484 ,
F_297 ( * ( V_11 -> V_485 ) ) ) ;
F_64 ( V_22 , L_70 ,
V_11 -> V_395 , F_298 ( V_11 ) ) ;
if ( F_299 ( V_2 -> V_4 ) )
F_293 ( V_11 ) ;
}
}
static void F_300 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return;
if ( ++ V_2 -> V_486 >= V_487 ) {
F_64 ( V_22 , L_71 ) ;
if ( F_53 ( V_2 ) )
V_2 -> V_273 = 1 ;
else if ( F_61 ( V_2 ) )
F_301 ( V_2 ,
V_488 ) ;
} else {
F_64 ( V_22 , L_72 ) ;
F_295 ( V_2 ) ;
V_2 -> V_4 -> V_340 = 1 ;
}
}
static struct V_489 * F_302 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_489 * V_350 = & V_22 -> V_350 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_303 ( V_2 ) ;
V_350 -> V_327 = V_2 -> V_350 . V_490 + V_2 -> V_350 . V_491 ;
V_350 -> V_323 = V_2 -> V_350 . V_492 ;
V_350 -> V_493 = V_2 -> V_350 . V_494 + V_2 -> V_350 . V_495 ;
V_350 -> V_496 = V_2 -> V_350 . V_497 ;
V_350 -> V_498 = V_2 -> V_350 . V_499 ;
V_350 -> V_500 = V_2 -> V_350 . V_501 ;
return V_350 ;
}
static T_10 F_304 ( struct V_1 * V_2 )
{
T_1 V_502 ;
V_502 = F_296 ( V_2 -> V_123 ) ;
if ( ! ( V_502 & V_2 -> V_4 -> V_121 ) )
return V_503 ;
V_502 = F_296 ( V_2 -> V_125 ) ;
if ( ! F_305 ( V_502 ) )
return V_503 ;
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
F_296 ( V_2 -> V_123 ) ;
F_296 ( V_2 -> V_123 ) ;
return V_504 ;
}
static T_10 V_304 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
if ( V_2 -> V_41 & V_104 )
goto V_505;
else if ( V_2 -> V_41 & V_103 ) {
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
goto V_505;
}
if ( F_306 ( V_2 ) == V_503 )
return V_503 ;
V_505:
V_2 -> V_4 -> V_506 ++ ;
F_204 ( V_2 , V_300 ) ;
return V_504 ;
}
static T_10 V_309 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
if ( F_306 ( V_2 ) == V_503 )
return V_503 ;
F_307 ( & V_300 -> V_507 ) ;
return V_504 ;
}
static T_10 V_308 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
struct V_1 * V_2 = V_300 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_117 ) ;
F_307 ( & V_300 -> V_507 ) ;
return V_504 ;
}
static T_10 V_307 ( int V_118 , void * V_169 )
{
struct V_18 * V_300 = V_169 ;
F_307 ( & V_300 -> V_507 ) ;
return V_504 ;
}
static T_10 V_313 ( int V_118 , void * V_169 )
{
struct V_10 * V_11 = V_169 ;
F_307 ( & V_11 -> V_507 ) ;
return V_504 ;
}
static void F_308 ( struct V_21 * V_22 )
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
F_200 ( V_2 , V_300 ) ;
F_307 ( & V_300 -> V_507 ) ;
}
if ( V_2 -> V_41 & V_104 ) {
if ( ( F_61 ( V_2 ) &&
( V_2 -> V_41 & V_312 ) ) ||
( F_53 ( V_2 ) &&
! F_69 ( V_2 ) ) )
return;
for ( V_301 = 0 ; V_301 < V_2 -> V_90 ; V_301 ++ ) {
V_11 = & V_2 -> V_11 [ V_301 ] ;
F_309 ( V_2 , V_11 ) ;
F_307 ( & V_11 -> V_507 ) ;
}
}
}
static void
F_150 ( struct V_1 * V_2 , T_2 V_508 )
{
T_1 V_509 ;
V_509 = V_2 -> V_431 & 0xf ;
V_509 |= V_508 << 7 ;
V_509 |= ( V_421 - V_2 -> V_420 ) << 8 ;
F_95 ( V_2 , V_510 , V_509 ) ;
V_2 -> V_420 = V_421 ;
}
static int
F_310 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_509 ;
F_311 ( V_46 != V_511 &&
V_46 != V_512 ) ;
if ( F_92 ( V_2 ) )
return - V_110 ;
V_509 = F_93 ( V_2 , V_513 ) ;
if ( V_46 == V_511 )
F_312 ( V_509 , V_2 -> V_431 ) ;
else if ( V_46 == V_512 )
F_313 ( V_509 , V_2 -> V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
F_96 ( V_2 ) ;
return 0 ;
}
static int
F_314 ( struct V_1 * V_2 )
{
T_1 V_509 ;
if ( F_92 ( V_2 ) )
return - V_355 ;
V_509 = F_93 ( V_2 , V_513 ) ;
F_315 ( V_509 , V_2 -> V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
F_96 ( V_2 ) ;
return 0 ;
}
void F_261 ( struct V_1 * V_2 , T_2 V_514 )
{
T_1 V_509 ;
if ( F_92 ( V_2 ) )
goto V_51;
V_509 = F_93 ( V_2 , V_515 ) ;
F_316 ( V_509 , V_2 -> V_431 ) ;
F_95 ( V_2 , V_515 , V_509 ) ;
if ( V_514 ) {
F_95 ( V_2 , V_296 ,
V_298 ) ;
F_67 ( & V_2 -> V_5 -> V_30 ,
L_73 ) ;
} else if ( ! ( V_509 & 0x11111111 ) )
F_95 ( V_2 , V_296 ,
V_516 ) ;
V_509 = F_93 ( V_2 , V_513 ) ;
F_315 ( V_509 , V_2 -> V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
F_96 ( V_2 ) ;
V_51:
V_2 -> V_517 = 0 ;
V_2 -> V_41 &= ~ V_518 ;
F_122 ( V_519 , & V_2 -> V_46 ) ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
}
static int
F_317 ( struct V_1 * V_2 )
{
int V_520 , V_46 , V_521 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_93 ( V_2 , V_513 ) ;
V_520 = F_93 ( V_2 , V_515 ) ;
if ( V_2 -> V_41 & V_522 ) {
V_521 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_520 = V_520 & V_521 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_520 & 0x11111111 ) ) ||
( ( V_520 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_318 ( struct V_1 * V_2 )
{
T_1 V_509 = F_93 ( V_2 , V_523 ) ;
if ( V_509 != V_524 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_74
L_75 , V_524 , V_509 ) ;
}
return 0 ;
}
static int
F_141 ( struct V_1 * V_2 )
{
T_1 V_509 , V_525 ;
T_2 V_526 = V_2 -> V_526 ;
T_2 V_431 = V_2 -> V_431 ;
T_2 V_26 ;
if ( F_174 ( V_519 , & V_2 -> V_46 ) )
return 1 ;
if ( F_92 ( V_2 ) )
return - 1 ;
V_509 = F_93 ( V_2 , V_515 ) ;
if ( ! ( V_509 & ( 1 << ( V_431 * 4 ) ) ) ) {
F_319 ( V_509 , V_431 ) ;
F_95 ( V_2 , V_515 , V_509 ) ;
}
V_525 = F_93 ( V_2 , V_296 ) ;
F_320 ( V_2 , V_527 , L_76 , V_525 ) ;
switch ( V_525 ) {
case V_516 :
F_95 ( V_2 , V_296 ,
V_528 ) ;
F_95 ( V_2 , V_523 ,
V_524 ) ;
F_150 ( V_2 , 0 ) ;
F_96 ( V_2 ) ;
return 1 ;
case V_297 :
V_26 = F_318 ( V_2 ) ;
F_96 ( V_2 ) ;
return V_26 ;
case V_511 :
V_509 = F_93 ( V_2 , V_513 ) ;
F_312 ( V_509 , V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
break;
case V_512 :
V_509 = F_93 ( V_2 , V_513 ) ;
F_313 ( V_509 , V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
break;
case V_298 :
F_79 ( & V_2 -> V_5 -> V_30 , L_77 ) ;
F_96 ( V_2 ) ;
return - 1 ;
case V_528 :
case V_529 :
break;
}
F_96 ( V_2 ) ;
do {
F_137 ( 1000 ) ;
V_525 = F_93 ( V_2 , V_296 ) ;
if ( V_525 == V_529 )
continue;
} while ( ( V_525 != V_297 ) && -- V_526 );
if ( ! V_526 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_78 ) ;
return - 1 ;
}
if ( F_92 ( V_2 ) )
return - 1 ;
V_509 = F_93 ( V_2 , V_513 ) ;
F_315 ( V_509 , V_431 ) ;
F_95 ( V_2 , V_513 , V_509 ) ;
V_26 = F_318 ( V_2 ) ;
F_96 ( V_2 ) ;
return V_26 ;
}
static void
F_321 ( struct V_530 * V_64 )
{
struct V_1 * V_2 = F_322 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
T_1 V_531 = 0xf ;
T_1 V_509 ;
if ( F_92 ( V_2 ) )
goto V_532;
V_531 = F_93 ( V_2 , V_296 ) ;
if ( V_531 == V_529 ||
V_531 == V_512 ) {
F_96 ( V_2 ) ;
F_256 ( V_2 , F_321 ,
V_441 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_143 == V_178 ) {
F_96 ( V_2 ) ;
goto V_533;
}
if ( V_531 == V_528 ||
V_531 == V_297 ) {
F_67 ( & V_2 -> V_5 -> V_30 , L_79
L_80 ) ;
goto V_534;
}
if ( V_2 -> V_535 ++ > V_2 -> V_536 ) {
F_67 ( & V_2 -> V_5 -> V_30 , L_81 ,
V_2 -> V_536 ) ;
goto V_534;
}
if ( ! F_317 ( V_2 ) ) {
V_534:
V_531 = F_93 ( V_2 , V_296 ) ;
if ( V_531 == V_511 ) {
F_95 ( V_2 , V_296 ,
V_528 ) ;
F_119 ( V_519 , & V_2 -> V_46 ) ;
F_320 ( V_2 , V_537 , L_82 ) ;
F_150 ( V_2 , 0 ) ;
V_509 = F_93 ( V_2 ,
V_513 ) ;
F_312 ( V_509 , V_2 -> V_431 ) ;
F_95 ( V_2 ,
V_513 , V_509 ) ;
}
F_96 ( V_2 ) ;
F_170 () ;
if ( F_323 ( V_2 ) &&
( V_2 -> V_41 & V_522 ) ) {
F_320 ( V_2 , V_537 , L_83 ) ;
F_324 ( V_2 ) ;
V_2 -> V_41 |= V_518 ;
}
F_172 () ;
V_2 -> V_41 &= ~ V_522 ;
if ( ! V_2 -> V_179 -> V_538 ( V_2 ) ) {
F_256 ( V_2 , V_539 , 0 ) ;
V_2 -> V_535 = 0 ;
return;
}
goto V_532;
}
F_96 ( V_2 ) ;
V_533:
V_531 = F_93 ( V_2 , V_296 ) ;
F_320 ( V_2 , V_527 , L_84 , V_531 ) ;
switch ( V_531 ) {
case V_297 :
if ( ! F_246 ( V_2 ) ) {
F_256 ( V_2 , V_539 , 0 ) ;
V_2 -> V_535 = 0 ;
return;
}
case V_298 :
break;
default:
F_256 ( V_2 ,
F_321 , V_441 ) ;
return;
}
V_532:
F_79 ( & V_2 -> V_5 -> V_30 , L_85
L_86 , V_531 , V_2 -> V_535 ) ;
F_25 ( V_2 -> V_22 ) ;
F_261 ( V_2 , 0 ) ;
}
static void
F_325 ( struct V_530 * V_64 )
{
struct V_1 * V_2 = F_322 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_502 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_531 == V_512 ) {
if ( F_171 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
} else
F_185 ( V_2 , V_22 ) ;
V_502 = F_93 ( V_2 , V_540 ) ;
if ( V_502 & V_541 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_87 ,
V_502 ) ;
if ( F_326 ( V_502 ) == V_542 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_88
L_89 ) ;
F_79 ( & V_2 -> V_5 -> V_30 ,
L_90 ) ;
}
goto V_532;
}
if ( V_2 -> V_4 -> V_241 == V_469 ) {
F_79 ( & V_2 -> V_5 -> V_30 , L_91 ,
V_2 -> V_4 -> V_241 ) ;
goto V_532;
}
if ( ! ( V_2 -> V_41 & V_522 ) ) {
if ( F_310 ( V_2 , V_2 -> V_531 ) ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_92
L_93 ) ;
goto V_532;
}
}
V_2 -> V_535 = 0 ;
F_256 ( V_2 , F_321 , V_441 ) ;
return;
V_532:
F_25 ( V_22 ) ;
F_261 ( V_2 , 1 ) ;
}
static void
F_327 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_93 ( V_2 , V_287 ) ;
if ( V_46 == V_543 )
return;
if ( F_92 ( V_2 ) )
return;
F_95 ( V_2 , V_287 ,
V_543 ) ;
F_96 ( V_2 ) ;
}
static void F_328 ( struct V_1 * V_2 ,
T_1 V_544 )
{
T_1 V_46 , V_545 = 0 , V_546 = 0 ;
F_329 ( V_545 ) ;
F_330 ( V_545 ) ;
F_148 ( V_2 , V_547 , V_545 ) ;
F_331 ( V_546 ) ;
F_332 ( V_546 ) ;
F_333 ( V_546 ) ;
F_334 ( V_546 ) ;
F_148 ( V_2 , V_548 , V_546 ) ;
F_67 ( & V_2 -> V_5 -> V_30 , L_94
L_95 ) ;
V_2 -> V_273 = 1 ;
if ( F_92 ( V_2 ) )
return;
V_46 = F_93 ( V_2 , V_296 ) ;
if ( F_21 ( V_442 , & V_2 -> V_46 ) ) {
F_118 ( V_2 -> V_22 , L_55 ,
V_54 ) ;
F_96 ( V_2 ) ;
return;
}
if ( V_46 == V_297 ) {
F_95 ( V_2 , V_296 ,
V_511 ) ;
V_2 -> V_41 |= V_522 ;
F_320 ( V_2 , V_537 , L_96 ) ;
F_150 ( V_2 , 0 ) ;
}
F_95 ( V_2 , V_287 ,
V_543 ) ;
F_96 ( V_2 ) ;
}
static void
F_139 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
return;
F_95 ( V_2 , V_287 ,
V_288 ) ;
F_320 ( V_2 , V_537 , L_97 ) ;
F_96 ( V_2 ) ;
}
void F_256 ( struct V_1 * V_2 ,
T_11 V_65 , int V_549 )
{
if ( F_21 ( V_550 , & V_2 -> V_46 ) )
return;
F_335 ( & V_2 -> V_63 , V_65 ) ;
F_336 ( V_2 -> V_417 , & V_2 -> V_63 ,
F_337 ( V_549 ) ) ;
}
static void
V_539 ( struct V_530 * V_64 )
{
struct V_1 * V_2 = F_322 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_286 ;
if ( V_2 -> V_4 -> V_143 != V_144 ) {
V_286 = F_93 ( V_2 ,
V_287 ) ;
if ( V_2 -> V_535 ++ > V_285 )
F_261 ( V_2 , 0 ) ;
else if ( V_286 != V_288 )
F_256 ( V_2 , V_539 ,
V_441 ) ;
else
goto V_551;
F_320 ( V_2 , V_537 , L_98 ) ;
return;
}
V_551:
F_253 ( V_2 -> V_392 ) ;
if ( F_171 ( V_22 ) ) {
if ( F_169 ( V_2 , V_22 ) )
goto V_505;
F_121 ( V_22 , V_356 ) ;
}
V_505:
F_25 ( V_22 ) ;
V_2 -> V_517 = 0 ;
V_2 -> V_41 &= ~ V_518 ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
if ( V_2 -> V_431 == 0 )
F_227 ( V_2 ) ;
if ( ! F_314 ( V_2 ) )
F_256 ( V_2 , V_440 ,
V_441 ) ;
}
static int
F_338 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_209 * V_210 = & V_4 -> V_210 ;
T_1 V_46 = 0 , V_552 ;
T_1 V_553 ;
int V_51 = 0 ;
if ( F_289 ( V_2 ) )
goto V_554;
if ( V_2 -> V_273 )
F_339 ( V_2 , 0 ) ;
V_46 = F_93 ( V_2 , V_296 ) ;
if ( V_46 == V_511 ) {
F_327 ( V_2 ) ;
V_2 -> V_273 = 1 ;
} else if ( V_46 == V_512 )
goto V_554;
V_552 = F_93 ( V_2 , V_555 ) ;
if ( V_552 != V_2 -> V_552 ) {
V_2 -> V_552 = V_552 ;
V_2 -> V_517 = 0 ;
if ( V_2 -> V_273 )
goto V_554;
if ( V_4 -> V_340 && V_556 )
F_205 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_517 < V_557 )
return 0 ;
V_2 -> V_41 |= V_518 ;
F_339 ( V_2 , 0 ) ;
if ( V_556 )
F_122 ( V_558 , & V_2 -> V_46 ) ;
F_79 ( & V_2 -> V_5 -> V_30 , L_99 ) ;
V_553 = F_93 ( V_2 , V_540 ) ;
F_79 ( & V_2 -> V_5 -> V_30 , L_100
L_101
L_102
L_103
L_104 ,
V_553 ,
F_93 ( V_2 , V_559 ) ,
F_114 ( V_2 , V_560 + 0x3c , & V_51 ) ,
F_114 ( V_2 , V_561 + 0x3c , & V_51 ) ,
F_114 ( V_2 , V_562 + 0x3c , & V_51 ) ,
F_114 ( V_2 , V_563 + 0x3c , & V_51 ) ,
F_114 ( V_2 , V_564 + 0x3c , & V_51 ) ) ;
if ( F_326 ( V_553 ) == 0x67 )
F_79 ( & V_2 -> V_5 -> V_30 ,
L_105
L_106 ) ;
V_554:
V_2 -> V_531 = ( V_46 == V_512 ) ? V_46 :
V_511 ;
if ( V_556 && ! F_44 ( V_62 ,
& V_2 -> V_46 ) ) {
F_256 ( V_2 , F_325 , 0 ) ;
F_320 ( V_2 , V_537 , L_107 ) ;
} else if ( ! V_556 && V_210 -> V_565 &&
V_2 -> V_41 & V_522 ) {
F_324 ( V_2 ) ;
}
return 1 ;
}
void V_440 ( struct V_530 * V_64 )
{
struct V_1 * V_2 = F_322 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
goto V_566;
if ( F_338 ( V_2 ) )
return;
if ( V_2 -> V_343 . V_344 )
F_340 ( V_2 ) ;
V_566:
F_256 ( V_2 , V_440 , V_441 ) ;
}
static int F_341 ( struct V_23 * V_5 )
{
struct V_23 * V_567 ;
int V_509 = V_5 -> V_568 ;
while ( V_509 -- > 0 ) {
V_567 = F_342 ( F_343
( V_5 -> V_569 ) , V_5 -> V_569 -> V_570 ,
F_344 ( F_345 ( V_5 -> V_568 ) , V_509 ) ) ;
if ( ! V_567 )
continue;
if ( V_567 -> V_571 != V_572 ) {
F_346 ( V_567 ) ;
return 0 ;
}
F_346 ( V_567 ) ;
}
return 1 ;
}
static int F_347 ( struct V_23 * V_5 )
{
int V_51 , V_573 ;
struct V_1 * V_2 = F_267 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_574 = V_575 ;
V_51 = F_231 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_234 ( V_5 ) ;
F_284 ( V_5 ) ;
V_573 = F_341 ( V_5 ) ;
if ( F_92 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_143 != V_178 && V_573 ) {
V_2 -> V_273 = 1 ;
F_119 ( V_519 , & V_2 -> V_46 ) ;
F_95 ( V_2 , V_296 ,
V_528 ) ;
F_320 ( V_2 , V_537 , L_82 ) ;
}
F_96 ( V_2 ) ;
V_51 = F_246 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_314 ( V_2 ) ;
F_7 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
V_51 = F_254 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_98 ) ;
F_118 ( V_22 , L_33 ) ;
return V_51 ;
}
if ( F_171 ( V_22 ) ) {
V_51 = F_186 ( V_2 ) ;
if ( V_51 ) {
F_261 ( V_2 , 1 ) ;
F_122 ( V_550 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_51 ;
}
V_51 = F_169 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_505;
F_121 ( V_22 , V_356 ) ;
}
V_505:
F_25 ( V_22 ) ;
return V_51 ;
}
static T_12 F_348 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_267 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_576 )
return V_577 ;
if ( V_46 == V_575 )
return V_578 ;
F_119 ( V_550 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_46 ( & V_2 -> V_63 ) ;
if ( F_171 ( V_22 ) )
F_185 ( V_2 , V_22 ) ;
F_196 ( V_2 ) ;
F_80 ( V_2 ) ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
F_349 ( V_5 ) ;
F_265 ( V_5 ) ;
return V_579 ;
}
static T_12 F_350 ( struct V_23 * V_5 )
{
return F_347 ( V_5 ) ? V_577 :
V_578 ;
}
static void F_351 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_267 ( V_5 ) ;
F_352 ( V_5 ) ;
V_46 = F_93 ( V_2 , V_296 ) ;
if ( V_46 == V_297 && F_174 ( V_550 ,
& V_2 -> V_46 ) )
F_256 ( V_2 , V_440 ,
V_441 ) ;
}
static T_12 F_353 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_267 ( V_5 ) ;
struct V_580 * V_410 = V_2 -> V_4 -> V_410 ;
if ( V_410 -> V_581 ) {
return V_410 -> V_581 ( V_5 , V_46 ) ;
} else {
F_79 ( & V_5 -> V_30 , L_108 ) ;
return V_577 ;
}
}
static T_12 F_354 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_267 ( V_5 ) ;
struct V_580 * V_410 = V_2 -> V_4 -> V_410 ;
if ( V_410 -> V_582 ) {
return V_410 -> V_582 ( V_5 ) ;
} else {
F_79 ( & V_5 -> V_30 , L_109 ) ;
return V_577 ;
}
}
static void F_355 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_267 ( V_5 ) ;
struct V_580 * V_410 = V_2 -> V_4 -> V_410 ;
if ( V_410 -> V_583 )
V_410 -> V_583 ( V_5 ) ;
else
F_79 ( & V_5 -> V_30 , L_110 ) ;
}
static int
F_356 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_141 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_136 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_112 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_108 ( V_2 ) ;
V_51 = F_124 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_273 = 0 ;
return V_51 ;
}
int F_357 ( struct V_1 * V_2 , T_14 V_80 ,
int V_81 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_584 = 0 ;
char V_585 [ 8 ] ;
int V_586 ;
if ( V_81 == V_85 ) {
V_584 = V_2 -> V_86 ;
V_586 = V_2 -> V_92 ;
strcpy ( V_585 , L_111 ) ;
} else if ( V_81 == V_87 ) {
V_584 = V_2 -> V_88 ;
V_586 = V_2 -> V_90 ;
strcpy ( V_585 , L_112 ) ;
}
if ( ! F_152 ( V_2 ) ) {
F_118 ( V_22 , L_113 ) ;
return - V_40 ;
}
if ( V_2 -> V_41 & V_103 ) {
F_118 ( V_22 , L_114 ) ;
return - V_40 ;
}
if ( ! F_358 ( V_80 ) ) {
F_118 ( V_22 , L_115 ,
V_585 ) ;
return - V_40 ;
}
if ( F_53 ( V_2 ) && ( V_81 == V_87 ) &&
! F_69 ( V_2 ) ) {
F_118 ( V_22 , L_116 ) ;
return - V_40 ;
}
if ( V_80 > F_57 () ) {
F_118 ( V_22 ,
L_117 ,
V_585 , F_57 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_359 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_587 , V_588 ;
int V_51 ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return - V_355 ;
V_587 = V_2 -> V_96 ;
V_588 = V_2 -> V_97 ;
F_22 ( V_22 ) ;
V_51 = F_208 ( V_2 , V_587 , V_588 ) ;
if ( V_51 )
goto V_505;
if ( F_171 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
F_196 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
F_259 ( V_2 ) ;
F_360 ( V_2 ) ;
}
F_80 ( V_2 ) ;
V_51 = F_254 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_98 ) ;
F_118 ( V_22 , L_33 ) ;
return V_51 ;
}
if ( ( V_587 != V_2 -> V_90 ) ||
( V_588 != V_2 -> V_92 ) ) {
V_51 = F_208 ( V_2 ,
V_2 -> V_90 ,
V_2 -> V_92 ) ;
if ( V_51 )
goto V_505;
}
if ( F_61 ( V_2 ) ) {
F_271 ( V_2 , 1 ) ;
V_51 = F_361 ( V_2 ) ;
F_362 ( V_2 ) ;
if ( V_51 ) {
F_79 ( & V_2 -> V_5 -> V_30 ,
L_118 ) ;
goto V_505;
}
}
if ( F_171 ( V_22 ) ) {
V_51 = F_186 ( V_2 ) ;
if ( V_51 )
goto V_505;
V_51 = F_161 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_505;
F_121 ( V_22 , V_356 ) ;
}
V_505:
F_25 ( V_22 ) ;
F_122 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_363 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_589 )
{
struct V_590 * V_591 ;
V_591 = F_364 ( V_30 ) ;
if ( ! V_591 )
return;
F_365 (indev) {
switch ( V_589 ) {
case V_356 :
F_366 ( V_2 ,
V_592 -> V_593 , V_594 ) ;
break;
case V_262 :
F_366 ( V_2 ,
V_592 -> V_593 , V_595 ) ;
break;
default:
break;
}
} F_367 ( V_591 ) ;
F_368 ( V_591 ) ;
}
void F_121 ( struct V_21 * V_22 , unsigned long V_589 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_260 ;
F_363 ( V_2 , V_22 , V_589 ) ;
F_369 () ;
F_370 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_371 ( V_22 , F_372 ( V_596 ) , V_260 ) ;
if ( ! V_30 )
continue;
F_363 ( V_2 , V_30 , V_589 ) ;
}
F_373 () ;
}
static int F_374 ( struct V_597 * V_598 ,
unsigned long V_589 , void * V_599 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_375 ( V_599 ) ;
V_600:
if ( V_30 == NULL )
goto V_505;
if ( V_30 -> V_390 & V_601 ) {
V_30 = F_376 ( V_30 ) ;
goto V_600;
}
if ( ! F_377 ( V_30 ) )
goto V_505;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_505;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_505;
F_363 ( V_2 , V_30 , V_589 ) ;
V_505:
return V_602 ;
}
static int
F_378 ( struct V_597 * V_598 ,
unsigned long V_589 , void * V_599 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_603 * V_592 = (struct V_603 * ) V_599 ;
V_30 = V_592 -> V_604 ? V_592 -> V_604 -> V_30 : NULL ;
V_600:
if ( V_30 == NULL )
goto V_505;
if ( V_30 -> V_390 & V_601 ) {
V_30 = F_376 ( V_30 ) ;
goto V_600;
}
if ( ! F_377 ( V_30 ) )
goto V_505;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_505;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_505;
switch ( V_589 ) {
case V_356 :
F_366 ( V_2 , V_592 -> V_593 , V_594 ) ;
break;
case V_262 :
F_366 ( V_2 , V_592 -> V_593 , V_595 ) ;
break;
default:
break;
}
V_505:
return V_602 ;
}
void F_121 ( struct V_21 * V_30 , unsigned long V_589 )
{ }
static int T_15 F_379 ( void )
{
int V_26 ;
F_380 ( V_475 L_119 , V_605 ) ;
#ifdef F_381
F_382 ( & V_606 ) ;
F_383 ( & V_607 ) ;
#endif
V_26 = F_384 ( & V_608 ) ;
if ( V_26 ) {
#ifdef F_381
F_385 ( & V_607 ) ;
F_386 ( & V_606 ) ;
#endif
}
return V_26 ;
}
static void T_16 F_387 ( void )
{
F_388 ( & V_608 ) ;
#ifdef F_381
F_385 ( & V_607 ) ;
F_386 ( & V_606 ) ;
#endif
}
