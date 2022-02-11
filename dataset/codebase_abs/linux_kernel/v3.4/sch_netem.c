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
F_31 ( V_3 ) ) )
return F_32 ( V_3 , V_47 ) ;
V_3 -> V_4 [ F_4 () % F_33 ( V_3 ) ] ^= 1 << ( F_4 () % 8 ) ;
}
V_56 = V_1 ( V_3 ) ;
if ( V_12 -> V_71 == 0 ||
V_12 -> V_72 < V_12 -> V_71 - 1 ||
V_12 -> V_73 < F_5 ( & V_12 -> V_74 ) ) {
T_4 V_75 ;
T_3 V_76 ;
V_76 = F_9 ( V_12 -> V_77 , V_12 -> V_78 ,
& V_12 -> V_79 , V_12 -> V_80 ) ;
V_75 = F_34 () ;
if ( V_12 -> V_44 ) {
struct V_48 * V_49 = & V_47 -> V_12 ;
V_76 += F_10 ( V_3 -> V_36 , V_12 ) ;
if ( ! F_35 ( V_49 ) ) {
V_76 -= V_75 - V_1 ( F_36 ( V_49 ) ) -> V_51 ;
V_75 = V_1 ( F_17 ( V_49 ) ) -> V_51 ;
}
}
V_56 -> V_51 = V_75 + V_76 ;
++ V_12 -> V_72 ;
V_58 = F_14 ( V_3 , V_47 ) ;
} else {
V_56 -> V_51 = F_34 () ;
V_12 -> V_72 = 0 ;
F_37 ( & V_47 -> V_12 , V_3 ) ;
V_47 -> V_53 . V_54 += F_21 ( V_3 ) ;
V_47 -> V_53 . V_81 ++ ;
V_58 = V_55 ;
}
if ( V_58 != V_55 ) {
if ( F_38 ( V_58 ) ) {
V_47 -> V_53 . V_62 ++ ;
return V_58 ;
}
}
return V_55 ;
}
static unsigned int F_39 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
unsigned int V_36 ;
V_36 = F_40 ( V_47 ) ;
if ( ! V_36 && V_12 -> V_82 && V_12 -> V_82 -> V_83 -> V_84 )
V_36 = V_12 -> V_82 -> V_83 -> V_84 ( V_12 -> V_82 ) ;
if ( V_36 )
V_47 -> V_53 . V_62 ++ ;
return V_36 ;
}
static struct V_2 * F_41 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_2 * V_3 ;
if ( F_42 ( V_47 ) )
return NULL ;
V_85:
V_3 = F_43 ( V_47 ) ;
if ( V_3 ) {
const struct V_1 * V_56 = V_1 ( V_3 ) ;
if ( V_56 -> V_51 <= F_34 () ) {
F_44 ( V_3 , & V_47 -> V_12 ) ;
V_47 -> V_53 . V_54 -= F_21 ( V_3 ) ;
#ifdef F_45
if ( F_46 ( V_3 -> V_86 ) & V_87 )
V_3 -> V_88 . V_89 = 0 ;
#endif
if ( V_12 -> V_82 ) {
int V_90 = F_47 ( V_3 , V_12 -> V_82 ) ;
if ( F_48 ( V_90 != V_55 ) ) {
if ( F_38 ( V_90 ) ) {
V_47 -> V_53 . V_62 ++ ;
F_49 ( V_47 , 1 ) ;
}
}
goto V_85;
}
V_91:
F_50 ( V_47 ) ;
F_51 ( V_47 , V_3 ) ;
return V_3 ;
}
if ( V_12 -> V_82 ) {
V_3 = V_12 -> V_82 -> V_83 -> V_92 ( V_12 -> V_82 ) ;
if ( V_3 )
goto V_91;
}
F_52 ( & V_12 -> V_93 , V_56 -> V_51 ) ;
}
if ( V_12 -> V_82 ) {
V_3 = V_12 -> V_82 -> V_83 -> V_92 ( V_12 -> V_82 ) ;
if ( V_3 )
goto V_91;
}
return NULL ;
}
static void F_53 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_54 ( V_47 ) ;
if ( V_12 -> V_82 )
F_55 ( V_12 -> V_82 ) ;
F_56 ( & V_12 -> V_93 ) ;
}
static void F_57 ( struct V_29 * V_94 )
{
if ( V_94 ) {
if ( F_58 ( V_94 ) )
F_59 ( V_94 ) ;
else
F_60 ( V_94 ) ;
}
}
static int F_61 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
T_5 V_97 = F_62 ( V_96 ) / sizeof( V_98 ) ;
const V_98 * V_4 = F_63 ( V_96 ) ;
T_6 * V_99 ;
struct V_29 * V_94 ;
int V_100 ;
T_5 V_101 ;
if ( V_97 > V_102 )
return - V_103 ;
V_101 = sizeof( struct V_29 ) + V_97 * sizeof( V_104 ) ;
V_94 = F_64 ( V_101 , V_105 | V_106 ) ;
if ( ! V_94 )
V_94 = F_65 ( V_101 ) ;
if ( ! V_94 )
return - V_107 ;
V_94 -> V_34 = V_97 ;
for ( V_100 = 0 ; V_100 < V_97 ; V_100 ++ )
V_94 -> V_33 [ V_100 ] = V_4 [ V_100 ] ;
V_99 = F_66 ( V_47 ) ;
F_67 ( V_99 ) ;
F_68 ( V_12 -> V_80 , V_94 ) ;
F_69 ( V_99 ) ;
F_57 ( V_94 ) ;
return 0 ;
}
static void F_70 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_108 * V_109 = F_63 ( V_96 ) ;
F_3 ( & V_12 -> V_79 , V_109 -> V_110 ) ;
F_3 ( & V_12 -> V_24 , V_109 -> V_111 ) ;
F_3 ( & V_12 -> V_61 , V_109 -> V_112 ) ;
}
static void F_71 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_113 * V_114 = F_63 ( V_96 ) ;
V_12 -> V_73 = V_114 -> V_115 ;
F_3 ( & V_12 -> V_74 , V_114 -> V_116 ) ;
}
static void F_72 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_117 * V_114 = F_63 ( V_96 ) ;
V_12 -> V_67 = V_114 -> V_115 ;
F_3 ( & V_12 -> V_68 , V_114 -> V_116 ) ;
}
static void F_73 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_118 * V_114 = F_63 ( V_96 ) ;
V_12 -> V_44 = V_114 -> V_44 ;
V_12 -> V_38 = V_114 -> V_38 ;
V_12 -> V_39 = V_114 -> V_39 ;
if ( V_12 -> V_39 )
V_12 -> V_41 = F_74 ( V_12 -> V_39 ) ;
V_12 -> V_42 = V_114 -> V_42 ;
}
static int F_75 ( struct V_46 * V_47 , const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
const struct V_95 * V_119 ;
int V_120 ;
F_76 (la, attr, rem) {
T_7 type = F_77 ( V_119 ) ;
switch( type ) {
case V_121 : {
const struct V_122 * V_123 = F_63 ( V_119 ) ;
if ( F_62 ( V_119 ) < sizeof( struct V_122 ) ) {
F_78 ( L_1 ) ;
return - V_103 ;
}
V_12 -> V_21 = V_25 ;
V_12 -> V_14 . V_6 = 1 ;
V_12 -> V_14 . V_17 = V_123 -> V_124 ;
V_12 -> V_14 . V_20 = V_123 -> V_125 ;
V_12 -> V_14 . V_19 = V_123 -> V_126 ;
V_12 -> V_14 . V_16 = V_123 -> V_127 ;
V_12 -> V_14 . V_18 = V_123 -> V_128 ;
break;
}
case V_129 : {
const struct V_130 * V_131 = F_63 ( V_119 ) ;
if ( F_62 ( V_119 ) < sizeof( struct V_130 ) ) {
F_78 ( L_2 ) ;
return - V_103 ;
}
V_12 -> V_21 = V_26 ;
V_12 -> V_14 . V_6 = 1 ;
V_12 -> V_14 . V_17 = V_131 -> V_132 ;
V_12 -> V_14 . V_20 = V_131 -> V_114 ;
V_12 -> V_14 . V_19 = V_131 -> V_133 ;
V_12 -> V_14 . V_16 = V_131 -> V_134 ;
break;
}
default:
F_78 ( L_3 , type ) ;
return - V_103 ;
}
}
return 0 ;
}
static int F_79 ( struct V_95 * V_135 [] , int V_136 , struct V_95 * V_137 ,
const struct V_138 * V_139 , int V_36 )
{
int V_140 = F_62 ( V_137 ) - F_80 ( V_36 ) ;
if ( V_140 < 0 ) {
F_78 ( L_4 , V_140 ) ;
return - V_103 ;
}
if ( V_140 >= F_81 ( 0 ) )
return F_82 ( V_135 , V_136 , F_63 ( V_137 ) + F_80 ( V_36 ) ,
V_140 , V_139 ) ;
memset ( V_135 , 0 , sizeof( struct V_95 * ) * ( V_136 + 1 ) ) ;
return 0 ;
}
static int F_83 ( struct V_46 * V_47 , struct V_95 * V_141 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_95 * V_135 [ V_142 + 1 ] ;
struct V_143 * V_144 ;
int V_58 ;
if ( V_141 == NULL )
return - V_103 ;
V_144 = F_63 ( V_141 ) ;
V_58 = F_79 ( V_135 , V_142 , V_141 , V_145 , sizeof( * V_144 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_47 -> V_52 = V_144 -> V_52 ;
V_12 -> V_77 = V_144 -> V_77 ;
V_12 -> V_78 = V_144 -> V_78 ;
V_12 -> V_52 = V_144 -> V_52 ;
V_12 -> V_71 = V_144 -> V_71 ;
V_12 -> V_72 = 0 ;
V_12 -> V_23 = V_144 -> V_23 ;
V_12 -> V_60 = V_144 -> V_60 ;
if ( V_12 -> V_71 )
V_12 -> V_73 = ~ 0 ;
if ( V_135 [ V_146 ] )
F_70 ( V_47 , V_135 [ V_146 ] ) ;
if ( V_135 [ V_147 ] ) {
V_58 = F_61 ( V_47 , V_135 [ V_147 ] ) ;
if ( V_58 )
return V_58 ;
}
if ( V_135 [ V_148 ] )
F_71 ( V_47 , V_135 [ V_148 ] ) ;
if ( V_135 [ V_149 ] )
F_72 ( V_47 , V_135 [ V_149 ] ) ;
if ( V_135 [ V_150 ] )
F_73 ( V_47 , V_135 [ V_150 ] ) ;
V_12 -> V_21 = V_22 ;
if ( V_135 [ V_151 ] )
V_58 = F_75 ( V_47 , V_135 [ V_151 ] ) ;
return V_58 ;
}
static int F_84 ( struct V_46 * V_47 , struct V_95 * V_141 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
int V_58 ;
if ( ! V_141 )
return - V_103 ;
F_85 ( & V_12 -> V_93 , V_47 ) ;
V_12 -> V_21 = V_22 ;
V_58 = F_83 ( V_47 , V_141 ) ;
if ( V_58 )
F_78 ( L_5 ) ;
return V_58 ;
}
static void F_86 ( struct V_46 * V_47 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_56 ( & V_12 -> V_93 ) ;
if ( V_12 -> V_82 )
F_87 ( V_12 -> V_82 ) ;
F_57 ( V_12 -> V_80 ) ;
}
static int F_88 ( const struct V_11 * V_12 ,
struct V_2 * V_3 )
{
struct V_95 * V_152 ;
V_152 = F_89 ( V_3 , V_151 ) ;
if ( V_152 == NULL )
goto V_153;
switch ( V_12 -> V_21 ) {
case V_22 :
F_90 ( V_3 , V_152 ) ;
return 0 ;
case V_25 : {
struct V_122 V_123 = {
. V_124 = V_12 -> V_14 . V_17 ,
. V_125 = V_12 -> V_14 . V_20 ,
. V_126 = V_12 -> V_14 . V_19 ,
. V_127 = V_12 -> V_14 . V_16 ,
. V_128 = V_12 -> V_14 . V_18 ,
} ;
F_91 ( V_3 , V_121 , sizeof( V_123 ) , & V_123 ) ;
break;
}
case V_26 : {
struct V_130 V_131 = {
. V_132 = V_12 -> V_14 . V_17 ,
. V_114 = V_12 -> V_14 . V_20 ,
. V_133 = V_12 -> V_14 . V_19 ,
. V_134 = V_12 -> V_14 . V_16 ,
} ;
F_91 ( V_3 , V_129 , sizeof( V_131 ) , & V_131 ) ;
break;
}
}
F_92 ( V_3 , V_152 ) ;
return 0 ;
V_153:
F_90 ( V_3 , V_152 ) ;
return - 1 ;
}
static int F_93 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
const struct V_11 * V_12 = F_24 ( V_47 ) ;
struct V_95 * V_137 = (struct V_95 * ) F_94 ( V_3 ) ;
struct V_143 V_144 ;
struct V_108 V_154 ;
struct V_113 V_73 ;
struct V_117 V_67 ;
struct V_118 V_44 ;
V_144 . V_77 = V_12 -> V_77 ;
V_144 . V_78 = V_12 -> V_78 ;
V_144 . V_52 = V_12 -> V_52 ;
V_144 . V_23 = V_12 -> V_23 ;
V_144 . V_71 = V_12 -> V_71 ;
V_144 . V_60 = V_12 -> V_60 ;
F_91 ( V_3 , V_155 , sizeof( V_144 ) , & V_144 ) ;
V_154 . V_110 = V_12 -> V_79 . V_7 ;
V_154 . V_111 = V_12 -> V_24 . V_7 ;
V_154 . V_112 = V_12 -> V_61 . V_7 ;
F_91 ( V_3 , V_146 , sizeof( V_154 ) , & V_154 ) ;
V_73 . V_115 = V_12 -> V_73 ;
V_73 . V_116 = V_12 -> V_74 . V_7 ;
F_91 ( V_3 , V_148 , sizeof( V_73 ) , & V_73 ) ;
V_67 . V_115 = V_12 -> V_67 ;
V_67 . V_116 = V_12 -> V_68 . V_7 ;
F_91 ( V_3 , V_149 , sizeof( V_67 ) , & V_67 ) ;
V_44 . V_44 = V_12 -> V_44 ;
V_44 . V_38 = V_12 -> V_38 ;
V_44 . V_39 = V_12 -> V_39 ;
V_44 . V_42 = V_12 -> V_42 ;
F_91 ( V_3 , V_150 , sizeof( V_44 ) , & V_44 ) ;
if ( F_88 ( V_12 , V_3 ) != 0 )
goto V_153;
return F_92 ( V_3 , V_137 ) ;
V_153:
F_95 ( V_3 , V_137 ) ;
return - 1 ;
}
static int F_96 ( struct V_46 * V_47 , unsigned long V_156 ,
struct V_2 * V_3 , struct V_157 * V_158 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
if ( V_156 != 1 || ! V_12 -> V_82 )
return - V_159 ;
V_158 -> V_160 |= F_97 ( 1 ) ;
V_158 -> V_161 = V_12 -> V_82 -> V_162 ;
return 0 ;
}
static int F_98 ( struct V_46 * V_47 , unsigned long V_163 , struct V_46 * V_164 ,
struct V_46 * * V_165 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
F_99 ( V_47 ) ;
* V_165 = V_12 -> V_82 ;
V_12 -> V_82 = V_164 ;
if ( * V_165 ) {
F_49 ( * V_165 , ( * V_165 ) -> V_12 . V_166 ) ;
F_55 ( * V_165 ) ;
}
F_100 ( V_47 ) ;
return 0 ;
}
static struct V_46 * F_101 ( struct V_46 * V_47 , unsigned long V_163 )
{
struct V_11 * V_12 = F_24 ( V_47 ) ;
return V_12 -> V_82 ;
}
static unsigned long F_102 ( struct V_46 * V_47 , T_1 V_167 )
{
return 1 ;
}
static void F_103 ( struct V_46 * V_47 , unsigned long V_163 )
{
}
static void F_104 ( struct V_46 * V_47 , struct V_168 * V_169 )
{
if ( ! V_169 -> V_170 ) {
if ( V_169 -> V_59 >= V_169 -> V_171 )
if ( V_169 -> V_172 ( V_47 , 1 , V_169 ) < 0 ) {
V_169 -> V_170 = 1 ;
return;
}
V_169 -> V_59 ++ ;
}
}
static int T_8 F_105 ( void )
{
F_78 ( L_6 V_173 L_7 ) ;
return F_106 ( & V_174 ) ;
}
static void T_9 F_107 ( void )
{
F_108 ( & V_174 ) ;
}
