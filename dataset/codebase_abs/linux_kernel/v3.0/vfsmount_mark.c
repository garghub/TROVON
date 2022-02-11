void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
F_2 ( V_9 ) ;
F_3 ( & V_2 -> V_10 -> V_11 ) ;
F_4 (mark, pos, n, &mnt->mnt_fsnotify_marks, m.m_list) {
F_5 ( & V_4 -> V_12 . V_13 , & V_9 ) ;
F_6 ( & V_4 -> V_12 . V_14 ) ;
F_7 ( V_4 ) ;
}
F_8 ( & V_2 -> V_10 -> V_11 ) ;
F_9 (mark, lmark, &free_list, m.free_m_list) {
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
}
}
void F_12 ( struct V_15 * V_16 )
{
F_13 ( V_16 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
T_1 V_18 = 0 ;
F_15 ( & V_2 -> V_10 -> V_11 ) ;
F_16 (mark, pos, &mnt->mnt_fsnotify_marks, m.m_list)
V_18 |= V_4 -> V_19 ;
V_2 -> V_20 = V_18 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_10 -> V_11 ) ;
F_14 ( V_2 ) ;
F_8 ( & V_2 -> V_10 -> V_11 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_12 . V_2 ;
F_15 ( & V_4 -> V_21 ) ;
F_15 ( & V_4 -> V_16 -> V_22 ) ;
F_3 ( & V_2 -> V_10 -> V_11 ) ;
F_6 ( & V_4 -> V_12 . V_14 ) ;
V_4 -> V_12 . V_2 = NULL ;
F_14 ( V_2 ) ;
F_8 ( & V_2 -> V_10 -> V_11 ) ;
}
static struct V_3 * F_19 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
F_15 ( & V_2 -> V_10 -> V_11 ) ;
F_16 (mark, pos, &mnt->mnt_fsnotify_marks, m.m_list) {
if ( V_4 -> V_16 == V_16 ) {
F_7 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
struct V_3 * F_20 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_10 -> V_11 ) ;
V_4 = F_19 ( V_16 , V_2 ) ;
F_8 ( & V_2 -> V_10 -> V_11 ) ;
return V_4 ;
}
int F_21 ( struct V_3 * V_4 ,
struct V_15 * V_16 , struct V_1 * V_2 ,
int V_23 )
{
struct V_3 * V_5 ;
struct V_6 * V_24 , * V_25 = NULL ;
int V_26 = 0 ;
V_4 -> V_27 |= V_17 ;
F_15 ( & V_4 -> V_21 ) ;
F_15 ( & V_16 -> V_22 ) ;
F_3 ( & V_2 -> V_10 -> V_11 ) ;
V_4 -> V_12 . V_2 = V_2 ;
if ( F_22 ( & V_2 -> V_28 ) ) {
F_23 ( & V_4 -> V_12 . V_14 , & V_2 -> V_28 ) ;
goto V_29;
}
F_16 (lmark, node, &mnt->mnt_fsnotify_marks, m.m_list) {
V_25 = V_24 ;
if ( ( V_5 -> V_16 == V_16 ) && ! V_23 ) {
V_26 = - V_30 ;
goto V_29;
}
if ( V_4 -> V_16 -> V_31 < V_5 -> V_16 -> V_31 )
continue;
if ( ( V_4 -> V_16 -> V_31 == V_5 -> V_16 -> V_31 ) &&
( V_4 -> V_16 < V_5 -> V_16 ) )
continue;
F_24 ( & V_4 -> V_12 . V_14 , & V_5 -> V_12 . V_14 ) ;
goto V_29;
}
F_25 ( V_25 == NULL ) ;
F_26 ( V_25 , & V_4 -> V_12 . V_14 ) ;
V_29:
F_14 ( V_2 ) ;
F_8 ( & V_2 -> V_10 -> V_11 ) ;
return V_26 ;
}
