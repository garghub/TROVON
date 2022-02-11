static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( ( unsigned long ) V_2 -> V_5 ) ;
F_3 ( ( unsigned long ) V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
}
static void F_6 ( void )
{
struct V_7 * V_8 , * V_9 ;
struct V_1 * V_2 ;
F_7 ( & V_10 ) ;
F_8 (iter, safe, &inactive_requests) {
V_2 = F_9 ( V_8 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_1 ( V_2 ) ;
}
F_11 ( & V_10 ) ;
}
static int F_12 ( void )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_13 ( sizeof( * V_4 ) + sizeof( * V_2 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 = ( void * ) V_4 -> V_14 ;
V_2 -> V_6 = ( void * ) F_14 ( V_15 ) ;
V_2 -> V_5 = ( void * ) F_14 ( V_15 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_6 ) {
F_1 ( V_2 ) ;
return - V_13 ;
}
if ( F_15 ( V_2 ) ) {
F_1 ( V_2 ) ;
return - V_13 ;
}
F_16 ( & V_2 -> V_11 ) ;
F_7 ( & V_10 ) ;
F_17 ( & V_2 -> V_11 , & V_16 ) ;
F_11 ( & V_10 ) ;
return 0 ;
}
static int F_18 ( unsigned int V_17 )
{
int V_18 = 0 ;
while ( V_17 -- && ! V_18 )
V_18 = F_12 () ;
return V_18 ;
}
static struct V_1 * F_19 ( void )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_10 ) ;
if ( F_21 ( & V_16 ) )
goto V_19;
V_2 = F_22 ( & V_16 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
V_19:
F_23 ( & V_10 ) ;
return V_2 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_25 ( & V_10 , V_20 ) ;
F_17 ( & V_2 -> V_11 , & V_16 ) ;
F_26 ( & V_10 , V_20 ) ;
}
static int F_27 ( struct V_21 * V_22 , T_1 V_23 )
{
return F_28 () ;
}
static int F_29 ( struct V_24 * V_24 , T_1 V_23 )
{
F_30 () ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_24 -> V_29 ;
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_30 * V_30 = & V_2 -> V_5 -> V_30 [ 0 ] ;
struct V_31 V_8 ;
struct V_32 * V_33 ;
V_30 -> V_34 = V_35 ;
V_2 -> V_5 -> V_36 . V_37 = 1 ;
V_30 -> V_38 = V_28 -> V_39 +
( ( V_40 ) F_32 ( V_2 -> V_36 ) << 9 ) ;
V_30 -> V_41 = ( F_33 ( V_2 -> V_36 ) == V_42 ) ?
V_43 : V_44 ;
V_30 -> V_20 |= V_45 ;
V_30 -> V_46 = ( V_40 ) V_6 ;
F_34 (bv, scmrq->request, iter) {
F_35 ( V_33 -> V_47 ) ;
V_30 -> V_48 += V_33 -> V_49 >> 12 ;
V_6 -> V_46 = ( V_40 ) F_36 ( V_33 -> V_50 ) ;
V_6 ++ ;
}
}
static inline void F_37 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
struct V_36 * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
memset ( V_2 -> V_6 , 0 , V_52 ) ;
V_4 -> V_28 = V_26 -> V_28 ;
V_5 -> V_36 . V_53 = V_54 ;
V_5 -> V_36 . V_14 = ( V_40 ) V_4 ;
V_2 -> V_36 = V_51 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_55 = 4 ;
V_2 -> error = 0 ;
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_25 * V_26 )
{
if ( F_40 ( & V_26 -> V_56 ) ) {
return;
}
F_41 ( V_26 -> V_57 , V_58 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
F_43 ( V_2 ) ;
F_44 ( V_26 -> V_57 , V_2 -> V_36 ) ;
F_24 ( V_2 ) ;
F_39 ( V_26 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_46 ( V_2 -> V_36 , V_2 -> error ) ;
F_24 ( V_2 ) ;
}
static void F_47 ( struct V_59 * V_57 )
{
struct V_27 * V_28 = V_57 -> V_60 ;
struct V_25 * V_26 = F_48 ( & V_28 -> V_61 ) ;
struct V_1 * V_2 ;
struct V_36 * V_51 ;
int V_18 ;
while ( ( V_51 = F_49 ( V_57 ) ) ) {
if ( V_51 -> V_62 != V_63 )
continue;
V_2 = F_19 () ;
if ( ! V_2 ) {
F_50 ( 5 , L_1 ) ;
F_39 ( V_26 ) ;
return;
}
F_37 ( V_26 , V_2 , V_51 ) ;
if ( ! F_51 ( V_2 ) ) {
F_50 ( 5 , L_2 ) ;
F_24 ( V_2 ) ;
return;
}
if ( F_52 ( V_2 ) ) {
F_53 ( V_51 ) ;
F_54 ( V_2 ) ;
return;
}
F_31 ( V_2 ) ;
F_53 ( V_51 ) ;
V_18 = F_55 ( V_2 -> V_5 ) ;
if ( V_18 ) {
F_50 ( 5 , L_3 ) ;
F_42 ( V_2 ) ;
return;
}
F_56 ( & V_26 -> V_56 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> error == - V_64 )
F_50 ( 1 , L_4 ) ;
else {
F_50 ( 1 , L_5 ) ;
F_58 ( 1 , & V_5 -> V_65 , sizeof( V_5 -> V_65 ) ) ;
}
if ( V_2 -> V_55 )
F_50 ( 1 , L_6 ) ;
else
F_59 ( L_7 ,
V_2 -> error ) ;
}
void F_60 ( struct V_27 * V_28 , void * V_14 , int error )
{
struct V_1 * V_2 = V_14 ;
struct V_25 * V_26 = V_2 -> V_26 ;
V_2 -> error = error ;
if ( error )
F_57 ( V_2 ) ;
F_20 ( & V_26 -> V_66 ) ;
F_61 ( & V_2 -> V_11 , & V_26 -> V_67 ) ;
F_23 ( & V_26 -> V_66 ) ;
F_62 ( & V_26 -> V_68 ) ;
}
static void F_63 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
unsigned long V_20 ;
F_25 ( & V_26 -> V_66 , V_20 ) ;
while ( ! F_21 ( & V_26 -> V_67 ) ) {
V_2 = F_22 ( & V_26 -> V_67 ,
struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_26 ( & V_26 -> V_66 , V_20 ) ;
if ( V_2 -> error && V_2 -> V_55 -- > 0 ) {
if ( F_55 ( V_2 -> V_5 ) ) {
F_25 ( & V_26 -> V_69 , V_20 ) ;
F_42 ( V_2 ) ;
F_26 ( & V_26 -> V_69 , V_20 ) ;
}
F_25 ( & V_26 -> V_66 , V_20 ) ;
continue;
}
if ( F_64 ( V_2 ) ) {
F_65 ( V_2 ) ;
F_25 ( & V_26 -> V_66 , V_20 ) ;
continue;
}
F_45 ( V_2 ) ;
F_66 ( & V_26 -> V_56 ) ;
F_25 ( & V_26 -> V_66 , V_20 ) ;
}
F_26 ( & V_26 -> V_66 , V_20 ) ;
F_67 ( V_26 -> V_57 ) ;
}
int F_68 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
struct V_59 * V_57 ;
int V_70 , V_18 = - V_13 ;
unsigned int V_71 , V_72 ;
V_71 = F_69 ( & V_73 ) - 1 ;
if ( V_71 > 701 ) {
V_18 = - V_74 ;
goto V_19;
}
V_26 -> V_28 = V_28 ;
F_70 ( & V_26 -> V_69 ) ;
F_70 ( & V_26 -> V_66 ) ;
F_16 ( & V_26 -> V_67 ) ;
F_71 ( & V_26 -> V_56 , 0 ) ;
F_72 ( & V_26 -> V_68 ,
( void (*) ( unsigned long ) ) F_63 ,
( unsigned long ) V_26 ) ;
V_57 = F_73 ( F_47 , & V_26 -> V_69 ) ;
if ( ! V_57 )
goto V_19;
V_26 -> V_57 = V_57 ;
V_72 = F_74 ( V_28 -> V_75 ,
( unsigned int ) ( V_52 / sizeof( struct V_6 ) ) ) ;
F_75 ( V_57 , 1 << 12 ) ;
F_76 ( V_57 , V_72 << 3 ) ;
F_77 ( V_57 , V_72 ) ;
F_78 ( V_76 , V_57 ) ;
F_79 ( V_26 ) ;
V_26 -> V_24 = F_80 ( V_77 ) ;
if ( ! V_26 -> V_24 )
goto V_78;
V_57 -> V_60 = V_28 ;
V_26 -> V_24 -> V_79 = & V_28 -> V_61 ;
V_26 -> V_24 -> V_29 = V_28 ;
V_26 -> V_24 -> V_80 = & V_81 ;
V_26 -> V_24 -> V_82 = V_57 ;
V_26 -> V_24 -> V_83 = V_84 ;
V_26 -> V_24 -> V_85 = V_71 * V_77 ;
V_70 = snprintf ( V_26 -> V_24 -> V_86 , V_87 , L_8 ) ;
if ( V_71 > 25 ) {
V_70 += snprintf ( V_26 -> V_24 -> V_86 + V_70 ,
V_87 - V_70 , L_9 ,
'a' + ( V_71 / 26 ) - 1 ) ;
V_71 = V_71 % 26 ;
}
snprintf ( V_26 -> V_24 -> V_86 + V_70 , V_87 - V_70 , L_9 ,
'a' + V_71 ) ;
F_81 ( V_26 -> V_24 , V_28 -> V_88 >> 9 ) ;
F_82 ( V_26 -> V_24 ) ;
return 0 ;
V_78:
F_83 ( V_57 ) ;
V_19:
F_66 ( & V_73 ) ;
return V_18 ;
}
void F_84 ( struct V_25 * V_26 )
{
F_85 ( & V_26 -> V_68 ) ;
F_86 ( V_26 -> V_24 ) ;
F_83 ( V_26 -> V_24 -> V_82 ) ;
F_87 ( V_26 -> V_24 ) ;
}
static int T_2 F_88 ( void )
{
int V_18 = - V_89 ;
if ( ! F_89 () )
goto V_19;
V_18 = F_90 ( 0 , L_8 ) ;
if ( V_18 < 0 )
goto V_19;
V_84 = V_18 ;
if ( F_18 ( V_90 ) )
goto V_91;
V_92 = F_91 ( L_10 , 16 , 1 , 16 ) ;
if ( ! V_92 )
goto V_93;
F_92 ( V_92 , & V_94 ) ;
F_93 ( V_92 , 2 ) ;
V_18 = F_94 () ;
if ( V_18 )
goto V_95;
return V_18 ;
V_95:
F_95 ( V_92 ) ;
V_93:
F_6 () ;
V_91:
F_96 ( V_84 , L_8 ) ;
V_19:
return V_18 ;
}
static void T_3 F_97 ( void )
{
F_98 () ;
F_95 ( V_92 ) ;
F_6 () ;
F_96 ( V_84 , L_8 ) ;
}
