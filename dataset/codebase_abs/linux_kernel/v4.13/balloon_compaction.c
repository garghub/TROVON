struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
struct V_1 * V_1 = F_2 ( F_3 () |
V_5 | V_6 ) ;
if ( ! V_1 )
return NULL ;
F_4 ( ! F_5 ( V_1 ) ) ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_7 ( V_3 , V_1 ) ;
F_8 ( V_8 ) ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
F_10 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_1 , * V_9 ;
unsigned long V_4 ;
bool V_10 ;
V_10 = false ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_12 (page, tmp, &b_dev_info->pages, lru) {
if ( F_5 ( V_1 ) ) {
#ifdef F_13
if ( F_14 ( V_1 ) ) {
F_10 ( V_1 ) ;
continue;
}
#endif
F_15 ( V_1 ) ;
F_8 ( V_11 ) ;
F_10 ( V_1 ) ;
V_10 = true ;
break;
}
}
F_9 ( & V_3 -> V_7 , V_4 ) ;
if ( ! V_10 ) {
F_6 ( & V_3 -> V_7 , V_4 ) ;
if ( F_16 ( F_17 ( & V_3 -> V_12 ) &&
! V_3 -> V_13 ) )
F_18 () ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
V_1 = NULL ;
}
return V_1 ;
}
bool F_19 ( struct V_1 * V_1 , T_1 V_14 )
{
struct V_2 * V_3 = F_20 ( V_1 ) ;
unsigned long V_4 ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_21 ( & V_1 -> V_15 ) ;
V_3 -> V_13 ++ ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
return true ;
}
void F_22 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_20 ( V_1 ) ;
unsigned long V_4 ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_23 ( & V_1 -> V_15 , & V_3 -> V_12 ) ;
V_3 -> V_13 -- ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
}
int F_24 ( struct V_16 * V_17 ,
struct V_1 * V_18 , struct V_1 * V_1 ,
enum V_19 V_14 )
{
struct V_2 * V_20 = F_20 ( V_1 ) ;
F_25 ( ! F_26 ( V_1 ) , V_1 ) ;
F_25 ( ! F_26 ( V_18 ) , V_18 ) ;
return V_20 -> V_21 ( V_20 , V_18 , V_1 , V_14 ) ;
}
