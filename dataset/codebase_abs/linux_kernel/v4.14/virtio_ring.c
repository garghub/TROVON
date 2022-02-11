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
void * V_36 ,
T_4 V_28 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
unsigned int V_29 , V_37 , V_38 , V_39 , V_40 ( V_41 ) , V_42 ;
int V_43 ;
bool V_44 ;
F_25 ( V_5 ) ;
F_26 ( V_35 == NULL ) ;
F_26 ( V_36 && V_5 -> V_44 ) ;
if ( F_27 ( V_5 -> V_45 ) ) {
F_28 ( V_5 ) ;
return - V_46 ;
}
#ifdef F_29
{
T_5 V_47 = F_30 () ;
if ( V_5 -> V_48 )
F_31 ( F_32 ( F_33 ( V_47 , V_5 -> V_49 ) )
> 100 ) ;
V_5 -> V_49 = V_47 ;
V_5 -> V_48 = true ;
}
#endif
F_26 ( V_27 == 0 ) ;
V_43 = V_5 -> V_50 ;
if ( V_5 -> V_44 && V_27 > 1 && V_5 -> V_5 . V_51 )
V_17 = F_20 ( V_26 , V_27 , V_28 ) ;
else {
V_17 = NULL ;
F_34 ( V_27 > V_5 -> V_52 . V_53 && ! V_5 -> V_44 ) ;
}
if ( V_17 ) {
V_44 = true ;
V_29 = 0 ;
V_39 = 1 ;
} else {
V_44 = false ;
V_17 = V_5 -> V_52 . V_17 ;
V_29 = V_43 ;
V_39 = V_27 ;
}
if ( V_5 -> V_5 . V_51 < V_39 ) {
F_35 ( L_1 ,
V_39 , V_5 -> V_5 . V_51 ) ;
if ( V_33 )
V_5 -> V_54 ( & V_5 -> V_5 ) ;
if ( V_44 )
F_36 ( V_17 ) ;
F_28 ( V_5 ) ;
return - V_55 ;
}
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
for ( V_9 = V_32 [ V_37 ] ; V_9 ; V_9 = F_37 ( V_9 ) ) {
T_1 V_20 = F_5 ( V_5 , V_9 , V_24 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_56;
V_17 [ V_29 ] . V_18 = F_22 ( V_26 -> V_2 , V_57 ) ;
V_17 [ V_29 ] . V_20 = F_38 ( V_26 -> V_2 , V_20 ) ;
V_17 [ V_29 ] . V_21 = F_39 ( V_26 -> V_2 , V_9 -> V_13 ) ;
V_41 = V_29 ;
V_29 = F_13 ( V_26 -> V_2 , V_17 [ V_29 ] . V_31 ) ;
}
}
for (; V_37 < ( V_33 + V_34 ) ; V_37 ++ ) {
for ( V_9 = V_32 [ V_37 ] ; V_9 ; V_9 = F_37 ( V_9 ) ) {
T_1 V_20 = F_5 ( V_5 , V_9 , V_23 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_56;
V_17 [ V_29 ] . V_18 = F_22 ( V_26 -> V_2 , V_57 | V_22 ) ;
V_17 [ V_29 ] . V_20 = F_38 ( V_26 -> V_2 , V_20 ) ;
V_17 [ V_29 ] . V_21 = F_39 ( V_26 -> V_2 , V_9 -> V_13 ) ;
V_41 = V_29 ;
V_29 = F_13 ( V_26 -> V_2 , V_17 [ V_29 ] . V_31 ) ;
}
}
V_17 [ V_41 ] . V_18 &= F_22 ( V_26 -> V_2 , ~ V_57 ) ;
if ( V_44 ) {
T_1 V_20 = F_9 (
V_5 , V_17 , V_27 * sizeof( struct V_16 ) ,
V_24 ) ;
if ( F_18 ( V_5 , V_20 ) )
goto V_56;
V_5 -> V_52 . V_17 [ V_43 ] . V_18 = F_22 ( V_26 -> V_2 , V_19 ) ;
V_5 -> V_52 . V_17 [ V_43 ] . V_20 = F_38 ( V_26 -> V_2 , V_20 ) ;
V_5 -> V_52 . V_17 [ V_43 ] . V_21 = F_39 ( V_26 -> V_2 , V_27 * sizeof( struct V_16 ) ) ;
}
V_5 -> V_5 . V_51 -= V_39 ;
if ( V_44 )
V_5 -> V_50 = F_13 ( V_26 -> V_2 , V_5 -> V_52 . V_17 [ V_43 ] . V_31 ) ;
else
V_5 -> V_50 = V_29 ;
V_5 -> V_58 [ V_43 ] . V_35 = V_35 ;
if ( V_44 )
V_5 -> V_58 [ V_43 ] . V_59 = V_17 ;
else
V_5 -> V_58 [ V_43 ] . V_59 = V_36 ;
V_38 = V_5 -> V_60 & ( V_5 -> V_52 . V_53 - 1 ) ;
V_5 -> V_52 . V_38 -> V_61 [ V_38 ] = F_22 ( V_26 -> V_2 , V_43 ) ;
F_40 ( V_5 -> V_62 ) ;
V_5 -> V_60 ++ ;
V_5 -> V_52 . V_38 -> V_63 = F_22 ( V_26 -> V_2 , V_5 -> V_60 ) ;
V_5 -> V_64 ++ ;
F_35 ( L_2 , V_43 , V_5 ) ;
F_28 ( V_5 ) ;
if ( F_27 ( V_5 -> V_64 == ( 1 << 16 ) - 1 ) )
F_41 ( V_26 ) ;
return 0 ;
V_56:
V_42 = V_29 ;
V_29 = V_43 ;
for ( V_37 = 0 ; V_37 < V_27 ; V_37 ++ ) {
if ( V_29 == V_42 )
break;
F_12 ( V_5 , & V_17 [ V_29 ] ) ;
V_29 = F_13 ( V_26 -> V_2 , V_5 -> V_52 . V_17 [ V_29 ] . V_31 ) ;
}
V_5 -> V_5 . V_51 += V_27 ;
if ( V_44 )
F_36 ( V_17 ) ;
F_28 ( V_5 ) ;
return - V_46 ;
}
int F_42 ( struct V_25 * V_26 ,
struct V_8 * V_32 [] ,
unsigned int V_33 ,
unsigned int V_34 ,
void * V_35 ,
T_4 V_28 )
{
unsigned int V_29 , V_27 = 0 ;
for ( V_29 = 0 ; V_29 < V_33 + V_34 ; V_29 ++ ) {
struct V_8 * V_9 ;
for ( V_9 = V_32 [ V_29 ] ; V_9 ; V_9 = F_37 ( V_9 ) )
V_27 ++ ;
}
return F_23 ( V_26 , V_32 , V_27 , V_33 , V_34 ,
V_35 , NULL , V_28 ) ;
}
int F_43 ( struct V_25 * V_5 ,
struct V_8 * V_9 , unsigned int V_53 ,
void * V_35 ,
T_4 V_28 )
{
return F_23 ( V_5 , & V_9 , V_53 , 1 , 0 , V_35 , NULL , V_28 ) ;
}
int F_44 ( struct V_25 * V_5 ,
struct V_8 * V_9 , unsigned int V_53 ,
void * V_35 ,
T_4 V_28 )
{
return F_23 ( V_5 , & V_9 , V_53 , 0 , 1 , V_35 , NULL , V_28 ) ;
}
int F_45 ( struct V_25 * V_5 ,
struct V_8 * V_9 , unsigned int V_53 ,
void * V_35 ,
void * V_36 ,
T_4 V_28 )
{
return F_23 ( V_5 , & V_9 , V_53 , 0 , 1 , V_35 , V_36 , V_28 ) ;
}
bool F_46 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_65 , V_66 ;
bool V_67 ;
F_25 ( V_5 ) ;
F_47 ( V_5 -> V_62 ) ;
V_66 = V_5 -> V_60 - V_5 -> V_64 ;
V_65 = V_5 -> V_60 ;
V_5 -> V_64 = 0 ;
#ifdef F_29
if ( V_5 -> V_48 ) {
F_31 ( F_32 ( F_33 ( F_30 () ,
V_5 -> V_49 ) ) > 100 ) ;
}
V_5 -> V_48 = false ;
#endif
if ( V_5 -> V_68 ) {
V_67 = F_48 ( F_13 ( V_26 -> V_2 , F_49 ( & V_5 -> V_52 ) ) ,
V_65 , V_66 ) ;
} else {
V_67 = ! ( V_5 -> V_52 . V_69 -> V_18 & F_22 ( V_26 -> V_2 , V_70 ) ) ;
}
F_28 ( V_5 ) ;
return V_67 ;
}
bool F_50 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( F_27 ( V_5 -> V_45 ) )
return false ;
if ( ! V_5 -> V_54 ( V_26 ) ) {
V_5 -> V_45 = true ;
return false ;
}
return true ;
}
bool F_41 ( struct V_25 * V_5 )
{
if ( F_46 ( V_5 ) )
return F_50 ( V_5 ) ;
return true ;
}
static void F_51 ( struct V_4 * V_5 , unsigned int V_43 ,
void * * V_36 )
{
unsigned int V_29 , V_71 ;
T_6 V_72 = F_22 ( V_5 -> V_5 . V_2 , V_57 ) ;
V_5 -> V_58 [ V_43 ] . V_35 = NULL ;
V_29 = V_43 ;
while ( V_5 -> V_52 . V_17 [ V_29 ] . V_18 & V_72 ) {
F_12 ( V_5 , & V_5 -> V_52 . V_17 [ V_29 ] ) ;
V_29 = F_13 ( V_5 -> V_5 . V_2 , V_5 -> V_52 . V_17 [ V_29 ] . V_31 ) ;
V_5 -> V_5 . V_51 ++ ;
}
F_12 ( V_5 , & V_5 -> V_52 . V_17 [ V_29 ] ) ;
V_5 -> V_52 . V_17 [ V_29 ] . V_31 = F_22 ( V_5 -> V_5 . V_2 , V_5 -> V_50 ) ;
V_5 -> V_50 = V_43 ;
V_5 -> V_5 . V_51 ++ ;
if ( V_5 -> V_44 ) {
struct V_16 * V_59 = V_5 -> V_58 [ V_43 ] . V_59 ;
T_7 V_21 ;
if ( ! V_59 )
return;
V_21 = F_16 ( V_5 -> V_5 . V_2 , V_5 -> V_52 . V_17 [ V_43 ] . V_21 ) ;
F_26 ( ! ( V_5 -> V_52 . V_17 [ V_43 ] . V_18 &
F_22 ( V_5 -> V_5 . V_2 , V_19 ) ) ) ;
F_26 ( V_21 == 0 || V_21 % sizeof( struct V_16 ) ) ;
for ( V_71 = 0 ; V_71 < V_21 / sizeof( struct V_16 ) ; V_71 ++ )
F_12 ( V_5 , & V_59 [ V_71 ] ) ;
F_36 ( V_59 ) ;
V_5 -> V_58 [ V_43 ] . V_59 = NULL ;
} else if ( V_36 ) {
* V_36 = V_5 -> V_58 [ V_43 ] . V_59 ;
}
}
static inline bool F_52 ( const struct V_4 * V_5 )
{
return V_5 -> V_73 != F_13 ( V_5 -> V_5 . V_2 , V_5 -> V_52 . V_69 -> V_63 ) ;
}
void * F_53 ( struct V_25 * V_26 , unsigned int * V_21 ,
void * * V_36 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
void * V_74 ;
unsigned int V_29 ;
T_3 V_75 ;
F_25 ( V_5 ) ;
if ( F_27 ( V_5 -> V_45 ) ) {
F_28 ( V_5 ) ;
return NULL ;
}
if ( ! F_52 ( V_5 ) ) {
F_35 ( L_3 ) ;
F_28 ( V_5 ) ;
return NULL ;
}
F_54 ( V_5 -> V_62 ) ;
V_75 = ( V_5 -> V_73 & ( V_5 -> V_52 . V_53 - 1 ) ) ;
V_29 = F_16 ( V_26 -> V_2 , V_5 -> V_52 . V_69 -> V_61 [ V_75 ] . V_76 ) ;
* V_21 = F_16 ( V_26 -> V_2 , V_5 -> V_52 . V_69 -> V_61 [ V_75 ] . V_21 ) ;
if ( F_27 ( V_29 >= V_5 -> V_52 . V_53 ) ) {
F_55 ( V_5 , L_4 , V_29 ) ;
return NULL ;
}
if ( F_27 ( ! V_5 -> V_58 [ V_29 ] . V_35 ) ) {
F_55 ( V_5 , L_5 , V_29 ) ;
return NULL ;
}
V_74 = V_5 -> V_58 [ V_29 ] . V_35 ;
F_51 ( V_5 , V_29 , V_36 ) ;
V_5 -> V_73 ++ ;
if ( ! ( V_5 -> V_77 & V_78 ) )
F_56 ( V_5 -> V_62 ,
& F_57 ( & V_5 -> V_52 ) ,
F_22 ( V_26 -> V_2 , V_5 -> V_73 ) ) ;
#ifdef F_29
V_5 -> V_48 = false ;
#endif
F_28 ( V_5 ) ;
return V_74 ;
}
void * F_58 ( struct V_25 * V_26 , unsigned int * V_21 )
{
return F_53 ( V_26 , V_21 , NULL ) ;
}
void F_59 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( ! ( V_5 -> V_77 & V_78 ) ) {
V_5 -> V_77 |= V_78 ;
if ( ! V_5 -> V_68 )
V_5 -> V_52 . V_38 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_77 ) ;
}
}
unsigned F_60 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_73 ;
F_25 ( V_5 ) ;
if ( V_5 -> V_77 & V_78 ) {
V_5 -> V_77 &= ~ V_78 ;
if ( ! V_5 -> V_68 )
V_5 -> V_52 . V_38 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_77 ) ;
}
F_57 ( & V_5 -> V_52 ) = F_22 ( V_26 -> V_2 , V_73 = V_5 -> V_73 ) ;
F_28 ( V_5 ) ;
return V_73 ;
}
bool F_61 ( struct V_25 * V_26 , unsigned V_73 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_47 ( V_5 -> V_62 ) ;
return ( T_3 ) V_73 != F_13 ( V_26 -> V_2 , V_5 -> V_52 . V_69 -> V_63 ) ;
}
bool F_62 ( struct V_25 * V_26 )
{
unsigned V_73 = F_60 ( V_26 ) ;
return ! F_61 ( V_26 , V_73 ) ;
}
bool F_63 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
T_3 V_79 ;
F_25 ( V_5 ) ;
if ( V_5 -> V_77 & V_78 ) {
V_5 -> V_77 &= ~ V_78 ;
if ( ! V_5 -> V_68 )
V_5 -> V_52 . V_38 -> V_18 = F_22 ( V_26 -> V_2 , V_5 -> V_77 ) ;
}
V_79 = ( T_3 ) ( V_5 -> V_60 - V_5 -> V_73 ) * 3 / 4 ;
F_56 ( V_5 -> V_62 ,
& F_57 ( & V_5 -> V_52 ) ,
F_22 ( V_26 -> V_2 , V_5 -> V_73 + V_79 ) ) ;
if ( F_27 ( ( T_3 ) ( F_13 ( V_26 -> V_2 , V_5 -> V_52 . V_69 -> V_63 ) - V_5 -> V_73 ) > V_79 ) ) {
F_28 ( V_5 ) ;
return false ;
}
F_28 ( V_5 ) ;
return true ;
}
void * F_64 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
unsigned int V_29 ;
void * V_80 ;
F_25 ( V_5 ) ;
for ( V_29 = 0 ; V_29 < V_5 -> V_52 . V_53 ; V_29 ++ ) {
if ( ! V_5 -> V_58 [ V_29 ] . V_35 )
continue;
V_80 = V_5 -> V_58 [ V_29 ] . V_35 ;
F_51 ( V_5 , V_29 , NULL ) ;
V_5 -> V_60 -- ;
V_5 -> V_52 . V_38 -> V_63 = F_22 ( V_26 -> V_2 , V_5 -> V_60 ) ;
F_28 ( V_5 ) ;
return V_80 ;
}
F_26 ( V_5 -> V_5 . V_51 != V_5 -> V_52 . V_53 ) ;
F_28 ( V_5 ) ;
return NULL ;
}
T_8 F_65 ( int V_81 , void * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( ! F_52 ( V_5 ) ) {
F_35 ( L_6 , V_5 ) ;
return V_82 ;
}
if ( F_27 ( V_5 -> V_45 ) )
return V_83 ;
F_35 ( L_7 , V_5 , V_5 -> V_5 . V_84 ) ;
if ( V_5 -> V_5 . V_84 )
V_5 -> V_5 . V_84 ( & V_5 -> V_5 ) ;
return V_83 ;
}
struct V_25 * F_66 ( unsigned int V_85 ,
struct V_52 V_52 ,
struct V_1 * V_2 ,
bool V_62 ,
bool V_86 ,
bool (* V_54)( struct V_25 * ) ,
void (* V_84)( struct V_25 * ) ,
const char * V_87 )
{
unsigned int V_29 ;
struct V_4 * V_5 ;
V_5 = F_21 ( sizeof( * V_5 ) + V_52 . V_53 * sizeof( struct V_88 ) ,
V_89 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_52 = V_52 ;
V_5 -> V_5 . V_84 = V_84 ;
V_5 -> V_5 . V_2 = V_2 ;
V_5 -> V_5 . V_87 = V_87 ;
V_5 -> V_5 . V_51 = V_52 . V_53 ;
V_5 -> V_5 . V_85 = V_85 ;
V_5 -> V_90 = false ;
V_5 -> V_91 = 0 ;
V_5 -> V_92 = 0 ;
V_5 -> V_54 = V_54 ;
V_5 -> V_62 = V_62 ;
V_5 -> V_45 = false ;
V_5 -> V_73 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_60 = 0 ;
V_5 -> V_64 = 0 ;
F_67 ( & V_5 -> V_5 . V_93 , & V_2 -> V_94 ) ;
#ifdef F_29
V_5 -> V_95 = false ;
V_5 -> V_48 = false ;
#endif
V_5 -> V_44 = F_68 ( V_2 , V_96 ) &&
! V_86 ;
V_5 -> V_68 = F_68 ( V_2 , V_97 ) ;
if ( ! V_84 ) {
V_5 -> V_77 |= V_78 ;
if ( ! V_5 -> V_68 )
V_5 -> V_52 . V_38 -> V_18 = F_22 ( V_2 , V_5 -> V_77 ) ;
}
V_5 -> V_50 = 0 ;
for ( V_29 = 0 ; V_29 < V_52 . V_53 - 1 ; V_29 ++ )
V_5 -> V_52 . V_17 [ V_29 ] . V_31 = F_22 ( V_2 , V_29 + 1 ) ;
memset ( V_5 -> V_58 , 0 , V_52 . V_53 * sizeof( struct V_88 ) ) ;
return & V_5 -> V_5 ;
}
static void * F_69 ( struct V_1 * V_2 , T_2 V_15 ,
T_1 * V_98 , T_4 V_99 )
{
if ( F_1 ( V_2 ) ) {
return F_70 ( V_2 -> V_6 . V_7 , V_15 ,
V_98 , V_99 ) ;
} else {
void * V_100 = F_71 ( F_72 ( V_15 ) , V_99 ) ;
if ( V_100 ) {
T_9 V_101 = F_10 ( V_100 ) ;
* V_98 = ( T_1 ) V_101 ;
if ( F_34 ( * V_98 != V_101 ) ) {
F_73 ( V_100 , F_72 ( V_15 ) ) ;
return NULL ;
}
}
return V_100 ;
}
}
static void F_74 ( struct V_1 * V_2 , T_2 V_15 ,
void * V_100 , T_1 V_98 )
{
if ( F_1 ( V_2 ) ) {
F_75 ( V_2 -> V_6 . V_7 , V_15 , V_100 , V_98 ) ;
} else {
F_73 ( V_100 , F_72 ( V_15 ) ) ;
}
}
struct V_25 * F_76 (
unsigned int V_85 ,
unsigned int V_53 ,
unsigned int V_102 ,
struct V_1 * V_2 ,
bool V_62 ,
bool V_103 ,
bool V_86 ,
bool (* V_54)( struct V_25 * ) ,
void (* V_84)( struct V_25 * ) ,
const char * V_87 )
{
struct V_25 * V_5 ;
void * V_100 = NULL ;
T_1 V_104 ;
T_2 V_92 ;
struct V_52 V_52 ;
if ( V_53 & ( V_53 - 1 ) ) {
F_77 ( & V_2 -> V_6 , L_8 , V_53 ) ;
return NULL ;
}
for (; V_53 && F_78 ( V_53 , V_102 ) > V_105 ; V_53 /= 2 ) {
V_100 = F_69 ( V_2 , F_78 ( V_53 , V_102 ) ,
& V_104 ,
V_89 | V_106 | V_107 ) ;
if ( V_100 )
break;
}
if ( ! V_53 )
return NULL ;
if ( ! V_100 ) {
V_100 = F_69 ( V_2 , F_78 ( V_53 , V_102 ) ,
& V_104 , V_89 | V_107 ) ;
}
if ( ! V_100 )
return NULL ;
V_92 = F_78 ( V_53 , V_102 ) ;
F_79 ( & V_52 , V_53 , V_100 , V_102 ) ;
V_5 = F_66 ( V_85 , V_52 , V_2 , V_62 , V_86 ,
V_54 , V_84 , V_87 ) ;
if ( ! V_5 ) {
F_74 ( V_2 , V_92 , V_100 ,
V_104 ) ;
return NULL ;
}
F_24 ( V_5 ) -> V_91 = V_104 ;
F_24 ( V_5 ) -> V_92 = V_92 ;
F_24 ( V_5 ) -> V_90 = true ;
return V_5 ;
}
struct V_25 * F_80 ( unsigned int V_85 ,
unsigned int V_53 ,
unsigned int V_102 ,
struct V_1 * V_2 ,
bool V_62 ,
bool V_86 ,
void * V_108 ,
bool (* V_54)( struct V_25 * V_5 ) ,
void (* V_84)( struct V_25 * V_5 ) ,
const char * V_87 )
{
struct V_52 V_52 ;
F_79 ( & V_52 , V_53 , V_108 , V_102 ) ;
return F_66 ( V_85 , V_52 , V_2 , V_62 , V_86 ,
V_54 , V_84 , V_87 ) ;
}
void F_81 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
if ( V_5 -> V_90 ) {
F_74 ( V_5 -> V_5 . V_2 , V_5 -> V_92 ,
V_5 -> V_52 . V_17 , V_5 -> V_91 ) ;
}
F_82 ( & V_26 -> V_93 ) ;
F_36 ( V_5 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
for ( V_29 = V_109 ; V_29 < V_110 ; V_29 ++ ) {
switch ( V_29 ) {
case V_96 :
break;
case V_97 :
break;
case V_111 :
break;
case V_112 :
break;
default:
F_84 ( V_2 , V_29 ) ;
}
}
}
unsigned int F_85 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
return V_5 -> V_52 . V_53 ;
}
bool F_86 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
return V_5 -> V_45 ;
}
void F_87 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
F_88 (_vq, &dev->vqs, list) {
struct V_4 * V_5 = F_24 ( V_26 ) ;
V_5 -> V_45 = true ;
}
}
T_1 F_89 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_90 ) ;
return V_5 -> V_91 ;
}
T_1 F_90 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_90 ) ;
return V_5 -> V_91 +
( ( char * ) V_5 -> V_52 . V_38 - ( char * ) V_5 -> V_52 . V_17 ) ;
}
T_1 F_91 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_24 ( V_26 ) ;
F_26 ( ! V_5 -> V_90 ) ;
return V_5 -> V_91 +
( ( char * ) V_5 -> V_52 . V_69 - ( char * ) V_5 -> V_52 . V_17 ) ;
}
const struct V_52 * F_92 ( struct V_25 * V_5 )
{
return & F_24 ( V_5 ) -> V_52 ;
}
