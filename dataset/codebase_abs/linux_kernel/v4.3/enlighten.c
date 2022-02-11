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
V_13 . V_19 = F_10 ( V_15 ) >> V_20 ;
V_13 . V_21 = F_11 ( V_15 ) ;
V_16 = F_12 ( V_22 , V_17 , & V_13 ) ;
F_13 ( V_16 ) ;
F_14 ( V_23 , V_17 ) = V_15 ;
F_15 ( V_24 , 0 ) ;
F_16 () ;
}
static void F_17 ( enum V_25 V_25 , const char * V_26 )
{
struct V_27 V_28 = { . V_29 = V_30 } ;
int V_31 ;
V_31 = F_18 ( V_32 , & V_28 ) ;
F_13 ( V_31 ) ;
}
static void F_19 ( void )
{
struct V_27 V_28 = { . V_29 = V_33 } ;
int V_31 ;
V_31 = F_18 ( V_32 , & V_28 ) ;
F_13 ( V_31 ) ;
}
static int F_20 ( struct V_34 * V_35 ,
unsigned long V_36 ,
void * V_37 )
{
switch ( V_36 ) {
case V_38 :
F_6 () ;
break;
default:
break;
}
return V_39 ;
}
static T_3 F_21 ( int V_40 , void * V_41 )
{
F_22 () ;
return V_42 ;
}
void T_4 F_23 ( void )
{
int V_43 ;
const char * V_44 = NULL ;
const char * V_45 = NULL ;
const char * V_46 = L_2 ;
V_47 = F_24 ( NULL , NULL , L_3 ) ;
if ( ! V_47 ) {
F_25 ( L_4 ) ;
return;
}
V_44 = F_26 ( V_47 , L_5 , & V_43 ) ;
if ( strlen ( V_46 ) + 3 < V_43 &&
! strncmp ( V_46 , V_44 , strlen ( V_46 ) ) )
V_45 = V_44 + strlen ( V_46 ) ;
if ( V_45 == NULL ) {
F_25 ( L_6 ) ;
return;
}
F_8 ( L_7 , V_45 ) ;
V_48 = V_49 ;
F_27 () ;
if ( F_28 ( V_50 ) )
V_51 -> V_52 |= V_53 | V_54 ;
else
V_51 -> V_52 &= ~ ( V_53 | V_54 ) ;
if ( ! V_55 && ! F_29 () )
F_30 ( L_8 , 0 , NULL ) ;
}
static int T_4 F_31 ( void )
{
struct V_56 V_57 ;
struct V_58 * V_59 = NULL ;
struct V_60 V_61 ;
T_5 V_62 ;
if ( ! F_32 () )
return 0 ;
if ( F_33 ( V_47 , V_63 , & V_61 ) ) {
F_34 ( L_9 ) ;
return - V_64 ;
}
V_62 = V_61 . V_65 ;
V_24 = F_35 ( V_47 , 0 ) ;
if ( ! V_24 ) {
F_34 ( L_10 ) ;
return - V_64 ;
}
V_59 = (struct V_58 * ) F_36 ( V_66 ) ;
if ( ! V_59 ) {
F_34 ( L_11 ) ;
return - V_67 ;
}
V_57 . V_8 = V_68 ;
V_57 . V_69 = 0 ;
V_57 . V_70 = V_71 ;
V_57 . V_72 = F_10 ( V_59 ) >> V_20 ;
if ( F_37 ( V_73 , & V_57 ) )
F_38 () ;
V_74 = (struct V_58 * ) V_59 ;
V_18 = F_39 ( sizeof( struct V_14 ) ,
sizeof( struct V_14 ) ) ;
if ( V_18 == NULL )
return - V_67 ;
if ( F_40 ( V_62 ) ) {
F_41 ( V_18 ) ;
return - V_67 ;
}
F_42 () ;
if ( ! F_29 () )
F_43 ( NULL ) ;
F_44 () ;
F_45 () ;
F_46 () ;
if ( F_47 ( V_24 , F_21 ,
L_12 , & V_23 ) ) {
F_34 ( L_13 , V_24 ) ;
return - V_75 ;
}
F_6 () ;
F_48 ( & V_76 ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
if ( ! F_32 () )
return - V_64 ;
V_77 = F_19 ;
V_78 = F_17 ;
return 0 ;
}
void F_50 ( void ) { }
void F_51 ( int V_79 ) { }
void F_52 ( void ) { }
void F_53 ( void ) { }
void F_54 ( void ) { }
