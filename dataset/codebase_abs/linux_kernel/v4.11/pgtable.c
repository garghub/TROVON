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
static inline void F_21 ( T_6 * V_18 )
{
struct V_6 * V_6 = F_14 ( V_18 ) ;
F_22 ( & V_6 -> V_19 , & V_20 ) ;
}
static inline void F_23 ( T_6 * V_18 )
{
struct V_6 * V_6 = F_14 ( V_18 ) ;
F_24 ( & V_6 -> V_19 ) ;
}
static void F_25 ( T_6 * V_18 , struct V_1 * V_2 )
{
F_26 ( sizeof( F_14 ( V_18 ) -> V_21 ) < sizeof( V_2 ) ) ;
F_14 ( V_18 ) -> V_21 = ( V_22 ) V_2 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 )
{
return (struct V_1 * ) V_6 -> V_21 ;
}
static void F_28 ( struct V_1 * V_2 , T_6 * V_18 )
{
if ( V_23 == 2 ||
( V_23 == 3 && V_24 ) ||
V_23 == 4 ) {
F_29 ( V_18 + V_25 ,
V_26 + V_25 ,
V_27 ) ;
}
if ( ! V_24 ) {
F_25 ( V_18 , V_2 ) ;
F_21 ( V_18 ) ;
}
}
static void F_30 ( T_6 * V_18 )
{
if ( V_24 )
return;
F_31 ( & V_28 ) ;
F_23 ( V_18 ) ;
F_32 ( & V_28 ) ;
}
void F_33 ( struct V_1 * V_2 , T_5 * V_29 , T_4 * V_14 )
{
F_34 ( V_2 , F_16 ( V_14 ) >> V_15 ) ;
F_35 ( V_29 , F_36 ( F_16 ( V_14 ) | V_30 ) ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_4 * V_31 [] )
{
int V_32 ;
for( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( V_31 [ V_32 ] ) {
F_18 ( F_14 ( V_31 [ V_32 ] ) ) ;
F_39 ( ( unsigned long ) V_31 [ V_32 ] ) ;
F_40 ( V_2 ) ;
}
}
static int F_41 ( struct V_1 * V_2 , T_4 * V_31 [] )
{
int V_32 ;
bool V_34 = false ;
T_7 V_35 = V_4 ;
if ( V_2 == & V_36 )
V_35 &= ~ V_5 ;
for( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
T_4 * V_14 = ( T_4 * ) F_2 ( V_35 ) ;
if ( ! V_14 )
V_34 = true ;
if ( V_14 && ! F_42 ( F_14 ( V_14 ) ) ) {
F_39 ( ( unsigned long ) V_14 ) ;
V_14 = NULL ;
V_34 = true ;
}
if ( V_14 )
F_43 ( V_2 ) ;
V_31 [ V_32 ] = V_14 ;
}
if ( V_34 ) {
F_38 ( V_2 , V_31 ) ;
return - V_37 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , T_6 * V_38 )
{
int V_32 ;
for( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
T_6 V_18 = V_38 [ V_32 ] ;
if ( F_45 ( V_18 ) != 0 ) {
T_4 * V_14 = ( T_4 * ) F_46 ( V_18 ) ;
V_38 [ V_32 ] = F_47 ( 0 ) ;
F_15 ( F_45 ( V_18 ) >> V_15 ) ;
F_48 ( V_2 , V_14 ) ;
F_40 ( V_2 ) ;
}
}
}
static void F_49 ( struct V_1 * V_2 , T_6 * V_18 , T_4 * V_31 [] )
{
T_5 * V_17 ;
int V_32 ;
if ( V_33 == 0 )
return;
V_17 = F_50 ( V_18 , 0 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ , V_17 ++ ) {
T_4 * V_14 = V_31 [ V_32 ] ;
if ( V_32 >= V_25 )
memcpy ( V_14 , ( T_4 * ) F_46 ( V_26 [ V_32 ] ) ,
sizeof( T_4 ) * V_39 ) ;
F_33 ( V_2 , V_17 , V_14 ) ;
}
}
static int T_3 F_51 ( void )
{
if ( ! V_24 )
return 0 ;
V_40 = F_52 ( L_2 , V_41 , V_42 ,
V_43 , NULL ) ;
if ( ! V_40 )
return - V_37 ;
return 0 ;
}
static inline T_6 * F_53 ( void )
{
if ( ! V_24 )
return ( T_6 * ) F_2 ( V_4 ) ;
return F_54 ( V_40 , V_4 ) ;
}
static inline void F_55 ( T_6 * V_18 )
{
if ( ! V_24 )
F_39 ( ( unsigned long ) V_18 ) ;
else
F_56 ( V_40 , V_18 ) ;
}
static inline T_6 * F_53 ( void )
{
return ( T_6 * ) F_2 ( V_4 ) ;
}
static inline void F_55 ( T_6 * V_18 )
{
F_39 ( ( unsigned long ) V_18 ) ;
}
T_6 * F_57 ( struct V_1 * V_2 )
{
T_6 * V_18 ;
T_4 * V_31 [ V_33 ] ;
V_18 = F_53 () ;
if ( V_18 == NULL )
goto V_44;
V_2 -> V_18 = V_18 ;
if ( F_41 ( V_2 , V_31 ) != 0 )
goto V_45;
if ( F_58 ( V_2 ) != 0 )
goto V_46;
F_31 ( & V_28 ) ;
F_28 ( V_2 , V_18 ) ;
F_49 ( V_2 , V_18 , V_31 ) ;
F_32 ( & V_28 ) ;
return V_18 ;
V_46:
F_38 ( V_2 , V_31 ) ;
V_45:
F_55 ( V_18 ) ;
V_44:
return NULL ;
}
void F_59 ( struct V_1 * V_2 , T_6 * V_18 )
{
F_44 ( V_2 , V_18 ) ;
F_30 ( V_18 ) ;
F_60 ( V_2 , V_18 ) ;
F_55 ( V_18 ) ;
}
int F_61 ( struct V_47 * V_48 ,
unsigned long V_3 , T_1 * V_49 ,
T_1 V_50 , int V_51 )
{
int V_52 = ! F_62 ( * V_49 , V_50 ) ;
if ( V_52 && V_51 ) {
* V_49 = V_50 ;
F_63 ( V_48 -> V_53 , V_3 , V_49 ) ;
}
return V_52 ;
}
int F_64 ( struct V_47 * V_48 ,
unsigned long V_3 , T_4 * V_54 ,
T_4 V_50 , int V_51 )
{
int V_52 = ! F_65 ( * V_54 , V_50 ) ;
F_66 ( V_3 & ~ V_55 ) ;
if ( V_52 && V_51 ) {
* V_54 = V_50 ;
}
return V_52 ;
}
int F_67 ( struct V_47 * V_48 , unsigned long V_3 ,
T_5 * V_29 , T_5 V_50 , int V_51 )
{
int V_52 = ! F_68 ( * V_29 , V_50 ) ;
F_66 ( V_3 & ~ V_56 ) ;
if ( V_52 && V_51 ) {
* V_29 = V_50 ;
}
return V_52 ;
}
int F_69 ( struct V_47 * V_48 ,
unsigned long V_57 , T_1 * V_49 )
{
int V_58 = 0 ;
if ( F_70 ( * V_49 ) )
V_58 = F_71 ( V_59 ,
( unsigned long * ) & V_49 -> V_7 ) ;
if ( V_58 )
F_63 ( V_48 -> V_53 , V_57 , V_49 ) ;
return V_58 ;
}
int F_72 ( struct V_47 * V_48 ,
unsigned long V_57 , T_4 * V_54 )
{
int V_58 = 0 ;
if ( F_73 ( * V_54 ) )
V_58 = F_71 ( V_59 ,
( unsigned long * ) V_54 ) ;
return V_58 ;
}
int F_74 ( struct V_47 * V_48 ,
unsigned long V_57 , T_5 * V_29 )
{
int V_58 = 0 ;
if ( F_75 ( * V_29 ) )
V_58 = F_71 ( V_59 ,
( unsigned long * ) V_29 ) ;
return V_58 ;
}
int F_76 ( struct V_47 * V_48 ,
unsigned long V_3 , T_1 * V_49 )
{
return F_69 ( V_48 , V_3 , V_49 ) ;
}
int F_77 ( struct V_47 * V_48 ,
unsigned long V_3 , T_4 * V_54 )
{
int V_60 ;
F_66 ( V_3 & ~ V_55 ) ;
V_60 = F_72 ( V_48 , V_3 , V_54 ) ;
if ( V_60 )
F_78 ( V_48 , V_3 , V_3 + V_61 ) ;
return V_60 ;
}
void T_3 F_79 ( unsigned long V_62 )
{
#ifdef F_80
F_81 ( V_63 > 0 ) ;
V_64 = F_82 ( - V_62 , 1 << V_65 ) - V_66 ;
F_83 ( V_67 L_3 ,
- V_62 , V_64 + V_66 ) ;
#endif
}
void F_84 ( enum V_68 V_69 , T_1 V_7 )
{
unsigned long V_3 = F_85 ( V_69 ) ;
if ( V_69 >= V_70 ) {
F_86 () ;
return;
}
F_87 ( V_3 , V_7 ) ;
V_63 ++ ;
}
void F_88 ( enum V_68 V_69 , T_8 V_71 ,
T_9 V_72 )
{
F_84 ( V_69 , F_89 ( V_71 >> V_15 , V_72 ) ) ;
}
int F_90 ( T_5 * V_17 , T_8 V_57 , T_9 V_73 )
{
T_10 V_74 , V_75 ;
V_74 = F_91 ( V_57 , V_57 + V_76 , & V_75 ) ;
if ( ( V_74 != V_77 ) && ( ! V_75 ) &&
( V_74 != V_78 ) )
return 0 ;
V_73 = F_92 ( V_73 ) ;
F_93 ( ( T_1 * ) V_17 , F_89 (
( V_79 ) V_57 >> V_15 ,
F_94 ( F_95 ( V_73 ) | V_80 ) ) ) ;
return 1 ;
}
int F_96 ( T_4 * V_14 , T_8 V_57 , T_9 V_73 )
{
T_10 V_74 , V_75 ;
V_74 = F_91 ( V_57 , V_57 + V_81 , & V_75 ) ;
if ( ( V_74 != V_77 ) && ( ! V_75 ) &&
( V_74 != V_78 ) ) {
F_97 ( L_4 ,
V_82 , V_57 , V_57 + V_81 ) ;
return 0 ;
}
V_73 = F_92 ( V_73 ) ;
F_93 ( ( T_1 * ) V_14 , F_89 (
( V_79 ) V_57 >> V_15 ,
F_94 ( F_95 ( V_73 ) | V_80 ) ) ) ;
return 1 ;
}
int F_98 ( T_5 * V_17 )
{
if ( F_99 ( * V_17 ) ) {
F_100 ( V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_101 ( T_4 * V_14 )
{
if ( F_102 ( * V_14 ) ) {
F_103 ( V_14 ) ;
return 1 ;
}
return 0 ;
}
