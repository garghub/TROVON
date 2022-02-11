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
struct V_15 V_16 = {
. V_17 = V_18 ,
} ;
F_9 ( V_16 . V_19 ) ;
do {
V_14 = F_10 ( & V_16 , 1000 , 1000 ) ;
} while ( V_14 > 10 );
}
int F_11 ( T_1 * V_20 , int V_21 ,
void T_2 * V_22 , T_3 * V_23 , T_4 * V_24 )
{
int V_25 ;
V_25 = F_12 ( V_20 , V_21 , V_22 , V_23 , V_24 ) ;
if ( V_25 )
return V_25 ;
if ( V_21 ) {
if ( V_26 & 1 )
F_13 ( F_1 , NULL ) ;
if ( V_26 & 2 )
F_8 () ;
}
return 0 ;
}
