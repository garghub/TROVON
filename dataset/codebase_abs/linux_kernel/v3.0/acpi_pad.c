static void F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 , V_4 ;
unsigned int V_5 = 0 ;
unsigned int V_6 = 0 ;
int V_7 ;
if ( ! F_2 ( V_8 ) )
return;
if ( V_9 . V_10 < V_11 )
return;
F_3 ( V_11 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
if ( ! ( V_3 & V_12 ) ||
! ( V_3 & V_13 ) )
return;
V_4 >>= V_14 ;
for ( V_7 = 0 ; V_7 < 7 && V_4 ; V_7 ++ , V_4 >>= V_14 ) {
if ( V_4 & V_15 ) {
V_5 = V_7 ;
V_6 = V_4 & V_15 ;
}
}
V_16 = ( V_5 << V_14 ) |
( V_6 - 1 ) ;
#if F_4 ( V_17 )
switch ( V_9 . V_18 ) {
case V_19 :
case V_20 :
if ( ! F_2 ( V_21 ) )
V_22 = 1 ;
if ( ! F_2 ( V_23 ) )
V_24 = 1 ;
break;
default:
V_22 = 1 ;
V_24 = 1 ;
}
#endif
}
static void F_5 ( unsigned int V_25 )
{
struct V_26 * V_27 = F_6 ( V_28 ) ;
T_1 V_29 ;
int V_30 ;
unsigned long V_31 = - 1 ;
unsigned long V_32 ( V_33 ) ;
if ( ! F_7 ( & V_29 , V_34 ) )
return;
F_8 ( & V_35 ) ;
F_9 ( V_29 ) ;
F_10 (cpu, pad_busy_cpus)
F_11 ( V_29 , V_29 , F_12 ( V_30 ) ) ;
F_13 ( V_29 , V_36 , V_29 ) ;
if ( F_14 ( V_29 ) )
F_13 ( V_29 , V_36 , V_27 ) ;
if ( F_14 ( V_29 ) ) {
F_15 ( & V_35 ) ;
return;
}
F_10 (cpu, tmp) {
if ( V_37 [ V_30 ] < V_31 ) {
V_31 = V_37 [ V_30 ] ;
V_33 = V_30 ;
}
}
if ( V_38 [ V_25 ] != - 1 )
F_16 ( V_38 [ V_25 ] , V_27 ) ;
V_38 [ V_25 ] = V_33 ;
F_17 ( V_33 , V_27 ) ;
V_37 [ V_33 ] ++ ;
F_15 ( & V_35 ) ;
F_18 ( V_39 , F_19 ( V_33 ) ) ;
}
static void F_20 ( unsigned int V_25 )
{
struct V_26 * V_27 = F_6 ( V_28 ) ;
F_16 ( V_38 [ V_25 ] , V_27 ) ;
V_38 [ V_25 ] = - 1 ;
}
static int F_21 ( void * V_40 )
{
struct V_41 V_42 = { . V_43 = 1 } ;
int V_44 ;
unsigned int V_25 = ( unsigned long ) V_40 ;
T_2 V_45 = 0 ;
F_22 ( V_39 , V_46 , & V_42 ) ;
while ( ! F_23 () ) {
int V_30 ;
T_2 V_47 ;
F_24 () ;
if ( V_45 + V_48 * V_49 < V_50 ) {
V_45 = V_50 ;
F_5 ( V_25 ) ;
}
V_44 = 0 ;
V_47 = V_50 + V_49 * ( 100 - V_51 ) / 100 ;
while ( ! F_25 () ) {
if ( V_22 && ! V_52 ) {
F_26 ( L_1 ) ;
V_52 = 1 ;
}
if ( V_24 && ! V_53 ) {
int V_7 ;
F_27 (i)
F_28 (
V_54 ,
& V_7 ) ;
V_53 = 1 ;
}
F_29 () ;
V_30 = F_30 () ;
if ( V_53 )
F_28 (
V_55 , & V_30 ) ;
F_31 () ;
F_32 ( ( void * ) & F_33 () -> V_56 , 0 , 0 ) ;
F_34 () ;
if ( ! F_25 () )
F_35 ( V_16 , 1 ) ;
F_36 () ;
if ( V_53 )
F_28 (
V_57 , & V_30 ) ;
F_37 () ;
if ( V_50 > V_47 ) {
V_44 = 1 ;
break;
}
}
if ( V_44 )
F_38 ( V_49 * V_51 / 100 ) ;
}
F_20 ( V_25 ) ;
return 0 ;
}
static int F_39 ( void )
{
int V_58 = - V_59 ;
V_60 [ V_61 ] = F_40 ( F_21 ,
( void * ) ( unsigned long ) V_61 ,
L_2 , V_61 ) ;
V_58 = F_41 ( V_60 [ V_61 ] ) ? F_42 ( V_60 [ V_61 ] ) : 0 ;
if ( ! V_58 )
V_61 ++ ;
else
V_60 [ V_61 ] = NULL ;
return V_58 ;
}
static void F_43 ( void )
{
if ( V_61 > 0 ) {
V_61 -- ;
F_44 ( V_60 [ V_61 ] ) ;
V_60 [ V_61 ] = NULL ;
}
}
static void F_45 ( unsigned int V_62 )
{
if ( V_62 > V_61 ) {
while ( V_61 < V_62 ) {
if ( F_39 () )
return;
}
} else if ( V_62 < V_61 ) {
while ( V_61 > V_62 )
F_43 () ;
}
}
static void F_46 ( unsigned int V_63 )
{
F_47 () ;
V_63 = F_48 (unsigned int, num_cpus, num_online_cpus()) ;
F_45 ( V_63 ) ;
F_49 () ;
}
static T_3 F_50 ( void )
{
return V_61 ;
}
static T_4 F_51 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_52 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
if ( V_62 < 1 || V_62 >= 100 )
return - V_70 ;
F_8 ( & V_35 ) ;
V_48 = V_62 ;
F_15 ( & V_35 ) ;
return V_69 ;
}
static T_4 F_53 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
return F_54 ( V_68 , V_71 , L_3 , V_48 ) ;
}
static T_4 F_55 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_52 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
if ( V_62 < 1 || V_62 >= 100 )
return - V_70 ;
F_8 ( & V_35 ) ;
V_51 = V_62 ;
F_15 ( & V_35 ) ;
return V_69 ;
}
static T_4 F_56 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
return F_54 ( V_68 , V_71 , L_3 , V_51 ) ;
}
static T_4 F_57 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_52 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
F_8 ( & V_35 ) ;
F_46 ( V_62 ) ;
F_15 ( & V_35 ) ;
return V_69 ;
}
static T_4 F_58 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
int V_72 = 0 ;
V_72 = F_59 ( V_68 , V_71 - 2 , F_6 ( V_28 ) ) ;
V_68 [ V_72 ++ ] = '\n' ;
V_68 [ V_72 ] = '\0' ;
return V_72 ;
}
static int F_60 ( struct V_73 * V_64 )
{
int V_74 ;
V_74 = F_61 ( & V_64 -> V_65 , & V_75 ) ;
if ( V_74 )
return - V_76 ;
V_74 = F_61 ( & V_64 -> V_65 , & V_77 ) ;
if ( V_74 ) {
F_62 ( & V_64 -> V_65 , & V_75 ) ;
return - V_76 ;
}
V_74 = F_61 ( & V_64 -> V_65 , & V_78 ) ;
if ( V_74 ) {
F_62 ( & V_64 -> V_65 , & V_75 ) ;
F_62 ( & V_64 -> V_65 , & V_77 ) ;
return - V_76 ;
}
return 0 ;
}
static void F_63 ( struct V_73 * V_64 )
{
F_62 ( & V_64 -> V_65 , & V_75 ) ;
F_62 ( & V_64 -> V_65 , & V_77 ) ;
F_62 ( & V_64 -> V_65 , & V_78 ) ;
}
static int F_64 ( T_6 V_79 )
{
struct V_80 V_81 = { V_82 , NULL } ;
union V_83 * V_84 ;
int V_62 = - 1 ;
if ( F_65 ( F_66 ( V_79 , L_4 , NULL , & V_81 ) ) )
return V_62 ;
if ( ! V_81 . V_85 || ! V_81 . V_86 )
return V_62 ;
V_84 = V_81 . V_86 ;
if ( V_84 -> type == V_87 &&
V_84 -> V_84 . V_69 == 2 &&
V_84 -> V_84 . V_88 [ 0 ] . integer . V_89 == 1 )
V_62 = V_84 -> V_84 . V_88 [ 1 ] . integer . V_89 ;
F_67 ( V_81 . V_86 ) ;
return V_62 ;
}
static void F_68 ( T_6 V_79 , int V_90 ,
T_3 V_91 )
{
union V_83 V_92 [ 3 ] = {
{ . type = V_93 ,} ,
{ . type = V_93 ,} ,
{ . type = V_94 ,} ,
} ;
struct V_95 V_96 = { 3 , V_92 } ;
V_92 [ 0 ] . integer . V_89 = V_97 ;
V_92 [ 1 ] . integer . V_89 = V_90 ;
V_92 [ 2 ] . V_81 . V_85 = 4 ;
V_92 [ 2 ] . V_81 . V_86 = ( void * ) & V_91 ;
F_66 ( V_79 , L_5 , & V_96 , NULL ) ;
}
static void F_69 ( T_6 V_79 )
{
int V_63 ;
T_3 V_91 ;
F_8 ( & V_35 ) ;
V_63 = F_64 ( V_79 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_35 ) ;
return;
}
F_46 ( V_63 ) ;
V_91 = F_50 () ;
F_68 ( V_79 , 0 , V_91 ) ;
F_15 ( & V_35 ) ;
}
static void F_70 ( T_6 V_79 , T_7 V_98 ,
void * V_40 )
{
struct V_73 * V_64 = V_40 ;
switch ( V_98 ) {
case V_97 :
F_69 ( V_79 ) ;
F_71 ( V_64 , V_98 , 0 ) ;
F_72 ( V_64 -> V_99 . V_100 ,
F_73 ( & V_64 -> V_65 ) , V_98 , 0 ) ;
break;
default:
F_74 ( V_101 L_6 , V_98 ) ;
break;
}
}
static int F_75 ( struct V_73 * V_64 )
{
T_8 V_102 ;
strcpy ( F_76 ( V_64 ) , V_103 ) ;
strcpy ( F_77 ( V_64 ) , V_104 ) ;
if ( F_60 ( V_64 ) )
return - V_76 ;
V_102 = F_78 ( V_64 -> V_79 ,
V_105 , F_70 , V_64 ) ;
if ( F_65 ( V_102 ) ) {
F_63 ( V_64 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_79 ( struct V_73 * V_64 ,
int type )
{
F_8 ( & V_35 ) ;
F_46 ( 0 ) ;
F_15 ( & V_35 ) ;
F_80 ( V_64 -> V_79 ,
V_105 , F_70 ) ;
F_63 ( V_64 ) ;
return 0 ;
}
static int T_9 F_81 ( void )
{
F_1 () ;
if ( V_16 == 0 )
return - V_70 ;
return F_82 ( & V_106 ) ;
}
static void T_10 F_83 ( void )
{
F_84 ( & V_106 ) ;
}
