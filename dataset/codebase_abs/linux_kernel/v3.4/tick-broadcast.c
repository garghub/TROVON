static inline void F_1 ( int V_1 ) { }
struct V_2 * F_2 ( void )
{
return & V_3 ;
}
struct V_4 * F_3 ( void )
{
return F_4 ( V_5 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
if ( V_7 )
F_6 ( V_7 , 1 ) ;
}
int F_7 ( struct V_6 * V_8 )
{
if ( ( V_3 . V_9 &&
V_3 . V_9 -> V_10 >= V_8 -> V_10 ) ||
( V_8 -> V_11 & V_12 ) )
return 0 ;
F_8 ( V_3 . V_9 , V_8 ) ;
V_3 . V_9 = V_8 ;
if ( ! F_9 ( F_3 () ) )
F_5 ( V_8 ) ;
return 1 ;
}
int F_10 ( struct V_6 * V_8 )
{
return ( V_8 && V_3 . V_9 == V_8 ) ;
}
int F_11 ( struct V_6 * V_8 , int V_1 )
{
unsigned long V_13 ;
int V_14 = 0 ;
F_12 ( & V_15 , V_13 ) ;
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_16 = V_17 ;
F_14 ( V_1 , F_3 () ) ;
F_5 ( V_3 . V_9 ) ;
V_14 = 1 ;
} else {
if ( ! ( V_8 -> V_11 & V_12 ) ) {
int V_1 = F_15 () ;
F_16 ( V_1 , F_3 () ) ;
F_1 ( V_1 ) ;
}
}
F_17 ( & V_15 , V_13 ) ;
return V_14 ;
}
static void F_18 ( struct V_4 * V_18 )
{
int V_1 = F_15 () ;
struct V_2 * V_19 ;
if ( F_19 ( V_1 , V_18 ) ) {
F_16 ( V_1 , V_18 ) ;
V_19 = & F_20 ( V_20 , V_1 ) ;
V_19 -> V_9 -> V_16 ( V_19 -> V_9 ) ;
}
if ( ! F_9 ( V_18 ) ) {
V_19 = & F_20 ( V_20 , F_21 ( V_18 ) ) ;
V_19 -> V_9 -> V_21 ( V_18 ) ;
}
}
static void F_22 ( void )
{
F_23 ( & V_15 ) ;
F_24 ( F_4 ( V_22 ) ,
V_23 , F_3 () ) ;
F_18 ( F_4 ( V_22 ) ) ;
F_25 ( & V_15 ) ;
}
static void F_26 ( struct V_6 * V_8 )
{
T_1 V_24 ;
F_22 () ;
if ( V_8 -> V_25 == V_26 )
return;
for ( V_24 = V_8 -> V_27 ; ; ) {
V_24 = F_27 ( V_24 , V_28 ) ;
if ( ! F_28 ( V_8 , V_24 , false ) )
return;
F_22 () ;
}
}
static void F_29 ( unsigned long * V_29 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_19 ;
unsigned long V_13 ;
int V_1 , V_30 ;
F_12 ( & V_15 , V_13 ) ;
V_1 = F_15 () ;
V_19 = & F_20 ( V_20 , V_1 ) ;
V_8 = V_19 -> V_9 ;
V_7 = V_3 . V_9 ;
if ( ! V_8 || ! ( V_8 -> V_11 & V_12 ) )
goto V_31;
if ( ! F_13 ( V_8 ) )
goto V_31;
V_30 = F_9 ( F_3 () ) ;
switch ( * V_29 ) {
case V_32 :
case V_33 :
if ( ! F_19 ( V_1 , F_3 () ) ) {
F_14 ( V_1 , F_3 () ) ;
if ( V_3 . V_25 ==
V_34 )
F_30 ( V_8 ) ;
}
if ( * V_29 == V_33 )
V_35 = 1 ;
break;
case V_36 :
if ( ! V_35 &&
F_19 ( V_1 , F_3 () ) ) {
F_16 ( V_1 , F_3 () ) ;
if ( V_3 . V_25 ==
V_34 )
F_6 ( V_8 , 0 ) ;
}
break;
}
if ( F_9 ( F_3 () ) ) {
if ( ! V_30 )
F_30 ( V_7 ) ;
} else if ( V_30 ) {
if ( V_3 . V_25 == V_34 )
F_5 ( V_7 ) ;
else
F_31 ( V_7 ) ;
}
V_31:
F_17 ( & V_15 , V_13 ) ;
}
void F_32 ( unsigned long V_29 , int * V_37 )
{
if ( ! F_19 ( * V_37 , V_23 ) )
F_33 ( V_38 L_1
L_2 , * V_37 ) ;
else
F_29 ( & V_29 ) ;
}
void F_34 ( struct V_6 * V_8 , int V_21 )
{
if ( ! V_21 )
V_8 -> V_16 = V_17 ;
else
V_8 -> V_16 = F_26 ;
}
void F_35 ( unsigned int * V_39 )
{
struct V_6 * V_7 ;
unsigned long V_13 ;
unsigned int V_1 = * V_39 ;
F_12 ( & V_15 , V_13 ) ;
V_7 = V_3 . V_9 ;
F_16 ( V_1 , F_3 () ) ;
if ( V_3 . V_25 == V_34 ) {
if ( V_7 && F_9 ( F_3 () ) )
F_30 ( V_7 ) ;
}
F_17 ( & V_15 , V_13 ) ;
}
void F_36 ( void )
{
struct V_6 * V_7 ;
unsigned long V_13 ;
F_12 ( & V_15 , V_13 ) ;
V_7 = V_3 . V_9 ;
if ( V_7 )
F_30 ( V_7 ) ;
F_17 ( & V_15 , V_13 ) ;
}
int F_37 ( void )
{
struct V_6 * V_7 ;
unsigned long V_13 ;
int V_21 = 0 ;
F_12 ( & V_15 , V_13 ) ;
V_7 = V_3 . V_9 ;
if ( V_7 ) {
F_38 ( V_7 , V_40 ) ;
switch ( V_3 . V_25 ) {
case V_34 :
if ( ! F_9 ( F_3 () ) )
F_5 ( V_7 ) ;
V_21 = F_19 ( F_15 () ,
F_3 () ) ;
break;
case V_41 :
if ( ! F_9 ( F_3 () ) )
V_21 = F_39 ( V_7 ) ;
break;
}
}
F_17 ( & V_15 , V_13 ) ;
return V_21 ;
}
struct V_4 * F_40 ( void )
{
return F_4 ( V_42 ) ;
}
static int F_41 ( T_1 V_43 , int V_44 )
{
struct V_6 * V_7 = V_3 . V_9 ;
if ( V_7 -> V_25 != V_45 )
F_38 ( V_7 , V_45 ) ;
return F_28 ( V_7 , V_43 , V_44 ) ;
}
int F_39 ( struct V_6 * V_7 )
{
F_38 ( V_7 , V_45 ) ;
return 0 ;
}
void F_42 ( int V_1 )
{
if ( F_19 ( V_1 , F_4 ( V_42 ) ) ) {
struct V_2 * V_19 = & F_20 ( V_20 , V_1 ) ;
F_38 ( V_19 -> V_9 , V_45 ) ;
}
}
static void F_43 ( struct V_6 * V_8 )
{
struct V_2 * V_19 ;
T_1 V_46 , V_27 ;
int V_1 ;
F_23 ( & V_15 ) ;
V_47:
V_8 -> V_27 . V_48 = V_49 ;
V_27 . V_48 = V_49 ;
F_44 ( F_4 ( V_22 ) ) ;
V_46 = F_45 () ;
F_46 (cpu, tick_get_broadcast_oneshot_mask()) {
V_19 = & F_20 ( V_20 , V_1 ) ;
if ( V_19 -> V_9 -> V_27 . V_48 <= V_46 . V_48 )
F_14 ( V_1 , F_4 ( V_22 ) ) ;
else if ( V_19 -> V_9 -> V_27 . V_48 < V_27 . V_48 )
V_27 . V_48 = V_19 -> V_9 -> V_27 . V_48 ;
}
F_18 ( F_4 ( V_22 ) ) ;
if ( V_27 . V_48 != V_49 ) {
if ( F_41 ( V_27 , 0 ) )
goto V_47;
}
F_25 ( & V_15 ) ;
}
void F_47 ( unsigned long V_29 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_19 ;
unsigned long V_13 ;
int V_1 ;
if ( V_3 . V_25 == V_34 )
return;
V_1 = F_15 () ;
V_19 = & F_20 ( V_20 , V_1 ) ;
V_8 = V_19 -> V_9 ;
if ( ! ( V_8 -> V_11 & V_12 ) )
return;
V_7 = V_3 . V_9 ;
F_12 ( & V_15 , V_13 ) ;
if ( V_29 == V_50 ) {
if ( ! F_19 ( V_1 , F_40 () ) ) {
F_14 ( V_1 , F_40 () ) ;
F_38 ( V_8 , V_51 ) ;
if ( V_8 -> V_27 . V_48 < V_7 -> V_27 . V_48 )
F_41 ( V_8 -> V_27 , 1 ) ;
}
} else {
if ( F_19 ( V_1 , F_40 () ) ) {
F_16 ( V_1 ,
F_40 () ) ;
F_38 ( V_8 , V_45 ) ;
if ( V_8 -> V_27 . V_48 != V_49 )
F_48 ( V_8 -> V_27 , 1 ) ;
}
}
F_17 ( & V_15 , V_13 ) ;
}
static void F_1 ( int V_1 )
{
F_16 ( V_1 , F_40 () ) ;
}
static void F_49 ( struct V_4 * V_18 ,
T_1 V_43 )
{
struct V_2 * V_19 ;
int V_1 ;
F_46 (cpu, mask) {
V_19 = & F_20 ( V_20 , V_1 ) ;
if ( V_19 -> V_9 )
V_19 -> V_9 -> V_27 = V_43 ;
}
}
void F_31 ( struct V_6 * V_7 )
{
int V_1 = F_15 () ;
if ( V_7 -> V_16 != F_43 ) {
int V_52 = V_7 -> V_25 == V_26 ;
V_7 -> V_16 = F_43 ;
V_53 = V_1 ;
F_50 ( F_4 ( V_22 ) , F_3 () ) ;
F_16 ( V_1 , F_4 ( V_22 ) ) ;
F_51 ( F_40 () ,
F_40 () ,
F_4 ( V_22 ) ) ;
if ( V_52 && ! F_9 ( F_4 ( V_22 ) ) ) {
F_38 ( V_7 , V_45 ) ;
F_49 ( F_4 ( V_22 ) ,
V_54 ) ;
F_41 ( V_54 , 1 ) ;
} else
V_7 -> V_27 . V_48 = V_49 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_52 ( void )
{
struct V_6 * V_7 ;
unsigned long V_13 ;
F_12 ( & V_15 , V_13 ) ;
V_3 . V_25 = V_41 ;
V_7 = V_3 . V_9 ;
if ( V_7 )
F_31 ( V_7 ) ;
F_17 ( & V_15 , V_13 ) ;
}
void F_53 ( unsigned int * V_39 )
{
unsigned long V_13 ;
unsigned int V_1 = * V_39 ;
F_12 ( & V_15 , V_13 ) ;
F_16 ( V_1 , F_40 () ) ;
F_17 ( & V_15 , V_13 ) ;
}
int F_54 ( void )
{
return V_3 . V_25 == V_41 ;
}
bool F_55 ( void )
{
struct V_6 * V_7 = V_3 . V_9 ;
return V_7 ? V_7 -> V_11 & V_55 : false ;
}
