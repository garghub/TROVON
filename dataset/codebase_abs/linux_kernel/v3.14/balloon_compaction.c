struct V_1 * F_1 ( void * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
V_3 -> V_6 = V_2 ;
V_3 -> V_7 = NULL ;
V_3 -> V_8 = 0 ;
F_4 ( & V_3 -> V_9 ) ;
F_5 ( & V_3 -> V_10 ) ;
return V_3 ;
}
struct V_11 * F_6 ( struct V_1 * V_3 )
{
unsigned long V_12 ;
struct V_11 * V_11 = F_7 ( F_8 () |
V_13 | V_14 ) ;
if ( ! V_11 )
return NULL ;
F_9 ( ! F_10 ( V_11 ) ) ;
F_11 ( & V_3 -> V_9 , V_12 ) ;
F_12 ( V_11 , V_3 -> V_7 , & V_3 -> V_10 ) ;
F_13 ( & V_3 -> V_9 , V_12 ) ;
F_14 ( V_11 ) ;
return V_11 ;
}
struct V_11 * F_15 ( struct V_1 * V_3 )
{
struct V_11 * V_11 , * V_15 ;
unsigned long V_12 ;
bool V_16 ;
V_16 = false ;
F_16 (page, tmp, &b_dev_info->pages, lru) {
if ( F_10 ( V_11 ) ) {
F_11 ( & V_3 -> V_9 , V_12 ) ;
F_17 ( V_11 ) ;
F_18 ( V_11 ) ;
F_13 ( & V_3 -> V_9 , V_12 ) ;
F_14 ( V_11 ) ;
V_16 = true ;
break;
}
}
if ( ! V_16 ) {
F_11 ( & V_3 -> V_9 , V_12 ) ;
if ( F_19 ( F_20 ( & V_3 -> V_10 ) &&
! V_3 -> V_8 ) )
F_21 () ;
F_13 ( & V_3 -> V_9 , V_12 ) ;
V_11 = NULL ;
}
return V_11 ;
}
struct V_17 * F_22 ( struct V_1 * V_3 ,
const struct V_18 * V_19 )
{
struct V_17 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_4 ) ;
if ( ! V_7 )
return F_3 ( - V_5 ) ;
F_23 ( V_7 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 , F_8 () ) ;
V_7 -> V_19 = V_19 ;
V_7 -> V_20 = V_3 ;
V_3 -> V_7 = V_7 ;
return V_7 ;
}
static inline void F_26 ( struct V_11 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_7 -> V_20 ;
unsigned long V_12 ;
F_11 ( & V_3 -> V_9 , V_12 ) ;
F_27 ( & V_11 -> V_21 ) ;
V_3 -> V_8 ++ ;
F_13 ( & V_3 -> V_9 , V_12 ) ;
}
static inline void F_28 ( struct V_11 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_7 -> V_20 ;
unsigned long V_12 ;
F_11 ( & V_3 -> V_9 , V_12 ) ;
F_29 ( & V_11 -> V_21 , & V_3 -> V_10 ) ;
V_3 -> V_8 -- ;
F_13 ( & V_3 -> V_9 , V_12 ) ;
}
static inline int F_30 ( struct V_17 * V_7 ,
struct V_11 * V_22 , struct V_11 * V_11 , enum V_23 V_24 )
{
return V_11 -> V_7 -> V_19 -> V_25 ( V_7 , V_22 , V_11 , V_24 ) ;
}
bool F_31 ( struct V_11 * V_11 )
{
if ( F_32 ( F_33 ( V_11 ) ) ) {
if ( F_32 ( F_10 ( V_11 ) ) ) {
if ( F_34 ( V_11 ) &&
F_35 ( V_11 ) == 2 ) {
F_26 ( V_11 ) ;
F_14 ( V_11 ) ;
return true ;
}
F_14 ( V_11 ) ;
}
F_36 ( V_11 ) ;
}
return false ;
}
void F_37 ( struct V_11 * V_11 )
{
F_38 ( V_11 ) ;
if ( F_34 ( V_11 ) ) {
F_28 ( V_11 ) ;
F_36 ( V_11 ) ;
} else {
F_39 ( 1 ) ;
F_40 ( V_11 , L_1 ) ;
}
F_14 ( V_11 ) ;
}
int F_41 ( struct V_11 * V_22 ,
struct V_11 * V_11 , enum V_23 V_24 )
{
struct V_17 * V_7 ;
int V_26 = - V_27 ;
F_9 ( ! F_10 ( V_22 ) ) ;
if ( F_39 ( ! F_34 ( V_11 ) ) ) {
F_40 ( V_11 , L_1 ) ;
F_14 ( V_22 ) ;
return V_26 ;
}
V_7 = V_11 -> V_7 ;
if ( V_7 )
V_26 = F_30 ( V_7 , V_22 , V_11 , V_24 ) ;
F_14 ( V_22 ) ;
return V_26 ;
}
