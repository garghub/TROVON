static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( ( unsigned long ) V_2 -> V_5 ) ;
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( void )
{
struct V_7 * V_8 , * V_9 ;
struct V_1 * V_2 ;
F_6 ( & V_10 ) ;
F_7 (iter, safe, &inactive_requests) {
V_2 = F_8 ( V_8 , struct V_1 , V_11 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_1 ( V_2 ) ;
}
F_10 ( & V_10 ) ;
F_11 ( V_12 ) ;
}
static int F_12 ( void )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_13 ( sizeof( * V_4 ) + sizeof( * V_2 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_2 = ( void * ) V_4 -> V_15 ;
V_2 -> V_5 = ( void * ) F_14 ( V_16 ) ;
if ( ! V_2 -> V_5 )
goto free;
V_2 -> V_6 = F_15 ( V_17 , sizeof( V_2 -> V_6 [ 0 ] ) ,
V_13 ) ;
if ( ! V_2 -> V_6 )
goto free;
F_16 ( & V_2 -> V_11 ) ;
F_6 ( & V_10 ) ;
F_17 ( & V_2 -> V_11 , & V_18 ) ;
F_10 ( & V_10 ) ;
return 0 ;
free:
F_1 ( V_2 ) ;
return - V_14 ;
}
static int F_18 ( unsigned int V_19 )
{
int V_20 = 0 ;
V_12 = F_19 ( F_20 ( V_19 / 8 , 1U ) , 0 ) ;
if ( ! V_12 )
return - V_14 ;
while ( V_19 -- && ! V_20 )
V_20 = F_12 () ;
return V_20 ;
}
static struct V_1 * F_21 ( void )
{
struct V_1 * V_2 = NULL ;
F_6 ( & V_10 ) ;
if ( F_22 ( & V_18 ) )
goto V_21;
V_2 = F_23 ( & V_18 , struct V_1 , V_11 ) ;
F_9 ( & V_2 -> V_11 ) ;
V_21:
F_10 ( & V_10 ) ;
return V_2 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
struct V_23 * V_23 ;
T_1 V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ ) {
V_23 = & V_2 -> V_5 -> V_23 [ V_25 ] ;
V_24 = V_23 -> V_26 ;
if ( ( V_23 -> V_22 & V_27 ) && V_24 &&
F_25 ( V_24 , V_28 ) )
F_26 ( F_27 ( V_24 ) , V_12 ) ;
}
F_28 ( & V_10 , V_22 ) ;
F_17 ( & V_2 -> V_11 , & V_18 ) ;
F_29 ( & V_10 , V_22 ) ;
}
static bool F_30 ( struct V_29 * V_30 , struct V_6 * V_31 )
{
return F_31 ( V_31 ) != V_32 || V_30 -> V_33 != V_34 ;
}
static inline struct V_24 * F_32 ( void )
{
struct V_35 * V_35 = F_33 ( V_12 , V_36 ) ;
return V_35 ? F_34 ( V_35 ) : NULL ;
}
static inline unsigned long F_35 ( struct V_24 * V_24 )
{
unsigned long V_37 = ( unsigned long ) V_24 ;
unsigned long V_38 = F_36 ( V_37 , V_28 ) - V_37 ;
return ( V_38 / sizeof( * V_24 ) ) * V_28 ;
}
struct V_24 * F_37 ( struct V_1 * V_2 , unsigned int V_38 )
{
struct V_24 * V_24 ;
if ( F_35 ( V_2 -> V_39 ) >= V_38 )
return V_2 -> V_39 ;
V_24 = F_32 () ;
if ( V_24 )
memset ( V_24 , 0 , V_28 ) ;
return V_24 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_40 * V_41 = V_30 -> V_42 -> V_43 ;
int V_44 = V_2 -> V_5 -> V_6 . V_45 ;
struct V_23 * V_23 = & V_2 -> V_5 -> V_23 [ V_44 ] ;
struct V_6 * V_31 = V_2 -> V_6 [ V_44 ] ;
struct V_46 V_8 ;
struct V_24 * V_24 ;
struct V_47 V_48 ;
V_24 = F_37 ( V_2 , F_39 ( V_31 ) ) ;
if ( ! V_24 )
return - V_14 ;
V_23 -> V_49 = V_50 ;
V_2 -> V_5 -> V_6 . V_45 ++ ;
V_23 -> V_51 = V_41 -> V_52 + ( ( T_1 ) F_40 ( V_31 ) << 9 ) ;
V_23 -> V_53 = ( F_31 ( V_31 ) == V_54 ) ? V_55 : V_56 ;
V_23 -> V_22 |= V_27 ;
V_23 -> V_26 = ( T_1 ) V_24 ;
F_41 (bv, req, iter) {
F_42 ( V_48 . V_57 ) ;
V_23 -> V_58 += V_48 . V_59 >> 12 ;
V_24 -> V_26 = ( T_1 ) F_34 ( V_48 . V_60 ) ;
V_24 ++ ;
}
V_2 -> V_39 = V_24 ;
return 0 ;
}
static inline void F_43 ( struct V_1 * V_2 ,
struct V_6 * V_31 )
{
V_2 -> V_6 [ V_2 -> V_5 -> V_6 . V_45 ] = V_31 ;
}
static inline void F_44 ( struct V_29 * V_30 ,
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
V_2 -> error = V_64 ;
V_2 -> V_39 = ( void * ) & V_5 -> V_23 [ V_17 ] ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ )
F_46 ( V_2 -> V_6 [ V_25 ] , false ) ;
F_47 ( & V_30 -> V_65 ) ;
F_24 ( V_2 ) ;
F_48 ( V_30 -> V_66 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
T_2 * error ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 && V_2 -> V_6 [ V_25 ] ; V_25 ++ ) {
error = F_50 ( V_2 -> V_6 [ V_25 ] ) ;
* error = V_2 -> error ;
F_51 ( V_2 -> V_6 [ V_25 ] ) ;
}
F_47 ( & V_30 -> V_65 ) ;
F_24 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
F_53 ( & V_30 -> V_65 ) ;
if ( F_54 ( V_2 -> V_5 ) ) {
F_55 ( 5 , L_1 ) ;
F_45 ( V_2 ) ;
}
}
static T_2 F_56 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_40 * V_41 = V_68 -> V_71 -> V_72 ;
struct V_29 * V_30 = F_57 ( & V_41 -> V_73 ) ;
struct V_74 * V_75 = V_68 -> V_76 ;
struct V_6 * V_31 = V_70 -> V_66 ;
struct V_1 * V_2 ;
F_58 ( & V_75 -> V_77 ) ;
if ( ! F_30 ( V_30 , V_31 ) ) {
F_59 ( & V_75 -> V_77 ) ;
return V_78 ;
}
V_2 = V_75 -> V_2 ;
if ( ! V_2 ) {
V_2 = F_21 () ;
if ( ! V_2 ) {
F_55 ( 5 , L_2 ) ;
F_59 ( & V_75 -> V_77 ) ;
return V_78 ;
}
F_44 ( V_30 , V_2 ) ;
V_75 -> V_2 = V_2 ;
}
F_43 ( V_2 , V_31 ) ;
if ( F_38 ( V_2 ) ) {
F_55 ( 5 , L_3 ) ;
F_43 ( V_2 , NULL ) ;
if ( V_2 -> V_5 -> V_6 . V_45 )
F_52 ( V_2 ) ;
V_75 -> V_2 = NULL ;
F_59 ( & V_75 -> V_77 ) ;
return V_78 ;
}
F_60 ( V_31 ) ;
if ( V_70 -> V_79 || V_2 -> V_5 -> V_6 . V_45 == V_17 ) {
F_52 ( V_2 ) ;
V_75 -> V_2 = NULL ;
}
F_59 ( & V_75 -> V_77 ) ;
return V_64 ;
}
static int F_61 ( struct V_67 * V_68 , void * V_15 ,
unsigned int V_80 )
{
struct V_74 * V_70 = F_13 ( sizeof( * V_70 ) , V_13 ) ;
if ( ! V_70 )
return - V_14 ;
F_62 ( & V_70 -> V_77 ) ;
V_68 -> V_76 = V_70 ;
return 0 ;
}
static void F_63 ( struct V_67 * V_68 , unsigned int V_80 )
{
struct V_74 * V_70 = V_68 -> V_76 ;
F_42 ( V_70 -> V_2 ) ;
F_4 ( V_68 -> V_76 ) ;
V_68 -> V_76 = NULL ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> error == V_81 )
F_55 ( 1 , L_4 ) ;
else {
F_55 ( 1 , L_5 ) ;
F_65 ( 1 , & V_5 -> V_82 , sizeof( V_5 -> V_82 ) ) ;
}
if ( V_2 -> V_63 )
F_55 ( 1 , L_6 ) ;
else
F_66 ( L_7 ,
V_2 -> error ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
unsigned long V_22 ;
if ( V_2 -> error != V_83 )
goto V_84;
switch ( V_2 -> V_5 -> V_82 . V_85 ) {
case V_86 :
F_28 ( & V_30 -> V_77 , V_22 ) ;
if ( V_30 -> V_33 != V_34 )
F_68 ( L_8 ,
( unsigned long ) V_30 -> V_41 -> V_52 ) ;
V_30 -> V_33 = V_34 ;
F_29 ( & V_30 -> V_77 , V_22 ) ;
goto V_87;
default:
break;
}
V_84:
if ( ! F_54 ( V_2 -> V_5 ) )
return;
V_87:
F_45 ( V_2 ) ;
}
void F_69 ( struct V_40 * V_41 , void * V_15 , T_2 error )
{
struct V_1 * V_2 = V_15 ;
V_2 -> error = error ;
if ( error ) {
F_64 ( V_2 ) ;
if ( V_2 -> V_63 -- > 0 ) {
F_67 ( V_2 ) ;
return;
}
}
F_49 ( V_2 ) ;
}
static void F_70 ( struct V_6 * V_31 )
{
T_2 * error = F_50 ( V_31 ) ;
F_71 ( V_31 , * error ) ;
}
int F_72 ( struct V_29 * V_30 , struct V_40 * V_41 )
{
unsigned int V_88 , V_89 ;
struct V_90 * V_66 ;
int V_91 , V_20 ;
V_88 = F_73 ( & V_92 ) - 1 ;
if ( V_88 > 701 ) {
V_20 = - V_93 ;
goto V_21;
}
V_30 -> V_41 = V_41 ;
V_30 -> V_33 = V_94 ;
F_62 ( & V_30 -> V_77 ) ;
F_74 ( & V_30 -> V_65 , 0 ) ;
V_30 -> V_95 . V_96 = & V_97 ;
V_30 -> V_95 . V_98 = sizeof( T_2 ) ;
V_30 -> V_95 . V_99 = V_100 ;
V_30 -> V_95 . V_101 = V_17 * V_100 ;
V_30 -> V_95 . V_22 = V_102 ;
V_20 = F_75 ( & V_30 -> V_95 ) ;
if ( V_20 )
goto V_21;
V_66 = F_76 ( & V_30 -> V_95 ) ;
if ( F_77 ( V_66 ) ) {
V_20 = F_78 ( V_66 ) ;
goto V_103;
}
V_30 -> V_66 = V_66 ;
V_89 = F_79 ( V_41 -> V_104 ,
( unsigned int ) ( V_28 / sizeof( struct V_24 ) ) ) ;
F_80 ( V_66 , 1 << 12 ) ;
F_81 ( V_66 , V_89 << 3 ) ;
F_82 ( V_66 , V_89 ) ;
F_83 ( V_105 , V_66 ) ;
F_84 ( V_106 , V_66 ) ;
V_30 -> V_42 = F_85 ( V_107 ) ;
if ( ! V_30 -> V_42 ) {
V_20 = - V_14 ;
goto V_108;
}
V_66 -> V_72 = V_41 ;
V_30 -> V_42 -> V_43 = V_41 ;
V_30 -> V_42 -> V_109 = & V_110 ;
V_30 -> V_42 -> V_71 = V_66 ;
V_30 -> V_42 -> V_111 = V_112 ;
V_30 -> V_42 -> V_113 = V_88 * V_107 ;
V_91 = snprintf ( V_30 -> V_42 -> V_114 , V_115 , L_9 ) ;
if ( V_88 > 25 ) {
V_91 += snprintf ( V_30 -> V_42 -> V_114 + V_91 ,
V_115 - V_91 , L_10 ,
'a' + ( V_88 / 26 ) - 1 ) ;
V_88 = V_88 % 26 ;
}
snprintf ( V_30 -> V_42 -> V_114 + V_91 , V_115 - V_91 , L_10 ,
'a' + V_88 ) ;
F_86 ( V_30 -> V_42 , V_41 -> V_116 >> 9 ) ;
F_87 ( & V_41 -> V_73 , V_30 -> V_42 ) ;
return 0 ;
V_108:
F_88 ( V_66 ) ;
V_103:
F_89 ( & V_30 -> V_95 ) ;
V_21:
F_47 ( & V_92 ) ;
return V_20 ;
}
void F_90 ( struct V_29 * V_30 )
{
F_91 ( V_30 -> V_42 ) ;
F_88 ( V_30 -> V_42 -> V_71 ) ;
F_89 ( & V_30 -> V_95 ) ;
F_92 ( V_30 -> V_42 ) ;
}
void F_93 ( struct V_29 * V_30 )
{
unsigned long V_22 ;
F_28 ( & V_30 -> V_77 , V_22 ) ;
if ( V_30 -> V_33 == V_34 )
F_68 ( L_11 ,
( unsigned long ) V_30 -> V_41 -> V_52 ) ;
V_30 -> V_33 = V_94 ;
F_29 ( & V_30 -> V_77 , V_22 ) ;
}
static bool T_3 F_94 ( void )
{
if ( ! V_17 || V_17 > 64 )
return false ;
return true ;
}
static int T_3 F_95 ( void )
{
int V_20 = - V_117 ;
if ( ! F_94 () )
goto V_21;
V_20 = F_96 ( 0 , L_9 ) ;
if ( V_20 < 0 )
goto V_21;
V_112 = V_20 ;
V_20 = F_18 ( V_100 ) ;
if ( V_20 )
goto V_118;
V_119 = F_97 ( L_12 , 16 , 1 , 16 ) ;
if ( ! V_119 ) {
V_20 = - V_14 ;
goto V_118;
}
F_98 ( V_119 , & V_120 ) ;
F_99 ( V_119 , 2 ) ;
V_20 = F_100 () ;
if ( V_20 )
goto V_121;
return V_20 ;
V_121:
F_101 ( V_119 ) ;
V_118:
F_5 () ;
F_102 ( V_112 , L_9 ) ;
V_21:
return V_20 ;
}
static void T_4 F_103 ( void )
{
F_104 () ;
F_101 ( V_119 ) ;
F_5 () ;
F_102 ( V_112 , L_9 ) ;
}
