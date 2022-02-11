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
enum V_18 V_19 , * V_20 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_21 ) )
return NULL ;
V_3 -> V_22 = V_23 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_24 ||
! V_4 -> V_24 -> V_25 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_24 -> V_25 ( V_3 , V_23 ) ;
if ( V_19 == V_26 ) * V_20 = V_19 ;
if ( * V_20 == V_27 ) * V_20 = V_19 ;
V_9 -> V_28 = true ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_20 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_18 V_19 , * V_20 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_21 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
if ( ! V_4 -> V_24 ||
! V_4 -> V_24 -> V_29 ||
( V_9 -> V_13 & V_30 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_24 -> V_29 ( V_3 ) ;
if ( V_19 == V_26 ) * V_20 = V_19 ;
if ( * V_20 == V_27 ) * V_20 = V_19 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_21 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_18 V_19 , * V_20 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_21 ) )
return NULL ;
V_3 -> V_22 = V_31 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_24 ||
! V_4 -> V_24 -> V_32 ||
( V_9 -> V_13 & V_30 ) ||
( ! V_9 -> V_28 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_24 -> V_32 ( V_3 ) ;
if ( ( * V_20 == V_27 ) ||
( * V_20 == V_33 ) ) * V_20 = V_19 ;
if ( * V_20 == V_34 &&
V_19 == V_26 ) * V_20 = V_19 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_22 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = V_16 ;
struct V_1 * V_2 ;
if ( ! V_9 )
return NULL ;
V_2 = F_16 ( V_9 ) ;
if ( ! V_2 )
return NULL ;
F_23 ( V_2 ) ;
return NULL ;
}
static void * F_24 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
bool V_35 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_21 ) )
return NULL ;
V_3 -> V_22 = V_31 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
V_35 = V_9 -> V_28 ;
V_9 -> V_28 = false ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_24 ||
! V_4 -> V_24 -> V_36 ||
( V_9 -> V_13 & V_30 ) || ! V_35 ) {
V_9 -> V_13 &= ~ V_30 ;
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_24 -> V_36 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_25 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) || F_19 ( V_9 -> V_21 ) )
return NULL ;
V_3 -> V_22 = V_37 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_24 ||
! V_4 -> V_24 -> V_25 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_24 -> V_25 ( V_3 , V_37 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_26 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_38 * V_39 = F_27 ( V_9 ) ;
if ( ! ( V_9 -> V_40 ) ) {
F_28 ( L_2 ,
V_41 , V_9 -> V_42 -> V_43 , V_39 -> V_44 ,
F_29 ( V_39 -> V_45 ) , F_30 ( V_39 -> V_45 ) ) ;
return NULL ;
}
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_24 )
return NULL ;
}
#ifdef F_31
F_32 ( V_9 -> V_40 , V_39 -> V_46 , 0 ) ;
#endif
return NULL ;
}
static void * F_33 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_47 * V_48 = (struct V_47 * ) V_17 ;
int * V_49 = V_48 ? & V_48 -> V_49 : NULL ;
if ( ! V_3 || ( V_3 -> V_50 == V_51 ) )
return NULL ;
if ( F_14 ( V_9 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_49 &&
F_19 ( V_9 -> V_21 ) )
return NULL ;
if ( V_49 &&
V_4 -> V_24 &&
V_4 -> V_24 -> V_25 &&
V_4 -> V_24 -> V_32 )
return NULL ;
}
F_34 ( L_3 ,
F_35 ( V_3 ) ) ;
V_9 -> V_52 = V_3 -> V_52 ;
V_9 -> V_13 |= V_53 ;
if ( V_49 )
( * V_49 ) ++ ;
if ( V_9 -> V_40 ) {
#ifdef F_31
struct V_38 * V_39 = F_27 ( V_9 ) ;
F_36 ( V_9 -> V_40 , V_39 -> V_46 , 0 ) ;
V_9 -> V_2 = NULL ;
V_39 -> V_54 = V_55 ;
#endif
if ( V_48 )
F_37 ( & V_9 -> V_56 , & V_48 -> V_57 ) ;
} else {
F_38 () ;
F_39 ( V_3 ) ;
F_40 () ;
}
return NULL ;
}
static void * F_41 ( void * V_16 , void * V_17 )
{
struct V_58 * V_21 = (struct V_58 * ) V_16 ;
struct V_8 * V_9 , * V_59 ;
F_42 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_53 ) )
continue;
V_9 -> V_13 &= ~ ( V_53 | V_14 ) ;
F_43 ( V_9 ) ;
}
return NULL ;
}
static void * F_44 ( void * V_16 , void * V_60 )
{
struct V_58 * V_21 = (struct V_58 * ) V_16 ;
bool * V_61 = V_60 ;
int V_62 , V_19 = 1 ;
for ( V_62 = 0 ; V_19 && V_62 < 3 ; V_62 ++ )
V_19 = F_45 ( V_21 , V_61 ) ;
if ( V_19 ) {
F_28 ( L_4 ,
V_41 , V_19 , V_21 -> V_42 -> V_43 , V_21 -> V_63 ) ;
return ( void * ) V_21 ;
}
return NULL ;
}
static int F_46 ( struct V_58 * V_21 ,
bool V_61 )
{
void * V_19 ;
V_19 = F_47 ( V_21 , F_44 , & V_61 ) ;
if ( ! V_19 )
F_48 ( V_21 , V_64 ) ;
return V_19 ? - V_65 : 0 ;
}
int F_49 ( struct V_58 * V_21 )
{
int V_66 , V_67 ;
if ( V_21 -> V_68 & V_69 )
return 0 ;
F_50 ( V_21 , V_69 ) ;
F_51 ( V_21 , F_15 , NULL ) ;
F_51 ( V_21 , F_18 , & V_66 ) ;
V_67 = F_52 ( V_21 ) ;
if ( V_67 ) {
F_48 ( V_21 , V_69 ) ;
return V_67 ;
}
V_67 = F_46 ( V_21 , true ) ;
if ( V_67 ) {
F_48 ( V_21 , V_69 ) ;
return V_67 ;
}
F_51 ( V_21 , F_21 , & V_66 ) ;
F_51 ( V_21 , F_22 , NULL ) ;
F_51 ( V_21 , F_24 , NULL ) ;
F_48 ( V_21 , V_69 ) ;
return 0 ;
}
static int F_53 ( struct V_58 * V_21 , struct V_70 * V_52 ,
struct V_47 * V_48 )
{
struct V_70 * V_71 = F_54 ( V_21 ) ;
struct V_72 V_73 ;
int V_74 , V_19 ;
struct V_8 * V_9 ;
V_74 = V_21 -> V_75 ;
V_73 = V_21 -> V_73 ;
F_50 ( V_21 , V_76 ) ;
if ( V_52 ) {
if ( V_21 -> type & V_77 ) {
F_51 ( V_21 , F_33 , NULL ) ;
} else {
F_48 ( V_21 , V_78 ) ;
F_38 () ;
F_55 ( V_52 ) ;
F_40 () ;
}
} else if ( V_71 ) {
F_51 ( V_21 , F_33 , & V_48 ) ;
}
V_19 = F_52 ( V_21 ) ;
if ( V_19 )
return V_19 ;
F_38 () ;
V_79 -> V_80 ( V_21 ) ;
F_56 ( V_21 ) ;
V_19 = F_46 ( V_21 , false ) ;
if ( V_19 )
return V_19 ;
if ( V_52 ) {
F_57 ( L_5 ) ;
F_58 ( 5 ) ;
V_9 = F_59 ( & V_21 -> V_81 , struct V_8 , V_82 ) ;
F_47 ( V_21 , F_41 , NULL ) ;
if ( V_21 -> type & V_77 )
F_26 ( V_9 , NULL ) ;
else
F_60 ( V_52 ) ;
} else if ( V_71 && V_48 -> V_49 ) {
F_57 ( L_6 ) ;
F_58 ( 5 ) ;
V_9 = F_59 ( & V_21 -> V_81 , struct V_8 , V_82 ) ;
F_47 ( V_21 , F_41 , NULL ) ;
if ( V_21 -> type & V_77 )
F_26 ( V_9 , NULL ) ;
else
F_60 ( V_71 ) ;
}
F_48 ( V_21 , V_76 ) ;
V_21 -> V_73 = V_73 ;
V_21 -> V_75 = V_74 ;
F_40 () ;
return 0 ;
}
static void F_61 ( struct V_58 * V_21 )
{
struct V_70 * V_71 ;
struct V_8 * V_9 , * V_59 ;
int V_19 = 0 ;
enum V_18 V_66 = V_27 ;
struct V_47 V_48 = { F_62 ( V_48 . V_57 ) , 0 } ;
V_71 = F_54 ( V_21 ) ;
if ( ! V_71 ) {
F_63 ( L_7 ,
V_41 , V_21 -> V_42 -> V_43 , V_21 -> V_63 ) ;
return;
}
F_64 ( V_21 ) ;
V_21 -> V_75 ++ ;
if ( V_21 -> V_75 > V_83 )
goto V_84;
F_28 ( L_8 ,
V_21 -> V_75 ) ;
F_57 ( L_9 ) ;
F_51 ( V_21 , F_18 , & V_66 ) ;
if ( ( V_21 -> type & V_85 ) &&
V_66 != V_27 &&
V_66 != V_26 )
V_66 = V_26 ;
V_19 = V_79 -> V_86 ( V_21 , V_87 * 1000 ) ;
if ( V_19 < 0 || V_19 == V_88 ) {
F_28 ( L_10 ) ;
goto V_89;
}
F_57 ( L_11 ) ;
F_65 ( V_21 , V_90 ) ;
if ( V_66 == V_27 ) {
F_57 ( L_12 ) ;
V_19 = F_53 ( V_21 , V_71 , NULL ) ;
if ( V_19 ) {
F_28 ( L_13 ,
V_41 , V_19 ) ;
goto V_89;
}
}
if ( V_66 == V_91 ) {
F_57 ( L_14 ) ;
V_19 = F_66 ( V_21 , V_92 ) ;
if ( V_19 < 0 )
goto V_89;
if ( V_19 ) {
V_66 = V_26 ;
} else {
F_57 ( L_15 ) ;
F_51 ( V_21 , F_20 , & V_66 ) ;
}
}
if ( V_66 == V_91 ) {
F_57 ( L_16 ) ;
V_19 = F_66 ( V_21 , V_93 ) ;
if ( V_19 < 0 )
goto V_89;
if ( V_19 ) {
V_66 = V_26 ;
} else {
F_48 ( V_21 , V_64 ) ;
V_66 = V_33 ;
}
}
if ( V_66 == V_34 ) {
F_28 ( L_17 ) ;
goto V_89;
}
if ( V_66 == V_26 ) {
F_57 ( L_18 ) ;
V_19 = F_53 ( V_21 , NULL , & V_48 ) ;
if ( V_19 ) {
F_28 ( L_19 ,
V_41 , V_19 ) ;
goto V_89;
}
F_57 ( L_20
L_21 ) ;
V_66 = V_27 ;
F_51 ( V_21 , F_21 , & V_66 ) ;
}
if ( ( V_66 != V_33 ) &&
( V_66 != V_27 ) ) {
F_28 ( L_22 ) ;
goto V_89;
}
F_67 (edev, tmp, &rmv_data.edev_list, rmv_list) {
F_26 ( V_9 , NULL ) ;
F_68 ( & V_9 -> V_56 ) ;
}
F_57 ( L_23 ) ;
F_51 ( V_21 , F_24 , NULL ) ;
return;
V_84:
F_63 ( L_24
L_25
L_26 ,
V_21 -> V_42 -> V_43 , V_21 -> V_63 ,
V_21 -> V_75 ) ;
goto V_94;
V_89:
F_63 ( L_27
L_28 ,
V_21 -> V_42 -> V_43 , V_21 -> V_63 ) ;
V_94:
F_65 ( V_21 , V_95 ) ;
F_51 ( V_21 , F_25 , NULL ) ;
F_50 ( V_21 , V_96 ) ;
if ( V_71 ) {
if ( V_21 -> type & V_77 ) {
F_51 ( V_21 , F_33 , NULL ) ;
F_69 ( V_21 , V_15 ) ;
} else {
F_48 ( V_21 , V_78 ) ;
F_69 ( V_21 , V_15 ) ;
F_38 () ;
F_55 ( V_71 ) ;
F_40 () ;
}
}
}
static void F_70 ( void )
{
struct V_58 * V_21 , * V_97 ;
struct V_70 * V_52 ;
struct V_98 * V_99 ;
unsigned long V_100 ;
int V_19 ;
do {
V_19 = V_79 -> V_101 ( & V_21 ) ;
switch ( V_19 ) {
case V_102 :
F_71 ( & V_100 ) ;
F_72 ( NULL , true ) ;
F_73 (hose, &hose_list, list_node) {
V_97 = F_74 ( V_99 ) ;
if ( ! V_97 ) continue;
F_50 ( V_97 , V_64 ) ;
}
F_75 ( V_100 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
F_71 ( & V_100 ) ;
F_72 ( V_21 , true ) ;
if ( V_19 == V_105 )
F_50 ( V_21 , V_64 ) ;
else
F_50 ( V_21 ,
V_64 | V_69 ) ;
F_75 ( V_100 ) ;
break;
case V_106 :
return;
default:
F_28 ( L_29 ,
V_41 , V_19 ) ;
return;
}
if ( V_19 == V_103 ||
V_19 == V_104 ) {
F_61 ( V_21 ) ;
F_48 ( V_21 , V_69 ) ;
} else {
F_38 () ;
F_73 (hose, &hose_list, list_node) {
V_97 = F_74 ( V_99 ) ;
if ( ! V_97 ||
! ( V_97 -> V_68 & V_64 ) ||
( V_97 -> V_68 & V_69 ) )
continue;
F_48 ( V_21 , V_78 ) ;
V_52 = F_54 ( V_97 ) ;
F_51 ( V_21 ,
F_25 , NULL ) ;
F_55 ( V_52 ) ;
}
F_40 () ;
}
if ( V_19 == V_102 )
break;
} while ( V_19 != V_106 );
}
void F_76 ( struct V_58 * V_21 )
{
if ( V_21 )
F_61 ( V_21 ) ;
else
F_70 () ;
}
