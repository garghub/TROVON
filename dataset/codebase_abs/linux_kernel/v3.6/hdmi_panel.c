static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 . V_4 = (struct V_5 )
{ 640 , 480 , 25175 , 96 , 16 , 48 , 2 , 11 , 31 ,
V_6 , V_6 ,
false ,
} ;
F_2 ( L_2 ,
V_2 -> V_3 . V_4 . V_7 ,
V_2 -> V_3 . V_4 . V_8 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_10 ;
F_5 ( & V_11 . V_12 ) ;
F_6 ( & V_11 . V_13 , V_9 ) ;
if ( V_2 -> V_14 != V_15 ||
! F_7 () ) {
F_8 ( L_3 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_10 = F_9 () ;
if ( ! V_10 )
V_2 -> V_18 = V_19 ;
V_17:
F_10 ( & V_11 . V_13 , V_9 ) ;
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_6 ( & V_11 . V_13 , V_9 ) ;
F_13 () ;
V_2 -> V_18 = V_20 ;
F_10 ( & V_11 . V_13 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_10 ;
F_6 ( & V_11 . V_13 , V_9 ) ;
if ( V_2 -> V_18 != V_19 ) {
F_8 ( L_4 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_10 = F_15 () ;
if ( ! V_10 )
V_2 -> V_18 = V_21 ;
V_17:
F_10 ( & V_11 . V_13 , V_9 ) ;
return V_10 ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_6 ( & V_11 . V_13 , V_9 ) ;
F_17 () ;
V_2 -> V_18 = V_19 ;
F_10 ( & V_11 . V_13 , V_9 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
bool V_10 = false ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_15 )
goto V_17;
if ( ! F_7 () )
goto V_17;
V_10 = true ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
unsigned long V_9 ;
int V_10 ;
F_5 ( & V_11 . V_12 ) ;
F_6 ( & V_11 . V_13 , V_9 ) ;
if ( V_2 -> V_14 != V_15 ||
! F_7 () ) {
F_8 ( L_3 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_10 = F_20 ( V_23 ) ;
if ( ! V_10 )
V_2 -> V_18 = V_24 ;
V_17:
F_10 ( & V_11 . V_13 , V_9 ) ;
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return - V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
}
static int F_14 ( struct V_1 * V_2 )
{
return - V_16 ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static bool F_18 ( struct V_1 * V_2 )
{
return false ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
return - V_16 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_2 ( L_5 ) ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_25 ) {
V_10 = - V_26 ;
goto V_17;
}
V_10 = F_22 ( V_2 ) ;
if ( V_10 ) {
F_8 ( L_6 ) ;
goto V_17;
}
V_2 -> V_14 = V_15 ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 == V_15 ) {
F_12 ( V_2 ) ;
F_24 ( V_2 ) ;
}
V_2 -> V_14 = V_25 ;
F_11 ( & V_11 . V_12 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_10 = - V_26 ;
goto V_17;
}
F_12 ( V_2 ) ;
V_2 -> V_14 = V_27 ;
F_24 ( V_2 ) ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_27 ) {
V_10 = - V_26 ;
goto V_17;
}
V_10 = F_22 ( V_2 ) ;
if ( V_10 ) {
F_8 ( L_6 ) ;
goto V_17;
}
V_2 -> V_14 = V_15 ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
F_5 ( & V_11 . V_12 ) ;
* V_4 = V_2 -> V_3 . V_4 ;
F_11 ( & V_11 . V_12 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
F_2 ( L_7 ) ;
F_5 ( & V_11 . V_12 ) ;
F_12 ( V_2 ) ;
V_2 -> V_3 . V_4 = * V_4 ;
F_29 ( V_2 ) ;
F_11 ( & V_11 . V_12 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
int V_10 = 0 ;
F_2 ( L_8 ) ;
F_5 ( & V_11 . V_12 ) ;
V_10 = F_31 ( V_2 , V_4 ) ;
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_28 , int V_29 )
{
int V_10 ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_10 = F_22 ( V_2 ) ;
if ( V_10 )
goto V_17;
}
V_10 = F_33 ( V_28 , V_29 ) ;
if ( V_2 -> V_14 == V_25 ||
V_2 -> V_14 == V_27 )
F_24 ( V_2 ) ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
int V_10 ;
F_5 ( & V_11 . V_12 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_10 = F_22 ( V_2 ) ;
if ( V_10 )
goto V_17;
}
V_10 = F_35 () ;
if ( V_2 -> V_14 == V_25 ||
V_2 -> V_14 == V_27 )
F_24 ( V_2 ) ;
V_17:
F_11 ( & V_11 . V_12 ) ;
return V_10 ;
}
int F_36 ( void )
{
F_37 ( & V_11 . V_12 ) ;
#if F_38 ( V_30 )
F_39 ( & V_11 . V_13 ) ;
#endif
F_40 ( & V_31 ) ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( & V_31 ) ;
}
