static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
F_1 ( sizeof( V_3 -> V_4 ) <
sizeof( struct V_5 ) + sizeof( struct V_1 ) ) ;
return (struct V_1 * ) V_5 ( V_3 ) -> V_6 ;
}
static void F_2 ( struct V_7 * V_8 , unsigned long V_9 )
{
V_8 -> V_9 = V_9 ;
V_8 -> V_10 = F_3 () ;
}
static T_1 F_4 ( struct V_7 * V_8 )
{
T_2 V_11 , V_9 ;
unsigned long V_12 ;
if ( V_8 -> V_9 == 0 )
return F_3 () ;
V_11 = F_3 () ;
V_9 = ( T_2 ) V_8 -> V_9 + 1 ;
V_12 = ( V_11 * ( ( 1ull << 32 ) - V_9 ) + V_8 -> V_10 * V_9 ) >> 32 ;
V_8 -> V_10 = V_12 ;
return V_12 ;
}
static bool F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
T_1 V_17 = F_3 () ;
switch ( V_16 -> V_8 ) {
case 1 :
if ( V_17 < V_16 -> V_18 ) {
V_16 -> V_8 = 4 ;
return true ;
} else if ( V_16 -> V_18 < V_17 && V_17 < V_16 -> V_19 ) {
V_16 -> V_8 = 3 ;
return true ;
} else if ( V_16 -> V_19 < V_17 )
V_16 -> V_8 = 1 ;
break;
case 2 :
if ( V_17 < V_16 -> V_20 ) {
V_16 -> V_8 = 3 ;
return true ;
} else
V_16 -> V_8 = 2 ;
break;
case 3 :
if ( V_17 < V_16 -> V_21 )
V_16 -> V_8 = 2 ;
else if ( V_16 -> V_21 < V_17 && V_17 < V_16 -> V_22 + V_16 -> V_21 ) {
V_16 -> V_8 = 1 ;
return true ;
} else if ( V_16 -> V_22 + V_16 -> V_21 < V_17 ) {
V_16 -> V_8 = 3 ;
return true ;
}
break;
case 4 :
V_16 -> V_8 = 1 ;
break;
}
return false ;
}
static bool F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
switch ( V_16 -> V_8 ) {
case 1 :
if ( F_3 () < V_16 -> V_19 )
V_16 -> V_8 = 2 ;
if ( F_3 () < V_16 -> V_18 )
return true ;
case 2 :
if ( F_3 () < V_16 -> V_22 )
V_16 -> V_8 = 1 ;
if ( V_16 -> V_21 > F_3 () )
return true ;
}
return false ;
}
static bool F_7 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_23 ) {
case V_24 :
return V_14 -> V_25 && V_14 -> V_25 >= F_4 ( & V_14 -> V_26 ) ;
case V_27 :
return F_5 ( V_14 ) ;
case V_28 :
return F_6 ( V_14 ) ;
}
return false ;
}
static T_3 F_8 ( T_3 V_29 , T_3 V_30 ,
struct V_7 * V_8 ,
const struct V_31 * V_32 )
{
T_3 V_33 ;
long V_34 ;
T_1 V_17 ;
if ( V_30 == 0 )
return V_29 ;
V_17 = F_4 ( V_8 ) ;
if ( V_32 == NULL )
return ( V_17 % ( 2 * V_30 ) ) - V_30 + V_29 ;
V_34 = V_32 -> V_35 [ V_17 % V_32 -> V_36 ] ;
V_33 = ( V_30 % V_37 ) * V_34 ;
if ( V_33 >= 0 )
V_33 += V_37 / 2 ;
else
V_33 -= V_37 / 2 ;
return V_33 / V_37 + ( V_30 / V_37 ) * V_34 + V_29 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_1 * V_4 ;
struct V_2 * V_40 ;
int V_41 ;
int V_42 = 1 ;
if ( V_14 -> V_43 && V_14 -> V_43 >= F_4 ( & V_14 -> V_44 ) )
++ V_42 ;
if ( F_7 ( V_14 ) )
-- V_42 ;
if ( V_42 == 0 ) {
V_39 -> V_45 . V_46 ++ ;
F_11 ( V_3 ) ;
return V_47 | V_48 ;
}
F_12 ( V_3 ) ;
if ( V_42 > 1 && ( V_40 = F_13 ( V_3 , V_49 ) ) != NULL ) {
struct V_38 * V_50 = F_14 ( V_39 ) ;
T_1 V_51 = V_14 -> V_43 ;
V_14 -> V_43 = 0 ;
F_15 ( V_40 , V_50 ) ;
V_14 -> V_43 = V_51 ;
}
if ( V_14 -> V_52 && V_14 -> V_52 >= F_4 ( & V_14 -> V_53 ) ) {
if ( ! ( V_3 = F_16 ( V_3 , V_49 ) ) ||
( V_3 -> V_54 == V_55 &&
F_17 ( V_3 ) ) ) {
V_39 -> V_45 . V_46 ++ ;
return V_56 ;
}
V_3 -> V_6 [ F_3 () % F_18 ( V_3 ) ] ^= 1 << ( F_3 () % 8 ) ;
}
V_4 = V_1 ( V_3 ) ;
if ( V_14 -> V_57 == 0 ||
V_14 -> V_58 < V_14 -> V_57 ||
V_14 -> V_59 < F_4 ( & V_14 -> V_60 ) ) {
T_4 V_61 ;
T_3 V_62 ;
V_62 = F_8 ( V_14 -> V_63 , V_14 -> V_64 ,
& V_14 -> V_65 , V_14 -> V_66 ) ;
V_61 = F_19 () ;
V_4 -> V_67 = V_61 + V_62 ;
++ V_14 -> V_58 ;
V_41 = F_20 ( V_3 , V_14 -> V_68 ) ;
} else {
V_4 -> V_67 = F_19 () ;
V_14 -> V_58 = 0 ;
F_21 ( & V_14 -> V_68 -> V_14 , V_3 ) ;
V_14 -> V_68 -> V_45 . V_69 += F_22 ( V_3 ) ;
V_14 -> V_68 -> V_45 . V_70 ++ ;
V_41 = V_47 ;
}
if ( V_41 != V_47 ) {
if ( F_23 ( V_41 ) ) {
V_39 -> V_45 . V_46 ++ ;
return V_41 ;
}
}
V_39 -> V_14 . V_71 ++ ;
return V_47 ;
}
static unsigned int F_24 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
unsigned int V_72 = 0 ;
if ( V_14 -> V_68 -> V_73 -> V_74 && ( V_72 = V_14 -> V_68 -> V_73 -> V_74 ( V_14 -> V_68 ) ) != 0 ) {
V_39 -> V_14 . V_71 -- ;
V_39 -> V_45 . V_46 ++ ;
}
return V_72 ;
}
static struct V_2 * F_25 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_2 * V_3 ;
if ( F_26 ( V_39 ) )
return NULL ;
V_3 = V_14 -> V_68 -> V_73 -> V_75 ( V_14 -> V_68 ) ;
if ( V_3 ) {
const struct V_1 * V_4 = V_1 ( V_3 ) ;
T_4 V_61 = F_19 () ;
if ( V_4 -> V_67 <= V_61 ) {
V_3 = F_27 ( V_14 -> V_68 ) ;
if ( F_28 ( ! V_3 ) )
return NULL ;
#ifdef F_29
if ( F_30 ( V_3 -> V_76 ) & V_77 )
V_3 -> V_78 . V_79 = 0 ;
#endif
V_39 -> V_14 . V_71 -- ;
F_31 ( V_39 ) ;
F_32 ( V_39 , V_3 ) ;
return V_3 ;
}
F_33 ( & V_14 -> V_80 , V_4 -> V_67 ) ;
}
return NULL ;
}
static void F_34 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
F_35 ( V_14 -> V_68 ) ;
V_39 -> V_14 . V_71 = 0 ;
F_36 ( & V_14 -> V_80 ) ;
}
static void F_37 ( struct V_31 * V_81 )
{
if ( V_81 ) {
if ( F_38 ( V_81 ) )
F_39 ( V_81 ) ;
else
F_40 ( V_81 ) ;
}
}
static int F_41 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
T_5 V_84 = F_42 ( V_83 ) / sizeof( V_85 ) ;
const V_85 * V_6 = F_43 ( V_83 ) ;
T_6 * V_86 ;
struct V_31 * V_81 ;
int V_87 ;
T_5 V_88 ;
if ( V_84 > V_89 )
return - V_90 ;
V_88 = sizeof( struct V_31 ) + V_84 * sizeof( V_91 ) ;
V_81 = F_44 ( V_88 , V_92 | V_93 ) ;
if ( ! V_81 )
V_81 = F_45 ( V_88 ) ;
if ( ! V_81 )
return - V_94 ;
V_81 -> V_36 = V_84 ;
for ( V_87 = 0 ; V_87 < V_84 ; V_87 ++ )
V_81 -> V_35 [ V_87 ] = V_6 [ V_87 ] ;
V_86 = F_46 ( V_39 ) ;
F_47 ( V_86 ) ;
F_48 ( V_14 -> V_66 , V_81 ) ;
F_49 ( V_86 ) ;
F_37 ( V_81 ) ;
return 0 ;
}
static void F_50 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_95 * V_96 = F_43 ( V_83 ) ;
F_2 ( & V_14 -> V_65 , V_96 -> V_97 ) ;
F_2 ( & V_14 -> V_26 , V_96 -> V_98 ) ;
F_2 ( & V_14 -> V_44 , V_96 -> V_99 ) ;
}
static void F_51 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_100 * V_101 = F_43 ( V_83 ) ;
V_14 -> V_59 = V_101 -> V_102 ;
F_2 ( & V_14 -> V_60 , V_101 -> V_103 ) ;
}
static void F_52 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_104 * V_101 = F_43 ( V_83 ) ;
V_14 -> V_52 = V_101 -> V_102 ;
F_2 ( & V_14 -> V_53 , V_101 -> V_103 ) ;
}
static int F_53 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_82 * V_105 ;
int V_106 ;
F_54 (la, attr, rem) {
T_7 type = F_55 ( V_105 ) ;
switch( type ) {
case V_107 : {
const struct V_108 * V_109 = F_43 ( V_105 ) ;
if ( F_42 ( V_105 ) != sizeof( struct V_108 ) ) {
F_56 ( L_1 ) ;
return - V_90 ;
}
V_14 -> V_23 = V_27 ;
V_14 -> V_16 . V_8 = 1 ;
V_14 -> V_16 . V_19 = V_109 -> V_110 ;
V_14 -> V_16 . V_22 = V_109 -> V_111 ;
V_14 -> V_16 . V_21 = V_109 -> V_112 ;
V_14 -> V_16 . V_18 = V_109 -> V_113 ;
V_14 -> V_16 . V_20 = V_109 -> V_114 ;
break;
}
case V_115 : {
const struct V_116 * V_117 = F_43 ( V_105 ) ;
if ( F_42 ( V_105 ) != sizeof( struct V_116 ) ) {
F_56 ( L_1 ) ;
return - V_90 ;
}
V_14 -> V_23 = V_28 ;
V_14 -> V_16 . V_8 = 1 ;
V_14 -> V_16 . V_19 = V_117 -> V_118 ;
V_14 -> V_16 . V_22 = V_117 -> V_101 ;
V_14 -> V_16 . V_21 = V_117 -> V_119 ;
V_14 -> V_16 . V_18 = V_117 -> V_120 ;
break;
}
default:
F_56 ( L_2 , type ) ;
return - V_90 ;
}
}
return 0 ;
}
static int F_57 ( struct V_82 * V_121 [] , int V_122 , struct V_82 * V_123 ,
const struct V_124 * V_125 , int V_72 )
{
int V_126 = F_42 ( V_123 ) - F_58 ( V_72 ) ;
if ( V_126 < 0 ) {
F_56 ( L_3 , V_126 ) ;
return - V_90 ;
}
if ( V_126 >= F_59 ( 0 ) )
return F_60 ( V_121 , V_122 , F_43 ( V_123 ) + F_58 ( V_72 ) ,
V_126 , V_125 ) ;
memset ( V_121 , 0 , sizeof( struct V_82 * ) * ( V_122 + 1 ) ) ;
return 0 ;
}
static int F_61 ( struct V_38 * V_39 , struct V_82 * V_127 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_82 * V_121 [ V_128 + 1 ] ;
struct V_129 * V_130 ;
int V_41 ;
if ( V_127 == NULL )
return - V_90 ;
V_130 = F_43 ( V_127 ) ;
V_41 = F_57 ( V_121 , V_128 , V_127 , V_131 , sizeof( * V_130 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_62 ( V_14 -> V_68 , V_130 -> V_132 ) ;
if ( V_41 ) {
F_56 ( L_4 ) ;
return V_41 ;
}
V_14 -> V_63 = V_130 -> V_63 ;
V_14 -> V_64 = V_130 -> V_64 ;
V_14 -> V_132 = V_130 -> V_132 ;
V_14 -> V_57 = V_130 -> V_57 ;
V_14 -> V_58 = 0 ;
V_14 -> V_25 = V_130 -> V_25 ;
V_14 -> V_43 = V_130 -> V_43 ;
if ( V_14 -> V_57 )
V_14 -> V_59 = ~ 0 ;
if ( V_121 [ V_133 ] )
F_50 ( V_39 , V_121 [ V_133 ] ) ;
if ( V_121 [ V_134 ] ) {
V_41 = F_41 ( V_39 , V_121 [ V_134 ] ) ;
if ( V_41 )
return V_41 ;
}
if ( V_121 [ V_135 ] )
F_51 ( V_39 , V_121 [ V_135 ] ) ;
if ( V_121 [ V_136 ] )
F_52 ( V_39 , V_121 [ V_136 ] ) ;
V_14 -> V_23 = V_24 ;
if ( V_121 [ V_137 ] )
V_41 = F_53 ( V_39 , V_121 [ V_137 ] ) ;
return V_41 ;
}
static int F_63 ( struct V_2 * V_138 , struct V_38 * V_39 )
{
struct V_139 * V_14 = F_10 ( V_39 ) ;
struct V_140 * V_141 = & V_39 -> V_14 ;
T_4 V_142 = V_1 ( V_138 ) -> V_67 ;
struct V_2 * V_3 ;
if ( F_64 ( F_65 ( V_141 ) < V_14 -> V_132 ) ) {
if ( F_64 ( F_66 ( V_141 ) || V_142 >= V_14 -> V_143 ) ) {
V_14 -> V_143 = V_142 ;
return F_67 ( V_138 , V_39 ) ;
}
F_68 (list, skb) {
const struct V_1 * V_4 = V_1 ( V_3 ) ;
if ( V_142 >= V_4 -> V_67 )
break;
}
F_69 ( V_141 , V_3 , V_138 ) ;
V_39 -> V_45 . V_69 += F_22 ( V_138 ) ;
return V_47 ;
}
return F_70 ( V_138 , V_39 ) ;
}
static int F_71 ( struct V_38 * V_39 , struct V_82 * V_127 )
{
struct V_139 * V_14 = F_10 ( V_39 ) ;
if ( V_127 ) {
struct V_144 * V_145 = F_43 ( V_127 ) ;
if ( F_42 ( V_127 ) < sizeof( * V_145 ) )
return - V_90 ;
V_14 -> V_132 = V_145 -> V_132 ;
} else
V_14 -> V_132 = F_72 ( T_1 , F_73 ( V_39 ) -> V_146 , 1 ) ;
V_14 -> V_143 = V_147 ;
return 0 ;
}
static int F_74 ( struct V_38 * V_39 , struct V_2 * V_3 )
{
struct V_139 * V_14 = F_10 ( V_39 ) ;
struct V_144 V_127 = { . V_132 = V_14 -> V_132 } ;
F_75 ( V_3 , V_148 , sizeof( V_127 ) , & V_127 ) ;
return V_3 -> V_72 ;
V_149:
return - 1 ;
}
static int F_76 ( struct V_38 * V_39 , struct V_82 * V_127 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
int V_41 ;
if ( ! V_127 )
return - V_90 ;
F_77 ( & V_14 -> V_80 , V_39 ) ;
V_14 -> V_23 = V_24 ;
V_14 -> V_68 = F_78 ( V_39 -> V_150 , & V_151 ,
F_79 ( V_39 -> V_152 , 1 ) ) ;
if ( ! V_14 -> V_68 ) {
F_80 ( L_5 ) ;
return - V_94 ;
}
V_41 = F_61 ( V_39 , V_127 ) ;
if ( V_41 ) {
F_56 ( L_6 ) ;
F_81 ( V_14 -> V_68 ) ;
}
return V_41 ;
}
static void F_82 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
F_36 ( & V_14 -> V_80 ) ;
F_81 ( V_14 -> V_68 ) ;
F_37 ( V_14 -> V_66 ) ;
}
static int F_83 ( const struct V_13 * V_14 ,
struct V_2 * V_3 )
{
struct V_82 * V_153 ;
V_153 = F_84 ( V_3 , V_137 ) ;
if ( V_153 == NULL )
goto V_149;
switch ( V_14 -> V_23 ) {
case V_24 :
F_85 ( V_3 , V_153 ) ;
return 0 ;
case V_27 : {
struct V_108 V_109 = {
. V_110 = V_14 -> V_16 . V_19 ,
. V_111 = V_14 -> V_16 . V_22 ,
. V_112 = V_14 -> V_16 . V_21 ,
. V_113 = V_14 -> V_16 . V_18 ,
. V_114 = V_14 -> V_16 . V_20 ,
} ;
F_75 ( V_3 , V_107 , sizeof( V_109 ) , & V_109 ) ;
break;
}
case V_28 : {
struct V_116 V_117 = {
. V_118 = V_14 -> V_16 . V_19 ,
. V_101 = V_14 -> V_16 . V_22 ,
. V_119 = V_14 -> V_16 . V_21 ,
. V_120 = V_14 -> V_16 . V_18 ,
} ;
F_75 ( V_3 , V_115 , sizeof( V_117 ) , & V_117 ) ;
break;
}
}
F_86 ( V_3 , V_153 ) ;
return 0 ;
V_149:
F_85 ( V_3 , V_153 ) ;
return - 1 ;
}
static int F_87 ( struct V_38 * V_39 , struct V_2 * V_3 )
{
const struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_82 * V_123 = (struct V_82 * ) F_88 ( V_3 ) ;
struct V_129 V_130 ;
struct V_95 V_154 ;
struct V_100 V_59 ;
struct V_104 V_52 ;
V_130 . V_63 = V_14 -> V_63 ;
V_130 . V_64 = V_14 -> V_64 ;
V_130 . V_132 = V_14 -> V_132 ;
V_130 . V_25 = V_14 -> V_25 ;
V_130 . V_57 = V_14 -> V_57 ;
V_130 . V_43 = V_14 -> V_43 ;
F_75 ( V_3 , V_148 , sizeof( V_130 ) , & V_130 ) ;
V_154 . V_97 = V_14 -> V_65 . V_9 ;
V_154 . V_98 = V_14 -> V_26 . V_9 ;
V_154 . V_99 = V_14 -> V_44 . V_9 ;
F_75 ( V_3 , V_133 , sizeof( V_154 ) , & V_154 ) ;
V_59 . V_102 = V_14 -> V_59 ;
V_59 . V_103 = V_14 -> V_60 . V_9 ;
F_75 ( V_3 , V_135 , sizeof( V_59 ) , & V_59 ) ;
V_52 . V_102 = V_14 -> V_52 ;
V_52 . V_103 = V_14 -> V_53 . V_9 ;
F_75 ( V_3 , V_136 , sizeof( V_52 ) , & V_52 ) ;
if ( F_83 ( V_14 , V_3 ) != 0 )
goto V_149;
return F_86 ( V_3 , V_123 ) ;
V_149:
F_89 ( V_3 , V_123 ) ;
return - 1 ;
}
static int F_90 ( struct V_38 * V_39 , unsigned long V_155 ,
struct V_2 * V_3 , struct V_156 * V_157 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
if ( V_155 != 1 )
return - V_158 ;
V_157 -> V_159 |= F_91 ( 1 ) ;
V_157 -> V_160 = V_14 -> V_68 -> V_152 ;
return 0 ;
}
static int F_92 ( struct V_38 * V_39 , unsigned long V_161 , struct V_38 * V_162 ,
struct V_38 * * V_163 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
if ( V_162 == NULL )
V_162 = & V_164 ;
F_93 ( V_39 ) ;
* V_163 = V_14 -> V_68 ;
V_14 -> V_68 = V_162 ;
F_94 ( * V_163 , ( * V_163 ) -> V_14 . V_71 ) ;
F_35 ( * V_163 ) ;
F_95 ( V_39 ) ;
return 0 ;
}
static struct V_38 * F_96 ( struct V_38 * V_39 , unsigned long V_161 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
return V_14 -> V_68 ;
}
static unsigned long F_97 ( struct V_38 * V_39 , T_1 V_165 )
{
return 1 ;
}
static void F_98 ( struct V_38 * V_39 , unsigned long V_161 )
{
}
static void F_99 ( struct V_38 * V_39 , struct V_166 * V_167 )
{
if ( ! V_167 -> V_168 ) {
if ( V_167 -> V_42 >= V_167 -> V_169 )
if ( V_167 -> V_170 ( V_39 , 1 , V_167 ) < 0 ) {
V_167 -> V_168 = 1 ;
return;
}
V_167 -> V_42 ++ ;
}
}
static int T_8 F_100 ( void )
{
F_56 ( L_7 V_171 L_8 ) ;
return F_101 ( & V_172 ) ;
}
static void T_9 F_102 ( void )
{
F_103 ( & V_172 ) ;
}
