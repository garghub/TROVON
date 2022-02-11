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
F_7 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
const struct V_18 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
return - V_19 ;
case V_11 :
return V_16 -> V_20 == NULL ||
F_8 ( V_16 -> V_20 , V_7 -> V_20 ) ;
}
return 0 ;
}
static int
F_9 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
struct V_18 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
if ( ! V_16 -> V_20 )
return - V_21 ;
memcpy ( V_7 -> V_20 , V_16 -> V_20 , V_22 ) ;
V_7 -> V_9 = V_11 ;
break;
case V_11 :
return - V_21 ;
case V_23 :
if ( V_16 -> V_20 ) {
memcpy ( V_7 -> V_20 , V_16 -> V_20 , V_22 ) ;
V_7 -> V_9 = V_11 ;
} else
V_7 -> V_9 = V_10 ;
}
return 0 ;
}
static int
F_10 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
struct V_18 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
if ( V_7 -> V_9 == V_23 )
return - V_21 ;
V_7 -> V_9 = V_23 ;
return 0 ;
}
static int
F_11 ( const struct V_12 * V_13 ,
struct V_24 * V_25 , struct V_26 * V_27 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_18 * V_7 ;
struct V_28 * V_29 , * V_30 ;
T_1 V_3 , V_31 = V_27 -> args [ 2 ] ;
T_1 V_32 = V_2 -> V_33 - V_2 -> V_34 ;
V_29 = F_12 ( V_25 , V_35 ) ;
if ( ! V_29 )
return - V_36 ;
for (; V_27 -> args [ 2 ] <= V_32 ; V_27 -> args [ 2 ] ++ ) {
V_3 = V_27 -> args [ 2 ] ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 -> V_9 == V_23 )
continue;
V_30 = F_12 ( V_25 , V_37 ) ;
if ( ! V_30 ) {
if ( V_3 == V_31 ) {
F_13 ( V_25 , V_29 ) ;
return - V_36 ;
} else
goto V_38;
}
if ( F_14 ( V_25 , V_39 ,
F_15 ( V_2 -> V_34 + V_3 ) ) ||
( V_7 -> V_9 == V_11 &&
F_16 ( V_25 , V_40 , V_22 ,
V_7 -> V_20 ) ) )
goto V_38;
F_17 ( V_25 , V_30 ) ;
}
F_17 ( V_25 , V_29 ) ;
V_27 -> args [ 2 ] = 0 ;
return 0 ;
V_38:
F_13 ( V_25 , V_30 ) ;
F_17 ( V_25 , V_29 ) ;
if ( F_18 ( V_3 == V_31 ) ) {
V_27 -> args [ 2 ] = 0 ;
return - V_36 ;
}
return 0 ;
}
static int
F_19 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
const struct V_18 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
switch ( V_7 -> V_9 ) {
case V_10 :
return - V_19 ;
case V_11 :
return ( V_16 -> V_20 == NULL ||
F_8 ( V_16 -> V_20 , V_7 -> V_20 ) ) &&
! F_4 ( V_2 , V_16 -> V_3 ) ;
}
return 0 ;
}
static int
F_20 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
struct V_6 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
bool V_41 = V_15 & V_42 ;
switch ( V_7 -> V_9 ) {
case V_10 :
if ( ! ( V_16 -> V_20 || V_41 ) )
return - V_21 ;
memcpy ( V_7 -> V_20 , V_16 -> V_20 , V_22 ) ;
V_7 -> V_9 = V_11 ;
if ( V_8 == V_2 -> V_8 )
V_8 = V_7 -> V_8 ;
V_7 -> V_8 = F_21 ( V_8 ) ;
break;
case V_11 :
if ( ! ( F_4 ( V_2 , V_16 -> V_3 ) || V_41 ) )
return - V_21 ;
case V_23 :
if ( V_16 -> V_20 ) {
memcpy ( V_7 -> V_20 , V_16 -> V_20 , V_22 ) ;
V_7 -> V_9 = V_11 ;
} else
V_7 -> V_9 = V_10 ;
V_7 -> V_8 = V_16 -> V_20 ? F_21 ( V_8 )
: V_8 ;
break;
}
return 0 ;
}
static int
F_22 ( struct V_12 * V_13 , void * V_14 , T_1 V_8 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_17 * V_16 = V_14 ;
struct V_6 * V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
if ( V_7 -> V_9 == V_23 || F_4 ( V_2 , V_16 -> V_3 ) )
return - V_21 ;
V_7 -> V_9 = V_23 ;
return 0 ;
}
static int
F_23 ( const struct V_12 * V_13 ,
struct V_24 * V_25 , struct V_26 * V_27 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
const struct V_6 * V_7 ;
struct V_28 * V_29 , * V_30 ;
T_1 V_3 , V_31 = V_27 -> args [ 2 ] ;
T_1 V_8 , V_32 = V_2 -> V_33 - V_2 -> V_34 ;
V_29 = F_12 ( V_25 , V_35 ) ;
if ( ! V_29 )
return - V_36 ;
for (; V_27 -> args [ 2 ] <= V_32 ; V_27 -> args [ 2 ] ++ ) {
V_3 = V_27 -> args [ 2 ] ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( ! F_6 ( V_7 ) )
continue;
V_30 = F_12 ( V_25 , V_37 ) ;
if ( ! V_30 ) {
if ( V_3 == V_31 ) {
F_13 ( V_25 , V_29 ) ;
return - V_36 ;
} else
goto V_38;
}
if ( F_14 ( V_25 , V_39 ,
F_15 ( V_2 -> V_34 + V_3 ) ) ||
( V_7 -> V_9 == V_11 &&
F_16 ( V_25 , V_40 , V_22 ,
V_7 -> V_20 ) ) )
goto V_38;
V_8 = V_7 -> V_9 == V_10 ? V_7 -> V_8
: F_24 ( V_7 -> V_8 ) ;
if ( F_25 ( V_25 , V_43 , F_15 ( V_8 ) ) )
goto V_38;
F_17 ( V_25 , V_30 ) ;
}
F_17 ( V_25 , V_29 ) ;
V_27 -> args [ 2 ] = 0 ;
return 0 ;
V_38:
F_13 ( V_25 , V_30 ) ;
F_17 ( V_25 , V_29 ) ;
return - V_36 ;
}
static int
F_26 ( struct V_12 * V_13 , const struct V_24 * V_25 ,
const struct V_44 * V_45 ,
enum V_46 V_47 , const struct V_48 * V_49 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
T_2 V_50 = V_13 -> V_51 -> V_47 [ V_47 ] ;
struct V_17 V_16 ;
if ( ! ( V_49 -> V_15 & V_52 ) )
return 0 ;
V_16 . V_3 = F_27 ( F_28 ( V_25 , V_49 -> V_15 & V_53 ) ) ;
if ( V_16 . V_3 < V_2 -> V_34 || V_16 . V_3 > V_2 -> V_33 )
return - V_54 ;
if ( F_29 ( V_25 ) < V_25 -> V_55 ||
( F_29 ( V_25 ) + V_56 ) > V_25 -> V_16 )
return - V_57 ;
V_16 . V_3 -= V_2 -> V_34 ;
V_16 . V_20 = F_30 ( V_25 ) -> V_58 ;
return V_50 ( V_13 , & V_16 , F_31 ( V_49 , V_2 ) , V_49 -> V_59 ) ;
}
static int
F_32 ( struct V_12 * V_13 , struct V_28 * V_60 [] ,
enum V_46 V_47 , T_1 * V_61 , T_1 V_15 , bool V_62 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
T_2 V_50 = V_13 -> V_51 -> V_47 [ V_47 ] ;
struct V_17 V_16 ;
T_1 V_8 = V_2 -> V_8 ;
int V_63 = 0 ;
if ( F_18 ( ! V_60 [ V_39 ] ||
! F_33 ( V_60 , V_43 ) ) )
return - V_64 ;
if ( V_60 [ V_65 ] )
* V_61 = F_34 ( V_60 [ V_65 ] ) ;
V_63 = F_35 ( V_60 [ V_39 ] , & V_16 . V_3 ) ;
if ( V_63 )
return V_63 ;
if ( V_16 . V_3 < V_2 -> V_34 || V_16 . V_3 > V_2 -> V_33 )
return - V_54 ;
if ( V_60 [ V_40 ] )
V_16 . V_20 = F_36 ( V_60 [ V_40 ] ) ;
else
V_16 . V_20 = NULL ;
if ( V_60 [ V_43 ] ) {
if ( ! F_37 ( V_2 -> V_8 ) )
return - V_66 ;
V_8 = F_38 ( V_60 [ V_43 ] ) ;
}
V_16 . V_3 -= V_2 -> V_34 ;
V_63 = V_50 ( V_13 , & V_16 , V_8 , V_15 ) ;
return F_39 ( V_63 , V_15 ) ? 0 : V_63 ;
}
static void
F_40 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
if ( F_37 ( V_2 -> V_8 ) )
F_41 ( & V_2 -> V_67 ) ;
F_42 ( V_2 -> V_4 ) ;
F_43 ( V_2 ) ;
V_13 -> V_16 = NULL ;
}
static void
F_44 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
memset ( V_2 -> V_4 , 0 ,
( V_2 -> V_33 - V_2 -> V_34 + 1 ) * V_2 -> V_5 ) ;
}
static int
F_45 ( struct V_12 * V_13 , struct V_24 * V_25 )
{
const struct V_1 * V_2 = V_13 -> V_16 ;
struct V_28 * V_30 ;
V_30 = F_12 ( V_25 , V_37 ) ;
if ( ! V_30 )
goto V_38;
if ( F_14 ( V_25 , V_39 , F_15 ( V_2 -> V_34 ) ) ||
F_14 ( V_25 , V_68 , F_15 ( V_2 -> V_33 ) ) ||
F_25 ( V_25 , V_69 , F_15 ( V_13 -> V_70 - 1 ) ) ||
F_25 ( V_25 , V_71 ,
F_15 ( sizeof( * V_2 ) +
( ( V_2 -> V_33 - V_2 -> V_34 + 1 ) *
V_2 -> V_5 ) ) ) ||
( F_37 ( V_2 -> V_8 ) &&
F_25 ( V_25 , V_43 , F_15 ( V_2 -> V_8 ) ) ) )
goto V_38;
F_17 ( V_25 , V_30 ) ;
return 0 ;
V_38:
return - V_36 ;
}
static bool
F_46 ( const struct V_12 * V_72 , const struct V_12 * V_73 )
{
const struct V_1 * V_74 = V_72 -> V_16 ;
const struct V_1 * V_75 = V_73 -> V_16 ;
return V_74 -> V_34 == V_75 -> V_34 &&
V_74 -> V_33 == V_75 -> V_33 &&
V_74 -> V_8 == V_75 -> V_8 ;
}
static void
F_47 ( unsigned long V_76 )
{
struct V_12 * V_13 = (struct V_12 * ) V_76 ;
struct V_1 * V_2 = V_13 -> V_16 ;
struct V_6 * V_7 ;
T_1 V_3 , V_32 = V_2 -> V_33 - V_2 -> V_34 ;
F_48 ( & V_13 -> V_77 ) ;
for ( V_3 = 0 ; V_3 <= V_32 ; V_3 ++ ) {
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 -> V_9 == V_11 &&
F_5 ( V_7 -> V_8 ) )
V_7 -> V_9 = V_23 ;
}
F_49 ( & V_13 -> V_77 ) ;
V_2 -> V_67 . V_78 = V_79 + F_50 ( V_2 -> V_8 ) * V_80 ;
F_51 ( & V_2 -> V_67 ) ;
}
static void
F_52 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
F_53 ( & V_2 -> V_67 ) ;
V_2 -> V_67 . V_16 = ( unsigned long ) V_13 ;
V_2 -> V_67 . V_81 = F_47 ;
V_2 -> V_67 . V_78 = V_79 + F_50 ( V_2 -> V_8 ) * V_80 ;
F_51 ( & V_2 -> V_67 ) ;
}
static bool
F_54 ( struct V_12 * V_13 , struct V_1 * V_2 ,
T_1 V_34 , T_1 V_33 )
{
V_2 -> V_4 = F_55 ( ( V_33 - V_34 + 1 ) * V_2 -> V_5 ) ;
if ( ! V_2 -> V_4 )
return false ;
V_2 -> V_34 = V_34 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_8 = V_82 ;
V_13 -> V_16 = V_2 ;
V_13 -> V_83 = V_84 ;
return true ;
}
static int
F_56 ( struct V_12 * V_13 , struct V_28 * V_60 [] ,
T_1 V_15 )
{
T_1 V_34 , V_33 ;
T_3 V_85 ;
struct V_1 * V_2 ;
int V_63 ;
if ( F_18 ( ! V_60 [ V_39 ] ||
! F_33 ( V_60 , V_43 ) ) )
return - V_64 ;
V_63 = F_35 ( V_60 [ V_39 ] , & V_34 ) ;
if ( V_63 )
return V_63 ;
if ( V_60 [ V_68 ] ) {
V_63 = F_35 ( V_60 [ V_68 ] , & V_33 ) ;
if ( V_63 )
return V_63 ;
if ( V_34 > V_33 ) {
T_1 V_86 = V_34 ;
V_34 = V_33 ;
V_33 = V_86 ;
}
} else if ( V_60 [ V_87 ] ) {
T_4 V_88 = F_57 ( V_60 [ V_87 ] ) ;
if ( V_88 >= 32 )
return - V_89 ;
F_58 ( V_34 , V_33 , V_88 ) ;
} else
return - V_64 ;
V_85 = ( T_3 ) V_33 - V_34 + 1 ;
if ( V_85 > V_90 + 1 )
return - V_91 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_93 ;
if ( V_60 [ V_43 ] ) {
V_2 -> V_5 = sizeof( struct V_6 ) ;
if ( ! F_54 ( V_13 , V_2 , V_34 , V_33 ) ) {
F_43 ( V_2 ) ;
return - V_93 ;
}
V_2 -> V_8 = F_38 ( V_60 [ V_43 ] ) ;
V_13 -> V_51 = & V_94 ;
F_52 ( V_13 ) ;
} else {
V_2 -> V_5 = sizeof( struct V_18 ) ;
if ( ! F_54 ( V_13 , V_2 , V_34 , V_33 ) ) {
F_43 ( V_2 ) ;
return - V_93 ;
}
V_13 -> V_51 = & V_1 ;
}
return 0 ;
}
static int T_5
F_60 ( void )
{
return F_61 ( & V_95 ) ;
}
static void T_6
F_62 ( void )
{
F_63 ( & V_95 ) ;
}
