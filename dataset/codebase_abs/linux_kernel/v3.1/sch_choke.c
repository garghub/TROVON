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
if ( F_18 ( V_31 ) | F_18 ( V_32 ) )
V_26 = 0 ;
V_21 += V_31 -> V_36 * 4 ;
V_22 += V_32 -> V_36 * 4 ;
break;
}
case F_17 ( V_37 ) : {
const struct V_38 * V_31 , * V_32 ;
V_31 = ( const struct V_38 * ) ( V_19 -> V_33 + V_21 ) ;
V_32 = ( const struct V_38 * ) ( V_20 -> V_33 + V_22 ) ;
V_26 = V_31 -> V_39 ;
if ( V_26 != V_32 -> V_39 ||
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
V_24 = ( V_40 T_1 * ) ( V_19 -> V_33 + V_21 ) ;
V_25 = ( V_40 T_1 * ) ( V_20 -> V_33 + V_22 ) ;
return * V_24 == * V_25 ;
}
static inline struct V_41 * V_41 ( const struct V_14 * V_15 )
{
F_21 ( sizeof( V_15 -> V_42 ) <
sizeof( struct V_43 ) + sizeof( struct V_41 ) ) ;
return (struct V_41 * ) V_43 ( V_15 ) -> V_33 ;
}
static inline void F_22 ( struct V_14 * V_15 , T_4 V_44 )
{
V_41 ( V_15 ) -> V_44 = V_44 ;
}
static T_4 F_23 ( const struct V_14 * V_15 )
{
return V_41 ( V_15 ) -> V_44 ;
}
static bool F_24 ( struct V_14 * V_15 ,
struct V_11 * V_12 , int * V_45 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_46 V_47 ;
int V_48 ;
V_48 = F_25 ( V_15 , V_3 -> V_49 , & V_47 ) ;
if ( V_48 >= 0 ) {
#ifdef F_26
switch ( V_48 ) {
case V_50 :
case V_51 :
* V_45 = V_52 | V_53 ;
case V_54 :
return false ;
}
#endif
F_22 ( V_15 , F_27 ( V_47 . V_44 ) ) ;
return true ;
}
return false ;
}
static struct V_14 * F_28 ( const struct V_2 * V_3 ,
unsigned int * V_55 )
{
struct V_14 * V_15 ;
int V_56 = 3 ;
do {
* V_55 = ( V_3 -> V_5 + F_1 ( F_4 ( V_3 ) ) ) & V_3 -> V_6 ;
V_15 = V_3 -> V_10 [ * V_55 ] ;
if ( V_15 )
return V_15 ;
} while ( -- V_56 > 0 );
return V_3 -> V_10 [ * V_55 = V_3 -> V_5 ] ;
}
static bool F_29 ( const struct V_2 * V_3 ,
struct V_14 * V_57 ,
unsigned int * V_55 )
{
struct V_14 * V_58 ;
if ( V_3 -> V_5 == V_3 -> V_4 )
return false ;
V_58 = F_28 ( V_3 , V_55 ) ;
if ( V_3 -> V_49 )
return F_23 ( V_57 ) == F_23 ( V_58 ) ;
return F_14 ( V_58 , V_57 ) ;
}
static int F_30 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_59 * V_60 = & V_3 -> V_61 ;
int V_62 = V_52 | V_63 ;
if ( V_3 -> V_49 ) {
if ( ! F_24 ( V_15 , V_12 , & V_62 ) )
goto V_64;
}
V_60 -> V_65 = F_31 ( V_60 , V_12 -> V_3 . V_18 ) ;
if ( F_32 ( V_60 ) )
F_33 ( V_60 ) ;
if ( V_60 -> V_65 <= V_60 -> V_66 )
V_60 -> V_67 = - 1 ;
else {
unsigned int V_13 ;
if ( F_29 ( V_3 , V_15 , & V_13 ) ) {
V_3 -> V_68 . V_69 ++ ;
F_9 ( V_12 , V_13 ) ;
goto V_70;
}
if ( V_60 -> V_65 > V_60 -> V_71 ) {
V_60 -> V_67 = - 1 ;
V_12 -> V_16 . V_72 ++ ;
if ( F_6 ( V_3 ) || ! F_5 ( V_3 ) ||
! F_34 ( V_15 ) ) {
V_3 -> V_68 . V_73 ++ ;
goto V_70;
}
V_3 -> V_68 . V_74 ++ ;
} else if ( ++ V_60 -> V_67 ) {
if ( F_35 ( V_60 , V_60 -> V_65 ) ) {
V_60 -> V_67 = 0 ;
V_60 -> V_75 = F_36 ( V_60 ) ;
V_12 -> V_16 . V_72 ++ ;
if ( ! F_5 ( V_3 ) || ! F_34 ( V_15 ) ) {
V_3 -> V_68 . V_76 ++ ;
goto V_70;
}
V_3 -> V_68 . V_77 ++ ;
}
} else
V_60 -> V_75 = F_36 ( V_60 ) ;
}
if ( V_12 -> V_3 . V_18 < V_3 -> V_78 ) {
V_3 -> V_10 [ V_3 -> V_4 ] = V_15 ;
V_3 -> V_4 = ( V_3 -> V_4 + 1 ) & V_3 -> V_6 ;
++ V_12 -> V_3 . V_18 ;
V_12 -> V_16 . V_17 += F_11 ( V_15 ) ;
return V_52 ;
}
V_3 -> V_68 . V_79 ++ ;
V_12 -> V_16 . V_80 ++ ;
F_37 ( V_15 ) ;
return V_81 ;
V_70:
F_12 ( V_15 , V_12 ) ;
return V_82 ;
V_64:
if ( V_62 & V_63 )
V_12 -> V_16 . V_80 ++ ;
F_37 ( V_15 ) ;
return V_62 ;
}
static struct V_14 * F_38 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_14 * V_15 ;
if ( V_3 -> V_5 == V_3 -> V_4 ) {
if ( ! F_32 ( & V_3 -> V_61 ) )
F_39 ( & V_3 -> V_61 ) ;
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
unsigned int V_83 ;
V_83 = F_42 ( V_12 ) ;
if ( V_83 > 0 )
V_3 -> V_68 . V_84 ++ ;
else {
if ( ! F_32 ( & V_3 -> V_61 ) )
F_39 ( & V_3 -> V_61 ) ;
}
return V_83 ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_44 ( & V_3 -> V_61 ) ;
}
static void F_45 ( void * V_85 )
{
if ( V_85 ) {
if ( F_46 ( V_85 ) )
F_47 ( V_85 ) ;
else
F_48 ( V_85 ) ;
}
}
static int F_49 ( struct V_11 * V_12 , struct V_86 * V_87 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_86 * V_88 [ V_89 + 1 ] ;
const struct V_90 * V_91 ;
int V_92 ;
struct V_14 * * V_93 = NULL ;
unsigned int V_94 ;
if ( V_87 == NULL )
return - V_95 ;
V_92 = F_50 ( V_88 , V_89 , V_87 , V_96 ) ;
if ( V_92 < 0 )
return V_92 ;
if ( V_88 [ V_97 ] == NULL ||
V_88 [ V_98 ] == NULL )
return - V_95 ;
V_91 = F_51 ( V_88 [ V_97 ] ) ;
if ( V_91 -> V_78 > V_99 )
return - V_95 ;
V_94 = F_52 ( V_91 -> V_78 + 1 ) - 1 ;
if ( V_94 != V_3 -> V_6 ) {
struct V_14 * * V_100 ;
V_100 = F_53 ( V_94 + 1 , sizeof( struct V_14 * ) , V_101 ) ;
if ( ! V_100 )
V_100 = F_54 ( ( V_94 + 1 ) * sizeof( struct V_14 * ) ) ;
if ( ! V_100 )
return - V_102 ;
F_55 ( V_12 ) ;
V_93 = V_3 -> V_10 ;
if ( V_93 ) {
unsigned int V_103 = V_12 -> V_3 . V_18 , V_4 = 0 ;
while ( V_3 -> V_5 != V_3 -> V_4 ) {
struct V_14 * V_15 = V_3 -> V_10 [ V_3 -> V_5 ] ;
V_3 -> V_5 = ( V_3 -> V_5 + 1 ) & V_3 -> V_6 ;
if ( ! V_15 )
continue;
if ( V_4 < V_94 ) {
V_100 [ V_4 ++ ] = V_15 ;
continue;
}
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
-- V_12 -> V_3 . V_18 ;
F_12 ( V_15 , V_12 ) ;
}
F_13 ( V_12 , V_103 - V_12 -> V_3 . V_18 ) ;
V_3 -> V_5 = 0 ;
V_3 -> V_4 = V_4 ;
}
V_3 -> V_6 = V_94 ;
V_3 -> V_10 = V_100 ;
} else
F_55 ( V_12 ) ;
V_3 -> V_7 = V_91 -> V_7 ;
V_3 -> V_78 = V_91 -> V_78 ;
F_56 ( & V_3 -> V_61 , V_91 -> V_66 , V_91 -> V_71 , V_91 -> V_104 ,
V_91 -> V_105 , V_91 -> V_106 ,
F_51 ( V_88 [ V_98 ] ) ) ;
if ( V_3 -> V_5 == V_3 -> V_4 )
F_33 ( & V_3 -> V_61 ) ;
F_57 ( V_12 ) ;
F_45 ( V_93 ) ;
return 0 ;
}
static int F_58 ( struct V_11 * V_12 , struct V_86 * V_87 )
{
return F_49 ( V_12 , V_87 ) ;
}
static int F_59 ( struct V_11 * V_12 , struct V_14 * V_15 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_86 * V_107 = NULL ;
struct V_90 V_87 = {
. V_78 = V_3 -> V_78 ,
. V_7 = V_3 -> V_7 ,
. V_66 = V_3 -> V_61 . V_66 >> V_3 -> V_61 . V_104 ,
. V_71 = V_3 -> V_61 . V_71 >> V_3 -> V_61 . V_104 ,
. V_104 = V_3 -> V_61 . V_104 ,
. V_105 = V_3 -> V_61 . V_105 ,
. V_106 = V_3 -> V_61 . V_106 ,
} ;
V_107 = F_60 ( V_15 , V_108 ) ;
if ( V_107 == NULL )
goto V_109;
F_61 ( V_15 , V_97 , sizeof( V_87 ) , & V_87 ) ;
return F_62 ( V_15 , V_107 ) ;
V_109:
F_63 ( V_15 , V_107 ) ;
return - V_110 ;
}
static int F_64 ( struct V_11 * V_12 , struct V_111 * V_112 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_113 V_114 = {
. V_115 = V_3 -> V_68 . V_76 + V_3 -> V_68 . V_73 ,
. V_116 = V_3 -> V_68 . V_77 + V_3 -> V_68 . V_74 ,
. V_79 = V_3 -> V_68 . V_79 ,
. V_84 = V_3 -> V_68 . V_84 ,
. V_69 = V_3 -> V_68 . V_69 ,
} ;
return F_65 ( V_112 , & V_114 , sizeof( V_114 ) ) ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_67 ( & V_3 -> V_49 ) ;
F_45 ( V_3 -> V_10 ) ;
}
static struct V_11 * F_68 ( struct V_11 * V_12 , unsigned long V_117 )
{
return NULL ;
}
static unsigned long F_69 ( struct V_11 * V_12 , T_1 V_44 )
{
return 0 ;
}
static void F_70 ( struct V_11 * V_3 , unsigned long V_118 )
{
}
static unsigned long F_71 ( struct V_11 * V_12 , unsigned long V_119 ,
T_1 V_44 )
{
return 0 ;
}
static struct V_120 * * F_72 ( struct V_11 * V_12 , unsigned long V_118 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
if ( V_118 )
return NULL ;
return & V_3 -> V_49 ;
}
static int F_73 ( struct V_11 * V_12 , unsigned long V_118 ,
struct V_14 * V_15 , struct V_121 * V_122 )
{
V_122 -> V_123 |= F_27 ( V_118 ) ;
return 0 ;
}
static void F_74 ( struct V_11 * V_12 , struct V_124 * V_117 )
{
if ( ! V_117 -> V_125 ) {
if ( V_117 -> V_126 ( V_12 , 1 , V_117 ) < 0 ) {
V_117 -> V_125 = 1 ;
return;
}
V_117 -> V_127 ++ ;
}
}
static struct V_14 * F_75 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
return ( V_3 -> V_5 != V_3 -> V_4 ) ? V_3 -> V_10 [ V_3 -> V_5 ] : NULL ;
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_128 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_128 ) ;
}
