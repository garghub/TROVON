static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
unsigned int V_13 = 0 ;
struct V_14 * V_15 ;
switch ( type ) {
default:
case V_16 :
return;
case V_17 :
switch ( V_12 ) {
case V_18 :
case V_19 :
return;
default:
break;
}
break;
case V_20 :
if ( V_12 != V_21 )
return;
V_13 = F_3 ( V_2 ) -> V_22 . V_23 [ 1 ] * 4 ;
break;
case V_24 :
break;
}
if ( V_5 -> V_25 == F_4 ( V_26 ) )
V_9 = F_5 ( V_6 , V_27 ) ;
else
V_9 = F_5 ( V_6 , V_28 ) ;
V_11 = ( const struct V_10 * ) ( F_3 ( V_2 ) + 1 ) ;
V_15 = F_6 ( V_9 , V_2 -> V_7 -> V_29 , V_5 -> V_30 ,
V_11 -> V_31 , V_11 -> V_32 , V_5 -> V_33 ) ;
if ( ! V_15 )
return;
#if F_7 ( V_34 )
if ( V_5 -> V_25 == F_4 ( V_35 ) &&
! F_8 ( V_2 , V_11 -> V_36 * 4 + V_5 -> V_37 ,
type , V_13 ) )
return;
#endif
if ( V_15 -> V_38 . V_11 . V_31 == 0 ||
F_9 ( V_15 -> V_38 . V_11 . V_31 ) )
return;
if ( V_15 -> V_38 . V_11 . V_39 == 0 && type == V_20 )
return;
if ( F_10 ( V_40 , V_15 -> V_41 + V_42 ) )
V_15 -> V_43 ++ ;
else
V_15 -> V_43 = 1 ;
V_15 -> V_41 = V_40 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_44 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
struct V_4 V_5 ;
bool V_45 = false ;
if ( F_12 ( V_2 , & V_5 , & V_45 , F_4 ( V_46 ) ,
V_11 -> V_36 * 4 ) < 0 ) {
if ( ! V_45 )
return;
}
if ( type == V_17 && V_12 == V_47 ) {
F_13 ( V_2 , F_2 ( V_2 -> V_7 ) , V_3 ,
V_2 -> V_7 -> V_29 , 0 , V_48 , 0 ) ;
return;
}
if ( type == V_24 ) {
F_14 ( V_2 , F_2 ( V_2 -> V_7 ) , V_2 -> V_7 -> V_29 , 0 ,
V_48 , 0 ) ;
return;
}
F_1 ( V_2 , V_3 , & V_5 ) ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
struct V_8 * V_9 , int V_37 , bool V_49 )
{
struct V_50 * V_51 = NULL ;
const struct V_10 * V_11 ;
struct V_14 * V_52 ;
V_11 = F_16 ( V_2 ) ;
V_52 = F_6 ( V_9 , V_2 -> V_7 -> V_29 , V_5 -> V_30 ,
V_11 -> V_32 , V_11 -> V_31 , V_5 -> V_33 ) ;
if ( V_52 ) {
if ( F_17 ( V_2 , V_37 , V_5 -> V_25 ,
V_49 , false ) < 0 )
goto V_53;
if ( V_52 -> V_7 -> type != V_54 )
F_18 ( V_2 ) ;
else
F_19 ( V_2 ) ;
if ( V_52 -> V_55 ) {
T_2 V_30 ;
T_3 V_56 ;
V_30 = V_5 -> V_30 & ( V_57 | V_58 ) ;
V_56 = F_20 ( V_5 -> V_33 ) ;
V_51 = F_21 ( V_2 , V_30 , V_56 , 0 ) ;
if ( ! V_51 )
return V_59 ;
}
F_22 ( V_52 , V_2 , V_5 , V_51 , V_60 ) ;
return V_61 ;
}
return V_62 ;
V_53:
F_23 ( V_2 ) ;
return V_61 ;
}
static int F_24 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
int V_37 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_63 ;
if ( V_5 -> V_25 == F_4 ( V_26 ) )
V_9 = F_5 ( V_6 , V_27 ) ;
else
V_9 = F_5 ( V_6 , V_28 ) ;
V_63 = F_15 ( V_2 , V_5 , V_9 , V_37 , false ) ;
if ( V_63 == V_62 && V_5 -> V_25 == F_4 ( V_26 ) ) {
V_9 = F_5 ( V_6 , V_28 ) ;
V_63 = F_15 ( V_2 , V_5 , V_9 , V_37 , true ) ;
}
return V_63 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
bool V_45 = false ;
int V_37 ;
#ifdef F_26
if ( F_9 ( F_16 ( V_2 ) -> V_31 ) ) {
if ( F_27 ( F_28 ( V_2 ) ) )
goto V_53;
}
#endif
V_37 = F_12 ( V_2 , & V_5 , & V_45 , F_4 ( V_46 ) , 0 ) ;
if ( V_37 < 0 )
goto V_53;
if ( F_24 ( V_2 , & V_5 , V_37 ) == V_61 )
return 0 ;
F_29 ( V_2 , V_17 , V_19 , 0 ) ;
V_53:
F_23 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_64 * V_7 ,
const struct V_10 * V_65 ,
T_2 V_25 )
{
struct V_14 * V_52 = F_31 ( V_7 ) ;
if ( V_52 -> V_38 . V_66 & V_67 )
V_52 -> V_68 ++ ;
F_32 ( V_2 , V_52 -> V_69 ,
V_52 -> V_38 . V_66 , V_25 , V_52 -> V_38 . V_70 ,
F_33 ( V_52 -> V_68 ) ) ;
F_34 ( V_2 , V_7 , V_65 , V_65 -> V_71 ) ;
}
static int F_35 ( struct V_1 * V_2 , bool V_72 )
{
return F_36 ( V_2 , V_72 ? V_73 : V_74 ) ;
}
static struct V_75 * F_37 ( struct V_1 * V_2 ,
struct V_64 * V_7 ,
struct V_76 * V_77 ,
const struct V_78 * V_33 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_31 = V_33 -> V_79 . V_80 . V_81 ;
V_77 -> V_32 = V_33 -> V_79 . V_80 . V_82 ;
V_77 -> V_83 = F_38 ( V_33 -> V_84 ) ;
V_77 -> V_85 = V_2 -> V_86 ;
V_77 -> V_87 = V_48 ;
return F_39 ( V_6 , V_77 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_64 * V_7 ,
T_2 V_25 )
{
struct V_88 * V_89 ;
const struct V_78 * V_33 ;
struct V_75 * V_90 = NULL ;
struct V_76 V_77 ;
int V_91 ;
int V_92 ;
T_2 V_93 , V_30 ;
bool V_94 ;
int V_95 ;
V_89 = F_41 ( V_2 ) ;
if ( F_42 ( ! V_89 || ! ( V_89 -> V_96 & V_97 ) ||
F_43 ( V_89 ) != V_98 ) )
goto V_99;
V_33 = & V_89 -> V_33 ;
V_94 = F_44 ( V_2 , V_89 ) ;
if ( V_94 )
V_90 = F_45 ( & V_89 -> V_100 , & V_77 . V_32 ) ;
if ( ! V_90 ) {
V_90 = F_37 ( V_2 , V_7 , & V_77 , V_33 ) ;
if ( F_46 ( V_90 ) )
goto V_99;
if ( V_94 )
F_47 ( & V_89 -> V_100 , & V_90 -> V_81 ,
V_77 . V_32 ) ;
}
V_92 = F_48 ( V_33 -> V_101 ) ;
V_91 = F_49 ( V_90 -> V_81 . V_7 ) + V_90 -> V_81 . V_102
+ V_92 + sizeof( struct V_10 ) ;
if ( F_50 ( V_2 ) < V_91 || F_51 ( V_2 ) ) {
int V_103 = F_52 ( V_91 -
F_50 ( V_2 ) +
16 ) ;
V_95 = F_53 ( V_2 , F_54 ( int , V_103 , 0 ) ,
0 , V_104 ) ;
if ( F_42 ( V_95 ) )
goto V_105;
}
if ( F_35 ( V_2 , ! ! ( V_89 -> V_33 . V_101 & V_57 ) ) )
goto V_105;
V_30 = V_89 -> V_33 . V_101 & ( V_57 | V_58 ) ;
F_32 ( V_2 , V_92 , V_30 , V_25 ,
F_55 ( V_89 -> V_33 . V_56 ) , 0 ) ;
V_93 = V_33 -> V_101 & V_106 ? F_4 ( V_107 ) : 0 ;
F_56 ( V_2 -> V_108 , V_90 , V_2 , V_77 . V_32 , V_33 -> V_79 . V_80 . V_81 , V_48 ,
V_33 -> V_84 , V_33 -> V_39 , V_93 , false ) ;
return;
V_105:
F_57 ( V_90 ) ;
V_99:
F_23 ( V_2 ) ;
V_7 -> V_109 . V_110 ++ ;
}
static int F_58 ( struct V_64 * V_7 , struct V_1 * V_2 )
{
struct V_88 * V_3 = F_41 ( V_2 ) ;
struct V_75 * V_90 ;
struct V_76 V_111 ;
if ( F_43 ( V_3 ) != V_98 )
return - V_112 ;
V_90 = F_37 ( V_2 , V_7 , & V_111 , & V_3 -> V_33 ) ;
if ( F_46 ( V_90 ) )
return F_59 ( V_90 ) ;
F_57 ( V_90 ) ;
V_3 -> V_33 . V_79 . V_80 . V_82 = V_111 . V_32 ;
return 0 ;
}
static T_4 F_60 ( struct V_1 * V_2 ,
struct V_64 * V_7 )
{
struct V_14 * V_52 = F_31 ( V_7 ) ;
const struct V_10 * V_65 ;
if ( V_52 -> V_55 ) {
F_40 ( V_2 , V_7 , V_2 -> V_71 ) ;
return V_113 ;
}
if ( V_7 -> V_114 ) {
if ( F_61 ( V_2 , V_7 -> V_115 -
( V_52 -> V_116 + sizeof( struct V_10 ) ) ) )
goto V_117;
V_65 = ( const struct V_10 * ) V_2 -> V_44 ;
F_62 ( V_2 , V_52 -> V_116 + sizeof( struct V_10 ) ) ;
F_19 ( V_2 ) ;
} else {
if ( F_61 ( V_2 , V_7 -> V_115 ) )
goto V_117;
V_65 = & V_52 -> V_38 . V_11 ;
}
if ( F_35 ( V_2 , ! ! ( V_52 -> V_38 . V_66 & V_57 ) ) )
goto V_117;
F_30 ( V_2 , V_7 , V_65 , V_2 -> V_71 ) ;
return V_113 ;
V_117:
F_23 ( V_2 ) ;
V_7 -> V_109 . V_110 ++ ;
return V_113 ;
}
static T_4 F_63 ( struct V_1 * V_2 ,
struct V_64 * V_7 )
{
struct V_14 * V_52 = F_31 ( V_7 ) ;
if ( V_52 -> V_55 ) {
F_40 ( V_2 , V_7 , F_4 ( V_26 ) ) ;
return V_113 ;
}
if ( F_35 ( V_2 , ! ! ( V_52 -> V_38 . V_66 & V_57 ) ) )
goto V_117;
if ( F_61 ( V_2 , V_7 -> V_115 ) )
goto V_117;
F_30 ( V_2 , V_7 , & V_52 -> V_38 . V_11 , F_4 ( V_26 ) ) ;
return V_113 ;
V_117:
F_23 ( V_2 ) ;
V_7 -> V_109 . V_110 ++ ;
return V_113 ;
}
static int F_64 ( struct V_64 * V_7 ,
struct V_118 * V_119 , int V_120 )
{
int V_95 ;
struct V_121 V_122 ;
if ( F_65 ( & V_122 , V_119 -> V_123 . V_124 , sizeof( V_122 ) ) )
return - V_125 ;
if ( V_120 == V_126 || V_120 == V_127 ) {
if ( V_122 . V_11 . V_128 != 4 || V_122 . V_11 . V_71 != V_48 ||
V_122 . V_11 . V_36 != 5 || ( V_122 . V_11 . V_129 & F_4 ( ~ V_107 ) ) ||
( ( V_122 . V_130 | V_122 . V_66 ) & ( V_131 | V_132 ) ) )
return - V_112 ;
}
V_122 . V_130 = F_66 ( V_122 . V_130 ) ;
V_122 . V_66 = F_66 ( V_122 . V_66 ) ;
V_95 = F_67 ( V_7 , & V_122 , V_120 ) ;
if ( V_95 )
return V_95 ;
V_122 . V_130 = F_68 ( V_122 . V_130 ) ;
V_122 . V_66 = F_68 ( V_122 . V_66 ) ;
if ( F_69 ( V_119 -> V_123 . V_124 , & V_122 , sizeof( V_122 ) ) )
return - V_125 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_64 * V_7 ,
unsigned short type ,
const void * V_31 , const void * V_32 , unsigned int V_133 )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_134 * V_135 ;
V_11 = (struct V_10 * ) F_71 ( V_2 , V_15 -> V_116 + sizeof( * V_11 ) ) ;
V_135 = (struct V_134 * ) ( V_11 + 1 ) ;
V_135 -> V_30 = F_68 ( V_15 -> V_38 . V_66 ) ;
V_135 -> V_71 = F_4 ( type ) ;
memcpy ( V_11 , & V_15 -> V_38 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_32 )
memcpy ( & V_11 -> V_32 , V_32 , 4 ) ;
if ( V_31 )
memcpy ( & V_11 -> V_31 , V_31 , 4 ) ;
if ( V_11 -> V_31 )
return V_15 -> V_116 + sizeof( * V_11 ) ;
return - ( V_15 -> V_116 + sizeof( * V_11 ) ) ;
}
static int F_72 ( const struct V_1 * V_2 , unsigned char * V_136 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_73 ( V_2 ) ;
memcpy ( V_136 , & V_11 -> V_32 , 4 ) ;
return 4 ;
}
static int F_74 ( struct V_64 * V_7 )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) ) {
struct V_76 V_111 ;
struct V_75 * V_90 ;
V_90 = F_75 ( V_15 -> V_6 , & V_111 ,
V_15 -> V_38 . V_11 . V_31 ,
V_15 -> V_38 . V_11 . V_32 ,
V_15 -> V_38 . V_70 ,
F_38 ( V_15 -> V_38 . V_11 . V_84 ) ,
V_15 -> V_38 . V_137 ) ;
if ( F_46 ( V_90 ) )
return - V_138 ;
V_7 = V_90 -> V_81 . V_7 ;
F_57 ( V_90 ) ;
if ( ! F_76 ( V_7 ) )
return - V_138 ;
V_15 -> V_139 = V_7 -> V_29 ;
F_77 ( F_76 ( V_7 ) , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static int F_78 ( struct V_64 * V_7 )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) && V_15 -> V_139 ) {
struct V_140 * V_141 ;
V_141 = F_79 ( V_15 -> V_6 , V_15 -> V_139 ) ;
if ( V_141 )
F_80 ( V_141 , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static void F_81 ( struct V_64 * V_7 )
{
V_7 -> V_142 = & V_143 ;
V_7 -> type = V_144 ;
F_82 ( V_7 , V_28 ) ;
}
static void F_83 ( struct V_64 * V_7 )
{
struct V_14 * V_52 ;
int V_145 ;
V_52 = F_31 ( V_7 ) ;
V_52 -> V_69 = F_48 ( V_52 -> V_38 . V_66 ) ;
V_52 -> V_38 . V_11 . V_71 = V_48 ;
V_52 -> V_116 = V_52 -> V_69 + V_52 -> V_146 ;
V_145 = V_52 -> V_116 + sizeof( struct V_10 ) ;
V_7 -> V_115 = V_147 + V_145 + 4 ;
V_7 -> V_148 = V_149 - V_145 - 4 ;
V_7 -> V_150 |= V_151 ;
V_7 -> V_152 |= V_151 ;
if ( ! ( V_52 -> V_38 . V_66 & V_67 ) ) {
if ( ! ( V_52 -> V_38 . V_66 & V_57 ) ||
( V_52 -> V_153 . type == V_154 ) ) {
V_7 -> V_150 |= V_155 ;
V_7 -> V_152 |= V_155 ;
}
V_7 -> V_150 |= V_156 ;
}
}
static int F_84 ( struct V_64 * V_7 )
{
struct V_14 * V_52 = F_31 ( V_7 ) ;
struct V_10 * V_11 = & V_52 -> V_38 . V_11 ;
F_83 ( V_7 ) ;
memcpy ( V_7 -> V_157 , & V_11 -> V_32 , 4 ) ;
memcpy ( V_7 -> V_158 , & V_11 -> V_31 , 4 ) ;
V_7 -> V_30 = V_159 ;
F_85 ( V_7 ) ;
V_7 -> V_160 = 4 ;
if ( V_11 -> V_31 && ! V_52 -> V_55 ) {
#ifdef F_26
if ( F_9 ( V_11 -> V_31 ) ) {
if ( ! V_11 -> V_32 )
return - V_112 ;
V_7 -> V_30 = V_161 ;
V_7 -> V_114 = & V_162 ;
}
#endif
} else if ( ! V_52 -> V_55 ) {
V_7 -> V_114 = & V_162 ;
}
return F_86 ( V_7 ) ;
}
static int T_5 F_87 ( struct V_6 * V_6 )
{
return F_88 ( V_6 , V_28 , & V_163 , NULL ) ;
}
static void T_6 F_89 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_28 ) ;
F_90 ( V_9 , & V_163 ) ;
}
static int F_91 ( struct V_164 * V_165 [] , struct V_164 * V_44 [] )
{
T_2 V_30 ;
if ( ! V_44 )
return 0 ;
V_30 = 0 ;
if ( V_44 [ V_166 ] )
V_30 |= F_92 ( V_44 [ V_166 ] ) ;
if ( V_44 [ V_167 ] )
V_30 |= F_92 ( V_44 [ V_167 ] ) ;
if ( V_30 & ( V_131 | V_132 ) )
return - V_112 ;
if ( V_44 [ V_168 ] &&
V_44 [ V_169 ] &&
F_93 ( V_44 [ V_169 ] ) != V_154 )
return - V_112 ;
return 0 ;
}
static int F_94 ( struct V_164 * V_165 [] , struct V_164 * V_44 [] )
{
T_7 V_31 ;
if ( V_165 [ V_170 ] ) {
if ( F_95 ( V_165 [ V_170 ] ) != V_171 )
return - V_112 ;
if ( ! F_96 ( F_97 ( V_165 [ V_170 ] ) ) )
return - V_138 ;
}
if ( ! V_44 )
goto V_172;
if ( V_44 [ V_173 ] ) {
memcpy ( & V_31 , F_97 ( V_44 [ V_173 ] ) , 4 ) ;
if ( ! V_31 )
return - V_112 ;
}
V_172:
return F_91 ( V_165 , V_44 ) ;
}
static int F_98 ( struct V_64 * V_7 ,
struct V_164 * V_44 [] ,
struct V_164 * V_165 [] ,
struct V_121 * V_38 ,
T_8 * V_174 )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_11 . V_71 = V_48 ;
if ( ! V_44 )
return 0 ;
if ( V_44 [ V_175 ] )
V_38 -> V_137 = F_99 ( V_44 [ V_175 ] ) ;
if ( V_44 [ V_166 ] )
V_38 -> V_130 = F_66 ( F_92 ( V_44 [ V_166 ] ) ) ;
if ( V_44 [ V_167 ] )
V_38 -> V_66 = F_66 ( F_92 ( V_44 [ V_167 ] ) ) ;
if ( V_44 [ V_176 ] )
V_38 -> V_177 = F_100 ( V_44 [ V_176 ] ) ;
if ( V_44 [ V_178 ] )
V_38 -> V_70 = F_100 ( V_44 [ V_178 ] ) ;
if ( V_44 [ V_179 ] )
V_38 -> V_11 . V_32 = F_101 ( V_44 [ V_179 ] ) ;
if ( V_44 [ V_173 ] )
V_38 -> V_11 . V_31 = F_101 ( V_44 [ V_173 ] ) ;
if ( V_44 [ V_180 ] )
V_38 -> V_11 . V_39 = F_102 ( V_44 [ V_180 ] ) ;
if ( V_44 [ V_181 ] )
V_38 -> V_11 . V_84 = F_102 ( V_44 [ V_181 ] ) ;
if ( ! V_44 [ V_182 ] || F_102 ( V_44 [ V_182 ] ) ) {
if ( V_15 -> V_183 )
return - V_112 ;
V_38 -> V_11 . V_129 = F_4 ( V_107 ) ;
}
if ( V_44 [ V_168 ] ) {
V_15 -> V_55 = true ;
if ( V_7 -> type == V_144 )
V_7 -> type = V_54 ;
}
if ( V_44 [ V_184 ] ) {
if ( F_102 ( V_44 [ V_184 ] )
&& ( V_38 -> V_11 . V_129 & F_4 ( V_107 ) ) )
return - V_112 ;
V_15 -> V_183 = ! ! F_102 ( V_44 [ V_184 ] ) ;
}
if ( V_44 [ V_185 ] )
* V_174 = F_99 ( V_44 [ V_185 ] ) ;
return 0 ;
}
static bool F_103 ( struct V_164 * V_44 [] ,
struct V_186 * V_187 )
{
bool V_188 = false ;
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
if ( ! V_44 )
return V_188 ;
if ( V_44 [ V_169 ] ) {
V_188 = true ;
V_187 -> type = F_93 ( V_44 [ V_169 ] ) ;
}
if ( V_44 [ V_189 ] ) {
V_188 = true ;
V_187 -> V_30 = F_93 ( V_44 [ V_189 ] ) ;
}
if ( V_44 [ V_190 ] ) {
V_188 = true ;
V_187 -> V_191 = F_92 ( V_44 [ V_190 ] ) ;
}
if ( V_44 [ V_192 ] ) {
V_188 = true ;
V_187 -> V_193 = F_92 ( V_44 [ V_192 ] ) ;
}
return V_188 ;
}
static int F_104 ( struct V_64 * V_7 )
{
F_83 ( V_7 ) ;
V_7 -> V_194 |= V_195 ;
return F_86 ( V_7 ) ;
}
static void F_105 ( struct V_64 * V_7 )
{
F_106 ( V_7 ) ;
V_7 -> V_142 = & V_196 ;
V_7 -> V_194 &= ~ V_197 ;
V_7 -> V_194 |= V_195 ;
F_82 ( V_7 , V_27 ) ;
}
static int F_107 ( struct V_6 * V_198 , struct V_64 * V_7 ,
struct V_164 * V_165 [] , struct V_164 * V_44 [] )
{
struct V_121 V_122 ;
struct V_186 V_187 ;
T_8 V_174 = 0 ;
int V_95 ;
if ( F_103 ( V_44 , & V_187 ) ) {
struct V_14 * V_15 = F_31 ( V_7 ) ;
V_95 = F_108 ( V_15 , & V_187 ) ;
if ( V_95 < 0 )
return V_95 ;
}
V_95 = F_98 ( V_7 , V_44 , V_165 , & V_122 , & V_174 ) ;
if ( V_95 < 0 )
return V_95 ;
return F_109 ( V_7 , V_165 , & V_122 , V_174 ) ;
}
static int F_110 ( struct V_64 * V_7 , struct V_164 * V_165 [] ,
struct V_164 * V_44 [] )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
struct V_121 V_122 ;
struct V_186 V_187 ;
T_8 V_174 = V_15 -> V_174 ;
int V_95 ;
if ( F_103 ( V_44 , & V_187 ) ) {
V_95 = F_108 ( V_15 , & V_187 ) ;
if ( V_95 < 0 )
return V_95 ;
}
V_95 = F_98 ( V_7 , V_44 , V_165 , & V_122 , & V_174 ) ;
if ( V_95 < 0 )
return V_95 ;
return F_111 ( V_7 , V_165 , & V_122 , V_174 ) ;
}
static T_9 F_112 ( const struct V_64 * V_7 )
{
return
F_113 ( 4 ) +
F_113 ( 2 ) +
F_113 ( 2 ) +
F_113 ( 4 ) +
F_113 ( 4 ) +
F_113 ( 4 ) +
F_113 ( 4 ) +
F_113 ( 1 ) +
F_113 ( 1 ) +
F_113 ( 1 ) +
F_113 ( 2 ) +
F_113 ( 2 ) +
F_113 ( 2 ) +
F_113 ( 2 ) +
F_113 ( 0 ) +
F_113 ( 1 ) +
F_113 ( 4 ) +
0 ;
}
static int F_114 ( struct V_1 * V_2 , const struct V_64 * V_7 )
{
struct V_14 * V_15 = F_31 ( V_7 ) ;
struct V_121 * V_122 = & V_15 -> V_38 ;
if ( F_115 ( V_2 , V_175 , V_122 -> V_137 ) ||
F_116 ( V_2 , V_166 ,
F_68 ( V_122 -> V_130 ) ) ||
F_116 ( V_2 , V_167 ,
F_68 ( V_122 -> V_66 ) ) ||
F_117 ( V_2 , V_176 , V_122 -> V_177 ) ||
F_117 ( V_2 , V_178 , V_122 -> V_70 ) ||
F_118 ( V_2 , V_179 , V_122 -> V_11 . V_32 ) ||
F_118 ( V_2 , V_173 , V_122 -> V_11 . V_31 ) ||
F_119 ( V_2 , V_180 , V_122 -> V_11 . V_39 ) ||
F_119 ( V_2 , V_181 , V_122 -> V_11 . V_84 ) ||
F_119 ( V_2 , V_182 ,
! ! ( V_122 -> V_11 . V_129 & F_4 ( V_107 ) ) ) ||
F_115 ( V_2 , V_185 , V_15 -> V_174 ) )
goto V_199;
if ( F_120 ( V_2 , V_169 ,
V_15 -> V_153 . type ) ||
F_116 ( V_2 , V_190 ,
V_15 -> V_153 . V_191 ) ||
F_116 ( V_2 , V_192 ,
V_15 -> V_153 . V_193 ) ||
F_120 ( V_2 , V_189 ,
V_15 -> V_153 . V_30 ) )
goto V_199;
if ( F_119 ( V_2 , V_184 , V_15 -> V_183 ) )
goto V_199;
if ( V_15 -> V_55 ) {
if ( F_121 ( V_2 , V_168 ) )
goto V_199;
}
return 0 ;
V_199:
return - V_200 ;
}
struct V_64 * F_122 ( struct V_6 * V_6 , const char * V_201 ,
T_10 V_202 )
{
struct V_164 * V_165 [ V_203 + 1 ] ;
struct V_64 * V_7 ;
F_123 ( V_204 ) ;
struct V_14 * V_15 ;
int V_95 ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_7 = F_124 ( V_6 , V_201 , V_202 ,
& V_205 , V_165 ) ;
if ( F_46 ( V_7 ) )
return V_7 ;
V_15 = F_31 ( V_7 ) ;
V_15 -> V_55 = true ;
V_95 = F_107 ( V_6 , V_7 , V_165 , NULL ) ;
if ( V_95 < 0 ) {
F_125 ( V_7 ) ;
return F_126 ( V_95 ) ;
}
V_95 = F_127 ( V_7 , V_206 , false ) ;
if ( V_95 )
goto V_172;
V_95 = F_128 ( V_7 , NULL ) ;
if ( V_95 < 0 )
goto V_172;
return V_7 ;
V_172:
F_129 ( V_7 , & V_204 ) ;
F_130 ( & V_204 ) ;
return F_126 ( V_95 ) ;
}
static int T_5 F_131 ( struct V_6 * V_6 )
{
return F_88 ( V_6 , V_27 , & V_205 , L_1 ) ;
}
static void T_6 F_132 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_27 ) ;
F_90 ( V_9 , & V_205 ) ;
}
static int T_11 F_133 ( void )
{
int V_95 ;
F_134 ( L_2 ) ;
V_95 = F_135 ( & V_207 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_135 ( & V_208 ) ;
if ( V_95 < 0 )
goto V_209;
V_95 = F_136 ( & V_210 , V_211 ) ;
if ( V_95 < 0 ) {
F_134 ( L_3 , V_212 ) ;
goto V_213;
}
V_95 = F_137 ( & V_163 ) ;
if ( V_95 < 0 )
goto V_214;
V_95 = F_137 ( & V_205 ) ;
if ( V_95 < 0 )
goto V_215;
return 0 ;
V_215:
F_138 ( & V_163 ) ;
V_214:
F_139 ( & V_210 , V_211 ) ;
V_213:
F_140 ( & V_208 ) ;
V_209:
F_140 ( & V_207 ) ;
return V_95 ;
}
static void T_12 F_141 ( void )
{
F_138 ( & V_205 ) ;
F_138 ( & V_163 ) ;
F_139 ( & V_210 , V_211 ) ;
F_140 ( & V_208 ) ;
F_140 ( & V_207 ) ;
}
