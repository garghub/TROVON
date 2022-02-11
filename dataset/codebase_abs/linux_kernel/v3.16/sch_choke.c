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
if ( V_21 -> V_23 != V_22 -> V_23 )
return false ;
if ( ! V_18 ( V_21 ) -> V_24 ) {
V_18 ( V_21 ) -> V_24 = 1 ;
F_16 ( V_21 , & V_18 ( V_21 ) -> V_25 ) ;
}
if ( ! V_18 ( V_22 ) -> V_24 ) {
V_18 ( V_22 ) -> V_24 = 1 ;
F_16 ( V_22 , & V_18 ( V_22 ) -> V_25 ) ;
}
return ! memcmp ( & V_18 ( V_21 ) -> V_25 ,
& V_18 ( V_22 ) -> V_25 ,
sizeof( struct V_26 ) ) ;
}
static bool F_17 ( struct V_13 * V_14 ,
struct V_10 * V_11 , int * V_27 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_28 V_29 ;
int V_30 ;
V_30 = F_18 ( V_14 , V_2 -> V_31 , & V_29 ) ;
if ( V_30 >= 0 ) {
#ifdef F_19
switch ( V_30 ) {
case V_32 :
case V_33 :
* V_27 = V_34 | V_35 ;
case V_36 :
return false ;
}
#endif
F_13 ( V_14 , F_20 ( V_29 . V_20 ) ) ;
return true ;
}
return false ;
}
static struct V_13 * F_21 ( const struct V_1 * V_2 ,
unsigned int * V_37 )
{
struct V_13 * V_14 ;
int V_38 = 3 ;
do {
* V_37 = ( V_2 -> V_4 + F_22 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_14 = V_2 -> V_9 [ * V_37 ] ;
if ( V_14 )
return V_14 ;
} while ( -- V_38 > 0 );
return V_2 -> V_9 [ * V_37 = V_2 -> V_4 ] ;
}
static bool F_23 ( const struct V_1 * V_2 ,
struct V_13 * V_39 ,
unsigned int * V_37 )
{
struct V_13 * V_40 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_40 = F_21 ( V_2 , V_37 ) ;
if ( V_2 -> V_31 )
return F_14 ( V_39 ) == F_14 ( V_40 ) ;
return F_15 ( V_40 , V_39 ) ;
}
static int F_24 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_41 * V_42 = & V_2 -> V_43 ;
int V_44 = V_34 | V_45 ;
if ( V_2 -> V_31 ) {
if ( ! F_17 ( V_14 , V_11 , & V_44 ) )
goto V_46;
}
V_18 ( V_14 ) -> V_24 = 0 ;
V_2 -> V_47 . V_48 = F_25 ( V_42 , & V_2 -> V_47 , V_11 -> V_2 . V_17 ) ;
if ( F_26 ( & V_2 -> V_47 ) )
F_27 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_47 . V_48 <= V_42 -> V_49 )
V_2 -> V_47 . V_50 = - 1 ;
else {
unsigned int V_12 ;
if ( F_23 ( V_2 , V_14 , & V_12 ) ) {
V_2 -> V_51 . V_52 ++ ;
F_6 ( V_11 , V_12 ) ;
goto V_53;
}
if ( V_2 -> V_47 . V_48 > V_42 -> V_54 ) {
V_2 -> V_47 . V_50 = - 1 ;
V_11 -> V_15 . V_55 ++ ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_28 ( V_14 ) ) {
V_2 -> V_51 . V_56 ++ ;
goto V_53;
}
V_2 -> V_51 . V_57 ++ ;
} else if ( ++ V_2 -> V_47 . V_50 ) {
if ( F_29 ( V_42 , & V_2 -> V_47 , V_2 -> V_47 . V_48 ) ) {
V_2 -> V_47 . V_50 = 0 ;
V_2 -> V_47 . V_58 = F_30 ( V_42 ) ;
V_11 -> V_15 . V_55 ++ ;
if ( ! F_2 ( V_2 ) || ! F_28 ( V_14 ) ) {
V_2 -> V_51 . V_59 ++ ;
goto V_53;
}
V_2 -> V_51 . V_60 ++ ;
}
} else
V_2 -> V_47 . V_58 = F_30 ( V_42 ) ;
}
if ( V_11 -> V_2 . V_17 < V_2 -> V_61 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_14 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_17 ;
V_11 -> V_15 . V_16 += F_8 ( V_14 ) ;
return V_34 ;
}
V_2 -> V_51 . V_62 ++ ;
return F_9 ( V_14 , V_11 ) ;
V_53:
F_9 ( V_14 , V_11 ) ;
return V_63 ;
V_46:
if ( V_44 & V_45 )
V_11 -> V_15 . V_64 ++ ;
F_31 ( V_14 ) ;
return V_44 ;
}
static struct V_13 * F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_14 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_26 ( & V_2 -> V_47 ) )
F_33 ( & V_2 -> V_47 ) ;
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
unsigned int V_65 ;
V_65 = F_36 ( V_11 ) ;
if ( V_65 > 0 )
V_2 -> V_51 . V_66 ++ ;
else {
if ( ! F_26 ( & V_2 -> V_47 ) )
F_33 ( & V_2 -> V_47 ) ;
}
return V_65 ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_38 ( & V_2 -> V_47 ) ;
}
static void F_39 ( void * V_67 )
{
F_40 ( V_67 ) ;
}
static int F_41 ( struct V_10 * V_11 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_68 * V_70 [ V_71 + 1 ] ;
const struct V_72 * V_73 ;
int V_74 ;
struct V_13 * * V_75 = NULL ;
unsigned int V_76 ;
T_2 V_77 ;
if ( V_69 == NULL )
return - V_78 ;
V_74 = F_42 ( V_70 , V_71 , V_69 , V_79 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_70 [ V_80 ] == NULL ||
V_70 [ V_81 ] == NULL )
return - V_78 ;
V_77 = V_70 [ V_82 ] ? F_43 ( V_70 [ V_82 ] ) : 0 ;
V_73 = F_44 ( V_70 [ V_80 ] ) ;
if ( V_73 -> V_61 > V_83 )
return - V_78 ;
V_76 = F_45 ( V_73 -> V_61 + 1 ) - 1 ;
if ( V_76 != V_2 -> V_5 ) {
struct V_13 * * V_84 ;
V_84 = F_46 ( V_76 + 1 , sizeof( struct V_13 * ) ,
V_85 | V_86 ) ;
if ( ! V_84 )
V_84 = F_47 ( ( V_76 + 1 ) * sizeof( struct V_13 * ) ) ;
if ( ! V_84 )
return - V_87 ;
F_48 ( V_11 ) ;
V_75 = V_2 -> V_9 ;
if ( V_75 ) {
unsigned int V_88 = V_11 -> V_2 . V_17 , V_3 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_14 )
continue;
if ( V_3 < V_76 ) {
V_84 [ V_3 ++ ] = V_14 ;
continue;
}
V_11 -> V_15 . V_16 -= F_8 ( V_14 ) ;
-- V_11 -> V_2 . V_17 ;
F_9 ( V_14 , V_11 ) ;
}
F_10 ( V_11 , V_88 - V_11 -> V_2 . V_17 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_76 ;
V_2 -> V_9 = V_84 ;
} else
F_48 ( V_11 ) ;
V_2 -> V_6 = V_73 -> V_6 ;
V_2 -> V_61 = V_73 -> V_61 ;
F_49 ( & V_2 -> V_43 , V_73 -> V_49 , V_73 -> V_54 , V_73 -> V_89 ,
V_73 -> V_90 , V_73 -> V_91 ,
F_44 ( V_70 [ V_81 ] ) ,
V_77 ) ;
F_50 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_27 ( & V_2 -> V_47 ) ;
F_51 ( V_11 ) ;
F_39 ( V_75 ) ;
return 0 ;
}
static int F_52 ( struct V_10 * V_11 , struct V_68 * V_69 )
{
return F_41 ( V_11 , V_69 ) ;
}
static int F_53 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_68 * V_92 = NULL ;
struct V_72 V_69 = {
. V_61 = V_2 -> V_61 ,
. V_6 = V_2 -> V_6 ,
. V_49 = V_2 -> V_43 . V_49 >> V_2 -> V_43 . V_89 ,
. V_54 = V_2 -> V_43 . V_54 >> V_2 -> V_43 . V_89 ,
. V_89 = V_2 -> V_43 . V_89 ,
. V_90 = V_2 -> V_43 . V_90 ,
. V_91 = V_2 -> V_43 . V_91 ,
} ;
V_92 = F_54 ( V_14 , V_93 ) ;
if ( V_92 == NULL )
goto V_94;
if ( F_55 ( V_14 , V_80 , sizeof( V_69 ) , & V_69 ) ||
F_56 ( V_14 , V_82 , V_2 -> V_43 . V_77 ) )
goto V_94;
return F_57 ( V_14 , V_92 ) ;
V_94:
F_58 ( V_14 , V_92 ) ;
return - V_95 ;
}
static int F_59 ( struct V_10 * V_11 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_98 V_99 = {
. V_100 = V_2 -> V_51 . V_59 + V_2 -> V_51 . V_56 ,
. V_101 = V_2 -> V_51 . V_60 + V_2 -> V_51 . V_57 ,
. V_62 = V_2 -> V_51 . V_62 ,
. V_66 = V_2 -> V_51 . V_66 ,
. V_52 = V_2 -> V_51 . V_52 ,
} ;
return F_60 ( V_97 , & V_99 , sizeof( V_99 ) ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_62 ( & V_2 -> V_31 ) ;
F_39 ( V_2 -> V_9 ) ;
}
static struct V_10 * F_63 ( struct V_10 * V_11 , unsigned long V_102 )
{
return NULL ;
}
static unsigned long F_64 ( struct V_10 * V_11 , T_2 V_20 )
{
return 0 ;
}
static void F_65 ( struct V_10 * V_2 , unsigned long V_103 )
{
}
static unsigned long F_66 ( struct V_10 * V_11 , unsigned long V_104 ,
T_2 V_20 )
{
return 0 ;
}
static struct V_105 * * F_67 ( struct V_10 * V_11 , unsigned long V_103 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( V_103 )
return NULL ;
return & V_2 -> V_31 ;
}
static int F_68 ( struct V_10 * V_11 , unsigned long V_103 ,
struct V_13 * V_14 , struct V_106 * V_107 )
{
V_107 -> V_108 |= F_20 ( V_103 ) ;
return 0 ;
}
static void F_69 ( struct V_10 * V_11 , struct V_109 * V_102 )
{
if ( ! V_102 -> V_110 ) {
if ( V_102 -> V_111 ( V_11 , 1 , V_102 ) < 0 ) {
V_102 -> V_110 = 1 ;
return;
}
V_102 -> V_112 ++ ;
}
}
static struct V_13 * F_70 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_3 F_71 ( void )
{
return F_72 ( & V_113 ) ;
}
static void T_4 F_73 ( void )
{
F_74 ( & V_113 ) ;
}
