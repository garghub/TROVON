static void F_1 ( void )
{
int V_1 ;
F_2 () ;
F_3 () ;
F_4 () ;
if ( ! F_5 ( V_2 ) ) {
F_6 () ;
F_7 () ;
}
V_1 = F_8 () ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) . V_3 = 1 ;
F_11 ( V_1 ) ;
F_12 () ;
F_13 ( V_1 ) ;
F_14 ( V_1 , true ) ;
F_15 ( V_1 ) ;
F_16 () ;
}
T_1 T_2 void F_17 ( void )
{
F_1 () ;
F_18 ( V_4 ) ;
}
void F_19 ( unsigned int V_1 )
{
if ( F_20 ( V_5 , V_1 ) . V_6 >= 0 ) {
F_21 ( F_20 ( V_5 , V_1 ) . V_6 , NULL ) ;
F_20 ( V_5 , V_1 ) . V_6 = - 1 ;
F_22 ( F_20 ( V_5 , V_1 ) . V_7 ) ;
F_20 ( V_5 , V_1 ) . V_7 = NULL ;
}
if ( F_20 ( V_8 , V_1 ) . V_6 >= 0 ) {
F_21 ( F_20 ( V_8 , V_1 ) . V_6 , NULL ) ;
F_20 ( V_8 , V_1 ) . V_6 = - 1 ;
F_22 ( F_20 ( V_8 , V_1 ) . V_7 ) ;
F_20 ( V_8 , V_1 ) . V_7 = NULL ;
}
}
int F_23 ( unsigned int V_1 )
{
int V_9 ;
char * V_10 , * V_11 ;
V_10 = F_24 ( V_12 , L_1 , V_1 ) ;
V_9 = F_25 ( V_13 ,
V_1 ,
V_14 ,
V_15 | V_16 ,
V_10 ,
NULL ) ;
if ( V_9 < 0 )
goto V_17;
F_20 ( V_5 , V_1 ) . V_6 = V_9 ;
F_20 ( V_5 , V_1 ) . V_7 = V_10 ;
if ( F_26 ( V_1 ) ) {
V_11 = F_24 ( V_12 , L_2 , V_1 ) ;
V_9 = F_27 ( V_18 , V_1 ,
V_19 ,
V_15 | V_16 ,
V_11 , NULL ) ;
if ( V_9 < 0 )
goto V_17;
F_20 ( V_8 , V_1 ) . V_6 = V_9 ;
F_20 ( V_8 , V_1 ) . V_7 = V_11 ;
}
return 0 ;
V_17:
F_19 ( V_1 ) ;
return V_9 ;
}
static void T_3 F_28 ( void )
{
int V_20 , V_9 ;
if ( F_29 () )
return;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_9 = F_30 ( V_22 , V_20 , NULL ) ;
if ( V_9 >= 0 ) {
V_23 ++ ;
F_31 ( V_20 , true ) ;
}
}
}
static void T_3 F_32 ( void )
{
int V_20 , V_9 ;
unsigned int V_24 = 0 ;
if ( ! F_29 () )
return;
V_23 = 0 ;
V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_9 = F_30 ( V_22 , V_20 , NULL ) ;
if ( V_9 >= 0 ) {
V_23 ++ ;
F_31 ( V_20 , true ) ;
} else {
F_31 ( V_20 , false ) ;
F_33 ( V_20 , false ) ;
V_24 ++ ;
}
}
#ifdef F_34
if ( V_24 )
V_21 = V_21 - V_24 ;
#endif
}
static void T_3 F_35 ( void )
{
F_36 ( F_8 () != 0 ) ;
F_37 () ;
if ( ! F_5 ( V_26 ) )
F_38 ( V_27 ) ;
#ifdef F_39
F_40 ( V_28 , V_29 ) ;
F_40 ( V_30 , V_29 ) ;
#endif
F_32 () ;
F_41 () ;
F_42 () ;
}
static void T_3 F_43 ( unsigned int V_31 )
{
unsigned V_1 ;
unsigned int V_20 ;
if ( V_32 ) {
char * V_33 = ( V_31 == 0 ) ?
L_3 \
L_4 :
L_5 ;
F_44 ( V_33 ) ;
F_45 ( V_33 ) ;
}
F_46 ( 0 ) ;
F_47 () ;
F_10 ( 0 ) . V_3 = 1 ;
F_48 (i) {
F_49 ( & F_20 ( V_34 , V_20 ) , V_12 ) ;
F_49 ( & F_20 ( V_35 , V_20 ) , V_12 ) ;
F_49 ( & F_20 ( V_36 , V_20 ) , V_12 ) ;
}
F_11 ( 0 ) ;
F_50 ( 0 ) ;
if ( F_51 ( 0 ) || F_23 ( 0 ) )
F_52 () ;
if ( ! F_53 ( & V_37 , V_12 ) )
F_45 ( L_6 ) ;
F_54 ( V_37 , F_55 ( 0 ) ) ;
while ( ( F_56 () > 1 ) && ( F_56 () > V_31 ) ) {
for ( V_1 = V_21 - 1 ; ! F_57 ( V_1 ) ; V_1 -- )
continue;
F_31 ( V_1 , false ) ;
}
F_48 (cpu)
F_33 ( V_1 , true ) ;
}
static int
F_58 ( unsigned int V_1 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
F_59 ( V_1 , V_45 ) ;
if ( F_60 ( V_1 , V_37 ) )
return 0 ;
V_41 = F_61 ( sizeof( * V_41 ) , V_12 ) ;
if ( V_41 == NULL )
return - V_46 ;
V_43 = F_62 ( V_1 ) ;
#ifdef F_39
V_41 -> V_47 . V_48 = V_49 ;
V_41 -> V_47 . V_50 = V_51 ;
#endif
memset ( & V_41 -> V_52 , 0 , sizeof( V_41 -> V_52 ) ) ;
V_41 -> V_47 . V_53 = ( unsigned long ) F_17 ;
V_41 -> V_54 = V_55 ;
V_41 -> V_47 . V_56 = 0x1000 ;
V_41 -> V_47 . V_28 = V_29 ;
V_41 -> V_47 . V_30 = V_29 ;
V_41 -> V_47 . V_57 = V_58 ;
F_63 ( V_41 -> V_59 ) ;
V_41 -> V_60 = 0 ;
F_36 ( ( unsigned long ) V_43 & ~ V_61 ) ;
V_44 = F_64 ( V_43 ) ;
F_65 ( V_43 ) ;
F_65 ( F_66 ( V_44 ) ) ;
V_41 -> V_62 [ 0 ] = V_44 ;
V_41 -> V_63 = V_64 ;
V_41 -> V_65 = V_58 ;
V_41 -> V_66 = V_39 -> V_67 . V_68 ;
#ifdef F_39
V_41 -> V_69 = V_70 ;
V_41 -> V_71 = V_70 ;
#else
V_41 -> V_72 = F_67 ( V_1 ) ;
#endif
V_41 -> V_73 =
( unsigned long ) V_74 ;
V_41 -> V_75 =
( unsigned long ) V_76 ;
V_41 -> V_47 . V_77 = V_70 ;
F_20 ( V_78 , V_1 ) = F_68 ( V_79 ) ;
V_41 -> V_47 . V_80 = V_39 -> V_67 . V_68 - sizeof( struct V_81 ) ;
V_41 -> V_82 [ 3 ] = F_69 ( F_70 ( V_79 ) ) ;
if ( F_30 ( V_83 , F_71 ( V_1 ) , V_41 ) )
F_52 () ;
F_22 ( V_41 ) ;
return 0 ;
}
static int F_72 ( unsigned int V_1 , struct V_38 * V_39 )
{
int V_9 ;
F_73 ( V_1 , V_39 ) ;
F_74 ( V_1 ) ;
V_9 = F_75 ( V_1 ) ;
if ( V_9 )
return V_9 ;
F_20 ( V_84 , V_1 ) -> V_85 = 1 ;
V_9 = F_58 ( V_1 , V_39 ) ;
if ( V_9 )
return V_9 ;
F_50 ( V_1 ) ;
V_9 = F_30 ( V_86 , F_71 ( V_1 ) , NULL ) ;
F_36 ( V_9 ) ;
while ( F_76 ( V_1 ) != V_87 )
F_77 ( V_88 , NULL ) ;
return 0 ;
}
static int F_78 ( void )
{
unsigned int V_1 = F_8 () ;
if ( V_1 == 0 )
return - V_89 ;
F_79 () ;
F_80 ( V_79 ) ;
return 0 ;
}
static void F_81 ( unsigned int V_1 )
{
while ( F_30 ( V_22 ,
F_71 ( V_1 ) , NULL ) ) {
F_82 ( V_90 ) ;
F_83 ( V_91 / 10 ) ;
}
if ( F_84 ( V_1 ) == 0 ) {
F_85 ( V_1 ) ;
F_86 ( V_1 ) ;
F_87 ( V_1 ) ;
F_88 ( V_1 ) ;
}
}
static void F_89 ( void )
{
F_90 () ;
F_30 ( V_92 , F_71 ( F_8 () ) , NULL ) ;
F_1 () ;
F_91 () ;
F_92 ( V_4 ) ;
}
static int F_78 ( void )
{
return - V_93 ;
}
static void F_81 ( unsigned int V_1 )
{
F_52 () ;
}
static void F_89 ( void )
{
F_52 () ;
}
static void F_93 ( void * V_94 )
{
int V_1 = F_8 () ;
F_80 ( V_79 ) ;
F_14 ( V_1 , false ) ;
F_30 ( V_92 , F_71 ( V_1 ) , NULL ) ;
F_52 () ;
}
static void F_94 ( int V_95 )
{
F_95 ( F_93 , NULL , V_95 ) ;
}
static T_4 V_14 ( int V_6 , void * V_96 )
{
F_96 () ;
F_97 () ;
F_98 ( V_97 ) ;
F_99 () ;
return V_98 ;
}
void T_3 F_100 ( void )
{
V_99 = V_100 ;
F_28 () ;
}
