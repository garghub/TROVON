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
static void F_8 ( void )
{
int V_14 ;
do {
int V_15 ;
V_14 = 0 ;
F_9 (nid)
V_14 += F_10 ( V_16 , V_15 ,
1000 , 1000 ) ;
} while ( V_14 > 10 );
}
int F_11 ( struct V_17 * V_18 , int V_19 ,
void T_1 * V_20 , T_2 * V_21 , T_3 * V_22 )
{
int V_23 ;
V_23 = F_12 ( V_18 , V_19 , V_20 , V_21 , V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_19 ) {
static int V_24 ;
if ( V_25 & 1 ) {
F_13 ( F_1 , NULL ) ;
F_14 ( V_26 ) ;
}
if ( V_25 & 2 ) {
F_8 () ;
F_14 ( V_27 ) ;
}
if ( ! V_24 ) {
F_15 ( L_1 ,
V_28 -> V_29 , F_16 ( V_28 ) ,
V_25 ) ;
}
V_24 |= V_25 & 4 ;
}
return 0 ;
}
