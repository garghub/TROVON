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
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_54 ( V_2 ) &&
( V_4 -> V_78 [ 0 ] & V_79 ) ) {
F_45 ( V_80 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_55 ( struct V_1 * V_2 , T_2 V_81 ,
int V_82 )
{
int V_83 , V_84 = V_85 ;
if ( V_82 == V_86 )
V_84 = V_2 -> V_87 ;
else if ( V_82 == V_88 )
V_84 = V_2 -> V_89 ;
V_83 = F_56 ( F_57 ( int , F_58 () ,
V_84 ) ) ;
if ( V_81 > V_83 )
return V_83 ;
else
return V_81 ;
}
void F_59 ( struct V_1 * V_2 , T_2 V_90 )
{
if ( V_2 -> V_89 )
V_2 -> V_91 = F_55 ( V_2 , V_90 ,
V_88 ) ;
else
V_2 -> V_91 = V_90 ;
}
void F_60 ( struct V_1 * V_2 , T_2 V_92 )
{
if ( V_2 -> V_87 )
V_2 -> V_93 = F_55 ( V_2 , V_92 ,
V_86 ) ;
else
V_2 -> V_93 = V_92 ;
}
int F_61 ( struct V_1 * V_2 )
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
if ( F_62 ( V_2 ) )
V_94 += 1 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_63 ( V_94 ,
sizeof( struct V_100 ) ,
V_20 ) ;
if ( ! V_2 -> V_99 )
return - V_56 ;
}
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ )
V_2 -> V_99 [ V_95 ] . V_101 = V_95 ;
V_102:
V_51 = F_64 ( V_5 , V_2 -> V_99 , V_94 ) ;
if ( V_51 == - V_103 ) {
if ( ! V_2 -> V_97 && ! V_2 -> V_98 )
return V_51 ;
F_65 ( V_2 -> V_22 ,
L_3 ,
V_94 , V_51 ) ;
V_94 = V_2 -> V_91 + V_2 -> V_93 ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = 0 ;
if ( F_62 ( V_2 ) )
V_94 += 1 ;
F_65 ( V_2 -> V_22 ,
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
int F_66 ( struct V_1 * V_2 , T_1 V_94 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 , V_95 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_63 ( V_94 ,
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
V_51 = F_67 ( V_5 ,
V_2 -> V_99 , 1 , V_94 ) ;
if ( V_51 == V_94 ) {
V_2 -> V_41 |= V_105 ;
V_2 -> V_4 -> V_94 = V_94 ;
F_68 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_51 > 0 ) {
F_69 ( V_5 ) ;
F_68 ( & V_5 -> V_30 ,
L_3 ,
V_94 , V_51 ) ;
if ( F_54 ( V_2 ) ) {
V_94 = F_56 ( V_51 ) ;
if ( V_51 < V_108 )
return - V_103 ;
} else {
V_94 = F_56 ( V_51 - 1 ) ;
V_94 += 1 ;
if ( V_51 < V_109 )
return - V_103 ;
}
if ( F_54 ( V_2 ) &&
! F_70 ( V_2 ) ) {
V_2 -> V_93 = V_94 ;
V_2 -> V_91 = V_110 ;
} else {
V_2 -> V_91 = V_94 / 2 ;
V_2 -> V_93 = V_2 -> V_91 ;
}
if ( V_94 ) {
F_68 ( & V_5 -> V_30 ,
L_6 ,
V_94 ) ;
goto V_107;
}
} else {
F_68 ( & V_5 -> V_30 ,
L_7 ,
V_94 , V_51 ) ;
return V_51 ;
}
}
return - V_111 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = V_2 -> V_93 ;
if ( F_70 ( V_2 ) )
V_94 += V_2 -> V_91 ;
else
V_94 += V_110 ;
return V_94 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_112 , V_113 ;
const struct V_114 * V_115 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_116 && ! F_73 ( V_5 ) ) {
V_2 -> V_41 |= V_104 ;
V_112 = V_117 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_118 = F_74 ( V_2 -> V_4 ,
V_112 ) ;
F_68 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_99 [ 0 ] . V_95 = V_5 -> V_119 ;
return V_51 ;
}
if ( V_116 || V_120 )
return - V_43 ;
V_115 = & V_121 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_122 = V_115 -> V_122 ;
V_112 = V_115 -> V_118 ;
V_2 -> V_118 = F_74 ( V_4 , V_112 ) ;
V_113 = V_115 -> V_123 ;
V_2 -> V_123 = F_74 ( V_4 , V_113 ) ;
V_2 -> V_124 = F_74 ( V_4 , V_125 ) ;
V_2 -> V_126 = F_74 ( V_4 , V_127 ) ;
F_68 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_99 [ 0 ] . V_95 = V_5 -> V_119 ;
return V_51 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_94 , V_51 = 0 ;
if ( V_2 -> V_41 & V_96 ) {
V_51 = F_61 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_94 = V_2 -> V_4 -> V_94 ;
} else {
V_94 = F_71 ( V_2 ) ;
V_51 = F_66 ( V_2 , V_94 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_105 ) ) {
F_76 ( V_2 ) ;
V_2 -> V_93 = V_110 ;
V_51 = F_72 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , int V_128 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_129 ;
if ( F_70 ( V_2 ) &&
! V_4 -> V_130 &&
( V_2 -> V_41 & V_105 ) ) {
V_4 -> V_131 = F_78 ( V_4 -> V_94 *
sizeof( struct V_132 ) ) ;
if ( ! V_4 -> V_131 )
return - V_56 ;
for ( V_129 = 0 ; V_129 < V_4 -> V_94 ; V_129 ++ ) {
V_4 -> V_131 [ V_129 ] . type = V_133 ;
V_4 -> V_131 [ V_129 ] . V_72 = V_129 ;
V_4 -> V_131 [ V_129 ] . V_134 = 0 ;
}
V_51 = F_79 ( V_2 , 1 ) ;
if ( V_51 )
F_80 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_94 ) ;
return V_51 ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_105 )
F_69 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_104 )
F_82 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
if ( V_2 -> V_4 -> V_131 ) {
F_83 ( V_2 -> V_4 -> V_131 ) ;
V_2 -> V_4 -> V_131 = NULL ;
}
}
static void F_84 ( struct V_3 * V_4 )
{
if ( V_4 -> V_135 != NULL )
F_85 ( V_4 -> V_135 ) ;
}
static int F_86 ( struct V_1 * V_2 )
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
V_137 = F_63 ( V_4 -> V_146 , sizeof( * V_137 ) , V_20 ) ;
if ( ! V_137 )
return - V_56 ;
V_26 = F_87 ( V_2 , V_137 ) ;
F_7 ( V_137 ) ;
return V_26 ;
}
static bool F_88 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_89 ( V_2 ) ) {
V_26 = true ;
} else if ( F_62 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_78 [ 0 ] &
V_147 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 * V_137 ;
int V_129 , V_72 = 0 , V_26 = 0 , V_148 = 0 ;
T_3 V_149 ;
T_2 V_150 ;
V_137 = F_63 ( V_4 -> V_146 , sizeof( * V_137 ) , V_20 ) ;
if ( ! V_137 )
return - V_56 ;
V_26 = F_87 ( V_2 , V_137 ) ;
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
F_80 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_54 , V_150 , V_4 -> V_146 ) ;
goto V_158;
}
if ( ! V_137 [ V_129 ] . V_159 ||
( V_137 [ V_129 ] . type != V_160 ) )
continue;
if ( F_88 ( V_2 ) ) {
if ( ! F_91 ( V_2 , V_150 ,
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
if ( ! F_88 ( V_2 ) ) {
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
F_92 ( struct V_1 * V_2 )
{
T_2 V_72 ;
int V_26 ;
T_1 V_170 = V_145 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_93 ( V_2 ) ;
if ( V_26 )
goto V_171;
V_72 = V_4 -> V_27 ;
V_170 = F_94 ( V_2 , V_172 ) ;
V_170 = ( V_170 & ~ F_95 ( 0xf , V_72 ) ) |
F_95 ( V_145 , V_72 ) ;
F_96 ( V_2 , V_172 , V_170 ) ;
F_97 ( V_2 ) ;
V_171:
return V_26 ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_173 * V_174 )
{
T_1 V_144 , V_175 ;
V_2 -> V_4 -> V_176 = F_94 ( V_2 ,
V_177 ) ;
F_99 ( V_2 ) ;
V_144 = F_94 ( V_2 , V_172 ) ;
if ( V_144 == V_178 )
V_175 = V_145 ;
else
V_175 = F_100 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_175 == V_179 ) {
V_2 -> V_4 -> V_144 = V_179 ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_176 ) ;
V_2 -> V_180 = & V_181 ;
} else
V_2 -> V_180 = & V_182 ;
}
static void F_101 ( T_1 V_183 , T_6 * V_184 )
{
switch ( V_183 ) {
case V_7 :
* V_184 = V_185 ;
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
* V_184 = V_190 ;
break;
default:
* V_184 = 0 ;
}
}
static int F_102 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_112 ;
void T_7 * V_191 = NULL ;
unsigned long V_192 , V_193 = 0 , V_194 ;
V_192 = F_103 ( V_5 , 0 ) ;
F_101 ( V_5 -> V_6 , & V_194 ) ;
if ( V_192 >= V_194 ) {
V_191 = F_104 ( V_5 , 0 ) ;
if ( V_191 == NULL ) {
F_80 ( & V_5 -> V_30 , L_13 ) ;
return - V_111 ;
}
V_193 = V_192 ;
} else {
return - V_111 ;
}
F_68 ( & V_5 -> V_30 , L_14 , ( int ) ( V_192 >> 10 ) ) ;
V_4 -> V_135 = V_191 ;
V_4 -> V_193 = V_193 ;
V_112 = F_105 ( F_106 ( V_4 -> V_27 ) ) ;
F_74 ( V_4 , V_112 ) ;
return 0 ;
}
static bool F_107 ( struct V_1 * V_2 ,
int V_195 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_196 ;
bool V_26 = true ;
V_196 = V_5 -> V_196 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_186 ) {
if ( V_197 [ V_195 ] . V_198 == V_196 &&
V_197 [ V_195 ] . V_199 == V_5 -> V_200 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_108 ( struct V_1 * V_2 , char * V_201 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_129 , V_202 = 0 ;
for ( V_129 = 0 ; V_129 < V_203 ; ++ V_129 ) {
if ( V_197 [ V_129 ] . V_204 == V_5 -> V_204 &&
V_197 [ V_129 ] . V_6 == V_5 -> V_6 &&
F_107 ( V_2 , V_129 ) ) {
V_202 = 1 ;
break;
}
}
if ( ! V_202 )
sprintf ( V_201 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_201 , L_16 , V_2 -> V_24 ,
V_197 [ V_129 ] . V_205 ) ;
}
static void
F_109 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_206 , V_207 , V_208 , V_209 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_210 * V_211 = & V_4 -> V_211 ;
V_209 = V_2 -> V_212 ;
V_206 = F_94 ( V_2 , V_213 ) ;
V_207 = F_94 ( V_2 , V_214 ) ;
V_208 = F_94 ( V_2 , V_215 ) ;
V_2 -> V_212 = F_110 ( V_206 , V_207 , V_208 ) ;
V_51 = F_111 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_144 != V_179 ) {
if ( V_211 -> V_216 == NULL ||
V_2 -> V_212 > V_209 ) {
if ( V_211 -> V_216 )
F_83 ( V_211 -> V_216 ) ;
if ( ! F_112 ( V_2 ) )
F_68 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_68 ( & V_5 -> V_30 , L_19 ,
V_217 , V_206 , V_207 , V_208 ) ;
if ( V_2 -> V_4 -> V_138 == V_142 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_218 = V_219 ;
V_2 -> V_220 = V_221 ;
} else {
V_2 -> V_218 = V_222 ;
V_2 -> V_220 = V_223 ;
}
V_2 -> V_224 = V_225 ;
V_2 -> V_226 = V_225 ;
} else if ( V_2 -> V_4 -> V_138 == V_139 ) {
V_2 -> V_218 = V_227 ;
V_2 -> V_224 = V_228 ;
V_2 -> V_226 = V_228 ;
V_2 -> V_220 = V_229 ;
}
V_2 -> V_4 -> V_106 = ! ! V_120 ;
V_2 -> V_230 = V_231 ;
V_2 -> V_232 = V_233 ;
}
static int
F_113 ( struct V_1 * V_2 )
{
struct V_234 V_235 ;
int V_51 = 0 ;
memset ( & V_235 , 0 , sizeof( struct V_234 ) ) ;
V_51 = F_114 ( V_2 , & V_235 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_236 = ( T_2 ) V_235 . V_237 ;
V_2 -> V_4 -> V_238 = V_235 . V_238 ;
V_2 -> V_4 -> V_239 = V_235 . V_239 ;
V_2 -> V_4 -> V_240 = V_235 . V_240 ;
V_2 -> V_4 -> V_8 = V_235 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_241 ) {
T_1 V_242 ;
V_242 = F_115 ( V_2 , V_243 , & V_51 ) ;
if ( V_51 == - V_111 )
return V_51 ;
V_2 -> V_4 -> V_78 [ 0 ] = V_242 ;
} else {
V_2 -> V_4 -> V_78 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_244 = V_235 . V_244 ;
V_2 -> V_4 -> V_245 = V_235 . V_245 ;
if ( V_2 -> V_4 -> V_8 & V_246 ) {
V_2 -> V_41 |= V_53 ;
V_2 -> V_4 -> V_247 = V_248 ;
V_2 -> V_89 = V_249 ;
V_2 -> V_87 = V_250 ;
F_68 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_247 = V_251 ;
V_2 -> V_89 = V_252 ;
V_2 -> V_87 = V_85 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_116 ( struct V_1 * V_2 ,
struct V_253 * V_254 )
{
if ( V_254 -> V_255 )
V_2 -> V_41 &= ~ V_256 ;
else
V_2 -> V_41 |= V_256 ;
if ( V_254 -> V_257 ) {
V_2 -> V_258 = V_254 -> V_257 ;
V_2 -> V_259 = V_254 -> V_257 ;
} else {
V_2 -> V_258 = 0 ;
V_2 -> V_259 = 0 ;
}
}
static int
F_117 ( struct V_21 * V_22 , T_5 V_260 , T_3 V_261 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_118 ( V_2 , V_261 , 1 ) ;
if ( V_51 ) {
F_119 ( V_22 ,
L_21 ,
V_261 , V_51 ) ;
return V_51 ;
}
}
F_120 ( V_261 , V_2 -> V_262 ) ;
return 0 ;
}
static int
F_121 ( struct V_21 * V_22 , T_5 V_260 , T_3 V_261 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_2 ) ) {
V_51 = F_118 ( V_2 , V_261 , 0 ) ;
if ( V_51 ) {
F_119 ( V_22 ,
L_22 ,
V_261 , V_51 ) ;
return V_51 ;
}
}
F_122 ( V_22 , V_263 ) ;
F_123 ( V_261 , V_2 -> V_262 ) ;
return 0 ;
}
void F_124 ( struct V_1 * V_2 ,
struct V_253 * V_254 )
{
V_2 -> V_41 &= ~ ( V_264 | V_42 |
V_265 ) ;
if ( V_254 -> V_266 )
V_2 -> V_41 |= V_264 ;
if ( ! V_254 -> V_267 )
V_2 -> V_41 |= V_42 ;
if ( ! V_254 -> V_268 )
V_2 -> V_41 |= V_265 ;
}
int F_125 ( struct V_1 * V_2 )
{
struct V_253 V_254 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_254 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_126 ( V_2 , & V_254 ) )
return - V_111 ;
F_116 ( V_2 , & V_254 ) ;
F_124 ( V_2 , & V_254 ) ;
F_127 ( V_2 , & V_254 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_253 * V_254 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_62 ( V_2 ) )
return;
V_2 -> V_269 = V_254 -> V_269 ;
V_2 -> V_41 |= V_270 ;
F_128 ( V_22 ) ;
V_2 -> V_41 &= ~ V_270 ;
}
static int
F_129 ( struct V_1 * V_2 )
{
T_1 V_144 , V_175 ;
int V_51 = 0 ;
V_51 = F_113 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_271 )
return 0 ;
V_144 = F_94 ( V_2 , V_172 ) ;
V_175 = F_100 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_144 == V_178 )
V_175 = V_145 ;
else
V_175 = F_100 ( V_144 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_175 == V_145 ) {
V_2 -> V_4 -> V_144 = V_145 ;
V_51 = F_90 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_92 ( V_2 ) ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_176 ) ;
} else if ( V_175 == V_272 ) {
V_2 -> V_4 -> V_144 = V_272 ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_176 ) ;
}
} else {
V_2 -> V_4 -> V_247 = V_251 ;
}
V_2 -> V_41 |= V_271 ;
return V_51 ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_253 V_254 ;
struct V_153 * V_273 ;
T_2 V_129 ;
if ( V_2 -> V_274 )
return 0 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_4 -> V_140 ; V_129 ++ ) {
if ( ! V_2 -> V_152 [ V_129 ] . V_161 )
continue;
memset ( & V_254 , 0 , sizeof( struct V_253 ) ) ;
V_254 . V_27 = V_2 -> V_152 [ V_129 ] . V_27 ;
V_254 . V_267 = V_275 ;
V_254 . V_268 = V_275 ;
if ( F_54 ( V_2 ) ) {
V_254 . V_269 = V_275 ;
if ( F_131 ( V_2 ) )
V_254 . V_269 |= ( V_276 | V_277 ) ;
}
if ( F_132 ( V_2 , & V_254 ) )
return - V_111 ;
V_273 = & V_2 -> V_152 [ V_129 ] ;
V_273 -> V_278 = V_254 . V_257 ;
V_273 -> V_267 = V_254 . V_267 ;
V_273 -> V_266 = V_254 . V_266 ;
V_273 -> V_255 = V_254 . V_255 ;
V_273 -> V_268 = V_254 . V_268 ;
V_273 -> V_269 = V_254 . V_269 ;
}
return 0 ;
}
static int
F_133 ( struct V_1 * V_2 ,
struct V_153 * V_273 , int V_27 )
{
struct V_253 V_254 ;
V_254 . V_144 = V_279 ;
V_254 . V_27 = V_27 ;
V_254 . V_257 = V_273 -> V_278 ;
V_254 . V_267 = V_273 -> V_267 ;
V_254 . V_255 = V_273 -> V_255 ;
V_254 . V_266 = V_273 -> V_266 ;
V_254 . V_269 = V_273 -> V_269 ;
V_254 . V_268 = V_273 -> V_268 ;
if ( F_132 ( V_2 , & V_254 ) )
return - V_111 ;
V_254 . V_144 = V_280 ;
if ( F_132 ( V_2 , & V_254 ) )
return - V_111 ;
return 0 ;
}
int F_134 ( struct V_1 * V_2 )
{
int V_129 , V_51 ;
struct V_153 * V_273 ;
struct V_234 V_235 ;
T_2 V_27 ;
if ( F_54 ( V_2 ) )
if ( ! V_2 -> V_274 )
return 0 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_4 -> V_140 ; V_129 ++ ) {
V_273 = & V_2 -> V_152 [ V_129 ] ;
V_27 = V_273 -> V_27 ;
if ( ! V_2 -> V_152 [ V_129 ] . V_161 )
continue;
memset ( & V_235 , 0 , sizeof( struct V_234 ) ) ;
V_51 = F_114 ( V_2 , & V_235 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_235 . V_281 = V_273 -> V_164 ;
V_235 . V_282 = V_273 -> V_166 ;
V_51 = F_135 ( V_2 , & V_235 ) ;
if ( V_51 )
return V_51 ;
if ( V_273 -> V_283 ) {
V_51 = F_136 ( V_2 ,
V_273 -> V_284 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_133 ( V_2 , V_273 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_2 V_285 = V_286 ;
T_1 V_287 ;
if ( V_2 -> V_4 -> V_144 == V_145 )
return 0 ;
V_287 = F_94 ( V_2 ,
V_288 ) ;
while ( V_287 != V_289 && -- V_285 ) {
F_138 ( 1000 ) ;
V_287 = F_94 ( V_2 ,
V_288 ) ;
}
if ( ! V_285 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_111 ;
}
return 0 ;
}
static int
F_139 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_144 != V_145 )
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
goto V_290;
if ( V_291 )
F_143 ( V_2 ) ;
else {
V_51 = F_144 ( V_2 ) ;
if ( V_51 )
goto V_292;
V_2 -> V_4 -> V_293 = V_294 ;
}
V_51 = F_145 ( V_2 ) ;
if ( V_51 == 0 )
goto V_290;
V_51 = F_146 ( V_2 ) ;
if ( V_51 )
goto V_292;
V_51 = F_147 ( V_2 ) ;
if ( V_51 )
goto V_292;
F_148 ( V_2 ) ;
F_149 ( V_2 , V_295 , V_296 ) ;
V_290:
V_51 = F_150 ( V_2 ) ;
if ( V_51 )
goto V_292;
F_96 ( V_2 , V_297 , V_298 ) ;
F_151 ( V_2 , 1 ) ;
V_51 = F_129 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_292;
}
V_51 = F_139 ( V_2 ) ;
if ( V_51 )
goto V_292;
F_109 ( V_2 ) ;
V_2 -> V_274 = 0 ;
F_148 ( V_2 ) ;
return 0 ;
V_292:
F_96 ( V_2 , V_297 , V_299 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_148 ( V_2 ) ;
return V_51 ;
}
static int
F_152 ( struct V_1 * V_2 )
{
T_8 V_300 ;
struct V_18 * V_301 ;
struct V_10 * V_11 ;
int V_51 , V_302 , V_303 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_130 == V_304 ) {
if ( F_54 ( V_2 ) )
V_300 = V_305 ;
else
V_300 = V_306 ;
if ( ! F_153 ( V_2 ) )
V_41 |= V_307 ;
} else {
if ( V_2 -> V_41 & V_105 )
V_300 = V_308 ;
else if ( V_2 -> V_41 & V_104 )
V_300 = V_309 ;
else {
V_41 |= V_307 ;
if ( F_54 ( V_2 ) )
V_300 = V_310 ;
else
V_300 = V_311 ;
}
}
V_2 -> V_119 = V_22 -> V_119 ;
if ( V_2 -> V_4 -> V_130 != V_312 ) {
if ( F_54 ( V_2 ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) ) ) {
V_303 = V_2 -> V_93 ;
for ( V_302 = 0 ; V_302 < V_303 ; V_302 ++ ) {
V_301 = & V_15 -> V_19 [ V_302 ] ;
if ( F_54 ( V_2 ) &&
! F_70 ( V_2 ) &&
( V_302 == ( V_303 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_105 ) )
snprintf ( V_301 -> V_201 ,
sizeof( V_301 -> V_201 ) ,
L_28 ) ;
else
snprintf ( V_301 -> V_201 ,
sizeof( V_301 -> V_201 ) ,
L_29 ,
V_22 -> V_201 , V_302 ) ;
} else {
snprintf ( V_301 -> V_201 ,
sizeof( V_301 -> V_201 ) ,
L_30 ,
V_22 -> V_201 , V_302 ) ;
}
V_51 = F_154 ( V_301 -> V_119 , V_300 , V_41 ,
V_301 -> V_201 , V_301 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_54 ( V_2 ) &&
F_70 ( V_2 ) ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) &&
! ( V_2 -> V_41 & V_313 ) ) ) {
V_300 = V_314 ;
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ;
V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
snprintf ( V_11 -> V_201 , sizeof( V_11 -> V_201 ) ,
L_31 , V_22 -> V_201 , V_302 ) ;
V_51 = F_154 ( V_11 -> V_119 , V_300 , V_41 ,
V_11 -> V_201 , V_11 ) ;
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
int V_302 ;
struct V_18 * V_301 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_130 != V_312 ) {
if ( F_54 ( V_2 ) ||
( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_105 ) ) ) {
for ( V_302 = 0 ; V_302 < V_2 -> V_93 ; V_302 ++ ) {
V_301 = & V_15 -> V_19 [ V_302 ] ;
F_156 ( V_301 -> V_119 , V_301 ) ;
}
}
if ( ( F_62 ( V_2 ) &&
! ( V_2 -> V_41 & V_313 ) ) ||
( F_54 ( V_2 ) &&
F_70 ( V_2 ) ) ) {
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ;
V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
if ( V_11 -> V_119 )
F_156 ( V_11 -> V_119 , V_11 ) ;
}
}
}
}
static void F_157 ( struct V_1 * V_2 )
{
T_1 V_315 = 0 ;
if ( F_54 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_78 [ 0 ] &
V_316 )
V_2 -> V_41 |= V_317 ;
} else {
V_315 = V_2 -> V_4 -> V_8 ;
if ( F_158 ( V_315 ) )
V_2 -> V_41 |= V_317 ;
}
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 ;
V_4 -> V_318 . V_319 = V_320 ;
if ( F_62 ( V_2 ) ) {
V_4 -> V_318 . type = V_321 ;
V_4 -> V_318 . V_322 = V_323 ;
V_4 -> V_318 . V_324 = V_325 ;
V_4 -> V_318 . V_326 = V_327 ;
V_4 -> V_318 . V_328 = V_329 ;
V_51 = F_160 ( V_2 ) ;
} else {
V_4 -> V_318 . type = V_330 ;
V_4 -> V_318 . V_326 = V_327 ;
V_4 -> V_318 . V_328 = V_329 ;
V_51 = F_161 ( V_2 ) ;
}
return V_51 ;
}
int F_162 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_302 ;
struct V_331 * V_332 ;
if ( V_2 -> V_333 != V_334 )
return - V_111 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_125 ( V_2 ) )
return - V_111 ;
F_157 ( V_2 ) ;
if ( F_163 ( V_2 ) )
return - V_111 ;
for ( V_302 = 0 ; V_302 < V_2 -> V_232 ; V_302 ++ ) {
V_332 = & V_2 -> V_15 -> V_335 [ V_302 ] ;
F_164 ( V_2 , V_332 , V_302 ) ;
}
F_24 ( V_22 ) ;
F_165 ( V_2 , V_22 -> V_336 ) ;
V_2 -> V_4 -> V_337 = 0 ;
if ( V_2 -> V_93 > 1 )
F_166 ( V_2 , 1 ) ;
F_159 ( V_2 ) ;
if ( V_22 -> V_338 & V_339 )
F_167 ( V_2 , V_340 ) ;
F_120 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_168 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_341 = 0 ;
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
int V_302 ;
if ( V_2 -> V_333 != V_334 )
return;
if ( ! F_175 ( V_45 , & V_2 -> V_46 ) )
return;
F_176 () ;
F_177 ( V_22 ) ;
V_2 -> V_4 -> V_337 = 0 ;
F_178 ( V_22 ) ;
F_179 ( V_2 ) ;
if ( V_2 -> V_342 . V_343 )
F_180 ( V_2 ) ;
F_181 ( V_2 , V_344 ) ;
if ( F_20 ( V_2 ) )
F_182 ( & V_2 -> V_4 -> V_345 -> V_346 ) ;
F_23 ( V_2 ) ;
F_183 ( V_2 ) ;
V_2 -> V_41 &= ~ V_317 ;
F_184 ( V_2 ) ;
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ )
F_185 ( V_2 , & V_2 -> V_11 [ V_302 ] ) ;
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
if ( V_2 -> V_333 == V_334 )
return 0 ;
V_51 = F_188 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_189 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_32 ) ;
goto V_347;
}
V_51 = F_190 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_33 ) ;
goto V_348;
}
V_51 = F_152 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_34 ) ;
goto V_349;
}
F_191 ( V_2 ) ;
#ifdef F_192
if ( F_50 ( V_2 ) )
F_193 ( V_22 ) ;
#endif
V_2 -> V_333 = V_334 ;
return 0 ;
V_349:
F_194 ( V_2 ) ;
V_348:
F_195 ( V_2 ) ;
V_347:
F_196 ( V_2 ) ;
return V_51 ;
}
void F_197 ( struct V_1 * V_2 )
{
if ( V_2 -> V_333 != V_334 )
return;
F_198 ( V_2 ) ;
F_194 ( V_2 ) ;
F_199 ( V_2 ) ;
F_155 ( V_2 ) ;
F_196 ( V_2 ) ;
F_195 ( V_2 ) ;
V_2 -> V_333 = 0 ;
}
void F_200 ( struct V_21 * V_22 , int V_93 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_301 ;
int V_91 = V_2 -> V_91 ;
int V_302 ;
F_123 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_130 == V_304 ) {
for ( V_302 = 0 ; V_302 < V_2 -> V_93 ; V_302 ++ ) {
V_301 = & V_2 -> V_15 -> V_19 [ V_302 ] ;
F_201 ( V_2 , V_301 ) ;
}
}
F_183 ( V_2 ) ;
F_197 ( V_2 ) ;
V_2 -> V_4 -> V_130 = 0 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_91 = V_91 ;
if ( F_187 ( V_2 ) )
goto V_350;
if ( F_172 ( V_22 ) )
F_162 ( V_2 , V_22 ) ;
V_350:
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
goto V_292;
}
if ( F_62 ( V_2 ) ) {
V_4 -> V_318 . type = V_321 ;
V_4 -> V_318 . V_322 = V_323 ;
V_4 -> V_318 . V_324 = V_325 ;
V_4 -> V_318 . V_326 = V_327 ;
V_4 -> V_318 . V_328 = V_329 ;
} else {
V_4 -> V_318 . type = V_330 ;
V_4 -> V_318 . V_326 = V_327 ;
V_4 -> V_318 . V_328 = V_329 ;
}
memset ( & V_2 -> V_351 , 0 , sizeof( V_2 -> V_351 ) ) ;
V_292:
return V_51 ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_210 * V_211 = & V_2 -> V_4 -> V_211 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_211 -> V_216 ) {
F_83 ( V_211 -> V_216 ) ;
V_211 -> V_216 = NULL ;
}
if ( V_211 -> V_352 ) {
F_204 ( & V_2 -> V_5 -> V_30 , V_353 ,
V_211 -> V_352 , V_211 -> V_354 ) ;
V_211 -> V_352 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_355 . V_356 ) ;
V_2 -> V_4 -> V_211 . V_216 = NULL ;
}
int F_205 ( struct V_21 * V_22 , int V_357 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_301 ;
struct V_331 * V_332 ;
int V_302 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
V_2 -> V_93 = V_110 ;
V_2 -> V_4 -> V_130 = V_357 ;
V_2 -> V_4 -> V_337 = 0 ;
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
for ( V_302 = 0 ; V_302 < V_2 -> V_232 ; V_302 ++ ) {
V_332 = & V_2 -> V_15 -> V_335 [ V_302 ] ;
F_164 ( V_2 , V_332 , V_302 ) ;
}
if ( V_2 -> V_4 -> V_130 == V_304 ) {
for ( V_302 = 0 ; V_302 < V_2 -> V_93 ; V_302 ++ ) {
V_301 = & V_2 -> V_15 -> V_19 [ V_302 ] ;
F_206 ( V_2 , V_301 ) ;
}
}
if ( V_2 -> V_4 -> V_130 == V_312 ) {
V_2 -> V_4 -> V_358 = 0 ;
F_168 ( V_2 , 1 ) ;
}
F_120 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_207 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_63 , & V_2 -> V_46 ) )
return - V_359 ;
F_22 ( V_22 ) ;
F_186 ( V_2 , V_22 ) ;
F_170 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
F_65 ( V_2 -> V_22 , L_35 , V_54 ) ;
return 0 ;
}
int
F_208 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_63 , & V_2 -> V_46 ) )
return - V_359 ;
if ( V_2 -> V_333 == V_334 ) {
F_22 ( V_22 ) ;
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( ! V_51 ) {
F_162 ( V_2 , V_22 ) ;
F_122 ( V_22 , V_360 ) ;
}
}
F_25 ( V_22 ) ;
}
F_123 ( V_63 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_361 = V_4 -> V_140 ;
T_3 V_16 ;
V_4 -> V_362 = V_363 ;
if ( V_361 <= 2 )
V_16 = ( V_364 - V_363 ) /
V_361 ;
else
V_16 = ( V_365 - V_363 ) /
V_361 ;
V_4 -> V_55 = V_16 ;
}
static int F_210 ( struct V_1 * V_2 ,
T_2 V_366 , T_2 V_367 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 = 0 ;
if ( V_366 ) {
V_51 = F_211 ( V_22 , V_366 ) ;
if ( V_51 ) {
F_119 ( V_22 , L_36 ,
V_366 ) ;
return V_51 ;
}
}
if ( V_367 ) {
V_51 = F_212 ( V_22 , V_367 ) ;
if ( V_51 )
F_119 ( V_22 , L_37 ,
V_367 ) ;
}
return V_51 ;
}
int
F_213 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_368 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_369 = 1 ;
V_2 -> V_4 -> V_370 = 0 ;
F_214 ( V_2 ) ;
V_22 -> V_371 = & V_372 ;
V_22 -> V_373 = V_374 * V_375 ;
F_215 ( V_22 , V_22 -> V_336 ) ;
V_22 -> V_376 = ( F_20 ( V_2 ) ) ?
& V_377 : & V_378 ;
V_22 -> V_338 |= ( V_379 | V_380 | V_381 |
V_382 | V_383 |
V_384 ) ;
V_22 -> V_385 |= ( V_379 | V_380 |
V_382 ) ;
if ( F_131 ( V_2 ) ) {
V_22 -> V_338 |= ( V_386 | V_387 ) ;
V_22 -> V_385 |= ( V_386 | V_387 ) ;
}
if ( V_368 ) {
V_22 -> V_338 |= V_388 ;
V_22 -> V_385 |= V_388 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_338 |= ( V_389 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_338 |= V_390 ;
if ( V_2 -> V_4 -> V_8 & V_391 )
V_22 -> V_338 |= V_339 ;
if ( F_216 ( V_2 ) ) {
V_22 -> V_338 |= V_392 ;
V_22 -> V_393 = V_380 |
V_392 |
V_386 |
V_387 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_393 |= V_381 ;
V_22 -> V_394 = V_22 -> V_338 ;
V_22 -> V_395 |= V_396 ;
V_22 -> V_119 = V_2 -> V_99 [ 0 ] . V_95 ;
V_51 = F_210 ( V_2 , V_2 -> V_91 ,
V_2 -> V_93 ) ;
if ( V_51 )
return V_51 ;
F_217 ( V_2 -> V_397 ) ;
V_51 = F_218 ( V_22 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_38 ) ;
return V_51 ;
}
return 0 ;
}
static int F_219 ( struct V_23 * V_5 , int * V_368 )
{
if ( ! F_220 ( V_5 , F_221 ( 64 ) ) &&
! F_222 ( V_5 , F_221 ( 64 ) ) )
* V_368 = 1 ;
else if ( ! F_220 ( V_5 , F_221 ( 32 ) ) &&
! F_222 ( V_5 , F_221 ( 32 ) ) )
* V_368 = 0 ;
else {
F_80 ( & V_5 -> V_30 , L_39 ) ;
return - V_111 ;
}
return 0 ;
}
void F_223 ( struct V_1 * V_2 )
{
int V_302 ;
struct V_10 * V_11 ;
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
if ( V_11 && V_11 -> V_398 != NULL ) {
F_83 ( V_11 -> V_398 ) ;
V_11 -> V_398 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_224 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_302 , V_95 , V_195 ;
struct V_10 * V_11 ;
struct V_399 * V_398 ;
V_11 = F_63 ( V_2 -> V_91 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
V_11 -> V_400 = V_2 -> V_230 ;
V_11 -> V_401 = F_225 ( V_22 , V_302 ) ;
V_398 = F_78 ( F_226 ( V_11 ) ) ;
if ( V_398 == NULL ) {
F_223 ( V_2 ) ;
return - V_56 ;
}
memset ( V_398 , 0 , F_226 ( V_11 ) ) ;
V_11 -> V_398 = V_398 ;
F_227 ( & V_11 -> V_402 ) ;
}
if ( F_62 ( V_2 ) ||
( F_54 ( V_2 ) && F_70 ( V_2 ) ) ) {
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_105 ) {
V_195 = V_2 -> V_93 + V_302 ;
V_95 = V_2 -> V_99 [ V_195 ] . V_95 ;
V_11 -> V_119 = V_95 ;
}
}
}
return 0 ;
}
void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_403 = 0 ;
if ( F_54 ( V_2 ) )
V_403 = V_404 ;
else if ( F_62 ( V_2 ) )
V_403 = V_405 ;
if ( V_4 -> V_78 [ 0 ] & V_406 )
F_229 ( V_2 , V_403 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
F_93 ( V_2 ) ;
F_97 ( V_2 ) ;
}
static int
F_231 ( struct V_23 * V_5 , const struct V_173 * V_174 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_368 = - 1 ;
char V_407 [ V_408 + 19 ] ;
V_51 = F_232 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_233 ( V_5 , 0 ) & V_409 ) ) {
V_51 = - V_410 ;
goto V_411;
}
V_51 = F_219 ( V_5 , & V_368 ) ;
if ( V_51 )
goto V_411;
V_51 = F_234 ( V_5 , V_412 ) ;
if ( V_51 )
goto V_411;
F_235 ( V_5 ) ;
F_236 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_413;
}
switch ( V_174 -> V_6 ) {
case V_7 :
V_4 -> V_414 = & V_415 ;
V_4 -> V_416 = ( T_1 * ) V_417 ;
break;
case V_186 :
case V_187 :
F_237 ( V_4 ) ;
break;
case V_188 :
case V_189 :
F_238 ( V_4 ) ;
break;
default:
goto V_418;
}
V_51 = F_102 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_418;
V_22 = F_239 ( sizeof( struct V_1 ) ,
V_419 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_420;
}
F_240 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_421 = F_241 ( L_28 ) ;
if ( V_2 -> V_421 == NULL ) {
V_51 = - V_56 ;
F_80 ( & V_5 -> V_30 , L_40 ) ;
goto V_422;
}
V_51 = F_202 ( V_2 ) ;
if ( V_51 )
goto V_423;
V_2 -> V_424 = V_425 ;
V_4 -> V_426 = V_5 -> V_427 ;
V_4 -> V_146 = F_242 ( V_2 ) ;
if ( V_428 == V_429 )
V_2 -> V_52 = true ;
else if ( V_428 == V_430 )
V_2 -> V_431 = true ;
F_243 ( & V_2 -> V_4 -> V_432 ) ;
F_244 ( & V_2 -> V_4 -> V_433 ) ;
F_245 ( & V_2 -> V_434 ) ;
F_246 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
F_98 ( V_2 , V_174 ) ;
V_2 -> V_435 = V_2 -> V_4 -> V_27 ;
F_230 ( V_2 ) ;
V_51 = F_247 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_436;
}
if ( V_2 -> V_4 -> V_106 ) {
if ( F_53 ( V_2 ) == 1 )
F_59 ( V_2 ,
V_110 ) ;
else
F_59 ( V_2 ,
V_437 ) ;
F_60 ( V_2 ,
V_438 ) ;
} else {
F_59 ( V_2 , V_110 ) ;
F_60 ( V_2 , V_110 ) ;
}
V_51 = F_248 ( V_2 ) ;
if ( V_51 )
goto V_349;
V_2 -> V_41 |= V_439 ;
} else if ( F_62 ( V_2 ) ) {
F_249 ( V_2 , V_174 ) ;
V_2 -> V_435 = V_2 -> V_4 -> V_27 ;
V_51 = F_250 ( V_2 , V_368 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_440 :
F_80 ( & V_5 -> V_30 , L_43 ) ;
F_80 ( & V_5 -> V_30 , L_44 ) ;
goto V_349;
case - V_56 :
F_80 ( & V_5 -> V_30 , L_45 ) ;
goto V_349;
case - V_43 :
F_80 ( & V_5 -> V_30 , L_46 ) ;
goto V_349;
default:
F_80 ( & V_5 -> V_30 , L_47 ) ;
goto V_436;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_80 ( & V_5 -> V_30 ,
L_48 , V_54 ) ;
goto V_349;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_251 ( V_2 ) ;
if ( V_2 -> V_435 == 0 ) {
F_108 ( V_2 , V_407 ) ;
F_37 ( L_50 ,
F_252 ( V_441 ) ,
V_407 , V_2 -> V_4 -> V_426 ) ;
}
if ( F_62 ( V_2 ) && ! V_120 &&
! ! V_116 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_54 ( V_2 ) ) {
F_253 ( V_2 -> V_397 ) ;
F_254 ( V_2 -> V_397 ) ;
V_51 = F_255 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_52 ) ;
goto V_442;
}
}
V_51 = F_86 ( V_2 ) ;
if ( V_51 )
goto V_443;
if ( V_2 -> V_435 == 0 )
F_228 ( V_2 ) ;
V_51 = F_213 ( V_2 , V_22 , V_368 ) ;
if ( V_51 )
goto V_443;
F_256 ( V_5 , V_2 ) ;
if ( F_54 ( V_2 ) )
F_257 ( V_2 , V_444 ,
V_445 ) ;
switch ( V_2 -> V_4 -> V_138 ) {
case V_139 :
F_68 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_201 ) ;
break;
case V_142 :
F_68 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_201 ) ;
break;
}
if ( V_2 -> V_431 )
F_258 ( V_2 ) ;
F_259 ( V_2 ) ;
F_260 ( V_2 ) ;
return 0 ;
V_443:
if ( F_62 ( V_2 ) )
F_261 ( V_2 ) ;
V_442:
F_81 ( V_2 ) ;
F_262 ( V_2 ) ;
F_263 ( V_2 , 0 ) ;
V_349:
F_203 ( V_2 ) ;
V_423:
F_264 ( V_2 -> V_421 ) ;
V_422:
F_265 ( V_22 ) ;
V_420:
F_84 ( V_4 ) ;
V_418:
F_7 ( V_4 ) ;
V_413:
F_266 ( V_5 ) ;
V_411:
F_267 ( V_5 ) ;
return V_51 ;
V_436:
F_120 ( V_446 , & V_2 -> V_46 ) ;
V_22 -> V_371 = & V_447 ;
V_22 -> V_376 = & V_448 ;
V_4 -> V_138 = V_142 ;
if ( F_62 ( V_2 ) )
V_2 -> V_118 = NULL ;
else
V_4 -> V_449 = V_450 ;
V_51 = F_218 ( V_22 ) ;
if ( V_51 ) {
F_80 ( & V_5 -> V_30 , L_55 ) ;
F_263 ( V_2 , 0 ) ;
goto V_349;
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
F_47 ( & V_2 -> V_451 ) ;
F_261 ( V_2 ) ;
F_274 ( V_2 ) ;
F_275 ( V_4 -> V_452 ) ;
F_7 ( V_4 -> V_453 ) ;
}
F_276 ( V_2 -> V_397 ) ;
F_197 ( V_2 ) ;
if ( V_2 -> V_152 != NULL )
F_7 ( V_2 -> V_152 ) ;
if ( V_2 -> V_154 != NULL )
F_7 ( V_2 -> V_154 ) ;
if ( F_54 ( V_2 ) )
F_263 ( V_2 , 0 ) ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
F_277 ( V_2 ) ;
F_81 ( V_2 ) ;
F_278 ( V_2 ) ;
F_279 ( V_2 ) ;
F_84 ( V_2 -> V_4 ) ;
F_148 ( V_2 ) ;
F_280 ( V_5 ) ;
F_266 ( V_5 ) ;
F_267 ( V_5 ) ;
if ( V_2 -> V_421 ) {
F_264 ( V_2 -> V_421 ) ;
V_2 -> V_421 = NULL ;
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
int V_454 ;
V_454 = F_282 ( V_5 ) ;
if ( V_454 )
return V_454 ;
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
F_284 ( V_5 , V_455 ) ;
F_235 ( V_5 ) ;
F_287 ( V_5 ) ;
return F_288 ( V_2 ) ;
}
static int F_289 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_51 ;
if ( F_21 ( V_446 , & V_2 -> V_46 ) ) {
F_119 ( V_22 , L_56 ,
V_54 ) ;
return - V_111 ;
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
int V_129 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_456 = 0 ;
T_3 V_149 = 0 ;
if ( V_2 -> V_342 . V_457 && V_2 -> V_342 . V_458 )
return;
V_149 = V_2 -> V_4 -> V_140 ;
F_227 ( & V_2 -> V_459 ) ;
F_227 ( & V_2 -> V_460 ) ;
if ( F_20 ( V_2 ) ) {
V_456 = V_461 - 1 ;
V_2 -> V_342 . V_462 = V_463 ;
} else if ( F_54 ( V_2 ) ) {
V_456 = V_365 ;
V_2 -> V_342 . V_462 = V_464 ;
} else {
V_456 = V_465 ;
V_2 -> V_342 . V_462 = V_466 ;
}
V_34 = F_63 ( V_2 -> V_342 . V_462 ,
sizeof( struct V_467 ) , V_468 ) ;
if ( ! V_34 )
return;
V_2 -> V_342 . V_457 = ( V_456 / V_149 ) ;
V_2 -> V_342 . V_458 = V_34 ;
F_65 ( V_22 , L_57 ,
V_149 , V_2 -> V_342 . V_457 ) ;
for ( V_129 = 0 ; V_129 < V_2 -> V_342 . V_462 ; V_129 ++ )
F_291 ( & V_2 -> V_342 . V_458 [ V_129 ] ) ;
V_2 -> V_469 . V_462 = V_2 -> V_342 . V_462 ;
V_34 = F_63 ( V_2 -> V_469 . V_462 ,
sizeof( struct V_467 ) , V_468 ) ;
if ( ! V_34 )
return;
V_2 -> V_469 . V_457 = ( V_456 / V_149 ) ;
V_2 -> V_469 . V_458 = V_34 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_469 . V_462 ; V_129 ++ )
F_291 ( & V_2 -> V_469 . V_458 [ V_129 ] ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
if ( V_2 -> V_342 . V_457 && V_2 -> V_342 . V_458 )
F_7 ( V_2 -> V_342 . V_458 ) ;
V_2 -> V_342 . V_458 = NULL ;
V_2 -> V_342 . V_457 = 0 ;
if ( V_2 -> V_469 . V_457 && V_2 -> V_469 . V_458 )
F_7 ( V_2 -> V_469 . V_458 ) ;
V_2 -> V_469 . V_457 = 0 ;
V_2 -> V_469 . V_458 = NULL ;
}
int F_292 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_470 , V_471 , V_242 = 0 ;
int V_472 = 0 ;
if ( F_62 ( V_2 ) )
V_242 = F_293 ( V_2 -> V_4 , V_473 ) ;
if ( F_54 ( V_2 ) )
V_242 = F_94 ( V_2 , V_474 ) ;
V_470 = F_294 ( V_242 ) ;
V_471 = F_295 ( V_242 ) ;
if ( V_470 == V_475 ) {
F_80 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_471 ) ;
V_472 = 1 ;
} else if ( V_470 == V_476 ) {
if ( V_2 -> V_4 -> V_242 == V_477 ) {
F_80 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_471 ) ;
}
} else {
if ( V_2 -> V_4 -> V_242 == V_476 ) {
F_68 ( & V_22 -> V_30 ,
L_63
L_64 , V_471 ) ;
}
}
V_2 -> V_4 -> V_242 = V_470 ;
return V_472 ;
}
static inline void F_296 ( struct V_10 * V_11 )
{
int V_129 ;
struct V_478 * V_479 ;
for ( V_129 = 0 ; V_129 < V_11 -> V_400 ; V_129 ++ ) {
V_479 = & V_11 -> V_480 [ V_129 ] ;
F_37 ( L_65 , V_129 ) ;
F_297 ( V_481 , L_66 , V_482 , 16 , 1 ,
& V_11 -> V_480 [ V_129 ] ,
sizeof( struct V_478 ) , true ) ;
}
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_331 * V_332 ;
struct V_18 * V_301 ;
struct V_10 * V_11 ;
int V_302 ;
if ( ! V_22 || ! F_172 ( V_22 ) )
return;
for ( V_302 = 0 ; V_302 < V_2 -> V_232 ; V_302 ++ ) {
V_332 = & V_15 -> V_335 [ V_302 ] ;
if ( ! V_332 )
continue;
F_65 ( V_22 ,
L_67 ,
V_302 , F_299 ( V_332 -> V_483 ) ,
V_332 -> V_12 , V_332 -> V_400 ) ;
}
for ( V_302 = 0 ; V_302 < V_2 -> V_93 ; V_302 ++ ) {
V_301 = & ( V_15 -> V_19 [ V_302 ] ) ;
if ( ! V_301 )
continue;
F_65 ( V_22 ,
L_68 ,
V_302 , F_299 ( V_301 -> V_484 ) ,
V_301 -> V_485 , F_299 ( V_301 -> V_486 ) ,
V_301 -> V_400 ) ;
}
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
if ( ! V_11 )
continue;
F_65 ( V_22 , L_69 ,
V_302 , V_11 -> V_487 ) ;
F_65 ( V_22 ,
L_70 ,
V_11 -> V_488 . V_489 ,
V_11 -> V_488 . V_490 ,
V_11 -> V_488 . V_491 ,
V_11 -> V_488 . V_492 ) ;
if ( V_11 -> V_486 )
F_65 ( V_22 , L_71 ,
F_299 ( V_11 -> V_486 ) ) ;
F_65 ( V_22 ,
L_72 ,
F_299 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_493 ,
F_300 ( * ( V_11 -> V_494 ) ) ) ;
F_65 ( V_22 , L_73 ,
V_11 -> V_400 , F_301 ( V_11 ) ) ;
if ( F_302 ( V_2 -> V_4 ) )
F_296 ( V_11 ) ;
}
}
static void F_303 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
return;
F_298 ( V_2 ) ;
if ( ++ V_2 -> V_495 >= V_496 ||
F_302 ( V_2 -> V_4 ) ) {
F_119 ( V_22 , L_74 ) ;
if ( F_54 ( V_2 ) )
V_2 -> V_274 = 1 ;
else if ( F_62 ( V_2 ) )
F_304 ( V_2 ,
V_497 ) ;
} else {
F_119 ( V_22 , L_75 ) ;
V_2 -> V_4 -> V_341 = 1 ;
}
}
static struct V_498 * F_305 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_498 * V_351 = & V_22 -> V_351 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_306 ( V_2 ) ;
V_351 -> V_328 = V_2 -> V_351 . V_499 + V_2 -> V_351 . V_500 ;
V_351 -> V_324 = V_2 -> V_351 . V_501 ;
V_351 -> V_502 = V_2 -> V_351 . V_503 + V_2 -> V_351 . V_504 ;
V_351 -> V_505 = V_2 -> V_351 . V_506 ;
V_351 -> V_507 = V_2 -> V_351 . V_508 ;
V_351 -> V_509 = V_2 -> V_351 . V_510 ;
return V_351 ;
}
static T_10 F_307 ( struct V_1 * V_2 )
{
T_1 V_511 ;
V_511 = F_299 ( V_2 -> V_124 ) ;
if ( ! ( V_511 & V_2 -> V_4 -> V_122 ) )
return V_512 ;
V_511 = F_299 ( V_2 -> V_126 ) ;
if ( ! F_308 ( V_511 ) )
return V_512 ;
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
F_299 ( V_2 -> V_124 ) ;
F_299 ( V_2 -> V_124 ) ;
return V_513 ;
}
static T_10 V_305 ( int V_119 , void * V_170 )
{
struct V_18 * V_301 = V_170 ;
struct V_1 * V_2 = V_301 -> V_2 ;
if ( V_2 -> V_41 & V_105 )
goto V_514;
else if ( V_2 -> V_41 & V_104 ) {
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
goto V_514;
}
if ( F_309 ( V_2 ) == V_512 )
return V_512 ;
V_514:
V_2 -> V_4 -> V_515 ++ ;
F_206 ( V_2 , V_301 ) ;
return V_513 ;
}
static T_10 V_310 ( int V_119 , void * V_170 )
{
struct V_18 * V_301 = V_170 ;
struct V_1 * V_2 = V_301 -> V_2 ;
if ( F_309 ( V_2 ) == V_512 )
return V_512 ;
F_310 ( & V_301 -> V_516 ) ;
return V_513 ;
}
static T_10 V_309 ( int V_119 , void * V_170 )
{
struct V_18 * V_301 = V_170 ;
struct V_1 * V_2 = V_301 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_118 ) ;
F_310 ( & V_301 -> V_516 ) ;
return V_513 ;
}
static T_10 V_308 ( int V_119 , void * V_170 )
{
struct V_18 * V_301 = V_170 ;
F_310 ( & V_301 -> V_516 ) ;
return V_513 ;
}
static T_10 V_314 ( int V_119 , void * V_170 )
{
struct V_10 * V_11 = V_170 ;
F_310 ( & V_11 -> V_516 ) ;
return V_513 ;
}
static void F_311 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_301 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_302 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_302 = 0 ; V_302 < V_2 -> V_93 ; V_302 ++ ) {
V_301 = & V_15 -> V_19 [ V_302 ] ;
F_201 ( V_2 , V_301 ) ;
F_310 ( & V_301 -> V_516 ) ;
}
if ( V_2 -> V_41 & V_105 ) {
if ( ( F_62 ( V_2 ) &&
( V_2 -> V_41 & V_313 ) ) ||
( F_54 ( V_2 ) &&
! F_70 ( V_2 ) ) )
return;
for ( V_302 = 0 ; V_302 < V_2 -> V_91 ; V_302 ++ ) {
V_11 = & V_2 -> V_11 [ V_302 ] ;
F_312 ( V_2 , V_11 ) ;
F_310 ( & V_11 -> V_516 ) ;
}
}
}
static void
F_151 ( struct V_1 * V_2 , T_2 V_517 )
{
T_1 V_518 ;
V_518 = V_2 -> V_435 & 0xf ;
V_518 |= V_517 << 7 ;
V_518 |= ( V_425 - V_2 -> V_424 ) << 8 ;
F_96 ( V_2 , V_519 , V_518 ) ;
V_2 -> V_424 = V_425 ;
}
static int
F_313 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_518 ;
F_314 ( V_46 != V_520 &&
V_46 != V_521 ) ;
if ( F_93 ( V_2 ) )
return - V_111 ;
V_518 = F_94 ( V_2 , V_522 ) ;
if ( V_46 == V_520 )
F_315 ( V_518 , V_2 -> V_435 ) ;
else if ( V_46 == V_521 )
F_316 ( V_518 , V_2 -> V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int
F_317 ( struct V_1 * V_2 )
{
T_1 V_518 ;
if ( F_93 ( V_2 ) )
return - V_359 ;
V_518 = F_94 ( V_2 , V_522 ) ;
F_318 ( V_518 , V_2 -> V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
void F_263 ( struct V_1 * V_2 , T_2 V_523 )
{
T_1 V_518 ;
if ( F_93 ( V_2 ) )
goto V_51;
V_518 = F_94 ( V_2 , V_524 ) ;
F_319 ( V_518 , V_2 -> V_435 ) ;
F_96 ( V_2 , V_524 , V_518 ) ;
if ( V_523 ) {
F_96 ( V_2 , V_297 ,
V_299 ) ;
F_68 ( & V_2 -> V_5 -> V_30 ,
L_76 ) ;
} else if ( ! ( V_518 & 0x11111111 ) )
F_96 ( V_2 , V_297 ,
V_525 ) ;
V_518 = F_94 ( V_2 , V_522 ) ;
F_318 ( V_518 , V_2 -> V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
F_97 ( V_2 ) ;
V_51:
V_2 -> V_526 = 0 ;
V_2 -> V_41 &= ~ V_527 ;
F_123 ( V_528 , & V_2 -> V_46 ) ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
}
static int
F_320 ( struct V_1 * V_2 )
{
int V_529 , V_46 , V_530 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_94 ( V_2 , V_522 ) ;
V_529 = F_94 ( V_2 , V_524 ) ;
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
static int F_321 ( struct V_1 * V_2 )
{
T_1 V_518 = F_94 ( V_2 , V_532 ) ;
if ( V_518 != V_533 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_533 , V_518 ) ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
T_1 V_518 , V_534 ;
T_2 V_535 = V_2 -> V_535 ;
T_2 V_435 = V_2 -> V_435 ;
T_2 V_26 ;
if ( F_175 ( V_528 , & V_2 -> V_46 ) )
return 1 ;
if ( F_93 ( V_2 ) )
return - 1 ;
V_518 = F_94 ( V_2 , V_524 ) ;
if ( ! ( V_518 & ( 1 << ( V_435 * 4 ) ) ) ) {
F_322 ( V_518 , V_435 ) ;
F_96 ( V_2 , V_524 , V_518 ) ;
}
V_534 = F_94 ( V_2 , V_297 ) ;
F_323 ( V_2 , V_536 , L_79 , V_534 ) ;
switch ( V_534 ) {
case V_525 :
F_96 ( V_2 , V_297 ,
V_537 ) ;
F_96 ( V_2 , V_532 ,
V_533 ) ;
F_151 ( V_2 , 0 ) ;
F_97 ( V_2 ) ;
return 1 ;
case V_298 :
V_26 = F_321 ( V_2 ) ;
F_97 ( V_2 ) ;
return V_26 ;
case V_520 :
V_518 = F_94 ( V_2 , V_522 ) ;
F_315 ( V_518 , V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
break;
case V_521 :
V_518 = F_94 ( V_2 , V_522 ) ;
F_316 ( V_518 , V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
break;
case V_299 :
F_80 ( & V_2 -> V_5 -> V_30 , L_80 ) ;
F_97 ( V_2 ) ;
return - 1 ;
case V_537 :
case V_538 :
break;
}
F_97 ( V_2 ) ;
do {
F_138 ( 1000 ) ;
V_534 = F_94 ( V_2 , V_297 ) ;
if ( V_534 == V_538 )
continue;
} while ( ( V_534 != V_298 ) && -- V_535 );
if ( ! V_535 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_81 ) ;
return - 1 ;
}
if ( F_93 ( V_2 ) )
return - 1 ;
V_518 = F_94 ( V_2 , V_522 ) ;
F_318 ( V_518 , V_435 ) ;
F_96 ( V_2 , V_522 , V_518 ) ;
V_26 = F_321 ( V_2 ) ;
F_97 ( V_2 ) ;
return V_26 ;
}
static void
F_324 ( struct V_539 * V_65 )
{
struct V_1 * V_2 = F_325 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
T_1 V_540 = 0xf ;
T_1 V_518 ;
if ( F_93 ( V_2 ) )
goto V_541;
V_540 = F_94 ( V_2 , V_297 ) ;
if ( V_540 == V_538 ||
V_540 == V_521 ) {
F_97 ( V_2 ) ;
F_257 ( V_2 , F_324 ,
V_445 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_144 == V_179 ) {
F_97 ( V_2 ) ;
goto V_542;
}
if ( V_540 == V_537 ||
V_540 == V_298 ) {
F_68 ( & V_2 -> V_5 -> V_30 , L_82
L_83 ) ;
goto V_543;
}
if ( V_2 -> V_544 ++ > V_2 -> V_545 ) {
F_68 ( & V_2 -> V_5 -> V_30 , L_84 ,
V_2 -> V_545 ) ;
goto V_543;
}
if ( ! F_320 ( V_2 ) ) {
V_543:
V_540 = F_94 ( V_2 , V_297 ) ;
if ( V_540 == V_520 ) {
F_96 ( V_2 , V_297 ,
V_537 ) ;
F_120 ( V_528 , & V_2 -> V_46 ) ;
F_323 ( V_2 , V_546 , L_85 ) ;
F_151 ( V_2 , 0 ) ;
V_518 = F_94 ( V_2 ,
V_522 ) ;
F_315 ( V_518 , V_2 -> V_435 ) ;
F_96 ( V_2 ,
V_522 , V_518 ) ;
}
F_97 ( V_2 ) ;
F_171 () ;
if ( F_326 ( V_2 ) &&
( V_2 -> V_41 & V_531 ) ) {
F_323 ( V_2 , V_546 , L_86 ) ;
F_327 ( V_2 ) ;
V_2 -> V_41 |= V_527 ;
}
F_173 () ;
V_2 -> V_41 &= ~ V_531 ;
if ( ! V_2 -> V_180 -> V_547 ( V_2 ) ) {
F_257 ( V_2 , V_548 , 0 ) ;
V_2 -> V_544 = 0 ;
return;
}
goto V_541;
}
F_97 ( V_2 ) ;
V_542:
V_540 = F_94 ( V_2 , V_297 ) ;
F_323 ( V_2 , V_536 , L_87 , V_540 ) ;
switch ( V_540 ) {
case V_298 :
if ( ! F_247 ( V_2 ) ) {
F_257 ( V_2 , V_548 , 0 ) ;
V_2 -> V_544 = 0 ;
return;
}
case V_299 :
break;
default:
F_257 ( V_2 ,
F_324 , V_445 ) ;
return;
}
V_541:
F_80 ( & V_2 -> V_5 -> V_30 , L_88
L_89 , V_540 , V_2 -> V_544 ) ;
F_25 ( V_2 -> V_22 ) ;
F_263 ( V_2 , 0 ) ;
}
static void
F_328 ( struct V_539 * V_65 )
{
struct V_1 * V_2 = F_325 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_511 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_540 == V_521 ) {
if ( F_172 ( V_22 ) )
F_174 ( V_2 , V_22 ) ;
} else
F_186 ( V_2 , V_22 ) ;
V_511 = F_94 ( V_2 , V_549 ) ;
if ( V_511 & V_550 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_90 ,
V_511 ) ;
if ( F_329 ( V_511 ) == V_551 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_91
L_92 ) ;
F_80 ( & V_2 -> V_5 -> V_30 ,
L_93 ) ;
}
goto V_541;
}
if ( V_2 -> V_4 -> V_242 == V_475 ) {
F_80 ( & V_2 -> V_5 -> V_30 , L_94 ,
V_2 -> V_4 -> V_242 ) ;
goto V_541;
}
if ( ! ( V_2 -> V_41 & V_531 ) ) {
if ( F_313 ( V_2 , V_2 -> V_540 ) ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_95
L_96 ) ;
goto V_541;
}
}
V_2 -> V_544 = 0 ;
F_257 ( V_2 , F_324 , V_445 ) ;
return;
V_541:
F_25 ( V_22 ) ;
F_263 ( V_2 , 1 ) ;
}
static void
F_330 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_94 ( V_2 , V_288 ) ;
if ( V_46 == V_552 )
return;
if ( F_93 ( V_2 ) )
return;
F_96 ( V_2 , V_288 ,
V_552 ) ;
F_97 ( V_2 ) ;
}
static void F_331 ( struct V_1 * V_2 ,
T_1 V_553 )
{
T_1 V_46 , V_554 = 0 , V_555 = 0 ;
F_332 ( V_554 ) ;
F_333 ( V_554 ) ;
F_149 ( V_2 , V_556 , V_554 ) ;
F_334 ( V_555 ) ;
F_335 ( V_555 ) ;
F_336 ( V_555 ) ;
F_337 ( V_555 ) ;
F_149 ( V_2 , V_557 , V_555 ) ;
F_68 ( & V_2 -> V_5 -> V_30 , L_97
L_98 ) ;
V_2 -> V_274 = 1 ;
if ( F_93 ( V_2 ) )
return;
V_46 = F_94 ( V_2 , V_297 ) ;
if ( F_21 ( V_446 , & V_2 -> V_46 ) ) {
F_119 ( V_2 -> V_22 , L_56 ,
V_54 ) ;
F_97 ( V_2 ) ;
return;
}
if ( V_46 == V_298 ) {
F_96 ( V_2 , V_297 ,
V_520 ) ;
V_2 -> V_41 |= V_531 ;
F_323 ( V_2 , V_546 , L_99 ) ;
F_151 ( V_2 , 0 ) ;
}
F_96 ( V_2 , V_288 ,
V_552 ) ;
F_97 ( V_2 ) ;
}
static void
F_140 ( struct V_1 * V_2 )
{
if ( F_93 ( V_2 ) )
return;
F_96 ( V_2 , V_288 ,
V_289 ) ;
F_323 ( V_2 , V_546 , L_100 ) ;
F_97 ( V_2 ) ;
}
void F_257 ( struct V_1 * V_2 ,
T_11 V_66 , int V_558 )
{
if ( F_21 ( V_559 , & V_2 -> V_46 ) )
return;
F_338 ( & V_2 -> V_64 , V_66 ) ;
F_339 ( V_2 -> V_421 , & V_2 -> V_64 ,
F_340 ( V_558 ) ) ;
}
static void
V_548 ( struct V_539 * V_65 )
{
struct V_1 * V_2 = F_325 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_287 ;
if ( V_2 -> V_4 -> V_144 != V_145 ) {
V_287 = F_94 ( V_2 ,
V_288 ) ;
if ( V_2 -> V_544 ++ > V_286 )
F_263 ( V_2 , 0 ) ;
else if ( V_287 != V_289 )
F_257 ( V_2 , V_548 ,
V_445 ) ;
else
goto V_560;
F_323 ( V_2 , V_546 , L_101 ) ;
return;
}
V_560:
F_254 ( V_2 -> V_397 ) ;
if ( F_172 ( V_22 ) ) {
if ( F_170 ( V_2 , V_22 ) )
goto V_514;
F_122 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
V_2 -> V_526 = 0 ;
V_2 -> V_41 &= ~ V_527 ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
if ( V_2 -> V_435 == 0 )
F_228 ( V_2 ) ;
if ( ! F_317 ( V_2 ) )
F_257 ( V_2 , V_444 ,
V_445 ) ;
}
static int
F_341 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_210 * V_211 = & V_4 -> V_211 ;
T_1 V_46 = 0 , V_561 ;
T_1 V_562 ;
int V_51 = 0 ;
if ( F_292 ( V_2 ) )
goto V_563;
if ( V_2 -> V_274 )
F_342 ( V_2 , 0 ) ;
V_46 = F_94 ( V_2 , V_297 ) ;
if ( V_46 == V_520 ) {
F_330 ( V_2 ) ;
V_2 -> V_274 = 1 ;
} else if ( V_46 == V_521 )
goto V_563;
V_561 = F_94 ( V_2 , V_564 ) ;
if ( V_561 != V_2 -> V_561 ) {
V_2 -> V_561 = V_561 ;
V_2 -> V_526 = 0 ;
if ( V_2 -> V_274 )
goto V_563;
if ( V_4 -> V_341 && V_565 )
F_207 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_526 < V_566 )
return 0 ;
V_2 -> V_41 |= V_527 ;
F_342 ( V_2 , 0 ) ;
if ( V_565 )
F_123 ( V_567 , & V_2 -> V_46 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_102 ) ;
V_562 = F_94 ( V_2 , V_549 ) ;
F_80 ( & V_2 -> V_5 -> V_30 , L_103
L_104
L_105
L_106
L_107 ,
V_562 ,
F_94 ( V_2 , V_568 ) ,
F_115 ( V_2 , V_569 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_570 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_571 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_572 + 0x3c , & V_51 ) ,
F_115 ( V_2 , V_573 + 0x3c , & V_51 ) ) ;
if ( F_329 ( V_562 ) == 0x67 )
F_80 ( & V_2 -> V_5 -> V_30 ,
L_108
L_109 ) ;
V_563:
V_2 -> V_540 = ( V_46 == V_521 ) ? V_46 :
V_520 ;
if ( V_565 && ! F_45 ( V_63 ,
& V_2 -> V_46 ) ) {
F_257 ( V_2 , F_328 , 0 ) ;
F_323 ( V_2 , V_546 , L_110 ) ;
} else if ( ! V_565 && V_211 -> V_574 &&
V_2 -> V_41 & V_531 ) {
F_327 ( V_2 ) ;
}
return 1 ;
}
void V_444 ( struct V_539 * V_65 )
{
struct V_1 * V_2 = F_325 ( V_65 ,
struct V_1 , V_64 . V_65 ) ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
goto V_575;
if ( F_341 ( V_2 ) )
return;
if ( V_2 -> V_342 . V_343 )
F_343 ( V_2 ) ;
V_575:
F_257 ( V_2 , V_444 , V_445 ) ;
}
static int F_344 ( struct V_23 * V_5 )
{
struct V_23 * V_576 ;
int V_518 = V_5 -> V_577 ;
while ( V_518 -- > 0 ) {
V_576 = F_345 ( F_346
( V_5 -> V_578 ) , V_5 -> V_578 -> V_579 ,
F_347 ( F_348 ( V_5 -> V_577 ) , V_518 ) ) ;
if ( ! V_576 )
continue;
if ( V_576 -> V_580 != V_581 ) {
F_349 ( V_576 ) ;
return 0 ;
}
F_349 ( V_576 ) ;
}
return 1 ;
}
static int F_350 ( struct V_23 * V_5 )
{
int V_51 , V_582 ;
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_583 = V_584 ;
V_51 = F_232 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_235 ( V_5 ) ;
F_287 ( V_5 ) ;
V_582 = F_344 ( V_5 ) ;
if ( F_93 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_144 != V_179 && V_582 ) {
V_2 -> V_274 = 1 ;
F_120 ( V_528 , & V_2 -> V_46 ) ;
F_96 ( V_2 , V_297 ,
V_537 ) ;
F_323 ( V_2 , V_546 , L_85 ) ;
}
F_97 ( V_2 ) ;
V_51 = F_247 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_317 ( V_2 ) ;
F_7 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
V_51 = F_255 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_99 ) ;
F_119 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( V_51 ) {
F_263 ( V_2 , 1 ) ;
F_123 ( V_559 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_51 ;
}
V_51 = F_170 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_514;
F_122 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
return V_51 ;
}
static T_12 F_351 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_585 )
return V_586 ;
if ( V_46 == V_584 )
return V_587 ;
F_120 ( V_559 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_64 ) ;
if ( F_172 ( V_22 ) )
F_186 ( V_2 , V_22 ) ;
F_197 ( V_2 ) ;
F_81 ( V_2 ) ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
F_352 ( V_5 ) ;
F_267 ( V_5 ) ;
return V_588 ;
}
static T_12 F_353 ( struct V_23 * V_5 )
{
return F_350 ( V_5 ) ? V_586 :
V_587 ;
}
static void F_354 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_269 ( V_5 ) ;
F_355 ( V_5 ) ;
V_46 = F_94 ( V_2 , V_297 ) ;
if ( V_46 == V_298 && F_175 ( V_559 ,
& V_2 -> V_46 ) )
F_257 ( V_2 , V_444 ,
V_445 ) ;
}
static T_12 F_356 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_590 ) {
return V_414 -> V_590 ( V_5 , V_46 ) ;
} else {
F_80 ( & V_5 -> V_30 , L_111 ) ;
return V_586 ;
}
}
static T_12 F_357 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_591 ) {
return V_414 -> V_591 ( V_5 ) ;
} else {
F_80 ( & V_5 -> V_30 , L_112 ) ;
return V_586 ;
}
}
static void F_358 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_269 ( V_5 ) ;
struct V_589 * V_414 = V_2 -> V_4 -> V_414 ;
if ( V_414 -> V_592 )
V_414 -> V_592 ( V_5 ) ;
else
F_80 ( & V_5 -> V_30 , L_113 ) ;
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
V_2 -> V_274 = 0 ;
return V_51 ;
}
int F_360 ( struct V_1 * V_2 , T_14 V_81 ,
int V_82 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_593 = 0 ;
char V_594 [ 8 ] ;
int V_595 ;
if ( V_82 == V_86 ) {
V_593 = V_2 -> V_87 ;
V_595 = V_2 -> V_93 ;
strcpy ( V_594 , L_114 ) ;
} else if ( V_82 == V_88 ) {
V_593 = V_2 -> V_89 ;
V_595 = V_2 -> V_91 ;
strcpy ( V_594 , L_115 ) ;
}
if ( ! F_361 ( V_81 ) ) {
F_119 ( V_22 , L_116 ,
V_594 ) ;
return - V_40 ;
}
if ( F_54 ( V_2 ) && ( V_82 == V_88 ) &&
! F_70 ( V_2 ) ) {
F_119 ( V_22 , L_117 ) ;
return - V_40 ;
}
if ( V_81 > F_58 () ) {
F_119 ( V_22 ,
L_118 ,
V_594 , F_58 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_362 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_596 , V_597 ;
int V_51 ;
if ( F_21 ( V_63 , & V_2 -> V_46 ) )
return - V_359 ;
V_596 = V_2 -> V_97 ;
V_597 = V_2 -> V_98 ;
F_22 ( V_22 ) ;
V_51 = F_210 ( V_2 , V_596 , V_597 ) ;
if ( V_51 )
goto V_514;
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
F_7 ( V_2 -> V_99 ) ;
F_119 ( V_22 , L_34 ) ;
return V_51 ;
}
if ( ( V_596 != V_2 -> V_91 ) ||
( V_597 != V_2 -> V_93 ) ) {
V_51 = F_210 ( V_2 ,
V_2 -> V_91 ,
V_2 -> V_93 ) ;
if ( V_51 )
goto V_514;
}
if ( F_62 ( V_2 ) ) {
F_273 ( V_2 , 1 ) ;
V_51 = F_364 ( V_2 ) ;
F_365 ( V_2 ) ;
if ( V_51 ) {
F_80 ( & V_2 -> V_5 -> V_30 ,
L_119 ) ;
goto V_514;
}
}
if ( F_172 ( V_22 ) ) {
V_51 = F_187 ( V_2 ) ;
if ( V_51 )
goto V_514;
V_51 = F_162 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_514;
F_122 ( V_22 , V_360 ) ;
}
V_514:
F_25 ( V_22 ) ;
F_123 ( V_63 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_366 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_598 )
{
struct V_599 * V_600 ;
V_600 = F_367 ( V_30 ) ;
if ( ! V_600 )
return;
F_368 (indev) {
switch ( V_598 ) {
case V_360 :
F_369 ( V_2 ,
V_601 -> V_602 , V_603 ) ;
break;
case V_263 :
F_369 ( V_2 ,
V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
} F_370 ( V_600 ) ;
F_371 ( V_600 ) ;
}
void F_122 ( struct V_21 * V_22 , unsigned long V_598 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_261 ;
F_366 ( V_2 , V_22 , V_598 ) ;
F_372 () ;
F_373 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_374 ( V_22 , F_375 ( V_605 ) , V_261 ) ;
if ( ! V_30 )
continue;
F_366 ( V_2 , V_30 , V_598 ) ;
}
F_376 () ;
}
static int F_377 ( struct V_606 * V_607 ,
unsigned long V_598 , void * V_608 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_378 ( V_608 ) ;
V_609:
if ( V_30 == NULL )
goto V_514;
if ( V_30 -> V_395 & V_610 ) {
V_30 = F_379 ( V_30 ) ;
goto V_609;
}
if ( ! F_380 ( V_30 ) )
goto V_514;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_514;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_514;
F_366 ( V_2 , V_30 , V_598 ) ;
V_514:
return V_611 ;
}
static int
F_381 ( struct V_606 * V_607 ,
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
V_30 = F_379 ( V_30 ) ;
goto V_609;
}
if ( ! F_380 ( V_30 ) )
goto V_514;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_514;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_514;
switch ( V_598 ) {
case V_360 :
F_369 ( V_2 , V_601 -> V_602 , V_603 ) ;
break;
case V_263 :
F_369 ( V_2 , V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
V_514:
return V_611 ;
}
void F_122 ( struct V_21 * V_30 , unsigned long V_598 )
{ }
static int T_15 F_382 ( void )
{
int V_26 ;
F_383 ( V_481 L_120 , V_614 ) ;
#ifdef F_384
F_385 ( & V_615 ) ;
F_386 ( & V_616 ) ;
#endif
V_26 = F_387 ( & V_617 ) ;
if ( V_26 ) {
#ifdef F_384
F_388 ( & V_616 ) ;
F_389 ( & V_615 ) ;
#endif
}
return V_26 ;
}
static void T_16 F_390 ( void )
{
F_391 ( & V_617 ) ;
#ifdef F_384
F_388 ( & V_616 ) ;
F_389 ( & V_615 ) ;
#endif
}
