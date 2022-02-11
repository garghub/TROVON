void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
enum V_3 V_4 ;
V_2 = V_5 ;
if ( ! V_2 || ! F_2 () )
return;
V_4 = F_3 ( V_2 -> V_3 ) ;
if ( V_4 == V_6 ) {
unsigned long * V_7 ;
unsigned long V_8 ;
unsigned long V_9 = V_10 ;
#ifdef F_4
V_9 -= F_5 () ;
#endif
F_6 () ;
V_7 = V_2 -> V_11 ;
V_8 = F_3 ( V_7 [ 0 ] ) + 1 ;
if ( F_7 ( V_8 < V_2 -> V_12 ) ) {
V_7 [ V_8 ] = V_9 ;
F_8 ( V_7 [ 0 ] , V_8 ) ;
}
}
}
static void F_9 ( struct V_13 * V_13 )
{
F_10 ( & V_13 -> V_14 ) ;
}
static void F_11 ( struct V_13 * V_13 )
{
if ( F_12 ( & V_13 -> V_14 ) ) {
F_13 ( V_13 -> V_7 ) ;
F_14 ( V_13 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_15 ;
V_2 -> V_12 = 0 ;
V_2 -> V_11 = NULL ;
V_2 -> V_13 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
V_13 = V_2 -> V_13 ;
if ( V_13 == NULL )
return;
F_17 ( & V_13 -> V_16 ) ;
if ( F_18 ( V_13 -> V_2 != V_2 ) ) {
F_19 ( & V_13 -> V_16 ) ;
return;
}
F_15 ( V_2 ) ;
V_13 -> V_2 = NULL ;
F_19 ( & V_13 -> V_16 ) ;
F_11 ( V_13 ) ;
}
static int F_20 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
int V_21 = 0 ;
void * V_7 ;
struct V_13 * V_13 = V_20 -> V_22 -> V_23 ;
unsigned long V_24 , V_25 ;
struct V_26 * V_26 ;
V_7 = F_21 ( V_20 -> V_27 - V_20 -> V_28 ) ;
if ( ! V_7 )
return - V_29 ;
F_17 ( & V_13 -> V_16 ) ;
V_24 = V_13 -> V_24 * sizeof( unsigned long ) ;
if ( V_13 -> V_4 == V_15 || V_20 -> V_30 != 0 ||
V_20 -> V_27 - V_20 -> V_28 != V_24 ) {
V_21 = - V_31 ;
goto exit;
}
if ( ! V_13 -> V_7 ) {
V_13 -> V_7 = V_7 ;
V_20 -> V_32 |= V_33 ;
F_19 ( & V_13 -> V_16 ) ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 += V_34 ) {
V_26 = F_22 ( V_13 -> V_7 + V_25 ) ;
if ( F_23 ( V_20 , V_20 -> V_28 + V_25 , V_26 ) )
F_24 ( 1 , L_1 ) ;
}
return 0 ;
}
exit:
F_19 ( & V_13 -> V_16 ) ;
F_13 ( V_7 ) ;
return V_21 ;
}
static int F_25 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
struct V_13 * V_13 ;
V_13 = F_26 ( sizeof( * V_13 ) , V_36 ) ;
if ( ! V_13 )
return - V_29 ;
F_27 ( & V_13 -> V_14 , 1 ) ;
F_28 ( & V_13 -> V_16 ) ;
V_18 -> V_23 = V_13 ;
return F_29 ( V_35 , V_18 ) ;
}
static int F_30 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
F_11 ( V_18 -> V_23 ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_13 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_1 * V_2 ;
unsigned long V_24 , V_39 ;
switch ( V_37 ) {
case V_40 :
if ( V_13 -> V_4 != V_15 )
return - V_41 ;
V_24 = V_38 ;
if ( V_24 < 2 || V_24 > V_42 / sizeof( unsigned long ) )
return - V_31 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_4 = V_6 ;
return 0 ;
case V_43 :
V_39 = V_38 ;
if ( V_39 != 0 || V_13 -> V_4 == V_15 ||
V_13 -> V_7 == NULL )
return - V_31 ;
if ( V_13 -> V_2 != NULL )
return - V_41 ;
V_2 = V_5 ;
V_2 -> V_12 = V_13 -> V_24 ;
V_2 -> V_11 = V_13 -> V_7 ;
F_6 () ;
F_8 ( V_2 -> V_3 , V_13 -> V_4 ) ;
V_2 -> V_13 = V_13 ;
V_13 -> V_2 = V_2 ;
F_9 ( V_13 ) ;
return 0 ;
case V_44 :
V_39 = V_38 ;
if ( V_39 != 0 || V_5 -> V_13 != V_13 )
return - V_31 ;
V_2 = V_5 ;
if ( F_18 ( V_13 -> V_2 != V_2 ) )
return - V_31 ;
F_15 ( V_2 ) ;
V_13 -> V_2 = NULL ;
F_11 ( V_13 ) ;
return 0 ;
default:
return - V_45 ;
}
}
static long F_32 ( struct V_17 * V_18 , unsigned int V_37 , unsigned long V_38 )
{
struct V_13 * V_13 ;
int V_21 ;
V_13 = V_18 -> V_23 ;
F_17 ( & V_13 -> V_16 ) ;
V_21 = F_31 ( V_13 , V_37 , V_38 ) ;
F_19 ( & V_13 -> V_16 ) ;
return V_21 ;
}
static int T_2 F_33 ( void )
{
if ( ! F_34 ( L_2 , 0600 , NULL , NULL , & V_46 ) ) {
F_35 ( L_3 ) ;
return - V_29 ;
}
return 0 ;
}
