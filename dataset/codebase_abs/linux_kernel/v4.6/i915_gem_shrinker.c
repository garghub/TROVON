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
if ( V_8 -> V_14 != F_4 ( V_8 ) )
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
unsigned long V_11 = 0 ;
F_11 ( V_18 , V_19 , V_20 ) ;
F_12 ( V_18 -> V_31 ) ;
for ( V_30 = V_24 ; V_30 -> V_22 ; V_30 ++ ) {
struct V_21 V_32 ;
if ( ( V_20 & V_30 -> V_23 ) == 0 )
continue;
F_13 ( & V_32 ) ;
while ( V_11 < V_19 && ! F_14 ( V_30 -> V_22 ) ) {
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_33 ;
V_8 = F_15 ( V_30 -> V_22 ,
F_16 ( * V_8 ) , V_34 ) ;
F_17 ( & V_8 -> V_34 , & V_32 ) ;
if ( V_20 & V_35 &&
V_8 -> V_15 != V_16 )
continue;
if ( ( V_20 & V_36 ) == 0 && V_8 -> V_37 )
continue;
if ( ! F_9 ( V_8 ) )
continue;
F_18 ( & V_8 -> V_38 ) ;
F_19 (vma, v,
&obj->vma_list, obj_link)
if ( F_20 ( V_10 ) )
break;
if ( F_21 ( V_8 ) == 0 )
V_11 += V_8 -> V_38 . V_39 >> V_40 ;
F_22 ( & V_8 -> V_38 ) ;
}
F_23 ( & V_32 , V_30 -> V_22 ) ;
}
F_12 ( V_18 -> V_31 ) ;
return V_11 ;
}
unsigned long F_24 ( struct V_17 * V_18 )
{
return F_10 ( V_18 , - 1UL ,
V_29 |
V_27 |
V_36 ) ;
}
static bool F_25 ( struct V_41 * V_31 , bool * V_42 )
{
if ( ! F_26 ( & V_31 -> V_43 ) ) {
if ( ! F_1 ( & V_31 -> V_43 , V_44 ) )
return false ;
if ( F_27 ( V_31 ) -> V_25 . V_45 )
return false ;
* V_42 = false ;
} else
* V_42 = true ;
return true ;
}
static unsigned long
F_28 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_17 * V_18 =
F_29 ( V_46 , struct V_17 , V_25 . V_46 ) ;
struct V_41 * V_31 = V_18 -> V_31 ;
struct V_7 * V_8 ;
unsigned long V_11 ;
bool V_42 ;
if ( ! F_25 ( V_31 , & V_42 ) )
return 0 ;
V_11 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list)
if ( V_8 -> V_14 == 0 )
V_11 += V_8 -> V_38 . V_39 >> V_40 ;
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_8 -> V_37 && F_9 ( V_8 ) )
V_11 += V_8 -> V_38 . V_39 >> V_40 ;
}
if ( V_42 )
F_30 ( & V_31 -> V_43 ) ;
return V_11 ;
}
static unsigned long
F_31 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_17 * V_18 =
F_29 ( V_46 , struct V_17 , V_25 . V_46 ) ;
struct V_41 * V_31 = V_18 -> V_31 ;
unsigned long V_49 ;
bool V_42 ;
if ( ! F_25 ( V_31 , & V_42 ) )
return V_50 ;
V_49 = F_10 ( V_18 ,
V_48 -> V_51 ,
V_29 |
V_27 |
V_35 ) ;
if ( V_49 < V_48 -> V_51 )
V_49 += F_10 ( V_18 ,
V_48 -> V_51 - V_49 ,
V_29 |
V_27 ) ;
if ( V_42 )
F_30 ( & V_31 -> V_43 ) ;
return V_49 ;
}
static int
F_32 ( struct V_52 * V_53 , unsigned long V_54 , void * V_55 )
{
struct V_17 * V_18 =
F_29 ( V_53 , struct V_17 , V_25 . V_56 ) ;
struct V_41 * V_31 = V_18 -> V_31 ;
struct V_7 * V_8 ;
unsigned long V_57 = F_33 ( 5000 ) + 1 ;
unsigned long V_58 , V_59 , V_60 , V_61 ;
bool V_62 ;
bool V_42 ;
while ( ! F_25 ( V_31 , & V_42 ) && -- V_57 ) {
F_34 ( 1 ) ;
if ( F_35 ( V_44 ) )
return V_63 ;
}
if ( V_57 == 0 ) {
F_36 ( L_1 ) ;
return V_63 ;
}
V_62 = V_18 -> V_25 . V_64 ;
V_18 -> V_25 . V_64 = false ;
V_61 = F_24 ( V_18 ) ;
V_18 -> V_25 . V_64 = V_62 ;
V_60 = V_59 = V_58 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! V_8 -> V_38 . V_65 )
continue;
if ( V_8 -> V_14 )
V_58 += V_8 -> V_38 . V_39 ;
else
V_60 += V_8 -> V_38 . V_39 ;
}
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_8 -> V_38 . V_65 )
continue;
if ( V_8 -> V_14 )
V_58 += V_8 -> V_38 . V_39 ;
else
V_59 += V_8 -> V_38 . V_39 ;
}
if ( V_42 )
F_30 ( & V_31 -> V_43 ) ;
if ( V_61 || V_60 || V_59 )
F_37 ( L_2 ,
V_61 << V_40 , V_58 ) ;
if ( V_60 || V_59 )
F_36 ( L_3
L_4 ,
V_59 , V_60 ) ;
* ( unsigned long * ) V_55 += V_61 ;
return V_63 ;
}
void F_38 ( struct V_17 * V_18 )
{
V_18 -> V_25 . V_46 . V_66 = F_31 ;
V_18 -> V_25 . V_46 . V_67 = F_28 ;
V_18 -> V_25 . V_46 . V_68 = V_69 ;
F_39 ( F_40 ( & V_18 -> V_25 . V_46 ) ) ;
V_18 -> V_25 . V_56 . V_70 = F_32 ;
F_39 ( F_41 ( & V_18 -> V_25 . V_56 ) ) ;
}
void F_42 ( struct V_17 * V_18 )
{
F_39 ( F_43 ( & V_18 -> V_25 . V_56 ) ) ;
F_44 ( & V_18 -> V_25 . V_46 ) ;
}
