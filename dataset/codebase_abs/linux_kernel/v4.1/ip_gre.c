static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
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
return V_16 ;
case V_17 :
switch ( V_12 ) {
case V_18 :
case V_19 :
return V_16 ;
default:
break;
}
break;
case V_20 :
if ( V_12 != V_21 )
return V_16 ;
break;
case V_22 :
break;
}
if ( V_5 -> V_23 == F_4 ( V_24 ) )
V_9 = F_5 ( V_6 , V_25 ) ;
else
V_9 = F_5 ( V_6 , V_26 ) ;
V_11 = ( const struct V_10 * ) ( F_3 ( V_2 ) + 1 ) ;
V_14 = F_6 ( V_9 , V_2 -> V_7 -> V_27 , V_5 -> V_28 ,
V_11 -> V_29 , V_11 -> V_30 , V_5 -> V_31 ) ;
if ( ! V_14 )
return V_32 ;
if ( V_14 -> V_33 . V_11 . V_29 == 0 ||
F_7 ( V_14 -> V_33 . V_11 . V_29 ) )
return V_16 ;
if ( V_14 -> V_33 . V_11 . V_34 == 0 && type == V_20 )
return V_16 ;
if ( F_8 ( V_35 , V_14 -> V_36 + V_37 ) )
V_14 -> V_38 ++ ;
else
V_14 -> V_38 = 1 ;
V_14 -> V_36 = V_35 ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
struct V_13 * V_39 ;
if ( V_5 -> V_23 == F_4 ( V_24 ) )
V_9 = F_5 ( V_6 , V_25 ) ;
else
V_9 = F_5 ( V_6 , V_26 ) ;
V_11 = F_10 ( V_2 ) ;
V_39 = F_6 ( V_9 , V_2 -> V_7 -> V_27 , V_5 -> V_28 ,
V_11 -> V_30 , V_11 -> V_29 , V_5 -> V_31 ) ;
if ( V_39 ) {
F_11 ( V_2 ) ;
F_12 ( V_39 , V_2 , V_5 , V_40 ) ;
return V_16 ;
}
return V_32 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_41 * V_7 ,
const struct V_10 * V_42 ,
T_2 V_23 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
struct V_4 V_5 ;
V_5 . V_28 = V_39 -> V_33 . V_43 ;
V_5 . V_23 = V_23 ;
V_5 . V_31 = V_39 -> V_33 . V_44 ;
if ( V_39 -> V_33 . V_43 & V_45 )
V_39 -> V_46 ++ ;
V_5 . V_47 = F_15 ( V_39 -> V_46 ) ;
F_16 ( V_2 , & V_5 , V_39 -> V_48 ) ;
F_17 ( V_2 , V_5 . V_23 ) ;
F_18 ( V_2 , V_7 , V_42 , V_42 -> V_49 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
const struct V_10 * V_42 ;
if ( V_7 -> V_50 ) {
if ( F_20 ( V_2 , V_7 -> V_51 -
( V_39 -> V_52 + sizeof( struct V_10 ) ) ) )
goto V_53;
V_42 = ( const struct V_10 * ) V_2 -> V_54 ;
F_21 ( V_2 , V_39 -> V_52 + sizeof( struct V_10 ) ) ;
F_22 ( V_2 ) ;
} else {
if ( F_20 ( V_2 , V_7 -> V_51 ) )
goto V_53;
V_42 = & V_39 -> V_33 . V_11 ;
}
V_2 = F_23 ( V_2 , ! ! ( V_39 -> V_33 . V_43 & V_55 ) ) ;
if ( F_24 ( V_2 ) )
goto V_56;
F_13 ( V_2 , V_7 , V_42 , V_2 -> V_49 ) ;
return V_57 ;
V_53:
F_25 ( V_2 ) ;
V_56:
V_7 -> V_58 . V_59 ++ ;
return V_57 ;
}
static T_3 F_26 ( struct V_1 * V_2 ,
struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
V_2 = F_23 ( V_2 , ! ! ( V_39 -> V_33 . V_43 & V_55 ) ) ;
if ( F_24 ( V_2 ) )
goto V_56;
if ( F_20 ( V_2 , V_7 -> V_51 ) )
goto V_53;
F_13 ( V_2 , V_7 , & V_39 -> V_33 . V_11 , F_4 ( V_24 ) ) ;
return V_57 ;
V_53:
F_25 ( V_2 ) ;
V_56:
V_7 -> V_58 . V_59 ++ ;
return V_57 ;
}
static int F_27 ( struct V_41 * V_7 ,
struct V_60 * V_61 , int V_62 )
{
int V_63 ;
struct V_64 V_65 ;
if ( F_28 ( & V_65 , V_61 -> V_66 . V_67 , sizeof( V_65 ) ) )
return - V_68 ;
if ( V_62 == V_69 || V_62 == V_70 ) {
if ( V_65 . V_11 . V_71 != 4 || V_65 . V_11 . V_49 != V_72 ||
V_65 . V_11 . V_73 != 5 || ( V_65 . V_11 . V_74 & F_4 ( ~ V_75 ) ) ||
( ( V_65 . V_76 | V_65 . V_43 ) & ( V_77 | V_78 ) ) )
return - V_79 ;
}
V_65 . V_76 = F_29 ( V_65 . V_76 ) ;
V_65 . V_43 = F_29 ( V_65 . V_43 ) ;
V_63 = F_30 ( V_7 , & V_65 , V_62 ) ;
if ( V_63 )
return V_63 ;
V_65 . V_76 = F_31 ( V_65 . V_76 ) ;
V_65 . V_43 = F_31 ( V_65 . V_43 ) ;
if ( F_32 ( V_61 -> V_66 . V_67 , & V_65 , sizeof( V_65 ) ) )
return - V_68 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_41 * V_7 ,
unsigned short type ,
const void * V_29 , const void * V_30 , unsigned int V_80 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_81 * V_82 ;
V_11 = (struct V_10 * ) F_34 ( V_2 , V_14 -> V_52 + sizeof( * V_11 ) ) ;
V_82 = (struct V_81 * ) ( V_11 + 1 ) ;
V_82 -> V_28 = F_31 ( V_14 -> V_33 . V_43 ) ;
V_82 -> V_49 = F_4 ( type ) ;
memcpy ( V_11 , & V_14 -> V_33 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_30 )
memcpy ( & V_11 -> V_30 , V_30 , 4 ) ;
if ( V_29 )
memcpy ( & V_11 -> V_29 , V_29 , 4 ) ;
if ( V_11 -> V_29 )
return V_14 -> V_52 + sizeof( * V_11 ) ;
return - ( V_14 -> V_52 + sizeof( * V_11 ) ) ;
}
static int F_35 ( const struct V_1 * V_2 , unsigned char * V_83 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_36 ( V_2 ) ;
memcpy ( V_83 , & V_11 -> V_30 , 4 ) ;
return 4 ;
}
static int F_37 ( struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
if ( F_7 ( V_14 -> V_33 . V_11 . V_29 ) ) {
struct V_84 V_85 ;
struct V_86 * V_87 ;
V_87 = F_38 ( V_14 -> V_6 , & V_85 ,
V_14 -> V_33 . V_11 . V_29 ,
V_14 -> V_33 . V_11 . V_30 ,
V_14 -> V_33 . V_44 ,
F_39 ( V_14 -> V_33 . V_11 . V_88 ) ,
V_14 -> V_33 . V_89 ) ;
if ( F_24 ( V_87 ) )
return - V_90 ;
V_7 = V_87 -> V_91 . V_7 ;
F_40 ( V_87 ) ;
if ( ! F_41 ( V_7 ) )
return - V_90 ;
V_14 -> V_92 = V_7 -> V_27 ;
F_42 ( F_41 ( V_7 ) , V_14 -> V_33 . V_11 . V_29 ) ;
}
return 0 ;
}
static int F_43 ( struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
if ( F_7 ( V_14 -> V_33 . V_11 . V_29 ) && V_14 -> V_92 ) {
struct V_93 * V_94 ;
V_94 = F_44 ( V_14 -> V_6 , V_14 -> V_92 ) ;
if ( V_94 )
F_45 ( V_94 , V_14 -> V_33 . V_11 . V_29 ) ;
}
return 0 ;
}
static void F_46 ( struct V_41 * V_7 )
{
V_7 -> V_95 = & V_96 ;
V_7 -> type = V_97 ;
F_47 ( V_7 , V_26 ) ;
}
static void F_48 ( struct V_41 * V_7 )
{
struct V_13 * V_39 ;
int V_98 ;
V_39 = F_14 ( V_7 ) ;
V_39 -> V_48 = F_49 ( V_39 -> V_33 . V_43 ) ;
V_39 -> V_33 . V_11 . V_49 = V_72 ;
V_39 -> V_52 = V_39 -> V_48 + V_39 -> V_99 ;
V_98 = V_39 -> V_52 + sizeof( struct V_10 ) ;
V_7 -> V_51 = V_100 + V_98 + 4 ;
V_7 -> V_101 = V_102 - V_98 - 4 ;
V_7 -> V_103 |= V_104 ;
V_7 -> V_105 |= V_104 ;
if ( ! ( V_39 -> V_33 . V_43 & V_45 ) ) {
V_7 -> V_103 |= V_106 ;
V_7 -> V_105 |= V_106 ;
V_7 -> V_103 |= V_107 ;
}
}
static int F_50 ( struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
struct V_10 * V_11 = & V_39 -> V_33 . V_11 ;
F_48 ( V_7 ) ;
memcpy ( V_7 -> V_108 , & V_11 -> V_30 , 4 ) ;
memcpy ( V_7 -> V_109 , & V_11 -> V_29 , 4 ) ;
V_7 -> V_28 = V_110 ;
F_51 ( V_7 ) ;
V_7 -> V_111 = 4 ;
if ( V_11 -> V_29 ) {
#ifdef F_52
if ( F_7 ( V_11 -> V_29 ) ) {
if ( ! V_11 -> V_30 )
return - V_79 ;
V_7 -> V_28 = V_112 ;
V_7 -> V_50 = & V_113 ;
}
#endif
} else
V_7 -> V_50 = & V_113 ;
return F_53 ( V_7 ) ;
}
static int T_4 F_54 ( struct V_6 * V_6 )
{
return F_55 ( V_6 , V_26 , & V_114 , NULL ) ;
}
static void T_5 F_56 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_26 ) ;
F_57 ( V_9 , & V_114 ) ;
}
static int F_58 ( struct V_115 * V_116 [] , struct V_115 * V_54 [] )
{
T_2 V_28 ;
if ( ! V_54 )
return 0 ;
V_28 = 0 ;
if ( V_54 [ V_117 ] )
V_28 |= F_59 ( V_54 [ V_117 ] ) ;
if ( V_54 [ V_118 ] )
V_28 |= F_59 ( V_54 [ V_118 ] ) ;
if ( V_28 & ( V_77 | V_78 ) )
return - V_79 ;
return 0 ;
}
static int F_60 ( struct V_115 * V_116 [] , struct V_115 * V_54 [] )
{
T_6 V_29 ;
if ( V_116 [ V_119 ] ) {
if ( F_61 ( V_116 [ V_119 ] ) != V_120 )
return - V_79 ;
if ( ! F_62 ( F_63 ( V_116 [ V_119 ] ) ) )
return - V_90 ;
}
if ( ! V_54 )
goto V_56;
if ( V_54 [ V_121 ] ) {
memcpy ( & V_29 , F_63 ( V_54 [ V_121 ] ) , 4 ) ;
if ( ! V_29 )
return - V_79 ;
}
V_56:
return F_58 ( V_116 , V_54 ) ;
}
static void F_64 ( struct V_115 * V_54 [] , struct V_115 * V_116 [] ,
struct V_64 * V_33 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_11 . V_49 = V_72 ;
if ( ! V_54 )
return;
if ( V_54 [ V_122 ] )
V_33 -> V_89 = F_65 ( V_54 [ V_122 ] ) ;
if ( V_54 [ V_117 ] )
V_33 -> V_76 = F_29 ( F_59 ( V_54 [ V_117 ] ) ) ;
if ( V_54 [ V_118 ] )
V_33 -> V_43 = F_29 ( F_59 ( V_54 [ V_118 ] ) ) ;
if ( V_54 [ V_123 ] )
V_33 -> V_124 = F_66 ( V_54 [ V_123 ] ) ;
if ( V_54 [ V_125 ] )
V_33 -> V_44 = F_66 ( V_54 [ V_125 ] ) ;
if ( V_54 [ V_126 ] )
V_33 -> V_11 . V_30 = F_67 ( V_54 [ V_126 ] ) ;
if ( V_54 [ V_121 ] )
V_33 -> V_11 . V_29 = F_67 ( V_54 [ V_121 ] ) ;
if ( V_54 [ V_127 ] )
V_33 -> V_11 . V_34 = F_68 ( V_54 [ V_127 ] ) ;
if ( V_54 [ V_128 ] )
V_33 -> V_11 . V_88 = F_68 ( V_54 [ V_128 ] ) ;
if ( ! V_54 [ V_129 ] || F_68 ( V_54 [ V_129 ] ) )
V_33 -> V_11 . V_74 = F_4 ( V_75 ) ;
}
static bool F_69 ( struct V_115 * V_54 [] ,
struct V_130 * V_131 )
{
bool V_132 = false ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
if ( ! V_54 )
return V_132 ;
if ( V_54 [ V_133 ] ) {
V_132 = true ;
V_131 -> type = F_70 ( V_54 [ V_133 ] ) ;
}
if ( V_54 [ V_134 ] ) {
V_132 = true ;
V_131 -> V_28 = F_70 ( V_54 [ V_134 ] ) ;
}
if ( V_54 [ V_135 ] ) {
V_132 = true ;
V_131 -> V_136 = F_59 ( V_54 [ V_135 ] ) ;
}
if ( V_54 [ V_137 ] ) {
V_132 = true ;
V_131 -> V_138 = F_59 ( V_54 [ V_137 ] ) ;
}
return V_132 ;
}
static int F_71 ( struct V_41 * V_7 )
{
F_48 ( V_7 ) ;
V_7 -> V_139 |= V_140 ;
return F_53 ( V_7 ) ;
}
static void F_72 ( struct V_41 * V_7 )
{
F_73 ( V_7 ) ;
V_7 -> V_95 = & V_141 ;
V_7 -> V_139 |= V_140 ;
F_47 ( V_7 , V_25 ) ;
}
static int F_74 ( struct V_6 * V_142 , struct V_41 * V_7 ,
struct V_115 * V_116 [] , struct V_115 * V_54 [] )
{
struct V_64 V_65 ;
struct V_130 V_131 ;
if ( F_69 ( V_54 , & V_131 ) ) {
struct V_13 * V_14 = F_14 ( V_7 ) ;
int V_63 = F_75 ( V_14 , & V_131 ) ;
if ( V_63 < 0 )
return V_63 ;
}
F_64 ( V_54 , V_116 , & V_65 ) ;
return F_76 ( V_7 , V_116 , & V_65 ) ;
}
static int F_77 ( struct V_41 * V_7 , struct V_115 * V_116 [] ,
struct V_115 * V_54 [] )
{
struct V_64 V_65 ;
struct V_130 V_131 ;
if ( F_69 ( V_54 , & V_131 ) ) {
struct V_13 * V_14 = F_14 ( V_7 ) ;
int V_63 = F_75 ( V_14 , & V_131 ) ;
if ( V_63 < 0 )
return V_63 ;
}
F_64 ( V_54 , V_116 , & V_65 ) ;
return F_78 ( V_7 , V_116 , & V_65 ) ;
}
static T_7 F_79 ( const struct V_41 * V_7 )
{
return
F_80 ( 4 ) +
F_80 ( 2 ) +
F_80 ( 2 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 1 ) +
F_80 ( 1 ) +
F_80 ( 1 ) +
F_80 ( 2 ) +
F_80 ( 2 ) +
F_80 ( 2 ) +
F_80 ( 2 ) +
0 ;
}
static int F_81 ( struct V_1 * V_2 , const struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
struct V_64 * V_65 = & V_14 -> V_33 ;
if ( F_82 ( V_2 , V_122 , V_65 -> V_89 ) ||
F_83 ( V_2 , V_117 , F_31 ( V_65 -> V_76 ) ) ||
F_83 ( V_2 , V_118 , F_31 ( V_65 -> V_43 ) ) ||
F_84 ( V_2 , V_123 , V_65 -> V_124 ) ||
F_84 ( V_2 , V_125 , V_65 -> V_44 ) ||
F_85 ( V_2 , V_126 , V_65 -> V_11 . V_30 ) ||
F_85 ( V_2 , V_121 , V_65 -> V_11 . V_29 ) ||
F_86 ( V_2 , V_127 , V_65 -> V_11 . V_34 ) ||
F_86 ( V_2 , V_128 , V_65 -> V_11 . V_88 ) ||
F_86 ( V_2 , V_129 ,
! ! ( V_65 -> V_11 . V_74 & F_4 ( V_75 ) ) ) )
goto V_143;
if ( F_87 ( V_2 , V_133 ,
V_14 -> V_144 . type ) ||
F_83 ( V_2 , V_135 ,
V_14 -> V_144 . V_136 ) ||
F_83 ( V_2 , V_137 ,
V_14 -> V_144 . V_138 ) ||
F_87 ( V_2 , V_134 ,
V_14 -> V_144 . V_28 ) )
goto V_143;
return 0 ;
V_143:
return - V_145 ;
}
static int T_4 F_88 ( struct V_6 * V_6 )
{
return F_55 ( V_6 , V_25 , & V_146 , NULL ) ;
}
static void T_5 F_89 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_25 ) ;
F_57 ( V_9 , & V_146 ) ;
}
static int T_8 F_90 ( void )
{
int V_63 ;
F_91 ( L_1 ) ;
V_63 = F_92 ( & V_147 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_92 ( & V_148 ) ;
if ( V_63 < 0 )
goto V_149;
V_63 = F_93 ( & V_150 ) ;
if ( V_63 < 0 ) {
F_91 ( L_2 , V_151 ) ;
goto V_152;
}
V_63 = F_94 ( & V_114 ) ;
if ( V_63 < 0 )
goto V_153;
V_63 = F_94 ( & V_146 ) ;
if ( V_63 < 0 )
goto V_154;
return 0 ;
V_154:
F_95 ( & V_114 ) ;
V_153:
F_96 ( & V_150 ) ;
V_152:
F_97 ( & V_148 ) ;
V_149:
F_97 ( & V_147 ) ;
return V_63 ;
}
static void T_9 F_98 ( void )
{
F_95 ( & V_146 ) ;
F_95 ( & V_114 ) ;
F_96 ( & V_150 ) ;
F_97 ( & V_148 ) ;
F_97 ( & V_147 ) ;
}
