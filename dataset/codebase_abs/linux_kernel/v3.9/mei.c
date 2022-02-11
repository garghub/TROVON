static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_4 L_1 , V_5 ) ;
V_3 -> V_6 = 1 ;
return 0 ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_4 L_1 , V_5 ) ;
V_3 -> V_6 = 0 ;
}
static int F_4 ( void * V_1 , struct V_7 * V_8 )
{
struct V_2 * V_3 = V_1 ;
int V_9 ;
F_5 ( L_2 , V_8 ) ;
V_9 = F_6 ( V_3 -> V_10 , V_8 -> V_11 , V_8 -> V_12 ) ;
if ( V_9 > 0 )
V_9 = 0 ;
return V_9 ;
}
static void F_7 ( struct V_13 * V_10 , T_1 V_14 ,
void * V_15 )
{
struct V_2 * V_3 = V_15 ;
if ( V_3 -> V_16 != 0 )
return;
if ( V_14 & F_8 ( V_17 ) ) {
struct V_7 * V_8 ;
int V_18 ;
V_8 = F_9 ( V_19 , V_20 ) ;
if ( ! V_8 )
return;
V_18 = F_10 ( V_10 , V_8 -> V_11 , V_19 ) ;
if ( V_18 < V_21 ) {
F_11 ( V_8 ) ;
return;
}
F_12 ( V_8 , V_18 ) ;
F_13 ( V_8 , V_21 ) ;
F_14 ( L_3 , V_8 ) ;
F_15 ( V_3 -> V_22 , V_8 ) ;
}
}
static int F_16 ( struct V_13 * V_10 ,
const struct V_23 * V_24 )
{
struct V_2 * V_3 ;
int V_9 ;
F_2 ( L_4 ) ;
V_3 = F_17 ( sizeof( struct V_2 ) , V_20 ) ;
if ( ! V_3 ) {
F_18 ( L_5 ) ;
return - V_25 ;
}
V_3 -> V_10 = V_10 ;
F_19 ( V_10 , V_3 ) ;
V_9 = F_20 ( V_10 , F_7 , V_3 ) ;
if ( V_9 ) {
F_18 ( V_26 L_6 ) ;
goto V_27;
}
V_9 = F_21 ( V_3 , & V_28 , V_29 ,
V_21 , 0 , V_30 ,
& V_3 -> V_22 ) ;
if ( V_9 < 0 )
goto V_27;
return 0 ;
V_27:
F_11 ( V_3 ) ;
return V_9 ;
}
static int F_22 ( struct V_13 * V_10 )
{
struct V_2 * V_3 = F_23 ( V_10 ) ;
F_2 ( L_7 ) ;
F_24 ( V_3 -> V_22 ) ;
if ( V_3 -> V_6 )
F_3 ( V_3 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_25 ( void )
{
int V_9 ;
F_26 ( V_4 L_1 , V_5 ) ;
V_9 = F_27 ( & V_31 ) ;
if ( V_9 ) {
F_18 ( V_26 L_8 ) ;
return V_9 ;
}
return 0 ;
}
static void F_28 ( void )
{
F_29 ( & V_31 ) ;
}
