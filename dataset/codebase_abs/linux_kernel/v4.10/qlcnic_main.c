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
struct V_21 * V_62 , int * V_63 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 = 0 ;
if ( ! V_2 -> V_53 )
return F_43 ( V_59 , V_61 , V_22 , V_62 , V_63 ) ;
if ( ( V_2 -> V_41 & V_54 ) ||
F_29 ( V_2 ) )
V_52 = F_43 ( V_59 , V_61 , V_22 , V_62 , V_63 ) ;
return V_52 ;
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
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_75 -> type != V_76 )
return;
if ( ! F_50 ( V_2 ) )
return;
if ( ! V_4 -> V_77 ) {
V_4 -> V_77 = 1 ;
V_4 -> V_78 = F_51 ( V_75 -> V_79 ) ;
V_2 -> V_41 |= V_80 ;
return;
}
if ( V_4 -> V_78 == F_51 ( V_75 -> V_79 ) )
V_4 -> V_77 ++ ;
}
static void F_52 ( struct V_21 * V_22 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_75 -> type != V_76 )
return;
if ( ! F_50 ( V_2 ) || ! V_4 -> V_77 ||
( V_4 -> V_78 != F_51 ( V_75 -> V_79 ) ) )
return;
V_4 -> V_77 -- ;
if ( ! V_4 -> V_77 )
V_2 -> V_41 |= V_81 ;
}
static T_4 F_53 ( struct V_58 * V_59 ,
struct V_21 * V_30 ,
T_4 V_82 )
{
V_82 = F_54 ( V_59 , V_82 ) ;
return F_55 ( V_59 , V_82 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_57 ( V_2 ) &&
( V_4 -> V_83 [ 0 ] & V_84 ) ) {
F_45 ( V_85 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_58 ( struct V_1 * V_2 , T_2 V_86 ,
int V_87 )
{
int V_88 , V_89 = V_90 ;
if ( V_87 == V_91 )
V_89 = V_2 -> V_92 ;
else if ( V_87 == V_93 )
V_89 = V_2 -> V_94 ;
V_88 = F_59 ( F_60 ( int , F_61 () ,
V_89 ) ) ;
if ( V_86 > V_88 )
return V_88 ;
else
return V_86 ;
}
void F_62 ( struct V_1 * V_2 , T_2 V_95 )
{
if ( V_2 -> V_94 )
V_2 -> V_96 = F_58 ( V_2 , V_95 ,
V_93 ) ;
else
V_2 -> V_96 = V_95 ;
}
void F_63 ( struct V_1 * V_2 , T_2 V_97 )
{
if ( V_2 -> V_92 )
V_2 -> V_98 = F_58 ( V_2 , V_97 ,
V_91 ) ;
else
V_2 -> V_98 = V_97 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_99 = 0 , V_52 = 0 , V_100 ;
V_2 -> V_41 &= ~ V_101 ;
if ( V_2 -> V_102 > 0 )
V_99 += V_2 -> V_102 ;
else
V_99 += V_2 -> V_96 ;
if ( V_2 -> V_103 > 0 )
V_99 += V_2 -> V_103 ;
else
V_99 += V_2 -> V_98 ;
if ( F_65 ( V_2 ) )
V_99 += 1 ;
if ( ! V_2 -> V_104 ) {
V_2 -> V_104 = F_66 ( V_99 ,
sizeof( struct V_105 ) ,
V_20 ) ;
if ( ! V_2 -> V_104 )
return - V_57 ;
}
for ( V_100 = 0 ; V_100 < V_99 ; V_100 ++ )
V_2 -> V_104 [ V_100 ] . V_106 = V_100 ;
V_107:
V_52 = F_67 ( V_5 , V_2 -> V_104 , V_99 ) ;
if ( V_52 == - V_108 ) {
if ( ! V_2 -> V_102 && ! V_2 -> V_103 )
return V_52 ;
F_68 ( V_2 -> V_22 ,
L_3 ,
V_99 , V_52 ) ;
V_99 = V_2 -> V_96 + V_2 -> V_98 ;
V_2 -> V_102 = 0 ;
V_2 -> V_103 = 0 ;
if ( F_65 ( V_2 ) )
V_99 += 1 ;
F_68 ( V_2 -> V_22 ,
L_4 ,
V_2 -> V_96 , V_2 -> V_98 ,
V_99 ) ;
goto V_107;
} else if ( V_52 < 0 ) {
return V_52 ;
}
V_2 -> V_4 -> V_99 = V_99 ;
if ( V_2 -> V_102 > 0 )
V_2 -> V_96 = V_2 -> V_102 ;
if ( V_2 -> V_103 > 0 )
V_2 -> V_98 = V_2 -> V_103 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_99 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_52 , V_100 ;
if ( ! V_2 -> V_104 ) {
V_2 -> V_104 = F_66 ( V_99 ,
sizeof( struct V_105 ) ,
V_20 ) ;
if ( ! V_2 -> V_104 )
return - V_57 ;
}
V_2 -> V_41 &= ~ ( V_109 | V_110 ) ;
if ( V_2 -> V_4 -> V_111 ) {
V_112:
for ( V_100 = 0 ; V_100 < V_99 ; V_100 ++ )
V_2 -> V_104 [ V_100 ] . V_106 = V_100 ;
V_52 = F_70 ( V_5 ,
V_2 -> V_104 , 1 , V_99 ) ;
if ( V_52 == V_99 ) {
V_2 -> V_41 |= V_110 ;
V_2 -> V_4 -> V_99 = V_99 ;
F_71 ( & V_5 -> V_30 , L_5 ) ;
return 0 ;
} else if ( V_52 > 0 ) {
F_72 ( V_5 ) ;
F_71 ( & V_5 -> V_30 ,
L_3 ,
V_99 , V_52 ) ;
if ( F_57 ( V_2 ) ) {
V_99 = F_59 ( V_52 ) ;
if ( V_52 < V_113 )
return - V_108 ;
} else {
V_99 = F_59 ( V_52 - 1 ) ;
V_99 += 1 ;
if ( V_52 < V_114 )
return - V_108 ;
}
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) {
V_2 -> V_98 = V_99 ;
V_2 -> V_96 = V_115 ;
} else {
V_2 -> V_96 = V_99 / 2 ;
V_2 -> V_98 = V_2 -> V_96 ;
}
if ( V_99 ) {
F_71 ( & V_5 -> V_30 ,
L_6 ,
V_99 ) ;
goto V_112;
}
} else {
F_71 ( & V_5 -> V_30 ,
L_7 ,
V_99 , V_52 ) ;
return V_52 ;
}
}
return - V_116 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_99 ;
V_99 = V_2 -> V_98 ;
if ( F_73 ( V_2 ) )
V_99 += V_2 -> V_96 ;
else
V_99 += V_115 ;
return V_99 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
T_1 V_117 , V_118 ;
const struct V_119 * V_120 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_121 && ! F_76 ( V_5 ) ) {
V_2 -> V_41 |= V_109 ;
V_117 = V_122 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_123 = F_77 ( V_2 -> V_4 ,
V_117 ) ;
F_71 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_104 [ 0 ] . V_100 = V_5 -> V_124 ;
return V_52 ;
}
if ( V_121 || V_125 )
return - V_43 ;
V_120 = & V_126 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_127 = V_120 -> V_127 ;
V_117 = V_120 -> V_123 ;
V_2 -> V_123 = F_77 ( V_4 , V_117 ) ;
V_118 = V_120 -> V_128 ;
V_2 -> V_128 = F_77 ( V_4 , V_118 ) ;
V_2 -> V_129 = F_77 ( V_4 , V_130 ) ;
V_2 -> V_131 = F_77 ( V_4 , V_132 ) ;
F_71 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_104 [ 0 ] . V_100 = V_5 -> V_124 ;
return V_52 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_99 , V_52 = 0 ;
if ( V_2 -> V_41 & V_101 ) {
V_52 = F_64 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
V_99 = V_2 -> V_4 -> V_99 ;
} else {
V_99 = F_74 ( V_2 ) ;
V_52 = F_69 ( V_2 , V_99 ) ;
if ( V_52 == - V_57 )
return V_52 ;
if ( ! ( V_2 -> V_41 & V_110 ) ) {
F_79 ( V_2 ) ;
V_2 -> V_98 = V_115 ;
V_52 = F_75 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_133 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 , V_134 ;
if ( F_73 ( V_2 ) &&
! V_4 -> V_135 &&
( V_2 -> V_41 & V_110 ) ) {
V_4 -> V_136 = F_81 ( V_4 -> V_99 *
sizeof( struct V_137 ) ) ;
if ( ! V_4 -> V_136 )
return - V_57 ;
for ( V_134 = 0 ; V_134 < V_4 -> V_99 ; V_134 ++ ) {
V_4 -> V_136 [ V_134 ] . type = V_138 ;
V_4 -> V_136 [ V_134 ] . V_73 = V_134 ;
V_4 -> V_136 [ V_134 ] . V_139 = 0 ;
}
V_52 = F_82 ( V_2 , 1 ) ;
if ( V_52 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_99 ) ;
return V_52 ;
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_110 )
F_72 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_109 )
F_85 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
if ( V_2 -> V_4 -> V_136 ) {
F_86 ( V_2 -> V_4 -> V_136 ) ;
V_2 -> V_4 -> V_136 = NULL ;
}
}
static void F_87 ( struct V_3 * V_4 )
{
if ( V_4 -> V_140 != NULL )
F_88 ( V_4 -> V_140 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_141 * V_142 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_54 ) ) {
switch ( V_4 -> V_143 ) {
case V_144 :
V_4 -> V_145 = V_146 ;
break;
case V_147 :
V_4 -> V_145 = V_148 ;
break;
}
return 0 ;
}
if ( V_4 -> V_149 == V_150 )
return 0 ;
V_142 = F_66 ( V_4 -> V_151 , sizeof( * V_142 ) , V_20 ) ;
if ( ! V_142 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_142 ) ;
F_7 ( V_142 ) ;
return V_26 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_92 ( V_2 ) ) {
V_26 = true ;
} else if ( F_65 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_83 [ 0 ] &
V_152 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_141 * V_142 ;
int V_134 , V_73 = 0 , V_26 = 0 , V_153 = 0 ;
T_3 V_154 ;
T_2 V_155 ;
V_142 = F_66 ( V_4 -> V_151 , sizeof( * V_142 ) , V_20 ) ;
if ( ! V_142 )
return - V_57 ;
V_26 = F_90 ( V_2 , V_142 ) ;
if ( V_26 )
goto V_156;
V_154 = V_4 -> V_145 ;
V_2 -> V_157 = F_5 ( sizeof( struct V_158 ) *
V_154 , V_20 ) ;
if ( ! V_2 -> V_157 ) {
V_26 = - V_57 ;
goto V_156;
}
V_2 -> V_159 = F_5 ( sizeof( struct V_160 ) *
V_148 , V_20 ) ;
if ( ! V_2 -> V_159 ) {
V_26 = - V_57 ;
goto V_161;
}
for ( V_134 = 0 ; V_134 < V_4 -> V_151 ; V_134 ++ ) {
V_155 = V_142 [ V_134 ] . V_73 ;
if ( V_155 >= V_4 -> V_151 ) {
V_26 = - V_40 ;
F_83 ( & V_2 -> V_5 -> V_30 , L_11 ,
V_55 , V_155 , V_4 -> V_151 ) ;
goto V_162;
}
if ( ! V_142 [ V_134 ] . V_163 ||
( V_142 [ V_134 ] . type != V_164 ) )
continue;
if ( F_91 ( V_2 ) ) {
if ( ! F_94 ( V_2 , V_155 ,
& V_73 ) )
V_2 -> V_157 [ V_153 ] . V_165 = true ;
else
continue;
} else {
V_2 -> V_157 [ V_153 ] . V_165 = true ;
}
V_2 -> V_157 [ V_153 ] . V_27 = V_155 ;
V_2 -> V_157 [ V_153 ] . V_163 = ( T_2 ) V_142 [ V_134 ] . V_163 ;
V_2 -> V_157 [ V_153 ] . type = ( T_2 ) V_142 [ V_134 ] . type ;
V_2 -> V_157 [ V_153 ] . V_166 = ( T_2 ) V_142 [ V_134 ] . V_167 ;
V_2 -> V_157 [ V_153 ] . V_168 = V_142 [ V_134 ] . V_169 ;
V_2 -> V_157 [ V_153 ] . V_170 = V_142 [ V_134 ] . V_171 ;
memcpy ( & V_2 -> V_157 [ V_153 ] . V_172 , & V_142 [ V_134 ] . V_172 , V_25 ) ;
V_153 ++ ;
}
if ( ! F_91 ( V_2 ) ) {
for ( V_134 = 0 ; V_134 < V_148 ; V_134 ++ )
V_2 -> V_159 [ V_134 ] . V_41 |= V_173 ;
}
F_7 ( V_142 ) ;
return 0 ;
V_162:
F_7 ( V_2 -> V_159 ) ;
V_2 -> V_159 = NULL ;
V_161:
F_7 ( V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
V_156:
F_7 ( V_142 ) ;
return V_26 ;
}
static int
F_95 ( struct V_1 * V_2 )
{
T_2 V_73 ;
int V_26 ;
T_1 V_174 = V_150 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_96 ( V_2 ) ;
if ( V_26 )
goto V_175;
V_73 = V_4 -> V_27 ;
V_174 = F_97 ( V_2 , V_176 ) ;
V_174 = ( V_174 & ~ F_98 ( 0xf , V_73 ) ) |
F_98 ( V_150 , V_73 ) ;
F_99 ( V_2 , V_176 , V_174 ) ;
F_100 ( V_2 ) ;
V_175:
return V_26 ;
}
static void F_101 ( struct V_1 * V_2 ,
const struct V_177 * V_178 )
{
T_1 V_149 , V_179 ;
V_2 -> V_4 -> V_180 = F_97 ( V_2 ,
V_181 ) ;
F_102 ( V_2 ) ;
V_149 = F_97 ( V_2 , V_176 ) ;
if ( V_149 == V_182 )
V_179 = V_150 ;
else
V_179 = F_103 ( V_149 , V_2 -> V_4 -> V_27 ) ;
if ( V_179 == V_183 ) {
V_2 -> V_4 -> V_149 = V_183 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_12 ,
V_2 -> V_4 -> V_180 ) ;
V_2 -> V_184 = & V_185 ;
} else
V_2 -> V_184 = & V_186 ;
}
static void F_104 ( T_1 V_187 , T_5 * V_188 )
{
switch ( V_187 ) {
case V_7 :
* V_188 = V_189 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
* V_188 = V_196 ;
break;
default:
* V_188 = 0 ;
}
}
static int F_105 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_117 ;
void T_6 * V_197 = NULL ;
unsigned long V_198 , V_199 = 0 , V_200 ;
V_198 = F_106 ( V_5 , 0 ) ;
F_104 ( V_5 -> V_6 , & V_200 ) ;
if ( V_198 >= V_200 ) {
V_197 = F_107 ( V_5 , 0 ) ;
if ( V_197 == NULL ) {
F_83 ( & V_5 -> V_30 , L_13 ) ;
return - V_116 ;
}
V_199 = V_198 ;
} else {
return - V_116 ;
}
F_71 ( & V_5 -> V_30 , L_14 , ( int ) ( V_198 >> 10 ) ) ;
V_4 -> V_140 = V_197 ;
V_4 -> V_199 = V_199 ;
V_117 = F_108 ( F_109 ( V_4 -> V_27 ) ) ;
F_77 ( V_4 , V_117 ) ;
return 0 ;
}
static bool F_110 ( struct V_1 * V_2 ,
int V_201 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_202 ;
bool V_26 = true ;
V_202 = V_5 -> V_202 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_190 ) {
if ( V_203 [ V_201 ] . V_204 == V_202 &&
V_203 [ V_201 ] . V_205 == V_5 -> V_206 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_111 ( struct V_1 * V_2 , char * V_207 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_134 , V_208 = 0 ;
for ( V_134 = 0 ; V_134 < V_209 ; ++ V_134 ) {
if ( V_203 [ V_134 ] . V_210 == V_5 -> V_210 &&
V_203 [ V_134 ] . V_6 == V_5 -> V_6 &&
F_110 ( V_2 , V_134 ) ) {
V_208 = 1 ;
break;
}
}
if ( ! V_208 )
sprintf ( V_207 , L_15 , V_2 -> V_24 ) ;
else
sprintf ( V_207 , L_16 , V_2 -> V_24 ,
V_203 [ V_134 ] . V_211 ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
int V_52 ;
T_1 V_212 , V_213 , V_214 , V_215 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_216 * V_217 = & V_4 -> V_217 ;
V_215 = V_2 -> V_218 ;
V_212 = F_97 ( V_2 , V_219 ) ;
V_213 = F_97 ( V_2 , V_220 ) ;
V_214 = F_97 ( V_2 , V_221 ) ;
V_2 -> V_218 = F_113 ( V_212 , V_213 , V_214 ) ;
V_52 = F_114 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_17 ) ;
return;
}
if ( V_4 -> V_149 != V_183 ) {
if ( V_217 -> V_222 == NULL ||
V_2 -> V_218 > V_215 ) {
F_86 ( V_217 -> V_222 ) ;
if ( ! F_115 ( V_2 ) )
F_71 ( & V_5 -> V_30 ,
L_18 ) ;
}
}
F_71 ( & V_5 -> V_30 , L_19 ,
V_223 , V_212 , V_213 , V_214 ) ;
if ( V_2 -> V_4 -> V_143 == V_147 ) {
if ( V_2 -> V_41 & V_54 ) {
V_2 -> V_224 = V_225 ;
V_2 -> V_226 = V_227 ;
} else {
V_2 -> V_224 = V_228 ;
V_2 -> V_226 = V_229 ;
}
V_2 -> V_230 = V_231 ;
V_2 -> V_232 = V_231 ;
} else if ( V_2 -> V_4 -> V_143 == V_144 ) {
V_2 -> V_224 = V_233 ;
V_2 -> V_230 = V_234 ;
V_2 -> V_232 = V_234 ;
V_2 -> V_226 = V_235 ;
}
V_2 -> V_4 -> V_111 = ! ! V_125 ;
V_2 -> V_236 = V_237 ;
V_2 -> V_238 = V_239 ;
}
static int
F_116 ( struct V_1 * V_2 )
{
struct V_240 V_241 ;
int V_52 = 0 ;
memset ( & V_241 , 0 , sizeof( struct V_240 ) ) ;
V_52 = F_117 ( V_2 , & V_241 , V_2 -> V_4 -> V_27 ) ;
if ( V_52 )
return V_52 ;
V_2 -> V_4 -> V_242 = ( T_2 ) V_241 . V_243 ;
V_2 -> V_4 -> V_244 = V_241 . V_244 ;
V_2 -> V_4 -> V_245 = V_241 . V_245 ;
V_2 -> V_4 -> V_246 = V_241 . V_246 ;
V_2 -> V_4 -> V_8 = V_241 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_247 ) {
T_1 V_248 ;
V_248 = F_118 ( V_2 , V_249 , & V_52 ) ;
if ( V_52 == - V_116 )
return V_52 ;
V_2 -> V_4 -> V_83 [ 0 ] = V_248 ;
} else {
V_2 -> V_4 -> V_83 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_250 = V_241 . V_250 ;
V_2 -> V_4 -> V_251 = V_241 . V_251 ;
if ( V_2 -> V_4 -> V_8 & V_252 ) {
V_2 -> V_41 |= V_54 ;
V_2 -> V_4 -> V_253 = V_254 ;
V_2 -> V_94 = V_255 ;
V_2 -> V_92 = V_256 ;
F_71 ( & V_2 -> V_5 -> V_30 , L_20 ) ;
} else {
V_2 -> V_4 -> V_253 = V_257 ;
V_2 -> V_94 = V_258 ;
V_2 -> V_92 = V_90 ;
V_2 -> V_41 &= ~ V_54 ;
}
return V_52 ;
}
void F_119 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
if ( V_260 -> V_261 )
V_2 -> V_41 &= ~ V_262 ;
else
V_2 -> V_41 |= V_262 ;
if ( V_260 -> V_263 ) {
V_2 -> V_264 = V_260 -> V_263 ;
V_2 -> V_265 = V_260 -> V_263 ;
} else {
V_2 -> V_264 = 0 ;
V_2 -> V_265 = 0 ;
}
}
static int
F_120 ( struct V_21 * V_22 , T_7 V_266 , T_3 V_51 )
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
F_123 ( V_51 , V_2 -> V_267 ) ;
return 0 ;
}
static int
F_124 ( struct V_21 * V_22 , T_7 V_266 , T_3 V_51 )
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
F_125 ( V_22 , V_268 ) ;
F_126 ( V_51 , V_2 -> V_267 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
V_2 -> V_41 &= ~ ( V_269 | V_42 |
V_270 ) ;
if ( V_260 -> V_271 )
V_2 -> V_41 |= V_269 ;
if ( ! V_260 -> V_272 )
V_2 -> V_41 |= V_42 ;
if ( ! V_260 -> V_273 )
V_2 -> V_41 |= V_270 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_259 V_260 ;
if ( ! ( V_2 -> V_41 & V_54 ) )
return 0 ;
V_260 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_129 ( V_2 , & V_260 ) )
return - V_116 ;
F_119 ( V_2 , & V_260 ) ;
F_127 ( V_2 , & V_260 ) ;
F_130 ( V_2 , & V_260 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_65 ( V_2 ) )
return;
V_2 -> V_274 = V_260 -> V_274 ;
V_2 -> V_41 |= V_275 ;
F_131 ( V_22 ) ;
V_2 -> V_41 &= ~ V_275 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_1 V_149 , V_179 ;
int V_52 = 0 ;
V_52 = F_116 ( V_2 ) ;
if ( V_52 )
return V_52 ;
if ( V_2 -> V_41 & V_276 )
return 0 ;
V_149 = F_97 ( V_2 , V_176 ) ;
V_179 = F_103 ( V_149 , V_2 -> V_4 -> V_27 ) ;
if ( V_149 == V_182 )
V_179 = V_150 ;
else
V_179 = F_103 ( V_149 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_54 ) {
if ( V_179 == V_150 ) {
V_2 -> V_4 -> V_149 = V_150 ;
V_52 = F_93 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_95 ( V_2 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_180 ) ;
} else if ( V_179 == V_277 ) {
V_2 -> V_4 -> V_149 = V_277 ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_24 ,
V_2 -> V_4 -> V_180 ) ;
}
} else {
V_2 -> V_4 -> V_253 = V_257 ;
}
V_2 -> V_41 |= V_276 ;
return V_52 ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_259 V_260 ;
struct V_158 * V_278 ;
T_2 V_134 ;
if ( V_2 -> V_279 )
return 0 ;
for ( V_134 = 0 ; V_134 < V_2 -> V_4 -> V_145 ; V_134 ++ ) {
if ( ! V_2 -> V_157 [ V_134 ] . V_165 )
continue;
memset ( & V_260 , 0 , sizeof( struct V_259 ) ) ;
V_260 . V_27 = V_2 -> V_157 [ V_134 ] . V_27 ;
V_260 . V_272 = V_280 ;
V_260 . V_273 = V_280 ;
if ( F_57 ( V_2 ) ) {
V_260 . V_274 = V_280 ;
if ( F_134 ( V_2 ) )
V_260 . V_274 |= ( V_281 | V_282 ) ;
}
if ( F_135 ( V_2 , & V_260 ) )
return - V_116 ;
V_278 = & V_2 -> V_157 [ V_134 ] ;
V_278 -> V_283 = V_260 . V_263 ;
V_278 -> V_272 = V_260 . V_272 ;
V_278 -> V_271 = V_260 . V_271 ;
V_278 -> V_261 = V_260 . V_261 ;
V_278 -> V_273 = V_260 . V_273 ;
V_278 -> V_274 = V_260 . V_274 ;
}
return 0 ;
}
static int
F_136 ( struct V_1 * V_2 ,
struct V_158 * V_278 , int V_27 )
{
struct V_259 V_260 ;
V_260 . V_149 = V_284 ;
V_260 . V_27 = V_27 ;
V_260 . V_263 = V_278 -> V_283 ;
V_260 . V_272 = V_278 -> V_272 ;
V_260 . V_261 = V_278 -> V_261 ;
V_260 . V_271 = V_278 -> V_271 ;
V_260 . V_274 = V_278 -> V_274 ;
V_260 . V_273 = V_278 -> V_273 ;
if ( F_135 ( V_2 , & V_260 ) )
return - V_116 ;
V_260 . V_149 = V_285 ;
if ( F_135 ( V_2 , & V_260 ) )
return - V_116 ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_134 , V_52 ;
struct V_158 * V_278 ;
struct V_240 V_241 ;
T_2 V_27 ;
if ( F_57 ( V_2 ) )
if ( ! V_2 -> V_279 )
return 0 ;
for ( V_134 = 0 ; V_134 < V_2 -> V_4 -> V_145 ; V_134 ++ ) {
V_278 = & V_2 -> V_157 [ V_134 ] ;
V_27 = V_278 -> V_27 ;
if ( ! V_2 -> V_157 [ V_134 ] . V_165 )
continue;
memset ( & V_241 , 0 , sizeof( struct V_240 ) ) ;
V_52 = F_117 ( V_2 , & V_241 , V_27 ) ;
if ( V_52 )
return V_52 ;
V_241 . V_286 = V_278 -> V_168 ;
V_241 . V_287 = V_278 -> V_170 ;
V_52 = F_138 ( V_2 , & V_241 ) ;
if ( V_52 )
return V_52 ;
if ( V_278 -> V_288 ) {
V_52 = F_139 ( V_2 ,
V_278 -> V_289 , 1 ,
V_27 ) ;
if ( V_52 )
return V_52 ;
}
V_52 = F_136 ( V_2 , V_278 , V_27 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
T_2 V_290 = V_291 ;
T_1 V_292 ;
if ( V_2 -> V_4 -> V_149 == V_150 )
return 0 ;
V_292 = F_97 ( V_2 ,
V_293 ) ;
while ( V_292 != V_294 && -- V_290 ) {
F_141 ( 1000 ) ;
V_292 = F_97 ( V_2 ,
V_293 ) ;
}
if ( ! V_290 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
return - V_116 ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
int V_52 ;
if ( ! ( V_2 -> V_41 & V_54 ) ||
V_2 -> V_4 -> V_149 != V_150 )
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
goto V_295;
if ( V_296 )
F_146 ( V_2 ) ;
else {
V_52 = F_147 ( V_2 ) ;
if ( V_52 )
goto V_297;
V_2 -> V_4 -> V_298 = V_299 ;
}
V_52 = F_148 ( V_2 ) ;
if ( V_52 == 0 )
goto V_295;
V_52 = F_149 ( V_2 ) ;
if ( V_52 )
goto V_297;
V_52 = F_150 ( V_2 ) ;
if ( V_52 )
goto V_297;
F_151 ( V_2 ) ;
F_152 ( V_2 , V_300 , V_301 ) ;
V_295:
V_52 = F_153 ( V_2 ) ;
if ( V_52 )
goto V_297;
F_99 ( V_2 , V_302 , V_303 ) ;
F_154 ( V_2 , 1 ) ;
V_52 = F_132 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_26 ) ;
goto V_297;
}
V_52 = F_142 ( V_2 ) ;
if ( V_52 )
goto V_297;
F_112 ( V_2 ) ;
V_2 -> V_279 = 0 ;
F_151 ( V_2 ) ;
return 0 ;
V_297:
F_99 ( V_2 , V_302 , V_304 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_27 ) ;
F_151 ( V_2 ) ;
return V_52 ;
}
static int
F_155 ( struct V_1 * V_2 )
{
T_8 V_305 ;
struct V_18 * V_306 ;
struct V_10 * V_11 ;
int V_52 , V_307 , V_308 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_135 == V_309 ) {
if ( F_57 ( V_2 ) )
V_305 = V_310 ;
else
V_305 = V_311 ;
if ( ! F_156 ( V_2 ) )
V_41 |= V_312 ;
} else {
if ( V_2 -> V_41 & V_110 )
V_305 = V_313 ;
else if ( V_2 -> V_41 & V_109 )
V_305 = V_314 ;
else {
V_41 |= V_312 ;
if ( F_57 ( V_2 ) )
V_305 = V_315 ;
else
V_305 = V_316 ;
}
}
V_2 -> V_124 = V_22 -> V_124 ;
if ( V_2 -> V_4 -> V_135 != V_317 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_110 ) ) ) {
V_308 = V_2 -> V_98 ;
for ( V_307 = 0 ; V_307 < V_308 ; V_307 ++ ) {
V_306 = & V_15 -> V_19 [ V_307 ] ;
if ( F_57 ( V_2 ) &&
! F_73 ( V_2 ) &&
( V_307 == ( V_308 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_110 ) )
snprintf ( V_306 -> V_207 ,
sizeof( V_306 -> V_207 ) ,
L_28 ) ;
else
snprintf ( V_306 -> V_207 ,
sizeof( V_306 -> V_207 ) ,
L_29 ,
V_22 -> V_207 , V_307 ) ;
} else {
snprintf ( V_306 -> V_207 ,
sizeof( V_306 -> V_207 ) ,
L_30 ,
V_22 -> V_207 , V_307 ) ;
}
V_52 = F_157 ( V_306 -> V_124 , V_305 , V_41 ,
V_306 -> V_207 , V_306 ) ;
if ( V_52 )
return V_52 ;
}
}
if ( ( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_110 ) &&
! ( V_2 -> V_41 & V_318 ) ) ) {
V_305 = V_319 ;
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ;
V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
snprintf ( V_11 -> V_207 , sizeof( V_11 -> V_207 ) ,
L_31 , V_22 -> V_207 , V_307 ) ;
V_52 = F_157 ( V_11 -> V_124 , V_305 , V_41 ,
V_11 -> V_207 , V_11 ) ;
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
int V_307 ;
struct V_18 * V_306 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_135 != V_317 ) {
if ( F_57 ( V_2 ) ||
( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_110 ) ) ) {
for ( V_307 = 0 ; V_307 < V_2 -> V_98 ; V_307 ++ ) {
V_306 = & V_15 -> V_19 [ V_307 ] ;
F_159 ( V_306 -> V_124 , V_306 ) ;
}
}
if ( ( F_65 ( V_2 ) &&
! ( V_2 -> V_41 & V_318 ) ) ||
( F_57 ( V_2 ) &&
F_73 ( V_2 ) ) ) {
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ;
V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
if ( V_11 -> V_124 )
F_159 ( V_11 -> V_124 , V_11 ) ;
}
}
}
}
static void F_160 ( struct V_1 * V_2 )
{
T_1 V_320 = 0 ;
if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_83 [ 0 ] &
V_321 )
V_2 -> V_41 |= V_322 ;
} else {
V_320 = V_2 -> V_4 -> V_8 ;
if ( F_161 ( V_320 ) )
V_2 -> V_41 |= V_322 ;
}
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 ;
V_4 -> V_323 . V_324 = V_325 ;
if ( F_65 ( V_2 ) ) {
V_4 -> V_323 . type = V_326 ;
V_4 -> V_323 . V_327 = V_328 ;
V_4 -> V_323 . V_329 = V_330 ;
V_4 -> V_323 . V_331 = V_332 ;
V_4 -> V_323 . V_333 = V_334 ;
V_52 = F_163 ( V_2 ) ;
} else {
V_4 -> V_323 . type = V_335 ;
V_4 -> V_323 . V_331 = V_332 ;
V_4 -> V_323 . V_333 = V_334 ;
V_52 = F_164 ( V_2 ) ;
}
return V_52 ;
}
int F_165 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_307 ;
struct V_336 * V_337 ;
if ( V_2 -> V_338 != V_339 )
return - V_116 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_128 ( V_2 ) )
return - V_116 ;
F_160 ( V_2 ) ;
if ( F_166 ( V_2 ) )
return - V_116 ;
for ( V_307 = 0 ; V_307 < V_2 -> V_238 ; V_307 ++ ) {
V_337 = & V_2 -> V_15 -> V_340 [ V_307 ] ;
F_167 ( V_2 , V_337 , V_307 ) ;
}
F_24 ( V_22 ) ;
F_168 ( V_2 , V_22 -> V_341 ) ;
V_2 -> V_4 -> V_342 = 0 ;
if ( V_2 -> V_98 > 1 )
F_169 ( V_2 , 1 ) ;
F_162 ( V_2 ) ;
if ( V_22 -> V_82 & V_343 )
F_170 ( V_2 , V_344 ) ;
F_123 ( V_45 , & V_2 -> V_46 ) ;
F_26 ( V_2 ) ;
F_171 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_345 = 0 ;
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
int V_307 ;
if ( V_2 -> V_338 != V_339 )
return;
if ( ! F_178 ( V_45 , & V_2 -> V_46 ) )
return;
F_179 () ;
F_180 ( V_22 ) ;
V_2 -> V_4 -> V_342 = 0 ;
F_181 ( V_22 ) ;
F_182 ( V_2 ) ;
if ( V_2 -> V_346 . V_347 )
F_183 ( V_2 ) ;
F_184 ( V_2 , V_348 ) ;
if ( F_20 ( V_2 ) )
F_185 ( & V_2 -> V_4 -> V_349 -> V_350 ) ;
F_23 ( V_2 ) ;
F_186 ( V_2 ) ;
V_2 -> V_41 &= ~ V_322 ;
F_187 ( V_2 ) ;
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ )
F_188 ( V_2 , & V_2 -> V_11 [ V_307 ] ) ;
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
if ( V_2 -> V_338 == V_339 )
return 0 ;
V_52 = F_191 ( V_2 , V_22 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_192 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_32 ) ;
goto V_351;
}
V_52 = F_193 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_33 ) ;
goto V_352;
}
V_52 = F_155 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_34 ) ;
goto V_353;
}
F_194 ( V_2 ) ;
if ( F_50 ( V_2 ) )
F_195 ( V_22 ) ;
V_2 -> V_338 = V_339 ;
return 0 ;
V_353:
F_196 ( V_2 ) ;
V_352:
F_197 ( V_2 ) ;
V_351:
F_198 ( V_2 ) ;
return V_52 ;
}
void F_199 ( struct V_1 * V_2 )
{
if ( V_2 -> V_338 != V_339 )
return;
F_200 ( V_2 ) ;
F_196 ( V_2 ) ;
F_201 ( V_2 ) ;
F_158 ( V_2 ) ;
F_198 ( V_2 ) ;
F_197 ( V_2 ) ;
V_2 -> V_338 = 0 ;
}
void F_202 ( struct V_21 * V_22 , int V_98 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_306 ;
int V_96 = V_2 -> V_96 ;
int V_307 ;
F_126 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_135 == V_309 ) {
for ( V_307 = 0 ; V_307 < V_2 -> V_98 ; V_307 ++ ) {
V_306 = & V_2 -> V_15 -> V_19 [ V_307 ] ;
F_203 ( V_2 , V_306 ) ;
}
}
F_186 ( V_2 ) ;
F_199 ( V_2 ) ;
V_2 -> V_4 -> V_135 = 0 ;
V_2 -> V_98 = V_98 ;
V_2 -> V_96 = V_96 ;
if ( F_190 ( V_2 ) )
goto V_354;
if ( F_175 ( V_22 ) )
F_165 ( V_2 , V_22 ) ;
V_354:
F_25 ( V_22 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_52 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_52 = - V_57 ;
goto V_297;
}
if ( F_65 ( V_2 ) ) {
V_4 -> V_323 . type = V_326 ;
V_4 -> V_323 . V_327 = V_328 ;
V_4 -> V_323 . V_329 = V_330 ;
V_4 -> V_323 . V_331 = V_332 ;
V_4 -> V_323 . V_333 = V_334 ;
} else {
V_4 -> V_323 . type = V_335 ;
V_4 -> V_323 . V_331 = V_332 ;
V_4 -> V_323 . V_333 = V_334 ;
}
memset ( & V_2 -> V_355 , 0 , sizeof( V_2 -> V_355 ) ) ;
V_297:
return V_52 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_216 * V_217 = & V_2 -> V_4 -> V_217 ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_217 -> V_222 ) {
F_86 ( V_217 -> V_222 ) ;
V_217 -> V_222 = NULL ;
}
if ( V_217 -> V_356 ) {
F_206 ( & V_2 -> V_5 -> V_30 , V_357 ,
V_217 -> V_356 , V_217 -> V_358 ) ;
V_217 -> V_356 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_359 . V_360 ) ;
V_2 -> V_4 -> V_217 . V_222 = NULL ;
}
int F_207 ( struct V_21 * V_22 , int V_361 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_306 ;
struct V_336 * V_337 ;
int V_307 ;
int V_26 ;
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
V_2 -> V_98 = V_115 ;
V_2 -> V_4 -> V_135 = V_361 ;
V_2 -> V_4 -> V_342 = 0 ;
V_26 = F_190 ( V_2 ) ;
if ( V_26 ) {
F_25 ( V_22 ) ;
return V_26 ;
}
V_26 = F_166 ( V_2 ) ;
if ( V_26 ) {
F_199 ( V_2 ) ;
F_25 ( V_22 ) ;
return V_26 ;
}
for ( V_307 = 0 ; V_307 < V_2 -> V_238 ; V_307 ++ ) {
V_337 = & V_2 -> V_15 -> V_340 [ V_307 ] ;
F_167 ( V_2 , V_337 , V_307 ) ;
}
if ( V_2 -> V_4 -> V_135 == V_309 ) {
for ( V_307 = 0 ; V_307 < V_2 -> V_98 ; V_307 ++ ) {
V_306 = & V_2 -> V_15 -> V_19 [ V_307 ] ;
F_208 ( V_2 , V_306 ) ;
}
}
if ( V_2 -> V_4 -> V_135 == V_317 ) {
V_2 -> V_4 -> V_362 = 0 ;
F_171 ( V_2 , 1 ) ;
}
F_123 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_209 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_64 , & V_2 -> V_46 ) )
return - V_363 ;
F_22 ( V_22 ) ;
F_189 ( V_2 , V_22 ) ;
F_173 ( V_2 , V_22 ) ;
F_25 ( V_22 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_68 ( V_2 -> V_22 , L_35 , V_55 ) ;
return 0 ;
}
int
F_210 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_45 ( V_64 , & V_2 -> V_46 ) )
return - V_363 ;
if ( V_2 -> V_338 == V_339 ) {
F_22 ( V_22 ) ;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( ! V_52 ) {
F_165 ( V_2 , V_22 ) ;
F_125 ( V_22 , V_364 ) ;
}
}
F_25 ( V_22 ) ;
}
F_126 ( V_64 , & V_2 -> V_46 ) ;
return V_52 ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_365 = V_4 -> V_145 ;
T_3 V_16 ;
V_4 -> V_366 = V_367 ;
if ( V_365 <= 2 )
V_16 = ( V_368 - V_367 ) /
V_365 ;
else
V_16 = ( V_369 - V_367 ) /
V_365 ;
V_4 -> V_56 = V_16 ;
}
static int F_212 ( struct V_1 * V_2 ,
T_2 V_370 , T_2 V_371 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_52 = 0 ;
if ( V_370 ) {
V_52 = F_213 ( V_22 , V_370 ) ;
if ( V_52 ) {
F_122 ( V_22 , L_36 ,
V_370 ) ;
return V_52 ;
}
}
if ( V_371 ) {
V_52 = F_214 ( V_22 , V_371 ) ;
if ( V_52 )
F_122 ( V_22 , L_37 ,
V_371 ) ;
}
return V_52 ;
}
int
F_215 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_372 )
{
int V_52 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_373 = 1 ;
V_2 -> V_4 -> V_374 = 0 ;
F_216 ( V_2 ) ;
V_22 -> V_375 = & V_376 ;
V_22 -> V_377 = V_378 * V_379 ;
F_217 ( V_22 , V_22 -> V_341 ) ;
V_22 -> V_380 = ( F_20 ( V_2 ) ) ?
& V_381 : & V_382 ;
V_22 -> V_82 |= ( V_383 | V_384 | V_385 |
V_386 | V_387 |
V_388 ) ;
V_22 -> V_389 |= ( V_383 | V_384 |
V_386 ) ;
if ( F_134 ( V_2 ) ) {
V_22 -> V_82 |= ( V_390 | V_391 ) ;
V_22 -> V_389 |= ( V_390 | V_391 ) ;
}
if ( V_372 ) {
V_22 -> V_82 |= V_392 ;
V_22 -> V_389 |= V_392 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_82 |= ( V_393 ) ;
if ( F_20 ( V_2 ) )
V_22 -> V_82 |= V_394 ;
if ( V_2 -> V_4 -> V_8 & V_395 )
V_22 -> V_82 |= V_343 ;
if ( F_218 ( V_2 ) ) {
V_22 -> V_82 |= V_396 ;
V_22 -> V_397 = V_384 |
V_396 |
V_390 |
V_391 ;
}
if ( F_50 ( V_2 ) )
V_22 -> V_397 |= V_385 ;
V_22 -> V_398 = V_22 -> V_82 ;
V_22 -> V_399 |= V_400 ;
V_22 -> V_124 = V_2 -> V_104 [ 0 ] . V_100 ;
V_22 -> V_401 = V_402 ;
V_22 -> V_251 = V_403 ;
V_52 = F_212 ( V_2 , V_2 -> V_96 ,
V_2 -> V_98 ) ;
if ( V_52 )
return V_52 ;
F_219 ( V_2 -> V_404 ) ;
V_52 = F_220 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_38 ) ;
return V_52 ;
}
return 0 ;
}
static int F_221 ( struct V_23 * V_5 , int * V_372 )
{
if ( ! F_222 ( V_5 , F_223 ( 64 ) ) &&
! F_224 ( V_5 , F_223 ( 64 ) ) )
* V_372 = 1 ;
else if ( ! F_222 ( V_5 , F_223 ( 32 ) ) &&
! F_224 ( V_5 , F_223 ( 32 ) ) )
* V_372 = 0 ;
else {
F_83 ( & V_5 -> V_30 , L_39 ) ;
return - V_116 ;
}
return 0 ;
}
void F_225 ( struct V_1 * V_2 )
{
int V_307 ;
struct V_10 * V_11 ;
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
if ( V_11 ) {
F_86 ( V_11 -> V_405 ) ;
V_11 -> V_405 = NULL ;
}
}
F_7 ( V_2 -> V_11 ) ;
}
int F_226 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_307 , V_100 , V_201 ;
struct V_10 * V_11 ;
struct V_406 * V_405 ;
V_11 = F_66 ( V_2 -> V_96 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_57 ;
V_2 -> V_11 = V_11 ;
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
V_11 -> V_407 = V_2 -> V_236 ;
V_11 -> V_408 = F_227 ( V_22 , V_307 ) ;
V_405 = F_81 ( F_228 ( V_11 ) ) ;
if ( V_405 == NULL ) {
F_225 ( V_2 ) ;
return - V_57 ;
}
V_11 -> V_405 = V_405 ;
F_229 ( & V_11 -> V_409 ) ;
}
if ( F_65 ( V_2 ) ||
( F_57 ( V_2 ) && F_73 ( V_2 ) ) ) {
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_110 ) {
V_201 = V_2 -> V_98 + V_307 ;
V_100 = V_2 -> V_104 [ V_201 ] . V_100 ;
V_11 -> V_124 = V_100 ;
}
}
}
return 0 ;
}
void F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_410 = 0 ;
if ( F_57 ( V_2 ) )
V_410 = V_411 ;
else if ( F_65 ( V_2 ) )
V_410 = V_412 ;
if ( V_4 -> V_83 [ 0 ] & V_413 )
F_231 ( V_2 , V_410 ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
F_100 ( V_2 ) ;
}
static int
F_233 ( struct V_23 * V_5 , const struct V_177 * V_178 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_52 , V_372 = - 1 ;
char V_414 [ V_415 + 19 ] ;
V_52 = F_234 ( V_5 ) ;
if ( V_52 )
return V_52 ;
if ( ! ( F_235 ( V_5 , 0 ) & V_416 ) ) {
V_52 = - V_417 ;
goto V_418;
}
V_52 = F_221 ( V_5 , & V_372 ) ;
if ( V_52 )
goto V_418;
V_52 = F_236 ( V_5 , V_419 ) ;
if ( V_52 )
goto V_418;
F_237 ( V_5 ) ;
F_238 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_52 = - V_57 ;
goto V_420;
}
switch ( V_178 -> V_6 ) {
case V_7 :
V_4 -> V_421 = & V_422 ;
V_4 -> V_423 = ( T_1 * ) V_424 ;
break;
case V_190 :
case V_191 :
case V_192 :
F_239 ( V_4 ) ;
break;
case V_193 :
case V_195 :
case V_194 :
F_240 ( V_4 ) ;
break;
default:
goto V_425;
}
V_52 = F_105 ( V_5 , V_4 ) ;
if ( V_52 )
goto V_425;
V_22 = F_241 ( sizeof( struct V_1 ) ,
V_426 ) ;
if ( ! V_22 ) {
V_52 = - V_57 ;
goto V_427;
}
F_242 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_428 = F_243 ( L_28 ) ;
if ( V_2 -> V_428 == NULL ) {
V_52 = - V_57 ;
F_83 ( & V_5 -> V_30 , L_40 ) ;
goto V_429;
}
V_52 = F_204 ( V_2 ) ;
if ( V_52 )
goto V_430;
V_2 -> V_431 = V_432 ;
V_4 -> V_433 = V_5 -> V_434 ;
V_4 -> V_151 = F_244 ( V_2 ) ;
if ( V_435 == V_436 )
V_2 -> V_53 = true ;
else if ( V_435 == V_437 )
V_2 -> V_438 = true ;
F_245 ( & V_2 -> V_4 -> V_439 ) ;
F_246 ( & V_2 -> V_4 -> V_440 ) ;
F_247 ( & V_2 -> V_441 ) ;
F_248 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_101 ( V_2 , V_178 ) ;
V_2 -> V_442 = V_2 -> V_4 -> V_27 ;
F_232 ( V_2 ) ;
V_52 = F_249 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_41
L_42 ) ;
goto V_443;
}
if ( V_2 -> V_4 -> V_111 ) {
if ( F_56 ( V_2 ) == 1 )
F_62 ( V_2 ,
V_115 ) ;
else
F_62 ( V_2 ,
V_444 ) ;
F_63 ( V_2 ,
V_445 ) ;
} else {
F_62 ( V_2 , V_115 ) ;
F_63 ( V_2 , V_115 ) ;
}
V_52 = F_250 ( V_2 ) ;
if ( V_52 )
goto V_353;
V_2 -> V_41 |= V_446 ;
} else if ( F_65 ( V_2 ) ) {
F_251 ( V_2 , V_178 ) ;
V_2 -> V_442 = V_2 -> V_4 -> V_27 ;
V_52 = F_252 ( V_2 , V_372 ) ;
if ( V_52 ) {
switch ( V_52 ) {
case - V_447 :
F_83 ( & V_5 -> V_30 , L_43 ) ;
F_83 ( & V_5 -> V_30 , L_44 ) ;
goto V_353;
case - V_57 :
F_83 ( & V_5 -> V_30 , L_45 ) ;
goto V_353;
case - V_43 :
F_83 ( & V_5 -> V_30 , L_46 ) ;
goto V_353;
default:
F_83 ( & V_5 -> V_30 , L_47 ) ;
goto V_443;
}
}
if ( F_20 ( V_2 ) )
return 0 ;
} else {
F_83 ( & V_5 -> V_30 ,
L_48 , V_55 ) ;
V_52 = - V_417 ;
goto V_353;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_49 ) ;
F_253 ( V_2 ) ;
if ( V_2 -> V_442 == 0 ) {
F_111 ( V_2 , V_414 ) ;
F_37 ( L_50 ,
F_254 ( V_448 ) ,
V_414 , V_2 -> V_4 -> V_433 ) ;
}
if ( F_65 ( V_2 ) && ! V_125 &&
! ! V_121 )
F_11 ( & V_5 -> V_30 ,
L_51 ) ;
if ( F_57 ( V_2 ) ) {
F_255 ( V_2 -> V_404 ) ;
F_256 ( V_2 -> V_404 ) ;
V_52 = F_257 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_52 ) ;
goto V_449;
}
}
V_52 = F_89 ( V_2 ) ;
if ( V_52 )
goto V_450;
if ( V_2 -> V_442 == 0 )
F_230 ( V_2 ) ;
V_52 = F_215 ( V_2 , V_22 , V_372 ) ;
if ( V_52 )
goto V_450;
F_258 ( V_5 , V_2 ) ;
if ( F_57 ( V_2 ) )
F_259 ( V_2 , V_451 ,
V_452 ) ;
switch ( V_2 -> V_4 -> V_143 ) {
case V_144 :
F_71 ( & V_2 -> V_5 -> V_30 , L_53 ,
V_2 -> V_22 -> V_207 ) ;
break;
case V_147 :
F_71 ( & V_2 -> V_5 -> V_30 , L_54 ,
V_2 -> V_22 -> V_207 ) ;
break;
}
if ( V_2 -> V_438 )
F_260 ( V_2 ) ;
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
return 0 ;
V_450:
if ( F_65 ( V_2 ) )
F_263 ( V_2 ) ;
V_449:
F_84 ( V_2 ) ;
F_264 ( V_2 ) ;
F_265 ( V_2 , 0 ) ;
V_353:
F_205 ( V_2 ) ;
V_430:
F_266 ( V_2 -> V_428 ) ;
V_429:
F_267 ( V_22 ) ;
V_427:
F_87 ( V_4 ) ;
V_425:
F_7 ( V_4 ) ;
V_420:
F_268 ( V_5 ) ;
V_418:
F_269 ( V_5 ) ;
return V_52 ;
V_443:
F_123 ( V_453 , & V_2 -> V_46 ) ;
V_22 -> V_375 = & V_454 ;
V_22 -> V_380 = & V_455 ;
V_4 -> V_143 = V_147 ;
if ( F_65 ( V_2 ) )
V_2 -> V_123 = NULL ;
else
V_4 -> V_456 = V_457 ;
V_52 = F_220 ( V_22 ) ;
if ( V_52 ) {
F_83 ( & V_5 -> V_30 , L_55 ) ;
F_265 ( V_2 , 0 ) ;
goto V_353;
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
if ( F_65 ( V_2 ) ) {
F_275 ( V_2 , 0 ) ;
F_47 ( & V_2 -> V_458 ) ;
F_263 ( V_2 ) ;
F_276 ( V_2 ) ;
F_277 ( V_4 -> V_459 ) ;
F_7 ( V_4 -> V_460 ) ;
}
F_278 ( V_2 -> V_404 ) ;
F_199 ( V_2 ) ;
F_7 ( V_2 -> V_157 ) ;
F_7 ( V_2 -> V_159 ) ;
if ( F_57 ( V_2 ) )
F_265 ( V_2 , 0 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_279 ( V_2 ) ;
F_84 ( V_2 ) ;
F_280 ( V_2 ) ;
F_281 ( V_2 ) ;
F_87 ( V_2 -> V_4 ) ;
F_151 ( V_2 ) ;
F_282 ( V_5 ) ;
F_268 ( V_5 ) ;
F_269 ( V_5 ) ;
if ( V_2 -> V_428 ) {
F_266 ( V_2 -> V_428 ) ;
V_2 -> V_428 = NULL ;
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
int V_461 ;
V_461 = F_284 ( V_5 ) ;
if ( V_461 )
return V_461 ;
F_286 ( V_5 , F_287 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_288 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
int V_52 ;
V_52 = F_234 ( V_5 ) ;
if ( V_52 )
return V_52 ;
F_286 ( V_5 , V_462 ) ;
F_237 ( V_5 ) ;
F_289 ( V_5 ) ;
return F_290 ( V_2 ) ;
}
static int F_291 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
int V_52 ;
if ( F_21 ( V_453 , & V_2 -> V_46 ) ) {
F_122 ( V_22 , L_56 ,
V_55 ) ;
return - V_116 ;
}
F_180 ( V_22 ) ;
V_52 = F_190 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_165 ( V_2 , V_22 ) ;
if ( V_52 )
F_199 ( V_2 ) ;
return V_52 ;
}
static int F_292 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_177 ( V_2 , V_22 ) ;
return 0 ;
}
void F_260 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_134 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_463 = 0 ;
T_3 V_154 = 0 ;
if ( V_2 -> V_346 . V_464 && V_2 -> V_346 . V_465 )
return;
V_154 = V_2 -> V_4 -> V_145 ;
F_229 ( & V_2 -> V_466 ) ;
F_229 ( & V_2 -> V_467 ) ;
if ( F_20 ( V_2 ) ) {
V_463 = V_468 - 1 ;
V_2 -> V_346 . V_469 = V_470 ;
} else if ( F_57 ( V_2 ) ) {
V_463 = V_369 ;
V_2 -> V_346 . V_469 = V_471 ;
} else {
V_463 = V_472 ;
V_2 -> V_346 . V_469 = V_473 ;
}
V_34 = F_66 ( V_2 -> V_346 . V_469 ,
sizeof( struct V_474 ) , V_475 ) ;
if ( ! V_34 )
return;
V_2 -> V_346 . V_464 = ( V_463 / V_154 ) ;
V_2 -> V_346 . V_465 = V_34 ;
F_68 ( V_22 , L_57 ,
V_154 , V_2 -> V_346 . V_464 ) ;
for ( V_134 = 0 ; V_134 < V_2 -> V_346 . V_469 ; V_134 ++ )
F_293 ( & V_2 -> V_346 . V_465 [ V_134 ] ) ;
V_2 -> V_476 . V_469 = V_2 -> V_346 . V_469 ;
V_34 = F_66 ( V_2 -> V_476 . V_469 ,
sizeof( struct V_474 ) , V_475 ) ;
if ( ! V_34 )
return;
V_2 -> V_476 . V_464 = ( V_463 / V_154 ) ;
V_2 -> V_476 . V_465 = V_34 ;
for ( V_134 = 0 ; V_134 < V_2 -> V_476 . V_469 ; V_134 ++ )
F_293 ( & V_2 -> V_476 . V_465 [ V_134 ] ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
if ( V_2 -> V_346 . V_464 )
F_7 ( V_2 -> V_346 . V_465 ) ;
V_2 -> V_346 . V_465 = NULL ;
V_2 -> V_346 . V_464 = 0 ;
if ( V_2 -> V_476 . V_464 )
F_7 ( V_2 -> V_476 . V_465 ) ;
V_2 -> V_476 . V_464 = 0 ;
V_2 -> V_476 . V_465 = NULL ;
}
int F_294 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_477 , V_478 , V_248 = 0 ;
int V_479 = 0 ;
if ( F_65 ( V_2 ) )
V_248 = F_295 ( V_2 -> V_4 , V_480 ) ;
if ( F_57 ( V_2 ) )
V_248 = F_97 ( V_2 , V_481 ) ;
V_477 = F_296 ( V_248 ) ;
V_478 = F_297 ( V_248 ) ;
if ( V_477 == V_482 ) {
F_83 ( & V_22 -> V_30 ,
L_58
L_59 ,
V_478 ) ;
V_479 = 1 ;
} else if ( V_477 == V_483 ) {
if ( V_2 -> V_4 -> V_248 == V_484 ) {
F_83 ( & V_22 -> V_30 ,
L_60
L_61
L_62 ,
V_478 ) ;
}
} else {
if ( V_2 -> V_4 -> V_248 == V_483 ) {
F_71 ( & V_22 -> V_30 ,
L_63
L_64 , V_478 ) ;
}
}
V_2 -> V_4 -> V_248 = V_477 ;
return V_479 ;
}
static inline void F_298 ( struct V_10 * V_11 )
{
int V_134 ;
struct V_485 * V_486 ;
for ( V_134 = 0 ; V_134 < V_11 -> V_407 ; V_134 ++ ) {
V_486 = & V_11 -> V_487 [ V_134 ] ;
F_37 ( L_65 , V_134 ) ;
F_299 ( V_488 , L_66 , V_489 , 16 , 1 ,
& V_11 -> V_487 [ V_134 ] ,
sizeof( struct V_485 ) , true ) ;
}
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_336 * V_337 ;
struct V_18 * V_306 ;
struct V_10 * V_11 ;
int V_307 ;
if ( ! V_22 || ! F_175 ( V_22 ) )
return;
for ( V_307 = 0 ; V_307 < V_2 -> V_238 ; V_307 ++ ) {
V_337 = & V_15 -> V_340 [ V_307 ] ;
if ( ! V_337 )
continue;
F_68 ( V_22 ,
L_67 ,
V_307 , F_301 ( V_337 -> V_490 ) ,
V_337 -> V_12 , V_337 -> V_407 ) ;
}
for ( V_307 = 0 ; V_307 < V_2 -> V_98 ; V_307 ++ ) {
V_306 = & ( V_15 -> V_19 [ V_307 ] ) ;
if ( ! V_306 )
continue;
F_68 ( V_22 ,
L_68 ,
V_307 , F_301 ( V_306 -> V_491 ) ,
V_306 -> V_492 , F_301 ( V_306 -> V_493 ) ,
V_306 -> V_407 ) ;
}
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
if ( ! V_11 )
continue;
F_68 ( V_22 , L_69 ,
V_307 , V_11 -> V_494 ) ;
F_68 ( V_22 ,
L_70 ,
V_11 -> V_495 . V_496 ,
V_11 -> V_495 . V_497 ,
V_11 -> V_495 . V_498 ,
V_11 -> V_495 . V_499 ) ;
if ( V_11 -> V_493 )
F_68 ( V_22 , L_71 ,
F_301 ( V_11 -> V_493 ) ) ;
F_68 ( V_22 ,
L_72 ,
F_301 ( V_11 -> V_13 ) ,
V_11 -> V_12 , V_11 -> V_500 ,
F_302 ( * ( V_11 -> V_501 ) ) ) ;
F_68 ( V_22 , L_73 ,
V_11 -> V_407 , F_303 ( V_11 ) ) ;
if ( F_304 ( V_2 -> V_4 ) )
F_298 ( V_11 ) ;
}
}
static void F_305 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
return;
F_300 ( V_2 ) ;
if ( ++ V_2 -> V_502 >= V_503 ||
F_304 ( V_2 -> V_4 ) ) {
F_122 ( V_22 , L_74 ) ;
if ( F_57 ( V_2 ) )
V_2 -> V_279 = 1 ;
else if ( F_65 ( V_2 ) )
F_306 ( V_2 ,
V_504 ) ;
} else {
F_122 ( V_22 , L_75 ) ;
V_2 -> V_4 -> V_345 = 1 ;
}
}
static struct V_505 * F_307 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_505 * V_355 = & V_22 -> V_355 ;
if ( F_21 ( V_45 , & V_2 -> V_46 ) )
F_308 ( V_2 ) ;
V_355 -> V_333 = V_2 -> V_355 . V_506 + V_2 -> V_355 . V_507 ;
V_355 -> V_329 = V_2 -> V_355 . V_508 ;
V_355 -> V_509 = V_2 -> V_355 . V_510 + V_2 -> V_355 . V_511 ;
V_355 -> V_512 = V_2 -> V_355 . V_513 ;
V_355 -> V_514 = V_2 -> V_355 . V_515 ;
V_355 -> V_516 = V_2 -> V_355 . V_517 ;
return V_355 ;
}
static T_10 F_309 ( struct V_1 * V_2 )
{
T_1 V_518 ;
V_518 = F_301 ( V_2 -> V_129 ) ;
if ( ! ( V_518 & V_2 -> V_4 -> V_127 ) )
return V_519 ;
V_518 = F_301 ( V_2 -> V_131 ) ;
if ( ! F_310 ( V_518 ) )
return V_519 ;
F_3 ( 0xffffffff , V_2 -> V_123 ) ;
F_301 ( V_2 -> V_129 ) ;
F_301 ( V_2 -> V_129 ) ;
return V_520 ;
}
static T_10 V_310 ( int V_124 , void * V_174 )
{
struct V_18 * V_306 = V_174 ;
struct V_1 * V_2 = V_306 -> V_2 ;
if ( V_2 -> V_41 & V_110 )
goto V_521;
else if ( V_2 -> V_41 & V_109 ) {
F_3 ( 0xffffffff , V_2 -> V_123 ) ;
goto V_521;
}
if ( F_311 ( V_2 ) == V_519 )
return V_519 ;
V_521:
V_2 -> V_4 -> V_522 ++ ;
F_208 ( V_2 , V_306 ) ;
return V_520 ;
}
static T_10 V_315 ( int V_124 , void * V_174 )
{
struct V_18 * V_306 = V_174 ;
struct V_1 * V_2 = V_306 -> V_2 ;
if ( F_311 ( V_2 ) == V_519 )
return V_519 ;
F_312 ( & V_306 -> V_523 ) ;
return V_520 ;
}
static T_10 V_314 ( int V_124 , void * V_174 )
{
struct V_18 * V_306 = V_174 ;
struct V_1 * V_2 = V_306 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_123 ) ;
F_312 ( & V_306 -> V_523 ) ;
return V_520 ;
}
static T_10 V_313 ( int V_124 , void * V_174 )
{
struct V_18 * V_306 = V_174 ;
F_312 ( & V_306 -> V_523 ) ;
return V_520 ;
}
static T_10 V_319 ( int V_124 , void * V_174 )
{
struct V_10 * V_11 = V_174 ;
F_312 ( & V_11 -> V_523 ) ;
return V_520 ;
}
static void F_313 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_18 * V_306 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_307 ;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
return;
V_15 = V_2 -> V_15 ;
for ( V_307 = 0 ; V_307 < V_2 -> V_98 ; V_307 ++ ) {
V_306 = & V_15 -> V_19 [ V_307 ] ;
F_203 ( V_2 , V_306 ) ;
F_312 ( & V_306 -> V_523 ) ;
}
if ( V_2 -> V_41 & V_110 ) {
if ( ( F_65 ( V_2 ) &&
( V_2 -> V_41 & V_318 ) ) ||
( F_57 ( V_2 ) &&
! F_73 ( V_2 ) ) )
return;
for ( V_307 = 0 ; V_307 < V_2 -> V_96 ; V_307 ++ ) {
V_11 = & V_2 -> V_11 [ V_307 ] ;
F_314 ( V_2 , V_11 ) ;
F_312 ( & V_11 -> V_523 ) ;
}
}
}
static void
F_154 ( struct V_1 * V_2 , T_2 V_524 )
{
T_1 V_525 ;
V_525 = V_2 -> V_442 & 0xf ;
V_525 |= V_524 << 7 ;
V_525 |= ( V_432 - V_2 -> V_431 ) << 8 ;
F_99 ( V_2 , V_526 , V_525 ) ;
V_2 -> V_431 = V_432 ;
}
static int
F_315 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_525 ;
F_316 ( V_46 != V_527 &&
V_46 != V_528 ) ;
if ( F_96 ( V_2 ) )
return - V_116 ;
V_525 = F_97 ( V_2 , V_529 ) ;
if ( V_46 == V_527 )
F_317 ( V_525 , V_2 -> V_442 ) ;
else if ( V_46 == V_528 )
F_318 ( V_525 , V_2 -> V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
static int
F_319 ( struct V_1 * V_2 )
{
T_1 V_525 ;
if ( F_96 ( V_2 ) )
return - V_363 ;
V_525 = F_97 ( V_2 , V_529 ) ;
F_320 ( V_525 , V_2 -> V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
void F_265 ( struct V_1 * V_2 , T_2 V_530 )
{
T_1 V_525 ;
if ( F_96 ( V_2 ) )
goto V_52;
V_525 = F_97 ( V_2 , V_531 ) ;
F_321 ( V_525 , V_2 -> V_442 ) ;
F_99 ( V_2 , V_531 , V_525 ) ;
if ( V_530 ) {
F_99 ( V_2 , V_302 ,
V_304 ) ;
F_71 ( & V_2 -> V_5 -> V_30 ,
L_76 ) ;
} else if ( ! ( V_525 & 0x11111111 ) )
F_99 ( V_2 , V_302 ,
V_532 ) ;
V_525 = F_97 ( V_2 , V_529 ) ;
F_320 ( V_525 , V_2 -> V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
F_100 ( V_2 ) ;
V_52:
V_2 -> V_533 = 0 ;
V_2 -> V_41 &= ~ V_534 ;
F_126 ( V_535 , & V_2 -> V_46 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
}
static int
F_322 ( struct V_1 * V_2 )
{
int V_536 , V_46 , V_537 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_97 ( V_2 , V_529 ) ;
V_536 = F_97 ( V_2 , V_531 ) ;
if ( V_2 -> V_41 & V_538 ) {
V_537 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_536 = V_536 & V_537 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_536 & 0x11111111 ) ) ||
( ( V_536 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_323 ( struct V_1 * V_2 )
{
T_1 V_525 = F_97 ( V_2 , V_539 ) ;
if ( V_525 != V_540 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_540 , V_525 ) ;
}
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 )
{
T_1 V_525 , V_541 ;
T_2 V_542 = V_2 -> V_542 ;
T_2 V_442 = V_2 -> V_442 ;
T_2 V_26 ;
if ( F_178 ( V_535 , & V_2 -> V_46 ) )
return 1 ;
if ( F_96 ( V_2 ) )
return - 1 ;
V_525 = F_97 ( V_2 , V_531 ) ;
if ( ! ( V_525 & ( 1 << ( V_442 * 4 ) ) ) ) {
F_324 ( V_525 , V_442 ) ;
F_99 ( V_2 , V_531 , V_525 ) ;
}
V_541 = F_97 ( V_2 , V_302 ) ;
F_325 ( V_2 , V_543 , L_79 , V_541 ) ;
switch ( V_541 ) {
case V_532 :
F_99 ( V_2 , V_302 ,
V_544 ) ;
F_99 ( V_2 , V_539 ,
V_540 ) ;
F_154 ( V_2 , 0 ) ;
F_100 ( V_2 ) ;
return 1 ;
case V_303 :
V_26 = F_323 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
case V_527 :
V_525 = F_97 ( V_2 , V_529 ) ;
F_317 ( V_525 , V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
break;
case V_528 :
V_525 = F_97 ( V_2 , V_529 ) ;
F_318 ( V_525 , V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
break;
case V_304 :
F_83 ( & V_2 -> V_5 -> V_30 , L_80 ) ;
F_100 ( V_2 ) ;
return - 1 ;
case V_544 :
case V_545 :
break;
}
F_100 ( V_2 ) ;
do {
F_141 ( 1000 ) ;
V_541 = F_97 ( V_2 , V_302 ) ;
if ( V_541 == V_545 )
continue;
} while ( ( V_541 != V_303 ) && -- V_542 );
if ( ! V_542 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_81 ) ;
return - 1 ;
}
if ( F_96 ( V_2 ) )
return - 1 ;
V_525 = F_97 ( V_2 , V_529 ) ;
F_320 ( V_525 , V_442 ) ;
F_99 ( V_2 , V_529 , V_525 ) ;
V_26 = F_323 ( V_2 ) ;
F_100 ( V_2 ) ;
return V_26 ;
}
static void
F_326 ( struct V_546 * V_66 )
{
struct V_1 * V_2 = F_327 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
T_1 V_547 = 0xf ;
T_1 V_525 ;
if ( F_96 ( V_2 ) )
goto V_548;
V_547 = F_97 ( V_2 , V_302 ) ;
if ( V_547 == V_545 ||
V_547 == V_528 ) {
F_100 ( V_2 ) ;
F_259 ( V_2 , F_326 ,
V_452 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_149 == V_183 ) {
F_100 ( V_2 ) ;
goto V_549;
}
if ( V_547 == V_544 ||
V_547 == V_303 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_82
L_83 ) ;
goto V_550;
}
if ( V_2 -> V_551 ++ > V_2 -> V_552 ) {
F_71 ( & V_2 -> V_5 -> V_30 , L_84 ,
V_2 -> V_552 ) ;
goto V_550;
}
if ( ! F_322 ( V_2 ) ) {
V_550:
V_547 = F_97 ( V_2 , V_302 ) ;
if ( V_547 == V_527 ) {
F_99 ( V_2 , V_302 ,
V_544 ) ;
F_123 ( V_535 , & V_2 -> V_46 ) ;
F_325 ( V_2 , V_553 , L_85 ) ;
F_154 ( V_2 , 0 ) ;
V_525 = F_97 ( V_2 ,
V_529 ) ;
F_317 ( V_525 , V_2 -> V_442 ) ;
F_99 ( V_2 ,
V_529 , V_525 ) ;
}
F_100 ( V_2 ) ;
F_174 () ;
if ( F_328 ( V_2 ) &&
( V_2 -> V_41 & V_538 ) ) {
F_325 ( V_2 , V_553 , L_86 ) ;
F_329 ( V_2 ) ;
V_2 -> V_41 |= V_534 ;
}
F_176 () ;
V_2 -> V_41 &= ~ V_538 ;
if ( ! V_2 -> V_184 -> V_554 ( V_2 ) ) {
F_259 ( V_2 , V_555 , 0 ) ;
V_2 -> V_551 = 0 ;
return;
}
goto V_548;
}
F_100 ( V_2 ) ;
V_549:
V_547 = F_97 ( V_2 , V_302 ) ;
F_325 ( V_2 , V_543 , L_87 , V_547 ) ;
switch ( V_547 ) {
case V_303 :
if ( ! F_249 ( V_2 ) ) {
F_259 ( V_2 , V_555 , 0 ) ;
V_2 -> V_551 = 0 ;
return;
}
case V_304 :
break;
default:
F_259 ( V_2 ,
F_326 , V_452 ) ;
return;
}
V_548:
F_83 ( & V_2 -> V_5 -> V_30 , L_88
L_89 , V_547 , V_2 -> V_551 ) ;
F_25 ( V_2 -> V_22 ) ;
F_265 ( V_2 , 0 ) ;
}
static void
F_330 ( struct V_546 * V_66 )
{
struct V_1 * V_2 = F_327 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_518 ;
F_22 ( V_22 ) ;
if ( V_2 -> V_547 == V_528 ) {
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
} else
F_189 ( V_2 , V_22 ) ;
V_518 = F_97 ( V_2 , V_556 ) ;
if ( V_518 & V_557 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_90 ,
V_518 ) ;
if ( F_331 ( V_518 ) == V_558 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_91
L_92 ) ;
F_83 ( & V_2 -> V_5 -> V_30 ,
L_93 ) ;
}
goto V_548;
}
if ( V_2 -> V_4 -> V_248 == V_482 ) {
F_83 ( & V_2 -> V_5 -> V_30 , L_94 ,
V_2 -> V_4 -> V_248 ) ;
goto V_548;
}
if ( ! ( V_2 -> V_41 & V_538 ) ) {
if ( F_315 ( V_2 , V_2 -> V_547 ) ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_95
L_96 ) ;
goto V_548;
}
}
V_2 -> V_551 = 0 ;
F_259 ( V_2 , F_326 , V_452 ) ;
return;
V_548:
F_25 ( V_22 ) ;
F_265 ( V_2 , 1 ) ;
}
static void
F_332 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_97 ( V_2 , V_293 ) ;
if ( V_46 == V_559 )
return;
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_293 ,
V_559 ) ;
F_100 ( V_2 ) ;
}
static void F_333 ( struct V_1 * V_2 ,
T_1 V_560 )
{
T_1 V_46 , V_561 = 0 , V_562 = 0 ;
F_334 ( V_561 ) ;
F_335 ( V_561 ) ;
F_152 ( V_2 , V_563 , V_561 ) ;
F_336 ( V_562 ) ;
F_337 ( V_562 ) ;
F_338 ( V_562 ) ;
F_339 ( V_562 ) ;
F_152 ( V_2 , V_564 , V_562 ) ;
F_71 ( & V_2 -> V_5 -> V_30 , L_97
L_98 ) ;
V_2 -> V_279 = 1 ;
if ( F_96 ( V_2 ) )
return;
V_46 = F_97 ( V_2 , V_302 ) ;
if ( F_21 ( V_453 , & V_2 -> V_46 ) ) {
F_122 ( V_2 -> V_22 , L_56 ,
V_55 ) ;
F_100 ( V_2 ) ;
return;
}
if ( V_46 == V_303 ) {
F_99 ( V_2 , V_302 ,
V_527 ) ;
V_2 -> V_41 |= V_538 ;
F_325 ( V_2 , V_553 , L_99 ) ;
F_154 ( V_2 , 0 ) ;
}
F_99 ( V_2 , V_293 ,
V_559 ) ;
F_100 ( V_2 ) ;
}
static void
F_143 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return;
F_99 ( V_2 , V_293 ,
V_294 ) ;
F_325 ( V_2 , V_553 , L_100 ) ;
F_100 ( V_2 ) ;
}
void F_259 ( struct V_1 * V_2 ,
T_11 V_67 , int V_565 )
{
if ( F_21 ( V_566 , & V_2 -> V_46 ) )
return;
F_340 ( & V_2 -> V_65 , V_67 ) ;
F_341 ( V_2 -> V_428 , & V_2 -> V_65 ,
F_342 ( V_565 ) ) ;
}
static void
V_555 ( struct V_546 * V_66 )
{
struct V_1 * V_2 = F_327 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_292 ;
if ( V_2 -> V_4 -> V_149 != V_150 ) {
V_292 = F_97 ( V_2 ,
V_293 ) ;
if ( V_2 -> V_551 ++ > V_291 )
F_265 ( V_2 , 0 ) ;
else if ( V_292 != V_294 )
F_259 ( V_2 , V_555 ,
V_452 ) ;
else
goto V_567;
F_325 ( V_2 , V_553 , L_101 ) ;
return;
}
V_567:
F_256 ( V_2 -> V_404 ) ;
if ( F_175 ( V_22 ) ) {
if ( F_173 ( V_2 , V_22 ) )
goto V_521;
F_125 ( V_22 , V_364 ) ;
}
V_521:
F_25 ( V_22 ) ;
V_2 -> V_533 = 0 ;
V_2 -> V_41 &= ~ V_534 ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
if ( V_2 -> V_442 == 0 )
F_230 ( V_2 ) ;
if ( ! F_319 ( V_2 ) )
F_259 ( V_2 , V_451 ,
V_452 ) ;
}
static int
F_343 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_216 * V_217 = & V_4 -> V_217 ;
T_1 V_46 = 0 , V_568 ;
T_1 V_569 ;
int V_52 = 0 ;
if ( F_294 ( V_2 ) )
goto V_570;
if ( V_2 -> V_279 )
F_344 ( V_2 , 0 ) ;
V_46 = F_97 ( V_2 , V_302 ) ;
if ( V_46 == V_527 ) {
F_332 ( V_2 ) ;
V_2 -> V_279 = 1 ;
} else if ( V_46 == V_528 )
goto V_570;
V_568 = F_97 ( V_2 , V_571 ) ;
if ( V_568 != V_2 -> V_568 ) {
V_2 -> V_568 = V_568 ;
V_2 -> V_533 = 0 ;
if ( V_2 -> V_279 )
goto V_570;
if ( V_4 -> V_345 && V_572 )
F_209 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_533 < V_573 )
return 0 ;
V_2 -> V_41 |= V_534 ;
F_344 ( V_2 , 0 ) ;
if ( V_572 )
F_126 ( V_574 , & V_2 -> V_46 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_102 ) ;
V_569 = F_97 ( V_2 , V_556 ) ;
F_83 ( & V_2 -> V_5 -> V_30 , L_103
L_104
L_105
L_106
L_107 ,
V_569 ,
F_97 ( V_2 , V_575 ) ,
F_118 ( V_2 , V_576 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_577 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_578 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_579 + 0x3c , & V_52 ) ,
F_118 ( V_2 , V_580 + 0x3c , & V_52 ) ) ;
if ( F_331 ( V_569 ) == 0x67 )
F_83 ( & V_2 -> V_5 -> V_30 ,
L_108
L_109 ) ;
V_570:
V_2 -> V_547 = ( V_46 == V_528 ) ? V_46 :
V_527 ;
if ( V_572 && ! F_45 ( V_64 ,
& V_2 -> V_46 ) ) {
F_259 ( V_2 , F_330 , 0 ) ;
F_325 ( V_2 , V_553 , L_110 ) ;
} else if ( ! V_572 && V_217 -> V_581 &&
V_2 -> V_41 & V_538 ) {
F_329 ( V_2 ) ;
}
return 1 ;
}
void V_451 ( struct V_546 * V_66 )
{
struct V_1 * V_2 = F_327 ( V_66 ,
struct V_1 , V_65 . V_66 ) ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
goto V_582;
if ( F_343 ( V_2 ) )
return;
if ( V_2 -> V_346 . V_347 )
F_345 ( V_2 ) ;
V_582:
F_259 ( V_2 , V_451 , V_452 ) ;
}
static int F_346 ( struct V_23 * V_5 )
{
struct V_23 * V_583 ;
int V_525 = V_5 -> V_584 ;
while ( V_525 -- > 0 ) {
V_583 = F_347 ( F_348
( V_5 -> V_585 ) , V_5 -> V_585 -> V_586 ,
F_349 ( F_350 ( V_5 -> V_584 ) , V_525 ) ) ;
if ( ! V_583 )
continue;
if ( V_583 -> V_587 != V_588 ) {
F_351 ( V_583 ) ;
return 0 ;
}
F_351 ( V_583 ) ;
}
return 1 ;
}
static int F_352 ( struct V_23 * V_5 )
{
int V_52 , V_589 ;
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_590 = V_591 ;
V_52 = F_234 ( V_5 ) ;
if ( V_52 )
return V_52 ;
F_237 ( V_5 ) ;
F_289 ( V_5 ) ;
V_589 = F_346 ( V_5 ) ;
if ( F_96 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_149 != V_183 && V_589 ) {
V_2 -> V_279 = 1 ;
F_123 ( V_535 , & V_2 -> V_46 ) ;
F_99 ( V_2 , V_302 ,
V_544 ) ;
F_325 ( V_2 , V_553 , L_85 ) ;
}
F_100 ( V_2 ) ;
V_52 = F_249 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_319 ( V_2 ) ;
F_7 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
V_52 = F_257 ( V_2 ) ;
if ( V_52 ) {
F_7 ( V_2 -> V_104 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 ) {
F_265 ( V_2 , 1 ) ;
F_126 ( V_566 , & V_2 -> V_46 ) ;
F_25 ( V_22 ) ;
return V_52 ;
}
V_52 = F_173 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_521;
F_125 ( V_22 , V_364 ) ;
}
V_521:
F_25 ( V_22 ) ;
return V_52 ;
}
static T_12 F_353 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_592 )
return V_593 ;
if ( V_46 == V_591 )
return V_594 ;
F_123 ( V_566 , & V_2 -> V_46 ) ;
F_22 ( V_22 ) ;
F_47 ( & V_2 -> V_65 ) ;
if ( F_175 ( V_22 ) )
F_189 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
F_84 ( V_2 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
F_354 ( V_5 ) ;
F_269 ( V_5 ) ;
return V_595 ;
}
static T_12 F_355 ( struct V_23 * V_5 )
{
T_12 V_596 ;
F_174 () ;
V_596 = F_352 ( V_5 ) ? V_593 :
V_594 ;
F_176 () ;
return V_596 ;
}
static void F_356 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_271 ( V_5 ) ;
F_357 ( V_5 ) ;
V_46 = F_97 ( V_2 , V_302 ) ;
if ( V_46 == V_303 && F_178 ( V_566 ,
& V_2 -> V_46 ) )
F_259 ( V_2 , V_451 ,
V_452 ) ;
}
static T_12 F_358 ( struct V_23 * V_5 ,
T_13 V_46 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_597 * V_421 = V_2 -> V_4 -> V_421 ;
if ( V_421 -> V_598 ) {
return V_421 -> V_598 ( V_5 , V_46 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_111 ) ;
return V_593 ;
}
}
static T_12 F_359 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_597 * V_421 = V_2 -> V_4 -> V_421 ;
if ( V_421 -> V_599 ) {
return V_421 -> V_599 ( V_5 ) ;
} else {
F_83 ( & V_5 -> V_30 , L_112 ) ;
return V_593 ;
}
}
static void F_360 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_271 ( V_5 ) ;
struct V_597 * V_421 = V_2 -> V_4 -> V_421 ;
if ( V_421 -> V_600 )
V_421 -> V_600 ( V_5 ) ;
else
F_83 ( & V_5 -> V_30 , L_113 ) ;
}
static int
F_361 ( struct V_1 * V_2 )
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
V_2 -> V_279 = 0 ;
return V_52 ;
}
int F_362 ( struct V_1 * V_2 , T_14 V_86 ,
int V_87 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_601 = 0 ;
char V_602 [ 8 ] ;
int V_603 ;
if ( V_87 == V_91 ) {
V_601 = V_2 -> V_92 ;
V_603 = V_2 -> V_98 ;
strcpy ( V_602 , L_114 ) ;
} else if ( V_87 == V_93 ) {
V_601 = V_2 -> V_94 ;
V_603 = V_2 -> V_96 ;
strcpy ( V_602 , L_115 ) ;
}
if ( ! F_363 ( V_86 ) ) {
F_122 ( V_22 , L_116 ,
V_602 ) ;
return - V_40 ;
}
if ( F_57 ( V_2 ) && ( V_87 == V_93 ) &&
! F_73 ( V_2 ) ) {
F_122 ( V_22 , L_117 ) ;
return - V_40 ;
}
if ( V_86 > F_61 () ) {
F_122 ( V_22 ,
L_118 ,
V_602 , F_61 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_364 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_604 , V_605 ;
int V_52 ;
if ( F_21 ( V_64 , & V_2 -> V_46 ) )
return - V_363 ;
V_604 = V_2 -> V_102 ;
V_605 = V_2 -> V_103 ;
F_22 ( V_22 ) ;
V_52 = F_212 ( V_2 , V_604 , V_605 ) ;
if ( V_52 )
goto V_521;
if ( F_175 ( V_22 ) )
F_177 ( V_2 , V_22 ) ;
F_199 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
F_263 ( V_2 ) ;
F_365 ( V_2 ) ;
}
F_84 ( V_2 ) ;
V_52 = F_257 ( V_2 ) ;
if ( V_52 ) {
F_7 ( V_2 -> V_104 ) ;
F_122 ( V_22 , L_34 ) ;
return V_52 ;
}
if ( ( V_604 != V_2 -> V_96 ) ||
( V_605 != V_2 -> V_98 ) ) {
V_52 = F_212 ( V_2 ,
V_2 -> V_96 ,
V_2 -> V_98 ) ;
if ( V_52 )
goto V_521;
}
if ( F_65 ( V_2 ) ) {
F_275 ( V_2 , 1 ) ;
V_52 = F_366 ( V_2 ) ;
F_367 ( V_2 ) ;
if ( V_52 ) {
F_83 ( & V_2 -> V_5 -> V_30 ,
L_119 ) ;
goto V_521;
}
}
if ( F_175 ( V_22 ) ) {
V_52 = F_190 ( V_2 ) ;
if ( V_52 )
goto V_521;
V_52 = F_165 ( V_2 , V_22 ) ;
if ( V_52 )
goto V_521;
F_125 ( V_22 , V_364 ) ;
}
V_521:
F_25 ( V_22 ) ;
F_126 ( V_64 , & V_2 -> V_46 ) ;
return V_52 ;
}
static void
F_368 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_606 )
{
struct V_607 * V_608 ;
V_608 = F_369 ( V_30 ) ;
if ( ! V_608 )
return;
F_370 (indev) {
switch ( V_606 ) {
case V_364 :
F_371 ( V_2 ,
V_609 -> V_610 , V_611 ) ;
break;
case V_268 :
F_371 ( V_2 ,
V_609 -> V_610 , V_612 ) ;
break;
default:
break;
}
} F_372 ( V_608 ) ;
F_373 ( V_608 ) ;
}
void F_125 ( struct V_21 * V_22 , unsigned long V_606 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_51 ;
F_368 ( V_2 , V_22 , V_606 ) ;
F_374 () ;
F_375 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_376 ( V_22 , F_377 ( V_613 ) , V_51 ) ;
if ( ! V_30 )
continue;
F_368 ( V_2 , V_30 , V_606 ) ;
}
F_378 () ;
}
static int F_379 ( struct V_614 * V_615 ,
unsigned long V_606 , void * V_616 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_380 ( V_616 ) ;
V_617:
if ( V_30 == NULL )
goto V_521;
if ( V_30 -> V_399 & V_618 ) {
V_30 = F_381 ( V_30 ) ;
goto V_617;
}
if ( ! F_382 ( V_30 ) )
goto V_521;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_521;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_521;
F_368 ( V_2 , V_30 , V_606 ) ;
V_521:
return V_619 ;
}
static int
F_383 ( struct V_614 * V_615 ,
unsigned long V_606 , void * V_616 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_620 * V_609 = (struct V_620 * ) V_616 ;
V_30 = V_609 -> V_621 ? V_609 -> V_621 -> V_30 : NULL ;
V_617:
if ( V_30 == NULL )
goto V_521;
if ( V_30 -> V_399 & V_618 ) {
V_30 = F_381 ( V_30 ) ;
goto V_617;
}
if ( ! F_382 ( V_30 ) )
goto V_521;
V_2 = F_19 ( V_30 ) ;
if ( ! V_2 )
goto V_521;
if ( ! F_21 ( V_45 , & V_2 -> V_46 ) )
goto V_521;
switch ( V_606 ) {
case V_364 :
F_371 ( V_2 , V_609 -> V_610 , V_611 ) ;
break;
case V_268 :
F_371 ( V_2 , V_609 -> V_610 , V_612 ) ;
break;
default:
break;
}
V_521:
return V_619 ;
}
void F_125 ( struct V_21 * V_30 , unsigned long V_606 )
{ }
static int T_15 F_384 ( void )
{
int V_26 ;
F_385 ( V_488 L_120 , V_622 ) ;
#ifdef F_386
F_387 ( & V_623 ) ;
F_388 ( & V_624 ) ;
#endif
V_26 = F_389 ( & V_625 ) ;
if ( V_26 ) {
#ifdef F_386
F_390 ( & V_624 ) ;
F_391 ( & V_623 ) ;
#endif
}
return V_26 ;
}
static void T_16 F_392 ( void )
{
F_393 ( & V_625 ) ;
#ifdef F_386
F_390 ( & V_624 ) ;
F_391 ( & V_623 ) ;
#endif
}
