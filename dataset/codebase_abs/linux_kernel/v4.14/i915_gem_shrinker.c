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
unsigned long V_20 ,
unsigned long * V_21 ,
unsigned V_22 )
{
const struct {
struct V_23 * V_24 ;
unsigned int V_25 ;
} V_26 [] = {
{ & V_2 -> V_13 . V_27 , V_28 } ,
{ & V_2 -> V_13 . V_29 , V_30 } ,
{ NULL , 0 } ,
} , * V_31 ;
unsigned long V_32 = 0 ;
unsigned long V_33 = 0 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_25 ( V_2 , V_20 , V_22 ) ;
F_26 ( V_2 ) ;
if ( ( V_22 & V_30 ) &&
! F_27 ( V_2 ) )
V_22 &= ~ V_30 ;
for ( V_31 = V_26 ; V_31 -> V_24 ; V_31 ++ ) {
struct V_23 V_34 ;
struct V_9 * V_10 ;
if ( ( V_22 & V_31 -> V_25 ) == 0 )
continue;
F_28 ( & V_34 ) ;
while ( V_32 < V_20 &&
( V_10 = F_29 ( V_31 -> V_24 ,
F_30 ( * V_10 ) ,
V_35 ) ) ) {
F_31 ( & V_10 -> V_35 , & V_34 ) ;
if ( ! V_10 -> V_13 . V_14 ) {
F_32 ( & V_10 -> V_35 ) ;
continue;
}
if ( V_22 & V_36 &&
V_10 -> V_13 . V_17 != V_18 )
continue;
if ( V_22 & V_37 &&
! F_33 ( V_10 -> V_13 . V_38 ) )
continue;
if ( ! ( V_22 & V_39 ) &&
( F_34 ( V_10 ) ||
F_35 ( V_10 ) ) )
continue;
if ( ! F_17 ( V_10 ) )
continue;
if ( F_20 ( V_10 ) ) {
F_36 ( & V_10 -> V_13 . V_40 ,
V_19 ) ;
if ( ! V_10 -> V_13 . V_14 ) {
F_37 ( V_10 ) ;
F_32 ( & V_10 -> V_35 ) ;
V_32 += V_10 -> V_41 . V_42 >> V_43 ;
}
F_10 ( & V_10 -> V_13 . V_40 ) ;
V_33 += V_10 -> V_41 . V_42 >> V_43 ;
}
}
F_38 ( & V_34 , V_31 -> V_24 ) ;
}
if ( V_22 & V_30 )
F_39 ( V_2 ) ;
F_26 ( V_2 ) ;
F_9 ( V_2 , V_3 ) ;
if ( V_21 )
* V_21 += V_33 ;
return V_32 ;
}
unsigned long F_40 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_41 ( V_2 ) ;
V_44 = F_24 ( V_2 , - 1UL , NULL ,
V_30 |
V_28 |
V_39 ) ;
F_39 ( V_2 ) ;
return V_44 ;
}
static unsigned long
F_42 ( struct V_45 * V_45 , struct V_46 * V_47 )
{
struct V_1 * V_2 =
F_43 ( V_45 , struct V_1 , V_13 . V_45 ) ;
struct V_9 * V_10 ;
unsigned long V_32 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_26 ( V_2 ) ;
V_32 = 0 ;
F_12 (obj, &dev_priv->mm.unbound_list, global_link)
if ( F_17 ( V_10 ) )
V_32 += V_10 -> V_41 . V_42 >> V_43 ;
F_12 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! F_34 ( V_10 ) && F_17 ( V_10 ) )
V_32 += V_10 -> V_41 . V_42 >> V_43 ;
}
F_9 ( V_2 , V_3 ) ;
return V_32 ;
}
static unsigned long
F_44 ( struct V_45 * V_45 , struct V_46 * V_47 )
{
struct V_1 * V_2 =
F_43 ( V_45 , struct V_1 , V_13 . V_45 ) ;
unsigned long V_44 ;
bool V_3 ;
V_47 -> V_21 = 0 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return V_48 ;
V_44 = F_24 ( V_2 ,
V_47 -> V_49 ,
& V_47 -> V_21 ,
V_30 |
V_28 |
V_36 ) ;
if ( V_44 < V_47 -> V_49 )
V_44 += F_24 ( V_2 ,
V_47 -> V_49 - V_47 -> V_21 ,
& V_47 -> V_21 ,
V_30 |
V_28 ) ;
if ( V_44 < V_47 -> V_49 && F_45 () ) {
F_41 ( V_2 ) ;
V_44 += F_24 ( V_2 ,
V_47 -> V_49 - V_47 -> V_21 ,
& V_47 -> V_21 ,
V_39 |
V_30 |
V_28 ) ;
F_39 ( V_2 ) ;
}
F_9 ( V_2 , V_3 ) ;
return V_47 -> V_21 ? V_44 : V_48 ;
}
static bool
F_46 ( struct V_1 * V_2 , bool * V_3 ,
int V_50 )
{
unsigned long V_51 = V_52 + F_47 ( V_50 ) ;
do {
if ( F_48 ( V_2 , 0 ) == 0 &&
F_1 ( V_2 , V_3 ) )
break;
F_49 ( 1 ) ;
if ( F_50 ( V_53 ) )
return false ;
if ( F_51 ( V_52 , V_51 ) ) {
F_52 ( L_1 ) ;
return false ;
}
} while ( 1 );
return true ;
}
static int
F_53 ( struct V_54 * V_55 , unsigned long V_56 , void * V_57 )
{
struct V_1 * V_2 =
F_43 ( V_55 , struct V_1 , V_13 . V_58 ) ;
struct V_9 * V_10 ;
unsigned long V_59 , V_60 , V_61 , V_62 ;
bool V_3 ;
if ( ! F_46 ( V_2 , & V_3 , 5000 ) )
return V_63 ;
V_62 = F_40 ( V_2 ) ;
V_61 = V_60 = V_59 = 0 ;
F_12 (obj, &dev_priv->mm.unbound_list, global_link) {
if ( ! V_10 -> V_13 . V_14 )
continue;
if ( ! F_17 ( V_10 ) )
V_59 += V_10 -> V_41 . V_42 >> V_43 ;
else
V_61 += V_10 -> V_41 . V_42 >> V_43 ;
}
F_12 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! V_10 -> V_13 . V_14 )
continue;
if ( ! F_17 ( V_10 ) )
V_59 += V_10 -> V_41 . V_42 >> V_43 ;
else
V_60 += V_10 -> V_41 . V_42 >> V_43 ;
}
F_9 ( V_2 , V_3 ) ;
if ( V_62 || V_61 || V_60 )
F_54 ( L_2
L_3 ,
V_62 , V_59 ) ;
if ( V_61 || V_60 )
F_52 ( L_4
L_5 ,
V_60 , V_61 ) ;
* ( unsigned long * ) V_57 += V_62 ;
return V_63 ;
}
static int
F_55 ( struct V_54 * V_55 , unsigned long V_56 , void * V_57 )
{
struct V_1 * V_2 =
F_43 ( V_55 , struct V_1 , V_13 . V_64 ) ;
struct V_11 * V_12 , * V_65 ;
unsigned long V_62 = 0 ;
bool V_3 ;
int V_66 ;
if ( ! F_46 ( V_2 , & V_3 , 5000 ) )
return V_63 ;
V_66 = F_48 ( V_2 , V_67 ) ;
if ( V_66 )
goto V_68;
F_41 ( V_2 ) ;
V_62 += F_24 ( V_2 , - 1UL , NULL ,
V_30 |
V_28 |
V_39 |
V_37 ) ;
F_39 ( V_2 ) ;
F_56 (vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long V_32 = V_12 -> V_69 . V_42 >> V_43 ;
if ( V_12 -> V_70 && F_57 ( V_12 ) == 0 )
V_62 += V_32 ;
}
V_68:
F_9 ( V_2 , V_3 ) ;
* ( unsigned long * ) V_57 += V_62 ;
return V_63 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_13 . V_45 . V_71 = F_44 ;
V_2 -> V_13 . V_45 . V_72 = F_42 ;
V_2 -> V_13 . V_45 . V_73 = V_74 ;
F_59 ( F_60 ( & V_2 -> V_13 . V_45 ) ) ;
V_2 -> V_13 . V_58 . V_75 = F_53 ;
F_59 ( F_61 ( & V_2 -> V_13 . V_58 ) ) ;
V_2 -> V_13 . V_64 . V_75 = F_55 ;
F_59 ( F_62 ( & V_2 -> V_13 . V_64 ) ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_59 ( F_64 ( & V_2 -> V_13 . V_64 ) ) ;
F_59 ( F_65 ( & V_2 -> V_13 . V_58 ) ) ;
F_66 ( & V_2 -> V_13 . V_45 ) ;
}
