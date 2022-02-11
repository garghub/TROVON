void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
enum V_3 V_4 ;
V_2 = V_5 ;
if ( ! V_2 || ( F_2 () & ( V_6 | V_7
| V_8 ) ) )
return;
V_4 = F_3 ( V_2 -> V_3 ) ;
if ( V_4 == V_9 ) {
unsigned long * V_10 ;
unsigned long V_11 ;
F_4 () ;
V_10 = V_2 -> V_12 ;
V_11 = F_3 ( V_10 [ 0 ] ) + 1 ;
if ( F_5 ( V_11 < V_2 -> V_13 ) ) {
V_10 [ V_11 ] = V_14 ;
F_6 ( V_10 [ 0 ] , V_11 ) ;
}
}
}
static void F_7 ( struct V_15 * V_15 )
{
F_8 ( & V_15 -> V_16 ) ;
}
static void F_9 ( struct V_15 * V_15 )
{
if ( F_10 ( & V_15 -> V_16 ) ) {
F_11 ( V_15 -> V_10 ) ;
F_12 ( V_15 ) ;
}
}
void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_17 ;
V_2 -> V_13 = 0 ;
V_2 -> V_12 = NULL ;
V_2 -> V_15 = NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_15 ;
V_15 = V_2 -> V_15 ;
if ( V_15 == NULL )
return;
F_15 ( & V_15 -> V_18 ) ;
if ( F_16 ( V_15 -> V_2 != V_2 ) ) {
F_17 ( & V_15 -> V_18 ) ;
return;
}
F_13 ( V_2 ) ;
V_15 -> V_2 = NULL ;
F_17 ( & V_15 -> V_18 ) ;
F_9 ( V_15 ) ;
}
static int F_18 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
int V_23 = 0 ;
void * V_10 ;
struct V_15 * V_15 = V_22 -> V_24 -> V_25 ;
unsigned long V_26 , V_27 ;
struct V_28 * V_28 ;
V_10 = F_19 ( V_22 -> V_29 - V_22 -> V_30 ) ;
if ( ! V_10 )
return - V_31 ;
F_15 ( & V_15 -> V_18 ) ;
V_26 = V_15 -> V_26 * sizeof( unsigned long ) ;
if ( V_15 -> V_4 == V_17 || V_22 -> V_32 != 0 ||
V_22 -> V_29 - V_22 -> V_30 != V_26 ) {
V_23 = - V_33 ;
goto exit;
}
if ( ! V_15 -> V_10 ) {
V_15 -> V_10 = V_10 ;
V_22 -> V_34 |= V_35 ;
F_17 ( & V_15 -> V_18 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 += V_36 ) {
V_28 = F_20 ( V_15 -> V_10 + V_27 ) ;
if ( F_21 ( V_22 , V_22 -> V_30 + V_27 , V_28 ) )
F_22 ( 1 , L_1 ) ;
}
return 0 ;
}
exit:
F_17 ( & V_15 -> V_18 ) ;
F_11 ( V_10 ) ;
return V_23 ;
}
static int F_23 ( struct V_37 * V_37 , struct V_19 * V_20 )
{
struct V_15 * V_15 ;
V_15 = F_24 ( sizeof( * V_15 ) , V_38 ) ;
if ( ! V_15 )
return - V_31 ;
F_25 ( & V_15 -> V_16 , 1 ) ;
F_26 ( & V_15 -> V_18 ) ;
V_20 -> V_25 = V_15 ;
return F_27 ( V_37 , V_20 ) ;
}
static int F_28 ( struct V_37 * V_37 , struct V_19 * V_20 )
{
F_9 ( V_20 -> V_25 ) ;
return 0 ;
}
static int F_29 ( struct V_15 * V_15 , unsigned int V_39 ,
unsigned long V_40 )
{
struct V_1 * V_2 ;
unsigned long V_26 , V_41 ;
switch ( V_39 ) {
case V_42 :
if ( V_15 -> V_4 != V_17 )
return - V_43 ;
V_26 = V_40 ;
if ( V_26 < 2 || V_26 > V_44 / sizeof( unsigned long ) )
return - V_33 ;
V_15 -> V_26 = V_26 ;
V_15 -> V_4 = V_9 ;
return 0 ;
case V_45 :
V_41 = V_40 ;
if ( V_41 != 0 || V_15 -> V_4 == V_17 ||
V_15 -> V_10 == NULL )
return - V_33 ;
if ( V_15 -> V_2 != NULL )
return - V_43 ;
V_2 = V_5 ;
V_2 -> V_13 = V_15 -> V_26 ;
V_2 -> V_12 = V_15 -> V_10 ;
F_4 () ;
F_6 ( V_2 -> V_3 , V_15 -> V_4 ) ;
V_2 -> V_15 = V_15 ;
V_15 -> V_2 = V_2 ;
F_7 ( V_15 ) ;
return 0 ;
case V_46 :
V_41 = V_40 ;
if ( V_41 != 0 || V_5 -> V_15 != V_15 )
return - V_33 ;
V_2 = V_5 ;
if ( F_16 ( V_15 -> V_2 != V_2 ) )
return - V_33 ;
F_13 ( V_2 ) ;
V_15 -> V_2 = NULL ;
F_9 ( V_15 ) ;
return 0 ;
default:
return - V_47 ;
}
}
static long F_30 ( struct V_19 * V_20 , unsigned int V_39 , unsigned long V_40 )
{
struct V_15 * V_15 ;
int V_23 ;
V_15 = V_20 -> V_25 ;
F_15 ( & V_15 -> V_18 ) ;
V_23 = F_29 ( V_15 , V_39 , V_40 ) ;
F_17 ( & V_15 -> V_18 ) ;
return V_23 ;
}
static int T_2 F_31 ( void )
{
if ( ! F_32 ( L_2 , 0600 , NULL , NULL , & V_48 ) ) {
F_33 ( L_3 ) ;
return - V_31 ;
}
return 0 ;
}
