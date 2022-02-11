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
int V_13 ;
int V_4 ;
int V_14 ;
if ( F_12 ( ! V_15 ) )
return;
V_14 = F_13 () ;
F_14 () ;
V_13 = F_15 ( V_16 , V_17 ) ;
if ( V_13 < 0 )
goto V_18;
V_4 = F_16 () ;
V_11 = V_2 -> V_11 [ V_4 ] ;
if ( ! F_17 ( & V_11 -> V_19 ) ) {
F_18 ( V_12 ) ;
F_19 ( V_2 , V_5 , V_6 , V_12 , V_14 ) ;
}
F_20 ( V_13 ) ;
V_18:
F_21 () ;
}
static void
F_22 ( unsigned long V_5 , unsigned long V_6 ,
struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_3 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
long V_19 ;
int V_4 ;
int V_14 ;
if ( F_12 ( ! V_15 ) )
return;
F_23 ( V_12 ) ;
V_4 = F_24 () ;
V_11 = V_2 -> V_11 [ V_4 ] ;
V_19 = F_25 ( & V_11 -> V_19 ) ;
if ( F_26 ( V_19 == 1 ) ) {
V_14 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_12 , V_14 ) ;
F_27 ( V_2 , V_12 , 5 , V_14 ) ;
}
F_28 ( & V_11 -> V_19 ) ;
F_29 ( V_12 ) ;
}
static void F_5 ( void )
{
V_15 = 0 ;
if ( V_20 . V_21 & V_22 )
F_30 ( & V_23 ) ;
else
F_30 ( & V_24 ) ;
V_15 = 1 ;
}
static void F_7 ( void )
{
V_15 = 0 ;
if ( V_20 . V_21 & V_22 )
F_31 ( & V_23 ) ;
else
F_31 ( & V_24 ) ;
}
static int F_32 ( T_1 V_25 , T_1 V_13 , int V_26 )
{
switch ( V_13 ) {
case V_22 :
if ( ! ! V_26 == ! ! ( V_20 . V_21 & V_22 ) )
break;
if ( V_26 ) {
F_31 ( & V_24 ) ;
F_30 ( & V_23 ) ;
} else {
F_31 ( & V_23 ) ;
F_30 ( & V_24 ) ;
}
break;
default:
return - V_27 ;
}
return 0 ;
}
static void
F_33 ( unsigned long V_5 , unsigned long V_6 , void * * V_11 )
{
long * V_28 = ( long * ) V_11 ;
if ( F_34 () )
return;
if ( ! * V_28 )
return;
if ( * V_28 != - 1 )
( * V_28 ) -- ;
F_35 () ;
}
static void
F_36 ( unsigned long V_5 , unsigned long V_6 , void * * V_11 )
{
long * V_28 = ( long * ) V_11 ;
if ( ! F_34 () )
return;
if ( ! * V_28 )
return;
if ( * V_28 != - 1 )
( * V_28 ) -- ;
F_37 () ;
}
static int
F_38 ( struct V_29 * V_30 , unsigned long V_5 ,
struct V_31 * V_32 , void * V_11 )
{
long V_28 = ( long ) V_11 ;
F_39 ( V_30 , L_1 , ( void * ) V_5 ) ;
if ( V_32 == & V_33 )
F_39 ( V_30 , L_2 ) ;
else
F_39 ( V_30 , L_3 ) ;
if ( V_28 == - 1 )
F_39 ( V_30 , L_4 ) ;
else
F_39 ( V_30 , L_5 , V_28 ) ;
return 0 ;
}
static int
F_40 ( char * V_34 , char * V_35 , char * V_36 )
{
struct V_31 * V_32 ;
if ( strcmp ( V_35 , L_2 ) == 0 )
V_32 = & V_33 ;
else
V_32 = & V_37 ;
F_41 ( V_34 , V_32 ) ;
return 0 ;
}
static int
F_42 ( struct V_38 * V_39 ,
char * V_34 , char * V_35 , char * V_36 , int V_40 )
{
struct V_31 * V_32 ;
void * V_28 = ( void * ) - 1 ;
char * V_41 ;
int V_42 ;
if ( ! V_40 )
return - V_27 ;
if ( V_34 [ 0 ] == '!' )
return F_40 ( V_34 + 1 , V_35 , V_36 ) ;
if ( strcmp ( V_35 , L_2 ) == 0 )
V_32 = & V_33 ;
else
V_32 = & V_37 ;
if ( ! V_36 )
goto V_43;
V_41 = F_43 ( & V_36 , L_6 ) ;
if ( ! strlen ( V_41 ) )
goto V_43;
V_42 = F_44 ( V_41 , 0 , ( unsigned long * ) & V_28 ) ;
if ( V_42 )
return V_42 ;
V_43:
V_42 = F_45 ( V_34 , V_32 , V_28 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int T_2 F_46 ( void )
{
int V_42 ;
V_42 = F_47 ( & V_44 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_47 ( & V_45 ) ;
if ( V_42 )
F_48 ( & V_44 ) ;
return V_42 ;
}
static inline int F_46 ( void )
{
return 0 ;
}
static T_2 int F_49 ( void )
{
F_46 () ;
return F_50 ( & V_46 ) ;
}
