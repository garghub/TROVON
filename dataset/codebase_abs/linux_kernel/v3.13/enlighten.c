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
static void T_6 F_13 ( void * V_43 )
{
struct V_44 V_24 ;
struct V_45 * V_46 ;
int V_14 ;
int V_47 = F_14 () ;
F_15 ( L_3 , V_47 ) ;
V_46 = F_16 ( V_48 , V_47 ) ;
V_24 . V_35 = F_17 ( V_46 ) >> V_38 ;
V_24 . V_49 = F_18 ( V_46 ) ;
V_14 = F_19 ( V_50 , V_47 , & V_24 ) ;
F_20 ( V_14 ) ;
F_21 ( V_51 , V_47 ) = V_46 ;
F_22 ( V_52 , 0 ) ;
F_23 () ;
}
static void F_24 ( enum V_53 V_53 , const char * V_54 )
{
struct V_55 V_56 = { . V_57 = V_58 } ;
int V_4 ;
V_4 = F_25 ( V_59 , & V_56 ) ;
if ( V_4 )
F_26 () ;
}
static void F_27 ( void )
{
struct V_55 V_56 = { . V_57 = V_60 } ;
int V_4 ;
V_4 = F_25 ( V_59 , & V_56 ) ;
if ( V_4 )
F_26 () ;
}
static int T_6 F_28 ( void )
{
struct V_61 V_6 ;
static struct V_62 * V_63 = 0 ;
struct V_64 * V_65 ;
int V_66 ;
const char * V_67 = NULL ;
const char * V_68 = NULL ;
const char * V_69 = L_4 ;
struct V_70 V_71 ;
V_65 = F_29 ( NULL , NULL , L_5 ) ;
if ( ! V_65 ) {
F_30 ( L_6 ) ;
return 0 ;
}
V_67 = F_31 ( V_65 , L_7 , & V_66 ) ;
if ( strlen ( V_69 ) + 3 < V_66 &&
! strncmp ( V_69 , V_67 , strlen ( V_69 ) ) )
V_68 = V_67 + strlen ( V_69 ) ;
if ( V_68 == NULL ) {
F_30 ( L_8 ) ;
return 0 ;
}
if ( F_32 ( V_65 , V_72 , & V_71 ) )
return 0 ;
V_73 = V_71 . V_74 ;
V_52 = F_33 ( V_65 , 0 ) ;
F_15 ( L_9 ,
V_68 , V_52 , ( V_73 >> V_38 ) ) ;
V_75 = V_76 ;
F_34 () ;
if ( F_35 ( V_77 ) )
V_78 -> V_79 |= V_80 | V_81 ;
else
V_78 -> V_79 &= ~ ( V_80 | V_81 ) ;
if ( ! V_63 )
V_63 = (struct V_62 * )
F_36 ( V_82 ) ;
if ( ! V_63 ) {
F_37 ( L_10 ) ;
return - V_83 ;
}
V_6 . V_3 = V_7 ;
V_6 . V_12 = 0 ;
V_6 . V_10 = V_84 ;
V_6 . V_13 = F_17 ( V_63 ) >> V_38 ;
if ( F_3 ( V_85 , & V_6 ) )
F_26 () ;
V_86 = (struct V_62 * ) V_63 ;
V_48 = F_38 ( sizeof( struct V_45 ) ,
sizeof( struct V_45 ) ) ;
if ( V_48 == NULL )
return - V_83 ;
F_39 () ;
if ( ! F_40 () )
F_41 ( NULL ) ;
F_42 () ;
F_43 () ;
return 0 ;
}
static int T_6 F_44 ( void )
{
if ( ! F_45 () )
return - V_87 ;
V_88 = F_27 ;
V_89 = F_24 ;
return 0 ;
}
static T_7 F_46 ( int V_90 , void * V_91 )
{
F_47 () ;
return V_92 ;
}
static int T_6 F_48 ( void )
{
if ( ! F_45 () || V_52 < 0 )
return - V_87 ;
F_49 () ;
if ( F_50 ( V_52 , F_46 ,
L_11 , & V_51 ) ) {
F_37 ( L_12 , V_52 ) ;
return - V_37 ;
}
F_51 ( F_13 , NULL , 0 ) ;
return 0 ;
}
