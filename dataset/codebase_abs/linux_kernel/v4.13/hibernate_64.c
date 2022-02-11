static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_3 * V_3 ;
T_4 * V_4 ;
if ( F_2 ( V_5 ) ) {
V_4 = ( T_4 * ) F_3 ( V_6 ) ;
if ( ! V_4 )
return - V_7 ;
}
V_3 = ( T_3 * ) F_3 ( V_6 ) ;
if ( ! V_3 )
return - V_7 ;
V_2 = ( T_2 * ) F_3 ( V_6 ) ;
if ( ! V_2 )
return - V_7 ;
F_4 ( V_2 + F_5 ( V_8 ) ,
F_6 ( ( V_9 & V_10 ) | V_11 ) ) ;
F_7 ( V_3 + F_8 ( V_8 ) ,
F_9 ( F_10 ( V_2 ) | V_12 ) ) ;
if ( F_2 ( V_5 ) ) {
F_11 ( V_4 + F_12 ( V_8 ) , F_13 ( F_10 ( V_3 ) | V_12 ) ) ;
F_14 ( V_1 + F_15 ( V_8 ) , F_16 ( F_10 ( V_4 ) | V_12 ) ) ;
} else {
F_14 ( V_1 + F_15 ( V_8 ) , F_16 ( F_10 ( V_3 ) | V_12 ) ) ;
}
return 0 ;
}
static void * F_17 ( void * V_13 )
{
return ( void * ) F_3 ( V_6 ) ;
}
static int F_18 ( void )
{
struct V_14 V_15 = {
. F_17 = F_17 ,
. V_16 = V_11 ,
. V_17 = V_18 ,
} ;
unsigned long V_19 , V_20 ;
T_1 * V_1 ;
int V_21 ;
int V_22 ;
V_1 = ( T_1 * ) F_3 ( V_6 ) ;
if ( ! V_1 )
return - V_7 ;
V_21 = F_1 ( V_1 ) ;
if ( V_21 )
return V_21 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_19 = V_24 [ V_22 ] . V_25 << V_26 ;
V_20 = V_24 [ V_22 ] . V_27 << V_26 ;
V_21 = F_19 ( & V_15 , V_1 , V_19 , V_20 ) ;
if ( V_21 )
return V_21 ;
}
V_28 = F_10 ( V_1 ) ;
return 0 ;
}
static int F_20 ( void )
{
T_1 * V_1 ;
T_4 * V_4 ;
T_3 * V_3 ;
T_2 * V_2 ;
T_5 * V_29 ;
V_30 = F_3 ( V_6 ) ;
if ( ! V_30 )
return - V_7 ;
memcpy ( ( void * ) V_30 , V_31 , V_32 ) ;
V_1 = ( T_1 * ) F_21 ( F_22 () ) +
F_15 ( V_30 ) ;
V_4 = F_23 ( V_1 , V_30 ) ;
if ( F_24 ( * V_4 ) ) {
F_11 ( V_4 , F_13 ( F_25 ( * V_4 ) & ~ V_33 ) ) ;
goto V_34;
}
V_3 = F_26 ( V_4 , V_30 ) ;
if ( F_27 ( * V_3 ) ) {
F_7 ( V_3 , F_9 ( F_28 ( * V_3 ) & ~ V_33 ) ) ;
goto V_34;
}
V_2 = F_29 ( V_3 , V_30 ) ;
if ( F_30 ( * V_2 ) ) {
F_4 ( V_2 , F_6 ( F_31 ( * V_2 ) & ~ V_33 ) ) ;
goto V_34;
}
V_29 = F_32 ( V_2 , V_30 ) ;
F_33 ( V_29 , F_34 ( F_35 ( * V_29 ) & ~ V_33 ) ) ;
V_34:
F_36 () ;
return 0 ;
}
int F_37 ( void )
{
int error ;
error = F_18 () ;
if ( error )
return error ;
error = F_20 () ;
if ( error )
return error ;
F_38 () ;
return 0 ;
}
int F_39 ( unsigned long V_35 )
{
unsigned long V_36 = F_40 ( & V_37 ) >> V_26 ;
unsigned long V_38 = F_41 ( F_40 ( & V_39 ) ) >> V_26 ;
return ( V_35 >= V_36 ) && ( V_35 < V_38 ) ;
}
static int F_42 ( struct V_40 * V_41 , void * V_42 )
{
struct V_43 V_44 ;
struct V_45 * V_46 ;
int V_47 ;
int V_48 = 0 ;
V_46 = F_43 ( L_1 , 0 , V_49 ) ;
if ( F_44 ( V_46 ) )
return - V_7 ;
{
F_45 ( V_50 , V_46 ) ;
V_47 = F_46 ( struct V_40 , V_51 ) + sizeof( struct V_52 ) * V_41 -> V_53 ;
F_47 ( V_50 , V_46 ) ;
F_48 ( & V_44 , ( V_54 * ) V_41 , V_47 ) ;
F_49 ( V_50 , 0 , NULL , NULL ) ;
F_50 ( V_50 , & V_44 , V_42 , V_47 ) ;
if ( F_51 ( V_50 ) )
V_48 = - V_55 ;
F_52 ( V_50 ) ;
}
F_53 ( V_46 ) ;
return V_48 ;
}
static void F_54 ( void * V_42 )
{
F_42 ( V_56 , V_42 ) ;
}
static bool F_55 ( void * V_42 )
{
int V_48 ;
V_54 V_21 [ V_57 ] ;
memset ( V_21 , 0 , V_57 ) ;
if ( ! memcmp ( V_21 , V_42 , V_57 ) )
return false ;
V_48 = F_42 ( V_56 , V_21 ) ;
if ( V_48 )
return true ;
return memcmp ( V_21 , V_42 , V_57 ) ? true : false ;
}
static void F_54 ( void * V_42 )
{
}
static bool F_55 ( void * V_42 )
{
return false ;
}
int F_56 ( void * V_58 , unsigned int V_59 )
{
struct V_60 * V_61 = V_58 ;
if ( V_59 < sizeof( struct V_60 ) )
return - V_62 ;
V_61 -> V_63 = ( unsigned long ) V_64 ;
V_61 -> V_9 = F_40 ( V_64 ) ;
V_61 -> V_65 = V_66 ;
V_61 -> V_67 = V_68 ;
F_54 ( V_61 -> V_69 ) ;
return 0 ;
}
int F_57 ( void * V_58 )
{
struct V_60 * V_61 = V_58 ;
V_8 = V_61 -> V_63 ;
V_9 = V_61 -> V_9 ;
V_66 = V_61 -> V_65 ;
if ( V_61 -> V_67 != V_68 ) {
F_58 ( L_2 ) ;
return - V_55 ;
}
if ( F_55 ( V_61 -> V_69 ) ) {
F_58 ( L_3 ) ;
return - V_70 ;
}
return 0 ;
}
