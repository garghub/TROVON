static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 . V_4 = V_5 |
V_6 | V_7 ;
V_2 -> V_3 . V_8 . V_9 = 640 ;
V_2 -> V_3 . V_8 . V_10 = 480 ;
F_2 ( L_2 ,
V_2 -> V_3 . V_8 . V_9 ,
V_2 -> V_3 . V_8 . V_10 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_2 ( L_3 ) ;
F_5 ( & V_12 . V_13 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_11 = - V_16 ;
goto V_17;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
F_7 ( L_4 ) ;
goto V_17;
}
V_2 -> V_14 = V_18 ;
V_17:
F_8 ( & V_12 . V_13 ) ;
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( & V_12 . V_13 ) ;
if ( V_2 -> V_14 == V_18 )
F_10 ( V_2 ) ;
V_2 -> V_14 = V_15 ;
F_8 ( & V_12 . V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_5 ( & V_12 . V_13 ) ;
if ( V_2 -> V_14 != V_18 ) {
V_11 = - V_16 ;
goto V_17;
}
V_2 -> V_14 = V_19 ;
F_10 ( V_2 ) ;
V_17:
F_8 ( & V_12 . V_13 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_5 ( & V_12 . V_13 ) ;
if ( V_2 -> V_14 != V_19 ) {
V_11 = - V_16 ;
goto V_17;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
F_7 ( L_4 ) ;
goto V_17;
}
V_2 -> V_14 = V_18 ;
V_17:
F_8 ( & V_12 . V_13 ) ;
return V_11 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_20 * V_8 )
{
F_5 ( & V_12 . V_13 ) ;
* V_8 = V_2 -> V_3 . V_8 ;
F_8 ( & V_12 . V_13 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_20 * V_8 )
{
F_2 ( L_5 ) ;
F_5 ( & V_12 . V_13 ) ;
V_2 -> V_3 . V_8 = * V_8 ;
if ( V_2 -> V_14 == V_18 ) {
F_10 ( V_2 ) ;
F_15 ( V_2 ) ;
}
F_8 ( & V_12 . V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_8 )
{
int V_11 = 0 ;
F_2 ( L_6 ) ;
F_5 ( & V_12 . V_13 ) ;
V_11 = F_17 ( V_2 , V_8 ) ;
if ( V_11 ) {
F_7 ( L_7 ) ;
goto V_17;
}
V_17:
F_8 ( & V_12 . V_13 ) ;
return V_11 ;
}
int F_18 ( void )
{
F_19 ( & V_12 . V_13 ) ;
F_20 ( & V_21 ) ;
return 0 ;
}
void F_21 ( void )
{
F_22 ( & V_21 ) ;
}
