static int F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
V_2 -> V_4 = F_2 () ;
F_3 () ;
F_4 () ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 () ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
static void
F_11 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
V_11 = F_13 () ;
F_14 () ;
F_15 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) )
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
F_20 ( & V_8 -> V_10 ) ;
F_21 () ;
}
static void
F_22 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
F_23 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) ) {
V_11 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
}
F_20 ( & V_8 -> V_10 ) ;
F_24 ( V_9 ) ;
}
static void
F_25 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
F_23 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) ) {
V_11 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
F_26 ( V_2 , V_9 , 5 , V_11 ) ;
}
F_20 ( & V_8 -> V_10 ) ;
F_24 ( V_9 ) ;
}
static void F_5 ( void )
{
V_12 = 0 ;
if ( V_13 & V_14 )
V_15 . V_16 = F_11 ;
else
V_15 . V_16 = F_22 ;
if ( V_17 . V_18 & V_19 )
F_27 ( & V_20 ) ;
else
F_27 ( & V_15 ) ;
V_12 = 1 ;
}
static void F_7 ( void )
{
V_12 = 0 ;
if ( V_17 . V_18 & V_19 )
F_28 ( & V_20 ) ;
else
F_28 ( & V_15 ) ;
}
static int F_29 ( T_1 V_21 , T_1 V_22 , int V_23 )
{
if ( V_22 == V_19 ) {
if ( ! ! V_23 == ! ! ( V_17 . V_18 & V_19 ) )
return 0 ;
if ( V_23 ) {
F_28 ( & V_15 ) ;
F_27 ( & V_20 ) ;
} else {
F_28 ( & V_20 ) ;
F_27 ( & V_15 ) ;
}
return 0 ;
}
return - V_24 ;
}
static void
F_30 ( unsigned long V_5 , unsigned long V_6 , void * * V_8 )
{
long * V_25 = ( long * ) V_8 ;
if ( F_31 () )
return;
if ( ! * V_25 )
return;
if ( * V_25 != - 1 )
( * V_25 ) -- ;
F_32 () ;
}
static void
F_33 ( unsigned long V_5 , unsigned long V_6 , void * * V_8 )
{
long * V_25 = ( long * ) V_8 ;
if ( ! F_31 () )
return;
if ( ! * V_25 )
return;
if ( * V_25 != - 1 )
( * V_25 ) -- ;
F_34 () ;
}
static int
F_35 ( struct V_26 * V_27 , unsigned long V_5 ,
struct V_28 * V_29 , void * V_8 )
{
long V_25 = ( long ) V_8 ;
F_36 ( V_27 , L_1 , ( void * ) V_5 ) ;
if ( V_29 == & V_30 )
F_36 ( V_27 , L_2 ) ;
else
F_36 ( V_27 , L_3 ) ;
if ( V_25 == - 1 )
F_36 ( V_27 , L_4 ) ;
else
F_36 ( V_27 , L_5 , V_25 ) ;
return 0 ;
}
static int
F_37 ( char * V_31 , char * V_32 , char * V_33 )
{
struct V_28 * V_29 ;
if ( strcmp ( V_32 , L_2 ) == 0 )
V_29 = & V_30 ;
else
V_29 = & V_34 ;
F_38 ( V_31 , V_29 ) ;
return 0 ;
}
static int
F_39 ( char * V_31 , char * V_32 , char * V_33 , int V_35 )
{
struct V_28 * V_29 ;
void * V_25 = ( void * ) - 1 ;
char * V_36 ;
int V_37 ;
if ( ! V_35 )
return - V_24 ;
if ( V_31 [ 0 ] == '!' )
return F_37 ( V_31 + 1 , V_32 , V_33 ) ;
if ( strcmp ( V_32 , L_2 ) == 0 )
V_29 = & V_30 ;
else
V_29 = & V_34 ;
if ( ! V_33 )
goto V_38;
V_36 = F_40 ( & V_33 , L_6 ) ;
if ( ! strlen ( V_36 ) )
goto V_38;
V_37 = F_41 ( V_36 , 0 , ( unsigned long * ) & V_25 ) ;
if ( V_37 )
return V_37 ;
V_38:
V_37 = F_42 ( V_31 , V_29 , V_25 ) ;
return V_37 < 0 ? V_37 : 0 ;
}
static int T_2 F_43 ( void )
{
int V_37 ;
V_37 = F_44 ( & V_39 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_44 ( & V_40 ) ;
if ( V_37 )
F_45 ( & V_39 ) ;
return V_37 ;
}
static inline int F_43 ( void )
{
return 0 ;
}
static T_2 int F_46 ( void )
{
F_43 () ;
return F_47 ( & V_41 ) ;
}
