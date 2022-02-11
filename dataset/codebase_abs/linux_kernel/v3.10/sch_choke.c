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
static inline struct V_19 * V_19 ( const struct V_14 * V_15 )
{
F_14 ( V_15 , sizeof( struct V_19 ) ) ;
return (struct V_19 * ) F_15 ( V_15 ) -> V_20 ;
}
static inline void F_16 ( struct V_14 * V_15 , T_2 V_21 )
{
V_19 ( V_15 ) -> V_21 = V_21 ;
}
static T_2 F_17 ( const struct V_14 * V_15 )
{
return V_19 ( V_15 ) -> V_21 ;
}
static bool F_18 ( struct V_14 * V_22 ,
struct V_14 * V_23 )
{
if ( V_22 -> V_24 != V_23 -> V_24 )
return false ;
if ( ! V_19 ( V_22 ) -> V_25 ) {
V_19 ( V_22 ) -> V_25 = 1 ;
F_19 ( V_22 , & V_19 ( V_22 ) -> V_26 ) ;
}
if ( ! V_19 ( V_23 ) -> V_25 ) {
V_19 ( V_23 ) -> V_25 = 1 ;
F_19 ( V_23 , & V_19 ( V_23 ) -> V_26 ) ;
}
return ! memcmp ( & V_19 ( V_22 ) -> V_26 ,
& V_19 ( V_23 ) -> V_26 ,
sizeof( struct V_27 ) ) ;
}
static bool F_20 ( struct V_14 * V_15 ,
struct V_11 * V_12 , int * V_28 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_29 V_30 ;
int V_31 ;
V_31 = F_21 ( V_15 , V_3 -> V_32 , & V_30 ) ;
if ( V_31 >= 0 ) {
#ifdef F_22
switch ( V_31 ) {
case V_33 :
case V_34 :
* V_28 = V_35 | V_36 ;
case V_37 :
return false ;
}
#endif
F_16 ( V_15 , F_23 ( V_30 . V_21 ) ) ;
return true ;
}
return false ;
}
static struct V_14 * F_24 ( const struct V_2 * V_3 ,
unsigned int * V_38 )
{
struct V_14 * V_15 ;
int V_39 = 3 ;
do {
* V_38 = ( V_3 -> V_5 + F_1 ( F_4 ( V_3 ) ) ) & V_3 -> V_6 ;
V_15 = V_3 -> V_10 [ * V_38 ] ;
if ( V_15 )
return V_15 ;
} while ( -- V_39 > 0 );
return V_3 -> V_10 [ * V_38 = V_3 -> V_5 ] ;
}
static bool F_25 ( const struct V_2 * V_3 ,
struct V_14 * V_40 ,
unsigned int * V_38 )
{
struct V_14 * V_41 ;
if ( V_3 -> V_5 == V_3 -> V_4 )
return false ;
V_41 = F_24 ( V_3 , V_38 ) ;
if ( V_3 -> V_32 )
return F_17 ( V_40 ) == F_17 ( V_41 ) ;
return F_18 ( V_41 , V_40 ) ;
}
static int F_26 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
const struct V_42 * V_43 = & V_3 -> V_44 ;
int V_45 = V_35 | V_46 ;
if ( V_3 -> V_32 ) {
if ( ! F_20 ( V_15 , V_12 , & V_45 ) )
goto V_47;
}
V_19 ( V_15 ) -> V_25 = 0 ;
V_3 -> V_48 . V_49 = F_27 ( V_43 , & V_3 -> V_48 , V_12 -> V_3 . V_18 ) ;
if ( F_28 ( & V_3 -> V_48 ) )
F_29 ( & V_3 -> V_48 ) ;
if ( V_3 -> V_48 . V_49 <= V_43 -> V_50 )
V_3 -> V_48 . V_51 = - 1 ;
else {
unsigned int V_13 ;
if ( F_25 ( V_3 , V_15 , & V_13 ) ) {
V_3 -> V_52 . V_53 ++ ;
F_9 ( V_12 , V_13 ) ;
goto V_54;
}
if ( V_3 -> V_48 . V_49 > V_43 -> V_55 ) {
V_3 -> V_48 . V_51 = - 1 ;
V_12 -> V_16 . V_56 ++ ;
if ( F_6 ( V_3 ) || ! F_5 ( V_3 ) ||
! F_30 ( V_15 ) ) {
V_3 -> V_52 . V_57 ++ ;
goto V_54;
}
V_3 -> V_52 . V_58 ++ ;
} else if ( ++ V_3 -> V_48 . V_51 ) {
if ( F_31 ( V_43 , & V_3 -> V_48 , V_3 -> V_48 . V_49 ) ) {
V_3 -> V_48 . V_51 = 0 ;
V_3 -> V_48 . V_59 = F_32 ( V_43 ) ;
V_12 -> V_16 . V_56 ++ ;
if ( ! F_5 ( V_3 ) || ! F_30 ( V_15 ) ) {
V_3 -> V_52 . V_60 ++ ;
goto V_54;
}
V_3 -> V_52 . V_61 ++ ;
}
} else
V_3 -> V_48 . V_59 = F_32 ( V_43 ) ;
}
if ( V_12 -> V_3 . V_18 < V_3 -> V_62 ) {
V_3 -> V_10 [ V_3 -> V_4 ] = V_15 ;
V_3 -> V_4 = ( V_3 -> V_4 + 1 ) & V_3 -> V_6 ;
++ V_12 -> V_3 . V_18 ;
V_12 -> V_16 . V_17 += F_11 ( V_15 ) ;
return V_35 ;
}
V_3 -> V_52 . V_63 ++ ;
return F_12 ( V_15 , V_12 ) ;
V_54:
F_12 ( V_15 , V_12 ) ;
return V_64 ;
V_47:
if ( V_45 & V_46 )
V_12 -> V_16 . V_65 ++ ;
F_33 ( V_15 ) ;
return V_45 ;
}
static struct V_14 * F_34 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_14 * V_15 ;
if ( V_3 -> V_5 == V_3 -> V_4 ) {
if ( ! F_28 ( & V_3 -> V_48 ) )
F_35 ( & V_3 -> V_48 ) ;
return NULL ;
}
V_15 = V_3 -> V_10 [ V_3 -> V_5 ] ;
V_3 -> V_10 [ V_3 -> V_5 ] = NULL ;
F_7 ( V_3 ) ;
-- V_12 -> V_3 . V_18 ;
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
F_36 ( V_12 , V_15 ) ;
return V_15 ;
}
static unsigned int F_37 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
unsigned int V_66 ;
V_66 = F_38 ( V_12 ) ;
if ( V_66 > 0 )
V_3 -> V_52 . V_67 ++ ;
else {
if ( ! F_28 ( & V_3 -> V_48 ) )
F_35 ( & V_3 -> V_48 ) ;
}
return V_66 ;
}
static void F_39 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_40 ( & V_3 -> V_48 ) ;
}
static void F_41 ( void * V_68 )
{
if ( V_68 ) {
if ( F_42 ( V_68 ) )
F_43 ( V_68 ) ;
else
F_44 ( V_68 ) ;
}
}
static int F_45 ( struct V_11 * V_12 , struct V_69 * V_70 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_69 * V_71 [ V_72 + 1 ] ;
const struct V_73 * V_74 ;
int V_75 ;
struct V_14 * * V_76 = NULL ;
unsigned int V_77 ;
T_1 V_78 ;
if ( V_70 == NULL )
return - V_79 ;
V_75 = F_46 ( V_71 , V_72 , V_70 , V_80 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_71 [ V_81 ] == NULL ||
V_71 [ V_82 ] == NULL )
return - V_79 ;
V_78 = V_71 [ V_83 ] ? F_47 ( V_71 [ V_83 ] ) : 0 ;
V_74 = F_48 ( V_71 [ V_81 ] ) ;
if ( V_74 -> V_62 > V_84 )
return - V_79 ;
V_77 = F_49 ( V_74 -> V_62 + 1 ) - 1 ;
if ( V_77 != V_3 -> V_6 ) {
struct V_14 * * V_85 ;
V_85 = F_50 ( V_77 + 1 , sizeof( struct V_14 * ) , V_86 ) ;
if ( ! V_85 )
V_85 = F_51 ( ( V_77 + 1 ) * sizeof( struct V_14 * ) ) ;
if ( ! V_85 )
return - V_87 ;
F_52 ( V_12 ) ;
V_76 = V_3 -> V_10 ;
if ( V_76 ) {
unsigned int V_88 = V_12 -> V_3 . V_18 , V_4 = 0 ;
while ( V_3 -> V_5 != V_3 -> V_4 ) {
struct V_14 * V_15 = V_3 -> V_10 [ V_3 -> V_5 ] ;
V_3 -> V_5 = ( V_3 -> V_5 + 1 ) & V_3 -> V_6 ;
if ( ! V_15 )
continue;
if ( V_4 < V_77 ) {
V_85 [ V_4 ++ ] = V_15 ;
continue;
}
V_12 -> V_16 . V_17 -= F_11 ( V_15 ) ;
-- V_12 -> V_3 . V_18 ;
F_12 ( V_15 , V_12 ) ;
}
F_13 ( V_12 , V_88 - V_12 -> V_3 . V_18 ) ;
V_3 -> V_5 = 0 ;
V_3 -> V_4 = V_4 ;
}
V_3 -> V_6 = V_77 ;
V_3 -> V_10 = V_85 ;
} else
F_52 ( V_12 ) ;
V_3 -> V_7 = V_74 -> V_7 ;
V_3 -> V_62 = V_74 -> V_62 ;
F_53 ( & V_3 -> V_44 , V_74 -> V_50 , V_74 -> V_55 , V_74 -> V_89 ,
V_74 -> V_90 , V_74 -> V_91 ,
F_48 ( V_71 [ V_82 ] ) ,
V_78 ) ;
F_54 ( & V_3 -> V_48 ) ;
if ( V_3 -> V_5 == V_3 -> V_4 )
F_29 ( & V_3 -> V_48 ) ;
F_55 ( V_12 ) ;
F_41 ( V_76 ) ;
return 0 ;
}
static int F_56 ( struct V_11 * V_12 , struct V_69 * V_70 )
{
return F_45 ( V_12 , V_70 ) ;
}
static int F_57 ( struct V_11 * V_12 , struct V_14 * V_15 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_69 * V_92 = NULL ;
struct V_73 V_70 = {
. V_62 = V_3 -> V_62 ,
. V_7 = V_3 -> V_7 ,
. V_50 = V_3 -> V_44 . V_50 >> V_3 -> V_44 . V_89 ,
. V_55 = V_3 -> V_44 . V_55 >> V_3 -> V_44 . V_89 ,
. V_89 = V_3 -> V_44 . V_89 ,
. V_90 = V_3 -> V_44 . V_90 ,
. V_91 = V_3 -> V_44 . V_91 ,
} ;
V_92 = F_58 ( V_15 , V_93 ) ;
if ( V_92 == NULL )
goto V_94;
if ( F_59 ( V_15 , V_81 , sizeof( V_70 ) , & V_70 ) ||
F_60 ( V_15 , V_83 , V_3 -> V_44 . V_78 ) )
goto V_94;
return F_61 ( V_15 , V_92 ) ;
V_94:
F_62 ( V_15 , V_92 ) ;
return - V_95 ;
}
static int F_63 ( struct V_11 * V_12 , struct V_96 * V_97 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
struct V_98 V_99 = {
. V_100 = V_3 -> V_52 . V_60 + V_3 -> V_52 . V_57 ,
. V_101 = V_3 -> V_52 . V_61 + V_3 -> V_52 . V_58 ,
. V_63 = V_3 -> V_52 . V_63 ,
. V_67 = V_3 -> V_52 . V_67 ,
. V_53 = V_3 -> V_52 . V_53 ,
} ;
return F_64 ( V_97 , & V_99 , sizeof( V_99 ) ) ;
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
F_66 ( & V_3 -> V_32 ) ;
F_41 ( V_3 -> V_10 ) ;
}
static struct V_11 * F_67 ( struct V_11 * V_12 , unsigned long V_102 )
{
return NULL ;
}
static unsigned long F_68 ( struct V_11 * V_12 , T_1 V_21 )
{
return 0 ;
}
static void F_69 ( struct V_11 * V_3 , unsigned long V_103 )
{
}
static unsigned long F_70 ( struct V_11 * V_12 , unsigned long V_104 ,
T_1 V_21 )
{
return 0 ;
}
static struct V_105 * * F_71 ( struct V_11 * V_12 , unsigned long V_103 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
if ( V_103 )
return NULL ;
return & V_3 -> V_32 ;
}
static int F_72 ( struct V_11 * V_12 , unsigned long V_103 ,
struct V_14 * V_15 , struct V_106 * V_107 )
{
V_107 -> V_108 |= F_23 ( V_103 ) ;
return 0 ;
}
static void F_73 ( struct V_11 * V_12 , struct V_109 * V_102 )
{
if ( ! V_102 -> V_110 ) {
if ( V_102 -> V_111 ( V_12 , 1 , V_102 ) < 0 ) {
V_102 -> V_110 = 1 ;
return;
}
V_102 -> V_112 ++ ;
}
}
static struct V_14 * F_74 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_10 ( V_12 ) ;
return ( V_3 -> V_5 != V_3 -> V_4 ) ? V_3 -> V_10 [ V_3 -> V_5 ] : NULL ;
}
static int T_3 F_75 ( void )
{
return F_76 ( & V_113 ) ;
}
static void T_4 F_77 ( void )
{
F_78 ( & V_113 ) ;
}
