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
if ( V_68 -> V_76 <= 64 )
V_68 -> V_78 -= V_79 ;
F_56 ( V_68 , F_57 ( V_68 -> V_76 , 64U ) ) ;
V_68 -> V_81 = F_58 ( V_68 , V_11 ) ;
V_11 -> V_60 . V_82 ++ ;
V_11 -> V_60 . V_83 += V_68 -> V_76 ;
F_59 ( & V_2 -> V_84 , V_68 ) ;
( * V_66 ) ++ ;
return true ;
}
static void F_60 ( struct V_85 * V_25 )
{
V_25 -> V_86 &= F_18 ( V_87 ) ;
V_25 -> V_88 = 0 ;
V_25 -> V_89 = 0 ;
V_25 -> V_90 = 0 ;
}
static bool F_61 ( struct V_85 * V_25 )
{
return V_25 -> V_86 & F_18 ( V_91 ) ;
}
static void F_62 ( struct V_85 * V_25 )
{
F_63 () ;
V_25 -> V_86 |= F_18 ( V_91 ) ;
}
static void F_64 ( struct V_85 * V_25 )
{
V_25 -> V_86 |= F_18 ( V_87 ) ;
}
static void F_65 ( struct V_85 * V_25 )
{
V_25 -> V_86 |= F_18 ( V_92 ) ;
}
static void F_66 ( struct V_85 * V_25 )
{
V_25 -> V_86 |= F_18 ( V_93 ) ;
}
static void F_67 ( struct V_85 * V_25 ,
unsigned int V_76 )
{
V_25 -> V_86 |= F_18 ( F_68 ( V_76 ) ) ;
}
static void F_69 ( struct V_85 * V_25 )
{
V_25 -> V_88 |= F_18 ( V_94 ) ;
}
static void F_70 ( struct V_85 * V_25 )
{
V_25 -> V_88 |= F_18 ( V_95 ) ;
}
static void F_71 ( struct V_85 * V_25 )
{
V_25 -> V_88 |= F_18 ( V_96 ) ;
}
static void F_72 ( struct V_85 * V_25 )
{
V_25 -> V_88 |= F_18 ( V_97 ) ;
}
static void F_73 ( struct V_85 * V_25 ,
T_1 V_3 )
{
V_25 -> V_90 = F_18 ( V_3 ) ;
}
static T_1 F_74 ( struct V_85 * V_25 )
{
return F_28 ( V_25 -> V_90 ) ;
}
static void F_75 ( struct V_85 * V_25 ,
struct V_67 * V_68 )
{
V_25 -> V_89 = ( unsigned int ) V_68 ;
}
static struct V_67 * F_76 ( struct V_85 * V_25 )
{
return (struct V_67 * ) V_25 -> V_89 ;
}
static int F_77 ( int V_56 )
{
return ( V_56 + 1 ) & ( V_98 - 1 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_99 = F_77 ( V_2 -> V_99 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_100 = F_77 ( V_2 -> V_100 ) ;
}
static struct V_85 * F_80 ( struct V_1 * V_2 )
{
return & V_2 -> V_59 -> V_25 [ V_2 -> V_99 ] ;
}
static struct V_85 *
F_81 ( struct V_1 * V_2 )
{
return & V_2 -> V_59 -> V_25 [ V_2 -> V_100 ] ;
}
static bool F_82 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_85 * V_25 ;
struct V_67 * V_68 ;
T_1 V_72 ;
if ( V_2 -> V_101 == 0 )
return false ;
V_25 = F_81 ( V_2 ) ;
if ( F_61 ( V_25 ) )
return false ;
V_68 = F_76 ( V_25 ) ;
V_72 = F_74 ( V_25 ) ;
V_11 -> V_60 . V_102 ++ ;
V_11 -> V_60 . V_103 += V_68 -> V_76 ;
F_83 ( V_2 -> V_73 , V_72 , F_84 ( V_68 ) , V_104 ) ;
F_85 ( V_68 ) ;
F_60 ( V_25 ) ;
F_79 ( V_2 ) ;
F_86 ( & V_2 -> V_105 ) ;
V_2 -> V_101 -- ;
F_87 ( & V_2 -> V_105 ) ;
F_88 ( V_11 ) ;
return true ;
}
static void F_89 ( struct V_1 * V_2 )
{
while ( F_82 ( V_2 ) )
;
}
static int F_90 ( struct V_1 * V_2 , struct V_67 * V_68 ,
T_1 V_72 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_85 * V_25 ;
unsigned int V_76 = ( V_68 -> V_76 < V_106 ) ? V_106 : V_68 -> V_76 ;
V_25 = F_80 ( V_2 ) ;
F_78 ( V_2 ) ;
F_75 ( V_25 , V_68 ) ;
F_73 ( V_25 , V_72 ) ;
F_67 ( V_25 , V_76 ) ;
F_65 ( V_25 ) ;
F_66 ( V_25 ) ;
F_69 ( V_25 ) ;
if ( V_68 -> V_70 == V_107 ) {
T_2 V_81 = V_68 -> V_81 ;
if ( V_81 == F_91 ( V_108 ) ) {
T_3 V_109 = F_92 ( V_68 ) -> V_81 ;
F_72 ( V_25 ) ;
if ( V_109 == V_110 )
F_70 ( V_25 ) ;
else if ( V_109 == V_111 )
F_71 ( V_25 ) ;
}
}
F_86 ( & V_2 -> V_105 ) ;
V_2 -> V_101 ++ ;
if ( V_2 -> V_101 == V_98 )
F_93 ( V_11 ) ;
F_62 ( V_25 ) ;
F_87 ( & V_2 -> V_105 ) ;
F_6 ( V_2 ) ;
return V_112 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_33 * V_24 , T_4 V_113 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_54 * V_54 ;
T_1 V_72 ;
V_54 = F_94 ( V_113 ) ;
if ( ! V_54 ) {
if ( F_46 () )
F_10 ( V_11 , L_10 ) ;
return - V_114 ;
}
V_72 = F_95 ( V_2 -> V_73 , V_54 , 0 , V_26 , V_74 ) ;
if ( F_45 ( F_96 ( V_2 -> V_73 , V_72 ) ) ) {
if ( F_46 () )
F_10 ( V_11 , L_11 ) ;
F_97 ( V_54 ) ;
return - V_114 ;
}
F_38 ( V_24 , V_54 ) ;
F_31 ( V_24 , V_72 ) ;
F_21 ( V_24 ) ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
struct V_33 * V_24 = & V_2 -> V_59 -> V_24 [ V_12 ] ;
struct V_54 * V_54 = F_39 ( V_24 ) ;
T_1 V_72 = F_32 ( V_24 ) ;
if ( ! V_54 )
continue;
F_52 ( V_2 -> V_73 , V_72 , V_26 , V_74 ) ;
F_97 ( V_54 ) ;
}
for ( V_12 = 0 ; V_12 < V_98 ; V_12 ++ ) {
struct V_85 * V_25 = & V_2 -> V_59 -> V_25 [ V_12 ] ;
struct V_67 * V_68 = F_76 ( V_25 ) ;
T_1 V_72 = F_74 ( V_25 ) ;
if ( ! V_68 )
continue;
F_83 ( V_2 -> V_73 , V_72 , F_84 ( V_68 ) , V_104 ) ;
F_85 ( V_68 ) ;
}
F_99 ( V_2 -> V_73 , sizeof( struct V_23 ) ,
V_2 -> V_59 , V_2 -> V_22 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_59 = F_101 ( V_2 -> V_73 ,
sizeof( struct V_23 ) ,
& V_2 -> V_22 , V_115 ) ;
if ( ! V_2 -> V_59 )
return - V_114 ;
memset ( V_2 -> V_59 , 0 , sizeof( struct V_23 ) ) ;
F_30 ( & V_2 -> V_59 -> V_24 [ V_57 - 1 ] ) ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
struct V_33 * V_24 = & V_2 -> V_59 -> V_24 [ V_12 ] ;
if ( F_55 ( V_2 , V_24 , V_115 ) )
goto V_116;
}
F_64 ( & V_2 -> V_59 -> V_25 [ V_98 - 1 ] ) ;
return 0 ;
V_116:
F_98 ( V_2 ) ;
return - V_114 ;
}
static void F_102 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
struct V_117 * V_118 = V_2 -> V_118 ;
int V_119 ;
if ( V_118 -> V_29 == V_2 -> V_120 )
return;
V_2 -> V_120 = V_118 -> V_29 ;
V_119 = F_8 ( V_2 -> V_4 + V_121 ) ;
F_2 ( 0 , V_2 -> V_4 + V_121 ) ;
F_93 ( V_11 ) ;
F_16 ( V_2 ) ;
F_104 ( V_11 ) ;
F_12 ( V_2 ) ;
F_15 ( V_2 , V_118 -> V_29 ) ;
F_2 ( V_119 , V_2 -> V_4 + V_121 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_117 * V_118 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_122 ; V_12 ++ ) {
struct V_117 * V_123 = V_2 -> V_124 -> V_125 [ V_12 ] ;
if ( V_123 ) {
V_118 = V_123 ;
break;
}
}
if ( ! V_118 ) {
F_47 ( V_11 , L_12 , V_11 -> V_126 ) ;
return - V_127 ;
}
V_118 = F_106 ( V_11 , F_107 ( & V_118 -> V_73 ) ,
& F_102 , 0 ,
V_128 ) ;
if ( F_108 ( V_118 ) ) {
F_10 ( V_11 , L_13 , V_11 -> V_126 ) ;
return F_109 ( V_118 ) ;
}
V_2 -> V_118 = V_118 ;
return 0 ;
}
static int F_110 ( struct V_124 * V_129 , int V_130 , int V_131 )
{
struct V_10 * V_11 = V_129 -> V_2 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
unsigned int V_132 ;
int V_12 ;
V_132 = F_8 ( V_2 -> V_4 + V_133 ) ;
V_132 &= V_134 ;
V_132 |= F_111 ( V_130 ) |
F_112 ( V_131 ) |
V_135 ;
F_2 ( V_132 , V_2 -> V_4 + V_133 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_132 = F_8 ( V_2 -> V_4 + V_133 ) ;
if ( ( V_132 & V_135 ) == 0 ) {
int V_136 ;
V_136 = F_8 ( V_2 -> V_4 + V_137 ) ;
return F_113 ( V_136 ) ;
}
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_14 ) ;
return - V_16 ;
}
static int F_114 ( struct V_124 * V_129 , int V_130 ,
int V_131 , T_5 V_138 )
{
struct V_10 * V_11 = V_129 -> V_2 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
unsigned int V_132 ;
int V_136 ;
int V_12 ;
V_132 = F_8 ( V_2 -> V_4 + V_133 ) ;
V_132 &= V_134 ;
V_132 |= F_111 ( V_130 ) |
F_112 ( V_131 ) |
V_139 ;
V_136 = F_115 ( V_138 ) ;
F_2 ( V_136 , V_2 -> V_4 + V_137 ) ;
F_2 ( V_132 , V_2 -> V_4 + V_133 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_132 = F_8 ( V_2 -> V_4 + V_133 ) ;
if ( ( V_132 & V_139 ) == 0 )
return 0 ;
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_15 ) ;
return - V_16 ;
}
static int F_116 ( struct V_124 * V_129 )
{
return 0 ;
}
static void F_117 ( struct V_10 * V_11 ,
struct V_140 * V_141 )
{
strcpy ( V_141 -> V_142 , V_143 ) ;
strcpy ( V_141 -> V_144 , V_145 ) ;
strcpy ( V_141 -> V_146 , F_107 ( & V_11 -> V_73 ) ) ;
}
static int F_118 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_119 ( V_2 -> V_118 , V_148 ) ;
}
static int F_120 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_121 ( V_2 -> V_118 , V_148 ) ;
}
static T_6 F_122 ( int V_149 , void * V_150 )
{
struct V_10 * V_11 = V_150 ;
struct V_1 * V_2 = F_103 ( V_11 ) ;
if ( F_123 ( F_124 ( V_11 ) ) ) {
F_2 ( 0 , V_2 -> V_4 + V_121 ) ;
F_125 ( & V_2 -> V_84 ) ;
}
return V_151 ;
}
static int F_126 ( struct V_152 * V_84 , int V_153 )
{
struct V_1 * V_2 = F_127 ( V_84 , struct V_1 , V_84 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_154 ;
bool V_155 = true ;
int V_156 = 0 ;
V_154 = F_8 ( V_2 -> V_4 + V_157 ) ;
F_2 ( V_154 , V_2 -> V_4 + V_157 ) ;
if ( V_154 & ( V_158 | V_159 ) ) {
bool V_160 ;
do {
V_160 = F_50 ( V_2 , & V_156 ) ;
} while ( V_160 && V_156 < V_153 );
if ( V_160 && V_156 == V_153 )
V_155 = false ;
}
if ( V_154 & ( V_161 | V_162 ) ) {
F_89 ( V_2 ) ;
}
if ( V_154 & ( V_159 | V_163 |
V_164 | V_165 ) ) {
if ( F_46 () )
F_47 ( V_11 , L_16 , V_154 ,
V_154 & V_159 ? L_17 : L_18 ,
V_154 & V_163 ? L_19 : L_18 ,
V_154 & V_164 ? L_20 : L_18 ,
V_154 & V_165 ? L_21 : L_18 ) ;
if ( V_154 & V_159 ) {
V_11 -> V_60 . V_166 ++ ;
}
if ( V_154 & V_163 ) {
V_11 -> V_60 . V_167 ++ ;
}
}
if ( V_155 ) {
F_128 ( V_84 ) ;
F_2 ( V_168 , V_2 -> V_4 + V_121 ) ;
}
return V_156 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
int V_116 ;
V_116 = F_100 ( V_2 ) ;
if ( V_116 ) {
F_10 ( V_11 , L_22 ) ;
goto V_169;
}
V_116 = F_130 ( V_2 -> V_149 , F_122 , 0 , V_11 -> V_126 , V_11 ) ;
if ( V_116 ) {
F_10 ( V_11 , L_23 , V_2 -> V_149 ) ;
goto V_170;
}
V_2 -> V_58 = 0 ;
V_2 -> V_100 = 0 ;
V_2 -> V_99 = 0 ;
V_2 -> V_101 = 0 ;
V_116 = F_7 ( V_2 ) ;
if ( V_116 )
goto V_171;
F_12 ( V_2 ) ;
F_15 ( V_2 , 10 ) ;
F_131 ( V_2 -> V_118 ) ;
F_132 ( & V_2 -> V_84 ) ;
F_104 ( V_11 ) ;
F_2 ( V_168 , V_2 -> V_4 + V_121 ) ;
return 0 ;
V_171:
F_133 ( V_2 -> V_149 , V_11 ) ;
V_170:
F_98 ( V_2 ) ;
V_169:
return V_116 ;
}
static int F_134 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
F_2 ( 0 , V_2 -> V_4 + V_121 ) ;
F_93 ( V_11 ) ;
F_135 ( & V_2 -> V_84 ) ;
F_136 ( V_2 -> V_118 ) ;
F_16 ( V_2 ) ;
F_133 ( V_2 -> V_149 , V_11 ) ;
F_98 ( V_2 ) ;
return 0 ;
}
static int F_137 ( struct V_67 * V_68 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
T_1 V_72 ;
if ( F_45 ( V_68 -> V_76 > V_172 ) ) {
if ( F_46 () )
F_49 ( V_11 , L_24 ) ;
V_11 -> V_60 . V_173 ++ ;
F_85 ( V_68 ) ;
return V_112 ;
}
V_72 = F_138 ( V_2 -> V_73 , V_68 -> V_136 , F_84 ( V_68 ) , V_104 ) ;
if ( F_45 ( F_96 ( V_2 -> V_73 , V_72 ) ) ) {
if ( F_46 () )
F_10 ( V_11 , L_25 ) ;
V_11 -> V_60 . V_173 ++ ;
F_85 ( V_68 ) ;
return V_112 ;
}
return F_90 ( V_2 , V_68 , V_72 ) ;
}
static int F_139 ( struct V_10 * V_11 , struct V_174 * V_175 , int V_148 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
return F_140 ( V_2 -> V_118 , V_175 , V_148 ) ;
}
static int F_141 ( struct V_176 * V_177 )
{
struct V_178 * V_179 ;
int V_149 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_116 ;
int V_12 ;
if ( ! V_177 )
return - V_127 ;
V_179 = F_142 ( V_177 , V_180 , 0 ) ;
if ( ! V_179 )
return - V_181 ;
V_149 = F_143 ( V_177 , 0 ) ;
if ( V_149 < 0 )
return V_149 ;
V_11 = F_144 ( sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
V_116 = - V_114 ;
goto V_182;
}
F_145 ( V_11 , & V_177 -> V_73 ) ;
F_146 ( V_11 , & V_183 ) ;
V_11 -> V_184 = & V_185 ;
V_11 -> V_186 = V_187 | V_188 ;
F_147 ( V_177 , V_11 ) ;
V_2 = F_103 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_73 = & V_177 -> V_73 ;
F_148 ( & V_2 -> V_105 ) ;
F_149 ( V_11 , & V_2 -> V_84 , F_126 , 64 ) ;
V_2 -> V_179 = F_150 ( V_179 -> V_189 , F_151 ( V_179 ) ,
F_107 ( & V_177 -> V_73 ) ) ;
if ( ! V_2 -> V_179 ) {
F_152 ( & V_177 -> V_73 , L_26 ) ;
V_116 = - V_114 ;
goto V_190;
}
V_2 -> V_4 = F_153 ( V_179 -> V_189 , F_151 ( V_179 ) ) ;
if ( ! V_2 -> V_4 ) {
F_152 ( & V_177 -> V_73 , L_27 ) ;
V_116 = - V_16 ;
goto V_191;
}
V_2 -> V_149 = V_149 ;
V_2 -> V_124 = F_154 () ;
if ( ! V_2 -> V_124 ) {
V_116 = - V_16 ;
goto V_192;
}
V_2 -> V_124 -> V_126 = L_28 ;
snprintf ( V_2 -> V_124 -> V_193 , V_194 , L_29 ) ;
V_2 -> V_124 -> V_2 = V_11 ;
V_2 -> V_124 -> V_195 = F_110 ;
V_2 -> V_124 -> V_196 = F_114 ;
V_2 -> V_124 -> V_197 = F_116 ;
V_2 -> V_124 -> V_149 = V_2 -> V_198 ;
for ( V_12 = 0 ; V_12 < V_122 ; V_12 ++ )
V_2 -> V_124 -> V_149 [ V_12 ] = V_199 ;
V_116 = F_155 ( V_2 -> V_124 ) ;
if ( V_116 ) {
F_152 ( & V_177 -> V_73 , L_30 ) ;
goto V_200;
}
V_116 = F_105 ( V_2 ) ;
if ( V_116 ) {
F_152 ( & V_177 -> V_73 , L_31 ) ;
goto V_201;
}
V_116 = F_156 ( V_11 ) ;
if ( V_116 ) {
F_152 ( & V_177 -> V_73 , L_32 ) ;
goto V_202;
}
F_47 ( V_11 , L_33 , V_2 -> V_149 , V_2 -> V_4 ) ;
if ( ! F_157 ( V_11 -> V_28 ) ) {
F_158 ( V_11 -> V_28 ) ;
F_47 ( V_11 , L_34 ,
V_11 -> V_28 ) ;
}
return 0 ;
V_202:
F_159 ( V_2 -> V_118 ) ;
V_201:
F_160 ( V_2 -> V_124 ) ;
V_200:
F_161 ( V_2 -> V_124 ) ;
V_192:
F_162 ( V_2 -> V_4 ) ;
V_191:
F_163 ( V_2 -> V_179 ) ;
V_190:
F_164 ( & V_2 -> V_84 ) ;
F_147 ( V_177 , NULL ) ;
F_165 ( V_11 ) ;
V_182:
return V_116 ;
}
static int T_7 F_166 ( struct V_176 * V_177 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_167 ( V_177 ) ;
V_2 = F_103 ( V_11 ) ;
F_168 ( V_11 ) ;
F_159 ( V_2 -> V_118 ) ;
F_160 ( V_2 -> V_124 ) ;
F_161 ( V_2 -> V_124 ) ;
F_162 ( V_2 -> V_4 ) ;
F_163 ( V_2 -> V_179 ) ;
F_164 ( & V_2 -> V_84 ) ;
F_147 ( V_177 , NULL ) ;
F_165 ( V_11 ) ;
return 0 ;
}
static int T_8 F_169 ( void )
{
F_170 ( L_35 V_145 L_36 ) ;
return F_171 ( & V_203 ) ;
}
static void T_7 F_172 ( void )
{
F_173 ( & V_203 ) ;
}
