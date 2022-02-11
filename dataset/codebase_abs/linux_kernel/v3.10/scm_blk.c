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
static void F_29 ( struct V_24 * V_24 , T_1 V_23 )
{
F_30 () ;
}
static bool F_31 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
return F_32 ( V_28 ) != V_29 || V_26 -> V_30 != V_31 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_32 * V_33 = V_26 -> V_24 -> V_34 ;
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_35 * V_35 = & V_2 -> V_5 -> V_35 [ 0 ] ;
struct V_36 V_8 ;
struct V_37 * V_38 ;
V_35 -> V_39 = V_40 ;
V_2 -> V_5 -> V_27 . V_41 = 1 ;
V_35 -> V_42 = V_33 -> V_43 +
( ( V_44 ) F_34 ( V_2 -> V_27 ) << 9 ) ;
V_35 -> V_45 = ( F_32 ( V_2 -> V_27 ) == V_46 ) ?
V_47 : V_48 ;
V_35 -> V_20 |= V_49 ;
V_35 -> V_50 = ( V_44 ) V_6 ;
F_35 (bv, scmrq->request, iter) {
F_36 ( V_38 -> V_51 ) ;
V_35 -> V_52 += V_38 -> V_53 >> 12 ;
V_6 -> V_50 = ( V_44 ) F_37 ( V_38 -> V_54 ) ;
V_6 ++ ;
}
}
static inline void F_38 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
memset ( V_2 -> V_6 , 0 , V_55 ) ;
V_4 -> V_33 = V_26 -> V_33 ;
V_5 -> V_27 . V_56 = V_57 ;
V_5 -> V_27 . V_14 = ( V_44 ) V_4 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_58 = 4 ;
V_2 -> error = 0 ;
F_39 ( V_2 ) ;
}
static void F_40 ( struct V_25 * V_26 )
{
if ( F_41 ( & V_26 -> V_59 ) ) {
return;
}
F_42 ( V_26 -> V_60 , V_61 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
F_44 ( V_2 ) ;
F_45 ( V_26 -> V_60 , V_2 -> V_27 ) ;
F_46 ( & V_26 -> V_59 ) ;
F_24 ( V_2 ) ;
F_40 ( V_26 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
F_44 ( V_2 ) ;
F_48 ( V_2 -> V_27 , V_2 -> error ) ;
F_46 ( & V_26 -> V_59 ) ;
F_24 ( V_2 ) ;
}
static void F_49 ( struct V_62 * V_60 )
{
struct V_32 * V_33 = V_60 -> V_63 ;
struct V_25 * V_26 = F_50 ( & V_33 -> V_64 ) ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_18 ;
while ( ( V_28 = F_51 ( V_60 ) ) ) {
if ( V_28 -> V_65 != V_66 )
continue;
if ( ! F_31 ( V_26 , V_28 ) ) {
F_40 ( V_26 ) ;
return;
}
V_2 = F_19 () ;
if ( ! V_2 ) {
F_52 ( 5 , L_1 ) ;
F_40 ( V_26 ) ;
return;
}
F_38 ( V_26 , V_2 , V_28 ) ;
if ( ! F_53 ( V_2 ) ) {
F_52 ( 5 , L_2 ) ;
F_24 ( V_2 ) ;
return;
}
if ( F_54 ( V_2 ) ) {
F_55 ( & V_26 -> V_59 ) ;
F_56 ( V_28 ) ;
F_57 ( V_2 ) ;
return;
}
F_33 ( V_2 ) ;
F_55 ( & V_26 -> V_59 ) ;
F_56 ( V_28 ) ;
V_18 = F_58 ( V_2 -> V_5 ) ;
if ( V_18 ) {
F_52 ( 5 , L_3 ) ;
F_43 ( V_2 ) ;
return;
}
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> error == - V_67 )
F_52 ( 1 , L_4 ) ;
else {
F_52 ( 1 , L_5 ) ;
F_60 ( 1 , & V_5 -> V_68 , sizeof( V_5 -> V_68 ) ) ;
}
if ( V_2 -> V_58 )
F_52 ( 1 , L_6 ) ;
else
F_61 ( L_7 ,
V_2 -> error ) ;
}
void F_62 ( struct V_32 * V_33 , void * V_14 , int error )
{
struct V_1 * V_2 = V_14 ;
struct V_25 * V_26 = V_2 -> V_26 ;
V_2 -> error = error ;
if ( error )
F_59 ( V_2 ) ;
F_20 ( & V_26 -> V_69 ) ;
F_63 ( & V_2 -> V_11 , & V_26 -> V_70 ) ;
F_23 ( & V_26 -> V_69 ) ;
F_64 ( & V_26 -> V_71 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned long V_20 ;
if ( V_2 -> error != - V_72 )
goto V_73;
switch ( V_2 -> V_5 -> V_68 . V_74 ) {
case V_75 :
F_25 ( & V_26 -> V_69 , V_20 ) ;
if ( V_26 -> V_30 != V_31 )
F_66 ( L_8 ,
( unsigned long ) V_26 -> V_33 -> V_43 ) ;
V_26 -> V_30 = V_31 ;
F_26 ( & V_26 -> V_69 , V_20 ) ;
goto V_76;
default:
break;
}
V_73:
if ( ! F_58 ( V_2 -> V_5 ) )
return;
V_76:
F_25 ( & V_26 -> V_77 , V_20 ) ;
F_43 ( V_2 ) ;
F_26 ( & V_26 -> V_77 , V_20 ) ;
}
static void F_67 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
unsigned long V_20 ;
F_25 ( & V_26 -> V_69 , V_20 ) ;
while ( ! F_21 ( & V_26 -> V_70 ) ) {
V_2 = F_22 ( & V_26 -> V_70 ,
struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_26 ( & V_26 -> V_69 , V_20 ) ;
if ( V_2 -> error && V_2 -> V_58 -- > 0 ) {
F_65 ( V_2 ) ;
F_25 ( & V_26 -> V_69 , V_20 ) ;
continue;
}
if ( F_68 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_25 ( & V_26 -> V_69 , V_20 ) ;
continue;
}
F_47 ( V_2 ) ;
F_25 ( & V_26 -> V_69 , V_20 ) ;
}
F_26 ( & V_26 -> V_69 , V_20 ) ;
F_70 ( V_26 -> V_60 ) ;
}
int F_71 ( struct V_25 * V_26 , struct V_32 * V_33 )
{
struct V_62 * V_60 ;
int V_78 , V_18 = - V_13 ;
unsigned int V_79 , V_80 ;
V_79 = F_72 ( & V_81 ) - 1 ;
if ( V_79 > 701 ) {
V_18 = - V_82 ;
goto V_19;
}
V_26 -> V_33 = V_33 ;
V_26 -> V_30 = V_83 ;
F_73 ( & V_26 -> V_77 ) ;
F_73 ( & V_26 -> V_69 ) ;
F_16 ( & V_26 -> V_70 ) ;
F_74 ( & V_26 -> V_59 , 0 ) ;
F_75 ( & V_26 -> V_71 ,
( void (*) ( unsigned long ) ) F_67 ,
( unsigned long ) V_26 ) ;
V_60 = F_76 ( F_49 , & V_26 -> V_77 ) ;
if ( ! V_60 )
goto V_19;
V_26 -> V_60 = V_60 ;
V_80 = F_77 ( V_33 -> V_84 ,
( unsigned int ) ( V_55 / sizeof( struct V_6 ) ) ) ;
F_78 ( V_60 , 1 << 12 ) ;
F_79 ( V_60 , V_80 << 3 ) ;
F_80 ( V_60 , V_80 ) ;
F_81 ( V_85 , V_60 ) ;
F_82 ( V_26 ) ;
V_26 -> V_24 = F_83 ( V_86 ) ;
if ( ! V_26 -> V_24 )
goto V_87;
V_60 -> V_63 = V_33 ;
V_26 -> V_24 -> V_88 = & V_33 -> V_64 ;
V_26 -> V_24 -> V_34 = V_33 ;
V_26 -> V_24 -> V_89 = & V_90 ;
V_26 -> V_24 -> V_91 = V_60 ;
V_26 -> V_24 -> V_92 = V_93 ;
V_26 -> V_24 -> V_94 = V_79 * V_86 ;
V_78 = snprintf ( V_26 -> V_24 -> V_95 , V_96 , L_9 ) ;
if ( V_79 > 25 ) {
V_78 += snprintf ( V_26 -> V_24 -> V_95 + V_78 ,
V_96 - V_78 , L_10 ,
'a' + ( V_79 / 26 ) - 1 ) ;
V_79 = V_79 % 26 ;
}
snprintf ( V_26 -> V_24 -> V_95 + V_78 , V_96 - V_78 , L_10 ,
'a' + V_79 ) ;
F_84 ( V_26 -> V_24 , V_33 -> V_97 >> 9 ) ;
F_85 ( V_26 -> V_24 ) ;
return 0 ;
V_87:
F_86 ( V_60 ) ;
V_19:
F_46 ( & V_81 ) ;
return V_18 ;
}
void F_87 ( struct V_25 * V_26 )
{
F_88 ( & V_26 -> V_71 ) ;
F_89 ( V_26 -> V_24 ) ;
F_86 ( V_26 -> V_24 -> V_91 ) ;
F_90 ( V_26 -> V_24 ) ;
}
void F_91 ( struct V_25 * V_26 )
{
unsigned long V_20 ;
F_25 ( & V_26 -> V_69 , V_20 ) ;
if ( V_26 -> V_30 == V_31 )
F_66 ( L_11 ,
( unsigned long ) V_26 -> V_33 -> V_43 ) ;
V_26 -> V_30 = V_83 ;
F_26 ( & V_26 -> V_69 , V_20 ) ;
}
static int T_2 F_92 ( void )
{
int V_18 = - V_98 ;
if ( ! F_93 () )
goto V_19;
V_18 = F_94 ( 0 , L_9 ) ;
if ( V_18 < 0 )
goto V_19;
V_93 = V_18 ;
V_18 = F_18 ( V_99 ) ;
if ( V_18 )
goto V_100;
V_101 = F_95 ( L_12 , 16 , 1 , 16 ) ;
if ( ! V_101 ) {
V_18 = - V_13 ;
goto V_100;
}
F_96 ( V_101 , & V_102 ) ;
F_97 ( V_101 , 2 ) ;
V_18 = F_98 () ;
if ( V_18 )
goto V_103;
return V_18 ;
V_103:
F_99 ( V_101 ) ;
V_100:
F_6 () ;
F_100 ( V_93 , L_9 ) ;
V_19:
return V_18 ;
}
static void T_3 F_101 ( void )
{
F_102 () ;
F_99 ( V_101 ) ;
F_6 () ;
F_100 ( V_93 , L_9 ) ;
}
