static bool F_1 ( struct V_1 * V_2 , bool * V_3 )
{
switch ( F_2 ( & V_2 -> V_4 ) ) {
case V_5 :
return false ;
case V_6 :
* V_3 = true ;
return true ;
case V_7 :
* V_3 = false ;
return true ;
}
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_3 )
return;
F_5 ( & V_2 -> V_4 ) ;
F_6 () ;
}
static bool F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
F_8 (vma, &obj->vma_list, obj_link)
if ( F_9 ( V_11 ) )
return true ;
return false ;
}
static bool F_10 ( void )
{
return F_11 () > 0 ;
}
static bool F_12 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_12 . V_13 )
return false ;
if ( ! F_13 ( V_9 ) )
return false ;
if ( F_14 ( & V_9 -> V_12 . V_14 ) > V_9 -> V_15 )
return false ;
if ( F_7 ( V_9 ) )
return false ;
return F_10 () || V_9 -> V_12 . V_16 == V_17 ;
}
static bool F_15 ( struct V_8 * V_9 )
{
if ( F_16 ( V_9 ) == 0 )
F_17 ( V_9 , V_18 ) ;
return ! F_18 ( V_9 -> V_12 . V_13 ) ;
}
unsigned long
F_19 ( struct V_19 * V_20 ,
unsigned long V_21 , unsigned V_22 )
{
const struct {
struct V_23 * V_24 ;
unsigned int V_25 ;
} V_26 [] = {
{ & V_20 -> V_12 . V_27 , V_28 } ,
{ & V_20 -> V_12 . V_29 , V_30 } ,
{ NULL , 0 } ,
} , * V_31 ;
unsigned long V_32 = 0 ;
bool V_3 ;
if ( ! F_1 ( & V_20 -> V_33 , & V_3 ) )
return 0 ;
F_20 ( V_20 , V_21 , V_22 ) ;
F_21 ( V_20 ) ;
if ( ( V_22 & V_30 ) &&
! F_22 ( V_20 ) )
V_22 &= ~ V_30 ;
for ( V_31 = V_26 ; V_31 -> V_24 ; V_31 ++ ) {
struct V_23 V_34 ;
struct V_8 * V_9 ;
if ( ( V_22 & V_31 -> V_25 ) == 0 )
continue;
F_23 ( & V_34 ) ;
while ( V_32 < V_21 &&
( V_9 = F_24 ( V_31 -> V_24 ,
F_25 ( * V_9 ) ,
V_35 ) ) ) {
F_26 ( & V_9 -> V_35 , & V_34 ) ;
if ( ! V_9 -> V_12 . V_13 ) {
F_27 ( & V_9 -> V_35 ) ;
continue;
}
if ( V_22 & V_36 &&
V_9 -> V_12 . V_16 != V_17 )
continue;
if ( V_22 & V_37 &&
! F_28 ( V_9 -> V_12 . V_38 ) )
continue;
if ( ! ( V_22 & V_39 ) &&
( F_29 ( V_9 ) ||
V_9 -> V_40 ) )
continue;
if ( ! F_12 ( V_9 ) )
continue;
if ( F_15 ( V_9 ) ) {
F_30 ( & V_9 -> V_12 . V_41 ,
V_18 ) ;
if ( ! V_9 -> V_12 . V_13 ) {
F_31 ( V_9 ) ;
F_27 ( & V_9 -> V_35 ) ;
V_32 += V_9 -> V_42 . V_43 >> V_44 ;
}
F_5 ( & V_9 -> V_12 . V_41 ) ;
}
}
F_32 ( & V_34 , V_31 -> V_24 ) ;
}
if ( V_22 & V_30 )
F_33 ( V_20 ) ;
F_21 ( V_20 ) ;
F_4 ( & V_20 -> V_33 , V_3 ) ;
return V_32 ;
}
unsigned long F_34 ( struct V_19 * V_20 )
{
unsigned long V_45 ;
V_45 = F_19 ( V_20 , - 1UL ,
V_30 |
V_28 |
V_39 ) ;
F_35 () ;
return V_45 ;
}
static unsigned long
F_36 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_19 * V_20 =
F_37 ( V_46 , struct V_19 , V_12 . V_46 ) ;
struct V_1 * V_2 = & V_20 -> V_33 ;
struct V_8 * V_9 ;
unsigned long V_32 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_21 ( V_20 ) ;
V_32 = 0 ;
F_8 (obj, &dev_priv->mm.unbound_list, global_link)
if ( F_12 ( V_9 ) )
V_32 += V_9 -> V_42 . V_43 >> V_44 ;
F_8 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! F_29 ( V_9 ) && F_12 ( V_9 ) )
V_32 += V_9 -> V_42 . V_43 >> V_44 ;
}
F_4 ( V_2 , V_3 ) ;
return V_32 ;
}
static unsigned long
F_38 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_19 * V_20 =
F_37 ( V_46 , struct V_19 , V_12 . V_46 ) ;
struct V_1 * V_2 = & V_20 -> V_33 ;
unsigned long V_45 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return V_49 ;
V_45 = F_19 ( V_20 ,
V_48 -> V_50 ,
V_30 |
V_28 |
V_36 ) ;
if ( V_45 < V_48 -> V_50 )
V_45 += F_19 ( V_20 ,
V_48 -> V_50 - V_45 ,
V_30 |
V_28 ) ;
F_4 ( V_2 , V_3 ) ;
return V_45 ;
}
static bool
F_39 ( struct V_19 * V_20 ,
struct V_51 * V_52 ,
int V_53 )
{
unsigned long V_54 = V_55 + F_40 ( V_53 ) ;
do {
if ( F_41 ( V_20 , 0 ) == 0 &&
F_1 ( & V_20 -> V_33 , & V_52 -> V_3 ) )
break;
F_42 ( 1 ) ;
if ( F_43 ( V_56 ) )
return false ;
if ( F_44 ( V_55 , V_54 ) ) {
F_45 ( L_1 ) ;
return false ;
}
} while ( 1 );
V_52 -> V_57 = V_20 -> V_12 . V_58 ;
V_20 -> V_12 . V_58 = false ;
return true ;
}
static void
F_46 ( struct V_19 * V_20 ,
struct V_51 * V_52 )
{
V_20 -> V_12 . V_58 = V_52 -> V_57 ;
F_4 ( & V_20 -> V_33 , V_52 -> V_3 ) ;
}
static int
F_47 ( struct V_59 * V_60 , unsigned long V_61 , void * V_62 )
{
struct V_19 * V_20 =
F_37 ( V_60 , struct V_19 , V_12 . V_63 ) ;
struct V_51 V_52 ;
struct V_8 * V_9 ;
unsigned long V_64 , V_65 , V_66 , V_67 ;
if ( ! F_39 ( V_20 , & V_52 , 5000 ) )
return V_68 ;
F_48 ( V_20 ) ;
V_67 = F_34 ( V_20 ) ;
F_33 ( V_20 ) ;
V_66 = V_65 = V_64 = 0 ;
F_8 (obj, &dev_priv->mm.unbound_list, global_link) {
if ( ! V_9 -> V_12 . V_13 )
continue;
if ( ! F_12 ( V_9 ) )
V_64 += V_9 -> V_42 . V_43 >> V_44 ;
else
V_66 += V_9 -> V_42 . V_43 >> V_44 ;
}
F_8 (obj, &dev_priv->mm.bound_list, global_link) {
if ( ! V_9 -> V_12 . V_13 )
continue;
if ( ! F_12 ( V_9 ) )
V_64 += V_9 -> V_42 . V_43 >> V_44 ;
else
V_65 += V_9 -> V_42 . V_43 >> V_44 ;
}
F_46 ( V_20 , & V_52 ) ;
if ( V_67 || V_66 || V_65 )
F_49 ( L_2
L_3 ,
V_67 , V_64 ) ;
if ( V_66 || V_65 )
F_45 ( L_4
L_5 ,
V_65 , V_66 ) ;
* ( unsigned long * ) V_62 += V_67 ;
return V_68 ;
}
static int
F_50 ( struct V_59 * V_60 , unsigned long V_61 , void * V_62 )
{
struct V_19 * V_20 =
F_37 ( V_60 , struct V_19 , V_12 . V_69 ) ;
struct V_51 V_52 ;
struct V_10 * V_11 , * V_70 ;
unsigned long V_67 = 0 ;
int V_71 ;
if ( ! F_39 ( V_20 , & V_52 , 5000 ) )
return V_68 ;
V_71 = F_41 ( V_20 , V_72 ) ;
if ( V_71 )
goto V_73;
F_48 ( V_20 ) ;
V_67 += F_19 ( V_20 , - 1UL ,
V_30 |
V_28 |
V_39 |
V_37 ) ;
F_33 ( V_20 ) ;
F_51 (vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long V_32 = V_11 -> V_74 . V_43 >> V_44 ;
if ( V_11 -> V_75 && F_52 ( V_11 ) == 0 )
V_67 += V_32 ;
}
V_73:
F_46 ( V_20 , & V_52 ) ;
* ( unsigned long * ) V_62 += V_67 ;
return V_68 ;
}
void F_53 ( struct V_19 * V_20 )
{
V_20 -> V_12 . V_46 . V_76 = F_38 ;
V_20 -> V_12 . V_46 . V_77 = F_36 ;
V_20 -> V_12 . V_46 . V_78 = V_79 ;
F_54 ( F_55 ( & V_20 -> V_12 . V_46 ) ) ;
V_20 -> V_12 . V_63 . V_80 = F_47 ;
F_54 ( F_56 ( & V_20 -> V_12 . V_63 ) ) ;
V_20 -> V_12 . V_69 . V_80 = F_50 ;
F_54 ( F_57 ( & V_20 -> V_12 . V_69 ) ) ;
}
void F_58 ( struct V_19 * V_20 )
{
F_54 ( F_59 ( & V_20 -> V_12 . V_69 ) ) ;
F_54 ( F_60 ( & V_20 -> V_12 . V_63 ) ) ;
F_61 ( & V_20 -> V_12 . V_46 ) ;
}
