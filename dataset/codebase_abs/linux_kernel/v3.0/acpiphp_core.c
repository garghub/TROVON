int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
if ( V_2 && V_2 -> V_5 && V_2 -> V_6 &&
V_2 -> V_7 && ! V_8 ) {
V_3 = 0 ;
V_8 = V_2 ;
}
return V_3 ;
}
int F_2 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
if ( V_2 && V_8 == V_2 ) {
V_8 = NULL ;
V_3 = 0 ;
}
return V_3 ;
}
static int F_3 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
return F_6 ( V_10 -> V_13 ) ;
}
static int F_7 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
int V_3 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
V_3 = F_8 ( V_10 -> V_13 ) ;
if ( ! V_3 )
V_3 = F_9 ( V_10 -> V_13 ) ;
return V_3 ;
}
static int F_10 ( struct V_9 * V_9 , T_1 V_14 )
{
int V_3 = - V_15 ;
F_4 ( L_1 , V_12 , F_11 ( V_9 ) ) ;
if ( V_8 && F_12 ( V_8 -> V_5 ) ) {
V_3 = V_8 -> V_6 ( V_9 , V_14 ) ;
F_13 ( V_8 -> V_5 ) ;
} else
V_8 = NULL ;
return V_3 ;
}
static int F_14 ( struct V_9 * V_9 , T_1 * V_16 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
* V_16 = F_15 ( V_10 -> V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_9 , T_1 * V_16 )
{
int V_3 = - V_4 ;
F_4 ( L_1 , V_12 , F_11 ( V_9 ) ) ;
if ( V_8 && F_12 ( V_8 -> V_5 ) ) {
V_3 = V_8 -> V_7 ( V_9 , V_16 ) ;
F_13 ( V_8 -> V_5 ) ;
} else
V_8 = NULL ;
return V_3 ;
}
static int F_17 ( struct V_9 * V_9 , T_1 * V_16 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
* V_16 = F_18 ( V_10 -> V_13 ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_9 , T_1 * V_16 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
* V_16 = F_20 ( V_10 -> V_13 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
int V_3 ;
V_3 = F_22 () ;
if ( ! V_3 ) {
V_17 = F_23 () ;
if ( V_17 == 0 ) {
F_24 () ;
V_3 = - V_15 ;
}
}
return V_3 ;
}
static void F_25 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
F_4 ( L_1 , V_12 , F_5 ( V_10 ) ) ;
F_26 ( V_10 -> V_9 ) ;
F_26 ( V_10 ) ;
}
int F_27 ( struct V_18 * V_18 )
{
struct V_10 * V_10 ;
int V_3 = - V_19 ;
char V_20 [ V_21 ] ;
V_10 = F_28 ( sizeof( * V_10 ) , V_22 ) ;
if ( ! V_10 )
goto error;
V_10 -> V_9 = F_28 ( sizeof( * V_10 -> V_9 ) , V_22 ) ;
if ( ! V_10 -> V_9 )
goto V_23;
V_10 -> V_9 -> V_2 = & V_10 -> V_2 ;
V_10 -> V_9 -> V_11 = V_10 ;
V_10 -> V_9 -> V_24 = & F_25 ;
V_10 -> V_9 -> V_25 = & V_26 ;
V_10 -> V_13 = V_18 ;
V_10 -> V_9 -> V_2 -> V_27 = F_15 ( V_10 -> V_13 ) ;
V_10 -> V_9 -> V_2 -> V_28 = 0 ;
V_10 -> V_9 -> V_2 -> V_29 = F_18 ( V_10 -> V_13 ) ;
V_10 -> V_9 -> V_2 -> V_30 = F_20 ( V_10 -> V_13 ) ;
V_18 -> V_10 = V_10 ;
snprintf ( V_20 , V_21 , L_2 , V_10 -> V_13 -> V_31 ) ;
V_3 = F_29 ( V_10 -> V_9 ,
V_18 -> V_32 -> V_33 ,
V_18 -> V_34 ,
V_20 ) ;
if ( V_3 == - V_35 )
goto V_36;
if ( V_3 ) {
F_30 ( L_3 , V_3 ) ;
goto V_36;
}
V_2 ( L_4 , F_5 ( V_10 ) ) ;
return 0 ;
V_36:
F_26 ( V_10 -> V_9 ) ;
V_23:
F_26 ( V_10 ) ;
error:
return V_3 ;
}
void F_31 ( struct V_18 * V_18 )
{
struct V_10 * V_10 = V_18 -> V_10 ;
int V_3 = 0 ;
V_2 ( L_5 , F_5 ( V_10 ) ) ;
V_3 = F_32 ( V_10 -> V_9 ) ;
if ( V_3 )
F_30 ( L_6 , V_3 ) ;
}
static int T_2 F_33 ( void )
{
V_2 ( V_37 L_7 V_38 L_8 ) ;
if ( V_39 )
return 0 ;
V_40 = V_41 ;
return F_21 () ;
}
static void T_3 F_34 ( void )
{
if ( V_39 )
return;
F_24 () ;
}
