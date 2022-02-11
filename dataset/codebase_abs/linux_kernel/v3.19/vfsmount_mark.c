void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( V_9 ) ;
F_4 ( & V_2 -> V_10 -> V_11 ) ;
F_5 (mark, n, &m->mnt_fsnotify_marks, obj_list) {
F_6 ( & V_4 -> V_9 , & V_9 ) ;
F_7 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
F_9 ( & V_2 -> V_10 -> V_11 ) ;
F_10 ( & V_9 ) ;
}
void F_11 ( struct V_13 * V_14 )
{
F_12 ( V_14 , V_15 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_4 ( & V_2 -> V_10 -> V_11 ) ;
V_8 -> V_16 = F_14 ( & V_8 -> V_17 ) ;
F_9 ( & V_2 -> V_10 -> V_11 ) ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_16 ( ! F_17 ( & V_4 -> V_14 -> V_18 ) ) ;
F_18 ( & V_4 -> V_19 ) ;
F_4 ( & V_2 -> V_10 -> V_11 ) ;
F_7 ( & V_4 -> V_12 ) ;
V_4 -> V_2 = NULL ;
V_8 -> V_16 = F_14 ( & V_8 -> V_17 ) ;
F_9 ( & V_2 -> V_10 -> V_11 ) ;
}
struct V_3 * F_19 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
F_4 ( & V_2 -> V_10 -> V_11 ) ;
V_4 = F_20 ( & V_8 -> V_17 , V_14 ) ;
F_9 ( & V_2 -> V_10 -> V_11 ) ;
return V_4 ;
}
int F_21 ( struct V_3 * V_4 ,
struct V_13 * V_14 , struct V_1 * V_2 ,
int V_20 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_21 ;
V_4 -> V_22 |= V_15 ;
F_16 ( ! F_17 ( & V_14 -> V_18 ) ) ;
F_18 ( & V_4 -> V_19 ) ;
F_4 ( & V_2 -> V_10 -> V_11 ) ;
V_4 -> V_2 = V_2 ;
V_21 = F_22 ( & V_8 -> V_17 , V_4 , V_20 ) ;
V_8 -> V_16 = F_14 ( & V_8 -> V_17 ) ;
F_9 ( & V_2 -> V_10 -> V_11 ) ;
return V_21 ;
}
