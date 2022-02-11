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
struct V_15 * V_16 ;
if ( ( V_9 -> V_13 ) & V_14 ) {
V_9 -> V_13 &= ~ V_14 ;
V_16 = F_11 ( V_3 -> V_12 ) ;
if ( V_16 && V_16 -> V_17 > 0 )
F_12 ( V_3 -> V_12 ) ;
}
}
static void * F_13 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
enum V_20 V_21 , * V_22 = V_19 ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_23 = V_24 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_26 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_21 = V_4 -> V_25 -> V_26 ( V_3 , V_24 ) ;
if ( V_21 == V_27 ) * V_22 = V_21 ;
if ( * V_22 == V_28 ) * V_22 = V_21 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_15 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
enum V_20 V_21 , * V_22 = V_19 ;
struct V_6 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_29 ||
( V_9 -> V_13 & V_30 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_21 = V_4 -> V_25 -> V_29 ( V_3 ) ;
if ( V_21 == V_27 ) * V_22 = V_21 ;
if ( * V_22 == V_28 ) * V_22 = V_21 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_16 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
enum V_20 V_21 , * V_22 = V_19 ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_23 = V_31 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_32 ||
( V_9 -> V_13 & V_30 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_21 = V_4 -> V_25 -> V_32 ( V_3 ) ;
if ( ( * V_22 == V_28 ) ||
( * V_22 == V_33 ) ) * V_22 = V_21 ;
if ( * V_22 == V_34 &&
V_21 == V_27 ) * V_22 = V_21 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_17 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_23 = V_31 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_35 ||
( V_9 -> V_13 & V_30 ) ) {
V_9 -> V_13 &= ~ V_30 ;
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_25 -> V_35 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_18 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_23 = V_36 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_26 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_25 -> V_26 ( V_3 , V_36 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_19 ( void * V_18 , void * V_19 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
int * V_37 = ( int * ) V_19 ;
if ( ! V_3 || ( V_3 -> V_38 & V_39 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_25 )
return NULL ;
}
F_20 ( L_2 ,
F_21 ( V_3 ) ) ;
V_9 -> V_40 = V_3 -> V_40 ;
V_9 -> V_13 |= V_41 ;
( * V_37 ) ++ ;
F_22 () ;
F_23 ( V_3 ) ;
F_24 () ;
return NULL ;
}
static void * F_25 ( void * V_18 , void * V_19 )
{
struct V_42 * V_43 = (struct V_42 * ) V_18 ;
struct V_8 * V_9 , * V_44 ;
F_26 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_41 ) )
continue;
V_9 -> V_13 &= ~ ( V_41 | V_14 ) ;
F_27 ( V_9 ) ;
}
return NULL ;
}
static int F_28 ( struct V_42 * V_43 , struct V_45 * V_40 )
{
struct V_45 * V_46 = F_29 ( V_43 ) ;
struct V_47 V_48 ;
int V_49 , V_21 , V_37 = 0 ;
V_49 = V_43 -> V_50 ;
V_48 = V_43 -> V_48 ;
F_30 ( V_43 , V_51 ) ;
if ( V_40 ) {
F_22 () ;
F_31 ( V_40 ) ;
F_24 () ;
} else if ( V_46 ) {
F_32 ( V_43 , F_19 , & V_37 ) ;
}
V_21 = F_33 ( V_43 ) ;
if ( V_21 )
return V_21 ;
F_22 () ;
V_52 -> V_53 ( V_43 ) ;
F_34 ( V_43 ) ;
if ( V_40 ) {
F_35 ( L_3 ) ;
F_36 ( 5 ) ;
F_37 ( V_43 , F_25 , NULL ) ;
F_38 ( V_40 ) ;
} else if ( V_46 && V_37 ) {
F_35 ( L_4 ) ;
F_36 ( 5 ) ;
F_37 ( V_43 , F_25 , NULL ) ;
F_38 ( V_46 ) ;
}
F_39 ( V_43 , V_51 ) ;
V_43 -> V_48 = V_48 ;
V_43 -> V_50 = V_49 ;
F_24 () ;
return 0 ;
}
static void F_40 ( struct V_42 * V_43 )
{
struct V_45 * V_46 ;
int V_21 = 0 ;
enum V_20 V_54 = V_28 ;
V_46 = F_29 ( V_43 ) ;
if ( ! V_46 ) {
F_41 ( L_5 ,
V_55 , V_43 -> V_56 -> V_57 , V_43 -> V_58 ) ;
return;
}
F_42 ( V_43 ) ;
V_43 -> V_50 ++ ;
if ( V_43 -> V_50 > V_59 )
goto V_60;
F_43 ( L_6 ,
V_43 -> V_50 ) ;
F_35 ( L_7 ) ;
F_32 ( V_43 , F_13 , & V_54 ) ;
V_21 = V_52 -> V_61 ( V_43 , V_62 * 1000 ) ;
if ( V_21 < 0 || V_21 == V_63 ) {
F_43 ( L_8 ) ;
goto V_64;
}
F_35 ( L_9 ) ;
F_44 ( V_43 , V_65 ) ;
if ( V_54 == V_28 ) {
F_35 ( L_10 ) ;
V_21 = F_28 ( V_43 , V_46 ) ;
if ( V_21 ) {
F_43 ( L_11 ,
V_55 , V_21 ) ;
goto V_64;
}
}
if ( V_54 == V_66 ) {
F_35 ( L_12 ) ;
V_21 = F_45 ( V_43 , V_67 ) ;
if ( V_21 < 0 )
goto V_64;
if ( V_21 ) {
V_54 = V_27 ;
} else {
F_35 ( L_13 ) ;
V_54 = V_28 ;
F_32 ( V_43 , F_15 , & V_54 ) ;
}
}
if ( V_54 == V_66 ) {
F_35 ( L_14 ) ;
V_21 = F_45 ( V_43 , V_68 ) ;
if ( V_21 < 0 )
goto V_64;
if ( V_21 )
V_54 = V_27 ;
else
V_54 = V_33 ;
}
if ( V_54 == V_34 ) {
F_43 ( L_15 ) ;
goto V_64;
}
if ( V_54 == V_27 ) {
F_35 ( L_16 ) ;
V_21 = F_28 ( V_43 , NULL ) ;
if ( V_21 ) {
F_43 ( L_17 ,
V_55 , V_21 ) ;
goto V_64;
}
F_35 ( L_18
L_19 ) ;
V_54 = V_28 ;
F_32 ( V_43 , F_16 , & V_54 ) ;
}
if ( ( V_54 != V_33 ) &&
( V_54 != V_28 ) ) {
F_43 ( L_20 ) ;
goto V_64;
}
F_35 ( L_21 ) ;
F_32 ( V_43 , F_17 , NULL ) ;
return;
V_60:
F_41 ( L_22
L_23
L_24 ,
V_43 -> V_56 -> V_57 , V_43 -> V_58 ,
V_43 -> V_50 ) ;
goto V_69;
V_64:
F_41 ( L_25
L_26 ,
V_43 -> V_56 -> V_57 , V_43 -> V_58 ) ;
V_69:
F_44 ( V_43 , V_70 ) ;
F_32 ( V_43 , F_18 , NULL ) ;
if ( V_46 ) {
F_22 () ;
F_31 ( V_46 ) ;
F_24 () ;
}
}
static void F_46 ( void )
{
struct V_42 * V_43 , * V_71 ;
struct V_45 * V_40 ;
struct V_72 * V_73 ;
unsigned long V_74 ;
int V_21 ;
do {
V_21 = V_52 -> V_75 ( & V_43 ) ;
switch ( V_21 ) {
case V_76 :
F_47 ( & V_74 ) ;
F_48 ( NULL ) ;
F_49 (hose, &hose_list, list_node) {
V_71 = F_50 ( V_73 ) ;
if ( ! V_71 ) continue;
F_30 ( V_71 ,
V_77 | V_78 ) ;
}
F_51 ( V_74 ) ;
break;
case V_79 :
case V_80 :
case V_81 :
F_47 ( & V_74 ) ;
F_48 ( V_43 ) ;
if ( V_21 == V_81 )
F_30 ( V_43 ,
V_77 | V_78 ) ;
else
F_30 ( V_43 ,
V_77 | V_82 ) ;
F_51 ( V_74 ) ;
break;
case V_83 :
return;
default:
F_52 ( L_27 ,
V_55 , V_21 ) ;
return;
}
if ( V_21 == V_79 ||
V_21 == V_80 ) {
F_40 ( V_43 ) ;
} else {
F_22 () ;
F_49 (hose, &hose_list, list_node) {
V_71 = F_50 ( V_73 ) ;
if ( ! V_71 ||
! ( V_71 -> V_84 & V_78 ) )
continue;
V_40 = F_29 ( V_71 ) ;
F_32 ( V_43 ,
F_18 , NULL ) ;
F_31 ( V_40 ) ;
}
F_24 () ;
}
if ( V_21 == V_76 )
break;
} while ( V_21 != V_83 );
}
void F_53 ( struct V_42 * V_43 )
{
if ( V_43 )
F_40 ( V_43 ) ;
else
F_46 () ;
}
