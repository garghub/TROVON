static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ! F_2 ( V_1 ) )
return false ;
#if F_3 ( V_4 ) || F_3 ( V_5 )
return V_1 -> V_6 == V_3 ;
#else
return false ;
#endif
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 = 0 ;
F_5 (vma, &obj->vma_list, obj_link) {
if ( F_6 ( & V_10 -> V_12 ) )
V_11 ++ ;
if ( V_10 -> V_13 )
V_11 ++ ;
}
return V_11 ;
}
static bool F_7 ( void )
{
return F_8 () > 0 ;
}
static bool F_9 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_14 . V_15 )
return false ;
if ( V_8 -> V_16 != F_4 ( V_8 ) )
return false ;
return F_7 () || V_8 -> V_17 == V_18 ;
}
unsigned long
F_10 ( struct V_19 * V_20 ,
unsigned long V_21 , unsigned V_22 )
{
const struct {
struct V_23 * V_24 ;
unsigned int V_25 ;
} V_26 [] = {
{ & V_20 -> V_27 . V_28 , V_29 } ,
{ & V_20 -> V_27 . V_30 , V_31 } ,
{ NULL , 0 } ,
} , * V_32 ;
unsigned long V_11 = 0 ;
F_11 ( V_20 , V_21 , V_22 ) ;
F_12 ( V_20 ) ;
if ( ( V_22 & V_31 ) &&
! F_13 ( V_20 ) )
V_22 &= ~ V_31 ;
for ( V_32 = V_26 ; V_32 -> V_24 ; V_32 ++ ) {
struct V_23 V_33 ;
if ( ( V_22 & V_32 -> V_25 ) == 0 )
continue;
F_14 ( & V_33 ) ;
while ( V_11 < V_21 && ! F_15 ( V_32 -> V_24 ) ) {
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_34 ;
V_8 = F_16 ( V_32 -> V_24 ,
F_17 ( * V_8 ) , V_35 ) ;
F_18 ( & V_8 -> V_35 , & V_33 ) ;
if ( V_22 & V_36 &&
V_8 -> V_17 != V_18 )
continue;
if ( V_22 & V_37 &&
! F_19 ( V_8 -> V_38 ) )
continue;
if ( ( V_22 & V_39 ) == 0 && V_8 -> V_40 )
continue;
if ( ! F_9 ( V_8 ) )
continue;
F_20 ( & V_8 -> V_14 ) ;
F_21 (vma, v,
&obj->vma_list, obj_link)
if ( F_22 ( V_10 ) )
break;
if ( F_23 ( V_8 ) == 0 )
V_11 += V_8 -> V_14 . V_41 >> V_42 ;
F_24 ( & V_8 -> V_14 ) ;
}
F_25 ( & V_33 , V_32 -> V_24 ) ;
}
if ( V_22 & V_31 )
F_26 ( V_20 ) ;
F_12 ( V_20 ) ;
return V_11 ;
}
unsigned long F_27 ( struct V_19 * V_20 )
{
return F_10 ( V_20 , - 1UL ,
V_31 |
V_29 |
V_39 ) ;
}
static bool F_28 ( struct V_43 * V_44 , bool * V_45 )
{
if ( ! F_29 ( & V_44 -> V_46 ) ) {
if ( ! F_1 ( & V_44 -> V_46 , V_47 ) )
return false ;
if ( F_30 ( V_44 ) -> V_27 . V_48 )
return false ;
* V_45 = false ;
} else
* V_45 = true ;
return true ;
}
static unsigned long
F_31 ( struct V_49 * V_49 , struct V_50 * V_51 )
{
struct V_19 * V_20 =
F_32 ( V_49 , struct V_19 , V_27 . V_49 ) ;
struct V_43 * V_44 = & V_20 -> V_52 ;
struct V_7 * V_8 ;
unsigned long V_11 ;
bool V_45 ;
if ( ! F_28 ( V_44 , & V_45 ) )
return 0 ;
F_12 ( V_20 ) ;
V_11 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list)
if ( F_9 ( V_8 ) )
V_11 += V_8 -> V_14 . V_41 >> V_42 ;
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_8 -> V_40 && F_9 ( V_8 ) )
V_11 += V_8 -> V_14 . V_41 >> V_42 ;
}
if ( V_45 )
F_33 ( & V_44 -> V_46 ) ;
return V_11 ;
}
static unsigned long
F_34 ( struct V_49 * V_49 , struct V_50 * V_51 )
{
struct V_19 * V_20 =
F_32 ( V_49 , struct V_19 , V_27 . V_49 ) ;
struct V_43 * V_44 = & V_20 -> V_52 ;
unsigned long V_53 ;
bool V_45 ;
if ( ! F_28 ( V_44 , & V_45 ) )
return V_54 ;
V_53 = F_10 ( V_20 ,
V_51 -> V_55 ,
V_31 |
V_29 |
V_36 ) ;
if ( V_53 < V_51 -> V_55 )
V_53 += F_10 ( V_20 ,
V_51 -> V_55 - V_53 ,
V_31 |
V_29 ) ;
if ( V_45 )
F_33 ( & V_44 -> V_46 ) ;
return V_53 ;
}
static bool
F_35 ( struct V_19 * V_20 ,
struct V_56 * V_57 ,
int V_58 )
{
unsigned long V_59 = F_36 ( V_58 ) + 1 ;
while ( ! F_28 ( & V_20 -> V_52 , & V_57 -> V_45 ) ) {
F_37 ( 1 ) ;
if ( F_38 ( V_47 ) )
return false ;
if ( -- V_59 == 0 ) {
F_39 ( L_1 ) ;
return false ;
}
}
V_57 -> V_60 = V_20 -> V_27 . V_61 ;
V_20 -> V_27 . V_61 = false ;
return true ;
}
static void
F_40 ( struct V_19 * V_20 ,
struct V_56 * V_57 )
{
V_20 -> V_27 . V_61 = V_57 -> V_60 ;
if ( V_57 -> V_45 )
F_33 ( & V_20 -> V_52 . V_46 ) ;
}
static int
F_41 ( struct V_62 * V_63 , unsigned long V_64 , void * V_65 )
{
struct V_19 * V_20 =
F_32 ( V_63 , struct V_19 , V_27 . V_66 ) ;
struct V_56 V_57 ;
struct V_7 * V_8 ;
unsigned long V_67 , V_68 , V_69 , V_70 ;
if ( ! F_35 ( V_20 , & V_57 , 5000 ) )
return V_71 ;
F_42 ( V_20 ) ;
V_70 = F_27 ( V_20 ) ;
F_26 ( V_20 ) ;
V_69 = V_68 = V_67 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_67 += V_8 -> V_14 . V_41 >> V_42 ;
else
V_69 += V_8 -> V_14 . V_41 >> V_42 ;
}
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_67 += V_8 -> V_14 . V_41 >> V_42 ;
else
V_68 += V_8 -> V_14 . V_41 >> V_42 ;
}
F_40 ( V_20 , & V_57 ) ;
if ( V_70 || V_69 || V_68 )
F_43 ( L_2
L_3 ,
V_70 , V_67 ) ;
if ( V_69 || V_68 )
F_39 ( L_4
L_5 ,
V_68 , V_69 ) ;
* ( unsigned long * ) V_65 += V_70 ;
return V_71 ;
}
static int
F_44 ( struct V_62 * V_63 , unsigned long V_64 , void * V_65 )
{
struct V_19 * V_20 =
F_32 ( V_63 , struct V_19 , V_27 . V_72 ) ;
struct V_56 V_57 ;
struct V_9 * V_10 , * V_73 ;
unsigned long V_70 = 0 ;
int V_74 ;
if ( ! F_35 ( V_20 , & V_57 , 5000 ) )
return V_71 ;
V_74 = F_45 ( V_20 ) ;
if ( V_74 )
goto V_75;
F_42 ( V_20 ) ;
V_70 += F_10 ( V_20 , - 1UL ,
V_31 |
V_29 |
V_39 |
V_37 ) ;
F_26 ( V_20 ) ;
F_21 (vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long V_11 = V_10 -> V_12 . V_41 >> V_42 ;
if ( V_10 -> V_76 && F_22 ( V_10 ) == 0 )
V_70 += V_11 ;
}
V_75:
F_40 ( V_20 , & V_57 ) ;
* ( unsigned long * ) V_65 += V_70 ;
return V_71 ;
}
void F_46 ( struct V_19 * V_20 )
{
V_20 -> V_27 . V_49 . V_77 = F_34 ;
V_20 -> V_27 . V_49 . V_78 = F_31 ;
V_20 -> V_27 . V_49 . V_79 = V_80 ;
F_47 ( F_48 ( & V_20 -> V_27 . V_49 ) ) ;
V_20 -> V_27 . V_66 . V_81 = F_41 ;
F_47 ( F_49 ( & V_20 -> V_27 . V_66 ) ) ;
V_20 -> V_27 . V_72 . V_81 = F_44 ;
F_47 ( F_50 ( & V_20 -> V_27 . V_72 ) ) ;
}
void F_51 ( struct V_19 * V_20 )
{
F_47 ( F_52 ( & V_20 -> V_27 . V_72 ) ) ;
F_47 ( F_53 ( & V_20 -> V_27 . V_66 ) ) ;
F_54 ( & V_20 -> V_27 . V_49 ) ;
}
