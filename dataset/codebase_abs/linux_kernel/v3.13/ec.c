static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( L_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_5 ) ;
F_3 ( L_2 , V_3 ) ;
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_3 ( L_3 , V_6 ) ;
F_6 ( V_6 , V_2 -> V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_7 )
{
F_3 ( L_4 , V_7 ) ;
F_6 ( V_7 , V_2 -> V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
int V_9 = 0 ;
F_9 ( & V_2 -> V_10 , V_8 ) ;
if ( ! V_2 -> V_11 || V_2 -> V_11 -> V_12 )
V_9 = 1 ;
F_10 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_11 -> V_13 = V_2 -> V_11 -> V_14 = V_2 -> V_11 -> V_15 = 0 ;
V_2 -> V_11 -> V_12 = false ;
F_5 ( V_2 , V_2 -> V_11 -> V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_16 )
{
unsigned long V_8 ;
struct V_17 * V_18 ;
F_9 ( & V_2 -> V_10 , V_8 ) ;
V_18 = V_2 -> V_11 ;
if ( ! V_18 )
goto V_19;
if ( V_18 -> V_20 > V_18 -> V_14 ) {
if ( ( V_16 & V_21 ) == 0 )
F_7 ( V_2 ,
V_18 -> V_22 [ V_18 -> V_14 ++ ] ) ;
else
goto V_23;
} else if ( V_18 -> V_24 > V_18 -> V_15 ) {
if ( ( V_16 & V_25 ) == 1 ) {
V_18 -> V_26 [ V_18 -> V_15 ++ ] = F_4 ( V_2 ) ;
if ( V_18 -> V_24 == V_18 -> V_15 )
V_18 -> V_12 = true ;
} else
goto V_23;
} else if ( V_18 -> V_20 == V_18 -> V_14 &&
( V_16 & V_21 ) == 0 )
V_18 -> V_12 = true ;
goto V_19;
V_23:
if ( F_13 () && ! ( V_16 & V_27 ) )
++ V_18 -> V_13 ;
V_19:
F_10 ( & V_2 -> V_10 , V_8 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_28 )
{
if ( V_28 & V_27 ) {
if ( ! F_15 ( V_29 , & V_2 -> V_8 ) )
return F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
int V_30 = 5 ;
while ( V_30 -- ) {
unsigned long V_31 = V_32 +
F_18 ( V_33 ) ;
do {
if ( V_34 || F_19 () ) {
F_20 ( V_35 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
} else {
if ( F_21 ( V_2 -> V_36 ,
F_8 ( V_2 ) ,
F_18 ( 1 ) ) )
return 0 ;
}
F_12 ( V_2 , F_1 ( V_2 ) ) ;
} while ( F_22 ( V_32 , V_31 ) );
F_3 ( L_5 ) ;
F_9 ( & V_2 -> V_10 , V_8 ) ;
F_11 ( V_2 ) ;
F_10 ( & V_2 -> V_10 , V_8 ) ;
}
return - V_37 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned long V_38 ;
int V_9 = 0 ;
if ( V_34 )
F_20 ( V_35 ) ;
F_9 ( & V_2 -> V_10 , V_38 ) ;
V_2 -> V_11 = V_18 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_11 -> V_6 == V_39 )
F_24 ( V_29 , & V_2 -> V_8 ) ;
F_10 ( & V_2 -> V_10 , V_38 ) ;
V_9 = F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_10 , V_38 ) ;
V_2 -> V_11 = NULL ;
F_10 ( & V_2 -> V_10 , V_38 ) ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_16 = F_1 ( V_2 ) ;
return ( V_16 & V_21 ) == 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_31 = V_32 + F_18 ( V_33 ) ;
while ( F_22 ( V_32 , V_31 ) )
if ( F_21 ( V_2 -> V_36 , F_25 ( V_2 ) ,
F_18 ( 1 ) ) )
return 0 ;
return - V_37 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_16 ;
T_2 V_40 ;
if ( ! V_2 || ( ! V_18 ) || ( V_18 -> V_20 && ! V_18 -> V_22 ) || ( V_18 -> V_24 && ! V_18 -> V_26 ) )
return - V_41 ;
if ( V_18 -> V_26 )
memset ( V_18 -> V_26 , 0 , V_18 -> V_24 ) ;
F_28 ( & V_2 -> V_42 ) ;
if ( F_29 ( V_43 , & V_2 -> V_8 ) ) {
V_16 = - V_41 ;
goto V_19;
}
if ( V_2 -> V_44 ) {
V_16 = F_30 ( V_45 , & V_40 ) ;
if ( F_31 ( V_16 ) ) {
V_16 = - V_46 ;
goto V_19;
}
}
if ( F_26 ( V_2 ) ) {
F_32 ( L_6
L_7 ) ;
V_16 = - V_37 ;
goto V_47;
}
F_3 ( L_8 ,
V_18 -> V_6 , V_18 -> V_22 ? V_18 -> V_22 [ 0 ] : 0 ) ;
if ( F_29 ( V_48 , & V_2 -> V_8 ) ) {
F_33 ( NULL , V_2 -> V_49 ) ;
}
V_16 = F_23 ( V_2 , V_18 ) ;
F_14 ( V_2 , F_1 ( V_2 ) ) ;
if ( F_29 ( V_48 , & V_2 -> V_8 ) ) {
F_34 ( 1 ) ;
F_35 ( NULL , V_2 -> V_49 ) ;
} else if ( V_18 -> V_13 > V_50 ) {
F_36 ( L_9
L_10 ,
V_18 -> V_13 ) ;
F_37 ( V_48 , & V_2 -> V_8 ) ;
}
F_3 ( L_11 ) ;
V_47:
if ( V_2 -> V_44 )
F_38 ( V_40 ) ;
V_19:
F_39 ( & V_2 -> V_42 ) ;
return V_16 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_51 ;
struct V_17 V_18 = { . V_6 = V_52 ,
. V_22 = NULL , . V_26 = & V_51 ,
. V_20 = 0 , . V_24 = 1 } ;
return F_27 ( V_2 , & V_18 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_17 V_18 = { . V_6 = V_53 ,
. V_22 = NULL , . V_26 = NULL ,
. V_20 = 0 , . V_24 = 0 } ;
return ( F_1 ( V_2 ) & V_54 ) ?
F_27 ( V_2 , & V_18 ) : 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_55 , T_1 * V_7 )
{
int V_56 ;
T_1 V_51 ;
struct V_17 V_18 = { . V_6 = V_57 ,
. V_22 = & V_55 , . V_26 = & V_51 ,
. V_20 = 1 , . V_24 = 1 } ;
V_56 = F_27 ( V_2 , & V_18 ) ;
* V_7 = V_51 ;
return V_56 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_55 , T_1 V_7 )
{
T_1 V_22 [ 2 ] = { V_55 , V_7 } ;
struct V_17 V_18 = { . V_6 = V_58 ,
. V_22 = V_22 , . V_26 = NULL ,
. V_20 = 2 , . V_24 = 0 } ;
return F_27 ( V_2 , & V_18 ) ;
}
int F_44 ( void )
{
if ( ! V_59 )
return - V_46 ;
return F_40 ( V_59 ) ;
}
int F_45 ( void )
{
if ( ! V_59 )
return - V_46 ;
return F_41 ( V_59 ) ;
}
int F_46 ( T_1 V_60 , T_1 * V_61 )
{
int V_23 ;
T_1 V_62 ;
if ( ! V_59 )
return - V_46 ;
V_23 = F_42 ( V_59 , V_60 , & V_62 ) ;
if ( ! V_23 ) {
* V_61 = V_62 ;
return 0 ;
} else
return V_23 ;
}
int F_47 ( T_1 V_60 , T_1 V_61 )
{
int V_23 ;
if ( ! V_59 )
return - V_46 ;
V_23 = F_43 ( V_59 , V_60 , V_61 ) ;
return V_23 ;
}
int F_48 ( T_1 V_6 ,
const T_1 * V_22 , unsigned V_63 ,
T_1 * V_26 , unsigned V_64 )
{
struct V_17 V_18 = { . V_6 = V_6 ,
. V_22 = V_22 , . V_26 = V_26 ,
. V_20 = V_63 , . V_24 = V_64 } ;
if ( ! V_59 )
return - V_46 ;
return F_27 ( V_59 , & V_18 ) ;
}
T_3 F_49 ( void )
{
if ( ! V_59 )
return NULL ;
return V_59 -> V_65 ;
}
void F_50 ( void )
{
struct V_1 * V_2 = V_59 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_37 ( V_43 , & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
void F_51 ( void )
{
struct V_1 * V_2 = V_59 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_24 ( V_43 , & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
void F_52 ( void )
{
if ( V_59 )
F_24 ( V_43 , & V_59 -> V_8 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 * V_7 )
{
int V_56 ;
T_1 V_51 ;
struct V_17 V_18 = { . V_6 = V_39 ,
. V_22 = NULL , . V_26 = & V_51 ,
. V_20 = 0 , . V_24 = 1 } ;
if ( ! V_2 || ! V_7 )
return - V_41 ;
V_56 = F_23 ( V_2 , & V_18 ) ;
if ( V_56 )
return V_56 ;
if ( ! V_51 )
return - V_66 ;
* V_7 = V_51 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_67 ,
T_3 V_65 , T_4 V_68 ,
void * V_7 )
{
struct V_69 * V_70 =
F_55 ( sizeof( struct V_69 ) , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
V_70 -> V_67 = V_67 ;
V_70 -> V_65 = V_65 ;
V_70 -> V_68 = V_68 ;
V_70 -> V_7 = V_7 ;
F_28 ( & V_2 -> V_42 ) ;
F_56 ( & V_70 -> V_73 , & V_2 -> V_74 ) ;
F_39 ( & V_2 -> V_42 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_69 * V_70 , * V_38 ;
F_28 ( & V_2 -> V_42 ) ;
F_58 (handler, tmp, &ec->list, node) {
if ( V_67 == V_70 -> V_67 ) {
F_59 ( & V_70 -> V_73 ) ;
F_60 ( V_70 ) ;
}
}
F_39 ( & V_2 -> V_42 ) ;
}
static void F_61 ( void * V_75 )
{
struct V_69 * V_70 = V_75 ;
if ( ! V_70 )
return;
F_3 ( L_12 ) ;
if ( V_70 -> V_68 )
V_70 -> V_68 ( V_70 -> V_7 ) ;
else if ( V_70 -> V_65 )
F_62 ( V_70 -> V_65 , NULL , NULL , NULL ) ;
F_3 ( L_13 ) ;
F_60 ( V_70 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_76 = 0 ;
int V_16 ;
struct V_69 * V_70 , * V_77 ;
if ( ( V_16 = F_53 ( V_2 , & V_76 ) ) )
return V_16 ;
F_63 (handler, &ec->list, node) {
if ( V_76 == V_70 -> V_67 ) {
V_77 = F_64 ( sizeof( * V_70 ) , V_71 ) ;
if ( ! V_77 )
return - V_72 ;
memcpy ( V_77 , V_70 , sizeof( * V_77 ) ) ;
F_3 ( L_14 ,
V_76 ) ;
return F_65 ( ( V_77 -> V_68 ) ?
V_78 : V_79 ,
F_61 , V_77 ) ;
}
}
return 0 ;
}
static void F_66 ( void * V_80 )
{
struct V_1 * V_2 = V_80 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_16 ( V_2 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_28 )
{
if ( V_28 & V_27 ) {
if ( ! F_15 ( V_29 , & V_2 -> V_8 ) ) {
F_3 ( L_15 ) ;
return F_65 ( V_78 ,
F_66 , V_2 ) ;
}
}
return 0 ;
}
static T_2 F_68 ( T_3 V_81 ,
T_2 V_82 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_16 = F_1 ( V_2 ) ;
F_3 ( L_16 , V_16 ) ;
F_12 ( V_2 , V_16 ) ;
if ( F_8 ( V_2 ) &&
( F_1 ( V_2 ) & V_21 ) == 0 ) {
F_69 ( & V_2 -> V_36 ) ;
F_67 ( V_2 , F_1 ( V_2 ) ) ;
}
return V_83 | V_84 ;
}
static T_5
F_70 ( T_2 V_85 , T_6 V_55 ,
T_2 V_86 , T_7 * V_87 ,
void * V_88 , void * V_89 )
{
struct V_1 * V_2 = V_88 ;
int V_56 = 0 , V_90 , V_91 = V_86 / 8 ;
T_1 * V_76 = ( T_1 * ) V_87 ;
if ( ( V_55 > 0xFF ) || ! V_76 || ! V_88 )
return V_92 ;
if ( V_85 != V_93 && V_85 != V_94 )
return V_92 ;
if ( V_34 || V_86 > 8 )
F_40 ( V_2 ) ;
for ( V_90 = 0 ; V_90 < V_91 ; ++ V_90 , ++ V_55 , ++ V_76 )
V_56 = ( V_85 == V_93 ) ?
F_42 ( V_2 , V_55 , V_76 ) :
F_43 ( V_2 , V_55 , * V_76 ) ;
if ( V_34 || V_86 > 8 )
F_41 ( V_2 ) ;
switch ( V_56 ) {
case - V_41 :
return V_92 ;
break;
case - V_46 :
return V_95 ;
break;
case - V_37 :
return V_96 ;
break;
default:
return V_97 ;
}
}
static struct V_1 * F_71 ( void )
{
struct V_1 * V_2 = F_55 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = 1 << V_29 ;
F_72 ( & V_2 -> V_42 ) ;
F_73 ( & V_2 -> V_36 ) ;
F_74 ( & V_2 -> V_74 ) ;
F_75 ( & V_2 -> V_10 ) ;
return V_2 ;
}
static T_5
F_76 ( T_3 V_65 , T_2 V_98 ,
void * V_99 , void * * V_100 )
{
char V_101 [ 5 ] ;
struct V_102 V_103 = { sizeof( V_101 ) , V_101 } ;
struct V_1 * V_2 = V_99 ;
int V_76 = 0 ;
T_5 V_16 ;
V_16 = F_77 ( V_65 , V_104 , & V_103 ) ;
if ( F_78 ( V_16 ) && sscanf ( V_101 , L_17 , & V_76 ) == 1 ) {
F_54 ( V_2 , V_76 , V_65 , NULL , NULL ) ;
}
return V_97 ;
}
static T_5
F_79 ( T_3 V_65 , T_2 V_105 , void * V_99 , void * * V_106 )
{
T_5 V_16 ;
unsigned long long V_38 = 0 ;
struct V_1 * V_2 = V_99 ;
V_2 -> V_4 = V_2 -> V_5 = 0 ;
V_16 = F_80 ( V_65 , V_107 ,
V_108 , V_2 ) ;
if ( F_31 ( V_16 ) )
return V_16 ;
V_16 = F_81 ( V_65 , L_18 , NULL , & V_38 ) ;
if ( F_31 ( V_16 ) )
return V_16 ;
V_2 -> V_49 = V_38 ;
V_38 = 0 ;
F_81 ( V_65 , L_19 , NULL , & V_38 ) ;
V_2 -> V_44 = V_38 ;
V_2 -> V_65 = V_65 ;
return V_109 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_5 V_16 ;
if ( F_29 ( V_110 , & V_2 -> V_8 ) )
return 0 ;
V_16 = F_83 ( NULL , V_2 -> V_49 ,
V_111 ,
& F_68 , V_2 ) ;
if ( F_31 ( V_16 ) )
return - V_46 ;
F_35 ( NULL , V_2 -> V_49 ) ;
V_16 = F_84 ( V_2 -> V_65 ,
V_112 ,
& F_70 ,
NULL , V_2 ) ;
if ( F_31 ( V_16 ) ) {
if ( V_16 == V_95 ) {
F_32 ( L_20
L_21 ) ;
} else {
F_85 ( NULL , V_2 -> V_49 ,
& F_68 ) ;
F_33 ( NULL , V_2 -> V_49 ) ;
return - V_46 ;
}
}
F_37 ( V_110 , & V_2 -> V_8 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_33 ( NULL , V_2 -> V_49 ) ;
if ( F_31 ( F_87 ( V_2 -> V_65 ,
V_112 , & F_70 ) ) )
F_32 ( L_22 ) ;
if ( F_31 ( F_85 ( NULL , V_2 -> V_49 ,
& F_68 ) ) )
F_32 ( L_23 ) ;
F_24 ( V_110 , & V_2 -> V_8 ) ;
}
static int F_88 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = NULL ;
int V_9 ;
strcpy ( F_89 ( V_114 ) , V_115 ) ;
strcpy ( F_90 ( V_114 ) , V_116 ) ;
if ( V_117 &&
( V_117 -> V_65 == V_114 -> V_65 ||
V_117 -> V_65 == V_118 ) ) {
V_2 = V_117 ;
V_117 = NULL ;
} else {
V_2 = F_71 () ;
if ( ! V_2 )
return - V_72 ;
}
if ( F_79 ( V_114 -> V_65 , 0 , V_2 , NULL ) !=
V_109 ) {
F_60 ( V_2 ) ;
return - V_41 ;
}
F_91 ( V_119 , V_2 -> V_65 , 1 ,
F_76 , NULL , V_2 , NULL ) ;
if ( ! V_59 )
V_59 = V_2 ;
V_114 -> V_120 = V_2 ;
V_9 = ! ! F_92 ( V_2 -> V_5 , 1 , L_24 ) ;
F_93 ( ! V_9 , L_25 , V_2 -> V_5 ) ;
V_9 = ! ! F_92 ( V_2 -> V_4 , 1 , L_26 ) ;
F_93 ( ! V_9 , L_27 , V_2 -> V_4 ) ;
F_36 ( L_28 ,
V_2 -> V_49 , V_2 -> V_4 , V_2 -> V_5 ) ;
V_9 = F_82 ( V_2 ) ;
F_24 ( V_29 , & V_2 -> V_8 ) ;
return V_9 ;
}
static int F_94 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_69 * V_70 , * V_38 ;
if ( ! V_114 )
return - V_41 ;
V_2 = F_95 ( V_114 ) ;
F_86 ( V_2 ) ;
F_28 ( & V_2 -> V_42 ) ;
F_58 (handler, tmp, &ec->list, node) {
F_59 ( & V_70 -> V_73 ) ;
F_60 ( V_70 ) ;
}
F_39 ( & V_2 -> V_42 ) ;
F_96 ( V_2 -> V_5 , 1 ) ;
F_96 ( V_2 -> V_4 , 1 ) ;
V_114 -> V_120 = NULL ;
if ( V_2 == V_59 )
V_59 = NULL ;
F_60 ( V_2 ) ;
return 0 ;
}
static T_5
V_108 ( struct V_121 * V_122 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
if ( V_122 -> type != V_123 )
return V_97 ;
if ( V_2 -> V_5 == 0 )
V_2 -> V_5 = V_122 -> V_7 . V_124 . V_125 ;
else if ( V_2 -> V_4 == 0 )
V_2 -> V_4 = V_122 -> V_7 . V_124 . V_125 ;
else
return V_109 ;
return V_97 ;
}
int T_8 F_97 ( void )
{
if ( ! V_117 || F_29 ( V_110 , & V_117 -> V_8 ) )
return 0 ;
if ( ! F_82 ( V_117 ) ) {
V_59 = V_117 ;
return 0 ;
}
return - V_126 ;
}
static int F_98 ( const struct V_127 * V_128 )
{
V_129 = 1 ;
return 0 ;
}
static int F_99 ( const struct V_127 * V_128 )
{
V_130 = 1 ;
return 0 ;
}
static int F_100 ( const struct V_127 * V_128 )
{
F_3 ( L_29 ) ;
V_34 = 1 ;
V_130 = 1 ;
return 0 ;
}
static int F_101 ( const struct V_127 * V_128 )
{
F_3 ( L_30 ) ;
V_50 = 20 ;
return 0 ;
}
int T_8 F_102 ( void )
{
T_5 V_16 ;
struct V_1 * V_131 = NULL ;
struct V_132 * V_133 ;
V_117 = F_71 () ;
if ( ! V_117 )
return - V_72 ;
F_103 ( V_134 ) ;
V_16 = F_104 ( V_135 , 1 ,
(struct V_136 * * ) & V_133 ) ;
if ( F_78 ( V_16 ) ) {
F_36 ( L_31 ) ;
V_117 -> V_4 = V_133 -> V_137 . V_55 ;
V_117 -> V_5 = V_133 -> V_7 . V_55 ;
V_117 -> V_49 = V_133 -> V_49 ;
V_117 -> V_65 = V_118 ;
F_105 ( V_118 , V_133 -> V_128 , & V_117 -> V_65 ) ;
if ( ! V_130 )
goto V_138;
V_131 = F_106 ( V_117 , sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_131 )
return - V_72 ;
}
if ( V_129 )
return - V_46 ;
F_3 ( L_32 ) ;
V_16 = F_107 ( V_139 [ 0 ] . V_128 , F_79 ,
V_117 , NULL ) ;
if ( F_31 ( V_16 ) || ! V_117 -> V_65 )
goto error;
if ( V_131 ) {
if ( V_131 -> V_4 != V_117 -> V_4 ||
V_131 -> V_5 != V_117 -> V_5 ||
V_131 -> V_49 != V_117 -> V_49 ||
V_131 -> V_65 != V_117 -> V_65 )
F_36 ( L_33
L_34
L_35
L_36 ) ;
F_60 ( V_131 ) ;
V_131 = NULL ;
} else {
if ( ! F_108 ( L_37 ) ||
! F_109 ( V_117 -> V_65 , L_38 ) )
return - V_46 ;
}
V_138:
if ( ! F_82 ( V_117 ) ) {
V_59 = V_117 ;
return 0 ;
}
error:
F_60 ( V_117 ) ;
V_117 = NULL ;
return - V_46 ;
}
int T_8 F_110 ( void )
{
int V_56 = 0 ;
V_56 = F_111 ( & V_140 ) ;
if ( V_56 < 0 )
return - V_46 ;
return V_56 ;
}
