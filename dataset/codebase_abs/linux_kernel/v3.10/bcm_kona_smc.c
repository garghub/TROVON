void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , V_3 ) ;
F_3 ( ! V_2 ) ;
V_4 . V_5 =
F_4 ( * F_5 ( V_2 , 0 , NULL , NULL ) ) ;
F_3 ( ! V_4 . V_5 ) ;
V_4 . V_6 = F_6 ( V_2 , 0 ) ;
F_3 ( ! V_4 . V_6 ) ;
V_4 . V_7 = 1 ;
F_7 ( L_1 ) ;
}
static void F_8 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
T_2 * args = V_4 . V_6 ;
int V_11 = 0 ;
F_3 ( F_9 () != 0 ) ;
F_3 ( ! V_4 . V_7 ) ;
args [ 0 ] = V_10 -> V_12 ;
args [ 1 ] = V_10 -> V_13 ;
args [ 2 ] = V_10 -> V_14 ;
args [ 3 ] = V_10 -> V_15 ;
if ( V_10 -> V_16 != V_17 )
F_10 () ;
V_11 = F_11 ( V_10 -> V_16 , V_4 . V_5 ) ;
if ( V_11 != V_18 )
F_12 ( L_2 , V_11 ) ;
}
unsigned F_13 ( unsigned V_16 , unsigned V_12 , unsigned V_13 ,
unsigned V_14 , unsigned V_15 )
{
struct V_9 V_10 ;
V_10 . V_16 = V_16 ;
V_10 . V_12 = V_12 ;
V_10 . V_13 = V_13 ;
V_10 . V_14 = V_14 ;
V_10 . V_15 = V_15 ;
if ( F_14 () != 0 )
F_15 ( 0 , F_8 , ( void * ) & V_10 , 1 ) ;
else
F_8 ( & V_10 ) ;
F_16 () ;
return 0 ;
}
