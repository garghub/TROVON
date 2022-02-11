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
void T_4 F_23 ( void )
{
int V_42 ;
const char * V_43 = NULL ;
const char * V_44 = NULL ;
const char * V_45 = L_2 ;
V_46 = F_24 ( NULL , NULL , L_3 ) ;
if ( ! V_46 ) {
F_25 ( L_4 ) ;
return;
}
V_43 = F_26 ( V_46 , L_5 , & V_42 ) ;
if ( strlen ( V_45 ) + 3 < V_42 &&
! strncmp ( V_45 , V_43 , strlen ( V_45 ) ) )
V_44 = V_43 + strlen ( V_45 ) ;
if ( V_44 == NULL ) {
F_25 ( L_6 ) ;
return;
}
F_8 ( L_7 , V_44 ) ;
V_47 = V_48 ;
F_27 () ;
if ( F_28 ( V_49 ) )
V_50 -> V_51 |= V_52 | V_53 ;
else
V_50 -> V_51 &= ~ ( V_52 | V_53 ) ;
if ( ! V_54 && ! F_29 () )
F_30 ( L_8 , 0 , NULL ) ;
}
static int T_4 F_31 ( void )
{
struct V_55 V_56 ;
struct V_57 * V_58 = NULL ;
struct V_59 V_60 ;
T_5 V_61 ;
if ( ! F_32 () )
return 0 ;
if ( F_33 ( V_46 , V_62 , & V_60 ) ) {
F_34 ( L_9 ) ;
return - V_63 ;
}
V_61 = V_60 . V_64 ;
V_23 = F_35 ( V_46 , 0 ) ;
if ( ! V_23 ) {
F_34 ( L_10 ) ;
return - V_63 ;
}
V_58 = (struct V_57 * ) F_36 ( V_65 ) ;
if ( ! V_58 ) {
F_34 ( L_11 ) ;
return - V_66 ;
}
V_56 . V_8 = V_67 ;
V_56 . V_68 = 0 ;
V_56 . V_69 = V_70 ;
V_56 . V_71 = F_10 ( V_58 ) >> V_19 ;
if ( F_37 ( V_72 , & V_56 ) )
F_38 () ;
V_73 = (struct V_57 * ) V_58 ;
V_18 = F_39 ( sizeof( struct V_14 ) ,
sizeof( struct V_14 ) ) ;
if ( V_18 == NULL )
return - V_66 ;
if ( F_40 ( V_61 ) ) {
F_41 ( V_18 ) ;
return - V_66 ;
}
F_42 () ;
if ( ! F_29 () )
F_43 ( NULL ) ;
F_44 () ;
F_45 () ;
F_46 () ;
if ( F_47 ( V_23 , F_21 ,
L_12 , & V_22 ) ) {
F_34 ( L_13 , V_23 ) ;
return - V_74 ;
}
F_6 () ;
F_48 ( & V_75 ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
if ( ! F_32 () )
return - V_63 ;
V_76 = F_19 ;
V_77 = F_17 ;
return 0 ;
}
void F_50 ( void ) { }
void F_51 ( int V_78 ) { }
void F_52 ( void ) { }
void F_53 ( void ) { }
void F_54 ( void ) { }
