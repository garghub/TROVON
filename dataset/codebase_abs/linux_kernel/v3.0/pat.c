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
static int F_13 ( T_4 V_16 , T_4 V_17 )
{
int V_23 = 0 , V_24 = 0 ;
unsigned long V_25 ;
for ( V_25 = ( V_16 >> V_26 ) ; V_25 < ( V_17 >> V_26 ) ;
++ V_25 ) {
if ( V_25 >= ( V_27 >> V_26 ) &&
F_14 ( V_25 ) )
V_23 = 1 ;
else
V_24 = 1 ;
if ( V_23 == V_24 )
return - 1 ;
}
return V_23 ;
}
static int F_15 ( T_2 V_16 , T_2 V_17 , unsigned long V_18 ,
unsigned long * V_28 )
{
struct V_29 * V_29 ;
T_2 V_30 ;
if ( V_18 == V_31 ) {
F_16 ( 1 ) ;
V_18 = V_22 ;
}
for ( V_30 = ( V_16 >> V_26 ) ; V_30 < ( V_17 >> V_26 ) ; ++ V_30 ) {
unsigned long type ;
V_29 = F_17 ( V_30 ) ;
type = F_18 ( V_29 ) ;
if ( type != - 1 ) {
F_2 ( V_3 L_7
L_8 ,
V_16 , V_17 , type , V_18 ) ;
if ( V_28 )
* V_28 = type ;
return - V_32 ;
}
}
if ( V_28 )
* V_28 = V_18 ;
for ( V_30 = ( V_16 >> V_26 ) ; V_30 < ( V_17 >> V_26 ) ; ++ V_30 ) {
V_29 = F_17 ( V_30 ) ;
F_19 ( V_29 , V_18 ) ;
}
return 0 ;
}
static int F_20 ( T_2 V_16 , T_2 V_17 )
{
struct V_29 * V_29 ;
T_2 V_30 ;
for ( V_30 = ( V_16 >> V_26 ) ; V_30 < ( V_17 >> V_26 ) ; ++ V_30 ) {
V_29 = F_17 ( V_30 ) ;
F_19 ( V_29 , - 1 ) ;
}
return 0 ;
}
int F_21 ( T_2 V_16 , T_2 V_17 , unsigned long V_18 ,
unsigned long * V_28 )
{
struct V_33 * V_34 ;
unsigned long V_35 ;
int V_36 ;
int V_37 = 0 ;
F_22 ( V_16 >= V_17 ) ;
if ( ! V_2 ) {
if ( V_28 ) {
if ( V_18 == V_38 )
* V_28 = V_22 ;
else
* V_28 = V_18 & V_39 ;
}
return 0 ;
}
if ( V_40 . V_41 ( V_16 , V_17 ) ) {
if ( V_28 )
* V_28 = V_19 ;
return 0 ;
}
V_35 = F_11 ( V_16 , V_17 , V_18 & V_39 ) ;
if ( V_28 )
* V_28 = V_35 ;
V_36 = F_13 ( V_16 , V_17 ) ;
if ( V_36 == 1 ) {
V_37 = F_15 ( V_16 , V_17 , V_18 , V_28 ) ;
return V_37 ;
} else if ( V_36 < 0 ) {
return - V_42 ;
}
V_34 = F_23 ( sizeof( struct V_33 ) , V_43 ) ;
if ( ! V_34 )
return - V_44 ;
V_34 -> V_16 = V_16 ;
V_34 -> V_17 = V_17 ;
V_34 -> type = V_35 ;
F_24 ( & V_45 ) ;
V_37 = F_25 ( V_34 , V_28 ) ;
if ( V_37 ) {
F_2 ( V_3 L_9
L_10 ,
V_16 , V_17 , F_26 ( V_34 -> type ) , F_26 ( V_18 ) ) ;
F_27 ( V_34 ) ;
F_28 ( & V_45 ) ;
return V_37 ;
}
F_28 ( & V_45 ) ;
F_29 ( L_11 ,
V_16 , V_17 , F_26 ( V_34 -> type ) , F_26 ( V_18 ) ,
V_28 ? F_26 ( * V_28 ) : L_12 ) ;
return V_37 ;
}
int F_30 ( T_2 V_16 , T_2 V_17 )
{
int V_37 = - V_42 ;
int V_36 ;
struct V_33 * V_46 ;
if ( ! V_2 )
return 0 ;
if ( V_40 . V_41 ( V_16 , V_17 ) )
return 0 ;
V_36 = F_13 ( V_16 , V_17 ) ;
if ( V_36 == 1 ) {
V_37 = F_20 ( V_16 , V_17 ) ;
return V_37 ;
} else if ( V_36 < 0 ) {
return - V_42 ;
}
F_24 ( & V_45 ) ;
V_46 = F_31 ( V_16 , V_17 ) ;
F_28 ( & V_45 ) ;
if ( ! V_46 ) {
F_2 ( V_3 L_13 ,
V_47 -> V_48 , V_47 -> V_49 , V_16 , V_17 ) ;
return - V_42 ;
}
F_27 ( V_46 ) ;
F_29 ( L_14 , V_16 , V_17 ) ;
return 0 ;
}
static unsigned long F_32 ( T_2 V_50 )
{
int V_51 = V_19 ;
struct V_33 * V_46 ;
if ( V_40 . V_41 ( V_50 , V_50 + V_52 ) )
return V_51 ;
if ( F_13 ( V_50 , V_50 + V_52 ) ) {
struct V_29 * V_29 ;
V_29 = F_17 ( V_50 >> V_26 ) ;
V_51 = F_18 ( V_29 ) ;
if ( V_51 == - 1 )
V_51 = V_19 ;
return V_51 ;
}
F_24 ( & V_45 ) ;
V_46 = F_33 ( V_50 ) ;
if ( V_46 != NULL )
V_51 = V_46 -> type ;
else
V_51 = V_22 ;
F_28 ( & V_45 ) ;
return V_51 ;
}
int F_34 ( T_4 V_16 , T_4 V_17 ,
unsigned long * type )
{
T_4 V_53 = V_17 - V_16 ;
unsigned long V_18 = * type ;
unsigned long V_28 ;
int V_54 ;
F_16 ( F_35 ( V_16 , V_53 ) ) ;
V_54 = F_21 ( V_16 , V_17 , V_18 , & V_28 ) ;
if ( V_54 )
goto V_55;
if ( ! F_36 ( V_16 , V_53 , V_18 , V_28 ) )
goto V_56;
if ( F_37 ( V_16 , V_53 , V_28 ) < 0 )
goto V_56;
* type = V_28 ;
return 0 ;
V_56:
F_30 ( V_16 , V_17 ) ;
V_54 = - V_32 ;
V_55:
return V_54 ;
}
void F_38 ( T_4 V_16 , T_4 V_17 )
{
F_30 ( V_16 , V_17 ) ;
}
T_5 F_39 ( struct V_57 * V_57 , unsigned long V_30 ,
unsigned long V_53 , T_5 V_58 )
{
return V_58 ;
}
static inline int F_40 ( unsigned long V_30 , unsigned long V_53 )
{
return 1 ;
}
static inline int F_40 ( unsigned long V_30 , unsigned long V_53 )
{
T_2 V_59 = ( ( T_2 ) V_30 ) << V_26 ;
T_2 V_60 = V_59 + V_53 ;
T_2 V_61 = V_59 ;
if ( ! V_2 )
return 1 ;
while ( V_61 < V_60 ) {
if ( ! F_41 ( V_30 ) ) {
F_2 ( V_3
L_15 ,
V_47 -> V_48 , V_59 , V_60 ) ;
return 0 ;
}
V_61 += V_52 ;
V_30 ++ ;
}
return 1 ;
}
int F_42 ( struct V_57 * V_57 , unsigned long V_30 ,
unsigned long V_53 , T_5 * V_58 )
{
unsigned long V_62 = V_19 ;
if ( ! F_40 ( V_30 , V_53 ) )
return 0 ;
if ( V_57 -> V_63 & V_64 )
V_62 = V_22 ;
#ifdef F_43
if ( ! V_2 &&
! ( F_44 ( V_65 ) ||
F_44 ( V_66 ) ||
F_44 ( V_67 ) ||
F_44 ( V_68 ) ) &&
( V_30 << V_26 ) >= F_45 ( V_69 ) ) {
V_62 = V_31 ;
}
#endif
* V_58 = F_46 ( ( F_47 ( * V_58 ) & ~ V_39 ) |
V_62 ) ;
return 1 ;
}
int F_37 ( T_2 V_70 , unsigned long V_53 , unsigned long V_62 )
{
unsigned long V_71 ;
if ( V_70 >= F_45 ( V_69 ) )
return 0 ;
V_71 = ( F_45 ( V_69 ) < V_70 + V_53 ) ?
F_45 ( V_69 ) - V_70 :
V_53 ;
if ( F_48 ( ( unsigned long ) F_49 ( V_70 ) , V_71 , V_62 ) < 0 ) {
F_2 ( V_3
L_16
L_17 ,
V_47 -> V_48 , V_47 -> V_49 ,
F_26 ( V_62 ) ,
V_70 , ( unsigned long long ) ( V_70 + V_53 ) ) ;
return - V_42 ;
}
return 0 ;
}
static int F_50 ( T_2 V_50 , unsigned long V_53 , T_5 * V_58 ,
int V_72 )
{
int V_73 = 0 ;
int V_54 ;
unsigned long V_74 = ( F_47 ( * V_58 ) & V_39 ) ;
unsigned long V_62 = V_74 ;
V_73 = F_13 ( V_50 , V_50 + V_53 ) ;
if ( V_73 ) {
if ( ! V_2 )
return 0 ;
V_62 = F_32 ( V_50 ) ;
if ( V_74 != V_62 ) {
F_2 ( V_75
L_18 ,
V_47 -> V_48 , V_47 -> V_49 ,
F_26 ( V_74 ) ,
( unsigned long long ) V_50 ,
( unsigned long long ) ( V_50 + V_53 ) ,
F_26 ( V_62 ) ) ;
* V_58 = F_46 ( ( F_47 ( * V_58 ) &
( ~ V_39 ) ) |
V_62 ) ;
}
return 0 ;
}
V_54 = F_21 ( V_50 , V_50 + V_53 , V_74 , & V_62 ) ;
if ( V_54 )
return V_54 ;
if ( V_62 != V_74 ) {
if ( V_72 ||
! F_36 ( V_50 , V_53 , V_74 , V_62 ) ) {
F_30 ( V_50 , V_50 + V_53 ) ;
F_2 ( V_10 L_19
L_20 ,
V_47 -> V_48 , V_47 -> V_49 ,
F_26 ( V_74 ) ,
( unsigned long long ) V_50 ,
( unsigned long long ) ( V_50 + V_53 ) ,
F_26 ( V_62 ) ) ;
return - V_42 ;
}
* V_58 = F_46 ( ( F_47 ( * V_58 ) &
( ~ V_39 ) ) |
V_62 ) ;
}
if ( F_37 ( V_50 , V_53 , V_62 ) < 0 ) {
F_30 ( V_50 , V_50 + V_53 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_51 ( T_2 V_50 , unsigned long V_53 )
{
int V_73 ;
V_73 = F_13 ( V_50 , V_50 + V_53 ) ;
if ( V_73 == 0 )
F_30 ( V_50 , V_50 + V_53 ) ;
}
int F_52 ( struct V_76 * V_77 )
{
T_4 V_50 ;
unsigned long V_78 ;
unsigned long V_79 = V_77 -> V_80 - V_77 -> V_81 ;
T_5 V_82 ;
if ( F_53 ( V_77 ) ) {
if ( F_54 ( V_77 , V_77 -> V_81 , 0 , & V_78 , & V_50 ) ) {
F_16 ( 1 ) ;
return - V_42 ;
}
V_82 = F_46 ( V_78 ) ;
return F_50 ( V_50 , V_79 , & V_82 , 1 ) ;
}
return 0 ;
}
int F_55 ( struct V_76 * V_77 , T_5 * V_78 ,
unsigned long V_30 , unsigned long V_53 )
{
unsigned long V_62 ;
T_4 V_50 ;
unsigned long V_79 = V_77 -> V_80 - V_77 -> V_81 ;
if ( F_53 ( V_77 ) ) {
V_50 = ( T_4 ) V_77 -> V_83 << V_26 ;
return F_50 ( V_50 , V_79 , V_78 , 0 ) ;
}
if ( ! V_2 )
return 0 ;
V_62 = F_32 ( V_30 << V_26 ) ;
* V_78 = F_46 ( ( F_47 ( V_77 -> V_84 ) & ( ~ V_39 ) ) |
V_62 ) ;
return 0 ;
}
void F_56 ( struct V_76 * V_77 , unsigned long V_30 ,
unsigned long V_53 )
{
T_4 V_50 ;
unsigned long V_79 = V_77 -> V_80 - V_77 -> V_81 ;
if ( F_53 ( V_77 ) ) {
V_50 = ( T_4 ) V_77 -> V_83 << V_26 ;
F_51 ( V_50 , V_79 ) ;
return;
}
}
T_5 F_57 ( T_5 V_78 )
{
if ( V_2 )
return F_46 ( F_47 ( V_78 ) | V_38 ) ;
else
return F_58 ( V_78 ) ;
}
static struct V_33 * F_59 ( T_6 V_85 )
{
struct V_33 * V_86 ;
int V_54 ;
V_86 = F_23 ( sizeof( struct V_33 ) , V_43 ) ;
if ( ! V_86 )
return NULL ;
F_24 ( & V_45 ) ;
V_54 = F_60 ( V_86 , V_85 ) ;
F_28 ( & V_45 ) ;
if ( ! V_54 ) {
return V_86 ;
} else {
F_27 ( V_86 ) ;
return NULL ;
}
}
static void * F_61 ( struct V_87 * V_88 , T_6 * V_85 )
{
if ( * V_85 == 0 ) {
++ * V_85 ;
F_62 ( V_88 , L_21 ) ;
}
return F_59 ( * V_85 ) ;
}
static void * F_63 ( struct V_87 * V_88 , void * V_89 , T_6 * V_85 )
{
++ * V_85 ;
return F_59 ( * V_85 ) ;
}
static void F_64 ( struct V_87 * V_88 , void * V_89 )
{
}
static int F_65 ( struct V_87 * V_88 , void * V_89 )
{
struct V_33 * V_86 = (struct V_33 * ) V_89 ;
F_62 ( V_88 , L_22 , F_26 ( V_86 -> type ) ,
V_86 -> V_16 , V_86 -> V_17 ) ;
F_27 ( V_86 ) ;
return 0 ;
}
static int F_66 ( struct V_90 * V_90 , struct V_57 * V_57 )
{
return F_67 ( V_57 , & V_91 ) ;
}
static int T_1 F_68 ( void )
{
if ( V_2 ) {
F_69 ( L_23 , V_92 ,
V_93 , NULL , & V_94 ) ;
}
return 0 ;
}
