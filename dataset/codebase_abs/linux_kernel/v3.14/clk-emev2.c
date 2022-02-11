static void T_1 F_1 ( unsigned long V_1 , int V_2 )
{
F_2 ( ! V_3 || ( V_2 >= V_4 ) ) ;
F_3 ( V_1 , V_3 + V_2 ) ;
}
static void T_1 F_4 ( void )
{
struct V_5 * V_6 ;
V_6 = F_5 ( NULL , V_7 ) ;
F_2 ( ! V_6 ) ;
V_3 = F_6 ( V_6 , 0 ) ;
F_2 ( ! V_3 ) ;
F_7 ( V_6 ) ;
F_1 ( 0 , V_8 ) ;
F_1 ( 1 , V_9 ) ;
F_1 ( 2 , V_10 ) ;
F_1 ( 2 , V_11 ) ;
F_1 ( 2 , V_12 ) ;
F_1 ( 2 , V_13 ) ;
}
static void T_1 F_8 ( struct V_5 * V_6 )
{
T_2 V_14 [ 2 ] ;
struct V_15 * V_15 ;
const char * V_16 = F_9 ( V_6 , 0 ) ;
if ( F_10 ( F_11 ( V_6 , L_1 , V_14 , 2 ) ) )
return;
if ( ! V_3 )
F_4 () ;
V_15 = F_12 ( NULL , V_6 -> V_17 , V_16 , 0 ,
V_3 + V_14 [ 0 ] , V_14 [ 1 ] , 8 , 0 , & V_18 ) ;
F_13 ( V_6 , V_19 , V_15 ) ;
F_14 ( V_15 , V_6 -> V_17 , NULL ) ;
F_15 ( L_2 , V_20 , V_6 -> V_17 , V_15 ) ;
}
static void T_1 F_16 ( struct V_5 * V_6 )
{
T_2 V_14 [ 2 ] ;
struct V_15 * V_15 ;
const char * V_16 = F_9 ( V_6 , 0 ) ;
if ( F_10 ( F_11 ( V_6 , L_1 , V_14 , 2 ) ) )
return;
if ( ! V_3 )
F_4 () ;
V_15 = F_17 ( NULL , V_6 -> V_17 , V_16 , 0 ,
V_3 + V_14 [ 0 ] , V_14 [ 1 ] , 0 , & V_18 ) ;
F_13 ( V_6 , V_19 , V_15 ) ;
F_14 ( V_15 , V_6 -> V_17 , NULL ) ;
F_15 ( L_2 , V_20 , V_6 -> V_17 , V_15 ) ;
}
