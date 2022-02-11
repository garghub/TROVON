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
F_9 ( ! F_10 ( & V_3 -> V_11 -> V_12 ) ) ;
F_2 ( & V_3 -> V_13 ) ;
F_5 ( & V_1 -> V_7 ) ;
F_11 ( & V_3 -> V_10 . V_14 ) ;
V_3 -> V_10 . V_1 = NULL ;
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_15 ;
struct V_4 * V_5 , * V_16 ;
F_13 ( V_17 ) ;
F_5 ( & V_1 -> V_7 ) ;
F_14 (mark, pos, n, &inode->i_fsnotify_marks, i.i_list) {
F_15 ( & V_3 -> V_10 . V_18 , & V_17 ) ;
F_11 ( & V_3 -> V_10 . V_14 ) ;
F_16 ( V_3 ) ;
}
F_6 ( & V_1 -> V_7 ) ;
F_17 (mark, lmark, &free_list, i.free_i_list) {
struct V_19 * V_11 ;
F_5 ( & V_3 -> V_13 ) ;
F_18 ( V_3 -> V_11 ) ;
V_11 = V_3 -> V_11 ;
F_6 ( & V_3 -> V_13 ) ;
F_19 ( V_3 , V_11 ) ;
F_20 ( V_3 ) ;
F_21 ( V_11 ) ;
}
}
void F_22 ( struct V_19 * V_11 )
{
F_23 ( V_11 , V_20 ) ;
}
static struct V_2 * F_24 (
struct V_19 * V_11 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_2 ( & V_1 -> V_7 ) ;
F_3 (mark, pos, &inode->i_fsnotify_marks, i.i_list) {
if ( V_3 -> V_11 == V_11 ) {
F_16 ( V_3 ) ;
return V_3 ;
}
}
return NULL ;
}
struct V_2 * F_25 ( struct V_19 * V_11 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_5 ( & V_1 -> V_7 ) ;
V_3 = F_24 ( V_11 , V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
return V_3 ;
}
void F_26 ( struct V_2 * V_3 ,
T_1 V_8 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 -> V_13 ) ;
if ( V_8 &&
V_3 -> V_10 . V_1 &&
! ( V_3 -> V_21 & V_22 ) ) {
V_3 -> V_21 |= V_22 ;
V_1 = F_27 ( V_3 -> V_10 . V_1 ) ;
F_9 ( ! V_1 ) ;
}
}
int F_28 ( struct V_2 * V_3 ,
struct V_19 * V_11 , struct V_1 * V_1 ,
int V_23 )
{
struct V_2 * V_15 ;
struct V_4 * V_24 , * V_25 = NULL ;
int V_26 = 0 ;
V_3 -> V_21 |= V_20 ;
F_9 ( ! F_10 ( & V_11 -> V_12 ) ) ;
F_2 ( & V_3 -> V_13 ) ;
F_5 ( & V_1 -> V_7 ) ;
V_3 -> V_10 . V_1 = V_1 ;
if ( F_29 ( & V_1 -> V_27 ) ) {
F_30 ( & V_3 -> V_10 . V_14 , & V_1 -> V_27 ) ;
goto V_28;
}
F_3 (lmark, node, &inode->i_fsnotify_marks, i.i_list) {
V_25 = V_24 ;
if ( ( V_15 -> V_11 == V_11 ) && ! V_23 ) {
V_26 = - V_29 ;
goto V_28;
}
if ( V_3 -> V_11 -> V_30 < V_15 -> V_11 -> V_30 )
continue;
if ( ( V_3 -> V_11 -> V_30 == V_15 -> V_11 -> V_30 ) &&
( V_3 -> V_11 < V_15 -> V_11 ) )
continue;
F_31 ( & V_3 -> V_10 . V_14 , & V_15 -> V_10 . V_14 ) ;
goto V_28;
}
F_9 ( V_25 == NULL ) ;
F_32 ( V_25 , & V_3 -> V_10 . V_14 ) ;
V_28:
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_7 ) ;
return V_26 ;
}
void F_33 ( struct V_31 * V_32 )
{
struct V_1 * V_1 , * V_33 , * V_34 = NULL ;
F_5 ( & V_35 ) ;
F_17 (inode, next_i, list, i_sb_list) {
struct V_1 * V_36 ;
F_5 ( & V_1 -> V_7 ) ;
if ( V_1 -> V_37 & ( V_38 | V_39 | V_40 ) ) {
F_6 ( & V_1 -> V_7 ) ;
continue;
}
if ( ! F_34 ( & V_1 -> V_41 ) ) {
F_6 ( & V_1 -> V_7 ) ;
continue;
}
V_36 = V_34 ;
V_34 = NULL ;
if ( V_1 != V_36 )
F_35 ( V_1 ) ;
else
V_36 = NULL ;
F_6 ( & V_1 -> V_7 ) ;
if ( ( & V_33 -> V_42 != V_32 ) &&
F_34 ( & V_33 -> V_41 ) ) {
F_5 ( & V_33 -> V_7 ) ;
if ( ! ( V_33 -> V_37 & ( V_38 | V_39 ) ) ) {
F_35 ( V_33 ) ;
V_34 = V_33 ;
}
F_6 ( & V_33 -> V_7 ) ;
}
F_6 ( & V_35 ) ;
if ( V_36 )
F_36 ( V_36 ) ;
F_37 ( V_1 , V_43 , V_1 , V_44 , NULL , 0 ) ;
F_38 ( V_1 ) ;
F_36 ( V_1 ) ;
F_5 ( & V_35 ) ;
}
F_6 ( & V_35 ) ;
}
