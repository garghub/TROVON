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
! V_4 -> V_25 -> V_29 ) {
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
V_3 -> V_23 = V_30 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_31 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_21 = V_4 -> V_25 -> V_31 ( V_3 ) ;
if ( ( * V_22 == V_28 ) ||
( * V_22 == V_32 ) ) * V_22 = V_21 ;
if ( * V_22 == V_33 &&
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
V_3 -> V_23 = V_30 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_10 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_34 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_25 -> V_34 ( V_3 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_18 ( void * V_18 , void * V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
struct V_6 * V_4 ;
if ( ! V_3 ) return NULL ;
V_3 -> V_23 = V_35 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) return NULL ;
F_6 ( V_3 ) ;
if ( ! V_4 -> V_25 ||
! V_4 -> V_25 -> V_26 ) {
F_4 ( V_3 ) ;
return NULL ;
}
V_4 -> V_25 -> V_26 ( V_3 , V_35 ) ;
F_4 ( V_3 ) ;
return NULL ;
}
static void * F_19 ( void * V_18 , void * V_19 )
{
struct V_6 * V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
struct V_1 * V_3 = F_14 ( V_9 ) ;
int * V_36 = ( int * ) V_19 ;
if ( ! V_3 || ( V_3 -> V_37 & V_38 ) )
return NULL ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_25 )
return NULL ;
F_20 ( L_2 ,
F_21 ( V_3 ) ) ;
V_9 -> V_39 = V_3 -> V_39 ;
V_9 -> V_13 |= V_40 ;
( * V_36 ) ++ ;
F_22 ( V_3 ) ;
return NULL ;
}
static void * F_23 ( void * V_18 , void * V_19 )
{
struct V_41 * V_42 = (struct V_41 * ) V_18 ;
struct V_8 * V_9 , * V_43 ;
F_24 (pe, edev, tmp) {
if ( ! ( V_9 -> V_13 & V_40 ) )
continue;
V_9 -> V_13 &= ~ ( V_40 | V_14 ) ;
F_25 ( V_9 ) ;
}
return NULL ;
}
static int F_26 ( struct V_41 * V_42 , struct V_44 * V_39 )
{
struct V_44 * V_45 = F_27 ( V_42 ) ;
struct V_46 V_47 ;
int V_48 , V_21 , V_36 = 0 ;
V_48 = V_42 -> V_49 ;
V_47 = V_42 -> V_47 ;
F_28 ( V_42 , V_50 ) ;
if ( V_39 )
F_29 ( V_39 ) ;
else if ( V_45 )
F_30 ( V_42 , F_19 , & V_36 ) ;
V_21 = F_31 ( V_42 ) ;
if ( V_21 )
return V_21 ;
V_51 -> V_52 ( V_42 ) ;
F_32 ( V_42 ) ;
if ( V_39 ) {
F_33 ( L_3 ) ;
F_34 ( 5 ) ;
F_35 ( V_42 , F_23 , NULL ) ;
F_36 ( V_39 ) ;
} else if ( V_45 && V_36 ) {
F_33 ( L_4 ) ;
F_34 ( 5 ) ;
F_35 ( V_42 , F_23 , NULL ) ;
F_36 ( V_45 ) ;
}
F_37 ( V_42 , V_50 ) ;
V_42 -> V_47 = V_47 ;
V_42 -> V_49 = V_48 ;
return 0 ;
}
static void F_38 ( struct V_41 * V_42 )
{
struct V_44 * V_45 ;
int V_21 = 0 ;
enum V_20 V_53 = V_28 ;
V_45 = F_27 ( V_42 ) ;
if ( ! V_45 ) {
F_39 ( L_5 ,
V_54 , V_42 -> V_55 -> V_56 , V_42 -> V_57 ) ;
return;
}
F_40 ( V_42 ) ;
V_42 -> V_49 ++ ;
if ( V_42 -> V_49 > V_58 )
goto V_59;
F_41 ( L_6 ,
V_42 -> V_49 ) ;
F_33 ( L_7 ) ;
F_30 ( V_42 , F_13 , & V_53 ) ;
V_21 = V_51 -> V_60 ( V_42 , V_61 * 1000 ) ;
if ( V_21 < 0 || V_21 == V_62 ) {
F_41 ( L_8 ) ;
goto V_63;
}
F_33 ( L_9 ) ;
F_42 ( V_42 , V_64 ) ;
if ( V_53 == V_28 ) {
F_33 ( L_10 ) ;
V_21 = F_26 ( V_42 , V_45 ) ;
if ( V_21 ) {
F_41 ( L_11 ,
V_54 , V_21 ) ;
goto V_63;
}
}
if ( V_53 == V_65 ) {
F_33 ( L_12 ) ;
V_21 = F_43 ( V_42 , V_66 ) ;
if ( V_21 < 0 )
goto V_63;
if ( V_21 ) {
V_53 = V_27 ;
} else {
F_33 ( L_13 ) ;
V_53 = V_28 ;
F_30 ( V_42 , F_15 , & V_53 ) ;
}
}
if ( V_53 == V_65 ) {
F_33 ( L_14 ) ;
V_21 = F_43 ( V_42 , V_67 ) ;
if ( V_21 < 0 )
goto V_63;
if ( V_21 )
V_53 = V_27 ;
else
V_53 = V_32 ;
}
if ( V_53 == V_33 ) {
F_41 ( L_15 ) ;
goto V_63;
}
if ( V_53 == V_27 ) {
F_33 ( L_16 ) ;
V_21 = F_26 ( V_42 , NULL ) ;
if ( V_21 ) {
F_41 ( L_17 ,
V_54 , V_21 ) ;
goto V_63;
}
F_33 ( L_18
L_19 ) ;
V_53 = V_28 ;
F_30 ( V_42 , F_16 , & V_53 ) ;
}
if ( ( V_53 != V_32 ) &&
( V_53 != V_28 ) ) {
F_41 ( L_20 ) ;
goto V_63;
}
F_33 ( L_21 ) ;
F_30 ( V_42 , F_17 , NULL ) ;
return;
V_59:
F_39 ( L_22
L_23
L_24 ,
V_42 -> V_55 -> V_56 , V_42 -> V_57 ,
V_42 -> V_49 ) ;
goto V_68;
V_63:
F_39 ( L_25
L_26 ,
V_42 -> V_55 -> V_56 , V_42 -> V_57 ) ;
V_68:
F_42 ( V_42 , V_69 ) ;
F_30 ( V_42 , F_18 , NULL ) ;
if ( V_45 )
F_29 ( V_45 ) ;
}
static void F_44 ( void )
{
struct V_41 * V_42 , * V_70 ;
struct V_44 * V_39 ;
struct V_71 * V_72 , * V_43 ;
unsigned long V_73 ;
int V_21 = 0 ;
V_21 = V_51 -> V_74 ( & V_42 ) ;
if ( V_21 <= 0 )
return;
switch ( V_21 ) {
case 4 :
F_45 ( & V_73 ) ;
F_46 (hose, tmp,
&hose_list, list_node) {
V_70 = F_47 ( V_72 ) ;
if ( ! V_70 ) continue;
F_28 ( V_70 ,
V_75 | V_76 ) ;
}
F_48 ( V_73 ) ;
F_49 ( NULL ) ;
break;
case 3 :
case 2 :
case 1 :
F_45 ( & V_73 ) ;
if ( V_21 == 3 )
F_28 ( V_42 ,
V_75 | V_76 ) ;
else
F_28 ( V_42 ,
V_75 | V_77 ) ;
F_48 ( V_73 ) ;
F_49 ( V_42 ) ;
break;
default:
F_39 ( L_27 ,
V_54 , V_21 ) ;
return;
}
if ( V_21 == 2 || V_21 == 1 )
F_38 ( V_42 ) ;
else {
F_46 (hose, tmp,
&hose_list, list_node) {
V_70 = F_47 ( V_72 ) ;
if ( ! V_70 || ! ( V_70 -> V_78 & V_76 ) )
continue;
V_39 = F_27 ( V_70 ) ;
F_30 ( V_42 , F_18 , NULL ) ;
F_29 ( V_39 ) ;
}
}
}
void F_50 ( struct V_41 * V_42 )
{
if ( V_42 )
F_38 ( V_42 ) ;
else
F_44 () ;
}
