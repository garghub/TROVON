static inline void *
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return ( void * ) ( ( char * ) V_2 -> V_4 + V_3 * V_2 -> V_5 ) ;
}
static inline bool
F_2 ( const struct V_1 * V_2 , T_1 V_3 )
{
const struct V_6 * V_7 = F_1 ( V_2 , V_3 ) ;
return F_3 ( V_7 -> V_8 ) ;
}
static inline bool
F_4 ( const struct V_1 * V_2 , T_1 V_3 )
{
const struct V_6 * V_7 = F_1 ( V_2 , V_3 ) ;
return F_5 ( V_7 -> V_8 ) ;
}
static inline int
F_6 ( const struct V_6 * V_7 )
{
return V_7 -> V_9 == V_10 ||
( V_7 -> V_9 == V_11 &&
! F_5 ( V_7 -> V_8 ) ) ;
}
static int
F_7 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
const struct V_17 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
return - V_18 ;
case V_11 :
return V_15 -> V_19 == NULL ||
F_8 ( V_15 -> V_19 , V_7 -> V_19 ) == 0 ;
}
return 0 ;
}
static int
F_9 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
struct V_17 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
if ( ! V_15 -> V_19 )
return - V_20 ;
memcpy ( V_7 -> V_19 , V_15 -> V_19 , V_21 ) ;
V_7 -> V_9 = V_11 ;
break;
case V_11 :
return - V_20 ;
case V_22 :
if ( V_15 -> V_19 ) {
memcpy ( V_7 -> V_19 , V_15 -> V_19 , V_21 ) ;
V_7 -> V_9 = V_11 ;
} else
V_7 -> V_9 = V_10 ;
}
return 0 ;
}
static int
F_10 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
struct V_17 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
if ( V_7 -> V_9 == V_22 )
return - V_20 ;
V_7 -> V_9 = V_22 ;
return 0 ;
}
static int
F_11 ( const struct V_12 * V_13 ,
struct V_23 * V_24 , struct V_25 * V_26 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_17 * V_7 ;
struct V_27 * V_28 , * V_29 ;
T_1 V_3 , V_30 = V_26 -> args [ 2 ] ;
T_1 V_31 = V_2 -> V_32 - V_2 -> V_33 ;
V_28 = F_12 ( V_24 , V_34 ) ;
if ( ! V_28 )
return - V_35 ;
for (; V_26 -> args [ 2 ] <= V_31 ; V_26 -> args [ 2 ] ++ ) {
V_3 = V_26 -> args [ 2 ] ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 -> V_9 == V_22 )
continue;
V_29 = F_12 ( V_24 , V_36 ) ;
if ( ! V_29 ) {
if ( V_3 == V_30 ) {
F_13 ( V_24 , V_28 ) ;
return - V_35 ;
} else
goto V_37;
}
F_14 ( V_24 , V_38 ,
F_15 ( V_2 -> V_33 + V_3 ) ) ;
if ( V_7 -> V_9 == V_11 )
F_16 ( V_24 , V_39 , V_21 ,
V_7 -> V_19 ) ;
F_17 ( V_24 , V_29 ) ;
}
F_17 ( V_24 , V_28 ) ;
V_26 -> args [ 2 ] = 0 ;
return 0 ;
V_37:
F_13 ( V_24 , V_29 ) ;
F_17 ( V_24 , V_28 ) ;
if ( F_18 ( V_3 == V_30 ) ) {
V_26 -> args [ 2 ] = 0 ;
return - V_35 ;
}
return 0 ;
}
static int
F_19 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
const struct V_17 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
return - V_18 ;
case V_11 :
return ( V_15 -> V_19 == NULL ||
F_8 ( V_15 -> V_19 , V_7 -> V_19 ) == 0 ) &&
! F_4 ( V_2 , V_15 -> V_3 ) ;
}
return 0 ;
}
static int
F_20 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
struct V_6 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
if ( ! V_15 -> V_19 )
return - V_20 ;
memcpy ( V_7 -> V_19 , V_15 -> V_19 , V_21 ) ;
V_7 -> V_9 = V_11 ;
if ( V_8 == V_2 -> V_8 )
V_8 = V_7 -> V_8 ;
V_7 -> V_8 = F_21 ( V_8 ) ;
break;
case V_11 :
if ( ! F_4 ( V_2 , V_15 -> V_3 ) )
return - V_20 ;
case V_22 :
if ( V_15 -> V_19 ) {
memcpy ( V_7 -> V_19 , V_15 -> V_19 , V_21 ) ;
V_7 -> V_9 = V_11 ;
} else
V_7 -> V_9 = V_10 ;
V_7 -> V_8 = V_15 -> V_19 ? F_21 ( V_8 )
: V_8 ;
break;
}
return 0 ;
}
static int
F_22 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_16 * V_15 = V_14 ;
struct V_6 * V_7 = F_1 ( V_2 , V_15 -> V_3 ) ;
if ( V_7 -> V_9 == V_22 || F_4 ( V_2 , V_15 -> V_3 ) )
return - V_20 ;
V_7 -> V_9 = V_22 ;
return 0 ;
}
static int
F_23 ( const struct V_12 * V_13 ,
struct V_23 * V_24 , struct V_25 * V_26 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
const struct V_6 * V_7 ;
struct V_27 * V_28 , * V_29 ;
T_1 V_3 , V_30 = V_26 -> args [ 2 ] ;
T_1 V_8 , V_31 = V_2 -> V_32 - V_2 -> V_33 ;
V_28 = F_12 ( V_24 , V_34 ) ;
if ( ! V_28 )
return - V_35 ;
for (; V_26 -> args [ 2 ] <= V_31 ; V_26 -> args [ 2 ] ++ ) {
V_3 = V_26 -> args [ 2 ] ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( ! F_6 ( V_7 ) )
continue;
V_29 = F_12 ( V_24 , V_36 ) ;
if ( ! V_29 ) {
if ( V_3 == V_30 ) {
F_13 ( V_24 , V_28 ) ;
return - V_35 ;
} else
goto V_37;
}
F_14 ( V_24 , V_38 ,
F_15 ( V_2 -> V_33 + V_3 ) ) ;
if ( V_7 -> V_9 == V_11 )
F_16 ( V_24 , V_39 , V_21 ,
V_7 -> V_19 ) ;
V_8 = V_7 -> V_9 == V_10 ? V_7 -> V_8
: F_24 ( V_7 -> V_8 ) ;
F_25 ( V_24 , V_40 , F_15 ( V_8 ) ) ;
F_17 ( V_24 , V_29 ) ;
}
F_17 ( V_24 , V_28 ) ;
V_26 -> args [ 2 ] = 0 ;
return 0 ;
V_37:
F_13 ( V_24 , V_29 ) ;
F_17 ( V_24 , V_28 ) ;
return - V_35 ;
}
static int
F_26 ( struct V_12 * V_13 , const struct V_23 * V_24 ,
enum V_41 V_42 , T_2 V_43 , T_2 V_44 , T_2 V_45 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
T_3 V_46 = V_13 -> V_47 -> V_42 [ V_42 ] ;
struct V_16 V_15 ;
if ( ! ( V_45 & V_48 ) )
return 0 ;
V_15 . V_3 = F_27 ( F_28 ( V_24 , V_45 & V_49 ) ) ;
if ( V_15 . V_3 < V_2 -> V_33 || V_15 . V_3 > V_2 -> V_32 )
return - V_50 ;
if ( F_29 ( V_24 ) < V_24 -> V_51 ||
( F_29 ( V_24 ) + V_52 ) > V_24 -> V_15 )
return - V_53 ;
V_15 . V_3 -= V_2 -> V_33 ;
V_15 . V_19 = F_30 ( V_24 ) -> V_54 ;
return V_46 ( V_13 , & V_15 , V_2 -> V_8 ) ;
}
static int
F_31 ( struct V_12 * V_13 , struct V_27 * V_55 [] ,
enum V_41 V_42 , T_1 * V_56 , T_1 V_45 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
T_3 V_46 = V_13 -> V_47 -> V_42 [ V_42 ] ;
struct V_16 V_15 ;
T_1 V_8 = V_2 -> V_8 ;
int V_57 = 0 ;
if ( F_18 ( ! V_55 [ V_38 ] ||
! F_32 ( V_55 , V_40 ) ) )
return - V_58 ;
if ( V_55 [ V_59 ] )
* V_56 = F_33 ( V_55 [ V_59 ] ) ;
V_57 = F_34 ( V_55 [ V_38 ] , & V_15 . V_3 ) ;
if ( V_57 )
return V_57 ;
if ( V_15 . V_3 < V_2 -> V_33 || V_15 . V_3 > V_2 -> V_32 )
return - V_50 ;
if ( V_55 [ V_39 ] )
V_15 . V_19 = F_35 ( V_55 [ V_39 ] ) ;
else
V_15 . V_19 = NULL ;
if ( V_55 [ V_40 ] ) {
if ( ! F_36 ( V_2 -> V_8 ) )
return - V_60 ;
V_8 = F_37 ( V_55 [ V_40 ] ) ;
}
V_15 . V_3 -= V_2 -> V_33 ;
V_57 = V_46 ( V_13 , & V_15 , V_8 ) ;
return F_38 ( V_57 , V_45 ) ? 0 : V_57 ;
}
static void
F_39 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
if ( F_36 ( V_2 -> V_8 ) )
F_40 ( & V_2 -> V_61 ) ;
F_41 ( V_2 -> V_4 ) ;
F_42 ( V_2 ) ;
V_13 -> V_15 = NULL ;
}
static void
F_43 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
memset ( V_2 -> V_4 , 0 ,
( V_2 -> V_32 - V_2 -> V_33 + 1 ) * V_2 -> V_5 ) ;
}
static int
F_44 ( struct V_12 * V_13 , struct V_23 * V_24 )
{
const struct V_1 * V_2 = V_13 -> V_15 ;
struct V_27 * V_29 ;
V_29 = F_12 ( V_24 , V_36 ) ;
if ( ! V_29 )
goto V_37;
F_14 ( V_24 , V_38 , F_15 ( V_2 -> V_33 ) ) ;
F_14 ( V_24 , V_62 , F_15 ( V_2 -> V_32 ) ) ;
F_25 ( V_24 , V_63 , F_15 ( V_13 -> V_64 - 1 ) ) ;
F_25 ( V_24 , V_65 ,
F_15 ( sizeof( * V_2 )
+ ( V_2 -> V_32 - V_2 -> V_33 + 1 ) * V_2 -> V_5 ) ) ;
if ( F_36 ( V_2 -> V_8 ) )
F_25 ( V_24 , V_40 , F_15 ( V_2 -> V_8 ) ) ;
F_17 ( V_24 , V_29 ) ;
return 0 ;
V_37:
return - V_35 ;
}
static bool
F_45 ( const struct V_12 * V_66 , const struct V_12 * V_67 )
{
const struct V_1 * V_68 = V_66 -> V_15 ;
const struct V_1 * V_69 = V_67 -> V_15 ;
return V_68 -> V_33 == V_69 -> V_33 &&
V_68 -> V_32 == V_69 -> V_32 &&
V_68 -> V_8 == V_69 -> V_8 ;
}
static void
F_46 ( unsigned long V_70 )
{
struct V_12 * V_13 = (struct V_12 * ) V_70 ;
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_6 * V_7 ;
T_1 V_3 , V_31 = V_2 -> V_32 - V_2 -> V_33 ;
F_47 ( & V_13 -> V_71 ) ;
for ( V_3 = 0 ; V_3 <= V_31 ; V_3 ++ ) {
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 -> V_9 == V_11 &&
F_5 ( V_7 -> V_8 ) )
V_7 -> V_9 = V_22 ;
}
F_48 ( & V_13 -> V_71 ) ;
V_2 -> V_61 . V_72 = V_73 + F_49 ( V_2 -> V_8 ) * V_74 ;
F_50 ( & V_2 -> V_61 ) ;
}
static void
F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
F_52 ( & V_2 -> V_61 ) ;
V_2 -> V_61 . V_15 = ( unsigned long ) V_13 ;
V_2 -> V_61 . V_75 = F_46 ;
V_2 -> V_61 . V_72 = V_73 + F_49 ( V_2 -> V_8 ) * V_74 ;
F_50 ( & V_2 -> V_61 ) ;
}
static bool
F_53 ( struct V_12 * V_13 , struct V_1 * V_2 ,
T_1 V_33 , T_1 V_32 )
{
V_2 -> V_4 = F_54 ( ( V_32 - V_33 + 1 ) * V_2 -> V_5 ) ;
if ( ! V_2 -> V_4 )
return false ;
V_2 -> V_33 = V_33 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_8 = V_76 ;
V_13 -> V_15 = V_2 ;
V_13 -> V_77 = V_78 ;
return true ;
}
static int
F_55 ( struct V_12 * V_13 , struct V_27 * V_55 [] ,
T_1 V_45 )
{
T_1 V_33 , V_32 , V_79 ;
struct V_1 * V_2 ;
int V_57 ;
if ( F_18 ( ! V_55 [ V_38 ] ||
! F_32 ( V_55 , V_40 ) ) )
return - V_58 ;
V_57 = F_34 ( V_55 [ V_38 ] , & V_33 ) ;
if ( V_57 )
return V_57 ;
if ( V_55 [ V_62 ] ) {
V_57 = F_34 ( V_55 [ V_62 ] , & V_32 ) ;
if ( V_57 )
return V_57 ;
if ( V_33 > V_32 ) {
T_1 V_80 = V_33 ;
V_33 = V_32 ;
V_32 = V_80 ;
}
} else if ( V_55 [ V_81 ] ) {
T_2 V_82 = F_56 ( V_55 [ V_81 ] ) ;
if ( V_82 >= 32 )
return - V_83 ;
V_32 = V_33 | ~ F_57 ( V_82 ) ;
} else
return - V_58 ;
V_79 = V_32 - V_33 + 1 ;
if ( V_79 > V_84 + 1 )
return - V_85 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_86 ) ;
if ( ! V_2 )
return - V_87 ;
if ( V_55 [ V_40 ] ) {
V_2 -> V_5 = sizeof( struct V_6 ) ;
if ( ! F_53 ( V_13 , V_2 , V_33 , V_32 ) ) {
F_42 ( V_2 ) ;
return - V_87 ;
}
V_2 -> V_8 = F_37 ( V_55 [ V_40 ] ) ;
V_13 -> V_47 = & V_88 ;
F_51 ( V_13 ) ;
} else {
V_2 -> V_5 = sizeof( struct V_17 ) ;
if ( ! F_53 ( V_13 , V_2 , V_33 , V_32 ) ) {
F_42 ( V_2 ) ;
return - V_87 ;
}
V_13 -> V_47 = & V_1 ;
}
return 0 ;
}
static int T_4
F_59 ( void )
{
return F_60 ( & V_89 ) ;
}
static void T_5
F_61 ( void )
{
F_62 ( & V_89 ) ;
}
