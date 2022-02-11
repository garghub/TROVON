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
if ( ( V_8 -> V_9 & V_10 ) ||
( V_3 . V_11 &&
V_3 . V_11 -> V_12 >= V_8 -> V_12 ) ||
( V_8 -> V_9 & V_13 ) )
return 0 ;
F_8 ( V_3 . V_11 , V_8 ) ;
V_3 . V_11 = V_8 ;
if ( ! F_9 ( F_3 () ) )
F_5 ( V_8 ) ;
return 1 ;
}
int F_10 ( struct V_6 * V_8 )
{
return ( V_8 && V_3 . V_11 == V_8 ) ;
}
static void F_11 ( const struct V_4 * V_14 )
{
F_12 ( L_1 ) ;
}
static void F_13 ( struct V_6 * V_8 )
{
if ( ! V_8 -> V_15 )
V_8 -> V_15 = V_16 ;
if ( ! V_8 -> V_15 ) {
F_14 ( L_2 ,
V_8 -> V_17 ) ;
V_8 -> V_15 = F_11 ;
}
}
int F_15 ( struct V_6 * V_8 , int V_1 )
{
unsigned long V_18 ;
int V_19 = 0 ;
F_16 ( & V_20 , V_18 ) ;
if ( ! F_17 ( V_8 ) ) {
V_8 -> V_21 = V_22 ;
F_13 ( V_8 ) ;
F_18 ( V_1 , F_3 () ) ;
F_5 ( V_3 . V_11 ) ;
V_19 = 1 ;
} else {
if ( ! ( V_8 -> V_9 & V_13 ) ) {
int V_1 = F_19 () ;
F_20 ( V_1 , F_3 () ) ;
F_1 ( V_1 ) ;
} else {
F_13 ( V_8 ) ;
}
}
F_21 ( & V_20 , V_18 ) ;
return V_19 ;
}
int F_22 ( void )
{
struct V_2 * V_23 = F_23 ( & V_24 ) ;
struct V_6 * V_25 = V_23 -> V_11 ;
if ( ! V_25 )
return - V_26 ;
if ( ! V_25 -> V_21 )
return - V_27 ;
V_25 -> V_21 ( V_25 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_14 )
{
int V_1 = F_19 () ;
struct V_2 * V_23 ;
if ( F_25 ( V_1 , V_14 ) ) {
F_20 ( V_1 , V_14 ) ;
V_23 = & F_26 ( V_24 , V_1 ) ;
V_23 -> V_11 -> V_21 ( V_23 -> V_11 ) ;
}
if ( ! F_9 ( V_14 ) ) {
V_23 = & F_26 ( V_24 , F_27 ( V_14 ) ) ;
V_23 -> V_11 -> V_15 ( V_14 ) ;
}
}
static void F_28 ( void )
{
F_29 ( & V_20 ) ;
F_30 ( F_4 ( V_28 ) ,
V_29 , F_3 () ) ;
F_24 ( F_4 ( V_28 ) ) ;
F_31 ( & V_20 ) ;
}
static void F_32 ( struct V_6 * V_8 )
{
T_1 V_30 ;
F_28 () ;
if ( V_8 -> V_31 == V_32 )
return;
for ( V_30 = V_8 -> V_33 ; ; ) {
V_30 = F_33 ( V_30 , V_34 ) ;
if ( ! F_34 ( V_8 , V_30 , false ) )
return;
F_28 () ;
}
}
static void F_35 ( unsigned long * V_35 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_23 ;
unsigned long V_18 ;
int V_1 , V_36 ;
F_16 ( & V_20 , V_18 ) ;
V_1 = F_19 () ;
V_23 = & F_26 ( V_24 , V_1 ) ;
V_8 = V_23 -> V_11 ;
V_7 = V_3 . V_11 ;
if ( ! V_8 || ! ( V_8 -> V_9 & V_13 ) )
goto V_37;
if ( ! F_17 ( V_8 ) )
goto V_37;
V_36 = F_9 ( F_3 () ) ;
switch ( * V_35 ) {
case V_38 :
case V_39 :
if ( ! F_25 ( V_1 , F_3 () ) ) {
F_18 ( V_1 , F_3 () ) ;
if ( V_3 . V_31 ==
V_40 )
F_36 ( V_8 ) ;
}
if ( * V_35 == V_39 )
V_41 = 1 ;
break;
case V_42 :
if ( ! V_41 &&
F_25 ( V_1 , F_3 () ) ) {
F_20 ( V_1 , F_3 () ) ;
if ( V_3 . V_31 ==
V_40 )
F_6 ( V_8 , 0 ) ;
}
break;
}
if ( F_9 ( F_3 () ) ) {
if ( ! V_36 )
F_36 ( V_7 ) ;
} else if ( V_36 ) {
if ( V_3 . V_31 == V_40 )
F_5 ( V_7 ) ;
else
F_37 ( V_7 ) ;
}
V_37:
F_21 ( & V_20 , V_18 ) ;
}
void F_38 ( unsigned long V_35 , int * V_43 )
{
if ( ! F_25 ( * V_43 , V_29 ) )
F_39 ( V_44 L_3
L_4 , * V_43 ) ;
else
F_35 ( & V_35 ) ;
}
void F_40 ( struct V_6 * V_8 , int V_15 )
{
if ( ! V_15 )
V_8 -> V_21 = V_22 ;
else
V_8 -> V_21 = F_32 ;
}
void F_41 ( unsigned int * V_45 )
{
struct V_6 * V_7 ;
unsigned long V_18 ;
unsigned int V_1 = * V_45 ;
F_16 ( & V_20 , V_18 ) ;
V_7 = V_3 . V_11 ;
F_20 ( V_1 , F_3 () ) ;
if ( V_3 . V_31 == V_40 ) {
if ( V_7 && F_9 ( F_3 () ) )
F_36 ( V_7 ) ;
}
F_21 ( & V_20 , V_18 ) ;
}
void F_42 ( void )
{
struct V_6 * V_7 ;
unsigned long V_18 ;
F_16 ( & V_20 , V_18 ) ;
V_7 = V_3 . V_11 ;
if ( V_7 )
F_36 ( V_7 ) ;
F_21 ( & V_20 , V_18 ) ;
}
int F_43 ( void )
{
struct V_6 * V_7 ;
unsigned long V_18 ;
int V_15 = 0 ;
F_16 ( & V_20 , V_18 ) ;
V_7 = V_3 . V_11 ;
if ( V_7 ) {
F_44 ( V_7 , V_46 ) ;
switch ( V_3 . V_31 ) {
case V_40 :
if ( ! F_9 ( F_3 () ) )
F_5 ( V_7 ) ;
V_15 = F_25 ( F_19 () ,
F_3 () ) ;
break;
case V_47 :
if ( ! F_9 ( F_3 () ) )
V_15 = F_45 ( V_7 ) ;
break;
}
}
F_21 ( & V_20 , V_18 ) ;
return V_15 ;
}
struct V_4 * F_46 ( void )
{
return F_4 ( V_48 ) ;
}
static int F_47 ( T_1 V_49 , int V_50 )
{
struct V_6 * V_7 = V_3 . V_11 ;
if ( V_7 -> V_31 != V_51 )
F_44 ( V_7 , V_51 ) ;
return F_34 ( V_7 , V_49 , V_50 ) ;
}
int F_45 ( struct V_6 * V_7 )
{
F_44 ( V_7 , V_51 ) ;
return 0 ;
}
void F_48 ( int V_1 )
{
if ( F_25 ( V_1 , F_4 ( V_48 ) ) ) {
struct V_2 * V_23 = & F_26 ( V_24 , V_1 ) ;
F_44 ( V_23 -> V_11 , V_51 ) ;
}
}
static void F_49 ( struct V_6 * V_8 )
{
struct V_2 * V_23 ;
T_1 V_52 , V_33 ;
int V_1 ;
F_29 ( & V_20 ) ;
V_53:
V_8 -> V_33 . V_54 = V_55 ;
V_33 . V_54 = V_55 ;
F_50 ( F_4 ( V_28 ) ) ;
V_52 = F_51 () ;
F_52 (cpu, tick_get_broadcast_oneshot_mask()) {
V_23 = & F_26 ( V_24 , V_1 ) ;
if ( V_23 -> V_11 -> V_33 . V_54 <= V_52 . V_54 )
F_18 ( V_1 , F_4 ( V_28 ) ) ;
else if ( V_23 -> V_11 -> V_33 . V_54 < V_33 . V_54 )
V_33 . V_54 = V_23 -> V_11 -> V_33 . V_54 ;
}
F_24 ( F_4 ( V_28 ) ) ;
if ( V_33 . V_54 != V_55 ) {
if ( F_47 ( V_33 , 0 ) )
goto V_53;
}
F_31 ( & V_20 ) ;
}
void F_53 ( unsigned long V_35 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_23 ;
unsigned long V_18 ;
int V_1 ;
if ( V_3 . V_31 == V_40 )
return;
V_1 = F_19 () ;
V_23 = & F_26 ( V_24 , V_1 ) ;
V_8 = V_23 -> V_11 ;
if ( ! ( V_8 -> V_9 & V_13 ) )
return;
V_7 = V_3 . V_11 ;
F_16 ( & V_20 , V_18 ) ;
if ( V_35 == V_56 ) {
if ( ! F_25 ( V_1 , F_46 () ) ) {
F_18 ( V_1 , F_46 () ) ;
F_44 ( V_8 , V_57 ) ;
if ( V_8 -> V_33 . V_54 < V_7 -> V_33 . V_54 )
F_47 ( V_8 -> V_33 , 1 ) ;
}
} else {
if ( F_25 ( V_1 , F_46 () ) ) {
F_20 ( V_1 ,
F_46 () ) ;
F_44 ( V_8 , V_51 ) ;
if ( V_8 -> V_33 . V_54 != V_55 )
F_54 ( V_8 -> V_33 , 1 ) ;
}
}
F_21 ( & V_20 , V_18 ) ;
}
static void F_1 ( int V_1 )
{
F_20 ( V_1 , F_46 () ) ;
}
static void F_55 ( struct V_4 * V_14 ,
T_1 V_49 )
{
struct V_2 * V_23 ;
int V_1 ;
F_52 (cpu, mask) {
V_23 = & F_26 ( V_24 , V_1 ) ;
if ( V_23 -> V_11 )
V_23 -> V_11 -> V_33 = V_49 ;
}
}
void F_37 ( struct V_6 * V_7 )
{
int V_1 = F_19 () ;
if ( V_7 -> V_21 != F_49 ) {
int V_58 = V_7 -> V_31 == V_32 ;
V_7 -> V_21 = F_49 ;
V_59 = V_1 ;
F_56 ( F_4 ( V_28 ) , F_3 () ) ;
F_20 ( V_1 , F_4 ( V_28 ) ) ;
F_57 ( F_46 () ,
F_46 () ,
F_4 ( V_28 ) ) ;
if ( V_58 && ! F_9 ( F_4 ( V_28 ) ) ) {
F_44 ( V_7 , V_51 ) ;
F_55 ( F_4 ( V_28 ) ,
V_60 ) ;
F_47 ( V_60 , 1 ) ;
} else
V_7 -> V_33 . V_54 = V_55 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_58 ( void )
{
struct V_6 * V_7 ;
unsigned long V_18 ;
F_16 ( & V_20 , V_18 ) ;
V_3 . V_31 = V_47 ;
V_7 = V_3 . V_11 ;
if ( V_7 )
F_37 ( V_7 ) ;
F_21 ( & V_20 , V_18 ) ;
}
void F_59 ( unsigned int * V_45 )
{
unsigned long V_18 ;
unsigned int V_1 = * V_45 ;
F_16 ( & V_20 , V_18 ) ;
F_20 ( V_1 , F_46 () ) ;
F_21 ( & V_20 , V_18 ) ;
}
int F_60 ( void )
{
return V_3 . V_31 == V_47 ;
}
bool F_61 ( void )
{
struct V_6 * V_7 = V_3 . V_11 ;
return V_7 ? V_7 -> V_9 & V_61 : false ;
}
