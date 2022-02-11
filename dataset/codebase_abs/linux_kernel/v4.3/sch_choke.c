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
F_16 ( V_19 , & V_22 , 0 ) ;
F_17 ( & V_16 ( V_19 ) -> V_25 , & V_22 ) ;
}
if ( ! V_16 ( V_20 ) -> V_24 ) {
V_16 ( V_20 ) -> V_24 = 1 ;
F_16 ( V_20 , & V_22 , 0 ) ;
F_17 ( & V_16 ( V_20 ) -> V_25 , & V_22 ) ;
}
return ! memcmp ( & V_16 ( V_19 ) -> V_25 ,
& V_16 ( V_20 ) -> V_25 ,
sizeof( V_16 ( V_19 ) -> V_25 ) ) ;
}
static bool F_18 ( struct V_13 * V_14 ,
struct V_10 * V_11 , int * V_26 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_19 ( V_2 -> V_32 ) ;
V_31 = F_20 ( V_14 , V_30 , & V_28 , false ) ;
if ( V_31 >= 0 ) {
#ifdef F_21
switch ( V_31 ) {
case V_33 :
case V_34 :
* V_26 = V_35 | V_36 ;
case V_37 :
return false ;
}
#endif
F_13 ( V_14 , F_22 ( V_28 . V_18 ) ) ;
return true ;
}
return false ;
}
static struct V_13 * F_23 ( const struct V_1 * V_2 ,
unsigned int * V_38 )
{
struct V_13 * V_14 ;
int V_39 = 3 ;
do {
* V_38 = ( V_2 -> V_4 + F_24 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_14 = V_2 -> V_9 [ * V_38 ] ;
if ( V_14 )
return V_14 ;
} while ( -- V_39 > 0 );
return V_2 -> V_9 [ * V_38 = V_2 -> V_4 ] ;
}
static bool F_25 ( const struct V_1 * V_2 ,
struct V_13 * V_40 ,
unsigned int * V_38 )
{
struct V_13 * V_41 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_41 = F_23 ( V_2 , V_38 ) ;
if ( F_26 ( V_2 -> V_32 ) )
return F_14 ( V_40 ) == F_14 ( V_41 ) ;
return F_15 ( V_41 , V_40 ) ;
}
static int F_27 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
int V_42 = V_35 | V_43 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_44 * V_45 = & V_2 -> V_46 ;
if ( F_26 ( V_2 -> V_32 ) ) {
if ( ! F_18 ( V_14 , V_11 , & V_42 ) )
goto V_47;
}
V_16 ( V_14 ) -> V_24 = 0 ;
V_2 -> V_48 . V_49 = F_28 ( V_45 , & V_2 -> V_48 , V_11 -> V_2 . V_15 ) ;
if ( F_29 ( & V_2 -> V_48 ) )
F_30 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_48 . V_49 <= V_45 -> V_50 )
V_2 -> V_48 . V_51 = - 1 ;
else {
unsigned int V_12 ;
if ( F_25 ( V_2 , V_14 , & V_12 ) ) {
V_2 -> V_52 . V_53 ++ ;
F_6 ( V_11 , V_12 ) ;
goto V_54;
}
if ( V_2 -> V_48 . V_49 > V_45 -> V_55 ) {
V_2 -> V_48 . V_51 = - 1 ;
F_31 ( V_11 ) ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_32 ( V_14 ) ) {
V_2 -> V_52 . V_56 ++ ;
goto V_54;
}
V_2 -> V_52 . V_57 ++ ;
} else if ( ++ V_2 -> V_48 . V_51 ) {
if ( F_33 ( V_45 , & V_2 -> V_48 , V_2 -> V_48 . V_49 ) ) {
V_2 -> V_48 . V_51 = 0 ;
V_2 -> V_48 . V_58 = F_34 ( V_45 ) ;
F_31 ( V_11 ) ;
if ( ! F_2 ( V_2 ) || ! F_32 ( V_14 ) ) {
V_2 -> V_52 . V_59 ++ ;
goto V_54;
}
V_2 -> V_52 . V_60 ++ ;
}
} else
V_2 -> V_48 . V_58 = F_34 ( V_45 ) ;
}
if ( V_11 -> V_2 . V_15 < V_2 -> V_61 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_14 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_15 ;
F_35 ( V_11 , V_14 ) ;
return V_35 ;
}
V_2 -> V_52 . V_62 ++ ;
return F_9 ( V_14 , V_11 ) ;
V_54:
F_9 ( V_14 , V_11 ) ;
return V_63 ;
V_47:
if ( V_42 & V_43 )
F_36 ( V_11 ) ;
F_37 ( V_14 ) ;
return V_42 ;
}
static struct V_13 * F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_14 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_29 ( & V_2 -> V_48 ) )
F_39 ( & V_2 -> V_48 ) ;
return NULL ;
}
V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_9 [ V_2 -> V_4 ] = NULL ;
F_4 ( V_2 ) ;
-- V_11 -> V_2 . V_15 ;
F_8 ( V_11 , V_14 ) ;
F_40 ( V_11 , V_14 ) ;
return V_14 ;
}
static unsigned int F_41 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
unsigned int V_64 ;
V_64 = F_42 ( V_11 ) ;
if ( V_64 > 0 )
V_2 -> V_52 . V_65 ++ ;
else {
if ( ! F_29 ( & V_2 -> V_48 ) )
F_39 ( & V_2 -> V_48 ) ;
}
return V_64 ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_14 )
continue;
F_8 ( V_11 , V_14 ) ;
-- V_11 -> V_2 . V_15 ;
F_9 ( V_14 , V_11 ) ;
}
memset ( V_2 -> V_9 , 0 , ( V_2 -> V_5 + 1 ) * sizeof( struct V_13 * ) ) ;
V_2 -> V_4 = V_2 -> V_3 = 0 ;
F_44 ( & V_2 -> V_48 ) ;
}
static void F_45 ( void * V_66 )
{
F_46 ( V_66 ) ;
}
static int F_47 ( struct V_10 * V_11 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_67 * V_69 [ V_70 + 1 ] ;
const struct V_71 * V_72 ;
int V_73 ;
struct V_13 * * V_74 = NULL ;
unsigned int V_75 ;
T_2 V_76 ;
if ( V_68 == NULL )
return - V_77 ;
V_73 = F_48 ( V_69 , V_70 , V_68 , V_78 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_69 [ V_79 ] == NULL ||
V_69 [ V_80 ] == NULL )
return - V_77 ;
V_76 = V_69 [ V_81 ] ? F_49 ( V_69 [ V_81 ] ) : 0 ;
V_72 = F_50 ( V_69 [ V_79 ] ) ;
if ( V_72 -> V_61 > V_82 )
return - V_77 ;
V_75 = F_51 ( V_72 -> V_61 + 1 ) - 1 ;
if ( V_75 != V_2 -> V_5 ) {
struct V_13 * * V_83 ;
V_83 = F_52 ( V_75 + 1 , sizeof( struct V_13 * ) ,
V_84 | V_85 ) ;
if ( ! V_83 )
V_83 = F_53 ( ( V_75 + 1 ) * sizeof( struct V_13 * ) ) ;
if ( ! V_83 )
return - V_86 ;
F_54 ( V_11 ) ;
V_74 = V_2 -> V_9 ;
if ( V_74 ) {
unsigned int V_87 = V_11 -> V_2 . V_15 , V_3 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_14 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_14 )
continue;
if ( V_3 < V_75 ) {
V_83 [ V_3 ++ ] = V_14 ;
continue;
}
F_8 ( V_11 , V_14 ) ;
-- V_11 -> V_2 . V_15 ;
F_9 ( V_14 , V_11 ) ;
}
F_10 ( V_11 , V_87 - V_11 -> V_2 . V_15 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_75 ;
V_2 -> V_9 = V_83 ;
} else
F_54 ( V_11 ) ;
V_2 -> V_6 = V_72 -> V_6 ;
V_2 -> V_61 = V_72 -> V_61 ;
F_55 ( & V_2 -> V_46 , V_72 -> V_50 , V_72 -> V_55 , V_72 -> V_88 ,
V_72 -> V_89 , V_72 -> V_90 ,
F_50 ( V_69 [ V_80 ] ) ,
V_76 ) ;
F_56 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_30 ( & V_2 -> V_48 ) ;
F_57 ( V_11 ) ;
F_45 ( V_74 ) ;
return 0 ;
}
static int F_58 ( struct V_10 * V_11 , struct V_67 * V_68 )
{
return F_47 ( V_11 , V_68 ) ;
}
static int F_59 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_67 * V_91 = NULL ;
struct V_71 V_68 = {
. V_61 = V_2 -> V_61 ,
. V_6 = V_2 -> V_6 ,
. V_50 = V_2 -> V_46 . V_50 >> V_2 -> V_46 . V_88 ,
. V_55 = V_2 -> V_46 . V_55 >> V_2 -> V_46 . V_88 ,
. V_88 = V_2 -> V_46 . V_88 ,
. V_89 = V_2 -> V_46 . V_89 ,
. V_90 = V_2 -> V_46 . V_90 ,
} ;
V_91 = F_60 ( V_14 , V_92 ) ;
if ( V_91 == NULL )
goto V_93;
if ( F_61 ( V_14 , V_79 , sizeof( V_68 ) , & V_68 ) ||
F_62 ( V_14 , V_81 , V_2 -> V_46 . V_76 ) )
goto V_93;
return F_63 ( V_14 , V_91 ) ;
V_93:
F_64 ( V_14 , V_91 ) ;
return - V_94 ;
}
static int F_65 ( struct V_10 * V_11 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_97 V_98 = {
. V_99 = V_2 -> V_52 . V_59 + V_2 -> V_52 . V_56 ,
. V_100 = V_2 -> V_52 . V_60 + V_2 -> V_52 . V_57 ,
. V_62 = V_2 -> V_52 . V_62 ,
. V_65 = V_2 -> V_52 . V_65 ,
. V_53 = V_2 -> V_52 . V_53 ,
} ;
return F_66 ( V_96 , & V_98 , sizeof( V_98 ) ) ;
}
static void F_67 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_68 ( & V_2 -> V_32 ) ;
F_45 ( V_2 -> V_9 ) ;
}
static struct V_10 * F_69 ( struct V_10 * V_11 , unsigned long V_101 )
{
return NULL ;
}
static unsigned long F_70 ( struct V_10 * V_11 , T_2 V_18 )
{
return 0 ;
}
static void F_71 ( struct V_10 * V_2 , unsigned long V_102 )
{
}
static unsigned long F_72 ( struct V_10 * V_11 , unsigned long V_103 ,
T_2 V_18 )
{
return 0 ;
}
static struct V_29 T_3 * * F_73 ( struct V_10 * V_11 ,
unsigned long V_102 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( V_102 )
return NULL ;
return & V_2 -> V_32 ;
}
static int F_74 ( struct V_10 * V_11 , unsigned long V_102 ,
struct V_13 * V_14 , struct V_104 * V_105 )
{
V_105 -> V_106 |= F_22 ( V_102 ) ;
return 0 ;
}
static void F_75 ( struct V_10 * V_11 , struct V_107 * V_101 )
{
if ( ! V_101 -> V_108 ) {
if ( V_101 -> V_109 ( V_11 , 1 , V_101 ) < 0 ) {
V_101 -> V_108 = 1 ;
return;
}
V_101 -> V_110 ++ ;
}
}
static struct V_13 * F_76 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_4 F_77 ( void )
{
return F_78 ( & V_111 ) ;
}
static void T_5 F_79 ( void )
{
F_80 ( & V_111 ) ;
}
