static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
V_5 = 1 ;
return 0 ;
}
void F_2 ( void )
{
F_3 ( & V_6 , & V_7 ) ;
}
void F_4 ( void )
{
F_5 ( & V_6 ,
& V_7 ) ;
}
int F_6 ( struct V_8 * V_9 )
{
V_9 -> V_10 = F_7 ( V_9 , V_11 ) ;
if ( V_9 -> V_10 == NULL )
return - V_12 ;
return 0 ;
}
void F_8 ( struct V_8 * V_9 )
{
char V_13 [ 32 ] ;
F_9 ( L_1 , V_14 , __LINE__ , F_10 ( V_13 ) ) ;
F_11 ( V_9 -> V_10 , V_15 ) ;
F_9 ( L_1 , V_14 , __LINE__ , F_10 ( V_13 ) ) ;
V_5 = 1 ;
F_12 ( V_9 -> V_10 ) ;
}
void F_13 ( struct V_8 * V_9 , void * V_16 , T_1 V_17 )
{
struct V_18 * V_19 = V_9 -> V_10 ;
struct V_20 * V_21 = (struct V_20 * ) V_19 -> V_22 ;
char V_13 [ 32 ] ;
F_9 ( L_1 , V_14 , __LINE__ , F_10 ( V_13 ) ) ;
if ( V_5 )
return;
V_19 -> V_23 = V_24 ;
V_17 = F_14 ( V_17 , V_19 -> V_25 ) ;
F_15 ( V_19 -> V_22 , V_16 , V_17 ) ;
V_21 -> type = V_26 ;
F_16 ( V_9 , V_19 ) ;
}
