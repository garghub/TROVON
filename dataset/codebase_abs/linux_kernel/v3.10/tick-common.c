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
static int F_35 ( struct V_4 * V_24 )
{
struct V_4 * V_34 ;
struct V_1 * V_23 ;
int V_2 , V_35 = V_36 ;
unsigned long V_37 ;
F_36 ( & V_38 , V_37 ) ;
V_2 = F_16 () ;
if ( ! F_37 ( V_2 , V_24 -> V_25 ) )
goto V_39;
V_23 = & F_2 ( V_3 , V_2 ) ;
V_34 = V_23 -> V_6 ;
if ( ! F_31 ( V_24 -> V_25 , F_38 ( V_2 ) ) ) {
if ( ! F_39 ( V_24 -> V_33 ) )
goto V_39;
if ( V_34 && F_31 ( V_34 -> V_25 , F_38 ( V_2 ) ) )
goto V_39;
}
if ( V_34 ) {
if ( ( V_34 -> V_7 & V_8 ) &&
! ( V_24 -> V_7 & V_8 ) )
goto V_39;
if ( V_34 -> V_40 >= V_24 -> V_40 )
goto V_39;
}
if ( F_40 ( V_34 ) ) {
F_41 ( V_34 ) ;
V_34 = NULL ;
}
F_42 ( V_34 , V_24 ) ;
F_26 ( V_23 , V_24 , V_2 , F_38 ( V_2 ) ) ;
if ( V_24 -> V_7 & V_8 )
F_43 () ;
F_44 ( & V_38 , V_37 ) ;
return V_41 ;
V_39:
if ( F_45 ( V_24 ) )
V_35 = V_41 ;
F_44 ( & V_38 , V_37 ) ;
return V_35 ;
}
static void F_46 ( int * V_42 )
{
if ( * V_42 == V_10 ) {
int V_2 = F_47 ( V_43 ) ;
V_10 = ( V_2 < V_44 ) ? V_2 :
V_27 ;
}
}
static void F_48 ( unsigned int * V_42 )
{
struct V_1 * V_23 = & F_2 ( V_3 , * V_42 ) ;
struct V_4 * V_5 = V_23 -> V_6 ;
unsigned long V_37 ;
F_36 ( & V_38 , V_37 ) ;
V_23 -> V_16 = V_30 ;
if ( V_5 ) {
V_5 -> V_16 = V_45 ;
F_42 ( V_5 , NULL ) ;
V_5 -> V_31 = V_32 ;
V_23 -> V_6 = NULL ;
}
F_44 ( & V_38 , V_37 ) ;
}
static void F_49 ( void )
{
struct V_1 * V_23 = & F_50 ( V_3 ) ;
unsigned long V_37 ;
F_36 ( & V_38 , V_37 ) ;
F_41 ( V_23 -> V_6 ) ;
F_44 ( & V_38 , V_37 ) ;
}
static void F_51 ( void )
{
struct V_1 * V_23 = & F_50 ( V_3 ) ;
unsigned long V_37 ;
int V_19 = F_52 () ;
F_36 ( & V_38 , V_37 ) ;
F_23 ( V_23 -> V_6 , V_46 ) ;
if ( ! V_19 ) {
if ( V_23 -> V_16 == V_30 )
F_19 ( V_23 -> V_6 , 0 ) ;
else
F_53 () ;
}
F_44 ( & V_38 , V_37 ) ;
}
static int F_54 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_5 )
{
switch ( V_49 ) {
case V_50 :
return F_35 ( V_5 ) ;
case V_51 :
case V_52 :
case V_53 :
F_55 ( V_49 , V_5 ) ;
break;
case V_54 :
case V_55 :
F_56 ( V_49 ) ;
break;
case V_56 :
F_46 ( V_5 ) ;
break;
case V_57 :
F_57 ( V_5 ) ;
F_58 ( V_5 ) ;
F_48 ( V_5 ) ;
break;
case V_58 :
F_49 () ;
F_59 () ;
break;
case V_59 :
F_51 () ;
break;
default:
break;
}
return V_36 ;
}
void T_2 F_60 ( void )
{
F_61 ( & V_60 ) ;
F_62 () ;
}
