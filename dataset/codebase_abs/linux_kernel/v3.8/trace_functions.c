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
F_11 ( unsigned long V_5 , unsigned long V_6 ,
struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_3 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
long V_13 ;
int V_4 ;
int V_14 ;
if ( F_12 ( ! V_15 ) )
return;
V_14 = F_13 () ;
F_14 () ;
F_15 ( V_12 ) ;
V_4 = F_16 () ;
V_11 = V_2 -> V_11 [ V_4 ] ;
V_13 = F_17 ( & V_11 -> V_13 ) ;
if ( F_18 ( V_13 == 1 ) )
F_19 ( V_2 , V_5 , V_6 , V_12 , V_14 ) ;
F_20 ( & V_11 -> V_13 ) ;
F_21 () ;
}
static void
F_22 ( unsigned long V_5 , unsigned long V_6 ,
struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_3 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
long V_13 ;
int V_4 ;
int V_14 ;
if ( F_12 ( ! V_15 ) )
return;
F_23 ( V_12 ) ;
V_4 = F_16 () ;
V_11 = V_2 -> V_11 [ V_4 ] ;
V_13 = F_17 ( & V_11 -> V_13 ) ;
if ( F_18 ( V_13 == 1 ) ) {
V_14 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_12 , V_14 ) ;
}
F_20 ( & V_11 -> V_13 ) ;
F_24 ( V_12 ) ;
}
static void
F_25 ( unsigned long V_5 , unsigned long V_6 ,
struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_3 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
long V_13 ;
int V_4 ;
int V_14 ;
if ( F_12 ( ! V_15 ) )
return;
F_23 ( V_12 ) ;
V_4 = F_16 () ;
V_11 = V_2 -> V_11 [ V_4 ] ;
V_13 = F_17 ( & V_11 -> V_13 ) ;
if ( F_18 ( V_13 == 1 ) ) {
V_14 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_12 , V_14 ) ;
F_26 ( V_2 , V_12 , 5 , V_14 ) ;
}
F_20 ( & V_11 -> V_13 ) ;
F_24 ( V_12 ) ;
}
static void F_5 ( void )
{
V_15 = 0 ;
if ( V_16 & V_17 )
V_18 . V_19 = F_11 ;
else
V_18 . V_19 = F_22 ;
if ( V_20 . V_21 & V_22 )
F_27 ( & V_23 ) ;
else
F_27 ( & V_18 ) ;
V_15 = 1 ;
}
static void F_7 ( void )
{
V_15 = 0 ;
if ( V_20 . V_21 & V_22 )
F_28 ( & V_23 ) ;
else
F_28 ( & V_18 ) ;
}
static int F_29 ( T_1 V_24 , T_1 V_25 , int V_26 )
{
switch ( V_25 ) {
case V_22 :
if ( ! ! V_26 == ! ! ( V_20 . V_21 & V_22 ) )
break;
if ( V_26 ) {
F_28 ( & V_18 ) ;
F_27 ( & V_23 ) ;
} else {
F_28 ( & V_23 ) ;
F_27 ( & V_18 ) ;
}
break;
default:
return - V_27 ;
}
return 0 ;
}
static void
F_30 ( unsigned long V_5 , unsigned long V_6 , void * * V_11 )
{
long * V_28 = ( long * ) V_11 ;
if ( F_31 () )
return;
if ( ! * V_28 )
return;
if ( * V_28 != - 1 )
( * V_28 ) -- ;
F_32 () ;
}
static void
F_33 ( unsigned long V_5 , unsigned long V_6 , void * * V_11 )
{
long * V_28 = ( long * ) V_11 ;
if ( ! F_31 () )
return;
if ( ! * V_28 )
return;
if ( * V_28 != - 1 )
( * V_28 ) -- ;
F_34 () ;
}
static int
F_35 ( struct V_29 * V_30 , unsigned long V_5 ,
struct V_31 * V_32 , void * V_11 )
{
long V_28 = ( long ) V_11 ;
F_36 ( V_30 , L_1 , ( void * ) V_5 ) ;
if ( V_32 == & V_33 )
F_36 ( V_30 , L_2 ) ;
else
F_36 ( V_30 , L_3 ) ;
if ( V_28 == - 1 )
F_36 ( V_30 , L_4 ) ;
else
F_36 ( V_30 , L_5 , V_28 ) ;
return 0 ;
}
static int
F_37 ( char * V_34 , char * V_35 , char * V_36 )
{
struct V_31 * V_32 ;
if ( strcmp ( V_35 , L_2 ) == 0 )
V_32 = & V_33 ;
else
V_32 = & V_37 ;
F_38 ( V_34 , V_32 ) ;
return 0 ;
}
static int
F_39 ( struct V_38 * V_39 ,
char * V_34 , char * V_35 , char * V_36 , int V_40 )
{
struct V_31 * V_32 ;
void * V_28 = ( void * ) - 1 ;
char * V_41 ;
int V_42 ;
if ( ! V_40 )
return - V_27 ;
if ( V_34 [ 0 ] == '!' )
return F_37 ( V_34 + 1 , V_35 , V_36 ) ;
if ( strcmp ( V_35 , L_2 ) == 0 )
V_32 = & V_33 ;
else
V_32 = & V_37 ;
if ( ! V_36 )
goto V_43;
V_41 = F_40 ( & V_36 , L_6 ) ;
if ( ! strlen ( V_41 ) )
goto V_43;
V_42 = F_41 ( V_41 , 0 , ( unsigned long * ) & V_28 ) ;
if ( V_42 )
return V_42 ;
V_43:
V_42 = F_42 ( V_34 , V_32 , V_28 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int T_2 F_43 ( void )
{
int V_42 ;
V_42 = F_44 ( & V_44 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_44 ( & V_45 ) ;
if ( V_42 )
F_45 ( & V_44 ) ;
return V_42 ;
}
static inline int F_43 ( void )
{
return 0 ;
}
static T_2 int F_46 ( void )
{
F_43 () ;
return F_47 ( & V_46 ) ;
}
