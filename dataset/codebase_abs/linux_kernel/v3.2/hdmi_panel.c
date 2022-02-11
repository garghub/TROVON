static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 . V_4 = V_5 |
V_6 | V_7 ;
V_2 -> V_3 . V_8 = (struct V_9 ) { 640 , 480 , 25175 , 96 , 16 , 48 , 2 , 11 , 31 } ;
F_2 ( L_2 ,
V_2 -> V_3 . V_8 . V_10 ,
V_2 -> V_3 . V_8 . V_11 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static int F_4 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
F_2 ( L_3 ) ;
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 != V_16 ) {
V_12 = - V_17 ;
goto V_18;
}
V_12 = F_6 ( V_2 ) ;
if ( V_12 ) {
F_7 ( L_4 ) ;
goto V_18;
}
V_2 -> V_15 = V_19 ;
V_18:
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 == V_19 )
F_10 ( V_2 ) ;
V_2 -> V_15 = V_16 ;
F_8 ( & V_13 . V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 != V_19 ) {
V_12 = - V_17 ;
goto V_18;
}
V_2 -> V_15 = V_20 ;
F_10 ( V_2 ) ;
V_18:
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 != V_20 ) {
V_12 = - V_17 ;
goto V_18;
}
V_12 = F_6 ( V_2 ) ;
if ( V_12 ) {
F_7 ( L_4 ) ;
goto V_18;
}
V_2 -> V_15 = V_19 ;
V_18:
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
F_5 ( & V_13 . V_14 ) ;
* V_8 = V_2 -> V_3 . V_8 ;
F_8 ( & V_13 . V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
F_2 ( L_5 ) ;
F_5 ( & V_13 . V_14 ) ;
V_2 -> V_3 . V_8 = * V_8 ;
F_15 ( V_2 ) ;
F_8 ( & V_13 . V_14 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
int V_12 = 0 ;
F_2 ( L_6 ) ;
F_5 ( & V_13 . V_14 ) ;
V_12 = F_17 ( V_2 , V_8 ) ;
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_21 , int V_22 )
{
int V_12 ;
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 != V_19 ) {
V_12 = F_6 ( V_2 ) ;
if ( V_12 )
goto V_18;
}
V_12 = F_19 ( V_21 , V_22 ) ;
if ( V_2 -> V_15 == V_16 ||
V_2 -> V_15 == V_20 )
F_10 ( V_2 ) ;
V_18:
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
static bool F_20 ( struct V_1 * V_2 )
{
int V_12 ;
F_5 ( & V_13 . V_14 ) ;
if ( V_2 -> V_15 != V_19 ) {
V_12 = F_6 ( V_2 ) ;
if ( V_12 )
goto V_18;
}
V_12 = F_21 () ;
if ( V_2 -> V_15 == V_16 ||
V_2 -> V_15 == V_20 )
F_10 ( V_2 ) ;
V_18:
F_8 ( & V_13 . V_14 ) ;
return V_12 ;
}
int F_22 ( void )
{
F_23 ( & V_13 . V_14 ) ;
F_24 ( & V_23 ) ;
return 0 ;
}
void F_25 ( void )
{
F_26 ( & V_23 ) ;
}
