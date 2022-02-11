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
static void F_27 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_32 , & V_2 -> V_4 ) ) {
F_20 ( V_2 , false ) ;
F_28 ( L_13 ) ;
F_29 ( V_32 , & V_2 -> V_4 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
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
F_27 ( V_2 ) ;
if ( ! F_3 ( V_2 ) )
return;
if ( ! F_34 ( V_33 , & V_2 -> V_4 ) ) {
F_35 ( L_15 ,
F_12 ( V_34 ) ) ;
V_2 -> V_35 ++ ;
F_36 ( & V_2 -> V_36 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
if ( F_38 ( V_33 , & V_2 -> V_4 ) )
F_35 ( L_16 ,
F_12 ( V_34 ) ) ;
F_30 ( V_2 ) ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
if ( ! F_34 ( V_6 , & V_2 -> V_4 ) )
F_40 ( L_17 ) ;
if ( ! F_2 ( V_33 , & V_2 -> V_4 ) )
F_19 ( V_2 ) ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
if ( F_38 ( V_6 , & V_2 -> V_4 ) )
F_40 ( L_18 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( F_1 ( V_2 ) )
F_39 ( V_2 ) ;
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
F_41 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_46 ( V_2 ) ;
}
void F_50 ( void )
{
if ( V_39 )
F_46 ( V_39 ) ;
F_51 () ;
}
static bool F_52 ( struct V_1 * V_2 )
{
bool V_40 = true ;
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_41 == V_42 ||
V_41 == V_43 ||
! F_2 ( V_33 , & V_2 -> V_4 ) ||
( V_2 -> V_44 && V_2 -> V_44 -> V_19 == V_34 ) )
V_40 = false ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_40 ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_45 = 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_2 -> V_44 && ( V_2 -> V_44 -> V_4 & V_46 ) )
V_45 = 1 ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_45 ;
}
static int F_54 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_45 = 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( V_2 -> V_44 && ( V_2 -> V_44 -> V_4 & V_47 ) )
V_45 = 1 ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_45 ;
}
static inline void F_55 ( struct V_1 * V_2 , unsigned long V_48 )
{
V_2 -> V_44 -> V_4 |= V_48 ;
if ( V_2 -> V_44 -> V_19 == V_34 ) {
if ( V_41 == V_42 &&
V_48 == V_46 )
F_37 ( V_2 ) ;
if ( V_41 == V_43 &&
V_48 == V_47 )
F_37 ( V_2 ) ;
if ( V_41 == V_49 &&
V_48 == V_47 )
F_29 ( V_50 , & V_2 -> V_4 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
T_1 V_53 ;
bool V_54 = false ;
F_56 ( L_19 , F_57 () ? L_20 : L_21 ,
F_58 () ) ;
F_22 ( V_2 ) ;
V_53 = F_5 ( V_2 ) ;
V_52 = V_2 -> V_44 ;
if ( ! V_52 || ! ( V_52 -> V_4 & V_46 ) ) {
if ( V_41 == V_49 &&
( ! V_2 -> V_35 ||
F_2 ( V_50 , & V_2 -> V_4 ) ) ) {
F_31 ( V_50 , & V_2 -> V_4 ) ;
F_37 ( V_2 ) ;
}
}
if ( ! V_52 )
goto V_55;
if ( V_52 -> V_4 & V_46 ) {
if ( V_52 -> V_56 > V_52 -> V_57 ) {
if ( ( V_53 & V_14 ) == 0 )
F_11 ( V_2 , V_52 -> V_58 [ V_52 -> V_57 ++ ] ) ;
else
goto V_55;
} else if ( V_52 -> V_59 > V_52 -> V_60 ) {
if ( ( V_53 & V_15 ) == 1 ) {
V_52 -> V_61 [ V_52 -> V_60 ++ ] = F_8 ( V_2 ) ;
if ( V_52 -> V_59 == V_52 -> V_60 ) {
F_55 ( V_2 , V_47 ) ;
if ( V_52 -> V_19 == V_34 )
F_35 ( L_22 ,
F_12 ( V_34 ) ) ;
V_54 = true ;
}
} else
goto V_55;
} else if ( V_52 -> V_56 == V_52 -> V_57 &&
( V_53 & V_14 ) == 0 ) {
F_55 ( V_2 , V_47 ) ;
V_54 = true ;
}
goto V_62;
} else {
if ( V_63 &&
! ( V_53 & V_11 ) &&
( V_52 -> V_19 == V_34 ) ) {
F_55 ( V_2 , V_46 ) ;
V_52 -> V_61 [ V_52 -> V_60 ++ ] = 0x00 ;
F_55 ( V_2 , V_47 ) ;
F_35 ( L_23 ,
F_12 ( V_34 ) ) ;
V_54 = true ;
} else if ( ( V_53 & V_14 ) == 0 ) {
F_9 ( V_2 , V_52 -> V_19 ) ;
F_55 ( V_2 , V_46 ) ;
} else
goto V_55;
goto V_62;
}
V_55:
if ( ! ( V_53 & V_11 ) ) {
if ( F_57 () && V_52 ) {
if ( V_52 -> V_64 < V_65 )
++ V_52 -> V_64 ;
if ( V_52 -> V_64 == V_65 )
F_27 ( V_2 ) ;
}
}
V_62:
if ( V_53 & V_11 )
F_33 ( V_2 ) ;
if ( V_54 && F_57 () )
F_26 ( & V_2 -> V_31 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
V_2 -> V_44 -> V_64 = V_2 -> V_44 -> V_57 = V_2 -> V_44 -> V_60 = 0 ;
V_2 -> V_44 -> V_4 = 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned long V_66 = F_61 ( V_2 -> V_67 ) ;
unsigned long V_68 = V_2 -> V_17 + V_66 ;
do {
if ( V_2 -> V_69 ) {
if ( F_54 ( V_2 ) )
return 0 ;
F_62 ( F_63 ( V_66 ) ) ;
} else {
if ( ! F_53 ( V_2 ) &&
! F_52 ( V_2 ) )
break;
if ( F_64 ( V_2 -> V_31 ,
F_54 ( V_2 ) ,
V_66 ) )
return 0 ;
}
} while ( F_65 ( V_18 , V_68 ) );
return - V_70 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_71 = 5 ;
while ( V_71 -- ) {
unsigned long V_72 = V_18 +
F_67 ( V_73 ) ;
do {
if ( ! F_60 ( V_2 ) )
return 0 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
} while ( F_65 ( V_18 , V_72 ) );
F_68 ( L_24 ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
F_59 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
return - V_70 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
unsigned long V_74 ;
int V_45 = 0 ;
F_43 ( & V_2 -> V_37 , V_74 ) ;
if ( ! F_32 ( V_2 ) ) {
V_45 = - V_75 ;
goto V_76;
}
F_70 ( V_2 , L_25 ) ;
V_2 -> V_44 = V_52 ;
F_71 ( L_26 , F_12 ( V_52 -> V_19 ) ) ;
F_59 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_74 ) ;
V_45 = F_66 ( V_2 ) ;
F_43 ( & V_2 -> V_37 , V_74 ) ;
if ( V_52 -> V_64 == V_65 )
F_30 ( V_2 ) ;
F_71 ( L_27 , F_12 ( V_52 -> V_19 ) ) ;
V_2 -> V_44 = NULL ;
F_25 ( V_2 ) ;
F_70 ( V_2 , L_28 ) ;
V_76:
F_44 ( & V_2 -> V_37 , V_74 ) ;
return V_45 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_53 ;
T_3 V_77 ;
if ( ! V_2 || ( ! V_52 ) || ( V_52 -> V_56 && ! V_52 -> V_58 ) || ( V_52 -> V_59 && ! V_52 -> V_61 ) )
return - V_75 ;
if ( V_52 -> V_61 )
memset ( V_52 -> V_61 , 0 , V_52 -> V_59 ) ;
F_73 ( & V_2 -> V_78 ) ;
if ( V_2 -> V_79 ) {
V_53 = F_74 ( V_80 , & V_77 ) ;
if ( F_75 ( V_53 ) ) {
V_53 = - V_81 ;
goto V_76;
}
}
V_53 = F_69 ( V_2 , V_52 ) ;
if ( V_2 -> V_79 )
F_76 ( V_77 ) ;
V_76:
F_77 ( & V_2 -> V_78 ) ;
return V_53 ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_1 V_82 ;
struct V_51 V_52 = { . V_19 = V_83 ,
. V_58 = NULL , . V_61 = & V_82 ,
. V_56 = 0 , . V_59 = 1 } ;
return F_72 ( V_2 , & V_52 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_51 V_52 = { . V_19 = V_84 ,
. V_58 = NULL , . V_61 = NULL ,
. V_56 = 0 , . V_59 = 0 } ;
return ( F_5 ( V_2 ) & V_12 ) ?
F_72 ( V_2 , & V_52 ) : 0 ;
}
static int F_80 ( struct V_1 * V_2 , T_1 V_85 , T_1 * V_20 )
{
int V_86 ;
T_1 V_82 ;
struct V_51 V_52 = { . V_19 = V_87 ,
. V_58 = & V_85 , . V_61 = & V_82 ,
. V_56 = 1 , . V_59 = 1 } ;
V_86 = F_72 ( V_2 , & V_52 ) ;
* V_20 = V_82 ;
return V_86 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_85 , T_1 V_20 )
{
T_1 V_58 [ 2 ] = { V_85 , V_20 } ;
struct V_51 V_52 = { . V_19 = V_88 ,
. V_58 = V_58 , . V_61 = NULL ,
. V_56 = 2 , . V_59 = 0 } ;
return F_72 ( V_2 , & V_52 ) ;
}
int F_82 ( T_1 V_89 , T_1 * V_90 )
{
int V_55 ;
T_1 V_91 ;
if ( ! V_39 )
return - V_81 ;
V_55 = F_80 ( V_39 , V_89 , & V_91 ) ;
if ( ! V_55 ) {
* V_90 = V_91 ;
return 0 ;
}
return V_55 ;
}
int F_83 ( T_1 V_89 , T_1 V_90 )
{
int V_55 ;
if ( ! V_39 )
return - V_81 ;
V_55 = F_81 ( V_39 , V_89 , V_90 ) ;
return V_55 ;
}
int F_84 ( T_1 V_19 ,
const T_1 * V_58 , unsigned V_92 ,
T_1 * V_61 , unsigned V_93 )
{
struct V_51 V_52 = { . V_19 = V_19 ,
. V_58 = V_58 , . V_61 = V_61 ,
. V_56 = V_92 , . V_59 = V_93 } ;
if ( ! V_39 )
return - V_81 ;
return F_72 ( V_39 , & V_52 ) ;
}
T_4 F_85 ( void )
{
if ( ! V_39 )
return NULL ;
return V_39 -> V_94 ;
}
static void F_86 ( struct V_1 * V_2 , bool V_95 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! F_34 ( V_3 , & V_2 -> V_4 ) ) {
F_28 ( L_29 ) ;
if ( ! V_95 ) {
F_24 ( V_2 ) ;
F_70 ( V_2 , L_30 ) ;
}
F_40 ( L_31 ) ;
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static bool F_87 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_30 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_30 = F_4 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
return V_30 ;
}
static void F_88 ( struct V_1 * V_2 , bool V_96 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_28 ( L_32 ) ;
F_29 ( V_5 , & V_2 -> V_4 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_47 ( V_2 -> V_31 , F_87 ( V_2 ) ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! V_96 ) {
F_25 ( V_2 ) ;
F_70 ( V_2 , L_33 ) ;
} else if ( ! V_7 )
F_41 ( V_2 ) ;
F_31 ( V_3 , & V_2 -> V_4 ) ;
F_31 ( V_5 , & V_2 -> V_4 ) ;
F_40 ( L_34 ) ;
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_69 = true ;
V_2 -> V_67 = 0 ;
F_40 ( L_35 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_69 = V_97 ;
V_2 -> V_67 = V_98 ;
F_40 ( L_36 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
void F_91 ( void )
{
struct V_1 * V_2 = V_39 ;
if ( ! V_2 )
return;
F_73 ( & V_2 -> V_78 ) ;
F_88 ( V_2 , true ) ;
F_77 ( & V_2 -> V_78 ) ;
}
void F_92 ( void )
{
if ( V_39 )
F_86 ( V_39 , true ) ;
}
static struct V_99 *
F_93 ( struct V_99 * V_100 )
{
if ( V_100 )
F_94 ( & V_100 -> V_101 ) ;
return V_100 ;
}
static struct V_99 *
F_95 ( struct V_1 * V_2 , T_1 V_102 )
{
struct V_99 * V_100 ;
bool V_103 = false ;
F_73 ( & V_2 -> V_78 ) ;
F_96 (handler, &ec->list, node) {
if ( V_102 == V_100 -> V_104 ) {
V_103 = true ;
break;
}
}
F_77 ( & V_2 -> V_78 ) ;
return V_103 ? F_93 ( V_100 ) : NULL ;
}
static void F_97 ( struct V_101 * V_101 )
{
struct V_99 * V_100 =
F_98 ( V_101 , struct V_99 , V_101 ) ;
F_99 ( V_100 ) ;
}
static void F_100 ( struct V_99 * V_100 )
{
F_101 ( & V_100 -> V_101 , F_97 ) ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_104 ,
T_4 V_94 , T_5 V_105 ,
void * V_20 )
{
struct V_99 * V_100 =
F_103 ( sizeof( struct V_99 ) , V_106 ) ;
if ( ! V_100 )
return - V_107 ;
V_100 -> V_104 = V_104 ;
V_100 -> V_94 = V_94 ;
V_100 -> V_105 = V_105 ;
V_100 -> V_20 = V_20 ;
F_73 ( & V_2 -> V_78 ) ;
F_104 ( & V_100 -> V_101 ) ;
F_105 ( & V_100 -> V_108 , & V_2 -> V_109 ) ;
F_77 ( & V_2 -> V_78 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 ,
bool V_110 , T_1 V_104 )
{
struct V_99 * V_100 , * V_74 ;
F_107 ( V_111 ) ;
F_73 ( & V_2 -> V_78 ) ;
F_108 (handler, tmp, &ec->list, node) {
if ( V_110 || V_104 == V_100 -> V_104 ) {
F_109 ( & V_100 -> V_108 ) ;
F_105 ( & V_100 -> V_108 , & V_111 ) ;
}
}
F_77 ( & V_2 -> V_78 ) ;
F_108 (handler, tmp, &free_list, node)
F_100 ( V_100 ) ;
}
void F_110 ( struct V_1 * V_2 , T_1 V_104 )
{
F_106 ( V_2 , false , V_104 ) ;
}
static struct V_112 * F_111 ( T_1 * V_113 )
{
struct V_112 * V_114 ;
struct V_51 * V_52 ;
V_114 = F_103 ( sizeof ( struct V_112 ) , V_106 ) ;
if ( ! V_114 )
return NULL ;
F_112 ( & V_114 -> V_36 , V_115 ) ;
V_52 = & V_114 -> V_51 ;
V_52 -> V_19 = V_34 ;
V_52 -> V_61 = V_113 ;
V_52 -> V_59 = 1 ;
return V_114 ;
}
static void F_113 ( struct V_112 * V_114 )
{
if ( V_114 ) {
if ( V_114 -> V_100 )
F_100 ( V_114 -> V_100 ) ;
F_99 ( V_114 ) ;
}
}
static void V_115 ( struct V_116 * V_36 )
{
struct V_112 * V_114 = F_98 ( V_36 , struct V_112 , V_36 ) ;
struct V_99 * V_100 = V_114 -> V_100 ;
F_35 ( L_37 , V_100 -> V_104 ) ;
if ( V_100 -> V_105 )
V_100 -> V_105 ( V_100 -> V_20 ) ;
else if ( V_100 -> V_94 )
F_114 ( V_100 -> V_94 , NULL , NULL , NULL ) ;
F_35 ( L_38 , V_100 -> V_104 ) ;
F_113 ( V_114 ) ;
}
static int V_112 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_1 V_102 = 0 ;
int V_86 ;
struct V_112 * V_114 ;
V_114 = F_111 ( & V_102 ) ;
if ( ! V_114 )
return - V_107 ;
V_86 = F_72 ( V_2 , & V_114 -> V_51 ) ;
if ( ! V_102 )
V_86 = - V_117 ;
if ( V_86 )
goto V_118;
V_114 -> V_100 = F_95 ( V_2 , V_102 ) ;
if ( ! V_114 -> V_100 ) {
V_86 = - V_117 ;
goto V_118;
}
F_35 ( L_39 , V_102 ) ;
if ( ! F_115 ( V_38 , & V_114 -> V_36 ) ) {
F_35 ( L_40 , V_102 ) ;
V_86 = - V_119 ;
}
V_118:
if ( V_86 )
F_113 ( V_114 ) ;
if ( V_20 )
* V_20 = V_102 ;
return V_86 ;
}
static void F_116 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_41 == V_49 ) {
if ( F_60 ( V_2 ) ) {
F_43 ( & V_2 -> V_37 , V_4 ) ;
if ( ! V_2 -> V_44 )
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_37 , V_4 ) ;
}
}
}
static void F_117 ( struct V_116 * V_36 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_98 ( V_36 , struct V_1 , V_36 ) ;
F_35 ( L_41 ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
while ( V_2 -> V_35 ) {
F_44 ( & V_2 -> V_37 , V_4 ) ;
( void ) V_112 ( V_2 , NULL ) ;
F_43 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_35 -- ;
if ( ! V_2 -> V_35 ) {
if ( V_41 == V_42 ||
V_41 == V_43 )
F_37 ( V_2 ) ;
}
}
F_44 ( & V_2 -> V_37 , V_4 ) ;
F_35 ( L_42 ) ;
F_116 ( V_2 ) ;
}
static T_3 F_118 ( T_4 V_120 ,
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
F_119 ( T_3 V_123 , T_7 V_85 ,
T_3 V_124 , T_8 * V_125 ,
void * V_126 , void * V_127 )
{
struct V_1 * V_2 = V_126 ;
int V_86 = 0 , V_128 , V_129 = V_124 / 8 ;
T_1 * V_102 = ( T_1 * ) V_125 ;
if ( ( V_85 > 0xFF ) || ! V_102 || ! V_126 )
return V_130 ;
if ( V_123 != V_131 && V_123 != V_132 )
return V_130 ;
if ( V_2 -> V_69 || V_124 > 8 )
F_78 ( V_2 ) ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 , ++ V_85 , ++ V_102 )
V_86 = ( V_123 == V_131 ) ?
F_80 ( V_2 , V_85 , V_102 ) :
F_81 ( V_2 , V_85 , * V_102 ) ;
if ( V_2 -> V_69 || V_124 > 8 )
F_79 ( V_2 ) ;
switch ( V_86 ) {
case - V_75 :
return V_130 ;
case - V_81 :
return V_133 ;
case - V_70 :
return V_134 ;
default:
return V_135 ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
if ( V_39 == V_2 )
V_39 = NULL ;
if ( V_136 == V_2 )
V_136 = NULL ;
F_99 ( V_2 ) ;
}
static struct V_1 * F_121 ( void )
{
struct V_1 * V_2 = F_103 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 )
return NULL ;
F_122 ( & V_2 -> V_78 ) ;
F_123 ( & V_2 -> V_31 ) ;
F_124 ( & V_2 -> V_109 ) ;
F_125 ( & V_2 -> V_37 ) ;
F_112 ( & V_2 -> V_36 , F_117 ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_69 = true ;
V_2 -> V_67 = 0 ;
return V_2 ;
}
static T_6
F_126 ( T_4 V_94 , T_3 V_137 ,
void * V_138 , void * * V_139 )
{
char V_140 [ 5 ] ;
struct V_141 V_142 = { sizeof( V_140 ) , V_140 } ;
struct V_1 * V_2 = V_138 ;
int V_102 = 0 ;
T_6 V_53 ;
V_53 = F_127 ( V_94 , V_143 , & V_142 ) ;
if ( F_128 ( V_53 ) && sscanf ( V_140 , L_43 , & V_102 ) == 1 )
F_102 ( V_2 , V_102 , V_94 , NULL , NULL ) ;
return V_135 ;
}
static T_6
F_129 ( T_4 V_94 , T_3 V_144 , void * V_138 , void * * V_145 )
{
T_6 V_53 ;
unsigned long long V_74 = 0 ;
struct V_1 * V_2 = V_138 ;
V_2 -> V_10 = V_2 -> V_16 = 0 ;
V_53 = F_130 ( V_94 , V_146 ,
V_147 , V_2 ) ;
if ( F_75 ( V_53 ) )
return V_53 ;
if ( V_2 -> V_16 == 0 || V_2 -> V_10 == 0 )
return V_135 ;
if ( V_136 && V_148 && V_149 ) {
V_2 -> V_23 = V_136 -> V_23 ;
} else {
V_53 = F_131 ( V_94 , L_44 , NULL , & V_74 ) ;
if ( F_75 ( V_53 ) )
return V_53 ;
V_2 -> V_23 = V_74 ;
}
V_74 = 0 ;
F_131 ( V_94 , L_45 , NULL , & V_74 ) ;
V_2 -> V_79 = V_74 ;
V_2 -> V_94 = V_94 ;
return V_150 ;
}
static int F_132 ( struct V_1 * V_2 , bool V_151 )
{
T_6 V_53 ;
F_86 ( V_2 , false ) ;
if ( ! F_2 ( V_152 , & V_2 -> V_4 ) ) {
F_89 ( V_2 ) ;
V_53 = F_133 ( V_2 -> V_94 ,
V_153 ,
& F_119 ,
NULL , V_2 ) ;
if ( F_75 ( V_53 ) ) {
if ( V_53 == V_133 ) {
F_134 ( L_46
L_47 ) ;
} else {
F_88 ( V_2 , false ) ;
return - V_81 ;
}
}
F_29 ( V_152 , & V_2 -> V_4 ) ;
}
if ( ! V_151 )
return 0 ;
if ( ! F_2 ( V_154 , & V_2 -> V_4 ) ) {
F_135 ( V_155 , V_2 -> V_94 , 1 ,
F_126 ,
NULL , V_2 , NULL ) ;
F_29 ( V_154 , & V_2 -> V_4 ) ;
}
if ( ! F_2 ( V_29 , & V_2 -> V_4 ) ) {
V_53 = F_136 ( NULL , V_2 -> V_23 ,
V_156 ,
& F_118 , V_2 ) ;
if ( F_128 ( V_53 ) ) {
F_29 ( V_29 , & V_2 -> V_4 ) ;
F_90 ( V_2 ) ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_8 >= 1 )
F_15 ( V_2 , true ) ;
F_42 ( V_2 ) ;
}
}
return 0 ;
}
static void F_137 ( struct V_1 * V_2 )
{
if ( F_2 ( V_152 , & V_2 -> V_4 ) ) {
if ( F_75 ( F_138 ( V_2 -> V_94 ,
V_153 , & F_119 ) ) )
F_134 ( L_48 ) ;
F_31 ( V_152 , & V_2 -> V_4 ) ;
}
F_88 ( V_2 , false ) ;
if ( F_2 ( V_29 , & V_2 -> V_4 ) ) {
if ( F_75 ( F_139 ( NULL , V_2 -> V_23 ,
& F_118 ) ) )
F_134 ( L_49 ) ;
F_31 ( V_29 , & V_2 -> V_4 ) ;
}
if ( F_2 ( V_154 , & V_2 -> V_4 ) ) {
F_106 ( V_2 , true , 0 ) ;
F_31 ( V_154 , & V_2 -> V_4 ) ;
}
}
static int F_140 ( struct V_1 * V_2 , bool V_151 )
{
int V_45 ;
V_45 = F_132 ( V_2 , V_151 ) ;
if ( V_45 )
return V_45 ;
if ( ! V_39 ) {
V_39 = V_2 ;
F_141 ( V_39 -> V_94 , L_50 ) ;
}
F_141 ( V_2 -> V_94 ,
L_51 ,
V_2 -> V_23 , V_2 -> V_10 , V_2 -> V_16 ) ;
return V_45 ;
}
static int F_142 ( struct V_1 * V_2 , T_4 V_94 ,
bool V_151 , bool V_157 )
{
int V_45 ;
if ( V_136 && V_136 -> V_94 != V_94 )
F_137 ( V_136 ) ;
if ( V_136 != V_2 )
F_120 ( V_136 ) ;
if ( V_2 -> V_94 != V_94 )
V_2 -> V_94 = V_94 ;
V_45 = F_140 ( V_2 , V_151 ) ;
if ( V_45 )
return V_45 ;
if ( ! V_136 ) {
V_136 = V_2 ;
V_148 = V_157 ;
}
F_141 ( V_136 -> V_94 ,
L_52 ,
V_157 ? L_53 : L_54 ,
V_151 ? L_55 : L_56 ) ;
return V_45 ;
}
static bool F_143 ( T_4 * V_158 )
{
struct V_159 * V_160 ;
T_6 V_53 ;
T_4 V_94 ;
V_53 = F_144 ( V_161 , 1 ,
(struct V_162 * * ) & V_160 ) ;
if ( F_75 ( V_53 ) )
return false ;
V_53 = F_145 ( NULL , V_160 -> V_163 , & V_94 ) ;
if ( F_75 ( V_53 ) )
return false ;
* V_158 = V_94 ;
return true ;
}
static bool F_146 ( struct V_1 * V_2 )
{
if ( ! V_136 )
return false ;
if ( V_2 -> V_10 == V_136 -> V_10 &&
V_2 -> V_16 == V_136 -> V_16 )
return true ;
return false ;
}
static int F_147 ( struct V_164 * V_165 )
{
struct V_1 * V_2 = NULL ;
int V_45 ;
strcpy ( F_148 ( V_165 ) , V_166 ) ;
strcpy ( F_149 ( V_165 ) , V_167 ) ;
V_2 = F_121 () ;
if ( ! V_2 )
return - V_107 ;
if ( F_129 ( V_165 -> V_94 , 0 , V_2 , NULL ) !=
V_150 ) {
V_45 = - V_75 ;
goto V_168;
}
if ( F_146 ( V_2 ) ) {
V_148 = false ;
V_136 -> V_94 = V_2 -> V_94 ;
F_150 ( V_2 -> V_94 , L_57 ) ;
F_120 ( V_2 ) ;
V_2 = V_136 ;
V_45 = F_142 ( V_2 , V_2 -> V_94 , true , false ) ;
} else
V_45 = F_140 ( V_2 , true ) ;
if ( V_45 )
goto V_169;
V_165 -> V_170 = V_2 ;
V_45 = ! ! F_151 ( V_2 -> V_16 , 1 , L_58 ) ;
F_152 ( ! V_45 , L_59 , V_2 -> V_16 ) ;
V_45 = ! ! F_151 ( V_2 -> V_10 , 1 , L_60 ) ;
F_152 ( ! V_45 , L_61 , V_2 -> V_10 ) ;
F_153 ( V_2 -> V_94 ) ;
F_150 ( V_2 -> V_94 , L_62 ) ;
return 0 ;
V_169:
if ( V_2 != V_136 )
F_106 ( V_2 , true , 0 ) ;
V_168:
if ( V_2 != V_136 )
F_120 ( V_2 ) ;
return V_45 ;
}
static int F_154 ( struct V_164 * V_165 )
{
struct V_1 * V_2 ;
if ( ! V_165 )
return - V_75 ;
V_2 = F_155 ( V_165 ) ;
F_156 ( V_2 -> V_16 , 1 ) ;
F_156 ( V_2 -> V_10 , 1 ) ;
V_165 -> V_170 = NULL ;
if ( V_2 != V_136 ) {
F_137 ( V_2 ) ;
F_120 ( V_2 ) ;
}
return 0 ;
}
static T_6
V_147 ( struct V_171 * V_172 , void * V_138 )
{
struct V_1 * V_2 = V_138 ;
if ( V_172 -> type != V_173 )
return V_135 ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_16 = V_172 -> V_20 . V_174 . V_175 ;
else if ( V_2 -> V_10 == 0 )
V_2 -> V_10 = V_172 -> V_20 . V_174 . V_175 ;
else
return V_150 ;
return V_135 ;
}
int T_9 F_157 ( void )
{
T_6 V_53 ;
struct V_1 * V_2 ;
int V_45 ;
if ( V_136 )
return - V_81 ;
V_2 = F_121 () ;
if ( ! V_2 )
return - V_107 ;
V_53 = F_158 ( V_176 [ 0 ] . V_163 ,
F_129 , V_2 , NULL ) ;
if ( F_75 ( V_53 ) || ! V_2 -> V_94 ) {
V_45 = - V_81 ;
goto error;
}
V_45 = F_142 ( V_2 , V_2 -> V_94 , false , false ) ;
error:
if ( V_45 )
F_120 ( V_2 ) ;
return V_45 ;
}
static int T_9 F_159 ( void )
{
T_4 V_94 ;
if ( ! V_136 )
return - V_81 ;
if ( ! V_148 )
return - V_81 ;
if ( V_136 -> V_94 != V_177 )
V_94 = V_136 -> V_94 ;
else if ( ! F_143 ( & V_94 ) )
return - V_81 ;
return F_142 ( V_136 , V_94 , true , true ) ;
}
static int F_160 ( const struct V_178 * V_163 )
{
F_68 ( L_63 ) ;
V_179 = 1 ;
return 0 ;
}
static int F_161 ( const struct V_178 * V_163 )
{
F_68 ( L_64 ) ;
V_149 = 1 ;
return 0 ;
}
int T_9 F_162 ( void )
{
int V_45 ;
T_6 V_53 ;
struct V_159 * V_160 ;
struct V_1 * V_2 ;
V_2 = F_121 () ;
if ( ! V_2 )
return - V_107 ;
F_163 ( V_180 ) ;
V_53 = F_144 ( V_161 , 1 ,
(struct V_162 * * ) & V_160 ) ;
if ( F_75 ( V_53 ) ) {
V_45 = - V_81 ;
goto error;
}
if ( ! V_160 -> V_181 . V_85 || ! V_160 -> V_20 . V_85 ) {
V_45 = - V_81 ;
goto error;
}
if ( V_179 ) {
V_2 -> V_10 = V_160 -> V_20 . V_85 ;
V_2 -> V_16 = V_160 -> V_181 . V_85 ;
} else {
V_2 -> V_10 = V_160 -> V_181 . V_85 ;
V_2 -> V_16 = V_160 -> V_20 . V_85 ;
}
V_2 -> V_23 = V_160 -> V_23 ;
V_45 = F_142 ( V_2 , V_177 , false , true ) ;
error:
if ( V_45 )
F_120 ( V_2 ) ;
return V_45 ;
}
static int F_164 ( struct V_165 * V_182 )
{
struct V_1 * V_2 =
F_155 ( F_165 ( V_182 ) ) ;
if ( F_166 () && V_7 )
F_49 ( V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_165 * V_182 )
{
struct V_1 * V_2 = F_155 ( F_165 ( V_182 ) ) ;
if ( V_183 && F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_8 >= 1 )
F_18 ( NULL , V_2 -> V_23 , V_28 ) ;
return 0 ;
}
static int F_168 ( struct V_165 * V_182 )
{
struct V_1 * V_2 = F_155 ( F_165 ( V_182 ) ) ;
if ( V_183 && F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_8 >= 1 )
F_18 ( NULL , V_2 -> V_23 , V_26 ) ;
return 0 ;
}
static int F_169 ( struct V_165 * V_182 )
{
struct V_1 * V_2 =
F_155 ( F_165 ( V_182 ) ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_170 ( const char * V_90 , struct V_184 * V_185 )
{
int V_86 = 0 ;
if ( ! strncmp ( V_90 , L_65 , sizeof( L_65 ) - 1 ) ) {
V_41 = V_42 ;
F_171 ( L_66 ) ;
} else if ( ! strncmp ( V_90 , L_67 , sizeof( L_67 ) - 1 ) ) {
V_41 = V_43 ;
F_171 ( L_68 ) ;
} else if ( ! strncmp ( V_90 , L_69 , sizeof( L_69 ) - 1 ) ) {
V_41 = V_49 ;
F_171 ( L_70 ) ;
} else
V_86 = - V_75 ;
return V_86 ;
}
static int F_172 ( char * V_142 , struct V_184 * V_185 )
{
switch ( V_41 ) {
case V_42 :
return sprintf ( V_142 , L_65 ) ;
case V_43 :
return sprintf ( V_142 , L_67 ) ;
case V_49 :
return sprintf ( V_142 , L_69 ) ;
default:
return sprintf ( V_142 , L_71 ) ;
}
return 0 ;
}
static inline int F_173 ( void )
{
if ( ! V_38 ) {
V_38 = F_174 ( L_72 , 0 ,
V_186 ) ;
if ( ! V_38 )
return - V_81 ;
}
return 0 ;
}
static inline void F_175 ( void )
{
if ( V_38 ) {
F_176 ( V_38 ) ;
V_38 = NULL ;
}
}
int T_9 F_177 ( void )
{
int V_86 ;
int V_187 , V_188 ;
V_86 = F_173 () ;
if ( V_86 )
return V_86 ;
V_188 = F_178 ( & V_189 ) ;
V_187 = F_159 () ;
return V_187 && V_188 ? - V_81 : 0 ;
}
