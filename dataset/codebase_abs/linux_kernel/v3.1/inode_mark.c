static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
T_1 V_6 = 0 ;
F_2 ( & V_1 -> V_7 ) ;
F_3 (mark, pos, &inode->i_fsnotify_marks, i.i_list)
V_6 |= V_3 -> V_8 ;
V_1 -> V_9 = V_6 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_7 ) ;
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
F_7 ( V_1 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = V_3 -> V_10 . V_1 ;
F_2 ( & V_3 -> V_11 ) ;
F_2 ( & V_3 -> V_12 -> V_13 ) ;
F_5 ( & V_1 -> V_7 ) ;
F_9 ( & V_3 -> V_10 . V_14 ) ;
V_3 -> V_10 . V_1 = NULL ;
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
}
void F_10 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_15 ;
struct V_4 * V_5 , * V_16 ;
F_11 ( V_17 ) ;
F_5 ( & V_1 -> V_7 ) ;
F_12 (mark, pos, n, &inode->i_fsnotify_marks, i.i_list) {
F_13 ( & V_3 -> V_10 . V_18 , & V_17 ) ;
F_9 ( & V_3 -> V_10 . V_14 ) ;
F_14 ( V_3 ) ;
}
F_6 ( & V_1 -> V_7 ) ;
F_15 (mark, lmark, &free_list, i.free_i_list) {
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
}
}
void F_18 ( struct V_19 * V_12 )
{
F_19 ( V_12 , V_20 ) ;
}
struct V_2 * F_20 ( struct V_19 * V_12 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_2 ( & V_1 -> V_7 ) ;
F_3 (mark, pos, &inode->i_fsnotify_marks, i.i_list) {
if ( V_3 -> V_12 == V_12 ) {
F_14 ( V_3 ) ;
return V_3 ;
}
}
return NULL ;
}
struct V_2 * F_21 ( struct V_19 * V_12 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_5 ( & V_1 -> V_7 ) ;
V_3 = F_20 ( V_12 , V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
return V_3 ;
}
void F_22 ( struct V_2 * V_3 ,
T_1 V_8 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 -> V_11 ) ;
if ( V_8 &&
V_3 -> V_10 . V_1 &&
! ( V_3 -> V_21 & V_22 ) ) {
V_3 -> V_21 |= V_22 ;
V_1 = F_23 ( V_3 -> V_10 . V_1 ) ;
F_24 ( ! V_1 ) ;
}
}
int F_25 ( struct V_2 * V_3 ,
struct V_19 * V_12 , struct V_1 * V_1 ,
int V_23 )
{
struct V_2 * V_15 ;
struct V_4 * V_24 , * V_25 = NULL ;
int V_26 = 0 ;
V_3 -> V_21 |= V_20 ;
F_2 ( & V_3 -> V_11 ) ;
F_2 ( & V_12 -> V_13 ) ;
F_5 ( & V_1 -> V_7 ) ;
V_3 -> V_10 . V_1 = V_1 ;
if ( F_26 ( & V_1 -> V_27 ) ) {
F_27 ( & V_3 -> V_10 . V_14 , & V_1 -> V_27 ) ;
goto V_28;
}
F_3 (lmark, node, &inode->i_fsnotify_marks, i.i_list) {
V_25 = V_24 ;
if ( ( V_15 -> V_12 == V_12 ) && ! V_23 ) {
V_26 = - V_29 ;
goto V_28;
}
if ( V_3 -> V_12 -> V_30 < V_15 -> V_12 -> V_30 )
continue;
if ( ( V_3 -> V_12 -> V_30 == V_15 -> V_12 -> V_30 ) &&
( V_3 -> V_12 < V_15 -> V_12 ) )
continue;
F_28 ( & V_3 -> V_10 . V_14 , & V_15 -> V_10 . V_14 ) ;
goto V_28;
}
F_24 ( V_25 == NULL ) ;
F_29 ( V_25 , & V_3 -> V_10 . V_14 ) ;
V_28:
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
return V_26 ;
}
void F_30 ( struct V_31 * V_32 )
{
struct V_1 * V_1 , * V_33 , * V_34 = NULL ;
F_5 ( & V_35 ) ;
F_15 (inode, next_i, list, i_sb_list) {
struct V_1 * V_36 ;
F_5 ( & V_1 -> V_7 ) ;
if ( V_1 -> V_37 & ( V_38 | V_39 | V_40 ) ) {
F_6 ( & V_1 -> V_7 ) ;
continue;
}
if ( ! F_31 ( & V_1 -> V_41 ) ) {
F_6 ( & V_1 -> V_7 ) ;
continue;
}
V_36 = V_34 ;
V_34 = NULL ;
if ( V_1 != V_36 )
F_32 ( V_1 ) ;
else
V_36 = NULL ;
F_6 ( & V_1 -> V_7 ) ;
if ( ( & V_33 -> V_42 != V_32 ) &&
F_31 ( & V_33 -> V_41 ) ) {
F_5 ( & V_33 -> V_7 ) ;
if ( ! ( V_33 -> V_37 & ( V_38 | V_39 ) ) ) {
F_32 ( V_33 ) ;
V_34 = V_33 ;
}
F_6 ( & V_33 -> V_7 ) ;
}
F_6 ( & V_35 ) ;
if ( V_36 )
F_33 ( V_36 ) ;
F_34 ( V_1 , V_43 , V_1 , V_44 , NULL , 0 ) ;
F_35 ( V_1 ) ;
F_33 ( V_1 ) ;
F_5 ( & V_35 ) ;
}
F_6 ( & V_35 ) ;
}
