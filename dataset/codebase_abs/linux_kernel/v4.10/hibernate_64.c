static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) F_2 ( V_4 ) ;
if ( ! V_3 )
return - V_5 ;
V_2 = ( T_2 * ) F_2 ( V_4 ) ;
if ( ! V_2 )
return - V_5 ;
F_3 ( V_2 + F_4 ( V_6 ) ,
F_5 ( ( V_7 & V_8 ) | V_9 ) ) ;
F_6 ( V_3 + F_7 ( V_6 ) ,
F_8 ( F_9 ( V_2 ) | V_10 ) ) ;
F_10 ( V_1 + F_11 ( V_6 ) ,
F_12 ( F_9 ( V_3 ) | V_10 ) ) ;
return 0 ;
}
static void * F_13 ( void * V_11 )
{
return ( void * ) F_2 ( V_4 ) ;
}
static int F_14 ( void )
{
struct V_12 V_13 = {
. F_13 = F_13 ,
. V_14 = V_9 ,
. V_15 = V_16 ,
} ;
unsigned long V_17 , V_18 ;
T_1 * V_1 ;
int V_19 ;
int V_20 ;
V_1 = ( T_1 * ) F_2 ( V_4 ) ;
if ( ! V_1 )
return - V_5 ;
V_19 = F_1 ( V_1 ) ;
if ( V_19 )
return V_19 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_17 = V_22 [ V_20 ] . V_23 << V_24 ;
V_18 = V_22 [ V_20 ] . V_25 << V_24 ;
V_19 = F_15 ( & V_13 , V_1 , V_17 , V_18 ) ;
if ( V_19 )
return V_19 ;
}
V_26 = F_9 ( V_1 ) ;
return 0 ;
}
static int F_16 ( void )
{
T_1 * V_1 ;
T_3 * V_3 ;
V_27 = F_2 ( V_4 ) ;
if ( ! V_27 )
return - V_5 ;
memcpy ( ( void * ) V_27 , & V_28 , V_29 ) ;
V_1 = ( T_1 * ) F_17 ( F_18 () ) + F_11 ( V_27 ) ;
V_3 = F_19 ( V_1 , V_27 ) ;
if ( F_20 ( * V_3 ) ) {
F_6 ( V_3 , F_8 ( F_21 ( * V_3 ) & ~ V_30 ) ) ;
} else {
T_2 * V_2 = F_22 ( V_3 , V_27 ) ;
if ( F_23 ( * V_2 ) ) {
F_3 ( V_2 , F_5 ( F_24 ( * V_2 ) & ~ V_30 ) ) ;
} else {
T_4 * V_31 = F_25 ( V_2 , V_27 ) ;
F_26 ( V_31 , F_27 ( F_28 ( * V_31 ) & ~ V_30 ) ) ;
}
}
F_29 () ;
return 0 ;
}
int F_30 ( void )
{
int error ;
error = F_14 () ;
if ( error )
return error ;
error = F_16 () ;
if ( error )
return error ;
F_31 () ;
return 0 ;
}
int F_32 ( unsigned long V_32 )
{
unsigned long V_33 = F_33 ( & V_34 ) >> V_24 ;
unsigned long V_35 = F_34 ( F_33 ( & V_36 ) ) >> V_24 ;
return ( V_32 >= V_33 ) && ( V_32 < V_35 ) ;
}
static int F_35 ( struct V_37 * V_38 , void * V_39 )
{
struct V_40 V_41 ;
struct V_42 * V_43 ;
int V_44 ;
int V_45 = 0 ;
V_43 = F_36 ( L_1 , 0 , V_46 ) ;
if ( F_37 ( V_43 ) )
return - V_5 ;
{
F_38 ( V_47 , V_43 ) ;
V_44 = F_39 ( struct V_37 , V_38 )
+ sizeof( struct V_48 ) * V_38 -> V_49 ;
F_40 ( V_47 , V_43 ) ;
F_41 ( & V_41 , ( V_50 * ) V_38 , V_44 ) ;
F_42 ( V_47 , 0 , NULL , NULL ) ;
F_43 ( V_47 , & V_41 , V_39 , V_44 ) ;
if ( F_44 ( V_47 ) )
V_45 = - V_51 ;
F_45 ( V_47 ) ;
}
F_46 ( V_43 ) ;
return V_45 ;
}
static void F_47 ( void * V_39 )
{
F_35 ( V_52 , V_39 ) ;
}
static bool F_48 ( void * V_39 )
{
int V_45 ;
V_50 V_19 [ V_53 ] ;
memset ( V_19 , 0 , V_53 ) ;
if ( ! memcmp ( V_19 , V_39 , V_53 ) )
return false ;
V_45 = F_35 ( V_52 , V_19 ) ;
if ( V_45 )
return true ;
return memcmp ( V_19 , V_39 , V_53 ) ? true : false ;
}
static void F_47 ( void * V_39 )
{
}
static bool F_48 ( void * V_39 )
{
return false ;
}
int F_49 ( void * V_54 , unsigned int V_55 )
{
struct V_56 * V_57 = V_54 ;
if ( V_55 < sizeof( struct V_56 ) )
return - V_58 ;
V_57 -> V_59 = ( unsigned long ) & V_60 ;
V_57 -> V_7 = F_33 ( & V_60 ) ;
V_57 -> V_61 = V_62 ;
V_57 -> V_63 = V_64 ;
F_47 ( V_57 -> V_65 ) ;
return 0 ;
}
int F_50 ( void * V_54 )
{
struct V_56 * V_57 = V_54 ;
V_6 = V_57 -> V_59 ;
V_7 = V_57 -> V_7 ;
V_62 = V_57 -> V_61 ;
if ( V_57 -> V_63 != V_64 ) {
F_51 ( L_2 ) ;
return - V_51 ;
}
if ( F_48 ( V_57 -> V_65 ) ) {
F_51 ( L_3 ) ;
return - V_66 ;
}
return 0 ;
}
