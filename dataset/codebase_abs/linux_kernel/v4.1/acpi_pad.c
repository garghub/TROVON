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
break;
default:
V_22 = 1 ;
}
#endif
}
static void F_5 ( unsigned int V_23 )
{
struct V_24 * V_25 = F_6 ( V_26 ) ;
T_1 V_27 ;
int V_28 ;
unsigned long V_29 = - 1 ;
unsigned long V_30 ( V_31 ) ;
if ( ! F_7 ( & V_27 , V_32 ) )
return;
F_8 ( & V_33 ) ;
F_9 ( V_27 ) ;
F_10 (cpu, pad_busy_cpus)
F_11 ( V_27 , V_27 , F_12 ( V_28 ) ) ;
F_13 ( V_27 , V_34 , V_27 ) ;
if ( F_14 ( V_27 ) )
F_13 ( V_27 , V_34 , V_25 ) ;
if ( F_14 ( V_27 ) ) {
F_15 ( & V_33 ) ;
return;
}
F_10 (cpu, tmp) {
if ( V_35 [ V_28 ] < V_29 ) {
V_29 = V_35 [ V_28 ] ;
V_31 = V_28 ;
}
}
if ( V_36 [ V_23 ] != - 1 )
F_16 ( V_36 [ V_23 ] , V_25 ) ;
V_36 [ V_23 ] = V_31 ;
F_17 ( V_31 , V_25 ) ;
V_35 [ V_31 ] ++ ;
F_15 ( & V_33 ) ;
F_18 ( V_37 , F_19 ( V_31 ) ) ;
}
static void F_20 ( unsigned int V_23 )
{
struct V_24 * V_25 = F_6 ( V_26 ) ;
F_16 ( V_36 [ V_23 ] , V_25 ) ;
V_36 [ V_23 ] = - 1 ;
}
static int F_21 ( void * V_38 )
{
struct V_39 V_40 = { . V_41 = 1 } ;
int V_42 ;
unsigned int V_23 = ( unsigned long ) V_38 ;
T_2 V_43 = 0 ;
F_22 ( V_37 , V_44 , & V_40 ) ;
while ( ! F_23 () ) {
unsigned long V_45 ;
F_24 () ;
V_45 = V_43 + V_46 * V_47 ;
if ( F_25 ( V_45 , V_48 ) ) {
V_43 = V_48 ;
F_5 ( V_23 ) ;
}
V_42 = 0 ;
V_45 = V_48 + V_47 * ( 100 - V_49 ) / 100 ;
while ( ! F_26 () ) {
if ( V_22 && ! V_50 ) {
F_27 ( L_1 ) ;
V_50 = 1 ;
}
F_28 () ;
F_29 () ;
F_30 () ;
F_31 () ;
F_32 ( V_16 , 1 ) ;
F_33 () ;
F_34 () ;
F_35 () ;
if ( F_25 ( V_45 , V_48 ) ) {
V_42 = 1 ;
break;
}
}
if ( F_36 ( V_42 ) )
F_37 ( V_47 * V_49 / 100 ) ;
if ( F_36 ( F_26 () ) )
F_38 () ;
}
F_20 ( V_23 ) ;
return 0 ;
}
static int F_39 ( void )
{
int V_51 ;
V_52 [ V_53 ] = F_40 ( F_21 ,
( void * ) ( unsigned long ) V_53 ,
L_2 , V_53 ) ;
if ( F_41 ( V_52 [ V_53 ] ) ) {
V_51 = F_42 ( V_52 [ V_53 ] ) ;
V_52 [ V_53 ] = NULL ;
} else {
V_51 = 0 ;
V_53 ++ ;
}
return V_51 ;
}
static void F_43 ( void )
{
if ( V_53 > 0 ) {
V_53 -- ;
F_44 ( V_52 [ V_53 ] ) ;
V_52 [ V_53 ] = NULL ;
}
}
static void F_45 ( unsigned int V_54 )
{
if ( V_54 > V_53 ) {
while ( V_53 < V_54 ) {
if ( F_39 () )
return;
}
} else if ( V_54 < V_53 ) {
while ( V_53 > V_54 )
F_43 () ;
}
}
static void F_46 ( unsigned int V_55 )
{
F_47 () ;
V_55 = F_48 (unsigned int, num_cpus, num_online_cpus()) ;
F_45 ( V_55 ) ;
F_49 () ;
}
static T_3 F_50 ( void )
{
return V_53 ;
}
static T_4 F_51 ( struct V_56 * V_57 ,
struct V_58 * V_59 , const char * V_60 , T_5 V_61 )
{
unsigned long V_54 ;
if ( F_52 ( V_60 , 0 , & V_54 ) )
return - V_62 ;
if ( V_54 < 1 || V_54 >= 100 )
return - V_62 ;
F_8 ( & V_63 ) ;
V_46 = V_54 ;
F_15 ( & V_63 ) ;
return V_61 ;
}
static T_4 F_53 ( struct V_56 * V_57 ,
struct V_58 * V_59 , char * V_60 )
{
return F_54 ( V_60 , V_64 , L_3 , V_46 ) ;
}
static T_4 F_55 ( struct V_56 * V_57 ,
struct V_58 * V_59 , const char * V_60 , T_5 V_61 )
{
unsigned long V_54 ;
if ( F_52 ( V_60 , 0 , & V_54 ) )
return - V_62 ;
if ( V_54 < 1 || V_54 >= 100 )
return - V_62 ;
F_8 ( & V_63 ) ;
V_49 = V_54 ;
F_15 ( & V_63 ) ;
return V_61 ;
}
static T_4 F_56 ( struct V_56 * V_57 ,
struct V_58 * V_59 , char * V_60 )
{
return F_54 ( V_60 , V_64 , L_3 , V_49 ) ;
}
static T_4 F_57 ( struct V_56 * V_57 ,
struct V_58 * V_59 , const char * V_60 , T_5 V_61 )
{
unsigned long V_54 ;
if ( F_52 ( V_60 , 0 , & V_54 ) )
return - V_62 ;
F_8 ( & V_63 ) ;
F_46 ( V_54 ) ;
F_15 ( & V_63 ) ;
return V_61 ;
}
static T_4 F_58 ( struct V_56 * V_57 ,
struct V_58 * V_59 , char * V_60 )
{
return F_59 ( false , V_60 ,
F_6 ( V_26 ) ) ;
}
static int F_60 ( struct V_65 * V_56 )
{
int V_66 ;
V_66 = F_61 ( & V_56 -> V_57 , & V_67 ) ;
if ( V_66 )
return - V_68 ;
V_66 = F_61 ( & V_56 -> V_57 , & V_69 ) ;
if ( V_66 ) {
F_62 ( & V_56 -> V_57 , & V_67 ) ;
return - V_68 ;
}
V_66 = F_61 ( & V_56 -> V_57 , & V_70 ) ;
if ( V_66 ) {
F_62 ( & V_56 -> V_57 , & V_67 ) ;
F_62 ( & V_56 -> V_57 , & V_69 ) ;
return - V_68 ;
}
return 0 ;
}
static void F_63 ( struct V_65 * V_56 )
{
F_62 ( & V_56 -> V_57 , & V_67 ) ;
F_62 ( & V_56 -> V_57 , & V_69 ) ;
F_62 ( & V_56 -> V_57 , & V_70 ) ;
}
static int F_64 ( T_6 V_71 )
{
struct V_72 V_73 = { V_74 , NULL } ;
union V_75 * V_76 ;
int V_54 = - 1 ;
if ( F_65 ( F_66 ( V_71 , L_4 , NULL , & V_73 ) ) )
return V_54 ;
if ( ! V_73 . V_77 || ! V_73 . V_78 )
return V_54 ;
V_76 = V_73 . V_78 ;
if ( V_76 -> type == V_79 &&
V_76 -> V_76 . V_61 == 2 &&
V_76 -> V_76 . V_80 [ 0 ] . integer . V_81 == 1 )
V_54 = V_76 -> V_76 . V_80 [ 1 ] . integer . V_81 ;
F_67 ( V_73 . V_78 ) ;
return V_54 ;
}
static void F_68 ( T_6 V_71 )
{
int V_55 ;
T_3 V_82 ;
struct V_72 V_40 = {
. V_77 = 4 ,
. V_78 = ( void * ) & V_82 ,
} ;
F_8 ( & V_63 ) ;
V_55 = F_64 ( V_71 ) ;
if ( V_55 < 0 ) {
F_15 ( & V_63 ) ;
return;
}
F_46 ( V_55 ) ;
V_82 = F_50 () ;
F_69 ( V_71 , V_83 , 0 , & V_40 ) ;
F_15 ( & V_63 ) ;
}
static void F_70 ( T_6 V_71 , T_7 V_84 ,
void * V_38 )
{
struct V_65 * V_56 = V_38 ;
switch ( V_84 ) {
case V_83 :
F_68 ( V_71 ) ;
F_71 ( V_56 -> V_85 . V_86 ,
F_72 ( & V_56 -> V_57 ) , V_84 , 0 ) ;
break;
default:
F_73 ( L_5 , V_84 ) ;
break;
}
}
static int F_74 ( struct V_65 * V_56 )
{
T_8 V_87 ;
strcpy ( F_75 ( V_56 ) , V_88 ) ;
strcpy ( F_76 ( V_56 ) , V_89 ) ;
if ( F_60 ( V_56 ) )
return - V_68 ;
V_87 = F_77 ( V_56 -> V_71 ,
V_90 , F_70 , V_56 ) ;
if ( F_65 ( V_87 ) ) {
F_63 ( V_56 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_78 ( struct V_65 * V_56 )
{
F_8 ( & V_63 ) ;
F_46 ( 0 ) ;
F_15 ( & V_63 ) ;
F_79 ( V_56 -> V_71 ,
V_90 , F_70 ) ;
F_63 ( V_56 ) ;
return 0 ;
}
static int T_9 F_80 ( void )
{
F_1 () ;
if ( V_16 == 0 )
return - V_62 ;
return F_81 ( & V_91 ) ;
}
static void T_10 F_82 ( void )
{
F_83 ( & V_91 ) ;
}
