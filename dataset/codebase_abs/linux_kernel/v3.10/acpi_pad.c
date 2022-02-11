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
V_58 = F_41 ( V_60 [ V_61 ] ) ;
if ( ! V_58 )
V_61 ++ ;
else
V_60 [ V_61 ] = NULL ;
return V_58 ;
}
static void F_42 ( void )
{
if ( V_61 > 0 ) {
V_61 -- ;
F_43 ( V_60 [ V_61 ] ) ;
V_60 [ V_61 ] = NULL ;
}
}
static void F_44 ( unsigned int V_62 )
{
if ( V_62 > V_61 ) {
while ( V_61 < V_62 ) {
if ( F_39 () )
return;
}
} else if ( V_62 < V_61 ) {
while ( V_61 > V_62 )
F_42 () ;
}
}
static void F_45 ( unsigned int V_63 )
{
F_46 () ;
V_63 = F_47 (unsigned int, num_cpus, num_online_cpus()) ;
F_44 ( V_63 ) ;
F_48 () ;
}
static T_3 F_49 ( void )
{
return V_61 ;
}
static T_4 F_50 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_51 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
if ( V_62 < 1 || V_62 >= 100 )
return - V_70 ;
F_8 ( & V_71 ) ;
V_48 = V_62 ;
F_15 ( & V_71 ) ;
return V_69 ;
}
static T_4 F_52 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
return F_53 ( V_68 , V_72 , L_3 , V_48 ) ;
}
static T_4 F_54 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_51 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
if ( V_62 < 1 || V_62 >= 100 )
return - V_70 ;
F_8 ( & V_71 ) ;
V_51 = V_62 ;
F_15 ( & V_71 ) ;
return V_69 ;
}
static T_4 F_55 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
return F_53 ( V_68 , V_72 , L_3 , V_51 ) ;
}
static T_4 F_56 ( struct V_64 * V_65 ,
struct V_66 * V_67 , const char * V_68 , T_5 V_69 )
{
unsigned long V_62 ;
if ( F_51 ( V_68 , 0 , & V_62 ) )
return - V_70 ;
F_8 ( & V_71 ) ;
F_45 ( V_62 ) ;
F_15 ( & V_71 ) ;
return V_69 ;
}
static T_4 F_57 ( struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
int V_73 = 0 ;
V_73 = F_58 ( V_68 , V_72 - 2 , F_6 ( V_28 ) ) ;
V_68 [ V_73 ++ ] = '\n' ;
V_68 [ V_73 ] = '\0' ;
return V_73 ;
}
static int F_59 ( struct V_74 * V_64 )
{
int V_75 ;
V_75 = F_60 ( & V_64 -> V_65 , & V_76 ) ;
if ( V_75 )
return - V_77 ;
V_75 = F_60 ( & V_64 -> V_65 , & V_78 ) ;
if ( V_75 ) {
F_61 ( & V_64 -> V_65 , & V_76 ) ;
return - V_77 ;
}
V_75 = F_60 ( & V_64 -> V_65 , & V_79 ) ;
if ( V_75 ) {
F_61 ( & V_64 -> V_65 , & V_76 ) ;
F_61 ( & V_64 -> V_65 , & V_78 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_62 ( struct V_74 * V_64 )
{
F_61 ( & V_64 -> V_65 , & V_76 ) ;
F_61 ( & V_64 -> V_65 , & V_78 ) ;
F_61 ( & V_64 -> V_65 , & V_79 ) ;
}
static int F_63 ( T_6 V_80 )
{
struct V_81 V_82 = { V_83 , NULL } ;
union V_84 * V_85 ;
int V_62 = - 1 ;
if ( F_64 ( F_65 ( V_80 , L_4 , NULL , & V_82 ) ) )
return V_62 ;
if ( ! V_82 . V_86 || ! V_82 . V_87 )
return V_62 ;
V_85 = V_82 . V_87 ;
if ( V_85 -> type == V_88 &&
V_85 -> V_85 . V_69 == 2 &&
V_85 -> V_85 . V_89 [ 0 ] . integer . V_90 == 1 )
V_62 = V_85 -> V_85 . V_89 [ 1 ] . integer . V_90 ;
F_66 ( V_82 . V_87 ) ;
return V_62 ;
}
static void F_67 ( T_6 V_80 , int V_91 ,
T_3 V_92 )
{
union V_84 V_93 [ 3 ] = {
{ . type = V_94 ,} ,
{ . type = V_94 ,} ,
{ . type = V_95 ,} ,
} ;
struct V_96 V_97 = { 3 , V_93 } ;
V_93 [ 0 ] . integer . V_90 = V_98 ;
V_93 [ 1 ] . integer . V_90 = V_91 ;
V_93 [ 2 ] . V_82 . V_86 = 4 ;
V_93 [ 2 ] . V_82 . V_87 = ( void * ) & V_92 ;
F_65 ( V_80 , L_5 , & V_97 , NULL ) ;
}
static void F_68 ( T_6 V_80 )
{
int V_63 ;
T_3 V_92 ;
F_8 ( & V_71 ) ;
V_63 = F_63 ( V_80 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_71 ) ;
return;
}
F_45 ( V_63 ) ;
V_92 = F_49 () ;
F_67 ( V_80 , 0 , V_92 ) ;
F_15 ( & V_71 ) ;
}
static void F_69 ( T_6 V_80 , T_7 V_99 ,
void * V_40 )
{
struct V_74 * V_64 = V_40 ;
switch ( V_99 ) {
case V_98 :
F_68 ( V_80 ) ;
F_70 ( V_64 , V_99 , 0 ) ;
F_71 ( V_64 -> V_100 . V_101 ,
F_72 ( & V_64 -> V_65 ) , V_99 , 0 ) ;
break;
default:
F_73 ( L_6 , V_99 ) ;
break;
}
}
static int F_74 ( struct V_74 * V_64 )
{
T_8 V_102 ;
strcpy ( F_75 ( V_64 ) , V_103 ) ;
strcpy ( F_76 ( V_64 ) , V_104 ) ;
if ( F_59 ( V_64 ) )
return - V_77 ;
V_102 = F_77 ( V_64 -> V_80 ,
V_105 , F_69 , V_64 ) ;
if ( F_64 ( V_102 ) ) {
F_62 ( V_64 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_78 ( struct V_74 * V_64 )
{
F_8 ( & V_71 ) ;
F_45 ( 0 ) ;
F_15 ( & V_71 ) ;
F_79 ( V_64 -> V_80 ,
V_105 , F_69 ) ;
F_62 ( V_64 ) ;
return 0 ;
}
static int T_9 F_80 ( void )
{
F_1 () ;
if ( V_16 == 0 )
return - V_70 ;
return F_81 ( & V_106 ) ;
}
static void T_10 F_82 ( void )
{
F_83 ( & V_106 ) ;
}
