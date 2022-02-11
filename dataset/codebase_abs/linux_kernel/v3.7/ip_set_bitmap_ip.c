static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return ( ( V_3 & F_2 ( V_2 -> V_4 ) ) - V_2 -> V_5 ) / V_2 -> V_6 ;
}
static int
F_3 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
const struct V_1 * V_12 = V_8 -> V_13 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
return ! ! F_4 ( V_14 , V_12 -> V_15 ) ;
}
static int
F_5 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
if ( F_6 ( V_14 , V_12 -> V_15 ) )
return - V_16 ;
return 0 ;
}
static int
F_7 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
if ( ! F_8 ( V_14 , V_12 -> V_15 ) )
return - V_16 ;
return 0 ;
}
static int
F_9 ( const struct V_7 * V_8 ,
struct V_17 * V_18 , struct V_19 * V_20 )
{
const struct V_1 * V_12 = V_8 -> V_13 ;
struct V_21 * V_22 , * V_23 ;
T_1 V_14 , V_24 = V_20 -> args [ 2 ] ;
V_22 = F_10 ( V_18 , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
for (; V_20 -> args [ 2 ] < V_12 -> V_27 ; V_20 -> args [ 2 ] ++ ) {
V_14 = V_20 -> args [ 2 ] ;
if ( ! F_4 ( V_14 , V_12 -> V_15 ) )
continue;
V_23 = F_10 ( V_18 , V_28 ) ;
if ( ! V_23 ) {
if ( V_14 == V_24 ) {
F_11 ( V_18 , V_22 ) ;
return - V_26 ;
} else
goto V_29;
}
if ( F_12 ( V_18 , V_30 ,
F_13 ( V_12 -> V_5 + V_14 * V_12 -> V_6 ) ) )
goto V_29;
F_14 ( V_18 , V_23 ) ;
}
F_14 ( V_18 , V_22 ) ;
V_20 -> args [ 2 ] = 0 ;
return 0 ;
V_29:
F_11 ( V_18 , V_23 ) ;
F_14 ( V_18 , V_22 ) ;
if ( F_15 ( V_14 == V_24 ) ) {
V_20 -> args [ 2 ] = 0 ;
return - V_26 ;
}
return 0 ;
}
static int
F_16 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
const struct V_1 * V_12 = V_8 -> V_13 ;
const unsigned long * V_15 = V_12 -> V_15 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
return F_17 ( V_15 [ V_14 ] ) ;
}
static int
F_18 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
unsigned long * V_15 = V_12 -> V_15 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
if ( F_17 ( V_15 [ V_14 ] ) && ! ( V_11 & V_31 ) )
return - V_16 ;
V_15 [ V_14 ] = F_19 ( V_10 ) ;
return 0 ;
}
static int
F_20 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
unsigned long * V_15 = V_12 -> V_15 ;
T_2 V_14 = * ( T_2 * ) V_9 ;
int V_32 = - V_16 ;
if ( F_17 ( V_15 [ V_14 ] ) )
V_32 = 0 ;
V_15 [ V_14 ] = V_33 ;
return V_32 ;
}
static int
F_21 ( const struct V_7 * V_8 ,
struct V_17 * V_18 , struct V_19 * V_20 )
{
const struct V_1 * V_12 = V_8 -> V_13 ;
struct V_21 * V_34 , * V_23 ;
T_1 V_14 , V_24 = V_20 -> args [ 2 ] ;
const unsigned long * V_15 = V_12 -> V_15 ;
V_34 = F_10 ( V_18 , V_25 ) ;
if ( ! V_34 )
return - V_26 ;
for (; V_20 -> args [ 2 ] < V_12 -> V_27 ; V_20 -> args [ 2 ] ++ ) {
V_14 = V_20 -> args [ 2 ] ;
if ( ! F_17 ( V_15 [ V_14 ] ) )
continue;
V_23 = F_10 ( V_18 , V_28 ) ;
if ( ! V_23 ) {
if ( V_14 == V_24 ) {
F_11 ( V_18 , V_34 ) ;
return - V_26 ;
} else
goto V_29;
}
if ( F_12 ( V_18 , V_30 ,
F_13 ( V_12 -> V_5 + V_14 * V_12 -> V_6 ) ) ||
F_22 ( V_18 , V_35 ,
F_13 ( F_23 ( V_15 [ V_14 ] ) ) ) )
goto V_29;
F_14 ( V_18 , V_23 ) ;
}
F_14 ( V_18 , V_34 ) ;
V_20 -> args [ 2 ] = 0 ;
return 0 ;
V_29:
F_11 ( V_18 , V_23 ) ;
F_14 ( V_18 , V_34 ) ;
if ( F_15 ( V_14 == V_24 ) ) {
V_20 -> args [ 2 ] = 0 ;
return - V_26 ;
}
return 0 ;
}
static int
F_24 ( struct V_7 * V_8 , const struct V_17 * V_18 ,
const struct V_36 * V_37 ,
enum V_38 V_34 , const struct V_39 * V_40 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
T_3 V_41 = V_8 -> V_42 -> V_34 [ V_34 ] ;
T_1 V_3 ;
V_3 = F_25 ( F_26 ( V_18 , V_40 -> V_11 & V_43 ) ) ;
if ( V_3 < V_12 -> V_5 || V_3 > V_12 -> V_44 )
return - V_45 ;
V_3 = F_1 ( V_12 , V_3 ) ;
return V_41 ( V_8 , & V_3 , F_27 ( V_40 , V_12 ) , V_40 -> V_46 ) ;
}
static int
F_28 ( struct V_7 * V_8 , struct V_21 * V_47 [] ,
enum V_38 V_34 , T_1 * V_48 , T_1 V_11 , bool V_49 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
T_3 V_41 = V_8 -> V_42 -> V_34 [ V_34 ] ;
T_1 V_10 = V_12 -> V_10 ;
T_1 V_3 , V_50 , V_14 ;
int V_32 = 0 ;
if ( F_15 ( ! V_47 [ V_30 ] ||
! F_29 ( V_47 , V_35 ) ) )
return - V_51 ;
if ( V_47 [ V_52 ] )
* V_48 = F_30 ( V_47 [ V_52 ] ) ;
V_32 = F_31 ( V_47 [ V_30 ] , & V_3 ) ;
if ( V_32 )
return V_32 ;
if ( V_3 < V_12 -> V_5 || V_3 > V_12 -> V_44 )
return - V_45 ;
if ( V_47 [ V_35 ] ) {
if ( ! F_32 ( V_12 -> V_10 ) )
return - V_53 ;
V_10 = F_33 ( V_47 [ V_35 ] ) ;
}
if ( V_34 == V_54 ) {
V_14 = F_1 ( V_12 , V_3 ) ;
return V_41 ( V_8 , & V_14 , V_10 , V_11 ) ;
}
if ( V_47 [ V_55 ] ) {
V_32 = F_31 ( V_47 [ V_55 ] , & V_50 ) ;
if ( V_32 )
return V_32 ;
if ( V_3 > V_50 ) {
F_34 ( V_3 , V_50 ) ;
if ( V_3 < V_12 -> V_5 )
return - V_45 ;
}
} else if ( V_47 [ V_56 ] ) {
T_4 V_57 = F_35 ( V_47 [ V_56 ] ) ;
if ( ! V_57 || V_57 > 32 )
return - V_58 ;
F_36 ( V_3 , V_50 , V_57 ) ;
} else
V_50 = V_3 ;
if ( V_50 > V_12 -> V_44 )
return - V_45 ;
for (; ! F_37 ( V_50 , V_3 ) ; V_3 += V_12 -> V_6 ) {
V_14 = F_1 ( V_12 , V_3 ) ;
V_32 = V_41 ( V_8 , & V_14 , V_10 , V_11 ) ;
if ( V_32 && ! F_38 ( V_32 , V_11 ) )
return V_32 ;
else
V_32 = 0 ;
}
return V_32 ;
}
static void
F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
if ( F_32 ( V_12 -> V_10 ) )
F_40 ( & V_12 -> V_59 ) ;
F_41 ( V_12 -> V_15 ) ;
F_42 ( V_12 ) ;
V_8 -> V_13 = NULL ;
}
static void
F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
memset ( V_12 -> V_15 , 0 , V_12 -> V_60 ) ;
}
static int
F_44 ( struct V_7 * V_8 , struct V_17 * V_18 )
{
const struct V_1 * V_12 = V_8 -> V_13 ;
struct V_21 * V_23 ;
V_23 = F_10 ( V_18 , V_28 ) ;
if ( ! V_23 )
goto V_29;
if ( F_12 ( V_18 , V_30 , F_13 ( V_12 -> V_5 ) ) ||
F_12 ( V_18 , V_55 , F_13 ( V_12 -> V_44 ) ) ||
( V_12 -> V_4 != 32 &&
F_45 ( V_18 , V_61 , V_12 -> V_4 ) ) ||
F_22 ( V_18 , V_62 , F_13 ( V_8 -> V_63 - 1 ) ) ||
F_22 ( V_18 , V_64 ,
F_13 ( sizeof( * V_12 ) + V_12 -> V_60 ) ) ||
( F_32 ( V_12 -> V_10 ) &&
F_22 ( V_18 , V_35 , F_13 ( V_12 -> V_10 ) ) ) )
goto V_29;
F_14 ( V_18 , V_23 ) ;
return 0 ;
V_29:
return - V_26 ;
}
static bool
F_46 ( const struct V_7 * V_65 , const struct V_7 * V_66 )
{
const struct V_1 * V_67 = V_65 -> V_13 ;
const struct V_1 * V_68 = V_66 -> V_13 ;
return V_67 -> V_5 == V_68 -> V_5 &&
V_67 -> V_44 == V_68 -> V_44 &&
V_67 -> V_4 == V_68 -> V_4 &&
V_67 -> V_10 == V_68 -> V_10 ;
}
static void
F_47 ( unsigned long V_69 )
{
struct V_7 * V_8 = (struct V_7 * ) V_69 ;
struct V_1 * V_12 = V_8 -> V_13 ;
unsigned long * V_70 = V_12 -> V_15 ;
T_1 V_14 ;
F_48 ( & V_8 -> V_71 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_27 ; V_14 ++ )
if ( F_49 ( V_70 [ V_14 ] ) )
V_70 [ V_14 ] = V_33 ;
F_50 ( & V_8 -> V_71 ) ;
V_12 -> V_59 . V_72 = V_73 + F_51 ( V_12 -> V_10 ) * V_74 ;
F_52 ( & V_12 -> V_59 ) ;
}
static void
F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_12 = V_8 -> V_13 ;
F_54 ( & V_12 -> V_59 ) ;
V_12 -> V_59 . V_13 = ( unsigned long ) V_8 ;
V_12 -> V_59 . V_75 = F_47 ;
V_12 -> V_59 . V_72 = V_73 + F_51 ( V_12 -> V_10 ) * V_74 ;
F_52 ( & V_12 -> V_59 ) ;
}
static bool
F_55 ( struct V_7 * V_8 , struct V_1 * V_12 ,
T_1 V_5 , T_1 V_44 ,
T_1 V_27 , T_1 V_6 , T_4 V_4 )
{
V_12 -> V_15 = F_56 ( V_12 -> V_60 ) ;
if ( ! V_12 -> V_15 )
return false ;
V_12 -> V_5 = V_5 ;
V_12 -> V_44 = V_44 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_4 = V_4 ;
V_12 -> V_10 = V_76 ;
V_8 -> V_13 = V_12 ;
V_8 -> V_77 = V_78 ;
return true ;
}
static int
F_57 ( struct V_7 * V_8 , struct V_21 * V_47 [] , T_1 V_11 )
{
struct V_1 * V_12 ;
T_1 V_5 , V_44 , V_6 ;
T_5 V_27 ;
T_4 V_4 = 32 ;
int V_32 ;
if ( F_15 ( ! V_47 [ V_30 ] ||
! F_29 ( V_47 , V_35 ) ) )
return - V_51 ;
V_32 = F_31 ( V_47 [ V_30 ] , & V_5 ) ;
if ( V_32 )
return V_32 ;
if ( V_47 [ V_55 ] ) {
V_32 = F_31 ( V_47 [ V_55 ] , & V_44 ) ;
if ( V_32 )
return V_32 ;
if ( V_5 > V_44 ) {
T_1 V_79 = V_5 ;
V_5 = V_44 ;
V_44 = V_79 ;
}
} else if ( V_47 [ V_56 ] ) {
T_4 V_57 = F_35 ( V_47 [ V_56 ] ) ;
if ( V_57 >= 32 )
return - V_58 ;
F_36 ( V_5 , V_44 , V_57 ) ;
} else
return - V_51 ;
if ( V_47 [ V_61 ] ) {
V_4 = F_35 ( V_47 [ V_61 ] ) ;
if ( V_4 > 32 )
return - V_80 ;
V_5 &= F_2 ( V_4 ) ;
V_44 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_27 = ( T_5 ) V_44 - V_5 + 1 ;
} else {
T_4 V_81 ;
T_1 V_82 ;
V_82 = F_58 ( V_5 , V_44 , & V_81 ) ;
if ( ( ! V_82 && ( V_5 || V_44 != 0xFFFFFFFF ) ) ||
V_4 <= V_81 )
return - V_45 ;
F_59 ( L_1 , V_81 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_27 = 2 << ( V_4 - V_81 - 1 ) ;
}
if ( V_27 > V_83 + 1 )
return - V_84 ;
F_59 ( L_2 ,
V_6 , ( unsigned long long ) V_27 ) ;
V_12 = F_60 ( sizeof( * V_12 ) , V_85 ) ;
if ( ! V_12 )
return - V_86 ;
if ( V_47 [ V_35 ] ) {
V_12 -> V_60 = V_27 * sizeof( unsigned long ) ;
if ( ! F_55 ( V_8 , V_12 , V_5 , V_44 ,
V_27 , V_6 , V_4 ) ) {
F_42 ( V_12 ) ;
return - V_86 ;
}
V_12 -> V_10 = F_33 ( V_47 [ V_35 ] ) ;
V_8 -> V_42 = & V_87 ;
F_53 ( V_8 ) ;
} else {
V_12 -> V_60 = F_61 ( 0 , V_27 - 1 ) ;
if ( ! F_55 ( V_8 , V_12 , V_5 , V_44 ,
V_27 , V_6 , V_4 ) ) {
F_42 ( V_12 ) ;
return - V_86 ;
}
V_8 -> V_42 = & V_1 ;
}
return 0 ;
}
static int T_6
F_62 ( void )
{
return F_63 ( & V_88 ) ;
}
static void T_7
F_64 ( void )
{
F_65 ( & V_88 ) ;
}
