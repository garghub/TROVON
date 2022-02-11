static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
return false ;
if ( F_2 ( ! F_3 ( & V_2 -> V_6 ) ) )
return false ;
F_4 ( & V_2 -> V_6 , V_4 ) ;
return F_5 ( & V_2 -> V_7 ) ;
}
int
F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , unsigned V_13 , unsigned V_14 ,
unsigned long V_15 , unsigned long V_16 ,
unsigned V_17 )
{
struct V_3 V_18 , V_19 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
int V_21 = 0 ;
F_7 ( V_9 , V_12 , V_13 , V_17 ) ;
F_8 ( & V_19 ) ;
if ( V_15 != 0 || V_16 != V_11 -> V_22 ) {
F_9 ( & V_11 -> V_23 , V_12 ,
V_13 , V_14 ,
V_15 , V_16 ) ;
} else
F_10 ( & V_11 -> V_23 , V_12 , V_13 , V_14 ) ;
V_24:
F_11 (vma, &vm->inactive_list, mm_list) {
if ( F_1 ( V_2 , & V_19 ) )
goto V_25;
}
if ( V_17 & V_26 )
goto V_27;
F_11 (vma, &vm->active_list, mm_list) {
if ( F_1 ( V_2 , & V_19 ) )
goto V_25;
}
V_27:
while ( ! F_3 ( & V_19 ) ) {
V_2 = F_12 ( & V_19 ,
struct V_1 ,
V_6 ) ;
V_20 = F_13 ( & V_2 -> V_7 ) ;
F_14 ( V_20 ) ;
F_15 ( & V_2 -> V_6 ) ;
}
if ( V_17 & V_26 )
return - V_28 ;
if ( V_21 ++ == 0 ) {
V_20 = F_16 ( V_9 ) ;
if ( V_20 )
return V_20 ;
F_17 ( V_9 ) ;
goto V_24;
}
return F_18 ( V_9 ) ? - V_29 : - V_28 ;
V_25:
F_8 ( & V_18 ) ;
while ( ! F_3 ( & V_19 ) ) {
V_2 = F_12 ( & V_19 ,
struct V_1 ,
V_6 ) ;
if ( F_13 ( & V_2 -> V_7 ) ) {
F_19 ( & V_2 -> V_6 , & V_18 ) ;
F_20 ( & V_2 -> V_30 -> V_31 ) ;
continue;
}
F_15 ( & V_2 -> V_6 ) ;
}
while ( ! F_3 ( & V_18 ) ) {
struct V_32 * V_30 ;
V_2 = F_12 ( & V_18 ,
struct V_1 ,
V_6 ) ;
V_30 = & V_2 -> V_30 -> V_31 ;
F_15 ( & V_2 -> V_6 ) ;
if ( V_20 == 0 )
V_20 = F_21 ( V_2 ) ;
F_22 ( V_30 ) ;
}
return V_20 ;
}
int F_23 ( struct V_10 * V_11 , bool V_33 )
{
struct V_1 * V_2 , * V_34 ;
int V_20 ;
F_2 ( ! F_24 ( & V_11 -> V_9 -> V_35 ) ) ;
F_25 ( V_11 ) ;
if ( V_33 ) {
V_20 = F_16 ( V_11 -> V_9 ) ;
if ( V_20 )
return V_20 ;
F_17 ( V_11 -> V_9 ) ;
F_2 ( ! F_3 ( & V_11 -> V_36 ) ) ;
}
F_26 (vma, next, &vm->inactive_list, mm_list)
if ( V_2 -> V_5 == 0 )
F_2 ( F_21 ( V_2 ) ) ;
return 0 ;
}
