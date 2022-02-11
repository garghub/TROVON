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
static bool F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
F_5 (vma, &obj->vma_list, obj_link)
if ( F_6 ( V_10 ) )
return true ;
return false ;
}
static bool F_7 ( void )
{
return F_8 () > 0 ;
}
static bool F_9 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 . V_12 )
return false ;
if ( V_8 -> V_13 > V_8 -> V_14 )
return false ;
if ( F_4 ( V_8 ) )
return false ;
return F_7 () || V_8 -> V_15 == V_16 ;
}
unsigned long
F_10 ( struct V_17 * V_18 ,
unsigned long V_19 , unsigned V_20 )
{
const struct {
struct V_21 * V_22 ;
unsigned int V_23 ;
} V_24 [] = {
{ & V_18 -> V_25 . V_26 , V_27 } ,
{ & V_18 -> V_25 . V_28 , V_29 } ,
{ NULL , 0 } ,
} , * V_30 ;
unsigned long V_31 = 0 ;
F_11 ( V_18 , V_19 , V_20 ) ;
F_12 ( V_18 ) ;
if ( ( V_20 & V_29 ) &&
! F_13 ( V_18 ) )
V_20 &= ~ V_29 ;
for ( V_30 = V_24 ; V_30 -> V_22 ; V_30 ++ ) {
struct V_21 V_32 ;
struct V_7 * V_8 ;
if ( ( V_20 & V_30 -> V_23 ) == 0 )
continue;
F_14 ( & V_32 ) ;
while ( V_31 < V_19 &&
( V_8 = F_15 ( V_30 -> V_22 ,
F_16 ( * V_8 ) ,
V_33 ) ) ) {
F_17 ( & V_8 -> V_33 , & V_32 ) ;
if ( V_20 & V_34 &&
V_8 -> V_15 != V_16 )
continue;
if ( V_20 & V_35 &&
! F_18 ( V_8 -> V_36 ) )
continue;
if ( ( V_20 & V_37 ) == 0 &&
F_19 ( V_8 ) )
continue;
if ( ! F_9 ( V_8 ) )
continue;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
if ( F_22 ( V_8 ) == 0 )
V_31 += V_8 -> V_11 . V_38 >> V_39 ;
F_23 ( V_8 ) ;
}
F_24 ( & V_32 , V_30 -> V_22 ) ;
}
if ( V_20 & V_29 )
F_25 ( V_18 ) ;
F_12 ( V_18 ) ;
F_26 () ;
return V_31 ;
}
unsigned long F_27 ( struct V_17 * V_18 )
{
unsigned long V_40 ;
V_40 = F_10 ( V_18 , - 1UL ,
V_29 |
V_27 |
V_37 ) ;
F_28 () ;
return V_40 ;
}
static bool F_29 ( struct V_41 * V_42 , bool * V_43 )
{
if ( ! F_30 ( & V_42 -> V_44 ) ) {
if ( ! F_1 ( & V_42 -> V_44 , V_45 ) )
return false ;
* V_43 = false ;
} else
* V_43 = true ;
return true ;
}
static unsigned long
F_31 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_17 * V_18 =
F_32 ( V_46 , struct V_17 , V_25 . V_46 ) ;
struct V_41 * V_42 = & V_18 -> V_49 ;
struct V_7 * V_8 ;
unsigned long V_31 ;
bool V_43 ;
if ( ! F_29 ( V_42 , & V_43 ) )
return 0 ;
F_12 ( V_18 ) ;
V_31 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list)
if ( F_9 ( V_8 ) )
V_31 += V_8 -> V_11 . V_38 >> V_39 ;
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_19 ( V_8 ) && F_9 ( V_8 ) )
V_31 += V_8 -> V_11 . V_38 >> V_39 ;
}
if ( V_43 )
F_33 ( & V_42 -> V_44 ) ;
return V_31 ;
}
static unsigned long
F_34 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_17 * V_18 =
F_32 ( V_46 , struct V_17 , V_25 . V_46 ) ;
struct V_41 * V_42 = & V_18 -> V_49 ;
unsigned long V_40 ;
bool V_43 ;
if ( ! F_29 ( V_42 , & V_43 ) )
return V_50 ;
V_40 = F_10 ( V_18 ,
V_48 -> V_51 ,
V_29 |
V_27 |
V_34 ) ;
if ( V_40 < V_48 -> V_51 )
V_40 += F_10 ( V_18 ,
V_48 -> V_51 - V_40 ,
V_29 |
V_27 ) ;
if ( V_43 )
F_33 ( & V_42 -> V_44 ) ;
return V_40 ;
}
static bool
F_35 ( struct V_17 * V_18 ,
struct V_52 * V_53 ,
int V_54 )
{
unsigned long V_55 = V_56 + F_36 ( V_54 ) ;
do {
if ( F_37 ( V_18 , 0 ) == 0 &&
F_29 ( & V_18 -> V_49 , & V_53 -> V_43 ) )
break;
F_38 ( 1 ) ;
if ( F_39 ( V_45 ) )
return false ;
if ( F_40 ( V_56 , V_55 ) ) {
F_41 ( L_1 ) ;
return false ;
}
} while ( 1 );
V_53 -> V_57 = V_18 -> V_25 . V_58 ;
V_18 -> V_25 . V_58 = false ;
return true ;
}
static void
F_42 ( struct V_17 * V_18 ,
struct V_52 * V_53 )
{
V_18 -> V_25 . V_58 = V_53 -> V_57 ;
if ( V_53 -> V_43 )
F_33 ( & V_18 -> V_49 . V_44 ) ;
}
static int
F_43 ( struct V_59 * V_60 , unsigned long V_61 , void * V_62 )
{
struct V_17 * V_18 =
F_32 ( V_60 , struct V_17 , V_25 . V_63 ) ;
struct V_52 V_53 ;
struct V_7 * V_8 ;
unsigned long V_64 , V_65 , V_66 , V_67 ;
if ( ! F_35 ( V_18 , & V_53 , 5000 ) )
return V_68 ;
F_44 ( V_18 ) ;
V_67 = F_27 ( V_18 ) ;
F_25 ( V_18 ) ;
V_66 = V_65 = V_64 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_64 += V_8 -> V_11 . V_38 >> V_39 ;
else
V_66 += V_8 -> V_11 . V_38 >> V_39 ;
}
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_64 += V_8 -> V_11 . V_38 >> V_39 ;
else
V_65 += V_8 -> V_11 . V_38 >> V_39 ;
}
F_42 ( V_18 , & V_53 ) ;
if ( V_67 || V_66 || V_65 )
F_45 ( L_2
L_3 ,
V_67 , V_64 ) ;
if ( V_66 || V_65 )
F_41 ( L_4
L_5 ,
V_65 , V_66 ) ;
* ( unsigned long * ) V_62 += V_67 ;
return V_68 ;
}
static int
F_46 ( struct V_59 * V_60 , unsigned long V_61 , void * V_62 )
{
struct V_17 * V_18 =
F_32 ( V_60 , struct V_17 , V_25 . V_69 ) ;
struct V_52 V_53 ;
struct V_9 * V_10 , * V_70 ;
unsigned long V_67 = 0 ;
int V_71 ;
if ( ! F_35 ( V_18 , & V_53 , 5000 ) )
return V_68 ;
V_71 = F_37 ( V_18 , V_72 ) ;
if ( V_71 )
goto V_73;
F_44 ( V_18 ) ;
V_67 += F_10 ( V_18 , - 1UL ,
V_29 |
V_27 |
V_37 |
V_35 ) ;
F_25 ( V_18 ) ;
F_47 (vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long V_31 = V_10 -> V_74 . V_38 >> V_39 ;
if ( V_10 -> V_75 && F_48 ( V_10 ) == 0 )
V_67 += V_31 ;
}
V_73:
F_42 ( V_18 , & V_53 ) ;
* ( unsigned long * ) V_62 += V_67 ;
return V_68 ;
}
void F_49 ( struct V_17 * V_18 )
{
V_18 -> V_25 . V_46 . V_76 = F_34 ;
V_18 -> V_25 . V_46 . V_77 = F_31 ;
V_18 -> V_25 . V_46 . V_78 = V_79 ;
F_50 ( F_51 ( & V_18 -> V_25 . V_46 ) ) ;
V_18 -> V_25 . V_63 . V_80 = F_43 ;
F_50 ( F_52 ( & V_18 -> V_25 . V_63 ) ) ;
V_18 -> V_25 . V_69 . V_80 = F_46 ;
F_50 ( F_53 ( & V_18 -> V_25 . V_69 ) ) ;
}
void F_54 ( struct V_17 * V_18 )
{
F_50 ( F_55 ( & V_18 -> V_25 . V_69 ) ) ;
F_50 ( F_56 ( & V_18 -> V_25 . V_63 ) ) ;
F_57 ( & V_18 -> V_25 . V_46 ) ;
}
