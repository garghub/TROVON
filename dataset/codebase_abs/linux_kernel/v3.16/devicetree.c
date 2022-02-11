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
void * V_44 ;
if ( ! V_7 )
return;
V_43 = F_40 ( V_45 - ( V_7 & ~ V_46 ) , ( T_2 ) 128 ) ;
V_47 = V_44 = F_41 ( V_7 , V_43 ) ;
V_3 = F_42 () ;
if ( V_43 < V_3 ) {
F_43 ( V_44 , V_43 ) ;
V_47 = V_44 = F_41 ( V_7 , V_3 ) ;
V_43 = V_3 ;
}
F_44 () ;
F_43 ( V_44 , V_43 ) ;
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
static int F_46 ( struct V_48 * V_49 ,
struct V_10 * V_50 ,
const T_3 * V_51 , T_3 V_52 ,
T_5 * V_53 , T_3 * V_54 )
{
struct V_55 V_56 ;
struct V_57 * V_58 ;
T_3 line , V_59 ;
int V_60 ;
if ( F_25 ( V_52 < 2 ) )
return - V_23 ;
line = V_51 [ 0 ] ;
if ( V_51 [ 1 ] >= F_47 ( V_57 ) )
return - V_23 ;
V_58 = & V_57 [ V_51 [ 1 ] ] ;
V_59 = ( T_3 ) V_49 -> V_61 ;
F_48 ( & V_56 , V_59 , line , V_58 -> V_62 , V_58 -> V_63 ) ;
V_60 = F_49 ( F_50 ( V_49 , line ) ,
F_51 ( 0 ) , & V_56 ) ;
if ( V_60 )
return V_60 ;
* V_53 = line ;
* V_54 = V_58 -> V_54 ;
return 0 ;
}
static void F_52 ( unsigned int V_64 ,
struct V_10 * V_13 )
{
struct V_48 * V_65 ;
struct V_66 * V_67 ;
int V_20 ;
int V_68 ;
V_67 = F_53 ( V_64 ) ;
V_68 = V_67 -> V_69 - V_67 -> V_70 + 1 ;
V_65 = F_54 ( V_13 , V_68 , & V_71 ,
( void * ) V_64 ) ;
F_55 ( ! V_65 ) ;
if ( V_67 -> V_70 == 0 ) {
F_56 ( V_65 , 0 , 0 , V_72 ) ;
if ( V_68 > V_72 ) {
V_20 = F_57 ( V_65 , V_72 ,
V_72 , V_68 - V_72 ) ;
if ( V_20 )
F_58 ( L_8
L_9 , V_20 ) ;
}
F_59 ( V_65 ) ;
} else {
V_20 = F_57 ( V_65 , V_67 -> V_70 , 0 , V_68 ) ;
if ( V_20 )
F_58 ( L_10 , V_20 ) ;
}
}
static void T_1 F_60 ( struct V_10 * V_13 )
{
struct V_28 V_29 ;
int V_73 , V_20 ;
V_20 = F_24 ( V_13 , 0 , & V_29 ) ;
if ( V_20 ) {
F_34 ( V_37 L_11 ,
V_13 -> V_38 ) ;
return;
}
for ( V_73 = 0 ; V_73 < V_41 ; V_73 ++ ) {
if ( V_29 . V_31 == F_61 ( V_73 ) ) {
F_52 ( V_73 , V_13 ) ;
return;
}
}
F_34 ( V_37 L_12 , V_13 -> V_38 ) ;
}
void T_1 F_62 ( void )
{
struct V_10 * V_74 ;
if ( ! F_10 () )
return;
F_63 (dp, L_13 ) {
if ( F_64 ( V_74 , L_6 ) )
F_60 ( V_74 ) ;
}
}
void T_1 F_62 ( void ) { }
