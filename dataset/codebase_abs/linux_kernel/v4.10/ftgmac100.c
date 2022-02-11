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
static void F_31 ( const struct V_1 * V_2 ,
struct V_39 * V_31 )
{
V_31 -> V_40 &= F_28 ( V_2 -> V_44 ) ;
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
static void F_40 ( const struct V_1 * V_2 ,
struct V_39 * V_31 )
{
V_31 -> V_40 |= F_28 ( V_2 -> V_44 ) ;
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
static inline struct V_60 * * F_48 ( struct V_1 * V_2 ,
struct V_39 * V_31 )
{
return & V_2 -> V_61 [ V_31 - V_2 -> V_62 -> V_31 ] ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_39 * V_31 ,
struct V_60 * V_60 )
{
* F_48 ( V_2 , V_31 ) = V_60 ;
}
static struct V_60 * F_50 ( struct V_1 * V_2 ,
struct V_39 * V_31 )
{
return * F_48 ( V_2 , V_31 ) ;
}
static int F_51 ( int V_63 )
{
return ( V_63 + 1 ) & ( V_64 - 1 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_65 = F_51 ( V_2 -> V_65 ) ;
}
static struct V_39 * F_53 ( struct V_1 * V_2 )
{
return & V_2 -> V_62 -> V_31 [ V_2 -> V_65 ] ;
}
static struct V_39 *
F_54 ( struct V_1 * V_2 )
{
struct V_39 * V_31 = F_53 ( V_2 ) ;
while ( F_30 ( V_31 ) ) {
if ( F_27 ( V_31 ) )
return V_31 ;
F_31 ( V_2 , V_31 ) ;
F_52 ( V_2 ) ;
V_31 = F_53 ( V_2 ) ;
}
return NULL ;
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_39 * V_31 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
bool error = false ;
if ( F_56 ( F_32 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_5 ) ;
V_11 -> V_66 . V_67 ++ ;
error = true ;
}
if ( F_56 ( F_33 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_6 ) ;
V_11 -> V_66 . V_68 ++ ;
error = true ;
} else if ( F_56 ( F_47 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_7 ) ;
error = true ;
}
if ( F_56 ( F_34 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_8 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
} else if ( F_56 ( F_35 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_9 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
} else if ( F_56 ( F_36 ( V_31 ) ) ) {
if ( F_57 () )
F_58 ( V_11 , L_10 ) ;
V_11 -> V_66 . V_69 ++ ;
error = true ;
}
return error ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_39 * V_31 = F_53 ( V_2 ) ;
bool V_70 = false ;
if ( F_57 () )
F_60 ( V_11 , L_11 , V_31 ) ;
do {
if ( F_29 ( V_31 ) )
V_70 = true ;
F_31 ( V_2 , V_31 ) ;
F_52 ( V_2 ) ;
V_31 = F_53 ( V_2 ) ;
} while ( ! V_70 && F_30 ( V_31 ) );
V_11 -> V_66 . V_71 ++ ;
}
static bool F_61 ( struct V_1 * V_2 , int * V_72 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_39 * V_31 ;
struct V_73 * V_74 ;
bool V_70 = false ;
V_31 = F_54 ( V_2 ) ;
if ( ! V_31 )
return false ;
if ( F_56 ( F_55 ( V_2 , V_31 ) ) ) {
F_59 ( V_2 ) ;
return true ;
}
V_74 = F_62 ( V_11 , 128 ) ;
if ( F_56 ( ! V_74 ) ) {
if ( F_57 () )
F_10 ( V_11 , L_12 ) ;
F_59 ( V_2 ) ;
return true ;
}
if ( F_56 ( F_39 ( V_31 ) ) )
V_11 -> V_66 . V_75 ++ ;
if ( ( F_43 ( V_31 ) && ! F_45 ( V_31 ) ) ||
( F_44 ( V_31 ) && ! F_46 ( V_31 ) ) )
V_74 -> V_76 = V_77 ;
do {
T_1 V_78 = F_42 ( V_31 ) ;
struct V_60 * V_60 = F_50 ( V_2 , V_31 ) ;
unsigned int V_6 ;
F_63 ( V_2 -> V_25 , V_78 , V_33 , V_79 ) ;
V_6 = F_37 ( V_31 ) ;
F_64 ( V_74 , F_65 ( V_74 ) -> V_80 , V_60 , 0 , V_6 ) ;
V_74 -> V_81 += V_6 ;
V_74 -> V_82 += V_6 ;
V_74 -> V_83 += V_84 ;
if ( F_29 ( V_31 ) )
V_70 = true ;
F_66 ( V_2 , V_31 , V_85 ) ;
F_52 ( V_2 ) ;
V_31 = F_53 ( V_2 ) ;
} while ( ! V_70 );
if ( V_74 -> V_81 <= 128 ) {
V_74 -> V_83 -= V_84 ;
F_67 ( V_74 , V_74 -> V_81 ) ;
} else {
F_67 ( V_74 , V_86 ) ;
}
V_74 -> V_87 = F_68 ( V_74 , V_11 ) ;
V_11 -> V_66 . V_88 ++ ;
V_11 -> V_66 . V_89 += V_74 -> V_81 ;
F_69 ( & V_2 -> V_90 , V_74 ) ;
( * V_72 ) ++ ;
return true ;
}
static void F_70 ( const struct V_1 * V_2 ,
struct V_91 * V_32 )
{
V_32 -> V_92 &= F_28 ( V_2 -> V_93 ) ;
V_32 -> V_94 = 0 ;
V_32 -> V_95 = 0 ;
V_32 -> V_96 = 0 ;
}
static bool F_71 ( struct V_91 * V_32 )
{
return V_32 -> V_92 & F_28 ( V_97 ) ;
}
static void F_72 ( struct V_91 * V_32 )
{
F_73 () ;
V_32 -> V_92 |= F_28 ( V_97 ) ;
}
static void F_74 ( const struct V_1 * V_2 ,
struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_2 -> V_93 ) ;
}
static void F_75 ( struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_98 ) ;
}
static void F_76 ( struct V_91 * V_32 )
{
V_32 -> V_92 |= F_28 ( V_99 ) ;
}
static void F_77 ( struct V_91 * V_32 ,
unsigned int V_81 )
{
V_32 -> V_92 |= F_28 ( F_78 ( V_81 ) ) ;
}
static void F_79 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_100 ) ;
}
static void F_80 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_101 ) ;
}
static void F_81 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_102 ) ;
}
static void F_82 ( struct V_91 * V_32 )
{
V_32 -> V_94 |= F_28 ( V_103 ) ;
}
static void F_83 ( struct V_91 * V_32 ,
T_1 V_3 )
{
V_32 -> V_96 = F_28 ( V_3 ) ;
}
static T_1 F_84 ( struct V_91 * V_32 )
{
return F_38 ( V_32 -> V_96 ) ;
}
static void F_85 ( struct V_91 * V_32 ,
struct V_73 * V_74 )
{
V_32 -> V_95 = ( unsigned int ) V_74 ;
}
static struct V_73 * F_86 ( struct V_91 * V_32 )
{
return (struct V_73 * ) V_32 -> V_95 ;
}
static int F_87 ( int V_63 )
{
return ( V_63 + 1 ) & ( V_104 - 1 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_2 -> V_105 = F_87 ( V_2 -> V_105 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
V_2 -> V_106 = F_87 ( V_2 -> V_106 ) ;
}
static struct V_91 * F_90 ( struct V_1 * V_2 )
{
return & V_2 -> V_62 -> V_32 [ V_2 -> V_105 ] ;
}
static struct V_91 *
F_91 ( struct V_1 * V_2 )
{
return & V_2 -> V_62 -> V_32 [ V_2 -> V_106 ] ;
}
static bool F_92 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_91 * V_32 ;
struct V_73 * V_74 ;
T_1 V_78 ;
if ( V_2 -> V_107 == 0 )
return false ;
V_32 = F_91 ( V_2 ) ;
if ( F_71 ( V_32 ) )
return false ;
V_74 = F_86 ( V_32 ) ;
V_78 = F_84 ( V_32 ) ;
V_11 -> V_66 . V_108 ++ ;
V_11 -> V_66 . V_109 += V_74 -> V_81 ;
F_93 ( V_2 -> V_25 , V_78 , F_94 ( V_74 ) , V_110 ) ;
F_95 ( V_74 ) ;
F_70 ( V_2 , V_32 ) ;
F_89 ( V_2 ) ;
F_96 ( & V_2 -> V_111 ) ;
V_2 -> V_107 -- ;
F_97 ( & V_2 -> V_111 ) ;
F_98 ( V_11 ) ;
return true ;
}
static void F_99 ( struct V_1 * V_2 )
{
while ( F_92 ( V_2 ) )
;
}
static int F_100 ( struct V_1 * V_2 , struct V_73 * V_74 ,
T_1 V_78 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_91 * V_32 ;
unsigned int V_81 = ( V_74 -> V_81 < V_112 ) ? V_112 : V_74 -> V_81 ;
V_32 = F_90 ( V_2 ) ;
F_88 ( V_2 ) ;
F_85 ( V_32 , V_74 ) ;
F_83 ( V_32 , V_78 ) ;
F_77 ( V_32 , V_81 ) ;
F_75 ( V_32 ) ;
F_76 ( V_32 ) ;
F_79 ( V_32 ) ;
if ( V_74 -> V_76 == V_113 ) {
T_3 V_87 = V_74 -> V_87 ;
if ( V_87 == F_101 ( V_114 ) ) {
T_2 V_115 = F_102 ( V_74 ) -> V_87 ;
F_82 ( V_32 ) ;
if ( V_115 == V_116 )
F_80 ( V_32 ) ;
else if ( V_115 == V_117 )
F_81 ( V_32 ) ;
}
}
F_96 ( & V_2 -> V_111 ) ;
V_2 -> V_107 ++ ;
if ( V_2 -> V_107 == V_104 )
F_103 ( V_11 ) ;
F_72 ( V_32 ) ;
F_97 ( & V_2 -> V_111 ) ;
F_6 ( V_2 ) ;
return V_118 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_39 * V_31 , T_4 V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_60 * V_60 ;
T_1 V_78 ;
V_60 = F_104 ( V_119 ) ;
if ( ! V_60 ) {
if ( F_57 () )
F_10 ( V_11 , L_13 ) ;
return - V_120 ;
}
V_78 = F_105 ( V_2 -> V_25 , V_60 , 0 , V_33 , V_79 ) ;
if ( F_56 ( F_106 ( V_2 -> V_25 , V_78 ) ) ) {
if ( F_57 () )
F_10 ( V_11 , L_14 ) ;
F_107 ( V_60 ) ;
return - V_120 ;
}
F_49 ( V_2 , V_31 , V_60 ) ;
F_41 ( V_31 , V_78 ) ;
F_31 ( V_2 , V_31 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ ) {
struct V_39 * V_31 = & V_2 -> V_62 -> V_31 [ V_12 ] ;
struct V_60 * V_60 = F_50 ( V_2 , V_31 ) ;
T_1 V_78 = F_42 ( V_31 ) ;
if ( ! V_60 )
continue;
F_63 ( V_2 -> V_25 , V_78 , V_33 , V_79 ) ;
F_107 ( V_60 ) ;
}
for ( V_12 = 0 ; V_12 < V_104 ; V_12 ++ ) {
struct V_91 * V_32 = & V_2 -> V_62 -> V_32 [ V_12 ] ;
struct V_73 * V_74 = F_86 ( V_32 ) ;
T_1 V_78 = F_84 ( V_32 ) ;
if ( ! V_74 )
continue;
F_93 ( V_2 -> V_25 , V_78 , F_94 ( V_74 ) , V_110 ) ;
F_109 ( V_74 ) ;
}
F_110 ( V_2 -> V_25 , sizeof( struct V_30 ) ,
V_2 -> V_62 , V_2 -> V_29 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_62 = F_112 ( V_2 -> V_25 ,
sizeof( struct V_30 ) ,
& V_2 -> V_29 , V_121 ) ;
if ( ! V_2 -> V_62 )
return - V_120 ;
F_40 ( V_2 ,
& V_2 -> V_62 -> V_31 [ V_64 - 1 ] ) ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ ) {
struct V_39 * V_31 = & V_2 -> V_62 -> V_31 [ V_12 ] ;
if ( F_66 ( V_2 , V_31 , V_121 ) )
goto V_122;
}
F_74 ( V_2 ,
& V_2 -> V_62 -> V_32 [ V_104 - 1 ] ) ;
return 0 ;
V_122:
F_108 ( V_2 ) ;
return - V_120 ;
}
static void F_113 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
struct V_123 * V_124 = V_11 -> V_124 ;
int V_125 ;
if ( V_124 -> V_35 == V_2 -> V_126 )
return;
V_2 -> V_126 = V_124 -> V_35 ;
V_125 = F_8 ( V_2 -> V_4 + V_127 ) ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_103 ( V_11 ) ;
F_26 ( V_2 ) ;
F_114 ( V_11 ) ;
F_22 ( V_2 ) ;
F_25 ( V_2 , V_124 -> V_35 ) ;
F_2 ( V_125 , V_2 -> V_4 + V_127 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_123 * V_124 ;
V_124 = F_116 ( V_2 -> V_128 ) ;
if ( ! V_124 ) {
F_58 ( V_11 , L_15 , V_11 -> V_129 ) ;
return - V_130 ;
}
V_124 = F_117 ( V_11 , F_118 ( V_124 ) ,
& F_113 , V_131 ) ;
if ( F_119 ( V_124 ) ) {
F_10 ( V_11 , L_16 , V_11 -> V_129 ) ;
return F_120 ( V_124 ) ;
}
return 0 ;
}
static int F_121 ( struct V_128 * V_132 , int V_133 , int V_134 )
{
struct V_10 * V_11 = V_132 -> V_2 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
unsigned int V_135 ;
int V_12 ;
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
V_135 &= V_137 ;
V_135 |= F_122 ( V_133 ) |
F_123 ( V_134 ) |
V_138 ;
F_2 ( V_135 , V_2 -> V_4 + V_136 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
if ( ( V_135 & V_138 ) == 0 ) {
int V_139 ;
V_139 = F_8 ( V_2 -> V_4 + V_140 ) ;
return F_124 ( V_139 ) ;
}
F_9 ( 100 ) ;
}
F_10 ( V_11 , L_17 ) ;
return - V_16 ;
}
static int F_125 ( struct V_128 * V_132 , int V_133 ,
int V_134 , T_5 V_141 )
{
struct V_10 * V_11 = V_132 -> V_2 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
unsigned int V_135 ;
int V_139 ;
int V_12 ;
V_135 = F_8 ( V_2 -> V_4 + V_136 ) ;
V_135 &= V_137 ;
V_135 |= F_122 ( V_133 ) |
F_123 ( V_134 ) |
V_142 ;
V_139 = F_126 ( V_141 ) ;
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
static void F_127 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
F_128 ( V_144 -> V_145 , V_146 , sizeof( V_144 -> V_145 ) ) ;
F_128 ( V_144 -> V_147 , V_148 , sizeof( V_144 -> V_147 ) ) ;
F_128 ( V_144 -> V_149 , F_129 ( & V_11 -> V_25 ) , sizeof( V_144 -> V_149 ) ) ;
}
static T_6 F_130 ( int V_150 , void * V_151 )
{
struct V_10 * V_11 = V_151 ;
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( F_131 ( V_2 -> V_152 || F_132 ( V_11 ) ) ) {
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_133 ( & V_2 -> V_90 ) ;
}
return V_153 ;
}
static int F_134 ( struct V_154 * V_90 , int V_155 )
{
struct V_1 * V_2 = F_135 ( V_90 , struct V_1 , V_90 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_156 ;
bool V_157 = true ;
int V_158 = 0 ;
V_156 = F_8 ( V_2 -> V_4 + V_159 ) ;
F_2 ( V_156 , V_2 -> V_4 + V_159 ) ;
if ( V_156 & ( V_160 | V_161 ) ) {
bool V_162 ;
do {
V_162 = F_61 ( V_2 , & V_158 ) ;
} while ( V_162 && V_158 < V_155 );
if ( V_162 && V_158 == V_155 )
V_157 = false ;
}
if ( V_156 & ( V_163 | V_164 ) ) {
F_99 ( V_2 ) ;
}
if ( V_156 & V_2 -> V_165 & ( V_161 |
V_166 | V_167 ) ) {
if ( F_57 () )
F_58 ( V_11 , L_19 , V_156 ,
V_156 & V_161 ? L_20 : L_21 ,
V_156 & V_166 ? L_22 : L_21 ,
V_156 & V_167 ? L_23 : L_21 ) ;
if ( V_156 & V_161 ) {
V_11 -> V_66 . V_168 ++ ;
}
if ( V_156 & V_166 ) {
V_11 -> V_66 . V_169 ++ ;
}
}
if ( V_157 ) {
F_136 ( V_90 ) ;
F_2 ( V_2 -> V_165 ,
V_2 -> V_4 + V_127 ) ;
}
return V_158 ;
}
static int F_137 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
unsigned int V_156 ;
int V_122 ;
V_122 = F_111 ( V_2 ) ;
if ( V_122 ) {
F_10 ( V_11 , L_24 ) ;
goto V_170;
}
V_122 = F_138 ( V_2 -> V_150 , F_130 , 0 , V_11 -> V_129 , V_11 ) ;
if ( V_122 ) {
F_10 ( V_11 , L_25 , V_2 -> V_150 ) ;
goto V_171;
}
V_2 -> V_65 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_107 = 0 ;
V_122 = F_7 ( V_2 ) ;
if ( V_122 )
goto V_172;
F_22 ( V_2 ) ;
F_25 ( V_2 , V_2 -> V_152 ? 100 : 10 ) ;
V_156 = F_8 ( V_2 -> V_4 + V_159 ) ;
F_2 ( V_156 , V_2 -> V_4 + V_159 ) ;
if ( V_11 -> V_124 )
F_139 ( V_11 -> V_124 ) ;
else if ( V_2 -> V_152 )
F_140 ( V_11 ) ;
F_141 ( & V_2 -> V_90 ) ;
F_114 ( V_11 ) ;
F_2 ( V_2 -> V_165 , V_2 -> V_4 + V_127 ) ;
if ( V_2 -> V_152 ) {
V_122 = F_142 ( V_2 -> V_173 ) ;
if ( V_122 )
goto V_174;
}
V_2 -> V_175 = true ;
return 0 ;
V_174:
F_143 ( & V_2 -> V_90 ) ;
F_103 ( V_11 ) ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
V_172:
F_144 ( V_2 -> V_150 , V_11 ) ;
V_171:
F_108 ( V_2 ) ;
V_170:
return V_122 ;
}
static int F_145 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( ! V_2 -> V_175 )
return 0 ;
V_2 -> V_175 = false ;
F_2 ( 0 , V_2 -> V_4 + V_127 ) ;
F_103 ( V_11 ) ;
F_143 ( & V_2 -> V_90 ) ;
if ( V_11 -> V_124 )
F_146 ( V_11 -> V_124 ) ;
else if ( V_2 -> V_152 )
F_147 ( V_2 -> V_173 ) ;
F_26 ( V_2 ) ;
F_144 ( V_2 -> V_150 , V_11 ) ;
F_108 ( V_2 ) ;
return 0 ;
}
static int F_148 ( struct V_73 * V_74 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
T_1 V_78 ;
if ( F_56 ( V_74 -> V_81 > V_176 ) ) {
if ( F_57 () )
F_60 ( V_11 , L_26 ) ;
V_11 -> V_66 . V_177 ++ ;
F_109 ( V_74 ) ;
return V_118 ;
}
V_78 = F_149 ( V_2 -> V_25 , V_74 -> V_139 , F_94 ( V_74 ) , V_110 ) ;
if ( F_56 ( F_106 ( V_2 -> V_25 , V_78 ) ) ) {
if ( F_57 () )
F_10 ( V_11 , L_27 ) ;
V_11 -> V_66 . V_177 ++ ;
F_109 ( V_74 ) ;
return V_118 ;
}
return F_100 ( V_2 , V_74 , V_78 ) ;
}
static int F_150 ( struct V_10 * V_11 , struct V_178 * V_179 , int V_180 )
{
if ( ! V_11 -> V_124 )
return - V_181 ;
return F_151 ( V_11 -> V_124 , V_179 , V_180 ) ;
}
static int F_152 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
struct V_182 * V_183 = F_153 ( V_2 -> V_25 ) ;
int V_12 , V_122 = 0 ;
T_7 V_184 ;
V_2 -> V_128 = F_154 () ;
if ( ! V_2 -> V_128 )
return - V_16 ;
if ( F_155 ( L_28 ) ||
F_155 ( L_29 ) ) {
V_184 = F_8 ( V_2 -> V_4 + V_185 ) ;
V_184 &= ~ V_186 ;
F_2 ( V_184 , V_2 -> V_4 + V_185 ) ;
} ;
V_2 -> V_128 -> V_129 = L_30 ;
snprintf ( V_2 -> V_128 -> V_187 , V_188 , L_31 ,
V_183 -> V_129 , V_183 -> V_187 ) ;
V_2 -> V_128 -> V_2 = V_2 -> V_11 ;
V_2 -> V_128 -> V_189 = F_121 ;
V_2 -> V_128 -> V_190 = F_125 ;
for ( V_12 = 0 ; V_12 < V_191 ; V_12 ++ )
V_2 -> V_128 -> V_150 [ V_12 ] = V_192 ;
V_122 = F_156 ( V_2 -> V_128 ) ;
if ( V_122 ) {
F_157 ( V_2 -> V_25 , L_32 ) ;
goto V_193;
}
V_122 = F_115 ( V_2 ) ;
if ( V_122 ) {
F_157 ( V_2 -> V_25 , L_33 ) ;
goto V_194;
}
return 0 ;
V_194:
F_158 ( V_2 -> V_128 ) ;
V_193:
F_159 ( V_2 -> V_128 ) ;
return V_122 ;
}
static void F_160 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
if ( ! V_11 -> V_124 )
return;
F_161 ( V_11 -> V_124 ) ;
F_158 ( V_2 -> V_128 ) ;
F_159 ( V_2 -> V_128 ) ;
}
static void F_162 ( struct V_195 * V_196 )
{
if ( F_56 ( V_196 -> V_197 != V_198 ) )
return;
F_58 ( V_196 -> V_25 , L_34 ,
V_196 -> V_199 ? L_35 : L_36 ) ;
}
static int F_163 ( struct V_182 * V_183 )
{
struct V_200 * V_201 ;
int V_150 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_122 = 0 ;
if ( ! V_183 )
return - V_130 ;
V_201 = F_164 ( V_183 , V_202 , 0 ) ;
if ( ! V_201 )
return - V_181 ;
V_150 = F_165 ( V_183 , 0 ) ;
if ( V_150 < 0 )
return V_150 ;
V_11 = F_166 ( sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
V_122 = - V_120 ;
goto V_203;
}
F_167 ( V_11 , & V_183 -> V_25 ) ;
V_11 -> V_204 = & V_205 ;
V_11 -> V_206 = & V_207 ;
F_168 ( V_183 , V_11 ) ;
V_2 = F_21 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_25 = & V_183 -> V_25 ;
F_169 ( & V_2 -> V_111 ) ;
F_170 ( V_11 , & V_2 -> V_90 , F_134 , 64 ) ;
V_2 -> V_201 = F_171 ( V_201 -> V_208 , F_172 ( V_201 ) ,
F_129 ( & V_183 -> V_25 ) ) ;
if ( ! V_2 -> V_201 ) {
F_157 ( & V_183 -> V_25 , L_37 ) ;
V_122 = - V_120 ;
goto V_209;
}
V_2 -> V_4 = F_173 ( V_201 -> V_208 , F_172 ( V_201 ) ) ;
if ( ! V_2 -> V_4 ) {
F_157 ( & V_183 -> V_25 , L_38 ) ;
V_122 = - V_16 ;
goto V_210;
}
V_2 -> V_150 = V_150 ;
F_12 ( V_2 ) ;
V_2 -> V_165 = ( V_166 |
V_163 |
V_164 |
V_167 |
V_160 |
V_161 ) ;
if ( F_155 ( L_28 ) ||
F_155 ( L_29 ) ) {
V_2 -> V_44 = F_174 ( 30 ) ;
V_2 -> V_93 = F_174 ( 30 ) ;
} else {
V_2 -> V_44 = F_174 ( 15 ) ;
V_2 -> V_93 = F_174 ( 15 ) ;
}
if ( V_183 -> V_25 . V_211 &&
F_175 ( V_183 -> V_25 . V_211 , L_39 , NULL ) ) {
if ( ! F_176 ( V_212 ) ) {
F_157 ( & V_183 -> V_25 , L_40 ) ;
goto V_213;
}
F_15 ( & V_183 -> V_25 , L_41 ) ;
V_2 -> V_152 = true ;
V_2 -> V_173 = F_177 ( V_11 , F_162 ) ;
if ( ! V_2 -> V_173 )
goto V_213;
} else {
V_2 -> V_152 = false ;
V_122 = F_152 ( V_11 ) ;
if ( V_122 )
goto V_214;
}
V_11 -> V_215 = V_216 | V_217 ;
if ( V_2 -> V_152 &&
F_175 ( V_183 -> V_25 . V_211 , L_42 , NULL ) )
V_11 -> V_215 &= ~ V_216 ;
V_122 = F_178 ( V_11 ) ;
if ( V_122 ) {
F_157 ( & V_183 -> V_25 , L_43 ) ;
goto V_218;
}
F_58 ( V_11 , L_44 , V_2 -> V_150 , V_2 -> V_4 ) ;
return 0 ;
V_213:
V_218:
F_160 ( V_11 ) ;
V_214:
F_179 ( V_2 -> V_4 ) ;
V_210:
F_180 ( V_2 -> V_201 ) ;
V_209:
F_181 ( & V_2 -> V_90 ) ;
F_182 ( V_11 ) ;
V_203:
return V_122 ;
}
static int T_8 F_183 ( struct V_182 * V_183 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_184 ( V_183 ) ;
V_2 = F_21 ( V_11 ) ;
F_185 ( V_11 ) ;
F_160 ( V_11 ) ;
F_179 ( V_2 -> V_4 ) ;
F_180 ( V_2 -> V_201 ) ;
F_181 ( & V_2 -> V_90 ) ;
F_182 ( V_11 ) ;
return 0 ;
}
