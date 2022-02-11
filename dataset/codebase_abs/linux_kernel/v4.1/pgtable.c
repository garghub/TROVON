T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return ( T_1 * ) F_2 ( V_4 ) ;
}
T_2 F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_7 , 0 ) ;
if ( ! V_6 )
return NULL ;
if ( ! F_5 ( V_6 ) ) {
F_6 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
static int T_3 F_7 ( char * V_8 )
{
if ( ! V_8 )
return - V_9 ;
if ( strcmp ( V_8 , L_1 ) == 0 )
V_7 &= ~ V_10 ;
else
return - V_9 ;
return 0 ;
}
void F_8 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
F_9 ( V_6 ) ;
F_10 ( F_11 ( V_6 ) ) ;
F_12 ( V_12 , V_6 ) ;
}
void F_13 ( struct V_11 * V_12 , T_4 * V_13 )
{
struct V_5 * V_5 = F_14 ( V_13 ) ;
F_15 ( F_16 ( V_13 ) >> V_14 ) ;
#ifdef F_17
V_12 -> V_15 = 1 ;
#endif
F_18 ( V_5 ) ;
F_12 ( V_12 , V_5 ) ;
}
void F_19 ( struct V_11 * V_12 , T_5 * V_16 )
{
F_20 ( F_16 ( V_16 ) >> V_14 ) ;
F_12 ( V_12 , F_14 ( V_16 ) ) ;
}
static inline void F_21 ( T_6 * V_17 )
{
struct V_5 * V_5 = F_14 ( V_17 ) ;
F_22 ( & V_5 -> V_18 , & V_19 ) ;
}
static inline void F_23 ( T_6 * V_17 )
{
struct V_5 * V_5 = F_14 ( V_17 ) ;
F_24 ( & V_5 -> V_18 ) ;
}
static void F_25 ( T_6 * V_17 , struct V_1 * V_2 )
{
F_26 ( sizeof( F_14 ( V_17 ) -> V_20 ) < sizeof( V_2 ) ) ;
F_14 ( V_17 ) -> V_20 = ( V_21 ) V_2 ;
}
struct V_1 * F_27 ( struct V_5 * V_5 )
{
return (struct V_1 * ) V_5 -> V_20 ;
}
static void F_28 ( struct V_1 * V_2 , T_6 * V_17 )
{
if ( V_22 == 2 ||
( V_22 == 3 && V_23 ) ||
V_22 == 4 ) {
F_29 ( V_17 + V_24 ,
V_25 + V_24 ,
V_26 ) ;
}
if ( ! V_23 ) {
F_25 ( V_17 , V_2 ) ;
F_21 ( V_17 ) ;
}
}
static void F_30 ( T_6 * V_17 )
{
if ( V_23 )
return;
F_31 ( & V_27 ) ;
F_23 ( V_17 ) ;
F_32 ( & V_27 ) ;
}
void F_33 ( struct V_1 * V_2 , T_5 * V_28 , T_4 * V_13 )
{
F_34 ( V_2 , F_16 ( V_13 ) >> V_14 ) ;
F_35 ( V_28 , F_36 ( F_16 ( V_13 ) | V_29 ) ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_4 * V_30 [] )
{
int V_31 ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
if ( V_30 [ V_31 ] ) {
F_18 ( F_14 ( V_30 [ V_31 ] ) ) ;
F_39 ( ( unsigned long ) V_30 [ V_31 ] ) ;
F_40 ( V_2 ) ;
}
}
static int F_41 ( struct V_1 * V_2 , T_4 * V_30 [] )
{
int V_31 ;
bool V_33 = false ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
T_4 * V_13 = ( T_4 * ) F_2 ( V_4 ) ;
if ( ! V_13 )
V_33 = true ;
if ( V_13 && ! F_42 ( F_14 ( V_13 ) ) ) {
F_39 ( ( unsigned long ) V_13 ) ;
V_13 = NULL ;
V_33 = true ;
}
if ( V_13 )
F_43 ( V_2 ) ;
V_30 [ V_31 ] = V_13 ;
}
if ( V_33 ) {
F_38 ( V_2 , V_30 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , T_6 * V_35 )
{
int V_31 ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
T_6 V_17 = V_35 [ V_31 ] ;
if ( F_45 ( V_17 ) != 0 ) {
T_4 * V_13 = ( T_4 * ) F_46 ( V_17 ) ;
V_35 [ V_31 ] = F_47 ( 0 ) ;
F_15 ( F_45 ( V_17 ) >> V_14 ) ;
F_48 ( V_2 , V_13 ) ;
F_40 ( V_2 ) ;
}
}
}
static void F_49 ( struct V_1 * V_2 , T_6 * V_17 , T_4 * V_30 [] )
{
T_5 * V_16 ;
int V_31 ;
if ( V_32 == 0 )
return;
V_16 = F_50 ( V_17 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ , V_16 ++ ) {
T_4 * V_13 = V_30 [ V_31 ] ;
if ( V_31 >= V_24 )
memcpy ( V_13 , ( T_4 * ) F_46 ( V_25 [ V_31 ] ) ,
sizeof( T_4 ) * V_36 ) ;
F_33 ( V_2 , V_16 , V_13 ) ;
}
}
static int T_3 F_51 ( void )
{
if ( ! V_23 )
return 0 ;
V_37 = F_52 ( L_2 , V_38 , V_39 ,
V_40 , NULL ) ;
if ( ! V_37 )
return - V_34 ;
return 0 ;
}
static inline T_6 * F_53 ( void )
{
if ( ! V_23 )
return ( T_6 * ) F_2 ( V_4 ) ;
return F_54 ( V_37 , V_4 ) ;
}
static inline void F_55 ( T_6 * V_17 )
{
if ( ! V_23 )
F_39 ( ( unsigned long ) V_17 ) ;
else
F_56 ( V_37 , V_17 ) ;
}
static inline T_6 * F_53 ( void )
{
return ( T_6 * ) F_2 ( V_4 ) ;
}
static inline void F_55 ( T_6 * V_17 )
{
F_39 ( ( unsigned long ) V_17 ) ;
}
T_6 * F_57 ( struct V_1 * V_2 )
{
T_6 * V_17 ;
T_4 * V_30 [ V_32 ] ;
V_17 = F_53 () ;
if ( V_17 == NULL )
goto V_41;
V_2 -> V_17 = V_17 ;
if ( F_41 ( V_2 , V_30 ) != 0 )
goto V_42;
if ( F_58 ( V_2 ) != 0 )
goto V_43;
F_31 ( & V_27 ) ;
F_28 ( V_2 , V_17 ) ;
F_49 ( V_2 , V_17 , V_30 ) ;
F_32 ( & V_27 ) ;
return V_17 ;
V_43:
F_38 ( V_2 , V_30 ) ;
V_42:
F_55 ( V_17 ) ;
V_41:
return NULL ;
}
void F_59 ( struct V_1 * V_2 , T_6 * V_17 )
{
F_44 ( V_2 , V_17 ) ;
F_30 ( V_17 ) ;
F_60 ( V_2 , V_17 ) ;
F_55 ( V_17 ) ;
}
int F_61 ( struct V_44 * V_45 ,
unsigned long V_3 , T_1 * V_46 ,
T_1 V_47 , int V_48 )
{
int V_49 = ! F_62 ( * V_46 , V_47 ) ;
if ( V_49 && V_48 ) {
* V_46 = V_47 ;
F_63 ( V_45 -> V_50 , V_3 , V_46 ) ;
}
return V_49 ;
}
int F_64 ( struct V_44 * V_45 ,
unsigned long V_3 , T_4 * V_51 ,
T_4 V_47 , int V_48 )
{
int V_49 = ! F_65 ( * V_51 , V_47 ) ;
F_66 ( V_3 & ~ V_52 ) ;
if ( V_49 && V_48 ) {
* V_51 = V_47 ;
F_67 ( V_45 -> V_50 , V_3 , V_51 ) ;
}
return V_49 ;
}
int F_68 ( struct V_44 * V_45 ,
unsigned long V_53 , T_1 * V_46 )
{
int V_54 = 0 ;
if ( F_69 ( * V_46 ) )
V_54 = F_70 ( V_55 ,
( unsigned long * ) & V_46 -> V_6 ) ;
if ( V_54 )
F_71 ( V_45 -> V_50 , V_53 , V_46 ) ;
return V_54 ;
}
int F_72 ( struct V_44 * V_45 ,
unsigned long V_53 , T_4 * V_51 )
{
int V_54 = 0 ;
if ( F_73 ( * V_51 ) )
V_54 = F_70 ( V_55 ,
( unsigned long * ) V_51 ) ;
if ( V_54 )
F_74 ( V_45 -> V_50 , V_53 , V_51 ) ;
return V_54 ;
}
int F_75 ( struct V_44 * V_45 ,
unsigned long V_3 , T_1 * V_46 )
{
return F_68 ( V_45 , V_3 , V_46 ) ;
}
int F_76 ( struct V_44 * V_45 ,
unsigned long V_3 , T_4 * V_51 )
{
int V_56 ;
F_66 ( V_3 & ~ V_52 ) ;
V_56 = F_72 ( V_45 , V_3 , V_51 ) ;
if ( V_56 )
F_77 ( V_45 , V_3 , V_3 + V_57 ) ;
return V_56 ;
}
void F_78 ( struct V_44 * V_45 ,
unsigned long V_3 , T_4 * V_51 )
{
int V_58 ;
F_66 ( V_3 & ~ V_52 ) ;
V_58 = ! F_79 ( V_59 ,
( unsigned long * ) V_51 ) ;
if ( V_58 ) {
F_74 ( V_45 -> V_50 , V_3 , V_51 ) ;
F_77 ( V_45 , V_3 , V_3 + V_57 ) ;
}
}
void T_3 F_80 ( unsigned long V_60 )
{
#ifdef F_81
F_82 ( V_61 > 0 ) ;
V_62 = F_83 ( - V_60 , 1 << V_63 ) - V_64 ;
F_84 ( V_65 L_3 ,
- V_60 , V_62 + V_64 ) ;
#endif
}
void F_85 ( enum V_66 V_67 , T_1 V_6 )
{
unsigned long V_3 = F_86 ( V_67 ) ;
if ( V_67 >= V_68 ) {
F_87 () ;
return;
}
F_88 ( V_3 , V_6 ) ;
V_61 ++ ;
}
void F_89 ( enum V_66 V_67 , T_7 V_69 ,
T_8 V_70 )
{
F_85 ( V_67 , F_90 ( V_69 >> V_14 , V_70 ) ) ;
}
int F_91 ( T_5 * V_16 , T_7 V_53 , T_8 V_71 )
{
T_9 V_72 ;
V_72 = F_92 ( V_53 , V_53 + V_73 ) ;
if ( ( V_72 != V_74 ) && ( V_72 != 0xFF ) )
return 0 ;
V_71 = F_93 ( V_71 ) ;
F_94 ( ( T_1 * ) V_16 , F_90 (
( V_75 ) V_53 >> V_14 ,
F_95 ( F_96 ( V_71 ) | V_76 ) ) ) ;
return 1 ;
}
int F_97 ( T_4 * V_13 , T_7 V_53 , T_8 V_71 )
{
T_9 V_72 ;
V_72 = F_92 ( V_53 , V_53 + V_77 ) ;
if ( ( V_72 != V_74 ) && ( V_72 != 0xFF ) )
return 0 ;
V_71 = F_93 ( V_71 ) ;
F_94 ( ( T_1 * ) V_13 , F_90 (
( V_75 ) V_53 >> V_14 ,
F_95 ( F_96 ( V_71 ) | V_76 ) ) ) ;
return 1 ;
}
int F_98 ( T_5 * V_16 )
{
if ( F_99 ( * V_16 ) ) {
F_100 ( V_16 ) ;
return 1 ;
}
return 0 ;
}
int F_101 ( T_4 * V_13 )
{
if ( F_102 ( * V_13 ) ) {
F_103 ( V_13 ) ;
return 1 ;
}
return 0 ;
}
