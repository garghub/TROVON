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
if ( ! V_3 || F_14 ( V_9 ) )
return NULL ;
V_3 -> V_21 = V_22 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_23 ||
! V_4 -> V_23 -> V_24 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_23 -> V_24 ( V_3 , V_22 ) ;
if ( V_19 == V_25 ) * V_20 = V_19 ;
if ( * V_20 == V_26 ) * V_20 = V_19 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_19 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_18 V_19 , * V_20 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
if ( ! V_4 -> V_23 ||
! V_4 -> V_23 -> V_27 ||
( V_9 -> V_13 & V_28 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_23 -> V_27 ( V_3 ) ;
if ( V_19 == V_25 ) * V_20 = V_19 ;
if ( * V_20 == V_26 ) * V_20 = V_19 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_20 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
enum V_18 V_19 , * V_20 = V_17 ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) )
return NULL ;
V_3 -> V_21 = V_29 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_23 ||
! V_4 -> V_23 -> V_30 ||
( V_9 -> V_13 & V_28 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_19 = V_4 -> V_23 -> V_30 ( V_3 ) ;
if ( ( * V_20 == V_26 ) ||
( * V_20 == V_31 ) ) * V_20 = V_19 ;
if ( * V_20 == V_32 &&
V_19 == V_25 ) * V_20 = V_19 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_21 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = V_16 ;
struct V_1 * V_2 ;
if ( ! V_9 )
return NULL ;
V_2 = F_16 ( V_9 ) ;
if ( ! V_2 )
return NULL ;
F_22 ( V_2 ) ;
return NULL ;
}
static void * F_23 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) )
return NULL ;
V_3 -> V_21 = V_29 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_23 ||
! V_4 -> V_23 -> V_33 ||
( V_9 -> V_13 & V_28 ) ) {
V_9 -> V_13 &= ~ V_28 ;
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_23 -> V_33 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_24 ( void * V_16 , void * V_17 )
{
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 || F_14 ( V_9 ) )
return NULL ;
V_3 -> V_21 = V_34 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_23 ||
! V_4 -> V_23 -> V_24 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_23 -> V_24 ( V_3 , V_34 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_25 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
int * V_35 = ( int * ) V_17 ;
if ( ! V_3 || ( V_3 -> V_36 == V_37 ) )
return NULL ;
if ( F_14 ( V_9 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_23 &&
V_4 -> V_23 -> V_24 &&
V_4 -> V_23 -> V_30 )
return NULL ;
}
F_26 ( L_2 ,
F_27 ( V_3 ) ) ;
V_9 -> V_38 = V_3 -> V_38 ;
V_9 -> V_13 |= V_39 ;
( * V_35 ) ++ ;
F_28 () ;
F_29 ( V_3 ) ;
F_30 () ;
return NULL ;
}
static void * F_31 ( void * V_16 , void * V_17 )
{
struct V_40 * V_41 = (struct V_40 * ) V_16 ;
struct V_8 * V_9 , * V_42 ;
F_32 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_39 ) )
continue;
V_9 -> V_13 &= ~ ( V_39 | V_14 ) ;
F_33 ( V_9 ) ;
}
return NULL ;
}
static void * F_34 ( void * V_16 , void * V_43 )
{
struct V_40 * V_41 = (struct V_40 * ) V_16 ;
bool * V_44 = V_43 ;
int V_45 , V_19 = 1 ;
for ( V_45 = 0 ; V_19 && V_45 < 3 ; V_45 ++ )
V_19 = F_35 ( V_41 , V_44 ) ;
if ( V_19 ) {
F_36 ( L_3 ,
V_46 , V_19 , V_41 -> V_47 -> V_48 , V_41 -> V_49 ) ;
return ( void * ) V_41 ;
}
return NULL ;
}
static int F_37 ( struct V_40 * V_41 ,
bool V_44 )
{
void * V_19 ;
V_19 = F_38 ( V_41 , F_34 , & V_44 ) ;
if ( ! V_19 )
F_39 ( V_41 , V_50 ) ;
return V_19 ? - V_51 : 0 ;
}
int F_40 ( struct V_40 * V_41 )
{
int V_52 , V_53 ;
if ( V_41 -> V_54 & V_55 )
return 0 ;
F_41 ( V_41 , V_55 ) ;
F_42 ( V_41 , F_15 , NULL ) ;
F_42 ( V_41 , F_18 , & V_52 ) ;
V_53 = F_43 ( V_41 ) ;
if ( V_53 ) {
F_39 ( V_41 , V_55 ) ;
return V_53 ;
}
V_53 = F_37 ( V_41 , true ) ;
if ( V_53 ) {
F_39 ( V_41 , V_55 ) ;
return V_53 ;
}
F_42 ( V_41 , F_20 , & V_52 ) ;
F_42 ( V_41 , F_21 , NULL ) ;
F_42 ( V_41 , F_23 , NULL ) ;
F_39 ( V_41 , V_55 ) ;
return 0 ;
}
static int F_44 ( struct V_40 * V_41 , struct V_56 * V_38 )
{
struct V_56 * V_57 = F_45 ( V_41 ) ;
struct V_58 V_59 ;
int V_60 , V_19 , V_35 = 0 ;
V_60 = V_41 -> V_61 ;
V_59 = V_41 -> V_59 ;
F_41 ( V_41 , V_62 ) ;
if ( V_38 ) {
F_39 ( V_41 , V_63 ) ;
F_28 () ;
F_46 ( V_38 ) ;
F_30 () ;
} else if ( V_57 ) {
F_42 ( V_41 , F_25 , & V_35 ) ;
}
V_19 = F_43 ( V_41 ) ;
if ( V_19 )
return V_19 ;
F_28 () ;
V_64 -> V_65 ( V_41 ) ;
F_47 ( V_41 ) ;
V_19 = F_37 ( V_41 , false ) ;
if ( V_19 )
return V_19 ;
if ( V_38 ) {
F_48 ( L_4 ) ;
F_49 ( 5 ) ;
F_38 ( V_41 , F_31 , NULL ) ;
F_50 ( V_38 ) ;
} else if ( V_57 && V_35 ) {
F_48 ( L_5 ) ;
F_49 ( 5 ) ;
F_38 ( V_41 , F_31 , NULL ) ;
F_50 ( V_57 ) ;
}
F_39 ( V_41 , V_62 ) ;
V_41 -> V_59 = V_59 ;
V_41 -> V_61 = V_60 ;
F_30 () ;
return 0 ;
}
static void F_51 ( struct V_40 * V_41 )
{
struct V_56 * V_57 ;
int V_19 = 0 ;
enum V_18 V_52 = V_26 ;
V_57 = F_45 ( V_41 ) ;
if ( ! V_57 ) {
F_52 ( L_6 ,
V_46 , V_41 -> V_47 -> V_48 , V_41 -> V_49 ) ;
return;
}
F_53 ( V_41 ) ;
V_41 -> V_61 ++ ;
if ( V_41 -> V_61 > V_66 )
goto V_67;
F_36 ( L_7 ,
V_41 -> V_61 ) ;
F_48 ( L_8 ) ;
F_42 ( V_41 , F_18 , & V_52 ) ;
if ( ( V_41 -> type & V_68 ) &&
V_52 != V_26 &&
V_52 != V_25 )
V_52 = V_25 ;
V_19 = V_64 -> V_69 ( V_41 , V_70 * 1000 ) ;
if ( V_19 < 0 || V_19 == V_71 ) {
F_36 ( L_9 ) ;
goto V_72;
}
F_48 ( L_10 ) ;
F_54 ( V_41 , V_73 ) ;
if ( V_52 == V_26 ) {
F_48 ( L_11 ) ;
V_19 = F_44 ( V_41 , V_57 ) ;
if ( V_19 ) {
F_36 ( L_12 ,
V_46 , V_19 ) ;
goto V_72;
}
}
if ( V_52 == V_74 ) {
F_48 ( L_13 ) ;
V_19 = F_55 ( V_41 , V_75 ) ;
if ( V_19 < 0 )
goto V_72;
if ( V_19 ) {
V_52 = V_25 ;
} else {
F_48 ( L_14 ) ;
F_42 ( V_41 , F_19 , & V_52 ) ;
}
}
if ( V_52 == V_74 ) {
F_48 ( L_15 ) ;
V_19 = F_55 ( V_41 , V_76 ) ;
if ( V_19 < 0 )
goto V_72;
if ( V_19 ) {
V_52 = V_25 ;
} else {
F_39 ( V_41 , V_50 ) ;
V_52 = V_31 ;
}
}
if ( V_52 == V_32 ) {
F_36 ( L_16 ) ;
goto V_72;
}
if ( V_52 == V_25 ) {
F_48 ( L_17 ) ;
V_19 = F_44 ( V_41 , NULL ) ;
if ( V_19 ) {
F_36 ( L_18 ,
V_46 , V_19 ) ;
goto V_72;
}
F_48 ( L_19
L_20 ) ;
V_52 = V_26 ;
F_42 ( V_41 , F_20 , & V_52 ) ;
}
if ( ( V_52 != V_31 ) &&
( V_52 != V_26 ) ) {
F_36 ( L_21 ) ;
goto V_72;
}
F_48 ( L_22 ) ;
F_42 ( V_41 , F_23 , NULL ) ;
return;
V_67:
F_52 ( L_23
L_24
L_25 ,
V_41 -> V_47 -> V_48 , V_41 -> V_49 ,
V_41 -> V_61 ) ;
goto V_77;
V_72:
F_52 ( L_26
L_27 ,
V_41 -> V_47 -> V_48 , V_41 -> V_49 ) ;
V_77:
F_54 ( V_41 , V_78 ) ;
F_42 ( V_41 , F_24 , NULL ) ;
F_41 ( V_41 , V_79 ) ;
if ( V_57 ) {
F_39 ( V_41 , V_63 ) ;
F_56 ( V_41 , V_15 ) ;
F_28 () ;
F_46 ( V_57 ) ;
F_30 () ;
}
}
static void F_57 ( void )
{
struct V_40 * V_41 , * V_80 ;
struct V_56 * V_38 ;
struct V_81 * V_82 ;
unsigned long V_83 ;
int V_19 ;
do {
V_19 = V_64 -> V_84 ( & V_41 ) ;
switch ( V_19 ) {
case V_85 :
F_58 ( & V_83 ) ;
F_59 ( NULL , true ) ;
F_60 (hose, &hose_list, list_node) {
V_80 = F_61 ( V_82 ) ;
if ( ! V_80 ) continue;
F_41 ( V_80 , V_50 ) ;
}
F_62 ( V_83 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
F_58 ( & V_83 ) ;
F_59 ( V_41 , true ) ;
if ( V_19 == V_88 )
F_41 ( V_41 , V_50 ) ;
else
F_41 ( V_41 ,
V_50 | V_55 ) ;
F_62 ( V_83 ) ;
break;
case V_89 :
return;
default:
F_36 ( L_28 ,
V_46 , V_19 ) ;
return;
}
if ( V_19 == V_86 ||
V_19 == V_87 ) {
F_51 ( V_41 ) ;
F_39 ( V_41 , V_55 ) ;
} else {
F_28 () ;
F_60 (hose, &hose_list, list_node) {
V_80 = F_61 ( V_82 ) ;
if ( ! V_80 ||
! ( V_80 -> V_54 & V_50 ) ||
( V_80 -> V_54 & V_55 ) )
continue;
F_39 ( V_41 , V_63 ) ;
V_38 = F_45 ( V_80 ) ;
F_42 ( V_41 ,
F_24 , NULL ) ;
F_46 ( V_38 ) ;
}
F_30 () ;
}
if ( V_19 == V_85 )
break;
} while ( V_19 != V_89 );
}
void F_63 ( struct V_40 * V_41 )
{
if ( V_41 )
F_51 ( V_41 ) ;
else
F_57 () ;
}
