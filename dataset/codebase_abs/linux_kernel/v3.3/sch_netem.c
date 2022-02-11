static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
F_1 ( V_3 , sizeof( struct V_1 ) ) ;
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static void F_3 ( struct V_5 * V_6 , unsigned long V_7 )
{
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = F_4 () ;
}
static T_1 F_5 ( struct V_5 * V_6 )
{
T_2 V_9 , V_7 ;
unsigned long V_10 ;
if ( V_6 -> V_7 == 0 )
return F_4 () ;
V_9 = F_4 () ;
V_7 = ( T_2 ) V_6 -> V_7 + 1 ;
V_10 = ( V_9 * ( ( 1ull << 32 ) - V_7 ) + V_6 -> V_8 * V_7 ) >> 32 ;
V_6 -> V_8 = V_10 ;
return V_10 ;
}
static bool F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
T_1 V_15 = F_4 () ;
switch ( V_14 -> V_6 ) {
case 1 :
if ( V_15 < V_14 -> V_16 ) {
V_14 -> V_6 = 4 ;
return true ;
} else if ( V_14 -> V_16 < V_15 && V_15 < V_14 -> V_17 ) {
V_14 -> V_6 = 3 ;
return true ;
} else if ( V_14 -> V_17 < V_15 )
V_14 -> V_6 = 1 ;
break;
case 2 :
if ( V_15 < V_14 -> V_18 ) {
V_14 -> V_6 = 3 ;
return true ;
} else
V_14 -> V_6 = 2 ;
break;
case 3 :
if ( V_15 < V_14 -> V_19 )
V_14 -> V_6 = 2 ;
else if ( V_14 -> V_19 < V_15 && V_15 < V_14 -> V_20 + V_14 -> V_19 ) {
V_14 -> V_6 = 1 ;
return true ;
} else if ( V_14 -> V_20 + V_14 -> V_19 < V_15 ) {
V_14 -> V_6 = 3 ;
return true ;
}
break;
case 4 :
V_14 -> V_6 = 1 ;
break;
}
return false ;
}
static bool F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
switch ( V_14 -> V_6 ) {
case 1 :
if ( F_4 () < V_14 -> V_17 )
V_14 -> V_6 = 2 ;
if ( F_4 () < V_14 -> V_16 )
return true ;
case 2 :
if ( F_4 () < V_14 -> V_20 )
V_14 -> V_6 = 1 ;
if ( V_14 -> V_19 > F_4 () )
return true ;
}
return false ;
}
static bool F_8 ( struct V_11 * V_12 )
{
switch ( V_12 -> V_21 ) {
case V_22 :
return V_12 -> V_23 && V_12 -> V_23 >= F_5 ( & V_12 -> V_24 ) ;
case V_25 :
return F_6 ( V_12 ) ;
case V_26 :
return F_7 ( V_12 ) ;
}
return false ;
}
static T_3 F_9 ( T_3 V_27 , T_3 V_28 ,
struct V_5 * V_6 ,
const struct V_29 * V_30 )
{
T_3 V_31 ;
long V_32 ;
T_1 V_15 ;
if ( V_28 == 0 )
return V_27 ;
V_15 = F_5 ( V_6 ) ;
if ( V_30 == NULL )
return ( V_15 % ( 2 * V_28 ) ) - V_28 + V_27 ;
V_32 = V_30 -> V_33 [ V_15 % V_30 -> V_34 ] ;
V_31 = ( V_28 % V_35 ) * V_32 ;
if ( V_31 >= 0 )
V_31 += V_35 / 2 ;
else
V_31 -= V_35 / 2 ;
return V_31 / V_35 + ( V_28 / V_35 ) * V_32 + V_27 ;
}
static T_4 F_10 ( unsigned int V_36 , struct V_11 * V_12 )
{
T_2 V_37 ;
V_36 += V_12 -> V_38 ;
if ( V_12 -> V_39 ) {
T_1 V_40 = F_11 ( V_36 , V_12 -> V_41 ) ;
if ( V_36 > V_40 * V_12 -> V_39 )
V_40 ++ ;
V_36 = V_40 * ( V_12 -> V_39 + V_12 -> V_42 ) ;
}
V_37 = ( T_2 ) V_36 * V_43 ;
F_12 ( V_37 , V_12 -> V_44 ) ;
return F_13 ( V_37 ) ;
}
static int F_14 ( struct V_2 * V_45 , struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_47 -> V_12 ;
T_4 V_50 = V_1 ( V_45 ) -> V_51 ;
struct V_2 * V_3 ;
if ( F_15 ( F_16 ( V_49 ) < V_47 -> V_52 ) ) {
V_3 = F_17 ( V_49 ) ;
if ( F_15 ( ! V_3 || V_50 >= V_1 ( V_3 ) -> V_51 ) )
return F_18 ( V_45 , V_47 ) ;
F_19 (list, skb) {
if ( V_50 >= V_1 ( V_3 ) -> V_51 )
break;
}
F_20 ( V_49 , V_3 , V_45 ) ;
V_47 -> V_53 . V_54 += F_21 ( V_45 ) ;
return V_55 ;
}
return F_22 ( V_45 , V_47 ) ;
}
static int F_23 ( struct V_2 * V_3 , struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_1 * V_56 ;
struct V_2 * V_57 ;
int V_58 ;
int V_59 = 1 ;
if ( V_12 -> V_60 && V_12 -> V_60 >= F_5 ( & V_12 -> V_61 ) )
++ V_59 ;
if ( F_8 ( V_12 ) )
-- V_59 ;
if ( V_59 == 0 ) {
V_47 -> V_53 . V_62 ++ ;
F_25 ( V_3 ) ;
return V_55 | V_63 ;
}
F_26 ( V_3 ) ;
if ( V_59 > 1 && ( V_57 = F_27 ( V_3 , V_64 ) ) != NULL ) {
struct V_46 * V_65 = F_28 ( V_47 ) ;
T_1 V_66 = V_12 -> V_60 ;
V_12 -> V_60 = 0 ;
F_29 ( V_57 , V_65 ) ;
V_12 -> V_60 = V_66 ;
}
if ( V_12 -> V_67 && V_12 -> V_67 >= F_5 ( & V_12 -> V_68 ) ) {
if ( ! ( V_3 = F_30 ( V_3 , V_64 ) ) ||
( V_3 -> V_69 == V_70 &&
F_31 ( V_3 ) ) ) {
V_47 -> V_53 . V_62 ++ ;
return V_71 ;
}
V_3 -> V_4 [ F_4 () % F_32 ( V_3 ) ] ^= 1 << ( F_4 () % 8 ) ;
}
V_56 = V_1 ( V_3 ) ;
if ( V_12 -> V_72 == 0 ||
V_12 -> V_73 < V_12 -> V_72 - 1 ||
V_12 -> V_74 < F_5 ( & V_12 -> V_75 ) ) {
T_4 V_76 ;
T_3 V_77 ;
V_77 = F_9 ( V_12 -> V_78 , V_12 -> V_79 ,
& V_12 -> V_80 , V_12 -> V_81 ) ;
V_76 = F_33 () ;
if ( V_12 -> V_44 ) {
struct V_48 * V_49 = & V_47 -> V_12 ;
V_77 += F_10 ( V_3 -> V_36 , V_12 ) ;
if ( ! F_34 ( V_49 ) ) {
V_77 -= V_76 - V_1 ( F_35 ( V_49 ) ) -> V_51 ;
V_76 = V_1 ( F_17 ( V_49 ) ) -> V_51 ;
}
}
V_56 -> V_51 = V_76 + V_77 ;
++ V_12 -> V_73 ;
V_58 = F_14 ( V_3 , V_47 ) ;
} else {
V_56 -> V_51 = F_33 () ;
V_12 -> V_73 = 0 ;
F_36 ( & V_47 -> V_12 , V_3 ) ;
V_47 -> V_53 . V_54 += F_21 ( V_3 ) ;
V_47 -> V_53 . V_82 ++ ;
V_58 = V_55 ;
}
if ( V_58 != V_55 ) {
if ( F_37 ( V_58 ) ) {
V_47 -> V_53 . V_62 ++ ;
return V_58 ;
}
}
return V_55 ;
}
static unsigned int F_38 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
unsigned int V_36 ;
V_36 = F_39 ( V_47 ) ;
if ( ! V_36 && V_12 -> V_83 && V_12 -> V_83 -> V_84 -> V_85 )
V_36 = V_12 -> V_83 -> V_84 -> V_85 ( V_12 -> V_83 ) ;
if ( V_36 )
V_47 -> V_53 . V_62 ++ ;
return V_36 ;
}
static struct V_2 * F_40 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_2 * V_3 ;
if ( F_41 ( V_47 ) )
return NULL ;
V_86:
V_3 = F_42 ( V_47 ) ;
if ( V_3 ) {
const struct V_1 * V_56 = V_1 ( V_3 ) ;
if ( V_56 -> V_51 <= F_33 () ) {
F_43 ( V_3 , & V_47 -> V_12 ) ;
V_47 -> V_53 . V_54 -= F_21 ( V_3 ) ;
#ifdef F_44
if ( F_45 ( V_3 -> V_87 ) & V_88 )
V_3 -> V_89 . V_90 = 0 ;
#endif
if ( V_12 -> V_83 ) {
int V_91 = F_46 ( V_3 , V_12 -> V_83 ) ;
if ( F_47 ( V_91 != V_55 ) ) {
if ( F_37 ( V_91 ) ) {
V_47 -> V_53 . V_62 ++ ;
F_48 ( V_47 , 1 ) ;
}
}
goto V_86;
}
V_92:
F_49 ( V_47 ) ;
F_50 ( V_47 , V_3 ) ;
return V_3 ;
}
if ( V_12 -> V_83 ) {
V_3 = V_12 -> V_83 -> V_84 -> V_93 ( V_12 -> V_83 ) ;
if ( V_3 )
goto V_92;
}
F_51 ( & V_12 -> V_94 , V_56 -> V_51 ) ;
}
if ( V_12 -> V_83 ) {
V_3 = V_12 -> V_83 -> V_84 -> V_93 ( V_12 -> V_83 ) ;
if ( V_3 )
goto V_92;
}
return NULL ;
}
static void F_52 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_53 ( V_47 ) ;
if ( V_12 -> V_83 )
F_54 ( V_12 -> V_83 ) ;
F_55 ( & V_12 -> V_94 ) ;
}
static void F_56 ( struct V_29 * V_95 )
{
if ( V_95 ) {
if ( F_57 ( V_95 ) )
F_58 ( V_95 ) ;
else
F_59 ( V_95 ) ;
}
}
static int F_60 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
T_5 V_98 = F_61 ( V_97 ) / sizeof( V_99 ) ;
const V_99 * V_4 = F_62 ( V_97 ) ;
T_6 * V_100 ;
struct V_29 * V_95 ;
int V_101 ;
T_5 V_102 ;
if ( V_98 > V_103 )
return - V_104 ;
V_102 = sizeof( struct V_29 ) + V_98 * sizeof( V_105 ) ;
V_95 = F_63 ( V_102 , V_106 | V_107 ) ;
if ( ! V_95 )
V_95 = F_64 ( V_102 ) ;
if ( ! V_95 )
return - V_108 ;
V_95 -> V_34 = V_98 ;
for ( V_101 = 0 ; V_101 < V_98 ; V_101 ++ )
V_95 -> V_33 [ V_101 ] = V_4 [ V_101 ] ;
V_100 = F_65 ( V_47 ) ;
F_66 ( V_100 ) ;
F_67 ( V_12 -> V_81 , V_95 ) ;
F_68 ( V_100 ) ;
F_56 ( V_95 ) ;
return 0 ;
}
static void F_69 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_109 * V_110 = F_62 ( V_97 ) ;
F_3 ( & V_12 -> V_80 , V_110 -> V_111 ) ;
F_3 ( & V_12 -> V_24 , V_110 -> V_112 ) ;
F_3 ( & V_12 -> V_61 , V_110 -> V_113 ) ;
}
static void F_70 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_114 * V_115 = F_62 ( V_97 ) ;
V_12 -> V_74 = V_115 -> V_116 ;
F_3 ( & V_12 -> V_75 , V_115 -> V_117 ) ;
}
static void F_71 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_118 * V_115 = F_62 ( V_97 ) ;
V_12 -> V_67 = V_115 -> V_116 ;
F_3 ( & V_12 -> V_68 , V_115 -> V_117 ) ;
}
static void F_72 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_119 * V_115 = F_62 ( V_97 ) ;
V_12 -> V_44 = V_115 -> V_44 ;
V_12 -> V_38 = V_115 -> V_38 ;
V_12 -> V_39 = V_115 -> V_39 ;
if ( V_12 -> V_39 )
V_12 -> V_41 = F_73 ( V_12 -> V_39 ) ;
V_12 -> V_42 = V_115 -> V_42 ;
}
static int F_74 ( struct V_46 * V_47 , const struct V_96 * V_97 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_96 * V_120 ;
int V_121 ;
F_75 (la, attr, rem) {
T_7 type = F_76 ( V_120 ) ;
switch( type ) {
case V_122 : {
const struct V_123 * V_124 = F_62 ( V_120 ) ;
if ( F_61 ( V_120 ) < sizeof( struct V_123 ) ) {
F_77 ( L_1 ) ;
return - V_104 ;
}
V_12 -> V_21 = V_25 ;
V_12 -> V_14 . V_6 = 1 ;
V_12 -> V_14 . V_17 = V_124 -> V_125 ;
V_12 -> V_14 . V_20 = V_124 -> V_126 ;
V_12 -> V_14 . V_19 = V_124 -> V_127 ;
V_12 -> V_14 . V_16 = V_124 -> V_128 ;
V_12 -> V_14 . V_18 = V_124 -> V_129 ;
break;
}
case V_130 : {
const struct V_131 * V_132 = F_62 ( V_120 ) ;
if ( F_61 ( V_120 ) < sizeof( struct V_131 ) ) {
F_77 ( L_2 ) ;
return - V_104 ;
}
V_12 -> V_21 = V_26 ;
V_12 -> V_14 . V_6 = 1 ;
V_12 -> V_14 . V_17 = V_132 -> V_133 ;
V_12 -> V_14 . V_20 = V_132 -> V_115 ;
V_12 -> V_14 . V_19 = V_132 -> V_134 ;
V_12 -> V_14 . V_16 = V_132 -> V_135 ;
break;
}
default:
F_77 ( L_3 , type ) ;
return - V_104 ;
}
}
return 0 ;
}
static int F_78 ( struct V_96 * V_136 [] , int V_137 , struct V_96 * V_138 ,
const struct V_139 * V_140 , int V_36 )
{
int V_141 = F_61 ( V_138 ) - F_79 ( V_36 ) ;
if ( V_141 < 0 ) {
F_77 ( L_4 , V_141 ) ;
return - V_104 ;
}
if ( V_141 >= F_80 ( 0 ) )
return F_81 ( V_136 , V_137 , F_62 ( V_138 ) + F_79 ( V_36 ) ,
V_141 , V_140 ) ;
memset ( V_136 , 0 , sizeof( struct V_96 * ) * ( V_137 + 1 ) ) ;
return 0 ;
}
static int F_82 ( struct V_46 * V_47 , struct V_96 * V_142 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_96 * V_136 [ V_143 + 1 ] ;
struct V_144 * V_145 ;
int V_58 ;
if ( V_142 == NULL )
return - V_104 ;
V_145 = F_62 ( V_142 ) ;
V_58 = F_78 ( V_136 , V_143 , V_142 , V_146 , sizeof( * V_145 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_47 -> V_52 = V_145 -> V_52 ;
V_12 -> V_78 = V_145 -> V_78 ;
V_12 -> V_79 = V_145 -> V_79 ;
V_12 -> V_52 = V_145 -> V_52 ;
V_12 -> V_72 = V_145 -> V_72 ;
V_12 -> V_73 = 0 ;
V_12 -> V_23 = V_145 -> V_23 ;
V_12 -> V_60 = V_145 -> V_60 ;
if ( V_12 -> V_72 )
V_12 -> V_74 = ~ 0 ;
if ( V_136 [ V_147 ] )
F_69 ( V_47 , V_136 [ V_147 ] ) ;
if ( V_136 [ V_148 ] ) {
V_58 = F_60 ( V_47 , V_136 [ V_148 ] ) ;
if ( V_58 )
return V_58 ;
}
if ( V_136 [ V_149 ] )
F_70 ( V_47 , V_136 [ V_149 ] ) ;
if ( V_136 [ V_150 ] )
F_71 ( V_47 , V_136 [ V_150 ] ) ;
if ( V_136 [ V_151 ] )
F_72 ( V_47 , V_136 [ V_151 ] ) ;
V_12 -> V_21 = V_22 ;
if ( V_136 [ V_152 ] )
V_58 = F_74 ( V_47 , V_136 [ V_152 ] ) ;
return V_58 ;
}
static int F_83 ( struct V_46 * V_47 , struct V_96 * V_142 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
int V_58 ;
if ( ! V_142 )
return - V_104 ;
F_84 ( & V_12 -> V_94 , V_47 ) ;
V_12 -> V_21 = V_22 ;
V_58 = F_82 ( V_47 , V_142 ) ;
if ( V_58 )
F_77 ( L_5 ) ;
return V_58 ;
}
static void F_85 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_55 ( & V_12 -> V_94 ) ;
if ( V_12 -> V_83 )
F_86 ( V_12 -> V_83 ) ;
F_56 ( V_12 -> V_81 ) ;
}
static int F_87 ( const struct V_11 * V_12 ,
struct V_2 * V_3 )
{
struct V_96 * V_153 ;
V_153 = F_88 ( V_3 , V_152 ) ;
if ( V_153 == NULL )
goto V_154;
switch ( V_12 -> V_21 ) {
case V_22 :
F_89 ( V_3 , V_153 ) ;
return 0 ;
case V_25 : {
struct V_123 V_124 = {
. V_125 = V_12 -> V_14 . V_17 ,
. V_126 = V_12 -> V_14 . V_20 ,
. V_127 = V_12 -> V_14 . V_19 ,
. V_128 = V_12 -> V_14 . V_16 ,
. V_129 = V_12 -> V_14 . V_18 ,
} ;
F_90 ( V_3 , V_122 , sizeof( V_124 ) , & V_124 ) ;
break;
}
case V_26 : {
struct V_131 V_132 = {
. V_133 = V_12 -> V_14 . V_17 ,
. V_115 = V_12 -> V_14 . V_20 ,
. V_134 = V_12 -> V_14 . V_19 ,
. V_135 = V_12 -> V_14 . V_16 ,
} ;
F_90 ( V_3 , V_130 , sizeof( V_132 ) , & V_132 ) ;
break;
}
}
F_91 ( V_3 , V_153 ) ;
return 0 ;
V_154:
F_89 ( V_3 , V_153 ) ;
return - 1 ;
}
static int F_92 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
const struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_96 * V_138 = (struct V_96 * ) F_93 ( V_3 ) ;
struct V_144 V_145 ;
struct V_109 V_155 ;
struct V_114 V_74 ;
struct V_118 V_67 ;
struct V_119 V_44 ;
V_145 . V_78 = V_12 -> V_78 ;
V_145 . V_79 = V_12 -> V_79 ;
V_145 . V_52 = V_12 -> V_52 ;
V_145 . V_23 = V_12 -> V_23 ;
V_145 . V_72 = V_12 -> V_72 ;
V_145 . V_60 = V_12 -> V_60 ;
F_90 ( V_3 , V_156 , sizeof( V_145 ) , & V_145 ) ;
V_155 . V_111 = V_12 -> V_80 . V_7 ;
V_155 . V_112 = V_12 -> V_24 . V_7 ;
V_155 . V_113 = V_12 -> V_61 . V_7 ;
F_90 ( V_3 , V_147 , sizeof( V_155 ) , & V_155 ) ;
V_74 . V_116 = V_12 -> V_74 ;
V_74 . V_117 = V_12 -> V_75 . V_7 ;
F_90 ( V_3 , V_149 , sizeof( V_74 ) , & V_74 ) ;
V_67 . V_116 = V_12 -> V_67 ;
V_67 . V_117 = V_12 -> V_68 . V_7 ;
F_90 ( V_3 , V_150 , sizeof( V_67 ) , & V_67 ) ;
V_44 . V_44 = V_12 -> V_44 ;
V_44 . V_38 = V_12 -> V_38 ;
V_44 . V_39 = V_12 -> V_39 ;
V_44 . V_42 = V_12 -> V_42 ;
F_90 ( V_3 , V_151 , sizeof( V_44 ) , & V_44 ) ;
if ( F_87 ( V_12 , V_3 ) != 0 )
goto V_154;
return F_91 ( V_3 , V_138 ) ;
V_154:
F_94 ( V_3 , V_138 ) ;
return - 1 ;
}
static int F_95 ( struct V_46 * V_47 , unsigned long V_157 ,
struct V_2 * V_3 , struct V_158 * V_159 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
if ( V_157 != 1 || ! V_12 -> V_83 )
return - V_160 ;
V_159 -> V_161 |= F_96 ( 1 ) ;
V_159 -> V_162 = V_12 -> V_83 -> V_163 ;
return 0 ;
}
static int F_97 ( struct V_46 * V_47 , unsigned long V_164 , struct V_46 * V_165 ,
struct V_46 * * V_166 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_98 ( V_47 ) ;
* V_166 = V_12 -> V_83 ;
V_12 -> V_83 = V_165 ;
if ( * V_166 ) {
F_48 ( * V_166 , ( * V_166 ) -> V_12 . V_167 ) ;
F_54 ( * V_166 ) ;
}
F_99 ( V_47 ) ;
return 0 ;
}
static struct V_46 * F_100 ( struct V_46 * V_47 , unsigned long V_164 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
return V_12 -> V_83 ;
}
static unsigned long F_101 ( struct V_46 * V_47 , T_1 V_168 )
{
return 1 ;
}
static void F_102 ( struct V_46 * V_47 , unsigned long V_164 )
{
}
static void F_103 ( struct V_46 * V_47 , struct V_169 * V_170 )
{
if ( ! V_170 -> V_171 ) {
if ( V_170 -> V_59 >= V_170 -> V_172 )
if ( V_170 -> V_173 ( V_47 , 1 , V_170 ) < 0 ) {
V_170 -> V_171 = 1 ;
return;
}
V_170 -> V_59 ++ ;
}
}
static int T_8 F_104 ( void )
{
F_77 ( L_6 V_174 L_7 ) ;
return F_105 ( & V_175 ) ;
}
static void T_9 F_106 ( void )
{
F_107 ( & V_175 ) ;
}
