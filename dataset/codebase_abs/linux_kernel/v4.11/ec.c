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
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( F_1 ( V_2 ) )
F_38 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
bool V_30 ;
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_30 = ! V_2 -> V_35 ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_30 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_31 , F_45 ( V_2 ) ) ;
if ( V_38 )
F_48 ( V_38 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_40 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_46 ( V_2 ) ;
}
static bool F_50 ( struct V_1 * V_2 )
{
bool V_39 = true ;
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_40 == V_41 ||
V_40 == V_42 ||
! F_2 ( V_33 , & V_2 -> V_4 ) ||
( V_2 -> V_43 && V_2 -> V_43 -> V_19 == V_34 ) )
V_39 = false ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_39 ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_44 = 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_2 -> V_43 && ( V_2 -> V_43 -> V_4 & V_45 ) )
V_44 = 1 ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_44 ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_44 = 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_2 -> V_43 && ( V_2 -> V_43 -> V_4 & V_46 ) )
V_44 = 1 ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_44 ;
}
static inline void F_53 ( struct V_1 * V_2 , unsigned long V_32 )
{
V_2 -> V_43 -> V_4 |= V_32 ;
if ( V_2 -> V_43 -> V_19 == V_34 ) {
if ( V_40 == V_41 &&
V_32 == V_45 )
F_37 ( V_2 ) ;
if ( V_40 == V_42 &&
V_32 == V_46 )
F_37 ( V_2 ) ;
if ( V_40 == V_47 &&
V_32 == V_46 )
F_29 ( V_48 , & V_2 -> V_4 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
T_1 V_51 ;
bool V_52 = false ;
F_54 ( L_19 , F_55 () ? L_20 : L_21 ,
F_56 () ) ;
F_22 ( V_2 ) ;
V_51 = F_5 ( V_2 ) ;
V_50 = V_2 -> V_43 ;
if ( ! V_50 || ! ( V_50 -> V_4 & V_45 ) ) {
if ( V_40 == V_47 &&
( ! V_2 -> V_35 ||
F_2 ( V_48 , & V_2 -> V_4 ) ) ) {
F_31 ( V_48 , & V_2 -> V_4 ) ;
F_37 ( V_2 ) ;
}
}
if ( ! V_50 )
goto V_53;
if ( V_50 -> V_4 & V_45 ) {
if ( V_50 -> V_54 > V_50 -> V_55 ) {
if ( ( V_51 & V_14 ) == 0 )
F_11 ( V_2 , V_50 -> V_56 [ V_50 -> V_55 ++ ] ) ;
else
goto V_53;
} else if ( V_50 -> V_57 > V_50 -> V_58 ) {
if ( ( V_51 & V_15 ) == 1 ) {
V_50 -> V_59 [ V_50 -> V_58 ++ ] = F_8 ( V_2 ) ;
if ( V_50 -> V_57 == V_50 -> V_58 ) {
F_53 ( V_2 , V_46 ) ;
if ( V_50 -> V_19 == V_34 )
F_35 ( L_22 ,
F_12 ( V_34 ) ) ;
V_52 = true ;
}
} else
goto V_53;
} else if ( V_50 -> V_54 == V_50 -> V_55 &&
( V_51 & V_14 ) == 0 ) {
F_53 ( V_2 , V_46 ) ;
V_52 = true ;
}
goto V_60;
} else {
if ( V_61 &&
! ( V_51 & V_11 ) &&
( V_50 -> V_19 == V_34 ) ) {
F_53 ( V_2 , V_45 ) ;
V_50 -> V_59 [ V_50 -> V_58 ++ ] = 0x00 ;
F_53 ( V_2 , V_46 ) ;
F_35 ( L_23 ,
F_12 ( V_34 ) ) ;
V_52 = true ;
} else if ( ( V_51 & V_14 ) == 0 ) {
F_9 ( V_2 , V_50 -> V_19 ) ;
F_53 ( V_2 , V_45 ) ;
} else
goto V_53;
goto V_60;
}
V_53:
if ( ! ( V_51 & V_11 ) ) {
if ( F_55 () && V_50 ) {
if ( V_50 -> V_62 < V_63 )
++ V_50 -> V_62 ;
if ( V_50 -> V_62 == V_63 )
F_27 ( V_2 , V_64 ) ;
}
}
V_60:
if ( V_51 & V_11 )
F_33 ( V_2 ) ;
if ( V_52 && F_55 () )
F_26 ( & V_2 -> V_31 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
V_2 -> V_43 -> V_62 = V_2 -> V_43 -> V_55 = V_2 -> V_43 -> V_58 = 0 ;
V_2 -> V_43 -> V_4 = 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
unsigned long V_65 = F_59 ( V_2 -> V_66 ) ;
unsigned long V_67 = V_2 -> V_17 + V_65 ;
do {
if ( V_2 -> V_68 ) {
if ( F_52 ( V_2 ) )
return 0 ;
F_60 ( F_61 ( V_65 ) ) ;
} else {
if ( ! F_51 ( V_2 ) &&
! F_50 ( V_2 ) )
break;
if ( F_62 ( V_2 -> V_31 ,
F_52 ( V_2 ) ,
V_65 ) )
return 0 ;
}
} while ( F_63 ( V_18 , V_67 ) );
return - V_69 ;
}
static int F_64 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_70 = 5 ;
while ( V_70 -- ) {
unsigned long V_71 = V_18 +
F_65 ( V_72 ) ;
do {
if ( ! F_58 ( V_2 ) )
return 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
} while ( F_63 ( V_18 , V_71 ) );
F_66 ( L_24 ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_57 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
return - V_69 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
unsigned long V_73 ;
int V_44 = 0 ;
F_43 ( & V_2 -> V_37 , V_73 ) ;
if ( ! F_32 ( V_2 ) ) {
V_44 = - V_74 ;
goto V_75;
}
F_68 ( V_2 , L_25 ) ;
V_2 -> V_43 = V_50 ;
F_69 ( L_26 , F_12 ( V_50 -> V_19 ) ) ;
F_57 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_73 ) ;
V_44 = F_64 ( V_2 ) ;
F_43 ( & V_2 -> V_37 , V_73 ) ;
if ( V_50 -> V_62 == V_63 )
F_30 ( V_2 , V_64 ) ;
F_69 ( L_27 , F_12 ( V_50 -> V_19 ) ) ;
V_2 -> V_43 = NULL ;
F_25 ( V_2 ) ;
F_68 ( V_2 , L_28 ) ;
V_75:
F_44 ( & V_2 -> V_37 , V_73 ) ;
return V_44 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_51 ;
T_3 V_76 ;
if ( ! V_2 || ( ! V_50 ) || ( V_50 -> V_54 && ! V_50 -> V_56 ) || ( V_50 -> V_57 && ! V_50 -> V_59 ) )
return - V_74 ;
if ( V_50 -> V_59 )
memset ( V_50 -> V_59 , 0 , V_50 -> V_57 ) ;
F_71 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 ) {
V_51 = F_72 ( V_79 , & V_76 ) ;
if ( F_73 ( V_51 ) ) {
V_51 = - V_80 ;
goto V_75;
}
}
V_51 = F_67 ( V_2 , V_50 ) ;
if ( V_2 -> V_78 )
F_74 ( V_76 ) ;
V_75:
F_75 ( & V_2 -> V_77 ) ;
return V_51 ;
}
static int F_76 ( struct V_1 * V_2 )
{
T_1 V_81 ;
struct V_49 V_50 = { . V_19 = V_82 ,
. V_56 = NULL , . V_59 = & V_81 ,
. V_54 = 0 , . V_57 = 1 } ;
return F_70 ( V_2 , & V_50 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_49 V_50 = { . V_19 = V_83 ,
. V_56 = NULL , . V_59 = NULL ,
. V_54 = 0 , . V_57 = 0 } ;
return ( F_5 ( V_2 ) & V_12 ) ?
F_70 ( V_2 , & V_50 ) : 0 ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_84 , T_1 * V_20 )
{
int V_85 ;
T_1 V_81 ;
struct V_49 V_50 = { . V_19 = V_86 ,
. V_56 = & V_84 , . V_59 = & V_81 ,
. V_54 = 1 , . V_57 = 1 } ;
V_85 = F_70 ( V_2 , & V_50 ) ;
* V_20 = V_81 ;
return V_85 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 V_84 , T_1 V_20 )
{
T_1 V_56 [ 2 ] = { V_84 , V_20 } ;
struct V_49 V_50 = { . V_19 = V_87 ,
. V_56 = V_56 , . V_59 = NULL ,
. V_54 = 2 , . V_57 = 0 } ;
return F_70 ( V_2 , & V_50 ) ;
}
int F_80 ( T_1 V_88 , T_1 * V_89 )
{
int V_53 ;
T_1 V_90 ;
if ( ! V_91 )
return - V_80 ;
V_53 = F_78 ( V_91 , V_88 , & V_90 ) ;
if ( ! V_53 ) {
* V_89 = V_90 ;
return 0 ;
}
return V_53 ;
}
int F_81 ( T_1 V_88 , T_1 V_89 )
{
int V_53 ;
if ( ! V_91 )
return - V_80 ;
V_53 = F_79 ( V_91 , V_88 , V_89 ) ;
return V_53 ;
}
int F_82 ( T_1 V_19 ,
const T_1 * V_56 , unsigned V_92 ,
T_1 * V_59 , unsigned V_93 )
{
struct V_49 V_50 = { . V_19 = V_19 ,
. V_56 = V_56 , . V_59 = V_59 ,
. V_54 = V_92 , . V_57 = V_93 } ;
if ( ! V_91 )
return - V_80 ;
return F_70 ( V_91 , & V_50 ) ;
}
T_4 F_83 ( void )
{
if ( ! V_91 )
return NULL ;
return V_91 -> V_94 ;
}
static void F_84 ( struct V_1 * V_2 , bool V_95 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! F_34 ( V_3 , & V_2 -> V_4 ) ) {
F_28 ( L_29 ) ;
if ( ! V_95 ) {
F_24 ( V_2 ) ;
F_68 ( V_2 , L_30 ) ;
}
F_39 ( L_31 ) ;
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static bool F_85 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_30 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_30 = F_4 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_30 ;
}
static void F_86 ( struct V_1 * V_2 , bool V_96 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_28 ( L_32 ) ;
F_29 ( V_5 , & V_2 -> V_4 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_47 ( V_2 -> V_31 , F_85 ( V_2 ) ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! V_96 ) {
F_25 ( V_2 ) ;
F_68 ( V_2 , L_33 ) ;
} else if ( ! V_7 )
F_40 ( V_2 ) ;
F_31 ( V_3 , & V_2 -> V_4 ) ;
F_31 ( V_5 , & V_2 -> V_4 ) ;
F_39 ( L_34 ) ;
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_68 = true ;
V_2 -> V_66 = 0 ;
F_39 ( L_35 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_68 = V_97 ;
V_2 -> V_66 = V_98 ;
F_39 ( L_36 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
void F_89 ( void )
{
struct V_1 * V_2 = V_91 ;
if ( ! V_2 )
return;
F_71 ( & V_2 -> V_77 ) ;
F_86 ( V_2 , true ) ;
F_75 ( & V_2 -> V_77 ) ;
}
void F_90 ( void )
{
if ( V_91 )
F_84 ( V_91 , true ) ;
}
static struct V_99 *
F_91 ( struct V_99 * V_100 )
{
if ( V_100 )
F_92 ( & V_100 -> V_101 ) ;
return V_100 ;
}
static struct V_99 *
F_93 ( struct V_1 * V_2 , T_1 V_102 )
{
struct V_99 * V_100 ;
bool V_103 = false ;
F_71 ( & V_2 -> V_77 ) ;
F_94 (handler, &ec->list, node) {
if ( V_102 == V_100 -> V_104 ) {
V_103 = true ;
break;
}
}
F_75 ( & V_2 -> V_77 ) ;
return V_103 ? F_91 ( V_100 ) : NULL ;
}
static void F_95 ( struct V_101 * V_101 )
{
struct V_99 * V_100 =
F_96 ( V_101 , struct V_99 , V_101 ) ;
F_97 ( V_100 ) ;
}
static void F_98 ( struct V_99 * V_100 )
{
F_99 ( & V_100 -> V_101 , F_95 ) ;
}
int F_100 ( struct V_1 * V_2 , T_1 V_104 ,
T_4 V_94 , T_5 V_105 ,
void * V_20 )
{
struct V_99 * V_100 =
F_101 ( sizeof( struct V_99 ) , V_106 ) ;
if ( ! V_100 )
return - V_107 ;
V_100 -> V_104 = V_104 ;
V_100 -> V_94 = V_94 ;
V_100 -> V_105 = V_105 ;
V_100 -> V_20 = V_20 ;
F_71 ( & V_2 -> V_77 ) ;
F_102 ( & V_100 -> V_101 ) ;
F_103 ( & V_100 -> V_108 , & V_2 -> V_109 ) ;
F_75 ( & V_2 -> V_77 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 ,
bool V_110 , T_1 V_104 )
{
struct V_99 * V_100 , * V_73 ;
F_105 ( V_111 ) ;
F_71 ( & V_2 -> V_77 ) ;
F_106 (handler, tmp, &ec->list, node) {
if ( V_110 || V_104 == V_100 -> V_104 ) {
F_107 ( & V_100 -> V_108 ) ;
F_103 ( & V_100 -> V_108 , & V_111 ) ;
}
}
F_75 ( & V_2 -> V_77 ) ;
F_106 (handler, tmp, &free_list, node)
F_98 ( V_100 ) ;
}
void F_108 ( struct V_1 * V_2 , T_1 V_104 )
{
F_104 ( V_2 , false , V_104 ) ;
}
static struct V_112 * F_109 ( T_1 * V_113 )
{
struct V_112 * V_114 ;
struct V_49 * V_50 ;
V_114 = F_101 ( sizeof ( struct V_112 ) , V_106 ) ;
if ( ! V_114 )
return NULL ;
F_110 ( & V_114 -> V_36 , V_115 ) ;
V_50 = & V_114 -> V_49 ;
V_50 -> V_19 = V_34 ;
V_50 -> V_59 = V_113 ;
V_50 -> V_57 = 1 ;
return V_114 ;
}
static void F_111 ( struct V_112 * V_114 )
{
if ( V_114 ) {
if ( V_114 -> V_100 )
F_98 ( V_114 -> V_100 ) ;
F_97 ( V_114 ) ;
}
}
static void V_115 ( struct V_116 * V_36 )
{
struct V_112 * V_114 = F_96 ( V_36 , struct V_112 , V_36 ) ;
struct V_99 * V_100 = V_114 -> V_100 ;
F_35 ( L_37 , V_100 -> V_104 ) ;
if ( V_100 -> V_105 )
V_100 -> V_105 ( V_100 -> V_20 ) ;
else if ( V_100 -> V_94 )
F_112 ( V_100 -> V_94 , NULL , NULL , NULL ) ;
F_35 ( L_38 , V_100 -> V_104 ) ;
F_111 ( V_114 ) ;
}
static int V_112 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_1 V_102 = 0 ;
int V_85 ;
struct V_112 * V_114 ;
V_114 = F_109 ( & V_102 ) ;
if ( ! V_114 )
return - V_107 ;
V_85 = F_70 ( V_2 , & V_114 -> V_49 ) ;
if ( ! V_102 )
V_85 = - V_117 ;
if ( V_85 )
goto V_118;
V_114 -> V_100 = F_93 ( V_2 , V_102 ) ;
if ( ! V_114 -> V_100 ) {
V_85 = - V_117 ;
goto V_118;
}
F_35 ( L_39 , V_102 ) ;
if ( ! F_113 ( V_38 , & V_114 -> V_36 ) ) {
F_35 ( L_40 , V_102 ) ;
V_85 = - V_119 ;
}
V_118:
if ( V_85 )
F_111 ( V_114 ) ;
if ( V_20 )
* V_20 = V_102 ;
return V_85 ;
}
static void F_114 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_40 == V_47 ) {
if ( F_58 ( V_2 ) ) {
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! V_2 -> V_43 )
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
}
}
static void F_115 ( struct V_116 * V_36 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_96 ( V_36 , struct V_1 , V_36 ) ;
F_35 ( L_41 ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
while ( V_2 -> V_35 ) {
F_44 ( & V_2 -> V_37 , V_4 ) ;
( void ) V_112 ( V_2 , NULL ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_35 -- ;
if ( ! V_2 -> V_35 ) {
if ( V_40 == V_41 ||
V_40 == V_42 )
F_37 ( V_2 ) ;
}
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_35 ( L_42 ) ;
F_114 ( V_2 ) ;
}
static T_3 F_116 ( T_4 V_120 ,
T_3 V_121 , void * V_20 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_20 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_122 ;
}
static T_6
F_117 ( T_3 V_123 , T_7 V_84 ,
T_3 V_124 , T_8 * V_125 ,
void * V_126 , void * V_127 )
{
struct V_1 * V_2 = V_126 ;
int V_85 = 0 , V_128 , V_129 = V_124 / 8 ;
T_1 * V_102 = ( T_1 * ) V_125 ;
if ( ( V_84 > 0xFF ) || ! V_102 || ! V_126 )
return V_130 ;
if ( V_123 != V_131 && V_123 != V_132 )
return V_130 ;
if ( V_2 -> V_68 || V_124 > 8 )
F_76 ( V_2 ) ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 , ++ V_84 , ++ V_102 )
V_85 = ( V_123 == V_131 ) ?
F_78 ( V_2 , V_84 , V_102 ) :
F_79 ( V_2 , V_84 , * V_102 ) ;
if ( V_2 -> V_68 || V_124 > 8 )
F_77 ( V_2 ) ;
switch ( V_85 ) {
case - V_74 :
return V_130 ;
case - V_80 :
return V_133 ;
case - V_69 :
return V_134 ;
default:
return V_135 ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
if ( V_91 == V_2 )
V_91 = NULL ;
if ( V_136 == V_2 )
V_136 = NULL ;
F_97 ( V_2 ) ;
}
static struct V_1 * F_119 ( void )
{
struct V_1 * V_2 = F_101 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 )
return NULL ;
F_120 ( & V_2 -> V_77 ) ;
F_121 ( & V_2 -> V_31 ) ;
F_122 ( & V_2 -> V_109 ) ;
F_123 ( & V_2 -> V_37 ) ;
F_110 ( & V_2 -> V_36 , F_115 ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_68 = true ;
V_2 -> V_66 = 0 ;
return V_2 ;
}
static T_6
F_124 ( T_4 V_94 , T_3 V_137 ,
void * V_138 , void * * V_139 )
{
char V_140 [ 5 ] ;
struct V_141 V_142 = { sizeof( V_140 ) , V_140 } ;
struct V_1 * V_2 = V_138 ;
int V_102 = 0 ;
T_6 V_51 ;
V_51 = F_125 ( V_94 , V_143 , & V_142 ) ;
if ( F_126 ( V_51 ) && sscanf ( V_140 , L_43 , & V_102 ) == 1 )
F_100 ( V_2 , V_102 , V_94 , NULL , NULL ) ;
return V_135 ;
}
static T_6
F_127 ( T_4 V_94 , T_3 V_144 , void * V_138 , void * * V_145 )
{
T_6 V_51 ;
unsigned long long V_73 = 0 ;
struct V_1 * V_2 = V_138 ;
V_2 -> V_10 = V_2 -> V_16 = 0 ;
V_51 = F_128 ( V_94 , V_146 ,
V_147 , V_2 ) ;
if ( F_73 ( V_51 ) )
return V_51 ;
V_51 = F_129 ( V_94 , L_44 , NULL , & V_73 ) ;
if ( F_73 ( V_51 ) )
return V_51 ;
V_2 -> V_23 = V_73 ;
V_73 = 0 ;
F_129 ( V_94 , L_45 , NULL , & V_73 ) ;
V_2 -> V_78 = V_73 ;
V_2 -> V_94 = V_94 ;
return V_148 ;
}
static int F_130 ( struct V_1 * V_2 , bool V_149 )
{
T_6 V_51 ;
F_84 ( V_2 , false ) ;
if ( ! F_2 ( V_150 , & V_2 -> V_4 ) ) {
F_87 ( V_2 ) ;
V_51 = F_131 ( V_2 -> V_94 ,
V_151 ,
& F_117 ,
NULL , V_2 ) ;
if ( F_73 ( V_51 ) ) {
if ( V_51 == V_133 ) {
F_132 ( L_46
L_47 ) ;
} else {
F_86 ( V_2 , false ) ;
return - V_80 ;
}
}
F_29 ( V_150 , & V_2 -> V_4 ) ;
}
if ( ! V_149 )
return 0 ;
if ( ! F_2 ( V_152 , & V_2 -> V_4 ) ) {
F_133 ( V_153 , V_2 -> V_94 , 1 ,
F_124 ,
NULL , V_2 , NULL ) ;
F_29 ( V_152 , & V_2 -> V_4 ) ;
}
if ( ! F_2 ( V_29 , & V_2 -> V_4 ) ) {
V_51 = F_134 ( NULL , V_2 -> V_23 ,
V_154 ,
& F_116 , V_2 ) ;
if ( F_126 ( V_51 ) ) {
F_29 ( V_29 , & V_2 -> V_4 ) ;
F_88 ( V_2 ) ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_8 >= 1 )
F_15 ( V_2 , true ) ;
F_42 ( V_2 ) ;
}
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
if ( F_2 ( V_150 , & V_2 -> V_4 ) ) {
if ( F_73 ( F_136 ( V_2 -> V_94 ,
V_151 , & F_117 ) ) )
F_132 ( L_48 ) ;
F_31 ( V_150 , & V_2 -> V_4 ) ;
}
F_86 ( V_2 , false ) ;
if ( F_2 ( V_29 , & V_2 -> V_4 ) ) {
if ( F_73 ( F_137 ( NULL , V_2 -> V_23 ,
& F_116 ) ) )
F_132 ( L_49 ) ;
F_31 ( V_29 , & V_2 -> V_4 ) ;
}
if ( F_2 ( V_152 , & V_2 -> V_4 ) ) {
F_104 ( V_2 , true , 0 ) ;
F_31 ( V_152 , & V_2 -> V_4 ) ;
}
}
static int F_138 ( struct V_1 * V_2 , bool V_149 )
{
int V_44 ;
V_44 = F_130 ( V_2 , V_149 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_91 ) {
V_91 = V_2 ;
F_139 ( V_91 -> V_94 , L_50 ) ;
}
F_139 ( V_2 -> V_94 ,
L_51 ,
V_2 -> V_23 , V_2 -> V_10 , V_2 -> V_16 ) ;
return V_44 ;
}
static int F_140 ( struct V_1 * V_2 , T_4 V_94 ,
bool V_149 , bool V_155 )
{
int V_44 ;
if ( V_136 && V_136 -> V_94 != V_94 )
F_135 ( V_136 ) ;
if ( V_136 != V_2 )
F_118 ( V_136 ) ;
if ( V_2 -> V_94 != V_94 )
V_2 -> V_94 = V_94 ;
V_44 = F_138 ( V_2 , V_149 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_136 ) {
V_136 = V_2 ;
V_156 = V_155 ;
}
F_139 ( V_136 -> V_94 ,
L_52 ,
V_155 ? L_53 : L_54 ,
V_149 ? L_55 : L_56 ) ;
return V_44 ;
}
static bool F_141 ( T_4 * V_157 )
{
struct V_158 * V_159 ;
T_6 V_51 ;
T_4 V_94 ;
V_51 = F_142 ( V_160 , 1 ,
(struct V_161 * * ) & V_159 ) ;
if ( F_73 ( V_51 ) )
return false ;
V_51 = F_143 ( NULL , V_159 -> V_162 , & V_94 ) ;
if ( F_73 ( V_51 ) )
return false ;
* V_157 = V_94 ;
return true ;
}
static bool F_144 ( struct V_1 * V_2 )
{
if ( ! V_136 )
return false ;
if ( V_2 -> V_94 == V_136 -> V_94 &&
V_2 -> V_23 == V_136 -> V_23 &&
V_2 -> V_10 == V_136 -> V_10 &&
V_2 -> V_16 == V_136 -> V_16 )
return true ;
return false ;
}
static int F_145 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = NULL ;
int V_44 ;
strcpy ( F_146 ( V_164 ) , V_165 ) ;
strcpy ( F_147 ( V_164 ) , V_166 ) ;
V_2 = F_119 () ;
if ( ! V_2 )
return - V_107 ;
if ( F_127 ( V_164 -> V_94 , 0 , V_2 , NULL ) !=
V_148 ) {
V_44 = - V_74 ;
goto V_167;
}
if ( F_144 ( V_2 ) ) {
V_156 = false ;
F_148 ( V_2 -> V_94 , L_57 ) ;
F_118 ( V_2 ) ;
V_2 = V_136 ;
V_44 = F_140 ( V_2 , V_2 -> V_94 , true , false ) ;
} else
V_44 = F_138 ( V_2 , true ) ;
if ( V_44 )
goto V_168;
V_164 -> V_169 = V_2 ;
V_44 = ! ! F_149 ( V_2 -> V_16 , 1 , L_58 ) ;
F_150 ( ! V_44 , L_59 , V_2 -> V_16 ) ;
V_44 = ! ! F_149 ( V_2 -> V_10 , 1 , L_60 ) ;
F_150 ( ! V_44 , L_61 , V_2 -> V_10 ) ;
F_151 ( V_2 -> V_94 ) ;
F_148 ( V_2 -> V_94 , L_62 ) ;
return 0 ;
V_168:
if ( V_2 != V_136 )
F_104 ( V_2 , true , 0 ) ;
V_167:
if ( V_2 != V_136 )
F_118 ( V_2 ) ;
return V_44 ;
}
static int F_152 ( struct V_163 * V_164 )
{
struct V_1 * V_2 ;
if ( ! V_164 )
return - V_74 ;
V_2 = F_153 ( V_164 ) ;
F_154 ( V_2 -> V_16 , 1 ) ;
F_154 ( V_2 -> V_10 , 1 ) ;
V_164 -> V_169 = NULL ;
if ( V_2 != V_136 ) {
F_135 ( V_2 ) ;
F_118 ( V_2 ) ;
}
return 0 ;
}
static T_6
V_147 ( struct V_170 * V_171 , void * V_138 )
{
struct V_1 * V_2 = V_138 ;
if ( V_171 -> type != V_172 )
return V_135 ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_16 = V_171 -> V_20 . V_173 . V_174 ;
else if ( V_2 -> V_10 == 0 )
V_2 -> V_10 = V_171 -> V_20 . V_173 . V_174 ;
else
return V_148 ;
return V_135 ;
}
int T_9 F_155 ( void )
{
T_6 V_51 ;
struct V_1 * V_2 ;
int V_44 ;
V_2 = F_119 () ;
if ( ! V_2 )
return - V_107 ;
V_51 = F_156 ( V_175 [ 0 ] . V_162 ,
F_127 , V_2 , NULL ) ;
if ( F_73 ( V_51 ) || ! V_2 -> V_94 ) {
V_44 = - V_80 ;
goto error;
}
V_44 = F_140 ( V_2 , V_2 -> V_94 , false , false ) ;
error:
if ( V_44 )
F_118 ( V_2 ) ;
return V_44 ;
}
int T_9 F_157 ( void )
{
T_4 V_94 ;
if ( ! V_136 )
return - V_80 ;
if ( ! V_156 )
return - V_80 ;
if ( ! F_141 ( & V_94 ) )
return - V_80 ;
return F_140 ( V_136 , V_94 , true , true ) ;
}
static int F_158 ( const struct V_176 * V_162 )
{
F_66 ( L_63 ) ;
V_177 = 1 ;
return 0 ;
}
int T_9 F_159 ( void )
{
int V_44 ;
T_6 V_51 ;
struct V_158 * V_159 ;
struct V_1 * V_2 ;
V_2 = F_119 () ;
if ( ! V_2 )
return - V_107 ;
F_160 ( V_178 ) ;
V_51 = F_142 ( V_160 , 1 ,
(struct V_161 * * ) & V_159 ) ;
if ( F_73 ( V_51 ) ) {
V_44 = - V_80 ;
goto error;
}
if ( ! V_159 -> V_179 . V_84 || ! V_159 -> V_20 . V_84 ) {
V_44 = - V_80 ;
goto error;
}
if ( V_177 ) {
V_2 -> V_10 = V_159 -> V_20 . V_84 ;
V_2 -> V_16 = V_159 -> V_179 . V_84 ;
} else {
V_2 -> V_10 = V_159 -> V_179 . V_84 ;
V_2 -> V_16 = V_159 -> V_20 . V_84 ;
}
V_2 -> V_23 = V_159 -> V_23 ;
V_44 = F_140 ( V_2 , V_180 , false , true ) ;
error:
if ( V_44 )
F_118 ( V_2 ) ;
return V_44 ;
}
static int F_161 ( struct V_164 * V_181 )
{
struct V_1 * V_2 =
F_153 ( F_162 ( V_181 ) ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_164 * V_181 )
{
struct V_1 * V_2 =
F_153 ( F_162 ( V_181 ) ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_164 * V_181 )
{
struct V_1 * V_2 =
F_153 ( F_162 ( V_181 ) ) ;
if ( V_7 )
F_49 ( V_2 ) ;
return 0 ;
}
static int F_165 ( struct V_164 * V_181 )
{
struct V_1 * V_2 =
F_153 ( F_162 ( V_181 ) ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_166 ( const char * V_89 , struct V_182 * V_183 )
{
int V_85 = 0 ;
if ( ! strncmp ( V_89 , L_64 , sizeof( L_64 ) - 1 ) ) {
V_40 = V_41 ;
F_167 ( L_65 ) ;
} else if ( ! strncmp ( V_89 , L_66 , sizeof( L_66 ) - 1 ) ) {
V_40 = V_42 ;
F_167 ( L_67 ) ;
} else if ( ! strncmp ( V_89 , L_68 , sizeof( L_68 ) - 1 ) ) {
V_40 = V_47 ;
F_167 ( L_69 ) ;
} else
V_85 = - V_74 ;
return V_85 ;
}
static int F_168 ( char * V_142 , struct V_182 * V_183 )
{
switch ( V_40 ) {
case V_41 :
return sprintf ( V_142 , L_64 ) ;
case V_42 :
return sprintf ( V_142 , L_66 ) ;
case V_47 :
return sprintf ( V_142 , L_68 ) ;
default:
return sprintf ( V_142 , L_70 ) ;
}
return 0 ;
}
static inline int F_169 ( void )
{
if ( ! V_38 ) {
V_38 = F_170 ( L_71 , 0 ,
V_184 ) ;
if ( ! V_38 )
return - V_80 ;
}
return 0 ;
}
static inline void F_171 ( void )
{
if ( V_38 ) {
F_172 ( V_38 ) ;
V_38 = NULL ;
}
}
int T_9 F_173 ( void )
{
int V_85 ;
V_85 = F_169 () ;
if ( V_85 )
goto V_118;
V_85 = F_174 ( & V_185 ) ;
if ( V_85 )
goto V_118;
V_118:
if ( V_85 )
F_171 () ;
return V_85 ;
}
