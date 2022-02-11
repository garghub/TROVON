void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
}
int F_3 ( struct V_6 * V_7 , T_1 V_8 , T_1 V_9 )
{
int V_10 ;
memset ( & V_7 -> V_11 , 0 , sizeof( V_7 -> V_11 ) ) ;
if ( V_9 != V_12 )
V_9 >>= V_13 ;
V_10 = F_4 ( & V_7 -> V_11 , V_8 >> V_13 , V_9 ) ;
if ( V_10 )
return V_10 ;
F_5 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
return V_10 ;
}
static inline struct V_6 * F_6 ( struct V_6 * V_7 )
{
return F_7 ( V_7 -> V_14 . V_19 , F_8 ( * V_7 ) , V_14 ) ;
}
static enum V_20 F_9 ( struct V_21 * V_22 , void * V_23 )
{
struct V_6 * V_7 = V_23 ;
struct V_6 * V_24 = F_10 ( V_22 ) ;
struct V_6 * V_25 ;
F_11 (iter, &overlap->rl_next_lock, rl_next_lock) {
if ( V_25 -> V_18 > V_7 -> V_18 ) {
-- V_25 -> V_17 ;
F_12 ( V_25 -> V_17 > 0 ) ;
}
}
if ( V_24 -> V_18 > V_7 -> V_18 ) {
-- V_24 -> V_17 ;
if ( V_24 -> V_17 == 0 )
F_13 ( V_24 -> V_15 ) ;
}
return V_26 ;
}
void F_14 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_15 ( & V_2 -> V_5 ) ;
if ( ! F_16 ( & V_7 -> V_14 ) ) {
struct V_6 * V_19 ;
if ( F_17 ( & V_7 -> V_11 ) ) {
V_19 = F_6 ( V_7 ) ;
V_19 -> V_16 = V_7 -> V_16 - 1 ;
F_18 ( & V_7 -> V_11 , & V_2 -> V_3 ) ;
F_19 ( & V_19 -> V_11 , & V_2 -> V_3 ) ;
} else {
F_11 (next, &lock->rl_next_lock,
rl_next_lock) {
if ( ! F_17 ( & V_19 -> V_11 ) )
continue;
F_12 ( V_19 -> V_16 > 0 ) ;
V_19 -> V_16 -- ;
break;
}
}
F_20 ( & V_7 -> V_14 ) ;
} else {
F_12 ( F_17 ( & V_7 -> V_11 ) ) ;
F_18 ( & V_7 -> V_11 , & V_2 -> V_3 ) ;
}
F_21 ( V_2 -> V_3 , & V_7 -> V_11 . V_27 ,
F_9 , V_7 ) ;
F_22 ( & V_2 -> V_5 ) ;
}
static enum V_20 F_23 ( struct V_21 * V_22 , void * V_23 )
{
struct V_6 * V_7 = V_23 ;
struct V_6 * V_24 = F_10 ( V_22 ) ;
V_7 -> V_17 += V_24 -> V_16 + 1 ;
return V_26 ;
}
int V_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_21 * V_22 ;
int V_10 = 0 ;
F_15 ( & V_2 -> V_5 ) ;
F_21 ( V_2 -> V_3 , & V_7 -> V_11 . V_27 ,
F_23 , V_7 ) ;
V_22 = F_19 ( & V_7 -> V_11 , & V_2 -> V_3 ) ;
if ( V_22 ) {
struct V_6 * V_28 = F_10 ( V_22 ) ;
F_24 ( & V_7 -> V_14 , & V_28 -> V_14 ) ;
V_28 -> V_16 ++ ;
}
V_7 -> V_18 = ++ V_2 -> V_4 ;
while ( V_7 -> V_17 > 0 ) {
V_7 -> V_15 = V_29 ;
F_25 ( V_30 ) ;
F_22 ( & V_2 -> V_5 ) ;
F_26 () ;
if ( F_27 ( V_29 ) ) {
F_14 ( V_2 , V_7 ) ;
V_10 = - V_31 ;
goto V_32;
}
F_15 ( & V_2 -> V_5 ) ;
}
F_22 ( & V_2 -> V_5 ) ;
V_32:
return V_10 ;
}
