unsigned long F_1 ( T_1 V_1 )
{
F_2 ( V_1 >= ( 1 << 16 ) ) ;
return ( unsigned long ) V_1 ;
}
void T_2 F_3 ( unsigned long V_2 )
{
F_4 () ;
}
void T_2 F_5 ( T_3 V_3 , T_3 V_4 )
{
F_4 () ;
}
void * T_2 F_6 ( T_3 V_4 , T_3 V_5 )
{
return F_7 ( V_4 , V_5 , F_8 ( V_6 ) ) ;
}
void T_2 F_9 ( T_3 V_7 , T_3 V_8 )
{
V_9 = ( unsigned long ) F_10 ( V_7 ) ;
V_10 = ( unsigned long ) F_10 ( V_8 ) ;
V_11 = 1 ;
}
void T_2 F_11 ( T_3 V_12 )
{
V_13 = V_12 + F_12 ( struct V_14 , V_12 ) ;
}
static int T_2 F_13 ( void )
{
if ( ! F_14 () )
return 0 ;
return F_15 ( NULL , V_15 , NULL ) ;
}
struct V_16 * F_16 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
F_17 (np, L_1 ) {
const void * V_20 ;
unsigned int V_21 ;
V_20 = F_18 ( V_19 , L_2 , NULL ) ;
if ( ! V_20 )
continue;
V_21 = F_19 ( V_20 ) ;
if ( V_18 -> V_22 == V_21 )
return V_19 ;
}
return NULL ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_25 V_26 ;
T_4 V_27 ;
int V_28 ;
T_5 V_29 ;
V_28 = F_21 ( V_24 , V_30 , & V_29 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_29 )
return 0 ;
V_28 = F_22 ( V_24 , & V_26 ) ;
if ( V_28 )
return V_28 ;
V_27 = F_23 ( V_26 . V_31 , V_26 . V_32 ,
V_26 . V_4 ) ;
if ( V_27 == 0 )
return - V_33 ;
V_24 -> V_34 = V_27 ;
return 0 ;
}
static void F_24 ( struct V_23 * V_24 )
{
}
void F_25 ( void )
{
V_35 = F_20 ;
V_36 = F_24 ;
}
static void T_2 F_26 ( void )
{
#ifdef F_27
struct V_16 * V_37 ;
struct V_38 V_39 ;
int V_28 ;
V_37 = F_28 ( NULL , NULL , L_3 ) ;
if ( ! V_37 )
return;
V_28 = F_29 ( V_37 , 0 , & V_39 ) ;
if ( V_28 ) {
F_30 ( 1 ) ;
return;
}
V_40 = V_39 . V_7 ;
#endif
}
static void T_2 F_31 ( void )
{
#ifdef F_32
struct V_16 * V_37 ;
struct V_38 V_39 ;
int V_28 ;
V_37 = F_28 ( NULL , NULL , L_4 ) ;
if ( ! V_37 )
return;
V_28 = F_29 ( V_37 , 0 , & V_39 ) ;
if ( F_30 ( V_28 ) )
return;
if ( ! V_41 ) {
if ( F_33 ( V_39 . V_7 ) )
return;
}
V_42 = 1 ;
V_43 = 1 ;
F_34 ( V_39 . V_7 ) ;
F_35 ( V_44 ,
F_36 ( F_37 ( V_45 ) ) ) ;
#endif
}
static void T_2 F_38 ( struct V_16 * V_37 )
{
struct V_38 V_39 ;
int V_28 ;
V_28 = F_29 ( V_37 , 0 , & V_39 ) ;
if ( V_28 ) {
F_39 ( V_46 L_5 ,
V_37 -> V_47 ) ;
return;
}
F_40 ( ++ V_48 , V_39 . V_7 , V_49 ) ;
}
static void T_2 F_41 ( void )
{
struct V_16 * V_37 ;
F_42 (dn, NULL, L_6 )
F_38 ( V_37 ) ;
if ( V_50 ) {
V_51 = 1 ;
return;
}
F_39 ( V_46 L_7 ) ;
}
static void T_2 F_41 ( void ) {}
static void T_2 F_43 ( void )
{
F_31 () ;
F_41 () ;
}
static void T_2 F_44 ( void )
{
T_4 V_4 , V_52 ;
void * V_53 ;
if ( ! V_13 )
return;
V_52 = F_45 ( V_54 - ( V_13 & ~ V_55 ) ,
( T_3 ) sizeof( struct V_56 ) ) ;
V_57 = F_46 ( V_13 , V_52 ) ;
V_4 = F_47 ( V_57 -> V_58 ) ;
if ( V_52 < V_4 ) {
F_48 ( V_57 , V_52 ) ;
V_57 = F_46 ( V_13 , V_4 ) ;
V_52 = V_4 ;
}
V_53 = F_49 ( V_4 ) ;
memcpy ( V_53 , V_57 , V_4 ) ;
F_48 ( V_57 , V_52 ) ;
V_57 = V_53 ;
F_50 ( V_59 , NULL ) ;
F_51 () ;
}
static inline void F_44 ( void ) { }
void T_2 F_52 ( void )
{
F_44 () ;
if ( ! F_14 () )
return;
F_26 () ;
F_43 () ;
}
static int F_53 ( struct V_60 * V_61 ,
struct V_16 * V_31 ,
const T_4 * V_62 , T_4 V_63 ,
T_6 * V_64 , T_4 * V_65 )
{
struct V_66 V_67 ;
struct V_68 * V_69 ;
T_4 line , V_70 ;
int V_71 ;
if ( F_30 ( V_63 < 2 ) )
return - V_33 ;
line = V_62 [ 0 ] ;
if ( V_62 [ 1 ] >= F_54 ( V_68 ) )
return - V_33 ;
V_69 = & V_68 [ V_62 [ 1 ] ] ;
V_70 = ( T_4 ) V_61 -> V_72 ;
F_55 ( & V_67 , V_70 , line , V_69 -> V_73 , V_69 -> V_74 ) ;
V_71 = F_56 ( F_57 ( V_61 , line ) ,
F_58 ( 0 ) , & V_67 ) ;
if ( V_71 )
return V_71 ;
* V_64 = line ;
* V_65 = V_69 -> V_65 ;
return 0 ;
}
static void F_59 ( unsigned int V_75 ,
struct V_16 * V_19 )
{
struct V_60 * V_76 ;
struct V_77 * V_78 ;
int V_28 ;
int V_79 ;
V_78 = F_60 ( V_75 ) ;
V_79 = V_78 -> V_80 - V_78 -> V_81 + 1 ;
V_76 = F_61 ( V_19 , V_79 , & V_82 ,
( void * ) V_75 ) ;
F_2 ( ! V_76 ) ;
if ( V_78 -> V_81 == 0 ) {
F_62 ( V_76 , 0 , 0 , V_83 ) ;
if ( V_79 > V_83 ) {
V_28 = F_63 ( V_76 , V_83 ,
V_83 , V_79 - V_83 ) ;
if ( V_28 )
F_64 ( L_8
L_9 , V_28 ) ;
}
F_65 ( V_76 ) ;
} else {
V_28 = F_63 ( V_76 , V_78 -> V_81 , 0 , V_79 ) ;
if ( V_28 )
F_64 ( L_10 , V_28 ) ;
}
}
static void T_2 F_66 ( struct V_16 * V_19 )
{
struct V_38 V_39 ;
int V_84 , V_28 ;
V_28 = F_29 ( V_19 , 0 , & V_39 ) ;
if ( V_28 ) {
F_39 ( V_46 L_11 ,
V_19 -> V_47 ) ;
return;
}
for ( V_84 = 0 ; V_84 < V_50 ; V_84 ++ ) {
if ( V_39 . V_7 == F_67 ( V_84 ) ) {
F_59 ( V_84 , V_19 ) ;
return;
}
}
F_39 ( V_46 L_12 , V_19 -> V_47 ) ;
}
void T_2 F_68 ( void )
{
struct V_16 * V_85 ;
if ( ! F_14 () )
return;
F_69 (dp, L_13 ) {
if ( F_70 ( V_85 , L_6 ) )
F_66 ( V_85 ) ;
}
}
void T_2 F_68 ( void ) { }
