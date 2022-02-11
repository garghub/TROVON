static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_6 , & V_2 -> V_4 ) )
return false ;
if ( V_7 )
return F_1 ( V_2 ) ;
else
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_8 == 1 ;
}
static inline T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_9 = F_6 ( V_2 -> V_10 ) ;
F_7 ( L_1
L_2 ,
V_9 ,
! ! ( V_9 & V_11 ) ,
! ! ( V_9 & V_12 ) ,
! ! ( V_9 & V_13 ) ,
! ! ( V_9 & V_14 ) ,
! ! ( V_9 & V_15 ) ) ;
return V_9 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_9 = F_6 ( V_2 -> V_16 ) ;
V_2 -> V_17 = V_18 ;
F_7 ( L_3 , V_9 ) ;
return V_9 ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_19 )
{
F_7 ( L_4 , V_19 ) ;
F_10 ( V_19 , V_2 -> V_10 ) ;
V_2 -> V_17 = V_18 ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_20 )
{
F_7 ( L_5 , V_20 ) ;
F_10 ( V_20 , V_2 -> V_16 ) ;
V_2 -> V_17 = V_18 ;
}
static const char * F_12 ( T_1 V_21 )
{
switch ( V_21 ) {
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
static inline bool F_13 ( struct V_1 * V_2 )
{
T_2 V_22 = 0 ;
( void ) F_14 ( NULL , V_2 -> V_23 , & V_22 ) ;
return ( V_22 & V_24 ) ? true : false ;
}
static inline void F_15 ( struct V_1 * V_2 , bool V_25 )
{
if ( V_25 )
F_16 ( NULL , V_2 -> V_23 ) ;
else {
F_17 ( V_2 -> V_8 < 1 ) ;
F_18 ( NULL , V_2 -> V_23 , V_26 ) ;
}
if ( F_13 ( V_2 ) ) {
F_7 ( L_12 ) ;
F_19 ( V_2 ) ;
}
}
static inline void F_20 ( struct V_1 * V_2 , bool V_27 )
{
if ( V_27 )
F_21 ( NULL , V_2 -> V_23 ) ;
else {
F_17 ( V_2 -> V_8 < 1 ) ;
F_18 ( NULL , V_2 -> V_23 , V_28 ) ;
}
}
static inline void F_22 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_2 ) )
return;
F_23 ( NULL , V_2 -> V_23 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_8 ++ ;
if ( F_2 ( V_29 , & V_2 -> V_4 ) &&
V_2 -> V_8 == 1 )
F_15 ( V_2 , true ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
bool V_30 = false ;
V_2 -> V_8 -- ;
if ( F_2 ( V_29 , & V_2 -> V_4 ) &&
V_2 -> V_8 == 0 )
F_20 ( V_2 , true ) ;
V_30 = F_4 ( V_2 ) ;
if ( V_30 )
F_26 ( & V_2 -> V_31 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( ! F_2 ( V_32 , & V_2 -> V_4 ) ) {
F_20 ( V_2 , false ) ;
F_28 ( L_13 ) ;
F_29 ( V_32 , & V_2 -> V_4 ) ;
}
}
static void F_30 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( F_2 ( V_32 , & V_2 -> V_4 ) ) {
F_31 ( V_32 , & V_2 -> V_4 ) ;
F_15 ( V_2 , false ) ;
F_28 ( L_14 ) ;
}
}
static bool F_32 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_24 ( V_2 ) ;
return true ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) &&
! F_34 ( V_33 , & V_2 -> V_4 ) ) {
F_35 ( L_15 ,
F_12 ( V_34 ) ) ;
V_2 -> V_35 ++ ;
F_36 ( & V_2 -> V_36 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
if ( F_2 ( V_33 , & V_2 -> V_4 ) ) {
F_31 ( V_33 , & V_2 -> V_4 ) ;
F_35 ( L_16 ,
F_12 ( V_34 ) ) ;
}
}
static inline void F_38 ( struct V_1 * V_2 )
{
if ( ! F_34 ( V_6 , & V_2 -> V_4 ) )
F_39 ( L_17 ) ;
if ( ! F_2 ( V_33 , & V_2 -> V_4 ) )
F_19 ( V_2 ) ;
}
static inline void F_40 ( struct V_1 * V_2 )
{
if ( F_41 ( V_6 , & V_2 -> V_4 ) )
F_39 ( L_18 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_37 , V_38 ;
T_1 V_39 = 0 ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
V_38 = F_43 ( V_2 , & V_39 ) ;
if ( V_38 || ! V_39 )
break;
}
if ( F_44 ( V_37 == V_40 ) )
F_45 ( L_19 , V_37 ) ;
else
F_46 ( L_20 , V_37 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( F_1 ( V_2 ) )
F_38 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
if ( V_42 )
F_42 ( V_2 ) ;
}
static bool F_50 ( struct V_1 * V_2 )
{
bool V_30 ;
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
V_30 = ! V_2 -> V_35 ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_30 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_31 , F_50 ( V_2 ) ) ;
if ( V_43 )
F_53 ( V_43 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
F_40 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
F_51 ( V_2 ) ;
}
static bool F_55 ( struct V_1 * V_2 )
{
bool V_44 = true ;
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( V_45 == V_46 ||
V_45 == V_47 ||
! F_2 ( V_33 , & V_2 -> V_4 ) ||
( V_2 -> V_48 && V_2 -> V_48 -> V_19 == V_34 ) )
V_44 = false ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_44 ;
}
static int F_56 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_49 = 0 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( V_2 -> V_48 && ( V_2 -> V_48 -> V_4 & V_50 ) )
V_49 = 1 ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_49 ;
}
static int F_57 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_49 = 0 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( V_2 -> V_48 && ( V_2 -> V_48 -> V_4 & V_51 ) )
V_49 = 1 ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_49 ;
}
static inline void F_58 ( struct V_1 * V_2 , unsigned long V_32 )
{
V_2 -> V_48 -> V_4 |= V_32 ;
if ( V_2 -> V_48 -> V_19 == V_34 ) {
if ( V_45 == V_46 &&
V_32 == V_50 )
F_37 ( V_2 ) ;
if ( V_45 == V_47 &&
V_32 == V_51 )
F_37 ( V_2 ) ;
if ( V_45 == V_52 &&
V_32 == V_51 )
F_29 ( V_53 , & V_2 -> V_4 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
T_1 V_38 ;
bool V_56 = false ;
F_59 ( L_21 , F_60 () ? L_22 : L_23 ,
F_61 () ) ;
F_22 ( V_2 ) ;
V_38 = F_5 ( V_2 ) ;
V_55 = V_2 -> V_48 ;
if ( ! V_55 || ! ( V_55 -> V_4 & V_50 ) ) {
if ( V_45 == V_52 &&
( ! V_2 -> V_35 ||
F_2 ( V_53 , & V_2 -> V_4 ) ) ) {
F_31 ( V_53 , & V_2 -> V_4 ) ;
F_37 ( V_2 ) ;
}
}
if ( ! V_55 )
goto V_57;
if ( V_55 -> V_4 & V_50 ) {
if ( V_55 -> V_58 > V_55 -> V_59 ) {
if ( ( V_38 & V_14 ) == 0 )
F_11 ( V_2 , V_55 -> V_60 [ V_55 -> V_59 ++ ] ) ;
else
goto V_57;
} else if ( V_55 -> V_61 > V_55 -> V_62 ) {
if ( ( V_38 & V_15 ) == 1 ) {
V_55 -> V_63 [ V_55 -> V_62 ++ ] = F_8 ( V_2 ) ;
if ( V_55 -> V_61 == V_55 -> V_62 ) {
F_58 ( V_2 , V_51 ) ;
if ( V_55 -> V_19 == V_34 )
F_35 ( L_24 ,
F_12 ( V_34 ) ) ;
V_56 = true ;
}
} else
goto V_57;
} else if ( V_55 -> V_58 == V_55 -> V_59 &&
( V_38 & V_14 ) == 0 ) {
F_58 ( V_2 , V_51 ) ;
V_56 = true ;
}
goto V_64;
} else {
if ( V_65 &&
! ( V_38 & V_11 ) &&
( V_55 -> V_19 == V_34 ) ) {
F_58 ( V_2 , V_50 ) ;
V_55 -> V_63 [ V_55 -> V_62 ++ ] = 0x00 ;
F_58 ( V_2 , V_51 ) ;
F_35 ( L_25 ,
F_12 ( V_34 ) ) ;
V_56 = true ;
} else if ( ( V_38 & V_14 ) == 0 ) {
F_9 ( V_2 , V_55 -> V_19 ) ;
F_58 ( V_2 , V_50 ) ;
} else
goto V_57;
goto V_64;
}
V_57:
if ( ! ( V_38 & V_11 ) ) {
if ( F_60 () && V_55 ) {
if ( V_55 -> V_66 < V_67 )
++ V_55 -> V_66 ;
if ( V_55 -> V_66 == V_67 )
F_27 ( V_2 , V_68 ) ;
}
}
V_64:
if ( V_38 & V_11 )
F_33 ( V_2 ) ;
if ( V_56 && F_60 () )
F_26 ( & V_2 -> V_31 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_48 -> V_66 = V_2 -> V_48 -> V_59 = V_2 -> V_48 -> V_62 = 0 ;
V_2 -> V_48 -> V_4 = 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
unsigned long V_69 = F_64 ( V_70 ) ;
unsigned long V_71 = V_2 -> V_17 + V_69 ;
do {
if ( V_72 ) {
if ( F_57 ( V_2 ) )
return 0 ;
F_65 ( F_66 ( V_69 ) ) ;
} else {
if ( ! F_56 ( V_2 ) &&
! F_55 ( V_2 ) )
break;
if ( F_67 ( V_2 -> V_31 ,
F_57 ( V_2 ) ,
V_69 ) )
return 0 ;
}
} while ( F_68 ( V_18 , V_71 ) );
return - V_73 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_74 = 5 ;
while ( V_74 -- ) {
unsigned long V_75 = V_18 +
F_70 ( V_76 ) ;
do {
if ( ! F_63 ( V_2 ) )
return 0 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
F_19 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
} while ( F_68 ( V_18 , V_75 ) );
F_71 ( L_26 ) ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
F_62 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
return - V_73 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
unsigned long V_77 ;
int V_49 = 0 ;
F_48 ( & V_2 -> V_41 , V_77 ) ;
if ( ! F_32 ( V_2 ) ) {
V_49 = - V_78 ;
goto V_79;
}
F_73 ( V_2 , L_27 ) ;
V_2 -> V_48 = V_55 ;
F_74 ( L_28 , F_12 ( V_55 -> V_19 ) ) ;
F_62 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_77 ) ;
V_49 = F_69 ( V_2 ) ;
F_48 ( & V_2 -> V_41 , V_77 ) ;
if ( V_55 -> V_66 == V_67 )
F_30 ( V_2 , V_68 ) ;
F_74 ( L_29 , F_12 ( V_55 -> V_19 ) ) ;
V_2 -> V_48 = NULL ;
F_25 ( V_2 ) ;
F_73 ( V_2 , L_30 ) ;
V_79:
F_49 ( & V_2 -> V_41 , V_77 ) ;
return V_49 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
int V_38 ;
T_3 V_80 ;
if ( ! V_2 || ( ! V_55 ) || ( V_55 -> V_58 && ! V_55 -> V_60 ) || ( V_55 -> V_61 && ! V_55 -> V_63 ) )
return - V_78 ;
if ( V_55 -> V_63 )
memset ( V_55 -> V_63 , 0 , V_55 -> V_61 ) ;
F_76 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_82 ) {
V_38 = F_77 ( V_83 , & V_80 ) ;
if ( F_78 ( V_38 ) ) {
V_38 = - V_84 ;
goto V_79;
}
}
V_38 = F_72 ( V_2 , V_55 ) ;
if ( V_2 -> V_82 )
F_79 ( V_80 ) ;
V_79:
F_80 ( & V_2 -> V_81 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 )
{
T_1 V_85 ;
struct V_54 V_55 = { . V_19 = V_86 ,
. V_60 = NULL , . V_63 = & V_85 ,
. V_58 = 0 , . V_61 = 1 } ;
return F_75 ( V_2 , & V_55 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_54 V_55 = { . V_19 = V_87 ,
. V_60 = NULL , . V_63 = NULL ,
. V_58 = 0 , . V_61 = 0 } ;
return ( F_5 ( V_2 ) & V_12 ) ?
F_75 ( V_2 , & V_55 ) : 0 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_88 , T_1 * V_20 )
{
int V_89 ;
T_1 V_85 ;
struct V_54 V_55 = { . V_19 = V_90 ,
. V_60 = & V_88 , . V_63 = & V_85 ,
. V_58 = 1 , . V_61 = 1 } ;
V_89 = F_75 ( V_2 , & V_55 ) ;
* V_20 = V_85 ;
return V_89 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_88 , T_1 V_20 )
{
T_1 V_60 [ 2 ] = { V_88 , V_20 } ;
struct V_54 V_55 = { . V_19 = V_91 ,
. V_60 = V_60 , . V_63 = NULL ,
. V_58 = 2 , . V_61 = 0 } ;
return F_75 ( V_2 , & V_55 ) ;
}
int F_85 ( T_1 V_92 , T_1 * V_93 )
{
int V_57 ;
T_1 V_94 ;
if ( ! V_95 )
return - V_84 ;
V_57 = F_83 ( V_95 , V_92 , & V_94 ) ;
if ( ! V_57 ) {
* V_93 = V_94 ;
return 0 ;
}
return V_57 ;
}
int F_86 ( T_1 V_92 , T_1 V_93 )
{
int V_57 ;
if ( ! V_95 )
return - V_84 ;
V_57 = F_84 ( V_95 , V_92 , V_93 ) ;
return V_57 ;
}
int F_87 ( T_1 V_19 ,
const T_1 * V_60 , unsigned V_96 ,
T_1 * V_63 , unsigned V_97 )
{
struct V_54 V_55 = { . V_19 = V_19 ,
. V_60 = V_60 , . V_63 = V_63 ,
. V_58 = V_96 , . V_61 = V_97 } ;
if ( ! V_95 )
return - V_84 ;
return F_75 ( V_95 , & V_55 ) ;
}
T_4 F_88 ( void )
{
if ( ! V_95 )
return NULL ;
return V_95 -> V_98 ;
}
static void F_89 ( struct V_1 * V_2 , bool V_99 )
{
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( ! F_34 ( V_3 , & V_2 -> V_4 ) ) {
F_28 ( L_31 ) ;
if ( ! V_99 ) {
F_24 ( V_2 ) ;
F_73 ( V_2 , L_32 ) ;
}
F_39 ( L_33 ) ;
}
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
static bool F_90 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_30 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
V_30 = F_4 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_30 ;
}
static void F_91 ( struct V_1 * V_2 , bool V_100 )
{
unsigned long V_4 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_28 ( L_34 ) ;
F_29 ( V_5 , & V_2 -> V_4 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
F_52 ( V_2 -> V_31 , F_90 ( V_2 ) ) ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( ! V_100 ) {
F_25 ( V_2 ) ;
F_73 ( V_2 , L_35 ) ;
} else if ( ! V_7 )
F_40 ( V_2 ) ;
F_31 ( V_3 , & V_2 -> V_4 ) ;
F_31 ( V_5 , & V_2 -> V_4 ) ;
F_39 ( L_36 ) ;
}
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
void F_92 ( void )
{
struct V_1 * V_2 = V_95 ;
if ( ! V_2 )
return;
F_76 ( & V_2 -> V_81 ) ;
F_91 ( V_2 , true ) ;
F_80 ( & V_2 -> V_81 ) ;
}
void F_93 ( void )
{
if ( V_95 )
F_89 ( V_95 , true ) ;
}
static struct V_101 *
F_94 ( struct V_101 * V_102 )
{
if ( V_102 )
F_95 ( & V_102 -> V_103 ) ;
return V_102 ;
}
static struct V_101 *
F_96 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_101 * V_102 ;
bool V_104 = false ;
F_76 ( & V_2 -> V_81 ) ;
F_97 (handler, &ec->list, node) {
if ( V_39 == V_102 -> V_105 ) {
V_104 = true ;
break;
}
}
F_80 ( & V_2 -> V_81 ) ;
return V_104 ? F_94 ( V_102 ) : NULL ;
}
static void F_98 ( struct V_103 * V_103 )
{
struct V_101 * V_102 =
F_99 ( V_103 , struct V_101 , V_103 ) ;
F_100 ( V_102 ) ;
}
static void F_101 ( struct V_101 * V_102 )
{
F_102 ( & V_102 -> V_103 , F_98 ) ;
}
int F_103 ( struct V_1 * V_2 , T_1 V_105 ,
T_4 V_98 , T_5 V_106 ,
void * V_20 )
{
struct V_101 * V_102 =
F_104 ( sizeof( struct V_101 ) , V_107 ) ;
if ( ! V_102 )
return - V_108 ;
V_102 -> V_105 = V_105 ;
V_102 -> V_98 = V_98 ;
V_102 -> V_106 = V_106 ;
V_102 -> V_20 = V_20 ;
F_76 ( & V_2 -> V_81 ) ;
F_105 ( & V_102 -> V_103 ) ;
F_106 ( & V_102 -> V_109 , & V_2 -> V_110 ) ;
F_80 ( & V_2 -> V_81 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 ,
bool V_111 , T_1 V_105 )
{
struct V_101 * V_102 , * V_77 ;
F_108 ( V_112 ) ;
F_76 ( & V_2 -> V_81 ) ;
F_109 (handler, tmp, &ec->list, node) {
if ( V_111 || V_105 == V_102 -> V_105 ) {
F_110 ( & V_102 -> V_109 ) ;
F_106 ( & V_102 -> V_109 , & V_112 ) ;
}
}
F_80 ( & V_2 -> V_81 ) ;
F_109 (handler, tmp, &free_list, node)
F_101 ( V_102 ) ;
}
void F_111 ( struct V_1 * V_2 , T_1 V_105 )
{
F_107 ( V_2 , false , V_105 ) ;
}
static struct F_43 * F_112 ( T_1 * V_113 )
{
struct F_43 * V_114 ;
struct V_54 * V_55 ;
V_114 = F_104 ( sizeof ( struct F_43 ) , V_107 ) ;
if ( ! V_114 )
return NULL ;
F_113 ( & V_114 -> V_36 , V_115 ) ;
V_55 = & V_114 -> V_54 ;
V_55 -> V_19 = V_34 ;
V_55 -> V_63 = V_113 ;
V_55 -> V_61 = 1 ;
return V_114 ;
}
static void F_114 ( struct F_43 * V_114 )
{
if ( V_114 ) {
if ( V_114 -> V_102 )
F_101 ( V_114 -> V_102 ) ;
F_100 ( V_114 ) ;
}
}
static void V_115 ( struct V_116 * V_36 )
{
struct F_43 * V_114 = F_99 ( V_36 , struct F_43 , V_36 ) ;
struct V_101 * V_102 = V_114 -> V_102 ;
F_35 ( L_37 , V_102 -> V_105 ) ;
if ( V_102 -> V_106 )
V_102 -> V_106 ( V_102 -> V_20 ) ;
else if ( V_102 -> V_98 )
F_115 ( V_102 -> V_98 , NULL , NULL , NULL ) ;
F_35 ( L_38 , V_102 -> V_105 ) ;
F_114 ( V_114 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_1 V_39 = 0 ;
int V_89 ;
struct F_43 * V_114 ;
V_114 = F_112 ( & V_39 ) ;
if ( ! V_114 )
return - V_108 ;
V_89 = F_75 ( V_2 , & V_114 -> V_54 ) ;
if ( ! V_39 )
V_89 = - V_117 ;
if ( V_89 )
goto V_118;
V_114 -> V_102 = F_96 ( V_2 , V_39 ) ;
if ( ! V_114 -> V_102 ) {
V_89 = - V_117 ;
goto V_118;
}
F_35 ( L_39 , V_39 ) ;
if ( ! F_116 ( V_43 , & V_114 -> V_36 ) ) {
F_35 ( L_40 , V_39 ) ;
V_89 = - V_119 ;
}
V_118:
if ( V_89 )
F_114 ( V_114 ) ;
if ( V_20 )
* V_20 = V_39 ;
return V_89 ;
}
static void F_117 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_45 == V_52 ) {
if ( F_63 ( V_2 ) ) {
F_48 ( & V_2 -> V_41 , V_4 ) ;
if ( ! V_2 -> V_48 )
F_19 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
}
}
static void F_118 ( struct V_116 * V_36 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_99 ( V_36 , struct V_1 , V_36 ) ;
F_35 ( L_41 ) ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
while ( V_2 -> V_35 ) {
F_49 ( & V_2 -> V_41 , V_4 ) ;
( void ) F_43 ( V_2 , NULL ) ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
V_2 -> V_35 -- ;
if ( ! V_2 -> V_35 ) {
if ( V_45 == V_46 ||
V_45 == V_47 )
F_37 ( V_2 ) ;
}
}
F_49 ( & V_2 -> V_41 , V_4 ) ;
F_35 ( L_42 ) ;
F_117 ( V_2 ) ;
}
static T_3 F_119 ( T_4 V_120 ,
T_3 V_121 , void * V_20 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_20 ;
F_48 ( & V_2 -> V_41 , V_4 ) ;
F_19 ( V_2 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
return V_122 ;
}
static T_6
F_120 ( T_3 V_123 , T_7 V_88 ,
T_3 V_124 , T_8 * V_125 ,
void * V_126 , void * V_127 )
{
struct V_1 * V_2 = V_126 ;
int V_89 = 0 , V_37 , V_128 = V_124 / 8 ;
T_1 * V_39 = ( T_1 * ) V_125 ;
if ( ( V_88 > 0xFF ) || ! V_39 || ! V_126 )
return V_129 ;
if ( V_123 != V_130 && V_123 != V_131 )
return V_129 ;
if ( V_72 || V_124 > 8 )
F_81 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < V_128 ; ++ V_37 , ++ V_88 , ++ V_39 )
V_89 = ( V_123 == V_130 ) ?
F_83 ( V_2 , V_88 , V_39 ) :
F_84 ( V_2 , V_88 , * V_39 ) ;
if ( V_72 || V_124 > 8 )
F_82 ( V_2 ) ;
switch ( V_89 ) {
case - V_78 :
return V_129 ;
case - V_84 :
return V_132 ;
case - V_73 :
return V_133 ;
default:
return V_134 ;
}
}
static void F_121 ( struct V_1 * V_2 )
{
if ( V_95 == V_2 )
V_95 = NULL ;
if ( V_135 == V_2 )
V_135 = NULL ;
F_100 ( V_2 ) ;
}
static struct V_1 * F_122 ( void )
{
struct V_1 * V_2 = F_104 ( sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_2 )
return NULL ;
F_123 ( & V_2 -> V_81 ) ;
F_124 ( & V_2 -> V_31 ) ;
F_125 ( & V_2 -> V_110 ) ;
F_126 ( & V_2 -> V_41 ) ;
F_113 ( & V_2 -> V_36 , F_118 ) ;
V_2 -> V_17 = V_18 ;
return V_2 ;
}
static T_6
F_127 ( T_4 V_98 , T_3 V_136 ,
void * V_137 , void * * V_138 )
{
char V_139 [ 5 ] ;
struct V_140 V_141 = { sizeof( V_139 ) , V_139 } ;
struct V_1 * V_2 = V_137 ;
int V_39 = 0 ;
T_6 V_38 ;
V_38 = F_128 ( V_98 , V_142 , & V_141 ) ;
if ( F_129 ( V_38 ) && sscanf ( V_139 , L_43 , & V_39 ) == 1 )
F_103 ( V_2 , V_39 , V_98 , NULL , NULL ) ;
return V_134 ;
}
static T_6
F_130 ( T_4 V_98 , T_3 V_143 , void * V_137 , void * * V_144 )
{
T_6 V_38 ;
unsigned long long V_77 = 0 ;
struct V_1 * V_2 = V_137 ;
V_2 -> V_10 = V_2 -> V_16 = 0 ;
V_38 = F_131 ( V_98 , V_145 ,
V_146 , V_2 ) ;
if ( F_78 ( V_38 ) )
return V_38 ;
V_38 = F_132 ( V_98 , L_44 , NULL , & V_77 ) ;
if ( F_78 ( V_38 ) )
return V_38 ;
V_2 -> V_23 = V_77 ;
V_77 = 0 ;
F_132 ( V_98 , L_45 , NULL , & V_77 ) ;
V_2 -> V_82 = V_77 ;
V_2 -> V_98 = V_98 ;
return V_147 ;
}
static int F_133 ( struct V_1 * V_2 , bool V_148 )
{
T_6 V_38 ;
F_89 ( V_2 , false ) ;
if ( ! F_2 ( V_149 , & V_2 -> V_4 ) ) {
V_38 = F_134 ( V_2 -> V_98 ,
V_150 ,
& F_120 ,
NULL , V_2 ) ;
if ( F_78 ( V_38 ) ) {
if ( V_38 == V_132 ) {
F_135 ( L_46
L_47 ) ;
} else {
F_91 ( V_2 , false ) ;
return - V_84 ;
}
}
F_29 ( V_149 , & V_2 -> V_4 ) ;
}
if ( ! V_148 )
return 0 ;
if ( ! F_2 ( V_151 , & V_2 -> V_4 ) ) {
F_136 ( V_152 , V_2 -> V_98 , 1 ,
F_127 ,
NULL , V_2 , NULL ) ;
F_29 ( V_151 , & V_2 -> V_4 ) ;
}
if ( ! F_2 ( V_29 , & V_2 -> V_4 ) ) {
V_38 = F_137 ( NULL , V_2 -> V_23 ,
V_153 ,
& F_119 , V_2 ) ;
if ( F_129 ( V_38 ) ) {
F_29 ( V_29 , & V_2 -> V_4 ) ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_8 >= 1 )
F_15 ( V_2 , true ) ;
F_47 ( V_2 ) ;
}
}
return 0 ;
}
static void F_138 ( struct V_1 * V_2 )
{
if ( F_2 ( V_149 , & V_2 -> V_4 ) ) {
if ( F_78 ( F_139 ( V_2 -> V_98 ,
V_150 , & F_120 ) ) )
F_135 ( L_48 ) ;
F_31 ( V_149 , & V_2 -> V_4 ) ;
}
F_91 ( V_2 , false ) ;
if ( F_2 ( V_29 , & V_2 -> V_4 ) ) {
if ( F_78 ( F_140 ( NULL , V_2 -> V_23 ,
& F_119 ) ) )
F_135 ( L_49 ) ;
F_31 ( V_29 , & V_2 -> V_4 ) ;
}
if ( F_2 ( V_151 , & V_2 -> V_4 ) ) {
F_107 ( V_2 , true , 0 ) ;
F_31 ( V_151 , & V_2 -> V_4 ) ;
}
}
static int F_141 ( struct V_1 * V_2 , bool V_148 )
{
int V_49 ;
V_49 = F_133 ( V_2 , V_148 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_95 ) {
V_95 = V_2 ;
F_142 ( V_95 -> V_98 , L_50 ) ;
}
F_142 ( V_2 -> V_98 ,
L_51 ,
V_2 -> V_23 , V_2 -> V_10 , V_2 -> V_16 ) ;
return V_49 ;
}
static int F_143 ( struct V_1 * V_2 , T_4 V_98 ,
bool V_148 , bool V_154 )
{
int V_49 ;
if ( V_135 && V_135 -> V_98 != V_98 )
F_138 ( V_135 ) ;
if ( V_135 != V_2 )
F_121 ( V_135 ) ;
if ( V_2 -> V_98 != V_98 )
V_2 -> V_98 = V_98 ;
V_49 = F_141 ( V_2 , V_148 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_135 ) {
V_135 = V_2 ;
V_155 = V_154 ;
}
F_142 ( V_135 -> V_98 ,
L_52 ,
V_154 ? L_53 : L_54 ,
V_148 ? L_55 : L_56 ) ;
return V_49 ;
}
static bool F_144 ( T_4 * V_156 )
{
struct V_157 * V_158 ;
T_6 V_38 ;
T_4 V_98 ;
V_38 = F_145 ( V_159 , 1 ,
(struct V_160 * * ) & V_158 ) ;
if ( F_78 ( V_38 ) )
return false ;
V_38 = F_146 ( NULL , V_158 -> V_161 , & V_98 ) ;
if ( F_78 ( V_38 ) )
return false ;
* V_156 = V_98 ;
return true ;
}
static bool F_147 ( struct V_1 * V_2 )
{
if ( ! V_135 )
return false ;
if ( V_2 -> V_98 == V_135 -> V_98 &&
V_2 -> V_23 == V_135 -> V_23 &&
V_2 -> V_10 == V_135 -> V_10 &&
V_2 -> V_16 == V_135 -> V_16 )
return true ;
return false ;
}
static int F_148 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = NULL ;
int V_49 ;
strcpy ( F_149 ( V_163 ) , V_164 ) ;
strcpy ( F_150 ( V_163 ) , V_165 ) ;
V_2 = F_122 () ;
if ( ! V_2 )
return - V_108 ;
if ( F_130 ( V_163 -> V_98 , 0 , V_2 , NULL ) !=
V_147 ) {
V_49 = - V_78 ;
goto V_166;
}
if ( F_147 ( V_2 ) ) {
V_155 = false ;
F_151 ( V_2 -> V_98 , L_57 ) ;
F_121 ( V_2 ) ;
V_2 = V_135 ;
V_49 = F_143 ( V_2 , V_2 -> V_98 , true , false ) ;
} else
V_49 = F_141 ( V_2 , true ) ;
if ( V_49 )
goto V_167;
V_163 -> V_168 = V_2 ;
V_49 = ! ! F_152 ( V_2 -> V_16 , 1 , L_58 ) ;
F_153 ( ! V_49 , L_59 , V_2 -> V_16 ) ;
V_49 = ! ! F_152 ( V_2 -> V_10 , 1 , L_60 ) ;
F_153 ( ! V_49 , L_61 , V_2 -> V_10 ) ;
F_154 ( V_2 -> V_98 ) ;
F_151 ( V_2 -> V_98 , L_62 ) ;
return 0 ;
V_167:
if ( V_2 != V_135 )
F_107 ( V_2 , true , 0 ) ;
V_166:
if ( V_2 != V_135 )
F_121 ( V_2 ) ;
return V_49 ;
}
static int F_155 ( struct V_162 * V_163 )
{
struct V_1 * V_2 ;
if ( ! V_163 )
return - V_78 ;
V_2 = F_156 ( V_163 ) ;
F_157 ( V_2 -> V_16 , 1 ) ;
F_157 ( V_2 -> V_10 , 1 ) ;
V_163 -> V_168 = NULL ;
if ( V_2 != V_135 ) {
F_138 ( V_2 ) ;
F_121 ( V_2 ) ;
}
return 0 ;
}
static T_6
V_146 ( struct V_169 * V_170 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
if ( V_170 -> type != V_171 )
return V_134 ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_16 = V_170 -> V_20 . V_172 . V_173 ;
else if ( V_2 -> V_10 == 0 )
V_2 -> V_10 = V_170 -> V_20 . V_172 . V_173 ;
else
return V_147 ;
return V_134 ;
}
int T_9 F_158 ( void )
{
T_6 V_38 ;
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_122 () ;
if ( ! V_2 )
return - V_108 ;
V_38 = F_159 ( V_174 [ 0 ] . V_161 ,
F_130 , V_2 , NULL ) ;
if ( F_78 ( V_38 ) || ! V_2 -> V_98 ) {
V_49 = - V_84 ;
goto error;
}
V_49 = F_143 ( V_2 , V_2 -> V_98 , false , false ) ;
error:
if ( V_49 )
F_121 ( V_2 ) ;
return V_49 ;
}
int T_9 F_160 ( void )
{
T_4 V_98 ;
if ( ! V_135 )
return - V_84 ;
if ( ! V_155 )
return - V_84 ;
if ( ! F_144 ( & V_98 ) )
return - V_84 ;
return F_143 ( V_135 , V_98 , true , true ) ;
}
static int F_161 ( const struct V_175 * V_161 )
{
F_71 ( L_63 ) ;
V_42 = 1 ;
V_45 = V_46 ;
return 0 ;
}
static int F_162 ( const struct V_175 * V_161 )
{
F_71 ( L_64 ) ;
V_176 = 1 ;
return 0 ;
}
int T_9 F_163 ( void )
{
int V_49 ;
T_6 V_38 ;
struct V_157 * V_158 ;
struct V_1 * V_2 ;
V_2 = F_122 () ;
if ( ! V_2 )
return - V_108 ;
F_164 ( V_177 ) ;
V_38 = F_145 ( V_159 , 1 ,
(struct V_160 * * ) & V_158 ) ;
if ( F_78 ( V_38 ) ) {
V_49 = - V_84 ;
goto error;
}
if ( ! V_158 -> V_178 . V_88 || ! V_158 -> V_20 . V_88 ) {
V_49 = - V_84 ;
goto error;
}
if ( V_176 ) {
V_2 -> V_10 = V_158 -> V_20 . V_88 ;
V_2 -> V_16 = V_158 -> V_178 . V_88 ;
} else {
V_2 -> V_10 = V_158 -> V_178 . V_88 ;
V_2 -> V_16 = V_158 -> V_20 . V_88 ;
}
V_2 -> V_23 = V_158 -> V_23 ;
V_49 = F_143 ( V_2 , V_179 , false , true ) ;
error:
if ( V_49 )
F_121 ( V_2 ) ;
return V_49 ;
}
static void F_165 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_2 == V_95 ) {
F_48 ( & V_2 -> V_41 , V_4 ) ;
V_2 -> V_180 = V_72 ;
V_2 -> V_181 = V_70 ;
V_72 = true ;
V_70 = 0 ;
F_39 ( L_65 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_2 == V_95 ) {
F_48 ( & V_2 -> V_41 , V_4 ) ;
V_72 = V_2 -> V_180 ;
V_70 = V_2 -> V_181 ;
F_39 ( L_66 ) ;
F_49 ( & V_2 -> V_41 , V_4 ) ;
}
}
static int F_167 ( struct V_163 * V_182 )
{
struct V_1 * V_2 =
F_156 ( F_168 ( V_182 ) ) ;
F_165 ( V_2 ) ;
return 0 ;
}
static int F_169 ( struct V_163 * V_182 )
{
struct V_1 * V_2 =
F_156 ( F_168 ( V_182 ) ) ;
F_166 ( V_2 ) ;
return 0 ;
}
static int F_170 ( struct V_163 * V_182 )
{
struct V_1 * V_2 =
F_156 ( F_168 ( V_182 ) ) ;
if ( V_7 )
F_54 ( V_2 ) ;
return 0 ;
}
static int F_171 ( struct V_163 * V_182 )
{
struct V_1 * V_2 =
F_156 ( F_168 ( V_182 ) ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_172 ( const char * V_93 , struct V_183 * V_184 )
{
int V_89 = 0 ;
if ( ! strncmp ( V_93 , L_67 , sizeof( L_67 ) - 1 ) ) {
V_45 = V_46 ;
F_46 ( L_68 ) ;
} else if ( ! strncmp ( V_93 , L_69 , sizeof( L_69 ) - 1 ) ) {
V_45 = V_47 ;
F_46 ( L_70 ) ;
} else if ( ! strncmp ( V_93 , L_71 , sizeof( L_71 ) - 1 ) ) {
V_45 = V_52 ;
F_46 ( L_72 ) ;
} else
V_89 = - V_78 ;
return V_89 ;
}
static int F_173 ( char * V_141 , struct V_183 * V_184 )
{
switch ( V_45 ) {
case V_46 :
return sprintf ( V_141 , L_67 ) ;
case V_47 :
return sprintf ( V_141 , L_69 ) ;
case V_52 :
return sprintf ( V_141 , L_71 ) ;
default:
return sprintf ( V_141 , L_73 ) ;
}
return 0 ;
}
static inline int F_174 ( void )
{
if ( ! V_43 ) {
V_43 = F_175 ( L_74 , 0 ,
V_185 ) ;
if ( ! V_43 )
return - V_84 ;
}
return 0 ;
}
static inline void F_176 ( void )
{
if ( V_43 ) {
F_177 ( V_43 ) ;
V_43 = NULL ;
}
}
int T_9 F_178 ( void )
{
int V_89 ;
V_89 = F_174 () ;
if ( V_89 )
goto V_118;
V_89 = F_179 ( & V_186 ) ;
if ( V_89 )
goto V_118;
V_118:
if ( V_89 )
F_176 () ;
return V_89 ;
}
