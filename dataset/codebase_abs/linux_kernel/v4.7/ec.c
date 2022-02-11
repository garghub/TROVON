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
V_2 -> V_15 = V_16 ;
F_6 ( L_3 , V_7 ) ;
return V_7 ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_17 )
{
F_6 ( L_4 , V_17 ) ;
F_9 ( V_17 , V_2 -> V_8 ) ;
V_2 -> V_15 = V_16 ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_18 )
{
F_6 ( L_5 , V_18 ) ;
F_9 ( V_18 , V_2 -> V_14 ) ;
V_2 -> V_15 = V_16 ;
}
static const char * F_11 ( T_1 V_19 )
{
switch ( V_19 ) {
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
T_2 V_20 = 0 ;
( void ) F_13 ( NULL , V_2 -> V_21 , & V_20 ) ;
return ( V_20 & V_22 ) ? true : false ;
}
static inline void F_14 ( struct V_1 * V_2 , bool V_23 )
{
if ( V_23 )
F_15 ( NULL , V_2 -> V_21 ) ;
else {
F_16 ( V_2 -> V_6 < 1 ) ;
F_17 ( NULL , V_2 -> V_21 , V_24 ) ;
}
if ( F_12 ( V_2 ) ) {
F_6 ( L_12 ) ;
F_18 ( V_2 ) ;
}
}
static inline void F_19 ( struct V_1 * V_2 , bool V_25 )
{
if ( V_25 )
F_20 ( NULL , V_2 -> V_21 ) ;
else {
F_16 ( V_2 -> V_6 < 1 ) ;
F_17 ( NULL , V_2 -> V_21 , V_26 ) ;
}
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_2 ) )
return;
F_22 ( NULL , V_2 -> V_21 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_6 ++ ;
if ( F_2 ( V_27 , & V_2 -> V_4 ) &&
V_2 -> V_6 == 1 )
F_14 ( V_2 , true ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
bool V_28 = false ;
V_2 -> V_6 -- ;
if ( F_2 ( V_27 , & V_2 -> V_4 ) &&
V_2 -> V_6 == 0 )
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
F_34 ( L_15 ,
F_11 ( V_32 ) ) ;
V_2 -> V_33 ++ ;
F_35 ( & V_2 -> V_34 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( F_2 ( V_31 , & V_2 -> V_4 ) ) {
F_30 ( V_31 , & V_2 -> V_4 ) ;
F_34 ( L_16 ,
F_11 ( V_32 ) ) ;
}
}
static bool F_37 ( struct V_1 * V_2 )
{
bool V_35 = true ;
unsigned long V_4 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( V_37 == V_38 ||
V_37 == V_39 ||
! F_2 ( V_31 , & V_2 -> V_4 ) ||
( V_2 -> V_40 && V_2 -> V_40 -> V_17 == V_32 ) )
V_35 = false ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
return V_35 ;
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_41 = 0 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( V_2 -> V_40 && ( V_2 -> V_40 -> V_4 & V_42 ) )
V_41 = 1 ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
return V_41 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_41 = 0 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( V_2 -> V_40 && ( V_2 -> V_40 -> V_4 & V_43 ) )
V_41 = 1 ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
return V_41 ;
}
static inline void F_42 ( struct V_1 * V_2 , unsigned long V_30 )
{
V_2 -> V_40 -> V_4 |= V_30 ;
if ( V_2 -> V_40 -> V_17 == V_32 ) {
if ( V_37 == V_38 &&
V_30 == V_42 )
F_36 ( V_2 ) ;
if ( V_37 == V_39 &&
V_30 == V_43 )
F_36 ( V_2 ) ;
if ( V_37 == V_44 &&
V_30 == V_43 )
F_28 ( V_45 , & V_2 -> V_4 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
T_1 V_48 ;
bool V_49 = false ;
F_43 ( L_17 , F_44 () ? L_18 : L_19 ,
F_45 () ) ;
F_21 ( V_2 ) ;
V_48 = F_4 ( V_2 ) ;
V_47 = V_2 -> V_40 ;
if ( ! V_47 || ! ( V_47 -> V_4 & V_42 ) ) {
if ( V_37 == V_44 &&
( ! V_2 -> V_33 ||
F_2 ( V_45 , & V_2 -> V_4 ) ) ) {
F_30 ( V_45 , & V_2 -> V_4 ) ;
F_36 ( V_2 ) ;
}
}
if ( ! V_47 )
goto V_50;
if ( V_47 -> V_4 & V_42 ) {
if ( V_47 -> V_51 > V_47 -> V_52 ) {
if ( ( V_48 & V_12 ) == 0 )
F_10 ( V_2 , V_47 -> V_53 [ V_47 -> V_52 ++ ] ) ;
else
goto V_50;
} else if ( V_47 -> V_54 > V_47 -> V_55 ) {
if ( ( V_48 & V_13 ) == 1 ) {
V_47 -> V_56 [ V_47 -> V_55 ++ ] = F_7 ( V_2 ) ;
if ( V_47 -> V_54 == V_47 -> V_55 ) {
F_42 ( V_2 , V_43 ) ;
if ( V_47 -> V_17 == V_32 )
F_34 ( L_20 ,
F_11 ( V_32 ) ) ;
V_49 = true ;
}
} else
goto V_50;
} else if ( V_47 -> V_51 == V_47 -> V_52 &&
( V_48 & V_12 ) == 0 ) {
F_42 ( V_2 , V_43 ) ;
V_49 = true ;
}
goto V_57;
} else {
if ( V_58 &&
! ( V_48 & V_9 ) &&
( V_47 -> V_17 == V_32 ) ) {
F_42 ( V_2 , V_42 ) ;
V_47 -> V_56 [ V_47 -> V_55 ++ ] = 0x00 ;
F_42 ( V_2 , V_43 ) ;
F_34 ( L_21 ,
F_11 ( V_32 ) ) ;
V_49 = true ;
} else if ( ( V_48 & V_12 ) == 0 ) {
F_8 ( V_2 , V_47 -> V_17 ) ;
F_42 ( V_2 , V_42 ) ;
} else
goto V_50;
goto V_57;
}
V_50:
if ( ! ( V_48 & V_9 ) ) {
if ( F_44 () && V_47 ) {
if ( V_47 -> V_59 < V_60 )
++ V_47 -> V_59 ;
if ( V_47 -> V_59 == V_60 )
F_26 ( V_2 , V_61 ) ;
}
}
V_57:
if ( V_48 & V_9 )
F_32 ( V_2 ) ;
if ( V_49 && F_44 () )
F_25 ( & V_2 -> V_29 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_40 -> V_59 = V_2 -> V_40 -> V_52 = V_2 -> V_40 -> V_55 = 0 ;
V_2 -> V_40 -> V_4 = 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned long V_62 = F_48 ( V_63 ) ;
unsigned long V_64 = V_2 -> V_15 + V_62 ;
do {
if ( V_65 ) {
if ( F_41 ( V_2 ) )
return 0 ;
F_49 ( F_50 ( V_62 ) ) ;
} else {
if ( ! F_40 ( V_2 ) &&
! F_37 ( V_2 ) )
break;
if ( F_51 ( V_2 -> V_29 ,
F_41 ( V_2 ) ,
V_62 ) )
return 0 ;
}
} while ( F_52 ( V_16 , V_64 ) );
return - V_66 ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_67 = 5 ;
while ( V_67 -- ) {
unsigned long V_68 = V_16 +
F_54 ( V_69 ) ;
do {
if ( ! F_47 ( V_2 ) )
return 0 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
} while ( F_52 ( V_16 , V_68 ) );
F_55 ( L_22 ) ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
F_46 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
}
return - V_66 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
unsigned long V_70 ;
int V_41 = 0 ;
F_38 ( & V_2 -> V_36 , V_70 ) ;
if ( ! F_31 ( V_2 ) ) {
V_41 = - V_71 ;
goto V_72;
}
F_57 ( V_2 , L_23 ) ;
V_2 -> V_40 = V_47 ;
F_58 ( L_24 , F_11 ( V_47 -> V_17 ) ) ;
F_46 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_70 ) ;
V_41 = F_53 ( V_2 ) ;
F_38 ( & V_2 -> V_36 , V_70 ) ;
if ( V_47 -> V_59 == V_60 )
F_29 ( V_2 , V_61 ) ;
F_58 ( L_25 , F_11 ( V_47 -> V_17 ) ) ;
V_2 -> V_40 = NULL ;
F_24 ( V_2 ) ;
F_57 ( V_2 , L_26 ) ;
V_72:
F_39 ( & V_2 -> V_36 , V_70 ) ;
return V_41 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_48 ;
T_3 V_73 ;
if ( ! V_2 || ( ! V_47 ) || ( V_47 -> V_51 && ! V_47 -> V_53 ) || ( V_47 -> V_54 && ! V_47 -> V_56 ) )
return - V_71 ;
if ( V_47 -> V_56 )
memset ( V_47 -> V_56 , 0 , V_47 -> V_54 ) ;
F_60 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_75 ) {
V_48 = F_61 ( V_76 , & V_73 ) ;
if ( F_62 ( V_48 ) ) {
V_48 = - V_77 ;
goto V_72;
}
}
V_48 = F_56 ( V_2 , V_47 ) ;
if ( V_2 -> V_75 )
F_63 ( V_73 ) ;
V_72:
F_64 ( & V_2 -> V_74 ) ;
return V_48 ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_1 V_78 ;
struct V_46 V_47 = { . V_17 = V_79 ,
. V_53 = NULL , . V_56 = & V_78 ,
. V_51 = 0 , . V_54 = 1 } ;
return F_59 ( V_2 , & V_47 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_46 V_47 = { . V_17 = V_80 ,
. V_53 = NULL , . V_56 = NULL ,
. V_51 = 0 , . V_54 = 0 } ;
return ( F_4 ( V_2 ) & V_10 ) ?
F_59 ( V_2 , & V_47 ) : 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_81 , T_1 * V_18 )
{
int V_82 ;
T_1 V_78 ;
struct V_46 V_47 = { . V_17 = V_83 ,
. V_53 = & V_81 , . V_56 = & V_78 ,
. V_51 = 1 , . V_54 = 1 } ;
V_82 = F_59 ( V_2 , & V_47 ) ;
* V_18 = V_78 ;
return V_82 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_81 , T_1 V_18 )
{
T_1 V_53 [ 2 ] = { V_81 , V_18 } ;
struct V_46 V_47 = { . V_17 = V_84 ,
. V_53 = V_53 , . V_56 = NULL ,
. V_51 = 2 , . V_54 = 0 } ;
return F_59 ( V_2 , & V_47 ) ;
}
int F_69 ( T_1 V_85 , T_1 * V_86 )
{
int V_50 ;
T_1 V_87 ;
if ( ! V_88 )
return - V_77 ;
V_50 = F_67 ( V_88 , V_85 , & V_87 ) ;
if ( ! V_50 ) {
* V_86 = V_87 ;
return 0 ;
}
return V_50 ;
}
int F_70 ( T_1 V_85 , T_1 V_86 )
{
int V_50 ;
if ( ! V_88 )
return - V_77 ;
V_50 = F_68 ( V_88 , V_85 , V_86 ) ;
return V_50 ;
}
int F_71 ( T_1 V_17 ,
const T_1 * V_53 , unsigned V_89 ,
T_1 * V_56 , unsigned V_90 )
{
struct V_46 V_47 = { . V_17 = V_17 ,
. V_53 = V_53 , . V_56 = V_56 ,
. V_51 = V_89 , . V_54 = V_90 } ;
if ( ! V_88 )
return - V_77 ;
return F_59 ( V_88 , & V_47 ) ;
}
T_4 F_72 ( void )
{
if ( ! V_88 )
return NULL ;
return V_88 -> V_91 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_92 , V_48 ;
T_1 V_93 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 ; V_92 ++ ) {
V_48 = F_74 ( V_2 , & V_93 ) ;
if ( V_48 || ! V_93 )
break;
}
if ( F_75 ( V_92 == V_94 ) )
F_76 ( L_27 , V_92 ) ;
else
F_77 ( L_28 , V_92 ) ;
}
static void F_78 ( struct V_1 * V_2 , bool V_95 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( ! F_33 ( V_3 , & V_2 -> V_4 ) ) {
F_27 ( L_29 ) ;
if ( ! V_95 ) {
F_23 ( V_2 ) ;
F_57 ( V_2 , L_30 ) ;
}
F_79 ( L_31 ) ;
}
F_39 ( & V_2 -> V_36 , V_4 ) ;
}
static bool F_80 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_28 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
V_28 = F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
return V_28 ;
}
static void F_81 ( struct V_1 * V_2 , bool V_96 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( L_32 ) ;
F_28 ( V_5 , & V_2 -> V_4 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
F_82 ( V_2 -> V_29 , F_80 ( V_2 ) ) ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( ! V_96 ) {
F_24 ( V_2 ) ;
F_57 ( V_2 , L_33 ) ;
}
F_30 ( V_3 , & V_2 -> V_4 ) ;
F_30 ( V_5 , & V_2 -> V_4 ) ;
F_79 ( L_34 ) ;
}
F_39 ( & V_2 -> V_36 , V_4 ) ;
}
void F_83 ( void )
{
struct V_1 * V_2 = V_88 ;
if ( ! V_2 )
return;
F_60 ( & V_2 -> V_74 ) ;
F_81 ( V_2 , true ) ;
F_64 ( & V_2 -> V_74 ) ;
}
void F_84 ( void )
{
struct V_1 * V_2 = V_88 ;
if ( ! V_2 )
return;
F_78 ( V_2 , true ) ;
if ( V_97 )
F_73 ( V_2 ) ;
}
void F_85 ( void )
{
if ( V_88 )
F_78 ( V_88 , true ) ;
}
static struct V_98 *
F_86 ( struct V_98 * V_99 )
{
if ( V_99 )
F_87 ( & V_99 -> V_100 ) ;
return V_99 ;
}
static struct V_98 *
F_88 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_98 * V_99 ;
bool V_101 = false ;
F_60 ( & V_2 -> V_74 ) ;
F_89 (handler, &ec->list, node) {
if ( V_93 == V_99 -> V_102 ) {
V_101 = true ;
break;
}
}
F_64 ( & V_2 -> V_74 ) ;
return V_101 ? F_86 ( V_99 ) : NULL ;
}
static void F_90 ( struct V_100 * V_100 )
{
struct V_98 * V_99 =
F_91 ( V_100 , struct V_98 , V_100 ) ;
F_92 ( V_99 ) ;
}
static void F_93 ( struct V_98 * V_99 )
{
F_94 ( & V_99 -> V_100 , F_90 ) ;
}
int F_95 ( struct V_1 * V_2 , T_1 V_102 ,
T_4 V_91 , T_5 V_103 ,
void * V_18 )
{
struct V_98 * V_99 =
F_96 ( sizeof( struct V_98 ) , V_104 ) ;
if ( ! V_99 )
return - V_105 ;
V_99 -> V_102 = V_102 ;
V_99 -> V_91 = V_91 ;
V_99 -> V_103 = V_103 ;
V_99 -> V_18 = V_18 ;
F_60 ( & V_2 -> V_74 ) ;
F_97 ( & V_99 -> V_100 ) ;
F_98 ( & V_99 -> V_106 , & V_2 -> V_107 ) ;
F_64 ( & V_2 -> V_74 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 ,
bool V_108 , T_1 V_102 )
{
struct V_98 * V_99 , * V_70 ;
F_100 ( V_109 ) ;
F_60 ( & V_2 -> V_74 ) ;
F_101 (handler, tmp, &ec->list, node) {
if ( V_108 || V_102 == V_99 -> V_102 ) {
F_102 ( & V_99 -> V_106 ) ;
F_98 ( & V_99 -> V_106 , & V_109 ) ;
}
}
F_64 ( & V_2 -> V_74 ) ;
F_101 (handler, tmp, &free_list, node)
F_93 ( V_99 ) ;
}
void F_103 ( struct V_1 * V_2 , T_1 V_102 )
{
F_99 ( V_2 , false , V_102 ) ;
}
static struct F_74 * F_104 ( T_1 * V_110 )
{
struct F_74 * V_111 ;
struct V_46 * V_47 ;
V_111 = F_96 ( sizeof ( struct F_74 ) , V_104 ) ;
if ( ! V_111 )
return NULL ;
F_105 ( & V_111 -> V_34 , V_112 ) ;
V_47 = & V_111 -> V_46 ;
V_47 -> V_17 = V_32 ;
V_47 -> V_56 = V_110 ;
V_47 -> V_54 = 1 ;
return V_111 ;
}
static void F_106 ( struct F_74 * V_111 )
{
if ( V_111 ) {
if ( V_111 -> V_99 )
F_93 ( V_111 -> V_99 ) ;
F_92 ( V_111 ) ;
}
}
static void V_112 ( struct V_113 * V_34 )
{
struct F_74 * V_111 = F_91 ( V_34 , struct F_74 , V_34 ) ;
struct V_98 * V_99 = V_111 -> V_99 ;
F_34 ( L_35 , V_99 -> V_102 ) ;
if ( V_99 -> V_103 )
V_99 -> V_103 ( V_99 -> V_18 ) ;
else if ( V_99 -> V_91 )
F_107 ( V_99 -> V_91 , NULL , NULL , NULL ) ;
F_34 ( L_36 , V_99 -> V_102 ) ;
F_106 ( V_111 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_1 * V_18 )
{
T_1 V_93 = 0 ;
int V_82 ;
struct F_74 * V_111 ;
V_111 = F_104 ( & V_93 ) ;
if ( ! V_111 )
return - V_105 ;
V_82 = F_59 ( V_2 , & V_111 -> V_46 ) ;
if ( ! V_93 )
V_82 = - V_114 ;
if ( V_82 )
goto V_115;
V_111 -> V_99 = F_88 ( V_2 , V_93 ) ;
if ( ! V_111 -> V_99 ) {
V_82 = - V_114 ;
goto V_115;
}
F_34 ( L_37 , V_93 ) ;
if ( ! F_35 ( & V_111 -> V_34 ) ) {
F_34 ( L_38 , V_93 ) ;
V_82 = - V_116 ;
}
V_115:
if ( V_82 )
F_106 ( V_111 ) ;
if ( V_18 )
* V_18 = V_93 ;
return V_82 ;
}
static void F_108 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_37 == V_44 ) {
if ( F_47 ( V_2 ) ) {
F_38 ( & V_2 -> V_36 , V_4 ) ;
if ( ! V_2 -> V_40 )
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
}
}
}
static void F_109 ( struct V_113 * V_34 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_91 ( V_34 , struct V_1 , V_34 ) ;
F_34 ( L_39 ) ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
while ( V_2 -> V_33 ) {
F_39 ( & V_2 -> V_36 , V_4 ) ;
( void ) F_74 ( V_2 , NULL ) ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
V_2 -> V_33 -- ;
if ( ! V_2 -> V_33 ) {
if ( V_37 == V_38 ||
V_37 == V_39 )
F_36 ( V_2 ) ;
}
}
F_39 ( & V_2 -> V_36 , V_4 ) ;
F_34 ( L_40 ) ;
F_108 ( V_2 ) ;
}
static T_3 F_110 ( T_4 V_117 ,
T_3 V_118 , void * V_18 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_18 ;
F_38 ( & V_2 -> V_36 , V_4 ) ;
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_36 , V_4 ) ;
return V_119 ;
}
static T_6
F_111 ( T_3 V_120 , T_7 V_81 ,
T_3 V_121 , T_8 * V_122 ,
void * V_123 , void * V_124 )
{
struct V_1 * V_2 = V_123 ;
int V_82 = 0 , V_92 , V_125 = V_121 / 8 ;
T_1 * V_93 = ( T_1 * ) V_122 ;
if ( ( V_81 > 0xFF ) || ! V_93 || ! V_123 )
return V_126 ;
if ( V_120 != V_127 && V_120 != V_128 )
return V_126 ;
if ( V_65 || V_121 > 8 )
F_65 ( V_2 ) ;
for ( V_92 = 0 ; V_92 < V_125 ; ++ V_92 , ++ V_81 , ++ V_93 )
V_82 = ( V_120 == V_127 ) ?
F_67 ( V_2 , V_81 , V_93 ) :
F_68 ( V_2 , V_81 , * V_93 ) ;
if ( V_65 || V_121 > 8 )
F_66 ( V_2 ) ;
switch ( V_82 ) {
case - V_71 :
return V_126 ;
case - V_77 :
return V_129 ;
case - V_66 :
return V_130 ;
default:
return V_131 ;
}
}
static struct V_1 * F_112 ( void )
{
struct V_1 * V_2 = F_96 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = 1 << V_31 ;
F_113 ( & V_2 -> V_74 ) ;
F_114 ( & V_2 -> V_29 ) ;
F_115 ( & V_2 -> V_107 ) ;
F_116 ( & V_2 -> V_36 ) ;
F_105 ( & V_2 -> V_34 , F_109 ) ;
V_2 -> V_15 = V_16 ;
return V_2 ;
}
static T_6
F_117 ( T_4 V_91 , T_3 V_132 ,
void * V_133 , void * * V_134 )
{
char V_135 [ 5 ] ;
struct V_136 V_137 = { sizeof( V_135 ) , V_135 } ;
struct V_1 * V_2 = V_133 ;
int V_93 = 0 ;
T_6 V_48 ;
V_48 = F_118 ( V_91 , V_138 , & V_137 ) ;
if ( F_119 ( V_48 ) && sscanf ( V_135 , L_41 , & V_93 ) == 1 )
F_95 ( V_2 , V_93 , V_91 , NULL , NULL ) ;
return V_131 ;
}
static T_6
F_120 ( T_4 V_91 , T_3 V_139 , void * V_133 , void * * V_140 )
{
T_6 V_48 ;
unsigned long long V_70 = 0 ;
struct V_1 * V_2 = V_133 ;
V_2 -> V_8 = V_2 -> V_14 = 0 ;
V_48 = F_121 ( V_91 , V_141 ,
V_142 , V_2 ) ;
if ( F_62 ( V_48 ) )
return V_48 ;
V_48 = F_122 ( V_91 , L_42 , NULL , & V_70 ) ;
if ( F_62 ( V_48 ) )
return V_48 ;
V_2 -> V_21 = V_70 ;
V_70 = 0 ;
F_122 ( V_91 , L_43 , NULL , & V_70 ) ;
V_2 -> V_75 = V_70 ;
V_2 -> V_91 = V_91 ;
return V_143 ;
}
static int F_123 ( struct V_1 * V_2 )
{
T_6 V_48 ;
F_78 ( V_2 , false ) ;
if ( ! F_2 ( V_144 , & V_2 -> V_4 ) ) {
V_48 = F_124 ( V_2 -> V_91 ,
V_145 ,
& F_111 ,
NULL , V_2 ) ;
if ( F_62 ( V_48 ) ) {
if ( V_48 == V_129 ) {
F_125 ( L_44
L_45 ) ;
} else {
F_81 ( V_2 , false ) ;
return - V_77 ;
}
}
F_28 ( V_144 , & V_2 -> V_4 ) ;
}
if ( ! F_2 ( V_27 , & V_2 -> V_4 ) ) {
V_48 = F_126 ( NULL , V_2 -> V_21 ,
V_146 ,
& F_110 , V_2 ) ;
if ( F_119 ( V_48 ) ) {
F_28 ( V_27 , & V_2 -> V_4 ) ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) &&
V_2 -> V_6 >= 1 )
F_14 ( V_2 , true ) ;
}
}
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
if ( F_2 ( V_144 , & V_2 -> V_4 ) ) {
if ( F_62 ( F_128 ( V_2 -> V_91 ,
V_145 , & F_111 ) ) )
F_125 ( L_46 ) ;
F_30 ( V_144 , & V_2 -> V_4 ) ;
}
F_81 ( V_2 , false ) ;
if ( F_2 ( V_27 , & V_2 -> V_4 ) ) {
if ( F_62 ( F_129 ( NULL , V_2 -> V_21 ,
& F_110 ) ) )
F_125 ( L_47 ) ;
F_30 ( V_27 , & V_2 -> V_4 ) ;
}
}
static int F_130 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = NULL ;
int V_41 ;
strcpy ( F_131 ( V_148 ) , V_149 ) ;
strcpy ( F_132 ( V_148 ) , V_150 ) ;
if ( V_151 ) {
V_2 = V_151 ;
V_151 = NULL ;
F_127 ( V_2 ) ;
if ( V_88 == V_2 )
V_88 = NULL ;
} else {
V_2 = F_112 () ;
if ( ! V_2 )
return - V_105 ;
}
if ( F_120 ( V_148 -> V_91 , 0 , V_2 , NULL ) !=
V_143 ) {
F_92 ( V_2 ) ;
return - V_71 ;
}
F_133 ( V_152 , V_2 -> V_91 , 1 ,
F_117 , NULL , V_2 , NULL ) ;
if ( ! V_88 )
V_88 = V_2 ;
V_148 -> V_153 = V_2 ;
V_41 = ! ! F_134 ( V_2 -> V_14 , 1 , L_48 ) ;
F_135 ( ! V_41 , L_49 , V_2 -> V_14 ) ;
V_41 = ! ! F_134 ( V_2 -> V_8 , 1 , L_50 ) ;
F_135 ( ! V_41 , L_51 , V_2 -> V_8 ) ;
F_77 ( L_52 ,
V_2 -> V_21 , V_2 -> V_8 , V_2 -> V_14 ) ;
V_41 = F_123 ( V_2 ) ;
F_136 ( V_2 -> V_91 ) ;
F_30 ( V_31 , & V_2 -> V_4 ) ;
if ( V_97 )
F_73 ( V_2 ) ;
return V_41 ;
}
static int F_137 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
if ( ! V_148 )
return - V_71 ;
V_2 = F_138 ( V_148 ) ;
F_127 ( V_2 ) ;
F_99 ( V_2 , true , 0 ) ;
F_139 ( V_2 -> V_14 , 1 ) ;
F_139 ( V_2 -> V_8 , 1 ) ;
V_148 -> V_153 = NULL ;
if ( V_2 == V_88 )
V_88 = NULL ;
F_92 ( V_2 ) ;
return 0 ;
}
static T_6
V_142 ( struct V_154 * V_155 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
if ( V_155 -> type != V_156 )
return V_131 ;
if ( V_2 -> V_14 == 0 )
V_2 -> V_14 = V_155 -> V_18 . V_157 . V_158 ;
else if ( V_2 -> V_8 == 0 )
V_2 -> V_8 = V_155 -> V_18 . V_157 . V_158 ;
else
return V_143 ;
return V_131 ;
}
int T_9 F_140 ( void )
{
T_6 V_48 ;
if ( V_151 )
return 0 ;
V_151 = F_112 () ;
if ( ! V_151 )
return - V_105 ;
V_48 = F_141 ( V_159 [ 0 ] . V_160 ,
F_120 , V_151 , NULL ) ;
if ( F_62 ( V_48 ) || ! V_151 -> V_91 )
return - V_77 ;
if ( ! F_123 ( V_151 ) ) {
V_88 = V_151 ;
return 0 ;
}
return - V_161 ;
}
static int F_142 ( const struct V_162 * V_160 )
{
F_55 ( L_53 ) ;
V_97 = 1 ;
V_37 = V_38 ;
return 0 ;
}
static int F_143 ( const struct V_162 * V_160 )
{
F_55 ( L_54 ) ;
V_163 = 1 ;
return 0 ;
}
int T_9 F_144 ( void )
{
int V_41 = 0 ;
T_6 V_48 ;
struct V_164 * V_165 ;
V_151 = F_112 () ;
if ( ! V_151 )
return - V_105 ;
F_145 ( V_166 ) ;
V_48 = F_146 ( V_167 , 1 ,
(struct V_168 * * ) & V_165 ) ;
if ( F_62 ( V_48 ) ) {
V_41 = - V_77 ;
goto error;
}
if ( ! V_165 -> V_169 . V_81 || ! V_165 -> V_18 . V_81 ) {
V_41 = - V_77 ;
goto error;
}
F_77 ( L_55 ) ;
if ( V_163 ) {
V_151 -> V_8 = V_165 -> V_18 . V_81 ;
V_151 -> V_14 = V_165 -> V_169 . V_81 ;
} else {
V_151 -> V_8 = V_165 -> V_169 . V_81 ;
V_151 -> V_14 = V_165 -> V_18 . V_81 ;
}
V_151 -> V_21 = V_165 -> V_21 ;
V_151 -> V_91 = V_170 ;
V_41 = F_123 ( V_151 ) ;
if ( ! V_41 )
V_88 = V_151 ;
error:
if ( V_41 ) {
F_92 ( V_151 ) ;
V_151 = NULL ;
}
return V_41 ;
}
static int F_147 ( const char * V_86 , struct V_171 * V_172 )
{
int V_82 = 0 ;
if ( ! strncmp ( V_86 , L_56 , sizeof( L_56 ) - 1 ) ) {
V_37 = V_38 ;
F_77 ( L_57 ) ;
} else if ( ! strncmp ( V_86 , L_58 , sizeof( L_58 ) - 1 ) ) {
V_37 = V_39 ;
F_77 ( L_59 ) ;
} else if ( ! strncmp ( V_86 , L_60 , sizeof( L_60 ) - 1 ) ) {
V_37 = V_44 ;
F_77 ( L_61 ) ;
} else
V_82 = - V_71 ;
return V_82 ;
}
static int F_148 ( char * V_137 , struct V_171 * V_172 )
{
switch ( V_37 ) {
case V_38 :
return sprintf ( V_137 , L_56 ) ;
case V_39 :
return sprintf ( V_137 , L_58 ) ;
case V_44 :
return sprintf ( V_137 , L_60 ) ;
default:
return sprintf ( V_137 , L_62 ) ;
}
return 0 ;
}
int T_9 F_149 ( void )
{
int V_82 = 0 ;
V_82 = F_150 ( & V_173 ) ;
if ( V_82 < 0 )
return - V_77 ;
return V_82 ;
}
