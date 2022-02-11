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
F_32 ( V_16 , 1 ) ;
F_33 () ;
if ( V_53 )
F_28 (
V_56 , & V_30 ) ;
F_34 () ;
if ( V_50 > V_47 ) {
V_44 = 1 ;
break;
}
}
if ( V_44 )
F_35 ( V_49 * V_51 / 100 ) ;
}
F_20 ( V_25 ) ;
return 0 ;
}
static int F_36 ( void )
{
int V_57 ;
V_58 [ V_59 ] = F_37 ( F_21 ,
( void * ) ( unsigned long ) V_59 ,
L_2 , V_59 ) ;
if ( F_38 ( V_58 [ V_59 ] ) ) {
V_57 = F_39 ( V_58 [ V_59 ] ) ;
V_58 [ V_59 ] = NULL ;
} else {
V_57 = 0 ;
V_59 ++ ;
}
return V_57 ;
}
static void F_40 ( void )
{
if ( V_59 > 0 ) {
V_59 -- ;
F_41 ( V_58 [ V_59 ] ) ;
V_58 [ V_59 ] = NULL ;
}
}
static void F_42 ( unsigned int V_60 )
{
if ( V_60 > V_59 ) {
while ( V_59 < V_60 ) {
if ( F_36 () )
return;
}
} else if ( V_60 < V_59 ) {
while ( V_59 > V_60 )
F_40 () ;
}
}
static void F_43 ( unsigned int V_61 )
{
F_44 () ;
V_61 = F_45 (unsigned int, num_cpus, num_online_cpus()) ;
F_42 ( V_61 ) ;
F_46 () ;
}
static T_3 F_47 ( void )
{
return V_59 ;
}
static T_4 F_48 ( struct V_62 * V_63 ,
struct V_64 * V_65 , const char * V_66 , T_5 V_67 )
{
unsigned long V_60 ;
if ( F_49 ( V_66 , 0 , & V_60 ) )
return - V_68 ;
if ( V_60 < 1 || V_60 >= 100 )
return - V_68 ;
F_8 ( & V_69 ) ;
V_48 = V_60 ;
F_15 ( & V_69 ) ;
return V_67 ;
}
static T_4 F_50 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
return F_51 ( V_66 , V_70 , L_3 , V_48 ) ;
}
static T_4 F_52 ( struct V_62 * V_63 ,
struct V_64 * V_65 , const char * V_66 , T_5 V_67 )
{
unsigned long V_60 ;
if ( F_49 ( V_66 , 0 , & V_60 ) )
return - V_68 ;
if ( V_60 < 1 || V_60 >= 100 )
return - V_68 ;
F_8 ( & V_69 ) ;
V_51 = V_60 ;
F_15 ( & V_69 ) ;
return V_67 ;
}
static T_4 F_53 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
return F_51 ( V_66 , V_70 , L_3 , V_51 ) ;
}
static T_4 F_54 ( struct V_62 * V_63 ,
struct V_64 * V_65 , const char * V_66 , T_5 V_67 )
{
unsigned long V_60 ;
if ( F_49 ( V_66 , 0 , & V_60 ) )
return - V_68 ;
F_8 ( & V_69 ) ;
F_43 ( V_60 ) ;
F_15 ( & V_69 ) ;
return V_67 ;
}
static T_4 F_55 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
int V_71 = 0 ;
V_71 = F_56 ( V_66 , V_70 - 2 , F_6 ( V_28 ) ) ;
V_66 [ V_71 ++ ] = '\n' ;
V_66 [ V_71 ] = '\0' ;
return V_71 ;
}
static int F_57 ( struct V_72 * V_62 )
{
int V_73 ;
V_73 = F_58 ( & V_62 -> V_63 , & V_74 ) ;
if ( V_73 )
return - V_75 ;
V_73 = F_58 ( & V_62 -> V_63 , & V_76 ) ;
if ( V_73 ) {
F_59 ( & V_62 -> V_63 , & V_74 ) ;
return - V_75 ;
}
V_73 = F_58 ( & V_62 -> V_63 , & V_77 ) ;
if ( V_73 ) {
F_59 ( & V_62 -> V_63 , & V_74 ) ;
F_59 ( & V_62 -> V_63 , & V_76 ) ;
return - V_75 ;
}
return 0 ;
}
static void F_60 ( struct V_72 * V_62 )
{
F_59 ( & V_62 -> V_63 , & V_74 ) ;
F_59 ( & V_62 -> V_63 , & V_76 ) ;
F_59 ( & V_62 -> V_63 , & V_77 ) ;
}
static int F_61 ( T_6 V_78 )
{
struct V_79 V_80 = { V_81 , NULL } ;
union V_82 * V_83 ;
int V_60 = - 1 ;
if ( F_62 ( F_63 ( V_78 , L_4 , NULL , & V_80 ) ) )
return V_60 ;
if ( ! V_80 . V_84 || ! V_80 . V_85 )
return V_60 ;
V_83 = V_80 . V_85 ;
if ( V_83 -> type == V_86 &&
V_83 -> V_83 . V_67 == 2 &&
V_83 -> V_83 . V_87 [ 0 ] . integer . V_88 == 1 )
V_60 = V_83 -> V_83 . V_87 [ 1 ] . integer . V_88 ;
F_64 ( V_80 . V_85 ) ;
return V_60 ;
}
static void F_65 ( T_6 V_78 , int V_89 ,
T_3 V_90 )
{
union V_82 V_91 [ 3 ] = {
{ . type = V_92 ,} ,
{ . type = V_92 ,} ,
{ . type = V_93 ,} ,
} ;
struct V_94 V_95 = { 3 , V_91 } ;
V_91 [ 0 ] . integer . V_88 = V_96 ;
V_91 [ 1 ] . integer . V_88 = V_89 ;
V_91 [ 2 ] . V_80 . V_84 = 4 ;
V_91 [ 2 ] . V_80 . V_85 = ( void * ) & V_90 ;
F_63 ( V_78 , L_5 , & V_95 , NULL ) ;
}
static void F_66 ( T_6 V_78 )
{
int V_61 ;
T_3 V_90 ;
F_8 ( & V_69 ) ;
V_61 = F_61 ( V_78 ) ;
if ( V_61 < 0 ) {
F_15 ( & V_69 ) ;
return;
}
F_43 ( V_61 ) ;
V_90 = F_47 () ;
F_65 ( V_78 , 0 , V_90 ) ;
F_15 ( & V_69 ) ;
}
static void F_67 ( T_6 V_78 , T_7 V_97 ,
void * V_40 )
{
struct V_72 * V_62 = V_40 ;
switch ( V_97 ) {
case V_96 :
F_66 ( V_78 ) ;
F_68 ( V_62 -> V_98 . V_99 ,
F_69 ( & V_62 -> V_63 ) , V_97 , 0 ) ;
break;
default:
F_70 ( L_6 , V_97 ) ;
break;
}
}
static int F_71 ( struct V_72 * V_62 )
{
T_8 V_100 ;
strcpy ( F_72 ( V_62 ) , V_101 ) ;
strcpy ( F_73 ( V_62 ) , V_102 ) ;
if ( F_57 ( V_62 ) )
return - V_75 ;
V_100 = F_74 ( V_62 -> V_78 ,
V_103 , F_67 , V_62 ) ;
if ( F_62 ( V_100 ) ) {
F_60 ( V_62 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_75 ( struct V_72 * V_62 )
{
F_8 ( & V_69 ) ;
F_43 ( 0 ) ;
F_15 ( & V_69 ) ;
F_76 ( V_62 -> V_78 ,
V_103 , F_67 ) ;
F_60 ( V_62 ) ;
return 0 ;
}
static int T_9 F_77 ( void )
{
F_1 () ;
if ( V_16 == 0 )
return - V_68 ;
return F_78 ( & V_104 ) ;
}
static void T_10 F_79 ( void )
{
F_80 ( & V_104 ) ;
}
