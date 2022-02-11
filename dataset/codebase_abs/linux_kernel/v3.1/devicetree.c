static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( & V_2 -> V_5 , & V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static struct V_1 * F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_9 = NULL ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_6 (ih, &irq_domains, l) {
if ( V_2 -> V_8 == V_8 ) {
V_9 = V_2 ;
break;
}
}
F_4 ( & V_4 , V_3 ) ;
return V_9 ;
}
unsigned int F_7 ( struct V_7 * V_8 ,
const T_1 * V_10 , unsigned int V_11 )
{
struct V_1 * V_2 ;
T_1 V_12 , type ;
int V_13 ;
V_2 = F_5 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
V_13 = V_2 -> V_14 ( V_2 , V_10 , V_11 , & V_12 , & type ) ;
if ( V_13 )
return 0 ;
if ( type == V_15 )
return V_12 ;
F_8 ( V_12 , type ) ;
return V_12 ;
}
unsigned long F_9 ( T_2 V_16 )
{
F_10 ( V_16 >= ( 1 << 16 ) ) ;
return ( unsigned long ) V_16 ;
}
void T_3 F_11 ( unsigned long V_17 )
{
F_12 () ;
}
void T_3 F_13 ( T_4 V_18 , T_4 V_19 )
{
F_12 () ;
}
void * T_3 F_14 ( T_4 V_19 , T_4 V_20 )
{
return F_15 ( V_19 , V_20 , F_16 ( V_21 ) ) ;
}
void T_3 F_17 ( unsigned long V_22 ,
unsigned long V_23 )
{
V_24 = ( unsigned long ) F_18 ( V_22 ) ;
V_25 = ( unsigned long ) F_18 ( V_23 ) ;
V_26 = 1 ;
}
void T_3 F_19 ( T_4 V_27 )
{
V_28 = V_27 + F_20 ( struct V_29 , V_27 ) ;
}
static int T_3 F_21 ( void )
{
if ( ! F_22 () )
return 0 ;
return F_23 ( NULL , V_30 , NULL ) ;
}
struct V_7 * F_24 ( struct V_31 * V_32 )
{
struct V_7 * V_33 ;
F_25 (np, L_1 ) {
const void * V_34 ;
unsigned int V_35 ;
V_34 = F_26 ( V_33 , L_2 , NULL ) ;
if ( ! V_34 )
continue;
V_35 = F_27 ( V_34 ) ;
if ( V_32 -> V_36 == V_35 )
return V_33 ;
}
return NULL ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_39 V_40 ;
T_1 V_12 ;
int V_13 ;
T_5 V_41 ;
V_13 = F_29 ( V_38 , V_42 , & V_41 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_41 )
return 0 ;
V_13 = F_30 ( V_38 , & V_40 ) ;
if ( V_13 )
return V_13 ;
V_12 = F_7 ( V_40 . V_8 , V_40 . V_43 ,
V_40 . V_19 ) ;
if ( V_12 == 0 )
return - V_44 ;
V_38 -> V_45 = V_12 ;
return 0 ;
}
static void F_31 ( struct V_37 * V_38 )
{
}
void T_6 F_32 ( void )
{
V_46 = F_28 ;
V_47 = F_31 ;
}
static void T_3 F_33 ( void )
{
#ifdef F_34
struct V_7 * V_48 ;
struct V_49 V_50 ;
int V_13 ;
V_48 = F_35 ( NULL , NULL , L_3 ) ;
if ( ! V_48 )
return;
V_13 = F_36 ( V_48 , 0 , & V_50 ) ;
if ( V_13 ) {
F_37 ( 1 ) ;
return;
}
V_51 = V_50 . V_22 ;
#endif
}
static void T_3 F_38 ( void )
{
#ifdef F_39
struct V_7 * V_48 ;
struct V_49 V_50 ;
int V_13 ;
V_48 = F_35 ( NULL , NULL , L_4 ) ;
if ( ! V_48 )
return;
V_13 = F_36 ( V_48 , 0 , & V_50 ) ;
if ( F_37 ( V_13 ) )
return;
if ( ! V_52 ) {
if ( F_40 ( V_50 . V_22 ) )
return;
}
V_53 = 1 ;
V_54 = 1 ;
F_41 ( V_50 . V_22 ) ;
F_42 ( V_55 ,
F_43 ( F_44 ( V_56 ) ) ) ;
#endif
}
static void T_3 F_45 ( struct V_7 * V_48 )
{
struct V_49 V_50 ;
int V_13 ;
V_13 = F_36 ( V_48 , 0 , & V_50 ) ;
if ( V_13 ) {
F_46 ( V_57 L_5 ,
V_48 -> V_58 ) ;
return;
}
F_47 ( ++ V_59 , V_50 . V_22 , V_60 ) ;
}
static void T_3 F_48 ( void )
{
struct V_7 * V_48 ;
F_49 (dn, NULL, L_6 )
F_45 ( V_48 ) ;
if ( V_61 ) {
V_62 = 1 ;
return;
}
F_46 ( V_57 L_7 ) ;
}
static void T_3 F_48 ( void ) {}
static void T_3 F_50 ( void )
{
F_38 () ;
F_48 () ;
}
static void T_3 F_51 ( void )
{
T_1 V_19 , V_63 ;
void * V_64 ;
if ( ! V_28 )
return;
V_63 = F_52 ( V_65 - ( V_28 & ~ V_66 ) ,
( T_4 ) sizeof( struct V_67 ) ) ;
V_68 = F_53 ( V_28 , V_63 ) ;
V_19 = F_54 ( V_68 -> V_69 ) ;
if ( V_63 < V_19 ) {
F_55 ( V_68 , V_63 ) ;
V_68 = F_53 ( V_28 , V_19 ) ;
V_63 = V_19 ;
}
V_64 = F_56 ( V_19 ) ;
memcpy ( V_64 , V_68 , V_19 ) ;
F_55 ( V_68 , V_63 ) ;
V_68 = V_64 ;
F_57 ( V_70 , NULL ) ;
F_58 () ;
}
static inline void F_51 ( void ) { }
void T_3 F_59 ( void )
{
F_51 () ;
if ( ! F_22 () )
return;
F_33 () ;
F_50 () ;
}
static int F_60 ( struct V_1 * V_71 , const T_1 * V_10 , T_1 V_11 ,
T_1 * V_72 , T_1 * V_73 )
{
struct V_74 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
T_1 line , V_80 , type ;
if ( V_11 < 2 )
return - V_44 ;
line = * V_10 ;
V_80 = ( T_1 ) V_71 -> V_81 ;
V_75 = F_61 ( V_80 ) ;
* V_72 = line + V_75 -> V_82 ;
V_10 ++ ;
type = * V_10 ;
if ( type >= F_62 ( V_78 ) )
return - V_44 ;
V_79 = V_78 + type ;
* V_73 = V_79 -> V_73 ;
F_63 ( & V_77 , V_80 , line , V_79 -> V_83 , V_79 -> V_84 ) ;
return F_64 ( * V_72 , F_65 ( 0 ) , & V_77 ) ;
}
static void T_3 F_66 ( struct V_7 * V_33 )
{
struct V_49 V_50 ;
int V_85 , V_13 ;
V_13 = F_36 ( V_33 , 0 , & V_50 ) ;
if ( V_13 ) {
F_46 ( V_57 L_8 ,
V_33 -> V_58 ) ;
return;
}
for ( V_85 = 0 ; V_85 < V_61 ; V_85 ++ ) {
if ( V_50 . V_22 == F_67 ( V_85 ) ) {
struct V_1 * V_71 ;
V_71 = F_68 ( sizeof( * V_71 ) , V_86 ) ;
F_10 ( ! V_71 ) ;
V_71 -> V_8 = V_33 ;
V_71 -> V_14 = F_60 ;
V_71 -> V_81 = ( void * ) V_85 ;
F_1 ( V_71 ) ;
return;
}
}
F_46 ( V_57 L_9 , V_33 -> V_58 ) ;
}
void T_3 F_69 ( void )
{
struct V_7 * V_87 ;
if ( ! F_22 () )
return;
F_70 (dp, L_10 ) {
if ( F_71 ( V_87 , L_6 ) )
F_66 ( V_87 ) ;
}
}
void T_3 F_69 ( void ) { }
