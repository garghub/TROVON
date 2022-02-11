void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
}
void F_3 ( struct V_6 * V_7 , T_1 V_8 , T_1 V_9 )
{
memset ( & V_7 -> V_10 , 0 , sizeof( V_7 -> V_10 ) ) ;
if ( V_9 != V_11 )
V_9 >>= V_12 ;
F_4 ( & V_7 -> V_10 , V_8 >> V_12 , V_9 ) ;
F_5 ( & V_7 -> V_13 ) ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
}
static inline struct V_6 * F_6 ( struct V_6 * V_7 )
{
return F_7 ( V_7 -> V_13 . V_18 , F_8 ( * V_7 ) , V_13 ) ;
}
static enum V_19 F_9 ( struct V_20 * V_21 , void * V_22 )
{
struct V_6 * V_7 = V_22 ;
struct V_6 * V_23 = F_10 ( V_21 ) ;
struct V_6 * V_24 ;
F_11 (iter, &overlap->rl_next_lock, rl_next_lock) {
if ( V_24 -> V_17 > V_7 -> V_17 ) {
-- V_24 -> V_16 ;
F_12 ( V_24 -> V_16 > 0 ) ;
}
}
if ( V_23 -> V_17 > V_7 -> V_17 ) {
-- V_23 -> V_16 ;
if ( V_23 -> V_16 == 0 )
F_13 ( V_23 -> V_14 ) ;
}
return V_25 ;
}
void F_14 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_15 ( & V_2 -> V_5 ) ;
if ( ! F_16 ( & V_7 -> V_13 ) ) {
struct V_6 * V_18 ;
if ( F_17 ( & V_7 -> V_10 ) ) {
V_18 = F_6 ( V_7 ) ;
V_18 -> V_15 = V_7 -> V_15 - 1 ;
F_18 ( & V_7 -> V_10 , & V_2 -> V_3 ) ;
F_19 ( & V_18 -> V_10 , & V_2 -> V_3 ) ;
} else {
F_11 (next, &lock->rl_next_lock,
rl_next_lock) {
if ( ! F_17 ( & V_18 -> V_10 ) )
continue;
F_12 ( V_18 -> V_15 > 0 ) ;
V_18 -> V_15 -- ;
break;
}
}
F_20 ( & V_7 -> V_13 ) ;
} else {
F_12 ( F_17 ( & V_7 -> V_10 ) ) ;
F_18 ( & V_7 -> V_10 , & V_2 -> V_3 ) ;
}
F_21 ( V_2 -> V_3 , & V_7 -> V_10 . V_26 ,
F_9 , V_7 ) ;
F_22 ( & V_2 -> V_5 ) ;
}
static enum V_19 F_23 ( struct V_20 * V_21 , void * V_22 )
{
struct V_6 * V_7 = (struct V_6 * ) V_22 ;
struct V_6 * V_23 = F_10 ( V_21 ) ;
V_7 -> V_16 += V_23 -> V_15 + 1 ;
return V_25 ;
}
int V_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_21 ;
int V_27 = 0 ;
F_15 ( & V_2 -> V_5 ) ;
F_21 ( V_2 -> V_3 , & V_7 -> V_10 . V_26 ,
F_23 , V_7 ) ;
V_21 = F_19 ( & V_7 -> V_10 , & V_2 -> V_3 ) ;
if ( V_21 ) {
struct V_6 * V_28 = F_10 ( V_21 ) ;
F_24 ( & V_7 -> V_13 , & V_28 -> V_13 ) ;
V_28 -> V_15 ++ ;
}
V_7 -> V_17 = ++ V_2 -> V_4 ;
while ( V_7 -> V_16 > 0 ) {
V_7 -> V_14 = V_29 ;
F_25 ( V_30 ) ;
F_22 ( & V_2 -> V_5 ) ;
F_26 () ;
if ( F_27 ( V_29 ) ) {
F_14 ( V_2 , V_7 ) ;
V_27 = - V_31 ;
goto V_32;
}
F_15 ( & V_2 -> V_5 ) ;
}
F_22 ( & V_2 -> V_5 ) ;
V_32:
return V_27 ;
}
