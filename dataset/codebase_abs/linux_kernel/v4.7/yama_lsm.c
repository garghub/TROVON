static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
char * V_5 , * V_6 ;
V_5 = F_3 ( V_4 -> V_7 , V_8 ) ;
V_6 = F_3 ( V_4 -> V_9 , V_8 ) ;
F_4 (
L_1 ,
V_4 -> V_10 , V_5 , V_4 -> V_7 -> V_11 , V_6 ,
V_4 -> V_9 -> V_11 ) ;
F_5 ( V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_4 -> V_9 ) ;
F_6 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
static void F_7 ( const char * V_10 , struct V_12 * V_7 ,
struct V_12 * V_9 )
{
struct V_3 * V_4 ;
char V_13 [ sizeof( V_9 -> V_14 ) ] ;
F_8 ( & V_7 -> V_15 ) ;
if ( V_16 -> V_17 & V_18 ) {
F_4 (
L_1 ,
V_10 , V_7 -> V_14 , V_7 -> V_11 ,
F_9 ( V_13 , V_9 ) , V_9 -> V_11 ) ;
return;
}
V_4 = F_10 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return;
F_11 ( & V_4 -> V_2 , F_1 ) ;
F_12 ( V_7 ) ;
F_12 ( V_9 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_9 = V_9 ;
if ( F_13 ( V_16 , & V_4 -> V_2 , true ) == 0 )
return;
F_14 ( 1 , L_2 ) ;
F_6 ( V_7 ) ;
F_6 ( V_9 ) ;
F_5 ( V_4 ) ;
}
static void F_15 ( struct V_20 * V_2 )
{
struct V_21 * V_22 ;
F_16 ( & V_23 ) ;
F_17 () ;
F_18 (relation, &ptracer_relations, node) {
if ( V_22 -> V_24 ) {
F_19 ( & V_22 -> V_25 ) ;
F_20 ( V_22 , V_26 ) ;
}
}
F_21 () ;
F_22 ( & V_23 ) ;
}
static int F_23 ( struct V_12 * V_27 ,
struct V_12 * V_28 )
{
struct V_21 * V_22 , * V_29 ;
V_29 = F_10 ( sizeof( * V_29 ) , V_8 ) ;
if ( ! V_29 )
return - V_30 ;
V_29 -> V_28 = V_28 ;
V_29 -> V_27 = V_27 ;
V_29 -> V_24 = false ;
F_16 ( & V_23 ) ;
F_17 () ;
F_18 (relation, &ptracer_relations, node) {
if ( V_22 -> V_24 )
continue;
if ( V_22 -> V_28 == V_28 ) {
F_24 ( & V_22 -> V_25 , & V_29 -> V_25 ) ;
F_20 ( V_22 , V_26 ) ;
goto V_31;
}
}
F_25 ( & V_29 -> V_25 , & V_32 ) ;
V_31:
F_21 () ;
F_22 ( & V_23 ) ;
return 0 ;
}
static void F_26 ( struct V_12 * V_27 ,
struct V_12 * V_28 )
{
struct V_21 * V_22 ;
bool V_33 = false ;
F_17 () ;
F_18 (relation, &ptracer_relations, node) {
if ( V_22 -> V_24 )
continue;
if ( V_22 -> V_28 == V_28 ||
( V_27 && V_22 -> V_27 == V_27 ) ) {
V_22 -> V_24 = true ;
V_33 = true ;
}
}
F_21 () ;
if ( V_33 )
F_27 ( & V_34 ) ;
}
void F_28 ( struct V_12 * V_35 )
{
F_26 ( V_35 , V_35 ) ;
}
int F_29 ( int V_36 , unsigned long V_37 , unsigned long V_38 ,
unsigned long V_39 , unsigned long V_40 )
{
int V_41 = - V_42 ;
struct V_12 * V_43 = V_16 ;
switch ( V_36 ) {
case V_44 :
F_17 () ;
if ( ! F_30 ( V_43 ) )
V_43 = F_31 ( V_43 -> V_45 ) ;
F_12 ( V_43 ) ;
F_21 () ;
if ( V_37 == 0 ) {
F_26 ( NULL , V_43 ) ;
V_41 = 0 ;
} else if ( V_37 == V_46 || ( int ) V_37 == - 1 ) {
V_41 = F_23 ( NULL , V_43 ) ;
} else {
struct V_12 * V_27 ;
F_17 () ;
V_27 = F_32 ( V_37 ) ;
if ( V_27 )
F_12 ( V_27 ) ;
else
V_41 = - V_47 ;
F_21 () ;
if ( V_27 ) {
V_41 = F_23 ( V_27 , V_43 ) ;
F_6 ( V_27 ) ;
}
}
F_6 ( V_43 ) ;
break;
}
return V_41 ;
}
static int F_33 ( struct V_12 * V_48 ,
struct V_12 * V_49 )
{
int V_41 = 0 ;
struct V_12 * V_50 = V_49 ;
if ( ! V_48 || ! V_49 )
return 0 ;
F_17 () ;
if ( ! F_30 ( V_48 ) )
V_48 = F_31 ( V_48 -> V_45 ) ;
while ( V_50 -> V_11 > 0 ) {
if ( ! F_30 ( V_50 ) )
V_50 = F_31 ( V_50 -> V_45 ) ;
if ( V_50 == V_48 ) {
V_41 = 1 ;
break;
}
V_50 = F_31 ( V_50 -> V_51 ) ;
}
F_21 () ;
return V_41 ;
}
static int F_34 ( struct V_12 * V_27 ,
struct V_12 * V_28 )
{
int V_41 = 0 ;
struct V_21 * V_22 ;
struct V_12 * V_48 = NULL ;
bool V_52 = false ;
F_17 () ;
if ( ! F_30 ( V_28 ) )
V_28 = F_31 ( V_28 -> V_45 ) ;
F_18 (relation, &ptracer_relations, node) {
if ( V_22 -> V_24 )
continue;
if ( V_22 -> V_28 == V_28 ) {
V_48 = V_22 -> V_27 ;
V_52 = true ;
break;
}
}
if ( V_52 && ( V_48 == NULL || F_33 ( V_48 , V_27 ) ) )
V_41 = 1 ;
F_21 () ;
return V_41 ;
}
static int F_35 ( struct V_12 * V_49 ,
unsigned int V_53 )
{
int V_41 = 0 ;
if ( V_53 & V_54 ) {
switch ( V_55 ) {
case V_56 :
break;
case V_57 :
F_17 () ;
if ( ! F_33 ( V_16 , V_49 ) &&
! F_34 ( V_16 , V_49 ) &&
! F_36 ( F_37 ( V_49 ) -> V_58 , V_59 ) )
V_41 = - V_60 ;
F_21 () ;
break;
case V_61 :
F_17 () ;
if ( ! F_36 ( F_37 ( V_49 ) -> V_58 , V_59 ) )
V_41 = - V_60 ;
F_21 () ;
break;
case V_62 :
default:
V_41 = - V_60 ;
break;
}
}
if ( V_41 && ( V_53 & V_63 ) == 0 )
F_7 ( L_3 , V_49 , V_16 ) ;
return V_41 ;
}
int F_38 ( struct V_12 * V_48 )
{
int V_41 = 0 ;
switch ( V_55 ) {
case V_61 :
if ( ! F_39 ( V_48 , F_40 () , V_59 ) )
V_41 = - V_60 ;
break;
case V_62 :
V_41 = - V_60 ;
break;
}
if ( V_41 ) {
F_41 ( V_16 ) ;
F_7 ( L_4 , V_16 , V_48 ) ;
F_42 ( V_16 ) ;
}
return V_41 ;
}
static int F_43 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_68 , T_3 * V_69 )
{
struct V_64 V_70 ;
if ( V_66 && ! F_44 ( V_59 ) )
return - V_60 ;
V_70 = * V_65 ;
if ( * ( int * ) V_70 . V_71 == * ( int * ) V_70 . V_72 )
V_70 . V_73 = V_70 . V_72 ;
return F_45 ( & V_70 , V_66 , V_67 , V_68 , V_69 ) ;
}
static void T_4 F_46 ( void )
{
if ( ! F_47 ( V_74 , V_75 ) )
F_48 ( L_5 ) ;
}
static inline void F_46 ( void ) { }
void T_4 F_49 ( void )
{
F_50 ( L_6 ) ;
F_51 ( V_76 , F_52 ( V_76 ) ) ;
F_46 () ;
}
