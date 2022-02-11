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
F_12 (page, tmp, &b_dev_info->pages, lru) {
if ( F_5 ( V_1 ) ) {
#ifdef F_13
if ( ! F_14 ( V_1 ) ) {
F_10 ( V_1 ) ;
continue;
}
#endif
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_15 ( V_1 ) ;
F_8 ( V_11 ) ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
F_10 ( V_1 ) ;
V_10 = true ;
break;
}
}
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
static inline void F_19 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_20 ( V_1 ) ;
unsigned long V_4 ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_21 ( V_1 ) ;
F_22 ( & V_1 -> V_14 ) ;
V_3 -> V_13 ++ ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
}
static inline void F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_20 ( V_1 ) ;
unsigned long V_4 ;
F_6 ( & V_3 -> V_7 , V_4 ) ;
F_24 ( V_1 ) ;
F_25 ( & V_1 -> V_14 , & V_3 -> V_12 ) ;
V_3 -> V_13 -- ;
F_9 ( & V_3 -> V_7 , V_4 ) ;
}
bool F_26 ( struct V_1 * V_1 )
{
if ( F_27 ( F_28 ( V_1 ) ) ) {
if ( F_27 ( F_5 ( V_1 ) ) ) {
if ( F_29 ( V_1 ) ) {
F_19 ( V_1 ) ;
F_10 ( V_1 ) ;
return true ;
}
F_10 ( V_1 ) ;
}
F_30 ( V_1 ) ;
}
return false ;
}
void F_31 ( struct V_1 * V_1 )
{
F_32 ( V_1 ) ;
if ( F_33 ( V_1 ) ) {
F_23 ( V_1 ) ;
F_30 ( V_1 ) ;
} else {
F_34 ( 1 ) ;
F_35 ( V_1 , L_1 ) ;
}
F_10 ( V_1 ) ;
}
int F_36 ( struct V_1 * V_15 ,
struct V_1 * V_1 , enum V_16 V_17 )
{
struct V_2 * V_18 = F_20 ( V_1 ) ;
int V_19 = - V_20 ;
F_4 ( ! F_5 ( V_15 ) ) ;
if ( F_34 ( ! F_33 ( V_1 ) ) ) {
F_35 ( V_1 , L_1 ) ;
F_10 ( V_15 ) ;
return V_19 ;
}
if ( V_18 && V_18 -> V_21 )
V_19 = V_18 -> V_21 ( V_18 , V_15 , V_1 , V_17 ) ;
F_10 ( V_15 ) ;
return V_19 ;
}
