static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == 1 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_7 = F_5 ( V_2 -> V_8 ) ;
F_6 ( L_1
L_2 ,
V_7 ,
! ! ( V_7 & V_9 ) ,
! ! ( V_7 & V_10 ) ,
! ! ( V_7 & V_11 ) ,
! ! ( V_7 & V_12 ) ,
! ! ( V_7 & V_13 ) ) ;
return V_7 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_7 = F_5 ( V_2 -> V_14 ) ;
V_2 -> V_15 -> V_16 = V_17 ;
F_6 ( L_3 , V_7 ) ;
return V_7 ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
F_6 ( L_4 , V_18 ) ;
F_9 ( V_18 , V_2 -> V_8 ) ;
V_2 -> V_15 -> V_16 = V_17 ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_19 )
{
F_6 ( L_5 , V_19 ) ;
F_9 ( V_19 , V_2 -> V_14 ) ;
V_2 -> V_15 -> V_16 = V_17 ;
}
static const char * F_11 ( T_1 V_20 )
{
switch ( V_20 ) {
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
static inline bool F_12 ( struct V_1 * V_2 )
{
T_2 V_21 = 0 ;
( void ) F_13 ( NULL , V_2 -> V_22 , & V_21 ) ;
return ( V_21 & V_23 ) ? true : false ;
}
static inline void F_14 ( struct V_1 * V_2 , bool V_24 )
{
if ( V_24 )
F_15 ( NULL , V_2 -> V_22 ) ;
else {
F_16 ( V_2 -> V_6 < 1 ) ;
F_17 ( NULL , V_2 -> V_22 , V_25 ) ;
}
if ( F_12 ( V_2 ) ) {
F_6 ( L_12 ) ;
F_18 ( V_2 ) ;
}
}
static inline void F_19 ( struct V_1 * V_2 , bool V_26 )
{
if ( V_26 )
F_20 ( NULL , V_2 -> V_22 ) ;
else {
F_16 ( V_2 -> V_6 < 1 ) ;
F_17 ( NULL , V_2 -> V_22 , V_27 ) ;
}
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_2 ) )
return;
F_22 ( NULL , V_2 -> V_22 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 == 1 )
F_14 ( V_2 , true ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
bool V_28 = false ;
V_2 -> V_6 -- ;
if ( V_2 -> V_6 == 0 )
F_19 ( V_2 , true ) ;
V_28 = F_3 ( V_2 ) ;
if ( V_28 )
F_25 ( & V_2 -> V_29 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_30 )
{
if ( ! F_2 ( V_30 , & V_2 -> V_4 ) ) {
F_19 ( V_2 , false ) ;
F_27 ( L_13 ) ;
F_28 ( V_30 , & V_2 -> V_4 ) ;
}
}
static void F_29 ( struct V_1 * V_2 , T_1 V_30 )
{
if ( F_2 ( V_30 , & V_2 -> V_4 ) ) {
F_30 ( V_30 , & V_2 -> V_4 ) ;
F_14 ( V_2 , false ) ;
F_27 ( L_14 ) ;
}
}
static bool F_31 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_23 ( V_2 ) ;
return true ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! F_33 ( V_31 , & V_2 -> V_4 ) ) {
F_34 ( L_15 ) ;
F_35 ( & V_2 -> V_32 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_18 == V_33 ) {
F_30 ( V_31 , & V_2 -> V_4 ) ;
F_34 ( L_16 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_34 = 0 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( V_2 -> V_15 && ( V_2 -> V_15 -> V_4 & V_36 ) )
V_34 = 1 ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_34 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
T_1 V_39 ;
bool V_40 = false ;
F_40 ( L_17 , F_41 () ? L_18 : L_19 ,
F_42 () ) ;
F_21 ( V_2 ) ;
V_39 = F_4 ( V_2 ) ;
V_38 = V_2 -> V_15 ;
if ( ! V_38 )
goto V_41;
if ( V_38 -> V_4 & V_42 ) {
if ( V_38 -> V_43 > V_38 -> V_44 ) {
if ( ( V_39 & V_12 ) == 0 )
F_10 ( V_2 , V_38 -> V_45 [ V_38 -> V_44 ++ ] ) ;
else
goto V_41;
} else if ( V_38 -> V_46 > V_38 -> V_47 ) {
if ( ( V_39 & V_13 ) == 1 ) {
V_38 -> V_48 [ V_38 -> V_47 ++ ] = F_7 ( V_2 ) ;
if ( V_38 -> V_46 == V_38 -> V_47 ) {
V_38 -> V_4 |= V_36 ;
if ( V_38 -> V_18 == V_33 )
F_34 ( L_20 ,
F_11 ( V_38 -> V_18 ) ) ;
V_40 = true ;
}
} else
goto V_41;
} else if ( V_38 -> V_43 == V_38 -> V_44 &&
( V_39 & V_12 ) == 0 ) {
V_38 -> V_4 |= V_36 ;
V_40 = true ;
}
goto V_49;
} else {
if ( V_50 &&
! ( V_39 & V_9 ) &&
( V_38 -> V_18 == V_33 ) ) {
V_38 -> V_4 |= V_42 ;
F_36 ( V_2 ) ;
V_38 -> V_48 [ V_38 -> V_47 ++ ] = 0x00 ;
V_38 -> V_4 |= V_36 ;
F_34 ( L_21 ,
F_11 ( V_38 -> V_18 ) ) ;
V_40 = true ;
} else if ( ( V_39 & V_12 ) == 0 ) {
F_8 ( V_2 , V_38 -> V_18 ) ;
V_38 -> V_4 |= V_42 ;
F_36 ( V_2 ) ;
} else
goto V_41;
goto V_49;
}
V_41:
if ( ! ( V_39 & V_9 ) ) {
if ( F_41 () && V_38 ) {
if ( V_38 -> V_51 < V_52 )
++ V_38 -> V_51 ;
if ( V_38 -> V_51 == V_52 )
F_26 ( V_2 , V_53 ) ;
}
}
V_49:
if ( V_39 & V_9 )
F_32 ( V_2 ) ;
if ( V_40 && F_41 () )
F_25 ( & V_2 -> V_29 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_15 -> V_51 = V_2 -> V_15 -> V_44 = V_2 -> V_15 -> V_47 = 0 ;
V_2 -> V_15 -> V_4 = 0 ;
V_2 -> V_15 -> V_16 = V_17 ;
F_18 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_54 = 5 ;
while ( V_54 -- ) {
unsigned long V_55 = V_17 +
F_45 ( V_56 ) ;
unsigned long V_57 = V_58 ;
do {
if ( V_59 || F_46 () ) {
V_57 = V_60 ;
F_47 ( V_57 ) ;
if ( F_37 ( V_2 ) )
return 0 ;
} else {
if ( F_48 ( V_2 -> V_29 ,
F_37 ( V_2 ) ,
F_49 ( V_57 ) ) )
return 0 ;
}
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( F_50 ( V_17 ,
V_2 -> V_15 -> V_16 +
F_49 ( V_57 ) ) )
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
} while ( F_51 ( V_17 , V_55 ) );
F_52 ( L_22 ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
F_43 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
return - V_61 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
unsigned long V_62 ;
int V_34 = 0 ;
if ( V_59 )
F_47 ( V_60 ) ;
F_38 ( & V_2 -> V_35 , V_62 ) ;
if ( ! F_31 ( V_2 ) ) {
V_34 = - V_63 ;
goto V_64;
}
F_54 ( V_2 , L_23 ) ;
V_2 -> V_15 = V_38 ;
F_34 ( L_24 , F_11 ( V_38 -> V_18 ) ) ;
F_43 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_62 ) ;
V_34 = F_44 ( V_2 ) ;
F_38 ( & V_2 -> V_35 , V_62 ) ;
if ( V_38 -> V_51 == V_52 )
F_29 ( V_2 , V_53 ) ;
F_34 ( L_25 , F_11 ( V_38 -> V_18 ) ) ;
V_2 -> V_15 = NULL ;
F_24 ( V_2 ) ;
F_54 ( V_2 , L_26 ) ;
V_64:
F_39 ( & V_2 -> V_35 , V_62 ) ;
return V_34 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_39 ;
T_3 V_65 ;
if ( ! V_2 || ( ! V_38 ) || ( V_38 -> V_43 && ! V_38 -> V_45 ) || ( V_38 -> V_46 && ! V_38 -> V_48 ) )
return - V_63 ;
if ( V_38 -> V_48 )
memset ( V_38 -> V_48 , 0 , V_38 -> V_46 ) ;
F_56 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_67 ) {
V_39 = F_57 ( V_68 , & V_65 ) ;
if ( F_58 ( V_39 ) ) {
V_39 = - V_69 ;
goto V_64;
}
}
V_39 = F_53 ( V_2 , V_38 ) ;
if ( F_2 ( V_53 , & V_2 -> V_4 ) )
F_59 ( 1 ) ;
if ( V_2 -> V_67 )
F_60 ( V_65 ) ;
V_64:
F_61 ( & V_2 -> V_66 ) ;
return V_39 ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_1 V_70 ;
struct V_37 V_38 = { . V_18 = V_71 ,
. V_45 = NULL , . V_48 = & V_70 ,
. V_43 = 0 , . V_46 = 1 } ;
return F_55 ( V_2 , & V_38 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_37 V_38 = { . V_18 = V_72 ,
. V_45 = NULL , . V_48 = NULL ,
. V_43 = 0 , . V_46 = 0 } ;
return ( F_4 ( V_2 ) & V_10 ) ?
F_55 ( V_2 , & V_38 ) : 0 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 V_73 , T_1 * V_19 )
{
int V_74 ;
T_1 V_70 ;
struct V_37 V_38 = { . V_18 = V_75 ,
. V_45 = & V_73 , . V_48 = & V_70 ,
. V_43 = 1 , . V_46 = 1 } ;
V_74 = F_55 ( V_2 , & V_38 ) ;
* V_19 = V_70 ;
return V_74 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_73 , T_1 V_19 )
{
T_1 V_45 [ 2 ] = { V_73 , V_19 } ;
struct V_37 V_38 = { . V_18 = V_76 ,
. V_45 = V_45 , . V_48 = NULL ,
. V_43 = 2 , . V_46 = 0 } ;
return F_55 ( V_2 , & V_38 ) ;
}
int F_66 ( T_1 V_77 , T_1 * V_78 )
{
int V_41 ;
T_1 V_79 ;
if ( ! V_80 )
return - V_69 ;
V_41 = F_64 ( V_80 , V_77 , & V_79 ) ;
if ( ! V_41 ) {
* V_78 = V_79 ;
return 0 ;
}
return V_41 ;
}
int F_67 ( T_1 V_77 , T_1 V_78 )
{
int V_41 ;
if ( ! V_80 )
return - V_69 ;
V_41 = F_65 ( V_80 , V_77 , V_78 ) ;
return V_41 ;
}
int F_68 ( T_1 V_18 ,
const T_1 * V_45 , unsigned V_81 ,
T_1 * V_48 , unsigned V_82 )
{
struct V_37 V_38 = { . V_18 = V_18 ,
. V_45 = V_45 , . V_48 = V_48 ,
. V_43 = V_81 , . V_46 = V_82 } ;
if ( ! V_80 )
return - V_69 ;
return F_55 ( V_80 , & V_38 ) ;
}
T_4 F_69 ( void )
{
if ( ! V_80 )
return NULL ;
return V_80 -> V_83 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_84 , V_39 ;
T_1 V_85 = 0 ;
for ( V_84 = 0 ; V_84 < V_86 ; V_84 ++ ) {
V_39 = F_71 ( V_2 , & V_85 ) ;
if ( V_39 || ! V_85 )
break;
}
if ( F_72 ( V_84 == V_86 ) )
F_73 ( L_27 , V_84 ) ;
else
F_74 ( L_28 , V_84 ) ;
}
static void F_75 ( struct V_1 * V_2 , bool V_87 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( ! F_33 ( V_3 , & V_2 -> V_4 ) ) {
F_27 ( L_29 ) ;
if ( ! V_87 ) {
F_23 ( V_2 ) ;
F_54 ( V_2 , L_30 ) ;
}
F_76 ( L_31 ) ;
}
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
static bool F_77 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_28 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
V_28 = F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_28 ;
}
static void F_78 ( struct V_1 * V_2 , bool V_88 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( L_32 ) ;
F_28 ( V_5 , & V_2 -> V_4 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
F_79 ( V_2 -> V_29 , F_77 ( V_2 ) ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( ! V_88 ) {
F_24 ( V_2 ) ;
F_54 ( V_2 , L_33 ) ;
}
F_30 ( V_3 , & V_2 -> V_4 ) ;
F_30 ( V_5 , & V_2 -> V_4 ) ;
F_76 ( L_34 ) ;
}
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
void F_80 ( void )
{
struct V_1 * V_2 = V_80 ;
if ( ! V_2 )
return;
F_56 ( & V_2 -> V_66 ) ;
F_78 ( V_2 , true ) ;
F_61 ( & V_2 -> V_66 ) ;
}
void F_81 ( void )
{
struct V_1 * V_2 = V_80 ;
if ( ! V_2 )
return;
F_75 ( V_2 , true ) ;
if ( V_89 )
F_70 ( V_2 ) ;
}
void F_82 ( void )
{
if ( V_80 )
F_75 ( V_80 , true ) ;
}
static struct V_90 *
F_83 ( struct V_90 * V_91 )
{
if ( V_91 )
F_84 ( & V_91 -> V_92 ) ;
return V_91 ;
}
static void F_85 ( struct V_92 * V_92 )
{
struct V_90 * V_91 =
F_86 ( V_92 , struct V_90 , V_92 ) ;
F_87 ( V_91 ) ;
}
static void F_88 ( struct V_90 * V_91 )
{
F_89 ( & V_91 -> V_92 , F_85 ) ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_93 ,
T_4 V_83 , T_5 V_94 ,
void * V_19 )
{
struct V_90 * V_91 =
F_91 ( sizeof( struct V_90 ) , V_95 ) ;
if ( ! V_91 )
return - V_96 ;
V_91 -> V_93 = V_93 ;
V_91 -> V_83 = V_83 ;
V_91 -> V_94 = V_94 ;
V_91 -> V_19 = V_19 ;
F_56 ( & V_2 -> V_66 ) ;
F_92 ( & V_91 -> V_92 ) ;
F_93 ( & V_91 -> V_97 , & V_2 -> V_98 ) ;
F_61 ( & V_2 -> V_66 ) ;
return 0 ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_90 * V_91 , * V_62 ;
F_95 ( V_99 ) ;
F_56 ( & V_2 -> V_66 ) ;
F_96 (handler, tmp, &ec->list, node) {
if ( V_93 == V_91 -> V_93 ) {
F_97 ( & V_91 -> V_97 ) ;
F_93 ( & V_91 -> V_97 , & V_99 ) ;
}
}
F_61 ( & V_2 -> V_66 ) ;
F_96 (handler, tmp, &free_list, node)
F_88 ( V_91 ) ;
}
static void F_98 ( void * V_100 )
{
struct V_90 * V_91 = V_100 ;
if ( ! V_91 )
return;
F_99 ( L_35 , V_91 -> V_93 ) ;
if ( V_91 -> V_94 )
V_91 -> V_94 ( V_91 -> V_19 ) ;
else if ( V_91 -> V_83 )
F_100 ( V_91 -> V_83 , NULL , NULL , NULL ) ;
F_99 ( L_36 , V_91 -> V_93 ) ;
F_88 ( V_91 ) ;
}
static int F_71 ( struct V_1 * V_2 , T_1 * V_19 )
{
T_1 V_85 = 0 ;
int V_74 ;
T_6 V_39 ;
struct V_90 * V_91 ;
struct V_37 V_38 = { . V_18 = V_33 ,
. V_45 = NULL , . V_48 = & V_85 ,
. V_43 = 0 , . V_46 = 1 } ;
V_74 = F_55 ( V_2 , & V_38 ) ;
if ( V_74 )
return V_74 ;
if ( V_19 )
* V_19 = V_85 ;
if ( ! V_85 )
return - V_101 ;
F_56 ( & V_2 -> V_66 ) ;
F_101 (handler, &ec->list, node) {
if ( V_85 == V_91 -> V_93 ) {
V_91 = F_83 ( V_91 ) ;
F_99 ( L_37 ,
V_91 -> V_93 ) ;
V_39 = F_102 ( ( V_91 -> V_94 ) ?
V_102 : V_103 ,
F_98 , V_91 ) ;
if ( F_58 ( V_39 ) )
V_74 = - V_104 ;
break;
}
}
F_61 ( & V_2 -> V_66 ) ;
return V_74 ;
}
static void F_103 ( struct V_105 * V_32 )
{
struct V_1 * V_2 = F_86 ( V_32 , struct V_1 , V_32 ) ;
F_71 ( V_2 , NULL ) ;
}
static T_3 F_104 ( T_4 V_106 ,
T_3 V_107 , void * V_19 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_19 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_108 ;
}
static T_6
F_105 ( T_3 V_109 , T_7 V_73 ,
T_3 V_110 , T_8 * V_111 ,
void * V_112 , void * V_113 )
{
struct V_1 * V_2 = V_112 ;
int V_74 = 0 , V_84 , V_114 = V_110 / 8 ;
T_1 * V_85 = ( T_1 * ) V_111 ;
if ( ( V_73 > 0xFF ) || ! V_85 || ! V_112 )
return V_115 ;
if ( V_109 != V_116 && V_109 != V_117 )
return V_115 ;
if ( V_59 || V_110 > 8 )
F_62 ( V_2 ) ;
for ( V_84 = 0 ; V_84 < V_114 ; ++ V_84 , ++ V_73 , ++ V_85 )
V_74 = ( V_109 == V_116 ) ?
F_64 ( V_2 , V_73 , V_85 ) :
F_65 ( V_2 , V_73 , * V_85 ) ;
if ( V_59 || V_110 > 8 )
F_63 ( V_2 ) ;
switch ( V_74 ) {
case - V_63 :
return V_115 ;
case - V_69 :
return V_118 ;
case - V_61 :
return V_119 ;
default:
return V_120 ;
}
}
static struct V_1 * F_106 ( void )
{
struct V_1 * V_2 = F_91 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = 1 << V_31 ;
F_107 ( & V_2 -> V_66 ) ;
F_108 ( & V_2 -> V_29 ) ;
F_109 ( & V_2 -> V_98 ) ;
F_110 ( & V_2 -> V_35 ) ;
F_111 ( & V_2 -> V_32 , F_103 ) ;
return V_2 ;
}
static T_6
F_112 ( T_4 V_83 , T_3 V_121 ,
void * V_122 , void * * V_123 )
{
char V_124 [ 5 ] ;
struct V_125 V_126 = { sizeof( V_124 ) , V_124 } ;
struct V_1 * V_2 = V_122 ;
int V_85 = 0 ;
T_6 V_39 ;
V_39 = F_113 ( V_83 , V_127 , & V_126 ) ;
if ( F_114 ( V_39 ) && sscanf ( V_124 , L_38 , & V_85 ) == 1 )
F_90 ( V_2 , V_85 , V_83 , NULL , NULL ) ;
return V_120 ;
}
static T_6
F_115 ( T_4 V_83 , T_3 V_128 , void * V_122 , void * * V_129 )
{
T_6 V_39 ;
unsigned long long V_62 = 0 ;
struct V_1 * V_2 = V_122 ;
V_2 -> V_8 = V_2 -> V_14 = 0 ;
V_39 = F_116 ( V_83 , V_130 ,
V_131 , V_2 ) ;
if ( F_58 ( V_39 ) )
return V_39 ;
V_39 = F_117 ( V_83 , L_39 , NULL , & V_62 ) ;
if ( F_58 ( V_39 ) )
return V_39 ;
V_2 -> V_22 = V_62 ;
V_62 = 0 ;
F_117 ( V_83 , L_40 , NULL , & V_62 ) ;
V_2 -> V_67 = V_62 ;
V_2 -> V_83 = V_83 ;
return V_132 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_6 V_39 ;
if ( F_2 ( V_133 , & V_2 -> V_4 ) )
return 0 ;
V_39 = F_119 ( NULL , V_2 -> V_22 ,
V_134 ,
& F_104 , V_2 ) ;
if ( F_58 ( V_39 ) )
return - V_69 ;
F_75 ( V_2 , false ) ;
V_39 = F_120 ( V_2 -> V_83 ,
V_135 ,
& F_105 ,
NULL , V_2 ) ;
if ( F_58 ( V_39 ) ) {
if ( V_39 == V_118 ) {
F_121 ( L_41
L_42 ) ;
} else {
F_78 ( V_2 , false ) ;
F_122 ( NULL , V_2 -> V_22 ,
& F_104 ) ;
return - V_69 ;
}
}
F_28 ( V_133 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_133 , & V_2 -> V_4 ) )
return;
F_78 ( V_2 , false ) ;
if ( F_58 ( F_124 ( V_2 -> V_83 ,
V_135 , & F_105 ) ) )
F_121 ( L_43 ) ;
if ( F_58 ( F_122 ( NULL , V_2 -> V_22 ,
& F_104 ) ) )
F_121 ( L_44 ) ;
F_30 ( V_133 , & V_2 -> V_4 ) ;
}
static int F_125 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = NULL ;
int V_34 ;
strcpy ( F_126 ( V_137 ) , V_138 ) ;
strcpy ( F_127 ( V_137 ) , V_139 ) ;
if ( V_140 &&
( V_140 -> V_83 == V_137 -> V_83 ||
V_140 -> V_83 == V_141 ) ) {
V_2 = V_140 ;
V_140 = NULL ;
} else {
V_2 = F_106 () ;
if ( ! V_2 )
return - V_96 ;
}
if ( F_115 ( V_137 -> V_83 , 0 , V_2 , NULL ) !=
V_132 ) {
F_87 ( V_2 ) ;
return - V_63 ;
}
F_128 ( V_142 , V_2 -> V_83 , 1 ,
F_112 , NULL , V_2 , NULL ) ;
if ( ! V_80 )
V_80 = V_2 ;
V_137 -> V_143 = V_2 ;
V_34 = ! ! F_129 ( V_2 -> V_14 , 1 , L_45 ) ;
F_130 ( ! V_34 , L_46 , V_2 -> V_14 ) ;
V_34 = ! ! F_129 ( V_2 -> V_8 , 1 , L_47 ) ;
F_130 ( ! V_34 , L_48 , V_2 -> V_8 ) ;
F_74 ( L_49 ,
V_2 -> V_22 , V_2 -> V_8 , V_2 -> V_14 ) ;
V_34 = F_118 ( V_2 ) ;
F_131 ( V_2 -> V_83 ) ;
F_30 ( V_31 , & V_2 -> V_4 ) ;
if ( V_89 )
F_70 ( V_2 ) ;
return V_34 ;
}
static int F_132 ( struct V_136 * V_137 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 , * V_62 ;
if ( ! V_137 )
return - V_63 ;
V_2 = F_133 ( V_137 ) ;
F_123 ( V_2 ) ;
F_56 ( & V_2 -> V_66 ) ;
F_96 (handler, tmp, &ec->list, node) {
F_134 ( & V_91 -> V_97 ) ;
F_87 ( V_91 ) ;
}
F_61 ( & V_2 -> V_66 ) ;
F_135 ( V_2 -> V_14 , 1 ) ;
F_135 ( V_2 -> V_8 , 1 ) ;
V_137 -> V_143 = NULL ;
if ( V_2 == V_80 )
V_80 = NULL ;
F_87 ( V_2 ) ;
return 0 ;
}
static T_6
V_131 ( struct V_144 * V_145 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
if ( V_145 -> type != V_146 )
return V_120 ;
if ( V_2 -> V_14 == 0 )
V_2 -> V_14 = V_145 -> V_19 . V_147 . V_148 ;
else if ( V_2 -> V_8 == 0 )
V_2 -> V_8 = V_145 -> V_19 . V_147 . V_148 ;
else
return V_132 ;
return V_120 ;
}
int T_9 F_136 ( void )
{
if ( ! V_140 || F_2 ( V_133 , & V_140 -> V_4 ) )
return 0 ;
if ( ! F_118 ( V_140 ) ) {
V_80 = V_140 ;
return 0 ;
}
return - V_149 ;
}
static int F_137 ( const struct V_150 * V_151 )
{
V_152 = 1 ;
return 0 ;
}
static int F_138 ( const struct V_150 * V_151 )
{
V_153 = 1 ;
return 0 ;
}
static int F_139 ( const struct V_150 * V_151 )
{
F_52 ( L_50 ) ;
V_59 = 1 ;
V_153 = 1 ;
return 0 ;
}
static int F_140 ( const struct V_150 * V_151 )
{
F_52 ( L_51 ) ;
V_52 = 20 ;
return 0 ;
}
static int F_141 ( const struct V_150 * V_151 )
{
F_52 ( L_52 ) ;
V_50 = 1 ;
return 0 ;
}
static int F_142 ( const struct V_150 * V_151 )
{
F_52 ( L_53 ) ;
V_89 = 1 ;
return 0 ;
}
int T_9 F_143 ( void )
{
T_6 V_39 ;
struct V_1 * V_154 = NULL ;
struct V_155 * V_156 ;
V_140 = F_106 () ;
if ( ! V_140 )
return - V_96 ;
F_144 ( V_157 ) ;
V_39 = F_145 ( V_158 , 1 ,
(struct V_159 * * ) & V_156 ) ;
if ( F_114 ( V_39 ) ) {
F_74 ( L_54 ) ;
V_140 -> V_8 = V_156 -> V_160 . V_73 ;
V_140 -> V_14 = V_156 -> V_19 . V_73 ;
V_140 -> V_22 = V_156 -> V_22 ;
V_140 -> V_83 = V_141 ;
F_146 ( V_141 , V_156 -> V_151 ,
& V_140 -> V_83 ) ;
if ( ! V_153 )
goto V_161;
V_154 = F_147 ( V_140 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_154 )
return - V_96 ;
}
if ( V_152 ) {
F_87 ( V_154 ) ;
return - V_69 ;
}
F_52 ( L_55 ) ;
V_39 = F_148 ( V_162 [ 0 ] . V_151 , F_115 ,
V_140 , NULL ) ;
if ( F_58 ( V_39 ) || ! V_140 -> V_83 )
goto error;
if ( V_154 ) {
if ( V_154 -> V_8 != V_140 -> V_8 ||
V_154 -> V_14 != V_140 -> V_14 ||
V_154 -> V_22 != V_140 -> V_22 ||
V_154 -> V_83 != V_140 -> V_83 )
F_74 ( L_56
L_57
L_58
L_59 ) ;
F_87 ( V_154 ) ;
V_154 = NULL ;
} else {
if ( ! F_149 ( L_60 ) ||
! F_150 ( V_140 -> V_83 , L_61 ) )
return - V_69 ;
}
V_161:
if ( ! F_118 ( V_140 ) ) {
V_80 = V_140 ;
return 0 ;
}
error:
F_87 ( V_140 ) ;
F_87 ( V_154 ) ;
V_140 = NULL ;
return - V_69 ;
}
int T_9 F_151 ( void )
{
int V_74 = 0 ;
V_74 = F_152 ( & V_163 ) ;
if ( V_74 < 0 )
return - V_69 ;
return V_74 ;
}
