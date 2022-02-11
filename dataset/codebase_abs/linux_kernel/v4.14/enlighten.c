static int F_1 ( unsigned int V_1 )
{
F_2 ( V_1 ) ;
return 0 ;
}
int F_3 ( int (* F_4)( unsigned int ) ,
int (* F_5)( unsigned int ) )
{
int V_2 ;
V_2 = F_6 ( V_3 ,
L_1 ,
F_4 , F_5 ) ;
if ( V_2 >= 0 ) {
V_2 = F_6 ( V_4 ,
L_2 ,
F_1 , NULL ) ;
if ( V_2 < 0 )
F_7 ( V_3 ) ;
}
return V_2 >= 0 ? 0 : V_2 ;
}
static int F_8 ( int V_1 )
{
int V_2 = 0 ;
F_9 ( V_1 ) ;
if ( F_10 () ||
( F_11 () && F_12 ( V_1 ) ) ) {
V_2 = F_13 ( V_1 ) ;
}
return V_2 ;
}
void F_14 ( void )
{
int V_1 , V_2 ;
F_15 (cpu) {
bool V_5 = ( V_1 != F_16 () ) ;
bool V_6 ;
if ( F_17 ( V_1 ) == V_7 )
continue;
V_6 = F_18 ( V_8 ,
F_17 ( V_1 ) , NULL ) > 0 ;
if ( V_5 && V_6 &&
F_18 ( V_9 , F_17 ( V_1 ) , NULL ) )
F_19 () ;
if ( F_10 () || F_20 ( V_10 ) )
F_21 ( V_1 ) ;
V_2 = F_8 ( V_1 ) ;
if ( V_2 )
F_22 ( L_3
L_4 , V_1 , V_2 ) ;
if ( V_5 && V_6 && ( V_2 == 0 ) &&
F_18 ( V_11 , F_17 ( V_1 ) , NULL ) )
F_19 () ;
}
}
void F_9 ( int V_1 )
{
if ( F_17 ( V_1 ) < V_12 ) {
F_23 ( V_13 , V_1 ) =
& V_14 -> V_15 [ F_17 ( V_1 ) ] ;
} else {
F_23 ( V_13 , V_1 ) = NULL ;
}
}
int F_13 ( int V_1 )
{
struct V_16 V_17 ;
int V_18 ;
struct V_15 * V_19 ;
F_24 ( V_14 == & V_20 ) ;
if ( F_11 () ) {
if ( F_23 ( V_13 , V_1 ) == & F_23 ( V_21 , V_1 ) )
return 0 ;
}
if ( V_22 ) {
V_19 = & F_23 ( V_21 , V_1 ) ;
V_17 . V_23 = F_25 ( V_19 ) ;
V_17 . V_24 = F_26 ( V_19 ) ;
V_18 = F_18 ( V_25 ,
F_17 ( V_1 ) , & V_17 ) ;
if ( V_18 ) {
F_27 ( L_5 ,
V_1 , V_18 ) ;
V_22 = 0 ;
} else {
F_23 ( V_13 , V_1 ) = V_19 ;
}
}
if ( ! V_22 )
F_9 ( V_1 ) ;
return ( ( F_23 ( V_13 , V_1 ) == NULL ) ? - V_26 : 0 ) ;
}
void F_28 ( int V_27 )
{
struct V_28 V_29 = { . V_27 = V_27 } ;
int V_1 ;
F_29 (cpu)
F_30 ( V_1 ) ;
if ( F_31 ( V_30 , & V_29 ) )
F_19 () ;
}
void F_32 ( void )
{
F_28 ( V_31 ) ;
}
static int
F_33 ( struct V_32 * V_33 , unsigned long V_34 , void * V_35 )
{
if ( ! F_34 () )
F_28 ( V_36 ) ;
return V_37 ;
}
int F_35 ( void )
{
F_36 ( & V_38 , & V_39 ) ;
return 0 ;
}
void F_37 ( int V_1 )
{
static bool V_40 ;
struct V_41 V_42 ;
int V_43 ;
if ( V_40 )
return;
V_42 . V_44 = V_1 ;
V_43 = F_31 ( V_45 , & V_42 ) ;
if ( V_1 < 0 )
return;
switch ( V_43 ) {
case - V_46 :
F_38 ( L_6 ,
V_1 ) ;
V_40 = true ;
break;
case - V_47 :
F_39 ( 1 , L_7 ) ;
V_40 = true ;
break;
case - V_48 :
case - V_49 :
F_38 ( L_8 ,
V_1 ) ;
break;
case 0 :
break;
default:
F_39 ( 1 , L_9 , V_43 ) ;
V_40 = true ;
}
}
void F_40 ( int V_50 )
{
F_41 ( V_50 ) ;
}
void F_42 ( int V_50 )
{
F_43 ( V_50 ) ;
}
