static T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( F_3 () , V_1 ) ;
}
static unsigned int F_4 ( const struct V_2 * V_3 )
{
return ( V_3 -> V_4 - V_3 -> V_5 ) & V_3 -> V_6 ;
}
static int F_5 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 & V_8 ;
}
static int F_6 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 & V_9 ;
}
static void F_7 ( struct V_2 * V_3 )
{
do {
V_3 -> V_5 = ( V_3 -> V_5 + 1 ) & V_3 -> V_6 ;
if ( V_3 -> V_5 == V_3 -> V_4 )
break;
} while ( V_3 -> V_10 [ V_3 -> V_5 ] == NULL );
}
static void F_8 ( struct V_2 * V_3 )
{
do {
V_3 -> V_4 = ( V_3 -> V_4 - 1 ) & V_3 -> V_6 ;
if ( V_3 -> V_5 == V_3 -> V_4 )
break;
} while ( V_3 -> V_10 [ V_3 -> V_4 ] == NULL );
}
static void F_9 ( struct V_11 * V_12 , unsigned int V_13 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_14 * V_15 = V_3 -> V_10 [ V_13 ] ;
V_3 -> V_10 [ V_13 ] = NULL ;
if ( V_13 == V_3 -> V_5 )
F_7 ( V_3 ) ;
if ( V_13 == V_3 -> V_4 )
F_8 ( V_3 ) ;
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
F_12 ( V_15 , V_12 ) ;
F_13 ( V_12 , 1 ) ;
-- V_12 -> V_3 . V_18 ;
}
static bool F_14 ( struct V_14 * V_19 ,
struct V_14 * V_20 )
{
int V_21 , V_22 , V_23 ;
const T_1 * V_24 , * V_25 ;
T_2 V_26 ;
T_3 V_27 ;
if ( V_19 -> V_28 != V_20 -> V_28 )
return false ;
V_27 = F_15 ( V_19 ) ;
if ( ! V_27 || V_27 != F_15 ( V_20 ) )
return false ;
V_21 = F_16 ( V_19 ) ;
V_22 = F_16 ( V_20 ) ;
switch ( V_19 -> V_28 ) {
case F_17 ( V_29 ) : {
const struct V_30 * V_31 , * V_32 ;
V_31 = ( const struct V_30 * ) ( V_19 -> V_33 + V_21 ) ;
V_32 = ( const struct V_30 * ) ( V_20 -> V_33 + V_22 ) ;
V_26 = V_31 -> V_28 ;
if ( V_26 != V_32 -> V_28 ||
V_31 -> V_34 != V_32 -> V_34 || V_31 -> V_35 != V_32 -> V_35 )
return false ;
if ( ( V_31 -> V_36 | V_32 -> V_36 ) & F_18 ( V_37 | V_38 ) )
V_26 = 0 ;
V_21 += V_31 -> V_39 * 4 ;
V_22 += V_32 -> V_39 * 4 ;
break;
}
case F_17 ( V_40 ) : {
const struct V_41 * V_31 , * V_32 ;
V_31 = ( const struct V_41 * ) ( V_19 -> V_33 + V_21 ) ;
V_32 = ( const struct V_41 * ) ( V_20 -> V_33 + V_22 ) ;
V_26 = V_31 -> V_42 ;
if ( V_26 != V_32 -> V_42 ||
F_19 ( & V_31 -> V_34 , & V_32 -> V_34 ) ||
F_19 ( & V_31 -> V_35 , & V_32 -> V_35 ) )
return false ;
V_21 += 40 ;
V_22 += 40 ;
}
default:
return false ;
}
V_23 = F_20 ( V_26 ) ;
if ( V_23 < 0 )
return true ;
V_21 += V_23 ;
V_22 += V_23 ;
V_24 = ( V_43 T_1 * ) ( V_19 -> V_33 + V_21 ) ;
V_25 = ( V_43 T_1 * ) ( V_20 -> V_33 + V_22 ) ;
return * V_24 == * V_25 ;
}
static inline struct V_44 * V_44 ( const struct V_14 * V_15 )
{
F_21 ( sizeof( V_15 -> V_45 ) <
sizeof( struct V_46 ) + sizeof( struct V_44 ) ) ;
return (struct V_44 * ) V_46 ( V_15 ) -> V_33 ;
}
static inline void F_22 ( struct V_14 * V_15 , T_4 V_47 )
{
V_44 ( V_15 ) -> V_47 = V_47 ;
}
static T_4 F_23 ( const struct V_14 * V_15 )
{
return V_44 ( V_15 ) -> V_47 ;
}
static bool F_24 ( struct V_14 * V_15 ,
struct V_11 * V_12 , int * V_48 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_49 V_50 ;
int V_51 ;
V_51 = F_25 ( V_15 , V_3 -> V_52 , & V_50 ) ;
if ( V_51 >= 0 ) {
#ifdef F_26
switch ( V_51 ) {
case V_53 :
case V_54 :
* V_48 = V_55 | V_56 ;
case V_57 :
return false ;
}
#endif
F_22 ( V_15 , F_27 ( V_50 . V_47 ) ) ;
return true ;
}
return false ;
}
static struct V_14 * F_28 ( const struct V_2 * V_3 ,
unsigned int * V_58 )
{
struct V_14 * V_15 ;
int V_59 = 3 ;
do {
* V_58 = ( V_3 -> V_5 + F_1 ( F_4 ( V_3 ) ) ) & V_3 -> V_6 ;
V_15 = V_3 -> V_10 [ * V_58 ] ;
if ( V_15 )
return V_15 ;
} while ( -- V_59 > 0 );
return V_3 -> V_10 [ * V_58 = V_3 -> V_5 ] ;
}
static bool F_29 ( const struct V_2 * V_3 ,
struct V_14 * V_60 ,
unsigned int * V_58 )
{
struct V_14 * V_61 ;
if ( V_3 -> V_5 == V_3 -> V_4 )
return false ;
V_61 = F_28 ( V_3 , V_58 ) ;
if ( V_3 -> V_52 )
return F_23 ( V_60 ) == F_23 ( V_61 ) ;
return F_14 ( V_61 , V_60 ) ;
}
static int F_30 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_62 * V_63 = & V_3 -> V_64 ;
int V_65 = V_55 | V_66 ;
if ( V_3 -> V_52 ) {
if ( ! F_24 ( V_15 , V_12 , & V_65 ) )
goto V_67;
}
V_63 -> V_68 = F_31 ( V_63 , V_12 -> V_3 . V_18 ) ;
if ( F_32 ( V_63 ) )
F_33 ( V_63 ) ;
if ( V_63 -> V_68 <= V_63 -> V_69 )
V_63 -> V_70 = - 1 ;
else {
unsigned int V_13 ;
if ( F_29 ( V_3 , V_15 , & V_13 ) ) {
V_3 -> V_71 . V_72 ++ ;
F_9 ( V_12 , V_13 ) ;
goto V_73;
}
if ( V_63 -> V_68 > V_63 -> V_74 ) {
V_63 -> V_70 = - 1 ;
V_12 -> V_16 . V_75 ++ ;
if ( F_6 ( V_3 ) || ! F_5 ( V_3 ) ||
! F_34 ( V_15 ) ) {
V_3 -> V_71 . V_76 ++ ;
goto V_73;
}
V_3 -> V_71 . V_77 ++ ;
} else if ( ++ V_63 -> V_70 ) {
if ( F_35 ( V_63 , V_63 -> V_68 ) ) {
V_63 -> V_70 = 0 ;
V_63 -> V_78 = F_36 ( V_63 ) ;
V_12 -> V_16 . V_75 ++ ;
if ( ! F_5 ( V_3 ) || ! F_34 ( V_15 ) ) {
V_3 -> V_71 . V_79 ++ ;
goto V_73;
}
V_3 -> V_71 . V_80 ++ ;
}
} else
V_63 -> V_78 = F_36 ( V_63 ) ;
}
if ( V_12 -> V_3 . V_18 < V_3 -> V_81 ) {
V_3 -> V_10 [ V_3 -> V_4 ] = V_15 ;
V_3 -> V_4 = ( V_3 -> V_4 + 1 ) & V_3 -> V_6 ;
++ V_12 -> V_3 . V_18 ;
V_12 -> V_16 . V_17 += F_11 ( V_15 ) ;
return V_55 ;
}
V_3 -> V_71 . V_82 ++ ;
V_12 -> V_16 . V_83 ++ ;
F_37 ( V_15 ) ;
return V_84 ;
V_73:
F_12 ( V_15 , V_12 ) ;
return V_85 ;
V_67:
if ( V_65 & V_66 )
V_12 -> V_16 . V_83 ++ ;
F_37 ( V_15 ) ;
return V_65 ;
}
static struct V_14 * F_38 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_14 * V_15 ;
if ( V_3 -> V_5 == V_3 -> V_4 ) {
if ( ! F_32 ( & V_3 -> V_64 ) )
F_39 ( & V_3 -> V_64 ) ;
return NULL ;
}
V_15 = V_3 -> V_10 [ V_3 -> V_5 ] ;
V_3 -> V_10 [ V_3 -> V_5 ] = NULL ;
F_7 ( V_3 ) ;
-- V_12 -> V_3 . V_18 ;
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
F_40 ( V_12 , V_15 ) ;
return V_15 ;
}
static unsigned int F_41 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
unsigned int V_86 ;
V_86 = F_42 ( V_12 ) ;
if ( V_86 > 0 )
V_3 -> V_71 . V_87 ++ ;
else {
if ( ! F_32 ( & V_3 -> V_64 ) )
F_39 ( & V_3 -> V_64 ) ;
}
return V_86 ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_44 ( & V_3 -> V_64 ) ;
}
static void F_45 ( void * V_88 )
{
if ( V_88 ) {
if ( F_46 ( V_88 ) )
F_47 ( V_88 ) ;
else
F_48 ( V_88 ) ;
}
}
static int F_49 ( struct V_11 * V_12 , struct V_89 * V_90 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_89 * V_91 [ V_92 + 1 ] ;
const struct V_93 * V_94 ;
int V_95 ;
struct V_14 * * V_96 = NULL ;
unsigned int V_97 ;
if ( V_90 == NULL )
return - V_98 ;
V_95 = F_50 ( V_91 , V_92 , V_90 , V_99 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_91 [ V_100 ] == NULL ||
V_91 [ V_101 ] == NULL )
return - V_98 ;
V_94 = F_51 ( V_91 [ V_100 ] ) ;
if ( V_94 -> V_81 > V_102 )
return - V_98 ;
V_97 = F_52 ( V_94 -> V_81 + 1 ) - 1 ;
if ( V_97 != V_3 -> V_6 ) {
struct V_14 * * V_103 ;
V_103 = F_53 ( V_97 + 1 , sizeof( struct V_14 * ) , V_104 ) ;
if ( ! V_103 )
V_103 = F_54 ( ( V_97 + 1 ) * sizeof( struct V_14 * ) ) ;
if ( ! V_103 )
return - V_105 ;
F_55 ( V_12 ) ;
V_96 = V_3 -> V_10 ;
if ( V_96 ) {
unsigned int V_106 = V_12 -> V_3 . V_18 , V_4 = 0 ;
while ( V_3 -> V_5 != V_3 -> V_4 ) {
struct V_14 * V_15 = V_3 -> V_10 [ V_3 -> V_5 ] ;
V_3 -> V_5 = ( V_3 -> V_5 + 1 ) & V_3 -> V_6 ;
if ( ! V_15 )
continue;
if ( V_4 < V_97 ) {
V_103 [ V_4 ++ ] = V_15 ;
continue;
}
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
-- V_12 -> V_3 . V_18 ;
F_12 ( V_15 , V_12 ) ;
}
F_13 ( V_12 , V_106 - V_12 -> V_3 . V_18 ) ;
V_3 -> V_5 = 0 ;
V_3 -> V_4 = V_4 ;
}
V_3 -> V_6 = V_97 ;
V_3 -> V_10 = V_103 ;
} else
F_55 ( V_12 ) ;
V_3 -> V_7 = V_94 -> V_7 ;
V_3 -> V_81 = V_94 -> V_81 ;
F_56 ( & V_3 -> V_64 , V_94 -> V_69 , V_94 -> V_74 , V_94 -> V_107 ,
V_94 -> V_108 , V_94 -> V_109 ,
F_51 ( V_91 [ V_101 ] ) ) ;
if ( V_3 -> V_5 == V_3 -> V_4 )
F_33 ( & V_3 -> V_64 ) ;
F_57 ( V_12 ) ;
F_45 ( V_96 ) ;
return 0 ;
}
static int F_58 ( struct V_11 * V_12 , struct V_89 * V_90 )
{
return F_49 ( V_12 , V_90 ) ;
}
static int F_59 ( struct V_11 * V_12 , struct V_14 * V_15 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_89 * V_110 = NULL ;
struct V_93 V_90 = {
. V_81 = V_3 -> V_81 ,
. V_7 = V_3 -> V_7 ,
. V_69 = V_3 -> V_64 . V_69 >> V_3 -> V_64 . V_107 ,
. V_74 = V_3 -> V_64 . V_74 >> V_3 -> V_64 . V_107 ,
. V_107 = V_3 -> V_64 . V_107 ,
. V_108 = V_3 -> V_64 . V_108 ,
. V_109 = V_3 -> V_64 . V_109 ,
} ;
V_110 = F_60 ( V_15 , V_111 ) ;
if ( V_110 == NULL )
goto V_112;
F_61 ( V_15 , V_100 , sizeof( V_90 ) , & V_90 ) ;
return F_62 ( V_15 , V_110 ) ;
V_112:
F_63 ( V_15 , V_110 ) ;
return - V_113 ;
}
static int F_64 ( struct V_11 * V_12 , struct V_114 * V_115 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_116 V_117 = {
. V_118 = V_3 -> V_71 . V_79 + V_3 -> V_71 . V_76 ,
. V_119 = V_3 -> V_71 . V_80 + V_3 -> V_71 . V_77 ,
. V_82 = V_3 -> V_71 . V_82 ,
. V_87 = V_3 -> V_71 . V_87 ,
. V_72 = V_3 -> V_71 . V_72 ,
} ;
return F_65 ( V_115 , & V_117 , sizeof( V_117 ) ) ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_67 ( & V_3 -> V_52 ) ;
F_45 ( V_3 -> V_10 ) ;
}
static struct V_11 * F_68 ( struct V_11 * V_12 , unsigned long V_120 )
{
return NULL ;
}
static unsigned long F_69 ( struct V_11 * V_12 , T_1 V_47 )
{
return 0 ;
}
static void F_70 ( struct V_11 * V_3 , unsigned long V_121 )
{
}
static unsigned long F_71 ( struct V_11 * V_12 , unsigned long V_122 ,
T_1 V_47 )
{
return 0 ;
}
static struct V_123 * * F_72 ( struct V_11 * V_12 , unsigned long V_121 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
if ( V_121 )
return NULL ;
return & V_3 -> V_52 ;
}
static int F_73 ( struct V_11 * V_12 , unsigned long V_121 ,
struct V_14 * V_15 , struct V_124 * V_125 )
{
V_125 -> V_126 |= F_27 ( V_121 ) ;
return 0 ;
}
static void F_74 ( struct V_11 * V_12 , struct V_127 * V_120 )
{
if ( ! V_120 -> V_128 ) {
if ( V_120 -> V_129 ( V_12 , 1 , V_120 ) < 0 ) {
V_120 -> V_128 = 1 ;
return;
}
V_120 -> V_130 ++ ;
}
}
static struct V_14 * F_75 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
return ( V_3 -> V_5 != V_3 -> V_4 ) ? V_3 -> V_10 [ V_3 -> V_5 ] : NULL ;
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_131 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_131 ) ;
}
