static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( L_1
L_2 ,
V_3 ,
! ! ( V_3 & V_5 ) ,
! ! ( V_3 & V_6 ) ,
! ! ( V_3 & V_7 ) ,
! ! ( V_3 & V_8 ) ,
! ! ( V_3 & V_9 ) ) ;
return V_3 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_10 ) ;
F_3 ( L_3 , V_3 ) ;
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_11 )
{
F_3 ( L_4 , V_11 ) ;
F_6 ( V_11 , V_2 -> V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
F_3 ( L_5 , V_12 ) ;
F_6 ( V_12 , V_2 -> V_10 ) ;
}
static const char * F_8 ( T_1 V_13 )
{
switch ( V_13 ) {
case 0x80 :
return L_6 ;
case 0x81 :
return L_7 ;
case 0x82 :
return L_8 ;
case 0x83 :
return L_9 ;
case 0x84 :
return L_10 ;
}
return L_11 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_15 = 0 ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_17 -> V_14 & V_18 ) )
V_15 = 1 ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
return V_15 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
T_1 V_21 ;
bool V_22 = false ;
F_3 ( L_12 ,
F_13 () ? L_13 : L_14 , F_14 () ) ;
V_21 = F_1 ( V_2 ) ;
V_20 = V_2 -> V_17 ;
if ( ! V_20 )
goto V_23;
if ( V_20 -> V_14 & V_24 ) {
if ( V_20 -> V_25 > V_20 -> V_26 ) {
if ( ( V_21 & V_8 ) == 0 )
F_7 ( V_2 , V_20 -> V_27 [ V_20 -> V_26 ++ ] ) ;
else
goto V_23;
} else if ( V_20 -> V_28 > V_20 -> V_29 ) {
if ( ( V_21 & V_9 ) == 1 ) {
V_20 -> V_30 [ V_20 -> V_29 ++ ] = F_4 ( V_2 ) ;
if ( V_20 -> V_28 == V_20 -> V_29 ) {
V_20 -> V_14 |= V_18 ;
if ( V_20 -> V_11 == V_31 )
F_3 ( L_15 ,
F_8 ( V_20 -> V_11 ) ) ;
V_22 = true ;
}
} else
goto V_23;
} else if ( V_20 -> V_25 == V_20 -> V_26 &&
( V_21 & V_8 ) == 0 ) {
V_20 -> V_14 |= V_18 ;
V_22 = true ;
}
return V_22 ;
} else {
if ( V_32 &&
! ( V_21 & V_5 ) &&
( V_20 -> V_11 == V_31 ) ) {
V_20 -> V_14 |= V_24 ;
V_20 -> V_30 [ V_20 -> V_29 ++ ] = 0x00 ;
V_20 -> V_14 |= V_18 ;
F_3 ( L_16 ,
F_8 ( V_20 -> V_11 ) ) ;
V_22 = true ;
} else if ( ( V_21 & V_8 ) == 0 ) {
F_5 ( V_2 , V_20 -> V_11 ) ;
V_20 -> V_14 |= V_24 ;
} else
goto V_23;
return V_22 ;
}
V_23:
if ( ! ( V_21 & V_5 ) ) {
if ( F_13 () && V_20 )
++ V_20 -> V_33 ;
}
return V_22 ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_17 -> V_33 = V_2 -> V_17 -> V_26 = V_2 -> V_17 -> V_29 = 0 ;
V_2 -> V_17 -> V_14 = 0 ;
( void ) F_12 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_34 )
{
if ( V_34 & V_5 ) {
if ( ! F_17 ( V_35 , & V_2 -> V_14 ) )
return F_18 ( V_2 , NULL ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_36 = 5 ;
while ( V_36 -- ) {
unsigned long V_37 = V_38 +
F_20 ( V_39 ) ;
do {
if ( V_40 || F_21 () ) {
F_22 ( V_41 ) ;
if ( F_9 ( V_2 ) )
return 0 ;
} else {
if ( F_23 ( V_2 -> V_42 ,
F_9 ( V_2 ) ,
F_20 ( 1 ) ) )
return 0 ;
}
F_10 ( & V_2 -> V_16 , V_14 ) ;
( void ) F_12 ( V_2 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
} while ( F_24 ( V_38 , V_37 ) );
F_3 ( L_17 ) ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
F_15 ( V_2 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
}
return - V_43 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
unsigned long V_44 ;
int V_15 = 0 ;
if ( V_40 )
F_22 ( V_41 ) ;
F_10 ( & V_2 -> V_16 , V_44 ) ;
V_2 -> V_17 = V_20 ;
F_3 ( L_18 ,
F_8 ( V_20 -> V_11 ) ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_17 -> V_11 == V_31 ) {
F_26 ( V_35 , & V_2 -> V_14 ) ;
F_3 ( L_19 ) ;
}
F_11 ( & V_2 -> V_16 , V_44 ) ;
V_15 = F_19 ( V_2 ) ;
F_10 ( & V_2 -> V_16 , V_44 ) ;
F_3 ( L_20 ,
F_8 ( V_20 -> V_11 ) ) ;
V_2 -> V_17 = NULL ;
F_11 ( & V_2 -> V_16 , V_44 ) ;
return V_15 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_21 ;
T_2 V_45 ;
if ( ! V_2 || ( ! V_20 ) || ( V_20 -> V_25 && ! V_20 -> V_27 ) || ( V_20 -> V_28 && ! V_20 -> V_30 ) )
return - V_46 ;
if ( V_20 -> V_30 )
memset ( V_20 -> V_30 , 0 , V_20 -> V_28 ) ;
F_28 ( & V_2 -> V_47 ) ;
if ( F_29 ( V_48 , & V_2 -> V_14 ) ) {
V_21 = - V_46 ;
goto V_49;
}
if ( V_2 -> V_50 ) {
V_21 = F_30 ( V_51 , & V_45 ) ;
if ( F_31 ( V_21 ) ) {
V_21 = - V_52 ;
goto V_49;
}
}
if ( F_29 ( V_53 , & V_2 -> V_14 ) ) {
F_32 ( NULL , V_2 -> V_54 ) ;
}
V_21 = F_25 ( V_2 , V_20 ) ;
F_16 ( V_2 , F_1 ( V_2 ) ) ;
if ( F_29 ( V_53 , & V_2 -> V_14 ) ) {
F_33 ( 1 ) ;
F_34 ( NULL , V_2 -> V_54 ) ;
} else if ( V_20 -> V_33 > V_55 ) {
F_35 ( L_21
L_22 ,
V_20 -> V_33 ) ;
F_36 ( V_53 , & V_2 -> V_14 ) ;
}
if ( V_2 -> V_50 )
F_37 ( V_45 ) ;
V_49:
F_38 ( & V_2 -> V_47 ) ;
return V_21 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_56 ;
struct V_19 V_20 = { . V_11 = V_57 ,
. V_27 = NULL , . V_30 = & V_56 ,
. V_25 = 0 , . V_28 = 1 } ;
return F_27 ( V_2 , & V_20 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_19 V_20 = { . V_11 = V_58 ,
. V_27 = NULL , . V_30 = NULL ,
. V_25 = 0 , . V_28 = 0 } ;
return ( F_1 ( V_2 ) & V_6 ) ?
F_27 ( V_2 , & V_20 ) : 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_59 , T_1 * V_12 )
{
int V_60 ;
T_1 V_56 ;
struct V_19 V_20 = { . V_11 = V_61 ,
. V_27 = & V_59 , . V_30 = & V_56 ,
. V_25 = 1 , . V_28 = 1 } ;
V_60 = F_27 ( V_2 , & V_20 ) ;
* V_12 = V_56 ;
return V_60 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_59 , T_1 V_12 )
{
T_1 V_27 [ 2 ] = { V_59 , V_12 } ;
struct V_19 V_20 = { . V_11 = V_62 ,
. V_27 = V_27 , . V_30 = NULL ,
. V_25 = 2 , . V_28 = 0 } ;
return F_27 ( V_2 , & V_20 ) ;
}
int F_43 ( T_1 V_63 , T_1 * V_64 )
{
int V_23 ;
T_1 V_65 ;
if ( ! V_66 )
return - V_52 ;
V_23 = F_41 ( V_66 , V_63 , & V_65 ) ;
if ( ! V_23 ) {
* V_64 = V_65 ;
return 0 ;
}
return V_23 ;
}
int F_44 ( T_1 V_63 , T_1 V_64 )
{
int V_23 ;
if ( ! V_66 )
return - V_52 ;
V_23 = F_42 ( V_66 , V_63 , V_64 ) ;
return V_23 ;
}
int F_45 ( T_1 V_11 ,
const T_1 * V_27 , unsigned V_67 ,
T_1 * V_30 , unsigned V_68 )
{
struct V_19 V_20 = { . V_11 = V_11 ,
. V_27 = V_27 , . V_30 = V_30 ,
. V_25 = V_67 , . V_28 = V_68 } ;
if ( ! V_66 )
return - V_52 ;
return F_27 ( V_66 , & V_20 ) ;
}
T_3 F_46 ( void )
{
if ( ! V_66 )
return NULL ;
return V_66 -> V_69 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_70 , V_21 ;
T_1 V_71 = 0 ;
for ( V_70 = 0 ; V_70 < V_72 ; V_70 ++ ) {
V_21 = F_18 ( V_2 , & V_71 ) ;
if ( V_21 || ! V_71 )
break;
}
if ( F_48 ( V_70 == V_72 ) )
F_49 ( L_23 , V_70 ) ;
else
F_35 ( L_24 , V_70 ) ;
}
void F_50 ( void )
{
struct V_1 * V_2 = V_66 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_47 ) ;
F_36 ( V_48 , & V_2 -> V_14 ) ;
F_38 ( & V_2 -> V_47 ) ;
}
void F_51 ( void )
{
struct V_1 * V_2 = V_66 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_47 ) ;
F_26 ( V_48 , & V_2 -> V_14 ) ;
if ( V_73 )
F_47 ( V_2 ) ;
F_38 ( & V_2 -> V_47 ) ;
}
void F_52 ( void )
{
if ( V_66 )
F_26 ( V_48 , & V_66 -> V_14 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_60 ;
T_1 V_56 ;
struct V_19 V_20 = { . V_11 = V_31 ,
. V_27 = NULL , . V_30 = & V_56 ,
. V_25 = 0 , . V_28 = 1 } ;
if ( ! V_2 || ! V_12 )
return - V_46 ;
V_60 = F_25 ( V_2 , & V_20 ) ;
if ( V_60 )
return V_60 ;
if ( ! V_56 )
return - V_74 ;
* V_12 = V_56 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_75 ,
T_3 V_69 , T_4 V_76 ,
void * V_12 )
{
struct V_77 * V_78 =
F_55 ( sizeof( struct V_77 ) , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_69 = V_69 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_12 = V_12 ;
F_28 ( & V_2 -> V_47 ) ;
F_56 ( & V_78 -> V_81 , & V_2 -> V_82 ) ;
F_38 ( & V_2 -> V_47 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , T_1 V_75 )
{
struct V_77 * V_78 , * V_44 ;
F_28 ( & V_2 -> V_47 ) ;
F_58 (handler, tmp, &ec->list, node) {
if ( V_75 == V_78 -> V_75 ) {
F_59 ( & V_78 -> V_81 ) ;
F_60 ( V_78 ) ;
}
}
F_38 ( & V_2 -> V_47 ) ;
}
static void F_61 ( void * V_83 )
{
struct V_77 * V_78 = V_83 ;
if ( ! V_78 )
return;
F_3 ( L_25 , V_78 -> V_75 ) ;
if ( V_78 -> V_76 )
V_78 -> V_76 ( V_78 -> V_12 ) ;
else if ( V_78 -> V_69 )
F_62 ( V_78 -> V_69 , NULL , NULL , NULL ) ;
F_3 ( L_26 , V_78 -> V_75 ) ;
F_60 ( V_78 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_12 )
{
T_1 V_71 = 0 ;
int V_21 ;
struct V_77 * V_78 , * V_84 ;
V_21 = F_53 ( V_2 , & V_71 ) ;
if ( V_12 )
* V_12 = V_71 ;
if ( V_21 )
return V_21 ;
F_63 (handler, &ec->list, node) {
if ( V_71 == V_78 -> V_75 ) {
V_84 = F_64 ( sizeof( * V_78 ) , V_79 ) ;
if ( ! V_84 )
return - V_80 ;
memcpy ( V_84 , V_78 , sizeof( * V_84 ) ) ;
F_3 ( L_27 ,
V_78 -> V_75 ) ;
return F_65 ( ( V_84 -> V_76 ) ?
V_85 : V_86 ,
F_61 , V_84 ) ;
}
}
return 0 ;
}
static void F_66 ( void * V_87 )
{
struct V_1 * V_2 = V_87 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_47 ) ;
F_18 ( V_2 , NULL ) ;
F_38 ( & V_2 -> V_47 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_34 )
{
if ( V_34 & V_5 ) {
if ( ! F_17 ( V_35 , & V_2 -> V_14 ) ) {
F_3 ( L_28 ) ;
return F_65 ( V_85 ,
F_66 , V_2 ) ;
}
}
return 0 ;
}
static T_2 F_68 ( T_3 V_88 ,
T_2 V_89 , void * V_12 )
{
unsigned long V_14 ;
struct V_1 * V_2 = V_12 ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
if ( F_12 ( V_2 ) )
F_69 ( & V_2 -> V_42 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
F_67 ( V_2 , F_1 ( V_2 ) ) ;
return V_90 | V_91 ;
}
static T_5
F_70 ( T_2 V_92 , T_6 V_59 ,
T_2 V_93 , T_7 * V_94 ,
void * V_95 , void * V_96 )
{
struct V_1 * V_2 = V_95 ;
int V_60 = 0 , V_70 , V_97 = V_93 / 8 ;
T_1 * V_71 = ( T_1 * ) V_94 ;
if ( ( V_59 > 0xFF ) || ! V_71 || ! V_95 )
return V_98 ;
if ( V_92 != V_99 && V_92 != V_100 )
return V_98 ;
if ( V_40 || V_93 > 8 )
F_39 ( V_2 ) ;
for ( V_70 = 0 ; V_70 < V_97 ; ++ V_70 , ++ V_59 , ++ V_71 )
V_60 = ( V_92 == V_99 ) ?
F_41 ( V_2 , V_59 , V_71 ) :
F_42 ( V_2 , V_59 , * V_71 ) ;
if ( V_40 || V_93 > 8 )
F_40 ( V_2 ) ;
switch ( V_60 ) {
case - V_46 :
return V_98 ;
case - V_52 :
return V_101 ;
case - V_43 :
return V_102 ;
default:
return V_103 ;
}
}
static struct V_1 * F_71 ( void )
{
struct V_1 * V_2 = F_55 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_14 = 1 << V_35 ;
F_72 ( & V_2 -> V_47 ) ;
F_73 ( & V_2 -> V_42 ) ;
F_74 ( & V_2 -> V_82 ) ;
F_75 ( & V_2 -> V_16 ) ;
return V_2 ;
}
static T_5
F_76 ( T_3 V_69 , T_2 V_104 ,
void * V_105 , void * * V_106 )
{
char V_107 [ 5 ] ;
struct V_108 V_109 = { sizeof( V_107 ) , V_107 } ;
struct V_1 * V_2 = V_105 ;
int V_71 = 0 ;
T_5 V_21 ;
V_21 = F_77 ( V_69 , V_110 , & V_109 ) ;
if ( F_78 ( V_21 ) && sscanf ( V_107 , L_29 , & V_71 ) == 1 )
F_54 ( V_2 , V_71 , V_69 , NULL , NULL ) ;
return V_103 ;
}
static T_5
F_79 ( T_3 V_69 , T_2 V_111 , void * V_105 , void * * V_112 )
{
T_5 V_21 ;
unsigned long long V_44 = 0 ;
struct V_1 * V_2 = V_105 ;
V_2 -> V_4 = V_2 -> V_10 = 0 ;
V_21 = F_80 ( V_69 , V_113 ,
V_114 , V_2 ) ;
if ( F_31 ( V_21 ) )
return V_21 ;
V_21 = F_81 ( V_69 , L_30 , NULL , & V_44 ) ;
if ( F_31 ( V_21 ) )
return V_21 ;
V_2 -> V_54 = V_44 ;
V_44 = 0 ;
F_81 ( V_69 , L_31 , NULL , & V_44 ) ;
V_2 -> V_50 = V_44 ;
V_2 -> V_69 = V_69 ;
return V_115 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_5 V_21 ;
if ( F_29 ( V_116 , & V_2 -> V_14 ) )
return 0 ;
V_21 = F_83 ( NULL , V_2 -> V_54 ,
V_117 ,
& F_68 , V_2 ) ;
if ( F_31 ( V_21 ) )
return - V_52 ;
F_34 ( NULL , V_2 -> V_54 ) ;
V_21 = F_84 ( V_2 -> V_69 ,
V_118 ,
& F_70 ,
NULL , V_2 ) ;
if ( F_31 ( V_21 ) ) {
if ( V_21 == V_101 ) {
F_85 ( L_32
L_33 ) ;
} else {
F_32 ( NULL , V_2 -> V_54 ) ;
F_86 ( NULL , V_2 -> V_54 ,
& F_68 ) ;
return - V_52 ;
}
}
F_36 ( V_116 , & V_2 -> V_14 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_32 ( NULL , V_2 -> V_54 ) ;
if ( F_31 ( F_88 ( V_2 -> V_69 ,
V_118 , & F_70 ) ) )
F_85 ( L_34 ) ;
if ( F_31 ( F_86 ( NULL , V_2 -> V_54 ,
& F_68 ) ) )
F_85 ( L_35 ) ;
F_26 ( V_116 , & V_2 -> V_14 ) ;
}
static int F_89 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = NULL ;
int V_15 ;
strcpy ( F_90 ( V_120 ) , V_121 ) ;
strcpy ( F_91 ( V_120 ) , V_122 ) ;
if ( V_123 &&
( V_123 -> V_69 == V_120 -> V_69 ||
V_123 -> V_69 == V_124 ) ) {
V_2 = V_123 ;
V_123 = NULL ;
} else {
V_2 = F_71 () ;
if ( ! V_2 )
return - V_80 ;
}
if ( F_79 ( V_120 -> V_69 , 0 , V_2 , NULL ) !=
V_115 ) {
F_60 ( V_2 ) ;
return - V_46 ;
}
F_92 ( V_125 , V_2 -> V_69 , 1 ,
F_76 , NULL , V_2 , NULL ) ;
if ( ! V_66 )
V_66 = V_2 ;
V_120 -> V_126 = V_2 ;
V_15 = ! ! F_93 ( V_2 -> V_10 , 1 , L_36 ) ;
F_94 ( ! V_15 , L_37 , V_2 -> V_10 ) ;
V_15 = ! ! F_93 ( V_2 -> V_4 , 1 , L_38 ) ;
F_94 ( ! V_15 , L_39 , V_2 -> V_4 ) ;
F_35 ( L_40 ,
V_2 -> V_54 , V_2 -> V_4 , V_2 -> V_10 ) ;
V_15 = F_82 ( V_2 ) ;
F_26 ( V_35 , & V_2 -> V_14 ) ;
if ( V_73 ) {
F_28 ( & V_2 -> V_47 ) ;
F_47 ( V_2 ) ;
F_38 ( & V_2 -> V_47 ) ;
}
return V_15 ;
}
static int F_95 ( struct V_119 * V_120 )
{
struct V_1 * V_2 ;
struct V_77 * V_78 , * V_44 ;
if ( ! V_120 )
return - V_46 ;
V_2 = F_96 ( V_120 ) ;
F_87 ( V_2 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_58 (handler, tmp, &ec->list, node) {
F_59 ( & V_78 -> V_81 ) ;
F_60 ( V_78 ) ;
}
F_38 ( & V_2 -> V_47 ) ;
F_97 ( V_2 -> V_10 , 1 ) ;
F_97 ( V_2 -> V_4 , 1 ) ;
V_120 -> V_126 = NULL ;
if ( V_2 == V_66 )
V_66 = NULL ;
F_60 ( V_2 ) ;
return 0 ;
}
static T_5
V_114 ( struct V_127 * V_128 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
if ( V_128 -> type != V_129 )
return V_103 ;
if ( V_2 -> V_10 == 0 )
V_2 -> V_10 = V_128 -> V_12 . V_130 . V_131 ;
else if ( V_2 -> V_4 == 0 )
V_2 -> V_4 = V_128 -> V_12 . V_130 . V_131 ;
else
return V_115 ;
return V_103 ;
}
int T_8 F_98 ( void )
{
if ( ! V_123 || F_29 ( V_116 , & V_123 -> V_14 ) )
return 0 ;
if ( ! F_82 ( V_123 ) ) {
V_66 = V_123 ;
return 0 ;
}
return - V_132 ;
}
static int F_99 ( const struct V_133 * V_134 )
{
V_135 = 1 ;
return 0 ;
}
static int F_100 ( const struct V_133 * V_134 )
{
V_136 = 1 ;
return 0 ;
}
static int F_101 ( const struct V_133 * V_134 )
{
F_3 ( L_41 ) ;
V_40 = 1 ;
V_136 = 1 ;
return 0 ;
}
static int F_102 ( const struct V_133 * V_134 )
{
F_3 ( L_42 ) ;
V_55 = 20 ;
return 0 ;
}
static int F_103 ( const struct V_133 * V_134 )
{
F_3 ( L_43 ) ;
V_32 = 1 ;
return 0 ;
}
static int F_104 ( const struct V_133 * V_134 )
{
F_3 ( L_44 ) ;
V_73 = 1 ;
return 0 ;
}
int T_8 F_105 ( void )
{
T_5 V_21 ;
struct V_1 * V_137 = NULL ;
struct V_138 * V_139 ;
V_123 = F_71 () ;
if ( ! V_123 )
return - V_80 ;
F_106 ( V_140 ) ;
V_21 = F_107 ( V_141 , 1 ,
(struct V_142 * * ) & V_139 ) ;
if ( F_78 ( V_21 ) ) {
F_35 ( L_45 ) ;
V_123 -> V_4 = V_139 -> V_143 . V_59 ;
V_123 -> V_10 = V_139 -> V_12 . V_59 ;
V_123 -> V_54 = V_139 -> V_54 ;
V_123 -> V_69 = V_124 ;
F_108 ( V_124 , V_139 -> V_134 ,
& V_123 -> V_69 ) ;
if ( ! V_136 )
goto V_144;
V_137 = F_109 ( V_123 , sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_137 )
return - V_80 ;
}
if ( V_135 ) {
F_60 ( V_137 ) ;
return - V_52 ;
}
F_3 ( L_46 ) ;
V_21 = F_110 ( V_145 [ 0 ] . V_134 , F_79 ,
V_123 , NULL ) ;
if ( F_31 ( V_21 ) || ! V_123 -> V_69 )
goto error;
if ( V_137 ) {
if ( V_137 -> V_4 != V_123 -> V_4 ||
V_137 -> V_10 != V_123 -> V_10 ||
V_137 -> V_54 != V_123 -> V_54 ||
V_137 -> V_69 != V_123 -> V_69 )
F_35 ( L_47
L_48
L_49
L_50 ) ;
F_60 ( V_137 ) ;
V_137 = NULL ;
} else {
if ( ! F_111 ( L_51 ) ||
! F_112 ( V_123 -> V_69 , L_52 ) )
return - V_52 ;
}
V_144:
if ( ! F_82 ( V_123 ) ) {
V_66 = V_123 ;
return 0 ;
}
error:
F_60 ( V_123 ) ;
F_60 ( V_137 ) ;
V_123 = NULL ;
return - V_52 ;
}
int T_8 F_113 ( void )
{
int V_60 = 0 ;
V_60 = F_114 ( & V_146 ) ;
if ( V_60 < 0 )
return - V_52 ;
return V_60 ;
}
