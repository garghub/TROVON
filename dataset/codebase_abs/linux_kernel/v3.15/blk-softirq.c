static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , V_5 ;
F_2 () ;
V_4 = F_3 ( & V_6 ) ;
F_4 ( V_4 , & V_5 ) ;
F_5 () ;
while ( ! F_6 ( & V_5 ) ) {
struct V_7 * V_8 ;
V_8 = F_7 ( V_5 . V_9 , struct V_7 , V_10 ) ;
F_8 ( & V_8 -> V_10 ) ;
V_8 -> V_11 -> V_12 ( V_8 ) ;
}
}
static void F_9 ( void * V_13 )
{
struct V_7 * V_8 = V_13 ;
unsigned long V_14 ;
struct V_3 * V_15 ;
F_10 ( V_14 ) ;
V_15 = F_3 ( & V_6 ) ;
F_11 ( & V_8 -> V_10 , V_15 ) ;
if ( V_15 -> V_9 == & V_8 -> V_10 )
F_12 ( V_16 ) ;
F_13 ( V_14 ) ;
}
static int F_14 ( int V_17 , struct V_7 * V_8 )
{
if ( F_15 ( V_17 ) ) {
struct V_18 * V_13 = & V_8 -> V_19 ;
V_13 -> V_20 = F_9 ;
V_13 -> V_21 = V_8 ;
V_13 -> V_14 = 0 ;
F_16 ( V_17 , V_13 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( int V_17 , struct V_7 * V_8 )
{
return 1 ;
}
static int F_17 ( struct V_22 * V_23 , unsigned long V_24 ,
void * V_25 )
{
if ( V_24 == V_26 || V_24 == V_27 ) {
int V_17 = ( unsigned long ) V_25 ;
F_2 () ;
F_18 ( & F_19 ( V_6 , V_17 ) ,
F_3 ( & V_6 ) ) ;
F_12 ( V_16 ) ;
F_5 () ;
}
return V_28 ;
}
void F_20 ( struct V_7 * V_29 )
{
int V_30 , V_17 ;
struct V_31 * V_11 = V_29 -> V_11 ;
unsigned long V_14 ;
bool V_32 = false ;
F_21 ( ! V_11 -> V_12 ) ;
F_10 ( V_14 ) ;
V_17 = F_22 () ;
if ( V_29 -> V_17 != - 1 ) {
V_30 = V_29 -> V_17 ;
if ( ! F_23 ( V_33 , & V_11 -> V_34 ) )
V_32 = F_24 ( V_17 , V_30 ) ;
} else
V_30 = V_17 ;
if ( V_30 == V_17 || V_32 ) {
struct V_3 * V_15 ;
V_35:
V_15 = F_3 ( & V_6 ) ;
F_11 ( & V_29 -> V_10 , V_15 ) ;
if ( V_15 -> V_9 == & V_29 -> V_10 )
F_12 ( V_16 ) ;
} else if ( F_14 ( V_30 , V_29 ) )
goto V_35;
F_13 ( V_14 ) ;
}
void F_25 ( struct V_7 * V_29 )
{
if ( F_26 ( F_27 ( V_29 -> V_11 ) ) )
return;
if ( ! F_28 ( V_29 ) )
F_20 ( V_29 ) ;
}
static T_1 int F_29 ( void )
{
int V_36 ;
F_30 (i)
F_31 ( & F_19 ( V_6 , V_36 ) ) ;
F_32 ( V_16 , F_1 ) ;
F_33 ( & V_37 ) ;
return 0 ;
}
