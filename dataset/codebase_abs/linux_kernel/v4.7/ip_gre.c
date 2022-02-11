static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
struct V_13 * V_14 ;
switch ( type ) {
default:
case V_15 :
return;
case V_16 :
switch ( V_12 ) {
case V_17 :
case V_18 :
return;
default:
break;
}
break;
case V_19 :
if ( V_12 != V_20 )
return;
break;
case V_21 :
break;
}
if ( V_5 -> V_22 == F_4 ( V_23 ) )
V_9 = F_5 ( V_6 , V_24 ) ;
else
V_9 = F_5 ( V_6 , V_25 ) ;
V_11 = ( const struct V_10 * ) ( F_3 ( V_2 ) + 1 ) ;
V_14 = F_6 ( V_9 , V_2 -> V_7 -> V_26 , V_5 -> V_27 ,
V_11 -> V_28 , V_11 -> V_29 , V_5 -> V_30 ) ;
if ( ! V_14 )
return;
if ( V_14 -> V_31 . V_11 . V_28 == 0 ||
F_7 ( V_14 -> V_31 . V_11 . V_28 ) )
return;
if ( V_14 -> V_31 . V_11 . V_32 == 0 && type == V_19 )
return;
if ( F_8 ( V_33 , V_14 -> V_34 + V_35 ) )
V_14 -> V_36 ++ ;
else
V_14 -> V_36 = 1 ;
V_14 -> V_34 = V_33 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_37 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
struct V_4 V_5 ;
bool V_38 = false ;
if ( F_10 ( V_2 , & V_5 , & V_38 , F_4 ( V_39 ) ,
V_11 -> V_40 * 4 ) < 0 ) {
if ( ! V_38 )
return;
}
if ( type == V_16 && V_12 == V_41 ) {
F_11 ( V_2 , F_2 ( V_2 -> V_7 ) , V_3 ,
V_2 -> V_7 -> V_26 , 0 , V_42 , 0 ) ;
return;
}
if ( type == V_21 ) {
F_12 ( V_2 , F_2 ( V_2 -> V_7 ) , V_2 -> V_7 -> V_26 , 0 ,
V_42 , 0 ) ;
return;
}
F_1 ( V_2 , V_3 , & V_5 ) ;
}
static T_2 F_13 ( T_3 V_30 )
{
#ifdef F_14
return ( V_43 T_2 ) ( ( V_43 T_1 ) V_30 ) ;
#else
return ( V_43 T_2 ) ( ( V_43 V_44 ) V_30 << 32 ) ;
#endif
}
static T_3 F_15 ( T_2 V_45 )
{
#ifdef F_14
return ( V_43 T_3 ) V_45 ;
#else
return ( V_43 T_3 ) ( ( V_43 V_44 ) V_45 >> 32 ) ;
#endif
}
static int F_16 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
struct V_8 * V_9 , int V_46 , bool V_47 )
{
struct V_48 * V_49 = NULL ;
const struct V_10 * V_11 ;
struct V_13 * V_50 ;
V_11 = F_17 ( V_2 ) ;
V_50 = F_6 ( V_9 , V_2 -> V_7 -> V_26 , V_5 -> V_27 ,
V_11 -> V_29 , V_11 -> V_28 , V_5 -> V_30 ) ;
if ( V_50 ) {
if ( F_18 ( V_2 , V_46 , V_5 -> V_22 ,
V_47 , false ) < 0 )
goto V_51;
if ( V_50 -> V_7 -> type != V_52 )
F_19 ( V_2 ) ;
else
F_20 ( V_2 ) ;
if ( V_50 -> V_53 ) {
T_4 V_27 ;
T_2 V_54 ;
V_27 = V_5 -> V_27 & ( V_55 | V_56 ) ;
V_54 = F_13 ( V_5 -> V_30 ) ;
V_49 = F_21 ( V_2 , V_27 , V_54 , 0 ) ;
if ( ! V_49 )
return V_57 ;
}
F_22 ( V_50 , V_2 , V_5 , V_49 , V_58 ) ;
return V_59 ;
}
return V_60 ;
V_51:
F_23 ( V_2 ) ;
return V_59 ;
}
static int F_24 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
int V_46 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_61 ;
if ( V_5 -> V_22 == F_4 ( V_23 ) )
V_9 = F_5 ( V_6 , V_24 ) ;
else
V_9 = F_5 ( V_6 , V_25 ) ;
V_61 = F_16 ( V_2 , V_5 , V_9 , V_46 , false ) ;
if ( V_61 == V_60 && V_5 -> V_22 == F_4 ( V_23 ) ) {
V_9 = F_5 ( V_6 , V_25 ) ;
V_61 = F_16 ( V_2 , V_5 , V_9 , V_46 , true ) ;
}
return V_61 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
bool V_38 = false ;
int V_46 ;
#ifdef F_26
if ( F_7 ( F_17 ( V_2 ) -> V_28 ) ) {
if ( F_27 ( F_28 ( V_2 ) ) )
goto V_51;
}
#endif
V_46 = F_10 ( V_2 , & V_5 , & V_38 , F_4 ( V_39 ) , 0 ) ;
if ( V_46 < 0 )
goto V_51;
if ( F_24 ( V_2 , & V_5 , V_46 ) == V_59 )
return 0 ;
F_29 ( V_2 , V_16 , V_18 , 0 ) ;
V_51:
F_23 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_62 * V_7 ,
const struct V_10 * V_63 ,
T_4 V_22 )
{
struct V_13 * V_50 = F_31 ( V_7 ) ;
if ( V_50 -> V_31 . V_64 & V_65 )
V_50 -> V_66 ++ ;
F_32 ( V_2 , V_50 -> V_67 ,
V_50 -> V_31 . V_64 , V_22 , V_50 -> V_31 . V_68 ,
F_33 ( V_50 -> V_66 ) ) ;
F_34 ( V_2 , V_22 ) ;
F_35 ( V_2 , V_7 , V_63 , V_63 -> V_69 ) ;
}
static int F_36 ( struct V_1 * V_2 , bool V_70 )
{
return F_37 ( V_2 , V_70 ? V_71 : V_72 ) ;
}
static struct V_73 * F_38 ( struct V_1 * V_2 ,
struct V_62 * V_7 ,
struct V_74 * V_75 ,
const struct V_76 * V_30 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 = V_30 -> V_77 . V_78 . V_79 ;
V_75 -> V_29 = V_30 -> V_77 . V_78 . V_80 ;
V_75 -> V_81 = F_39 ( V_30 -> V_82 ) ;
V_75 -> V_83 = V_2 -> V_84 ;
V_75 -> V_85 = V_42 ;
return F_40 ( V_6 , V_75 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_62 * V_7 ,
T_4 V_22 )
{
struct V_86 * V_87 ;
const struct V_76 * V_30 ;
struct V_73 * V_88 = NULL ;
struct V_74 V_75 ;
int V_89 ;
int V_90 ;
T_4 V_91 , V_27 ;
bool V_92 ;
int V_93 ;
V_87 = F_42 ( V_2 ) ;
if ( F_43 ( ! V_87 || ! ( V_87 -> V_94 & V_95 ) ||
F_44 ( V_87 ) != V_96 ) )
goto V_97;
V_30 = & V_87 -> V_30 ;
V_92 = F_45 ( V_2 , V_87 ) ;
if ( V_92 )
V_88 = F_46 ( & V_87 -> V_98 , & V_75 . V_29 ) ;
if ( ! V_88 ) {
V_88 = F_38 ( V_2 , V_7 , & V_75 , V_30 ) ;
if ( F_47 ( V_88 ) )
goto V_97;
if ( V_92 )
F_48 ( & V_87 -> V_98 , & V_88 -> V_79 ,
V_75 . V_29 ) ;
}
V_90 = F_49 ( V_30 -> V_99 ) ;
V_89 = F_50 ( V_88 -> V_79 . V_7 ) + V_88 -> V_79 . V_100
+ V_90 + sizeof( struct V_10 ) ;
if ( F_51 ( V_2 ) < V_89 || F_52 ( V_2 ) ) {
int V_101 = F_53 ( V_89 -
F_51 ( V_2 ) +
16 ) ;
V_93 = F_54 ( V_2 , F_55 ( int , V_101 , 0 ) ,
0 , V_102 ) ;
if ( F_43 ( V_93 ) )
goto V_103;
}
if ( F_36 ( V_2 , ! ! ( V_87 -> V_30 . V_99 & V_55 ) ) )
goto V_103;
V_27 = V_87 -> V_30 . V_99 & ( V_55 | V_56 ) ;
F_32 ( V_2 , V_90 , V_27 , V_22 ,
F_15 ( V_87 -> V_30 . V_54 ) , 0 ) ;
V_91 = V_30 -> V_99 & V_104 ? F_4 ( V_105 ) : 0 ;
F_56 ( V_2 -> V_106 , V_88 , V_2 , V_75 . V_29 , V_30 -> V_77 . V_78 . V_79 , V_42 ,
V_30 -> V_82 , V_30 -> V_32 , V_91 , false ) ;
return;
V_103:
F_57 ( V_88 ) ;
V_97:
F_23 ( V_2 ) ;
V_7 -> V_107 . V_108 ++ ;
}
static int F_58 ( struct V_62 * V_7 , struct V_1 * V_2 )
{
struct V_86 * V_3 = F_42 ( V_2 ) ;
struct V_73 * V_88 ;
struct V_74 V_109 ;
if ( F_44 ( V_3 ) != V_96 )
return - V_110 ;
V_88 = F_38 ( V_2 , V_7 , & V_109 , & V_3 -> V_30 ) ;
if ( F_47 ( V_88 ) )
return F_59 ( V_88 ) ;
F_57 ( V_88 ) ;
V_3 -> V_30 . V_77 . V_78 . V_80 = V_109 . V_29 ;
return 0 ;
}
static T_5 F_60 ( struct V_1 * V_2 ,
struct V_62 * V_7 )
{
struct V_13 * V_50 = F_31 ( V_7 ) ;
const struct V_10 * V_63 ;
if ( V_50 -> V_53 ) {
F_41 ( V_2 , V_7 , V_2 -> V_69 ) ;
return V_111 ;
}
if ( V_7 -> V_112 ) {
if ( F_61 ( V_2 , V_7 -> V_113 -
( V_50 -> V_114 + sizeof( struct V_10 ) ) ) )
goto V_115;
V_63 = ( const struct V_10 * ) V_2 -> V_37 ;
F_62 ( V_2 , V_50 -> V_114 + sizeof( struct V_10 ) ) ;
F_20 ( V_2 ) ;
} else {
if ( F_61 ( V_2 , V_7 -> V_113 ) )
goto V_115;
V_63 = & V_50 -> V_31 . V_11 ;
}
if ( F_36 ( V_2 , ! ! ( V_50 -> V_31 . V_64 & V_55 ) ) )
goto V_115;
F_30 ( V_2 , V_7 , V_63 , V_2 -> V_69 ) ;
return V_111 ;
V_115:
F_23 ( V_2 ) ;
V_7 -> V_107 . V_108 ++ ;
return V_111 ;
}
static T_5 F_63 ( struct V_1 * V_2 ,
struct V_62 * V_7 )
{
struct V_13 * V_50 = F_31 ( V_7 ) ;
if ( V_50 -> V_53 ) {
F_41 ( V_2 , V_7 , F_4 ( V_23 ) ) ;
return V_111 ;
}
if ( F_36 ( V_2 , ! ! ( V_50 -> V_31 . V_64 & V_55 ) ) )
goto V_115;
if ( F_61 ( V_2 , V_7 -> V_113 ) )
goto V_115;
F_30 ( V_2 , V_7 , & V_50 -> V_31 . V_11 , F_4 ( V_23 ) ) ;
return V_111 ;
V_115:
F_23 ( V_2 ) ;
V_7 -> V_107 . V_108 ++ ;
return V_111 ;
}
static int F_64 ( struct V_62 * V_7 ,
struct V_116 * V_117 , int V_118 )
{
int V_93 ;
struct V_119 V_120 ;
if ( F_65 ( & V_120 , V_117 -> V_121 . V_122 , sizeof( V_120 ) ) )
return - V_123 ;
if ( V_118 == V_124 || V_118 == V_125 ) {
if ( V_120 . V_11 . V_126 != 4 || V_120 . V_11 . V_69 != V_42 ||
V_120 . V_11 . V_40 != 5 || ( V_120 . V_11 . V_127 & F_4 ( ~ V_105 ) ) ||
( ( V_120 . V_128 | V_120 . V_64 ) & ( V_129 | V_130 ) ) )
return - V_110 ;
}
V_120 . V_128 = F_66 ( V_120 . V_128 ) ;
V_120 . V_64 = F_66 ( V_120 . V_64 ) ;
V_93 = F_67 ( V_7 , & V_120 , V_118 ) ;
if ( V_93 )
return V_93 ;
V_120 . V_128 = F_68 ( V_120 . V_128 ) ;
V_120 . V_64 = F_68 ( V_120 . V_64 ) ;
if ( F_69 ( V_117 -> V_121 . V_122 , & V_120 , sizeof( V_120 ) ) )
return - V_123 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_62 * V_7 ,
unsigned short type ,
const void * V_28 , const void * V_29 , unsigned int V_131 )
{
struct V_13 * V_14 = F_31 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_132 * V_133 ;
V_11 = (struct V_10 * ) F_71 ( V_2 , V_14 -> V_114 + sizeof( * V_11 ) ) ;
V_133 = (struct V_132 * ) ( V_11 + 1 ) ;
V_133 -> V_27 = F_68 ( V_14 -> V_31 . V_64 ) ;
V_133 -> V_69 = F_4 ( type ) ;
memcpy ( V_11 , & V_14 -> V_31 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_29 )
memcpy ( & V_11 -> V_29 , V_29 , 4 ) ;
if ( V_28 )
memcpy ( & V_11 -> V_28 , V_28 , 4 ) ;
if ( V_11 -> V_28 )
return V_14 -> V_114 + sizeof( * V_11 ) ;
return - ( V_14 -> V_114 + sizeof( * V_11 ) ) ;
}
static int F_72 ( const struct V_1 * V_2 , unsigned char * V_134 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_73 ( V_2 ) ;
memcpy ( V_134 , & V_11 -> V_29 , 4 ) ;
return 4 ;
}
static int F_74 ( struct V_62 * V_7 )
{
struct V_13 * V_14 = F_31 ( V_7 ) ;
if ( F_7 ( V_14 -> V_31 . V_11 . V_28 ) ) {
struct V_74 V_109 ;
struct V_73 * V_88 ;
V_88 = F_75 ( V_14 -> V_6 , & V_109 ,
V_14 -> V_31 . V_11 . V_28 ,
V_14 -> V_31 . V_11 . V_29 ,
V_14 -> V_31 . V_68 ,
F_39 ( V_14 -> V_31 . V_11 . V_82 ) ,
V_14 -> V_31 . V_135 ) ;
if ( F_47 ( V_88 ) )
return - V_136 ;
V_7 = V_88 -> V_79 . V_7 ;
F_57 ( V_88 ) ;
if ( ! F_76 ( V_7 ) )
return - V_136 ;
V_14 -> V_137 = V_7 -> V_26 ;
F_77 ( F_76 ( V_7 ) , V_14 -> V_31 . V_11 . V_28 ) ;
}
return 0 ;
}
static int F_78 ( struct V_62 * V_7 )
{
struct V_13 * V_14 = F_31 ( V_7 ) ;
if ( F_7 ( V_14 -> V_31 . V_11 . V_28 ) && V_14 -> V_137 ) {
struct V_138 * V_139 ;
V_139 = F_79 ( V_14 -> V_6 , V_14 -> V_137 ) ;
if ( V_139 )
F_80 ( V_139 , V_14 -> V_31 . V_11 . V_28 ) ;
}
return 0 ;
}
static void F_81 ( struct V_62 * V_7 )
{
V_7 -> V_140 = & V_141 ;
V_7 -> type = V_142 ;
F_82 ( V_7 , V_25 ) ;
}
static void F_83 ( struct V_62 * V_7 )
{
struct V_13 * V_50 ;
int V_143 ;
V_50 = F_31 ( V_7 ) ;
V_50 -> V_67 = F_49 ( V_50 -> V_31 . V_64 ) ;
V_50 -> V_31 . V_11 . V_69 = V_42 ;
V_50 -> V_114 = V_50 -> V_67 + V_50 -> V_144 ;
V_143 = V_50 -> V_114 + sizeof( struct V_10 ) ;
V_7 -> V_113 = V_145 + V_143 + 4 ;
V_7 -> V_146 = V_147 - V_143 - 4 ;
V_7 -> V_148 |= V_149 ;
V_7 -> V_150 |= V_149 ;
if ( ! ( V_50 -> V_31 . V_64 & V_65 ) ) {
if ( ! ( V_50 -> V_31 . V_64 & V_55 ) ||
( V_50 -> V_151 . type == V_152 ) ) {
V_7 -> V_148 |= V_153 ;
V_7 -> V_150 |= V_153 ;
}
V_7 -> V_148 |= V_154 ;
}
}
static int F_84 ( struct V_62 * V_7 )
{
struct V_13 * V_50 = F_31 ( V_7 ) ;
struct V_10 * V_11 = & V_50 -> V_31 . V_11 ;
F_83 ( V_7 ) ;
memcpy ( V_7 -> V_155 , & V_11 -> V_29 , 4 ) ;
memcpy ( V_7 -> V_156 , & V_11 -> V_28 , 4 ) ;
V_7 -> V_27 = V_157 ;
F_85 ( V_7 ) ;
V_7 -> V_158 = 4 ;
if ( V_11 -> V_28 && ! V_50 -> V_53 ) {
#ifdef F_26
if ( F_7 ( V_11 -> V_28 ) ) {
if ( ! V_11 -> V_29 )
return - V_110 ;
V_7 -> V_27 = V_159 ;
V_7 -> V_112 = & V_160 ;
}
#endif
} else if ( ! V_50 -> V_53 ) {
V_7 -> V_112 = & V_160 ;
}
return F_86 ( V_7 ) ;
}
static int T_6 F_87 ( struct V_6 * V_6 )
{
return F_88 ( V_6 , V_25 , & V_161 , NULL ) ;
}
static void T_7 F_89 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_25 ) ;
F_90 ( V_9 , & V_161 ) ;
}
static int F_91 ( struct V_162 * V_163 [] , struct V_162 * V_37 [] )
{
T_4 V_27 ;
if ( ! V_37 )
return 0 ;
V_27 = 0 ;
if ( V_37 [ V_164 ] )
V_27 |= F_92 ( V_37 [ V_164 ] ) ;
if ( V_37 [ V_165 ] )
V_27 |= F_92 ( V_37 [ V_165 ] ) ;
if ( V_27 & ( V_129 | V_130 ) )
return - V_110 ;
if ( V_37 [ V_166 ] &&
V_37 [ V_167 ] &&
F_93 ( V_37 [ V_167 ] ) != V_152 )
return - V_110 ;
return 0 ;
}
static int F_94 ( struct V_162 * V_163 [] , struct V_162 * V_37 [] )
{
T_3 V_28 ;
if ( V_163 [ V_168 ] ) {
if ( F_95 ( V_163 [ V_168 ] ) != V_169 )
return - V_110 ;
if ( ! F_96 ( F_97 ( V_163 [ V_168 ] ) ) )
return - V_136 ;
}
if ( ! V_37 )
goto V_170;
if ( V_37 [ V_171 ] ) {
memcpy ( & V_28 , F_97 ( V_37 [ V_171 ] ) , 4 ) ;
if ( ! V_28 )
return - V_110 ;
}
V_170:
return F_91 ( V_163 , V_37 ) ;
}
static void F_98 ( struct V_62 * V_7 ,
struct V_162 * V_37 [] ,
struct V_162 * V_163 [] ,
struct V_119 * V_31 )
{
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_11 . V_69 = V_42 ;
if ( ! V_37 )
return;
if ( V_37 [ V_172 ] )
V_31 -> V_135 = F_99 ( V_37 [ V_172 ] ) ;
if ( V_37 [ V_164 ] )
V_31 -> V_128 = F_66 ( F_92 ( V_37 [ V_164 ] ) ) ;
if ( V_37 [ V_165 ] )
V_31 -> V_64 = F_66 ( F_92 ( V_37 [ V_165 ] ) ) ;
if ( V_37 [ V_173 ] )
V_31 -> V_174 = F_100 ( V_37 [ V_173 ] ) ;
if ( V_37 [ V_175 ] )
V_31 -> V_68 = F_100 ( V_37 [ V_175 ] ) ;
if ( V_37 [ V_176 ] )
V_31 -> V_11 . V_29 = F_101 ( V_37 [ V_176 ] ) ;
if ( V_37 [ V_171 ] )
V_31 -> V_11 . V_28 = F_101 ( V_37 [ V_171 ] ) ;
if ( V_37 [ V_177 ] )
V_31 -> V_11 . V_32 = F_102 ( V_37 [ V_177 ] ) ;
if ( V_37 [ V_178 ] )
V_31 -> V_11 . V_82 = F_102 ( V_37 [ V_178 ] ) ;
if ( ! V_37 [ V_179 ] || F_102 ( V_37 [ V_179 ] ) )
V_31 -> V_11 . V_127 = F_4 ( V_105 ) ;
if ( V_37 [ V_166 ] ) {
struct V_13 * V_14 = F_31 ( V_7 ) ;
V_14 -> V_53 = true ;
if ( V_7 -> type == V_142 )
V_7 -> type = V_52 ;
}
}
static bool F_103 ( struct V_162 * V_37 [] ,
struct V_180 * V_181 )
{
bool V_182 = false ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
if ( ! V_37 )
return V_182 ;
if ( V_37 [ V_167 ] ) {
V_182 = true ;
V_181 -> type = F_93 ( V_37 [ V_167 ] ) ;
}
if ( V_37 [ V_183 ] ) {
V_182 = true ;
V_181 -> V_27 = F_93 ( V_37 [ V_183 ] ) ;
}
if ( V_37 [ V_184 ] ) {
V_182 = true ;
V_181 -> V_185 = F_92 ( V_37 [ V_184 ] ) ;
}
if ( V_37 [ V_186 ] ) {
V_182 = true ;
V_181 -> V_187 = F_92 ( V_37 [ V_186 ] ) ;
}
return V_182 ;
}
static int F_104 ( struct V_62 * V_7 )
{
F_83 ( V_7 ) ;
V_7 -> V_188 |= V_189 ;
return F_86 ( V_7 ) ;
}
static void F_105 ( struct V_62 * V_7 )
{
F_106 ( V_7 ) ;
V_7 -> V_140 = & V_190 ;
V_7 -> V_188 &= ~ V_191 ;
V_7 -> V_188 |= V_189 ;
F_82 ( V_7 , V_24 ) ;
}
static int F_107 ( struct V_6 * V_192 , struct V_62 * V_7 ,
struct V_162 * V_163 [] , struct V_162 * V_37 [] )
{
struct V_119 V_120 ;
struct V_180 V_181 ;
if ( F_103 ( V_37 , & V_181 ) ) {
struct V_13 * V_14 = F_31 ( V_7 ) ;
int V_93 = F_108 ( V_14 , & V_181 ) ;
if ( V_93 < 0 )
return V_93 ;
}
F_98 ( V_7 , V_37 , V_163 , & V_120 ) ;
return F_109 ( V_7 , V_163 , & V_120 ) ;
}
static int F_110 ( struct V_62 * V_7 , struct V_162 * V_163 [] ,
struct V_162 * V_37 [] )
{
struct V_119 V_120 ;
struct V_180 V_181 ;
if ( F_103 ( V_37 , & V_181 ) ) {
struct V_13 * V_14 = F_31 ( V_7 ) ;
int V_93 = F_108 ( V_14 , & V_181 ) ;
if ( V_93 < 0 )
return V_93 ;
}
F_98 ( V_7 , V_37 , V_163 , & V_120 ) ;
return F_111 ( V_7 , V_163 , & V_120 ) ;
}
static T_8 F_112 ( const struct V_62 * V_7 )
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
0 ;
}
static int F_114 ( struct V_1 * V_2 , const struct V_62 * V_7 )
{
struct V_13 * V_14 = F_31 ( V_7 ) ;
struct V_119 * V_120 = & V_14 -> V_31 ;
if ( F_115 ( V_2 , V_172 , V_120 -> V_135 ) ||
F_116 ( V_2 , V_164 ,
F_68 ( V_120 -> V_128 ) ) ||
F_116 ( V_2 , V_165 ,
F_68 ( V_120 -> V_64 ) ) ||
F_117 ( V_2 , V_173 , V_120 -> V_174 ) ||
F_117 ( V_2 , V_175 , V_120 -> V_68 ) ||
F_118 ( V_2 , V_176 , V_120 -> V_11 . V_29 ) ||
F_118 ( V_2 , V_171 , V_120 -> V_11 . V_28 ) ||
F_119 ( V_2 , V_177 , V_120 -> V_11 . V_32 ) ||
F_119 ( V_2 , V_178 , V_120 -> V_11 . V_82 ) ||
F_119 ( V_2 , V_179 ,
! ! ( V_120 -> V_11 . V_127 & F_4 ( V_105 ) ) ) )
goto V_193;
if ( F_120 ( V_2 , V_167 ,
V_14 -> V_151 . type ) ||
F_116 ( V_2 , V_184 ,
V_14 -> V_151 . V_185 ) ||
F_116 ( V_2 , V_186 ,
V_14 -> V_151 . V_187 ) ||
F_120 ( V_2 , V_183 ,
V_14 -> V_151 . V_27 ) )
goto V_193;
if ( V_14 -> V_53 ) {
if ( F_121 ( V_2 , V_166 ) )
goto V_193;
}
return 0 ;
V_193:
return - V_194 ;
}
struct V_62 * F_122 ( struct V_6 * V_6 , const char * V_195 ,
T_9 V_196 )
{
struct V_162 * V_163 [ V_197 + 1 ] ;
struct V_62 * V_7 ;
F_123 ( V_198 ) ;
struct V_13 * V_14 ;
int V_93 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_7 = F_124 ( V_6 , V_195 , V_196 ,
& V_199 , V_163 ) ;
if ( F_47 ( V_7 ) )
return V_7 ;
V_14 = F_31 ( V_7 ) ;
V_14 -> V_53 = true ;
V_93 = F_107 ( V_6 , V_7 , V_163 , NULL ) ;
if ( V_93 < 0 ) {
F_125 ( V_7 ) ;
return F_126 ( V_93 ) ;
}
V_93 = F_127 ( V_7 , V_200 , false ) ;
if ( V_93 )
goto V_170;
V_93 = F_128 ( V_7 , NULL ) ;
if ( V_93 < 0 )
goto V_170;
return V_7 ;
V_170:
F_129 ( V_7 , & V_198 ) ;
F_130 ( & V_198 ) ;
return F_126 ( V_93 ) ;
}
static int T_6 F_131 ( struct V_6 * V_6 )
{
return F_88 ( V_6 , V_24 , & V_199 , L_1 ) ;
}
static void T_7 F_132 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_24 ) ;
F_90 ( V_9 , & V_199 ) ;
}
static int T_10 F_133 ( void )
{
int V_93 ;
F_134 ( L_2 ) ;
V_93 = F_135 ( & V_201 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_135 ( & V_202 ) ;
if ( V_93 < 0 )
goto V_203;
V_93 = F_136 ( & V_204 , V_205 ) ;
if ( V_93 < 0 ) {
F_134 ( L_3 , V_206 ) ;
goto V_207;
}
V_93 = F_137 ( & V_161 ) ;
if ( V_93 < 0 )
goto V_208;
V_93 = F_137 ( & V_199 ) ;
if ( V_93 < 0 )
goto V_209;
return 0 ;
V_209:
F_138 ( & V_161 ) ;
V_208:
F_139 ( & V_204 , V_205 ) ;
V_207:
F_140 ( & V_202 ) ;
V_203:
F_140 ( & V_201 ) ;
return V_93 ;
}
static void T_11 F_141 ( void )
{
F_138 ( & V_199 ) ;
F_138 ( & V_161 ) ;
F_139 ( & V_204 , V_205 ) ;
F_140 ( & V_202 ) ;
F_140 ( & V_201 ) ;
}
