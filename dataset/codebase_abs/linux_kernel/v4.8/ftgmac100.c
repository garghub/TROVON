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
T_2 V_17 [ V_22 ] ;
unsigned int V_23 ;
unsigned int V_24 ;
void * V_3 ;
V_3 = F_13 ( V_2 -> V_25 , V_17 , V_22 ) ;
if ( V_3 ) {
F_14 ( V_2 -> V_11 -> V_26 , V_17 ) ;
F_15 ( V_2 -> V_25 , L_2 ,
V_17 ) ;
return;
}
V_23 = F_8 ( V_2 -> V_4 + V_20 ) ;
V_24 = F_8 ( V_2 -> V_4 + V_21 ) ;
V_17 [ 0 ] = ( V_23 >> 8 ) & 0xff ;
V_17 [ 1 ] = V_23 & 0xff ;
V_17 [ 2 ] = ( V_24 >> 24 ) & 0xff ;
V_17 [ 3 ] = ( V_24 >> 16 ) & 0xff ;
V_17 [ 4 ] = ( V_24 >> 8 ) & 0xff ;
V_17 [ 5 ] = V_24 & 0xff ;
if ( F_16 ( V_17 ) ) {
F_14 ( V_2 -> V_11 -> V_26 , V_17 ) ;
F_15 ( V_2 -> V_25 , L_3 , V_17 ) ;
} else {
F_17 ( V_2 -> V_11 ) ;
F_15 ( V_2 -> V_25 , L_4 ,
V_2 -> V_11 -> V_26 ) ;
}
}
static int F_18 ( struct V_10 * V_25 , void * V_27 )
{
int V_28 ;
V_28 = F_19 ( V_25 , V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
F_20 ( V_25 , V_27 ) ;
F_11 ( F_21 ( V_25 ) , V_25 -> V_26 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
V_2 -> V_29 +
F_23 ( struct V_30 , V_31 ) ) ;
F_5 ( V_2 ,
V_2 -> V_29 +
F_23 ( struct V_30 , V_32 ) ) ;
F_3 ( V_2 , V_33 ) ;
F_2 ( F_24 ( 1 ) , V_2 -> V_4 + V_34 ) ;
F_11 ( V_2 , V_2 -> V_11 -> V_26 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_35 )
{
int V_15 = V_36 ;
switch ( V_35 ) {
default:
case 10 :
break;
case 100 :
V_15 |= V_37 ;
break;
case 1000 :
V_15 |= V_38 ;
break;
}
F_2 ( V_15 , V_2 -> V_4 + V_14 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_14 ) ;
}
static bool F_27 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_41 ) ;
}
static bool F_29 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_42 ) ;
}
static bool F_30 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_43 ) ;
}
static void F_31 ( struct V_39 * V_31 )
{
V_31 -> V_40 &= F_28 ( V_44 ) ;
}
static bool F_32 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_45 ) ;
}
static bool F_33 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_46 ) ;
}
static bool F_34 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_47 ) ;
}
static bool F_35 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_48 ) ;
}
static bool F_36 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_49 ) ;
}
static unsigned int F_37 ( struct V_39 * V_31 )
{
return F_38 ( V_31 -> V_40 ) & V_50 ;
}
static bool F_39 ( struct V_39 * V_31 )
{
return V_31 -> V_40 & F_28 ( V_51 ) ;
}
static void F_40 ( struct V_39 * V_31 )
{
V_31 -> V_40 |= F_28 ( V_44 ) ;
}
static void F_41 ( struct V_39 * V_31 ,
T_1 V_3 )
{
V_31 -> V_52 = F_28 ( V_3 ) ;
}
static T_1 F_42 ( struct V_39 * V_31 )
{
return F_38 ( V_31 -> V_52 ) ;
}
static bool F_43 ( struct V_39 * V_31 )
{
return ( V_31 -> V_53 & F_28 ( V_54 ) ) ==
F_28 ( V_55 ) ;
}
static bool F_44 ( struct V_39 * V_31 )
{
return ( V_31 -> V_53 & F_28 ( V_54 ) ) ==
F_28 ( V_56 ) ;
}
static bool F_45 ( struct V_39 * V_31 )
{
return V_31 -> V_53 & F_28 ( V_57 ) ;
}
static bool F_46 ( struct V_39 * V_31 )
{
return V_31 -> V_53 & F_28 ( V_58 ) ;
}
static bool F_47 ( struct V_39 * V_31 )
{
return V_31 -> V_53 & F_28 ( V_59 ) ;
}
static void F_48 ( struct V_39 * V_31 , struct V_60 * V_60 )
{
V_31 -> V_61 = ( unsigned int ) V_60 ;
}
static struct V_60 * F_49 ( struct V_39 * V_31 )
{
return (struct V_60 * ) V_31 -> V_61 ;
}
static int F_50 ( int V_62 )
{
return ( V_62 + 1 ) & ( V_63 - 1 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_64 = F_50 ( V_2 -> V_64 ) ;
}
static struct V_39 * F_52 ( struct V_1 * V_2 )
{
return & V_2 -> V_65 -> V_31 [ V_2 -> V_64 ] ;
}
static struct V_39 *
F_53 ( struct V_1 * V_2 )
{
struct V_39 * V_31 = F_52 ( V_2 ) ;
while ( F_30 ( V_31 ) ) {
if ( F_27 ( V_31 ) )
return V_31 ;
F_31 ( V_31 ) ;
F_51 ( V_2 ) ;
V_31 = F_52 ( V_2 ) ;
}
return NULL ;
}
static bool F_54 ( struct V_1 * V_2 ,
struct V_39 * V_31 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
bool error = false ;
if ( F_55 ( F_32 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_5 ) ;
V_11 -> V_66 . V_67 ++ ;
error = true ;
}
if ( F_55 ( F_33 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_6 ) ;
V_11 -> V_66 . V_68 ++ ;
error = true ;
} else if ( F_55 ( F_47 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_7 ) ;
error = true ;
}
if ( F_55 ( F_34 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_8 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
} else if ( F_55 ( F_35 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_9 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
} else if ( F_55 ( F_36 ( V_31 ) ) ) {
if ( F_56 () )
F_57 ( V_11 , L_10 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
}
return error ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_39 * V_31 = F_52 ( V_2 ) ;
bool V_70 = false ;
if ( F_56 () )
F_59 ( V_11 , L_11 , V_31 ) ;
do {
if ( F_29 ( V_31 ) )
V_70 = true ;
F_31 ( V_31 ) ;
F_51 ( V_2 ) ;
V_31 = F_52 ( V_2 ) ;
} while ( ! V_70 && F_30 ( V_31 ) );
V_11 -> V_66 . V_71 ++ ;
}
static bool F_60 ( struct V_1 * V_2 , int * V_72 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_39 * V_31 ;
struct V_73 * V_74 ;
bool V_70 = false ;
V_31 = F_53 ( V_2 ) ;
if ( ! V_31 )
return false ;
if ( F_55 ( F_54 ( V_2 , V_31 ) ) ) {
F_58 ( V_2 ) ;
return true ;
}
V_74 = F_61 ( V_11 , 128 ) ;
if ( F_55 ( ! V_74 ) ) {
if ( F_56 () )
F_10 ( V_11 , L_12 ) ;
F_58 ( V_2 ) ;
return true ;
}
if ( F_55 ( F_39 ( V_31 ) ) )
V_11 -> V_66 . V_75 ++ ;
if ( ( F_43 ( V_31 ) && ! F_45 ( V_31 ) ) ||
( F_44 ( V_31 ) && ! F_46 ( V_31 ) ) )
V_74 -> V_76 = V_77 ;
do {
T_1 V_78 = F_42 ( V_31 ) ;
struct V_60 * V_60 = F_49 ( V_31 ) ;
unsigned int V_6 ;
F_62 ( V_2 -> V_25 , V_78 , V_33 , V_79 ) ;
V_6 = F_37 ( V_31 ) ;
F_63 ( V_74 , F_64 ( V_74 ) -> V_80 , V_60 , 0 , V_6 ) ;
V_74 -> V_81 += V_6 ;
V_74 -> V_82 += V_6 ;
V_74 -> V_83 += V_84 ;
if ( F_29 ( V_31 ) )
V_70 = true ;
F_65 ( V_2 , V_31 , V_85 ) ;
F_51 ( V_2 ) ;
V_31 = F_52 ( V_2 ) ;
} while ( ! V_70 );
if ( V_74 -> V_81 <= 128 ) {
V_74 -> V_83 -= V_84 ;
F_66 ( V_74 , V_74 -> V_81 ) ;
} else {
F_66 ( V_74 , V_86 ) ;
}
V_74 -> V_87 = F_67 ( V_74 , V_11 ) ;
V_11 -> V_66 . V_88 ++ ;
V_11 -> V_66 . V_89 += V_74 -> V_81 ;
F_68 ( & V_2 -> V_90 , V_74 ) ;
( * V_72 ) ++ ;
return true ;
}
static void F_69 ( struct V_91 * V_32 )
{
V_32 -> V_92 &= F_28 ( V_93 ) ;
V_32 -> V_94 = 0 ;
V_32 -> V_95 = 0 ;
V_32 -> V_96 = 0 ;
}
static bool F_70 ( struct V_91 * V_32 )
{
return V_32 -> V_92 & F_28 ( V_97 ) ;
}
static void F_71 ( struct V_91 * V_32 )
{
F_72 () ;
V_32 -> V_92 |= F_28 ( V_97 ) ;
}
static void F_73 ( struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_93 ) ;
}
static void F_74 ( struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_98 ) ;
}
static void F_75 ( struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_99 ) ;
}
static void F_76 ( struct V_91 * V_32 ,
unsigned int V_81 )
{
V_32 -> V_92 |= F_28 ( F_77 ( V_81 ) ) ;
}
static void F_78 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_100 ) ;
}
static void F_79 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_101 ) ;
}
static void F_80 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_102 ) ;
}
static void F_81 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_103 ) ;
}
static void F_82 ( struct V_91 * V_32 ,
T_1 V_3 )
{
V_32 -> V_96 = F_28 ( V_3 ) ;
}
static T_1 F_83 ( struct V_91 * V_32 )
{
return F_38 ( V_32 -> V_96 ) ;
}
static void F_84 ( struct V_91 * V_32 ,
struct V_73 * V_74 )
{
V_32 -> V_95 = ( unsigned int ) V_74 ;
}
static struct V_73 * F_85 ( struct V_91 * V_32 )
{
return (struct V_73 * ) V_32 -> V_95 ;
}
static int F_86 ( int V_62 )
{
return ( V_62 + 1 ) & ( V_104 - 1 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_105 = F_86 ( V_2 -> V_105 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_2 -> V_106 = F_86 ( V_2 -> V_106 ) ;
}
static struct V_91 * F_89 ( struct V_1 * V_2 )
{
return & V_2 -> V_65 -> V_32 [ V_2 -> V_105 ] ;
}
static struct V_91 *
F_90 ( struct V_1 * V_2 )
{
return & V_2 -> V_65 -> V_32 [ V_2 -> V_106 ] ;
}
static bool F_91 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_91 * V_32 ;
struct V_73 * V_74 ;
T_1 V_78 ;
if ( V_2 -> V_107 == 0 )
return false ;
V_32 = F_90 ( V_2 ) ;
if ( F_70 ( V_32 ) )
return false ;
V_74 = F_85 ( V_32 ) ;
V_78 = F_83 ( V_32 ) ;
V_11 -> V_66 . V_108 ++ ;
V_11 -> V_66 . V_109 += V_74 -> V_81 ;
F_92 ( V_2 -> V_25 , V_78 , F_93 ( V_74 ) , V_110 ) ;
F_94 ( V_74 ) ;
F_69 ( V_32 ) ;
F_88 ( V_2 ) ;
F_95 ( & V_2 -> V_111 ) ;
V_2 -> V_107 -- ;
F_96 ( & V_2 -> V_111 ) ;
F_97 ( V_11 ) ;
return true ;
}
static void F_98 ( struct V_1 * V_2 )
{
while ( F_91 ( V_2 ) )
;
}
static int F_99 ( struct V_1 * V_2 , struct V_73 * V_74 ,
T_1 V_78 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_91 * V_32 ;
unsigned int V_81 = ( V_74 -> V_81 < V_112 ) ? V_112 : V_74 -> V_81 ;
V_32 = F_89 ( V_2 ) ;
F_87 ( V_2 ) ;
F_84 ( V_32 , V_74 ) ;
F_82 ( V_32 , V_78 ) ;
F_76 ( V_32 , V_81 ) ;
F_74 ( V_32 ) ;
F_75 ( V_32 ) ;
F_78 ( V_32 ) ;
if ( V_74 -> V_76 == V_113 ) {
T_3 V_87 = V_74 -> V_87 ;
if ( V_87 == F_100 ( V_114 ) ) {
T_2 V_115 = F_101 ( V_74 ) -> V_87 ;
F_81 ( V_32 ) ;
if ( V_115 == V_116 )
F_79 ( V_32 ) ;
else if ( V_115 == V_117 )
F_80 ( V_32 ) ;
}
}
F_95 ( & V_2 -> V_111 ) ;
V_2 -> V_107 ++ ;
if ( V_2 -> V_107 == V_104 )
F_102 ( V_11 ) ;
F_71 ( V_32 ) ;
F_96 ( & V_2 -> V_111 ) ;
F_6 ( V_2 ) ;
return V_118 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_39 * V_31 , T_4 V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_60 * V_60 ;
T_1 V_78 ;
V_60 = F_103 ( V_119 ) ;
if ( ! V_60 ) {
if ( F_56 () )
F_10 ( V_11 , L_13 ) ;
return - V_120 ;
}
V_78 = F_104 ( V_2 -> V_25 , V_60 , 0 , V_33 , V_79 ) ;
if ( F_55 ( F_105 ( V_2 -> V_25 , V_78 ) ) ) {
if ( F_56 () )
F_10 ( V_11 , L_14 ) ;
F_106 ( V_60 ) ;
return - V_120 ;
}
F_48 ( V_31 , V_60 ) ;
F_41 ( V_31 , V_78 ) ;
F_31 ( V_31 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_63 ; V_12 ++ ) {
struct V_39 * V_31 = & V_2 -> V_65 -> V_31 [ V_12 ] ;
struct V_60 * V_60 = F_49 ( V_31 ) ;
T_1 V_78 = F_42 ( V_31 ) ;
if ( ! V_60 )
continue;
F_62 ( V_2 -> V_25 , V_78 , V_33 , V_79 ) ;
F_106 ( V_60 ) ;
}
for ( V_12 = 0 ; V_12 < V_104 ; V_12 ++ ) {
struct V_91 * V_32 = & V_2 -> V_65 -> V_32 [ V_12 ] ;
struct V_73 * V_74 = F_85 ( V_32 ) ;
T_1 V_78 = F_83 ( V_32 ) ;
if ( ! V_74 )
continue;
F_92 ( V_2 -> V_25 , V_78 , F_93 ( V_74 ) , V_110 ) ;
F_108 ( V_74 ) ;
}
F_109 ( V_2 -> V_25 , sizeof( struct V_30 ) ,
V_2 -> V_65 , V_2 -> V_29 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_65 = F_111 ( V_2 -> V_25 ,
sizeof( struct V_30 ) ,
& V_2 -> V_29 , V_121 ) ;
if ( ! V_2 -> V_65 )
return - V_120 ;
F_40 ( & V_2 -> V_65 -> V_31 [ V_63 - 1 ] ) ;
for ( V_12 = 0 ; V_12 < V_63 ; V_12 ++ ) {
struct V_39 * V_31 = & V_2 -> V_65 -> V_31 [ V_12 ] ;
if ( F_65 ( V_2 , V_31 , V_121 ) )
goto V_122;
}
F_73 ( & V_2 -> V_65 -> V_32 [ V_104 - 1 ] ) ;
return 0 ;
V_122:
F_107 ( V_2 ) ;
return - V_120 ;
}
static void F_112 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
struct V_123 * V_124 = V_11 -> V_124 ;
int V_125 ;
if ( V_124 -> V_35 == V_2 -> V_126 )
return;
V_2 -> V_126 = V_124 -> V_35 ;
V_125 = F_8 ( V_2 -> V_4 + V_127 ) ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_102 ( V_11 ) ;
F_26 ( V_2 ) ;
F_113 ( V_11 ) ;
F_22 ( V_2 ) ;
F_25 ( V_2 , V_124 -> V_35 ) ;
F_2 ( V_125 , V_2 -> V_4 + V_127 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_123 * V_124 ;
V_124 = F_115 ( V_2 -> V_128 ) ;
if ( ! V_124 ) {
F_57 ( V_11 , L_15 , V_11 -> V_129 ) ;
return - V_130 ;
}
V_124 = F_116 ( V_11 , F_117 ( V_124 ) ,
& F_112 , V_131 ) ;
if ( F_118 ( V_124 ) ) {
F_10 ( V_11 , L_16 , V_11 -> V_129 ) ;
return F_119 ( V_124 ) ;
}
return 0 ;
}
static int F_120 ( struct V_128 * V_132 , int V_133 , int V_134 )
{
struct V_10 * V_11 = V_132 -> V_2 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
unsigned int V_135 ;
int V_12 ;
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
V_135 &= V_137 ;
V_135 |= F_121 ( V_133 ) |
F_122 ( V_134 ) |
V_138 ;
F_2 ( V_135 , V_2 -> V_4 + V_136 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
if ( ( V_135 & V_138 ) == 0 ) {
int V_139 ;
V_139 = F_8 ( V_2 -> V_4 + V_140 ) ;
return F_123 ( V_139 ) ;
}
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_17 ) ;
return - V_16 ;
}
static int F_124 ( struct V_128 * V_132 , int V_133 ,
int V_134 , T_5 V_141 )
{
struct V_10 * V_11 = V_132 -> V_2 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
unsigned int V_135 ;
int V_139 ;
int V_12 ;
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
V_135 &= V_137 ;
V_135 |= F_121 ( V_133 ) |
F_122 ( V_134 ) |
V_142 ;
V_139 = F_125 ( V_141 ) ;
F_2 ( V_139 , V_2 -> V_4 + V_140 ) ;
F_2 ( V_135 , V_2 -> V_4 + V_136 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
if ( ( V_135 & V_142 ) == 0 )
return 0 ;
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_18 ) ;
return - V_16 ;
}
static void F_126 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
F_127 ( V_144 -> V_145 , V_146 , sizeof( V_144 -> V_145 ) ) ;
F_127 ( V_144 -> V_147 , V_148 , sizeof( V_144 -> V_147 ) ) ;
F_127 ( V_144 -> V_149 , F_128 ( & V_11 -> V_25 ) , sizeof( V_144 -> V_149 ) ) ;
}
static T_6 F_129 ( int V_150 , void * V_151 )
{
struct V_10 * V_11 = V_151 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( F_130 ( V_2 -> V_152 || F_131 ( V_11 ) ) ) {
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_132 ( & V_2 -> V_90 ) ;
}
return V_153 ;
}
static int F_133 ( struct V_154 * V_90 , int V_155 )
{
struct V_1 * V_2 = F_134 ( V_90 , struct V_1 , V_90 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_156 ;
bool V_157 = true ;
int V_158 = 0 ;
V_156 = F_8 ( V_2 -> V_4 + V_159 ) ;
F_2 ( V_156 , V_2 -> V_4 + V_159 ) ;
if ( V_156 & ( V_160 | V_161 ) ) {
bool V_162 ;
do {
V_162 = F_60 ( V_2 , & V_158 ) ;
} while ( V_162 && V_158 < V_155 );
if ( V_162 && V_158 == V_155 )
V_157 = false ;
}
if ( V_156 & ( V_163 | V_164 ) ) {
F_98 ( V_2 ) ;
}
if ( V_156 & V_2 -> V_165 & ( V_161 |
V_166 | V_167 |
V_168 ) ) {
if ( F_56 () )
F_57 ( V_11 , L_19 , V_156 ,
V_156 & V_161 ? L_20 : L_21 ,
V_156 & V_166 ? L_22 : L_21 ,
V_156 & V_167 ? L_23 : L_21 ,
V_156 & V_168 ? L_24 : L_21 ) ;
if ( V_156 & V_161 ) {
V_11 -> V_66 . V_169 ++ ;
}
if ( V_156 & V_166 ) {
V_11 -> V_66 . V_170 ++ ;
}
}
if ( V_157 ) {
F_135 ( V_90 ) ;
F_2 ( V_2 -> V_165 ,
V_2 -> V_4 + V_127 ) ;
}
return V_158 ;
}
static int F_136 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
int V_122 ;
V_122 = F_110 ( V_2 ) ;
if ( V_122 ) {
F_10 ( V_11 , L_25 ) ;
goto V_171;
}
V_122 = F_137 ( V_2 -> V_150 , F_129 , 0 , V_11 -> V_129 , V_11 ) ;
if ( V_122 ) {
F_10 ( V_11 , L_26 , V_2 -> V_150 ) ;
goto V_172;
}
V_2 -> V_64 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_107 = 0 ;
V_122 = F_7 ( V_2 ) ;
if ( V_122 )
goto V_173;
F_22 ( V_2 ) ;
F_25 ( V_2 , V_2 -> V_152 ? 100 : 10 ) ;
if ( V_11 -> V_124 )
F_138 ( V_11 -> V_124 ) ;
else if ( V_2 -> V_152 )
F_139 ( V_11 ) ;
F_140 ( & V_2 -> V_90 ) ;
F_113 ( V_11 ) ;
F_2 ( V_2 -> V_165 , V_2 -> V_4 + V_127 ) ;
if ( V_2 -> V_152 ) {
V_122 = F_141 ( V_2 -> V_174 ) ;
if ( V_122 )
goto V_175;
}
V_2 -> V_176 = true ;
return 0 ;
V_175:
F_142 ( & V_2 -> V_90 ) ;
F_102 ( V_11 ) ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
V_173:
F_143 ( V_2 -> V_150 , V_11 ) ;
V_172:
F_107 ( V_2 ) ;
V_171:
return V_122 ;
}
static int F_144 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( ! V_2 -> V_176 )
return 0 ;
V_2 -> V_176 = false ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_102 ( V_11 ) ;
F_142 ( & V_2 -> V_90 ) ;
if ( V_11 -> V_124 )
F_145 ( V_11 -> V_124 ) ;
F_26 ( V_2 ) ;
F_143 ( V_2 -> V_150 , V_11 ) ;
F_107 ( V_2 ) ;
return 0 ;
}
static int F_146 ( struct V_73 * V_74 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
T_1 V_78 ;
if ( F_55 ( V_74 -> V_81 > V_177 ) ) {
if ( F_56 () )
F_59 ( V_11 , L_27 ) ;
V_11 -> V_66 . V_178 ++ ;
F_108 ( V_74 ) ;
return V_118 ;
}
V_78 = F_147 ( V_2 -> V_25 , V_74 -> V_139 , F_93 ( V_74 ) , V_110 ) ;
if ( F_55 ( F_105 ( V_2 -> V_25 , V_78 ) ) ) {
if ( F_56 () )
F_10 ( V_11 , L_28 ) ;
V_11 -> V_66 . V_178 ++ ;
F_108 ( V_74 ) ;
return V_118 ;
}
return F_99 ( V_2 , V_74 , V_78 ) ;
}
static int F_148 ( struct V_10 * V_11 , struct V_179 * V_180 , int V_181 )
{
if ( ! V_11 -> V_124 )
return - V_182 ;
return F_149 ( V_11 -> V_124 , V_180 , V_181 ) ;
}
static int F_150 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
struct V_183 * V_184 = F_151 ( V_2 -> V_25 ) ;
int V_12 , V_122 = 0 ;
V_2 -> V_128 = F_152 () ;
if ( ! V_2 -> V_128 )
return - V_16 ;
V_2 -> V_128 -> V_129 = L_29 ;
snprintf ( V_2 -> V_128 -> V_185 , V_186 , L_30 ,
V_184 -> V_129 , V_184 -> V_185 ) ;
V_2 -> V_128 -> V_2 = V_2 -> V_11 ;
V_2 -> V_128 -> V_187 = F_120 ;
V_2 -> V_128 -> V_188 = F_124 ;
for ( V_12 = 0 ; V_12 < V_189 ; V_12 ++ )
V_2 -> V_128 -> V_150 [ V_12 ] = V_190 ;
V_122 = F_153 ( V_2 -> V_128 ) ;
if ( V_122 ) {
F_154 ( V_2 -> V_25 , L_31 ) ;
goto V_191;
}
V_122 = F_114 ( V_2 ) ;
if ( V_122 ) {
F_154 ( V_2 -> V_25 , L_32 ) ;
goto V_192;
}
return 0 ;
V_192:
F_155 ( V_2 -> V_128 ) ;
V_191:
F_156 ( V_2 -> V_128 ) ;
return V_122 ;
}
static void F_157 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( ! V_11 -> V_124 )
return;
F_158 ( V_11 -> V_124 ) ;
F_155 ( V_2 -> V_128 ) ;
F_156 ( V_2 -> V_128 ) ;
}
static void F_159 ( struct V_193 * V_194 )
{
if ( F_55 ( V_194 -> V_195 != V_196 ) )
return;
F_57 ( V_194 -> V_25 , L_33 ,
V_194 -> V_197 ? L_34 : L_35 ) ;
}
static int F_160 ( struct V_183 * V_184 )
{
struct V_198 * V_199 ;
int V_150 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_122 = 0 ;
if ( ! V_184 )
return - V_130 ;
V_199 = F_161 ( V_184 , V_200 , 0 ) ;
if ( ! V_199 )
return - V_182 ;
V_150 = F_162 ( V_184 , 0 ) ;
if ( V_150 < 0 )
return V_150 ;
V_11 = F_163 ( sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
V_122 = - V_120 ;
goto V_201;
}
F_164 ( V_11 , & V_184 -> V_25 ) ;
V_11 -> V_202 = & V_203 ;
V_11 -> V_204 = & V_205 ;
F_165 ( V_184 , V_11 ) ;
V_2 = F_21 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_25 = & V_184 -> V_25 ;
F_166 ( & V_2 -> V_111 ) ;
F_167 ( V_11 , & V_2 -> V_90 , F_133 , 64 ) ;
V_2 -> V_199 = F_168 ( V_199 -> V_206 , F_169 ( V_199 ) ,
F_128 ( & V_184 -> V_25 ) ) ;
if ( ! V_2 -> V_199 ) {
F_154 ( & V_184 -> V_25 , L_36 ) ;
V_122 = - V_120 ;
goto V_207;
}
V_2 -> V_4 = F_170 ( V_199 -> V_206 , F_169 ( V_199 ) ) ;
if ( ! V_2 -> V_4 ) {
F_154 ( & V_184 -> V_25 , L_37 ) ;
V_122 = - V_16 ;
goto V_208;
}
V_2 -> V_150 = V_150 ;
F_12 ( V_2 ) ;
V_2 -> V_165 = ( V_166 |
V_163 |
V_164 |
V_167 |
V_168 |
V_160 |
V_161 ) ;
if ( V_184 -> V_25 . V_209 &&
F_171 ( V_184 -> V_25 . V_209 , L_38 , NULL ) ) {
if ( ! F_172 ( V_210 ) ) {
F_154 ( & V_184 -> V_25 , L_39 ) ;
goto V_211;
}
F_15 ( & V_184 -> V_25 , L_40 ) ;
V_2 -> V_152 = true ;
V_2 -> V_165 &= ~ V_168 ;
V_2 -> V_174 = F_173 ( V_11 , F_159 ) ;
if ( ! V_2 -> V_174 )
goto V_211;
} else {
V_2 -> V_152 = false ;
V_122 = F_150 ( V_11 ) ;
if ( V_122 )
goto V_212;
}
V_11 -> V_213 = V_214 | V_215 ;
if ( V_2 -> V_152 &&
F_171 ( V_184 -> V_25 . V_209 , L_41 , NULL ) )
V_11 -> V_213 &= ~ V_214 ;
V_122 = F_174 ( V_11 ) ;
if ( V_122 ) {
F_154 ( & V_184 -> V_25 , L_42 ) ;
goto V_216;
}
F_57 ( V_11 , L_43 , V_2 -> V_150 , V_2 -> V_4 ) ;
return 0 ;
V_211:
V_216:
F_157 ( V_11 ) ;
V_212:
F_175 ( V_2 -> V_4 ) ;
V_208:
F_176 ( V_2 -> V_199 ) ;
V_207:
F_177 ( & V_2 -> V_90 ) ;
F_178 ( V_11 ) ;
V_201:
return V_122 ;
}
static int T_7 F_179 ( struct V_183 * V_184 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_180 ( V_184 ) ;
V_2 = F_21 ( V_11 ) ;
F_181 ( V_11 ) ;
F_157 ( V_11 ) ;
F_175 ( V_2 -> V_4 ) ;
F_176 ( V_2 -> V_199 ) ;
F_177 ( & V_2 -> V_90 ) ;
F_178 ( V_11 ) ;
return 0 ;
}
