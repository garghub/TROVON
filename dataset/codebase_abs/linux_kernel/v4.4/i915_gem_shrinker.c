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
unsigned long V_9 , unsigned V_10 )
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
F_5 ( V_8 , V_9 , V_10 ) ;
F_6 ( V_8 -> V_22 ) ;
for ( V_20 = V_14 ; V_20 -> V_12 ; V_20 ++ ) {
struct V_11 V_23 ;
if ( ( V_10 & V_20 -> V_13 ) == 0 )
continue;
F_7 ( & V_23 ) ;
while ( V_21 < V_9 && ! F_8 ( V_20 -> V_12 ) ) {
struct V_24 * V_25 ;
struct V_26 * V_27 , * V_28 ;
V_25 = F_9 ( V_20 -> V_12 ,
F_10 ( * V_25 ) , V_29 ) ;
F_11 ( & V_25 -> V_29 , & V_23 ) ;
if ( V_10 & V_30 &&
V_25 -> V_31 != V_32 )
continue;
if ( ( V_10 & V_33 ) == 0 && V_25 -> V_34 )
continue;
F_12 ( & V_25 -> V_35 ) ;
F_13 (vma, v,
&obj->vma_list, vma_link)
if ( F_14 ( V_27 ) )
break;
if ( F_15 ( V_25 ) == 0 )
V_21 += V_25 -> V_35 . V_36 >> V_37 ;
F_16 ( & V_25 -> V_35 ) ;
}
F_17 ( & V_23 , V_20 -> V_12 ) ;
}
F_6 ( V_8 -> V_22 ) ;
return V_21 ;
}
unsigned long F_18 ( struct V_7 * V_8 )
{
return F_4 ( V_8 , - 1UL ,
V_19 |
V_17 |
V_33 ) ;
}
static bool F_19 ( struct V_38 * V_22 , bool * V_39 )
{
if ( ! F_20 ( & V_22 -> V_40 ) ) {
if ( ! F_1 ( & V_22 -> V_40 , V_41 ) )
return false ;
if ( F_21 ( V_22 ) -> V_15 . V_42 )
return false ;
* V_39 = false ;
} else
* V_39 = true ;
return true ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_21 = 0 ;
F_23 (vma, &obj->vma_list, vma_link) {
if ( F_24 ( & V_27 -> V_43 ) )
V_21 ++ ;
if ( V_27 -> V_44 )
V_21 ++ ;
}
return V_21 ;
}
static unsigned long
F_25 ( struct V_45 * V_45 , struct V_46 * V_47 )
{
struct V_7 * V_8 =
F_26 ( V_45 , struct V_7 , V_15 . V_45 ) ;
struct V_38 * V_22 = V_8 -> V_22 ;
struct V_24 * V_25 ;
unsigned long V_21 ;
bool V_39 ;
if ( ! F_19 ( V_22 , & V_39 ) )
return 0 ;
V_21 = 0 ;
F_23 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_25 -> V_48 == 0 )
V_21 += V_25 -> V_35 . V_36 >> V_37 ;
F_23 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_25 -> V_34 && V_25 -> V_48 == F_22 ( V_25 ) )
V_21 += V_25 -> V_35 . V_36 >> V_37 ;
}
if ( V_39 )
F_27 ( & V_22 -> V_40 ) ;
return V_21 ;
}
static unsigned long
F_28 ( struct V_45 * V_45 , struct V_46 * V_47 )
{
struct V_7 * V_8 =
F_26 ( V_45 , struct V_7 , V_15 . V_45 ) ;
struct V_38 * V_22 = V_8 -> V_22 ;
unsigned long V_49 ;
bool V_39 ;
if ( ! F_19 ( V_22 , & V_39 ) )
return V_50 ;
V_49 = F_4 ( V_8 ,
V_47 -> V_51 ,
V_19 |
V_17 |
V_30 ) ;
if ( V_49 < V_47 -> V_51 )
V_49 += F_4 ( V_8 ,
V_47 -> V_51 - V_49 ,
V_19 |
V_17 ) ;
if ( V_39 )
F_27 ( & V_22 -> V_40 ) ;
return V_49 ;
}
static int
F_29 ( struct V_52 * V_53 , unsigned long V_54 , void * V_55 )
{
struct V_7 * V_8 =
F_26 ( V_53 , struct V_7 , V_15 . V_56 ) ;
struct V_38 * V_22 = V_8 -> V_22 ;
struct V_24 * V_25 ;
unsigned long V_57 = F_30 ( 5000 ) + 1 ;
unsigned long V_58 , V_59 , V_60 , V_61 ;
bool V_62 ;
bool V_39 ;
while ( ! F_19 ( V_22 , & V_39 ) && -- V_57 ) {
F_31 ( 1 ) ;
if ( F_32 ( V_41 ) )
return V_63 ;
}
if ( V_57 == 0 ) {
F_33 ( L_1 ) ;
return V_63 ;
}
V_62 = V_8 -> V_15 . V_64 ;
V_8 -> V_15 . V_64 = false ;
V_61 = F_18 ( V_8 ) ;
V_8 -> V_15 . V_64 = V_62 ;
V_60 = V_59 = V_58 = 0 ;
F_23 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_25 -> V_35 . V_65 )
continue;
if ( V_25 -> V_48 )
V_58 += V_25 -> V_35 . V_36 ;
else
V_60 += V_25 -> V_35 . V_36 ;
}
F_23 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_25 -> V_35 . V_65 )
continue;
if ( V_25 -> V_48 )
V_58 += V_25 -> V_35 . V_36 ;
else
V_59 += V_25 -> V_35 . V_36 ;
}
if ( V_39 )
F_27 ( & V_22 -> V_40 ) ;
if ( V_61 || V_60 || V_59 )
F_34 ( L_2 ,
V_61 << V_37 , V_58 ) ;
if ( V_60 || V_59 )
F_33 ( L_3
L_4 ,
V_59 , V_60 ) ;
* ( unsigned long * ) V_55 += V_61 ;
return V_63 ;
}
void F_35 ( struct V_7 * V_8 )
{
V_8 -> V_15 . V_45 . V_66 = F_28 ;
V_8 -> V_15 . V_45 . V_67 = F_25 ;
V_8 -> V_15 . V_45 . V_68 = V_69 ;
F_36 ( & V_8 -> V_15 . V_45 ) ;
V_8 -> V_15 . V_56 . V_70 = F_29 ;
F_37 ( & V_8 -> V_15 . V_56 ) ;
}
