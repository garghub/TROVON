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
return F_16 ( V_2 , NULL ) ;
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
int F_44 ( T_1 V_59 , T_1 * V_60 )
{
int V_23 ;
T_1 V_61 ;
if ( ! V_62 )
return - V_46 ;
V_23 = F_42 ( V_62 , V_59 , & V_61 ) ;
if ( ! V_23 ) {
* V_60 = V_61 ;
return 0 ;
} else
return V_23 ;
}
int F_45 ( T_1 V_59 , T_1 V_60 )
{
int V_23 ;
if ( ! V_62 )
return - V_46 ;
V_23 = F_43 ( V_62 , V_59 , V_60 ) ;
return V_23 ;
}
int F_46 ( T_1 V_6 ,
const T_1 * V_22 , unsigned V_63 ,
T_1 * V_26 , unsigned V_64 )
{
struct V_17 V_18 = { . V_6 = V_6 ,
. V_22 = V_22 , . V_26 = V_26 ,
. V_20 = V_63 , . V_24 = V_64 } ;
if ( ! V_62 )
return - V_46 ;
return F_27 ( V_62 , & V_18 ) ;
}
T_3 F_47 ( void )
{
if ( ! V_62 )
return NULL ;
return V_62 -> V_65 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_66 , V_16 ;
T_1 V_67 = 0 ;
for ( V_66 = 0 ; V_66 < V_68 ; V_66 ++ ) {
V_16 = F_16 ( V_2 , & V_67 ) ;
if ( V_16 || ! V_67 )
break;
}
if ( F_49 ( V_66 == V_68 ) )
F_50 ( L_12 , V_66 ) ;
else
F_36 ( L_13 , V_66 ) ;
}
void F_51 ( void )
{
struct V_1 * V_2 = V_62 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_37 ( V_43 , & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
void F_52 ( void )
{
struct V_1 * V_2 = V_62 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_24 ( V_43 , & V_2 -> V_8 ) ;
if ( V_69 )
F_48 ( V_2 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
void F_53 ( void )
{
if ( V_62 )
F_24 ( V_43 , & V_62 -> V_8 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 * V_7 )
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
return - V_70 ;
* V_7 = V_51 ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , T_1 V_71 ,
T_3 V_65 , T_4 V_72 ,
void * V_7 )
{
struct V_73 * V_74 =
F_56 ( sizeof( struct V_73 ) , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_74 -> V_71 = V_71 ;
V_74 -> V_65 = V_65 ;
V_74 -> V_72 = V_72 ;
V_74 -> V_7 = V_7 ;
F_28 ( & V_2 -> V_42 ) ;
F_57 ( & V_74 -> V_77 , & V_2 -> V_78 ) ;
F_39 ( & V_2 -> V_42 ) ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_73 * V_74 , * V_38 ;
F_28 ( & V_2 -> V_42 ) ;
F_59 (handler, tmp, &ec->list, node) {
if ( V_71 == V_74 -> V_71 ) {
F_60 ( & V_74 -> V_77 ) ;
F_61 ( V_74 ) ;
}
}
F_39 ( & V_2 -> V_42 ) ;
}
static void F_62 ( void * V_79 )
{
struct V_73 * V_74 = V_79 ;
if ( ! V_74 )
return;
F_3 ( L_14 ) ;
if ( V_74 -> V_72 )
V_74 -> V_72 ( V_74 -> V_7 ) ;
else if ( V_74 -> V_65 )
F_63 ( V_74 -> V_65 , NULL , NULL , NULL ) ;
F_3 ( L_15 ) ;
F_61 ( V_74 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_7 )
{
T_1 V_67 = 0 ;
int V_16 ;
struct V_73 * V_74 , * V_80 ;
V_16 = F_54 ( V_2 , & V_67 ) ;
if ( V_7 )
* V_7 = V_67 ;
if ( V_16 )
return V_16 ;
F_64 (handler, &ec->list, node) {
if ( V_67 == V_74 -> V_71 ) {
V_80 = F_65 ( sizeof( * V_74 ) , V_75 ) ;
if ( ! V_80 )
return - V_76 ;
memcpy ( V_80 , V_74 , sizeof( * V_80 ) ) ;
F_3 ( L_16 ,
V_67 ) ;
return F_66 ( ( V_80 -> V_72 ) ?
V_81 : V_82 ,
F_62 , V_80 ) ;
}
}
return 0 ;
}
static void F_67 ( void * V_83 )
{
struct V_1 * V_2 = V_83 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_42 ) ;
F_16 ( V_2 , NULL ) ;
F_39 ( & V_2 -> V_42 ) ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_28 )
{
if ( V_28 & V_27 ) {
if ( ! F_15 ( V_29 , & V_2 -> V_8 ) ) {
F_3 ( L_17 ) ;
return F_66 ( V_81 ,
F_67 , V_2 ) ;
}
}
return 0 ;
}
static T_2 F_69 ( T_3 V_84 ,
T_2 V_85 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_16 = F_1 ( V_2 ) ;
F_3 ( L_18 , V_16 ) ;
F_12 ( V_2 , V_16 ) ;
if ( F_8 ( V_2 ) &&
( F_1 ( V_2 ) & V_21 ) == 0 ) {
F_70 ( & V_2 -> V_36 ) ;
F_68 ( V_2 , F_1 ( V_2 ) ) ;
}
return V_86 | V_87 ;
}
static T_5
F_71 ( T_2 V_88 , T_6 V_55 ,
T_2 V_89 , T_7 * V_90 ,
void * V_91 , void * V_92 )
{
struct V_1 * V_2 = V_91 ;
int V_56 = 0 , V_66 , V_93 = V_89 / 8 ;
T_1 * V_67 = ( T_1 * ) V_90 ;
if ( ( V_55 > 0xFF ) || ! V_67 || ! V_91 )
return V_94 ;
if ( V_88 != V_95 && V_88 != V_96 )
return V_94 ;
if ( V_34 || V_89 > 8 )
F_40 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_93 ; ++ V_66 , ++ V_55 , ++ V_67 )
V_56 = ( V_88 == V_95 ) ?
F_42 ( V_2 , V_55 , V_67 ) :
F_43 ( V_2 , V_55 , * V_67 ) ;
if ( V_34 || V_89 > 8 )
F_41 ( V_2 ) ;
switch ( V_56 ) {
case - V_41 :
return V_94 ;
break;
case - V_46 :
return V_97 ;
break;
case - V_37 :
return V_98 ;
break;
default:
return V_99 ;
}
}
static struct V_1 * F_72 ( void )
{
struct V_1 * V_2 = F_56 ( sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = 1 << V_29 ;
F_73 ( & V_2 -> V_42 ) ;
F_74 ( & V_2 -> V_36 ) ;
F_75 ( & V_2 -> V_78 ) ;
F_76 ( & V_2 -> V_10 ) ;
return V_2 ;
}
static T_5
F_77 ( T_3 V_65 , T_2 V_100 ,
void * V_101 , void * * V_102 )
{
char V_103 [ 5 ] ;
struct V_104 V_105 = { sizeof( V_103 ) , V_103 } ;
struct V_1 * V_2 = V_101 ;
int V_67 = 0 ;
T_5 V_16 ;
V_16 = F_78 ( V_65 , V_106 , & V_105 ) ;
if ( F_79 ( V_16 ) && sscanf ( V_103 , L_19 , & V_67 ) == 1 ) {
F_55 ( V_2 , V_67 , V_65 , NULL , NULL ) ;
}
return V_99 ;
}
static T_5
F_80 ( T_3 V_65 , T_2 V_107 , void * V_101 , void * * V_108 )
{
T_5 V_16 ;
unsigned long long V_38 = 0 ;
struct V_1 * V_2 = V_101 ;
V_2 -> V_4 = V_2 -> V_5 = 0 ;
V_16 = F_81 ( V_65 , V_109 ,
V_110 , V_2 ) ;
if ( F_31 ( V_16 ) )
return V_16 ;
V_16 = F_82 ( V_65 , L_20 , NULL , & V_38 ) ;
if ( F_31 ( V_16 ) )
return V_16 ;
V_2 -> V_49 = V_38 ;
V_38 = 0 ;
F_82 ( V_65 , L_21 , NULL , & V_38 ) ;
V_2 -> V_44 = V_38 ;
V_2 -> V_65 = V_65 ;
return V_111 ;
}
static int F_83 ( struct V_1 * V_2 )
{
T_5 V_16 ;
if ( F_29 ( V_112 , & V_2 -> V_8 ) )
return 0 ;
V_16 = F_84 ( NULL , V_2 -> V_49 ,
V_113 ,
& F_69 , V_2 ) ;
if ( F_31 ( V_16 ) )
return - V_46 ;
F_35 ( NULL , V_2 -> V_49 ) ;
V_16 = F_85 ( V_2 -> V_65 ,
V_114 ,
& F_71 ,
NULL , V_2 ) ;
if ( F_31 ( V_16 ) ) {
if ( V_16 == V_97 ) {
F_32 ( L_22
L_23 ) ;
} else {
F_33 ( NULL , V_2 -> V_49 ) ;
F_86 ( NULL , V_2 -> V_49 ,
& F_69 ) ;
return - V_46 ;
}
}
F_37 ( V_112 , & V_2 -> V_8 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_33 ( NULL , V_2 -> V_49 ) ;
if ( F_31 ( F_88 ( V_2 -> V_65 ,
V_114 , & F_71 ) ) )
F_32 ( L_24 ) ;
if ( F_31 ( F_86 ( NULL , V_2 -> V_49 ,
& F_69 ) ) )
F_32 ( L_25 ) ;
F_24 ( V_112 , & V_2 -> V_8 ) ;
}
static int F_89 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = NULL ;
int V_9 ;
strcpy ( F_90 ( V_116 ) , V_117 ) ;
strcpy ( F_91 ( V_116 ) , V_118 ) ;
if ( V_119 &&
( V_119 -> V_65 == V_116 -> V_65 ||
V_119 -> V_65 == V_120 ) ) {
V_2 = V_119 ;
V_119 = NULL ;
} else {
V_2 = F_72 () ;
if ( ! V_2 )
return - V_76 ;
}
if ( F_80 ( V_116 -> V_65 , 0 , V_2 , NULL ) !=
V_111 ) {
F_61 ( V_2 ) ;
return - V_41 ;
}
F_92 ( V_121 , V_2 -> V_65 , 1 ,
F_77 , NULL , V_2 , NULL ) ;
if ( ! V_62 )
V_62 = V_2 ;
V_116 -> V_122 = V_2 ;
V_9 = ! ! F_93 ( V_2 -> V_5 , 1 , L_26 ) ;
F_94 ( ! V_9 , L_27 , V_2 -> V_5 ) ;
V_9 = ! ! F_93 ( V_2 -> V_4 , 1 , L_28 ) ;
F_94 ( ! V_9 , L_29 , V_2 -> V_4 ) ;
F_36 ( L_30 ,
V_2 -> V_49 , V_2 -> V_4 , V_2 -> V_5 ) ;
V_9 = F_83 ( V_2 ) ;
F_24 ( V_29 , & V_2 -> V_8 ) ;
if ( V_69 ) {
F_28 ( & V_2 -> V_42 ) ;
F_48 ( V_2 ) ;
F_39 ( & V_2 -> V_42 ) ;
}
return V_9 ;
}
static int F_95 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 , * V_38 ;
if ( ! V_116 )
return - V_41 ;
V_2 = F_96 ( V_116 ) ;
F_87 ( V_2 ) ;
F_28 ( & V_2 -> V_42 ) ;
F_59 (handler, tmp, &ec->list, node) {
F_60 ( & V_74 -> V_77 ) ;
F_61 ( V_74 ) ;
}
F_39 ( & V_2 -> V_42 ) ;
F_97 ( V_2 -> V_5 , 1 ) ;
F_97 ( V_2 -> V_4 , 1 ) ;
V_116 -> V_122 = NULL ;
if ( V_2 == V_62 )
V_62 = NULL ;
F_61 ( V_2 ) ;
return 0 ;
}
static T_5
V_110 ( struct V_123 * V_124 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
if ( V_124 -> type != V_125 )
return V_99 ;
if ( V_2 -> V_5 == 0 )
V_2 -> V_5 = V_124 -> V_7 . V_126 . V_127 ;
else if ( V_2 -> V_4 == 0 )
V_2 -> V_4 = V_124 -> V_7 . V_126 . V_127 ;
else
return V_111 ;
return V_99 ;
}
int T_8 F_98 ( void )
{
if ( ! V_119 || F_29 ( V_112 , & V_119 -> V_8 ) )
return 0 ;
if ( ! F_83 ( V_119 ) ) {
V_62 = V_119 ;
return 0 ;
}
return - V_128 ;
}
static int F_99 ( const struct V_129 * V_130 )
{
V_131 = 1 ;
return 0 ;
}
static int F_100 ( const struct V_129 * V_130 )
{
V_132 = 1 ;
return 0 ;
}
static int F_101 ( const struct V_129 * V_130 )
{
F_3 ( L_31 ) ;
V_34 = 1 ;
V_132 = 1 ;
return 0 ;
}
static int F_102 ( const struct V_129 * V_130 )
{
F_3 ( L_32 ) ;
V_50 = 20 ;
return 0 ;
}
static int F_103 ( const struct V_129 * V_130 )
{
F_3 ( L_33 ) ;
V_69 = 1 ;
return 0 ;
}
int T_8 F_104 ( void )
{
T_5 V_16 ;
struct V_1 * V_133 = NULL ;
struct V_134 * V_135 ;
V_119 = F_72 () ;
if ( ! V_119 )
return - V_76 ;
F_105 ( V_136 ) ;
V_16 = F_106 ( V_137 , 1 ,
(struct V_138 * * ) & V_135 ) ;
if ( F_79 ( V_16 ) ) {
F_36 ( L_34 ) ;
V_119 -> V_4 = V_135 -> V_139 . V_55 ;
V_119 -> V_5 = V_135 -> V_7 . V_55 ;
V_119 -> V_49 = V_135 -> V_49 ;
V_119 -> V_65 = V_120 ;
F_107 ( V_120 , V_135 -> V_130 , & V_119 -> V_65 ) ;
if ( ! V_132 )
goto V_140;
V_133 = F_108 ( V_119 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_133 )
return - V_76 ;
}
if ( V_131 )
return - V_46 ;
F_3 ( L_35 ) ;
V_16 = F_109 ( V_141 [ 0 ] . V_130 , F_80 ,
V_119 , NULL ) ;
if ( F_31 ( V_16 ) || ! V_119 -> V_65 )
goto error;
if ( V_133 ) {
if ( V_133 -> V_4 != V_119 -> V_4 ||
V_133 -> V_5 != V_119 -> V_5 ||
V_133 -> V_49 != V_119 -> V_49 ||
V_133 -> V_65 != V_119 -> V_65 )
F_36 ( L_36
L_37
L_38
L_39 ) ;
F_61 ( V_133 ) ;
V_133 = NULL ;
} else {
if ( ! F_110 ( L_40 ) ||
! F_111 ( V_119 -> V_65 , L_41 ) )
return - V_46 ;
}
V_140:
if ( ! F_83 ( V_119 ) ) {
V_62 = V_119 ;
return 0 ;
}
error:
F_61 ( V_119 ) ;
V_119 = NULL ;
return - V_46 ;
}
int T_8 F_112 ( void )
{
int V_56 = 0 ;
V_56 = F_113 ( & V_142 ) ;
if ( V_56 < 0 )
return - V_46 ;
return V_56 ;
}
