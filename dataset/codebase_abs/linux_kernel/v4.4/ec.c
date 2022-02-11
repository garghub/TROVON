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
if ( V_2 -> V_6 == 1 )
F_14 ( V_2 , true ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
bool V_27 = false ;
V_2 -> V_6 -- ;
if ( V_2 -> V_6 == 0 )
F_19 ( V_2 , true ) ;
V_27 = F_3 ( V_2 ) ;
if ( V_27 )
F_25 ( & V_2 -> V_28 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_29 )
{
if ( ! F_2 ( V_29 , & V_2 -> V_4 ) ) {
F_19 ( V_2 , false ) ;
F_27 ( L_13 ) ;
F_28 ( V_29 , & V_2 -> V_4 ) ;
}
}
static void F_29 ( struct V_1 * V_2 , T_1 V_29 )
{
if ( F_2 ( V_29 , & V_2 -> V_4 ) ) {
F_30 ( V_29 , & V_2 -> V_4 ) ;
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
if ( ! F_33 ( V_30 , & V_2 -> V_4 ) ) {
F_34 ( L_15 ,
F_11 ( V_31 ) ) ;
V_2 -> V_32 ++ ;
F_35 ( & V_2 -> V_33 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( F_2 ( V_30 , & V_2 -> V_4 ) ) {
F_30 ( V_30 , & V_2 -> V_4 ) ;
F_34 ( L_16 ,
F_11 ( V_31 ) ) ;
}
}
static bool F_37 ( struct V_1 * V_2 )
{
bool V_34 = true ;
unsigned long V_4 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( V_36 == V_37 ||
V_36 == V_38 ||
! F_2 ( V_30 , & V_2 -> V_4 ) ||
( V_2 -> V_39 && V_2 -> V_39 -> V_17 == V_31 ) )
V_34 = false ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_34 ;
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_40 = 0 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( V_2 -> V_39 && ( V_2 -> V_39 -> V_4 & V_41 ) )
V_40 = 1 ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_40 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_40 = 0 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( V_2 -> V_39 && ( V_2 -> V_39 -> V_4 & V_42 ) )
V_40 = 1 ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_40 ;
}
static inline void F_42 ( struct V_1 * V_2 , unsigned long V_29 )
{
V_2 -> V_39 -> V_4 |= V_29 ;
if ( V_2 -> V_39 -> V_17 == V_31 ) {
if ( V_36 == V_37 &&
V_29 == V_41 )
F_36 ( V_2 ) ;
if ( V_36 == V_38 &&
V_29 == V_42 )
F_36 ( V_2 ) ;
if ( V_36 == V_43 &&
V_29 == V_42 )
F_28 ( V_44 , & V_2 -> V_4 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
T_1 V_47 ;
bool V_48 = false ;
F_43 ( L_17 , F_44 () ? L_18 : L_19 ,
F_45 () ) ;
F_21 ( V_2 ) ;
V_47 = F_4 ( V_2 ) ;
V_46 = V_2 -> V_39 ;
if ( ! V_46 || ! ( V_46 -> V_4 & V_41 ) ) {
if ( V_36 == V_43 &&
( ! V_2 -> V_32 ||
F_2 ( V_44 , & V_2 -> V_4 ) ) ) {
F_30 ( V_44 , & V_2 -> V_4 ) ;
F_36 ( V_2 ) ;
}
}
if ( ! V_46 )
goto V_49;
if ( V_46 -> V_4 & V_41 ) {
if ( V_46 -> V_50 > V_46 -> V_51 ) {
if ( ( V_47 & V_12 ) == 0 )
F_10 ( V_2 , V_46 -> V_52 [ V_46 -> V_51 ++ ] ) ;
else
goto V_49;
} else if ( V_46 -> V_53 > V_46 -> V_54 ) {
if ( ( V_47 & V_13 ) == 1 ) {
V_46 -> V_55 [ V_46 -> V_54 ++ ] = F_7 ( V_2 ) ;
if ( V_46 -> V_53 == V_46 -> V_54 ) {
F_42 ( V_2 , V_42 ) ;
if ( V_46 -> V_17 == V_31 )
F_34 ( L_20 ,
F_11 ( V_31 ) ) ;
V_48 = true ;
}
} else
goto V_49;
} else if ( V_46 -> V_50 == V_46 -> V_51 &&
( V_47 & V_12 ) == 0 ) {
F_42 ( V_2 , V_42 ) ;
V_48 = true ;
}
goto V_56;
} else {
if ( V_57 &&
! ( V_47 & V_9 ) &&
( V_46 -> V_17 == V_31 ) ) {
F_42 ( V_2 , V_41 ) ;
V_46 -> V_55 [ V_46 -> V_54 ++ ] = 0x00 ;
F_42 ( V_2 , V_42 ) ;
F_34 ( L_21 ,
F_11 ( V_31 ) ) ;
V_48 = true ;
} else if ( ( V_47 & V_12 ) == 0 ) {
F_8 ( V_2 , V_46 -> V_17 ) ;
F_42 ( V_2 , V_41 ) ;
} else
goto V_49;
goto V_56;
}
V_49:
if ( ! ( V_47 & V_9 ) ) {
if ( F_44 () && V_46 ) {
if ( V_46 -> V_58 < V_59 )
++ V_46 -> V_58 ;
if ( V_46 -> V_58 == V_59 )
F_26 ( V_2 , V_60 ) ;
}
}
V_56:
if ( V_47 & V_9 )
F_32 ( V_2 ) ;
if ( V_48 && F_44 () )
F_25 ( & V_2 -> V_28 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_39 -> V_58 = V_2 -> V_39 -> V_51 = V_2 -> V_39 -> V_54 = 0 ;
V_2 -> V_39 -> V_4 = 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned long V_61 = F_48 ( V_62 ) ;
unsigned long V_63 = V_2 -> V_15 + V_61 ;
do {
if ( V_64 ) {
if ( F_41 ( V_2 ) )
return 0 ;
F_49 ( F_50 ( V_61 ) ) ;
} else {
if ( ! F_40 ( V_2 ) &&
! F_37 ( V_2 ) )
break;
if ( F_51 ( V_2 -> V_28 ,
F_41 ( V_2 ) ,
V_61 ) )
return 0 ;
}
} while ( F_52 ( V_16 , V_63 ) );
return - V_65 ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_66 = 5 ;
while ( V_66 -- ) {
unsigned long V_67 = V_16 +
F_54 ( V_68 ) ;
do {
if ( ! F_47 ( V_2 ) )
return 0 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
} while ( F_52 ( V_16 , V_67 ) );
F_55 ( L_22 ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
F_46 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
return - V_65 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
unsigned long V_69 ;
int V_40 = 0 ;
F_38 ( & V_2 -> V_35 , V_69 ) ;
if ( ! F_31 ( V_2 ) ) {
V_40 = - V_70 ;
goto V_71;
}
F_57 ( V_2 , L_23 ) ;
V_2 -> V_39 = V_46 ;
F_58 ( L_24 , F_11 ( V_46 -> V_17 ) ) ;
F_46 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_69 ) ;
V_40 = F_53 ( V_2 ) ;
F_38 ( & V_2 -> V_35 , V_69 ) ;
if ( V_46 -> V_58 == V_59 )
F_29 ( V_2 , V_60 ) ;
F_58 ( L_25 , F_11 ( V_46 -> V_17 ) ) ;
V_2 -> V_39 = NULL ;
F_24 ( V_2 ) ;
F_57 ( V_2 , L_26 ) ;
V_71:
F_39 ( & V_2 -> V_35 , V_69 ) ;
return V_40 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_47 ;
T_3 V_72 ;
if ( ! V_2 || ( ! V_46 ) || ( V_46 -> V_50 && ! V_46 -> V_52 ) || ( V_46 -> V_53 && ! V_46 -> V_55 ) )
return - V_70 ;
if ( V_46 -> V_55 )
memset ( V_46 -> V_55 , 0 , V_46 -> V_53 ) ;
F_60 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_74 ) {
V_47 = F_61 ( V_75 , & V_72 ) ;
if ( F_62 ( V_47 ) ) {
V_47 = - V_76 ;
goto V_71;
}
}
V_47 = F_56 ( V_2 , V_46 ) ;
if ( V_2 -> V_74 )
F_63 ( V_72 ) ;
V_71:
F_64 ( & V_2 -> V_73 ) ;
return V_47 ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_1 V_77 ;
struct V_45 V_46 = { . V_17 = V_78 ,
. V_52 = NULL , . V_55 = & V_77 ,
. V_50 = 0 , . V_53 = 1 } ;
return F_59 ( V_2 , & V_46 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_45 V_46 = { . V_17 = V_79 ,
. V_52 = NULL , . V_55 = NULL ,
. V_50 = 0 , . V_53 = 0 } ;
return ( F_4 ( V_2 ) & V_10 ) ?
F_59 ( V_2 , & V_46 ) : 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_80 , T_1 * V_18 )
{
int V_81 ;
T_1 V_77 ;
struct V_45 V_46 = { . V_17 = V_82 ,
. V_52 = & V_80 , . V_55 = & V_77 ,
. V_50 = 1 , . V_53 = 1 } ;
V_81 = F_59 ( V_2 , & V_46 ) ;
* V_18 = V_77 ;
return V_81 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_18 )
{
T_1 V_52 [ 2 ] = { V_80 , V_18 } ;
struct V_45 V_46 = { . V_17 = V_83 ,
. V_52 = V_52 , . V_55 = NULL ,
. V_50 = 2 , . V_53 = 0 } ;
return F_59 ( V_2 , & V_46 ) ;
}
int F_69 ( T_1 V_84 , T_1 * V_85 )
{
int V_49 ;
T_1 V_86 ;
if ( ! V_87 )
return - V_76 ;
V_49 = F_67 ( V_87 , V_84 , & V_86 ) ;
if ( ! V_49 ) {
* V_85 = V_86 ;
return 0 ;
}
return V_49 ;
}
int F_70 ( T_1 V_84 , T_1 V_85 )
{
int V_49 ;
if ( ! V_87 )
return - V_76 ;
V_49 = F_68 ( V_87 , V_84 , V_85 ) ;
return V_49 ;
}
int F_71 ( T_1 V_17 ,
const T_1 * V_52 , unsigned V_88 ,
T_1 * V_55 , unsigned V_89 )
{
struct V_45 V_46 = { . V_17 = V_17 ,
. V_52 = V_52 , . V_55 = V_55 ,
. V_50 = V_88 , . V_53 = V_89 } ;
if ( ! V_87 )
return - V_76 ;
return F_59 ( V_87 , & V_46 ) ;
}
T_4 F_72 ( void )
{
if ( ! V_87 )
return NULL ;
return V_87 -> V_90 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_91 , V_47 ;
T_1 V_92 = 0 ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_47 = F_74 ( V_2 , & V_92 ) ;
if ( V_47 || ! V_92 )
break;
}
if ( F_75 ( V_91 == V_93 ) )
F_76 ( L_27 , V_91 ) ;
else
F_77 ( L_28 , V_91 ) ;
}
static void F_78 ( struct V_1 * V_2 , bool V_94 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( ! F_33 ( V_3 , & V_2 -> V_4 ) ) {
F_27 ( L_29 ) ;
if ( ! V_94 ) {
F_23 ( V_2 ) ;
F_57 ( V_2 , L_30 ) ;
}
F_79 ( L_31 ) ;
}
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
static bool F_80 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_27 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
V_27 = F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_27 ;
}
static void F_81 ( struct V_1 * V_2 , bool V_95 )
{
unsigned long V_4 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( L_32 ) ;
F_28 ( V_5 , & V_2 -> V_4 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
F_82 ( V_2 -> V_28 , F_80 ( V_2 ) ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( ! V_95 ) {
F_24 ( V_2 ) ;
F_57 ( V_2 , L_33 ) ;
}
F_30 ( V_3 , & V_2 -> V_4 ) ;
F_30 ( V_5 , & V_2 -> V_4 ) ;
F_79 ( L_34 ) ;
}
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
void F_83 ( void )
{
struct V_1 * V_2 = V_87 ;
if ( ! V_2 )
return;
F_60 ( & V_2 -> V_73 ) ;
F_81 ( V_2 , true ) ;
F_64 ( & V_2 -> V_73 ) ;
}
void F_84 ( void )
{
struct V_1 * V_2 = V_87 ;
if ( ! V_2 )
return;
F_78 ( V_2 , true ) ;
if ( V_96 )
F_73 ( V_2 ) ;
}
void F_85 ( void )
{
if ( V_87 )
F_78 ( V_87 , true ) ;
}
static struct V_97 *
F_86 ( struct V_97 * V_98 )
{
if ( V_98 )
F_87 ( & V_98 -> V_99 ) ;
return V_98 ;
}
static struct V_97 *
F_88 ( struct V_1 * V_2 , T_1 V_92 )
{
struct V_97 * V_98 ;
bool V_100 = false ;
F_60 ( & V_2 -> V_73 ) ;
F_89 (handler, &ec->list, node) {
if ( V_92 == V_98 -> V_101 ) {
V_100 = true ;
break;
}
}
F_64 ( & V_2 -> V_73 ) ;
return V_100 ? F_86 ( V_98 ) : NULL ;
}
static void F_90 ( struct V_99 * V_99 )
{
struct V_97 * V_98 =
F_91 ( V_99 , struct V_97 , V_99 ) ;
F_92 ( V_98 ) ;
}
static void F_93 ( struct V_97 * V_98 )
{
F_94 ( & V_98 -> V_99 , F_90 ) ;
}
int F_95 ( struct V_1 * V_2 , T_1 V_101 ,
T_4 V_90 , T_5 V_102 ,
void * V_18 )
{
struct V_97 * V_98 =
F_96 ( sizeof( struct V_97 ) , V_103 ) ;
if ( ! V_98 )
return - V_104 ;
V_98 -> V_101 = V_101 ;
V_98 -> V_90 = V_90 ;
V_98 -> V_102 = V_102 ;
V_98 -> V_18 = V_18 ;
F_60 ( & V_2 -> V_73 ) ;
F_97 ( & V_98 -> V_99 ) ;
F_98 ( & V_98 -> V_105 , & V_2 -> V_106 ) ;
F_64 ( & V_2 -> V_73 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 ,
bool V_107 , T_1 V_101 )
{
struct V_97 * V_98 , * V_69 ;
F_100 ( V_108 ) ;
F_60 ( & V_2 -> V_73 ) ;
F_101 (handler, tmp, &ec->list, node) {
if ( V_107 || V_101 == V_98 -> V_101 ) {
F_102 ( & V_98 -> V_105 ) ;
F_98 ( & V_98 -> V_105 , & V_108 ) ;
}
}
F_64 ( & V_2 -> V_73 ) ;
F_101 (handler, tmp, &free_list, node)
F_93 ( V_98 ) ;
}
void F_103 ( struct V_1 * V_2 , T_1 V_101 )
{
F_99 ( V_2 , false , V_101 ) ;
}
static struct F_74 * F_104 ( T_1 * V_109 )
{
struct F_74 * V_110 ;
struct V_45 * V_46 ;
V_110 = F_96 ( sizeof ( struct F_74 ) , V_103 ) ;
if ( ! V_110 )
return NULL ;
F_105 ( & V_110 -> V_33 , V_111 ) ;
V_46 = & V_110 -> V_45 ;
V_46 -> V_17 = V_31 ;
V_46 -> V_55 = V_109 ;
V_46 -> V_53 = 1 ;
return V_110 ;
}
static void F_106 ( struct F_74 * V_110 )
{
if ( V_110 ) {
if ( V_110 -> V_98 )
F_93 ( V_110 -> V_98 ) ;
F_92 ( V_110 ) ;
}
}
static void V_111 ( struct V_112 * V_33 )
{
struct F_74 * V_110 = F_91 ( V_33 , struct F_74 , V_33 ) ;
struct V_97 * V_98 = V_110 -> V_98 ;
F_34 ( L_35 , V_98 -> V_101 ) ;
if ( V_98 -> V_102 )
V_98 -> V_102 ( V_98 -> V_18 ) ;
else if ( V_98 -> V_90 )
F_107 ( V_98 -> V_90 , NULL , NULL , NULL ) ;
F_34 ( L_36 , V_98 -> V_101 ) ;
F_106 ( V_110 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_1 * V_18 )
{
T_1 V_92 = 0 ;
int V_81 ;
struct F_74 * V_110 ;
V_110 = F_104 ( & V_92 ) ;
if ( ! V_110 )
return - V_104 ;
V_81 = F_59 ( V_2 , & V_110 -> V_45 ) ;
if ( ! V_92 )
V_81 = - V_113 ;
if ( V_81 )
goto V_114;
V_110 -> V_98 = F_88 ( V_2 , V_92 ) ;
if ( ! V_110 -> V_98 ) {
V_81 = - V_113 ;
goto V_114;
}
F_34 ( L_37 , V_92 ) ;
if ( ! F_35 ( & V_110 -> V_33 ) ) {
F_34 ( L_38 , V_92 ) ;
V_81 = - V_115 ;
}
V_114:
if ( V_81 )
F_106 ( V_110 ) ;
if ( V_18 )
* V_18 = V_92 ;
return V_81 ;
}
static void F_108 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_36 == V_43 ) {
if ( F_47 ( V_2 ) ) {
F_38 ( & V_2 -> V_35 , V_4 ) ;
if ( ! V_2 -> V_39 )
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
}
}
}
static void F_109 ( struct V_112 * V_33 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_91 ( V_33 , struct V_1 , V_33 ) ;
F_34 ( L_39 ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
while ( V_2 -> V_32 ) {
F_39 ( & V_2 -> V_35 , V_4 ) ;
( void ) F_74 ( V_2 , NULL ) ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
V_2 -> V_32 -- ;
if ( ! V_2 -> V_32 ) {
if ( V_36 == V_37 ||
V_36 == V_38 )
F_36 ( V_2 ) ;
}
}
F_39 ( & V_2 -> V_35 , V_4 ) ;
F_34 ( L_40 ) ;
F_108 ( V_2 ) ;
}
static T_3 F_110 ( T_4 V_116 ,
T_3 V_117 , void * V_18 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_18 ;
F_38 ( & V_2 -> V_35 , V_4 ) ;
F_18 ( V_2 ) ;
F_39 ( & V_2 -> V_35 , V_4 ) ;
return V_118 ;
}
static T_6
F_111 ( T_3 V_119 , T_7 V_80 ,
T_3 V_120 , T_8 * V_121 ,
void * V_122 , void * V_123 )
{
struct V_1 * V_2 = V_122 ;
int V_81 = 0 , V_91 , V_124 = V_120 / 8 ;
T_1 * V_92 = ( T_1 * ) V_121 ;
if ( ( V_80 > 0xFF ) || ! V_92 || ! V_122 )
return V_125 ;
if ( V_119 != V_126 && V_119 != V_127 )
return V_125 ;
if ( V_64 || V_120 > 8 )
F_65 ( V_2 ) ;
for ( V_91 = 0 ; V_91 < V_124 ; ++ V_91 , ++ V_80 , ++ V_92 )
V_81 = ( V_119 == V_126 ) ?
F_67 ( V_2 , V_80 , V_92 ) :
F_68 ( V_2 , V_80 , * V_92 ) ;
if ( V_64 || V_120 > 8 )
F_66 ( V_2 ) ;
switch ( V_81 ) {
case - V_70 :
return V_125 ;
case - V_76 :
return V_128 ;
case - V_65 :
return V_129 ;
default:
return V_130 ;
}
}
static struct V_1 * F_112 ( void )
{
struct V_1 * V_2 = F_96 ( sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = 1 << V_30 ;
F_113 ( & V_2 -> V_73 ) ;
F_114 ( & V_2 -> V_28 ) ;
F_115 ( & V_2 -> V_106 ) ;
F_116 ( & V_2 -> V_35 ) ;
F_105 ( & V_2 -> V_33 , F_109 ) ;
V_2 -> V_15 = V_16 ;
return V_2 ;
}
static T_6
F_117 ( T_4 V_90 , T_3 V_131 ,
void * V_132 , void * * V_133 )
{
char V_134 [ 5 ] ;
struct V_135 V_136 = { sizeof( V_134 ) , V_134 } ;
struct V_1 * V_2 = V_132 ;
int V_92 = 0 ;
T_6 V_47 ;
V_47 = F_118 ( V_90 , V_137 , & V_136 ) ;
if ( F_119 ( V_47 ) && sscanf ( V_134 , L_41 , & V_92 ) == 1 )
F_95 ( V_2 , V_92 , V_90 , NULL , NULL ) ;
return V_130 ;
}
static T_6
F_120 ( T_4 V_90 , T_3 V_138 , void * V_132 , void * * V_139 )
{
T_6 V_47 ;
unsigned long long V_69 = 0 ;
struct V_1 * V_2 = V_132 ;
V_2 -> V_8 = V_2 -> V_14 = 0 ;
V_47 = F_121 ( V_90 , V_140 ,
V_141 , V_2 ) ;
if ( F_62 ( V_47 ) )
return V_47 ;
V_47 = F_122 ( V_90 , L_42 , NULL , & V_69 ) ;
if ( F_62 ( V_47 ) )
return V_47 ;
V_2 -> V_21 = V_69 ;
V_69 = 0 ;
F_122 ( V_90 , L_43 , NULL , & V_69 ) ;
V_2 -> V_74 = V_69 ;
V_2 -> V_90 = V_90 ;
return V_142 ;
}
static int F_123 ( struct V_1 * V_2 )
{
T_6 V_47 ;
if ( F_2 ( V_143 , & V_2 -> V_4 ) )
return 0 ;
V_47 = F_124 ( NULL , V_2 -> V_21 ,
V_144 ,
& F_110 , V_2 ) ;
if ( F_62 ( V_47 ) )
return - V_76 ;
F_78 ( V_2 , false ) ;
V_47 = F_125 ( V_2 -> V_90 ,
V_145 ,
& F_111 ,
NULL , V_2 ) ;
if ( F_62 ( V_47 ) ) {
if ( V_47 == V_128 ) {
F_126 ( L_44
L_45 ) ;
} else {
F_81 ( V_2 , false ) ;
F_127 ( NULL , V_2 -> V_21 ,
& F_110 ) ;
return - V_76 ;
}
}
F_28 ( V_143 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_143 , & V_2 -> V_4 ) )
return;
F_81 ( V_2 , false ) ;
if ( F_62 ( F_129 ( V_2 -> V_90 ,
V_145 , & F_111 ) ) )
F_126 ( L_46 ) ;
if ( F_62 ( F_127 ( NULL , V_2 -> V_21 ,
& F_110 ) ) )
F_126 ( L_47 ) ;
F_30 ( V_143 , & V_2 -> V_4 ) ;
}
static int F_130 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = NULL ;
int V_40 ;
strcpy ( F_131 ( V_147 ) , V_148 ) ;
strcpy ( F_132 ( V_147 ) , V_149 ) ;
if ( V_150 &&
( V_150 -> V_90 == V_147 -> V_90 ||
V_150 -> V_90 == V_151 ) ) {
V_2 = V_150 ;
V_150 = NULL ;
} else {
V_2 = F_112 () ;
if ( ! V_2 )
return - V_104 ;
}
if ( F_120 ( V_147 -> V_90 , 0 , V_2 , NULL ) !=
V_142 ) {
F_92 ( V_2 ) ;
return - V_70 ;
}
F_133 ( V_152 , V_2 -> V_90 , 1 ,
F_117 , NULL , V_2 , NULL ) ;
if ( ! V_87 )
V_87 = V_2 ;
V_147 -> V_153 = V_2 ;
V_40 = ! ! F_134 ( V_2 -> V_14 , 1 , L_48 ) ;
F_135 ( ! V_40 , L_49 , V_2 -> V_14 ) ;
V_40 = ! ! F_134 ( V_2 -> V_8 , 1 , L_50 ) ;
F_135 ( ! V_40 , L_51 , V_2 -> V_8 ) ;
F_77 ( L_52 ,
V_2 -> V_21 , V_2 -> V_8 , V_2 -> V_14 ) ;
V_40 = F_123 ( V_2 ) ;
F_136 ( V_2 -> V_90 ) ;
F_30 ( V_30 , & V_2 -> V_4 ) ;
if ( V_96 )
F_73 ( V_2 ) ;
return V_40 ;
}
static int F_137 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
if ( ! V_147 )
return - V_70 ;
V_2 = F_138 ( V_147 ) ;
F_128 ( V_2 ) ;
F_99 ( V_2 , true , 0 ) ;
F_139 ( V_2 -> V_14 , 1 ) ;
F_139 ( V_2 -> V_8 , 1 ) ;
V_147 -> V_153 = NULL ;
if ( V_2 == V_87 )
V_87 = NULL ;
F_92 ( V_2 ) ;
return 0 ;
}
static T_6
V_141 ( struct V_154 * V_155 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
if ( V_155 -> type != V_156 )
return V_130 ;
if ( V_2 -> V_14 == 0 )
V_2 -> V_14 = V_155 -> V_18 . V_157 . V_158 ;
else if ( V_2 -> V_8 == 0 )
V_2 -> V_8 = V_155 -> V_18 . V_157 . V_158 ;
else
return V_142 ;
return V_130 ;
}
int T_9 F_140 ( void )
{
if ( ! V_150 || F_2 ( V_143 , & V_150 -> V_4 ) )
return 0 ;
if ( ! F_123 ( V_150 ) ) {
V_87 = V_150 ;
return 0 ;
}
return - V_159 ;
}
static int F_141 ( const struct V_160 * V_161 )
{
V_162 = 1 ;
return 0 ;
}
static int F_142 ( const struct V_160 * V_161 )
{
V_163 = 1 ;
return 0 ;
}
static int F_143 ( const struct V_160 * V_161 )
{
F_55 ( L_53 ) ;
V_96 = 1 ;
V_36 = V_37 ;
return 0 ;
}
int T_9 F_144 ( void )
{
T_6 V_47 ;
struct V_1 * V_164 = NULL ;
struct V_165 * V_166 ;
V_150 = F_112 () ;
if ( ! V_150 )
return - V_104 ;
F_145 ( V_167 ) ;
V_47 = F_146 ( V_168 , 1 ,
(struct V_169 * * ) & V_166 ) ;
if ( F_119 ( V_47 ) ) {
F_77 ( L_54 ) ;
V_150 -> V_8 = V_166 -> V_170 . V_80 ;
V_150 -> V_14 = V_166 -> V_18 . V_80 ;
V_150 -> V_21 = V_166 -> V_21 ;
V_150 -> V_90 = V_151 ;
F_147 ( V_151 , V_166 -> V_161 ,
& V_150 -> V_90 ) ;
if ( ! V_163 )
goto V_171;
V_164 = F_148 ( V_150 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_164 )
return - V_104 ;
}
if ( V_162 ) {
F_92 ( V_164 ) ;
return - V_76 ;
}
F_55 ( L_55 ) ;
V_47 = F_149 ( V_172 [ 0 ] . V_161 , F_120 ,
V_150 , NULL ) ;
if ( F_62 ( V_47 ) || ! V_150 -> V_90 )
goto error;
if ( V_164 ) {
if ( V_164 -> V_8 != V_150 -> V_8 ||
V_164 -> V_14 != V_150 -> V_14 ||
V_164 -> V_21 != V_150 -> V_21 ||
V_164 -> V_90 != V_150 -> V_90 )
F_77 ( L_56
L_57
L_58
L_59 ) ;
F_92 ( V_164 ) ;
V_164 = NULL ;
} else {
if ( ! F_150 ( L_60 ) ||
! F_151 ( V_150 -> V_90 , L_61 ) )
return - V_76 ;
}
V_171:
if ( ! F_123 ( V_150 ) ) {
V_87 = V_150 ;
return 0 ;
}
error:
F_92 ( V_150 ) ;
F_92 ( V_164 ) ;
V_150 = NULL ;
return - V_76 ;
}
static int F_152 ( const char * V_85 , struct V_173 * V_174 )
{
int V_81 = 0 ;
if ( ! strncmp ( V_85 , L_62 , sizeof( L_62 ) - 1 ) ) {
V_36 = V_37 ;
F_77 ( L_63 ) ;
} else if ( ! strncmp ( V_85 , L_64 , sizeof( L_64 ) - 1 ) ) {
V_36 = V_38 ;
F_77 ( L_65 ) ;
} else if ( ! strncmp ( V_85 , L_66 , sizeof( L_66 ) - 1 ) ) {
V_36 = V_43 ;
F_77 ( L_67 ) ;
} else
V_81 = - V_70 ;
return V_81 ;
}
static int F_153 ( char * V_136 , struct V_173 * V_174 )
{
switch ( V_36 ) {
case V_37 :
return sprintf ( V_136 , L_62 ) ;
case V_38 :
return sprintf ( V_136 , L_64 ) ;
case V_43 :
return sprintf ( V_136 , L_66 ) ;
default:
return sprintf ( V_136 , L_68 ) ;
}
return 0 ;
}
int T_9 F_154 ( void )
{
int V_81 = 0 ;
V_81 = F_155 ( & V_175 ) ;
if ( V_81 < 0 )
return - V_76 ;
return V_81 ;
}
