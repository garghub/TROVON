static struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( F_3 ( struct V_2 , V_4 ) != 0 ) ;
F_2 ( F_3 ( struct V_2 , V_5 ) !=
F_3 ( struct V_2 , V_4 ) + sizeof( V_3 -> V_4 ) ) ;
F_2 ( F_3 ( struct V_2 , V_6 ) !=
F_3 ( struct V_2 , V_5 ) + sizeof( V_3 -> V_5 ) ) ;
F_2 ( sizeof( struct V_1 ) > sizeof( V_3 -> V_4 ) +
sizeof( V_3 -> V_5 ) +
sizeof( V_3 -> V_6 ) ) ;
return (struct V_1 * ) & V_3 -> V_4 ;
}
static struct V_2 * F_4 ( struct V_1 * V_7 )
{
return (struct V_2 * ) V_7 ;
}
static inline struct V_8 * V_8 ( struct V_2 * V_3 )
{
F_5 ( V_3 , sizeof( struct V_8 ) ) ;
return (struct V_8 * ) F_6 ( V_3 ) -> V_9 ;
}
static void F_7 ( struct V_10 * V_11 , unsigned long V_12 )
{
V_11 -> V_12 = V_12 ;
V_11 -> V_13 = F_8 () ;
}
static T_1 F_9 ( struct V_10 * V_11 )
{
T_2 V_14 , V_12 ;
unsigned long V_15 ;
if ( V_11 -> V_12 == 0 )
return F_8 () ;
V_14 = F_8 () ;
V_12 = ( T_2 ) V_11 -> V_12 + 1 ;
V_15 = ( V_14 * ( ( 1ull << 32 ) - V_12 ) + V_11 -> V_13 * V_12 ) >> 32 ;
V_11 -> V_13 = V_15 ;
return V_15 ;
}
static bool F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
T_1 V_20 = F_8 () ;
switch ( V_19 -> V_11 ) {
case 1 :
if ( V_20 < V_19 -> V_21 ) {
V_19 -> V_11 = 4 ;
return true ;
} else if ( V_19 -> V_21 < V_20 && V_20 < V_19 -> V_22 ) {
V_19 -> V_11 = 3 ;
return true ;
} else if ( V_19 -> V_22 < V_20 )
V_19 -> V_11 = 1 ;
break;
case 2 :
if ( V_20 < V_19 -> V_23 ) {
V_19 -> V_11 = 3 ;
return true ;
} else
V_19 -> V_11 = 2 ;
break;
case 3 :
if ( V_20 < V_19 -> V_24 )
V_19 -> V_11 = 2 ;
else if ( V_19 -> V_24 < V_20 && V_20 < V_19 -> V_25 + V_19 -> V_24 ) {
V_19 -> V_11 = 1 ;
return true ;
} else if ( V_19 -> V_25 + V_19 -> V_24 < V_20 ) {
V_19 -> V_11 = 3 ;
return true ;
}
break;
case 4 :
V_19 -> V_11 = 1 ;
break;
}
return false ;
}
static bool F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
switch ( V_19 -> V_11 ) {
case 1 :
if ( F_8 () < V_19 -> V_22 )
V_19 -> V_11 = 2 ;
if ( F_8 () < V_19 -> V_21 )
return true ;
case 2 :
if ( F_8 () < V_19 -> V_25 )
V_19 -> V_11 = 1 ;
if ( V_19 -> V_24 > F_8 () )
return true ;
}
return false ;
}
static bool F_12 ( struct V_16 * V_17 )
{
switch ( V_17 -> V_26 ) {
case V_27 :
return V_17 -> V_28 && V_17 -> V_28 >= F_9 ( & V_17 -> V_29 ) ;
case V_30 :
return F_10 ( V_17 ) ;
case V_31 :
return F_11 ( V_17 ) ;
}
return false ;
}
static T_3 F_13 ( T_3 V_32 , T_3 V_33 ,
struct V_10 * V_11 ,
const struct V_34 * V_35 )
{
T_3 V_36 ;
long V_37 ;
T_1 V_20 ;
if ( V_33 == 0 )
return V_32 ;
V_20 = F_9 ( V_11 ) ;
if ( V_35 == NULL )
return ( V_20 % ( 2 * V_33 ) ) - V_33 + V_32 ;
V_37 = V_35 -> V_38 [ V_20 % V_35 -> V_39 ] ;
V_36 = ( V_33 % V_40 ) * V_37 ;
if ( V_36 >= 0 )
V_36 += V_40 / 2 ;
else
V_36 -= V_40 / 2 ;
return V_36 / V_40 + ( V_33 / V_40 ) * V_37 + V_32 ;
}
static T_4 F_14 ( unsigned int V_41 , struct V_16 * V_17 )
{
T_2 V_42 ;
V_41 += V_17 -> V_43 ;
if ( V_17 -> V_44 ) {
T_1 V_45 = F_15 ( V_41 , V_17 -> V_46 ) ;
if ( V_41 > V_45 * V_17 -> V_44 )
V_45 ++ ;
V_41 = V_45 * ( V_17 -> V_44 + V_17 -> V_47 ) ;
}
V_42 = ( T_2 ) V_41 * V_48 ;
F_16 ( V_42 , V_17 -> V_49 ) ;
return F_17 ( V_42 ) ;
}
static void F_18 ( struct V_2 * V_50 , struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
T_4 V_53 = V_8 ( V_50 ) -> V_54 ;
struct V_1 * * V_55 = & V_17 -> V_56 . V_1 , * V_57 = NULL ;
while ( * V_55 ) {
struct V_2 * V_3 ;
V_57 = * V_55 ;
V_3 = F_4 ( V_57 ) ;
if ( V_53 >= V_8 ( V_3 ) -> V_54 )
V_55 = & V_57 -> V_58 ;
else
V_55 = & V_57 -> V_59 ;
}
F_20 ( F_1 ( V_50 ) , V_57 , V_55 ) ;
F_21 ( F_1 ( V_50 ) , & V_17 -> V_56 ) ;
V_52 -> V_17 . V_60 ++ ;
}
static int F_22 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
struct V_8 * V_61 ;
struct V_2 * V_62 ;
int V_63 = 1 ;
if ( V_17 -> V_64 && V_17 -> V_64 >= F_9 ( & V_17 -> V_65 ) )
++ V_63 ;
if ( F_12 ( V_17 ) ) {
if ( V_17 -> V_66 && F_23 ( V_3 ) )
V_52 -> V_67 . V_68 ++ ;
else
-- V_63 ;
}
if ( V_63 == 0 ) {
V_52 -> V_67 . V_68 ++ ;
F_24 ( V_3 ) ;
return V_69 | V_70 ;
}
if ( V_17 -> V_71 || V_17 -> V_72 )
F_25 ( V_3 ) ;
if ( V_63 > 1 && ( V_62 = F_26 ( V_3 , V_73 ) ) != NULL ) {
struct V_51 * V_74 = F_27 ( V_52 ) ;
T_1 V_75 = V_17 -> V_64 ;
V_17 -> V_64 = 0 ;
F_28 ( V_62 , V_74 ) ;
V_17 -> V_64 = V_75 ;
}
if ( V_17 -> V_76 && V_17 -> V_76 >= F_9 ( & V_17 -> V_77 ) ) {
if ( ! ( V_3 = F_29 ( V_3 , V_73 ) ) ||
( V_3 -> V_78 == V_79 &&
F_30 ( V_3 ) ) )
return F_31 ( V_3 , V_52 ) ;
V_3 -> V_9 [ F_8 () % F_32 ( V_3 ) ] ^= 1 << ( F_8 () % 8 ) ;
}
if ( F_33 ( F_34 ( & V_52 -> V_17 ) >= V_52 -> V_80 ) )
return F_35 ( V_3 , V_52 ) ;
V_52 -> V_67 . V_81 += F_36 ( V_3 ) ;
V_61 = V_8 ( V_3 ) ;
if ( V_17 -> V_82 == 0 ||
V_17 -> V_83 < V_17 -> V_82 - 1 ||
V_17 -> V_84 < F_9 ( & V_17 -> V_85 ) ) {
T_4 V_86 ;
T_3 V_87 ;
V_87 = F_13 ( V_17 -> V_71 , V_17 -> V_72 ,
& V_17 -> V_88 , V_17 -> V_89 ) ;
V_86 = F_37 () ;
if ( V_17 -> V_49 ) {
struct V_2 * V_13 ;
if ( ! F_38 ( & V_52 -> V_17 ) )
V_13 = F_39 ( & V_52 -> V_17 ) ;
else
V_13 = F_4 ( F_40 ( & V_17 -> V_56 ) ) ;
if ( V_13 ) {
V_87 -= V_8 ( V_13 ) -> V_54 - V_86 ;
V_87 = F_41 ( T_3 , 0 , V_87 ) ;
V_86 = V_8 ( V_13 ) -> V_54 ;
}
V_87 += F_14 ( V_3 -> V_41 , V_17 ) ;
}
V_61 -> V_54 = V_86 + V_87 ;
V_61 -> V_90 = V_3 -> V_6 ;
++ V_17 -> V_83 ;
F_18 ( V_3 , V_52 ) ;
} else {
V_61 -> V_54 = F_37 () ;
V_17 -> V_83 = 0 ;
F_42 ( & V_52 -> V_17 , V_3 ) ;
V_52 -> V_67 . V_91 ++ ;
}
return V_69 ;
}
static unsigned int F_43 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
unsigned int V_41 ;
V_41 = F_44 ( V_52 ) ;
if ( ! V_41 ) {
struct V_1 * V_55 = F_45 ( & V_17 -> V_56 ) ;
if ( V_55 ) {
struct V_2 * V_3 = F_4 ( V_55 ) ;
F_46 ( V_55 , & V_17 -> V_56 ) ;
V_52 -> V_17 . V_60 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_41 = F_36 ( V_3 ) ;
F_24 ( V_3 ) ;
}
}
if ( ! V_41 && V_17 -> V_92 && V_17 -> V_92 -> V_93 -> V_94 )
V_41 = V_17 -> V_92 -> V_93 -> V_94 ( V_17 -> V_92 ) ;
if ( V_41 )
V_52 -> V_67 . V_68 ++ ;
return V_41 ;
}
static struct V_2 * F_47 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
struct V_2 * V_3 ;
struct V_1 * V_55 ;
if ( F_48 ( V_52 ) )
return NULL ;
V_95:
V_3 = F_49 ( & V_52 -> V_17 ) ;
if ( V_3 ) {
V_96:
V_52 -> V_67 . V_81 -= F_36 ( V_3 ) ;
F_50 ( V_52 ) ;
F_51 ( V_52 , V_3 ) ;
return V_3 ;
}
V_55 = F_45 ( & V_17 -> V_56 ) ;
if ( V_55 ) {
T_4 V_54 ;
V_3 = F_4 ( V_55 ) ;
V_54 = V_8 ( V_3 ) -> V_54 ;
if ( V_54 <= F_37 () ) {
F_46 ( V_55 , & V_17 -> V_56 ) ;
V_52 -> V_17 . V_60 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = V_8 ( V_3 ) -> V_90 ;
#ifdef F_52
if ( F_53 ( V_3 -> V_97 ) & V_98 )
V_3 -> V_6 . V_99 = 0 ;
#endif
if ( V_17 -> V_92 ) {
int V_100 = F_54 ( V_3 , V_17 -> V_92 ) ;
if ( F_33 ( V_100 != V_69 ) ) {
if ( F_55 ( V_100 ) ) {
V_52 -> V_67 . V_68 ++ ;
F_56 ( V_52 , 1 ) ;
}
}
goto V_95;
}
goto V_96;
}
if ( V_17 -> V_92 ) {
V_3 = V_17 -> V_92 -> V_93 -> V_101 ( V_17 -> V_92 ) ;
if ( V_3 )
goto V_96;
}
F_57 ( & V_17 -> V_102 , V_54 ) ;
}
if ( V_17 -> V_92 ) {
V_3 = V_17 -> V_92 -> V_93 -> V_101 ( V_17 -> V_92 ) ;
if ( V_3 )
goto V_96;
}
return NULL ;
}
static void F_58 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
F_59 ( V_52 ) ;
if ( V_17 -> V_92 )
F_60 ( V_17 -> V_92 ) ;
F_61 ( & V_17 -> V_102 ) ;
}
static void F_62 ( struct V_34 * V_103 )
{
if ( V_103 ) {
if ( F_63 ( V_103 ) )
F_64 ( V_103 ) ;
else
F_65 ( V_103 ) ;
}
}
static int F_66 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
T_5 V_106 = F_67 ( V_105 ) / sizeof( V_107 ) ;
const V_107 * V_9 = F_68 ( V_105 ) ;
T_6 * V_108 ;
struct V_34 * V_103 ;
int V_109 ;
T_5 V_110 ;
if ( V_106 > V_111 )
return - V_112 ;
V_110 = sizeof( struct V_34 ) + V_106 * sizeof( V_113 ) ;
V_103 = F_69 ( V_110 , V_114 | V_115 ) ;
if ( ! V_103 )
V_103 = F_70 ( V_110 ) ;
if ( ! V_103 )
return - V_116 ;
V_103 -> V_39 = V_106 ;
for ( V_109 = 0 ; V_109 < V_106 ; V_109 ++ )
V_103 -> V_38 [ V_109 ] = V_9 [ V_109 ] ;
V_108 = F_71 ( V_52 ) ;
F_72 ( V_108 ) ;
F_73 ( V_17 -> V_89 , V_103 ) ;
F_74 ( V_108 ) ;
F_62 ( V_103 ) ;
return 0 ;
}
static void F_75 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
const struct V_117 * V_118 = F_68 ( V_105 ) ;
F_7 ( & V_17 -> V_88 , V_118 -> V_119 ) ;
F_7 ( & V_17 -> V_29 , V_118 -> V_120 ) ;
F_7 ( & V_17 -> V_65 , V_118 -> V_121 ) ;
}
static void F_76 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
const struct V_122 * V_123 = F_68 ( V_105 ) ;
V_17 -> V_84 = V_123 -> V_124 ;
F_7 ( & V_17 -> V_85 , V_123 -> V_125 ) ;
}
static void F_77 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
const struct V_126 * V_123 = F_68 ( V_105 ) ;
V_17 -> V_76 = V_123 -> V_124 ;
F_7 ( & V_17 -> V_77 , V_123 -> V_125 ) ;
}
static void F_78 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
const struct V_127 * V_123 = F_68 ( V_105 ) ;
V_17 -> V_49 = V_123 -> V_49 ;
V_17 -> V_43 = V_123 -> V_43 ;
V_17 -> V_44 = V_123 -> V_44 ;
if ( V_17 -> V_44 )
V_17 -> V_46 = F_79 ( V_17 -> V_44 ) ;
V_17 -> V_47 = V_123 -> V_47 ;
}
static int F_80 ( struct V_51 * V_52 , const struct V_104 * V_105 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
const struct V_104 * V_128 ;
int V_129 ;
F_81 (la, attr, rem) {
T_7 type = F_82 ( V_128 ) ;
switch( type ) {
case V_130 : {
const struct V_131 * V_132 = F_68 ( V_128 ) ;
if ( F_67 ( V_128 ) < sizeof( struct V_131 ) ) {
F_83 ( L_1 ) ;
return - V_112 ;
}
V_17 -> V_26 = V_30 ;
V_17 -> V_19 . V_11 = 1 ;
V_17 -> V_19 . V_22 = V_132 -> V_133 ;
V_17 -> V_19 . V_25 = V_132 -> V_134 ;
V_17 -> V_19 . V_24 = V_132 -> V_135 ;
V_17 -> V_19 . V_21 = V_132 -> V_136 ;
V_17 -> V_19 . V_23 = V_132 -> V_137 ;
break;
}
case V_138 : {
const struct V_139 * V_140 = F_68 ( V_128 ) ;
if ( F_67 ( V_128 ) < sizeof( struct V_139 ) ) {
F_83 ( L_2 ) ;
return - V_112 ;
}
V_17 -> V_26 = V_31 ;
V_17 -> V_19 . V_11 = 1 ;
V_17 -> V_19 . V_22 = V_140 -> V_55 ;
V_17 -> V_19 . V_25 = V_140 -> V_123 ;
V_17 -> V_19 . V_24 = V_140 -> V_141 ;
V_17 -> V_19 . V_21 = V_140 -> V_142 ;
break;
}
default:
F_83 ( L_3 , type ) ;
return - V_112 ;
}
}
return 0 ;
}
static int F_84 ( struct V_104 * V_143 [] , int V_144 , struct V_104 * V_145 ,
const struct V_146 * V_147 , int V_41 )
{
int V_148 = F_67 ( V_145 ) - F_85 ( V_41 ) ;
if ( V_148 < 0 ) {
F_83 ( L_4 , V_148 ) ;
return - V_112 ;
}
if ( V_148 >= F_86 ( 0 ) )
return F_87 ( V_143 , V_144 , F_68 ( V_145 ) + F_85 ( V_41 ) ,
V_148 , V_147 ) ;
memset ( V_143 , 0 , sizeof( struct V_104 * ) * ( V_144 + 1 ) ) ;
return 0 ;
}
static int F_88 ( struct V_51 * V_52 , struct V_104 * V_149 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
struct V_104 * V_143 [ V_150 + 1 ] ;
struct V_151 * V_152 ;
int V_153 ;
if ( V_149 == NULL )
return - V_112 ;
V_152 = F_68 ( V_149 ) ;
V_153 = F_84 ( V_143 , V_150 , V_149 , V_154 , sizeof( * V_152 ) ) ;
if ( V_153 < 0 )
return V_153 ;
V_52 -> V_80 = V_152 -> V_80 ;
V_17 -> V_71 = V_152 -> V_71 ;
V_17 -> V_72 = V_152 -> V_72 ;
V_17 -> V_80 = V_152 -> V_80 ;
V_17 -> V_82 = V_152 -> V_82 ;
V_17 -> V_83 = 0 ;
V_17 -> V_28 = V_152 -> V_28 ;
V_17 -> V_64 = V_152 -> V_64 ;
if ( V_17 -> V_82 )
V_17 -> V_84 = ~ 0 ;
if ( V_143 [ V_155 ] )
F_75 ( V_52 , V_143 [ V_155 ] ) ;
if ( V_143 [ V_156 ] ) {
V_153 = F_66 ( V_52 , V_143 [ V_156 ] ) ;
if ( V_153 )
return V_153 ;
}
if ( V_143 [ V_157 ] )
F_76 ( V_52 , V_143 [ V_157 ] ) ;
if ( V_143 [ V_158 ] )
F_77 ( V_52 , V_143 [ V_158 ] ) ;
if ( V_143 [ V_159 ] )
F_78 ( V_52 , V_143 [ V_159 ] ) ;
if ( V_143 [ V_160 ] )
V_17 -> V_66 = F_89 ( V_143 [ V_160 ] ) ;
V_17 -> V_26 = V_27 ;
if ( V_143 [ V_161 ] )
V_153 = F_80 ( V_52 , V_143 [ V_161 ] ) ;
return V_153 ;
}
static int F_90 ( struct V_51 * V_52 , struct V_104 * V_149 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
int V_153 ;
if ( ! V_149 )
return - V_112 ;
F_91 ( & V_17 -> V_102 , V_52 ) ;
V_17 -> V_26 = V_27 ;
V_153 = F_88 ( V_52 , V_149 ) ;
if ( V_153 )
F_83 ( L_5 ) ;
return V_153 ;
}
static void F_92 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
F_61 ( & V_17 -> V_102 ) ;
if ( V_17 -> V_92 )
F_93 ( V_17 -> V_92 ) ;
F_62 ( V_17 -> V_89 ) ;
}
static int F_94 ( const struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_104 * V_162 ;
V_162 = F_95 ( V_3 , V_161 ) ;
if ( V_162 == NULL )
goto V_163;
switch ( V_17 -> V_26 ) {
case V_27 :
F_96 ( V_3 , V_162 ) ;
return 0 ;
case V_30 : {
struct V_131 V_132 = {
. V_133 = V_17 -> V_19 . V_22 ,
. V_134 = V_17 -> V_19 . V_25 ,
. V_135 = V_17 -> V_19 . V_24 ,
. V_136 = V_17 -> V_19 . V_21 ,
. V_137 = V_17 -> V_19 . V_23 ,
} ;
if ( F_97 ( V_3 , V_130 , sizeof( V_132 ) , & V_132 ) )
goto V_163;
break;
}
case V_31 : {
struct V_139 V_140 = {
. V_55 = V_17 -> V_19 . V_22 ,
. V_123 = V_17 -> V_19 . V_25 ,
. V_141 = V_17 -> V_19 . V_24 ,
. V_142 = V_17 -> V_19 . V_21 ,
} ;
if ( F_97 ( V_3 , V_138 , sizeof( V_140 ) , & V_140 ) )
goto V_163;
break;
}
}
F_98 ( V_3 , V_162 ) ;
return 0 ;
V_163:
F_96 ( V_3 , V_162 ) ;
return - 1 ;
}
static int F_99 ( struct V_51 * V_52 , struct V_2 * V_3 )
{
const struct V_16 * V_17 = F_19 ( V_52 ) ;
struct V_104 * V_145 = (struct V_104 * ) F_100 ( V_3 ) ;
struct V_151 V_152 ;
struct V_117 V_164 ;
struct V_122 V_84 ;
struct V_126 V_76 ;
struct V_127 V_49 ;
V_152 . V_71 = V_17 -> V_71 ;
V_152 . V_72 = V_17 -> V_72 ;
V_152 . V_80 = V_17 -> V_80 ;
V_152 . V_28 = V_17 -> V_28 ;
V_152 . V_82 = V_17 -> V_82 ;
V_152 . V_64 = V_17 -> V_64 ;
if ( F_97 ( V_3 , V_165 , sizeof( V_152 ) , & V_152 ) )
goto V_163;
V_164 . V_119 = V_17 -> V_88 . V_12 ;
V_164 . V_120 = V_17 -> V_29 . V_12 ;
V_164 . V_121 = V_17 -> V_65 . V_12 ;
if ( F_97 ( V_3 , V_155 , sizeof( V_164 ) , & V_164 ) )
goto V_163;
V_84 . V_124 = V_17 -> V_84 ;
V_84 . V_125 = V_17 -> V_85 . V_12 ;
if ( F_97 ( V_3 , V_157 , sizeof( V_84 ) , & V_84 ) )
goto V_163;
V_76 . V_124 = V_17 -> V_76 ;
V_76 . V_125 = V_17 -> V_77 . V_12 ;
if ( F_97 ( V_3 , V_158 , sizeof( V_76 ) , & V_76 ) )
goto V_163;
V_49 . V_49 = V_17 -> V_49 ;
V_49 . V_43 = V_17 -> V_43 ;
V_49 . V_44 = V_17 -> V_44 ;
V_49 . V_47 = V_17 -> V_47 ;
if ( F_97 ( V_3 , V_159 , sizeof( V_49 ) , & V_49 ) )
goto V_163;
if ( V_17 -> V_66 && F_101 ( V_3 , V_160 , V_17 -> V_66 ) )
goto V_163;
if ( F_94 ( V_17 , V_3 ) != 0 )
goto V_163;
return F_98 ( V_3 , V_145 ) ;
V_163:
F_102 ( V_3 , V_145 ) ;
return - 1 ;
}
static int F_103 ( struct V_51 * V_52 , unsigned long V_166 ,
struct V_2 * V_3 , struct V_167 * V_168 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
if ( V_166 != 1 || ! V_17 -> V_92 )
return - V_169 ;
V_168 -> V_170 |= F_104 ( 1 ) ;
V_168 -> V_171 = V_17 -> V_92 -> V_172 ;
return 0 ;
}
static int F_105 ( struct V_51 * V_52 , unsigned long V_173 , struct V_51 * V_174 ,
struct V_51 * * V_175 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
F_106 ( V_52 ) ;
* V_175 = V_17 -> V_92 ;
V_17 -> V_92 = V_174 ;
if ( * V_175 ) {
F_56 ( * V_175 , ( * V_175 ) -> V_17 . V_60 ) ;
F_60 ( * V_175 ) ;
}
F_107 ( V_52 ) ;
return 0 ;
}
static struct V_51 * F_108 ( struct V_51 * V_52 , unsigned long V_173 )
{
struct V_16 * V_17 = F_19 ( V_52 ) ;
return V_17 -> V_92 ;
}
static unsigned long F_109 ( struct V_51 * V_52 , T_1 V_176 )
{
return 1 ;
}
static void F_110 ( struct V_51 * V_52 , unsigned long V_173 )
{
}
static void F_111 ( struct V_51 * V_52 , struct V_177 * V_178 )
{
if ( ! V_178 -> V_179 ) {
if ( V_178 -> V_63 >= V_178 -> V_180 )
if ( V_178 -> V_181 ( V_52 , 1 , V_178 ) < 0 ) {
V_178 -> V_179 = 1 ;
return;
}
V_178 -> V_63 ++ ;
}
}
static int T_8 F_112 ( void )
{
F_83 ( L_6 V_182 L_7 ) ;
return F_113 ( & V_183 ) ;
}
static void T_9 F_114 ( void )
{
F_115 ( & V_183 ) ;
}
