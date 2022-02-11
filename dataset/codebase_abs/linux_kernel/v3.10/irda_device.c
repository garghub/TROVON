int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 ) ;
if ( V_1 == NULL ) {
F_3 ( L_1 ) ;
return - V_3 ;
}
F_4 ( & V_1 -> V_4 ) ;
V_5 = F_2 ( V_6 ) ;
if ( V_5 == NULL ) {
F_3 ( L_2 ) ;
F_5 ( V_1 , NULL ) ;
return - V_3 ;
}
return 0 ;
}
static void F_6 ( void * V_7 )
{
struct V_8 * V_9 = V_7 ;
F_3 ( L_3 ,
V_9 -> type ) ;
}
void F_7 ( void )
{
F_8 ( 4 , L_4 , V_10 ) ;
F_5 ( V_5 , ( V_11 ) V_12 ) ;
F_5 ( V_1 , F_6 ) ;
}
void F_9 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 ;
F_8 ( 4 , L_5 , V_10 , V_15 ? L_6 : L_7 ) ;
V_17 = (struct V_16 * ) V_14 -> V_18 ;
if ( ! V_17 || V_17 -> V_19 != V_20 )
return;
if ( V_15 ) {
V_17 -> V_21 = TRUE ;
if ( V_15 == V_22 )
F_10 ( V_17 , V_23 ) ;
else
F_10 ( V_17 , V_24 ) ;
F_8 ( 4 , L_8 ) ;
} else {
V_17 -> V_21 = FALSE ;
F_11 ( V_17 ) ;
}
}
int F_12 ( struct V_13 * V_14 )
{
struct V_25 V_26 ;
int V_27 ;
F_8 ( 2 , L_4 , V_10 ) ;
if ( ! V_14 -> V_28 -> V_29 ) {
F_13 ( L_9 ,
V_10 ) ;
return - 1 ;
}
V_27 = ( V_14 -> V_28 -> V_29 ) ( V_14 , (struct V_30 * ) & V_26 ,
V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_26 . V_32 ;
}
static void V_12 ( struct V_33 * V_34 )
{
F_14 ( & V_34 -> V_35 ) ;
F_15 ( V_34 ) ;
}
static void F_16 ( struct V_33 * V_34 )
{
F_17 ( V_5 , ( long ) V_34 , NULL ) ;
V_12 ( V_34 ) ;
}
static int F_18 ( struct V_33 * V_34 )
{
int V_36 = TRUE ;
int V_37 = 0 ;
int V_38 ;
F_8 ( 2 , L_4 , V_10 ) ;
F_19 (task != NULL, return -1;) ;
F_19 (task->magic == IRDA_TASK_MAGIC, return -1;) ;
do {
V_38 = V_34 -> V_39 ( V_34 ) ;
if ( V_37 ++ > 100 ) {
F_13 ( L_10 ,
V_10 ) ;
F_16 ( V_34 ) ;
return TRUE ;
}
} while ( ( V_38 == 0 ) && ( V_34 -> V_40 != V_41 ) );
if ( V_38 < 0 ) {
F_13 ( L_11 , V_10 ) ;
F_16 ( V_34 ) ;
return TRUE ;
}
if ( V_34 -> V_40 == V_41 ) {
F_14 ( & V_34 -> V_35 ) ;
if ( V_34 -> V_36 )
V_34 -> V_36 ( V_34 ) ;
if ( V_34 -> V_42 ) {
if ( V_34 -> V_42 -> V_40 == V_43 ) {
V_34 -> V_42 -> V_40 = V_44 ;
F_14 ( & V_34 -> V_42 -> V_35 ) ;
F_18 ( V_34 -> V_42 ) ;
}
}
F_16 ( V_34 ) ;
} else if ( V_38 > 0 ) {
F_20 ( & V_34 -> V_35 , V_38 , ( void * ) V_34 ,
V_45 ) ;
V_36 = FALSE ;
} else {
F_8 ( 0 , L_12 ,
V_10 ) ;
V_36 = FALSE ;
}
return V_36 ;
}
static void V_45 ( void * V_46 )
{
struct V_33 * V_34 ;
F_8 ( 2 , L_4 , V_10 ) ;
V_34 = V_46 ;
F_18 ( V_34 ) ;
}
static void F_21 ( struct V_13 * V_14 )
{
V_14 -> V_47 = 0 ;
V_14 -> V_48 = V_49 ;
V_14 -> type = V_50 ;
V_14 -> V_51 = 8 ;
memset ( V_14 -> V_52 , 0xff , V_49 ) ;
V_14 -> V_53 = 2048 ;
V_14 -> V_54 = V_55 ;
}
struct V_13 * F_22 ( int V_56 )
{
return F_23 ( V_56 , L_13 , F_21 ) ;
}
void F_24 ( int V_57 , T_2 V_58 , int V_37 , int V_59 )
{
unsigned long V_54 ;
V_54 = F_25 () ;
F_26 ( V_57 ) ;
F_27 ( V_57 ) ;
F_28 ( V_57 , V_59 ) ;
F_29 ( V_57 , V_58 ) ;
F_30 ( V_57 , V_37 ) ;
F_31 ( V_57 ) ;
F_32 ( V_54 ) ;
}
