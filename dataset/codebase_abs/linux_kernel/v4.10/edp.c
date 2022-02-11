static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
return F_2 ( V_4 -> V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_4 ( V_7 ) ;
if ( ! V_4 )
return;
if ( V_4 -> V_5 ) {
F_5 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
F_6 ( V_7 , NULL ) ;
}
static struct V_3 * F_7 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = NULL ;
int V_8 ;
if ( ! V_7 ) {
F_8 ( L_1 ) ;
V_8 = - V_9 ;
goto V_10;
}
V_4 = F_9 ( & V_7 -> V_11 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 ) {
V_8 = - V_13 ;
goto V_10;
}
F_10 ( L_2 , V_4 ) ;
V_4 -> V_7 = V_7 ;
F_6 ( V_7 , V_4 ) ;
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
goto V_10;
return V_4 ;
V_10:
if ( V_4 )
F_3 ( V_7 ) ;
return F_12 ( V_8 ) ;
}
static int F_13 ( struct V_14 * V_11 , struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_18 = F_14 ( V_15 ) ;
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_3 * V_4 ;
F_10 ( L_3 ) ;
V_4 = F_7 ( F_15 ( V_11 ) ) ;
if ( F_16 ( V_4 ) )
return F_17 ( V_4 ) ;
V_20 -> V_4 = V_4 ;
return 0 ;
}
static void F_18 ( struct V_14 * V_11 , struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_18 = F_14 ( V_15 ) ;
struct V_19 * V_20 = V_18 -> V_21 ;
F_10 ( L_3 ) ;
if ( V_20 -> V_4 ) {
F_3 ( F_15 ( V_11 ) ) ;
V_20 -> V_4 = NULL ;
}
}
static int F_19 ( struct V_6 * V_7 )
{
F_10 ( L_3 ) ;
return F_20 ( & V_7 -> V_11 , & V_22 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
F_10 ( L_3 ) ;
F_22 ( & V_7 -> V_11 , & V_22 ) ;
return 0 ;
}
void T_2 F_23 ( void )
{
F_10 ( L_3 ) ;
F_24 ( & V_23 ) ;
}
void T_3 F_25 ( void )
{
F_10 ( L_3 ) ;
F_26 ( & V_23 ) ;
}
int F_27 ( struct V_3 * V_4 , struct V_17 * V_11 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_19 * V_20 = V_11 -> V_21 ;
int V_8 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_26 = F_28 ( V_4 ) ;
if ( F_16 ( V_4 -> V_26 ) ) {
V_8 = F_17 ( V_4 -> V_26 ) ;
F_29 ( V_11 -> V_11 , L_4 , V_8 ) ;
V_4 -> V_26 = NULL ;
goto V_10;
}
V_4 -> V_27 = F_30 ( V_4 ) ;
if ( F_16 ( V_4 -> V_27 ) ) {
V_8 = F_17 ( V_4 -> V_27 ) ;
F_29 ( V_11 -> V_11 , L_5 , V_8 ) ;
V_4 -> V_27 = NULL ;
goto V_10;
}
V_4 -> V_1 = F_31 ( V_7 -> V_11 . V_28 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
V_8 = V_4 -> V_1 ;
F_29 ( V_11 -> V_11 , L_6 , V_8 ) ;
goto V_10;
}
V_8 = F_32 ( & V_7 -> V_11 , V_4 -> V_1 ,
F_1 , V_29 | V_30 ,
L_7 , V_4 ) ;
if ( V_8 < 0 ) {
F_29 ( V_11 -> V_11 , L_8 ,
V_4 -> V_1 , V_8 ) ;
goto V_10;
}
V_25 -> V_26 = V_4 -> V_26 ;
V_20 -> V_31 [ V_20 -> V_32 ++ ] = V_4 -> V_26 ;
V_20 -> V_33 [ V_20 -> V_34 ++ ] = V_4 -> V_27 ;
return 0 ;
V_10:
if ( V_4 -> V_26 ) {
F_33 ( V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
}
if ( V_4 -> V_27 ) {
V_4 -> V_27 -> V_35 -> V_36 ( V_4 -> V_27 ) ;
V_4 -> V_27 = NULL ;
}
return V_8 ;
}
