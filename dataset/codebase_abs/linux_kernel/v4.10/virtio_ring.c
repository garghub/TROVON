static bool F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return true ;
if ( F_3 () )
return true ;
return false ;
}
static inline struct V_3 * F_4 ( const struct V_4 * V_5 )
{
return V_5 -> V_5 . V_2 -> V_6 . V_7 ;
}
static T_1 F_5 ( const struct V_4 * V_5 ,
struct V_8 * V_9 ,
enum V_10 V_11 )
{
if ( ! F_1 ( V_5 -> V_5 . V_2 ) )
return ( T_1 ) F_6 ( V_9 ) ;
return F_7 ( F_4 ( V_5 ) ,
F_8 ( V_9 ) , V_9 -> V_12 , V_9 -> V_13 ,
V_11 ) ;
}
static T_1 F_9 ( const struct V_4 * V_5 ,
void * V_14 , T_2 V_15 ,
enum V_10 V_11 )
{
if ( ! F_1 ( V_5 -> V_5 . V_2 ) )
return ( T_1 ) F_10 ( V_14 ) ;
return F_11 ( F_4 ( V_5 ) ,
V_14 , V_15 , V_11 ) ;
}
static void F_12 ( const struct V_4 * V_5 ,
struct V_16 * V_17 )
{
T_3 V_18 ;
if ( ! F_1 ( V_5 -> V_5 . V_2 ) )
return;
V_18 = F_13 ( V_5 -> V_5 . V_2 , V_17 -> V_18 ) ;
if ( V_18 & V_19 ) {
F_14 ( F_4 ( V_5 ) ,
F_15 ( V_5 -> V_5 . V_2 , V_17 -> V_20 ) ,
F_16 ( V_5 -> V_5 . V_2 , V_17 -> V_21 ) ,
( V_18 & V_22 ) ?
V_23 : V_24 ) ;
} else {
F_17 ( F_4 ( V_5 ) ,
F_15 ( V_5 -> V_5 . V_2 , V_17 -> V_20 ) ,
F_16 ( V_5 -> V_5 . V_2 , V_17 -> V_21 ) ,
( V_18 & V_22 ) ?
V_23 : V_24 ) ;
}
}
static int F_18 ( const struct V_4 * V_5 ,
T_1 V_20 )
{
if ( ! F_1 ( V_5 -> V_5 . V_2 ) )
return 0 ;
return F_19 ( F_4 ( V_5 ) , V_20 ) ;
}
static struct V_16 * F_20 ( struct V_25 * V_26 ,
unsigned int V_27 , T_4 V_28 )
{
struct V_16 * V_17 ;
unsigned int V_29 ;
V_28 &= ~ V_30 ;
V_17 = F_21 ( V_27 * sizeof( struct V_16 ) , V_28 ) ;
if ( ! V_17 )
return NULL ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ )
V_17 [ V_29 ] . V_31 = F_22 ( V_26 -> V_2 , V_29 + 1 ) ;
return V_17 ;
}
static inline int F_23 ( struct V_25 * V_26 ,
struct V_8 * V_32 [] ,
unsigned int V_27 ,
unsigned int V_33 ,
unsigned int V_34 ,
void * V_35 ,
T_4 V_28 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
unsigned int V_29 , V_36 , V_37 , V_38 , V_39 ( V_40 ) , V_41 ;
int V_42 ;
bool V_43 ;
F_25 ( V_5 ) ;
F_26 ( V_35 == NULL ) ;
if ( F_27 ( V_5 -> V_44 ) ) {
F_28 ( V_5 ) ;
return - V_45 ;
}
#ifdef F_29
{
T_5 V_46 = F_30 () ;
if ( V_5 -> V_47 )
F_31 ( F_32 ( F_33 ( V_46 , V_5 -> V_48 ) )
> 100 ) ;
V_5 -> V_48 = V_46 ;
V_5 -> V_47 = true ;
}
#endif
F_26 ( V_27 > V_5 -> V_49 . V_50 ) ;
F_26 ( V_27 == 0 ) ;
V_42 = V_5 -> V_51 ;
if ( V_5 -> V_43 && V_27 > 1 && V_5 -> V_5 . V_52 )
V_17 = F_20 ( V_26 , V_27 , V_28 ) ;
else
V_17 = NULL ;
if ( V_17 ) {
V_43 = true ;
V_29 = 0 ;
V_38 = 1 ;
} else {
V_43 = false ;
V_17 = V_5 -> V_49 . V_17 ;
V_29 = V_42 ;
V_38 = V_27 ;
}
if ( V_5 -> V_5 . V_52 < V_38 ) {
F_34 ( L_1 ,
V_38 , V_5 -> V_5 . V_52 ) ;
if ( V_33 )
V_5 -> V_53 ( & V_5 -> V_5 ) ;
if ( V_43 )
F_35 ( V_17 ) ;
F_28 ( V_5 ) ;
return - V_54 ;
}
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
for ( V_9 = V_32 [ V_36 ] ; V_9 ; V_9 = F_36 ( V_9 ) ) {
T_1 V_20 = F_5 ( V_5 , V_9 , V_24 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_55;
V_17 [ V_29 ] . V_18 = F_22 ( V_26 -> V_2 , V_56 ) ;
V_17 [ V_29 ] . V_20 = F_37 ( V_26 -> V_2 , V_20 ) ;
V_17 [ V_29 ] . V_21 = F_38 ( V_26 -> V_2 , V_9 -> V_13 ) ;
V_40 = V_29 ;
V_29 = F_13 ( V_26 -> V_2 , V_17 [ V_29 ] . V_31 ) ;
}
}
for (; V_36 < ( V_33 + V_34 ) ; V_36 ++ ) {
for ( V_9 = V_32 [ V_36 ] ; V_9 ; V_9 = F_36 ( V_9 ) ) {
T_1 V_20 = F_5 ( V_5 , V_9 , V_23 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_55;
V_17 [ V_29 ] . V_18 = F_22 ( V_26 -> V_2 , V_56 | V_22 ) ;
V_17 [ V_29 ] . V_20 = F_37 ( V_26 -> V_2 , V_20 ) ;
V_17 [ V_29 ] . V_21 = F_38 ( V_26 -> V_2 , V_9 -> V_13 ) ;
V_40 = V_29 ;
V_29 = F_13 ( V_26 -> V_2 , V_17 [ V_29 ] . V_31 ) ;
}
}
V_17 [ V_40 ] . V_18 &= F_22 ( V_26 -> V_2 , ~ V_56 ) ;
if ( V_43 ) {
T_1 V_20 = F_9 (
V_5 , V_17 , V_27 * sizeof( struct V_16 ) ,
V_24 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_55;
V_5 -> V_49 . V_17 [ V_42 ] . V_18 = F_22 ( V_26 -> V_2 , V_19 ) ;
V_5 -> V_49 . V_17 [ V_42 ] . V_20 = F_37 ( V_26 -> V_2 , V_20 ) ;
V_5 -> V_49 . V_17 [ V_42 ] . V_21 = F_38 ( V_26 -> V_2 , V_27 * sizeof( struct V_16 ) ) ;
}
V_5 -> V_5 . V_52 -= V_38 ;
if ( V_43 )
V_5 -> V_51 = F_13 ( V_26 -> V_2 , V_5 -> V_49 . V_17 [ V_42 ] . V_31 ) ;
else
V_5 -> V_51 = V_29 ;
V_5 -> V_57 [ V_42 ] . V_35 = V_35 ;
if ( V_43 )
V_5 -> V_57 [ V_42 ] . V_58 = V_17 ;
V_37 = V_5 -> V_59 & ( V_5 -> V_49 . V_50 - 1 ) ;
V_5 -> V_49 . V_37 -> V_60 [ V_37 ] = F_22 ( V_26 -> V_2 , V_42 ) ;
F_39 ( V_5 -> V_61 ) ;
V_5 -> V_59 ++ ;
V_5 -> V_49 . V_37 -> V_62 = F_22 ( V_26 -> V_2 , V_5 -> V_59 ) ;
V_5 -> V_63 ++ ;
F_34 ( L_2 , V_42 , V_5 ) ;
F_28 ( V_5 ) ;
if ( F_27 ( V_5 -> V_63 == ( 1 << 16 ) - 1 ) )
F_40 ( V_26 ) ;
return 0 ;
V_55:
V_41 = V_29 ;
V_29 = V_42 ;
for ( V_36 = 0 ; V_36 < V_27 ; V_36 ++ ) {
if ( V_29 == V_41 )
break;
F_12 ( V_5 , & V_17 [ V_29 ] ) ;
V_29 = F_13 ( V_26 -> V_2 , V_5 -> V_49 . V_17 [ V_29 ] . V_31 ) ;
}
V_5 -> V_5 . V_52 += V_27 ;
if ( V_43 )
F_35 ( V_17 ) ;
F_28 ( V_5 ) ;
return - V_45 ;
}
int F_41 ( struct V_25 * V_26 ,
struct V_8 * V_32 [] ,
unsigned int V_33 ,
unsigned int V_34 ,
void * V_35 ,
T_4 V_28 )
{
unsigned int V_29 , V_27 = 0 ;
for ( V_29 = 0 ; V_29 < V_33 + V_34 ; V_29 ++ ) {
struct V_8 * V_9 ;
for ( V_9 = V_32 [ V_29 ] ; V_9 ; V_9 = F_36 ( V_9 ) )
V_27 ++ ;
}
return F_23 ( V_26 , V_32 , V_27 , V_33 , V_34 , V_35 , V_28 ) ;
}
int F_42 ( struct V_25 * V_5 ,
struct V_8 * V_9 , unsigned int V_50 ,
void * V_35 ,
T_4 V_28 )
{
return F_23 ( V_5 , & V_9 , V_50 , 1 , 0 , V_35 , V_28 ) ;
}
int F_43 ( struct V_25 * V_5 ,
struct V_8 * V_9 , unsigned int V_50 ,
void * V_35 ,
T_4 V_28 )
{
return F_23 ( V_5 , & V_9 , V_50 , 0 , 1 , V_35 , V_28 ) ;
}
bool F_44 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_64 , V_65 ;
bool V_66 ;
F_25 ( V_5 ) ;
F_45 ( V_5 -> V_61 ) ;
V_65 = V_5 -> V_59 - V_5 -> V_63 ;
V_64 = V_5 -> V_59 ;
V_5 -> V_63 = 0 ;
#ifdef F_29
if ( V_5 -> V_47 ) {
F_31 ( F_32 ( F_33 ( F_30 () ,
V_5 -> V_48 ) ) > 100 ) ;
}
V_5 -> V_47 = false ;
#endif
if ( V_5 -> V_67 ) {
V_66 = F_46 ( F_13 ( V_26 -> V_2 , F_47 ( & V_5 -> V_49 ) ) ,
V_64 , V_65 ) ;
} else {
V_66 = ! ( V_5 -> V_49 . V_68 -> V_18 & F_22 ( V_26 -> V_2 , V_69 ) ) ;
}
F_28 ( V_5 ) ;
return V_66 ;
}
bool F_48 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( F_27 ( V_5 -> V_44 ) )
return false ;
if ( ! V_5 -> V_53 ( V_26 ) ) {
V_5 -> V_44 = true ;
return false ;
}
return true ;
}
bool F_40 ( struct V_25 * V_5 )
{
if ( F_44 ( V_5 ) )
return F_48 ( V_5 ) ;
return true ;
}
static void F_49 ( struct V_4 * V_5 , unsigned int V_42 )
{
unsigned int V_29 , V_70 ;
T_6 V_71 = F_22 ( V_5 -> V_5 . V_2 , V_56 ) ;
V_5 -> V_57 [ V_42 ] . V_35 = NULL ;
V_29 = V_42 ;
while ( V_5 -> V_49 . V_17 [ V_29 ] . V_18 & V_71 ) {
F_12 ( V_5 , & V_5 -> V_49 . V_17 [ V_29 ] ) ;
V_29 = F_13 ( V_5 -> V_5 . V_2 , V_5 -> V_49 . V_17 [ V_29 ] . V_31 ) ;
V_5 -> V_5 . V_52 ++ ;
}
F_12 ( V_5 , & V_5 -> V_49 . V_17 [ V_29 ] ) ;
V_5 -> V_49 . V_17 [ V_29 ] . V_31 = F_22 ( V_5 -> V_5 . V_2 , V_5 -> V_51 ) ;
V_5 -> V_51 = V_42 ;
V_5 -> V_5 . V_52 ++ ;
if ( V_5 -> V_57 [ V_42 ] . V_58 ) {
struct V_16 * V_58 = V_5 -> V_57 [ V_42 ] . V_58 ;
T_7 V_21 = F_16 ( V_5 -> V_5 . V_2 , V_5 -> V_49 . V_17 [ V_42 ] . V_21 ) ;
F_26 ( ! ( V_5 -> V_49 . V_17 [ V_42 ] . V_18 &
F_22 ( V_5 -> V_5 . V_2 , V_19 ) ) ) ;
F_26 ( V_21 == 0 || V_21 % sizeof( struct V_16 ) ) ;
for ( V_70 = 0 ; V_70 < V_21 / sizeof( struct V_16 ) ; V_70 ++ )
F_12 ( V_5 , & V_58 [ V_70 ] ) ;
F_35 ( V_5 -> V_57 [ V_42 ] . V_58 ) ;
V_5 -> V_57 [ V_42 ] . V_58 = NULL ;
}
}
static inline bool F_50 ( const struct V_4 * V_5 )
{
return V_5 -> V_72 != F_13 ( V_5 -> V_5 . V_2 , V_5 -> V_49 . V_68 -> V_62 ) ;
}
void * F_51 ( struct V_25 * V_26 , unsigned int * V_21 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
void * V_73 ;
unsigned int V_29 ;
T_3 V_74 ;
F_25 ( V_5 ) ;
if ( F_27 ( V_5 -> V_44 ) ) {
F_28 ( V_5 ) ;
return NULL ;
}
if ( ! F_50 ( V_5 ) ) {
F_34 ( L_3 ) ;
F_28 ( V_5 ) ;
return NULL ;
}
F_52 ( V_5 -> V_61 ) ;
V_74 = ( V_5 -> V_72 & ( V_5 -> V_49 . V_50 - 1 ) ) ;
V_29 = F_16 ( V_26 -> V_2 , V_5 -> V_49 . V_68 -> V_60 [ V_74 ] . V_75 ) ;
* V_21 = F_16 ( V_26 -> V_2 , V_5 -> V_49 . V_68 -> V_60 [ V_74 ] . V_21 ) ;
if ( F_27 ( V_29 >= V_5 -> V_49 . V_50 ) ) {
F_53 ( V_5 , L_4 , V_29 ) ;
return NULL ;
}
if ( F_27 ( ! V_5 -> V_57 [ V_29 ] . V_35 ) ) {
F_53 ( V_5 , L_5 , V_29 ) ;
return NULL ;
}
V_73 = V_5 -> V_57 [ V_29 ] . V_35 ;
F_49 ( V_5 , V_29 ) ;
V_5 -> V_72 ++ ;
if ( ! ( V_5 -> V_76 & V_77 ) )
F_54 ( V_5 -> V_61 ,
& F_55 ( & V_5 -> V_49 ) ,
F_22 ( V_26 -> V_2 , V_5 -> V_72 ) ) ;
#ifdef F_29
V_5 -> V_47 = false ;
#endif
F_28 ( V_5 ) ;
return V_73 ;
}
void F_56 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( ! ( V_5 -> V_76 & V_77 ) ) {
V_5 -> V_76 |= V_77 ;
if ( ! V_5 -> V_67 )
V_5 -> V_49 . V_37 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_76 ) ;
}
}
unsigned F_57 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_72 ;
F_25 ( V_5 ) ;
if ( V_5 -> V_76 & V_77 ) {
V_5 -> V_76 &= ~ V_77 ;
if ( ! V_5 -> V_67 )
V_5 -> V_49 . V_37 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_76 ) ;
}
F_55 ( & V_5 -> V_49 ) = F_22 ( V_26 -> V_2 , V_72 = V_5 -> V_72 ) ;
F_28 ( V_5 ) ;
return V_72 ;
}
bool F_58 ( struct V_25 * V_26 , unsigned V_72 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_45 ( V_5 -> V_61 ) ;
return ( T_3 ) V_72 != F_13 ( V_26 -> V_2 , V_5 -> V_49 . V_68 -> V_62 ) ;
}
bool F_59 ( struct V_25 * V_26 )
{
unsigned V_72 = F_57 ( V_26 ) ;
return ! F_58 ( V_26 , V_72 ) ;
}
bool F_60 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_78 ;
F_25 ( V_5 ) ;
if ( V_5 -> V_76 & V_77 ) {
V_5 -> V_76 &= ~ V_77 ;
if ( ! V_5 -> V_67 )
V_5 -> V_49 . V_37 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_76 ) ;
}
V_78 = ( T_3 ) ( V_5 -> V_59 - V_5 -> V_72 ) * 3 / 4 ;
F_54 ( V_5 -> V_61 ,
& F_55 ( & V_5 -> V_49 ) ,
F_22 ( V_26 -> V_2 , V_5 -> V_72 + V_78 ) ) ;
if ( F_27 ( ( T_3 ) ( F_13 ( V_26 -> V_2 , V_5 -> V_49 . V_68 -> V_62 ) - V_5 -> V_72 ) > V_78 ) ) {
F_28 ( V_5 ) ;
return false ;
}
F_28 ( V_5 ) ;
return true ;
}
void * F_61 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
unsigned int V_29 ;
void * V_79 ;
F_25 ( V_5 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_49 . V_50 ; V_29 ++ ) {
if ( ! V_5 -> V_57 [ V_29 ] . V_35 )
continue;
V_79 = V_5 -> V_57 [ V_29 ] . V_35 ;
F_49 ( V_5 , V_29 ) ;
V_5 -> V_59 -- ;
V_5 -> V_49 . V_37 -> V_62 = F_22 ( V_26 -> V_2 , V_5 -> V_59 ) ;
F_28 ( V_5 ) ;
return V_79 ;
}
F_26 ( V_5 -> V_5 . V_52 != V_5 -> V_49 . V_50 ) ;
F_28 ( V_5 ) ;
return NULL ;
}
T_8 F_62 ( int V_80 , void * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( ! F_50 ( V_5 ) ) {
F_34 ( L_6 , V_5 ) ;
return V_81 ;
}
if ( F_27 ( V_5 -> V_44 ) )
return V_82 ;
F_34 ( L_7 , V_5 , V_5 -> V_5 . V_83 ) ;
if ( V_5 -> V_5 . V_83 )
V_5 -> V_5 . V_83 ( & V_5 -> V_5 ) ;
return V_82 ;
}
struct V_25 * F_63 ( unsigned int V_84 ,
struct V_49 V_49 ,
struct V_1 * V_2 ,
bool V_61 ,
bool (* V_53)( struct V_25 * ) ,
void (* V_83)( struct V_25 * ) ,
const char * V_85 )
{
unsigned int V_29 ;
struct V_4 * V_5 ;
V_5 = F_21 ( sizeof( * V_5 ) + V_49 . V_50 * sizeof( struct V_86 ) ,
V_87 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_49 = V_49 ;
V_5 -> V_5 . V_83 = V_83 ;
V_5 -> V_5 . V_2 = V_2 ;
V_5 -> V_5 . V_85 = V_85 ;
V_5 -> V_5 . V_52 = V_49 . V_50 ;
V_5 -> V_5 . V_84 = V_84 ;
V_5 -> V_88 = false ;
V_5 -> V_89 = 0 ;
V_5 -> V_90 = 0 ;
V_5 -> V_53 = V_53 ;
V_5 -> V_61 = V_61 ;
V_5 -> V_44 = false ;
V_5 -> V_72 = 0 ;
V_5 -> V_76 = 0 ;
V_5 -> V_59 = 0 ;
V_5 -> V_63 = 0 ;
F_64 ( & V_5 -> V_5 . V_91 , & V_2 -> V_92 ) ;
#ifdef F_29
V_5 -> V_93 = false ;
V_5 -> V_47 = false ;
#endif
V_5 -> V_43 = F_65 ( V_2 , V_94 ) ;
V_5 -> V_67 = F_65 ( V_2 , V_95 ) ;
if ( ! V_83 ) {
V_5 -> V_76 |= V_77 ;
if ( ! V_5 -> V_67 )
V_5 -> V_49 . V_37 -> V_18 = F_22 ( V_2 , V_5 -> V_76 ) ;
}
V_5 -> V_51 = 0 ;
for ( V_29 = 0 ; V_29 < V_49 . V_50 - 1 ; V_29 ++ )
V_5 -> V_49 . V_17 [ V_29 ] . V_31 = F_22 ( V_2 , V_29 + 1 ) ;
memset ( V_5 -> V_57 , 0 , V_49 . V_50 * sizeof( struct V_86 ) ) ;
return & V_5 -> V_5 ;
}
static void * F_66 ( struct V_1 * V_2 , T_2 V_15 ,
T_1 * V_96 , T_4 V_97 )
{
if ( F_1 ( V_2 ) ) {
return F_67 ( V_2 -> V_6 . V_7 , V_15 ,
V_96 , V_97 ) ;
} else {
void * V_98 = F_68 ( F_69 ( V_15 ) , V_97 ) ;
if ( V_98 ) {
T_9 V_99 = F_10 ( V_98 ) ;
* V_96 = ( T_1 ) V_99 ;
if ( F_70 ( * V_96 != V_99 ) ) {
F_71 ( V_98 , F_69 ( V_15 ) ) ;
return NULL ;
}
}
return V_98 ;
}
}
static void F_72 ( struct V_1 * V_2 , T_2 V_15 ,
void * V_98 , T_1 V_96 )
{
if ( F_1 ( V_2 ) ) {
F_73 ( V_2 -> V_6 . V_7 , V_15 , V_98 , V_96 ) ;
} else {
F_71 ( V_98 , F_69 ( V_15 ) ) ;
}
}
struct V_25 * F_74 (
unsigned int V_84 ,
unsigned int V_50 ,
unsigned int V_100 ,
struct V_1 * V_2 ,
bool V_61 ,
bool V_101 ,
bool (* V_53)( struct V_25 * ) ,
void (* V_83)( struct V_25 * ) ,
const char * V_85 )
{
struct V_25 * V_5 ;
void * V_98 = NULL ;
T_1 V_102 ;
T_2 V_90 ;
struct V_49 V_49 ;
if ( V_50 & ( V_50 - 1 ) ) {
F_75 ( & V_2 -> V_6 , L_8 , V_50 ) ;
return NULL ;
}
for (; V_50 && F_76 ( V_50 , V_100 ) > V_103 ; V_50 /= 2 ) {
V_98 = F_66 ( V_2 , F_76 ( V_50 , V_100 ) ,
& V_102 ,
V_87 | V_104 | V_105 ) ;
if ( V_98 )
break;
}
if ( ! V_50 )
return NULL ;
if ( ! V_98 ) {
V_98 = F_66 ( V_2 , F_76 ( V_50 , V_100 ) ,
& V_102 , V_87 | V_105 ) ;
}
if ( ! V_98 )
return NULL ;
V_90 = F_76 ( V_50 , V_100 ) ;
F_77 ( & V_49 , V_50 , V_98 , V_100 ) ;
V_5 = F_63 ( V_84 , V_49 , V_2 , V_61 ,
V_53 , V_83 , V_85 ) ;
if ( ! V_5 ) {
F_72 ( V_2 , V_90 , V_98 ,
V_102 ) ;
return NULL ;
}
F_24 ( V_5 ) -> V_89 = V_102 ;
F_24 ( V_5 ) -> V_90 = V_90 ;
F_24 ( V_5 ) -> V_88 = true ;
return V_5 ;
}
struct V_25 * F_78 ( unsigned int V_84 ,
unsigned int V_50 ,
unsigned int V_100 ,
struct V_1 * V_2 ,
bool V_61 ,
void * V_106 ,
bool (* V_53)( struct V_25 * V_5 ) ,
void (* V_83)( struct V_25 * V_5 ) ,
const char * V_85 )
{
struct V_49 V_49 ;
F_77 ( & V_49 , V_50 , V_106 , V_100 ) ;
return F_63 ( V_84 , V_49 , V_2 , V_61 ,
V_53 , V_83 , V_85 ) ;
}
void F_79 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( V_5 -> V_88 ) {
F_72 ( V_5 -> V_5 . V_2 , V_5 -> V_90 ,
V_5 -> V_49 . V_17 , V_5 -> V_89 ) ;
}
F_80 ( & V_26 -> V_91 ) ;
F_35 ( V_5 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
for ( V_29 = V_107 ; V_29 < V_108 ; V_29 ++ ) {
switch ( V_29 ) {
case V_94 :
break;
case V_95 :
break;
case V_109 :
break;
case V_110 :
break;
default:
F_82 ( V_2 , V_29 ) ;
}
}
}
unsigned int F_83 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
return V_5 -> V_49 . V_50 ;
}
bool F_84 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
return V_5 -> V_44 ;
}
void F_85 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
F_86 (_vq, &dev->vqs, list) {
struct V_4 * V_5 = F_24 ( V_26 ) ;
V_5 -> V_44 = true ;
}
}
T_1 F_87 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_88 ) ;
return V_5 -> V_89 ;
}
T_1 F_88 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_88 ) ;
return V_5 -> V_89 +
( ( char * ) V_5 -> V_49 . V_37 - ( char * ) V_5 -> V_49 . V_17 ) ;
}
T_1 F_89 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_88 ) ;
return V_5 -> V_89 +
( ( char * ) V_5 -> V_49 . V_68 - ( char * ) V_5 -> V_49 . V_17 ) ;
}
const struct V_49 * F_90 ( struct V_25 * V_5 )
{
return & F_24 ( V_5 ) -> V_49 ;
}
