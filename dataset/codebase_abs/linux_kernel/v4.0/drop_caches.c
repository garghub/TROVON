static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 , * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (inode, &sb->s_inodes, i_sb_list) {
F_2 ( & V_4 -> V_7 ) ;
if ( ( V_4 -> V_8 & ( V_9 | V_10 | V_11 ) ) ||
( V_4 -> V_12 -> V_13 == 0 ) ) {
F_4 ( & V_4 -> V_7 ) ;
continue;
}
F_5 ( V_4 ) ;
F_4 ( & V_4 -> V_7 ) ;
F_4 ( & V_6 ) ;
F_6 ( V_4 -> V_12 , 0 , - 1 ) ;
F_7 ( V_5 ) ;
V_5 = V_4 ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
F_7 ( V_5 ) ;
}
int F_8 ( struct V_14 * V_15 , int V_16 ,
void T_1 * V_17 , T_2 * V_18 , T_3 * V_19 )
{
int V_20 ;
V_20 = F_9 ( V_15 , V_16 , V_17 , V_18 , V_19 ) ;
if ( V_20 )
return V_20 ;
if ( V_16 ) {
static int V_21 ;
if ( V_22 & 1 ) {
F_10 ( F_1 , NULL ) ;
F_11 ( V_23 ) ;
}
if ( V_22 & 2 ) {
F_12 () ;
F_11 ( V_24 ) ;
}
if ( ! V_21 ) {
F_13 ( L_1 ,
V_25 -> V_26 , F_14 ( V_25 ) ,
V_22 ) ;
}
V_21 |= V_22 & 4 ;
}
return 0 ;
}
