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
unsigned long
F_4 ( struct V_7 * V_8 ,
long V_9 , unsigned V_10 )
{
const struct {
struct V_11 * V_12 ;
unsigned int V_13 ;
} V_14 [] = {
{ & V_8 -> V_15 . V_16 , V_17 } ,
{ & V_8 -> V_15 . V_18 , V_19 } ,
{ NULL , 0 } ,
} , * V_20 ;
unsigned long V_21 = 0 ;
for ( V_20 = V_14 ; V_20 -> V_12 ; V_20 ++ ) {
struct V_11 V_22 ;
if ( ( V_10 & V_20 -> V_13 ) == 0 )
continue;
F_5 ( & V_22 ) ;
while ( V_21 < V_9 && ! F_6 ( V_20 -> V_12 ) ) {
struct V_23 * V_24 ;
struct V_25 * V_26 , * V_27 ;
V_24 = F_7 ( V_20 -> V_12 ,
F_8 ( * V_24 ) , V_28 ) ;
F_9 ( & V_24 -> V_28 , & V_22 ) ;
if ( V_10 & V_29 &&
V_24 -> V_30 != V_31 )
continue;
F_10 ( & V_24 -> V_32 ) ;
F_11 (vma, v,
&obj->vma_list, vma_link)
if ( F_12 ( V_26 ) )
break;
if ( F_13 ( V_24 ) == 0 )
V_21 += V_24 -> V_32 . V_33 >> V_34 ;
F_14 ( & V_24 -> V_32 ) ;
}
F_15 ( & V_22 , V_20 -> V_12 ) ;
}
return V_21 ;
}
unsigned long F_16 ( struct V_7 * V_8 )
{
F_17 ( V_8 -> V_35 ) ;
return F_4 ( V_8 , V_36 ,
V_19 | V_17 ) ;
}
static bool F_18 ( struct V_37 * V_35 , bool * V_38 )
{
if ( ! F_19 ( & V_35 -> V_39 ) ) {
if ( ! F_1 ( & V_35 -> V_39 , V_40 ) )
return false ;
if ( F_20 ( V_35 ) -> V_15 . V_41 )
return false ;
* V_38 = false ;
} else
* V_38 = true ;
return true ;
}
static int F_21 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
int V_21 = 0 ;
F_22 (vma, &obj->vma_list, vma_link)
if ( F_23 ( & V_26 -> V_42 ) )
V_21 ++ ;
return V_21 ;
}
static unsigned long
F_24 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_7 * V_8 =
F_25 ( V_43 , struct V_7 , V_15 . V_43 ) ;
struct V_37 * V_35 = V_8 -> V_35 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
bool V_38 ;
if ( ! F_18 ( V_35 , & V_38 ) )
return 0 ;
V_21 = 0 ;
F_22 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_24 -> V_46 == 0 )
V_21 += V_24 -> V_32 . V_33 >> V_34 ;
F_22 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_26 ( V_24 ) &&
V_24 -> V_46 == F_21 ( V_24 ) )
V_21 += V_24 -> V_32 . V_33 >> V_34 ;
}
if ( V_38 )
F_27 ( & V_35 -> V_39 ) ;
return V_21 ;
}
static unsigned long
F_28 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
struct V_7 * V_8 =
F_25 ( V_43 , struct V_7 , V_15 . V_43 ) ;
struct V_37 * V_35 = V_8 -> V_35 ;
unsigned long V_47 ;
bool V_38 ;
if ( ! F_18 ( V_35 , & V_38 ) )
return V_48 ;
V_47 = F_4 ( V_8 ,
V_45 -> V_49 ,
V_19 |
V_17 |
V_29 ) ;
if ( V_47 < V_45 -> V_49 )
V_47 += F_4 ( V_8 ,
V_45 -> V_49 - V_47 ,
V_19 |
V_17 ) ;
if ( V_38 )
F_27 ( & V_35 -> V_39 ) ;
return V_47 ;
}
static int
F_29 ( struct V_50 * V_51 , unsigned long V_52 , void * V_53 )
{
struct V_7 * V_8 =
F_25 ( V_51 , struct V_7 , V_15 . V_54 ) ;
struct V_37 * V_35 = V_8 -> V_35 ;
struct V_23 * V_24 ;
unsigned long V_55 = F_30 ( 5000 ) + 1 ;
unsigned long V_56 , V_57 , V_58 , V_59 ;
bool V_60 ;
bool V_38 ;
while ( ! F_18 ( V_35 , & V_38 ) && -- V_55 ) {
F_31 ( 1 ) ;
if ( F_32 ( V_40 ) )
return V_61 ;
}
if ( V_55 == 0 ) {
F_33 ( L_1 ) ;
return V_61 ;
}
V_60 = V_8 -> V_15 . V_62 ;
V_8 -> V_15 . V_62 = false ;
V_59 = F_16 ( V_8 ) ;
V_8 -> V_15 . V_62 = V_60 ;
V_58 = V_57 = V_56 = 0 ;
F_22 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_24 -> V_32 . V_63 )
continue;
if ( V_24 -> V_46 )
V_56 += V_24 -> V_32 . V_33 ;
else
V_58 += V_24 -> V_32 . V_33 ;
}
F_22 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_24 -> V_32 . V_63 )
continue;
if ( V_24 -> V_46 )
V_56 += V_24 -> V_32 . V_33 ;
else
V_57 += V_24 -> V_32 . V_33 ;
}
if ( V_38 )
F_27 ( & V_35 -> V_39 ) ;
if ( V_59 || V_58 || V_57 )
F_34 ( L_2 ,
V_59 << V_34 , V_56 ) ;
if ( V_58 || V_57 )
F_33 ( L_3
L_4 ,
V_57 , V_58 ) ;
* ( unsigned long * ) V_53 += V_59 ;
return V_61 ;
}
void F_35 ( struct V_7 * V_8 )
{
V_8 -> V_15 . V_43 . V_64 = F_28 ;
V_8 -> V_15 . V_43 . V_65 = F_24 ;
V_8 -> V_15 . V_43 . V_66 = V_67 ;
F_36 ( & V_8 -> V_15 . V_43 ) ;
V_8 -> V_15 . V_54 . V_68 = F_29 ;
F_37 ( & V_8 -> V_15 . V_54 ) ;
}
