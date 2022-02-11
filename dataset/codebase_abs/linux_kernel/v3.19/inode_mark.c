void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = F_3 ( & V_1 -> V_4 ) ;
F_4 ( & V_1 -> V_2 ) ;
F_5 ( V_1 ) ;
}
void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
F_7 ( ! F_8 ( & V_6 -> V_7 -> V_8 ) ) ;
F_9 ( & V_6 -> V_9 ) ;
F_2 ( & V_1 -> V_2 ) ;
F_10 ( & V_6 -> V_10 ) ;
V_6 -> V_1 = NULL ;
V_1 -> V_3 = F_3 ( & V_1 -> V_4 ) ;
F_4 ( & V_1 -> V_2 ) ;
}
void F_11 ( struct V_1 * V_1 )
{
struct V_5 * V_6 ;
struct V_11 * V_12 ;
F_12 ( V_13 ) ;
F_2 ( & V_1 -> V_2 ) ;
F_13 (mark, n, &inode->i_fsnotify_marks, obj_list) {
F_14 ( & V_6 -> V_13 , & V_13 ) ;
F_10 ( & V_6 -> V_10 ) ;
F_15 ( V_6 ) ;
}
F_4 ( & V_1 -> V_2 ) ;
F_16 ( & V_13 ) ;
}
void F_17 ( struct V_14 * V_7 )
{
F_18 ( V_7 , V_15 ) ;
}
struct V_5 * F_19 ( struct V_14 * V_7 ,
struct V_1 * V_1 )
{
struct V_5 * V_6 ;
F_2 ( & V_1 -> V_2 ) ;
V_6 = F_20 ( & V_1 -> V_4 , V_7 ) ;
F_4 ( & V_1 -> V_2 ) ;
return V_6 ;
}
void F_21 ( struct V_5 * V_6 ,
T_1 V_16 )
{
struct V_1 * V_1 ;
F_9 ( & V_6 -> V_9 ) ;
if ( V_16 &&
V_6 -> V_1 &&
! ( V_6 -> V_17 & V_18 ) ) {
V_6 -> V_17 |= V_18 ;
V_1 = F_22 ( V_6 -> V_1 ) ;
F_7 ( ! V_1 ) ;
}
}
int F_23 ( struct V_5 * V_6 ,
struct V_14 * V_7 , struct V_1 * V_1 ,
int V_19 )
{
int V_20 ;
V_6 -> V_17 |= V_15 ;
F_7 ( ! F_8 ( & V_7 -> V_8 ) ) ;
F_9 ( & V_6 -> V_9 ) ;
F_2 ( & V_1 -> V_2 ) ;
V_6 -> V_1 = V_1 ;
V_20 = F_24 ( & V_1 -> V_4 , V_6 ,
V_19 ) ;
V_1 -> V_3 = F_3 ( & V_1 -> V_4 ) ;
F_4 ( & V_1 -> V_2 ) ;
return V_20 ;
}
void F_25 ( struct V_21 * V_22 )
{
struct V_1 * V_1 , * V_23 , * V_24 = NULL ;
F_2 ( & V_25 ) ;
F_26 (inode, next_i, list, i_sb_list) {
struct V_1 * V_26 ;
F_2 ( & V_1 -> V_2 ) ;
if ( V_1 -> V_27 & ( V_28 | V_29 | V_30 ) ) {
F_4 ( & V_1 -> V_2 ) ;
continue;
}
if ( ! F_27 ( & V_1 -> V_31 ) ) {
F_4 ( & V_1 -> V_2 ) ;
continue;
}
V_26 = V_24 ;
V_24 = NULL ;
if ( V_1 != V_26 )
F_28 ( V_1 ) ;
else
V_26 = NULL ;
F_4 ( & V_1 -> V_2 ) ;
while ( & V_23 -> V_32 != V_22 ) {
F_2 ( & V_23 -> V_2 ) ;
if ( ! ( V_23 -> V_27 & ( V_28 | V_29 ) ) &&
F_27 ( & V_23 -> V_31 ) ) {
F_28 ( V_23 ) ;
V_24 = V_23 ;
F_4 ( & V_23 -> V_2 ) ;
break;
}
F_4 ( & V_23 -> V_2 ) ;
V_23 = F_29 ( V_23 -> V_32 . V_33 ,
struct V_1 , V_32 ) ;
}
F_4 ( & V_25 ) ;
if ( V_26 )
F_30 ( V_26 ) ;
F_31 ( V_1 , V_34 , V_1 , V_35 , NULL , 0 ) ;
F_32 ( V_1 ) ;
F_30 ( V_1 ) ;
F_2 ( & V_25 ) ;
}
F_4 ( & V_25 ) ;
}
