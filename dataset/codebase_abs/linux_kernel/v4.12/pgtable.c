T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return ( T_1 * ) F_2 ( V_4 & ~ V_5 ) ;
}
T_2 F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_8 , 0 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_5 ( V_7 ) ) {
F_6 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static int T_3 F_7 ( char * V_9 )
{
if ( ! V_9 )
return - V_10 ;
if ( strcmp ( V_9 , L_1 ) == 0 )
V_8 &= ~ V_11 ;
else
return - V_10 ;
return 0 ;
}
void F_8 ( struct V_12 * V_13 , struct V_6 * V_7 )
{
F_9 ( V_7 ) ;
F_10 ( F_11 ( V_7 ) ) ;
F_12 ( V_13 , V_7 ) ;
}
void F_13 ( struct V_12 * V_13 , T_4 * V_14 )
{
struct V_6 * V_6 = F_14 ( V_14 ) ;
F_15 ( F_16 ( V_14 ) >> V_15 ) ;
#ifdef F_17
V_13 -> V_16 = 1 ;
#endif
F_18 ( V_6 ) ;
F_12 ( V_13 , V_6 ) ;
}
void F_19 ( struct V_12 * V_13 , T_5 * V_17 )
{
F_20 ( F_16 ( V_17 ) >> V_15 ) ;
F_12 ( V_13 , F_14 ( V_17 ) ) ;
}
void F_21 ( struct V_12 * V_13 , T_6 * V_18 )
{
F_22 ( F_16 ( V_18 ) >> V_15 ) ;
F_12 ( V_13 , F_14 ( V_18 ) ) ;
}
static inline void F_23 ( T_7 * V_19 )
{
struct V_6 * V_6 = F_14 ( V_19 ) ;
F_24 ( & V_6 -> V_20 , & V_21 ) ;
}
static inline void F_25 ( T_7 * V_19 )
{
struct V_6 * V_6 = F_14 ( V_19 ) ;
F_26 ( & V_6 -> V_20 ) ;
}
static void F_27 ( T_7 * V_19 , struct V_1 * V_2 )
{
F_28 ( sizeof( F_14 ( V_19 ) -> V_22 ) < sizeof( V_2 ) ) ;
F_14 ( V_19 ) -> V_22 = ( V_23 ) V_2 ;
}
struct V_1 * F_29 ( struct V_6 * V_6 )
{
return (struct V_1 * ) V_6 -> V_22 ;
}
static void F_30 ( struct V_1 * V_2 , T_7 * V_19 )
{
if ( V_24 == 2 ||
( V_24 == 3 && V_25 ) ||
V_24 >= 4 ) {
F_31 ( V_19 + V_26 ,
V_27 + V_26 ,
V_28 ) ;
}
if ( ! V_25 ) {
F_27 ( V_19 , V_2 ) ;
F_23 ( V_19 ) ;
}
}
static void F_32 ( T_7 * V_19 )
{
if ( V_25 )
return;
F_33 ( & V_29 ) ;
F_25 ( V_19 ) ;
F_34 ( & V_29 ) ;
}
void F_35 ( struct V_1 * V_2 , T_5 * V_30 , T_4 * V_14 )
{
F_36 ( V_2 , F_16 ( V_14 ) >> V_15 ) ;
F_37 ( V_30 , F_38 ( F_16 ( V_14 ) | V_31 ) ) ;
F_39 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_4 * V_32 [] )
{
int V_33 ;
for( V_33 = 0 ; V_33 < V_34 ; V_33 ++ )
if ( V_32 [ V_33 ] ) {
F_18 ( F_14 ( V_32 [ V_33 ] ) ) ;
F_41 ( ( unsigned long ) V_32 [ V_33 ] ) ;
F_42 ( V_2 ) ;
}
}
static int F_43 ( struct V_1 * V_2 , T_4 * V_32 [] )
{
int V_33 ;
bool V_35 = false ;
T_8 V_36 = V_4 ;
if ( V_2 == & V_37 )
V_36 &= ~ V_5 ;
for( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
T_4 * V_14 = ( T_4 * ) F_2 ( V_36 ) ;
if ( ! V_14 )
V_35 = true ;
if ( V_14 && ! F_44 ( F_14 ( V_14 ) ) ) {
F_41 ( ( unsigned long ) V_14 ) ;
V_14 = NULL ;
V_35 = true ;
}
if ( V_14 )
F_45 ( V_2 ) ;
V_32 [ V_33 ] = V_14 ;
}
if ( V_35 ) {
F_40 ( V_2 , V_32 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , T_7 * V_39 )
{
int V_33 ;
for( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
T_7 V_19 = V_39 [ V_33 ] ;
if ( F_47 ( V_19 ) != 0 ) {
T_4 * V_14 = ( T_4 * ) F_48 ( V_19 ) ;
V_39 [ V_33 ] = F_49 ( 0 ) ;
F_15 ( F_47 ( V_19 ) >> V_15 ) ;
F_50 ( V_2 , V_14 ) ;
F_42 ( V_2 ) ;
}
}
}
static void F_51 ( struct V_1 * V_2 , T_7 * V_19 , T_4 * V_32 [] )
{
T_6 * V_18 ;
T_5 * V_17 ;
int V_33 ;
if ( V_34 == 0 )
return;
V_18 = F_52 ( V_19 , 0 ) ;
V_17 = F_53 ( V_18 , 0 ) ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ , V_17 ++ ) {
T_4 * V_14 = V_32 [ V_33 ] ;
if ( V_33 >= V_26 )
memcpy ( V_14 , ( T_4 * ) F_48 ( V_27 [ V_33 ] ) ,
sizeof( T_4 ) * V_40 ) ;
F_35 ( V_2 , V_17 , V_14 ) ;
}
}
static int T_3 F_54 ( void )
{
if ( ! V_25 )
return 0 ;
V_41 = F_55 ( L_2 , V_42 , V_43 ,
V_44 , NULL ) ;
if ( ! V_41 )
return - V_38 ;
return 0 ;
}
static inline T_7 * F_56 ( void )
{
if ( ! V_25 )
return ( T_7 * ) F_2 ( V_4 ) ;
return F_57 ( V_41 , V_4 ) ;
}
static inline void F_58 ( T_7 * V_19 )
{
if ( ! V_25 )
F_41 ( ( unsigned long ) V_19 ) ;
else
F_59 ( V_41 , V_19 ) ;
}
static inline T_7 * F_56 ( void )
{
return ( T_7 * ) F_2 ( V_4 ) ;
}
static inline void F_58 ( T_7 * V_19 )
{
F_41 ( ( unsigned long ) V_19 ) ;
}
T_7 * F_60 ( struct V_1 * V_2 )
{
T_7 * V_19 ;
T_4 * V_32 [ V_34 ] ;
V_19 = F_56 () ;
if ( V_19 == NULL )
goto V_45;
V_2 -> V_19 = V_19 ;
if ( F_43 ( V_2 , V_32 ) != 0 )
goto V_46;
if ( F_61 ( V_2 ) != 0 )
goto V_47;
F_33 ( & V_29 ) ;
F_30 ( V_2 , V_19 ) ;
F_51 ( V_2 , V_19 , V_32 ) ;
F_34 ( & V_29 ) ;
return V_19 ;
V_47:
F_40 ( V_2 , V_32 ) ;
V_46:
F_58 ( V_19 ) ;
V_45:
return NULL ;
}
void F_62 ( struct V_1 * V_2 , T_7 * V_19 )
{
F_46 ( V_2 , V_19 ) ;
F_32 ( V_19 ) ;
F_63 ( V_2 , V_19 ) ;
F_58 ( V_19 ) ;
}
int F_64 ( struct V_48 * V_49 ,
unsigned long V_3 , T_1 * V_50 ,
T_1 V_51 , int V_52 )
{
int V_53 = ! F_65 ( * V_50 , V_51 ) ;
if ( V_53 && V_52 ) {
* V_50 = V_51 ;
F_66 ( V_49 -> V_54 , V_3 , V_50 ) ;
}
return V_53 ;
}
int F_67 ( struct V_48 * V_49 ,
unsigned long V_3 , T_4 * V_55 ,
T_4 V_51 , int V_52 )
{
int V_53 = ! F_68 ( * V_55 , V_51 ) ;
F_69 ( V_3 & ~ V_56 ) ;
if ( V_53 && V_52 ) {
* V_55 = V_51 ;
}
return V_53 ;
}
int F_70 ( struct V_48 * V_49 , unsigned long V_3 ,
T_5 * V_30 , T_5 V_51 , int V_52 )
{
int V_53 = ! F_71 ( * V_30 , V_51 ) ;
F_69 ( V_3 & ~ V_57 ) ;
if ( V_53 && V_52 ) {
* V_30 = V_51 ;
}
return V_53 ;
}
int F_72 ( struct V_48 * V_49 ,
unsigned long V_58 , T_1 * V_50 )
{
int V_59 = 0 ;
if ( F_73 ( * V_50 ) )
V_59 = F_74 ( V_60 ,
( unsigned long * ) & V_50 -> V_7 ) ;
if ( V_59 )
F_66 ( V_49 -> V_54 , V_58 , V_50 ) ;
return V_59 ;
}
int F_75 ( struct V_48 * V_49 ,
unsigned long V_58 , T_4 * V_55 )
{
int V_59 = 0 ;
if ( F_76 ( * V_55 ) )
V_59 = F_74 ( V_60 ,
( unsigned long * ) V_55 ) ;
return V_59 ;
}
int F_77 ( struct V_48 * V_49 ,
unsigned long V_58 , T_5 * V_30 )
{
int V_59 = 0 ;
if ( F_78 ( * V_30 ) )
V_59 = F_74 ( V_60 ,
( unsigned long * ) V_30 ) ;
return V_59 ;
}
int F_79 ( struct V_48 * V_49 ,
unsigned long V_3 , T_1 * V_50 )
{
return F_72 ( V_49 , V_3 , V_50 ) ;
}
int F_80 ( struct V_48 * V_49 ,
unsigned long V_3 , T_4 * V_55 )
{
int V_61 ;
F_69 ( V_3 & ~ V_56 ) ;
V_61 = F_75 ( V_49 , V_3 , V_55 ) ;
if ( V_61 )
F_81 ( V_49 , V_3 , V_3 + V_62 ) ;
return V_61 ;
}
void T_3 F_82 ( unsigned long V_63 )
{
#ifdef F_83
F_84 ( V_64 > 0 ) ;
V_65 = F_85 ( - V_63 , 1 << V_66 ) - V_67 ;
F_86 ( V_68 L_3 ,
- V_63 , V_65 + V_67 ) ;
#endif
}
void F_87 ( enum V_69 V_70 , T_1 V_7 )
{
unsigned long V_3 = F_88 ( V_70 ) ;
if ( V_70 >= V_71 ) {
F_89 () ;
return;
}
F_90 ( V_3 , V_7 ) ;
V_64 ++ ;
}
void F_91 ( enum V_69 V_70 , T_9 V_72 ,
T_10 V_73 )
{
F_87 ( V_70 , F_92 ( V_72 >> V_15 , V_73 ) ) ;
}
int F_93 ( T_6 * V_18 , T_9 V_58 , T_10 V_74 )
{
return 0 ;
}
int F_94 ( T_6 * V_18 )
{
return 0 ;
}
int F_95 ( T_5 * V_17 , T_9 V_58 , T_10 V_74 )
{
T_11 V_75 , V_76 ;
V_75 = F_96 ( V_58 , V_58 + V_77 , & V_76 ) ;
if ( ( V_75 != V_78 ) && ( ! V_76 ) &&
( V_75 != V_79 ) )
return 0 ;
V_74 = F_97 ( V_74 ) ;
F_98 ( ( T_1 * ) V_17 , F_92 (
( V_80 ) V_58 >> V_15 ,
F_99 ( F_100 ( V_74 ) | V_81 ) ) ) ;
return 1 ;
}
int F_101 ( T_4 * V_14 , T_9 V_58 , T_10 V_74 )
{
T_11 V_75 , V_76 ;
V_75 = F_96 ( V_58 , V_58 + V_82 , & V_76 ) ;
if ( ( V_75 != V_78 ) && ( ! V_76 ) &&
( V_75 != V_79 ) ) {
F_102 ( L_4 ,
V_83 , V_58 , V_58 + V_82 ) ;
return 0 ;
}
V_74 = F_97 ( V_74 ) ;
F_98 ( ( T_1 * ) V_14 , F_92 (
( V_80 ) V_58 >> V_15 ,
F_99 ( F_100 ( V_74 ) | V_81 ) ) ) ;
return 1 ;
}
int F_103 ( T_5 * V_17 )
{
if ( F_104 ( * V_17 ) ) {
F_105 ( V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_106 ( T_4 * V_14 )
{
if ( F_107 ( * V_14 ) ) {
F_108 ( V_14 ) ;
return 1 ;
}
return 0 ;
}
