static inline bool F_1 ( struct V_1 * V_2 , int V_3 )
{
return ( unsigned long ) V_2 -> V_4 & V_3 ;
}
static inline struct V_1 * F_2 ( struct V_1 * V_2 )
{
unsigned long V_4 = ( unsigned long ) V_2 -> V_4 ;
V_4 &= ~ V_5 ;
return (struct V_1 * ) V_4 ;
}
static inline struct V_1 * F_3 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 = ( unsigned long ) V_2 ;
V_4 |= V_3 ;
return (struct V_1 * ) V_4 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_4 , * V_6 ;
do {
V_4 = V_2 -> V_4 ;
if ( ( unsigned long ) V_4 & V_7 )
return false ;
V_6 = F_3 ( V_4 , V_5 ) ;
} while ( F_5 ( & V_2 -> V_4 , V_4 , V_6 ) != V_4 );
return true ;
}
void __weak F_6 ( void )
{
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_4 ;
F_8 () ;
do {
V_4 = F_9 ( V_8 ) ;
V_2 -> V_4 = F_3 ( V_4 , V_5 ) ;
} while ( F_10 ( V_8 , V_4 , V_2 ) != V_4 );
if ( ! F_2 ( V_2 ) )
F_6 () ;
F_11 () ;
}
bool F_12 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_2 ) ) {
return false ;
}
F_7 ( V_2 ) ;
return true ;
}
void F_13 ( void )
{
struct V_1 * V_9 ;
if ( F_14 ( V_8 ) == NULL )
return;
F_15 ( ! F_16 () ) ;
F_15 ( ! F_17 () ) ;
V_9 = F_18 ( V_8 , NULL ) ;
while ( V_9 != NULL ) {
struct V_1 * V_2 = V_9 ;
V_9 = F_2 ( V_9 ) ;
V_2 -> V_4 = F_3 ( NULL , V_10 ) ;
V_2 -> V_11 ( V_2 ) ;
( void ) F_5 ( & V_2 -> V_4 ,
F_3 ( NULL , V_10 ) ,
NULL ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( F_17 () ) ;
while ( F_1 ( V_2 , V_10 ) )
F_21 () ;
}
