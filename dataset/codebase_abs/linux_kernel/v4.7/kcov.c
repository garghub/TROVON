void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
enum V_3 V_4 ;
V_2 = V_5 ;
if ( ! V_2 || F_2 () )
return;
V_4 = F_3 ( V_2 -> V_3 ) ;
if ( V_4 == V_6 ) {
unsigned long * V_7 ;
unsigned long V_8 ;
F_4 () ;
V_7 = V_2 -> V_9 ;
V_8 = F_3 ( V_7 [ 0 ] ) + 1 ;
if ( F_5 ( V_8 < V_2 -> V_10 ) ) {
V_7 [ V_8 ] = V_11 ;
F_6 ( V_7 [ 0 ] , V_8 ) ;
}
}
}
static void F_7 ( struct V_12 * V_12 )
{
F_8 ( & V_12 -> V_13 ) ;
}
static void F_9 ( struct V_12 * V_12 )
{
if ( F_10 ( & V_12 -> V_13 ) ) {
F_11 ( V_12 -> V_7 ) ;
F_12 ( V_12 ) ;
}
}
void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_14 ;
V_2 -> V_10 = 0 ;
V_2 -> V_9 = NULL ;
V_2 -> V_12 = NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_12 * V_12 ;
V_12 = V_2 -> V_12 ;
if ( V_12 == NULL )
return;
F_15 ( & V_12 -> V_15 ) ;
if ( F_16 ( V_12 -> V_2 != V_2 ) ) {
F_17 ( & V_12 -> V_15 ) ;
return;
}
F_13 ( V_2 ) ;
V_12 -> V_2 = NULL ;
F_17 ( & V_12 -> V_15 ) ;
F_9 ( V_12 ) ;
}
static int F_18 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
void * V_7 ;
struct V_12 * V_12 = V_19 -> V_21 -> V_22 ;
unsigned long V_23 , V_24 ;
struct V_25 * V_25 ;
V_7 = F_19 ( V_19 -> V_26 - V_19 -> V_27 ) ;
if ( ! V_7 )
return - V_28 ;
F_15 ( & V_12 -> V_15 ) ;
V_23 = V_12 -> V_23 * sizeof( unsigned long ) ;
if ( V_12 -> V_4 == V_14 || V_19 -> V_29 != 0 ||
V_19 -> V_26 - V_19 -> V_27 != V_23 ) {
V_20 = - V_30 ;
goto exit;
}
if ( ! V_12 -> V_7 ) {
V_12 -> V_7 = V_7 ;
V_19 -> V_31 |= V_32 ;
F_17 ( & V_12 -> V_15 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 += V_33 ) {
V_25 = F_20 ( V_12 -> V_7 + V_24 ) ;
if ( F_21 ( V_19 , V_19 -> V_27 + V_24 , V_25 ) )
F_22 ( 1 , L_1 ) ;
}
return 0 ;
}
exit:
F_17 ( & V_12 -> V_15 ) ;
F_11 ( V_7 ) ;
return V_20 ;
}
static int F_23 ( struct V_34 * V_34 , struct V_16 * V_17 )
{
struct V_12 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_35 ) ;
if ( ! V_12 )
return - V_28 ;
F_25 ( & V_12 -> V_13 , 1 ) ;
F_26 ( & V_12 -> V_15 ) ;
V_17 -> V_22 = V_12 ;
return F_27 ( V_34 , V_17 ) ;
}
static int F_28 ( struct V_34 * V_34 , struct V_16 * V_17 )
{
F_9 ( V_17 -> V_22 ) ;
return 0 ;
}
static int F_29 ( struct V_12 * V_12 , unsigned int V_36 ,
unsigned long V_37 )
{
struct V_1 * V_2 ;
unsigned long V_23 , V_38 ;
switch ( V_36 ) {
case V_39 :
if ( V_12 -> V_4 != V_14 )
return - V_40 ;
V_23 = V_37 ;
if ( V_23 < 2 || V_23 > V_41 / sizeof( unsigned long ) )
return - V_30 ;
V_12 -> V_23 = V_23 ;
V_12 -> V_4 = V_6 ;
return 0 ;
case V_42 :
V_38 = V_37 ;
if ( V_38 != 0 || V_12 -> V_4 == V_14 ||
V_12 -> V_7 == NULL )
return - V_30 ;
if ( V_12 -> V_2 != NULL )
return - V_40 ;
V_2 = V_5 ;
V_2 -> V_10 = V_12 -> V_23 ;
V_2 -> V_9 = V_12 -> V_7 ;
F_4 () ;
F_6 ( V_2 -> V_3 , V_12 -> V_4 ) ;
V_2 -> V_12 = V_12 ;
V_12 -> V_2 = V_2 ;
F_7 ( V_12 ) ;
return 0 ;
case V_43 :
V_38 = V_37 ;
if ( V_38 != 0 || V_5 -> V_12 != V_12 )
return - V_30 ;
V_2 = V_5 ;
if ( F_16 ( V_12 -> V_2 != V_2 ) )
return - V_30 ;
F_13 ( V_2 ) ;
V_12 -> V_2 = NULL ;
F_9 ( V_12 ) ;
return 0 ;
default:
return - V_44 ;
}
}
static long F_30 ( struct V_16 * V_17 , unsigned int V_36 , unsigned long V_37 )
{
struct V_12 * V_12 ;
int V_20 ;
V_12 = V_17 -> V_22 ;
F_15 ( & V_12 -> V_15 ) ;
V_20 = F_29 ( V_12 , V_36 , V_37 ) ;
F_17 ( & V_12 -> V_15 ) ;
return V_20 ;
}
static int T_2 F_31 ( void )
{
if ( ! F_32 ( L_2 , 0600 , NULL , NULL , & V_45 ) ) {
F_33 ( L_3 ) ;
return - V_28 ;
}
return 0 ;
}
