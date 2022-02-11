void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( V_10 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ) ;
F_5 (mark, n, &m->mnt_fsnotify_marks, m.m_list) {
F_6 ( & V_4 -> V_9 . V_13 , & V_10 ) ;
F_7 ( & V_4 -> V_9 . V_14 ) ;
F_8 ( V_4 ) ;
}
F_9 ( & V_2 -> V_11 -> V_12 ) ;
F_10 (mark, lmark, &free_list, m.free_m_list) {
struct V_15 * V_16 ;
F_4 ( & V_4 -> V_17 ) ;
F_11 ( V_4 -> V_16 ) ;
V_16 = V_4 -> V_16 ;
F_9 ( & V_4 -> V_17 ) ;
F_12 ( V_4 , V_16 ) ;
F_13 ( V_4 ) ;
F_14 ( V_16 ) ;
}
}
void F_15 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_18 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_19 = 0 ;
F_18 ( & V_2 -> V_11 -> V_12 ) ;
F_19 (mark, &m->mnt_fsnotify_marks, m.m_list)
V_19 |= V_4 -> V_20 ;
V_9 -> V_21 = V_19 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 -> V_12 ) ;
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_11 -> V_12 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_9 . V_2 ;
F_22 ( ! F_23 ( & V_4 -> V_16 -> V_22 ) ) ;
F_18 ( & V_4 -> V_17 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ) ;
F_7 ( & V_4 -> V_9 . V_14 ) ;
V_4 -> V_9 . V_2 = NULL ;
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_11 -> V_12 ) ;
}
static struct V_3 * F_24 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
F_18 ( & V_2 -> V_11 -> V_12 ) ;
F_19 (mark, &m->mnt_fsnotify_marks, m.m_list) {
if ( V_4 -> V_16 == V_16 ) {
F_8 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
struct V_3 * F_25 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_4 ( & V_2 -> V_11 -> V_12 ) ;
V_4 = F_24 ( V_16 , V_2 ) ;
F_9 ( & V_2 -> V_11 -> V_12 ) ;
return V_4 ;
}
int F_26 ( struct V_3 * V_4 ,
struct V_15 * V_16 , struct V_1 * V_2 ,
int V_23 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_3 * V_5 , * V_24 = NULL ;
int V_25 = 0 ;
V_4 -> V_26 |= V_18 ;
F_22 ( ! F_23 ( & V_16 -> V_22 ) ) ;
F_18 ( & V_4 -> V_17 ) ;
F_4 ( & V_2 -> V_11 -> V_12 ) ;
V_4 -> V_9 . V_2 = V_2 ;
if ( F_27 ( & V_9 -> V_27 ) ) {
F_28 ( & V_4 -> V_9 . V_14 , & V_9 -> V_27 ) ;
goto V_28;
}
F_19 (lmark, &m->mnt_fsnotify_marks, m.m_list) {
V_24 = V_5 ;
if ( ( V_5 -> V_16 == V_16 ) && ! V_23 ) {
V_25 = - V_29 ;
goto V_28;
}
if ( V_4 -> V_16 -> V_30 < V_5 -> V_16 -> V_30 )
continue;
if ( ( V_4 -> V_16 -> V_30 == V_5 -> V_16 -> V_30 ) &&
( V_4 -> V_16 < V_5 -> V_16 ) )
continue;
F_29 ( & V_4 -> V_9 . V_14 , & V_5 -> V_9 . V_14 ) ;
goto V_28;
}
F_22 ( V_24 == NULL ) ;
F_30 ( & V_4 -> V_9 . V_14 , & V_24 -> V_9 . V_14 ) ;
V_28:
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_11 -> V_12 ) ;
return V_25 ;
}
