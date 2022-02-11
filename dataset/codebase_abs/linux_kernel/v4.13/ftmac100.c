static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_6 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_7 )
{
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
F_2 ( V_7 , V_2 -> V_4 + V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_4 + V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_13 ;
F_2 ( V_14 , V_2 -> V_4 + V_15 ) ;
for ( V_13 = 0 ; V_13 < 5 ; V_13 ++ ) {
unsigned int V_16 ;
V_16 = F_8 ( V_2 -> V_4 + V_15 ) ;
if ( ! ( V_16 & V_14 ) ) {
F_9 ( 500 ) ;
return 0 ;
}
F_9 ( 1000 ) ;
}
F_10 ( V_12 , L_1 ) ;
return - V_17 ;
}
static void F_11 ( struct V_1 * V_2 , const unsigned char * V_18 )
{
unsigned int V_19 = V_18 [ 0 ] << 8 | V_18 [ 1 ] ;
unsigned int V_20 = V_18 [ 2 ] << 24 | V_18 [ 3 ] << 16 | V_18 [ 4 ] << 8 | V_18 [ 5 ] ;
F_2 ( V_19 , V_2 -> V_4 + V_21 ) ;
F_2 ( V_20 , V_2 -> V_4 + V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( F_7 ( V_2 ) )
return - V_17 ;
F_4 ( V_2 ,
V_2 -> V_23 +
F_13 ( struct V_24 , V_25 ) ) ;
F_5 ( V_2 ,
V_2 -> V_23 +
F_13 ( struct V_24 , V_26 ) ) ;
F_2 ( F_14 ( 1 ) , V_2 -> V_4 + V_27 ) ;
F_11 ( V_2 , V_12 -> V_28 ) ;
F_2 ( V_29 , V_2 -> V_4 + V_15 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_15 ) ;
}
static bool F_16 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_32 ) ;
}
static bool F_18 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_33 ) ;
}
static bool F_19 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_34 ) ;
}
static void F_20 ( struct V_30 * V_25 )
{
V_25 -> V_31 = F_17 ( V_34 ) ;
}
static bool F_21 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_35 ) ;
}
static bool F_22 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_36 ) ;
}
static bool F_23 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_37 ) ;
}
static bool F_24 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_38 ) ;
}
static bool F_25 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_39 ) ;
}
static unsigned int F_26 ( struct V_30 * V_25 )
{
return F_27 ( V_25 -> V_31 ) & V_40 ;
}
static bool F_28 ( struct V_30 * V_25 )
{
return V_25 -> V_31 & F_17 ( V_41 ) ;
}
static void F_29 ( struct V_30 * V_25 ,
unsigned int V_42 )
{
V_25 -> V_43 &= F_17 ( V_44 ) ;
V_25 -> V_43 |= F_17 ( F_30 ( V_42 ) ) ;
}
static void F_31 ( struct V_30 * V_25 )
{
V_25 -> V_43 |= F_17 ( V_44 ) ;
}
static void F_32 ( struct V_30 * V_25 ,
T_1 V_7 )
{
V_25 -> V_45 = F_17 ( V_7 ) ;
}
static T_1 F_33 ( struct V_30 * V_25 )
{
return F_27 ( V_25 -> V_45 ) ;
}
static void F_34 ( struct V_30 * V_25 , struct V_46 * V_46 )
{
V_25 -> V_47 = ( unsigned int ) V_46 ;
}
static struct V_46 * F_35 ( struct V_30 * V_25 )
{
return (struct V_46 * ) V_25 -> V_47 ;
}
static int F_36 ( int V_48 )
{
return ( V_48 + 1 ) & ( V_49 - 1 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_50 = F_36 ( V_2 -> V_50 ) ;
}
static struct V_30 * F_38 ( struct V_1 * V_2 )
{
return & V_2 -> V_51 -> V_25 [ V_2 -> V_50 ] ;
}
static struct V_30 *
F_39 ( struct V_1 * V_2 )
{
struct V_30 * V_25 = F_38 ( V_2 ) ;
while ( ! F_19 ( V_25 ) ) {
if ( F_16 ( V_25 ) )
return V_25 ;
F_20 ( V_25 ) ;
F_37 ( V_2 ) ;
V_25 = F_38 ( V_2 ) ;
}
return NULL ;
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_30 * V_25 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
bool error = false ;
if ( F_41 ( F_21 ( V_25 ) ) ) {
if ( F_42 () )
F_43 ( V_12 , L_2 ) ;
V_12 -> V_52 . V_53 ++ ;
error = true ;
}
if ( F_41 ( F_22 ( V_25 ) ) ) {
if ( F_42 () )
F_43 ( V_12 , L_3 ) ;
V_12 -> V_52 . V_54 ++ ;
error = true ;
}
if ( F_41 ( F_23 ( V_25 ) ) ) {
if ( F_42 () )
F_43 ( V_12 , L_4 ) ;
V_12 -> V_52 . V_55 ++ ;
error = true ;
} else if ( F_41 ( F_24 ( V_25 ) ) ) {
if ( F_42 () )
F_43 ( V_12 , L_5 ) ;
V_12 -> V_52 . V_55 ++ ;
error = true ;
} else if ( F_41 ( F_25 ( V_25 ) ) ) {
if ( F_42 () )
F_43 ( V_12 , L_6 ) ;
V_12 -> V_52 . V_55 ++ ;
error = true ;
}
return error ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_30 * V_25 = F_38 ( V_2 ) ;
bool V_56 = false ;
if ( F_42 () )
F_45 ( V_12 , L_7 , V_25 ) ;
do {
if ( F_18 ( V_25 ) )
V_56 = true ;
F_20 ( V_25 ) ;
F_37 ( V_2 ) ;
V_25 = F_38 ( V_2 ) ;
} while ( ! V_56 && ! F_19 ( V_25 ) );
V_12 -> V_52 . V_57 ++ ;
}
static bool F_46 ( struct V_1 * V_2 , int * V_58 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_30 * V_25 ;
struct V_59 * V_60 ;
struct V_46 * V_46 ;
T_1 V_61 ;
int V_62 ;
V_25 = F_39 ( V_2 ) ;
if ( ! V_25 )
return false ;
if ( F_41 ( F_40 ( V_2 , V_25 ) ) ) {
F_44 ( V_2 ) ;
return true ;
}
if ( F_41 ( ! F_18 ( V_25 ) ) )
F_47 () ;
V_60 = F_48 ( V_12 , 128 ) ;
if ( F_41 ( ! V_60 ) ) {
if ( F_42 () )
F_10 ( V_12 , L_8 ) ;
F_44 ( V_2 ) ;
return true ;
}
if ( F_41 ( F_28 ( V_25 ) ) )
V_12 -> V_52 . V_63 ++ ;
V_61 = F_33 ( V_25 ) ;
F_49 ( V_2 -> V_64 , V_61 , V_65 , V_66 ) ;
V_62 = F_26 ( V_25 ) ;
V_46 = F_35 ( V_25 ) ;
F_50 ( V_60 , 0 , V_46 , 0 , V_62 ) ;
V_60 -> V_67 += V_62 ;
V_60 -> V_68 += V_62 ;
if ( V_62 > 128 ) {
V_60 -> V_69 += V_70 ;
F_51 ( V_60 , V_71 ) ;
} else {
F_51 ( V_60 , V_62 ) ;
}
F_52 ( V_2 , V_25 , V_72 ) ;
F_37 ( V_2 ) ;
V_60 -> V_73 = F_53 ( V_60 , V_12 ) ;
V_12 -> V_52 . V_74 ++ ;
V_12 -> V_52 . V_75 += V_60 -> V_67 ;
F_54 ( V_60 ) ;
( * V_58 ) ++ ;
return true ;
}
static void F_55 ( struct V_76 * V_26 )
{
V_26 -> V_77 = 0 ;
V_26 -> V_78 &= F_17 ( V_79 ) ;
V_26 -> V_80 = 0 ;
V_26 -> V_81 = 0 ;
}
static bool F_56 ( struct V_76 * V_26 )
{
return V_26 -> V_77 & F_17 ( V_82 ) ;
}
static void F_57 ( struct V_76 * V_26 )
{
F_58 () ;
V_26 -> V_77 |= F_17 ( V_82 ) ;
}
static bool F_59 ( struct V_76 * V_26 )
{
return V_26 -> V_77 & F_17 ( V_83 ) ;
}
static bool F_60 ( struct V_76 * V_26 )
{
return V_26 -> V_77 & F_17 ( V_84 ) ;
}
static void F_61 ( struct V_76 * V_26 )
{
V_26 -> V_78 |= F_17 ( V_79 ) ;
}
static void F_62 ( struct V_76 * V_26 )
{
V_26 -> V_78 |= F_17 ( V_85 ) ;
}
static void F_63 ( struct V_76 * V_26 )
{
V_26 -> V_78 |= F_17 ( V_86 ) ;
}
static void F_64 ( struct V_76 * V_26 )
{
V_26 -> V_78 |= F_17 ( V_87 ) ;
}
static void F_65 ( struct V_76 * V_26 ,
unsigned int V_67 )
{
V_26 -> V_78 |= F_17 ( F_66 ( V_67 ) ) ;
}
static void F_67 ( struct V_76 * V_26 ,
T_1 V_7 )
{
V_26 -> V_80 = F_17 ( V_7 ) ;
}
static T_1 F_68 ( struct V_76 * V_26 )
{
return F_27 ( V_26 -> V_80 ) ;
}
static void F_69 ( struct V_76 * V_26 , struct V_59 * V_60 )
{
V_26 -> V_81 = ( unsigned int ) V_60 ;
}
static struct V_59 * F_70 ( struct V_76 * V_26 )
{
return (struct V_59 * ) V_26 -> V_81 ;
}
static int F_71 ( int V_48 )
{
return ( V_48 + 1 ) & ( V_88 - 1 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
V_2 -> V_89 = F_71 ( V_2 -> V_89 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_90 = F_71 ( V_2 -> V_90 ) ;
}
static struct V_76 * F_74 ( struct V_1 * V_2 )
{
return & V_2 -> V_51 -> V_26 [ V_2 -> V_89 ] ;
}
static struct V_76 * F_75 ( struct V_1 * V_2 )
{
return & V_2 -> V_51 -> V_26 [ V_2 -> V_90 ] ;
}
static bool F_76 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_76 * V_26 ;
struct V_59 * V_60 ;
T_1 V_61 ;
if ( V_2 -> V_91 == 0 )
return false ;
V_26 = F_75 ( V_2 ) ;
if ( F_56 ( V_26 ) )
return false ;
V_60 = F_70 ( V_26 ) ;
V_61 = F_68 ( V_26 ) ;
if ( F_41 ( F_59 ( V_26 ) ||
F_60 ( V_26 ) ) ) {
V_12 -> V_52 . V_92 ++ ;
} else {
V_12 -> V_52 . V_93 ++ ;
V_12 -> V_52 . V_94 += V_60 -> V_67 ;
}
F_77 ( V_2 -> V_64 , V_61 , F_78 ( V_60 ) , V_95 ) ;
F_79 ( V_60 ) ;
F_55 ( V_26 ) ;
F_73 ( V_2 ) ;
F_80 ( & V_2 -> V_96 ) ;
V_2 -> V_91 -- ;
F_81 ( & V_2 -> V_96 ) ;
F_82 ( V_12 ) ;
return true ;
}
static void F_83 ( struct V_1 * V_2 )
{
while ( F_76 ( V_2 ) )
;
}
static int F_84 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_61 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_76 * V_26 ;
unsigned int V_67 = ( V_60 -> V_67 < V_97 ) ? V_97 : V_60 -> V_67 ;
V_26 = F_74 ( V_2 ) ;
F_72 ( V_2 ) ;
F_69 ( V_26 , V_60 ) ;
F_67 ( V_26 , V_61 ) ;
F_62 ( V_26 ) ;
F_63 ( V_26 ) ;
F_64 ( V_26 ) ;
F_65 ( V_26 , V_67 ) ;
F_80 ( & V_2 -> V_96 ) ;
V_2 -> V_91 ++ ;
if ( V_2 -> V_91 == V_88 )
F_85 ( V_12 ) ;
F_57 ( V_26 ) ;
F_81 ( & V_2 -> V_96 ) ;
F_6 ( V_2 ) ;
return V_98 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_30 * V_25 , T_2 V_99 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_46 * V_46 ;
T_1 V_61 ;
V_46 = F_86 ( V_99 ) ;
if ( ! V_46 ) {
if ( F_42 () )
F_10 ( V_12 , L_9 ) ;
return - V_100 ;
}
V_61 = F_87 ( V_2 -> V_64 , V_46 , 0 , V_65 , V_66 ) ;
if ( F_41 ( F_88 ( V_2 -> V_64 , V_61 ) ) ) {
if ( F_42 () )
F_10 ( V_12 , L_10 ) ;
F_89 ( V_46 ) ;
return - V_100 ;
}
F_34 ( V_25 , V_46 ) ;
F_32 ( V_25 , V_61 ) ;
F_29 ( V_25 , V_65 ) ;
F_20 ( V_25 ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ ) {
struct V_30 * V_25 = & V_2 -> V_51 -> V_25 [ V_13 ] ;
struct V_46 * V_46 = F_35 ( V_25 ) ;
T_1 V_61 = F_33 ( V_25 ) ;
if ( ! V_46 )
continue;
F_49 ( V_2 -> V_64 , V_61 , V_65 , V_66 ) ;
F_89 ( V_46 ) ;
}
for ( V_13 = 0 ; V_13 < V_88 ; V_13 ++ ) {
struct V_76 * V_26 = & V_2 -> V_51 -> V_26 [ V_13 ] ;
struct V_59 * V_60 = F_70 ( V_26 ) ;
T_1 V_61 = F_68 ( V_26 ) ;
if ( ! V_60 )
continue;
F_77 ( V_2 -> V_64 , V_61 , F_78 ( V_60 ) , V_95 ) ;
F_79 ( V_60 ) ;
}
F_91 ( V_2 -> V_64 , sizeof( struct V_24 ) ,
V_2 -> V_51 , V_2 -> V_23 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_13 ;
V_2 -> V_51 = F_93 ( V_2 -> V_64 ,
sizeof( struct V_24 ) ,
& V_2 -> V_23 ,
V_101 ) ;
if ( ! V_2 -> V_51 )
return - V_100 ;
F_31 ( & V_2 -> V_51 -> V_25 [ V_49 - 1 ] ) ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ ) {
struct V_30 * V_25 = & V_2 -> V_51 -> V_25 [ V_13 ] ;
if ( F_52 ( V_2 , V_25 , V_101 ) )
goto V_102;
}
F_61 ( & V_2 -> V_51 -> V_26 [ V_88 - 1 ] ) ;
return 0 ;
V_102:
F_90 ( V_2 ) ;
return - V_100 ;
}
static int F_94 ( struct V_11 * V_12 , int V_103 , int V_104 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
unsigned int V_105 ;
int V_13 ;
V_105 = F_96 ( V_103 ) |
F_97 ( V_104 ) |
V_106 ;
F_2 ( V_105 , V_2 -> V_4 + V_107 ) ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
V_105 = F_8 ( V_2 -> V_4 + V_107 ) ;
if ( ( V_105 & V_106 ) == 0 )
return V_105 & V_108 ;
F_9 ( 100 ) ;
}
F_10 ( V_12 , L_11 ) ;
return 0 ;
}
static void F_98 ( struct V_11 * V_12 , int V_103 , int V_104 ,
int V_109 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
unsigned int V_105 ;
int V_13 ;
V_105 = F_96 ( V_103 ) |
F_97 ( V_104 ) |
V_110 ;
V_109 = F_99 ( V_109 ) ;
F_2 ( V_109 , V_2 -> V_4 + V_111 ) ;
F_2 ( V_105 , V_2 -> V_4 + V_107 ) ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
V_105 = F_8 ( V_2 -> V_4 + V_107 ) ;
if ( ( V_105 & V_110 ) == 0 )
return;
F_9 ( 100 ) ;
}
F_10 ( V_12 , L_12 ) ;
}
static void F_100 ( struct V_11 * V_12 ,
struct V_112 * V_113 )
{
F_101 ( V_113 -> V_114 , V_115 , sizeof( V_113 -> V_114 ) ) ;
F_101 ( V_113 -> V_116 , V_117 , sizeof( V_113 -> V_116 ) ) ;
F_101 ( V_113 -> V_118 , F_102 ( & V_12 -> V_64 ) , sizeof( V_113 -> V_118 ) ) ;
}
static int F_103 ( struct V_11 * V_12 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
F_104 ( & V_2 -> V_121 , V_120 ) ;
return 0 ;
}
static int F_105 ( struct V_11 * V_12 ,
const struct V_119 * V_120 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
return F_106 ( & V_2 -> V_121 , V_120 ) ;
}
static int F_107 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
return F_108 ( & V_2 -> V_121 ) ;
}
static T_3 F_109 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
return F_110 ( & V_2 -> V_121 ) ;
}
static T_4 F_111 ( int V_122 , void * V_123 )
{
struct V_11 * V_12 = V_123 ;
struct V_1 * V_2 = F_95 ( V_12 ) ;
if ( F_112 ( F_113 ( V_12 ) ) ) {
F_3 ( V_2 ) ;
F_114 ( & V_2 -> V_124 ) ;
}
return V_125 ;
}
static int F_115 ( struct V_126 * V_124 , int V_127 )
{
struct V_1 * V_2 = F_116 ( V_124 , struct V_1 , V_124 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned int V_128 ;
bool V_129 = true ;
int V_130 = 0 ;
V_128 = F_8 ( V_2 -> V_4 + V_131 ) ;
if ( V_128 & ( V_132 | V_133 ) ) {
bool V_134 ;
do {
V_134 = F_46 ( V_2 , & V_130 ) ;
} while ( V_134 && V_130 < V_127 );
if ( V_134 && V_130 == V_127 )
V_129 = false ;
}
if ( V_128 & ( V_135 | V_136 ) ) {
F_83 ( V_2 ) ;
}
if ( V_128 & ( V_133 | V_137 |
V_138 | V_139 ) ) {
if ( F_42 () )
F_43 ( V_12 , L_13 , V_128 ,
V_128 & V_133 ? L_14 : L_15 ,
V_128 & V_137 ? L_16 : L_15 ,
V_128 & V_138 ? L_17 : L_15 ,
V_128 & V_139 ? L_18 : L_15 ) ;
if ( V_128 & V_133 ) {
V_12 -> V_52 . V_140 ++ ;
}
if ( V_128 & V_137 ) {
V_12 -> V_52 . V_141 ++ ;
}
if ( V_128 & V_139 ) {
F_117 ( & V_2 -> V_121 ) ;
}
}
if ( V_129 ) {
F_118 ( V_124 ) ;
F_1 ( V_2 ) ;
}
return V_130 ;
}
static int F_119 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
int V_102 ;
V_102 = F_92 ( V_2 ) ;
if ( V_102 ) {
F_10 ( V_12 , L_19 ) ;
goto V_142;
}
V_102 = F_120 ( V_2 -> V_122 , F_111 , 0 , V_12 -> V_143 , V_12 ) ;
if ( V_102 ) {
F_10 ( V_12 , L_20 , V_2 -> V_122 ) ;
goto V_144;
}
V_2 -> V_50 = 0 ;
V_2 -> V_90 = 0 ;
V_2 -> V_89 = 0 ;
V_2 -> V_91 = 0 ;
V_102 = F_12 ( V_2 ) ;
if ( V_102 )
goto V_145;
F_121 ( & V_2 -> V_124 ) ;
F_122 ( V_12 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_145:
F_123 ( V_2 -> V_122 , V_12 ) ;
V_144:
F_90 ( V_2 ) ;
V_142:
return V_102 ;
}
static int F_124 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
F_3 ( V_2 ) ;
F_85 ( V_12 ) ;
F_125 ( & V_2 -> V_124 ) ;
F_15 ( V_2 ) ;
F_123 ( V_2 -> V_122 , V_12 ) ;
F_90 ( V_2 ) ;
return 0 ;
}
static int F_126 ( struct V_59 * V_60 , struct V_11 * V_12 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
T_1 V_61 ;
if ( F_41 ( V_60 -> V_67 > V_146 ) ) {
if ( F_42 () )
F_45 ( V_12 , L_21 ) ;
V_12 -> V_52 . V_147 ++ ;
F_79 ( V_60 ) ;
return V_98 ;
}
V_61 = F_127 ( V_2 -> V_64 , V_60 -> V_109 , F_78 ( V_60 ) , V_95 ) ;
if ( F_41 ( F_88 ( V_2 -> V_64 , V_61 ) ) ) {
if ( F_42 () )
F_10 ( V_12 , L_22 ) ;
V_12 -> V_52 . V_147 ++ ;
F_79 ( V_60 ) ;
return V_98 ;
}
return F_84 ( V_2 , V_60 , V_61 ) ;
}
static int F_128 ( struct V_11 * V_12 , struct V_148 * V_149 , int V_120 )
{
struct V_1 * V_2 = F_95 ( V_12 ) ;
struct V_150 * V_109 = F_129 ( V_149 ) ;
return F_130 ( & V_2 -> V_121 , V_109 , V_120 , NULL ) ;
}
static int F_131 ( struct V_151 * V_152 )
{
struct V_153 * V_154 ;
int V_122 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_102 ;
if ( ! V_152 )
return - V_155 ;
V_154 = F_132 ( V_152 , V_156 , 0 ) ;
if ( ! V_154 )
return - V_157 ;
V_122 = F_133 ( V_152 , 0 ) ;
if ( V_122 < 0 )
return V_122 ;
V_12 = F_134 ( sizeof( * V_2 ) ) ;
if ( ! V_12 ) {
V_102 = - V_100 ;
goto V_158;
}
F_135 ( V_12 , & V_152 -> V_64 ) ;
V_12 -> V_159 = & V_160 ;
V_12 -> V_161 = & V_162 ;
F_136 ( V_152 , V_12 ) ;
V_2 = F_95 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_64 = & V_152 -> V_64 ;
F_137 ( & V_2 -> V_96 ) ;
F_138 ( V_12 , & V_2 -> V_124 , F_115 , 64 ) ;
V_2 -> V_154 = F_139 ( V_154 -> V_163 , F_140 ( V_154 ) ,
F_102 ( & V_152 -> V_64 ) ) ;
if ( ! V_2 -> V_154 ) {
F_141 ( & V_152 -> V_64 , L_23 ) ;
V_102 = - V_100 ;
goto V_164;
}
V_2 -> V_4 = F_142 ( V_154 -> V_163 , F_140 ( V_154 ) ) ;
if ( ! V_2 -> V_4 ) {
F_141 ( & V_152 -> V_64 , L_24 ) ;
V_102 = - V_17 ;
goto V_165;
}
V_2 -> V_122 = V_122 ;
V_2 -> V_121 . V_103 = 0 ;
V_2 -> V_121 . V_166 = 0x1f ;
V_2 -> V_121 . V_167 = 0x1f ;
V_2 -> V_121 . V_64 = V_12 ;
V_2 -> V_121 . V_168 = F_94 ;
V_2 -> V_121 . V_169 = F_98 ;
V_102 = F_143 ( V_12 ) ;
if ( V_102 ) {
F_141 ( & V_152 -> V_64 , L_25 ) ;
goto V_170;
}
F_43 ( V_12 , L_26 , V_2 -> V_122 , V_2 -> V_4 ) ;
if ( ! F_144 ( V_12 -> V_28 ) ) {
F_145 ( V_12 ) ;
F_43 ( V_12 , L_27 ,
V_12 -> V_28 ) ;
}
return 0 ;
V_170:
F_146 ( V_2 -> V_4 ) ;
V_165:
F_147 ( V_2 -> V_154 ) ;
V_164:
F_148 ( & V_2 -> V_124 ) ;
F_149 ( V_12 ) ;
V_158:
return V_102 ;
}
static int F_150 ( struct V_151 * V_152 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_151 ( V_152 ) ;
V_2 = F_95 ( V_12 ) ;
F_152 ( V_12 ) ;
F_146 ( V_2 -> V_4 ) ;
F_147 ( V_2 -> V_154 ) ;
F_148 ( & V_2 -> V_124 ) ;
F_149 ( V_12 ) ;
return 0 ;
}
static int T_5 F_153 ( void )
{
F_154 ( L_28 V_117 L_29 ) ;
return F_155 ( & V_171 ) ;
}
static void T_6 F_156 ( void )
{
F_157 ( & V_171 ) ;
}
