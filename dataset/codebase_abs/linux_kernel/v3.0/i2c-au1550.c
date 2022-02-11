static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
volatile T_2 * V_5 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ ) {
V_3 = V_5 -> V_8 ;
F_2 () ;
if ( ( V_3 & V_9 ) != 0 )
return 0 ;
F_3 ( 1 ) ;
}
return - V_10 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
volatile T_2 * V_5 ;
if ( F_1 ( V_2 ) )
return - V_10 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
V_3 = V_5 -> V_11 ;
F_2 () ;
if ( ( V_3 & ( V_12 | V_13 | V_14 ) ) != 0 )
return - V_10 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
volatile T_2 * V_5 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ ) {
V_3 = V_5 -> V_11 ;
F_2 () ;
if ( ( V_3 & V_15 ) != 0 )
return 0 ;
F_3 ( 1 ) ;
}
return - V_10 ;
}
static int
F_6 ( struct V_1 * V_2 , unsigned int V_16 , int V_17 , int V_18 )
{
volatile T_2 * V_5 ;
T_1 V_3 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
V_3 = V_5 -> V_8 ;
V_5 -> V_11 = V_19 ;
F_2 () ;
if ( ! ( V_3 & V_9 ) || ! ( V_3 & V_20 ) ) {
V_5 -> V_21 = V_22 ;
F_2 () ;
do {
V_3 = V_5 -> V_21 ;
F_2 () ;
} while ( ( V_3 & V_22 ) != 0 );
F_3 ( 50 ) ;
}
V_16 <<= 1 ;
if ( V_17 )
V_16 |= 1 ;
if ( V_18 )
V_16 |= V_23 ;
V_5 -> V_24 = V_16 ;
F_2 () ;
V_5 -> V_21 = V_25 ;
F_2 () ;
if ( F_4 ( V_2 ) )
return - V_26 ;
return ( V_18 ) ? F_5 ( V_2 ) : 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 , T_1 * V_27 )
{
int V_28 ;
T_1 V_29 , V_3 ;
volatile T_2 * V_5 ;
if ( F_1 ( V_2 ) )
return - V_26 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
V_28 = V_2 -> V_7 * 100 ;
do {
V_28 -- ;
if ( V_28 <= 0 )
return - V_26 ;
V_3 = V_5 -> V_8 ;
F_2 () ;
if ( ( V_3 & V_20 ) == 0 )
V_28 = 0 ;
else
F_3 ( 1 ) ;
} while ( V_28 > 0 );
V_29 = V_5 -> V_24 ;
F_2 () ;
* V_27 = V_29 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , unsigned char * V_30 ,
unsigned int V_31 )
{
int V_4 ;
T_1 V_29 ;
volatile T_2 * V_5 ;
if ( V_31 == 0 )
return 0 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
V_4 = 0 ;
while ( V_4 < ( V_31 - 1 ) ) {
V_5 -> V_24 = 0 ;
F_2 () ;
if ( F_7 ( V_2 , & V_29 ) )
return - V_26 ;
V_30 [ V_4 ] = V_29 ;
V_4 ++ ;
}
V_5 -> V_24 = V_23 ;
F_2 () ;
if ( F_5 ( V_2 ) )
return - V_26 ;
V_29 = V_5 -> V_24 ;
F_2 () ;
V_30 [ V_4 ] = V_29 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , unsigned char * V_30 ,
unsigned int V_31 )
{
int V_4 ;
T_1 V_29 ;
volatile T_2 * V_5 ;
if ( V_31 == 0 )
return 0 ;
V_5 = ( volatile T_2 * ) ( V_2 -> V_6 ) ;
V_4 = 0 ;
while ( V_4 < ( V_31 - 1 ) ) {
V_29 = V_30 [ V_4 ] ;
V_5 -> V_24 = V_29 ;
F_2 () ;
if ( F_4 ( V_2 ) )
return - V_26 ;
V_4 ++ ;
}
V_29 = V_30 [ V_4 ] ;
V_29 |= V_23 ;
V_5 -> V_24 = V_29 ;
F_2 () ;
if ( F_5 ( V_2 ) )
return - V_26 ;
return 0 ;
}
static int
F_10 ( struct V_32 * V_33 , struct V_34 * V_35 , int V_36 )
{
struct V_1 * V_2 = V_33 -> V_37 ;
volatile T_2 * V_5 = ( volatile T_2 * ) V_2 -> V_6 ;
struct V_34 * V_38 ;
int V_4 , V_39 = 0 ;
V_5 -> V_40 = V_41 ;
F_2 () ;
for ( V_4 = 0 ; ! V_39 && V_4 < V_36 ; V_4 ++ ) {
V_38 = & V_35 [ V_4 ] ;
V_39 = F_6 ( V_2 , V_38 -> V_16 , V_38 -> V_42 & V_43 ,
( V_38 -> V_31 == 0 ) ) ;
if ( V_39 || ! V_38 -> V_31 )
continue;
if ( V_38 -> V_42 & V_43 )
V_39 = F_8 ( V_2 , V_38 -> V_30 , V_38 -> V_31 ) ;
else
V_39 = F_9 ( V_2 , V_38 -> V_30 , V_38 -> V_31 ) ;
}
if ( V_39 == 0 )
V_39 = V_36 ;
V_5 -> V_40 = V_44 ;
F_2 () ;
return V_39 ;
}
static T_1
F_11 ( struct V_32 * V_2 )
{
return V_45 | V_46 ;
}
static void F_12 ( struct V_1 * V_47 )
{
volatile T_2 * V_5 = ( volatile T_2 * ) V_47 -> V_6 ;
T_1 V_3 ;
V_5 -> V_40 = V_48 ;
F_2 () ;
V_5 -> V_49 = V_50 ;
V_5 -> V_51 = 0 ;
F_2 () ;
V_5 -> V_40 = V_41 ;
F_2 () ;
do {
V_3 = V_5 -> V_8 ;
F_2 () ;
} while ( ( V_3 & V_52 ) == 0 );
V_5 -> V_51 = ( V_53 | V_54 |
V_55 ) ;
V_5 -> V_51 |= F_13 ( V_56 ) ;
V_5 -> V_57 = V_58 ;
F_2 () ;
V_5 -> V_59 = F_14 ( 0 ) | F_15 ( 15 ) | \
F_16 ( 15 ) | F_17 ( 15 ) | \
F_18 ( 15 ) | F_19 ( 15 ) | \
F_20 ( 15 ) ;
F_2 () ;
V_5 -> V_51 |= V_60 ;
do {
V_3 = V_5 -> V_8 ;
F_2 () ;
} while ( ( V_3 & V_52 ) == 0 );
V_5 -> V_40 = V_44 ;
F_2 () ;
}
static void F_21 ( struct V_1 * V_47 )
{
volatile T_2 * V_5 = ( volatile T_2 * ) V_47 -> V_6 ;
V_5 -> V_51 = 0 ;
V_5 -> V_40 = V_48 ;
F_2 () ;
}
static int T_3
F_22 ( struct V_61 * V_62 )
{
struct V_1 * V_47 ;
struct V_63 * V_64 ;
int V_65 ;
V_64 = F_23 ( V_62 , V_66 , 0 ) ;
if ( ! V_64 ) {
V_65 = - V_67 ;
goto V_68;
}
V_47 = F_24 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_47 ) {
V_65 = - V_70 ;
goto V_68;
}
V_47 -> V_71 = F_25 ( V_64 -> V_72 , F_26 ( V_64 ) ,
V_62 -> V_73 ) ;
if ( ! V_47 -> V_71 ) {
V_65 = - V_74 ;
goto V_75;
}
V_47 -> V_6 = F_27 ( V_64 -> V_72 ) ;
V_47 -> V_7 = 200 ;
V_47 -> V_76 = 200 ;
V_47 -> V_2 . V_77 = V_62 -> V_78 ;
V_47 -> V_2 . V_79 = & V_80 ;
V_47 -> V_2 . V_37 = V_47 ;
V_47 -> V_2 . V_81 . V_82 = & V_62 -> V_81 ;
F_28 ( V_47 -> V_2 . V_73 , L_1 , sizeof( V_47 -> V_2 . V_73 ) ) ;
F_12 ( V_47 ) ;
V_65 = F_29 ( & V_47 -> V_2 ) ;
if ( V_65 == 0 ) {
F_30 ( V_62 , V_47 ) ;
return 0 ;
}
F_21 ( V_47 ) ;
F_31 ( V_47 -> V_71 ) ;
F_32 ( V_47 -> V_71 ) ;
V_75:
F_32 ( V_47 ) ;
V_68:
return V_65 ;
}
static int T_4
F_33 ( struct V_61 * V_62 )
{
struct V_1 * V_47 = F_34 ( V_62 ) ;
F_30 ( V_62 , NULL ) ;
F_35 ( & V_47 -> V_2 ) ;
F_21 ( V_47 ) ;
F_31 ( V_47 -> V_71 ) ;
F_32 ( V_47 -> V_71 ) ;
F_32 ( V_47 ) ;
return 0 ;
}
static int
F_36 ( struct V_61 * V_62 , T_5 V_83 )
{
struct V_1 * V_47 = F_34 ( V_62 ) ;
F_21 ( V_47 ) ;
return 0 ;
}
static int
F_37 ( struct V_61 * V_62 )
{
struct V_1 * V_47 = F_34 ( V_62 ) ;
F_12 ( V_47 ) ;
return 0 ;
}
static int T_6
F_38 ( void )
{
return F_39 ( & V_84 ) ;
}
static void T_7
F_40 ( void )
{
F_41 ( & V_84 ) ;
}
