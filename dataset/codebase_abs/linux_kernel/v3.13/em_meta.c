static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 . V_4 ) ;
}
static inline unsigned long F_5 ( int V_5 )
{
int V_6 = V_5 + ( V_7 / 200 ) ;
int V_8 = ( ( V_6 & ( V_7 - 1 ) ) * 100 ) >> V_9 ;
return ( ( V_6 >> V_9 ) * 100 ) + V_8 ;
}
static inline int F_6 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( F_7 ( V_11 == NULL ) )
return - 1 ;
V_13 -> V_14 = V_11 -> V_15 ;
return 0 ;
}
static inline int F_8 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( F_7 ( V_11 == NULL ) )
return - 1 ;
V_13 -> V_14 = ( unsigned long ) V_11 -> V_16 ;
V_13 -> V_17 = strlen ( V_11 -> V_16 ) ;
return 0 ;
}
static inline struct V_18 * V_18 ( struct V_1 * V_19 )
{
return & V_20 [ F_3 ( V_19 ) ] [ F_1 ( V_19 ) ] ;
}
static int F_9 ( struct V_12 * V_21 , struct V_12 * V_22 )
{
int V_23 = V_21 -> V_17 - V_22 -> V_17 ;
if ( V_23 == 0 )
V_23 = memcmp ( ( void * ) V_21 -> V_14 , ( void * ) V_22 -> V_14 , V_21 -> V_17 ) ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_13 , struct V_24 * V_25 )
{
int V_17 = F_11 ( V_25 ) ;
V_13 -> V_19 = ( unsigned long ) F_12 ( F_13 ( V_25 ) , V_17 , V_26 ) ;
if ( V_13 -> V_19 == 0UL )
return - V_27 ;
V_13 -> V_17 = V_17 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( ( void * ) V_2 -> V_19 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_28 = V_2 -> V_3 . V_28 ;
if ( V_28 && V_28 < V_13 -> V_17 )
V_13 -> V_17 -= V_28 ;
}
static int F_17 ( struct V_29 * V_30 , struct V_1 * V_2 , int V_31 )
{
if ( V_2 -> V_19 && V_2 -> V_17 &&
F_18 ( V_30 , V_31 , V_2 -> V_17 , ( void * ) V_2 -> V_19 ) )
goto V_32;
return 0 ;
V_32:
return - 1 ;
}
static int F_19 ( struct V_12 * V_21 , struct V_12 * V_22 )
{
if ( F_7 ( V_21 -> V_14 == V_22 -> V_14 ) )
return 0 ;
else if ( V_21 -> V_14 < V_22 -> V_14 )
return - 1 ;
else
return 1 ;
}
static int F_20 ( struct V_1 * V_13 , struct V_24 * V_25 )
{
if ( F_11 ( V_25 ) >= sizeof( unsigned long ) ) {
V_13 -> V_19 = * ( unsigned long * ) F_13 ( V_25 ) ;
V_13 -> V_17 = sizeof( unsigned long ) ;
} else if ( F_11 ( V_25 ) == sizeof( V_33 ) ) {
V_13 -> V_19 = F_21 ( V_25 ) ;
V_13 -> V_17 = sizeof( V_33 ) ;
} else
return - V_34 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( V_2 -> V_3 . V_28 )
V_13 -> V_14 >>= V_2 -> V_3 . V_28 ;
if ( V_2 -> V_19 )
V_13 -> V_14 &= V_2 -> V_19 ;
}
static int F_23 ( struct V_29 * V_30 , struct V_1 * V_2 , int V_31 )
{
if ( V_2 -> V_17 == sizeof( unsigned long ) ) {
if ( F_18 ( V_30 , V_31 , sizeof( unsigned long ) , & V_2 -> V_19 ) )
goto V_32;
} else if ( V_2 -> V_17 == sizeof( V_33 ) ) {
if ( F_24 ( V_30 , V_31 , V_2 -> V_19 ) )
goto V_32;
}
return 0 ;
V_32:
return - 1 ;
}
static inline struct V_35 * V_35 ( struct V_1 * V_2 )
{
return & V_36 [ F_3 ( V_2 ) ] ;
}
static int F_25 ( struct V_29 * V_30 , struct V_37 * V_38 ,
struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_39 = 0 ;
if ( F_1 ( V_2 ) == V_40 ) {
V_13 -> V_14 = V_2 -> V_19 ;
V_13 -> V_17 = V_2 -> V_17 ;
return 0 ;
}
V_18 ( V_2 ) -> F_26 ( V_30 , V_38 , V_2 , V_13 , & V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_35 ( V_2 ) -> V_41 )
V_35 ( V_2 ) -> V_41 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 , struct V_42 * V_43 ,
struct V_37 * V_38 )
{
int V_23 ;
struct V_44 * V_45 = (struct V_44 * ) V_43 -> V_46 ;
struct V_12 V_47 , V_48 ;
if ( F_25 ( V_30 , V_38 , & V_45 -> V_49 , & V_47 ) < 0 ||
F_25 ( V_30 , V_38 , & V_45 -> V_50 , & V_48 ) < 0 )
return 0 ;
V_23 = V_35 ( & V_45 -> V_49 ) -> F_28 ( & V_47 , & V_48 ) ;
switch ( V_45 -> V_49 . V_3 . V_51 ) {
case V_52 :
return ! V_23 ;
case V_53 :
return V_23 < 0 ;
case V_54 :
return V_23 > 0 ;
}
return 0 ;
}
static void F_29 ( struct V_44 * V_45 )
{
if ( V_45 ) {
struct V_35 * V_55 = V_35 ( & V_45 -> V_49 ) ;
if ( V_55 && V_55 -> V_56 ) {
V_55 -> V_56 ( & V_45 -> V_49 ) ;
V_55 -> V_56 ( & V_45 -> V_50 ) ;
}
}
F_15 ( V_45 ) ;
}
static inline int F_30 ( struct V_1 * V_13 , struct V_24 * V_25 )
{
if ( V_25 ) {
if ( F_11 ( V_25 ) == 0 )
return - V_34 ;
return V_35 ( V_13 ) -> F_31 ( V_13 , V_25 ) ;
}
return 0 ;
}
static inline int F_32 ( struct V_1 * V_19 )
{
return ! F_1 ( V_19 ) || V_18 ( V_19 ) -> F_26 ;
}
static int F_33 ( struct V_57 * V_58 , void * V_46 , int V_17 ,
struct V_42 * V_43 )
{
int V_39 ;
struct V_24 * V_59 [ V_60 + 1 ] ;
struct V_61 * V_3 ;
struct V_44 * V_45 = NULL ;
V_39 = F_34 ( V_59 , V_60 , V_46 , V_17 , V_62 ) ;
if ( V_39 < 0 )
goto V_63;
V_39 = - V_34 ;
if ( V_59 [ V_64 ] == NULL )
goto V_63;
V_3 = F_13 ( V_59 [ V_64 ] ) ;
if ( F_4 ( V_3 -> V_65 . V_4 ) != F_4 ( V_3 -> V_66 . V_4 ) ||
F_4 ( V_3 -> V_65 . V_4 ) > V_67 ||
F_2 ( V_3 -> V_65 . V_4 ) > V_68 ||
F_2 ( V_3 -> V_66 . V_4 ) > V_68 )
goto V_63;
V_45 = F_35 ( sizeof( * V_45 ) , V_26 ) ;
if ( V_45 == NULL ) {
V_39 = - V_27 ;
goto V_63;
}
memcpy ( & V_45 -> V_49 . V_3 , & V_3 -> V_65 , sizeof( V_3 -> V_65 ) ) ;
memcpy ( & V_45 -> V_50 . V_3 , & V_3 -> V_66 , sizeof( V_3 -> V_66 ) ) ;
if ( ! F_32 ( & V_45 -> V_49 ) ||
! F_32 ( & V_45 -> V_50 ) ) {
V_39 = - V_69 ;
goto V_63;
}
if ( F_30 ( & V_45 -> V_49 , V_59 [ V_70 ] ) < 0 ||
F_30 ( & V_45 -> V_50 , V_59 [ V_71 ] ) < 0 )
goto V_63;
V_43 -> V_72 = sizeof( * V_45 ) ;
V_43 -> V_46 = ( unsigned long ) V_45 ;
V_39 = 0 ;
V_63:
if ( V_39 && V_45 )
F_29 ( V_45 ) ;
return V_39 ;
}
static void F_36 ( struct V_57 * V_58 , struct V_42 * V_43 )
{
if ( V_43 )
F_29 ( (struct V_44 * ) V_43 -> V_46 ) ;
}
static int F_37 ( struct V_29 * V_30 , struct V_42 * V_73 )
{
struct V_44 * V_45 = (struct V_44 * ) V_73 -> V_46 ;
struct V_61 V_3 ;
struct V_35 * V_55 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
memcpy ( & V_3 . V_65 , & V_45 -> V_49 . V_3 , sizeof( V_3 . V_65 ) ) ;
memcpy ( & V_3 . V_66 , & V_45 -> V_50 . V_3 , sizeof( V_3 . V_66 ) ) ;
if ( F_18 ( V_30 , V_64 , sizeof( V_3 ) , & V_3 ) )
goto V_32;
V_55 = V_35 ( & V_45 -> V_49 ) ;
if ( V_55 -> V_74 ( V_30 , & V_45 -> V_49 , V_70 ) < 0 ||
V_55 -> V_74 ( V_30 , & V_45 -> V_50 , V_71 ) < 0 )
goto V_32;
return 0 ;
V_32:
return - 1 ;
}
static int T_1 F_38 ( void )
{
return F_39 ( & V_75 ) ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_75 ) ;
}
