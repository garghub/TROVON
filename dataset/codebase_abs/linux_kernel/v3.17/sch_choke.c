static unsigned int F_1 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 - V_2 -> V_4 ) & V_2 -> V_5 ;
}
static int F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_6 & V_7 ;
}
static int F_3 ( const struct V_1 * V_2 )
{
return V_2 -> V_6 & V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
do {
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
break;
} while ( V_2 -> V_9 [ V_2 -> V_4 ] == NULL );
}
static void F_5 ( struct V_1 * V_2 )
{
do {
V_2 -> V_3 = ( V_2 -> V_3 - 1 ) & V_2 -> V_5 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
break;
} while ( V_2 -> V_9 [ V_2 -> V_3 ] == NULL );
}
static void F_6 ( struct V_10 * V_11 , unsigned int V_12 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_14 = V_2 -> V_9 [ V_12 ] ;
V_2 -> V_9 [ V_12 ] = NULL ;
if ( V_12 == V_2 -> V_4 )
F_4 ( V_2 ) ;
if ( V_12 == V_2 -> V_3 )
F_5 ( V_2 ) ;
V_11 -> V_15 . V_16 -= F_8 ( V_14 ) ;
F_9 ( V_14 , V_11 ) ;
F_10 ( V_11 , 1 ) ;
-- V_11 -> V_2 . V_17 ;
}
static inline struct V_18 * V_18 ( const struct V_13 * V_14 )
{
F_11 ( V_14 , sizeof( struct V_18 ) ) ;
return (struct V_18 * ) F_12 ( V_14 ) -> V_19 ;
}
static inline void F_13 ( struct V_13 * V_14 , T_1 V_20 )
{
V_18 ( V_14 ) -> V_20 = V_20 ;
}
static T_1 F_14 ( const struct V_13 * V_14 )
{
return V_18 ( V_14 ) -> V_20 ;
}
static bool F_15 ( struct V_13 * V_21 ,
struct V_13 * V_22 )
{
struct V_23 V_24 ;
if ( V_21 -> V_25 != V_22 -> V_25 )
return false ;
if ( ! V_18 ( V_21 ) -> V_26 ) {
V_18 ( V_21 ) -> V_26 = 1 ;
F_16 ( V_21 , & V_24 ) ;
memcpy ( & V_18 ( V_21 ) -> V_27 , & V_24 , V_28 ) ;
}
if ( ! V_18 ( V_22 ) -> V_26 ) {
V_18 ( V_22 ) -> V_26 = 1 ;
F_16 ( V_22 , & V_24 ) ;
memcpy ( & V_18 ( V_22 ) -> V_27 , & V_24 , V_28 ) ;
}
return ! memcmp ( & V_18 ( V_21 ) -> V_27 ,
& V_18 ( V_22 ) -> V_27 ,
V_28 ) ;
}
static bool F_17 ( struct V_13 * V_14 ,
struct V_10 * V_11 , int * V_29 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_30 V_31 ;
int V_32 ;
V_32 = F_18 ( V_14 , V_2 -> V_33 , & V_31 ) ;
if ( V_32 >= 0 ) {
#ifdef F_19
switch ( V_32 ) {
case V_34 :
case V_35 :
* V_29 = V_36 | V_37 ;
case V_38 :
return false ;
}
#endif
F_13 ( V_14 , F_20 ( V_31 . V_20 ) ) ;
return true ;
}
return false ;
}
static struct V_13 * F_21 ( const struct V_1 * V_2 ,
unsigned int * V_39 )
{
struct V_13 * V_14 ;
int V_40 = 3 ;
do {
* V_39 = ( V_2 -> V_4 + F_22 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_14 = V_2 -> V_9 [ * V_39 ] ;
if ( V_14 )
return V_14 ;
} while ( -- V_40 > 0 );
return V_2 -> V_9 [ * V_39 = V_2 -> V_4 ] ;
}
static bool F_23 ( const struct V_1 * V_2 ,
struct V_13 * V_41 ,
unsigned int * V_39 )
{
struct V_13 * V_42 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_42 = F_21 ( V_2 , V_39 ) ;
if ( V_2 -> V_33 )
return F_14 ( V_41 ) == F_14 ( V_42 ) ;
return F_15 ( V_42 , V_41 ) ;
}
static int F_24 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_43 * V_44 = & V_2 -> V_45 ;
int V_46 = V_36 | V_47 ;
if ( V_2 -> V_33 ) {
if ( ! F_17 ( V_14 , V_11 , & V_46 ) )
goto V_48;
}
V_18 ( V_14 ) -> V_26 = 0 ;
V_2 -> V_49 . V_50 = F_25 ( V_44 , & V_2 -> V_49 , V_11 -> V_2 . V_17 ) ;
if ( F_26 ( & V_2 -> V_49 ) )
F_27 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_49 . V_50 <= V_44 -> V_51 )
V_2 -> V_49 . V_52 = - 1 ;
else {
unsigned int V_12 ;
if ( F_23 ( V_2 , V_14 , & V_12 ) ) {
V_2 -> V_53 . V_54 ++ ;
F_6 ( V_11 , V_12 ) ;
goto V_55;
}
if ( V_2 -> V_49 . V_50 > V_44 -> V_56 ) {
V_2 -> V_49 . V_52 = - 1 ;
V_11 -> V_15 . V_57 ++ ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_28 ( V_14 ) ) {
V_2 -> V_53 . V_58 ++ ;
goto V_55;
}
V_2 -> V_53 . V_59 ++ ;
} else if ( ++ V_2 -> V_49 . V_52 ) {
if ( F_29 ( V_44 , & V_2 -> V_49 , V_2 -> V_49 . V_50 ) ) {
V_2 -> V_49 . V_52 = 0 ;
V_2 -> V_49 . V_60 = F_30 ( V_44 ) ;
V_11 -> V_15 . V_57 ++ ;
if ( ! F_2 ( V_2 ) || ! F_28 ( V_14 ) ) {
V_2 -> V_53 . V_61 ++ ;
goto V_55;
}
V_2 -> V_53 . V_62 ++ ;
}
} else
V_2 -> V_49 . V_60 = F_30 ( V_44 ) ;
}
if ( V_11 -> V_2 . V_17 < V_2 -> V_63 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_14 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_17 ;
V_11 -> V_15 . V_16 += F_8 ( V_14 ) ;
return V_36 ;
}
V_2 -> V_53 . V_64 ++ ;
return F_9 ( V_14 , V_11 ) ;
V_55:
F_9 ( V_14 , V_11 ) ;
return V_65 ;
V_48:
if ( V_46 & V_47 )
V_11 -> V_15 . V_66 ++ ;
F_31 ( V_14 ) ;
return V_46 ;
}
static struct V_13 * F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_14 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_26 ( & V_2 -> V_49 ) )
F_33 ( & V_2 -> V_49 ) ;
return NULL ;
}
V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_9 [ V_2 -> V_4 ] = NULL ;
F_4 ( V_2 ) ;
-- V_11 -> V_2 . V_17 ;
V_11 -> V_15 . V_16 -= F_8 ( V_14 ) ;
F_34 ( V_11 , V_14 ) ;
return V_14 ;
}
static unsigned int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
unsigned int V_67 ;
V_67 = F_36 ( V_11 ) ;
if ( V_67 > 0 )
V_2 -> V_53 . V_68 ++ ;
else {
if ( ! F_26 ( & V_2 -> V_49 ) )
F_33 ( & V_2 -> V_49 ) ;
}
return V_67 ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_38 ( & V_2 -> V_49 ) ;
}
static void F_39 ( void * V_69 )
{
F_40 ( V_69 ) ;
}
static int F_41 ( struct V_10 * V_11 , struct V_70 * V_71 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_70 * V_72 [ V_73 + 1 ] ;
const struct V_74 * V_75 ;
int V_76 ;
struct V_13 * * V_77 = NULL ;
unsigned int V_78 ;
T_2 V_79 ;
if ( V_71 == NULL )
return - V_80 ;
V_76 = F_42 ( V_72 , V_73 , V_71 , V_81 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( V_72 [ V_82 ] == NULL ||
V_72 [ V_83 ] == NULL )
return - V_80 ;
V_79 = V_72 [ V_84 ] ? F_43 ( V_72 [ V_84 ] ) : 0 ;
V_75 = F_44 ( V_72 [ V_82 ] ) ;
if ( V_75 -> V_63 > V_85 )
return - V_80 ;
V_78 = F_45 ( V_75 -> V_63 + 1 ) - 1 ;
if ( V_78 != V_2 -> V_5 ) {
struct V_13 * * V_86 ;
V_86 = F_46 ( V_78 + 1 , sizeof( struct V_13 * ) ,
V_87 | V_88 ) ;
if ( ! V_86 )
V_86 = F_47 ( ( V_78 + 1 ) * sizeof( struct V_13 * ) ) ;
if ( ! V_86 )
return - V_89 ;
F_48 ( V_11 ) ;
V_77 = V_2 -> V_9 ;
if ( V_77 ) {
unsigned int V_90 = V_11 -> V_2 . V_17 , V_3 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_14 )
continue;
if ( V_3 < V_78 ) {
V_86 [ V_3 ++ ] = V_14 ;
continue;
}
V_11 -> V_15 . V_16 -= F_8 ( V_14 ) ;
-- V_11 -> V_2 . V_17 ;
F_9 ( V_14 , V_11 ) ;
}
F_10 ( V_11 , V_90 - V_11 -> V_2 . V_17 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_78 ;
V_2 -> V_9 = V_86 ;
} else
F_48 ( V_11 ) ;
V_2 -> V_6 = V_75 -> V_6 ;
V_2 -> V_63 = V_75 -> V_63 ;
F_49 ( & V_2 -> V_45 , V_75 -> V_51 , V_75 -> V_56 , V_75 -> V_91 ,
V_75 -> V_92 , V_75 -> V_93 ,
F_44 ( V_72 [ V_83 ] ) ,
V_79 ) ;
F_50 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_27 ( & V_2 -> V_49 ) ;
F_51 ( V_11 ) ;
F_39 ( V_77 ) ;
return 0 ;
}
static int F_52 ( struct V_10 * V_11 , struct V_70 * V_71 )
{
return F_41 ( V_11 , V_71 ) ;
}
static int F_53 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_70 * V_94 = NULL ;
struct V_74 V_71 = {
. V_63 = V_2 -> V_63 ,
. V_6 = V_2 -> V_6 ,
. V_51 = V_2 -> V_45 . V_51 >> V_2 -> V_45 . V_91 ,
. V_56 = V_2 -> V_45 . V_56 >> V_2 -> V_45 . V_91 ,
. V_91 = V_2 -> V_45 . V_91 ,
. V_92 = V_2 -> V_45 . V_92 ,
. V_93 = V_2 -> V_45 . V_93 ,
} ;
V_94 = F_54 ( V_14 , V_95 ) ;
if ( V_94 == NULL )
goto V_96;
if ( F_55 ( V_14 , V_82 , sizeof( V_71 ) , & V_71 ) ||
F_56 ( V_14 , V_84 , V_2 -> V_45 . V_79 ) )
goto V_96;
return F_57 ( V_14 , V_94 ) ;
V_96:
F_58 ( V_14 , V_94 ) ;
return - V_97 ;
}
static int F_59 ( struct V_10 * V_11 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_100 V_101 = {
. V_102 = V_2 -> V_53 . V_61 + V_2 -> V_53 . V_58 ,
. V_103 = V_2 -> V_53 . V_62 + V_2 -> V_53 . V_59 ,
. V_64 = V_2 -> V_53 . V_64 ,
. V_68 = V_2 -> V_53 . V_68 ,
. V_54 = V_2 -> V_53 . V_54 ,
} ;
return F_60 ( V_99 , & V_101 , sizeof( V_101 ) ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_62 ( & V_2 -> V_33 ) ;
F_39 ( V_2 -> V_9 ) ;
}
static struct V_10 * F_63 ( struct V_10 * V_11 , unsigned long V_104 )
{
return NULL ;
}
static unsigned long F_64 ( struct V_10 * V_11 , T_2 V_20 )
{
return 0 ;
}
static void F_65 ( struct V_10 * V_2 , unsigned long V_105 )
{
}
static unsigned long F_66 ( struct V_10 * V_11 , unsigned long V_106 ,
T_2 V_20 )
{
return 0 ;
}
static struct V_107 * * F_67 ( struct V_10 * V_11 , unsigned long V_105 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( V_105 )
return NULL ;
return & V_2 -> V_33 ;
}
static int F_68 ( struct V_10 * V_11 , unsigned long V_105 ,
struct V_13 * V_14 , struct V_108 * V_109 )
{
V_109 -> V_110 |= F_20 ( V_105 ) ;
return 0 ;
}
static void F_69 ( struct V_10 * V_11 , struct V_111 * V_104 )
{
if ( ! V_104 -> V_112 ) {
if ( V_104 -> V_113 ( V_11 , 1 , V_104 ) < 0 ) {
V_104 -> V_112 = 1 ;
return;
}
V_104 -> V_114 ++ ;
}
}
static struct V_13 * F_70 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_3 F_71 ( void )
{
return F_72 ( & V_115 ) ;
}
static void T_4 F_73 ( void )
{
F_74 ( & V_115 ) ;
}
