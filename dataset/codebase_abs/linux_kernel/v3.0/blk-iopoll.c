void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_4 , & F_4 ( V_5 ) ) ;
F_5 ( V_6 ) ;
F_6 ( V_3 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_4 ) ;
F_9 () ;
F_10 ( V_7 , & V_2 -> V_8 ) ;
}
void F_11 ( struct V_1 * V_9 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_7 ( V_9 ) ;
F_6 ( V_3 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_4 = & F_4 ( V_5 ) ;
int V_13 = 0 , V_14 = V_15 ;
unsigned long V_16 = V_17 ;
F_13 () ;
while ( ! F_14 ( V_4 ) ) {
struct V_1 * V_2 ;
int V_18 , V_19 ;
if ( V_14 <= 0 || F_15 ( V_17 , V_16 ) ) {
V_13 = 1 ;
break;
}
F_16 () ;
V_2 = F_17 ( V_4 -> V_20 , struct V_1 , V_4 ) ;
V_19 = V_2 -> V_19 ;
V_18 = 0 ;
if ( F_18 ( V_7 , & V_2 -> V_8 ) )
V_18 = V_2 -> V_21 ( V_2 , V_19 ) ;
V_14 -= V_18 ;
F_13 () ;
if ( V_18 >= V_19 ) {
if ( F_19 ( V_2 ) )
F_7 ( V_2 ) ;
else
F_20 ( & V_2 -> V_4 , V_4 ) ;
}
}
if ( V_13 )
F_5 ( V_6 ) ;
F_16 () ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_22 , & V_2 -> V_8 ) ;
while ( F_23 ( V_7 , & V_2 -> V_8 ) )
F_24 ( 1 ) ;
F_25 ( V_22 , & V_2 -> V_8 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( ! F_18 ( V_7 , & V_2 -> V_8 ) ) ;
F_9 () ;
F_10 ( V_7 , & V_2 -> V_8 ) ;
}
void F_28 ( struct V_1 * V_2 , int V_19 , T_1 * V_23 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_29 ( & V_2 -> V_4 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_21 = V_23 ;
F_22 ( V_7 , & V_2 -> V_8 ) ;
}
static int T_2 F_30 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
if ( V_26 == V_28 || V_26 == V_29 ) {
int V_30 = ( unsigned long ) V_27 ;
F_13 () ;
F_31 ( & F_32 ( V_5 , V_30 ) ,
& F_4 ( V_5 ) ) ;
F_5 ( V_6 ) ;
F_16 () ;
}
return V_31 ;
}
static T_3 int F_33 ( void )
{
int V_32 ;
F_34 (i)
F_29 ( & F_32 ( V_5 , V_32 ) ) ;
F_35 ( V_6 , F_12 ) ;
F_36 ( & V_33 ) ;
return 0 ;
}
