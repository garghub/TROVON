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
static int F_24 ( struct V_31 * V_32 )
{
struct V_33 V_34 ;
T_1 V_12 ;
int V_13 ;
T_5 V_35 ;
V_13 = F_25 ( V_32 , V_36 , & V_35 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_35 )
return 0 ;
V_13 = F_26 ( V_32 , & V_34 ) ;
if ( V_13 )
return V_13 ;
V_12 = F_7 ( V_34 . V_8 , V_34 . V_37 ,
V_34 . V_19 ) ;
if ( V_12 == 0 )
return - V_38 ;
V_32 -> V_39 = V_12 ;
return 0 ;
}
static void F_27 ( struct V_31 * V_32 )
{
}
void T_6 F_28 ( void )
{
struct V_7 * V_40 ;
V_41 = F_24 ;
V_42 = F_27 ;
F_29 (np, L_1 ) {
const void * V_43 ;
struct V_44 * V_45 ;
unsigned int V_46 ;
struct V_7 * V_47 ;
V_43 = F_30 ( V_40 , L_2 , NULL ) ;
if ( ! V_43 )
continue;
V_46 = F_31 ( V_43 ) ;
V_45 = F_32 ( 0 , V_46 ) ;
if ( ! V_45 ) {
F_33 ( V_48 L_3 ,
V_40 -> V_49 ) ;
continue;
}
if ( V_45 -> V_50 )
V_45 -> V_50 -> V_32 . V_51 = V_40 ;
else
V_45 -> V_32 . V_51 = V_40 ;
F_34 (np, child) {
struct V_31 * V_32 ;
T_1 V_52 ;
V_43 = F_30 ( V_47 , L_4 , NULL ) ;
if ( ! V_43 )
continue;
V_52 = ( F_31 ( V_43 ) >> 8 ) & 0xff ;
V_32 = F_35 ( V_45 , V_52 ) ;
if ( ! V_32 )
continue;
V_32 -> V_32 . V_51 = V_47 ;
F_36 ( V_32 ) ;
}
}
}
static void T_3 F_37 ( void )
{
#ifdef F_38
struct V_7 * V_53 ;
struct V_54 V_55 ;
int V_13 ;
V_53 = F_39 ( NULL , NULL , L_5 ) ;
if ( ! V_53 )
return;
V_13 = F_40 ( V_53 , 0 , & V_55 ) ;
if ( V_13 ) {
F_41 ( 1 ) ;
return;
}
V_56 = V_55 . V_22 ;
#endif
}
static void T_3 F_42 ( void )
{
#ifdef F_43
struct V_7 * V_53 ;
struct V_54 V_55 ;
int V_13 ;
V_53 = F_39 ( NULL , NULL , L_6 ) ;
if ( ! V_53 )
return;
V_13 = F_40 ( V_53 , 0 , & V_55 ) ;
if ( F_41 ( V_13 ) )
return;
if ( ! V_57 ) {
if ( F_44 ( V_55 . V_22 ) )
return;
}
V_58 = 1 ;
V_59 = 1 ;
F_45 ( V_55 . V_22 ) ;
F_46 ( V_60 ,
F_47 ( F_48 ( V_61 ) ) ) ;
#endif
}
static void T_3 F_49 ( struct V_7 * V_53 )
{
struct V_54 V_55 ;
int V_13 ;
V_13 = F_40 ( V_53 , 0 , & V_55 ) ;
if ( V_13 ) {
F_33 ( V_48 L_7 ,
V_53 -> V_49 ) ;
return;
}
F_50 ( ++ V_62 , V_55 . V_22 , V_63 ) ;
}
static void T_3 F_51 ( void )
{
struct V_7 * V_53 ;
F_52 (dn, NULL, L_8 )
F_49 ( V_53 ) ;
if ( V_64 ) {
V_65 = 1 ;
return;
}
F_33 ( V_48 L_9 ) ;
}
static void T_3 F_51 ( void ) {}
static void T_3 F_53 ( void )
{
F_42 () ;
F_51 () ;
}
static void T_3 F_54 ( void )
{
T_1 V_19 , V_66 ;
void * V_67 ;
if ( ! V_28 )
return;
V_66 = F_55 ( V_68 - ( V_28 & ~ V_69 ) ,
( T_4 ) sizeof( struct V_70 ) ) ;
V_71 = F_56 ( V_28 , V_66 ) ;
V_19 = F_57 ( V_71 -> V_72 ) ;
if ( V_66 < V_19 ) {
F_58 ( V_71 , V_66 ) ;
V_71 = F_56 ( V_28 , V_19 ) ;
V_66 = V_19 ;
}
V_67 = F_59 ( V_19 ) ;
memcpy ( V_67 , V_71 , V_19 ) ;
F_58 ( V_71 , V_66 ) ;
V_71 = V_67 ;
F_60 ( V_73 , NULL ) ;
F_61 () ;
}
static inline void F_54 ( void ) { }
void T_3 F_62 ( void )
{
F_54 () ;
if ( ! F_22 () )
return;
F_37 () ;
F_53 () ;
}
static int F_63 ( struct V_1 * V_74 , const T_1 * V_10 , T_1 V_11 ,
T_1 * V_75 , T_1 * V_76 )
{
struct V_77 * V_78 ;
struct V_79 V_80 ;
struct V_81 * V_82 ;
T_1 line , V_83 , type ;
if ( V_11 < 2 )
return - V_38 ;
line = * V_10 ;
V_83 = ( T_1 ) V_74 -> V_84 ;
V_78 = F_64 ( V_83 ) ;
* V_75 = line + V_78 -> V_85 ;
V_10 ++ ;
type = * V_10 ;
if ( type >= F_65 ( V_81 ) )
return - V_38 ;
V_82 = V_81 + type ;
* V_76 = V_82 -> V_76 ;
F_66 ( & V_80 , V_83 , line , V_82 -> V_86 , V_82 -> V_87 ) ;
return F_67 ( * V_75 , F_68 ( 0 ) , & V_80 ) ;
}
static void T_3 F_69 ( struct V_7 * V_40 )
{
struct V_54 V_55 ;
int V_88 , V_13 ;
V_13 = F_40 ( V_40 , 0 , & V_55 ) ;
if ( V_13 ) {
F_33 ( V_48 L_10 ,
V_40 -> V_49 ) ;
return;
}
for ( V_88 = 0 ; V_88 < V_64 ; V_88 ++ ) {
if ( V_55 . V_22 == F_70 ( V_88 ) ) {
struct V_1 * V_74 ;
V_74 = F_71 ( sizeof( * V_74 ) , V_89 ) ;
F_10 ( ! V_74 ) ;
V_74 -> V_8 = V_40 ;
V_74 -> V_14 = F_63 ;
V_74 -> V_84 = ( void * ) V_88 ;
F_1 ( V_74 ) ;
return;
}
}
F_33 ( V_48 L_11 , V_40 -> V_49 ) ;
}
void T_3 F_72 ( void )
{
struct V_7 * V_90 ;
if ( ! F_22 () )
return;
F_73 (dp, L_12 ) {
if ( F_74 ( V_90 , L_8 ) )
F_69 ( V_90 ) ;
}
}
void T_3 F_72 ( void ) { }
