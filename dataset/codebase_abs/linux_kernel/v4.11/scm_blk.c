static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( ( unsigned long ) V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 -> V_6 ) ;
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
F_12 ( V_12 ) ;
}
static int F_13 ( void )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_14 ( sizeof( * V_4 ) + sizeof( * V_2 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_2 = ( void * ) V_4 -> V_15 ;
V_2 -> V_5 = ( void * ) F_15 ( V_16 ) ;
if ( ! V_2 -> V_5 )
goto free;
V_2 -> V_6 = F_16 ( V_17 , sizeof( V_2 -> V_6 [ 0 ] ) ,
V_13 ) ;
if ( ! V_2 -> V_6 )
goto free;
if ( F_17 ( V_2 ) )
goto free;
F_18 ( & V_2 -> V_11 ) ;
F_7 ( & V_10 ) ;
F_19 ( & V_2 -> V_11 , & V_18 ) ;
F_11 ( & V_10 ) ;
return 0 ;
free:
F_1 ( V_2 ) ;
return - V_14 ;
}
static int F_20 ( unsigned int V_19 )
{
int V_20 = 0 ;
V_12 = F_21 ( F_22 ( V_19 / 8 , 1U ) , 0 ) ;
if ( ! V_12 )
return - V_14 ;
while ( V_19 -- && ! V_20 )
V_20 = F_13 () ;
return V_20 ;
}
static struct V_1 * F_23 ( void )
{
struct V_1 * V_2 = NULL ;
F_24 ( & V_10 ) ;
if ( F_25 ( & V_18 ) )
goto V_21;
V_2 = F_26 ( & V_18 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
V_21:
F_27 ( & V_10 ) ;
return V_2 ;
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
struct V_23 * V_23 ;
T_1 V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ ) {
V_23 = & V_2 -> V_5 -> V_23 [ V_25 ] ;
V_24 = V_23 -> V_26 ;
if ( ( V_23 -> V_22 & V_27 ) && V_24 &&
F_29 ( V_24 , V_28 ) )
F_30 ( F_31 ( V_24 ) , V_12 ) ;
}
F_32 ( & V_10 , V_22 ) ;
F_19 ( & V_2 -> V_11 , & V_18 ) ;
F_33 ( & V_10 , V_22 ) ;
}
static bool F_34 ( struct V_29 * V_30 , struct V_6 * V_31 )
{
return F_35 ( V_31 ) != V_32 || V_30 -> V_33 != V_34 ;
}
static inline struct V_24 * F_36 ( void )
{
struct V_35 * V_35 = F_37 ( V_12 , V_36 ) ;
return V_35 ? F_38 ( V_35 ) : NULL ;
}
static inline unsigned long F_39 ( struct V_24 * V_24 )
{
unsigned long V_37 = ( unsigned long ) V_24 ;
unsigned long V_38 = F_40 ( V_37 , V_28 ) - V_37 ;
return ( V_38 / sizeof( * V_24 ) ) * V_28 ;
}
struct V_24 * F_41 ( struct V_1 * V_2 , unsigned int V_38 )
{
struct V_24 * V_24 ;
if ( F_39 ( V_2 -> V_39 ) >= V_38 )
return V_2 -> V_39 ;
V_24 = F_36 () ;
if ( V_24 )
memset ( V_24 , 0 , V_28 ) ;
return V_24 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_40 * V_41 = V_30 -> V_42 -> V_43 ;
int V_44 = V_2 -> V_5 -> V_6 . V_45 ;
struct V_23 * V_23 = & V_2 -> V_5 -> V_23 [ V_44 ] ;
struct V_6 * V_31 = V_2 -> V_6 [ V_44 ] ;
struct V_46 V_8 ;
struct V_24 * V_24 ;
struct V_47 V_48 ;
V_24 = F_41 ( V_2 , F_43 ( V_31 ) ) ;
if ( ! V_24 )
return - V_14 ;
V_23 -> V_49 = V_50 ;
V_2 -> V_5 -> V_6 . V_45 ++ ;
V_23 -> V_51 = V_41 -> V_52 + ( ( T_1 ) F_44 ( V_31 ) << 9 ) ;
V_23 -> V_53 = ( F_35 ( V_31 ) == V_54 ) ? V_55 : V_56 ;
V_23 -> V_22 |= V_27 ;
V_23 -> V_26 = ( T_1 ) V_24 ;
F_45 (bv, req, iter) {
F_46 ( V_48 . V_57 ) ;
V_23 -> V_58 += V_48 . V_59 >> 12 ;
V_24 -> V_26 = ( T_1 ) F_38 ( V_48 . V_60 ) ;
V_24 ++ ;
}
V_2 -> V_39 = V_24 ;
return 0 ;
}
static inline void F_47 ( struct V_1 * V_2 ,
struct V_6 * V_31 )
{
V_2 -> V_6 [ V_2 -> V_5 -> V_6 . V_45 ] = V_31 ;
}
static inline void F_48 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
memset ( V_2 -> V_6 , 0 ,
V_17 * sizeof( V_2 -> V_6 [ 0 ] ) ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_4 -> V_41 = V_30 -> V_41 ;
V_5 -> V_6 . V_61 = V_62 ;
V_5 -> V_6 . V_15 = ( T_1 ) V_4 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_63 = 4 ;
V_2 -> error = 0 ;
V_2 -> V_39 = ( void * ) & V_5 -> V_23 [ V_17 ] ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_29 * V_30 )
{
if ( F_51 ( & V_30 -> V_64 ) ) {
return;
}
F_52 ( V_30 -> V_65 , V_66 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_25 ;
F_54 ( V_2 ) ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ )
F_55 ( V_30 -> V_65 , V_2 -> V_6 [ V_25 ] ) ;
F_56 ( & V_30 -> V_64 ) ;
F_28 ( V_2 ) ;
F_50 ( V_30 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_25 ;
F_54 ( V_2 ) ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ )
F_58 ( V_2 -> V_6 [ V_25 ] , V_2 -> error ) ;
F_56 ( & V_30 -> V_64 ) ;
F_28 ( V_2 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_20 ;
F_60 ( & V_30 -> V_64 ) ;
if ( ! V_2 -> V_5 -> V_6 . V_45 ) {
F_53 ( V_2 ) ;
return - V_67 ;
}
V_20 = F_61 ( V_2 -> V_5 ) ;
if ( V_20 ) {
F_62 ( 5 , L_1 ) ;
F_53 ( V_2 ) ;
}
return V_20 ;
}
static void F_63 ( struct V_68 * V_65 )
{
struct V_40 * V_41 = V_65 -> V_69 ;
struct V_29 * V_30 = F_64 ( & V_41 -> V_70 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_31 ;
while ( ( V_31 = F_65 ( V_65 ) ) ) {
if ( ! F_34 ( V_30 , V_31 ) )
goto V_21;
if ( ! V_2 ) {
V_2 = F_23 () ;
if ( ! V_2 ) {
F_62 ( 5 , L_2 ) ;
goto V_21;
}
F_48 ( V_30 , V_2 ) ;
}
F_47 ( V_2 , V_31 ) ;
if ( ! F_66 ( V_2 ) ) {
F_62 ( 5 , L_3 ) ;
F_47 ( V_2 , NULL ) ;
if ( V_2 -> V_5 -> V_6 . V_45 )
goto V_21;
F_28 ( V_2 ) ;
return;
}
if ( F_67 ( V_2 ) ) {
if ( V_2 -> V_5 -> V_6 . V_45 ) {
F_47 ( V_2 , NULL ) ;
if ( F_59 ( V_2 ) )
return;
} else {
F_60 ( & V_30 -> V_64 ) ;
F_68 ( V_31 ) ;
F_69 ( V_2 ) ;
}
V_2 = NULL ;
continue;
}
if ( F_42 ( V_2 ) ) {
F_62 ( 5 , L_4 ) ;
F_47 ( V_2 , NULL ) ;
goto V_21;
}
F_68 ( V_31 ) ;
if ( V_2 -> V_5 -> V_6 . V_45 < V_17 )
continue;
if ( F_59 ( V_2 ) )
return;
V_2 = NULL ;
}
V_21:
if ( V_2 )
F_59 ( V_2 ) ;
else
F_50 ( V_30 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> error == - V_71 )
F_62 ( 1 , L_5 ) ;
else {
F_62 ( 1 , L_6 ) ;
F_71 ( 1 , & V_5 -> V_72 , sizeof( V_5 -> V_72 ) ) ;
}
if ( V_2 -> V_63 )
F_62 ( 1 , L_7 ) ;
else
F_72 ( L_8 ,
V_2 -> error ) ;
}
void F_73 ( struct V_40 * V_41 , void * V_15 , int error )
{
struct V_1 * V_2 = V_15 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_2 -> error = error ;
if ( error )
F_70 ( V_2 ) ;
F_24 ( & V_30 -> V_73 ) ;
F_74 ( & V_2 -> V_11 , & V_30 -> V_74 ) ;
F_27 ( & V_30 -> V_73 ) ;
F_75 ( & V_30 -> V_75 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
unsigned long V_22 ;
if ( V_2 -> error != - V_76 )
goto V_77;
switch ( V_2 -> V_5 -> V_72 . V_78 ) {
case V_79 :
F_32 ( & V_30 -> V_73 , V_22 ) ;
if ( V_30 -> V_33 != V_34 )
F_77 ( L_9 ,
( unsigned long ) V_30 -> V_41 -> V_52 ) ;
V_30 -> V_33 = V_34 ;
F_33 ( & V_30 -> V_73 , V_22 ) ;
goto V_80;
default:
break;
}
V_77:
if ( ! F_61 ( V_2 -> V_5 ) )
return;
V_80:
F_32 ( & V_30 -> V_81 , V_22 ) ;
F_53 ( V_2 ) ;
F_33 ( & V_30 -> V_81 , V_22 ) ;
}
static void F_78 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
unsigned long V_22 ;
F_32 ( & V_30 -> V_73 , V_22 ) ;
while ( ! F_25 ( & V_30 -> V_74 ) ) {
V_2 = F_26 ( & V_30 -> V_74 ,
struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_33 ( & V_30 -> V_73 , V_22 ) ;
if ( V_2 -> error && V_2 -> V_63 -- > 0 ) {
F_76 ( V_2 ) ;
F_32 ( & V_30 -> V_73 , V_22 ) ;
continue;
}
if ( F_79 ( V_2 ) ) {
F_80 ( V_2 ) ;
F_32 ( & V_30 -> V_73 , V_22 ) ;
continue;
}
F_57 ( V_2 ) ;
F_32 ( & V_30 -> V_73 , V_22 ) ;
}
F_33 ( & V_30 -> V_73 , V_22 ) ;
F_81 ( V_30 -> V_65 ) ;
}
int F_82 ( struct V_29 * V_30 , struct V_40 * V_41 )
{
struct V_68 * V_65 ;
int V_82 , V_20 = - V_14 ;
unsigned int V_83 , V_84 ;
V_83 = F_83 ( & V_85 ) - 1 ;
if ( V_83 > 701 ) {
V_20 = - V_86 ;
goto V_21;
}
V_30 -> V_41 = V_41 ;
V_30 -> V_33 = V_87 ;
F_84 ( & V_30 -> V_81 ) ;
F_84 ( & V_30 -> V_73 ) ;
F_18 ( & V_30 -> V_74 ) ;
F_85 ( & V_30 -> V_64 , 0 ) ;
F_86 ( & V_30 -> V_75 ,
( void (*) ( unsigned long ) ) F_78 ,
( unsigned long ) V_30 ) ;
V_65 = F_87 ( F_63 , & V_30 -> V_81 ) ;
if ( ! V_65 )
goto V_21;
V_30 -> V_65 = V_65 ;
V_84 = F_88 ( V_41 -> V_88 ,
( unsigned int ) ( V_28 / sizeof( struct V_24 ) ) ) ;
F_89 ( V_65 , 1 << 12 ) ;
F_90 ( V_65 , V_84 << 3 ) ;
F_91 ( V_65 , V_84 ) ;
F_92 ( V_89 , V_65 ) ;
F_93 ( V_90 , V_65 ) ;
F_94 ( V_30 ) ;
V_30 -> V_42 = F_95 ( V_91 ) ;
if ( ! V_30 -> V_42 )
goto V_92;
V_65 -> V_69 = V_41 ;
V_30 -> V_42 -> V_43 = V_41 ;
V_30 -> V_42 -> V_93 = & V_94 ;
V_30 -> V_42 -> V_95 = V_65 ;
V_30 -> V_42 -> V_96 = V_97 ;
V_30 -> V_42 -> V_98 = V_83 * V_91 ;
V_82 = snprintf ( V_30 -> V_42 -> V_99 , V_100 , L_10 ) ;
if ( V_83 > 25 ) {
V_82 += snprintf ( V_30 -> V_42 -> V_99 + V_82 ,
V_100 - V_82 , L_11 ,
'a' + ( V_83 / 26 ) - 1 ) ;
V_83 = V_83 % 26 ;
}
snprintf ( V_30 -> V_42 -> V_99 + V_82 , V_100 - V_82 , L_11 ,
'a' + V_83 ) ;
F_96 ( V_30 -> V_42 , V_41 -> V_101 >> 9 ) ;
F_97 ( & V_41 -> V_70 , V_30 -> V_42 ) ;
return 0 ;
V_92:
F_98 ( V_65 ) ;
V_21:
F_56 ( & V_85 ) ;
return V_20 ;
}
void F_99 ( struct V_29 * V_30 )
{
F_100 ( & V_30 -> V_75 ) ;
F_101 ( V_30 -> V_42 ) ;
F_98 ( V_30 -> V_42 -> V_95 ) ;
F_102 ( V_30 -> V_42 ) ;
}
void F_103 ( struct V_29 * V_30 )
{
unsigned long V_22 ;
F_32 ( & V_30 -> V_73 , V_22 ) ;
if ( V_30 -> V_33 == V_34 )
F_77 ( L_12 ,
( unsigned long ) V_30 -> V_41 -> V_52 ) ;
V_30 -> V_33 = V_87 ;
F_33 ( & V_30 -> V_73 , V_22 ) ;
}
static bool T_2 F_104 ( void )
{
if ( ! V_17 || V_17 > 64 )
return false ;
return F_105 () ;
}
static int T_2 F_106 ( void )
{
int V_20 = - V_67 ;
if ( ! F_104 () )
goto V_21;
V_20 = F_107 ( 0 , L_10 ) ;
if ( V_20 < 0 )
goto V_21;
V_97 = V_20 ;
V_20 = F_20 ( V_102 ) ;
if ( V_20 )
goto V_103;
V_104 = F_108 ( L_13 , 16 , 1 , 16 ) ;
if ( ! V_104 ) {
V_20 = - V_14 ;
goto V_103;
}
F_109 ( V_104 , & V_105 ) ;
F_110 ( V_104 , 2 ) ;
V_20 = F_111 () ;
if ( V_20 )
goto V_106;
return V_20 ;
V_106:
F_112 ( V_104 ) ;
V_103:
F_6 () ;
F_113 ( V_97 , L_10 ) ;
V_21:
return V_20 ;
}
static void T_3 F_114 ( void )
{
F_115 () ;
F_112 ( V_104 ) ;
F_6 () ;
F_113 ( V_97 , L_10 ) ;
}
