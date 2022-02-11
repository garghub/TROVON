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
F_11 ( V_12 , F_15 ( V_13 ) ) ;
}
void F_16 ( struct V_11 * V_12 , T_5 * V_15 )
{
F_17 ( F_14 ( V_15 ) >> V_14 ) ;
F_11 ( V_12 , F_15 ( V_15 ) ) ;
}
static inline void F_18 ( T_6 * V_16 )
{
struct V_5 * V_5 = F_15 ( V_16 ) ;
F_19 ( & V_5 -> V_17 , & V_18 ) ;
}
static inline void F_20 ( T_6 * V_16 )
{
struct V_5 * V_5 = F_15 ( V_16 ) ;
F_21 ( & V_5 -> V_17 ) ;
}
static void F_22 ( T_6 * V_16 , struct V_1 * V_2 )
{
F_23 ( sizeof( F_15 ( V_16 ) -> V_19 ) < sizeof( V_2 ) ) ;
F_15 ( V_16 ) -> V_19 = ( V_20 ) V_2 ;
}
struct V_1 * F_24 ( struct V_5 * V_5 )
{
return (struct V_1 * ) V_5 -> V_19 ;
}
static void F_25 ( struct V_1 * V_2 , T_6 * V_16 )
{
if ( V_21 == 2 ||
( V_21 == 3 && V_22 ) ||
V_21 == 4 ) {
F_26 ( V_16 + V_23 ,
V_24 + V_23 ,
V_25 ) ;
}
if ( ! V_22 ) {
F_22 ( V_16 , V_2 ) ;
F_18 ( V_16 ) ;
}
}
static void F_27 ( T_6 * V_16 )
{
if ( V_22 )
return;
F_28 ( & V_26 ) ;
F_20 ( V_16 ) ;
F_29 ( & V_26 ) ;
}
void F_30 ( struct V_1 * V_2 , T_5 * V_27 , T_4 * V_13 )
{
F_31 ( V_2 , F_14 ( V_13 ) >> V_14 ) ;
F_32 ( V_27 , F_33 ( F_14 ( V_13 ) | V_28 ) ) ;
F_34 ( V_2 ) ;
}
static void F_35 ( T_4 * V_29 [] )
{
int V_30 ;
for( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
if ( V_29 [ V_30 ] )
F_36 ( ( unsigned long ) V_29 [ V_30 ] ) ;
}
static int F_37 ( T_4 * V_29 [] )
{
int V_30 ;
bool V_32 = false ;
for( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
T_4 * V_13 = ( T_4 * ) F_2 ( V_4 ) ;
if ( V_13 == NULL )
V_32 = true ;
V_29 [ V_30 ] = V_13 ;
}
if ( V_32 ) {
F_35 ( V_29 ) ;
return - V_33 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_6 * V_34 )
{
int V_30 ;
for( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
T_6 V_16 = V_34 [ V_30 ] ;
if ( F_39 ( V_16 ) != 0 ) {
T_4 * V_13 = ( T_4 * ) F_40 ( V_16 ) ;
V_34 [ V_30 ] = F_41 ( 0 ) ;
F_13 ( F_39 ( V_16 ) >> V_14 ) ;
F_42 ( V_2 , V_13 ) ;
}
}
}
static void F_43 ( struct V_1 * V_2 , T_6 * V_16 , T_4 * V_29 [] )
{
T_5 * V_15 ;
unsigned long V_35 ;
int V_30 ;
if ( V_31 == 0 )
return;
V_15 = F_44 ( V_16 , 0 ) ;
for ( V_35 = V_30 = 0 ; V_30 < V_31 ;
V_30 ++ , V_15 ++ , V_35 += V_36 ) {
T_4 * V_13 = V_29 [ V_30 ] ;
if ( V_30 >= V_23 )
memcpy ( V_13 , ( T_4 * ) F_40 ( V_24 [ V_30 ] ) ,
sizeof( T_4 ) * V_37 ) ;
F_30 ( V_2 , V_15 , V_13 ) ;
}
}
T_6 * F_45 ( struct V_1 * V_2 )
{
T_6 * V_16 ;
T_4 * V_29 [ V_31 ] ;
V_16 = ( T_6 * ) F_2 ( V_4 ) ;
if ( V_16 == NULL )
goto V_38;
V_2 -> V_16 = V_16 ;
if ( F_37 ( V_29 ) != 0 )
goto V_39;
if ( F_46 ( V_2 ) != 0 )
goto V_40;
F_28 ( & V_26 ) ;
F_25 ( V_2 , V_16 ) ;
F_43 ( V_2 , V_16 , V_29 ) ;
F_29 ( & V_26 ) ;
return V_16 ;
V_40:
F_35 ( V_29 ) ;
V_39:
F_36 ( ( unsigned long ) V_16 ) ;
V_38:
return NULL ;
}
void F_47 ( struct V_1 * V_2 , T_6 * V_16 )
{
F_38 ( V_2 , V_16 ) ;
F_27 ( V_16 ) ;
F_48 ( V_2 , V_16 ) ;
F_36 ( ( unsigned long ) V_16 ) ;
}
int F_49 ( struct V_41 * V_42 ,
unsigned long V_3 , T_1 * V_43 ,
T_1 V_44 , int V_45 )
{
int V_46 = ! F_50 ( * V_43 , V_44 ) ;
if ( V_46 && V_45 ) {
* V_43 = V_44 ;
F_51 ( V_42 -> V_47 , V_3 , V_43 ) ;
}
return V_46 ;
}
int F_52 ( struct V_41 * V_42 ,
unsigned long V_3 , T_4 * V_48 ,
T_4 V_44 , int V_45 )
{
int V_46 = ! F_53 ( * V_48 , V_44 ) ;
F_54 ( V_3 & ~ V_49 ) ;
if ( V_46 && V_45 ) {
* V_48 = V_44 ;
F_55 ( V_42 -> V_47 , V_3 , V_48 ) ;
F_56 ( V_42 , V_3 , V_3 + V_50 ) ;
}
return V_46 ;
}
int F_57 ( struct V_41 * V_42 ,
unsigned long V_35 , T_1 * V_43 )
{
int V_51 = 0 ;
if ( F_58 ( * V_43 ) )
V_51 = F_59 ( V_52 ,
( unsigned long * ) & V_43 -> V_6 ) ;
if ( V_51 )
F_60 ( V_42 -> V_47 , V_35 , V_43 ) ;
return V_51 ;
}
int F_61 ( struct V_41 * V_42 ,
unsigned long V_35 , T_4 * V_48 )
{
int V_51 = 0 ;
if ( F_62 ( * V_48 ) )
V_51 = F_59 ( V_52 ,
( unsigned long * ) V_48 ) ;
if ( V_51 )
F_63 ( V_42 -> V_47 , V_35 , V_48 ) ;
return V_51 ;
}
int F_64 ( struct V_41 * V_42 ,
unsigned long V_3 , T_1 * V_43 )
{
int V_53 ;
V_53 = F_57 ( V_42 , V_3 , V_43 ) ;
if ( V_53 )
F_65 ( V_42 , V_3 ) ;
return V_53 ;
}
int F_66 ( struct V_41 * V_42 ,
unsigned long V_3 , T_4 * V_48 )
{
int V_53 ;
F_54 ( V_3 & ~ V_49 ) ;
V_53 = F_61 ( V_42 , V_3 , V_48 ) ;
if ( V_53 )
F_56 ( V_42 , V_3 , V_3 + V_50 ) ;
return V_53 ;
}
void F_67 ( struct V_41 * V_42 ,
unsigned long V_3 , T_4 * V_48 )
{
int V_54 ;
F_54 ( V_3 & ~ V_49 ) ;
V_54 = ! F_68 ( V_55 ,
( unsigned long * ) V_48 ) ;
if ( V_54 ) {
F_63 ( V_42 -> V_47 , V_3 , V_48 ) ;
F_56 ( V_42 , V_3 , V_3 + V_50 ) ;
}
}
void T_3 F_69 ( unsigned long V_56 )
{
#ifdef F_70
F_71 ( V_57 > 0 ) ;
F_72 ( V_58 L_2 ,
( int ) - V_56 ) ;
V_59 = - V_56 - V_60 ;
#endif
}
void F_73 ( enum V_61 V_62 , T_1 V_6 )
{
unsigned long V_3 = F_74 ( V_62 ) ;
if ( V_62 >= V_63 ) {
F_75 () ;
return;
}
F_76 ( V_3 , V_6 ) ;
V_57 ++ ;
}
void F_77 ( enum V_61 V_62 , T_7 V_64 ,
T_8 V_65 )
{
F_73 ( V_62 , F_78 ( V_64 >> V_14 , V_65 ) ) ;
}
