static bool F_1 ( struct V_1 * V_2 , bool * V_3 )
{
switch ( F_2 ( & V_2 -> V_4 . V_5 ) ) {
case V_6 :
* V_3 = false ;
return true ;
case V_7 :
* V_3 = false ;
F_3 () ;
do {
F_4 () ;
if ( F_5 ( & V_2 -> V_4 . V_5 ) ) {
* V_3 = true ;
break;
}
} while ( ! F_6 () );
F_7 () ;
return * V_3 ;
case V_8 :
* V_3 = true ;
return true ;
}
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_3 )
return;
F_10 ( & V_2 -> V_4 . V_5 ) ;
}
static bool F_11 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
F_12 (vma, &obj->vma_list, obj_link) {
if ( ! F_13 ( V_12 ) )
break;
if ( F_14 ( V_12 ) )
return true ;
}
return false ;
}
static bool F_15 ( void )
{
return F_16 () > 0 ;
}
static bool F_17 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_13 . V_14 )
return false ;
if ( ! F_18 ( V_10 ) )
return false ;
if ( F_19 ( & V_10 -> V_13 . V_15 ) > V_10 -> V_16 )
return false ;
if ( F_11 ( V_10 ) )
return false ;
return F_15 () || V_10 -> V_13 . V_17 == V_18 ;
}
static bool F_20 ( struct V_9 * V_10 )
{
if ( F_21 ( V_10 ) == 0 )
F_22 ( V_10 , V_19 ) ;
return ! F_23 ( V_10 -> V_13 . V_14 ) ;
}
unsigned long
F_24 ( struct V_1 * V_2 ,
unsigned long V_20 , unsigned V_21 )
{
const struct {
struct V_22 * V_23 ;
unsigned int V_24 ;
} V_25 [] = {
{ & V_2 -> V_13 . V_26 , V_27 } ,
{ & V_2 -> V_13 . V_28 , V_29 } ,
{ NULL , 0 } ,
} , * V_30 ;
unsigned long V_31 = 0 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_25 ( V_2 , V_20 , V_21 ) ;
F_26 ( V_2 ) ;
if ( ( V_21 & V_29 ) &&
! F_27 ( V_2 ) )
V_21 &= ~ V_29 ;
for ( V_30 = V_25 ; V_30 -> V_23 ; V_30 ++ ) {
struct V_22 V_32 ;
struct V_9 * V_10 ;
if ( ( V_21 & V_30 -> V_24 ) == 0 )
continue;
F_28 ( & V_32 ) ;
while ( V_31 < V_20 &&
( V_10 = F_29 ( V_30 -> V_23 ,
F_30 ( * V_10 ) ,
V_33 ) ) ) {
F_31 ( & V_10 -> V_33 , & V_32 ) ;
if ( ! V_10 -> V_13 . V_14 ) {
F_32 ( & V_10 -> V_33 ) ;
continue;
}
if ( V_21 & V_34 &&
V_10 -> V_13 . V_17 != V_18 )
continue;
if ( V_21 & V_35 &&
! F_33 ( V_10 -> V_13 . V_36 ) )
continue;
if ( ! ( V_21 & V_37 ) &&
( F_34 ( V_10 ) ||
F_35 ( V_10 ) ) )
continue;
if ( ! F_17 ( V_10 ) )
continue;
if ( F_20 ( V_10 ) ) {
F_36 ( & V_10 -> V_13 . V_38 ,
V_19 ) ;
if ( ! V_10 -> V_13 . V_14 ) {
F_37 ( V_10 ) ;
F_32 ( & V_10 -> V_33 ) ;
V_31 += V_10 -> V_39 . V_40 >> V_41 ;
}
F_10 ( & V_10 -> V_13 . V_38 ) ;
}
}
F_38 ( & V_32 , V_30 -> V_23 ) ;
}
if ( V_21 & V_29 )
F_39 ( V_2 ) ;
F_26 ( V_2 ) ;
F_9 ( V_2 , V_3 ) ;
return V_31 ;
}
unsigned long F_40 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
F_41 ( V_2 ) ;
V_42 = F_24 ( V_2 , - 1UL ,
V_29 |
V_27 |
V_37 ) ;
F_39 ( V_2 ) ;
return V_42 ;
}
static unsigned long
F_42 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 =
F_43 ( V_43 , struct V_1 , V_13 . V_43 ) ;
struct V_9 * V_10 ;
unsigned long V_31 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_26 ( V_2 ) ;
V_31 = 0 ;
F_12 (obj, &dev_priv->mm.unbound_list, global_link)
if ( F_17 ( V_10 ) )
V_31 += V_10 -> V_39 . V_40 >> V_41 ;
F_12 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! F_34 ( V_10 ) && F_17 ( V_10 ) )
V_31 += V_10 -> V_39 . V_40 >> V_41 ;
}
F_9 ( V_2 , V_3 ) ;
return V_31 ;
}
static unsigned long
F_44 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 =
F_43 ( V_43 , struct V_1 , V_13 . V_43 ) ;
unsigned long V_42 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return V_46 ;
V_42 = F_24 ( V_2 ,
V_45 -> V_47 ,
V_29 |
V_27 |
V_34 ) ;
if ( V_42 < V_45 -> V_47 )
V_42 += F_24 ( V_2 ,
V_45 -> V_47 - V_42 ,
V_29 |
V_27 ) ;
if ( V_42 < V_45 -> V_47 && F_45 () ) {
F_41 ( V_2 ) ;
V_42 += F_24 ( V_2 ,
V_45 -> V_47 - V_42 ,
V_37 |
V_29 |
V_27 ) ;
F_39 ( V_2 ) ;
}
F_9 ( V_2 , V_3 ) ;
return V_42 ;
}
static bool
F_46 ( struct V_1 * V_2 , bool * V_3 ,
int V_48 )
{
unsigned long V_49 = V_50 + F_47 ( V_48 ) ;
do {
if ( F_48 ( V_2 , 0 ) == 0 &&
F_1 ( V_2 , V_3 ) )
break;
F_49 ( 1 ) ;
if ( F_50 ( V_51 ) )
return false ;
if ( F_51 ( V_50 , V_49 ) ) {
F_52 ( L_1 ) ;
return false ;
}
} while ( 1 );
return true ;
}
static int
F_53 ( struct V_52 * V_53 , unsigned long V_54 , void * V_55 )
{
struct V_1 * V_2 =
F_43 ( V_53 , struct V_1 , V_13 . V_56 ) ;
struct V_9 * V_10 ;
unsigned long V_57 , V_58 , V_59 , V_60 ;
bool V_3 ;
if ( ! F_46 ( V_2 , & V_3 , 5000 ) )
return V_61 ;
V_60 = F_40 ( V_2 ) ;
V_59 = V_58 = V_57 = 0 ;
F_12 (obj, &dev_priv->mm.unbound_list, global_link) {
if ( ! V_10 -> V_13 . V_14 )
continue;
if ( ! F_17 ( V_10 ) )
V_57 += V_10 -> V_39 . V_40 >> V_41 ;
else
V_59 += V_10 -> V_39 . V_40 >> V_41 ;
}
F_12 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! V_10 -> V_13 . V_14 )
continue;
if ( ! F_17 ( V_10 ) )
V_57 += V_10 -> V_39 . V_40 >> V_41 ;
else
V_58 += V_10 -> V_39 . V_40 >> V_41 ;
}
F_9 ( V_2 , V_3 ) ;
if ( V_60 || V_59 || V_58 )
F_54 ( L_2
L_3 ,
V_60 , V_57 ) ;
if ( V_59 || V_58 )
F_52 ( L_4
L_5 ,
V_58 , V_59 ) ;
* ( unsigned long * ) V_55 += V_60 ;
return V_61 ;
}
static int
F_55 ( struct V_52 * V_53 , unsigned long V_54 , void * V_55 )
{
struct V_1 * V_2 =
F_43 ( V_53 , struct V_1 , V_13 . V_62 ) ;
struct V_11 * V_12 , * V_63 ;
unsigned long V_60 = 0 ;
bool V_3 ;
int V_64 ;
if ( ! F_46 ( V_2 , & V_3 , 5000 ) )
return V_61 ;
V_64 = F_48 ( V_2 , V_65 ) ;
if ( V_64 )
goto V_66;
F_41 ( V_2 ) ;
V_60 += F_24 ( V_2 , - 1UL ,
V_29 |
V_27 |
V_37 |
V_35 ) ;
F_39 ( V_2 ) ;
F_56 (vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long V_31 = V_12 -> V_67 . V_40 >> V_41 ;
if ( V_12 -> V_68 && F_57 ( V_12 ) == 0 )
V_60 += V_31 ;
}
V_66:
F_9 ( V_2 , V_3 ) ;
* ( unsigned long * ) V_55 += V_60 ;
return V_61 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_13 . V_43 . V_69 = F_44 ;
V_2 -> V_13 . V_43 . V_70 = F_42 ;
V_2 -> V_13 . V_43 . V_71 = V_72 ;
F_59 ( F_60 ( & V_2 -> V_13 . V_43 ) ) ;
V_2 -> V_13 . V_56 . V_73 = F_53 ;
F_59 ( F_61 ( & V_2 -> V_13 . V_56 ) ) ;
V_2 -> V_13 . V_62 . V_73 = F_55 ;
F_59 ( F_62 ( & V_2 -> V_13 . V_62 ) ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_59 ( F_64 ( & V_2 -> V_13 . V_62 ) ) ;
F_59 ( F_65 ( & V_2 -> V_13 . V_56 ) ) ;
F_66 ( & V_2 -> V_13 . V_43 ) ;
}
