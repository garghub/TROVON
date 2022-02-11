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
unsigned long V_12 ;
int V_13 ;
F_5 ( & V_14 . V_15 ) ;
F_6 ( & V_14 . V_16 , V_12 ) ;
if ( V_2 -> V_17 != V_18 ||
! F_7 () ) {
F_8 ( L_3 ) ;
V_13 = - V_19 ;
goto V_20;
}
V_13 = F_9 () ;
if ( ! V_13 )
V_2 -> V_21 = V_22 ;
V_20:
F_10 ( & V_14 . V_16 , V_12 ) ;
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_6 ( & V_14 . V_16 , V_12 ) ;
F_13 () ;
V_2 -> V_21 = V_23 ;
F_10 ( & V_14 . V_16 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
int V_13 ;
F_6 ( & V_14 . V_16 , V_12 ) ;
if ( V_2 -> V_21 != V_22 ) {
F_8 ( L_4 ) ;
V_13 = - V_19 ;
goto V_20;
}
V_13 = F_15 () ;
if ( ! V_13 )
V_2 -> V_21 = V_24 ;
V_20:
F_10 ( & V_14 . V_16 , V_12 ) ;
return V_13 ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_6 ( & V_14 . V_16 , V_12 ) ;
F_17 () ;
V_2 -> V_21 = V_22 ;
F_10 ( & V_14 . V_16 , V_12 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
bool V_13 = false ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_18 )
goto V_20;
if ( ! F_7 () )
goto V_20;
V_13 = true ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
unsigned long V_12 ;
int V_13 ;
F_5 ( & V_14 . V_15 ) ;
F_6 ( & V_14 . V_16 , V_12 ) ;
if ( V_2 -> V_17 != V_18 ||
! F_7 () ) {
F_8 ( L_3 ) ;
V_13 = - V_19 ;
goto V_20;
}
V_13 = F_20 ( V_26 ) ;
if ( ! V_13 )
V_2 -> V_21 = V_27 ;
V_20:
F_10 ( & V_14 . V_16 , V_12 ) ;
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return - V_19 ;
}
static void F_12 ( struct V_1 * V_2 )
{
}
static int F_14 ( struct V_1 * V_2 )
{
return - V_19 ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static bool F_18 ( struct V_1 * V_2 )
{
return false ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
return - V_19 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_2 ( L_5 ) ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_28 ) {
V_13 = - V_29 ;
goto V_20;
}
V_13 = F_22 ( V_2 ) ;
if ( V_13 ) {
F_8 ( L_6 ) ;
goto V_20;
}
V_2 -> V_17 = V_18 ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 == V_18 ) {
F_12 ( V_2 ) ;
F_24 ( V_2 ) ;
}
V_2 -> V_17 = V_28 ;
F_11 ( & V_14 . V_15 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_18 ) {
V_13 = - V_29 ;
goto V_20;
}
F_12 ( V_2 ) ;
V_2 -> V_17 = V_30 ;
F_24 ( V_2 ) ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_30 ) {
V_13 = - V_29 ;
goto V_20;
}
V_13 = F_22 ( V_2 ) ;
if ( V_13 ) {
F_8 ( L_6 ) ;
goto V_20;
}
V_2 -> V_17 = V_18 ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
F_5 ( & V_14 . V_15 ) ;
* V_8 = V_2 -> V_3 . V_8 ;
F_11 ( & V_14 . V_15 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
F_2 ( L_7 ) ;
F_5 ( & V_14 . V_15 ) ;
F_12 ( V_2 ) ;
V_2 -> V_3 . V_8 = * V_8 ;
F_29 ( V_2 ) ;
F_11 ( & V_14 . V_15 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
int V_13 = 0 ;
F_2 ( L_8 ) ;
F_5 ( & V_14 . V_15 ) ;
V_13 = F_31 ( V_2 , V_8 ) ;
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_31 , int V_32 )
{
int V_13 ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_18 ) {
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
goto V_20;
}
V_13 = F_33 ( V_31 , V_32 ) ;
if ( V_2 -> V_17 == V_28 ||
V_2 -> V_17 == V_30 )
F_24 ( V_2 ) ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
int V_13 ;
F_5 ( & V_14 . V_15 ) ;
if ( V_2 -> V_17 != V_18 ) {
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
goto V_20;
}
V_13 = F_35 () ;
if ( V_2 -> V_17 == V_28 ||
V_2 -> V_17 == V_30 )
F_24 ( V_2 ) ;
V_20:
F_11 ( & V_14 . V_15 ) ;
return V_13 ;
}
int F_36 ( void )
{
F_37 ( & V_14 . V_15 ) ;
#if F_38 ( V_33 )
F_39 ( & V_14 . V_16 ) ;
#endif
F_40 ( & V_34 ) ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( & V_34 ) ;
}
