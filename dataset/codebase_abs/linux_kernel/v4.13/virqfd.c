static int T_1 F_1 ( void )
{
V_1 =
F_2 ( L_1 ) ;
if ( ! V_1 )
return - V_2 ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( V_1 ) ;
}
static void F_5 ( struct V_3 * V_3 )
{
F_6 ( V_1 , & V_3 -> V_4 ) ;
}
static int F_7 ( T_3 * V_5 , unsigned V_6 , int V_7 , void * V_8 )
{
struct V_3 * V_3 = F_8 ( V_5 , struct V_3 , V_5 ) ;
unsigned long V_9 = ( unsigned long ) V_8 ;
if ( V_9 & V_10 ) {
if ( ( ! V_3 -> V_11 ||
V_3 -> V_11 ( V_3 -> V_12 , V_3 -> V_13 ) ) &&
V_3 -> V_14 )
F_9 ( & V_3 -> V_15 ) ;
}
if ( V_9 & V_16 ) {
unsigned long V_9 ;
F_10 ( & V_17 , V_9 ) ;
if ( * ( V_3 -> V_18 ) == V_3 ) {
* ( V_3 -> V_18 ) = NULL ;
F_5 ( V_3 ) ;
}
F_11 ( & V_17 , V_9 ) ;
}
return 0 ;
}
static void F_12 ( struct V_19 * V_19 ,
T_4 * V_20 , T_5 * V_21 )
{
struct V_3 * V_3 = F_8 ( V_21 , struct V_3 , V_21 ) ;
F_13 ( V_20 , & V_3 -> V_5 ) ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_3 * V_3 = F_8 ( V_23 , struct V_3 , V_4 ) ;
T_6 V_24 ;
F_15 ( V_3 -> V_25 , & V_3 -> V_5 , & V_24 ) ;
F_16 ( & V_3 -> V_15 ) ;
F_17 ( V_3 -> V_25 ) ;
F_18 ( V_3 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_3 * V_3 = F_8 ( V_23 , struct V_3 , V_15 ) ;
if ( V_3 -> V_14 )
V_3 -> V_14 ( V_3 -> V_12 , V_3 -> V_13 ) ;
}
int F_20 ( void * V_12 ,
int (* V_11)( void * , void * ) ,
void (* V_14)( void * , void * ) ,
void * V_13 , struct V_3 * * V_18 , int V_26 )
{
struct V_26 V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_3 ;
int V_30 = 0 ;
unsigned int V_31 ;
V_3 = F_21 ( sizeof( * V_3 ) , V_32 ) ;
if ( ! V_3 )
return - V_2 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_11 = V_11 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_13 = V_13 ;
F_22 ( & V_3 -> V_4 , F_14 ) ;
F_22 ( & V_3 -> V_15 , F_19 ) ;
V_27 = F_23 ( V_26 ) ;
if ( ! V_27 . V_19 ) {
V_30 = - V_33 ;
goto V_34;
}
V_29 = F_24 ( V_27 . V_19 ) ;
if ( F_25 ( V_29 ) ) {
V_30 = F_26 ( V_29 ) ;
goto V_35;
}
V_3 -> V_25 = V_29 ;
F_27 ( & V_17 ) ;
if ( * V_18 ) {
F_28 ( & V_17 ) ;
V_30 = - V_36 ;
goto V_37;
}
* V_18 = V_3 ;
F_28 ( & V_17 ) ;
F_29 ( & V_3 -> V_5 , F_7 ) ;
F_30 ( & V_3 -> V_21 , F_12 ) ;
V_31 = V_27 . V_19 -> V_38 -> V_39 ( V_27 . V_19 , & V_3 -> V_21 ) ;
if ( V_31 & V_10 ) {
if ( ( ! V_11 || V_11 ( V_12 , V_13 ) ) && V_14 )
F_9 ( & V_3 -> V_15 ) ;
}
F_31 ( V_27 ) ;
return 0 ;
V_37:
F_17 ( V_29 ) ;
V_35:
F_31 ( V_27 ) ;
V_34:
F_18 ( V_3 ) ;
return V_30 ;
}
void F_32 ( struct V_3 * * V_18 )
{
unsigned long V_9 ;
F_10 ( & V_17 , V_9 ) ;
if ( * V_18 ) {
F_5 ( * V_18 ) ;
* V_18 = NULL ;
}
F_11 ( & V_17 , V_9 ) ;
F_33 ( V_1 ) ;
}
