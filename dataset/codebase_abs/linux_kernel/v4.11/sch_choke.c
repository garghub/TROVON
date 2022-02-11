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
static void F_6 ( struct V_10 * V_11 , unsigned int V_12 ,
struct V_13 * * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_15 = V_2 -> V_9 [ V_12 ] ;
V_2 -> V_9 [ V_12 ] = NULL ;
if ( V_12 == V_2 -> V_4 )
F_4 ( V_2 ) ;
if ( V_12 == V_2 -> V_3 )
F_5 ( V_2 ) ;
F_8 ( V_11 , V_15 ) ;
F_9 ( V_11 , 1 , F_10 ( V_15 ) ) ;
F_11 ( V_15 , V_11 , V_14 ) ;
-- V_11 -> V_2 . V_16 ;
}
static inline struct V_17 * V_17 ( const struct V_13 * V_15 )
{
F_12 ( V_15 , sizeof( struct V_17 ) ) ;
return (struct V_17 * ) F_13 ( V_15 ) -> V_18 ;
}
static inline void F_14 ( struct V_13 * V_15 , T_1 V_19 )
{
V_17 ( V_15 ) -> V_19 = V_19 ;
}
static T_1 F_15 ( const struct V_13 * V_15 )
{
return V_17 ( V_15 ) -> V_19 ;
}
static bool F_16 ( struct V_13 * V_20 ,
struct V_13 * V_21 )
{
struct V_22 V_23 ;
if ( V_20 -> V_24 != V_21 -> V_24 )
return false ;
if ( ! V_17 ( V_20 ) -> V_25 ) {
V_17 ( V_20 ) -> V_25 = 1 ;
F_17 ( V_20 , & V_23 , 0 ) ;
F_18 ( & V_17 ( V_20 ) -> V_26 , & V_23 ) ;
}
if ( ! V_17 ( V_21 ) -> V_25 ) {
V_17 ( V_21 ) -> V_25 = 1 ;
F_17 ( V_21 , & V_23 , 0 ) ;
F_18 ( & V_17 ( V_21 ) -> V_26 , & V_23 ) ;
}
return ! memcmp ( & V_17 ( V_20 ) -> V_26 ,
& V_17 ( V_21 ) -> V_26 ,
sizeof( V_17 ( V_20 ) -> V_26 ) ) ;
}
static bool F_19 ( struct V_13 * V_15 ,
struct V_10 * V_11 , int * V_27 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_20 ( V_2 -> V_33 ) ;
V_32 = F_21 ( V_15 , V_31 , & V_29 , false ) ;
if ( V_32 >= 0 ) {
#ifdef F_22
switch ( V_32 ) {
case V_34 :
case V_35 :
* V_27 = V_36 | V_37 ;
case V_38 :
return false ;
}
#endif
F_14 ( V_15 , F_23 ( V_29 . V_19 ) ) ;
return true ;
}
return false ;
}
static struct V_13 * F_24 ( const struct V_1 * V_2 ,
unsigned int * V_39 )
{
struct V_13 * V_15 ;
int V_40 = 3 ;
do {
* V_39 = ( V_2 -> V_4 + F_25 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_15 = V_2 -> V_9 [ * V_39 ] ;
if ( V_15 )
return V_15 ;
} while ( -- V_40 > 0 );
return V_2 -> V_9 [ * V_39 = V_2 -> V_4 ] ;
}
static bool F_26 ( const struct V_1 * V_2 ,
struct V_13 * V_41 ,
unsigned int * V_39 )
{
struct V_13 * V_42 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_42 = F_24 ( V_2 , V_39 ) ;
if ( F_27 ( V_2 -> V_33 ) )
return F_15 ( V_41 ) == F_15 ( V_42 ) ;
return F_16 ( V_42 , V_41 ) ;
}
static int F_28 ( struct V_13 * V_15 , struct V_10 * V_11 ,
struct V_13 * * V_14 )
{
int V_43 = V_36 | V_44 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_45 * V_46 = & V_2 -> V_47 ;
if ( F_27 ( V_2 -> V_33 ) ) {
if ( ! F_19 ( V_15 , V_11 , & V_43 ) )
goto V_48;
}
V_17 ( V_15 ) -> V_25 = 0 ;
V_2 -> V_49 . V_50 = F_29 ( V_46 , & V_2 -> V_49 , V_11 -> V_2 . V_16 ) ;
if ( F_30 ( & V_2 -> V_49 ) )
F_31 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_49 . V_50 <= V_46 -> V_51 )
V_2 -> V_49 . V_52 = - 1 ;
else {
unsigned int V_12 ;
if ( F_26 ( V_2 , V_15 , & V_12 ) ) {
V_2 -> V_53 . V_54 ++ ;
F_6 ( V_11 , V_12 , V_14 ) ;
goto V_55;
}
if ( V_2 -> V_49 . V_50 > V_46 -> V_56 ) {
V_2 -> V_49 . V_52 = - 1 ;
F_32 ( V_11 ) ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_33 ( V_15 ) ) {
V_2 -> V_53 . V_57 ++ ;
goto V_55;
}
V_2 -> V_53 . V_58 ++ ;
} else if ( ++ V_2 -> V_49 . V_52 ) {
if ( F_34 ( V_46 , & V_2 -> V_49 , V_2 -> V_49 . V_50 ) ) {
V_2 -> V_49 . V_52 = 0 ;
V_2 -> V_49 . V_59 = F_35 ( V_46 ) ;
F_32 ( V_11 ) ;
if ( ! F_2 ( V_2 ) || ! F_33 ( V_15 ) ) {
V_2 -> V_53 . V_60 ++ ;
goto V_55;
}
V_2 -> V_53 . V_61 ++ ;
}
} else
V_2 -> V_49 . V_59 = F_35 ( V_46 ) ;
}
if ( V_11 -> V_2 . V_16 < V_2 -> V_62 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_15 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_16 ;
F_36 ( V_11 , V_15 ) ;
return V_36 ;
}
V_2 -> V_53 . V_63 ++ ;
return F_11 ( V_15 , V_11 , V_14 ) ;
V_55:
F_11 ( V_15 , V_11 , V_14 ) ;
return V_64 ;
V_48:
if ( V_43 & V_44 )
F_37 ( V_11 ) ;
F_38 ( V_15 , V_14 ) ;
return V_43 ;
}
static struct V_13 * F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_15 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_30 ( & V_2 -> V_49 ) )
F_40 ( & V_2 -> V_49 ) ;
return NULL ;
}
V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_9 [ V_2 -> V_4 ] = NULL ;
F_4 ( V_2 ) ;
-- V_11 -> V_2 . V_16 ;
F_8 ( V_11 , V_15 ) ;
F_41 ( V_11 , V_15 ) ;
return V_15 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_15 )
continue;
F_43 ( V_15 , V_11 ) ;
}
V_11 -> V_2 . V_16 = 0 ;
V_11 -> V_65 . V_66 = 0 ;
memset ( V_2 -> V_9 , 0 , ( V_2 -> V_5 + 1 ) * sizeof( struct V_13 * ) ) ;
V_2 -> V_4 = V_2 -> V_3 = 0 ;
F_44 ( & V_2 -> V_49 ) ;
}
static void F_45 ( void * V_67 )
{
F_46 ( V_67 ) ;
}
static int F_47 ( struct V_10 * V_11 , struct V_68 * V_69 )
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
V_74 = F_48 ( V_70 , V_71 , V_69 , V_79 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_70 [ V_80 ] == NULL ||
V_70 [ V_81 ] == NULL )
return - V_78 ;
V_77 = V_70 [ V_82 ] ? F_49 ( V_70 [ V_82 ] ) : 0 ;
V_73 = F_50 ( V_70 [ V_80 ] ) ;
if ( V_73 -> V_62 > V_83 )
return - V_78 ;
V_76 = F_51 ( V_73 -> V_62 + 1 ) - 1 ;
if ( V_76 != V_2 -> V_5 ) {
struct V_13 * * V_84 ;
V_84 = F_52 ( V_76 + 1 , sizeof( struct V_13 * ) ,
V_85 | V_86 ) ;
if ( ! V_84 )
V_84 = F_53 ( ( V_76 + 1 ) * sizeof( struct V_13 * ) ) ;
if ( ! V_84 )
return - V_87 ;
F_54 ( V_11 ) ;
V_75 = V_2 -> V_9 ;
if ( V_75 ) {
unsigned int V_88 = V_11 -> V_2 . V_16 , V_3 = 0 ;
unsigned V_89 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_15 )
continue;
if ( V_3 < V_76 ) {
V_84 [ V_3 ++ ] = V_15 ;
continue;
}
V_89 += F_10 ( V_15 ) ;
F_8 ( V_11 , V_15 ) ;
-- V_11 -> V_2 . V_16 ;
F_43 ( V_15 , V_11 ) ;
}
F_9 ( V_11 , V_88 - V_11 -> V_2 . V_16 , V_89 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_76 ;
V_2 -> V_9 = V_84 ;
} else
F_54 ( V_11 ) ;
V_2 -> V_6 = V_73 -> V_6 ;
V_2 -> V_62 = V_73 -> V_62 ;
F_55 ( & V_2 -> V_47 , V_73 -> V_51 , V_73 -> V_56 , V_73 -> V_90 ,
V_73 -> V_91 , V_73 -> V_92 ,
F_50 ( V_70 [ V_81 ] ) ,
V_77 ) ;
F_56 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_31 ( & V_2 -> V_49 ) ;
F_57 ( V_11 ) ;
F_45 ( V_75 ) ;
return 0 ;
}
static int F_58 ( struct V_10 * V_11 , struct V_68 * V_69 )
{
return F_47 ( V_11 , V_69 ) ;
}
static int F_59 ( struct V_10 * V_11 , struct V_13 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_68 * V_93 = NULL ;
struct V_72 V_69 = {
. V_62 = V_2 -> V_62 ,
. V_6 = V_2 -> V_6 ,
. V_51 = V_2 -> V_47 . V_51 >> V_2 -> V_47 . V_90 ,
. V_56 = V_2 -> V_47 . V_56 >> V_2 -> V_47 . V_90 ,
. V_90 = V_2 -> V_47 . V_90 ,
. V_91 = V_2 -> V_47 . V_91 ,
. V_92 = V_2 -> V_47 . V_92 ,
} ;
V_93 = F_60 ( V_15 , V_94 ) ;
if ( V_93 == NULL )
goto V_95;
if ( F_61 ( V_15 , V_80 , sizeof( V_69 ) , & V_69 ) ||
F_62 ( V_15 , V_82 , V_2 -> V_47 . V_77 ) )
goto V_95;
return F_63 ( V_15 , V_93 ) ;
V_95:
F_64 ( V_15 , V_93 ) ;
return - V_96 ;
}
static int F_65 ( struct V_10 * V_11 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_99 V_100 = {
. V_101 = V_2 -> V_53 . V_60 + V_2 -> V_53 . V_57 ,
. V_102 = V_2 -> V_53 . V_61 + V_2 -> V_53 . V_58 ,
. V_63 = V_2 -> V_53 . V_63 ,
. V_103 = V_2 -> V_53 . V_103 ,
. V_54 = V_2 -> V_53 . V_54 ,
} ;
return F_66 ( V_98 , & V_100 , sizeof( V_100 ) ) ;
}
static void F_67 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_68 ( & V_2 -> V_33 ) ;
F_45 ( V_2 -> V_9 ) ;
}
static struct V_13 * F_69 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_3 F_70 ( void )
{
return F_71 ( & V_104 ) ;
}
static void T_4 F_72 ( void )
{
F_73 ( & V_104 ) ;
}
