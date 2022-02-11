int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , V_3 ) ;
if ( ! V_2 )
return - V_4 ;
V_5 . V_6 =
F_3 ( * F_4 ( V_2 , 0 , NULL , NULL ) ) ;
F_5 ( ! V_5 . V_6 ) ;
V_5 . V_7 = F_6 ( V_2 , 0 ) ;
F_5 ( ! V_5 . V_7 ) ;
V_5 . V_8 = 1 ;
F_7 ( L_1 ) ;
return 0 ;
}
static void F_8 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
T_2 * args = V_5 . V_7 ;
int V_12 = 0 ;
F_5 ( F_9 () != 0 ) ;
F_5 ( ! V_5 . V_8 ) ;
args [ 0 ] = V_11 -> V_13 ;
args [ 1 ] = V_11 -> V_14 ;
args [ 2 ] = V_11 -> V_15 ;
args [ 3 ] = V_11 -> V_16 ;
if ( V_11 -> V_17 != V_18 )
F_10 () ;
V_12 = F_11 ( V_11 -> V_17 , V_5 . V_6 ) ;
if ( V_12 != V_19 )
F_12 ( L_2 , V_12 ) ;
}
unsigned F_13 ( unsigned V_17 , unsigned V_13 , unsigned V_14 ,
unsigned V_15 , unsigned V_16 )
{
struct V_10 V_11 ;
V_11 . V_17 = V_17 ;
V_11 . V_13 = V_13 ;
V_11 . V_14 = V_14 ;
V_11 . V_15 = V_15 ;
V_11 . V_16 = V_16 ;
if ( F_14 () != 0 )
F_15 ( 0 , F_8 , ( void * ) & V_11 , 1 ) ;
else
F_8 ( & V_11 ) ;
F_16 () ;
return 0 ;
}
