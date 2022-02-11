static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 = 0 ;
F_2 ( & V_1 -> V_5 ) ;
F_3 (mark, &inode->i_fsnotify_marks, i.i_list)
V_4 |= V_3 -> V_6 ;
V_1 -> V_7 = V_4 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_5 ) ;
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_5 ) ;
F_7 ( V_1 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = V_3 -> V_8 . V_1 ;
F_9 ( ! F_10 ( & V_3 -> V_9 -> V_10 ) ) ;
F_2 ( & V_3 -> V_11 ) ;
F_5 ( & V_1 -> V_5 ) ;
F_11 ( & V_3 -> V_8 . V_12 ) ;
V_3 -> V_8 . V_1 = NULL ;
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_5 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_13 ;
struct V_14 * V_15 ;
F_13 ( V_16 ) ;
F_5 ( & V_1 -> V_5 ) ;
F_14 (mark, n, &inode->i_fsnotify_marks, i.i_list) {
F_15 ( & V_3 -> V_8 . V_17 , & V_16 ) ;
F_11 ( & V_3 -> V_8 . V_12 ) ;
F_16 ( V_3 ) ;
}
F_6 ( & V_1 -> V_5 ) ;
F_17 (mark, lmark, &free_list, i.free_i_list) {
struct V_18 * V_9 ;
F_5 ( & V_3 -> V_11 ) ;
F_18 ( V_3 -> V_9 ) ;
V_9 = V_3 -> V_9 ;
F_6 ( & V_3 -> V_11 ) ;
F_19 ( V_3 , V_9 ) ;
F_20 ( V_3 ) ;
F_21 ( V_9 ) ;
}
}
void F_22 ( struct V_18 * V_9 )
{
F_23 ( V_9 , V_19 ) ;
}
static struct V_2 * F_24 (
struct V_18 * V_9 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_2 ( & V_1 -> V_5 ) ;
F_3 (mark, &inode->i_fsnotify_marks, i.i_list) {
if ( V_3 -> V_9 == V_9 ) {
F_16 ( V_3 ) ;
return V_3 ;
}
}
return NULL ;
}
struct V_2 * F_25 ( struct V_18 * V_9 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_5 ( & V_1 -> V_5 ) ;
V_3 = F_24 ( V_9 , V_1 ) ;
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
void F_26 ( struct V_2 * V_3 ,
T_1 V_6 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 -> V_11 ) ;
if ( V_6 &&
V_3 -> V_8 . V_1 &&
! ( V_3 -> V_20 & V_21 ) ) {
V_3 -> V_20 |= V_21 ;
V_1 = F_27 ( V_3 -> V_8 . V_1 ) ;
F_9 ( ! V_1 ) ;
}
}
int F_28 ( struct V_2 * V_3 ,
struct V_18 * V_9 , struct V_1 * V_1 ,
int V_22 )
{
struct V_2 * V_13 , * V_23 = NULL ;
int V_24 = 0 ;
V_3 -> V_20 |= V_19 ;
F_9 ( ! F_10 ( & V_9 -> V_10 ) ) ;
F_2 ( & V_3 -> V_11 ) ;
F_5 ( & V_1 -> V_5 ) ;
V_3 -> V_8 . V_1 = V_1 ;
if ( F_29 ( & V_1 -> V_25 ) ) {
F_30 ( & V_3 -> V_8 . V_12 , & V_1 -> V_25 ) ;
goto V_26;
}
F_3 (lmark, &inode->i_fsnotify_marks, i.i_list) {
V_23 = V_13 ;
if ( ( V_13 -> V_9 == V_9 ) && ! V_22 ) {
V_24 = - V_27 ;
goto V_26;
}
if ( V_3 -> V_9 -> V_28 < V_13 -> V_9 -> V_28 )
continue;
if ( ( V_3 -> V_9 -> V_28 == V_13 -> V_9 -> V_28 ) &&
( V_3 -> V_9 < V_13 -> V_9 ) )
continue;
F_31 ( & V_3 -> V_8 . V_12 , & V_13 -> V_8 . V_12 ) ;
goto V_26;
}
F_9 ( V_23 == NULL ) ;
F_32 ( & V_3 -> V_8 . V_12 , & V_23 -> V_8 . V_12 ) ;
V_26:
F_1 ( V_1 ) ;
F_6 ( & V_1 -> V_5 ) ;
return V_24 ;
}
void F_33 ( struct V_29 * V_30 )
{
struct V_1 * V_1 , * V_31 , * V_32 = NULL ;
F_5 ( & V_33 ) ;
F_17 (inode, next_i, list, i_sb_list) {
struct V_1 * V_34 ;
F_5 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_35 & ( V_36 | V_37 | V_38 ) ) {
F_6 ( & V_1 -> V_5 ) ;
continue;
}
if ( ! F_34 ( & V_1 -> V_39 ) ) {
F_6 ( & V_1 -> V_5 ) ;
continue;
}
V_34 = V_32 ;
V_32 = NULL ;
if ( V_1 != V_34 )
F_35 ( V_1 ) ;
else
V_34 = NULL ;
F_6 ( & V_1 -> V_5 ) ;
if ( ( & V_31 -> V_40 != V_30 ) &&
F_34 ( & V_31 -> V_39 ) ) {
F_5 ( & V_31 -> V_5 ) ;
if ( ! ( V_31 -> V_35 & ( V_36 | V_37 ) ) ) {
F_35 ( V_31 ) ;
V_32 = V_31 ;
}
F_6 ( & V_31 -> V_5 ) ;
}
F_6 ( & V_33 ) ;
if ( V_34 )
F_36 ( V_34 ) ;
F_37 ( V_1 , V_41 , V_1 , V_42 , NULL , 0 ) ;
F_38 ( V_1 ) ;
F_36 ( V_1 ) ;
F_5 ( & V_33 ) ;
}
F_6 ( & V_33 ) ;
}
