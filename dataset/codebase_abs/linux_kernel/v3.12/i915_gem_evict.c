static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 -> V_6 )
return false ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
return F_3 ( & V_2 -> V_8 ) ;
}
int
F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , unsigned V_14 , unsigned V_15 ,
bool V_16 , bool V_17 )
{
T_1 * V_18 = V_10 -> V_19 ;
struct V_3 V_20 , V_21 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
F_5 ( V_10 , V_13 , V_14 , V_16 ) ;
F_6 ( & V_21 ) ;
if ( V_16 ) {
F_7 ( ! F_8 ( V_12 ) ) ;
F_9 ( & V_12 -> V_23 , V_13 ,
V_14 , V_15 , 0 ,
V_18 -> V_24 . V_25 ) ;
} else
F_10 ( & V_12 -> V_23 , V_13 , V_14 , V_15 ) ;
F_11 (vma, &vm->inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_21 ) )
goto V_26;
}
if ( V_17 )
goto V_27;
F_11 (vma, &vm->active_list, mm_list) {
if ( F_1 ( V_2 , & V_21 ) )
goto V_26;
}
V_27:
while ( ! F_12 ( & V_21 ) ) {
V_2 = F_13 ( & V_21 ,
struct V_1 ,
V_7 ) ;
V_22 = F_14 ( & V_2 -> V_8 ) ;
F_7 ( V_22 ) ;
F_15 ( & V_2 -> V_7 ) ;
}
return - V_28 ;
V_26:
F_6 ( & V_20 ) ;
while ( ! F_12 ( & V_21 ) ) {
V_2 = F_13 ( & V_21 ,
struct V_1 ,
V_7 ) ;
if ( F_14 ( & V_2 -> V_8 ) ) {
F_16 ( & V_2 -> V_7 , & V_20 ) ;
F_17 ( & V_2 -> V_5 -> V_29 ) ;
continue;
}
F_15 ( & V_2 -> V_7 ) ;
}
while ( ! F_12 ( & V_20 ) ) {
struct V_30 * V_5 ;
V_2 = F_13 ( & V_20 ,
struct V_1 ,
V_7 ) ;
V_5 = & V_2 -> V_5 -> V_29 ;
F_15 ( & V_2 -> V_7 ) ;
if ( V_22 == 0 )
V_22 = F_18 ( V_2 ) ;
F_19 ( V_5 ) ;
}
return V_22 ;
}
int
F_20 ( struct V_9 * V_10 )
{
T_1 * V_18 = V_10 -> V_19 ;
struct V_11 * V_12 ;
struct V_1 * V_2 , * V_31 ;
bool V_32 = true ;
int V_22 ;
F_11 (vm, &dev_priv->vm_list, global_link) {
V_32 = ( F_12 ( & V_12 -> V_33 ) &&
F_12 ( & V_12 -> V_34 ) ) ;
if ( ! V_32 )
V_32 = false ;
}
if ( V_32 )
return - V_28 ;
F_21 ( V_10 ) ;
V_22 = F_22 ( V_10 ) ;
if ( V_22 )
return V_22 ;
F_23 ( V_10 ) ;
F_11 (vm, &dev_priv->vm_list, global_link) {
F_24 (vma, next, &vm->inactive_list, mm_list)
if ( V_2 -> V_5 -> V_6 == 0 )
F_25 ( F_18 ( V_2 ) ) ;
}
return 0 ;
}
