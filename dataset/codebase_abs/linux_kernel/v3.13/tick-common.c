struct V_1 * F_1 ( int V_2 )
{
return & F_2 ( V_3 , V_2 ) ;
}
int F_3 ( void )
{
struct V_4 * V_5 = F_4 ( V_3 . V_6 ) ;
if ( ! V_5 || ! ( V_5 -> V_7 & V_8 ) )
return 0 ;
if ( ! ( V_5 -> V_7 & V_9 ) )
return 1 ;
return F_5 () ;
}
static void F_6 ( int V_2 )
{
if ( V_10 == V_2 ) {
F_7 ( & V_11 ) ;
V_12 = F_8 ( V_12 , V_13 ) ;
F_9 ( 1 ) ;
F_10 ( & V_11 ) ;
}
F_11 ( F_12 ( F_13 () ) ) ;
F_14 ( V_14 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
int V_2 = F_16 () ;
T_1 V_15 ;
F_6 ( V_2 ) ;
if ( V_5 -> V_16 != V_17 )
return;
V_15 = F_8 ( V_5 -> V_18 , V_13 ) ;
for (; ; ) {
if ( ! F_17 ( V_5 , V_15 , false ) )
return;
if ( F_18 () )
F_6 ( V_2 ) ;
V_15 = F_8 ( V_15 , V_13 ) ;
}
}
void F_19 ( struct V_4 * V_5 , int V_19 )
{
F_20 ( V_5 , V_19 ) ;
if ( ! F_21 ( V_5 ) )
return;
if ( ( V_5 -> V_7 & V_20 ) &&
! F_22 () ) {
F_23 ( V_5 , V_21 ) ;
} else {
unsigned long V_22 ;
T_1 V_15 ;
do {
V_22 = F_24 ( & V_11 ) ;
V_15 = V_12 ;
} while ( F_25 ( & V_11 , V_22 ) );
F_23 ( V_5 , V_17 ) ;
for (; ; ) {
if ( ! F_17 ( V_5 , V_15 , false ) )
return;
V_15 = F_8 ( V_15 , V_13 ) ;
}
}
}
static void F_26 ( struct V_1 * V_23 ,
struct V_4 * V_24 , int V_2 ,
const struct V_25 * V_25 )
{
T_1 V_18 ;
void (* F_27)( struct V_4 * ) = NULL ;
if ( ! V_23 -> V_6 ) {
if ( V_10 == V_26 ) {
if ( ! F_28 ( V_2 ) )
V_10 = V_2 ;
else
V_10 = V_27 ;
V_12 = F_29 () ;
V_13 = F_30 ( 0 , V_28 / V_29 ) ;
}
V_23 -> V_16 = V_30 ;
} else {
F_27 = V_23 -> V_6 -> V_31 ;
V_18 = V_23 -> V_6 -> V_18 ;
V_23 -> V_6 -> V_31 = V_32 ;
}
V_23 -> V_6 = V_24 ;
if ( ! F_31 ( V_24 -> V_25 , V_25 ) )
F_32 ( V_24 -> V_33 , V_25 ) ;
if ( F_33 ( V_24 , V_2 ) )
return;
if ( V_23 -> V_16 == V_30 )
F_19 ( V_24 , 0 ) ;
else
F_34 ( V_24 , F_27 , V_18 ) ;
}
void F_35 ( struct V_4 * V_24 )
{
struct V_1 * V_23 = & F_36 ( V_3 ) ;
int V_2 = F_16 () ;
F_37 ( V_23 -> V_6 , V_24 ) ;
F_26 ( V_23 , V_24 , V_2 , F_38 ( V_2 ) ) ;
if ( V_24 -> V_7 & V_8 )
F_39 () ;
}
static bool F_40 ( struct V_4 * V_34 ,
struct V_4 * V_24 , int V_2 )
{
if ( ! F_41 ( V_2 , V_24 -> V_25 ) )
return false ;
if ( F_31 ( V_24 -> V_25 , F_38 ( V_2 ) ) )
return true ;
if ( V_24 -> V_33 >= 0 && ! F_42 ( V_24 -> V_33 ) )
return false ;
if ( V_34 && F_31 ( V_34 -> V_25 , F_38 ( V_2 ) ) )
return false ;
return true ;
}
static bool F_43 ( struct V_4 * V_34 ,
struct V_4 * V_24 )
{
if ( ! ( V_24 -> V_7 & V_8 ) ) {
if ( V_34 && ( V_34 -> V_7 & V_8 ) )
return false ;
if ( F_44 () )
return false ;
}
return ! V_34 ||
V_24 -> V_35 > V_34 -> V_35 ||
! F_31 ( V_34 -> V_25 , V_24 -> V_25 ) ;
}
bool F_45 ( struct V_4 * V_34 ,
struct V_4 * V_24 )
{
if ( F_40 ( V_34 , V_24 , F_16 () ) )
return false ;
return F_43 ( V_34 , V_24 ) ;
}
void F_46 ( struct V_4 * V_24 )
{
struct V_4 * V_34 ;
struct V_1 * V_23 ;
int V_2 ;
V_2 = F_16 () ;
if ( ! F_41 ( V_2 , V_24 -> V_25 ) )
goto V_36;
V_23 = & F_2 ( V_3 , V_2 ) ;
V_34 = V_23 -> V_6 ;
if ( ! F_40 ( V_34 , V_24 , V_2 ) )
goto V_36;
if ( ! F_43 ( V_34 , V_24 ) )
goto V_36;
if ( ! F_47 ( V_24 -> V_37 ) )
return;
if ( F_48 ( V_34 ) ) {
F_49 ( V_34 ) ;
V_34 = NULL ;
}
F_37 ( V_34 , V_24 ) ;
F_26 ( V_23 , V_24 , V_2 , F_38 ( V_2 ) ) ;
if ( V_24 -> V_7 & V_8 )
F_39 () ;
return;
V_36:
F_50 ( V_24 ) ;
}
void F_51 ( int * V_38 )
{
if ( * V_38 == V_10 ) {
int V_2 = F_52 ( V_39 ) ;
V_10 = ( V_2 < V_40 ) ? V_2 :
V_27 ;
}
}
void F_53 ( unsigned int * V_38 )
{
struct V_1 * V_23 = & F_2 ( V_3 , * V_38 ) ;
struct V_4 * V_5 = V_23 -> V_6 ;
V_23 -> V_16 = V_30 ;
if ( V_5 ) {
V_5 -> V_16 = V_41 ;
F_37 ( V_5 , NULL ) ;
V_5 -> V_31 = V_32 ;
V_23 -> V_6 = NULL ;
}
}
void F_54 ( void )
{
struct V_1 * V_23 = & F_36 ( V_3 ) ;
F_49 ( V_23 -> V_6 ) ;
}
void F_55 ( void )
{
struct V_1 * V_23 = & F_36 ( V_3 ) ;
int V_19 = F_56 () ;
F_23 ( V_23 -> V_6 , V_42 ) ;
if ( ! V_19 ) {
if ( V_23 -> V_16 == V_30 )
F_19 ( V_23 -> V_6 , 0 ) ;
else
F_57 () ;
}
}
void T_2 F_58 ( void )
{
F_59 () ;
}
