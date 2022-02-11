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
static T_2 F_15 ( T_3 V_33 )
{
#ifdef F_16
return ( V_49 T_2 ) ( ( V_49 T_1 ) V_33 ) ;
#else
return ( V_49 T_2 ) ( ( V_49 V_50 ) V_33 << 32 ) ;
#endif
}
static T_3 F_17 ( T_2 V_51 )
{
#ifdef F_16
return ( V_49 T_3 ) V_51 ;
#else
return ( V_49 T_3 ) ( ( V_49 V_50 ) V_51 >> 32 ) ;
#endif
}
static int F_18 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
struct V_8 * V_9 , int V_37 , bool V_52 )
{
struct V_53 * V_54 = NULL ;
const struct V_10 * V_11 ;
struct V_14 * V_55 ;
V_11 = F_19 ( V_2 ) ;
V_55 = F_6 ( V_9 , V_2 -> V_7 -> V_29 , V_5 -> V_30 ,
V_11 -> V_32 , V_11 -> V_31 , V_5 -> V_33 ) ;
if ( V_55 ) {
if ( F_20 ( V_2 , V_37 , V_5 -> V_25 ,
V_52 , false ) < 0 )
goto V_56;
if ( V_55 -> V_7 -> type != V_57 )
F_21 ( V_2 ) ;
else
F_22 ( V_2 ) ;
if ( V_55 -> V_58 ) {
T_4 V_30 ;
T_2 V_59 ;
V_30 = V_5 -> V_30 & ( V_60 | V_61 ) ;
V_59 = F_15 ( V_5 -> V_33 ) ;
V_54 = F_23 ( V_2 , V_30 , V_59 , 0 ) ;
if ( ! V_54 )
return V_62 ;
}
F_24 ( V_55 , V_2 , V_5 , V_54 , V_63 ) ;
return V_64 ;
}
return V_65 ;
V_56:
F_25 ( V_2 ) ;
return V_64 ;
}
static int F_26 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
int V_37 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_66 ;
if ( V_5 -> V_25 == F_4 ( V_26 ) )
V_9 = F_5 ( V_6 , V_27 ) ;
else
V_9 = F_5 ( V_6 , V_28 ) ;
V_66 = F_18 ( V_2 , V_5 , V_9 , V_37 , false ) ;
if ( V_66 == V_65 && V_5 -> V_25 == F_4 ( V_26 ) ) {
V_9 = F_5 ( V_6 , V_28 ) ;
V_66 = F_18 ( V_2 , V_5 , V_9 , V_37 , true ) ;
}
return V_66 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
bool V_45 = false ;
int V_37 ;
#ifdef F_28
if ( F_9 ( F_19 ( V_2 ) -> V_31 ) ) {
if ( F_29 ( F_30 ( V_2 ) ) )
goto V_56;
}
#endif
V_37 = F_12 ( V_2 , & V_5 , & V_45 , F_4 ( V_46 ) , 0 ) ;
if ( V_37 < 0 )
goto V_56;
if ( F_26 ( V_2 , & V_5 , V_37 ) == V_64 )
return 0 ;
F_31 ( V_2 , V_17 , V_19 , 0 ) ;
V_56:
F_25 ( V_2 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_67 * V_7 ,
const struct V_10 * V_68 ,
T_4 V_25 )
{
struct V_14 * V_55 = F_33 ( V_7 ) ;
if ( V_55 -> V_38 . V_69 & V_70 )
V_55 -> V_71 ++ ;
F_34 ( V_2 , V_55 -> V_72 ,
V_55 -> V_38 . V_69 , V_25 , V_55 -> V_38 . V_73 ,
F_35 ( V_55 -> V_71 ) ) ;
F_36 ( V_2 , V_7 , V_68 , V_68 -> V_74 ) ;
}
static int F_37 ( struct V_1 * V_2 , bool V_75 )
{
return F_38 ( V_2 , V_75 ? V_76 : V_77 ) ;
}
static struct V_78 * F_39 ( struct V_1 * V_2 ,
struct V_67 * V_7 ,
struct V_79 * V_80 ,
const struct V_81 * V_33 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
V_80 -> V_31 = V_33 -> V_82 . V_83 . V_84 ;
V_80 -> V_32 = V_33 -> V_82 . V_83 . V_85 ;
V_80 -> V_86 = F_40 ( V_33 -> V_87 ) ;
V_80 -> V_88 = V_2 -> V_89 ;
V_80 -> V_90 = V_48 ;
return F_41 ( V_6 , V_80 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_67 * V_7 ,
T_4 V_25 )
{
struct V_91 * V_92 ;
const struct V_81 * V_33 ;
struct V_78 * V_93 = NULL ;
struct V_79 V_80 ;
int V_94 ;
int V_95 ;
T_4 V_96 , V_30 ;
bool V_97 ;
int V_98 ;
V_92 = F_43 ( V_2 ) ;
if ( F_44 ( ! V_92 || ! ( V_92 -> V_99 & V_100 ) ||
F_45 ( V_92 ) != V_101 ) )
goto V_102;
V_33 = & V_92 -> V_33 ;
V_97 = F_46 ( V_2 , V_92 ) ;
if ( V_97 )
V_93 = F_47 ( & V_92 -> V_103 , & V_80 . V_32 ) ;
if ( ! V_93 ) {
V_93 = F_39 ( V_2 , V_7 , & V_80 , V_33 ) ;
if ( F_48 ( V_93 ) )
goto V_102;
if ( V_97 )
F_49 ( & V_92 -> V_103 , & V_93 -> V_84 ,
V_80 . V_32 ) ;
}
V_95 = F_50 ( V_33 -> V_104 ) ;
V_94 = F_51 ( V_93 -> V_84 . V_7 ) + V_93 -> V_84 . V_105
+ V_95 + sizeof( struct V_10 ) ;
if ( F_52 ( V_2 ) < V_94 || F_53 ( V_2 ) ) {
int V_106 = F_54 ( V_94 -
F_52 ( V_2 ) +
16 ) ;
V_98 = F_55 ( V_2 , F_56 ( int , V_106 , 0 ) ,
0 , V_107 ) ;
if ( F_44 ( V_98 ) )
goto V_108;
}
if ( F_37 ( V_2 , ! ! ( V_92 -> V_33 . V_104 & V_60 ) ) )
goto V_108;
V_30 = V_92 -> V_33 . V_104 & ( V_60 | V_61 ) ;
F_34 ( V_2 , V_95 , V_30 , V_25 ,
F_17 ( V_92 -> V_33 . V_59 ) , 0 ) ;
V_96 = V_33 -> V_104 & V_109 ? F_4 ( V_110 ) : 0 ;
F_57 ( V_2 -> V_111 , V_93 , V_2 , V_80 . V_32 , V_33 -> V_82 . V_83 . V_84 , V_48 ,
V_33 -> V_87 , V_33 -> V_39 , V_96 , false ) ;
return;
V_108:
F_58 ( V_93 ) ;
V_102:
F_25 ( V_2 ) ;
V_7 -> V_112 . V_113 ++ ;
}
static int F_59 ( struct V_67 * V_7 , struct V_1 * V_2 )
{
struct V_91 * V_3 = F_43 ( V_2 ) ;
struct V_78 * V_93 ;
struct V_79 V_114 ;
if ( F_45 ( V_3 ) != V_101 )
return - V_115 ;
V_93 = F_39 ( V_2 , V_7 , & V_114 , & V_3 -> V_33 ) ;
if ( F_48 ( V_93 ) )
return F_60 ( V_93 ) ;
F_58 ( V_93 ) ;
V_3 -> V_33 . V_82 . V_83 . V_85 = V_114 . V_32 ;
return 0 ;
}
static T_5 F_61 ( struct V_1 * V_2 ,
struct V_67 * V_7 )
{
struct V_14 * V_55 = F_33 ( V_7 ) ;
const struct V_10 * V_68 ;
if ( V_55 -> V_58 ) {
F_42 ( V_2 , V_7 , V_2 -> V_74 ) ;
return V_116 ;
}
if ( V_7 -> V_117 ) {
if ( F_62 ( V_2 , V_7 -> V_118 -
( V_55 -> V_119 + sizeof( struct V_10 ) ) ) )
goto V_120;
V_68 = ( const struct V_10 * ) V_2 -> V_44 ;
F_63 ( V_2 , V_55 -> V_119 + sizeof( struct V_10 ) ) ;
F_22 ( V_2 ) ;
} else {
if ( F_62 ( V_2 , V_7 -> V_118 ) )
goto V_120;
V_68 = & V_55 -> V_38 . V_11 ;
}
if ( F_37 ( V_2 , ! ! ( V_55 -> V_38 . V_69 & V_60 ) ) )
goto V_120;
F_32 ( V_2 , V_7 , V_68 , V_2 -> V_74 ) ;
return V_116 ;
V_120:
F_25 ( V_2 ) ;
V_7 -> V_112 . V_113 ++ ;
return V_116 ;
}
static T_5 F_64 ( struct V_1 * V_2 ,
struct V_67 * V_7 )
{
struct V_14 * V_55 = F_33 ( V_7 ) ;
if ( V_55 -> V_58 ) {
F_42 ( V_2 , V_7 , F_4 ( V_26 ) ) ;
return V_116 ;
}
if ( F_37 ( V_2 , ! ! ( V_55 -> V_38 . V_69 & V_60 ) ) )
goto V_120;
if ( F_62 ( V_2 , V_7 -> V_118 ) )
goto V_120;
F_32 ( V_2 , V_7 , & V_55 -> V_38 . V_11 , F_4 ( V_26 ) ) ;
return V_116 ;
V_120:
F_25 ( V_2 ) ;
V_7 -> V_112 . V_113 ++ ;
return V_116 ;
}
static int F_65 ( struct V_67 * V_7 ,
struct V_121 * V_122 , int V_123 )
{
int V_98 ;
struct V_124 V_125 ;
if ( F_66 ( & V_125 , V_122 -> V_126 . V_127 , sizeof( V_125 ) ) )
return - V_128 ;
if ( V_123 == V_129 || V_123 == V_130 ) {
if ( V_125 . V_11 . V_131 != 4 || V_125 . V_11 . V_74 != V_48 ||
V_125 . V_11 . V_36 != 5 || ( V_125 . V_11 . V_132 & F_4 ( ~ V_110 ) ) ||
( ( V_125 . V_133 | V_125 . V_69 ) & ( V_134 | V_135 ) ) )
return - V_115 ;
}
V_125 . V_133 = F_67 ( V_125 . V_133 ) ;
V_125 . V_69 = F_67 ( V_125 . V_69 ) ;
V_98 = F_68 ( V_7 , & V_125 , V_123 ) ;
if ( V_98 )
return V_98 ;
V_125 . V_133 = F_69 ( V_125 . V_133 ) ;
V_125 . V_69 = F_69 ( V_125 . V_69 ) ;
if ( F_70 ( V_122 -> V_126 . V_127 , & V_125 , sizeof( V_125 ) ) )
return - V_128 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_67 * V_7 ,
unsigned short type ,
const void * V_31 , const void * V_32 , unsigned int V_136 )
{
struct V_14 * V_15 = F_33 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_137 * V_138 ;
V_11 = (struct V_10 * ) F_72 ( V_2 , V_15 -> V_119 + sizeof( * V_11 ) ) ;
V_138 = (struct V_137 * ) ( V_11 + 1 ) ;
V_138 -> V_30 = F_69 ( V_15 -> V_38 . V_69 ) ;
V_138 -> V_74 = F_4 ( type ) ;
memcpy ( V_11 , & V_15 -> V_38 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_32 )
memcpy ( & V_11 -> V_32 , V_32 , 4 ) ;
if ( V_31 )
memcpy ( & V_11 -> V_31 , V_31 , 4 ) ;
if ( V_11 -> V_31 )
return V_15 -> V_119 + sizeof( * V_11 ) ;
return - ( V_15 -> V_119 + sizeof( * V_11 ) ) ;
}
static int F_73 ( const struct V_1 * V_2 , unsigned char * V_139 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_74 ( V_2 ) ;
memcpy ( V_139 , & V_11 -> V_32 , 4 ) ;
return 4 ;
}
static int F_75 ( struct V_67 * V_7 )
{
struct V_14 * V_15 = F_33 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) ) {
struct V_79 V_114 ;
struct V_78 * V_93 ;
V_93 = F_76 ( V_15 -> V_6 , & V_114 ,
V_15 -> V_38 . V_11 . V_31 ,
V_15 -> V_38 . V_11 . V_32 ,
V_15 -> V_38 . V_73 ,
F_40 ( V_15 -> V_38 . V_11 . V_87 ) ,
V_15 -> V_38 . V_140 ) ;
if ( F_48 ( V_93 ) )
return - V_141 ;
V_7 = V_93 -> V_84 . V_7 ;
F_58 ( V_93 ) ;
if ( ! F_77 ( V_7 ) )
return - V_141 ;
V_15 -> V_142 = V_7 -> V_29 ;
F_78 ( F_77 ( V_7 ) , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static int F_79 ( struct V_67 * V_7 )
{
struct V_14 * V_15 = F_33 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) && V_15 -> V_142 ) {
struct V_143 * V_144 ;
V_144 = F_80 ( V_15 -> V_6 , V_15 -> V_142 ) ;
if ( V_144 )
F_81 ( V_144 , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static void F_82 ( struct V_67 * V_7 )
{
V_7 -> V_145 = & V_146 ;
V_7 -> type = V_147 ;
F_83 ( V_7 , V_28 ) ;
}
static void F_84 ( struct V_67 * V_7 )
{
struct V_14 * V_55 ;
int V_148 ;
V_55 = F_33 ( V_7 ) ;
V_55 -> V_72 = F_50 ( V_55 -> V_38 . V_69 ) ;
V_55 -> V_38 . V_11 . V_74 = V_48 ;
V_55 -> V_119 = V_55 -> V_72 + V_55 -> V_149 ;
V_148 = V_55 -> V_119 + sizeof( struct V_10 ) ;
V_7 -> V_118 = V_150 + V_148 + 4 ;
V_7 -> V_151 = V_152 - V_148 - 4 ;
V_7 -> V_153 |= V_154 ;
V_7 -> V_155 |= V_154 ;
if ( ! ( V_55 -> V_38 . V_69 & V_70 ) ) {
if ( ! ( V_55 -> V_38 . V_69 & V_60 ) ||
( V_55 -> V_156 . type == V_157 ) ) {
V_7 -> V_153 |= V_158 ;
V_7 -> V_155 |= V_158 ;
}
V_7 -> V_153 |= V_159 ;
}
}
static int F_85 ( struct V_67 * V_7 )
{
struct V_14 * V_55 = F_33 ( V_7 ) ;
struct V_10 * V_11 = & V_55 -> V_38 . V_11 ;
F_84 ( V_7 ) ;
memcpy ( V_7 -> V_160 , & V_11 -> V_32 , 4 ) ;
memcpy ( V_7 -> V_161 , & V_11 -> V_31 , 4 ) ;
V_7 -> V_30 = V_162 ;
F_86 ( V_7 ) ;
V_7 -> V_163 = 4 ;
if ( V_11 -> V_31 && ! V_55 -> V_58 ) {
#ifdef F_28
if ( F_9 ( V_11 -> V_31 ) ) {
if ( ! V_11 -> V_32 )
return - V_115 ;
V_7 -> V_30 = V_164 ;
V_7 -> V_117 = & V_165 ;
}
#endif
} else if ( ! V_55 -> V_58 ) {
V_7 -> V_117 = & V_165 ;
}
return F_87 ( V_7 ) ;
}
static int T_6 F_88 ( struct V_6 * V_6 )
{
return F_89 ( V_6 , V_28 , & V_166 , NULL ) ;
}
static void T_7 F_90 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_28 ) ;
F_91 ( V_9 , & V_166 ) ;
}
static int F_92 ( struct V_167 * V_168 [] , struct V_167 * V_44 [] )
{
T_4 V_30 ;
if ( ! V_44 )
return 0 ;
V_30 = 0 ;
if ( V_44 [ V_169 ] )
V_30 |= F_93 ( V_44 [ V_169 ] ) ;
if ( V_44 [ V_170 ] )
V_30 |= F_93 ( V_44 [ V_170 ] ) ;
if ( V_30 & ( V_134 | V_135 ) )
return - V_115 ;
if ( V_44 [ V_171 ] &&
V_44 [ V_172 ] &&
F_94 ( V_44 [ V_172 ] ) != V_157 )
return - V_115 ;
return 0 ;
}
static int F_95 ( struct V_167 * V_168 [] , struct V_167 * V_44 [] )
{
T_3 V_31 ;
if ( V_168 [ V_173 ] ) {
if ( F_96 ( V_168 [ V_173 ] ) != V_174 )
return - V_115 ;
if ( ! F_97 ( F_98 ( V_168 [ V_173 ] ) ) )
return - V_141 ;
}
if ( ! V_44 )
goto V_175;
if ( V_44 [ V_176 ] ) {
memcpy ( & V_31 , F_98 ( V_44 [ V_176 ] ) , 4 ) ;
if ( ! V_31 )
return - V_115 ;
}
V_175:
return F_92 ( V_168 , V_44 ) ;
}
static int F_99 ( struct V_67 * V_7 ,
struct V_167 * V_44 [] ,
struct V_167 * V_168 [] ,
struct V_124 * V_38 )
{
struct V_14 * V_15 = F_33 ( V_7 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_11 . V_74 = V_48 ;
if ( ! V_44 )
return 0 ;
if ( V_44 [ V_177 ] )
V_38 -> V_140 = F_100 ( V_44 [ V_177 ] ) ;
if ( V_44 [ V_169 ] )
V_38 -> V_133 = F_67 ( F_93 ( V_44 [ V_169 ] ) ) ;
if ( V_44 [ V_170 ] )
V_38 -> V_69 = F_67 ( F_93 ( V_44 [ V_170 ] ) ) ;
if ( V_44 [ V_178 ] )
V_38 -> V_179 = F_101 ( V_44 [ V_178 ] ) ;
if ( V_44 [ V_180 ] )
V_38 -> V_73 = F_101 ( V_44 [ V_180 ] ) ;
if ( V_44 [ V_181 ] )
V_38 -> V_11 . V_32 = F_102 ( V_44 [ V_181 ] ) ;
if ( V_44 [ V_176 ] )
V_38 -> V_11 . V_31 = F_102 ( V_44 [ V_176 ] ) ;
if ( V_44 [ V_182 ] )
V_38 -> V_11 . V_39 = F_103 ( V_44 [ V_182 ] ) ;
if ( V_44 [ V_183 ] )
V_38 -> V_11 . V_87 = F_103 ( V_44 [ V_183 ] ) ;
if ( ! V_44 [ V_184 ] || F_103 ( V_44 [ V_184 ] ) ) {
if ( V_15 -> V_185 )
return - V_115 ;
V_38 -> V_11 . V_132 = F_4 ( V_110 ) ;
}
if ( V_44 [ V_171 ] ) {
V_15 -> V_58 = true ;
if ( V_7 -> type == V_147 )
V_7 -> type = V_57 ;
}
if ( V_44 [ V_186 ] ) {
if ( F_103 ( V_44 [ V_186 ] )
&& ( V_38 -> V_11 . V_132 & F_4 ( V_110 ) ) )
return - V_115 ;
V_15 -> V_185 = ! ! F_103 ( V_44 [ V_186 ] ) ;
}
return 0 ;
}
static bool F_104 ( struct V_167 * V_44 [] ,
struct V_187 * V_188 )
{
bool V_189 = false ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
if ( ! V_44 )
return V_189 ;
if ( V_44 [ V_172 ] ) {
V_189 = true ;
V_188 -> type = F_94 ( V_44 [ V_172 ] ) ;
}
if ( V_44 [ V_190 ] ) {
V_189 = true ;
V_188 -> V_30 = F_94 ( V_44 [ V_190 ] ) ;
}
if ( V_44 [ V_191 ] ) {
V_189 = true ;
V_188 -> V_192 = F_93 ( V_44 [ V_191 ] ) ;
}
if ( V_44 [ V_193 ] ) {
V_189 = true ;
V_188 -> V_194 = F_93 ( V_44 [ V_193 ] ) ;
}
return V_189 ;
}
static int F_105 ( struct V_67 * V_7 )
{
F_84 ( V_7 ) ;
V_7 -> V_195 |= V_196 ;
return F_87 ( V_7 ) ;
}
static void F_106 ( struct V_67 * V_7 )
{
F_107 ( V_7 ) ;
V_7 -> V_145 = & V_197 ;
V_7 -> V_195 &= ~ V_198 ;
V_7 -> V_195 |= V_196 ;
F_83 ( V_7 , V_27 ) ;
}
static int F_108 ( struct V_6 * V_199 , struct V_67 * V_7 ,
struct V_167 * V_168 [] , struct V_167 * V_44 [] )
{
struct V_124 V_125 ;
struct V_187 V_188 ;
int V_98 ;
if ( F_104 ( V_44 , & V_188 ) ) {
struct V_14 * V_15 = F_33 ( V_7 ) ;
V_98 = F_109 ( V_15 , & V_188 ) ;
if ( V_98 < 0 )
return V_98 ;
}
V_98 = F_99 ( V_7 , V_44 , V_168 , & V_125 ) ;
if ( V_98 < 0 )
return V_98 ;
return F_110 ( V_7 , V_168 , & V_125 ) ;
}
static int F_111 ( struct V_67 * V_7 , struct V_167 * V_168 [] ,
struct V_167 * V_44 [] )
{
struct V_124 V_125 ;
struct V_187 V_188 ;
int V_98 ;
if ( F_104 ( V_44 , & V_188 ) ) {
struct V_14 * V_15 = F_33 ( V_7 ) ;
V_98 = F_109 ( V_15 , & V_188 ) ;
if ( V_98 < 0 )
return V_98 ;
}
V_98 = F_99 ( V_7 , V_44 , V_168 , & V_125 ) ;
if ( V_98 < 0 )
return V_98 ;
return F_112 ( V_7 , V_168 , & V_125 ) ;
}
static T_8 F_113 ( const struct V_67 * V_7 )
{
return
F_114 ( 4 ) +
F_114 ( 2 ) +
F_114 ( 2 ) +
F_114 ( 4 ) +
F_114 ( 4 ) +
F_114 ( 4 ) +
F_114 ( 4 ) +
F_114 ( 1 ) +
F_114 ( 1 ) +
F_114 ( 1 ) +
F_114 ( 2 ) +
F_114 ( 2 ) +
F_114 ( 2 ) +
F_114 ( 2 ) +
F_114 ( 0 ) +
F_114 ( 1 ) +
0 ;
}
static int F_115 ( struct V_1 * V_2 , const struct V_67 * V_7 )
{
struct V_14 * V_15 = F_33 ( V_7 ) ;
struct V_124 * V_125 = & V_15 -> V_38 ;
if ( F_116 ( V_2 , V_177 , V_125 -> V_140 ) ||
F_117 ( V_2 , V_169 ,
F_69 ( V_125 -> V_133 ) ) ||
F_117 ( V_2 , V_170 ,
F_69 ( V_125 -> V_69 ) ) ||
F_118 ( V_2 , V_178 , V_125 -> V_179 ) ||
F_118 ( V_2 , V_180 , V_125 -> V_73 ) ||
F_119 ( V_2 , V_181 , V_125 -> V_11 . V_32 ) ||
F_119 ( V_2 , V_176 , V_125 -> V_11 . V_31 ) ||
F_120 ( V_2 , V_182 , V_125 -> V_11 . V_39 ) ||
F_120 ( V_2 , V_183 , V_125 -> V_11 . V_87 ) ||
F_120 ( V_2 , V_184 ,
! ! ( V_125 -> V_11 . V_132 & F_4 ( V_110 ) ) ) )
goto V_200;
if ( F_121 ( V_2 , V_172 ,
V_15 -> V_156 . type ) ||
F_117 ( V_2 , V_191 ,
V_15 -> V_156 . V_192 ) ||
F_117 ( V_2 , V_193 ,
V_15 -> V_156 . V_194 ) ||
F_121 ( V_2 , V_190 ,
V_15 -> V_156 . V_30 ) )
goto V_200;
if ( F_120 ( V_2 , V_186 , V_15 -> V_185 ) )
goto V_200;
if ( V_15 -> V_58 ) {
if ( F_122 ( V_2 , V_171 ) )
goto V_200;
}
return 0 ;
V_200:
return - V_201 ;
}
struct V_67 * F_123 ( struct V_6 * V_6 , const char * V_202 ,
T_9 V_203 )
{
struct V_167 * V_168 [ V_204 + 1 ] ;
struct V_67 * V_7 ;
F_124 ( V_205 ) ;
struct V_14 * V_15 ;
int V_98 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_7 = F_125 ( V_6 , V_202 , V_203 ,
& V_206 , V_168 ) ;
if ( F_48 ( V_7 ) )
return V_7 ;
V_15 = F_33 ( V_7 ) ;
V_15 -> V_58 = true ;
V_98 = F_108 ( V_6 , V_7 , V_168 , NULL ) ;
if ( V_98 < 0 ) {
F_126 ( V_7 ) ;
return F_127 ( V_98 ) ;
}
V_98 = F_128 ( V_7 , V_207 , false ) ;
if ( V_98 )
goto V_175;
V_98 = F_129 ( V_7 , NULL ) ;
if ( V_98 < 0 )
goto V_175;
return V_7 ;
V_175:
F_130 ( V_7 , & V_205 ) ;
F_131 ( & V_205 ) ;
return F_127 ( V_98 ) ;
}
static int T_6 F_132 ( struct V_6 * V_6 )
{
return F_89 ( V_6 , V_27 , & V_206 , L_1 ) ;
}
static void T_7 F_133 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_27 ) ;
F_91 ( V_9 , & V_206 ) ;
}
static int T_10 F_134 ( void )
{
int V_98 ;
F_135 ( L_2 ) ;
V_98 = F_136 ( & V_208 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_136 ( & V_209 ) ;
if ( V_98 < 0 )
goto V_210;
V_98 = F_137 ( & V_211 , V_212 ) ;
if ( V_98 < 0 ) {
F_135 ( L_3 , V_213 ) ;
goto V_214;
}
V_98 = F_138 ( & V_166 ) ;
if ( V_98 < 0 )
goto V_215;
V_98 = F_138 ( & V_206 ) ;
if ( V_98 < 0 )
goto V_216;
return 0 ;
V_216:
F_139 ( & V_166 ) ;
V_215:
F_140 ( & V_211 , V_212 ) ;
V_214:
F_141 ( & V_209 ) ;
V_210:
F_141 ( & V_208 ) ;
return V_98 ;
}
static void T_11 F_142 ( void )
{
F_139 ( & V_206 ) ;
F_139 ( & V_166 ) ;
F_140 ( & V_211 , V_212 ) ;
F_141 ( & V_209 ) ;
F_141 ( & V_208 ) ;
}
