static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return ( ( V_3 & F_2 ( V_2 -> V_4 ) ) - V_2 -> V_5 ) / V_2 -> V_6 ;
}
static int
F_3 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
const struct V_1 * V_11 = V_8 -> V_12 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
return ! ! F_4 ( V_13 , V_11 -> V_14 ) ;
}
static int
F_5 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
if ( F_6 ( V_13 , V_11 -> V_14 ) )
return - V_15 ;
return 0 ;
}
static int
F_7 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
if ( ! F_8 ( V_13 , V_11 -> V_14 ) )
return - V_15 ;
return 0 ;
}
static int
F_9 ( const struct V_7 * V_8 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
const struct V_1 * V_11 = V_8 -> V_12 ;
struct V_20 * V_21 , * V_22 ;
T_1 V_13 , V_23 = V_19 -> args [ 2 ] ;
V_21 = F_10 ( V_17 , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
for (; V_19 -> args [ 2 ] < V_11 -> V_26 ; V_19 -> args [ 2 ] ++ ) {
V_13 = V_19 -> args [ 2 ] ;
if ( ! F_4 ( V_13 , V_11 -> V_14 ) )
continue;
V_22 = F_10 ( V_17 , V_27 ) ;
if ( ! V_22 ) {
if ( V_13 == V_23 ) {
F_11 ( V_17 , V_21 ) ;
return - V_25 ;
} else
goto V_28;
}
F_12 ( V_17 , V_29 ,
F_13 ( V_11 -> V_5 + V_13 * V_11 -> V_6 ) ) ;
F_14 ( V_17 , V_22 ) ;
}
F_14 ( V_17 , V_21 ) ;
V_19 -> args [ 2 ] = 0 ;
return 0 ;
V_28:
F_11 ( V_17 , V_22 ) ;
F_14 ( V_17 , V_21 ) ;
if ( F_15 ( V_13 == V_23 ) ) {
V_19 -> args [ 2 ] = 0 ;
return - V_25 ;
}
return 0 ;
}
static int
F_16 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
const struct V_1 * V_11 = V_8 -> V_12 ;
const unsigned long * V_14 = V_11 -> V_14 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
return F_17 ( V_14 [ V_13 ] ) ;
}
static int
F_18 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
unsigned long * V_14 = V_11 -> V_14 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
if ( F_17 ( V_14 [ V_13 ] ) )
return - V_15 ;
V_14 [ V_13 ] = F_19 ( V_10 ) ;
return 0 ;
}
static int
F_20 ( struct V_7 * V_8 , void * V_9 , T_1 V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
unsigned long * V_14 = V_11 -> V_14 ;
T_2 V_13 = * ( T_2 * ) V_9 ;
int V_30 = - V_15 ;
if ( F_17 ( V_14 [ V_13 ] ) )
V_30 = 0 ;
V_14 [ V_13 ] = V_31 ;
return V_30 ;
}
static int
F_21 ( const struct V_7 * V_8 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
const struct V_1 * V_11 = V_8 -> V_12 ;
struct V_20 * V_32 , * V_22 ;
T_1 V_13 , V_23 = V_19 -> args [ 2 ] ;
const unsigned long * V_14 = V_11 -> V_14 ;
V_32 = F_10 ( V_17 , V_24 ) ;
if ( ! V_32 )
return - V_25 ;
for (; V_19 -> args [ 2 ] < V_11 -> V_26 ; V_19 -> args [ 2 ] ++ ) {
V_13 = V_19 -> args [ 2 ] ;
if ( ! F_17 ( V_14 [ V_13 ] ) )
continue;
V_22 = F_10 ( V_17 , V_27 ) ;
if ( ! V_22 ) {
if ( V_13 == V_23 ) {
F_11 ( V_17 , V_32 ) ;
return - V_25 ;
} else
goto V_28;
}
F_12 ( V_17 , V_29 ,
F_13 ( V_11 -> V_5 + V_13 * V_11 -> V_6 ) ) ;
F_22 ( V_17 , V_33 ,
F_13 ( F_23 ( V_14 [ V_13 ] ) ) ) ;
F_14 ( V_17 , V_22 ) ;
}
F_14 ( V_17 , V_32 ) ;
V_19 -> args [ 2 ] = 0 ;
return 0 ;
V_28:
F_11 ( V_17 , V_22 ) ;
F_14 ( V_17 , V_32 ) ;
if ( F_15 ( V_13 == V_23 ) ) {
V_19 -> args [ 2 ] = 0 ;
return - V_25 ;
}
return 0 ;
}
static int
F_24 ( struct V_7 * V_8 , const struct V_16 * V_17 ,
enum V_34 V_32 , T_3 V_35 , T_3 V_36 , T_3 V_37 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
T_4 V_38 = V_8 -> V_39 -> V_32 [ V_32 ] ;
T_1 V_3 ;
V_3 = F_25 ( F_26 ( V_17 , V_37 & V_40 ) ) ;
if ( V_3 < V_11 -> V_5 || V_3 > V_11 -> V_41 )
return - V_42 ;
V_3 = F_1 ( V_11 , V_3 ) ;
return V_38 ( V_8 , & V_3 , V_11 -> V_10 ) ;
}
static int
F_27 ( struct V_7 * V_8 , struct V_20 * V_43 [] ,
enum V_34 V_32 , T_1 * V_44 , T_1 V_37 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
T_4 V_38 = V_8 -> V_39 -> V_32 [ V_32 ] ;
T_1 V_10 = V_11 -> V_10 ;
T_1 V_3 , V_45 , V_13 ;
int V_30 = 0 ;
if ( F_15 ( ! V_43 [ V_29 ] ||
! F_28 ( V_43 , V_33 ) ) )
return - V_46 ;
if ( V_43 [ V_47 ] )
* V_44 = F_29 ( V_43 [ V_47 ] ) ;
V_30 = F_30 ( V_43 [ V_29 ] , & V_3 ) ;
if ( V_30 )
return V_30 ;
if ( V_3 < V_11 -> V_5 || V_3 > V_11 -> V_41 )
return - V_42 ;
if ( V_43 [ V_33 ] ) {
if ( ! F_31 ( V_11 -> V_10 ) )
return - V_48 ;
V_10 = F_32 ( V_43 [ V_33 ] ) ;
}
if ( V_32 == V_49 ) {
V_13 = F_1 ( V_11 , V_3 ) ;
return V_38 ( V_8 , & V_13 , V_10 ) ;
}
if ( V_43 [ V_50 ] ) {
V_30 = F_30 ( V_43 [ V_50 ] , & V_45 ) ;
if ( V_30 )
return V_30 ;
if ( V_3 > V_45 ) {
F_33 ( V_3 , V_45 ) ;
if ( V_3 < V_11 -> V_5 )
return - V_42 ;
}
} else if ( V_43 [ V_51 ] ) {
T_3 V_52 = F_34 ( V_43 [ V_51 ] ) ;
if ( V_52 > 32 )
return - V_53 ;
V_3 &= F_2 ( V_52 ) ;
V_45 = V_3 | ~ F_2 ( V_52 ) ;
} else
V_45 = V_3 ;
if ( V_45 > V_11 -> V_41 )
return - V_42 ;
for (; ! F_35 ( V_45 , V_3 ) ; V_3 += V_11 -> V_6 ) {
V_13 = F_1 ( V_11 , V_3 ) ;
V_30 = V_38 ( V_8 , & V_13 , V_10 ) ;
if ( V_30 && ! F_36 ( V_30 , V_37 ) )
return V_30 ;
else
V_30 = 0 ;
}
return V_30 ;
}
static void
F_37 ( struct V_7 * V_8 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
if ( F_31 ( V_11 -> V_10 ) )
F_38 ( & V_11 -> V_54 ) ;
F_39 ( V_11 -> V_14 ) ;
F_40 ( V_11 ) ;
V_8 -> V_12 = NULL ;
}
static void
F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
memset ( V_11 -> V_14 , 0 , V_11 -> V_55 ) ;
}
static int
F_42 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
const struct V_1 * V_11 = V_8 -> V_12 ;
struct V_20 * V_22 ;
V_22 = F_10 ( V_17 , V_27 ) ;
if ( ! V_22 )
goto V_28;
F_12 ( V_17 , V_29 , F_13 ( V_11 -> V_5 ) ) ;
F_12 ( V_17 , V_50 , F_13 ( V_11 -> V_41 ) ) ;
if ( V_11 -> V_4 != 32 )
F_43 ( V_17 , V_56 , V_11 -> V_4 ) ;
F_22 ( V_17 , V_57 , F_13 ( V_8 -> V_58 - 1 ) ) ;
F_22 ( V_17 , V_59 ,
F_13 ( sizeof( * V_11 ) + V_11 -> V_55 ) ) ;
if ( F_31 ( V_11 -> V_10 ) )
F_22 ( V_17 , V_33 , F_13 ( V_11 -> V_10 ) ) ;
F_14 ( V_17 , V_22 ) ;
return 0 ;
V_28:
return - V_25 ;
}
static bool
F_44 ( const struct V_7 * V_60 , const struct V_7 * V_61 )
{
const struct V_1 * V_62 = V_60 -> V_12 ;
const struct V_1 * V_63 = V_61 -> V_12 ;
return V_62 -> V_5 == V_63 -> V_5 &&
V_62 -> V_41 == V_63 -> V_41 &&
V_62 -> V_4 == V_63 -> V_4 &&
V_62 -> V_10 == V_63 -> V_10 ;
}
static void
F_45 ( unsigned long V_64 )
{
struct V_7 * V_8 = (struct V_7 * ) V_64 ;
struct V_1 * V_11 = V_8 -> V_12 ;
unsigned long * V_65 = V_11 -> V_14 ;
T_1 V_13 ;
F_46 ( & V_8 -> V_66 ) ;
for ( V_13 = 0 ; V_13 < V_11 -> V_26 ; V_13 ++ )
if ( F_47 ( V_65 [ V_13 ] ) )
V_65 [ V_13 ] = V_31 ;
F_48 ( & V_8 -> V_66 ) ;
V_11 -> V_54 . V_67 = V_68 + F_49 ( V_11 -> V_10 ) * V_69 ;
F_50 ( & V_11 -> V_54 ) ;
}
static void
F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
F_52 ( & V_11 -> V_54 ) ;
V_11 -> V_54 . V_12 = ( unsigned long ) V_8 ;
V_11 -> V_54 . V_70 = F_45 ;
V_11 -> V_54 . V_67 = V_68 + F_49 ( V_11 -> V_10 ) * V_69 ;
F_50 ( & V_11 -> V_54 ) ;
}
static bool
F_53 ( struct V_7 * V_8 , struct V_1 * V_11 ,
T_1 V_5 , T_1 V_41 ,
T_1 V_26 , T_1 V_6 , T_3 V_4 )
{
V_11 -> V_14 = F_54 ( V_11 -> V_55 ) ;
if ( ! V_11 -> V_14 )
return false ;
V_11 -> V_5 = V_5 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_26 = V_26 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_10 = V_71 ;
V_8 -> V_12 = V_11 ;
V_8 -> V_72 = V_73 ;
return true ;
}
static int
F_55 ( struct V_7 * V_8 , struct V_20 * V_43 [] , T_1 V_37 )
{
struct V_1 * V_11 ;
T_1 V_5 , V_41 , V_6 , V_26 ;
T_3 V_4 = 32 ;
int V_30 ;
if ( F_15 ( ! V_43 [ V_29 ] ||
! F_28 ( V_43 , V_33 ) ) )
return - V_46 ;
V_30 = F_30 ( V_43 [ V_29 ] , & V_5 ) ;
if ( V_30 )
return V_30 ;
if ( V_43 [ V_50 ] ) {
V_30 = F_30 ( V_43 [ V_50 ] , & V_41 ) ;
if ( V_30 )
return V_30 ;
if ( V_5 > V_41 ) {
T_1 V_74 = V_5 ;
V_5 = V_41 ;
V_41 = V_74 ;
}
} else if ( V_43 [ V_51 ] ) {
T_3 V_52 = F_34 ( V_43 [ V_51 ] ) ;
if ( V_52 >= 32 )
return - V_53 ;
V_41 = V_5 | ~ F_2 ( V_52 ) ;
} else
return - V_46 ;
if ( V_43 [ V_56 ] ) {
V_4 = F_34 ( V_43 [ V_56 ] ) ;
if ( V_4 > 32 )
return - V_75 ;
V_5 &= F_2 ( V_4 ) ;
V_41 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_26 = V_41 - V_5 + 1 ;
} else {
T_3 V_76 ;
T_1 V_77 ;
V_77 = F_56 ( V_5 , V_41 , & V_76 ) ;
if ( ( ! V_77 && ( V_5 || V_41 != 0xFFFFFFFF ) ) ||
V_4 <= V_76 )
return - V_42 ;
F_57 ( L_1 , V_76 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_26 = 2 << ( V_4 - V_76 - 1 ) ;
}
if ( V_26 > V_78 + 1 )
return - V_79 ;
F_57 ( L_2 , V_6 , V_26 ) ;
V_11 = F_58 ( sizeof( * V_11 ) , V_80 ) ;
if ( ! V_11 )
return - V_81 ;
if ( V_43 [ V_33 ] ) {
V_11 -> V_55 = V_26 * sizeof( unsigned long ) ;
if ( ! F_53 ( V_8 , V_11 , V_5 , V_41 ,
V_26 , V_6 , V_4 ) ) {
F_40 ( V_11 ) ;
return - V_81 ;
}
V_11 -> V_10 = F_32 ( V_43 [ V_33 ] ) ;
V_8 -> V_39 = & V_82 ;
F_51 ( V_8 ) ;
} else {
V_11 -> V_55 = F_59 ( 0 , V_26 - 1 ) ;
if ( ! F_53 ( V_8 , V_11 , V_5 , V_41 ,
V_26 , V_6 , V_4 ) ) {
F_40 ( V_11 ) ;
return - V_81 ;
}
V_8 -> V_39 = & V_1 ;
}
return 0 ;
}
static int T_5
F_60 ( void )
{
return F_61 ( & V_83 ) ;
}
static void T_6
F_62 ( void )
{
F_63 ( & V_83 ) ;
}
