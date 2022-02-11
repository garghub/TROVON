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
static void * F_14 ( void * V_15 , void * V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
enum V_17 V_18 , * V_19 = V_16 ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_20 = V_21 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_22 ||
! V_4 -> V_22 -> V_23 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_18 = V_4 -> V_22 -> V_23 ( V_3 , V_21 ) ;
if ( V_18 == V_24 ) * V_19 = V_18 ;
if ( * V_19 == V_25 ) * V_19 = V_18 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_16 ( void * V_15 , void * V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
enum V_17 V_18 , * V_19 = V_16 ;
struct V_6 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
if ( ! V_4 -> V_22 ||
! V_4 -> V_22 -> V_26 ||
( V_9 -> V_13 & V_27 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_18 = V_4 -> V_22 -> V_26 ( V_3 ) ;
if ( V_18 == V_24 ) * V_19 = V_18 ;
if ( * V_19 == V_25 ) * V_19 = V_18 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_17 ( void * V_15 , void * V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
enum V_17 V_18 , * V_19 = V_16 ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_20 = V_28 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_22 ||
! V_4 -> V_22 -> V_29 ||
( V_9 -> V_13 & V_27 ) ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_18 = V_4 -> V_22 -> V_29 ( V_3 ) ;
if ( ( * V_19 == V_25 ) ||
( * V_19 == V_30 ) ) * V_19 = V_18 ;
if ( * V_19 == V_31 &&
V_18 == V_24 ) * V_19 = V_18 ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_18 ( void * V_15 , void * V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_20 = V_28 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_22 ||
! V_4 -> V_22 -> V_32 ||
( V_9 -> V_13 & V_27 ) ) {
V_9 -> V_13 &= ~ V_27 ;
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_22 -> V_32 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_19 ( void * V_15 , void * V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_20 = V_33 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_22 ||
! V_4 -> V_22 -> V_23 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_22 -> V_23 ( V_3 , V_33 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_20 ( void * V_15 , void * V_16 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_15 ;
struct V_1 * V_3 = F_15 ( V_9 ) ;
int * V_34 = ( int * ) V_16 ;
if ( ! V_3 || ( V_3 -> V_35 & V_36 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 ) {
F_4 ( V_3 ) ;
if ( V_4 -> V_22 )
return NULL ;
}
F_21 ( L_2 ,
F_22 ( V_3 ) ) ;
V_9 -> V_37 = V_3 -> V_37 ;
V_9 -> V_13 |= V_38 ;
( * V_34 ) ++ ;
F_23 () ;
F_24 ( V_3 ) ;
F_25 () ;
return NULL ;
}
static void * F_26 ( void * V_15 , void * V_16 )
{
struct V_39 * V_40 = (struct V_39 * ) V_15 ;
struct V_8 * V_9 , * V_41 ;
F_27 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_38 ) )
continue;
V_9 -> V_13 &= ~ ( V_38 | V_14 ) ;
F_28 ( V_9 ) ;
}
return NULL ;
}
static int F_29 ( struct V_39 * V_40 , struct V_42 * V_37 )
{
struct V_42 * V_43 = F_30 ( V_40 ) ;
struct V_44 V_45 ;
int V_46 , V_18 , V_34 = 0 ;
V_46 = V_40 -> V_47 ;
V_45 = V_40 -> V_45 ;
F_31 ( V_40 , V_48 ) ;
if ( V_37 ) {
F_23 () ;
F_32 ( V_37 ) ;
F_25 () ;
} else if ( V_43 ) {
F_33 ( V_40 , F_20 , & V_34 ) ;
}
V_18 = F_34 ( V_40 ) ;
if ( V_18 )
return V_18 ;
F_23 () ;
V_49 -> V_50 ( V_40 ) ;
F_35 ( V_40 ) ;
if ( V_37 ) {
F_36 ( L_3 ) ;
F_37 ( 5 ) ;
F_38 ( V_40 , F_26 , NULL ) ;
F_39 ( V_37 ) ;
} else if ( V_43 && V_34 ) {
F_36 ( L_4 ) ;
F_37 ( 5 ) ;
F_38 ( V_40 , F_26 , NULL ) ;
F_39 ( V_43 ) ;
}
F_40 ( V_40 , V_48 ) ;
V_40 -> V_45 = V_45 ;
V_40 -> V_47 = V_46 ;
F_25 () ;
return 0 ;
}
static void F_41 ( struct V_39 * V_40 )
{
struct V_42 * V_43 ;
int V_18 = 0 ;
enum V_17 V_51 = V_25 ;
V_43 = F_30 ( V_40 ) ;
if ( ! V_43 ) {
F_42 ( L_5 ,
V_52 , V_40 -> V_53 -> V_54 , V_40 -> V_55 ) ;
return;
}
F_43 ( V_40 ) ;
V_40 -> V_47 ++ ;
if ( V_40 -> V_47 > V_56 )
goto V_57;
F_44 ( L_6 ,
V_40 -> V_47 ) ;
F_36 ( L_7 ) ;
F_33 ( V_40 , F_14 , & V_51 ) ;
V_18 = V_49 -> V_58 ( V_40 , V_59 * 1000 ) ;
if ( V_18 < 0 || V_18 == V_60 ) {
F_44 ( L_8 ) ;
goto V_61;
}
F_36 ( L_9 ) ;
F_45 ( V_40 , V_62 ) ;
if ( V_51 == V_25 ) {
F_36 ( L_10 ) ;
V_18 = F_29 ( V_40 , V_43 ) ;
if ( V_18 ) {
F_44 ( L_11 ,
V_52 , V_18 ) ;
goto V_61;
}
}
if ( V_51 == V_63 ) {
F_36 ( L_12 ) ;
V_18 = F_46 ( V_40 , V_64 ) ;
if ( V_18 < 0 )
goto V_61;
if ( V_18 ) {
V_51 = V_24 ;
} else {
F_36 ( L_13 ) ;
V_51 = V_25 ;
F_33 ( V_40 , F_16 , & V_51 ) ;
}
}
if ( V_51 == V_63 ) {
F_36 ( L_14 ) ;
V_18 = F_46 ( V_40 , V_65 ) ;
if ( V_18 < 0 )
goto V_61;
if ( V_18 )
V_51 = V_24 ;
else
V_51 = V_30 ;
}
if ( V_51 == V_31 ) {
F_44 ( L_15 ) ;
goto V_61;
}
if ( V_51 == V_24 ) {
F_36 ( L_16 ) ;
V_18 = F_29 ( V_40 , NULL ) ;
if ( V_18 ) {
F_44 ( L_17 ,
V_52 , V_18 ) ;
goto V_61;
}
F_36 ( L_18
L_19 ) ;
V_51 = V_25 ;
F_33 ( V_40 , F_17 , & V_51 ) ;
}
if ( ( V_51 != V_30 ) &&
( V_51 != V_25 ) ) {
F_44 ( L_20 ) ;
goto V_61;
}
F_36 ( L_21 ) ;
F_33 ( V_40 , F_18 , NULL ) ;
return;
V_57:
F_42 ( L_22
L_23
L_24 ,
V_40 -> V_53 -> V_54 , V_40 -> V_55 ,
V_40 -> V_47 ) ;
goto V_66;
V_61:
F_42 ( L_25
L_26 ,
V_40 -> V_53 -> V_54 , V_40 -> V_55 ) ;
V_66:
F_45 ( V_40 , V_67 ) ;
F_33 ( V_40 , F_19 , NULL ) ;
if ( V_43 ) {
F_23 () ;
F_32 ( V_43 ) ;
F_25 () ;
}
}
static void F_47 ( void )
{
struct V_39 * V_40 , * V_68 ;
struct V_42 * V_37 ;
struct V_69 * V_70 ;
unsigned long V_71 ;
int V_18 ;
do {
V_18 = V_49 -> V_72 ( & V_40 ) ;
switch ( V_18 ) {
case V_73 :
F_48 ( & V_71 ) ;
F_49 ( NULL ) ;
F_50 (hose, &hose_list, list_node) {
V_68 = F_51 ( V_70 ) ;
if ( ! V_68 ) continue;
F_31 ( V_68 ,
V_74 | V_75 ) ;
}
F_52 ( V_71 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
F_48 ( & V_71 ) ;
F_49 ( V_40 ) ;
if ( V_18 == V_78 )
F_31 ( V_40 ,
V_74 | V_75 ) ;
else
F_31 ( V_40 ,
V_74 | V_79 ) ;
F_52 ( V_71 ) ;
break;
case V_80 :
return;
default:
F_53 ( L_27 ,
V_52 , V_18 ) ;
return;
}
if ( V_18 == V_76 ||
V_18 == V_77 ) {
F_41 ( V_40 ) ;
} else {
F_23 () ;
F_50 (hose, &hose_list, list_node) {
V_68 = F_51 ( V_70 ) ;
if ( ! V_68 ||
! ( V_68 -> V_81 & V_75 ) )
continue;
V_37 = F_30 ( V_68 ) ;
F_33 ( V_40 ,
F_19 , NULL ) ;
F_32 ( V_37 ) ;
}
F_25 () ;
}
if ( V_18 == V_73 )
break;
} while ( V_18 != V_80 );
}
void F_54 ( struct V_39 * V_40 )
{
if ( V_40 )
F_41 ( V_40 ) ;
else
F_47 () ;
}
