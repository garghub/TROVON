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
if ( ! F_50 ( V_2 ) || V_4 -> V_76 )
return;
V_4 -> V_76 = F_51 ( V_75 ) ;
V_2 -> V_41 |= V_77 ;
}
static void F_52 ( struct V_21 * V_22 ,
T_4 V_74 , T_5 V_75 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || ! V_4 -> V_76 ||
( V_4 -> V_76 != F_51 ( V_75 ) ) )
return;
V_2 -> V_41 |= V_78 ;
}
static T_6 F_53 ( struct V_58 * V_59 ,
struct V_21 * V_30 ,
T_6 V_79 )
{
V_79 = F_54 ( V_59 , V_79 ) ;
return F_55 ( V_59 , V_79 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_57 ( V_2 ) &&
( V_4 -> V_80 [ 0 ] & V_81 ) ) {
F_45 ( V_82 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_58 ( struct V_1 * V_2 , T_2 V_83 ,
int V_84 )
{
int V_85 , V_86 = V_87 ;
if ( V_84 == V_88 )
V_86 = V_2 -> V_89 ;
else if ( V_84 == V_90 )
V_86 = V_2 -> V_91 ;
V_85 = F_59 ( F_60 ( int , F_61 () ,
V_86 ) ) ;
if ( V_83 > V_85 )
return V_85 ;
else
return V_83 ;
}
void F_62 ( struct V_1 * V_2 , T_2 V_92 )
{
if ( V_2 -> V_91 )
V_2 -> V_93 = F_58 ( V_2 , V_92 ,
V_90 ) ;
else
V_2 -> V_93 = V_92 ;
}
void F_63 ( struct V_1 * V_2 , T_2 V_94 )
{
if ( V_2 -> V_89 )
V_2 -> V_95 = F_58 ( V_2 , V_94 ,
V_88 ) ;
else
V_2 -> V_95 = V_94 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_96 = 0 , V_52 = 0 , V_97 ;
V_2 -> V_41 &= ~ V_98 ;
if ( V_2 -> V_99 > 0 )
V_96 += V_2 -> V_99 ;
else
V_96 += V_2 -> V_93 ;
if ( V_2 -> V_100 > 0 )
V_96 += V_2 -> V_100 ;
else
V_96 += V_2 -> V_95 ;
if ( F_65 ( V_2 ) )
V_96 += 1 ;
if ( ! V_2 -> V_101 ) {
V_2 -> V_101 = F_66 ( V_96 ,
sizeof( struct V_102 ) ,
V_20 ) ;
if ( ! V_2 -> V_101 )
return - V_57 ;
}
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ )
V_2 -> V_101 [ V_97 ] . V_103 = V_97 ;
V_104:
V_52 = F_67 ( V_5 , V_2 -> V_101 , V_96 ) ;
if ( V_52 == - V_105 ) {
if ( ! V_2 -> V_99 && ! V_2 -> V_100 )
return V_52 ;
F_68 ( V_2 -> V_22 ,
L_3 ,
V_96 , V_52 ) ;
V_96 = V_2 -> V_93 + V_2 -> V_95 ;
V_2 -> V_99 = 0 ;
V_2 -> V_100 = 0 ;
if ( F_65 ( V_2 ) )
V_96 += 1 ;
F_68 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_93 , V_2 -> V_95 ,
V_96 ) ;
goto V_104;
} else if ( V_52 < 0 ) {
return V_52 ;
}
V_2 -> V_4 -> V_96 = V_96 ;
if ( V_2 -> V_99 > 0 )
V_2 -> V_93 = V_2 -> V_99 ;
if ( V_2 -> V_100 > 0 )
V_2 -> V_95 = V_2 -> V_100 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_96 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_52 , V_97 ;
if ( ! V_2 -> V_101 ) {
V_2 -> V_101 = F_66 ( V_96 ,
sizeof( struct V_102 ) ,
V_20 ) ;
if ( ! V_2 -> V_101 )
return - V_57 ;
}
V_2 -> V_41 &= ~ ( V_106 | V_107 ) ;
if ( V_2 -> V_4 -> V_108 ) {
V_109:
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ )
V_2 -> V_101 [ V_97 ] . V_103 = V_97 ;
V_52 = F_70 ( V_5 ,
V_2 -> V_101 , 1 , V_96 ) ;
if ( V_52 == V_96 ) {
V_2 -> V_41 |= V_107 ;
V_2 -> V_4 -> V_96 = V_96 ;
F_71 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_52 > 0 ) {
F_72 ( V_5 ) ;
F_71 ( & V_5 -> V_30 ,
L_3 ,
V_96 , V_52 ) ;
if ( F_57 ( V_2 ) ) {
V_96 = F_59 ( V_52 ) ;
if ( V_52 < V_110 )
return - V_105 ;
} else {
V_96 = F_59 ( V_52 - 1 ) ;
V_96 += 1 ;
if ( V_52 < V_111 )
return - V_105 ;
}
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) {
V_2 -> V_95 = V_96 ;
V_2 -> V_93 = V_112 ;
} else {
V_2 -> V_93 = V_96 / 2 ;
V_2 -> V_95 = V_2 -> V_93 ;
}
if ( V_96 ) {
F_71 ( & V_5 -> V_30 ,
L_6 ,
V_96 ) ;
goto V_109;
}
} else {
F_71 ( & V_5 -> V_30 ,
L_7 ,
V_96 , V_52 ) ;
return V_52 ;
}
}
return - V_113 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = V_2 -> V_95 ;
if ( F_73 ( V_2 ) )
V_96 += V_2 -> V_93 ;
else
V_96 += V_112 ;
return V_96 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
T_1 V_114 , V_115 ;
const struct V_116 * V_117 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_118 && ! F_76 ( V_5 ) ) {
V_2 -> V_41 |= V_106 ;
V_114 = V_119 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_120 = F_77 ( V_2 -> V_4 ,
V_114 ) ;
F_71 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_101 [ 0 ] . V_97 = V_5 -> V_121 ;
return V_52 ;
}
if ( V_118 || V_122 )
return - V_43 ;
V_117 = & V_123 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_124 = V_117 -> V_124 ;
V_114 = V_117 -> V_120 ;
V_2 -> V_120 = F_77 ( V_4 , V_114 ) ;
V_115 = V_117 -> V_125 ;
V_2 -> V_125 = F_77 ( V_4 , V_115 ) ;
V_2 -> V_126 = F_77 ( V_4 , V_127 ) ;
V_2 -> V_128 = F_77 ( V_4 , V_129 ) ;
F_71 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_101 [ 0 ] . V_97 = V_5 -> V_121 ;
return V_52 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_96 , V_52 = 0 ;
if ( V_2 -> V_41 & V_98 ) {
V_52 = F_64 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
V_96 = V_2 -> V_4 -> V_96 ;
} else {
V_96 = F_74 ( V_2 ) ;
V_52 = F_69 ( V_2 , V_96 ) ;
if ( V_52 == - V_57 )
return V_52 ;
if ( ! ( V_2 -> V_41 & V_107 ) ) {
F_79 ( V_2 ) ;
V_2 -> V_95 = V_112 ;
V_52 = F_75 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_130 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 , V_131 ;
if ( F_73 ( V_2 ) &&
! V_4 -> V_132 &&
( V_2 -> V_41 & V_107 ) ) {
V_4 -> V_133 = F_81 ( V_4 -> V_96 *
sizeof( struct V_134 ) ) ;
if ( ! V_4 -> V_133 )
return - V_57 ;
for ( V_131 = 0 ; V_131 < V_4 -> V_96 ; V_131 ++ ) {
V_4 -> V_133 [ V_131 ] . type = V_135 ;
V_4 -> V_133 [ V_131 ] . V_73 = V_131 ;
V_4 -> V_133 [ V_131 ] . V_136 = 0 ;
}
V_52 = F_82 ( V_2 , 1 ) ;
if ( V_52 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_96 ) ;
return V_52 ;
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_107 )
F_72 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_106 )
F_85 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
if ( V_2 -> V_4 -> V_133 ) {
F_86 ( V_2 -> V_4 -> V_133 ) ;
V_2 -> V_4 -> V_133 = NULL ;
}
}
static void F_87 ( struct V_3 * V_4 )
{
if ( V_4 -> V_137 != NULL )
F_88 ( V_4 -> V_137 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_138 * V_139 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_54 ) ) {
switch ( V_4 -> V_140 ) {
case V_141 :
V_4 -> V_142 = V_143 ;
break;
case V_144 :
V_4 -> V_142 = V_145 ;
break;
}
return 0 ;
}
if ( V_4 -> V_146 == V_147 )
return 0 ;
V_139 = F_66 ( V_4 -> V_148 , sizeof( * V_139 ) , V_20 ) ;
if ( ! V_139 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_139 ) ;
F_7 ( V_139 ) ;
return V_26 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_92 ( V_2 ) ) {
V_26 = true ;
} else if ( F_65 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_80 [ 0 ] &
V_149 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_138 * V_139 ;
int V_131 , V_73 = 0 , V_26 = 0 , V_150 = 0 ;
T_3 V_151 ;
T_2 V_152 ;
V_139 = F_66 ( V_4 -> V_148 , sizeof( * V_139 ) , V_20 ) ;
if ( ! V_139 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_139 ) ;
if ( V_26 )
goto V_153;
V_151 = V_4 -> V_142 ;
V_2 -> V_154 = F_5 ( sizeof( struct V_155 ) *
V_151 , V_20 ) ;
if ( ! V_2 -> V_154 ) {
V_26 = - V_57 ;
goto V_153;
}
V_2 -> V_156 = F_5 ( sizeof( struct V_157 ) *
V_145 , V_20 ) ;
if ( ! V_2 -> V_156 ) {
V_26 = - V_57 ;
goto V_158;
}
for ( V_131 = 0 ; V_131 < V_4 -> V_148 ; V_131 ++ ) {
V_152 = V_139 [ V_131 ] . V_73 ;
if ( V_152 >= V_4 -> V_148 ) {
V_26 = - V_40 ;
F_83 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_55 , V_152 , V_4 -> V_148 ) ;
goto V_159;
}
if ( ! V_139 [ V_131 ] . V_160 ||
( V_139 [ V_131 ] . type != V_161 ) )
continue;
if ( F_91 ( V_2 ) ) {
if ( ! F_94 ( V_2 , V_152 ,
& V_73 ) )
V_2 -> V_154 [ V_150 ] . V_162 = true ;
else
continue;
} else {
V_2 -> V_154 [ V_150 ] . V_162 = true ;
}
V_2 -> V_154 [ V_150 ] . V_27 = V_152 ;
V_2 -> V_154 [ V_150 ] . V_160 = ( T_2 ) V_139 [ V_131 ] . V_160 ;
V_2 -> V_154 [ V_150 ] . type = ( T_2 ) V_139 [ V_131 ] . type ;
V_2 -> V_154 [ V_150 ] . V_163 = ( T_2 ) V_139 [ V_131 ] . V_164 ;
V_2 -> V_154 [ V_150 ] . V_165 = V_139 [ V_131 ] . V_166 ;
V_2 -> V_154 [ V_150 ] . V_167 = V_139 [ V_131 ] . V_168 ;
memcpy ( & V_2 -> V_154 [ V_150 ] . V_169 , & V_139 [ V_131 ] . V_169 , V_25 ) ;
V_150 ++ ;
}
if ( ! F_91 ( V_2 ) ) {
for ( V_131 = 0 ; V_131 < V_145 ; V_131 ++ )
V_2 -> V_156 [ V_131 ] . V_41 |= V_170 ;
}
F_7 ( V_139 ) ;
return 0 ;
V_159:
F_7 ( V_2 -> V_156 ) ;
V_2 -> V_156 = NULL ;
V_158:
F_7 ( V_2 -> V_154 ) ;
V_2 -> V_154 = NULL ;
V_153:
F_7 ( V_139 ) ;
return V_26 ;
}
static int
F_95 ( struct V_1 * V_2 )
{
T_2 V_73 ;
int V_26 ;
T_1 V_171 = V_147 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_96 ( V_2 ) ;
if ( V_26 )
goto V_172;
V_73 = V_4 -> V_27 ;
V_171 = F_97 ( V_2 , V_173 ) ;
V_171 = ( V_171 & ~ F_98 ( 0xf , V_73 ) ) |
F_98 ( V_147 , V_73 ) ;
F_99 ( V_2 , V_173 , V_171 ) ;
F_100 ( V_2 ) ;
V_172:
return V_26 ;
}
static void F_101 ( struct V_1 * V_2 ,
const struct V_174 * V_175 )
{
T_1 V_146 , V_176 ;
V_2 -> V_4 -> V_177 = F_97 ( V_2 ,
V_178 ) ;
F_102 ( V_2 ) ;
V_146 = F_97 ( V_2 , V_173 ) ;
if ( V_146 == V_179 )
V_176 = V_147 ;
else
V_176 = F_103 ( V_146 , V_2 -> V_4 -> V_27 ) ;
if ( V_176 == V_180 ) {
V_2 -> V_4 -> V_146 = V_180 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_177 ) ;
V_2 -> V_181 = & V_182 ;
} else
V_2 -> V_181 = & V_183 ;
}
static void F_104 ( T_1 V_184 , T_7 * V_185 )
{
switch ( V_184 ) {
case V_7 :
* V_185 = V_186 ;
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
* V_185 = V_192 ;
break;
default:
* V_185 = 0 ;
}
}
static int F_105 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_114 ;
void T_8 * V_193 = NULL ;
unsigned long V_194 , V_195 = 0 , V_196 ;
V_194 = F_106 ( V_5 , 0 ) ;
F_104 ( V_5 -> V_6 , & V_196 ) ;
if ( V_194 >= V_196 ) {
V_193 = F_107 ( V_5 , 0 ) ;
if ( V_193 == NULL ) {
F_83 ( & V_5 -> V_30 , L_13 ) ;
return - V_113 ;
}
V_195 = V_194 ;
} else {
return - V_113 ;
}
F_71 ( & V_5 -> V_30 , L_14 , ( int ) ( V_194 >> 10 ) ) ;
V_4 -> V_137 = V_193 ;
V_4 -> V_195 = V_195 ;
V_114 = F_108 ( F_109 ( V_4 -> V_27 ) ) ;
F_77 ( V_4 , V_114 ) ;
return 0 ;
}
static bool F_110 ( struct V_1 * V_2 ,
int V_197 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_198 ;
bool V_26 = true ;
V_198 = V_5 -> V_198 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_187 ) {
if ( V_199 [ V_197 ] . V_200 == V_198 &&
V_199 [ V_197 ] . V_201 == V_5 -> V_202 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_111 ( struct V_1 * V_2 , char * V_203 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_131 , V_204 = 0 ;
for ( V_131 = 0 ; V_131 < V_205 ; ++ V_131 ) {
if ( V_199 [ V_131 ] . V_206 == V_5 -> V_206 &&
V_199 [ V_131 ] . V_6 == V_5 -> V_6 &&
F_110 ( V_2 , V_131 ) ) {
V_204 = 1 ;
break;
}
}
if ( ! V_204 )
sprintf ( V_203 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_203 , L_16 , V_2 -> V_24 ,
V_199 [ V_131 ] . V_207 ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
int V_52 ;
T_1 V_208 , V_209 , V_210 , V_211 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_212 * V_213 = & V_4 -> V_213 ;
V_211 = V_2 -> V_214 ;
V_208 = F_97 ( V_2 , V_215 ) ;
V_209 = F_97 ( V_2 , V_216 ) ;
V_210 = F_97 ( V_2 , V_217 ) ;
V_2 -> V_214 = F_113 ( V_208 , V_209 , V_210 ) ;
V_52 = F_114 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_146 != V_180 ) {
if ( V_213 -> V_218 == NULL ||
V_2 -> V_214 > V_211 ) {
F_86 ( V_213 -> V_218 ) ;
if ( ! F_115 ( V_2 ) )
F_71 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_71 ( & V_5 -> V_30 , L_19 ,
V_219 , V_208 , V_209 , V_210 ) ;
if ( V_2 -> V_4 -> V_140 == V_144 ) {
if ( V_2 -> V_41 & V_54 ) {
V_2 -> V_220 = V_221 ;
V_2 -> V_222 = V_223 ;
} else {
V_2 -> V_220 = V_224 ;
V_2 -> V_222 = V_225 ;
}
V_2 -> V_226 = V_227 ;
V_2 -> V_228 = V_227 ;
} else if ( V_2 -> V_4 -> V_140 == V_141 ) {
V_2 -> V_220 = V_229 ;
V_2 -> V_226 = V_230 ;
V_2 -> V_228 = V_230 ;
V_2 -> V_222 = V_231 ;
}
V_2 -> V_4 -> V_108 = ! ! V_122 ;
V_2 -> V_232 = V_233 ;
V_2 -> V_234 = V_235 ;
}
static int
F_116 ( struct V_1 * V_2 )
{
struct V_236 V_237 ;
int V_52 = 0 ;
memset ( & V_237 , 0 , sizeof( struct V_236 ) ) ;
V_52 = F_117 ( V_2 , & V_237 , V_2 -> V_4 -> V_27 ) ;
if ( V_52 )
return V_52 ;
V_2 -> V_4 -> V_238 = ( T_2 ) V_237 . V_239 ;
V_2 -> V_4 -> V_240 = V_237 . V_240 ;
V_2 -> V_4 -> V_241 = V_237 . V_241 ;
V_2 -> V_4 -> V_242 = V_237 . V_242 ;
V_2 -> V_4 -> V_8 = V_237 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_243 ) {
T_1 V_244 ;
V_244 = F_118 ( V_2 , V_245 , & V_52 ) ;
if ( V_52 == - V_113 )
return V_52 ;
V_2 -> V_4 -> V_80 [ 0 ] = V_244 ;
} else {
V_2 -> V_4 -> V_80 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_246 = V_237 . V_246 ;
V_2 -> V_4 -> V_247 = V_237 . V_247 ;
if ( V_2 -> V_4 -> V_8 & V_248 ) {
V_2 -> V_41 |= V_54 ;
V_2 -> V_4 -> V_249 = V_250 ;
V_2 -> V_91 = V_251 ;
V_2 -> V_89 = V_252 ;
F_71 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_249 = V_253 ;
V_2 -> V_91 = V_254 ;
V_2 -> V_89 = V_87 ;
V_2 -> V_41 &= ~ V_54 ;
}
return V_52 ;
}
void F_119 ( struct V_1 * V_2 ,
struct V_255 * V_256 )
{
if ( V_256 -> V_257 )
V_2 -> V_41 &= ~ V_258 ;
else
V_2 -> V_41 |= V_258 ;
if ( V_256 -> V_259 ) {
V_2 -> V_260 = V_256 -> V_259 ;
V_2 -> V_261 = V_256 -> V_259 ;
} else {
V_2 -> V_260 = 0 ;
V_2 -> V_261 = 0 ;
}
}
static int
F_120 ( struct V_21 * V_22 , T_5 V_262 , T_3 V_51 )
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
F_123 ( V_51 , V_2 -> V_263 ) ;
return 0 ;
}
static int
F_124 ( struct V_21 * V_22 , T_5 V_262 , T_3 V_51 )
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
F_125 ( V_22 , V_264 ) ;
F_126 ( V_51 , V_2 -> V_263 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_255 * V_256 )
{
V_2 -> V_41 &= ~ ( V_265 | V_42 |
V_266 ) ;
if ( V_256 -> V_267 )
V_2 -> V_41 |= V_265 ;
if ( ! V_256 -> V_268 )
V_2 -> V_41 |= V_42 ;
if ( ! V_256 -> V_269 )
V_2 -> V_41 |= V_266 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_255 V_256 ;
if ( ! ( V_2 -> V_41 & V_54 ) )
return 0 ;
V_256 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_129 ( V_2 , & V_256 ) )
return - V_113 ;
F_119 ( V_2 , & V_256 ) ;
F_127 ( V_2 , & V_256 ) ;
F_130 ( V_2 , & V_256 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_2 ,
struct V_255 * V_256 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_65 ( V_2 ) )
return;
V_2 -> V_270 = V_256 -> V_270 ;
V_2 -> V_41 |= V_271 ;
F_131 ( V_22 ) ;
V_2 -> V_41 &= ~ V_271 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_1 V_146 , V_176 ;
int V_52 = 0 ;
V_52 = F_116 ( V_2 ) ;
if ( V_52 )
return V_52 ;
if ( V_2 -> V_41 & V_272 )
return 0 ;
V_146 = F_97 ( V_2 , V_173 ) ;
V_176 = F_103 ( V_146 , V_2 -> V_4 -> V_27 ) ;
if ( V_146 == V_179 )
V_176 = V_147 ;
else
V_176 = F_103 ( V_146 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_54 ) {
if ( V_176 == V_147 ) {
V_2 -> V_4 -> V_146 = V_147 ;
V_52 = F_93 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_95 ( V_2 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_177 ) ;
} else if ( V_176 == V_273 ) {
V_2 -> V_4 -> V_146 = V_273 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_177 ) ;
}
} else {
V_2 -> V_4 -> V_249 = V_253 ;
}
V_2 -> V_41 |= V_272 ;
return V_52 ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_255 V_256 ;
struct V_155 * V_274 ;
T_2 V_131 ;
if ( V_2 -> V_275 )
return 0 ;
for ( V_131 = 0 ; V_131 < V_2 -> V_4 -> V_142 ; V_131 ++ ) {
if ( ! V_2 -> V_154 [ V_131 ] . V_162 )
continue;
memset ( & V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 . V_27 = V_2 -> V_154 [ V_131 ] . V_27 ;
V_256 . V_268 = V_276 ;
V_256 . V_269 = V_276 ;
if ( F_57 ( V_2 ) ) {
V_256 . V_270 = V_276 ;
if ( F_134 ( V_2 ) )
V_256 . V_270 |= ( V_277 | V_278 ) ;
}
if ( F_135 ( V_2 , & V_256 ) )
return - V_113 ;
V_274 = & V_2 -> V_154 [ V_131 ] ;
V_274 -> V_279 = V_256 . V_259 ;
V_274 -> V_268 = V_256 . V_268 ;
V_274 -> V_267 = V_256 . V_267 ;
V_274 -> V_257 = V_256 . V_257 ;
V_274 -> V_269 = V_256 . V_269 ;
V_274 -> V_270 = V_256 . V_270 ;
}
return 0 ;
}
static int
F_136 ( struct V_1 * V_2 ,
struct V_155 * V_274 , int V_27 )
{
struct V_255 V_256 ;
V_256 . V_146 = V_280 ;
V_256 . V_27 = V_27 ;
V_256 . V_259 = V_274 -> V_279 ;
V_256 . V_268 = V_274 -> V_268 ;
V_256 . V_257 = V_274 -> V_257 ;
V_256 . V_267 = V_274 -> V_267 ;
V_256 . V_270 = V_274 -> V_270 ;
V_256 . V_269 = V_274 -> V_269 ;
if ( F_135 ( V_2 , & V_256 ) )
return - V_113 ;
V_256 . V_146 = V_281 ;
if ( F_135 ( V_2 , & V_256 ) )
return - V_113 ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_131 , V_52 ;
struct V_155 * V_274 ;
struct V_236 V_237 ;
T_2 V_27 ;
if ( F_57 ( V_2 ) )
if ( ! V_2 -> V_275 )
return 0 ;
for ( V_131 = 0 ; V_131 < V_2 -> V_4 -> V_142 ; V_131 ++ ) {
V_274 = & V_2 -> V_154 [ V_131 ] ;
V_27 = V_274 -> V_27 ;
if ( ! V_2 -> V_154 [ V_131 ] . V_162 )
continue;
memset ( & V_237 , 0 , sizeof( struct V_236 ) ) ;
V_52 = F_117 ( V_2 , & V_237 , V_27 ) ;
if ( V_52 )
return V_52 ;
V_237 . V_282 = V_274 -> V_165 ;
V_237 . V_283 = V_274 -> V_167 ;
V_52 = F_138 ( V_2 , & V_237 ) ;
if ( V_52 )
return V_52 ;
if ( V_274 -> V_284 ) {
V_52 = F_139 ( V_2 ,
V_274 -> V_285 , 1 ,
V_27 ) ;
if ( V_52 )
return V_52 ;
}
V_52 = F_136 ( V_2 , V_274 , V_27 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
T_2 V_286 = V_287 ;
T_1 V_288 ;
if ( V_2 -> V_4 -> V_146 == V_147 )
return 0 ;
V_288 = F_97 ( V_2 ,
V_289 ) ;
while ( V_288 != V_290 && -- V_286 ) {
F_141 ( 1000 ) ;
V_288 = F_97 ( V_2 ,
V_289 ) ;
}
if ( ! V_286 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_113 ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
int V_52 ;
if ( ! ( V_2 -> V_41 & V_54 ) ||
V_2 -> V_4 -> V_146 != V_147 )
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
goto V_291;
if ( V_292 )
F_146 ( V_2 ) ;
else {
V_52 = F_147 ( V_2 ) ;
if ( V_52 )
goto V_293;
V_2 -> V_4 -> V_294 = V_295 ;
}
V_52 = F_148 ( V_2 ) ;
if ( V_52 == 0 )
goto V_291;
V_52 = F_149 ( V_2 ) ;
if ( V_52 )
goto V_293;
V_52 = F_150 ( V_2 ) ;
if ( V_52 )
goto V_293;
F_151 ( V_2 ) ;
F_152 ( V_2 , V_296 , V_297 ) ;
V_291:
V_52 = F_153 ( V_2 ) ;
if ( V_52 )
goto V_293;
F_99 ( V_2 , V_298 , V_299 ) ;
F_154 ( V_2 , 1 ) ;
V_52 = F_132 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_293;
}
V_52 = F_142 ( V_2 ) ;
if ( V_52 )
goto V_293;
F_112 ( V_2 ) ;
V_2 -> V_275 = 0 ;
F_151 ( V_2 ) ;
return 0 ;
V_293:
F_99 ( V_2 , V_298 , V_300 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_151 ( V_2 ) ;
return V_52 ;
}
static int
F_155 ( struct V_1 * V_2 )
{
T_9 V_301 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
int V_52 , V_303 , V_304 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_132 == V_305 ) {
if ( F_57 ( V_2 ) )
V_301 = V_306 ;
else
V_301 = V_307 ;
if ( ! F_156 ( V_2 ) )
V_41 |= V_308 ;
} else {
if ( V_2 -> V_41 & V_107 )
V_301 = V_309 ;
else if ( V_2 -> V_41 & V_106 )
V_301 = V_310 ;
else {
V_41 |= V_308 ;
if ( F_57 ( V_2 ) )
V_301 = V_311 ;
else
V_301 = V_312 ;
}
}
V_2 -> V_121 = V_22 -> V_121 ;
if ( V_2 -> V_4 -> V_132 != V_313 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_107 ) ) ) {
V_304 = V_2 -> V_95 ;
for ( V_303 = 0 ; V_303 < V_304 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) &&
( V_303 == ( V_304 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_107 ) )
snprintf ( V_302 -> V_203 ,
sizeof( V_302 -> V_203 ) ,
L_28 ) ;
else
snprintf ( V_302 -> V_203 ,
sizeof( V_302 -> V_203 ) ,
L_29 ,
V_22 -> V_203 , V_303 ) ;
} else {
snprintf ( V_302 -> V_203 ,
sizeof( V_302 -> V_203 ) ,
L_30 ,
V_22 -> V_203 , V_303 ) ;
}
V_52 = F_157 ( V_302 -> V_121 , V_301 , V_41 ,
V_302 -> V_203 , V_302 ) ;
if ( V_52 )
return V_52 ;
}
}
if ( ( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_107 ) &&
! ( V_2 -> V_41 & V_314 ) ) ) {
V_301 = V_315 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ;
V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
snprintf ( V_11 -> V_203 , sizeof( V_11 -> V_203 ) ,
L_31 , V_22 -> V_203 , V_303 ) ;
V_52 = F_157 ( V_11 -> V_121 , V_301 , V_41 ,
V_11 -> V_203 , V_11 ) ;
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
int V_303 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_132 != V_313 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_107 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_95 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
F_159 ( V_302 -> V_121 , V_302 ) ;
}
}
if ( ( F_65 ( V_2 ) &&
! ( V_2 -> V_41 & V_314 ) ) ||
( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ;
V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( V_11 -> V_121 )
F_159 ( V_11 -> V_121 , V_11 ) ;
}
}
}
}
static void F_160 ( struct V_1 * V_2 )
{
T_1 V_316 = 0 ;
if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_80 [ 0 ] &
V_317 )
V_2 -> V_41 |= V_318 ;
} else {
V_316 = V_2 -> V_4 -> V_8 ;
if ( F_161 ( V_316 ) )
V_2 -> V_41 |= V_318 ;
}
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 ;
V_4 -> V_319 . V_320 = V_321 ;
if ( F_65 ( V_2 ) ) {
V_4 -> V_319 . type = V_322 ;
V_4 -> V_319 . V_323 = V_324 ;
V_4 -> V_319 . V_325 = V_326 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
V_52 = F_163 ( V_2 ) ;
} else {
V_4 -> V_319 . type = V_331 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
V_52 = F_164 ( V_2 ) ;
}
return V_52 ;
}
int F_165 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_303 ;
struct V_332 * V_333 ;
if ( V_2 -> V_334 != V_335 )
return - V_113 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_128 ( V_2 ) )
return - V_113 ;
F_160 ( V_2 ) ;
if ( F_166 ( V_2 ) )
return - V_113 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_234 ; V_303 ++ ) {
V_333 = & V_2 -> V_15 -> V_336 [ V_303 ] ;
F_167 ( V_2 , V_333 , V_303 ) ;
}
F_24 ( V_22 ) ;
F_168 ( V_2 , V_22 -> V_337 ) ;
V_2 -> V_4 -> V_338 = 0 ;
if ( V_2 -> V_95 > 1 )
F_169 ( V_2 , 1 ) ;
F_162 ( V_2 ) ;
if ( V_22 -> V_79 & V_339 )
F_170 ( V_2 , V_340 ) ;
F_123 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_171 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_341 = 0 ;
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
int V_303 ;
if ( V_2 -> V_334 != V_335 )
return;
if ( ! F_178 ( V_45 , & V_2 -> V_46 ) )
return;
F_179 () ;
F_180 ( V_22 ) ;
V_2 -> V_4 -> V_338 = 0 ;
F_181 ( V_22 ) ;
F_182 ( V_2 ) ;
if ( V_2 -> V_342 . V_343 )
F_183 ( V_2 ) ;
F_184 ( V_2 , V_344 ) ;
if ( F_20 ( V_2 ) )
F_185 ( & V_2 -> V_4 -> V_345 -> V_346 ) ;
F_23 ( V_2 ) ;
F_186 ( V_2 ) ;
V_2 -> V_41 &= ~ V_318 ;
F_187 ( V_2 ) ;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ )
F_188 ( V_2 , & V_2 -> V_11 [ V_303 ] ) ;
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
if ( V_2 -> V_334 == V_335 )
return 0 ;
V_52 = F_191 ( V_2 , V_22 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_192 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_32 ) ;
goto V_347;
}
V_52 = F_193 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_33 ) ;
goto V_348;
}
V_52 = F_155 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_34 ) ;
goto V_349;
}
F_194 ( V_2 ) ;
#ifdef F_195
if ( F_50 ( V_2 ) )
F_196 ( V_22 ) ;
#endif
V_2 -> V_334 = V_335 ;
return 0 ;
V_349:
F_197 ( V_2 ) ;
V_348:
F_198 ( V_2 ) ;
V_347:
F_199 ( V_2 ) ;
return V_52 ;
}
void F_200 ( struct V_1 * V_2 )
{
if ( V_2 -> V_334 != V_335 )
return;
F_201 ( V_2 ) ;
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
F_158 ( V_2 ) ;
F_199 ( V_2 ) ;
F_198 ( V_2 ) ;
V_2 -> V_334 = 0 ;
}
void F_203 ( struct V_21 * V_22 , int V_95 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
int V_93 = V_2 -> V_93 ;
int V_303 ;
F_126 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_132 == V_305 ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_95 ; V_303 ++ ) {
V_302 = & V_2 -> V_15 -> V_19 [ V_303 ] ;
F_204 ( V_2 , V_302 ) ;
}
}
F_186 ( V_2 ) ;
F_200 ( V_2 ) ;
V_2 -> V_4 -> V_132 = 0 ;
V_2 -> V_95 = V_95 ;
V_2 -> V_93 = V_93 ;
if ( F_190 ( V_2 ) )
goto V_350;
if ( F_175 ( V_22 ) )
F_165 ( V_2 , V_22 ) ;
V_350:
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
goto V_293;
}
if ( F_65 ( V_2 ) ) {
V_4 -> V_319 . type = V_322 ;
V_4 -> V_319 . V_323 = V_324 ;
V_4 -> V_319 . V_325 = V_326 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
} else {
V_4 -> V_319 . type = V_331 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
}
memset ( & V_2 -> V_351 , 0 , sizeof( V_2 -> V_351 ) ) ;
V_293:
return V_52 ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_212 * V_213 = & V_2 -> V_4 -> V_213 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_213 -> V_218 ) {
F_86 ( V_213 -> V_218 ) ;
V_213 -> V_218 = NULL ;
}
if ( V_213 -> V_352 ) {
F_207 ( & V_2 -> V_5 -> V_30 , V_353 ,
V_213 -> V_352 , V_213 -> V_354 ) ;
V_213 -> V_352 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_355 . V_356 ) ;
V_2 -> V_4 -> V_213 . V_218 = NULL ;
}
int F_208 ( struct V_21 * V_22 , int V_357 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
struct V_332 * V_333 ;
int V_303 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
V_2 -> V_95 = V_112 ;
V_2 -> V_4 -> V_132 = V_357 ;
V_2 -> V_4 -> V_338 = 0 ;
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
for ( V_303 = 0 ; V_303 < V_2 -> V_234 ; V_303 ++ ) {
V_333 = & V_2 -> V_15 -> V_336 [ V_303 ] ;
F_167 ( V_2 , V_333 , V_303 ) ;
}
if ( V_2 -> V_4 -> V_132 == V_305 ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_95 ; V_303 ++ ) {
V_302 = & V_2 -> V_15 -> V_19 [ V_303 ] ;
F_209 ( V_2 , V_302 ) ;
}
}
if ( V_2 -> V_4 -> V_132 == V_313 ) {
V_2 -> V_4 -> V_358 = 0 ;
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
return - V_359 ;
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
return - V_359 ;
if ( V_2 -> V_334 == V_335 ) {
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( ! V_52 ) {
F_165 ( V_2 , V_22 ) ;
F_125 ( V_22 , V_360 ) ;
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
T_3 V_361 = V_4 -> V_142 ;
T_3 V_16 ;
V_4 -> V_362 = V_363 ;
if ( V_361 <= 2 )
V_16 = ( V_364 - V_363 ) /
V_361 ;
else
V_16 = ( V_365 - V_363 ) /
V_361 ;
V_4 -> V_56 = V_16 ;
}
static int F_213 ( struct V_1 * V_2 ,
T_2 V_366 , T_2 V_367 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_52 = 0 ;
if ( V_366 ) {
V_52 = F_214 ( V_22 , V_366 ) ;
if ( V_52 ) {
F_122 ( V_22 , L_36 ,
V_366 ) ;
return V_52 ;
}
}
if ( V_367 ) {
V_52 = F_215 ( V_22 , V_367 ) ;
if ( V_52 )
F_122 ( V_22 , L_37 ,
V_367 ) ;
}
return V_52 ;
}
int
F_216 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_368 )
{
int V_52 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_369 = 1 ;
V_2 -> V_4 -> V_370 = 0 ;
F_217 ( V_2 ) ;
V_22 -> V_371 = & V_372 ;
V_22 -> V_373 = V_374 * V_375 ;
F_218 ( V_22 , V_22 -> V_337 ) ;
V_22 -> V_376 = ( F_20 ( V_2 ) ) ?
& V_377 : & V_378 ;
V_22 -> V_79 |= ( V_379 | V_380 | V_381 |
V_382 | V_383 |
V_384 ) ;
V_22 -> V_385 |= ( V_379 | V_380 |
V_382 ) ;
if ( F_134 ( V_2 ) ) {
V_22 -> V_79 |= ( V_386 | V_387 ) ;
V_22 -> V_385 |= ( V_386 | V_387 ) ;
}
if ( V_368 ) {
V_22 -> V_79 |= V_388 ;
V_22 -> V_385 |= V_388 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_79 |= ( V_389 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_79 |= V_390 ;
if ( V_2 -> V_4 -> V_8 & V_391 )
V_22 -> V_79 |= V_339 ;
if ( F_219 ( V_2 ) ) {
V_22 -> V_79 |= V_392 ;
V_22 -> V_393 = V_380 |
V_392 |
V_386 |
V_387 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_393 |= V_381 ;
V_22 -> V_394 = V_22 -> V_79 ;
V_22 -> V_395 |= V_396 ;
V_22 -> V_121 = V_2 -> V_101 [ 0 ] . V_97 ;
V_52 = F_213 ( V_2 , V_2 -> V_93 ,
V_2 -> V_95 ) ;
if ( V_52 )
return V_52 ;
F_220 ( V_2 -> V_397 ) ;
V_52 = F_221 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_38 ) ;
return V_52 ;
}
return 0 ;
}
static int F_222 ( struct V_23 * V_5 , int * V_368 )
{
if ( ! F_223 ( V_5 , F_224 ( 64 ) ) &&
! F_225 ( V_5 , F_224 ( 64 ) ) )
* V_368 = 1 ;
else if ( ! F_223 ( V_5 , F_224 ( 32 ) ) &&
! F_225 ( V_5 , F_224 ( 32 ) ) )
* V_368 = 0 ;
else {
F_83 ( & V_5 -> V_30 , L_39 ) ;
return - V_113 ;
}
return 0 ;
}
void F_226 ( struct V_1 * V_2 )
{
int V_303 ;
struct V_10 * V_11 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( V_11 ) {
F_86 ( V_11 -> V_398 ) ;
V_11 -> V_398 = NULL ;
}
}
F_7 ( V_2 -> V_11 ) ;
}
int F_227 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_303 , V_97 , V_197 ;
struct V_10 * V_11 ;
struct V_399 * V_398 ;
V_11 = F_66 ( V_2 -> V_93 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_57 ;
V_2 -> V_11 = V_11 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
V_11 -> V_400 = V_2 -> V_232 ;
V_11 -> V_401 = F_228 ( V_22 , V_303 ) ;
V_398 = F_81 ( F_229 ( V_11 ) ) ;
if ( V_398 == NULL ) {
F_226 ( V_2 ) ;
return - V_57 ;
}
memset ( V_398 , 0 , F_229 ( V_11 ) ) ;
V_11 -> V_398 = V_398 ;
F_230 ( & V_11 -> V_402 ) ;
}
if ( F_65 ( V_2 ) ||
( F_57 ( V_2 ) && F_73 ( V_2 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_107 ) {
V_197 = V_2 -> V_95 + V_303 ;
V_97 = V_2 -> V_101 [ V_197 ] . V_97 ;
V_11 -> V_121 = V_97 ;
}
}
}
return 0 ;
}
void F_231 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_403 = 0 ;
if ( F_57 ( V_2 ) )
V_403 = V_404 ;
else if ( F_65 ( V_2 ) )
V_403 = V_405 ;
if ( V_4 -> V_80 [ 0 ] & V_406 )
F_232 ( V_2 , V_403 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
F_100 ( V_2 ) ;
}
static int
F_234 ( struct V_23 * V_5 , const struct V_174 * V_175 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_52 , V_368 = - 1 ;
char V_407 [ V_408 + 19 ] ;
V_52 = F_235 ( V_5 ) ;
if ( V_52 )
return V_52 ;
if ( ! ( F_236 ( V_5 , 0 ) & V_409 ) ) {
V_52 = - V_410 ;
goto V_411;
}
V_52 = F_222 ( V_5 , & V_368 ) ;
if ( V_52 )
goto V_411;
V_52 = F_237 ( V_5 , V_412 ) ;
if ( V_52 )
goto V_411;
F_238 ( V_5 ) ;
F_239 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_52 = - V_57 ;
goto V_413;
}
switch ( V_175 -> V_6 ) {
case V_7 :
V_4 -> V_414 = & V_415 ;
V_4 -> V_416 = ( T_1 * ) V_417 ;
break;
case V_187 :
case V_188 :
case V_189 :
F_240 ( V_4 ) ;
break;
case V_190 :
case V_191 :
F_241 ( V_4 ) ;
break;
default:
goto V_418;
}
V_52 = F_105 ( V_5 , V_4 ) ;
if ( V_52 )
goto V_418;
V_22 = F_242 ( sizeof( struct V_1 ) ,
V_419 ) ;
if ( ! V_22 ) {
V_52 = - V_57 ;
goto V_420;
}
F_243 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_421 = F_244 ( L_28 ) ;
if ( V_2 -> V_421 == NULL ) {
V_52 = - V_57 ;
F_83 ( & V_5 -> V_30 , L_40 ) ;
goto V_422;
}
V_52 = F_205 ( V_2 ) ;
if ( V_52 )
goto V_423;
V_2 -> V_424 = V_425 ;
V_4 -> V_426 = V_5 -> V_427 ;
V_4 -> V_148 = F_245 ( V_2 ) ;
if ( V_428 == V_429 )
V_2 -> V_53 = true ;
else if ( V_428 == V_430 )
V_2 -> V_431 = true ;
F_246 ( & V_2 -> V_4 -> V_432 ) ;
F_247 ( & V_2 -> V_4 -> V_433 ) ;
F_248 ( & V_2 -> V_434 ) ;
F_249 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_101 ( V_2 , V_175 ) ;
V_2 -> V_435 = V_2 -> V_4 -> V_27 ;
F_233 ( V_2 ) ;
V_52 = F_250 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_436;
}
if ( V_2 -> V_4 -> V_108 ) {
if ( F_56 ( V_2 ) == 1 )
F_62 ( V_2 ,
V_112 ) ;
else
F_62 ( V_2 ,
V_437 ) ;
F_63 ( V_2 ,
V_438 ) ;
} else {
F_62 ( V_2 , V_112 ) ;
F_63 ( V_2 , V_112 ) ;
}
V_52 = F_251 ( V_2 ) ;
if ( V_52 )
goto V_349;
V_2 -> V_41 |= V_439 ;
} else if ( F_65 ( V_2 ) ) {
F_252 ( V_2 , V_175 ) ;
V_2 -> V_435 = V_2 -> V_4 -> V_27 ;
V_52 = F_253 ( V_2 , V_368 ) ;
if ( V_52 ) {
switch ( V_52 ) {
case - V_440 :
F_83 ( & V_5 -> V_30 , L_43 ) ;
F_83 ( & V_5 -> V_30 , L_44 ) ;
goto V_349;
case - V_57 :
F_83 ( & V_5 -> V_30 , L_45 ) ;
goto V_349;
case - V_43 :
F_83 ( & V_5 -> V_30 , L_46 ) ;
goto V_349;
default:
F_83 ( & V_5 -> V_30 , L_47 ) ;
goto V_436;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_83 ( & V_5 -> V_30 ,
L_48 , V_55 ) ;
V_52 = - V_410 ;
goto V_349;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_254 ( V_2 ) ;
if ( V_2 -> V_435 == 0 ) {
F_111 ( V_2 , V_407 ) ;
F_37 ( L_50 ,
F_255 ( V_441 ) ,
V_407 , V_2 -> V_4 -> V_426 ) ;
}
if ( F_65 ( V_2 ) && ! V_122 &&
! ! V_118 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_57 ( V_2 ) ) {
F_256 ( V_2 -> V_397 ) ;
F_257 ( V_2 -> V_397 ) ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_52 ) ;
goto V_442;
}
}
V_52 = F_89 ( V_2 ) ;
if ( V_52 )
goto V_443;
if ( V_2 -> V_435 == 0 )
F_231 ( V_2 ) ;
V_52 = F_216 ( V_2 , V_22 , V_368 ) ;
if ( V_52 )
goto V_443;
F_259 ( V_5 , V_2 ) ;
if ( F_57 ( V_2 ) )
F_260 ( V_2 , V_444 ,
V_445 ) ;
switch ( V_2 -> V_4 -> V_140 ) {
case V_141 :
F_71 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_203 ) ;
break;
case V_144 :
F_71 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_203 ) ;
break;
}
if ( V_2 -> V_431 )
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
F_263 ( V_2 ) ;
return 0 ;
V_443:
if ( F_65 ( V_2 ) )
F_264 ( V_2 ) ;
V_442:
F_84 ( V_2 ) ;
F_265 ( V_2 ) ;
F_266 ( V_2 , 0 ) ;
V_349:
F_206 ( V_2 ) ;
V_423:
F_267 ( V_2 -> V_421 ) ;
V_422:
F_268 ( V_22 ) ;
V_420:
F_87 ( V_4 ) ;
V_418:
F_7 ( V_4 ) ;
V_413:
F_269 ( V_5 ) ;
V_411:
F_270 ( V_5 ) ;
return V_52 ;
V_436:
F_123 ( V_446 , & V_2 -> V_46 ) ;
V_22 -> V_371 = & V_447 ;
V_22 -> V_376 = & V_448 ;
V_4 -> V_140 = V_144 ;
if ( F_65 ( V_2 ) )
V_2 -> V_120 = NULL ;
else
V_4 -> V_449 = V_450 ;
V_52 = F_221 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_55 ) ;
F_266 ( V_2 , 0 ) ;
goto V_349;
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
F_47 ( & V_2 -> V_451 ) ;
F_264 ( V_2 ) ;
F_277 ( V_2 ) ;
F_278 ( V_4 -> V_452 ) ;
F_7 ( V_4 -> V_453 ) ;
}
F_279 ( V_2 -> V_397 ) ;
F_200 ( V_2 ) ;
F_7 ( V_2 -> V_154 ) ;
F_7 ( V_2 -> V_156 ) ;
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
if ( V_2 -> V_421 ) {
F_267 ( V_2 -> V_421 ) ;
V_2 -> V_421 = NULL ;
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
int V_454 ;
V_454 = F_285 ( V_5 ) ;
if ( V_454 )
return V_454 ;
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
F_287 ( V_5 , V_455 ) ;
F_238 ( V_5 ) ;
F_290 ( V_5 ) ;
return F_291 ( V_2 ) ;
}
static int F_292 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 ;
if ( F_21 ( V_446 , & V_2 -> V_46 ) ) {
F_122 ( V_22 , L_56 ,
V_55 ) ;
return - V_113 ;
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
int V_131 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_456 = 0 ;
T_3 V_151 = 0 ;
if ( V_2 -> V_342 . V_457 && V_2 -> V_342 . V_458 )
return;
V_151 = V_2 -> V_4 -> V_142 ;
F_230 ( & V_2 -> V_459 ) ;
F_230 ( & V_2 -> V_460 ) ;
if ( F_20 ( V_2 ) ) {
V_456 = V_461 - 1 ;
V_2 -> V_342 . V_462 = V_463 ;
} else if ( F_57 ( V_2 ) ) {
V_456 = V_365 ;
V_2 -> V_342 . V_462 = V_464 ;
} else {
V_456 = V_465 ;
V_2 -> V_342 . V_462 = V_466 ;
}
V_34 = F_66 ( V_2 -> V_342 . V_462 ,
sizeof( struct V_467 ) , V_468 ) ;
if ( ! V_34 )
return;
V_2 -> V_342 . V_457 = ( V_456 / V_151 ) ;
V_2 -> V_342 . V_458 = V_34 ;
F_68 ( V_22 , L_57 ,
V_151 , V_2 -> V_342 . V_457 ) ;
for ( V_131 = 0 ; V_131 < V_2 -> V_342 . V_462 ; V_131 ++ )
F_294 ( & V_2 -> V_342 . V_458 [ V_131 ] ) ;
V_2 -> V_469 . V_462 = V_2 -> V_342 . V_462 ;
V_34 = F_66 ( V_2 -> V_469 . V_462 ,
sizeof( struct V_467 ) , V_468 ) ;
if ( ! V_34 )
return;
V_2 -> V_469 . V_457 = ( V_456 / V_151 ) ;
V_2 -> V_469 . V_458 = V_34 ;
for ( V_131 = 0 ; V_131 < V_2 -> V_469 . V_462 ; V_131 ++ )
F_294 ( & V_2 -> V_469 . V_458 [ V_131 ] ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
if ( V_2 -> V_342 . V_457 )
F_7 ( V_2 -> V_342 . V_458 ) ;
V_2 -> V_342 . V_458 = NULL ;
V_2 -> V_342 . V_457 = 0 ;
if ( V_2 -> V_469 . V_457 )
F_7 ( V_2 -> V_469 . V_458 ) ;
V_2 -> V_469 . V_457 = 0 ;
V_2 -> V_469 . V_458 = NULL ;
}
int F_295 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_470 , V_471 , V_244 = 0 ;
int V_472 = 0 ;
if ( F_65 ( V_2 ) )
V_244 = F_296 ( V_2 -> V_4 , V_473 ) ;
if ( F_57 ( V_2 ) )
V_244 = F_97 ( V_2 , V_474 ) ;
V_470 = F_297 ( V_244 ) ;
V_471 = F_298 ( V_244 ) ;
if ( V_470 == V_475 ) {
F_83 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_471 ) ;
V_472 = 1 ;
} else if ( V_470 == V_476 ) {
if ( V_2 -> V_4 -> V_244 == V_477 ) {
F_83 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_471 ) ;
}
} else {
if ( V_2 -> V_4 -> V_244 == V_476 ) {
F_71 ( & V_22 -> V_30 ,
L_63
L_64 , V_471 ) ;
}
}
V_2 -> V_4 -> V_244 = V_470 ;
return V_472 ;
}
static inline void F_299 ( struct V_10 * V_11 )
{
int V_131 ;
struct V_478 * V_479 ;
for ( V_131 = 0 ; V_131 < V_11 -> V_400 ; V_131 ++ ) {
V_479 = & V_11 -> V_480 [ V_131 ] ;
F_37 ( L_65 , V_131 ) ;
F_300 ( V_481 , L_66 , V_482 , 16 , 1 ,
& V_11 -> V_480 [ V_131 ] ,
sizeof( struct V_478 ) , true ) ;
}
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_332 * V_333 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
int V_303 ;
if ( ! V_22 || ! F_175 ( V_22 ) )
return;
for ( V_303 = 0 ; V_303 < V_2 -> V_234 ; V_303 ++ ) {
V_333 = & V_15 -> V_336 [ V_303 ] ;
if ( ! V_333 )
continue;
F_68 ( V_22 ,
L_67 ,
V_303 , F_302 ( V_333 -> V_483 ) ,
V_333 -> V_12 , V_333 -> V_400 ) ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_95 ; V_303 ++ ) {
V_302 = & ( V_15 -> V_19 [ V_303 ] ) ;
if ( ! V_302 )
continue;
F_68 ( V_22 ,
L_68 ,
V_303 , F_302 ( V_302 -> V_484 ) ,
V_302 -> V_485 , F_302 ( V_302 -> V_486 ) ,
V_302 -> V_400 ) ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( ! V_11 )
continue;
F_68 ( V_22 , L_69 ,
V_303 , V_11 -> V_487 ) ;
F_68 ( V_22 ,
L_70 ,
V_11 -> V_488 . V_489 ,
V_11 -> V_488 . V_490 ,
V_11 -> V_488 . V_491 ,
V_11 -> V_488 . V_492 ) ;
if ( V_11 -> V_486 )
F_68 ( V_22 , L_71 ,
F_302 ( V_11 -> V_486 ) ) ;
F_68 ( V_22 ,
L_72 ,
F_302 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_493 ,
F_303 ( * ( V_11 -> V_494 ) ) ) ;
F_68 ( V_22 , L_73 ,
V_11 -> V_400 , F_304 ( V_11 ) ) ;
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
if ( ++ V_2 -> V_495 >= V_496 ||
F_305 ( V_2 -> V_4 ) ) {
F_122 ( V_22 , L_74 ) ;
if ( F_57 ( V_2 ) )
V_2 -> V_275 = 1 ;
else if ( F_65 ( V_2 ) )
F_307 ( V_2 ,
V_497 ) ;
} else {
F_122 ( V_22 , L_75 ) ;
V_2 -> V_4 -> V_341 = 1 ;
}
}
static struct V_498 * F_308 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_498 * V_351 = & V_22 -> V_351 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_309 ( V_2 ) ;
V_351 -> V_329 = V_2 -> V_351 . V_499 + V_2 -> V_351 . V_500 ;
V_351 -> V_325 = V_2 -> V_351 . V_501 ;
V_351 -> V_502 = V_2 -> V_351 . V_503 + V_2 -> V_351 . V_504 ;
V_351 -> V_505 = V_2 -> V_351 . V_506 ;
V_351 -> V_507 = V_2 -> V_351 . V_508 ;
V_351 -> V_509 = V_2 -> V_351 . V_510 ;
return V_351 ;
}
static T_11 F_310 ( struct V_1 * V_2 )
{
T_1 V_511 ;
V_511 = F_302 ( V_2 -> V_126 ) ;
if ( ! ( V_511 & V_2 -> V_4 -> V_124 ) )
return V_512 ;
V_511 = F_302 ( V_2 -> V_128 ) ;
if ( ! F_311 ( V_511 ) )
return V_512 ;
F_3 ( 0xffffffff , V_2 -> V_120 ) ;
F_302 ( V_2 -> V_126 ) ;
F_302 ( V_2 -> V_126 ) ;
return V_513 ;
}
static T_11 V_306 ( int V_121 , void * V_171 )
{
struct V_18 * V_302 = V_171 ;
struct V_1 * V_2 = V_302 -> V_2 ;
if ( V_2 -> V_41 & V_107 )
goto V_514;
else if ( V_2 -> V_41 & V_106 ) {
F_3 ( 0xffffffff , V_2 -> V_120 ) ;
goto V_514;
}
if ( F_312 ( V_2 ) == V_512 )
return V_512 ;
V_514:
V_2 -> V_4 -> V_515 ++ ;
F_209 ( V_2 , V_302 ) ;
return V_513 ;
}
static T_11 V_311 ( int V_121 , void * V_171 )
{
struct V_18 * V_302 = V_171 ;
struct V_1 * V_2 = V_302 -> V_2 ;
if ( F_312 ( V_2 ) == V_512 )
return V_512 ;
F_313 ( & V_302 -> V_516 ) ;
return V_513 ;
}
static T_11 V_310 ( int V_121 , void * V_171 )
{
struct V_18 * V_302 = V_171 ;
struct V_1 * V_2 = V_302 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_120 ) ;
F_313 ( & V_302 -> V_516 ) ;
return V_513 ;
}
static T_11 V_309 ( int V_121 , void * V_171 )
{
struct V_18 * V_302 = V_171 ;
F_313 ( & V_302 -> V_516 ) ;
return V_513 ;
}
static T_11 V_315 ( int V_121 , void * V_171 )
{
struct V_10 * V_11 = V_171 ;
F_313 ( & V_11 -> V_516 ) ;
return V_513 ;
}
static void F_314 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_303 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_95 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
F_204 ( V_2 , V_302 ) ;
F_313 ( & V_302 -> V_516 ) ;
}
if ( V_2 -> V_41 & V_107 ) {
if ( ( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_314 ) ) ||
( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) )
return;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
F_315 ( V_2 , V_11 ) ;
F_313 ( & V_11 -> V_516 ) ;
}
}
}
static void
F_154 ( struct V_1 * V_2 , T_2 V_517 )
{
T_1 V_518 ;
V_518 = V_2 -> V_435 & 0xf ;
V_518 |= V_517 << 7 ;
V_518 |= ( V_425 - V_2 -> V_424 ) << 8 ;
F_99 ( V_2 , V_519 , V_518 ) ;
V_2 -> V_424 = V_425 ;
}
static int
F_316 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_518 ;
F_317 ( V_46 != V_520 &&
V_46 != V_521 ) ;
if ( F_96 ( V_2 ) )
return - V_113 ;
V_518 = F_97 ( V_2 , V_522 ) ;
if ( V_46 == V_520 )
F_318 ( V_518 , V_2 -> V_435 ) ;
else if ( V_46 == V_521 )
F_319 ( V_518 , V_2 -> V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
static int
F_320 ( struct V_1 * V_2 )
{
T_1 V_518 ;
if ( F_96 ( V_2 ) )
return - V_359 ;
V_518 = F_97 ( V_2 , V_522 ) ;
F_321 ( V_518 , V_2 -> V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
void F_266 ( struct V_1 * V_2 , T_2 V_523 )
{
T_1 V_518 ;
if ( F_96 ( V_2 ) )
goto V_52;
V_518 = F_97 ( V_2 , V_524 ) ;
F_322 ( V_518 , V_2 -> V_435 ) ;
F_99 ( V_2 , V_524 , V_518 ) ;
if ( V_523 ) {
F_99 ( V_2 , V_298 ,
V_300 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_76 ) ;
} else if ( ! ( V_518 & 0x11111111 ) )
F_99 ( V_2 , V_298 ,
V_525 ) ;
V_518 = F_97 ( V_2 , V_522 ) ;
F_321 ( V_518 , V_2 -> V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
F_100 ( V_2 ) ;
V_52:
V_2 -> V_526 = 0 ;
V_2 -> V_41 &= ~ V_527 ;
F_126 ( V_528 , & V_2 -> V_46 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
}
static int
F_323 ( struct V_1 * V_2 )
{
int V_529 , V_46 , V_530 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_97 ( V_2 , V_522 ) ;
V_529 = F_97 ( V_2 , V_524 ) ;
if ( V_2 -> V_41 & V_531 ) {
V_530 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_529 = V_529 & V_530 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_529 & 0x11111111 ) ) ||
( ( V_529 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_324 ( struct V_1 * V_2 )
{
T_1 V_518 = F_97 ( V_2 , V_532 ) ;
if ( V_518 != V_533 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_533 , V_518 ) ;
}
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 )
{
T_1 V_518 , V_534 ;
T_2 V_535 = V_2 -> V_535 ;
T_2 V_435 = V_2 -> V_435 ;
T_2 V_26 ;
if ( F_178 ( V_528 , & V_2 -> V_46 ) )
return 1 ;
if ( F_96 ( V_2 ) )
return - 1 ;
V_518 = F_97 ( V_2 , V_524 ) ;
if ( ! ( V_518 & ( 1 << ( V_435 * 4 ) ) ) ) {
F_325 ( V_518 , V_435 ) ;
F_99 ( V_2 , V_524 , V_518 ) ;
}
V_534 = F_97 ( V_2 , V_298 ) ;
F_326 ( V_2 , V_536 , L_79 , V_534 ) ;
switch ( V_534 ) {
case V_525 :
F_99 ( V_2 , V_298 ,
V_537 ) ;
F_99 ( V_2 , V_532 ,
V_533 ) ;
F_154 ( V_2 , 0 ) ;
F_100 ( V_2 ) ;
return 1 ;
case V_299 :
V_26 = F_324 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
case V_520 :
V_518 = F_97 ( V_2 , V_522 ) ;
F_318 ( V_518 , V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
break;
case V_521 :
V_518 = F_97 ( V_2 , V_522 ) ;
F_319 ( V_518 , V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
break;
case V_300 :
F_83 ( & V_2 -> V_5 -> V_30 , L_80 ) ;
F_100 ( V_2 ) ;
return - 1 ;
case V_537 :
case V_538 :
break;
}
F_100 ( V_2 ) ;
do {
F_141 ( 1000 ) ;
V_534 = F_97 ( V_2 , V_298 ) ;
if ( V_534 == V_538 )
continue;
} while ( ( V_534 != V_299 ) && -- V_535 );
if ( ! V_535 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_81 ) ;
return - 1 ;
}
if ( F_96 ( V_2 ) )
return - 1 ;
V_518 = F_97 ( V_2 , V_522 ) ;
F_321 ( V_518 , V_435 ) ;
F_99 ( V_2 , V_522 , V_518 ) ;
V_26 = F_324 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
}
static void
F_327 ( struct V_539 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
T_1 V_540 = 0xf ;
T_1 V_518 ;
if ( F_96 ( V_2 ) )
goto V_541;
V_540 = F_97 ( V_2 , V_298 ) ;
if ( V_540 == V_538 ||
V_540 == V_521 ) {
F_100 ( V_2 ) ;
F_260 ( V_2 , F_327 ,
V_445 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_146 == V_180 ) {
F_100 ( V_2 ) ;
goto V_542;
}
if ( V_540 == V_537 ||
V_540 == V_299 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_82
L_83 ) ;
goto V_543;
}
if ( V_2 -> V_544 ++ > V_2 -> V_545 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_84 ,
V_2 -> V_545 ) ;
goto V_543;
}
if ( ! F_323 ( V_2 ) ) {
V_543:
V_540 = F_97 ( V_2 , V_298 ) ;
if ( V_540 == V_520 ) {
F_99 ( V_2 , V_298 ,
V_537 ) ;
F_123 ( V_528 , & V_2 -> V_46 ) ;
F_326 ( V_2 , V_546 , L_85 ) ;
F_154 ( V_2 , 0 ) ;
V_518 = F_97 ( V_2 ,
V_522 ) ;
F_318 ( V_518 , V_2 -> V_435 ) ;
F_99 ( V_2 ,
V_522 , V_518 ) ;
}
F_100 ( V_2 ) ;
F_174 () ;
if ( F_329 ( V_2 ) &&
( V_2 -> V_41 & V_531 ) ) {
F_326 ( V_2 , V_546 , L_86 ) ;
F_330 ( V_2 ) ;
V_2 -> V_41 |= V_527 ;
}
F_176 () ;
V_2 -> V_41 &= ~ V_531 ;
if ( ! V_2 -> V_181 -> V_547 ( V_2 ) ) {
F_260 ( V_2 , V_548 , 0 ) ;
V_2 -> V_544 = 0 ;
return;
}
goto V_541;
}
F_100 ( V_2 ) ;
V_542:
V_540 = F_97 ( V_2 , V_298 ) ;
F_326 ( V_2 , V_536 , L_87 , V_540 ) ;
switch ( V_540 ) {
case V_299 :
if ( ! F_250 ( V_2 ) ) {
F_260 ( V_2 , V_548 , 0 ) ;
V_2 -> V_544 = 0 ;
return;
}
case V_300 :
break;
default:
F_260 ( V_2 ,
F_327 , V_445 ) ;
return;
}
V_541:
F_83 ( & V_2 -> V_5 -> V_30 , L_88
L_89 , V_540 , V_2 -> V_544 ) ;
F_25 ( V_2 -> V_22 ) ;
F_266 ( V_2 , 0 ) ;
}
static void
F_331 ( struct V_539 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_511 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_540 == V_521 ) {
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
} else
F_189 ( V_2 , V_22 ) ;
V_511 = F_97 ( V_2 , V_549 ) ;
if ( V_511 & V_550 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_90 ,
V_511 ) ;
if ( F_332 ( V_511 ) == V_551 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_91
L_92 ) ;
F_83 ( & V_2 -> V_5 -> V_30 ,
L_93 ) ;
}
goto V_541;
}
if ( V_2 -> V_4 -> V_244 == V_475 ) {
F_83 ( & V_2 -> V_5 -> V_30 , L_94 ,
V_2 -> V_4 -> V_244 ) ;
goto V_541;
}
if ( ! ( V_2 -> V_41 & V_531 ) ) {
if ( F_316 ( V_2 , V_2 -> V_540 ) ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_95
L_96 ) ;
goto V_541;
}
}
V_2 -> V_544 = 0 ;
F_260 ( V_2 , F_327 , V_445 ) ;
return;
V_541:
F_25 ( V_22 ) ;
F_266 ( V_2 , 1 ) ;
}
static void
F_333 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_97 ( V_2 , V_289 ) ;
if ( V_46 == V_552 )
return;
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_289 ,
V_552 ) ;
F_100 ( V_2 ) ;
}
static void F_334 ( struct V_1 * V_2 ,
T_1 V_553 )
{
T_1 V_46 , V_554 = 0 , V_555 = 0 ;
F_335 ( V_554 ) ;
F_336 ( V_554 ) ;
F_152 ( V_2 , V_556 , V_554 ) ;
F_337 ( V_555 ) ;
F_338 ( V_555 ) ;
F_339 ( V_555 ) ;
F_340 ( V_555 ) ;
F_152 ( V_2 , V_557 , V_555 ) ;
F_71 ( & V_2 -> V_5 -> V_30 , L_97
L_98 ) ;
V_2 -> V_275 = 1 ;
if ( F_96 ( V_2 ) )
return;
V_46 = F_97 ( V_2 , V_298 ) ;
if ( F_21 ( V_446 , & V_2 -> V_46 ) ) {
F_122 ( V_2 -> V_22 , L_56 ,
V_55 ) ;
F_100 ( V_2 ) ;
return;
}
if ( V_46 == V_299 ) {
F_99 ( V_2 , V_298 ,
V_520 ) ;
V_2 -> V_41 |= V_531 ;
F_326 ( V_2 , V_546 , L_99 ) ;
F_154 ( V_2 , 0 ) ;
}
F_99 ( V_2 , V_289 ,
V_552 ) ;
F_100 ( V_2 ) ;
}
static void
F_143 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_289 ,
V_290 ) ;
F_326 ( V_2 , V_546 , L_100 ) ;
F_100 ( V_2 ) ;
}
void F_260 ( struct V_1 * V_2 ,
T_12 V_67 , int V_558 )
{
if ( F_21 ( V_559 , & V_2 -> V_46 ) )
return;
F_341 ( & V_2 -> V_65 , V_67 ) ;
F_342 ( V_2 -> V_421 , & V_2 -> V_65 ,
F_343 ( V_558 ) ) ;
}
static void
V_548 ( struct V_539 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_288 ;
if ( V_2 -> V_4 -> V_146 != V_147 ) {
V_288 = F_97 ( V_2 ,
V_289 ) ;
if ( V_2 -> V_544 ++ > V_287 )
F_266 ( V_2 , 0 ) ;
else if ( V_288 != V_290 )
F_260 ( V_2 , V_548 ,
V_445 ) ;
else
goto V_560;
F_326 ( V_2 , V_546 , L_101 ) ;
return;
}
V_560:
F_257 ( V_2 -> V_397 ) ;
if ( F_175 ( V_22 ) ) {
if ( F_173 ( V_2 , V_22 ) )
goto V_514;
F_125 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
V_2 -> V_526 = 0 ;
V_2 -> V_41 &= ~ V_527 ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
if ( V_2 -> V_435 == 0 )
F_231 ( V_2 ) ;
if ( ! F_320 ( V_2 ) )
F_260 ( V_2 , V_444 ,
V_445 ) ;
}
static int
F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_212 * V_213 = & V_4 -> V_213 ;
T_1 V_46 = 0 , V_561 ;
T_1 V_562 ;
int V_52 = 0 ;
if ( F_295 ( V_2 ) )
goto V_563;
if ( V_2 -> V_275 )
F_345 ( V_2 , 0 ) ;
V_46 = F_97 ( V_2 , V_298 ) ;
if ( V_46 == V_520 ) {
F_333 ( V_2 ) ;
V_2 -> V_275 = 1 ;
} else if ( V_46 == V_521 )
goto V_563;
V_561 = F_97 ( V_2 , V_564 ) ;
if ( V_561 != V_2 -> V_561 ) {
V_2 -> V_561 = V_561 ;
V_2 -> V_526 = 0 ;
if ( V_2 -> V_275 )
goto V_563;
if ( V_4 -> V_341 && V_565 )
F_210 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_526 < V_566 )
return 0 ;
V_2 -> V_41 |= V_527 ;
F_345 ( V_2 , 0 ) ;
if ( V_565 )
F_126 ( V_567 , & V_2 -> V_46 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_102 ) ;
V_562 = F_97 ( V_2 , V_549 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_103
L_104
L_105
L_106
L_107 ,
V_562 ,
F_97 ( V_2 , V_568 ) ,
F_118 ( V_2 , V_569 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_570 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_571 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_572 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_573 + 0x3c , & V_52 ) ) ;
if ( F_332 ( V_562 ) == 0x67 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_108
L_109 ) ;
V_563:
V_2 -> V_540 = ( V_46 == V_521 ) ? V_46 :
V_520 ;
if ( V_565 && ! F_45 ( V_64 ,
& V_2 -> V_46 ) ) {
F_260 ( V_2 , F_331 , 0 ) ;
F_326 ( V_2 , V_546 , L_110 ) ;
} else if ( ! V_565 && V_213 -> V_574 &&
V_2 -> V_41 & V_531 ) {
F_330 ( V_2 ) ;
}
return 1 ;
}
void V_444 ( struct V_539 * V_66 )
{
struct V_1 * V_2 = F_328 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
goto V_575;
if ( F_344 ( V_2 ) )
return;
if ( V_2 -> V_342 . V_343 )
F_346 ( V_2 ) ;
V_575:
F_260 ( V_2 , V_444 , V_445 ) ;
}
static int F_347 ( struct V_23 * V_5 )
{
struct V_23 * V_576 ;
int V_518 = V_5 -> V_577 ;
while ( V_518 -- > 0 ) {
V_576 = F_348 ( F_349
( V_5 -> V_578 ) , V_5 -> V_578 -> V_579 ,
F_350 ( F_351 ( V_5 -> V_577 ) , V_518 ) ) ;
if ( ! V_576 )
continue;
if ( V_576 -> V_580 != V_581 ) {
F_352 ( V_576 ) ;
return 0 ;
}
F_352 ( V_576 ) ;
}
return 1 ;
}
static int F_353 ( struct V_23 * V_5 )
{
int V_52 , V_582 ;
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_583 = V_584 ;
V_52 = F_235 ( V_5 ) ;
if ( V_52 )
return V_52 ;
F_238 ( V_5 ) ;
F_290 ( V_5 ) ;
V_582 = F_347 ( V_5 ) ;
if ( F_96 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_146 != V_180 && V_582 ) {
V_2 -> V_275 = 1 ;
F_123 ( V_528 , & V_2 -> V_46 ) ;
F_99 ( V_2 , V_298 ,
V_537 ) ;
F_326 ( V_2 , V_546 , L_85 ) ;
}
F_100 ( V_2 ) ;
V_52 = F_250 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_320 ( V_2 ) ;
F_7 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
V_52 = F_258 ( V_2 ) ;
if ( V_52 ) {
F_7 ( V_2 -> V_101 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 ) {
F_266 ( V_2 , 1 ) ;
F_126 ( V_559 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_52 ;
}
V_52 = F_173 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_514;
F_125 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
return V_52 ;
}
static T_13 F_354 ( struct V_23 * V_5 ,
T_14 V_46 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_585 )
return V_586 ;
if ( V_46 == V_584 )
return V_587 ;
F_123 ( V_559 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_65 ) ;
if ( F_175 ( V_22 ) )
F_189 ( V_2 , V_22 ) ;
F_200 ( V_2 ) ;
F_84 ( V_2 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_355 ( V_5 ) ;
F_270 ( V_5 ) ;
return V_588 ;
}
static T_13 F_356 ( struct V_23 * V_5 )
{
return F_353 ( V_5 ) ? V_586 :
V_587 ;
}
static void F_357 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_272 ( V_5 ) ;
F_358 ( V_5 ) ;
V_46 = F_97 ( V_2 , V_298 ) ;
if ( V_46 == V_299 && F_178 ( V_559 ,
& V_2 -> V_46 ) )
F_260 ( V_2 , V_444 ,
V_445 ) ;
}
static T_13 F_359 ( struct V_23 * V_5 ,
T_14 V_46 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_590 ) {
return V_414 -> V_590 ( V_5 , V_46 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_111 ) ;
return V_586 ;
}
}
static T_13 F_360 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_591 ) {
return V_414 -> V_591 ( V_5 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_112 ) ;
return V_586 ;
}
}
static void F_361 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_272 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_592 )
V_414 -> V_592 ( V_5 ) ;
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
V_2 -> V_275 = 0 ;
return V_52 ;
}
int F_363 ( struct V_1 * V_2 , T_15 V_83 ,
int V_84 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_593 = 0 ;
char V_594 [ 8 ] ;
int V_595 ;
if ( V_84 == V_88 ) {
V_593 = V_2 -> V_89 ;
V_595 = V_2 -> V_95 ;
strcpy ( V_594 , L_114 ) ;
} else if ( V_84 == V_90 ) {
V_593 = V_2 -> V_91 ;
V_595 = V_2 -> V_93 ;
strcpy ( V_594 , L_115 ) ;
}
if ( ! F_364 ( V_83 ) ) {
F_122 ( V_22 , L_116 ,
V_594 ) ;
return - V_40 ;
}
if ( F_57 ( V_2 ) && ( V_84 == V_90 ) &&
! F_73 ( V_2 ) ) {
F_122 ( V_22 , L_117 ) ;
return - V_40 ;
}
if ( V_83 > F_61 () ) {
F_122 ( V_22 ,
L_118 ,
V_594 , F_61 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_365 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_596 , V_597 ;
int V_52 ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
return - V_359 ;
V_596 = V_2 -> V_99 ;
V_597 = V_2 -> V_100 ;
F_22 ( V_22 ) ;
V_52 = F_213 ( V_2 , V_596 , V_597 ) ;
if ( V_52 )
goto V_514;
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
F_7 ( V_2 -> V_101 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( ( V_596 != V_2 -> V_93 ) ||
( V_597 != V_2 -> V_95 ) ) {
V_52 = F_213 ( V_2 ,
V_2 -> V_93 ,
V_2 -> V_95 ) ;
if ( V_52 )
goto V_514;
}
if ( F_65 ( V_2 ) ) {
F_276 ( V_2 , 1 ) ;
V_52 = F_367 ( V_2 ) ;
F_368 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_119 ) ;
goto V_514;
}
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 )
goto V_514;
V_52 = F_165 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_514;
F_125 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
return V_52 ;
}
static void
F_369 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_598 )
{
struct V_599 * V_600 ;
V_600 = F_370 ( V_30 ) ;
if ( ! V_600 )
return;
F_371 (indev) {
switch ( V_598 ) {
case V_360 :
F_372 ( V_2 ,
V_601 -> V_602 , V_603 ) ;
break;
case V_264 :
F_372 ( V_2 ,
V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
} F_373 ( V_600 ) ;
F_374 ( V_600 ) ;
}
void F_125 ( struct V_21 * V_22 , unsigned long V_598 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_51 ;
F_369 ( V_2 , V_22 , V_598 ) ;
F_375 () ;
F_376 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_377 ( V_22 , F_378 ( V_605 ) , V_51 ) ;
if ( ! V_30 )
continue;
F_369 ( V_2 , V_30 , V_598 ) ;
}
F_379 () ;
}
static int F_380 ( struct V_606 * V_607 ,
unsigned long V_598 , void * V_608 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_381 ( V_608 ) ;
V_609:
if ( V_30 == NULL )
goto V_514;
if ( V_30 -> V_395 & V_610 ) {
V_30 = F_382 ( V_30 ) ;
goto V_609;
}
if ( ! F_383 ( V_30 ) )
goto V_514;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_514;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_514;
F_369 ( V_2 , V_30 , V_598 ) ;
V_514:
return V_611 ;
}
static int
F_384 ( struct V_606 * V_607 ,
unsigned long V_598 , void * V_608 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_612 * V_601 = (struct V_612 * ) V_608 ;
V_30 = V_601 -> V_613 ? V_601 -> V_613 -> V_30 : NULL ;
V_609:
if ( V_30 == NULL )
goto V_514;
if ( V_30 -> V_395 & V_610 ) {
V_30 = F_382 ( V_30 ) ;
goto V_609;
}
if ( ! F_383 ( V_30 ) )
goto V_514;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_514;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_514;
switch ( V_598 ) {
case V_360 :
F_372 ( V_2 , V_601 -> V_602 , V_603 ) ;
break;
case V_264 :
F_372 ( V_2 , V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
V_514:
return V_611 ;
}
void F_125 ( struct V_21 * V_30 , unsigned long V_598 )
{ }
static int T_16 F_385 ( void )
{
int V_26 ;
F_386 ( V_481 L_120 , V_614 ) ;
#ifdef F_387
F_388 ( & V_615 ) ;
F_389 ( & V_616 ) ;
#endif
V_26 = F_390 ( & V_617 ) ;
if ( V_26 ) {
#ifdef F_387
F_391 ( & V_616 ) ;
F_392 ( & V_615 ) ;
#endif
}
return V_26 ;
}
static void T_17 F_393 ( void )
{
F_394 ( & V_617 ) ;
#ifdef F_387
F_391 ( & V_616 ) ;
F_392 ( & V_615 ) ;
#endif
}
