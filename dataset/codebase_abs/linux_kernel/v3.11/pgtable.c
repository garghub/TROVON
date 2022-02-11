T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return ( T_1 * ) F_2 ( V_4 ) ;
}
T_2 F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_7 , 0 ) ;
if ( V_6 )
F_5 ( V_6 ) ;
return V_6 ;
}
static int T_3 F_6 ( char * V_8 )
{
if ( ! V_8 )
return - V_9 ;
if ( strcmp ( V_8 , L_1 ) == 0 )
V_7 &= ~ V_10 ;
else
return - V_9 ;
return 0 ;
}
void F_7 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_9 ( F_10 ( V_6 ) ) ;
F_11 ( V_12 , V_6 ) ;
}
void F_12 ( struct V_11 * V_12 , T_4 * V_13 )
{
F_13 ( F_14 ( V_13 ) >> V_14 ) ;
#ifdef F_15
V_12 -> V_15 = 1 ;
#endif
F_11 ( V_12 , F_16 ( V_13 ) ) ;
}
void F_17 ( struct V_11 * V_12 , T_5 * V_16 )
{
F_18 ( F_14 ( V_16 ) >> V_14 ) ;
F_11 ( V_12 , F_16 ( V_16 ) ) ;
}
static inline void F_19 ( T_6 * V_17 )
{
struct V_5 * V_5 = F_16 ( V_17 ) ;
F_20 ( & V_5 -> V_18 , & V_19 ) ;
}
static inline void F_21 ( T_6 * V_17 )
{
struct V_5 * V_5 = F_16 ( V_17 ) ;
F_22 ( & V_5 -> V_18 ) ;
}
static void F_23 ( T_6 * V_17 , struct V_1 * V_2 )
{
F_24 ( sizeof( F_16 ( V_17 ) -> V_20 ) < sizeof( V_2 ) ) ;
F_16 ( V_17 ) -> V_20 = ( V_21 ) V_2 ;
}
struct V_1 * F_25 ( struct V_5 * V_5 )
{
return (struct V_1 * ) V_5 -> V_20 ;
}
static void F_26 ( struct V_1 * V_2 , T_6 * V_17 )
{
if ( V_22 == 2 ||
( V_22 == 3 && V_23 ) ||
V_22 == 4 ) {
F_27 ( V_17 + V_24 ,
V_25 + V_24 ,
V_26 ) ;
}
if ( ! V_23 ) {
F_23 ( V_17 , V_2 ) ;
F_19 ( V_17 ) ;
}
}
static void F_28 ( T_6 * V_17 )
{
if ( V_23 )
return;
F_29 ( & V_27 ) ;
F_21 ( V_17 ) ;
F_30 ( & V_27 ) ;
}
void F_31 ( struct V_1 * V_2 , T_5 * V_28 , T_4 * V_13 )
{
F_32 ( V_2 , F_14 ( V_13 ) >> V_14 ) ;
F_33 ( V_28 , F_34 ( F_14 ( V_13 ) | V_29 ) ) ;
F_35 ( V_2 ) ;
}
static void F_36 ( T_4 * V_30 [] )
{
int V_31 ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
if ( V_30 [ V_31 ] )
F_37 ( ( unsigned long ) V_30 [ V_31 ] ) ;
}
static int F_38 ( T_4 * V_30 [] )
{
int V_31 ;
bool V_33 = false ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
T_4 * V_13 = ( T_4 * ) F_2 ( V_4 ) ;
if ( V_13 == NULL )
V_33 = true ;
V_30 [ V_31 ] = V_13 ;
}
if ( V_33 ) {
F_36 ( V_30 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , T_6 * V_35 )
{
int V_31 ;
for( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
T_6 V_17 = V_35 [ V_31 ] ;
if ( F_40 ( V_17 ) != 0 ) {
T_4 * V_13 = ( T_4 * ) F_41 ( V_17 ) ;
V_35 [ V_31 ] = F_42 ( 0 ) ;
F_13 ( F_40 ( V_17 ) >> V_14 ) ;
F_43 ( V_2 , V_13 ) ;
}
}
}
static void F_44 ( struct V_1 * V_2 , T_6 * V_17 , T_4 * V_30 [] )
{
T_5 * V_16 ;
int V_31 ;
if ( V_32 == 0 )
return;
V_16 = F_45 ( V_17 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ , V_16 ++ ) {
T_4 * V_13 = V_30 [ V_31 ] ;
if ( V_31 >= V_24 )
memcpy ( V_13 , ( T_4 * ) F_41 ( V_25 [ V_31 ] ) ,
sizeof( T_4 ) * V_36 ) ;
F_31 ( V_2 , V_16 , V_13 ) ;
}
}
T_6 * F_46 ( struct V_1 * V_2 )
{
T_6 * V_17 ;
T_4 * V_30 [ V_32 ] ;
V_17 = ( T_6 * ) F_2 ( V_4 ) ;
if ( V_17 == NULL )
goto V_37;
V_2 -> V_17 = V_17 ;
if ( F_38 ( V_30 ) != 0 )
goto V_38;
if ( F_47 ( V_2 ) != 0 )
goto V_39;
F_29 ( & V_27 ) ;
F_26 ( V_2 , V_17 ) ;
F_44 ( V_2 , V_17 , V_30 ) ;
F_30 ( & V_27 ) ;
return V_17 ;
V_39:
F_36 ( V_30 ) ;
V_38:
F_37 ( ( unsigned long ) V_17 ) ;
V_37:
return NULL ;
}
void F_48 ( struct V_1 * V_2 , T_6 * V_17 )
{
F_39 ( V_2 , V_17 ) ;
F_28 ( V_17 ) ;
F_49 ( V_2 , V_17 ) ;
F_37 ( ( unsigned long ) V_17 ) ;
}
int F_50 ( struct V_40 * V_41 ,
unsigned long V_3 , T_1 * V_42 ,
T_1 V_43 , int V_44 )
{
int V_45 = ! F_51 ( * V_42 , V_43 ) ;
if ( V_45 && V_44 ) {
* V_42 = V_43 ;
F_52 ( V_41 -> V_46 , V_3 , V_42 ) ;
}
return V_45 ;
}
int F_53 ( struct V_40 * V_41 ,
unsigned long V_3 , T_4 * V_47 ,
T_4 V_43 , int V_44 )
{
int V_45 = ! F_54 ( * V_47 , V_43 ) ;
F_55 ( V_3 & ~ V_48 ) ;
if ( V_45 && V_44 ) {
* V_47 = V_43 ;
F_56 ( V_41 -> V_46 , V_3 , V_47 ) ;
}
return V_45 ;
}
int F_57 ( struct V_40 * V_41 ,
unsigned long V_49 , T_1 * V_42 )
{
int V_50 = 0 ;
if ( F_58 ( * V_42 ) )
V_50 = F_59 ( V_51 ,
( unsigned long * ) & V_42 -> V_6 ) ;
if ( V_50 )
F_60 ( V_41 -> V_46 , V_49 , V_42 ) ;
return V_50 ;
}
int F_61 ( struct V_40 * V_41 ,
unsigned long V_49 , T_4 * V_47 )
{
int V_50 = 0 ;
if ( F_62 ( * V_47 ) )
V_50 = F_59 ( V_51 ,
( unsigned long * ) V_47 ) ;
if ( V_50 )
F_63 ( V_41 -> V_46 , V_49 , V_47 ) ;
return V_50 ;
}
int F_64 ( struct V_40 * V_41 ,
unsigned long V_3 , T_1 * V_42 )
{
int V_52 ;
V_52 = F_57 ( V_41 , V_3 , V_42 ) ;
if ( V_52 )
F_65 ( V_41 , V_3 ) ;
return V_52 ;
}
int F_66 ( struct V_40 * V_41 ,
unsigned long V_3 , T_4 * V_47 )
{
int V_52 ;
F_55 ( V_3 & ~ V_48 ) ;
V_52 = F_61 ( V_41 , V_3 , V_47 ) ;
if ( V_52 )
F_67 ( V_41 , V_3 , V_3 + V_53 ) ;
return V_52 ;
}
void F_68 ( struct V_40 * V_41 ,
unsigned long V_3 , T_4 * V_47 )
{
int V_54 ;
F_55 ( V_3 & ~ V_48 ) ;
V_54 = ! F_69 ( V_55 ,
( unsigned long * ) V_47 ) ;
if ( V_54 ) {
F_63 ( V_41 -> V_46 , V_3 , V_47 ) ;
F_67 ( V_41 , V_3 , V_3 + V_53 ) ;
}
}
void T_3 F_70 ( unsigned long V_56 )
{
#ifdef F_71
F_72 ( V_57 > 0 ) ;
F_73 ( V_58 L_2 ,
( int ) - V_56 ) ;
V_59 = - V_56 - V_60 ;
#endif
}
void F_74 ( enum V_61 V_62 , T_1 V_6 )
{
unsigned long V_3 = F_75 ( V_62 ) ;
if ( V_62 >= V_63 ) {
F_76 () ;
return;
}
F_77 ( V_3 , V_6 ) ;
V_57 ++ ;
}
void F_78 ( enum V_61 V_62 , T_7 V_64 ,
T_8 V_65 )
{
F_74 ( V_62 , F_79 ( V_64 >> V_14 , V_65 ) ) ;
}
