static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 -> V_6 )
return false ;
if ( F_2 ( ! F_3 ( & V_2 -> V_7 ) ) )
return false ;
F_4 ( & V_2 -> V_7 , V_4 ) ;
return F_5 ( & V_2 -> V_8 ) ;
}
int
F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , unsigned V_14 , unsigned V_15 ,
bool V_16 , bool V_17 )
{
T_1 * V_18 = V_10 -> V_19 ;
struct V_3 V_20 , V_21 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
F_7 ( V_10 , V_13 , V_14 , V_16 ) ;
F_8 ( & V_21 ) ;
if ( V_16 ) {
F_9 ( ! F_10 ( V_12 ) ) ;
F_11 ( & V_12 -> V_23 , V_13 ,
V_14 , V_15 , 0 ,
V_18 -> V_24 . V_25 ) ;
} else
F_12 ( & V_12 -> V_23 , V_13 , V_14 , V_15 ) ;
V_26:
F_13 (vma, &vm->inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_21 ) )
goto V_27;
}
if ( V_17 )
goto V_28;
F_13 (vma, &vm->active_list, mm_list) {
if ( F_1 ( V_2 , & V_21 ) )
goto V_27;
}
V_28:
while ( ! F_3 ( & V_21 ) ) {
V_2 = F_14 ( & V_21 ,
struct V_1 ,
V_7 ) ;
V_22 = F_15 ( & V_2 -> V_8 ) ;
F_9 ( V_22 ) ;
F_16 ( & V_2 -> V_7 ) ;
}
V_22 = V_17 ? - V_29 : F_17 ( V_10 ) ;
if ( V_22 )
return V_22 ;
F_18 ( V_10 ) ;
V_17 = true ;
goto V_26;
V_27:
F_8 ( & V_20 ) ;
while ( ! F_3 ( & V_21 ) ) {
V_2 = F_14 ( & V_21 ,
struct V_1 ,
V_7 ) ;
if ( F_15 ( & V_2 -> V_8 ) ) {
F_19 ( & V_2 -> V_7 , & V_20 ) ;
F_20 ( & V_2 -> V_5 -> V_30 ) ;
continue;
}
F_16 ( & V_2 -> V_7 ) ;
}
while ( ! F_3 ( & V_20 ) ) {
struct V_31 * V_5 ;
V_2 = F_14 ( & V_20 ,
struct V_1 ,
V_7 ) ;
V_5 = & V_2 -> V_5 -> V_30 ;
F_16 ( & V_2 -> V_7 ) ;
if ( V_22 == 0 )
V_22 = F_21 ( V_2 ) ;
F_22 ( V_5 ) ;
}
return V_22 ;
}
int F_23 ( struct V_11 * V_12 , bool V_32 )
{
struct V_1 * V_2 , * V_33 ;
int V_22 ;
F_24 ( V_12 ) ;
if ( V_32 ) {
V_22 = F_17 ( V_12 -> V_10 ) ;
if ( V_22 )
return V_22 ;
F_18 ( V_12 -> V_10 ) ;
}
F_25 (vma, next, &vm->inactive_list, mm_list)
if ( V_2 -> V_5 -> V_6 == 0 )
F_2 ( F_21 ( V_2 ) ) ;
return 0 ;
}
int
F_26 ( struct V_9 * V_10 )
{
T_1 * V_18 = V_10 -> V_19 ;
struct V_11 * V_12 ;
bool V_34 = true ;
int V_22 ;
F_13 (vm, &dev_priv->vm_list, global_link) {
V_34 = ( F_3 ( & V_12 -> V_35 ) &&
F_3 ( & V_12 -> V_36 ) ) ;
if ( ! V_34 )
V_34 = false ;
}
if ( V_34 )
return - V_29 ;
F_27 ( V_10 ) ;
V_22 = F_17 ( V_10 ) ;
if ( V_22 )
return V_22 ;
F_18 ( V_10 ) ;
F_13 (vm, &dev_priv->vm_list, global_link)
F_2 ( F_23 ( V_12 , false ) ) ;
return 0 ;
}
