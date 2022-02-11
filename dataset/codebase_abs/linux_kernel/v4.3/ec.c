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
if ( V_34 == V_35 ||
V_34 == V_36 ||
! F_2 ( V_30 , & V_2 -> V_4 ) ||
( V_2 -> V_37 && V_2 -> V_37 -> V_17 == V_31 ) )
return false ;
return true ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_38 = 0 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( V_2 -> V_37 && ( V_2 -> V_37 -> V_4 & V_40 ) )
V_38 = 1 ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_38 = 0 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( V_2 -> V_37 && ( V_2 -> V_37 -> V_4 & V_41 ) )
V_38 = 1 ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
return V_38 ;
}
static inline void F_42 ( struct V_1 * V_2 , unsigned long V_29 )
{
V_2 -> V_37 -> V_4 |= V_29 ;
if ( V_2 -> V_37 -> V_17 == V_31 ) {
if ( V_34 == V_35 &&
V_29 == V_40 )
F_36 ( V_2 ) ;
if ( V_34 == V_36 &&
V_29 == V_41 )
F_36 ( V_2 ) ;
if ( V_34 == V_42 &&
V_29 == V_41 )
F_28 ( V_43 , & V_2 -> V_4 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
T_1 V_46 ;
bool V_47 = false ;
F_43 ( L_17 , F_44 () ? L_18 : L_19 ,
F_45 () ) ;
F_21 ( V_2 ) ;
V_46 = F_4 ( V_2 ) ;
V_45 = V_2 -> V_37 ;
if ( ! V_45 || ! ( V_45 -> V_4 & V_40 ) ) {
if ( V_34 == V_42 &&
( ! V_2 -> V_32 ||
F_2 ( V_43 , & V_2 -> V_4 ) ) ) {
F_30 ( V_43 , & V_2 -> V_4 ) ;
F_36 ( V_2 ) ;
}
}
if ( ! V_45 )
goto V_48;
if ( V_45 -> V_4 & V_40 ) {
if ( V_45 -> V_49 > V_45 -> V_50 ) {
if ( ( V_46 & V_12 ) == 0 )
F_10 ( V_2 , V_45 -> V_51 [ V_45 -> V_50 ++ ] ) ;
else
goto V_48;
} else if ( V_45 -> V_52 > V_45 -> V_53 ) {
if ( ( V_46 & V_13 ) == 1 ) {
V_45 -> V_54 [ V_45 -> V_53 ++ ] = F_7 ( V_2 ) ;
if ( V_45 -> V_52 == V_45 -> V_53 ) {
F_42 ( V_2 , V_41 ) ;
if ( V_45 -> V_17 == V_31 )
F_34 ( L_20 ,
F_11 ( V_31 ) ) ;
V_47 = true ;
}
} else
goto V_48;
} else if ( V_45 -> V_49 == V_45 -> V_50 &&
( V_46 & V_12 ) == 0 ) {
F_42 ( V_2 , V_41 ) ;
V_47 = true ;
}
goto V_55;
} else {
if ( V_56 &&
! ( V_46 & V_9 ) &&
( V_45 -> V_17 == V_31 ) ) {
F_42 ( V_2 , V_40 ) ;
V_45 -> V_54 [ V_45 -> V_53 ++ ] = 0x00 ;
F_42 ( V_2 , V_41 ) ;
F_34 ( L_21 ,
F_11 ( V_31 ) ) ;
V_47 = true ;
} else if ( ( V_46 & V_12 ) == 0 ) {
F_8 ( V_2 , V_45 -> V_17 ) ;
F_42 ( V_2 , V_40 ) ;
} else
goto V_48;
goto V_55;
}
V_48:
if ( ! ( V_46 & V_9 ) ) {
if ( F_44 () && V_45 ) {
if ( V_45 -> V_57 < V_58 )
++ V_45 -> V_57 ;
if ( V_45 -> V_57 == V_58 )
F_26 ( V_2 , V_59 ) ;
}
}
V_55:
if ( V_46 & V_9 )
F_32 ( V_2 ) ;
if ( V_47 && F_44 () )
F_25 ( & V_2 -> V_28 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_37 -> V_57 = V_2 -> V_37 -> V_50 = V_2 -> V_37 -> V_53 = 0 ;
V_2 -> V_37 -> V_4 = 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned long V_60 = F_48 ( V_61 ) ;
unsigned long V_62 = V_2 -> V_15 + V_60 ;
do {
if ( V_63 ) {
if ( F_41 ( V_2 ) )
return 0 ;
F_49 ( F_50 ( V_60 ) ) ;
} else {
if ( ! F_38 ( V_2 ) &&
! F_37 ( V_2 ) )
break;
if ( F_51 ( V_2 -> V_28 ,
F_41 ( V_2 ) ,
V_60 ) )
return 0 ;
}
} while ( F_52 ( V_16 , V_62 ) );
return - V_64 ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_65 = 5 ;
while ( V_65 -- ) {
unsigned long V_66 = V_16 +
F_54 ( V_67 ) ;
do {
if ( ! F_47 ( V_2 ) )
return 0 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
F_18 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
} while ( F_52 ( V_16 , V_66 ) );
F_55 ( L_22 ) ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
F_46 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
}
return - V_64 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned long V_68 ;
int V_38 = 0 ;
F_39 ( & V_2 -> V_39 , V_68 ) ;
if ( ! F_31 ( V_2 ) ) {
V_38 = - V_69 ;
goto V_70;
}
F_57 ( V_2 , L_23 ) ;
V_2 -> V_37 = V_45 ;
F_58 ( L_24 , F_11 ( V_45 -> V_17 ) ) ;
F_46 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_68 ) ;
V_38 = F_53 ( V_2 ) ;
F_39 ( & V_2 -> V_39 , V_68 ) ;
if ( V_45 -> V_57 == V_58 )
F_29 ( V_2 , V_59 ) ;
F_58 ( L_25 , F_11 ( V_45 -> V_17 ) ) ;
V_2 -> V_37 = NULL ;
F_24 ( V_2 ) ;
F_57 ( V_2 , L_26 ) ;
V_70:
F_40 ( & V_2 -> V_39 , V_68 ) ;
return V_38 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_46 ;
T_3 V_71 ;
if ( ! V_2 || ( ! V_45 ) || ( V_45 -> V_49 && ! V_45 -> V_51 ) || ( V_45 -> V_52 && ! V_45 -> V_54 ) )
return - V_69 ;
if ( V_45 -> V_54 )
memset ( V_45 -> V_54 , 0 , V_45 -> V_52 ) ;
F_60 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_73 ) {
V_46 = F_61 ( V_74 , & V_71 ) ;
if ( F_62 ( V_46 ) ) {
V_46 = - V_75 ;
goto V_70;
}
}
V_46 = F_56 ( V_2 , V_45 ) ;
if ( V_2 -> V_73 )
F_63 ( V_71 ) ;
V_70:
F_64 ( & V_2 -> V_72 ) ;
return V_46 ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_1 V_76 ;
struct V_44 V_45 = { . V_17 = V_77 ,
. V_51 = NULL , . V_54 = & V_76 ,
. V_49 = 0 , . V_52 = 1 } ;
return F_59 ( V_2 , & V_45 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_44 V_45 = { . V_17 = V_78 ,
. V_51 = NULL , . V_54 = NULL ,
. V_49 = 0 , . V_52 = 0 } ;
return ( F_4 ( V_2 ) & V_10 ) ?
F_59 ( V_2 , & V_45 ) : 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_79 , T_1 * V_18 )
{
int V_80 ;
T_1 V_76 ;
struct V_44 V_45 = { . V_17 = V_81 ,
. V_51 = & V_79 , . V_54 = & V_76 ,
. V_49 = 1 , . V_52 = 1 } ;
V_80 = F_59 ( V_2 , & V_45 ) ;
* V_18 = V_76 ;
return V_80 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_79 , T_1 V_18 )
{
T_1 V_51 [ 2 ] = { V_79 , V_18 } ;
struct V_44 V_45 = { . V_17 = V_82 ,
. V_51 = V_51 , . V_54 = NULL ,
. V_49 = 2 , . V_52 = 0 } ;
return F_59 ( V_2 , & V_45 ) ;
}
int F_69 ( T_1 V_83 , T_1 * V_84 )
{
int V_48 ;
T_1 V_85 ;
if ( ! V_86 )
return - V_75 ;
V_48 = F_67 ( V_86 , V_83 , & V_85 ) ;
if ( ! V_48 ) {
* V_84 = V_85 ;
return 0 ;
}
return V_48 ;
}
int F_70 ( T_1 V_83 , T_1 V_84 )
{
int V_48 ;
if ( ! V_86 )
return - V_75 ;
V_48 = F_68 ( V_86 , V_83 , V_84 ) ;
return V_48 ;
}
int F_71 ( T_1 V_17 ,
const T_1 * V_51 , unsigned V_87 ,
T_1 * V_54 , unsigned V_88 )
{
struct V_44 V_45 = { . V_17 = V_17 ,
. V_51 = V_51 , . V_54 = V_54 ,
. V_49 = V_87 , . V_52 = V_88 } ;
if ( ! V_86 )
return - V_75 ;
return F_59 ( V_86 , & V_45 ) ;
}
T_4 F_72 ( void )
{
if ( ! V_86 )
return NULL ;
return V_86 -> V_89 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_90 , V_46 ;
T_1 V_91 = 0 ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
V_46 = F_74 ( V_2 , & V_91 ) ;
if ( V_46 || ! V_91 )
break;
}
if ( F_75 ( V_90 == V_92 ) )
F_76 ( L_27 , V_90 ) ;
else
F_77 ( L_28 , V_90 ) ;
}
static void F_78 ( struct V_1 * V_2 , bool V_93 )
{
unsigned long V_4 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( ! F_33 ( V_3 , & V_2 -> V_4 ) ) {
F_27 ( L_29 ) ;
if ( ! V_93 ) {
F_23 ( V_2 ) ;
F_57 ( V_2 , L_30 ) ;
}
F_79 ( L_31 ) ;
}
F_40 ( & V_2 -> V_39 , V_4 ) ;
}
static bool F_80 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
bool V_27 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
V_27 = F_3 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
return V_27 ;
}
static void F_81 ( struct V_1 * V_2 , bool V_94 )
{
unsigned long V_4 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( L_32 ) ;
F_28 ( V_5 , & V_2 -> V_4 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
F_82 ( V_2 -> V_28 , F_80 ( V_2 ) ) ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( ! V_94 ) {
F_24 ( V_2 ) ;
F_57 ( V_2 , L_33 ) ;
}
F_30 ( V_3 , & V_2 -> V_4 ) ;
F_30 ( V_5 , & V_2 -> V_4 ) ;
F_79 ( L_34 ) ;
}
F_40 ( & V_2 -> V_39 , V_4 ) ;
}
void F_83 ( void )
{
struct V_1 * V_2 = V_86 ;
if ( ! V_2 )
return;
F_60 ( & V_2 -> V_72 ) ;
F_81 ( V_2 , true ) ;
F_64 ( & V_2 -> V_72 ) ;
}
void F_84 ( void )
{
struct V_1 * V_2 = V_86 ;
if ( ! V_2 )
return;
F_78 ( V_2 , true ) ;
if ( V_95 )
F_73 ( V_2 ) ;
}
void F_85 ( void )
{
if ( V_86 )
F_78 ( V_86 , true ) ;
}
static struct V_96 *
F_86 ( struct V_96 * V_97 )
{
if ( V_97 )
F_87 ( & V_97 -> V_98 ) ;
return V_97 ;
}
static void F_88 ( struct V_98 * V_98 )
{
struct V_96 * V_97 =
F_89 ( V_98 , struct V_96 , V_98 ) ;
F_90 ( V_97 ) ;
}
static void F_91 ( struct V_96 * V_97 )
{
F_92 ( & V_97 -> V_98 , F_88 ) ;
}
int F_93 ( struct V_1 * V_2 , T_1 V_99 ,
T_4 V_89 , T_5 V_100 ,
void * V_18 )
{
struct V_96 * V_97 =
F_94 ( sizeof( struct V_96 ) , V_101 ) ;
if ( ! V_97 )
return - V_102 ;
V_97 -> V_99 = V_99 ;
V_97 -> V_89 = V_89 ;
V_97 -> V_100 = V_100 ;
V_97 -> V_18 = V_18 ;
F_60 ( & V_2 -> V_72 ) ;
F_95 ( & V_97 -> V_98 ) ;
F_96 ( & V_97 -> V_103 , & V_2 -> V_104 ) ;
F_64 ( & V_2 -> V_72 ) ;
return 0 ;
}
void F_97 ( struct V_1 * V_2 , T_1 V_99 )
{
struct V_96 * V_97 , * V_68 ;
F_98 ( V_105 ) ;
F_60 ( & V_2 -> V_72 ) ;
F_99 (handler, tmp, &ec->list, node) {
if ( V_99 == V_97 -> V_99 ) {
F_100 ( & V_97 -> V_103 ) ;
F_96 ( & V_97 -> V_103 , & V_105 ) ;
}
}
F_64 ( & V_2 -> V_72 ) ;
F_99 (handler, tmp, &free_list, node)
F_91 ( V_97 ) ;
}
static struct F_74 * F_101 ( T_1 * V_106 )
{
struct F_74 * V_107 ;
struct V_44 * V_45 ;
V_107 = F_94 ( sizeof ( struct F_74 ) , V_101 ) ;
if ( ! V_107 )
return NULL ;
F_102 ( & V_107 -> V_33 , V_108 ) ;
V_45 = & V_107 -> V_44 ;
V_45 -> V_17 = V_31 ;
V_45 -> V_54 = V_106 ;
V_45 -> V_52 = 1 ;
return V_107 ;
}
static void F_103 ( struct F_74 * V_107 )
{
if ( V_107 ) {
if ( V_107 -> V_97 )
F_91 ( V_107 -> V_97 ) ;
F_90 ( V_107 ) ;
}
}
static void V_108 ( struct V_109 * V_33 )
{
struct F_74 * V_107 = F_89 ( V_33 , struct F_74 , V_33 ) ;
struct V_96 * V_97 = V_107 -> V_97 ;
F_34 ( L_35 , V_97 -> V_99 ) ;
if ( V_97 -> V_100 )
V_97 -> V_100 ( V_97 -> V_18 ) ;
else if ( V_97 -> V_89 )
F_104 ( V_97 -> V_89 , NULL , NULL , NULL ) ;
F_34 ( L_36 , V_97 -> V_99 ) ;
F_103 ( V_107 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_1 * V_18 )
{
T_1 V_91 = 0 ;
int V_80 ;
struct V_96 * V_97 ;
struct F_74 * V_107 ;
V_107 = F_101 ( & V_91 ) ;
if ( ! V_107 )
return - V_102 ;
V_80 = F_59 ( V_2 , & V_107 -> V_44 ) ;
if ( ! V_91 )
V_80 = - V_110 ;
if ( V_80 )
goto V_111;
F_60 ( & V_2 -> V_72 ) ;
V_80 = - V_110 ;
F_105 (handler, &ec->list, node) {
if ( V_91 == V_97 -> V_99 ) {
V_80 = 0 ;
V_107 -> V_97 = F_86 ( V_97 ) ;
F_34 ( L_37 ,
V_107 -> V_97 -> V_99 ) ;
if ( ! F_35 ( & V_107 -> V_33 ) )
V_80 = - V_112 ;
break;
}
}
F_64 ( & V_2 -> V_72 ) ;
V_111:
if ( V_80 && V_107 )
F_103 ( V_107 ) ;
if ( V_18 )
* V_18 = V_91 ;
return V_80 ;
}
static void F_106 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_34 == V_42 ) {
if ( F_47 ( V_2 ) ) {
F_39 ( & V_2 -> V_39 , V_4 ) ;
if ( ! V_2 -> V_37 )
F_18 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
}
}
}
static void F_107 ( struct V_109 * V_33 )
{
unsigned long V_4 ;
struct V_1 * V_2 = F_89 ( V_33 , struct V_1 , V_33 ) ;
F_34 ( L_38 ) ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
while ( V_2 -> V_32 ) {
F_40 ( & V_2 -> V_39 , V_4 ) ;
( void ) F_74 ( V_2 , NULL ) ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
V_2 -> V_32 -- ;
if ( ! V_2 -> V_32 ) {
if ( V_34 == V_35 ||
V_34 == V_36 )
F_36 ( V_2 ) ;
}
}
F_40 ( & V_2 -> V_39 , V_4 ) ;
F_34 ( L_39 ) ;
F_106 ( V_2 ) ;
}
static T_3 F_108 ( T_4 V_113 ,
T_3 V_114 , void * V_18 )
{
unsigned long V_4 ;
struct V_1 * V_2 = V_18 ;
F_39 ( & V_2 -> V_39 , V_4 ) ;
F_18 ( V_2 ) ;
F_40 ( & V_2 -> V_39 , V_4 ) ;
return V_115 ;
}
static T_6
F_109 ( T_3 V_116 , T_7 V_79 ,
T_3 V_117 , T_8 * V_118 ,
void * V_119 , void * V_120 )
{
struct V_1 * V_2 = V_119 ;
int V_80 = 0 , V_90 , V_121 = V_117 / 8 ;
T_1 * V_91 = ( T_1 * ) V_118 ;
if ( ( V_79 > 0xFF ) || ! V_91 || ! V_119 )
return V_122 ;
if ( V_116 != V_123 && V_116 != V_124 )
return V_122 ;
if ( V_63 || V_117 > 8 )
F_65 ( V_2 ) ;
for ( V_90 = 0 ; V_90 < V_121 ; ++ V_90 , ++ V_79 , ++ V_91 )
V_80 = ( V_116 == V_123 ) ?
F_67 ( V_2 , V_79 , V_91 ) :
F_68 ( V_2 , V_79 , * V_91 ) ;
if ( V_63 || V_117 > 8 )
F_66 ( V_2 ) ;
switch ( V_80 ) {
case - V_69 :
return V_122 ;
case - V_75 :
return V_125 ;
case - V_64 :
return V_126 ;
default:
return V_127 ;
}
}
static struct V_1 * F_110 ( void )
{
struct V_1 * V_2 = F_94 ( sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = 1 << V_30 ;
F_111 ( & V_2 -> V_72 ) ;
F_112 ( & V_2 -> V_28 ) ;
F_113 ( & V_2 -> V_104 ) ;
F_114 ( & V_2 -> V_39 ) ;
F_102 ( & V_2 -> V_33 , F_107 ) ;
V_2 -> V_15 = V_16 ;
return V_2 ;
}
static T_6
F_115 ( T_4 V_89 , T_3 V_128 ,
void * V_129 , void * * V_130 )
{
char V_131 [ 5 ] ;
struct V_132 V_133 = { sizeof( V_131 ) , V_131 } ;
struct V_1 * V_2 = V_129 ;
int V_91 = 0 ;
T_6 V_46 ;
V_46 = F_116 ( V_89 , V_134 , & V_133 ) ;
if ( F_117 ( V_46 ) && sscanf ( V_131 , L_40 , & V_91 ) == 1 )
F_93 ( V_2 , V_91 , V_89 , NULL , NULL ) ;
return V_127 ;
}
static T_6
F_118 ( T_4 V_89 , T_3 V_135 , void * V_129 , void * * V_136 )
{
T_6 V_46 ;
unsigned long long V_68 = 0 ;
struct V_1 * V_2 = V_129 ;
V_2 -> V_8 = V_2 -> V_14 = 0 ;
V_46 = F_119 ( V_89 , V_137 ,
V_138 , V_2 ) ;
if ( F_62 ( V_46 ) )
return V_46 ;
V_46 = F_120 ( V_89 , L_41 , NULL , & V_68 ) ;
if ( F_62 ( V_46 ) )
return V_46 ;
V_2 -> V_21 = V_68 ;
V_68 = 0 ;
F_120 ( V_89 , L_42 , NULL , & V_68 ) ;
V_2 -> V_73 = V_68 ;
V_2 -> V_89 = V_89 ;
return V_139 ;
}
static int F_121 ( struct V_1 * V_2 )
{
T_6 V_46 ;
if ( F_2 ( V_140 , & V_2 -> V_4 ) )
return 0 ;
V_46 = F_122 ( NULL , V_2 -> V_21 ,
V_141 ,
& F_108 , V_2 ) ;
if ( F_62 ( V_46 ) )
return - V_75 ;
F_78 ( V_2 , false ) ;
V_46 = F_123 ( V_2 -> V_89 ,
V_142 ,
& F_109 ,
NULL , V_2 ) ;
if ( F_62 ( V_46 ) ) {
if ( V_46 == V_125 ) {
F_124 ( L_43
L_44 ) ;
} else {
F_81 ( V_2 , false ) ;
F_125 ( NULL , V_2 -> V_21 ,
& F_108 ) ;
return - V_75 ;
}
}
F_28 ( V_140 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_126 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_140 , & V_2 -> V_4 ) )
return;
F_81 ( V_2 , false ) ;
if ( F_62 ( F_127 ( V_2 -> V_89 ,
V_142 , & F_109 ) ) )
F_124 ( L_45 ) ;
if ( F_62 ( F_125 ( NULL , V_2 -> V_21 ,
& F_108 ) ) )
F_124 ( L_46 ) ;
F_30 ( V_140 , & V_2 -> V_4 ) ;
}
static int F_128 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = NULL ;
int V_38 ;
strcpy ( F_129 ( V_144 ) , V_145 ) ;
strcpy ( F_130 ( V_144 ) , V_146 ) ;
if ( V_147 &&
( V_147 -> V_89 == V_144 -> V_89 ||
V_147 -> V_89 == V_148 ) ) {
V_2 = V_147 ;
V_147 = NULL ;
} else {
V_2 = F_110 () ;
if ( ! V_2 )
return - V_102 ;
}
if ( F_118 ( V_144 -> V_89 , 0 , V_2 , NULL ) !=
V_139 ) {
F_90 ( V_2 ) ;
return - V_69 ;
}
F_131 ( V_149 , V_2 -> V_89 , 1 ,
F_115 , NULL , V_2 , NULL ) ;
if ( ! V_86 )
V_86 = V_2 ;
V_144 -> V_150 = V_2 ;
V_38 = ! ! F_132 ( V_2 -> V_14 , 1 , L_47 ) ;
F_133 ( ! V_38 , L_48 , V_2 -> V_14 ) ;
V_38 = ! ! F_132 ( V_2 -> V_8 , 1 , L_49 ) ;
F_133 ( ! V_38 , L_50 , V_2 -> V_8 ) ;
F_77 ( L_51 ,
V_2 -> V_21 , V_2 -> V_8 , V_2 -> V_14 ) ;
V_38 = F_121 ( V_2 ) ;
F_134 ( V_2 -> V_89 ) ;
F_30 ( V_30 , & V_2 -> V_4 ) ;
if ( V_95 )
F_73 ( V_2 ) ;
return V_38 ;
}
static int F_135 ( struct V_143 * V_144 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 , * V_68 ;
if ( ! V_144 )
return - V_69 ;
V_2 = F_136 ( V_144 ) ;
F_126 ( V_2 ) ;
F_60 ( & V_2 -> V_72 ) ;
F_99 (handler, tmp, &ec->list, node) {
F_137 ( & V_97 -> V_103 ) ;
F_90 ( V_97 ) ;
}
F_64 ( & V_2 -> V_72 ) ;
F_138 ( V_2 -> V_14 , 1 ) ;
F_138 ( V_2 -> V_8 , 1 ) ;
V_144 -> V_150 = NULL ;
if ( V_2 == V_86 )
V_86 = NULL ;
F_90 ( V_2 ) ;
return 0 ;
}
static T_6
V_138 ( struct V_151 * V_152 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
if ( V_152 -> type != V_153 )
return V_127 ;
if ( V_2 -> V_14 == 0 )
V_2 -> V_14 = V_152 -> V_18 . V_154 . V_155 ;
else if ( V_2 -> V_8 == 0 )
V_2 -> V_8 = V_152 -> V_18 . V_154 . V_155 ;
else
return V_139 ;
return V_127 ;
}
int T_9 F_139 ( void )
{
if ( ! V_147 || F_2 ( V_140 , & V_147 -> V_4 ) )
return 0 ;
if ( ! F_121 ( V_147 ) ) {
V_86 = V_147 ;
return 0 ;
}
return - V_156 ;
}
static int F_140 ( const struct V_157 * V_158 )
{
V_159 = 1 ;
return 0 ;
}
static int F_141 ( const struct V_157 * V_158 )
{
V_160 = 1 ;
return 0 ;
}
static int F_142 ( const struct V_157 * V_158 )
{
F_55 ( L_52 ) ;
V_95 = 1 ;
V_34 = V_35 ;
return 0 ;
}
int T_9 F_143 ( void )
{
T_6 V_46 ;
struct V_1 * V_161 = NULL ;
struct V_162 * V_163 ;
V_147 = F_110 () ;
if ( ! V_147 )
return - V_102 ;
F_144 ( V_164 ) ;
V_46 = F_145 ( V_165 , 1 ,
(struct V_166 * * ) & V_163 ) ;
if ( F_117 ( V_46 ) ) {
F_77 ( L_53 ) ;
V_147 -> V_8 = V_163 -> V_167 . V_79 ;
V_147 -> V_14 = V_163 -> V_18 . V_79 ;
V_147 -> V_21 = V_163 -> V_21 ;
V_147 -> V_89 = V_148 ;
F_146 ( V_148 , V_163 -> V_158 ,
& V_147 -> V_89 ) ;
if ( ! V_160 )
goto V_168;
V_161 = F_147 ( V_147 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_161 )
return - V_102 ;
}
if ( V_159 ) {
F_90 ( V_161 ) ;
return - V_75 ;
}
F_55 ( L_54 ) ;
V_46 = F_148 ( V_169 [ 0 ] . V_158 , F_118 ,
V_147 , NULL ) ;
if ( F_62 ( V_46 ) || ! V_147 -> V_89 )
goto error;
if ( V_161 ) {
if ( V_161 -> V_8 != V_147 -> V_8 ||
V_161 -> V_14 != V_147 -> V_14 ||
V_161 -> V_21 != V_147 -> V_21 ||
V_161 -> V_89 != V_147 -> V_89 )
F_77 ( L_55
L_56
L_57
L_58 ) ;
F_90 ( V_161 ) ;
V_161 = NULL ;
} else {
if ( ! F_149 ( L_59 ) ||
! F_150 ( V_147 -> V_89 , L_60 ) )
return - V_75 ;
}
V_168:
if ( ! F_121 ( V_147 ) ) {
V_86 = V_147 ;
return 0 ;
}
error:
F_90 ( V_147 ) ;
F_90 ( V_161 ) ;
V_147 = NULL ;
return - V_75 ;
}
static int F_151 ( const char * V_84 , struct V_170 * V_171 )
{
int V_80 = 0 ;
if ( ! strncmp ( V_84 , L_61 , sizeof( L_61 ) - 1 ) ) {
V_34 = V_35 ;
F_77 ( L_62 ) ;
} else if ( ! strncmp ( V_84 , L_63 , sizeof( L_63 ) - 1 ) ) {
V_34 = V_36 ;
F_77 ( L_64 ) ;
} else if ( ! strncmp ( V_84 , L_65 , sizeof( L_65 ) - 1 ) ) {
V_34 = V_42 ;
F_77 ( L_66 ) ;
} else
V_80 = - V_69 ;
return V_80 ;
}
static int F_152 ( char * V_133 , struct V_170 * V_171 )
{
switch ( V_34 ) {
case V_35 :
return sprintf ( V_133 , L_61 ) ;
case V_36 :
return sprintf ( V_133 , L_63 ) ;
case V_42 :
return sprintf ( V_133 , L_65 ) ;
default:
return sprintf ( V_133 , L_67 ) ;
}
return 0 ;
}
int T_9 F_153 ( void )
{
int V_80 = 0 ;
V_80 = F_154 ( & V_172 ) ;
if ( V_80 < 0 )
return - V_75 ;
return V_80 ;
}
