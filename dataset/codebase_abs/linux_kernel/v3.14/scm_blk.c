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
static bool F_27 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
return F_28 ( V_24 ) != V_25 || V_22 -> V_26 != V_27 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_28 * V_29 = V_22 -> V_30 -> V_31 ;
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_32 * V_32 = & V_2 -> V_5 -> V_32 [ 0 ] ;
struct V_33 V_8 ;
struct V_34 V_35 ;
V_32 -> V_36 = V_37 ;
V_2 -> V_5 -> V_23 . V_38 = 1 ;
V_32 -> V_39 = V_29 -> V_40 +
( ( V_41 ) F_30 ( V_2 -> V_23 ) << 9 ) ;
V_32 -> V_42 = ( F_28 ( V_2 -> V_23 ) == V_43 ) ?
V_44 : V_45 ;
V_32 -> V_20 |= V_46 ;
V_32 -> V_47 = ( V_41 ) V_6 ;
F_31 (bv, scmrq->request, iter) {
F_32 ( V_35 . V_48 ) ;
V_32 -> V_49 += V_35 . V_50 >> 12 ;
V_6 -> V_47 = ( V_41 ) F_33 ( V_35 . V_51 ) ;
V_6 ++ ;
}
}
static inline void F_34 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
memset ( V_2 -> V_6 , 0 , V_52 ) ;
V_4 -> V_29 = V_22 -> V_29 ;
V_5 -> V_23 . V_53 = V_54 ;
V_5 -> V_23 . V_14 = ( V_41 ) V_4 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_55 = 4 ;
V_2 -> error = 0 ;
F_35 ( V_2 ) ;
}
static void F_36 ( struct V_21 * V_22 )
{
if ( F_37 ( & V_22 -> V_56 ) ) {
return;
}
F_38 ( V_22 -> V_57 , V_58 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
F_40 ( V_2 ) ;
F_41 ( V_22 -> V_57 , V_2 -> V_23 ) ;
F_42 ( & V_22 -> V_56 ) ;
F_24 ( V_2 ) ;
F_36 ( V_22 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
F_40 ( V_2 ) ;
F_44 ( V_2 -> V_23 , V_2 -> error ) ;
F_42 ( & V_22 -> V_56 ) ;
F_24 ( V_2 ) ;
}
static void F_45 ( struct V_59 * V_57 )
{
struct V_28 * V_29 = V_57 -> V_60 ;
struct V_21 * V_22 = F_46 ( & V_29 -> V_61 ) ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_18 ;
while ( ( V_24 = F_47 ( V_57 ) ) ) {
if ( V_24 -> V_62 != V_63 ) {
F_48 ( V_24 ) ;
F_49 ( V_24 , V_64 L_1 ) ;
F_44 ( V_24 , - V_65 ) ;
continue;
}
if ( ! F_27 ( V_22 , V_24 ) ) {
F_36 ( V_22 ) ;
return;
}
V_2 = F_19 () ;
if ( ! V_2 ) {
F_50 ( 5 , L_2 ) ;
F_36 ( V_22 ) ;
return;
}
F_34 ( V_22 , V_2 , V_24 ) ;
if ( ! F_51 ( V_2 ) ) {
F_50 ( 5 , L_3 ) ;
F_24 ( V_2 ) ;
return;
}
if ( F_52 ( V_2 ) ) {
F_53 ( & V_22 -> V_56 ) ;
F_48 ( V_24 ) ;
F_54 ( V_2 ) ;
return;
}
F_29 ( V_2 ) ;
F_53 ( & V_22 -> V_56 ) ;
F_48 ( V_24 ) ;
V_18 = F_55 ( V_2 -> V_5 ) ;
if ( V_18 ) {
F_50 ( 5 , L_4 ) ;
F_39 ( V_2 ) ;
return;
}
}
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> error == - V_66 )
F_50 ( 1 , L_5 ) ;
else {
F_50 ( 1 , L_6 ) ;
F_57 ( 1 , & V_5 -> V_67 , sizeof( V_5 -> V_67 ) ) ;
}
if ( V_2 -> V_55 )
F_50 ( 1 , L_7 ) ;
else
F_58 ( L_8 ,
V_2 -> error ) ;
}
void F_59 ( struct V_28 * V_29 , void * V_14 , int error )
{
struct V_1 * V_2 = V_14 ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_2 -> error = error ;
if ( error )
F_56 ( V_2 ) ;
F_20 ( & V_22 -> V_68 ) ;
F_60 ( & V_2 -> V_11 , & V_22 -> V_69 ) ;
F_23 ( & V_22 -> V_68 ) ;
F_61 ( & V_22 -> V_70 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
unsigned long V_20 ;
if ( V_2 -> error != - V_65 )
goto V_71;
switch ( V_2 -> V_5 -> V_67 . V_72 ) {
case V_73 :
F_25 ( & V_22 -> V_68 , V_20 ) ;
if ( V_22 -> V_26 != V_27 )
F_63 ( L_9 ,
( unsigned long ) V_22 -> V_29 -> V_40 ) ;
V_22 -> V_26 = V_27 ;
F_26 ( & V_22 -> V_68 , V_20 ) ;
goto V_74;
default:
break;
}
V_71:
if ( ! F_55 ( V_2 -> V_5 ) )
return;
V_74:
F_25 ( & V_22 -> V_75 , V_20 ) ;
F_39 ( V_2 ) ;
F_26 ( & V_22 -> V_75 , V_20 ) ;
}
static void F_64 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
unsigned long V_20 ;
F_25 ( & V_22 -> V_68 , V_20 ) ;
while ( ! F_21 ( & V_22 -> V_69 ) ) {
V_2 = F_22 ( & V_22 -> V_69 ,
struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_26 ( & V_22 -> V_68 , V_20 ) ;
if ( V_2 -> error && V_2 -> V_55 -- > 0 ) {
F_62 ( V_2 ) ;
F_25 ( & V_22 -> V_68 , V_20 ) ;
continue;
}
if ( F_65 ( V_2 ) ) {
F_66 ( V_2 ) ;
F_25 ( & V_22 -> V_68 , V_20 ) ;
continue;
}
F_43 ( V_2 ) ;
F_25 ( & V_22 -> V_68 , V_20 ) ;
}
F_26 ( & V_22 -> V_68 , V_20 ) ;
F_67 ( V_22 -> V_57 ) ;
}
int F_68 ( struct V_21 * V_22 , struct V_28 * V_29 )
{
struct V_59 * V_57 ;
int V_76 , V_18 = - V_13 ;
unsigned int V_77 , V_78 ;
V_77 = F_69 ( & V_79 ) - 1 ;
if ( V_77 > 701 ) {
V_18 = - V_80 ;
goto V_19;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_26 = V_81 ;
F_70 ( & V_22 -> V_75 ) ;
F_70 ( & V_22 -> V_68 ) ;
F_16 ( & V_22 -> V_69 ) ;
F_71 ( & V_22 -> V_56 , 0 ) ;
F_72 ( & V_22 -> V_70 ,
( void (*) ( unsigned long ) ) F_64 ,
( unsigned long ) V_22 ) ;
V_57 = F_73 ( F_45 , & V_22 -> V_75 ) ;
if ( ! V_57 )
goto V_19;
V_22 -> V_57 = V_57 ;
V_78 = F_74 ( V_29 -> V_82 ,
( unsigned int ) ( V_52 / sizeof( struct V_6 ) ) ) ;
F_75 ( V_57 , 1 << 12 ) ;
F_76 ( V_57 , V_78 << 3 ) ;
F_77 ( V_57 , V_78 ) ;
F_78 ( V_83 , V_57 ) ;
F_79 ( V_22 ) ;
V_22 -> V_30 = F_80 ( V_84 ) ;
if ( ! V_22 -> V_30 )
goto V_85;
V_57 -> V_60 = V_29 ;
V_22 -> V_30 -> V_86 = & V_29 -> V_61 ;
V_22 -> V_30 -> V_31 = V_29 ;
V_22 -> V_30 -> V_87 = & V_88 ;
V_22 -> V_30 -> V_89 = V_57 ;
V_22 -> V_30 -> V_90 = V_91 ;
V_22 -> V_30 -> V_92 = V_77 * V_84 ;
V_76 = snprintf ( V_22 -> V_30 -> V_93 , V_94 , L_10 ) ;
if ( V_77 > 25 ) {
V_76 += snprintf ( V_22 -> V_30 -> V_93 + V_76 ,
V_94 - V_76 , L_11 ,
'a' + ( V_77 / 26 ) - 1 ) ;
V_77 = V_77 % 26 ;
}
snprintf ( V_22 -> V_30 -> V_93 + V_76 , V_94 - V_76 , L_11 ,
'a' + V_77 ) ;
F_81 ( V_22 -> V_30 , V_29 -> V_95 >> 9 ) ;
F_82 ( V_22 -> V_30 ) ;
return 0 ;
V_85:
F_83 ( V_57 ) ;
V_19:
F_42 ( & V_79 ) ;
return V_18 ;
}
void F_84 ( struct V_21 * V_22 )
{
F_85 ( & V_22 -> V_70 ) ;
F_86 ( V_22 -> V_30 ) ;
F_83 ( V_22 -> V_30 -> V_89 ) ;
F_87 ( V_22 -> V_30 ) ;
}
void F_88 ( struct V_21 * V_22 )
{
unsigned long V_20 ;
F_25 ( & V_22 -> V_68 , V_20 ) ;
if ( V_22 -> V_26 == V_27 )
F_63 ( L_12 ,
( unsigned long ) V_22 -> V_29 -> V_40 ) ;
V_22 -> V_26 = V_81 ;
F_26 ( & V_22 -> V_68 , V_20 ) ;
}
static int T_1 F_89 ( void )
{
int V_18 = - V_96 ;
if ( ! F_90 () )
goto V_19;
V_18 = F_91 ( 0 , L_10 ) ;
if ( V_18 < 0 )
goto V_19;
V_91 = V_18 ;
V_18 = F_18 ( V_97 ) ;
if ( V_18 )
goto V_98;
V_99 = F_92 ( L_13 , 16 , 1 , 16 ) ;
if ( ! V_99 ) {
V_18 = - V_13 ;
goto V_98;
}
F_93 ( V_99 , & V_100 ) ;
F_94 ( V_99 , 2 ) ;
V_18 = F_95 () ;
if ( V_18 )
goto V_101;
return V_18 ;
V_101:
F_96 ( V_99 ) ;
V_98:
F_6 () ;
F_97 ( V_91 , L_10 ) ;
V_19:
return V_18 ;
}
static void T_2 F_98 ( void )
{
F_99 () ;
F_96 ( V_99 ) ;
F_6 () ;
F_97 ( V_91 , L_10 ) ;
}
