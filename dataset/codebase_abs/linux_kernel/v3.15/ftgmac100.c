static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
V_6 = F_4 ( V_6 ) ;
F_2 ( V_6 , V_2 -> V_4 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_4 + V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 ;
F_2 ( V_13 , V_2 -> V_4 + V_14 ) ;
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ ) {
unsigned int V_15 ;
V_15 = F_8 ( V_2 -> V_4 + V_14 ) ;
if ( ! ( V_15 & V_13 ) )
return 0 ;
F_9 ( 1000 ) ;
}
F_10 ( V_11 , L_1 ) ;
return - V_16 ;
}
static void F_11 ( struct V_1 * V_2 , const unsigned char * V_17 )
{
unsigned int V_18 = V_17 [ 0 ] << 8 | V_17 [ 1 ] ;
unsigned int V_19 = V_17 [ 2 ] << 24 | V_17 [ 3 ] << 16 | V_17 [ 4 ] << 8 | V_17 [ 5 ] ;
F_2 ( V_18 , V_2 -> V_4 + V_20 ) ;
F_2 ( V_19 , V_2 -> V_4 + V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
V_2 -> V_22 +
F_13 ( struct V_23 , V_24 ) ) ;
F_5 ( V_2 ,
V_2 -> V_22 +
F_13 ( struct V_23 , V_25 ) ) ;
F_3 ( V_2 , V_26 ) ;
F_2 ( F_14 ( 1 ) , V_2 -> V_4 + V_27 ) ;
F_11 ( V_2 , V_2 -> V_11 -> V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_29 )
{
int V_15 = V_30 ;
switch ( V_29 ) {
default:
case 10 :
break;
case 100 :
V_15 |= V_31 ;
break;
case 1000 :
V_15 |= V_32 ;
break;
}
F_2 ( V_15 , V_2 -> V_4 + V_14 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_14 ) ;
}
static bool F_17 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_35 ) ;
}
static bool F_19 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_36 ) ;
}
static bool F_20 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_37 ) ;
}
static void F_21 ( struct V_33 * V_24 )
{
V_24 -> V_34 &= F_18 ( V_38 ) ;
}
static bool F_22 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_39 ) ;
}
static bool F_23 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_40 ) ;
}
static bool F_24 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_41 ) ;
}
static bool F_25 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_42 ) ;
}
static bool F_26 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_43 ) ;
}
static unsigned int F_27 ( struct V_33 * V_24 )
{
return F_28 ( V_24 -> V_34 ) & V_44 ;
}
static bool F_29 ( struct V_33 * V_24 )
{
return V_24 -> V_34 & F_18 ( V_45 ) ;
}
static void F_30 ( struct V_33 * V_24 )
{
V_24 -> V_34 |= F_18 ( V_38 ) ;
}
static void F_31 ( struct V_33 * V_24 ,
T_1 V_3 )
{
V_24 -> V_46 = F_18 ( V_3 ) ;
}
static T_1 F_32 ( struct V_33 * V_24 )
{
return F_28 ( V_24 -> V_46 ) ;
}
static bool F_33 ( struct V_33 * V_24 )
{
return ( V_24 -> V_47 & F_18 ( V_48 ) ) ==
F_18 ( V_49 ) ;
}
static bool F_34 ( struct V_33 * V_24 )
{
return ( V_24 -> V_47 & F_18 ( V_48 ) ) ==
F_18 ( V_50 ) ;
}
static bool F_35 ( struct V_33 * V_24 )
{
return V_24 -> V_47 & F_18 ( V_51 ) ;
}
static bool F_36 ( struct V_33 * V_24 )
{
return V_24 -> V_47 & F_18 ( V_52 ) ;
}
static bool F_37 ( struct V_33 * V_24 )
{
return V_24 -> V_47 & F_18 ( V_53 ) ;
}
static void F_38 ( struct V_33 * V_24 , struct V_54 * V_54 )
{
V_24 -> V_55 = ( unsigned int ) V_54 ;
}
static struct V_54 * F_39 ( struct V_33 * V_24 )
{
return (struct V_54 * ) V_24 -> V_55 ;
}
static int F_40 ( int V_56 )
{
return ( V_56 + 1 ) & ( V_57 - 1 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_58 = F_40 ( V_2 -> V_58 ) ;
}
static struct V_33 * F_42 ( struct V_1 * V_2 )
{
return & V_2 -> V_59 -> V_24 [ V_2 -> V_58 ] ;
}
static struct V_33 *
F_43 ( struct V_1 * V_2 )
{
struct V_33 * V_24 = F_42 ( V_2 ) ;
while ( F_20 ( V_24 ) ) {
if ( F_17 ( V_24 ) )
return V_24 ;
F_21 ( V_24 ) ;
F_41 ( V_2 ) ;
V_24 = F_42 ( V_2 ) ;
}
return NULL ;
}
static bool F_44 ( struct V_1 * V_2 ,
struct V_33 * V_24 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
bool error = false ;
if ( F_45 ( F_22 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_2 ) ;
V_11 -> V_60 . V_61 ++ ;
error = true ;
}
if ( F_45 ( F_23 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_3 ) ;
V_11 -> V_60 . V_62 ++ ;
error = true ;
} else if ( F_45 ( F_37 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_4 ) ;
error = true ;
}
if ( F_45 ( F_24 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_5 ) ;
V_11 -> V_60 . V_63 ++ ;
error = true ;
} else if ( F_45 ( F_25 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_6 ) ;
V_11 -> V_60 . V_63 ++ ;
error = true ;
} else if ( F_45 ( F_26 ( V_24 ) ) ) {
if ( F_46 () )
F_47 ( V_11 , L_7 ) ;
V_11 -> V_60 . V_63 ++ ;
error = true ;
}
return error ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_33 * V_24 = F_42 ( V_2 ) ;
bool V_64 = false ;
if ( F_46 () )
F_49 ( V_11 , L_8 , V_24 ) ;
do {
if ( F_19 ( V_24 ) )
V_64 = true ;
F_21 ( V_24 ) ;
F_41 ( V_2 ) ;
V_24 = F_42 ( V_2 ) ;
} while ( ! V_64 && F_20 ( V_24 ) );
V_11 -> V_60 . V_65 ++ ;
}
static bool F_50 ( struct V_1 * V_2 , int * V_66 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_33 * V_24 ;
struct V_67 * V_68 ;
bool V_64 = false ;
V_24 = F_43 ( V_2 ) ;
if ( ! V_24 )
return false ;
if ( F_45 ( F_44 ( V_2 , V_24 ) ) ) {
F_48 ( V_2 ) ;
return true ;
}
V_68 = F_51 ( V_11 , 128 ) ;
if ( F_45 ( ! V_68 ) ) {
if ( F_46 () )
F_10 ( V_11 , L_9 ) ;
F_48 ( V_2 ) ;
return true ;
}
if ( F_45 ( F_29 ( V_24 ) ) )
V_11 -> V_60 . V_69 ++ ;
if ( ( F_33 ( V_24 ) && ! F_35 ( V_24 ) ) ||
( F_34 ( V_24 ) && ! F_36 ( V_24 ) ) )
V_68 -> V_70 = V_71 ;
do {
T_1 V_72 = F_32 ( V_24 ) ;
struct V_54 * V_54 = F_39 ( V_24 ) ;
unsigned int V_6 ;
F_52 ( V_2 -> V_73 , V_72 , V_26 , V_74 ) ;
V_6 = F_27 ( V_24 ) ;
F_53 ( V_68 , F_54 ( V_68 ) -> V_75 , V_54 , 0 , V_6 ) ;
V_68 -> V_76 += V_6 ;
V_68 -> V_77 += V_6 ;
V_68 -> V_78 += V_79 ;
if ( F_19 ( V_24 ) )
V_64 = true ;
F_55 ( V_2 , V_24 , V_80 ) ;
F_41 ( V_2 ) ;
V_24 = F_42 ( V_2 ) ;
} while ( ! V_64 );
if ( V_68 -> V_76 <= 128 ) {
V_68 -> V_78 -= V_79 ;
F_56 ( V_68 , V_68 -> V_76 ) ;
} else {
F_56 ( V_68 , V_81 ) ;
}
V_68 -> V_82 = F_57 ( V_68 , V_11 ) ;
V_11 -> V_60 . V_83 ++ ;
V_11 -> V_60 . V_84 += V_68 -> V_76 ;
F_58 ( & V_2 -> V_85 , V_68 ) ;
( * V_66 ) ++ ;
return true ;
}
static void F_59 ( struct V_86 * V_25 )
{
V_25 -> V_87 &= F_18 ( V_88 ) ;
V_25 -> V_89 = 0 ;
V_25 -> V_90 = 0 ;
V_25 -> V_91 = 0 ;
}
static bool F_60 ( struct V_86 * V_25 )
{
return V_25 -> V_87 & F_18 ( V_92 ) ;
}
static void F_61 ( struct V_86 * V_25 )
{
F_62 () ;
V_25 -> V_87 |= F_18 ( V_92 ) ;
}
static void F_63 ( struct V_86 * V_25 )
{
V_25 -> V_87 |= F_18 ( V_88 ) ;
}
static void F_64 ( struct V_86 * V_25 )
{
V_25 -> V_87 |= F_18 ( V_93 ) ;
}
static void F_65 ( struct V_86 * V_25 )
{
V_25 -> V_87 |= F_18 ( V_94 ) ;
}
static void F_66 ( struct V_86 * V_25 ,
unsigned int V_76 )
{
V_25 -> V_87 |= F_18 ( F_67 ( V_76 ) ) ;
}
static void F_68 ( struct V_86 * V_25 )
{
V_25 -> V_89 |= F_18 ( V_95 ) ;
}
static void F_69 ( struct V_86 * V_25 )
{
V_25 -> V_89 |= F_18 ( V_96 ) ;
}
static void F_70 ( struct V_86 * V_25 )
{
V_25 -> V_89 |= F_18 ( V_97 ) ;
}
static void F_71 ( struct V_86 * V_25 )
{
V_25 -> V_89 |= F_18 ( V_98 ) ;
}
static void F_72 ( struct V_86 * V_25 ,
T_1 V_3 )
{
V_25 -> V_91 = F_18 ( V_3 ) ;
}
static T_1 F_73 ( struct V_86 * V_25 )
{
return F_28 ( V_25 -> V_91 ) ;
}
static void F_74 ( struct V_86 * V_25 ,
struct V_67 * V_68 )
{
V_25 -> V_90 = ( unsigned int ) V_68 ;
}
static struct V_67 * F_75 ( struct V_86 * V_25 )
{
return (struct V_67 * ) V_25 -> V_90 ;
}
static int F_76 ( int V_56 )
{
return ( V_56 + 1 ) & ( V_99 - 1 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_100 = F_76 ( V_2 -> V_100 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_101 = F_76 ( V_2 -> V_101 ) ;
}
static struct V_86 * F_79 ( struct V_1 * V_2 )
{
return & V_2 -> V_59 -> V_25 [ V_2 -> V_100 ] ;
}
static struct V_86 *
F_80 ( struct V_1 * V_2 )
{
return & V_2 -> V_59 -> V_25 [ V_2 -> V_101 ] ;
}
static bool F_81 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_86 * V_25 ;
struct V_67 * V_68 ;
T_1 V_72 ;
if ( V_2 -> V_102 == 0 )
return false ;
V_25 = F_80 ( V_2 ) ;
if ( F_60 ( V_25 ) )
return false ;
V_68 = F_75 ( V_25 ) ;
V_72 = F_73 ( V_25 ) ;
V_11 -> V_60 . V_103 ++ ;
V_11 -> V_60 . V_104 += V_68 -> V_76 ;
F_82 ( V_2 -> V_73 , V_72 , F_83 ( V_68 ) , V_105 ) ;
F_84 ( V_68 ) ;
F_59 ( V_25 ) ;
F_78 ( V_2 ) ;
F_85 ( & V_2 -> V_106 ) ;
V_2 -> V_102 -- ;
F_86 ( & V_2 -> V_106 ) ;
F_87 ( V_11 ) ;
return true ;
}
static void F_88 ( struct V_1 * V_2 )
{
while ( F_81 ( V_2 ) )
;
}
static int F_89 ( struct V_1 * V_2 , struct V_67 * V_68 ,
T_1 V_72 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_86 * V_25 ;
unsigned int V_76 = ( V_68 -> V_76 < V_107 ) ? V_107 : V_68 -> V_76 ;
V_25 = F_79 ( V_2 ) ;
F_77 ( V_2 ) ;
F_74 ( V_25 , V_68 ) ;
F_72 ( V_25 , V_72 ) ;
F_66 ( V_25 , V_76 ) ;
F_64 ( V_25 ) ;
F_65 ( V_25 ) ;
F_68 ( V_25 ) ;
if ( V_68 -> V_70 == V_108 ) {
T_2 V_82 = V_68 -> V_82 ;
if ( V_82 == F_90 ( V_109 ) ) {
T_3 V_110 = F_91 ( V_68 ) -> V_82 ;
F_71 ( V_25 ) ;
if ( V_110 == V_111 )
F_69 ( V_25 ) ;
else if ( V_110 == V_112 )
F_70 ( V_25 ) ;
}
}
F_85 ( & V_2 -> V_106 ) ;
V_2 -> V_102 ++ ;
if ( V_2 -> V_102 == V_99 )
F_92 ( V_11 ) ;
F_61 ( V_25 ) ;
F_86 ( & V_2 -> V_106 ) ;
F_6 ( V_2 ) ;
return V_113 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_33 * V_24 , T_4 V_114 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_54 * V_54 ;
T_1 V_72 ;
V_54 = F_93 ( V_114 ) ;
if ( ! V_54 ) {
if ( F_46 () )
F_10 ( V_11 , L_10 ) ;
return - V_115 ;
}
V_72 = F_94 ( V_2 -> V_73 , V_54 , 0 , V_26 , V_74 ) ;
if ( F_45 ( F_95 ( V_2 -> V_73 , V_72 ) ) ) {
if ( F_46 () )
F_10 ( V_11 , L_11 ) ;
F_96 ( V_54 ) ;
return - V_115 ;
}
F_38 ( V_24 , V_54 ) ;
F_31 ( V_24 , V_72 ) ;
F_21 ( V_24 ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
struct V_33 * V_24 = & V_2 -> V_59 -> V_24 [ V_12 ] ;
struct V_54 * V_54 = F_39 ( V_24 ) ;
T_1 V_72 = F_32 ( V_24 ) ;
if ( ! V_54 )
continue;
F_52 ( V_2 -> V_73 , V_72 , V_26 , V_74 ) ;
F_96 ( V_54 ) ;
}
for ( V_12 = 0 ; V_12 < V_99 ; V_12 ++ ) {
struct V_86 * V_25 = & V_2 -> V_59 -> V_25 [ V_12 ] ;
struct V_67 * V_68 = F_75 ( V_25 ) ;
T_1 V_72 = F_73 ( V_25 ) ;
if ( ! V_68 )
continue;
F_82 ( V_2 -> V_73 , V_72 , F_83 ( V_68 ) , V_105 ) ;
F_98 ( V_68 ) ;
}
F_99 ( V_2 -> V_73 , sizeof( struct V_23 ) ,
V_2 -> V_59 , V_2 -> V_22 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_59 = F_101 ( V_2 -> V_73 ,
sizeof( struct V_23 ) ,
& V_2 -> V_22 , V_116 ) ;
if ( ! V_2 -> V_59 )
return - V_115 ;
F_30 ( & V_2 -> V_59 -> V_24 [ V_57 - 1 ] ) ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
struct V_33 * V_24 = & V_2 -> V_59 -> V_24 [ V_12 ] ;
if ( F_55 ( V_2 , V_24 , V_116 ) )
goto V_117;
}
F_63 ( & V_2 -> V_59 -> V_25 [ V_99 - 1 ] ) ;
return 0 ;
V_117:
F_97 ( V_2 ) ;
return - V_115 ;
}
static void F_102 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
struct V_118 * V_119 = V_2 -> V_119 ;
int V_120 ;
if ( V_119 -> V_29 == V_2 -> V_121 )
return;
V_2 -> V_121 = V_119 -> V_29 ;
V_120 = F_8 ( V_2 -> V_4 + V_122 ) ;
F_2 ( 0 , V_2 -> V_4 + V_122 ) ;
F_92 ( V_11 ) ;
F_16 ( V_2 ) ;
F_104 ( V_11 ) ;
F_12 ( V_2 ) ;
F_15 ( V_2 , V_119 -> V_29 ) ;
F_2 ( V_120 , V_2 -> V_4 + V_122 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_118 * V_119 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_123 ; V_12 ++ ) {
struct V_118 * V_124 = V_2 -> V_125 -> V_126 [ V_12 ] ;
if ( V_124 ) {
V_119 = V_124 ;
break;
}
}
if ( ! V_119 ) {
F_47 ( V_11 , L_12 , V_11 -> V_127 ) ;
return - V_128 ;
}
V_119 = F_106 ( V_11 , F_107 ( & V_119 -> V_73 ) ,
& F_102 , V_129 ) ;
if ( F_108 ( V_119 ) ) {
F_10 ( V_11 , L_13 , V_11 -> V_127 ) ;
return F_109 ( V_119 ) ;
}
V_2 -> V_119 = V_119 ;
return 0 ;
}
static int F_110 ( struct V_125 * V_130 , int V_131 , int V_132 )
{
struct V_10 * V_11 = V_130 -> V_2 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
unsigned int V_133 ;
int V_12 ;
V_133 = F_8 ( V_2 -> V_4 + V_134 ) ;
V_133 &= V_135 ;
V_133 |= F_111 ( V_131 ) |
F_112 ( V_132 ) |
V_136 ;
F_2 ( V_133 , V_2 -> V_4 + V_134 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_133 = F_8 ( V_2 -> V_4 + V_134 ) ;
if ( ( V_133 & V_136 ) == 0 ) {
int V_137 ;
V_137 = F_8 ( V_2 -> V_4 + V_138 ) ;
return F_113 ( V_137 ) ;
}
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_14 ) ;
return - V_16 ;
}
static int F_114 ( struct V_125 * V_130 , int V_131 ,
int V_132 , T_5 V_139 )
{
struct V_10 * V_11 = V_130 -> V_2 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
unsigned int V_133 ;
int V_137 ;
int V_12 ;
V_133 = F_8 ( V_2 -> V_4 + V_134 ) ;
V_133 &= V_135 ;
V_133 |= F_111 ( V_131 ) |
F_112 ( V_132 ) |
V_140 ;
V_137 = F_115 ( V_139 ) ;
F_2 ( V_137 , V_2 -> V_4 + V_138 ) ;
F_2 ( V_133 , V_2 -> V_4 + V_134 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_133 = F_8 ( V_2 -> V_4 + V_134 ) ;
if ( ( V_133 & V_140 ) == 0 )
return 0 ;
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_15 ) ;
return - V_16 ;
}
static void F_116 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
F_117 ( V_142 -> V_143 , V_144 , sizeof( V_142 -> V_143 ) ) ;
F_117 ( V_142 -> V_145 , V_146 , sizeof( V_142 -> V_145 ) ) ;
F_117 ( V_142 -> V_147 , F_107 ( & V_11 -> V_73 ) , sizeof( V_142 -> V_147 ) ) ;
}
static int F_118 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_119 ( V_2 -> V_119 , V_149 ) ;
}
static int F_120 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_121 ( V_2 -> V_119 , V_149 ) ;
}
static T_6 F_122 ( int V_150 , void * V_151 )
{
struct V_10 * V_11 = V_151 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
if ( F_123 ( F_124 ( V_11 ) ) ) {
F_2 ( 0 , V_2 -> V_4 + V_122 ) ;
F_125 ( & V_2 -> V_85 ) ;
}
return V_152 ;
}
static int F_126 ( struct V_153 * V_85 , int V_154 )
{
struct V_1 * V_2 = F_127 ( V_85 , struct V_1 , V_85 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_155 ;
bool V_156 = true ;
int V_157 = 0 ;
V_155 = F_8 ( V_2 -> V_4 + V_158 ) ;
F_2 ( V_155 , V_2 -> V_4 + V_158 ) ;
if ( V_155 & ( V_159 | V_160 ) ) {
bool V_161 ;
do {
V_161 = F_50 ( V_2 , & V_157 ) ;
} while ( V_161 && V_157 < V_154 );
if ( V_161 && V_157 == V_154 )
V_156 = false ;
}
if ( V_155 & ( V_162 | V_163 ) ) {
F_88 ( V_2 ) ;
}
if ( V_155 & ( V_160 | V_164 |
V_165 | V_166 ) ) {
if ( F_46 () )
F_47 ( V_11 , L_16 , V_155 ,
V_155 & V_160 ? L_17 : L_18 ,
V_155 & V_164 ? L_19 : L_18 ,
V_155 & V_165 ? L_20 : L_18 ,
V_155 & V_166 ? L_21 : L_18 ) ;
if ( V_155 & V_160 ) {
V_11 -> V_60 . V_167 ++ ;
}
if ( V_155 & V_164 ) {
V_11 -> V_60 . V_168 ++ ;
}
}
if ( V_156 ) {
F_128 ( V_85 ) ;
F_2 ( V_169 , V_2 -> V_4 + V_122 ) ;
}
return V_157 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
int V_117 ;
V_117 = F_100 ( V_2 ) ;
if ( V_117 ) {
F_10 ( V_11 , L_22 ) ;
goto V_170;
}
V_117 = F_130 ( V_2 -> V_150 , F_122 , 0 , V_11 -> V_127 , V_11 ) ;
if ( V_117 ) {
F_10 ( V_11 , L_23 , V_2 -> V_150 ) ;
goto V_171;
}
V_2 -> V_58 = 0 ;
V_2 -> V_101 = 0 ;
V_2 -> V_100 = 0 ;
V_2 -> V_102 = 0 ;
V_117 = F_7 ( V_2 ) ;
if ( V_117 )
goto V_172;
F_12 ( V_2 ) ;
F_15 ( V_2 , 10 ) ;
F_131 ( V_2 -> V_119 ) ;
F_132 ( & V_2 -> V_85 ) ;
F_104 ( V_11 ) ;
F_2 ( V_169 , V_2 -> V_4 + V_122 ) ;
return 0 ;
V_172:
F_133 ( V_2 -> V_150 , V_11 ) ;
V_171:
F_97 ( V_2 ) ;
V_170:
return V_117 ;
}
static int F_134 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
F_2 ( 0 , V_2 -> V_4 + V_122 ) ;
F_92 ( V_11 ) ;
F_135 ( & V_2 -> V_85 ) ;
F_136 ( V_2 -> V_119 ) ;
F_16 ( V_2 ) ;
F_133 ( V_2 -> V_150 , V_11 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int F_137 ( struct V_67 * V_68 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
T_1 V_72 ;
if ( F_45 ( V_68 -> V_76 > V_173 ) ) {
if ( F_46 () )
F_49 ( V_11 , L_24 ) ;
V_11 -> V_60 . V_174 ++ ;
F_98 ( V_68 ) ;
return V_113 ;
}
V_72 = F_138 ( V_2 -> V_73 , V_68 -> V_137 , F_83 ( V_68 ) , V_105 ) ;
if ( F_45 ( F_95 ( V_2 -> V_73 , V_72 ) ) ) {
if ( F_46 () )
F_10 ( V_11 , L_25 ) ;
V_11 -> V_60 . V_174 ++ ;
F_98 ( V_68 ) ;
return V_113 ;
}
return F_89 ( V_2 , V_68 , V_72 ) ;
}
static int F_139 ( struct V_10 * V_11 , struct V_175 * V_176 , int V_149 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_140 ( V_2 -> V_119 , V_176 , V_149 ) ;
}
static int F_141 ( struct V_177 * V_178 )
{
struct V_179 * V_180 ;
int V_150 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_117 ;
int V_12 ;
if ( ! V_178 )
return - V_128 ;
V_180 = F_142 ( V_178 , V_181 , 0 ) ;
if ( ! V_180 )
return - V_182 ;
V_150 = F_143 ( V_178 , 0 ) ;
if ( V_150 < 0 )
return V_150 ;
V_11 = F_144 ( sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
V_117 = - V_115 ;
goto V_183;
}
F_145 ( V_11 , & V_178 -> V_73 ) ;
F_146 ( V_11 , & V_184 ) ;
V_11 -> V_185 = & V_186 ;
V_11 -> V_187 = V_188 | V_189 ;
F_147 ( V_178 , V_11 ) ;
V_2 = F_103 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_73 = & V_178 -> V_73 ;
F_148 ( & V_2 -> V_106 ) ;
F_149 ( V_11 , & V_2 -> V_85 , F_126 , 64 ) ;
V_2 -> V_180 = F_150 ( V_180 -> V_190 , F_151 ( V_180 ) ,
F_107 ( & V_178 -> V_73 ) ) ;
if ( ! V_2 -> V_180 ) {
F_152 ( & V_178 -> V_73 , L_26 ) ;
V_117 = - V_115 ;
goto V_191;
}
V_2 -> V_4 = F_153 ( V_180 -> V_190 , F_151 ( V_180 ) ) ;
if ( ! V_2 -> V_4 ) {
F_152 ( & V_178 -> V_73 , L_27 ) ;
V_117 = - V_16 ;
goto V_192;
}
V_2 -> V_150 = V_150 ;
V_2 -> V_125 = F_154 () ;
if ( ! V_2 -> V_125 ) {
V_117 = - V_16 ;
goto V_193;
}
V_2 -> V_125 -> V_127 = L_28 ;
snprintf ( V_2 -> V_125 -> V_194 , V_195 , L_29 ) ;
V_2 -> V_125 -> V_2 = V_11 ;
V_2 -> V_125 -> V_196 = F_110 ;
V_2 -> V_125 -> V_197 = F_114 ;
V_2 -> V_125 -> V_150 = V_2 -> V_198 ;
for ( V_12 = 0 ; V_12 < V_123 ; V_12 ++ )
V_2 -> V_125 -> V_150 [ V_12 ] = V_199 ;
V_117 = F_155 ( V_2 -> V_125 ) ;
if ( V_117 ) {
F_152 ( & V_178 -> V_73 , L_30 ) ;
goto V_200;
}
V_117 = F_105 ( V_2 ) ;
if ( V_117 ) {
F_152 ( & V_178 -> V_73 , L_31 ) ;
goto V_201;
}
V_117 = F_156 ( V_11 ) ;
if ( V_117 ) {
F_152 ( & V_178 -> V_73 , L_32 ) ;
goto V_202;
}
F_47 ( V_11 , L_33 , V_2 -> V_150 , V_2 -> V_4 ) ;
if ( ! F_157 ( V_11 -> V_28 ) ) {
F_158 ( V_11 ) ;
F_47 ( V_11 , L_34 ,
V_11 -> V_28 ) ;
}
return 0 ;
V_202:
F_159 ( V_2 -> V_119 ) ;
V_201:
F_160 ( V_2 -> V_125 ) ;
V_200:
F_161 ( V_2 -> V_125 ) ;
V_193:
F_162 ( V_2 -> V_4 ) ;
V_192:
F_163 ( V_2 -> V_180 ) ;
V_191:
F_164 ( & V_2 -> V_85 ) ;
F_165 ( V_11 ) ;
V_183:
return V_117 ;
}
static int T_7 F_166 ( struct V_177 * V_178 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_167 ( V_178 ) ;
V_2 = F_103 ( V_11 ) ;
F_168 ( V_11 ) ;
F_159 ( V_2 -> V_119 ) ;
F_160 ( V_2 -> V_125 ) ;
F_161 ( V_2 -> V_125 ) ;
F_162 ( V_2 -> V_4 ) ;
F_163 ( V_2 -> V_180 ) ;
F_164 ( & V_2 -> V_85 ) ;
F_165 ( V_11 ) ;
return 0 ;
}
