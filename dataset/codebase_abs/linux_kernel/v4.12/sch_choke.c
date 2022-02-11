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
static bool F_15 ( struct V_13 * V_20 ,
struct V_13 * V_21 )
{
struct V_22 V_23 ;
if ( V_20 -> V_24 != V_21 -> V_24 )
return false ;
if ( ! V_17 ( V_20 ) -> V_25 ) {
V_17 ( V_20 ) -> V_25 = 1 ;
F_16 ( V_20 , & V_23 , 0 ) ;
F_17 ( & V_17 ( V_20 ) -> V_26 , & V_23 ) ;
}
if ( ! V_17 ( V_21 ) -> V_25 ) {
V_17 ( V_21 ) -> V_25 = 1 ;
F_16 ( V_21 , & V_23 , 0 ) ;
F_17 ( & V_17 ( V_21 ) -> V_26 , & V_23 ) ;
}
return ! memcmp ( & V_17 ( V_20 ) -> V_26 ,
& V_17 ( V_21 ) -> V_26 ,
sizeof( V_17 ( V_20 ) -> V_26 ) ) ;
}
static struct V_13 * F_18 ( const struct V_1 * V_2 ,
unsigned int * V_27 )
{
struct V_13 * V_15 ;
int V_28 = 3 ;
do {
* V_27 = ( V_2 -> V_4 + F_19 ( F_1 ( V_2 ) ) ) & V_2 -> V_5 ;
V_15 = V_2 -> V_9 [ * V_27 ] ;
if ( V_15 )
return V_15 ;
} while ( -- V_28 > 0 );
return V_2 -> V_9 [ * V_27 = V_2 -> V_4 ] ;
}
static bool F_20 ( const struct V_1 * V_2 ,
struct V_13 * V_29 ,
unsigned int * V_27 )
{
struct V_13 * V_30 ;
if ( V_2 -> V_4 == V_2 -> V_3 )
return false ;
V_30 = F_18 ( V_2 , V_27 ) ;
return F_15 ( V_30 , V_29 ) ;
}
static int F_21 ( struct V_13 * V_15 , struct V_10 * V_11 ,
struct V_13 * * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_31 * V_32 = & V_2 -> V_33 ;
V_17 ( V_15 ) -> V_25 = 0 ;
V_2 -> V_34 . V_35 = F_22 ( V_32 , & V_2 -> V_34 , V_11 -> V_2 . V_16 ) ;
if ( F_23 ( & V_2 -> V_34 ) )
F_24 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_34 . V_35 <= V_32 -> V_36 )
V_2 -> V_34 . V_37 = - 1 ;
else {
unsigned int V_12 ;
if ( F_20 ( V_2 , V_15 , & V_12 ) ) {
V_2 -> V_38 . V_39 ++ ;
F_6 ( V_11 , V_12 , V_14 ) ;
goto V_40;
}
if ( V_2 -> V_34 . V_35 > V_32 -> V_41 ) {
V_2 -> V_34 . V_37 = - 1 ;
F_25 ( V_11 ) ;
if ( F_3 ( V_2 ) || ! F_2 ( V_2 ) ||
! F_26 ( V_15 ) ) {
V_2 -> V_38 . V_42 ++ ;
goto V_40;
}
V_2 -> V_38 . V_43 ++ ;
} else if ( ++ V_2 -> V_34 . V_37 ) {
if ( F_27 ( V_32 , & V_2 -> V_34 , V_2 -> V_34 . V_35 ) ) {
V_2 -> V_34 . V_37 = 0 ;
V_2 -> V_34 . V_44 = F_28 ( V_32 ) ;
F_25 ( V_11 ) ;
if ( ! F_2 ( V_2 ) || ! F_26 ( V_15 ) ) {
V_2 -> V_38 . V_45 ++ ;
goto V_40;
}
V_2 -> V_38 . V_46 ++ ;
}
} else
V_2 -> V_34 . V_44 = F_28 ( V_32 ) ;
}
if ( V_11 -> V_2 . V_16 < V_2 -> V_47 ) {
V_2 -> V_9 [ V_2 -> V_3 ] = V_15 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) & V_2 -> V_5 ;
++ V_11 -> V_2 . V_16 ;
F_29 ( V_11 , V_15 ) ;
return V_48 ;
}
V_2 -> V_38 . V_49 ++ ;
return F_11 ( V_15 , V_11 , V_14 ) ;
V_40:
F_11 ( V_15 , V_11 , V_14 ) ;
return V_50 ;
}
static struct V_13 * F_30 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_13 * V_15 ;
if ( V_2 -> V_4 == V_2 -> V_3 ) {
if ( ! F_23 ( & V_2 -> V_34 ) )
F_31 ( & V_2 -> V_34 ) ;
return NULL ;
}
V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_9 [ V_2 -> V_4 ] = NULL ;
F_4 ( V_2 ) ;
-- V_11 -> V_2 . V_16 ;
F_8 ( V_11 , V_15 ) ;
F_32 ( V_11 , V_15 ) ;
return V_15 ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_15 )
continue;
F_34 ( V_15 , V_11 ) ;
}
V_11 -> V_2 . V_16 = 0 ;
V_11 -> V_51 . V_52 = 0 ;
memset ( V_2 -> V_9 , 0 , ( V_2 -> V_5 + 1 ) * sizeof( struct V_13 * ) ) ;
V_2 -> V_4 = V_2 -> V_3 = 0 ;
F_35 ( & V_2 -> V_34 ) ;
}
static void F_36 ( void * V_53 )
{
F_37 ( V_53 ) ;
}
static int F_38 ( struct V_10 * V_11 , struct V_54 * V_55 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_54 * V_56 [ V_57 + 1 ] ;
const struct V_58 * V_59 ;
int V_60 ;
struct V_13 * * V_61 = NULL ;
unsigned int V_62 ;
T_2 V_63 ;
if ( V_55 == NULL )
return - V_64 ;
V_60 = F_39 ( V_56 , V_57 , V_55 , V_65 , NULL ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_56 [ V_66 ] == NULL ||
V_56 [ V_67 ] == NULL )
return - V_64 ;
V_63 = V_56 [ V_68 ] ? F_40 ( V_56 [ V_68 ] ) : 0 ;
V_59 = F_41 ( V_56 [ V_66 ] ) ;
if ( V_59 -> V_47 > V_69 )
return - V_64 ;
V_62 = F_42 ( V_59 -> V_47 + 1 ) - 1 ;
if ( V_62 != V_2 -> V_5 ) {
struct V_13 * * V_70 ;
V_70 = F_43 ( ( V_62 + 1 ) , sizeof( struct V_13 * ) , V_71 | V_72 ) ;
if ( ! V_70 )
return - V_73 ;
F_44 ( V_11 ) ;
V_61 = V_2 -> V_9 ;
if ( V_61 ) {
unsigned int V_74 = V_11 -> V_2 . V_16 , V_3 = 0 ;
unsigned V_75 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_3 ) {
struct V_13 * V_15 = V_2 -> V_9 [ V_2 -> V_4 ] ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) & V_2 -> V_5 ;
if ( ! V_15 )
continue;
if ( V_3 < V_62 ) {
V_70 [ V_3 ++ ] = V_15 ;
continue;
}
V_75 += F_10 ( V_15 ) ;
F_8 ( V_11 , V_15 ) ;
-- V_11 -> V_2 . V_16 ;
F_34 ( V_15 , V_11 ) ;
}
F_9 ( V_11 , V_74 - V_11 -> V_2 . V_16 , V_75 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_3 ;
}
V_2 -> V_5 = V_62 ;
V_2 -> V_9 = V_70 ;
} else
F_44 ( V_11 ) ;
V_2 -> V_6 = V_59 -> V_6 ;
V_2 -> V_47 = V_59 -> V_47 ;
F_45 ( & V_2 -> V_33 , V_59 -> V_36 , V_59 -> V_41 , V_59 -> V_76 ,
V_59 -> V_77 , V_59 -> V_78 ,
F_41 ( V_56 [ V_67 ] ) ,
V_63 ) ;
F_46 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_4 == V_2 -> V_3 )
F_24 ( & V_2 -> V_34 ) ;
F_47 ( V_11 ) ;
F_36 ( V_61 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 , struct V_54 * V_55 )
{
return F_38 ( V_11 , V_55 ) ;
}
static int F_49 ( struct V_10 * V_11 , struct V_13 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_54 * V_79 = NULL ;
struct V_58 V_55 = {
. V_47 = V_2 -> V_47 ,
. V_6 = V_2 -> V_6 ,
. V_36 = V_2 -> V_33 . V_36 >> V_2 -> V_33 . V_76 ,
. V_41 = V_2 -> V_33 . V_41 >> V_2 -> V_33 . V_76 ,
. V_76 = V_2 -> V_33 . V_76 ,
. V_77 = V_2 -> V_33 . V_77 ,
. V_78 = V_2 -> V_33 . V_78 ,
} ;
V_79 = F_50 ( V_15 , V_80 ) ;
if ( V_79 == NULL )
goto V_81;
if ( F_51 ( V_15 , V_66 , sizeof( V_55 ) , & V_55 ) ||
F_52 ( V_15 , V_68 , V_2 -> V_33 . V_63 ) )
goto V_81;
return F_53 ( V_15 , V_79 ) ;
V_81:
F_54 ( V_15 , V_79 ) ;
return - V_82 ;
}
static int F_55 ( struct V_10 * V_11 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_85 V_86 = {
. V_87 = V_2 -> V_38 . V_45 + V_2 -> V_38 . V_42 ,
. V_88 = V_2 -> V_38 . V_46 + V_2 -> V_38 . V_43 ,
. V_49 = V_2 -> V_38 . V_49 ,
. V_89 = V_2 -> V_38 . V_89 ,
. V_39 = V_2 -> V_38 . V_39 ,
} ;
return F_56 ( V_84 , & V_86 , sizeof( V_86 ) ) ;
}
static void F_57 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_36 ( V_2 -> V_9 ) ;
}
static struct V_13 * F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return ( V_2 -> V_4 != V_2 -> V_3 ) ? V_2 -> V_9 [ V_2 -> V_4 ] : NULL ;
}
static int T_3 F_59 ( void )
{
return F_60 ( & V_90 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_90 ) ;
}
