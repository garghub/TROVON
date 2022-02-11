static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_8 , * V_9 = V_3 ;
T_3 V_10 ;
int V_11 ;
T_4 * V_12 ;
if ( V_4 < 6 )
return - V_13 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
V_8 = F_3 ( V_6 -> V_14 + 1 ) ;
if ( ( V_8 & V_15 ) == 0 ) {
F_4 ( & V_2 -> V_7 , L_1 ) ;
return - V_13 ;
}
* V_3 ++ = F_3 ( V_6 -> V_14 ) ;
}
V_12 = ( V_16 T_4 * ) ( V_9 + 2 ) ;
V_10 = F_5 ( * V_12 ) ;
if ( V_4 < V_10 ) {
F_4 ( & V_2 -> V_7 ,
L_2 , V_10 ) ;
for (; V_11 < V_10 ; V_11 ++ ) {
V_8 = F_3 ( V_6 -> V_14 + 1 ) ;
if ( ( V_8 & V_15 ) == 0 ) {
F_4 ( & V_2 -> V_7 , L_3 ) ;
return - V_13 ;
}
}
return - V_13 ;
}
for (; V_11 < V_10 ; V_11 ++ ) {
V_8 = F_3 ( V_6 -> V_14 + 1 ) ;
if ( ( V_8 & V_15 ) == 0 ) {
F_4 ( & V_2 -> V_7 , L_3 ) ;
return - V_13 ;
}
* V_3 ++ = F_3 ( V_6 -> V_14 ) ;
}
V_8 = F_3 ( V_6 -> V_14 + 1 ) ;
if ( V_8 & V_15 ) {
F_4 ( & V_2 -> V_7 , L_4 ) ;
return - V_13 ;
}
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_11 ;
F_7 ( & V_2 -> V_7 , L_5 ) ;
for ( V_11 = 0 ; V_11 < V_4 ; V_11 ++ ) {
F_7 ( & V_2 -> V_7 , L_6 , V_11 , V_3 [ V_11 ] , V_3 [ V_11 ] ) ;
F_8 ( V_3 [ V_11 ] , V_6 -> V_14 ) ;
}
return V_4 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
F_8 ( V_17 , V_6 -> V_14 + 1 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
return F_3 ( V_6 -> V_14 + 1 ) ;
}
static bool F_11 ( struct V_1 * V_2 , T_1 V_8 )
{
return ( V_8 == V_18 ) ;
}
static void F_12 ( void )
{
struct V_1 * V_2 = F_2 ( & V_19 -> V_7 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
F_13 ( V_2 ) ;
if ( V_6 -> V_20 )
F_14 ( V_6 -> V_21 , V_6 -> V_22 ) ;
F_15 ( V_6 -> V_14 ) ;
F_16 ( V_19 ) ;
}
static int T_5 F_17 ( void )
{
int V_23 = 0 ;
void T_6 * V_14 = NULL ;
int V_20 , V_22 ;
unsigned long V_21 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_23 = F_18 ( & V_24 ) ;
if ( V_23 )
return V_23 ;
if ( ( V_14 = F_19 ( & V_21 , & V_22 ) ) == NULL ) {
V_23 = - V_25 ;
goto V_26;
}
V_20 =
( F_20
( V_21 , V_22 , L_7 ) == NULL ) ? 0 : 1 ;
V_19 = F_21 ( L_8 , - 1 , NULL , 0 ) ;
if ( F_22 ( V_19 ) ) {
V_23 = F_23 ( V_19 ) ;
goto V_27;
}
V_6 = F_24 ( & V_19 -> V_7 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 ) {
V_23 = - V_29 ;
goto V_30;
}
V_6 -> V_14 = V_14 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_22 = V_22 ;
V_2 = F_25 ( & V_19 -> V_7 , & V_31 ) ;
if ( F_22 ( V_2 ) ) {
V_23 = F_23 ( V_2 ) ;
goto V_30;
}
F_26 ( & V_2 -> V_7 , V_6 ) ;
V_23 = F_27 ( V_2 ) ;
if ( V_23 )
goto V_30;
return 0 ;
V_30:
F_16 ( V_19 ) ;
V_27:
F_15 ( V_14 ) ;
if ( V_20 )
F_14 ( V_21 ,
V_22 ) ;
V_26:
F_28 ( & V_24 ) ;
return V_23 ;
}
static void T_7 F_29 ( void )
{
F_28 ( & V_24 ) ;
F_12 () ;
}
