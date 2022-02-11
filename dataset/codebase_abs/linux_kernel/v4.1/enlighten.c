int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 * V_4 , int V_5 ,
int * V_6 , T_2 V_7 ,
unsigned V_8 ,
struct V_9 * * V_10 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_10 ) ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 V_4 , int V_5 ,
T_2 V_7 , unsigned V_8 ,
struct V_9 * * V_10 )
{
return - V_11 ;
}
int F_4 ( struct V_1 * V_2 ,
int V_5 , struct V_9 * * V_10 )
{
return F_5 ( V_2 , V_5 , V_10 ) ;
}
static void F_6 ( void )
{
struct V_12 V_13 ;
struct V_14 * V_15 ;
int V_16 ;
int V_17 = F_7 () ;
F_8 ( L_1 , V_17 ) ;
V_15 = F_9 ( V_18 , V_17 ) ;
V_13 . V_4 = F_10 ( V_15 ) >> V_19 ;
V_13 . V_20 = F_11 ( V_15 ) ;
V_16 = F_12 ( V_21 , V_17 , & V_13 ) ;
F_13 ( V_16 ) ;
F_14 ( V_22 , V_17 ) = V_15 ;
F_15 ( V_23 , 0 ) ;
F_16 () ;
}
static void F_17 ( enum V_24 V_24 , const char * V_25 )
{
struct V_26 V_27 = { . V_28 = V_29 } ;
int V_30 ;
V_30 = F_18 ( V_31 , & V_27 ) ;
F_13 ( V_30 ) ;
}
static void F_19 ( void )
{
struct V_26 V_27 = { . V_28 = V_32 } ;
int V_30 ;
V_30 = F_18 ( V_31 , & V_27 ) ;
F_13 ( V_30 ) ;
}
static int F_20 ( struct V_33 * V_34 ,
unsigned long V_35 ,
void * V_36 )
{
switch ( V_35 ) {
case V_37 :
F_6 () ;
break;
default:
break;
}
return V_38 ;
}
static T_3 F_21 ( int V_39 , void * V_40 )
{
F_22 () ;
return V_41 ;
}
static int T_4 F_23 ( void )
{
struct V_42 V_43 ;
static struct V_44 * V_45 = 0 ;
struct V_46 * V_47 ;
int V_48 ;
const char * V_49 = NULL ;
const char * V_50 = NULL ;
const char * V_51 = L_2 ;
struct V_52 V_53 ;
T_5 V_54 ;
V_47 = F_24 ( NULL , NULL , L_3 ) ;
if ( ! V_47 ) {
F_25 ( L_4 ) ;
return 0 ;
}
V_49 = F_26 ( V_47 , L_5 , & V_48 ) ;
if ( strlen ( V_51 ) + 3 < V_48 &&
! strncmp ( V_51 , V_49 , strlen ( V_51 ) ) )
V_50 = V_49 + strlen ( V_51 ) ;
if ( V_50 == NULL ) {
F_25 ( L_6 ) ;
return 0 ;
}
if ( F_27 ( V_47 , V_55 , & V_53 ) )
return 0 ;
V_54 = V_53 . V_56 ;
V_23 = F_28 ( V_47 , 0 ) ;
F_8 ( L_7 ,
V_50 , V_23 , & V_54 ) ;
if ( V_23 < 0 )
return - V_57 ;
V_58 = V_59 ;
F_29 () ;
if ( F_30 ( V_60 ) )
V_61 -> V_62 |= V_63 | V_64 ;
else
V_61 -> V_62 &= ~ ( V_63 | V_64 ) ;
if ( ! V_45 )
V_45 = (struct V_44 * )
F_31 ( V_65 ) ;
if ( ! V_45 ) {
F_32 ( L_8 ) ;
return - V_66 ;
}
V_43 . V_8 = V_67 ;
V_43 . V_68 = 0 ;
V_43 . V_69 = V_70 ;
V_43 . V_71 = F_10 ( V_45 ) >> V_19 ;
if ( F_33 ( V_72 , & V_43 ) )
F_34 () ;
V_73 = (struct V_44 * ) V_45 ;
V_18 = F_35 ( sizeof( struct V_14 ) ,
sizeof( struct V_14 ) ) ;
if ( V_18 == NULL )
return - V_66 ;
if ( F_36 ( V_54 ) ) {
F_37 ( V_18 ) ;
return - V_66 ;
}
F_38 () ;
if ( ! F_39 () )
F_40 ( NULL ) ;
F_41 () ;
F_42 () ;
F_43 () ;
if ( F_44 ( V_23 , F_21 ,
L_9 , & V_22 ) ) {
F_32 ( L_10 , V_23 ) ;
return - V_74 ;
}
F_6 () ;
F_45 ( & V_75 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
if ( ! F_47 () )
return - V_57 ;
V_76 = F_19 ;
V_77 = F_17 ;
return 0 ;
}
void F_48 ( void ) { }
void F_49 ( int V_78 ) { }
void F_50 ( void ) { }
void F_51 ( void ) { }
void F_52 ( void ) { }
