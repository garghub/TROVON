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
V_81 = F_44 ( V_88 , V_92 ) ;
if ( ! V_81 )
V_81 = F_45 ( V_88 ) ;
if ( ! V_81 )
return - V_93 ;
V_81 -> V_36 = V_84 ;
for ( V_87 = 0 ; V_87 < V_84 ; V_87 ++ )
V_81 -> V_35 [ V_87 ] = V_6 [ V_87 ] ;
V_86 = F_46 ( V_39 ) ;
F_47 ( V_86 ) ;
F_37 ( V_14 -> V_66 ) ;
V_14 -> V_66 = V_81 ;
F_48 ( V_86 ) ;
return 0 ;
}
static void F_49 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_94 * V_95 = F_43 ( V_83 ) ;
F_2 ( & V_14 -> V_65 , V_95 -> V_96 ) ;
F_2 ( & V_14 -> V_26 , V_95 -> V_97 ) ;
F_2 ( & V_14 -> V_44 , V_95 -> V_98 ) ;
}
static void F_50 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_99 * V_100 = F_43 ( V_83 ) ;
V_14 -> V_59 = V_100 -> V_101 ;
F_2 ( & V_14 -> V_60 , V_100 -> V_102 ) ;
}
static void F_51 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_103 * V_100 = F_43 ( V_83 ) ;
V_14 -> V_52 = V_100 -> V_101 ;
F_2 ( & V_14 -> V_53 , V_100 -> V_102 ) ;
}
static int F_52 ( struct V_38 * V_39 , const struct V_82 * V_83 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
const struct V_82 * V_104 ;
int V_105 ;
F_53 (la, attr, rem) {
T_7 type = F_54 ( V_104 ) ;
switch( type ) {
case V_106 : {
const struct V_107 * V_108 = F_43 ( V_104 ) ;
if ( F_42 ( V_104 ) != sizeof( struct V_107 ) ) {
F_55 ( L_1 ) ;
return - V_90 ;
}
V_14 -> V_23 = V_27 ;
V_14 -> V_16 . V_8 = 1 ;
V_14 -> V_16 . V_19 = V_108 -> V_109 ;
V_14 -> V_16 . V_22 = V_108 -> V_110 ;
V_14 -> V_16 . V_21 = V_108 -> V_111 ;
V_14 -> V_16 . V_18 = V_108 -> V_112 ;
V_14 -> V_16 . V_20 = V_108 -> V_113 ;
break;
}
case V_114 : {
const struct V_115 * V_116 = F_43 ( V_104 ) ;
if ( F_42 ( V_104 ) != sizeof( struct V_115 ) ) {
F_55 ( L_1 ) ;
return - V_90 ;
}
V_14 -> V_23 = V_28 ;
V_14 -> V_16 . V_8 = 1 ;
V_14 -> V_16 . V_19 = V_116 -> V_117 ;
V_14 -> V_16 . V_22 = V_116 -> V_100 ;
V_14 -> V_16 . V_21 = V_116 -> V_118 ;
V_14 -> V_16 . V_18 = V_116 -> V_119 ;
break;
}
default:
F_55 ( L_2 , type ) ;
return - V_90 ;
}
}
return 0 ;
}
static int F_56 ( struct V_82 * V_120 [] , int V_121 , struct V_82 * V_122 ,
const struct V_123 * V_124 , int V_72 )
{
int V_125 = F_42 ( V_122 ) - F_57 ( V_72 ) ;
if ( V_125 < 0 ) {
F_55 ( L_3 , V_125 ) ;
return - V_90 ;
}
if ( V_125 >= F_58 ( 0 ) )
return F_59 ( V_120 , V_121 , F_43 ( V_122 ) + F_57 ( V_72 ) ,
V_125 , V_124 ) ;
memset ( V_120 , 0 , sizeof( struct V_82 * ) * ( V_121 + 1 ) ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 , struct V_82 * V_126 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_82 * V_120 [ V_127 + 1 ] ;
struct V_128 * V_129 ;
int V_41 ;
if ( V_126 == NULL )
return - V_90 ;
V_129 = F_43 ( V_126 ) ;
V_41 = F_56 ( V_120 , V_127 , V_126 , V_130 , sizeof( * V_129 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_61 ( V_14 -> V_68 , V_129 -> V_131 ) ;
if ( V_41 ) {
F_55 ( L_4 ) ;
return V_41 ;
}
V_14 -> V_63 = V_129 -> V_63 ;
V_14 -> V_64 = V_129 -> V_64 ;
V_14 -> V_131 = V_129 -> V_131 ;
V_14 -> V_57 = V_129 -> V_57 ;
V_14 -> V_58 = 0 ;
V_14 -> V_25 = V_129 -> V_25 ;
V_14 -> V_43 = V_129 -> V_43 ;
if ( V_14 -> V_57 )
V_14 -> V_59 = ~ 0 ;
if ( V_120 [ V_132 ] )
F_49 ( V_39 , V_120 [ V_132 ] ) ;
if ( V_120 [ V_133 ] ) {
V_41 = F_41 ( V_39 , V_120 [ V_133 ] ) ;
if ( V_41 )
return V_41 ;
}
if ( V_120 [ V_134 ] )
F_50 ( V_39 , V_120 [ V_134 ] ) ;
if ( V_120 [ V_135 ] )
F_51 ( V_39 , V_120 [ V_135 ] ) ;
V_14 -> V_23 = V_24 ;
if ( V_120 [ V_136 ] )
V_41 = F_52 ( V_39 , V_120 [ V_136 ] ) ;
return V_41 ;
}
static int F_62 ( struct V_2 * V_137 , struct V_38 * V_39 )
{
struct V_138 * V_14 = F_10 ( V_39 ) ;
struct V_139 * V_140 = & V_39 -> V_14 ;
T_4 V_141 = V_1 ( V_137 ) -> V_67 ;
struct V_2 * V_3 ;
if ( F_63 ( F_64 ( V_140 ) < V_14 -> V_131 ) ) {
if ( F_63 ( F_65 ( V_140 ) || V_141 >= V_14 -> V_142 ) ) {
V_14 -> V_142 = V_141 ;
return F_66 ( V_137 , V_39 ) ;
}
F_67 (list, skb) {
const struct V_1 * V_4 = V_1 ( V_3 ) ;
if ( V_141 >= V_4 -> V_67 )
break;
}
F_68 ( V_140 , V_3 , V_137 ) ;
V_39 -> V_45 . V_69 += F_22 ( V_137 ) ;
return V_47 ;
}
return F_69 ( V_137 , V_39 ) ;
}
static int F_70 ( struct V_38 * V_39 , struct V_82 * V_126 )
{
struct V_138 * V_14 = F_10 ( V_39 ) ;
if ( V_126 ) {
struct V_143 * V_144 = F_43 ( V_126 ) ;
if ( F_42 ( V_126 ) < sizeof( * V_144 ) )
return - V_90 ;
V_14 -> V_131 = V_144 -> V_131 ;
} else
V_14 -> V_131 = F_71 ( T_1 , F_72 ( V_39 ) -> V_145 , 1 ) ;
V_14 -> V_142 = V_146 ;
return 0 ;
}
static int F_73 ( struct V_38 * V_39 , struct V_2 * V_3 )
{
struct V_138 * V_14 = F_10 ( V_39 ) ;
struct V_143 V_126 = { . V_131 = V_14 -> V_131 } ;
F_74 ( V_3 , V_147 , sizeof( V_126 ) , & V_126 ) ;
return V_3 -> V_72 ;
V_148:
return - 1 ;
}
static int F_75 ( struct V_38 * V_39 , struct V_82 * V_126 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
int V_41 ;
if ( ! V_126 )
return - V_90 ;
F_76 ( & V_14 -> V_80 , V_39 ) ;
V_14 -> V_23 = V_24 ;
V_14 -> V_68 = F_77 ( V_39 -> V_149 , & V_150 ,
F_78 ( V_39 -> V_151 , 1 ) ) ;
if ( ! V_14 -> V_68 ) {
F_79 ( L_5 ) ;
return - V_93 ;
}
V_41 = F_60 ( V_39 , V_126 ) ;
if ( V_41 ) {
F_55 ( L_6 ) ;
F_80 ( V_14 -> V_68 ) ;
}
return V_41 ;
}
static void F_81 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
F_36 ( & V_14 -> V_80 ) ;
F_80 ( V_14 -> V_68 ) ;
F_37 ( V_14 -> V_66 ) ;
}
static int F_82 ( const struct V_13 * V_14 ,
struct V_2 * V_3 )
{
struct V_82 * V_152 ;
V_152 = F_83 ( V_3 , V_136 ) ;
if ( V_152 == NULL )
goto V_148;
switch ( V_14 -> V_23 ) {
case V_24 :
F_84 ( V_3 , V_152 ) ;
return 0 ;
case V_27 : {
struct V_107 V_108 = {
. V_109 = V_14 -> V_16 . V_19 ,
. V_110 = V_14 -> V_16 . V_22 ,
. V_111 = V_14 -> V_16 . V_21 ,
. V_112 = V_14 -> V_16 . V_18 ,
. V_113 = V_14 -> V_16 . V_20 ,
} ;
F_74 ( V_3 , V_106 , sizeof( V_108 ) , & V_108 ) ;
break;
}
case V_28 : {
struct V_115 V_116 = {
. V_117 = V_14 -> V_16 . V_19 ,
. V_100 = V_14 -> V_16 . V_22 ,
. V_118 = V_14 -> V_16 . V_21 ,
. V_119 = V_14 -> V_16 . V_18 ,
} ;
F_74 ( V_3 , V_114 , sizeof( V_116 ) , & V_116 ) ;
break;
}
}
F_85 ( V_3 , V_152 ) ;
return 0 ;
V_148:
F_84 ( V_3 , V_152 ) ;
return - 1 ;
}
static int F_86 ( struct V_38 * V_39 , struct V_2 * V_3 )
{
const struct V_13 * V_14 = F_10 ( V_39 ) ;
struct V_82 * V_122 = (struct V_82 * ) F_87 ( V_3 ) ;
struct V_128 V_129 ;
struct V_94 V_153 ;
struct V_99 V_59 ;
struct V_103 V_52 ;
V_129 . V_63 = V_14 -> V_63 ;
V_129 . V_64 = V_14 -> V_64 ;
V_129 . V_131 = V_14 -> V_131 ;
V_129 . V_25 = V_14 -> V_25 ;
V_129 . V_57 = V_14 -> V_57 ;
V_129 . V_43 = V_14 -> V_43 ;
F_74 ( V_3 , V_147 , sizeof( V_129 ) , & V_129 ) ;
V_153 . V_96 = V_14 -> V_65 . V_9 ;
V_153 . V_97 = V_14 -> V_26 . V_9 ;
V_153 . V_98 = V_14 -> V_44 . V_9 ;
F_74 ( V_3 , V_132 , sizeof( V_153 ) , & V_153 ) ;
V_59 . V_101 = V_14 -> V_59 ;
V_59 . V_102 = V_14 -> V_60 . V_9 ;
F_74 ( V_3 , V_134 , sizeof( V_59 ) , & V_59 ) ;
V_52 . V_101 = V_14 -> V_52 ;
V_52 . V_102 = V_14 -> V_53 . V_9 ;
F_74 ( V_3 , V_135 , sizeof( V_52 ) , & V_52 ) ;
if ( F_82 ( V_14 , V_3 ) != 0 )
goto V_148;
return F_85 ( V_3 , V_122 ) ;
V_148:
F_88 ( V_3 , V_122 ) ;
return - 1 ;
}
static int F_89 ( struct V_38 * V_39 , unsigned long V_154 ,
struct V_2 * V_3 , struct V_155 * V_156 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
if ( V_154 != 1 )
return - V_157 ;
V_156 -> V_158 |= F_90 ( 1 ) ;
V_156 -> V_159 = V_14 -> V_68 -> V_151 ;
return 0 ;
}
static int F_91 ( struct V_38 * V_39 , unsigned long V_160 , struct V_38 * V_161 ,
struct V_38 * * V_162 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
if ( V_161 == NULL )
V_161 = & V_163 ;
F_92 ( V_39 ) ;
* V_162 = V_14 -> V_68 ;
V_14 -> V_68 = V_161 ;
F_93 ( * V_162 , ( * V_162 ) -> V_14 . V_71 ) ;
F_35 ( * V_162 ) ;
F_94 ( V_39 ) ;
return 0 ;
}
static struct V_38 * F_95 ( struct V_38 * V_39 , unsigned long V_160 )
{
struct V_13 * V_14 = F_10 ( V_39 ) ;
return V_14 -> V_68 ;
}
static unsigned long F_96 ( struct V_38 * V_39 , T_1 V_164 )
{
return 1 ;
}
static void F_97 ( struct V_38 * V_39 , unsigned long V_160 )
{
}
static void F_98 ( struct V_38 * V_39 , struct V_165 * V_166 )
{
if ( ! V_166 -> V_167 ) {
if ( V_166 -> V_42 >= V_166 -> V_168 )
if ( V_166 -> V_169 ( V_39 , 1 , V_166 ) < 0 ) {
V_166 -> V_167 = 1 ;
return;
}
V_166 -> V_42 ++ ;
}
}
static int T_8 F_99 ( void )
{
F_55 ( L_7 V_170 L_8 ) ;
return F_100 ( & V_171 ) ;
}
static void T_9 F_101 ( void )
{
F_102 ( & V_171 ) ;
}
