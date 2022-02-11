static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( V_1 , & V_6 -> V_8 ) ;
F_3 ( V_3 -> V_9 , L_1 ,
V_10 , __LINE__ , V_1 ) ;
F_4 ( & V_3 -> V_11 , F_5 ( & V_6 -> V_12 ) ) ;
}
static int F_6 ( struct V_13 * V_14 , unsigned long V_15 ,
void * V_16 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( - 1 , & V_6 -> V_17 ) ;
F_2 ( - 1 , & V_6 -> V_18 ) ;
F_1 ( V_19 ) ;
return V_20 ;
}
static T_3 F_7 ( int V_21 , void * V_22 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_8 ( & V_4 -> V_11 ) ;
if ( F_5 ( & V_6 -> V_23 ) )
F_9 ( true ) ;
return V_24 ;
}
static int F_10 ( void )
{
int V_25 = 0 ;
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
int V_26 ;
V_26 = F_11 () ;
V_27 = F_12 ( F_7 , NULL ,
L_2 , V_3 , V_26 ) ;
if ( F_13 ( V_27 ) )
V_25 = F_14 ( V_27 ) ;
else
F_2 ( V_26 , & V_6 -> V_18 ) ;
return V_25 ;
}
static void F_15 ( void )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( - 1 , & V_6 -> V_18 ) ;
F_16 ( V_27 , V_3 ) ;
}
static int T_4 F_17 ( void )
{
struct V_2 * V_3 = V_4 ;
struct V_28 * V_11 = & V_3 -> V_11 ;
struct V_5 T_2 * V_6 ;
T_5 V_29 , V_30 , V_31 ;
T_6 V_32 ;
V_29 = F_18 ( & V_3 -> V_11 , V_33 ) ;
V_30 = F_18 ( & V_3 -> V_11 , V_34 ) ;
V_31 = V_29 | ( V_30 << 32 ) ;
V_3 -> V_7 = F_19 ( V_11 , V_31 , V_35 ) ;
if ( ! V_3 -> V_7 ) {
F_20 ( V_3 -> V_9 , L_3 ) ;
return - V_36 ;
}
V_6 = V_3 -> V_7 ;
V_32 = F_21 ( & V_6 -> V_32 ) ;
if ( V_37 != V_32 ) {
F_20 ( V_3 -> V_9 , L_4 , V_32 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_22 ( void )
{
F_23 ( & V_4 -> V_11 , V_4 -> V_7 ) ;
}
struct V_39 *
F_12 ( T_7 V_40 ,
T_7 V_41 , const char * V_42 ,
void * V_22 , int V_43 )
{
int V_25 = 0 ;
unsigned long V_44 ;
struct V_2 * V_3 = V_4 ;
V_25 = F_24 ( F_25 ( V_3 , V_43 ) , V_40 ,
V_41 , 0 , V_42 , V_22 ) ;
if ( V_25 ) {
F_20 ( V_3 -> V_9 , L_5 , V_25 ) ;
goto V_45;
}
V_3 -> V_46 . V_47 [ V_43 ] ++ ;
V_44 = V_43 ;
return (struct V_39 * ) V_44 ;
V_45:
return F_26 ( V_25 ) ;
}
void F_16 ( struct V_39 * V_44 , void * V_22 )
{
int V_43 ;
struct V_2 * V_3 = V_4 ;
V_43 = ( unsigned long ) V_44 & 0xFFFFU ;
F_27 ( F_25 ( V_3 , V_43 ) , V_22 ) ;
V_3 -> V_46 . V_47 [ V_43 ] -- ;
}
int F_11 ( void )
{
int V_48 ;
int V_43 = 0 ;
struct V_2 * V_3 = V_4 ;
for ( V_48 = 0 ; V_48 < V_3 -> V_49 . V_50 ; V_48 ++ ) {
if ( V_3 -> V_46 . V_47 [ V_48 ] <
V_3 -> V_46 . V_47 [ V_43 ] )
V_43 = V_48 ;
}
return V_43 ;
}
static int F_28 ( void )
{
struct V_2 * V_3 = V_4 ;
V_3 -> V_46 . V_47 = F_29 ( ( sizeof( T_6 ) *
V_3 -> V_49 . V_50 ) ,
V_51 ) ;
if ( ! V_3 -> V_46 . V_47 )
return - V_36 ;
return 0 ;
}
static void F_30 ( void )
{
struct V_2 * V_3 = V_4 ;
F_31 ( V_3 -> V_46 . V_47 ) ;
}
static inline struct V_2 * F_32 ( struct V_52 * V_53 )
{
return F_33 ( V_53 -> V_9 . V_54 ) ;
}
static struct V_39 *
F_34 ( struct V_52 * V_53 ,
T_3 (* F_35)( int V_21 , void * V_22 ) ,
const char * V_42 , void * V_22 ,
int V_55 )
{
return F_12 ( F_35 , NULL , V_42 , V_22 , V_55 ) ;
}
static void
F_36 ( struct V_52 * V_53 ,
struct V_39 * V_44 , void * V_22 )
{
return F_16 ( V_44 , V_22 ) ;
}
static void F_37 ( struct V_52 * V_53 , int V_56 )
{
struct V_2 * V_3 = F_32 ( V_53 ) ;
F_8 ( & V_3 -> V_11 ) ;
}
static int F_38 ( struct V_52 * V_53 )
{
return F_11 () ;
}
static void F_39 ( struct V_52 * V_53 , int V_55 )
{
struct V_2 * V_3 = F_32 ( V_53 ) ;
F_4 ( & V_3 -> V_11 , V_55 ) ;
}
static void F_40 ( struct V_52 * V_53 , int V_55 ,
struct V_57 * V_58 )
{
F_41 ( V_55 , V_58 ) ;
}
static void T_2 *
F_42 ( struct V_52 * V_53 ,
T_8 V_59 , T_9 V_60 )
{
struct V_2 * V_3 = F_32 ( V_53 ) ;
return F_19 ( & V_3 -> V_11 , V_59 , V_60 ) ;
}
static void F_43 ( struct V_52 * V_53 , void T_2 * V_61 )
{
struct V_2 * V_3 = F_32 ( V_53 ) ;
F_23 ( & V_3 -> V_11 , V_61 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
T_10 V_62 ;
struct V_63 * V_64 ;
F_45 ( L_6 ) ;
F_46 ( V_62 ) ;
F_47 ( V_65 , V_62 ) ;
do {
V_64 = F_48 ( V_62 , NULL , NULL ) ;
if ( V_64 ) {
V_3 -> V_66 [ V_3 -> V_67 ++ ] = V_64 ;
if ( V_3 -> V_67 >= V_68 )
break;
}
} while ( V_64 );
F_49 ( V_3 -> V_9 , L_7 , V_3 -> V_67 ) ;
return V_3 -> V_67 ;
}
static void F_50 ( struct V_2 * V_3 )
{
int V_48 = 0 ;
for ( V_48 = 0 ; V_48 < V_3 -> V_67 ; V_48 ++ ) {
F_51 ( V_3 -> V_66 [ V_48 ] ) ;
V_3 -> V_66 [ V_48 ] = NULL ;
}
V_3 -> V_67 = 0 ;
}
int T_4 F_52 ( struct V_2 * V_3 )
{
int V_25 ;
struct V_5 T_2 * V_6 ;
T_1 V_69 ;
V_4 = V_3 ;
if ( ! F_53 ( V_3 -> V_9 -> V_70 -> V_71 ) ) {
V_25 = - V_72 ;
goto V_73;
}
V_25 = F_17 () ;
if ( V_25 )
goto V_74;
V_25 = F_28 () ;
if ( V_25 )
goto V_75;
V_25 = F_10 () ;
if ( V_25 )
goto V_76;
if ( ! F_44 ( V_3 ) ) {
V_25 = - V_72 ;
goto V_77;
}
V_25 = F_54 ( V_3 ) ;
if ( V_25 )
goto V_78;
V_6 = V_3 -> V_7 ;
V_69 = F_5 ( & V_6 -> V_69 ) ;
V_3 -> V_53 = F_55 ( V_3 -> V_9 , V_79 ,
NULL , & V_80 ,
0 , V_69 , & V_3 -> V_11 . V_81 , NULL ,
NULL , V_3 -> V_7 , V_3 -> V_66 ,
V_3 -> V_67 ) ;
if ( F_13 ( V_3 -> V_53 ) ) {
V_25 = F_14 ( V_3 -> V_53 ) ;
goto V_82;
}
F_56 ( V_3 ) ;
F_57 ( & V_83 , & V_84 ) ;
V_73:
return V_25 ;
V_82:
F_58 ( V_3 ) ;
V_78:
F_50 ( V_3 ) ;
V_77:
F_15 () ;
V_76:
F_30 () ;
V_75:
F_22 () ;
V_74:
F_59 ( V_3 -> V_9 -> V_70 -> V_71 ) ;
return V_25 ;
}
void F_60 ( struct V_2 * V_3 )
{
F_61 ( V_3 ) ;
F_62 ( V_3 -> V_53 ) ;
F_58 ( V_3 ) ;
F_50 ( V_3 ) ;
F_1 ( V_85 ) ;
F_15 () ;
F_30 () ;
F_22 () ;
F_59 ( V_3 -> V_9 -> V_70 -> V_71 ) ;
}
