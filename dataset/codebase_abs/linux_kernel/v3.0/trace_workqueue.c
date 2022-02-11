static void F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 , struct V_2 , V_1 ) ) ;
}
static void
F_4 ( void * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 = F_5 ( & V_5 -> V_9 ) ;
struct V_2 * V_10 ;
unsigned long V_11 ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
F_8 (node, &workqueue_cpu_stat(cpu)->list, list) {
if ( V_10 -> V_13 == V_5 -> V_13 ) {
F_9 ( & V_10 -> V_14 ) ;
goto V_15;
}
}
F_10 ( L_1 ) ;
V_15:
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
}
static void
F_12 ( void * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 = F_5 ( & V_5 -> V_9 ) ;
struct V_2 * V_10 ;
unsigned long V_11 ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
F_8 (node, &workqueue_cpu_stat(cpu)->list, list) {
if ( V_10 -> V_13 == V_5 -> V_13 ) {
V_10 -> V_16 ++ ;
goto V_15;
}
}
F_10 ( L_1 ) ;
V_15:
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
}
static void F_13 ( void * V_3 ,
struct V_4 * V_5 , int V_8 )
{
struct V_2 * V_17 ;
unsigned long V_11 ;
F_14 ( V_8 < 0 ) ;
V_17 = F_15 ( sizeof( struct V_2 ) , V_18 ) ;
if ( ! V_17 ) {
F_16 ( L_2 ) ;
return;
}
F_17 ( & V_17 -> V_19 ) ;
F_18 ( & V_17 -> V_1 ) ;
V_17 -> V_8 = V_8 ;
V_17 -> V_13 = V_5 -> V_13 ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
F_19 ( & V_17 -> V_19 , & F_7 ( V_8 ) -> V_19 ) ;
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
}
static void
F_20 ( void * V_3 , struct V_4 * V_5 )
{
int V_8 = F_5 ( & V_5 -> V_9 ) ;
struct V_2 * V_10 , * V_20 ;
unsigned long V_11 ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
F_21 (node, next, &workqueue_cpu_stat(cpu)->list,
list) {
if ( V_10 -> V_13 == V_5 -> V_13 ) {
F_22 ( & V_10 -> V_19 ) ;
F_23 ( & V_10 -> V_1 , F_1 ) ;
goto V_15;
}
}
F_10 ( L_3 ) ;
V_15:
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
}
static struct V_2 * F_24 ( int V_8 )
{
unsigned long V_11 ;
struct V_2 * V_21 = NULL ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
if ( ! F_25 ( & F_7 ( V_8 ) -> V_19 ) ) {
V_21 = F_26 ( F_7 ( V_8 ) -> V_19 . V_20 ,
struct V_2 , V_19 ) ;
F_27 ( & V_21 -> V_1 ) ;
}
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
return V_21 ;
}
static void * F_28 ( struct V_22 * V_23 )
{
int V_8 ;
void * V_21 = NULL ;
F_29 (cpu) {
V_21 = F_24 ( V_8 ) ;
if ( V_21 )
return V_21 ;
}
return NULL ;
}
static void * F_30 ( void * V_24 , int V_25 )
{
struct V_2 * V_26 = V_24 ;
struct V_2 * V_21 ;
int V_8 = V_26 -> V_8 ;
unsigned long V_11 ;
F_6 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
if ( F_31 ( & V_26 -> V_19 , & F_7 ( V_8 ) -> V_19 ) ) {
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
do {
V_8 = F_32 ( V_8 , V_27 ) ;
if ( V_8 >= V_28 )
return NULL ;
} while ( ! ( V_21 = F_24 ( V_8 ) ) );
return V_21 ;
} else {
V_21 = F_26 ( V_26 -> V_19 . V_20 ,
struct V_2 , V_19 ) ;
F_27 ( & V_21 -> V_1 ) ;
}
F_11 ( & F_7 ( V_8 ) -> V_12 , V_11 ) ;
return V_21 ;
}
static int F_33 ( struct V_29 * V_30 , void * V_31 )
{
struct V_2 * V_17 = V_31 ;
struct V_13 * V_13 ;
struct V_4 * V_32 ;
V_13 = F_34 ( V_17 -> V_13 ) ;
if ( V_13 ) {
V_32 = F_35 ( V_13 , V_33 ) ;
if ( V_32 ) {
F_36 ( V_30 , L_4 , V_17 -> V_8 ,
F_37 ( & V_17 -> V_14 ) , V_17 -> V_16 ,
V_32 -> V_34 ) ;
F_38 ( V_32 ) ;
}
F_39 ( V_13 ) ;
}
return 0 ;
}
static void F_40 ( void * V_35 )
{
struct V_2 * V_10 = V_35 ;
F_23 ( & V_10 -> V_1 , F_1 ) ;
}
static int F_41 ( struct V_29 * V_30 )
{
F_36 ( V_30 , L_5 ) ;
F_36 ( V_30 , L_6 ) ;
return 0 ;
}
int T_1 F_42 ( void )
{
if ( F_43 ( & V_36 ) ) {
F_16 ( L_7 ) ;
return 1 ;
}
return 0 ;
}
int T_1 F_44 ( void )
{
int V_21 , V_8 ;
F_29 (cpu) {
F_45 ( & F_7 ( V_8 ) -> V_12 ) ;
F_17 ( & F_7 ( V_8 ) -> V_19 ) ;
}
V_21 = F_46 ( F_4 , NULL ) ;
if ( V_21 )
goto V_37;
V_21 = F_47 ( F_12 , NULL ) ;
if ( V_21 )
goto V_38;
V_21 = F_48 ( F_13 , NULL ) ;
if ( V_21 )
goto V_39;
V_21 = F_49 ( F_20 , NULL ) ;
if ( V_21 )
goto V_40;
return 0 ;
V_40:
F_50 ( F_13 , NULL ) ;
V_39:
F_51 ( F_12 , NULL ) ;
V_38:
F_52 ( F_4 , NULL ) ;
V_37:
F_16 ( L_8 ) ;
return 1 ;
}
