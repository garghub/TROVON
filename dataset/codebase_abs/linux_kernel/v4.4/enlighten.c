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
if ( F_8 ( V_18 , V_17 ) != NULL )
goto V_19;
F_9 ( L_1 , V_17 ) ;
V_15 = F_10 ( V_20 , V_17 ) ;
V_13 . V_21 = F_11 ( V_15 ) ;
V_13 . V_22 = F_12 ( V_15 ) ;
V_16 = F_13 ( V_23 , V_17 , & V_13 ) ;
F_14 ( V_16 ) ;
F_8 ( V_18 , V_17 ) = V_15 ;
V_19:
F_15 ( V_24 , 0 ) ;
F_16 () ;
}
static void F_17 ( enum V_25 V_25 , const char * V_26 )
{
struct V_27 V_28 = { . V_29 = V_30 } ;
int V_31 ;
V_31 = F_18 ( V_32 , & V_28 ) ;
F_14 ( V_31 ) ;
}
static void F_19 ( void )
{
struct V_27 V_28 = { . V_29 = V_33 } ;
int V_31 ;
V_31 = F_18 ( V_32 , & V_28 ) ;
F_14 ( V_31 ) ;
}
static int F_20 ( struct V_34 * V_35 ,
unsigned long V_36 ,
void * V_37 )
{
switch ( V_36 ) {
case V_38 :
F_6 () ;
break;
case V_39 :
F_21 ( V_24 ) ;
break;
default:
break;
}
return V_40 ;
}
static T_3 F_22 ( int V_41 , void * V_42 )
{
F_23 () ;
return V_43 ;
}
void T_4 F_24 ( void )
{
int V_44 ;
const char * V_45 = NULL ;
const char * V_46 = NULL ;
const char * V_47 = L_2 ;
V_48 = F_25 ( NULL , NULL , L_3 ) ;
if ( ! V_48 ) {
F_26 ( L_4 ) ;
return;
}
V_45 = F_27 ( V_48 , L_5 , & V_44 ) ;
if ( strlen ( V_47 ) + 3 < V_44 &&
! strncmp ( V_47 , V_45 , strlen ( V_47 ) ) )
V_46 = V_45 + strlen ( V_47 ) ;
if ( V_46 == NULL ) {
F_26 ( L_6 ) ;
return;
}
F_9 ( L_7 , V_46 ) ;
V_49 = V_50 ;
F_28 () ;
if ( F_29 ( V_51 ) )
V_52 -> V_53 |= V_54 | V_55 ;
else
V_52 -> V_53 &= ~ ( V_54 | V_55 ) ;
if ( ! V_56 && ! F_30 () )
F_31 ( L_8 , 0 , NULL ) ;
}
static int T_4 F_32 ( void )
{
struct V_57 V_58 ;
struct V_59 * V_60 = NULL ;
struct V_61 V_62 ;
T_5 V_63 ;
if ( ! F_33 () )
return 0 ;
if ( F_34 ( V_48 , V_64 , & V_62 ) ) {
F_35 ( L_9 ) ;
return - V_65 ;
}
V_63 = V_62 . V_66 ;
V_24 = F_36 ( V_48 , 0 ) ;
if ( ! V_24 ) {
F_35 ( L_10 ) ;
return - V_65 ;
}
V_60 = (struct V_59 * ) F_37 ( V_67 ) ;
if ( ! V_60 ) {
F_35 ( L_11 ) ;
return - V_68 ;
}
V_58 . V_8 = V_69 ;
V_58 . V_70 = 0 ;
V_58 . V_71 = V_72 ;
V_58 . V_73 = F_11 ( V_60 ) ;
if ( F_38 ( V_74 , & V_58 ) )
F_39 () ;
V_75 = (struct V_59 * ) V_60 ;
V_20 = F_40 ( sizeof( struct V_14 ) ,
sizeof( struct V_14 ) ) ;
if ( V_20 == NULL )
return - V_68 ;
if ( F_41 ( V_63 ) ) {
F_42 ( V_20 ) ;
return - V_68 ;
}
F_43 () ;
if ( ! F_30 () )
F_44 ( NULL ) ;
F_45 () ;
F_46 () ;
F_47 () ;
if ( F_48 ( V_24 , F_22 ,
L_12 , & V_18 ) ) {
F_35 ( L_13 , V_24 ) ;
return - V_76 ;
}
F_6 () ;
F_49 ( & V_77 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
if ( ! F_33 () )
return - V_65 ;
V_78 = F_19 ;
V_79 = F_17 ;
return 0 ;
}
void F_51 ( void ) { }
void F_52 ( int V_80 ) { }
void F_53 ( void ) { }
void F_54 ( void ) { }
void F_55 ( void ) { }
