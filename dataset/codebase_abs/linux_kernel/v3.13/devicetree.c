void T_1 F_1 ( unsigned long V_1 )
{
F_2 () ;
}
void T_1 F_3 ( T_2 V_2 , T_2 V_3 )
{
F_2 () ;
}
void * T_1 F_4 ( T_2 V_3 , T_2 V_4 )
{
return F_5 ( V_3 , V_4 , F_6 ( V_5 ) ) ;
}
void T_1 F_7 ( T_2 V_6 )
{
V_7 = V_6 + F_8 ( struct V_8 , V_6 ) ;
}
static int T_1 F_9 ( void )
{
if ( ! F_10 () )
return 0 ;
return F_11 ( NULL , V_9 , NULL ) ;
}
struct V_10 * F_12 ( struct V_11 * V_12 )
{
struct V_10 * V_13 ;
F_13 (np, L_1 ) {
const void * V_14 ;
unsigned int V_15 ;
V_14 = F_14 ( V_13 , L_2 , NULL ) ;
if ( ! V_14 )
continue;
V_15 = F_15 ( V_14 ) ;
if ( V_12 -> V_16 == V_15 )
return V_13 ;
}
return NULL ;
}
static int F_16 ( struct V_17 * V_18 )
{
T_3 V_19 ;
int V_20 ;
T_4 V_21 ;
V_20 = F_17 ( V_18 , V_22 , & V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_21 )
return 0 ;
V_19 = F_18 ( V_18 , 0 , 0 ) ;
if ( V_19 == 0 )
return - V_23 ;
V_18 -> V_24 = V_19 ;
return 0 ;
}
static void F_19 ( struct V_17 * V_18 )
{
}
void F_20 ( void )
{
V_25 = F_16 ;
V_26 = F_19 ;
}
static void T_1 F_21 ( void )
{
#ifdef F_22
struct V_10 * V_27 ;
struct V_28 V_29 ;
int V_20 ;
V_27 = F_23 ( NULL , NULL , L_3 ) ;
if ( ! V_27 )
return;
V_20 = F_24 ( V_27 , 0 , & V_29 ) ;
if ( V_20 ) {
F_25 ( 1 ) ;
return;
}
V_30 = V_29 . V_31 ;
#endif
}
static void T_1 F_26 ( void )
{
#ifdef F_27
struct V_10 * V_27 ;
struct V_28 V_29 ;
int V_20 ;
V_27 = F_23 ( NULL , NULL , L_4 ) ;
if ( ! V_27 )
return;
V_20 = F_24 ( V_27 , 0 , & V_29 ) ;
if ( F_25 ( V_20 ) )
return;
if ( ! V_32 ) {
if ( F_28 ( V_29 . V_31 ) )
return;
}
V_33 = 1 ;
V_34 = 1 ;
F_29 ( V_29 . V_31 ) ;
F_30 ( V_35 ,
F_31 ( F_32 ( V_36 ) ) ) ;
#endif
}
static void T_1 F_33 ( struct V_10 * V_27 )
{
struct V_28 V_29 ;
int V_20 ;
V_20 = F_24 ( V_27 , 0 , & V_29 ) ;
if ( V_20 ) {
F_34 ( V_37 L_5 ,
V_27 -> V_38 ) ;
return;
}
F_35 ( ++ V_39 , V_29 . V_31 , V_40 ) ;
}
static void T_1 F_36 ( void )
{
struct V_10 * V_27 ;
F_37 (dn, NULL, L_6 )
F_33 ( V_27 ) ;
if ( V_41 ) {
V_42 = 1 ;
return;
}
F_34 ( V_37 L_7 ) ;
}
static void T_1 F_36 ( void ) {}
static void T_1 F_38 ( void )
{
F_26 () ;
F_36 () ;
}
static void T_1 F_39 ( void )
{
T_3 V_3 , V_43 ;
struct V_44 * V_45 ;
if ( ! V_7 )
return;
V_43 = F_40 ( V_46 - ( V_7 & ~ V_47 ) ,
( T_2 ) sizeof( struct V_44 ) ) ;
V_45 = F_41 ( V_7 , V_43 ) ;
V_3 = F_42 ( V_45 -> V_48 ) ;
if ( V_43 < V_3 ) {
F_43 ( V_45 , V_43 ) ;
V_45 = F_41 ( V_7 , V_3 ) ;
V_43 = V_3 ;
}
V_49 = V_45 ;
F_44 () ;
F_43 ( V_45 , V_43 ) ;
}
static inline void F_39 ( void ) { }
void T_1 F_45 ( void )
{
F_39 () ;
if ( ! F_10 () )
return;
F_21 () ;
F_38 () ;
}
static int F_46 ( struct V_50 * V_51 ,
struct V_10 * V_52 ,
const T_3 * V_53 , T_3 V_54 ,
T_5 * V_55 , T_3 * V_56 )
{
struct V_57 V_58 ;
struct V_59 * V_60 ;
T_3 line , V_61 ;
int V_62 ;
if ( F_25 ( V_54 < 2 ) )
return - V_23 ;
line = V_53 [ 0 ] ;
if ( V_53 [ 1 ] >= F_47 ( V_59 ) )
return - V_23 ;
V_60 = & V_59 [ V_53 [ 1 ] ] ;
V_61 = ( T_3 ) V_51 -> V_63 ;
F_48 ( & V_58 , V_61 , line , V_60 -> V_64 , V_60 -> V_65 ) ;
V_62 = F_49 ( F_50 ( V_51 , line ) ,
F_51 ( 0 ) , & V_58 ) ;
if ( V_62 )
return V_62 ;
* V_55 = line ;
* V_56 = V_60 -> V_56 ;
return 0 ;
}
static void F_52 ( unsigned int V_66 ,
struct V_10 * V_13 )
{
struct V_50 * V_67 ;
struct V_68 * V_69 ;
int V_20 ;
int V_70 ;
V_69 = F_53 ( V_66 ) ;
V_70 = V_69 -> V_71 - V_69 -> V_72 + 1 ;
V_67 = F_54 ( V_13 , V_70 , & V_73 ,
( void * ) V_66 ) ;
F_55 ( ! V_67 ) ;
if ( V_69 -> V_72 == 0 ) {
F_56 ( V_67 , 0 , 0 , V_74 ) ;
if ( V_70 > V_74 ) {
V_20 = F_57 ( V_67 , V_74 ,
V_74 , V_70 - V_74 ) ;
if ( V_20 )
F_58 ( L_8
L_9 , V_20 ) ;
}
F_59 ( V_67 ) ;
} else {
V_20 = F_57 ( V_67 , V_69 -> V_72 , 0 , V_70 ) ;
if ( V_20 )
F_58 ( L_10 , V_20 ) ;
}
}
static void T_1 F_60 ( struct V_10 * V_13 )
{
struct V_28 V_29 ;
int V_75 , V_20 ;
V_20 = F_24 ( V_13 , 0 , & V_29 ) ;
if ( V_20 ) {
F_34 ( V_37 L_11 ,
V_13 -> V_38 ) ;
return;
}
for ( V_75 = 0 ; V_75 < V_41 ; V_75 ++ ) {
if ( V_29 . V_31 == F_61 ( V_75 ) ) {
F_52 ( V_75 , V_13 ) ;
return;
}
}
F_34 ( V_37 L_12 , V_13 -> V_38 ) ;
}
void T_1 F_62 ( void )
{
struct V_10 * V_76 ;
if ( ! F_10 () )
return;
F_63 (dp, L_13 ) {
if ( F_64 ( V_76 , L_6 ) )
F_60 ( V_76 ) ;
}
}
void T_1 F_62 ( void ) { }
