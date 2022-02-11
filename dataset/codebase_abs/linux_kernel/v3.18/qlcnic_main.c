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
struct V_21 * V_22 ,
struct V_21 * V_61 , int V_62 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( ! V_2 -> V_52 )
return F_43 ( V_58 , V_60 , V_22 , V_61 , V_62 ) ;
if ( ( V_2 -> V_41 & V_53 ) ||
F_29 ( V_2 ) )
V_62 = F_43 ( V_58 , V_60 , V_22 , V_61 , V_62 ) ;
return V_62 ;
}
static void F_44 ( struct V_1 * V_2 )
{
while ( F_45 ( V_63 , & V_2 -> V_46 ) )
F_46 ( 10000 , 11000 ) ;
if ( ! V_2 -> V_64 . V_65 . V_66 )
return;
F_47 ( & V_2 -> V_64 ) ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! ( V_2 -> V_41 & V_69 ) )
return - V_43 ;
V_68 -> V_70 = sizeof( V_4 -> V_71 ) ;
memcpy ( V_68 -> V_72 , V_4 -> V_71 , V_68 -> V_70 ) ;
return 0 ;
}
static void F_49 ( struct V_21 * V_22 ,
T_4 V_73 , T_5 V_74 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || V_4 -> V_75 )
return;
V_4 -> V_75 = F_51 ( V_74 ) ;
V_2 -> V_41 |= V_76 ;
}
static void F_52 ( struct V_21 * V_22 ,
T_4 V_73 , T_5 V_74 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_50 ( V_2 ) || ! V_4 -> V_75 ||
( V_4 -> V_75 != F_51 ( V_74 ) ) )
return;
V_2 -> V_41 |= V_77 ;
}
static bool F_53 ( struct V_57 * V_58 , struct V_21 * V_30 )
{
return F_54 ( V_58 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_56 ( V_2 ) &&
( V_4 -> V_78 [ 0 ] & V_79 ) ) {
F_45 ( V_80 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_57 ( struct V_1 * V_2 , T_2 V_81 ,
int V_82 )
{
int V_83 , V_84 = V_85 ;
if ( V_82 == V_86 )
V_84 = V_2 -> V_87 ;
else if ( V_82 == V_88 )
V_84 = V_2 -> V_89 ;
V_83 = F_58 ( F_59 ( int , F_60 () ,
V_84 ) ) ;
if ( V_81 > V_83 )
return V_83 ;
else
return V_81 ;
}
void F_61 ( struct V_1 * V_2 , T_2 V_90 )
{
if ( V_2 -> V_89 )
V_2 -> V_91 = F_57 ( V_2 , V_90 ,
V_88 ) ;
else
V_2 -> V_91 = V_90 ;
}
void F_62 ( struct V_1 * V_2 , T_2 V_92 )
{
if ( V_2 -> V_87 )
V_2 -> V_93 = F_57 ( V_2 , V_92 ,
V_86 ) ;
else
V_2 -> V_93 = V_92 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_94 = 0 , V_51 = 0 , V_95 ;
V_2 -> V_41 &= ~ V_96 ;
if ( V_2 -> V_97 > 0 )
V_94 += V_2 -> V_97 ;
else
V_94 += V_2 -> V_91 ;
if ( V_2 -> V_98 > 0 )
V_94 += V_2 -> V_98 ;
else
V_94 += V_2 -> V_93 ;
if ( F_64 ( V_2 ) )
V_94 += 1 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_65 ( V_94 ,
sizeof( struct V_100 ) ,
V_20 ) ;
if ( ! V_2 -> V_99 )
return - V_56 ;
}
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ )
V_2 -> V_99 [ V_95 ] . V_101 = V_95 ;
V_102:
V_51 = F_66 ( V_5 , V_2 -> V_99 , V_94 ) ;
if ( V_51 == - V_103 ) {
if ( ! V_2 -> V_97 && ! V_2 -> V_98 )
return V_51 ;
F_67 ( V_2 -> V_22 ,
L_3 ,
V_94 , V_51 ) ;
V_94 = V_2 -> V_91 + V_2 -> V_93 ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = 0 ;
if ( F_64 ( V_2 ) )
V_94 += 1 ;
F_67 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_91 , V_2 -> V_93 ,
V_94 ) ;
goto V_102;
} else if ( V_51 < 0 ) {
return V_51 ;
}
V_2 -> V_4 -> V_94 = V_94 ;
if ( V_2 -> V_97 > 0 )
V_2 -> V_91 = V_2 -> V_97 ;
if ( V_2 -> V_98 > 0 )
V_2 -> V_93 = V_2 -> V_98 ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , T_1 V_94 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 , V_95 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_65 ( V_94 ,
sizeof( struct V_100 ) ,
V_20 ) ;
if ( ! V_2 -> V_99 )
return - V_56 ;
}
V_2 -> V_41 &= ~ ( V_104 | V_105 ) ;
if ( V_2 -> V_4 -> V_106 ) {
V_107:
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ )
V_2 -> V_99 [ V_95 ] . V_101 = V_95 ;
V_51 = F_69 ( V_5 ,
V_2 -> V_99 , 1 , V_94 ) ;
if ( V_51 == V_94 ) {
V_2 -> V_41 |= V_105 ;
V_2 -> V_4 -> V_94 = V_94 ;
F_70 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_51 > 0 ) {
F_71 ( V_5 ) ;
F_70 ( & V_5 -> V_30 ,
L_3 ,
V_94 , V_51 ) ;
if ( F_56 ( V_2 ) ) {
V_94 = F_58 ( V_51 ) ;
if ( V_51 < V_108 )
return - V_103 ;
} else {
V_94 = F_58 ( V_51 - 1 ) ;
V_94 += 1 ;
if ( V_51 < V_109 )
return - V_103 ;
}
if ( F_56 ( V_2 ) &&
! F_72 ( V_2 ) ) {
V_2 -> V_93 = V_94 ;
V_2 -> V_91 = V_110 ;
} else {
V_2 -> V_91 = V_94 / 2 ;
V_2 -> V_93 = V_2 -> V_91 ;
}
if ( V_94 ) {
F_70 ( & V_5 -> V_30 ,
L_6 ,
V_94 ) ;
goto V_107;
}
} else {
F_70 ( & V_5 -> V_30 ,
L_7 ,
V_94 , V_51 ) ;
return V_51 ;
}
}
return - V_111 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = V_2 -> V_93 ;
if ( F_72 ( V_2 ) )
V_94 += V_2 -> V_91 ;
else
V_94 += V_110 ;
return V_94 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_112 , V_113 ;
const struct V_114 * V_115 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_116 && ! F_75 ( V_5 ) ) {
V_2 -> V_41 |= V_104 ;
V_112 = V_117 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_118 = F_76 ( V_2 -> V_4 ,
V_112 ) ;
F_70 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_99 [ 0 ] . V_95 = V_5 -> V_119 ;
return V_51 ;
}
if ( V_116 || V_120 )
return - V_43 ;
V_115 = & V_121 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_122 = V_115 -> V_122 ;
V_112 = V_115 -> V_118 ;
V_2 -> V_118 = F_76 ( V_4 , V_112 ) ;
V_113 = V_115 -> V_123 ;
V_2 -> V_123 = F_76 ( V_4 , V_113 ) ;
V_2 -> V_124 = F_76 ( V_4 , V_125 ) ;
V_2 -> V_126 = F_76 ( V_4 , V_127 ) ;
F_70 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_99 [ 0 ] . V_95 = V_5 -> V_119 ;
return V_51 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_94 , V_51 = 0 ;
if ( V_2 -> V_41 & V_96 ) {
V_51 = F_63 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_94 = V_2 -> V_4 -> V_94 ;
} else {
V_94 = F_73 ( V_2 ) ;
V_51 = F_68 ( V_2 , V_94 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_105 ) ) {
F_78 ( V_2 ) ;
V_2 -> V_93 = V_110 ;
V_51 = F_74 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , int V_128 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_129 ;
if ( F_72 ( V_2 ) &&
! V_4 -> V_130 &&
( V_2 -> V_41 & V_105 ) ) {
V_4 -> V_131 = F_80 ( V_4 -> V_94 *
sizeof( struct V_132 ) ) ;
if ( ! V_4 -> V_131 )
return - V_56 ;
for ( V_129 = 0 ; V_129 < V_4 -> V_94 ; V_129 ++ ) {
V_4 -> V_131 [ V_129 ] . type = V_133 ;
V_4 -> V_131 [ V_129 ] . V_72 = V_129 ;
V_4 -> V_131 [ V_129 ] . V_134 = 0 ;
}
V_51 = F_81 ( V_2 , 1 ) ;
if ( V_51 )
F_82 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_94 ) ;
return V_51 ;
}
return 0 ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_105 )
F_71 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_104 )
F_84 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
if ( V_2 -> V_4 -> V_131 ) {
F_85 ( V_2 -> V_4 -> V_131 ) ;
V_2 -> V_4 -> V_131 = NULL ;
}
}
static void F_86 ( struct V_3 * V_4 )
{
if ( V_4 -> V_135 != NULL )
F_87 ( V_4 -> V_135 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 * V_137 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
switch ( V_4 -> V_138 ) {
case V_139 :
V_4 -> V_140 = V_141 ;
break;
case V_142 :
V_4 -> V_140 = V_143 ;
break;
}
return 0 ;
}
if ( V_4 -> V_144 == V_145 )
return 0 ;
V_137 = F_65 ( V_4 -> V_146 , sizeof( * V_137 ) , V_20 ) ;
if ( ! V_137 )
return - V_56 ;
V_26 = F_89 ( V_2 , V_137 ) ;
F_7 ( V_137 ) ;
return V_26 ;
}
static bool F_90 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_91 ( V_2 ) ) {
V_26 = true ;
} else if ( F_64 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_78 [ 0 ] &
V_147 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 * V_137 ;
int V_129 , V_72 = 0 , V_26 = 0 , V_148 = 0 ;
T_3 V_149 ;
T_2 V_150 ;
V_137 = F_65 ( V_4 -> V_146 , sizeof( * V_137 ) , V_20 ) ;
if ( ! V_137 )
return - V_56 ;
V_26 = F_89 ( V_2 , V_137 ) ;
if ( V_26 )
goto V_151;
V_149 = V_4 -> V_140 ;
V_2 -> V_152 = F_5 ( sizeof( struct V_153 ) *
V_149 , V_20 ) ;
if ( ! V_2 -> V_152 ) {
V_26 = - V_56 ;
goto V_151;
}
V_2 -> V_154 = F_5 ( sizeof( struct V_155 ) *
V_143 , V_20 ) ;
if ( ! V_2 -> V_154 ) {
V_26 = - V_56 ;
goto V_156;
}
for ( V_129 = 0 ; V_129 < V_4 -> V_146 ; V_129 ++ ) {
V_150 = V_137 [ V_129 ] . V_72 ;
if ( V_150 >= V_4 -> V_146 ) {
V_26 = V_157 ;
F_82 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_54 , V_150 , V_4 -> V_146 ) ;
goto V_158;
}
if ( ! V_137 [ V_129 ] . V_159 ||
( V_137 [ V_129 ] . type != V_160 ) )
continue;
if ( F_90 ( V_2 ) ) {
if ( ! F_93 ( V_2 , V_150 ,
& V_72 ) )
V_2 -> V_152 [ V_148 ] . V_161 = true ;
else
continue;
} else {
V_2 -> V_152 [ V_148 ] . V_161 = true ;
}
V_2 -> V_152 [ V_148 ] . V_27 = V_150 ;
V_2 -> V_152 [ V_148 ] . V_159 = ( T_2 ) V_137 [ V_129 ] . V_159 ;
V_2 -> V_152 [ V_148 ] . type = ( T_2 ) V_137 [ V_129 ] . type ;
V_2 -> V_152 [ V_148 ] . V_162 = ( T_2 ) V_137 [ V_129 ] . V_163 ;
V_2 -> V_152 [ V_148 ] . V_164 = V_137 [ V_129 ] . V_165 ;
V_2 -> V_152 [ V_148 ] . V_166 = V_137 [ V_129 ] . V_167 ;
memcpy ( & V_2 -> V_152 [ V_148 ] . V_168 , & V_137 [ V_129 ] . V_168 , V_25 ) ;
V_148 ++ ;
}
if ( ! F_90 ( V_2 ) ) {
for ( V_129 = 0 ; V_129 < V_143 ; V_129 ++ )
V_2 -> V_154 [ V_129 ] . V_41 |= V_169 ;
}
F_7 ( V_137 ) ;
return 0 ;
V_158:
F_7 ( V_2 -> V_154 ) ;
V_2 -> V_154 = NULL ;
V_156:
F_7 ( V_2 -> V_152 ) ;
V_2 -> V_152 = NULL ;
V_151:
F_7 ( V_137 ) ;
return V_26 ;
}
static int
F_94 ( struct V_1 * V_2 )
{
T_2 V_72 ;
int V_26 ;
T_1 V_170 = V_145 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_95 ( V_2 ) ;
if ( V_26 )
goto V_171;
V_72 = V_4 -> V_27 ;
V_170 = F_96 ( V_2 , V_172 ) ;
V_170 = ( V_170 & ~ F_97 ( 0xf , V_72 ) ) |
F_97 ( V_145 , V_72 ) ;
F_98 ( V_2 , V_172 , V_170 ) ;
F_99 ( V_2 ) ;
V_171:
return V_26 ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_173 * V_174 )
{
T_1 V_144 , V_175 ;
V_2 -> V_4 -> V_176 = F_96 ( V_2 ,
V_177 ) ;
F_101 ( V_2 ) ;
V_144 = F_96 ( V_2 , V_172 ) ;
if ( V_144 == V_178 )
V_175 = V_145 ;
else
V_175 = F_102 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_175 == V_179 ) {
V_2 -> V_4 -> V_144 = V_179 ;
F_70 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_176 ) ;
V_2 -> V_180 = & V_181 ;
} else
V_2 -> V_180 = & V_182 ;
}
static void F_103 ( T_1 V_183 , T_6 * V_184 )
{
switch ( V_183 ) {
case V_7 :
* V_184 = V_185 ;
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
* V_184 = V_191 ;
break;
default:
* V_184 = 0 ;
}
}
static int F_104 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_112 ;
void T_7 * V_192 = NULL ;
unsigned long V_193 , V_194 = 0 , V_195 ;
V_193 = F_105 ( V_5 , 0 ) ;
F_103 ( V_5 -> V_6 , & V_195 ) ;
if ( V_193 >= V_195 ) {
V_192 = F_106 ( V_5 , 0 ) ;
if ( V_192 == NULL ) {
F_82 ( & V_5 -> V_30 , L_13 ) ;
return - V_111 ;
}
V_194 = V_193 ;
} else {
return - V_111 ;
}
F_70 ( & V_5 -> V_30 , L_14 , ( int ) ( V_193 >> 10 ) ) ;
V_4 -> V_135 = V_192 ;
V_4 -> V_194 = V_194 ;
V_112 = F_107 ( F_108 ( V_4 -> V_27 ) ) ;
F_76 ( V_4 , V_112 ) ;
return 0 ;
}
static bool F_109 ( struct V_1 * V_2 ,
int V_196 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_197 ;
bool V_26 = true ;
V_197 = V_5 -> V_197 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_186 ) {
if ( V_198 [ V_196 ] . V_199 == V_197 &&
V_198 [ V_196 ] . V_200 == V_5 -> V_201 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_110 ( struct V_1 * V_2 , char * V_202 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_129 , V_203 = 0 ;
for ( V_129 = 0 ; V_129 < V_204 ; ++ V_129 ) {
if ( V_198 [ V_129 ] . V_205 == V_5 -> V_205 &&
V_198 [ V_129 ] . V_6 == V_5 -> V_6 &&
F_109 ( V_2 , V_129 ) ) {
V_203 = 1 ;
break;
}
}
if ( ! V_203 )
sprintf ( V_202 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_202 , L_16 , V_2 -> V_24 ,
V_198 [ V_129 ] . V_206 ) ;
}
static void
F_111 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_207 , V_208 , V_209 , V_210 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_211 * V_212 = & V_4 -> V_212 ;
V_210 = V_2 -> V_213 ;
V_207 = F_96 ( V_2 , V_214 ) ;
V_208 = F_96 ( V_2 , V_215 ) ;
V_209 = F_96 ( V_2 , V_216 ) ;
V_2 -> V_213 = F_112 ( V_207 , V_208 , V_209 ) ;
V_51 = F_113 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_144 != V_179 ) {
if ( V_212 -> V_217 == NULL ||
V_2 -> V_213 > V_210 ) {
if ( V_212 -> V_217 )
F_85 ( V_212 -> V_217 ) ;
if ( ! F_114 ( V_2 ) )
F_70 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_70 ( & V_5 -> V_30 , L_19 ,
V_218 , V_207 , V_208 , V_209 ) ;
if ( V_2 -> V_4 -> V_138 == V_142 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_219 = V_220 ;
V_2 -> V_221 = V_222 ;
} else {
V_2 -> V_219 = V_223 ;
V_2 -> V_221 = V_224 ;
}
V_2 -> V_225 = V_226 ;
V_2 -> V_227 = V_226 ;
} else if ( V_2 -> V_4 -> V_138 == V_139 ) {
V_2 -> V_219 = V_228 ;
V_2 -> V_225 = V_229 ;
V_2 -> V_227 = V_229 ;
V_2 -> V_221 = V_230 ;
}
V_2 -> V_4 -> V_106 = ! ! V_120 ;
V_2 -> V_231 = V_232 ;
V_2 -> V_233 = V_234 ;
}
static int
F_115 ( struct V_1 * V_2 )
{
struct V_235 V_236 ;
int V_51 = 0 ;
memset ( & V_236 , 0 , sizeof( struct V_235 ) ) ;
V_51 = F_116 ( V_2 , & V_236 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_237 = ( T_2 ) V_236 . V_238 ;
V_2 -> V_4 -> V_239 = V_236 . V_239 ;
V_2 -> V_4 -> V_240 = V_236 . V_240 ;
V_2 -> V_4 -> V_241 = V_236 . V_241 ;
V_2 -> V_4 -> V_8 = V_236 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_242 ) {
T_1 V_243 ;
V_243 = F_117 ( V_2 , V_244 , & V_51 ) ;
if ( V_51 == - V_111 )
return V_51 ;
V_2 -> V_4 -> V_78 [ 0 ] = V_243 ;
} else {
V_2 -> V_4 -> V_78 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_245 = V_236 . V_245 ;
V_2 -> V_4 -> V_246 = V_236 . V_246 ;
if ( V_2 -> V_4 -> V_8 & V_247 ) {
V_2 -> V_41 |= V_53 ;
V_2 -> V_4 -> V_248 = V_249 ;
V_2 -> V_89 = V_250 ;
V_2 -> V_87 = V_251 ;
F_70 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_248 = V_252 ;
V_2 -> V_89 = V_253 ;
V_2 -> V_87 = V_85 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
if ( V_255 -> V_256 )
V_2 -> V_41 &= ~ V_257 ;
else
V_2 -> V_41 |= V_257 ;
if ( V_255 -> V_258 ) {
V_2 -> V_259 = V_255 -> V_258 ;
V_2 -> V_260 = V_255 -> V_258 ;
} else {
V_2 -> V_259 = 0 ;
V_2 -> V_260 = 0 ;
}
}
static int
F_119 ( struct V_21 * V_22 , T_5 V_261 , T_3 V_262 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_120 ( V_2 , V_262 , 1 ) ;
if ( V_51 ) {
F_121 ( V_22 ,
L_21 ,
V_262 , V_51 ) ;
return V_51 ;
}
}
F_122 ( V_262 , V_2 -> V_263 ) ;
return 0 ;
}
static int
F_123 ( struct V_21 * V_22 , T_5 V_261 , T_3 V_262 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_120 ( V_2 , V_262 , 0 ) ;
if ( V_51 ) {
F_121 ( V_22 ,
L_22 ,
V_262 , V_51 ) ;
return V_51 ;
}
}
F_124 ( V_22 , V_264 ) ;
F_125 ( V_262 , V_2 -> V_263 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
V_2 -> V_41 &= ~ ( V_265 | V_42 |
V_266 ) ;
if ( V_255 -> V_267 )
V_2 -> V_41 |= V_265 ;
if ( ! V_255 -> V_268 )
V_2 -> V_41 |= V_42 ;
if ( ! V_255 -> V_269 )
V_2 -> V_41 |= V_266 ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_254 V_255 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_255 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_128 ( V_2 , & V_255 ) )
return - V_111 ;
F_118 ( V_2 , & V_255 ) ;
F_126 ( V_2 , & V_255 ) ;
F_129 ( V_2 , & V_255 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_64 ( V_2 ) )
return;
V_2 -> V_270 = V_255 -> V_270 ;
V_2 -> V_41 |= V_271 ;
F_130 ( V_22 ) ;
V_2 -> V_41 &= ~ V_271 ;
}
static int
F_131 ( struct V_1 * V_2 )
{
T_1 V_144 , V_175 ;
int V_51 = 0 ;
V_51 = F_115 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_272 )
return 0 ;
V_144 = F_96 ( V_2 , V_172 ) ;
V_175 = F_102 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_144 == V_178 )
V_175 = V_145 ;
else
V_175 = F_102 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_175 == V_145 ) {
V_2 -> V_4 -> V_144 = V_145 ;
V_51 = F_92 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_94 ( V_2 ) ;
F_70 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_176 ) ;
} else if ( V_175 == V_273 ) {
V_2 -> V_4 -> V_144 = V_273 ;
F_70 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_176 ) ;
}
} else {
V_2 -> V_4 -> V_248 = V_252 ;
}
V_2 -> V_41 |= V_272 ;
return V_51 ;
}
int F_132 ( struct V_1 * V_2 )
{
struct V_254 V_255 ;
struct V_153 * V_274 ;
T_2 V_129 ;
if ( V_2 -> V_275 )
return 0 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_4 -> V_140 ; V_129 ++ ) {
if ( ! V_2 -> V_152 [ V_129 ] . V_161 )
continue;
memset ( & V_255 , 0 , sizeof( struct V_254 ) ) ;
V_255 . V_27 = V_2 -> V_152 [ V_129 ] . V_27 ;
V_255 . V_268 = V_276 ;
V_255 . V_269 = V_276 ;
if ( F_56 ( V_2 ) ) {
V_255 . V_270 = V_276 ;
if ( F_133 ( V_2 ) )
V_255 . V_270 |= ( V_277 | V_278 ) ;
}
if ( F_134 ( V_2 , & V_255 ) )
return - V_111 ;
V_274 = & V_2 -> V_152 [ V_129 ] ;
V_274 -> V_279 = V_255 . V_258 ;
V_274 -> V_268 = V_255 . V_268 ;
V_274 -> V_267 = V_255 . V_267 ;
V_274 -> V_256 = V_255 . V_256 ;
V_274 -> V_269 = V_255 . V_269 ;
V_274 -> V_270 = V_255 . V_270 ;
}
return 0 ;
}
static int
F_135 ( struct V_1 * V_2 ,
struct V_153 * V_274 , int V_27 )
{
struct V_254 V_255 ;
V_255 . V_144 = V_280 ;
V_255 . V_27 = V_27 ;
V_255 . V_258 = V_274 -> V_279 ;
V_255 . V_268 = V_274 -> V_268 ;
V_255 . V_256 = V_274 -> V_256 ;
V_255 . V_267 = V_274 -> V_267 ;
V_255 . V_270 = V_274 -> V_270 ;
V_255 . V_269 = V_274 -> V_269 ;
if ( F_134 ( V_2 , & V_255 ) )
return - V_111 ;
V_255 . V_144 = V_281 ;
if ( F_134 ( V_2 , & V_255 ) )
return - V_111 ;
return 0 ;
}
int F_136 ( struct V_1 * V_2 )
{
int V_129 , V_51 ;
struct V_153 * V_274 ;
struct V_235 V_236 ;
T_2 V_27 ;
if ( F_56 ( V_2 ) )
if ( ! V_2 -> V_275 )
return 0 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_4 -> V_140 ; V_129 ++ ) {
V_274 = & V_2 -> V_152 [ V_129 ] ;
V_27 = V_274 -> V_27 ;
if ( ! V_2 -> V_152 [ V_129 ] . V_161 )
continue;
memset ( & V_236 , 0 , sizeof( struct V_235 ) ) ;
V_51 = F_116 ( V_2 , & V_236 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_236 . V_282 = V_274 -> V_164 ;
V_236 . V_283 = V_274 -> V_166 ;
V_51 = F_137 ( V_2 , & V_236 ) ;
if ( V_51 )
return V_51 ;
if ( V_274 -> V_284 ) {
V_51 = F_138 ( V_2 ,
V_274 -> V_285 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_135 ( V_2 , V_274 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
T_2 V_286 = V_287 ;
T_1 V_288 ;
if ( V_2 -> V_4 -> V_144 == V_145 )
return 0 ;
V_288 = F_96 ( V_2 ,
V_289 ) ;
while ( V_288 != V_290 && -- V_286 ) {
F_140 ( 1000 ) ;
V_288 = F_96 ( V_2 ,
V_289 ) ;
}
if ( ! V_286 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_111 ;
}
return 0 ;
}
static int
F_141 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_144 != V_145 )
return 0 ;
V_51 = F_132 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_136 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_142 ( V_2 ) ;
return V_51 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_144 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_291;
if ( V_292 )
F_145 ( V_2 ) ;
else {
V_51 = F_146 ( V_2 ) ;
if ( V_51 )
goto V_293;
V_2 -> V_4 -> V_294 = V_295 ;
}
V_51 = F_147 ( V_2 ) ;
if ( V_51 == 0 )
goto V_291;
V_51 = F_148 ( V_2 ) ;
if ( V_51 )
goto V_293;
V_51 = F_149 ( V_2 ) ;
if ( V_51 )
goto V_293;
F_150 ( V_2 ) ;
F_151 ( V_2 , V_296 , V_297 ) ;
V_291:
V_51 = F_152 ( V_2 ) ;
if ( V_51 )
goto V_293;
F_98 ( V_2 , V_298 , V_299 ) ;
F_153 ( V_2 , 1 ) ;
V_51 = F_131 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_293;
}
V_51 = F_141 ( V_2 ) ;
if ( V_51 )
goto V_293;
F_111 ( V_2 ) ;
V_2 -> V_275 = 0 ;
F_150 ( V_2 ) ;
return 0 ;
V_293:
F_98 ( V_2 , V_298 , V_300 ) ;
F_82 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_150 ( V_2 ) ;
return V_51 ;
}
static int
F_154 ( struct V_1 * V_2 )
{
T_8 V_301 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
int V_51 , V_303 , V_304 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_130 == V_305 ) {
if ( F_56 ( V_2 ) )
V_301 = V_306 ;
else
V_301 = V_307 ;
if ( ! F_155 ( V_2 ) )
V_41 |= V_308 ;
} else {
if ( V_2 -> V_41 & V_105 )
V_301 = V_309 ;
else if ( V_2 -> V_41 & V_104 )
V_301 = V_310 ;
else {
V_41 |= V_308 ;
if ( F_56 ( V_2 ) )
V_301 = V_311 ;
else
V_301 = V_312 ;
}
}
V_2 -> V_119 = V_22 -> V_119 ;
if ( V_2 -> V_4 -> V_130 != V_313 ) {
if ( F_56 ( V_2 ) ||
( F_64 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) ) ) {
V_304 = V_2 -> V_93 ;
for ( V_303 = 0 ; V_303 < V_304 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
if ( F_56 ( V_2 ) &&
! F_72 ( V_2 ) &&
( V_303 == ( V_304 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_105 ) )
snprintf ( V_302 -> V_202 ,
sizeof( V_302 -> V_202 ) ,
L_28 ) ;
else
snprintf ( V_302 -> V_202 ,
sizeof( V_302 -> V_202 ) ,
L_29 ,
V_22 -> V_202 , V_303 ) ;
} else {
snprintf ( V_302 -> V_202 ,
sizeof( V_302 -> V_202 ) ,
L_30 ,
V_22 -> V_202 , V_303 ) ;
}
V_51 = F_156 ( V_302 -> V_119 , V_301 , V_41 ,
V_302 -> V_202 , V_302 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_56 ( V_2 ) &&
F_72 ( V_2 ) ) ||
( F_64 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) &&
! ( V_2 -> V_41 & V_314 ) ) ) {
V_301 = V_315 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ;
V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
snprintf ( V_11 -> V_202 , sizeof( V_11 -> V_202 ) ,
L_31 , V_22 -> V_202 , V_303 ) ;
V_51 = F_156 ( V_11 -> V_119 , V_301 , V_41 ,
V_11 -> V_202 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_157 ( struct V_1 * V_2 )
{
int V_303 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_130 != V_313 ) {
if ( F_56 ( V_2 ) ||
( F_64 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
F_158 ( V_302 -> V_119 , V_302 ) ;
}
}
if ( ( F_64 ( V_2 ) &&
! ( V_2 -> V_41 & V_314 ) ) ||
( F_56 ( V_2 ) &&
F_72 ( V_2 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ;
V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( V_11 -> V_119 )
F_158 ( V_11 -> V_119 , V_11 ) ;
}
}
}
}
static void F_159 ( struct V_1 * V_2 )
{
T_1 V_316 = 0 ;
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_78 [ 0 ] &
V_317 )
V_2 -> V_41 |= V_318 ;
} else {
V_316 = V_2 -> V_4 -> V_8 ;
if ( F_160 ( V_316 ) )
V_2 -> V_41 |= V_318 ;
}
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 ;
V_4 -> V_319 . V_320 = V_321 ;
if ( F_64 ( V_2 ) ) {
V_4 -> V_319 . type = V_322 ;
V_4 -> V_319 . V_323 = V_324 ;
V_4 -> V_319 . V_325 = V_326 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
V_51 = F_162 ( V_2 ) ;
} else {
V_4 -> V_319 . type = V_331 ;
V_4 -> V_319 . V_327 = V_328 ;
V_4 -> V_319 . V_329 = V_330 ;
V_51 = F_163 ( V_2 ) ;
}
return V_51 ;
}
int F_164 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_303 ;
struct V_332 * V_333 ;
if ( V_2 -> V_334 != V_335 )
return - V_111 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_127 ( V_2 ) )
return - V_111 ;
F_159 ( V_2 ) ;
if ( F_165 ( V_2 ) )
return - V_111 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_233 ; V_303 ++ ) {
V_333 = & V_2 -> V_15 -> V_336 [ V_303 ] ;
F_166 ( V_2 , V_333 , V_303 ) ;
}
F_24 ( V_22 ) ;
F_167 ( V_2 , V_22 -> V_337 ) ;
V_2 -> V_4 -> V_338 = 0 ;
if ( V_2 -> V_93 > 1 )
F_168 ( V_2 , 1 ) ;
F_161 ( V_2 ) ;
if ( V_22 -> V_339 & V_340 )
F_169 ( V_2 , V_341 ) ;
F_122 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_170 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_342 = 0 ;
F_171 ( V_22 ) ;
return 0 ;
}
int F_172 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_173 () ;
if ( F_174 ( V_22 ) )
V_51 = F_164 ( V_2 , V_22 ) ;
F_175 () ;
return V_51 ;
}
void F_176 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_303 ;
if ( V_2 -> V_334 != V_335 )
return;
if ( ! F_177 ( V_45 , & V_2 -> V_46 ) )
return;
F_178 () ;
F_179 ( V_22 ) ;
V_2 -> V_4 -> V_338 = 0 ;
F_180 ( V_22 ) ;
F_181 ( V_2 ) ;
if ( V_2 -> V_343 . V_344 )
F_182 ( V_2 ) ;
F_183 ( V_2 , V_345 ) ;
if ( F_20 ( V_2 ) )
F_184 ( & V_2 -> V_4 -> V_346 -> V_347 ) ;
F_23 ( V_2 ) ;
F_185 ( V_2 ) ;
V_2 -> V_41 &= ~ V_318 ;
F_186 ( V_2 ) ;
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ )
F_187 ( V_2 , & V_2 -> V_11 [ V_303 ] ) ;
}
void F_188 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_173 () ;
if ( F_174 ( V_22 ) )
F_176 ( V_2 , V_22 ) ;
F_175 () ;
}
int
F_189 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_334 == V_335 )
return 0 ;
V_51 = F_190 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_191 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_32 ) ;
goto V_348;
}
V_51 = F_192 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_33 ) ;
goto V_349;
}
V_51 = F_154 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_34 ) ;
goto V_350;
}
F_193 ( V_2 ) ;
#ifdef F_194
if ( F_50 ( V_2 ) )
F_195 ( V_22 ) ;
#endif
V_2 -> V_334 = V_335 ;
return 0 ;
V_350:
F_196 ( V_2 ) ;
V_349:
F_197 ( V_2 ) ;
V_348:
F_198 ( V_2 ) ;
return V_51 ;
}
void F_199 ( struct V_1 * V_2 )
{
if ( V_2 -> V_334 != V_335 )
return;
F_200 ( V_2 ) ;
F_196 ( V_2 ) ;
F_201 ( V_2 ) ;
F_157 ( V_2 ) ;
F_198 ( V_2 ) ;
F_197 ( V_2 ) ;
V_2 -> V_334 = 0 ;
}
void F_202 ( struct V_21 * V_22 , int V_93 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
int V_91 = V_2 -> V_91 ;
int V_303 ;
F_125 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_130 == V_305 ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_302 = & V_2 -> V_15 -> V_19 [ V_303 ] ;
F_203 ( V_2 , V_302 ) ;
}
}
F_185 ( V_2 ) ;
F_199 ( V_2 ) ;
V_2 -> V_4 -> V_130 = 0 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_91 = V_91 ;
if ( F_189 ( V_2 ) )
goto V_351;
if ( F_174 ( V_22 ) )
F_164 ( V_2 , V_22 ) ;
V_351:
F_25 ( V_22 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_293;
}
if ( F_64 ( V_2 ) ) {
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
memset ( & V_2 -> V_352 , 0 , sizeof( V_2 -> V_352 ) ) ;
V_293:
return V_51 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_211 * V_212 = & V_2 -> V_4 -> V_212 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_212 -> V_217 ) {
F_85 ( V_212 -> V_217 ) ;
V_212 -> V_217 = NULL ;
}
if ( V_212 -> V_353 ) {
F_206 ( & V_2 -> V_5 -> V_30 , V_354 ,
V_212 -> V_353 , V_212 -> V_355 ) ;
V_212 -> V_353 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_356 . V_357 ) ;
V_2 -> V_4 -> V_212 . V_217 = NULL ;
}
int F_207 ( struct V_21 * V_22 , int V_358 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
struct V_332 * V_333 ;
int V_303 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_174 ( V_22 ) )
F_176 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
V_2 -> V_93 = V_110 ;
V_2 -> V_4 -> V_130 = V_358 ;
V_2 -> V_4 -> V_338 = 0 ;
V_26 = F_189 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_165 ( V_2 ) ;
if ( V_26 ) {
F_199 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_233 ; V_303 ++ ) {
V_333 = & V_2 -> V_15 -> V_336 [ V_303 ] ;
F_166 ( V_2 , V_333 , V_303 ) ;
}
if ( V_2 -> V_4 -> V_130 == V_305 ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_302 = & V_2 -> V_15 -> V_19 [ V_303 ] ;
F_208 ( V_2 , V_302 ) ;
}
}
if ( V_2 -> V_4 -> V_130 == V_313 ) {
V_2 -> V_4 -> V_359 = 0 ;
F_170 ( V_2 , 1 ) ;
}
F_122 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_209 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_63 , & V_2 -> V_46 ) )
return - V_360 ;
F_22 ( V_22 ) ;
F_188 ( V_2 , V_22 ) ;
F_172 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
F_67 ( V_2 -> V_22 , L_35 , V_54 ) ;
return 0 ;
}
int
F_210 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_63 , & V_2 -> V_46 ) )
return - V_360 ;
if ( V_2 -> V_334 == V_335 ) {
F_22 ( V_22 ) ;
if ( F_174 ( V_22 ) )
F_176 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
if ( F_174 ( V_22 ) ) {
V_51 = F_189 ( V_2 ) ;
if ( ! V_51 ) {
F_164 ( V_2 , V_22 ) ;
F_124 ( V_22 , V_361 ) ;
}
}
F_25 ( V_22 ) ;
}
F_125 ( V_63 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_362 = V_4 -> V_140 ;
T_3 V_16 ;
V_4 -> V_363 = V_364 ;
if ( V_362 <= 2 )
V_16 = ( V_365 - V_364 ) /
V_362 ;
else
V_16 = ( V_366 - V_364 ) /
V_362 ;
V_4 -> V_55 = V_16 ;
}
static int F_212 ( struct V_1 * V_2 ,
T_2 V_367 , T_2 V_368 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 = 0 ;
if ( V_367 ) {
V_51 = F_213 ( V_22 , V_367 ) ;
if ( V_51 ) {
F_121 ( V_22 , L_36 ,
V_367 ) ;
return V_51 ;
}
}
if ( V_368 ) {
V_51 = F_214 ( V_22 , V_368 ) ;
if ( V_51 )
F_121 ( V_22 , L_37 ,
V_368 ) ;
}
return V_51 ;
}
int
F_215 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_369 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_370 = 1 ;
V_2 -> V_4 -> V_371 = 0 ;
F_216 ( V_2 ) ;
V_22 -> V_372 = & V_373 ;
V_22 -> V_374 = V_375 * V_376 ;
F_217 ( V_22 , V_22 -> V_337 ) ;
V_22 -> V_377 = ( F_20 ( V_2 ) ) ?
& V_378 : & V_379 ;
V_22 -> V_339 |= ( V_380 | V_381 | V_382 |
V_383 | V_384 |
V_385 ) ;
V_22 -> V_386 |= ( V_380 | V_381 |
V_383 ) ;
if ( F_133 ( V_2 ) ) {
V_22 -> V_339 |= ( V_387 | V_388 ) ;
V_22 -> V_386 |= ( V_387 | V_388 ) ;
}
if ( V_369 ) {
V_22 -> V_339 |= V_389 ;
V_22 -> V_386 |= V_389 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_339 |= ( V_390 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_339 |= V_391 ;
if ( V_2 -> V_4 -> V_8 & V_392 )
V_22 -> V_339 |= V_340 ;
if ( F_218 ( V_2 ) ) {
V_22 -> V_339 |= V_393 ;
V_22 -> V_394 = V_381 |
V_393 |
V_387 |
V_388 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_394 |= V_382 ;
V_22 -> V_395 = V_22 -> V_339 ;
V_22 -> V_396 |= V_397 ;
V_22 -> V_119 = V_2 -> V_99 [ 0 ] . V_95 ;
V_51 = F_212 ( V_2 , V_2 -> V_91 ,
V_2 -> V_93 ) ;
if ( V_51 )
return V_51 ;
F_219 ( V_2 -> V_398 ) ;
V_51 = F_220 ( V_22 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_38 ) ;
return V_51 ;
}
return 0 ;
}
static int F_221 ( struct V_23 * V_5 , int * V_369 )
{
if ( ! F_222 ( V_5 , F_223 ( 64 ) ) &&
! F_224 ( V_5 , F_223 ( 64 ) ) )
* V_369 = 1 ;
else if ( ! F_222 ( V_5 , F_223 ( 32 ) ) &&
! F_224 ( V_5 , F_223 ( 32 ) ) )
* V_369 = 0 ;
else {
F_82 ( & V_5 -> V_30 , L_39 ) ;
return - V_111 ;
}
return 0 ;
}
void F_225 ( struct V_1 * V_2 )
{
int V_303 ;
struct V_10 * V_11 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( V_11 && V_11 -> V_399 != NULL ) {
F_85 ( V_11 -> V_399 ) ;
V_11 -> V_399 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_226 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_303 , V_95 , V_196 ;
struct V_10 * V_11 ;
struct V_400 * V_399 ;
V_11 = F_65 ( V_2 -> V_91 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
V_11 -> V_401 = V_2 -> V_231 ;
V_11 -> V_402 = F_227 ( V_22 , V_303 ) ;
V_399 = F_80 ( F_228 ( V_11 ) ) ;
if ( V_399 == NULL ) {
F_225 ( V_2 ) ;
return - V_56 ;
}
memset ( V_399 , 0 , F_228 ( V_11 ) ) ;
V_11 -> V_399 = V_399 ;
F_229 ( & V_11 -> V_403 ) ;
}
if ( F_64 ( V_2 ) ||
( F_56 ( V_2 ) && F_72 ( V_2 ) ) ) {
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_105 ) {
V_196 = V_2 -> V_93 + V_303 ;
V_95 = V_2 -> V_99 [ V_196 ] . V_95 ;
V_11 -> V_119 = V_95 ;
}
}
}
return 0 ;
}
void F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_404 = 0 ;
if ( F_56 ( V_2 ) )
V_404 = V_405 ;
else if ( F_64 ( V_2 ) )
V_404 = V_406 ;
if ( V_4 -> V_78 [ 0 ] & V_407 )
F_231 ( V_2 , V_404 ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
F_95 ( V_2 ) ;
F_99 ( V_2 ) ;
}
static int
F_233 ( struct V_23 * V_5 , const struct V_173 * V_174 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_369 = - 1 ;
char V_408 [ V_409 + 19 ] ;
V_51 = F_234 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_235 ( V_5 , 0 ) & V_410 ) ) {
V_51 = - V_411 ;
goto V_412;
}
V_51 = F_221 ( V_5 , & V_369 ) ;
if ( V_51 )
goto V_412;
V_51 = F_236 ( V_5 , V_413 ) ;
if ( V_51 )
goto V_412;
F_237 ( V_5 ) ;
F_238 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_414;
}
switch ( V_174 -> V_6 ) {
case V_7 :
V_4 -> V_415 = & V_416 ;
V_4 -> V_417 = ( T_1 * ) V_418 ;
break;
case V_186 :
case V_187 :
case V_188 :
F_239 ( V_4 ) ;
break;
case V_189 :
case V_190 :
F_240 ( V_4 ) ;
break;
default:
goto V_419;
}
V_51 = F_104 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_419;
V_22 = F_241 ( sizeof( struct V_1 ) ,
V_420 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_421;
}
F_242 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_422 = F_243 ( L_28 ) ;
if ( V_2 -> V_422 == NULL ) {
V_51 = - V_56 ;
F_82 ( & V_5 -> V_30 , L_40 ) ;
goto V_423;
}
V_51 = F_204 ( V_2 ) ;
if ( V_51 )
goto V_424;
V_2 -> V_425 = V_426 ;
V_4 -> V_427 = V_5 -> V_428 ;
V_4 -> V_146 = F_244 ( V_2 ) ;
if ( V_429 == V_430 )
V_2 -> V_52 = true ;
else if ( V_429 == V_431 )
V_2 -> V_432 = true ;
F_245 ( & V_2 -> V_4 -> V_433 ) ;
F_246 ( & V_2 -> V_4 -> V_434 ) ;
F_247 ( & V_2 -> V_435 ) ;
F_248 ( V_2 ) ;
if ( F_56 ( V_2 ) ) {
F_100 ( V_2 , V_174 ) ;
V_2 -> V_436 = V_2 -> V_4 -> V_27 ;
F_232 ( V_2 ) ;
V_51 = F_249 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_437;
}
if ( V_2 -> V_4 -> V_106 ) {
if ( F_55 ( V_2 ) == 1 )
F_61 ( V_2 ,
V_110 ) ;
else
F_61 ( V_2 ,
V_438 ) ;
F_62 ( V_2 ,
V_439 ) ;
} else {
F_61 ( V_2 , V_110 ) ;
F_62 ( V_2 , V_110 ) ;
}
V_51 = F_250 ( V_2 ) ;
if ( V_51 )
goto V_350;
V_2 -> V_41 |= V_440 ;
} else if ( F_64 ( V_2 ) ) {
F_251 ( V_2 , V_174 ) ;
V_2 -> V_436 = V_2 -> V_4 -> V_27 ;
V_51 = F_252 ( V_2 , V_369 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_441 :
F_82 ( & V_5 -> V_30 , L_43 ) ;
F_82 ( & V_5 -> V_30 , L_44 ) ;
goto V_350;
case - V_56 :
F_82 ( & V_5 -> V_30 , L_45 ) ;
goto V_350;
case - V_43 :
F_82 ( & V_5 -> V_30 , L_46 ) ;
goto V_350;
default:
F_82 ( & V_5 -> V_30 , L_47 ) ;
goto V_437;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_82 ( & V_5 -> V_30 ,
L_48 , V_54 ) ;
goto V_350;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_253 ( V_2 ) ;
if ( V_2 -> V_436 == 0 ) {
F_110 ( V_2 , V_408 ) ;
F_37 ( L_50 ,
F_254 ( V_442 ) ,
V_408 , V_2 -> V_4 -> V_427 ) ;
}
if ( F_64 ( V_2 ) && ! V_120 &&
! ! V_116 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_56 ( V_2 ) ) {
F_255 ( V_2 -> V_398 ) ;
F_256 ( V_2 -> V_398 ) ;
V_51 = F_257 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_52 ) ;
goto V_443;
}
}
V_51 = F_88 ( V_2 ) ;
if ( V_51 )
goto V_444;
if ( V_2 -> V_436 == 0 )
F_230 ( V_2 ) ;
V_51 = F_215 ( V_2 , V_22 , V_369 ) ;
if ( V_51 )
goto V_444;
F_258 ( V_5 , V_2 ) ;
if ( F_56 ( V_2 ) )
F_259 ( V_2 , V_445 ,
V_446 ) ;
switch ( V_2 -> V_4 -> V_138 ) {
case V_139 :
F_70 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_202 ) ;
break;
case V_142 :
F_70 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_202 ) ;
break;
}
if ( V_2 -> V_432 )
F_260 ( V_2 ) ;
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
return 0 ;
V_444:
if ( F_64 ( V_2 ) )
F_263 ( V_2 ) ;
V_443:
F_83 ( V_2 ) ;
F_264 ( V_2 ) ;
F_265 ( V_2 , 0 ) ;
V_350:
F_205 ( V_2 ) ;
V_424:
F_266 ( V_2 -> V_422 ) ;
V_423:
F_267 ( V_22 ) ;
V_421:
F_86 ( V_4 ) ;
V_419:
F_7 ( V_4 ) ;
V_414:
F_268 ( V_5 ) ;
V_412:
F_269 ( V_5 ) ;
return V_51 ;
V_437:
F_122 ( V_447 , & V_2 -> V_46 ) ;
V_22 -> V_372 = & V_448 ;
V_22 -> V_377 = & V_449 ;
V_4 -> V_138 = V_142 ;
if ( F_64 ( V_2 ) )
V_2 -> V_118 = NULL ;
else
V_4 -> V_450 = V_451 ;
V_51 = F_220 ( V_22 ) ;
if ( V_51 ) {
F_82 ( & V_5 -> V_30 , L_55 ) ;
F_265 ( V_2 , 0 ) ;
goto V_350;
}
F_258 ( V_5 , V_2 ) ;
F_261 ( V_2 ) ;
return 0 ;
}
static void F_270 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_271 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_264 ( V_2 ) ;
F_272 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_273 ( V_22 ) ;
F_274 ( V_2 ) ;
if ( F_64 ( V_2 ) ) {
F_275 ( V_2 , 0 ) ;
F_47 ( & V_2 -> V_452 ) ;
F_263 ( V_2 ) ;
F_276 ( V_2 ) ;
F_277 ( V_4 -> V_453 ) ;
F_7 ( V_4 -> V_454 ) ;
}
F_278 ( V_2 -> V_398 ) ;
F_199 ( V_2 ) ;
if ( V_2 -> V_152 != NULL )
F_7 ( V_2 -> V_152 ) ;
if ( V_2 -> V_154 != NULL )
F_7 ( V_2 -> V_154 ) ;
if ( F_56 ( V_2 ) )
F_265 ( V_2 , 0 ) ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
F_279 ( V_2 ) ;
F_83 ( V_2 ) ;
F_280 ( V_2 ) ;
F_281 ( V_2 ) ;
F_86 ( V_2 -> V_4 ) ;
F_150 ( V_2 ) ;
F_282 ( V_5 ) ;
F_268 ( V_5 ) ;
F_269 ( V_5 ) ;
if ( V_2 -> V_422 ) {
F_266 ( V_2 -> V_422 ) ;
V_2 -> V_422 = NULL ;
}
F_205 ( V_2 ) ;
F_7 ( V_4 ) ;
F_267 ( V_22 ) ;
}
static void F_283 ( struct V_23 * V_5 )
{
if ( F_284 ( V_5 ) )
return;
F_269 ( V_5 ) ;
}
static int F_285 ( struct V_23 * V_5 , T_9 V_46 )
{
int V_455 ;
V_455 = F_284 ( V_5 ) ;
if ( V_455 )
return V_455 ;
F_286 ( V_5 , F_287 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_288 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
int V_51 ;
V_51 = F_234 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_286 ( V_5 , V_456 ) ;
F_237 ( V_5 ) ;
F_289 ( V_5 ) ;
return F_290 ( V_2 ) ;
}
static int F_291 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_21 ( V_447 , & V_2 -> V_46 ) ) {
F_121 ( V_22 , L_56 ,
V_54 ) ;
return - V_111 ;
}
F_179 ( V_22 ) ;
V_51 = F_189 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_164 ( V_2 , V_22 ) ;
if ( V_51 )
F_199 ( V_2 ) ;
return V_51 ;
}
static int F_292 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_176 ( V_2 , V_22 ) ;
return 0 ;
}
void F_260 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_129 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_457 = 0 ;
T_3 V_149 = 0 ;
if ( V_2 -> V_343 . V_458 && V_2 -> V_343 . V_459 )
return;
V_149 = V_2 -> V_4 -> V_140 ;
F_229 ( & V_2 -> V_460 ) ;
F_229 ( & V_2 -> V_461 ) ;
if ( F_20 ( V_2 ) ) {
V_457 = V_462 - 1 ;
V_2 -> V_343 . V_463 = V_464 ;
} else if ( F_56 ( V_2 ) ) {
V_457 = V_366 ;
V_2 -> V_343 . V_463 = V_465 ;
} else {
V_457 = V_466 ;
V_2 -> V_343 . V_463 = V_467 ;
}
V_34 = F_65 ( V_2 -> V_343 . V_463 ,
sizeof( struct V_468 ) , V_469 ) ;
if ( ! V_34 )
return;
V_2 -> V_343 . V_458 = ( V_457 / V_149 ) ;
V_2 -> V_343 . V_459 = V_34 ;
F_67 ( V_22 , L_57 ,
V_149 , V_2 -> V_343 . V_458 ) ;
for ( V_129 = 0 ; V_129 < V_2 -> V_343 . V_463 ; V_129 ++ )
F_293 ( & V_2 -> V_343 . V_459 [ V_129 ] ) ;
V_2 -> V_470 . V_463 = V_2 -> V_343 . V_463 ;
V_34 = F_65 ( V_2 -> V_470 . V_463 ,
sizeof( struct V_468 ) , V_469 ) ;
if ( ! V_34 )
return;
V_2 -> V_470 . V_458 = ( V_457 / V_149 ) ;
V_2 -> V_470 . V_459 = V_34 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_470 . V_463 ; V_129 ++ )
F_293 ( & V_2 -> V_470 . V_459 [ V_129 ] ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
if ( V_2 -> V_343 . V_458 && V_2 -> V_343 . V_459 )
F_7 ( V_2 -> V_343 . V_459 ) ;
V_2 -> V_343 . V_459 = NULL ;
V_2 -> V_343 . V_458 = 0 ;
if ( V_2 -> V_470 . V_458 && V_2 -> V_470 . V_459 )
F_7 ( V_2 -> V_470 . V_459 ) ;
V_2 -> V_470 . V_458 = 0 ;
V_2 -> V_470 . V_459 = NULL ;
}
int F_294 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_471 , V_472 , V_243 = 0 ;
int V_473 = 0 ;
if ( F_64 ( V_2 ) )
V_243 = F_295 ( V_2 -> V_4 , V_474 ) ;
if ( F_56 ( V_2 ) )
V_243 = F_96 ( V_2 , V_475 ) ;
V_471 = F_296 ( V_243 ) ;
V_472 = F_297 ( V_243 ) ;
if ( V_471 == V_476 ) {
F_82 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_472 ) ;
V_473 = 1 ;
} else if ( V_471 == V_477 ) {
if ( V_2 -> V_4 -> V_243 == V_478 ) {
F_82 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_472 ) ;
}
} else {
if ( V_2 -> V_4 -> V_243 == V_477 ) {
F_70 ( & V_22 -> V_30 ,
L_63
L_64 , V_472 ) ;
}
}
V_2 -> V_4 -> V_243 = V_471 ;
return V_473 ;
}
static inline void F_298 ( struct V_10 * V_11 )
{
int V_129 ;
struct V_479 * V_480 ;
for ( V_129 = 0 ; V_129 < V_11 -> V_401 ; V_129 ++ ) {
V_480 = & V_11 -> V_481 [ V_129 ] ;
F_37 ( L_65 , V_129 ) ;
F_299 ( V_482 , L_66 , V_483 , 16 , 1 ,
& V_11 -> V_481 [ V_129 ] ,
sizeof( struct V_479 ) , true ) ;
}
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_332 * V_333 ;
struct V_18 * V_302 ;
struct V_10 * V_11 ;
int V_303 ;
if ( ! V_22 || ! F_174 ( V_22 ) )
return;
for ( V_303 = 0 ; V_303 < V_2 -> V_233 ; V_303 ++ ) {
V_333 = & V_15 -> V_336 [ V_303 ] ;
if ( ! V_333 )
continue;
F_67 ( V_22 ,
L_67 ,
V_303 , F_301 ( V_333 -> V_484 ) ,
V_333 -> V_12 , V_333 -> V_401 ) ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_302 = & ( V_15 -> V_19 [ V_303 ] ) ;
if ( ! V_302 )
continue;
F_67 ( V_22 ,
L_68 ,
V_303 , F_301 ( V_302 -> V_485 ) ,
V_302 -> V_486 , F_301 ( V_302 -> V_487 ) ,
V_302 -> V_401 ) ;
}
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
if ( ! V_11 )
continue;
F_67 ( V_22 , L_69 ,
V_303 , V_11 -> V_488 ) ;
F_67 ( V_22 ,
L_70 ,
V_11 -> V_489 . V_490 ,
V_11 -> V_489 . V_491 ,
V_11 -> V_489 . V_492 ,
V_11 -> V_489 . V_493 ) ;
if ( V_11 -> V_487 )
F_67 ( V_22 , L_71 ,
F_301 ( V_11 -> V_487 ) ) ;
F_67 ( V_22 ,
L_72 ,
F_301 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_494 ,
F_302 ( * ( V_11 -> V_495 ) ) ) ;
F_67 ( V_22 , L_73 ,
V_11 -> V_401 , F_303 ( V_11 ) ) ;
if ( F_304 ( V_2 -> V_4 ) )
F_298 ( V_11 ) ;
}
}
static void F_305 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
return;
F_300 ( V_2 ) ;
if ( ++ V_2 -> V_496 >= V_497 ||
F_304 ( V_2 -> V_4 ) ) {
F_121 ( V_22 , L_74 ) ;
if ( F_56 ( V_2 ) )
V_2 -> V_275 = 1 ;
else if ( F_64 ( V_2 ) )
F_306 ( V_2 ,
V_498 ) ;
} else {
F_121 ( V_22 , L_75 ) ;
V_2 -> V_4 -> V_342 = 1 ;
}
}
static struct V_499 * F_307 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_499 * V_352 = & V_22 -> V_352 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_308 ( V_2 ) ;
V_352 -> V_329 = V_2 -> V_352 . V_500 + V_2 -> V_352 . V_501 ;
V_352 -> V_325 = V_2 -> V_352 . V_502 ;
V_352 -> V_503 = V_2 -> V_352 . V_504 + V_2 -> V_352 . V_505 ;
V_352 -> V_506 = V_2 -> V_352 . V_507 ;
V_352 -> V_508 = V_2 -> V_352 . V_509 ;
V_352 -> V_510 = V_2 -> V_352 . V_511 ;
return V_352 ;
}
static T_10 F_309 ( struct V_1 * V_2 )
{
T_1 V_512 ;
V_512 = F_301 ( V_2 -> V_124 ) ;
if ( ! ( V_512 & V_2 -> V_4 -> V_122 ) )
return V_513 ;
V_512 = F_301 ( V_2 -> V_126 ) ;
if ( ! F_310 ( V_512 ) )
return V_513 ;
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
F_301 ( V_2 -> V_124 ) ;
F_301 ( V_2 -> V_124 ) ;
return V_514 ;
}
static T_10 V_306 ( int V_119 , void * V_170 )
{
struct V_18 * V_302 = V_170 ;
struct V_1 * V_2 = V_302 -> V_2 ;
if ( V_2 -> V_41 & V_105 )
goto V_515;
else if ( V_2 -> V_41 & V_104 ) {
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
goto V_515;
}
if ( F_311 ( V_2 ) == V_513 )
return V_513 ;
V_515:
V_2 -> V_4 -> V_516 ++ ;
F_208 ( V_2 , V_302 ) ;
return V_514 ;
}
static T_10 V_311 ( int V_119 , void * V_170 )
{
struct V_18 * V_302 = V_170 ;
struct V_1 * V_2 = V_302 -> V_2 ;
if ( F_311 ( V_2 ) == V_513 )
return V_513 ;
F_312 ( & V_302 -> V_517 ) ;
return V_514 ;
}
static T_10 V_310 ( int V_119 , void * V_170 )
{
struct V_18 * V_302 = V_170 ;
struct V_1 * V_2 = V_302 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
F_312 ( & V_302 -> V_517 ) ;
return V_514 ;
}
static T_10 V_309 ( int V_119 , void * V_170 )
{
struct V_18 * V_302 = V_170 ;
F_312 ( & V_302 -> V_517 ) ;
return V_514 ;
}
static T_10 V_315 ( int V_119 , void * V_170 )
{
struct V_10 * V_11 = V_170 ;
F_312 ( & V_11 -> V_517 ) ;
return V_514 ;
}
static void F_313 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_302 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_303 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_303 = 0 ; V_303 < V_2 -> V_93 ; V_303 ++ ) {
V_302 = & V_15 -> V_19 [ V_303 ] ;
F_203 ( V_2 , V_302 ) ;
F_312 ( & V_302 -> V_517 ) ;
}
if ( V_2 -> V_41 & V_105 ) {
if ( ( F_64 ( V_2 ) &&
( V_2 -> V_41 & V_314 ) ) ||
( F_56 ( V_2 ) &&
! F_72 ( V_2 ) ) )
return;
for ( V_303 = 0 ; V_303 < V_2 -> V_91 ; V_303 ++ ) {
V_11 = & V_2 -> V_11 [ V_303 ] ;
F_314 ( V_2 , V_11 ) ;
F_312 ( & V_11 -> V_517 ) ;
}
}
}
static void
F_153 ( struct V_1 * V_2 , T_2 V_518 )
{
T_1 V_519 ;
V_519 = V_2 -> V_436 & 0xf ;
V_519 |= V_518 << 7 ;
V_519 |= ( V_426 - V_2 -> V_425 ) << 8 ;
F_98 ( V_2 , V_520 , V_519 ) ;
V_2 -> V_425 = V_426 ;
}
static int
F_315 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_519 ;
F_316 ( V_46 != V_521 &&
V_46 != V_522 ) ;
if ( F_95 ( V_2 ) )
return - V_111 ;
V_519 = F_96 ( V_2 , V_523 ) ;
if ( V_46 == V_521 )
F_317 ( V_519 , V_2 -> V_436 ) ;
else if ( V_46 == V_522 )
F_318 ( V_519 , V_2 -> V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static int
F_319 ( struct V_1 * V_2 )
{
T_1 V_519 ;
if ( F_95 ( V_2 ) )
return - V_360 ;
V_519 = F_96 ( V_2 , V_523 ) ;
F_320 ( V_519 , V_2 -> V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
void F_265 ( struct V_1 * V_2 , T_2 V_524 )
{
T_1 V_519 ;
if ( F_95 ( V_2 ) )
goto V_51;
V_519 = F_96 ( V_2 , V_525 ) ;
F_321 ( V_519 , V_2 -> V_436 ) ;
F_98 ( V_2 , V_525 , V_519 ) ;
if ( V_524 ) {
F_98 ( V_2 , V_298 ,
V_300 ) ;
F_70 ( & V_2 -> V_5 -> V_30 ,
L_76 ) ;
} else if ( ! ( V_519 & 0x11111111 ) )
F_98 ( V_2 , V_298 ,
V_526 ) ;
V_519 = F_96 ( V_2 , V_523 ) ;
F_320 ( V_519 , V_2 -> V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
F_99 ( V_2 ) ;
V_51:
V_2 -> V_527 = 0 ;
V_2 -> V_41 &= ~ V_528 ;
F_125 ( V_529 , & V_2 -> V_46 ) ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
}
static int
F_322 ( struct V_1 * V_2 )
{
int V_530 , V_46 , V_531 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_96 ( V_2 , V_523 ) ;
V_530 = F_96 ( V_2 , V_525 ) ;
if ( V_2 -> V_41 & V_532 ) {
V_531 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_530 = V_530 & V_531 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_530 & 0x11111111 ) ) ||
( ( V_530 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_323 ( struct V_1 * V_2 )
{
T_1 V_519 = F_96 ( V_2 , V_533 ) ;
if ( V_519 != V_534 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_534 , V_519 ) ;
}
return 0 ;
}
static int
F_144 ( struct V_1 * V_2 )
{
T_1 V_519 , V_535 ;
T_2 V_536 = V_2 -> V_536 ;
T_2 V_436 = V_2 -> V_436 ;
T_2 V_26 ;
if ( F_177 ( V_529 , & V_2 -> V_46 ) )
return 1 ;
if ( F_95 ( V_2 ) )
return - 1 ;
V_519 = F_96 ( V_2 , V_525 ) ;
if ( ! ( V_519 & ( 1 << ( V_436 * 4 ) ) ) ) {
F_324 ( V_519 , V_436 ) ;
F_98 ( V_2 , V_525 , V_519 ) ;
}
V_535 = F_96 ( V_2 , V_298 ) ;
F_325 ( V_2 , V_537 , L_79 , V_535 ) ;
switch ( V_535 ) {
case V_526 :
F_98 ( V_2 , V_298 ,
V_538 ) ;
F_98 ( V_2 , V_533 ,
V_534 ) ;
F_153 ( V_2 , 0 ) ;
F_99 ( V_2 ) ;
return 1 ;
case V_299 :
V_26 = F_323 ( V_2 ) ;
F_99 ( V_2 ) ;
return V_26 ;
case V_521 :
V_519 = F_96 ( V_2 , V_523 ) ;
F_317 ( V_519 , V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
break;
case V_522 :
V_519 = F_96 ( V_2 , V_523 ) ;
F_318 ( V_519 , V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
break;
case V_300 :
F_82 ( & V_2 -> V_5 -> V_30 , L_80 ) ;
F_99 ( V_2 ) ;
return - 1 ;
case V_538 :
case V_539 :
break;
}
F_99 ( V_2 ) ;
do {
F_140 ( 1000 ) ;
V_535 = F_96 ( V_2 , V_298 ) ;
if ( V_535 == V_539 )
continue;
} while ( ( V_535 != V_299 ) && -- V_536 );
if ( ! V_536 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_81 ) ;
return - 1 ;
}
if ( F_95 ( V_2 ) )
return - 1 ;
V_519 = F_96 ( V_2 , V_523 ) ;
F_320 ( V_519 , V_436 ) ;
F_98 ( V_2 , V_523 , V_519 ) ;
V_26 = F_323 ( V_2 ) ;
F_99 ( V_2 ) ;
return V_26 ;
}
static void
F_326 ( struct V_540 * V_65 )
{
struct V_1 * V_2 = F_327 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
T_1 V_541 = 0xf ;
T_1 V_519 ;
if ( F_95 ( V_2 ) )
goto V_542;
V_541 = F_96 ( V_2 , V_298 ) ;
if ( V_541 == V_539 ||
V_541 == V_522 ) {
F_99 ( V_2 ) ;
F_259 ( V_2 , F_326 ,
V_446 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_144 == V_179 ) {
F_99 ( V_2 ) ;
goto V_543;
}
if ( V_541 == V_538 ||
V_541 == V_299 ) {
F_70 ( & V_2 -> V_5 -> V_30 , L_82
L_83 ) ;
goto V_544;
}
if ( V_2 -> V_545 ++ > V_2 -> V_546 ) {
F_70 ( & V_2 -> V_5 -> V_30 , L_84 ,
V_2 -> V_546 ) ;
goto V_544;
}
if ( ! F_322 ( V_2 ) ) {
V_544:
V_541 = F_96 ( V_2 , V_298 ) ;
if ( V_541 == V_521 ) {
F_98 ( V_2 , V_298 ,
V_538 ) ;
F_122 ( V_529 , & V_2 -> V_46 ) ;
F_325 ( V_2 , V_547 , L_85 ) ;
F_153 ( V_2 , 0 ) ;
V_519 = F_96 ( V_2 ,
V_523 ) ;
F_317 ( V_519 , V_2 -> V_436 ) ;
F_98 ( V_2 ,
V_523 , V_519 ) ;
}
F_99 ( V_2 ) ;
F_173 () ;
if ( F_328 ( V_2 ) &&
( V_2 -> V_41 & V_532 ) ) {
F_325 ( V_2 , V_547 , L_86 ) ;
F_329 ( V_2 ) ;
V_2 -> V_41 |= V_528 ;
}
F_175 () ;
V_2 -> V_41 &= ~ V_532 ;
if ( ! V_2 -> V_180 -> V_548 ( V_2 ) ) {
F_259 ( V_2 , V_549 , 0 ) ;
V_2 -> V_545 = 0 ;
return;
}
goto V_542;
}
F_99 ( V_2 ) ;
V_543:
V_541 = F_96 ( V_2 , V_298 ) ;
F_325 ( V_2 , V_537 , L_87 , V_541 ) ;
switch ( V_541 ) {
case V_299 :
if ( ! F_249 ( V_2 ) ) {
F_259 ( V_2 , V_549 , 0 ) ;
V_2 -> V_545 = 0 ;
return;
}
case V_300 :
break;
default:
F_259 ( V_2 ,
F_326 , V_446 ) ;
return;
}
V_542:
F_82 ( & V_2 -> V_5 -> V_30 , L_88
L_89 , V_541 , V_2 -> V_545 ) ;
F_25 ( V_2 -> V_22 ) ;
F_265 ( V_2 , 0 ) ;
}
static void
F_330 ( struct V_540 * V_65 )
{
struct V_1 * V_2 = F_327 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_512 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_541 == V_522 ) {
if ( F_174 ( V_22 ) )
F_176 ( V_2 , V_22 ) ;
} else
F_188 ( V_2 , V_22 ) ;
V_512 = F_96 ( V_2 , V_550 ) ;
if ( V_512 & V_551 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_90 ,
V_512 ) ;
if ( F_331 ( V_512 ) == V_552 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_91
L_92 ) ;
F_82 ( & V_2 -> V_5 -> V_30 ,
L_93 ) ;
}
goto V_542;
}
if ( V_2 -> V_4 -> V_243 == V_476 ) {
F_82 ( & V_2 -> V_5 -> V_30 , L_94 ,
V_2 -> V_4 -> V_243 ) ;
goto V_542;
}
if ( ! ( V_2 -> V_41 & V_532 ) ) {
if ( F_315 ( V_2 , V_2 -> V_541 ) ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_95
L_96 ) ;
goto V_542;
}
}
V_2 -> V_545 = 0 ;
F_259 ( V_2 , F_326 , V_446 ) ;
return;
V_542:
F_25 ( V_22 ) ;
F_265 ( V_2 , 1 ) ;
}
static void
F_332 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_96 ( V_2 , V_289 ) ;
if ( V_46 == V_553 )
return;
if ( F_95 ( V_2 ) )
return;
F_98 ( V_2 , V_289 ,
V_553 ) ;
F_99 ( V_2 ) ;
}
static void F_333 ( struct V_1 * V_2 ,
T_1 V_554 )
{
T_1 V_46 , V_555 = 0 , V_556 = 0 ;
F_334 ( V_555 ) ;
F_335 ( V_555 ) ;
F_151 ( V_2 , V_557 , V_555 ) ;
F_336 ( V_556 ) ;
F_337 ( V_556 ) ;
F_338 ( V_556 ) ;
F_339 ( V_556 ) ;
F_151 ( V_2 , V_558 , V_556 ) ;
F_70 ( & V_2 -> V_5 -> V_30 , L_97
L_98 ) ;
V_2 -> V_275 = 1 ;
if ( F_95 ( V_2 ) )
return;
V_46 = F_96 ( V_2 , V_298 ) ;
if ( F_21 ( V_447 , & V_2 -> V_46 ) ) {
F_121 ( V_2 -> V_22 , L_56 ,
V_54 ) ;
F_99 ( V_2 ) ;
return;
}
if ( V_46 == V_299 ) {
F_98 ( V_2 , V_298 ,
V_521 ) ;
V_2 -> V_41 |= V_532 ;
F_325 ( V_2 , V_547 , L_99 ) ;
F_153 ( V_2 , 0 ) ;
}
F_98 ( V_2 , V_289 ,
V_553 ) ;
F_99 ( V_2 ) ;
}
static void
F_142 ( struct V_1 * V_2 )
{
if ( F_95 ( V_2 ) )
return;
F_98 ( V_2 , V_289 ,
V_290 ) ;
F_325 ( V_2 , V_547 , L_100 ) ;
F_99 ( V_2 ) ;
}
void F_259 ( struct V_1 * V_2 ,
T_11 V_66 , int V_559 )
{
if ( F_21 ( V_560 , & V_2 -> V_46 ) )
return;
F_340 ( & V_2 -> V_64 , V_66 ) ;
F_341 ( V_2 -> V_422 , & V_2 -> V_64 ,
F_342 ( V_559 ) ) ;
}
static void
V_549 ( struct V_540 * V_65 )
{
struct V_1 * V_2 = F_327 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_288 ;
if ( V_2 -> V_4 -> V_144 != V_145 ) {
V_288 = F_96 ( V_2 ,
V_289 ) ;
if ( V_2 -> V_545 ++ > V_287 )
F_265 ( V_2 , 0 ) ;
else if ( V_288 != V_290 )
F_259 ( V_2 , V_549 ,
V_446 ) ;
else
goto V_561;
F_325 ( V_2 , V_547 , L_101 ) ;
return;
}
V_561:
F_256 ( V_2 -> V_398 ) ;
if ( F_174 ( V_22 ) ) {
if ( F_172 ( V_2 , V_22 ) )
goto V_515;
F_124 ( V_22 , V_361 ) ;
}
V_515:
F_25 ( V_22 ) ;
V_2 -> V_527 = 0 ;
V_2 -> V_41 &= ~ V_528 ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
if ( V_2 -> V_436 == 0 )
F_230 ( V_2 ) ;
if ( ! F_319 ( V_2 ) )
F_259 ( V_2 , V_445 ,
V_446 ) ;
}
static int
F_343 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_211 * V_212 = & V_4 -> V_212 ;
T_1 V_46 = 0 , V_562 ;
T_1 V_563 ;
int V_51 = 0 ;
if ( F_294 ( V_2 ) )
goto V_564;
if ( V_2 -> V_275 )
F_344 ( V_2 , 0 ) ;
V_46 = F_96 ( V_2 , V_298 ) ;
if ( V_46 == V_521 ) {
F_332 ( V_2 ) ;
V_2 -> V_275 = 1 ;
} else if ( V_46 == V_522 )
goto V_564;
V_562 = F_96 ( V_2 , V_565 ) ;
if ( V_562 != V_2 -> V_562 ) {
V_2 -> V_562 = V_562 ;
V_2 -> V_527 = 0 ;
if ( V_2 -> V_275 )
goto V_564;
if ( V_4 -> V_342 && V_566 )
F_209 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_527 < V_567 )
return 0 ;
V_2 -> V_41 |= V_528 ;
F_344 ( V_2 , 0 ) ;
if ( V_566 )
F_125 ( V_568 , & V_2 -> V_46 ) ;
F_82 ( & V_2 -> V_5 -> V_30 , L_102 ) ;
V_563 = F_96 ( V_2 , V_550 ) ;
F_82 ( & V_2 -> V_5 -> V_30 , L_103
L_104
L_105
L_106
L_107 ,
V_563 ,
F_96 ( V_2 , V_569 ) ,
F_117 ( V_2 , V_570 + 0x3c , & V_51 ) ,
F_117 ( V_2 , V_571 + 0x3c , & V_51 ) ,
F_117 ( V_2 , V_572 + 0x3c , & V_51 ) ,
F_117 ( V_2 , V_573 + 0x3c , & V_51 ) ,
F_117 ( V_2 , V_574 + 0x3c , & V_51 ) ) ;
if ( F_331 ( V_563 ) == 0x67 )
F_82 ( & V_2 -> V_5 -> V_30 ,
L_108
L_109 ) ;
V_564:
V_2 -> V_541 = ( V_46 == V_522 ) ? V_46 :
V_521 ;
if ( V_566 && ! F_45 ( V_63 ,
& V_2 -> V_46 ) ) {
F_259 ( V_2 , F_330 , 0 ) ;
F_325 ( V_2 , V_547 , L_110 ) ;
} else if ( ! V_566 && V_212 -> V_575 &&
V_2 -> V_41 & V_532 ) {
F_329 ( V_2 ) ;
}
return 1 ;
}
void V_445 ( struct V_540 * V_65 )
{
struct V_1 * V_2 = F_327 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
goto V_576;
if ( F_343 ( V_2 ) )
return;
if ( V_2 -> V_343 . V_344 )
F_345 ( V_2 ) ;
V_576:
F_259 ( V_2 , V_445 , V_446 ) ;
}
static int F_346 ( struct V_23 * V_5 )
{
struct V_23 * V_577 ;
int V_519 = V_5 -> V_578 ;
while ( V_519 -- > 0 ) {
V_577 = F_347 ( F_348
( V_5 -> V_579 ) , V_5 -> V_579 -> V_580 ,
F_349 ( F_350 ( V_5 -> V_578 ) , V_519 ) ) ;
if ( ! V_577 )
continue;
if ( V_577 -> V_581 != V_582 ) {
F_351 ( V_577 ) ;
return 0 ;
}
F_351 ( V_577 ) ;
}
return 1 ;
}
static int F_352 ( struct V_23 * V_5 )
{
int V_51 , V_583 ;
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_584 = V_585 ;
V_51 = F_234 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_237 ( V_5 ) ;
F_289 ( V_5 ) ;
V_583 = F_346 ( V_5 ) ;
if ( F_95 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_144 != V_179 && V_583 ) {
V_2 -> V_275 = 1 ;
F_122 ( V_529 , & V_2 -> V_46 ) ;
F_98 ( V_2 , V_298 ,
V_538 ) ;
F_325 ( V_2 , V_547 , L_85 ) ;
}
F_99 ( V_2 ) ;
V_51 = F_249 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_319 ( V_2 ) ;
F_7 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
V_51 = F_257 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_99 ) ;
F_121 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( F_174 ( V_22 ) ) {
V_51 = F_189 ( V_2 ) ;
if ( V_51 ) {
F_265 ( V_2 , 1 ) ;
F_125 ( V_560 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_51 ;
}
V_51 = F_172 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_515;
F_124 ( V_22 , V_361 ) ;
}
V_515:
F_25 ( V_22 ) ;
return V_51 ;
}
static T_12 F_353 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_586 )
return V_587 ;
if ( V_46 == V_585 )
return V_588 ;
F_122 ( V_560 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_64 ) ;
if ( F_174 ( V_22 ) )
F_188 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
F_83 ( V_2 ) ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
F_354 ( V_5 ) ;
F_269 ( V_5 ) ;
return V_589 ;
}
static T_12 F_355 ( struct V_23 * V_5 )
{
return F_352 ( V_5 ) ? V_587 :
V_588 ;
}
static void F_356 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_271 ( V_5 ) ;
F_357 ( V_5 ) ;
V_46 = F_96 ( V_2 , V_298 ) ;
if ( V_46 == V_299 && F_177 ( V_560 ,
& V_2 -> V_46 ) )
F_259 ( V_2 , V_445 ,
V_446 ) ;
}
static T_12 F_358 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_590 * V_415 = V_2 -> V_4 -> V_415 ;
if ( V_415 -> V_591 ) {
return V_415 -> V_591 ( V_5 , V_46 ) ;
} else {
F_82 ( & V_5 -> V_30 , L_111 ) ;
return V_587 ;
}
}
static T_12 F_359 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_590 * V_415 = V_2 -> V_4 -> V_415 ;
if ( V_415 -> V_592 ) {
return V_415 -> V_592 ( V_5 ) ;
} else {
F_82 ( & V_5 -> V_30 , L_112 ) ;
return V_587 ;
}
}
static void F_360 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_590 * V_415 = V_2 -> V_4 -> V_415 ;
if ( V_415 -> V_593 )
V_415 -> V_593 ( V_5 ) ;
else
F_82 ( & V_5 -> V_30 , L_113 ) ;
}
static int
F_361 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_144 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_139 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_115 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_111 ( V_2 ) ;
V_51 = F_127 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_275 = 0 ;
return V_51 ;
}
int F_362 ( struct V_1 * V_2 , T_14 V_81 ,
int V_82 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_594 = 0 ;
char V_595 [ 8 ] ;
int V_596 ;
if ( V_82 == V_86 ) {
V_594 = V_2 -> V_87 ;
V_596 = V_2 -> V_93 ;
strcpy ( V_595 , L_114 ) ;
} else if ( V_82 == V_88 ) {
V_594 = V_2 -> V_89 ;
V_596 = V_2 -> V_91 ;
strcpy ( V_595 , L_115 ) ;
}
if ( ! F_363 ( V_81 ) ) {
F_121 ( V_22 , L_116 ,
V_595 ) ;
return - V_40 ;
}
if ( F_56 ( V_2 ) && ( V_82 == V_88 ) &&
! F_72 ( V_2 ) ) {
F_121 ( V_22 , L_117 ) ;
return - V_40 ;
}
if ( V_81 > F_60 () ) {
F_121 ( V_22 ,
L_118 ,
V_595 , F_60 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_364 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_597 , V_598 ;
int V_51 ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
return - V_360 ;
V_597 = V_2 -> V_97 ;
V_598 = V_2 -> V_98 ;
F_22 ( V_22 ) ;
V_51 = F_212 ( V_2 , V_597 , V_598 ) ;
if ( V_51 )
goto V_515;
if ( F_174 ( V_22 ) )
F_176 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
if ( F_64 ( V_2 ) ) {
F_263 ( V_2 ) ;
F_365 ( V_2 ) ;
}
F_83 ( V_2 ) ;
V_51 = F_257 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_99 ) ;
F_121 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( ( V_597 != V_2 -> V_91 ) ||
( V_598 != V_2 -> V_93 ) ) {
V_51 = F_212 ( V_2 ,
V_2 -> V_91 ,
V_2 -> V_93 ) ;
if ( V_51 )
goto V_515;
}
if ( F_64 ( V_2 ) ) {
F_275 ( V_2 , 1 ) ;
V_51 = F_366 ( V_2 ) ;
F_367 ( V_2 ) ;
if ( V_51 ) {
F_82 ( & V_2 -> V_5 -> V_30 ,
L_119 ) ;
goto V_515;
}
}
if ( F_174 ( V_22 ) ) {
V_51 = F_189 ( V_2 ) ;
if ( V_51 )
goto V_515;
V_51 = F_164 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_515;
F_124 ( V_22 , V_361 ) ;
}
V_515:
F_25 ( V_22 ) ;
F_125 ( V_63 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_368 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_599 )
{
struct V_600 * V_601 ;
V_601 = F_369 ( V_30 ) ;
if ( ! V_601 )
return;
F_370 (indev) {
switch ( V_599 ) {
case V_361 :
F_371 ( V_2 ,
V_602 -> V_603 , V_604 ) ;
break;
case V_264 :
F_371 ( V_2 ,
V_602 -> V_603 , V_605 ) ;
break;
default:
break;
}
} F_372 ( V_601 ) ;
F_373 ( V_601 ) ;
}
void F_124 ( struct V_21 * V_22 , unsigned long V_599 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_262 ;
F_368 ( V_2 , V_22 , V_599 ) ;
F_374 () ;
F_375 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_376 ( V_22 , F_377 ( V_606 ) , V_262 ) ;
if ( ! V_30 )
continue;
F_368 ( V_2 , V_30 , V_599 ) ;
}
F_378 () ;
}
static int F_379 ( struct V_607 * V_608 ,
unsigned long V_599 , void * V_609 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_380 ( V_609 ) ;
V_610:
if ( V_30 == NULL )
goto V_515;
if ( V_30 -> V_396 & V_611 ) {
V_30 = F_381 ( V_30 ) ;
goto V_610;
}
if ( ! F_382 ( V_30 ) )
goto V_515;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_515;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_515;
F_368 ( V_2 , V_30 , V_599 ) ;
V_515:
return V_612 ;
}
static int
F_383 ( struct V_607 * V_608 ,
unsigned long V_599 , void * V_609 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_613 * V_602 = (struct V_613 * ) V_609 ;
V_30 = V_602 -> V_614 ? V_602 -> V_614 -> V_30 : NULL ;
V_610:
if ( V_30 == NULL )
goto V_515;
if ( V_30 -> V_396 & V_611 ) {
V_30 = F_381 ( V_30 ) ;
goto V_610;
}
if ( ! F_382 ( V_30 ) )
goto V_515;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_515;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_515;
switch ( V_599 ) {
case V_361 :
F_371 ( V_2 , V_602 -> V_603 , V_604 ) ;
break;
case V_264 :
F_371 ( V_2 , V_602 -> V_603 , V_605 ) ;
break;
default:
break;
}
V_515:
return V_612 ;
}
void F_124 ( struct V_21 * V_30 , unsigned long V_599 )
{ }
static int T_15 F_384 ( void )
{
int V_26 ;
F_385 ( V_482 L_120 , V_615 ) ;
#ifdef F_386
F_387 ( & V_616 ) ;
F_388 ( & V_617 ) ;
#endif
V_26 = F_389 ( & V_618 ) ;
if ( V_26 ) {
#ifdef F_386
F_390 ( & V_617 ) ;
F_391 ( & V_616 ) ;
#endif
}
return V_26 ;
}
static void T_16 F_392 ( void )
{
F_393 ( & V_618 ) ;
#ifdef F_386
F_390 ( & V_617 ) ;
F_391 ( & V_616 ) ;
#endif
}
