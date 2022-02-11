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
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_49 ( V_2 ) &&
( V_4 -> V_72 [ 0 ] & V_73 ) ) {
F_44 ( V_74 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_50 ( struct V_1 * V_2 , T_2 V_75 ,
int V_76 )
{
int V_77 , V_78 = V_79 ;
if ( V_76 == V_80 )
V_78 = V_2 -> V_81 ;
else if ( V_76 == V_82 )
V_78 = V_2 -> V_83 ;
V_77 = F_51 ( F_52 ( int , F_53 () ,
V_78 ) ) ;
if ( V_75 > V_77 )
return V_77 ;
else
return V_75 ;
}
void F_54 ( struct V_1 * V_2 , T_2 V_84 )
{
if ( V_2 -> V_83 )
V_2 -> V_85 = F_50 ( V_2 , V_84 ,
V_82 ) ;
else
V_2 -> V_85 = V_84 ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_86 )
{
if ( V_2 -> V_81 )
V_2 -> V_87 = F_50 ( V_2 , V_86 ,
V_80 ) ;
else
V_2 -> V_87 = V_86 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_88 = 0 , V_51 = 0 , V_89 ;
V_2 -> V_41 &= ~ V_90 ;
if ( V_2 -> V_91 > 0 )
V_88 += V_2 -> V_91 ;
else
V_88 += V_2 -> V_85 ;
if ( V_2 -> V_92 > 0 )
V_88 += V_2 -> V_92 ;
else
V_88 += V_2 -> V_87 ;
if ( F_57 ( V_2 ) )
V_88 += 1 ;
if ( ! V_2 -> V_93 ) {
V_2 -> V_93 = F_58 ( V_88 ,
sizeof( struct V_94 ) ,
V_20 ) ;
if ( ! V_2 -> V_93 )
return - V_56 ;
}
V_95:
for ( V_89 = 0 ; V_89 < V_88 ; V_89 ++ )
V_2 -> V_93 [ V_89 ] . V_96 = V_89 ;
V_51 = F_59 ( V_5 , V_2 -> V_93 , V_88 ) ;
if ( V_51 == 0 ) {
V_2 -> V_4 -> V_88 = V_88 ;
if ( V_2 -> V_91 > 0 )
V_2 -> V_85 = V_2 -> V_91 ;
if ( V_2 -> V_92 > 0 )
V_2 -> V_87 = V_2 -> V_92 ;
} else {
F_60 ( V_2 -> V_22 ,
L_3 ,
V_88 , V_51 ) ;
V_88 = V_2 -> V_85 + V_2 -> V_87 ;
V_2 -> V_91 = 0 ;
V_2 -> V_92 = 0 ;
if ( F_57 ( V_2 ) )
V_88 += 1 ;
F_60 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_85 , V_2 -> V_87 ,
V_88 ) ;
goto V_95;
V_51 = - V_97 ;
}
return V_51 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_88 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 = - 1 , V_89 ;
if ( ! V_2 -> V_93 ) {
V_2 -> V_93 = F_58 ( V_88 ,
sizeof( struct V_94 ) ,
V_20 ) ;
if ( ! V_2 -> V_93 )
return - V_56 ;
}
V_2 -> V_41 &= ~ ( V_98 | V_99 ) ;
if ( V_2 -> V_4 -> V_100 ) {
V_101:
for ( V_89 = 0 ; V_89 < V_88 ; V_89 ++ )
V_2 -> V_93 [ V_89 ] . V_96 = V_89 ;
V_51 = F_59 ( V_5 , V_2 -> V_93 , V_88 ) ;
if ( V_51 == 0 ) {
V_2 -> V_41 |= V_99 ;
V_2 -> V_4 -> V_88 = V_88 ;
F_62 ( & V_5 -> V_30 , L_5 ) ;
return V_51 ;
} else if ( V_51 > 0 ) {
F_62 ( & V_5 -> V_30 ,
L_3 ,
V_88 , V_51 ) ;
if ( F_49 ( V_2 ) ) {
V_88 = F_51 ( V_51 ) ;
if ( V_51 < V_102 )
return - V_97 ;
} else {
V_88 = F_51 ( V_51 - 1 ) ;
V_88 += 1 ;
if ( V_51 < V_103 )
return - V_97 ;
}
if ( F_49 ( V_2 ) &&
! F_63 ( V_2 ) ) {
V_2 -> V_87 = V_88 ;
V_2 -> V_85 = V_104 ;
} else {
V_2 -> V_85 = V_88 / 2 ;
V_2 -> V_87 = V_2 -> V_85 ;
}
if ( V_88 ) {
F_62 ( & V_5 -> V_30 ,
L_6 ,
V_88 ) ;
goto V_101;
}
} else {
F_62 ( & V_5 -> V_30 ,
L_7 ,
V_88 , V_51 ) ;
return V_51 ;
}
}
return V_51 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = V_2 -> V_87 ;
if ( F_63 ( V_2 ) )
V_88 += V_2 -> V_85 ;
else
V_88 += V_104 ;
return V_88 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_105 , V_106 ;
const struct V_107 * V_108 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_109 && ! F_66 ( V_5 ) ) {
V_2 -> V_41 |= V_98 ;
V_105 = V_110 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_111 = F_67 ( V_2 -> V_4 ,
V_105 ) ;
F_62 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_93 [ 0 ] . V_89 = V_5 -> V_112 ;
return V_51 ;
}
if ( V_109 || V_113 )
return - V_43 ;
V_108 = & V_114 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_115 = V_108 -> V_115 ;
V_105 = V_108 -> V_111 ;
V_2 -> V_111 = F_67 ( V_4 , V_105 ) ;
V_106 = V_108 -> V_116 ;
V_2 -> V_116 = F_67 ( V_4 , V_106 ) ;
V_2 -> V_117 = F_67 ( V_4 , V_118 ) ;
V_2 -> V_119 = F_67 ( V_4 , V_120 ) ;
F_62 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_93 [ 0 ] . V_89 = V_5 -> V_112 ;
return V_51 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_88 , V_51 = 0 ;
if ( V_2 -> V_41 & V_90 ) {
V_51 = F_56 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_88 = V_2 -> V_4 -> V_88 ;
} else {
V_88 = F_64 ( V_2 ) ;
V_51 = F_61 ( V_2 , V_88 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_99 ) ) {
F_69 ( V_2 ) ;
V_2 -> V_87 = V_104 ;
V_51 = F_65 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
int F_70 ( struct V_1 * V_2 , int V_121 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_122 ;
if ( F_63 ( V_2 ) &&
! V_4 -> V_123 &&
( V_2 -> V_41 & V_99 ) ) {
V_4 -> V_124 = F_71 ( V_4 -> V_88 *
sizeof( struct V_125 ) ) ;
if ( ! V_4 -> V_124 )
return - V_56 ;
for ( V_122 = 0 ; V_122 < V_4 -> V_88 ; V_122 ++ ) {
V_4 -> V_124 [ V_122 ] . type = V_126 ;
V_4 -> V_124 [ V_122 ] . V_71 = V_122 ;
V_4 -> V_124 [ V_122 ] . V_127 = 0 ;
}
V_51 = F_72 ( V_2 , 1 ) ;
if ( V_51 )
F_73 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_88 ) ;
return V_51 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_99 )
F_75 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_98 )
F_76 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
if ( V_2 -> V_4 -> V_124 ) {
F_77 ( V_2 -> V_4 -> V_124 ) ;
V_2 -> V_4 -> V_124 = NULL ;
}
}
static void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_128 != NULL )
F_79 ( V_4 -> V_128 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_129 * V_130 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
switch ( V_4 -> V_131 ) {
case V_132 :
V_4 -> V_133 = V_134 ;
break;
case V_135 :
V_4 -> V_133 = V_136 ;
break;
}
return 0 ;
}
if ( V_4 -> V_137 == V_138 )
return 0 ;
V_130 = F_58 ( V_4 -> V_139 , sizeof( * V_130 ) , V_20 ) ;
if ( ! V_130 )
return - V_56 ;
V_26 = F_81 ( V_2 , V_130 ) ;
F_7 ( V_130 ) ;
return V_26 ;
}
static bool F_82 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_83 ( V_2 ) ) {
V_26 = true ;
} else if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_72 [ 0 ] &
V_140 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_129 * V_130 ;
int V_122 , V_71 = 0 , V_26 = 0 , V_141 = 0 ;
T_3 V_142 ;
T_2 V_143 ;
V_130 = F_58 ( V_4 -> V_139 , sizeof( * V_130 ) , V_20 ) ;
if ( ! V_130 )
return - V_56 ;
V_26 = F_81 ( V_2 , V_130 ) ;
if ( V_26 )
goto V_144;
V_142 = V_4 -> V_133 ;
V_2 -> V_145 = F_5 ( sizeof( struct V_146 ) *
V_142 , V_20 ) ;
if ( ! V_2 -> V_145 ) {
V_26 = - V_56 ;
goto V_144;
}
V_2 -> V_147 = F_5 ( sizeof( struct V_148 ) *
V_136 , V_20 ) ;
if ( ! V_2 -> V_147 ) {
V_26 = - V_56 ;
goto V_149;
}
for ( V_122 = 0 ; V_122 < V_4 -> V_139 ; V_122 ++ ) {
V_143 = V_130 [ V_122 ] . V_71 ;
if ( V_143 >= V_4 -> V_139 ) {
V_26 = V_150 ;
goto V_151;
}
if ( ! V_130 [ V_122 ] . V_152 ||
( V_130 [ V_122 ] . type != V_153 ) )
continue;
if ( F_82 ( V_2 ) ) {
if ( ! F_85 ( V_2 , V_143 ,
& V_71 ) )
V_2 -> V_145 [ V_141 ] . V_154 = true ;
else
continue;
} else {
V_2 -> V_145 [ V_141 ] . V_154 = true ;
}
V_2 -> V_145 [ V_141 ] . V_27 = V_143 ;
V_2 -> V_145 [ V_141 ] . V_152 = ( T_2 ) V_130 [ V_122 ] . V_152 ;
V_2 -> V_145 [ V_141 ] . type = ( T_2 ) V_130 [ V_122 ] . type ;
V_2 -> V_145 [ V_141 ] . V_155 = ( T_2 ) V_130 [ V_122 ] . V_156 ;
V_2 -> V_145 [ V_141 ] . V_157 = V_130 [ V_122 ] . V_158 ;
V_2 -> V_145 [ V_141 ] . V_159 = V_130 [ V_122 ] . V_160 ;
memcpy ( & V_2 -> V_145 [ V_141 ] . V_161 , & V_130 [ V_122 ] . V_161 , V_25 ) ;
V_141 ++ ;
}
if ( ! F_82 ( V_2 ) ) {
for ( V_122 = 0 ; V_122 < V_136 ; V_122 ++ )
V_2 -> V_147 [ V_122 ] . V_41 |= V_162 ;
}
F_7 ( V_130 ) ;
return 0 ;
V_151:
F_7 ( V_2 -> V_147 ) ;
V_2 -> V_147 = NULL ;
V_149:
F_7 ( V_2 -> V_145 ) ;
V_2 -> V_145 = NULL ;
V_144:
F_7 ( V_130 ) ;
return V_26 ;
}
static int
F_86 ( struct V_1 * V_2 )
{
T_2 V_71 ;
int V_26 ;
T_1 V_163 = V_138 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_87 ( V_2 ) ;
if ( V_26 )
goto V_164;
V_71 = V_4 -> V_27 ;
V_163 = F_88 ( V_2 , V_165 ) ;
V_163 = ( V_163 & ~ F_89 ( 0xf , V_71 ) ) |
F_89 ( V_138 , V_71 ) ;
F_90 ( V_2 , V_165 , V_163 ) ;
F_91 ( V_2 ) ;
V_164:
return V_26 ;
}
static void F_92 ( struct V_1 * V_2 ,
const struct V_166 * V_167 )
{
T_1 V_137 , V_168 ;
V_2 -> V_4 -> V_169 = F_88 ( V_2 ,
V_170 ) ;
F_93 ( V_2 ) ;
V_137 = F_88 ( V_2 , V_165 ) ;
if ( V_137 == V_171 )
V_168 = V_138 ;
else
V_168 = F_94 ( V_137 , V_2 -> V_4 -> V_27 ) ;
if ( V_168 == V_172 ) {
V_2 -> V_4 -> V_137 = V_172 ;
F_62 ( & V_2 -> V_5 -> V_30 ,
L_11 ,
V_2 -> V_4 -> V_169 ) ;
V_2 -> V_173 = & V_174 ;
} else
V_2 -> V_173 = & V_175 ;
}
static void F_95 ( T_1 V_176 , T_4 * V_177 )
{
switch ( V_176 ) {
case V_7 :
* V_177 = V_178 ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
* V_177 = V_183 ;
break;
default:
* V_177 = 0 ;
}
}
static int F_96 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_105 ;
void T_5 * V_184 = NULL ;
unsigned long V_185 , V_186 = 0 , V_187 ;
V_185 = F_97 ( V_5 , 0 ) ;
F_95 ( V_5 -> V_6 , & V_187 ) ;
if ( V_185 >= V_187 ) {
V_184 = F_98 ( V_5 , 0 ) ;
if ( V_184 == NULL ) {
F_73 ( & V_5 -> V_30 , L_12 ) ;
return - V_97 ;
}
V_186 = V_185 ;
} else {
return - V_97 ;
}
F_62 ( & V_5 -> V_30 , L_13 , ( int ) ( V_185 >> 10 ) ) ;
V_4 -> V_128 = V_184 ;
V_4 -> V_186 = V_186 ;
V_105 = F_99 ( F_100 ( V_4 -> V_27 ) ) ;
F_67 ( V_4 , V_105 ) ;
return 0 ;
}
static bool F_101 ( struct V_1 * V_2 ,
int V_188 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_189 ;
bool V_26 = true ;
V_189 = V_5 -> V_189 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_179 ) {
if ( V_190 [ V_188 ] . V_191 == V_189 &&
V_190 [ V_188 ] . V_192 == V_5 -> V_193 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_102 ( struct V_1 * V_2 , char * V_194 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_122 , V_195 = 0 ;
for ( V_122 = 0 ; V_122 < V_196 ; ++ V_122 ) {
if ( V_190 [ V_122 ] . V_197 == V_5 -> V_197 &&
V_190 [ V_122 ] . V_6 == V_5 -> V_6 &&
F_101 ( V_2 , V_122 ) ) {
V_195 = 1 ;
break;
}
}
if ( ! V_195 )
sprintf ( V_194 , L_14 , V_2 -> V_24 ) ;
else
sprintf ( V_194 , L_15 , V_2 -> V_24 ,
V_190 [ V_122 ] . V_198 ) ;
}
static void
F_103 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_199 , V_200 , V_201 , V_202 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_203 * V_204 = & V_4 -> V_204 ;
V_202 = V_2 -> V_205 ;
V_199 = F_88 ( V_2 , V_206 ) ;
V_200 = F_88 ( V_2 , V_207 ) ;
V_201 = F_88 ( V_2 , V_208 ) ;
V_2 -> V_205 = F_104 ( V_199 , V_200 , V_201 ) ;
V_51 = F_105 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_16 ) ;
return;
}
if ( V_4 -> V_137 != V_172 ) {
if ( V_204 -> V_209 == NULL ||
V_2 -> V_205 > V_202 ) {
if ( V_204 -> V_209 )
F_77 ( V_204 -> V_209 ) ;
if ( ! F_106 ( V_2 ) )
F_62 ( & V_5 -> V_30 ,
L_17 ) ;
}
}
F_62 ( & V_5 -> V_30 , L_18 ,
V_210 , V_199 , V_200 , V_201 ) ;
if ( V_2 -> V_4 -> V_131 == V_135 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_211 = V_212 ;
V_2 -> V_213 = V_214 ;
} else {
V_2 -> V_211 = V_215 ;
V_2 -> V_213 = V_216 ;
}
V_2 -> V_217 = V_218 ;
V_2 -> V_219 = V_218 ;
} else if ( V_2 -> V_4 -> V_131 == V_132 ) {
V_2 -> V_211 = V_220 ;
V_2 -> V_217 = V_221 ;
V_2 -> V_219 = V_221 ;
V_2 -> V_213 = V_222 ;
}
V_2 -> V_4 -> V_100 = ! ! V_113 ;
V_2 -> V_223 = V_224 ;
V_2 -> V_225 = V_226 ;
}
static int
F_107 ( struct V_1 * V_2 )
{
struct V_227 V_228 ;
int V_51 = 0 ;
memset ( & V_228 , 0 , sizeof( struct V_227 ) ) ;
V_51 = F_108 ( V_2 , & V_228 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_229 = ( T_2 ) V_228 . V_230 ;
V_2 -> V_4 -> V_231 = V_228 . V_231 ;
V_2 -> V_4 -> V_232 = V_228 . V_232 ;
V_2 -> V_4 -> V_233 = V_228 . V_233 ;
V_2 -> V_4 -> V_8 = V_228 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_234 ) {
T_1 V_235 ;
V_235 = F_109 ( V_2 , V_236 , & V_51 ) ;
if ( V_51 == - V_97 )
return V_51 ;
V_2 -> V_4 -> V_72 [ 0 ] = V_235 ;
} else {
V_2 -> V_4 -> V_72 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_237 = V_228 . V_237 ;
V_2 -> V_4 -> V_238 = V_228 . V_238 ;
if ( V_2 -> V_4 -> V_8 & V_239 ) {
V_2 -> V_41 |= V_53 ;
V_2 -> V_4 -> V_240 = V_241 ;
V_2 -> V_83 = V_242 ;
V_2 -> V_81 = V_243 ;
F_62 ( & V_2 -> V_5 -> V_30 , L_19 ) ;
} else {
V_2 -> V_4 -> V_240 = V_244 ;
V_2 -> V_83 = V_245 ;
V_2 -> V_81 = V_79 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_110 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
if ( V_247 -> V_248 )
V_2 -> V_41 &= ~ V_249 ;
else
V_2 -> V_41 |= V_249 ;
if ( V_247 -> V_250 ) {
V_2 -> V_251 = V_247 -> V_250 ;
V_2 -> V_252 = V_247 -> V_250 ;
} else {
V_2 -> V_251 = 0 ;
V_2 -> V_252 = 0 ;
}
}
static int
F_111 ( struct V_21 * V_22 , T_6 V_253 , T_3 V_254 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_112 ( V_2 , V_254 , 1 ) ;
if ( V_51 ) {
F_113 ( V_22 ,
L_20 ,
V_254 , V_51 ) ;
return V_51 ;
}
}
F_114 ( V_254 , V_2 -> V_255 ) ;
return 0 ;
}
static int
F_115 ( struct V_21 * V_22 , T_6 V_253 , T_3 V_254 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_112 ( V_2 , V_254 , 0 ) ;
if ( V_51 ) {
F_113 ( V_22 ,
L_21 ,
V_254 , V_51 ) ;
return V_51 ;
}
}
F_116 ( V_22 , V_256 ) ;
F_117 ( V_254 , V_2 -> V_255 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
V_2 -> V_41 &= ~ ( V_257 | V_42 |
V_258 ) ;
if ( V_247 -> V_259 )
V_2 -> V_41 |= V_257 ;
if ( ! V_247 -> V_260 )
V_2 -> V_41 |= V_42 ;
if ( ! V_247 -> V_261 )
V_2 -> V_41 |= V_258 ;
}
int F_119 ( struct V_1 * V_2 )
{
struct V_246 V_247 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_247 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_120 ( V_2 , & V_247 ) )
return - V_97 ;
F_110 ( V_2 , & V_247 ) ;
F_118 ( V_2 , & V_247 ) ;
F_121 ( V_2 , & V_247 ) ;
return 0 ;
}
void F_121 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_57 ( V_2 ) )
return;
V_2 -> V_262 = V_247 -> V_262 ;
V_2 -> V_41 |= V_263 ;
F_122 ( V_22 ) ;
V_2 -> V_41 &= ~ V_263 ;
}
static int
F_123 ( struct V_1 * V_2 )
{
T_1 V_137 , V_168 ;
int V_51 = 0 ;
V_51 = F_107 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_264 )
return 0 ;
V_137 = F_88 ( V_2 , V_165 ) ;
V_168 = F_94 ( V_137 , V_2 -> V_4 -> V_27 ) ;
if ( V_137 == V_171 )
V_168 = V_138 ;
else
V_168 = F_94 ( V_137 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_168 == V_138 ) {
V_2 -> V_4 -> V_137 = V_138 ;
V_51 = F_84 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_86 ( V_2 ) ;
F_62 ( & V_2 -> V_5 -> V_30 ,
L_22 ,
V_2 -> V_4 -> V_169 ) ;
} else if ( V_168 == V_265 ) {
V_2 -> V_4 -> V_137 = V_265 ;
F_62 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_169 ) ;
}
} else {
V_2 -> V_4 -> V_240 = V_244 ;
}
V_2 -> V_41 |= V_264 ;
return V_51 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_246 V_247 ;
struct V_146 * V_266 ;
T_2 V_122 ;
if ( V_2 -> V_267 )
return 0 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_4 -> V_133 ; V_122 ++ ) {
if ( ! V_2 -> V_145 [ V_122 ] . V_154 )
continue;
memset ( & V_247 , 0 , sizeof( struct V_246 ) ) ;
V_247 . V_27 = V_2 -> V_145 [ V_122 ] . V_27 ;
V_247 . V_260 = V_268 ;
V_247 . V_261 = V_268 ;
if ( F_49 ( V_2 ) ) {
V_247 . V_262 = V_268 ;
if ( F_125 ( V_2 ) )
V_247 . V_262 |= ( V_269 | V_270 ) ;
}
if ( F_126 ( V_2 , & V_247 ) )
return - V_97 ;
V_266 = & V_2 -> V_145 [ V_122 ] ;
V_266 -> V_271 = V_247 . V_250 ;
V_266 -> V_260 = V_247 . V_260 ;
V_266 -> V_259 = V_247 . V_259 ;
V_266 -> V_248 = V_247 . V_248 ;
V_266 -> V_261 = V_247 . V_261 ;
V_266 -> V_262 = V_247 . V_262 ;
}
return 0 ;
}
static int
F_127 ( struct V_1 * V_2 ,
struct V_146 * V_266 , int V_27 )
{
struct V_246 V_247 ;
V_247 . V_137 = V_272 ;
V_247 . V_27 = V_27 ;
V_247 . V_250 = V_266 -> V_271 ;
V_247 . V_260 = V_266 -> V_260 ;
V_247 . V_248 = V_266 -> V_248 ;
V_247 . V_259 = V_266 -> V_259 ;
V_247 . V_262 = V_266 -> V_262 ;
V_247 . V_261 = V_266 -> V_261 ;
if ( F_126 ( V_2 , & V_247 ) )
return - V_97 ;
V_247 . V_137 = V_273 ;
if ( F_126 ( V_2 , & V_247 ) )
return - V_97 ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_122 , V_51 ;
struct V_146 * V_266 ;
struct V_227 V_228 ;
T_2 V_27 ;
if ( F_49 ( V_2 ) )
if ( ! V_2 -> V_267 )
return 0 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_4 -> V_133 ; V_122 ++ ) {
V_266 = & V_2 -> V_145 [ V_122 ] ;
V_27 = V_266 -> V_27 ;
if ( ! V_2 -> V_145 [ V_122 ] . V_154 )
continue;
memset ( & V_228 , 0 , sizeof( struct V_227 ) ) ;
V_51 = F_108 ( V_2 , & V_228 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_228 . V_274 = V_266 -> V_157 ;
V_228 . V_275 = V_266 -> V_159 ;
V_51 = F_129 ( V_2 , & V_228 ) ;
if ( V_51 )
return V_51 ;
if ( V_266 -> V_276 ) {
V_51 = F_130 ( V_2 ,
V_266 -> V_277 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_127 ( V_2 , V_266 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
T_2 V_278 = V_279 ;
T_1 V_280 ;
if ( V_2 -> V_4 -> V_137 == V_138 )
return 0 ;
V_280 = F_88 ( V_2 ,
V_281 ) ;
while ( V_280 != V_282 && -- V_278 ) {
F_132 ( 1000 ) ;
V_280 = F_88 ( V_2 ,
V_281 ) ;
}
if ( ! V_278 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_24 ) ;
return - V_97 ;
}
return 0 ;
}
static int
F_133 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_137 != V_138 )
return 0 ;
V_51 = F_124 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_128 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_134 ( V_2 ) ;
return V_51 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_136 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_283;
if ( V_284 )
F_137 ( V_2 ) ;
else {
V_51 = F_138 ( V_2 ) ;
if ( V_51 )
goto V_285;
V_2 -> V_4 -> V_286 = V_287 ;
}
V_51 = F_139 ( V_2 ) ;
if ( V_51 == 0 )
goto V_283;
V_51 = F_140 ( V_2 ) ;
if ( V_51 )
goto V_285;
V_51 = F_141 ( V_2 ) ;
if ( V_51 )
goto V_285;
F_142 ( V_2 ) ;
F_143 ( V_2 , V_288 , V_289 ) ;
V_283:
V_51 = F_144 ( V_2 ) ;
if ( V_51 )
goto V_285;
F_90 ( V_2 , V_290 , V_291 ) ;
F_145 ( V_2 , 1 ) ;
V_51 = F_123 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
goto V_285;
}
V_51 = F_133 ( V_2 ) ;
if ( V_51 )
goto V_285;
F_103 ( V_2 ) ;
V_2 -> V_267 = 0 ;
F_142 ( V_2 ) ;
return 0 ;
V_285:
F_90 ( V_2 , V_290 , V_292 ) ;
F_73 ( & V_2 -> V_5 -> V_30 , L_26 ) ;
F_142 ( V_2 ) ;
return V_51 ;
}
static int
F_146 ( struct V_1 * V_2 )
{
T_7 V_293 ;
struct V_18 * V_294 ;
struct V_10 * V_11 ;
int V_51 , V_295 , V_296 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_123 == V_297 ) {
if ( F_49 ( V_2 ) )
V_293 = V_298 ;
else
V_293 = V_299 ;
if ( ! F_147 ( V_2 ) )
V_41 |= V_300 ;
} else {
if ( V_2 -> V_41 & V_99 )
V_293 = V_301 ;
else if ( V_2 -> V_41 & V_98 )
V_293 = V_302 ;
else {
V_41 |= V_300 ;
if ( F_49 ( V_2 ) )
V_293 = V_303 ;
else
V_293 = V_304 ;
}
}
V_2 -> V_112 = V_22 -> V_112 ;
if ( V_2 -> V_4 -> V_123 != V_305 ) {
if ( F_49 ( V_2 ) ||
( F_57 ( V_2 ) &&
( V_2 -> V_41 & V_99 ) ) ) {
V_296 = V_2 -> V_87 ;
for ( V_295 = 0 ; V_295 < V_296 ; V_295 ++ ) {
V_294 = & V_15 -> V_19 [ V_295 ] ;
if ( F_49 ( V_2 ) &&
! F_63 ( V_2 ) &&
( V_295 == ( V_296 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_99 ) )
snprintf ( V_294 -> V_194 ,
sizeof( V_294 -> V_194 ) ,
L_27 ) ;
else
snprintf ( V_294 -> V_194 ,
sizeof( V_294 -> V_194 ) ,
L_28 ,
V_22 -> V_194 , V_295 ) ;
} else {
snprintf ( V_294 -> V_194 ,
sizeof( V_294 -> V_194 ) ,
L_29 ,
V_22 -> V_194 , V_295 ) ;
}
V_51 = F_148 ( V_294 -> V_112 , V_293 , V_41 ,
V_294 -> V_194 , V_294 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_49 ( V_2 ) &&
F_63 ( V_2 ) ) ||
( F_57 ( V_2 ) &&
( V_2 -> V_41 & V_99 ) &&
! ( V_2 -> V_41 & V_306 ) ) ) {
V_293 = V_307 ;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ;
V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
snprintf ( V_11 -> V_194 , sizeof( V_11 -> V_194 ) ,
L_30 , V_22 -> V_194 , V_295 ) ;
V_51 = F_148 ( V_11 -> V_112 , V_293 , V_41 ,
V_11 -> V_194 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_149 ( struct V_1 * V_2 )
{
int V_295 ;
struct V_18 * V_294 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_123 != V_305 ) {
if ( F_49 ( V_2 ) ||
( F_57 ( V_2 ) &&
( V_2 -> V_41 & V_99 ) ) ) {
for ( V_295 = 0 ; V_295 < V_2 -> V_87 ; V_295 ++ ) {
V_294 = & V_15 -> V_19 [ V_295 ] ;
F_150 ( V_294 -> V_112 , V_294 ) ;
}
}
if ( ( F_57 ( V_2 ) &&
! ( V_2 -> V_41 & V_306 ) ) ||
( F_49 ( V_2 ) &&
F_63 ( V_2 ) ) ) {
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ;
V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
if ( V_11 -> V_112 )
F_150 ( V_11 -> V_112 , V_11 ) ;
}
}
}
}
static void F_151 ( struct V_1 * V_2 )
{
T_1 V_308 = 0 ;
if ( F_49 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_72 [ 0 ] &
V_309 )
V_2 -> V_41 |= V_310 ;
} else {
V_308 = V_2 -> V_4 -> V_8 ;
if ( F_152 ( V_308 ) )
V_2 -> V_41 |= V_310 ;
}
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 ;
V_4 -> V_311 . V_312 = V_313 ;
if ( F_57 ( V_2 ) ) {
V_4 -> V_311 . type = V_314 ;
V_4 -> V_311 . V_315 = V_316 ;
V_4 -> V_311 . V_317 = V_318 ;
V_4 -> V_311 . V_319 = V_320 ;
V_4 -> V_311 . V_321 = V_322 ;
V_51 = F_154 ( V_2 ) ;
} else {
V_4 -> V_311 . type = V_323 ;
V_4 -> V_311 . V_319 = V_320 ;
V_4 -> V_311 . V_321 = V_322 ;
V_51 = F_155 ( V_2 ) ;
}
return V_51 ;
}
int F_156 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_295 ;
struct V_324 * V_325 ;
if ( V_2 -> V_326 != V_327 )
return - V_97 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_119 ( V_2 ) )
return - V_97 ;
F_151 ( V_2 ) ;
if ( F_157 ( V_2 ) )
return - V_97 ;
for ( V_295 = 0 ; V_295 < V_2 -> V_225 ; V_295 ++ ) {
V_325 = & V_2 -> V_15 -> V_328 [ V_295 ] ;
F_158 ( V_2 , V_325 , V_295 ) ;
}
F_24 ( V_22 ) ;
F_159 ( V_2 , V_22 -> V_329 ) ;
V_2 -> V_4 -> V_330 = 0 ;
if ( V_2 -> V_87 > 1 )
F_160 ( V_2 , 1 ) ;
F_153 ( V_2 ) ;
if ( V_22 -> V_331 & V_332 )
F_161 ( V_2 , V_333 ) ;
F_114 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_162 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_334 = 0 ;
F_163 ( V_22 ) ;
return 0 ;
}
int F_164 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_165 () ;
if ( F_166 ( V_22 ) )
V_51 = F_156 ( V_2 , V_22 ) ;
F_167 () ;
return V_51 ;
}
void F_168 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_295 ;
if ( V_2 -> V_326 != V_327 )
return;
if ( ! F_169 ( V_45 , & V_2 -> V_46 ) )
return;
if ( F_20 ( V_2 ) )
F_170 ( & V_2 -> V_4 -> V_335 -> V_336 ) ;
F_171 () ;
F_172 ( V_22 ) ;
V_2 -> V_4 -> V_330 = 0 ;
F_173 ( V_22 ) ;
F_174 ( V_2 ) ;
if ( V_2 -> V_337 . V_338 )
F_175 ( V_2 ) ;
F_176 ( V_2 , V_339 ) ;
F_23 ( V_2 ) ;
F_177 ( V_2 ) ;
V_2 -> V_41 &= ~ V_310 ;
F_178 ( V_2 ) ;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ )
F_179 ( V_2 , & V_2 -> V_11 [ V_295 ] ) ;
}
void F_180 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_165 () ;
if ( F_166 ( V_22 ) )
F_168 ( V_2 , V_22 ) ;
F_167 () ;
}
int
F_181 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_326 == V_327 )
return 0 ;
V_51 = F_182 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_183 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_31 ) ;
goto V_340;
}
V_51 = F_184 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_32 ) ;
goto V_341;
}
V_51 = F_146 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_33 ) ;
goto V_342;
}
F_185 ( V_2 ) ;
V_2 -> V_326 = V_327 ;
return 0 ;
V_342:
F_186 ( V_2 ) ;
V_341:
F_187 ( V_2 ) ;
V_340:
F_188 ( V_2 ) ;
return V_51 ;
}
void F_189 ( struct V_1 * V_2 )
{
if ( V_2 -> V_326 != V_327 )
return;
F_190 ( V_2 ) ;
F_186 ( V_2 ) ;
F_191 ( V_2 ) ;
F_149 ( V_2 ) ;
F_188 ( V_2 ) ;
F_187 ( V_2 ) ;
V_2 -> V_326 = 0 ;
}
void F_192 ( struct V_21 * V_22 , int V_87 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_294 ;
int V_85 = V_2 -> V_85 ;
int V_295 ;
F_117 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_123 == V_297 ) {
for ( V_295 = 0 ; V_295 < V_2 -> V_87 ; V_295 ++ ) {
V_294 = & V_2 -> V_15 -> V_19 [ V_295 ] ;
F_193 ( V_2 , V_294 ) ;
}
}
F_177 ( V_2 ) ;
F_189 ( V_2 ) ;
V_2 -> V_4 -> V_123 = 0 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_85 = V_85 ;
if ( F_181 ( V_2 ) )
goto V_343;
if ( F_166 ( V_22 ) )
F_156 ( V_2 , V_22 ) ;
V_343:
F_25 ( V_22 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_285;
}
memset ( & V_2 -> V_344 , 0 , sizeof( V_2 -> V_344 ) ) ;
V_285:
return V_51 ;
}
static void F_195 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_204 . V_209 ) {
F_77 ( V_2 -> V_4 -> V_204 . V_209 ) ;
V_2 -> V_4 -> V_204 . V_209 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_345 . V_346 ) ;
V_2 -> V_4 -> V_204 . V_209 = NULL ;
}
int F_196 ( struct V_21 * V_22 , int V_347 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_294 ;
struct V_324 * V_325 ;
int V_295 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_166 ( V_22 ) )
F_168 ( V_2 , V_22 ) ;
F_189 ( V_2 ) ;
V_2 -> V_87 = V_104 ;
V_2 -> V_4 -> V_123 = V_347 ;
V_2 -> V_4 -> V_330 = 0 ;
V_26 = F_181 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_157 ( V_2 ) ;
if ( V_26 ) {
F_189 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_295 = 0 ; V_295 < V_2 -> V_225 ; V_295 ++ ) {
V_325 = & V_2 -> V_15 -> V_328 [ V_295 ] ;
F_158 ( V_2 , V_325 , V_295 ) ;
}
if ( V_2 -> V_4 -> V_123 == V_297 ) {
for ( V_295 = 0 ; V_295 < V_2 -> V_87 ; V_295 ++ ) {
V_294 = & V_2 -> V_15 -> V_19 [ V_295 ] ;
F_197 ( V_2 , V_294 ) ;
}
}
if ( V_2 -> V_4 -> V_123 == V_305 ) {
V_2 -> V_4 -> V_348 = 0 ;
F_162 ( V_2 , 1 ) ;
}
F_114 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_198 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_44 ( V_62 , & V_2 -> V_46 ) )
return - V_349 ;
F_22 ( V_22 ) ;
F_180 ( V_2 , V_22 ) ;
F_164 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
F_60 ( V_2 -> V_22 , L_34 , V_54 ) ;
return 0 ;
}
int
F_199 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_44 ( V_62 , & V_2 -> V_46 ) )
return - V_349 ;
if ( V_2 -> V_326 == V_327 ) {
F_22 ( V_22 ) ;
if ( F_166 ( V_22 ) )
F_168 ( V_2 , V_22 ) ;
F_189 ( V_2 ) ;
if ( F_166 ( V_22 ) ) {
V_51 = F_181 ( V_2 ) ;
if ( ! V_51 ) {
F_156 ( V_2 , V_22 ) ;
F_116 ( V_22 , V_350 ) ;
}
}
F_25 ( V_22 ) ;
}
F_117 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_351 = V_4 -> V_133 ;
T_3 V_16 ;
V_4 -> V_352 = V_353 ;
if ( V_351 <= 2 )
V_16 = ( V_354 - V_353 ) /
V_351 ;
else
V_16 = ( V_355 - V_353 ) /
V_351 ;
V_4 -> V_55 = V_16 ;
}
int
F_201 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_356 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_357 = 1 ;
V_2 -> V_4 -> V_358 = 0 ;
F_202 ( V_2 ) ;
V_22 -> V_359 = & V_360 ;
V_22 -> V_361 = V_362 * V_363 ;
F_203 ( V_22 , V_22 -> V_329 ) ;
if ( F_20 ( V_2 ) )
F_204 ( V_22 , & V_364 ) ;
else
F_204 ( V_22 , & V_365 ) ;
V_22 -> V_331 |= ( V_366 | V_367 | V_368 |
V_369 | V_370 |
V_371 ) ;
V_22 -> V_372 |= ( V_366 | V_367 |
V_369 ) ;
if ( F_125 ( V_2 ) ) {
V_22 -> V_331 |= ( V_373 | V_374 ) ;
V_22 -> V_372 |= ( V_373 | V_374 ) ;
}
if ( V_356 ) {
V_22 -> V_331 |= V_375 ;
V_22 -> V_372 |= V_375 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_331 |= ( V_376 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_331 |= V_377 ;
if ( V_2 -> V_4 -> V_8 & V_378 )
V_22 -> V_331 |= V_332 ;
V_22 -> V_379 = V_22 -> V_331 ;
V_22 -> V_380 |= V_381 ;
V_22 -> V_112 = V_2 -> V_93 [ 0 ] . V_89 ;
V_51 = F_205 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_206 ( V_22 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_35 ) ;
return V_51 ;
}
F_207 ( V_2 -> V_382 ) ;
return 0 ;
}
static int F_208 ( struct V_23 * V_5 , int * V_356 )
{
if ( ! F_209 ( V_5 , F_210 ( 64 ) ) &&
! F_211 ( V_5 , F_210 ( 64 ) ) )
* V_356 = 1 ;
else if ( ! F_209 ( V_5 , F_210 ( 32 ) ) &&
! F_211 ( V_5 , F_210 ( 32 ) ) )
* V_356 = 0 ;
else {
F_73 ( & V_5 -> V_30 , L_36 ) ;
return - V_97 ;
}
return 0 ;
}
void F_212 ( struct V_1 * V_2 )
{
int V_295 ;
struct V_10 * V_11 ;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
if ( V_11 && V_11 -> V_383 != NULL ) {
F_77 ( V_11 -> V_383 ) ;
V_11 -> V_383 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_213 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_295 , V_89 , V_188 ;
struct V_10 * V_11 ;
struct V_384 * V_383 ;
V_11 = F_58 ( V_2 -> V_85 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
V_11 -> V_385 = V_2 -> V_223 ;
V_11 -> V_386 = F_214 ( V_22 , V_295 ) ;
V_383 = F_71 ( F_215 ( V_11 ) ) ;
if ( V_383 == NULL ) {
F_212 ( V_2 ) ;
return - V_56 ;
}
memset ( V_383 , 0 , F_215 ( V_11 ) ) ;
V_11 -> V_383 = V_383 ;
F_216 ( & V_11 -> V_387 ) ;
}
if ( F_57 ( V_2 ) ||
( F_49 ( V_2 ) && F_63 ( V_2 ) ) ) {
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_99 ) {
V_188 = V_2 -> V_87 + V_295 ;
V_89 = V_2 -> V_93 [ V_188 ] . V_89 ;
V_11 -> V_112 = V_89 ;
}
}
}
return 0 ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_388 = 0 ;
if ( F_49 ( V_2 ) )
V_388 = V_389 ;
else if ( F_57 ( V_2 ) )
V_388 = V_390 ;
if ( V_4 -> V_72 [ 0 ] & V_391 )
F_218 ( V_2 , V_388 ) ;
}
static int
F_219 ( struct V_23 * V_5 , const struct V_166 * V_167 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_356 = - 1 ;
char V_392 [ V_393 + 19 ] ;
if ( V_5 -> V_394 )
return - V_395 ;
V_51 = F_220 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_221 ( V_5 , 0 ) & V_396 ) ) {
V_51 = - V_395 ;
goto V_397;
}
V_51 = F_208 ( V_5 , & V_356 ) ;
if ( V_51 )
goto V_397;
V_51 = F_222 ( V_5 , V_398 ) ;
if ( V_51 )
goto V_397;
F_223 ( V_5 ) ;
F_224 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_399;
}
switch ( V_167 -> V_6 ) {
case V_7 :
V_4 -> V_400 = & V_401 ;
V_4 -> V_402 = ( T_1 * ) V_403 ;
break;
case V_179 :
case V_180 :
F_225 ( V_4 ) ;
break;
case V_181 :
case V_182 :
F_226 ( V_4 ) ;
break;
default:
goto V_404;
}
V_51 = F_96 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_404;
V_22 = F_227 ( sizeof( struct V_1 ) ,
V_405 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_406;
}
F_228 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_407 = F_229 ( L_27 ) ;
if ( V_2 -> V_407 == NULL ) {
V_51 = - V_56 ;
F_73 ( & V_5 -> V_30 , L_37 ) ;
goto V_408;
}
V_51 = F_194 ( V_2 ) ;
if ( V_51 )
goto V_409;
V_2 -> V_410 = V_411 ;
V_4 -> V_412 = V_5 -> V_413 ;
V_4 -> V_139 = F_230 ( V_2 ) ;
if ( V_414 == V_415 )
V_2 -> V_52 = true ;
else if ( V_414 == V_416 )
V_2 -> V_417 = true ;
F_231 ( & V_2 -> V_4 -> V_418 ) ;
F_232 ( & V_2 -> V_4 -> V_419 ) ;
F_233 ( & V_2 -> V_420 ) ;
F_234 ( V_2 ) ;
if ( F_49 ( V_2 ) ) {
F_92 ( V_2 , V_167 ) ;
V_2 -> V_421 = V_2 -> V_4 -> V_27 ;
V_51 = F_235 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_38
L_39 ) ;
goto V_422;
}
if ( V_2 -> V_4 -> V_100 ) {
if ( F_48 ( V_2 ) == 1 )
F_54 ( V_2 ,
V_104 ) ;
else
F_54 ( V_2 ,
V_423 ) ;
F_55 ( V_2 ,
V_424 ) ;
} else {
F_54 ( V_2 , V_104 ) ;
F_55 ( V_2 , V_104 ) ;
}
V_51 = F_236 ( V_2 ) ;
if ( V_51 )
goto V_342;
V_2 -> V_41 |= V_425 ;
} else if ( F_57 ( V_2 ) ) {
F_237 ( V_2 , V_167 ) ;
V_2 -> V_421 = V_2 -> V_4 -> V_27 ;
V_51 = F_238 ( V_2 , V_356 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_426 :
F_73 ( & V_5 -> V_30 , L_40 ) ;
F_73 ( & V_5 -> V_30 , L_41 ) ;
goto V_342;
case - V_56 :
F_73 ( & V_5 -> V_30 , L_42 ) ;
goto V_342;
default:
F_73 ( & V_5 -> V_30 , L_43 ) ;
F_73 ( & V_5 -> V_30 , L_44 ) ;
goto V_422;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_73 ( & V_5 -> V_30 ,
L_45 , V_54 ) ;
goto V_342;
}
F_239 ( V_2 -> V_382 ) ;
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_46 ) ;
F_240 ( V_2 ) ;
if ( V_2 -> V_421 == 0 ) {
F_102 ( V_2 , V_392 ) ;
F_36 ( L_47 ,
F_241 ( V_427 ) ,
V_392 , V_2 -> V_4 -> V_412 ) ;
}
if ( F_57 ( V_2 ) && ! V_113 &&
! ! V_109 )
F_11 ( & V_5 -> V_30 ,
L_48 ) ;
if ( F_49 ( V_2 ) ) {
V_51 = F_242 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_49 ) ;
goto V_428;
}
}
V_51 = F_80 ( V_2 ) ;
if ( V_51 )
goto V_429;
V_51 = F_201 ( V_2 , V_22 , V_356 ) ;
if ( V_51 )
goto V_429;
if ( V_2 -> V_421 == 0 )
F_217 ( V_2 ) ;
F_243 ( V_5 , V_2 ) ;
if ( F_49 ( V_2 ) )
F_244 ( V_2 , V_430 ,
V_431 ) ;
switch ( V_2 -> V_4 -> V_131 ) {
case V_132 :
F_62 ( & V_2 -> V_5 -> V_30 , L_50 ,
V_2 -> V_22 -> V_194 ) ;
break;
case V_135 :
F_62 ( & V_2 -> V_5 -> V_30 , L_51 ,
V_2 -> V_22 -> V_194 ) ;
break;
}
if ( V_2 -> V_417 )
F_245 ( V_2 ) ;
F_246 ( V_2 ) ;
return 0 ;
V_429:
if ( F_57 ( V_2 ) )
F_247 ( V_2 ) ;
V_428:
F_74 ( V_2 ) ;
F_248 ( V_2 ) ;
F_249 ( V_2 , 0 ) ;
V_342:
F_195 ( V_2 ) ;
V_409:
F_250 ( V_2 -> V_407 ) ;
V_408:
F_251 ( V_22 ) ;
V_406:
F_78 ( V_4 ) ;
V_404:
F_7 ( V_4 ) ;
V_399:
F_252 ( V_5 ) ;
V_397:
F_253 ( V_5 ) ;
return V_51 ;
V_422:
F_114 ( V_432 , & V_2 -> V_46 ) ;
V_22 -> V_359 = & V_433 ;
F_204 ( V_22 , & V_434 ) ;
V_4 -> V_131 = V_135 ;
if ( F_57 ( V_2 ) )
V_2 -> V_111 = NULL ;
else
V_4 -> V_435 = V_436 ;
V_51 = F_206 ( V_22 ) ;
if ( V_51 ) {
F_73 ( & V_5 -> V_30 , L_52 ) ;
F_249 ( V_2 , 0 ) ;
goto V_342;
}
F_243 ( V_5 , V_2 ) ;
F_246 ( V_2 ) ;
return 0 ;
}
static void F_254 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_255 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_256 ( V_2 ) ;
F_248 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_257 ( V_22 ) ;
F_258 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_259 ( V_2 , 0 ) ;
F_46 ( & V_2 -> V_437 ) ;
F_247 ( V_2 ) ;
F_260 ( V_2 ) ;
F_261 ( V_4 -> V_438 ) ;
F_7 ( V_4 -> V_439 ) ;
}
F_262 ( V_2 -> V_382 ) ;
F_189 ( V_2 ) ;
if ( V_2 -> V_145 != NULL )
F_7 ( V_2 -> V_145 ) ;
if ( V_2 -> V_147 != NULL )
F_7 ( V_2 -> V_147 ) ;
if ( F_49 ( V_2 ) )
F_249 ( V_2 , 0 ) ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
F_263 ( V_2 ) ;
F_74 ( V_2 ) ;
F_264 ( V_2 ) ;
F_78 ( V_2 -> V_4 ) ;
F_142 ( V_2 ) ;
F_265 ( V_5 ) ;
F_252 ( V_5 ) ;
F_253 ( V_5 ) ;
if ( V_2 -> V_407 ) {
F_250 ( V_2 -> V_407 ) ;
V_2 -> V_407 = NULL ;
}
F_195 ( V_2 ) ;
F_7 ( V_4 ) ;
F_251 ( V_22 ) ;
}
static void F_266 ( struct V_23 * V_5 )
{
if ( F_267 ( V_5 ) )
return;
F_253 ( V_5 ) ;
}
static int F_268 ( struct V_23 * V_5 , T_8 V_46 )
{
int V_440 ;
V_440 = F_267 ( V_5 ) ;
if ( V_440 )
return V_440 ;
F_269 ( V_5 , F_270 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_271 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_255 ( V_5 ) ;
int V_51 ;
V_51 = F_220 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_269 ( V_5 , V_441 ) ;
F_223 ( V_5 ) ;
F_272 ( V_5 ) ;
return F_273 ( V_2 ) ;
}
static int F_274 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_21 ( V_432 , & V_2 -> V_46 ) ) {
F_113 ( V_22 , L_53 ,
V_54 ) ;
return - V_97 ;
}
F_172 ( V_22 ) ;
V_51 = F_181 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_156 ( V_2 , V_22 ) ;
if ( V_51 )
F_189 ( V_2 ) ;
return V_51 ;
}
static int F_275 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_168 ( V_2 , V_22 ) ;
return 0 ;
}
void F_245 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_122 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_442 = 0 ;
T_3 V_142 = 0 ;
if ( V_2 -> V_337 . V_443 && V_2 -> V_337 . V_444 )
return;
V_142 = V_2 -> V_4 -> V_133 ;
F_216 ( & V_2 -> V_445 ) ;
F_216 ( & V_2 -> V_446 ) ;
if ( F_49 ( V_2 ) ) {
V_442 = V_355 ;
V_2 -> V_337 . V_447 = V_448 ;
} else {
V_442 = V_449 ;
V_2 -> V_337 . V_447 = V_450 ;
}
V_34 = F_58 ( V_2 -> V_337 . V_447 ,
sizeof( struct V_451 ) , V_452 ) ;
if ( ! V_34 )
return;
V_2 -> V_337 . V_443 = ( V_442 / V_142 ) ;
V_2 -> V_337 . V_444 = V_34 ;
F_60 ( V_22 , L_54 ,
V_142 , V_2 -> V_337 . V_443 ) ;
for ( V_122 = 0 ; V_122 < V_2 -> V_337 . V_447 ; V_122 ++ )
F_276 ( & V_2 -> V_337 . V_444 [ V_122 ] ) ;
V_2 -> V_453 . V_447 = V_2 -> V_337 . V_447 ;
V_34 = F_58 ( V_2 -> V_453 . V_447 ,
sizeof( struct V_451 ) , V_452 ) ;
if ( ! V_34 )
return;
V_2 -> V_453 . V_443 = ( V_442 / V_142 ) ;
V_2 -> V_453 . V_444 = V_34 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_453 . V_447 ; V_122 ++ )
F_276 ( & V_2 -> V_453 . V_444 [ V_122 ] ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
if ( V_2 -> V_337 . V_443 && V_2 -> V_337 . V_444 )
F_7 ( V_2 -> V_337 . V_444 ) ;
V_2 -> V_337 . V_444 = NULL ;
V_2 -> V_337 . V_443 = 0 ;
if ( V_2 -> V_453 . V_443 && V_2 -> V_453 . V_444 )
F_7 ( V_2 -> V_453 . V_444 ) ;
V_2 -> V_453 . V_443 = 0 ;
V_2 -> V_453 . V_444 = NULL ;
}
int F_277 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_454 , V_455 , V_235 = 0 ;
int V_456 = 0 ;
if ( F_57 ( V_2 ) )
V_235 = F_278 ( V_2 -> V_4 , V_457 ) ;
if ( F_49 ( V_2 ) )
V_235 = F_88 ( V_2 , V_458 ) ;
V_454 = F_279 ( V_235 ) ;
V_455 = F_280 ( V_235 ) ;
if ( V_454 == V_459 ) {
F_73 ( & V_22 -> V_30 ,
L_55
L_56 ,
V_455 ) ;
V_456 = 1 ;
} else if ( V_454 == V_460 ) {
if ( V_2 -> V_4 -> V_235 == V_461 ) {
F_73 ( & V_22 -> V_30 ,
L_57
L_58
L_59 ,
V_455 ) ;
}
} else {
if ( V_2 -> V_4 -> V_235 == V_460 ) {
F_62 ( & V_22 -> V_30 ,
L_60
L_61 , V_455 ) ;
}
}
V_2 -> V_4 -> V_235 = V_454 ;
return V_456 ;
}
static inline void F_281 ( struct V_10 * V_11 )
{
int V_122 ;
struct V_462 * V_463 ;
for ( V_122 = 0 ; V_122 < V_11 -> V_385 ; V_122 ++ ) {
V_463 = & V_11 -> V_464 [ V_122 ] ;
F_36 ( L_62 , V_122 ) ;
F_282 ( V_465 , L_63 , V_466 , 16 , 1 ,
& V_11 -> V_464 [ V_122 ] ,
sizeof( struct V_462 ) , true ) ;
}
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_10 * V_11 ;
int V_295 ;
if ( ! V_22 || ! F_166 ( V_22 ) )
return;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
F_60 ( V_22 , L_64 ,
V_295 , V_11 -> V_467 ) ;
F_60 ( V_22 ,
L_65 ,
V_11 -> V_468 . V_469 ,
V_11 -> V_468 . V_470 ,
V_11 -> V_468 . V_471 ,
V_11 -> V_468 . V_472 ) ;
F_60 ( V_22 ,
L_66 ,
F_284 ( V_11 -> V_473 ) ,
F_284 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_474 ,
F_285 ( * ( V_11 -> V_475 ) ) ) ;
F_60 ( V_22 , L_67 ,
V_11 -> V_385 , F_286 ( V_11 ) ) ;
if ( F_287 ( V_2 -> V_4 ) )
F_281 ( V_11 ) ;
}
}
static void F_288 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return;
if ( ++ V_2 -> V_476 >= V_477 ) {
F_60 ( V_22 , L_68 ) ;
if ( F_49 ( V_2 ) )
V_2 -> V_267 = 1 ;
else if ( F_57 ( V_2 ) )
F_289 ( V_2 ,
V_478 ) ;
} else {
F_60 ( V_22 , L_69 ) ;
F_283 ( V_2 ) ;
V_2 -> V_4 -> V_334 = 1 ;
}
}
static struct V_479 * F_290 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_479 * V_344 = & V_22 -> V_344 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_291 ( V_2 ) ;
V_344 -> V_321 = V_2 -> V_344 . V_480 + V_2 -> V_344 . V_481 ;
V_344 -> V_317 = V_2 -> V_344 . V_482 ;
V_344 -> V_483 = V_2 -> V_344 . V_484 + V_2 -> V_344 . V_485 ;
V_344 -> V_486 = V_2 -> V_344 . V_487 ;
V_344 -> V_488 = V_2 -> V_344 . V_489 ;
V_344 -> V_490 = V_2 -> V_344 . V_491 ;
return V_344 ;
}
static T_9 F_292 ( struct V_1 * V_2 )
{
T_1 V_492 ;
V_492 = F_284 ( V_2 -> V_117 ) ;
if ( ! ( V_492 & V_2 -> V_4 -> V_115 ) )
return V_493 ;
V_492 = F_284 ( V_2 -> V_119 ) ;
if ( ! F_293 ( V_492 ) )
return V_493 ;
F_3 ( 0xffffffff , V_2 -> V_111 ) ;
F_284 ( V_2 -> V_117 ) ;
F_284 ( V_2 -> V_117 ) ;
return V_494 ;
}
static T_9 V_298 ( int V_112 , void * V_163 )
{
struct V_18 * V_294 = V_163 ;
struct V_1 * V_2 = V_294 -> V_2 ;
if ( V_2 -> V_41 & V_99 )
goto V_495;
else if ( V_2 -> V_41 & V_98 ) {
F_3 ( 0xffffffff , V_2 -> V_111 ) ;
goto V_495;
}
if ( F_294 ( V_2 ) == V_493 )
return V_493 ;
V_495:
V_2 -> V_4 -> V_496 ++ ;
F_197 ( V_2 , V_294 ) ;
return V_494 ;
}
static T_9 V_303 ( int V_112 , void * V_163 )
{
struct V_18 * V_294 = V_163 ;
struct V_1 * V_2 = V_294 -> V_2 ;
if ( F_294 ( V_2 ) == V_493 )
return V_493 ;
F_295 ( & V_294 -> V_497 ) ;
return V_494 ;
}
static T_9 V_302 ( int V_112 , void * V_163 )
{
struct V_18 * V_294 = V_163 ;
struct V_1 * V_2 = V_294 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_111 ) ;
F_295 ( & V_294 -> V_497 ) ;
return V_494 ;
}
static T_9 V_301 ( int V_112 , void * V_163 )
{
struct V_18 * V_294 = V_163 ;
F_295 ( & V_294 -> V_497 ) ;
return V_494 ;
}
static T_9 V_307 ( int V_112 , void * V_163 )
{
struct V_10 * V_11 = V_163 ;
F_295 ( & V_11 -> V_497 ) ;
return V_494 ;
}
static void F_296 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_294 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_295 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_295 = 0 ; V_295 < V_2 -> V_87 ; V_295 ++ ) {
V_294 = & V_15 -> V_19 [ V_295 ] ;
F_193 ( V_2 , V_294 ) ;
F_295 ( & V_294 -> V_497 ) ;
}
if ( V_2 -> V_41 & V_99 ) {
if ( ( F_57 ( V_2 ) &&
( V_2 -> V_41 & V_306 ) ) ||
( F_49 ( V_2 ) &&
! F_63 ( V_2 ) ) )
return;
for ( V_295 = 0 ; V_295 < V_2 -> V_85 ; V_295 ++ ) {
V_11 = & V_2 -> V_11 [ V_295 ] ;
F_297 ( V_2 , V_11 ) ;
F_295 ( & V_11 -> V_497 ) ;
}
}
}
static void
F_145 ( struct V_1 * V_2 , T_2 V_498 )
{
T_1 V_499 ;
V_499 = V_2 -> V_421 & 0xf ;
V_499 |= V_498 << 7 ;
V_499 |= ( V_411 - V_2 -> V_410 ) << 8 ;
F_90 ( V_2 , V_500 , V_499 ) ;
V_2 -> V_410 = V_411 ;
}
static int
F_298 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_499 ;
F_299 ( V_46 != V_501 &&
V_46 != V_502 ) ;
if ( F_87 ( V_2 ) )
return - V_97 ;
V_499 = F_88 ( V_2 , V_503 ) ;
if ( V_46 == V_501 )
F_300 ( V_499 , V_2 -> V_421 ) ;
else if ( V_46 == V_502 )
F_301 ( V_499 , V_2 -> V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int
F_302 ( struct V_1 * V_2 )
{
T_1 V_499 ;
if ( F_87 ( V_2 ) )
return - V_349 ;
V_499 = F_88 ( V_2 , V_503 ) ;
F_303 ( V_499 , V_2 -> V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
void F_249 ( struct V_1 * V_2 , T_2 V_504 )
{
T_1 V_499 ;
if ( F_87 ( V_2 ) )
goto V_51;
V_499 = F_88 ( V_2 , V_505 ) ;
F_304 ( V_499 , V_2 -> V_421 ) ;
F_90 ( V_2 , V_505 , V_499 ) ;
if ( V_504 ) {
F_90 ( V_2 , V_290 ,
V_292 ) ;
F_62 ( & V_2 -> V_5 -> V_30 ,
L_70 ) ;
} else if ( ! ( V_499 & 0x11111111 ) )
F_90 ( V_2 , V_290 ,
V_506 ) ;
V_499 = F_88 ( V_2 , V_503 ) ;
F_303 ( V_499 , V_2 -> V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
F_91 ( V_2 ) ;
V_51:
V_2 -> V_507 = 0 ;
V_2 -> V_41 &= ~ V_508 ;
F_117 ( V_509 , & V_2 -> V_46 ) ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
}
static int
F_305 ( struct V_1 * V_2 )
{
int V_510 , V_46 , V_511 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_88 ( V_2 , V_503 ) ;
V_510 = F_88 ( V_2 , V_505 ) ;
if ( V_2 -> V_41 & V_512 ) {
V_511 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_510 = V_510 & V_511 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_510 & 0x11111111 ) ) ||
( ( V_510 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_306 ( struct V_1 * V_2 )
{
T_1 V_499 = F_88 ( V_2 , V_513 ) ;
if ( V_499 != V_514 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_71
L_72 , V_514 , V_499 ) ;
}
return 0 ;
}
static int
F_136 ( struct V_1 * V_2 )
{
T_1 V_499 , V_515 ;
T_2 V_516 = V_2 -> V_516 ;
T_2 V_421 = V_2 -> V_421 ;
T_2 V_26 ;
if ( F_169 ( V_509 , & V_2 -> V_46 ) )
return 1 ;
if ( F_87 ( V_2 ) )
return - 1 ;
V_499 = F_88 ( V_2 , V_505 ) ;
if ( ! ( V_499 & ( 1 << ( V_421 * 4 ) ) ) ) {
F_307 ( V_499 , V_421 ) ;
F_90 ( V_2 , V_505 , V_499 ) ;
}
V_515 = F_88 ( V_2 , V_290 ) ;
F_308 ( V_2 , V_517 , L_73 , V_515 ) ;
switch ( V_515 ) {
case V_506 :
F_90 ( V_2 , V_290 ,
V_518 ) ;
F_90 ( V_2 , V_513 ,
V_514 ) ;
F_145 ( V_2 , 0 ) ;
F_91 ( V_2 ) ;
return 1 ;
case V_291 :
V_26 = F_306 ( V_2 ) ;
F_91 ( V_2 ) ;
return V_26 ;
case V_501 :
V_499 = F_88 ( V_2 , V_503 ) ;
F_300 ( V_499 , V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
break;
case V_502 :
V_499 = F_88 ( V_2 , V_503 ) ;
F_301 ( V_499 , V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
break;
case V_292 :
F_73 ( & V_2 -> V_5 -> V_30 , L_74 ) ;
F_91 ( V_2 ) ;
return - 1 ;
case V_518 :
case V_519 :
break;
}
F_91 ( V_2 ) ;
do {
F_132 ( 1000 ) ;
V_515 = F_88 ( V_2 , V_290 ) ;
if ( V_515 == V_519 )
continue;
} while ( ( V_515 != V_291 ) && -- V_516 );
if ( ! V_516 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_75 ) ;
return - 1 ;
}
if ( F_87 ( V_2 ) )
return - 1 ;
V_499 = F_88 ( V_2 , V_503 ) ;
F_303 ( V_499 , V_421 ) ;
F_90 ( V_2 , V_503 , V_499 ) ;
V_26 = F_306 ( V_2 ) ;
F_91 ( V_2 ) ;
return V_26 ;
}
static void
F_309 ( struct V_520 * V_64 )
{
struct V_1 * V_2 = F_310 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
T_1 V_521 = 0xf ;
T_1 V_499 ;
if ( F_87 ( V_2 ) )
goto V_522;
V_521 = F_88 ( V_2 , V_290 ) ;
if ( V_521 == V_519 ||
V_521 == V_502 ) {
F_91 ( V_2 ) ;
F_244 ( V_2 , F_309 ,
V_431 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_137 == V_172 ) {
F_91 ( V_2 ) ;
goto V_523;
}
if ( V_521 == V_518 ||
V_521 == V_291 ) {
F_62 ( & V_2 -> V_5 -> V_30 , L_76
L_77 ) ;
goto V_524;
}
if ( V_2 -> V_525 ++ > V_2 -> V_526 ) {
F_62 ( & V_2 -> V_5 -> V_30 , L_78 ,
V_2 -> V_526 ) ;
goto V_524;
}
if ( ! F_305 ( V_2 ) ) {
V_524:
V_521 = F_88 ( V_2 , V_290 ) ;
if ( V_521 == V_501 ) {
F_90 ( V_2 , V_290 ,
V_518 ) ;
F_114 ( V_509 , & V_2 -> V_46 ) ;
F_308 ( V_2 , V_527 , L_79 ) ;
F_145 ( V_2 , 0 ) ;
V_499 = F_88 ( V_2 ,
V_503 ) ;
F_300 ( V_499 , V_2 -> V_421 ) ;
F_90 ( V_2 ,
V_503 , V_499 ) ;
}
F_91 ( V_2 ) ;
F_165 () ;
if ( F_311 ( V_2 ) &&
( V_2 -> V_41 & V_512 ) ) {
F_308 ( V_2 , V_527 , L_80 ) ;
F_312 ( V_2 ) ;
V_2 -> V_41 |= V_508 ;
}
F_167 () ;
V_2 -> V_41 &= ~ V_512 ;
if ( ! V_2 -> V_173 -> V_528 ( V_2 ) ) {
F_244 ( V_2 , V_529 , 0 ) ;
V_2 -> V_525 = 0 ;
return;
}
goto V_522;
}
F_91 ( V_2 ) ;
V_523:
V_521 = F_88 ( V_2 , V_290 ) ;
F_308 ( V_2 , V_517 , L_81 , V_521 ) ;
switch ( V_521 ) {
case V_291 :
if ( ! F_235 ( V_2 ) ) {
F_244 ( V_2 , V_529 , 0 ) ;
V_2 -> V_525 = 0 ;
return;
}
case V_292 :
break;
default:
F_244 ( V_2 ,
F_309 , V_431 ) ;
return;
}
V_522:
F_73 ( & V_2 -> V_5 -> V_30 , L_82
L_83 , V_521 , V_2 -> V_525 ) ;
F_25 ( V_2 -> V_22 ) ;
F_249 ( V_2 , 0 ) ;
}
static void
F_313 ( struct V_520 * V_64 )
{
struct V_1 * V_2 = F_310 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_492 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_521 == V_502 ) {
if ( F_166 ( V_22 ) )
F_168 ( V_2 , V_22 ) ;
} else
F_180 ( V_2 , V_22 ) ;
V_492 = F_88 ( V_2 , V_530 ) ;
if ( V_492 & V_531 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_84 ,
V_492 ) ;
if ( F_314 ( V_492 ) == V_532 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_85
L_86 ) ;
F_73 ( & V_2 -> V_5 -> V_30 ,
L_87 ) ;
}
goto V_522;
}
if ( V_2 -> V_4 -> V_235 == V_459 ) {
F_73 ( & V_2 -> V_5 -> V_30 , L_88 ,
V_2 -> V_4 -> V_235 ) ;
goto V_522;
}
if ( ! ( V_2 -> V_41 & V_512 ) ) {
if ( F_298 ( V_2 , V_2 -> V_521 ) ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_89
L_90 ) ;
goto V_522;
}
}
V_2 -> V_525 = 0 ;
F_244 ( V_2 , F_309 , V_431 ) ;
return;
V_522:
F_25 ( V_22 ) ;
F_249 ( V_2 , 1 ) ;
}
static void
F_315 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_88 ( V_2 , V_281 ) ;
if ( V_46 == V_533 )
return;
if ( F_87 ( V_2 ) )
return;
F_90 ( V_2 , V_281 ,
V_533 ) ;
F_91 ( V_2 ) ;
}
static void F_316 ( struct V_1 * V_2 ,
T_1 V_534 )
{
T_1 V_46 , V_535 = 0 , V_536 = 0 ;
F_317 ( V_535 ) ;
F_318 ( V_535 ) ;
F_143 ( V_2 , V_537 , V_535 ) ;
F_319 ( V_536 ) ;
F_320 ( V_536 ) ;
F_321 ( V_536 ) ;
F_322 ( V_536 ) ;
F_143 ( V_2 , V_538 , V_536 ) ;
F_62 ( & V_2 -> V_5 -> V_30 , L_91
L_92 ) ;
V_2 -> V_267 = 1 ;
if ( F_87 ( V_2 ) )
return;
V_46 = F_88 ( V_2 , V_290 ) ;
if ( F_21 ( V_432 , & V_2 -> V_46 ) ) {
F_113 ( V_2 -> V_22 , L_53 ,
V_54 ) ;
F_91 ( V_2 ) ;
return;
}
if ( V_46 == V_291 ) {
F_90 ( V_2 , V_290 ,
V_501 ) ;
V_2 -> V_41 |= V_512 ;
F_308 ( V_2 , V_527 , L_93 ) ;
F_145 ( V_2 , 0 ) ;
}
F_90 ( V_2 , V_281 ,
V_533 ) ;
F_91 ( V_2 ) ;
}
static void
F_134 ( struct V_1 * V_2 )
{
if ( F_87 ( V_2 ) )
return;
F_90 ( V_2 , V_281 ,
V_282 ) ;
F_308 ( V_2 , V_527 , L_94 ) ;
F_91 ( V_2 ) ;
}
void F_244 ( struct V_1 * V_2 ,
T_10 V_65 , int V_539 )
{
if ( F_21 ( V_540 , & V_2 -> V_46 ) )
return;
F_323 ( & V_2 -> V_63 , V_65 ) ;
F_324 ( V_2 -> V_407 , & V_2 -> V_63 ,
F_325 ( V_539 ) ) ;
}
static void
V_529 ( struct V_520 * V_64 )
{
struct V_1 * V_2 = F_310 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_280 ;
if ( V_2 -> V_4 -> V_137 != V_138 ) {
V_280 = F_88 ( V_2 ,
V_281 ) ;
if ( V_2 -> V_525 ++ > V_279 )
F_249 ( V_2 , 0 ) ;
else if ( V_280 != V_282 )
F_244 ( V_2 , V_529 ,
V_431 ) ;
else
goto V_541;
F_308 ( V_2 , V_527 , L_95 ) ;
return;
}
V_541:
F_326 ( V_2 -> V_382 ) ;
if ( F_166 ( V_22 ) ) {
if ( F_164 ( V_2 , V_22 ) )
goto V_495;
F_116 ( V_22 , V_350 ) ;
}
V_495:
F_25 ( V_22 ) ;
V_2 -> V_507 = 0 ;
V_2 -> V_41 &= ~ V_508 ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
if ( V_2 -> V_421 == 0 )
F_217 ( V_2 ) ;
if ( ! F_302 ( V_2 ) )
F_244 ( V_2 , V_430 ,
V_431 ) ;
}
static int
F_327 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_203 * V_204 = & V_4 -> V_204 ;
T_1 V_46 = 0 , V_542 ;
T_1 V_543 ;
int V_51 = 0 ;
if ( F_277 ( V_2 ) )
goto V_544;
if ( V_2 -> V_267 )
F_328 ( V_2 , 0 ) ;
V_46 = F_88 ( V_2 , V_290 ) ;
if ( V_46 == V_501 ) {
F_315 ( V_2 ) ;
V_2 -> V_267 = 1 ;
} else if ( V_46 == V_502 )
goto V_544;
V_542 = F_88 ( V_2 , V_545 ) ;
if ( V_542 != V_2 -> V_542 ) {
V_2 -> V_542 = V_542 ;
V_2 -> V_507 = 0 ;
if ( V_2 -> V_267 )
goto V_544;
if ( V_4 -> V_334 && V_546 )
F_198 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_507 < V_547 )
return 0 ;
V_2 -> V_41 |= V_508 ;
F_328 ( V_2 , 0 ) ;
if ( V_546 )
F_117 ( V_548 , & V_2 -> V_46 ) ;
F_73 ( & V_2 -> V_5 -> V_30 , L_96 ) ;
V_543 = F_88 ( V_2 , V_530 ) ;
F_73 ( & V_2 -> V_5 -> V_30 , L_97
L_98
L_99
L_100
L_101 ,
V_543 ,
F_88 ( V_2 , V_549 ) ,
F_109 ( V_2 , V_550 + 0x3c , & V_51 ) ,
F_109 ( V_2 , V_551 + 0x3c , & V_51 ) ,
F_109 ( V_2 , V_552 + 0x3c , & V_51 ) ,
F_109 ( V_2 , V_553 + 0x3c , & V_51 ) ,
F_109 ( V_2 , V_554 + 0x3c , & V_51 ) ) ;
if ( F_314 ( V_543 ) == 0x67 )
F_73 ( & V_2 -> V_5 -> V_30 ,
L_102
L_103 ) ;
V_544:
V_2 -> V_521 = ( V_46 == V_502 ) ? V_46 :
V_501 ;
if ( V_546 && ! F_44 ( V_62 ,
& V_2 -> V_46 ) ) {
F_244 ( V_2 , F_313 , 0 ) ;
F_308 ( V_2 , V_527 , L_104 ) ;
} else if ( ! V_546 && V_204 -> V_555 &&
V_2 -> V_41 & V_512 ) {
F_312 ( V_2 ) ;
}
return 1 ;
}
void V_430 ( struct V_520 * V_64 )
{
struct V_1 * V_2 = F_310 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
goto V_556;
if ( F_327 ( V_2 ) )
return;
if ( V_2 -> V_337 . V_338 )
F_329 ( V_2 ) ;
V_556:
F_244 ( V_2 , V_430 , V_431 ) ;
}
static int F_330 ( struct V_23 * V_5 )
{
struct V_23 * V_557 ;
int V_499 = V_5 -> V_558 ;
while ( V_499 -- > 0 ) {
V_557 = F_331 ( F_332
( V_5 -> V_559 ) , V_5 -> V_559 -> V_560 ,
F_333 ( F_334 ( V_5 -> V_558 ) , V_499 ) ) ;
if ( ! V_557 )
continue;
if ( V_557 -> V_561 != V_562 ) {
F_335 ( V_557 ) ;
return 0 ;
}
F_335 ( V_557 ) ;
}
return 1 ;
}
static int F_336 ( struct V_23 * V_5 )
{
int V_51 , V_563 ;
struct V_1 * V_2 = F_255 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_564 = V_565 ;
V_51 = F_220 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_223 ( V_5 ) ;
F_272 ( V_5 ) ;
V_563 = F_330 ( V_5 ) ;
if ( F_87 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_137 != V_172 && V_563 ) {
V_2 -> V_267 = 1 ;
F_114 ( V_509 , & V_2 -> V_46 ) ;
F_90 ( V_2 , V_290 ,
V_518 ) ;
F_308 ( V_2 , V_527 , L_79 ) ;
}
F_91 ( V_2 ) ;
V_51 = F_235 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_302 ( V_2 ) ;
F_7 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
V_51 = F_242 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_93 ) ;
F_113 ( V_22 , L_33 ) ;
return V_51 ;
}
if ( F_166 ( V_22 ) ) {
V_51 = F_181 ( V_2 ) ;
if ( V_51 ) {
F_249 ( V_2 , 1 ) ;
F_117 ( V_540 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_51 ;
}
V_51 = F_164 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_495;
F_116 ( V_22 , V_350 ) ;
}
V_495:
F_25 ( V_22 ) ;
return V_51 ;
}
static T_11 F_337 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_255 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_566 )
return V_567 ;
if ( V_46 == V_565 )
return V_568 ;
F_114 ( V_540 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_46 ( & V_2 -> V_63 ) ;
if ( F_166 ( V_22 ) )
F_180 ( V_2 , V_22 ) ;
F_189 ( V_2 ) ;
F_74 ( V_2 ) ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
F_338 ( V_5 ) ;
F_253 ( V_5 ) ;
return V_569 ;
}
static T_11 F_339 ( struct V_23 * V_5 )
{
return F_336 ( V_5 ) ? V_567 :
V_568 ;
}
static void F_340 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_255 ( V_5 ) ;
F_341 ( V_5 ) ;
V_46 = F_88 ( V_2 , V_290 ) ;
if ( V_46 == V_291 && F_169 ( V_540 ,
& V_2 -> V_46 ) )
F_244 ( V_2 , V_430 ,
V_431 ) ;
}
static T_11 F_342 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_255 ( V_5 ) ;
struct V_570 * V_400 = V_2 -> V_4 -> V_400 ;
if ( V_400 -> V_571 ) {
return V_400 -> V_571 ( V_5 , V_46 ) ;
} else {
F_73 ( & V_5 -> V_30 , L_105 ) ;
return V_567 ;
}
}
static T_11 F_343 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_255 ( V_5 ) ;
struct V_570 * V_400 = V_2 -> V_4 -> V_400 ;
if ( V_400 -> V_572 ) {
return V_400 -> V_572 ( V_5 ) ;
} else {
F_73 ( & V_5 -> V_30 , L_106 ) ;
return V_567 ;
}
}
static void F_344 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_255 ( V_5 ) ;
struct V_570 * V_400 = V_2 -> V_4 -> V_400 ;
if ( V_400 -> V_573 )
V_400 -> V_573 ( V_5 ) ;
else
F_73 ( & V_5 -> V_30 , L_107 ) ;
}
static int
F_345 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_136 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_131 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_107 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_103 ( V_2 ) ;
V_51 = F_119 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_267 = 0 ;
return V_51 ;
}
int F_346 ( struct V_1 * V_2 , T_13 V_75 ,
int V_76 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_574 = 0 ;
char V_575 [ 8 ] ;
int V_576 ;
if ( V_76 == V_80 ) {
V_574 = V_2 -> V_81 ;
V_576 = V_2 -> V_87 ;
strcpy ( V_575 , L_108 ) ;
} else if ( V_76 == V_82 ) {
V_574 = V_2 -> V_83 ;
V_576 = V_2 -> V_85 ;
strcpy ( V_575 , L_109 ) ;
}
if ( ! F_147 ( V_2 ) ) {
F_113 ( V_22 , L_110 ) ;
return - V_40 ;
}
if ( V_2 -> V_41 & V_98 ) {
F_113 ( V_22 , L_111 ) ;
return - V_40 ;
}
if ( ! F_347 ( V_75 ) ) {
F_113 ( V_22 , L_112 ,
V_575 ) ;
return - V_40 ;
}
if ( F_49 ( V_2 ) && ( V_76 == V_82 ) &&
! F_63 ( V_2 ) ) {
F_113 ( V_22 , L_113 ) ;
return - V_40 ;
}
if ( V_75 > F_53 () ) {
F_113 ( V_22 ,
L_114 ,
V_575 , F_53 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_348 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 ;
if ( F_21 ( V_62 , & V_2 -> V_46 ) )
return - V_349 ;
F_22 ( V_22 ) ;
if ( F_166 ( V_22 ) )
F_168 ( V_2 , V_22 ) ;
F_189 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_247 ( V_2 ) ;
F_349 ( V_2 ) ;
}
F_74 ( V_2 ) ;
V_51 = F_242 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_93 ) ;
F_113 ( V_22 , L_33 ) ;
return V_51 ;
}
F_350 ( V_22 , V_2 -> V_85 ) ;
if ( F_57 ( V_2 ) ) {
F_259 ( V_2 , 1 ) ;
V_51 = F_351 ( V_2 ) ;
F_352 ( V_2 ) ;
if ( V_51 ) {
F_73 ( & V_2 -> V_5 -> V_30 ,
L_115 ) ;
goto V_495;
}
}
if ( F_166 ( V_22 ) ) {
V_51 = F_181 ( V_2 ) ;
if ( V_51 )
goto V_495;
V_51 = F_156 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_495;
F_116 ( V_22 , V_350 ) ;
}
V_495:
F_25 ( V_22 ) ;
F_117 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_353 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_577 )
{
struct V_578 * V_579 ;
V_579 = F_354 ( V_30 ) ;
if ( ! V_579 )
return;
F_355 (indev) {
switch ( V_577 ) {
case V_350 :
F_356 ( V_2 ,
V_580 -> V_581 , V_582 ) ;
break;
case V_256 :
F_356 ( V_2 ,
V_580 -> V_581 , V_583 ) ;
break;
default:
break;
}
} F_357 ( V_579 ) ;
F_358 ( V_579 ) ;
}
void F_116 ( struct V_21 * V_22 , unsigned long V_577 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_254 ;
F_353 ( V_2 , V_22 , V_577 ) ;
F_359 () ;
F_360 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_361 ( V_22 , F_362 ( V_584 ) , V_254 ) ;
if ( ! V_30 )
continue;
F_353 ( V_2 , V_30 , V_577 ) ;
}
F_363 () ;
}
static int F_364 ( struct V_585 * V_586 ,
unsigned long V_577 , void * V_587 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_365 ( V_587 ) ;
V_588:
if ( V_30 == NULL )
goto V_495;
if ( V_30 -> V_380 & V_589 ) {
V_30 = F_366 ( V_30 ) ;
goto V_588;
}
if ( ! F_367 ( V_30 ) )
goto V_495;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_495;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_495;
F_353 ( V_2 , V_30 , V_577 ) ;
V_495:
return V_590 ;
}
static int
F_368 ( struct V_585 * V_586 ,
unsigned long V_577 , void * V_587 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_591 * V_580 = (struct V_591 * ) V_587 ;
V_30 = V_580 -> V_592 ? V_580 -> V_592 -> V_30 : NULL ;
V_588:
if ( V_30 == NULL )
goto V_495;
if ( V_30 -> V_380 & V_589 ) {
V_30 = F_366 ( V_30 ) ;
goto V_588;
}
if ( ! F_367 ( V_30 ) )
goto V_495;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_495;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_495;
switch ( V_577 ) {
case V_350 :
F_356 ( V_2 , V_580 -> V_581 , V_582 ) ;
break;
case V_256 :
F_356 ( V_2 , V_580 -> V_581 , V_583 ) ;
break;
default:
break;
}
V_495:
return V_590 ;
}
void F_116 ( struct V_21 * V_30 , unsigned long V_577 )
{ }
static int T_14 F_369 ( void )
{
int V_26 ;
F_370 ( V_465 L_116 , V_593 ) ;
#ifdef F_371
F_372 ( & V_594 ) ;
F_373 ( & V_595 ) ;
#endif
V_26 = F_374 ( & V_596 ) ;
if ( V_26 ) {
#ifdef F_371
F_375 ( & V_595 ) ;
F_376 ( & V_594 ) ;
#endif
}
return V_26 ;
}
static void T_15 F_377 ( void )
{
F_378 ( & V_596 ) ;
#ifdef F_371
F_375 ( & V_595 ) ;
F_376 ( & V_594 ) ;
#endif
}
