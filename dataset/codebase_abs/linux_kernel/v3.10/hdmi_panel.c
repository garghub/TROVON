static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 V_4 = {
. V_5 = 640 ,
. V_6 = 480 ,
. V_7 = 25175 ,
. V_8 = 96 ,
. V_9 = 16 ,
. V_10 = 48 ,
. V_11 = 2 ,
. V_12 = 11 ,
. V_13 = 31 ,
. V_14 = V_15 ,
. V_16 = V_15 ,
. V_17 = false ,
} ;
F_2 ( L_1 ) ;
V_2 -> V_18 . V_19 = V_4 ;
F_2 ( L_2 ,
V_2 -> V_18 . V_19 . V_5 ,
V_2 -> V_18 . V_19 . V_6 ) ;
F_3 ( V_2 , & V_2 -> V_18 . V_19 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
int V_21 ;
F_6 ( & V_22 . V_23 ) ;
F_7 ( & V_22 . V_24 , V_20 ) ;
if ( V_2 -> V_25 != V_26 ||
! F_8 () ) {
F_9 ( L_3 ) ;
V_21 = - V_27 ;
goto V_28;
}
V_21 = F_10 () ;
if ( ! V_21 )
V_2 -> V_29 = V_30 ;
V_28:
F_11 ( & V_22 . V_24 , V_20 ) ;
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_7 ( & V_22 . V_24 , V_20 ) ;
F_14 () ;
V_2 -> V_29 = V_31 ;
F_11 ( & V_22 . V_24 , V_20 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
int V_21 ;
F_7 ( & V_22 . V_24 , V_20 ) ;
if ( V_2 -> V_29 != V_30 ) {
F_9 ( L_4 ) ;
V_21 = - V_27 ;
goto V_28;
}
V_21 = F_16 () ;
if ( ! V_21 )
V_2 -> V_29 = V_32 ;
V_28:
F_11 ( & V_22 . V_24 , V_20 ) ;
return V_21 ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_7 ( & V_22 . V_24 , V_20 ) ;
F_18 () ;
V_2 -> V_29 = V_30 ;
F_11 ( & V_22 . V_24 , V_20 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
bool V_21 = false ;
F_6 ( & V_22 . V_23 ) ;
if ( V_2 -> V_25 != V_26 )
goto V_28;
if ( ! F_8 () )
goto V_28;
V_21 = true ;
V_28:
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
unsigned long V_20 ;
int V_21 ;
F_6 ( & V_22 . V_23 ) ;
F_7 ( & V_22 . V_24 , V_20 ) ;
if ( V_2 -> V_25 != V_26 ||
! F_8 () ) {
F_9 ( L_3 ) ;
V_21 = - V_27 ;
goto V_28;
}
V_21 = F_21 ( V_34 ) ;
if ( ! V_21 )
V_2 -> V_29 = V_35 ;
V_28:
F_11 ( & V_22 . V_24 , V_20 ) ;
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return - V_27 ;
}
static void F_13 ( struct V_1 * V_2 )
{
}
static int F_15 ( struct V_1 * V_2 )
{
return - V_27 ;
}
static void F_17 ( struct V_1 * V_2 )
{
}
static bool F_19 ( struct V_1 * V_2 )
{
return false ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
return - V_27 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
F_2 ( L_5 ) ;
F_6 ( & V_22 . V_23 ) ;
if ( V_2 -> V_25 != V_36 ) {
V_21 = - V_37 ;
goto V_28;
}
F_3 ( V_2 , & V_2 -> V_18 . V_19 ) ;
V_21 = F_23 ( V_2 ) ;
if ( V_21 ) {
F_9 ( L_6 ) ;
goto V_28;
}
V_2 -> V_25 = V_26 ;
V_28:
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_6 ( & V_22 . V_23 ) ;
if ( V_2 -> V_25 == V_26 ) {
F_13 ( V_2 ) ;
F_25 ( V_2 ) ;
}
V_2 -> V_25 = V_36 ;
F_12 ( & V_22 . V_23 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_19 )
{
F_6 ( & V_22 . V_23 ) ;
* V_19 = V_2 -> V_18 . V_19 ;
F_12 ( & V_22 . V_23 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_19 )
{
F_2 ( L_7 ) ;
F_6 ( & V_22 . V_23 ) ;
F_13 ( V_2 ) ;
F_3 ( V_2 , V_19 ) ;
V_2 -> V_18 . V_19 = * V_19 ;
F_12 ( & V_22 . V_23 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_19 )
{
int V_21 = 0 ;
F_2 ( L_8 ) ;
F_6 ( & V_22 . V_23 ) ;
V_21 = F_29 ( V_2 , V_19 ) ;
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_38 , int V_39 )
{
int V_21 ;
bool V_40 ;
F_6 ( & V_22 . V_23 ) ;
V_40 = V_2 -> V_25 == V_36 ;
if ( V_40 ) {
V_21 = F_31 ( V_2 ) ;
if ( V_21 )
goto V_28;
}
V_21 = F_32 ( V_38 , V_39 ) ;
if ( V_40 )
F_33 ( V_2 ) ;
V_28:
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
int V_21 ;
bool V_40 ;
F_6 ( & V_22 . V_23 ) ;
V_40 = V_2 -> V_25 == V_36 ;
if ( V_40 ) {
V_21 = F_31 ( V_2 ) ;
if ( V_21 )
goto V_28;
}
V_21 = F_35 () ;
if ( V_40 )
F_33 ( V_2 ) ;
V_28:
F_12 ( & V_22 . V_23 ) ;
return V_21 ;
}
int F_36 ( void )
{
F_37 ( & V_22 . V_23 ) ;
#if F_38 ( V_41 )
F_39 ( & V_22 . V_24 ) ;
#endif
return F_40 ( & V_42 ) ;
}
void F_41 ( void )
{
F_42 ( & V_42 ) ;
}
