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
void F_11 ( struct V_11 * V_7 )
{
F_12 ( V_7 , V_12 ) ;
}
struct V_5 * F_13 ( struct V_11 * V_7 ,
struct V_1 * V_1 )
{
struct V_5 * V_6 ;
F_2 ( & V_1 -> V_2 ) ;
V_6 = F_14 ( & V_1 -> V_4 , V_7 ) ;
F_4 ( & V_1 -> V_2 ) ;
return V_6 ;
}
void F_15 ( struct V_5 * V_6 ,
T_1 V_13 )
{
struct V_1 * V_1 ;
F_9 ( & V_6 -> V_9 ) ;
if ( V_13 &&
V_6 -> V_1 &&
! ( V_6 -> V_14 & V_15 ) ) {
V_6 -> V_14 |= V_15 ;
V_1 = F_16 ( V_6 -> V_1 ) ;
F_7 ( ! V_1 ) ;
}
}
int F_17 ( struct V_5 * V_6 ,
struct V_11 * V_7 , struct V_1 * V_1 ,
int V_16 )
{
int V_17 ;
V_6 -> V_14 |= V_12 ;
F_7 ( ! F_8 ( & V_7 -> V_8 ) ) ;
F_9 ( & V_6 -> V_9 ) ;
F_2 ( & V_1 -> V_2 ) ;
V_6 -> V_1 = V_1 ;
V_17 = F_18 ( & V_1 -> V_4 , V_6 ,
V_16 ) ;
V_1 -> V_3 = F_3 ( & V_1 -> V_4 ) ;
F_4 ( & V_1 -> V_2 ) ;
return V_17 ;
}
void F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_1 , * V_20 = NULL ;
F_2 ( & V_19 -> V_21 ) ;
F_20 (inode, &sb->s_inodes, i_sb_list) {
F_2 ( & V_1 -> V_2 ) ;
if ( V_1 -> V_22 & ( V_23 | V_24 | V_25 ) ) {
F_4 ( & V_1 -> V_2 ) ;
continue;
}
if ( ! F_21 ( & V_1 -> V_26 ) ) {
F_4 ( & V_1 -> V_2 ) ;
continue;
}
F_22 ( V_1 ) ;
F_4 ( & V_1 -> V_2 ) ;
F_4 ( & V_19 -> V_21 ) ;
if ( V_20 )
F_23 ( V_20 ) ;
F_24 ( V_1 , V_27 , V_1 , V_28 , NULL , 0 ) ;
F_25 ( V_1 ) ;
V_20 = V_1 ;
F_2 ( & V_19 -> V_21 ) ;
}
F_4 ( & V_19 -> V_21 ) ;
if ( V_20 )
F_23 ( V_20 ) ;
}
