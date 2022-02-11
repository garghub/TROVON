static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
V_4 = V_2 -> V_6 ;
V_5 = F_2 ( V_4 -> V_7 + V_8 ) ;
F_3 () ;
}
static void F_4 ( void * V_9 , const T_2 V_10 ,
unsigned long V_11 )
{
F_5 ( V_9 , V_10 , V_11 ) ;
F_1 ( F_6 ( V_10 ) ) ;
}
static int T_3 F_7 ( struct V_12 * V_13 ,
void T_4 * V_7 )
{
void * V_14 ;
T_5 V_15 ;
#ifdef F_8
T_1 V_5 = F_2 ( V_7 + V_16 ) ;
F_9 ( L_1 , V_5 ) ;
F_10 ( V_7 + V_16 , V_5 | 0x8 ) ;
#endif
V_14 = F_11 ( V_17 , V_18 ) ;
if ( ! V_14 ) {
F_12 ( L_2 ) ;
return - 1 ;
}
V_15 = F_13 ( V_13 -> V_19 , V_14 ,
V_17 , V_20 ) ;
if ( F_14 ( V_13 -> V_19 , V_15 ) ) {
F_12 ( L_3 ) ;
F_15 ( V_14 ) ;
return - 1 ;
}
F_10 ( V_7 + V_21 , V_15 ) ;
return 0 ;
}
int T_3 F_16 ( struct V_1 * V_2 , void * V_22 )
{
void T_4 * V_7 = NULL ;
struct V_3 * V_4 ;
struct V_23 * V_24 = V_2 -> V_13 -> V_25 ;
struct V_26 V_27 ;
unsigned long V_28 = ( unsigned long ) V_22 ;
F_9 ( L_4 ,
V_24 ) ;
V_4 = F_17 ( sizeof( struct V_3 ) , V_18 ) ;
if ( ! V_4 ) {
F_12 ( L_5
L_6 ) ;
return - 1 ;
}
if ( F_18 ( V_24 , 0 , & V_27 ) ) {
F_12 ( L_7 ) ;
goto error;
}
V_7 = F_19 ( V_27 . V_29 + V_28 , V_30 ) ;
if ( ! V_7 ) {
F_12 ( L_8 ) ;
goto error;
}
V_4 -> V_7 = V_7 ;
V_2 -> V_6 = V_4 ;
if ( F_7 ( V_2 -> V_13 , V_7 ) )
goto error;
return 0 ;
error:
F_15 ( V_4 ) ;
V_2 -> V_6 = NULL ;
if ( V_7 )
F_20 ( V_7 ) ;
return - 1 ;
}
