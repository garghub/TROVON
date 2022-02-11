void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_3 ( V_11 ) ;
F_4 ( & V_2 -> V_12 -> V_13 ) ;
F_5 (mark, pos, n, &m->mnt_fsnotify_marks, m.m_list) {
F_6 ( & V_4 -> V_10 . V_14 , & V_11 ) ;
F_7 ( & V_4 -> V_10 . V_15 ) ;
F_8 ( V_4 ) ;
}
F_9 ( & V_2 -> V_12 -> V_13 ) ;
F_10 (mark, lmark, &free_list, m.free_m_list) {
struct V_16 * V_17 ;
F_4 ( & V_4 -> V_18 ) ;
F_11 ( V_4 -> V_17 ) ;
V_17 = V_4 -> V_17 ;
F_9 ( & V_4 -> V_18 ) ;
F_12 ( V_4 , V_17 ) ;
F_13 ( V_4 ) ;
F_14 ( V_17 ) ;
}
}
void F_15 ( struct V_16 * V_17 )
{
F_16 ( V_17 , V_19 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
T_1 V_20 = 0 ;
F_18 ( & V_2 -> V_12 -> V_13 ) ;
F_19 (mark, pos, &m->mnt_fsnotify_marks, m.m_list)
V_20 |= V_4 -> V_21 ;
V_10 -> V_22 = V_20 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_12 -> V_13 ) ;
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_12 -> V_13 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_10 . V_2 ;
F_22 ( ! F_23 ( & V_4 -> V_17 -> V_23 ) ) ;
F_18 ( & V_4 -> V_18 ) ;
F_4 ( & V_2 -> V_12 -> V_13 ) ;
F_7 ( & V_4 -> V_10 . V_15 ) ;
V_4 -> V_10 . V_2 = NULL ;
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_12 -> V_13 ) ;
}
static struct V_3 * F_24 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
F_18 ( & V_2 -> V_12 -> V_13 ) ;
F_19 (mark, pos, &m->mnt_fsnotify_marks, m.m_list) {
if ( V_4 -> V_17 == V_17 ) {
F_8 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
struct V_3 * F_25 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_4 ( & V_2 -> V_12 -> V_13 ) ;
V_4 = F_24 ( V_17 , V_2 ) ;
F_9 ( & V_2 -> V_12 -> V_13 ) ;
return V_4 ;
}
int F_26 ( struct V_3 * V_4 ,
struct V_16 * V_17 , struct V_1 * V_2 ,
int V_24 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_3 * V_5 ;
struct V_6 * V_25 , * V_26 = NULL ;
int V_27 = 0 ;
V_4 -> V_28 |= V_19 ;
F_22 ( ! F_23 ( & V_17 -> V_23 ) ) ;
F_18 ( & V_4 -> V_18 ) ;
F_4 ( & V_2 -> V_12 -> V_13 ) ;
V_4 -> V_10 . V_2 = V_2 ;
if ( F_27 ( & V_10 -> V_29 ) ) {
F_28 ( & V_4 -> V_10 . V_15 , & V_10 -> V_29 ) ;
goto V_30;
}
F_19 (lmark, node, &m->mnt_fsnotify_marks, m.m_list) {
V_26 = V_25 ;
if ( ( V_5 -> V_17 == V_17 ) && ! V_24 ) {
V_27 = - V_31 ;
goto V_30;
}
if ( V_4 -> V_17 -> V_32 < V_5 -> V_17 -> V_32 )
continue;
if ( ( V_4 -> V_17 -> V_32 == V_5 -> V_17 -> V_32 ) &&
( V_4 -> V_17 < V_5 -> V_17 ) )
continue;
F_29 ( & V_4 -> V_10 . V_15 , & V_5 -> V_10 . V_15 ) ;
goto V_30;
}
F_22 ( V_26 == NULL ) ;
F_30 ( V_26 , & V_4 -> V_10 . V_15 ) ;
V_30:
F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_12 -> V_13 ) ;
return V_27 ;
}
