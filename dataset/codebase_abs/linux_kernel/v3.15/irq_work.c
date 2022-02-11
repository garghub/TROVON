static bool F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
V_3 = V_2 -> V_3 & ~ V_6 ;
for (; ; ) {
V_5 = V_3 | V_7 ;
V_4 = F_2 ( & V_2 -> V_3 , V_3 , V_5 ) ;
if ( V_4 == V_3 )
break;
if ( V_4 & V_6 )
return false ;
V_3 = V_4 ;
F_3 () ;
}
return true ;
}
void __weak F_4 ( void )
{
}
bool F_5 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_6 () ;
F_7 ( & V_2 -> V_8 , & F_8 ( V_9 ) ) ;
if ( ! ( V_2 -> V_3 & V_10 ) || F_9 () ) {
if ( ! F_10 ( V_11 , 0 , 1 ) )
F_4 () ;
}
F_11 () ;
return true ;
}
bool F_12 ( void )
{
struct V_12 * V_13 ;
V_13 = & F_8 ( V_9 ) ;
if ( F_13 ( V_13 ) )
return false ;
F_14 ( F_15 ( F_16 () ) ) ;
return true ;
}
static void F_17 ( void )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_14 * V_8 ;
F_18 ( V_11 , 0 ) ;
F_19 () ;
V_13 = & F_8 ( V_9 ) ;
if ( F_13 ( V_13 ) )
return;
F_20 ( ! F_21 () ) ;
V_8 = F_22 ( V_13 ) ;
while ( V_8 != NULL ) {
V_2 = F_23 ( V_8 , struct V_1 , V_8 ) ;
V_8 = F_24 ( V_8 ) ;
V_3 = V_2 -> V_3 & ~ V_6 ;
F_25 ( & V_2 -> V_3 , V_3 ) ;
V_2 -> V_15 ( V_2 ) ;
( void ) F_2 ( & V_2 -> V_3 , V_3 , V_3 & ~ V_16 ) ;
}
}
void F_26 ( void )
{
F_20 ( ! F_27 () ) ;
F_17 () ;
}
void F_28 ( struct V_1 * V_2 )
{
F_14 ( F_21 () ) ;
while ( V_2 -> V_3 & V_16 )
F_3 () ;
}
static int F_29 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
long V_21 = ( long ) V_20 ;
switch ( V_19 ) {
case V_22 :
if ( F_14 ( V_21 != F_16 () ) )
break;
F_17 () ;
break;
default:
break;
}
return V_23 ;
}
static T_1 int F_30 ( void )
{
V_24 . V_25 = F_29 ;
V_24 . V_26 = 0 ;
F_31 ( & V_24 ) ;
return 0 ;
}
