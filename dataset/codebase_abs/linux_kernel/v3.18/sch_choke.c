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
F_8 ( V_11 , V_14 ) ;
F_9 ( V_14 , V_11 ) ;
F_10 ( V_11 , 1 ) ;
-- V_11 -> V_2 . V_15 ;
}
static inline struct V_16 * V_16 ( const struct V_13 * V_14 )
{
F_11 ( V_14 , sizeof( struct V_16 ) ) ;
return (struct V_16 * ) F_12 ( V_14 ) -> V_17 ;
}
static inline void F_13 ( struct V_13 * V_14 , T_1 V_18 )
{
V_16 ( V_14 ) -> V_18 = V_18 ;
}
static T_1 F_14 ( const struct V_13 * V_14 )
{
return V_16 ( V_14 ) -> V_18 ;
}
static bool F_15 ( struct V_13 * V_19 ,
struct V_13 * V_20 )
{
struct V_21 V_22 ;
if ( V_19 -> V_23 != V_20 -> V_23 )
return false ;
if ( ! V_16 ( V_19 ) -> V_24 ) {
V_16 ( V_19 ) -> V_24 = 1 ;
F_16 ( V_19 , & V_22 ) ;
memcpy ( & V_16 ( V_19 ) -> V_25 , & V_22 , V_26 ) ;
}
if ( ! V_16 ( V_20 ) -> V_24 ) {
V_16 ( V_20 ) -> V_24 = 1 ;
F_16 ( V_20 , & V_22 ) ;
memcpy ( & V_16 ( V_20 ) -> V_25 , & V_22 , V_26 ) ;
}
return ! memcmp ( & V_16 ( V_19 ) -> V_25 ,
& V_16 ( V_20 ) -> V_25 ,
V_26 ) ;
}
static bool F_17 ( struct V_13 * V_14 ,
struct V_10 * V_11 , int * V_27 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_18 ( V_2 -> V_33 ) ;
V_32 = F_19 ( V_14 , V_31 , & V_29 ) ;
if ( V_32 >= 0 ) {
#ifdef F_20
switch ( V_32 ) {
case V_34 :
case V_35 :
* V_27 = V_36 | V_37 ;
case V_38 :
return false ;
}
#endif
F_13 ( V_14 , F_21 ( V_29 . V_18 ) ) ;
return true ;
}
return false ;
}
static struct V_13 * F_22 ( const struct V_1 * V_2 ,
unsigned int * V_39 )
{
struct V_13 * V_14 ;
int V_40 = 3 ;
do {
* V_39 = ( V_2 -> V_4 + F_23 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_14 = V_2 -> V_9 [ * V_39 ] ;
if ( V_14 )
return V_14 ;
} while ( -- V_40 > 0 );
return V_2 -> V_9 [ * V_39 = V_2 -> V_4 ] ;
}
static bool F_24 ( const struct V_1 * V_2 ,
struct V_13 * V_41 ,
unsigned int * V_39 )
{
struct V_13 * V_42 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_42 = F_22 ( V_2 , V_39 ) ;
if ( F_25 ( V_2 -> V_33 ) )
return F_14 ( V_41 ) == F_14 ( V_42 ) ;
return F_15 ( V_42 , V_41 ) ;
}
static int F_26 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
int V_43 = V_36 | V_44 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_45 * V_46 = & V_2 -> V_47 ;
if ( F_25 ( V_2 -> V_33 ) ) {
if ( ! F_17 ( V_14 , V_11 , & V_43 ) )
goto V_48;
}
V_16 ( V_14 ) -> V_24 = 0 ;
V_2 -> V_49 . V_50 = F_27 ( V_46 , & V_2 -> V_49 , V_11 -> V_2 . V_15 ) ;
if ( F_28 ( & V_2 -> V_49 ) )
F_29 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_49 . V_50 <= V_46 -> V_51 )
V_2 -> V_49 . V_52 = - 1 ;
else {
unsigned int V_12 ;
if ( F_24 ( V_2 , V_14 , & V_12 ) ) {
V_2 -> V_53 . V_54 ++ ;
F_6 ( V_11 , V_12 ) ;
goto V_55;
}
if ( V_2 -> V_49 . V_50 > V_46 -> V_56 ) {
V_2 -> V_49 . V_52 = - 1 ;
F_30 ( V_11 ) ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_31 ( V_14 ) ) {
V_2 -> V_53 . V_57 ++ ;
goto V_55;
}
V_2 -> V_53 . V_58 ++ ;
} else if ( ++ V_2 -> V_49 . V_52 ) {
if ( F_32 ( V_46 , & V_2 -> V_49 , V_2 -> V_49 . V_50 ) ) {
V_2 -> V_49 . V_52 = 0 ;
V_2 -> V_49 . V_59 = F_33 ( V_46 ) ;
F_30 ( V_11 ) ;
if ( ! F_2 ( V_2 ) || ! F_31 ( V_14 ) ) {
V_2 -> V_53 . V_60 ++ ;
goto V_55;
}
V_2 -> V_53 . V_61 ++ ;
}
} else
V_2 -> V_49 . V_59 = F_33 ( V_46 ) ;
}
if ( V_11 -> V_2 . V_15 < V_2 -> V_62 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_14 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_15 ;
F_34 ( V_11 , V_14 ) ;
return V_36 ;
}
V_2 -> V_53 . V_63 ++ ;
return F_9 ( V_14 , V_11 ) ;
V_55:
F_9 ( V_14 , V_11 ) ;
return V_64 ;
V_48:
if ( V_43 & V_44 )
F_35 ( V_11 ) ;
F_36 ( V_14 ) ;
return V_43 ;
}
static struct V_13 * F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_14 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_28 ( & V_2 -> V_49 ) )
F_38 ( & V_2 -> V_49 ) ;
return NULL ;
}
V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_9 [ V_2 -> V_4 ] = NULL ;
F_4 ( V_2 ) ;
-- V_11 -> V_2 . V_15 ;
F_8 ( V_11 , V_14 ) ;
F_39 ( V_11 , V_14 ) ;
return V_14 ;
}
static unsigned int F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
unsigned int V_65 ;
V_65 = F_41 ( V_11 ) ;
if ( V_65 > 0 )
V_2 -> V_53 . V_66 ++ ;
else {
if ( ! F_28 ( & V_2 -> V_49 ) )
F_38 ( & V_2 -> V_49 ) ;
}
return V_65 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_43 ( & V_2 -> V_49 ) ;
}
static void F_44 ( void * V_67 )
{
F_45 ( V_67 ) ;
}
static int F_46 ( struct V_10 * V_11 , struct V_68 * V_69 )
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
V_74 = F_47 ( V_70 , V_71 , V_69 , V_79 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_70 [ V_80 ] == NULL ||
V_70 [ V_81 ] == NULL )
return - V_78 ;
V_77 = V_70 [ V_82 ] ? F_48 ( V_70 [ V_82 ] ) : 0 ;
V_73 = F_49 ( V_70 [ V_80 ] ) ;
if ( V_73 -> V_62 > V_83 )
return - V_78 ;
V_76 = F_50 ( V_73 -> V_62 + 1 ) - 1 ;
if ( V_76 != V_2 -> V_5 ) {
struct V_13 * * V_84 ;
V_84 = F_51 ( V_76 + 1 , sizeof( struct V_13 * ) ,
V_85 | V_86 ) ;
if ( ! V_84 )
V_84 = F_52 ( ( V_76 + 1 ) * sizeof( struct V_13 * ) ) ;
if ( ! V_84 )
return - V_87 ;
F_53 ( V_11 ) ;
V_75 = V_2 -> V_9 ;
if ( V_75 ) {
unsigned int V_88 = V_11 -> V_2 . V_15 , V_3 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_14 )
continue;
if ( V_3 < V_76 ) {
V_84 [ V_3 ++ ] = V_14 ;
continue;
}
F_8 ( V_11 , V_14 ) ;
-- V_11 -> V_2 . V_15 ;
F_9 ( V_14 , V_11 ) ;
}
F_10 ( V_11 , V_88 - V_11 -> V_2 . V_15 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_76 ;
V_2 -> V_9 = V_84 ;
} else
F_53 ( V_11 ) ;
V_2 -> V_6 = V_73 -> V_6 ;
V_2 -> V_62 = V_73 -> V_62 ;
F_54 ( & V_2 -> V_47 , V_73 -> V_51 , V_73 -> V_56 , V_73 -> V_89 ,
V_73 -> V_90 , V_73 -> V_91 ,
F_49 ( V_70 [ V_81 ] ) ,
V_77 ) ;
F_55 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_29 ( & V_2 -> V_49 ) ;
F_56 ( V_11 ) ;
F_44 ( V_75 ) ;
return 0 ;
}
static int F_57 ( struct V_10 * V_11 , struct V_68 * V_69 )
{
return F_46 ( V_11 , V_69 ) ;
}
static int F_58 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_68 * V_92 = NULL ;
struct V_72 V_69 = {
. V_62 = V_2 -> V_62 ,
. V_6 = V_2 -> V_6 ,
. V_51 = V_2 -> V_47 . V_51 >> V_2 -> V_47 . V_89 ,
. V_56 = V_2 -> V_47 . V_56 >> V_2 -> V_47 . V_89 ,
. V_89 = V_2 -> V_47 . V_89 ,
. V_90 = V_2 -> V_47 . V_90 ,
. V_91 = V_2 -> V_47 . V_91 ,
} ;
V_92 = F_59 ( V_14 , V_93 ) ;
if ( V_92 == NULL )
goto V_94;
if ( F_60 ( V_14 , V_80 , sizeof( V_69 ) , & V_69 ) ||
F_61 ( V_14 , V_82 , V_2 -> V_47 . V_77 ) )
goto V_94;
return F_62 ( V_14 , V_92 ) ;
V_94:
F_63 ( V_14 , V_92 ) ;
return - V_95 ;
}
static int F_64 ( struct V_10 * V_11 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_98 V_99 = {
. V_100 = V_2 -> V_53 . V_60 + V_2 -> V_53 . V_57 ,
. V_101 = V_2 -> V_53 . V_61 + V_2 -> V_53 . V_58 ,
. V_63 = V_2 -> V_53 . V_63 ,
. V_66 = V_2 -> V_53 . V_66 ,
. V_54 = V_2 -> V_53 . V_54 ,
} ;
return F_65 ( V_97 , & V_99 , sizeof( V_99 ) ) ;
}
static void F_66 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_67 ( & V_2 -> V_33 ) ;
F_44 ( V_2 -> V_9 ) ;
}
static struct V_10 * F_68 ( struct V_10 * V_11 , unsigned long V_102 )
{
return NULL ;
}
static unsigned long F_69 ( struct V_10 * V_11 , T_2 V_18 )
{
return 0 ;
}
static void F_70 ( struct V_10 * V_2 , unsigned long V_103 )
{
}
static unsigned long F_71 ( struct V_10 * V_11 , unsigned long V_104 ,
T_2 V_18 )
{
return 0 ;
}
static struct V_30 T_3 * * F_72 ( struct V_10 * V_11 ,
unsigned long V_103 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( V_103 )
return NULL ;
return & V_2 -> V_33 ;
}
static int F_73 ( struct V_10 * V_11 , unsigned long V_103 ,
struct V_13 * V_14 , struct V_105 * V_106 )
{
V_106 -> V_107 |= F_21 ( V_103 ) ;
return 0 ;
}
static void F_74 ( struct V_10 * V_11 , struct V_108 * V_102 )
{
if ( ! V_102 -> V_109 ) {
if ( V_102 -> V_110 ( V_11 , 1 , V_102 ) < 0 ) {
V_102 -> V_109 = 1 ;
return;
}
V_102 -> V_111 ++ ;
}
}
static struct V_13 * F_75 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_4 F_76 ( void )
{
return F_77 ( & V_112 ) ;
}
static void T_5 F_78 ( void )
{
F_79 ( & V_112 ) ;
}
