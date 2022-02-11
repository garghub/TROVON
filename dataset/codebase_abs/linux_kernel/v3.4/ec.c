static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( V_5 L_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_5 L_2 , V_3 ) ;
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
F_3 ( V_5 L_3 , V_7 ) ;
F_6 ( V_7 , V_2 -> V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_8 )
{
F_3 ( V_5 L_4 , V_8 ) ;
F_6 ( V_8 , V_2 -> V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_10 = 0 ;
F_9 ( & V_2 -> V_11 , V_9 ) ;
if ( ! V_2 -> V_12 || V_2 -> V_12 -> V_13 )
V_10 = 1 ;
F_10 ( & V_2 -> V_11 , V_9 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_12 -> V_14 = V_2 -> V_12 -> V_15 = V_2 -> V_12 -> V_16 = 0 ;
V_2 -> V_12 -> V_13 = false ;
F_5 ( V_2 , V_2 -> V_12 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_17 )
{
unsigned long V_9 ;
F_9 ( & V_2 -> V_11 , V_9 ) ;
if ( ! V_2 -> V_12 )
goto V_18;
if ( V_2 -> V_12 -> V_19 > V_2 -> V_12 -> V_15 ) {
if ( ( V_17 & V_20 ) == 0 )
F_7 ( V_2 ,
V_2 -> V_12 -> V_21 [ V_2 -> V_12 -> V_15 ++ ] ) ;
else
goto V_22;
} else if ( V_2 -> V_12 -> V_23 > V_2 -> V_12 -> V_16 ) {
if ( ( V_17 & V_24 ) == 1 ) {
V_2 -> V_12 -> V_25 [ V_2 -> V_12 -> V_16 ++ ] = F_4 ( V_2 ) ;
if ( V_2 -> V_12 -> V_23 == V_2 -> V_12 -> V_16 )
V_2 -> V_12 -> V_13 = true ;
} else
goto V_22;
} else if ( V_2 -> V_12 -> V_19 == V_2 -> V_12 -> V_15 &&
( V_17 & V_20 ) == 0 )
V_2 -> V_12 -> V_13 = true ;
goto V_18;
V_22:
if ( F_13 () )
++ V_2 -> V_12 -> V_14 ;
V_18:
F_10 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_26 )
{
if ( V_26 & V_27 ) {
if ( ! F_15 ( V_28 , & V_2 -> V_9 ) )
return F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_29 = 2 ;
while ( V_29 -- ) {
unsigned long V_30 = V_31 +
F_18 ( V_32 ) ;
do {
if ( V_33 || F_19 () ) {
F_20 ( V_34 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
} else {
if ( F_21 ( V_2 -> V_35 ,
F_8 ( V_2 ) ,
F_18 ( 1 ) ) )
return 0 ;
}
F_12 ( V_2 , F_1 ( V_2 ) ) ;
} while ( F_22 ( V_31 , V_30 ) );
if ( F_1 ( V_2 ) & V_20 )
break;
F_3 ( V_5 L_5 ) ;
F_9 ( & V_2 -> V_11 , V_9 ) ;
F_11 ( V_2 ) ;
F_10 ( & V_2 -> V_11 , V_9 ) ;
}
return - V_36 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
unsigned long V_39 ;
int V_10 = 0 ;
if ( V_33 )
F_20 ( V_34 ) ;
F_9 ( & V_2 -> V_11 , V_39 ) ;
V_2 -> V_12 = V_38 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_12 -> V_7 == V_40 )
F_24 ( V_28 , & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_11 , V_39 ) ;
V_10 = F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_11 , V_39 ) ;
V_2 -> V_12 = NULL ;
F_10 ( & V_2 -> V_11 , V_39 ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_17 = F_1 ( V_2 ) ;
return ( V_17 & V_20 ) == 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_30 = V_31 + F_18 ( V_32 ) ;
while ( F_22 ( V_31 , V_30 ) )
if ( F_21 ( V_2 -> V_35 , F_25 ( V_2 ) ,
F_18 ( 1 ) ) )
return 0 ;
return - V_36 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_17 ;
T_2 V_41 ;
if ( ! V_2 || ( ! V_38 ) || ( V_38 -> V_19 && ! V_38 -> V_21 ) || ( V_38 -> V_23 && ! V_38 -> V_25 ) )
return - V_42 ;
if ( V_38 -> V_25 )
memset ( V_38 -> V_25 , 0 , V_38 -> V_23 ) ;
F_28 ( & V_2 -> V_43 ) ;
if ( F_29 ( V_44 , & V_2 -> V_9 ) ) {
V_17 = - V_42 ;
goto V_18;
}
if ( V_2 -> V_45 ) {
V_17 = F_30 ( V_46 , & V_41 ) ;
if ( F_31 ( V_17 ) ) {
V_17 = - V_47 ;
goto V_18;
}
}
if ( F_26 ( V_2 ) ) {
F_32 ( V_5 L_6
L_7 ) ;
V_17 = - V_36 ;
goto V_48;
}
F_3 ( V_5 L_8 ) ;
if ( F_29 ( V_49 , & V_2 -> V_9 ) ) {
F_33 ( NULL , V_2 -> V_50 ) ;
}
V_17 = F_23 ( V_2 , V_38 ) ;
F_14 ( V_2 , F_1 ( V_2 ) ) ;
if ( F_29 ( V_49 , & V_2 -> V_9 ) ) {
F_34 ( 1 ) ;
F_35 ( NULL , V_2 -> V_50 ) ;
} else if ( V_38 -> V_14 > V_51 ) {
F_36 ( V_5 L_9
L_10 ) ;
F_37 ( V_49 , & V_2 -> V_9 ) ;
}
F_3 ( V_5 L_11 ) ;
V_48:
if ( V_2 -> V_45 )
F_38 ( V_41 ) ;
V_18:
F_39 ( & V_2 -> V_43 ) ;
return V_17 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_52 ;
struct V_37 V_38 = { . V_7 = V_53 ,
. V_21 = NULL , . V_25 = & V_52 ,
. V_19 = 0 , . V_23 = 1 } ;
return F_27 ( V_2 , & V_38 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_37 V_38 = { . V_7 = V_54 ,
. V_21 = NULL , . V_25 = NULL ,
. V_19 = 0 , . V_23 = 0 } ;
return ( F_1 ( V_2 ) & V_55 ) ?
F_27 ( V_2 , & V_38 ) : 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_56 , T_1 * V_8 )
{
int V_57 ;
T_1 V_52 ;
struct V_37 V_38 = { . V_7 = V_58 ,
. V_21 = & V_56 , . V_25 = & V_52 ,
. V_19 = 1 , . V_23 = 1 } ;
V_57 = F_27 ( V_2 , & V_38 ) ;
* V_8 = V_52 ;
return V_57 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_56 , T_1 V_8 )
{
T_1 V_21 [ 2 ] = { V_56 , V_8 } ;
struct V_37 V_38 = { . V_7 = V_59 ,
. V_21 = V_21 , . V_25 = NULL ,
. V_19 = 2 , . V_23 = 0 } ;
return F_27 ( V_2 , & V_38 ) ;
}
int F_44 ( void )
{
if ( ! V_60 )
return - V_47 ;
return F_40 ( V_60 ) ;
}
int F_45 ( void )
{
if ( ! V_60 )
return - V_47 ;
return F_41 ( V_60 ) ;
}
int F_46 ( T_1 V_61 , T_1 * V_62 )
{
int V_22 ;
T_1 V_63 ;
if ( ! V_60 )
return - V_47 ;
V_22 = F_42 ( V_60 , V_61 , & V_63 ) ;
if ( ! V_22 ) {
* V_62 = V_63 ;
return 0 ;
} else
return V_22 ;
}
int F_47 ( T_1 V_61 , T_1 V_62 )
{
int V_22 ;
if ( ! V_60 )
return - V_47 ;
V_22 = F_43 ( V_60 , V_61 , V_62 ) ;
return V_22 ;
}
int F_48 ( T_1 V_7 ,
const T_1 * V_21 , unsigned V_64 ,
T_1 * V_25 , unsigned V_65 )
{
struct V_37 V_38 = { . V_7 = V_7 ,
. V_21 = V_21 , . V_25 = V_25 ,
. V_19 = V_64 , . V_23 = V_65 } ;
if ( ! V_60 )
return - V_47 ;
return F_27 ( V_60 , & V_38 ) ;
}
T_3 F_49 ( void )
{
if ( ! V_60 )
return NULL ;
return V_60 -> V_66 ;
}
void F_50 ( void )
{
struct V_1 * V_2 = V_60 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_43 ) ;
F_37 ( V_44 , & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_43 ) ;
}
void F_51 ( void )
{
struct V_1 * V_2 = V_60 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_43 ) ;
F_24 ( V_44 , & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_43 ) ;
}
void F_52 ( void )
{
if ( V_60 )
F_24 ( V_44 , & V_60 -> V_9 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 * V_8 )
{
int V_57 ;
T_1 V_52 ;
struct V_37 V_38 = { . V_7 = V_40 ,
. V_21 = NULL , . V_25 = & V_52 ,
. V_19 = 0 , . V_23 = 1 } ;
if ( ! V_2 || ! V_8 )
return - V_42 ;
V_57 = F_23 ( V_2 , & V_38 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_52 )
return - V_67 ;
* V_8 = V_52 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_68 ,
T_3 V_66 , T_4 V_69 ,
void * V_8 )
{
struct V_70 * V_71 =
F_55 ( sizeof( struct V_70 ) , V_72 ) ;
if ( ! V_71 )
return - V_73 ;
V_71 -> V_68 = V_68 ;
V_71 -> V_66 = V_66 ;
V_71 -> V_69 = V_69 ;
V_71 -> V_8 = V_8 ;
F_28 ( & V_2 -> V_43 ) ;
F_56 ( & V_71 -> V_74 , & V_2 -> V_75 ) ;
F_39 ( & V_2 -> V_43 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_70 * V_71 , * V_39 ;
F_28 ( & V_2 -> V_43 ) ;
F_58 (handler, tmp, &ec->list, node) {
if ( V_68 == V_71 -> V_68 ) {
F_59 ( & V_71 -> V_74 ) ;
F_60 ( V_71 ) ;
}
}
F_39 ( & V_2 -> V_43 ) ;
}
static void F_61 ( void * V_76 )
{
struct V_70 * V_71 = V_76 ;
if ( ! V_71 )
return;
F_3 ( V_5 L_12 ) ;
if ( V_71 -> V_69 )
V_71 -> V_69 ( V_71 -> V_8 ) ;
else if ( V_71 -> V_66 )
F_62 ( V_71 -> V_66 , NULL , NULL , NULL ) ;
F_3 ( V_5 L_13 ) ;
F_60 ( V_71 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_77 = 0 ;
int V_17 ;
struct V_70 * V_71 , * V_78 ;
if ( ( V_17 = F_53 ( V_2 , & V_77 ) ) )
return V_17 ;
F_63 (handler, &ec->list, node) {
if ( V_77 == V_71 -> V_68 ) {
V_78 = F_64 ( sizeof( * V_71 ) , V_72 ) ;
if ( ! V_78 )
return - V_73 ;
memcpy ( V_78 , V_71 , sizeof( * V_78 ) ) ;
F_3 ( V_5 L_14 , V_77 ) ;
return F_65 ( ( V_78 -> V_69 ) ?
V_79 : V_80 ,
F_61 , V_78 ) ;
}
}
return 0 ;
}
static void F_66 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_43 ) ;
F_16 ( V_2 ) ;
F_39 ( & V_2 -> V_43 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_26 )
{
if ( V_26 & V_27 ) {
if ( ! F_15 ( V_28 , & V_2 -> V_9 ) ) {
F_3 ( V_5 L_15 ) ;
return F_65 ( V_79 ,
F_66 , V_2 ) ;
}
}
return 0 ;
}
static T_2 F_68 ( T_3 V_82 ,
T_2 V_83 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
F_3 ( V_5 L_16 ) ;
F_12 ( V_2 , F_1 ( V_2 ) ) ;
if ( F_8 ( V_2 ) &&
( F_1 ( V_2 ) & V_20 ) == 0 ) {
F_69 ( & V_2 -> V_35 ) ;
F_67 ( V_2 , F_1 ( V_2 ) ) ;
}
return V_84 | V_85 ;
}
static T_5
F_70 ( T_2 V_86 , T_6 V_56 ,
T_2 V_87 , T_7 * V_88 ,
void * V_89 , void * V_90 )
{
struct V_1 * V_2 = V_89 ;
int V_57 = 0 , V_91 , V_92 = V_87 / 8 ;
T_1 * V_77 = ( T_1 * ) V_88 ;
if ( ( V_56 > 0xFF ) || ! V_77 || ! V_89 )
return V_93 ;
if ( V_86 != V_94 && V_86 != V_95 )
return V_93 ;
if ( V_33 || V_87 > 8 )
F_40 ( V_2 ) ;
for ( V_91 = 0 ; V_91 < V_92 ; ++ V_91 , ++ V_56 , ++ V_77 )
V_57 = ( V_86 == V_94 ) ?
F_42 ( V_2 , V_56 , V_77 ) :
F_43 ( V_2 , V_56 , * V_77 ) ;
if ( V_33 || V_87 > 8 )
F_41 ( V_2 ) ;
switch ( V_57 ) {
case - V_42 :
return V_93 ;
break;
case - V_47 :
return V_96 ;
break;
case - V_36 :
return V_97 ;
break;
default:
return V_98 ;
}
}
static struct V_1 * F_71 ( void )
{
struct V_1 * V_2 = F_55 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = 1 << V_28 ;
F_72 ( & V_2 -> V_43 ) ;
F_73 ( & V_2 -> V_35 ) ;
F_74 ( & V_2 -> V_75 ) ;
F_75 ( & V_2 -> V_11 ) ;
return V_2 ;
}
static T_5
F_76 ( T_3 V_66 , T_2 V_99 ,
void * V_100 , void * * V_101 )
{
char V_102 [ 5 ] ;
struct V_103 V_104 = { sizeof( V_102 ) , V_102 } ;
struct V_1 * V_2 = V_100 ;
int V_77 = 0 ;
T_5 V_17 ;
V_17 = F_77 ( V_66 , V_105 , & V_104 ) ;
if ( F_78 ( V_17 ) && sscanf ( V_102 , L_17 , & V_77 ) == 1 ) {
F_54 ( V_2 , V_77 , V_66 , NULL , NULL ) ;
}
return V_98 ;
}
static T_5
F_79 ( T_3 V_66 , T_2 V_106 , void * V_100 , void * * V_107 )
{
T_5 V_17 ;
unsigned long long V_39 = 0 ;
struct V_1 * V_2 = V_100 ;
V_2 -> V_4 = V_2 -> V_6 = 0 ;
V_17 = F_80 ( V_66 , V_108 ,
V_109 , V_2 ) ;
if ( F_31 ( V_17 ) )
return V_17 ;
V_17 = F_81 ( V_66 , L_18 , NULL , & V_39 ) ;
if ( F_31 ( V_17 ) )
return V_17 ;
V_2 -> V_50 = V_39 ;
V_39 = 0 ;
F_81 ( V_66 , L_19 , NULL , & V_39 ) ;
V_2 -> V_45 = V_39 ;
V_2 -> V_66 = V_66 ;
return V_110 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_5 V_17 ;
if ( F_29 ( V_111 , & V_2 -> V_9 ) )
return 0 ;
V_17 = F_83 ( NULL , V_2 -> V_50 ,
V_112 ,
& F_68 , V_2 ) ;
if ( F_31 ( V_17 ) )
return - V_47 ;
F_35 ( NULL , V_2 -> V_50 ) ;
V_17 = F_84 ( V_2 -> V_66 ,
V_113 ,
& F_70 ,
NULL , V_2 ) ;
if ( F_31 ( V_17 ) ) {
if ( V_17 == V_96 ) {
F_85 ( V_114 L_20
L_21 ) ;
} else {
F_86 ( NULL , V_2 -> V_50 ,
& F_68 ) ;
F_33 ( NULL , V_2 -> V_50 ) ;
return - V_47 ;
}
}
F_37 ( V_111 , & V_2 -> V_9 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_33 ( NULL , V_2 -> V_50 ) ;
if ( F_31 ( F_88 ( V_2 -> V_66 ,
V_113 , & F_70 ) ) )
F_32 ( V_5 L_22 ) ;
if ( F_31 ( F_86 ( NULL , V_2 -> V_50 ,
& F_68 ) ) )
F_32 ( V_5 L_23 ) ;
F_24 ( V_111 , & V_2 -> V_9 ) ;
}
static int F_89 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = NULL ;
int V_10 ;
strcpy ( F_90 ( V_116 ) , V_117 ) ;
strcpy ( F_91 ( V_116 ) , V_118 ) ;
if ( V_119 &&
( V_119 -> V_66 == V_116 -> V_66 ||
V_119 -> V_66 == V_120 ) ) {
V_2 = V_119 ;
V_119 = NULL ;
} else {
V_2 = F_71 () ;
if ( ! V_2 )
return - V_73 ;
}
if ( F_79 ( V_116 -> V_66 , 0 , V_2 , NULL ) !=
V_110 ) {
F_60 ( V_2 ) ;
return - V_42 ;
}
F_92 ( V_121 , V_2 -> V_66 , 1 ,
F_76 , NULL , V_2 , NULL ) ;
if ( ! V_60 )
V_60 = V_2 ;
V_116 -> V_122 = V_2 ;
V_10 = ! ! F_93 ( V_2 -> V_6 , 1 , L_24 ) ;
F_94 ( ! V_10 , L_25 , V_2 -> V_6 ) ;
V_10 = ! ! F_93 ( V_2 -> V_4 , 1 , L_26 ) ;
F_94 ( ! V_10 , L_27 , V_2 -> V_4 ) ;
F_36 ( V_5 L_28 ,
V_2 -> V_50 , V_2 -> V_4 , V_2 -> V_6 ) ;
V_10 = F_82 ( V_2 ) ;
F_24 ( V_28 , & V_2 -> V_9 ) ;
return V_10 ;
}
static int F_95 ( struct V_115 * V_116 , int type )
{
struct V_1 * V_2 ;
struct V_70 * V_71 , * V_39 ;
if ( ! V_116 )
return - V_42 ;
V_2 = F_96 ( V_116 ) ;
F_87 ( V_2 ) ;
F_28 ( & V_2 -> V_43 ) ;
F_58 (handler, tmp, &ec->list, node) {
F_59 ( & V_71 -> V_74 ) ;
F_60 ( V_71 ) ;
}
F_39 ( & V_2 -> V_43 ) ;
F_97 ( V_2 -> V_6 , 1 ) ;
F_97 ( V_2 -> V_4 , 1 ) ;
V_116 -> V_122 = NULL ;
if ( V_2 == V_60 )
V_60 = NULL ;
F_60 ( V_2 ) ;
return 0 ;
}
static T_5
V_109 ( struct V_123 * V_124 , void * V_100 )
{
struct V_1 * V_2 = V_100 ;
if ( V_124 -> type != V_125 )
return V_98 ;
if ( V_2 -> V_6 == 0 )
V_2 -> V_6 = V_124 -> V_8 . V_126 . V_127 ;
else if ( V_2 -> V_4 == 0 )
V_2 -> V_4 = V_124 -> V_8 . V_126 . V_127 ;
else
return V_110 ;
return V_98 ;
}
int T_8 F_98 ( void )
{
if ( ! V_119 || F_29 ( V_111 , & V_119 -> V_9 ) )
return 0 ;
if ( ! F_82 ( V_119 ) ) {
V_60 = V_119 ;
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
F_85 (KERN_DEBUG PREFIX L_29 ) ;
V_33 = 1 ;
V_132 = 1 ;
return 0 ;
}
int T_8 F_102 ( void )
{
T_5 V_17 ;
struct V_1 * V_133 = NULL ;
struct V_134 * V_135 ;
V_119 = F_71 () ;
if ( ! V_119 )
return - V_73 ;
F_103 ( V_136 ) ;
V_17 = F_104 ( V_137 , 1 ,
(struct V_138 * * ) & V_135 ) ;
if ( F_78 ( V_17 ) ) {
F_36 ( V_5 L_30 ) ;
V_119 -> V_4 = V_135 -> V_139 . V_56 ;
V_119 -> V_6 = V_135 -> V_8 . V_56 ;
V_119 -> V_50 = V_135 -> V_50 ;
V_119 -> V_66 = V_120 ;
F_105 ( V_120 , V_135 -> V_130 , & V_119 -> V_66 ) ;
if ( ! V_132 )
goto V_140;
V_133 = F_106 ( V_119 , sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_133 )
return - V_73 ;
}
if ( V_131 )
return - V_47 ;
F_85 (KERN_DEBUG PREFIX L_31 ) ;
V_17 = F_107 ( V_141 [ 0 ] . V_130 , F_79 ,
V_119 , NULL ) ;
if ( F_31 ( V_17 ) || ! V_119 -> V_66 )
goto error;
if ( V_133 ) {
if ( V_133 -> V_4 != V_119 -> V_4 ||
V_133 -> V_6 != V_119 -> V_6 ||
V_133 -> V_50 != V_119 -> V_50 ||
V_133 -> V_66 != V_119 -> V_66 )
F_36 ( V_5 L_32
L_33
L_34
L_35 ) ;
F_60 ( V_133 ) ;
V_133 = NULL ;
} else {
T_3 V_142 ;
if ( ! F_108 ( L_36 ) ||
F_31 ( F_105 ( V_119 -> V_66 , L_37 ,
& V_142 ) ) )
return - V_47 ;
}
V_140:
if ( ! F_82 ( V_119 ) ) {
V_60 = V_119 ;
return 0 ;
}
error:
F_60 ( V_119 ) ;
V_119 = NULL ;
return - V_47 ;
}
int T_8 F_109 ( void )
{
int V_57 = 0 ;
V_57 = F_110 ( & V_143 ) ;
if ( V_57 < 0 )
return - V_47 ;
return V_57 ;
}
