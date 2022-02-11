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
F_12 ( V_20 -> V_33 ) ;
for ( V_32 = V_26 ; V_32 -> V_24 ; V_32 ++ ) {
struct V_23 V_34 ;
if ( ( V_22 & V_32 -> V_25 ) == 0 )
continue;
F_13 ( & V_34 ) ;
while ( V_11 < V_21 && ! F_14 ( V_32 -> V_24 ) ) {
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_35 ;
V_8 = F_15 ( V_32 -> V_24 ,
F_16 ( * V_8 ) , V_36 ) ;
F_17 ( & V_8 -> V_36 , & V_34 ) ;
if ( V_22 & V_37 &&
V_8 -> V_17 != V_18 )
continue;
if ( V_22 & V_38 &&
! F_18 ( V_8 -> V_39 ) )
continue;
if ( ( V_22 & V_40 ) == 0 && V_8 -> V_41 )
continue;
if ( ! F_9 ( V_8 ) )
continue;
F_19 ( & V_8 -> V_14 ) ;
F_20 (vma, v,
&obj->vma_list, obj_link)
if ( F_21 ( V_10 ) )
break;
if ( F_22 ( V_8 ) == 0 )
V_11 += V_8 -> V_14 . V_42 >> V_43 ;
F_23 ( & V_8 -> V_14 ) ;
}
F_24 ( & V_34 , V_32 -> V_24 ) ;
}
F_12 ( V_20 -> V_33 ) ;
return V_11 ;
}
unsigned long F_25 ( struct V_19 * V_20 )
{
return F_10 ( V_20 , - 1UL ,
V_31 |
V_29 |
V_40 ) ;
}
static bool F_26 ( struct V_44 * V_33 , bool * V_45 )
{
if ( ! F_27 ( & V_33 -> V_46 ) ) {
if ( ! F_1 ( & V_33 -> V_46 , V_47 ) )
return false ;
if ( F_28 ( V_33 ) -> V_27 . V_48 )
return false ;
* V_45 = false ;
} else
* V_45 = true ;
return true ;
}
static unsigned long
F_29 ( struct V_49 * V_49 , struct V_50 * V_51 )
{
struct V_19 * V_20 =
F_30 ( V_49 , struct V_19 , V_27 . V_49 ) ;
struct V_44 * V_33 = V_20 -> V_33 ;
struct V_7 * V_8 ;
unsigned long V_11 ;
bool V_45 ;
if ( ! F_26 ( V_33 , & V_45 ) )
return 0 ;
V_11 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list)
if ( F_9 ( V_8 ) )
V_11 += V_8 -> V_14 . V_42 >> V_43 ;
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! V_8 -> V_41 && F_9 ( V_8 ) )
V_11 += V_8 -> V_14 . V_42 >> V_43 ;
}
if ( V_45 )
F_31 ( & V_33 -> V_46 ) ;
return V_11 ;
}
static unsigned long
F_32 ( struct V_49 * V_49 , struct V_50 * V_51 )
{
struct V_19 * V_20 =
F_30 ( V_49 , struct V_19 , V_27 . V_49 ) ;
struct V_44 * V_33 = V_20 -> V_33 ;
unsigned long V_52 ;
bool V_45 ;
if ( ! F_26 ( V_33 , & V_45 ) )
return V_53 ;
V_52 = F_10 ( V_20 ,
V_51 -> V_54 ,
V_31 |
V_29 |
V_37 ) ;
if ( V_52 < V_51 -> V_54 )
V_52 += F_10 ( V_20 ,
V_51 -> V_54 - V_52 ,
V_31 |
V_29 ) ;
if ( V_45 )
F_31 ( & V_33 -> V_46 ) ;
return V_52 ;
}
static bool
F_33 ( struct V_19 * V_20 ,
struct V_55 * V_56 ,
int V_57 )
{
unsigned long V_58 = F_34 ( V_57 ) + 1 ;
while ( ! F_26 ( V_20 -> V_33 , & V_56 -> V_45 ) ) {
F_35 ( 1 ) ;
if ( F_36 ( V_47 ) )
return false ;
if ( -- V_58 == 0 ) {
F_37 ( L_1 ) ;
return false ;
}
}
V_56 -> V_59 = V_20 -> V_27 . V_60 ;
V_20 -> V_27 . V_60 = false ;
return true ;
}
static void
F_38 ( struct V_19 * V_20 ,
struct V_55 * V_56 )
{
V_20 -> V_27 . V_60 = V_56 -> V_59 ;
if ( V_56 -> V_45 )
F_31 ( & V_20 -> V_33 -> V_46 ) ;
}
static int
F_39 ( struct V_61 * V_62 , unsigned long V_63 , void * V_64 )
{
struct V_19 * V_20 =
F_30 ( V_62 , struct V_19 , V_27 . V_65 ) ;
struct V_55 V_56 ;
struct V_7 * V_8 ;
unsigned long V_66 , V_67 , V_68 , V_69 ;
if ( ! F_33 ( V_20 , & V_56 , 5000 ) )
return V_70 ;
V_69 = F_25 ( V_20 ) ;
V_68 = V_67 = V_66 = 0 ;
F_5 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_66 += V_8 -> V_14 . V_42 >> V_43 ;
else
V_68 += V_8 -> V_14 . V_42 >> V_43 ;
}
F_5 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_9 ( V_8 ) )
V_66 += V_8 -> V_14 . V_42 >> V_43 ;
else
V_67 += V_8 -> V_14 . V_42 >> V_43 ;
}
F_38 ( V_20 , & V_56 ) ;
if ( V_69 || V_68 || V_67 )
F_40 ( L_2
L_3 ,
V_69 , V_66 ) ;
if ( V_68 || V_67 )
F_37 ( L_4
L_5 ,
V_67 , V_68 ) ;
* ( unsigned long * ) V_64 += V_69 ;
return V_70 ;
}
static int
F_41 ( struct V_61 * V_62 , unsigned long V_63 , void * V_64 )
{
struct V_19 * V_20 =
F_30 ( V_62 , struct V_19 , V_27 . V_71 ) ;
struct V_55 V_56 ;
unsigned long V_69 ;
if ( ! F_33 ( V_20 , & V_56 , 5000 ) )
return V_70 ;
V_69 = F_10 ( V_20 , - 1UL ,
V_31 |
V_29 |
V_40 |
V_38 ) ;
F_38 ( V_20 , & V_56 ) ;
* ( unsigned long * ) V_64 += V_69 ;
return V_70 ;
}
void F_42 ( struct V_19 * V_20 )
{
V_20 -> V_27 . V_49 . V_72 = F_32 ;
V_20 -> V_27 . V_49 . V_73 = F_29 ;
V_20 -> V_27 . V_49 . V_74 = V_75 ;
F_43 ( F_44 ( & V_20 -> V_27 . V_49 ) ) ;
V_20 -> V_27 . V_65 . V_76 = F_39 ;
F_43 ( F_45 ( & V_20 -> V_27 . V_65 ) ) ;
V_20 -> V_27 . V_71 . V_76 = F_41 ;
F_43 ( F_46 ( & V_20 -> V_27 . V_71 ) ) ;
}
void F_47 ( struct V_19 * V_20 )
{
F_43 ( F_48 ( & V_20 -> V_27 . V_71 ) ) ;
F_43 ( F_49 ( & V_20 -> V_27 . V_65 ) ) ;
F_50 ( & V_20 -> V_27 . V_49 ) ;
}
