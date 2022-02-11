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
static int F_33 ( struct V_37 * V_38 ,
struct V_10 * V_39 ,
const T_3 * V_40 , T_3 V_41 ,
T_5 * V_42 , T_3 * V_43 )
{
struct V_44 * V_45 ;
T_3 line , V_46 , V_47 ;
if ( F_25 ( V_41 < 2 ) )
return - V_23 ;
line = V_40 [ 0 ] ;
if ( V_40 [ 1 ] >= F_34 ( V_44 ) )
return - V_23 ;
V_45 = & V_44 [ V_40 [ 1 ] ] ;
V_46 = ( T_3 ) ( long ) V_38 -> V_48 ;
V_47 = F_35 ( V_46 , line ) ;
if ( F_36 ( V_47 , V_45 -> V_49 , V_45 -> V_50 , F_37 ( 0 ) ) )
return - V_51 ;
* V_42 = line ;
* V_43 = V_45 -> V_43 ;
return 0 ;
}
static void T_1 F_38 ( struct V_10 * V_27 )
{
struct V_28 V_29 ;
int V_20 ;
struct V_52 V_53 = {
. type = V_54 ,
. V_55 = & V_56 ,
. V_18 = V_27 ,
} ;
V_20 = F_24 ( V_27 , 0 , & V_29 ) ;
if ( V_20 ) {
F_39 ( V_57 L_5 ,
V_27 -> V_58 ) ;
return;
}
F_40 ( ++ V_59 , V_29 . V_31 , V_60 , & V_53 ) ;
}
static void T_1 F_41 ( void )
{
struct V_10 * V_27 ;
F_42 (dn, NULL, L_6 )
F_38 ( V_27 ) ;
if ( V_61 ) {
V_62 = 1 ;
return;
}
F_39 ( V_57 L_7 ) ;
}
static void T_1 F_41 ( void ) {}
static void T_1 F_43 ( void )
{
F_26 () ;
F_41 () ;
}
static void T_1 F_44 ( void )
{
T_3 V_3 , V_63 ;
void * V_64 ;
if ( ! V_7 )
return;
V_63 = F_45 ( V_65 - ( V_7 & ~ V_66 ) , ( T_2 ) 128 ) ;
V_67 = V_64 = F_46 ( V_7 , V_63 ) ;
V_3 = F_47 () ;
if ( V_63 < V_3 ) {
F_48 ( V_64 , V_63 ) ;
V_67 = V_64 = F_46 ( V_7 , V_3 ) ;
V_63 = V_3 ;
}
F_49 () ;
F_48 ( V_64 , V_63 ) ;
}
static inline void F_44 ( void ) { }
void T_1 F_50 ( void )
{
F_44 () ;
if ( ! F_10 () )
return;
F_21 () ;
F_43 () ;
}
