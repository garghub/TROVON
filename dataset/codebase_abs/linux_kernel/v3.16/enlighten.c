static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 )
{
int V_4 ;
struct V_5 V_6 = {
. V_3 = V_7 ,
. V_8 = V_3 ,
. V_9 = 1 ,
. V_10 = V_11 ,
} ;
T_1 V_12 = V_2 ;
T_2 V_13 = V_1 ;
int V_14 = 0 ;
F_2 ( V_6 . V_15 , & V_12 ) ;
F_2 ( V_6 . V_16 , & V_13 ) ;
F_2 ( V_6 . V_17 , & V_14 ) ;
V_4 = F_3 ( V_18 , & V_6 ) ;
if ( V_4 || V_14 ) {
F_4 ( L_1 ,
V_4 , V_14 , V_1 , V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_5 ( T_3 * V_19 , T_4 V_20 , unsigned long V_21 ,
void * V_22 )
{
struct V_23 * V_24 = V_22 ;
struct V_25 * V_25 = V_24 -> V_26 [ V_24 -> V_27 ++ ] ;
unsigned long V_28 = F_6 ( V_25 ) ;
T_3 V_29 = F_7 ( F_8 ( V_28 , V_24 -> V_30 ) ) ;
if ( F_1 ( V_28 , V_24 -> V_2 , V_24 -> V_3 ) )
return - V_31 ;
F_9 ( V_24 -> V_32 -> V_33 , V_21 , V_19 , V_29 ) ;
return 0 ;
}
int F_10 ( struct V_34 * V_32 ,
unsigned long V_21 ,
T_2 V_35 , int V_36 ,
T_5 V_30 , unsigned V_3 ,
struct V_25 * * V_26 )
{
int V_14 ;
struct V_23 V_22 ;
if ( V_36 > 1 )
return - V_37 ;
V_22 . V_2 = V_35 ;
V_22 . V_30 = V_30 ;
V_22 . V_3 = V_3 ;
V_22 . V_32 = V_32 ;
V_22 . V_27 = 0 ;
V_22 . V_26 = V_26 ;
V_14 = F_11 ( V_32 -> V_33 , V_21 , V_36 << V_38 ,
F_5 , & V_22 ) ;
return V_14 ;
}
int F_12 ( struct V_34 * V_32 ,
int V_36 , struct V_25 * * V_26 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
struct V_40 V_41 ;
unsigned long V_4 , V_28 ;
V_28 = F_6 ( V_26 [ V_39 ] ) ;
V_41 . V_3 = V_7 ;
V_41 . V_13 = V_28 ;
V_4 = F_3 ( V_42 , & V_41 ) ;
if ( V_4 ) {
F_4 ( L_2 ,
V_28 , V_4 ) ;
return V_4 ;
}
}
return 0 ;
}
static void F_13 ( void )
{
struct V_43 V_24 ;
struct V_44 * V_45 ;
int V_14 ;
int V_46 = F_14 () ;
F_15 ( L_3 , V_46 ) ;
V_45 = F_16 ( V_47 , V_46 ) ;
V_24 . V_35 = F_17 ( V_45 ) >> V_38 ;
V_24 . V_48 = F_18 ( V_45 ) ;
V_14 = F_19 ( V_49 , V_46 , & V_24 ) ;
F_20 ( V_14 ) ;
F_21 ( V_50 , V_46 ) = V_45 ;
F_22 ( V_51 , 0 ) ;
F_23 () ;
}
static void F_24 ( enum V_52 V_52 , const char * V_53 )
{
struct V_54 V_55 = { . V_56 = V_57 } ;
int V_4 ;
V_4 = F_25 ( V_58 , & V_55 ) ;
if ( V_4 )
F_26 () ;
}
static void F_27 ( void )
{
struct V_54 V_55 = { . V_56 = V_59 } ;
int V_4 ;
V_4 = F_25 ( V_58 , & V_55 ) ;
if ( V_4 )
F_26 () ;
}
static int F_28 ( struct V_60 * V_61 ,
unsigned long V_62 ,
void * V_63 )
{
switch ( V_62 ) {
case V_64 :
F_13 () ;
break;
default:
break;
}
return V_65 ;
}
static T_6 F_29 ( int V_66 , void * V_67 )
{
F_30 () ;
return V_68 ;
}
static int T_7 F_31 ( void )
{
struct V_69 V_6 ;
static struct V_70 * V_71 = 0 ;
struct V_72 * V_73 ;
int V_74 ;
const char * V_75 = NULL ;
const char * V_76 = NULL ;
const char * V_77 = L_4 ;
struct V_78 V_79 ;
T_8 V_80 ;
V_73 = F_32 ( NULL , NULL , L_5 ) ;
if ( ! V_73 ) {
F_33 ( L_6 ) ;
return 0 ;
}
V_75 = F_34 ( V_73 , L_7 , & V_74 ) ;
if ( strlen ( V_77 ) + 3 < V_74 &&
! strncmp ( V_77 , V_75 , strlen ( V_77 ) ) )
V_76 = V_75 + strlen ( V_77 ) ;
if ( V_76 == NULL ) {
F_33 ( L_8 ) ;
return 0 ;
}
if ( F_35 ( V_73 , V_81 , & V_79 ) )
return 0 ;
V_80 = V_79 . V_82 ;
V_51 = F_36 ( V_73 , 0 ) ;
F_15 ( L_9 ,
V_76 , V_51 , & V_80 ) ;
if ( V_51 < 0 )
return - V_83 ;
V_84 = V_85 ;
F_37 () ;
if ( F_38 ( V_86 ) )
V_87 -> V_88 |= V_89 | V_90 ;
else
V_87 -> V_88 &= ~ ( V_89 | V_90 ) ;
if ( ! V_71 )
V_71 = (struct V_70 * )
F_39 ( V_91 ) ;
if ( ! V_71 ) {
F_40 ( L_10 ) ;
return - V_92 ;
}
V_6 . V_3 = V_7 ;
V_6 . V_12 = 0 ;
V_6 . V_10 = V_93 ;
V_6 . V_13 = F_17 ( V_71 ) >> V_38 ;
if ( F_3 ( V_94 , & V_6 ) )
F_26 () ;
V_95 = (struct V_70 * ) V_71 ;
V_47 = F_41 ( sizeof( struct V_44 ) ,
sizeof( struct V_44 ) ) ;
if ( V_47 == NULL )
return - V_92 ;
if ( F_42 ( V_80 ) ) {
F_43 ( V_47 ) ;
return - V_92 ;
}
F_44 () ;
if ( ! F_45 () )
F_46 ( NULL ) ;
F_47 () ;
F_48 () ;
F_49 () ;
if ( F_50 ( V_51 , F_29 ,
L_11 , & V_50 ) ) {
F_40 ( L_12 , V_51 ) ;
return - V_37 ;
}
F_13 () ;
F_51 ( & V_96 ) ;
return 0 ;
}
static int T_7 F_52 ( void )
{
if ( ! F_53 () )
return - V_83 ;
V_97 = F_27 ;
V_98 = F_24 ;
return 0 ;
}
void F_54 ( void ) { }
void F_55 ( int V_99 ) { }
void F_56 ( void ) { }
void F_57 ( void ) { }
