static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 ;
F_4 () ;
F_5 ( V_5 -> V_11 ) ;
V_10 = - V_12 ;
if ( V_8 -> V_5 )
goto V_13;
V_10 = - V_14 ;
if ( V_5 -> V_8 )
goto V_13;
V_10 = 0 ;
V_8 -> V_5 = V_5 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_15 . V_6 = V_6 ;
F_6 ( V_5 -> V_11 ) ;
F_7 ( V_5 -> V_11 ) ;
F_8 ( V_5 -> V_15 . V_3 ) ;
F_9 ( & V_8 -> V_16 ) ;
V_13:
F_10 ( V_5 -> V_11 ) ;
return V_10 ;
}
static void F_11 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_11 ) ;
F_12 ( V_5 -> V_11 ) ;
V_5 -> V_8 = NULL ;
F_10 ( V_5 -> V_11 ) ;
F_13 ( & V_5 -> V_15 . V_3 -> V_17 ) ;
F_14 ( V_5 -> V_11 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_16 () ;
F_11 ( V_5 ) ;
F_17 () ;
}
static struct V_4 * F_18 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = NULL ;
if ( F_19 ( & V_8 -> V_16 ) )
V_5 = V_8 -> V_5 ;
return V_5 ;
}
static struct V_4 * F_20 ( struct V_6 * V_6 )
{
return F_18 ( V_6 -> V_9 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
if ( F_22 ( & V_8 -> V_16 ) )
F_15 ( V_8 -> V_5 ) ;
}
static void F_23 ( T_1 * V_18 , const T_2 * V_19 )
{
int V_20 = F_24 ( V_21 , V_19 ) >> 26 ;
V_18 [ V_20 >> 5 ] |= ( 1 << ( V_20 & 31 ) ) ;
}
static unsigned int F_25 ( const T_1 * V_18 , const T_2 * V_19 )
{
int V_20 = F_24 ( V_21 , V_19 ) >> 26 ;
return V_18 [ V_20 >> 5 ] & ( 1 << ( V_20 & 31 ) ) ;
}
static int F_26 ( struct V_22 * V_23 , void T_3 * V_24 )
{
struct { T_2 V_25 [ V_21 ] ; } * V_19 ;
struct V_26 V_27 ;
int V_10 , V_28 , V_20 , V_29 ;
if ( F_27 ( & V_27 , V_24 , sizeof( V_27 ) ) )
return - V_30 ;
if ( ! V_27 . V_16 ) {
V_23 -> V_16 = 0 ;
return 0 ;
}
V_28 = V_21 * V_27 . V_16 ;
V_19 = F_28 ( V_28 , V_31 ) ;
if ( ! V_19 )
return - V_32 ;
if ( F_27 ( V_19 , V_24 + sizeof( V_27 ) , V_28 ) ) {
V_10 = - V_30 ;
goto V_33;
}
V_23 -> V_16 = 0 ;
F_29 () ;
for ( V_20 = 0 ; V_20 < V_27 . V_16 && V_20 < V_34 ; V_20 ++ )
memcpy ( V_23 -> V_19 [ V_20 ] , V_19 [ V_20 ] . V_25 , V_21 ) ;
V_29 = V_20 ;
memset ( V_23 -> V_18 , 0 , sizeof( V_23 -> V_18 ) ) ;
for (; V_20 < V_27 . V_16 ; V_20 ++ ) {
if ( ! F_30 ( V_19 [ V_20 ] . V_25 ) ) {
V_10 = 0 ;
goto V_33;
}
F_23 ( V_23 -> V_18 , V_19 [ V_20 ] . V_25 ) ;
}
if ( ( V_27 . V_35 & V_36 ) )
memset ( V_23 -> V_18 , ~ 0 , sizeof( V_23 -> V_18 ) ) ;
F_29 () ;
V_23 -> V_16 = V_29 ;
V_10 = V_29 ;
V_33:
F_31 ( V_19 ) ;
return V_10 ;
}
static int F_32 ( struct V_22 * V_23 , const struct V_37 * V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) V_38 -> V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_23 -> V_16 ; V_42 ++ )
if ( F_33 ( V_40 -> V_43 , V_23 -> V_19 [ V_42 ] ) )
return 1 ;
if ( F_30 ( V_40 -> V_43 ) )
return F_25 ( V_23 -> V_18 , V_40 -> V_43 ) ;
return 0 ;
}
static int F_34 ( struct V_22 * V_23 , const struct V_37 * V_38 )
{
if ( ! V_23 -> V_16 )
return 1 ;
return F_32 ( V_23 , V_38 ) ;
}
static void F_35 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_8 ) {
F_37 ( & V_5 -> V_45 . V_46 ) ;
if ( F_22 ( & V_8 -> V_16 ) )
F_11 ( V_5 ) ;
}
}
static void F_38 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
F_39 ( ! F_40 ( V_47 , & V_5 -> V_15 . V_35 ) ) ;
F_41 ( V_5 -> V_15 . V_3 ) ;
}
static int F_42 ( struct V_44 * V_11 )
{
F_43 ( V_11 ) ;
return 0 ;
}
static int F_44 ( struct V_44 * V_11 )
{
F_45 ( V_11 ) ;
return 0 ;
}
static T_4 F_46 ( struct V_37 * V_38 , struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
F_47 ( V_48 , V_5 , L_1 , V_38 -> V_49 ) ;
if ( ! V_5 -> V_8 )
goto V_50;
if ( ! F_34 ( & V_5 -> V_51 , V_38 ) )
goto V_50;
if ( V_5 -> V_15 . V_3 -> V_52 &&
V_52 ( V_5 -> V_15 . V_3 , V_38 ) )
goto V_50;
if ( F_48 ( & V_5 -> V_15 . V_3 -> V_17 ) >= V_11 -> V_53 ) {
if ( ! ( V_5 -> V_35 & V_54 ) ) {
F_45 ( V_11 ) ;
V_11 -> V_55 . V_56 ++ ;
} else {
goto V_50;
}
}
if ( F_49 ( F_50 ( V_38 , V_57 ) ) )
goto V_50;
F_51 ( V_38 ) ;
F_52 ( & V_5 -> V_15 . V_3 -> V_17 , V_38 ) ;
if ( V_5 -> V_35 & V_58 )
F_53 ( & V_5 -> V_59 , V_60 , V_61 ) ;
F_54 ( & V_5 -> V_45 . V_46 , V_62 |
V_63 | V_64 ) ;
return V_65 ;
V_50:
V_11 -> V_55 . V_66 ++ ;
F_55 ( V_38 ) ;
return V_65 ;
}
static void F_56 ( struct V_44 * V_11 )
{
}
static int
F_57 ( struct V_44 * V_11 , int V_67 )
{
if ( V_67 < V_68 || V_67 + V_11 -> V_69 > V_70 )
return - V_12 ;
V_11 -> V_71 = V_67 ;
return 0 ;
}
static T_5 F_58 ( struct V_44 * V_11 ,
T_5 V_72 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
return ( V_72 & V_5 -> V_73 ) | ( V_72 & ~ V_74 ) ;
}
static void F_59 ( struct V_44 * V_11 )
{
return;
}
static void F_60 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
switch ( V_5 -> V_35 & V_75 ) {
case V_76 :
V_11 -> V_77 = & V_78 ;
V_11 -> V_69 = 0 ;
V_11 -> V_79 = 0 ;
V_11 -> V_71 = 1500 ;
V_11 -> type = V_80 ;
V_11 -> V_35 = V_81 | V_82 | V_83 ;
V_11 -> V_53 = V_84 ;
break;
case V_85 :
V_11 -> V_77 = & V_86 ;
F_61 ( V_11 ) ;
V_11 -> V_87 &= ~ V_88 ;
F_62 ( V_11 ) ;
V_11 -> V_53 = V_84 ;
break;
}
}
static unsigned int F_63 ( struct V_6 * V_6 , T_6 * V_46 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_8 ) ;
struct V_2 * V_3 ;
unsigned int V_18 = 0 ;
if ( ! V_5 )
return V_89 ;
V_3 = V_5 -> V_15 . V_3 ;
F_47 ( V_48 , V_5 , L_2 ) ;
F_64 ( V_6 , & V_5 -> V_45 . V_46 , V_46 ) ;
if ( ! F_65 ( & V_3 -> V_17 ) )
V_18 |= V_62 | V_63 ;
if ( F_66 ( V_3 ) ||
( ! F_67 ( V_90 , & V_3 -> V_91 -> V_35 ) &&
F_66 ( V_3 ) ) )
V_18 |= V_92 | V_93 ;
if ( V_5 -> V_11 -> V_94 != V_95 )
V_18 = V_89 ;
F_21 ( V_5 ) ;
return V_18 ;
}
static struct V_37 * F_68 ( struct V_4 * V_5 ,
T_7 V_96 , T_7 V_49 ,
T_7 V_97 , int V_98 )
{
struct V_2 * V_3 = V_5 -> V_15 . V_3 ;
struct V_37 * V_38 ;
int V_10 ;
F_69 ( V_3 ) ;
if ( V_96 + V_49 < V_99 || ! V_97 )
V_97 = V_49 ;
V_38 = F_70 ( V_3 , V_96 + V_97 , V_49 - V_97 , V_98 ,
& V_10 ) ;
if ( ! V_38 )
return F_71 ( V_10 ) ;
F_72 ( V_38 , V_96 ) ;
F_73 ( V_38 , V_97 ) ;
V_38 -> V_100 = V_49 - V_97 ;
V_38 -> V_49 += V_49 - V_97 ;
return V_38 ;
}
static int F_74 ( struct V_37 * V_38 , const struct V_101 * V_102 ,
int V_103 , T_7 V_16 )
{
int V_49 = F_75 ( V_102 , V_16 ) - V_103 ;
int V_104 = F_76 ( V_38 ) ;
int V_105 , V_106 = 0 ;
int V_42 = 0 ;
while ( V_16 && ( V_103 >= V_102 -> V_107 ) ) {
V_103 -= V_102 -> V_107 ;
++ V_102 ;
-- V_16 ;
}
while ( V_16 && ( V_104 > 0 ) ) {
V_105 = F_77 (unsigned int, copy, from->iov_len - offset) ;
if ( F_27 ( V_38 -> V_41 + V_106 , V_102 -> V_108 + V_103 ,
V_105 ) )
return - V_30 ;
if ( V_104 > V_105 ) {
++ V_102 ;
-- V_16 ;
V_103 = 0 ;
} else
V_103 += V_105 ;
V_104 -= V_105 ;
V_106 += V_105 ;
}
if ( V_49 == V_106 )
return 0 ;
while ( V_16 -- ) {
struct V_109 * V_109 [ V_110 ] ;
int V_111 ;
unsigned long V_112 ;
unsigned long V_113 ;
V_49 = V_102 -> V_107 - V_103 ;
if ( ! V_49 ) {
V_103 = 0 ;
++ V_102 ;
continue;
}
V_112 = ( unsigned long ) V_102 -> V_108 + V_103 ;
V_105 = ( ( V_112 & ~ V_114 ) + V_49 + ~ V_114 ) >> V_115 ;
if ( V_42 + V_105 > V_110 )
return - V_116 ;
V_111 = F_78 ( V_112 , V_105 , 0 , & V_109 [ V_42 ] ) ;
if ( V_111 != V_105 ) {
for ( V_42 = 0 ; V_42 < V_111 ; V_42 ++ )
F_79 ( V_109 [ V_42 ] ) ;
return - V_30 ;
}
V_113 = V_105 * V_99 ;
V_38 -> V_100 += V_49 ;
V_38 -> V_49 += V_49 ;
V_38 -> V_113 += V_113 ;
F_80 ( V_113 , & V_38 -> V_3 -> V_117 ) ;
while ( V_49 ) {
int V_118 = V_112 & ~ V_114 ;
int V_105 = F_77 ( int , V_49 , V_99 - V_118 ) ;
F_81 ( V_38 , V_42 , V_109 [ V_42 ] , V_118 , V_105 ) ;
F_82 ( V_38 ) -> V_119 ++ ;
V_112 += V_105 ;
V_49 -= V_105 ;
V_42 ++ ;
}
V_103 = 0 ;
++ V_102 ;
}
return 0 ;
}
static T_8 F_83 ( struct V_4 * V_5 , void * V_120 ,
const struct V_101 * V_121 , T_7 V_122 ,
T_7 V_16 , int V_98 )
{
struct V_123 V_124 = { 0 , F_84 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_7 V_49 = V_122 , V_125 = V_126 ;
struct V_127 V_128 = { 0 } ;
int V_103 = 0 ;
int V_129 ;
bool V_130 = false ;
int V_10 ;
if ( ! ( V_5 -> V_35 & V_131 ) ) {
if ( ( V_49 -= sizeof( V_124 ) ) > V_122 )
return - V_12 ;
if ( F_85 ( ( void * ) & V_124 , V_121 , 0 , sizeof( V_124 ) ) )
return - V_30 ;
V_103 += sizeof( V_124 ) ;
}
if ( V_5 -> V_35 & V_132 ) {
if ( ( V_49 -= V_5 -> V_133 ) > V_122 )
return - V_12 ;
if ( F_85 ( ( void * ) & V_128 , V_121 , V_103 , sizeof( V_128 ) ) )
return - V_30 ;
if ( ( V_128 . V_35 & V_134 ) &&
V_128 . V_135 + V_128 . V_136 + 2 > V_128 . V_137 )
V_128 . V_137 = V_128 . V_135 + V_128 . V_136 + 2 ;
if ( V_128 . V_137 > V_49 )
return - V_12 ;
V_103 += V_5 -> V_133 ;
}
if ( ( V_5 -> V_35 & V_75 ) == V_85 ) {
V_125 += V_138 ;
if ( F_49 ( V_49 < V_139 ||
( V_128 . V_137 && V_128 . V_137 < V_139 ) ) )
return - V_12 ;
}
if ( V_120 )
V_130 = true ;
if ( V_130 ) {
if ( V_16 > V_110 ) {
V_129 = F_75 ( V_121 , V_16 - V_110 ) ;
if ( V_129 < V_103 )
V_129 = 0 ;
else
V_129 -= V_103 ;
} else
V_129 = 0 ;
if ( V_129 < V_128 . V_137 )
V_129 = V_128 . V_137 ;
if ( ! V_129 )
V_129 = V_140 ;
} else
V_129 = V_49 ;
V_38 = F_68 ( V_5 , V_125 , V_129 , V_128 . V_137 , V_98 ) ;
if ( F_86 ( V_38 ) ) {
if ( F_87 ( V_38 ) != - V_141 )
V_5 -> V_11 -> V_55 . V_142 ++ ;
return F_87 ( V_38 ) ;
}
if ( V_130 )
V_10 = F_74 ( V_38 , V_121 , V_103 , V_16 ) ;
else
V_10 = F_88 ( V_38 , 0 , V_121 , V_103 , V_49 ) ;
if ( V_10 ) {
V_5 -> V_11 -> V_55 . V_142 ++ ;
F_55 ( V_38 ) ;
return - V_30 ;
}
if ( V_128 . V_35 & V_134 ) {
if ( ! F_89 ( V_38 , V_128 . V_135 ,
V_128 . V_136 ) ) {
V_5 -> V_11 -> V_55 . V_143 ++ ;
F_55 ( V_38 ) ;
return - V_12 ;
}
}
switch ( V_5 -> V_35 & V_75 ) {
case V_76 :
if ( V_5 -> V_35 & V_131 ) {
switch ( V_38 -> V_41 [ 0 ] & 0xf0 ) {
case 0x40 :
V_124 . V_144 = F_90 ( V_145 ) ;
break;
case 0x60 :
V_124 . V_144 = F_90 ( V_146 ) ;
break;
default:
V_5 -> V_11 -> V_55 . V_142 ++ ;
F_55 ( V_38 ) ;
return - V_12 ;
}
}
F_91 ( V_38 ) ;
V_38 -> V_147 = V_124 . V_144 ;
V_38 -> V_11 = V_5 -> V_11 ;
break;
case V_85 :
V_38 -> V_147 = F_92 ( V_38 , V_5 -> V_11 ) ;
break;
}
if ( V_128 . V_148 != V_149 ) {
F_93 ( L_3 ) ;
switch ( V_128 . V_148 & ~ V_150 ) {
case V_151 :
F_82 ( V_38 ) -> V_148 = V_152 ;
break;
case V_153 :
F_82 ( V_38 ) -> V_148 = V_154 ;
break;
case V_155 :
F_82 ( V_38 ) -> V_148 = V_156 ;
break;
default:
V_5 -> V_11 -> V_55 . V_143 ++ ;
F_55 ( V_38 ) ;
return - V_12 ;
}
if ( V_128 . V_148 & V_150 )
F_82 ( V_38 ) -> V_148 |= V_157 ;
F_82 ( V_38 ) -> V_158 = V_128 . V_158 ;
if ( F_82 ( V_38 ) -> V_158 == 0 ) {
V_5 -> V_11 -> V_55 . V_143 ++ ;
F_55 ( V_38 ) ;
return - V_12 ;
}
F_82 ( V_38 ) -> V_148 |= V_159 ;
F_82 ( V_38 ) -> V_160 = 0 ;
}
if ( V_130 ) {
F_82 ( V_38 ) -> V_161 = V_120 ;
F_82 ( V_38 ) -> V_162 |= V_163 ;
}
F_94 ( V_38 ) ;
V_5 -> V_11 -> V_55 . V_164 ++ ;
V_5 -> V_11 -> V_55 . V_165 += V_49 ;
return V_122 ;
}
static T_8 F_95 ( struct V_166 * V_167 , const struct V_101 * V_121 ,
unsigned long V_16 , T_9 V_168 )
{
struct V_6 * V_6 = V_167 -> V_169 ;
struct V_4 * V_5 = F_20 ( V_6 ) ;
T_8 V_170 ;
if ( ! V_5 )
return - V_171 ;
F_47 ( V_48 , V_5 , L_4 , V_16 ) ;
V_170 = F_83 ( V_5 , NULL , V_121 , F_75 ( V_121 , V_16 ) , V_16 ,
V_6 -> V_172 & V_173 ) ;
F_21 ( V_5 ) ;
return V_170 ;
}
static T_8 F_96 ( struct V_4 * V_5 ,
struct V_37 * V_38 ,
const struct V_101 * V_121 , int V_49 )
{
struct V_123 V_124 = { 0 , V_38 -> V_147 } ;
T_8 V_174 = 0 ;
if ( ! ( V_5 -> V_35 & V_131 ) ) {
if ( ( V_49 -= sizeof( V_124 ) ) < 0 )
return - V_12 ;
if ( V_49 < V_38 -> V_49 ) {
V_124 . V_35 |= V_175 ;
}
if ( F_97 ( V_121 , ( void * ) & V_124 , 0 , sizeof( V_124 ) ) )
return - V_30 ;
V_174 += sizeof( V_124 ) ;
}
if ( V_5 -> V_35 & V_132 ) {
struct V_127 V_128 = { 0 } ;
if ( ( V_49 -= V_5 -> V_133 ) < 0 )
return - V_12 ;
if ( F_98 ( V_38 ) ) {
struct V_176 * V_177 = F_82 ( V_38 ) ;
V_128 . V_137 = F_76 ( V_38 ) ;
V_128 . V_158 = V_177 -> V_158 ;
if ( V_177 -> V_148 & V_152 )
V_128 . V_148 = V_151 ;
else if ( V_177 -> V_148 & V_154 )
V_128 . V_148 = V_153 ;
else if ( V_177 -> V_148 & V_156 )
V_128 . V_148 = V_155 ;
else {
F_99 ( L_5
L_6 ,
V_177 -> V_148 , V_128 . V_158 ,
V_128 . V_137 ) ;
F_100 ( V_178 , L_7 ,
V_179 ,
16 , 1 , V_38 -> V_180 ,
F_101 ( ( int ) V_128 . V_137 , 64 ) , true ) ;
F_102 ( 1 ) ;
return - V_12 ;
}
if ( V_177 -> V_148 & V_157 )
V_128 . V_148 |= V_150 ;
} else
V_128 . V_148 = V_149 ;
if ( V_38 -> V_181 == V_182 ) {
V_128 . V_35 = V_134 ;
V_128 . V_135 = F_103 ( V_38 ) ;
V_128 . V_136 = V_38 -> V_136 ;
} else if ( V_38 -> V_181 == V_183 ) {
V_128 . V_35 = V_184 ;
}
if ( F_49 ( F_97 ( V_121 , ( void * ) & V_128 , V_174 ,
sizeof( V_128 ) ) ) )
return - V_30 ;
V_174 += V_5 -> V_133 ;
}
V_49 = F_77 ( int , V_38 -> V_49 , V_49 ) ;
F_104 ( V_38 , 0 , V_121 , V_174 , V_49 ) ;
V_174 += V_38 -> V_49 ;
V_5 -> V_11 -> V_55 . V_185 ++ ;
V_5 -> V_11 -> V_55 . V_186 += V_49 ;
return V_174 ;
}
static T_8 F_105 ( struct V_4 * V_5 ,
struct V_166 * V_167 , const struct V_101 * V_121 ,
T_8 V_49 , int V_98 )
{
F_106 ( V_46 , V_187 ) ;
struct V_37 * V_38 ;
T_8 V_188 = 0 ;
F_47 ( V_48 , V_5 , L_8 ) ;
if ( F_49 ( ! V_98 ) )
F_107 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
while ( V_49 ) {
V_187 -> V_189 = V_190 ;
if ( ! ( V_38 = F_108 ( & V_5 -> V_15 . V_3 -> V_17 ) ) ) {
if ( V_98 ) {
V_188 = - V_141 ;
break;
}
if ( F_109 ( V_187 ) ) {
V_188 = - V_191 ;
break;
}
if ( V_5 -> V_11 -> V_94 != V_95 ) {
V_188 = - V_192 ;
break;
}
F_110 () ;
continue;
}
F_111 ( V_5 -> V_11 ) ;
V_188 = F_96 ( V_5 , V_38 , V_121 , V_49 ) ;
F_55 ( V_38 ) ;
break;
}
V_187 -> V_189 = V_193 ;
if ( F_49 ( ! V_98 ) )
F_112 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
return V_188 ;
}
static T_8 F_113 ( struct V_166 * V_167 , const struct V_101 * V_121 ,
unsigned long V_16 , T_9 V_168 )
{
struct V_6 * V_6 = V_167 -> V_169 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_8 ) ;
T_8 V_49 , V_188 ;
if ( ! V_5 )
return - V_171 ;
V_49 = F_75 ( V_121 , V_16 ) ;
if ( V_49 < 0 ) {
V_188 = - V_12 ;
goto V_13;
}
V_188 = F_105 ( V_5 , V_167 , V_121 , V_49 , V_6 -> V_172 & V_173 ) ;
V_188 = F_77 ( T_8 , V_188 , V_49 ) ;
V_13:
F_21 ( V_5 ) ;
return V_188 ;
}
static void F_114 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_194 = V_195 ;
V_5 -> V_196 = V_197 ;
V_11 -> V_198 = & V_199 ;
V_11 -> V_200 = F_38 ;
}
static int F_115 ( struct V_201 * V_202 [] , struct V_201 * V_41 [] )
{
return - V_12 ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_10 * V_203 ;
if ( ! F_66 ( V_3 ) )
return;
if ( ! F_117 ( V_90 , & V_3 -> V_91 -> V_35 ) )
return;
V_203 = F_118 ( V_3 ) ;
if ( V_203 && F_119 ( V_203 ) )
F_120 ( V_203 , V_92 |
V_93 | V_204 ) ;
V_5 = F_1 ( V_3 ) -> V_5 ;
F_53 ( & V_5 -> V_59 , V_60 , V_205 ) ;
}
static void F_121 ( struct V_2 * V_3 )
{
F_122 ( F_1 ( V_3 ) -> V_5 -> V_11 ) ;
}
static int F_123 ( struct V_166 * V_167 , struct V_15 * V_2 ,
struct V_206 * V_207 , T_7 V_122 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
return F_83 ( V_5 , V_207 -> V_120 , V_207 -> V_208 , V_122 ,
V_207 -> V_209 , V_207 -> V_210 & V_211 ) ;
}
static int F_124 ( struct V_166 * V_167 , struct V_15 * V_2 ,
struct V_206 * V_207 , T_7 V_122 ,
int V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
int V_188 ;
if ( V_35 & ~ ( V_211 | V_212 ) )
return - V_12 ;
V_188 = F_105 ( V_5 , V_167 , V_207 -> V_208 , V_122 ,
V_35 & V_211 ) ;
if ( V_188 > V_122 ) {
V_207 -> V_210 |= V_212 ;
V_188 = V_35 & V_212 ? V_188 : V_122 ;
}
return V_188 ;
}
static int F_125 ( struct V_15 * V_2 )
{
if ( V_2 -> V_3 )
F_126 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_127 ( struct V_4 * V_5 )
{
int V_35 = 0 ;
if ( V_5 -> V_35 & V_76 )
V_35 |= V_213 ;
else
V_35 |= V_214 ;
if ( V_5 -> V_35 & V_131 )
V_35 |= V_215 ;
if ( V_5 -> V_35 & V_54 )
V_35 |= V_216 ;
if ( V_5 -> V_35 & V_132 )
V_35 |= V_217 ;
return V_35 ;
}
static T_8 F_128 ( struct V_218 * V_11 , struct V_219 * V_220 ,
char * V_221 )
{
struct V_4 * V_5 = F_36 ( F_129 ( V_11 ) ) ;
return sprintf ( V_221 , L_9 , F_127 ( V_5 ) ) ;
}
static T_8 F_130 ( struct V_218 * V_11 , struct V_219 * V_220 ,
char * V_221 )
{
struct V_4 * V_5 = F_36 ( F_129 ( V_11 ) ) ;
return F_131 ( V_5 -> V_194 ) ?
sprintf ( V_221 , L_10 ,
F_132 ( F_133 () , V_5 -> V_194 ) ) :
sprintf ( V_221 , L_11 ) ;
}
static T_8 F_134 ( struct V_218 * V_11 , struct V_219 * V_220 ,
char * V_221 )
{
struct V_4 * V_5 = F_36 ( F_129 ( V_11 ) ) ;
return F_135 ( V_5 -> V_196 ) ?
sprintf ( V_221 , L_10 ,
F_136 ( F_133 () , V_5 -> V_196 ) ) :
sprintf ( V_221 , L_11 ) ;
}
static int F_137 ( struct V_222 * V_222 , struct V_6 * V_6 , struct V_223 * V_224 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_11 ;
int V_10 ;
V_11 = F_138 ( V_222 , V_224 -> V_225 ) ;
if ( V_11 ) {
const struct V_226 * V_226 = F_139 () ;
if ( V_224 -> V_227 & V_228 )
return - V_14 ;
if ( ( V_224 -> V_227 & V_213 ) && V_11 -> V_77 == & V_78 )
V_5 = F_36 ( V_11 ) ;
else if ( ( V_224 -> V_227 & V_214 ) && V_11 -> V_77 == & V_86 )
V_5 = F_36 ( V_11 ) ;
else
return - V_12 ;
if ( ( ( F_131 ( V_5 -> V_194 ) && ! F_140 ( V_226 -> V_229 , V_5 -> V_194 ) ) ||
( F_135 ( V_5 -> V_196 ) && ! F_141 ( V_5 -> V_196 ) ) ) &&
! F_142 ( V_230 ) )
return - V_231 ;
V_10 = F_143 ( V_5 -> V_15 . V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
}
else {
char * V_232 ;
unsigned long V_35 = 0 ;
if ( ! F_142 ( V_230 ) )
return - V_231 ;
V_10 = F_144 () ;
if ( V_10 < 0 )
return V_10 ;
if ( V_224 -> V_227 & V_213 ) {
V_35 |= V_76 ;
V_232 = L_12 ;
} else if ( V_224 -> V_227 & V_214 ) {
V_35 |= V_85 ;
V_232 = L_13 ;
} else
return - V_12 ;
if ( * V_224 -> V_225 )
V_232 = V_224 -> V_225 ;
V_11 = F_145 ( sizeof( struct V_4 ) , V_232 ,
F_114 ) ;
if ( ! V_11 )
return - V_32 ;
F_146 ( V_11 , V_222 ) ;
V_11 -> V_233 = & V_234 ;
V_5 = F_36 ( V_11 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_51 . V_16 = 0 ;
V_5 -> V_133 = sizeof( struct V_127 ) ;
F_147 ( V_47 , & V_5 -> V_15 . V_35 ) ;
V_10 = - V_32 ;
V_3 = F_148 ( & V_235 , V_236 , V_31 , & V_237 ) ;
if ( ! V_3 )
goto V_238;
F_149 ( V_3 , V_222 ) ;
V_5 -> V_15 . V_45 = & V_5 -> V_45 ;
F_150 ( & V_5 -> V_45 . V_46 ) ;
V_5 -> V_15 . V_239 = & V_240 ;
F_151 ( & V_5 -> V_15 , V_3 ) ;
V_3 -> V_241 = F_116 ;
V_3 -> V_242 = V_243 ;
F_152 ( V_3 , V_244 ) ;
F_1 ( V_3 ) -> V_5 = V_5 ;
F_153 ( V_3 ) ;
F_60 ( V_11 ) ;
V_11 -> V_245 = V_246 | V_247 |
V_74 ;
V_11 -> V_72 = V_11 -> V_245 ;
V_10 = F_154 ( V_5 -> V_11 ) ;
if ( V_10 < 0 )
goto V_248;
if ( F_155 ( & V_5 -> V_11 -> V_11 , & V_249 ) ||
F_155 ( & V_5 -> V_11 -> V_11 , & V_250 ) ||
F_155 ( & V_5 -> V_11 -> V_11 , & V_251 ) )
F_99 ( L_14 ) ;
V_3 -> V_252 = F_121 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
goto V_253;
}
F_47 ( V_48 , V_5 , L_15 ) ;
if ( V_224 -> V_227 & V_215 )
V_5 -> V_35 |= V_131 ;
else
V_5 -> V_35 &= ~ V_131 ;
if ( V_224 -> V_227 & V_216 )
V_5 -> V_35 |= V_54 ;
else
V_5 -> V_35 &= ~ V_54 ;
if ( V_224 -> V_227 & V_217 )
V_5 -> V_35 |= V_132 ;
else
V_5 -> V_35 &= ~ V_132 ;
if ( F_156 ( V_5 -> V_11 ) )
F_111 ( V_5 -> V_11 ) ;
strcpy ( V_224 -> V_225 , V_5 -> V_11 -> V_232 ) ;
return 0 ;
V_248:
F_38 ( V_11 ) ;
V_238:
F_122 ( V_11 ) ;
V_253:
return V_10 ;
}
static int F_157 ( struct V_222 * V_222 , struct V_4 * V_5 ,
struct V_223 * V_224 )
{
F_47 ( V_48 , V_5 , L_16 ) ;
strcpy ( V_224 -> V_225 , V_5 -> V_11 -> V_232 ) ;
V_224 -> V_227 = F_127 ( V_5 ) ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 , unsigned long V_24 )
{
T_5 V_72 = 0 ;
if ( V_24 & V_254 ) {
V_72 |= V_255 ;
V_24 &= ~ V_254 ;
if ( V_24 & ( V_256 | V_257 ) ) {
if ( V_24 & V_258 ) {
V_72 |= V_259 ;
V_24 &= ~ V_258 ;
}
if ( V_24 & V_256 )
V_72 |= V_260 ;
if ( V_24 & V_257 )
V_72 |= V_261 ;
V_24 &= ~ ( V_256 | V_257 ) ;
}
if ( V_24 & V_262 ) {
V_72 |= V_263 ;
V_24 &= ~ V_262 ;
}
}
if ( V_24 )
return - V_12 ;
V_5 -> V_73 = V_72 ;
F_159 ( V_5 -> V_11 ) ;
return 0 ;
}
static long F_160 ( struct V_6 * V_6 , unsigned int V_264 ,
unsigned long V_24 , int V_265 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
void T_3 * V_266 = ( void T_3 * ) V_24 ;
struct V_267 V_268 ;
struct V_223 V_224 ;
T_11 V_194 ;
T_12 V_196 ;
int V_269 ;
int V_133 ;
int V_188 ;
if ( V_264 == V_270 || F_161 ( V_264 ) == 0x89 ) {
if ( F_27 ( & V_224 , V_266 , V_265 ) )
return - V_30 ;
} else {
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
}
if ( V_264 == V_271 ) {
return F_162 ( V_213 | V_214 | V_215 | V_216 |
V_217 ,
( unsigned int T_3 * ) V_266 ) ;
}
F_16 () ;
V_5 = F_18 ( V_8 ) ;
if ( V_264 == V_270 && ! V_5 ) {
V_224 . V_225 [ V_272 - 1 ] = '\0' ;
V_188 = F_137 ( V_8 -> V_222 , V_6 , & V_224 ) ;
if ( V_188 )
goto V_273;
if ( F_163 ( V_266 , & V_224 , V_265 ) )
V_188 = - V_30 ;
goto V_273;
}
V_188 = - V_171 ;
if ( ! V_5 )
goto V_273;
F_47 ( V_48 , V_5 , L_17 , V_264 ) ;
V_188 = 0 ;
switch ( V_264 ) {
case V_274 :
V_188 = F_157 ( V_187 -> V_275 -> V_276 , V_5 , & V_224 ) ;
if ( V_188 )
break;
if ( F_163 ( V_266 , & V_224 , V_265 ) )
V_188 = - V_30 ;
break;
case V_277 :
F_47 ( V_48 , V_5 , L_18 ,
V_24 ? L_19 : L_20 ) ;
break;
case V_278 :
if ( V_24 )
V_5 -> V_35 |= V_279 ;
else
V_5 -> V_35 &= ~ V_279 ;
F_47 ( V_48 , V_5 , L_21 ,
V_24 ? L_20 : L_19 ) ;
break;
case V_280 :
V_194 = F_164 ( F_133 () , V_24 ) ;
if ( ! F_131 ( V_194 ) ) {
V_188 = - V_12 ;
break;
}
V_5 -> V_194 = V_194 ;
F_47 ( V_48 , V_5 , L_22 ,
F_165 ( & V_281 , V_5 -> V_194 ) ) ;
break;
case V_282 :
V_196 = F_166 ( F_133 () , V_24 ) ;
if ( ! F_135 ( V_196 ) ) {
V_188 = - V_12 ;
break;
}
V_5 -> V_196 = V_196 ;
F_47 ( V_48 , V_5 , L_23 ,
F_167 ( & V_281 , V_5 -> V_196 ) ) ;
break;
case V_283 :
if ( V_5 -> V_11 -> V_35 & V_284 ) {
F_47 ( V_48 , V_5 ,
L_24 ) ;
V_188 = - V_14 ;
} else {
V_5 -> V_11 -> type = ( int ) V_24 ;
F_47 ( V_48 , V_5 , L_25 ,
V_5 -> V_11 -> type ) ;
V_188 = 0 ;
}
break;
#ifdef F_168
case V_285 :
V_5 -> V_286 = V_24 ;
break;
#endif
case V_287 :
V_188 = F_158 ( V_5 , V_24 ) ;
break;
case V_288 :
V_188 = - V_12 ;
if ( ( V_5 -> V_35 & V_75 ) != V_85 )
break;
V_188 = F_26 ( & V_5 -> V_51 , ( void T_3 * ) V_24 ) ;
break;
case V_289 :
memcpy ( V_224 . V_290 . V_291 , V_5 -> V_11 -> V_292 , V_21 ) ;
V_224 . V_290 . V_293 = V_5 -> V_11 -> type ;
if ( F_163 ( V_266 , & V_224 , V_265 ) )
V_188 = - V_30 ;
break;
case V_294 :
F_47 ( V_295 , V_5 , L_26 ,
V_224 . V_290 . V_291 ) ;
V_188 = F_169 ( V_5 -> V_11 , & V_224 . V_290 ) ;
break;
case V_296 :
V_269 = V_5 -> V_15 . V_3 -> V_242 ;
if ( F_163 ( V_266 , & V_269 , sizeof( V_269 ) ) )
V_188 = - V_30 ;
break;
case V_297 :
if ( F_27 ( & V_269 , V_266 , sizeof( V_269 ) ) ) {
V_188 = - V_30 ;
break;
}
V_5 -> V_15 . V_3 -> V_242 = V_269 ;
break;
case V_298 :
V_133 = V_5 -> V_133 ;
if ( F_163 ( V_266 , & V_133 , sizeof( V_133 ) ) )
V_188 = - V_30 ;
break;
case V_299 :
if ( F_27 ( & V_133 , V_266 , sizeof( V_133 ) ) ) {
V_188 = - V_30 ;
break;
}
if ( V_133 < ( int ) sizeof( struct V_127 ) ) {
V_188 = - V_12 ;
break;
}
V_5 -> V_133 = V_133 ;
break;
case V_300 :
V_188 = - V_12 ;
if ( ( V_5 -> V_35 & V_75 ) != V_85 )
break;
V_188 = - V_30 ;
if ( F_27 ( & V_268 , V_266 , sizeof( V_268 ) ) )
break;
V_188 = F_170 ( & V_268 , V_5 -> V_15 . V_3 ) ;
break;
case V_301 :
V_188 = - V_12 ;
if ( ( V_5 -> V_35 & V_75 ) != V_85 )
break;
V_188 = F_171 ( V_5 -> V_15 . V_3 ) ;
break;
default:
V_188 = - V_12 ;
break;
}
V_273:
F_17 () ;
if ( V_5 )
F_21 ( V_5 ) ;
return V_188 ;
}
static long F_172 ( struct V_6 * V_6 ,
unsigned int V_264 , unsigned long V_24 )
{
return F_160 ( V_6 , V_264 , V_24 , sizeof ( struct V_223 ) ) ;
}
static long F_173 ( struct V_6 * V_6 ,
unsigned int V_264 , unsigned long V_24 )
{
switch ( V_264 ) {
case V_270 :
case V_274 :
case V_288 :
case V_296 :
case V_297 :
case V_289 :
case V_294 :
V_24 = ( unsigned long ) F_174 ( V_24 ) ;
break;
default:
V_24 = ( V_302 ) V_24 ;
break;
}
return F_160 ( V_6 , V_264 , V_24 , sizeof( struct V_303 ) ) ;
}
static int F_175 ( int V_304 , struct V_6 * V_6 , int V_305 )
{
struct V_4 * V_5 = F_20 ( V_6 ) ;
int V_188 ;
if ( ! V_5 )
return - V_171 ;
F_47 ( V_48 , V_5 , L_27 , V_305 ) ;
if ( ( V_188 = F_176 ( V_304 , V_6 , V_305 , & V_5 -> V_59 ) ) < 0 )
goto V_13;
if ( V_305 ) {
V_188 = F_177 ( V_6 , F_178 ( V_187 ) , V_306 , 0 ) ;
if ( V_188 )
goto V_13;
V_5 -> V_35 |= V_58 ;
} else
V_5 -> V_35 &= ~ V_58 ;
V_188 = 0 ;
V_13:
F_21 ( V_5 ) ;
return V_188 ;
}
static int F_179 ( struct V_307 * V_307 , struct V_6 * V_6 )
{
struct V_7 * V_8 ;
F_180 ( V_48 , L_28 ) ;
V_8 = F_28 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return - V_32 ;
F_181 ( & V_8 -> V_16 , 0 ) ;
V_8 -> V_5 = NULL ;
V_8 -> V_222 = F_182 ( V_187 -> V_275 -> V_276 ) ;
V_6 -> V_9 = V_8 ;
return 0 ;
}
static int F_183 ( struct V_307 * V_307 , struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
V_5 = F_18 ( V_8 ) ;
if ( V_5 ) {
struct V_44 * V_11 = V_5 -> V_11 ;
F_47 ( V_48 , V_5 , L_29 ) ;
F_11 ( V_5 ) ;
if ( ! ( V_5 -> V_35 & V_279 ) ) {
F_16 () ;
if ( V_11 -> V_94 == V_95 )
F_184 ( V_11 ) ;
F_17 () ;
}
}
V_5 = V_8 -> V_5 ;
if ( V_5 )
F_126 ( V_5 -> V_15 . V_3 ) ;
F_185 ( V_8 -> V_222 ) ;
F_31 ( V_8 ) ;
return 0 ;
}
static int F_186 ( struct V_44 * V_11 , struct V_308 * V_264 )
{
V_264 -> V_309 = 0 ;
V_264 -> V_310 = 0 ;
F_187 ( V_264 , V_311 ) ;
V_264 -> V_312 = V_313 ;
V_264 -> V_314 = V_315 ;
V_264 -> V_316 = 0 ;
V_264 -> V_317 = V_318 ;
V_264 -> V_319 = V_320 ;
V_264 -> V_321 = 0 ;
V_264 -> V_322 = 0 ;
return 0 ;
}
static void F_188 ( struct V_44 * V_11 , struct V_323 * V_324 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
F_189 ( V_324 -> V_325 , V_326 , sizeof( V_324 -> V_325 ) ) ;
F_189 ( V_324 -> V_327 , V_328 , sizeof( V_324 -> V_327 ) ) ;
switch ( V_5 -> V_35 & V_75 ) {
case V_76 :
F_189 ( V_324 -> V_329 , L_30 , sizeof( V_324 -> V_329 ) ) ;
break;
case V_85 :
F_189 ( V_324 -> V_329 , L_31 , sizeof( V_324 -> V_329 ) ) ;
break;
}
}
static T_1 F_190 ( struct V_44 * V_11 )
{
#ifdef F_168
struct V_4 * V_5 = F_36 ( V_11 ) ;
return V_5 -> V_286 ;
#else
return - V_330 ;
#endif
}
static void F_191 ( struct V_44 * V_11 , T_1 V_331 )
{
#ifdef F_168
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_286 = V_331 ;
#endif
}
static int T_13 F_192 ( void )
{
int V_188 = 0 ;
F_193 ( L_32 , V_332 , V_328 ) ;
F_193 ( L_33 , V_333 ) ;
V_188 = F_194 ( & V_234 ) ;
if ( V_188 ) {
F_99 ( L_34 ) ;
goto V_334;
}
V_188 = F_195 ( & V_335 ) ;
if ( V_188 ) {
F_99 ( L_35 , V_336 ) ;
goto V_337;
}
return 0 ;
V_337:
F_196 ( & V_234 ) ;
V_334:
return V_188 ;
}
static void F_197 ( void )
{
F_198 ( & V_335 ) ;
F_196 ( & V_234 ) ;
}
struct V_15 * F_199 ( struct V_6 * V_6 )
{
struct V_4 * V_5 ;
if ( V_6 -> V_338 != & V_339 )
return F_71 ( - V_12 ) ;
V_5 = F_20 ( V_6 ) ;
if ( ! V_5 )
return F_71 ( - V_171 ) ;
F_21 ( V_5 ) ;
return & V_5 -> V_15 ;
}
