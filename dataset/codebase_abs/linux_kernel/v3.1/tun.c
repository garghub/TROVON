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
V_5 -> V_15 . V_6 = NULL ;
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
if ( ! F_33 ( V_40 -> V_43 , V_23 -> V_19 [ V_42 ] ) )
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
F_39 ( V_5 -> V_15 . V_3 ) ;
}
static int F_40 ( struct V_44 * V_11 )
{
F_41 ( V_11 ) ;
return 0 ;
}
static int F_42 ( struct V_44 * V_11 )
{
F_43 ( V_11 ) ;
return 0 ;
}
static T_4 F_44 ( struct V_37 * V_38 , struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
F_45 ( V_47 , V_5 , L_1 , V_38 -> V_48 ) ;
if ( ! V_5 -> V_8 )
goto V_49;
if ( ! F_34 ( & V_5 -> V_50 , V_38 ) )
goto V_49;
if ( V_5 -> V_15 . V_3 -> V_51 &&
V_51 ( V_5 -> V_15 . V_3 , V_38 ) )
goto V_49;
if ( F_46 ( & V_5 -> V_15 . V_3 -> V_17 ) >= V_11 -> V_52 ) {
if ( ! ( V_5 -> V_35 & V_53 ) ) {
F_43 ( V_11 ) ;
V_11 -> V_54 . V_55 ++ ;
} else {
goto V_49;
}
}
F_47 ( V_38 ) ;
F_48 ( & V_5 -> V_15 . V_3 -> V_17 , V_38 ) ;
if ( V_5 -> V_35 & V_56 )
F_49 ( & V_5 -> V_57 , V_58 , V_59 ) ;
F_50 ( & V_5 -> V_45 . V_46 , V_60 |
V_61 | V_62 ) ;
return V_63 ;
V_49:
V_11 -> V_54 . V_64 ++ ;
F_51 ( V_38 ) ;
return V_63 ;
}
static void F_52 ( struct V_44 * V_11 )
{
}
static int
F_53 ( struct V_44 * V_11 , int V_65 )
{
if ( V_65 < V_66 || V_65 + V_11 -> V_67 > V_68 )
return - V_12 ;
V_11 -> V_69 = V_65 ;
return 0 ;
}
static T_1 F_54 ( struct V_44 * V_11 , T_1 V_70 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
return ( V_70 & V_5 -> V_71 ) | ( V_70 & ~ V_72 ) ;
}
static void F_55 ( struct V_44 * V_11 )
{
return;
}
static void F_56 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
switch ( V_5 -> V_35 & V_73 ) {
case V_74 :
V_11 -> V_75 = & V_76 ;
V_11 -> V_67 = 0 ;
V_11 -> V_77 = 0 ;
V_11 -> V_69 = 1500 ;
V_11 -> type = V_78 ;
V_11 -> V_35 = V_79 | V_80 | V_81 ;
V_11 -> V_52 = V_82 ;
break;
case V_83 :
V_11 -> V_75 = & V_84 ;
F_57 ( V_11 ) ;
V_11 -> V_85 &= ~ V_86 ;
F_58 ( V_11 -> V_87 ) ;
V_11 -> V_52 = V_82 ;
break;
}
}
static unsigned int F_59 ( struct V_6 * V_6 , T_5 * V_46 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_8 ) ;
struct V_2 * V_3 ;
unsigned int V_18 = 0 ;
if ( ! V_5 )
return V_88 ;
V_3 = V_5 -> V_15 . V_3 ;
F_45 ( V_47 , V_5 , L_2 ) ;
F_60 ( V_6 , & V_5 -> V_45 . V_46 , V_46 ) ;
if ( ! F_61 ( & V_3 -> V_17 ) )
V_18 |= V_60 | V_61 ;
if ( F_62 ( V_3 ) ||
( ! F_63 ( V_89 , & V_3 -> V_90 -> V_35 ) &&
F_62 ( V_3 ) ) )
V_18 |= V_91 | V_92 ;
if ( V_5 -> V_11 -> V_93 != V_94 )
V_18 = V_88 ;
F_21 ( V_5 ) ;
return V_18 ;
}
static struct V_37 * F_64 ( struct V_4 * V_5 ,
T_6 V_95 , T_6 V_48 ,
T_6 V_96 , int V_97 )
{
struct V_2 * V_3 = V_5 -> V_15 . V_3 ;
struct V_37 * V_38 ;
int V_10 ;
F_65 ( V_3 ) ;
if ( V_95 + V_48 < V_98 || ! V_96 )
V_96 = V_48 ;
V_38 = F_66 ( V_3 , V_95 + V_96 , V_48 - V_96 , V_97 ,
& V_10 ) ;
if ( ! V_38 )
return F_67 ( V_10 ) ;
F_68 ( V_38 , V_95 ) ;
F_69 ( V_38 , V_96 ) ;
V_38 -> V_99 = V_48 - V_96 ;
V_38 -> V_48 += V_48 - V_96 ;
return V_38 ;
}
static T_7 F_70 ( struct V_4 * V_5 ,
const struct V_100 * V_101 , T_6 V_16 ,
int V_97 )
{
struct V_102 V_103 = { 0 , F_71 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_6 V_48 = V_16 , V_104 = V_105 ;
struct V_106 V_107 = { 0 } ;
int V_108 = 0 ;
if ( ! ( V_5 -> V_35 & V_109 ) ) {
if ( ( V_48 -= sizeof( V_103 ) ) > V_16 )
return - V_12 ;
if ( F_72 ( ( void * ) & V_103 , V_101 , 0 , sizeof( V_103 ) ) )
return - V_30 ;
V_108 += sizeof( V_103 ) ;
}
if ( V_5 -> V_35 & V_110 ) {
if ( ( V_48 -= V_5 -> V_111 ) > V_16 )
return - V_12 ;
if ( F_72 ( ( void * ) & V_107 , V_101 , V_108 , sizeof( V_107 ) ) )
return - V_30 ;
if ( ( V_107 . V_35 & V_112 ) &&
V_107 . V_113 + V_107 . V_114 + 2 > V_107 . V_115 )
V_107 . V_115 = V_107 . V_113 + V_107 . V_114 + 2 ;
if ( V_107 . V_115 > V_48 )
return - V_12 ;
V_108 += V_5 -> V_111 ;
}
if ( ( V_5 -> V_35 & V_73 ) == V_83 ) {
V_104 += V_116 ;
if ( F_73 ( V_48 < V_117 ||
( V_107 . V_115 && V_107 . V_115 < V_117 ) ) )
return - V_12 ;
}
V_38 = F_64 ( V_5 , V_104 , V_48 , V_107 . V_115 , V_97 ) ;
if ( F_74 ( V_38 ) ) {
if ( F_75 ( V_38 ) != - V_118 )
V_5 -> V_11 -> V_54 . V_119 ++ ;
return F_75 ( V_38 ) ;
}
if ( F_76 ( V_38 , 0 , V_101 , V_108 , V_48 ) ) {
V_5 -> V_11 -> V_54 . V_119 ++ ;
F_51 ( V_38 ) ;
return - V_30 ;
}
if ( V_107 . V_35 & V_112 ) {
if ( ! F_77 ( V_38 , V_107 . V_113 ,
V_107 . V_114 ) ) {
V_5 -> V_11 -> V_54 . V_120 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
}
switch ( V_5 -> V_35 & V_73 ) {
case V_74 :
if ( V_5 -> V_35 & V_109 ) {
switch ( V_38 -> V_41 [ 0 ] & 0xf0 ) {
case 0x40 :
V_103 . V_121 = F_78 ( V_122 ) ;
break;
case 0x60 :
V_103 . V_121 = F_78 ( V_123 ) ;
break;
default:
V_5 -> V_11 -> V_54 . V_119 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
}
F_79 ( V_38 ) ;
V_38 -> V_124 = V_103 . V_121 ;
V_38 -> V_11 = V_5 -> V_11 ;
break;
case V_83 :
V_38 -> V_124 = F_80 ( V_38 , V_5 -> V_11 ) ;
break;
}
if ( V_107 . V_125 != V_126 ) {
F_81 ( L_3 ) ;
switch ( V_107 . V_125 & ~ V_127 ) {
case V_128 :
F_82 ( V_38 ) -> V_125 = V_129 ;
break;
case V_130 :
F_82 ( V_38 ) -> V_125 = V_131 ;
break;
case V_132 :
F_82 ( V_38 ) -> V_125 = V_133 ;
break;
default:
V_5 -> V_11 -> V_54 . V_120 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
if ( V_107 . V_125 & V_127 )
F_82 ( V_38 ) -> V_125 |= V_134 ;
F_82 ( V_38 ) -> V_135 = V_107 . V_135 ;
if ( F_82 ( V_38 ) -> V_135 == 0 ) {
V_5 -> V_11 -> V_54 . V_120 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
F_82 ( V_38 ) -> V_125 |= V_136 ;
F_82 ( V_38 ) -> V_137 = 0 ;
}
F_83 ( V_38 ) ;
V_5 -> V_11 -> V_54 . V_138 ++ ;
V_5 -> V_11 -> V_54 . V_139 += V_48 ;
return V_16 ;
}
static T_7 F_84 ( struct V_140 * V_141 , const struct V_100 * V_101 ,
unsigned long V_16 , T_8 V_142 )
{
struct V_6 * V_6 = V_141 -> V_143 ;
struct V_4 * V_5 = F_20 ( V_6 ) ;
T_7 V_144 ;
if ( ! V_5 )
return - V_145 ;
F_45 ( V_47 , V_5 , L_4 , V_16 ) ;
V_144 = F_70 ( V_5 , V_101 , F_85 ( V_101 , V_16 ) ,
V_6 -> V_146 & V_147 ) ;
F_21 ( V_5 ) ;
return V_144 ;
}
static T_7 F_86 ( struct V_4 * V_5 ,
struct V_37 * V_38 ,
const struct V_100 * V_101 , int V_48 )
{
struct V_102 V_103 = { 0 , V_38 -> V_124 } ;
T_7 V_148 = 0 ;
if ( ! ( V_5 -> V_35 & V_109 ) ) {
if ( ( V_48 -= sizeof( V_103 ) ) < 0 )
return - V_12 ;
if ( V_48 < V_38 -> V_48 ) {
V_103 . V_35 |= V_149 ;
}
if ( F_87 ( V_101 , ( void * ) & V_103 , 0 , sizeof( V_103 ) ) )
return - V_30 ;
V_148 += sizeof( V_103 ) ;
}
if ( V_5 -> V_35 & V_110 ) {
struct V_106 V_107 = { 0 } ;
if ( ( V_48 -= V_5 -> V_111 ) < 0 )
return - V_12 ;
if ( F_88 ( V_38 ) ) {
struct V_150 * V_151 = F_82 ( V_38 ) ;
V_107 . V_115 = F_89 ( V_38 ) ;
V_107 . V_135 = V_151 -> V_135 ;
if ( V_151 -> V_125 & V_129 )
V_107 . V_125 = V_128 ;
else if ( V_151 -> V_125 & V_131 )
V_107 . V_125 = V_130 ;
else if ( V_151 -> V_125 & V_133 )
V_107 . V_125 = V_132 ;
else {
F_90 ( L_5
L_6 ,
V_151 -> V_125 , V_107 . V_135 ,
V_107 . V_115 ) ;
F_91 ( V_152 , L_7 ,
V_153 ,
16 , 1 , V_38 -> V_154 ,
F_92 ( ( int ) V_107 . V_115 , 64 ) , true ) ;
F_93 ( 1 ) ;
return - V_12 ;
}
if ( V_151 -> V_125 & V_134 )
V_107 . V_125 |= V_127 ;
} else
V_107 . V_125 = V_126 ;
if ( V_38 -> V_155 == V_156 ) {
V_107 . V_35 = V_112 ;
V_107 . V_113 = F_94 ( V_38 ) ;
V_107 . V_114 = V_38 -> V_114 ;
} else if ( V_38 -> V_155 == V_157 ) {
V_107 . V_35 = V_158 ;
}
if ( F_73 ( F_87 ( V_101 , ( void * ) & V_107 , V_148 ,
sizeof( V_107 ) ) ) )
return - V_30 ;
V_148 += V_5 -> V_111 ;
}
V_48 = F_95 ( int , V_38 -> V_48 , V_48 ) ;
F_96 ( V_38 , 0 , V_101 , V_148 , V_48 ) ;
V_148 += V_38 -> V_48 ;
V_5 -> V_11 -> V_54 . V_159 ++ ;
V_5 -> V_11 -> V_54 . V_160 += V_48 ;
return V_148 ;
}
static T_7 F_97 ( struct V_4 * V_5 ,
struct V_140 * V_141 , const struct V_100 * V_101 ,
T_7 V_48 , int V_97 )
{
F_98 ( V_46 , V_161 ) ;
struct V_37 * V_38 ;
T_7 V_162 = 0 ;
F_45 ( V_47 , V_5 , L_8 ) ;
if ( F_73 ( ! V_97 ) )
F_99 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
while ( V_48 ) {
V_161 -> V_163 = V_164 ;
if ( ! ( V_38 = F_100 ( & V_5 -> V_15 . V_3 -> V_17 ) ) ) {
if ( V_97 ) {
V_162 = - V_118 ;
break;
}
if ( F_101 ( V_161 ) ) {
V_162 = - V_165 ;
break;
}
if ( V_5 -> V_11 -> V_93 != V_94 ) {
V_162 = - V_166 ;
break;
}
F_102 () ;
continue;
}
F_103 ( V_5 -> V_11 ) ;
V_162 = F_86 ( V_5 , V_38 , V_101 , V_48 ) ;
F_51 ( V_38 ) ;
break;
}
V_161 -> V_163 = V_167 ;
if ( F_73 ( ! V_97 ) )
F_104 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
return V_162 ;
}
static T_7 F_105 ( struct V_140 * V_141 , const struct V_100 * V_101 ,
unsigned long V_16 , T_8 V_142 )
{
struct V_6 * V_6 = V_141 -> V_143 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_8 ) ;
T_7 V_48 , V_162 ;
if ( ! V_5 )
return - V_145 ;
V_48 = F_85 ( V_101 , V_16 ) ;
if ( V_48 < 0 ) {
V_162 = - V_12 ;
goto V_13;
}
V_162 = F_97 ( V_5 , V_141 , V_101 , V_48 , V_6 -> V_146 & V_147 ) ;
V_162 = F_95 ( T_7 , V_162 , V_48 ) ;
V_13:
F_21 ( V_5 ) ;
return V_162 ;
}
static void F_106 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_168 = - 1 ;
V_5 -> V_169 = - 1 ;
V_11 -> V_170 = & V_171 ;
V_11 -> V_172 = F_38 ;
}
static int F_107 ( struct V_173 * V_174 [] , struct V_173 * V_41 [] )
{
return - V_12 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_9 * V_175 ;
if ( ! F_62 ( V_3 ) )
return;
if ( ! F_109 ( V_89 , & V_3 -> V_90 -> V_35 ) )
return;
V_175 = F_110 ( V_3 ) ;
if ( V_175 && F_111 ( V_175 ) )
F_112 ( V_175 , V_91 |
V_92 | V_176 ) ;
V_5 = F_1 ( V_3 ) -> V_5 ;
F_49 ( & V_5 -> V_57 , V_58 , V_177 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_114 ( F_1 ( V_3 ) -> V_5 -> V_11 ) ;
}
static int F_115 ( struct V_140 * V_141 , struct V_15 * V_2 ,
struct V_178 * V_179 , T_6 V_180 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
return F_70 ( V_5 , V_179 -> V_181 , V_180 ,
V_179 -> V_182 & V_183 ) ;
}
static int F_116 ( struct V_140 * V_141 , struct V_15 * V_2 ,
struct V_178 * V_179 , T_6 V_180 ,
int V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
int V_162 ;
if ( V_35 & ~ ( V_183 | V_184 ) )
return - V_12 ;
V_162 = F_97 ( V_5 , V_141 , V_179 -> V_181 , V_180 ,
V_35 & V_183 ) ;
if ( V_162 > V_180 ) {
V_179 -> V_182 |= V_184 ;
V_162 = V_35 & V_184 ? V_162 : V_180 ;
}
return V_162 ;
}
static int F_117 ( struct V_4 * V_5 )
{
int V_35 = 0 ;
if ( V_5 -> V_35 & V_74 )
V_35 |= V_185 ;
else
V_35 |= V_186 ;
if ( V_5 -> V_35 & V_109 )
V_35 |= V_187 ;
if ( V_5 -> V_35 & V_53 )
V_35 |= V_188 ;
if ( V_5 -> V_35 & V_110 )
V_35 |= V_189 ;
return V_35 ;
}
static T_7 F_118 ( struct V_190 * V_11 , struct V_191 * V_192 ,
char * V_193 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_193 , L_9 , F_117 ( V_5 ) ) ;
}
static T_7 F_120 ( struct V_190 * V_11 , struct V_191 * V_192 ,
char * V_193 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_193 , L_10 , V_5 -> V_168 ) ;
}
static T_7 F_121 ( struct V_190 * V_11 , struct V_191 * V_192 ,
char * V_193 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_193 , L_10 , V_5 -> V_169 ) ;
}
static int F_122 ( struct V_194 * V_194 , struct V_6 * V_6 , struct V_195 * V_196 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_11 ;
int V_10 ;
V_11 = F_123 ( V_194 , V_196 -> V_197 ) ;
if ( V_11 ) {
const struct V_198 * V_198 = F_124 () ;
if ( V_196 -> V_199 & V_200 )
return - V_14 ;
if ( ( V_196 -> V_199 & V_185 ) && V_11 -> V_75 == & V_76 )
V_5 = F_36 ( V_11 ) ;
else if ( ( V_196 -> V_199 & V_186 ) && V_11 -> V_75 == & V_84 )
V_5 = F_36 ( V_11 ) ;
else
return - V_12 ;
if ( ( ( V_5 -> V_168 != - 1 && V_198 -> V_201 != V_5 -> V_168 ) ||
( V_5 -> V_169 != - 1 && ! F_125 ( V_5 -> V_169 ) ) ) &&
! F_126 ( V_202 ) )
return - V_203 ;
V_10 = F_127 ( V_5 -> V_15 . V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
}
else {
char * V_204 ;
unsigned long V_35 = 0 ;
if ( ! F_126 ( V_202 ) )
return - V_203 ;
V_10 = F_128 () ;
if ( V_10 < 0 )
return V_10 ;
if ( V_196 -> V_199 & V_185 ) {
V_35 |= V_74 ;
V_204 = L_11 ;
} else if ( V_196 -> V_199 & V_186 ) {
V_35 |= V_83 ;
V_204 = L_12 ;
} else
return - V_12 ;
if ( * V_196 -> V_197 )
V_204 = V_196 -> V_197 ;
V_11 = F_129 ( sizeof( struct V_4 ) , V_204 ,
F_106 ) ;
if ( ! V_11 )
return - V_32 ;
F_130 ( V_11 , V_194 ) ;
V_11 -> V_205 = & V_206 ;
V_5 = F_36 ( V_11 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_50 . V_16 = 0 ;
V_5 -> V_111 = sizeof( struct V_106 ) ;
V_10 = - V_32 ;
V_3 = F_131 ( V_194 , V_207 , V_31 , & V_208 ) ;
if ( ! V_3 )
goto V_209;
V_5 -> V_15 . V_45 = & V_5 -> V_45 ;
F_132 ( & V_5 -> V_45 . V_46 ) ;
V_5 -> V_15 . V_210 = & V_211 ;
F_133 ( & V_5 -> V_15 , V_3 ) ;
V_3 -> V_212 = F_108 ;
V_3 -> V_213 = V_214 ;
F_1 ( V_3 ) -> V_5 = V_5 ;
F_134 ( V_3 ) ;
F_56 ( V_11 ) ;
V_11 -> V_215 = V_216 | V_217 |
V_72 ;
V_11 -> V_70 = V_11 -> V_215 ;
V_10 = F_135 ( V_5 -> V_11 ) ;
if ( V_10 < 0 )
goto V_218;
if ( F_136 ( & V_5 -> V_11 -> V_11 , & V_219 ) ||
F_136 ( & V_5 -> V_11 -> V_11 , & V_220 ) ||
F_136 ( & V_5 -> V_11 -> V_11 , & V_221 ) )
F_90 ( L_13 ) ;
V_3 -> V_222 = F_113 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
goto V_223;
}
F_45 ( V_47 , V_5 , L_14 ) ;
if ( V_196 -> V_199 & V_187 )
V_5 -> V_35 |= V_109 ;
else
V_5 -> V_35 &= ~ V_109 ;
if ( V_196 -> V_199 & V_188 )
V_5 -> V_35 |= V_53 ;
else
V_5 -> V_35 &= ~ V_53 ;
if ( V_196 -> V_199 & V_189 )
V_5 -> V_35 |= V_110 ;
else
V_5 -> V_35 &= ~ V_110 ;
if ( F_137 ( V_5 -> V_11 ) )
F_103 ( V_5 -> V_11 ) ;
strcpy ( V_196 -> V_197 , V_5 -> V_11 -> V_204 ) ;
return 0 ;
V_218:
F_39 ( V_3 ) ;
V_209:
F_114 ( V_11 ) ;
V_223:
return V_10 ;
}
static int F_138 ( struct V_194 * V_194 , struct V_4 * V_5 ,
struct V_195 * V_196 )
{
F_45 ( V_47 , V_5 , L_15 ) ;
strcpy ( V_196 -> V_197 , V_5 -> V_11 -> V_204 ) ;
V_196 -> V_199 = F_117 ( V_5 ) ;
return 0 ;
}
static int F_139 ( struct V_4 * V_5 , unsigned long V_24 )
{
T_1 V_70 = 0 ;
if ( V_24 & V_224 ) {
V_70 |= V_225 ;
V_24 &= ~ V_224 ;
if ( V_24 & ( V_226 | V_227 ) ) {
if ( V_24 & V_228 ) {
V_70 |= V_229 ;
V_24 &= ~ V_228 ;
}
if ( V_24 & V_226 )
V_70 |= V_230 ;
if ( V_24 & V_227 )
V_70 |= V_231 ;
V_24 &= ~ ( V_226 | V_227 ) ;
}
if ( V_24 & V_232 ) {
V_70 |= V_233 ;
V_24 &= ~ V_232 ;
}
}
if ( V_24 )
return - V_12 ;
V_5 -> V_71 = V_70 ;
F_140 ( V_5 -> V_11 ) ;
return 0 ;
}
static long F_141 ( struct V_6 * V_6 , unsigned int V_234 ,
unsigned long V_24 , int V_235 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
void T_3 * V_236 = ( void T_3 * ) V_24 ;
struct V_237 V_238 ;
struct V_195 V_196 ;
int V_239 ;
int V_111 ;
int V_162 ;
if ( V_234 == V_240 || F_142 ( V_234 ) == 0x89 )
if ( F_27 ( & V_196 , V_236 , V_235 ) )
return - V_30 ;
if ( V_234 == V_241 ) {
return F_143 ( V_185 | V_186 | V_187 | V_188 |
V_189 ,
( unsigned int T_3 * ) V_236 ) ;
}
F_16 () ;
V_5 = F_18 ( V_8 ) ;
if ( V_234 == V_240 && ! V_5 ) {
V_196 . V_197 [ V_242 - 1 ] = '\0' ;
V_162 = F_122 ( V_8 -> V_194 , V_6 , & V_196 ) ;
if ( V_162 )
goto V_243;
if ( F_144 ( V_236 , & V_196 , V_235 ) )
V_162 = - V_30 ;
goto V_243;
}
V_162 = - V_145 ;
if ( ! V_5 )
goto V_243;
F_45 ( V_47 , V_5 , L_16 , V_234 ) ;
V_162 = 0 ;
switch ( V_234 ) {
case V_244 :
V_162 = F_138 ( V_161 -> V_245 -> V_246 , V_5 , & V_196 ) ;
if ( V_162 )
break;
if ( F_144 ( V_236 , & V_196 , V_235 ) )
V_162 = - V_30 ;
break;
case V_247 :
F_45 ( V_47 , V_5 , L_17 ,
V_24 ? L_18 : L_19 ) ;
break;
case V_248 :
if ( V_24 )
V_5 -> V_35 |= V_249 ;
else
V_5 -> V_35 &= ~ V_249 ;
F_45 ( V_47 , V_5 , L_20 ,
V_24 ? L_19 : L_18 ) ;
break;
case V_250 :
V_5 -> V_168 = ( V_251 ) V_24 ;
F_45 ( V_47 , V_5 , L_21 , V_5 -> V_168 ) ;
break;
case V_252 :
V_5 -> V_169 = ( V_253 ) V_24 ;
F_45 ( V_47 , V_5 , L_22 , V_5 -> V_169 ) ;
break;
case V_254 :
if ( V_5 -> V_11 -> V_35 & V_255 ) {
F_45 ( V_47 , V_5 ,
L_23 ) ;
V_162 = - V_14 ;
} else {
V_5 -> V_11 -> type = ( int ) V_24 ;
F_45 ( V_47 , V_5 , L_24 ,
V_5 -> V_11 -> type ) ;
V_162 = 0 ;
}
break;
#ifdef F_145
case V_256 :
V_5 -> V_257 = V_24 ;
break;
#endif
case V_258 :
V_162 = F_139 ( V_5 , V_24 ) ;
break;
case V_259 :
V_162 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_162 = F_26 ( & V_5 -> V_50 , ( void T_3 * ) V_24 ) ;
break;
case V_260 :
memcpy ( V_196 . V_261 . V_262 , V_5 -> V_11 -> V_87 , V_21 ) ;
V_196 . V_261 . V_263 = V_5 -> V_11 -> type ;
if ( F_144 ( V_236 , & V_196 , V_235 ) )
V_162 = - V_30 ;
break;
case V_264 :
F_45 ( V_265 , V_5 , L_25 ,
V_196 . V_261 . V_262 ) ;
V_162 = F_146 ( V_5 -> V_11 , & V_196 . V_261 ) ;
break;
case V_266 :
V_239 = V_5 -> V_15 . V_3 -> V_213 ;
if ( F_144 ( V_236 , & V_239 , sizeof( V_239 ) ) )
V_162 = - V_30 ;
break;
case V_267 :
if ( F_27 ( & V_239 , V_236 , sizeof( V_239 ) ) ) {
V_162 = - V_30 ;
break;
}
V_5 -> V_15 . V_3 -> V_213 = V_239 ;
break;
case V_268 :
V_111 = V_5 -> V_111 ;
if ( F_144 ( V_236 , & V_111 , sizeof( V_111 ) ) )
V_162 = - V_30 ;
break;
case V_269 :
if ( F_27 ( & V_111 , V_236 , sizeof( V_111 ) ) ) {
V_162 = - V_30 ;
break;
}
if ( V_111 < ( int ) sizeof( struct V_106 ) ) {
V_162 = - V_12 ;
break;
}
V_5 -> V_111 = V_111 ;
break;
case V_270 :
V_162 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_162 = - V_30 ;
if ( F_27 ( & V_238 , V_236 , sizeof( V_238 ) ) )
break;
V_162 = F_147 ( & V_238 , V_5 -> V_15 . V_3 ) ;
break;
case V_271 :
V_162 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_162 = F_148 ( V_5 -> V_15 . V_3 ) ;
break;
default:
V_162 = - V_12 ;
break;
}
V_243:
F_17 () ;
if ( V_5 )
F_21 ( V_5 ) ;
return V_162 ;
}
static long F_149 ( struct V_6 * V_6 ,
unsigned int V_234 , unsigned long V_24 )
{
return F_141 ( V_6 , V_234 , V_24 , sizeof ( struct V_195 ) ) ;
}
static long F_150 ( struct V_6 * V_6 ,
unsigned int V_234 , unsigned long V_24 )
{
switch ( V_234 ) {
case V_240 :
case V_244 :
case V_259 :
case V_266 :
case V_267 :
case V_260 :
case V_264 :
V_24 = ( unsigned long ) F_151 ( V_24 ) ;
break;
default:
V_24 = ( V_272 ) V_24 ;
break;
}
return F_141 ( V_6 , V_234 , V_24 , sizeof( struct V_273 ) ) ;
}
static int F_152 ( int V_274 , struct V_6 * V_6 , int V_275 )
{
struct V_4 * V_5 = F_20 ( V_6 ) ;
int V_162 ;
if ( ! V_5 )
return - V_145 ;
F_45 ( V_47 , V_5 , L_26 , V_275 ) ;
if ( ( V_162 = F_153 ( V_274 , V_6 , V_275 , & V_5 -> V_57 ) ) < 0 )
goto V_13;
if ( V_275 ) {
V_162 = F_154 ( V_6 , F_155 ( V_161 ) , V_276 , 0 ) ;
if ( V_162 )
goto V_13;
V_5 -> V_35 |= V_56 ;
} else
V_5 -> V_35 &= ~ V_56 ;
V_162 = 0 ;
V_13:
F_21 ( V_5 ) ;
return V_162 ;
}
static int F_156 ( struct V_277 * V_277 , struct V_6 * V_6 )
{
struct V_7 * V_8 ;
F_157 ( V_47 , L_27 ) ;
V_8 = F_28 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return - V_32 ;
F_158 ( & V_8 -> V_16 , 0 ) ;
V_8 -> V_5 = NULL ;
V_8 -> V_194 = F_159 ( V_161 -> V_245 -> V_246 ) ;
V_6 -> V_9 = V_8 ;
return 0 ;
}
static int F_160 ( struct V_277 * V_277 , struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
V_5 = F_18 ( V_8 ) ;
if ( V_5 ) {
struct V_44 * V_11 = V_5 -> V_11 ;
F_45 ( V_47 , V_5 , L_28 ) ;
F_11 ( V_5 ) ;
if ( ! ( V_5 -> V_35 & V_249 ) ) {
F_16 () ;
if ( V_11 -> V_93 == V_94 )
F_161 ( V_11 ) ;
F_17 () ;
}
}
V_5 = V_8 -> V_5 ;
if ( V_5 )
F_39 ( V_5 -> V_15 . V_3 ) ;
F_162 ( V_8 -> V_194 ) ;
F_31 ( V_8 ) ;
return 0 ;
}
static int F_163 ( struct V_44 * V_11 , struct V_278 * V_234 )
{
V_234 -> V_279 = 0 ;
V_234 -> V_280 = 0 ;
F_164 ( V_234 , V_281 ) ;
V_234 -> V_282 = V_283 ;
V_234 -> V_284 = V_285 ;
V_234 -> V_286 = 0 ;
V_234 -> V_287 = V_288 ;
V_234 -> V_289 = V_290 ;
V_234 -> V_291 = 0 ;
V_234 -> V_292 = 0 ;
return 0 ;
}
static void F_165 ( struct V_44 * V_11 , struct V_293 * V_294 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
strcpy ( V_294 -> V_295 , V_296 ) ;
strcpy ( V_294 -> V_297 , V_298 ) ;
strcpy ( V_294 -> V_299 , L_29 ) ;
switch ( V_5 -> V_35 & V_73 ) {
case V_74 :
strcpy ( V_294 -> V_300 , L_30 ) ;
break;
case V_83 :
strcpy ( V_294 -> V_300 , L_31 ) ;
break;
}
}
static T_1 F_166 ( struct V_44 * V_11 )
{
#ifdef F_145
struct V_4 * V_5 = F_36 ( V_11 ) ;
return V_5 -> V_257 ;
#else
return - V_301 ;
#endif
}
static void F_167 ( struct V_44 * V_11 , T_1 V_302 )
{
#ifdef F_145
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_257 = V_302 ;
#endif
}
static int T_10 F_168 ( void )
{
int V_162 = 0 ;
F_169 ( L_32 , V_303 , V_298 ) ;
F_169 ( L_33 , V_304 ) ;
V_162 = F_170 ( & V_206 ) ;
if ( V_162 ) {
F_90 ( L_34 ) ;
goto V_305;
}
V_162 = F_171 ( & V_306 ) ;
if ( V_162 ) {
F_90 ( L_35 , V_307 ) ;
goto V_308;
}
return 0 ;
V_308:
F_172 ( & V_206 ) ;
V_305:
return V_162 ;
}
static void F_173 ( void )
{
F_174 ( & V_306 ) ;
F_172 ( & V_206 ) ;
}
struct V_15 * F_175 ( struct V_6 * V_6 )
{
struct V_4 * V_5 ;
if ( V_6 -> V_309 != & V_310 )
return F_67 ( - V_12 ) ;
V_5 = F_20 ( V_6 ) ;
if ( ! V_5 )
return F_67 ( - V_145 ) ;
F_21 ( V_5 ) ;
return & V_5 -> V_15 ;
}
