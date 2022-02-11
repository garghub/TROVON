static int F_1 ( void * V_1 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 ( & V_7 , V_2 ) ;
V_4 = NULL ;
if ( ! F_3 ( & V_8 ) ) {
V_4 = F_4 ( V_8 . V_9 , struct V_3 , V_10 ) ;
F_5 ( & V_4 -> V_10 ) ;
}
F_6 ( & V_7 , V_2 ) ;
if ( V_4 == NULL )
return 0 ;
F_7 ( & V_11 ) ;
V_6 = V_4 -> V_6 ;
F_8 ( V_6 , V_12 ) ;
F_9 ( L_1 ,
V_6 -> V_13 -> V_14 , V_6 -> V_15 ) ;
F_10 ( V_16 ) ;
F_11 ( V_6 ) ;
F_12 ( V_6 , V_12 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_11 ) ;
if ( V_6 && V_6 -> V_17 > 0 ) {
F_15 ( 3600 * 1000 ) ;
if ( V_6 -> V_17 > 0 )
V_6 -> V_17 -- ;
}
return 0 ;
}
static void F_16 ( struct V_18 * V_1 )
{
if ( F_17 ( F_18 ( F_1 , NULL , L_2 ) ) )
F_19 ( V_19 L_3 ) ;
}
int F_20 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
V_4 = F_21 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 ) {
F_22 ( L_4 ) ;
return - V_21 ;
}
V_4 -> V_6 = V_6 ;
F_2 ( & V_7 , V_2 ) ;
F_23 ( & V_4 -> V_10 , & V_8 ) ;
F_6 ( & V_7 , V_2 ) ;
F_24 ( & V_22 ) ;
return 0 ;
}
