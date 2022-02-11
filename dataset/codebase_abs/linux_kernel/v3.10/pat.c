static inline void F_1 ( const char * V_1 )
{
V_2 = 0 ;
F_2 ( V_3 L_1 , V_1 ) ;
}
static int T_1 F_3 ( char * V_4 )
{
F_1 ( L_2 ) ;
return 0 ;
}
static inline void F_1 ( const char * V_1 )
{
( void ) V_1 ;
}
static int T_1 F_4 ( char * V_4 )
{
V_5 = 1 ;
return 0 ;
}
void F_5 ( void )
{
T_2 V_6 ;
bool V_7 = ! V_8 ;
if ( ! V_2 )
return;
if ( ! V_9 ) {
if ( ! V_8 ) {
F_1 ( L_3 ) ;
return;
} else {
F_2 ( V_10 L_4
L_5 ) ;
F_6 () ;
}
}
V_6 = F_7 ( 0 , V_11 ) | F_7 ( 1 , V_12 ) | F_7 ( 2 , V_13 ) | F_7 ( 3 , V_14 ) |
F_7 ( 4 , V_11 ) | F_7 ( 5 , V_12 ) | F_7 ( 6 , V_13 ) | F_7 ( 7 , V_14 ) ;
if ( ! V_8 )
F_8 ( V_15 , V_8 ) ;
F_9 ( V_15 , V_6 ) ;
if ( V_7 )
F_2 ( V_3 L_6 ,
F_10 () , V_8 , V_6 ) ;
}
static unsigned long F_11 ( T_2 V_16 , T_2 V_17 , unsigned long V_18 )
{
if ( V_18 == V_19 ) {
T_3 V_20 ;
V_20 = F_12 ( V_16 , V_17 ) ;
if ( V_20 != V_21 )
return V_22 ;
return V_19 ;
}
return V_18 ;
}
static int
F_13 ( unsigned long V_23 , unsigned long V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
V_27 -> V_28 |= V_23 > V_27 -> V_29 ;
V_27 -> V_30 |= V_24 > 0 ;
V_27 -> V_29 = V_23 + V_24 ;
return V_27 -> V_30 && V_27 -> V_28 ;
}
static int F_14 ( T_4 V_16 , T_4 V_17 )
{
int V_31 = 0 ;
unsigned long V_32 = V_16 >> V_33 ;
unsigned long V_34 = ( V_17 + V_35 - 1 ) >> V_33 ;
struct V_26 V_27 = { V_32 , 0 , 0 } ;
if ( V_32 < V_36 > > V_33 )
V_32 = V_36 >> V_33 ;
if ( V_32 < V_34 ) {
V_31 = F_15 ( V_32 , V_34 - V_32 ,
& V_27 , F_13 ) ;
}
return ( V_31 > 0 ) ? - 1 : ( V_27 . V_30 ? 1 : 0 ) ;
}
static int F_16 ( T_2 V_16 , T_2 V_17 , unsigned long V_18 ,
unsigned long * V_37 )
{
struct V_38 * V_38 ;
T_2 V_39 ;
if ( V_18 == V_40 ) {
F_17 ( 1 ) ;
V_18 = V_22 ;
}
for ( V_39 = ( V_16 >> V_33 ) ; V_39 < ( V_17 >> V_33 ) ; ++ V_39 ) {
unsigned long type ;
V_38 = F_18 ( V_39 ) ;
type = F_19 ( V_38 ) ;
if ( type != - 1 ) {
F_2 ( V_3 L_7 ,
V_16 , V_17 - 1 , type , V_18 ) ;
if ( V_37 )
* V_37 = type ;
return - V_41 ;
}
}
if ( V_37 )
* V_37 = V_18 ;
for ( V_39 = ( V_16 >> V_33 ) ; V_39 < ( V_17 >> V_33 ) ; ++ V_39 ) {
V_38 = F_18 ( V_39 ) ;
F_20 ( V_38 , V_18 ) ;
}
return 0 ;
}
static int F_21 ( T_2 V_16 , T_2 V_17 )
{
struct V_38 * V_38 ;
T_2 V_39 ;
for ( V_39 = ( V_16 >> V_33 ) ; V_39 < ( V_17 >> V_33 ) ; ++ V_39 ) {
V_38 = F_18 ( V_39 ) ;
F_20 ( V_38 , - 1 ) ;
}
return 0 ;
}
int F_22 ( T_2 V_16 , T_2 V_17 , unsigned long V_18 ,
unsigned long * V_37 )
{
struct V_42 * V_43 ;
unsigned long V_44 ;
int V_45 ;
int V_46 = 0 ;
F_23 ( V_16 >= V_17 ) ;
if ( ! V_2 ) {
if ( V_37 ) {
if ( V_18 == V_47 )
* V_37 = V_22 ;
else
* V_37 = V_18 & V_48 ;
}
return 0 ;
}
if ( V_49 . V_50 ( V_16 , V_17 ) ) {
if ( V_37 )
* V_37 = V_19 ;
return 0 ;
}
V_44 = F_11 ( V_16 , V_17 , V_18 & V_48 ) ;
if ( V_37 )
* V_37 = V_44 ;
V_45 = F_14 ( V_16 , V_17 ) ;
if ( V_45 == 1 ) {
V_46 = F_16 ( V_16 , V_17 , V_18 , V_37 ) ;
return V_46 ;
} else if ( V_45 < 0 ) {
return - V_51 ;
}
V_43 = F_24 ( sizeof( struct V_42 ) , V_52 ) ;
if ( ! V_43 )
return - V_53 ;
V_43 -> V_16 = V_16 ;
V_43 -> V_17 = V_17 ;
V_43 -> type = V_44 ;
F_25 ( & V_54 ) ;
V_46 = F_26 ( V_43 , V_37 ) ;
if ( V_46 ) {
F_2 ( V_3 L_8 ,
V_16 , V_17 - 1 ,
F_27 ( V_43 -> type ) , F_27 ( V_18 ) ) ;
F_28 ( V_43 ) ;
F_29 ( & V_54 ) ;
return V_46 ;
}
F_29 ( & V_54 ) ;
F_30 ( L_9 ,
V_16 , V_17 - 1 , F_27 ( V_43 -> type ) , F_27 ( V_18 ) ,
V_37 ? F_27 ( * V_37 ) : L_10 ) ;
return V_46 ;
}
int F_31 ( T_2 V_16 , T_2 V_17 )
{
int V_46 = - V_51 ;
int V_45 ;
struct V_42 * V_55 ;
if ( ! V_2 )
return 0 ;
if ( V_49 . V_50 ( V_16 , V_17 ) )
return 0 ;
V_45 = F_14 ( V_16 , V_17 ) ;
if ( V_45 == 1 ) {
V_46 = F_21 ( V_16 , V_17 ) ;
return V_46 ;
} else if ( V_45 < 0 ) {
return - V_51 ;
}
F_25 ( & V_54 ) ;
V_55 = F_32 ( V_16 , V_17 ) ;
F_29 ( & V_54 ) ;
if ( ! V_55 ) {
F_2 ( V_3 L_11 ,
V_56 -> V_57 , V_56 -> V_58 , V_16 , V_17 - 1 ) ;
return - V_51 ;
}
F_28 ( V_55 ) ;
F_30 ( L_12 , V_16 , V_17 - 1 ) ;
return 0 ;
}
static unsigned long F_33 ( T_2 V_59 )
{
int V_60 = V_19 ;
struct V_42 * V_55 ;
if ( V_49 . V_50 ( V_59 , V_59 + V_35 ) )
return V_60 ;
if ( F_14 ( V_59 , V_59 + V_35 ) ) {
struct V_38 * V_38 ;
V_38 = F_18 ( V_59 >> V_33 ) ;
V_60 = F_19 ( V_38 ) ;
if ( V_60 == - 1 )
V_60 = V_19 ;
return V_60 ;
}
F_25 ( & V_54 ) ;
V_55 = F_34 ( V_59 ) ;
if ( V_55 != NULL )
V_60 = V_55 -> type ;
else
V_60 = V_22 ;
F_29 ( & V_54 ) ;
return V_60 ;
}
int F_35 ( T_4 V_16 , T_4 V_17 ,
unsigned long * type )
{
T_4 V_61 = V_17 - V_16 ;
unsigned long V_18 = * type ;
unsigned long V_37 ;
int V_31 ;
F_17 ( F_36 ( V_16 , V_61 ) ) ;
V_31 = F_22 ( V_16 , V_17 , V_18 , & V_37 ) ;
if ( V_31 )
goto V_62;
if ( ! F_37 ( V_16 , V_61 , V_18 , V_37 ) )
goto V_63;
if ( F_38 ( V_16 , V_61 , V_37 ) < 0 )
goto V_63;
* type = V_37 ;
return 0 ;
V_63:
F_31 ( V_16 , V_17 ) ;
V_31 = - V_41 ;
V_62:
return V_31 ;
}
void F_39 ( T_4 V_16 , T_4 V_17 )
{
F_31 ( V_16 , V_17 ) ;
}
T_5 F_40 ( struct V_64 * V_64 , unsigned long V_39 ,
unsigned long V_61 , T_5 V_65 )
{
return V_65 ;
}
static inline int F_41 ( unsigned long V_39 , unsigned long V_61 )
{
return 1 ;
}
static inline int F_41 ( unsigned long V_39 , unsigned long V_61 )
{
T_2 V_66 = ( ( T_2 ) V_39 ) << V_33 ;
T_2 V_67 = V_66 + V_61 ;
T_2 V_68 = V_66 ;
if ( ! V_2 )
return 1 ;
while ( V_68 < V_67 ) {
if ( ! F_42 ( V_39 ) ) {
F_2 ( V_3 L_13 ,
V_56 -> V_57 , V_66 , V_67 - 1 ) ;
return 0 ;
}
V_68 += V_35 ;
V_39 ++ ;
}
return 1 ;
}
int F_43 ( struct V_64 * V_64 , unsigned long V_39 ,
unsigned long V_61 , T_5 * V_65 )
{
unsigned long V_69 = V_19 ;
if ( ! F_41 ( V_39 , V_61 ) )
return 0 ;
if ( V_64 -> V_70 & V_71 )
V_69 = V_22 ;
#ifdef F_44
if ( ! V_2 &&
! ( F_45 ( V_72 ) ||
F_45 ( V_73 ) ||
F_45 ( V_74 ) ||
F_45 ( V_75 ) ) &&
( V_39 << V_33 ) >= F_46 ( V_76 ) ) {
V_69 = V_40 ;
}
#endif
* V_65 = F_47 ( ( F_48 ( * V_65 ) & ~ V_48 ) |
V_69 ) ;
return 1 ;
}
int F_38 ( T_2 V_77 , unsigned long V_61 , unsigned long V_69 )
{
unsigned long V_78 ;
if ( V_77 > F_46 ( V_76 - 1 ) )
return 0 ;
if ( ! F_49 ( V_77 >> V_33 ) )
return 0 ;
V_78 = ( F_46 ( V_76 - 1 ) <= V_77 + V_61 ) ?
F_46 ( V_76 ) - V_77 :
V_61 ;
if ( F_50 ( ( unsigned long ) F_51 ( V_77 ) , V_78 , V_69 ) < 0 ) {
F_2 ( V_3 L_14
L_15 ,
V_56 -> V_57 , V_56 -> V_58 ,
F_27 ( V_69 ) ,
V_77 , ( unsigned long long ) ( V_77 + V_61 - 1 ) ) ;
return - V_51 ;
}
return 0 ;
}
static int F_52 ( T_2 V_59 , unsigned long V_61 , T_5 * V_65 ,
int V_79 )
{
int V_80 = 0 ;
int V_31 ;
unsigned long V_81 = ( F_48 ( * V_65 ) & V_48 ) ;
unsigned long V_69 = V_81 ;
V_80 = F_14 ( V_59 , V_59 + V_61 ) ;
if ( V_80 ) {
if ( ! V_2 )
return 0 ;
V_69 = F_33 ( V_59 ) ;
if ( V_81 != V_69 ) {
F_2 ( V_82 L_16 ,
V_56 -> V_57 , V_56 -> V_58 ,
F_27 ( V_81 ) ,
( unsigned long long ) V_59 ,
( unsigned long long ) ( V_59 + V_61 - 1 ) ,
F_27 ( V_69 ) ) ;
* V_65 = F_47 ( ( F_48 ( * V_65 ) &
( ~ V_48 ) ) |
V_69 ) ;
}
return 0 ;
}
V_31 = F_22 ( V_59 , V_59 + V_61 , V_81 , & V_69 ) ;
if ( V_31 )
return V_31 ;
if ( V_69 != V_81 ) {
if ( V_79 ||
! F_37 ( V_59 , V_61 , V_81 , V_69 ) ) {
F_31 ( V_59 , V_59 + V_61 ) ;
F_2 ( V_10 L_17
L_18 ,
V_56 -> V_57 , V_56 -> V_58 ,
F_27 ( V_81 ) ,
( unsigned long long ) V_59 ,
( unsigned long long ) ( V_59 + V_61 - 1 ) ,
F_27 ( V_69 ) ) ;
return - V_51 ;
}
* V_65 = F_47 ( ( F_48 ( * V_65 ) &
( ~ V_48 ) ) |
V_69 ) ;
}
if ( F_38 ( V_59 , V_61 , V_69 ) < 0 ) {
F_31 ( V_59 , V_59 + V_61 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_53 ( T_2 V_59 , unsigned long V_61 )
{
int V_80 ;
V_80 = F_14 ( V_59 , V_59 + V_61 ) ;
if ( V_80 == 0 )
F_31 ( V_59 , V_59 + V_61 ) ;
}
int F_54 ( struct V_83 * V_84 )
{
T_4 V_59 ;
unsigned long V_85 ;
unsigned long V_86 = V_84 -> V_87 - V_84 -> V_88 ;
T_5 V_89 ;
if ( V_84 -> V_90 & V_91 ) {
if ( F_55 ( V_84 , V_84 -> V_88 , 0 , & V_85 , & V_59 ) ) {
F_17 ( 1 ) ;
return - V_51 ;
}
V_89 = F_47 ( V_85 ) ;
return F_52 ( V_59 , V_86 , & V_89 , 1 ) ;
}
return 0 ;
}
int F_56 ( struct V_83 * V_84 , T_5 * V_85 ,
unsigned long V_39 , unsigned long V_92 , unsigned long V_61 )
{
T_4 V_59 = ( T_4 ) V_39 << V_33 ;
unsigned long V_69 ;
if ( V_92 == V_84 -> V_88 && V_61 == ( V_84 -> V_87 - V_84 -> V_88 ) ) {
int V_31 ;
V_31 = F_52 ( V_59 , V_61 , V_85 , 0 ) ;
if ( ! V_31 )
V_84 -> V_90 |= V_91 ;
return V_31 ;
}
if ( ! V_2 )
return 0 ;
V_69 = F_33 ( V_59 ) ;
while ( V_61 > V_35 ) {
V_61 -= V_35 ;
V_59 += V_35 ;
if ( V_69 != F_33 ( V_59 ) )
return - V_51 ;
}
* V_85 = F_47 ( ( F_48 ( V_84 -> V_93 ) & ( ~ V_48 ) ) |
V_69 ) ;
return 0 ;
}
int F_57 ( struct V_83 * V_84 , T_5 * V_85 ,
unsigned long V_39 )
{
unsigned long V_69 ;
if ( ! V_2 )
return 0 ;
V_69 = F_33 ( ( T_4 ) V_39 << V_33 ) ;
* V_85 = F_47 ( ( F_48 ( V_84 -> V_93 ) & ( ~ V_48 ) ) |
V_69 ) ;
return 0 ;
}
void F_58 ( struct V_83 * V_84 , unsigned long V_39 ,
unsigned long V_61 )
{
T_4 V_59 ;
unsigned long V_85 ;
if ( ! ( V_84 -> V_90 & V_91 ) )
return;
V_59 = ( T_4 ) V_39 << V_33 ;
if ( ! V_59 && ! V_61 ) {
if ( F_55 ( V_84 , V_84 -> V_88 , 0 , & V_85 , & V_59 ) ) {
F_17 ( 1 ) ;
return;
}
V_61 = V_84 -> V_87 - V_84 -> V_88 ;
}
F_53 ( V_59 , V_61 ) ;
V_84 -> V_90 &= ~ V_91 ;
}
T_5 F_59 ( T_5 V_85 )
{
if ( V_2 )
return F_47 ( F_48 ( V_85 ) | V_47 ) ;
else
return F_60 ( V_85 ) ;
}
static struct V_42 * F_61 ( T_6 V_94 )
{
struct V_42 * V_95 ;
int V_31 ;
V_95 = F_24 ( sizeof( struct V_42 ) , V_52 ) ;
if ( ! V_95 )
return NULL ;
F_25 ( & V_54 ) ;
V_31 = F_62 ( V_95 , V_94 ) ;
F_29 ( & V_54 ) ;
if ( ! V_31 ) {
return V_95 ;
} else {
F_28 ( V_95 ) ;
return NULL ;
}
}
static void * F_63 ( struct V_96 * V_97 , T_6 * V_94 )
{
if ( * V_94 == 0 ) {
++ * V_94 ;
F_64 ( V_97 , L_19 ) ;
}
return F_61 ( * V_94 ) ;
}
static void * F_65 ( struct V_96 * V_97 , void * V_98 , T_6 * V_94 )
{
++ * V_94 ;
return F_61 ( * V_94 ) ;
}
static void F_66 ( struct V_96 * V_97 , void * V_98 )
{
}
static int F_67 ( struct V_96 * V_97 , void * V_98 )
{
struct V_42 * V_95 = (struct V_42 * ) V_98 ;
F_64 ( V_97 , L_20 , F_27 ( V_95 -> type ) ,
V_95 -> V_16 , V_95 -> V_17 ) ;
F_28 ( V_95 ) ;
return 0 ;
}
static int F_68 ( struct V_99 * V_99 , struct V_64 * V_64 )
{
return F_69 ( V_64 , & V_100 ) ;
}
static int T_1 F_70 ( void )
{
if ( V_2 ) {
F_71 ( L_21 , V_101 ,
V_102 , NULL , & V_103 ) ;
}
return 0 ;
}
