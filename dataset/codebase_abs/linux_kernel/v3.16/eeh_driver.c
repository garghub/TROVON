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
static void * F_17 ( void * V_16 , void * V_17 )
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
static void * F_18 ( void * V_16 , void * V_17 )
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
static void * F_19 ( void * V_16 , void * V_17 )
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
static void * F_20 ( void * V_16 , void * V_17 )
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
static void * F_21 ( void * V_16 , void * V_17 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_16 ;
struct V_1 * V_3 = F_16 ( V_9 ) ;
int * V_35 = ( int * ) V_17 ;
if ( ! V_3 || ( V_3 -> V_36 & V_37 ) )
return NULL ;
if ( F_14 ( V_9 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_23 )
return NULL ;
}
F_22 ( L_2 ,
F_23 ( V_3 ) ) ;
V_9 -> V_38 = V_3 -> V_38 ;
V_9 -> V_13 |= V_39 ;
( * V_35 ) ++ ;
F_24 () ;
F_25 ( V_3 ) ;
F_26 () ;
return NULL ;
}
static void * F_27 ( void * V_16 , void * V_17 )
{
struct V_40 * V_41 = (struct V_40 * ) V_16 ;
struct V_8 * V_9 , * V_42 ;
F_28 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_39 ) )
continue;
V_9 -> V_13 &= ~ ( V_39 | V_14 ) ;
F_29 ( V_9 ) ;
}
return NULL ;
}
static void * F_30 ( void * V_16 , void * V_43 )
{
struct V_40 * V_41 = (struct V_40 * ) V_16 ;
int V_44 , V_19 ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
V_19 = F_31 ( V_41 , V_45 ) ;
if ( V_19 )
continue;
V_19 = F_31 ( V_41 , V_46 ) ;
if ( ! V_19 )
break;
}
if ( V_19 ) {
F_32 ( L_3 ,
V_47 , V_41 -> V_48 -> V_49 , V_41 -> V_50 , V_19 ) ;
return ( void * ) V_41 ;
}
return NULL ;
}
static int F_33 ( struct V_40 * V_41 )
{
void * V_19 ;
V_19 = F_34 ( V_41 , F_30 , NULL ) ;
if ( ! V_19 )
F_35 ( V_41 , V_51 ) ;
return V_19 ? - V_52 : 0 ;
}
static int F_36 ( struct V_40 * V_41 , struct V_53 * V_38 )
{
struct V_53 * V_54 = F_37 ( V_41 ) ;
struct V_55 V_56 ;
int V_57 , V_19 , V_35 = 0 ;
V_57 = V_41 -> V_58 ;
V_56 = V_41 -> V_56 ;
F_38 ( V_41 , V_59 ) ;
if ( V_38 ) {
F_24 () ;
F_39 ( V_38 ) ;
F_26 () ;
} else if ( V_54 ) {
F_40 ( V_41 , F_21 , & V_35 ) ;
}
F_38 ( V_41 , V_60 ) ;
V_19 = F_41 ( V_41 ) ;
if ( V_19 ) {
F_35 ( V_41 , V_60 ) ;
return V_19 ;
}
F_24 () ;
V_61 -> V_62 ( V_41 ) ;
F_42 ( V_41 ) ;
F_35 ( V_41 , V_60 ) ;
V_19 = F_33 ( V_41 ) ;
if ( V_19 )
return V_19 ;
if ( V_38 ) {
F_43 ( L_4 ) ;
F_44 ( 5 ) ;
F_34 ( V_41 , F_27 , NULL ) ;
F_45 ( V_38 ) ;
} else if ( V_54 && V_35 ) {
F_43 ( L_5 ) ;
F_44 ( 5 ) ;
F_34 ( V_41 , F_27 , NULL ) ;
F_45 ( V_54 ) ;
}
F_35 ( V_41 , V_59 ) ;
V_41 -> V_56 = V_56 ;
V_41 -> V_58 = V_57 ;
F_26 () ;
return 0 ;
}
static void F_46 ( struct V_40 * V_41 )
{
struct V_53 * V_54 ;
int V_19 = 0 ;
enum V_18 V_63 = V_26 ;
V_54 = F_37 ( V_41 ) ;
if ( ! V_54 ) {
F_47 ( L_6 ,
V_47 , V_41 -> V_48 -> V_49 , V_41 -> V_50 ) ;
return;
}
F_48 ( V_41 ) ;
V_41 -> V_58 ++ ;
if ( V_41 -> V_58 > V_64 )
goto V_65;
F_49 ( L_7 ,
V_41 -> V_58 ) ;
F_43 ( L_8 ) ;
F_40 ( V_41 , F_15 , & V_63 ) ;
V_19 = V_61 -> V_66 ( V_41 , V_67 * 1000 ) ;
if ( V_19 < 0 || V_19 == V_68 ) {
F_49 ( L_9 ) ;
goto V_69;
}
F_43 ( L_10 ) ;
F_50 ( V_41 , V_70 ) ;
if ( V_63 == V_26 ) {
F_43 ( L_11 ) ;
V_19 = F_36 ( V_41 , V_54 ) ;
if ( V_19 ) {
F_49 ( L_12 ,
V_47 , V_19 ) ;
goto V_69;
}
}
if ( V_63 == V_71 ) {
F_43 ( L_13 ) ;
V_19 = F_31 ( V_41 , V_45 ) ;
if ( V_19 < 0 )
goto V_69;
if ( V_19 ) {
V_63 = V_25 ;
} else {
F_43 ( L_14 ) ;
F_40 ( V_41 , F_17 , & V_63 ) ;
}
}
if ( V_63 == V_71 ) {
F_43 ( L_15 ) ;
V_19 = F_31 ( V_41 , V_46 ) ;
if ( V_19 < 0 )
goto V_69;
if ( V_19 ) {
V_63 = V_25 ;
} else {
F_35 ( V_41 , V_51 ) ;
V_63 = V_31 ;
}
}
if ( V_63 == V_32 ) {
F_49 ( L_16 ) ;
goto V_69;
}
if ( V_63 == V_25 ) {
F_43 ( L_17 ) ;
V_19 = F_36 ( V_41 , NULL ) ;
if ( V_19 ) {
F_49 ( L_18 ,
V_47 , V_19 ) ;
goto V_69;
}
F_43 ( L_19
L_20 ) ;
V_63 = V_26 ;
F_40 ( V_41 , F_18 , & V_63 ) ;
}
if ( ( V_63 != V_31 ) &&
( V_63 != V_26 ) ) {
F_49 ( L_21 ) ;
goto V_69;
}
F_43 ( L_22 ) ;
F_40 ( V_41 , F_19 , NULL ) ;
return;
V_65:
F_47 ( L_23
L_24
L_25 ,
V_41 -> V_48 -> V_49 , V_41 -> V_50 ,
V_41 -> V_58 ) ;
goto V_72;
V_69:
F_47 ( L_26
L_27 ,
V_41 -> V_48 -> V_49 , V_41 -> V_50 ) ;
V_72:
F_50 ( V_41 , V_73 ) ;
F_40 ( V_41 , F_20 , NULL ) ;
V_41 -> V_58 = V_64 + 1 ;
if ( V_54 ) {
F_51 ( V_41 , V_15 ) ;
F_24 () ;
F_39 ( V_54 ) ;
F_26 () ;
}
}
static void F_52 ( void )
{
struct V_40 * V_41 , * V_74 ;
struct V_53 * V_38 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
int V_19 ;
do {
V_19 = V_61 -> V_78 ( & V_41 ) ;
switch ( V_19 ) {
case V_79 :
F_53 ( & V_77 ) ;
F_54 ( NULL , true ) ;
F_55 (hose, &hose_list, list_node) {
V_74 = F_56 ( V_76 ) ;
if ( ! V_74 ) continue;
F_38 ( V_74 , V_51 ) ;
}
F_57 ( V_77 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
F_53 ( & V_77 ) ;
F_54 ( V_41 , true ) ;
if ( V_19 == V_82 )
F_38 ( V_41 , V_51 ) ;
else
F_38 ( V_41 ,
V_51 | V_83 ) ;
F_57 ( V_77 ) ;
break;
case V_84 :
return;
default:
F_32 ( L_28 ,
V_47 , V_19 ) ;
return;
}
if ( V_19 == V_80 ||
V_19 == V_81 ) {
F_46 ( V_41 ) ;
F_35 ( V_41 , V_83 ) ;
} else {
F_24 () ;
F_55 (hose, &hose_list, list_node) {
V_74 = F_56 ( V_76 ) ;
if ( ! V_74 ||
! ( V_74 -> V_85 & V_51 ) ||
( V_74 -> V_85 & V_83 ) )
continue;
V_38 = F_37 ( V_74 ) ;
F_40 ( V_41 ,
F_20 , NULL ) ;
F_39 ( V_38 ) ;
}
F_26 () ;
}
if ( V_19 == V_79 )
break;
} while ( V_19 != V_84 );
}
void F_58 ( struct V_40 * V_41 )
{
if ( V_41 )
F_46 ( V_41 ) ;
else
F_52 () ;
}
