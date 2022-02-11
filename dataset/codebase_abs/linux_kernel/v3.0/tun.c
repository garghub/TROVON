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
F_58 ( V_11 -> V_85 ) ;
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
return V_86 ;
V_3 = V_5 -> V_15 . V_3 ;
F_45 ( V_47 , V_5 , L_2 ) ;
F_60 ( V_6 , & V_5 -> V_45 . V_46 , V_46 ) ;
if ( ! F_61 ( & V_3 -> V_17 ) )
V_18 |= V_60 | V_61 ;
if ( F_62 ( V_3 ) ||
( ! F_63 ( V_87 , & V_3 -> V_88 -> V_35 ) &&
F_62 ( V_3 ) ) )
V_18 |= V_89 | V_90 ;
if ( V_5 -> V_11 -> V_91 != V_92 )
V_18 = V_86 ;
F_21 ( V_5 ) ;
return V_18 ;
}
static inline struct V_37 * F_64 ( struct V_4 * V_5 ,
T_6 V_93 , T_6 V_48 ,
T_6 V_94 , int V_95 )
{
struct V_2 * V_3 = V_5 -> V_15 . V_3 ;
struct V_37 * V_38 ;
int V_10 ;
F_65 ( V_3 ) ;
if ( V_93 + V_48 < V_96 || ! V_94 )
V_94 = V_48 ;
V_38 = F_66 ( V_3 , V_93 + V_94 , V_48 - V_94 , V_95 ,
& V_10 ) ;
if ( ! V_38 )
return F_67 ( V_10 ) ;
F_68 ( V_38 , V_93 ) ;
F_69 ( V_38 , V_94 ) ;
V_38 -> V_97 = V_48 - V_94 ;
V_38 -> V_48 += V_48 - V_94 ;
return V_38 ;
}
static T_7 T_8 F_70 ( struct V_4 * V_5 ,
const struct V_98 * V_99 , T_6 V_16 ,
int V_95 )
{
struct V_100 V_101 = { 0 , F_71 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_6 V_48 = V_16 , V_102 = 0 ;
struct V_103 V_104 = { 0 } ;
int V_105 = 0 ;
if ( ! ( V_5 -> V_35 & V_106 ) ) {
if ( ( V_48 -= sizeof( V_101 ) ) > V_16 )
return - V_12 ;
if ( F_72 ( ( void * ) & V_101 , V_99 , 0 , sizeof( V_101 ) ) )
return - V_30 ;
V_105 += sizeof( V_101 ) ;
}
if ( V_5 -> V_35 & V_107 ) {
if ( ( V_48 -= V_5 -> V_108 ) > V_16 )
return - V_12 ;
if ( F_72 ( ( void * ) & V_104 , V_99 , V_105 , sizeof( V_104 ) ) )
return - V_30 ;
if ( ( V_104 . V_35 & V_109 ) &&
V_104 . V_110 + V_104 . V_111 + 2 > V_104 . V_112 )
V_104 . V_112 = V_104 . V_110 + V_104 . V_111 + 2 ;
if ( V_104 . V_112 > V_48 )
return - V_12 ;
V_105 += V_5 -> V_108 ;
}
if ( ( V_5 -> V_35 & V_73 ) == V_83 ) {
V_102 = V_113 ;
if ( F_73 ( V_48 < V_114 ||
( V_104 . V_112 && V_104 . V_112 < V_114 ) ) )
return - V_12 ;
}
V_38 = F_64 ( V_5 , V_102 , V_48 , V_104 . V_112 , V_95 ) ;
if ( F_74 ( V_38 ) ) {
if ( F_75 ( V_38 ) != - V_115 )
V_5 -> V_11 -> V_54 . V_116 ++ ;
return F_75 ( V_38 ) ;
}
if ( F_76 ( V_38 , 0 , V_99 , V_105 , V_48 ) ) {
V_5 -> V_11 -> V_54 . V_116 ++ ;
F_51 ( V_38 ) ;
return - V_30 ;
}
if ( V_104 . V_35 & V_109 ) {
if ( ! F_77 ( V_38 , V_104 . V_110 ,
V_104 . V_111 ) ) {
V_5 -> V_11 -> V_54 . V_117 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
}
switch ( V_5 -> V_35 & V_73 ) {
case V_74 :
if ( V_5 -> V_35 & V_106 ) {
switch ( V_38 -> V_41 [ 0 ] & 0xf0 ) {
case 0x40 :
V_101 . V_118 = F_78 ( V_119 ) ;
break;
case 0x60 :
V_101 . V_118 = F_78 ( V_120 ) ;
break;
default:
V_5 -> V_11 -> V_54 . V_116 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
}
F_79 ( V_38 ) ;
V_38 -> V_121 = V_101 . V_118 ;
V_38 -> V_11 = V_5 -> V_11 ;
break;
case V_83 :
V_38 -> V_121 = F_80 ( V_38 , V_5 -> V_11 ) ;
break;
} ;
if ( V_104 . V_122 != V_123 ) {
F_81 ( L_3 ) ;
switch ( V_104 . V_122 & ~ V_124 ) {
case V_125 :
F_82 ( V_38 ) -> V_122 = V_126 ;
break;
case V_127 :
F_82 ( V_38 ) -> V_122 = V_128 ;
break;
case V_129 :
F_82 ( V_38 ) -> V_122 = V_130 ;
break;
default:
V_5 -> V_11 -> V_54 . V_117 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
if ( V_104 . V_122 & V_124 )
F_82 ( V_38 ) -> V_122 |= V_131 ;
F_82 ( V_38 ) -> V_132 = V_104 . V_132 ;
if ( F_82 ( V_38 ) -> V_132 == 0 ) {
V_5 -> V_11 -> V_54 . V_117 ++ ;
F_51 ( V_38 ) ;
return - V_12 ;
}
F_82 ( V_38 ) -> V_122 |= V_133 ;
F_82 ( V_38 ) -> V_134 = 0 ;
}
F_83 ( V_38 ) ;
V_5 -> V_11 -> V_54 . V_135 ++ ;
V_5 -> V_11 -> V_54 . V_136 += V_48 ;
return V_16 ;
}
static T_8 F_84 ( struct V_137 * V_138 , const struct V_98 * V_99 ,
unsigned long V_16 , T_9 V_139 )
{
struct V_6 * V_6 = V_138 -> V_140 ;
struct V_4 * V_5 = F_20 ( V_6 ) ;
T_8 V_141 ;
if ( ! V_5 )
return - V_142 ;
F_45 ( V_47 , V_5 , L_4 , V_16 ) ;
V_141 = F_70 ( V_5 , V_99 , F_85 ( V_99 , V_16 ) ,
V_6 -> V_143 & V_144 ) ;
F_21 ( V_5 ) ;
return V_141 ;
}
static T_7 T_8 F_86 ( struct V_4 * V_5 ,
struct V_37 * V_38 ,
const struct V_98 * V_99 , int V_48 )
{
struct V_100 V_101 = { 0 , V_38 -> V_121 } ;
T_8 V_145 = 0 ;
if ( ! ( V_5 -> V_35 & V_106 ) ) {
if ( ( V_48 -= sizeof( V_101 ) ) < 0 )
return - V_12 ;
if ( V_48 < V_38 -> V_48 ) {
V_101 . V_35 |= V_146 ;
}
if ( F_87 ( V_99 , ( void * ) & V_101 , 0 , sizeof( V_101 ) ) )
return - V_30 ;
V_145 += sizeof( V_101 ) ;
}
if ( V_5 -> V_35 & V_107 ) {
struct V_103 V_104 = { 0 } ;
if ( ( V_48 -= V_5 -> V_108 ) < 0 )
return - V_12 ;
if ( F_88 ( V_38 ) ) {
struct V_147 * V_148 = F_82 ( V_38 ) ;
V_104 . V_112 = F_89 ( V_38 ) ;
V_104 . V_132 = V_148 -> V_132 ;
if ( V_148 -> V_122 & V_126 )
V_104 . V_122 = V_125 ;
else if ( V_148 -> V_122 & V_128 )
V_104 . V_122 = V_127 ;
else if ( V_148 -> V_122 & V_130 )
V_104 . V_122 = V_129 ;
else {
F_90 ( L_5
L_6 ,
V_148 -> V_122 , V_104 . V_132 ,
V_104 . V_112 ) ;
F_91 ( V_149 , L_7 ,
V_150 ,
16 , 1 , V_38 -> V_151 ,
F_92 ( ( int ) V_104 . V_112 , 64 ) , true ) ;
F_93 ( 1 ) ;
return - V_12 ;
}
if ( V_148 -> V_122 & V_131 )
V_104 . V_122 |= V_124 ;
} else
V_104 . V_122 = V_123 ;
if ( V_38 -> V_152 == V_153 ) {
V_104 . V_35 = V_109 ;
V_104 . V_110 = F_94 ( V_38 ) ;
V_104 . V_111 = V_38 -> V_111 ;
}
if ( F_73 ( F_87 ( V_99 , ( void * ) & V_104 , V_145 ,
sizeof( V_104 ) ) ) )
return - V_30 ;
V_145 += V_5 -> V_108 ;
}
V_48 = F_95 ( int , V_38 -> V_48 , V_48 ) ;
F_96 ( V_38 , 0 , V_99 , V_145 , V_48 ) ;
V_145 += V_38 -> V_48 ;
V_5 -> V_11 -> V_54 . V_154 ++ ;
V_5 -> V_11 -> V_54 . V_155 += V_48 ;
return V_145 ;
}
static T_8 F_97 ( struct V_4 * V_5 ,
struct V_137 * V_138 , const struct V_98 * V_99 ,
T_8 V_48 , int V_95 )
{
F_98 ( V_46 , V_156 ) ;
struct V_37 * V_38 ;
T_8 V_157 = 0 ;
F_45 ( V_47 , V_5 , L_8 ) ;
F_99 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
while ( V_48 ) {
V_156 -> V_158 = V_159 ;
if ( ! ( V_38 = F_100 ( & V_5 -> V_15 . V_3 -> V_17 ) ) ) {
if ( V_95 ) {
V_157 = - V_115 ;
break;
}
if ( F_101 ( V_156 ) ) {
V_157 = - V_160 ;
break;
}
if ( V_5 -> V_11 -> V_91 != V_92 ) {
V_157 = - V_161 ;
break;
}
F_102 () ;
continue;
}
F_103 ( V_5 -> V_11 ) ;
V_157 = F_86 ( V_5 , V_38 , V_99 , V_48 ) ;
F_51 ( V_38 ) ;
break;
}
V_156 -> V_158 = V_162 ;
F_104 ( & V_5 -> V_45 . V_46 , & V_46 ) ;
return V_157 ;
}
static T_8 F_105 ( struct V_137 * V_138 , const struct V_98 * V_99 ,
unsigned long V_16 , T_9 V_139 )
{
struct V_6 * V_6 = V_138 -> V_140 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_8 ) ;
T_8 V_48 , V_157 ;
if ( ! V_5 )
return - V_142 ;
V_48 = F_85 ( V_99 , V_16 ) ;
if ( V_48 < 0 ) {
V_157 = - V_12 ;
goto V_13;
}
V_157 = F_97 ( V_5 , V_138 , V_99 , V_48 , V_6 -> V_143 & V_144 ) ;
V_157 = F_95 ( T_8 , V_157 , V_48 ) ;
V_13:
F_21 ( V_5 ) ;
return V_157 ;
}
static void F_106 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_163 = - 1 ;
V_5 -> V_164 = - 1 ;
V_11 -> V_165 = & V_166 ;
V_11 -> V_167 = F_38 ;
}
static int F_107 ( struct V_168 * V_169 [] , struct V_168 * V_41 [] )
{
return - V_12 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_10 * V_170 ;
if ( ! F_62 ( V_3 ) )
return;
if ( ! F_109 ( V_87 , & V_3 -> V_88 -> V_35 ) )
return;
V_170 = F_110 ( V_3 ) ;
if ( V_170 && F_111 ( V_170 ) )
F_112 ( V_170 , V_89 |
V_90 | V_171 ) ;
V_5 = F_1 ( V_3 ) -> V_5 ;
F_49 ( & V_5 -> V_57 , V_58 , V_172 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_114 ( F_1 ( V_3 ) -> V_5 -> V_11 ) ;
}
static int F_115 ( struct V_137 * V_138 , struct V_15 * V_2 ,
struct V_173 * V_174 , T_6 V_175 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
return F_70 ( V_5 , V_174 -> V_176 , V_175 ,
V_174 -> V_177 & V_178 ) ;
}
static int F_116 ( struct V_137 * V_138 , struct V_15 * V_2 ,
struct V_173 * V_174 , T_6 V_175 ,
int V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_15 ) ;
int V_157 ;
if ( V_35 & ~ ( V_178 | V_179 ) )
return - V_12 ;
V_157 = F_97 ( V_5 , V_138 , V_174 -> V_176 , V_175 ,
V_35 & V_178 ) ;
if ( V_157 > V_175 ) {
V_174 -> V_177 |= V_179 ;
V_157 = V_35 & V_179 ? V_157 : V_175 ;
}
return V_157 ;
}
static int F_117 ( struct V_4 * V_5 )
{
int V_35 = 0 ;
if ( V_5 -> V_35 & V_74 )
V_35 |= V_180 ;
else
V_35 |= V_181 ;
if ( V_5 -> V_35 & V_106 )
V_35 |= V_182 ;
if ( V_5 -> V_35 & V_53 )
V_35 |= V_183 ;
if ( V_5 -> V_35 & V_107 )
V_35 |= V_184 ;
return V_35 ;
}
static T_8 F_118 ( struct V_185 * V_11 , struct V_186 * V_187 ,
char * V_188 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_188 , L_9 , F_117 ( V_5 ) ) ;
}
static T_8 F_120 ( struct V_185 * V_11 , struct V_186 * V_187 ,
char * V_188 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_188 , L_10 , V_5 -> V_163 ) ;
}
static T_8 F_121 ( struct V_185 * V_11 , struct V_186 * V_187 ,
char * V_188 )
{
struct V_4 * V_5 = F_36 ( F_119 ( V_11 ) ) ;
return sprintf ( V_188 , L_10 , V_5 -> V_164 ) ;
}
static int F_122 ( struct V_189 * V_189 , struct V_6 * V_6 , struct V_190 * V_191 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_11 ;
int V_10 ;
V_11 = F_123 ( V_189 , V_191 -> V_192 ) ;
if ( V_11 ) {
const struct V_193 * V_193 = F_124 () ;
if ( V_191 -> V_194 & V_195 )
return - V_14 ;
if ( ( V_191 -> V_194 & V_180 ) && V_11 -> V_75 == & V_76 )
V_5 = F_36 ( V_11 ) ;
else if ( ( V_191 -> V_194 & V_181 ) && V_11 -> V_75 == & V_84 )
V_5 = F_36 ( V_11 ) ;
else
return - V_12 ;
if ( ( ( V_5 -> V_163 != - 1 && V_193 -> V_196 != V_5 -> V_163 ) ||
( V_5 -> V_164 != - 1 && ! F_125 ( V_5 -> V_164 ) ) ) &&
! F_126 ( V_197 ) )
return - V_198 ;
V_10 = F_127 ( V_5 -> V_15 . V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
}
else {
char * V_199 ;
unsigned long V_35 = 0 ;
if ( ! F_126 ( V_197 ) )
return - V_198 ;
V_10 = F_128 () ;
if ( V_10 < 0 )
return V_10 ;
if ( V_191 -> V_194 & V_180 ) {
V_35 |= V_74 ;
V_199 = L_11 ;
} else if ( V_191 -> V_194 & V_181 ) {
V_35 |= V_83 ;
V_199 = L_12 ;
} else
return - V_12 ;
if ( * V_191 -> V_192 )
V_199 = V_191 -> V_192 ;
V_11 = F_129 ( sizeof( struct V_4 ) , V_199 ,
F_106 ) ;
if ( ! V_11 )
return - V_32 ;
F_130 ( V_11 , V_189 ) ;
V_11 -> V_200 = & V_201 ;
V_5 = F_36 ( V_11 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_50 . V_16 = 0 ;
V_5 -> V_108 = sizeof( struct V_103 ) ;
V_10 = - V_32 ;
V_3 = F_131 ( V_189 , V_202 , V_31 , & V_203 ) ;
if ( ! V_3 )
goto V_204;
V_5 -> V_15 . V_45 = & V_5 -> V_45 ;
F_132 ( & V_5 -> V_45 . V_46 ) ;
V_5 -> V_15 . V_205 = & V_206 ;
F_133 ( & V_5 -> V_15 , V_3 ) ;
V_3 -> V_207 = F_108 ;
V_3 -> V_208 = V_209 ;
F_1 ( V_3 ) -> V_5 = V_5 ;
F_134 ( V_3 ) ;
F_56 ( V_11 ) ;
V_11 -> V_210 = V_211 | V_212 |
V_72 ;
V_11 -> V_70 = V_11 -> V_210 ;
V_10 = F_135 ( V_5 -> V_11 ) ;
if ( V_10 < 0 )
goto V_213;
if ( F_136 ( & V_5 -> V_11 -> V_11 , & V_214 ) ||
F_136 ( & V_5 -> V_11 -> V_11 , & V_215 ) ||
F_136 ( & V_5 -> V_11 -> V_11 , & V_216 ) )
F_90 ( L_13 ) ;
V_3 -> V_217 = F_113 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
goto V_218;
}
F_45 ( V_47 , V_5 , L_14 ) ;
if ( V_191 -> V_194 & V_182 )
V_5 -> V_35 |= V_106 ;
else
V_5 -> V_35 &= ~ V_106 ;
if ( V_191 -> V_194 & V_183 )
V_5 -> V_35 |= V_53 ;
else
V_5 -> V_35 &= ~ V_53 ;
if ( V_191 -> V_194 & V_184 )
V_5 -> V_35 |= V_107 ;
else
V_5 -> V_35 &= ~ V_107 ;
if ( F_137 ( V_5 -> V_11 ) )
F_103 ( V_5 -> V_11 ) ;
strcpy ( V_191 -> V_192 , V_5 -> V_11 -> V_199 ) ;
return 0 ;
V_213:
F_39 ( V_3 ) ;
V_204:
F_114 ( V_11 ) ;
V_218:
return V_10 ;
}
static int F_138 ( struct V_189 * V_189 , struct V_4 * V_5 ,
struct V_190 * V_191 )
{
F_45 ( V_47 , V_5 , L_15 ) ;
strcpy ( V_191 -> V_192 , V_5 -> V_11 -> V_199 ) ;
V_191 -> V_194 = F_117 ( V_5 ) ;
return 0 ;
}
static int F_139 ( struct V_4 * V_5 , unsigned long V_24 )
{
T_1 V_70 = 0 ;
if ( V_24 & V_219 ) {
V_70 |= V_220 ;
V_24 &= ~ V_219 ;
if ( V_24 & ( V_221 | V_222 ) ) {
if ( V_24 & V_223 ) {
V_70 |= V_224 ;
V_24 &= ~ V_223 ;
}
if ( V_24 & V_221 )
V_70 |= V_225 ;
if ( V_24 & V_222 )
V_70 |= V_226 ;
V_24 &= ~ ( V_221 | V_222 ) ;
}
if ( V_24 & V_227 ) {
V_70 |= V_228 ;
V_24 &= ~ V_227 ;
}
}
if ( V_24 )
return - V_12 ;
V_5 -> V_71 = V_70 ;
F_140 ( V_5 -> V_11 ) ;
return 0 ;
}
static long F_141 ( struct V_6 * V_6 , unsigned int V_229 ,
unsigned long V_24 , int V_230 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
void T_3 * V_231 = ( void T_3 * ) V_24 ;
struct V_232 V_233 ;
struct V_190 V_191 ;
int V_234 ;
int V_108 ;
int V_157 ;
if ( V_229 == V_235 || F_142 ( V_229 ) == 0x89 )
if ( F_27 ( & V_191 , V_231 , V_230 ) )
return - V_30 ;
if ( V_229 == V_236 ) {
return F_143 ( V_180 | V_181 | V_182 | V_183 |
V_184 ,
( unsigned int T_3 * ) V_231 ) ;
}
F_16 () ;
V_5 = F_18 ( V_8 ) ;
if ( V_229 == V_235 && ! V_5 ) {
V_191 . V_192 [ V_237 - 1 ] = '\0' ;
V_157 = F_122 ( V_8 -> V_189 , V_6 , & V_191 ) ;
if ( V_157 )
goto V_238;
if ( F_144 ( V_231 , & V_191 , V_230 ) )
V_157 = - V_30 ;
goto V_238;
}
V_157 = - V_142 ;
if ( ! V_5 )
goto V_238;
F_45 ( V_47 , V_5 , L_16 , V_229 ) ;
V_157 = 0 ;
switch ( V_229 ) {
case V_239 :
V_157 = F_138 ( V_156 -> V_240 -> V_241 , V_5 , & V_191 ) ;
if ( V_157 )
break;
if ( F_144 ( V_231 , & V_191 , V_230 ) )
V_157 = - V_30 ;
break;
case V_242 :
F_45 ( V_47 , V_5 , L_17 ,
V_24 ? L_18 : L_19 ) ;
break;
case V_243 :
if ( V_24 )
V_5 -> V_35 |= V_244 ;
else
V_5 -> V_35 &= ~ V_244 ;
F_45 ( V_47 , V_5 , L_20 ,
V_24 ? L_19 : L_18 ) ;
break;
case V_245 :
V_5 -> V_163 = ( V_246 ) V_24 ;
F_45 ( V_47 , V_5 , L_21 , V_5 -> V_163 ) ;
break;
case V_247 :
V_5 -> V_164 = ( V_248 ) V_24 ;
F_45 ( V_47 , V_5 , L_22 , V_5 -> V_164 ) ;
break;
case V_249 :
if ( V_5 -> V_11 -> V_35 & V_250 ) {
F_45 ( V_47 , V_5 ,
L_23 ) ;
V_157 = - V_14 ;
} else {
V_5 -> V_11 -> type = ( int ) V_24 ;
F_45 ( V_47 , V_5 , L_24 ,
V_5 -> V_11 -> type ) ;
V_157 = 0 ;
}
break;
#ifdef F_145
case V_251 :
V_5 -> V_252 = V_24 ;
break;
#endif
case V_253 :
V_157 = F_139 ( V_5 , V_24 ) ;
break;
case V_254 :
V_157 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_157 = F_26 ( & V_5 -> V_50 , ( void T_3 * ) V_24 ) ;
break;
case V_255 :
memcpy ( V_191 . V_256 . V_257 , V_5 -> V_11 -> V_85 , V_21 ) ;
V_191 . V_256 . V_258 = V_5 -> V_11 -> type ;
if ( F_144 ( V_231 , & V_191 , V_230 ) )
V_157 = - V_30 ;
break;
case V_259 :
F_45 ( V_260 , V_5 , L_25 ,
V_191 . V_256 . V_257 ) ;
V_157 = F_146 ( V_5 -> V_11 , & V_191 . V_256 ) ;
break;
case V_261 :
V_234 = V_5 -> V_15 . V_3 -> V_208 ;
if ( F_144 ( V_231 , & V_234 , sizeof( V_234 ) ) )
V_157 = - V_30 ;
break;
case V_262 :
if ( F_27 ( & V_234 , V_231 , sizeof( V_234 ) ) ) {
V_157 = - V_30 ;
break;
}
V_5 -> V_15 . V_3 -> V_208 = V_234 ;
break;
case V_263 :
V_108 = V_5 -> V_108 ;
if ( F_144 ( V_231 , & V_108 , sizeof( V_108 ) ) )
V_157 = - V_30 ;
break;
case V_264 :
if ( F_27 ( & V_108 , V_231 , sizeof( V_108 ) ) ) {
V_157 = - V_30 ;
break;
}
if ( V_108 < ( int ) sizeof( struct V_103 ) ) {
V_157 = - V_12 ;
break;
}
V_5 -> V_108 = V_108 ;
break;
case V_265 :
V_157 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_157 = - V_30 ;
if ( F_27 ( & V_233 , V_231 , sizeof( V_233 ) ) )
break;
V_157 = F_147 ( & V_233 , V_5 -> V_15 . V_3 ) ;
break;
case V_266 :
V_157 = - V_12 ;
if ( ( V_5 -> V_35 & V_73 ) != V_83 )
break;
V_157 = F_148 ( V_5 -> V_15 . V_3 ) ;
break;
default:
V_157 = - V_12 ;
break;
}
V_238:
F_17 () ;
if ( V_5 )
F_21 ( V_5 ) ;
return V_157 ;
}
static long F_149 ( struct V_6 * V_6 ,
unsigned int V_229 , unsigned long V_24 )
{
return F_141 ( V_6 , V_229 , V_24 , sizeof ( struct V_190 ) ) ;
}
static long F_150 ( struct V_6 * V_6 ,
unsigned int V_229 , unsigned long V_24 )
{
switch ( V_229 ) {
case V_235 :
case V_239 :
case V_254 :
case V_261 :
case V_262 :
case V_255 :
case V_259 :
V_24 = ( unsigned long ) F_151 ( V_24 ) ;
break;
default:
V_24 = ( V_267 ) V_24 ;
break;
}
return F_141 ( V_6 , V_229 , V_24 , sizeof( struct V_268 ) ) ;
}
static int F_152 ( int V_269 , struct V_6 * V_6 , int V_270 )
{
struct V_4 * V_5 = F_20 ( V_6 ) ;
int V_157 ;
if ( ! V_5 )
return - V_142 ;
F_45 ( V_47 , V_5 , L_26 , V_270 ) ;
if ( ( V_157 = F_153 ( V_269 , V_6 , V_270 , & V_5 -> V_57 ) ) < 0 )
goto V_13;
if ( V_270 ) {
V_157 = F_154 ( V_6 , F_155 ( V_156 ) , V_271 , 0 ) ;
if ( V_157 )
goto V_13;
V_5 -> V_35 |= V_56 ;
} else
V_5 -> V_35 &= ~ V_56 ;
V_157 = 0 ;
V_13:
F_21 ( V_5 ) ;
return V_157 ;
}
static int F_156 ( struct V_272 * V_272 , struct V_6 * V_6 )
{
struct V_7 * V_8 ;
F_157 ( V_47 , L_27 ) ;
V_8 = F_28 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return - V_32 ;
F_158 ( & V_8 -> V_16 , 0 ) ;
V_8 -> V_5 = NULL ;
V_8 -> V_189 = F_159 ( V_156 -> V_240 -> V_241 ) ;
V_6 -> V_9 = V_8 ;
return 0 ;
}
static int F_160 ( struct V_272 * V_272 , struct V_6 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_4 * V_5 ;
V_5 = F_18 ( V_8 ) ;
if ( V_5 ) {
struct V_44 * V_11 = V_5 -> V_11 ;
F_45 ( V_47 , V_5 , L_28 ) ;
F_11 ( V_5 ) ;
if ( ! ( V_5 -> V_35 & V_244 ) ) {
F_16 () ;
if ( V_11 -> V_91 == V_92 )
F_161 ( V_11 ) ;
F_17 () ;
}
}
V_5 = V_8 -> V_5 ;
if ( V_5 )
F_39 ( V_5 -> V_15 . V_3 ) ;
F_162 ( V_8 -> V_189 ) ;
F_31 ( V_8 ) ;
return 0 ;
}
static int F_163 ( struct V_44 * V_11 , struct V_273 * V_229 )
{
V_229 -> V_274 = 0 ;
V_229 -> V_275 = 0 ;
F_164 ( V_229 , V_276 ) ;
V_229 -> V_277 = V_278 ;
V_229 -> V_279 = V_280 ;
V_229 -> V_281 = 0 ;
V_229 -> V_282 = V_283 ;
V_229 -> V_284 = V_285 ;
V_229 -> V_286 = 0 ;
V_229 -> V_287 = 0 ;
return 0 ;
}
static void F_165 ( struct V_44 * V_11 , struct V_288 * V_289 )
{
struct V_4 * V_5 = F_36 ( V_11 ) ;
strcpy ( V_289 -> V_290 , V_291 ) ;
strcpy ( V_289 -> V_292 , V_293 ) ;
strcpy ( V_289 -> V_294 , L_29 ) ;
switch ( V_5 -> V_35 & V_73 ) {
case V_74 :
strcpy ( V_289 -> V_295 , L_30 ) ;
break;
case V_83 :
strcpy ( V_289 -> V_295 , L_31 ) ;
break;
}
}
static T_1 F_166 ( struct V_44 * V_11 )
{
#ifdef F_145
struct V_4 * V_5 = F_36 ( V_11 ) ;
return V_5 -> V_252 ;
#else
return - V_296 ;
#endif
}
static void F_167 ( struct V_44 * V_11 , T_1 V_297 )
{
#ifdef F_145
struct V_4 * V_5 = F_36 ( V_11 ) ;
V_5 -> V_252 = V_297 ;
#endif
}
static int T_11 F_168 ( void )
{
int V_157 = 0 ;
F_169 ( L_32 , V_298 , V_293 ) ;
F_169 ( L_33 , V_299 ) ;
V_157 = F_170 ( & V_201 ) ;
if ( V_157 ) {
F_90 ( L_34 ) ;
goto V_300;
}
V_157 = F_171 ( & V_301 ) ;
if ( V_157 ) {
F_90 ( L_35 , V_302 ) ;
goto V_303;
}
return 0 ;
V_303:
F_172 ( & V_201 ) ;
V_300:
return V_157 ;
}
static void F_173 ( void )
{
F_174 ( & V_301 ) ;
F_172 ( & V_201 ) ;
}
struct V_15 * F_175 ( struct V_6 * V_6 )
{
struct V_4 * V_5 ;
if ( V_6 -> V_304 != & V_305 )
return F_67 ( - V_12 ) ;
V_5 = F_20 ( V_6 ) ;
if ( ! V_5 )
return F_67 ( - V_142 ) ;
F_21 ( V_5 ) ;
return & V_5 -> V_15 ;
}
