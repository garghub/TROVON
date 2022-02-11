static bool F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
for (; ; ) {
V_3 = V_2 -> V_3 ;
if ( V_3 & V_5 )
return false ;
V_4 = V_3 | V_6 ;
if ( F_2 ( & V_2 -> V_3 , V_3 , V_4 ) == V_3 )
break;
F_3 () ;
}
return true ;
}
void __weak F_4 ( void )
{
}
static void F_5 ( struct V_1 * V_2 )
{
bool V_7 ;
F_6 () ;
V_7 = F_7 ( & V_2 -> V_8 , & F_8 ( V_9 ) ) ;
if ( V_7 )
F_4 () ;
F_9 () ;
}
bool F_10 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) ) {
return false ;
}
F_5 ( V_2 ) ;
return true ;
}
void F_11 ( void )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_12 * V_8 ;
V_11 = & F_8 ( V_9 ) ;
if ( F_12 ( V_11 ) )
return;
F_13 ( ! F_14 () ) ;
F_13 ( ! F_15 () ) ;
V_8 = F_16 ( V_11 ) ;
while ( V_8 != NULL ) {
V_2 = F_17 ( V_8 , struct V_1 , V_8 ) ;
V_8 = F_18 ( V_8 ) ;
V_2 -> V_3 = V_13 ;
V_2 -> V_14 ( V_2 ) ;
( void ) F_2 ( & V_2 -> V_3 , V_13 , 0 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( F_15 () ) ;
while ( V_2 -> V_3 & V_13 )
F_3 () ;
}
