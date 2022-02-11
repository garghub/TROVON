void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_2 ( V_4 , & V_2 -> V_5 ) )
return;
if ( F_3 ( V_6 , & V_2 -> V_5 ) )
return;
F_4 ( V_3 ) ;
F_5 ( & V_2 -> V_7 , F_6 ( & V_8 ) ) ;
F_7 ( V_9 ) ;
F_8 ( V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_7 ) ;
F_11 () ;
F_12 ( V_6 , & V_2 -> V_5 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_4 ( V_3 ) ;
F_9 ( V_2 ) ;
F_8 ( V_3 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_7 = F_6 ( & V_8 ) ;
int V_13 = 0 , V_14 = V_15 ;
unsigned long V_16 = V_17 ;
F_15 () ;
while ( ! F_16 ( V_7 ) ) {
struct V_1 * V_2 ;
int V_18 , V_19 ;
if ( V_14 <= 0 || F_17 ( V_17 , V_16 ) ) {
V_13 = 1 ;
break;
}
F_18 () ;
V_2 = F_19 ( V_7 -> V_20 , struct V_1 , V_7 ) ;
V_19 = V_2 -> V_19 ;
V_18 = 0 ;
if ( F_2 ( V_6 , & V_2 -> V_5 ) )
V_18 = V_2 -> V_21 ( V_2 , V_19 ) ;
V_14 -= V_18 ;
F_15 () ;
if ( V_18 >= V_19 ) {
if ( F_2 ( V_4 , & V_2 -> V_5 ) )
F_9 ( V_2 ) ;
else
F_20 ( & V_2 -> V_7 , V_7 ) ;
}
}
if ( V_13 )
F_7 ( V_9 ) ;
F_18 () ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_4 , & V_2 -> V_5 ) ;
while ( F_3 ( V_6 , & V_2 -> V_5 ) )
F_23 ( 1 ) ;
F_24 ( V_4 , & V_2 -> V_5 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( ! F_2 ( V_6 , & V_2 -> V_5 ) ) ;
F_11 () ;
F_12 ( V_6 , & V_2 -> V_5 ) ;
}
void F_27 ( struct V_1 * V_2 , int V_19 , T_1 * V_22 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_28 ( & V_2 -> V_7 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_21 = V_22 ;
}
static int F_29 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_26 )
{
if ( V_25 == V_27 || V_25 == V_28 ) {
int V_29 = ( unsigned long ) V_26 ;
F_15 () ;
F_30 ( & F_31 ( V_8 , V_29 ) ,
F_6 ( & V_8 ) ) ;
F_7 ( V_9 ) ;
F_18 () ;
}
return V_30 ;
}
static T_2 int F_32 ( void )
{
int V_31 ;
F_33 (i)
F_28 ( & F_31 ( V_8 , V_31 ) ) ;
F_34 ( V_9 , F_14 ) ;
F_35 ( & V_32 ) ;
return 0 ;
}
