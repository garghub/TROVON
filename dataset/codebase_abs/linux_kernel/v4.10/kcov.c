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
unsigned long V_12 = V_13 ;
#ifdef F_4
V_12 -= F_5 () ;
#endif
F_6 () ;
V_10 = V_2 -> V_14 ;
V_11 = F_3 ( V_10 [ 0 ] ) + 1 ;
if ( F_7 ( V_11 < V_2 -> V_15 ) ) {
V_10 [ V_11 ] = V_12 ;
F_8 ( V_10 [ 0 ] , V_11 ) ;
}
}
}
static void F_9 ( struct V_16 * V_16 )
{
F_10 ( & V_16 -> V_17 ) ;
}
static void F_11 ( struct V_16 * V_16 )
{
if ( F_12 ( & V_16 -> V_17 ) ) {
F_13 ( V_16 -> V_10 ) ;
F_14 ( V_16 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_18 ;
V_2 -> V_15 = 0 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_16 ;
V_16 = V_2 -> V_16 ;
if ( V_16 == NULL )
return;
F_17 ( & V_16 -> V_19 ) ;
if ( F_18 ( V_16 -> V_2 != V_2 ) ) {
F_19 ( & V_16 -> V_19 ) ;
return;
}
F_15 ( V_2 ) ;
V_16 -> V_2 = NULL ;
F_19 ( & V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
int V_24 = 0 ;
void * V_10 ;
struct V_16 * V_16 = V_23 -> V_25 -> V_26 ;
unsigned long V_27 , V_28 ;
struct V_29 * V_29 ;
V_10 = F_21 ( V_23 -> V_30 - V_23 -> V_31 ) ;
if ( ! V_10 )
return - V_32 ;
F_17 ( & V_16 -> V_19 ) ;
V_27 = V_16 -> V_27 * sizeof( unsigned long ) ;
if ( V_16 -> V_4 == V_18 || V_23 -> V_33 != 0 ||
V_23 -> V_30 - V_23 -> V_31 != V_27 ) {
V_24 = - V_34 ;
goto exit;
}
if ( ! V_16 -> V_10 ) {
V_16 -> V_10 = V_10 ;
V_23 -> V_35 |= V_36 ;
F_19 ( & V_16 -> V_19 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += V_37 ) {
V_29 = F_22 ( V_16 -> V_10 + V_28 ) ;
if ( F_23 ( V_23 , V_23 -> V_31 + V_28 , V_29 ) )
F_24 ( 1 , L_1 ) ;
}
return 0 ;
}
exit:
F_19 ( & V_16 -> V_19 ) ;
F_13 ( V_10 ) ;
return V_24 ;
}
static int F_25 ( struct V_38 * V_38 , struct V_20 * V_21 )
{
struct V_16 * V_16 ;
V_16 = F_26 ( sizeof( * V_16 ) , V_39 ) ;
if ( ! V_16 )
return - V_32 ;
F_27 ( & V_16 -> V_17 , 1 ) ;
F_28 ( & V_16 -> V_19 ) ;
V_21 -> V_26 = V_16 ;
return F_29 ( V_38 , V_21 ) ;
}
static int F_30 ( struct V_38 * V_38 , struct V_20 * V_21 )
{
F_11 ( V_21 -> V_26 ) ;
return 0 ;
}
static int F_31 ( struct V_16 * V_16 , unsigned int V_40 ,
unsigned long V_41 )
{
struct V_1 * V_2 ;
unsigned long V_27 , V_42 ;
switch ( V_40 ) {
case V_43 :
if ( V_16 -> V_4 != V_18 )
return - V_44 ;
V_27 = V_41 ;
if ( V_27 < 2 || V_27 > V_45 / sizeof( unsigned long ) )
return - V_34 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_4 = V_9 ;
return 0 ;
case V_46 :
V_42 = V_41 ;
if ( V_42 != 0 || V_16 -> V_4 == V_18 ||
V_16 -> V_10 == NULL )
return - V_34 ;
if ( V_16 -> V_2 != NULL )
return - V_44 ;
V_2 = V_5 ;
V_2 -> V_15 = V_16 -> V_27 ;
V_2 -> V_14 = V_16 -> V_10 ;
F_6 () ;
F_8 ( V_2 -> V_3 , V_16 -> V_4 ) ;
V_2 -> V_16 = V_16 ;
V_16 -> V_2 = V_2 ;
F_9 ( V_16 ) ;
return 0 ;
case V_47 :
V_42 = V_41 ;
if ( V_42 != 0 || V_5 -> V_16 != V_16 )
return - V_34 ;
V_2 = V_5 ;
if ( F_18 ( V_16 -> V_2 != V_2 ) )
return - V_34 ;
F_15 ( V_2 ) ;
V_16 -> V_2 = NULL ;
F_11 ( V_16 ) ;
return 0 ;
default:
return - V_48 ;
}
}
static long F_32 ( struct V_20 * V_21 , unsigned int V_40 , unsigned long V_41 )
{
struct V_16 * V_16 ;
int V_24 ;
V_16 = V_21 -> V_26 ;
F_17 ( & V_16 -> V_19 ) ;
V_24 = F_31 ( V_16 , V_40 , V_41 ) ;
F_19 ( & V_16 -> V_19 ) ;
return V_24 ;
}
static int T_2 F_33 ( void )
{
if ( ! F_34 ( L_2 , 0600 , NULL , NULL , & V_49 ) ) {
F_35 ( L_3 ) ;
return - V_32 ;
}
return 0 ;
}
