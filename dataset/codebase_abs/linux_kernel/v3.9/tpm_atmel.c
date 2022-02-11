static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
T_1 V_5 , * V_6 = V_3 ;
T_3 V_7 ;
int V_8 ;
T_4 * V_9 ;
if ( V_4 < 6 )
return - V_10 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_5 = F_2 ( V_2 -> V_11 . V_12 + 1 ) ;
if ( ( V_5 & V_13 ) == 0 ) {
F_3 ( V_2 -> V_14 , L_1 ) ;
return - V_10 ;
}
* V_3 ++ = F_2 ( V_2 -> V_11 . V_12 ) ;
}
V_9 = ( V_15 T_4 * ) ( V_6 + 2 ) ;
V_7 = F_4 ( * V_9 ) ;
if ( V_4 < V_7 ) {
F_3 ( V_2 -> V_14 ,
L_2 , V_7 ) ;
for (; V_8 < V_7 ; V_8 ++ ) {
V_5 = F_2 ( V_2 -> V_11 . V_12 + 1 ) ;
if ( ( V_5 & V_13 ) == 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return - V_10 ;
}
}
return - V_10 ;
}
for (; V_8 < V_7 ; V_8 ++ ) {
V_5 = F_2 ( V_2 -> V_11 . V_12 + 1 ) ;
if ( ( V_5 & V_13 ) == 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return - V_10 ;
}
* V_3 ++ = F_2 ( V_2 -> V_11 . V_12 ) ;
}
V_5 = F_2 ( V_2 -> V_11 . V_12 + 1 ) ;
if ( V_5 & V_13 ) {
F_3 ( V_2 -> V_14 , L_4 ) ;
return - V_10 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
int V_8 ;
F_6 ( V_2 -> V_14 , L_5 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
F_6 ( V_2 -> V_14 , L_6 , V_8 , V_3 [ V_8 ] , V_3 [ V_8 ] ) ;
F_7 ( V_3 [ V_8 ] , V_2 -> V_11 . V_12 ) ;
}
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_7 ( V_16 , V_2 -> V_11 . V_12 + 1 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_11 . V_12 + 1 ) ;
}
static bool F_10 ( struct V_1 * V_2 , T_1 V_5 )
{
return ( V_5 == V_17 ) ;
}
static void F_11 ( void )
{
struct V_1 * V_2 = F_12 ( & V_18 -> V_14 ) ;
if ( V_2 ) {
if ( V_2 -> V_11 . V_19 )
F_13 ( V_2 -> V_11 . V_20 ,
V_2 -> V_11 . V_21 ) ;
F_14 ( V_2 -> V_11 . V_12 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_18 ) ;
}
}
static int T_5 F_17 ( void )
{
int V_22 = 0 ;
void T_6 * V_12 = NULL ;
int V_19 , V_21 ;
unsigned long V_20 ;
struct V_1 * V_2 ;
V_22 = F_18 ( & V_23 ) ;
if ( V_22 )
return V_22 ;
if ( ( V_12 = F_19 ( & V_20 , & V_21 ) ) == NULL ) {
V_22 = - V_24 ;
goto V_25;
}
V_19 =
( F_20
( V_26 . V_20 , V_21 , L_7 ) == NULL ) ? 0 : 1 ;
V_18 = F_21 ( L_8 , - 1 , NULL , 0 ) ;
if ( F_22 ( V_18 ) ) {
V_22 = F_23 ( V_18 ) ;
goto V_27;
}
if ( ! ( V_2 = F_24 ( & V_18 -> V_14 , & V_26 ) ) ) {
V_22 = - V_24 ;
goto V_28;
}
V_2 -> V_11 . V_12 = V_12 ;
V_2 -> V_11 . V_20 = V_20 ;
V_2 -> V_11 . V_19 = V_19 ;
V_2 -> V_11 . V_21 = V_21 ;
return 0 ;
V_28:
F_16 ( V_18 ) ;
V_27:
F_14 ( V_12 ) ;
if ( V_19 )
F_13 ( V_20 ,
V_21 ) ;
V_25:
F_25 ( & V_23 ) ;
return V_22 ;
}
static void T_7 F_26 ( void )
{
F_25 ( & V_23 ) ;
F_11 () ;
}
