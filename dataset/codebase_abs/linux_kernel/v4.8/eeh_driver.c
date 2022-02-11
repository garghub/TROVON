static inline const char * F_1 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_3 . V_4 )
return V_2 -> V_3 . V_4 -> V_5 ;
return L_1 ;
}
static inline struct V_6 * F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_4 )
return NULL ;
if ( ! F_3 ( V_2 -> V_4 -> V_4 . V_7 ) )
return NULL ;
return V_2 -> V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_4 )
return;
F_5 ( V_2 -> V_4 -> V_4 . V_7 ) ;
}
static void F_6 ( struct V_1 * V_3 )
{
struct V_8 * V_9 = F_7 ( V_3 ) ;
if ( V_3 -> V_10 || V_3 -> V_11 )
return;
if ( ! F_8 ( V_3 -> V_12 ) )
return;
V_9 -> V_13 |= V_14 ;
F_9 ( V_3 -> V_12 ) ;
}
static void F_10 ( struct V_1 * V_3 )
{
struct V_8 * V_9 = F_7 ( V_3 ) ;
if ( ( V_9 -> V_13 ) & V_14 ) {
V_9 -> V_13 &= ~ V_14 ;
if ( F_11 ( F_12 ( V_3 -> V_12 ) ) )
F_13 ( V_3 -> V_12 ) ;
}
}
static bool F_14 ( struct V_8 * V_9 )
{
if ( ! V_9 || ( V_9 -> V_13 & V_15 ) )
return true ;
return false ;
}
static void * F_15 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = V_16 ;
struct V_1 * V_2 ;
if ( ! V_9 )
return NULL ;
if ( V_9 -> V_18 && ( V_9 -> V_18 -> V_19 & V_20 ) )
return NULL ;
V_2 = F_16 ( V_9 ) ;
if ( ! V_2 )
return NULL ;
F_17 ( V_2 ) ;
return NULL ;
}
static void * F_18 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_21 V_22 , * V_23 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_18 ) )
return NULL ;
V_3 -> V_24 = V_25 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_26 ||
! V_4 -> V_26 -> V_27 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_22 = V_4 -> V_26 -> V_27 ( V_3 , V_25 ) ;
if ( V_22 == V_28 ) * V_23 = V_22 ;
if ( * V_23 == V_29 ) * V_23 = V_22 ;
V_9 -> V_30 = true ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_20 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_21 V_22 , * V_23 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_18 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
if ( ! V_4 -> V_26 ||
! V_4 -> V_26 -> V_31 ||
( V_9 -> V_13 & V_32 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_22 = V_4 -> V_26 -> V_31 ( V_3 ) ;
if ( V_22 == V_28 ) * V_23 = V_22 ;
if ( * V_23 == V_29 ) * V_23 = V_22 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_21 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_21 V_22 , * V_23 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_18 ) )
return NULL ;
V_3 -> V_24 = V_33 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_26 ||
! V_4 -> V_26 -> V_34 ||
( V_9 -> V_13 & V_32 ) ||
( ! V_9 -> V_30 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_22 = V_4 -> V_26 -> V_34 ( V_3 ) ;
if ( ( * V_23 == V_29 ) ||
( * V_23 == V_35 ) ) * V_23 = V_22 ;
if ( * V_23 == V_36 &&
V_22 == V_28 ) * V_23 = V_22 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_22 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = V_16 ;
struct V_1 * V_2 ;
if ( ! V_9 )
return NULL ;
if ( V_9 -> V_18 && ( V_9 -> V_18 -> V_19 & V_20 ) ) {
if ( F_23 ( & V_9 -> V_37 , & V_9 -> V_18 -> V_38 ) )
F_24 ( V_9 -> V_18 ) ;
return NULL ;
}
V_2 = F_16 ( V_9 ) ;
if ( ! V_2 )
return NULL ;
F_25 ( V_2 ) ;
return NULL ;
}
static void * F_26 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
bool V_39 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_18 ) )
return NULL ;
V_3 -> V_24 = V_33 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
V_39 = V_9 -> V_30 ;
V_9 -> V_30 = false ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_26 ||
! V_4 -> V_26 -> V_40 ||
( V_9 -> V_13 & V_32 ) || ! V_39 ) {
V_9 -> V_13 &= ~ V_32 ;
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_26 -> V_40 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_27 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_18 ) )
return NULL ;
V_3 -> V_24 = V_41 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_26 ||
! V_4 -> V_26 -> V_27 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_26 -> V_27 ( V_3 , V_41 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_28 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_42 * V_43 = F_29 ( V_9 ) ;
if ( ! ( V_9 -> V_44 ) ) {
F_30 ( L_2 ,
V_45 , V_9 -> V_46 -> V_47 , V_43 -> V_48 ,
F_31 ( V_43 -> V_49 ) , F_32 ( V_43 -> V_49 ) ) ;
return NULL ;
}
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_26 )
return NULL ;
}
#ifdef F_33
F_34 ( V_9 -> V_44 , V_43 -> V_50 , 0 ) ;
#endif
return NULL ;
}
static void * F_35 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_51 * V_52 = (struct V_51 * ) V_17 ;
int * V_53 = V_52 ? & V_52 -> V_53 : NULL ;
if ( ! V_3 || ( V_3 -> V_54 == V_55 ) )
return NULL ;
if ( F_14 ( V_9 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_53 &&
F_19 ( V_9 -> V_18 ) )
return NULL ;
if ( V_53 &&
V_4 -> V_26 &&
V_4 -> V_26 -> V_27 &&
V_4 -> V_26 -> V_34 )
return NULL ;
}
F_36 ( L_3 ,
F_37 ( V_3 ) ) ;
V_9 -> V_56 = V_3 -> V_56 ;
V_9 -> V_13 |= V_57 ;
if ( V_53 )
( * V_53 ) ++ ;
if ( V_9 -> V_44 ) {
#ifdef F_33
struct V_42 * V_43 = F_29 ( V_9 ) ;
F_38 ( V_9 -> V_44 , V_43 -> V_50 , 0 ) ;
V_9 -> V_2 = NULL ;
V_43 -> V_58 = V_59 ;
#endif
if ( V_52 )
F_39 ( & V_9 -> V_60 , & V_52 -> V_61 ) ;
} else {
F_40 () ;
F_41 ( V_3 ) ;
F_42 () ;
}
return NULL ;
}
static void * F_43 ( void * V_16 , void * V_17 )
{
struct V_62 * V_18 = (struct V_62 * ) V_16 ;
struct V_8 * V_9 , * V_63 ;
F_44 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_57 ) )
continue;
V_9 -> V_13 &= ~ ( V_57 | V_14 ) ;
F_45 ( V_9 ) ;
}
return NULL ;
}
static void * F_46 ( void * V_16 , void * V_64 )
{
struct V_62 * V_18 = (struct V_62 * ) V_16 ;
bool * V_65 = V_64 ;
int V_66 , V_22 = 1 ;
for ( V_66 = 0 ; V_22 && V_66 < 3 ; V_66 ++ )
V_22 = F_47 ( V_18 , V_65 ) ;
if ( V_22 ) {
F_30 ( L_4 ,
V_45 , V_22 , V_18 -> V_46 -> V_47 , V_18 -> V_67 ) ;
return ( void * ) V_18 ;
}
return NULL ;
}
static int F_48 ( struct V_62 * V_18 ,
bool V_65 )
{
void * V_22 ;
V_22 = F_49 ( V_18 , F_46 , & V_65 ) ;
if ( ! V_22 )
F_50 ( V_18 , V_68 ) ;
return V_22 ? - V_69 : 0 ;
}
int F_51 ( struct V_62 * V_18 )
{
int V_70 ;
if ( V_18 -> V_19 & V_71 )
return 0 ;
F_52 ( V_18 , V_71 ) ;
F_53 ( V_18 , F_15 , NULL ) ;
V_70 = F_54 ( V_18 ) ;
if ( V_70 ) {
F_50 ( V_18 , V_71 ) ;
return V_70 ;
}
V_70 = F_48 ( V_18 , true ) ;
if ( V_70 ) {
F_50 ( V_18 , V_71 ) ;
return V_70 ;
}
F_53 ( V_18 , F_22 , NULL ) ;
F_50 ( V_18 , V_71 ) ;
return 0 ;
}
static int F_55 ( struct V_62 * V_18 , struct V_72 * V_56 ,
struct V_51 * V_52 )
{
struct V_72 * V_73 = F_56 ( V_18 ) ;
struct V_74 V_75 ;
int V_76 , V_22 ;
struct V_8 * V_9 ;
V_76 = V_18 -> V_77 ;
V_75 = V_18 -> V_75 ;
F_52 ( V_18 , V_78 ) ;
if ( V_56 ) {
if ( V_18 -> type & V_79 ) {
F_53 ( V_18 , F_35 , NULL ) ;
} else {
F_40 () ;
F_57 ( V_56 ) ;
F_42 () ;
}
} else if ( V_73 ) {
F_53 ( V_18 , F_35 , V_52 ) ;
}
V_22 = F_54 ( V_18 ) ;
if ( V_22 )
return V_22 ;
F_40 () ;
V_80 -> V_81 ( V_18 ) ;
F_24 ( V_18 ) ;
V_22 = F_48 ( V_18 , false ) ;
if ( V_22 )
return V_22 ;
if ( V_56 ) {
F_58 ( L_5 ) ;
F_59 ( 5 ) ;
V_9 = F_60 ( & V_18 -> V_38 , struct V_8 , V_37 ) ;
F_49 ( V_18 , F_43 , NULL ) ;
if ( V_18 -> type & V_79 ) {
F_28 ( V_9 , NULL ) ;
} else {
F_50 ( V_18 , V_82 ) ;
F_61 ( V_56 ) ;
}
} else if ( V_73 && V_52 -> V_53 ) {
F_58 ( L_6 ) ;
F_59 ( 5 ) ;
V_9 = F_60 ( & V_18 -> V_38 , struct V_8 , V_37 ) ;
F_49 ( V_18 , F_43 , NULL ) ;
if ( V_18 -> type & V_79 )
F_28 ( V_9 , NULL ) ;
else
F_61 ( V_73 ) ;
}
F_50 ( V_18 , V_78 ) ;
V_18 -> V_75 = V_75 ;
V_18 -> V_77 = V_76 ;
F_42 () ;
return 0 ;
}
static void F_62 ( struct V_62 * V_18 )
{
struct V_72 * V_73 ;
struct V_8 * V_9 , * V_63 ;
int V_22 = 0 ;
enum V_21 V_83 = V_29 ;
struct V_51 V_52 = { F_63 ( V_52 . V_61 ) , 0 } ;
V_73 = F_56 ( V_18 ) ;
if ( ! V_73 ) {
F_64 ( L_7 ,
V_45 , V_18 -> V_46 -> V_47 , V_18 -> V_67 ) ;
return;
}
F_65 ( V_18 ) ;
V_18 -> V_77 ++ ;
if ( V_18 -> V_77 > V_84 )
goto V_85;
F_30 ( L_8 ,
V_18 -> V_77 ) ;
F_58 ( L_9 ) ;
F_53 ( V_18 , F_18 , & V_83 ) ;
if ( ( V_18 -> type & V_86 ) &&
V_83 != V_29 &&
V_83 != V_28 )
V_83 = V_28 ;
V_22 = V_80 -> V_87 ( V_18 , V_88 * 1000 ) ;
if ( V_22 < 0 || V_22 == V_89 ) {
F_30 ( L_10 ) ;
goto V_90;
}
F_58 ( L_11 ) ;
F_66 ( V_18 , V_91 ) ;
if ( V_83 == V_29 ) {
F_58 ( L_12 ) ;
V_22 = F_55 ( V_18 , V_73 , NULL ) ;
if ( V_22 ) {
F_30 ( L_13 ,
V_45 , V_22 ) ;
goto V_90;
}
}
if ( V_83 == V_92 ) {
F_58 ( L_14 ) ;
V_22 = F_67 ( V_18 , V_93 ) ;
if ( V_22 < 0 )
goto V_90;
if ( V_22 ) {
V_83 = V_28 ;
} else {
F_58 ( L_15 ) ;
F_53 ( V_18 , F_20 , & V_83 ) ;
}
}
if ( V_83 == V_92 ) {
F_58 ( L_16 ) ;
V_22 = F_67 ( V_18 , V_94 ) ;
if ( V_22 < 0 )
goto V_90;
if ( V_22 ) {
V_83 = V_28 ;
} else {
F_50 ( V_18 , V_68 ) ;
V_83 = V_35 ;
}
}
if ( V_83 == V_36 ) {
F_30 ( L_17 ) ;
goto V_90;
}
if ( V_83 == V_28 ) {
F_58 ( L_18 ) ;
V_22 = F_55 ( V_18 , NULL , & V_52 ) ;
if ( V_22 ) {
F_30 ( L_19 ,
V_45 , V_22 ) ;
goto V_90;
}
F_58 ( L_20
L_21 ) ;
V_83 = V_29 ;
F_53 ( V_18 , F_21 , & V_83 ) ;
}
if ( ( V_83 != V_35 ) &&
( V_83 != V_29 ) ) {
F_30 ( L_22 ) ;
goto V_90;
}
F_68 (edev, tmp, &rmv_data.edev_list, rmv_list) {
F_28 ( V_9 , NULL ) ;
F_69 ( & V_9 -> V_60 ) ;
}
F_58 ( L_23 ) ;
F_53 ( V_18 , F_26 , NULL ) ;
return;
V_85:
F_64 ( L_24
L_25
L_26 ,
V_18 -> V_46 -> V_47 , V_18 -> V_67 ,
V_18 -> V_77 ) ;
goto V_95;
V_90:
F_64 ( L_27
L_28 ,
V_18 -> V_46 -> V_47 , V_18 -> V_67 ) ;
V_95:
F_66 ( V_18 , V_96 ) ;
F_53 ( V_18 , F_27 , NULL ) ;
F_52 ( V_18 , V_97 ) ;
if ( V_73 ) {
if ( V_18 -> type & V_79 ) {
F_53 ( V_18 , F_35 , NULL ) ;
F_70 ( V_18 , V_15 ) ;
} else {
F_50 ( V_18 , V_82 ) ;
F_70 ( V_18 , V_15 ) ;
F_40 () ;
F_57 ( V_73 ) ;
F_42 () ;
}
}
}
static void F_71 ( void )
{
struct V_62 * V_18 , * V_98 ;
struct V_72 * V_56 ;
struct V_99 * V_100 ;
unsigned long V_101 ;
int V_22 ;
do {
V_22 = V_80 -> V_102 ( & V_18 ) ;
switch ( V_22 ) {
case V_103 :
F_72 ( & V_101 ) ;
F_73 ( NULL , true ) ;
F_74 (hose, &hose_list, list_node) {
V_98 = F_75 ( V_100 ) ;
if ( ! V_98 ) continue;
F_52 ( V_98 , V_68 ) ;
}
F_76 ( V_101 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
F_72 ( & V_101 ) ;
F_73 ( V_18 , true ) ;
if ( V_22 == V_106 )
F_52 ( V_18 , V_68 ) ;
else
F_52 ( V_18 ,
V_68 | V_71 ) ;
F_76 ( V_101 ) ;
break;
case V_107 :
return;
default:
F_30 ( L_29 ,
V_45 , V_22 ) ;
return;
}
if ( V_22 == V_104 ||
V_22 == V_105 ) {
F_62 ( V_18 ) ;
F_50 ( V_18 , V_71 ) ;
} else {
F_40 () ;
F_74 (hose, &hose_list, list_node) {
V_98 = F_75 ( V_100 ) ;
if ( ! V_98 ||
! ( V_98 -> V_19 & V_68 ) ||
( V_98 -> V_19 & V_71 ) )
continue;
F_50 ( V_18 , V_82 ) ;
V_56 = F_56 ( V_98 ) ;
F_53 ( V_18 ,
F_27 , NULL ) ;
F_57 ( V_56 ) ;
}
F_42 () ;
}
if ( V_22 == V_103 )
break;
} while ( V_22 != V_107 );
}
void F_77 ( struct V_62 * V_18 )
{
if ( V_18 )
F_62 ( V_18 ) ;
else
F_71 () ;
}
