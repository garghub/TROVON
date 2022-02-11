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
V_10 = V_2 ;
V_12 = F_28 () ;
V_13 = F_29 ( 0 , V_27 / V_28 ) ;
}
V_23 -> V_16 = V_29 ;
} else {
F_27 = V_23 -> V_6 -> V_30 ;
V_18 = V_23 -> V_6 -> V_18 ;
V_23 -> V_6 -> V_30 = V_31 ;
}
V_23 -> V_6 = V_24 ;
if ( ! F_30 ( V_24 -> V_25 , V_25 ) )
F_31 ( V_24 -> V_32 , V_25 ) ;
if ( F_32 ( V_24 , V_2 ) )
return;
if ( V_23 -> V_16 == V_29 )
F_19 ( V_24 , 0 ) ;
else
F_33 ( V_24 , F_27 , V_18 ) ;
}
static int F_34 ( struct V_4 * V_24 )
{
struct V_4 * V_33 ;
struct V_1 * V_23 ;
int V_2 , V_34 = V_35 ;
unsigned long V_36 ;
F_35 ( & V_37 , V_36 ) ;
V_2 = F_16 () ;
if ( ! F_36 ( V_2 , V_24 -> V_25 ) )
goto V_38;
V_23 = & F_2 ( V_3 , V_2 ) ;
V_33 = V_23 -> V_6 ;
if ( ! F_30 ( V_24 -> V_25 , F_37 ( V_2 ) ) ) {
if ( ! F_38 ( V_24 -> V_32 ) )
goto V_38;
if ( V_33 && F_30 ( V_33 -> V_25 , F_37 ( V_2 ) ) )
goto V_38;
}
if ( V_33 ) {
if ( ( V_33 -> V_7 & V_8 ) &&
! ( V_24 -> V_7 & V_8 ) )
goto V_38;
if ( V_33 -> V_39 >= V_24 -> V_39 )
goto V_38;
}
if ( F_39 ( V_33 ) ) {
F_40 ( V_33 ) ;
V_33 = NULL ;
}
F_41 ( V_33 , V_24 ) ;
F_26 ( V_23 , V_24 , V_2 , F_37 ( V_2 ) ) ;
if ( V_24 -> V_7 & V_8 )
F_42 () ;
F_43 ( & V_37 , V_36 ) ;
return V_40 ;
V_38:
if ( F_44 ( V_24 ) )
V_34 = V_40 ;
F_43 ( & V_37 , V_36 ) ;
return V_34 ;
}
static void F_45 ( int * V_41 )
{
if ( * V_41 == V_10 ) {
int V_2 = F_46 ( V_42 ) ;
V_10 = ( V_2 < V_43 ) ? V_2 :
V_44 ;
}
}
static void F_47 ( unsigned int * V_41 )
{
struct V_1 * V_23 = & F_2 ( V_3 , * V_41 ) ;
struct V_4 * V_5 = V_23 -> V_6 ;
unsigned long V_36 ;
F_35 ( & V_37 , V_36 ) ;
V_23 -> V_16 = V_29 ;
if ( V_5 ) {
V_5 -> V_16 = V_45 ;
F_41 ( V_5 , NULL ) ;
V_23 -> V_6 = NULL ;
}
F_43 ( & V_37 , V_36 ) ;
}
static void F_48 ( void )
{
struct V_1 * V_23 = & F_49 ( V_3 ) ;
unsigned long V_36 ;
F_35 ( & V_37 , V_36 ) ;
F_40 ( V_23 -> V_6 ) ;
F_43 ( & V_37 , V_36 ) ;
}
static void F_50 ( void )
{
struct V_1 * V_23 = & F_49 ( V_3 ) ;
unsigned long V_36 ;
int V_19 = F_51 () ;
F_35 ( & V_37 , V_36 ) ;
F_23 ( V_23 -> V_6 , V_46 ) ;
if ( ! V_19 ) {
if ( V_23 -> V_16 == V_29 )
F_19 ( V_23 -> V_6 , 0 ) ;
else
F_52 () ;
}
F_43 ( & V_37 , V_36 ) ;
}
static int F_53 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_5 )
{
switch ( V_49 ) {
case V_50 :
return F_34 ( V_5 ) ;
case V_51 :
case V_52 :
case V_53 :
F_54 ( V_49 , V_5 ) ;
break;
case V_54 :
case V_55 :
F_55 ( V_49 ) ;
break;
case V_56 :
F_45 ( V_5 ) ;
break;
case V_57 :
F_56 ( V_5 ) ;
F_57 ( V_5 ) ;
F_47 ( V_5 ) ;
break;
case V_58 :
F_48 () ;
F_58 () ;
break;
case V_59 :
F_50 () ;
break;
default:
break;
}
return V_35 ;
}
void T_2 F_59 ( void )
{
F_60 ( & V_60 ) ;
}
