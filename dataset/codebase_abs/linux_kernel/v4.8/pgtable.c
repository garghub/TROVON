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
int F_67 ( struct V_47 * V_48 ,
unsigned long V_56 , T_1 * V_49 )
{
int V_57 = 0 ;
if ( F_68 ( * V_49 ) )
V_57 = F_69 ( V_58 ,
( unsigned long * ) & V_49 -> V_7 ) ;
if ( V_57 )
F_63 ( V_48 -> V_53 , V_56 , V_49 ) ;
return V_57 ;
}
int F_70 ( struct V_47 * V_48 ,
unsigned long V_56 , T_4 * V_54 )
{
int V_57 = 0 ;
if ( F_71 ( * V_54 ) )
V_57 = F_69 ( V_58 ,
( unsigned long * ) V_54 ) ;
return V_57 ;
}
int F_72 ( struct V_47 * V_48 ,
unsigned long V_3 , T_1 * V_49 )
{
return F_67 ( V_48 , V_3 , V_49 ) ;
}
int F_73 ( struct V_47 * V_48 ,
unsigned long V_3 , T_4 * V_54 )
{
int V_59 ;
F_66 ( V_3 & ~ V_55 ) ;
V_59 = F_70 ( V_48 , V_3 , V_54 ) ;
if ( V_59 )
F_74 ( V_48 , V_3 , V_3 + V_60 ) ;
return V_59 ;
}
void T_3 F_75 ( unsigned long V_61 )
{
#ifdef F_76
F_77 ( V_62 > 0 ) ;
V_63 = F_78 ( - V_61 , 1 << V_64 ) - V_65 ;
F_79 ( V_66 L_3 ,
- V_61 , V_63 + V_65 ) ;
#endif
}
void F_80 ( enum V_67 V_68 , T_1 V_7 )
{
unsigned long V_3 = F_81 ( V_68 ) ;
if ( V_68 >= V_69 ) {
F_82 () ;
return;
}
F_83 ( V_3 , V_7 ) ;
V_62 ++ ;
}
void F_84 ( enum V_67 V_68 , T_8 V_70 ,
T_9 V_71 )
{
F_80 ( V_68 , F_85 ( V_70 >> V_15 , V_71 ) ) ;
}
int F_86 ( T_5 * V_17 , T_8 V_56 , T_9 V_72 )
{
T_10 V_73 , V_74 ;
V_73 = F_87 ( V_56 , V_56 + V_75 , & V_74 ) ;
if ( ( V_73 != V_76 ) && ( ! V_74 ) &&
( V_73 != V_77 ) )
return 0 ;
V_72 = F_88 ( V_72 ) ;
F_89 ( ( T_1 * ) V_17 , F_85 (
( V_78 ) V_56 >> V_15 ,
F_90 ( F_91 ( V_72 ) | V_79 ) ) ) ;
return 1 ;
}
int F_92 ( T_4 * V_14 , T_8 V_56 , T_9 V_72 )
{
T_10 V_73 , V_74 ;
V_73 = F_87 ( V_56 , V_56 + V_80 , & V_74 ) ;
if ( ( V_73 != V_76 ) && ( ! V_74 ) &&
( V_73 != V_77 ) ) {
F_93 ( L_4 ,
V_81 , V_56 , V_56 + V_80 ) ;
return 0 ;
}
V_72 = F_88 ( V_72 ) ;
F_89 ( ( T_1 * ) V_14 , F_85 (
( V_78 ) V_56 >> V_15 ,
F_90 ( F_91 ( V_72 ) | V_79 ) ) ) ;
return 1 ;
}
int F_94 ( T_5 * V_17 )
{
if ( F_95 ( * V_17 ) ) {
F_96 ( V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_97 ( T_4 * V_14 )
{
if ( F_98 ( * V_14 ) ) {
F_99 ( V_14 ) ;
return 1 ;
}
return 0 ;
}
