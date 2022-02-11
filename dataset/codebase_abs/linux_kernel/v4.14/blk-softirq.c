static T_1 void F_1 ( struct V_1 * V_2 )
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
T_2 * V_13 = & V_8 -> V_18 ;
V_13 -> V_19 = F_9 ;
V_13 -> V_20 = V_8 ;
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
static int F_17 ( unsigned int V_17 )
{
F_2 () ;
F_18 ( & F_19 ( V_6 , V_17 ) ,
F_3 ( & V_6 ) ) ;
F_12 ( V_16 ) ;
F_5 () ;
return 0 ;
}
void F_20 ( struct V_7 * V_21 )
{
int V_22 , V_17 ;
struct V_23 * V_11 = V_21 -> V_11 ;
unsigned long V_14 ;
bool V_24 = false ;
F_21 ( ! V_11 -> V_12 ) ;
F_10 ( V_14 ) ;
V_17 = F_22 () ;
if ( V_21 -> V_17 != - 1 ) {
V_22 = V_21 -> V_17 ;
if ( ! F_23 ( V_25 , & V_11 -> V_26 ) )
V_24 = F_24 ( V_17 , V_22 ) ;
} else
V_22 = V_17 ;
if ( V_22 == V_17 || V_24 ) {
struct V_3 * V_15 ;
V_27:
V_15 = F_3 ( & V_6 ) ;
F_11 ( & V_21 -> V_10 , V_15 ) ;
if ( V_15 -> V_9 == & V_21 -> V_10 )
F_12 ( V_16 ) ;
} else if ( F_14 ( V_22 , V_21 ) )
goto V_27;
F_13 ( V_14 ) ;
}
void F_25 ( struct V_7 * V_21 )
{
if ( F_26 ( F_27 ( V_21 -> V_11 ) ) )
return;
if ( ! F_28 ( V_21 ) )
F_20 ( V_21 ) ;
}
static T_3 int F_29 ( void )
{
int V_28 ;
F_30 (i)
F_31 ( & F_19 ( V_6 , V_28 ) ) ;
F_32 ( V_16 , F_1 ) ;
F_33 ( V_29 ,
L_1 , NULL ,
F_17 ) ;
return 0 ;
}
