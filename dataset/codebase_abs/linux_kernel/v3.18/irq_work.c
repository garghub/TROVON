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
bool F_5 ( struct V_1 * V_2 , int V_8 )
{
F_6 ( F_7 ( V_8 ) ) ;
F_6 ( F_8 () ) ;
if ( ! F_1 ( V_2 ) )
return false ;
if ( F_9 ( & V_2 -> V_9 , & F_10 ( V_10 , V_8 ) ) )
F_11 ( V_8 ) ;
return true ;
}
bool F_12 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return false ;
F_13 () ;
if ( V_2 -> V_3 & V_11 ) {
if ( F_9 ( & V_2 -> V_9 , F_14 ( & V_12 ) ) &&
F_15 () )
F_4 () ;
} else {
if ( F_9 ( & V_2 -> V_9 , F_14 ( & V_10 ) ) )
F_4 () ;
}
F_16 () ;
return true ;
}
bool F_17 ( void )
{
struct V_13 * V_14 , * V_15 ;
V_14 = F_14 ( & V_10 ) ;
V_15 = F_14 ( & V_12 ) ;
if ( F_18 ( V_14 ) || F_19 () )
if ( F_18 ( V_15 ) )
return false ;
F_6 ( F_7 ( F_20 () ) ) ;
return true ;
}
static void F_21 ( struct V_13 * V_16 )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_17 * V_9 ;
F_22 ( ! F_23 () ) ;
if ( F_18 ( V_16 ) )
return;
V_9 = F_24 ( V_16 ) ;
while ( V_9 != NULL ) {
V_2 = F_25 ( V_9 , struct V_1 , V_9 ) ;
V_9 = F_26 ( V_9 ) ;
V_3 = V_2 -> V_3 & ~ V_6 ;
F_27 ( & V_2 -> V_3 , V_3 ) ;
V_2 -> V_18 ( V_2 ) ;
( void ) F_2 ( & V_2 -> V_3 , V_3 , V_3 & ~ V_19 ) ;
}
}
void F_28 ( void )
{
F_21 ( F_14 ( & V_10 ) ) ;
F_21 ( F_14 ( & V_12 ) ) ;
}
void F_29 ( void )
{
struct V_13 * V_14 = & F_30 ( V_10 ) ;
if ( ! F_18 ( V_14 ) && ! F_19 () )
F_21 ( V_14 ) ;
F_21 ( & F_30 ( V_12 ) ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_6 ( F_23 () ) ;
while ( V_2 -> V_3 & V_19 )
F_3 () ;
}
