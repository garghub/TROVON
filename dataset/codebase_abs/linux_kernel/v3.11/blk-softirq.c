static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , V_5 ;
F_2 () ;
V_4 = & F_3 ( V_6 ) ;
F_4 ( V_4 , & V_5 ) ;
F_5 () ;
while ( ! F_6 ( & V_5 ) ) {
struct V_7 * V_8 ;
V_8 = F_7 ( V_5 . V_9 , struct V_7 , V_10 . V_11 ) ;
F_8 ( & V_8 -> V_10 . V_11 ) ;
V_8 -> V_12 -> V_13 ( V_8 ) ;
}
}
static void F_9 ( void * V_14 )
{
struct V_7 * V_8 = V_14 ;
unsigned long V_15 ;
struct V_3 * V_11 ;
F_10 ( V_15 ) ;
V_11 = & F_3 ( V_6 ) ;
F_11 ( & V_8 -> V_10 . V_11 , V_11 ) ;
if ( V_11 -> V_9 == & V_8 -> V_10 . V_11 )
F_12 ( V_16 ) ;
F_13 ( V_15 ) ;
}
static int F_14 ( int V_17 , struct V_7 * V_8 )
{
if ( F_15 ( V_17 ) ) {
struct V_18 * V_14 = & V_8 -> V_10 ;
V_14 -> V_19 = F_9 ;
V_14 -> V_20 = V_8 ;
V_14 -> V_15 = 0 ;
F_16 ( V_17 , V_14 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( int V_17 , struct V_7 * V_8 )
{
return 1 ;
}
static int F_17 ( struct V_21 * V_22 , unsigned long V_23 ,
void * V_24 )
{
if ( V_23 == V_25 || V_23 == V_26 ) {
int V_17 = ( unsigned long ) V_24 ;
F_2 () ;
F_18 ( & F_19 ( V_6 , V_17 ) ,
& F_3 ( V_6 ) ) ;
F_12 ( V_16 ) ;
F_5 () ;
}
return V_27 ;
}
void F_20 ( struct V_7 * V_28 )
{
int V_29 , V_17 ;
struct V_30 * V_12 = V_28 -> V_12 ;
unsigned long V_15 ;
bool V_31 = false ;
F_21 ( ! V_12 -> V_13 ) ;
F_10 ( V_15 ) ;
V_17 = F_22 () ;
if ( V_28 -> V_17 != - 1 ) {
V_29 = V_28 -> V_17 ;
if ( ! F_23 ( V_32 , & V_12 -> V_33 ) )
V_31 = F_24 ( V_17 , V_29 ) ;
} else
V_29 = V_17 ;
if ( V_29 == V_17 || V_31 ) {
struct V_3 * V_11 ;
V_34:
V_11 = & F_3 ( V_6 ) ;
F_11 ( & V_28 -> V_10 . V_11 , V_11 ) ;
if ( V_11 -> V_9 == & V_28 -> V_10 . V_11 )
F_12 ( V_16 ) ;
} else if ( F_14 ( V_29 , V_28 ) )
goto V_34;
F_13 ( V_15 ) ;
}
void F_25 ( struct V_7 * V_28 )
{
if ( F_26 ( F_27 ( V_28 -> V_12 ) ) )
return;
if ( ! F_28 ( V_28 ) )
F_20 ( V_28 ) ;
}
static T_1 int F_29 ( void )
{
int V_35 ;
F_30 (i)
F_31 ( & F_19 ( V_6 , V_35 ) ) ;
F_32 ( V_16 , F_1 ) ;
F_33 ( & V_36 ) ;
return 0 ;
}
