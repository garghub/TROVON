static int F_1 ( void * V_1 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 ( V_7 , L_1 ) ;
F_3 ( & V_8 , V_2 ) ;
V_4 = NULL ;
if ( ! F_4 ( & V_9 ) ) {
V_4 = F_5 ( V_9 . V_10 , struct V_3 , V_11 ) ;
F_6 ( & V_4 -> V_11 ) ;
}
F_7 ( & V_8 , V_2 ) ;
if ( V_4 == NULL )
return 0 ;
F_8 ( & V_12 ) ;
V_6 = V_4 -> V_6 ;
F_9 ( F_10 ( V_6 ) , V_13 ) ;
F_11 ( V_14 L_2 ,
F_12 ( V_6 -> V_15 ) ) ;
F_13 ( V_16 ) ;
V_6 = F_14 ( V_4 ) ;
if ( V_6 ) {
F_15 ( F_10 ( V_6 ) , V_13 ) ;
F_16 ( V_6 -> V_15 ) ;
}
F_17 ( V_4 ) ;
F_18 ( & V_12 ) ;
if ( V_6 && V_6 -> V_17 > 0 ) {
F_19 ( 3600 * 1000 ) ;
if ( V_6 -> V_17 > 0 )
V_6 -> V_17 -- ;
}
return 0 ;
}
static void F_20 ( struct V_18 * V_1 )
{
if ( F_21 ( F_1 , NULL , V_19 ) < 0 )
F_11 ( V_20 L_3 ) ;
}
int F_22 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = F_10 ( V_6 ) ;
const char * V_23 ;
if ( ! V_24 ) {
F_11 ( V_20 L_4 ) ;
V_23 = F_23 ( V_22 , L_5 , NULL ) ;
F_11 ( V_20 L_6 , V_22 -> V_25 ) ;
F_11 ( V_20 L_7 , V_23 ) ;
return 1 ;
}
V_4 = F_24 ( sizeof( * V_4 ) , V_26 ) ;
if ( V_4 == NULL ) {
F_11 ( V_20 L_8 ) ;
return 1 ;
}
if ( V_6 -> V_15 )
F_25 ( V_6 -> V_15 ) ;
V_4 -> V_6 = V_6 ;
F_3 ( & V_8 , V_2 ) ;
F_26 ( & V_4 -> V_11 , & V_9 ) ;
F_7 ( & V_8 , V_2 ) ;
F_27 ( & V_27 ) ;
return 0 ;
}
