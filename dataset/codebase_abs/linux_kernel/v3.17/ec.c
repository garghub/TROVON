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
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
int V_14 = 0 ;
F_9 ( & V_2 -> V_15 , V_13 ) ;
if ( V_2 -> V_16 && ( V_2 -> V_16 -> V_13 & V_17 ) )
V_14 = 1 ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
return V_14 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
T_1 V_20 ;
bool V_21 = false ;
F_3 ( L_6 , F_12 () ? L_7 : L_8 ) ;
V_20 = F_1 ( V_2 ) ;
V_19 = V_2 -> V_16 ;
if ( ! V_19 )
goto V_22;
if ( V_19 -> V_13 & V_23 ) {
if ( V_19 -> V_24 > V_19 -> V_25 ) {
if ( ( V_20 & V_8 ) == 0 )
F_7 ( V_2 , V_19 -> V_26 [ V_19 -> V_25 ++ ] ) ;
else
goto V_22;
} else if ( V_19 -> V_27 > V_19 -> V_28 ) {
if ( ( V_20 & V_9 ) == 1 ) {
V_19 -> V_29 [ V_19 -> V_28 ++ ] = F_4 ( V_2 ) ;
if ( V_19 -> V_27 == V_19 -> V_28 ) {
V_19 -> V_13 |= V_17 ;
if ( V_19 -> V_11 == V_30 )
F_3 ( L_9 ) ;
V_21 = true ;
}
} else
goto V_22;
} else if ( V_19 -> V_24 == V_19 -> V_25 &&
( V_20 & V_8 ) == 0 ) {
V_19 -> V_13 |= V_17 ;
V_21 = true ;
}
return V_21 ;
} else {
if ( ! ( V_20 & V_5 ) &&
( V_19 -> V_11 == V_30 ) ) {
V_19 -> V_13 |= V_23 ;
V_19 -> V_29 [ V_19 -> V_28 ++ ] = 0x00 ;
V_19 -> V_13 |= V_17 ;
F_3 ( L_10 ) ;
V_21 = true ;
} else if ( ( V_20 & V_8 ) == 0 ) {
F_5 ( V_2 , V_19 -> V_11 ) ;
V_19 -> V_13 |= V_23 ;
} else
goto V_22;
return V_21 ;
}
V_22:
if ( ! ( V_20 & V_5 ) ) {
if ( F_12 () && V_19 )
++ V_19 -> V_31 ;
}
return V_21 ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_16 -> V_31 = V_2 -> V_16 -> V_25 = V_2 -> V_16 -> V_28 = 0 ;
V_2 -> V_16 -> V_13 = 0 ;
( void ) F_11 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( V_32 & V_5 ) {
if ( ! F_15 ( V_33 , & V_2 -> V_13 ) )
return F_16 ( V_2 , NULL ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
int V_34 = 5 ;
while ( V_34 -- ) {
unsigned long V_35 = V_36 +
F_18 ( V_37 ) ;
do {
if ( V_38 || F_19 () ) {
F_20 ( V_39 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
} else {
if ( F_21 ( V_2 -> V_40 ,
F_8 ( V_2 ) ,
F_18 ( 1 ) ) )
return 0 ;
}
F_9 ( & V_2 -> V_15 , V_13 ) ;
( void ) F_11 ( V_2 ) ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
} while ( F_22 ( V_36 , V_35 ) );
F_3 ( L_11 ) ;
F_9 ( & V_2 -> V_15 , V_13 ) ;
F_13 ( V_2 ) ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
}
return - V_41 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
unsigned long V_42 ;
int V_14 = 0 ;
if ( V_38 )
F_20 ( V_39 ) ;
F_9 ( & V_2 -> V_15 , V_42 ) ;
V_2 -> V_16 = V_19 ;
F_13 ( V_2 ) ;
F_10 ( & V_2 -> V_15 , V_42 ) ;
V_14 = F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_15 , V_42 ) ;
if ( V_2 -> V_16 -> V_11 == V_30 )
F_24 ( V_33 , & V_2 -> V_13 ) ;
V_2 -> V_16 = NULL ;
F_10 ( & V_2 -> V_15 , V_42 ) ;
return V_14 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
int V_20 ;
T_2 V_43 ;
if ( ! V_2 || ( ! V_19 ) || ( V_19 -> V_24 && ! V_19 -> V_26 ) || ( V_19 -> V_27 && ! V_19 -> V_29 ) )
return - V_44 ;
if ( V_19 -> V_29 )
memset ( V_19 -> V_29 , 0 , V_19 -> V_27 ) ;
F_26 ( & V_2 -> V_45 ) ;
if ( F_27 ( V_46 , & V_2 -> V_13 ) ) {
V_20 = - V_44 ;
goto V_47;
}
if ( V_2 -> V_48 ) {
V_20 = F_28 ( V_49 , & V_43 ) ;
if ( F_29 ( V_20 ) ) {
V_20 = - V_50 ;
goto V_47;
}
}
F_3 ( L_12 ,
V_19 -> V_11 , V_19 -> V_26 ? V_19 -> V_26 [ 0 ] : 0 ) ;
if ( F_27 ( V_51 , & V_2 -> V_13 ) ) {
F_30 ( NULL , V_2 -> V_52 ) ;
}
V_20 = F_23 ( V_2 , V_19 ) ;
F_14 ( V_2 , F_1 ( V_2 ) ) ;
if ( F_27 ( V_51 , & V_2 -> V_13 ) ) {
F_31 ( 1 ) ;
F_32 ( NULL , V_2 -> V_52 ) ;
} else if ( V_19 -> V_31 > V_53 ) {
F_33 ( L_13
L_14 ,
V_19 -> V_31 ) ;
F_34 ( V_51 , & V_2 -> V_13 ) ;
}
F_3 ( L_15 ) ;
if ( V_2 -> V_48 )
F_35 ( V_43 ) ;
V_47:
F_36 ( & V_2 -> V_45 ) ;
return V_20 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_54 ;
struct V_18 V_19 = { . V_11 = V_55 ,
. V_26 = NULL , . V_29 = & V_54 ,
. V_24 = 0 , . V_27 = 1 } ;
return F_25 ( V_2 , & V_19 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_18 V_19 = { . V_11 = V_56 ,
. V_26 = NULL , . V_29 = NULL ,
. V_24 = 0 , . V_27 = 0 } ;
return ( F_1 ( V_2 ) & V_6 ) ?
F_25 ( V_2 , & V_19 ) : 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_57 , T_1 * V_12 )
{
int V_58 ;
T_1 V_54 ;
struct V_18 V_19 = { . V_11 = V_59 ,
. V_26 = & V_57 , . V_29 = & V_54 ,
. V_24 = 1 , . V_27 = 1 } ;
V_58 = F_25 ( V_2 , & V_19 ) ;
* V_12 = V_54 ;
return V_58 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_57 , T_1 V_12 )
{
T_1 V_26 [ 2 ] = { V_57 , V_12 } ;
struct V_18 V_19 = { . V_11 = V_60 ,
. V_26 = V_26 , . V_29 = NULL ,
. V_24 = 2 , . V_27 = 0 } ;
return F_25 ( V_2 , & V_19 ) ;
}
int F_41 ( T_1 V_61 , T_1 * V_62 )
{
int V_22 ;
T_1 V_63 ;
if ( ! V_64 )
return - V_50 ;
V_22 = F_39 ( V_64 , V_61 , & V_63 ) ;
if ( ! V_22 ) {
* V_62 = V_63 ;
return 0 ;
} else
return V_22 ;
}
int F_42 ( T_1 V_61 , T_1 V_62 )
{
int V_22 ;
if ( ! V_64 )
return - V_50 ;
V_22 = F_40 ( V_64 , V_61 , V_62 ) ;
return V_22 ;
}
int F_43 ( T_1 V_11 ,
const T_1 * V_26 , unsigned V_65 ,
T_1 * V_29 , unsigned V_66 )
{
struct V_18 V_19 = { . V_11 = V_11 ,
. V_26 = V_26 , . V_29 = V_29 ,
. V_24 = V_65 , . V_27 = V_66 } ;
if ( ! V_64 )
return - V_50 ;
return F_25 ( V_64 , & V_19 ) ;
}
T_3 F_44 ( void )
{
if ( ! V_64 )
return NULL ;
return V_64 -> V_67 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_68 , V_20 ;
T_1 V_69 = 0 ;
for ( V_68 = 0 ; V_68 < V_70 ; V_68 ++ ) {
V_20 = F_16 ( V_2 , & V_69 ) ;
if ( V_20 || ! V_69 )
break;
}
if ( F_46 ( V_68 == V_70 ) )
F_47 ( L_16 , V_68 ) ;
else
F_33 ( L_17 , V_68 ) ;
}
void F_48 ( void )
{
struct V_1 * V_2 = V_64 ;
if ( ! V_2 )
return;
F_26 ( & V_2 -> V_45 ) ;
F_34 ( V_46 , & V_2 -> V_13 ) ;
F_36 ( & V_2 -> V_45 ) ;
}
void F_49 ( void )
{
struct V_1 * V_2 = V_64 ;
if ( ! V_2 )
return;
F_26 ( & V_2 -> V_45 ) ;
F_24 ( V_46 , & V_2 -> V_13 ) ;
if ( V_71 )
F_45 ( V_2 ) ;
F_36 ( & V_2 -> V_45 ) ;
}
void F_50 ( void )
{
if ( V_64 )
F_24 ( V_46 , & V_64 -> V_13 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_58 ;
T_1 V_54 ;
struct V_18 V_19 = { . V_11 = V_30 ,
. V_26 = NULL , . V_29 = & V_54 ,
. V_24 = 0 , . V_27 = 1 } ;
if ( ! V_2 || ! V_12 )
return - V_44 ;
V_58 = F_23 ( V_2 , & V_19 ) ;
if ( V_58 )
return V_58 ;
if ( ! V_54 )
return - V_72 ;
* V_12 = V_54 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_73 ,
T_3 V_67 , T_4 V_74 ,
void * V_12 )
{
struct V_75 * V_76 =
F_53 ( sizeof( struct V_75 ) , V_77 ) ;
if ( ! V_76 )
return - V_78 ;
V_76 -> V_73 = V_73 ;
V_76 -> V_67 = V_67 ;
V_76 -> V_74 = V_74 ;
V_76 -> V_12 = V_12 ;
F_26 ( & V_2 -> V_45 ) ;
F_54 ( & V_76 -> V_79 , & V_2 -> V_80 ) ;
F_36 ( & V_2 -> V_45 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 , T_1 V_73 )
{
struct V_75 * V_76 , * V_42 ;
F_26 ( & V_2 -> V_45 ) ;
F_56 (handler, tmp, &ec->list, node) {
if ( V_73 == V_76 -> V_73 ) {
F_57 ( & V_76 -> V_79 ) ;
F_58 ( V_76 ) ;
}
}
F_36 ( & V_2 -> V_45 ) ;
}
static void F_59 ( void * V_81 )
{
struct V_75 * V_76 = V_81 ;
if ( ! V_76 )
return;
F_3 ( L_18 ) ;
if ( V_76 -> V_74 )
V_76 -> V_74 ( V_76 -> V_12 ) ;
else if ( V_76 -> V_67 )
F_60 ( V_76 -> V_67 , NULL , NULL , NULL ) ;
F_3 ( L_19 ) ;
F_58 ( V_76 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_12 )
{
T_1 V_69 = 0 ;
int V_20 ;
struct V_75 * V_76 , * V_82 ;
V_20 = F_51 ( V_2 , & V_69 ) ;
if ( V_12 )
* V_12 = V_69 ;
if ( V_20 )
return V_20 ;
F_61 (handler, &ec->list, node) {
if ( V_69 == V_76 -> V_73 ) {
V_82 = F_62 ( sizeof( * V_76 ) , V_77 ) ;
if ( ! V_82 )
return - V_78 ;
memcpy ( V_82 , V_76 , sizeof( * V_82 ) ) ;
F_3 ( L_20 ,
V_69 ) ;
return F_63 ( ( V_82 -> V_74 ) ?
V_83 : V_84 ,
F_59 , V_82 ) ;
}
}
return 0 ;
}
static void F_64 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
if ( ! V_2 )
return;
F_26 ( & V_2 -> V_45 ) ;
F_16 ( V_2 , NULL ) ;
F_36 ( & V_2 -> V_45 ) ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( V_32 & V_5 ) {
if ( ! F_15 ( V_33 , & V_2 -> V_13 ) ) {
F_3 ( L_21 ) ;
return F_63 ( V_83 ,
F_64 , V_2 ) ;
}
}
return 0 ;
}
static T_2 F_66 ( T_3 V_86 ,
T_2 V_87 , void * V_12 )
{
unsigned long V_13 ;
struct V_1 * V_2 = V_12 ;
F_9 ( & V_2 -> V_15 , V_13 ) ;
if ( F_11 ( V_2 ) )
F_67 ( & V_2 -> V_40 ) ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
F_65 ( V_2 , F_1 ( V_2 ) ) ;
return V_88 | V_89 ;
}
static T_5
F_68 ( T_2 V_90 , T_6 V_57 ,
T_2 V_91 , T_7 * V_92 ,
void * V_93 , void * V_94 )
{
struct V_1 * V_2 = V_93 ;
int V_58 = 0 , V_68 , V_95 = V_91 / 8 ;
T_1 * V_69 = ( T_1 * ) V_92 ;
if ( ( V_57 > 0xFF ) || ! V_69 || ! V_93 )
return V_96 ;
if ( V_90 != V_97 && V_90 != V_98 )
return V_96 ;
if ( V_38 || V_91 > 8 )
F_37 ( V_2 ) ;
for ( V_68 = 0 ; V_68 < V_95 ; ++ V_68 , ++ V_57 , ++ V_69 )
V_58 = ( V_90 == V_97 ) ?
F_39 ( V_2 , V_57 , V_69 ) :
F_40 ( V_2 , V_57 , * V_69 ) ;
if ( V_38 || V_91 > 8 )
F_38 ( V_2 ) ;
switch ( V_58 ) {
case - V_44 :
return V_96 ;
break;
case - V_50 :
return V_99 ;
break;
case - V_41 :
return V_100 ;
break;
default:
return V_101 ;
}
}
static struct V_1 * F_69 ( void )
{
struct V_1 * V_2 = F_53 ( sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = 1 << V_33 ;
F_70 ( & V_2 -> V_45 ) ;
F_71 ( & V_2 -> V_40 ) ;
F_72 ( & V_2 -> V_80 ) ;
F_73 ( & V_2 -> V_15 ) ;
return V_2 ;
}
static T_5
F_74 ( T_3 V_67 , T_2 V_102 ,
void * V_103 , void * * V_104 )
{
char V_105 [ 5 ] ;
struct V_106 V_107 = { sizeof( V_105 ) , V_105 } ;
struct V_1 * V_2 = V_103 ;
int V_69 = 0 ;
T_5 V_20 ;
V_20 = F_75 ( V_67 , V_108 , & V_107 ) ;
if ( F_76 ( V_20 ) && sscanf ( V_105 , L_22 , & V_69 ) == 1 ) {
F_52 ( V_2 , V_69 , V_67 , NULL , NULL ) ;
}
return V_101 ;
}
static T_5
F_77 ( T_3 V_67 , T_2 V_109 , void * V_103 , void * * V_110 )
{
T_5 V_20 ;
unsigned long long V_42 = 0 ;
struct V_1 * V_2 = V_103 ;
V_2 -> V_4 = V_2 -> V_10 = 0 ;
V_20 = F_78 ( V_67 , V_111 ,
V_112 , V_2 ) ;
if ( F_29 ( V_20 ) )
return V_20 ;
V_20 = F_79 ( V_67 , L_23 , NULL , & V_42 ) ;
if ( F_29 ( V_20 ) )
return V_20 ;
V_2 -> V_52 = V_42 ;
V_42 = 0 ;
F_79 ( V_67 , L_24 , NULL , & V_42 ) ;
V_2 -> V_48 = V_42 ;
V_2 -> V_67 = V_67 ;
return V_113 ;
}
static int F_80 ( struct V_1 * V_2 )
{
T_5 V_20 ;
if ( F_27 ( V_114 , & V_2 -> V_13 ) )
return 0 ;
V_20 = F_81 ( NULL , V_2 -> V_52 ,
V_115 ,
& F_66 , V_2 ) ;
if ( F_29 ( V_20 ) )
return - V_50 ;
F_32 ( NULL , V_2 -> V_52 ) ;
V_20 = F_82 ( V_2 -> V_67 ,
V_116 ,
& F_68 ,
NULL , V_2 ) ;
if ( F_29 ( V_20 ) ) {
if ( V_20 == V_99 ) {
F_83 ( L_25
L_26 ) ;
} else {
F_30 ( NULL , V_2 -> V_52 ) ;
F_84 ( NULL , V_2 -> V_52 ,
& F_66 ) ;
return - V_50 ;
}
}
F_34 ( V_114 , & V_2 -> V_13 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_30 ( NULL , V_2 -> V_52 ) ;
if ( F_29 ( F_86 ( V_2 -> V_67 ,
V_116 , & F_68 ) ) )
F_83 ( L_27 ) ;
if ( F_29 ( F_84 ( NULL , V_2 -> V_52 ,
& F_66 ) ) )
F_83 ( L_28 ) ;
F_24 ( V_114 , & V_2 -> V_13 ) ;
}
static int F_87 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = NULL ;
int V_14 ;
strcpy ( F_88 ( V_118 ) , V_119 ) ;
strcpy ( F_89 ( V_118 ) , V_120 ) ;
if ( V_121 &&
( V_121 -> V_67 == V_118 -> V_67 ||
V_121 -> V_67 == V_122 ) ) {
V_2 = V_121 ;
V_121 = NULL ;
} else {
V_2 = F_69 () ;
if ( ! V_2 )
return - V_78 ;
}
if ( F_77 ( V_118 -> V_67 , 0 , V_2 , NULL ) !=
V_113 ) {
F_58 ( V_2 ) ;
return - V_44 ;
}
F_90 ( V_123 , V_2 -> V_67 , 1 ,
F_74 , NULL , V_2 , NULL ) ;
if ( ! V_64 )
V_64 = V_2 ;
V_118 -> V_124 = V_2 ;
V_14 = ! ! F_91 ( V_2 -> V_10 , 1 , L_29 ) ;
F_92 ( ! V_14 , L_30 , V_2 -> V_10 ) ;
V_14 = ! ! F_91 ( V_2 -> V_4 , 1 , L_31 ) ;
F_92 ( ! V_14 , L_32 , V_2 -> V_4 ) ;
F_33 ( L_33 ,
V_2 -> V_52 , V_2 -> V_4 , V_2 -> V_10 ) ;
V_14 = F_80 ( V_2 ) ;
F_24 ( V_33 , & V_2 -> V_13 ) ;
if ( V_71 ) {
F_26 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
F_36 ( & V_2 -> V_45 ) ;
}
return V_14 ;
}
static int F_93 ( struct V_117 * V_118 )
{
struct V_1 * V_2 ;
struct V_75 * V_76 , * V_42 ;
if ( ! V_118 )
return - V_44 ;
V_2 = F_94 ( V_118 ) ;
F_85 ( V_2 ) ;
F_26 ( & V_2 -> V_45 ) ;
F_56 (handler, tmp, &ec->list, node) {
F_57 ( & V_76 -> V_79 ) ;
F_58 ( V_76 ) ;
}
F_36 ( & V_2 -> V_45 ) ;
F_95 ( V_2 -> V_10 , 1 ) ;
F_95 ( V_2 -> V_4 , 1 ) ;
V_118 -> V_124 = NULL ;
if ( V_2 == V_64 )
V_64 = NULL ;
F_58 ( V_2 ) ;
return 0 ;
}
static T_5
V_112 ( struct V_125 * V_126 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
if ( V_126 -> type != V_127 )
return V_101 ;
if ( V_2 -> V_10 == 0 )
V_2 -> V_10 = V_126 -> V_12 . V_128 . V_129 ;
else if ( V_2 -> V_4 == 0 )
V_2 -> V_4 = V_126 -> V_12 . V_128 . V_129 ;
else
return V_113 ;
return V_101 ;
}
int T_8 F_96 ( void )
{
if ( ! V_121 || F_27 ( V_114 , & V_121 -> V_13 ) )
return 0 ;
if ( ! F_80 ( V_121 ) ) {
V_64 = V_121 ;
return 0 ;
}
return - V_130 ;
}
static int F_97 ( const struct V_131 * V_132 )
{
V_133 = 1 ;
return 0 ;
}
static int F_98 ( const struct V_131 * V_132 )
{
V_134 = 1 ;
return 0 ;
}
static int F_99 ( const struct V_131 * V_132 )
{
F_3 ( L_34 ) ;
V_38 = 1 ;
V_134 = 1 ;
return 0 ;
}
static int F_100 ( const struct V_131 * V_132 )
{
F_3 ( L_35 ) ;
V_53 = 20 ;
return 0 ;
}
static int F_101 ( const struct V_131 * V_132 )
{
F_3 ( L_36 ) ;
V_71 = 1 ;
return 0 ;
}
int T_8 F_102 ( void )
{
T_5 V_20 ;
struct V_1 * V_135 = NULL ;
struct V_136 * V_137 ;
V_121 = F_69 () ;
if ( ! V_121 )
return - V_78 ;
F_103 ( V_138 ) ;
V_20 = F_104 ( V_139 , 1 ,
(struct V_140 * * ) & V_137 ) ;
if ( F_76 ( V_20 ) ) {
F_33 ( L_37 ) ;
V_121 -> V_4 = V_137 -> V_141 . V_57 ;
V_121 -> V_10 = V_137 -> V_12 . V_57 ;
V_121 -> V_52 = V_137 -> V_52 ;
V_121 -> V_67 = V_122 ;
F_105 ( V_122 , V_137 -> V_132 , & V_121 -> V_67 ) ;
if ( ! V_134 )
goto V_142;
V_135 = F_106 ( V_121 , sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_135 )
return - V_78 ;
}
if ( V_133 ) {
F_58 ( V_135 ) ;
return - V_50 ;
}
F_3 ( L_38 ) ;
V_20 = F_107 ( V_143 [ 0 ] . V_132 , F_77 ,
V_121 , NULL ) ;
if ( F_29 ( V_20 ) || ! V_121 -> V_67 )
goto error;
if ( V_135 ) {
if ( V_135 -> V_4 != V_121 -> V_4 ||
V_135 -> V_10 != V_121 -> V_10 ||
V_135 -> V_52 != V_121 -> V_52 ||
V_135 -> V_67 != V_121 -> V_67 )
F_33 ( L_39
L_40
L_41
L_42 ) ;
F_58 ( V_135 ) ;
V_135 = NULL ;
} else {
if ( ! F_108 ( L_43 ) ||
! F_109 ( V_121 -> V_67 , L_44 ) )
return - V_50 ;
}
V_142:
if ( ! F_80 ( V_121 ) ) {
V_64 = V_121 ;
return 0 ;
}
error:
F_58 ( V_121 ) ;
F_58 ( V_135 ) ;
V_121 = NULL ;
return - V_50 ;
}
int T_8 F_110 ( void )
{
int V_58 = 0 ;
V_58 = F_111 ( & V_144 ) ;
if ( V_58 < 0 )
return - V_50 ;
return V_58 ;
}
